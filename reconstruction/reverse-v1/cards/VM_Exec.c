/* cally 逆向卡：VM::Exec（原版 libyoyo.so，armv7）
 *
 * @func  0x000e7fd0 0x000e8588   size 1464   366 条指令
 * 级别:  骨架
 * 符号:  _ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_
 *        → VM::Exec(CCode*, YYObjectBase* self, YYObjectBase* other, RValue*, RValue*, int, RValue*, int, RValue*)
 * 锚表:  reconstruction/reverse-v1/asm/index-VM_Exec.tsv
 *
 * 已证（asm 直读）：
 *   1. 入口先从 GOT 取一个全局对象的 [+0x14] 字节（`ldrb r3,[r12,#0x14]`），
 *      `cmp #0; beq 0xe8210` —— 即按一个运行期开关（debug 标志）二选一。
 *   2. 两条路径分别调用 `VM::ExecDebug(VMExec&, RValue*, bool)`（0xe47c8, 992 B）
 *      与 `VM::ExecRelease(VMExec&, RValue*)`（0xe4540, 648 B），各出现一次。
 *   3. 从 CCode 读取的字段偏移：+0x50、+0x54、+0x58、+0x5c（汇编里以
 *      `ldr rN,[r6,#0x5x]` 出现），落到寄存器后再填 VMExec。
 *   4. 本函数不含间接跳转，真正的字节码主循环在 ExecDebug/ExecRelease 里。
 *
 * 未钉：九个形参各自的落位与用途；VMExec 结构体布局；debug 开关的符号名。
 * 下一步：ExecRelease（0xe4540，648 B）先做正文——它是唯一的线程化派发循环。
 */
/* @0xe7fd0 ldr r12, [pc, #0x580] —— 未钉 */
/* @0xe7fd4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 未钉 */
/* @0xe7fd8 add r12, pc, r12 —— 未钉 */
/* @0xe7fdc mov r9, r3 —— 未钉 */
/* @0xe7fe0 ldr r4, [pc, #0x574] —— 未钉 */
/* @0xe7fe4 ldrb r3, [r12, #0x14] —— 未钉 */
/* @0xe7fe8 sub sp, sp, #124 —— 未钉 */
/* @0xe7fec add r4, pc, r4 —— 未钉 */
/* @0xe7ff0 mov r6, r0 —— 未钉 */
/* @0xe7ff4 cmp r3, #0 —— 未钉 */
/* @0xe7ff8 mov r11, r1 —— 未钉 */
/* @0xe7ffc mov r10, r2 —— 未钉 */
/* @0xe8000 beq 0xe8210 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x240> —— 未钉 */
/* @0xe8004 ldr r3, [pc, #0x554] —— 未钉 */
/* @0xe8008 ldr r5, [r4, r3] —— 未钉 */
/* @0xe800c ldr r3, [pc, #0x550] —— 未钉 */
/* @0xe8010 ldr r2, [pc, #0x550] —— 未钉 */
/* @0xe8014 ldr r0, [r6, #0x58] —— 未钉 */
/* @0xe8018 ldr r3, [r4, r3] —— 未钉 */
/* @0xe801c ldr r2, [r4, r2] —— 未钉 */
/* @0xe8020 ldr r8, [r6, #0x5c] —— 未钉 */
/* @0xe8024 ldrb r3, [r3] —— 未钉 */
/* @0xe8028 ldr r2, [r2] —— 未钉 */
/* @0xe802c cmp r3, #0 —— 未钉 */
/* @0xe8030 ldr r7, [r6, #0x50] —— 未钉 */
/* @0xe8034 ldr r3, [r6, #0x54] —— 未钉 */
/* @0xe8038 str r2, [sp, #0x10] —— 未钉 */
/* @0xe803c str r0, [sp, #0xc] —— 未钉 */
/* @0xe8040 bne 0xe82a8 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x2d8> —— 未钉 */
/* @0xe8044 ldr lr, [r5, #0x8] —— 未钉 */
/* @0xe8048 mov r2, #16384 —— 未钉 */
/* @0xe804c str r11, [sp, #0x2c] —— 未钉 */
/* @0xe8050 cmp lr, #0 —— 未钉 */
/* @0xe8054 str r10, [sp, #0x30] —— 未钉 */
/* @0xe8058 str r2, [sp, #0x58] —— 未钉 */
/* @0xe805c beq 0xe832c <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x35c> —— 未钉 */
/* @0xe8060 ldr r10, [r5, #0x10] —— 未钉 */
/* @0xe8064 movw r12, #0x3ff0 —— 未钉 */
/* @0xe8068 ldr r0, [lr] —— 未钉 */
/* @0xe806c ldr r1, [sp, #0xa4] —— 未钉 */
/* @0xe8070 add r12, lr, r12 —— 未钉 */
/* @0xe8074 str r0, [r5, #0x8] —— 未钉 */
/* @0xe8078 sub r10, r10, #1 —— 未钉 */
/* @0xe807c ldr r0, [r7, #0x4] —— 未钉 */
/* @0xe8080 lsl r2, r1, #4 —— 未钉 */
/* @0xe8084 ldr r11, [r7, #0x10] —— 未钉 */
/* @0xe8088 rsb r12, r2, r12 —— 未钉 */
/* @0xe808c str r3, [sp, #0x50] —— 未钉 */
/* @0xe8090 ldr r3, [sp, #0xc] —— 未钉 */
/* @0xe8094 str lr, [sp, #0x20] —— 未钉 */
/* @0xe8098 ldr lr, [r5, #0xc] —— 未钉 */
/* @0xe809c ldr r1, [sp, #0xa8] —— 未钉 */
/* @0xe80a0 str r0, [sp, #0x68] —— 未钉 */
/* @0xe80a4 mov r0, r12 —— 未钉 */
/* @0xe80a8 str r10, [r5, #0x10] —— 未钉 */
/* @0xe80ac add lr, lr, #1 —— 未钉 */
/* @0xe80b0 str r11, [sp, #0x3c] —— 未钉 */
/* @0xe80b4 add r11, sp, #24 —— 未钉 */
/* @0xe80b8 str lr, [r5, #0xc] —— 未钉 */
/* @0xe80bc str r7, [sp, #0x44] —— 未钉 */
/* @0xe80c0 str r3, [sp, #0x54] —— 未钉 */
/* @0xe80c4 str r8, [sp, #0x4c] —— 未钉 */
/* @0xe80c8 bl 0xb65bc <memcpy@plt> —— 未钉 */
/* @0xe80cc ldr r5, [pc, #0x498] —— 未钉 */
/* @0xe80d0 mov r1, #0 —— 未钉 */
/* @0xe80d4 ldr lr, [pc, #0x494] —— 未钉 */
/* @0xe80d8 mov r2, #60 —— 未钉 */
/* @0xe80dc ldr r10, [sp, #0xa4] —— 未钉 */
/* @0xe80e0 ldr r7, [r4, r5] —— 未钉 */
/* @0xe80e4 ldr r5, [r4, lr] —— 未钉 */
/* @0xe80e8 str r10, [sp, #0x38] —— 未钉 */
/* @0xe80ec ldr r10, [r7] —— 未钉 */
/* @0xe80f0 ldr r8, [r5] —— 未钉 */
/* @0xe80f4 sub r3, r0, #60 —— 未钉 */
/* @0xe80f8 mov r12, r0 —— 未钉 */
/* @0xe80fc str r3, [sp, #0x40] —— 未钉 */
/* @0xe8100 mov r0, r3 —— 未钉 */
/* @0xe8104 ldr r3, [sp, #0xa4] —— 未钉 */
/* @0xe8108 str r12, [sp, #0x34] —— 未钉 */
/* @0xe810c str r12, [r5] —— 未钉 */
/* @0xe8110 str r3, [r7] —— 未钉 */
/* @0xe8114 bl 0xb65b0 <memset@plt> —— 未钉 */
/* @0xe8118 ldr r1, [r6, #0x6c] —— 未钉 */
/* @0xe811c mov r2, #0 —— 未钉 */
/* @0xe8120 ldr r0, [sp, #0x40] —— 未钉 */
/* @0xe8124 mvn r12, #0 —— 未钉 */
/* @0xe8128 ldr r3, [pc, #0x444] —— 未钉 */
/* @0xe812c str r12, [r0, #0xc] —— 未钉 */
/* @0xe8130 str r1, [sp, #0x5c] —— 未钉 */
/* @0xe8134 mov r1, #0 —— 未钉 */
/* @0xe8138 str r2, [sp, #0x64] —— 未钉 */
/* @0xe813c ldr r6, [r4, r3] —— 未钉 */
/* @0xe8140 ldr r3, [r6] —— 未钉 */
/* @0xe8144 cmp r3, r2 —— 未钉 */
/* @0xe8148 ldr r2, [sp, #0x44] —— 未钉 */
/* @0xe814c strne r11, [r3] —— 未钉 */
/* @0xe8150 str r3, [sp, #0x1c] —— 未钉 */
/* @0xe8154 mov r0, r2 —— 未钉 */
/* @0xe8158 str r11, [r6] —— 未钉 */
/* @0xe815c str r1, [sp, #0x18] —— 未钉 */
/* @0xe8160 str r2, [sp] —— 未钉 */
/* @0xe8164 bl 0xec750 <_ZN8VMBuffer13convertBufferEv> —— 未钉 */
/* @0xe8168 ldr r3, [sp, #0x44] —— 未钉 */
/* @0xe816c ldr r2, [sp] —— 未钉 */
/* @0xe8170 ldr lr, [sp, #0xa0] —— 未钉 */
/* @0xe8174 ldr r3, [r3, #0x18] —— 未钉 */
/* @0xe8178 ldr r2, [r2, #0x14] —— 未钉 */
/* @0xe817c cmp lr, #0 —— 未钉 */
/* @0xe8180 str r3, [sp, #0x74] —— 未钉 */
/* @0xe8184 str r2, [sp, #0x70] —— 未钉 */
/* @0xe8188 beq 0xe83cc <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x3fc> —— 未钉 */
/* @0xe818c mov r3, #1 —— 未钉 */
/* @0xe8190 str lr, [sp, #0x28] —— 未钉 */
/* @0xe8194 str r3, [sp, #0x24] —— 未钉 */
/* @0xe8198 ldr r3, [pc, #0x3d8] —— 未钉 */
/* @0xe819c ldr r3, [r4, r3] —— 未钉 */
/* @0xe81a0 ldrb r3, [r3] —— 未钉 */
/* @0xe81a4 cmp r3, #0 —— 未钉 */
/* @0xe81a8 bne 0xe8230 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x260> —— 未钉 */
/* @0xe81ac ldr r3, [pc, #0x3c8] —— 未钉 */
/* @0xe81b0 mov r0, r11 —— 未钉 */
/* @0xe81b4 mov r1, r9 —— 未钉 */
/* @0xe81b8 ldr r3, [r4, r3] —— 未钉 */
/* @0xe81bc ldr r3, [r3] —— 未钉 */
/* @0xe81c0 cmp r3, #0 —— 未钉 */
/* @0xe81c4 beq 0xe8324 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x354> —— 未钉 */
/* @0xe81c8 mov r2, #0 —— 未钉 */
/* @0xe81cc bl 0xe47c8 <_ZN2VM9ExecDebugER6VMExecP6RValueb> —— 未钉 */
/* @0xe81d0 ldr r3, [sp, #0x1c] —— 未钉 */
/* @0xe81d4 cmp r3, #0 —— 未钉 */
/* @0xe81d8 movne r2, #0 —— 未钉 */
/* @0xe81dc strne r2, [r3] —— 未钉 */
/* @0xe81e0 ldr r2, [sp, #0x24] —— 未钉 */
/* @0xe81e4 str r3, [r6] —— 未钉 */
/* @0xe81e8 cmp r2, #0 —— 未钉 */
/* @0xe81ec str r10, [r7] —— 未钉 */
/* @0xe81f0 str r8, [r5] —— 未钉 */
/* @0xe81f4 bne 0xe8208 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x238> —— 未钉 */
/* @0xe81f8 ldr r0, [sp, #0x28] —— 未钉 */
/* @0xe81fc cmp r0, #0 —— 未钉 */
/* @0xe8200 beq 0xe8208 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x238> —— 未钉 */
/* @0xe8204 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_> —— 未钉 */
/* @0xe8208 add sp, sp, #124 —— 未钉 */
/* @0xe820c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 未钉 */
/* @0xe8210 ldr r1, [pc, #0x348] —— 未钉 */
/* @0xe8214 mov r2, #1 —— 未钉 */
/* @0xe8218 ldr r5, [r4, r1] —— 未钉 */
/* @0xe821c strb r2, [r12, #0x14] —— 未钉 */
/* @0xe8220 str r3, [r5, #0x4] —— 未钉 */
/* @0xe8224 str r3, [r5, #0x8] —— 未钉 */
/* @0xe8228 str r3, [r5, #0xc] —— 未钉 */
/* @0xe822c b 0xe800c <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x3c> —— 未钉 */
/* @0xe8230 ldr r0, [sp, #0x28] —— 未钉 */
/* @0xe8234 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> —— 未钉 */
/* @0xe8238 ldr r0, [sp, #0x28] —— 未钉 */
/* @0xe823c ldr r1, [r0, #0x4] —— 未钉 */
/* @0xe8240 cmp r1, #0 —— 未钉 */
/* @0xe8244 beq 0xe8454 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x484> —— 未钉 */
/* @0xe8248 ldr r2, [r1, #0xc] —— 未钉 */
/* @0xe824c bic r3, r2, #-16777216 —— 未钉 */
/* @0xe8250 cmp r3, #1 —— 未钉 */
/* @0xe8254 beq 0xe82d8 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x308> —— 未钉 */
/* @0xe8258 cmp r3, #2 —— 未钉 */
/* @0xe825c bne 0xe8274 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x2a4> —— 未钉 */
/* @0xe8260 sub r3, r2, #1 —— 未钉 */
/* @0xe8264 bic r3, r3, #-16777216 —— 未钉 */
/* @0xe8268 bic r3, r3, #3 —— 未钉 */
/* @0xe826c cmp r3, #0 —— 未钉 */
/* @0xe8270 beq 0xe8440 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x470> —— 未钉 */
/* @0xe8274 ldr lr, [sp, #0xb0] —— 未钉 */
/* @0xe8278 mov r2, #6 —— 未钉 */
/* @0xe827c mov r3, #5 —— 未钉 */
/* @0xe8280 str r2, [r1, #0xc] —— 未钉 */
/* @0xe8284 cmp lr, #0 —— 未钉 */
/* @0xe8288 str r3, [r1, #0x8] —— 未钉 */
/* @0xe828c str lr, [r1] —— 未钉 */
/* @0xe8290 beq 0xe82a0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x2d0> —— 未钉 */
/* @0xe8294 bl 0xd3a54 <_Z18GetContextStackTopv> —— 未钉 */
/* @0xe8298 ldr r1, [sp, #0xb0] —— 未钉 */
/* @0xe829c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> —— 未钉 */
/* @0xe82a0 bl 0xd3a34 <_Z15PopContextStackv> —— 未钉 */
/* @0xe82a4 b 0xe81ac <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x1dc> —— 未钉 */
/* @0xe82a8 ldr r0, [pc, #0x2d0] —— 未钉 */
/* @0xe82ac mov r2, r8 —— 未钉 */
/* @0xe82b0 ldr r1, [pc, #0x2cc] —— 未钉 */
/* @0xe82b4 ldr r0, [r4, r0] —— 未钉 */
/* @0xe82b8 add r1, pc, r1 —— 未钉 */
/* @0xe82bc ldr r0, [r0] —— 未钉 */
/* @0xe82c0 ldr r12, [r0] —— 未钉 */
/* @0xe82c4 ldr r12, [r12, #0xc] —— 未钉 */
/* @0xe82c8 str r3, [sp, #0x4] —— 未钉 */
/* @0xe82cc blx r12 —— 未钉 */
/* @0xe82d0 ldr r3, [sp, #0x4] —— 未钉 */
/* @0xe82d4 b 0xe8044 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x74> —— 未钉 */
/* @0xe82d8 ldr r3, [r1] —— 未钉 */
/* @0xe82dc cmp r3, #0 —— 未钉 */
/* @0xe82e0 beq 0xe8318 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x348> —— 未钉 */
/* @0xe82e4 str r1, [sp, #0x8] —— 未钉 */
/* @0xe82e8 str r3, [sp, #0x4] —— 未钉 */
/* @0xe82ec bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> —— 未钉 */
/* @0xe82f0 ldr r3, [sp, #0x4] —— 未钉 */
/* @0xe82f4 ldr r1, [sp, #0x8] —— 未钉 */
/* @0xe82f8 ldr r2, [r3, #0x4] —— 未钉 */
/* @0xe82fc sub r2, r2, #1 —— 未钉 */
/* @0xe8300 str r2, [r3, #0x4] —— 未钉 */
/* @0xe8304 cmp r2, #0 —— 未钉 */
/* @0xe8308 beq 0xe83e4 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x414> —— 未钉 */
/* @0xe830c str r1, [sp, #0x8] —— 未钉 */
/* @0xe8310 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> —— 未钉 */
/* @0xe8314 ldr r1, [sp, #0x8] —— 未钉 */
/* @0xe8318 mov r3, #0 —— 未钉 */
/* @0xe831c str r3, [r1] —— 未钉 */
/* @0xe8320 b 0xe8274 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x2a4> —— 未钉 */
/* @0xe8324 bl 0xe4540 <_ZN2VM11ExecReleaseER6VMExecP6RValue> —— 未钉 */
/* @0xe8328 b 0xe81d0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x200> —— 未钉 */
/* @0xe832c movw r0, #0x8008 —— 未钉 */
/* @0xe8330 movt r0, #0x10 —— 未钉 */
/* @0xe8334 str r3, [sp, #0x4] —— 未钉 */
/* @0xe8338 bl 0x27c524 <_Znwj> —— 未钉 */
/* @0xe833c mov r1, #120 —— 未钉 */
/* @0xe8340 mov r2, #1081344 —— 未钉 */
/* @0xe8344 mov r10, r0 —— 未钉 */
/* @0xe8348 add r0, r0, #8 —— 未钉 */
/* @0xe834c bl 0xb65b0 <memset@plt> —— 未钉 */
/* @0xe8350 ldr r1, [r5, #0x8] —— 未钉 */
/* @0xe8354 ldr r0, [r5, #0x4] —— 未钉 */
/* @0xe8358 add lr, r10, #32768 —— 未钉 */
/* @0xe835c add lr, lr, #8 —— 未钉 */
/* @0xe8360 ldr r11, [r5, #0x10] —— 未钉 */
/* @0xe8364 str r1, [sp, #0x14] —— 未钉 */
/* @0xe8368 bic lr, lr, #32512 —— 未钉 */
/* @0xe836c str r0, [r10] —— 未钉 */
/* @0xe8370 bic lr, lr, #255 —— 未钉 */
/* @0xe8374 str r10, [r5, #0x4] —— 未钉 */
/* @0xe8378 add r12, r11, #1 —— 未钉 */
/* @0xe837c ldr r10, [sp, #0x14] —— 未钉 */
/* @0xe8380 add r2, lr, #32768 —— 未钉 */
/* @0xe8384 add r1, lr, #1015808 —— 未钉 */
/* @0xe8388 mov r0, lr —— 未钉 */
/* @0xe838c ldr r3, [sp, #0x4] —— 未钉 */
/* @0xe8390 str r10, [lr] —— 未钉 */
/* @0xe8394 str lr, [r5, #0x8] —— 未钉 */
/* @0xe8398 str r12, [r5, #0x10] —— 未钉 */
/* @0xe839c b 0xe83a4 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x3d4> —— 未钉 */
/* @0xe83a0 mov r0, r12 —— 未钉 */
/* @0xe83a4 str r0, [r2] —— 未钉 */
/* @0xe83a8 mov r12, r2 —— 未钉 */
/* @0xe83ac add r2, r2, #32768 —— 未钉 */
/* @0xe83b0 cmp r2, r1 —— 未钉 */
/* @0xe83b4 bne 0xe83a0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x3d0> —— 未钉 */
/* @0xe83b8 ldr r2, [sp, #0x58] —— 未钉 */
/* @0xe83bc add r10, r11, #31 —— 未钉 */
/* @0xe83c0 add lr, lr, #983040 —— 未钉 */
/* @0xe83c4 sub r12, r2, #16 —— 未钉 */
/* @0xe83c8 b 0xe806c <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x9c> —— 未钉 */
/* @0xe83cc ldr r0, [sp, #0x10] —— 未钉 */
/* @0xe83d0 bl 0xd41e4 <_Z20YYAllocLocalStackNewi> —— 未钉 */
/* @0xe83d4 ldr r3, [sp, #0xa0] —— 未钉 */
/* @0xe83d8 str r3, [sp, #0x24] —— 未钉 */
/* @0xe83dc str r0, [sp, #0x28] —— 未钉 */
/* @0xe83e0 b 0xe8198 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x1c8> —— 未钉 */
/* @0xe83e4 ldr r0, [r3] —— 未钉 */
/* @0xe83e8 stm sp, {r2, r3} —— 未钉 */
/* @0xe83ec bl 0xcef90 <_Z6YYFreePKv> —— 未钉 */
/* @0xe83f0 ldm sp, {r2, r3} —— 未钉 */
/* @0xe83f4 str r2, [r3] —— 未钉 */
/* @0xe83f8 str r2, [r3, #0x8] —— 未钉 */
/* @0xe83fc str r3, [sp, #0x4] —— 未钉 */
/* @0xe8400 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> —— 未钉 */
/* @0xe8404 ldr r3, [sp, #0x4] —— 未钉 */
/* @0xe8408 ldr r1, [sp, #0x8] —— 未钉 */
/* @0xe840c ldr r2, [r3, #0x4] —— 未钉 */
/* @0xe8410 sub r2, r2, #1 —— 未钉 */
/* @0xe8414 str r2, [r3, #0x4] —— 未钉 */
/* @0xe8418 cmp r2, #0 —— 未钉 */
/* @0xe841c beq 0xe8460 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x490> —— 未钉 */
/* @0xe8420 str r1, [sp, #0x8] —— 未钉 */
/* @0xe8424 str r3, [sp, #0x4] —— 未钉 */
/* @0xe8428 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> —— 未钉 */
/* @0xe842c ldr r3, [sp, #0x4] —— 未钉 */
/* @0xe8430 mov r0, r3 —— 未钉 */
/* @0xe8434 bl 0x27d1d0 <_ZdlPv> —— 未钉 */
/* @0xe8438 ldr r1, [sp, #0x8] —— 未钉 */
/* @0xe843c b 0xe830c <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x33c> —— 未钉 */
/* @0xe8440 mov r0, r1 —— 未钉 */
/* @0xe8444 str r1, [sp, #0x8] —— 未钉 */
/* @0xe8448 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> —— 未钉 */
/* @0xe844c ldr r1, [sp, #0x8] —— 未钉 */
/* @0xe8450 b 0xe8274 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x2a4> —— 未钉 */
/* @0xe8454 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> —— 未钉 */
/* @0xe8458 mov r1, r0 —— 未钉 */
/* @0xe845c b 0xe8248 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x278> —— 未钉 */
/* @0xe8460 ldr r0, [r3] —— 未钉 */
/* @0xe8464 stm sp, {r2, r3} —— 未钉 */
/* @0xe8468 bl 0xcef90 <_Z6YYFreePKv> —— 未钉 */
/* @0xe846c ldm sp, {r2, r3} —— 未钉 */
/* @0xe8470 str r2, [r3] —— 未钉 */
/* @0xe8474 str r2, [r3, #0x8] —— 未钉 */
/* @0xe8478 str r3, [sp, #0x4] —— 未钉 */
/* @0xe847c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> —— 未钉 */
/* @0xe8480 ldr r3, [sp, #0x4] —— 未钉 */
/* @0xe8484 ldr r1, [sp, #0x8] —— 未钉 */
/* @0xe8488 ldr r2, [r3, #0x4] —— 未钉 */
/* @0xe848c sub r2, r2, #1 —— 未钉 */
/* @0xe8490 str r2, [r3, #0x4] —— 未钉 */
/* @0xe8494 cmp r2, #0 —— 未钉 */
/* @0xe8498 beq 0xe84c0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x4f0> —— 未钉 */
/* @0xe849c str r1, [sp, #0x8] —— 未钉 */
/* @0xe84a0 str r3, [sp, #0x4] —— 未钉 */
/* @0xe84a4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> —— 未钉 */
/* @0xe84a8 ldr r3, [sp, #0x4] —— 未钉 */
/* @0xe84ac mov r0, r3 —— 未钉 */
/* @0xe84b0 bl 0x27d1d0 <_ZdlPv> —— 未钉 */
/* @0xe84b4 ldr r3, [sp, #0x4] —— 未钉 */
/* @0xe84b8 ldr r1, [sp, #0x8] —— 未钉 */
/* @0xe84bc b 0xe8420 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x450> —— 未钉 */
/* @0xe84c0 ldr r0, [r3] —— 未钉 */
/* @0xe84c4 stm sp, {r2, r3} —— 未钉 */
/* @0xe84c8 bl 0xcef90 <_Z6YYFreePKv> —— 未钉 */
/* @0xe84cc ldm sp, {r2, r3} —— 未钉 */
/* @0xe84d0 str r2, [r3] —— 未钉 */
/* @0xe84d4 str r2, [r3, #0x8] —— 未钉 */
/* @0xe84d8 str r3, [sp, #0x4] —— 未钉 */
/* @0xe84dc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> —— 未钉 */
/* @0xe84e0 ldr r3, [sp, #0x4] —— 未钉 */
/* @0xe84e4 ldr r1, [sp, #0x8] —— 未钉 */
/* @0xe84e8 ldr r2, [r3, #0x4] —— 未钉 */
/* @0xe84ec sub r2, r2, #1 —— 未钉 */
/* @0xe84f0 str r2, [r3, #0x4] —— 未钉 */
/* @0xe84f4 cmp r2, #0 —— 未钉 */
/* @0xe84f8 bne 0xe8534 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x564> —— 未钉 */
/* @0xe84fc ldr r0, [r3] —— 未钉 */
/* @0xe8500 stm sp, {r2, r3} —— 未钉 */
/* @0xe8504 bl 0xcef90 <_Z6YYFreePKv> —— 未钉 */
/* @0xe8508 ldm sp, {r2, r3} —— 未钉 */
/* @0xe850c str r2, [r3] —— 未钉 */
/* @0xe8510 mov r0, r3 —— 未钉 */
/* @0xe8514 str r2, [r3, #0x8] —— 未钉 */
/* @0xe8518 str r3, [sp, #0x4] —— 未钉 */
/* @0xe851c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> —— 未钉 */
/* @0xe8520 ldr r3, [sp, #0x4] —— 未钉 */
/* @0xe8524 mov r0, r3 —— 未钉 */
/* @0xe8528 bl 0x27d1d0 <_ZdlPv> —— 未钉 */
/* @0xe852c ldr r3, [sp, #0x4] —— 未钉 */
/* @0xe8530 ldr r1, [sp, #0x8] —— 未钉 */
/* @0xe8534 str r1, [sp, #0x8] —— 未钉 */
/* @0xe8538 str r3, [sp, #0x4] —— 未钉 */
/* @0xe853c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> —— 未钉 */
/* @0xe8540 ldr r3, [sp, #0x4] —— 未钉 */
/* @0xe8544 mov r0, r3 —— 未钉 */
/* @0xe8548 bl 0x27d1d0 <_ZdlPv> —— 未钉 */
/* @0xe854c ldr r3, [sp, #0x4] —— 未钉 */
/* @0xe8550 ldr r1, [sp, #0x8] —— 未钉 */
/* @0xe8554 b 0xe849c <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x4cc> —— 未钉 */
/* @0xe8558 ldrsbteq r2, [r9], -r12 —— 未钉 */
/* @0xe855c eorseq r9, r0, r4, ror #24 —— 未钉 */
/* @0xe8560 .word 0xffffc0e4 —— 未钉 */
/* @0xe8564 .word 0xffffc100 —— 未钉 */
/* @0xe8568 .word 0xffffc104 —— 未钉 */
/* @0xe856c .word 0xffffc0bc —— 未钉 */
/* @0xe8570 .word 0xffffc0c0 —— 未钉 */
/* @0xe8574 .word 0xffffbf58 —— 未钉 */
/* @0xe8578 .word 0xffffbf68 —— 未钉 */
/* @0xe857c .word 0xffffc0a4 —— 未钉 */
/* @0xe8580 .word 0xffffbac4 —— 未钉 */
/* @0xe8584 eoreq r12, r4, r0, asr r5 —— 未钉 */
