# room60-63（asset rooms 58-61）后门链第十一段契约

`room_bindings` 锚定 gml 房名 = asset 索引 +2（asset58=room60 … asset61=room63；+3 基准在 rm_boss3/asset48 打断后降为 +2，规律全量核对见 room68-71-branch.md 更正）。门卡 CODE 920-927 逐条字节码核验（各 8 指令），八门 `unlocked=1` 全部在活实例字段断言。

## 门链（真实踩门贯通，双向返程逐站钉落点）

- asset57（room59）CODE 919 → asset58 (128,204)；asset58 CODE 920 → asset57 (672,364)。
- asset58 CODE 921 → asset59 (128,204)；asset59 CODE 922 → asset58 (1888,364)。
- asset59 CODE 923 → asset60 (128,140)；asset60 CODE 924 → asset59 (1920,172)。
- asset60 CODE 925 → asset61 (128,108)；asset61 CODE 926 → asset60 (640,1164)。
- asset61 CODE 927 → asset62 (1664,620) 门卡延续（房体未进本批）。

## 卡司（运行时实测固化）

- asset58（room60, 2048x480）：wall×225、wall_2×187、boulder×104、firehulk×2、zombie×2、hulkingbandit×2、bat×2、slime×1、fireslime×1、coin×11、**iceblock×3**；无 chest/spikes（负断言）——冰块走廊房。
- asset59（room61, 2048x480）：wall×141、wall_2×105、boulder×154、**spikes×59**、watersurface×18、waterfill×5、bat×3、coin×15、chest×2、iceblock×2；无 obj_enemy/knifebandit 负断言（尖刺湖只有 bat 活动）。
- asset60（room62, 800x1280）：wall×163、wall_2×192、boulder×200、platform×2、enemy×1、knifebandit×1、hulkingbandit×1、wolf×1、ghost×1、bat×4、fireslime×1、coin×18、**chest×5**、**boulderblock×3**（分支第三块火箭收益房）、iceblock×2。
- asset61（room63, 2048x640）：wall×186、wall_2×201、boulder×179、**watersurface×47**（本分支最大水面房）、waterfill×1、firehulk×1、enemy2×1、ghost×2、bat×1、slime×1、fireslime×2、coin×34、无 chest（负断言）——水穿越房。

## 测试

`crates/core/tests/room60_63_branch_ir.rs` 4 项：逐房全量卡司+双门+unlocked；第 4 项 asset61→60→59→58 返程三站落点逐一钉死。探针实测后固化，探针已删。

## 边界

- asset62（room64）房体未进本批（CODE 928→asset61、929→asset63 门卡已见，下批延续）。
- iceblock(159)×三连房，但其行为契约（CODE 687/688/689 melting/type）仍未建立——本段 iceblock 密度上升，建议下一批与其配对。
- hulkingbandit/weaponswap 行为契约未建立；真机/GPU 视觉层未验收（同一口径）。
