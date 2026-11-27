/* cally 逆向卡：ExecuteIt（原版 libyoyo.so，armv7）
 *
 * @func 0xcf914 0xcfc60  size 844  211 条指令（含 3 个 literal 词）
 * 级别:  骨架（锚点全挂；仅顶部已证，其余逐条标未钉）
 * 符号:  _Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei
 *        → int ExecuteIt(CInstance* self, CInstance* other, CCode* code, RValue* result, int arg)
 * 锚表:  reconstruction/reverse-v1/asm/index-ExecuteIt.tsv
 *
 * 已证（asm 直读）：
 *   0. 参数落位：code→r4、result→r5、self→r8、other→r9；r6/r7 清零；入口先清一个全局字节。
 *   1. **分派变量是 code->type（[r4+8]）**，不是 RValue，取值语义：
 *        type < 1        → 0xcfa24：`mov r0,#1` 直接返回 1（什么都不做）
 *        1 <= type <= 2  → 0xcfa30：读 code->[0x64]，非空则 `ldr r3,[r3,#4]; blx r3`（虚调用回调），
 *                          之后 `mov r0,#1` 返回 1；空则落 0xcfa50 继续
 *        type == 3       → 就地继续（唯一的真正执行路径，末尾调 VM::Exec）
 *        type > 3        → 0xcfa24：返回 1
 *   2. 即 ExecuteIt 是「按 CCode 种类分派」的外壳：1/2 走回调，3 走字节码解释，其余视为成功空转。
 *   3. 调用点统计不变：LOCK/UNLOCK_RVALUE_MUTEX ×4、YYFree ×4、operator delete ×4、
 *      CProfiler::Push/Pop、VM::Exec、DeterminePotentialRoot、GetContextStackTop、
 *      FREE_RValue__Pre、_RefThing<const char>::dec 各 ×1。
 *
 * 仍未钉：type==1 与 type==2 是否真的走同一处理（asm 上确实同路，需查调用者确认语义差别）；
 *         0xcfa50..0xcfaec 段落的用途；VM::Exec 的 9 个实参如何被填；literal 三条归属。
 */

/* @0xcf914 push {r4, r5, r6, r7, r8, r9, lr} —— 未钉 */
/* @0xcf918 mov r4, r2 —— 未钉 */
/* @0xcf91c ldr r6, [pc, #0x32c] —— 未钉 */
/* @0xcf920 mov r5, r3 —— 未钉 */
/* @0xcf924 ldr r2, [pc, #0x328] —— 未钉 */
/* @0xcf928 mov r7, #0 —— 未钉 */
/* @0xcf92c add r6, pc, r6 —— 未钉 */
/* @0xcf930 ldr r12, [r4, #0x8] —— 未钉 */
/* @0xcf934 sub sp, sp, #28 —— 未钉 */
/* @0xcf938 mov r8, r0 —— 未钉 */
/* @0xcf93c ldr r3, [r6, r2] —— 未钉 */
/* @0xcf940 cmp r12, #1 —— 未钉 */
/* @0xcf944 mov r9, r1 —— 未钉 */
/* @0xcf948 strb r7, [r3] —— 未钉 */
/* @0xcf94c blt 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> —— 未钉 */
/* @0xcf950 cmp r12, #2 —— 未钉 */
/* @0xcf954 ble 0xcfa30 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x11c> —— 未钉 */
/* @0xcf958 cmp r12, #3 —— 未钉 */
/* @0xcf95c bne 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> —— 未钉 */
/* @0xcf960 ldr r2, [r5, #0xc] —— 未钉 */
/* @0xcf964 bic r3, r2, #-16777216 —— 未钉 */
/* @0xcf968 cmp r3, #1 —— 未钉 */
/* @0xcf96c beq 0xcfaec <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1d8> —— 未钉 */
/* @0xcf970 cmp r3, #2 —— 未钉 */
/* @0xcf974 bne 0xcf99c <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x88> —— 未钉 */
/* @0xcf978 sub r2, r2, #1 —— 未钉 */
/* @0xcf97c bic r2, r2, #-16777216 —— 未钉 */
/* @0xcf980 bic r2, r2, #3 —— 未钉 */
/* @0xcf984 cmp r2, #0 —— 未钉 */
/* @0xcf988 beq 0xcfb9c <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x288> —— 未钉 */
/* @0xcf98c mov r2, #0 —— 未钉 */
/* @0xcf990 mov r3, #5 —— 未钉 */
/* @0xcf994 str r2, [r5, #0x8] —— 未钉 */
/* @0xcf998 str r3, [r5, #0xc] —— 未钉 */
/* @0xcf99c ldr r3, [r4, #0x4c] —— 未钉 */
/* @0xcf9a0 mov r1, #0 —— 未钉 */
/* @0xcf9a4 ldr r2, [r4, #0x48] —— 未钉 */
/* @0xcf9a8 str r1, [r5] —— 未钉 */
/* @0xcf9ac str r3, [r5, #0xc] —— 未钉 */
/* @0xcf9b0 ldr r3, [r4, #0x4c] —— 未钉 */
/* @0xcf9b4 str r2, [r5, #0x8] —— 未钉 */
/* @0xcf9b8 bic r3, r3, #-16777216 —— 未钉 */
/* @0xcf9bc cmp r3, #14 —— 未钉 */
/* @0xcf9c0 addls pc, pc, r3, lsl #2 —— 未钉 */
/* @0xcf9c4 b 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> —— 未钉 */
/* @0xcf9c8 b 0xcfadc <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1c8> —— 未钉 */
/* @0xcf9cc b 0xcfb20 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x20c> —— 未钉 */
/* @0xcf9d0 b 0xcfb38 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x224> —— 未钉 */
/* @0xcf9d4 b 0xcfac8 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1b4> —— 未钉 */
/* @0xcf9d8 b 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> —— 未钉 */
/* @0xcf9dc b 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> —— 未钉 */
/* @0xcf9e0 b 0xcfa04 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0xf0> —— 未钉 */
/* @0xcf9e4 b 0xcfac8 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1b4> —— 未钉 */
/* @0xcf9e8 b 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> —— 未钉 */
/* @0xcf9ec b 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> —— 未钉 */
/* @0xcf9f0 b 0xcfadc <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1c8> —— 未钉 */
/* @0xcf9f4 b 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> —— 未钉 */
/* @0xcf9f8 b 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> —— 未钉 */
/* @0xcf9fc b 0xcfadc <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1c8> —— 未钉 */
/* @0xcfa00 b 0xcfac8 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1b4> —— 未钉 */
/* @0xcfa04 ldr r3, [r4, #0x40] —— 未钉 */
/* @0xcfa08 str r3, [r5] —— 未钉 */
/* @0xcfa0c ldr r3, [r4, #0x40] —— 未钉 */
/* @0xcfa10 cmp r3, #0 —— 未钉 */
/* @0xcfa14 beq 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> —— 未钉 */
/* @0xcfa18 bl 0xd3a54 <_Z18GetContextStackTopv> —— 未钉 */
/* @0xcfa1c ldr r1, [r4, #0x40] —— 未钉 */
/* @0xcfa20 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> —— 未钉 */
/* @0xcfa24 mov r0, #1 —— 未钉 */
/* @0xcfa28 add sp, sp, #28 —— 未钉 */
/* @0xcfa2c pop {r4, r5, r6, r7, r8, r9, pc} —— 未钉 */
/* @0xcfa30 ldr r3, [r4, #0x64] —— 未钉 */
/* @0xcfa34 cmp r3, #0 —— 未钉 */
/* @0xcfa38 beq 0xcfa50 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x13c> —— 未钉 */
/* @0xcfa3c ldr r3, [r3, #0x4] —— 未钉 */
/* @0xcfa40 blx r3 —— 未钉 */
/* @0xcfa44 mov r0, #1 —— 未钉 */
/* @0xcfa48 add sp, sp, #28 —— 未钉 */
/* @0xcfa4c pop {r4, r5, r6, r7, r8, r9, pc} —— 未钉 */
/* @0xcfa50 ldr r3, [r4, #0x50] —— 未钉 */
/* @0xcfa54 cmp r3, #0 —— 未钉 */
/* @0xcfa58 beq 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> —— 未钉 */
/* @0xcfa5c ldr r3, [r3, #0x4] —— 未钉 */
/* @0xcfa60 cmp r3, #0 —— 未钉 */
/* @0xcfa64 ble 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> —— 未钉 */
/* @0xcfa68 ldr r3, [pc, #0x1e8] —— 未钉 */
/* @0xcfa6c ldr r7, [r6, r3] —— 未钉 */
/* @0xcfa70 ldrb r3, [r7] —— 未钉 */
/* @0xcfa74 cmp r3, #0 —— 未钉 */
/* @0xcfa78 bne 0xcfba8 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x294> —— 未钉 */
/* @0xcfa7c ldr r3, [sp, #0x38] —— 未钉 */
/* @0xcfa80 mov r12, #0 —— 未钉 */
/* @0xcfa84 mov r0, r4 —— 未钉 */
/* @0xcfa88 mov r1, r8 —— 未钉 */
/* @0xcfa8c mov r2, r9 —— 未钉 */
/* @0xcfa90 str r12, [sp] —— 未钉 */
/* @0xcfa94 str r3, [sp, #0xc] —— 未钉 */
/* @0xcfa98 mov r3, r5 —— 未钉 */
/* @0xcfa9c str r12, [sp, #0x4] —— 未钉 */
/* @0xcfaa0 str r12, [sp, #0x8] —— 未钉 */
/* @0xcfaa4 str r12, [sp, #0x10] —— 未钉 */
/* @0xcfaa8 bl 0xe7fd0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_> —— 未钉 */
/* @0xcfaac ldrb r3, [r7] —— 未钉 */
/* @0xcfab0 cmp r3, #0 —— 未钉 */
/* @0xcfab4 beq 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> —— 未钉 */
/* @0xcfab8 ldr r3, [pc, #0x19c] —— 未钉 */
/* @0xcfabc ldr r0, [r6, r3] —— 未钉 */
/* @0xcfac0 bl 0x2a08ac <_ZN9CProfiler3PopEv> —— 未钉 */
/* @0xcfac4 b 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> —— 未钉 */
/* @0xcfac8 ldr r3, [r4, #0x40] —— 未钉 */
/* @0xcfacc mov r0, #1 —— 未钉 */
/* @0xcfad0 str r3, [r5] —— 未钉 */
/* @0xcfad4 add sp, sp, #28 —— 未钉 */
/* @0xcfad8 pop {r4, r5, r6, r7, r8, r9, pc} —— 未钉 */
/* @0xcfadc ldr r2, [r4, #0x40] —— 未钉 */
/* @0xcfae0 ldr r3, [r4, #0x44] —— 未钉 */
/* @0xcfae4 stm r5, {r2, r3} —— 未钉 */
/* @0xcfae8 b 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> —— 未钉 */
/* @0xcfaec ldr r6, [r5] —— 未钉 */
/* @0xcfaf0 cmp r6, #0 —— 未钉 */
/* @0xcfaf4 beq 0xcfb14 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x200> —— 未钉 */
/* @0xcfaf8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> —— 未钉 */
/* @0xcfafc ldr r7, [r6, #0x4] —— 未钉 */
/* @0xcfb00 sub r7, r7, #1 —— 未钉 */
/* @0xcfb04 str r7, [r6, #0x4] —— 未钉 */
/* @0xcfb08 cmp r7, #0 —— 未钉 */
/* @0xcfb0c beq 0xcfb64 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x250> —— 未钉 */
/* @0xcfb10 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> —— 未钉 */
/* @0xcfb14 mov r3, #0 —— 未钉 */
/* @0xcfb18 str r3, [r5] —— 未钉 */
/* @0xcfb1c b 0xcf99c <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x88> —— 未钉 */
/* @0xcfb20 ldr r3, [r4, #0x40] —— 未钉 */
/* @0xcfb24 cmp r3, #0 —— 未钉 */
/* @0xcfb28 ldrne r2, [r3, #0x4] —— 未钉 */
/* @0xcfb2c addne r2, r2, #1 —— 未钉 */
/* @0xcfb30 strne r2, [r3, #0x4] —— 未钉 */
/* @0xcfb34 b 0xcfacc <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1b8> —— 未钉 */
/* @0xcfb38 ldr r3, [r4, #0x40] —— 未钉 */
/* @0xcfb3c cmp r3, #0 —— 未钉 */
/* @0xcfb40 str r3, [r5] —— 未钉 */
/* @0xcfb44 beq 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> —— 未钉 */
/* @0xcfb48 ldr r1, [r3, #0x8] —— 未钉 */
/* @0xcfb4c ldr r2, [r3] —— 未钉 */
/* @0xcfb50 cmp r1, #0 —— 未钉 */
/* @0xcfb54 streq r5, [r3, #0x8] —— 未钉 */
/* @0xcfb58 add r2, r2, #1 —— 未钉 */
/* @0xcfb5c str r2, [r3] —— 未钉 */
/* @0xcfb60 b 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> —— 未钉 */
/* @0xcfb64 ldr r0, [r6] —— 未钉 */
/* @0xcfb68 bl 0xcef90 <_Z6YYFreePKv> —— 未钉 */
/* @0xcfb6c str r7, [r6] —— 未钉 */
/* @0xcfb70 str r7, [r6, #0x8] —— 未钉 */
/* @0xcfb74 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> —— 未钉 */
/* @0xcfb78 ldr r7, [r6, #0x4] —— 未钉 */
/* @0xcfb7c sub r7, r7, #1 —— 未钉 */
/* @0xcfb80 str r7, [r6, #0x4] —— 未钉 */
/* @0xcfb84 cmp r7, #0 —— 未钉 */
/* @0xcfb88 beq 0xcfbc0 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x2ac> —— 未钉 */
/* @0xcfb8c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> —— 未钉 */
/* @0xcfb90 mov r0, r6 —— 未钉 */
/* @0xcfb94 bl 0x27d1d0 <_ZdlPv> —— 未钉 */
/* @0xcfb98 b 0xcfb10 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1fc> —— 未钉 */
/* @0xcfb9c mov r0, r5 —— 未钉 */
/* @0xcfba0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> —— 未钉 */
/* @0xcfba4 b 0xcf98c <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x78> —— 未钉 */
/* @0xcfba8 ldr r3, [pc, #0xac] —— 未钉 */
/* @0xcfbac mov r1, #1 —— 未钉 */
/* @0xcfbb0 ldr r2, [r4, #0x60] —— 未钉 */
/* @0xcfbb4 ldr r0, [r6, r3] —— 未钉 */
/* @0xcfbb8 bl 0x2a0738 <_ZN9CProfiler4PushEii> —— 未钉 */
/* @0xcfbbc b 0xcfa7c <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x168> —— 未钉 */
/* @0xcfbc0 ldr r0, [r6] —— 未钉 */
/* @0xcfbc4 bl 0xcef90 <_Z6YYFreePKv> —— 未钉 */
/* @0xcfbc8 str r7, [r6] —— 未钉 */
/* @0xcfbcc str r7, [r6, #0x8] —— 未钉 */
/* @0xcfbd0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> —— 未钉 */
/* @0xcfbd4 ldr r7, [r6, #0x4] —— 未钉 */
/* @0xcfbd8 sub r7, r7, #1 —— 未钉 */
/* @0xcfbdc str r7, [r6, #0x4] —— 未钉 */
/* @0xcfbe0 cmp r7, #0 —— 未钉 */
/* @0xcfbe4 beq 0xcfbf8 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x2e4> —— 未钉 */
/* @0xcfbe8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> —— 未钉 */
/* @0xcfbec mov r0, r6 —— 未钉 */
/* @0xcfbf0 bl 0x27d1d0 <_ZdlPv> —— 未钉 */
/* @0xcfbf4 b 0xcfb8c <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x278> —— 未钉 */
/* @0xcfbf8 ldr r0, [r6] —— 未钉 */
/* @0xcfbfc bl 0xcef90 <_Z6YYFreePKv> —— 未钉 */
/* @0xcfc00 str r7, [r6] —— 未钉 */
/* @0xcfc04 str r7, [r6, #0x8] —— 未钉 */
/* @0xcfc08 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> —— 未钉 */
/* @0xcfc0c ldr r7, [r6, #0x4] —— 未钉 */
/* @0xcfc10 sub r7, r7, #1 —— 未钉 */
/* @0xcfc14 str r7, [r6, #0x4] —— 未钉 */
/* @0xcfc18 cmp r7, #0 —— 未钉 */
/* @0xcfc1c bne 0xcfc40 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x32c> —— 未钉 */
/* @0xcfc20 ldr r0, [r6] —— 未钉 */
/* @0xcfc24 bl 0xcef90 <_Z6YYFreePKv> —— 未钉 */
/* @0xcfc28 mov r0, r6 —— 未钉 */
/* @0xcfc2c str r7, [r6] —— 未钉 */
/* @0xcfc30 str r7, [r6, #0x8] —— 未钉 */
/* @0xcfc34 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> —— 未钉 */
/* @0xcfc38 mov r0, r6 —— 未钉 */
/* @0xcfc3c bl 0x27d1d0 <_ZdlPv> —— 未钉 */
/* @0xcfc40 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> —— 未钉 */
/* @0xcfc44 mov r0, r6 —— 未钉 */
/* @0xcfc48 bl 0x27d1d0 <_ZdlPv> —— 未钉 */
/* @0xcfc4c b 0xcfbe8 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x2d4> —— 未钉 */
/* @0xcfc50 eorseq r2, r2, r4, lsr #6 —— 未钉 */
/* @0xcfc54 .word 0xffffbf14 —— 未钉 */
/* @0xcfc58 .word 0xffffbf18 —— 未钉 */
/* @0xcfc5c .word 0xffffbf1c —— 未钉 */
