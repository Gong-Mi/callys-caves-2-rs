# room64-67（asset rooms 62-66）后门链第十二段契约

`room_bindings` 锚定 gml 房名（分段规律见 room68-71-branch.md 更正）：asset62=room64、asset63=room65 为 +2；rm_boss4（asset64）打断后 asset65=room66、asset66=room67 为 +1。rm_boss4 房打断序列与第八段 asset48=rm_boss3 同形态。门卡 CODE 928-937 逐条字节码核验（各 8 指令），十门全部 `unlocked=1` 在活实例字段断言。

## 门链（真实踩门贯通，双向返程逐站钉落点）

- asset61（room63）CODE 927 → asset62 落点 (1664,620)；asset62 CODE 928 → asset61 落点 (128,524)。
- asset62 CODE 929 → asset63 落点 (128,204)；asset63 CODE 930 → asset62 落点 (1920,684)。
- asset63 CODE 931 → asset64（rm_boss4）落点 (128,140)；rm_boss4 CODE 932 → asset63 落点 (2432,236)。
- rm_boss4 CODE 933 → asset65 落点 (128,108)；asset65 CODE 934 → rm_boss4 落点 (1152,364)。
- asset65 CODE 935 → asset66 落点 (128,204)；asset66 CODE 936 → asset65 落点 (352,1164)。
- asset66 CODE 937 → asset67 门卡延续（房体未进本批）。

## 卡司（运行时实测固化）

- asset62（room64, 2048x800）：wall×275、wall_2×213、boulder×250、**platform×10**（本分支平台最密房）、knifebandit×2、shooter1×1、skeleton×1、hulkingbandit×2、enemy2×2、wolf×2、slime×3、coin×21；无 chest/iceblock/flamethrower（负断言）——混合关房。
- asset63（room65, 2560x384）：wall×140、wall_2×134、boulder×189、watersurface×11、waterfill×3、enemy×1、shooter1×1、firehulk×1、shooter2×2、enemy2×1、wolf×1、coin×31、**obj_flamethrower×1**（本分支首个火焰喷射器拾取）、**iceblock×4**（熔化解冻契约密度房）；无 chest 负断言。
- asset64（rm_boss4, 1280x480）：**obj_boss4(28)×1**（sprite 76）、**obj_bossboulder(3)×2**（CODE 28/29）、**obj_triggerintro(186)×1**（Step CODE 781 开场门控）、wall×75、wall_2×208、boulder×89、platform×1；coin/shooter/slime/wolf 全零——干净 Boss 场，与 rm_boss3 房同构。
- asset65（room66, 512x1280）：wall×85、wall_2×125、boulder×139、platform×5、shooter1×1、firehulk×1、shooter2×1、wolf×1、ghost×2、coin×22、chest×1、**iceblock×5**（单房最密， melting 契约直接适用）。
- asset66（room67, 2048x640）：wall×283、wall_2×159、boulder×139、spikes×10、knifebandit×1、skeleton×1、firehulk×2、zombie×2、shooter2×2、hulkingbandit×1、wolf×1、slime×4、fireslime×1、coin×32、**chest×6**（本分支单房最大宝库房）、iceblock×2。

## 测试

`crates/core/tests/room64_67_branch_ir.rs` 5 项：逐房全量卡司 + 双门 + unlocked 断言；第 5 项把 asset66→65→64→63→62 整段返程走通并逐站钉落点。探针实测后固化为断言，探针文件已删。

## 边界

- asset67（room68）房体未进本批（CODE 938/939 门卡已见，下批延续）。
- obj_boss4（28，CODE 187-198）与 obj_bossboulder（3，CODE 28/29）行为契约未建立——boss 战本体批次处理；rm_boss3/boss2 场已有各自契约先例。
- obj_flamethrower（77）拾取与火焰弹道未建契约；obj_triggerintro Step CODE 781 未建契约。
- hulkingbandit(21)/firehulk(18) 行为契约仍欠（本批卡司密度继续上升）。
- iceblock 密度房（×4/×5）已配对 melting 契约（6f15fce）。
- 引擎统一包围盒碰撞近似（全批同口径）；真机/GPU 视觉层未验收。
