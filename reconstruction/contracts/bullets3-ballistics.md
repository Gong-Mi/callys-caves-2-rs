# 三武器弹道行为契约（obj_iceball / obj_spikegunspike / obj_rocket）

武器拾取链（见 `weapons3-pickup-chain.md`）的配套弹道本体：三个弹体对象在 IR 场景宿主上的创建、飞行、命中、超时与自毁全生命周期，逐断言先经真实字节码探针实测再固化。发射侧（玩家 Alarm 0，CODE 11）的创建坐标契约已由 `original_player_combat.rs` 在事件层覆盖，本契约补弹体本体行为。

## 对象与 CODE（full_ir.json 锚定）

| 对象 | ID | sprite | CODE | 伤害全局 | xp 全局 |
|---|---|---|---|---|---|
| obj_iceball | 40 | 41 | 285 Create / 286 Step | icegundamage (1.0) | icegunxp |
| obj_spikegunspike | 42 | 44 | 291 Create / 292 Alarm1 / 293 Alarm0 / 294 Step | spikegundamage (3.0) | spikegunxp |
| obj_rocket | 44 | 43 | 299 Create / 300 Destroy / 301 Alarm1 / 302 Alarm0 / 303 Step | rocketdamage (6.0) | rocketxp |

支撑对象：obj_bulletspark(13, CODE 38 装 alarm[0]=7 / 39 自毁)、obj_damage(104 浮字)、obj_knifebandit(15, hpknife)、obj_wall(4, par_wall 子, type=1)、obj_boulderblock(156, par_wall 子)。声效（audio-sond.json）：snd_impactsound2=23、snd_explode2=8。spr_bigexplosion=50（CODE 302 原始字节码 constant=50 实证）。

## 行为还原

### obj_iceball（冰枪弹，无重力直线弹）
- **Create 285**：读 `obj_player.facing`（对象选择器，要求玩家 alive+active），facing 1 → hspeed −15，否则 +15。
- **Step 286**：①`instance_place(x,y,par_wall)` 裸真值分支（cast to=5 直通；-4 真值语义按原版）→ 生成 obj_bulletspark、自毁，后续敌人分支不再执行；②`image_angle = direction`；③按 14 个敌人族顺序探测（knifebandit/wolf/enemy/enemy2/trex/bat/slime/ghost/shooter1/shooter2/fireslime/hulkingbandit/zombie/firehulk/skeleton），命中即 flashing=1、2 粒子、hpfrozen=1、alarm[3]=45、扣 icegundamage、生成 obj_damage、snd 23、icegunxp+1、自毁（一次命中）。
- **冰域=冻结域**：CODE 286 无任何 poisonenabled 分支（grep 0 命中；32 个 poison 站点全部在 CODE 294）。冰枪的附加状态是 hpfrozen+alarm[3]=45（bat 例外：alarm[3]=90；trex/skeleton 分支不设 alarm[3]）。

### obj_spikegunspike（钉墙弹，Stick 'em 式）
- **Create 291**：facing 1 → hspeed −14 且 image_xscale=−1；facing 0 → +14 且 xscale=+1；`type=2`（自身是 par_wall 子且作为 type 2 墙参与他人探测）；alarm[1]=240。
- **Alarm 1 (292)** / **Alarm 0 (293)**：均 `instance_destroy()`——前者 240 帧超时，后者命中后挂 1 帧的自毁。
- **Step 294**：hspeed==0 且与另一根 spike 重叠 → 自毁（双钉合并）；`instance_place(x±hspeed…)` 先清另一根 spike（with 环境，PushEnv/Popenv 实证可跑）；(x+hspeed,y) 命中 par_wall 且 `hitwall.type != 3` → hspeed=vspeed=0（钉墙，不销毁，240 超时接管；type 3 银地板穿透，全恢复 GML 中仅 obj_silvercoin 设 type=3，为未来契约预钉）；对 26 个敌人/boss 目标做 (x+20,y)/(x−20,y)（hulkingbandit/boss 类 x±30）双向探测，命中 → flashing、3 粒子、扣 spikegundamage、alarm[0]=1（下一 tick 自毁）、stunned=1、alarm[4]=10（ghost 例外 swordstunned+alarm[5]=30）、snd 23、xp+1、poisonenabled==1 → alarm[6]=1（shooter2/firehulk 用 alarm[7]）。

### obj_rocket（火箭，单发锁 + 定时爆炸）
- **Create 299**：facing 1 → −16 否则 +16；四锁存位 hitblock/hitwall/canhit/hitboulder=0；alarm[0]=10 引信。
- **Step 303**：(x+hspeed,y) 命中 obj_boulderblock → with 销毁 + alarm[0]=1 + hitboulder=1（boulder 锁只允许一次"炸石续引"）；(x,y) 命中 par_wall 且 hitwall==0 → alarm[0]=1；对 21 个敌人/boss 目标以 (x,y) 重叠探测，canhit==0 才结算（单发锁）：flashing、2 粒子、扣 rocketdamage、obj_damage、stunned+alarm[4]=10（trex/boss 组无 stun）、alarm[0]=1、xp+1、canhit=1。
- **Alarm 0 (302)**：hspeed=vspeed=0；若 sprite≠50 → image_index=1、sprite_index=spr_bigexplosion(50)；alarm[1]=18。
- **Alarm 1 (301)**：instance_destroy()。**Destroy (300)**：snd_explode2(8)（soundmute 双分支）。
- **同 tick 槽序实测**：tick10 alarm[0] 归零派发 CODE 302 装 alarm[1]=18，tick 调度 0..12 顺序继续走到槽 1 再减 1 → 同 tick 读回 17；销毁发生在第 27 个 tick（非直觉的 28）。飞行段逐帧断言 x=300+16t（t≤9）、sprite 43；爆炸段 sprite 50、image_index 钉 1（image_speed 默认 1 但 sprite 50 帧窗由既有动画引擎管理，本批只钉 CODE 显式写入值）。

## 测试

`crates/core/tests/bullets3_ballistics_ir.rs` 12 项：iceball 双向 Create、命中冻结域全量断言（含 alarm[6] 必须为 −1 的反断言）、poison 归属反证（286 无站点、294 有）、撞墙 spark(7 帧)；spike 双向+镜像+type2+240 帧超时逐帧、命中 stun/自毁钉、撞普通墙清零速度但存活；rocket 四锁存位+引信、单发锁、boulderblock 一次性、27 tick 全生命周期（逐帧 x/sprite、爆炸 swap、销毁音唯一性）。

夹具纪律新增证据：`Scene::select` 过滤 alive+active —— 弹体 Create 前玩家不得 park（RED `read has no receiver for selector 0` 实证）；受害者同样不得 park（park 后全部 instance_place 落空，伤害 0）。直派 Step（不经 tick）故无需每帧重钉速度。

## 边界

- 碰撞模型统一包围盒近似（prec 像素级未实现），与既有全部契约同一声明。
- obj_damage 浮字仅断言生成计数，其飘字动画/Draw 属渲染层未验。
- 冰枪 alarm[3]=45 / 冻结的"敌人侧后果"（hpfrozen 消费方）属敌人行为契约，本批不重复建立。
- rocket 命中 trex/boss 组无 stun、ghost swordstunned 分支等 26 目标全分支未逐一铺测（模板同构，抽 knifebandit 代表）；真机/GPU 视觉层未验收。
