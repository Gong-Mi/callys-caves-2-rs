# room76-79（asset rooms 75-78）后门链第十五段契约

`room_bindings` 锚定 gml 房名 = asset 索引 +1（asset75=room76 … asset78=room79；分段规律同第十三/十四段，见 room68-71-branch.md）。门卡 CODE 954-961 逐条字节码核验，八门全部 `unlocked=1` 在活实例字段断言。

## 门链（真实踩门贯通，双向返程逐站钉落点）

- asset74（room75）CODE 953 → asset75 落点 (672,684)；asset75 CODE 955 → asset74 落点 (320,1420)。
- asset75 CODE 954 → asset76 落点 (128,204)；asset76 CODE 956 → asset75 落点 (1344,1100)。
- asset76 CODE 957 → asset77 落点 (128,172)；asset77 CODE 958 → asset76 落点 (1920,108)。
- asset77 CODE 959 → asset78 落点 (128,108)；asset78 CODE 960 → asset77 落点 (1152,204)。
- asset78 CODE 961 → asset79 (128,204) 门卡延续（房体未进本批）。

## 卡司（运行时实测固化）

- asset75（room76, 1472x1216）：wall×77、**wall_2×652**（本分支 wall_2 最密房）、boulder×255、**platform×30**（本分支平台最密房，竖直攀爬宝库）、knifebandit×1、shooter2×1、hulkingbandit×3、coin×21、**chest×7**；iceblock 零负断言。
- asset76（room77, 2048x480）：wall×228、wall_2×238、boulder×93、**ghost×6**（本分支 ghost 最密房）、coin×10、iceblock×4、**obj_laser(80)×1**（本分支首个激光枪拾取；Create CODE 400 / Step CODE 401，与已验收三武器同构）；未购时 CODE 400 额外生成 obj_pickupflare(70) 信标一枚（非布置实例）；chest 零负断言。
- asset77（room78, 1280x1280）：wall×210、wall_2×254、boulder×291、platform×4、knifebandit×2、shooter1×1、skeleton×2、zombie×3、enemy2×1、bat×1、fireslime×2、coin×31、chest×1——地穴混编房。
- asset78（room79, 1600x640）：wall×211、wall_2×201、boulder×119、enemy2×3、ghost×4、bat×5、coin×25、**chest×7**（与 asset75 并列本分支最大宝库）、**boulderblock×2**（火箭收益房）；iceblock/laser 零负断言。

## 测试

`crates/core/tests/room76_79_branch_ir.rs` 4 项：逐房全量卡司 + 双门 + unlocked 断言；第 4 项 asset78→77→76→75→74 整段返程逐站钉落点（(1152,204)/(1920,108)/(1344,1100)/(320,1420)）。探针实测后固化为断言，探针文件已删。

## 边界

- asset79（room80）房体未进本批（CODE 962/963 门卡待读，下段延续）。
- **obj_laser(80) 拾取链已由 `laser-pickup-chain.md` 与 `crates/core/tests/laser_pickup_ir.rs` 覆盖；obj_bladegun/obj_flamethrower/obj_bombgun/obj_boomerang 的拾取链已由后续 `weapons4-pickup-chain.md` 配对闭环。**
- hulkingbandit(21)/firehulk(18) 行为契约仍欠；obj_flamethrower(77) 的拾取链已建，但火焰弹道仍欠。
- 引擎统一包围盒碰撞近似（全批同口径）；真机/GPU 视觉层未验收。