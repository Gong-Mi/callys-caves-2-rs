/* libyoyo.so 覆盖卡组 0055
 * 函数 0x126298..0x1270d8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x126298 · F_ShowVideo(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x126298 push {r3, r4, r5, lr} */
/* @0x12629c mov r1, #1 */
/* @0x1262a0 ldr r4, [sp, #0x10] */
/* @0x1262a4 mov r0, r4 */
/* @0x1262a8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1262ac ldr r2, [pc, #0x5c] */
/* @0x1262b0 ldr r3, [pc, #0x5c] */
/* @0x1262b4 mov r1, #0 */
/* @0x1262b8 ldr r2, [pc, r2] */
/* @0x1262bc ldr r3, [pc, r3] */
/* @0x1262c0 mov r12, r0 */
/* @0x1262c4 mov r0, r4 */
/* @0x1262c8 eor lr, r12, #1 */
/* @0x1262cc strb r12, [r2] */
/* @0x1262d0 strb lr, [r3] */
/* @0x1262d4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1262d8 mov r1, #2 */
/* @0x1262dc mov r5, r0 */
/* @0x1262e0 mov r0, r4 */
/* @0x1262e4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1262e8 mov r1, r0 */
/* @0x1262ec mov r0, r5 */
/* @0x1262f0 bl 0x1dc774 <_Z17Splash_Show_MoviePKcb> */
/* @0x1262f4 subs r1, r0, #0 */
/* @0x1262f8 bne 0x126308 <_Z11F_ShowVideoR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x1262fc ldr r0, [pc, #0x14] */
/* @0x126300 add r0, pc, r0 */
/* @0x126304 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x126308 pop {r3, r4, r5, lr} */
/* @0x12630c b 0x18c2c8 <_Z8IO_Clearv> */
/* @0x126310 eoreq r8, r12, r12, ror r7 */
/* @0x126314 eoreq r8, r12, r8, lsl #15 */
/* @0x126318 .word 0x00215dfc */

/* ── FUNC 0x12631c · F_ShowInfo(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x12631c push {r3, lr} */
/* @0x126320 ldr r3, [pc, #0x20] */
/* @0x126324 ldr r1, [pc, #0x20] */
/* @0x126328 ldr r3, [pc, r3] */
/* @0x12632c add r1, pc, r1 */
/* @0x126330 ldr r0, [r3] */
/* @0x126334 ldr r3, [r0] */
/* @0x126338 ldr r3, [r3, #0xc] */
/* @0x12633c blx r3 */
/* @0x126340 pop {r3, lr} */
/* @0x126344 b 0x18c2c8 <_Z8IO_Clearv> */
/* @0x126348 eoreq r7, r12, r12, ror #7 */
/* @0x12634c .word 0x00215dfc */

/* ── FUNC 0x126350 · F_ShowMessageExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x126350 ldr r3, [pc, #0x40] */
/* @0x126354 push {r4, lr} */
/* @0x126358 ldr r3, [pc, r3] */
/* @0x12635c mov r4, r0 */
/* @0x126360 ldr r1, [pc, #0x34] */
/* @0x126364 ldr r0, [r3] */
/* @0x126368 add r1, pc, r1 */
/* @0x12636c ldr r3, [r0] */
/* @0x126370 ldr r3, [r3, #0xc] */
/* @0x126374 blx r3 */
/* @0x126378 mov r2, #0 */
/* @0x12637c mov r3, r2 */
/* @0x126380 movt r2, #0x3ff0 */
/* @0x126384 str r3, [r4, #0xc] */
/* @0x126388 str r2, [r4, #0x4] */
/* @0x12638c str r3, [r4] */
/* @0x126390 pop {r4, lr} */
/* @0x126394 b 0x18c2c8 <_Z8IO_Clearv> */
/* @0x126398 .word 0x002c73bc */
/* @0x12639c eoreq r5, r1, r0, ror #27 */

/* ── FUNC 0x1263a0 · F_ShowMenu(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x1263a0 ldr r3, [pc, #0x38] */
/* @0x1263a4 push {r4, lr} */
/* @0x1263a8 ldr r3, [pc, r3] */
/* @0x1263ac mov r4, r0 */
/* @0x1263b0 ldr r1, [pc, #0x2c] */
/* @0x1263b4 ldr r0, [r3] */
/* @0x1263b8 add r1, pc, r1 */
/* @0x1263bc ldr r3, [r0] */
/* @0x1263c0 ldr r3, [r3, #0xc] */
/* @0x1263c4 blx r3 */
/* @0x1263c8 mov r3, #0 */
/* @0x1263cc str r3, [r4, #0xc] */
/* @0x1263d0 str r3, [r4] */
/* @0x1263d4 str r3, [r4, #0x4] */
/* @0x1263d8 pop {r4, lr} */
/* @0x1263dc b 0x18c2c8 <_Z8IO_Clearv> */
/* @0x1263e0 eoreq r7, r12, r12, ror #6 */
/* @0x1263e4 eoreq r5, r1, r8, asr #27 */

/* ── FUNC 0x1263e8 · F_ShowMenuPos(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x1263e8 ldr r3, [pc, #0x38] */
/* @0x1263ec push {r4, lr} */
/* @0x1263f0 ldr r3, [pc, r3] */
/* @0x1263f4 mov r4, r0 */
/* @0x1263f8 ldr r1, [pc, #0x2c] */
/* @0x1263fc ldr r0, [r3] */
/* @0x126400 add r1, pc, r1 */
/* @0x126404 ldr r3, [r0] */
/* @0x126408 ldr r3, [r3, #0xc] */
/* @0x12640c blx r3 */
/* @0x126410 mov r3, #0 */
/* @0x126414 str r3, [r4, #0xc] */
/* @0x126418 str r3, [r4] */
/* @0x12641c str r3, [r4, #0x4] */
/* @0x126420 pop {r4, lr} */
/* @0x126424 b 0x18c2c8 <_Z8IO_Clearv> */
/* @0x126428 eoreq r7, r12, r4, lsr #6 */
/* @0x12642c eoreq r5, r1, r12, lsr #27 */

/* ── FUNC 0x126430 · F_GetColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x126430 ldr r3, [pc, #0x38] */
/* @0x126434 push {r4, lr} */
/* @0x126438 ldr r3, [pc, r3] */
/* @0x12643c mov r4, r0 */
/* @0x126440 ldr r1, [pc, #0x2c] */
/* @0x126444 ldr r0, [r3] */
/* @0x126448 add r1, pc, r1 */
/* @0x12644c ldr r3, [r0] */
/* @0x126450 ldr r3, [r3, #0xc] */
/* @0x126454 blx r3 */
/* @0x126458 mov r3, #0 */
/* @0x12645c str r3, [r4, #0xc] */
/* @0x126460 str r3, [r4] */
/* @0x126464 str r3, [r4, #0x4] */
/* @0x126468 pop {r4, lr} */
/* @0x12646c b 0x18c2c8 <_Z8IO_Clearv> */
/* @0x126470 .word 0x002c72dc */
/* @0x126474 mlaeq r1, r8, sp, r5 */

/* ── FUNC 0x126478 · F_SplashShowImage(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x126478 push {r3, r4, r5, lr} */
/* @0x12647c mov r1, #0 */
/* @0x126480 ldr r4, [sp, #0x10] */
/* @0x126484 mov r0, r4 */
/* @0x126488 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12648c mov r1, #1 */
/* @0x126490 mov r5, r0 */
/* @0x126494 mov r0, r4 */
/* @0x126498 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12649c mov r1, r0 */
/* @0x1264a0 mov r0, r5 */
/* @0x1264a4 bl 0x1dc77c <_Z17Splash_Show_ImagePKci> */
/* @0x1264a8 subs r1, r0, #0 */
/* @0x1264ac bne 0x1264bc <_Z17F_SplashShowImageR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1264b0 ldr r0, [pc, #0xc] */
/* @0x1264b4 add r0, pc, r0 */
/* @0x1264b8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1264bc pop {r3, r4, r5, lr} */
/* @0x1264c0 b 0x18c2c8 <_Z8IO_Clearv> */
/* @0x1264c4 eoreq r5, r1, r0, asr sp */

/* ── FUNC 0x1264c8 · F_ShowImage(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x1264c8 push {r3, r4, r5, lr} */
/* @0x1264cc mov r1, #1 */
/* @0x1264d0 ldr r4, [sp, #0x10] */
/* @0x1264d4 mov r0, r4 */
/* @0x1264d8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1264dc ldr r2, [pc, #0x5c] */
/* @0x1264e0 ldr r3, [pc, #0x5c] */
/* @0x1264e4 mov r1, #0 */
/* @0x1264e8 ldr r2, [pc, r2] */
/* @0x1264ec ldr r3, [pc, r3] */
/* @0x1264f0 mov r12, r0 */
/* @0x1264f4 mov r0, r4 */
/* @0x1264f8 eor lr, r12, #1 */
/* @0x1264fc strb r12, [r2] */
/* @0x126500 strb lr, [r3] */
/* @0x126504 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x126508 mov r1, #2 */
/* @0x12650c mov r5, r0 */
/* @0x126510 mov r0, r4 */
/* @0x126514 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x126518 mov r1, r0 */
/* @0x12651c mov r0, r5 */
/* @0x126520 bl 0x1dc77c <_Z17Splash_Show_ImagePKci> */
/* @0x126524 subs r1, r0, #0 */
/* @0x126528 bne 0x126538 <_Z11F_ShowImageR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x12652c ldr r0, [pc, #0x14] */
/* @0x126530 add r0, pc, r0 */
/* @0x126534 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x126538 pop {r3, r4, r5, lr} */
/* @0x12653c b 0x18c2c8 <_Z8IO_Clearv> */
/* @0x126540 eoreq r8, r12, r12, asr #10 */
/* @0x126544 eoreq r8, r12, r8, asr r5 */
/* @0x126548 .word 0x00215cd4 */

/* ── FUNC 0x12654c · F_SplashShowText(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x12654c push {r3, r4, r5, lr} */
/* @0x126550 mov r1, #0 */
/* @0x126554 ldr r4, [sp, #0x10] */
/* @0x126558 mov r0, r4 */
/* @0x12655c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x126560 mov r1, #1 */
/* @0x126564 mov r5, r0 */
/* @0x126568 mov r0, r4 */
/* @0x12656c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x126570 mov r1, r0 */
/* @0x126574 mov r0, r5 */
/* @0x126578 bl 0x1dc784 <_Z16Splash_Show_TextPKci> */
/* @0x12657c subs r1, r0, #0 */
/* @0x126580 bne 0x126590 <_Z16F_SplashShowTextR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x126584 ldr r0, [pc, #0xc] */
/* @0x126588 add r0, pc, r0 */
/* @0x12658c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x126590 pop {r3, r4, r5, lr} */
/* @0x126594 b 0x18c2c8 <_Z8IO_Clearv> */
/* @0x126598 mlaeq r1, r4, r12, r5 */

/* ── FUNC 0x12659c · F_ShowText(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x12659c push {r3, r4, r5, lr} */
/* @0x1265a0 mov r1, #1 */
/* @0x1265a4 ldr r4, [sp, #0x10] */
/* @0x1265a8 mov r0, r4 */
/* @0x1265ac bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1265b0 ldr r2, [pc, #0x74] */
/* @0x1265b4 ldr r3, [pc, #0x74] */
/* @0x1265b8 mov r1, #2 */
/* @0x1265bc ldr r2, [pc, r2] */
/* @0x1265c0 ldr r3, [pc, r3] */
/* @0x1265c4 mov r12, r0 */
/* @0x1265c8 mov r0, r4 */
/* @0x1265cc eor lr, r12, #1 */
/* @0x1265d0 strb r12, [r2] */
/* @0x1265d4 strb lr, [r3] */
/* @0x1265d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1265dc ldr r3, [pc, #0x50] */
/* @0x1265e0 mov r1, #0 */
/* @0x1265e4 ldr r3, [pc, r3] */
/* @0x1265e8 str r0, [r3] */
/* @0x1265ec mov r0, r4 */
/* @0x1265f0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1265f4 mov r1, #3 */
/* @0x1265f8 mov r5, r0 */
/* @0x1265fc mov r0, r4 */
/* @0x126600 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x126604 mov r1, r0 */
/* @0x126608 mov r0, r5 */
/* @0x12660c bl 0x1dc784 <_Z16Splash_Show_TextPKci> */
/* @0x126610 subs r1, r0, #0 */
/* @0x126614 bne 0x126624 <_Z10F_ShowTextR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x126618 ldr r0, [pc, #0x18] */
/* @0x12661c add r0, pc, r0 */
/* @0x126620 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x126624 pop {r3, r4, r5, lr} */
/* @0x126628 b 0x18c2c8 <_Z8IO_Clearv> */
/* @0x12662c eoreq r8, r12, r8, ror r4 */
/* @0x126630 eoreq r8, r12, r4, lsl #9 */
/* @0x126634 eoreq r8, r12, r4, lsl #9 */
/* @0x126638 eoreq r5, r1, r0, lsl #24 */

/* ── FUNC 0x12663c · F_GetLoginAsync(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x12663c push {r4, r5, r6, lr} */
/* @0x126640 mov r1, #0 */
/* @0x126644 ldr r5, [sp, #0x10] */
/* @0x126648 mov r4, r0 */
/* @0x12664c mov r0, r5 */
/* @0x126650 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x126654 mov r1, #1 */
/* @0x126658 mov r6, r0 */
/* @0x12665c mov r0, r5 */
/* @0x126660 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x126664 mov r1, r0 */
/* @0x126668 mov r0, r6 */
/* @0x12666c bl 0xf272c <_ZN10InputQuery10LoginASyncEPKcS1_> */
/* @0x126670 mov r3, #0 */
/* @0x126674 str r3, [r4, #0xc] */
/* @0x126678 vmov s15, r0 */
/* @0x12667c vcvt.f64.s32 d7, s15 */
/* @0x126680 vmov r0, r1, d7 */
/* @0x126684 vmov r2, s14 */
/* @0x126688 mov r3, r1 */
/* @0x12668c stm r4, {r2, r3} */
/* @0x126690 pop {r4, r5, r6, pc} */

/* ── FUNC 0x126694 · F_ShowQuestion(RValue&, CInstance*, CInstance*, int, RValue*) · size=304 · insn=76 */
/* @0x126694 ldr r1, [pc, #0x110] */
/* @0x126698 mov r12, #16 */
/* @0x12669c push {r4, r5, lr} */
/* @0x1266a0 sub sp, sp, #28 */
/* @0x1266a4 add r1, pc, r1 */
/* @0x1266a8 movw r2, #0x232 */
/* @0x1266ac mov r3, #1 */
/* @0x1266b0 mov r5, r0 */
/* @0x1266b4 mov r0, r12 */
/* @0x1266b8 str r12, [sp, #0xc] */
/* @0x1266bc ldr r4, [sp, #0x28] */
/* @0x1266c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1266c4 mov r1, #0 */
/* @0x1266c8 mov r3, r4 */
/* @0x1266cc ldr r4, [pc, #0xdc] */
/* @0x1266d0 add r4, pc, r4 */
/* @0x1266d4 mov r2, r0 */
/* @0x1266d8 add r0, sp, #24 */
/* @0x1266dc str r2, [sp, #0x10] */
/* @0x1266e0 str r2, [r0, #-0x4]! */
/* @0x1266e4 strb r1, [r2] */
/* @0x1266e8 add r1, sp, #16 */
/* @0x1266ec add r2, sp, #12 */
/* @0x1266f0 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x1266f4 ldr r0, [sp, #0x10] */
/* @0x1266f8 bl 0x212da8 <_Z19String_Replace_HashPc> */
/* @0x1266fc bl 0x29cb74 <_Z19DebuggerIsConnectedv> */
/* @0x126700 cmp r0, #0 */
/* @0x126704 beq 0x126780 <_Z14F_ShowQuestionR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x126708 ldr r3, [pc, #0xa4] */
/* @0x12670c ldr r3, [r4, r3] */
/* @0x126710 ldrb r3, [r3] */
/* @0x126714 cmp r3, #0 */
/* @0x126718 beq 0x126730 <_Z14F_ShowQuestionR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x12671c ldr r3, [pc, #0x94] */
/* @0x126720 ldr r3, [r4, r3] */
/* @0x126724 ldr r3, [r3] */
/* @0x126728 cmp r3, #0 */
/* @0x12672c beq 0x126798 <_Z14F_ShowQuestionR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x126730 bl 0x29cb88 <_Z32DebuggerRunBackgroundMessageLoopv> */
/* @0x126734 ldr r3, [pc, #0x80] */
/* @0x126738 ldr r1, [sp, #0x10] */
/* @0x12673c ldr r3, [r4, r3] */
/* @0x126740 ldr r0, [r3] */
/* @0x126744 bl 0xf29a4 <_ZN10InputQuery8QuestionEPKcS1_> */
/* @0x126748 str r0, [sp, #0x4] */
/* @0x12674c bl 0x29cc30 <_Z33DebuggerStopBackgroundMessageLoopv> */
/* @0x126750 ldr r0, [sp, #0x4] */
/* @0x126754 vmov s15, r0 */
/* @0x126758 mov r1, #0 */
/* @0x12675c str r1, [r5, #0xc] */
/* @0x126760 vcvt.f64.s32 d7, s15 */
/* @0x126764 vmov r2, r3, d7 */
/* @0x126768 stm r5, {r2, r3} */
/* @0x12676c bl 0x18c2c8 <_Z8IO_Clearv> */
/* @0x126770 ldr r0, [sp, #0x10] */
/* @0x126774 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x126778 add sp, sp, #28 */
/* @0x12677c pop {r4, r5, pc} */
/* @0x126780 ldr r3, [pc, #0x34] */
/* @0x126784 ldr r1, [sp, #0x10] */
/* @0x126788 ldr r3, [r4, r3] */
/* @0x12678c ldr r0, [r3] */
/* @0x126790 bl 0xf29a4 <_ZN10InputQuery8QuestionEPKcS1_> */
/* @0x126794 b 0x126754 <_Z14F_ShowQuestionR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x126798 ldr r1, [pc, #0x20] */
/* @0x12679c mov r0, #1 */
/* @0x1267a0 add r1, pc, r1 */
/* @0x1267a4 bl 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz> */
/* @0x1267a8 b 0x126730 <_Z14F_ShowQuestionR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x1267ac mlaeq r1, r0, r11, r5 */
/* @0x1267b0 eoreq r11, r12, r0, lsl #11 */
/* @0x1267b4 .word 0xffffbcd4 */
/* @0x1267b8 .word 0xffffc7d0 */
/* @0x1267bc .word 0xffffce30 */
/* @0x1267c0 .word 0x00215ad8 */

/* ── FUNC 0x1267c4 · F_ShowQuestionASync(RValue&, CInstance*, CInstance*, int, RValue*) · size=172 · insn=43 */
/* @0x1267c4 ldr r1, [pc, #0x9c] */
/* @0x1267c8 mov r12, #16 */
/* @0x1267cc push {r4, r5, lr} */
/* @0x1267d0 sub sp, sp, #20 */
/* @0x1267d4 mov r4, r0 */
/* @0x1267d8 add r1, pc, r1 */
/* @0x1267dc mov r0, r12 */
/* @0x1267e0 mov r2, #604 */
/* @0x1267e4 mov r3, #1 */
/* @0x1267e8 str r12, [sp, #0x4] */
/* @0x1267ec ldr r5, [sp, #0x20] */
/* @0x1267f0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1267f4 add r1, sp, #8 */
/* @0x1267f8 mov r3, r5 */
/* @0x1267fc mov r5, #0 */
/* @0x126800 mov r2, r0 */
/* @0x126804 add r0, sp, #16 */
/* @0x126808 str r2, [sp, #0x8] */
/* @0x12680c str r2, [r0, #-0x4]! */
/* @0x126810 strb r5, [r2] */
/* @0x126814 add r2, sp, #4 */
/* @0x126818 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x12681c ldr r0, [sp, #0x8] */
/* @0x126820 bl 0x212da8 <_Z19String_Replace_HashPc> */
/* @0x126824 ldr r3, [pc, #0x40] */
/* @0x126828 ldr r1, [sp, #0x8] */
/* @0x12682c ldr r3, [pc, r3] */
/* @0x126830 str r5, [r4, #0xc] */
/* @0x126834 ldr r0, [r3] */
/* @0x126838 bl 0xf26ec <_ZN10InputQuery13QuestionAsyncEPKcS1_> */
/* @0x12683c vmov s15, r0 */
/* @0x126840 vcvt.f64.s32 d7, s15 */
/* @0x126844 vmov r0, r1, d7 */
/* @0x126848 vmov r2, s14 */
/* @0x12684c mov r3, r1 */
/* @0x126850 stm r4, {r2, r3} */
/* @0x126854 bl 0x18c2c8 <_Z8IO_Clearv> */
/* @0x126858 ldr r0, [sp, #0x8] */
/* @0x12685c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x126860 add sp, sp, #20 */
/* @0x126864 pop {r4, r5, pc} */
/* @0x126868 eoreq r5, r1, r12, asr r10 */
/* @0x12686c eoreq r8, r12, r4, asr r2 */

/* ── FUNC 0x126870 · F_HighscoreShow(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x126870 push {r3, lr} */
/* @0x126874 mov r1, #0 */
/* @0x126878 ldr r0, [sp, #0x8] */
/* @0x12687c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x126880 bl 0x1dc2d4 <_Z14HighScore_Showi> */
/* @0x126884 pop {r3, lr} */
/* @0x126888 b 0x18c2c8 <_Z8IO_Clearv> */

/* ── FUNC 0x12688c · F_HighscoreClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x12688c b 0x1dc2d8 <_Z15HighScore_Clearv> */

/* ── FUNC 0x126890 · F_HighscoreAdd(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x126890 push {r3, r4, r5, lr} */
/* @0x126894 mov r1, #0 */
/* @0x126898 ldr r4, [sp, #0x10] */
/* @0x12689c mov r0, r4 */
/* @0x1268a0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1268a4 mov r1, #1 */
/* @0x1268a8 mov r5, r0 */
/* @0x1268ac mov r0, r4 */
/* @0x1268b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1268b4 mov r1, r0 */
/* @0x1268b8 mov r0, r5 */
/* @0x1268bc pop {r3, r4, r5, lr} */
/* @0x1268c0 b 0x1dc318 <_Z13HighScore_AddPKci> */

/* ── FUNC 0x1268c4 · F_HighscoreAddCurrent(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x1268c4 push {r3, lr} */
/* @0x1268c8 ldr r3, [pc, #0x18] */
/* @0x1268cc ldr r0, [pc, #0x18] */
/* @0x1268d0 ldr r3, [pc, r3] */
/* @0x1268d4 add r0, pc, r0 */
/* @0x1268d8 ldr r1, [r3] */
/* @0x1268dc bl 0x1dc318 <_Z13HighScore_AddPKci> */
/* @0x1268e0 pop {r3, lr} */
/* @0x1268e4 b 0x18c2c8 <_Z8IO_Clearv> */
/* @0x1268e8 .word 0x002c81b4 */
/* @0x1268ec .word 0x002159b8 */

/* ── FUNC 0x1268f0 · F_HighscoreValue(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1268f0 push {r4, lr} */
/* @0x1268f4 mov r3, #0 */
/* @0x1268f8 mov r1, r3 */
/* @0x1268fc str r3, [r0, #0xc] */
/* @0x126900 mov r4, r0 */
/* @0x126904 ldr r0, [sp, #0x8] */
/* @0x126908 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12690c bl 0x1dc310 <_Z15HighScore_Valuei> */
/* @0x126910 vmov s15, r0 */
/* @0x126914 vcvt.f64.s32 d7, s15 */
/* @0x126918 vmov r0, r1, d7 */
/* @0x12691c vmov r2, s14 */
/* @0x126920 mov r3, r1 */
/* @0x126924 stm r4, {r2, r3} */
/* @0x126928 pop {r4, pc} */

/* ── FUNC 0x12692c · F_HighscoreName(RValue&, CInstance*, CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x12692c push {r4, lr} */
/* @0x126930 sub sp, sp, #8 */
/* @0x126934 mov r4, r0 */
/* @0x126938 mov r1, #0 */
/* @0x12693c ldr r0, [sp, #0x10] */
/* @0x126940 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x126944 mov r1, r0 */
/* @0x126948 add r0, sp, #4 */
/* @0x12694c bl 0x1dc314 <_Z14HighScore_NameRPKci> */
/* @0x126950 mov r0, r4 */
/* @0x126954 ldr r1, [sp, #0x4] */
/* @0x126958 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x12695c add sp, sp, #8 */
/* @0x126960 pop {r4, pc} */

/* ── FUNC 0x126964 · F_GetDirectory(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x126964 ldr r3, [pc, #0x38] */
/* @0x126968 push {r4, lr} */
/* @0x12696c ldr r3, [pc, r3] */
/* @0x126970 mov r4, r0 */
/* @0x126974 ldr r1, [pc, #0x2c] */
/* @0x126978 ldr r0, [r3] */
/* @0x12697c add r1, pc, r1 */
/* @0x126980 ldr r2, [r0] */
/* @0x126984 ldr r3, [r2, #0xc] */
/* @0x126988 blx r3 */
/* @0x12698c ldr r1, [pc, #0x18] */
/* @0x126990 mov r0, r4 */
/* @0x126994 add r1, pc, r1 */
/* @0x126998 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x12699c pop {r4, lr} */
/* @0x1269a0 b 0x18c2c8 <_Z8IO_Clearv> */
/* @0x1269a4 eoreq r6, r12, r8, lsr #27 */
/* @0x1269a8 eoreq r5, r1, r8, lsl r9 */
/* @0x1269ac eoreq r8, r0, r2, lsr #3 */

/* ── FUNC 0x1269b0 · F_GetDirectoryAlt(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1269b0 ldr r3, [pc, #0x38] */
/* @0x1269b4 push {r4, lr} */
/* @0x1269b8 ldr r3, [pc, r3] */
/* @0x1269bc mov r4, r0 */
/* @0x1269c0 ldr r1, [pc, #0x2c] */
/* @0x1269c4 ldr r0, [r3] */
/* @0x1269c8 add r1, pc, r1 */
/* @0x1269cc ldr r2, [r0] */
/* @0x1269d0 ldr r3, [r2, #0xc] */
/* @0x1269d4 blx r3 */
/* @0x1269d8 ldr r1, [pc, #0x18] */
/* @0x1269dc mov r0, r4 */
/* @0x1269e0 add r1, pc, r1 */
/* @0x1269e4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1269e8 pop {r4, lr} */
/* @0x1269ec b 0x18c2c8 <_Z8IO_Clearv> */
/* @0x1269f0 eoreq r6, r12, r12, asr sp */
/* @0x1269f4 .word 0x002158f4 */
/* @0x1269f8 eoreq r8, r0, r6, asr r1 */

/* ── FUNC 0x1269fc · F_DrawHighscore(RValue&, CInstance*, CInstance*, int, RValue*) · size=380 · insn=95 */
/* @0x1269fc ldr r12, [pc, #0x16c] */
/* @0x126a00 mov r2, #256 */
/* @0x126a04 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x126a08 vpush {d8} */
/* @0x126a0c ldr r12, [pc, r12] */
/* @0x126a10 sub sp, sp, #292 */
/* @0x126a14 mov r1, #0 */
/* @0x126a18 ldr r3, [r12] */
/* @0x126a1c add r5, sp, #28 */
/* @0x126a20 ldr r8, [sp, #0x150] */
/* @0x126a24 mov r4, #1 */
/* @0x126a28 mov r0, r5 */
/* @0x126a2c str r12, [sp, #0x14] */
/* @0x126a30 str r3, [sp, #0x11c] */
/* @0x126a34 bl 0xb65b0 <memset@plt> */
/* @0x126a38 mov r0, r8 */
/* @0x126a3c mov r1, #0 */
/* @0x126a40 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x126a44 mov r1, r4 */
/* @0x126a48 ldr r11, [pc, #0x124] */
/* @0x126a4c add r10, sp, #24 */
/* @0x126a50 mvn r7, #0 */
/* @0x126a54 add r11, pc, r11 */
/* @0x126a58 vmov s16, r0 */
/* @0x126a5c mov r0, r8 */
/* @0x126a60 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x126a64 mov r1, #2 */
/* @0x126a68 mov r3, r0 */
/* @0x126a6c mov r0, r8 */
/* @0x126a70 mov r6, r3 */
/* @0x126a74 str r3, [sp, #0xc] */
/* @0x126a78 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x126a7c mov r1, #3 */
/* @0x126a80 mov r9, r0 */
/* @0x126a84 mov r0, r8 */
/* @0x126a88 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x126a8c vcvt.f32.s32 s16, s16 */
/* @0x126a90 ldr r3, [sp, #0xc] */
/* @0x126a94 movw r2, #0x6667 */
/* @0x126a98 movt r2, #0x6666 */
/* @0x126a9c vmov r8, s16 */
/* @0x126aa0 rsb r0, r3, r0 */
/* @0x126aa4 smull r1, r2, r2, r0 */
/* @0x126aa8 asr r3, r0, #31 */
/* @0x126aac rsb r3, r3, r2, asr #2 */
/* @0x126ab0 str r3, [sp, #0x10] */
/* @0x126ab4 mov r1, r4 */
/* @0x126ab8 mov r0, r10 */
/* @0x126abc mov r3, #0 */
/* @0x126ac0 str r3, [sp, #0x18] */
/* @0x126ac4 bl 0x1dc314 <_Z14HighScore_NameRPKci> */
/* @0x126ac8 vmov s15, r6 */
/* @0x126acc ldr r12, [sp, #0x10] */
/* @0x126ad0 mvn r3, #0 */
/* @0x126ad4 vcvt.f32.s32 s16, s15 */
/* @0x126ad8 ldr r2, [sp, #0x18] */
/* @0x126adc mov r0, r8 */
/* @0x126ae0 str r7, [sp] */
/* @0x126ae4 add r6, r6, r12 */
/* @0x126ae8 vmov r1, s16 */
/* @0x126aec bl 0x172df8 <_Z12GR_Text_DrawffPKcii> */
/* @0x126af0 mov r0, r4 */
/* @0x126af4 bl 0x1dc310 <_Z15HighScore_Valuei> */
/* @0x126af8 mov r1, #256 */
/* @0x126afc mov r2, r11 */
/* @0x126b00 add r4, r4, #1 */
/* @0x126b04 mov r3, r0 */
/* @0x126b08 mov r0, r5 */
/* @0x126b0c bl 0xb65c8 <snprintf@plt> */
/* @0x126b10 mvn r1, #0 */
/* @0x126b14 mov r2, r1 */
/* @0x126b18 mov r0, r5 */
/* @0x126b1c bl 0x172bc8 <_Z13GR_Text_WidthPKcii> */
/* @0x126b20 str r7, [sp] */
/* @0x126b24 vmov r1, s16 */
/* @0x126b28 mov r2, r5 */
/* @0x126b2c mvn r3, #0 */
/* @0x126b30 rsb r0, r0, r9 */
/* @0x126b34 vmov s15, r0 */
/* @0x126b38 vcvt.f32.s32 s15, s15 */
/* @0x126b3c vmov r0, s15 */
/* @0x126b40 bl 0x172df8 <_Z12GR_Text_DrawffPKcii> */
/* @0x126b44 cmp r4, #11 */
/* @0x126b48 bne 0x126ab4 <_Z15F_DrawHighscoreR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x126b4c ldr r12, [sp, #0x14] */
/* @0x126b50 ldr r2, [sp, #0x11c] */
/* @0x126b54 ldr r3, [r12] */
/* @0x126b58 cmp r2, r3 */
/* @0x126b5c bne 0x126b6c <_Z15F_DrawHighscoreR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x126b60 add sp, sp, #292 */
/* @0x126b64 vpop {d8} */
/* @0x126b68 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x126b6c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x126b70 eoreq r6, r12, r4, asr #30 */
/* @0x126b74 .word 0x0020bab8 */

/* ── FUNC 0x126b78 · F_GetOpenFileName(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x126b78 push {r4, r5, r6, lr} */
/* @0x126b7c mov r1, #0 */
/* @0x126b80 ldr r4, [sp, #0x10] */
/* @0x126b84 mov r6, r0 */
/* @0x126b88 mov r0, r4 */
/* @0x126b8c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x126b90 mov r1, #1 */
/* @0x126b94 mov r5, r0 */
/* @0x126b98 mov r0, r4 */
/* @0x126b9c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x126ba0 mov r2, #0 */
/* @0x126ba4 mov r3, r2 */
/* @0x126ba8 mov r1, r0 */
/* @0x126bac mov r0, r5 */
/* @0x126bb0 bl 0x160ec0 <_Z17YYGetOpenFileNamePcS_S_S_> */
/* @0x126bb4 subs r5, r0, #0 */
/* @0x126bb8 beq 0x126bf0 <_Z17F_GetOpenFileNameR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x126bbc mov r0, #12 */
/* @0x126bc0 bl 0x27c524 <_Znwj> */
/* @0x126bc4 mov r4, r0 */
/* @0x126bc8 mov r0, r5 */
/* @0x126bcc bl 0xb6640 <strdup@plt> */
/* @0x126bd0 ldr r3, [pc, #0x2c] */
/* @0x126bd4 mov r2, #0 */
/* @0x126bd8 strb r2, [r4, #0x8] */
/* @0x126bdc ldr r3, [pc, r3] */
/* @0x126be0 ldr r2, [r3] */
/* @0x126be4 str r2, [r4] */
/* @0x126be8 str r4, [r3] */
/* @0x126bec str r0, [r4, #0x4] */
/* @0x126bf0 mov r0, r6 */
/* @0x126bf4 mov r1, r5 */
/* @0x126bf8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x126bfc pop {r4, r5, r6, lr} */
/* @0x126c00 b 0x18c2c8 <_Z8IO_Clearv> */
/* @0x126c04 eoreq r7, r12, r12, lsr #29 */

/* ── FUNC 0x126c08 · F_GetOpenFileNameExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x126c08 push {r4, r5, r6, r7, r8, lr} */
/* @0x126c0c mov r1, #0 */
/* @0x126c10 ldr r4, [sp, #0x18] */
/* @0x126c14 mov r6, r0 */
/* @0x126c18 mov r0, r4 */
/* @0x126c1c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x126c20 mov r1, #1 */
/* @0x126c24 mov r8, r0 */
/* @0x126c28 mov r0, r4 */
/* @0x126c2c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x126c30 mov r1, #2 */
/* @0x126c34 mov r7, r0 */
/* @0x126c38 mov r0, r4 */
/* @0x126c3c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x126c40 mov r1, #3 */
/* @0x126c44 mov r5, r0 */
/* @0x126c48 mov r0, r4 */
/* @0x126c4c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x126c50 mov r2, r5 */
/* @0x126c54 mov r1, r7 */
/* @0x126c58 mov r3, r0 */
/* @0x126c5c mov r0, r8 */
/* @0x126c60 bl 0x160ec0 <_Z17YYGetOpenFileNamePcS_S_S_> */
/* @0x126c64 subs r5, r0, #0 */
/* @0x126c68 beq 0x126ca0 <_Z20F_GetOpenFileNameExtR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x126c6c mov r0, #12 */
/* @0x126c70 bl 0x27c524 <_Znwj> */
/* @0x126c74 mov r4, r0 */
/* @0x126c78 mov r0, r5 */
/* @0x126c7c bl 0xb6640 <strdup@plt> */
/* @0x126c80 ldr r3, [pc, #0x2c] */
/* @0x126c84 mov r2, #0 */
/* @0x126c88 strb r2, [r4, #0x8] */
/* @0x126c8c ldr r3, [pc, r3] */
/* @0x126c90 ldr r2, [r3] */
/* @0x126c94 str r2, [r4] */
/* @0x126c98 str r4, [r3] */
/* @0x126c9c str r0, [r4, #0x4] */
/* @0x126ca0 mov r0, r6 */
/* @0x126ca4 mov r1, r5 */
/* @0x126ca8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x126cac pop {r4, r5, r6, r7, r8, lr} */
/* @0x126cb0 b 0x18c2c8 <_Z8IO_Clearv> */
/* @0x126cb4 .word 0x002c7dfc */

/* ── FUNC 0x126cb8 · F_GetSaveFileName(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x126cb8 push {r4, r5, r6, lr} */
/* @0x126cbc mov r1, #0 */
/* @0x126cc0 ldr r4, [sp, #0x10] */
/* @0x126cc4 mov r6, r0 */
/* @0x126cc8 mov r0, r4 */
/* @0x126ccc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x126cd0 mov r1, #1 */
/* @0x126cd4 mov r5, r0 */
/* @0x126cd8 mov r0, r4 */
/* @0x126cdc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x126ce0 mov r2, #0 */
/* @0x126ce4 mov r3, r2 */
/* @0x126ce8 mov r1, r0 */
/* @0x126cec mov r0, r5 */
/* @0x126cf0 bl 0x160ec8 <_Z17YYGetSaveFileNamePcS_S_S_> */
/* @0x126cf4 subs r5, r0, #0 */
/* @0x126cf8 beq 0x126d30 <_Z17F_GetSaveFileNameR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x126cfc mov r0, #12 */
/* @0x126d00 bl 0x27c524 <_Znwj> */
/* @0x126d04 mov r4, r0 */
/* @0x126d08 mov r0, r5 */
/* @0x126d0c bl 0xb6640 <strdup@plt> */
/* @0x126d10 ldr r3, [pc, #0x2c] */
/* @0x126d14 mov r2, #0 */
/* @0x126d18 strb r2, [r4, #0x8] */
/* @0x126d1c ldr r3, [pc, r3] */
/* @0x126d20 ldr r2, [r3] */
/* @0x126d24 str r2, [r4] */
/* @0x126d28 str r4, [r3] */
/* @0x126d2c str r0, [r4, #0x4] */
/* @0x126d30 mov r0, r6 */
/* @0x126d34 mov r1, r5 */
/* @0x126d38 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x126d3c pop {r4, r5, r6, lr} */
/* @0x126d40 b 0x18c2c8 <_Z8IO_Clearv> */
/* @0x126d44 .word 0x002c6cb0 */

/* ── FUNC 0x126d48 · F_GetSaveFileNameExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x126d48 push {r4, r5, r6, r7, r8, lr} */
/* @0x126d4c mov r1, #0 */
/* @0x126d50 ldr r4, [sp, #0x18] */
/* @0x126d54 mov r6, r0 */
/* @0x126d58 mov r0, r4 */
/* @0x126d5c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x126d60 mov r1, #1 */
/* @0x126d64 mov r8, r0 */
/* @0x126d68 mov r0, r4 */
/* @0x126d6c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x126d70 mov r1, #2 */
/* @0x126d74 mov r7, r0 */
/* @0x126d78 mov r0, r4 */
/* @0x126d7c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x126d80 mov r1, #3 */
/* @0x126d84 mov r5, r0 */
/* @0x126d88 mov r0, r4 */
/* @0x126d8c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x126d90 mov r2, r5 */
/* @0x126d94 mov r1, r7 */
/* @0x126d98 mov r3, r0 */
/* @0x126d9c mov r0, r8 */
/* @0x126da0 bl 0x160ec8 <_Z17YYGetSaveFileNamePcS_S_S_> */
/* @0x126da4 subs r5, r0, #0 */
/* @0x126da8 beq 0x126de0 <_Z20F_GetSaveFileNameExtR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x126dac mov r0, #12 */
/* @0x126db0 bl 0x27c524 <_Znwj> */
/* @0x126db4 mov r4, r0 */
/* @0x126db8 mov r0, r5 */
/* @0x126dbc bl 0xb6640 <strdup@plt> */
/* @0x126dc0 ldr r3, [pc, #0x2c] */
/* @0x126dc4 mov r2, #0 */
/* @0x126dc8 strb r2, [r4, #0x8] */
/* @0x126dcc ldr r3, [pc, r3] */
/* @0x126dd0 ldr r2, [r3] */
/* @0x126dd4 str r2, [r4] */
/* @0x126dd8 str r4, [r3] */
/* @0x126ddc str r0, [r4, #0x4] */
/* @0x126de0 mov r0, r6 */
/* @0x126de4 mov r1, r5 */
/* @0x126de8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x126dec pop {r4, r5, r6, r7, r8, lr} */
/* @0x126df0 b 0x18c2c8 <_Z8IO_Clearv> */
/* @0x126df4 eoreq r6, r12, r0, lsl #24 */

/* ── FUNC 0x126df8 · F_MouseWheelUp(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x126df8 mov r3, #0 */
/* @0x126dfc push {r4, lr} */
/* @0x126e00 mov r4, r0 */
/* @0x126e04 str r3, [r4, #0xc] */
/* @0x126e08 mov r0, r3 */
/* @0x126e0c bl 0x18c168 <_Z11IO_Wheel_Upi> */
/* @0x126e10 vmov s15, r0 */
/* @0x126e14 vcvt.f64.u32 d7, s15 */
/* @0x126e18 vmov r0, r1, d7 */
/* @0x126e1c vmov r2, s14 */
/* @0x126e20 mov r3, r1 */
/* @0x126e24 stm r4, {r2, r3} */
/* @0x126e28 pop {r4, pc} */

/* ── FUNC 0x126e2c · F_MouseWheelDown(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x126e2c mov r3, #0 */
/* @0x126e30 push {r4, lr} */
/* @0x126e34 mov r4, r0 */
/* @0x126e38 str r3, [r4, #0xc] */
/* @0x126e3c mov r0, r3 */
/* @0x126e40 bl 0x18c18c <_Z13IO_Wheel_Downi> */
/* @0x126e44 vmov s15, r0 */
/* @0x126e48 vcvt.f64.u32 d7, s15 */
/* @0x126e4c vmov r0, r1, d7 */
/* @0x126e50 vmov r2, s14 */
/* @0x126e54 mov r3, r1 */
/* @0x126e58 stm r4, {r2, r3} */
/* @0x126e5c pop {r4, pc} */

/* ── FUNC 0x126e60 · F_ShowMessage(RValue&, CInstance*, CInstance*, int, RValue*) · size=228 · insn=57 */
/* @0x126e60 ldr r1, [pc, #0xcc] */
/* @0x126e64 mov r12, #16 */
/* @0x126e68 push {r4, lr} */
/* @0x126e6c sub sp, sp, #16 */
/* @0x126e70 mov r0, r12 */
/* @0x126e74 add r1, pc, r1 */
/* @0x126e78 movw r2, #0x575 */
/* @0x126e7c mov r3, #1 */
/* @0x126e80 str r12, [sp, #0x4] */
/* @0x126e84 ldr r4, [sp, #0x18] */
/* @0x126e88 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x126e8c mov r1, #0 */
/* @0x126e90 mov r3, r4 */
/* @0x126e94 mov r2, r0 */
/* @0x126e98 str r0, [sp, #0x8] */
/* @0x126e9c add r0, sp, #16 */
/* @0x126ea0 str r2, [r0, #-0x4]! */
/* @0x126ea4 strb r1, [r2] */
/* @0x126ea8 add r1, sp, #8 */
/* @0x126eac add r2, sp, #4 */
/* @0x126eb0 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x126eb4 ldr r0, [sp, #0x8] */
/* @0x126eb8 bl 0x212da8 <_Z19String_Replace_HashPc> */
/* @0x126ebc bl 0x29cb74 <_Z19DebuggerIsConnectedv> */
/* @0x126ec0 cmp r0, #0 */
/* @0x126ec4 beq 0x126f14 <_Z13F_ShowMessageR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x126ec8 ldr r3, [pc, #0x68] */
/* @0x126ecc ldr r3, [pc, r3] */
/* @0x126ed0 ldrb r3, [r3] */
/* @0x126ed4 cmp r3, #0 */
/* @0x126ed8 beq 0x126ef0 <_Z13F_ShowMessageR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x126edc ldr r3, [pc, #0x58] */
/* @0x126ee0 ldr r3, [pc, r3] */
/* @0x126ee4 ldr r3, [r3] */
/* @0x126ee8 cmp r3, #0 */
/* @0x126eec beq 0x126f20 <_Z13F_ShowMessageR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x126ef0 bl 0x29cb88 <_Z32DebuggerRunBackgroundMessageLoopv> */
/* @0x126ef4 ldr r0, [sp, #0x8] */
/* @0x126ef8 bl 0xc4b0c <_Z11ShowMessagePKc> */
/* @0x126efc bl 0x29cc30 <_Z33DebuggerStopBackgroundMessageLoopv> */
/* @0x126f00 bl 0x18c2c8 <_Z8IO_Clearv> */
/* @0x126f04 ldr r0, [sp, #0x8] */
/* @0x126f08 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x126f0c add sp, sp, #16 */
/* @0x126f10 pop {r4, pc} */
/* @0x126f14 ldr r0, [sp, #0x8] */
/* @0x126f18 bl 0xc4b0c <_Z11ShowMessagePKc> */
/* @0x126f1c b 0x126f00 <_Z13F_ShowMessageR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x126f20 ldr r1, [pc, #0x18] */
/* @0x126f24 mov r0, #1 */
/* @0x126f28 add r1, pc, r1 */
/* @0x126f2c bl 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz> */
/* @0x126f30 b 0x126ef0 <_Z13F_ShowMessageR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x126f34 eoreq r5, r1, r0, asr #7 */
/* @0x126f38 eoreq r6, r12, r8, asr r10 */
/* @0x126f3c eoreq r7, r12, r0, asr #10 */
/* @0x126f40 eoreq r5, r1, r0, asr r3 */

/* ── FUNC 0x126f44 · F_ShowMessageASync(RValue&, CInstance*, CInstance*, int, RValue*) · size=172 · insn=43 */
/* @0x126f44 ldr r1, [pc, #0x9c] */
/* @0x126f48 mov r12, #16 */
/* @0x126f4c push {r4, r5, lr} */
/* @0x126f50 sub sp, sp, #20 */
/* @0x126f54 mov r4, r0 */
/* @0x126f58 add r1, pc, r1 */
/* @0x126f5c mov r0, r12 */
/* @0x126f60 movw r2, #0x59c */
/* @0x126f64 mov r3, #1 */
/* @0x126f68 str r12, [sp, #0x4] */
/* @0x126f6c ldr r5, [sp, #0x20] */
/* @0x126f70 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x126f74 add r1, sp, #8 */
/* @0x126f78 mov r3, r5 */
/* @0x126f7c mov r5, #0 */
/* @0x126f80 mov r2, r0 */
/* @0x126f84 add r0, sp, #16 */
/* @0x126f88 str r2, [sp, #0x8] */
/* @0x126f8c str r2, [r0, #-0x4]! */
/* @0x126f90 strb r5, [r2] */
/* @0x126f94 add r2, sp, #4 */
/* @0x126f98 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x126f9c ldr r0, [sp, #0x8] */
/* @0x126fa0 bl 0x212da8 <_Z19String_Replace_HashPc> */
/* @0x126fa4 ldr r3, [pc, #0x40] */
/* @0x126fa8 ldr r1, [sp, #0x8] */
/* @0x126fac ldr r3, [pc, r3] */
/* @0x126fb0 str r5, [r4, #0xc] */
/* @0x126fb4 ldr r0, [r3] */
/* @0x126fb8 bl 0xf270c <_ZN10InputQuery16ShowMessageASyncEPKcS1_> */
/* @0x126fbc vmov s15, r0 */
/* @0x126fc0 vcvt.f64.s32 d7, s15 */
/* @0x126fc4 vmov r0, r1, d7 */
/* @0x126fc8 vmov r2, s14 */
/* @0x126fcc mov r3, r1 */
/* @0x126fd0 stm r4, {r2, r3} */
/* @0x126fd4 bl 0x18c2c8 <_Z8IO_Clearv> */
/* @0x126fd8 ldr r0, [sp, #0x8] */
/* @0x126fdc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x126fe0 add sp, sp, #20 */
/* @0x126fe4 pop {r4, r5, pc} */
/* @0x126fe8 .word 0x002152dc */
/* @0x126fec .word 0x002c7ad4 */

/* ── FUNC 0x126ff0 · F_GetString(RValue&, CInstance*, CInstance*, int, RValue*) · size=232 · insn=58 */
/* @0x126ff0 ldr r1, [pc, #0xd4] */
/* @0x126ff4 mov r12, #16 */
/* @0x126ff8 push {r4, r5, r6, lr} */
/* @0x126ffc sub sp, sp, #16 */
/* @0x127000 add r1, pc, r1 */
/* @0x127004 movw r2, #0x5b9 */
/* @0x127008 mov r3, #1 */
/* @0x12700c mov r6, r0 */
/* @0x127010 mov r0, r12 */
/* @0x127014 str r12, [sp] */
/* @0x127018 ldr r5, [sp, #0x20] */
/* @0x12701c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x127020 mov r4, #0 */
/* @0x127024 mov r2, sp */
/* @0x127028 add r1, sp, #4 */
/* @0x12702c mov r3, r0 */
/* @0x127030 add r0, sp, #16 */
/* @0x127034 str r3, [sp, #0x4] */
/* @0x127038 str r3, [r0, #-0x8]! */
/* @0x12703c strb r4, [r3] */
/* @0x127040 add r3, r5, #16 */
/* @0x127044 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x127048 ldr r0, [sp, #0x4] */
/* @0x12704c bl 0x212da8 <_Z19String_Replace_HashPc> */
/* @0x127050 mov r0, r5 */
/* @0x127054 mov r1, r4 */
/* @0x127058 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12705c str r4, [sp, #0xc] */
/* @0x127060 mov r5, r0 */
/* @0x127064 bl 0x29cb74 <_Z19DebuggerIsConnectedv> */
/* @0x127068 cmp r0, r4 */
/* @0x12706c bne 0x1270a4 <_Z11F_GetStringR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x127070 ldr r12, [pc, #0x58] */
/* @0x127074 mov r1, r5 */
/* @0x127078 ldr r2, [sp, #0x4] */
/* @0x12707c add r3, sp, #12 */
/* @0x127080 ldr r12, [pc, r12] */
/* @0x127084 ldr r0, [r12] */
/* @0x127088 bl 0xf28b0 <_ZN10InputQuery5InputEPKcS1_S1_RPc> */
/* @0x12708c bl 0x18c2c8 <_Z8IO_Clearv> */
/* @0x127090 mov r0, r6 */
/* @0x127094 ldr r1, [sp, #0xc] */
/* @0x127098 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x12709c add sp, sp, #16 */
/* @0x1270a0 pop {r4, r5, r6, pc} */
/* @0x1270a4 bl 0x29cb88 <_Z32DebuggerRunBackgroundMessageLoopv> */
/* @0x1270a8 ldr r0, [pc, #0x24] */
/* @0x1270ac mov r1, r5 */
/* @0x1270b0 ldr r2, [sp, #0x4] */
/* @0x1270b4 ldr r0, [pc, r0] */
/* @0x1270b8 add r3, sp, #12 */
/* @0x1270bc ldr r0, [r0] */
/* @0x1270c0 bl 0xf28b0 <_ZN10InputQuery5InputEPKcS1_S1_RPc> */
/* @0x1270c4 bl 0x29cc30 <_Z33DebuggerStopBackgroundMessageLoopv> */
/* @0x1270c8 b 0x12708c <_Z11F_GetStringR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x1270cc eoreq r5, r1, r4, lsr r2 */
/* @0x1270d0 eoreq r7, r12, r0, lsl #20 */
/* @0x1270d4 eoreq r7, r12, r12, asr #19 */

/* ── FUNC 0x1270d8 · F_GetStringAsync(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x1270d8 ldr r1, [pc, #0xa0] */
/* @0x1270dc mov r12, #16 */
/* @0x1270e0 push {r4, r5, r6, lr} */
/* @0x1270e4 sub sp, sp, #16 */
/* @0x1270e8 mov r4, r0 */
/* @0x1270ec add r1, pc, r1 */
/* @0x1270f0 mov r0, r12 */
/* @0x1270f4 movw r2, #0x5d1 */
/* @0x1270f8 mov r3, #1 */
/* @0x1270fc str r12, [sp, #0x4] */
/* @0x127100 ldr r6, [sp, #0x20] */
/* @0x127104 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x127108 mov r5, #0 */
/* @0x12710c add r2, sp, #4 */
/* @0x127110 add r1, sp, #8 */
/* @0x127114 mov r3, r0 */
/* @0x127118 add r0, sp, #16 */
/* @0x12711c str r3, [sp, #0x8] */
/* @0x127120 str r3, [r0, #-0x4]! */
/* @0x127124 strb r5, [r3] */
/* @0x127128 add r3, r6, #16 */
/* @0x12712c bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x127130 ldr r0, [sp, #0x8] */
/* @0x127134 bl 0x212da8 <_Z19String_Replace_HashPc> */
/* @0x127138 mov r1, r5 */
/* @0x12713c mov r0, r6 */
/* @0x127140 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x127144 ldr r3, [pc, #0x38] */
/* @0x127148 ldr r2, [sp, #0x8] */
/* @0x12714c ldr r3, [pc, r3] */
/* @0x127150 str r5, [r4, #0xc] */
/* @0x127154 mov r1, r0 */
/* @0x127158 ldr r0, [r3] */
/* @0x12715c bl 0xf26c4 <_ZN10InputQuery10InputAsyncEPKcS1_S1_> */
/* @0x127160 vmov s15, r0 */
/* @0x127164 ldr r0, [sp, #0x8] */
/* @0x127168 vcvt.f64.s32 d7, s15 */
/* @0x12716c vmov r2, r3, d7 */
/* @0x127170 stm r4, {r2, r3} */
/* @0x127174 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x127178 add sp, sp, #16 */
/* @0x12717c pop {r4, r5, r6, pc} */
/* @0x127180 eoreq r5, r1, r8, asr #2 */
/* @0x127184 eoreq r7, r12, r4, lsr r9 */
