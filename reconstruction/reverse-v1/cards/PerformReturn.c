/* cally 逆向卡：PerformReturn（原版 libyoyo.so，armv7）
 * @func 0xe42d8 0xe44d4  size 508  127 条指令
 * 级别: 骨架（帧弹出骨架已证，值搬运与 refcount 细节未展开）
 * 符号: _Z13PerformReturnPhP6VMExec → uchar* PerformReturn(uchar* sp, VMExec* exec)
 *
 * 已证（指令级，前 15 条）：
 *   ++<global counter>                          ; e42f4-e4300 取 GOT 三跳后 +1 写回（疑似调用计数/深度）
 *   if (<global byte flag>) goto 0xe449c        ; e4308/e4310 —— 调试/慢路径开关
 *   frame = exec->[0x28]                        ; e4314 —— 当前调用帧指针
 *   --exec->[0x4c]                              ; e4318-e4328 —— 帧深度自减（返回即出栈）
 *   resume = frame + 60                         ; e431c —— 帧内 +0x3c 保存恢复点
 *   if (*(void**)(frame+0x18) == 0) goto 0xe4490 ; e4320/e432c —— 空帧/末尾帧的特例
 *   随后从帧内 +0x0c / +0x24 / +0x04 / +0x20 取字段                    ; e4334-e4344
 *
 * 结论：
 *   1. exec->[0x28] 是**当前调用帧指针**，exec->[0x4c] 是**帧深度**（返回时自减）。
 *   2. 帧内至少五个字段：+0x04、+0x0c、+0x18、+0x20、+0x24，以及 +0x3c（恢复点）。
 *   3. PerformReturn 是 VM::ExecRelease 的唯二出口之一（另一处是循环出口 bge）。
 *
 * 帧格式已由 DoCallScript（cards/DoCallScript.c）闭合，本卡的 open 收窄为：
 *   frame+0x00 = **返回地址 / pc**（DoCallScript e8608/e8624 写入 exec[0x44]，
 *                本卡 e4354/e4390 用 str lr,[r6,#0x44] 还回去）——不是旧 sp
 *   frame+0x08 = 旧全局 Argument 绝对值；frame+0x38 = 旧 sp 相对栈基址的偏移
 *   ⇒ 早先 CALL-007「旧 sp 存 frame+0」的说法已 refuted（claims XFRAME-002）
 * open：self/other 落在帧内哪两个槽、refcount 的 4 段处理、全局计数器与调试标志的符号名。
 */
/* @0xe42d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe42dc mov r6, r1 */
/* @0xe42e0 ldr r5, [pc, #0x1d4] */
/* @0xe42e4 sub sp, sp, #12 */
/* @0xe42e8 ldr r3, [pc, #0x1d0] */
/* @0xe42ec add r5, pc, r5 */
/* @0xe42f0 ldr r2, [pc, #0x1cc] */
/* @0xe42f4 ldr r3, [r5, r3] */
/* @0xe42f8 ldr r1, [r3] */
/* @0xe42fc add r1, r1, #1 */
/* @0xe4300 str r1, [r3] */
/* @0xe4304 ldr r3, [r5, r2] */
/* @0xe4308 ldrb r3, [r3] */
/* @0xe430c cmp r3, #0 */
/* @0xe4310 bne 0xe449c <_Z13PerformReturnPhP6VMExec+0x1c4> */
/* @0xe4314 ldr r11, [r6, #0x28] */
/* @0xe4318 ldr r3, [r6, #0x4c] */
/* @0xe431c add r8, r11, #60 */
/* @0xe4320 ldr r4, [r11, #0x18] */
/* @0xe4324 sub r3, r3, #1 */
/* @0xe4328 str r3, [r6, #0x4c] */
/* @0xe432c cmp r4, #0 */
/* @0xe4330 beq 0xe4490 <_Z13PerformReturnPhP6VMExec+0x1b8> */
/* @0xe4334 ldr r3, [r11, #0xc] */
/* @0xe4338 ldr r1, [r11, #0x24] */
/* @0xe433c ldr r2, [r11, #0x4] */
/* @0xe4340 cmp r3, #0 */
/* @0xe4344 ldr r0, [r11, #0x20] */
/* @0xe4348 ldr r9, [r11, #0x10] */
/* @0xe434c movlt r3, #0 */
/* @0xe4350 ldr r7, [r11, #0x14] */
/* @0xe4354 ldr lr, [r11] */
/* @0xe4358 ldr r12, [r11, #0x1c] */
/* @0xe435c str r1, [r6, #0x34] */
/* @0xe4360 ldrge r1, [r6, #0x40] */
/* @0xe4364 str r2, [r6, #0x30] */
/* @0xe4368 ldrge r2, [r6, #0x8] */
/* @0xe436c rsbge r3, r3, r1 */
/* @0xe4370 str r0, [r6, #0x3c] */
/* @0xe4374 ldr r0, [r6, #0xc] */
/* @0xe4378 addge r3, r2, r3 */
/* @0xe437c ldr r1, [r4, #0x10] */
/* @0xe4380 ldr r2, [r4, #0x4] */
/* @0xe4384 cmp r0, #0 */
/* @0xe4388 str r9, [r6, #0x14] */
/* @0xe438c str r7, [r6, #0x18] */
/* @0xe4390 str lr, [r6, #0x44] */
/* @0xe4394 str r4, [r6, #0x2c] */
/* @0xe4398 str r12, [r6, #0x38] */
/* @0xe439c str r3, [r6, #0x28] */
/* @0xe43a0 str r1, [r6, #0x24] */
/* @0xe43a4 str r2, [r6, #0x50] */
/* @0xe43a8 beq 0xe44ac <_Z13PerformReturnPhP6VMExec+0x1d4> */
/* @0xe43ac ldr r2, [r11, #0x30] */
/* @0xe43b0 mov r0, r4 */
/* @0xe43b4 ldr r3, [r11, #0x2c] */
/* @0xe43b8 str r2, [r6, #0x10] */
/* @0xe43bc str r3, [r6, #0xc] */
/* @0xe43c0 bl 0xec750 <_ZN8VMBuffer13convertBufferEv> */
/* @0xe43c4 ldr r3, [r6, #0x44] */
/* @0xe43c8 ldr r2, [r6, #0x2c] */
/* @0xe43cc cmp r3, #0 */
/* @0xe43d0 add r0, r3, #3 */
/* @0xe43d4 ldr r1, [r4, #0x14] */
/* @0xe43d8 ldr r2, [r2, #0x18] */
/* @0xe43dc movlt r3, r0 */
/* @0xe43e0 asr r3, r3, #2 */
/* @0xe43e4 ldr r0, [r11, #0x28] */
/* @0xe43e8 str r1, [r6, #0x58] */
/* @0xe43ec ldr r3, [r2, r3, lsl #2] */
/* @0xe43f0 str r2, [r6, #0x5c] */
/* @0xe43f4 str r3, [r6, #0x48] */
/* @0xe43f8 bl 0x27d1d0 <_ZdlPv> */
/* @0xe43fc ldr r2, [pc, #0xc4] */
/* @0xe4400 ldr r3, [pc, #0xc4] */
/* @0xe4404 ldr r9, [r5, r2] */
/* @0xe4408 ldr r3, [r5, r3] */
/* @0xe440c str r3, [sp, #0x4] */
/* @0xe4410 ldr r3, [r9] */
/* @0xe4414 ldr r2, [sp, #0x4] */
/* @0xe4418 subs r5, r3, #1 */
/* @0xe441c ldr r4, [r2] */
/* @0xe4420 bmi 0xe4470 <_Z13PerformReturnPhP6VMExec+0x198> */
/* @0xe4424 mov r7, #0 */
/* @0xe4428 mov r10, #5 */
/* @0xe442c b 0xe4444 <_Z13PerformReturnPhP6VMExec+0x16c> */
/* @0xe4430 cmn r5, #1 */
/* @0xe4434 str r7, [r4, #0x8] */
/* @0xe4438 str r10, [r4, #0xc] */
/* @0xe443c str r7, [r4], #16 */
/* @0xe4440 beq 0xe446c <_Z13PerformReturnPhP6VMExec+0x194> */
/* @0xe4444 ldr r3, [r4, #0xc] */
/* @0xe4448 sub r5, r5, #1 */
/* @0xe444c sub r3, r3, #1 */
/* @0xe4450 bic r3, r3, #-16777216 */
/* @0xe4454 bic r3, r3, #3 */
/* @0xe4458 cmp r3, #0 */
/* @0xe445c bne 0xe4430 <_Z13PerformReturnPhP6VMExec+0x158> */
/* @0xe4460 mov r0, r4 */
/* @0xe4464 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe4468 b 0xe4430 <_Z13PerformReturnPhP6VMExec+0x158> */
/* @0xe446c ldr r3, [r9] */
/* @0xe4470 ldr r2, [r6, #0x8] */
/* @0xe4474 add r8, r8, r3, lsl #4 */
/* @0xe4478 ldr r3, [r11, #0x38] */
/* @0xe447c ldr r1, [r11, #0x8] */
/* @0xe4480 add r3, r2, r3 */
/* @0xe4484 ldr r2, [sp, #0x4] */
/* @0xe4488 str r1, [r9] */
/* @0xe448c str r3, [r2] */
/* @0xe4490 mov r0, r8 */
/* @0xe4494 add sp, sp, #12 */
/* @0xe4498 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe449c ldr r3, [pc, #0x2c] */
/* @0xe44a0 ldr r0, [r5, r3] */
/* @0xe44a4 bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0xe44a8 b 0xe4314 <_Z13PerformReturnPhP6VMExec+0x3c> */
/* @0xe44ac ldr r0, [r6, #0x10] */
/* @0xe44b0 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_> */
/* @0xe44b4 ldr r4, [r6, #0x2c] */
/* @0xe44b8 b 0xe43ac <_Z13PerformReturnPhP6VMExec+0xd4> */
/* @0xe44bc eorseq sp, r0, r4, ror #18 */
/* @0xe44c0 .word 0xffffc0d0 */
/* @0xe44c4 .word 0xffffbf18 */
/* @0xe44c8 .word 0xffffc0bc */
/* @0xe44cc .word 0xffffc0c0 */
/* @0xe44d0 .word 0xffffbf1c */
