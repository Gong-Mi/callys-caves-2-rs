# Cally's Caves 2 游戏流程全量逆向拓扑契约

基于哈希固定的原版 GameMaker Studio 1.4 资产（`game.droid` SHA256: `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`）与全量 1,354 份 GML 恢复源码审计完成。

---

## 1. 关卡网络拓扑（全 114 个 ROOM，6 大区域 + 6 大 Boss）

进入任意房间时，由玩家 `Other_4`（Room Start / CODE 16）打上对应的 `global.{room}visited = 1`。

### 区域 1：洞穴浅层（The Caves）
- **大本营**：`rm_town`（Room 0，安全营地，Lloyd 小屋 `obj_house`，商店与强化）
- **关卡**：`rm_level1` ~ `rm_level8` + 支线 `rm_level8a`
- **主要敌人**：`obj_bearcub`、`obj_knifebandit`、`obj_spider`、`obj_bat`、`obj_wolf`
- **获取武器**：散弹枪（`Shotgun`，拾取后触发 `global.shotgunbought = 1`）
- **关底 Boss 1**：`rm_boss1`（Room 10）
  - Boss 实体：`obj_trex`（霸王龙机甲，275 HP，CODE 154~162）
  - 封门实体：`obj_bossboulder`（object 3，CODE 28/29），检查 `global.boss1dead == 0` 锁闭
  - 击败判定：`hptrex <= 0` 触发 Alarm 0（CODE 160），写入 `global.boss1dead = 1`，巨石消散，进入下一区域

### 区域 2：废弃矿道（The Mines）
- **关卡**：`rm_level9` ~ `rm_level17` + 支线 `rm_level9a`, `11a`, `13a`, `14a`, `15a`, `16a`, `17a`
- **主要敌人**：`obj_pistolbandit`、`obj_turret`、`obj_slime`
- **获取武器**：突击步枪（`Assault Rifle`）
- **关底 Boss 2**：`rm_boss2`（Room 26）
  - Boss 实体：`obj_boss2`（CODE 163~171）
  - 击败判定：写入 `global.boss2dead = 1`

### 区域 3：地底深渊（The Depths）
- **关卡**：`room31` ~ `room50`（编号由具名转向内部 room 标号）
- **主要敌人**：`obj_zombie`、`obj_redslime`、`obj_skeleton`
- **关底 Boss 3**：`rm_boss3`（Room 47）
  - Boss 实体：`obj_boss3`（CODE 172~187）
  - 击败判定：写入 `global.boss3dead = 1`

### 区域 4：工业熔炉与能源核心（The Core）
- **关卡**：`room51` ~ `room65`
- **主要敌人**：`obj_hulkingbandit`、`obj_bee`
- **关底 Boss 4**：`rm_boss4`（Room 63）
  - Boss 实体：`obj_boss4`（CODE 188~199）
  - 击败判定：写入 `global.boss4dead = 1`

### 区域 5：秘密生化实验室（The Secret Laboratory）
- **关卡**：`room66` ~ `room82`
- **主要敌人**：`obj_firehulk`、强化激光发生器、幽灵
- **关底 Boss 5**：`rm_boss5`（Room 81）
  - Boss 实体：`obj_boss5`（CODE 200~216）
  - 击败判定：写入 `global.boss5dead = 1`

### 区域 6：Herbert 终极堡垒（Herbert's Lair）
- **关卡**：`room83` ~ `room103`
- **最终战 Boss 6**：`rm_boss6`（Room 103）
  - Boss 实体：`obj_boss6`（Herbert 博士终极战斗机甲，CODE 217~235）
  - 击败判定：写入 `global.boss6dead = 1`，触发通往结局房间的剧情传送

### 特殊房间与支线
- **结局**：`rm_ending`（救出父母剧情、致谢名单与时间统计 `global.timeplayed`）
- **隐藏挑战关**：`rm_challenge1` ~ `rm_challenge5`
- **大地图系统**：`rm_map`、`rm_mapview0`、`rm_mapview3`

---

## 2. 存档系统规范（三份 INI 结构映射）

每次玩家离开房间时，由 `Other_5`（Room End / CODE 15）执行原子落盘；游戏启动时由 `Other_2`（CODE 17）读取。

### 主存档：`savefile.ini`
- **角色状态**：`current_level`、`current_maxhp`、`current_score`、`current_XP`、`timeplayed`、`haskey`
- **主线进度**：`boss1dead` ~ `boss6dead`
- **剧情推进**：`talkedtolloyd1` ~ `talkedtolloyd16`（记录 Lloyd 在各关卡是否交谈完毕）
- **武器与被动**：12 种武器的 `bought` 状态、当前等级与累积经验；力量、生命恢复、三段跳、双倍/五倍金币倍率

### 挑战存档：`savefile2.ini`
- 记录 5 个隐藏挑战房通过状态：`levelchallenge1visited` ~ `levelchallenge5visited`

### 成就与击杀统计：`savefile3.ini`
- 40+ 项怪物累计击杀阈值：`twentyfivebears`、`onehundredbears`、`twentyfivewolf`、`onehundredwolf`、`twentyfiveenemies`、`onethousandenemies` 等

---

## 3. 数值成长系统（RPG Mechanics）

由 `obj_UI` 定时器（CODE 368 / Alarm 0，每 30 帧）统一驱动：

1. **Cally 角色等级（1 ~ 20 级）**：
   - 经验阈值公式：`global.xptolevelup = global.xptolevelup * 1.12`（每级递增 12%，初始 30）
   - 上限：20 级
2. **12 种武器熟练度（1 ~ 10 级）**：
   - 武器列表：Pistol, Shotgun, Assault Rifle, Rocket, Laser, Icegun, Bladegun, Flamethrower, Bow, Bombgun, Boomerang, Spikegun
   - 升级阈值公式：`{weapon}xptolevelup = {weapon}xptolevelup * 1.5`（每级递增 50%）
   - **外观与弹道三阶质变**：
     - 等级 4：`drawchange{weapon}4 = 1`（弹道强化）
     - 等级 7：`drawchange{weapon}7 = 1`（双重/连击判定）
     - 等级 10（MAX）：`drawchange{weapon}10 = 1`（攻速与伤害质变）
3. **Lloyd 小屋升级**：
   - 剑术强化：`swordupgrade1` ~ `swordupgrade3`
   - 力量倍率：`strengthupgrade`、`strengthupgrade2`
   - 被动技能：`triplejumpbought`（三段跳）、`healthregenbought`（回血芯片，每 300 帧自动回血 1 点）

---

## 4. 死亡与大地图快通机制

1. **死亡状态机（`obj_youhavedied` / CODE 540~543）**：
   - 生命归零触发，全场景冻结（`instance_deactivate_all(true)`），暂停背景音乐
   - 随机扣除金币：`irandom_range(30, 99)`
   - 倒计时 70 帧后解锁触摸，恢复生命至 4 点，重置至关卡锚点 `(global.startx, global.starty)` 并调用 `room_restart()`
2. **大地图快速旅行（`rm_map`）**：
   - 每个房间对应地图节点实例，其 Creation Code 检测 `if (global.room{N}visited == 0) instance_destroy();`
   - 未探索房间节点彻底隐形，已探索房间点击后直接执行 `room_goto(goto)`，实现跨区域瞬移
