# room56-59（asset rooms 54-57）后门链第十段契约

`room_bindings` 锚定 gml 房名 = asset 索引 +2（asset54=room56 … asset57=room59；+3 基准在 rm_boss3/asset48 打断后降为 +2，规律全量核对见 room68-71-branch.md 更正）。门卡 CODE 910-919 逐条字节码核验（各 8 指令），十门全部 `unlocked=1` 在活实例字段上断言（不只读 GML 文本）。

## 门链（真实踩门贯通，双向）

- asset53（room55）CODE 910 → asset54 落点 (128,140)；asset54 CODE 912 → asset53 落点 (640,684)。
- asset54 CODE 913 → asset55 落点 (608,556)；asset55 CODE 914 → asset54 落点 (640,1164)。
- asset55 CODE 915 → asset56 落点 (128,300)；asset56 CODE 916 → asset55 落点 (1376,908)。
- asset56 CODE 917 → asset57 落点 (128,364)；asset57 CODE 918 → asset56 落点 (1920,268)。
- asset57 CODE 919 → asset58 门卡延续（房体未进本批）。

注意：asset54 与 asset55 之间的两对门都不是边缘门（落点 608,556 / 640,1164 在房体内部），warp 图继续按 CODE 实参走。

## 卡司（运行时实测固化）

- asset54（room56, 800x1280）：wall×146、wall_2×211、boulder×180、**shooter2×2**、firehulk×1、hulkingbandit×1、enemy2×1、wolf×1、bat×3、coin×28、gem×3、chest×1、weaponswap×1；无 boulderblock（负断言）。
- asset55（room57, 1536x1024）：wall×234、wall_2×355、boulder×209、platform×2、firehulk×2、hulkingbandit×1、enemy2×2、ghost×2、bat×1、fireslime×1、coin×14、chest×3、**boulderblock×3**（全链第二段出现 boulderblock，火箭弹清石收益房，关联 bullets3-ballistics 契约）。
- asset56（room58, 2048x640）：wall×222、wall_2×333、boulder×226、platform×2、skeleton×2、**zombie×5**、hulkingbandit×1、bat×2、coin×21；无 chest/gem（负断言）。
- asset57（room59, 800x480）：wall×61、wall_2×157、boulder×46、zombie×4、**bat×5**、coin×34、无 chest；→asset58 门延续。

## 测试

`crates/core/tests/room56_59_branch_ir.rs` 4 项：逐房全量卡司 + 双门 + 十门 unlocked 断言；第 4 项额外把 asset57→56→55→54→53 整段返程走通并逐站钉落点坐标。探针实测后固化为断言，探针文件已删。

## 验收

本地 workspace 86→87 套件全量；exact-head 三 workflow（见 PR#33 评论回写）。

## 边界

- asset58（room60）房体未进本批。
- hulkingbandit(21)/weaponswap(126) 行为契约未建立（hulkingbandit 卡司已在第四段锚定）；gem/firehulk/iceblock 行为契约仍欠。
- 真机/GPU 视觉层未验收（与既往门链批同一口径）。
