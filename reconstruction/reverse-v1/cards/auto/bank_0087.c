/* libyoyo.so 覆盖卡组 0087
 * 函数 0x1552b4..0x156080，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1552b4 · F_IAP_RestoreAll(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1552b4 str lr, [sp, #-0x4]! */
/* @0x1552b8 sub sp, sp, #12 */
/* @0x1552bc ldr r1, [pc, #0x2c] */
/* @0x1552c0 mov r3, #0 */
/* @0x1552c4 mov r2, #0 */
/* @0x1552c8 str r3, [sp] */
/* @0x1552cc add r1, pc, r1 */
/* @0x1552d0 mov r0, #1 */
/* @0x1552d4 mov r3, #0 */
/* @0x1552d8 movt r3, #0x4010 */
/* @0x1552dc bl 0x154a70 <_Z19YYIAPEventsDispatchv+0xe88> */
/* @0x1552e0 mov r1, #4 */
/* @0x1552e4 add sp, sp, #12 */
/* @0x1552e8 ldr lr, [sp], #4 */
/* @0x1552ec b 0x153acc <_Z16InitIAPFunctionsv+0x5f8> */
/* @0x1552f0 andseq r0, pc, r12, asr lr */

/* ── FUNC 0x1552f4 · F_IAP_ProductDetails(RValue&, CInstance*, CInstance*, int, RValue*) · size=244 · insn=61 */
/* @0x1552f4 push {r4, r5, r6, r7, r8, lr} */
/* @0x1552f8 sub sp, sp, #24 */
/* @0x1552fc mov r3, #0 */
/* @0x155300 mov r4, r0 */
/* @0x155304 ldr r5, [sp, #0x30] */
/* @0x155308 str r3, [r0, #0xc] */
/* @0x15530c str r3, [r0] */
/* @0x155310 str r3, [r0, #0x4] */
/* @0x155314 mov r0, r5 */
/* @0x155318 bl 0x15327c <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x15531c subs r6, r0, #0 */
/* @0x155320 blt 0x15537c <_Z20F_IAP_ProductDetailsR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x155324 ldr r3, [pc, #0xac] */
/* @0x155328 ldr r3, [pc, r3] */
/* @0x15532c ldr r3, [r3] */
/* @0x155330 cmp r6, r3 */
/* @0x155334 bge 0x15537c <_Z20F_IAP_ProductDetailsR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x155338 ldr r7, [pc, #0x9c] */
/* @0x15533c ldr r7, [pc, r7] */
/* @0x155340 ldr r3, [r7, #0x4] */
/* @0x155344 ldr r8, [r3, r6, lsl #2] */
/* @0x155348 ldrb r1, [r8, #0x14] */
/* @0x15534c cmp r1, #0 */
/* @0x155350 beq 0x155384 <_Z20F_IAP_ProductDetailsR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x155354 mov r1, #1 */
/* @0x155358 mov r0, r5 */
/* @0x15535c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x155360 mov r1, r0 */
/* @0x155364 mov r0, r8 */
/* @0x155368 bl 0x18b348 <_ZN11CIAPProduct11PopulateMapEi> */
/* @0x15536c mov r3, #0 */
/* @0x155370 mov r2, r3 */
/* @0x155374 movt r3, #0x3ff0 */
/* @0x155378 stm r4, {r2, r3} */
/* @0x15537c add sp, sp, #24 */
/* @0x155380 pop {r4, r5, r6, r7, r8, pc} */
/* @0x155384 ldr r12, [pc, #0x54] */
/* @0x155388 mov r2, #0 */
/* @0x15538c str r1, [sp] */
/* @0x155390 mov r3, #0 */
/* @0x155394 add r12, pc, r12 */
/* @0x155398 strd r2, r3, [sp, #8] */
/* @0x15539c str r12, [sp, #0x4] */
/* @0x1553a0 mov r2, #0 */
/* @0x1553a4 ldr r12, [r8] */
/* @0x1553a8 mov r0, #2 */
/* @0x1553ac ldr r1, [pc, #0x30] */
/* @0x1553b0 mov r3, #0 */
/* @0x1553b4 movt r3, #0x4008 */
/* @0x1553b8 add r1, pc, r1 */
/* @0x1553bc str r12, [sp, #0x10] */
/* @0x1553c0 bl 0x154a70 <_Z19YYIAPEventsDispatchv+0xe88> */
/* @0x1553c4 mov r1, #3 */
/* @0x1553c8 bl 0x153acc <_Z16InitIAPFunctionsv+0x5f8> */
/* @0x1553cc ldr r3, [r7, #0x4] */
/* @0x1553d0 ldr r8, [r3, r6, lsl #2] */
/* @0x1553d4 b 0x155354 <_Z20F_IAP_ProductDetailsR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x1553d8 eoreq r10, r9, r8, lsr #15 */
/* @0x1553dc mlaeq r9, r8, r7, r10 */
/* @0x1553e0 mulseq pc, r12, sp */
/* @0x1553e4 andseq r0, pc, r0, ror sp */

/* ── FUNC 0x1553e8 · YYIAPProductDetailsReceived(char const*) · size=196 · insn=49 */
/* @0x1553e8 ldr r3, [pc, #0xa4] */
/* @0x1553ec push {r4, lr} */
/* @0x1553f0 add r3, pc, r3 */
/* @0x1553f4 sub sp, sp, #24 */
/* @0x1553f8 mov r4, r0 */
/* @0x1553fc ldr r0, [r3] */
/* @0x155400 bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0x155404 mov r0, r4 */
/* @0x155408 bl 0x28075c <json_tokener_parse> */
/* @0x15540c cmn r0, #4000 */
/* @0x155410 bls 0x15544c <_Z27YYIAPProductDetailsReceivedPKc+0x64> */
/* @0x155414 ldr r3, [pc, #0x7c] */
/* @0x155418 mov r2, r4 */
/* @0x15541c ldr r1, [pc, #0x78] */
/* @0x155420 ldr r3, [pc, r3] */
/* @0x155424 add r1, pc, r1 */
/* @0x155428 ldr r0, [r3] */
/* @0x15542c ldr r3, [r0] */
/* @0x155430 ldr r3, [r3, #0xc] */
/* @0x155434 blx r3 */
/* @0x155438 ldr r3, [pc, #0x60] */
/* @0x15543c ldr r0, [pc, r3] */
/* @0x155440 add sp, sp, #24 */
/* @0x155444 pop {r4, lr} */
/* @0x155448 b 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0x15544c vmov s13, r0 */
/* @0x155450 ldr r2, [pc, #0x4c] */
/* @0x155454 ldr r1, [pc, #0x4c] */
/* @0x155458 mov r3, #0 */
/* @0x15545c vcvt.f64.s32 d7, s13 */
/* @0x155460 add r2, pc, r2 */
/* @0x155464 str r3, [sp] */
/* @0x155468 add r1, pc, r1 */
/* @0x15546c str r2, [sp, #0x4] */
/* @0x155470 mov r0, #2 */
/* @0x155474 str r3, [sp, #0x10] */
/* @0x155478 mov r2, #0 */
/* @0x15547c mov r3, #0 */
/* @0x155480 movt r3, #0x3ff0 */
/* @0x155484 vstr d7, [sp, #8] */
/* @0x155488 bl 0x154a70 <_Z19YYIAPEventsDispatchv+0xe88> */
/* @0x15548c bl 0x1531cc <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x1d8> */
/* @0x155490 b 0x155438 <_Z27YYIAPProductDetailsReceivedPKc+0x50> */
/* @0x155494 eorseq pc, r2, r0, asr r6 */
/* @0x155498 eoreq r8, r9, r0, lsr #10 */
/* @0x15549c ldrsheq r0, [pc], -r4 */
/* @0x1554a0 eorseq pc, r2, r4, lsl #12 */
/* @0x1554a4 andseq r0, pc, r0, lsr #27 */
/* @0x1554a8 andseq r0, pc, r0, asr #25 */

/* ── FUNC 0x1554ac · YYIAPPurchaseEvent(char const*) · size=192 · insn=48 */
/* @0x1554ac ldr r3, [pc, #0xa0] */
/* @0x1554b0 push {r4, lr} */
/* @0x1554b4 add r3, pc, r3 */
/* @0x1554b8 sub sp, sp, #24 */
/* @0x1554bc mov r4, r0 */
/* @0x1554c0 ldr r0, [r3] */
/* @0x1554c4 bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0x1554c8 mov r0, r4 */
/* @0x1554cc bl 0x28075c <json_tokener_parse> */
/* @0x1554d0 cmn r0, #4000 */
/* @0x1554d4 bls 0x155510 <_Z18YYIAPPurchaseEventPKc+0x64> */
/* @0x1554d8 ldr r3, [pc, #0x78] */
/* @0x1554dc mov r2, r4 */
/* @0x1554e0 ldr r1, [pc, #0x74] */
/* @0x1554e4 ldr r3, [pc, r3] */
/* @0x1554e8 add r1, pc, r1 */
/* @0x1554ec ldr r0, [r3] */
/* @0x1554f0 ldr r3, [r0] */
/* @0x1554f4 ldr r3, [r3, #0xc] */
/* @0x1554f8 blx r3 */
/* @0x1554fc ldr r3, [pc, #0x5c] */
/* @0x155500 ldr r0, [pc, r3] */
/* @0x155504 add sp, sp, #24 */
/* @0x155508 pop {r4, lr} */
/* @0x15550c b 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0x155510 vmov s13, r0 */
/* @0x155514 ldr r2, [pc, #0x48] */
/* @0x155518 ldr r1, [pc, #0x48] */
/* @0x15551c mov r3, #0 */
/* @0x155520 vcvt.f64.s32 d7, s13 */
/* @0x155524 add r2, pc, r2 */
/* @0x155528 str r3, [sp] */
/* @0x15552c add r1, pc, r1 */
/* @0x155530 str r2, [sp, #0x4] */
/* @0x155534 mov r0, #2 */
/* @0x155538 str r3, [sp, #0x10] */
/* @0x15553c mov r2, #0 */
/* @0x155540 mov r3, #1073741824 */
/* @0x155544 vstr d7, [sp, #8] */
/* @0x155548 bl 0x154a70 <_Z19YYIAPEventsDispatchv+0xe88> */
/* @0x15554c bl 0x1531cc <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x1d8> */
/* @0x155550 b 0x1554fc <_Z18YYIAPPurchaseEventPKc+0x50> */
/* @0x155554 eorseq pc, r2, r12, lsl #11 */
/* @0x155558 eoreq r8, r9, r12, asr r4 */
/* @0x15555c andseq r0, pc, r8, ror #28 */
/* @0x155560 eorseq pc, r2, r0, asr #10 */
/* @0x155564 ldrsbeq r0, [pc], -r12 */
/* @0x155568 ldrsheq r0, [pc], -r12 */

/* ── FUNC 0x15556c · YYIAPConsumeEvent(char const*) · size=196 · insn=49 */
/* @0x15556c ldr r3, [pc, #0xa4] */
/* @0x155570 push {r4, lr} */
/* @0x155574 add r3, pc, r3 */
/* @0x155578 sub sp, sp, #24 */
/* @0x15557c mov r4, r0 */
/* @0x155580 ldr r0, [r3] */
/* @0x155584 bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0x155588 mov r0, r4 */
/* @0x15558c bl 0x28075c <json_tokener_parse> */
/* @0x155590 cmn r0, #4000 */
/* @0x155594 bls 0x1555d0 <_Z17YYIAPConsumeEventPKc+0x64> */
/* @0x155598 ldr r3, [pc, #0x7c] */
/* @0x15559c mov r2, r4 */
/* @0x1555a0 ldr r1, [pc, #0x78] */
/* @0x1555a4 ldr r3, [pc, r3] */
/* @0x1555a8 add r1, pc, r1 */
/* @0x1555ac ldr r0, [r3] */
/* @0x1555b0 ldr r3, [r0] */
/* @0x1555b4 ldr r3, [r3, #0xc] */
/* @0x1555b8 blx r3 */
/* @0x1555bc ldr r3, [pc, #0x60] */
/* @0x1555c0 ldr r0, [pc, r3] */
/* @0x1555c4 add sp, sp, #24 */
/* @0x1555c8 pop {r4, lr} */
/* @0x1555cc b 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0x1555d0 vmov s13, r0 */
/* @0x1555d4 ldr r2, [pc, #0x4c] */
/* @0x1555d8 ldr r1, [pc, #0x4c] */
/* @0x1555dc mov r3, #0 */
/* @0x1555e0 vcvt.f64.s32 d7, s13 */
/* @0x1555e4 add r2, pc, r2 */
/* @0x1555e8 str r3, [sp] */
/* @0x1555ec add r1, pc, r1 */
/* @0x1555f0 str r2, [sp, #0x4] */
/* @0x1555f4 mov r0, #2 */
/* @0x1555f8 str r3, [sp, #0x10] */
/* @0x1555fc mov r2, #0 */
/* @0x155600 mov r3, #0 */
/* @0x155604 movt r3, #0x4008 */
/* @0x155608 vstr d7, [sp, #8] */
/* @0x15560c bl 0x154a70 <_Z19YYIAPEventsDispatchv+0xe88> */
/* @0x155610 bl 0x1531cc <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x1d8> */
/* @0x155614 b 0x1555bc <_Z17YYIAPConsumeEventPKc+0x50> */
/* @0x155618 eorseq pc, r2, r12, asr #9 */
/* @0x15561c mlaeq r9, r12, r3, r8 */
/* @0x155620 ldrsbeq r0, [pc], -r12 */
/* @0x155624 eorseq pc, r2, r0, lsl #9 */
/* @0x155628 andseq r0, pc, r12, lsl r12 */
/* @0x15562c andseq r0, pc, r12, lsr r11 */

/* ── FUNC 0x155630 · YYIAPStoreLoadEvent(int) · size=120 · insn=30 */
/* @0x155630 push {r4, r5, lr} */
/* @0x155634 mov r5, r0 */
/* @0x155638 ldr r4, [pc, #0x5c] */
/* @0x15563c sub sp, sp, #28 */
/* @0x155640 add r4, pc, r4 */
/* @0x155644 ldr r0, [r4] */
/* @0x155648 bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0x15564c vmov s13, r5 */
/* @0x155650 ldr r2, [pc, #0x48] */
/* @0x155654 mov r3, #0 */
/* @0x155658 vcvt.f64.s32 d7, s13 */
/* @0x15565c ldr r1, [pc, #0x40] */
/* @0x155660 str r3, [sp] */
/* @0x155664 add r2, pc, r2 */
/* @0x155668 str r3, [sp, #0x10] */
/* @0x15566c add r1, pc, r1 */
/* @0x155670 str r2, [sp, #0x4] */
/* @0x155674 mov r3, #0 */
/* @0x155678 mov r2, #0 */
/* @0x15567c mov r0, #2 */
/* @0x155680 vstr d7, [sp, #8] */
/* @0x155684 bl 0x154a70 <_Z19YYIAPEventsDispatchv+0xe88> */
/* @0x155688 bl 0x1531cc <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x1d8> */
/* @0x15568c ldr r0, [r4] */
/* @0x155690 add sp, sp, #28 */
/* @0x155694 pop {r4, r5, lr} */
/* @0x155698 b 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0x15569c eorseq pc, r2, r0, lsl #8 */
/* @0x1556a0 andseq r11, sp, r12, ror #7 */
/* @0x1556a4 ldrheq r0, [pc], -r12 */

/* ── FUNC 0x1556a8 · YYIAPRestoreEvent(int) · size=124 · insn=31 */
/* @0x1556a8 push {r4, r5, lr} */
/* @0x1556ac mov r5, r0 */
/* @0x1556b0 ldr r4, [pc, #0x60] */
/* @0x1556b4 sub sp, sp, #28 */
/* @0x1556b8 add r4, pc, r4 */
/* @0x1556bc ldr r0, [r4] */
/* @0x1556c0 bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0x1556c4 vmov s13, r5 */
/* @0x1556c8 ldr r2, [pc, #0x4c] */
/* @0x1556cc mov r3, #0 */
/* @0x1556d0 vcvt.f64.s32 d7, s13 */
/* @0x1556d4 ldr r1, [pc, #0x44] */
/* @0x1556d8 str r3, [sp] */
/* @0x1556dc add r2, pc, r2 */
/* @0x1556e0 str r3, [sp, #0x10] */
/* @0x1556e4 add r1, pc, r1 */
/* @0x1556e8 str r2, [sp, #0x4] */
/* @0x1556ec mov r0, #2 */
/* @0x1556f0 mov r2, #0 */
/* @0x1556f4 mov r3, #0 */
/* @0x1556f8 movt r3, #0x4010 */
/* @0x1556fc vstr d7, [sp, #8] */
/* @0x155700 bl 0x154a70 <_Z19YYIAPEventsDispatchv+0xe88> */
/* @0x155704 bl 0x1531cc <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x1d8> */
/* @0x155708 ldr r0, [r4] */
/* @0x15570c add sp, sp, #28 */
/* @0x155710 pop {r4, r5, lr} */
/* @0x155714 b 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0x155718 eorseq pc, r2, r8, lsl #7 */
/* @0x15571c andseq r1, lr, r12, ror r8 */
/* @0x155720 andseq r0, pc, r4, asr #20 */

/* ── FUNC 0x155724 · F_IAP_EnumerateProducts(RValue&, CInstance*, CInstance*, int, RValue*) · size=272 · insn=68 */
/* @0x155724 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x155728 sub sp, sp, #20 */
/* @0x15572c mov r1, #0 */
/* @0x155730 ldr r0, [sp, #0x30] */
/* @0x155734 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x155738 ldr r3, [pc, #0xdc] */
/* @0x15573c add r3, pc, r3 */
/* @0x155740 cmp r0, #0 */
/* @0x155744 blt 0x155804 <_Z23F_IAP_EnumerateProductsR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x155748 ldr r2, [pc, #0xd0] */
/* @0x15574c ldr r2, [r3, r2] */
/* @0x155750 ldr r2, [r2] */
/* @0x155754 cmp r0, r2 */
/* @0x155758 bge 0x155804 <_Z23F_IAP_EnumerateProductsR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x15575c ldr r2, [pc, #0xc0] */
/* @0x155760 lsl r8, r0, #2 */
/* @0x155764 ldr r6, [r3, r2] */
/* @0x155768 ldr r2, [r6, #0x4] */
/* @0x15576c ldr r2, [r2, r0, lsl #2] */
/* @0x155770 cmp r2, #0 */
/* @0x155774 beq 0x155804 <_Z23F_IAP_EnumerateProductsR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x155778 ldr r2, [pc, #0xa8] */
/* @0x15577c ldr r7, [r3, r2] */
/* @0x155780 ldr r2, [r7] */
/* @0x155784 cmp r2, #0 */
/* @0x155788 ble 0x1557fc <_Z23F_IAP_EnumerateProductsR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x15578c ldr r2, [pc, #0x98] */
/* @0x155790 mov r4, #0 */
/* @0x155794 ldr r9, [r3, r2] */
/* @0x155798 b 0x1557a8 <_Z23F_IAP_EnumerateProductsR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x15579c ldr r3, [r7] */
/* @0x1557a0 cmp r3, r4 */
/* @0x1557a4 ble 0x1557fc <_Z23F_IAP_EnumerateProductsR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x1557a8 ldr r3, [r9, #0x4] */
/* @0x1557ac mov r0, sp */
/* @0x1557b0 ldr r3, [r3, r4, lsl #2] */
/* @0x1557b4 add r4, r4, #1 */
/* @0x1557b8 ldr r1, [r3] */
/* @0x1557bc bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x1557c0 ldr r3, [r6, #0x4] */
/* @0x1557c4 mov r1, sp */
/* @0x1557c8 ldr r0, [r3, r8] */
/* @0x1557cc bl 0x205d18 <_ZN8CDS_List3AddEP6RValue> */
/* @0x1557d0 ldr r3, [sp, #0xc] */
/* @0x1557d4 sub r3, r3, #1 */
/* @0x1557d8 bic r3, r3, #-16777216 */
/* @0x1557dc bic r3, r3, #3 */
/* @0x1557e0 cmp r3, #0 */
/* @0x1557e4 bne 0x15579c <_Z23F_IAP_EnumerateProductsR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1557e8 mov r0, sp */
/* @0x1557ec bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1557f0 ldr r3, [r7] */
/* @0x1557f4 cmp r3, r4 */
/* @0x1557f8 bgt 0x1557a8 <_Z23F_IAP_EnumerateProductsR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x1557fc add sp, sp, #20 */
/* @0x155800 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x155804 ldr r0, [pc, #0x24] */
/* @0x155808 mov r1, #0 */
/* @0x15580c add r0, pc, r0 */
/* @0x155810 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x155814 add sp, sp, #20 */
/* @0x155818 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x15581c eoreq r12, r9, r4, lsl r5 */
/* @0x155820 .word 0xffffc02c */
/* @0x155824 .word 0xffffc030 */
/* @0x155828 .word 0xffffde80 */
/* @0x15582c .word 0xffffde84 */
/* @0x155830 ldrsheq r2, [lr], -r0 */

/* ── FUNC 0x155834 · F_Push_GetFirstLocalNotification(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x155834 push {r4, r5, r6, r8, r9, lr} */
/* @0x155838 sub sp, sp, #24 */
/* @0x15583c mov r5, #0 */
/* @0x155840 mov r4, r0 */
/* @0x155844 str r5, [r0, #0xc] */
/* @0x155848 mov r3, r5 */
/* @0x15584c str r5, [r0] */
/* @0x155850 movt r3, #0xbff0 */
/* @0x155854 mov r1, r5 */
/* @0x155858 str r3, [r0, #0x4] */
/* @0x15585c ldr r0, [sp, #0x30] */
/* @0x155860 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x155864 subs r6, r0, #0 */
/* @0x155868 blt 0x15589c <_Z32F_Push_GetFirstLocalNotificationR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x15586c vmov s13, r6 */
/* @0x155870 add r12, sp, #24 */
/* @0x155874 mov r1, r5 */
/* @0x155878 mov r2, r5 */
/* @0x15587c vcvt.f64.s32 d7, s13 */
/* @0x155880 mov r3, #1 */
/* @0x155884 str r5, [sp, #0x14] */
/* @0x155888 vmov r8, r9, d7 */
/* @0x15588c strd r8, r9, [r12, #-16]! */
/* @0x155890 mov r0, r12 */
/* @0x155894 str r12, [sp] */
/* @0x155898 bl 0xfed40 <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_> */
/* @0x15589c ldr r2, [pc, #0x34] */
/* @0x1558a0 mov r3, #0 */
/* @0x1558a4 mov r1, r6 */
/* @0x1558a8 mov r0, r3 */
/* @0x1558ac add r2, pc, r2 */
/* @0x1558b0 str r3, [r2] */
/* @0x1558b4 bl 0x161c00 <_Z25Push_GetLocalNotificationii> */
/* @0x1558b8 vmov s15, r0 */
/* @0x1558bc vcvt.f64.s32 d7, s15 */
/* @0x1558c0 vmov r0, r1, d7 */
/* @0x1558c4 vmov r2, s14 */
/* @0x1558c8 mov r3, r1 */
/* @0x1558cc stm r4, {r2, r3} */
/* @0x1558d0 add sp, sp, #24 */
/* @0x1558d4 pop {r4, r5, r6, r8, r9, pc} */
/* @0x1558d8 eoreq r12, r9, r8, lsr #21 */

/* ── FUNC 0x1558dc · F_Push_GetNextLocalNotification(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x1558dc push {r4, r5, r6, r8, r9, lr} */
/* @0x1558e0 sub sp, sp, #24 */
/* @0x1558e4 mov r5, #0 */
/* @0x1558e8 mov r4, r0 */
/* @0x1558ec str r5, [r0, #0xc] */
/* @0x1558f0 mov r3, r5 */
/* @0x1558f4 str r5, [r0] */
/* @0x1558f8 movt r3, #0xbff0 */
/* @0x1558fc mov r1, r5 */
/* @0x155900 str r3, [r0, #0x4] */
/* @0x155904 ldr r0, [sp, #0x30] */
/* @0x155908 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x15590c subs r6, r0, #0 */
/* @0x155910 blt 0x155944 <_Z31F_Push_GetNextLocalNotificationR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x155914 vmov s13, r6 */
/* @0x155918 add r12, sp, #24 */
/* @0x15591c mov r1, r5 */
/* @0x155920 mov r2, r5 */
/* @0x155924 vcvt.f64.s32 d7, s13 */
/* @0x155928 mov r3, #1 */
/* @0x15592c str r5, [sp, #0x14] */
/* @0x155930 vmov r8, r9, d7 */
/* @0x155934 strd r8, r9, [r12, #-16]! */
/* @0x155938 mov r0, r12 */
/* @0x15593c str r12, [sp] */
/* @0x155940 bl 0xfed40 <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_> */
/* @0x155944 ldr r3, [pc, #0x34] */
/* @0x155948 mov r1, r6 */
/* @0x15594c add r3, pc, r3 */
/* @0x155950 ldr r0, [r3] */
/* @0x155954 add r0, r0, #1 */
/* @0x155958 str r0, [r3] */
/* @0x15595c bl 0x161c00 <_Z25Push_GetLocalNotificationii> */
/* @0x155960 vmov s15, r0 */
/* @0x155964 vcvt.f64.s32 d7, s15 */
/* @0x155968 vmov r0, r1, d7 */
/* @0x15596c vmov r2, s14 */
/* @0x155970 mov r3, r1 */
/* @0x155974 stm r4, {r2, r3} */
/* @0x155978 add sp, sp, #24 */
/* @0x15597c pop {r4, r5, r6, r8, r9, pc} */
/* @0x155980 eoreq r12, r9, r8, lsl #20 */

/* ── FUNC 0x155984 · anon_155984 · size=4 · insn=1 */
/* @0x155984 andeq r0, r0, r0 */

/* ── FUNC 0x155988 · F_Push_LocalNotification(RValue&, CInstance*, CInstance*, int, RValue*) · size=348 · insn=85 */
/* @0x155988 push {r4, r5, r6, r7, lr} */
/* @0x15598c vpush {d8, d9} */
/* @0x155990 mov r4, #0 */
/* @0x155994 ldr r6, [pc, #0x134] */
/* @0x155998 sub sp, sp, #28 */
/* @0x15599c ldr r3, [pc, #0x130] */
/* @0x1559a0 mov r5, r0 */
/* @0x1559a4 add r6, pc, r6 */
/* @0x1559a8 str r4, [r0] */
/* @0x1559ac str r4, [r0, #0xc] */
/* @0x1559b0 str r4, [r0, #0x4] */
/* @0x1559b4 ldr r3, [r6, r3] */
/* @0x1559b8 ldr r7, [sp, #0x40] */
/* @0x1559bc ldrb r3, [r3] */
/* @0x1559c0 cmp r3, r4 */
/* @0x1559c4 beq 0x155a94 <_Z24F_Push_LocalNotificationR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x1559c8 mov r0, r7 */
/* @0x1559cc mov r1, r4 */
/* @0x1559d0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1559d4 mov r2, r4 */
/* @0x1559d8 str r4, [sp] */
/* @0x1559dc mov r3, r4 */
/* @0x1559e0 vmov d9, r0, r1 */
/* @0x1559e4 add r0, sp, #8 */
/* @0x1559e8 mov r1, r4 */
/* @0x1559ec bl 0x114ed8 <_Z21F_DateCurrentDateTimeR6RValueP9CInstanceS2_iPS_> */
/* @0x1559f0 vldr d7, [sp, #8] */
/* @0x1559f4 vsub.f64 d8, d9, d7 */
/* @0x1559f8 vldr d6, [pc, #192] */
/* @0x1559fc ldr r3, [pc, #0xd4] */
/* @0x155a00 ldr r1, [pc, #0xd4] */
/* @0x155a04 ldr r3, [r6, r3] */
/* @0x155a08 add r1, pc, r1 */
/* @0x155a0c ldr r0, [r3] */
/* @0x155a10 vmul.f64 d8, d8, d6 */
/* @0x155a14 ldr r3, [r0] */
/* @0x155a18 ldr r3, [r3, #0xc] */
/* @0x155a1c vcmpe.f64 d8, #0 */
/* @0x155a20 vmrs APSR_nzcv, fpscr */
/* @0x155a24 vcvtpl.s32.f64 s15, d8 */
/* @0x155a28 movmi r2, r4 */
/* @0x155a2c vldrmi d8, [pc, #148] */
/* @0x155a30 vmovpl r2, s15 */
/* @0x155a34 blx r3 */
/* @0x155a38 mov r0, r7 */
/* @0x155a3c mov r1, #1 */
/* @0x155a40 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x155a44 mov r1, #2 */
/* @0x155a48 mov r6, r0 */
/* @0x155a4c mov r0, r7 */
/* @0x155a50 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x155a54 mov r1, #3 */
/* @0x155a58 mov r4, r0 */
/* @0x155a5c mov r0, r7 */
/* @0x155a60 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x155a64 mov r2, r6 */
/* @0x155a68 mov r3, r4 */
/* @0x155a6c str r0, [sp] */
/* @0x155a70 vmov r0, r1, d8 */
/* @0x155a74 bl 0x161b4c <_Z26Push_SendLocalNotificationdPKcS0_S0_> */
/* @0x155a78 mov r3, #0 */
/* @0x155a7c mov r2, r3 */
/* @0x155a80 movt r3, #0x3ff0 */
/* @0x155a84 stm r5, {r2, r3} */
/* @0x155a88 add sp, sp, #28 */
/* @0x155a8c vpop {d8, d9} */
/* @0x155a90 pop {r4, r5, r6, r7, pc} */
/* @0x155a94 ldr r3, [pc, #0x3c] */
/* @0x155a98 ldr r1, [pc, #0x40] */
/* @0x155a9c ldr r3, [r6, r3] */
/* @0x155aa0 add r1, pc, r1 */
/* @0x155aa4 ldr r0, [r3] */
/* @0x155aa8 ldr r3, [r0] */
/* @0x155aac ldr r3, [r3, #0xc] */
/* @0x155ab0 blx r3 */
/* @0x155ab4 add sp, sp, #28 */
/* @0x155ab8 vpop {d8, d9} */
/* @0x155abc pop {r4, r5, r6, r7, pc} */
/* @0x155ac0 andeq r0, r0, r0 */
/* @0x155ac4 rscsmi r1, r5, r0, lsl #16 */
/* @0x155ad0 eoreq r12, r9, r12, lsr #5 */
/* @0x155ad4 .word 0xffffdec0 */
/* @0x155ad8 .word 0xffffbac4 */
/* @0x155adc andseq r0, pc, r12, lsr #19 */
/* @0x155ae0 andseq r0, pc, r0, asr #18 */

/* ── FUNC 0x155ae4 · anon_155ae4 · size=4 · insn=1 */
/* @0x155ae4 nop */

/* ── FUNC 0x155ae8 · F_Push_CancelLocalNotification(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x155ae8 push {r4, lr} */
/* @0x155aec mov r1, #0 */
/* @0x155af0 mov r3, r1 */
/* @0x155af4 str r1, [r0, #0xc] */
/* @0x155af8 movt r3, #0xbff0 */
/* @0x155afc mov r4, r0 */
/* @0x155b00 stm r0, {r1, r3} */
/* @0x155b04 ldr r0, [sp, #0x8] */
/* @0x155b08 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x155b0c bl 0x161c48 <_Z28Push_CancelLocalNotificationi> */
/* @0x155b10 vmov s15, r0 */
/* @0x155b14 vcvt.f64.s32 d7, s15 */
/* @0x155b18 vmov r0, r1, d7 */
/* @0x155b1c vmov r2, s14 */
/* @0x155b20 vcmp.f64 d7, #0 */
/* @0x155b24 vmrs APSR_nzcv, fpscr */
/* @0x155b28 mov r3, r1 */
/* @0x155b2c stm r4, {r2, r3} */
/* @0x155b30 popeq {r4, pc} */
/* @0x155b34 ldr r3, [pc, #0x10] */
/* @0x155b38 add r3, pc, r3 */
/* @0x155b3c ldr r2, [r3] */
/* @0x155b40 sub r2, r2, #1 */
/* @0x155b44 str r2, [r3] */
/* @0x155b48 pop {r4, pc} */
/* @0x155b4c eoreq r12, r9, r12, lsl r8 */

/* ── FUNC 0x155b50 · SPushNotificationEvent::SPushNotificationEvent(int, ePushEventType, char const*) · size=48 · insn=12 */
/* @0x155b50 push {r4, lr} */
/* @0x155b54 mov r4, r0 */
/* @0x155b58 str r1, [r0, #0x4] */
/* @0x155b5c mov r12, #0 */
/* @0x155b60 mov r0, r3 */
/* @0x155b64 str r2, [r4, #0x8] */
/* @0x155b68 str r12, [r4] */
/* @0x155b6c str r12, [r4, #0xc] */
/* @0x155b70 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x155b74 str r0, [r4, #0xc] */
/* @0x155b78 mov r0, r4 */
/* @0x155b7c pop {r4, pc} */

/* ── FUNC 0x155b50 · SPushNotificationEvent::SPushNotificationEvent(int, ePushEventType, char const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x155b80 · SPushNotificationEvent::~SPushNotificationEvent() · size=32 · insn=8 */
/* @0x155b80 push {r4, lr} */
/* @0x155b84 mov r4, r0 */
/* @0x155b88 ldr r0, [r0, #0xc] */
/* @0x155b8c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x155b90 mov r3, #0 */
/* @0x155b94 mov r0, r4 */
/* @0x155b98 str r3, [r4, #0xc] */
/* @0x155b9c pop {r4, pc} */

/* ── FUNC 0x155b80 · SPushNotificationEvent::~SPushNotificationEvent() · alias of the symbol above · insn=0 */

/* ── FUNC 0x155ba0 · Push_InitQueue() · size=88 · insn=22 */
/* @0x155ba0 push {r4, r5, r6, lr} */
/* @0x155ba4 ldr r4, [pc, #0x40] */
/* @0x155ba8 add r4, pc, r4 */
/* @0x155bac ldrb r5, [r4] */
/* @0x155bb0 cmp r5, #0 */
/* @0x155bb4 popne {r4, r5, r6, pc} */
/* @0x155bb8 mov r0, #8 */
/* @0x155bbc bl 0x27c524 <_Znwj> */
/* @0x155bc0 ldr r1, [pc, #0x28] */
/* @0x155bc4 add r1, pc, r1 */
/* @0x155bc8 mov r6, r0 */
/* @0x155bcc bl 0x27e070 <_ZN5MutexC2EPKc> */
/* @0x155bd0 ldr r3, [pc, #0x1c] */
/* @0x155bd4 mov r2, #1 */
/* @0x155bd8 str r6, [r4, #0x4] */
/* @0x155bdc ldr r3, [pc, r3] */
/* @0x155be0 strb r2, [r4] */
/* @0x155be4 str r5, [r3] */
/* @0x155be8 pop {r4, r5, r6, pc} */
/* @0x155bec ldrhteq lr, [r2], -r4 */
/* @0x155bf0 andseq r0, pc, r8, asr #16 */
/* @0x155bf4 eoreq r9, r9, r8, lsr pc */

/* ── FUNC 0x155bf8 · Push_DispatchEvents() · size=676 · insn=167 */
/* @0x155bf8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x155bfc vpush {d8} */
/* @0x155c00 sub sp, sp, #68 */
/* @0x155c04 ldr r6, [pc, #0x24c] */
/* @0x155c08 ldr r3, [pc, #0x24c] */
/* @0x155c0c add r6, pc, r6 */
/* @0x155c10 ldr r5, [r6, r3] */
/* @0x155c14 ldr r3, [r5] */
/* @0x155c18 cmp r3, #0 */
/* @0x155c1c beq 0x155e40 <_Z19Push_DispatchEventsv+0x248> */
/* @0x155c20 ldr r3, [pc, #0x238] */
/* @0x155c24 add r2, sp, #60 */
/* @0x155c28 str r2, [sp, #0x34] */
/* @0x155c2c ldr r4, [pc, #0x230] */
/* @0x155c30 ldr r3, [r6, r3] */
/* @0x155c34 ldr r1, [pc, #0x22c] */
/* @0x155c38 add r4, pc, r4 */
/* @0x155c3c ldr r0, [r3] */
/* @0x155c40 add r1, pc, r1 */
/* @0x155c44 ldr r3, [r0] */
/* @0x155c48 ldr r3, [r3, #0xc] */
/* @0x155c4c blx r3 */
/* @0x155c50 ldr r0, [r4, #0x4] */
/* @0x155c54 bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0x155c58 ldr r0, [r4, #0x4] */
/* @0x155c5c ldr r4, [r5] */
/* @0x155c60 mov r3, #0 */
/* @0x155c64 str r3, [r5] */
/* @0x155c68 bl 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0x155c6c add r0, sp, #60 */
/* @0x155c70 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x155c74 cmp r4, #0 */
/* @0x155c78 beq 0x155e34 <_Z19Push_DispatchEventsv+0x23c> */
/* @0x155c7c ldr r3, [pc, #0x1e8] */
/* @0x155c80 vldr d8, [pc, #456] */
/* @0x155c84 ldr r7, [pc, #0x1e4] */
/* @0x155c88 ldr r10, [pc, #0x1e4] */
/* @0x155c8c ldr r5, [r6, r3] */
/* @0x155c90 add r7, pc, r7 */
/* @0x155c94 ldr r9, [pc, #0x1dc] */
/* @0x155c98 add r10, pc, r10 */
/* @0x155c9c ldr r3, [pc, #0x1d8] */
/* @0x155ca0 ldr r2, [pc, #0x1d8] */
/* @0x155ca4 add r9, pc, r9 */
/* @0x155ca8 add r3, pc, r3 */
/* @0x155cac str r3, [sp, #0x2c] */
/* @0x155cb0 add r2, pc, r2 */
/* @0x155cb4 str r2, [sp, #0x30] */
/* @0x155cb8 b 0x155d70 <_Z19Push_DispatchEventsv+0x178> */
/* @0x155cbc ldr r2, [sp, #0x2c] */
/* @0x155cc0 mov r3, #0 */
/* @0x155cc4 stm sp, {r1, r9} */
/* @0x155cc8 vstr d8, [sp, #24] */
/* @0x155ccc str r3, [sp, #0x10] */
/* @0x155cd0 mov r0, #3 */
/* @0x155cd4 str r2, [sp, #0x14] */
/* @0x155cd8 mov r1, r10 */
/* @0x155cdc str r12, [sp, #0x20] */
/* @0x155ce0 mov r2, #0 */
/* @0x155ce4 mov r3, #0 */
/* @0x155ce8 vstr d7, [sp, #8] */
/* @0x155cec bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x155cf0 str r0, [r5] */
/* @0x155cf4 mov r0, #71 */
/* @0x155cf8 bl 0x1ce134 <_Z14HandleWebEventi> */
/* @0x155cfc ldr r3, [r5] */
/* @0x155d00 cmp r3, #0 */
/* @0x155d04 blt 0x155d48 <_Z19Push_DispatchEventsv+0x150> */
/* @0x155d08 ldr r2, [pc, #0x174] */
/* @0x155d0c ldr r11, [r6, r2] */
/* @0x155d10 ldr r2, [r11, #0x4] */
/* @0x155d14 add r0, r2, r3, lsl #2 */
/* @0x155d18 ldr r8, [r2, r3, lsl #2] */
/* @0x155d1c cmp r8, #0 */
/* @0x155d20 beq 0x155d40 <_Z19Push_DispatchEventsv+0x148> */
/* @0x155d24 mov r0, r8 */
/* @0x155d28 bl 0x20d9e8 <_ZN7CDS_MapD2Ev> */
/* @0x155d2c mov r0, r8 */
/* @0x155d30 bl 0x27d1d0 <_ZdlPv> */
/* @0x155d34 ldr r0, [r5] */
/* @0x155d38 ldr r3, [r11, #0x4] */
/* @0x155d3c add r0, r3, r0, lsl #2 */
/* @0x155d40 mov r3, #0 */
/* @0x155d44 str r3, [r0] */
/* @0x155d48 ldr r11, [r4] */
/* @0x155d4c mov r0, r4 */
/* @0x155d50 mvn r2, #0 */
/* @0x155d54 str r2, [r5] */
/* @0x155d58 bl 0x155b80 <_ZN22SPushNotificationEventD2Ev> */
/* @0x155d5c mov r0, r4 */
/* @0x155d60 bl 0x27d1d0 <_ZdlPv> */
/* @0x155d64 cmp r11, #0 */
/* @0x155d68 beq 0x155e34 <_Z19Push_DispatchEventsv+0x23c> */
/* @0x155d6c mov r4, r11 */
/* @0x155d70 ldr r2, [r4, #0x4] */
/* @0x155d74 mvn r1, #0 */
/* @0x155d78 ldr r3, [r4, #0x8] */
/* @0x155d7c cmp r2, #0 */
/* @0x155d80 str r1, [r5] */
/* @0x155d84 ldr r12, [r4, #0xc] */
/* @0x155d88 ldr r1, [r7, r3, lsl #2] */
/* @0x155d8c beq 0x155de8 <_Z19Push_DispatchEventsv+0x1f0> */
/* @0x155d90 vmov s13, r2 */
/* @0x155d94 cmp r3, #0 */
/* @0x155d98 vcvt.f64.s32 d7, s13 */
/* @0x155d9c bne 0x155cbc <_Z19Push_DispatchEventsv+0xc4> */
/* @0x155da0 ldr lr, [pc, #0xe0] */
/* @0x155da4 vstr d8, [sp, #24] */
/* @0x155da8 ldr r2, [pc, #0xdc] */
/* @0x155dac mov r0, #3 */
/* @0x155db0 add lr, pc, lr */
/* @0x155db4 str r1, [sp] */
/* @0x155db8 add r2, pc, r2 */
/* @0x155dbc str r3, [sp, #0x10] */
/* @0x155dc0 str r2, [sp, #0x14] */
/* @0x155dc4 vstr d7, [sp, #8] */
/* @0x155dc8 ldr r1, [sp, #0x30] */
/* @0x155dcc mov r2, #0 */
/* @0x155dd0 str r12, [sp, #0x20] */
/* @0x155dd4 mov r3, #0 */
/* @0x155dd8 str lr, [sp, #0x4] */
/* @0x155ddc bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x155de0 str r0, [r5] */
/* @0x155de4 b 0x155cf4 <_Z19Push_DispatchEventsv+0xfc> */
/* @0x155de8 str r1, [sp] */
/* @0x155dec vstr d8, [sp, #8] */
/* @0x155df0 ldr lr, [pc, #0x98] */
/* @0x155df4 vstr d8, [sp, #24] */
/* @0x155df8 ldr r3, [pc, #0x94] */
/* @0x155dfc mov r0, #3 */
/* @0x155e00 ldr r1, [pc, #0x90] */
/* @0x155e04 add lr, pc, lr */
/* @0x155e08 add r3, pc, r3 */
/* @0x155e0c str r2, [sp, #0x10] */
/* @0x155e10 str r3, [sp, #0x14] */
/* @0x155e14 add r1, pc, r1 */
/* @0x155e18 str r12, [sp, #0x20] */
/* @0x155e1c mov r2, #0 */
/* @0x155e20 str lr, [sp, #0x4] */
/* @0x155e24 mov r3, #0 */
/* @0x155e28 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x155e2c str r0, [r5] */
/* @0x155e30 b 0x155cf4 <_Z19Push_DispatchEventsv+0xfc> */
/* @0x155e34 bl 0x161bfc <_Z23Push_ClearNotificationsv> */
/* @0x155e38 add r0, sp, #60 */
/* @0x155e3c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x155e40 add sp, sp, #68 */
/* @0x155e44 vpop {d8} */
/* @0x155e48 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x155e4c nop */
/* @0x155e58 eoreq r12, r9, r4, asr #32 */
/* @0x155e5c .word 0xffffdec4 */
/* @0x155e60 .word 0xffffbac4 */
/* @0x155e64 eorseq lr, r2, r4, lsr #28 */
/* @0x155e68 ldrsbeq r0, [pc], -r8 */
/* @0x155e6c .word 0xffffdec8 */
/* @0x155e70 .word 0x002516b8 */
/* @0x155e74 mulseq pc, r0, r4 */
/* @0x155e78 andseq r10, sp, r12, lsr #27 */
/* @0x155e7c mulseq pc, r4, r7 */
/* @0x155e80 andseq r0, pc, r8, ror r4 */
/* @0x155e84 .word 0xffffbcec */
/* @0x155e88 andseq r10, sp, r0, lsr #25 */
/* @0x155e8c andseq r0, pc, r12, ror r6 */
/* @0x155e90 andseq r10, sp, r12, asr #24 */
/* @0x155e94 andseq r10, sp, r12, ror sp */
/* @0x155e98 andseq r0, pc, r4, lsl r3 */

/* ── FUNC 0x155e9c · anon_155e9c · size=4 · insn=1 */
/* @0x155e9c nop */

/* ── FUNC 0x155ea0 · InitPushFunctions() · size=228 · insn=57 */
/* @0x155ea0 push {r4, r5, r6, lr} */
/* @0x155ea4 mov r5, #1 */
/* @0x155ea8 ldr r4, [pc, #0xa4] */
/* @0x155eac ldr r3, [pc, #0xa4] */
/* @0x155eb0 add r4, pc, r4 */
/* @0x155eb4 ldr r1, [pc, #0xa0] */
/* @0x155eb8 ldr r3, [r4, r3] */
/* @0x155ebc add r1, pc, r1 */
/* @0x155ec0 ldr r0, [r3] */
/* @0x155ec4 ldr r3, [r0] */
/* @0x155ec8 ldr r3, [r3, #0xc] */
/* @0x155ecc blx r3 */
/* @0x155ed0 ldr r3, [pc, #0x88] */
/* @0x155ed4 ldr r3, [r4, r3] */
/* @0x155ed8 strb r5, [r3] */
/* @0x155edc bl 0x155ba0 <_Z14Push_InitQueuev> */
/* @0x155ee0 ldr r1, [pc, #0x7c] */
/* @0x155ee4 mov r2, #4 */
/* @0x155ee8 ldr r0, [pc, #0x78] */
/* @0x155eec mov r3, #0 */
/* @0x155ef0 ldr r1, [r4, r1] */
/* @0x155ef4 add r0, pc, r0 */
/* @0x155ef8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x155efc ldr r1, [pc, #0x68] */
/* @0x155f00 ldr r0, [pc, #0x68] */
/* @0x155f04 mov r2, r5 */
/* @0x155f08 mov r3, #0 */
/* @0x155f0c ldr r1, [r4, r1] */
/* @0x155f10 add r0, pc, r0 */
/* @0x155f14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x155f18 ldr r1, [pc, #0x54] */
/* @0x155f1c ldr r0, [pc, #0x54] */
/* @0x155f20 mov r2, r5 */
/* @0x155f24 mov r3, #0 */
/* @0x155f28 ldr r1, [r4, r1] */
/* @0x155f2c add r0, pc, r0 */
/* @0x155f30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x155f34 ldr r1, [pc, #0x40] */
/* @0x155f38 ldr r0, [pc, #0x40] */
/* @0x155f3c mov r2, r5 */
/* @0x155f40 mov r3, #0 */
/* @0x155f44 ldr r1, [r4, r1] */
/* @0x155f48 add r0, pc, r0 */
/* @0x155f4c pop {r4, r5, r6, lr} */
/* @0x155f50 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x155f54 eoreq r11, r9, r0, lsr #27 */
/* @0x155f58 .word 0xffffdecc */
/* @0x155f5c andseq r0, pc, r8, lsl #11 */
/* @0x155f60 .word 0xffffdec0 */
/* @0x155f64 .word 0xffffded0 */
/* @0x155f68 andseq r0, pc, r8, ror #10 */
/* @0x155f6c .word 0xffffded4 */
/* @0x155f70 andseq r0, pc, r4, ror #10 */
/* @0x155f74 .word 0xffffded8 */
/* @0x155f78 andseq r0, pc, r12, ror #10 */
/* @0x155f7c .word 0xffffdedc */
/* @0x155f80 andseq r0, pc, r4, ror r5 */

/* ── FUNC 0x155f84 · Push_SendEvent(bool, ePushEventType, char const*) · size=172 · insn=43 */
/* @0x155f84 push {r3, r4, r5, r6, r7, lr} */
/* @0x155f88 mov r7, r0 */
/* @0x155f8c mov r0, #16 */
/* @0x155f90 mov r6, r1 */
/* @0x155f94 mov r5, r2 */
/* @0x155f98 bl 0x27c524 <_Znwj> */
/* @0x155f9c mov r1, r7 */
/* @0x155fa0 mov r2, r6 */
/* @0x155fa4 mov r3, r5 */
/* @0x155fa8 mov r4, r0 */
/* @0x155fac bl 0x155b50 <_ZN22SPushNotificationEventC2Ei14ePushEventTypePKc> */
/* @0x155fb0 ldr r3, [pc, #0x64] */
/* @0x155fb4 ldr r1, [pc, #0x64] */
/* @0x155fb8 ldr r3, [pc, r3] */
/* @0x155fbc ldr r2, [r4, #0x8] */
/* @0x155fc0 add r1, pc, r1 */
/* @0x155fc4 ldr r0, [r3] */
/* @0x155fc8 ldr r3, [r0] */
/* @0x155fcc ldr r3, [r3, #0xc] */
/* @0x155fd0 blx r3 */
/* @0x155fd4 ldr r3, [pc, #0x48] */
/* @0x155fd8 add r3, pc, r3 */
/* @0x155fdc ldrb r3, [r3] */
/* @0x155fe0 cmp r3, #0 */
/* @0x155fe4 bne 0x155fec <_Z14Push_SendEventb14ePushEventTypePKc+0x68> */
/* @0x155fe8 bl 0x155ba0 <_Z14Push_InitQueuev> */
/* @0x155fec ldr r5, [pc, #0x34] */
/* @0x155ff0 add r5, pc, r5 */
/* @0x155ff4 ldr r0, [r5, #0x4] */
/* @0x155ff8 bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0x155ffc ldr r3, [pc, #0x28] */
/* @0x156000 ldr r0, [r5, #0x4] */
/* @0x156004 ldr r3, [pc, r3] */
/* @0x156008 ldr r2, [r3] */
/* @0x15600c str r2, [r4] */
/* @0x156010 str r4, [r3] */
/* @0x156014 pop {r3, r4, r5, r6, r7, lr} */
/* @0x156018 b 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0x15601c eoreq r7, r9, r12, asr r7 */
/* @0x156020 andseq r0, pc, r12, lsl r5 */
/* @0x156024 eorseq lr, r2, r4, lsl #21 */
/* @0x156028 eorseq lr, r2, r12, ror #20 */
/* @0x15602c eoreq r9, r9, r0, lsl r11 */

/* ── FUNC 0x156030 · F_YoYo_AchievementsAvailable(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x156030 ldr r3, [pc, #0x28] */
/* @0x156034 mov r2, #0 */
/* @0x156038 str r2, [r0, #0xc] */
/* @0x15603c ldr r3, [pc, r3] */
/* @0x156040 ldrb r3, [r3] */
/* @0x156044 cmp r3, r2 */
/* @0x156048 strne r2, [r0] */
/* @0x15604c streq r3, [r0] */
/* @0x156050 movne r3, r2 */
/* @0x156054 movtne r3, #0x3ff0 */
/* @0x156058 str r3, [r0, #0x4] */
/* @0x15605c bx lr */
/* @0x156060 .word 0x00299af4 */

/* ── FUNC 0x156064 · F_BE_AddButton(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x156064 bx lr */

/* ── FUNC 0x156068 · F_BE_AddButtonExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x156068 bx lr */

/* ── FUNC 0x15606c · F_BE_ChangeImage(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x15606c bx lr */

/* ── FUNC 0x156070 · F_BE_Change(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x156070 bx lr */

/* ── FUNC 0x156074 · F_BE_DeleteButton(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x156074 bx lr */

/* ── FUNC 0x156078 · F_BE_ExistsButton(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x156078 bx lr */

/* ── FUNC 0x15607c · F_BE_SetStyle(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x15607c bx lr */

/* ── FUNC 0x156080 · F_YoYo_AdsEngagementAvailable(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x156080 mov r3, #0 */
/* @0x156084 str r3, [r0, #0xc] */
/* @0x156088 str r3, [r0] */
/* @0x15608c str r3, [r0, #0x4] */
/* @0x156090 bx lr */
