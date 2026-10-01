# 最终 Boss 契约（obj_finalboss + finalbosslaser + finalbossgrenade）

boss 名册收官：boss1(trex)/boss2/boss3/4/5 之后，finalboss(30) 及其两个投射物 obj_finalbosslaser(49)、obj_finalbossgrenade(50) 在本批闭环。全部断言先经 scratch 探针实测再固化进 `crates/core/tests/final_boss_ir.rs`（7 项，一次全绿）；探针已删。

## 对象与 CODE

| 对象 | ID | sprite | CODE | 说明 |
|---|---|---|---|---|
| obj_finalboss | 30 | 53 | 215 Create / 216 Destroy / 217-228 A11..A0 / 229 Step / 230 Col34 / 231 Draw | hp 阶梯 1750/1650/1550/1350（全游戏最高） |
| obj_finalbosslaser | 49 | 94 | 316 Create / 317 A0 / 318 Step | 定速 10 光束 |
| obj_finalbossgrenade | 50 | 97→50 | 319 Create / 320 Destroy / 321 A1 / 322 A0 / 323 Step / 324 Col34 | 重力炸弹 |
| obj_finalbosspuff | 189 | — | — | 死亡烟雾（Destroy 生成） |

## obj_finalboss 行为（逐值探针实测）

- **Create 215**：hp 阶梯 + finalbossmaxhp 镜像；hspeed=−1 开场漂移；**a1=180（空处理器）**、a2=270（六激光扇面种子）、a3=120（四手雷齐射种子）、a4=100（移动相位种子）；hpdrop=choose(5..1)、coindrop=choose(5..1)、xpdrop=1。
- **Step 229**：room≠110 门内——hp≤0 → 装 a0=1（死亡拍）；**三槽自续规则：`alarm[1] <= 0` → a1=180、`alarm[2] <= 0` → a2=180、`alarm[3] <= 0` → a3=120**（比较字 comp2 实证；探针：a3 在 tick 120 触发后 200 tick 时读回 40 = 120−80）；着地（y+1）→ gravity 0/0.6；facing 决定 image_xscale=−1（两支都写 −1）；前方 5px 探墙翻转 facing（`type != 2` 墙才转——银地板 type 3/普通 type 1 转，type 2 不转）；swordstunned → blend 255+冻结；poisoned → 绿 32768。
- **移动相位中继环**（全部 room≠110 门控，探针逐段实测）：A4（a7=100）：vspeed=2/hspeed=−2 对角俯冲 → A7（a8=50）：vspeed=3/hspeed=0.5 快落慢滑 → A8（a9=20）：**vspeed=10 重击砸地** → A9（a10=100）：vspeed=−0.5 缓慢回升 → A10（a11=100）：hspeed=2/vspeed=3 横扫 → A11（a4=100）：vspeed=1/hspeed=−2 恢复对角 → **闭环回 A4**。
- **A2 (226) 六激光扇面**：在 (x−100,y)/(x−80,y−20)/(x−80,y+20)/(x,y−20)/(x,y+20)/(x+80,y−20) 生成六道 finalbosslaser，方向 **45/90/135/180/225/270** 六向全覆盖（探针排序实测）。注意：这些偏移与地面墙 sprite 盒重叠——**真实调度+带墙夹具里激光同 tick 内撞墙自灭**，探针必须直派 A2 且场景无墙（夹具教训）。
- **A3 (225) 四手雷齐射**：生成四颗 finalbossgrenade，方向 90/135/180/225（探针排序实测）；不是激光。
- **A1 (227)**：空处理器（0 指令）——占位节拍。
- **A10 (218) 即 poison 槽**：poisoned=1、hp−0.25、自续 30（boss 族 poison 槽 = alarm[10] 规律延续）。
- **死亡**：Step 装 a0=1 → **A0 (228)**：snd 7 + `action_kill_object`（无掉落喷洒——终 boss 不掉币）。**Destroy 216**：`audio_stop_all` + snd 49 + obj_finalbosspuff(189)。实测音频 [15（激光 hum 残留）, 7, 49]。
- **Collision 34 (230)**：`action_bounce`——撞墙反弹（与 fireslime/grenade 同款）。

## obj_finalbosslaser 行为

- **Create 316**：**speed=10 固定**（非 choose）、canhit=0、snd 15（光束嗡鸣）。
- **Step 318**：剑格挡（`instance_place(obj_sword)`）→ 生成 obj_parry(12) + 自毁，剑存活（实测 parry=1）；撞墙 → 生成 obj_bulletspark(13) + 自毁；**命中玩家**（invulnerable==0 && invulnerable2==0 && canhit==0 门）→ snd 23、flashing、4 粒子、**严格击退链**（x>player.x → 侧A；x<player.x → 侧B；等距不写——与 boss3projectile 同型）、玩家 a4/a7/a8=10/22/25、**health1−1**、自装 a0=1、**canhit=1**——**光束命中后不死**（区别于 boss3projectile 的即毁），下一 tick 才经 A0 (317) 自毁（探针两步实测：hit 后 alive=true、tick 后 alive=false）。
- **image_angle = direction**（飞行姿态）。

## obj_finalbossgrenade 行为

- **Create 319**：gravity=0.6、speed=3、**a0=45 引信**、**a1=63 硬寿命**、canhit=0。
- **Step 323**：剑格挡 → obj_parry + 自毁；**命中玩家**（canhit==0 门）→ snd 23、flashing、粒子、击退链、health1−1、**canhit=1 锁存**（第二 Step 0 伤害探针实证）——**手雷命中不死**（接触危险物，非自杀弹）；同帧装 a0=1 不影响 45/63 主计时（a0 已在倒计时，重装 1 会被 A0 的爆炸提前接管——探针直派实测引信语义）。
- **A0 (322) 引信**：sprite 换 50（爆炸贴图 spr_bigexplosion）、image_index=0、**hspeed/vspeed=0 定住**、snd 8。
- **A1 (321)**：`action_kill_object` 硬杀。**Destroy 320**：snd 8（soundmute 双分支）。
- **Collision 34 (324)**：`action_bounce` 撞墙反弹。

## 跨对象规律（boss 名册收官总结）

- **三种投射物命中语义谱系**：boss3projectile（即毁）、finalbosslaser（命中不死、a0=1 下一 tick 死）、finalbossgrenade（canhit 锁存接触危险、45/63 独立计时死）——同一严格击退链与玩家 a4/a7/a8=10/22/25 顿帧在三者一致。
- **poison 槽 = alarm[10]**（boss3/4/5/finalboss 全体一致）。
- **死亡统一走 alarm[0]**；Destroy 只做清场（audio_stop_all + 各自 fanfare + puff）。
- finalboss 是唯一**无掉落喷洒**的 boss（A0 只 kill）——终战语义。
- **比较字解码**（`(words_raw & 0xFF00) >> 8` = 1..6）继续适用；本批用它钉了 Step 三槽自续的 `<=` 门与探墙 `type != 2`。

## 测试

`crates/core/tests/final_boss_ir.rs` 7 项：finalboss 4（阶梯+四种子+开场漂移、三槽自续直派实测、六激光扇面 45..270 + 四手雷 90/135/180/225 齐射、六段移动相位中继环逐段断言、死亡 snd49+finalbosspuff）；laser 2（speed 10/snd 15/命中不死+canhit 锁存+下一 tick 死+击退侧选、格挡 parry+撞墙 spark13）；grenade 1（gravity 0.6 引信 45/寿命 63/接触危险锁存/引信爆炸贴图换装 snd8/A1 硬杀）。

## 边界

- A1 空处理器、Draw（231）血条层、rm_ending(110) 内 boss 静止分支未铺测（room≠110 门静态钉）。
- 激光/手雷的飞行轨迹逐帧积分未断言（方向+初速+重力已钉，宿主 motion 积分已有 physics_and_motion_ir 覆盖）。
- 真机/GPU 视觉层未验收。
