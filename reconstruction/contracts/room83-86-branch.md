# room83-86 后 Boss5 分支门链契约

本批基于 `assets/game.droid` 的真实房间对象、`full_ir.json` 的 room binding 与 IR Scene 运行时实测。asset 索引是门 `warproom` 使用的真实编号；房名直接取 `room_bindings`，不按数字偏移猜测。

## 门链

- asset82 `rm_boss5` → asset83 `room83`：CODE 969，落点 `(128,204)`。
- asset83 `room83`：CODE 970 返回 asset82 `(1152,364)`；CODE 971 前往 asset84 `(128,108)`。
- asset84 `room84`：CODE 972 返回 asset83 `(1920,236)`；CODE 973 前往 asset85 `(128,204)`。
- asset85 `room85`：CODE 974 返回 asset84 `(352,1484)`；CODE 975 前往 asset86 `(128,204)`。
- asset86 `room86`：CODE 976 返回 asset85 `(1408,364)`；CODE 977 前往 asset87 `(128,204)`。

8 个门实例均在活 Scene 中断言 `unlocked=1`；测试沿现有真实传送链进入四房，再按反向门逐站回到 asset82，验证持久化玩家落点。

## 四房卡司

| asset / 房名 | 关键静态对象计数 |
|---|---|
| 83 / room83 | wall 105、wall_2 40、boulder 52、watersurface 50、waterfill 1、shooter1 8、coin 11、treasurechest 1、weaponswap 1 |
| 84 / room84 | wall 139、wall_2 190、boulder 134、skeleton 2、firehulk 1、enemy2 1、ghost 5、bat 1、coin 24、bombgun 1、weaponswap 1；bombgun Create 另生成 pickupflare 1 |
| 85 / room85 | wall 92、wall_2 92、boulder 104、skeleton 7、coin 20、gem 1、weaponswap 1 |
| 86 / room86 | wall 209、wall_2 446、boulder 243、spikes 25、firehulk 1、hulkingbandit 1、enemy2 1、ghost 4、bat 2、fireslime 2、coin 24、weaponswap 1 |

## 测试与边界

`crates/core/tests/room83_86_branch_ir.rs` 是本批唯一拓扑/卡司测试入口，覆盖门 CODE 970-977、四房完整关键卡司、asset84 的 bombgun 动态 beacon 与正向/反向落点。

本批不把卡司存在升级成敌人行为已恢复：skeleton、firehulk、hulkingbandit、room83 shooter1、ghost、bat、fireslime 仍需各自行为契约；Bombgun 弹道也不在本批（拾取链已由 `weapons4-pickup-chain.md` 覆盖）。仍未做真机/GPU 视觉验收。
