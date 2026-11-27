# 差分里程碑 1 实测（2026-10-28）

harness 本身是通的：4400 例、两边都跑完、逐字段比对、第一处不等能给出最小复现。**结果是「不等价」**，
下面是真实数字和归因，不是"两边都能跑"的结论。

## 实测

    cases                     4400（22 op × 200，seed 0xCA11）
    c 侧输出                 4400 行（2707 ok / 1693 error）
    rust 侧输出              4400 行
    完全一致                   27 例（0.6%）
    只有 sp 不同              213
    只有 bytes 不同            23
    bytes + tag 不同           33
    sp + bytes 不同            85
    sp + bytes + tag 不同    1020
    ok 状态相反              1426（C 成功/Rust 报错 1306，反向 120）
    两边都错但错误串不同      1566
    两边同错且串相同            7

## 归因（四类，都不是"个别 bug"）

    1  值模型不同（最大项，约 1370 例）
       Rust 侧栈是 Vec<f64>、无 tag；C 侧按卡实现 16 字节 RValue + tag
       （0/13 real、1 string、2 array、3 pointer、5 undefined、7 int32、10 int64、13 bool）
       ⇒ int32 回绕、int64、字符串拼接在 Rust 侧根本表示不出来

    2  sp 口径不同（约 1300 例，与 1 有重叠）
       C 按卡的字节差（int+int = +4、real+real = +8、串拼接 = -8）
       Rust 按 16 字节槽（二元一律 -16）

    3  op 覆盖不同（1306 例）
       Rust 的 code_vm::Op 没有 rem / mod / or / xor / shl / shr / neg
       ⇒ 这些 op 只有 C 侧有真值，比的是"实现了 vs 没实现"

    4  错误串不同（1566 例）
       C 用卡里抄录的 .rodata 原文（`DoDiv :: Divide by zero` 等）
       Rust 用自家的错误文本

## 结论

这不是"差分发现了很多 bug"，而是**两个语义模型不同**：C 侧忠于原版的值模型，Rust 侧是一个 f64-only
的重建。在值模型统一之前，任何"等价"声明都不成立。

按用户决定：**ART / javam 的动态语义分析延后**，先把静态逆向与语义化框架补齐。下一步顺序：

    1  写死值模型契约（reconstruction/contracts/value-model.md）——tag、位宽、提升规则、错误串表
    2  让 Rust 侧按契约改造（新增 tagged value 类型）；这是改动库，不是适配层能绕过的
    3  重跑本 harness，目标：identical 占据绝大多数，剩余差异逐条归因
    4  静态继续推进对象模型（CInstance/CObjectGM/CRoom/CSprite），为里程碑 2 的整段轨迹差分铺路

## 2026-10-28 第二次实测（C 侧按修正后的卡更新；Rust 侧只改协议字段）

    C 侧     diff/c/vm_ref.c：tag 5/12 的注释与语义按 claims RVALUE-004 改写（5=undefined、12=null=0.0）；
             编译零警告（clang -O2 -std=c11 -Wall -Wextra）
    Rust 侧  op_eval.rs：失败行补上 "sp": 0（协议要求 ok=false 时 sp==0）；sp 保持 VM 自己的槽计数。
             **试过 ×16 换算，反而错得更远**：push_immediate 卡里是 -4 字节，×16 得 -256。
             结论：原版 sp 是**按操作数宽度**推进（4/8/16），不是固定 16 字节/槽，不能用比例换算。

### 全量 4400 例

    identical            27   0.6%
    sp+bytes+tag       1020
    ok 相反            1426   (C 成 / Rust 错 1306，反向 120)
    error 串不同       1566
    其余（单字段差）     361

### 数值可比子集（1264 例：只取两边都实现的 15 个 op，且 tag 全在 0/7/10/13）

    identical            15   1.2%
    sp+bytes+tag        763  60.4%
    ok 相反             211  16.7%
    sp only             175  13.8%
    sp+bytes             62   4.9%
    bytes(+tag)          23   1.8%
    error 其他           15   1.2%

**这一栏才是真问题**：即使只看两边都支持、tag 全是数值的用例，仍有约 **67%** 的结果值不同
（sp+bytes+tag 763 + sp+bytes 62 + bytes* 23）。原因不是"缺 tag"这一层，而是 **f64 模型本身在数值上不等价**：
int32 回绕、int64 精度、整数除法/移位语义在 Rust 侧全是 f64 近似。

### 结论（对下一步的约束）

    1  只补 tag 不够：`Vec<f64>` 必须换成 {tag, 数值联合} 的值类型，否则 int32 回绕这类差异永远在
    2  sp 不能用换算对齐：VM 的栈单位要按操作数宽度推进（DoPushImmediate 4 字节、二元按宽度和）
    3  这两个都是 crates/core 的库内改动，适配层绕不过去
