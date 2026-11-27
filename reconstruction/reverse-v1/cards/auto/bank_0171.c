/* libyoyo.so 覆盖卡组 0171
 * 函数 0x1f7f4c..0x1f8850，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1f7f4c · GV_BackgroundXScale(CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1f7f4c ldr r3, [pc, #0x44] */
/* @0x1f7f50 cmp r1, #7 */
/* @0x1f7f54 push {r4, r5} */
/* @0x1f7f58 ldr r3, [pc, r3] */
/* @0x1f7f5c movhi r1, #0 */
/* @0x1f7f60 mov r0, #0 */
/* @0x1f7f64 ldr r3, [r3] */
/* @0x1f7f68 str r0, [r2, #0xc] */
/* @0x1f7f6c mov r0, #1 */
/* @0x1f7f70 add r1, r3, r1, lsl #2 */
/* @0x1f7f74 ldr r3, [r1, #0x24] */
/* @0x1f7f78 vldr s15, [r3, #28] */
/* @0x1f7f7c vcvt.f64.f32 d6, s15 */
/* @0x1f7f80 vmov r4, r5, d6 */
/* @0x1f7f84 vmov r1, s12 */
/* @0x1f7f88 mov r3, r5 */
/* @0x1f7f8c pop {r4, r5} */
/* @0x1f7f90 stm r2, {r1, r3} */
/* @0x1f7f94 bx lr */
/* @0x1f7f98 ldrsbeq r5, [pc], -r0 */

/* ── FUNC 0x1f7f9c · GV_BackgroundYScale(CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1f7f9c ldr r3, [pc, #0x44] */
/* @0x1f7fa0 cmp r1, #7 */
/* @0x1f7fa4 push {r4, r5} */
/* @0x1f7fa8 ldr r3, [pc, r3] */
/* @0x1f7fac movhi r1, #0 */
/* @0x1f7fb0 mov r0, #0 */
/* @0x1f7fb4 ldr r3, [r3] */
/* @0x1f7fb8 str r0, [r2, #0xc] */
/* @0x1f7fbc mov r0, #1 */
/* @0x1f7fc0 add r1, r3, r1, lsl #2 */
/* @0x1f7fc4 ldr r3, [r1, #0x24] */
/* @0x1f7fc8 vldr s15, [r3, #32] */
/* @0x1f7fcc vcvt.f64.f32 d6, s15 */
/* @0x1f7fd0 vmov r4, r5, d6 */
/* @0x1f7fd4 vmov r1, s12 */
/* @0x1f7fd8 mov r3, r5 */
/* @0x1f7fdc pop {r4, r5} */
/* @0x1f7fe0 stm r2, {r1, r3} */
/* @0x1f7fe4 bx lr */
/* @0x1f7fe8 andseq r5, pc, r0, lsl #19 */

/* ── FUNC 0x1f7fec · GV_BackgroundHSpeed(CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1f7fec ldr r3, [pc, #0x44] */
/* @0x1f7ff0 cmp r1, #7 */
/* @0x1f7ff4 push {r4, r5} */
/* @0x1f7ff8 ldr r3, [pc, r3] */
/* @0x1f7ffc movhi r1, #0 */
/* @0x1f8000 mov r0, #0 */
/* @0x1f8004 ldr r3, [r3] */
/* @0x1f8008 str r0, [r2, #0xc] */
/* @0x1f800c mov r0, #1 */
/* @0x1f8010 add r1, r3, r1, lsl #2 */
/* @0x1f8014 ldr r3, [r1, #0x24] */
/* @0x1f8018 vldr s15, [r3, #20] */
/* @0x1f801c vcvt.f64.f32 d6, s15 */
/* @0x1f8020 vmov r4, r5, d6 */
/* @0x1f8024 vmov r1, s12 */
/* @0x1f8028 mov r3, r5 */
/* @0x1f802c pop {r4, r5} */
/* @0x1f8030 stm r2, {r1, r3} */
/* @0x1f8034 bx lr */
/* @0x1f8038 andseq r5, pc, r0, lsr r9 */

/* ── FUNC 0x1f803c · GV_BackgroundVSpeed(CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1f803c ldr r3, [pc, #0x44] */
/* @0x1f8040 cmp r1, #7 */
/* @0x1f8044 push {r4, r5} */
/* @0x1f8048 ldr r3, [pc, r3] */
/* @0x1f804c movhi r1, #0 */
/* @0x1f8050 mov r0, #0 */
/* @0x1f8054 ldr r3, [r3] */
/* @0x1f8058 str r0, [r2, #0xc] */
/* @0x1f805c mov r0, #1 */
/* @0x1f8060 add r1, r3, r1, lsl #2 */
/* @0x1f8064 ldr r3, [r1, #0x24] */
/* @0x1f8068 vldr s15, [r3, #24] */
/* @0x1f806c vcvt.f64.f32 d6, s15 */
/* @0x1f8070 vmov r4, r5, d6 */
/* @0x1f8074 vmov r1, s12 */
/* @0x1f8078 mov r3, r5 */
/* @0x1f807c pop {r4, r5} */
/* @0x1f8080 stm r2, {r1, r3} */
/* @0x1f8084 bx lr */
/* @0x1f8088 andseq r5, pc, r0, ror #17 */

/* ── FUNC 0x1f808c · GV_BackgroundBlend(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1f808c ldr r3, [pc, #0x48] */
/* @0x1f8090 cmp r1, #7 */
/* @0x1f8094 push {r4, r5} */
/* @0x1f8098 ldr r3, [pc, r3] */
/* @0x1f809c movhi r1, #0 */
/* @0x1f80a0 mov r0, #0 */
/* @0x1f80a4 ldr r3, [r3] */
/* @0x1f80a8 str r0, [r2, #0xc] */
/* @0x1f80ac mov r0, #1 */
/* @0x1f80b0 add r1, r3, r1, lsl #2 */
/* @0x1f80b4 ldr r3, [r1, #0x24] */
/* @0x1f80b8 ldr r4, [r3, #0x24] */
/* @0x1f80bc vmov s15, r4 */
/* @0x1f80c0 vcvt.f64.s32 d7, s15 */
/* @0x1f80c4 vmov r4, r5, d7 */
/* @0x1f80c8 vmov r1, s14 */
/* @0x1f80cc mov r3, r5 */
/* @0x1f80d0 pop {r4, r5} */
/* @0x1f80d4 stm r2, {r1, r3} */
/* @0x1f80d8 bx lr */
/* @0x1f80dc mulseq pc, r0, r8 */

/* ── FUNC 0x1f80e0 · GV_BackgroundAlpha(CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1f80e0 ldr r3, [pc, #0x44] */
/* @0x1f80e4 cmp r1, #7 */
/* @0x1f80e8 push {r4, r5} */
/* @0x1f80ec ldr r3, [pc, r3] */
/* @0x1f80f0 movhi r1, #0 */
/* @0x1f80f4 mov r0, #0 */
/* @0x1f80f8 ldr r3, [r3] */
/* @0x1f80fc str r0, [r2, #0xc] */
/* @0x1f8100 mov r0, #1 */
/* @0x1f8104 add r1, r3, r1, lsl #2 */
/* @0x1f8108 ldr r3, [r1, #0x24] */
/* @0x1f810c vldr s15, [r3, #40] */
/* @0x1f8110 vcvt.f64.f32 d6, s15 */
/* @0x1f8114 vmov r4, r5, d6 */
/* @0x1f8118 vmov r1, s12 */
/* @0x1f811c mov r3, r5 */
/* @0x1f8120 pop {r4, r5} */
/* @0x1f8124 stm r2, {r1, r3} */
/* @0x1f8128 bx lr */
/* @0x1f812c andseq r5, pc, r12, lsr r8 */

/* ── FUNC 0x1f8130 · GV_ViewEnabled(CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x1f8130 ldr r3, [pc, #0x38] */
/* @0x1f8134 mov r1, #0 */
/* @0x1f8138 push {r4, r5} */
/* @0x1f813c ldr r3, [pc, r3] */
/* @0x1f8140 str r1, [r2, #0xc] */
/* @0x1f8144 mov r0, #1 */
/* @0x1f8148 ldr r3, [r3] */
/* @0x1f814c ldrb r4, [r3, #0x44] */
/* @0x1f8150 vmov s15, r4 */
/* @0x1f8154 vcvt.f64.u32 d7, s15 */
/* @0x1f8158 vmov r4, r5, d7 */
/* @0x1f815c vmov r1, s14 */
/* @0x1f8160 mov r3, r5 */
/* @0x1f8164 pop {r4, r5} */
/* @0x1f8168 stm r2, {r1, r3} */
/* @0x1f816c bx lr */
/* @0x1f8170 andseq r5, pc, r12, ror #15 */

/* ── FUNC 0x1f8174 · GV_ViewCurrent(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f8174 ldr r3, [pc, #0x34] */
/* @0x1f8178 mov r1, #0 */
/* @0x1f817c push {r4, r5} */
/* @0x1f8180 ldr r3, [pc, r3] */
/* @0x1f8184 str r1, [r2, #0xc] */
/* @0x1f8188 mov r0, #1 */
/* @0x1f818c ldr r4, [r3] */
/* @0x1f8190 vmov s15, r4 */
/* @0x1f8194 vcvt.f64.s32 d7, s15 */
/* @0x1f8198 vmov r4, r5, d7 */
/* @0x1f819c vmov r1, s14 */
/* @0x1f81a0 mov r3, r5 */
/* @0x1f81a4 pop {r4, r5} */
/* @0x1f81a8 stm r2, {r1, r3} */
/* @0x1f81ac bx lr */
/* @0x1f81b0 andseq r6, pc, r0, asr r4 */

/* ── FUNC 0x1f81b4 · GV_ViewVisible(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1f81b4 ldr r3, [pc, #0x48] */
/* @0x1f81b8 cmp r1, #7 */
/* @0x1f81bc push {r4, r5} */
/* @0x1f81c0 ldr r3, [pc, r3] */
/* @0x1f81c4 movhi r1, #0 */
/* @0x1f81c8 add r1, r1, #18 */
/* @0x1f81cc ldr r3, [r3] */
/* @0x1f81d0 mov r12, #0 */
/* @0x1f81d4 mov r0, #1 */
/* @0x1f81d8 str r12, [r2, #0xc] */
/* @0x1f81dc ldr r3, [r3, r1, lsl #2] */
/* @0x1f81e0 ldrb r4, [r3] */
/* @0x1f81e4 vmov s15, r4 */
/* @0x1f81e8 vcvt.f64.u32 d7, s15 */
/* @0x1f81ec vmov r4, r5, d7 */
/* @0x1f81f0 vmov r1, s14 */
/* @0x1f81f4 mov r3, r5 */
/* @0x1f81f8 pop {r4, r5} */
/* @0x1f81fc stm r2, {r1, r3} */
/* @0x1f8200 bx lr */
/* @0x1f8204 andseq r5, pc, r8, ror #14 */

/* ── FUNC 0x1f8208 · GV_ViewXview(CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1f8208 ldr r3, [pc, #0x44] */
/* @0x1f820c cmp r1, #7 */
/* @0x1f8210 push {r4, r5} */
/* @0x1f8214 ldr r3, [pc, r3] */
/* @0x1f8218 movhi r1, #0 */
/* @0x1f821c add r1, r1, #18 */
/* @0x1f8220 ldr r3, [r3] */
/* @0x1f8224 mov r12, #0 */
/* @0x1f8228 mov r0, #1 */
/* @0x1f822c str r12, [r2, #0xc] */
/* @0x1f8230 ldr r3, [r3, r1, lsl #2] */
/* @0x1f8234 vldr s15, [r3, #4] */
/* @0x1f8238 vcvt.f64.f32 d6, s15 */
/* @0x1f823c vmov r4, r5, d6 */
/* @0x1f8240 vmov r1, s12 */
/* @0x1f8244 mov r3, r5 */
/* @0x1f8248 pop {r4, r5} */
/* @0x1f824c stm r2, {r1, r3} */
/* @0x1f8250 bx lr */
/* @0x1f8254 andseq r5, pc, r4, lsl r7 */

/* ── FUNC 0x1f8258 · GV_ViewYview(CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1f8258 ldr r3, [pc, #0x44] */
/* @0x1f825c cmp r1, #7 */
/* @0x1f8260 push {r4, r5} */
/* @0x1f8264 ldr r3, [pc, r3] */
/* @0x1f8268 movhi r1, #0 */
/* @0x1f826c add r1, r1, #18 */
/* @0x1f8270 ldr r3, [r3] */
/* @0x1f8274 mov r12, #0 */
/* @0x1f8278 mov r0, #1 */
/* @0x1f827c str r12, [r2, #0xc] */
/* @0x1f8280 ldr r3, [r3, r1, lsl #2] */
/* @0x1f8284 vldr s15, [r3, #8] */
/* @0x1f8288 vcvt.f64.f32 d6, s15 */
/* @0x1f828c vmov r4, r5, d6 */
/* @0x1f8290 vmov r1, s12 */
/* @0x1f8294 mov r3, r5 */
/* @0x1f8298 pop {r4, r5} */
/* @0x1f829c stm r2, {r1, r3} */
/* @0x1f82a0 bx lr */
/* @0x1f82a4 andseq r5, pc, r4, asr #13 */

/* ── FUNC 0x1f82a8 · GV_ViewWview(CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1f82a8 ldr r3, [pc, #0x44] */
/* @0x1f82ac cmp r1, #7 */
/* @0x1f82b0 push {r4, r5} */
/* @0x1f82b4 ldr r3, [pc, r3] */
/* @0x1f82b8 movhi r1, #0 */
/* @0x1f82bc add r1, r1, #18 */
/* @0x1f82c0 ldr r3, [r3] */
/* @0x1f82c4 mov r12, #0 */
/* @0x1f82c8 mov r0, #1 */
/* @0x1f82cc str r12, [r2, #0xc] */
/* @0x1f82d0 ldr r3, [r3, r1, lsl #2] */
/* @0x1f82d4 vldr s15, [r3, #12] */
/* @0x1f82d8 vcvt.f64.f32 d6, s15 */
/* @0x1f82dc vmov r4, r5, d6 */
/* @0x1f82e0 vmov r1, s12 */
/* @0x1f82e4 mov r3, r5 */
/* @0x1f82e8 pop {r4, r5} */
/* @0x1f82ec stm r2, {r1, r3} */
/* @0x1f82f0 bx lr */
/* @0x1f82f4 andseq r5, pc, r4, ror r6 */

/* ── FUNC 0x1f82f8 · GV_ViewHview(CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1f82f8 ldr r3, [pc, #0x44] */
/* @0x1f82fc cmp r1, #7 */
/* @0x1f8300 push {r4, r5} */
/* @0x1f8304 ldr r3, [pc, r3] */
/* @0x1f8308 movhi r1, #0 */
/* @0x1f830c add r1, r1, #18 */
/* @0x1f8310 ldr r3, [r3] */
/* @0x1f8314 mov r12, #0 */
/* @0x1f8318 mov r0, #1 */
/* @0x1f831c str r12, [r2, #0xc] */
/* @0x1f8320 ldr r3, [r3, r1, lsl #2] */
/* @0x1f8324 vldr s15, [r3, #16] */
/* @0x1f8328 vcvt.f64.f32 d6, s15 */
/* @0x1f832c vmov r4, r5, d6 */
/* @0x1f8330 vmov r1, s12 */
/* @0x1f8334 mov r3, r5 */
/* @0x1f8338 pop {r4, r5} */
/* @0x1f833c stm r2, {r1, r3} */
/* @0x1f8340 bx lr */
/* @0x1f8344 andseq r5, pc, r4, lsr #12 */

/* ── FUNC 0x1f8348 · GV_ViewXport(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1f8348 ldr r3, [pc, #0x48] */
/* @0x1f834c cmp r1, #7 */
/* @0x1f8350 push {r4, r5} */
/* @0x1f8354 ldr r3, [pc, r3] */
/* @0x1f8358 movhi r1, #0 */
/* @0x1f835c add r1, r1, #18 */
/* @0x1f8360 ldr r3, [r3] */
/* @0x1f8364 mov r12, #0 */
/* @0x1f8368 mov r0, #1 */
/* @0x1f836c str r12, [r2, #0xc] */
/* @0x1f8370 ldr r3, [r3, r1, lsl #2] */
/* @0x1f8374 ldr r4, [r3, #0x14] */
/* @0x1f8378 vmov s15, r4 */
/* @0x1f837c vcvt.f64.s32 d7, s15 */
/* @0x1f8380 vmov r4, r5, d7 */
/* @0x1f8384 vmov r1, s14 */
/* @0x1f8388 mov r3, r5 */
/* @0x1f838c pop {r4, r5} */
/* @0x1f8390 stm r2, {r1, r3} */
/* @0x1f8394 bx lr */
/* @0x1f8398 ldrsbeq r5, [pc], -r4 */

/* ── FUNC 0x1f839c · GV_ViewYport(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1f839c ldr r3, [pc, #0x48] */
/* @0x1f83a0 cmp r1, #7 */
/* @0x1f83a4 push {r4, r5} */
/* @0x1f83a8 ldr r3, [pc, r3] */
/* @0x1f83ac movhi r1, #0 */
/* @0x1f83b0 add r1, r1, #18 */
/* @0x1f83b4 ldr r3, [r3] */
/* @0x1f83b8 mov r12, #0 */
/* @0x1f83bc mov r0, #1 */
/* @0x1f83c0 str r12, [r2, #0xc] */
/* @0x1f83c4 ldr r3, [r3, r1, lsl #2] */
/* @0x1f83c8 ldr r4, [r3, #0x18] */
/* @0x1f83cc vmov s15, r4 */
/* @0x1f83d0 vcvt.f64.s32 d7, s15 */
/* @0x1f83d4 vmov r4, r5, d7 */
/* @0x1f83d8 vmov r1, s14 */
/* @0x1f83dc mov r3, r5 */
/* @0x1f83e0 pop {r4, r5} */
/* @0x1f83e4 stm r2, {r1, r3} */
/* @0x1f83e8 bx lr */
/* @0x1f83ec andseq r5, pc, r0, lsl #11 */

/* ── FUNC 0x1f83f0 · GV_ViewWport(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1f83f0 ldr r3, [pc, #0x48] */
/* @0x1f83f4 cmp r1, #7 */
/* @0x1f83f8 push {r4, r5} */
/* @0x1f83fc ldr r3, [pc, r3] */
/* @0x1f8400 movhi r1, #0 */
/* @0x1f8404 add r1, r1, #18 */
/* @0x1f8408 ldr r3, [r3] */
/* @0x1f840c mov r12, #0 */
/* @0x1f8410 mov r0, #1 */
/* @0x1f8414 str r12, [r2, #0xc] */
/* @0x1f8418 ldr r3, [r3, r1, lsl #2] */
/* @0x1f841c ldr r4, [r3, #0x1c] */
/* @0x1f8420 vmov s15, r4 */
/* @0x1f8424 vcvt.f64.s32 d7, s15 */
/* @0x1f8428 vmov r4, r5, d7 */
/* @0x1f842c vmov r1, s14 */
/* @0x1f8430 mov r3, r5 */
/* @0x1f8434 pop {r4, r5} */
/* @0x1f8438 stm r2, {r1, r3} */
/* @0x1f843c bx lr */
/* @0x1f8440 andseq r5, pc, r12, lsr #10 */

/* ── FUNC 0x1f8444 · GV_ViewHport(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1f8444 ldr r3, [pc, #0x48] */
/* @0x1f8448 cmp r1, #7 */
/* @0x1f844c push {r4, r5} */
/* @0x1f8450 ldr r3, [pc, r3] */
/* @0x1f8454 movhi r1, #0 */
/* @0x1f8458 add r1, r1, #18 */
/* @0x1f845c ldr r3, [r3] */
/* @0x1f8460 mov r12, #0 */
/* @0x1f8464 mov r0, #1 */
/* @0x1f8468 str r12, [r2, #0xc] */
/* @0x1f846c ldr r3, [r3, r1, lsl #2] */
/* @0x1f8470 ldr r4, [r3, #0x20] */
/* @0x1f8474 vmov s15, r4 */
/* @0x1f8478 vcvt.f64.s32 d7, s15 */
/* @0x1f847c vmov r4, r5, d7 */
/* @0x1f8480 vmov r1, s14 */
/* @0x1f8484 mov r3, r5 */
/* @0x1f8488 pop {r4, r5} */
/* @0x1f848c stm r2, {r1, r3} */
/* @0x1f8490 bx lr */
/* @0x1f8494 ldrsbeq r5, [pc], -r8 */

/* ── FUNC 0x1f8498 · GV_ViewAngle(CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1f8498 ldr r3, [pc, #0x44] */
/* @0x1f849c cmp r1, #7 */
/* @0x1f84a0 push {r4, r5} */
/* @0x1f84a4 ldr r3, [pc, r3] */
/* @0x1f84a8 movhi r1, #0 */
/* @0x1f84ac add r1, r1, #18 */
/* @0x1f84b0 ldr r3, [r3] */
/* @0x1f84b4 mov r12, #0 */
/* @0x1f84b8 mov r0, #1 */
/* @0x1f84bc str r12, [r2, #0xc] */
/* @0x1f84c0 ldr r3, [r3, r1, lsl #2] */
/* @0x1f84c4 vldr s15, [r3, #36] */
/* @0x1f84c8 vcvt.f64.f32 d6, s15 */
/* @0x1f84cc vmov r4, r5, d6 */
/* @0x1f84d0 vmov r1, s12 */
/* @0x1f84d4 mov r3, r5 */
/* @0x1f84d8 pop {r4, r5} */
/* @0x1f84dc stm r2, {r1, r3} */
/* @0x1f84e0 bx lr */
/* @0x1f84e4 andseq r5, pc, r4, lsl #9 */

/* ── FUNC 0x1f84e8 · GV_ViewHBorder(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1f84e8 ldr r3, [pc, #0x48] */
/* @0x1f84ec cmp r1, #7 */
/* @0x1f84f0 push {r4, r5} */
/* @0x1f84f4 ldr r3, [pc, r3] */
/* @0x1f84f8 movhi r1, #0 */
/* @0x1f84fc add r1, r1, #18 */
/* @0x1f8500 ldr r3, [r3] */
/* @0x1f8504 mov r12, #0 */
/* @0x1f8508 mov r0, #1 */
/* @0x1f850c str r12, [r2, #0xc] */
/* @0x1f8510 ldr r3, [r3, r1, lsl #2] */
/* @0x1f8514 ldr r4, [r3, #0x28] */
/* @0x1f8518 vmov s15, r4 */
/* @0x1f851c vcvt.f64.s32 d7, s15 */
/* @0x1f8520 vmov r4, r5, d7 */
/* @0x1f8524 vmov r1, s14 */
/* @0x1f8528 mov r3, r5 */
/* @0x1f852c pop {r4, r5} */
/* @0x1f8530 stm r2, {r1, r3} */
/* @0x1f8534 bx lr */
/* @0x1f8538 andseq r5, pc, r4, lsr r4 */

/* ── FUNC 0x1f853c · GV_ViewVBorder(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1f853c ldr r3, [pc, #0x48] */
/* @0x1f8540 cmp r1, #7 */
/* @0x1f8544 push {r4, r5} */
/* @0x1f8548 ldr r3, [pc, r3] */
/* @0x1f854c movhi r1, #0 */
/* @0x1f8550 add r1, r1, #18 */
/* @0x1f8554 ldr r3, [r3] */
/* @0x1f8558 mov r12, #0 */
/* @0x1f855c mov r0, #1 */
/* @0x1f8560 str r12, [r2, #0xc] */
/* @0x1f8564 ldr r3, [r3, r1, lsl #2] */
/* @0x1f8568 ldr r4, [r3, #0x2c] */
/* @0x1f856c vmov s15, r4 */
/* @0x1f8570 vcvt.f64.s32 d7, s15 */
/* @0x1f8574 vmov r4, r5, d7 */
/* @0x1f8578 vmov r1, s14 */
/* @0x1f857c mov r3, r5 */
/* @0x1f8580 pop {r4, r5} */
/* @0x1f8584 stm r2, {r1, r3} */
/* @0x1f8588 bx lr */
/* @0x1f858c andseq r5, pc, r0, ror #7 */

/* ── FUNC 0x1f8590 · GV_ViewHSpeed(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1f8590 ldr r3, [pc, #0x48] */
/* @0x1f8594 cmp r1, #7 */
/* @0x1f8598 push {r4, r5} */
/* @0x1f859c ldr r3, [pc, r3] */
/* @0x1f85a0 movhi r1, #0 */
/* @0x1f85a4 add r1, r1, #18 */
/* @0x1f85a8 ldr r3, [r3] */
/* @0x1f85ac mov r12, #0 */
/* @0x1f85b0 mov r0, #1 */
/* @0x1f85b4 str r12, [r2, #0xc] */
/* @0x1f85b8 ldr r3, [r3, r1, lsl #2] */
/* @0x1f85bc ldr r4, [r3, #0x30] */
/* @0x1f85c0 vmov s15, r4 */
/* @0x1f85c4 vcvt.f64.s32 d7, s15 */
/* @0x1f85c8 vmov r4, r5, d7 */
/* @0x1f85cc vmov r1, s14 */
/* @0x1f85d0 mov r3, r5 */
/* @0x1f85d4 pop {r4, r5} */
/* @0x1f85d8 stm r2, {r1, r3} */
/* @0x1f85dc bx lr */
/* @0x1f85e0 andseq r5, pc, r12, lsl #7 */

/* ── FUNC 0x1f85e4 · GV_ViewVspeed(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1f85e4 ldr r3, [pc, #0x48] */
/* @0x1f85e8 cmp r1, #7 */
/* @0x1f85ec push {r4, r5} */
/* @0x1f85f0 ldr r3, [pc, r3] */
/* @0x1f85f4 movhi r1, #0 */
/* @0x1f85f8 add r1, r1, #18 */
/* @0x1f85fc ldr r3, [r3] */
/* @0x1f8600 mov r12, #0 */
/* @0x1f8604 mov r0, #1 */
/* @0x1f8608 str r12, [r2, #0xc] */
/* @0x1f860c ldr r3, [r3, r1, lsl #2] */
/* @0x1f8610 ldr r4, [r3, #0x34] */
/* @0x1f8614 vmov s15, r4 */
/* @0x1f8618 vcvt.f64.s32 d7, s15 */
/* @0x1f861c vmov r4, r5, d7 */
/* @0x1f8620 vmov r1, s14 */
/* @0x1f8624 mov r3, r5 */
/* @0x1f8628 pop {r4, r5} */
/* @0x1f862c stm r2, {r1, r3} */
/* @0x1f8630 bx lr */
/* @0x1f8634 andseq r5, pc, r8, lsr r3 */

/* ── FUNC 0x1f8638 · GV_ViewObject(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1f8638 ldr r3, [pc, #0x48] */
/* @0x1f863c cmp r1, #7 */
/* @0x1f8640 push {r4, r5} */
/* @0x1f8644 ldr r3, [pc, r3] */
/* @0x1f8648 movhi r1, #0 */
/* @0x1f864c add r1, r1, #18 */
/* @0x1f8650 ldr r3, [r3] */
/* @0x1f8654 mov r12, #0 */
/* @0x1f8658 mov r0, #1 */
/* @0x1f865c str r12, [r2, #0xc] */
/* @0x1f8660 ldr r3, [r3, r1, lsl #2] */
/* @0x1f8664 ldr r4, [r3, #0x38] */
/* @0x1f8668 vmov s15, r4 */
/* @0x1f866c vcvt.f64.s32 d7, s15 */
/* @0x1f8670 vmov r4, r5, d7 */
/* @0x1f8674 vmov r1, s14 */
/* @0x1f8678 mov r3, r5 */
/* @0x1f867c pop {r4, r5} */
/* @0x1f8680 stm r2, {r1, r3} */
/* @0x1f8684 bx lr */
/* @0x1f8688 andseq r5, pc, r4, ror #5 */

/* ── FUNC 0x1f868c · GV_ShowScore(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f868c ldr r3, [pc, #0x34] */
/* @0x1f8690 mov r1, #0 */
/* @0x1f8694 push {r4, r5} */
/* @0x1f8698 ldr r3, [pc, r3] */
/* @0x1f869c str r1, [r2, #0xc] */
/* @0x1f86a0 mov r0, #1 */
/* @0x1f86a4 ldrb r4, [r3] */
/* @0x1f86a8 vmov s15, r4 */
/* @0x1f86ac vcvt.f64.u32 d7, s15 */
/* @0x1f86b0 vmov r4, r5, d7 */
/* @0x1f86b4 vmov r1, s14 */
/* @0x1f86b8 mov r3, r5 */
/* @0x1f86bc pop {r4, r5} */
/* @0x1f86c0 stm r2, {r1, r3} */
/* @0x1f86c4 bx lr */
/* @0x1f86c8 andseq r6, pc, r4, asr pc */

/* ── FUNC 0x1f86cc · GV_ShowLives(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f86cc ldr r3, [pc, #0x34] */
/* @0x1f86d0 mov r1, #0 */
/* @0x1f86d4 push {r4, r5} */
/* @0x1f86d8 ldr r3, [pc, r3] */
/* @0x1f86dc str r1, [r2, #0xc] */
/* @0x1f86e0 mov r0, #1 */
/* @0x1f86e4 ldrb r4, [r3] */
/* @0x1f86e8 vmov s15, r4 */
/* @0x1f86ec vcvt.f64.u32 d7, s15 */
/* @0x1f86f0 vmov r4, r5, d7 */
/* @0x1f86f4 vmov r1, s14 */
/* @0x1f86f8 mov r3, r5 */
/* @0x1f86fc pop {r4, r5} */
/* @0x1f8700 stm r2, {r1, r3} */
/* @0x1f8704 bx lr */
/* @0x1f8708 andseq r6, pc, r12, lsl pc */

/* ── FUNC 0x1f870c · GV_ShowHealth(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f870c ldr r3, [pc, #0x34] */
/* @0x1f8710 mov r1, #0 */
/* @0x1f8714 push {r4, r5} */
/* @0x1f8718 ldr r3, [pc, r3] */
/* @0x1f871c str r1, [r2, #0xc] */
/* @0x1f8720 mov r0, #1 */
/* @0x1f8724 ldrb r4, [r3] */
/* @0x1f8728 vmov s15, r4 */
/* @0x1f872c vcvt.f64.u32 d7, s15 */
/* @0x1f8730 vmov r4, r5, d7 */
/* @0x1f8734 vmov r1, s14 */
/* @0x1f8738 mov r3, r5 */
/* @0x1f873c pop {r4, r5} */
/* @0x1f8740 stm r2, {r1, r3} */
/* @0x1f8744 bx lr */
/* @0x1f8748 andseq r6, pc, r4, ror #29 */

/* ── FUNC 0x1f874c · GV_CursorSprite(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f874c ldr r3, [pc, #0x34] */
/* @0x1f8750 mov r1, #0 */
/* @0x1f8754 push {r4, r5} */
/* @0x1f8758 ldr r3, [pc, r3] */
/* @0x1f875c str r1, [r2, #0xc] */
/* @0x1f8760 mov r0, #1 */
/* @0x1f8764 ldr r4, [r3] */
/* @0x1f8768 vmov s15, r4 */
/* @0x1f876c vcvt.f64.s32 d7, s15 */
/* @0x1f8770 vmov r4, r5, d7 */
/* @0x1f8774 vmov r1, s14 */
/* @0x1f8778 mov r3, r5 */
/* @0x1f877c pop {r4, r5} */
/* @0x1f8780 stm r2, {r1, r3} */
/* @0x1f8784 bx lr */
/* @0x1f8788 mulseq pc, r0, r12 */

/* ── FUNC 0x1f878c · GV_FontTexturePageSize(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f878c ldr r3, [pc, #0x34] */
/* @0x1f8790 mov r1, #10 */
/* @0x1f8794 push {r4, r5} */
/* @0x1f8798 ldr r3, [pc, r3] */
/* @0x1f879c str r1, [r2, #0xc] */
/* @0x1f87a0 mov r0, #1 */
/* @0x1f87a4 ldr r4, [r3] */
/* @0x1f87a8 vmov s15, r4 */
/* @0x1f87ac vcvt.f64.s32 d7, s15 */
/* @0x1f87b0 vmov r4, r5, d7 */
/* @0x1f87b4 vmov r1, s14 */
/* @0x1f87b8 mov r3, r5 */
/* @0x1f87bc pop {r4, r5} */
/* @0x1f87c0 stm r2, {r1, r3} */
/* @0x1f87c4 bx lr */
/* @0x1f87c8 ldrheq r5, [pc], -r12 */

/* ── FUNC 0x1f87cc · GV_Fps(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f87cc ldr r3, [pc, #0x34] */
/* @0x1f87d0 mov r1, #0 */
/* @0x1f87d4 push {r4, r5} */
/* @0x1f87d8 ldr r3, [pc, r3] */
/* @0x1f87dc str r1, [r2, #0xc] */
/* @0x1f87e0 mov r0, #1 */
/* @0x1f87e4 ldr r4, [r3] */
/* @0x1f87e8 vmov s15, r4 */
/* @0x1f87ec vcvt.f64.s32 d7, s15 */
/* @0x1f87f0 vmov r4, r5, d7 */
/* @0x1f87f4 vmov r1, s14 */
/* @0x1f87f8 mov r3, r5 */
/* @0x1f87fc pop {r4, r5} */
/* @0x1f8800 stm r2, {r1, r3} */
/* @0x1f8804 bx lr */
/* @0x1f8808 mulseq pc, r4, pc */

/* ── FUNC 0x1f880c · GV_FpsReal(CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1f880c ldr r3, [pc, #0x30] */
/* @0x1f8810 mov r1, #0 */
/* @0x1f8814 push {r4, r5} */
/* @0x1f8818 ldr r3, [pc, r3] */
/* @0x1f881c vldr s15, [r3] */
/* @0x1f8820 vcvt.f64.f32 d6, s15 */
/* @0x1f8824 str r1, [r2, #0xc] */
/* @0x1f8828 mov r0, #1 */
/* @0x1f882c vmov r4, r5, d6 */
/* @0x1f8830 vmov r1, s12 */
/* @0x1f8834 mov r3, r5 */
/* @0x1f8838 pop {r4, r5} */
/* @0x1f883c stm r2, {r1, r3} */
/* @0x1f8840 bx lr */
/* @0x1f8844 andseq r7, pc, r0, ror #23 */

/* ── FUNC 0x1f8848 · SV_TransitionSteps(CInstance*, int, RValue*) · size=8 · insn=2 */
/* @0x1f8848 mov r0, #1 */
/* @0x1f884c bx lr */

/* ── FUNC 0x1f8850 · SV_CaptionScore(CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x1f8850 ldr r3, [r2] */
/* @0x1f8854 mov r0, #1 */
/* @0x1f8858 cmp r3, #0 */
/* @0x1f885c ldrne r2, [r3, #0x4] */
/* @0x1f8860 addne r2, r2, #1 */
/* @0x1f8864 strne r2, [r3, #0x4] */
/* @0x1f8868 ldr r2, [pc, #0x8] */
/* @0x1f886c ldr r2, [pc, r2] */
/* @0x1f8870 str r3, [r2] */
/* @0x1f8874 bx lr */
/* @0x1f8878 andseq r6, pc, r4, lsl #27 */
