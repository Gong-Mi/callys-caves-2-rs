/* libyoyo.so 覆盖卡组 0075
 * 函数 0x14013c..0x141574，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x14013c · F_ActionCDPause(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x14013c b 0x2148ac <_Z8CD_Pausev> */

/* ── FUNC 0x140140 · F_ActionCDResume(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x140140 b 0x2148b0 <_Z9CD_Resumev> */

/* ── FUNC 0x140144 · F_ActionCDPresent(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x140144 push {r3, r4, r5, lr} */
/* @0x140148 mov r5, #0 */
/* @0x14014c str r5, [r0, #0xc] */
/* @0x140150 mov r4, r0 */
/* @0x140154 bl 0x21485c <_Z10CD_Presentv> */
/* @0x140158 cmp r0, #0 */
/* @0x14015c movne r0, r5 */
/* @0x140160 moveq r3, r0 */
/* @0x140164 movne r3, r0 */
/* @0x140168 movtne r3, #0x3ff0 */
/* @0x14016c stm r4, {r0, r3} */
/* @0x140170 pop {r3, r4, r5, pc} */

/* ── FUNC 0x140174 · F_ActionCDPlaying(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x140174 push {r3, r4, r5, lr} */
/* @0x140178 mov r5, #0 */
/* @0x14017c str r5, [r0, #0xc] */
/* @0x140180 mov r4, r0 */
/* @0x140184 bl 0x21486c <_Z10CD_Playingv> */
/* @0x140188 cmp r0, #0 */
/* @0x14018c movne r0, r5 */
/* @0x140190 moveq r3, r0 */
/* @0x140194 movne r3, r0 */
/* @0x140198 movtne r3, #0x3ff0 */
/* @0x14019c stm r4, {r0, r3} */
/* @0x1401a0 pop {r3, r4, r5, pc} */

/* ── FUNC 0x1401a4 · F_ActionSetCursor(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x1401a4 push {r4, lr} */
/* @0x1401a8 mov r1, #0 */
/* @0x1401ac ldr r4, [sp, #0x8] */
/* @0x1401b0 mov r0, r4 */
/* @0x1401b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1401b8 ldr r3, [pc, #0x48] */
/* @0x1401bc mov r1, #1 */
/* @0x1401c0 ldr r3, [pc, r3] */
/* @0x1401c4 str r0, [r3] */
/* @0x1401c8 mov r0, r4 */
/* @0x1401cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1401d0 ldr r3, [pc, #0x34] */
/* @0x1401d4 ldr r3, [pc, r3] */
/* @0x1401d8 cmp r0, #0 */
/* @0x1401dc movle r0, #0 */
/* @0x1401e0 movgt r0, #1 */
/* @0x1401e4 cmp r0, #0 */
/* @0x1401e8 strb r0, [r3] */
/* @0x1401ec bne 0x1401fc <_Z17F_ActionSetCursorR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x1401f0 mvn r0, #0 */
/* @0x1401f4 pop {r4, lr} */
/* @0x1401f8 b 0x17af8c <_Z20GR_Window_Set_Cursori> */
/* @0x1401fc mov r0, #0 */
/* @0x140200 pop {r4, lr} */
/* @0x140204 b 0x17af8c <_Z20GR_Window_Set_Cursori> */
/* @0x140208 eoreq pc, r10, r8, lsr #4 */
/* @0x14020c eoreq pc, r10, r8, lsl r2 */

/* ── FUNC 0x140210 · F_ActionWebpage(RValue&, CInstance*, CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x140210 push {r3, r4, r5, lr} */
/* @0x140214 ldr r5, [sp, #0x10] */
/* @0x140218 bl 0x214e1c <_Z13GetCurrentDirv> */
/* @0x14021c mov r1, #0 */
/* @0x140220 mov r4, r0 */
/* @0x140224 mov r0, r5 */
/* @0x140228 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x14022c cmp r0, #0 */
/* @0x140230 beq 0x14024c <_Z15F_ActionWebpageR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x140234 ldr r1, [pc, #0x2c] */
/* @0x140238 mov r2, r4 */
/* @0x14023c add r1, pc, r1 */
/* @0x140240 bl 0x214ddc <_Z17File_ShellExecutePKcS0_S0_> */
/* @0x140244 cmp r0, #0 */
/* @0x140248 bne 0x14025c <_Z15F_ActionWebpageR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x14024c ldr r0, [pc, #0x18] */
/* @0x140250 mov r1, #0 */
/* @0x140254 add r0, pc, r0 */
/* @0x140258 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14025c mov r0, r4 */
/* @0x140260 pop {r3, r4, r5, lr} */
/* @0x140264 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x140268 ldrsheq lr, [lr], -r10 */
/* @0x14026c .word 0x002006d4 */

/* ── FUNC 0x140270 · F_ActionDrawTextTransformed(RValue&, CInstance*, CInstance*, int, RValue*) · size=280 · insn=70 */
/* @0x140270 push {r4, r5, r6, r7, lr} */
/* @0x140274 vpush {d8} */
/* @0x140278 mov r7, r1 */
/* @0x14027c ldr r1, [pc, #0xfc] */
/* @0x140280 sub sp, sp, #36 */
/* @0x140284 mov r12, #16 */
/* @0x140288 movw r2, #0x811 */
/* @0x14028c mov r0, r12 */
/* @0x140290 add r1, pc, r1 */
/* @0x140294 mov r3, #1 */
/* @0x140298 str r12, [sp, #0x14] */
/* @0x14029c ldr r4, [sp, #0x40] */
/* @0x1402a0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1402a4 add r1, sp, #24 */
/* @0x1402a8 mov r2, #0 */
/* @0x1402ac mov r3, r0 */
/* @0x1402b0 add r0, sp, #32 */
/* @0x1402b4 str r3, [sp, #0x18] */
/* @0x1402b8 str r3, [r0, #-0x4]! */
/* @0x1402bc strb r2, [r3] */
/* @0x1402c0 mov r3, r4 */
/* @0x1402c4 add r2, sp, #20 */
/* @0x1402c8 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x1402cc ldr r0, [sp, #0x18] */
/* @0x1402d0 bl 0x212da8 <_Z19String_Replace_HashPc> */
/* @0x1402d4 mov r0, r4 */
/* @0x1402d8 mov r1, #1 */
/* @0x1402dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1402e0 mov r1, #2 */
/* @0x1402e4 vmov s17, r0 */
/* @0x1402e8 mov r0, r4 */
/* @0x1402ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1402f0 mov r1, #3 */
/* @0x1402f4 vmov s16, r0 */
/* @0x1402f8 mov r0, r4 */
/* @0x1402fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x140300 mov r1, #4 */
/* @0x140304 mov r6, r0 */
/* @0x140308 mov r0, r4 */
/* @0x14030c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x140310 mov r1, #5 */
/* @0x140314 mov r5, r0 */
/* @0x140318 mov r0, r4 */
/* @0x14031c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x140320 ldr r3, [pc, #0x5c] */
/* @0x140324 ldr r2, [sp, #0x18] */
/* @0x140328 ldr r3, [pc, r3] */
/* @0x14032c ldrb r3, [r3] */
/* @0x140330 str r6, [sp, #0x4] */
/* @0x140334 cmp r3, #0 */
/* @0x140338 str r5, [sp, #0x8] */
/* @0x14033c mvn r3, #0 */
/* @0x140340 str r3, [sp] */
/* @0x140344 vmoveq r1, s16 */
/* @0x140348 str r0, [sp, #0xc] */
/* @0x14034c vldrne s14, [r7, #180] */
/* @0x140350 vldrne s15, [r7, #184] */
/* @0x140354 vaddne.f32 s14, s17, s14 */
/* @0x140358 vmoveq r0, s17 */
/* @0x14035c vaddne.f32 s15, s16, s15 */
/* @0x140360 vmovne r0, s14 */
/* @0x140364 vmovne r1, s15 */
/* @0x140368 bl 0x173068 <_Z24GR_Text_Draw_TransformedffPKciifff> */
/* @0x14036c ldr r0, [sp, #0x18] */
/* @0x140370 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x140374 add sp, sp, #36 */
/* @0x140378 vpop {d8} */
/* @0x14037c pop {r4, r5, r6, r7, pc} */
/* @0x140380 eoreq r0, r0, r12, asr r6 */
/* @0x140384 eoreq sp, r10, r4, lsl r8 */

/* ── FUNC 0x140388 · F_ActionDrawRectangle(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0x140388 push {r4, r5, r6, lr} */
/* @0x14038c vpush {d8, d9} */
/* @0x140390 mov r5, r1 */
/* @0x140394 ldr r4, [sp, #0x20] */
/* @0x140398 mov r1, #0 */
/* @0x14039c mov r0, r4 */
/* @0x1403a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1403a4 mov r1, #1 */
/* @0x1403a8 vmov s19, r0 */
/* @0x1403ac mov r0, r4 */
/* @0x1403b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1403b4 mov r1, #2 */
/* @0x1403b8 vmov s18, r0 */
/* @0x1403bc mov r0, r4 */
/* @0x1403c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1403c4 mov r1, #3 */
/* @0x1403c8 vmov s17, r0 */
/* @0x1403cc mov r0, r4 */
/* @0x1403d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1403d4 mov r1, #4 */
/* @0x1403d8 vmov s16, r0 */
/* @0x1403dc mov r0, r4 */
/* @0x1403e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1403e4 ldr r3, [pc, #0x6c] */
/* @0x1403e8 ldr r3, [pc, r3] */
/* @0x1403ec ldrb r3, [r3] */
/* @0x1403f0 cmp r0, #0 */
/* @0x1403f4 movle r0, #0 */
/* @0x1403f8 movgt r0, #1 */
/* @0x1403fc cmp r3, #0 */
/* @0x140400 str r0, [sp, #0x20] */
/* @0x140404 bne 0x140424 <_Z21F_ActionDrawRectangleR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x140408 vmov r0, s19 */
/* @0x14040c vmov r1, s18 */
/* @0x140410 vmov r2, s17 */
/* @0x140414 vmov r3, s16 */
/* @0x140418 vpop {d8, d9} */
/* @0x14041c pop {r4, r5, r6, lr} */
/* @0x140420 b 0x16aa1c <_Z20YYGML_draw_rectangleffffb> */
/* @0x140424 vldr s14, [r5, #180] */
/* @0x140428 vldr s15, [r5, #184] */
/* @0x14042c vadd.f32 s19, s19, s14 */
/* @0x140430 vadd.f32 s18, s18, s15 */
/* @0x140434 vmov r0, s19 */
/* @0x140438 vadd.f32 s14, s17, s14 */
/* @0x14043c vmov r1, s18 */
/* @0x140440 vadd.f32 s15, s16, s15 */
/* @0x140444 vpop {d8, d9} */
/* @0x140448 vmov r2, s14 */
/* @0x14044c pop {r4, r5, r6, lr} */
/* @0x140450 vmov r3, s15 */
/* @0x140454 b 0x16aa1c <_Z20YYGML_draw_rectangleffffb> */
/* @0x140458 eoreq sp, r10, r4, asr r7 */

/* ── FUNC 0x14045c · F_ActionDrawGradientHor(RValue&, CInstance*, CInstance*, int, RValue*) · size=268 · insn=67 */
/* @0x14045c push {r4, r5, r6, lr} */
/* @0x140460 vpush {d8, d9} */
/* @0x140464 sub sp, sp, #24 */
/* @0x140468 mov r6, r1 */
/* @0x14046c mov r1, #0 */
/* @0x140470 ldr r4, [sp, #0x38] */
/* @0x140474 mov r0, r4 */
/* @0x140478 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14047c mov r1, #1 */
/* @0x140480 vmov s19, r0 */
/* @0x140484 mov r0, r4 */
/* @0x140488 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14048c mov r1, #2 */
/* @0x140490 vmov s18, r0 */
/* @0x140494 mov r0, r4 */
/* @0x140498 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14049c mov r1, #3 */
/* @0x1404a0 vmov s17, r0 */
/* @0x1404a4 mov r0, r4 */
/* @0x1404a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1404ac mov r1, #4 */
/* @0x1404b0 vmov s16, r0 */
/* @0x1404b4 mov r0, r4 */
/* @0x1404b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1404bc mov r1, #5 */
/* @0x1404c0 mov r5, r0 */
/* @0x1404c4 mov r0, r4 */
/* @0x1404c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1404cc ldr r3, [pc, #0x90] */
/* @0x1404d0 ldr r3, [pc, r3] */
/* @0x1404d4 ldrb r3, [r3] */
/* @0x1404d8 str r5, [sp] */
/* @0x1404dc cmp r3, #0 */
/* @0x1404e0 mov r2, r0 */
/* @0x1404e4 bne 0x140518 <_Z23F_ActionDrawGradientHorR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x1404e8 str r0, [sp, #0x4] */
/* @0x1404ec str r0, [sp, #0x8] */
/* @0x1404f0 str r3, [sp, #0x10] */
/* @0x1404f4 str r5, [sp, #0xc] */
/* @0x1404f8 vmov r0, s19 */
/* @0x1404fc vmov r1, s18 */
/* @0x140500 vmov r2, s17 */
/* @0x140504 vmov r3, s16 */
/* @0x140508 bl 0x16ac60 <_Z21GR_Draw_Rectangle_Extffffjjjjb> */
/* @0x14050c add sp, sp, #24 */
/* @0x140510 vpop {d8, d9} */
/* @0x140514 pop {r4, r5, r6, pc} */
/* @0x140518 vldr s14, [r6, #180] */
/* @0x14051c str r0, [sp, #0x4] */
/* @0x140520 str r2, [sp, #0x8] */
/* @0x140524 vadd.f32 s19, s19, s14 */
/* @0x140528 vldr s15, [r6, #184] */
/* @0x14052c mov r3, #0 */
/* @0x140530 str r5, [sp, #0xc] */
/* @0x140534 str r3, [sp, #0x10] */
/* @0x140538 vadd.f32 s14, s17, s14 */
/* @0x14053c vmov r0, s19 */
/* @0x140540 vadd.f32 s18, s18, s15 */
/* @0x140544 vmov r2, s14 */
/* @0x140548 vadd.f32 s15, s16, s15 */
/* @0x14054c vmov r1, s18 */
/* @0x140550 vmov r3, s15 */
/* @0x140554 bl 0x16ac60 <_Z21GR_Draw_Rectangle_Extffffjjjjb> */
/* @0x140558 add sp, sp, #24 */
/* @0x14055c vpop {d8, d9} */
/* @0x140560 pop {r4, r5, r6, pc} */
/* @0x140564 eoreq sp, r10, r12, ror #12 */

/* ── FUNC 0x140568 · F_ActionDrawGradientVert(RValue&, CInstance*, CInstance*, int, RValue*) · size=268 · insn=67 */
/* @0x140568 push {r4, r5, r6, lr} */
/* @0x14056c vpush {d8, d9} */
/* @0x140570 sub sp, sp, #24 */
/* @0x140574 mov r6, r1 */
/* @0x140578 mov r1, #0 */
/* @0x14057c ldr r4, [sp, #0x38] */
/* @0x140580 mov r0, r4 */
/* @0x140584 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x140588 mov r1, #1 */
/* @0x14058c vmov s19, r0 */
/* @0x140590 mov r0, r4 */
/* @0x140594 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x140598 mov r1, #2 */
/* @0x14059c vmov s18, r0 */
/* @0x1405a0 mov r0, r4 */
/* @0x1405a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1405a8 mov r1, #3 */
/* @0x1405ac vmov s17, r0 */
/* @0x1405b0 mov r0, r4 */
/* @0x1405b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1405b8 mov r1, #4 */
/* @0x1405bc vmov s16, r0 */
/* @0x1405c0 mov r0, r4 */
/* @0x1405c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1405c8 mov r1, #5 */
/* @0x1405cc mov r5, r0 */
/* @0x1405d0 mov r0, r4 */
/* @0x1405d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1405d8 ldr r3, [pc, #0x90] */
/* @0x1405dc ldr r3, [pc, r3] */
/* @0x1405e0 ldrb r3, [r3] */
/* @0x1405e4 str r5, [sp] */
/* @0x1405e8 cmp r3, #0 */
/* @0x1405ec mov r2, r0 */
/* @0x1405f0 bne 0x140624 <_Z24F_ActionDrawGradientVertR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x1405f4 str r0, [sp, #0x8] */
/* @0x1405f8 str r0, [sp, #0xc] */
/* @0x1405fc str r3, [sp, #0x10] */
/* @0x140600 str r5, [sp, #0x4] */
/* @0x140604 vmov r0, s19 */
/* @0x140608 vmov r1, s18 */
/* @0x14060c vmov r2, s17 */
/* @0x140610 vmov r3, s16 */
/* @0x140614 bl 0x16ac60 <_Z21GR_Draw_Rectangle_Extffffjjjjb> */
/* @0x140618 add sp, sp, #24 */
/* @0x14061c vpop {d8, d9} */
/* @0x140620 pop {r4, r5, r6, pc} */
/* @0x140624 vldr s14, [r6, #180] */
/* @0x140628 str r2, [sp, #0x8] */
/* @0x14062c str r5, [sp, #0x4] */
/* @0x140630 vadd.f32 s19, s19, s14 */
/* @0x140634 vldr s15, [r6, #184] */
/* @0x140638 mov r3, #0 */
/* @0x14063c str r2, [sp, #0xc] */
/* @0x140640 str r3, [sp, #0x10] */
/* @0x140644 vadd.f32 s14, s17, s14 */
/* @0x140648 vmov r0, s19 */
/* @0x14064c vadd.f32 s18, s18, s15 */
/* @0x140650 vmov r2, s14 */
/* @0x140654 vadd.f32 s15, s16, s15 */
/* @0x140658 vmov r1, s18 */
/* @0x14065c vmov r3, s15 */
/* @0x140660 bl 0x16ac60 <_Z21GR_Draw_Rectangle_Extffffjjjjb> */
/* @0x140664 add sp, sp, #24 */
/* @0x140668 vpop {d8, d9} */
/* @0x14066c pop {r4, r5, r6, pc} */
/* @0x140670 eoreq sp, r10, r0, ror #10 */

/* ── FUNC 0x140674 · F_ActionDrawEllipse(RValue&, CInstance*, CInstance*, int, RValue*) · size=200 · insn=50 */
/* @0x140674 push {r4, r5, r6, lr} */
/* @0x140678 vpush {d8, d9} */
/* @0x14067c mov r5, r1 */
/* @0x140680 ldr r4, [sp, #0x20] */
/* @0x140684 mov r1, #0 */
/* @0x140688 mov r0, r4 */
/* @0x14068c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x140690 mov r1, #1 */
/* @0x140694 vmov s19, r0 */
/* @0x140698 mov r0, r4 */
/* @0x14069c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1406a0 mov r1, #2 */
/* @0x1406a4 vmov s18, r0 */
/* @0x1406a8 mov r0, r4 */
/* @0x1406ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1406b0 mov r1, #3 */
/* @0x1406b4 vmov s17, r0 */
/* @0x1406b8 mov r0, r4 */
/* @0x1406bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1406c0 mov r1, #4 */
/* @0x1406c4 vmov s16, r0 */
/* @0x1406c8 mov r0, r4 */
/* @0x1406cc bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1406d0 ldr r3, [pc, #0x60] */
/* @0x1406d4 ldr r3, [pc, r3] */
/* @0x1406d8 ldrb r3, [r3] */
/* @0x1406dc cmp r3, #0 */
/* @0x1406e0 str r0, [sp, #0x20] */
/* @0x1406e4 bne 0x140704 <_Z19F_ActionDrawEllipseR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x1406e8 vmov r0, s19 */
/* @0x1406ec vmov r1, s18 */
/* @0x1406f0 vmov r2, s17 */
/* @0x1406f4 vmov r3, s16 */
/* @0x1406f8 vpop {d8, d9} */
/* @0x1406fc pop {r4, r5, r6, lr} */
/* @0x140700 b 0x16b278 <_Z15GR_Draw_Ellipseffffb> */
/* @0x140704 vldr s14, [r5, #180] */
/* @0x140708 vldr s15, [r5, #184] */
/* @0x14070c vadd.f32 s19, s19, s14 */
/* @0x140710 vadd.f32 s18, s18, s15 */
/* @0x140714 vmov r0, s19 */
/* @0x140718 vadd.f32 s14, s17, s14 */
/* @0x14071c vmov r1, s18 */
/* @0x140720 vadd.f32 s15, s16, s15 */
/* @0x140724 vpop {d8, d9} */
/* @0x140728 vmov r2, s14 */
/* @0x14072c pop {r4, r5, r6, lr} */
/* @0x140730 vmov r3, s15 */
/* @0x140734 b 0x16b278 <_Z15GR_Draw_Ellipseffffb> */
/* @0x140738 eoreq sp, r10, r8, ror #8 */

/* ── FUNC 0x14073c · F_ActionDrawEllipseGradient(RValue&, CInstance*, CInstance*, int, RValue*) · size=244 · insn=61 */
/* @0x14073c push {r4, r5, r6, lr} */
/* @0x140740 vpush {d8, d9} */
/* @0x140744 sub sp, sp, #16 */
/* @0x140748 mov r6, r1 */
/* @0x14074c mov r1, #0 */
/* @0x140750 ldr r4, [sp, #0x30] */
/* @0x140754 mov r0, r4 */
/* @0x140758 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14075c mov r1, #1 */
/* @0x140760 vmov s19, r0 */
/* @0x140764 mov r0, r4 */
/* @0x140768 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14076c mov r1, #2 */
/* @0x140770 vmov s18, r0 */
/* @0x140774 mov r0, r4 */
/* @0x140778 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14077c mov r1, #3 */
/* @0x140780 vmov s17, r0 */
/* @0x140784 mov r0, r4 */
/* @0x140788 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14078c mov r1, #4 */
/* @0x140790 vmov s16, r0 */
/* @0x140794 mov r0, r4 */
/* @0x140798 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14079c mov r1, #5 */
/* @0x1407a0 mov r5, r0 */
/* @0x1407a4 mov r0, r4 */
/* @0x1407a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1407ac ldr r3, [pc, #0x78] */
/* @0x1407b0 ldr r3, [pc, r3] */
/* @0x1407b4 ldrb r3, [r3] */
/* @0x1407b8 str r5, [sp] */
/* @0x1407bc cmp r3, #0 */
/* @0x1407c0 bne 0x1407e8 <_Z27F_ActionDrawEllipseGradientR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x1407c4 stmib sp, {r0, r3} */
/* @0x1407c8 vmov r1, s18 */
/* @0x1407cc vmov r0, s19 */
/* @0x1407d0 vmov r2, s17 */
/* @0x1407d4 vmov r3, s16 */
/* @0x1407d8 bl 0x16b2ac <_Z19GR_Draw_Ellipse_Extffffjjb> */
/* @0x1407dc add sp, sp, #16 */
/* @0x1407e0 vpop {d8, d9} */
/* @0x1407e4 pop {r4, r5, r6, pc} */
/* @0x1407e8 vldr s14, [r6, #180] */
/* @0x1407ec str r0, [sp, #0x4] */
/* @0x1407f0 vadd.f32 s19, s19, s14 */
/* @0x1407f4 vldr s15, [r6, #184] */
/* @0x1407f8 mov r3, #0 */
/* @0x1407fc str r3, [sp, #0x8] */
/* @0x140800 vadd.f32 s14, s17, s14 */
/* @0x140804 vmov r0, s19 */
/* @0x140808 vadd.f32 s18, s18, s15 */
/* @0x14080c vmov r2, s14 */
/* @0x140810 vadd.f32 s15, s16, s15 */
/* @0x140814 vmov r1, s18 */
/* @0x140818 vmov r3, s15 */
/* @0x14081c bl 0x16b2ac <_Z19GR_Draw_Ellipse_Extffffjjb> */
/* @0x140820 add sp, sp, #16 */
/* @0x140824 vpop {d8, d9} */
/* @0x140828 pop {r4, r5, r6, pc} */
/* @0x14082c eoreq sp, r10, r12, lsl #7 */

/* ── FUNC 0x140830 · F_ActionDrawLine(RValue&, CInstance*, CInstance*, int, RValue*) · size=184 · insn=46 */
/* @0x140830 push {r4, r5, r6, lr} */
/* @0x140834 vpush {d8, d9} */
/* @0x140838 mov r5, r1 */
/* @0x14083c ldr r4, [sp, #0x20] */
/* @0x140840 mov r1, #0 */
/* @0x140844 mov r0, r4 */
/* @0x140848 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14084c mov r1, #1 */
/* @0x140850 vmov s18, r0 */
/* @0x140854 mov r0, r4 */
/* @0x140858 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14085c mov r1, #2 */
/* @0x140860 vmov s17, r0 */
/* @0x140864 mov r0, r4 */
/* @0x140868 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14086c mov r1, #3 */
/* @0x140870 vmov s16, r0 */
/* @0x140874 mov r0, r4 */
/* @0x140878 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14087c ldr r3, [pc, #0x60] */
/* @0x140880 ldr r3, [pc, r3] */
/* @0x140884 ldrb r3, [r3] */
/* @0x140888 cmp r3, #0 */
/* @0x14088c vmov s15, r0 */
/* @0x140890 bne 0x1408b0 <_Z16F_ActionDrawLineR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x140894 vmov r0, s18 */
/* @0x140898 vmov r1, s17 */
/* @0x14089c vmov r2, s16 */
/* @0x1408a0 vpop {d8, d9} */
/* @0x1408a4 vmov r3, s15 */
/* @0x1408a8 pop {r4, r5, r6, lr} */
/* @0x1408ac b 0x16a21c <_Z12GR_Draw_Lineffff> */
/* @0x1408b0 vldr s13, [r5, #180] */
/* @0x1408b4 vldr s14, [r5, #184] */
/* @0x1408b8 vadd.f32 s18, s18, s13 */
/* @0x1408bc vadd.f32 s17, s17, s14 */
/* @0x1408c0 vmov r0, s18 */
/* @0x1408c4 vadd.f32 s13, s16, s13 */
/* @0x1408c8 vmov r1, s17 */
/* @0x1408cc vpop {d8, d9} */
/* @0x1408d0 pop {r4, r5, r6, lr} */
/* @0x1408d4 vadd.f32 s14, s15, s14 */
/* @0x1408d8 vmov r2, s13 */
/* @0x1408dc vmov r3, s14 */
/* @0x1408e0 b 0x16a21c <_Z12GR_Draw_Lineffff> */
/* @0x1408e4 .word 0x002ad2bc */

/* ── FUNC 0x1408e8 · F_ActionDrawArrow(RValue&, CInstance*, CInstance*, int, RValue*) · size=200 · insn=50 */
/* @0x1408e8 push {r4, r5, r6, lr} */
/* @0x1408ec vpush {d8, d9} */
/* @0x1408f0 mov r5, r1 */
/* @0x1408f4 ldr r4, [sp, #0x20] */
/* @0x1408f8 mov r1, #0 */
/* @0x1408fc mov r0, r4 */
/* @0x140900 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x140904 mov r1, #1 */
/* @0x140908 vmov s19, r0 */
/* @0x14090c mov r0, r4 */
/* @0x140910 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x140914 mov r1, #2 */
/* @0x140918 vmov s18, r0 */
/* @0x14091c mov r0, r4 */
/* @0x140920 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x140924 mov r1, #3 */
/* @0x140928 vmov s17, r0 */
/* @0x14092c mov r0, r4 */
/* @0x140930 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x140934 mov r1, #4 */
/* @0x140938 vmov s16, r0 */
/* @0x14093c mov r0, r4 */
/* @0x140940 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x140944 ldr r3, [pc, #0x60] */
/* @0x140948 ldr r3, [pc, r3] */
/* @0x14094c ldrb r3, [r3] */
/* @0x140950 cmp r3, #0 */
/* @0x140954 str r0, [sp, #0x20] */
/* @0x140958 bne 0x140978 <_Z17F_ActionDrawArrowR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x14095c vmov r0, s19 */
/* @0x140960 vmov r1, s18 */
/* @0x140964 vmov r2, s17 */
/* @0x140968 vmov r3, s16 */
/* @0x14096c vpop {d8, d9} */
/* @0x140970 pop {r4, r5, r6, lr} */
/* @0x140974 b 0x16bee4 <_Z13GR_Draw_Arrowfffff> */
/* @0x140978 vldr s14, [r5, #180] */
/* @0x14097c vldr s15, [r5, #184] */
/* @0x140980 vadd.f32 s19, s19, s14 */
/* @0x140984 vadd.f32 s18, s18, s15 */
/* @0x140988 vmov r0, s19 */
/* @0x14098c vadd.f32 s14, s17, s14 */
/* @0x140990 vmov r1, s18 */
/* @0x140994 vadd.f32 s15, s16, s15 */
/* @0x140998 vpop {d8, d9} */
/* @0x14099c vmov r2, s14 */
/* @0x1409a0 pop {r4, r5, r6, lr} */
/* @0x1409a4 vmov r3, s15 */
/* @0x1409a8 b 0x16bee4 <_Z13GR_Draw_Arrowfffff> */
/* @0x1409ac .word 0x002ad1f4 */

/* ── FUNC 0x1409b0 · F_ActionColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x1409b0 push {r3, lr} */
/* @0x1409b4 mov r1, #0 */
/* @0x1409b8 ldr r0, [sp, #0x8] */
/* @0x1409bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1409c0 pop {r3, lr} */
/* @0x1409c4 b 0x169d98 <_Z21YYGML_draw_set_colourj> */

/* ── FUNC 0x1409c8 · F_ActionFont(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x1409c8 push {r4, lr} */
/* @0x1409cc mov r1, #0 */
/* @0x1409d0 ldr r4, [sp, #0x8] */
/* @0x1409d4 mov r0, r4 */
/* @0x1409d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1409dc bl 0x172ac8 <_Z16GR_Text_Set_Fonti> */
/* @0x1409e0 mov r0, r4 */
/* @0x1409e4 mov r1, #1 */
/* @0x1409e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1409ec pop {r4, lr} */
/* @0x1409f0 b 0x172b30 <_Z18GR_Text_Set_HAligni> */

/* ── FUNC 0x1409f4 · F_ActionSnapshot(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x1409f4 push {r3, lr} */
/* @0x1409f8 mov r1, #0 */
/* @0x1409fc ldr r0, [sp, #0x8] */
/* @0x140a00 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x140a04 pop {r3, lr} */
/* @0x140a08 b 0x1c9fac <_Z18Command_ScreenShotPKc> */

/* ── FUNC 0x140a0c · F_ActionEffect(RValue&, CInstance*, CInstance*, int, RValue*) · size=192 · insn=48 */
/* @0x140a0c push {r4, r5, r6, r7, r8, lr} */
/* @0x140a10 vpush {d8} */
/* @0x140a14 sub sp, sp, #8 */
/* @0x140a18 mov r8, r1 */
/* @0x140a1c mov r1, #0 */
/* @0x140a20 ldr r4, [sp, #0x28] */
/* @0x140a24 mov r0, r4 */
/* @0x140a28 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x140a2c mov r1, #1 */
/* @0x140a30 mov r6, r0 */
/* @0x140a34 mov r0, r4 */
/* @0x140a38 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x140a3c mov r1, #2 */
/* @0x140a40 vmov s17, r0 */
/* @0x140a44 mov r0, r4 */
/* @0x140a48 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x140a4c mov r1, #3 */
/* @0x140a50 vmov s16, r0 */
/* @0x140a54 mov r0, r4 */
/* @0x140a58 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x140a5c mov r1, #4 */
/* @0x140a60 mov r7, r0 */
/* @0x140a64 mov r0, r4 */
/* @0x140a68 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x140a6c mov r1, #5 */
/* @0x140a70 mov r5, r0 */
/* @0x140a74 mov r0, r4 */
/* @0x140a78 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x140a7c ldr r3, [pc, #0x44] */
/* @0x140a80 mov r1, r6 */
/* @0x140a84 ldr r3, [pc, r3] */
/* @0x140a88 ldrb r3, [r3] */
/* @0x140a8c str r7, [sp] */
/* @0x140a90 cmp r3, #0 */
/* @0x140a94 str r5, [sp, #0x4] */
/* @0x140a98 vldrne s14, [r8, #180] */
/* @0x140a9c vldrne s15, [r8, #184] */
/* @0x140aa0 vmoveq r2, s17 */
/* @0x140aa4 vmoveq r3, s16 */
/* @0x140aa8 vaddne.f32 s14, s17, s14 */
/* @0x140aac vaddne.f32 s15, s16, s15 */
/* @0x140ab0 vmovne r2, s14 */
/* @0x140ab4 vmovne r3, s15 */
/* @0x140ab8 bl 0x1a25d0 <_Z13Effect_Createbiffij> */
/* @0x140abc add sp, sp, #8 */
/* @0x140ac0 vpop {d8} */
/* @0x140ac4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x140ac8 strhteq sp, [r10], -r8 */

/* ── FUNC 0x140acc · F_ActionReplaceBackground(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0x140acc push {r4, r5, r6, r7, r8, lr} */
/* @0x140ad0 mov r1, #0 */
/* @0x140ad4 ldr r4, [sp, #0x18] */
/* @0x140ad8 mov r0, r4 */
/* @0x140adc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x140ae0 mov r1, #1 */
/* @0x140ae4 mov r5, r0 */
/* @0x140ae8 mov r0, r4 */
/* @0x140aec bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x140af0 mov r4, r0 */
/* @0x140af4 mov r0, r5 */
/* @0x140af8 bl 0xc3640 <_Z17Background_Existsi> */
/* @0x140afc subs r1, r0, #0 */
/* @0x140b00 beq 0x140b68 <_Z25F_ActionReplaceBackgroundR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x140b04 mov r0, r4 */
/* @0x140b08 bl 0x214e48 <_Z10FileExistsPKc> */
/* @0x140b0c subs r1, r0, #0 */
/* @0x140b10 beq 0x140b58 <_Z25F_ActionReplaceBackgroundR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x140b14 mov r0, r5 */
/* @0x140b18 bl 0xc3794 <_Z15Background_Datai> */
/* @0x140b1c mov r6, r0 */
/* @0x140b20 bl 0xc2d88 <_ZN11CBackground14GetTransparentEv> */
/* @0x140b24 mov r8, r0 */
/* @0x140b28 mov r0, r6 */
/* @0x140b2c bl 0xc2d90 <_ZN11CBackground6SmoothEv> */
/* @0x140b30 mov r7, r0 */
/* @0x140b34 mov r0, r6 */
/* @0x140b38 bl 0xc2d98 <_ZN11CBackground10GetPreloadEv> */
/* @0x140b3c mov r2, r8 */
/* @0x140b40 mov r3, r7 */
/* @0x140b44 mov r1, r4 */
/* @0x140b48 str r0, [sp, #0x18] */
/* @0x140b4c mov r0, r5 */
/* @0x140b50 pop {r4, r5, r6, r7, r8, lr} */
/* @0x140b54 b 0xc3aa4 <_Z18Background_ReplaceiPKcbbb> */
/* @0x140b58 ldr r0, [pc, #0x18] */
/* @0x140b5c pop {r4, r5, r6, r7, r8, lr} */
/* @0x140b60 add r0, pc, r0 */
/* @0x140b64 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x140b68 ldr r0, [pc, #0xc] */
/* @0x140b6c pop {r4, r5, r6, r7, r8, lr} */
/* @0x140b70 add r0, pc, r0 */
/* @0x140b74 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x140b78 andseq pc, pc, r0, lsl lr */
/* @0x140b7c ldrsbeq pc, [pc], -r4 */

/* ── FUNC 0x140b80 · F_ActionIfMouse(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x140b80 push {r3, r4, r5, r6, r7, lr} */
/* @0x140b84 mov r1, #0 */
/* @0x140b88 mov r4, r0 */
/* @0x140b8c ldr r0, [sp, #0x18] */
/* @0x140b90 mov r5, r1 */
/* @0x140b94 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x140b98 str r5, [r4, #0xc] */
/* @0x140b9c cmp r0, #2 */
/* @0x140ba0 mov r6, r0 */
/* @0x140ba4 beq 0x140be4 <_Z15F_ActionIfMouseR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x140ba8 cmp r0, #3 */
/* @0x140bac beq 0x140be4 <_Z15F_ActionIfMouseR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x140bb0 cmp r0, #1 */
/* @0x140bb4 beq 0x140be4 <_Z15F_ActionIfMouseR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x140bb8 mov r0, r5 */
/* @0x140bbc bl 0x18c048 <_Z21IO_Button_Current_Geti> */
/* @0x140bc0 cmp r0, #0 */
/* @0x140bc4 movne r3, r5 */
/* @0x140bc8 bne 0x140bd8 <_Z15F_ActionIfMouseR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x140bcc mov r5, r0 */
/* @0x140bd0 mov r3, #0 */
/* @0x140bd4 movt r3, #0x3ff0 */
/* @0x140bd8 str r5, [r4] */
/* @0x140bdc str r3, [r4, #0x4] */
/* @0x140be0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x140be4 mov r1, r5 */
/* @0x140be8 bl 0x18c0b4 <_Z14IO_Button_Downii> */
/* @0x140bec subs r7, r0, #0 */
/* @0x140bf0 bne 0x140bd0 <_Z15F_ActionIfMouseR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x140bf4 mov r0, r6 */
/* @0x140bf8 mov r1, r7 */
/* @0x140bfc bl 0x18c12c <_Z18IO_Button_Releasedii> */
/* @0x140c00 cmp r0, #0 */
/* @0x140c04 moveq r5, r0 */
/* @0x140c08 movne r3, #0 */
/* @0x140c0c moveq r3, r5 */
/* @0x140c10 movtne r3, #0x3ff0 */
/* @0x140c14 movne r5, r7 */
/* @0x140c18 b 0x140bd8 <_Z15F_ActionIfMouseR6RValueP9CInstanceS2_iPS_+0x58> */

/* ── FUNC 0x140c1c · F_ActionSetLife(RValue&, CInstance*, CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x140c1c push {r3, lr} */
/* @0x140c20 mov r1, #0 */
/* @0x140c24 ldr r0, [sp, #0x8] */
/* @0x140c28 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x140c2c ldr r2, [pc, #0x40] */
/* @0x140c30 ldr r3, [pc, #0x40] */
/* @0x140c34 ldr r2, [pc, r2] */
/* @0x140c38 ldr r3, [pc, r3] */
/* @0x140c3c ldrb r1, [r2] */
/* @0x140c40 ldr r2, [r3] */
/* @0x140c44 cmp r1, #0 */
/* @0x140c48 addne r0, r0, r2 */
/* @0x140c4c cmp r2, #0 */
/* @0x140c50 str r0, [r3] */
/* @0x140c54 pople {r3, pc} */
/* @0x140c58 ldr r3, [r3] */
/* @0x140c5c cmp r3, #0 */
/* @0x140c60 popgt {r3, pc} */
/* @0x140c64 mov r0, #7 */
/* @0x140c68 mov r1, #6 */
/* @0x140c6c pop {r3, lr} */
/* @0x140c70 b 0xf33b0 <_Z17Perform_Event_Allii> */
/* @0x140c74 eoreq r12, r10, r8, lsl #30 */
/* @0x140c78 mlaeq r10, r8, r7, lr */

/* ── FUNC 0x140c7c · F_ActionSetHealth(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x140c7c push {r3, lr} */
/* @0x140c80 mov r1, #0 */
/* @0x140c84 ldr r0, [sp, #0x8] */
/* @0x140c88 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x140c8c ldr r2, [pc, #0x4c] */
/* @0x140c90 ldr r3, [pc, #0x4c] */
/* @0x140c94 ldr r2, [pc, r2] */
/* @0x140c98 ldr r3, [pc, r3] */
/* @0x140c9c vldr d7, [r3] */
/* @0x140ca0 ldrb r2, [r2] */
/* @0x140ca4 vcmpe.f64 d7, #0 */
/* @0x140ca8 cmp r2, #0 */
/* @0x140cac vmov d6, r0, r1 */
/* @0x140cb0 vaddne.f64 d6, d6, d7 */
/* @0x140cb4 vmrs APSR_nzcv, fpscr */
/* @0x140cb8 vstr d6, [r3] */
/* @0x140cbc pople {r3, pc} */
/* @0x140cc0 vldr d7, [r3] */
/* @0x140cc4 vcmpe.f64 d7, #0 */
/* @0x140cc8 vmrs APSR_nzcv, fpscr */
/* @0x140ccc pophi {r3, pc} */
/* @0x140cd0 mov r0, #7 */
/* @0x140cd4 mov r1, #9 */
/* @0x140cd8 pop {r3, lr} */
/* @0x140cdc b 0xf33b0 <_Z17Perform_Event_Allii> */
/* @0x140ce0 eoreq r12, r10, r8, lsr #29 */
/* @0x140ce4 eoreq lr, r10, r0, asr #14 */

/* ── FUNC 0x140ce8 · F_ActionPartEmitBurst(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0x140ce8 push {r4, r5, r6, r7, lr} */
/* @0x140cec sub sp, sp, #12 */
/* @0x140cf0 mov r1, #0 */
/* @0x140cf4 ldr r4, [pc, #0xa0] */
/* @0x140cf8 ldr r5, [sp, #0x20] */
/* @0x140cfc mov r0, r5 */
/* @0x140d00 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x140d04 mov r1, #1 */
/* @0x140d08 mov r6, r0 */
/* @0x140d0c mov r0, r5 */
/* @0x140d10 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x140d14 mov r1, #2 */
/* @0x140d18 mov r7, r0 */
/* @0x140d1c mov r0, r5 */
/* @0x140d20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x140d24 ldr r4, [pc, r4] */
/* @0x140d28 ldr r2, [r4] */
/* @0x140d2c cmp r2, #0 */
/* @0x140d30 mov r3, r0 */
/* @0x140d34 blt 0x140d80 <_Z21F_ActionPartEmitBurstR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x140d38 ldr r2, [pc, #0x60] */
/* @0x140d3c ldr r2, [pc, r2] */
/* @0x140d40 ldr r1, [r2, r6, lsl #2] */
/* @0x140d44 cmp r1, #0 */
/* @0x140d48 blt 0x140d68 <_Z21F_ActionPartEmitBurstR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x140d4c ldr r2, [pc, #0x50] */
/* @0x140d50 ldr r0, [r4] */
/* @0x140d54 ldr r2, [pc, r2] */
/* @0x140d58 ldr r2, [r2, r7, lsl #2] */
/* @0x140d5c add sp, sp, #12 */
/* @0x140d60 pop {r4, r5, r6, r7, lr} */
/* @0x140d64 b 0x1a3cf0 <_Z28ParticleSystem_Emitter_Burstiiii> */
/* @0x140d68 ldr r0, [pc, #0x38] */
/* @0x140d6c mov r1, #0 */
/* @0x140d70 add r0, pc, r0 */
/* @0x140d74 add sp, sp, #12 */
/* @0x140d78 pop {r4, r5, r6, r7, lr} */
/* @0x140d7c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x140d80 mvn r0, #0 */
/* @0x140d84 mov r1, #1 */
/* @0x140d88 str r3, [sp, #0x4] */
/* @0x140d8c bl 0x1a42dc <_Z21ParticleSystem_Createib> */
/* @0x140d90 ldr r3, [sp, #0x4] */
/* @0x140d94 str r0, [r4] */
/* @0x140d98 b 0x140d38 <_Z21F_ActionPartEmitBurstR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x140d9c .word 0x002ae6b8 */
/* @0x140da0 eoreq lr, r10, r8, lsr #13 */
/* @0x140da4 eoreq lr, r10, r12, lsl #13 */
/* @0x140da8 andseq pc, pc, r8, lsl r12 */

/* ── FUNC 0x140dac · F_ActionPartEmitStream(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0x140dac push {r4, r5, r6, r7, lr} */
/* @0x140db0 sub sp, sp, #12 */
/* @0x140db4 mov r1, #0 */
/* @0x140db8 ldr r4, [pc, #0xa0] */
/* @0x140dbc ldr r5, [sp, #0x20] */
/* @0x140dc0 mov r0, r5 */
/* @0x140dc4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x140dc8 mov r1, #1 */
/* @0x140dcc mov r6, r0 */
/* @0x140dd0 mov r0, r5 */
/* @0x140dd4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x140dd8 mov r1, #2 */
/* @0x140ddc mov r7, r0 */
/* @0x140de0 mov r0, r5 */
/* @0x140de4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x140de8 ldr r4, [pc, r4] */
/* @0x140dec ldr r2, [r4] */
/* @0x140df0 cmp r2, #0 */
/* @0x140df4 mov r3, r0 */
/* @0x140df8 blt 0x140e44 <_Z22F_ActionPartEmitStreamR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x140dfc ldr r2, [pc, #0x60] */
/* @0x140e00 ldr r2, [pc, r2] */
/* @0x140e04 ldr r1, [r2, r6, lsl #2] */
/* @0x140e08 cmp r1, #0 */
/* @0x140e0c blt 0x140e2c <_Z22F_ActionPartEmitStreamR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x140e10 ldr r2, [pc, #0x50] */
/* @0x140e14 ldr r0, [r4] */
/* @0x140e18 ldr r2, [pc, r2] */
/* @0x140e1c ldr r2, [r2, r7, lsl #2] */
/* @0x140e20 add sp, sp, #12 */
/* @0x140e24 pop {r4, r5, r6, r7, lr} */
/* @0x140e28 b 0x1a3ad4 <_Z29ParticleSystem_Emitter_Streamiiii> */
/* @0x140e2c ldr r0, [pc, #0x38] */
/* @0x140e30 mov r1, #0 */
/* @0x140e34 add r0, pc, r0 */
/* @0x140e38 add sp, sp, #12 */
/* @0x140e3c pop {r4, r5, r6, r7, lr} */
/* @0x140e40 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x140e44 mvn r0, #0 */
/* @0x140e48 mov r1, #1 */
/* @0x140e4c str r3, [sp, #0x4] */
/* @0x140e50 bl 0x1a42dc <_Z21ParticleSystem_Createib> */
/* @0x140e54 ldr r3, [sp, #0x4] */
/* @0x140e58 str r0, [r4] */
/* @0x140e5c b 0x140dfc <_Z22F_ActionPartEmitStreamR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x140e60 .word 0x002ae5f4 */
/* @0x140e64 eoreq lr, r10, r4, ror #11 */
/* @0x140e68 eoreq lr, r10, r8, asr #11 */
/* @0x140e6c andseq pc, pc, r4, asr r11 */

/* ── FUNC 0x140e70 · F_ActionDrawSprite(RValue&, CInstance*, CInstance*, int, RValue*) · size=316 · insn=79 */
/* @0x140e70 push {r4, r5, r6, lr} */
/* @0x140e74 vpush {d8} */
/* @0x140e78 sub sp, sp, #24 */
/* @0x140e7c mov r6, r1 */
/* @0x140e80 mov r1, #0 */
/* @0x140e84 ldr r4, [sp, #0x30] */
/* @0x140e88 mov r0, r4 */
/* @0x140e8c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x140e90 mov r1, #1 */
/* @0x140e94 mov r5, r0 */
/* @0x140e98 mov r0, r4 */
/* @0x140e9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x140ea0 mov r1, #2 */
/* @0x140ea4 vmov s17, r0 */
/* @0x140ea8 mov r0, r4 */
/* @0x140eac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x140eb0 mov r1, #3 */
/* @0x140eb4 vmov s16, r0 */
/* @0x140eb8 mov r0, r4 */
/* @0x140ebc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x140ec0 mov r4, r0 */
/* @0x140ec4 mov r0, r5 */
/* @0x140ec8 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x140ecc subs r1, r0, #0 */
/* @0x140ed0 beq 0x140f8c <_Z18F_ActionDrawSpriteR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x140ed4 cmp r4, #0 */
/* @0x140ed8 vldrlt s15, [r6, #144] */
/* @0x140edc ldr r3, [pc, #0xc0] */
/* @0x140ee0 mov r0, r5 */
/* @0x140ee4 vcvtlt.s32.f32 s15, s15 */
/* @0x140ee8 ldr r3, [pc, r3] */
/* @0x140eec ldrb r3, [r3] */
/* @0x140ef0 vmovlt r4, s15 */
/* @0x140ef4 cmp r3, #0 */
/* @0x140ef8 bne 0x140f3c <_Z18F_ActionDrawSpriteR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x140efc bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x140f00 mov r12, #1065353216 */
/* @0x140f04 mov r1, r4 */
/* @0x140f08 mov r2, #0 */
/* @0x140f0c mvn r3, #-16777216 */
/* @0x140f10 str r2, [sp, #0x8] */
/* @0x140f14 str r3, [sp, #0xc] */
/* @0x140f18 vmov r2, s17 */
/* @0x140f1c vmov r3, s16 */
/* @0x140f20 str r12, [sp] */
/* @0x140f24 str r12, [sp, #0x4] */
/* @0x140f28 str r12, [sp, #0x10] */
/* @0x140f2c bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */
/* @0x140f30 add sp, sp, #24 */
/* @0x140f34 vpop {d8} */
/* @0x140f38 pop {r4, r5, r6, pc} */
/* @0x140f3c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x140f40 vldr s14, [r6, #180] */
/* @0x140f44 vldr s15, [r6, #184] */
/* @0x140f48 vadd.f32 s14, s17, s14 */
/* @0x140f4c mov r3, #1065353216 */
/* @0x140f50 mov r12, #0 */
/* @0x140f54 str r3, [sp] */
/* @0x140f58 mov r1, r4 */
/* @0x140f5c str r3, [sp, #0x4] */
/* @0x140f60 mvn r2, #-16777216 */
/* @0x140f64 str r3, [sp, #0x10] */
/* @0x140f68 str r2, [sp, #0xc] */
/* @0x140f6c str r12, [sp, #0x8] */
/* @0x140f70 vadd.f32 s15, s16, s15 */
/* @0x140f74 vmov r2, s14 */
/* @0x140f78 vmov r3, s15 */
/* @0x140f7c bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */
/* @0x140f80 add sp, sp, #24 */
/* @0x140f84 vpop {d8} */
/* @0x140f88 pop {r4, r5, r6, pc} */
/* @0x140f8c ldr r0, [pc, #0x14] */
/* @0x140f90 add r0, pc, r0 */
/* @0x140f94 add sp, sp, #24 */
/* @0x140f98 vpop {d8} */
/* @0x140f9c pop {r4, r5, r6, lr} */
/* @0x140fa0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x140fa4 eoreq r12, r10, r4, asr r12 */
/* @0x140fa8 andseq pc, pc, r4, lsr #20 */

/* ── FUNC 0x140fac · F_ActionDrawBackground(RValue&, CInstance*, CInstance*, int, RValue*) · size=412 · insn=103 */
/* @0x140fac push {r4, r5, r6, r7, lr} */
/* @0x140fb0 vpush {d8} */
/* @0x140fb4 sub sp, sp, #44 */
/* @0x140fb8 mov r7, r1 */
/* @0x140fbc mov r1, #0 */
/* @0x140fc0 ldr r4, [sp, #0x48] */
/* @0x140fc4 ldr r5, [pc, #0x16c] */
/* @0x140fc8 mov r0, r4 */
/* @0x140fcc add r5, pc, r5 */
/* @0x140fd0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x140fd4 mov r1, #1 */
/* @0x140fd8 mov r6, r0 */
/* @0x140fdc mov r0, r4 */
/* @0x140fe0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x140fe4 mov r1, #2 */
/* @0x140fe8 vmov s17, r0 */
/* @0x140fec mov r0, r4 */
/* @0x140ff0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x140ff4 mov r1, #3 */
/* @0x140ff8 vmov s16, r0 */
/* @0x140ffc mov r0, r4 */
/* @0x141000 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x141004 cmp r0, #0 */
/* @0x141008 mov r0, r6 */
/* @0x14100c movle r4, #0 */
/* @0x141010 movgt r4, #1 */
/* @0x141014 bl 0xc3640 <_Z17Background_Existsi> */
/* @0x141018 subs r1, r0, #0 */
/* @0x14101c beq 0x141120 <_Z22F_ActionDrawBackgroundR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x141020 ldr r3, [pc, #0x114] */
/* @0x141024 mov r0, r6 */
/* @0x141028 ldr r3, [r5, r3] */
/* @0x14102c ldrb r3, [r3] */
/* @0x141030 cmp r3, #0 */
/* @0x141034 bne 0x1410a4 <_Z22F_ActionDrawBackgroundR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x141038 bl 0xc3794 <_Z15Background_Datai> */
/* @0x14103c ldr lr, [pc, #0xfc] */
/* @0x141040 mov r12, #1065353216 */
/* @0x141044 mov r3, #0 */
/* @0x141048 mvn r6, #-16777216 */
/* @0x14104c vmov r1, s17 */
/* @0x141050 ldr lr, [r5, lr] */
/* @0x141054 str r3, [sp, #0xc] */
/* @0x141058 str r3, [sp, #0x10] */
/* @0x14105c mov r3, r12 */
/* @0x141060 str r4, [sp, #0x4] */
/* @0x141064 str r4, [sp, #0x8] */
/* @0x141068 ldr lr, [lr] */
/* @0x14106c str r12, [sp] */
/* @0x141070 vldr s14, [lr, #16] */
/* @0x141074 vcvt.f32.s32 s15, s14 */
/* @0x141078 vmov r2, s16 */
/* @0x14107c vstr s15, [sp, #20] */
/* @0x141080 vldr s15, [lr, #20] */
/* @0x141084 vcvt.f32.s32 s15, s15 */
/* @0x141088 str r12, [sp, #0x20] */
/* @0x14108c str r6, [sp, #0x1c] */
/* @0x141090 vstr s15, [sp, #24] */
/* @0x141094 bl 0xc22d8 <_ZN11CBackground9DrawTiledEffffbbffffjf> */
/* @0x141098 add sp, sp, #44 */
/* @0x14109c vpop {d8} */
/* @0x1410a0 pop {r4, r5, r6, r7, pc} */
/* @0x1410a4 bl 0xc3794 <_Z15Background_Datai> */
/* @0x1410a8 vldr s15, [r7, #180] */
/* @0x1410ac vadd.f32 s15, s17, s15 */
/* @0x1410b0 ldr r2, [pc, #0x88] */
/* @0x1410b4 vldr s14, [r7, #184] */
/* @0x1410b8 mov r12, #1065353216 */
/* @0x1410bc mov r3, #0 */
/* @0x1410c0 mvn lr, #-16777216 */
/* @0x1410c4 ldr r2, [r5, r2] */
/* @0x1410c8 str r3, [sp, #0xc] */
/* @0x1410cc str r3, [sp, #0x10] */
/* @0x1410d0 mov r3, r12 */
/* @0x1410d4 str r4, [sp, #0x4] */
/* @0x1410d8 str r4, [sp, #0x8] */
/* @0x1410dc ldr r2, [r2] */
/* @0x1410e0 str r12, [sp] */
/* @0x1410e4 vldr s13, [r2, #16] */
/* @0x1410e8 vmov r1, s15 */
/* @0x1410ec vcvt.f32.s32 s15, s13 */
/* @0x1410f0 vadd.f32 s14, s16, s14 */
/* @0x1410f4 vstr s15, [sp, #20] */
/* @0x1410f8 vldr s15, [r2, #20] */
/* @0x1410fc str r12, [sp, #0x20] */
/* @0x141100 str lr, [sp, #0x1c] */
/* @0x141104 vcvt.f32.s32 s15, s15 */
/* @0x141108 vmov r2, s14 */
/* @0x14110c vstr s15, [sp, #24] */
/* @0x141110 bl 0xc22d8 <_ZN11CBackground9DrawTiledEffffbbffffjf> */
/* @0x141114 add sp, sp, #44 */
/* @0x141118 vpop {d8} */
/* @0x14111c pop {r4, r5, r6, r7, pc} */
/* @0x141120 ldr r0, [pc, #0x1c] */
/* @0x141124 add r0, pc, r0 */
/* @0x141128 add sp, sp, #44 */
/* @0x14112c vpop {d8} */
/* @0x141130 pop {r4, r5, r6, r7, lr} */
/* @0x141134 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x141138 eoreq r0, r11, r4, lsl #25 */
/* @0x14113c .word 0xffffbeec */
/* @0x141140 .word 0xffffbcd8 */
/* @0x141144 ldrheq pc, [pc], -r8 */

/* ── FUNC 0x141148 · F_ActionReplaceSound(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x141148 push {r4, r5, r6, lr} */
/* @0x14114c mov r1, #0 */
/* @0x141150 ldr r4, [sp, #0x10] */
/* @0x141154 mov r0, r4 */
/* @0x141158 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14115c mov r1, #1 */
/* @0x141160 mov r5, r0 */
/* @0x141164 mov r0, r4 */
/* @0x141168 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x14116c mov r4, r0 */
/* @0x141170 mov r0, r5 */
/* @0x141174 bl 0x21fbd0 <_Z12Sound_Existsi> */
/* @0x141178 subs r1, r0, #0 */
/* @0x14117c beq 0x1411c4 <_Z20F_ActionReplaceSoundR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x141180 mov r0, r4 */
/* @0x141184 bl 0x214e48 <_Z10FileExistsPKc> */
/* @0x141188 subs r1, r0, #0 */
/* @0x14118c beq 0x1411b4 <_Z20F_ActionReplaceSoundR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x141190 mov r0, r5 */
/* @0x141194 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x141198 mov r1, r4 */
/* @0x14119c mov r3, r0 */
/* @0x1411a0 mov r0, r5 */
/* @0x1411a4 ldr r2, [r3, #0x4] */
/* @0x1411a8 pop {r4, r5, r6, lr} */
/* @0x1411ac ldrb r3, [r3, #0x14] */
/* @0x1411b0 b 0x220018 <_Z13Sound_ReplaceiPKcib> */
/* @0x1411b4 ldr r0, [pc, #0x18] */
/* @0x1411b8 pop {r4, r5, r6, lr} */
/* @0x1411bc add r0, pc, r0 */
/* @0x1411c0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1411c4 ldr r0, [pc, #0xc] */
/* @0x1411c8 pop {r4, r5, r6, lr} */
/* @0x1411cc add r0, pc, r0 */
/* @0x1411d0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1411d4 ldrheq pc, [pc], -r4 */
/* @0x1411d8 andseq pc, pc, r8, ror r7 */

/* ── FUNC 0x1411dc · F_ActionReplaceSprite(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x1411dc push {r4, r5, r6, lr} */
/* @0x1411e0 sub sp, sp, #24 */
/* @0x1411e4 mov r1, #0 */
/* @0x1411e8 ldr r4, [sp, #0x28] */
/* @0x1411ec mov r0, r4 */
/* @0x1411f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1411f4 mov r1, #1 */
/* @0x1411f8 mov r5, r0 */
/* @0x1411fc mov r0, r4 */
/* @0x141200 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x141204 mov r1, #2 */
/* @0x141208 mov r6, r0 */
/* @0x14120c mov r0, r4 */
/* @0x141210 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x141214 mov r4, r0 */
/* @0x141218 mov r0, r5 */
/* @0x14121c bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x141220 subs r1, r0, #0 */
/* @0x141224 beq 0x14129c <_Z21F_ActionReplaceSpriteR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x141228 mov r0, r6 */
/* @0x14122c bl 0x214e48 <_Z10FileExistsPKc> */
/* @0x141230 subs r1, r0, #0 */
/* @0x141234 beq 0x141288 <_Z21F_ActionReplaceSpriteR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x141238 mov r0, r5 */
/* @0x14123c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x141240 mov r1, r6 */
/* @0x141244 mov r2, r4 */
/* @0x141248 ldrb lr, [r0, #0x32] */
/* @0x14124c mov r12, r0 */
/* @0x141250 ldrb r3, [r12, #0x30] */
/* @0x141254 mov r0, r5 */
/* @0x141258 str lr, [sp] */
/* @0x14125c ldrb lr, [r12, #0x33] */
/* @0x141260 str lr, [sp, #0x4] */
/* @0x141264 ldrb lr, [r12, #0x34] */
/* @0x141268 str lr, [sp, #0x8] */
/* @0x14126c ldr lr, [r12, #0x24] */
/* @0x141270 str lr, [sp, #0xc] */
/* @0x141274 ldr r12, [r12, #0x28] */
/* @0x141278 str r12, [sp, #0x10] */
/* @0x14127c bl 0x1ef5a8 <_Z14Sprite_ReplaceiPKcibbbbii> */
/* @0x141280 add sp, sp, #24 */
/* @0x141284 pop {r4, r5, r6, pc} */
/* @0x141288 ldr r0, [pc, #0x20] */
/* @0x14128c add r0, pc, r0 */
/* @0x141290 add sp, sp, #24 */
/* @0x141294 pop {r4, r5, r6, lr} */
/* @0x141298 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14129c ldr r0, [pc, #0x10] */
/* @0x1412a0 add r0, pc, r0 */
/* @0x1412a4 add sp, sp, #24 */
/* @0x1412a8 pop {r4, r5, r6, lr} */
/* @0x1412ac b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1412b0 andseq pc, pc, r4, ror #13 */
/* @0x1412b4 andseq pc, pc, r4, lsr #13 */

/* ── FUNC 0x1412b8 · F_ActionInherited(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x1412b8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1412bc mov r7, r1 */
/* @0x1412c0 ldr r4, [pc, #0xb8] */
/* @0x1412c4 mov r6, r2 */
/* @0x1412c8 ldr r3, [pc, #0xb4] */
/* @0x1412cc add r4, pc, r4 */
/* @0x1412d0 ldr r5, [r4, r3] */
/* @0x1412d4 ldr r0, [r5] */
/* @0x1412d8 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x1412dc cmp r0, #0 */
/* @0x1412e0 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1412e4 ldr r3, [pc, #0x9c] */
/* @0x1412e8 ldr lr, [r5] */
/* @0x1412ec ldr r3, [r4, r3] */
/* @0x1412f0 ldr r3, [r3] */
/* @0x1412f4 ldr r2, [r3, #0x4] */
/* @0x1412f8 ldr r3, [r3] */
/* @0x1412fc and r2, lr, r2 */
/* @0x141300 ldr r3, [r3, r2, lsl #3] */
/* @0x141304 cmp r3, #0 */
/* @0x141308 beq 0x141334 <_Z17F_ActionInheritedR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x14130c ldr r2, [r3, #0x8] */
/* @0x141310 cmp lr, r2 */
/* @0x141314 bne 0x141328 <_Z17F_ActionInheritedR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x141318 b 0x141378 <_Z17F_ActionInheritedR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x14131c ldr r12, [r3, #0x8] */
/* @0x141320 cmp lr, r12 */
/* @0x141324 beq 0x141378 <_Z17F_ActionInheritedR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x141328 ldr r3, [r3, #0x4] */
/* @0x14132c cmp r3, #0 */
/* @0x141330 bne 0x14131c <_Z17F_ActionInheritedR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x141334 ldr r5, [r3, #0xc] */
/* @0x141338 mov r0, r5 */
/* @0x14133c bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x141340 cmp r0, #0 */
/* @0x141344 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x141348 ldr r12, [pc, #0x3c] */
/* @0x14134c mov r0, r7 */
/* @0x141350 ldr r3, [pc, #0x38] */
/* @0x141354 mov r1, r6 */
/* @0x141358 mov r2, r5 */
/* @0x14135c ldr r12, [r4, r12] */
/* @0x141360 ldr r3, [r4, r3] */
/* @0x141364 ldr r12, [r12] */
/* @0x141368 ldr r3, [r3] */
/* @0x14136c str r12, [sp, #0x18] */
/* @0x141370 pop {r4, r5, r6, r7, r8, lr} */
/* @0x141374 b 0xf32e4 <_Z20Perform_Event_ObjectP9CInstanceS0_iii> */
/* @0x141378 ldr r3, [r3, #0xc] */
/* @0x14137c b 0x141334 <_Z17F_ActionInheritedR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x141380 eoreq r0, r11, r4, lsl #19 */
/* @0x141384 .word 0xffffc168 */
/* @0x141388 .word 0xffffbfec */
/* @0x14138c .word 0xffffc164 */
/* @0x141390 .word 0xffffc160 */

/* ── FUNC 0x141394 · YYGML_action_move(CInstance*, char const*, float) · size=420 · insn=105 */
/* @0x141394 push {r4, r5, r6, lr} */
/* @0x141398 subs r4, r1, #0 */
/* @0x14139c mov r5, r0 */
/* @0x1413a0 mov r6, r2 */
/* @0x1413a4 beq 0x1413b8 <_Z17YYGML_action_moveP9CInstancePKcf+0x24> */
/* @0x1413a8 mov r0, r4 */
/* @0x1413ac bl 0xb6538 <strlen@plt> */
/* @0x1413b0 cmp r0, #9 */
/* @0x1413b4 beq 0x1413cc <_Z17YYGML_action_moveP9CInstancePKcf+0x38> */
/* @0x1413b8 ldr r0, [pc, #0x170] */
/* @0x1413bc mov r1, #0 */
/* @0x1413c0 pop {r4, r5, r6, lr} */
/* @0x1413c4 add r0, pc, r0 */
/* @0x1413c8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1413cc mov r3, #0 */
/* @0x1413d0 mov r12, r3 */
/* @0x1413d4 cmp r12, #0 */
/* @0x1413d8 bne 0x1413ec <_Z17YYGML_action_moveP9CInstancePKcf+0x58> */
/* @0x1413dc ldrb r12, [r4, r3] */
/* @0x1413e0 subs r2, r12, #49 */
/* @0x1413e4 rsbs r12, r2, #0 */
/* @0x1413e8 adcs r12, r12, r2 */
/* @0x1413ec add r3, r3, #1 */
/* @0x1413f0 cmp r3, #9 */
/* @0x1413f4 bne 0x1413d4 <_Z17YYGML_action_moveP9CInstancePKcf+0x40> */
/* @0x1413f8 cmp r12, #0 */
/* @0x1413fc popeq {r4, r5, r6, pc} */
/* @0x141400 ldr r3, [pc, #0x12c] */
/* @0x141404 ldr r3, [pc, r3] */
/* @0x141408 ldrb r3, [r3] */
/* @0x14140c cmp r3, #0 */
/* @0x141410 vldrne s15, [r5, #208] */
/* @0x141414 vmovne s14, r6 */
/* @0x141418 movne r0, r5 */
/* @0x14141c moveq r1, r6 */
/* @0x141420 moveq r0, r5 */
/* @0x141424 vaddne.f32 s14, s14, s15 */
/* @0x141428 vmovne r1, s14 */
/* @0x14142c bl 0x1930d4 <_ZN9CInstance8SetSpeedEf> */
/* @0x141430 mov r0, #9 */
/* @0x141434 bl 0xc4600 <_Z8YYRandomi> */
/* @0x141438 ldrb r3, [r4, r0] */
/* @0x14143c cmp r3, #49 */
/* @0x141440 bne 0x141430 <_Z17YYGML_action_moveP9CInstancePKcf+0x9c> */
/* @0x141444 cmp r0, #8 */
/* @0x141448 addls pc, pc, r0, lsl #2 */
/* @0x14144c b 0x141474 <_Z17YYGML_action_moveP9CInstancePKcf+0xe0> */
/* @0x141450 b 0x14148c <_Z17YYGML_action_moveP9CInstancePKcf+0xf8> */
/* @0x141454 b 0x1414a0 <_Z17YYGML_action_moveP9CInstancePKcf+0x10c> */
/* @0x141458 b 0x1414b4 <_Z17YYGML_action_moveP9CInstancePKcf+0x120> */
/* @0x14145c b 0x1414c8 <_Z17YYGML_action_moveP9CInstancePKcf+0x134> */
/* @0x141460 b 0x1414dc <_Z17YYGML_action_moveP9CInstancePKcf+0x148> */
/* @0x141464 b 0x1414f8 <_Z17YYGML_action_moveP9CInstancePKcf+0x164> */
/* @0x141468 b 0x141508 <_Z17YYGML_action_moveP9CInstancePKcf+0x174> */
/* @0x14146c b 0x14151c <_Z17YYGML_action_moveP9CInstancePKcf+0x188> */
/* @0x141470 b 0x141478 <_Z17YYGML_action_moveP9CInstancePKcf+0xe4> */
/* @0x141474 pop {r4, r5, r6, pc} */
/* @0x141478 mov r0, r5 */
/* @0x14147c mov r1, #0 */
/* @0x141480 pop {r4, r5, r6, lr} */
/* @0x141484 movt r1, #0x4234 */
/* @0x141488 b 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x14148c mov r0, r5 */
/* @0x141490 mov r1, #0 */
/* @0x141494 pop {r4, r5, r6, lr} */
/* @0x141498 movt r1, #0x4361 */
/* @0x14149c b 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x1414a0 mov r0, r5 */
/* @0x1414a4 mov r1, #0 */
/* @0x1414a8 pop {r4, r5, r6, lr} */
/* @0x1414ac movt r1, #0x4387 */
/* @0x1414b0 b 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x1414b4 mov r0, r5 */
/* @0x1414b8 mov r1, #32768 */
/* @0x1414bc pop {r4, r5, r6, lr} */
/* @0x1414c0 movt r1, #0x439d */
/* @0x1414c4 b 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x1414c8 mov r0, r5 */
/* @0x1414cc mov r1, #0 */
/* @0x1414d0 pop {r4, r5, r6, lr} */
/* @0x1414d4 movt r1, #0x4334 */
/* @0x1414d8 b 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x1414dc mov r0, r5 */
/* @0x1414e0 mov r1, #0 */
/* @0x1414e4 bl 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x1414e8 mov r0, r5 */
/* @0x1414ec mov r1, #0 */
/* @0x1414f0 pop {r4, r5, r6, lr} */
/* @0x1414f4 b 0x1930d4 <_ZN9CInstance8SetSpeedEf> */
/* @0x1414f8 mov r0, r5 */
/* @0x1414fc mov r1, #0 */
/* @0x141500 pop {r4, r5, r6, lr} */
/* @0x141504 b 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x141508 mov r0, r5 */
/* @0x14150c mov r1, #0 */
/* @0x141510 pop {r4, r5, r6, lr} */
/* @0x141514 movt r1, #0x4307 */
/* @0x141518 b 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x14151c mov r0, r5 */
/* @0x141520 mov r1, #0 */
/* @0x141524 pop {r4, r5, r6, lr} */
/* @0x141528 movt r1, #0x42b4 */
/* @0x14152c b 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x141530 andseq pc, pc, r4, asr #12 */
/* @0x141534 eoreq r12, r10, r8, lsr r7 */

/* ── FUNC 0x141538 · F_ActionMove(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x141538 push {r4, r5, r6, lr} */
/* @0x14153c mov r6, r1 */
/* @0x141540 ldr r4, [sp, #0x10] */
/* @0x141544 mov r1, #0 */
/* @0x141548 mov r0, r4 */
/* @0x14154c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x141550 mov r1, #1 */
/* @0x141554 mov r5, r0 */
/* @0x141558 mov r0, r4 */
/* @0x14155c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x141560 mov r1, r5 */
/* @0x141564 mov r2, r0 */
/* @0x141568 mov r0, r6 */
/* @0x14156c pop {r4, r5, r6, lr} */
/* @0x141570 b 0x141394 <_Z17YYGML_action_moveP9CInstancePKcf> */

/* ── FUNC 0x141574 · YYGML_action_set_gravity(CInstance*, float, float) · size=56 · insn=14 */
/* @0x141574 ldr r3, [pc, #0x2c] */
/* @0x141578 vmov s14, r1 */
/* @0x14157c vmov s15, r2 */
/* @0x141580 ldr r3, [pc, r3] */
/* @0x141584 ldrb r3, [r3] */
/* @0x141588 cmp r3, #0 */
/* @0x14158c vldrne s12, [r0, #216] */
/* @0x141590 vldrne s13, [r0, #220] */
/* @0x141594 vaddne.f32 s14, s12, s14 */
/* @0x141598 vaddne.f32 s15, s13, s15 */
/* @0x14159c vstr s14, [r0, #216] */
/* @0x1415a0 vstr s15, [r0, #220] */
/* @0x1415a4 bx lr */
/* @0x1415a8 .word 0x002ac5bc */
