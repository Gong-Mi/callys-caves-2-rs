/* libyoyo.so 覆盖卡组 0088
 * 函数 0x156094..0x1565c0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x156094 · F_YoYoAdsEngagementActive(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x156094 mov r3, #0 */
/* @0x156098 str r3, [r0, #0xc] */
/* @0x15609c str r3, [r0] */
/* @0x1560a0 str r3, [r0, #0x4] */
/* @0x1560a4 bx lr */

/* ── FUNC 0x1560a8 · F_YoYoAdsEngagementLaunch(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x1560a8 bx lr */

/* ── FUNC 0x1560ac · F_YoYoAdsRewardCallback(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x1560ac bx lr */

/* ── FUNC 0x1560b0 · F_YoYo_Ads_Interstitial_Available(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x1560b0 mov r3, #0 */
/* @0x1560b4 str r3, [r0, #0xc] */
/* @0x1560b8 str r3, [r0] */
/* @0x1560bc str r3, [r0, #0x4] */
/* @0x1560c0 bx lr */

/* ── FUNC 0x1560c4 · F_YoYo_Ads_Interstitial_Display(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x1560c4 mov r3, #0 */
/* @0x1560c8 str r3, [r0, #0xc] */
/* @0x1560cc str r3, [r0] */
/* @0x1560d0 str r3, [r0, #0x4] */
/* @0x1560d4 bx lr */

/* ── FUNC 0x1560d8 · F_YoYo_GetTiltX(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x1560d8 ldr r3, [pc, #0x1c] */
/* @0x1560dc mov r2, #0 */
/* @0x1560e0 str r2, [r0, #0xc] */
/* @0x1560e4 ldr r3, [pc, r3] */
/* @0x1560e8 vldr s15, [r3] */
/* @0x1560ec vcvt.f64.f32 d6, s15 */
/* @0x1560f0 vmov r2, r3, d6 */
/* @0x1560f4 stm r0, {r2, r3} */
/* @0x1560f8 bx lr */
/* @0x1560fc eoreq r9, r9, r0, asr r10 */

/* ── FUNC 0x156100 · F_YoYo_GetTiltY(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x156100 ldr r3, [pc, #0x1c] */
/* @0x156104 mov r2, #0 */
/* @0x156108 str r2, [r0, #0xc] */
/* @0x15610c ldr r3, [pc, r3] */
/* @0x156110 vldr s15, [r3] */
/* @0x156114 vcvt.f64.f32 d6, s15 */
/* @0x156118 vmov r2, r3, d6 */
/* @0x15611c stm r0, {r2, r3} */
/* @0x156120 bx lr */
/* @0x156124 eoreq r9, r9, r12, lsr #20 */

/* ── FUNC 0x156128 · F_YoYo_GetTiltZ(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x156128 ldr r3, [pc, #0x1c] */
/* @0x15612c mov r2, #0 */
/* @0x156130 str r2, [r0, #0xc] */
/* @0x156134 ldr r3, [pc, r3] */
/* @0x156138 vldr s15, [r3] */
/* @0x15613c vcvt.f64.f32 d6, s15 */
/* @0x156140 vmov r2, r3, d6 */
/* @0x156144 stm r0, {r2, r3} */
/* @0x156148 bx lr */
/* @0x15614c eoreq r9, r9, r8, lsl #20 */

/* ── FUNC 0x156150 · F_YoYo_IsKeypadOpen(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x156150 ldr r3, [pc, #0x28] */
/* @0x156154 mov r2, #0 */
/* @0x156158 str r2, [r0, #0xc] */
/* @0x15615c ldr r3, [pc, r3] */
/* @0x156160 ldrb r3, [r3] */
/* @0x156164 cmp r3, r2 */
/* @0x156168 movne r3, r2 */
/* @0x15616c moveq r2, r3 */
/* @0x156170 movtne r2, #0x3ff0 */
/* @0x156174 str r3, [r0] */
/* @0x156178 str r2, [r0, #0x4] */
/* @0x15617c bx lr */
/* @0x156180 eoreq r9, r9, r4, ror #19 */

/* ── FUNC 0x156184 · F_YoYo_GetSessionKey(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x156184 mov r3, #0 */
/* @0x156188 str r3, [r0, #0xc] */
/* @0x15618c str r3, [r0] */
/* @0x156190 str r3, [r0, #0x4] */
/* @0x156194 bx lr */

/* ── FUNC 0x156198 · F_YoYo_CheckSecurity(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x156198 mov r3, #0 */
/* @0x15619c str r3, [r0, #0xc] */
/* @0x1561a0 str r3, [r0] */
/* @0x1561a4 str r3, [r0, #0x4] */
/* @0x1561a8 bx lr */

/* ── FUNC 0x1561ac · F_YoYo_FacebookNull(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x1561ac mov r3, #0 */
/* @0x1561b0 str r3, [r0, #0xc] */
/* @0x1561b4 str r3, [r0] */
/* @0x1561b8 str r3, [r0, #0x4] */
/* @0x1561bc bx lr */

/* ── FUNC 0x1561c0 · F_YoYo_OSPauseEvent(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1561c0 ldr r3, [pc, #0x28] */
/* @0x1561c4 mov r2, #0 */
/* @0x1561c8 str r2, [r0, #0xc] */
/* @0x1561cc ldr r3, [pc, r3] */
/* @0x1561d0 ldrb r3, [r3] */
/* @0x1561d4 cmp r3, r2 */
/* @0x1561d8 movne r3, r2 */
/* @0x1561dc moveq r2, r3 */
/* @0x1561e0 movtne r2, #0x3ff0 */
/* @0x1561e4 str r3, [r0] */
/* @0x1561e8 str r2, [r0, #0x4] */
/* @0x1561ec bx lr */
/* @0x1561f0 eoreq r9, r9, r8, ror r9 */

/* ── FUNC 0x1561f4 · F_YoYo_OSHasFocus(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x1561f4 mov r2, #0 */
/* @0x1561f8 mov r3, r2 */
/* @0x1561fc movt r2, #0x3ff0 */
/* @0x156200 str r3, [r0, #0xc] */
/* @0x156204 str r2, [r0, #0x4] */
/* @0x156208 str r3, [r0] */
/* @0x15620c bx lr */

/* ── FUNC 0x156210 · F_CodeIsCompiled(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x156210 mov r3, #0 */
/* @0x156214 str r3, [r0, #0xc] */
/* @0x156218 str r3, [r0] */
/* @0x15621c str r3, [r0, #0x4] */
/* @0x156220 bx lr */

/* ── FUNC 0x156224 · F_YoYo_WinPhone_License_Trial(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x156224 push {r3, lr} */
/* @0x156228 mov r2, #0 */
/* @0x15622c ldr r3, [pc, #0x28] */
/* @0x156230 str r2, [r0] */
/* @0x156234 ldr r3, [pc, r3] */
/* @0x156238 str r2, [r0, #0x4] */
/* @0x15623c str r2, [r0, #0xc] */
/* @0x156240 ldr r0, [r3] */
/* @0x156244 ldr r1, [pc, #0x14] */
/* @0x156248 ldr r3, [r0] */
/* @0x15624c add r1, pc, r1 */
/* @0x156250 ldr r3, [r3, #0xc] */
/* @0x156254 blx r3 */
/* @0x156258 pop {r3, pc} */
/* @0x15625c eoreq r7, r9, r0, ror #9 */
/* @0x156260 andseq r0, pc, r0, asr #5 */

/* ── FUNC 0x156264 · F_YoYo_WinPhone_SetTile_Common_Count(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x156264 push {r3, lr} */
/* @0x156268 ldr r3, [pc, #0x1c] */
/* @0x15626c ldr r1, [pc, #0x1c] */
/* @0x156270 ldr r3, [pc, r3] */
/* @0x156274 add r1, pc, r1 */
/* @0x156278 ldr r0, [r3] */
/* @0x15627c ldr r3, [r0] */
/* @0x156280 ldr r3, [r3, #0xc] */
/* @0x156284 blx r3 */
/* @0x156288 pop {r3, pc} */
/* @0x15628c eoreq r7, r9, r4, lsr #9 */
/* @0x156290 mulseq pc, r8, r2 */

/* ── FUNC 0x156294 · F_YoYo_WinPhone_SetTile_Iconic_BackgroundColour(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x156294 push {r3, lr} */
/* @0x156298 ldr r3, [pc, #0x1c] */
/* @0x15629c ldr r1, [pc, #0x1c] */
/* @0x1562a0 ldr r3, [pc, r3] */
/* @0x1562a4 add r1, pc, r1 */
/* @0x1562a8 ldr r0, [r3] */
/* @0x1562ac ldr r3, [r0] */
/* @0x1562b0 ldr r3, [r3, #0xc] */
/* @0x1562b4 blx r3 */
/* @0x1562b8 pop {r3, pc} */
/* @0x1562bc eoreq r7, r9, r4, ror r4 */
/* @0x1562c0 andseq r0, pc, r8, ror #4 */

/* ── FUNC 0x1562c4 · F_YoYo_WinPhone_SetTile_Iconic_WideContent(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1562c4 push {r3, lr} */
/* @0x1562c8 mov r2, #0 */
/* @0x1562cc ldr r3, [pc, #0x28] */
/* @0x1562d0 str r2, [r0] */
/* @0x1562d4 ldr r3, [pc, r3] */
/* @0x1562d8 str r2, [r0, #0x4] */
/* @0x1562dc str r2, [r0, #0xc] */
/* @0x1562e0 ldr r0, [r3] */
/* @0x1562e4 ldr r1, [pc, #0x14] */
/* @0x1562e8 ldr r3, [r0] */
/* @0x1562ec add r1, pc, r1 */
/* @0x1562f0 ldr r3, [r3, #0xc] */
/* @0x1562f4 blx r3 */
/* @0x1562f8 pop {r3, pc} */
/* @0x1562fc eoreq r7, r9, r0, asr #8 */
/* @0x156300 andseq r0, pc, r0, lsr #4 */

/* ── FUNC 0x156304 · F_AppSurfaceIsEnabled(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x156304 ldr r3, [pc, #0x28] */
/* @0x156308 mov r2, #0 */
/* @0x15630c str r2, [r0, #0xc] */
/* @0x156310 ldr r3, [pc, r3] */
/* @0x156314 ldrb r3, [r3] */
/* @0x156318 cmp r3, r2 */
/* @0x15631c movne r3, r2 */
/* @0x156320 moveq r2, r3 */
/* @0x156324 movtne r2, #0x3ff0 */
/* @0x156328 str r3, [r0] */
/* @0x15632c str r2, [r0, #0x4] */
/* @0x156330 bx lr */
/* @0x156334 eoreq r9, r9, r8, lsr r8 */

/* ── FUNC 0x156338 · F_PlayerRestarted(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x156338 ldr r3, [pc, #0x28] */
/* @0x15633c mov r1, #0 */
/* @0x156340 str r1, [r0, #0xc] */
/* @0x156344 ldr r3, [pc, r3] */
/* @0x156348 ldrb r2, [r3] */
/* @0x15634c cmp r2, r1 */
/* @0x156350 movne r2, r1 */
/* @0x156354 moveq r3, #0 */
/* @0x156358 movne r3, r2 */
/* @0x15635c movteq r3, #0x3ff0 */
/* @0x156360 stm r0, {r2, r3} */
/* @0x156364 bx lr */
/* @0x156368 eoreq r9, r9, r8, lsl #16 */

/* ── FUNC 0x15636c · F_ExtensionStubFuncReal(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x15636c mov r3, #0 */
/* @0x156370 str r3, [r0, #0xc] */
/* @0x156374 str r3, [r0] */
/* @0x156378 str r3, [r0, #0x4] */
/* @0x15637c bx lr */

/* ── FUNC 0x156380 · GET_YoYo_GetOSBrowser(CInstance*, int, RValue*) · size=32 · insn=8 */
/* @0x156380 mov r1, #0 */
/* @0x156384 mov r0, #1 */
/* @0x156388 mov r3, r1 */
/* @0x15638c movt r1, #0xbff0 */
/* @0x156390 str r3, [r2, #0xc] */
/* @0x156394 str r1, [r2, #0x4] */
/* @0x156398 str r3, [r2] */
/* @0x15639c bx lr */

/* ── FUNC 0x1563a0 · F_Platform_Function_Not_Supported(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x1563a0 mov r2, #0 */
/* @0x1563a4 mov r3, r2 */
/* @0x1563a8 movt r2, #0xbff0 */
/* @0x1563ac str r3, [r0, #0xc] */
/* @0x1563b0 str r2, [r0, #0x4] */
/* @0x1563b4 str r3, [r0] */
/* @0x1563b8 bx lr */

/* ── FUNC 0x1563bc · F_IO_AddVirtualKey(RValue&, CInstance*, CInstance*, int, RValue*) · size=208 · insn=52 */
/* @0x1563bc push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1563c0 mov r3, #0 */
/* @0x1563c4 mov r5, r3 */
/* @0x1563c8 movt r3, #0xbff0 */
/* @0x1563cc str r5, [r0] */
/* @0x1563d0 mov r6, r0 */
/* @0x1563d4 str r3, [r0, #0x4] */
/* @0x1563d8 str r5, [r0, #0xc] */
/* @0x1563dc ldr r7, [sp, #0x20] */
/* @0x1563e0 bl 0x18c590 <_Z18AllocateVirtualKeyv> */
/* @0x1563e4 subs r4, r0, #0 */
/* @0x1563e8 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1563ec mov r0, r7 */
/* @0x1563f0 mov r1, r5 */
/* @0x1563f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1563f8 mov r1, #1 */
/* @0x1563fc str r0, [r4, #0x4] */
/* @0x156400 mov r0, r7 */
/* @0x156404 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x156408 mov r1, #2 */
/* @0x15640c str r0, [r4, #0x8] */
/* @0x156410 mov r0, r7 */
/* @0x156414 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x156418 mov r1, #3 */
/* @0x15641c str r0, [r4, #0x14] */
/* @0x156420 mov r0, r7 */
/* @0x156424 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x156428 mov r1, #4 */
/* @0x15642c str r0, [r4, #0x18] */
/* @0x156430 mov r0, r7 */
/* @0x156434 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x156438 ldrsh r2, [r4, #2] */
/* @0x15643c mov r1, #1 */
/* @0x156440 ldr r9, [r4, #0x4] */
/* @0x156444 add r2, r2, r1 */
/* @0x156448 ldr r7, [r4, #0x14] */
/* @0x15644c ldr r8, [r4, #0x8] */
/* @0x156450 vmov s15, r2 */
/* @0x156454 ldr r12, [r4, #0x18] */
/* @0x156458 str r5, [r4, #0x20] */
/* @0x15645c add r7, r9, r7 */
/* @0x156460 vcvt.f64.s32 d7, s15 */
/* @0x156464 str r5, [r4, #0x1c] */
/* @0x156468 add r12, r8, r12 */
/* @0x15646c str r5, [r4, #0x28] */
/* @0x156470 str r7, [r4, #0xc] */
/* @0x156474 str r12, [r4, #0x10] */
/* @0x156478 strh r1, [r4] */
/* @0x15647c vmov r2, r3, d7 */
/* @0x156480 str r0, [r4, #0x24] */
/* @0x156484 stm r6, {r2, r3} */
/* @0x156488 pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x15648c · F_IO_ShowVirtualKey(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x15648c push {r4, lr} */
/* @0x156490 mov r1, #0 */
/* @0x156494 ldr r0, [sp, #0x8] */
/* @0x156498 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x15649c subs r4, r0, #1 */
/* @0x1564a0 bmi 0x1564b8 <_Z19F_IO_ShowVirtualKeyR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x1564a4 ldr r3, [pc, #0x40] */
/* @0x1564a8 ldr r3, [pc, r3] */
/* @0x1564ac ldr r3, [r3] */
/* @0x1564b0 cmp r4, r3 */
/* @0x1564b4 blt 0x1564c8 <_Z19F_IO_ShowVirtualKeyR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1564b8 ldr r0, [pc, #0x30] */
/* @0x1564bc mov r1, #0 */
/* @0x1564c0 add r0, pc, r0 */
/* @0x1564c4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1564c8 ldr r3, [pc, #0x24] */
/* @0x1564cc mov r0, #44 */
/* @0x1564d0 mul r0, r0, r4 */
/* @0x1564d4 ldr r3, [pc, r3] */
/* @0x1564d8 ldr r3, [r3] */
/* @0x1564dc ldrh r2, [r3, r0] */
/* @0x1564e0 orr r2, r2, #2 */
/* @0x1564e4 strh r2, [r3, r0] */
/* @0x1564e8 pop {r4, pc} */
/* @0x1564ec eoreq r9, r9, r8, lsr #13 */
/* @0x1564f0 andseq r0, pc, r8, lsl #1 */
/* @0x1564f4 eoreq r9, r9, r0, lsl #13 */

/* ── FUNC 0x1564f8 · F_IO_HideVirtualKey(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x1564f8 push {r4, lr} */
/* @0x1564fc mov r1, #0 */
/* @0x156500 ldr r0, [sp, #0x8] */
/* @0x156504 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x156508 subs r4, r0, #1 */
/* @0x15650c bmi 0x156524 <_Z19F_IO_HideVirtualKeyR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x156510 ldr r3, [pc, #0x40] */
/* @0x156514 ldr r3, [pc, r3] */
/* @0x156518 ldr r3, [r3] */
/* @0x15651c cmp r4, r3 */
/* @0x156520 blt 0x156534 <_Z19F_IO_HideVirtualKeyR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x156524 ldr r0, [pc, #0x30] */
/* @0x156528 mov r1, #0 */
/* @0x15652c add r0, pc, r0 */
/* @0x156530 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x156534 ldr r3, [pc, #0x24] */
/* @0x156538 mov r0, #44 */
/* @0x15653c mul r0, r0, r4 */
/* @0x156540 ldr r3, [pc, r3] */
/* @0x156544 ldr r3, [r3] */
/* @0x156548 ldrh r2, [r3, r0] */
/* @0x15654c bic r2, r2, #2 */
/* @0x156550 strh r2, [r3, r0] */
/* @0x156554 pop {r4, pc} */
/* @0x156558 eoreq r9, r9, r12, lsr r6 */
/* @0x15655c andseq r0, pc, r12, lsl r0 */
/* @0x156560 eoreq r9, r9, r4, lsl r6 */

/* ── FUNC 0x156564 · F_IO_DeleteVirtualKey(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x156564 push {r4, lr} */
/* @0x156568 mov r1, #0 */
/* @0x15656c ldr r0, [sp, #0x8] */
/* @0x156570 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x156574 subs r4, r0, #1 */
/* @0x156578 bmi 0x156590 <_Z21F_IO_DeleteVirtualKeyR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x15657c ldr r3, [pc, #0x28] */
/* @0x156580 ldr r3, [pc, r3] */
/* @0x156584 ldr r3, [r3] */
/* @0x156588 cmp r4, r3 */
/* @0x15658c blt 0x1565a0 <_Z21F_IO_DeleteVirtualKeyR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x156590 ldr r0, [pc, #0x18] */
/* @0x156594 mov r1, #0 */
/* @0x156598 add r0, pc, r0 */
/* @0x15659c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1565a0 mov r0, r4 */
/* @0x1565a4 pop {r4, lr} */
/* @0x1565a8 b 0x18c608 <_Z14FreeVirtualKeyi> */
/* @0x1565ac .word 0x002995d0 */
/* @0x1565b0 ldrheq pc, [lr], -r0 */

/* ── FUNC 0x1565b4 · F_YoYo_LoginAchievements(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x1565b4 b 0x160f7c <_Z17Achievement_Loginv> */

/* ── FUNC 0x1565b8 · F_YoYo_LogoutAchievements(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x1565b8 b 0x160fac <_Z18Achievement_Logoutv> */

/* ── FUNC 0x1565bc · F_YoYo_AchievementsShowAchievements(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x1565bc b 0x160fdc <_Z28Achievement_Show_Achievementv> */

/* ── FUNC 0x1565c0 · F_YoYo_AchievementsShow(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x1565c0 push {r4, r5, r6, lr} */
/* @0x1565c4 mov r1, #0 */
/* @0x1565c8 ldr r4, [sp, #0x10] */
/* @0x1565cc mov r0, r4 */
/* @0x1565d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1565d4 mov r1, #1 */
/* @0x1565d8 mov r6, r0 */
/* @0x1565dc mov r0, r4 */
/* @0x1565e0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1565e4 mov r1, #2 */
/* @0x1565e8 mov r5, r0 */
/* @0x1565ec mov r0, r4 */
/* @0x1565f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1565f4 mov r1, r5 */
/* @0x1565f8 mov r2, r0 */
/* @0x1565fc mov r0, r6 */
/* @0x156600 pop {r4, r5, r6, lr} */
/* @0x156604 b 0x16100c <_Z16Achievement_ShowiPci> */
