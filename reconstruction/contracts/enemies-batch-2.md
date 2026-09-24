# 五族敌人行为契约（hulkingbandit / firehulk / skeleton / ghost / fireslime）

六个房间分支契约反复登记的行为欠账（room52-55/56-59/60-63/64-67/68-71/72-75/76-79/83-86 的卡司密度主角）在本批闭环。全部断言先经 scratch 探针在 IR 宿主实测再固化进 `crates/core/tests/enemies2_batch_ir.rs`（12 项）；探针已删。敌人受击侧（武器弹体的 20 族探测分支）已由 ballistics-closure 覆盖，本批是敌人**自身**的生命周期。

## 对象与 CODE（full_ir.json 锚定）

| 对象 | ID | parent | CODE（Create/Destroy/Alarm 族/Step/Draw） | 自有 hp 字段 | 死亡计数 global |
|---|---|---|---|---|---|
| obj_hulkingbandit | 21 | par_enemy(11) | 112 / 113 / 114-120(A0-A6) / 121 / 122 | hphulkingbandit | hulkingbanditskilled |
| obj_firehulk | 18 | par_enemy | 80 / 81 / 82-88(A7,A6,A5,A4,A3,A1,A0) / 89 / 90 | hpfirehulk | firehulkskilled |
| obj_skeleton | 17 | par_enemy | 69 / 70 / 71-77(A6-A0) / 78 / 79 | hpskeleton | skeletonskilled |
| obj_ghost | 24 | par_enemy | 145 / 146 / 147-151(A6-A0) / 152 / 153 | hpghost | ghostskilled |
| obj_fireslime | 33 | par_enemy | 256 / 257 / 258-264(A6-A0) / 265 / 266(Col 34) / 267 | hpfireslime | fireslimeskilled |

全部五族 Destroy：`{族}skilled+=1`、`enemieskilled+=1`、`instance_create(obj_bigpuff=188)`（skeleton/ghost 用 obj_smallpuff=187）。死亡掉落**不走 Destroy**，走各自 Create 预装的死亡 Alarm（CODE 掉落表见下）。

## 等级×威力 hp 阶梯（Create 实测全表）

比较链是 `level <= N` 系列块（bf 跳链静态解码 + 逐值实测；level=1 与 10 同落 ≤10 块）：

- **hulkingbandit**：≤5/≤10 → pwr1-4 = 100/95/90/85；≤15 → 120/115/110/105；≤20 → 130/125/118/113。**唯一有 ≤5 块的族**。
- **firehulk**：≤10 → 100/95/90/80；≤15 → 115/110/105/95；≤20 → 130/120/115/105。
- **skeleton**：≤10 → 60/55/50/45；≤15 → 70/65/60/55；≤20 → 80/75/70/65。
- **ghost**：≤5 → 45/42/39/35；≤10 → 47/44/41/37；≤15 → 55/51/48/44；≤20 → 60/55/51/48。
- **fireslime**：≤5 → 80/75/70/60；≤10 → 86/80/76/68；≤15 → 95/88/82/78；≤20 → 110/98/90/85。

Create 同时掷 `coindrop=choose(5,4,3,2,1)`、`hpdrop=choose(...)`（firehulk/skeleton 的 hpdrop 含 0）、`xpdrop=1`、frozen/_poisoned/stunned/swordstunned/shooting 全 0，并按族装攻击节拍 Alarm。

## 行为还原（逐值来自探针）

### obj_hulkingbandit（重装枪手）
- **Create 112**：hp 阶梯 + `alarm[1]=30`（远程攻击节拍）。
- **Step 121**：hp≤0 → 装 `alarm[0]=1`（死亡掉落拍）；探边（x±5 对 par_wall/6/7）翻转 facing；着地判定（y+1 par_wall）→ gravity 0/0.6 + falling；facing×shopping 门控 hspeed ±2 与 image_xscale ±1；距玩家 <50 且玩家可伤 → hspeed=0（逼近停车）；frozen=1 → 蓝色 blend 16711680 + 全速冻结；stunned → sprite 116；poisoned → 绿 blend 32768；room==110 → 冻结速度（ending 静止）。
- **Alarm 1 (119)**：room==110 整体跳过（攻击只在非 ending 房运行——**倒序注意：cmp(room,110) 真则 b 跳尾**）；`collision_line(self→player, par_wall, prec=1, notme=1)` 视线通畅 && image_xscale==1（左向分支；xscale=-1 走 396 右向镜像分支）→ `distance_to_object(player) <= 200`（比较字 357696000，与 level 阶梯同型）→ frozen==0 → **shooting=1、alarm[2]=8（射击姿势）、vspeed=0、friction=0、snd 12、instance_create(obj_hulkingbanditbullet=51)@ (x∓20, y−15) 子弹 hspeed ∓10**；尾部无条件 `alarm[1]=45` 重装（实测 tick30 开火、tick75 再开火）。距离 ≥200 时尾部只清 shooting=0 并重装 45。
- **Alarm 0 (120)**：死亡掉落——snd 7；gemdropenabled → obj_gem(59)@ (x, y−35)；hpdrop==1 → obj_health(62)；xpdrop → obj_XPorb(61)+motion_set(5, xpspread)；`instance_number(coin)<20` 双重门 → coindrop 1-5 阶梯散布（x±2/4/6/8/10/11 偏移，motion_set(5, coinspreadN)）；`action_kill_object`。
- **恢复族**：A2=sprite 117 复位；A3=`image_blend -= 16777215`（16711680→−65535 实测）+ frozen=0；A4=stunned=0+sprite；A5=swordstunned=0+sprite；A6=poisoned=1、hp−0.25、obj_damage(0.25)、自重装 30。

### obj_firehulk（火焰巨人）
- **Create 80**：阶梯 + `alarm[1]=30`。
- **Alarm 1 (87)**：facing 0 → `instance_create(obj_firehulkflame=53)@ (x+5, y−8)`；facing 1 → (x−5, y−8)；两支都 `alarm[6]=8` + snd 14。**flame 的持续喷吐由 A6 (CODE 82) 接管**：poison 槽即此族的 A7（与 ballistics-closure 的跨族 poison 槽规律一致）——A7：poisoned=1、hp−0.25、自重装 30。
- **Step 89**：hp≤0 → alarm[0]=1；着地 y+2 判定 → gravity 0/0.6；facing 定 hspeed ±2+xscale；距玩家 <50 停车；frozen 蓝+冻结；stunned/swordstunned → blend 255 + 冻结；面向玩家翻转 xscale（player.x 比较）；poisoned 绿；room==110 冻结。
- **Alarm 0 (88)**：死亡掉落（snd 7、gem、hp、xp、coin 1-5 阶梯到 12 枚）+ kill。
- A3=解冻、A4/A5=清 stun、A6=喷吐节拍。

### obj_skeleton（骷髅投骨手）
- **Create 69**：阶梯 + **alarm[1]=60（投骨拍）+ alarm[2]=56（姿势拍）**。
- **Alarm 1 (76)**：facing 0 → `instance_create(obj_bone=56)@ (x+10, y−15)`；facing 1 → (x−10, y−15)；sprite=111（投掷姿势）、snd 13、自重装 `alarm[1]=60`。
- **Alarm 2 (75)**：sprite=110（行走姿势）、自重装 `alarm[2]=60`——两拍独立循环（实测 60 tick 首根骨头）。
- **Step 78**：hp≤0 → alarm[0]=1；facing → hspeed ±3 + xscale ±1（无 shooting 门）；距玩家 <50 停车；探边翻转；frozen 蓝+冻结；stunned/swordstunned 处理；poisoned 绿；room==110 冻结。
- **Alarm 0 (77)**：死亡掉落（coin 阶梯到 13 枚）+ kill。A6=poison（实测 0.25/30 重装）。

### obj_ghost（幽灵）
- **Create 145**：阶梯（无 attack/alarm 节拍——**全族唯一不在 Create 装攻击拍的**)。
- **Step 152**：room==110 跳过；hp≤0 → alarm[0]=1；gravity=0（漂浮）；面向玩家 xscale；`distance_to_object(player) <= 220` 唤醒带内 → **再次 <50 内圈判定**：swordstunned/frozen 不在 → `mp_potential_step(player.x, player.y, 3, false)` 直线逼近（实测 200px 处每步 +3px；>220 完全不动）；frozen 蓝+冻结；stunned/swordstunned blend 255+冻结；poisoned 绿；room==110 冻结。
- **Alarm 0 (151)**：死亡掉落（snd 0、gem、hp、xp、coin 阶梯到 11）+ kill。

### obj_fireslime（火焰史莱姆）
- **Create 256**：阶梯 + `blobjump=45` + **alarm[0]=30（起跳拍）+ alarm[1]=40（落地拍）** + `slimedirection=choose(3,−3)` 直接写进 hspeed（实测两值随机）。
- **Alarm 0 (264)**：`place_meeting(x, y+1, par_wall)` 着地 && frozen==0 → **vspeed=−5 起跳**、sprite=75、jumping=1、自重装 60。着地判定用真实墙盒（wall@216 的 sprite 盒覆盖 y+1；wall@240 不覆盖——探针实证的原版几何）。
- **Alarm 1 (263)**：jumping=0、sprite=70、自重装 60。
- **Step 265**：hp≤0 → **alarm[2]=1**（死亡拍，区别于其他族的 slot 0）；下方 (y+vspeed) 实体判定 → gravity 0.7/0；头顶 (y−3) 空判定 + 左右 (x±5, y−2) 探测翻转方向；面向玩家 xscale；(y+1) 着地 && frozen==0 && `collision_line(self→player, par_wall)` 通畅 → **vspeed=−8 扑跳**、sprite 75；frozen 蓝+冻结；stunned → sprite 72；poisoned 绿；room==110 冻结；jumping → sprite 75 保持。
- **Collision 34 (266)**：`action_bounce(0,0)`——撞墙反弹（mines_slime 的 blob 同款）。
- **Alarm 2 (262)**：死亡掉落（snd 7、gem、双 hp、xp、coin 阶梯到 13）+ destroy。
- **A6=poison 0.25/30 重装**。

## 夹具新证据（本批血泪）

- **`distance_to_object` 无目标返回 100000**（宿主 sentinel，非 −1）：park 玩家后所有距离门静默失败。远程攻击/扑跳类探针**必须保持玩家 alive+active**，用零速+逐帧重钉冻结，不能用 park。
- **无地面的场景里敌人会掉出攻击带**：hulkingbandit 29 tick 掉到 y=461（重力 0.6/步），与玩家距离超 200 → 攻击门正确拒绝。夹具必须给敌人脚下放真实墙（wall@216 的 sprite 盒恰好覆盖 y=200 行的 y+1）或逐帧重钉 y。
- **同 tick 槽序读回 −1**：alarm 装填后同 tick 的槽循环继续递减（装 8 读回 7），与 rocket 批 alarm[1]=18 读回 17 同源；断言要么记 −1 差值，要么在装填 tick 后立刻断言。
- **`{族}skilled` global 只在首杀后存在**：`init_fresh_start_globals` 只种子 bearskilled/knifebanditskilled/pistolthugskilled/wolfkilled/chomperbotkilled——新族的 killed 计数在 Destroy 才首次写入，测试用 `.get().copied().unwrap_or(0.0)`。
- **alarm 装填解码**：`constant V; constant -1; constant I; store alarm` = alarm[I]=V（value/slot 与 laserbeam 批同型）。

## 测试

`crates/core/tests/enemies2_batch_ir.rs` 12 项：hulkingbandit 4（阶梯全表+节拍、死亡掉落链+计数、真实调度 30 tick 开火+45 重装+冻结钳制、恢复族 A2-A6 全清）；firehulk 2（阶梯+火舌 A1/A6/A7、死亡掉落计数）；skeleton 2（60 拍投骨+姿势循环+真实调度、poison 槽）；ghost 2（220 唤醒带 mp_potential_step 3px/步 + 远距不动、死亡+poison）；fireslime 2（方向掷值+起跳/落地真实几何+调度、alarm[2] 死亡链）。

## 边界

- Draw 事件（fog+draw_self 闪烁高亮）属渲染层，静态钉不铺测；真机/GPU 视觉未验收。
- coindrop/hpdrop 的 choose 具体取值由场景 rng 决定，测试断言掉落喷洒的结构（gem/health/xp/coin 计数≥1）而非具体骰值。
- 武器侧的 20 族受击分支（stun/poison 槽差异）由 ballistics-closure 覆盖；boss2-6/finalboss 的 hp 消费侧不属本批。
- ghost 的 alarm3/4/5（解冻/清 stun）与 hulk/firehulk 同型未逐一铺测（模板一致，A3 已在 hulking 覆盖）。
