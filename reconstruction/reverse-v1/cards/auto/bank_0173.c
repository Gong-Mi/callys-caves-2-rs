/* libyoyo.so 覆盖卡组 0173
 * 函数 0x1f8f34..0x1f9620，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1f8f34 · GV_Depth(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f8f34 vldr s15, [r0, #384] */
/* @0x1f8f38 vcvt.f64.f32 d6, s15 */
/* @0x1f8f3c push {r4, r5} */
/* @0x1f8f40 mov r3, #0 */
/* @0x1f8f44 mov r0, #1 */
/* @0x1f8f48 str r3, [r2, #0xc] */
/* @0x1f8f4c vmov r4, r5, d6 */
/* @0x1f8f50 vmov r1, s12 */
/* @0x1f8f54 mov r3, r5 */
/* @0x1f8f58 pop {r4, r5} */
/* @0x1f8f5c stm r2, {r1, r3} */
/* @0x1f8f60 bx lr */

/* ── FUNC 0x1f8f64 · GV_SpriteIndex(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1f8f64 push {r4, r5} */
/* @0x1f8f68 mov r3, #0 */
/* @0x1f8f6c ldr r4, [r0, #0x8c] */
/* @0x1f8f70 mov r0, #1 */
/* @0x1f8f74 str r3, [r2, #0xc] */
/* @0x1f8f78 vmov s15, r4 */
/* @0x1f8f7c vcvt.f64.s32 d7, s15 */
/* @0x1f8f80 vmov r4, r5, d7 */
/* @0x1f8f84 vmov r1, s14 */
/* @0x1f8f88 mov r3, r5 */
/* @0x1f8f8c pop {r4, r5} */
/* @0x1f8f90 stm r2, {r1, r3} */
/* @0x1f8f94 bx lr */

/* ── FUNC 0x1f8f98 · GV_ImageIndex(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f8f98 vldr s15, [r0, #144] */
/* @0x1f8f9c vcvt.f64.f32 d6, s15 */
/* @0x1f8fa0 push {r4, r5} */
/* @0x1f8fa4 mov r3, #0 */
/* @0x1f8fa8 mov r0, #1 */
/* @0x1f8fac str r3, [r2, #0xc] */
/* @0x1f8fb0 vmov r4, r5, d6 */
/* @0x1f8fb4 vmov r1, s12 */
/* @0x1f8fb8 mov r3, r5 */
/* @0x1f8fbc pop {r4, r5} */
/* @0x1f8fc0 stm r2, {r1, r3} */
/* @0x1f8fc4 bx lr */

/* ── FUNC 0x1f8fc8 · GV_ImageSingle(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f8fc8 vldr s15, [r0, #148] */
/* @0x1f8fcc vcmp.f32 s15, #0 */
/* @0x1f8fd0 mov r3, #0 */
/* @0x1f8fd4 str r3, [r2, #0xc] */
/* @0x1f8fd8 vmrs APSR_nzcv, fpscr */
/* @0x1f8fdc vldreq s15, [r0, #144] */
/* @0x1f8fe0 vcvteq.f64.f32 d6, s15 */
/* @0x1f8fe4 strne r3, [r2] */
/* @0x1f8fe8 movne r3, #0 */
/* @0x1f8fec movtne r3, #0xbff0 */
/* @0x1f8ff0 strne r3, [r2, #0x4] */
/* @0x1f8ff4 vmoveq r0, r1, d6 */
/* @0x1f8ff8 moveq r3, r1 */
/* @0x1f8ffc stmeq r2, {r0, r3} */
/* @0x1f9000 mov r0, #1 */
/* @0x1f9004 bx lr */

/* ── FUNC 0x1f9008 · GV_ImageXScale(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f9008 vldr s15, [r0, #152] */
/* @0x1f900c vcvt.f64.f32 d6, s15 */
/* @0x1f9010 push {r4, r5} */
/* @0x1f9014 mov r3, #0 */
/* @0x1f9018 mov r0, #1 */
/* @0x1f901c str r3, [r2, #0xc] */
/* @0x1f9020 vmov r4, r5, d6 */
/* @0x1f9024 vmov r1, s12 */
/* @0x1f9028 mov r3, r5 */
/* @0x1f902c pop {r4, r5} */
/* @0x1f9030 stm r2, {r1, r3} */
/* @0x1f9034 bx lr */

/* ── FUNC 0x1f9038 · GV_ImageYScale(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f9038 vldr s15, [r0, #156] */
/* @0x1f903c vcvt.f64.f32 d6, s15 */
/* @0x1f9040 push {r4, r5} */
/* @0x1f9044 mov r3, #0 */
/* @0x1f9048 mov r0, #1 */
/* @0x1f904c str r3, [r2, #0xc] */
/* @0x1f9050 vmov r4, r5, d6 */
/* @0x1f9054 vmov r1, s12 */
/* @0x1f9058 mov r3, r5 */
/* @0x1f905c pop {r4, r5} */
/* @0x1f9060 stm r2, {r1, r3} */
/* @0x1f9064 bx lr */

/* ── FUNC 0x1f9068 · GV_ImageAngle(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f9068 vldr s15, [r0, #160] */
/* @0x1f906c vcvt.f64.f32 d6, s15 */
/* @0x1f9070 push {r4, r5} */
/* @0x1f9074 mov r3, #0 */
/* @0x1f9078 mov r0, #1 */
/* @0x1f907c str r3, [r2, #0xc] */
/* @0x1f9080 vmov r4, r5, d6 */
/* @0x1f9084 vmov r1, s12 */
/* @0x1f9088 mov r3, r5 */
/* @0x1f908c pop {r4, r5} */
/* @0x1f9090 stm r2, {r1, r3} */
/* @0x1f9094 bx lr */

/* ── FUNC 0x1f9098 · GV_ImageAlpha(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f9098 vldr s15, [r0, #164] */
/* @0x1f909c vcvt.f64.f32 d6, s15 */
/* @0x1f90a0 push {r4, r5} */
/* @0x1f90a4 mov r3, #0 */
/* @0x1f90a8 mov r0, #1 */
/* @0x1f90ac str r3, [r2, #0xc] */
/* @0x1f90b0 vmov r4, r5, d6 */
/* @0x1f90b4 vmov r1, s12 */
/* @0x1f90b8 mov r3, r5 */
/* @0x1f90bc pop {r4, r5} */
/* @0x1f90c0 stm r2, {r1, r3} */
/* @0x1f90c4 bx lr */

/* ── FUNC 0x1f90c8 · GV_ImageBlend(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1f90c8 push {r4, r5} */
/* @0x1f90cc mov r3, #0 */
/* @0x1f90d0 ldr r4, [r0, #0xa8] */
/* @0x1f90d4 mov r0, #1 */
/* @0x1f90d8 str r3, [r2, #0xc] */
/* @0x1f90dc vmov s15, r4 */
/* @0x1f90e0 vcvt.f64.u32 d7, s15 */
/* @0x1f90e4 vmov r4, r5, d7 */
/* @0x1f90e8 vmov r1, s14 */
/* @0x1f90ec mov r3, r5 */
/* @0x1f90f0 pop {r4, r5} */
/* @0x1f90f4 stm r2, {r1, r3} */
/* @0x1f90f8 bx lr */

/* ── FUNC 0x1f90fc · GV_ImageSpeed(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f90fc vldr s15, [r0, #148] */
/* @0x1f9100 vcvt.f64.f32 d6, s15 */
/* @0x1f9104 push {r4, r5} */
/* @0x1f9108 mov r3, #0 */
/* @0x1f910c mov r0, #1 */
/* @0x1f9110 str r3, [r2, #0xc] */
/* @0x1f9114 vmov r4, r5, d6 */
/* @0x1f9118 vmov r1, s12 */
/* @0x1f911c mov r3, r5 */
/* @0x1f9120 pop {r4, r5} */
/* @0x1f9124 stm r2, {r1, r3} */
/* @0x1f9128 bx lr */

/* ── FUNC 0x1f912c · GV_MaskIndex(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1f912c push {r4, r5} */
/* @0x1f9130 mov r3, #0 */
/* @0x1f9134 ldr r4, [r0, #0xac] */
/* @0x1f9138 mov r0, #1 */
/* @0x1f913c str r3, [r2, #0xc] */
/* @0x1f9140 vmov s15, r4 */
/* @0x1f9144 vcvt.f64.s32 d7, s15 */
/* @0x1f9148 vmov r4, r5, d7 */
/* @0x1f914c vmov r1, s14 */
/* @0x1f9150 mov r3, r5 */
/* @0x1f9154 pop {r4, r5} */
/* @0x1f9158 stm r2, {r1, r3} */
/* @0x1f915c bx lr */

/* ── FUNC 0x1f9160 · GV_PathIndex(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1f9160 push {r4, r5} */
/* @0x1f9164 mov r3, #0 */
/* @0x1f9168 ldr r4, [r0, #0x128] */
/* @0x1f916c mov r0, #1 */
/* @0x1f9170 str r3, [r2, #0xc] */
/* @0x1f9174 vmov s15, r4 */
/* @0x1f9178 vcvt.f64.s32 d7, s15 */
/* @0x1f917c vmov r4, r5, d7 */
/* @0x1f9180 vmov r1, s14 */
/* @0x1f9184 mov r3, r5 */
/* @0x1f9188 pop {r4, r5} */
/* @0x1f918c stm r2, {r1, r3} */
/* @0x1f9190 bx lr */

/* ── FUNC 0x1f9194 · GV_PathPosition(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f9194 vldr s15, [r0, #300] */
/* @0x1f9198 vcvt.f64.f32 d6, s15 */
/* @0x1f919c push {r4, r5} */
/* @0x1f91a0 mov r3, #0 */
/* @0x1f91a4 mov r0, #1 */
/* @0x1f91a8 str r3, [r2, #0xc] */
/* @0x1f91ac vmov r4, r5, d6 */
/* @0x1f91b0 vmov r1, s12 */
/* @0x1f91b4 mov r3, r5 */
/* @0x1f91b8 pop {r4, r5} */
/* @0x1f91bc stm r2, {r1, r3} */
/* @0x1f91c0 bx lr */

/* ── FUNC 0x1f91c4 · GV_PathPositionPrevious(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f91c4 vldr s15, [r0, #304] */
/* @0x1f91c8 vcvt.f64.f32 d6, s15 */
/* @0x1f91cc push {r4, r5} */
/* @0x1f91d0 mov r3, #0 */
/* @0x1f91d4 mov r0, #1 */
/* @0x1f91d8 str r3, [r2, #0xc] */
/* @0x1f91dc vmov r4, r5, d6 */
/* @0x1f91e0 vmov r1, s12 */
/* @0x1f91e4 mov r3, r5 */
/* @0x1f91e8 pop {r4, r5} */
/* @0x1f91ec stm r2, {r1, r3} */
/* @0x1f91f0 bx lr */

/* ── FUNC 0x1f91f4 · GV_PathSpeed(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f91f4 vldr s15, [r0, #308] */
/* @0x1f91f8 vcvt.f64.f32 d6, s15 */
/* @0x1f91fc push {r4, r5} */
/* @0x1f9200 mov r3, #0 */
/* @0x1f9204 mov r0, #1 */
/* @0x1f9208 str r3, [r2, #0xc] */
/* @0x1f920c vmov r4, r5, d6 */
/* @0x1f9210 vmov r1, s12 */
/* @0x1f9214 mov r3, r5 */
/* @0x1f9218 pop {r4, r5} */
/* @0x1f921c stm r2, {r1, r3} */
/* @0x1f9220 bx lr */

/* ── FUNC 0x1f9224 · GV_PathScale(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f9224 vldr s15, [r0, #312] */
/* @0x1f9228 vcvt.f64.f32 d6, s15 */
/* @0x1f922c push {r4, r5} */
/* @0x1f9230 mov r3, #0 */
/* @0x1f9234 mov r0, #1 */
/* @0x1f9238 str r3, [r2, #0xc] */
/* @0x1f923c vmov r4, r5, d6 */
/* @0x1f9240 vmov r1, s12 */
/* @0x1f9244 mov r3, r5 */
/* @0x1f9248 pop {r4, r5} */
/* @0x1f924c stm r2, {r1, r3} */
/* @0x1f9250 bx lr */

/* ── FUNC 0x1f9254 · GV_PathOrientation(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f9254 vldr s15, [r0, #316] */
/* @0x1f9258 vcvt.f64.f32 d6, s15 */
/* @0x1f925c push {r4, r5} */
/* @0x1f9260 mov r3, #0 */
/* @0x1f9264 mov r0, #1 */
/* @0x1f9268 str r3, [r2, #0xc] */
/* @0x1f926c vmov r4, r5, d6 */
/* @0x1f9270 vmov r1, s12 */
/* @0x1f9274 mov r3, r5 */
/* @0x1f9278 pop {r4, r5} */
/* @0x1f927c stm r2, {r1, r3} */
/* @0x1f9280 bx lr */

/* ── FUNC 0x1f9284 · GV_PathEndAction(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1f9284 push {r4, r5} */
/* @0x1f9288 mov r3, #0 */
/* @0x1f928c ldr r4, [r0, #0x140] */
/* @0x1f9290 mov r0, #1 */
/* @0x1f9294 str r3, [r2, #0xc] */
/* @0x1f9298 vmov s15, r4 */
/* @0x1f929c vcvt.f64.s32 d7, s15 */
/* @0x1f92a0 vmov r4, r5, d7 */
/* @0x1f92a4 vmov r1, s14 */
/* @0x1f92a8 mov r3, r5 */
/* @0x1f92ac pop {r4, r5} */
/* @0x1f92b0 stm r2, {r1, r3} */
/* @0x1f92b4 bx lr */

/* ── FUNC 0x1f92b8 · GV_TimelineIndex(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1f92b8 push {r4, r5} */
/* @0x1f92bc mov r3, #0 */
/* @0x1f92c0 ldr r4, [r0, #0x14c] */
/* @0x1f92c4 mov r0, #1 */
/* @0x1f92c8 str r3, [r2, #0xc] */
/* @0x1f92cc vmov s15, r4 */
/* @0x1f92d0 vcvt.f64.s32 d7, s15 */
/* @0x1f92d4 vmov r4, r5, d7 */
/* @0x1f92d8 vmov r1, s14 */
/* @0x1f92dc mov r3, r5 */
/* @0x1f92e0 pop {r4, r5} */
/* @0x1f92e4 stm r2, {r1, r3} */
/* @0x1f92e8 bx lr */

/* ── FUNC 0x1f92ec · GV_TimelinePosition(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f92ec vldr s15, [r0, #340] */
/* @0x1f92f0 vcvt.f64.f32 d6, s15 */
/* @0x1f92f4 push {r4, r5} */
/* @0x1f92f8 mov r3, #0 */
/* @0x1f92fc mov r0, #1 */
/* @0x1f9300 str r3, [r2, #0xc] */
/* @0x1f9304 vmov r4, r5, d6 */
/* @0x1f9308 vmov r1, s12 */
/* @0x1f930c mov r3, r5 */
/* @0x1f9310 pop {r4, r5} */
/* @0x1f9314 stm r2, {r1, r3} */
/* @0x1f9318 bx lr */

/* ── FUNC 0x1f931c · GV_TimelineSpeed(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f931c vldr s15, [r0, #344] */
/* @0x1f9320 vcvt.f64.f32 d6, s15 */
/* @0x1f9324 push {r4, r5} */
/* @0x1f9328 mov r3, #0 */
/* @0x1f932c mov r0, #1 */
/* @0x1f9330 str r3, [r2, #0xc] */
/* @0x1f9334 vmov r4, r5, d6 */
/* @0x1f9338 vmov r1, s12 */
/* @0x1f933c mov r3, r5 */
/* @0x1f9340 pop {r4, r5} */
/* @0x1f9344 stm r2, {r1, r3} */
/* @0x1f9348 bx lr */

/* ── FUNC 0x1f934c · GV_TimelineRunning(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1f934c push {r4, r5} */
/* @0x1f9350 mov r3, #0 */
/* @0x1f9354 ldrb r4, [r0, #0x15c] */
/* @0x1f9358 mov r0, #1 */
/* @0x1f935c str r3, [r2, #0xc] */
/* @0x1f9360 vmov s15, r4 */
/* @0x1f9364 vcvt.f64.u32 d7, s15 */
/* @0x1f9368 vmov r4, r5, d7 */
/* @0x1f936c vmov r1, s14 */
/* @0x1f9370 mov r3, r5 */
/* @0x1f9374 pop {r4, r5} */
/* @0x1f9378 stm r2, {r1, r3} */
/* @0x1f937c bx lr */

/* ── FUNC 0x1f9380 · GV_TimelineLoop(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1f9380 push {r4, r5} */
/* @0x1f9384 mov r3, #0 */
/* @0x1f9388 ldrb r4, [r0, #0x15d] */
/* @0x1f938c mov r0, #1 */
/* @0x1f9390 str r3, [r2, #0xc] */
/* @0x1f9394 vmov s15, r4 */
/* @0x1f9398 vcvt.f64.u32 d7, s15 */
/* @0x1f939c vmov r4, r5, d7 */
/* @0x1f93a0 vmov r1, s14 */
/* @0x1f93a4 mov r3, r5 */
/* @0x1f93a8 pop {r4, r5} */
/* @0x1f93ac stm r2, {r1, r3} */
/* @0x1f93b0 bx lr */

/* ── FUNC 0x1f93b4 · GV_AsyncLoad(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f93b4 ldr r3, [pc, #0x34] */
/* @0x1f93b8 mov r1, #0 */
/* @0x1f93bc push {r4, r5} */
/* @0x1f93c0 ldr r3, [pc, r3] */
/* @0x1f93c4 str r1, [r2, #0xc] */
/* @0x1f93c8 mov r0, #1 */
/* @0x1f93cc ldr r4, [r3] */
/* @0x1f93d0 vmov s15, r4 */
/* @0x1f93d4 vcvt.f64.s32 d7, s15 */
/* @0x1f93d8 vmov r4, r5, d7 */
/* @0x1f93dc vmov r1, s14 */
/* @0x1f93e0 mov r3, r5 */
/* @0x1f93e4 pop {r4, r5} */
/* @0x1f93e8 stm r2, {r1, r3} */
/* @0x1f93ec bx lr */
/* @0x1f93f0 andseq r6, pc, r8, asr r7 */

/* ── FUNC 0x1f93f4 · GV_EventData(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f93f4 ldr r3, [pc, #0x34] */
/* @0x1f93f8 mov r1, #0 */
/* @0x1f93fc push {r4, r5} */
/* @0x1f9400 ldr r3, [pc, r3] */
/* @0x1f9404 str r1, [r2, #0xc] */
/* @0x1f9408 mov r0, #1 */
/* @0x1f940c ldr r4, [r3] */
/* @0x1f9410 vmov s15, r4 */
/* @0x1f9414 vcvt.f64.s32 d7, s15 */
/* @0x1f9418 vmov r4, r5, d7 */
/* @0x1f941c vmov r1, s14 */
/* @0x1f9420 mov r3, r5 */
/* @0x1f9424 pop {r4, r5} */
/* @0x1f9428 stm r2, {r1, r3} */
/* @0x1f942c bx lr */
/* @0x1f9430 andseq r4, pc, r8, lsr r5 */

/* ── FUNC 0x1f9434 · GV_IAPEventData(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f9434 ldr r3, [pc, #0x34] */
/* @0x1f9438 mov r1, #0 */
/* @0x1f943c push {r4, r5} */
/* @0x1f9440 ldr r3, [pc, r3] */
/* @0x1f9444 str r1, [r2, #0xc] */
/* @0x1f9448 mov r0, #1 */
/* @0x1f944c ldr r4, [r3] */
/* @0x1f9450 vmov s15, r4 */
/* @0x1f9454 vcvt.f64.s32 d7, s15 */
/* @0x1f9458 vmov r4, r5, d7 */
/* @0x1f945c vmov r1, s14 */
/* @0x1f9460 mov r3, r5 */
/* @0x1f9464 pop {r4, r5} */
/* @0x1f9468 stm r2, {r1, r3} */
/* @0x1f946c bx lr */
/* @0x1f9470 andseq r6, pc, r0, asr #13 */

/* ── FUNC 0x1f9474 · GV_PhysicsMass(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f9474 ldr r0, [r0, #0x84] */
/* @0x1f9478 push {r4, r5} */
/* @0x1f947c cmp r0, #0 */
/* @0x1f9480 beq 0x1f94ac <_Z14GV_PhysicsMassP9CInstanceiP6RValue+0x38> */
/* @0x1f9484 ldr r3, [r0] */
/* @0x1f9488 vldr s15, [r3, #132] */
/* @0x1f948c vcvt.f64.f32 d6, s15 */
/* @0x1f9490 mov r0, #1 */
/* @0x1f9494 mov r3, #0 */
/* @0x1f9498 str r3, [r2, #0xc] */
/* @0x1f949c vmov r4, r5, d6 */
/* @0x1f94a0 vmov r1, s12 */
/* @0x1f94a4 mov r3, r5 */
/* @0x1f94a8 stm r2, {r1, r3} */
/* @0x1f94ac pop {r4, r5} */
/* @0x1f94b0 bx lr */

/* ── FUNC 0x1f94b4 · GV_PhysicsInertia(CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1f94b4 ldr r0, [r0, #0x84] */
/* @0x1f94b8 push {r4, r5} */
/* @0x1f94bc cmp r0, #0 */
/* @0x1f94c0 beq 0x1f9504 <_Z17GV_PhysicsInertiaP9CInstanceiP6RValue+0x50> */
/* @0x1f94c4 ldr r3, [r0] */
/* @0x1f94c8 vldr s14, [r3, #48] */
/* @0x1f94cc vmul.f32 s14, s14, s14 */
/* @0x1f94d0 vldr s13, [r3, #44] */
/* @0x1f94d4 vldr s12, [r3, #132] */
/* @0x1f94d8 vldr s15, [r3, #140] */
/* @0x1f94dc mov r0, #1 */
/* @0x1f94e0 mov r3, #0 */
/* @0x1f94e4 str r3, [r2, #0xc] */
/* @0x1f94e8 vmla.f32 s14, s13, s13 */
/* @0x1f94ec vmla.f32 s15, s14, s12 */
/* @0x1f94f0 vcvt.f64.f32 d6, s15 */
/* @0x1f94f4 vmov r4, r5, d6 */
/* @0x1f94f8 vmov r1, s12 */
/* @0x1f94fc mov r3, r5 */
/* @0x1f9500 stm r2, {r1, r3} */
/* @0x1f9504 pop {r4, r5} */
/* @0x1f9508 bx lr */

/* ── FUNC 0x1f950c · GV_PhysicsAngularVelocity(CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1f950c ldr r0, [r0, #0x84] */
/* @0x1f9510 push {r4, r5} */
/* @0x1f9514 cmp r0, #0 */
/* @0x1f9518 beq 0x1f9554 <_Z25GV_PhysicsAngularVelocityP9CInstanceiP6RValue+0x48> */
/* @0x1f951c ldr r3, [r0] */
/* @0x1f9520 vldr s15, [pc, #52] */
/* @0x1f9524 vldr s14, [r3, #88] */
/* @0x1f9528 vmul.f32 s15, s14, s15 */
/* @0x1f952c vldr s14, [pc, #44] */
/* @0x1f9530 mov r0, #1 */
/* @0x1f9534 mov r3, #0 */
/* @0x1f9538 str r3, [r2, #0xc] */
/* @0x1f953c vdiv.f32 s15, s15, s14 */
/* @0x1f9540 vcvt.f64.f32 d6, s15 */
/* @0x1f9544 vmov r4, r5, d6 */
/* @0x1f9548 vmov r1, s12 */
/* @0x1f954c mov r3, r5 */
/* @0x1f9550 stm r2, {r1, r3} */
/* @0x1f9554 pop {r4, r5} */
/* @0x1f9558 bx lr */
/* @0x1f955c teqmi r4, #0 */
/* @0x1f9560 ldrdmi r0, r1, [r9], #-251 */

/* ── FUNC 0x1f9564 · GV_PhysicsAngle(CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1f9564 ldr r0, [r0, #0x84] */
/* @0x1f9568 push {r4, r5} */
/* @0x1f956c cmp r0, #0 */
/* @0x1f9570 beq 0x1f95ac <_Z15GV_PhysicsAngleP9CInstanceiP6RValue+0x48> */
/* @0x1f9574 ldr r3, [r0] */
/* @0x1f9578 vldr s15, [pc, #52] */
/* @0x1f957c vldr s14, [r3, #72] */
/* @0x1f9580 vmul.f32 s15, s14, s15 */
/* @0x1f9584 vldr s14, [pc, #44] */
/* @0x1f9588 mov r0, #1 */
/* @0x1f958c mov r3, #0 */
/* @0x1f9590 str r3, [r2, #0xc] */
/* @0x1f9594 vdiv.f32 s15, s15, s14 */
/* @0x1f9598 vcvt.f64.f32 d6, s15 */
/* @0x1f959c vmov r4, r5, d6 */
/* @0x1f95a0 vmov r1, s12 */
/* @0x1f95a4 mov r3, r5 */
/* @0x1f95a8 stm r2, {r1, r3} */
/* @0x1f95ac pop {r4, r5} */
/* @0x1f95b0 bx lr */
/* @0x1f95b4 teqmi r4, #0 */
/* @0x1f95b8 ldrdmi r0, r1, [r9], #-251 */

/* ── FUNC 0x1f95bc · GV_PhysicsPositionX(CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x1f95bc ldr r3, [pc, #0x58] */
/* @0x1f95c0 ldr r1, [r0, #0x84] */
/* @0x1f95c4 ldr r3, [pc, r3] */
/* @0x1f95c8 push {r4, r5} */
/* @0x1f95cc ldr r3, [r3] */
/* @0x1f95d0 ldr r3, [r3, #0xb4] */
/* @0x1f95d4 cmp r1, #0 */
/* @0x1f95d8 cmpne r3, #0 */
/* @0x1f95dc moveq r0, #0 */
/* @0x1f95e0 movne r0, #1 */
/* @0x1f95e4 beq 0x1f9614 <_Z19GV_PhysicsPositionXP9CInstanceiP6RValue+0x58> */
/* @0x1f95e8 ldr r12, [r1] */
/* @0x1f95ec mov r1, #0 */
/* @0x1f95f0 vldr s14, [r12, #12] */
/* @0x1f95f4 str r1, [r2, #0xc] */
/* @0x1f95f8 vldr s15, [r3, #96] */
/* @0x1f95fc vdiv.f32 s15, s14, s15 */
/* @0x1f9600 vcvt.f64.f32 d6, s15 */
/* @0x1f9604 vmov r4, r5, d6 */
/* @0x1f9608 vmov r1, s12 */
/* @0x1f960c mov r3, r5 */
/* @0x1f9610 stm r2, {r1, r3} */
/* @0x1f9614 pop {r4, r5} */
/* @0x1f9618 bx lr */
/* @0x1f961c andseq r4, pc, r4, ror #6 */

/* ── FUNC 0x1f9620 · GV_PhysicsPositionY(CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x1f9620 ldr r3, [pc, #0x58] */
/* @0x1f9624 ldr r1, [r0, #0x84] */
/* @0x1f9628 ldr r3, [pc, r3] */
/* @0x1f962c push {r4, r5} */
/* @0x1f9630 ldr r3, [r3] */
/* @0x1f9634 ldr r3, [r3, #0xb4] */
/* @0x1f9638 cmp r1, #0 */
/* @0x1f963c cmpne r3, #0 */
/* @0x1f9640 moveq r0, #0 */
/* @0x1f9644 movne r0, #1 */
/* @0x1f9648 beq 0x1f9678 <_Z19GV_PhysicsPositionYP9CInstanceiP6RValue+0x58> */
/* @0x1f964c ldr r12, [r1] */
/* @0x1f9650 mov r1, #0 */
/* @0x1f9654 vldr s14, [r12, #16] */
/* @0x1f9658 str r1, [r2, #0xc] */
/* @0x1f965c vldr s15, [r3, #96] */
/* @0x1f9660 vdiv.f32 s15, s14, s15 */
/* @0x1f9664 vcvt.f64.f32 d6, s15 */
/* @0x1f9668 vmov r4, r5, d6 */
/* @0x1f966c vmov r1, s12 */
/* @0x1f9670 mov r3, r5 */
/* @0x1f9674 stm r2, {r1, r3} */
/* @0x1f9678 pop {r4, r5} */
/* @0x1f967c bx lr */
/* @0x1f9680 andseq r4, pc, r0, lsl #6 */
