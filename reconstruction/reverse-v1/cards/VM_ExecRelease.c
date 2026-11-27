/* cally 逆向卡：VM::ExecRelease（原版 libyoyo.so，armv7）
 *
 * @func 0xe4540 0xe47c8  size 648  162 条索引记录（152 指令 + 10 池字）
 * 级别:  骨架（本卡保留原始指令；完整 C 本体候选在 c/vm_exec_release/）
 * 符号:  _ZN2VM11ExecReleaseER6VMExecP6RValue → VM::ExecRelease(VMExec&, RValue*)
 * 锚表:  reconstruction/reverse-v1/asm/index-VM_ExecRelease.tsv
 *
 * tier: bytecode_anchored（此处指固定 ARMv7 ELF 的静态证据）
 * 已证（完整取证链见 reconstruction/contracts/vm-buffer-dispatch.md）：
 *   1. 入循环或退帧重入时，e4598..e45cc 用字节 PC (+0x44) 有符号除 4，
 *      先经 [+0x5c][PC/4] 得密集槽位，然后由 [+0x58][槽位] 取处理器；
 *      +0x48 在 e45c8 写「槽位+1」，不是字节 PC。e45d0 的有符号 PC >= [+0x50]
 *      发生在两次读表及槽位写回之后。两表出自 VMBuffer::convertBuffer (0xec750)，
 *      不是 .data 的 32 项 g_instructions 本身。
 *   2. e45dc..e4620 用 [+0x24]+PC 读指令字；向处理器传 (指令字、当前值栈顶、
 *      指令地址+4、VMExec*)。e45e4/e4618 先分别写旧 PC (+0x54) 和下一字节 PC (+0x44)：
 *      步长通常 4；位 30 置位则加 g_paramSize[bits19:16]。e4628..e4644 重读下一槽位和表、
 *      预取下一处理器，把本次 r0 作为值栈顶；处理器可在自身调用期间改写 VMExec。
 *   3. e46a0..e4750 在 +0x4c > 0 时调用 PerformReturn，再填三个零字并重走入口取槽；
 *      否则到顶层退出。e46ac..e46c4/e477c..e4798 的四字结果写回要求 out 非空且
 *      执行到出口时重读的 +0x28 栈边界高于当前值栈顶（无符号比较）。
 *   4. 另外直接调用 MemoryManager::Free、YYObjectBase::Free（各一个站点）。
 *   5. e4624..e4688：先采样异常字节再预取；命中条件比较两个实时全局，不比较入参。
 *      同值路复制异常四字到 g_pExceptionSP-16 后清标志；不同值先结束当前帧。
 *   6. e46c8..e4778：遍历页链按 [page+8,page+0x100008) 回收，否则调用通用 Free。
 *      回收后重读 +0x0c；为零且 +0x10 非空时调对象 Free，再清 +0x10。
 *
 * gap: PerformReturn 已真实链接进合成夹具；两类 Free、全局提供者和上游仍未接。
 *      合成运行不证明原件等价。
 */
/* @0xe4540 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 未钉 */
/* @0xe4544 mov r9, r1 —— 未钉 */
/* @0xe4548 ldr r5, [pc, #0x250] —— 未钉 */
/* @0xe454c mov r4, r0 —— 未钉 */
/* @0xe4550 ldr r3, [pc, #0x24c] —— 未钉 */
/* @0xe4554 sub sp, sp, #12 —— 未钉 */
/* @0xe4558 add r5, pc, r5 —— 未钉 */
/* @0xe455c ldr r1, [pc, #0x244] —— 未钉 */
/* @0xe4560 ldr r12, [r0, #0x28] —— 未钉 */
/* @0xe4564 mov r7, #0 —— 未钉 */
/* @0xe4568 ldr r3, [r5, r3] —— 未钉 */
/* @0xe456c ldr r2, [pc, #0x238] —— 未钉 */
/* @0xe4570 ldr r0, [r3] —— 未钉 */
/* @0xe4574 add r0, r0, #1 —— 未钉 */
/* @0xe4578 str r0, [r3] —— 未钉 */
/* @0xe457c ldr r3, [r5, r1] —— 未钉 */
/* @0xe4580 str r3, [sp] —— 未钉 */
/* @0xe4584 ldr r8, [r5, r2] —— 未钉 */
/* @0xe4588 ldr r2, [sp] —— 未钉 */
/* @0xe458c str r4, [r8] —— 未钉 */
/* @0xe4590 ldr r2, [r2] —— 未钉 */
/* @0xe4594 str r2, [sp, #0x4] —— 未钉 */
/* @0xe4598 ldr r2, [r4, #0x44] —— 未钉 */
/* @0xe459c ldr r1, [r4, #0x5c] —— 未钉 */
/* @0xe45a0 cmp r2, #0 —— 未钉 */
/* @0xe45a4 add r6, r2, #3 —— 未钉 */
/* @0xe45a8 ldr r3, [r4, #0x50] —— 未钉 */
/* @0xe45ac movge r6, r2 —— 未钉 */
/* @0xe45b0 ldr r0, [r4, #0x58] —— 未钉 */
/* @0xe45b4 asr r6, r6, #2 —— 未钉 */
/* @0xe45b8 cmp r2, r3 —— 未钉 */
/* @0xe45bc mov r3, r2 —— 未钉 */
/* @0xe45c0 ldr r1, [r1, r6, lsl #2] —— 未钉 */
/* @0xe45c4 add r6, r1, #1 —— 未钉 */
/* @0xe45c8 str r6, [r4, #0x48] —— 未钉 */
/* @0xe45cc ldr r6, [r0, r1, lsl #2] —— 未钉 */
/* @0xe45d0 bge 0xe46a0 <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x160> —— 未钉 */
/* @0xe45d4 ldr r1, [pc, #0x1d4] —— 未钉 */
/* @0xe45d8 ldr r10, [r5, r1] —— 未钉 */
/* @0xe45dc ldr r11, [r4, #0x24] —— 未钉 */
/* @0xe45e0 mov r1, #4 —— 未钉 */
/* @0xe45e4 str r3, [r4, #0x54] —— 未钉 */
/* @0xe45e8 ldr lr, [pc, #0x1c4] —— 未钉 */
/* @0xe45ec ldr r0, [r11, r2] —— 未钉 */
/* @0xe45f0 add r2, r11, r2 —— 未钉 */
/* @0xe45f4 add r2, r2, r1 —— 未钉 */
/* @0xe45f8 tst r0, #1073741824 —— 未钉 */
/* @0xe45fc ubfx r11, r0, #0x10, #0x4 —— 未钉 */
/* @0xe4600 ldrne r1, [r5, lr] —— 未钉 */
/* @0xe4604 ldrne r1, [r1, r11, lsl #2] —— 未钉 */
/* @0xe4608 ldr r11, [pc, #0x1a8] —— 未钉 */
/* @0xe460c addne r1, r1, #4 —— 未钉 */
/* @0xe4610 add r3, r1, r3 —— 未钉 */
/* @0xe4614 mov r1, r12 —— 未钉 */
/* @0xe4618 str r3, [r4, #0x44] —— 未钉 */
/* @0xe461c mov r3, r4 —— 未钉 */
/* @0xe4620 blx r6 —— 未钉 */
/* @0xe4624 ldrb r2, [r10] —— 未钉 */
/* @0xe4628 ldr r3, [r4, #0x48] —— 未钉 */
/* @0xe462c cmp r2, #0 —— 未钉 */
/* @0xe4630 ldr r2, [r4, #0x58] —— 未钉 */
/* @0xe4634 add r6, r3, #1 —— 未钉 */
/* @0xe4638 ldr r1, [pc, #0x17c] —— 未钉 */
/* @0xe463c str r6, [r4, #0x48] —— 未钉 */
/* @0xe4640 ldr r6, [r2, r3, lsl #2] —— 未钉 */
/* @0xe4644 mov r12, r0 —— 未钉 */
/* @0xe4648 ldr r0, [pc, #0x170] —— 未钉 */
/* @0xe464c beq 0xe468c <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x14c> —— 未钉 */
/* @0xe4650 ldr r3, [r5, r1] —— 未钉 */
/* @0xe4654 ldr r2, [r8] —— 未钉 */
/* @0xe4658 ldr r3, [r3] —— 未钉 */
/* @0xe465c cmp r2, r3 —— 未钉 */
/* @0xe4660 bne 0xe46a0 <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x160> —— 未钉 */
/* @0xe4664 ldr r12, [r5, r11] —— 未钉 */
/* @0xe4668 ldr r11, [r5, r0] —— 未钉 */
/* @0xe466c ldm r12!, {r0, r1, r2, r3} —— 未钉 */
/* @0xe4670 ldr r11, [r11] —— 未钉 */
/* @0xe4674 sub r12, r11, #16 —— 未钉 */
/* @0xe4678 str r0, [r11, #-0x10] —— 未钉 */
/* @0xe467c str r1, [r12, #0x4] —— 未钉 */
/* @0xe4680 str r2, [r12, #0x8] —— 未钉 */
/* @0xe4684 str r3, [r12, #0xc] —— 未钉 */
/* @0xe4688 strb r7, [r10] —— 未钉 */
/* @0xe468c ldr r3, [r4, #0x44] —— 未钉 */
/* @0xe4690 ldr r2, [r4, #0x50] —— 未钉 */
/* @0xe4694 cmp r3, r2 —— 未钉 */
/* @0xe4698 mov r2, r3 —— 未钉 */
/* @0xe469c blt 0xe45dc <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x9c> —— 未钉 */
/* @0xe46a0 ldr r3, [r4, #0x4c] —— 未钉 */
/* @0xe46a4 cmp r3, #0 —— 未钉 */
/* @0xe46a8 bgt 0xe4734 <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x1f4> —— 未钉 */
/* @0xe46ac ldm sp, {r2, r3} —— 未钉 */
/* @0xe46b0 cmp r9, #0 —— 未钉 */
/* @0xe46b4 str r3, [r2] —— 未钉 */
/* @0xe46b8 beq 0xe46c8 <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x188> —— 未钉 */
/* @0xe46bc ldr r3, [r4, #0x28] —— 未钉 */
/* @0xe46c0 cmp r3, r12 —— 未钉 */
/* @0xe46c4 bhi 0xe477c <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x23c> —— 未钉 */
/* @0xe46c8 ldr r3, [pc, #0xf4] —— 未钉 */
/* @0xe46cc ldr r0, [r4, #0x8] —— 未钉 */
/* @0xe46d0 ldr r12, [r5, r3] —— 未钉 */
/* @0xe46d4 ldr r3, [r12, #0x4] —— 未钉 */
/* @0xe46d8 cmp r3, #0 —— 未钉 */
/* @0xe46dc beq 0xe4708 <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x1c8> —— 未钉 */
/* @0xe46e0 add r1, r3, #8 —— 未钉 */
/* @0xe46e4 add r2, r3, #1048576 —— 未钉 */
/* @0xe46e8 cmp r0, r1 —— 未钉 */
/* @0xe46ec add r2, r2, #8 —— 未钉 */
/* @0xe46f0 blo 0xe46fc <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x1bc> —— 未钉 */
/* @0xe46f4 cmp r2, r0 —— 未钉 */
/* @0xe46f8 bhi 0xe4754 <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x214> —— 未钉 */
/* @0xe46fc ldr r3, [r3] —— 未钉 */
/* @0xe4700 cmp r3, #0 —— 未钉 */
/* @0xe4704 bne 0xe46e0 <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x1a0> —— 未钉 */
/* @0xe4708 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> —— 未钉 */
/* @0xe470c ldr r5, [r4, #0xc] —— 未钉 */
/* @0xe4710 cmp r5, #0 —— 未钉 */
/* @0xe4714 bne 0xe472c <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x1ec> —— 未钉 */
/* @0xe4718 ldr r0, [r4, #0x10] —— 未钉 */
/* @0xe471c cmp r0, #0 —— 未钉 */
/* @0xe4720 beq 0xe472c <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x1ec> —— 未钉 */
/* @0xe4724 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_> —— 未钉 */
/* @0xe4728 str r5, [r4, #0x10] —— 未钉 */
/* @0xe472c add sp, sp, #12 —— 未钉 */
/* @0xe4730 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 未钉 */
/* @0xe4734 mov r0, r12 —— 未钉 */
/* @0xe4738 mov r1, r4 —— 未钉 */
/* @0xe473c bl 0xe42d8 <_Z13PerformReturnPhP6VMExec> —— 未钉 */
/* @0xe4740 str r7, [r0, #-0x4] —— 未钉 */
/* @0xe4744 sub r12, r0, #16 —— 未钉 */
/* @0xe4748 str r7, [r0, #-0x10] —— 未钉 */
/* @0xe474c str r7, [r0, #-0xc] —— 未钉 */
/* @0xe4750 b 0xe4598 <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x58> —— 未钉 */
/* @0xe4754 ldr r1, [r12, #0x8] —— 未钉 */
/* @0xe4758 ldr r2, [r12, #0x10] —— 未钉 */
/* @0xe475c ldr r3, [r12, #0xc] —— 未钉 */
/* @0xe4760 add r2, r2, #1 —— 未钉 */
/* @0xe4764 str r1, [r0] —— 未钉 */
/* @0xe4768 sub r3, r3, #1 —— 未钉 */
/* @0xe476c str r0, [r12, #0x8] —— 未钉 */
/* @0xe4770 str r2, [r12, #0x10] —— 未钉 */
/* @0xe4774 str r3, [r12, #0xc] —— 未钉 */
/* @0xe4778 b 0xe470c <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x1cc> —— 未钉 */
/* @0xe477c ldr r0, [r12] —— 未钉 */
/* @0xe4780 ldr r1, [r12, #0x4] —— 未钉 */
/* @0xe4784 ldr r2, [r12, #0x8] —— 未钉 */
/* @0xe4788 ldr r3, [r12, #0xc] —— 未钉 */
/* @0xe478c str r0, [r9] —— 未钉 */
/* @0xe4790 str r1, [r9, #0x4] —— 未钉 */
/* @0xe4794 str r2, [r9, #0x8] —— 未钉 */
/* @0xe4798 str r3, [r9, #0xc] —— 未钉 */
/* @0xe479c b 0xe46c8 <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x188> —— 未钉 */
/* @0xe47a0 ldrshteq sp, [r0], -r8 —— 未钉 */
/* @0xe47a4 .word 0xffffc0d4 —— 未钉 */
/* @0xe47a8 .word 0xffffc0bc —— 未钉 */
/* @0xe47ac .word 0xffffbf58 —— 未钉 */
/* @0xe47b0 .word 0xffffc0cc —— 未钉 */
/* @0xe47b4 .word 0xffffc09c —— 未钉 */
/* @0xe47b8 .word 0xffffc0d8 —— 未钉 */
/* @0xe47bc .word 0xffffc0dc —— 未钉 */
/* @0xe47c0 .word 0xffffc0e0 —— 未钉 */
/* @0xe47c4 .word 0xffffc0e4 —— 未钉 */
