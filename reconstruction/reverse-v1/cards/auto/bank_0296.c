/* libyoyo.so 覆盖卡组 0296
 * 函数 0x319cc4..0x31afa4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x319cc4 · anon_319cc4 · size=40 · insn=11 */
/* @0x319cc4 push {r0, r1, r2, r3, r4, lr} */
/* @0x319cc8 add r3, sp, #16 */
/* @0x319ccc mov r12, r1 */
/* @0x319cd0 mov r1, #0 */
/* @0x319cd4 str r2, [r3, #-0x4]! */
/* @0x319cd8 mov r2, r12 */
/* @0x319cdc str r3, [sp] */
/* @0x319ce0 mov r3, r1 */
/* @0x319ce4 bl 0x319c68 <_Unwind_VRS_Set> */
/* @0x319ce8 add sp, sp, #20 */
/* @0x319cec ldr pc, [sp], #4 */

/* ── FUNC 0x319cf0 · __gnu_Unwind_Backtrace · size=196 · insn=49 */
/* @0x319cf0 ldr r3, [r2, #0x3c] */
/* @0x319cf4 push {r4, r5, r6, r7, r8, lr} */
/* @0x319cf8 add lr, r2, #4 */
/* @0x319cfc str r3, [r2, #0x40] */
/* @0x319d00 mov r7, r0 */
/* @0x319d04 mov r8, r1 */
/* @0x319d08 sub sp, sp, #568 */
/* @0x319d0c ldm lr!, {r0, r1, r2, r3} */
/* @0x319d10 add r12, sp, #92 */
/* @0x319d14 add r4, sp, #88 */
/* @0x319d18 stm r12!, {r0, r1, r2, r3} */
/* @0x319d1c ldm lr!, {r0, r1, r2, r3} */
/* @0x319d20 stm r12!, {r0, r1, r2, r3} */
/* @0x319d24 ldm lr!, {r0, r1, r2, r3} */
/* @0x319d28 stm r12!, {r0, r1, r2, r3} */
/* @0x319d2c ldm lr, {r0, r1, r2, r3} */
/* @0x319d30 stm r12, {r0, r1, r2, r3} */
/* @0x319d34 mvn r3, #0 */
/* @0x319d38 str r3, [sp, #0x58] */
/* @0x319d3c mov r0, sp */
/* @0x319d40 ldr r1, [sp, #0x98] */
/* @0x319d44 bl 0x319744 <__gnu_uldivmod_helper+0x150> */
/* @0x319d48 cmp r0, #0 */
/* @0x319d4c beq 0x319d58 <__gnu_Unwind_Backtrace+0x68> */
/* @0x319d50 mov r5, #9 */
/* @0x319d54 b 0x319da0 <__gnu_Unwind_Backtrace+0xb0> */
/* @0x319d58 mov r0, r4 */
/* @0x319d5c mov r1, #12 */
/* @0x319d60 mov r2, sp */
/* @0x319d64 bl 0x319cc4 <_Unwind_VRS_Set+0x5c> */
/* @0x319d68 mov r0, r4 */
/* @0x319d6c mov r1, r8 */
/* @0x319d70 blx r7 */
/* @0x319d74 cmp r0, #0 */
/* @0x319d78 bne 0x319d50 <__gnu_Unwind_Backtrace+0x60> */
/* @0x319d7c mov r0, #8 */
/* @0x319d80 mov r1, sp */
/* @0x319d84 mov r2, r4 */
/* @0x319d88 ldr r3, [sp, #0x10] */
/* @0x319d8c blx r3 */
/* @0x319d90 cmp r0, #9 */
/* @0x319d94 cmpne r0, #5 */
/* @0x319d98 mov r5, r0 */
/* @0x319d9c bne 0x319d3c <__gnu_Unwind_Backtrace+0x4c> */
/* @0x319da0 mov r0, r4 */
/* @0x319da4 bl 0x319850 <__gnu_uldivmod_helper+0x25c> */
/* @0x319da8 mov r0, r5 */
/* @0x319dac add sp, sp, #568 */
/* @0x319db0 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x319db4 · anon_319db4 · size=1004 · insn=252 */
/* @0x319db4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x319db8 mov r6, r2 */
/* @0x319dbc ldr r2, [r1, #0x4c] */
/* @0x319dc0 sub sp, sp, #36 */
/* @0x319dc4 subs r9, r3, #0 */
/* @0x319dc8 mov r4, r1 */
/* @0x319dcc add r5, r2, #4 */
/* @0x319dd0 and r7, r0, #3 */
/* @0x319dd4 ldr r2, [r2] */
/* @0x319dd8 str r5, [sp, #0x18] */
/* @0x319ddc str r2, [sp, #0x14] */
/* @0x319de0 bne 0x319dfc <__gnu_Unwind_Backtrace+0x10c> */
/* @0x319de4 lsl r2, r2, #8 */
/* @0x319de8 mov r3, #3 */
/* @0x319dec str r2, [sp, #0x14] */
/* @0x319df0 strb r9, [sp, #0x1d] */
/* @0x319df4 strb r3, [sp, #0x1c] */
/* @0x319df8 b 0x319e24 <__gnu_Unwind_Backtrace+0x134> */
/* @0x319dfc cmp r9, #2 */
/* @0x319e00 bgt 0x319e24 <__gnu_Unwind_Backtrace+0x134> */
/* @0x319e04 lsr r3, r2, #16 */
/* @0x319e08 strb r3, [sp, #0x1d] */
/* @0x319e0c lsl r2, r2, #16 */
/* @0x319e10 str r2, [sp, #0x14] */
/* @0x319e14 uxtb r3, r3 */
/* @0x319e18 mov r2, #2 */
/* @0x319e1c strb r2, [sp, #0x1c] */
/* @0x319e20 add r5, r5, r3, lsl #2 */
/* @0x319e24 cmp r7, #2 */
/* @0x319e28 ldr r10, [r4, #0x50] */
/* @0x319e2c ldreq r5, [r4, #0x38] */
/* @0x319e30 ands r10, r10, #1 */
/* @0x319e34 bne 0x31a130 <__gnu_Unwind_Backtrace+0x440> */
/* @0x319e38 eor r0, r0, #8 */
/* @0x319e3c ubfx r0, r0, #0x3, #0x1 */
/* @0x319e40 str r0, [sp, #0xc] */
/* @0x319e44 ldr r8, [r5] */
/* @0x319e48 cmp r8, #0 */
/* @0x319e4c beq 0x31a134 <__gnu_Unwind_Backtrace+0x444> */
/* @0x319e50 cmp r9, #2 */
/* @0x319e54 ldr r2, [r4, #0x48] */
/* @0x319e58 mov r0, r6 */
/* @0x319e5c mov r1, #15 */
/* @0x319e60 ldreq r11, [r5, #0x4] */
/* @0x319e64 addeq r5, r5, #8 */
/* @0x319e68 ldrhne r11, [r5, #2] */
/* @0x319e6c ldrhne r8, [r5] */
/* @0x319e70 addne r5, r5, #4 */
/* @0x319e74 bic r3, r11, #1 */
/* @0x319e78 add r3, r3, r2 */
/* @0x319e7c str r3, [sp, #0x4] */
/* @0x319e80 bl 0x319c40 <_Unwind_VRS_Get+0x5c> */
/* @0x319e84 ldr r3, [sp, #0x4] */
/* @0x319e88 cmp r3, r0 */
/* @0x319e8c movhi r0, #0 */
/* @0x319e90 bhi 0x319ea8 <__gnu_Unwind_Backtrace+0x1b8> */
/* @0x319e94 bic r2, r8, #1 */
/* @0x319e98 add r3, r3, r2 */
/* @0x319e9c cmp r0, r3 */
/* @0x319ea0 movhs r0, #0 */
/* @0x319ea4 movlo r0, #1 */
/* @0x319ea8 and r11, r11, #1 */
/* @0x319eac and r8, r8, #1 */
/* @0x319eb0 orr r8, r8, r11, lsl #1 */
/* @0x319eb4 cmp r8, #1 */
/* @0x319eb8 beq 0x319f1c <__gnu_Unwind_Backtrace+0x22c> */
/* @0x319ebc blo 0x319ecc <__gnu_Unwind_Backtrace+0x1dc> */
/* @0x319ec0 cmp r8, #2 */
/* @0x319ec4 beq 0x319ffc <__gnu_Unwind_Backtrace+0x30c> */
/* @0x319ec8 b 0x31a194 <__gnu_Unwind_Backtrace+0x4a4> */
/* @0x319ecc cmp r7, #0 */
/* @0x319ed0 moveq r0, #0 */
/* @0x319ed4 andne r0, r0, #1 */
/* @0x319ed8 add r8, r5, #4 */
/* @0x319edc cmp r0, #0 */
/* @0x319ee0 beq 0x319f14 <__gnu_Unwind_Backtrace+0x224> */
/* @0x319ee4 mov r0, r5 */
/* @0x319ee8 bl 0x319630 <__gnu_uldivmod_helper+0x3c> */
/* @0x319eec str r8, [r4, #0x38] */
/* @0x319ef0 mov r5, r0 */
/* @0x319ef4 mov r0, r4 */
/* @0x319ef8 blx 0x318628 <__cxa_begin_cleanup> */
/* @0x319efc cmp r0, #0 */
/* @0x319f00 beq 0x31a194 <__gnu_Unwind_Backtrace+0x4a4> */
/* @0x319f04 mov r0, r6 */
/* @0x319f08 mov r1, #15 */
/* @0x319f0c mov r2, r5 */
/* @0x319f10 b 0x319fe8 <__gnu_Unwind_Backtrace+0x2f8> */
/* @0x319f14 mov r5, r8 */
/* @0x319f18 b 0x319e44 <__gnu_Unwind_Backtrace+0x154> */
/* @0x319f1c cmp r7, #0 */
/* @0x319f20 bne 0x319fa0 <__gnu_Unwind_Backtrace+0x2b0> */
/* @0x319f24 cmp r0, #0 */
/* @0x319f28 beq 0x319ff4 <__gnu_Unwind_Backtrace+0x304> */
/* @0x319f2c ldr r3, [r5, #0x4] */
/* @0x319f30 ldr r11, [r5] */
/* @0x319f34 cmn r3, #2 */
/* @0x319f38 lsr r11, r11, #31 */
/* @0x319f3c beq 0x31a194 <__gnu_Unwind_Backtrace+0x4a4> */
/* @0x319f40 cmn r3, #1 */
/* @0x319f44 add r2, r4, #88 */
/* @0x319f48 str r2, [sp, #0x10] */
/* @0x319f4c beq 0x319f74 <__gnu_Unwind_Backtrace+0x284> */
/* @0x319f50 add r0, r5, #4 */
/* @0x319f54 bl 0x3198bc <__gnu_uldivmod_helper+0x2c8> */
/* @0x319f58 mov r2, r11 */
/* @0x319f5c add r3, sp, #16 */
/* @0x319f60 mov r1, r0 */
/* @0x319f64 mov r0, r4 */
/* @0x319f68 blx 0x3185b4 <__cxa_type_match> */
/* @0x319f6c subs r8, r0, #0 */
/* @0x319f70 beq 0x319ff4 <__gnu_Unwind_Backtrace+0x304> */
/* @0x319f74 mov r0, r6 */
/* @0x319f78 mov r1, #13 */
/* @0x319f7c bl 0x319c40 <_Unwind_VRS_Get+0x5c> */
/* @0x319f80 cmp r8, #2 */
/* @0x319f84 ldr r2, [sp, #0x10] */
/* @0x319f88 moveq r3, r4 */
/* @0x319f8c strne r2, [r4, #0x24] */
/* @0x319f90 str r0, [r4, #0x20] */
/* @0x319f94 streq r2, [r3, #0x2c]! */
/* @0x319f98 bne 0x31a094 <__gnu_Unwind_Backtrace+0x3a4> */
/* @0x319f9c b 0x31a090 <__gnu_Unwind_Backtrace+0x3a0> */
/* @0x319fa0 mov r0, r6 */
/* @0x319fa4 mov r1, #13 */
/* @0x319fa8 ldr r8, [r4, #0x20] */
/* @0x319fac bl 0x319c40 <_Unwind_VRS_Get+0x5c> */
/* @0x319fb0 cmp r8, r0 */
/* @0x319fb4 bne 0x319ff4 <__gnu_Unwind_Backtrace+0x304> */
/* @0x319fb8 ldr r3, [r4, #0x28] */
/* @0x319fbc cmp r5, r3 */
/* @0x319fc0 bne 0x319ff4 <__gnu_Unwind_Backtrace+0x304> */
/* @0x319fc4 mov r0, r5 */
/* @0x319fc8 bl 0x319630 <__gnu_uldivmod_helper+0x3c> */
/* @0x319fcc mov r1, #15 */
/* @0x319fd0 mov r2, r0 */
/* @0x319fd4 mov r0, r6 */
/* @0x319fd8 bl 0x319cc4 <_Unwind_VRS_Set+0x5c> */
/* @0x319fdc mov r0, r6 */
/* @0x319fe0 mov r1, #0 */
/* @0x319fe4 mov r2, r4 */
/* @0x319fe8 bl 0x319cc4 <_Unwind_VRS_Set+0x5c> */
/* @0x319fec mov r0, #7 */
/* @0x319ff0 b 0x31a198 <__gnu_Unwind_Backtrace+0x4a8> */
/* @0x319ff4 add r5, r5, #8 */
/* @0x319ff8 b 0x319e44 <__gnu_Unwind_Backtrace+0x154> */
/* @0x319ffc ldr r8, [r5] */
/* @0x31a000 cmp r7, #0 */
/* @0x31a004 bic r8, r8, #-2147483648 */
/* @0x31a008 bne 0x31a0a0 <__gnu_Unwind_Backtrace+0x3b0> */
/* @0x31a00c cmp r0, #0 */
/* @0x31a010 beq 0x31a118 <__gnu_Unwind_Backtrace+0x428> */
/* @0x31a014 ldr r3, [sp, #0xc] */
/* @0x31a018 cmp r8, #0 */
/* @0x31a01c orreq r3, r3, #1 */
/* @0x31a020 cmp r3, #0 */
/* @0x31a024 beq 0x31a118 <__gnu_Unwind_Backtrace+0x428> */
/* @0x31a028 add r11, sp, #16 */
/* @0x31a02c mov r12, r7 */
/* @0x31a030 add r3, r4, #88 */
/* @0x31a034 str r3, [sp, #0x8] */
/* @0x31a038 cmp r12, r8 */
/* @0x31a03c beq 0x31a07c <__gnu_Unwind_Backtrace+0x38c> */
/* @0x31a040 add r12, r12, #1 */
/* @0x31a044 ldr r3, [sp, #0x8] */
/* @0x31a048 str r12, [sp, #0x4] */
/* @0x31a04c add r0, r5, r12, lsl #2 */
/* @0x31a050 str r3, [sp, #0x10] */
/* @0x31a054 bl 0x3198bc <__gnu_uldivmod_helper+0x2c8> */
/* @0x31a058 mov r2, #0 */
/* @0x31a05c mov r3, r11 */
/* @0x31a060 mov r1, r0 */
/* @0x31a064 mov r0, r4 */
/* @0x31a068 blx 0x3185b4 <__cxa_type_match> */
/* @0x31a06c ldr r12, [sp, #0x4] */
/* @0x31a070 cmp r0, #0 */
/* @0x31a074 beq 0x31a038 <__gnu_Unwind_Backtrace+0x348> */
/* @0x31a078 b 0x31a118 <__gnu_Unwind_Backtrace+0x428> */
/* @0x31a07c mov r0, r6 */
/* @0x31a080 mov r1, #13 */
/* @0x31a084 bl 0x319c40 <_Unwind_VRS_Get+0x5c> */
/* @0x31a088 ldr r3, [sp, #0x10] */
/* @0x31a08c str r0, [r4, #0x20] */
/* @0x31a090 str r3, [r4, #0x24] */
/* @0x31a094 str r5, [r4, #0x28] */
/* @0x31a098 mov r0, #6 */
/* @0x31a09c b 0x31a198 <__gnu_Unwind_Backtrace+0x4a8> */
/* @0x31a0a0 mov r0, r6 */
/* @0x31a0a4 mov r1, #13 */
/* @0x31a0a8 ldr r11, [r4, #0x20] */
/* @0x31a0ac bl 0x319c40 <_Unwind_VRS_Get+0x5c> */
/* @0x31a0b0 cmp r11, r0 */
/* @0x31a0b4 bne 0x31a118 <__gnu_Unwind_Backtrace+0x428> */
/* @0x31a0b8 ldr r3, [r4, #0x28] */
/* @0x31a0bc cmp r5, r3 */
/* @0x31a0c0 bne 0x31a118 <__gnu_Unwind_Backtrace+0x428> */
/* @0x31a0c4 mov r10, #0 */
/* @0x31a0c8 mov r3, #4 */
/* @0x31a0cc str r8, [r4, #0x28] */
/* @0x31a0d0 str r3, [r4, #0x30] */
/* @0x31a0d4 add r3, r5, r3 */
/* @0x31a0d8 str r10, [r4, #0x2c] */
/* @0x31a0dc str r3, [r4, #0x34] */
/* @0x31a0e0 ldr r3, [r5] */
/* @0x31a0e4 cmp r3, r10 */
/* @0x31a0e8 bge 0x31a114 <__gnu_Unwind_Backtrace+0x424> */
/* @0x31a0ec add r0, r8, #1 */
/* @0x31a0f0 add r0, r5, r0, lsl #2 */
/* @0x31a0f4 bl 0x319630 <__gnu_uldivmod_helper+0x3c> */
/* @0x31a0f8 mov r1, #15 */
/* @0x31a0fc mov r2, r0 */
/* @0x31a100 mov r0, r6 */
/* @0x31a104 bl 0x319cc4 <_Unwind_VRS_Set+0x5c> */
/* @0x31a108 mov r0, r6 */
/* @0x31a10c mov r1, r10 */
/* @0x31a110 b 0x319fe4 <__gnu_Unwind_Backtrace+0x2f4> */
/* @0x31a114 mov r10, #1 */
/* @0x31a118 ldr r3, [r5] */
/* @0x31a11c add r8, r8, #1 */
/* @0x31a120 cmp r3, #0 */
/* @0x31a124 addlt r5, r5, #4 */
/* @0x31a128 add r5, r5, r8, lsl #2 */
/* @0x31a12c b 0x319e44 <__gnu_Unwind_Backtrace+0x154> */
/* @0x31a130 mov r10, #0 */
/* @0x31a134 cmp r9, #2 */
/* @0x31a138 ble 0x31a144 <__gnu_Unwind_Backtrace+0x454> */
/* @0x31a13c bl 0x3198d0 <__gnu_uldivmod_helper+0x2dc> */
/* @0x31a140 b 0x31a150 <__gnu_Unwind_Backtrace+0x460> */
/* @0x31a144 mov r0, r6 */
/* @0x31a148 add r1, sp, #20 */
/* @0x31a14c bl 0x31a73c <__gnu_unwind_execute> */
/* @0x31a150 cmp r0, #0 */
/* @0x31a154 bne 0x31a194 <__gnu_Unwind_Backtrace+0x4a4> */
/* @0x31a158 cmp r10, #0 */
/* @0x31a15c moveq r0, #8 */
/* @0x31a160 beq 0x31a198 <__gnu_Unwind_Backtrace+0x4a8> */
/* @0x31a164 mov r1, #15 */
/* @0x31a168 mov r0, r6 */
/* @0x31a16c bl 0x319c40 <_Unwind_VRS_Get+0x5c> */
/* @0x31a170 mov r1, #14 */
/* @0x31a174 mov r2, r0 */
/* @0x31a178 mov r0, r6 */
/* @0x31a17c bl 0x319cc4 <_Unwind_VRS_Set+0x5c> */
/* @0x31a180 ldr r2, [pc, #0x18] */
/* @0x31a184 mov r0, r6 */
/* @0x31a188 mov r1, #15 */
/* @0x31a18c ldr r2, [pc, r2] */
/* @0x31a190 b 0x319fe8 <__gnu_Unwind_Backtrace+0x2f8> */
/* @0x31a194 mov r0, #9 */
/* @0x31a198 add sp, sp, #36 */
/* @0x31a19c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x31a1a0 andeq r7, sp, r0, asr #21 */

/* ── FUNC 0x31a1a4 · __aeabi_unwind_cpp_pr0 · size=8 · insn=2 */
/* @0x31a1a4 mov r3, #0 */
/* @0x31a1a8 b 0x319db4 <__gnu_Unwind_Backtrace+0xc4> */

/* ── FUNC 0x31a1ac · __aeabi_unwind_cpp_pr1 · size=8 · insn=2 */
/* @0x31a1ac mov r3, #1 */
/* @0x31a1b0 b 0x319db4 <__gnu_Unwind_Backtrace+0xc4> */

/* ── FUNC 0x31a1b4 · __aeabi_unwind_cpp_pr2 · size=8 · insn=2 */
/* @0x31a1b4 mov r3, #2 */
/* @0x31a1b8 b 0x319db4 <__gnu_Unwind_Backtrace+0xc4> */

/* ── FUNC 0x31a1bc · _Unwind_VRS_Pop · size=844 · insn=211 */
/* @0x31a1bc push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x31a1c0 mov r4, r0 */
/* @0x31a1c4 sub sp, sp, #268 */
/* @0x31a1c8 mov r5, r2 */
/* @0x31a1cc cmp r1, #4 */
/* @0x31a1d0 addls pc, pc, r1, lsl #2 */
/* @0x31a1d4 b 0x31a4f4 <_Unwind_VRS_Pop+0x338> */
/* @0x31a1d8 b 0x31a1ec <_Unwind_VRS_Pop+0x30> */
/* @0x31a1dc b 0x31a230 <_Unwind_VRS_Pop+0x74> */
/* @0x31a1e0 b 0x31a4f4 <_Unwind_VRS_Pop+0x338> */
/* @0x31a1e4 b 0x31a410 <_Unwind_VRS_Pop+0x254> */
/* @0x31a1e8 b 0x31a48c <_Unwind_VRS_Pop+0x2d0> */
/* @0x31a1ec cmp r3, #0 */
/* @0x31a1f0 bne 0x31a4f4 <_Unwind_VRS_Pop+0x338> */
/* @0x31a1f4 uxth r1, r2 */
/* @0x31a1f8 ldr r2, [r0, #0x38] */
/* @0x31a1fc mov r0, #1 */
/* @0x31a200 ands r12, r1, r0, lsl r3 */
/* @0x31a204 addne r12, r4, r3, lsl #2 */
/* @0x31a208 add r3, r3, #1 */
/* @0x31a20c ldrne r6, [r2] */
/* @0x31a210 addne r2, r2, #4 */
/* @0x31a214 strne r6, [r12, #0x4] */
/* @0x31a218 cmp r3, #16 */
/* @0x31a21c bne 0x31a200 <_Unwind_VRS_Pop+0x44> */
/* @0x31a220 ands r0, r5, #8192 */
/* @0x31a224 streq r2, [r4, #0x38] */
/* @0x31a228 beq 0x31a500 <_Unwind_VRS_Pop+0x344> */
/* @0x31a22c b 0x31a4fc <_Unwind_VRS_Pop+0x340> */
/* @0x31a230 bic r2, r3, #4 */
/* @0x31a234 cmp r2, #1 */
/* @0x31a238 bne 0x31a4f4 <_Unwind_VRS_Pop+0x338> */
/* @0x31a23c cmp r3, #1 */
/* @0x31a240 lsr r6, r5, #16 */
/* @0x31a244 uxth r5, r5 */
/* @0x31a248 add r2, r5, r6 */
/* @0x31a24c movne r1, #32 */
/* @0x31a250 moveq r1, #16 */
/* @0x31a254 cmp r2, r1 */
/* @0x31a258 bhi 0x31a4f4 <_Unwind_VRS_Pop+0x338> */
/* @0x31a25c subs r1, r3, #1 */
/* @0x31a260 rsbs r9, r1, #0 */
/* @0x31a264 adcs r9, r9, r1 */
/* @0x31a268 cmp r6, #15 */
/* @0x31a26c movls r8, #0 */
/* @0x31a270 movhi r8, #1 */
/* @0x31a274 tst r9, r8 */
/* @0x31a278 bne 0x31a4f4 <_Unwind_VRS_Pop+0x338> */
/* @0x31a27c cmp r8, #0 */
/* @0x31a280 movne r8, r5 */
/* @0x31a284 bne 0x31a290 <_Unwind_VRS_Pop+0xd4> */
/* @0x31a288 cmp r2, #16 */
/* @0x31a28c subhi r8, r2, #16 */
/* @0x31a290 adds r7, r8, #0 */
/* @0x31a294 movne r7, #1 */
/* @0x31a298 cmp r3, #5 */
/* @0x31a29c cmpne r8, #0 */
/* @0x31a2a0 bne 0x31a4f4 <_Unwind_VRS_Pop+0x338> */
/* @0x31a2a4 cmp r6, #15 */
/* @0x31a2a8 bhi 0x31a2e8 <_Unwind_VRS_Pop+0x12c> */
/* @0x31a2ac ldr r2, [r4] */
/* @0x31a2b0 tst r2, #1 */
/* @0x31a2b4 beq 0x31a2e8 <_Unwind_VRS_Pop+0x12c> */
/* @0x31a2b8 cmp r3, #5 */
/* @0x31a2bc mov r0, r4 */
/* @0x31a2c0 bic r1, r2, #1 */
/* @0x31a2c4 str r1, [r0], #72 */
/* @0x31a2c8 bne 0x31a2dc <_Unwind_VRS_Pop+0x120> */
/* @0x31a2cc orr r1, r1, #2 */
/* @0x31a2d0 str r1, [r4] */
/* @0x31a2d4 bl 0x31a534 <__gnu_Unwind_Save_VFP_D> */
/* @0x31a2d8 b 0x31a2e8 <_Unwind_VRS_Pop+0x12c> */
/* @0x31a2dc bic r2, r2, #3 */
/* @0x31a2e0 str r2, [r4] */
/* @0x31a2e4 bl 0x31a524 <__gnu_Unwind_Save_VFP> */
/* @0x31a2e8 cmp r7, #0 */
/* @0x31a2ec beq 0x31a30c <_Unwind_VRS_Pop+0x150> */
/* @0x31a2f0 ldr r3, [r4] */
/* @0x31a2f4 tst r3, #4 */
/* @0x31a2f8 beq 0x31a30c <_Unwind_VRS_Pop+0x150> */
/* @0x31a2fc mov r0, r4 */
/* @0x31a300 bic r3, r3, #4 */
/* @0x31a304 str r3, [r0], #208 */
/* @0x31a308 bl 0x31a544 <__gnu_Unwind_Save_VFP_D_16_to_31> */
/* @0x31a30c cmp r9, #0 */
/* @0x31a310 beq 0x31a328 <_Unwind_VRS_Pop+0x16c> */
/* @0x31a314 add r0, sp, #128 */
/* @0x31a318 bl 0x31a524 <__gnu_Unwind_Save_VFP> */
/* @0x31a31c cmp r7, #0 */
/* @0x31a320 bne 0x31a348 <_Unwind_VRS_Pop+0x18c> */
/* @0x31a324 b 0x31a34c <_Unwind_VRS_Pop+0x190> */
/* @0x31a328 cmp r6, #15 */
/* @0x31a32c bhi 0x31a338 <_Unwind_VRS_Pop+0x17c> */
/* @0x31a330 add r0, sp, #128 */
/* @0x31a334 bl 0x31a534 <__gnu_Unwind_Save_VFP_D> */
/* @0x31a338 cmp r7, #0 */
/* @0x31a33c beq 0x31a34c <_Unwind_VRS_Pop+0x190> */
/* @0x31a340 mov r0, sp */
/* @0x31a344 bl 0x31a544 <__gnu_Unwind_Save_VFP_D_16_to_31> */
/* @0x31a348 rsb r5, r6, #16 */
/* @0x31a34c ldr r2, [r4, #0x38] */
/* @0x31a350 cmp r5, #0 */
/* @0x31a354 mov r3, r2 */
/* @0x31a358 ble 0x31a388 <_Unwind_VRS_Pop+0x1cc> */
/* @0x31a35c add r3, sp, #128 */
/* @0x31a360 lsl r5, r5, #1 */
/* @0x31a364 add r3, r3, r6, lsl #3 */
/* @0x31a368 sub r0, r2, #4 */
/* @0x31a36c rsb r3, r2, r3 */
/* @0x31a370 mov r1, r5 */
/* @0x31a374 subs r1, r1, #1 */
/* @0x31a378 ldrhs r12, [r0, #0x4]! */
/* @0x31a37c strhs r12, [r3, r0] */
/* @0x31a380 bhs 0x31a374 <_Unwind_VRS_Pop+0x1b8> */
/* @0x31a384 add r3, r2, r5, lsl #2 */
/* @0x31a388 cmp r7, #0 */
/* @0x31a38c beq 0x31a3cc <_Unwind_VRS_Pop+0x210> */
/* @0x31a390 cmp r6, #16 */
/* @0x31a394 movhs r0, r6 */
/* @0x31a398 movlo r0, #16 */
/* @0x31a39c add r2, sp, #264 */
/* @0x31a3a0 lsl r8, r8, #1 */
/* @0x31a3a4 add r0, r2, r0, lsl #3 */
/* @0x31a3a8 mov r2, #0 */
/* @0x31a3ac sub r0, r0, #392 */
/* @0x31a3b0 cmp r2, r8 */
/* @0x31a3b4 lsl r1, r2, #2 */
/* @0x31a3b8 ldrne r1, [r3, r2, lsl #2] */
/* @0x31a3bc strne r1, [r0, r2, lsl #2] */
/* @0x31a3c0 addne r2, r2, #1 */
/* @0x31a3c4 bne 0x31a3b0 <_Unwind_VRS_Pop+0x1f4> */
/* @0x31a3c8 add r3, r3, r1 */
/* @0x31a3cc cmp r9, #0 */
/* @0x31a3d0 addne r3, r3, #4 */
/* @0x31a3d4 cmp r9, #0 */
/* @0x31a3d8 str r3, [r4, #0x38] */
/* @0x31a3dc beq 0x31a3ec <_Unwind_VRS_Pop+0x230> */
/* @0x31a3e0 add r0, sp, #128 */
/* @0x31a3e4 bl 0x31a51c <__gnu_Unwind_Restore_VFP> */
/* @0x31a3e8 b 0x31a4fc <_Unwind_VRS_Pop+0x340> */
/* @0x31a3ec cmp r6, #15 */
/* @0x31a3f0 bhi 0x31a3fc <_Unwind_VRS_Pop+0x240> */
/* @0x31a3f4 add r0, sp, #128 */
/* @0x31a3f8 bl 0x31a52c <__gnu_Unwind_Restore_VFP_D> */
/* @0x31a3fc cmp r7, #0 */
/* @0x31a400 beq 0x31a4fc <_Unwind_VRS_Pop+0x340> */
/* @0x31a404 mov r0, sp */
/* @0x31a408 bl 0x31a53c <__gnu_Unwind_Restore_VFP_D_16_to_31> */
/* @0x31a40c b 0x31a4fc <_Unwind_VRS_Pop+0x340> */
/* @0x31a410 cmp r3, #3 */
/* @0x31a414 bne 0x31a4f4 <_Unwind_VRS_Pop+0x338> */
/* @0x31a418 lsr r7, r2, #16 */
/* @0x31a41c uxth r5, r2 */
/* @0x31a420 add r3, r5, r7 */
/* @0x31a424 cmp r3, #16 */
/* @0x31a428 bhi 0x31a4f4 <_Unwind_VRS_Pop+0x338> */
/* @0x31a42c ldr r3, [r0] */
/* @0x31a430 tst r3, #8 */
/* @0x31a434 beq 0x31a444 <_Unwind_VRS_Pop+0x288> */
/* @0x31a438 bic r3, r3, #8 */
/* @0x31a43c str r3, [r0], #336 */
/* @0x31a440 bl 0x31a590 <__gnu_Unwind_Save_WMMXD> */
/* @0x31a444 add r6, sp, #128 */
/* @0x31a448 lsl r5, r5, #1 */
/* @0x31a44c add r7, r6, r7, lsl #3 */
/* @0x31a450 mov r0, r6 */
/* @0x31a454 bl 0x31a590 <__gnu_Unwind_Save_WMMXD> */
/* @0x31a458 ldr r3, [r4, #0x38] */
/* @0x31a45c mov r2, r5 */
/* @0x31a460 sub r1, r3, #4 */
/* @0x31a464 rsb r7, r3, r7 */
/* @0x31a468 subs r2, r2, #1 */
/* @0x31a46c ldrhs r0, [r1, #0x4]! */
/* @0x31a470 strhs r0, [r7, r1] */
/* @0x31a474 bhs 0x31a468 <_Unwind_VRS_Pop+0x2ac> */
/* @0x31a478 add r5, r3, r5, lsl #2 */
/* @0x31a47c mov r0, r6 */
/* @0x31a480 str r5, [r4, #0x38] */
/* @0x31a484 bl 0x31a54c <__gnu_Unwind_Restore_WMMXD> */
/* @0x31a488 b 0x31a4fc <_Unwind_VRS_Pop+0x340> */
/* @0x31a48c cmp r2, #16 */
/* @0x31a490 cmpls r3, #0 */
/* @0x31a494 bne 0x31a4f4 <_Unwind_VRS_Pop+0x338> */
/* @0x31a498 ldr r3, [r0] */
/* @0x31a49c tst r3, #16 */
/* @0x31a4a0 beq 0x31a4b0 <_Unwind_VRS_Pop+0x2f4> */
/* @0x31a4a4 bic r3, r3, #16 */
/* @0x31a4a8 str r3, [r0], #464 */
/* @0x31a4ac bl 0x31a5e8 <__gnu_Unwind_Save_WMMXC> */
/* @0x31a4b0 add r6, sp, #128 */
/* @0x31a4b4 mov r0, r6 */
/* @0x31a4b8 bl 0x31a5e8 <__gnu_Unwind_Save_WMMXC> */
/* @0x31a4bc ldr r2, [r4, #0x38] */
/* @0x31a4c0 mov r3, #0 */
/* @0x31a4c4 mov r1, #1 */
/* @0x31a4c8 ands r12, r5, r1, lsl r3 */
/* @0x31a4cc ldrne r0, [r2] */
/* @0x31a4d0 addne r2, r2, #4 */
/* @0x31a4d4 strne r0, [r6, r3, lsl #2] */
/* @0x31a4d8 add r3, r3, #1 */
/* @0x31a4dc cmp r3, #4 */
/* @0x31a4e0 bne 0x31a4c8 <_Unwind_VRS_Pop+0x30c> */
/* @0x31a4e4 str r2, [r4, #0x38] */
/* @0x31a4e8 mov r0, r6 */
/* @0x31a4ec bl 0x31a5d4 <__gnu_Unwind_Restore_WMMXC> */
/* @0x31a4f0 b 0x31a4fc <_Unwind_VRS_Pop+0x340> */
/* @0x31a4f4 mov r0, #2 */
/* @0x31a4f8 b 0x31a500 <_Unwind_VRS_Pop+0x344> */
/* @0x31a4fc mov r0, #0 */
/* @0x31a500 add sp, sp, #268 */
/* @0x31a504 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x31a508 · __restore_core_regs · size=20 · insn=5 */
/* @0x31a508 add r1, r0, #52 */
/* @0x31a50c ldm r1, {r3, r4, r5} */
/* @0x31a510 push {r3, r4, r5} */
/* @0x31a514 ldm r0, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x31a518 ldm sp, {sp, lr, pc} */

/* ── FUNC 0x31a508 · restore_core_regs · alias of the symbol above · insn=0 */

/* ── FUNC 0x31a51c · anon_31a51c · size=220 · insn=56 */
/* @0x31a51c fldmiax r0, {d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x31a520 bx lr */
/* @0x31a524 fstmiax r0, {d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x31a528 bx lr */
/* @0x31a52c vldmia r0, {d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x31a530 bx lr */
/* @0x31a534 vstmia r0, {d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x31a538 bx lr */
/* @0x31a53c vldmia r0, {d16, d17, d18, d19, d20, d21, d22, d23, d24, d25, d26, d27, d28, d29, d30, d31} */
/* @0x31a540 bx lr */
/* @0x31a544 vstmia r0, {d16, d17, d18, d19, d20, d21, d22, d23, d24, d25, d26, d27, d28, d29, d30, d31} */
/* @0x31a548 bx lr */
/* @0x31a54c ldcl p1, c0, [r0], #8 */
/* @0x31a550 ldcl p1, c1, [r0], #8 */
/* @0x31a554 ldcl p1, c2, [r0], #8 */
/* @0x31a558 ldcl p1, c3, [r0], #8 */
/* @0x31a55c ldcl p1, c4, [r0], #8 */
/* @0x31a560 ldcl p1, c5, [r0], #8 */
/* @0x31a564 ldcl p1, c6, [r0], #8 */
/* @0x31a568 ldcl p1, c7, [r0], #8 */
/* @0x31a56c ldcl p1, c8, [r0], #8 */
/* @0x31a570 ldcl p1, c9, [r0], #8 */
/* @0x31a574 ldcl p1, c10, [r0], #8 */
/* @0x31a578 ldcl p1, c11, [r0], #8 */
/* @0x31a57c ldcl p1, c12, [r0], #8 */
/* @0x31a580 ldcl p1, c13, [r0], #8 */
/* @0x31a584 ldcl p1, c14, [r0], #8 */
/* @0x31a588 ldcl p1, c15, [r0], #8 */
/* @0x31a58c bx lr */
/* @0x31a590 stcl p1, c0, [r0], #8 */
/* @0x31a594 stcl p1, c1, [r0], #8 */
/* @0x31a598 stcl p1, c2, [r0], #8 */
/* @0x31a59c stcl p1, c3, [r0], #8 */
/* @0x31a5a0 stcl p1, c4, [r0], #8 */
/* @0x31a5a4 stcl p1, c5, [r0], #8 */
/* @0x31a5a8 stcl p1, c6, [r0], #8 */
/* @0x31a5ac stcl p1, c7, [r0], #8 */
/* @0x31a5b0 stcl p1, c8, [r0], #8 */
/* @0x31a5b4 stcl p1, c9, [r0], #8 */
/* @0x31a5b8 stcl p1, c10, [r0], #8 */
/* @0x31a5bc stcl p1, c11, [r0], #8 */
/* @0x31a5c0 stcl p1, c12, [r0], #8 */
/* @0x31a5c4 stcl p1, c13, [r0], #8 */
/* @0x31a5c8 stcl p1, c14, [r0], #8 */
/* @0x31a5cc stcl p1, c15, [r0], #8 */
/* @0x31a5d0 bx lr */
/* @0x31a5d4 ldc2 p1, c8, [r0], #4 */
/* @0x31a5d8 ldc2 p1, c9, [r0], #4 */
/* @0x31a5dc ldc2 p1, c10, [r0], #4 */
/* @0x31a5e0 ldc2 p1, c11, [r0], #4 */
/* @0x31a5e4 bx lr */
/* @0x31a5e8 stc2 p1, c8, [r0], #4 */
/* @0x31a5ec stc2 p1, c9, [r0], #4 */
/* @0x31a5f0 stc2 p1, c10, [r0], #4 */
/* @0x31a5f4 stc2 p1, c11, [r0], #4 */
/* @0x31a5f8 bx lr */

/* ── FUNC 0x31a5fc · _Unwind_RaiseException · size=36 · insn=9 */
/* @0x31a5fc push {sp, lr, pc} */
/* @0x31a600 push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12} */
/* @0x31a604 mov r3, #0 */
/* @0x31a608 push {r2, r3} */
/* @0x31a60c add r1, sp, #4 */
/* @0x31a610 bl 0x319a6c <__gnu_Unwind_RaiseException> */
/* @0x31a614 ldr lr, [sp, #0x40] */
/* @0x31a618 add sp, sp, #72 */
/* @0x31a61c bx lr */

/* ── FUNC 0x31a5fc · ___Unwind_RaiseException · alias of the symbol above · insn=0 */

/* ── FUNC 0x31a620 · _Unwind_Resume · size=36 · insn=9 */
/* @0x31a620 push {sp, lr, pc} */
/* @0x31a624 push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12} */
/* @0x31a628 mov r3, #0 */
/* @0x31a62c push {r2, r3} */
/* @0x31a630 add r1, sp, #4 */
/* @0x31a634 bl 0x319b2c <__gnu_Unwind_Resume> */
/* @0x31a638 ldr lr, [sp, #0x40] */
/* @0x31a63c add sp, sp, #72 */
/* @0x31a640 bx lr */

/* ── FUNC 0x31a620 · ___Unwind_Resume · alias of the symbol above · insn=0 */

/* ── FUNC 0x31a644 · _Unwind_Resume_or_Rethrow · size=36 · insn=9 */
/* @0x31a644 push {sp, lr, pc} */
/* @0x31a648 push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12} */
/* @0x31a64c mov r3, #0 */
/* @0x31a650 push {r2, r3} */
/* @0x31a654 add r1, sp, #4 */
/* @0x31a658 bl 0x319ba0 <__gnu_Unwind_Resume_or_Rethrow> */
/* @0x31a65c ldr lr, [sp, #0x40] */
/* @0x31a660 add sp, sp, #72 */
/* @0x31a664 bx lr */

/* ── FUNC 0x31a644 · ___Unwind_Resume_or_Rethrow · alias of the symbol above · insn=0 */

/* ── FUNC 0x31a668 · _Unwind_ForcedUnwind · size=36 · insn=9 */
/* @0x31a668 push {sp, lr, pc} */
/* @0x31a66c push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12} */
/* @0x31a670 mov r3, #0 */
/* @0x31a674 push {r2, r3} */
/* @0x31a678 add r3, sp, #4 */
/* @0x31a67c bl 0x319b10 <__gnu_Unwind_ForcedUnwind> */
/* @0x31a680 ldr lr, [sp, #0x40] */
/* @0x31a684 add sp, sp, #72 */
/* @0x31a688 bx lr */

/* ── FUNC 0x31a668 · ___Unwind_ForcedUnwind · alias of the symbol above · insn=0 */

/* ── FUNC 0x31a68c · _Unwind_Backtrace · size=36 · insn=9 */
/* @0x31a68c push {sp, lr, pc} */
/* @0x31a690 push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12} */
/* @0x31a694 mov r3, #0 */
/* @0x31a698 push {r2, r3} */
/* @0x31a69c add r2, sp, #4 */
/* @0x31a6a0 bl 0x319cf0 <__gnu_Unwind_Backtrace> */
/* @0x31a6a4 ldr lr, [sp, #0x40] */
/* @0x31a6a8 add sp, sp, #72 */
/* @0x31a6ac bx lr */

/* ── FUNC 0x31a68c · ___Unwind_Backtrace · alias of the symbol above · insn=0 */

/* ── FUNC 0x31a6b0 · anon_31a6b0 · size=136 · insn=35 */
/* @0x31a6b0 ldrb r3, [r0, #0x8] */
/* @0x31a6b4 cmp r3, #0 */
/* @0x31a6b8 bne 0x31a6ec <___Unwind_Backtrace+0x60> */
/* @0x31a6bc ldrb r3, [r0, #0x9] */
/* @0x31a6c0 cmp r3, #0 */
/* @0x31a6c4 beq 0x31a708 <___Unwind_Backtrace+0x7c> */
/* @0x31a6c8 sub r3, r3, #1 */
/* @0x31a6cc strb r3, [r0, #0x9] */
/* @0x31a6d0 ldr r3, [r0, #0x4] */
/* @0x31a6d4 add r2, r3, #4 */
/* @0x31a6d8 str r2, [r0, #0x4] */
/* @0x31a6dc ldr r3, [r3] */
/* @0x31a6e0 str r3, [r0] */
/* @0x31a6e4 mov r3, #3 */
/* @0x31a6e8 b 0x31a6f0 <___Unwind_Backtrace+0x64> */
/* @0x31a6ec sub r3, r3, #1 */
/* @0x31a6f0 strb r3, [r0, #0x8] */
/* @0x31a6f4 ldr r3, [r0] */
/* @0x31a6f8 lsl r2, r3, #8 */
/* @0x31a6fc str r2, [r0] */
/* @0x31a700 lsr r0, r3, #24 */
/* @0x31a704 bx lr */
/* @0x31a708 mov r0, #176 */
/* @0x31a70c bx lr */
/* @0x31a710 push {r0, r1, r2, r3, r4, lr} */
/* @0x31a714 mov r1, #0 */
/* @0x31a718 add r3, sp, #12 */
/* @0x31a71c mov r2, #12 */
/* @0x31a720 str r3, [sp] */
/* @0x31a724 mov r3, r1 */
/* @0x31a728 bl 0x319be4 <_Unwind_VRS_Get> */
/* @0x31a72c ldr r0, [sp, #0xc] */
/* @0x31a730 add sp, sp, #20 */
/* @0x31a734 ldr pc, [sp], #4 */
/* @0x31a738 b 0x31a710 <___Unwind_Backtrace+0x84> */

/* ── FUNC 0x31a73c · __gnu_unwind_execute · size=892 · insn=223 */
/* @0x31a73c push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x31a740 add r8, sp, #12 */
/* @0x31a744 mov r5, r0 */
/* @0x31a748 mov r6, r1 */
/* @0x31a74c mov r7, #0 */
/* @0x31a750 mov r9, #4080 */
/* @0x31a754 mov r0, r6 */
/* @0x31a758 bl 0x31a6b0 <___Unwind_Backtrace+0x24> */
/* @0x31a75c cmp r0, #176 */
/* @0x31a760 mov r4, r0 */
/* @0x31a764 bne 0x31a7a8 <__gnu_unwind_execute+0x6c> */
/* @0x31a768 cmp r7, #0 */
/* @0x31a76c bne 0x31aaac <__gnu_unwind_execute+0x370> */
/* @0x31a770 add r4, sp, #12 */
/* @0x31a774 mov r1, r7 */
/* @0x31a778 mov r3, r7 */
/* @0x31a77c str r4, [sp] */
/* @0x31a780 mov r0, r5 */
/* @0x31a784 mov r2, #14 */
/* @0x31a788 bl 0x319be4 <_Unwind_VRS_Get> */
/* @0x31a78c str r4, [sp] */
/* @0x31a790 mov r0, r5 */
/* @0x31a794 mov r1, r7 */
/* @0x31a798 mov r2, #15 */
/* @0x31a79c mov r3, r7 */
/* @0x31a7a0 bl 0x319c68 <_Unwind_VRS_Set> */
/* @0x31a7a4 b 0x31aaac <__gnu_unwind_execute+0x370> */
/* @0x31a7a8 bic r1, r0, #127 */
/* @0x31a7ac ands r1, r1, #255 */
/* @0x31a7b0 bne 0x31a7ec <__gnu_unwind_execute+0xb0> */
/* @0x31a7b4 lsl r10, r0, #2 */
/* @0x31a7b8 mov r3, r1 */
/* @0x31a7bc str r8, [sp] */
/* @0x31a7c0 mov r0, r5 */
/* @0x31a7c4 mov r2, #13 */
/* @0x31a7c8 uxtb r10, r10 */
/* @0x31a7cc bl 0x319be4 <_Unwind_VRS_Get> */
/* @0x31a7d0 ldr r3, [sp, #0xc] */
/* @0x31a7d4 add r10, r10, #4 */
/* @0x31a7d8 tst r4, #64 */
/* @0x31a7dc rsbne r10, r10, r3 */
/* @0x31a7e0 addeq r10, r3, r10 */
/* @0x31a7e4 str r10, [sp, #0xc] */
/* @0x31a7e8 b 0x31a870 <__gnu_unwind_execute+0x134> */
/* @0x31a7ec and r3, r0, #240 */
/* @0x31a7f0 cmp r3, #128 */
/* @0x31a7f4 bne 0x31a844 <__gnu_unwind_execute+0x108> */
/* @0x31a7f8 lsl r4, r0, #8 */
/* @0x31a7fc mov r0, r6 */
/* @0x31a800 bl 0x31a6b0 <___Unwind_Backtrace+0x24> */
/* @0x31a804 orr r0, r0, r4 */
/* @0x31a808 cmp r0, #32768 */
/* @0x31a80c bne 0x31a818 <__gnu_unwind_execute+0xdc> */
/* @0x31a810 mov r0, #9 */
/* @0x31a814 b 0x31aab0 <__gnu_unwind_execute+0x374> */
/* @0x31a818 lsl r4, r0, #4 */
/* @0x31a81c mov r1, #0 */
/* @0x31a820 mov r0, r5 */
/* @0x31a824 mov r3, r1 */
/* @0x31a828 uxth r2, r4 */
/* @0x31a82c bl 0x31a1bc <_Unwind_VRS_Pop> */
/* @0x31a830 cmp r0, #0 */
/* @0x31a834 bne 0x31a810 <__gnu_unwind_execute+0xd4> */
/* @0x31a838 tst r4, #32768 */
/* @0x31a83c movne r7, #1 */
/* @0x31a840 b 0x31a754 <__gnu_unwind_execute+0x18> */
/* @0x31a844 cmp r3, #144 */
/* @0x31a848 bne 0x31a88c <__gnu_unwind_execute+0x150> */
/* @0x31a84c and r3, r0, #13 */
/* @0x31a850 cmp r3, #13 */
/* @0x31a854 beq 0x31a810 <__gnu_unwind_execute+0xd4> */
/* @0x31a858 mov r1, #0 */
/* @0x31a85c str r8, [sp] */
/* @0x31a860 mov r0, r5 */
/* @0x31a864 and r2, r4, #15 */
/* @0x31a868 mov r3, r1 */
/* @0x31a86c bl 0x319be4 <_Unwind_VRS_Get> */
/* @0x31a870 mov r0, r5 */
/* @0x31a874 mov r1, #0 */
/* @0x31a878 str r8, [sp] */
/* @0x31a87c mov r2, #13 */
/* @0x31a880 mov r3, r1 */
/* @0x31a884 bl 0x319c68 <_Unwind_VRS_Set> */
/* @0x31a888 b 0x31a754 <__gnu_unwind_execute+0x18> */
/* @0x31a88c cmp r3, #160 */
/* @0x31a890 bne 0x31a8b8 <__gnu_unwind_execute+0x17c> */
/* @0x31a894 mvn r2, r0 */
/* @0x31a898 and r2, r2, #7 */
/* @0x31a89c asr r2, r9, r2 */
/* @0x31a8a0 tst r0, #8 */
/* @0x31a8a4 and r2, r2, #4080 */
/* @0x31a8a8 mov r0, r5 */
/* @0x31a8ac orrne r2, r2, #16384 */
/* @0x31a8b0 mov r1, #0 */
/* @0x31a8b4 b 0x31a8e4 <__gnu_unwind_execute+0x1a8> */
/* @0x31a8b8 cmp r3, #176 */
/* @0x31a8bc bne 0x31a9a4 <__gnu_unwind_execute+0x268> */
/* @0x31a8c0 cmp r0, #177 */
/* @0x31a8c4 bne 0x31a8ec <__gnu_unwind_execute+0x1b0> */
/* @0x31a8c8 mov r0, r6 */
/* @0x31a8cc bl 0x31a6b0 <___Unwind_Backtrace+0x24> */
/* @0x31a8d0 subs r2, r0, #0 */
/* @0x31a8d4 beq 0x31a810 <__gnu_unwind_execute+0xd4> */
/* @0x31a8d8 ands r1, r2, #240 */
/* @0x31a8dc bne 0x31a810 <__gnu_unwind_execute+0xd4> */
/* @0x31a8e0 mov r0, r5 */
/* @0x31a8e4 mov r3, r1 */
/* @0x31a8e8 b 0x31aa9c <__gnu_unwind_execute+0x360> */
/* @0x31a8ec cmp r0, #178 */
/* @0x31a8f0 bne 0x31a958 <__gnu_unwind_execute+0x21c> */
/* @0x31a8f4 mov r1, #0 */
/* @0x31a8f8 mov r2, #13 */
/* @0x31a8fc mov r3, r1 */
/* @0x31a900 str r8, [sp] */
/* @0x31a904 mov r0, r5 */
/* @0x31a908 mov r4, #2 */
/* @0x31a90c bl 0x319be4 <_Unwind_VRS_Get> */
/* @0x31a910 mov r0, r6 */
/* @0x31a914 bl 0x31a6b0 <___Unwind_Backtrace+0x24> */
/* @0x31a918 ands r1, r0, #128 */
/* @0x31a91c ldr r3, [sp, #0xc] */
/* @0x31a920 and r0, r0, #127 */
/* @0x31a924 beq 0x31a940 <__gnu_unwind_execute+0x204> */
/* @0x31a928 add r0, r3, r0, lsl r4 */
/* @0x31a92c str r0, [sp, #0xc] */
/* @0x31a930 mov r0, r6 */
/* @0x31a934 add r4, r4, #7 */
/* @0x31a938 bl 0x31a6b0 <___Unwind_Backtrace+0x24> */
/* @0x31a93c b 0x31a918 <__gnu_unwind_execute+0x1dc> */
/* @0x31a940 add r3, r3, #516 */
/* @0x31a944 str r8, [sp] */
/* @0x31a948 add r0, r3, r0, lsl r4 */
/* @0x31a94c str r0, [sp, #0xc] */
/* @0x31a950 mov r0, r5 */
/* @0x31a954 b 0x31a87c <__gnu_unwind_execute+0x140> */
/* @0x31a958 cmp r0, #179 */
/* @0x31a95c bne 0x31a980 <__gnu_unwind_execute+0x244> */
/* @0x31a960 mov r0, r6 */
/* @0x31a964 bl 0x31a6b0 <___Unwind_Backtrace+0x24> */
/* @0x31a968 mov r1, #1 */
/* @0x31a96c and r3, r0, #15 */
/* @0x31a970 and r2, r0, #240 */
/* @0x31a974 add r3, r3, #1 */
/* @0x31a978 mov r0, r5 */
/* @0x31a97c b 0x31a9d0 <__gnu_unwind_execute+0x294> */
/* @0x31a980 and r3, r0, #252 */
/* @0x31a984 cmp r3, #180 */
/* @0x31a988 beq 0x31a810 <__gnu_unwind_execute+0xd4> */
/* @0x31a98c and r4, r0, #7 */
/* @0x31a990 mov r1, #1 */
/* @0x31a994 add r2, r4, #1 */
/* @0x31a998 mov r0, r5 */
/* @0x31a99c orr r2, r2, #524288 */
/* @0x31a9a0 b 0x31a8e4 <__gnu_unwind_execute+0x1a8> */
/* @0x31a9a4 cmp r3, #192 */
/* @0x31a9a8 bne 0x31aa78 <__gnu_unwind_execute+0x33c> */
/* @0x31a9ac cmp r0, #198 */
/* @0x31a9b0 bne 0x31a9d8 <__gnu_unwind_execute+0x29c> */
/* @0x31a9b4 mov r0, r6 */
/* @0x31a9b8 bl 0x31a6b0 <___Unwind_Backtrace+0x24> */
/* @0x31a9bc mov r1, #3 */
/* @0x31a9c0 and r3, r0, #15 */
/* @0x31a9c4 and r2, r0, #240 */
/* @0x31a9c8 add r3, r3, #1 */
/* @0x31a9cc mov r0, r5 */
/* @0x31a9d0 orr r2, r3, r2, lsl #12 */
/* @0x31a9d4 b 0x31a8e4 <__gnu_unwind_execute+0x1a8> */
/* @0x31a9d8 cmp r0, #199 */
/* @0x31a9dc bne 0x31aa04 <__gnu_unwind_execute+0x2c8> */
/* @0x31a9e0 mov r0, r6 */
/* @0x31a9e4 bl 0x31a6b0 <___Unwind_Backtrace+0x24> */
/* @0x31a9e8 subs r2, r0, #0 */
/* @0x31a9ec beq 0x31a810 <__gnu_unwind_execute+0xd4> */
/* @0x31a9f0 ands r3, r2, #240 */
/* @0x31a9f4 bne 0x31a810 <__gnu_unwind_execute+0xd4> */
/* @0x31a9f8 mov r0, r5 */
/* @0x31a9fc mov r1, #4 */
/* @0x31aa00 b 0x31aa9c <__gnu_unwind_execute+0x360> */
/* @0x31aa04 and r3, r0, #248 */
/* @0x31aa08 cmp r3, #192 */
/* @0x31aa0c bne 0x31aa28 <__gnu_unwind_execute+0x2ec> */
/* @0x31aa10 and r4, r0, #15 */
/* @0x31aa14 mov r1, #3 */
/* @0x31aa18 add r2, r4, #1 */
/* @0x31aa1c mov r0, r5 */
/* @0x31aa20 orr r2, r2, #655360 */
/* @0x31aa24 b 0x31a8e4 <__gnu_unwind_execute+0x1a8> */
/* @0x31aa28 cmp r0, #200 */
/* @0x31aa2c bne 0x31aa4c <__gnu_unwind_execute+0x310> */
/* @0x31aa30 mov r0, r6 */
/* @0x31aa34 bl 0x31a6b0 <___Unwind_Backtrace+0x24> */
/* @0x31aa38 and r2, r0, #240 */
/* @0x31aa3c and r0, r0, #15 */
/* @0x31aa40 add r2, r2, #16 */
/* @0x31aa44 add r3, r0, #1 */
/* @0x31aa48 b 0x31aa68 <__gnu_unwind_execute+0x32c> */
/* @0x31aa4c cmp r0, #201 */
/* @0x31aa50 bne 0x31a810 <__gnu_unwind_execute+0xd4> */
/* @0x31aa54 mov r0, r6 */
/* @0x31aa58 bl 0x31a6b0 <___Unwind_Backtrace+0x24> */
/* @0x31aa5c and r3, r0, #15 */
/* @0x31aa60 and r2, r0, #240 */
/* @0x31aa64 add r3, r3, #1 */
/* @0x31aa68 mov r0, r5 */
/* @0x31aa6c mov r1, #1 */
/* @0x31aa70 orr r2, r3, r2, lsl #12 */
/* @0x31aa74 b 0x31aa98 <__gnu_unwind_execute+0x35c> */
/* @0x31aa78 and r3, r0, #248 */
/* @0x31aa7c cmp r3, #208 */
/* @0x31aa80 bne 0x31a810 <__gnu_unwind_execute+0xd4> */
/* @0x31aa84 and r4, r0, #7 */
/* @0x31aa88 mov r1, #1 */
/* @0x31aa8c add r2, r4, #1 */
/* @0x31aa90 mov r0, r5 */
/* @0x31aa94 orr r2, r2, #524288 */
/* @0x31aa98 mov r3, #5 */
/* @0x31aa9c bl 0x31a1bc <_Unwind_VRS_Pop> */
/* @0x31aaa0 cmp r0, #0 */
/* @0x31aaa4 bne 0x31a810 <__gnu_unwind_execute+0xd4> */
/* @0x31aaa8 b 0x31a754 <__gnu_unwind_execute+0x18> */
/* @0x31aaac mov r0, #0 */
/* @0x31aab0 add sp, sp, #16 */
/* @0x31aab4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x31aab8 · __gnu_unwind_frame · size=64 · insn=16 */
/* @0x31aab8 push {r0, r1, r2, r3, r4, lr} */
/* @0x31aabc ldr r3, [r0, #0x4c] */
/* @0x31aac0 mov r0, r1 */
/* @0x31aac4 add r1, sp, #4 */
/* @0x31aac8 ldr r2, [r3, #0x4] */
/* @0x31aacc lsl r2, r2, #8 */
/* @0x31aad0 str r2, [sp, #0x4] */
/* @0x31aad4 add r2, r3, #8 */
/* @0x31aad8 str r2, [sp, #0x8] */
/* @0x31aadc mov r2, #3 */
/* @0x31aae0 strb r2, [sp, #0xc] */
/* @0x31aae4 ldrb r3, [r3, #0x7] */
/* @0x31aae8 strb r3, [sp, #0xd] */
/* @0x31aaec bl 0x31a73c <__gnu_unwind_execute> */
/* @0x31aaf0 add sp, sp, #20 */
/* @0x31aaf4 ldr pc, [sp], #4 */

/* ── FUNC 0x31aaf8 · _Unwind_GetRegionStart · size=16 · insn=4 */
/* @0x31aaf8 push {r3, lr} */
/* @0x31aafc bl 0x31a738 <___Unwind_Backtrace+0xac> */
/* @0x31ab00 ldr r0, [r0, #0x48] */
/* @0x31ab04 pop {r3, pc} */

/* ── FUNC 0x31ab08 · _Unwind_GetLanguageSpecificData · size=28 · insn=7 */
/* @0x31ab08 push {r3, lr} */
/* @0x31ab0c bl 0x31a738 <___Unwind_Backtrace+0xac> */
/* @0x31ab10 ldr r3, [r0, #0x4c] */
/* @0x31ab14 ldrb r2, [r3, #0x7] */
/* @0x31ab18 add r0, r3, r2, lsl #2 */
/* @0x31ab1c add r0, r0, #8 */
/* @0x31ab20 pop {r3, pc} */

/* ── FUNC 0x31ab24 · _Unwind_GetDataRelBase · size=8 · insn=2 */
/* @0x31ab24 push {r3, lr} */
/* @0x31ab28 bl 0xb6c88 <abort@plt> */

/* ── FUNC 0x31ab2c · _Unwind_GetTextRelBase · size=8 · insn=2 */
/* @0x31ab2c push {r3, lr} */
/* @0x31ab30 bl 0xb6c88 <abort@plt> */

/* ── FUNC 0x31ab34 · __aeabi_dmul · size=620 · insn=155 */
/* @0x31ab34 push {r4, r5, r6, lr} */
/* @0x31ab38 mov r12, #255 */
/* @0x31ab3c orr r12, r12, #1792 */
/* @0x31ab40 ands r4, r12, r1, lsr #20 */
/* @0x31ab44 andsne r5, r12, r3, lsr #20 */
/* @0x31ab48 teqne r4, r12 */
/* @0x31ab4c teqne r5, r12 */
/* @0x31ab50 bleq 0x31ad14 <__muldf3+0x1e0> */
/* @0x31ab54 add r4, r4, r5 */
/* @0x31ab58 eor r6, r1, r3 */
/* @0x31ab5c bic r1, r1, r12, lsl #21 */
/* @0x31ab60 bic r3, r3, r12, lsl #21 */
/* @0x31ab64 orrs r5, r0, r1, lsl #12 */
/* @0x31ab68 orrsne r5, r2, r3, lsl #12 */
/* @0x31ab6c orr r1, r1, #1048576 */
/* @0x31ab70 orr r3, r3, #1048576 */
/* @0x31ab74 beq 0x31abec <__muldf3+0xb8> */
/* @0x31ab78 umull r12, lr, r0, r2 */
/* @0x31ab7c mov r5, #0 */
/* @0x31ab80 umlal lr, r5, r1, r2 */
/* @0x31ab84 and r2, r6, #-2147483648 */
/* @0x31ab88 umlal lr, r5, r0, r3 */
/* @0x31ab8c mov r6, #0 */
/* @0x31ab90 umlal r5, r6, r1, r3 */
/* @0x31ab94 teq r12, #0 */
/* @0x31ab98 orrne lr, lr, #1 */
/* @0x31ab9c sub r4, r4, #255 */
/* @0x31aba0 cmp r6, #512 */
/* @0x31aba4 sbc r4, r4, #768 */
/* @0x31aba8 bhs 0x31abb8 <__muldf3+0x84> */
/* @0x31abac lsls lr, lr, #1 */
/* @0x31abb0 adcs r5, r5, r5 */
/* @0x31abb4 adc r6, r6, r6 */
/* @0x31abb8 orr r1, r2, r6, lsl #11 */
/* @0x31abbc orr r1, r1, r5, lsr #21 */
/* @0x31abc0 lsl r0, r5, #11 */
/* @0x31abc4 orr r0, r0, lr, lsr #21 */
/* @0x31abc8 lsl lr, lr, #11 */
/* @0x31abcc subs r12, r4, #253 */
/* @0x31abd0 cmphi r12, #1792 */
/* @0x31abd4 bhi 0x31ac18 <__muldf3+0xe4> */
/* @0x31abd8 cmp lr, #-2147483648 */
/* @0x31abdc lsrseq lr, r0, #1 */
/* @0x31abe0 adcs r0, r0, #0 */
/* @0x31abe4 adc r1, r1, r4, lsl #20 */
/* @0x31abe8 pop {r4, r5, r6, pc} */
/* @0x31abec and r6, r6, #-2147483648 */
/* @0x31abf0 orr r1, r6, r1 */
/* @0x31abf4 orr r0, r0, r2 */
/* @0x31abf8 eor r1, r1, r3 */
/* @0x31abfc subs r4, r4, r12, lsr #1 */
/* @0x31ac00 rsbsgt r5, r4, r12 */
/* @0x31ac04 orrgt r1, r1, r4, lsl #20 */
/* @0x31ac08 popgt {r4, r5, r6, pc} */
/* @0x31ac0c orr r1, r1, #1048576 */
/* @0x31ac10 mov lr, #0 */
/* @0x31ac14 subs r4, r4, #1 */
/* @0x31ac18 bgt 0x31ad80 <__muldf3+0x24c> */
/* @0x31ac1c cmn r4, #54 */
/* @0x31ac20 movle r0, #0 */
/* @0x31ac24 andle r1, r1, #-2147483648 */
/* @0x31ac28 pople {r4, r5, r6, pc} */
/* @0x31ac2c rsb r4, r4, #0 */
/* @0x31ac30 subs r4, r4, #32 */
/* @0x31ac34 bge 0x31ac9c <__muldf3+0x168> */
/* @0x31ac38 adds r4, r4, #12 */
/* @0x31ac3c bgt 0x31ac70 <__muldf3+0x13c> */
/* @0x31ac40 add r4, r4, #20 */
/* @0x31ac44 rsb r5, r4, #32 */
/* @0x31ac48 lsl r3, r0, r5 */
/* @0x31ac4c lsr r0, r0, r4 */
/* @0x31ac50 orr r0, r0, r1, lsl r5 */
/* @0x31ac54 and r2, r1, #-2147483648 */
/* @0x31ac58 bic r1, r1, #-2147483648 */
/* @0x31ac5c adds r0, r0, r3, lsr #31 */
/* @0x31ac60 adc r1, r2, r1, lsr r4 */
/* @0x31ac64 orrs lr, lr, r3, lsl #1 */
/* @0x31ac68 biceq r0, r0, r3, lsr #31 */
/* @0x31ac6c pop {r4, r5, r6, pc} */
/* @0x31ac70 rsb r4, r4, #12 */
/* @0x31ac74 rsb r5, r4, #32 */
/* @0x31ac78 lsl r3, r0, r4 */
/* @0x31ac7c lsr r0, r0, r5 */
/* @0x31ac80 orr r0, r0, r1, lsl r4 */
/* @0x31ac84 and r1, r1, #-2147483648 */
/* @0x31ac88 adds r0, r0, r3, lsr #31 */
/* @0x31ac8c adc r1, r1, #0 */
/* @0x31ac90 orrs lr, lr, r3, lsl #1 */
/* @0x31ac94 biceq r0, r0, r3, lsr #31 */
/* @0x31ac98 pop {r4, r5, r6, pc} */
/* @0x31ac9c rsb r5, r4, #32 */
/* @0x31aca0 orr lr, lr, r0, lsl r5 */
/* @0x31aca4 lsr r3, r0, r4 */
/* @0x31aca8 orr r3, r3, r1, lsl r5 */
/* @0x31acac lsr r0, r1, r4 */
/* @0x31acb0 and r1, r1, #-2147483648 */
/* @0x31acb4 bic r0, r0, r1, lsr r4 */
/* @0x31acb8 add r0, r0, r3, lsr #31 */
/* @0x31acbc orrs lr, lr, r3, lsl #1 */
/* @0x31acc0 biceq r0, r0, r3, lsr #31 */
/* @0x31acc4 pop {r4, r5, r6, pc} */
/* @0x31acc8 teq r4, #0 */
/* @0x31accc bne 0x31acf4 <__muldf3+0x1c0> */
/* @0x31acd0 and r6, r1, #-2147483648 */
/* @0x31acd4 lsls r0, r0, #1 */
/* @0x31acd8 adc r1, r1, r1 */
/* @0x31acdc tst r1, #1048576 */
/* @0x31ace0 subeq r4, r4, #1 */
/* @0x31ace4 beq 0x31acd4 <__muldf3+0x1a0> */
/* @0x31ace8 orr r1, r1, r6 */
/* @0x31acec teq r5, #0 */
/* @0x31acf0 bxne lr */
/* @0x31acf4 and r6, r3, #-2147483648 */
/* @0x31acf8 lsls r2, r2, #1 */
/* @0x31acfc adc r3, r3, r3 */
/* @0x31ad00 tst r3, #1048576 */
/* @0x31ad04 subeq r5, r5, #1 */
/* @0x31ad08 beq 0x31acf8 <__muldf3+0x1c4> */
/* @0x31ad0c orr r3, r3, r6 */
/* @0x31ad10 bx lr */
/* @0x31ad14 teq r4, r12 */
/* @0x31ad18 and r5, r12, r3, lsr #20 */
/* @0x31ad1c teqne r5, r12 */
/* @0x31ad20 beq 0x31ad40 <__muldf3+0x20c> */
/* @0x31ad24 orrs r6, r0, r1, lsl #1 */
/* @0x31ad28 orrsne r6, r2, r3, lsl #1 */
/* @0x31ad2c bne 0x31acc8 <__muldf3+0x194> */
/* @0x31ad30 eor r1, r1, r3 */
/* @0x31ad34 and r1, r1, #-2147483648 */
/* @0x31ad38 mov r0, #0 */
/* @0x31ad3c pop {r4, r5, r6, pc} */
/* @0x31ad40 orrs r6, r0, r1, lsl #1 */
/* @0x31ad44 moveq r0, r2 */
/* @0x31ad48 moveq r1, r3 */
/* @0x31ad4c orrsne r6, r2, r3, lsl #1 */
/* @0x31ad50 beq 0x31ad94 <__muldf3+0x260> */
/* @0x31ad54 teq r4, r12 */
/* @0x31ad58 bne 0x31ad64 <__muldf3+0x230> */
/* @0x31ad5c orrs r6, r0, r1, lsl #12 */
/* @0x31ad60 bne 0x31ad94 <__muldf3+0x260> */
/* @0x31ad64 teq r5, r12 */
/* @0x31ad68 bne 0x31ad7c <__muldf3+0x248> */
/* @0x31ad6c orrs r6, r2, r3, lsl #12 */
/* @0x31ad70 movne r0, r2 */
/* @0x31ad74 movne r1, r3 */
/* @0x31ad78 bne 0x31ad94 <__muldf3+0x260> */
/* @0x31ad7c eor r1, r1, r3 */
/* @0x31ad80 and r1, r1, #-2147483648 */
/* @0x31ad84 orr r1, r1, #2130706432 */
/* @0x31ad88 orr r1, r1, #15728640 */
/* @0x31ad8c mov r0, #0 */
/* @0x31ad90 pop {r4, r5, r6, pc} */
/* @0x31ad94 orr r1, r1, #2130706432 */
/* @0x31ad98 orr r1, r1, #16252928 */
/* @0x31ad9c pop {r4, r5, r6, pc} */

/* ── FUNC 0x31ab34 · __muldf3 · alias of the symbol above · insn=0 */

/* ── FUNC 0x31ada0 · __aeabi_ddiv · size=516 · insn=129 */
/* @0x31ada0 push {r4, r5, r6, lr} */
/* @0x31ada4 mov r12, #255 */
/* @0x31ada8 orr r12, r12, #1792 */
/* @0x31adac ands r4, r12, r1, lsr #20 */
/* @0x31adb0 andsne r5, r12, r3, lsr #20 */
/* @0x31adb4 teqne r4, r12 */
/* @0x31adb8 teqne r5, r12 */
/* @0x31adbc bleq 0x31af34 <__divdf3+0x194> */
/* @0x31adc0 sub r4, r4, r5 */
/* @0x31adc4 eor lr, r1, r3 */
/* @0x31adc8 orrs r5, r2, r3, lsl #12 */
/* @0x31adcc lsl r1, r1, #12 */
/* @0x31add0 beq 0x31af04 <__divdf3+0x164> */
/* @0x31add4 lsl r3, r3, #12 */
/* @0x31add8 mov r5, #268435456 */
/* @0x31addc orr r3, r5, r3, lsr #4 */
/* @0x31ade0 orr r3, r3, r2, lsr #24 */
/* @0x31ade4 lsl r2, r2, #8 */
/* @0x31ade8 orr r5, r5, r1, lsr #4 */
/* @0x31adec orr r5, r5, r0, lsr #24 */
/* @0x31adf0 lsl r6, r0, #8 */
/* @0x31adf4 and r1, lr, #-2147483648 */
/* @0x31adf8 cmp r5, r3 */
/* @0x31adfc cmpeq r6, r2 */
/* @0x31ae00 adc r4, r4, #253 */
/* @0x31ae04 add r4, r4, #768 */
/* @0x31ae08 bhs 0x31ae14 <__divdf3+0x74> */
/* @0x31ae0c lsrs r3, r3, #1 */
/* @0x31ae10 rrx r2, r2 */
/* @0x31ae14 subs r6, r6, r2 */
/* @0x31ae18 sbc r5, r5, r3 */
/* @0x31ae1c lsrs r3, r3, #1 */
/* @0x31ae20 rrx r2, r2 */
/* @0x31ae24 mov r0, #1048576 */
/* @0x31ae28 mov r12, #524288 */
/* @0x31ae2c subs lr, r6, r2 */
/* @0x31ae30 sbcs lr, r5, r3 */
/* @0x31ae34 subhs r6, r6, r2 */
/* @0x31ae38 movhs r5, lr */
/* @0x31ae3c orrhs r0, r0, r12 */
/* @0x31ae40 lsrs r3, r3, #1 */
/* @0x31ae44 rrx r2, r2 */
/* @0x31ae48 subs lr, r6, r2 */
/* @0x31ae4c sbcs lr, r5, r3 */
/* @0x31ae50 subhs r6, r6, r2 */
/* @0x31ae54 movhs r5, lr */
/* @0x31ae58 orrhs r0, r0, r12, lsr #1 */
/* @0x31ae5c lsrs r3, r3, #1 */
/* @0x31ae60 rrx r2, r2 */
/* @0x31ae64 subs lr, r6, r2 */
/* @0x31ae68 sbcs lr, r5, r3 */
/* @0x31ae6c subhs r6, r6, r2 */
/* @0x31ae70 movhs r5, lr */
/* @0x31ae74 orrhs r0, r0, r12, lsr #2 */
/* @0x31ae78 lsrs r3, r3, #1 */
/* @0x31ae7c rrx r2, r2 */
/* @0x31ae80 subs lr, r6, r2 */
/* @0x31ae84 sbcs lr, r5, r3 */
/* @0x31ae88 subhs r6, r6, r2 */
/* @0x31ae8c movhs r5, lr */
/* @0x31ae90 orrhs r0, r0, r12, lsr #3 */
/* @0x31ae94 orrs lr, r5, r6 */
/* @0x31ae98 beq 0x31aed4 <__divdf3+0x134> */
/* @0x31ae9c lsl r5, r5, #4 */
/* @0x31aea0 orr r5, r5, r6, lsr #28 */
/* @0x31aea4 lsl r6, r6, #4 */
/* @0x31aea8 lsl r3, r3, #3 */
/* @0x31aeac orr r3, r3, r2, lsr #29 */
/* @0x31aeb0 lsl r2, r2, #3 */
/* @0x31aeb4 lsrs r12, r12, #4 */
/* @0x31aeb8 bne 0x31ae2c <__divdf3+0x8c> */
/* @0x31aebc tst r1, #1048576 */
/* @0x31aec0 bne 0x31aee0 <__divdf3+0x140> */
/* @0x31aec4 orr r1, r1, r0 */
/* @0x31aec8 mov r0, #0 */
/* @0x31aecc mov r12, #-2147483648 */
/* @0x31aed0 b 0x31ae2c <__divdf3+0x8c> */
/* @0x31aed4 tst r1, #1048576 */
/* @0x31aed8 orreq r1, r1, r0 */
/* @0x31aedc moveq r0, #0 */
/* @0x31aee0 subs r12, r4, #253 */
/* @0x31aee4 cmphi r12, #1792 */
/* @0x31aee8 bhi 0x31ac18 <__muldf3+0xe4> */
/* @0x31aeec subs r12, r5, r3 */
/* @0x31aef0 subseq r12, r6, r2 */
/* @0x31aef4 lsrseq r12, r0, #1 */
/* @0x31aef8 adcs r0, r0, #0 */
/* @0x31aefc adc r1, r1, r4, lsl #20 */
/* @0x31af00 pop {r4, r5, r6, pc} */
/* @0x31af04 and lr, lr, #-2147483648 */
/* @0x31af08 orr r1, lr, r1, lsr #12 */
/* @0x31af0c adds r4, r4, r12, lsr #1 */
/* @0x31af10 rsbsgt r5, r4, r12 */
/* @0x31af14 orrgt r1, r1, r4, lsl #20 */
/* @0x31af18 popgt {r4, r5, r6, pc} */
/* @0x31af1c orr r1, r1, #1048576 */
/* @0x31af20 mov lr, #0 */
/* @0x31af24 subs r4, r4, #1 */
/* @0x31af28 b 0x31ac18 <__muldf3+0xe4> */
/* @0x31af2c orr lr, r5, r6 */
/* @0x31af30 b 0x31ac18 <__muldf3+0xe4> */
/* @0x31af34 and r5, r12, r3, lsr #20 */
/* @0x31af38 teq r4, r12 */
/* @0x31af3c teqeq r5, r12 */
/* @0x31af40 beq 0x31ad94 <__muldf3+0x260> */
/* @0x31af44 teq r4, r12 */
/* @0x31af48 bne 0x31af68 <__divdf3+0x1c8> */
/* @0x31af4c orrs r4, r0, r1, lsl #12 */
/* @0x31af50 bne 0x31ad94 <__muldf3+0x260> */
/* @0x31af54 teq r5, r12 */
/* @0x31af58 bne 0x31ad7c <__muldf3+0x248> */
/* @0x31af5c mov r0, r2 */
/* @0x31af60 mov r1, r3 */
/* @0x31af64 b 0x31ad94 <__muldf3+0x260> */
/* @0x31af68 teq r5, r12 */
/* @0x31af6c bne 0x31af84 <__divdf3+0x1e4> */
/* @0x31af70 orrs r5, r2, r3, lsl #12 */
/* @0x31af74 beq 0x31ad30 <__muldf3+0x1fc> */
/* @0x31af78 mov r0, r2 */
/* @0x31af7c mov r1, r3 */
/* @0x31af80 b 0x31ad94 <__muldf3+0x260> */
/* @0x31af84 orrs r6, r0, r1, lsl #1 */
/* @0x31af88 orrsne r6, r2, r3, lsl #1 */
/* @0x31af8c bne 0x31acc8 <__muldf3+0x194> */
/* @0x31af90 orrs r4, r0, r1, lsl #1 */
/* @0x31af94 bne 0x31ad7c <__muldf3+0x248> */
/* @0x31af98 orrs r5, r2, r3, lsl #1 */
/* @0x31af9c bne 0x31ad30 <__muldf3+0x1fc> */
/* @0x31afa0 b 0x31ad94 <__muldf3+0x260> */

/* ── FUNC 0x31ada0 · __divdf3 · alias of the symbol above · insn=0 */

/* ── FUNC 0x31afa4 · __gedf2 · size=152 · insn=2 */
/* @0x31afa4 mvn r12, #0 */
/* @0x31afa8 b 0x31afb8 <__nedf2+0x4> */
