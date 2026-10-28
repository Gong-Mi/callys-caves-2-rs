/* cally 逆向卡：DoPushLocal（原版 libyoyo.so，armv7）
 * @func 0xd4a34 0xd4bd8  size 420  105 条指令
 * 级别: 骨架（头部 12 条已证，其余逐条未钉）
 * 符号: _Z11DoPushLocaljPhPKhP6VMExec → uchar* DoPushLocal(uint32 imm, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   self = exec->[0x10]                       ; d4a34 ldr r0,[r3,#0x10]
 *   idx  = (*(uint32_t*)base) & 0x0FFFFFFF    ; d4a44 / d4a54 bic #-268435456
 *   tag  = ~0xFF000000 == 0x00FFFFFF           ; d4a50 mvn r3,#-16777216
 *   *(uint32*)(sp-4)  = tag                    ; d4a58 —— 值栈顶先写"局部变量"类型标记
 *   n    = *(uint32*)(self+4)                  ; d4a4c —— 局部变量个数
 *   slot = idx - 99328 - 672 == idx - 100000    ; d4a60/d4a68 —— 变量 id 以 100000 为基址
 *   res  = sp - 16；清零 sp-8/sp-12/sp-16       ; d4a6c..d4a78 —— RValue 16 字节，tag 在 +0..+3
 *   if (n == 0) → 0xd4bc8（空局部表路径）       ; d4a5c/d4a7c
 *   否则 next = n + slot*16                     ; d4a80 add r5,r6,r1,lsl #4 —— 槽位步长 16 字节
 *
 * 结论：「变量 id 空间 100000 起」这条与 DoCallGML 的脚本 id 基址一致，说明 100000 是
 *       统一的 id 分区（脚本/变量共用同一编号空间）。
 * open：空表路径的构造、拷贝语义（深/浅拷贝）、越界检查。
 */
/* @0xd4a34 ldr r0, [r3, #0x10] */
/* @0xd4a38 mov r12, #0 */
/* @0xd4a3c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xd4a40 mov r4, r1 */
/* @0xd4a44 ldr r7, [r2] */
/* @0xd4a48 mov r8, r3 */
/* @0xd4a4c ldr r6, [r0, #0x4] */
/* @0xd4a50 mvn r3, #-16777216 */
/* @0xd4a54 bic r7, r7, #-268435456 */
/* @0xd4a58 str r3, [r1, #-0x4] */
/* @0xd4a5c cmp r6, r12 */
/* @0xd4a60 sub r5, r7, #99328 */
/* @0xd4a64 sub sp, sp, #12 */
/* @0xd4a68 sub r1, r5, #672 */
/* @0xd4a6c sub r9, r4, #16 */
/* @0xd4a70 str r12, [r4, #-0x8] */
/* @0xd4a74 str r12, [r4, #-0xc] */
/* @0xd4a78 str r12, [r4, #-0x10] */
/* @0xd4a7c beq 0xd4bc8 <_Z11DoPushLocaljPhPKhP6VMExec+0x194> */
/* @0xd4a80 add r5, r6, r1, lsl #4 */
/* @0xd4a84 ldr r1, [r5, #0xc] */
/* @0xd4a88 ldr r3, [r5, #0x8] */
/* @0xd4a8c str r1, [r4, #-0x4] */
/* @0xd4a90 ldr r12, [r5, #0xc] */
/* @0xd4a94 str r3, [r4, #-0x8] */
/* @0xd4a98 bic r12, r12, #-16777216 */
/* @0xd4a9c cmp r12, #14 */
/* @0xd4aa0 addls pc, pc, r12, lsl #2 */
/* @0xd4aa4 b 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4aa8 b 0xd4b04 <_Z11DoPushLocaljPhPKhP6VMExec+0xd0> */
/* @0xd4aac b 0xd4b80 <_Z11DoPushLocaljPhPKhP6VMExec+0x14c> */
/* @0xd4ab0 b 0xd4b9c <_Z11DoPushLocaljPhPKhP6VMExec+0x168> */
/* @0xd4ab4 b 0xd4ae4 <_Z11DoPushLocaljPhPKhP6VMExec+0xb0> */
/* @0xd4ab8 b 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4abc b 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4ac0 b 0xd4b58 <_Z11DoPushLocaljPhPKhP6VMExec+0x124> */
/* @0xd4ac4 b 0xd4ae4 <_Z11DoPushLocaljPhPKhP6VMExec+0xb0> */
/* @0xd4ac8 b 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4acc b 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4ad0 b 0xd4b04 <_Z11DoPushLocaljPhPKhP6VMExec+0xd0> */
/* @0xd4ad4 b 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4ad8 b 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4adc b 0xd4b04 <_Z11DoPushLocaljPhPKhP6VMExec+0xd0> */
/* @0xd4ae0 b 0xd4ae4 <_Z11DoPushLocaljPhPKhP6VMExec+0xb0> */
/* @0xd4ae4 ldr r3, [r5] */
/* @0xd4ae8 str r3, [r4, #-0x10] */
/* @0xd4aec mvn r3, #-16777216 */
/* @0xd4af0 cmp r1, r3 */
/* @0xd4af4 beq 0xd4b1c <_Z11DoPushLocaljPhPKhP6VMExec+0xe8> */
/* @0xd4af8 mov r0, r9 */
/* @0xd4afc add sp, sp, #12 */
/* @0xd4b00 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xd4b04 ldm r5, {r2, r3} */
/* @0xd4b08 str r3, [r4, #-0xc] */
/* @0xd4b0c mvn r3, #-16777216 */
/* @0xd4b10 cmp r1, r3 */
/* @0xd4b14 str r2, [r4, #-0x10] */
/* @0xd4b18 bne 0xd4af8 <_Z11DoPushLocaljPhPKhP6VMExec+0xc4> */
/* @0xd4b1c mov r2, r7 */
/* @0xd4b20 ldr r0, [r8, #0x34] */
/* @0xd4b24 mvn r1, #6 */
/* @0xd4b28 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xd4b2c ldr r1, [pc, #0xa0] */
/* @0xd4b30 mov r12, #-2147483648 */
/* @0xd4b34 mov r3, r7 */
/* @0xd4b38 add r1, pc, r1 */
/* @0xd4b3c str r12, [sp] */
/* @0xd4b40 mov r2, r0 */
/* @0xd4b44 mov r0, r8 */
/* @0xd4b48 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd4b4c mov r0, r9 */
/* @0xd4b50 add sp, sp, #12 */
/* @0xd4b54 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xd4b58 ldr r3, [r5] */
/* @0xd4b5c str r3, [r4, #-0x10] */
/* @0xd4b60 ldr r3, [r5] */
/* @0xd4b64 cmp r3, #0 */
/* @0xd4b68 beq 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4b6c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xd4b70 ldr r1, [r5] */
/* @0xd4b74 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xd4b78 ldr r1, [r4, #-0x4] */
/* @0xd4b7c b 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4b80 ldr r3, [r5] */
/* @0xd4b84 cmp r3, #0 */
/* @0xd4b88 ldrne r2, [r3, #0x4] */
/* @0xd4b8c addne r2, r2, #1 */
/* @0xd4b90 strne r2, [r3, #0x4] */
/* @0xd4b94 ldrne r1, [r4, #-0x4] */
/* @0xd4b98 b 0xd4ae8 <_Z11DoPushLocaljPhPKhP6VMExec+0xb4> */
/* @0xd4b9c ldr r3, [r5] */
/* @0xd4ba0 cmp r3, #0 */
/* @0xd4ba4 str r3, [r4, #-0x10] */
/* @0xd4ba8 beq 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4bac ldr r0, [r3, #0x8] */
/* @0xd4bb0 ldr r2, [r3] */
/* @0xd4bb4 cmp r0, #0 */
/* @0xd4bb8 streq r9, [r3, #0x8] */
/* @0xd4bbc add r2, r2, #1 */
/* @0xd4bc0 str r2, [r3] */
/* @0xd4bc4 b 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4bc8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xd4bcc mov r5, r0 */
/* @0xd4bd0 b 0xd4a84 <_Z11DoPushLocaljPhPKhP6VMExec+0x50> */
/* @0xd4bd4 eoreq sp, r5, r4, ror #28 */
