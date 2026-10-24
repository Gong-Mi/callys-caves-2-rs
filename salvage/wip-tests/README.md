# WIP 测试打捞（2026-10-24 工作区清理）

这三份文件原本是 `~/cally-worktrees/wl58-hud`、`wl59-ui-alarms`、`wl60-levelup-particles`
三棵工作树里**未跟踪、也未进 main** 的唯一内容。三棵树的 HEAD 都等于 origin/main
(60f2f16)，所以树本身是已并入的残留；删树前把唯一内容取出，避免丢失。

| 文件 | 原工作树 | sha256 | 状态 |
| --- | --- | --- | --- |
| crates/core/tests/levelup_particle_table_ir.rs | wl60-levelup-particles | 6df284364b9733038ebf49a049aa124f9470c3c8df11f6447d1f69127f4cd6e8 | 编译通过，6/6 测试通过，已作为正式测试提交 |
| salvage/wip-tests/ui_hud_matrix_ir.rs | wl58-hud | 7121adad279c9d97d2d15ec57add3f00e143d188ae7b1bbb6bdf55e011a1563f | 编译失败，未修改内容 |
| salvage/wip-tests/ui_progression_tables_ir.rs | wl59-ui-alarms | 5ca43b09ad2a0971658a38b1e340fd414455b5bbdda1505d72628a39733252d5 | 编译失败，未修改内容 |

`salvage/wip-tests/` 不在 cargo 测试目标里（不是 `tests/` 目录），因此不影响 workspace 构建。

## 已知编译错误（原样保留，未修）

ui_hud_matrix_ir.rs：

    error[E0609]: no field `fog` on type `ExpDraw`
    error[E0502]: cannot borrow `out` as mutable because it is also borrowed as immutable
    error[E0502]: cannot borrow `out` as immutable because it is also borrowed as mutable
    error[E0502]: cannot borrow `out` as immutable because it is also borrowed as mutable

ui_progression_tables_ir.rs：

    error[E0308]: mismatched types   (ui_progression_tables_ir.rs:825:13, `level`)

要复活这两份，先按当前 `ExpDraw` 字段和借用形状改到能编译，再按字节码核对期望值；
不要在没编译通过前把它们挪回 `crates/core/tests/`。
