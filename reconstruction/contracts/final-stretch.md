# 最终段：room87-103 门链、rm_boss6、挑战链与结局触发契约

编号房门链（room31-86 各段）之后的最后一段：**room87→103 全链、rm_boss6 竞技场、rm_challenge1-5 挑战链、结局入口**。全部断言先经 scratch 探针/静态解码实测再固化进 `crates/core/tests/final_stretch_ir.rs`（2 项）；探针已删。

## 门链图（CODE 977-1021 静态全解 + 活实例核验）

编号段（每房两门，全部 `unlocked=1`）：

- room86 →87（CODE 977）；87↔88（978/979）；88↔89（980/981）；89↔90（982/983）；90↔91（984/985）；91↔92（986/987）；92↔93（988/989）；93↔94（990/991）；94↔95（992/993）；95↔96（994/995）；96↔97（996/997）；97↔98（998/999）；98↔99（1000/1001）；99↔100（1002/1003）；100↔101（1004/1005）；101↔102（1006/1007）；102↔103（1008/1009）；**103→rm_boss6**（1010）。
- rm_boss6 只有**一个**门（CODE 1012）回 room103（warproom=103, warpx=1408, warpy=364）。

挑战链（**不在编号链上**——从 rm_map 进入；每房直载核验门钉）：

- challenge1 (105)：回 boss6（1013：(104,128,140)）+ 去 challenge2（1014：(106,128,140)）
- challenge2 (106)：回 105（1015：(105,1376,908)）+ 去 107（1016）
- challenge3 (107)：回 106（1017：(106,1888,332)）+ 去 108（1018）
- challenge4 (108)：回 107（1019：(107,1216,492)）+ 去 109（1020：(109,128,428)）
- challenge5 (109)：回 108（1021：(108,1376,1164)）——链条终点

**夹具事实**：walk 落点是**进入门**的 warpx/warpy（如进 boss6 落 (128,140) = CODE 1010 的钉），不是房内回程门的钉；挑战房不能从 boss6 walk 进入（boss6 无 105 门）。

## 结局触发链（探针实测）

1. **finalboss 死亡**（Step hp≤0 → a0=1 → A0 kill）→ Destroy 生成 **obj_finalbosspuff(189)**。
2. **finalbosspuff Create (786)**：先清 obj_leftbutton(130)/obj_rightbutton(131) 残留；在 (x±20, y)、(x, y±20) 预生成 4 团 obj_bosspuff(190) 烟雾；**装 a0=10/a1=20/a2=30/a3=129**——三段 10 tick 间隔的烟雾环扩散（A0(791)/A1(790)/A2(789) 各再撒 4-5 团 bosspuff）+ 129 tick 硬寿命（A3(788) 自毁）。
3. **finalbosspuff Destroy (787)**：`instance_deactivate_object(0)`（全场失活）+ **`room_goto(110)`**——杀最终 boss 直开 rm_ending。实测 `target_room_warp == Some(110)`。
4. rm_ending 房内绑定（CODE 1022/1023）：玩家 sprite=30、obj_enemy(14) 静止（hspeed/vspeed=0）——站桩谢幕布景。Room Start 的 roomstart=1 + alarm[6]=10 输入锁已由 game-start-p0 契约钉死（CODE 16 仅 room==110 装填；CODE 5 Alarm 6 清零）。

## 测试

`crates/core/tests/final_stretch_ir.rs` 2 项：

1. `room87_to_room103_branch_and_boss6_challenges_are_asset_exact`——从 rm_level1 起沿**真实传送链**走 5→86→87→…→103→boss6（25+ 次真实 warp），逐房断言 current_room、双门存在、unlocked=1 全体；boss6 断言落点 (128,140) 与回程门钉 (103,1408,364)；五个挑战房直载核验回程/前进门钉（CODE 1013-1021 全表）。
2. `killing_the_final_boss_opens_the_ending`——finalboss hp=0 → 死亡拍 → finalbosspuff 生成（三段烟雾环拍 10/20/30 + 129 硬寿命实测）→ Destroy → `target_room_warp == Some(110)`。

## 边界

- room87-103 的卡司计数未逐房固化（模板同构，门链+双门+unlocked 已覆盖行进可达性；后续批可按需补卡司表）。
- rm_map/rm_mapview0/3 的 90+ 房间绑定（obj 160 的地图界面）未铺测——属地图 UI 批次。
- rm_ending 的结局演出（obj_logo 渐入、按钮 Draw、CODE 16 链）已有 game-start-p0/prologue 批的部分覆盖；完整结局 Draw 层未铺。
- 真机/GPU 视觉层未验收。
