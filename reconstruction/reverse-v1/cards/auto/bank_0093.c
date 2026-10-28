/* libyoyo.so 覆盖卡组 0093
 * 函数 0x159d44..0x15e538，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x159d44 · RaiseOSPauseEvent · size=24 · insn=6 */
/* @0x159d44 ldr r3, [pc, #0xc] */
/* @0x159d48 mov r2, #1 */
/* @0x159d4c ldr r3, [pc, r3] */
/* @0x159d50 strb r2, [r3] */
/* @0x159d54 bx lr */
/* @0x159d58 mlaeq r9, r12, lr, r5 */

/* ── FUNC 0x159d5c · RaiseOSPauseEvent_Metro(bool) · size=128 · insn=32 */
/* @0x159d5c push {r4, lr} */
/* @0x159d60 cmp r0, #0 */
/* @0x159d64 ldr r4, [pc, #0x5c] */
/* @0x159d68 add r4, pc, r4 */
/* @0x159d6c bne 0x159db4 <_Z23RaiseOSPauseEvent_Metrob+0x58> */
/* @0x159d70 ldr r1, [pc, #0x54] */
/* @0x159d74 ldr r2, [pc, #0x54] */
/* @0x159d78 ldr r3, [pc, #0x54] */
/* @0x159d7c ldr r1, [r4, r1] */
/* @0x159d80 strb r0, [r1] */
/* @0x159d84 ldr r2, [r4, r2] */
/* @0x159d88 strb r0, [r2] */
/* @0x159d8c ldr r3, [r4, r3] */
/* @0x159d90 ldrb r3, [r3] */
/* @0x159d94 cmp r3, #0 */
/* @0x159d98 popne {r4, pc} */
/* @0x159d9c bl 0x29cb74 <_Z19DebuggerIsConnectedv> */
/* @0x159da0 cmp r0, #0 */
/* @0x159da4 ldreq r3, [pc, #0x2c] */
/* @0x159da8 ldreq r3, [r4, r3] */
/* @0x159dac strbeq r0, [r3] */
/* @0x159db0 pop {r4, pc} */
/* @0x159db4 ldr r3, [pc, #0x14] */
/* @0x159db8 mov r2, #1 */
/* @0x159dbc ldr r3, [r4, r3] */
/* @0x159dc0 strb r2, [r3] */
/* @0x159dc4 pop {r4, pc} */
/* @0x159dc8 eoreq r7, r9, r8, ror #29 */
/* @0x159dcc .word 0xffffdef4 */
/* @0x159dd0 .word 0xffffdf98 */
/* @0x159dd4 .word 0xffffdf9c */
/* @0x159dd8 .word 0xffffdfa0 */

/* ── FUNC 0x159ddc · UpdateOSEvents() · size=176 · insn=44 */
/* @0x159ddc push {r4, r5, r6, lr} */
/* @0x159de0 ldr r4, [pc, #0x8c] */
/* @0x159de4 ldr r3, [pc, #0x8c] */
/* @0x159de8 add r4, pc, r4 */
/* @0x159dec ldr r6, [r4, r3] */
/* @0x159df0 ldrb r5, [r6] */
/* @0x159df4 cmp r5, #0 */
/* @0x159df8 bne 0x159e38 <_Z14UpdateOSEventsv+0x5c> */
/* @0x159dfc ldr r3, [pc, #0x78] */
/* @0x159e00 ldr r6, [r4, r3] */
/* @0x159e04 ldrb r3, [r6] */
/* @0x159e08 cmp r3, #0 */
/* @0x159e0c popeq {r4, r5, r6, pc} */
/* @0x159e10 ldr r3, [pc, #0x68] */
/* @0x159e14 ldr r1, [pc, #0x68] */
/* @0x159e18 ldr r3, [r4, r3] */
/* @0x159e1c add r1, pc, r1 */
/* @0x159e20 ldr r0, [r3] */
/* @0x159e24 ldr r3, [r0] */
/* @0x159e28 ldr r3, [r3, #0xc] */
/* @0x159e2c blx r3 */
/* @0x159e30 strb r5, [r6] */
/* @0x159e34 pop {r4, r5, r6, pc} */
/* @0x159e38 ldr r3, [pc, #0x40] */
/* @0x159e3c ldr r1, [pc, #0x44] */
/* @0x159e40 ldr r3, [r4, r3] */
/* @0x159e44 add r1, pc, r1 */
/* @0x159e48 ldr r0, [r3] */
/* @0x159e4c ldr r3, [r0] */
/* @0x159e50 ldr r3, [r3, #0xc] */
/* @0x159e54 blx r3 */
/* @0x159e58 ldr r3, [pc, #0x1c] */
/* @0x159e5c mov r2, #1 */
/* @0x159e60 mov r1, #0 */
/* @0x159e64 ldr r3, [r4, r3] */
/* @0x159e68 strb r1, [r6] */
/* @0x159e6c strb r2, [r3] */
/* @0x159e70 pop {r4, r5, r6, pc} */
/* @0x159e74 eoreq r7, r9, r8, ror #28 */
/* @0x159e78 .word 0xffffdf98 */
/* @0x159e7c .word 0xffffdef4 */
/* @0x159e80 .word 0xffffbac4 */
/* @0x159e84 andseq r12, lr, r4, ror #25 */
/* @0x159e88 andseq r12, lr, r12, lsl #25 */

/* ── FUNC 0x159e8c · GetRawMouseX(int) · size=36 · insn=9 */
/* @0x159e8c cmp r0, #10 */
/* @0x159e90 bhi 0x159ea4 <_Z12GetRawMouseXi+0x18> */
/* @0x159e94 ldr r3, [pc, #0x10] */
/* @0x159e98 ldr r3, [pc, r3] */
/* @0x159e9c ldr r0, [r3, r0, lsl #2] */
/* @0x159ea0 bx lr */
/* @0x159ea4 mov r0, #0 */
/* @0x159ea8 bx lr */
/* @0x159eac eoreq r5, r9, r4, lsl #26 */

/* ── FUNC 0x159eb0 · F_YoYo_MouseXRaw(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x159eb0 push {r4, lr} */
/* @0x159eb4 mov r3, #0 */
/* @0x159eb8 mov r1, r3 */
/* @0x159ebc str r3, [r0, #0xc] */
/* @0x159ec0 mov r4, r0 */
/* @0x159ec4 ldr r0, [sp, #0x8] */
/* @0x159ec8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x159ecc bl 0x159e8c <_Z12GetRawMouseXi> */
/* @0x159ed0 vmov s15, r0 */
/* @0x159ed4 vcvt.f64.s32 d7, s15 */
/* @0x159ed8 vmov r0, r1, d7 */
/* @0x159edc vmov r2, s14 */
/* @0x159ee0 mov r3, r1 */
/* @0x159ee4 stm r4, {r2, r3} */
/* @0x159ee8 pop {r4, pc} */

/* ── FUNC 0x159eec · GetRawMouseY(int) · size=36 · insn=9 */
/* @0x159eec cmp r0, #10 */
/* @0x159ef0 bhi 0x159f04 <_Z12GetRawMouseYi+0x18> */
/* @0x159ef4 ldr r3, [pc, #0x10] */
/* @0x159ef8 ldr r3, [pc, r3] */
/* @0x159efc ldr r0, [r3, r0, lsl #2] */
/* @0x159f00 bx lr */
/* @0x159f04 mov r0, #0 */
/* @0x159f08 bx lr */
/* @0x159f0c eoreq r5, r9, r0, lsr #25 */

/* ── FUNC 0x159f10 · F_YoYo_MouseYRaw(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x159f10 push {r4, lr} */
/* @0x159f14 mov r3, #0 */
/* @0x159f18 mov r1, r3 */
/* @0x159f1c str r3, [r0, #0xc] */
/* @0x159f20 mov r4, r0 */
/* @0x159f24 ldr r0, [sp, #0x8] */
/* @0x159f28 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x159f2c bl 0x159eec <_Z12GetRawMouseYi> */
/* @0x159f30 vmov s15, r0 */
/* @0x159f34 vcvt.f64.s32 d7, s15 */
/* @0x159f38 vmov r0, r1, d7 */
/* @0x159f3c vmov r2, s14 */
/* @0x159f40 mov r3, r1 */
/* @0x159f44 stm r4, {r2, r3} */
/* @0x159f48 pop {r4, pc} */

/* ── FUNC 0x159f4c · ConvertRawToGUI(float, float, float&, float&) · size=80 · insn=20 */
/* @0x159f4c vmov s15, r1 */
/* @0x159f50 ldr r12, [pc, #0x40] */
/* @0x159f54 vmov s13, r0 */
/* @0x159f58 ldr r12, [pc, r12] */
/* @0x159f5c vldr s14, [r12, #16] */
/* @0x159f60 vmul.f32 s14, s15, s14 */
/* @0x159f64 vldr s11, [r12] */
/* @0x159f68 vldr s12, [r12, #48] */
/* @0x159f6c vmla.f32 s14, s13, s11 */
/* @0x159f70 vadd.f32 s14, s14, s12 */
/* @0x159f74 vstr s14, [r2] */
/* @0x159f78 vldr s14, [r12, #20] */
/* @0x159f7c vmul.f32 s15, s15, s14 */
/* @0x159f80 vldr s12, [r12, #4] */
/* @0x159f84 vldr s14, [r12, #52] */
/* @0x159f88 vmla.f32 s15, s13, s12 */
/* @0x159f8c vadd.f32 s15, s15, s14 */
/* @0x159f90 vstr s15, [r3] */
/* @0x159f94 bx lr */
/* @0x159f98 eoreq r5, r9, r8, asr #24 */

/* ── FUNC 0x159f9c · GMLCallback(int, int, RValue*) · size=272 · insn=68 */
/* @0x159f9c ldr r3, [pc, #0xf8] */
/* @0x159fa0 push {r4, r5, r6, r7, r8, lr} */
/* @0x159fa4 add r3, pc, r3 */
/* @0x159fa8 ldr r5, [pc, #0xf0] */
/* @0x159fac sub sp, sp, #8 */
/* @0x159fb0 mov r8, r0 */
/* @0x159fb4 ldr r0, [r3] */
/* @0x159fb8 add r5, pc, r5 */
/* @0x159fbc mov r6, r1 */
/* @0x159fc0 mov r4, r2 */
/* @0x159fc4 bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0x159fc8 ldr r3, [r5] */
/* @0x159fcc cmn r3, #1 */
/* @0x159fd0 movne r0, r3 */
/* @0x159fd4 beq 0x15a08c <_Z11GMLCallbackiiP6RValue+0xf0> */
/* @0x159fd8 vmov s15, r8 */
/* @0x159fdc mov r5, #0 */
/* @0x159fe0 mov r1, #1 */
/* @0x159fe4 str r5, [sp] */
/* @0x159fe8 vcvt.f64.s32 d7, s15 */
/* @0x159fec ldr r7, [pc, #0xb0] */
/* @0x159ff0 add r7, pc, r7 */
/* @0x159ff4 vmov r2, r3, d7 */
/* @0x159ff8 bl 0x2053f0 <_Z14DsQueueEnqueueiiz> */
/* @0x159ffc ldr r0, [r7] */
/* @0x15a000 vmov s15, r6 */
/* @0x15a004 str r5, [sp] */
/* @0x15a008 mov r1, #1 */
/* @0x15a00c vcvt.f64.s32 d7, s15 */
/* @0x15a010 vmov r2, r3, d7 */
/* @0x15a014 bl 0x2053f0 <_Z14DsQueueEnqueueiiz> */
/* @0x15a018 cmp r6, r5 */
/* @0x15a01c bgt 0x15a048 <_Z11GMLCallbackiiP6RValue+0xac> */
/* @0x15a020 b 0x15a078 <_Z11GMLCallbackiiP6RValue+0xdc> */
/* @0x15a024 mov r3, r1 */
/* @0x15a028 mov r2, r12 */
/* @0x15a02c str lr, [sp] */
/* @0x15a030 add r5, r5, #1 */
/* @0x15a034 mov r1, #1 */
/* @0x15a038 add r4, r4, #16 */
/* @0x15a03c bl 0x2053f0 <_Z14DsQueueEnqueueiiz> */
/* @0x15a040 cmp r5, r6 */
/* @0x15a044 beq 0x15a078 <_Z11GMLCallbackiiP6RValue+0xdc> */
/* @0x15a048 ldr r3, [r4, #0xc] */
/* @0x15a04c mov lr, #0 */
/* @0x15a050 ldr r0, [r7] */
/* @0x15a054 bic r3, r3, #-16777216 */
/* @0x15a058 ldr r12, [r4] */
/* @0x15a05c cmp r3, #1 */
/* @0x15a060 ldr r1, [r4, #0x4] */
/* @0x15a064 bne 0x15a024 <_Z11GMLCallbackiiP6RValue+0x88> */
/* @0x15a068 cmp r12, lr */
/* @0x15a06c ldrne lr, [r12] */
/* @0x15a070 moveq lr, r12 */
/* @0x15a074 b 0x15a024 <_Z11GMLCallbackiiP6RValue+0x88> */
/* @0x15a078 ldr r3, [pc, #0x28] */
/* @0x15a07c ldr r0, [pc, r3] */
/* @0x15a080 add sp, sp, #8 */
/* @0x15a084 pop {r4, r5, r6, r7, r8, lr} */
/* @0x15a088 b 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0x15a08c bl 0x2053bc <_Z13DsQueueCreatev> */
/* @0x15a090 mov r3, r0 */
/* @0x15a094 str r3, [r5] */
/* @0x15a098 b 0x159fd8 <_Z11GMLCallbackiiP6RValue+0x3c> */
/* @0x15a09c eorseq r10, r2, r4, asr #21 */
/* @0x15a0a0 eoreq r8, r9, r0, lsr #7 */
/* @0x15a0a4 eoreq r8, r9, r8, ror #6 */
/* @0x15a0a8 eorseq r10, r2, r12, ror #19 */

/* ── FUNC 0x15a0ac · UpdateYoYoFunctions() · size=20 · insn=5 */
/* @0x15a0ac push {r3, lr} */
/* @0x15a0b0 bl 0x15e29c <_Z20UpdateYoYoFunctionsMv> */
/* @0x15a0b4 bl 0x1598c4 <_Z22UpdateAchievementCachev> */
/* @0x15a0b8 pop {r3, lr} */
/* @0x15a0bc b 0x159ddc <_Z14UpdateOSEventsv> */

/* ── FUNC 0x15a0c0 · QuitYoYoFunctions() · size=16 · insn=4 */
/* @0x15a0c0 push {r3, lr} */
/* @0x15a0c4 bl 0x159640 <_Z21FlushAchievementCachev> */
/* @0x15a0c8 pop {r3, lr} */
/* @0x15a0cc b 0x15e2a0 <_Z18QuitYoYoFunctionsMv> */

/* ── FUNC 0x15a0d0 · InitYoYoFunctions() · size=12328 · insn=3082 */
/* @0x15a0d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x15a0d4 mov r0, #8 */
/* @0x15a0d8 sub sp, sp, #28 */
/* @0x15a0dc ldr r6, [pc, #0xff8] */
/* @0x15a0e0 bl 0x27c524 <_Znwj> */
/* @0x15a0e4 ldr r1, [pc, #0xff4] */
/* @0x15a0e8 add r6, pc, r6 */
/* @0x15a0ec mov r4, #0 */
/* @0x15a0f0 add r1, pc, r1 */
/* @0x15a0f4 mov r10, r6 */
/* @0x15a0f8 mov r5, r0 */
/* @0x15a0fc bl 0x27e070 <_ZN5MutexC2EPKc> */
/* @0x15a100 ldr r2, [pc, #0xfdc] */
/* @0x15a104 mov r0, #8 */
/* @0x15a108 ldr r3, [pc, #0xfd8] */
/* @0x15a10c ldr r2, [r6, r2] */
/* @0x15a110 str r5, [r2] */
/* @0x15a114 ldr r3, [r6, r3] */
/* @0x15a118 str r4, [r3] */
/* @0x15a11c bl 0x27c524 <_Znwj> */
/* @0x15a120 ldr r1, [pc, #0xfc4] */
/* @0x15a124 add r1, pc, r1 */
/* @0x15a128 mov r5, r0 */
/* @0x15a12c bl 0x27e070 <_ZN5MutexC2EPKc> */
/* @0x15a130 ldr r3, [pc, #0xfb8] */
/* @0x15a134 mov r1, r4 */
/* @0x15a138 mov r2, r4 */
/* @0x15a13c mov r0, #1 */
/* @0x15a140 add r3, pc, r3 */
/* @0x15a144 str r5, [r3] */
/* @0x15a148 bl 0x159c88 <_Z11UpdateCache10eCacheTypePKcj> */
/* @0x15a14c bl 0x1534d4 <_Z16InitIAPFunctionsv> */
/* @0x15a150 bl 0x15e2a8 <_Z18InitYoYoFunctionsMv> */
/* @0x15a154 ldr r1, [pc, #0xf98] */
/* @0x15a158 ldr r0, [pc, #0xf98] */
/* @0x15a15c mov r3, r4 */
/* @0x15a160 mov r2, #5 */
/* @0x15a164 ldr r8, [r6, r1] */
/* @0x15a168 add r0, pc, r0 */
/* @0x15a16c mov r1, r8 */
/* @0x15a170 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a174 ldr r1, [pc, #0xf80] */
/* @0x15a178 ldr r0, [pc, #0xf80] */
/* @0x15a17c mov r3, r4 */
/* @0x15a180 mov r2, #1 */
/* @0x15a184 ldr r7, [r6, r1] */
/* @0x15a188 add r0, pc, r0 */
/* @0x15a18c mov r1, r7 */
/* @0x15a190 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a194 ldr r1, [pc, #0xf68] */
/* @0x15a198 ldr r0, [pc, #0xf68] */
/* @0x15a19c mov r3, r4 */
/* @0x15a1a0 mov r2, #1 */
/* @0x15a1a4 ldr r6, [r6, r1] */
/* @0x15a1a8 add r0, pc, r0 */
/* @0x15a1ac mov r1, r6 */
/* @0x15a1b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a1b4 ldr r1, [pc, #0xf50] */
/* @0x15a1b8 ldr r0, [pc, #0xf50] */
/* @0x15a1bc mov r3, r4 */
/* @0x15a1c0 mov r2, #1 */
/* @0x15a1c4 ldr r5, [r10, r1] */
/* @0x15a1c8 add r0, pc, r0 */
/* @0x15a1cc mov r1, r5 */
/* @0x15a1d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a1d4 ldr r0, [pc, #0xf38] */
/* @0x15a1d8 mov r1, r8 */
/* @0x15a1dc mov r3, r4 */
/* @0x15a1e0 add r0, pc, r0 */
/* @0x15a1e4 mov r2, #5 */
/* @0x15a1e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a1ec ldr r0, [pc, #0xf24] */
/* @0x15a1f0 mov r1, r7 */
/* @0x15a1f4 mov r3, r4 */
/* @0x15a1f8 add r0, pc, r0 */
/* @0x15a1fc mov r2, #1 */
/* @0x15a200 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a204 ldr r0, [pc, #0xf10] */
/* @0x15a208 mov r1, r6 */
/* @0x15a20c mov r3, r4 */
/* @0x15a210 add r0, pc, r0 */
/* @0x15a214 mov r2, #1 */
/* @0x15a218 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a21c ldr r0, [pc, #0xefc] */
/* @0x15a220 mov r1, r5 */
/* @0x15a224 mov r3, r4 */
/* @0x15a228 add r0, pc, r0 */
/* @0x15a22c mov r2, #1 */
/* @0x15a230 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a234 ldr r1, [pc, #0xee8] */
/* @0x15a238 ldr r0, [pc, #0xee8] */
/* @0x15a23c mov r2, r4 */
/* @0x15a240 mov r3, r4 */
/* @0x15a244 ldr r6, [r10, r1] */
/* @0x15a248 add r0, pc, r0 */
/* @0x15a24c mov r1, r6 */
/* @0x15a250 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a254 ldr r1, [pc, #0xed0] */
/* @0x15a258 ldr r0, [pc, #0xed0] */
/* @0x15a25c mov r2, r4 */
/* @0x15a260 mov r3, r4 */
/* @0x15a264 ldr r5, [r10, r1] */
/* @0x15a268 add r0, pc, r0 */
/* @0x15a26c mov r1, r5 */
/* @0x15a270 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a274 ldr r1, [pc, #0xeb8] */
/* @0x15a278 ldr r0, [pc, #0xeb8] */
/* @0x15a27c mov r3, r4 */
/* @0x15a280 mov r2, #2 */
/* @0x15a284 ldr r7, [r10, r1] */
/* @0x15a288 add r0, pc, r0 */
/* @0x15a28c mov r1, r7 */
/* @0x15a290 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a294 ldr r1, [pc, #0xea0] */
/* @0x15a298 ldr r0, [pc, #0xea0] */
/* @0x15a29c mov r3, r4 */
/* @0x15a2a0 mov r2, #2 */
/* @0x15a2a4 ldr r8, [r10, r1] */
/* @0x15a2a8 add r0, pc, r0 */
/* @0x15a2ac mov r1, r8 */
/* @0x15a2b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a2b4 ldr r1, [pc, #0xe88] */
/* @0x15a2b8 ldr r0, [pc, #0xe88] */
/* @0x15a2bc mov r2, r4 */
/* @0x15a2c0 mov r3, r4 */
/* @0x15a2c4 ldr r9, [r10, r1] */
/* @0x15a2c8 add r0, pc, r0 */
/* @0x15a2cc mov r1, r9 */
/* @0x15a2d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a2d4 ldr r0, [pc, #0xe70] */
/* @0x15a2d8 mov r1, r9 */
/* @0x15a2dc mov r2, r4 */
/* @0x15a2e0 mov r3, r4 */
/* @0x15a2e4 add r0, pc, r0 */
/* @0x15a2e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a2ec ldr r0, [pc, #0xe5c] */
/* @0x15a2f0 mov r1, r8 */
/* @0x15a2f4 mov r3, r4 */
/* @0x15a2f8 add r0, pc, r0 */
/* @0x15a2fc mov r2, #2 */
/* @0x15a300 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a304 ldr r0, [pc, #0xe48] */
/* @0x15a308 mov r1, r7 */
/* @0x15a30c mov r3, r4 */
/* @0x15a310 add r0, pc, r0 */
/* @0x15a314 mov r2, #2 */
/* @0x15a318 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a31c ldr r1, [pc, #0xe34] */
/* @0x15a320 ldr r0, [pc, #0xe34] */
/* @0x15a324 mov r3, r4 */
/* @0x15a328 mov r2, #2 */
/* @0x15a32c ldr r1, [r10, r1] */
/* @0x15a330 add r0, pc, r0 */
/* @0x15a334 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a338 ldr r1, [pc, #0xe20] */
/* @0x15a33c ldr r0, [pc, #0xe20] */
/* @0x15a340 mov r3, r4 */
/* @0x15a344 mov r2, #1 */
/* @0x15a348 ldr r1, [r10, r1] */
/* @0x15a34c add r0, pc, r0 */
/* @0x15a350 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a354 ldr r0, [pc, #0xe0c] */
/* @0x15a358 mov r1, r6 */
/* @0x15a35c mov r2, r4 */
/* @0x15a360 mov r3, r4 */
/* @0x15a364 add r0, pc, r0 */
/* @0x15a368 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a36c ldr r0, [pc, #0xdf8] */
/* @0x15a370 mov r1, r5 */
/* @0x15a374 mov r2, r4 */
/* @0x15a378 mov r3, r4 */
/* @0x15a37c add r0, pc, r0 */
/* @0x15a380 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a384 ldr r1, [pc, #0xde4] */
/* @0x15a388 ldr r0, [pc, #0xde4] */
/* @0x15a38c mov r2, r4 */
/* @0x15a390 mov r3, r4 */
/* @0x15a394 ldr r1, [r10, r1] */
/* @0x15a398 add r0, pc, r0 */
/* @0x15a39c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a3a0 ldr r1, [pc, #0xdd0] */
/* @0x15a3a4 ldr r0, [pc, #0xdd0] */
/* @0x15a3a8 mov r2, r4 */
/* @0x15a3ac mov r3, r4 */
/* @0x15a3b0 ldr r1, [r10, r1] */
/* @0x15a3b4 add r0, pc, r0 */
/* @0x15a3b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a3bc ldr r1, [pc, #0xdbc] */
/* @0x15a3c0 ldr r0, [pc, #0xdbc] */
/* @0x15a3c4 mov r3, r4 */
/* @0x15a3c8 mov r2, #2 */
/* @0x15a3cc ldr r1, [r10, r1] */
/* @0x15a3d0 add r0, pc, r0 */
/* @0x15a3d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a3d8 ldr r1, [pc, #0xda8] */
/* @0x15a3dc ldr r0, [pc, #0xda8] */
/* @0x15a3e0 mov r2, r4 */
/* @0x15a3e4 mov r3, r4 */
/* @0x15a3e8 ldr r1, [r10, r1] */
/* @0x15a3ec add r0, pc, r0 */
/* @0x15a3f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a3f4 ldr r1, [pc, #0xd94] */
/* @0x15a3f8 ldr r0, [pc, #0xd94] */
/* @0x15a3fc mov r2, r4 */
/* @0x15a400 mov r3, r4 */
/* @0x15a404 ldr r1, [r10, r1] */
/* @0x15a408 add r0, pc, r0 */
/* @0x15a40c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a410 ldr r1, [pc, #0xd80] */
/* @0x15a414 ldr r0, [pc, #0xd80] */
/* @0x15a418 mov r3, r4 */
/* @0x15a41c mov r2, #4 */
/* @0x15a420 ldr r1, [r10, r1] */
/* @0x15a424 add r0, pc, r0 */
/* @0x15a428 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a42c ldr r1, [pc, #0xd6c] */
/* @0x15a430 ldr r0, [pc, #0xd6c] */
/* @0x15a434 mov r3, r4 */
/* @0x15a438 mov r2, #1 */
/* @0x15a43c ldr r1, [r10, r1] */
/* @0x15a440 add r0, pc, r0 */
/* @0x15a444 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a448 ldr r1, [pc, #0xd58] */
/* @0x15a44c ldr r0, [pc, #0xd58] */
/* @0x15a450 mov r3, r4 */
/* @0x15a454 mov r2, #1 */
/* @0x15a458 ldr r1, [r10, r1] */
/* @0x15a45c add r0, pc, r0 */
/* @0x15a460 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a464 ldr r1, [pc, #0xd44] */
/* @0x15a468 ldr r0, [pc, #0xd44] */
/* @0x15a46c mov r2, r4 */
/* @0x15a470 mov r3, r4 */
/* @0x15a474 ldr r1, [r10, r1] */
/* @0x15a478 add r0, pc, r0 */
/* @0x15a47c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a480 ldr r1, [pc, #0xd30] */
/* @0x15a484 ldr r0, [pc, #0xd30] */
/* @0x15a488 mov r3, r4 */
/* @0x15a48c mov r2, #5 */
/* @0x15a490 ldr r1, [r10, r1] */
/* @0x15a494 add r0, pc, r0 */
/* @0x15a498 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a49c ldr r1, [pc, #0xd1c] */
/* @0x15a4a0 ldr r0, [pc, #0xd1c] */
/* @0x15a4a4 mov r2, r4 */
/* @0x15a4a8 mov r3, r4 */
/* @0x15a4ac ldr r1, [r10, r1] */
/* @0x15a4b0 add r0, pc, r0 */
/* @0x15a4b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a4b8 ldr r1, [pc, #0xd08] */
/* @0x15a4bc ldr r0, [pc, #0xd08] */
/* @0x15a4c0 mov r3, r4 */
/* @0x15a4c4 mov r2, #3 */
/* @0x15a4c8 ldr r1, [r10, r1] */
/* @0x15a4cc add r0, pc, r0 */
/* @0x15a4d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a4d4 ldr r1, [pc, #0xcf4] */
/* @0x15a4d8 ldr r0, [pc, #0xcf4] */
/* @0x15a4dc mov r2, #2 */
/* @0x15a4e0 mov r3, #1 */
/* @0x15a4e4 ldr r1, [r10, r1] */
/* @0x15a4e8 add r0, pc, r0 */
/* @0x15a4ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a4f0 ldr r1, [pc, #0xce0] */
/* @0x15a4f4 ldr r0, [pc, #0xce0] */
/* @0x15a4f8 mov r2, #2 */
/* @0x15a4fc mov r3, #1 */
/* @0x15a500 ldr r1, [r10, r1] */
/* @0x15a504 add r0, pc, r0 */
/* @0x15a508 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a50c ldr r1, [pc, #0xccc] */
/* @0x15a510 ldr r0, [pc, #0xccc] */
/* @0x15a514 mov r2, r4 */
/* @0x15a518 mov r3, #1 */
/* @0x15a51c ldr r1, [r10, r1] */
/* @0x15a520 add r0, pc, r0 */
/* @0x15a524 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a528 ldr r1, [pc, #0xcb8] */
/* @0x15a52c ldr r0, [pc, #0xcb8] */
/* @0x15a530 mov r3, r4 */
/* @0x15a534 mov r2, #1 */
/* @0x15a538 ldr r7, [r10, r1] */
/* @0x15a53c add r0, pc, r0 */
/* @0x15a540 mov r1, r7 */
/* @0x15a544 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a548 ldr r1, [pc, #0xca0] */
/* @0x15a54c ldr r0, [pc, #0xca0] */
/* @0x15a550 mov r3, r4 */
/* @0x15a554 mov r2, #2 */
/* @0x15a558 ldr r6, [r10, r1] */
/* @0x15a55c add r0, pc, r0 */
/* @0x15a560 mov r1, r6 */
/* @0x15a564 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a568 ldr r1, [pc, #0xc88] */
/* @0x15a56c ldr r0, [pc, #0xc88] */
/* @0x15a570 mov r3, r4 */
/* @0x15a574 mov r2, #3 */
/* @0x15a578 ldr r5, [r10, r1] */
/* @0x15a57c add r0, pc, r0 */
/* @0x15a580 mov r1, r5 */
/* @0x15a584 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a588 ldr r0, [pc, #0xc70] */
/* @0x15a58c mov r1, r7 */
/* @0x15a590 mov r3, r4 */
/* @0x15a594 add r0, pc, r0 */
/* @0x15a598 mov r2, #1 */
/* @0x15a59c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a5a0 ldr r0, [pc, #0xc5c] */
/* @0x15a5a4 mov r1, r6 */
/* @0x15a5a8 mov r3, r4 */
/* @0x15a5ac add r0, pc, r0 */
/* @0x15a5b0 mov r2, #2 */
/* @0x15a5b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a5b8 ldr r0, [pc, #0xc48] */
/* @0x15a5bc mov r1, r5 */
/* @0x15a5c0 mov r3, r4 */
/* @0x15a5c4 add r0, pc, r0 */
/* @0x15a5c8 mov r2, #3 */
/* @0x15a5cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a5d0 ldr r1, [pc, #0xc34] */
/* @0x15a5d4 ldr r0, [pc, #0xc34] */
/* @0x15a5d8 mov r3, r4 */
/* @0x15a5dc mov r2, #1 */
/* @0x15a5e0 ldr r1, [r10, r1] */
/* @0x15a5e4 add r0, pc, r0 */
/* @0x15a5e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a5ec ldr r1, [pc, #0xc20] */
/* @0x15a5f0 ldr r0, [pc, #0xc20] */
/* @0x15a5f4 mov r3, r4 */
/* @0x15a5f8 mov r2, #5 */
/* @0x15a5fc ldr r1, [r10, r1] */
/* @0x15a600 add r0, pc, r0 */
/* @0x15a604 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a608 ldr r1, [pc, #0xc0c] */
/* @0x15a60c ldr r0, [pc, #0xc0c] */
/* @0x15a610 mov r2, r4 */
/* @0x15a614 mov r3, r4 */
/* @0x15a618 ldr r6, [r10, r1] */
/* @0x15a61c add r0, pc, r0 */
/* @0x15a620 mov r1, r6 */
/* @0x15a624 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a628 ldr r1, [pc, #0xbf4] */
/* @0x15a62c ldr r0, [pc, #0xbf4] */
/* @0x15a630 mov r3, r4 */
/* @0x15a634 mov r2, #4 */
/* @0x15a638 ldr r5, [r10, r1] */
/* @0x15a63c add r0, pc, r0 */
/* @0x15a640 mov r1, r5 */
/* @0x15a644 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a648 ldr r1, [pc, #0xbdc] */
/* @0x15a64c ldr r0, [pc, #0xbdc] */
/* @0x15a650 mov r3, r4 */
/* @0x15a654 mov r2, #3 */
/* @0x15a658 ldr r1, [r10, r1] */
/* @0x15a65c add r0, pc, r0 */
/* @0x15a660 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a664 ldr r0, [pc, #0xbc8] */
/* @0x15a668 mov r1, r6 */
/* @0x15a66c mov r3, r4 */
/* @0x15a670 add r0, pc, r0 */
/* @0x15a674 mov r2, #1 */
/* @0x15a678 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a67c ldr r1, [pc, #0xbb4] */
/* @0x15a680 ldr r0, [pc, #0xbb4] */
/* @0x15a684 mov r3, r4 */
/* @0x15a688 mov r2, #1 */
/* @0x15a68c ldr r1, [r10, r1] */
/* @0x15a690 add r0, pc, r0 */
/* @0x15a694 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a698 ldr r1, [pc, #0xba0] */
/* @0x15a69c ldr r0, [pc, #0xba0] */
/* @0x15a6a0 mov r3, r4 */
/* @0x15a6a4 mov r2, #1 */
/* @0x15a6a8 ldr r1, [r10, r1] */
/* @0x15a6ac add r0, pc, r0 */
/* @0x15a6b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a6b4 ldr r1, [pc, #0xb8c] */
/* @0x15a6b8 ldr r0, [pc, #0xb8c] */
/* @0x15a6bc mov r3, r4 */
/* @0x15a6c0 mov r2, #1 */
/* @0x15a6c4 ldr r1, [r10, r1] */
/* @0x15a6c8 add r0, pc, r0 */
/* @0x15a6cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a6d0 ldr r1, [pc, #0xb78] */
/* @0x15a6d4 ldr r0, [pc, #0xb78] */
/* @0x15a6d8 mov r3, r4 */
/* @0x15a6dc mov r2, #1 */
/* @0x15a6e0 ldr r1, [r10, r1] */
/* @0x15a6e4 add r0, pc, r0 */
/* @0x15a6e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a6ec ldr r1, [pc, #0xb64] */
/* @0x15a6f0 ldr r0, [pc, #0xb64] */
/* @0x15a6f4 mov r3, r4 */
/* @0x15a6f8 mov r2, #3 */
/* @0x15a6fc ldr r1, [r10, r1] */
/* @0x15a700 add r0, pc, r0 */
/* @0x15a704 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a708 ldr r1, [pc, #0xb50] */
/* @0x15a70c ldr r0, [pc, #0xb50] */
/* @0x15a710 mov r2, r4 */
/* @0x15a714 mov r3, r4 */
/* @0x15a718 ldr r1, [r10, r1] */
/* @0x15a71c add r0, pc, r0 */
/* @0x15a720 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a724 ldr r1, [pc, #0xb3c] */
/* @0x15a728 ldr r0, [pc, #0xb3c] */
/* @0x15a72c mov r2, r4 */
/* @0x15a730 mov r3, r4 */
/* @0x15a734 ldr r1, [r10, r1] */
/* @0x15a738 add r0, pc, r0 */
/* @0x15a73c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a740 ldr r1, [pc, #0xb28] */
/* @0x15a744 ldr r0, [pc, #0xb28] */
/* @0x15a748 mov r3, r4 */
/* @0x15a74c mov r2, #1 */
/* @0x15a750 ldr r1, [r10, r1] */
/* @0x15a754 add r0, pc, r0 */
/* @0x15a758 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a75c ldr r1, [pc, #0xb14] */
/* @0x15a760 ldr r0, [pc, #0xb14] */
/* @0x15a764 mov r3, r4 */
/* @0x15a768 mov r2, #1 */
/* @0x15a76c ldr r1, [r10, r1] */
/* @0x15a770 add r0, pc, r0 */
/* @0x15a774 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a778 ldr r1, [pc, #0xb00] */
/* @0x15a77c ldr r0, [pc, #0xb00] */
/* @0x15a780 mov r3, r4 */
/* @0x15a784 mov r2, #1 */
/* @0x15a788 ldr r1, [r10, r1] */
/* @0x15a78c add r0, pc, r0 */
/* @0x15a790 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a794 ldr r1, [pc, #0xaec] */
/* @0x15a798 ldr r0, [pc, #0xaec] */
/* @0x15a79c mov r3, r4 */
/* @0x15a7a0 mov r2, #2 */
/* @0x15a7a4 ldr r1, [r10, r1] */
/* @0x15a7a8 add r0, pc, r0 */
/* @0x15a7ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a7b0 ldr r1, [pc, #0xad8] */
/* @0x15a7b4 ldr r0, [pc, #0xad8] */
/* @0x15a7b8 mov r3, r4 */
/* @0x15a7bc mov r2, #1 */
/* @0x15a7c0 ldr r1, [r10, r1] */
/* @0x15a7c4 add r0, pc, r0 */
/* @0x15a7c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a7cc ldr r1, [pc, #0xac4] */
/* @0x15a7d0 ldr r0, [pc, #0xac4] */
/* @0x15a7d4 mov r3, r4 */
/* @0x15a7d8 mov r2, #6 */
/* @0x15a7dc ldr r1, [r10, r1] */
/* @0x15a7e0 add r0, pc, r0 */
/* @0x15a7e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a7e8 ldr r1, [pc, #0xab0] */
/* @0x15a7ec ldr r0, [pc, #0xab0] */
/* @0x15a7f0 mov r3, r4 */
/* @0x15a7f4 mov r2, #8 */
/* @0x15a7f8 ldr r1, [r10, r1] */
/* @0x15a7fc add r0, pc, r0 */
/* @0x15a800 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a804 ldr r1, [pc, #0xa9c] */
/* @0x15a808 ldr r0, [pc, #0xa9c] */
/* @0x15a80c mov r3, r4 */
/* @0x15a810 mov r2, #4 */
/* @0x15a814 ldr r1, [r10, r1] */
/* @0x15a818 add r0, pc, r0 */
/* @0x15a81c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a820 ldr r1, [pc, #0xa88] */
/* @0x15a824 ldr r0, [pc, #0xa88] */
/* @0x15a828 mov r3, r4 */
/* @0x15a82c mov r2, #5 */
/* @0x15a830 ldr r1, [r10, r1] */
/* @0x15a834 add r0, pc, r0 */
/* @0x15a838 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a83c ldr r1, [pc, #0xa74] */
/* @0x15a840 ldr r0, [pc, #0xa74] */
/* @0x15a844 mov r3, r4 */
/* @0x15a848 mov r2, #1 */
/* @0x15a84c ldr r1, [r10, r1] */
/* @0x15a850 add r0, pc, r0 */
/* @0x15a854 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a858 ldr r1, [pc, #0xa60] */
/* @0x15a85c ldr r0, [pc, #0xa60] */
/* @0x15a860 mov r3, r4 */
/* @0x15a864 mov r2, #1 */
/* @0x15a868 ldr r1, [r10, r1] */
/* @0x15a86c add r0, pc, r0 */
/* @0x15a870 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a874 ldr r1, [pc, #0xa4c] */
/* @0x15a878 ldr r0, [pc, #0xa4c] */
/* @0x15a87c mov r3, r4 */
/* @0x15a880 mov r2, #2 */
/* @0x15a884 ldr r1, [r10, r1] */
/* @0x15a888 add r0, pc, r0 */
/* @0x15a88c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a890 ldr r0, [pc, #0xa38] */
/* @0x15a894 mov r1, r5 */
/* @0x15a898 mov r3, r4 */
/* @0x15a89c add r0, pc, r0 */
/* @0x15a8a0 mov r2, #4 */
/* @0x15a8a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a8a8 ldr r1, [pc, #0xa24] */
/* @0x15a8ac ldr r0, [pc, #0xa24] */
/* @0x15a8b0 mov r2, r4 */
/* @0x15a8b4 mov r3, r4 */
/* @0x15a8b8 ldr r6, [r10, r1] */
/* @0x15a8bc add r0, pc, r0 */
/* @0x15a8c0 mov r1, r6 */
/* @0x15a8c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a8c8 ldr r1, [pc, #0xa0c] */
/* @0x15a8cc ldr r0, [pc, #0xa0c] */
/* @0x15a8d0 mov r2, r4 */
/* @0x15a8d4 mov r3, r4 */
/* @0x15a8d8 ldr r1, [r10, r1] */
/* @0x15a8dc add r0, pc, r0 */
/* @0x15a8e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a8e4 ldr r1, [pc, #0x9f8] */
/* @0x15a8e8 ldr r0, [pc, #0x9f8] */
/* @0x15a8ec mov r2, r4 */
/* @0x15a8f0 mov r3, r4 */
/* @0x15a8f4 ldr r1, [r10, r1] */
/* @0x15a8f8 add r0, pc, r0 */
/* @0x15a8fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a900 ldr r1, [pc, #0x9e4] */
/* @0x15a904 ldr r0, [pc, #0x9e4] */
/* @0x15a908 mov r2, r4 */
/* @0x15a90c mov r3, r4 */
/* @0x15a910 ldr r1, [r10, r1] */
/* @0x15a914 add r0, pc, r0 */
/* @0x15a918 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a91c ldr r1, [pc, #0x9d0] */
/* @0x15a920 ldr r0, [pc, #0x9d0] */
/* @0x15a924 mov r2, r4 */
/* @0x15a928 mov r3, r4 */
/* @0x15a92c ldr r5, [r10, r1] */
/* @0x15a930 add r0, pc, r0 */
/* @0x15a934 mov r1, r5 */
/* @0x15a938 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a93c ldr r1, [pc, #0x9b8] */
/* @0x15a940 ldr r0, [pc, #0x9b8] */
/* @0x15a944 mov r2, r4 */
/* @0x15a948 mov r3, r4 */
/* @0x15a94c ldr r1, [r10, r1] */
/* @0x15a950 add r0, pc, r0 */
/* @0x15a954 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a958 ldr r1, [pc, #0x9a4] */
/* @0x15a95c ldr r0, [pc, #0x9a4] */
/* @0x15a960 mov r3, r4 */
/* @0x15a964 mov r2, #1 */
/* @0x15a968 ldr r1, [r10, r1] */
/* @0x15a96c add r0, pc, r0 */
/* @0x15a970 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a974 ldr r0, [pc, #0x990] */
/* @0x15a978 mov r1, r6 */
/* @0x15a97c mov r2, r4 */
/* @0x15a980 mov r3, r4 */
/* @0x15a984 add r0, pc, r0 */
/* @0x15a988 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a98c ldr r0, [pc, #0x97c] */
/* @0x15a990 mov r1, r5 */
/* @0x15a994 mov r2, r4 */
/* @0x15a998 mov r3, r4 */
/* @0x15a99c add r0, pc, r0 */
/* @0x15a9a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a9a4 ldr r1, [pc, #0x968] */
/* @0x15a9a8 ldr r0, [pc, #0x968] */
/* @0x15a9ac mov r2, r4 */
/* @0x15a9b0 mov r3, r4 */
/* @0x15a9b4 ldr r1, [r10, r1] */
/* @0x15a9b8 add r0, pc, r0 */
/* @0x15a9bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a9c0 ldr r1, [pc, #0x954] */
/* @0x15a9c4 ldr r0, [pc, #0x954] */
/* @0x15a9c8 mov r2, r4 */
/* @0x15a9cc mov r3, r4 */
/* @0x15a9d0 ldr r1, [r10, r1] */
/* @0x15a9d4 add r0, pc, r0 */
/* @0x15a9d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a9dc ldr r1, [pc, #0x940] */
/* @0x15a9e0 ldr r0, [pc, #0x940] */
/* @0x15a9e4 mov r2, r4 */
/* @0x15a9e8 mov r3, r4 */
/* @0x15a9ec ldr r1, [r10, r1] */
/* @0x15a9f0 add r0, pc, r0 */
/* @0x15a9f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15a9f8 ldr r1, [pc, #0x92c] */
/* @0x15a9fc ldr r0, [pc, #0x92c] */
/* @0x15aa00 mov r3, r4 */
/* @0x15aa04 mov r2, #1 */
/* @0x15aa08 ldr r1, [r10, r1] */
/* @0x15aa0c add r0, pc, r0 */
/* @0x15aa10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15aa14 ldr r1, [pc, #0x918] */
/* @0x15aa18 ldr r0, [pc, #0x918] */
/* @0x15aa1c mov r3, r4 */
/* @0x15aa20 mov r2, #1 */
/* @0x15aa24 ldr r1, [r10, r1] */
/* @0x15aa28 add r0, pc, r0 */
/* @0x15aa2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15aa30 ldr r1, [pc, #0x904] */
/* @0x15aa34 ldr r0, [pc, #0x904] */
/* @0x15aa38 mov r2, r4 */
/* @0x15aa3c mov r3, r4 */
/* @0x15aa40 ldr r1, [r10, r1] */
/* @0x15aa44 add r0, pc, r0 */
/* @0x15aa48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15aa4c ldr r1, [pc, #0x8f0] */
/* @0x15aa50 ldr r0, [pc, #0x8f0] */
/* @0x15aa54 mov r2, r4 */
/* @0x15aa58 mov r3, r4 */
/* @0x15aa5c ldr r1, [r10, r1] */
/* @0x15aa60 add r0, pc, r0 */
/* @0x15aa64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15aa68 ldr r1, [pc, #0x8dc] */
/* @0x15aa6c ldr r0, [pc, #0x8dc] */
/* @0x15aa70 mov r2, r4 */
/* @0x15aa74 mov r3, r4 */
/* @0x15aa78 ldr r1, [r10, r1] */
/* @0x15aa7c add r0, pc, r0 */
/* @0x15aa80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15aa84 ldr r1, [pc, #0x8c8] */
/* @0x15aa88 ldr r0, [pc, #0x8c8] */
/* @0x15aa8c mov r3, r4 */
/* @0x15aa90 mov r2, #2 */
/* @0x15aa94 ldr r1, [r10, r1] */
/* @0x15aa98 add r0, pc, r0 */
/* @0x15aa9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15aaa0 ldr r1, [pc, #0x8b4] */
/* @0x15aaa4 ldr r0, [pc, #0x8b4] */
/* @0x15aaa8 mov r2, r4 */
/* @0x15aaac mov r3, r4 */
/* @0x15aab0 ldr r1, [r10, r1] */
/* @0x15aab4 add r0, pc, r0 */
/* @0x15aab8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15aabc ldr r1, [pc, #0x8a0] */
/* @0x15aac0 ldr r0, [pc, #0x8a0] */
/* @0x15aac4 mov r2, r4 */
/* @0x15aac8 mov r3, r4 */
/* @0x15aacc ldr r1, [r10, r1] */
/* @0x15aad0 add r0, pc, r0 */
/* @0x15aad4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15aad8 ldr r1, [pc, #0x88c] */
/* @0x15aadc ldr r0, [pc, #0x88c] */
/* @0x15aae0 mov r3, r4 */
/* @0x15aae4 mov r2, #2 */
/* @0x15aae8 ldr r1, [r10, r1] */
/* @0x15aaec add r0, pc, r0 */
/* @0x15aaf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15aaf4 ldr r1, [pc, #0x878] */
/* @0x15aaf8 ldr r0, [pc, #0x878] */
/* @0x15aafc mov r2, r4 */
/* @0x15ab00 mov r3, r4 */
/* @0x15ab04 ldr r11, [r10, r1] */
/* @0x15ab08 add r0, pc, r0 */
/* @0x15ab0c mov r1, r11 */
/* @0x15ab10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ab14 ldr r1, [pc, #0x860] */
/* @0x15ab18 ldr r0, [pc, #0x860] */
/* @0x15ab1c mov r3, r4 */
/* @0x15ab20 mov r2, #2 */
/* @0x15ab24 ldr r1, [r10, r1] */
/* @0x15ab28 add r0, pc, r0 */
/* @0x15ab2c str r1, [sp, #0x4] */
/* @0x15ab30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ab34 ldr r1, [pc, #0x848] */
/* @0x15ab38 mov r3, r4 */
/* @0x15ab3c ldr r0, [pc, #0x844] */
/* @0x15ab40 mov r2, #3 */
/* @0x15ab44 ldr r9, [r10, r1] */
/* @0x15ab48 add r0, pc, r0 */
/* @0x15ab4c mov r1, r9 */
/* @0x15ab50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ab54 ldr r1, [pc, #0x830] */
/* @0x15ab58 ldr r0, [pc, #0x830] */
/* @0x15ab5c mov r3, r4 */
/* @0x15ab60 mov r2, #3 */
/* @0x15ab64 ldr r8, [r10, r1] */
/* @0x15ab68 add r0, pc, r0 */
/* @0x15ab6c mov r1, r8 */
/* @0x15ab70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ab74 ldr r1, [pc, #0x818] */
/* @0x15ab78 ldr r0, [pc, #0x818] */
/* @0x15ab7c mov r3, r4 */
/* @0x15ab80 mov r2, #1 */
/* @0x15ab84 ldr r7, [r10, r1] */
/* @0x15ab88 add r0, pc, r0 */
/* @0x15ab8c mov r1, r7 */
/* @0x15ab90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ab94 ldr r1, [pc, #0x800] */
/* @0x15ab98 ldr r0, [pc, #0x800] */
/* @0x15ab9c mov r3, r4 */
/* @0x15aba0 mov r2, #3 */
/* @0x15aba4 ldr r1, [r10, r1] */
/* @0x15aba8 add r0, pc, r0 */
/* @0x15abac str r1, [sp, #0x8] */
/* @0x15abb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15abb4 ldr r1, [pc, #0x7e8] */
/* @0x15abb8 mov r3, r4 */
/* @0x15abbc ldr r0, [pc, #0x7e4] */
/* @0x15abc0 mov r2, #1 */
/* @0x15abc4 ldr r1, [r10, r1] */
/* @0x15abc8 add r0, pc, r0 */
/* @0x15abcc str r1, [sp, #0xc] */
/* @0x15abd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15abd4 ldr r1, [pc, #0x7d0] */
/* @0x15abd8 mov r2, r4 */
/* @0x15abdc ldr r0, [pc, #0x7cc] */
/* @0x15abe0 mov r3, r4 */
/* @0x15abe4 ldr r1, [r10, r1] */
/* @0x15abe8 add r0, pc, r0 */
/* @0x15abec str r1, [sp, #0x10] */
/* @0x15abf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15abf4 ldr r1, [pc, #0x7b8] */
/* @0x15abf8 mov r2, r4 */
/* @0x15abfc ldr r0, [pc, #0x7b4] */
/* @0x15ac00 mov r3, r4 */
/* @0x15ac04 ldr r6, [r10, r1] */
/* @0x15ac08 add r0, pc, r0 */
/* @0x15ac0c mov r1, r6 */
/* @0x15ac10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ac14 ldr r1, [pc, #0x7a0] */
/* @0x15ac18 ldr r0, [pc, #0x7a0] */
/* @0x15ac1c mov r3, r4 */
/* @0x15ac20 mov r2, #2 */
/* @0x15ac24 ldr r5, [r10, r1] */
/* @0x15ac28 add r0, pc, r0 */
/* @0x15ac2c mov r1, r5 */
/* @0x15ac30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ac34 ldr r0, [pc, #0x788] */
/* @0x15ac38 mov r1, r11 */
/* @0x15ac3c mov r2, r4 */
/* @0x15ac40 mov r3, r4 */
/* @0x15ac44 add r0, pc, r0 */
/* @0x15ac48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ac4c ldr r0, [pc, #0x774] */
/* @0x15ac50 ldr r1, [sp, #0x4] */
/* @0x15ac54 mov r3, r4 */
/* @0x15ac58 add r0, pc, r0 */
/* @0x15ac5c mov r2, #2 */
/* @0x15ac60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ac64 ldr r0, [pc, #0x760] */
/* @0x15ac68 mov r1, r9 */
/* @0x15ac6c mov r3, r4 */
/* @0x15ac70 add r0, pc, r0 */
/* @0x15ac74 mov r2, #3 */
/* @0x15ac78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ac7c ldr r0, [pc, #0x74c] */
/* @0x15ac80 mov r1, r8 */
/* @0x15ac84 mov r3, r4 */
/* @0x15ac88 add r0, pc, r0 */
/* @0x15ac8c mov r2, #3 */
/* @0x15ac90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ac94 ldr r0, [pc, #0x738] */
/* @0x15ac98 mov r1, r7 */
/* @0x15ac9c mov r3, r4 */
/* @0x15aca0 add r0, pc, r0 */
/* @0x15aca4 mov r2, #1 */
/* @0x15aca8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15acac ldr r0, [pc, #0x724] */
/* @0x15acb0 ldr r1, [sp, #0x8] */
/* @0x15acb4 mov r3, r4 */
/* @0x15acb8 add r0, pc, r0 */
/* @0x15acbc mov r2, #3 */
/* @0x15acc0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15acc4 ldr r0, [pc, #0x710] */
/* @0x15acc8 ldr r1, [sp, #0xc] */
/* @0x15accc mov r3, r4 */
/* @0x15acd0 add r0, pc, r0 */
/* @0x15acd4 mov r2, #1 */
/* @0x15acd8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15acdc ldr r0, [pc, #0x6fc] */
/* @0x15ace0 ldr r1, [sp, #0x10] */
/* @0x15ace4 mov r2, r4 */
/* @0x15ace8 mov r3, r4 */
/* @0x15acec add r0, pc, r0 */
/* @0x15acf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15acf4 ldr r0, [pc, #0x6e8] */
/* @0x15acf8 mov r1, r6 */
/* @0x15acfc mov r2, r4 */
/* @0x15ad00 mov r3, r4 */
/* @0x15ad04 add r0, pc, r0 */
/* @0x15ad08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ad0c ldr r0, [pc, #0x6d4] */
/* @0x15ad10 mov r1, r5 */
/* @0x15ad14 mov r3, r4 */
/* @0x15ad18 add r0, pc, r0 */
/* @0x15ad1c mov r2, #2 */
/* @0x15ad20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ad24 ldr r1, [pc, #0x6c0] */
/* @0x15ad28 ldr r0, [pc, #0x6c0] */
/* @0x15ad2c mov r3, r4 */
/* @0x15ad30 mov r2, #2 */
/* @0x15ad34 ldr r11, [r10, r1] */
/* @0x15ad38 add r0, pc, r0 */
/* @0x15ad3c mov r1, r11 */
/* @0x15ad40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ad44 ldr r1, [pc, #0x6a8] */
/* @0x15ad48 ldr r0, [pc, #0x6a8] */
/* @0x15ad4c mov r3, r4 */
/* @0x15ad50 mov r2, #2 */
/* @0x15ad54 ldr r1, [r10, r1] */
/* @0x15ad58 add r0, pc, r0 */
/* @0x15ad5c str r1, [sp, #0x4] */
/* @0x15ad60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ad64 ldr r1, [pc, #0x690] */
/* @0x15ad68 mov r3, r4 */
/* @0x15ad6c ldr r0, [pc, #0x68c] */
/* @0x15ad70 mov r2, #2 */
/* @0x15ad74 ldr r9, [r10, r1] */
/* @0x15ad78 add r0, pc, r0 */
/* @0x15ad7c mov r1, r9 */
/* @0x15ad80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ad84 ldr r1, [pc, #0x678] */
/* @0x15ad88 ldr r0, [pc, #0x678] */
/* @0x15ad8c mov r3, r4 */
/* @0x15ad90 mov r2, #1 */
/* @0x15ad94 ldr r8, [r10, r1] */
/* @0x15ad98 add r0, pc, r0 */
/* @0x15ad9c mov r1, r8 */
/* @0x15ada0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ada4 ldr r1, [pc, #0x660] */
/* @0x15ada8 ldr r0, [pc, #0x660] */
/* @0x15adac mov r3, r4 */
/* @0x15adb0 mov r2, #1 */
/* @0x15adb4 ldr r1, [r10, r1] */
/* @0x15adb8 add r0, pc, r0 */
/* @0x15adbc str r1, [sp, #0x8] */
/* @0x15adc0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15adc4 ldr r1, [pc, #0x648] */
/* @0x15adc8 mov r3, r4 */
/* @0x15adcc ldr r0, [pc, #0x644] */
/* @0x15add0 mov r2, #1 */
/* @0x15add4 ldr r1, [r10, r1] */
/* @0x15add8 add r0, pc, r0 */
/* @0x15addc str r1, [sp, #0xc] */
/* @0x15ade0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ade4 ldr r1, [pc, #0x630] */
/* @0x15ade8 mov r3, r4 */
/* @0x15adec ldr r0, [pc, #0x62c] */
/* @0x15adf0 mov r2, #1 */
/* @0x15adf4 ldr r1, [r10, r1] */
/* @0x15adf8 add r0, pc, r0 */
/* @0x15adfc str r1, [sp, #0x10] */
/* @0x15ae00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ae04 ldr r1, [pc, #0x618] */
/* @0x15ae08 mov r2, r4 */
/* @0x15ae0c ldr r0, [pc, #0x614] */
/* @0x15ae10 mov r3, r4 */
/* @0x15ae14 ldr r1, [r10, r1] */
/* @0x15ae18 add r0, pc, r0 */
/* @0x15ae1c str r1, [sp, #0x14] */
/* @0x15ae20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ae24 ldr r1, [pc, #0x600] */
/* @0x15ae28 mov r2, r4 */
/* @0x15ae2c ldr r0, [pc, #0x5fc] */
/* @0x15ae30 mov r3, r4 */
/* @0x15ae34 ldr r7, [r10, r1] */
/* @0x15ae38 add r0, pc, r0 */
/* @0x15ae3c mov r1, r7 */
/* @0x15ae40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ae44 ldr r1, [pc, #0x5e8] */
/* @0x15ae48 ldr r0, [pc, #0x5e8] */
/* @0x15ae4c mov r2, r4 */
/* @0x15ae50 mov r3, r4 */
/* @0x15ae54 ldr r6, [r10, r1] */
/* @0x15ae58 add r0, pc, r0 */
/* @0x15ae5c mov r1, r6 */
/* @0x15ae60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ae64 ldr r1, [pc, #0x5d0] */
/* @0x15ae68 ldr r0, [pc, #0x5d0] */
/* @0x15ae6c mov r2, r4 */
/* @0x15ae70 mov r3, r4 */
/* @0x15ae74 ldr r5, [r10, r1] */
/* @0x15ae78 add r0, pc, r0 */
/* @0x15ae7c mov r1, r5 */
/* @0x15ae80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ae84 ldr r0, [pc, #0x5b8] */
/* @0x15ae88 mov r1, r11 */
/* @0x15ae8c mov r3, r4 */
/* @0x15ae90 add r0, pc, r0 */
/* @0x15ae94 mov r2, #2 */
/* @0x15ae98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ae9c ldr r0, [pc, #0x5a4] */
/* @0x15aea0 ldr r1, [sp, #0x4] */
/* @0x15aea4 mov r3, r4 */
/* @0x15aea8 add r0, pc, r0 */
/* @0x15aeac mov r2, #2 */
/* @0x15aeb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15aeb4 ldr r0, [pc, #0x590] */
/* @0x15aeb8 mov r1, r9 */
/* @0x15aebc mov r3, r4 */
/* @0x15aec0 add r0, pc, r0 */
/* @0x15aec4 mov r2, #2 */
/* @0x15aec8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15aecc ldr r0, [pc, #0x57c] */
/* @0x15aed0 mov r1, r8 */
/* @0x15aed4 mov r3, r4 */
/* @0x15aed8 add r0, pc, r0 */
/* @0x15aedc mov r2, #1 */
/* @0x15aee0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15aee4 ldr r0, [pc, #0x568] */
/* @0x15aee8 ldr r1, [sp, #0x8] */
/* @0x15aeec mov r3, r4 */
/* @0x15aef0 add r0, pc, r0 */
/* @0x15aef4 mov r2, #1 */
/* @0x15aef8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15aefc ldr r0, [pc, #0x554] */
/* @0x15af00 ldr r1, [sp, #0xc] */
/* @0x15af04 mov r3, r4 */
/* @0x15af08 add r0, pc, r0 */
/* @0x15af0c mov r2, #1 */
/* @0x15af10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15af14 ldr r0, [pc, #0x540] */
/* @0x15af18 ldr r1, [sp, #0x10] */
/* @0x15af1c mov r3, r4 */
/* @0x15af20 add r0, pc, r0 */
/* @0x15af24 mov r2, #1 */
/* @0x15af28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15af2c ldr r1, [pc, #0x52c] */
/* @0x15af30 ldr r0, [pc, #0x52c] */
/* @0x15af34 mov r3, r4 */
/* @0x15af38 mov r2, #1 */
/* @0x15af3c ldr r1, [r10, r1] */
/* @0x15af40 add r0, pc, r0 */
/* @0x15af44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15af48 ldr r1, [pc, #0x518] */
/* @0x15af4c ldr r0, [pc, #0x518] */
/* @0x15af50 mov r3, r4 */
/* @0x15af54 mov r2, #1 */
/* @0x15af58 ldr r1, [r10, r1] */
/* @0x15af5c add r0, pc, r0 */
/* @0x15af60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15af64 ldr r0, [pc, #0x504] */
/* @0x15af68 ldr r1, [sp, #0x14] */
/* @0x15af6c mov r2, r4 */
/* @0x15af70 mov r3, r4 */
/* @0x15af74 add r0, pc, r0 */
/* @0x15af78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15af7c ldr r0, [pc, #0x4f0] */
/* @0x15af80 mov r1, r7 */
/* @0x15af84 mov r2, r4 */
/* @0x15af88 mov r3, r4 */
/* @0x15af8c add r0, pc, r0 */
/* @0x15af90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15af94 ldr r0, [pc, #0x4dc] */
/* @0x15af98 mov r1, r6 */
/* @0x15af9c mov r2, r4 */
/* @0x15afa0 mov r3, r4 */
/* @0x15afa4 add r0, pc, r0 */
/* @0x15afa8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15afac ldr r0, [pc, #0x4c8] */
/* @0x15afb0 mov r1, r5 */
/* @0x15afb4 mov r2, r4 */
/* @0x15afb8 mov r3, r4 */
/* @0x15afbc add r0, pc, r0 */
/* @0x15afc0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15afc4 ldr r1, [pc, #0x4b4] */
/* @0x15afc8 ldr r0, [pc, #0x4b4] */
/* @0x15afcc mov r2, r4 */
/* @0x15afd0 mov r3, r4 */
/* @0x15afd4 ldr r1, [r10, r1] */
/* @0x15afd8 add r0, pc, r0 */
/* @0x15afdc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15afe0 ldr r1, [pc, #0x4a0] */
/* @0x15afe4 ldr r0, [pc, #0x4a0] */
/* @0x15afe8 mov r3, r4 */
/* @0x15afec mov r2, #2 */
/* @0x15aff0 ldr r1, [r10, r1] */
/* @0x15aff4 add r0, pc, r0 */
/* @0x15aff8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15affc ldr r1, [pc, #0x48c] */
/* @0x15b000 ldr r0, [pc, #0x48c] */
/* @0x15b004 mov r2, r4 */
/* @0x15b008 mov r3, r4 */
/* @0x15b00c ldr r1, [r10, r1] */
/* @0x15b010 add r0, pc, r0 */
/* @0x15b014 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b018 ldr r1, [pc, #0x478] */
/* @0x15b01c ldr r0, [pc, #0x478] */
/* @0x15b020 mov r3, r4 */
/* @0x15b024 mov r2, #4 */
/* @0x15b028 ldr r1, [r10, r1] */
/* @0x15b02c add r0, pc, r0 */
/* @0x15b030 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b034 ldr r1, [pc, #0x464] */
/* @0x15b038 ldr r0, [pc, #0x464] */
/* @0x15b03c mov r3, r4 */
/* @0x15b040 mov r2, #3 */
/* @0x15b044 ldr r1, [r10, r1] */
/* @0x15b048 add r0, pc, r0 */
/* @0x15b04c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b050 ldr r1, [pc, #0x450] */
/* @0x15b054 ldr r0, [pc, #0x450] */
/* @0x15b058 mov r2, r4 */
/* @0x15b05c mov r3, r4 */
/* @0x15b060 ldr r1, [r10, r1] */
/* @0x15b064 add r0, pc, r0 */
/* @0x15b068 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b06c ldr r1, [pc, #0x43c] */
/* @0x15b070 ldr r0, [pc, #0x43c] */
/* @0x15b074 mov r2, r4 */
/* @0x15b078 mov r3, r4 */
/* @0x15b07c ldr r1, [r10, r1] */
/* @0x15b080 add r0, pc, r0 */
/* @0x15b084 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b088 ldr r1, [pc, #0x428] */
/* @0x15b08c ldr r0, [pc, #0x428] */
/* @0x15b090 mov r2, r4 */
/* @0x15b094 mov r3, r4 */
/* @0x15b098 ldr r1, [r10, r1] */
/* @0x15b09c add r0, pc, r0 */
/* @0x15b0a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b0a4 ldr r1, [pc, #0x414] */
/* @0x15b0a8 ldr r0, [pc, #0x414] */
/* @0x15b0ac mov r3, r4 */
/* @0x15b0b0 mov r2, #1 */
/* @0x15b0b4 ldr r1, [r10, r1] */
/* @0x15b0b8 add r0, pc, r0 */
/* @0x15b0bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b0c0 ldr r1, [pc, #0x400] */
/* @0x15b0c4 ldr r0, [pc, #0x400] */
/* @0x15b0c8 mov r3, r4 */
/* @0x15b0cc mov r2, #7 */
/* @0x15b0d0 ldr r1, [r10, r1] */
/* @0x15b0d4 add r0, pc, r0 */
/* @0x15b0d8 b 0x15b814 <_Z17InitYoYoFunctionsv+0x1744> */
/* @0x15b0dc eoreq r7, r9, r8, ror #22 */
/* @0x15b0e0 andseq r12, lr, r4, lsr r10 */
/* @0x15b0e4 .word 0xffffdf84 */
/* @0x15b0e8 .word 0xffffdf74 */
/* @0x15b0ec andseq r12, lr, r8, lsl r10 */
/* @0x15b0f0 eorseq r10, r2, r8, lsr #18 */
/* @0x15b0f4 .word 0xffffdfa4 */
/* @0x15b0f8 andseq r12, lr, r8, ror #19 */
/* @0x15b0fc .word 0xffffdfa8 */
/* @0x15b100 ldrsbeq r12, [lr], -r12 */
/* @0x15b104 .word 0xffffdfac */
/* @0x15b108 ldrsbeq r12, [lr], -r4 */
/* @0x15b10c .word 0xffffdfb0 */
/* @0x15b110 andseq r12, lr, r8, asr #19 */
/* @0x15b114 andseq r12, lr, r4, asr #19 */
/* @0x15b118 ldrheq r12, [lr], -r12 */
/* @0x15b11c ldrheq r12, [lr], -r8 */
/* @0x15b120 ldrheq r12, [lr], -r4 */
/* @0x15b124 .word 0xffffdfb4 */
/* @0x15b128 andseq r12, lr, r8, lsr #19 */
/* @0x15b12c .word 0xffffdfb8 */
/* @0x15b130 andseq r12, lr, r0, lsr #19 */
/* @0x15b134 .word 0xffffdfbc */
/* @0x15b138 mulseq lr, r8, r9 */
/* @0x15b13c .word 0xffffdfc0 */
/* @0x15b140 mulseq lr, r0, r9 */
/* @0x15b144 .word 0xffffdfc4 */
/* @0x15b148 andseq r12, lr, r0, lsl #19 */
/* @0x15b14c andseq r12, lr, r0, lsl #19 */
/* @0x15b150 andseq r12, lr, r4, lsl #19 */
/* @0x15b154 andseq r12, lr, r4, lsl #19 */
/* @0x15b158 .word 0xffffdfc8 */
/* @0x15b15c andseq r12, lr, r8, ror r9 */
/* @0x15b160 .word 0xffffdfcc */
/* @0x15b164 andseq r12, lr, r4, ror r9 */
/* @0x15b168 andseq r12, lr, r0, ror r9 */
/* @0x15b16c andseq r12, lr, r12, ror #18 */
/* @0x15b170 .word 0xffffdfd0 */
/* @0x15b174 andseq r12, lr, r4, ror #18 */
/* @0x15b178 .word 0xffffdfd4 */
/* @0x15b17c andseq r12, lr, r12, asr r9 */
/* @0x15b180 .word 0xffffdfd8 */
/* @0x15b184 andseq r12, lr, r0, ror #18 */
/* @0x15b188 .word 0xffffdfdc */
/* @0x15b18c andseq r12, lr, r8, asr r9 */
/* @0x15b190 .word 0xffffdfe0 */
/* @0x15b194 andseq r12, lr, r12, asr r9 */
/* @0x15b198 .word 0xffffdfe4 */
/* @0x15b19c andseq r12, lr, r12, asr r9 */
/* @0x15b1a0 .word 0xffffdfe8 */
/* @0x15b1a4 andseq r12, lr, r0, ror #18 */
/* @0x15b1a8 .word 0xffffdfec */
/* @0x15b1ac andseq r12, lr, r8, asr r9 */
/* @0x15b1b0 .word 0xffffdff0 */
/* @0x15b1b4 andseq r12, lr, r4, asr r9 */
/* @0x15b1b8 .word 0xffffdff4 */
/* @0x15b1bc andseq r12, lr, r4, asr r9 */
/* @0x15b1c0 .word 0xffffdff8 */
/* @0x15b1c4 andseq r12, lr, r4, asr r9 */
/* @0x15b1c8 .word 0xffffdffc */
/* @0x15b1cc andseq r12, lr, r4, asr r9 */
/* @0x15b1d0 .word 0xffffe000 */
/* @0x15b1d4 andseq r12, lr, r4, ror #18 */
/* @0x15b1d8 .word 0xffffe004 */
/* @0x15b1dc andseq r12, lr, r8, asr r9 */
/* @0x15b1e0 .word 0xffffe008 */
/* @0x15b1e4 andseq r12, lr, r0, asr r9 */
/* @0x15b1e8 .word 0xffffe00c */
/* @0x15b1ec andseq r12, lr, r8, asr #18 */
/* @0x15b1f0 .word 0xffffe010 */
/* @0x15b1f4 andseq r12, lr, r8, lsr r9 */
/* @0x15b1f8 .word 0xffffe014 */
/* @0x15b1fc andseq r12, lr, r12, lsr #18 */
/* @0x15b200 andseq r12, lr, r8, lsr #18 */
/* @0x15b204 andseq r12, lr, r12, lsl r9 */
/* @0x15b208 andseq r12, lr, r4, lsl r9 */
/* @0x15b20c .word 0xffffe018 */
/* @0x15b210 andseq r12, lr, r4, lsl #18 */
/* @0x15b214 .word 0xffffe01c */
/* @0x15b218 ldrsheq r12, [lr], -r8 */
/* @0x15b21c .word 0xffffe020 */
/* @0x15b220 andseq r12, lr, r12, ror #17 */
/* @0x15b224 .word 0xffffe024 */
/* @0x15b228 ldrsbeq r12, [lr], -r12 */
/* @0x15b22c .word 0xffffe028 */
/* @0x15b230 ldrsbeq r12, [lr], -r0 */
/* @0x15b234 andseq r12, lr, r8, asr #17 */
/* @0x15b238 .word 0xffffe02c */
/* @0x15b23c ldrheq r12, [lr], -r4 */
/* @0x15b240 .word 0xffffe030 */
/* @0x15b244 andseq r12, lr, r4, lsr #17 */
/* @0x15b248 .word 0xffffe034 */
/* @0x15b24c mulseq lr, r12, r8 */
/* @0x15b250 .word 0xffffe038 */
/* @0x15b254 mulseq lr, r8, r8 */
/* @0x15b258 .word 0xffffe03c */
/* @0x15b25c mulseq lr, r4, r8 */
/* @0x15b260 .word 0xffffe040 */
/* @0x15b264 andseq r12, lr, r4, lsl #17 */
/* @0x15b268 .word 0xffffe044 */
/* @0x15b26c andseq r12, lr, r4, lsl #17 */
/* @0x15b270 .word 0xffffe048 */
/* @0x15b274 andseq r12, lr, r4, lsl #17 */
/* @0x15b278 .word 0xffffe04c */
/* @0x15b27c andseq r12, lr, r4, lsl #17 */
/* @0x15b280 .word 0xffffe050 */
/* @0x15b284 andseq r12, lr, r0, lsl #17 */
/* @0x15b288 .word 0xffffe054 */
/* @0x15b28c andseq r12, lr, r12, ror r8 */
/* @0x15b290 .word 0xffffe058 */
/* @0x15b294 andseq r12, lr, r12, ror #16 */
/* @0x15b298 .word 0xffffe05c */
/* @0x15b29c andseq r12, lr, r8, ror #16 */
/* @0x15b2a0 .word 0xffffe060 */
/* @0x15b2a4 andseq r12, lr, r12, asr r8 */
/* @0x15b2a8 .word 0xffffe064 */
/* @0x15b2ac andseq r12, lr, r4, asr r8 */
/* @0x15b2b0 .word 0xffffe068 */
/* @0x15b2b4 andseq r12, lr, r12, asr #16 */
/* @0x15b2b8 .word 0xffffe06c */
/* @0x15b2bc andseq r12, lr, r8, asr #16 */
/* @0x15b2c0 .word 0xffffe070 */
/* @0x15b2c4 andseq r12, lr, r0, asr #16 */
/* @0x15b2c8 .word 0xffffe074 */
/* @0x15b2cc andseq r12, lr, r8, lsr r8 */
/* @0x15b2d0 andseq r12, lr, r8, lsr r8 */
/* @0x15b2d4 .word 0xffffe078 */
/* @0x15b2d8 andseq r12, lr, r12, lsr #16 */
/* @0x15b2dc .word 0xffffe07c */
/* @0x15b2e0 andseq r12, lr, r12, lsl r8 */
/* @0x15b2e4 .word 0xffffe080 */
/* @0x15b2e8 andseq r12, lr, r4, lsl r8 */
/* @0x15b2ec .word 0xffffe084 */
/* @0x15b2f0 andseq r12, lr, r8, lsl #16 */
/* @0x15b2f4 .word 0xffffe088 */
/* @0x15b2f8 andseq r12, lr, r0, lsl #16 */
/* @0x15b2fc .word 0xffffe08c */
/* @0x15b300 ldrsheq r12, [lr], -r0 */
/* @0x15b304 .word 0xffffe090 */
/* @0x15b308 andseq r12, lr, r8, ror #15 */
/* @0x15b30c andseq r12, lr, r4, ror #15 */
/* @0x15b310 ldrsbeq r12, [lr], -r8 */
/* @0x15b314 .word 0xffffe094 */
/* @0x15b318 andseq r12, lr, r12, asr #15 */
/* @0x15b31c .word 0xffffe098 */
/* @0x15b320 ldrheq r12, [lr], -r12 */
/* @0x15b324 .word 0xffffe09c */
/* @0x15b328 ldrheq r12, [lr], -r0 */
/* @0x15b32c .word 0xffffe0a0 */
/* @0x15b330 andseq r12, lr, r4, lsr #15 */
/* @0x15b334 .word 0xffffe0a4 */
/* @0x15b338 andseq r12, lr, r0, lsr #15 */
/* @0x15b33c .word 0xffffe0a8 */
/* @0x15b340 mulseq lr, r8, r7 */
/* @0x15b344 .word 0xffffe0ac */
/* @0x15b348 mulseq lr, r0, r7 */
/* @0x15b34c .word 0xffffe0b0 */
/* @0x15b350 andseq r12, lr, r8, lsl #15 */
/* @0x15b354 .word 0xffffe0b4 */
/* @0x15b358 andseq r12, lr, r0, lsl #15 */
/* @0x15b35c .word 0xffffe0b8 */
/* @0x15b360 andseq r12, lr, r12, ror r7 */
/* @0x15b364 .word 0xffffe0bc */
/* @0x15b368 andseq r12, lr, r8, ror r7 */
/* @0x15b36c .word 0xffffe0c0 */
/* @0x15b370 andseq r12, lr, r4, ror r7 */
/* @0x15b374 .word 0xffffe0c4 */
/* @0x15b378 andseq r12, lr, r4, ror r7 */
/* @0x15b37c .word 0xffffe0c8 */
/* @0x15b380 andseq r12, lr, r12, ror #14 */
/* @0x15b384 .word 0xffffe0cc */
/* @0x15b388 andseq r12, lr, r4, ror #14 */
/* @0x15b38c .word 0xffffe0d0 */
/* @0x15b390 andseq r12, lr, r12, asr r7 */
/* @0x15b394 .word 0xffffe0d4 */
/* @0x15b398 andseq r12, lr, r4, asr r7 */
/* @0x15b39c .word 0xffffe0d8 */
/* @0x15b3a0 andseq r12, lr, r8, asr #14 */
/* @0x15b3a4 .word 0xffffe0dc */
/* @0x15b3a8 andseq r12, lr, r12, lsr r7 */
/* @0x15b3ac .word 0xffffe0e0 */
/* @0x15b3b0 andseq r12, lr, r12, lsr #14 */
/* @0x15b3b4 .word 0xffffe0e4 */
/* @0x15b3b8 andseq r12, lr, r4, lsr #14 */
/* @0x15b3bc .word 0xffffe0e8 */
/* @0x15b3c0 andseq r12, lr, r8, lsl r7 */
/* @0x15b3c4 andseq r12, lr, r8, lsl r7 */
/* @0x15b3c8 andseq r12, lr, r4, lsl r7 */
/* @0x15b3cc andseq r12, lr, r8, lsl r7 */
/* @0x15b3d0 andseq r12, lr, r12, lsl r7 */
/* @0x15b3d4 andseq r12, lr, r0, lsr #14 */
/* @0x15b3d8 andseq r12, lr, r0, lsr #14 */
/* @0x15b3dc andseq r12, lr, r0, lsr #14 */
/* @0x15b3e0 andseq r12, lr, r8, lsl r7 */
/* @0x15b3e4 andseq r12, lr, r12, lsl r7 */
/* @0x15b3e8 andseq r12, lr, r4, lsr #14 */
/* @0x15b3ec .word 0xffffe0ec */
/* @0x15b3f0 andseq r12, lr, r12, lsl r7 */
/* @0x15b3f4 .word 0xffffe0f0 */
/* @0x15b3f8 andseq r12, lr, r4, lsl r7 */
/* @0x15b3fc .word 0xffffe0f4 */
/* @0x15b400 andseq r12, lr, r4, lsl r7 */
/* @0x15b404 .word 0xffffe0f8 */
/* @0x15b408 andseq r12, lr, r4, lsl r7 */
/* @0x15b40c .word 0xffffe0fc */
/* @0x15b410 andseq r12, lr, r0, lsl #14 */
/* @0x15b414 .word 0xffffe100 */
/* @0x15b418 andseq r12, lr, r12, ror #13 */
/* @0x15b41c .word 0xffffe104 */
/* @0x15b420 ldrsbeq r12, [lr], -r12 */
/* @0x15b424 .word 0xffffe108 */
/* @0x15b428 andseq r12, lr, r12, asr #13 */
/* @0x15b42c .word 0xffffe10c */
/* @0x15b430 ldrheq r12, [lr], -r12 */
/* @0x15b434 .word 0xffffe110 */
/* @0x15b438 andseq r12, lr, r12, lsr #13 */
/* @0x15b43c .word 0xffffe114 */
/* @0x15b440 mulseq lr, r12, r6 */
/* @0x15b444 mulseq lr, r8, r6 */
/* @0x15b448 mulseq lr, r12, r6 */
/* @0x15b44c andseq r12, lr, r8, lsr #13 */
/* @0x15b450 ldrheq r12, [lr], -r4 */
/* @0x15b454 andseq r12, lr, r12, lsr #13 */
/* @0x15b458 andseq r12, lr, r4, lsr #13 */
/* @0x15b45c andseq r12, lr, r0, lsr #13 */
/* @0x15b460 .word 0xffffe118 */
/* @0x15b464 mulseq lr, r4, r6 */
/* @0x15b468 .word 0xffffe11c */
/* @0x15b46c mulseq lr, r0, r6 */
/* @0x15b470 mulseq lr, r0, r6 */
/* @0x15b474 andseq r12, lr, r12, lsl #13 */
/* @0x15b478 andseq r12, lr, r8, lsl #13 */
/* @0x15b47c andseq r12, lr, r4, lsl #13 */
/* @0x15b480 .word 0xffffe120 */
/* @0x15b484 andseq r12, lr, r0, lsl #13 */
/* @0x15b488 .word 0xffffe124 */
/* @0x15b48c andseq r12, lr, r4, ror r6 */
/* @0x15b490 .word 0xffffe128 */
/* @0x15b494 andseq r12, lr, r8, ror #12 */
/* @0x15b498 .word 0xffffe12c */
/* @0x15b49c andseq r12, lr, r12, asr r6 */
/* @0x15b4a0 .word 0xffffe130 */
/* @0x15b4a4 andseq r12, lr, r8, asr r6 */
/* @0x15b4a8 .word 0xffffe134 */
/* @0x15b4ac andseq r12, lr, r12, asr #12 */
/* @0x15b4b0 .word 0xffffe138 */
/* @0x15b4b4 andseq r12, lr, r0, asr #12 */
/* @0x15b4b8 .word 0xffffe13c */
/* @0x15b4bc andseq r12, lr, r8, lsr r6 */
/* @0x15b4c0 .word 0xffffe140 */
/* @0x15b4c4 andseq r12, lr, r4, lsr r6 */
/* @0x15b4c8 .word 0xffffe144 */
/* @0x15b4cc andseq r12, lr, r4, lsr r6 */
/* @0x15b4d0 .word 0xffffe148 */
/* @0x15b4d4 ldrsheq r11, [lr], -r4 */
/* @0x15b4d8 .word 0xffffe14c */
/* @0x15b4dc ldrsheq r11, [lr], -r0 */
/* @0x15b4e0 .word 0xffffe150 */
/* @0x15b4e4 ldrsheq r11, [lr], -r0 */
/* @0x15b4e8 .word 0xffffe154 */
/* @0x15b4ec ldrsheq r11, [lr], -r8 */
/* @0x15b4f0 .word 0xffffe158 */
/* @0x15b4f4 andseq r11, lr, r4, lsl #30 */
/* @0x15b4f8 ldrsheq r11, [lr], -r12 */
/* @0x15b4fc .word 0xffffe15c */
/* @0x15b500 ldrsheq r11, [lr], -r0 */
/* @0x15b504 .word 0xffffe160 */
/* @0x15b508 andseq r11, lr, r8, ror #29 */
/* @0x15b50c .word 0xffffe164 */
/* @0x15b510 ldrsbeq r11, [lr], -r12 */
/* @0x15b514 .word 0xffffe168 */
/* @0x15b518 ldrsbeq r11, [lr], -r0 */
/* @0x15b51c .word 0xffffe16c */
/* @0x15b520 andseq r11, lr, r8, asr #29 */
/* @0x15b524 .word 0xffffe170 */
/* @0x15b528 ldrheq r11, [lr], -r12 */
/* @0x15b52c .word 0xffffe174 */
/* @0x15b530 andseq r11, lr, r12, lsr #29 */
/* @0x15b534 .word 0xffffe178 */
/* @0x15b538 andseq r11, lr, r4, lsr #29 */
/* @0x15b53c .word 0xffffe17c */
/* @0x15b540 mulseq lr, r12, lr */
/* @0x15b544 .word 0xffffe180 */
/* @0x15b548 andseq r11, lr, r12, lsl #29 */
/* @0x15b54c .word 0xffffe184 */
/* @0x15b550 andseq r11, lr, r8, lsl #29 */
/* @0x15b554 .word 0xffffe188 */
/* @0x15b558 andseq r11, lr, r0, lsl #29 */
/* @0x15b55c .word 0xffffe18c */
/* @0x15b560 andseq r11, lr, r8, ror lr */
/* @0x15b564 .word 0xffffe190 */
/* @0x15b568 andseq r11, lr, r12, ror #28 */
/* @0x15b56c .word 0xffffe194 */
/* @0x15b570 andseq r11, lr, r4, ror #28 */
/* @0x15b574 .word 0xffffe198 */
/* @0x15b578 andseq r11, lr, r8, ror #28 */
/* @0x15b57c .word 0xffffe19c */
/* @0x15b580 andseq r11, lr, r0, ror #28 */
/* @0x15b584 .word 0xffffe1a0 */
/* @0x15b588 andseq r11, lr, r8, asr lr */
/* @0x15b58c .word 0xffffe1a4 */
/* @0x15b590 andseq r11, lr, r8, asr lr */
/* @0x15b594 .word 0xffffe1a8 */
/* @0x15b598 andseq r11, lr, r8, asr lr */
/* @0x15b59c .word 0xffffe1ac */
/* @0x15b5a0 andseq r11, lr, r12, asr lr */
/* @0x15b5a4 .word 0xffffe1b0 */
/* @0x15b5a8 andseq r11, lr, r12, asr lr */
/* @0x15b5ac .word 0xffffe1b4 */
/* @0x15b5b0 andseq r11, lr, r0, ror #28 */
/* @0x15b5b4 .word 0xffffe1b8 */
/* @0x15b5b8 andseq r11, lr, r4, ror #28 */
/* @0x15b5bc .word 0xffffe1bc */
/* @0x15b5c0 andseq r11, lr, r4, ror #28 */
/* @0x15b5c4 .word 0xffffe1c0 */
/* @0x15b5c8 andseq r11, lr, r8, ror #28 */
/* @0x15b5cc andseq r11, lr, r0, ror lr */
/* @0x15b5d0 .word 0xffffe1c4 */
/* @0x15b5d4 andseq r11, lr, r0, ror lr */
/* @0x15b5d8 .word 0xffffe1c8 */
/* @0x15b5dc andseq r11, lr, r0, ror lr */
/* @0x15b5e0 .word 0xffffe1cc */
/* @0x15b5e4 andseq r11, lr, r4, ror lr */
/* @0x15b5e8 .word 0xffffe1d0 */
/* @0x15b5ec andseq r11, lr, r4, ror lr */
/* @0x15b5f0 .word 0xffffe1d4 */
/* @0x15b5f4 andseq r11, lr, r4, ror lr */
/* @0x15b5f8 .word 0xffffe1d8 */
/* @0x15b5fc andseq r11, lr, r0, lsl #29 */
/* @0x15b600 .word 0xffffe1dc */
/* @0x15b604 andseq r11, lr, r8, ror lr */
/* @0x15b608 .word 0xffffe1e0 */
/* @0x15b60c andseq r11, lr, r12, ror lr */
/* @0x15b610 .word 0xffffe1e4 */
/* @0x15b614 andseq r11, lr, r12, ror lr */
/* @0x15b618 .word 0xffffe1e8 */
/* @0x15b61c andseq r11, lr, r12, ror lr */
/* @0x15b620 .word 0xffffe1ec */
/* @0x15b624 andseq r11, lr, r0, lsl #29 */
/* @0x15b628 .word 0xffffe1f0 */
/* @0x15b62c andseq r11, lr, r4, ror lr */
/* @0x15b630 .word 0xffffe1f4 */
/* @0x15b634 andseq r11, lr, r0, ror lr */
/* @0x15b638 .word 0xffffe1f8 */
/* @0x15b63c andseq r11, lr, r12, ror #28 */
/* @0x15b640 .word 0xffffe1fc */
/* @0x15b644 andseq r11, lr, r8, ror #28 */
/* @0x15b648 .word 0xffffe200 */
/* @0x15b64c andseq r11, lr, r8, ror #28 */
/* @0x15b650 andseq r11, lr, r8, ror #28 */
/* @0x15b654 andseq r11, lr, r8, ror #28 */
/* @0x15b658 andseq r11, lr, r4, ror lr */
/* @0x15b65c andseq r11, lr, r0, ror lr */
/* @0x15b660 andseq r11, lr, r12, ror #28 */
/* @0x15b664 andseq r11, lr, r0, ror lr */
/* @0x15b668 andseq r11, lr, r0, ror lr */
/* @0x15b66c andseq r11, lr, r0, ror lr */
/* @0x15b670 andseq r11, lr, r4, ror lr */
/* @0x15b674 andseq r11, lr, r4, ror lr */
/* @0x15b678 andseq r11, lr, r0, lsl #29 */
/* @0x15b67c andseq r11, lr, r8, lsl #29 */
/* @0x15b680 andseq r11, lr, r12, lsl #29 */
/* @0x15b684 mulseq lr, r0, lr */
/* @0x15b688 mulseq lr, r4, lr */
/* @0x15b68c mulseq lr, r8, lr */
/* @0x15b690 mulseq lr, r8, lr */
/* @0x15b694 andseq r11, lr, r0, lsr #29 */
/* @0x15b698 andseq r11, lr, r0, lsr #29 */
/* @0x15b69c andseq r11, lr, r4, lsr #29 */
/* @0x15b6a0 andseq r11, lr, r8, lsr #29 */
/* @0x15b6a4 ldrheq r11, [lr], -r8 */
/* @0x15b6a8 andseq r11, lr, r4, asr #29 */
/* @0x15b6ac andseq r11, lr, r12, asr #29 */
/* @0x15b6b0 ldrsbeq r11, [lr], -r4 */
/* @0x15b6b4 ldrsbeq r11, [lr], -r8 */
/* @0x15b6b8 ldrsbeq r11, [lr], -r8 */
/* @0x15b6bc ldrsbeq r11, [lr], -r8 */
/* @0x15b6c0 ldrsbeq r11, [lr], -r8 */
/* @0x15b6c4 ldrsbeq r11, [lr], -r8 */
/* @0x15b6c8 andseq r11, lr, r12, asr #29 */
/* @0x15b6cc andseq r11, lr, r12, asr #29 */
/* @0x15b6d0 ldrsbeq r11, [lr], -r4 */
/* @0x15b6d4 ldrsbeq r11, [lr], -r8 */
/* @0x15b6d8 andseq r11, lr, r8, ror #29 */
/* @0x15b6dc andseq r11, lr, r8, ror #29 */
/* @0x15b6e0 andseq r11, lr, r4, ror #29 */
/* @0x15b6e4 andseq r11, lr, r8, ror #29 */
/* @0x15b6e8 andseq r11, lr, r4, ror #29 */
/* @0x15b6ec andseq r11, lr, r8, ror #29 */
/* @0x15b6f0 andseq r11, lr, r12, ror #29 */
/* @0x15b6f4 ldrsheq r11, [lr], -r4 */
/* @0x15b6f8 ldrsheq r11, [lr], -r8 */
/* @0x15b6fc ldrsheq r11, [lr], -r4 */
/* @0x15b700 ldrsheq r11, [lr], -r12 */
/* @0x15b704 ldrsheq r11, [lr], -r12 */
/* @0x15b708 andseq r11, lr, r4, lsl #30 */
/* @0x15b70c andseq r11, lr, r8, lsl #30 */
/* @0x15b710 andseq r11, lr, r0, lsl pc */
/* @0x15b714 andseq r11, lr, r0, lsr #30 */
/* @0x15b718 andseq r11, lr, r12, lsr #30 */
/* @0x15b71c andseq r11, lr, r0, lsr pc */
/* @0x15b720 andseq r11, lr, r4, lsr pc */
/* @0x15b724 andseq r11, lr, r4, lsr pc */
/* @0x15b728 andseq r11, lr, r8, lsr pc */
/* @0x15b72c andseq r11, lr, r12, lsr pc */
/* @0x15b730 andseq r11, lr, r12, asr #30 */
/* @0x15b734 andseq r11, lr, r12, asr pc */
/* @0x15b738 andseq r11, lr, r8, ror #30 */
/* @0x15b73c andseq r11, lr, r12, ror pc */
/* @0x15b740 andseq r11, lr, r4, lsl #31 */
/* @0x15b744 mulseq lr, r0, pc */
/* @0x15b748 mulseq lr, r12, pc */
/* @0x15b74c andseq r11, lr, r8, lsr #31 */
/* @0x15b750 andseq r11, lr, r8, lsr #31 */
/* @0x15b754 ldrheq r11, [lr], -r12 */
/* @0x15b758 andseq r11, lr, r4, asr #31 */
/* @0x15b75c andseq r11, lr, r0, asr #31 */
/* @0x15b760 ldrheq r11, [lr], -r12 */
/* @0x15b764 andseq r11, lr, r4, asr #31 */
/* @0x15b768 andseq r11, lr, r4, asr #31 */
/* @0x15b76c andseq r11, lr, r4, asr #31 */
/* @0x15b770 andseq r11, lr, r8, asr #31 */
/* @0x15b774 andseq r11, lr, r12, asr #31 */
/* @0x15b778 andseq r11, lr, r12, asr #31 */
/* @0x15b77c ldrsbeq r11, [lr], -r8 */
/* @0x15b780 andseq r11, lr, r8, ror #31 */
/* @0x15b784 andseq r11, lr, r8, ror #31 */
/* @0x15b788 andseq r11, lr, r12, ror #31 */
/* @0x15b78c ldrsheq r11, [lr], -r0 */
/* @0x15b790 ldrsheq r11, [lr], -r8 */
/* @0x15b794 andseq r12, lr, r0 */
/* @0x15b798 andseq r12, lr, r0 */
/* @0x15b79c andseq r12, lr, r8 */
/* @0x15b7a0 andseq r12, lr, r8 */
/* @0x15b7a4 andseq r12, lr, r12 */
/* @0x15b7a8 andseq r12, lr, r4, lsl r0 */
/* @0x15b7ac andseq r12, lr, r4, lsr #32 */
/* @0x15b7b0 andseq r12, lr, r0, lsr r0 */
/* @0x15b7b4 andseq r12, lr, r12, lsr r0 */
/* @0x15b7b8 andseq r12, lr, r4, asr #32 */
/* @0x15b7bc andseq r12, lr, r12, asr #32 */
/* @0x15b7c0 andseq r12, lr, r0, asr r0 */
/* @0x15b7c4 andseq r12, lr, r0, asr r0 */
/* @0x15b7c8 andseq r12, lr, r12, asr #32 */
/* @0x15b7cc andseq r12, lr, r8, asr #32 */
/* @0x15b7d0 andseq r12, lr, r4, asr #32 */
/* @0x15b7d4 andseq r12, lr, r4, lsr r0 */
/* @0x15b7d8 andseq r12, lr, r0, lsr r0 */
/* @0x15b7dc andseq r12, lr, r4, lsr r0 */
/* @0x15b7e0 andseq r12, lr, r4, lsr r0 */
/* @0x15b7e4 andseq r12, lr, r0, asr #32 */
/* @0x15b7e8 andseq r12, lr, r12, lsr r0 */
/* @0x15b7ec andseq r12, lr, r8, lsr r0 */
/* @0x15b7f0 andseq r12, lr, r12, lsr r0 */
/* @0x15b7f4 andseq r12, lr, r12, lsr r0 */
/* @0x15b7f8 andseq r12, lr, r4, asr #32 */
/* @0x15b7fc andseq r12, lr, r8, asr #32 */
/* @0x15b800 andseq r12, lr, r0, asr r0 */
/* @0x15b804 andseq r12, lr, r4, asr r0 */
/* @0x15b808 andseq r12, lr, r0, asr r0 */
/* @0x15b80c andseq r12, lr, r8, asr r0 */
/* @0x15b810 andseq r12, lr, r8, asr r0 */
/* @0x15b814 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b818 ldr r1, [pc, #-0x350] */
/* @0x15b81c ldr r0, [pc, #-0x350] */
/* @0x15b820 mov r3, r4 */
/* @0x15b824 mov r2, #5 */
/* @0x15b828 ldr r1, [r10, r1] */
/* @0x15b82c add r0, pc, r0 */
/* @0x15b830 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b834 ldr r1, [pc, #-0x364] */
/* @0x15b838 ldr r0, [pc, #-0x364] */
/* @0x15b83c mov r3, r4 */
/* @0x15b840 mov r2, #1 */
/* @0x15b844 ldr r1, [r10, r1] */
/* @0x15b848 add r0, pc, r0 */
/* @0x15b84c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b850 ldr r1, [pc, #-0x378] */
/* @0x15b854 ldr r0, [pc, #-0x378] */
/* @0x15b858 mov r3, r4 */
/* @0x15b85c mov r2, #1 */
/* @0x15b860 ldr r1, [r10, r1] */
/* @0x15b864 add r0, pc, r0 */
/* @0x15b868 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b86c ldr r1, [pc, #-0x38c] */
/* @0x15b870 ldr r0, [pc, #-0x38c] */
/* @0x15b874 mov r3, r4 */
/* @0x15b878 mov r2, #1 */
/* @0x15b87c ldr r1, [r10, r1] */
/* @0x15b880 add r0, pc, r0 */
/* @0x15b884 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b888 ldr r1, [pc, #-0x3a0] */
/* @0x15b88c mov r2, r4 */
/* @0x15b890 mov r3, r4 */
/* @0x15b894 ldr r0, [pc, #-0x3a8] */
/* @0x15b898 ldr r4, [r10, r1] */
/* @0x15b89c add r0, pc, r0 */
/* @0x15b8a0 mov r1, r4 */
/* @0x15b8a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b8a8 ldr r0, [pc, #-0x3b8] */
/* @0x15b8ac mov r2, #0 */
/* @0x15b8b0 mov r1, r4 */
/* @0x15b8b4 mov r3, r2 */
/* @0x15b8b8 add r0, pc, r0 */
/* @0x15b8bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b8c0 ldr r1, [pc, #-0x3cc] */
/* @0x15b8c4 ldr r0, [pc, #-0x3cc] */
/* @0x15b8c8 mov r2, #0 */
/* @0x15b8cc mov r3, r2 */
/* @0x15b8d0 ldr r1, [r10, r1] */
/* @0x15b8d4 add r0, pc, r0 */
/* @0x15b8d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b8dc ldr r1, [pc, #-0x3e0] */
/* @0x15b8e0 ldr r0, [pc, #-0x3e0] */
/* @0x15b8e4 mov r2, #1 */
/* @0x15b8e8 mov r3, #0 */
/* @0x15b8ec ldr r1, [r10, r1] */
/* @0x15b8f0 add r0, pc, r0 */
/* @0x15b8f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b8f8 ldr r1, [pc, #-0x3f4] */
/* @0x15b8fc ldr r0, [pc, #-0x3f4] */
/* @0x15b900 mov r2, #1 */
/* @0x15b904 mov r3, #0 */
/* @0x15b908 ldr r1, [r10, r1] */
/* @0x15b90c add r0, pc, r0 */
/* @0x15b910 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b914 ldr r1, [pc, #-0x408] */
/* @0x15b918 ldr r0, [pc, #-0x408] */
/* @0x15b91c mov r2, #1 */
/* @0x15b920 mov r3, #0 */
/* @0x15b924 ldr r1, [r10, r1] */
/* @0x15b928 add r0, pc, r0 */
/* @0x15b92c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b930 ldr r1, [pc, #-0x41c] */
/* @0x15b934 ldr r0, [pc, #-0x41c] */
/* @0x15b938 mov r2, #1 */
/* @0x15b93c mov r3, #0 */
/* @0x15b940 ldr r1, [r10, r1] */
/* @0x15b944 add r0, pc, r0 */
/* @0x15b948 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b94c ldr r1, [pc, #-0x430] */
/* @0x15b950 ldr r0, [pc, #-0x430] */
/* @0x15b954 mov r2, #1 */
/* @0x15b958 mov r3, #0 */
/* @0x15b95c ldr r1, [r10, r1] */
/* @0x15b960 add r0, pc, r0 */
/* @0x15b964 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b968 ldr r1, [pc, #-0x444] */
/* @0x15b96c ldr r0, [pc, #-0x444] */
/* @0x15b970 mov r2, #1 */
/* @0x15b974 mov r3, #0 */
/* @0x15b978 ldr r1, [r10, r1] */
/* @0x15b97c add r0, pc, r0 */
/* @0x15b980 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b984 ldr r1, [pc, #-0x458] */
/* @0x15b988 ldr r0, [pc, #-0x458] */
/* @0x15b98c mov r2, #1 */
/* @0x15b990 mov r3, #0 */
/* @0x15b994 ldr r1, [r10, r1] */
/* @0x15b998 add r0, pc, r0 */
/* @0x15b99c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b9a0 ldr r1, [pc, #-0x46c] */
/* @0x15b9a4 ldr r0, [pc, #-0x46c] */
/* @0x15b9a8 mov r2, #1 */
/* @0x15b9ac mov r3, #0 */
/* @0x15b9b0 ldr r1, [r10, r1] */
/* @0x15b9b4 add r0, pc, r0 */
/* @0x15b9b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b9bc ldr r1, [pc, #-0x480] */
/* @0x15b9c0 ldr r0, [pc, #-0x480] */
/* @0x15b9c4 mov r2, #0 */
/* @0x15b9c8 mov r3, r2 */
/* @0x15b9cc ldr r1, [r10, r1] */
/* @0x15b9d0 add r0, pc, r0 */
/* @0x15b9d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b9d8 ldr r1, [pc, #-0x494] */
/* @0x15b9dc ldr r0, [pc, #-0x494] */
/* @0x15b9e0 mov r2, #1 */
/* @0x15b9e4 mov r3, #0 */
/* @0x15b9e8 ldr r1, [r10, r1] */
/* @0x15b9ec add r0, pc, r0 */
/* @0x15b9f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15b9f4 ldr r1, [pc, #-0x4a8] */
/* @0x15b9f8 ldr r0, [pc, #-0x4a8] */
/* @0x15b9fc mov r2, #1 */
/* @0x15ba00 mov r3, #0 */
/* @0x15ba04 ldr r1, [r10, r1] */
/* @0x15ba08 add r0, pc, r0 */
/* @0x15ba0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ba10 ldr r1, [pc, #-0x4bc] */
/* @0x15ba14 ldr r0, [pc, #-0x4bc] */
/* @0x15ba18 mov r2, #1 */
/* @0x15ba1c mov r3, #0 */
/* @0x15ba20 ldr r1, [r10, r1] */
/* @0x15ba24 add r0, pc, r0 */
/* @0x15ba28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ba2c ldr r1, [pc, #-0x4d0] */
/* @0x15ba30 ldr r0, [pc, #-0x4d0] */
/* @0x15ba34 mvn r2, #0 */
/* @0x15ba38 mov r3, #0 */
/* @0x15ba3c ldr r1, [r10, r1] */
/* @0x15ba40 add r0, pc, r0 */
/* @0x15ba44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ba48 ldr r1, [pc, #-0x4e4] */
/* @0x15ba4c ldr r0, [pc, #-0x4e4] */
/* @0x15ba50 mov r2, #0 */
/* @0x15ba54 mov r3, r2 */
/* @0x15ba58 ldr r1, [r10, r1] */
/* @0x15ba5c add r0, pc, r0 */
/* @0x15ba60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ba64 ldr r1, [pc, #-0x4f8] */
/* @0x15ba68 ldr r0, [pc, #-0x4f8] */
/* @0x15ba6c mov r2, #1 */
/* @0x15ba70 mov r3, #0 */
/* @0x15ba74 ldr r1, [r10, r1] */
/* @0x15ba78 add r0, pc, r0 */
/* @0x15ba7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ba80 ldr r1, [pc, #-0x50c] */
/* @0x15ba84 ldr r0, [pc, #-0x50c] */
/* @0x15ba88 mov r2, #1 */
/* @0x15ba8c mov r3, #0 */
/* @0x15ba90 ldr r1, [r10, r1] */
/* @0x15ba94 add r0, pc, r0 */
/* @0x15ba98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ba9c ldr r1, [pc, #-0x520] */
/* @0x15baa0 ldr r0, [pc, #-0x520] */
/* @0x15baa4 mov r2, #1 */
/* @0x15baa8 mov r3, #0 */
/* @0x15baac ldr r1, [r10, r1] */
/* @0x15bab0 add r0, pc, r0 */
/* @0x15bab4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bab8 ldr r1, [pc, #-0x534] */
/* @0x15babc ldr r0, [pc, #-0x534] */
/* @0x15bac0 mov r2, #1 */
/* @0x15bac4 mov r3, #0 */
/* @0x15bac8 ldr r1, [r10, r1] */
/* @0x15bacc add r0, pc, r0 */
/* @0x15bad0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bad4 ldr r1, [pc, #-0x548] */
/* @0x15bad8 ldr r0, [pc, #-0x548] */
/* @0x15badc mov r2, #1 */
/* @0x15bae0 mov r3, #0 */
/* @0x15bae4 ldr r1, [r10, r1] */
/* @0x15bae8 add r0, pc, r0 */
/* @0x15baec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15baf0 ldr r1, [pc, #-0x55c] */
/* @0x15baf4 ldr r0, [pc, #-0x55c] */
/* @0x15baf8 mov r2, #1 */
/* @0x15bafc mov r3, #0 */
/* @0x15bb00 ldr r1, [r10, r1] */
/* @0x15bb04 add r0, pc, r0 */
/* @0x15bb08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bb0c ldr r1, [pc, #-0x570] */
/* @0x15bb10 ldr r0, [pc, #-0x570] */
/* @0x15bb14 mov r2, #1 */
/* @0x15bb18 mov r3, #0 */
/* @0x15bb1c ldr r1, [r10, r1] */
/* @0x15bb20 add r0, pc, r0 */
/* @0x15bb24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bb28 ldr r1, [pc, #-0x584] */
/* @0x15bb2c ldr r0, [pc, #-0x584] */
/* @0x15bb30 mov r2, #1 */
/* @0x15bb34 mov r3, #0 */
/* @0x15bb38 ldr r1, [r10, r1] */
/* @0x15bb3c add r0, pc, r0 */
/* @0x15bb40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bb44 ldr r1, [pc, #-0x598] */
/* @0x15bb48 ldr r0, [pc, #-0x598] */
/* @0x15bb4c mov r2, #1 */
/* @0x15bb50 mov r3, #0 */
/* @0x15bb54 ldr r1, [r10, r1] */
/* @0x15bb58 add r0, pc, r0 */
/* @0x15bb5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bb60 ldr r1, [pc, #-0x5ac] */
/* @0x15bb64 ldr r0, [pc, #-0x5ac] */
/* @0x15bb68 mov r2, #1 */
/* @0x15bb6c mov r3, #0 */
/* @0x15bb70 ldr r1, [r10, r1] */
/* @0x15bb74 add r0, pc, r0 */
/* @0x15bb78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bb7c ldr r1, [pc, #-0x5c0] */
/* @0x15bb80 ldr r0, [pc, #-0x5c0] */
/* @0x15bb84 mov r2, #1 */
/* @0x15bb88 mov r3, #0 */
/* @0x15bb8c ldr r4, [r10, r1] */
/* @0x15bb90 add r0, pc, r0 */
/* @0x15bb94 mov r1, r4 */
/* @0x15bb98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bb9c ldr r0, [pc, #-0x5d8] */
/* @0x15bba0 mov r1, r4 */
/* @0x15bba4 mov r2, #1 */
/* @0x15bba8 add r0, pc, r0 */
/* @0x15bbac mov r3, #0 */
/* @0x15bbb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bbb4 ldr r1, [pc, #-0x5ec] */
/* @0x15bbb8 ldr r0, [pc, #-0x5ec] */
/* @0x15bbbc mov r2, #1 */
/* @0x15bbc0 mov r3, #0 */
/* @0x15bbc4 ldr r1, [r10, r1] */
/* @0x15bbc8 add r0, pc, r0 */
/* @0x15bbcc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bbd0 ldr r1, [pc, #-0x600] */
/* @0x15bbd4 ldr r0, [pc, #-0x600] */
/* @0x15bbd8 mov r2, #1 */
/* @0x15bbdc mov r3, #0 */
/* @0x15bbe0 ldr r1, [r10, r1] */
/* @0x15bbe4 add r0, pc, r0 */
/* @0x15bbe8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bbec ldr r1, [pc, #-0x614] */
/* @0x15bbf0 ldr r0, [pc, #-0x614] */
/* @0x15bbf4 mov r2, #2 */
/* @0x15bbf8 mov r3, #0 */
/* @0x15bbfc ldr r1, [r10, r1] */
/* @0x15bc00 add r0, pc, r0 */
/* @0x15bc04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bc08 ldr r1, [pc, #-0x628] */
/* @0x15bc0c ldr r0, [pc, #-0x628] */
/* @0x15bc10 mvn r2, #0 */
/* @0x15bc14 mov r3, #0 */
/* @0x15bc18 ldr r1, [r10, r1] */
/* @0x15bc1c add r0, pc, r0 */
/* @0x15bc20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bc24 ldr r1, [pc, #-0x63c] */
/* @0x15bc28 ldr r0, [pc, #-0x63c] */
/* @0x15bc2c mov r2, #1 */
/* @0x15bc30 mov r3, #0 */
/* @0x15bc34 ldr r1, [r10, r1] */
/* @0x15bc38 add r0, pc, r0 */
/* @0x15bc3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bc40 ldr r1, [pc, #-0x650] */
/* @0x15bc44 ldr r0, [pc, #-0x650] */
/* @0x15bc48 mov r2, #1 */
/* @0x15bc4c mov r3, r2 */
/* @0x15bc50 ldr r1, [r10, r1] */
/* @0x15bc54 add r0, pc, r0 */
/* @0x15bc58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bc5c ldr r1, [pc, #-0x664] */
/* @0x15bc60 ldr r0, [pc, #-0x664] */
/* @0x15bc64 mov r2, #1 */
/* @0x15bc68 mov r3, r2 */
/* @0x15bc6c ldr r1, [r10, r1] */
/* @0x15bc70 add r0, pc, r0 */
/* @0x15bc74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bc78 ldr r1, [pc, #-0x678] */
/* @0x15bc7c ldr r0, [pc, #-0x678] */
/* @0x15bc80 mov r2, #0 */
/* @0x15bc84 mov r3, r2 */
/* @0x15bc88 ldr r1, [r10, r1] */
/* @0x15bc8c add r0, pc, r0 */
/* @0x15bc90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bc94 ldr r1, [pc, #-0x68c] */
/* @0x15bc98 ldr r0, [pc, #-0x68c] */
/* @0x15bc9c mov r2, #1 */
/* @0x15bca0 mov r3, r2 */
/* @0x15bca4 ldr r1, [r10, r1] */
/* @0x15bca8 add r0, pc, r0 */
/* @0x15bcac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bcb0 ldr r1, [pc, #-0x6a0] */
/* @0x15bcb4 ldr r0, [pc, #-0x6a0] */
/* @0x15bcb8 mov r2, #0 */
/* @0x15bcbc mov r3, #1 */
/* @0x15bcc0 ldr r1, [r10, r1] */
/* @0x15bcc4 add r0, pc, r0 */
/* @0x15bcc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bccc ldr r1, [pc, #-0x6b4] */
/* @0x15bcd0 ldr r0, [pc, #-0x6b4] */
/* @0x15bcd4 mov r2, #4 */
/* @0x15bcd8 mov r3, #0 */
/* @0x15bcdc ldr r1, [r10, r1] */
/* @0x15bce0 add r0, pc, r0 */
/* @0x15bce4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bce8 ldr r1, [pc, #-0x6c8] */
/* @0x15bcec ldr r0, [pc, #-0x6c8] */
/* @0x15bcf0 mov r2, #0 */
/* @0x15bcf4 mov r3, r2 */
/* @0x15bcf8 ldr r1, [r10, r1] */
/* @0x15bcfc add r0, pc, r0 */
/* @0x15bd00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bd04 ldr r1, [pc, #-0x6dc] */
/* @0x15bd08 ldr r0, [pc, #-0x6dc] */
/* @0x15bd0c mov r2, #0 */
/* @0x15bd10 mov r3, r2 */
/* @0x15bd14 ldr r1, [r10, r1] */
/* @0x15bd18 add r0, pc, r0 */
/* @0x15bd1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bd20 ldr r1, [pc, #-0x6f0] */
/* @0x15bd24 ldr r0, [pc, #-0x6f0] */
/* @0x15bd28 mov r2, #0 */
/* @0x15bd2c mov r3, r2 */
/* @0x15bd30 ldr r1, [r10, r1] */
/* @0x15bd34 add r0, pc, r0 */
/* @0x15bd38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bd3c ldr r1, [pc, #-0x704] */
/* @0x15bd40 ldr r0, [pc, #-0x704] */
/* @0x15bd44 mov r2, #0 */
/* @0x15bd48 mov r3, r2 */
/* @0x15bd4c ldr r1, [r10, r1] */
/* @0x15bd50 add r0, pc, r0 */
/* @0x15bd54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bd58 ldr r1, [pc, #-0x718] */
/* @0x15bd5c ldr r0, [pc, #-0x718] */
/* @0x15bd60 mov r2, #1 */
/* @0x15bd64 mov r3, r2 */
/* @0x15bd68 ldr r5, [r10, r1] */
/* @0x15bd6c add r0, pc, r0 */
/* @0x15bd70 mov r1, r5 */
/* @0x15bd74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bd78 ldr r0, [pc, #-0x730] */
/* @0x15bd7c mov r2, #1 */
/* @0x15bd80 mov r1, r5 */
/* @0x15bd84 mov r3, r2 */
/* @0x15bd88 add r0, pc, r0 */
/* @0x15bd8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bd90 ldr r0, [pc, #-0x744] */
/* @0x15bd94 mov r2, #1 */
/* @0x15bd98 mov r1, r5 */
/* @0x15bd9c mov r3, r2 */
/* @0x15bda0 add r0, pc, r0 */
/* @0x15bda4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bda8 ldr r0, [pc, #-0x758] */
/* @0x15bdac mov r1, r5 */
/* @0x15bdb0 mov r2, #0 */
/* @0x15bdb4 add r0, pc, r0 */
/* @0x15bdb8 mov r3, #1 */
/* @0x15bdbc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bdc0 ldr r0, [pc, #-0x76c] */
/* @0x15bdc4 mov r2, #1 */
/* @0x15bdc8 mov r1, r5 */
/* @0x15bdcc mov r3, r2 */
/* @0x15bdd0 add r0, pc, r0 */
/* @0x15bdd4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bdd8 ldr r0, [pc, #-0x780] */
/* @0x15bddc mov r2, #1 */
/* @0x15bde0 mov r1, r5 */
/* @0x15bde4 mov r3, r2 */
/* @0x15bde8 add r0, pc, r0 */
/* @0x15bdec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bdf0 ldr r0, [pc, #-0x794] */
/* @0x15bdf4 mov r2, #1 */
/* @0x15bdf8 mov r1, r5 */
/* @0x15bdfc mov r3, r2 */
/* @0x15be00 add r0, pc, r0 */
/* @0x15be04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15be08 ldr r0, [pc, #-0x7a8] */
/* @0x15be0c mov r2, #1 */
/* @0x15be10 mov r1, r5 */
/* @0x15be14 mov r3, r2 */
/* @0x15be18 add r0, pc, r0 */
/* @0x15be1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15be20 ldr r0, [pc, #-0x7bc] */
/* @0x15be24 mov r2, #1 */
/* @0x15be28 mov r1, r5 */
/* @0x15be2c mov r3, r2 */
/* @0x15be30 add r0, pc, r0 */
/* @0x15be34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15be38 ldr r0, [pc, #-0x7d0] */
/* @0x15be3c mov r2, #1 */
/* @0x15be40 mov r1, r5 */
/* @0x15be44 mov r3, r2 */
/* @0x15be48 add r0, pc, r0 */
/* @0x15be4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15be50 ldr r0, [pc, #-0x7e4] */
/* @0x15be54 mov r2, #1 */
/* @0x15be58 mov r1, r5 */
/* @0x15be5c mov r3, r2 */
/* @0x15be60 add r0, pc, r0 */
/* @0x15be64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15be68 ldr r0, [pc, #-0x7f8] */
/* @0x15be6c mov r2, #1 */
/* @0x15be70 mov r1, r5 */
/* @0x15be74 mov r3, r2 */
/* @0x15be78 add r0, pc, r0 */
/* @0x15be7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15be80 ldr r0, [pc, #-0x80c] */
/* @0x15be84 mov r2, #1 */
/* @0x15be88 mov r1, r5 */
/* @0x15be8c mov r3, r2 */
/* @0x15be90 add r0, pc, r0 */
/* @0x15be94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15be98 ldr r0, [pc, #-0x820] */
/* @0x15be9c mov r2, #1 */
/* @0x15bea0 mov r1, r5 */
/* @0x15bea4 mov r3, r2 */
/* @0x15bea8 add r0, pc, r0 */
/* @0x15beac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15beb0 ldr r0, [pc, #-0x834] */
/* @0x15beb4 mov r2, #1 */
/* @0x15beb8 mov r1, r5 */
/* @0x15bebc mov r3, r2 */
/* @0x15bec0 add r0, pc, r0 */
/* @0x15bec4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bec8 ldr r0, [pc, #-0x848] */
/* @0x15becc mov r2, #1 */
/* @0x15bed0 mov r1, r5 */
/* @0x15bed4 mov r3, r2 */
/* @0x15bed8 add r0, pc, r0 */
/* @0x15bedc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bee0 ldr r0, [pc, #-0x85c] */
/* @0x15bee4 mov r2, #1 */
/* @0x15bee8 mov r1, r5 */
/* @0x15beec mov r3, r2 */
/* @0x15bef0 add r0, pc, r0 */
/* @0x15bef4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bef8 ldr r0, [pc, #-0x870] */
/* @0x15befc mov r2, #1 */
/* @0x15bf00 mov r1, r5 */
/* @0x15bf04 mov r3, r2 */
/* @0x15bf08 add r0, pc, r0 */
/* @0x15bf0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bf10 ldr r0, [pc, #-0x884] */
/* @0x15bf14 mov r1, r5 */
/* @0x15bf18 mov r2, #2 */
/* @0x15bf1c add r0, pc, r0 */
/* @0x15bf20 mov r3, #1 */
/* @0x15bf24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bf28 ldr r0, [pc, #-0x898] */
/* @0x15bf2c mov r1, r5 */
/* @0x15bf30 mov r2, #2 */
/* @0x15bf34 add r0, pc, r0 */
/* @0x15bf38 mov r3, #1 */
/* @0x15bf3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bf40 ldr r0, [pc, #-0x8ac] */
/* @0x15bf44 mov r1, r5 */
/* @0x15bf48 mov r2, #2 */
/* @0x15bf4c add r0, pc, r0 */
/* @0x15bf50 mov r3, #1 */
/* @0x15bf54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bf58 ldr r0, [pc, #-0x8c0] */
/* @0x15bf5c mov r1, r5 */
/* @0x15bf60 mov r2, #4 */
/* @0x15bf64 add r0, pc, r0 */
/* @0x15bf68 mov r3, #1 */
/* @0x15bf6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bf70 ldr r0, [pc, #-0x8d4] */
/* @0x15bf74 mov r1, r5 */
/* @0x15bf78 mov r2, #2 */
/* @0x15bf7c add r0, pc, r0 */
/* @0x15bf80 mov r3, #1 */
/* @0x15bf84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bf88 ldr r0, [pc, #-0x8e8] */
/* @0x15bf8c mov r1, r5 */
/* @0x15bf90 mov r2, #0 */
/* @0x15bf94 add r0, pc, r0 */
/* @0x15bf98 mov r3, #1 */
/* @0x15bf9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bfa0 ldr r0, [pc, #-0x8fc] */
/* @0x15bfa4 mov r2, #1 */
/* @0x15bfa8 mov r1, r5 */
/* @0x15bfac mov r3, r2 */
/* @0x15bfb0 add r0, pc, r0 */
/* @0x15bfb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bfb8 ldr r0, [pc, #-0x910] */
/* @0x15bfbc mov r1, r5 */
/* @0x15bfc0 mov r2, #0 */
/* @0x15bfc4 add r0, pc, r0 */
/* @0x15bfc8 mov r3, #1 */
/* @0x15bfcc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bfd0 ldr r0, [pc, #-0x924] */
/* @0x15bfd4 mov r1, r5 */
/* @0x15bfd8 mov r2, #0 */
/* @0x15bfdc add r0, pc, r0 */
/* @0x15bfe0 mov r3, #1 */
/* @0x15bfe4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15bfe8 ldr r0, [pc, #-0x938] */
/* @0x15bfec mov r1, r5 */
/* @0x15bff0 mov r2, #0 */
/* @0x15bff4 add r0, pc, r0 */
/* @0x15bff8 mov r3, #1 */
/* @0x15bffc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c000 ldr r0, [pc, #-0x94c] */
/* @0x15c004 mov r1, r5 */
/* @0x15c008 mov r2, #0 */
/* @0x15c00c add r0, pc, r0 */
/* @0x15c010 mov r3, #1 */
/* @0x15c014 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c018 ldr r0, [pc, #-0x960] */
/* @0x15c01c mov r1, r5 */
/* @0x15c020 mov r2, #0 */
/* @0x15c024 add r0, pc, r0 */
/* @0x15c028 mov r3, #1 */
/* @0x15c02c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c030 ldr r0, [pc, #-0x974] */
/* @0x15c034 mov r1, r5 */
/* @0x15c038 mov r2, #0 */
/* @0x15c03c add r0, pc, r0 */
/* @0x15c040 mov r3, #1 */
/* @0x15c044 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c048 ldr r0, [pc, #-0x988] */
/* @0x15c04c mov r2, #1 */
/* @0x15c050 mov r1, r5 */
/* @0x15c054 mov r3, r2 */
/* @0x15c058 add r0, pc, r0 */
/* @0x15c05c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c060 ldr r0, [pc, #-0x99c] */
/* @0x15c064 mov r1, r5 */
/* @0x15c068 mov r2, #0 */
/* @0x15c06c add r0, pc, r0 */
/* @0x15c070 mov r3, #1 */
/* @0x15c074 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c078 ldr r0, [pc, #-0x9b0] */
/* @0x15c07c mov r1, r5 */
/* @0x15c080 mov r2, #0 */
/* @0x15c084 add r0, pc, r0 */
/* @0x15c088 mov r3, #1 */
/* @0x15c08c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c090 ldr r0, [pc, #-0x9c4] */
/* @0x15c094 mov r1, r5 */
/* @0x15c098 mov r2, #0 */
/* @0x15c09c add r0, pc, r0 */
/* @0x15c0a0 mov r3, #1 */
/* @0x15c0a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c0a8 ldr r0, [pc, #-0x9d8] */
/* @0x15c0ac mov r1, r5 */
/* @0x15c0b0 mov r2, #3 */
/* @0x15c0b4 add r0, pc, r0 */
/* @0x15c0b8 mov r3, #1 */
/* @0x15c0bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c0c0 ldr r0, [pc, #-0x9ec] */
/* @0x15c0c4 mov r1, r5 */
/* @0x15c0c8 mvn r2, #0 */
/* @0x15c0cc add r0, pc, r0 */
/* @0x15c0d0 mov r3, #1 */
/* @0x15c0d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c0d8 ldr r0, [pc, #-0xa00] */
/* @0x15c0dc mov r1, r5 */
/* @0x15c0e0 mvn r2, #0 */
/* @0x15c0e4 add r0, pc, r0 */
/* @0x15c0e8 mov r3, #1 */
/* @0x15c0ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c0f0 ldr r0, [pc, #-0xa14] */
/* @0x15c0f4 mov r1, r5 */
/* @0x15c0f8 mov r2, #2 */
/* @0x15c0fc add r0, pc, r0 */
/* @0x15c100 mov r3, #1 */
/* @0x15c104 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c108 ldr r0, [pc, #-0xa28] */
/* @0x15c10c mov r1, r5 */
/* @0x15c110 mov r2, #3 */
/* @0x15c114 add r0, pc, r0 */
/* @0x15c118 mov r3, #1 */
/* @0x15c11c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c120 ldr r0, [pc, #-0xa3c] */
/* @0x15c124 mov r1, r5 */
/* @0x15c128 mov r2, #3 */
/* @0x15c12c add r0, pc, r0 */
/* @0x15c130 mov r3, #1 */
/* @0x15c134 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c138 ldr r0, [pc, #-0xa50] */
/* @0x15c13c mov r1, r5 */
/* @0x15c140 mov r2, #3 */
/* @0x15c144 add r0, pc, r0 */
/* @0x15c148 mov r3, #1 */
/* @0x15c14c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c150 ldr r0, [pc, #-0xa64] */
/* @0x15c154 mov r1, r5 */
/* @0x15c158 mov r2, #2 */
/* @0x15c15c add r0, pc, r0 */
/* @0x15c160 mov r3, #1 */
/* @0x15c164 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c168 ldr r0, [pc, #-0xa78] */
/* @0x15c16c mov r1, r5 */
/* @0x15c170 mov r2, #2 */
/* @0x15c174 add r0, pc, r0 */
/* @0x15c178 mov r3, #1 */
/* @0x15c17c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c180 ldr r0, [pc, #-0xa8c] */
/* @0x15c184 mov r2, #1 */
/* @0x15c188 mov r1, r5 */
/* @0x15c18c mov r3, r2 */
/* @0x15c190 add r0, pc, r0 */
/* @0x15c194 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c198 ldr r0, [pc, #-0xaa0] */
/* @0x15c19c mov r2, #1 */
/* @0x15c1a0 mov r1, r5 */
/* @0x15c1a4 mov r3, r2 */
/* @0x15c1a8 add r0, pc, r0 */
/* @0x15c1ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c1b0 ldr r0, [pc, #-0xab4] */
/* @0x15c1b4 mov r2, #1 */
/* @0x15c1b8 mov r1, r5 */
/* @0x15c1bc mov r3, r2 */
/* @0x15c1c0 add r0, pc, r0 */
/* @0x15c1c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c1c8 ldr r0, [pc, #-0xac8] */
/* @0x15c1cc mov r1, r5 */
/* @0x15c1d0 mov r2, #2 */
/* @0x15c1d4 add r0, pc, r0 */
/* @0x15c1d8 mov r3, #1 */
/* @0x15c1dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c1e0 ldr r0, [pc, #-0xadc] */
/* @0x15c1e4 mov r1, r5 */
/* @0x15c1e8 mov r2, #6 */
/* @0x15c1ec add r0, pc, r0 */
/* @0x15c1f0 mov r3, #1 */
/* @0x15c1f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c1f8 ldr r0, [pc, #-0xaf0] */
/* @0x15c1fc mov r1, r5 */
/* @0x15c200 mov r2, #7 */
/* @0x15c204 add r0, pc, r0 */
/* @0x15c208 mov r3, #1 */
/* @0x15c20c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c210 ldr r0, [pc, #-0xb04] */
/* @0x15c214 mov r1, r5 */
/* @0x15c218 mov r2, #3 */
/* @0x15c21c add r0, pc, r0 */
/* @0x15c220 mov r3, #1 */
/* @0x15c224 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c228 ldr r0, [pc, #-0xb18] */
/* @0x15c22c mov r1, r5 */
/* @0x15c230 mov r2, #3 */
/* @0x15c234 add r0, pc, r0 */
/* @0x15c238 mov r3, #1 */
/* @0x15c23c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c240 ldr r0, [pc, #-0xb2c] */
/* @0x15c244 mov r1, r5 */
/* @0x15c248 mov r2, #4 */
/* @0x15c24c add r0, pc, r0 */
/* @0x15c250 mov r3, #1 */
/* @0x15c254 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c258 ldr r0, [pc, #-0xb40] */
/* @0x15c25c mov r1, r5 */
/* @0x15c260 mov r2, #3 */
/* @0x15c264 add r0, pc, r0 */
/* @0x15c268 mov r3, #1 */
/* @0x15c26c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c270 ldr r0, [pc, #-0xb54] */
/* @0x15c274 mov r2, #1 */
/* @0x15c278 mov r1, r5 */
/* @0x15c27c mov r3, r2 */
/* @0x15c280 add r0, pc, r0 */
/* @0x15c284 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c288 ldr r0, [pc, #-0xb68] */
/* @0x15c28c mov r2, #1 */
/* @0x15c290 mov r1, r5 */
/* @0x15c294 mov r3, r2 */
/* @0x15c298 add r0, pc, r0 */
/* @0x15c29c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c2a0 ldr r0, [pc, #-0xb7c] */
/* @0x15c2a4 mov r2, #1 */
/* @0x15c2a8 mov r1, r5 */
/* @0x15c2ac mov r3, r2 */
/* @0x15c2b0 add r0, pc, r0 */
/* @0x15c2b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c2b8 ldr r0, [pc, #-0xb90] */
/* @0x15c2bc mov r2, #1 */
/* @0x15c2c0 mov r1, r5 */
/* @0x15c2c4 mov r3, r2 */
/* @0x15c2c8 add r0, pc, r0 */
/* @0x15c2cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c2d0 ldr r0, [pc, #-0xba4] */
/* @0x15c2d4 mov r1, r5 */
/* @0x15c2d8 mov r2, #3 */
/* @0x15c2dc add r0, pc, r0 */
/* @0x15c2e0 mov r3, #1 */
/* @0x15c2e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c2e8 ldr r0, [pc, #-0xbb8] */
/* @0x15c2ec mov r1, r5 */
/* @0x15c2f0 mov r2, #2 */
/* @0x15c2f4 add r0, pc, r0 */
/* @0x15c2f8 mov r3, #1 */
/* @0x15c2fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c300 ldr r0, [pc, #-0xbcc] */
/* @0x15c304 mov r1, r5 */
/* @0x15c308 mov r2, #4 */
/* @0x15c30c add r0, pc, r0 */
/* @0x15c310 mov r3, #1 */
/* @0x15c314 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c318 ldr r0, [pc, #-0xbe0] */
/* @0x15c31c mov r1, r5 */
/* @0x15c320 mov r2, #3 */
/* @0x15c324 add r0, pc, r0 */
/* @0x15c328 mov r3, #1 */
/* @0x15c32c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c330 ldr r0, [pc, #-0xbf4] */
/* @0x15c334 mov r1, r5 */
/* @0x15c338 mov r2, #2 */
/* @0x15c33c add r0, pc, r0 */
/* @0x15c340 mov r3, #1 */
/* @0x15c344 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c348 ldr r0, [pc, #-0xc08] */
/* @0x15c34c mov r1, r5 */
/* @0x15c350 mov r2, #2 */
/* @0x15c354 add r0, pc, r0 */
/* @0x15c358 mov r3, #1 */
/* @0x15c35c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c360 ldr r0, [pc, #-0xc1c] */
/* @0x15c364 mov r2, #1 */
/* @0x15c368 mov r1, r5 */
/* @0x15c36c mov r3, r2 */
/* @0x15c370 add r0, pc, r0 */
/* @0x15c374 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c378 ldr r0, [pc, #-0xc30] */
/* @0x15c37c mov r2, #1 */
/* @0x15c380 mov r1, r5 */
/* @0x15c384 mov r3, r2 */
/* @0x15c388 add r0, pc, r0 */
/* @0x15c38c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c390 ldr r0, [pc, #-0xc44] */
/* @0x15c394 mov r1, r5 */
/* @0x15c398 mov r2, #4 */
/* @0x15c39c add r0, pc, r0 */
/* @0x15c3a0 mov r3, #1 */
/* @0x15c3a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c3a8 ldr r0, [pc, #-0xc58] */
/* @0x15c3ac mov r1, r5 */
/* @0x15c3b0 mov r2, #0 */
/* @0x15c3b4 add r0, pc, r0 */
/* @0x15c3b8 mov r3, #1 */
/* @0x15c3bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c3c0 ldr r0, [pc, #-0xc6c] */
/* @0x15c3c4 mov r2, #1 */
/* @0x15c3c8 mov r1, r5 */
/* @0x15c3cc mov r3, r2 */
/* @0x15c3d0 add r0, pc, r0 */
/* @0x15c3d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c3d8 ldr r0, [pc, #-0xc80] */
/* @0x15c3dc mov r2, #1 */
/* @0x15c3e0 mov r1, r5 */
/* @0x15c3e4 mov r3, r2 */
/* @0x15c3e8 add r0, pc, r0 */
/* @0x15c3ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c3f0 ldr r0, [pc, #-0xc94] */
/* @0x15c3f4 mov r2, #1 */
/* @0x15c3f8 mov r1, r5 */
/* @0x15c3fc mov r3, r2 */
/* @0x15c400 add r0, pc, r0 */
/* @0x15c404 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c408 ldr r0, [pc, #-0xca8] */
/* @0x15c40c mov r2, #1 */
/* @0x15c410 mov r1, r5 */
/* @0x15c414 mov r3, r2 */
/* @0x15c418 add r0, pc, r0 */
/* @0x15c41c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c420 ldr r0, [pc, #-0xcbc] */
/* @0x15c424 mov r2, #1 */
/* @0x15c428 mov r1, r5 */
/* @0x15c42c mov r3, r2 */
/* @0x15c430 add r0, pc, r0 */
/* @0x15c434 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c438 ldr r0, [pc, #-0xcd0] */
/* @0x15c43c mov r2, #1 */
/* @0x15c440 mov r1, r5 */
/* @0x15c444 mov r3, r2 */
/* @0x15c448 add r0, pc, r0 */
/* @0x15c44c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c450 ldr r0, [pc, #-0xce4] */
/* @0x15c454 mov r2, #1 */
/* @0x15c458 mov r1, r5 */
/* @0x15c45c mov r3, r2 */
/* @0x15c460 add r0, pc, r0 */
/* @0x15c464 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c468 ldr r0, [pc, #-0xcf8] */
/* @0x15c46c mov r2, #1 */
/* @0x15c470 mov r1, r5 */
/* @0x15c474 mov r3, r2 */
/* @0x15c478 add r0, pc, r0 */
/* @0x15c47c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c480 ldr r0, [pc, #-0xd0c] */
/* @0x15c484 mov r2, #1 */
/* @0x15c488 mov r1, r5 */
/* @0x15c48c mov r3, r2 */
/* @0x15c490 add r0, pc, r0 */
/* @0x15c494 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c498 ldr r0, [pc, #-0xd20] */
/* @0x15c49c mov r1, r5 */
/* @0x15c4a0 mvn r2, #0 */
/* @0x15c4a4 add r0, pc, r0 */
/* @0x15c4a8 mov r3, #1 */
/* @0x15c4ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c4b0 ldr r0, [pc, #-0xd34] */
/* @0x15c4b4 mov r2, #1 */
/* @0x15c4b8 mov r1, r5 */
/* @0x15c4bc mov r3, r2 */
/* @0x15c4c0 add r0, pc, r0 */
/* @0x15c4c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c4c8 ldr r0, [pc, #-0xd48] */
/* @0x15c4cc mov r2, #1 */
/* @0x15c4d0 mov r1, r5 */
/* @0x15c4d4 mov r3, r2 */
/* @0x15c4d8 add r0, pc, r0 */
/* @0x15c4dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c4e0 ldr r0, [pc, #-0xd5c] */
/* @0x15c4e4 mov r2, #1 */
/* @0x15c4e8 mov r1, r5 */
/* @0x15c4ec mov r3, r2 */
/* @0x15c4f0 add r0, pc, r0 */
/* @0x15c4f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c4f8 ldr r0, [pc, #-0xd70] */
/* @0x15c4fc mov r2, #1 */
/* @0x15c500 mov r1, r5 */
/* @0x15c504 mov r3, r2 */
/* @0x15c508 add r0, pc, r0 */
/* @0x15c50c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c510 ldr r0, [pc, #-0xd84] */
/* @0x15c514 mov r2, #1 */
/* @0x15c518 mov r1, r5 */
/* @0x15c51c mov r3, r2 */
/* @0x15c520 add r0, pc, r0 */
/* @0x15c524 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c528 ldr r0, [pc, #-0xd98] */
/* @0x15c52c mov r2, #1 */
/* @0x15c530 mov r1, r5 */
/* @0x15c534 mov r3, r2 */
/* @0x15c538 add r0, pc, r0 */
/* @0x15c53c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c540 ldr r0, [pc, #-0xdac] */
/* @0x15c544 mov r1, r5 */
/* @0x15c548 mov r2, #2 */
/* @0x15c54c add r0, pc, r0 */
/* @0x15c550 mov r3, #1 */
/* @0x15c554 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c558 ldr r0, [pc, #-0xdc0] */
/* @0x15c55c mov r1, r5 */
/* @0x15c560 mov r2, #2 */
/* @0x15c564 add r0, pc, r0 */
/* @0x15c568 mov r3, #1 */
/* @0x15c56c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c570 ldr r0, [pc, #-0xdd4] */
/* @0x15c574 mov r1, r5 */
/* @0x15c578 mov r2, #2 */
/* @0x15c57c add r0, pc, r0 */
/* @0x15c580 mov r3, #1 */
/* @0x15c584 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c588 ldr r0, [pc, #-0xde8] */
/* @0x15c58c mov r1, r5 */
/* @0x15c590 mov r2, #4 */
/* @0x15c594 add r0, pc, r0 */
/* @0x15c598 mov r3, #1 */
/* @0x15c59c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c5a0 ldr r0, [pc, #-0xdfc] */
/* @0x15c5a4 mov r1, r5 */
/* @0x15c5a8 mov r2, #2 */
/* @0x15c5ac add r0, pc, r0 */
/* @0x15c5b0 mov r3, #1 */
/* @0x15c5b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c5b8 ldr r0, [pc, #-0xe10] */
/* @0x15c5bc mov r1, r5 */
/* @0x15c5c0 mov r2, #0 */
/* @0x15c5c4 add r0, pc, r0 */
/* @0x15c5c8 mov r3, #1 */
/* @0x15c5cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c5d0 ldr r0, [pc, #-0xe24] */
/* @0x15c5d4 mov r1, r5 */
/* @0x15c5d8 mov r2, #4 */
/* @0x15c5dc add r0, pc, r0 */
/* @0x15c5e0 mov r3, #1 */
/* @0x15c5e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c5e8 ldr r0, [pc, #-0xe38] */
/* @0x15c5ec mov r2, #1 */
/* @0x15c5f0 mov r1, r5 */
/* @0x15c5f4 mov r3, r2 */
/* @0x15c5f8 add r0, pc, r0 */
/* @0x15c5fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c600 ldr r0, [pc, #-0xe4c] */
/* @0x15c604 mov r1, r5 */
/* @0x15c608 mov r2, #0 */
/* @0x15c60c add r0, pc, r0 */
/* @0x15c610 mov r3, #1 */
/* @0x15c614 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c618 ldr r0, [pc, #-0xe60] */
/* @0x15c61c mov r1, r5 */
/* @0x15c620 mov r2, #0 */
/* @0x15c624 add r0, pc, r0 */
/* @0x15c628 mov r3, #1 */
/* @0x15c62c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c630 ldr r0, [pc, #-0xe74] */
/* @0x15c634 mov r1, r5 */
/* @0x15c638 mov r2, #0 */
/* @0x15c63c add r0, pc, r0 */
/* @0x15c640 mov r3, #1 */
/* @0x15c644 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c648 ldr r0, [pc, #-0xe88] */
/* @0x15c64c mov r1, r5 */
/* @0x15c650 mov r2, #0 */
/* @0x15c654 add r0, pc, r0 */
/* @0x15c658 mov r3, #1 */
/* @0x15c65c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c660 ldr r0, [pc, #-0xe9c] */
/* @0x15c664 mov r1, r5 */
/* @0x15c668 mov r2, #0 */
/* @0x15c66c add r0, pc, r0 */
/* @0x15c670 mov r3, #1 */
/* @0x15c674 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c678 ldr r0, [pc, #-0xeb0] */
/* @0x15c67c mov r1, r5 */
/* @0x15c680 mov r2, #0 */
/* @0x15c684 add r0, pc, r0 */
/* @0x15c688 mov r3, #1 */
/* @0x15c68c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c690 ldr r0, [pc, #-0xec4] */
/* @0x15c694 mov r2, #1 */
/* @0x15c698 mov r1, r5 */
/* @0x15c69c mov r3, r2 */
/* @0x15c6a0 add r0, pc, r0 */
/* @0x15c6a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c6a8 ldr r0, [pc, #-0xed8] */
/* @0x15c6ac mov r1, r5 */
/* @0x15c6b0 mov r2, #0 */
/* @0x15c6b4 add r0, pc, r0 */
/* @0x15c6b8 mov r3, #1 */
/* @0x15c6bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c6c0 ldr r0, [pc, #-0xeec] */
/* @0x15c6c4 mov r1, r5 */
/* @0x15c6c8 mov r2, #0 */
/* @0x15c6cc add r0, pc, r0 */
/* @0x15c6d0 mov r3, #1 */
/* @0x15c6d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c6d8 ldr r0, [pc, #-0xf00] */
/* @0x15c6dc mov r1, r5 */
/* @0x15c6e0 mov r2, #0 */
/* @0x15c6e4 add r0, pc, r0 */
/* @0x15c6e8 mov r3, #1 */
/* @0x15c6ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c6f0 ldr r0, [pc, #-0xf14] */
/* @0x15c6f4 mov r1, r5 */
/* @0x15c6f8 mov r2, #3 */
/* @0x15c6fc add r0, pc, r0 */
/* @0x15c700 mov r3, #1 */
/* @0x15c704 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c708 ldr r0, [pc, #-0xf28] */
/* @0x15c70c mov r1, r5 */
/* @0x15c710 mvn r2, #0 */
/* @0x15c714 add r0, pc, r0 */
/* @0x15c718 mov r3, #1 */
/* @0x15c71c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c720 ldr r0, [pc, #-0xf3c] */
/* @0x15c724 mov r1, r5 */
/* @0x15c728 mvn r2, #0 */
/* @0x15c72c add r0, pc, r0 */
/* @0x15c730 mov r3, #1 */
/* @0x15c734 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c738 ldr r0, [pc, #-0xf50] */
/* @0x15c73c mov r1, r5 */
/* @0x15c740 mov r2, #2 */
/* @0x15c744 add r0, pc, r0 */
/* @0x15c748 mov r3, #1 */
/* @0x15c74c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c750 ldr r0, [pc, #-0xf64] */
/* @0x15c754 mov r1, r5 */
/* @0x15c758 mov r2, #3 */
/* @0x15c75c add r0, pc, r0 */
/* @0x15c760 mov r3, #1 */
/* @0x15c764 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c768 ldr r0, [pc, #-0xf78] */
/* @0x15c76c mov r1, r5 */
/* @0x15c770 mov r2, #3 */
/* @0x15c774 add r0, pc, r0 */
/* @0x15c778 mov r3, #1 */
/* @0x15c77c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c780 ldr r0, [pc, #-0xf8c] */
/* @0x15c784 mov r1, r5 */
/* @0x15c788 mov r2, #3 */
/* @0x15c78c add r0, pc, r0 */
/* @0x15c790 mov r3, #1 */
/* @0x15c794 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c798 ldr r0, [pc, #-0xfa0] */
/* @0x15c79c mov r1, r5 */
/* @0x15c7a0 mov r2, #2 */
/* @0x15c7a4 add r0, pc, r0 */
/* @0x15c7a8 mov r3, #1 */
/* @0x15c7ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c7b0 ldr r0, [pc, #-0xfb4] */
/* @0x15c7b4 mov r1, r5 */
/* @0x15c7b8 mov r2, #2 */
/* @0x15c7bc add r0, pc, r0 */
/* @0x15c7c0 mov r3, #1 */
/* @0x15c7c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c7c8 ldr r0, [pc, #-0xfc8] */
/* @0x15c7cc mov r2, #1 */
/* @0x15c7d0 mov r1, r5 */
/* @0x15c7d4 mov r3, r2 */
/* @0x15c7d8 add r0, pc, r0 */
/* @0x15c7dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c7e0 ldr r0, [pc, #-0xfdc] */
/* @0x15c7e4 mov r2, #1 */
/* @0x15c7e8 mov r1, r5 */
/* @0x15c7ec mov r3, r2 */
/* @0x15c7f0 add r0, pc, r0 */
/* @0x15c7f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c7f8 ldr r0, [pc, #-0xff0] */
/* @0x15c7fc mov r2, #1 */
/* @0x15c800 mov r1, r5 */
/* @0x15c804 mov r3, r2 */
/* @0x15c808 add r0, pc, r0 */
/* @0x15c80c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c810 ldr r0, [pc, #0x79c] */
/* @0x15c814 mov r1, r5 */
/* @0x15c818 mov r2, #2 */
/* @0x15c81c add r0, pc, r0 */
/* @0x15c820 mov r3, #1 */
/* @0x15c824 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c828 ldr r0, [pc, #0x788] */
/* @0x15c82c mov r1, r5 */
/* @0x15c830 mov r2, #6 */
/* @0x15c834 add r0, pc, r0 */
/* @0x15c838 mov r3, #1 */
/* @0x15c83c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c840 ldr r0, [pc, #0x774] */
/* @0x15c844 mov r1, r5 */
/* @0x15c848 mov r2, #7 */
/* @0x15c84c add r0, pc, r0 */
/* @0x15c850 mov r3, #1 */
/* @0x15c854 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c858 ldr r0, [pc, #0x760] */
/* @0x15c85c mov r1, r5 */
/* @0x15c860 mov r2, #3 */
/* @0x15c864 add r0, pc, r0 */
/* @0x15c868 mov r3, #1 */
/* @0x15c86c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c870 ldr r0, [pc, #0x74c] */
/* @0x15c874 mov r1, r5 */
/* @0x15c878 mov r2, #3 */
/* @0x15c87c add r0, pc, r0 */
/* @0x15c880 mov r3, #1 */
/* @0x15c884 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c888 ldr r0, [pc, #0x738] */
/* @0x15c88c mov r1, r5 */
/* @0x15c890 mov r2, #4 */
/* @0x15c894 add r0, pc, r0 */
/* @0x15c898 mov r3, #1 */
/* @0x15c89c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c8a0 ldr r0, [pc, #0x724] */
/* @0x15c8a4 mov r1, r5 */
/* @0x15c8a8 mov r2, #3 */
/* @0x15c8ac add r0, pc, r0 */
/* @0x15c8b0 mov r3, #1 */
/* @0x15c8b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c8b8 ldr r0, [pc, #0x710] */
/* @0x15c8bc mov r2, #1 */
/* @0x15c8c0 mov r1, r5 */
/* @0x15c8c4 mov r3, r2 */
/* @0x15c8c8 add r0, pc, r0 */
/* @0x15c8cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c8d0 ldr r0, [pc, #0x6fc] */
/* @0x15c8d4 mov r2, #1 */
/* @0x15c8d8 mov r1, r5 */
/* @0x15c8dc mov r3, r2 */
/* @0x15c8e0 add r0, pc, r0 */
/* @0x15c8e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c8e8 ldr r0, [pc, #0x6e8] */
/* @0x15c8ec mov r2, #1 */
/* @0x15c8f0 mov r1, r5 */
/* @0x15c8f4 mov r3, r2 */
/* @0x15c8f8 add r0, pc, r0 */
/* @0x15c8fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c900 ldr r0, [pc, #0x6d4] */
/* @0x15c904 mov r2, #1 */
/* @0x15c908 mov r1, r5 */
/* @0x15c90c mov r3, r2 */
/* @0x15c910 add r0, pc, r0 */
/* @0x15c914 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c918 ldr r0, [pc, #0x6c0] */
/* @0x15c91c mov r1, r5 */
/* @0x15c920 mov r2, #3 */
/* @0x15c924 add r0, pc, r0 */
/* @0x15c928 mov r3, #1 */
/* @0x15c92c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c930 ldr r0, [pc, #0x6ac] */
/* @0x15c934 mov r1, r5 */
/* @0x15c938 mov r2, #2 */
/* @0x15c93c add r0, pc, r0 */
/* @0x15c940 mov r3, #1 */
/* @0x15c944 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c948 ldr r0, [pc, #0x698] */
/* @0x15c94c mov r1, r5 */
/* @0x15c950 mov r2, #4 */
/* @0x15c954 add r0, pc, r0 */
/* @0x15c958 mov r3, #1 */
/* @0x15c95c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c960 ldr r0, [pc, #0x684] */
/* @0x15c964 mov r1, r5 */
/* @0x15c968 mov r2, #3 */
/* @0x15c96c add r0, pc, r0 */
/* @0x15c970 mov r3, #1 */
/* @0x15c974 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c978 ldr r0, [pc, #0x670] */
/* @0x15c97c mov r1, r5 */
/* @0x15c980 mov r2, #2 */
/* @0x15c984 add r0, pc, r0 */
/* @0x15c988 mov r3, #1 */
/* @0x15c98c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c990 ldr r0, [pc, #0x65c] */
/* @0x15c994 mov r1, r5 */
/* @0x15c998 mov r2, #2 */
/* @0x15c99c add r0, pc, r0 */
/* @0x15c9a0 mov r3, #1 */
/* @0x15c9a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c9a8 ldr r0, [pc, #0x648] */
/* @0x15c9ac mov r1, r5 */
/* @0x15c9b0 mov r2, #2 */
/* @0x15c9b4 add r0, pc, r0 */
/* @0x15c9b8 mov r3, #1 */
/* @0x15c9bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c9c0 ldr r0, [pc, #0x634] */
/* @0x15c9c4 mov r2, #1 */
/* @0x15c9c8 mov r1, r5 */
/* @0x15c9cc mov r3, r2 */
/* @0x15c9d0 add r0, pc, r0 */
/* @0x15c9d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c9d8 ldr r0, [pc, #0x620] */
/* @0x15c9dc mov r1, r5 */
/* @0x15c9e0 mov r2, #4 */
/* @0x15c9e4 add r0, pc, r0 */
/* @0x15c9e8 mov r3, #1 */
/* @0x15c9ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15c9f0 ldr r0, [pc, #0x60c] */
/* @0x15c9f4 mov r1, r5 */
/* @0x15c9f8 mov r2, #0 */
/* @0x15c9fc add r0, pc, r0 */
/* @0x15ca00 mov r3, #1 */
/* @0x15ca04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ca08 ldr r0, [pc, #0x5f8] */
/* @0x15ca0c mov r2, #1 */
/* @0x15ca10 mov r1, r5 */
/* @0x15ca14 mov r3, r2 */
/* @0x15ca18 add r0, pc, r0 */
/* @0x15ca1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ca20 ldr r0, [pc, #0x5e4] */
/* @0x15ca24 mov r1, r5 */
/* @0x15ca28 mov r2, #2 */
/* @0x15ca2c add r0, pc, r0 */
/* @0x15ca30 mov r3, #1 */
/* @0x15ca34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ca38 ldr r0, [pc, #0x5d0] */
/* @0x15ca3c mov r2, #1 */
/* @0x15ca40 mov r1, r5 */
/* @0x15ca44 mov r3, r2 */
/* @0x15ca48 add r0, pc, r0 */
/* @0x15ca4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ca50 ldr r0, [pc, #0x5bc] */
/* @0x15ca54 mov r1, r5 */
/* @0x15ca58 mov r2, #3 */
/* @0x15ca5c add r0, pc, r0 */
/* @0x15ca60 mov r3, #1 */
/* @0x15ca64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ca68 ldr r0, [pc, #0x5a8] */
/* @0x15ca6c mov r1, r5 */
/* @0x15ca70 mov r2, #0 */
/* @0x15ca74 add r0, pc, r0 */
/* @0x15ca78 mov r3, #1 */
/* @0x15ca7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ca80 ldr r0, [pc, #0x594] */
/* @0x15ca84 mov r1, r5 */
/* @0x15ca88 mov r2, #2 */
/* @0x15ca8c add r0, pc, r0 */
/* @0x15ca90 mov r3, #1 */
/* @0x15ca94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ca98 ldr r0, [pc, #0x580] */
/* @0x15ca9c mov r1, r5 */
/* @0x15caa0 mov r2, #3 */
/* @0x15caa4 add r0, pc, r0 */
/* @0x15caa8 mov r3, #1 */
/* @0x15caac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cab0 ldr r0, [pc, #0x56c] */
/* @0x15cab4 mov r1, r5 */
/* @0x15cab8 mov r2, #4 */
/* @0x15cabc add r0, pc, r0 */
/* @0x15cac0 mov r3, #1 */
/* @0x15cac4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cac8 ldr r0, [pc, #0x558] */
/* @0x15cacc mov r1, r5 */
/* @0x15cad0 mov r2, #2 */
/* @0x15cad4 add r0, pc, r0 */
/* @0x15cad8 mov r3, #1 */
/* @0x15cadc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cae0 ldr r0, [pc, #0x544] */
/* @0x15cae4 mov r1, r5 */
/* @0x15cae8 mov r2, #0 */
/* @0x15caec add r0, pc, r0 */
/* @0x15caf0 mov r3, #1 */
/* @0x15caf4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15caf8 ldr r0, [pc, #0x530] */
/* @0x15cafc mov r1, r5 */
/* @0x15cb00 mov r2, #4 */
/* @0x15cb04 add r0, pc, r0 */
/* @0x15cb08 mov r3, #1 */
/* @0x15cb0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cb10 ldr r0, [pc, #0x51c] */
/* @0x15cb14 mov r2, #1 */
/* @0x15cb18 mov r1, r5 */
/* @0x15cb1c mov r3, r2 */
/* @0x15cb20 add r0, pc, r0 */
/* @0x15cb24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cb28 ldr r0, [pc, #0x508] */
/* @0x15cb2c mov r1, r5 */
/* @0x15cb30 mov r2, #0 */
/* @0x15cb34 add r0, pc, r0 */
/* @0x15cb38 mov r3, #1 */
/* @0x15cb3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cb40 ldr r0, [pc, #0x4f4] */
/* @0x15cb44 mov r2, #1 */
/* @0x15cb48 mov r1, r5 */
/* @0x15cb4c mov r3, r2 */
/* @0x15cb50 add r0, pc, r0 */
/* @0x15cb54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cb58 ldr r0, [pc, #0x4e0] */
/* @0x15cb5c mov r1, r5 */
/* @0x15cb60 mov r2, #0 */
/* @0x15cb64 add r0, pc, r0 */
/* @0x15cb68 mov r3, #1 */
/* @0x15cb6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cb70 ldr r0, [pc, #0x4cc] */
/* @0x15cb74 mov r1, r5 */
/* @0x15cb78 mov r2, #2 */
/* @0x15cb7c add r0, pc, r0 */
/* @0x15cb80 mov r3, #1 */
/* @0x15cb84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cb88 ldr r0, [pc, #0x4b8] */
/* @0x15cb8c mov r1, r5 */
/* @0x15cb90 mov r2, #2 */
/* @0x15cb94 add r0, pc, r0 */
/* @0x15cb98 mov r3, #1 */
/* @0x15cb9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cba0 ldr r0, [pc, #0x4a4] */
/* @0x15cba4 mov r2, #1 */
/* @0x15cba8 mov r1, r5 */
/* @0x15cbac mov r3, r2 */
/* @0x15cbb0 add r0, pc, r0 */
/* @0x15cbb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cbb8 ldr r0, [pc, #0x490] */
/* @0x15cbbc mov r2, #1 */
/* @0x15cbc0 mov r1, r5 */
/* @0x15cbc4 mov r3, r2 */
/* @0x15cbc8 add r0, pc, r0 */
/* @0x15cbcc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cbd0 ldr r0, [pc, #0x47c] */
/* @0x15cbd4 mov r2, #1 */
/* @0x15cbd8 mov r1, r5 */
/* @0x15cbdc mov r3, r2 */
/* @0x15cbe0 add r0, pc, r0 */
/* @0x15cbe4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cbe8 ldr r0, [pc, #0x468] */
/* @0x15cbec mov r2, #1 */
/* @0x15cbf0 mov r1, r5 */
/* @0x15cbf4 mov r3, r2 */
/* @0x15cbf8 add r0, pc, r0 */
/* @0x15cbfc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cc00 ldr r0, [pc, #0x454] */
/* @0x15cc04 mov r2, #1 */
/* @0x15cc08 mov r1, r5 */
/* @0x15cc0c mov r3, r2 */
/* @0x15cc10 add r0, pc, r0 */
/* @0x15cc14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cc18 ldr r0, [pc, #0x440] */
/* @0x15cc1c mov r1, r5 */
/* @0x15cc20 mov r2, #0 */
/* @0x15cc24 add r0, pc, r0 */
/* @0x15cc28 mov r3, #1 */
/* @0x15cc2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cc30 ldr r0, [pc, #0x42c] */
/* @0x15cc34 mov r1, r5 */
/* @0x15cc38 mov r2, #3 */
/* @0x15cc3c add r0, pc, r0 */
/* @0x15cc40 mov r3, #1 */
/* @0x15cc44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cc48 ldr r0, [pc, #0x418] */
/* @0x15cc4c mov r1, r5 */
/* @0x15cc50 mov r2, #0 */
/* @0x15cc54 add r0, pc, r0 */
/* @0x15cc58 mov r3, #1 */
/* @0x15cc5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cc60 ldr r0, [pc, #0x404] */
/* @0x15cc64 mov r2, #1 */
/* @0x15cc68 mov r1, r5 */
/* @0x15cc6c mov r3, r2 */
/* @0x15cc70 add r0, pc, r0 */
/* @0x15cc74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cc78 ldr r0, [pc, #0x3f0] */
/* @0x15cc7c mov r2, #1 */
/* @0x15cc80 mov r1, r5 */
/* @0x15cc84 mov r3, r2 */
/* @0x15cc88 add r0, pc, r0 */
/* @0x15cc8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cc90 ldr r0, [pc, #0x3dc] */
/* @0x15cc94 mov r2, #1 */
/* @0x15cc98 mov r1, r5 */
/* @0x15cc9c mov r3, r2 */
/* @0x15cca0 add r0, pc, r0 */
/* @0x15cca4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cca8 ldr r0, [pc, #0x3c8] */
/* @0x15ccac mov r1, r5 */
/* @0x15ccb0 mov r2, #2 */
/* @0x15ccb4 add r0, pc, r0 */
/* @0x15ccb8 mov r3, #1 */
/* @0x15ccbc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ccc0 ldr r0, [pc, #0x3b4] */
/* @0x15ccc4 mov r1, r5 */
/* @0x15ccc8 mov r2, #0 */
/* @0x15cccc add r0, pc, r0 */
/* @0x15ccd0 mov r3, #1 */
/* @0x15ccd4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ccd8 ldr r0, [pc, #0x3a0] */
/* @0x15ccdc mov r2, #1 */
/* @0x15cce0 mov r1, r5 */
/* @0x15cce4 mov r3, r2 */
/* @0x15cce8 add r0, pc, r0 */
/* @0x15ccec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ccf0 ldr r0, [pc, #0x38c] */
/* @0x15ccf4 mov r1, r5 */
/* @0x15ccf8 mov r2, #4 */
/* @0x15ccfc add r0, pc, r0 */
/* @0x15cd00 mov r3, #1 */
/* @0x15cd04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cd08 ldr r0, [pc, #0x378] */
/* @0x15cd0c mov r1, r5 */
/* @0x15cd10 mov r2, #3 */
/* @0x15cd14 add r0, pc, r0 */
/* @0x15cd18 mov r3, #1 */
/* @0x15cd1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cd20 ldr r0, [pc, #0x364] */
/* @0x15cd24 mov r1, r5 */
/* @0x15cd28 mov r2, #0 */
/* @0x15cd2c add r0, pc, r0 */
/* @0x15cd30 mov r3, #1 */
/* @0x15cd34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cd38 ldr r0, [pc, #0x350] */
/* @0x15cd3c mov r2, #1 */
/* @0x15cd40 mov r1, r5 */
/* @0x15cd44 mov r3, r2 */
/* @0x15cd48 add r0, pc, r0 */
/* @0x15cd4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cd50 ldr r0, [pc, #0x33c] */
/* @0x15cd54 mov r1, r5 */
/* @0x15cd58 mov r2, #3 */
/* @0x15cd5c add r0, pc, r0 */
/* @0x15cd60 mov r3, #1 */
/* @0x15cd64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cd68 ldr r0, [pc, #0x328] */
/* @0x15cd6c mov r1, r5 */
/* @0x15cd70 mov r2, #3 */
/* @0x15cd74 add r0, pc, r0 */
/* @0x15cd78 mov r3, #1 */
/* @0x15cd7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cd80 ldr r0, [pc, #0x314] */
/* @0x15cd84 mov r1, r5 */
/* @0x15cd88 mov r2, #0 */
/* @0x15cd8c add r0, pc, r0 */
/* @0x15cd90 mov r3, #1 */
/* @0x15cd94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cd98 ldr r0, [pc, #0x300] */
/* @0x15cd9c mov r1, r5 */
/* @0x15cda0 mov r2, #3 */
/* @0x15cda4 add r0, pc, r0 */
/* @0x15cda8 mov r3, #1 */
/* @0x15cdac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cdb0 ldr r0, [pc, #0x2ec] */
/* @0x15cdb4 mov r2, #1 */
/* @0x15cdb8 mov r1, r5 */
/* @0x15cdbc mov r3, r2 */
/* @0x15cdc0 add r0, pc, r0 */
/* @0x15cdc4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cdc8 ldr r0, [pc, #0x2d8] */
/* @0x15cdcc mov r1, r5 */
/* @0x15cdd0 mov r2, #0 */
/* @0x15cdd4 add r0, pc, r0 */
/* @0x15cdd8 mov r3, #1 */
/* @0x15cddc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cde0 ldr r0, [pc, #0x2c4] */
/* @0x15cde4 mov r2, #1 */
/* @0x15cde8 mov r1, r5 */
/* @0x15cdec mov r3, r2 */
/* @0x15cdf0 add r0, pc, r0 */
/* @0x15cdf4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cdf8 ldr r0, [pc, #0x2b0] */
/* @0x15cdfc mov r1, r5 */
/* @0x15ce00 mov r2, #2 */
/* @0x15ce04 add r0, pc, r0 */
/* @0x15ce08 mov r3, #1 */
/* @0x15ce0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ce10 ldr r0, [pc, #0x29c] */
/* @0x15ce14 mov r1, r5 */
/* @0x15ce18 mov r2, #4 */
/* @0x15ce1c add r0, pc, r0 */
/* @0x15ce20 mov r3, #1 */
/* @0x15ce24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ce28 ldr r0, [pc, #0x288] */
/* @0x15ce2c mov r1, r5 */
/* @0x15ce30 mov r2, #2 */
/* @0x15ce34 add r0, pc, r0 */
/* @0x15ce38 mov r3, #1 */
/* @0x15ce3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ce40 ldr r0, [pc, #0x274] */
/* @0x15ce44 mov r1, r5 */
/* @0x15ce48 mov r2, #3 */
/* @0x15ce4c add r0, pc, r0 */
/* @0x15ce50 mov r3, #1 */
/* @0x15ce54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ce58 ldr r0, [pc, #0x260] */
/* @0x15ce5c mov r1, r5 */
/* @0x15ce60 mov r2, #2 */
/* @0x15ce64 add r0, pc, r0 */
/* @0x15ce68 mov r3, #1 */
/* @0x15ce6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ce70 ldr r0, [pc, #0x24c] */
/* @0x15ce74 mov r1, r5 */
/* @0x15ce78 mov r2, #2 */
/* @0x15ce7c add r0, pc, r0 */
/* @0x15ce80 mov r3, #1 */
/* @0x15ce84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ce88 ldr r0, [pc, #0x238] */
/* @0x15ce8c mov r2, #1 */
/* @0x15ce90 mov r1, r5 */
/* @0x15ce94 mov r3, r2 */
/* @0x15ce98 add r0, pc, r0 */
/* @0x15ce9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cea0 ldr r0, [pc, #0x224] */
/* @0x15cea4 mov r1, r5 */
/* @0x15cea8 mov r2, #0 */
/* @0x15ceac add r0, pc, r0 */
/* @0x15ceb0 mov r3, #1 */
/* @0x15ceb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ceb8 ldr r0, [pc, #0x210] */
/* @0x15cebc mov r1, r5 */
/* @0x15cec0 mov r2, #0 */
/* @0x15cec4 add r0, pc, r0 */
/* @0x15cec8 mov r3, #1 */
/* @0x15cecc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15ced0 ldr r0, [pc, #0x1fc] */
/* @0x15ced4 mov r2, #1 */
/* @0x15ced8 mov r1, r5 */
/* @0x15cedc mov r3, r2 */
/* @0x15cee0 add r0, pc, r0 */
/* @0x15cee4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cee8 ldr r0, [pc, #0x1e8] */
/* @0x15ceec mov r2, #1 */
/* @0x15cef0 mov r1, r5 */
/* @0x15cef4 mov r3, r2 */
/* @0x15cef8 add r0, pc, r0 */
/* @0x15cefc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cf00 ldr r0, [pc, #0x1d4] */
/* @0x15cf04 mov r2, #1 */
/* @0x15cf08 mov r1, r5 */
/* @0x15cf0c mov r3, r2 */
/* @0x15cf10 add r0, pc, r0 */
/* @0x15cf14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cf18 ldr r0, [pc, #0x1c0] */
/* @0x15cf1c mov r1, r5 */
/* @0x15cf20 mov r2, #2 */
/* @0x15cf24 add r0, pc, r0 */
/* @0x15cf28 mov r3, #1 */
/* @0x15cf2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cf30 ldr r0, [pc, #0x1ac] */
/* @0x15cf34 mov r1, r5 */
/* @0x15cf38 mov r2, #0 */
/* @0x15cf3c add r0, pc, r0 */
/* @0x15cf40 mov r3, #1 */
/* @0x15cf44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cf48 ldr r0, [pc, #0x198] */
/* @0x15cf4c mov r2, #1 */
/* @0x15cf50 mov r1, r5 */
/* @0x15cf54 mov r3, r2 */
/* @0x15cf58 add r0, pc, r0 */
/* @0x15cf5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cf60 ldr r0, [pc, #0x184] */
/* @0x15cf64 mov r1, r5 */
/* @0x15cf68 mov r2, #0 */
/* @0x15cf6c add r0, pc, r0 */
/* @0x15cf70 mov r3, #1 */
/* @0x15cf74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cf78 ldr r0, [pc, #0x170] */
/* @0x15cf7c mov r1, r5 */
/* @0x15cf80 mov r2, #0 */
/* @0x15cf84 add r0, pc, r0 */
/* @0x15cf88 mov r3, #1 */
/* @0x15cf8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cf90 ldr r0, [pc, #0x15c] */
/* @0x15cf94 mov r2, #1 */
/* @0x15cf98 mov r1, r5 */
/* @0x15cf9c mov r3, r2 */
/* @0x15cfa0 add r0, pc, r0 */
/* @0x15cfa4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15cfa8 add sp, sp, #28 */
/* @0x15cfac pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x15cfb0 b 0x246fe0 <_Z23InitJavaScriptFunctionsv> */
/* @0x15cfb4 andseq r12, lr, r0, rrx */
/* @0x15cfb8 andseq r12, lr, r4, rrx */
/* @0x15cfbc andseq r12, lr, r12, rrx */
/* @0x15cfc0 andseq r12, lr, r12, ror r0 */
/* @0x15cfc4 andseq r12, lr, r8, lsl #1 */
/* @0x15cfc8 andseq r12, lr, r12, lsl #1 */
/* @0x15cfcc mulseq lr, r0, r0 */
/* @0x15cfd0 mulseq lr, r0, r0 */
/* @0x15cfd4 mulseq lr, r4, r0 */
/* @0x15cfd8 mulseq lr, r8, r0 */
/* @0x15cfdc andseq r12, lr, r8, lsr #1 */
/* @0x15cfe0 ldrheq r12, [lr], -r8 */
/* @0x15cfe4 andseq r12, lr, r4, asr #1 */
/* @0x15cfe8 ldrsbeq r12, [lr], -r8 */
/* @0x15cfec andseq r12, lr, r4, ror #1 */
/* @0x15cff0 ldrsheq r12, [lr], -r0 */
/* @0x15cff4 ldrsheq r12, [lr], -r12 */
/* @0x15cff8 andseq r12, lr, r12, lsl #2 */
/* @0x15cffc andseq r12, lr, r8, lsl #2 */
/* @0x15d000 andseq r12, lr, r12, lsl r1 */
/* @0x15d004 andseq r12, lr, r4, lsr #2 */
/* @0x15d008 andseq r12, lr, r0, lsr #2 */
/* @0x15d00c andseq r12, lr, r0, lsr #2 */
/* @0x15d010 andseq r12, lr, r8, lsl r1 */
/* @0x15d014 andseq r12, lr, r0, lsr #2 */
/* @0x15d018 andseq r12, lr, r12, lsl r1 */
/* @0x15d01c andseq r12, lr, r8, lsl r1 */
/* @0x15d020 andseq r12, lr, r12, lsl r1 */
/* @0x15d024 andseq r12, lr, r0, lsr #2 */
/* @0x15d028 andseq r12, lr, r12, lsr #2 */
/* @0x15d02c andseq r12, lr, r0, lsr r1 */
/* @0x15d030 andseq r12, lr, r0, lsr r1 */
/* @0x15d034 andseq r12, lr, r12, lsr #2 */
/* @0x15d038 andseq r12, lr, r12, lsr #2 */
/* @0x15d03c andseq r12, lr, r4, lsr #2 */
/* @0x15d040 andseq r12, lr, r4, lsr #2 */
/* @0x15d044 andseq r12, lr, r12, lsr #2 */
/* @0x15d048 andseq r12, lr, r4, lsr r1 */
/* @0x15d04c andseq r12, lr, r4, lsr r1 */
/* @0x15d050 andseq r12, lr, r12, lsr r1 */
/* @0x15d054 andseq r12, lr, r4, asr #2 */
/* @0x15d058 andseq r12, lr, r12, asr #2 */
/* @0x15d05c andseq r12, lr, r4, asr r1 */
/* @0x15d060 andseq r12, lr, r0, ror #2 */
/* @0x15d064 andseq r12, lr, r8, ror #2 */
/* @0x15d068 andseq r12, lr, r12, ror #2 */
/* @0x15d06c andseq r12, lr, r12, ror #2 */
/* @0x15d070 andseq r12, lr, r0, ror r1 */
/* @0x15d074 andseq r12, lr, r4, ror r1 */
/* @0x15d078 andseq r12, lr, r12, ror r1 */
/* @0x15d07c andseq r12, lr, r8, ror r1 */
/* @0x15d080 andseq r12, lr, r0, ror r1 */
/* @0x15d084 andseq r12, lr, r0, lsl #3 */
/* @0x15d088 andseq r12, lr, r8, lsl #3 */
/* @0x15d08c andseq r12, lr, r12, lsl #3 */
/* @0x15d090 andseq r12, lr, r12, lsl #3 */
/* @0x15d094 mulseq lr, r0, r1 */
/* @0x15d098 andseq r12, lr, r12, lsl #3 */
/* @0x15d09c mulseq lr, r0, r1 */
/* @0x15d0a0 mulseq lr, r4, r1 */
/* @0x15d0a4 mulseq lr, r4, r1 */
/* @0x15d0a8 mulseq lr, r12, r1 */
/* @0x15d0ac mulseq lr, r4, r1 */
/* @0x15d0b0 mulseq lr, r4, r1 */
/* @0x15d0b4 mulseq lr, r0, r1 */
/* @0x15d0b8 andseq r12, lr, r12, lsl #3 */
/* @0x15d0bc andseq r12, lr, r12, lsl #3 */
/* @0x15d0c0 andseq r12, lr, r12, lsl #3 */
/* @0x15d0c4 andseq r12, lr, r8, lsl #3 */
/* @0x15d0c8 andseq r12, lr, r8, lsl #3 */
/* @0x15d0cc andseq r12, lr, r4, lsl #3 */
/* @0x15d0d0 andseq r12, lr, r0, lsl #3 */
/* @0x15d0d4 andseq r12, lr, r0, ror r1 */
/* @0x15d0d8 andseq r12, lr, r8, ror #2 */
/* @0x15d0dc andseq r12, lr, r0, ror #2 */
/* @0x15d0e0 andseq r12, lr, r4, ror #2 */
/* @0x15d0e4 andseq r12, lr, r4, ror #2 */
/* @0x15d0e8 andseq r12, lr, r4, ror #2 */
/* @0x15d0ec andseq r12, lr, r12, asr r1 */
/* @0x15d0f0 andseq r12, lr, r0, asr r1 */
/* @0x15d0f4 andseq r12, lr, r0, asr #2 */

/* ── FUNC 0x15d0f8 · InitYoYoFunctionConstants() · size=2564 · insn=641 */
/* @0x15d0f8 push {r4, lr} */
/* @0x15d0fc bl 0x15e2a4 <_Z18InitYoYoConstantsMv> */
/* @0x15d100 mov r2, #0 */
/* @0x15d104 ldr r0, [pc, #0x878] */
/* @0x15d108 mov r3, #0 */
/* @0x15d10c movt r3, #0xbff0 */
/* @0x15d110 add r0, pc, r0 */
/* @0x15d114 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d118 ldr r0, [pc, #0x868] */
/* @0x15d11c mov r2, #0 */
/* @0x15d120 mov r3, #0 */
/* @0x15d124 add r0, pc, r0 */
/* @0x15d128 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d12c ldr r0, [pc, #0x858] */
/* @0x15d130 mov r2, #0 */
/* @0x15d134 mov r3, #0 */
/* @0x15d138 add r0, pc, r0 */
/* @0x15d13c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d140 ldr r0, [pc, #0x848] */
/* @0x15d144 mov r2, #0 */
/* @0x15d148 mov r3, #0 */
/* @0x15d14c add r0, pc, r0 */
/* @0x15d150 movt r3, #0x3ff0 */
/* @0x15d154 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d158 ldr r3, [pc, #0x834] */
/* @0x15d15c ldr r3, [pc, r3] */
/* @0x15d160 ldrb r3, [r3] */
/* @0x15d164 cmp r3, #0 */
/* @0x15d168 bne 0x15d180 <_Z25InitYoYoFunctionConstantsv+0x88> */
/* @0x15d16c ldr r0, [pc, #0x824] */
/* @0x15d170 mov r2, #0 */
/* @0x15d174 mov r3, #1073741824 */
/* @0x15d178 add r0, pc, r0 */
/* @0x15d17c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d180 ldr r0, [pc, #0x814] */
/* @0x15d184 mov r2, #0 */
/* @0x15d188 mov r3, #0 */
/* @0x15d18c movt r3, #0x4008 */
/* @0x15d190 add r0, pc, r0 */
/* @0x15d194 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d198 ldr r0, [pc, #0x800] */
/* @0x15d19c mov r2, #0 */
/* @0x15d1a0 mov r3, #0 */
/* @0x15d1a4 add r0, pc, r0 */
/* @0x15d1a8 movt r3, #0x4010 */
/* @0x15d1ac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d1b0 ldr r0, [pc, #0x7ec] */
/* @0x15d1b4 mov r2, #0 */
/* @0x15d1b8 mov r3, #0 */
/* @0x15d1bc add r0, pc, r0 */
/* @0x15d1c0 movt r3, #0x4014 */
/* @0x15d1c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d1c8 ldr r0, [pc, #0x7d8] */
/* @0x15d1cc mov r2, #0 */
/* @0x15d1d0 mov r3, #0 */
/* @0x15d1d4 add r0, pc, r0 */
/* @0x15d1d8 movt r3, #0x4018 */
/* @0x15d1dc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d1e0 ldr r0, [pc, #0x7c4] */
/* @0x15d1e4 mov r2, #0 */
/* @0x15d1e8 mov r3, #0 */
/* @0x15d1ec add r0, pc, r0 */
/* @0x15d1f0 movt r3, #0x401c */
/* @0x15d1f4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d1f8 ldr r0, [pc, #0x7b0] */
/* @0x15d1fc mov r2, #0 */
/* @0x15d200 mov r3, #0 */
/* @0x15d204 add r0, pc, r0 */
/* @0x15d208 movt r3, #0x4020 */
/* @0x15d20c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d210 ldr r0, [pc, #0x79c] */
/* @0x15d214 mov r2, #0 */
/* @0x15d218 mov r3, #0 */
/* @0x15d21c add r0, pc, r0 */
/* @0x15d220 movt r3, #0x4022 */
/* @0x15d224 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d228 ldr r0, [pc, #0x788] */
/* @0x15d22c mov r2, #0 */
/* @0x15d230 mov r3, #0 */
/* @0x15d234 add r0, pc, r0 */
/* @0x15d238 movt r3, #0x4024 */
/* @0x15d23c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d240 ldr r0, [pc, #0x774] */
/* @0x15d244 mov r2, #0 */
/* @0x15d248 mov r3, #0 */
/* @0x15d24c add r0, pc, r0 */
/* @0x15d250 movt r3, #0x4026 */
/* @0x15d254 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d258 ldr r0, [pc, #0x760] */
/* @0x15d25c mov r2, #0 */
/* @0x15d260 mov r3, #0 */
/* @0x15d264 add r0, pc, r0 */
/* @0x15d268 movt r3, #0x4028 */
/* @0x15d26c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d270 ldr r0, [pc, #0x74c] */
/* @0x15d274 mov r2, #0 */
/* @0x15d278 mov r3, #0 */
/* @0x15d27c add r0, pc, r0 */
/* @0x15d280 movt r3, #0x402a */
/* @0x15d284 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d288 ldr r0, [pc, #0x738] */
/* @0x15d28c mov r2, #0 */
/* @0x15d290 mov r3, #0 */
/* @0x15d294 add r0, pc, r0 */
/* @0x15d298 movt r3, #0x402c */
/* @0x15d29c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d2a0 ldr r0, [pc, #0x724] */
/* @0x15d2a4 mov r2, #0 */
/* @0x15d2a8 mov r3, #0 */
/* @0x15d2ac add r0, pc, r0 */
/* @0x15d2b0 movt r3, #0x402e */
/* @0x15d2b4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d2b8 ldr r0, [pc, #0x710] */
/* @0x15d2bc mov r2, #0 */
/* @0x15d2c0 mov r3, #0 */
/* @0x15d2c4 add r0, pc, r0 */
/* @0x15d2c8 movt r3, #0x4030 */
/* @0x15d2cc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d2d0 ldr r0, [pc, #0x6fc] */
/* @0x15d2d4 mov r2, #0 */
/* @0x15d2d8 mov r3, #0 */
/* @0x15d2dc add r0, pc, r0 */
/* @0x15d2e0 movt r3, #0x4031 */
/* @0x15d2e4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d2e8 ldr r0, [pc, #0x6e8] */
/* @0x15d2ec mov r2, #0 */
/* @0x15d2f0 mov r3, #0 */
/* @0x15d2f4 add r0, pc, r0 */
/* @0x15d2f8 movt r3, #0x4032 */
/* @0x15d2fc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d300 ldr r0, [pc, #0x6d4] */
/* @0x15d304 mov r2, #0 */
/* @0x15d308 mov r3, #0 */
/* @0x15d30c add r0, pc, r0 */
/* @0x15d310 movt r3, #0x4033 */
/* @0x15d314 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d318 ldr r0, [pc, #0x6c0] */
/* @0x15d31c mov r2, #0 */
/* @0x15d320 mov r3, #0 */
/* @0x15d324 add r0, pc, r0 */
/* @0x15d328 movt r3, #0x40f0 */
/* @0x15d32c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d330 ldr r0, [pc, #0x6ac] */
/* @0x15d334 mov r2, #0 */
/* @0x15d338 mov r3, #16 */
/* @0x15d33c add r0, pc, r0 */
/* @0x15d340 movt r3, #0x40f0 */
/* @0x15d344 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d348 ldr r0, [pc, #0x698] */
/* @0x15d34c mov r2, #0 */
/* @0x15d350 mov r3, #32 */
/* @0x15d354 add r0, pc, r0 */
/* @0x15d358 movt r3, #0x40f0 */
/* @0x15d35c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d360 ldr r0, [pc, #0x684] */
/* @0x15d364 mov r2, #0 */
/* @0x15d368 mov r3, #48 */
/* @0x15d36c add r0, pc, r0 */
/* @0x15d370 movt r3, #0x40f0 */
/* @0x15d374 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d378 ldr r0, [pc, #0x670] */
/* @0x15d37c mov r2, #0 */
/* @0x15d380 mov r3, #64 */
/* @0x15d384 add r0, pc, r0 */
/* @0x15d388 movt r3, #0x40f0 */
/* @0x15d38c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d390 ldr r0, [pc, #0x65c] */
/* @0x15d394 mov r2, #0 */
/* @0x15d398 mov r3, #80 */
/* @0x15d39c add r0, pc, r0 */
/* @0x15d3a0 movt r3, #0x40f0 */
/* @0x15d3a4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d3a8 ldr r0, [pc, #0x648] */
/* @0x15d3ac mov r2, #0 */
/* @0x15d3b0 mov r3, #96 */
/* @0x15d3b4 add r0, pc, r0 */
/* @0x15d3b8 movt r3, #0x40f0 */
/* @0x15d3bc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d3c0 ldr r0, [pc, #0x634] */
/* @0x15d3c4 mov r2, #0 */
/* @0x15d3c8 mov r3, #112 */
/* @0x15d3cc add r0, pc, r0 */
/* @0x15d3d0 movt r3, #0x40f0 */
/* @0x15d3d4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d3d8 ldr r0, [pc, #0x620] */
/* @0x15d3dc mov r2, #0 */
/* @0x15d3e0 mov r3, #0 */
/* @0x15d3e4 add r0, pc, r0 */
/* @0x15d3e8 movt r3, #0xbff0 */
/* @0x15d3ec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d3f0 ldr r0, [pc, #0x60c] */
/* @0x15d3f4 mov r2, #0 */
/* @0x15d3f8 mov r3, #0 */
/* @0x15d3fc add r0, pc, r0 */
/* @0x15d400 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d404 ldr r0, [pc, #0x5fc] */
/* @0x15d408 mov r2, #0 */
/* @0x15d40c mov r3, #0 */
/* @0x15d410 add r0, pc, r0 */
/* @0x15d414 movt r3, #0x3ff0 */
/* @0x15d418 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d41c ldr r0, [pc, #0x5e8] */
/* @0x15d420 mov r2, #0 */
/* @0x15d424 mov r3, #1073741824 */
/* @0x15d428 add r0, pc, r0 */
/* @0x15d42c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d430 ldr r0, [pc, #0x5d8] */
/* @0x15d434 mov r2, #0 */
/* @0x15d438 mov r3, #0 */
/* @0x15d43c add r0, pc, r0 */
/* @0x15d440 movt r3, #0x4008 */
/* @0x15d444 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d448 ldr r0, [pc, #0x5c4] */
/* @0x15d44c mov r2, #0 */
/* @0x15d450 mov r3, #0 */
/* @0x15d454 add r0, pc, r0 */
/* @0x15d458 movt r3, #0x4010 */
/* @0x15d45c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d460 ldr r0, [pc, #0x5b0] */
/* @0x15d464 mov r2, #0 */
/* @0x15d468 mov r3, #0 */
/* @0x15d46c add r0, pc, r0 */
/* @0x15d470 movt r3, #0x4070 */
/* @0x15d474 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d478 ldr r0, [pc, #0x59c] */
/* @0x15d47c mov r2, #0 */
/* @0x15d480 mov r3, #1073741824 */
/* @0x15d484 add r0, pc, r0 */
/* @0x15d488 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d48c ldr r0, [pc, #0x58c] */
/* @0x15d490 mov r2, #0 */
/* @0x15d494 mov r3, #0 */
/* @0x15d498 add r0, pc, r0 */
/* @0x15d49c movt r3, #0xbff0 */
/* @0x15d4a0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d4a4 ldr r0, [pc, #0x578] */
/* @0x15d4a8 mov r2, #0 */
/* @0x15d4ac mov r3, #0 */
/* @0x15d4b0 add r0, pc, r0 */
/* @0x15d4b4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d4b8 ldr r0, [pc, #0x568] */
/* @0x15d4bc mov r2, #0 */
/* @0x15d4c0 mov r3, #0 */
/* @0x15d4c4 add r0, pc, r0 */
/* @0x15d4c8 movt r3, #0x3ff0 */
/* @0x15d4cc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d4d0 ldr r0, [pc, #0x554] */
/* @0x15d4d4 mov r2, #0 */
/* @0x15d4d8 mov r3, #1073741824 */
/* @0x15d4dc add r0, pc, r0 */
/* @0x15d4e0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d4e4 ldr r0, [pc, #0x544] */
/* @0x15d4e8 mov r2, #0 */
/* @0x15d4ec mov r3, #0 */
/* @0x15d4f0 add r0, pc, r0 */
/* @0x15d4f4 movt r3, #0x4008 */
/* @0x15d4f8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d4fc ldr r0, [pc, #0x530] */
/* @0x15d500 mov r2, #0 */
/* @0x15d504 mov r3, #0 */
/* @0x15d508 add r0, pc, r0 */
/* @0x15d50c movt r3, #0x4010 */
/* @0x15d510 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d514 ldr r0, [pc, #0x51c] */
/* @0x15d518 mov r2, #0 */
/* @0x15d51c mov r3, #0 */
/* @0x15d520 add r0, pc, r0 */
/* @0x15d524 movt r3, #0x4014 */
/* @0x15d528 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d52c ldr r0, [pc, #0x508] */
/* @0x15d530 mov r2, #0 */
/* @0x15d534 mov r3, #0 */
/* @0x15d538 add r0, pc, r0 */
/* @0x15d53c movt r3, #0x4018 */
/* @0x15d540 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d544 ldr r0, [pc, #0x4f4] */
/* @0x15d548 mov r2, #0 */
/* @0x15d54c mov r3, #0 */
/* @0x15d550 add r0, pc, r0 */
/* @0x15d554 movt r3, #0x401c */
/* @0x15d558 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d55c ldr r0, [pc, #0x4e0] */
/* @0x15d560 mov r2, #0 */
/* @0x15d564 mov r3, #0 */
/* @0x15d568 add r0, pc, r0 */
/* @0x15d56c movt r3, #0x4020 */
/* @0x15d570 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d574 ldr r0, [pc, #0x4cc] */
/* @0x15d578 mov r2, #0 */
/* @0x15d57c mov r3, #0 */
/* @0x15d580 add r0, pc, r0 */
/* @0x15d584 movt r3, #0x4022 */
/* @0x15d588 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d58c ldr r0, [pc, #0x4b8] */
/* @0x15d590 mov r2, #0 */
/* @0x15d594 mov r3, #0 */
/* @0x15d598 add r0, pc, r0 */
/* @0x15d59c movt r3, #0x4024 */
/* @0x15d5a0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d5a4 ldr r0, [pc, #0x4a4] */
/* @0x15d5a8 mov r2, #0 */
/* @0x15d5ac mov r3, #0 */
/* @0x15d5b0 add r0, pc, r0 */
/* @0x15d5b4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d5b8 ldr r0, [pc, #0x494] */
/* @0x15d5bc mov r2, #0 */
/* @0x15d5c0 mov r3, #0 */
/* @0x15d5c4 add r0, pc, r0 */
/* @0x15d5c8 movt r3, #0x3ff0 */
/* @0x15d5cc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d5d0 ldr r0, [pc, #0x480] */
/* @0x15d5d4 mov r2, #0 */
/* @0x15d5d8 mov r3, #1073741824 */
/* @0x15d5dc add r0, pc, r0 */
/* @0x15d5e0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d5e4 ldr r0, [pc, #0x470] */
/* @0x15d5e8 mov r2, #0 */
/* @0x15d5ec mov r3, #0 */
/* @0x15d5f0 add r0, pc, r0 */
/* @0x15d5f4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d5f8 ldr r0, [pc, #0x460] */
/* @0x15d5fc mov r2, #0 */
/* @0x15d600 mov r3, #0 */
/* @0x15d604 add r0, pc, r0 */
/* @0x15d608 movt r3, #0x3ff0 */
/* @0x15d60c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d610 ldr r0, [pc, #0x44c] */
/* @0x15d614 mov r2, #0 */
/* @0x15d618 mov r3, #20480 */
/* @0x15d61c add r0, pc, r0 */
/* @0x15d620 movt r3, #0x408f */
/* @0x15d624 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d628 ldr r0, [pc, #0x438] */
/* @0x15d62c mov r2, #0 */
/* @0x15d630 mov r3, #22528 */
/* @0x15d634 add r0, pc, r0 */
/* @0x15d638 movt r3, #0x408f */
/* @0x15d63c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d640 ldr r0, [pc, #0x424] */
/* @0x15d644 mov r2, #0 */
/* @0x15d648 mov r3, #24576 */
/* @0x15d64c add r0, pc, r0 */
/* @0x15d650 movt r3, #0x408f */
/* @0x15d654 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d658 ldr r0, [pc, #0x410] */
/* @0x15d65c mov r2, #0 */
/* @0x15d660 mov r3, #26624 */
/* @0x15d664 add r0, pc, r0 */
/* @0x15d668 movt r3, #0x408f */
/* @0x15d66c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d670 ldr r0, [pc, #0x3fc] */
/* @0x15d674 mov r2, #0 */
/* @0x15d678 mov r3, #28672 */
/* @0x15d67c add r0, pc, r0 */
/* @0x15d680 movt r3, #0x408f */
/* @0x15d684 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d688 ldr r0, [pc, #0x3e8] */
/* @0x15d68c mov r2, #0 */
/* @0x15d690 mov r3, #30720 */
/* @0x15d694 add r0, pc, r0 */
/* @0x15d698 movt r3, #0x408f */
/* @0x15d69c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d6a0 ldr r0, [pc, #0x3d4] */
/* @0x15d6a4 mov r2, #0 */
/* @0x15d6a8 mov r3, #32768 */
/* @0x15d6ac add r0, pc, r0 */
/* @0x15d6b0 movt r3, #0x408f */
/* @0x15d6b4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d6b8 ldr r0, [pc, #0x3c0] */
/* @0x15d6bc mov r2, #0 */
/* @0x15d6c0 mov r3, #34816 */
/* @0x15d6c4 add r0, pc, r0 */
/* @0x15d6c8 movt r3, #0x408f */
/* @0x15d6cc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d6d0 ldr r0, [pc, #0x3ac] */
/* @0x15d6d4 mov r2, #0 */
/* @0x15d6d8 mov r3, #36864 */
/* @0x15d6dc add r0, pc, r0 */
/* @0x15d6e0 movt r3, #0x408f */
/* @0x15d6e4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d6e8 ldr r0, [pc, #0x398] */
/* @0x15d6ec mov r2, #0 */
/* @0x15d6f0 mov r3, #38912 */
/* @0x15d6f4 add r0, pc, r0 */
/* @0x15d6f8 movt r3, #0x408f */
/* @0x15d6fc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d700 ldr r0, [pc, #0x384] */
/* @0x15d704 mov r2, #0 */
/* @0x15d708 mov r3, #0 */
/* @0x15d70c add r0, pc, r0 */
/* @0x15d710 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d714 ldr r0, [pc, #0x374] */
/* @0x15d718 mov r2, #0 */
/* @0x15d71c mov r3, #0 */
/* @0x15d720 add r0, pc, r0 */
/* @0x15d724 movt r3, #0x3ff0 */
/* @0x15d728 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d72c ldr r0, [pc, #0x360] */
/* @0x15d730 mov r2, #0 */
/* @0x15d734 mov r3, #1073741824 */
/* @0x15d738 add r0, pc, r0 */
/* @0x15d73c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d740 ldr r0, [pc, #0x350] */
/* @0x15d744 mov r2, #0 */
/* @0x15d748 mov r3, #0 */
/* @0x15d74c add r0, pc, r0 */
/* @0x15d750 movt r3, #0x4008 */
/* @0x15d754 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d758 ldr r0, [pc, #0x33c] */
/* @0x15d75c mov r2, #0 */
/* @0x15d760 mov r3, #0 */
/* @0x15d764 add r0, pc, r0 */
/* @0x15d768 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d76c ldr r0, [pc, #0x32c] */
/* @0x15d770 mov r2, #0 */
/* @0x15d774 mov r3, #0 */
/* @0x15d778 add r0, pc, r0 */
/* @0x15d77c movt r3, #0x3ff0 */
/* @0x15d780 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d784 ldr r0, [pc, #0x318] */
/* @0x15d788 mov r2, #0 */
/* @0x15d78c mov r3, #0 */
/* @0x15d790 add r0, pc, r0 */
/* @0x15d794 movt r3, #0xbff0 */
/* @0x15d798 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d79c ldr r0, [pc, #0x304] */
/* @0x15d7a0 mov r2, #0 */
/* @0x15d7a4 mov r3, #0 */
/* @0x15d7a8 add r0, pc, r0 */
/* @0x15d7ac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d7b0 ldr r0, [pc, #0x2f4] */
/* @0x15d7b4 mov r2, #0 */
/* @0x15d7b8 mov r3, #0 */
/* @0x15d7bc add r0, pc, r0 */
/* @0x15d7c0 movt r3, #0x3ff0 */
/* @0x15d7c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d7c8 ldr r0, [pc, #0x2e0] */
/* @0x15d7cc mov r2, #0 */
/* @0x15d7d0 mov r3, #1073741824 */
/* @0x15d7d4 add r0, pc, r0 */
/* @0x15d7d8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d7dc ldr r0, [pc, #0x2d0] */
/* @0x15d7e0 mov r2, #0 */
/* @0x15d7e4 mov r3, #0 */
/* @0x15d7e8 add r0, pc, r0 */
/* @0x15d7ec movt r3, #0x4008 */
/* @0x15d7f0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d7f4 ldr r0, [pc, #0x2bc] */
/* @0x15d7f8 mov r2, #0 */
/* @0x15d7fc mov r3, #0 */
/* @0x15d800 add r0, pc, r0 */
/* @0x15d804 movt r3, #0x4010 */
/* @0x15d808 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d80c ldr r0, [pc, #0x2a8] */
/* @0x15d810 mov r2, #0 */
/* @0x15d814 mov r3, #0 */
/* @0x15d818 add r0, pc, r0 */
/* @0x15d81c movt r3, #0x4014 */
/* @0x15d820 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d824 ldr r0, [pc, #0x294] */
/* @0x15d828 mov r2, #0 */
/* @0x15d82c mov r3, #0 */
/* @0x15d830 add r0, pc, r0 */
/* @0x15d834 movt r3, #0x4018 */
/* @0x15d838 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d83c ldr r0, [pc, #0x280] */
/* @0x15d840 mov r2, #0 */
/* @0x15d844 mov r3, #0 */
/* @0x15d848 add r0, pc, r0 */
/* @0x15d84c movt r3, #0x401c */
/* @0x15d850 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d854 ldr r0, [pc, #0x26c] */
/* @0x15d858 mov r2, #0 */
/* @0x15d85c mov r3, #0 */
/* @0x15d860 add r0, pc, r0 */
/* @0x15d864 movt r3, #0x4020 */
/* @0x15d868 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d86c ldr r0, [pc, #0x258] */
/* @0x15d870 mov r2, #0 */
/* @0x15d874 mov r3, #0 */
/* @0x15d878 add r0, pc, r0 */
/* @0x15d87c movt r3, #0x3ff0 */
/* @0x15d880 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d884 ldr r0, [pc, #0x244] */
/* @0x15d888 mov r2, #0 */
/* @0x15d88c mov r3, #1073741824 */
/* @0x15d890 add r0, pc, r0 */
/* @0x15d894 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d898 ldr r0, [pc, #0x234] */
/* @0x15d89c mov r2, #0 */
/* @0x15d8a0 mov r3, #0 */
/* @0x15d8a4 add r0, pc, r0 */
/* @0x15d8a8 movt r3, #0x4008 */
/* @0x15d8ac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d8b0 ldr r0, [pc, #0x220] */
/* @0x15d8b4 mov r2, #0 */
/* @0x15d8b8 mov r3, #0 */
/* @0x15d8bc add r0, pc, r0 */
/* @0x15d8c0 movt r3, #0x4010 */
/* @0x15d8c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d8c8 ldr r0, [pc, #0x20c] */
/* @0x15d8cc mov r2, #0 */
/* @0x15d8d0 mov r3, #0 */
/* @0x15d8d4 add r0, pc, r0 */
/* @0x15d8d8 movt r3, #0x4014 */
/* @0x15d8dc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d8e0 ldr r0, [pc, #0x1f8] */
/* @0x15d8e4 mov r2, #0 */
/* @0x15d8e8 mov r3, #0 */
/* @0x15d8ec add r0, pc, r0 */
/* @0x15d8f0 movt r3, #0x4018 */
/* @0x15d8f4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d8f8 ldr r0, [pc, #0x1e4] */
/* @0x15d8fc mov r2, #0 */
/* @0x15d900 mov r3, #0 */
/* @0x15d904 add r0, pc, r0 */
/* @0x15d908 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d90c ldr r0, [pc, #0x1d4] */
/* @0x15d910 mov r2, #0 */
/* @0x15d914 mov r3, #0 */
/* @0x15d918 add r0, pc, r0 */
/* @0x15d91c movt r3, #0x3ff0 */
/* @0x15d920 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d924 ldr r0, [pc, #0x1c0] */
/* @0x15d928 mov r2, #0 */
/* @0x15d92c mov r3, #1073741824 */
/* @0x15d930 add r0, pc, r0 */
/* @0x15d934 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d938 ldr r0, [pc, #0x1b0] */
/* @0x15d93c mov r2, #0 */
/* @0x15d940 mov r3, #0 */
/* @0x15d944 add r0, pc, r0 */
/* @0x15d948 movt r3, #0x4008 */
/* @0x15d94c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d950 ldr r0, [pc, #0x19c] */
/* @0x15d954 mov r2, #0 */
/* @0x15d958 mov r3, #0 */
/* @0x15d95c add r0, pc, r0 */
/* @0x15d960 movt r3, #0x4010 */
/* @0x15d964 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d968 ldr r0, [pc, #0x188] */
/* @0x15d96c mov r3, #0 */
/* @0x15d970 mov r2, #0 */
/* @0x15d974 add r0, pc, r0 */
/* @0x15d978 movt r3, #0x4014 */
/* @0x15d97c pop {r4, lr} */
/* @0x15d980 b 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0x15d984 andseq r9, sp, r8, asr r3 */
/* @0x15d988 andseq r9, sp, r0, asr r3 */
/* @0x15d98c andseq r9, sp, r8, asr #6 */
/* @0x15d990 andseq r9, sp, r0, asr #6 */
/* @0x15d994 eoreq r0, r9, r8, asr #15 */
/* @0x15d998 andseq r9, sp, r0, lsr #6 */
/* @0x15d99c andseq r9, sp, r0, lsl r3 */
/* @0x15d9a0 andseq r9, sp, r4, lsl #6 */
/* @0x15d9a4 ldrsheq r9, [sp], -r8 */
/* @0x15d9a8 andseq r9, sp, r12, ror #5 */
/* @0x15d9ac andseq r9, sp, r0, ror #5 */
/* @0x15d9b0 ldrsbeq r9, [sp], -r4 */
/* @0x15d9b4 andseq r9, sp, r8, asr #5 */
/* @0x15d9b8 andseq r9, sp, r0, asr #5 */
/* @0x15d9bc ldrheq r9, [sp], -r0 */
/* @0x15d9c0 andseq r9, sp, r0, lsr #5 */
/* @0x15d9c4 mulseq sp, r4, r2 */
/* @0x15d9c8 andseq r9, sp, r4, lsl #5 */
/* @0x15d9cc andseq r9, sp, r4, ror r2 */
/* @0x15d9d0 andseq r9, sp, r8, ror #4 */
/* @0x15d9d4 andseq r9, sp, r8, asr r2 */
/* @0x15d9d8 andseq r9, sp, r12, asr #4 */
/* @0x15d9dc andseq r11, lr, r8, ror #27 */
/* @0x15d9e0 ldrsbeq r11, [lr], -r12 */
/* @0x15d9e4 ldrsbeq r11, [lr], -r4 */
/* @0x15d9e8 andseq r11, lr, r12, asr #27 */
/* @0x15d9ec andseq r11, lr, r0, asr #27 */
/* @0x15d9f0 ldrheq r11, [lr], -r4 */
/* @0x15d9f4 andseq r11, lr, r12, lsr #27 */
/* @0x15d9f8 andseq r11, lr, r4, lsr #27 */
/* @0x15d9fc mulseq lr, r12, sp */
/* @0x15da00 mulseq lr, r8, sp */
/* @0x15da04 mulseq lr, r4, sp */
/* @0x15da08 mulseq lr, r4, sp */
/* @0x15da0c mulseq lr, r8, sp */
/* @0x15da10 mulseq lr, r4, sp */
/* @0x15da14 mulseq lr, r4, sp */
/* @0x15da18 mulseq lr, r0, sp */
/* @0x15da1c andseq r11, lr, r8, lsl #27 */
/* @0x15da20 andseq r11, lr, r4, lsl #27 */
/* @0x15da24 andseq r11, lr, r4, lsl #27 */
/* @0x15da28 andseq r11, lr, r0, lsl #27 */
/* @0x15da2c andseq r11, lr, r4, ror sp */
/* @0x15da30 andseq r11, lr, r0, ror sp */
/* @0x15da34 andseq r11, lr, r8, ror #26 */
/* @0x15da38 andseq r11, lr, r0, ror #26 */
/* @0x15da3c andseq r11, lr, r0, ror #26 */
/* @0x15da40 andseq r11, lr, r8, asr sp */
/* @0x15da44 andseq r11, lr, r8, asr sp */
/* @0x15da48 andseq r11, lr, r8, asr sp */
/* @0x15da4c andseq r11, lr, r0, asr sp */
/* @0x15da50 andseq r11, lr, r12, asr #26 */
/* @0x15da54 andseq r11, lr, r12, asr #26 */
/* @0x15da58 andseq r11, lr, r8, asr #26 */
/* @0x15da5c andseq r11, lr, r8, asr #26 */
/* @0x15da60 andseq r11, lr, r12, asr #26 */
/* @0x15da64 andseq r11, lr, r4, asr sp */
/* @0x15da68 andseq r11, lr, r4, asr sp */
/* @0x15da6c andseq r11, lr, r8, asr sp */
/* @0x15da70 andseq r11, lr, r0, ror #26 */
/* @0x15da74 andseq r11, lr, r8, ror #26 */
/* @0x15da78 andseq r11, lr, r8, ror #26 */
/* @0x15da7c andseq r11, lr, r0, ror sp */
/* @0x15da80 andseq r11, lr, r4, lsl #27 */
/* @0x15da84 andseq r11, lr, r12, lsl #27 */
/* @0x15da88 mulseq lr, r8, sp */
/* @0x15da8c andseq r11, lr, r0, lsr #27 */
/* @0x15da90 andseq r11, lr, r12, lsr #27 */
/* @0x15da94 ldrheq r11, [lr], -r4 */
/* @0x15da98 andseq r11, lr, r4, asr #27 */
/* @0x15da9c andseq r11, lr, r12, asr #27 */
/* @0x15daa0 andseq r11, lr, r0, ror #27 */
/* @0x15daa4 andseq r11, lr, r12, ror #27 */
/* @0x15daa8 andseq r11, lr, r4, ror #27 */
/* @0x15daac andseq r11, lr, r0, ror #27 */
/* @0x15dab0 ldrsbeq r11, [lr], -r8 */
/* @0x15dab4 ldrsbeq r11, [lr], -r0 */
/* @0x15dab8 andseq r11, lr, r4, asr #27 */
/* @0x15dabc andseq r11, lr, r0, asr #27 */
/* @0x15dac0 ldrheq r11, [lr], -r4 */
/* @0x15dac4 andseq r11, lr, r12, lsr #27 */
/* @0x15dac8 andseq r11, lr, r0, lsr #27 */
/* @0x15dacc mulseq lr, r8, sp */
/* @0x15dad0 andseq r11, lr, r12, lsl #27 */
/* @0x15dad4 andseq r11, lr, r8, lsl #27 */
/* @0x15dad8 andseq r11, lr, r0, lsl #27 */
/* @0x15dadc andseq r11, lr, r8, ror sp */
/* @0x15dae0 andseq r11, lr, r0, ror sp */
/* @0x15dae4 andseq r11, lr, r12, ror #26 */
/* @0x15dae8 andseq r11, lr, r12, ror #26 */
/* @0x15daec andseq r11, lr, r4, ror sp */
/* @0x15daf0 andseq r11, lr, r0, lsl #27 */
/* @0x15daf4 andseq r11, lr, r4, lsl #27 */
/* @0x15daf8 andseq r11, lr, r8, lsl #27 */

/* ── FUNC 0x15dafc · InitYoYoBuiltInVariables() · size=236 · insn=59 */
/* @0x15dafc push {r4, lr} */
/* @0x15db00 mov r2, #0 */
/* @0x15db04 ldr r4, [pc, #0xa8] */
/* @0x15db08 mov r3, r2 */
/* @0x15db0c ldr r1, [pc, #0xa4] */
/* @0x15db10 add r4, pc, r4 */
/* @0x15db14 ldr r0, [pc, #0xa0] */
/* @0x15db18 ldr r1, [r4, r1] */
/* @0x15db1c add r0, pc, r0 */
/* @0x15db20 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x15db24 ldr r1, [pc, #0x94] */
/* @0x15db28 ldr r0, [pc, #0x94] */
/* @0x15db2c mov r2, #0 */
/* @0x15db30 mov r3, r2 */
/* @0x15db34 ldr r1, [r4, r1] */
/* @0x15db38 add r0, pc, r0 */
/* @0x15db3c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x15db40 ldr r1, [pc, #0x80] */
/* @0x15db44 ldr r0, [pc, #0x80] */
/* @0x15db48 mov r2, #0 */
/* @0x15db4c mov r3, r2 */
/* @0x15db50 ldr r1, [r4, r1] */
/* @0x15db54 add r0, pc, r0 */
/* @0x15db58 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x15db5c ldr r1, [pc, #0x6c] */
/* @0x15db60 ldr r0, [pc, #0x6c] */
/* @0x15db64 mov r2, #0 */
/* @0x15db68 mov r3, r2 */
/* @0x15db6c ldr r1, [r4, r1] */
/* @0x15db70 add r0, pc, r0 */
/* @0x15db74 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x15db78 ldr r1, [pc, #0x58] */
/* @0x15db7c ldr r0, [pc, #0x58] */
/* @0x15db80 mov r2, #0 */
/* @0x15db84 mov r3, r2 */
/* @0x15db88 ldr r1, [r4, r1] */
/* @0x15db8c add r0, pc, r0 */
/* @0x15db90 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x15db94 ldr r1, [pc, #0x44] */
/* @0x15db98 ldr r0, [pc, #0x44] */
/* @0x15db9c mov r2, #0 */
/* @0x15dba0 mov r3, r2 */
/* @0x15dba4 ldr r1, [r4, r1] */
/* @0x15dba8 add r0, pc, r0 */
/* @0x15dbac pop {r4, lr} */
/* @0x15dbb0 b 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x15dbb4 eoreq r4, r9, r0, asr #2 */
/* @0x15dbb8 .word 0xffffe204 */
/* @0x15dbbc ldrsheq r11, [lr], -r8 */
/* @0x15dbc0 .word 0xffffe208 */
/* @0x15dbc4 andseq r11, lr, r4, ror #23 */
/* @0x15dbc8 .word 0xffffe20c */
/* @0x15dbcc ldrsbeq r11, [lr], -r4 */
/* @0x15dbd0 .word 0xffffe210 */
/* @0x15dbd4 andseq r11, lr, r4, asr #23 */
/* @0x15dbd8 .word 0xffffe214 */
/* @0x15dbdc ldrheq r11, [lr], -r4 */
/* @0x15dbe0 .word 0xffffe218 */
/* @0x15dbe4 andseq r11, lr, r8, lsr #23 */

/* ── FUNC 0x15dbe8 · ProcessGMLCallbacks() · size=1224 · insn=306 */
/* @0x15dbe8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x15dbec add r11, sp, #32 */
/* @0x15dbf0 ldr r1, [pc, #0x494] */
/* @0x15dbf4 sub sp, sp, #76 */
/* @0x15dbf8 ldr r2, [pc, #0x490] */
/* @0x15dbfc ldr r1, [pc, r1] */
/* @0x15dc00 str r1, [r11, #-0x5c] */
/* @0x15dc04 add r2, pc, r2 */
/* @0x15dc08 ldr r3, [r1] */
/* @0x15dc0c ldr r0, [r2] */
/* @0x15dc10 str r3, [r11, #-0x28] */
/* @0x15dc14 bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0x15dc18 ldr r3, [pc, #0x474] */
/* @0x15dc1c ldr r0, [pc, r3] */
/* @0x15dc20 cmn r0, #1 */
/* @0x15dc24 beq 0x15de08 <_Z19ProcessGMLCallbacksv+0x220> */
/* @0x15dc28 ldr r3, [pc, #0x468] */
/* @0x15dc2c mov r7, #0 */
/* @0x15dc30 ldr r1, [pc, #0x464] */
/* @0x15dc34 sub r8, r11, #56 */
/* @0x15dc38 add r3, pc, r3 */
/* @0x15dc3c str r3, [r11, #-0x54] */
/* @0x15dc40 ldr r3, [pc, #0x458] */
/* @0x15dc44 add r1, pc, r1 */
/* @0x15dc48 str r1, [r11, #-0x50] */
/* @0x15dc4c add r3, pc, r3 */
/* @0x15dc50 str r3, [r11, #-0x58] */
/* @0x15dc54 bl 0x2055c8 <_Z11DsQueueSizei> */
/* @0x15dc58 cmp r0, #0 */
/* @0x15dc5c ble 0x15de08 <_Z19ProcessGMLCallbacksv+0x220> */
/* @0x15dc60 ldr r1, [r11, #-0x54] */
/* @0x15dc64 str r7, [r11, #-0x38] */
/* @0x15dc68 ldr r0, [r1] */
/* @0x15dc6c mov r1, r8 */
/* @0x15dc70 bl 0x20557c <_Z14DsQueueDequeueiR6RValue> */
/* @0x15dc74 ldr r4, [r11, #-0x2c] */
/* @0x15dc78 ldr r3, [r11, #-0x38] */
/* @0x15dc7c ldr r1, [r11, #-0x34] */
/* @0x15dc80 cmp r4, #0 */
/* @0x15dc84 str r3, [r11, #-0x4c] */
/* @0x15dc88 str r1, [r11, #-0x48] */
/* @0x15dc8c bne 0x15ddf4 <_Z19ProcessGMLCallbacksv+0x20c> */
/* @0x15dc90 vldr d7, [r11, #-76] */
/* @0x15dc94 vcmpe.f64 d7, #0 */
/* @0x15dc98 vmrs APSR_nzcv, fpscr */
/* @0x15dc9c blt 0x15ddf4 <_Z19ProcessGMLCallbacksv+0x20c> */
/* @0x15dca0 ldr r1, [r11, #-0x54] */
/* @0x15dca4 str r4, [r11, #-0x38] */
/* @0x15dca8 ldr r0, [r1] */
/* @0x15dcac mov r1, r8 */
/* @0x15dcb0 bl 0x20557c <_Z14DsQueueDequeueiR6RValue> */
/* @0x15dcb4 ldr r3, [r11, #-0x34] */
/* @0x15dcb8 ldr r2, [r11, #-0x38] */
/* @0x15dcbc vmov d7, r2, r3 */
/* @0x15dcc0 vcvt.s32.f64 s15, d7 */
/* @0x15dcc4 vmov r5, s15 */
/* @0x15dcc8 vstr s15, [r11, #-64] */
/* @0x15dccc lsl r3, r5, #4 */
/* @0x15dcd0 cmp r5, #0 */
/* @0x15dcd4 add r3, r3, #8 */
/* @0x15dcd8 sub sp, sp, r3 */
/* @0x15dcdc add r3, sp, #8 */
/* @0x15dce0 str r3, [r11, #-0x3c] */
/* @0x15dce4 addgt r9, r3, #12 */
/* @0x15dce8 movgt r10, r3 */
/* @0x15dcec ble 0x15ddb8 <_Z19ProcessGMLCallbacksv+0x1d0> */
/* @0x15dcf0 ldr r1, [r11, #-0x50] */
/* @0x15dcf4 str r7, [r11, #-0x38] */
/* @0x15dcf8 ldr r0, [r1] */
/* @0x15dcfc mov r1, r8 */
/* @0x15dd00 bl 0x20557c <_Z14DsQueueDequeueiR6RValue> */
/* @0x15dd04 ldr r2, [r10, #0xc] */
/* @0x15dd08 bic r3, r2, #-16777216 */
/* @0x15dd0c cmp r3, #1 */
/* @0x15dd10 beq 0x15deb8 <_Z19ProcessGMLCallbacksv+0x2d0> */
/* @0x15dd14 cmp r3, #2 */
/* @0x15dd18 bne 0x15dd3c <_Z19ProcessGMLCallbacksv+0x154> */
/* @0x15dd1c sub r2, r2, #1 */
/* @0x15dd20 bic r2, r2, #-16777216 */
/* @0x15dd24 bic r2, r2, #3 */
/* @0x15dd28 cmp r2, #0 */
/* @0x15dd2c beq 0x15df28 <_Z19ProcessGMLCallbacksv+0x340> */
/* @0x15dd30 mov r3, #5 */
/* @0x15dd34 str r7, [r10, #0x8] */
/* @0x15dd38 str r3, [r10, #0xc] */
/* @0x15dd3c ldr r1, [r11, #-0x2c] */
/* @0x15dd40 ldr r2, [r11, #-0x30] */
/* @0x15dd44 bic r3, r1, #-16777216 */
/* @0x15dd48 str r7, [r9, #-0xc] */
/* @0x15dd4c str r1, [r10, #0xc] */
/* @0x15dd50 str r2, [r10, #0x8] */
/* @0x15dd54 cmp r3, #14 */
/* @0x15dd58 addls pc, pc, r3, lsl #2 */
/* @0x15dd5c b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc> */
/* @0x15dd60 b 0x15de5c <_Z19ProcessGMLCallbacksv+0x274> */
/* @0x15dd64 b 0x15de44 <_Z19ProcessGMLCallbacksv+0x25c> */
/* @0x15dd68 b 0x15de6c <_Z19ProcessGMLCallbacksv+0x284> */
/* @0x15dd6c b 0x15dd9c <_Z19ProcessGMLCallbacksv+0x1b4> */
/* @0x15dd70 b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc> */
/* @0x15dd74 b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc> */
/* @0x15dd78 b 0x15de98 <_Z19ProcessGMLCallbacksv+0x2b0> */
/* @0x15dd7c b 0x15dd9c <_Z19ProcessGMLCallbacksv+0x1b4> */
/* @0x15dd80 b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc> */
/* @0x15dd84 b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc> */
/* @0x15dd88 b 0x15de30 <_Z19ProcessGMLCallbacksv+0x248> */
/* @0x15dd8c b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc> */
/* @0x15dd90 b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc> */
/* @0x15dd94 b 0x15de5c <_Z19ProcessGMLCallbacksv+0x274> */
/* @0x15dd98 b 0x15dd9c <_Z19ProcessGMLCallbacksv+0x1b4> */
/* @0x15dd9c ldr r3, [r11, #-0x38] */
/* @0x15dda0 str r3, [r9, #-0xc] */
/* @0x15dda4 add r4, r4, #1 */
/* @0x15dda8 add r9, r9, #16 */
/* @0x15ddac cmp r4, r5 */
/* @0x15ddb0 add r10, r10, #16 */
/* @0x15ddb4 bne 0x15dcf0 <_Z19ProcessGMLCallbacksv+0x108> */
/* @0x15ddb8 vldr d7, [r11, #-76] */
/* @0x15ddbc vcvt.s32.f64 s15, d7 */
/* @0x15ddc0 mov r1, #0 */
/* @0x15ddc4 mov r3, r5 */
/* @0x15ddc8 sub r12, r11, #64 */
/* @0x15ddcc str r8, [sp] */
/* @0x15ddd0 mov r2, r1 */
/* @0x15ddd4 str r12, [sp, #0x4] */
/* @0x15ddd8 vmov r0, s15 */
/* @0x15dddc bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue> */
/* @0x15dde0 ldr r3, [pc, #0x2bc] */
/* @0x15dde4 ldr r3, [pc, r3] */
/* @0x15dde8 ldrb r3, [r3] */
/* @0x15ddec cmp r3, #0 */
/* @0x15ddf0 bne 0x15df74 <_Z19ProcessGMLCallbacksv+0x38c> */
/* @0x15ddf4 ldr r1, [r11, #-0x58] */
/* @0x15ddf8 ldr r0, [r1] */
/* @0x15ddfc bl 0x2055c8 <_Z11DsQueueSizei> */
/* @0x15de00 cmp r0, #0 */
/* @0x15de04 bgt 0x15dc60 <_Z19ProcessGMLCallbacksv+0x78> */
/* @0x15de08 ldr r3, [pc, #0x298] */
/* @0x15de0c ldr r0, [pc, r3] */
/* @0x15de10 bl 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0x15de14 ldr r1, [r11, #-0x5c] */
/* @0x15de18 ldr r2, [r11, #-0x28] */
/* @0x15de1c ldr r3, [r1] */
/* @0x15de20 cmp r2, r3 */
/* @0x15de24 bne 0x15e088 <_Z19ProcessGMLCallbacksv+0x4a0> */
/* @0x15de28 sub sp, r11, #32 */
/* @0x15de2c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x15de30 ldr r2, [r11, #-0x38] */
/* @0x15de34 ldr r3, [r11, #-0x34] */
/* @0x15de38 str r2, [r9, #-0xc] */
/* @0x15de3c str r3, [r9, #-0x8] */
/* @0x15de40 b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc> */
/* @0x15de44 ldr r3, [r11, #-0x38] */
/* @0x15de48 cmp r3, #0 */
/* @0x15de4c ldrne r2, [r3, #0x4] */
/* @0x15de50 addne r2, r2, #1 */
/* @0x15de54 strne r2, [r3, #0x4] */
/* @0x15de58 b 0x15dda0 <_Z19ProcessGMLCallbacksv+0x1b8> */
/* @0x15de5c ldr r2, [r11, #-0x38] */
/* @0x15de60 ldr r3, [r11, #-0x34] */
/* @0x15de64 strd r2, r3, [r9, #-12] */
/* @0x15de68 b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc> */
/* @0x15de6c ldr r3, [r11, #-0x38] */
/* @0x15de70 cmp r3, #0 */
/* @0x15de74 str r3, [r9, #-0xc] */
/* @0x15de78 beq 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc> */
/* @0x15de7c ldr r1, [r3, #0x8] */
/* @0x15de80 ldr r2, [r3] */
/* @0x15de84 cmp r1, #0 */
/* @0x15de88 streq r10, [r3, #0x8] */
/* @0x15de8c add r2, r2, #1 */
/* @0x15de90 str r2, [r3] */
/* @0x15de94 b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc> */
/* @0x15de98 ldr r2, [r11, #-0x38] */
/* @0x15de9c subs r3, r2, #0 */
/* @0x15dea0 str r3, [r9, #-0xc] */
/* @0x15dea4 beq 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc> */
/* @0x15dea8 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x15deac ldr r1, [r11, #-0x38] */
/* @0x15deb0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x15deb4 b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc> */
/* @0x15deb8 ldr r6, [r9, #-0xc] */
/* @0x15debc cmp r6, #0 */
/* @0x15dec0 beq 0x15dee0 <_Z19ProcessGMLCallbacksv+0x2f8> */
/* @0x15dec4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x15dec8 ldr r2, [r6, #0x4] */
/* @0x15decc sub r2, r2, #1 */
/* @0x15ded0 str r2, [r6, #0x4] */
/* @0x15ded4 cmp r2, #0 */
/* @0x15ded8 beq 0x15dee8 <_Z19ProcessGMLCallbacksv+0x300> */
/* @0x15dedc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x15dee0 str r7, [r9, #-0xc] */
/* @0x15dee4 b 0x15dd3c <_Z19ProcessGMLCallbacksv+0x154> */
/* @0x15dee8 ldr r0, [r6] */
/* @0x15deec str r2, [r11, #-0x60] */
/* @0x15def0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x15def4 ldr r2, [r11, #-0x60] */
/* @0x15def8 str r2, [r6] */
/* @0x15defc str r2, [r6, #0x8] */
/* @0x15df00 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x15df04 ldr r2, [r6, #0x4] */
/* @0x15df08 sub r2, r2, #1 */
/* @0x15df0c str r2, [r6, #0x4] */
/* @0x15df10 cmp r2, #0 */
/* @0x15df14 beq 0x15df34 <_Z19ProcessGMLCallbacksv+0x34c> */
/* @0x15df18 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x15df1c mov r0, r6 */
/* @0x15df20 bl 0x27d1d0 <_ZdlPv> */
/* @0x15df24 b 0x15dedc <_Z19ProcessGMLCallbacksv+0x2f4> */
/* @0x15df28 mov r0, r10 */
/* @0x15df2c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x15df30 b 0x15dd30 <_Z19ProcessGMLCallbacksv+0x148> */
/* @0x15df34 ldr r0, [r6] */
/* @0x15df38 str r2, [r11, #-0x60] */
/* @0x15df3c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x15df40 ldr r2, [r11, #-0x60] */
/* @0x15df44 str r2, [r6] */
/* @0x15df48 str r2, [r6, #0x8] */
/* @0x15df4c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x15df50 ldr r2, [r6, #0x4] */
/* @0x15df54 sub r2, r2, #1 */
/* @0x15df58 str r2, [r6, #0x4] */
/* @0x15df5c cmp r2, #0 */
/* @0x15df60 beq 0x15df90 <_Z19ProcessGMLCallbacksv+0x3a8> */
/* @0x15df64 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x15df68 mov r0, r6 */
/* @0x15df6c bl 0x27d1d0 <_ZdlPv> */
/* @0x15df70 b 0x15df18 <_Z19ProcessGMLCallbacksv+0x330> */
/* @0x15df74 ldr r3, [pc, #0x130] */
/* @0x15df78 mov r1, #0 */
/* @0x15df7c ldr r3, [pc, r3] */
/* @0x15df80 ldr r3, [r3] */
/* @0x15df84 ldr r0, [r3] */
/* @0x15df88 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x15df8c b 0x15ddf4 <_Z19ProcessGMLCallbacksv+0x20c> */
/* @0x15df90 ldr r0, [r6] */
/* @0x15df94 str r2, [r11, #-0x60] */
/* @0x15df98 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x15df9c ldr r2, [r11, #-0x60] */
/* @0x15dfa0 str r2, [r6] */
/* @0x15dfa4 str r2, [r6, #0x8] */
/* @0x15dfa8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x15dfac ldr r2, [r6, #0x4] */
/* @0x15dfb0 sub r2, r2, #1 */
/* @0x15dfb4 str r2, [r6, #0x4] */
/* @0x15dfb8 cmp r2, #0 */
/* @0x15dfbc beq 0x15dfdc <_Z19ProcessGMLCallbacksv+0x3f4> */
/* @0x15dfc0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x15dfc4 mov r0, r6 */
/* @0x15dfc8 bl 0x27d1d0 <_ZdlPv> */
/* @0x15dfcc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x15dfd0 mov r0, r6 */
/* @0x15dfd4 bl 0x27d1d0 <_ZdlPv> */
/* @0x15dfd8 b 0x15df18 <_Z19ProcessGMLCallbacksv+0x330> */
/* @0x15dfdc ldr r0, [r6] */
/* @0x15dfe0 str r2, [r11, #-0x60] */
/* @0x15dfe4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x15dfe8 ldr r2, [r11, #-0x60] */
/* @0x15dfec str r2, [r6] */
/* @0x15dff0 str r2, [r6, #0x8] */
/* @0x15dff4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x15dff8 ldr r2, [r6, #0x4] */
/* @0x15dffc sub r2, r2, #1 */
/* @0x15e000 str r2, [r6, #0x4] */
/* @0x15e004 cmp r2, #0 */
/* @0x15e008 beq 0x15e01c <_Z19ProcessGMLCallbacksv+0x434> */
/* @0x15e00c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x15e010 mov r0, r6 */
/* @0x15e014 bl 0x27d1d0 <_ZdlPv> */
/* @0x15e018 b 0x15dfc0 <_Z19ProcessGMLCallbacksv+0x3d8> */
/* @0x15e01c ldr r0, [r6] */
/* @0x15e020 str r2, [r11, #-0x60] */
/* @0x15e024 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x15e028 ldr r2, [r11, #-0x60] */
/* @0x15e02c str r2, [r6] */
/* @0x15e030 str r2, [r6, #0x8] */
/* @0x15e034 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x15e038 ldr r2, [r6, #0x4] */
/* @0x15e03c sub r2, r2, #1 */
/* @0x15e040 str r2, [r6, #0x4] */
/* @0x15e044 cmp r2, #0 */
/* @0x15e048 beq 0x15e05c <_Z19ProcessGMLCallbacksv+0x474> */
/* @0x15e04c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x15e050 mov r0, r6 */
/* @0x15e054 bl 0x27d1d0 <_ZdlPv> */
/* @0x15e058 b 0x15e00c <_Z19ProcessGMLCallbacksv+0x424> */
/* @0x15e05c ldr r0, [r6] */
/* @0x15e060 str r2, [r11, #-0x60] */
/* @0x15e064 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x15e068 ldr r2, [r11, #-0x60] */
/* @0x15e06c mov r0, r6 */
/* @0x15e070 str r2, [r6] */
/* @0x15e074 str r2, [r6, #0x8] */
/* @0x15e078 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x15e07c mov r0, r6 */
/* @0x15e080 bl 0x27d1d0 <_ZdlPv> */
/* @0x15e084 b 0x15e04c <_Z19ProcessGMLCallbacksv+0x464> */
/* @0x15e088 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x15e08c eoreq pc, r8, r4, asr sp */
/* @0x15e090 eorseq r6, r2, r4, ror #28 */
/* @0x15e094 eoreq r4, r9, r12, lsr r7 */
/* @0x15e098 eoreq r4, r9, r0, lsr #14 */
/* @0x15e09c eoreq r4, r9, r4, lsl r7 */
/* @0x15e0a0 eoreq r4, r9, r12, lsl #14 */
/* @0x15e0a4 eoreq pc, r8, r0, lsl #27 */
/* @0x15e0a8 eorseq r6, r2, r12, asr r12 */
/* @0x15e0ac .word 0x0028fbf4 */

/* ── FUNC 0x15e0b0 · _JNIEnv::CallStaticBooleanMethod(_jclass*, _jmethodID*, ...) · size=56 · insn=14 */
/* @0x15e0b0 push {r2, r3} */
/* @0x15e0b4 str lr, [sp, #-0x4]! */
/* @0x15e0b8 sub sp, sp, #12 */
/* @0x15e0bc ldr lr, [r0] */
/* @0x15e0c0 add r12, sp, #20 */
/* @0x15e0c4 ldr r2, [sp, #0x10] */
/* @0x15e0c8 mov r3, r12 */
/* @0x15e0cc str r12, [sp, #0x4] */
/* @0x15e0d0 ldr r12, [lr, #0x1d8] */
/* @0x15e0d4 blx r12 */
/* @0x15e0d8 add sp, sp, #12 */
/* @0x15e0dc ldr lr, [sp], #4 */
/* @0x15e0e0 add sp, sp, #8 */
/* @0x15e0e4 bx lr */

/* ── FUNC 0x15e0e8 · YYStrBuilderYY::AddFormat(char const*, ...) · size=416 · insn=104 */
/* @0x15e0e8 push {r1, r2, r3} */
/* @0x15e0ec push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x15e0f0 sub sp, sp, #12 */
/* @0x15e0f4 mov r4, r0 */
/* @0x15e0f8 add r6, sp, #48 */
/* @0x15e0fc ldr r7, [sp, #0x2c] */
/* @0x15e100 str r6, [sp] */
/* @0x15e104 mov r0, r7 */
/* @0x15e108 bl 0xb6538 <strlen@plt> */
/* @0x15e10c ldr r3, [r4, #0x8] */
/* @0x15e110 ldr r5, [r4, #0x4] */
/* @0x15e114 mvn r1, r3 */
/* @0x15e118 add r1, r5, r1 */
/* @0x15e11c cmp r0, #16 */
/* @0x15e120 movhs r2, r0 */
/* @0x15e124 movlo r2, #16 */
/* @0x15e128 mov r8, r0 */
/* @0x15e12c cmp r2, r1 */
/* @0x15e130 bgt 0x15e224 <_ZN14YYStrBuilderYY9AddFormatEPKcz+0x13c> */
/* @0x15e134 cmp r8, #32 */
/* @0x15e138 movlo r8, #32 */
/* @0x15e13c ldr r2, [r4] */
/* @0x15e140 mov r1, #0 */
/* @0x15e144 add r8, r8, r8, lsl #1 */
/* @0x15e148 strb r1, [r2, r3] */
/* @0x15e14c add r8, r8, r8, lsr #31 */
/* @0x15e150 asr r8, r8, #1 */
/* @0x15e154 ldr r1, [r4, #0x8] */
/* @0x15e158 mov r3, r6 */
/* @0x15e15c ldr r12, [r4, #0x4] */
/* @0x15e160 mov r2, r7 */
/* @0x15e164 ldr r0, [r4] */
/* @0x15e168 mvn r5, r1 */
/* @0x15e16c add r5, r5, r12 */
/* @0x15e170 add r0, r0, r1 */
/* @0x15e174 str r6, [sp, #0x4] */
/* @0x15e178 mov r1, r5 */
/* @0x15e17c bl 0xb6610 <vsnprintf@plt> */
/* @0x15e180 lsr r3, r0, #31 */
/* @0x15e184 cmp r5, r0 */
/* @0x15e188 movge r5, r3 */
/* @0x15e18c orrlt r5, r3, #1 */
/* @0x15e190 cmp r5, #0 */
/* @0x15e194 bne 0x15e1bc <_ZN14YYStrBuilderYY9AddFormatEPKcz+0xd4> */
/* @0x15e198 ldr r2, [r4, #0x8] */
/* @0x15e19c ldr r3, [r4] */
/* @0x15e1a0 add r0, r0, r2 */
/* @0x15e1a4 str r0, [r4, #0x8] */
/* @0x15e1a8 strb r5, [r3, r0] */
/* @0x15e1ac add sp, sp, #12 */
/* @0x15e1b0 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x15e1b4 add sp, sp, #12 */
/* @0x15e1b8 bx lr */
/* @0x15e1bc ldr r5, [r4, #0x4] */
/* @0x15e1c0 ldr r2, [r4, #0x8] */
/* @0x15e1c4 cmp r5, #0 */
/* @0x15e1c8 add r3, r8, r5 */
/* @0x15e1cc ldr r10, [r4] */
/* @0x15e1d0 moveq r9, r3 */
/* @0x15e1d4 movne r9, r5 */
/* @0x15e1d8 add r3, r3, r2 */
/* @0x15e1dc add r9, r9, r9, lsl #1 */
/* @0x15e1e0 add r2, r3, r3, lsl #1 */
/* @0x15e1e4 add r9, r9, r9, lsr #31 */
/* @0x15e1e8 add r2, r2, r2, lsr #31 */
/* @0x15e1ec asr r9, r9, #1 */
/* @0x15e1f0 cmp r9, r3 */
/* @0x15e1f4 asrlt r9, r2, #1 */
/* @0x15e1f8 mov r0, r9 */
/* @0x15e1fc bl 0xb6544 <malloc@plt> */
/* @0x15e200 mov r2, r5 */
/* @0x15e204 mov r1, r10 */
/* @0x15e208 str r0, [r4] */
/* @0x15e20c bl 0xb65bc <memcpy@plt> */
/* @0x15e210 subs r0, r10, #0 */
/* @0x15e214 str r9, [r4, #0x4] */
/* @0x15e218 beq 0x15e154 <_ZN14YYStrBuilderYY9AddFormatEPKcz+0x6c> */
/* @0x15e21c bl 0xb655c <free@plt> */
/* @0x15e220 b 0x15e154 <_ZN14YYStrBuilderYY9AddFormatEPKcz+0x6c> */
/* @0x15e224 cmp r5, #0 */
/* @0x15e228 add r3, r2, r3 */
/* @0x15e22c ldr r10, [r4] */
/* @0x15e230 moveq r9, r2 */
/* @0x15e234 movne r9, r5 */
/* @0x15e238 add r9, r9, r9, lsl #1 */
/* @0x15e23c add r9, r9, r9, lsr #31 */
/* @0x15e240 asr r9, r9, #1 */
/* @0x15e244 cmp r9, r3 */
/* @0x15e248 addlt r3, r3, r3, lsl #1 */
/* @0x15e24c addlt r3, r3, r3, lsr #31 */
/* @0x15e250 asrlt r9, r3, #1 */
/* @0x15e254 mov r0, r9 */
/* @0x15e258 bl 0xb6544 <malloc@plt> */
/* @0x15e25c mov r2, r5 */
/* @0x15e260 mov r1, r10 */
/* @0x15e264 str r0, [r4] */
/* @0x15e268 bl 0xb65bc <memcpy@plt> */
/* @0x15e26c cmp r10, #0 */
/* @0x15e270 str r9, [r4, #0x4] */
/* @0x15e274 beq 0x15e280 <_ZN14YYStrBuilderYY9AddFormatEPKcz+0x198> */
/* @0x15e278 mov r0, r10 */
/* @0x15e27c bl 0xb655c <free@plt> */
/* @0x15e280 ldr r3, [r4, #0x8] */
/* @0x15e284 b 0x15e134 <_ZN14YYStrBuilderYY9AddFormatEPKcz+0x4c> */

/* ── FUNC 0x15e288 · GetOrientation · size=20 · insn=5 */
/* @0x15e288 ldr r3, [pc, #0x8] */
/* @0x15e28c ldr r3, [pc, r3] */
/* @0x15e290 ldr r0, [r3] */
/* @0x15e294 bx lr */
/* @0x15e298 eoreq r1, r9, r0, ror #23 */

/* ── FUNC 0x15e29c · UpdateYoYoFunctionsM() · size=4 · insn=1 */
/* @0x15e29c bx lr */

/* ── FUNC 0x15e2a0 · QuitYoYoFunctionsM() · size=4 · insn=1 */
/* @0x15e2a0 bx lr */

/* ── FUNC 0x15e2a4 · InitYoYoConstantsM() · size=4 · insn=1 */
/* @0x15e2a4 bx lr */

/* ── FUNC 0x15e2a8 · InitYoYoFunctionsM() · size=16 · insn=4 */
/* @0x15e2a8 push {r3, lr} */
/* @0x15e2ac bl 0x160f44 <_Z30AreOnlineAchievementsAvailablev> */
/* @0x15e2b0 pop {r3, lr} */
/* @0x15e2b4 b 0x159a60 <_Z21Set_AchievementSystemb> */

/* ── FUNC 0x15e2b8 · DisplaySetUIVisibility(int) · size=56 · insn=14 */
/* @0x15e2b8 push {r4, lr} */
/* @0x15e2bc mov r4, r0 */
/* @0x15e2c0 bl 0x290274 <getJNIEnv> */
/* @0x15e2c4 ldr r1, [pc, #0x1c] */
/* @0x15e2c8 mov r3, r4 */
/* @0x15e2cc ldr r2, [pc, #0x18] */
/* @0x15e2d0 ldr r1, [pc, r1] */
/* @0x15e2d4 ldr r2, [pc, r2] */
/* @0x15e2d8 ldr r1, [r1] */
/* @0x15e2dc ldr r2, [r2] */
/* @0x15e2e0 pop {r4, lr} */
/* @0x15e2e4 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x15e2e8 .word 0x0028f6d4 */
/* @0x15e2ec mlaeq r9, r12, r11, r1 */

/* ── FUNC 0x15e2f0 · AdsSetup(char*) · size=80 · insn=20 */
/* @0x15e2f0 push {r4, lr} */
/* @0x15e2f4 mov r4, r0 */
/* @0x15e2f8 bl 0x290274 <getJNIEnv> */
/* @0x15e2fc mov r1, r4 */
/* @0x15e300 ldr r3, [r0] */
/* @0x15e304 ldr r3, [r3, #0x29c] */
/* @0x15e308 blx r3 */
/* @0x15e30c mov r4, r0 */
/* @0x15e310 bl 0x290274 <getJNIEnv> */
/* @0x15e314 ldr r1, [pc, #0x1c] */
/* @0x15e318 mov r3, r4 */
/* @0x15e31c ldr r2, [pc, #0x18] */
/* @0x15e320 ldr r1, [pc, r1] */
/* @0x15e324 ldr r2, [pc, r2] */
/* @0x15e328 ldr r1, [r1] */
/* @0x15e32c ldr r2, [r2] */
/* @0x15e330 pop {r4, lr} */
/* @0x15e334 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x15e338 eoreq pc, r8, r4, lsl #13 */
/* @0x15e33c eoreq r1, r9, r0, asr r11 */

/* ── FUNC 0x15e340 · MoveAd(int, int, int) · size=80 · insn=20 */
/* @0x15e340 push {r4, r5, r6, lr} */
/* @0x15e344 sub sp, sp, #8 */
/* @0x15e348 mov r5, r1 */
/* @0x15e34c mov r4, r2 */
/* @0x15e350 mov r6, r0 */
/* @0x15e354 bl 0x290274 <getJNIEnv> */
/* @0x15e358 ldr lr, [pc, #0x28] */
/* @0x15e35c mov r3, r6 */
/* @0x15e360 ldr r12, [pc, #0x24] */
/* @0x15e364 ldr lr, [pc, lr] */
/* @0x15e368 ldr r12, [pc, r12] */
/* @0x15e36c ldr r1, [lr] */
/* @0x15e370 ldr r2, [r12] */
/* @0x15e374 str r5, [sp] */
/* @0x15e378 str r4, [sp, #0x4] */
/* @0x15e37c bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x15e380 add sp, sp, #8 */
/* @0x15e384 pop {r4, r5, r6, pc} */
/* @0x15e388 eoreq pc, r8, r0, asr #12 */
/* @0x15e38c eoreq r1, r9, r0, lsl r11 */

/* ── FUNC 0x15e390 · EnableAdServing(int, int, int) · size=88 · insn=22 */
/* @0x15e390 push {r4, r5, r6, lr} */
/* @0x15e394 sub sp, sp, #8 */
/* @0x15e398 mov r5, r1 */
/* @0x15e39c mov r4, r2 */
/* @0x15e3a0 mov r6, r0 */
/* @0x15e3a4 bl 0x290274 <getJNIEnv> */
/* @0x15e3a8 ldr lr, [pc, #0x30] */
/* @0x15e3ac mov r3, r6 */
/* @0x15e3b0 ldr r12, [pc, #0x2c] */
/* @0x15e3b4 ldr lr, [pc, lr] */
/* @0x15e3b8 ldr r12, [pc, r12] */
/* @0x15e3bc ldr r1, [lr] */
/* @0x15e3c0 ldr r2, [r12] */
/* @0x15e3c4 str r5, [sp] */
/* @0x15e3c8 str r4, [sp, #0x4] */
/* @0x15e3cc bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x15e3d0 mov r0, #0 */
/* @0x15e3d4 mov r1, #0 */
/* @0x15e3d8 add sp, sp, #8 */
/* @0x15e3dc pop {r4, r5, r6, pc} */
/* @0x15e3e0 .word 0x0028f5f0 */
/* @0x15e3e4 eoreq r1, r9, r4, asr #21 */

/* ── FUNC 0x15e3e8 · DisableAdServing(int) · size=64 · insn=16 */
/* @0x15e3e8 push {r4, lr} */
/* @0x15e3ec mov r4, r0 */
/* @0x15e3f0 bl 0x290274 <getJNIEnv> */
/* @0x15e3f4 ldr r1, [pc, #0x24] */
/* @0x15e3f8 mov r3, r4 */
/* @0x15e3fc ldr r2, [pc, #0x20] */
/* @0x15e400 ldr r1, [pc, r1] */
/* @0x15e404 ldr r2, [pc, r2] */
/* @0x15e408 ldr r1, [r1] */
/* @0x15e40c ldr r2, [r2] */
/* @0x15e410 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x15e414 mov r0, #0 */
/* @0x15e418 mov r1, #0 */
/* @0x15e41c pop {r4, pc} */
/* @0x15e420 eoreq pc, r8, r4, lsr #11 */
/* @0x15e424 eoreq r1, r9, r12, ror r10 */

/* ── FUNC 0x15e428 · AdsEvent(char*) · size=80 · insn=20 */
/* @0x15e428 push {r4, lr} */
/* @0x15e42c mov r4, r0 */
/* @0x15e430 bl 0x290274 <getJNIEnv> */
/* @0x15e434 mov r1, r4 */
/* @0x15e438 ldr r3, [r0] */
/* @0x15e43c ldr r3, [r3, #0x29c] */
/* @0x15e440 blx r3 */
/* @0x15e444 mov r4, r0 */
/* @0x15e448 bl 0x290274 <getJNIEnv> */
/* @0x15e44c ldr r1, [pc, #0x1c] */
/* @0x15e450 mov r3, r4 */
/* @0x15e454 ldr r2, [pc, #0x18] */
/* @0x15e458 ldr r1, [pc, r1] */
/* @0x15e45c ldr r2, [pc, r2] */
/* @0x15e460 ldr r1, [r1] */
/* @0x15e464 ldr r2, [r2] */
/* @0x15e468 pop {r4, lr} */
/* @0x15e46c b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x15e470 eoreq pc, r8, r12, asr #10 */
/* @0x15e474 eoreq r1, r9, r8, lsr #20 */

/* ── FUNC 0x15e478 · AdsPreload(char*) · size=80 · insn=20 */
/* @0x15e478 push {r4, lr} */
/* @0x15e47c mov r4, r0 */
/* @0x15e480 bl 0x290274 <getJNIEnv> */
/* @0x15e484 mov r1, r4 */
/* @0x15e488 ldr r3, [r0] */
/* @0x15e48c ldr r3, [r3, #0x29c] */
/* @0x15e490 blx r3 */
/* @0x15e494 mov r4, r0 */
/* @0x15e498 bl 0x290274 <getJNIEnv> */
/* @0x15e49c ldr r1, [pc, #0x1c] */
/* @0x15e4a0 mov r3, r4 */
/* @0x15e4a4 ldr r2, [pc, #0x18] */
/* @0x15e4a8 ldr r1, [pc, r1] */
/* @0x15e4ac ldr r2, [pc, r2] */
/* @0x15e4b0 ldr r1, [r1] */
/* @0x15e4b4 ldr r2, [r2] */
/* @0x15e4b8 pop {r4, lr} */
/* @0x15e4bc b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x15e4c0 .word 0x0028f4fc */
/* @0x15e4c4 .word 0x002919dc */

/* ── FUNC 0x15e4c8 · AdDisplayWidth(int) · size=56 · insn=14 */
/* @0x15e4c8 push {r4, lr} */
/* @0x15e4cc mov r4, r0 */
/* @0x15e4d0 bl 0x290274 <getJNIEnv> */
/* @0x15e4d4 ldr r1, [pc, #0x1c] */
/* @0x15e4d8 mov r3, r4 */
/* @0x15e4dc ldr r2, [pc, #0x18] */
/* @0x15e4e0 ldr r1, [pc, r1] */
/* @0x15e4e4 ldr r2, [pc, r2] */
/* @0x15e4e8 ldr r1, [r1] */
/* @0x15e4ec ldr r2, [r2] */
/* @0x15e4f0 pop {r4, lr} */
/* @0x15e4f4 b 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x15e4f8 eoreq pc, r8, r4, asr #9 */
/* @0x15e4fc eoreq r1, r9, r8, lsr #19 */

/* ── FUNC 0x15e500 · AdDisplayHeight(int) · size=56 · insn=14 */
/* @0x15e500 push {r4, lr} */
/* @0x15e504 mov r4, r0 */
/* @0x15e508 bl 0x290274 <getJNIEnv> */
/* @0x15e50c ldr r1, [pc, #0x1c] */
/* @0x15e510 mov r3, r4 */
/* @0x15e514 ldr r2, [pc, #0x18] */
/* @0x15e518 ldr r1, [pc, r1] */
/* @0x15e51c ldr r2, [pc, r2] */
/* @0x15e520 ldr r1, [r1] */
/* @0x15e524 ldr r2, [r2] */
/* @0x15e528 pop {r4, lr} */
/* @0x15e52c b 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x15e530 eoreq pc, r8, r12, lsl #9 */
/* @0x15e534 eoreq r1, r9, r4, ror r9 */

/* ── FUNC 0x15e538 · LeaveRating(char*, char const*, char const*, char const*) · size=192 · insn=48 */
/* @0x15e538 push {r4, r5, r6, r7, lr} */
/* @0x15e53c sub sp, sp, #20 */
/* @0x15e540 mov r4, r2 */
/* @0x15e544 mov r6, r1 */
/* @0x15e548 mov r7, r3 */
/* @0x15e54c mov r5, r0 */
/* @0x15e550 bl 0x290274 <getJNIEnv> */
/* @0x15e554 mov r1, r7 */
/* @0x15e558 ldr r3, [r0] */
/* @0x15e55c ldr r3, [r3, #0x29c] */
/* @0x15e560 blx r3 */
/* @0x15e564 mov r7, r0 */
/* @0x15e568 bl 0x290274 <getJNIEnv> */
/* @0x15e56c mov r1, r4 */
/* @0x15e570 ldr r3, [r0] */
/* @0x15e574 ldr r3, [r3, #0x29c] */
/* @0x15e578 blx r3 */
/* @0x15e57c mov r4, r0 */
/* @0x15e580 bl 0x290274 <getJNIEnv> */
/* @0x15e584 mov r1, r6 */
/* @0x15e588 ldr r3, [r0] */
/* @0x15e58c ldr r3, [r3, #0x29c] */
/* @0x15e590 blx r3 */
/* @0x15e594 mov r6, r0 */
/* @0x15e598 bl 0x290274 <getJNIEnv> */
/* @0x15e59c mov r1, r5 */
/* @0x15e5a0 ldr r3, [r0] */
/* @0x15e5a4 ldr r3, [r3, #0x29c] */
/* @0x15e5a8 blx r3 */
/* @0x15e5ac mov r5, r0 */
/* @0x15e5b0 bl 0x290274 <getJNIEnv> */
/* @0x15e5b4 ldr r1, [pc, #0x34] */
/* @0x15e5b8 mov r3, r5 */
/* @0x15e5bc ldr r2, [pc, #0x30] */
/* @0x15e5c0 ldr r1, [pc, r1] */
/* @0x15e5c4 ldr r2, [pc, r2] */
/* @0x15e5c8 ldr r1, [r1] */
/* @0x15e5cc ldr r2, [r2] */
/* @0x15e5d0 str r7, [sp, #0x8] */
/* @0x15e5d4 str r6, [sp] */
/* @0x15e5d8 str r4, [sp, #0x4] */
/* @0x15e5dc bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x15e5e0 mov r0, #0 */
/* @0x15e5e4 mov r1, #0 */
/* @0x15e5e8 add sp, sp, #20 */
/* @0x15e5ec pop {r4, r5, r6, r7, pc} */
/* @0x15e5f0 eoreq pc, r8, r4, ror #7 */
/* @0x15e5f4 .word 0x002918d0 */
