# Boss 3/4/5 战斗契约（obj_boss3 / obj_boss4 / obj_boss5 + 双投射物）

room50（rm_boss3）/room64（rm_boss4）/room80（rm_boss5）三个竞技场契约登记的"boss 战本体批次处理"欠账闭环；boss1(trex)/boss2 已有先例契约，本批后 boss 名册到 boss5 全建（finalboss(30) 仍欠）。全部断言先经 scratch 探针实测再固化进 `crates/core/tests/bosses_3_5_ir.rs`（8 项）；探针已删。

## 比较字解码（本批新增的静态工具）

`cmp` 的 comparison 字节 = `(words_raw[0] & 0xFF00) >> 8`，按 VM 枚举 1..6 = `<`, `<=`, `==`, `!=`, `>=`, `>`。修正前批两处措辞：enemies-batch-2 的 hulkingbandit 远程距离门是 **`distance <= 200`**（357696000=comp2，非 "<200"）；boss4 追击唤醒是 **`distance <= 100`**。

## 对象与 CODE

| 对象 | ID | hp global（阶梯 pwr1-4） | Create 装填 |
|---|---|---|---|
| obj_boss3 | 27 | hpboss3/boss3maxhp：850/800/725/600 | a9=400（召唤拍）、a1=90（弹幕链种子）、a11=60（漂移拍）——均在 room≠110 门内 |
| obj_boss4 | 28 | hpboss4/boss4maxhp：950/900/825/700 | chasing=1、a4=60、a3=30、a1=90 |
| obj_boss5 | 29 | hpboss5/boss5maxhp：1000/900/800/700 | a1=90（连发链种子）、a11=70（侧翼拍） |

投射物：obj_boss3projectile(55, CODE 335/336, sprite=弹幕)、obj_fireprojectile(54, CODE 333/334)。支撑：obj_sword(46)=玩家剑、obj_parry(12)=格挡火花、obj_bosspuff(190)=死亡烟雾、obj_ghost(24)=boss3 召唤物、obj_slime(32)=召唤门第二计数。

## 行为还原（逐值来自探针）

### obj_boss3（弹幕塔）
- **Create 171**：hp 阶梯 + image_xscale=−1（镜像起手）+ coindrop=choose(5..1) + hpdrop=1 + xpdrop=1 + a9=400/a1=90/a11=60（三拍全在 room≠110 门内——rm_ending 里 boss3 静止不攻）。
- **弹幕环**：a1 在第 90 tick 首发（真实调度实测）；CODE 183(A1) 生成 obj_boss3projectile@ (x−50, y) + 装 a2=10 → CODE 182(A2) 生成 + a3=10 → A3/A4/A6/A7/A8 依次 10 tick 接力生成，A8(176) 尾部装 **a1=30** 重新入环——环自续。每发都落在 (x−50, y)（左向固定，镜像 boss 向左喷）。
- **boss3projectile Create 335**：`direction = choose(60,45,30,15,0,−15,−30)` 七向散射（实测首抽 60°）、speed=−5 为 choose 前的占位（direction 写入后 speed 语义由宿主 motion 保留）。
- **boss3projectile Step 336**：命中玩家分支——`rebuff != 1` 反弹无敌豁免 → `invulnerable==0 && invulnerable2==0` → snd 23、flashing、4 粒子 → **击退方向链：`x > player.x` → invulnerable/sliding1=1；否则 `x < player.x` → invulnerable2/sliding2=1；x 完全相等两侧都不写**（严格不等链，实测等距不击退）→ 玩家 alarm[4]=10/a[7]=22/a[8]=25 → **health1 −= 1** → 弹体自毁。撞墙 → 自毁。**剑格挡**：`instance_place(obj_sword)` 命中 → 生成 obj_parry(12) + 弹体自毁，剑存活（实测 sparks=1、sword alive）。`rebuff==1 && distance_to_object(player) <= 2` 近失 → 生成 obj_dodged(106)（闪避奖牌）。
- **召唤 A9 (175)**：`instance_number(obj_ghost) < 2 && instance_number(obj_slime) < 2` 双守卫 → 在 (x−70,y) 与 (x+70,y) **生成两只 obj_ghost**（增加物），尾部装 a9=200。实测首召 0→2，二次召被 <2 守卫挡住（仍是 2）。
- **漂移 A11 (173)**：`x vs player.x` 比较 → 近侧 `vspeed=choose(3,−3)`+`hspeed=choose(2,−2)` 随机漂移，或 `move_towards_point(player.x, player.y, 2)` 追位；自续 a11=20。
- **Step 185**：hp≤0 → 装 a0=1（死亡拍）；镜像 xscale=−1 保持；撞实体 `move_bounce_all` 反弹；swordstunned → blend 255+冻结；poisoned → 绿 32768；room==110 冻结。
- **死亡**：Step 装 a0=1 → **CODE 184(A0)**：snd 7、hpdrop → obj_health、**boss3dead=1**、gem、10×obj_XPorb（coinspread 5 向）、coindrop 1-5 阶梯 20 币、`action_kill_object`。**Destroy 172**：清 obj_boss3projectile(55) 与 obj_fireprojectile(54) 残弹、`audio_stop_all`、snd 50、obj_bosspuff(190)。实测：10 XP 弹 + 20 币 + 1 puff + 音频 [7,50]。

### obj_boss4（追击盾卫）
- **Create 187**：hp 阶梯 + **chasing=1** + a4=60（追击重同步）/a3=30（movelock 拍）/a1=90（姿势环种子）。
- **Step 197**：着地（y+1 par_wall）→ gravity 0/0.6；hp≤0 → a0=1；**chasing 时 `distance_to_object(player) <= 100` → swinging=1**（80px 实测）/远距 swinging=0；movelock=1 与玩家 x 比较 → xscale ±1 + hspeed ∓2 追走；撞玩家无敌门 → 停步；chasing=0 → sprite 76；poisoned 绿；room==110 冻结；前方 10px 撞墙 → hspeed 反向（∓2 翻转）。
- **姿势环 A1 (195)**：room≠110 门内：swinging=1 → **sprite 77（举盾）**+ a2=10；swinging=0 → sprite 76 + a1=30。
- **挥砍落 A2 (194)**：swinging=0 + chasing=1 → 在 (x+30,y−10) 与 (x−30,y−10) **生成两只 obj_fireprojectile(54)**（实测 2 只）。
- **A6 (190)**：chasing=1 + a4=60（60 tick 后恢复追击节拍）；A4 (192)：chasing=0 + a6=30（歇息 30）；A3 (193)：movelock=1；A5 (191)：清 swordstunned；**A10 (189)**：poison 0.25/自续 30（boss 族的 poison 槽是 **10**）。
- **死亡 A0 (196)**：boss4dead=1 + 掉落（10 XP + coin 阶梯）+ kill。**Destroy 188**：`audio_stop_all` + **snd 49** + bosspuff。实测 snd 49 与 boss3 的 50 区分。

### obj_boss5（连发炮台）
- **Create 199**：hp 阶梯（1000 峰值，全 boss 最高）+ a1=90 + a11=70。
- **Step 213**：hp≤0 → a0=1；`player.x vs self.x` → xscale ±1；前方 100px 无墙 → **hspeed ±1 慢速逼近** + facing 同步；有墙 → 停（实测无墙 hsp=1/facing=1/xscale=1）；swordstunned/poisoned/room==110 标准处理。
- **连发链**：A1 (211) room≠110 门内：facing 0 → 生成 obj_fireprojectile@ (x−50, y−5)；facing 1 → (x+50, y−5)；**snd 12** + a2=10。A2-A9 (210..203) 依次 10 tick 接力（每发同 facing 门控 + snd 12），A9 尾部装 **a1=30** 重新入链——八连发后自续。A11 (201)：**只装 a11=110 不做事**（占位循环，静态钉）。
- **fireprojectile Create 333**：`direction = point_direction(self→player)` 精确瞄准 + **speed=8**（实测玩家在右侧时 dir≈358°）。
- **fireprojectile Step 334**：与 boss3projectile 同构——剑格挡 → obj_parry + 自毁（scale 0.5 火花）；命中玩家 → 击退链/health1−1/自毁；**撞墙 → 生成 0.5 缩放的 obj_smallpuff(187) + 自毁**（与 boss3proj 的直接自毁不同）；`rebuff==1 && distance<=2` → obj_dodged。
- **死亡 A0 (212)**：boss5dead=1 + 10 XP + coin 阶梯 + kill；Destroy 200 与 boss3 同构（清残弹 + audio_stop_all + snd + bosspuff）。

## 跨 boss 规律（本批固化）

- **死亡拍统一走 alarm[0]**（Step hp≤0 装 1，A0 做掉落+kill），Destroy 只做清场（残弹清扫 + audio_stop_all + 各自 fanfare：boss3=50、boss4=49）+ bosspuff。
- **弹幕/连发链自续结构**：种子拍（a1=90）→ 10 tick 槽接力 → 尾槽重新装种子（30 tick）——boss3 的七槽环与 boss5 的八连发同型。
- **poison 槽是 alarm[10]**（boss 族），与敌人五族的 slot 6/7 不同。
- **maxhp 镜像字段**（boss3maxhp 等）与 hp 同拍写入，供 UI 血条层用。
- 剑格挡链（obj_sword 46 拦截 → obj_parry 12 火花）与 rebuff 闪避奖牌（obj_dodged 106）在两投射物上行为一致。

## 测试

`crates/core/tests/bosses_3_5_ir.rs` 8 项：boss3 4（阶梯+三拍+镜像、真实调度 90 tick 弹幕首抽 60°、召唤双守卫 0→2→挡、死亡清场含残弹清扫+10XP/20币+snd50）、boss4 2（阶梯+追击唤醒 ≤100+挥砍双火弹、死亡 snd49+掉落）、boss5 2（阶梯+慢速逼近+定向连发 point_direction 358°/speed 8、死亡 boss5dead+10XP）。boss3projectile 命中链（击退侧选、等距不击退、a4/a7/a8=10/22/25、health1−1、剑格挡 parry 火花）在 boss3 测试内覆盖。

## 边界

- boss4 的 movelock/chasing 状态机完整轮转（A3/A4/A6 的歇息-恢复循环）只静态钉+单点实测，未铺全状态轮转测试。
- boss5 A11（空占位）、boss3 A5/A10（解冻/毒）与五族同型未重复铺测。
- finalboss(30) 与 obj_finalbosslaser(49) 未在本批；rm_boss6+ 纯名房段未触。
- Draw 层（血条/fog）未铺；真机/GPU 视觉未验收。
