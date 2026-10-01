# 五武器弹道收口契约（laserbeam / flame / blade / bomb / arrow / boomerangthrow / energywave）

`bullets3-ballistics.md`（iceball/spike/rocket）登记的五条弹道欠账在本批全部闭环；连同手枪（`weapon-combat-bullet-hit.md`）与冰/钉/火箭，**武器弹道本体 12/12 建立**（拾取链 12/12 已在前批）。全部断言先经 scratch 探针在本引擎宿主实测，再固化进 `crates/core/tests/ballistics_closure_ir.rs`（24 项）；探针文件已删除。

## 对象与 CODE（full_ir.json 锚定）

| 弹体 | ID | sprite | CODE | 伤害 | xp 全局 |
|---|---|---|---|---|---|
| obj_laserbeam | 41 | 42 | 287 Create / 288 Alarm1 / 289 Step / 290 Other_0 | laserdamage (3.0)，**global.laser==1 才结算** | laserxp |
| obj_flame | 35 | 49 | 268 Create / 269 Alarm0 / 270 Step | flamethrowerdamage (0.3)/Step，无门控 | flamethrowerxp |
| obj_blade | 36 | 38 | 271 Create / 272 Alarm1 / 273 Alarm0 / 274 Step | bladegundamage (3.0)，无锁存 | bladegunxp |
| obj_bomb | 37 | 44→50 | 275 Create / 276 Alarm1 / 277 Alarm0 / 278 Step | bombgundamage (4.0)，canhit 单次锁 | bombgunxp |
| obj_arrow | 38 | 39 | 279 Create / 280 Alarm0 / 281 Step | bowdamage (2.0)，无锁存 | bowxp |
| obj_boomerangthrow | 43 | 144 | 295 Create / 296 Alarm1 / 297 Alarm0 / 298 Step | boomerangdamage (2.0)，无锁存 | boomerangxp |
| obj_energywave | 45 | 150 | 304 Create / 305 Destroy / 306 Alarm1 / 307 Alarm0 / 308 Step | **常量 3**（非全局阶梯），canhit 单次锁 | 无 xp |

发射侧（玩家 Alarm 0，CODE 11）对每把武器的 instance_create 分支已在事件层覆盖（`original_player_combat.rs` / combat-batch.md）；CODE 11 的 instance_create 目标全量核对：39/41/40/44/37/38/36/35/43/42，本批补齐其中五个弹体本体。

## 行为还原（逐值来自字节码+探针实测）

### obj_laserbeam（等级门控激光）
- **Create 287**：alarm[1]=120 引信；facing 1 → hspeed −20 否则 +20（vspeed 无写入，直线激光）。无 image_angle 写入于 Create；Step 首行 `image_angle = direction`。
- **Step 289**：**无撞墙分支**（全 CODE 零 par_wall/woodblock 探测；起始即 knifebandit）。按 20 族顺序 `instance_place(x,y,N)` 探测：15/23/14/22/25/31/32/24/16/20/33/21/19/18/17/26/27/28/29/30。命中分支结构（以 knifebandit 为代表）：flashing=1、2 粒子 → **`global.laser==1` 门控伤害块**（bf@168 目标 308：门关时直接跳到 stunned）→ hp−laserdamage、obj_damage(104) 带 damage 字段、laserxp+1 → 门外仍执行 stunned=1（with 环境 pushenv/popenv 写受害者字段）、**knife 族 alarm[4]=5**（其余常规族=10，shooter2/firehulk 槽 7）→ snd 23（soundmute 双分支）→ poisonenabled==1 → alarm[6]=1（shooter2/firehulk alarm[7]）→ **instance_destroy（一次命中即耗尽）**。
- **实测**：laser=0 时命中只闪不扣血（hp Δ=0、无 obj_damage、xp=0）但 stunned=1/a4=5/自毁/snd 23 照常；laser=1 时 hp Δ=laserdamage、obj_damage=1、xp=1。**夹具事实**：obj_player Create（CODE 0 offset 544-548）无条件 `global.laser=0`——门控注入必须在玩家创建之后。
- **Alarm 1 (288)**：instance_destroy——120 tick 引信（探针实测 1-based 第 120 tick 死亡）。**Other_0 (290)**：instance_destroy（出房间自毁，宿主未派发该事件，只做静态钉）。
- boss3(27)/boss4(28)/boss5(29)/finalboss(30) 分支**无 poison 段**（boss2(26) 是最后一个带 poison 的族）。

### obj_flame（穿透火舌，逐帧灼烧）
- **Create 268**：alarm[0]=9；facing 1 → (−15,−1)，facing 0 → (+15,−1)——**两支都写 vspeed=−1**（火舌上飘）。
- **Step 270**：①`room==110`（rm_ending）→ hspeed=vspeed=0（冻结但仍继续膨胀+探测）；②`image_xscale/yscale += 0.1`（每步膨胀，IEEE 链 1.1→2.0）；③image_angle=direction；④按 20 族探测（顺序同 laserbeam），命中：flashing、2 粒子、**hp−flamethrowerdamage（无任何武器门控）**、obj_damage、**snd 23 经 `audio_is_playing` 去重门**（正在播则不重播）、xp+1、poison→alarm[6]（shooter2/firehulk 槽 7）、**无 stunned、无自毁**——穿透，同一目标每 Step 持续扣 0.3。
- **实测**：15→14.7→14.399…（float 链，测试用 1e-9 容差）；两次 burn 只有 1 条 snd 23（audio_voices 去重生效）；boss4/5/finalboss 无 poison 段。
- **Alarm 0 (269)**：instance_destroy——9 tick 寿命（实测第 9 tick 死）。

### obj_blade（穿透刀刃，双杀木块）
- **Create 271**：alarm[1]=40；facing → hspeed ±20。
- **Step 274**：①`(x+hspeed,y)` 探测 **obj_woodblock(158)** → with 双杀（woodblock 销毁 + 刀自毁）；②`(x,y)` 探测 par_wall(34) → 生成 obj_bulletspark(13) + 自毁；③image_angle=direction；④21 族探测（158/34 前置 + 15/14/23/22/25/31/32/24/16/20/33/21/19/18/17/26/27/28/29/30），命中：flashing、**3 粒子**、hp−bladegundamage（**无门控无锁存，同一目标可反复命中**）、obj_damage、snd 23、xp+1、stunned=1 + alarm[4]=10（25/26/27/28/29/30 族无 stun）、poison→alarm[6]/[7]、**无自毁**。
- **Alarm 1 (272)**：instance_destroy——40 tick 超时（实测 1-based 第 40 tick）。**Alarm 0 (273)**：instance_destroy（宿主中该槽未被 CODE 写入；静态钉）。

### obj_bomb（弹跳炸弹，单次命中+30 帧引信）
- **Create 275**：canhit=0、hitwall=0；facing → hspeed ±8；alarm[0]=30。
- **Step 278**：①`(x+hspeed,y+vspeed)` 探测 par_wall 且 sprite≠50 → `move_bounce_solid(0)`（hspeed 取反，实测 −8）→ **gravity=0.3**（首次接触起下落）；②20 族探测（同 laserbeam 顺序，无 25 缺位），命中且 **canhit==0** 才结算：flashing、4 粒子、hp−bombgundamage、obj_damage、snd **8**（撞击即爆炸音）、xp+1、poison→alarm[6]/[7]、**canhit=1**（生命周期内锁死，实测第二 Step 0 伤害）。
- **Alarm 0 (277)**：引爆——image_index=0、sprite=50（spr_bigexplosion）、gravity/hspeed/vspeed=0、alarm[1]=18、snd 23。实测：撞击路径 alarm[0]=1 下一 tick 即爆（tick 1 爆、tick 18 死）；无撞击引信 tick 30 爆、tick 47 死。
- **Alarm 1 (276)**：instance_destroy。finalboss(30) 分支为**空分支**（bf 跳到 CODE 末尾，abs target == code end 实证）。

### obj_arrow（弓箭，抛物线+近玩家可回收）
- **Create 279**：facing → (±15, −1)——**两支都写 vspeed=−1**（上抛起飞）。
- **Step 281**：①par_wall 命中且 **NOT** (`distance_to_object(obj_player) < 16` 且 boomerangbought==0 的合取按字节码序) → spark + 自毁；**距活玩家 <16 时存活**（可回收箭，边界实测 gap 16 死 / 15.9 活）；②**gravity=0.3**（抛物线）；③image_angle=direction；④20 族探测同 bomb，命中：flashing、3 粒子、hp−bowdamage、obj_damage、stunned=1 + alarm[4]=10（trex/boss 族无 stun）、snd 23、xp+1、poison→alarm[6]/[7]、**无自毁**（穿透）。
- **Alarm 0 (280)**：instance_destroy（宿主中未被写入；静态钉）。

### obj_boomerangthrow（回旋镖，30 帧返程）
- **Create 295**：image_speed=0；facing → hspeed ±5（慢速投掷）；**alarm[1]=30**；boomerangreturn=0；`boomeranglevel` 阶梯选 image_index：**≤3→0 / 4-6→1 / 7-9→2 / ≥10→3**（边界实测 3→0、4→1、9→2、10→3）。
- **Step 298**：①boomerangreturn==1 → `move_towards_point(player.x, player.y, 5)` 追玩家；②`(x,y)` 探测 obj_player(0) 命中且 boomerangreturn==1 → **instance_destroy（玩家接住）**，实测投出后第 36 tick 死（tick 30 转向、追 5-6 tick 接住）；③boomerangreturn=0；**image_angle −= 40/Step**（实测 −40 → −1440 链）；④15 族探测（无 trex/boss 族）：flashing、2 粒子、hp−boomerangdamage、obj_damage、stunned=1 + alarm[4]=10、snd 23、xp+1、poison→alarm[6]/[7]、**无自毁**。
- **Alarm 1 (296)**：`direction = point_direction(player.x, player.y, self.x, self.y)` + boomerangreturn=1——30 tick 时转向玩家（实测 ret=1 于 tick 30）。
- **Alarm 0 (297)**：instance_destroy。

### obj_energywave（能量波，穿透+常量伤害）
- **Create 304**：canhit=0；facing → hspeed ±20；**alarm[1]=12**；snd 6（无条件，soundmute 分支存在于字节码但 Create 直写）。
- **Step 308**：①par_wall 命中 → 自身 alarm[0]=1（**不销毁**——波穿墙）；②20 族探测，命中且 canhit==0：flashing、2 粒子、**hp −= 常量 3**（无伤害全局）、obj_damage 带 damage=3、**自身 alarm[0]=1**（每次命中标记）、stunned=1 + alarm[4]=10（trex/boss 族无 stun）、**canhit=1**（同一波对已命中目标不再结算，实测第二 Step 0 伤害）。
- **Alarm 0 (307)**：sprite_index=50（爆炸贴图标记）。**Alarm 1 (306)**：action_kill_object——12 tick 寿命（实测第 12 tick 死）。**Destroy (305)**：snd 18（实测音频序列 [6, 18]）。

## 跨弹体规律（本批固化）

- **stun 阵营差**：knife 族 alarm[4]：laserbeam=**5**，其余全部 10；shooter2(20)/firehulk(18) 一律用 poison 槽 **alarm[7]**；trex(25)/boss2-6(26-29)/finalboss(30) 无 stun；flame/bomb **完全没有 stun**。
- **poison 尾段**：boss3 之后各族（boss4/5/finalboss）分支无 poison（laser/flame/blade/bomb/arrow/bt/ew 全体一致）。
- **穿透 vs 耗尽**：laserbeam 一次命中即毁；flame/blade/arrow/boomerangthrow/energywave 穿透；bomb 被撞击的 alarm[0]=1 引爆接销毁。
- **音频**：撞击音 snd 23（laser/flame/blade/arrow/bt/ew）；bomb 撞击 snd 8、爆炸 snd 23；flame 用 `audio_is_playing` 去重门（唯一使用该 builtin 的弹体）；energywave Create snd 6 / Destroy snd 18。soundmute 双分支全部保留。
- **夹具纪律**：`global.laser` 被 obj_player Create 重置为 0——武器门控注入必须在玩家创建**之后**；arrow 的 `distance_to_object` 需要活玩家；boomerang 返程测试每帧重钉玩家位置（玩家自身 Step 重力会漂移夹具）。

## 测试

`crates/core/tests/ballistics_closure_ir.rs` 24 项：laserbeam 4（双向 Create+引信、门控伤害/门外 stun、poison 槽、120 tick 引信+无墙分支反断言）；flame 3（双向+膨胀+9 tick 寿命、room110 冻结仍膨胀、逐 Step 灼烧+音频去重+无 stun）；blade 3（woodblock 双杀、par_wall spark+自毁、无锁存穿透+40 tick 超时）；bomb 4（Create 锁存+引信、弹墙+gravity、单次命中锁、双引信时序（30/47 与撞击次日爆）+爆炸精灵链）；arrow 3（抛物线+gravity 0.3、<16 近玩家存活边界（16 死/15.9 活）、命中 stun+穿透）；boomerang 3（Create 阶梯+30 tick 返程、回旋接住、命中穿透）；energywave 4（Create+常量 3、单波锁存+alarm[0] 标记、12 tick+Destroy 音、墙只换精灵不死）。

## 边界

- 碰撞模型统一包围盒近似（prec 未实现），与既有契约同一声明；trex/boss 族分支抽 knifebandit 代表（模板同构，静态读图已列全族差异）。
- obj_damage 浮字仅断言生成与 damage 字段值；飘字动画属渲染层未验。
- obj_laserbeam Other_0（出房间自毁）与 obj_arrow Alarm 0/obj_blade Alarm 0 在宿主中无派发路径，只做静态锚定。
- boomerang 的返程 `point_direction` 具体角度值依赖玩家相对位置，测试钉转向时刻+接住时刻，不钉绝对角度。
- 真机/GPU 视觉层未验收；武器切换 UI（weaponswap）与商店购买链不在本批。
