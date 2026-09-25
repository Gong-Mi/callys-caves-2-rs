# room68-71（asset rooms 67-70）后门链第十三段契约

`room_bindings` 实测：asset67=room68、asset68=room69、asset69=room70、asset70=room71——rm_boss4（asset64）打断后 gml 房名 = asset 索引 +1（本段起全量核对，见文末偏移更正）。门卡 CODE 938-945 逐条字节码核验，八门全部 `unlocked=1` 在活实例字段断言。

## 偏移规律更正（系统性，覆盖第九至十三段）

全量 `room_bindings` dump 实证：gml 房名编号 = asset 索引 + 3 −（已过的 rm_bossN 数）。rm_boss3（asset48）前为 +3（至 asset47=room50）；rm_boss3 后 asset49=room51 起降为 +2（第九段 asset50=room52、第十段 asset54=room56、第十一段 asset58=room60、第十二段 asset62=room64——这些段契约里"+3 偏移第 N 次验证"的叙述是错的，门链数据与断言本身全部正确）；rm_boss4（asset64）后本段起为 +1；rm_boss5（asset82）后为 +0；rm_boss6（asset104）起为纯名房。今后新契约一律先查 `room_bindings` 再叙述，不再用"+3"作为规律。

## 门链（真实踩门贯通，双向返程逐站钉落点）

- asset66（room67）CODE 937 → asset67 落点 (128,108)；asset67 CODE 938 → asset66 落点 (1920,268)。
- asset67 CODE 939 → asset68 落点 (672,364)；asset68 CODE 941 → asset67 落点 (128,1164)。
- asset68 CODE 940 → asset69 落点 (1920,172)；asset69 CODE 943 → asset68 落点 (128,204)。
- asset69 CODE 942 → asset70 落点 (128,684)；asset70 CODE 944 → asset69 落点 (1920,620)。
- asset70 CODE 945 → asset71 (128,192) 门卡延续（房体未进本批）。

注意：asset67↔asset68 与 asset68↔asset69 的门对 CODE 号不连续递增（939→68 前向、940→69 前向、941→67 返程、942→70 前向、943→68 返程、944→69 返程）——warp 图继续按 CODE 实参走，不按号序猜。

## 卡司（运行时实测固化）

- asset67（room68, 1280x1280）：wall×281、wall_2×414（本分支 wall_2 最密房）、boulder×176、enemy×1、shooter1×1、skeleton×1、firehulk×2、hulkingbandit×2、enemy2×1、ghost×1、bat×1、coin×27；chest/iceblock/spikes/water 全零负断言——幽灵混编关房。
- asset68（room69, 800x480）：wall×58、wall_2×77、boulder×50、firehulk×1、**ghost×3**（单房最密）、coin×3、chest×2；bat/slime 零——ghost 育房。
- asset69（room70, 2048x800）：wall×318、wall_2×322、boulder×170、platform×5、**spikes×19**、shooter1×1、zombie×2、hulkingbandit×3、enemy2×1、ghost×1、bat×1、slime×1、**fireslime×5**（火史莱姆窝）、coin×32、**chest×6**（第二座六宝箱）、**boulderblock×3**（分支第四块火箭收益房）；iceblock 零。
- asset70（room71, 1024x800）：wall×65、wall_2×52、boulder×177、**watersurface×25**、waterfill×1、shooter1×1、zombie×2、shooter2×1、ghost×1、bat×1、coin×20；chest/spikes 零负断言——水穿越房。

## 测试

`crates/core/tests/room68_71_branch_ir.rs` 4 项：逐房全量卡司 + 双门 + unlocked 断言；第 4 项 asset70→69→68→67→66 整段返程逐站钉落点（(1920,620)/(128,204)/(128,1164)/(1920,268)）。探针实测后固化为断言，探针文件已删。

## 验收

本地 workspace 全量测试 + exact-head 三 workflow（见 PR#33 评论回写）。

## 边界

- asset71（room72）房体未进本批（CODE 946/947 门卡已见，下段延续）。
- hulkingbandit(21)/firehulk(18) 行为契约仍欠（本段卡司密度继续上升）；obj_flamethrower(77) 拾取与火焰弹道未建。
- 引擎统一包围盒碰撞近似（全批同口径）；真机/GPU 视觉层未验收。
