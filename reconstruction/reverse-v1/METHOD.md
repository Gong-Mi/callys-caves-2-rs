# 方法（已定，不再讨论）

这份文件的目的：把"怎么做才算数"钉死。以后谁接手，按这里做，不需要重新吵一遍方法。

## 1. 证据分层（不许混报）

    bytecode_anchored  每条指令都锚到二进制里的同一条指令，语义从 asm 推出
    oracle_anchored    与原版运行时/活体的数据对过（本仓库只用于少数实例表/房间表）
    test_anchored      只证明"两个自研实现互相一致"（C↔VM 差分属于这一层）
    host_authored      手写实现，没有原版对应（c-recon/src/*.c 属于这一层）

一条主张只能落在其中一层；**跨层升格必须补证据**，不能因为"看起来对"就往上写。

## 2. 锚点

    索引来源      scripts/asm_index.py 从 .so 生成（addr/word/mnem/operands），不接受手抄
    卡片格式      每条指令一行 `/* @0x<addr> <mnem> <operands> */`，操作数与索引逐字一致
    单卡校验      scripts/check_card_anchors.py → 必须 RESULT EXACT（缺/多/错操作数都算失败）
    全库校验      scripts/verify_reverse_v1.py → 对全局 instructions.jsonl(.xz) 逐地址比
    锚点写法      `/* @0x…` 与块注释内的 `* @0x…` 都接受（verify 的正则会两种都认）

## 3. ISA（ARM vs Thumb-2）

    .dynsym 的 st_value 为奇数 = Thumb-2（bit0 是 ISA 选择位）；地址要 &~1 归一
    无名 Thumb 不能靠"解码看起来像什么"判：0x2f8e0a 的 ARM 视图与 Thumb 视图都"看着合理"
    唯一可靠判据是**调用点编码**：`bl`/`blx` 状态保持 —— ARM bl 命中 0 且 Thumb bl 命中数与该段
      in-degree 逐字相同，才能定 Thumb；判定的段写进 asm/thumb_ranges_extra.txt，由 census 重解

## 4. 匿名区

    切分用三个信号（缺一不可）：bl 直接目标 / ARM prologue（push{...,lr}）/ .data·.rodata 里的
      数据指针（方法表入口，必须先过滤"落在指令边界上"，且 Thumb 指针要 &~1）
    段长 ≠ 函数长度：段长是"到下一个切分点的距离"；0x2f8e0a 的段 1,170 B 里入口只有 28 B
    无名段只能叫 anon_<addr>，级别最多骨架；不许给它编名字

## 5. 覆盖口径（三个数分开报）

    指令基线      649,229（Thumb 双遍解码后的真值；早期 627,423 是 ARM 误解码少算的）
    函数          9,538 个具名 + 272 个匿名合并块 → 切出 636 段
    语义覆盖      按 @func 起址去重的**上限估计**（整段计入，卡实际可能只覆盖段内一部分）
    capacity ≠ delivery：生成器能产出多少、已提交多少、已证明多少，是三个不同的数

## 6. 差分（C 参考实现 ↔ Rust VM）

    协议          reconstruction/contracts/opcode-diff-protocol.md（JSONL 逐行）
    用例          diff/gen_cases.py，种子 0xCA11，22 op × 200 = 4,400
    C 侧          diff/c/vm_ref.c，tier: host_authored，语义按卡
    Rust 侧       crates/core/examples/op_eval.rs，走真 VM（code_vm），不改库以迁就对比
    判据          ok / sp / result.bytes / result.tag / error 逐字段相等
    禁止          为了对齐而伪造 tag、用 ×16 换算 sp（已实测 −4 会变 −256）、
                  把"两边都能跑"当成等价

## 7. 交付与并发（踩过的坑）

    子代理并发上限 4（10 并发会把父进程打满，整批 0 交付，已发生两次）
    子代理必须增量落盘：卡头 + 第一节 → check → 落盘 → 追加；不许算完全部才写
    验收只看盘：git status + verify_reverse_v1；不信子代理自述（两次事故里自述都像"完成"）

## 8. 明确不做

    不驱动原版 app 逐帧操作（慢、不可复现）
    不用截图/像素当语义判据（像素是下游消费）
    不给无名函数编名字
    不把"我实现了"说成"原版是这样"
