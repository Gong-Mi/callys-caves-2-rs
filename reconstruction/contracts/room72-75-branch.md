# room72-75（asset rooms 71-74）后门链第十四段契约

`room_bindings` 锚定 gml 房名 = asset 索引 +1（asset71=room72 … asset74=room75；分段规律同第十三段，见 room68-71-branch.md）。门卡 CODE 946-953 逐条字节码核验，八门全部 `unlocked=1` 在活实例字段断言。

## 门链（真实踩门贯通，双向返程逐站钉落点）

- asset70（room71）CODE 945 → asset71 落点 (128,192)；asset71 CODE 946 → asset70 落点 (896,140)。
- asset71 CODE 947 → asset72 落点 (448,684)（非边缘门，房体内部）；asset72 CODE 949 → asset71 落点 (2240,364)。
- asset72 CODE 948 → asset73 落点 (128,108)；asset73 CODE 950 → asset72 落点 (1920,236)。
- asset73 CODE 951 → asset74 落点 (128,204)；asset74 CODE 952 → asset73 落点 (1408,684)。
- asset74 CODE 953 → asset75 (672,684) 门卡延续（房体未进本批）。

## 卡司（运行时实测固化）

- asset71（room72, 2400x480）：wall×266、wall_2×203、boulder×117、knifebandit×1、shooter1×1、firehulk×3、hulkingbandit×2、enemy2×1、wolf×2、bat×3、coin×24、chest×1、**woodblock×4**（本分支首现 obj_woodblock(158)——既有契约仅锚定其卡司计数，其 Create/Destroy/Collision 36（CODE 684/685/686）行为契约未建）；iceblock/gem 零负断言。
- asset72（room73, 2048x1024）：wall×319、wall_2×374、**boulder×320**（本分支最重巨石场）、platform×6、shooter1×2、skeleton×1、zombie×2、hulkingbandit×2、enemy2×2、fireslime×4、coin×13、**gem×2**（chest vault 之后首对宝石）、chest×4、**boulderblock×4**（分支第五块火箭收益房）、iceblock×2。
- asset73（room74, 1536x800）：wall×258、wall_2×233、boulder×144、knifebandit×1、shooter1×2、firehulk×1、hulkingbandit×1、wolf×1、bat×2、slime×2、fireslime×1、coin×26；chest/woodblock 零——混编行军房。
- asset74（room75, 512x1536）：wall×108、wall_2×242、boulder×128、platform×2、skeleton×1、hulkingbandit×1、enemy2×1、**ghost×2**、coin×21；chest/wolf 零——竖塔房（512 宽、1536 高）。

## 测试

`crates/core/tests/room72_75_branch_ir.rs` 4 项：逐房全量卡司 + 双门 + unlocked 断言；第 4 项 asset74→73→72→71→70 整段返程逐站钉落点（(1408,684)/(1920,236)/(2240,364)/(896,140)）。探针实测后固化为断言，探针文件已删。

## 边界

- asset75（room76）房体未进本批（CODE 954/955 门卡已见，下段延续）。
- hulkingbandit(21)/firehulk(18) 行为契约仍欠；obj_flamethrower(77)、obj_woodblock(158, CODE 684/685/686) 行为未建。
- 引擎统一包围盒碰撞近似（全批同口径）；真机/GPU 视觉层未验收。
