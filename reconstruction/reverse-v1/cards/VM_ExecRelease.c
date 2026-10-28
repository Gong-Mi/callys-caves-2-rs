/* cally 逆向卡：VM::ExecRelease（原版 libyoyo.so，armv7）
 *
 * @func  0x000e4540 0x000e47c8   size 648   162 条指令
 * 级别:  骨架（循环骨架已证，逐条语义未钉）
 * 符号:  _ZN2VM11ExecReleaseER6VMExecP6RValue → VM::ExecRelease(VMExec&, RValue*)
 * 锚表:  reconstruction/reverse-v1/asm/index-VM_ExecRelease.tsv
 *
 * 已证（asm 直读，地址见下方锚点）：
 *   1. **线程化派发（threaded dispatch）**，不是 switch/跳转表：
 *        r2 = [VMExec+0x58]            ; 处理器指针表基址
 *        r3 = [VMExec+0x48]            ; 当前 pc（索引）
 *        r6 = [r2 + r3*4]              ; 取该 pc 对应的处理器指针
 *        pc+1 → [VMExec+0x48]          ; 先自增再调用（e45c4/e45c8）
 *        blx r6                        ; e4620 —— 调用处理器，参数为 VMExec*
 *      处理器返回后 e4624 起重新取指，形成循环。
 *   2. 循环带出口条件：e45d0 的 `bge 0xe46a0` 在前置比较满足时跳到函数尾部；
 *      该比较的输入尚未回溯（open）。
 *   3. 本函数引用 `PerformReturn(uchar*, VMExec*)`（e473c），即正常退栈路径也在这里。
 *   4. 其它被调：MemoryManager::Free、YYObjectBase::Free（各一次），无 RValue 锁相关调用。
 *
 * 未钉：VMExec 的完整布局（已证被读写：+0x24、+0x44、+0x48、+0x54、+0x58、+0x5c）；
 *       出口条件的判据；64 个字节码如何映射到 48 个 Do* 处理器。
 * 结论：原版用的是**预解析处理器表 + blx**，所以每个 opcode 的语义都在 Do* 处理器里，
 *       这解释了为什么 VM::Exec/ExecRelease 里看不到 opcode 比较链。
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
