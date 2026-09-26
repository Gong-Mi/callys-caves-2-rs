# room80-83（asset rooms 79-82）Boss5 前后门链第十六段契约

`room_bindings` 锚定：asset79=`room80`、asset80=`room81`、asset81=`room82`、asset82=`rm_boss5`。门卡 CODE 962-969 逐条读取原始字节码并在活实例上断言 `unlocked=1`；本批从 asset78 真实踩门进入，向前到 Boss5，再逐站返程。

## 门链

- asset78（room79）CODE 961 → asset79，落点 `(128,204)`。
- asset79 CODE 962 → asset78，落点 `(1440,524)`；CODE 963 → asset80，落点 `(128,204)`。
- asset80 CODE 964 → asset79，落点 `(896,204)`；CODE 965 → asset81，落点 `(128,204)`。
- asset81 CODE 966 → asset80，落点 `(1152,364)`；CODE 967 → asset82，落点 `(128,140)`。
- asset82（rm_boss5）CODE 968 → asset81，落点 `(1440,204)`；CODE 969 → asset83，落点 `(128,204)`，本批只验证门卡延续，不进入 asset83 房体。

## 卡司（`game.droid` 原始 ROOM 实例计数 + IR 装载实测）

- asset79（room80, 1024×640）：wall×60、wall_2×169、boulder×152、fireslime×8、gem×3、coin×2、weaponswap×1。
- asset80（room81, 1280×480）：wall×81、wall_2×63、boulder×156、zombie×6、enemy2×1、chest×1、coin×12、weaponswap×1。
- asset81（room82, 1600×384）：wall×69、wall_2×120、boulder×45、watersurface×21、waterfill×9、ghost×4、enemy2×2、coin×13、weaponswap×1。
- asset82（rm_boss5, 1280×480）：wall×76、wall_2×120、boulder×56、platform×5、obj_boss5×1、weaponswap×1。

## 测试

`crates/core/tests/room80_83_branch_ir.rs` 1 项复合集成测试：

- 通过 asset78→79→80→81→82 的真实门链进入；
- 四个房间逐房断言尺寸对应的完整关键卡司、门目标、落点与 `unlocked=1`；
- 通过 asset82→81→80→79→78 的完整返程，断言每站落点及 room79 的 `weaponswap` 重物化。

## 边界

- asset83（room83）只被 CODE 969 作为后续目标门卡引用，房体与完整卡司待下一段。
- Boss5（obj_boss5=29）AI/伤害/击杀/封门生命周期未在本批建立；`weaponswap` 行为另有独立契约。
- 引擎统一使用既有包围盒碰撞近似；真机/GPU 视觉层未验收。
