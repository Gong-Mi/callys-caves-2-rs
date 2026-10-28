/* cally 逆向卡：DoPushGlobal（原版 libyoyo.so，armv7）
 * @func 0xd4bd8 0xd4d74  size 412  103 条指令
 * 级别: 骨架（头部与分派已证，15 个 case 分支未逐个展开）
 * 符号: _Z12DoPushGlobaljPhPKhP6VMExec → uchar* DoPushGlobal(uint32 imm, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   idx  = (*(uint32_t*)base) & 0x0FFFFFFF     ; d4be4 / d4bf4
 *   slot = idx - 100000                         ; d4bfc / d4c10
 *   g    = *(void**)<GOT 指向的全局单例>        ; d4bd8/d4be0/d4bec 三跳
 *   n    = *(uint32*)(g+4)                      ; d4c04 —— 全局变量个数
 *   *(uint32*)(sp-4) = 0x00FFFFFF               ; d4bfc9 mvn 后 d4c0c —— 与 DoPushLocal 同一 tag
 *   res  = sp-16，清零 sp-8/-12/-16             ; d4c08..d4c20
 *   if (n == 0) r5 = self->InternalGetYYVar(slot)  ; d4d60 bl YYObjectBase::InternalGetYYVar
 *   else        r5 = n + slot*16                ; d4c28 —— 与局部变量同构，只是基址换成全局单例
 *   src  = *(uint32*)(r5+0xc); tag = src & 0xFF000000 >> 24   ; d4c2c/d4c30/d4c40
 *   **switch (tag) 0..14：`cmp #14; addls pc,pc,r12,lsl #2` + 15 条 b 组成的跳转表**  ; d4c44-d4c80
 *     0→d4c94 1→d4ca8 2→d4d18 3→d4d34 4→d4c8c 5/6→d4c94 …（按 b 的目标表）
 *
 * 结论（新增三条硬事实）：
 *   1. RValue 的**类型 tag 在 +12（高字节）**，取值 **0..14**，按 tag 走 15 路跳转表；
 *      这解释了 DoPushLocal/DoPushBuiltin 为什么都写 +0xc 处的 tag。
 *   2. 全局变量表与局部变量表**同构**：16 字节槽、索引基址 100000，仅基址不同
 *      （全局 = GOT 单例 +4；局部 = self +4）。
 *   3. tag 0x00FFFFFF 是"尚未解析的变量引用"占位，解析后才换成真实类型 tag。
 * open：15 个 case 各自对哪些 tag 做引用计数/深拷贝；InternalGetYYVar 的返回约定。
 */
/* @0xd4bd8 ldr r12, [pc, #0x18c] */
/* @0xd4bdc push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xd4be0 ldr r12, [pc, r12] */
/* @0xd4be4 ldr r7, [r2] */
/* @0xd4be8 mov r4, r1 */
/* @0xd4bec ldr r0, [r12] */
/* @0xd4bf0 mov r12, #0 */
/* @0xd4bf4 bic r7, r7, #-268435456 */
/* @0xd4bf8 mov r9, r3 */
/* @0xd4bfc sub r5, r7, #99328 */
/* @0xd4c00 mvn r3, #-16777216 */
/* @0xd4c04 ldr r6, [r0, #0x4] */
/* @0xd4c08 sub r8, r4, #16 */
/* @0xd4c0c str r3, [r1, #-0x4] */
/* @0xd4c10 sub r1, r5, #672 */
/* @0xd4c14 cmp r6, r12 */
/* @0xd4c18 str r12, [r4, #-0x8] */
/* @0xd4c1c str r12, [r4, #-0xc] */
/* @0xd4c20 str r12, [r4, #-0x10] */
/* @0xd4c24 beq 0xd4d60 <_Z12DoPushGlobaljPhPKhP6VMExec+0x188> */
/* @0xd4c28 add r5, r6, r1, lsl #4 */
/* @0xd4c2c ldr r1, [r5, #0xc] */
/* @0xd4c30 ldr r3, [r5, #0x8] */
/* @0xd4c34 str r1, [r4, #-0x4] */
/* @0xd4c38 ldr r12, [r5, #0xc] */
/* @0xd4c3c str r3, [r4, #-0x8] */
/* @0xd4c40 bic r12, r12, #-16777216 */
/* @0xd4c44 cmp r12, #14 */
/* @0xd4c48 addls pc, pc, r12, lsl #2 */
/* @0xd4c4c b 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4c50 b 0xd4ca8 <_Z12DoPushGlobaljPhPKhP6VMExec+0xd0> */
/* @0xd4c54 b 0xd4d18 <_Z12DoPushGlobaljPhPKhP6VMExec+0x140> */
/* @0xd4c58 b 0xd4d34 <_Z12DoPushGlobaljPhPKhP6VMExec+0x15c> */
/* @0xd4c5c b 0xd4c8c <_Z12DoPushGlobaljPhPKhP6VMExec+0xb4> */
/* @0xd4c60 b 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4c64 b 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4c68 b 0xd4cf0 <_Z12DoPushGlobaljPhPKhP6VMExec+0x118> */
/* @0xd4c6c b 0xd4c8c <_Z12DoPushGlobaljPhPKhP6VMExec+0xb4> */
/* @0xd4c70 b 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4c74 b 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4c78 b 0xd4ca8 <_Z12DoPushGlobaljPhPKhP6VMExec+0xd0> */
/* @0xd4c7c b 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4c80 b 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4c84 b 0xd4ca8 <_Z12DoPushGlobaljPhPKhP6VMExec+0xd0> */
/* @0xd4c88 b 0xd4c8c <_Z12DoPushGlobaljPhPKhP6VMExec+0xb4> */
/* @0xd4c8c ldr r3, [r5] */
/* @0xd4c90 str r3, [r4, #-0x10] */
/* @0xd4c94 mvn r3, #-16777216 */
/* @0xd4c98 cmp r1, r3 */
/* @0xd4c9c beq 0xd4cc0 <_Z12DoPushGlobaljPhPKhP6VMExec+0xe8> */
/* @0xd4ca0 mov r0, r8 */
/* @0xd4ca4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xd4ca8 ldm r5, {r2, r3} */
/* @0xd4cac str r3, [r4, #-0xc] */
/* @0xd4cb0 mvn r3, #-16777216 */
/* @0xd4cb4 cmp r1, r3 */
/* @0xd4cb8 str r2, [r4, #-0x10] */
/* @0xd4cbc bne 0xd4ca0 <_Z12DoPushGlobaljPhPKhP6VMExec+0xc8> */
/* @0xd4cc0 mov r2, r7 */
/* @0xd4cc4 ldr r0, [r9, #0x34] */
/* @0xd4cc8 mvn r1, #4 */
/* @0xd4ccc bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xd4cd0 ldr r1, [pc, #0x98] */
/* @0xd4cd4 mov r3, r7 */
/* @0xd4cd8 add r1, pc, r1 */
/* @0xd4cdc mov r2, r0 */
/* @0xd4ce0 mov r0, r9 */
/* @0xd4ce4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd4ce8 mov r0, r8 */
/* @0xd4cec pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xd4cf0 ldr r3, [r5] */
/* @0xd4cf4 str r3, [r4, #-0x10] */
/* @0xd4cf8 ldr r3, [r5] */
/* @0xd4cfc cmp r3, #0 */
/* @0xd4d00 beq 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4d04 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xd4d08 ldr r1, [r5] */
/* @0xd4d0c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xd4d10 ldr r1, [r4, #-0x4] */
/* @0xd4d14 b 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4d18 ldr r3, [r5] */
/* @0xd4d1c cmp r3, #0 */
/* @0xd4d20 ldrne r2, [r3, #0x4] */
/* @0xd4d24 addne r2, r2, #1 */
/* @0xd4d28 strne r2, [r3, #0x4] */
/* @0xd4d2c ldrne r1, [r4, #-0x4] */
/* @0xd4d30 b 0xd4c90 <_Z12DoPushGlobaljPhPKhP6VMExec+0xb8> */
/* @0xd4d34 ldr r3, [r5] */
/* @0xd4d38 cmp r3, #0 */
/* @0xd4d3c str r3, [r4, #-0x10] */
/* @0xd4d40 beq 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4d44 ldr r0, [r3, #0x8] */
/* @0xd4d48 ldr r2, [r3] */
/* @0xd4d4c cmp r0, #0 */
/* @0xd4d50 streq r8, [r3, #0x8] */
/* @0xd4d54 add r2, r2, #1 */
/* @0xd4d58 str r2, [r3] */
/* @0xd4d5c b 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4d60 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xd4d64 mov r5, r0 */
/* @0xd4d68 b 0xd4c2c <_Z12DoPushGlobaljPhPKhP6VMExec+0x54> */
/* @0xd4d6c ldrsbteq r8, [r1], -r4 */
/* @0xd4d70 .word 0x0025dcfc */
