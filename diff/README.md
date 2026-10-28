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
