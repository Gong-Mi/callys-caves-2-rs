# WIP 测试打捞（2026-10-24 工作区清理）

这三份文件原本是 `~/cally-worktrees/wl58-hud`、`wl59-ui-alarms`、`wl60-levelup-particles`
三棵工作树里**未跟踪、也未进 main** 的唯一内容。三棵树的 HEAD 都等于 origin/main
(60f2f16)，所以树本身是已并入的残留；删树前把唯一内容取出，避免丢失。

## 状态

| 文件 | 原工作树 | 打捞时 sha256 | 状态 |
| --- | --- | --- | --- |
| crates/core/tests/levelup_particle_table_ir.rs | wl60-levelup-particles | 6df284364b9733038ebf49a049aa124f9470c3c8df11f6447d1f69127f4cd6e8 | 已作为正式测试提交（#124），6/6 通过 |
| crates/core/tests/ui_hud_matrix_ir.rs | wl58-hud | 7121adad279c9d97d2d15ec57add3f00e143d188ae7b1bbb6bdf55e011a1563f | 已复活并提交，8/8 通过 |
| crates/core/tests/ui_progression_tables_ir.rs | wl59-ui-alarms | 5ca43b09ad2a0971658a38b1e340fd414455b5bbdda1505d72628a39733252d5 | 已复活并补齐测试入口，8/8 通过 |

后两份的原文已从本目录移入 `crates/core/tests/`；其打捞时的字节内容仍可在 #124
的提交 `78ed335` 里取回（sha256 见上表）。

## 复活时改了什么（第一轮真正跑起来才暴露的）

编译层：

- `ui_hud_matrix_ir.rs`：`fog` 是 `DrawCommand` 的字段，不是本地投影结构 `ExpDraw`
  的；原来在投影后误读 `got.fog`。另有两处 `out` 的不可变借用跨 `iter_mut()`
  （改成先快照 spans/keys），以及 `block_view` 闭包与 `out[i].role` 写入冲突。
- `ui_progression_tables_ir.rs`：`BannerArm.level` 是 `String`，赋值处传的是 `&str`；
  该文件打捞时**没有任何 `#[test]`**，本轮补了 8 个入口。

语义层（**以字节码为准**，GML 只作导航）：

- CODE 368 头部守卫的 `bf` 落点是「生成调用 popz 之后」（code_offset 16 → 84），不是
  生成的第一条指令；它包住「清 latch + 生成」整块。
- CODE 368 玩家块里 `level += 1` 的 `add` 在指令 `[28]`，不是 `[27]`。
- 12 个 XP 块的起点是 `[78]`（`load <w>xp; load <w>xptolevelup` 首对），不是 `[62]`
  ——`[62]` 是 `coinsound` 的 `choose()` 实参。
- XP 块「守卫内 store」的边界是**内层** `level < 10` 的 `bf`（`[i+7]`），不是外层阈值
  `bf`（`[i+3]`）；两者只在 pistol 上不同（1 个 vs 4 个 store），而这正是要钉的下发版
  怪癖。块结束仍按外层 `bf` 推进。
- `derive_spawn` 的偏移必须是有符号的：武器横幅是 `y + 132`，升级浮层是 `y - 32`。
- HUD 台账把「health 组的 view 闸门」与「22 条 health1 分支」混成了一个角色：六个闸门
  是独立 if 链（`bf` 指向下一条测试），只要玩家存在，它们的比较在**每个** view 上都会
  执行；22 条分支才只在对应 view 内跑。
- `level >= 10` / `>= 20` 都是 `< 10` / `< 20` 的 else 分支，比较只在 then 分支失败后
  执行（`b` 会先跳过它），台账期望要跟着条件化。
- 负控 (2) 的第三段原本写成 `expect_err`（视图 3 本该不受扰动影响）；负控 (3) 原本假设
  改 `bf`（**比较为假才跳**）能影响 `health1 == 2` 的真分支——改成把 `bf` 指向自己的臂
  体，让其它 health1 值多画一段。

## 不要做的事

- 不要在没有跑通前把内容改回本目录当备份——提交历史才是备份。
- 期望值一律从 `crates/core/src/generated/full_ir.json` 直读，或由 `validate_*` 在运行时
  交叉核对；不要拿恢复 GML 的分译结构当 oracle。
