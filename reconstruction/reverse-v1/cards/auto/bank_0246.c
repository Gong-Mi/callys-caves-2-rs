/* libyoyo.so 覆盖卡组 0246
 * 函数 0x299238..0x29a764，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x299238 · F_NETWORK_Create_Server_Raw(RValue&, CInstance*, CInstance*, int, RValue*) · size=12 · insn=3 */
/* @0x299238 ldr r1, [sp] */
/* @0x29923c mov r2, #1 */
/* @0x299240 b 0x298fd0 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x13c> */

/* ── FUNC 0x299244 · FreeSocket(int) · size=312 · insn=78 */
/* @0x299244 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x299248 lsl r8, r0, #1 */
/* @0x29924c ldr r6, [pc, #0x124] */
/* @0x299250 add r3, r8, r0 */
/* @0x299254 mov r7, r0 */
/* @0x299258 ldr r6, [pc, r6] */
/* @0x29925c lsl r3, r3, #2 */
/* @0x299260 add r9, r6, r3 */
/* @0x299264 ldrb r2, [r6, r3] */
/* @0x299268 cmp r2, #0 */
/* @0x29926c popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x299270 ldr r11, [r9, #0x8] */
/* @0x299274 mov r4, #0 */
/* @0x299278 strb r4, [r6, r3] */
/* @0x29927c cmp r11, r4 */
/* @0x299280 strb r4, [r9, #0x1] */
/* @0x299284 beq 0x2992e8 <_Z10FreeSocketi+0xa4> */
/* @0x299288 mov r10, r4 */
/* @0x29928c b 0x29929c <_Z10FreeSocketi+0x58> */
/* @0x299290 add r4, r4, #12 */
/* @0x299294 cmp r4, #768 */
/* @0x299298 beq 0x2992d0 <_Z10FreeSocketi+0x8c> */
/* @0x29929c add r5, r6, r4 */
/* @0x2992a0 ldrb r3, [r5, #0x1] */
/* @0x2992a4 cmp r3, #0 */
/* @0x2992a8 beq 0x299290 <_Z10FreeSocketi+0x4c> */
/* @0x2992ac mov r0, r11 */
/* @0x2992b0 ldr r1, [r5, #0x4] */
/* @0x2992b4 bl 0x2974d4 <_ZN8yyServer12DeleteSocketEP8yySocket> */
/* @0x2992b8 add r4, r4, #12 */
/* @0x2992bc cmp r0, #0 */
/* @0x2992c0 strbne r10, [r5, #0x1] */
/* @0x2992c4 cmp r4, #768 */
/* @0x2992c8 ldr r11, [r9, #0x8] */
/* @0x2992cc bne 0x29929c <_Z10FreeSocketi+0x58> */
/* @0x2992d0 cmp r11, #0 */
/* @0x2992d4 beq 0x2992e8 <_Z10FreeSocketi+0xa4> */
/* @0x2992d8 mov r0, r11 */
/* @0x2992dc bl 0x297184 <_ZN8yyServerD2Ev> */
/* @0x2992e0 mov r0, r11 */
/* @0x2992e4 bl 0x27d1d0 <_ZdlPv> */
/* @0x2992e8 add r9, r8, r7 */
/* @0x2992ec add r9, r6, r9, lsl #2 */
/* @0x2992f0 ldr r2, [r9, #0x4] */
/* @0x2992f4 cmp r2, #0 */
/* @0x2992f8 beq 0x299360 <_Z10FreeSocketi+0x11c> */
/* @0x2992fc add r5, r6, #768 */
/* @0x299300 mov r4, r6 */
/* @0x299304 ldrb r3, [r4] */
/* @0x299308 cmp r3, #0 */
/* @0x29930c beq 0x299328 <_Z10FreeSocketi+0xe4> */
/* @0x299310 ldr r0, [r4, #0x8] */
/* @0x299314 mov r1, r2 */
/* @0x299318 cmp r0, #0 */
/* @0x29931c beq 0x299328 <_Z10FreeSocketi+0xe4> */
/* @0x299320 bl 0x2974d4 <_ZN8yyServer12DeleteSocketEP8yySocket> */
/* @0x299324 ldr r2, [r9, #0x4] */
/* @0x299328 add r4, r4, #12 */
/* @0x29932c cmp r4, r5 */
/* @0x299330 bne 0x299304 <_Z10FreeSocketi+0xc0> */
/* @0x299334 mov r0, r2 */
/* @0x299338 bl 0x295474 <_ZN8yySocket5CloseEv> */
/* @0x29933c add r2, r8, r7 */
/* @0x299340 mov r3, #3 */
/* @0x299344 add r2, r6, r2, lsl #2 */
/* @0x299348 ldr r4, [r2, #0x4] */
/* @0x29934c str r3, [r4, #0x28] */
/* @0x299350 mov r0, r4 */
/* @0x299354 bl 0x294cbc <_ZN8yySocketD2Ev> */
/* @0x299358 mov r0, r4 */
/* @0x29935c bl 0x27d1d0 <_ZdlPv> */
/* @0x299360 add r7, r8, r7 */
/* @0x299364 mov r3, #0 */
/* @0x299368 add r6, r6, r7, lsl #2 */
/* @0x29936c str r3, [r6, #0x4] */
/* @0x299370 str r3, [r6, #0x8] */
/* @0x299374 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x299378 andseq r8, r5, r12, asr #14 */

/* ── FUNC 0x29937c · F_NETWORK_Destroy_Socket(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x29937c push {r3, lr} */
/* @0x299380 mov r1, #0 */
/* @0x299384 ldr r0, [sp, #0x8] */
/* @0x299388 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x29938c pop {r3, lr} */
/* @0x299390 b 0x299244 <_Z10FreeSocketi> */

/* ── FUNC 0x299394 · F_NETWORK_Create_Socket_Ext(RValue&, CInstance*, CInstance*, int, RValue*) · size=456 · insn=114 */
/* @0x299394 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x299398 mov r5, r0 */
/* @0x29939c ldr r4, [pc, #0x19c] */
/* @0x2993a0 mov r2, #0 */
/* @0x2993a4 ldr r0, [pc, #0x198] */
/* @0x2993a8 movt r2, #0xbff0 */
/* @0x2993ac add r4, pc, r4 */
/* @0x2993b0 ldr r1, [pc, #0x190] */
/* @0x2993b4 sub sp, sp, #28 */
/* @0x2993b8 mov r3, #0 */
/* @0x2993bc ldr r9, [r4, r0] */
/* @0x2993c0 str r2, [r5, #0x4] */
/* @0x2993c4 str r3, [r5, #0xc] */
/* @0x2993c8 ldr r2, [r9] */
/* @0x2993cc str r3, [r5] */
/* @0x2993d0 ldr r10, [sp, #0x40] */
/* @0x2993d4 str r2, [sp, #0x14] */
/* @0x2993d8 ldr r6, [r4, r1] */
/* @0x2993dc ldrb r3, [r6] */
/* @0x2993e0 cmp r3, #0 */
/* @0x2993e4 beq 0x299520 <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0x2993e8 mov r0, r10 */
/* @0x2993ec mov r1, #0 */
/* @0x2993f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x2993f4 ldr r3, [pc, #0x150] */
/* @0x2993f8 ldr r3, [r4, r3] */
/* @0x2993fc ldr r3, [r3] */
/* @0x299400 sub r3, r3, #2 */
/* @0x299404 cmp r3, #2 */
/* @0x299408 mov r7, r0 */
/* @0x29940c bls 0x2994e8 <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x299410 cmp r0, #0 */
/* @0x299414 bne 0x2994d0 <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x299418 bl 0x298e28 <_Z11AllocSocketv> */
/* @0x29941c subs r8, r0, #0 */
/* @0x299420 blt 0x29950c <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x299424 mov r0, #200 */
/* @0x299428 add r11, sp, #4 */
/* @0x29942c bl 0x27c524 <_Znwj> */
/* @0x299430 mov r1, r7 */
/* @0x299434 mov r6, r0 */
/* @0x299438 bl 0x2970ac <_ZN8yySocketC2E11eSocketType> */
/* @0x29943c ldr r2, [pc, #0x10c] */
/* @0x299440 add r3, r8, r8, lsl #1 */
/* @0x299444 mov r0, r6 */
/* @0x299448 ldr r2, [r4, r2] */
/* @0x29944c add r3, r2, r3, lsl #2 */
/* @0x299450 str r6, [r3, #0x4] */
/* @0x299454 bl 0x294ec8 <_ZN8yySocket4InitEv> */
/* @0x299458 mov r0, r6 */
/* @0x29945c mov r1, #65536 */
/* @0x299460 str r8, [r6, #0x68] */
/* @0x299464 bl 0x296080 <_ZN8yySocket14AllocateBufferEi> */
/* @0x299468 mov r0, r6 */
/* @0x29946c bl 0x295fec <_ZN8yySocket12CreateSocketEv> */
/* @0x299470 mov r0, r10 */
/* @0x299474 mov r1, #1 */
/* @0x299478 mov r3, #0 */
/* @0x29947c mov r2, #2 */
/* @0x299480 str r3, [sp, #0x4] */
/* @0x299484 str r3, [sp, #0x8] */
/* @0x299488 str r3, [sp, #0xc] */
/* @0x29948c str r3, [sp, #0x10] */
/* @0x299490 strh r2, [sp, #4] */
/* @0x299494 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x299498 rev16 r0, r0 */
/* @0x29949c cmp r7, #3 */
/* @0x2994a0 strh r0, [sp, #6] */
/* @0x2994a4 beq 0x2994c0 <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x2994a8 mov r0, r6 */
/* @0x2994ac mov r1, r11 */
/* @0x2994b0 mov r2, #16 */
/* @0x2994b4 bl 0x2951c4 <_ZN8yySocket4BindEPK8sockaddri> */
/* @0x2994b8 cmp r0, #0 */
/* @0x2994bc blt 0x299530 <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x2994c0 vmov s15, r8 */
/* @0x2994c4 vcvt.f64.s32 d7, s15 */
/* @0x2994c8 vmov r2, r3, d7 */
/* @0x2994cc stm r5, {r2, r3} */
/* @0x2994d0 ldr r2, [sp, #0x14] */
/* @0x2994d4 ldr r3, [r9] */
/* @0x2994d8 cmp r2, r3 */
/* @0x2994dc bne 0x29953c <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x2994e0 add sp, sp, #28 */
/* @0x2994e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2994e8 cmp r0, #2 */
/* @0x2994ec bne 0x299418 <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x2994f0 ldr r0, [pc, #0x5c] */
/* @0x2994f4 mov r1, #0 */
/* @0x2994f8 add r0, pc, r0 */
/* @0x2994fc bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x299500 bl 0x298e28 <_Z11AllocSocketv> */
/* @0x299504 subs r8, r0, #0 */
/* @0x299508 bge 0x299424 <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x29950c ldr r0, [pc, #0x44] */
/* @0x299510 mov r1, #0 */
/* @0x299514 add r0, pc, r0 */
/* @0x299518 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x29951c b 0x2994d0 <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x299520 bl 0x294d18 <_ZN8yySocket7StartupEv> */
/* @0x299524 mov r3, #1 */
/* @0x299528 strb r3, [r6] */
/* @0x29952c b 0x2993e8 <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x299530 mov r0, r8 */
/* @0x299534 bl 0x299244 <_Z10FreeSocketi> */
/* @0x299538 b 0x2994d0 <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x29953c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x299540 andseq r8, r5, r4, lsr #17 */
/* @0x299544 .word 0xffffbd00 */
/* @0x299548 .word 0xfffffd4c */
/* @0x29954c .word 0xffffe6d0 */
/* @0x299550 .word 0xfffffd54 */
/* @0x299554 andeq r0, r12, r12, asr #3 */
/* @0x299558 ldrdeq r0, r1, [r12], -r8 */

/* ── FUNC 0x29955c · FreeSocket(yySocket*) · size=200 · insn=50 */
/* @0x29955c push {r3, r4, r5, r6, r7, lr} */
/* @0x299560 mov r3, #0 */
/* @0x299564 ldr r4, [pc, #0xb4] */
/* @0x299568 mov r5, r3 */
/* @0x29956c ldr r4, [pc, r4] */
/* @0x299570 b 0x299580 <_Z10FreeSocketP8yySocket+0x24> */
/* @0x299574 cmp r3, #768 */
/* @0x299578 add r5, r5, #1 */
/* @0x29957c beq 0x299618 <_Z10FreeSocketP8yySocket+0xbc> */
/* @0x299580 ldrb r2, [r4, r3] */
/* @0x299584 add r1, r4, r3 */
/* @0x299588 add r3, r3, #12 */
/* @0x29958c cmp r2, #0 */
/* @0x299590 beq 0x299574 <_Z10FreeSocketP8yySocket+0x18> */
/* @0x299594 ldr r2, [r1, #0x4] */
/* @0x299598 cmp r2, r0 */
/* @0x29959c bne 0x299574 <_Z10FreeSocketP8yySocket+0x18> */
/* @0x2995a0 lsl r6, r5, #1 */
/* @0x2995a4 mov r2, #0 */
/* @0x2995a8 add r1, r6, r5 */
/* @0x2995ac lsl r1, r1, #2 */
/* @0x2995b0 add r3, r4, r1 */
/* @0x2995b4 strb r2, [r4, r1] */
/* @0x2995b8 ldr r7, [r3, #0x4] */
/* @0x2995bc strb r2, [r3, #0x1] */
/* @0x2995c0 cmp r7, r2 */
/* @0x2995c4 beq 0x2995d8 <_Z10FreeSocketP8yySocket+0x7c> */
/* @0x2995c8 mov r0, r7 */
/* @0x2995cc bl 0x294cbc <_ZN8yySocketD2Ev> */
/* @0x2995d0 mov r0, r7 */
/* @0x2995d4 bl 0x27d1d0 <_ZdlPv> */
/* @0x2995d8 add r3, r6, r5 */
/* @0x2995dc add r3, r4, r3, lsl #2 */
/* @0x2995e0 ldr r7, [r3, #0x8] */
/* @0x2995e4 cmp r7, #0 */
/* @0x2995e8 beq 0x2995fc <_Z10FreeSocketP8yySocket+0xa0> */
/* @0x2995ec mov r0, r7 */
/* @0x2995f0 bl 0x297184 <_ZN8yyServerD2Ev> */
/* @0x2995f4 mov r0, r7 */
/* @0x2995f8 bl 0x27d1d0 <_ZdlPv> */
/* @0x2995fc add r6, r6, r5 */
/* @0x299600 mov r3, #0 */
/* @0x299604 mov r0, r5 */
/* @0x299608 add r4, r4, r6, lsl #2 */
/* @0x29960c str r3, [r4, #0x4] */
/* @0x299610 str r3, [r4, #0x8] */
/* @0x299614 pop {r3, r4, r5, r6, r7, pc} */
/* @0x299618 mvn r0, #0 */
/* @0x29961c pop {r3, r4, r5, r6, r7, pc} */
/* @0x299620 andseq r8, r5, r8, lsr r4 */

/* ── FUNC 0x299624 · GetSocketIndex(yySocket*) · size=96 · insn=24 */
/* @0x299624 ldr r2, [pc, #0x54] */
/* @0x299628 mov r3, #0 */
/* @0x29962c str r4, [sp, #-0x4]! */
/* @0x299630 mov r1, r3 */
/* @0x299634 ldr r2, [pc, r2] */
/* @0x299638 b 0x299648 <_Z14GetSocketIndexP8yySocket+0x24> */
/* @0x29963c cmp r3, #768 */
/* @0x299640 add r1, r1, #1 */
/* @0x299644 beq 0x299674 <_Z14GetSocketIndexP8yySocket+0x50> */
/* @0x299648 ldrb r12, [r2, r3] */
/* @0x29964c add r4, r2, r3 */
/* @0x299650 add r3, r3, #12 */
/* @0x299654 cmp r12, #0 */
/* @0x299658 beq 0x29963c <_Z14GetSocketIndexP8yySocket+0x18> */
/* @0x29965c ldr r12, [r4, #0x4] */
/* @0x299660 cmp r12, r0 */
/* @0x299664 bne 0x29963c <_Z14GetSocketIndexP8yySocket+0x18> */
/* @0x299668 mov r0, r1 */
/* @0x29966c ldr r4, [sp], #4 */
/* @0x299670 bx lr */
/* @0x299674 mvn r0, #0 */
/* @0x299678 ldr r4, [sp], #4 */
/* @0x29967c bx lr */
/* @0x299680 andseq r8, r5, r0, ror r3 */

/* ── FUNC 0x299684 · InitNetworkingFunctions() · size=564 · insn=141 */
/* @0x299684 push {r4, lr} */
/* @0x299688 bl 0x298df4 <_Z14InitNetworkingv> */
/* @0x29968c mov r2, #1 */
/* @0x299690 ldr r4, [pc, #0x1a4] */
/* @0x299694 mov r3, #0 */
/* @0x299698 ldr r1, [pc, #0x1a0] */
/* @0x29969c add r4, pc, r4 */
/* @0x2996a0 ldr r0, [pc, #0x19c] */
/* @0x2996a4 ldr r1, [r4, r1] */
/* @0x2996a8 add r0, pc, r0 */
/* @0x2996ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x2996b0 ldr r1, [pc, #0x190] */
/* @0x2996b4 ldr r0, [pc, #0x190] */
/* @0x2996b8 mov r2, #2 */
/* @0x2996bc mov r3, #0 */
/* @0x2996c0 ldr r1, [r4, r1] */
/* @0x2996c4 add r0, pc, r0 */
/* @0x2996c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x2996cc ldr r1, [pc, #0x17c] */
/* @0x2996d0 ldr r0, [pc, #0x17c] */
/* @0x2996d4 mov r2, #3 */
/* @0x2996d8 mov r3, #0 */
/* @0x2996dc ldr r1, [r4, r1] */
/* @0x2996e0 add r0, pc, r0 */
/* @0x2996e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x2996e8 ldr r1, [pc, #0x168] */
/* @0x2996ec ldr r0, [pc, #0x168] */
/* @0x2996f0 mov r2, #3 */
/* @0x2996f4 mov r3, #0 */
/* @0x2996f8 ldr r1, [r4, r1] */
/* @0x2996fc add r0, pc, r0 */
/* @0x299700 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x299704 ldr r1, [pc, #0x154] */
/* @0x299708 ldr r0, [pc, #0x154] */
/* @0x29970c mov r2, #3 */
/* @0x299710 mov r3, #0 */
/* @0x299714 ldr r1, [r4, r1] */
/* @0x299718 add r0, pc, r0 */
/* @0x29971c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x299720 ldr r1, [pc, #0x140] */
/* @0x299724 ldr r0, [pc, #0x140] */
/* @0x299728 mov r2, #3 */
/* @0x29972c mov r3, #0 */
/* @0x299730 ldr r1, [r4, r1] */
/* @0x299734 add r0, pc, r0 */
/* @0x299738 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x29973c ldr r1, [pc, #0x12c] */
/* @0x299740 ldr r0, [pc, #0x12c] */
/* @0x299744 mov r2, #3 */
/* @0x299748 mov r3, #0 */
/* @0x29974c ldr r1, [r4, r1] */
/* @0x299750 add r0, pc, r0 */
/* @0x299754 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x299758 ldr r1, [pc, #0x118] */
/* @0x29975c ldr r0, [pc, #0x118] */
/* @0x299760 mov r2, #3 */
/* @0x299764 mov r3, #0 */
/* @0x299768 ldr r1, [r4, r1] */
/* @0x29976c add r0, pc, r0 */
/* @0x299770 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x299774 ldr r1, [pc, #0x104] */
/* @0x299778 ldr r0, [pc, #0x104] */
/* @0x29977c mov r2, #3 */
/* @0x299780 mov r3, #0 */
/* @0x299784 ldr r1, [r4, r1] */
/* @0x299788 add r0, pc, r0 */
/* @0x29978c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x299790 ldr r1, [pc, #0xf0] */
/* @0x299794 ldr r0, [pc, #0xf0] */
/* @0x299798 mov r2, #5 */
/* @0x29979c mov r3, #0 */
/* @0x2997a0 ldr r1, [r4, r1] */
/* @0x2997a4 add r0, pc, r0 */
/* @0x2997a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x2997ac ldr r1, [pc, #0xdc] */
/* @0x2997b0 ldr r0, [pc, #0xdc] */
/* @0x2997b4 mov r2, #5 */
/* @0x2997b8 mov r3, #0 */
/* @0x2997bc ldr r1, [r4, r1] */
/* @0x2997c0 add r0, pc, r0 */
/* @0x2997c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x2997c8 ldr r1, [pc, #0xc8] */
/* @0x2997cc ldr r0, [pc, #0xc8] */
/* @0x2997d0 mov r2, #1 */
/* @0x2997d4 mov r3, #0 */
/* @0x2997d8 ldr r1, [r4, r1] */
/* @0x2997dc add r0, pc, r0 */
/* @0x2997e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x2997e4 ldr r1, [pc, #0xb4] */
/* @0x2997e8 ldr r0, [pc, #0xb4] */
/* @0x2997ec mov r2, #1 */
/* @0x2997f0 mov r3, #0 */
/* @0x2997f4 ldr r1, [r4, r1] */
/* @0x2997f8 add r0, pc, r0 */
/* @0x2997fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x299800 ldr r1, [pc, #0xa0] */
/* @0x299804 ldr r0, [pc, #0xa0] */
/* @0x299808 mov r2, #3 */
/* @0x29980c mov r3, #0 */
/* @0x299810 ldr r1, [r4, r1] */
/* @0x299814 add r0, pc, r0 */
/* @0x299818 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x29981c ldr r1, [pc, #0x8c] */
/* @0x299820 ldr r0, [pc, #0x8c] */
/* @0x299824 mov r2, #2 */
/* @0x299828 mov r3, #0 */
/* @0x29982c ldr r1, [r4, r1] */
/* @0x299830 add r0, pc, r0 */
/* @0x299834 pop {r4, lr} */
/* @0x299838 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x29983c ldrheq r8, [r5], -r4 */
/* @0x299840 .word 0xfffffd5c */
/* @0x299844 andeq r0, r12, r0, lsl r1 */
/* @0x299848 .word 0xfffffd60 */
/* @0x29984c andeq r0, r12, r12, lsl #2 */
/* @0x299850 .word 0xfffffd64 */
/* @0x299854 andeq r0, r12, r12, lsl #2 */
/* @0x299858 .word 0xfffffd68 */
/* @0x29985c andeq r0, r12, r8, lsl #2 */
/* @0x299860 .word 0xfffffd6c */
/* @0x299864 andeq r0, r12, r8, lsl #2 */
/* @0x299868 .word 0xfffffd70 */
/* @0x29986c strdeq r0, r1, [r12], -r12 */
/* @0x299870 .word 0xfffffd74 */
/* @0x299874 strdeq r0, r1, [r12], -r4 */
/* @0x299878 .word 0xfffffd78 */
/* @0x29987c andeq r0, r12, r12, ror #1 */
/* @0x299880 .word 0xfffffd7c */
/* @0x299884 andeq r0, r12, r4, ror #1 */
/* @0x299888 .word 0xfffffd80 */
/* @0x29988c andeq r0, r12, r0, ror #1 */
/* @0x299890 .word 0xfffffd84 */
/* @0x299894 ldrdeq r0, r1, [r12], -r8 */
/* @0x299898 .word 0xfffffd88 */
/* @0x29989c ldrdeq r0, r1, [r12], -r4 */
/* @0x2998a0 .word 0xfffffd8c */
/* @0x2998a4 andeq r0, r12, r8, asr #1 */
/* @0x2998a8 .word 0xfffffd90 */
/* @0x2998ac strheq r0, [r12], -r12 */
/* @0x2998b0 .word 0xfffffd94 */
/* @0x2998b4 strheq r0, [r12], -r4 */

/* ── FUNC 0x2998b8 · QuitNetworkingFunctions() · size=32 · insn=8 */
/* @0x2998b8 push {r4, lr} */
/* @0x2998bc mov r4, #0 */
/* @0x2998c0 mov r0, r4 */
/* @0x2998c4 add r4, r4, #1 */
/* @0x2998c8 bl 0x299244 <_Z10FreeSocketi> */
/* @0x2998cc cmp r4, #64 */
/* @0x2998d0 bne 0x2998c0 <_Z23QuitNetworkingFunctionsv+0x8> */
/* @0x2998d4 pop {r4, pc} */

/* ── FUNC 0x2998d8 · RelyAckFindClient(char const*, int, int) · size=108 · insn=27 */
/* @0x2998d8 push {r3, r4, r5, r6, r7, lr} */
/* @0x2998dc mov r5, r0 */
/* @0x2998e0 ldr r3, [pc, #0x58] */
/* @0x2998e4 mov r6, r1 */
/* @0x2998e8 mov r7, r2 */
/* @0x2998ec ldr r3, [pc, r3] */
/* @0x2998f0 ldr r4, [r3] */
/* @0x2998f4 cmp r4, #0 */
/* @0x2998f8 bne 0x29990c <_Z17RelyAckFindClientPKcii+0x34> */
/* @0x2998fc b 0x299938 <_Z17RelyAckFindClientPKcii+0x60> */
/* @0x299900 ldr r4, [r4, #0x40c] */
/* @0x299904 cmp r4, #0 */
/* @0x299908 beq 0x299938 <_Z17RelyAckFindClientPKcii+0x60> */
/* @0x29990c ldr r0, [r4] */
/* @0x299910 mov r1, r5 */
/* @0x299914 bl 0xb6574 <strcmp@plt> */
/* @0x299918 cmp r0, #0 */
/* @0x29991c bne 0x299900 <_Z17RelyAckFindClientPKcii+0x28> */
/* @0x299920 ldr r3, [r4, #0x4] */
/* @0x299924 cmp r3, r6 */
/* @0x299928 bne 0x299900 <_Z17RelyAckFindClientPKcii+0x28> */
/* @0x29992c ldr r3, [r4, #0x8] */
/* @0x299930 cmp r3, r7 */
/* @0x299934 bne 0x299900 <_Z17RelyAckFindClientPKcii+0x28> */
/* @0x299938 mov r0, r4 */
/* @0x29993c pop {r3, r4, r5, r6, r7, pc} */
/* @0x299940 ldrsheq r8, [r5], -r12 */

/* ── FUNC 0x299944 · RelyAckNumPackets(SRelyAck*) · size=28 · insn=7 */
/* @0x299944 ldrb r3, [r0, #0x408] */
/* @0x299948 ldrb r2, [r0, #0x409] */
/* @0x29994c cmp r2, r3 */
/* @0x299950 rsblo r3, r3, #255 */
/* @0x299954 addlo r0, r3, r2 */
/* @0x299958 rsbhs r0, r3, r2 */
/* @0x29995c bx lr */

/* ── FUNC 0x299960 · RelyAckClearPackets(SRelyAck*) · size=12 · insn=3 */
/* @0x299960 ldrb r3, [r0, #0x409] */
/* @0x299964 strb r3, [r0, #0x408] */
/* @0x299968 bx lr */

/* ── FUNC 0x29996c · RelyAckBuildPacket(SRelyAck*) · size=144 · insn=36 */
/* @0x29996c push {r4, r5, r6, lr} */
/* @0x299970 mov r4, r0 */
/* @0x299974 bl 0x299944 <_Z17RelyAckNumPacketsP8SRelyAck> */
/* @0x299978 cmp r0, #0 */
/* @0x29997c ble 0x2999f4 <_Z18RelyAckBuildPacketP8SRelyAck+0x88> */
/* @0x299980 mov r1, #3 */
/* @0x299984 mov r2, #1 */
/* @0x299988 lsl r0, r0, #2 */
/* @0x29998c bl 0xc6ad0 <_Z12CreateBufferi14eBuffer_Formati> */
/* @0x299990 mov r5, r0 */
/* @0x299994 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x299998 ldrb r3, [r4, #0x408] */
/* @0x29999c ldrb r2, [r4, #0x409] */
/* @0x2999a0 cmp r2, r3 */
/* @0x2999a4 add r1, r4, r3, lsl #2 */
/* @0x2999a8 mov r6, r0 */
/* @0x2999ac bhs 0x2999dc <_Z18RelyAckBuildPacketP8SRelyAck+0x70> */
/* @0x2999b0 rsb r3, r3, #255 */
/* @0x2999b4 add r1, r1, #12 */
/* @0x2999b8 mov r2, #4 */
/* @0x2999bc bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj> */
/* @0x2999c0 mov r0, r6 */
/* @0x2999c4 add r1, r4, #12 */
/* @0x2999c8 ldrb r3, [r4, #0x409] */
/* @0x2999cc mov r2, #4 */
/* @0x2999d0 bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj> */
/* @0x2999d4 mov r0, r5 */
/* @0x2999d8 pop {r4, r5, r6, pc} */
/* @0x2999dc rsb r3, r3, r2 */
/* @0x2999e0 add r1, r1, #12 */
/* @0x2999e4 mov r2, #4 */
/* @0x2999e8 bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj> */
/* @0x2999ec mov r0, r5 */
/* @0x2999f0 pop {r4, r5, r6, pc} */
/* @0x2999f4 mvn r0, #0 */
/* @0x2999f8 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2999fc · RelyConfig(char*, char*) · size=160 · insn=40 */
/* @0x2999fc push {r3, r4, r5, lr} */
/* @0x299a00 mov r5, r1 */
/* @0x299a04 ldr r1, [pc, #0x80] */
/* @0x299a08 mov r4, r0 */
/* @0x299a0c add r1, pc, r1 */
/* @0x299a10 bl 0xb66d0 <strcasecmp@plt> */
/* @0x299a14 subs r1, r0, #0 */
/* @0x299a18 beq 0x299a60 <_Z10RelyConfigPcS_+0x64> */
/* @0x299a1c ldr r1, [pc, #0x6c] */
/* @0x299a20 mov r0, r4 */
/* @0x299a24 add r1, pc, r1 */
/* @0x299a28 bl 0xb66d0 <strcasecmp@plt> */
/* @0x299a2c subs r1, r0, #0 */
/* @0x299a30 popne {r3, r4, r5, pc} */
/* @0x299a34 mov r0, r5 */
/* @0x299a38 bl 0xb6658 <strtod@plt> */
/* @0x299a3c vmov.f32 s14, #1.000000e+01 */
/* @0x299a40 vmov d6, r0, r1 */
/* @0x299a44 vcvt.f32.f64 s15, d6 */
/* @0x299a48 vcmpe.f32 s15, s14 */
/* @0x299a4c vmrs APSR_nzcv, fpscr */
/* @0x299a50 ldrls r3, [pc, #0x3c] */
/* @0x299a54 ldrls r3, [pc, r3] */
/* @0x299a58 vstrls s15, [r3] */
/* @0x299a5c pop {r3, r4, r5, pc} */
/* @0x299a60 mov r0, r5 */
/* @0x299a64 bl 0xb6658 <strtod@plt> */
/* @0x299a68 vmov.f32 s14, #3.000000e+01 */
/* @0x299a6c vmov d6, r0, r1 */
/* @0x299a70 vcvt.f32.f64 s15, d6 */
/* @0x299a74 vcmpe.f32 s15, s14 */
/* @0x299a78 vmrs APSR_nzcv, fpscr */
/* @0x299a7c ldrls r3, [pc, #0x14] */
/* @0x299a80 ldrls r3, [pc, r3] */
/* @0x299a84 vstrls s15, [r3] */
/* @0x299a88 b 0x299a1c <_Z10RelyConfigPcS_+0x20> */
/* @0x299a8c andeq pc, r11, r12, ror #29 */
/* @0x299a90 andeq pc, r11, r0, ror #29 */
/* @0x299a94 mulseq r5, r8, pc */
/* @0x299a98 andseq r7, r5, r0, ror pc */

/* ── FUNC 0x299a9c · RelyAddPacket(SRelyEntry*) · size=96 · insn=24 */
/* @0x299a9c ldr r3, [pc, #0x4c] */
/* @0x299aa0 ldr r2, [pc, #0x4c] */
/* @0x299aa4 add r3, pc, r3 */
/* @0x299aa8 ldr r2, [r3, r2] */
/* @0x299aac ldr r1, [r2] */
/* @0x299ab0 cmp r1, #0 */
/* @0x299ab4 beq 0x299adc <_Z13RelyAddPacketP10SRelyEntry+0x40> */
/* @0x299ab8 ldr r2, [pc, #0x38] */
/* @0x299abc mov r1, #0 */
/* @0x299ac0 ldr r2, [r3, r2] */
/* @0x299ac4 ldr r3, [r2] */
/* @0x299ac8 str r0, [r2] */
/* @0x299acc str r0, [r3, #0x20] */
/* @0x299ad0 str r3, [r0, #0x24] */
/* @0x299ad4 str r1, [r0, #0x20] */
/* @0x299ad8 bx lr */
/* @0x299adc ldr r1, [pc, #0x14] */
/* @0x299ae0 str r0, [r2] */
/* @0x299ae4 ldr r3, [r3, r1] */
/* @0x299ae8 str r0, [r3] */
/* @0x299aec bx lr */
/* @0x299af0 andseq r8, r5, r12, lsr #3 */
/* @0x299af4 .word 0xfffffda4 */
/* @0x299af8 .word 0xfffffda8 */

/* ── FUNC 0x299afc · RelyAddPacket(int, char const*, int, unsigned int, int) · size=100 · insn=25 */
/* @0x299afc push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x299b00 mov r5, r0 */
/* @0x299b04 mov r6, r1 */
/* @0x299b08 mov r0, #1 */
/* @0x299b0c mov r1, #40 */
/* @0x299b10 mov r9, r3 */
/* @0x299b14 mov r8, r2 */
/* @0x299b18 ldr r7, [sp, #0x20] */
/* @0x299b1c bl 0xb6c34 <calloc@plt> */
/* @0x299b20 str r7, [r0] */
/* @0x299b24 mov r4, r0 */
/* @0x299b28 bl 0x215148 <Timing_Time> */
/* @0x299b2c str r9, [r4, #0x4] */
/* @0x299b30 strd r0, r1, [r4, #24] */
/* @0x299b34 mov r0, r6 */
/* @0x299b38 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x299b3c mov r3, #0 */
/* @0x299b40 str r8, [r4, #0xc] */
/* @0x299b44 str r5, [r4, #0x10] */
/* @0x299b48 str r3, [r4, #0x24] */
/* @0x299b4c str r3, [r4, #0x20] */
/* @0x299b50 str r0, [r4, #0x8] */
/* @0x299b54 mov r0, r4 */
/* @0x299b58 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x299b5c b 0x299a9c <_Z13RelyAddPacketP10SRelyEntry> */

/* ── FUNC 0x299b60 · RelyFindPacket(int) · size=60 · insn=15 */
/* @0x299b60 ldr r3, [pc, #0x30] */
/* @0x299b64 ldr r3, [pc, r3] */
/* @0x299b68 ldr r3, [r3] */
/* @0x299b6c cmp r3, #0 */
/* @0x299b70 bne 0x299b84 <_Z14RelyFindPacketi+0x24> */
/* @0x299b74 b 0x299b90 <_Z14RelyFindPacketi+0x30> */
/* @0x299b78 ldr r3, [r3, #0x20] */
/* @0x299b7c cmp r3, #0 */
/* @0x299b80 beq 0x299b90 <_Z14RelyFindPacketi+0x30> */
/* @0x299b84 ldr r2, [r3] */
/* @0x299b88 cmp r2, r0 */
/* @0x299b8c bne 0x299b78 <_Z14RelyFindPacketi+0x18> */
/* @0x299b90 mov r0, r3 */
/* @0x299b94 bx lr */
/* @0x299b98 mulseq r5, r0, lr */

/* ── FUNC 0x299b9c · RelyRemovePacket(SRelyEntry*) · size=76 · insn=19 */
/* @0x299b9c ldr r3, [pc, #0x3c] */
/* @0x299ba0 ldr r1, [r0, #0x20] */
/* @0x299ba4 ldr r3, [pc, r3] */
/* @0x299ba8 ldr r2, [r0, #0x24] */
/* @0x299bac ldr r12, [r3] */
/* @0x299bb0 cmp r2, #0 */
/* @0x299bb4 strne r1, [r2, #0x20] */
/* @0x299bb8 cmp r1, #0 */
/* @0x299bbc strne r2, [r1, #0x24] */
/* @0x299bc0 cmp r0, r12 */
/* @0x299bc4 streq r1, [r3] */
/* @0x299bc8 ldr r3, [pc, #0x14] */
/* @0x299bcc ldr r3, [pc, r3] */
/* @0x299bd0 ldr r1, [r3] */
/* @0x299bd4 cmp r0, r1 */
/* @0x299bd8 streq r2, [r3] */
/* @0x299bdc bx lr */
/* @0x299be0 andseq r7, r5, r0, asr lr */
/* @0x299be4 andseq r7, r5, r12, lsr #28 */

/* ── FUNC 0x299be8 · RelyDeletePacket(SRelyEntry*) · size=40 · insn=10 */
/* @0x299be8 push {r4, lr} */
/* @0x299bec mov r4, r0 */
/* @0x299bf0 bl 0x299b9c <_Z16RelyRemovePacketP10SRelyEntry> */
/* @0x299bf4 ldr r0, [r4, #0x4] */
/* @0x299bf8 bl 0xc6a88 <_Z11FreeIBufferi> */
/* @0x299bfc ldr r0, [r4, #0x8] */
/* @0x299c00 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x299c04 mov r0, r4 */
/* @0x299c08 pop {r4, lr} */
/* @0x299c0c b 0xb655c <free@plt> */

/* ── FUNC 0x299c10 · RelyDeletePacket(int) · size=36 · insn=9 */
/* @0x299c10 push {r3, lr} */
/* @0x299c14 bl 0x299b60 <_Z14RelyFindPacketi> */
/* @0x299c18 subs r3, r0, #0 */
/* @0x299c1c beq 0x299c2c <_Z16RelyDeletePacketi+0x1c> */
/* @0x299c20 bl 0x299be8 <_Z16RelyDeletePacketP10SRelyEntry> */
/* @0x299c24 mov r0, #1 */
/* @0x299c28 pop {r3, pc} */
/* @0x299c2c mov r0, r3 */
/* @0x299c30 pop {r3, pc} */

/* ── FUNC 0x299c34 · RelyClearList() · size=52 · insn=13 */
/* @0x299c34 ldr r3, [pc, #0x28] */
/* @0x299c38 push {r4, lr} */
/* @0x299c3c ldr r3, [pc, r3] */
/* @0x299c40 ldr r4, [r3] */
/* @0x299c44 cmp r4, #0 */
/* @0x299c48 popeq {r4, pc} */
/* @0x299c4c ldr r4, [r4, #0x20] */
/* @0x299c50 mov r0, r4 */
/* @0x299c54 bl 0x299be8 <_Z16RelyDeletePacketP10SRelyEntry> */
/* @0x299c58 cmp r4, #0 */
/* @0x299c5c bne 0x299c4c <_Z13RelyClearListv+0x18> */
/* @0x299c60 pop {r4, pc} */
/* @0x299c64 ldrheq r7, [r5], -r8 */

/* ── FUNC 0x299c68 · RelySendReliable(int, char const*, int, int, int) · size=312 · insn=78 */
/* @0x299c68 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x299c6c sub sp, sp, #36 */
/* @0x299c70 ldr r12, [pc, #0x124] */
/* @0x299c74 mov r7, r0 */
/* @0x299c78 mov r0, r3 */
/* @0x299c7c ldr r3, [sp, #0x48] */
/* @0x299c80 ldr r12, [pc, r12] */
/* @0x299c84 mov r5, #1 */
/* @0x299c88 add r11, r3, #12 */
/* @0x299c8c mov r10, r1 */
/* @0x299c90 ldr r3, [r12] */
/* @0x299c94 mov r6, #0 */
/* @0x299c98 mov r9, r2 */
/* @0x299c9c str r6, [sp, #0x18] */
/* @0x299ca0 add r2, r3, r5 */
/* @0x299ca4 str r6, [sp, #0x14] */
/* @0x299ca8 str r3, [sp, #0x1c] */
/* @0x299cac str r2, [r12] */
/* @0x299cb0 strb r5, [sp, #0x18] */
/* @0x299cb4 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x299cb8 mov r2, r5 */
/* @0x299cbc mov r1, #3 */
/* @0x299cc0 str r0, [sp, #0xc] */
/* @0x299cc4 mov r0, r11 */
/* @0x299cc8 bl 0xc6ad0 <_Z12CreateBufferi14eBuffer_Formati> */
/* @0x299ccc mov r8, r0 */
/* @0x299cd0 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x299cd4 add r12, sp, #20 */
/* @0x299cd8 mov r2, r5 */
/* @0x299cdc mov r3, #12 */
/* @0x299ce0 str r12, [sp, #0x8] */
/* @0x299ce4 mov r1, r12 */
/* @0x299ce8 mov r4, r0 */
/* @0x299cec bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj> */
/* @0x299cf0 ldr r3, [sp, #0xc] */
/* @0x299cf4 mov r2, r5 */
/* @0x299cf8 mov r0, r4 */
/* @0x299cfc ldr r1, [r3, #0xc] */
/* @0x299d00 ldr r3, [sp, #0x48] */
/* @0x299d04 bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj> */
/* @0x299d08 ldr r0, [r4, #0xc] */
/* @0x299d0c ldr r1, [r4, #0x10] */
/* @0x299d10 add r0, r0, #4 */
/* @0x299d14 sub r1, r1, #4 */
/* @0x299d18 bl 0x27dfa0 <_Z7CalcCRCPKci> */
/* @0x299d1c ldr r3, [r4] */
/* @0x299d20 mov r1, r6 */
/* @0x299d24 mov r2, r6 */
/* @0x299d28 ldr r3, [r3, #0x10] */
/* @0x299d2c str r0, [sp, #0x14] */
/* @0x299d30 mov r0, r4 */
/* @0x299d34 blx r3 */
/* @0x299d38 ldr r12, [sp, #0x8] */
/* @0x299d3c mov r2, r5 */
/* @0x299d40 mov r0, r4 */
/* @0x299d44 mov r3, #12 */
/* @0x299d48 mov r1, r12 */
/* @0x299d4c bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj> */
/* @0x299d50 mov r1, r10 */
/* @0x299d54 mov r2, r9 */
/* @0x299d58 mov r3, r8 */
/* @0x299d5c str r11, [sp] */
/* @0x299d60 mov r0, r7 */
/* @0x299d64 bl 0x299ff8 <_Z12RelySendDataiPKciii> */
/* @0x299d68 ldr r12, [sp, #0x1c] */
/* @0x299d6c mov r1, r10 */
/* @0x299d70 mov r2, r9 */
/* @0x299d74 mov r3, r8 */
/* @0x299d78 str r12, [sp] */
/* @0x299d7c mov r4, r0 */
/* @0x299d80 mov r0, r7 */
/* @0x299d84 bl 0x299afc <_Z13RelyAddPacketiPKciji> */
/* @0x299d88 cmp r4, #12 */
/* @0x299d8c subhi r0, r4, #12 */
/* @0x299d90 mvnls r0, #3 */
/* @0x299d94 add sp, sp, #36 */
/* @0x299d98 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x299d9c andseq r7, r5, r12, ror sp */

/* ── FUNC 0x299da0 · anon_299da0 · size=232 · insn=58 */
/* @0x299da0 push {r4, r5, r6, r7, r8, lr} */
/* @0x299da4 cmp r0, #63 */
/* @0x299da8 sub sp, sp, #16 */
/* @0x299dac mov r4, r0 */
/* @0x299db0 mov r7, r3 */
/* @0x299db4 ldrb r6, [sp, #0x2c] */
/* @0x299db8 bhi 0x299ddc <_Z16RelySendReliableiPKciii+0x174> */
/* @0x299dbc ldr r12, [pc, #0xc0] */
/* @0x299dc0 add r5, r0, r0, lsl #1 */
/* @0x299dc4 ldr r12, [pc, r12] */
/* @0x299dc8 lsl r5, r5, #2 */
/* @0x299dcc add r8, r12, r5 */
/* @0x299dd0 ldrb r3, [r12, r5] */
/* @0x299dd4 cmp r3, #0 */
/* @0x299dd8 bne 0x299de8 <_Z16RelySendReliableiPKciii+0x180> */
/* @0x299ddc vmov.f64 d0, #-1.000000e+00 */
/* @0x299de0 add sp, sp, #16 */
/* @0x299de4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x299de8 mov r0, r7 */
/* @0x299dec str r1, [sp, #0xc] */
/* @0x299df0 str r2, [sp, #0x8] */
/* @0x299df4 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x299df8 ldr r1, [sp, #0xc] */
/* @0x299dfc ldr r2, [sp, #0x8] */
/* @0x299e00 subs r3, r0, #0 */
/* @0x299e04 beq 0x299ddc <_Z16RelySendReliableiPKciii+0x174> */
/* @0x299e08 ldr r0, [r8, #0x4] */
/* @0x299e0c ldr r3, [r3, #0xc] */
/* @0x299e10 cmp r0, #0 */
/* @0x299e14 moveq r12, #0 */
/* @0x299e18 andne r12, r6, #1 */
/* @0x299e1c cmp r12, #0 */
/* @0x299e20 beq 0x299e50 <_Z16RelySendReliableiPKciii+0x1e8> */
/* @0x299e24 ldrb r12, [r0, #0x30] */
/* @0x299e28 cmp r12, #0 */
/* @0x299e2c beq 0x299e58 <_Z16RelySendReliableiPKciii+0x1f0> */
/* @0x299e30 ldr r3, [sp, #0x28] */
/* @0x299e34 mov r0, r4 */
/* @0x299e38 str r3, [sp] */
/* @0x299e3c mov r3, r7 */
/* @0x299e40 bl 0x299c68 <_Z16RelySendReliableiPKciii> */
/* @0x299e44 vmov s15, r0 */
/* @0x299e48 vcvt.f64.s32 d0, s15 */
/* @0x299e4c b 0x299de0 <_Z16RelySendReliableiPKciii+0x178> */
/* @0x299e50 cmp r0, #0 */
/* @0x299e54 beq 0x299e78 <_Z16RelySendReliableiPKciii+0x210> */
/* @0x299e58 ldr r12, [sp, #0x28] */
/* @0x299e5c str r6, [sp, #0x4] */
/* @0x299e60 str r12, [sp] */
/* @0x299e64 bl 0x296a38 <_ZN8yySocket13SendUDPPacketEPciPhib> */
/* @0x299e68 vmov s15, r0 */
/* @0x299e6c vcvt.f64.s32 d0, s15 */
/* @0x299e70 add sp, sp, #16 */
/* @0x299e74 pop {r4, r5, r6, r7, r8, pc} */
/* @0x299e78 ldr r0, [r8, #0x8] */
/* @0x299e7c ldr r0, [r0] */
/* @0x299e80 b 0x299e58 <_Z16RelySendReliableiPKciii+0x1f0> */
/* @0x299e84 andseq r7, r5, r0, ror #23 */

/* ── FUNC 0x299e88 · F_NETWORK_Send_UDP(RValue&, CInstance*, CInstance*, int, RValue*) · size=184 · insn=46 */
/* @0x299e88 ldr r3, [pc, #0xac] */
/* @0x299e8c mov r1, #0 */
/* @0x299e90 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x299e94 ldr r3, [pc, r3] */
/* @0x299e98 str r1, [r0] */
/* @0x299e9c sub sp, sp, #12 */
/* @0x299ea0 ldr r3, [r3] */
/* @0x299ea4 mov r2, r1 */
/* @0x299ea8 mov r4, r0 */
/* @0x299eac movt r2, #0xbff0 */
/* @0x299eb0 sub r3, r3, #2 */
/* @0x299eb4 str r1, [r0, #0xc] */
/* @0x299eb8 cmp r3, #2 */
/* @0x299ebc str r2, [r0, #0x4] */
/* @0x299ec0 ldr r5, [sp, #0x28] */
/* @0x299ec4 bhi 0x299f34 <_Z18F_NETWORK_Send_UDPR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x299ec8 mov r0, r5 */
/* @0x299ecc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x299ed0 mov r1, #1 */
/* @0x299ed4 mov r6, r0 */
/* @0x299ed8 mov r0, r5 */
/* @0x299edc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x299ee0 mov r1, #2 */
/* @0x299ee4 mov r9, r0 */
/* @0x299ee8 mov r0, r5 */
/* @0x299eec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x299ef0 mov r1, #3 */
/* @0x299ef4 mov r8, r0 */
/* @0x299ef8 mov r0, r5 */
/* @0x299efc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x299f00 mov r1, #4 */
/* @0x299f04 mov r7, r0 */
/* @0x299f08 mov r0, r5 */
/* @0x299f0c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x299f10 mov r12, #1 */
/* @0x299f14 mov r1, r9 */
/* @0x299f18 mov r2, r8 */
/* @0x299f1c mov r3, r7 */
/* @0x299f20 stm sp, {r0, r12} */
/* @0x299f24 mov r0, r6 */
/* @0x299f28 bl 0x299da0 <_Z16RelySendReliableiPKciii+0x138> */
/* @0x299f2c vstr s0, [r4] */
/* @0x299f30 vstr s1, [r4, #4] */
/* @0x299f34 add sp, sp, #12 */
/* @0x299f38 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x299f3c andseq r6, r5, r12, lsl #9 */

/* ── FUNC 0x299f40 · F_NETWORK_Send_UDP_Raw(RValue&, CInstance*, CInstance*, int, RValue*) · size=184 · insn=46 */
/* @0x299f40 ldr r3, [pc, #0xac] */
/* @0x299f44 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x299f48 ldr r3, [pc, r3] */
/* @0x299f4c mov r5, #0 */
/* @0x299f50 str r5, [r0] */
/* @0x299f54 ldr r3, [r3] */
/* @0x299f58 sub sp, sp, #8 */
/* @0x299f5c mov r2, r5 */
/* @0x299f60 mov r4, r0 */
/* @0x299f64 sub r3, r3, #2 */
/* @0x299f68 movt r2, #0xbff0 */
/* @0x299f6c cmp r3, #2 */
/* @0x299f70 str r5, [r0, #0xc] */
/* @0x299f74 str r2, [r0, #0x4] */
/* @0x299f78 ldr r6, [sp, #0x28] */
/* @0x299f7c bhi 0x299fec <_Z22F_NETWORK_Send_UDP_RawR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x299f80 mov r1, r5 */
/* @0x299f84 mov r0, r6 */
/* @0x299f88 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x299f8c mov r1, #1 */
/* @0x299f90 mov r7, r0 */
/* @0x299f94 mov r0, r6 */
/* @0x299f98 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x299f9c mov r1, #2 */
/* @0x299fa0 mov r10, r0 */
/* @0x299fa4 mov r0, r6 */
/* @0x299fa8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x299fac mov r1, #3 */
/* @0x299fb0 mov r9, r0 */
/* @0x299fb4 mov r0, r6 */
/* @0x299fb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x299fbc mov r1, #4 */
/* @0x299fc0 mov r8, r0 */
/* @0x299fc4 mov r0, r6 */
/* @0x299fc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x299fcc mov r1, r10 */
/* @0x299fd0 mov r2, r9 */
/* @0x299fd4 mov r3, r8 */
/* @0x299fd8 stm sp, {r0, r5} */
/* @0x299fdc mov r0, r7 */
/* @0x299fe0 bl 0x299da0 <_Z16RelySendReliableiPKciii+0x138> */
/* @0x299fe4 vstr s0, [r4] */
/* @0x299fe8 vstr s1, [r4, #4] */
/* @0x299fec add sp, sp, #8 */
/* @0x299ff0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x299ff4 ldrsbeq r6, [r5], -r8 */

/* ── FUNC 0x299ff8 · RelySendData(int, char const*, int, int, int) · size=192 · insn=48 */
/* @0x299ff8 vmov s13, r0 */
/* @0x299ffc push {r4, lr} */
/* @0x29a000 vcvt.f64.s32 d5, s13 */
/* @0x29a004 sub sp, sp, #112 */
/* @0x29a008 mov r4, #0 */
/* @0x29a00c add r0, sp, #48 */
/* @0x29a010 str r2, [sp, #0xc] */
/* @0x29a014 str r3, [sp, #0x8] */
/* @0x29a018 str r4, [sp, #0x2c] */
/* @0x29a01c vstr d5, [sp, #32] */
/* @0x29a020 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x29a024 ldr r3, [sp, #0x8] */
/* @0x29a028 ldr r2, [sp, #0xc] */
/* @0x29a02c str r4, [sp, #0x4c] */
/* @0x29a030 vmov s11, r3 */
/* @0x29a034 mov r0, r3 */
/* @0x29a038 vmov s15, r2 */
/* @0x29a03c str r4, [sp, #0x5c] */
/* @0x29a040 vcvt.f64.s32 d6, s15 */
/* @0x29a044 vcvt.f64.s32 d7, s11 */
/* @0x29a048 vstr d6, [sp, #64] */
/* @0x29a04c vstr d7, [sp, #80] */
/* @0x29a050 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x29a054 cmp r0, #0 */
/* @0x29a058 beq 0x29a0b0 <_Z12RelySendDataiPKciii+0xb8> */
/* @0x29a05c ldr r3, [sp, #0x78] */
/* @0x29a060 mov r1, #0 */
/* @0x29a064 str r4, [sp, #0x6c] */
/* @0x29a068 add r4, sp, #16 */
/* @0x29a06c cmn r3, #1 */
/* @0x29a070 vldreq s14, [r0, #32] */
/* @0x29a074 vldrne s11, [sp, #120] */
/* @0x29a078 mov r2, r1 */
/* @0x29a07c vcvteq.f64.s32 d7, s14 */
/* @0x29a080 mov r0, r4 */
/* @0x29a084 add r3, sp, #32 */
/* @0x29a088 str r3, [sp] */
/* @0x29a08c mov r3, #5 */
/* @0x29a090 vcvtne.f64.s32 d7, s11 */
/* @0x29a094 vstr d7, [sp, #96] */
/* @0x29a098 bl 0x299f40 <_Z22F_NETWORK_Send_UDP_RawR6RValueP9CInstanceS2_iPS_> */
/* @0x29a09c mov r0, r4 */
/* @0x29a0a0 mov r1, #0 */
/* @0x29a0a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x29a0a8 add sp, sp, #112 */
/* @0x29a0ac pop {r4, pc} */
/* @0x29a0b0 mvn r0, #0 */
/* @0x29a0b4 b 0x29a0a8 <_Z12RelySendDataiPKciii+0xb0> */

/* ── FUNC 0x29a0b8 · RelySendUnreliable(int, char const*, int, int) · size=236 · insn=59 */
/* @0x29a0b8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29a0bc mov r11, r0 */
/* @0x29a0c0 sub sp, sp, #20 */
/* @0x29a0c4 mov r0, r3 */
/* @0x29a0c8 mov r10, r1 */
/* @0x29a0cc mov r9, r2 */
/* @0x29a0d0 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x29a0d4 mov r2, #1 */
/* @0x29a0d8 mov r1, #3 */
/* @0x29a0dc add r8, sp, #8 */
/* @0x29a0e0 mov r5, #0 */
/* @0x29a0e4 mov r6, r0 */
/* @0x29a0e8 ldr r0, [r0, #0x10] */
/* @0x29a0ec add r0, r0, r2 */
/* @0x29a0f0 bl 0xc6ad0 <_Z12CreateBufferi14eBuffer_Formati> */
/* @0x29a0f4 mov r7, r0 */
/* @0x29a0f8 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x29a0fc mov r1, r8 */
/* @0x29a100 mov r2, #1 */
/* @0x29a104 mov r3, #8 */
/* @0x29a108 str r5, [sp, #0x8] */
/* @0x29a10c str r5, [sp, #0xc] */
/* @0x29a110 mov r4, r0 */
/* @0x29a114 bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj> */
/* @0x29a118 ldr r3, [r6, #0x10] */
/* @0x29a11c mov r2, #1 */
/* @0x29a120 ldr r1, [r6, #0xc] */
/* @0x29a124 mov r0, r4 */
/* @0x29a128 bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj> */
/* @0x29a12c ldr r0, [r4, #0xc] */
/* @0x29a130 ldr r1, [r4, #0x10] */
/* @0x29a134 add r0, r0, #4 */
/* @0x29a138 sub r1, r1, #4 */
/* @0x29a13c bl 0x27dfa0 <_Z7CalcCRCPKci> */
/* @0x29a140 ldr r3, [r4] */
/* @0x29a144 mov r1, r5 */
/* @0x29a148 mov r2, r5 */
/* @0x29a14c ldr r3, [r3, #0x10] */
/* @0x29a150 str r0, [sp, #0x8] */
/* @0x29a154 mov r0, r4 */
/* @0x29a158 blx r3 */
/* @0x29a15c mov r1, r8 */
/* @0x29a160 mov r0, r4 */
/* @0x29a164 mov r2, #1 */
/* @0x29a168 mov r3, #8 */
/* @0x29a16c bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj> */
/* @0x29a170 mvn r12, #0 */
/* @0x29a174 mov r1, r10 */
/* @0x29a178 mov r2, r9 */
/* @0x29a17c mov r3, r7 */
/* @0x29a180 str r12, [sp] */
/* @0x29a184 mov r0, r11 */
/* @0x29a188 bl 0x299ff8 <_Z12RelySendDataiPKciii> */
/* @0x29a18c mov r4, r0 */
/* @0x29a190 mov r0, r7 */
/* @0x29a194 bl 0xc6a88 <_Z11FreeIBufferi> */
/* @0x29a198 mov r0, r4 */
/* @0x29a19c add sp, sp, #20 */
/* @0x29a1a0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x29a1a4 · RelySendAckPacket(int, char const*, int, int) · size=292 · insn=73 */
/* @0x29a1a4 ldr r12, [pc, #0x118] */
/* @0x29a1a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29a1ac ldr r12, [pc, r12] */
/* @0x29a1b0 mov r7, r0 */
/* @0x29a1b4 mov r0, r3 */
/* @0x29a1b8 ldr r3, [r12] */
/* @0x29a1bc sub sp, sp, #28 */
/* @0x29a1c0 mov r5, #0 */
/* @0x29a1c4 mov r10, r1 */
/* @0x29a1c8 mov r9, r2 */
/* @0x29a1cc add r1, r3, #1 */
/* @0x29a1d0 str r3, [sp, #0x14] */
/* @0x29a1d4 mov r2, #2 */
/* @0x29a1d8 str r1, [r12] */
/* @0x29a1dc add r11, sp, #12 */
/* @0x29a1e0 str r5, [sp, #0x10] */
/* @0x29a1e4 str r5, [sp, #0xc] */
/* @0x29a1e8 strb r2, [sp, #0x10] */
/* @0x29a1ec bl 0xc6720 <_Z10GetIBufferi> */
/* @0x29a1f0 mov r1, #3 */
/* @0x29a1f4 mov r2, #1 */
/* @0x29a1f8 mov r6, r0 */
/* @0x29a1fc ldr r0, [r0, #0x10] */
/* @0x29a200 add r0, r0, #12 */
/* @0x29a204 bl 0xc6ad0 <_Z12CreateBufferi14eBuffer_Formati> */
/* @0x29a208 mov r8, r0 */
/* @0x29a20c bl 0xc6720 <_Z10GetIBufferi> */
/* @0x29a210 mov r1, r11 */
/* @0x29a214 mov r2, #1 */
/* @0x29a218 mov r3, #12 */
/* @0x29a21c mov r4, r0 */
/* @0x29a220 bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj> */
/* @0x29a224 ldr r3, [r6, #0x10] */
/* @0x29a228 mov r2, #1 */
/* @0x29a22c ldr r1, [r6, #0xc] */
/* @0x29a230 mov r0, r4 */
/* @0x29a234 bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj> */
/* @0x29a238 ldr r0, [r4, #0xc] */
/* @0x29a23c ldr r1, [r4, #0x10] */
/* @0x29a240 add r0, r0, #4 */
/* @0x29a244 sub r1, r1, #4 */
/* @0x29a248 bl 0x27dfa0 <_Z7CalcCRCPKci> */
/* @0x29a24c ldr r3, [r4] */
/* @0x29a250 mov r1, r5 */
/* @0x29a254 mov r2, r5 */
/* @0x29a258 ldr r3, [r3, #0x10] */
/* @0x29a25c str r0, [sp, #0xc] */
/* @0x29a260 mov r0, r4 */
/* @0x29a264 blx r3 */
/* @0x29a268 mov r1, r11 */
/* @0x29a26c mov r0, r4 */
/* @0x29a270 mov r2, #1 */
/* @0x29a274 mov r3, #12 */
/* @0x29a278 bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj> */
/* @0x29a27c mov r1, r10 */
/* @0x29a280 mov r2, r9 */
/* @0x29a284 mov r3, r8 */
/* @0x29a288 mvn r12, #0 */
/* @0x29a28c mov r0, r7 */
/* @0x29a290 str r12, [sp] */
/* @0x29a294 bl 0x299ff8 <_Z12RelySendDataiPKciii> */
/* @0x29a298 ldr r12, [sp, #0x14] */
/* @0x29a29c mov r1, r10 */
/* @0x29a2a0 mov r2, r9 */
/* @0x29a2a4 mov r3, r8 */
/* @0x29a2a8 str r12, [sp] */
/* @0x29a2ac mov r4, r0 */
/* @0x29a2b0 mov r0, r7 */
/* @0x29a2b4 bl 0x299afc <_Z13RelyAddPacketiPKciji> */
/* @0x29a2b8 mov r0, r4 */
/* @0x29a2bc add sp, sp, #28 */
/* @0x29a2c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29a2c4 andseq r7, r5, r0, asr r8 */

/* ── FUNC 0x29a2c8 · RelyAckSendToClient(SRelyAck*) · size=80 · insn=20 */
/* @0x29a2c8 push {r3, r4, r5, lr} */
/* @0x29a2cc mov r4, r0 */
/* @0x29a2d0 bl 0x299944 <_Z17RelyAckNumPacketsP8SRelyAck> */
/* @0x29a2d4 cmp r0, #0 */
/* @0x29a2d8 pople {r3, r4, r5, pc} */
/* @0x29a2dc mov r0, r4 */
/* @0x29a2e0 bl 0x29996c <_Z18RelyAckBuildPacketP8SRelyAck> */
/* @0x29a2e4 ldm r4, {r1, r2} */
/* @0x29a2e8 mov r3, r0 */
/* @0x29a2ec mov r5, r0 */
/* @0x29a2f0 ldr r0, [r4, #0x8] */
/* @0x29a2f4 bl 0x29a1a4 <_Z17RelySendAckPacketiPKcii> */
/* @0x29a2f8 mov r0, r5 */
/* @0x29a2fc bl 0xc6a88 <_Z11FreeIBufferi> */
/* @0x29a300 mov r0, r4 */
/* @0x29a304 bl 0x299960 <_Z19RelyAckClearPacketsP8SRelyAck> */
/* @0x29a308 bl 0x215148 <Timing_Time> */
/* @0x29a30c movw r3, #0x418 */
/* @0x29a310 strd r0, r1, [r4, r3] */
/* @0x29a314 pop {r3, r4, r5, pc} */

/* ── FUNC 0x29a318 · RelyAckAdd(int, char const*, int, unsigned int) · size=404 · insn=101 */
/* @0x29a318 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x29a31c mov r4, r0 */
/* @0x29a320 sub sp, sp, #12 */
/* @0x29a324 mov r0, r1 */
/* @0x29a328 mov r9, r1 */
/* @0x29a32c mov r8, r2 */
/* @0x29a330 mov r1, r2 */
/* @0x29a334 mov r2, r4 */
/* @0x29a338 mov r5, r3 */
/* @0x29a33c bl 0x2998d8 <_Z17RelyAckFindClientPKcii> */
/* @0x29a340 ldr r7, [pc, #0x150] */
/* @0x29a344 add r7, pc, r7 */
/* @0x29a348 subs r6, r0, #0 */
/* @0x29a34c addne lr, r6, #8 */
/* @0x29a350 movne r12, #0 */
/* @0x29a354 bne 0x29a364 <_Z10RelyAckAddiPKcij+0x4c> */
/* @0x29a358 b 0x29a3fc <_Z10RelyAckAddiPKcij+0xe4> */
/* @0x29a35c cmp r12, #255 */
/* @0x29a360 beq 0x29a3ac <_Z10RelyAckAddiPKcij+0x94> */
/* @0x29a364 ldr r4, [lr, #0x4]! */
/* @0x29a368 add r12, r12, #1 */
/* @0x29a36c cmp r4, r5 */
/* @0x29a370 bne 0x29a35c <_Z10RelyAckAddiPKcij+0x44> */
/* @0x29a374 ldr r0, [pc, #0x120] */
/* @0x29a378 mov r2, r5 */
/* @0x29a37c ldr r1, [pc, #0x11c] */
/* @0x29a380 mov r3, r9 */
/* @0x29a384 ldr r0, [r7, r0] */
/* @0x29a388 add r1, pc, r1 */
/* @0x29a38c ldr r0, [r0] */
/* @0x29a390 ldr r12, [r0] */
/* @0x29a394 str r8, [sp] */
/* @0x29a398 ldr r12, [r12, #0xc] */
/* @0x29a39c blx r12 */
/* @0x29a3a0 mov r0, #0 */
/* @0x29a3a4 add sp, sp, #12 */
/* @0x29a3a8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x29a3ac ldrb r2, [r6, #0x409] */
/* @0x29a3b0 movw r1, #0x8081 */
/* @0x29a3b4 movt r1, #0x8080 */
/* @0x29a3b8 add r3, r2, #1 */
/* @0x29a3bc smull r0, r1, r1, r3 */
/* @0x29a3c0 add r1, r1, r3 */
/* @0x29a3c4 add r3, r3, r1, asr #7 */
/* @0x29a3c8 and r3, r3, #255 */
/* @0x29a3cc add r2, r6, r2, lsl #2 */
/* @0x29a3d0 mov r0, r6 */
/* @0x29a3d4 str r5, [r2, #0xc] */
/* @0x29a3d8 strb r3, [r6, #0x409] */
/* @0x29a3dc bl 0x299944 <_Z17RelyAckNumPacketsP8SRelyAck> */
/* @0x29a3e0 cmp r0, #255 */
/* @0x29a3e4 movne r0, #1 */
/* @0x29a3e8 bne 0x29a3a4 <_Z10RelyAckAddiPKcij+0x8c> */
/* @0x29a3ec mov r0, r6 */
/* @0x29a3f0 bl 0x29a2c8 <_Z19RelyAckSendToClientP8SRelyAck> */
/* @0x29a3f4 mov r0, #1 */
/* @0x29a3f8 b 0x29a3a4 <_Z10RelyAckAddiPKcij+0x8c> */
/* @0x29a3fc mov r1, #1056 */
/* @0x29a400 mov r0, #1 */
/* @0x29a404 bl 0xb6c34 <calloc@plt> */
/* @0x29a408 mov r6, r0 */
/* @0x29a40c mov r0, r9 */
/* @0x29a410 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x29a414 str r8, [r6, #0x4] */
/* @0x29a418 str r4, [r6, #0x8] */
/* @0x29a41c str r0, [r6] */
/* @0x29a420 bl 0x215148 <Timing_Time> */
/* @0x29a424 ldr r2, [pc, #0x78] */
/* @0x29a428 movw r12, #0x418 */
/* @0x29a42c mov r3, #0 */
/* @0x29a430 strb r3, [r6, #0x408] */
/* @0x29a434 strb r3, [r6, #0x409] */
/* @0x29a438 strd r0, r1, [r6, r12] */
/* @0x29a43c ldr r0, [r7, r2] */
/* @0x29a440 ldr r1, [r0] */
/* @0x29a444 cmp r1, r3 */
/* @0x29a448 beq 0x29a474 <_Z10RelyAckAddiPKcij+0x15c> */
/* @0x29a44c ldr r1, [pc, #0x54] */
/* @0x29a450 mov r2, r3 */
/* @0x29a454 str r3, [r6, #0x40c] */
/* @0x29a458 mov r3, #1 */
/* @0x29a45c ldr r0, [r7, r1] */
/* @0x29a460 ldr r1, [r0] */
/* @0x29a464 str r6, [r0] */
/* @0x29a468 str r1, [r6, #0x410] */
/* @0x29a46c str r6, [r1, #0x40c] */
/* @0x29a470 b 0x29a3cc <_Z10RelyAckAddiPKcij+0xb4> */
/* @0x29a474 ldr r12, [pc, #0x2c] */
/* @0x29a478 mov r2, r1 */
/* @0x29a47c str r1, [r6, #0x40c] */
/* @0x29a480 mov r3, #1 */
/* @0x29a484 str r1, [r6, #0x410] */
/* @0x29a488 ldr r1, [r7, r12] */
/* @0x29a48c str r6, [r0] */
/* @0x29a490 str r6, [r1] */
/* @0x29a494 b 0x29a3cc <_Z10RelyAckAddiPKcij+0xb4> */
/* @0x29a498 andseq r7, r5, r12, lsl #18 */
/* @0x29a49c .word 0xffffbac4 */
/* @0x29a4a0 andeq pc, r11, r12, lsl #11 */
/* @0x29a4a4 .word 0xfffffd98 */
/* @0x29a4a8 .word 0xfffffdb0 */

/* ── FUNC 0x29a4ac · RelyFilterIncomingPacket(int, unsigned char*, int, char*, int) · size=284 · insn=71 */
/* @0x29a4ac push {r3, r4, r5, r6, r7, lr} */
/* @0x29a4b0 mov r5, r1 */
/* @0x29a4b4 mov r7, r0 */
/* @0x29a4b8 add r0, r1, #4 */
/* @0x29a4bc sub r1, r2, #4 */
/* @0x29a4c0 mov r6, r2 */
/* @0x29a4c4 mov r4, r3 */
/* @0x29a4c8 bl 0x27dfa0 <_Z7CalcCRCPKci> */
/* @0x29a4cc ldr r12, [r5] */
/* @0x29a4d0 cmp r0, r12 */
/* @0x29a4d4 bne 0x29a59c <_Z24RelyFilterIncomingPacketiPhiPci+0xf0> */
/* @0x29a4d8 ldrb r12, [r5, #0x4] */
/* @0x29a4dc cmp r12, #0 */
/* @0x29a4e0 beq 0x29a540 <_Z24RelyFilterIncomingPacketiPhiPci+0x94> */
/* @0x29a4e4 cmp r12, #1 */
/* @0x29a4e8 beq 0x29a548 <_Z24RelyFilterIncomingPacketiPhiPci+0x9c> */
/* @0x29a4ec cmp r12, #2 */
/* @0x29a4f0 bne 0x29a56c <_Z24RelyFilterIncomingPacketiPhiPci+0xc0> */
/* @0x29a4f4 mov r0, r7 */
/* @0x29a4f8 mov r1, r4 */
/* @0x29a4fc ldr r2, [sp, #0x18] */
/* @0x29a500 ldr r3, [r5, #0x8] */
/* @0x29a504 bl 0x29a318 <_Z10RelyAckAddiPKcij> */
/* @0x29a508 cmp r0, #0 */
/* @0x29a50c beq 0x29a538 <_Z24RelyFilterIncomingPacketiPhiPci+0x8c> */
/* @0x29a510 sub r6, r6, #12 */
/* @0x29a514 lsrs r6, r6, #2 */
/* @0x29a518 beq 0x29a538 <_Z24RelyFilterIncomingPacketiPhiPci+0x8c> */
/* @0x29a51c add r5, r5, #8 */
/* @0x29a520 mov r4, #0 */
/* @0x29a524 add r4, r4, #1 */
/* @0x29a528 ldr r0, [r5, #0x4]! */
/* @0x29a52c bl 0x299c10 <_Z16RelyDeletePacketi> */
/* @0x29a530 cmp r6, r4 */
/* @0x29a534 bne 0x29a524 <_Z24RelyFilterIncomingPacketiPhiPci+0x78> */
/* @0x29a538 mov r0, #0 */
/* @0x29a53c pop {r3, r4, r5, r6, r7, pc} */
/* @0x29a540 add r0, r5, #8 */
/* @0x29a544 pop {r3, r4, r5, r6, r7, pc} */
/* @0x29a548 mov r0, r7 */
/* @0x29a54c mov r1, r4 */
/* @0x29a550 ldr r2, [sp, #0x18] */
/* @0x29a554 ldr r3, [r5, #0x8] */
/* @0x29a558 bl 0x29a318 <_Z10RelyAckAddiPKcij> */
/* @0x29a55c cmp r0, #0 */
/* @0x29a560 beq 0x29a538 <_Z24RelyFilterIncomingPacketiPhiPci+0x8c> */
/* @0x29a564 add r0, r5, #12 */
/* @0x29a568 pop {r3, r4, r5, r6, r7, pc} */
/* @0x29a56c ldr r0, [pc, #0x44] */
/* @0x29a570 mov r2, r4 */
/* @0x29a574 ldr r1, [pc, #0x40] */
/* @0x29a578 ldr r3, [sp, #0x18] */
/* @0x29a57c ldr r0, [pc, r0] */
/* @0x29a580 add r1, pc, r1 */
/* @0x29a584 ldr r0, [r0] */
/* @0x29a588 ldr r12, [r0] */
/* @0x29a58c ldr r12, [r12, #0xc] */
/* @0x29a590 blx r12 */
/* @0x29a594 mov r0, #0 */
/* @0x29a598 pop {r3, r4, r5, r6, r7, pc} */
/* @0x29a59c ldr r0, [pc, #0x1c] */
/* @0x29a5a0 mov r2, r4 */
/* @0x29a5a4 ldr r1, [pc, #0x18] */
/* @0x29a5a8 ldr r3, [sp, #0x18] */
/* @0x29a5ac ldr r0, [pc, r0] */
/* @0x29a5b0 add r1, pc, r1 */
/* @0x29a5b4 b 0x29a584 <_Z24RelyFilterIncomingPacketiPhiPci+0xd8> */
/* @0x29a5b8 mulseq r5, r8, r1 */
/* @0x29a5bc andeq pc, r11, r4, lsl #8 */
/* @0x29a5c0 andseq r3, r5, r8, ror #2 */
/* @0x29a5c4 andeq pc, r11, r12, lsl #7 */

/* ── FUNC 0x29a5c8 · RelyTick() · size=412 · insn=103 */
/* @0x29a5c8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x29a5cc vpush {d8} */
/* @0x29a5d0 sub sp, sp, #8 */
/* @0x29a5d4 bl 0x215148 <Timing_Time> */
/* @0x29a5d8 ldr r6, [pc, #0x170] */
/* @0x29a5dc ldr r3, [pc, #0x170] */
/* @0x29a5e0 add r6, pc, r6 */
/* @0x29a5e4 ldr r3, [r6, r3] */
/* @0x29a5e8 ldr r7, [r3] */
/* @0x29a5ec cmp r7, #0 */
/* @0x29a5f0 mov r4, r0 */
/* @0x29a5f4 mov r5, r1 */
/* @0x29a5f8 beq 0x29a658 <_Z8RelyTickv+0x90> */
/* @0x29a5fc ldr r3, [pc, #0x154] */
/* @0x29a600 movw r9, #0x418 */
/* @0x29a604 vldr s16, [pc, #320] */
/* @0x29a608 ldr r8, [r6, r3] */
/* @0x29a60c b 0x29a61c <_Z8RelyTickv+0x54> */
/* @0x29a610 ldr r7, [r7, #0x40c] */
/* @0x29a614 cmp r7, #0 */
/* @0x29a618 beq 0x29a658 <_Z8RelyTickv+0x90> */
/* @0x29a61c ldrd r0, r1, [r7, r9] */
/* @0x29a620 subs r0, r4, r0 */
/* @0x29a624 sbc r1, r5, r1 */
/* @0x29a628 bl 0x319398 <__floatdisf> */
/* @0x29a62c vldr s15, [r8] */
/* @0x29a630 vmov s13, r0 */
/* @0x29a634 vdiv.f32 s14, s13, s16 */
/* @0x29a638 vcmpe.f32 s14, s15 */
/* @0x29a63c vmrs APSR_nzcv, fpscr */
/* @0x29a640 ble 0x29a610 <_Z8RelyTickv+0x48> */
/* @0x29a644 mov r0, r7 */
/* @0x29a648 bl 0x29a2c8 <_Z19RelyAckSendToClientP8SRelyAck> */
/* @0x29a64c ldr r7, [r7, #0x40c] */
/* @0x29a650 cmp r7, #0 */
/* @0x29a654 bne 0x29a61c <_Z8RelyTickv+0x54> */
/* @0x29a658 bl 0x215148 <Timing_Time> */
/* @0x29a65c ldr r3, [pc, #0xf8] */
/* @0x29a660 ldr r3, [r6, r3] */
/* @0x29a664 ldr r7, [r3] */
/* @0x29a668 cmp r7, #0 */
/* @0x29a66c mov r4, r0 */
/* @0x29a670 mov r5, r1 */
/* @0x29a674 beq 0x29a740 <_Z8RelyTickv+0x178> */
/* @0x29a678 ldrd r0, r1, [r7, #24] */
/* @0x29a67c vldr s16, [pc, #200] */
/* @0x29a680 subs r0, r4, r0 */
/* @0x29a684 sbc r1, r5, r1 */
/* @0x29a688 bl 0x319398 <__floatdisf> */
/* @0x29a68c ldr r3, [pc, #0xcc] */
/* @0x29a690 ldr r6, [r6, r3] */
/* @0x29a694 vldr s15, [r6] */
/* @0x29a698 vmov s13, r0 */
/* @0x29a69c vdiv.f32 s14, s13, s16 */
/* @0x29a6a0 vcmpe.f32 s14, s15 */
/* @0x29a6a4 vmrs APSR_nzcv, fpscr */
/* @0x29a6a8 ble 0x29a740 <_Z8RelyTickv+0x178> */
/* @0x29a6ac mvn r8, #0 */
/* @0x29a6b0 mov r9, #0 */
/* @0x29a6b4 b 0x29a6f4 <_Z8RelyTickv+0x12c> */
/* @0x29a6b8 strd r4, r5, [r7, #24] */
/* @0x29a6bc bl 0x299a9c <_Z13RelyAddPacketP10SRelyEntry> */
/* @0x29a6c0 ldr r7, [r7, #0x20] */
/* @0x29a6c4 cmp r7, #0 */
/* @0x29a6c8 beq 0x29a740 <_Z8RelyTickv+0x178> */
/* @0x29a6cc ldrd r0, r1, [r7, #24] */
/* @0x29a6d0 subs r0, r4, r0 */
/* @0x29a6d4 sbc r1, r5, r1 */
/* @0x29a6d8 bl 0x319398 <__floatdisf> */
/* @0x29a6dc vldr s15, [r6] */
/* @0x29a6e0 vmov s13, r0 */
/* @0x29a6e4 vdiv.f32 s14, s13, s16 */
/* @0x29a6e8 vcmpe.f32 s14, s15 */
/* @0x29a6ec vmrs APSR_nzcv, fpscr */
/* @0x29a6f0 ble 0x29a740 <_Z8RelyTickv+0x178> */
/* @0x29a6f4 mov r0, r7 */
/* @0x29a6f8 bl 0x299b9c <_Z16RelyRemovePacketP10SRelyEntry> */
/* @0x29a6fc ldr r0, [r7, #0x10] */
/* @0x29a700 ldr r1, [r7, #0x8] */
/* @0x29a704 ldr r2, [r7, #0xc] */
/* @0x29a708 ldr r3, [r7, #0x4] */
/* @0x29a70c str r8, [sp] */
/* @0x29a710 bl 0x299ff8 <_Z12RelySendDataiPKciii> */
/* @0x29a714 cmp r0, #0 */
/* @0x29a718 mov r0, r7 */
/* @0x29a71c bge 0x29a6b8 <_Z8RelyTickv+0xf0> */
/* @0x29a720 ldr r10, [r7, #0x20] */
/* @0x29a724 mov r0, r7 */
/* @0x29a728 str r9, [r7, #0x24] */
/* @0x29a72c str r9, [r7, #0x20] */
/* @0x29a730 bl 0x299be8 <_Z16RelyDeletePacketP10SRelyEntry> */
/* @0x29a734 mov r7, r10 */
/* @0x29a738 cmp r7, #0 */
/* @0x29a73c bne 0x29a6cc <_Z8RelyTickv+0x104> */
/* @0x29a740 add sp, sp, #8 */
/* @0x29a744 vpop {d8} */
/* @0x29a748 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x29a74c ldmdbmi r4!, {r10, sp} ^ */
/* @0x29a750 andseq r7, r5, r0, ror r6 */
/* @0x29a754 .word 0xfffffd98 */
/* @0x29a758 .word 0xfffffd9c */
/* @0x29a75c .word 0xfffffda4 */
/* @0x29a760 .word 0xfffffda0 */

/* ── FUNC 0x29a764 · ProcessNetworking() · size=216 · insn=54 */
/* @0x29a764 push {r3, r4, r5, lr} */
/* @0x29a768 ldr r5, [pc, #0xc8] */
/* @0x29a76c ldr r5, [pc, r5] */
/* @0x29a770 add r4, r5, #8 */
/* @0x29a774 add r5, r5, #776 */
/* @0x29a778 b 0x29a78c <_Z17ProcessNetworkingv+0x28> */
/* @0x29a77c bl 0x297f98 <_ZN8yyServer7ProcessEv> */
/* @0x29a780 add r4, r4, #12 */
/* @0x29a784 cmp r4, r5 */
/* @0x29a788 beq 0x29a824 <_Z17ProcessNetworkingv+0xc0> */
/* @0x29a78c ldrb r3, [r4, #-0x8] */
/* @0x29a790 cmp r3, #0 */
/* @0x29a794 beq 0x29a780 <_Z17ProcessNetworkingv+0x1c> */
/* @0x29a798 ldr r0, [r4, #-0x4] */
/* @0x29a79c cmp r0, #0 */
/* @0x29a7a0 beq 0x29a7a8 <_Z17ProcessNetworkingv+0x44> */
/* @0x29a7a4 bl 0x294d28 <_ZN8yySocket7ProcessEv> */
/* @0x29a7a8 ldr r0, [r4] */
/* @0x29a7ac cmp r0, #0 */
/* @0x29a7b0 bne 0x29a77c <_Z17ProcessNetworkingv+0x18> */
/* @0x29a7b4 ldr r0, [r4, #-0x4] */
/* @0x29a7b8 cmp r0, #0 */
/* @0x29a7bc beq 0x29a780 <_Z17ProcessNetworkingv+0x1c> */
/* @0x29a7c0 ldr r3, [r0, #0x50] */
/* @0x29a7c4 cmp r3, #0 */
/* @0x29a7c8 beq 0x29a780 <_Z17ProcessNetworkingv+0x1c> */
/* @0x29a7cc ldrb r3, [r4, #-0x7] */
/* @0x29a7d0 cmp r3, #0 */
/* @0x29a7d4 bne 0x29a780 <_Z17ProcessNetworkingv+0x1c> */
/* @0x29a7d8 ldrb r3, [r0, #0x2d] */
/* @0x29a7dc cmp r3, #0 */
/* @0x29a7e0 bne 0x29a780 <_Z17ProcessNetworkingv+0x1c> */
/* @0x29a7e4 ldrb r3, [r0, #0x2f] */
/* @0x29a7e8 cmp r3, #0 */
/* @0x29a7ec bne 0x29a780 <_Z17ProcessNetworkingv+0x1c> */
/* @0x29a7f0 ldr r3, [r0, #0x8] */
/* @0x29a7f4 cmp r3, #0 */
/* @0x29a7f8 beq 0x29a82c <_Z17ProcessNetworkingv+0xc8> */
/* @0x29a7fc cmp r3, #3 */
/* @0x29a800 beq 0x29a82c <_Z17ProcessNetworkingv+0xc8> */
/* @0x29a804 cmp r3, #1 */
/* @0x29a808 beq 0x29a814 <_Z17ProcessNetworkingv+0xb0> */
/* @0x29a80c cmp r3, #4 */
/* @0x29a810 bne 0x29a780 <_Z17ProcessNetworkingv+0x1c> */
/* @0x29a814 add r4, r4, #12 */
/* @0x29a818 bl 0x296cb8 <_ZN8yySocket10ProcessUDPEv> */
/* @0x29a81c cmp r4, r5 */
/* @0x29a820 bne 0x29a78c <_Z17ProcessNetworkingv+0x28> */
/* @0x29a824 pop {r3, r4, r5, lr} */
/* @0x29a828 b 0x29a5c8 <_Z8RelyTickv> */
/* @0x29a82c mov r1, #0 */
/* @0x29a830 bl 0x296e1c <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer> */
/* @0x29a834 b 0x29a780 <_Z17ProcessNetworkingv+0x1c> */
/* @0x29a838 andseq r7, r5, r8, lsr r2 */
