# 终段卡司表与 boss4 状态机轮转契约（room87-103 + challenge1-5）

final-stretch 门链批登记的"卡司表待补"欠账闭环：17 个编号房 + 5 个挑战房的逐房卡司经**全新场景真实 loader** 实测固化；boss4 的歇息/追击/锁向中继（bosses-3-5 边界登记项）经直派实测。固化进 `crates/core/tests/final_casts_ir.rs`（2 项）；探针已删。

## 夹具关键修正（本批血泪）

- **obj_UI 持久累积**：沿真实传送链连走的探针里 obj_UI(66) 每过一房 +1（85、86…106 递增）——早期探针数据被持久化污染。**逐房卡司必须用全新场景直载**（fresh per-room），走链可达性由 final_stretch_ir 独立证明。
- 走链场景另有玩家（持久），fresh 场景无 obj_player(0)——两套断言口径分开。

## 卡司表（fresh 实测，逐房全量）

共享底盘（每房 1 件）：obj_bg(65)/obj_UI(66)/obj_muting(67)/obj_viewresolution(133) + 按钮 125-131；门 obj_warpanywhere(69) 每房 2（challenge5 仅 1 + obj_finalchest(101)）。

| 房 | 游戏性卡司（探针全量） |
|---|---|
| room87 | wall142 wall2_138 boulder70 spikes46 coin15 ghost5 gem4 |
| room88 | wall2_178 wall110 boulder108 coin22 ghost3 hulking×2 shooter1/skeleton/firehulk/bat 各1 |
| room89 | wall2_175 wall124 boulder108 **zombie17** coin12 **music(68)×1** |
| room90 | wall234 boulder142 wall2_107 coin23 water20 platform10 zombie3 chest3 firehulk2 hulking2 enemy2×2 + knife/skeleton/wolf/ghost/waterfill 各1 |
| room91 | wall126 boulder62 wall2_35 coin20 **enemy(14)×11**（哑剧敌人堆） |
| room92 | wall2_262 boulder180 wall140 coin18 fireslime4 enemy2×3 ghost3 chest2 knife/shooter2 各1 |
| room93 | wall137 wall2_135 boulder114 coin35 spikes26 water15 waterfill4 skeleton3 ghost3 knife/hulking/wolf 各1 |
| room94 | wall101 water64 boulder26 coin16 platform7 hulking4 waterfill1 |
| room95 | wall2_330 wall250 boulder197 coin24 chest5 ghost4 skeleton3 **iceblock3** firehulk2 zombie2 fireslime2 hulking1 bat1 |
| room96 | wall114 boulder79 wall2_55 water38 coin28 spikes12 skeleton4 chest3 platform/waterfill/enemy2/bat 各1 |
| room97 | boulder125 wall91 wall2_62 coin36 **shooter1×14**（炮塔阵） |
| room98 | boulder195 wall2_171 wall25 platform24 coin11 bat7 gem7 |
| room99 | wall2_119 wall112 boulder81 spikes14 water11 coin4 firehulk3 chest3 waterfill2 zombie2 **boulderblock2 iceblock2** |
| room100 | wall2_109 boulder84 wall54 ghost8 water6 waterfill3 |
| room101 | wall2_174 wall119 boulder82 platform10 coin6 water5 firehulk4 chest2 iceblock2 waterfill1 fireslime1 |
| room102 | boulder112 wall78 wall2_44 coin23 platform12 ghost4 hulking2 gem2 shooter2/wolf/bat/chest 各1 |
| room103 | wall2_194 wall119 boulder117 bat3 coin3 chest3 zombie2 + 每族 1（shooter1/skeleton/firehulk/shooter2/hulking/enemy2）+ **lloyd(154)** |
| challenge1 | wall2_393 wall248 boulder124 water12 bat4 waterfill3 hulking3 fireslime3 wolf2 ghost1 **lloyd** |
| challenge2 | wall2_461 wall124 boulder64 zombie6 enemy2×4 bat3 fireslime3 ghost2 wolf2 **slime1**（唯一 slime） |
| challenge3 | wall2_355 boulder204 wall192 ghost4 slime4 gem4 enemy2×3 hulking2 bat2 fireslime2 skeleton1 |
| challenge4 | wall290 boulder240 wall2_234 water65 spikes34 **bat11** waterfill6 fireslime5 ghost3 slime3 firehulk2 |
| challenge5 | wall2_498 wall234 boulder57 **chest13**（全游戏最大宝库）ghost4 skeleton3 gem3 hulking2 bat2 **finalchest(101)** |

## boss4 状态机轮转（直派实测，闭环 bosses-3-5 边界）

- **A4 (192)**：chasing=0 + 装 a6=30（歇息 30 tick）。
- **A6 (190)**：chasing=1 + 装 a4=60（追击重同步 60 tick）——**歇息↔追击闭环**。
- **A3 (193)**：movelock=1（锁向）。
- **A5 (191)**：swordstunned=0（恢复）。
- 与 bosses-3-5 批的移动/挥砍测试拼合，boss4 全状态机（追击/歇息/锁向/挥砍/恢复）闭合。

## 测试

`crates/core/tests/final_casts_ir.rs` 2 项：22 房逐房卡司（fresh 直载 + 底盘/门钉）；boss4 四 Alarm 轮转直派。

## 边界

- 卡司计数是**布置实例**；动态生成物（pickupflare、掉落）不在此表（各对象行为契约已建）。
- 走链场景的 obj_UI 累积行为（持久化语义）只做记录，不铺测——属宿主持久化层。
- 真机/GPU 视觉未验收。
