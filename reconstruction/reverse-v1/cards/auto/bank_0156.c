/* libyoyo.so 覆盖卡组 0156
 * 函数 0x1d32c0..0x1d51f8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1d32c0 · DoAStep() · size=920 · insn=230 */
/* @0x1d32c0 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1d32c4 bl 0x215148 <Timing_Time> */
/* @0x1d32c8 ldr r6, [pc, #0x344] */
/* @0x1d32cc ldr r12, [pc, #0x344] */
/* @0x1d32d0 add r6, pc, r6 */
/* @0x1d32d4 ldr lr, [pc, #0x340] */
/* @0x1d32d8 ldr r12, [r6, r12] */
/* @0x1d32dc ldr lr, [r6, lr] */
/* @0x1d32e0 ldrd r4, r5, [r12] */
/* @0x1d32e4 mov r3, r1 */
/* @0x1d32e8 ldr r1, [pc, #0x330] */
/* @0x1d32ec mov r2, r0 */
/* @0x1d32f0 movw r0, #0x8080 */
/* @0x1d32f4 add r1, pc, r1 */
/* @0x1d32f8 movt r0, #0xff80 */
/* @0x1d32fc strd r2, r3, [r12] */
/* @0x1d3300 subs r2, r2, r4 */
/* @0x1d3304 sbc r3, r3, r5 */
/* @0x1d3308 strd r2, r3, [lr] */
/* @0x1d330c bl 0x17b8f0 <_ZN12GraphicsPerf4PushEjPKc> */
/* @0x1d3310 mov r0, #0 */
/* @0x1d3314 bl 0xd6aac <_Z12MarkAndSweepP12YYObjectBase> */
/* @0x1d3318 bl 0x17bb10 <_ZN12GraphicsPerf3PopEv> */
/* @0x1d331c ldr r3, [pc, #0x300] */
/* @0x1d3320 ldr r0, [r6, r3] */
/* @0x1d3324 bl 0x168294 <_ZN18RenderStateManager5ForceEv> */
/* @0x1d3328 bl 0x1d0ed4 <_Z19Check_LoadGameStatev> */
/* @0x1d332c ldr r1, [pc, #0x2f4] */
/* @0x1d3330 mov r0, #65280 */
/* @0x1d3334 movt r0, #0xff00 */
/* @0x1d3338 add r1, pc, r1 */
/* @0x1d333c bl 0x17b8f0 <_ZN12GraphicsPerf4PushEjPKc> */
/* @0x1d3340 bl 0x18d37c <_Z13IO_Start_Stepv> */
/* @0x1d3344 bl 0x15a0ac <_Z19UpdateYoYoFunctionsv> */
/* @0x1d3348 bl 0x17bb10 <_ZN12GraphicsPerf3PopEv> */
/* @0x1d334c ldr r1, [pc, #0x2d8] */
/* @0x1d3350 mov r0, #255 */
/* @0x1d3354 movt r0, #0xff00 */
/* @0x1d3358 add r1, pc, r1 */
/* @0x1d335c bl 0x17b8f0 <_ZN12GraphicsPerf4PushEjPKc> */
/* @0x1d3360 ldr r2, [pc, #0x2c8] */
/* @0x1d3364 ldr r3, [pc, #0x2c8] */
/* @0x1d3368 ldr r9, [r6, r2] */
/* @0x1d336c add r3, pc, r3 */
/* @0x1d3370 ldrb r2, [r3] */
/* @0x1d3374 ldr r0, [r9] */
/* @0x1d3378 cmp r2, #0 */
/* @0x1d337c ldr r4, [r0, #0x80] */
/* @0x1d3380 bne 0x1d35c4 <_Z7DoAStepv+0x304> */
/* @0x1d3384 cmp r4, #0 */
/* @0x1d3388 beq 0x1d35e8 <_Z7DoAStepv+0x328> */
/* @0x1d338c mov r7, #0 */
/* @0x1d3390 mov r8, r7 */
/* @0x1d3394 ldr r3, [r4, #0xb8] */
/* @0x1d3398 mov r0, r4 */
/* @0x1d339c ldr r2, [r4, #0xb4] */
/* @0x1d33a0 ldr r5, [r4, #0x178] */
/* @0x1d33a4 str r3, [r4, #0xc8] */
/* @0x1d33a8 ldr r3, [r4, #0x12c] */
/* @0x1d33ac str r2, [r4, #0xc4] */
/* @0x1d33b0 str r3, [r4, #0x130] */
/* @0x1d33b4 bl 0x1d317c <_Z16Instance_AnimateP9CInstance> */
/* @0x1d33b8 ldrb r2, [r4, #0x15c] */
/* @0x1d33bc ldr r3, [r4, #0x128] */
/* @0x1d33c0 mov r4, r5 */
/* @0x1d33c4 cmp r2, #0 */
/* @0x1d33c8 movne r8, #1 */
/* @0x1d33cc cmp r3, #0 */
/* @0x1d33d0 movge r7, #1 */
/* @0x1d33d4 cmp r5, #0 */
/* @0x1d33d8 bne 0x1d3394 <_Z7DoAStepv+0xd4> */
/* @0x1d33dc ldr r0, [r9] */
/* @0x1d33e0 bl 0x1abfa0 <_ZN5CRoom12UpdateLayersEv> */
/* @0x1d33e4 mov r0, #1 */
/* @0x1d33e8 bl 0x1cdf6c <_Z10HandleStepi> */
/* @0x1d33ec bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d33f0 ldr r3, [pc, #0x240] */
/* @0x1d33f4 ldr r4, [r6, r3] */
/* @0x1d33f8 ldr r3, [r4] */
/* @0x1d33fc cmn r3, #1 */
/* @0x1d3400 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d3404 bl 0x29a764 <_Z17ProcessNetworkingv> */
/* @0x1d3408 bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d340c ldr r3, [r4] */
/* @0x1d3410 cmn r3, #1 */
/* @0x1d3414 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d3418 cmp r8, #0 */
/* @0x1d341c bne 0x1d35f4 <_Z7DoAStepv+0x334> */
/* @0x1d3420 bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d3424 ldr r3, [r4] */
/* @0x1d3428 cmn r3, #1 */
/* @0x1d342c popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d3430 bl 0x1cdd70 <_Z11HandleAlarmv> */
/* @0x1d3434 bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d3438 ldr r3, [r4] */
/* @0x1d343c cmn r3, #1 */
/* @0x1d3440 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d3444 bl 0x1d5c3c <_Z14HandleKeyboardv> */
/* @0x1d3448 bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d344c ldr r3, [r4] */
/* @0x1d3450 cmn r3, #1 */
/* @0x1d3454 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d3458 bl 0x1dc75c <_Z14HandleJoystickv> */
/* @0x1d345c bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d3460 ldr r3, [r4] */
/* @0x1d3464 cmn r3, #1 */
/* @0x1d3468 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d346c bl 0x1db7bc <_Z11HandleMousev> */
/* @0x1d3470 bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d3474 ldr r3, [r4] */
/* @0x1d3478 cmn r3, #1 */
/* @0x1d347c popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d3480 mov r0, #0 */
/* @0x1d3484 bl 0x1cdf6c <_Z10HandleStepi> */
/* @0x1d3488 bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d348c ldr r3, [r4] */
/* @0x1d3490 cmn r3, #1 */
/* @0x1d3494 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d3498 mov r0, r7 */
/* @0x1d349c bl 0x1d1cec <_Z22HandleInstanceMovementb> */
/* @0x1d34a0 mov r5, r0 */
/* @0x1d34a4 bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d34a8 ldr r3, [r4] */
/* @0x1d34ac cmn r3, #1 */
/* @0x1d34b0 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d34b4 bl 0x1ce594 <_Z11HandleOtherv> */
/* @0x1d34b8 bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d34bc ldr r3, [r4] */
/* @0x1d34c0 cmn r3, #1 */
/* @0x1d34c4 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d34c8 bl 0x1ce38c <_Z17HandleAsyncEventsv> */
/* @0x1d34cc bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d34d0 ldr r3, [r4] */
/* @0x1d34d4 cmn r3, #1 */
/* @0x1d34d8 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d34dc cmp r5, #0 */
/* @0x1d34e0 beq 0x1d35fc <_Z7DoAStepv+0x33c> */
/* @0x1d34e4 mov r0, #2 */
/* @0x1d34e8 bl 0x1cdf6c <_Z10HandleStepi> */
/* @0x1d34ec bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d34f0 ldr r3, [r4] */
/* @0x1d34f4 cmn r3, #1 */
/* @0x1d34f8 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d34fc bl 0x1a4fbc <_Z24ParticleSystem_UpdateAllv> */
/* @0x1d3500 bl 0x17bb10 <_ZN12GraphicsPerf3PopEv> */
/* @0x1d3504 ldr r1, [pc, #0x130] */
/* @0x1d3508 mvn r0, #16711680 */
/* @0x1d350c add r1, pc, r1 */
/* @0x1d3510 bl 0x17b8f0 <_ZN12GraphicsPerf4PushEjPKc> */
/* @0x1d3514 ldr r0, [r9] */
/* @0x1d3518 bl 0x1abb24 <_ZN5CRoom12RemoveMarkedEv> */
/* @0x1d351c ldr r3, [pc, #0x11c] */
/* @0x1d3520 ldr r3, [r6, r3] */
/* @0x1d3524 ldrb r3, [r3] */
/* @0x1d3528 cmp r3, #0 */
/* @0x1d352c beq 0x1d3538 <_Z7DoAStepv+0x278> */
/* @0x1d3530 bl 0x1b3e98 <_Z9Draw_Roomv> */
/* @0x1d3534 bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d3538 bl 0x17bb10 <_ZN12GraphicsPerf3PopEv> */
/* @0x1d353c ldr r3, [pc, #0x100] */
/* @0x1d3540 add r3, pc, r3 */
/* @0x1d3544 ldrb r2, [r3, #0x1] */
/* @0x1d3548 cmp r2, #0 */
/* @0x1d354c bne 0x1d3570 <_Z7DoAStepv+0x2b0> */
/* @0x1d3550 ldr r2, [pc, #0xf0] */
/* @0x1d3554 ldr r2, [r6, r2] */
/* @0x1d3558 ldr r2, [r2] */
/* @0x1d355c cmp r2, #0 */
/* @0x1d3560 beq 0x1d3570 <_Z7DoAStepv+0x2b0> */
/* @0x1d3564 mov r2, #1 */
/* @0x1d3568 strb r2, [r3, #0x1] */
/* @0x1d356c bl 0x1d23a0 <CheckLicense> */
/* @0x1d3570 ldr r1, [pc, #0xd4] */
/* @0x1d3574 movw r0, #0x8080 */
/* @0x1d3578 movt r0, #0xff00 */
/* @0x1d357c add r1, pc, r1 */
/* @0x1d3580 bl 0x17b8f0 <_ZN12GraphicsPerf4PushEjPKc> */
/* @0x1d3584 ldr r0, [r9] */
/* @0x1d3588 bl 0x1ac200 <_ZN5CRoom16ScrollBackgroundEv> */
/* @0x1d358c bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d3590 ldr r3, [pc, #0xb8] */
/* @0x1d3594 ldr r3, [r6, r3] */
/* @0x1d3598 ldr r2, [r3] */
/* @0x1d359c add r2, r2, #1 */
/* @0x1d35a0 str r2, [r3] */
/* @0x1d35a4 bl 0x17bb10 <_ZN12GraphicsPerf3PopEv> */
/* @0x1d35a8 ldr r3, [pc, #0xa4] */
/* @0x1d35ac ldr r3, [r6, r3] */
/* @0x1d35b0 ldr r3, [r3] */
/* @0x1d35b4 cmp r3, #0 */
/* @0x1d35b8 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d35bc pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1d35c0 b 0x1c9f50 <_Z15Command_EndGamev> */
/* @0x1d35c4 mov r2, #0 */
/* @0x1d35c8 strb r2, [r3] */
/* @0x1d35cc bl 0x1abb24 <_ZN5CRoom12RemoveMarkedEv> */
/* @0x1d35d0 mov r0, #8 */
/* @0x1d35d4 mov r1, #65 */
/* @0x1d35d8 bl 0xf33b0 <_Z17Perform_Event_Allii> */
/* @0x1d35dc ldr r0, [r9] */
/* @0x1d35e0 bl 0x1abb24 <_ZN5CRoom12RemoveMarkedEv> */
/* @0x1d35e4 b 0x1d3384 <_Z7DoAStepv+0xc4> */
/* @0x1d35e8 mov r7, r4 */
/* @0x1d35ec mov r8, r4 */
/* @0x1d35f0 b 0x1d33dc <_Z7DoAStepv+0x11c> */
/* @0x1d35f4 bl 0x1d00b4 <_Z14HandleTimeLinev> */
/* @0x1d35f8 b 0x1d3420 <_Z7DoAStepv+0x160> */
/* @0x1d35fc bl 0x1cc500 <_Z15HandleCollisionv> */
/* @0x1d3600 bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d3604 ldr r3, [r4] */
/* @0x1d3608 cmn r3, #1 */
/* @0x1d360c popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d3610 b 0x1d34e4 <_Z7DoAStepv+0x224> */
/* @0x1d3614 eoreq lr, r1, r0, lsl #19 */
/* @0x1d3618 .word 0xffffef20 */
/* @0x1d361c .word 0xffffef24 */
/* @0x1d3620 andseq sp, r7, r8, lsl #27 */
/* @0x1d3624 .word 0xffffc0a8 */
/* @0x1d3628 andseq sp, r7, r8, asr sp */
/* @0x1d362c andseq sp, r7, r0, asr #26 */
/* @0x1d3630 .word 0xffffbcd8 */
/* @0x1d3634 eorseq pc, r6, r12, asr r6 */
/* @0x1d3638 .word 0xffffc154 */
/* @0x1d363c ldrsbeq r4, [r6], -r8 */
/* @0x1d3640 .word 0xffffc974 */
/* @0x1d3644 eorseq pc, r6, r8, lsl #9 */
/* @0x1d3648 .word 0xffffef04 */
/* @0x1d364c andseq sp, r7, r4, lsr #22 */
/* @0x1d3650 .word 0xffffebf0 */
/* @0x1d3654 .word 0xffffef10 */

/* ── FUNC 0x1d3658 · MainLoop_Init() · size=232 · insn=58 */
/* @0x1d3658 push {r4, r5, r6, lr} */
/* @0x1d365c bl 0x215148 <Timing_Time> */
/* @0x1d3660 mov r3, #0 */
/* @0x1d3664 ldr r4, [pc, #0xac] */
/* @0x1d3668 ldr r2, [pc, #0xac] */
/* @0x1d366c add r4, pc, r4 */
/* @0x1d3670 ldr lr, [pc, #0xa8] */
/* @0x1d3674 ldr r12, [pc, #0xa8] */
/* @0x1d3678 ldr r5, [r4, r2] */
/* @0x1d367c ldr r2, [pc, #0xa4] */
/* @0x1d3680 ldr r6, [pc, #0xa4] */
/* @0x1d3684 add r6, pc, r6 */
/* @0x1d3688 strd r0, r1, [r5] */
/* @0x1d368c ldr lr, [r4, lr] */
/* @0x1d3690 str r3, [lr] */
/* @0x1d3694 ldr r12, [r4, r12] */
/* @0x1d3698 str r3, [r12] */
/* @0x1d369c ldr r3, [r4, r2] */
/* @0x1d36a0 strd r0, r1, [r3] */
/* @0x1d36a4 bl 0x28fe64 <_Z15ProcessMessagesv> */
/* @0x1d36a8 ldr r3, [pc, #0x80] */
/* @0x1d36ac mov r1, r6 */
/* @0x1d36b0 ldr r3, [r4, r3] */
/* @0x1d36b4 ldr r5, [r3] */
/* @0x1d36b8 ldr r3, [r5] */
/* @0x1d36bc mov r0, r5 */
/* @0x1d36c0 ldr r3, [r3, #0xc] */
/* @0x1d36c4 blx r3 */
/* @0x1d36c8 ldr r3, [r5] */
/* @0x1d36cc ldr r1, [pc, #0x60] */
/* @0x1d36d0 mov r0, r5 */
/* @0x1d36d4 add r1, pc, r1 */
/* @0x1d36d8 ldr r3, [r3, #0xc] */
/* @0x1d36dc blx r3 */
/* @0x1d36e0 ldr r3, [r5] */
/* @0x1d36e4 mov r1, r6 */
/* @0x1d36e8 mov r0, r5 */
/* @0x1d36ec ldr r3, [r3, #0xc] */
/* @0x1d36f0 blx r3 */
/* @0x1d36f4 ldr r1, [pc, #0x3c] */
/* @0x1d36f8 mvn r0, #0 */
/* @0x1d36fc add r1, pc, r1 */
/* @0x1d3700 bl 0x27d234 <_Z18DisplayMemoryErrorjPKc> */
/* @0x1d3704 bl 0x215148 <Timing_Time> */
/* @0x1d3708 ldr r3, [pc, #0x2c] */
/* @0x1d370c ldr r3, [r4, r3] */
/* @0x1d3710 strd r0, r1, [r3] */
/* @0x1d3714 pop {r4, r5, r6, pc} */
/* @0x1d3718 eoreq lr, r1, r4, ror #11 */
/* @0x1d371c .word 0xffffef28 */
/* @0x1d3720 .word 0xffffeb1c */
/* @0x1d3724 .word 0xffffef2c */
/* @0x1d3728 .word 0xffffef30 */
/* @0x1d372c andseq sp, r7, r4, lsr #20 */
/* @0x1d3730 .word 0xffffdecc */
/* @0x1d3734 ldrsheq sp, [r7], -r12 */
/* @0x1d3738 andseq sp, r7, r12, ror #19 */
/* @0x1d373c .word 0xffffef20 */

/* ── FUNC 0x1d3740 · Run_Stop() · size=76 · insn=19 */
/* @0x1d3740 ldr r1, [pc, #0x38] */
/* @0x1d3744 mov r0, #0 */
/* @0x1d3748 push {r3, lr} */
/* @0x1d374c ldr r1, [pc, r1] */
/* @0x1d3750 ldr r2, [pc, #0x2c] */
/* @0x1d3754 ldr r3, [pc, #0x2c] */
/* @0x1d3758 ldrb r1, [r1] */
/* @0x1d375c ldr r2, [pc, r2] */
/* @0x1d3760 ldr r3, [pc, r3] */
/* @0x1d3764 cmp r1, r0 */
/* @0x1d3768 strb r0, [r2] */
/* @0x1d376c strb r0, [r3] */
/* @0x1d3770 popne {r3, pc} */
/* @0x1d3774 bl 0x1d1b38 <_Z11Run_EndGamev> */
/* @0x1d3778 pop {r3, lr} */
/* @0x1d377c b 0x28fe4c <_Z9Terminatev> */
/* @0x1d3780 eoreq sp, r1, r8, lsr r4 */
/* @0x1d3784 .word 0x0021d3b0 */
/* @0x1d3788 mlaeq r1, r0, r4, r12 */

/* ── FUNC 0x1d378c · Run_Pause() · size=24 · insn=6 */
/* @0x1d378c ldr r3, [pc, #0xc] */
/* @0x1d3790 mov r2, #1 */
/* @0x1d3794 ldr r3, [pc, r3] */
/* @0x1d3798 strb r2, [r3] */
/* @0x1d379c bx lr */
/* @0x1d37a0 eoreq r12, r1, r12, asr r4 */

/* ── FUNC 0x1d37a4 · INITIALIZE_Main() · size=40 · insn=10 */
/* @0x1d37a4 ldr r2, [pc, #0x18] */
/* @0x1d37a8 mov r1, #0 */
/* @0x1d37ac ldr r3, [pc, #0x14] */
/* @0x1d37b0 ldr r2, [pc, r2] */
/* @0x1d37b4 ldr r3, [pc, r3] */
/* @0x1d37b8 str r1, [r2, #0x8] */
/* @0x1d37bc str r1, [r3, #0x8] */
/* @0x1d37c0 bx lr */
/* @0x1d37c4 mlaeq r1, r0, r4, r10 */
/* @0x1d37c8 .word 0x0021a8f0 */

/* ── FUNC 0x1d37cc · FINALIZE_Run_Main() · size=276 · insn=69 */
/* @0x1d37cc push {r4, r5, r6, r7, r8, lr} */
/* @0x1d37d0 ldr r6, [pc, #0xfc] */
/* @0x1d37d4 ldr r7, [pc, #0xfc] */
/* @0x1d37d8 ldr r6, [pc, r6] */
/* @0x1d37dc ldr r7, [pc, r7] */
/* @0x1d37e0 ldr r2, [r6] */
/* @0x1d37e4 cmp r2, #0 */
/* @0x1d37e8 str r2, [r7] */
/* @0x1d37ec movgt r4, #0 */
/* @0x1d37f0 movgt r5, r4 */
/* @0x1d37f4 movgt r8, r4 */
/* @0x1d37f8 bgt 0x1d3804 <_Z17FINALIZE_Run_Mainv+0x38> */
/* @0x1d37fc b 0x1d3870 <_Z17FINALIZE_Run_Mainv+0xa4> */
/* @0x1d3800 ldr r2, [r6] */
/* @0x1d3804 cmp r5, r2 */
/* @0x1d3808 ldr r3, [pc, #0xcc] */
/* @0x1d380c bge 0x1d3850 <_Z17FINALIZE_Run_Mainv+0x84> */
/* @0x1d3810 ldr r1, [r6, #0x4] */
/* @0x1d3814 add r2, r1, r4 */
/* @0x1d3818 ldr r1, [r1, r4] */
/* @0x1d381c cmp r1, #0 */
/* @0x1d3820 mov r0, r1 */
/* @0x1d3824 beq 0x1d3858 <_Z17FINALIZE_Run_Mainv+0x8c> */
/* @0x1d3828 ldr r3, [pc, r3] */
/* @0x1d382c ldrb r3, [r3] */
/* @0x1d3830 cmp r3, #0 */
/* @0x1d3834 beq 0x1d3844 <_Z17FINALIZE_Run_Mainv+0x78> */
/* @0x1d3838 ldr r3, [r1, #0x44] */
/* @0x1d383c cmn r3, #1 */
/* @0x1d3840 beq 0x1d3858 <_Z17FINALIZE_Run_Mainv+0x8c> */
/* @0x1d3844 ldr r3, [r1] */
/* @0x1d3848 ldr r3, [r3, #0x4] */
/* @0x1d384c blx r3 */
/* @0x1d3850 ldr r2, [r6, #0x4] */
/* @0x1d3854 add r2, r2, r4 */
/* @0x1d3858 ldr r3, [r7] */
/* @0x1d385c add r5, r5, #1 */
/* @0x1d3860 add r4, r4, #4 */
/* @0x1d3864 str r8, [r2] */
/* @0x1d3868 cmp r3, r5 */
/* @0x1d386c bgt 0x1d3800 <_Z17FINALIZE_Run_Mainv+0x34> */
/* @0x1d3870 ldr r4, [r6, #0x4] */
/* @0x1d3874 cmp r4, #0 */
/* @0x1d3878 beq 0x1d38c4 <_Z17FINALIZE_Run_Mainv+0xf8> */
/* @0x1d387c ldr r2, [r6] */
/* @0x1d3880 cmp r2, #0 */
/* @0x1d3884 ble 0x1d38a4 <_Z17FINALIZE_Run_Mainv+0xd8> */
/* @0x1d3888 mov r3, #0 */
/* @0x1d388c mov r1, r3 */
/* @0x1d3890 str r1, [r4, r3, lsl #2] */
/* @0x1d3894 add r3, r3, #1 */
/* @0x1d3898 cmp r3, r2 */
/* @0x1d389c ldr r4, [r6, #0x4] */
/* @0x1d38a0 bne 0x1d3890 <_Z17FINALIZE_Run_Mainv+0xc4> */
/* @0x1d38a4 mov r0, r4 */
/* @0x1d38a8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d38ac mov r3, #0 */
/* @0x1d38b0 str r3, [r6, #0x4] */
/* @0x1d38b4 mov r3, #0 */
/* @0x1d38b8 str r3, [r6] */
/* @0x1d38bc str r3, [r7] */
/* @0x1d38c0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1d38c4 mov r0, r4 */
/* @0x1d38c8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d38cc str r4, [r6, #0x4] */
/* @0x1d38d0 b 0x1d38b4 <_Z17FINALIZE_Run_Mainv+0xe8> */
/* @0x1d38d4 eoreq sp, r1, r0, ror r3 */
/* @0x1d38d8 eoreq sp, r1, r8, ror #6 */
/* @0x1d38dc mlaeq r1, r0, r3, r10 */

/* ── FUNC 0x1d38e0 · StartRoom(int, bool) · size=2928 · insn=732 */
/* @0x1d38e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d38e4 sub sp, sp, #68 */
/* @0x1d38e8 ldr r11, [pc, #0xb1c] */
/* @0x1d38ec mov r2, #0 */
/* @0x1d38f0 ldr r3, [pc, #0xb18] */
/* @0x1d38f4 cmp r1, #0 */
/* @0x1d38f8 add r11, pc, r11 */
/* @0x1d38fc str r2, [sp, #0x30] */
/* @0x1d3900 str r1, [sp, #0x2c] */
/* @0x1d3904 mvn r2, #0 */
/* @0x1d3908 ldr r3, [r11, r3] */
/* @0x1d390c mov r7, r0 */
/* @0x1d3910 str r2, [r3] */
/* @0x1d3914 bne 0x1d4308 <_Z9StartRoomib+0xa28> */
/* @0x1d3918 bl 0x1a277c <_Z12Effect_Clearv> */
/* @0x1d391c ldr r3, [pc, #0xaf0] */
/* @0x1d3920 ldr r4, [r11, r3] */
/* @0x1d3924 ldr r5, [r4] */
/* @0x1d3928 cmp r5, r7 */
/* @0x1d392c ble 0x1d424c <_Z9StartRoomib+0x96c> */
/* @0x1d3930 ldr r3, [pc, #0xae0] */
/* @0x1d3934 ldr r3, [r11, r3] */
/* @0x1d3938 str r7, [r3] */
/* @0x1d393c ldr r3, [r4, #0x4] */
/* @0x1d3940 ldr r0, [r3, r7, lsl #2] */
/* @0x1d3944 bl 0x1cba58 <_Z12Run_Room_SetP5CRoom> */
/* @0x1d3948 ldr r3, [pc, #0xacc] */
/* @0x1d394c ldr r6, [r11, r3] */
/* @0x1d3950 ldr r3, [r6] */
/* @0x1d3954 adds r12, r3, #0 */
/* @0x1d3958 movne r12, #1 */
/* @0x1d395c cmp r12, #0 */
/* @0x1d3960 str r12, [sp, #0x20] */
/* @0x1d3964 beq 0x1d41f0 <_Z9StartRoomib+0x910> */
/* @0x1d3968 ldr r4, [r3, #0x80] */
/* @0x1d396c cmp r4, #0 */
/* @0x1d3970 beq 0x1d3a18 <_Z9StartRoomib+0x138> */
/* @0x1d3974 ldr r3, [pc, #0xaa4] */
/* @0x1d3978 ldr r10, [pc, #0xaa4] */
/* @0x1d397c ldr r5, [r11, r3] */
/* @0x1d3980 add r10, pc, r10 */
/* @0x1d3984 str r6, [sp, #0x14] */
/* @0x1d3988 b 0x1d3990 <_Z9StartRoomib+0xb0> */
/* @0x1d398c mov r4, r7 */
/* @0x1d3990 ldr r0, [r4, #0x80] */
/* @0x1d3994 mov r1, r4 */
/* @0x1d3998 ldr r7, [r4, #0x178] */
/* @0x1d399c bl 0x19e02c <_ZN9CObjectGM11AddInstanceEP9CInstance> */
/* @0x1d39a0 movw r2, #0x132 */
/* @0x1d39a4 mov r3, #1 */
/* @0x1d39a8 mov r0, #16 */
/* @0x1d39ac mov r1, r10 */
/* @0x1d39b0 ldr r8, [r5] */
/* @0x1d39b4 ldr r6, [r4, #0x78] */
/* @0x1d39b8 ldr r9, [r5, #0x4] */
/* @0x1d39bc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d39c0 and r9, r6, r9 */
/* @0x1d39c4 ldr r2, [r8, r9, lsl #3] */
/* @0x1d39c8 add r3, r8, r9, lsl #3 */
/* @0x1d39cc cmp r2, #0 */
/* @0x1d39d0 ldrne r2, [r3, #0x4] */
/* @0x1d39d4 movne lr, #0 */
/* @0x1d39d8 str r6, [r0, #0x8] */
/* @0x1d39dc str r4, [r0, #0xc] */
/* @0x1d39e0 strne r2, [r0] */
/* @0x1d39e4 streq r0, [r3, #0x4] */
/* @0x1d39e8 strne r0, [r2, #0x4] */
/* @0x1d39ec streq r0, [r8, r9, lsl #3] */
/* @0x1d39f0 strne r0, [r3, #0x4] */
/* @0x1d39f4 streq r2, [r0, #0x4] */
/* @0x1d39f8 streq r2, [r0] */
/* @0x1d39fc strne lr, [r0, #0x4] */
/* @0x1d3a00 cmp r7, #0 */
/* @0x1d3a04 ldr r3, [r5, #0x8] */
/* @0x1d3a08 add r3, r3, #1 */
/* @0x1d3a0c str r3, [r5, #0x8] */
/* @0x1d3a10 bne 0x1d398c <_Z9StartRoomib+0xac> */
/* @0x1d3a14 ldr r6, [sp, #0x14] */
/* @0x1d3a18 ldr r3, [pc, #0xa08] */
/* @0x1d3a1c ldr r3, [r11, r3] */
/* @0x1d3a20 str r3, [sp, #0x14] */
/* @0x1d3a24 ldrb r3, [r3] */
/* @0x1d3a28 cmp r3, #0 */
/* @0x1d3a2c bne 0x1d41e0 <_Z9StartRoomib+0x900> */
/* @0x1d3a30 ldr r0, [r6] */
/* @0x1d3a34 bl 0x1c5dbc <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom> */
/* @0x1d3a38 bl 0x1a5b9c <_Z29ParticleSystem_AddAllToLayersv> */
/* @0x1d3a3c bl 0x1b29bc <_Z17Draw_Room_SetSizev> */
/* @0x1d3a40 ldr r3, [pc, #0x9e4] */
/* @0x1d3a44 ldr r3, [r11, r3] */
/* @0x1d3a48 str r3, [sp, #0x18] */
/* @0x1d3a4c ldr r3, [r3] */
/* @0x1d3a50 cmp r3, #0 */
/* @0x1d3a54 ldr r3, [pc, #0x9d4] */
/* @0x1d3a58 ble 0x1d43e8 <_Z9StartRoomib+0xb08> */
/* @0x1d3a5c ldr r0, [pc, #0x9d0] */
/* @0x1d3a60 mov r12, #0 */
/* @0x1d3a64 mov r8, r12 */
/* @0x1d3a68 add r0, pc, r0 */
/* @0x1d3a6c str r0, [sp, #0x28] */
/* @0x1d3a70 ldr r7, [r11, r3] */
/* @0x1d3a74 str r11, [sp, #0x24] */
/* @0x1d3a78 mov r11, r12 */
/* @0x1d3a7c ldr r3, [r7] */
/* @0x1d3a80 ldr r10, [r6] */
/* @0x1d3a84 cmp r3, r8 */
/* @0x1d3a88 ldrgt r3, [r7, #0x4] */
/* @0x1d3a8c movle r4, #0 */
/* @0x1d3a90 ldrgt r4, [r3, r11] */
/* @0x1d3a94 ldr r3, [r10, #0x80] */
/* @0x1d3a98 cmp r3, #0 */
/* @0x1d3a9c ldr r9, [r4, #0x78] */
/* @0x1d3aa0 beq 0x1d3ad4 <_Z9StartRoomib+0x1f4> */
/* @0x1d3aa4 ldr r2, [r3, #0x78] */
/* @0x1d3aa8 ldr r5, [r3, #0x178] */
/* @0x1d3aac cmp r2, r9 */
/* @0x1d3ab0 bne 0x1d3acc <_Z9StartRoomib+0x1ec> */
/* @0x1d3ab4 b 0x1d3e44 <_Z9StartRoomib+0x564> */
/* @0x1d3ab8 ldr r3, [r5, #0x78] */
/* @0x1d3abc ldr r2, [r5, #0x178] */
/* @0x1d3ac0 cmp r3, r9 */
/* @0x1d3ac4 beq 0x1d3e48 <_Z9StartRoomib+0x568> */
/* @0x1d3ac8 mov r5, r2 */
/* @0x1d3acc cmp r5, #0 */
/* @0x1d3ad0 bne 0x1d3ab8 <_Z9StartRoomib+0x1d8> */
/* @0x1d3ad4 ldr r3, [r4, #0x7c] */
/* @0x1d3ad8 mov r0, #432 */
/* @0x1d3adc ldr r1, [r4, #0xb4] */
/* @0x1d3ae0 ldr r10, [r4, #0xb8] */
/* @0x1d3ae4 str r3, [sp, #0xc] */
/* @0x1d3ae8 str r1, [sp, #0x10] */
/* @0x1d3aec bl 0x27c524 <_Znwj> */
/* @0x1d3af0 ldr r3, [sp, #0xc] */
/* @0x1d3af4 mov lr, #0 */
/* @0x1d3af8 ldr r1, [sp, #0x10] */
/* @0x1d3afc mov r2, r10 */
/* @0x1d3b00 str lr, [sp, #0x4] */
/* @0x1d3b04 str r3, [sp] */
/* @0x1d3b08 mov r3, r9 */
/* @0x1d3b0c mov r5, r0 */
/* @0x1d3b10 bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1d3b14 ldr r12, [sp, #0x14] */
/* @0x1d3b18 ldrb r3, [r12] */
/* @0x1d3b1c cmp r3, #0 */
/* @0x1d3b20 ldrne r3, [r4, #0x180] */
/* @0x1d3b24 strne r3, [r5, #0x180] */
/* @0x1d3b28 mov r2, #1 */
/* @0x1d3b2c mov r0, r5 */
/* @0x1d3b30 mov r1, r4 */
/* @0x1d3b34 bl 0x1986ec <_ZN9CInstance6AssignEPS_b> */
/* @0x1d3b38 ldr r1, [r6] */
/* @0x1d3b3c mov r0, r5 */
/* @0x1d3b40 bl 0x192fa4 <_ZN9CInstance18RebuildPhysicsBodyEP5CRoom> */
/* @0x1d3b44 ldr r2, [r6] */
/* @0x1d3b48 ldr r3, [r2, #0x84] */
/* @0x1d3b4c ldr r1, [r2, #0x88] */
/* @0x1d3b50 cmp r3, #0 */
/* @0x1d3b54 vldrne s14, [r5, #384] */
/* @0x1d3b58 add r1, r1, #1 */
/* @0x1d3b5c str r1, [r2, #0x88] */
/* @0x1d3b60 beq 0x1d41ac <_Z9StartRoomib+0x8cc> */
/* @0x1d3b64 vldr s15, [r3, #388] */
/* @0x1d3b68 vcmpe.f32 s15, s14 */
/* @0x1d3b6c vmrs APSR_nzcv, fpscr */
/* @0x1d3b70 bls 0x1d3f7c <_Z9StartRoomib+0x69c> */
/* @0x1d3b74 ldr r3, [r3, #0x17c] */
/* @0x1d3b78 cmp r3, #0 */
/* @0x1d3b7c bne 0x1d3b64 <_Z9StartRoomib+0x284> */
/* @0x1d3b80 ldr r1, [r2, #0x80] */
/* @0x1d3b84 vstr s14, [r5, #388] */
/* @0x1d3b88 str r5, [r1, #0x17c] */
/* @0x1d3b8c str r1, [r5, #0x178] */
/* @0x1d3b90 str r5, [r2, #0x80] */
/* @0x1d3b94 str r3, [r5, #0x17c] */
/* @0x1d3b98 ldr r12, [r5, #0x78] */
/* @0x1d3b9c movw r2, #0x132 */
/* @0x1d3ba0 ldr lr, [pc, #0x878] */
/* @0x1d3ba4 mov r3, #1 */
/* @0x1d3ba8 ldr r1, [sp, #0x28] */
/* @0x1d3bac mov r0, #16 */
/* @0x1d3bb0 str r12, [sp, #0x1c] */
/* @0x1d3bb4 ldr r12, [sp, #0x24] */
/* @0x1d3bb8 ldr r9, [r12, lr] */
/* @0x1d3bbc ldr lr, [sp, #0x1c] */
/* @0x1d3bc0 ldm r9, {r10, r12} */
/* @0x1d3bc4 and r12, lr, r12 */
/* @0x1d3bc8 str r12, [sp, #0x10] */
/* @0x1d3bcc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d3bd0 ldr r12, [sp, #0x10] */
/* @0x1d3bd4 ldr r1, [sp, #0x1c] */
/* @0x1d3bd8 ldr r2, [r10, r12, lsl #3] */
/* @0x1d3bdc add r3, r10, r12, lsl #3 */
/* @0x1d3be0 cmp r2, #0 */
/* @0x1d3be4 ldrne r2, [r3, #0x4] */
/* @0x1d3be8 str r1, [r0, #0x8] */
/* @0x1d3bec mov r1, r5 */
/* @0x1d3bf0 strne r2, [r0] */
/* @0x1d3bf4 str r5, [r0, #0xc] */
/* @0x1d3bf8 streq r0, [r3, #0x4] */
/* @0x1d3bfc strne r0, [r2, #0x4] */
/* @0x1d3c00 movne r2, #0 */
/* @0x1d3c04 strne r0, [r3, #0x4] */
/* @0x1d3c08 ldr r3, [r9, #0x8] */
/* @0x1d3c0c streq r0, [r10, r12, lsl #3] */
/* @0x1d3c10 mov r12, #0 */
/* @0x1d3c14 streq r2, [r0, #0x4] */
/* @0x1d3c18 add r3, r3, #1 */
/* @0x1d3c1c streq r2, [r0] */
/* @0x1d3c20 strne r2, [r0, #0x4] */
/* @0x1d3c24 mvn r2, #0 */
/* @0x1d3c28 strb r12, [r5, #0x174] */
/* @0x1d3c2c str r2, [r5, #0x170] */
/* @0x1d3c30 ldr r0, [r6] */
/* @0x1d3c34 str r3, [r9, #0x8] */
/* @0x1d3c38 bl 0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance> */
/* @0x1d3c3c mov lr, #1 */
/* @0x1d3c40 strb lr, [r5, #0x6b] */
/* @0x1d3c44 ldr r3, [r4] */
/* @0x1d3c48 mov r0, r4 */
/* @0x1d3c4c add r8, r8, #1 */
/* @0x1d3c50 ldr r3, [r3, #0x4] */
/* @0x1d3c54 blx r3 */
/* @0x1d3c58 ldr r12, [sp, #0x18] */
/* @0x1d3c5c ldr r3, [r7, #0x4] */
/* @0x1d3c60 mov lr, #0 */
/* @0x1d3c64 ldr r2, [r12] */
/* @0x1d3c68 str lr, [r3, r11] */
/* @0x1d3c6c add r11, r11, #4 */
/* @0x1d3c70 cmp r2, r8 */
/* @0x1d3c74 bgt 0x1d3a7c <_Z9StartRoomib+0x19c> */
/* @0x1d3c78 ldr r11, [sp, #0x24] */
/* @0x1d3c7c ldr r4, [r7, #0x4] */
/* @0x1d3c80 cmp r4, #0 */
/* @0x1d3c84 beq 0x1d43c0 <_Z9StartRoomib+0xae0> */
/* @0x1d3c88 ldr r2, [r7] */
/* @0x1d3c8c cmp r2, #0 */
/* @0x1d3c90 ble 0x1d3cb0 <_Z9StartRoomib+0x3d0> */
/* @0x1d3c94 mov r3, #0 */
/* @0x1d3c98 mov r1, r3 */
/* @0x1d3c9c str r1, [r4, r3, lsl #2] */
/* @0x1d3ca0 add r3, r3, #1 */
/* @0x1d3ca4 cmp r3, r2 */
/* @0x1d3ca8 ldr r4, [r7, #0x4] */
/* @0x1d3cac bne 0x1d3c9c <_Z9StartRoomib+0x3bc> */
/* @0x1d3cb0 mov r0, r4 */
/* @0x1d3cb4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d3cb8 mov r3, #0 */
/* @0x1d3cbc str r3, [r7, #0x4] */
/* @0x1d3cc0 ldr r12, [sp, #0x20] */
/* @0x1d3cc4 mov r3, #0 */
/* @0x1d3cc8 str r3, [r7] */
/* @0x1d3ccc cmp r12, #0 */
/* @0x1d3cd0 ldr r12, [sp, #0x18] */
/* @0x1d3cd4 str r3, [r12] */
/* @0x1d3cd8 beq 0x1d3fb0 <_Z9StartRoomib+0x6d0> */
/* @0x1d3cdc ldr r0, [r6] */
/* @0x1d3ce0 bl 0x1abb24 <_ZN5CRoom12RemoveMarkedEv> */
/* @0x1d3ce4 ldr r12, [sp, #0x2c] */
/* @0x1d3ce8 mov r3, #0 */
/* @0x1d3cec cmp r12, #0 */
/* @0x1d3cf0 ldr r12, [sp, #0x18] */
/* @0x1d3cf4 str r3, [r12] */
/* @0x1d3cf8 bne 0x1d41c8 <_Z9StartRoomib+0x8e8> */
/* @0x1d3cfc ldr r12, [sp, #0x20] */
/* @0x1d3d00 cmp r12, #0 */
/* @0x1d3d04 bne 0x1d3e00 <_Z9StartRoomib+0x520> */
/* @0x1d3d08 ldr r3, [r6] */
/* @0x1d3d0c ldr r2, [r3, #0x68] */
/* @0x1d3d10 cmp r2, #0 */
/* @0x1d3d14 beq 0x1d3e00 <_Z9StartRoomib+0x520> */
/* @0x1d3d18 ldr r2, [r3, #0x6c] */
/* @0x1d3d1c cmp r2, #0 */
/* @0x1d3d20 beq 0x1d3e00 <_Z9StartRoomib+0x520> */
/* @0x1d3d24 ldr r3, [pc, #0x70c] */
/* @0x1d3d28 ldr r3, [r11, r3] */
/* @0x1d3d2c ldrb r3, [r3] */
/* @0x1d3d30 cmp r3, #0 */
/* @0x1d3d34 bne 0x1d417c <_Z9StartRoomib+0x89c> */
/* @0x1d3d38 mov r0, #432 */
/* @0x1d3d3c add r5, sp, #48 */
/* @0x1d3d40 bl 0x27c524 <_Znwj> */
/* @0x1d3d44 ldr r3, [sp, #0x20] */
/* @0x1d3d48 mov r1, #0 */
/* @0x1d3d4c mov r2, r1 */
/* @0x1d3d50 str r3, [sp] */
/* @0x1d3d54 str r3, [sp, #0x4] */
/* @0x1d3d58 mov r4, r0 */
/* @0x1d3d5c bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1d3d60 ldr r3, [sp, #0x3c] */
/* @0x1d3d64 sub r3, r3, #1 */
/* @0x1d3d68 bic r3, r3, #-16777216 */
/* @0x1d3d6c bic r3, r3, #3 */
/* @0x1d3d70 cmp r3, #0 */
/* @0x1d3d74 beq 0x1d43dc <_Z9StartRoomib+0xafc> */
/* @0x1d3d78 ldr r2, [r6] */
/* @0x1d3d7c mov r12, #0 */
/* @0x1d3d80 mov r3, r5 */
/* @0x1d3d84 mov r0, r4 */
/* @0x1d3d88 mov r1, r4 */
/* @0x1d3d8c mov lr, #5 */
/* @0x1d3d90 ldr r2, [r2, #0x6c] */
/* @0x1d3d94 str r12, [sp] */
/* @0x1d3d98 str r12, [sp, #0x38] */
/* @0x1d3d9c str r12, [sp, #0x30] */
/* @0x1d3da0 str lr, [sp, #0x3c] */
/* @0x1d3da4 bl 0xcfc60 <_Z12Code_ExecuteP9CInstanceS0_P5CCodeP6RValuei> */
/* @0x1d3da8 ldr r3, [sp, #0x3c] */
/* @0x1d3dac sub r3, r3, #1 */
/* @0x1d3db0 bic r3, r3, #-16777216 */
/* @0x1d3db4 bic r3, r3, #3 */
/* @0x1d3db8 cmp r3, #0 */
/* @0x1d3dbc beq 0x1d43d0 <_Z9StartRoomib+0xaf0> */
/* @0x1d3dc0 cmp r4, #0 */
/* @0x1d3dc4 mov r3, #0 */
/* @0x1d3dc8 mov r2, #5 */
/* @0x1d3dcc str r3, [sp, #0x38] */
/* @0x1d3dd0 str r3, [sp, #0x30] */
/* @0x1d3dd4 str r2, [sp, #0x3c] */
/* @0x1d3dd8 beq 0x1d3dec <_Z9StartRoomib+0x50c> */
/* @0x1d3ddc ldr r3, [r4] */
/* @0x1d3de0 mov r0, r4 */
/* @0x1d3de4 ldr r3, [r3, #0x4] */
/* @0x1d3de8 blx r3 */
/* @0x1d3dec ldr r3, [pc, #0x648] */
/* @0x1d3df0 ldr r3, [r11, r3] */
/* @0x1d3df4 ldrb r3, [r3] */
/* @0x1d3df8 cmp r3, #0 */
/* @0x1d3dfc bne 0x1d4404 <_Z9StartRoomib+0xb24> */
/* @0x1d3e00 mov r0, #7 */
/* @0x1d3e04 mov r1, #4 */
/* @0x1d3e08 bl 0xf33b0 <_Z17Perform_Event_Allii> */
/* @0x1d3e0c ldr r0, [r6] */
/* @0x1d3e10 bl 0x1abb24 <_ZN5CRoom12RemoveMarkedEv> */
/* @0x1d3e14 ldr r3, [sp, #0x3c] */
/* @0x1d3e18 sub r3, r3, #1 */
/* @0x1d3e1c bic r3, r3, #-16777216 */
/* @0x1d3e20 bic r3, r3, #3 */
/* @0x1d3e24 cmp r3, #0 */
/* @0x1d3e28 beq 0x1d41a0 <_Z9StartRoomib+0x8c0> */
/* @0x1d3e2c ldr r3, [pc, #0x60c] */
/* @0x1d3e30 mov r2, #1 */
/* @0x1d3e34 ldr r3, [r11, r3] */
/* @0x1d3e38 strb r2, [r3] */
/* @0x1d3e3c add sp, sp, #68 */
/* @0x1d3e40 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d3e44 mov r5, r3 */
/* @0x1d3e48 ldr r12, [sp, #0x14] */
/* @0x1d3e4c ldrb r3, [r12] */
/* @0x1d3e50 cmp r3, #0 */
/* @0x1d3e54 bne 0x1d3e9c <_Z9StartRoomib+0x5bc> */
/* @0x1d3e58 mov r0, r5 */
/* @0x1d3e5c mov r1, r4 */
/* @0x1d3e60 mov r2, #1 */
/* @0x1d3e64 bl 0x1986ec <_ZN9CInstance6AssignEPS_b> */
/* @0x1d3e68 mov r0, r5 */
/* @0x1d3e6c ldr r1, [r6] */
/* @0x1d3e70 bl 0x192fa4 <_ZN9CInstance18RebuildPhysicsBodyEP5CRoom> */
/* @0x1d3e74 mov lr, #1 */
/* @0x1d3e78 mov r0, #0 */
/* @0x1d3e7c mvn r3, #0 */
/* @0x1d3e80 strb r0, [r5, #0x174] */
/* @0x1d3e84 mov r1, r5 */
/* @0x1d3e88 strb lr, [r5, #0x6b] */
/* @0x1d3e8c str r3, [r5, #0x170] */
/* @0x1d3e90 ldr r0, [r6] */
/* @0x1d3e94 bl 0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance> */
/* @0x1d3e98 b 0x1d3c44 <_Z9StartRoomib+0x364> */
/* @0x1d3e9c ldr r3, [r4, #0x180] */
/* @0x1d3ea0 str r3, [r5, #0x180] */
/* @0x1d3ea4 ldr r0, [r4, #0x78] */
/* @0x1d3ea8 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1d3eac ldr r1, [r10, #0x118] */
/* @0x1d3eb0 ldr r9, [r10, #0x120] */
/* @0x1d3eb4 bic r0, r0, #-2147483648 */
/* @0x1d3eb8 and r3, r0, r1 */
/* @0x1d3ebc lsl lr, r3, #1 */
/* @0x1d3ec0 add r2, lr, r3 */
/* @0x1d3ec4 add r2, r9, r2, lsl #2 */
/* @0x1d3ec8 ldr r2, [r2, #0x8] */
/* @0x1d3ecc cmp r2, #0 */
/* @0x1d3ed0 beq 0x1d3e58 <_Z9StartRoomib+0x578> */
/* @0x1d3ed4 cmp r0, r2 */
/* @0x1d3ed8 beq 0x1d3f48 <_Z9StartRoomib+0x668> */
/* @0x1d3edc ldr r10, [r10, #0x110] */
/* @0x1d3ee0 and r2, r1, r2 */
/* @0x1d3ee4 add r12, r3, r10 */
/* @0x1d3ee8 rsb r2, r2, r12 */
/* @0x1d3eec tst r2, r1 */
/* @0x1d3ef0 bmi 0x1d3e58 <_Z9StartRoomib+0x578> */
/* @0x1d3ef4 mov r12, #0 */
/* @0x1d3ef8 b 0x1d3f14 <_Z9StartRoomib+0x634> */
/* @0x1d3efc and r2, r1, r2 */
/* @0x1d3f00 add lr, r3, r10 */
/* @0x1d3f04 rsb r2, r2, lr */
/* @0x1d3f08 and r2, r2, r1 */
/* @0x1d3f0c cmp r2, r12 */
/* @0x1d3f10 blt 0x1d3e58 <_Z9StartRoomib+0x578> */
/* @0x1d3f14 add r3, r3, #1 */
/* @0x1d3f18 add r12, r12, #1 */
/* @0x1d3f1c and r3, r1, r3 */
/* @0x1d3f20 lsl lr, r3, #1 */
/* @0x1d3f24 add r2, lr, r3 */
/* @0x1d3f28 add r2, r9, r2, lsl #2 */
/* @0x1d3f2c ldr r2, [r2, #0x8] */
/* @0x1d3f30 cmp r2, #0 */
/* @0x1d3f34 beq 0x1d3e58 <_Z9StartRoomib+0x578> */
/* @0x1d3f38 cmp r0, r2 */
/* @0x1d3f3c bne 0x1d3efc <_Z9StartRoomib+0x61c> */
/* @0x1d3f40 cmn r3, #1 */
/* @0x1d3f44 beq 0x1d3e58 <_Z9StartRoomib+0x578> */
/* @0x1d3f48 add r3, lr, r3 */
/* @0x1d3f4c add r9, r9, r3, lsl #2 */
/* @0x1d3f50 cmn r9, #4 */
/* @0x1d3f54 beq 0x1d3e58 <_Z9StartRoomib+0x578> */
/* @0x1d3f58 ldr r3, [r9, #0x4] */
/* @0x1d3f5c cmp r3, #0 */
/* @0x1d3f60 beq 0x1d3e58 <_Z9StartRoomib+0x578> */
/* @0x1d3f64 ldr r1, [r3, #0x20] */
/* @0x1d3f68 cmp r1, #0 */
/* @0x1d3f6c beq 0x1d3e58 <_Z9StartRoomib+0x578> */
/* @0x1d3f70 ldr r0, [r6] */
/* @0x1d3f74 bl 0x1b9e5c <_ZN13CLayerManager14RemoveInstanceEP5CRoomP9CInstance> */
/* @0x1d3f78 b 0x1d3e58 <_Z9StartRoomib+0x578> */
/* @0x1d3f7c ldr r1, [r3, #0x178] */
/* @0x1d3f80 cmp r1, #0 */
/* @0x1d3f84 streq r3, [r5, #0x17c] */
/* @0x1d3f88 strne r1, [r5, #0x178] */
/* @0x1d3f8c ldrne r2, [r3, #0x178] */
/* @0x1d3f90 streq r5, [r3, #0x178] */
/* @0x1d3f94 strne r3, [r5, #0x17c] */
/* @0x1d3f98 streq r5, [r2, #0x84] */
/* @0x1d3f9c strne r5, [r2, #0x17c] */
/* @0x1d3fa0 streq r1, [r5, #0x178] */
/* @0x1d3fa4 strne r5, [r3, #0x178] */
/* @0x1d3fa8 vstr s14, [r5, #388] */
/* @0x1d3fac b 0x1d3b98 <_Z9StartRoomib+0x2b8> */
/* @0x1d3fb0 ldr r3, [r6] */
/* @0x1d3fb4 mov r8, #1 */
/* @0x1d3fb8 ldr r4, [sp, #0x20] */
/* @0x1d3fbc mov r7, #5 */
/* @0x1d3fc0 add r9, sp, #48 */
/* @0x1d3fc4 ldr r12, [r3, #0xa8] */
/* @0x1d3fc8 mov r10, r4 */
/* @0x1d3fcc ldr r0, [r3, #0xa4] */
/* @0x1d3fd0 cmp r4, r12 */
/* @0x1d3fd4 bge 0x1d404c <_Z9StartRoomib+0x76c> */
/* @0x1d3fd8 ldr r2, [pc, #0x440] */
/* @0x1d3fdc ldr r3, [r0, r4, lsl #2] */
/* @0x1d3fe0 ldr r2, [r11, r2] */
/* @0x1d3fe4 ldr r1, [r2, #0x4] */
/* @0x1d3fe8 ldr r2, [r2] */
/* @0x1d3fec and r1, r3, r1 */
/* @0x1d3ff0 ldr r2, [r2, r1, lsl #3] */
/* @0x1d3ff4 cmp r2, #0 */
/* @0x1d3ff8 bne 0x1d400c <_Z9StartRoomib+0x72c> */
/* @0x1d3ffc b 0x1d4040 <_Z9StartRoomib+0x760> */
/* @0x1d4000 ldr r2, [r2, #0x4] */
/* @0x1d4004 cmp r2, #0 */
/* @0x1d4008 beq 0x1d4040 <_Z9StartRoomib+0x760> */
/* @0x1d400c ldr r1, [r2, #0x8] */
/* @0x1d4010 cmp r3, r1 */
/* @0x1d4014 bne 0x1d4000 <_Z9StartRoomib+0x720> */
/* @0x1d4018 ldr r5, [r2, #0xc] */
/* @0x1d401c cmp r5, #0 */
/* @0x1d4020 beq 0x1d4040 <_Z9StartRoomib+0x760> */
/* @0x1d4024 ldrb r3, [r5, #0x6b] */
/* @0x1d4028 cmp r3, #0 */
/* @0x1d402c strbne r10, [r5, #0x6b] */
/* @0x1d4030 bne 0x1d4040 <_Z9StartRoomib+0x760> */
/* @0x1d4034 ldrb r3, [r5, #0x68] */
/* @0x1d4038 cmp r3, #0 */
/* @0x1d403c beq 0x1d4068 <_Z9StartRoomib+0x788> */
/* @0x1d4040 add r4, r4, #1 */
/* @0x1d4044 cmp r4, r12 */
/* @0x1d4048 blt 0x1d3fd8 <_Z9StartRoomib+0x6f8> */
/* @0x1d404c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d4050 ldr r3, [r6] */
/* @0x1d4054 mov r2, #0 */
/* @0x1d4058 mov r0, r3 */
/* @0x1d405c str r2, [r3, #0xa4] */
/* @0x1d4060 str r2, [r3, #0xa8] */
/* @0x1d4064 b 0x1d3ce0 <_Z9StartRoomib+0x400> */
/* @0x1d4068 ldr r2, [r5, #0x7c] */
/* @0x1d406c mov r0, r5 */
/* @0x1d4070 str r3, [sp] */
/* @0x1d4074 mov r1, r5 */
/* @0x1d4078 mov r3, #14 */
/* @0x1d407c bl 0xf32e4 <_Z20Perform_Event_ObjectP9CInstanceS0_iii> */
/* @0x1d4080 ldr r2, [r5, #0x164] */
/* @0x1d4084 cmp r2, #0 */
/* @0x1d4088 beq 0x1d40e8 <_Z9StartRoomib+0x808> */
/* @0x1d408c ldr r3, [sp, #0x3c] */
/* @0x1d4090 sub r3, r3, #1 */
/* @0x1d4094 bic r3, r3, #-16777216 */
/* @0x1d4098 bic r3, r3, #3 */
/* @0x1d409c cmp r3, #0 */
/* @0x1d40a0 beq 0x1d431c <_Z9StartRoomib+0xa3c> */
/* @0x1d40a4 mov r3, r9 */
/* @0x1d40a8 str r8, [sp] */
/* @0x1d40ac mov r0, r5 */
/* @0x1d40b0 mov r1, r5 */
/* @0x1d40b4 str r10, [sp, #0x38] */
/* @0x1d40b8 str r7, [sp, #0x3c] */
/* @0x1d40bc str r10, [sp, #0x30] */
/* @0x1d40c0 bl 0xcfc60 <_Z12Code_ExecuteP9CInstanceS0_P5CCodeP6RValuei> */
/* @0x1d40c4 ldr r3, [sp, #0x3c] */
/* @0x1d40c8 sub r3, r3, #1 */
/* @0x1d40cc bic r3, r3, #-16777216 */
/* @0x1d40d0 bic r3, r3, #3 */
/* @0x1d40d4 cmp r3, #0 */
/* @0x1d40d8 beq 0x1d4330 <_Z9StartRoomib+0xa50> */
/* @0x1d40dc str r10, [sp, #0x38] */
/* @0x1d40e0 str r7, [sp, #0x3c] */
/* @0x1d40e4 str r10, [sp, #0x30] */
/* @0x1d40e8 ldr r2, [r5, #0x7c] */
/* @0x1d40ec mov r0, r5 */
/* @0x1d40f0 str r10, [sp] */
/* @0x1d40f4 mov r1, r5 */
/* @0x1d40f8 mov r3, #0 */
/* @0x1d40fc bl 0xf32e4 <_Z20Perform_Event_ObjectP9CInstanceS0_iii> */
/* @0x1d4100 ldr r2, [r5, #0x160] */
/* @0x1d4104 cmp r2, #0 */
/* @0x1d4108 beq 0x1d4168 <_Z9StartRoomib+0x888> */
/* @0x1d410c ldr r3, [sp, #0x3c] */
/* @0x1d4110 sub r3, r3, #1 */
/* @0x1d4114 bic r3, r3, #-16777216 */
/* @0x1d4118 bic r3, r3, #3 */
/* @0x1d411c cmp r3, #0 */
/* @0x1d4120 beq 0x1d433c <_Z9StartRoomib+0xa5c> */
/* @0x1d4124 mov r3, r9 */
/* @0x1d4128 str r8, [sp] */
/* @0x1d412c mov r0, r5 */
/* @0x1d4130 mov r1, r5 */
/* @0x1d4134 str r10, [sp, #0x38] */
/* @0x1d4138 str r7, [sp, #0x3c] */
/* @0x1d413c str r10, [sp, #0x30] */
/* @0x1d4140 bl 0xcfc60 <_Z12Code_ExecuteP9CInstanceS0_P5CCodeP6RValuei> */
/* @0x1d4144 ldr r3, [sp, #0x3c] */
/* @0x1d4148 sub r3, r3, #1 */
/* @0x1d414c bic r3, r3, #-16777216 */
/* @0x1d4150 bic r3, r3, #3 */
/* @0x1d4154 cmp r3, #0 */
/* @0x1d4158 beq 0x1d4310 <_Z9StartRoomib+0xa30> */
/* @0x1d415c str r10, [sp, #0x38] */
/* @0x1d4160 str r7, [sp, #0x3c] */
/* @0x1d4164 str r10, [sp, #0x30] */
/* @0x1d4168 ldr r3, [r6] */
/* @0x1d416c strb r8, [r5, #0x6c] */
/* @0x1d4170 ldr r12, [r3, #0xa8] */
/* @0x1d4174 ldr r0, [r3, #0xa4] */
/* @0x1d4178 b 0x1d4040 <_Z9StartRoomib+0x760> */
/* @0x1d417c ldr r1, [pc, #0x2c0] */
/* @0x1d4180 add r3, sp, #48 */
/* @0x1d4184 ldr r12, [sp, #0x20] */
/* @0x1d4188 ldr r1, [r11, r1] */
/* @0x1d418c str r12, [sp] */
/* @0x1d4190 ldr r0, [r1] */
/* @0x1d4194 mov r1, r0 */
/* @0x1d4198 bl 0xcfc60 <_Z12Code_ExecuteP9CInstanceS0_P5CCodeP6RValuei> */
/* @0x1d419c b 0x1d3dec <_Z9StartRoomib+0x50c> */
/* @0x1d41a0 add r0, sp, #48 */
/* @0x1d41a4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1d41a8 b 0x1d3e2c <_Z9StartRoomib+0x54c> */
/* @0x1d41ac ldr r1, [r5, #0x180] */
/* @0x1d41b0 str r5, [r2, #0x84] */
/* @0x1d41b4 str r5, [r2, #0x80] */
/* @0x1d41b8 str r1, [r5, #0x184] */
/* @0x1d41bc str r3, [r5, #0x17c] */
/* @0x1d41c0 str r3, [r5, #0x178] */
/* @0x1d41c4 b 0x1d3b98 <_Z9StartRoomib+0x2b8> */
/* @0x1d41c8 mov r0, #7 */
/* @0x1d41cc mov r1, #2 */
/* @0x1d41d0 bl 0xf33b0 <_Z17Perform_Event_Allii> */
/* @0x1d41d4 ldr r0, [r6] */
/* @0x1d41d8 bl 0x1abb24 <_ZN5CRoom12RemoveMarkedEv> */
/* @0x1d41dc b 0x1d3cfc <_Z9StartRoomib+0x41c> */
/* @0x1d41e0 ldr r3, [pc, #0x260] */
/* @0x1d41e4 ldr r0, [r11, r3] */
/* @0x1d41e8 bl 0x16ec9c <_ZN14CCameraManager9StartRoomEv> */
/* @0x1d41ec b 0x1d3a30 <_Z9StartRoomib+0x150> */
/* @0x1d41f0 mov r0, #292 */
/* @0x1d41f4 bl 0x27c524 <_Znwj> */
/* @0x1d41f8 mov r5, r0 */
/* @0x1d41fc bl 0x1ad2cc <_ZN5CRoomC2Ev> */
/* @0x1d4200 ldm r4, {r2, r3} */
/* @0x1d4204 mov r0, r7 */
/* @0x1d4208 cmp r7, r2 */
/* @0x1d420c str r5, [r3, r7, lsl #2] */
/* @0x1d4210 ldrlt r3, [r4, #0x4] */
/* @0x1d4214 ldrge r5, [sp, #0x20] */
/* @0x1d4218 ldrlt r5, [r3, r7, lsl #2] */
/* @0x1d421c bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x1d4220 mov r2, #1 */
/* @0x1d4224 mov r1, r0 */
/* @0x1d4228 mov r0, r5 */
/* @0x1d422c bl 0x1ad70c <_ZN5CRoom6AssignEPS_b> */
/* @0x1d4230 ldr r3, [r4] */
/* @0x1d4234 cmp r7, r3 */
/* @0x1d4238 ldrlt r3, [r4, #0x4] */
/* @0x1d423c movge r0, #0 */
/* @0x1d4240 ldrlt r0, [r3, r7, lsl #2] */
/* @0x1d4244 bl 0x1cba58 <_Z12Run_Room_SetP5CRoom> */
/* @0x1d4248 b 0x1d3a18 <_Z9StartRoomib+0x138> */
/* @0x1d424c add r6, r7, #1 */
/* @0x1d4250 cmp r5, r6 */
/* @0x1d4254 beq 0x1d43f0 <_Z9StartRoomib+0xb10> */
/* @0x1d4258 cmp r6, #0 */
/* @0x1d425c ldr r0, [r4, #0x4] */
/* @0x1d4260 bne 0x1d4350 <_Z9StartRoomib+0xa70> */
/* @0x1d4264 cmp r0, #0 */
/* @0x1d4268 beq 0x1d42f8 <_Z9StartRoomib+0xa18> */
/* @0x1d426c cmp r5, #0 */
/* @0x1d4270 ble 0x1d42f8 <_Z9StartRoomib+0xa18> */
/* @0x1d4274 mov r8, r6 */
/* @0x1d4278 mov r10, r6 */
/* @0x1d427c mov r3, r0 */
/* @0x1d4280 str r5, [sp, #0x14] */
/* @0x1d4284 ldr r1, [r3] */
/* @0x1d4288 movw r2, #0xfeee */
/* @0x1d428c movt r2, #0xfeee */
/* @0x1d4290 cmp r1, r2 */
/* @0x1d4294 beq 0x1d42e0 <_Z9StartRoomib+0xa00> */
/* @0x1d4298 ldr r9, [r3, r8, lsl #2] */
/* @0x1d429c lsl r5, r8, #2 */
/* @0x1d42a0 add r1, r3, r5 */
/* @0x1d42a4 cmp r9, #0 */
/* @0x1d42a8 beq 0x1d42e0 <_Z9StartRoomib+0xa00> */
/* @0x1d42ac ldr r0, [r9] */
/* @0x1d42b0 movw r3, #0xfeee */
/* @0x1d42b4 movt r3, #0xfeee */
/* @0x1d42b8 cmp r0, r3 */
/* @0x1d42bc beq 0x1d42d8 <_Z9StartRoomib+0x9f8> */
/* @0x1d42c0 mov r0, r9 */
/* @0x1d42c4 bl 0x1afa00 <_ZN5CRoomD2Ev> */
/* @0x1d42c8 mov r0, r9 */
/* @0x1d42cc bl 0x27d1d0 <_ZdlPv> */
/* @0x1d42d0 ldr r1, [r4, #0x4] */
/* @0x1d42d4 add r1, r1, r5 */
/* @0x1d42d8 str r10, [r1] */
/* @0x1d42dc ldr r3, [r4, #0x4] */
/* @0x1d42e0 ldr r2, [r4] */
/* @0x1d42e4 add r8, r8, #1 */
/* @0x1d42e8 cmp r8, r2 */
/* @0x1d42ec blt 0x1d4284 <_Z9StartRoomib+0x9a4> */
/* @0x1d42f0 ldr r5, [sp, #0x14] */
/* @0x1d42f4 mov r0, r3 */
/* @0x1d42f8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d42fc mov r3, #0 */
/* @0x1d4300 str r3, [r4, #0x4] */
/* @0x1d4304 b 0x1d4374 <_Z9StartRoomib+0xa94> */
/* @0x1d4308 bl 0x18c2c8 <_Z8IO_Clearv> */
/* @0x1d430c b 0x1d3918 <_Z9StartRoomib+0x38> */
/* @0x1d4310 mov r0, r9 */
/* @0x1d4314 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1d4318 b 0x1d415c <_Z9StartRoomib+0x87c> */
/* @0x1d431c mov r0, r9 */
/* @0x1d4320 str r2, [sp, #0x10] */
/* @0x1d4324 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1d4328 ldr r2, [sp, #0x10] */
/* @0x1d432c b 0x1d40a4 <_Z9StartRoomib+0x7c4> */
/* @0x1d4330 mov r0, r9 */
/* @0x1d4334 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1d4338 b 0x1d40dc <_Z9StartRoomib+0x7fc> */
/* @0x1d433c mov r0, r9 */
/* @0x1d4340 str r2, [sp, #0x10] */
/* @0x1d4344 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1d4348 ldr r2, [sp, #0x10] */
/* @0x1d434c b 0x1d4124 <_Z9StartRoomib+0x844> */
/* @0x1d4350 lsls r1, r6, #2 */
/* @0x1d4354 beq 0x1d42f8 <_Z9StartRoomib+0xa18> */
/* @0x1d4358 ldr r2, [pc, #0xec] */
/* @0x1d435c mov r3, #0 */
/* @0x1d4360 str r3, [sp] */
/* @0x1d4364 mov r3, #135 */
/* @0x1d4368 add r2, pc, r2 */
/* @0x1d436c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1d4370 str r0, [r4, #0x4] */
/* @0x1d4374 cmp r5, r6 */
/* @0x1d4378 str r6, [r4] */
/* @0x1d437c bge 0x1d43a4 <_Z9StartRoomib+0xac4> */
/* @0x1d4380 lsl r3, r5, #2 */
/* @0x1d4384 mov r1, #0 */
/* @0x1d4388 ldr r2, [r4, #0x4] */
/* @0x1d438c add r5, r5, #1 */
/* @0x1d4390 str r1, [r2, r3] */
/* @0x1d4394 add r3, r3, #4 */
/* @0x1d4398 ldr r6, [r4] */
/* @0x1d439c cmp r6, r5 */
/* @0x1d43a0 bgt 0x1d4388 <_Z9StartRoomib+0xaa8> */
/* @0x1d43a4 ldr r3, [pc, #0x6c] */
/* @0x1d43a8 cmp r7, r6 */
/* @0x1d43ac movge r0, #0 */
/* @0x1d43b0 ldr r3, [r11, r3] */
/* @0x1d43b4 str r7, [r3] */
/* @0x1d43b8 bge 0x1d3944 <_Z9StartRoomib+0x64> */
/* @0x1d43bc b 0x1d393c <_Z9StartRoomib+0x5c> */
/* @0x1d43c0 mov r0, r4 */
/* @0x1d43c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d43c8 str r4, [r7, #0x4] */
/* @0x1d43cc b 0x1d3cc0 <_Z9StartRoomib+0x3e0> */
/* @0x1d43d0 mov r0, r5 */
/* @0x1d43d4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1d43d8 b 0x1d3dc0 <_Z9StartRoomib+0x4e0> */
/* @0x1d43dc mov r0, r5 */
/* @0x1d43e0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1d43e4 b 0x1d3d78 <_Z9StartRoomib+0x498> */
/* @0x1d43e8 ldr r7, [r11, r3] */
/* @0x1d43ec b 0x1d3c7c <_Z9StartRoomib+0x39c> */
/* @0x1d43f0 ldr r3, [pc, #0x20] */
/* @0x1d43f4 mov r0, #0 */
/* @0x1d43f8 ldr r3, [r11, r3] */
/* @0x1d43fc str r7, [r3] */
/* @0x1d4400 b 0x1d3944 <_Z9StartRoomib+0x64> */
/* @0x1d4404 mov r0, #0 */
/* @0x1d4408 bl 0xb6688 <exit@plt> */
/* @0x1d440c eoreq lr, r1, r8, asr r3 */
/* @0x1d4410 .word 0xffffc154 */
/* @0x1d4414 .word 0xffffeed8 */
/* @0x1d4418 .word 0xffffd784 */
/* @0x1d441c .word 0xffffbcd8 */
/* @0x1d4420 .word 0xffffbff4 */
/* @0x1d4424 andseq r9, r7, r12, lsr #6 */
/* @0x1d4428 .word 0xffffbcd4 */
/* @0x1d442c .word 0xffffeef4 */
/* @0x1d4430 .word 0xffffeef8 */
/* @0x1d4434 andseq r9, r7, r4, asr #4 */
/* @0x1d4438 .word 0xffffbf68 */
/* @0x1d443c .word 0xffffef38 */
/* @0x1d4440 .word 0xffffef3c */
/* @0x1d4444 .word 0xffffbf64 */
/* @0x1d4448 .word 0xffffc024 */
/* @0x1d444c andseq r8, r7, r8, lsl #31 */

/* ── FUNC 0x1d4450 · SwitchRoom(int) · size=172 · insn=43 */
/* @0x1d4450 push {r3, r4, r5, lr} */
/* @0x1d4454 mov r4, r0 */
/* @0x1d4458 ldr r3, [pc, #0x88] */
/* @0x1d445c ldr r3, [pc, r3] */
/* @0x1d4460 ldrb r3, [r3] */
/* @0x1d4464 cmp r3, #0 */
/* @0x1d4468 beq 0x1d4480 <_Z10SwitchRoomi+0x30> */
/* @0x1d446c ldr r3, [pc, #0x78] */
/* @0x1d4470 ldr r3, [pc, r3] */
/* @0x1d4474 ldr r3, [r3] */
/* @0x1d4478 cmp r3, #0 */
/* @0x1d447c beq 0x1d44b0 <_Z10SwitchRoomi+0x60> */
/* @0x1d4480 mov r0, r4 */
/* @0x1d4484 bl 0x1b530c <_Z9Room_Namei> */
/* @0x1d4488 mov r1, r0 */
/* @0x1d448c ldr r0, [pc, #0x5c] */
/* @0x1d4490 add r0, pc, r0 */
/* @0x1d4494 bl 0x27ba28 <_Z11memLogEventPKcz> */
/* @0x1d4498 mov r0, #0 */
/* @0x1d449c bl 0x1d1724 <_Z7EndRoomb> */
/* @0x1d44a0 mov r0, r4 */
/* @0x1d44a4 mov r1, #0 */
/* @0x1d44a8 pop {r3, r4, r5, lr} */
/* @0x1d44ac b 0x1d38e0 <_Z9StartRoomib> */
/* @0x1d44b0 ldr r3, [pc, #0x3c] */
/* @0x1d44b4 ldr r3, [pc, r3] */
/* @0x1d44b8 ldr r0, [r3] */
/* @0x1d44bc bl 0x1b530c <_Z9Room_Namei> */
/* @0x1d44c0 mov r5, r0 */
/* @0x1d44c4 mov r0, r4 */
/* @0x1d44c8 bl 0x1b530c <_Z9Room_Namei> */
/* @0x1d44cc ldr r1, [pc, #0x24] */
/* @0x1d44d0 mov r2, r5 */
/* @0x1d44d4 add r1, pc, r1 */
/* @0x1d44d8 mov r3, r0 */
/* @0x1d44dc mov r0, #2 */
/* @0x1d44e0 bl 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz> */
/* @0x1d44e4 b 0x1d4480 <_Z10SwitchRoomi+0x30> */
/* @0x1d44e8 eoreq r9, r1, r8, asr #9 */
/* @0x1d44ec .word 0x00219fb0 */
/* @0x1d44f0 andseq r12, r7, r12, lsl #25 */
/* @0x1d44f4 eoreq r10, r1, r0, lsr #30 */
/* @0x1d44f8 andseq r12, r7, r12, lsr #24 */

/* ── FUNC 0x1d44fc · StartGame() · size=636 · insn=159 */
/* @0x1d44fc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1d4500 sub sp, sp, #8 */
/* @0x1d4504 ldr r6, [pc, #0x22c] */
/* @0x1d4508 ldr r3, [pc, #0x22c] */
/* @0x1d450c add r6, pc, r6 */
/* @0x1d4510 ldr r3, [r6, r3] */
/* @0x1d4514 ldrb r3, [r3] */
/* @0x1d4518 cmp r3, #0 */
/* @0x1d451c beq 0x1d4538 <_Z9StartGamev+0x3c> */
/* @0x1d4520 ldr r2, [pc, #0x218] */
/* @0x1d4524 ldr r3, [pc, #0x218] */
/* @0x1d4528 ldr r2, [r6, r2] */
/* @0x1d452c ldr r3, [r6, r3] */
/* @0x1d4530 ldr r2, [r2] */
/* @0x1d4534 str r2, [r3] */
/* @0x1d4538 bl 0x19e7dc <_Z19Create_Object_Listsv> */
/* @0x1d453c ldr r3, [pc, #0x204] */
/* @0x1d4540 ldr r0, [pc, #0x204] */
/* @0x1d4544 mov r4, #0 */
/* @0x1d4548 ldr r1, [pc, #0x200] */
/* @0x1d454c mvn r5, #0 */
/* @0x1d4550 ldr r12, [r6, r3] */
/* @0x1d4554 ldr r2, [pc, #0x1f8] */
/* @0x1d4558 ldr r3, [pc, #0x1f8] */
/* @0x1d455c str r4, [r12] */
/* @0x1d4560 ldr r0, [r6, r0] */
/* @0x1d4564 str r5, [r0] */
/* @0x1d4568 ldr r1, [r6, r1] */
/* @0x1d456c str r5, [r1] */
/* @0x1d4570 ldr r2, [r6, r2] */
/* @0x1d4574 str r4, [r2] */
/* @0x1d4578 ldr r3, [r6, r3] */
/* @0x1d457c str r4, [r3] */
/* @0x1d4580 bl 0xf63f0 <_Z20Extension_Initializev> */
/* @0x1d4584 cmp r0, r4 */
/* @0x1d4588 beq 0x1d46d0 <_Z9StartGamev+0x1d4> */
/* @0x1d458c ldr r3, [pc, #0x1c8] */
/* @0x1d4590 ldr r3, [r6, r3] */
/* @0x1d4594 ldrb r3, [r3] */
/* @0x1d4598 cmp r3, r4 */
/* @0x1d459c moveq r0, r5 */
/* @0x1d45a0 movne r0, r4 */
/* @0x1d45a4 bl 0x17af8c <_Z20GR_Window_Set_Cursori> */
/* @0x1d45a8 ldr r3, [pc, #0x1b0] */
/* @0x1d45ac ldr r3, [r6, r3] */
/* @0x1d45b0 ldrb r0, [r3] */
/* @0x1d45b4 bl 0x168710 <_Z32GR_D3D_Set_Texture_Interpolationb> */
/* @0x1d45b8 bl 0x1b523c <_Z11Room_Numberv> */
/* @0x1d45bc ldr r3, [pc, #0x1a0] */
/* @0x1d45c0 ldr r5, [r6, r3] */
/* @0x1d45c4 ldr r2, [r5] */
/* @0x1d45c8 cmp r0, r2 */
/* @0x1d45cc mov r9, r0 */
/* @0x1d45d0 beq 0x1d4678 <_Z9StartGamev+0x17c> */
/* @0x1d45d4 cmp r0, #0 */
/* @0x1d45d8 bne 0x1d46d8 <_Z9StartGamev+0x1dc> */
/* @0x1d45dc ldr r3, [r5, #0x4] */
/* @0x1d45e0 cmp r3, #0 */
/* @0x1d45e4 beq 0x1d4664 <_Z9StartGamev+0x168> */
/* @0x1d45e8 cmp r2, #0 */
/* @0x1d45ec ble 0x1d4664 <_Z9StartGamev+0x168> */
/* @0x1d45f0 mov r4, r0 */
/* @0x1d45f4 mov r10, r0 */
/* @0x1d45f8 ldr r0, [r3] */
/* @0x1d45fc movw r2, #0xfeee */
/* @0x1d4600 movt r2, #0xfeee */
/* @0x1d4604 movw r1, #0xfeee */
/* @0x1d4608 cmp r0, r2 */
/* @0x1d460c movt r1, #0xfeee */
/* @0x1d4610 lsl r8, r4, #2 */
/* @0x1d4614 beq 0x1d4654 <_Z9StartGamev+0x158> */
/* @0x1d4618 ldr r7, [r3, r4, lsl #2] */
/* @0x1d461c add r2, r3, r8 */
/* @0x1d4620 cmp r7, #0 */
/* @0x1d4624 mov r0, r7 */
/* @0x1d4628 beq 0x1d4654 <_Z9StartGamev+0x158> */
/* @0x1d462c ldr r3, [r7] */
/* @0x1d4630 cmp r3, r1 */
/* @0x1d4634 beq 0x1d464c <_Z9StartGamev+0x150> */
/* @0x1d4638 bl 0x1afa00 <_ZN5CRoomD2Ev> */
/* @0x1d463c mov r0, r7 */
/* @0x1d4640 bl 0x27d1d0 <_ZdlPv> */
/* @0x1d4644 ldr r2, [r5, #0x4] */
/* @0x1d4648 add r2, r2, r8 */
/* @0x1d464c str r10, [r2] */
/* @0x1d4650 ldr r3, [r5, #0x4] */
/* @0x1d4654 ldr r2, [r5] */
/* @0x1d4658 add r4, r4, #1 */
/* @0x1d465c cmp r4, r2 */
/* @0x1d4660 blt 0x1d45f8 <_Z9StartGamev+0xfc> */
/* @0x1d4664 mov r0, r3 */
/* @0x1d4668 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d466c mov r3, #0 */
/* @0x1d4670 str r3, [r5, #0x4] */
/* @0x1d4674 str r9, [r5] */
/* @0x1d4678 mov r4, #0 */
/* @0x1d467c mov r7, r4 */
/* @0x1d4680 b 0x1d4690 <_Z9StartGamev+0x194> */
/* @0x1d4684 ldr r3, [r5, #0x4] */
/* @0x1d4688 str r7, [r3, r4, lsl #2] */
/* @0x1d468c add r4, r4, #1 */
/* @0x1d4690 bl 0x1b523c <_Z11Room_Numberv> */
/* @0x1d4694 cmp r4, r0 */
/* @0x1d4698 blt 0x1d4684 <_Z9StartGamev+0x188> */
/* @0x1d469c ldr r2, [pc, #0xc4] */
/* @0x1d46a0 mov r1, #0 */
/* @0x1d46a4 ldr r3, [pc, #0xc0] */
/* @0x1d46a8 ldr r2, [r6, r2] */
/* @0x1d46ac str r1, [r2] */
/* @0x1d46b0 ldr r3, [r6, r3] */
/* @0x1d46b4 ldrb r3, [r3] */
/* @0x1d46b8 cmp r3, r1 */
/* @0x1d46bc beq 0x1d4704 <_Z9StartGamev+0x208> */
/* @0x1d46c0 mov r0, #0 */
/* @0x1d46c4 add sp, sp, #8 */
/* @0x1d46c8 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1d46cc b 0x27c28c <_ZN13MemoryManager10DumpMemoryEP7__sFILE> */
/* @0x1d46d0 add sp, sp, #8 */
/* @0x1d46d4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1d46d8 lsls r1, r0, #2 */
/* @0x1d46dc beq 0x1d4730 <_Z9StartGamev+0x234> */
/* @0x1d46e0 ldr r2, [pc, #0x88] */
/* @0x1d46e4 mov r3, #0 */
/* @0x1d46e8 ldr r0, [r5, #0x4] */
/* @0x1d46ec add r2, pc, r2 */
/* @0x1d46f0 str r3, [sp] */
/* @0x1d46f4 mov r3, #135 */
/* @0x1d46f8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1d46fc str r0, [r5, #0x4] */
/* @0x1d4700 b 0x1d4674 <_Z9StartGamev+0x178> */
/* @0x1d4704 bl 0x1b5d08 <_Z10Room_Firstv> */
/* @0x1d4708 ldr r3, [pc, #0x64] */
/* @0x1d470c mov r1, #1 */
/* @0x1d4710 ldr r4, [r6, r3] */
/* @0x1d4714 str r0, [r4] */
/* @0x1d4718 bl 0x1d38e0 <_Z9StartRoomib> */
/* @0x1d471c ldr r0, [r4] */
/* @0x1d4720 cmp r0, #0 */
/* @0x1d4724 blt 0x1d46c0 <_Z9StartGamev+0x1c4> */
/* @0x1d4728 bl 0x1d4450 <_Z10SwitchRoomi> */
/* @0x1d472c b 0x1d46c0 <_Z9StartGamev+0x1c4> */
/* @0x1d4730 ldr r3, [r5, #0x4] */
/* @0x1d4734 b 0x1d4664 <_Z9StartGamev+0x168> */
/* @0x1d4738 eoreq sp, r1, r4, asr #14 */
/* @0x1d473c .word 0xffffbcd4 */
/* @0x1d4740 .word 0xffffeb14 */
/* @0x1d4744 .word 0xffffc0ac */
/* @0x1d4748 .word 0xffffce34 */
/* @0x1d474c .word 0xffffd780 */
/* @0x1d4750 .word 0xffffd798 */
/* @0x1d4754 .word 0xffffebf0 */
/* @0x1d4758 .word 0xffffc458 */
/* @0x1d475c .word 0xffffd79c */
/* @0x1d4760 .word 0xffffe4d8 */
/* @0x1d4764 .word 0xffffeed8 */
/* @0x1d4768 .word 0xffffeef4 */
/* @0x1d476c .word 0xffffdf9c */
/* @0x1d4770 andseq r8, r7, r4, lsl #24 */
/* @0x1d4774 .word 0xffffc154 */

/* ── FUNC 0x1d4778 · MainLoop_Process() · size=1632 · insn=408 */
/* @0x1d4778 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d477c vpush {d8} */
/* @0x1d4780 sub sp, sp, #20 */
/* @0x1d4784 ldr r8, [pc, #0x518] */
/* @0x1d4788 ldr r3, [pc, #0x518] */
/* @0x1d478c add r8, pc, r8 */
/* @0x1d4790 ldr r3, [r8, r3] */
/* @0x1d4794 mov r0, r3 */
/* @0x1d4798 str r3, [sp, #0x8] */
/* @0x1d479c bl 0x2a03f8 <_ZN9CProfiler10BeginFrameEv> */
/* @0x1d47a0 bl 0x27d23c <_ZN13MemoryManager11Memory_TickEv> */
/* @0x1d47a4 bl 0x215148 <Timing_Time> */
/* @0x1d47a8 ldr r2, [pc, #0x4fc] */
/* @0x1d47ac ldr r3, [pc, #0x4fc] */
/* @0x1d47b0 ldr r4, [r8, r2] */
/* @0x1d47b4 strd r0, r1, [r4] */
/* @0x1d47b8 ldr r6, [r8, r3] */
/* @0x1d47bc ldrd r2, r3, [r6] */
/* @0x1d47c0 cmp r0, r2 */
/* @0x1d47c4 sbcs r12, r1, r3 */
/* @0x1d47c8 ldr r3, [pc, #0x4e4] */
/* @0x1d47cc strdlt r0, r1, [r6] */
/* @0x1d47d0 ldr r3, [r8, r3] */
/* @0x1d47d4 str r3, [sp, #0x4] */
/* @0x1d47d8 ldrb r3, [r3] */
/* @0x1d47dc cmp r3, #0 */
/* @0x1d47e0 bne 0x1d4c20 <_Z16MainLoop_Processv+0x4a8> */
/* @0x1d47e4 ldr r3, [pc, #0x4cc] */
/* @0x1d47e8 ldr r3, [r8, r3] */
/* @0x1d47ec ldr r3, [r3] */
/* @0x1d47f0 cmp r3, #0 */
/* @0x1d47f4 beq 0x1d4dac <_Z16MainLoop_Processv+0x634> */
/* @0x1d47f8 ldr r11, [r3, #0xc] */
/* @0x1d47fc mov r7, #1 */
/* @0x1d4800 cmp r11, #0 */
/* @0x1d4804 movle r11, #1 */
/* @0x1d4808 strle r11, [r3, #0xc] */
/* @0x1d480c ldr r3, [pc, #0x4a8] */
/* @0x1d4810 mov r0, #0 */
/* @0x1d4814 ldr r3, [r8, r3] */
/* @0x1d4818 str r11, [r3] */
/* @0x1d481c bl 0xb67fc <time@plt> */
/* @0x1d4820 ldr r3, [pc, #0x498] */
/* @0x1d4824 ldr r12, [pc, #0x498] */
/* @0x1d4828 ldrd r4, r5, [r4] */
/* @0x1d482c ldr lr, [r8, r3] */
/* @0x1d4830 ldrd r2, r3, [r6] */
/* @0x1d4834 ldr r1, [pc, #0x48c] */
/* @0x1d4838 subs r4, r4, r2 */
/* @0x1d483c sbc r5, r5, r3 */
/* @0x1d4840 asr r3, r0, #31 */
/* @0x1d4844 mov r2, r0 */
/* @0x1d4848 strd r2, r3, [lr] */
/* @0x1d484c ldr r12, [r8, r12] */
/* @0x1d4850 strd r4, r5, [r12] */
/* @0x1d4854 ldr r10, [r8, r1] */
/* @0x1d4858 ldrb r3, [r10] */
/* @0x1d485c cmp r3, #0 */
/* @0x1d4860 beq 0x1d487c <_Z16MainLoop_Processv+0x104> */
/* @0x1d4864 ldr r3, [pc, #0x460] */
/* @0x1d4868 ldr r3, [r8, r3] */
/* @0x1d486c ldrd r2, r3, [r3] */
/* @0x1d4870 subs r4, r4, r2 */
/* @0x1d4874 sbc r5, r5, r3 */
/* @0x1d4878 strd r4, r5, [r12] */
/* @0x1d487c ldr r0, [sp, #0x4] */
/* @0x1d4880 ldrb r3, [r0] */
/* @0x1d4884 cmp r3, #0 */
/* @0x1d4888 beq 0x1d48a4 <_Z16MainLoop_Processv+0x12c> */
/* @0x1d488c ldr r3, [pc, #0x480] */
/* @0x1d4890 ldr r3, [r8, r3] */
/* @0x1d4894 vldr d7, [r3, #24] */
/* @0x1d4898 vcmpe.f64 d7, #0 */
/* @0x1d489c vmrs APSR_nzcv, fpscr */
/* @0x1d48a0 ble 0x1d4d2c <_Z16MainLoop_Processv+0x5b4> */
/* @0x1d48a4 vmov s14, r11 */
/* @0x1d48a8 vldr s16, [pc, #1004] */
/* @0x1d48ac ldrd r0, r1, [r12] */
/* @0x1d48b0 vcvt.f32.s32 s17, s14 */
/* @0x1d48b4 bl 0x319398 <__floatdisf> */
/* @0x1d48b8 vdiv.f32 s17, s16, s17 */
/* @0x1d48bc vmov s14, r0 */
/* @0x1d48c0 vsub.f32 s15, s17, s14 */
/* @0x1d48c4 vcmpe.f32 s15, #0 */
/* @0x1d48c8 vmrs APSR_nzcv, fpscr */
/* @0x1d48cc bmi 0x1d4c64 <_Z16MainLoop_Processv+0x4ec> */
/* @0x1d48d0 vmov r0, s15 */
/* @0x1d48d4 bl 0x319468 <__fixsfdi> */
/* @0x1d48d8 ldr r3, [pc, #0x42c] */
/* @0x1d48dc ldr r4, [r8, r3] */
/* @0x1d48e0 strd r0, r1, [r4] */
/* @0x1d48e4 bl 0x319398 <__floatdisf> */
/* @0x1d48e8 vmov s14, r0 */
/* @0x1d48ec vcmpe.f32 s14, s16 */
/* @0x1d48f0 vmrs APSR_nzcv, fpscr */
/* @0x1d48f4 movwpl r0, #0x4240 */
/* @0x1d48f8 movpl r1, #0 */
/* @0x1d48fc movtpl r0, #0xf */
/* @0x1d4900 bmi 0x1d4dd0 <_Z16MainLoop_Processv+0x658> */
/* @0x1d4904 stm r4, {r0, r1} */
/* @0x1d4908 ldr r3, [pc, #0x3c0] */
/* @0x1d490c ldr r3, [r8, r3] */
/* @0x1d4910 ldrb r3, [r3] */
/* @0x1d4914 cmp r3, #0 */
/* @0x1d4918 beq 0x1d4a1c <_Z16MainLoop_Processv+0x2a4> */
/* @0x1d491c ldr r3, [pc, #0x3b0] */
/* @0x1d4920 ldr r3, [r8, r3] */
/* @0x1d4924 ldrb r3, [r3] */
/* @0x1d4928 cmp r3, #0 */
/* @0x1d492c bne 0x1d49e4 <_Z16MainLoop_Processv+0x26c> */
/* @0x1d4930 ldr r3, [pc, #0x3a0] */
/* @0x1d4934 ldr r3, [r8, r3] */
/* @0x1d4938 ldrb r3, [r3] */
/* @0x1d493c cmp r3, #0 */
/* @0x1d4940 beq 0x1d49e4 <_Z16MainLoop_Processv+0x26c> */
/* @0x1d4944 ldr r3, [pc, #0x390] */
/* @0x1d4948 ldr r2, [pc, #0x390] */
/* @0x1d494c ldr r3, [r8, r3] */
/* @0x1d4950 ldr r5, [r8, r2] */
/* @0x1d4954 ldrb r3, [r3] */
/* @0x1d4958 cmp r3, #0 */
/* @0x1d495c movne r3, #1 */
/* @0x1d4960 cmp r7, #0 */
/* @0x1d4964 str r3, [r5] */
/* @0x1d4968 beq 0x1d49e4 <_Z16MainLoop_Processv+0x26c> */
/* @0x1d496c vmov s14, r11 */
/* @0x1d4970 ldr r3, [pc, #0x36c] */
/* @0x1d4974 vmov.f32 s17, #1.000000e+00 */
/* @0x1d4978 ldr r3, [r8, r3] */
/* @0x1d497c vldr s16, [r3] */
/* @0x1d4980 vcvt.f32.s32 s15, s14 */
/* @0x1d4984 vdiv.f32 s16, s16, s15 */
/* @0x1d4988 vmov r0, s16 */
/* @0x1d498c bl 0xb6910 <floorf@plt> */
/* @0x1d4990 vmov s14, r0 */
/* @0x1d4994 vsub.f32 s15, s16, s14 */
/* @0x1d4998 vsub.f32 s17, s17, s15 */
/* @0x1d499c vcmpe.f32 s15, s17 */
/* @0x1d49a0 vmrs APSR_nzcv, fpscr */
/* @0x1d49a4 ble 0x1d49b8 <_Z16MainLoop_Processv+0x240> */
/* @0x1d49a8 vmov r0, s16 */
/* @0x1d49ac bl 0xb6994 <ceilf@plt> */
/* @0x1d49b0 vmov.f32 s15, s17 */
/* @0x1d49b4 vmov s14, r0 */
/* @0x1d49b8 vldr s13, [pc, #736] */
/* @0x1d49bc vcmpe.f32 s15, s13 */
/* @0x1d49c0 vmrs APSR_nzcv, fpscr */
/* @0x1d49c4 bpl 0x1d49e4 <_Z16MainLoop_Processv+0x26c> */
/* @0x1d49c8 vcvt.s32.f32 s14, s14 */
/* @0x1d49cc vmov r3, s14 */
/* @0x1d49d0 cmp r3, #4 */
/* @0x1d49d4 strle r3, [r5] */
/* @0x1d49d8 movle r2, #0 */
/* @0x1d49dc movle r3, #0 */
/* @0x1d49e0 strdle r2, r3, [r4] */
/* @0x1d49e4 ldr r1, [pc, #0x2fc] */
/* @0x1d49e8 movw r0, #0x4040 */
/* @0x1d49ec movt r0, #0xff80 */
/* @0x1d49f0 add r1, pc, r1 */
/* @0x1d49f4 bl 0x17b8f0 <_ZN12GraphicsPerf4PushEjPKc> */
/* @0x1d49f8 ldrb r3, [r10] */
/* @0x1d49fc cmp r3, #0 */
/* @0x1d4a00 bne 0x1d4d18 <_Z16MainLoop_Processv+0x5a0> */
/* @0x1d4a04 ldrd r0, r1, [r4] */
/* @0x1d4a08 bl 0x212da4 <Timing_Wait> */
/* @0x1d4a0c ldrb r3, [r10] */
/* @0x1d4a10 cmp r3, #0 */
/* @0x1d4a14 bne 0x1d4c90 <_Z16MainLoop_Processv+0x518> */
/* @0x1d4a18 bl 0x17bb10 <_ZN12GraphicsPerf3PopEv> */
/* @0x1d4a1c bl 0x215148 <Timing_Time> */
/* @0x1d4a20 ldr r3, [pc, #0x2c4] */
/* @0x1d4a24 mov r4, r0 */
/* @0x1d4a28 mov r5, r1 */
/* @0x1d4a2c strd r4, r5, [r6] */
/* @0x1d4a30 ldr r3, [r8, r3] */
/* @0x1d4a34 str r3, [sp, #0xc] */
/* @0x1d4a38 ldrd r2, r3, [r3] */
/* @0x1d4a3c cmp r4, r2 */
/* @0x1d4a40 sbcs r0, r5, r3 */
/* @0x1d4a44 mov r0, r4 */
/* @0x1d4a48 ldrlt r12, [sp, #0xc] */
/* @0x1d4a4c movge r9, r2 */
/* @0x1d4a50 movge r11, r3 */
/* @0x1d4a54 movw r2, #0x4240 */
/* @0x1d4a58 mov r3, #0 */
/* @0x1d4a5c movt r2, #0xf */
/* @0x1d4a60 strdlt r4, r5, [r12] */
/* @0x1d4a64 movlt r9, r4 */
/* @0x1d4a68 movlt r11, r1 */
/* @0x1d4a6c bl 0x319414 <__aeabi_ldivmod> */
/* @0x1d4a70 mov r3, #0 */
/* @0x1d4a74 movw r2, #0x4240 */
/* @0x1d4a78 movt r2, #0xf */
/* @0x1d4a7c mov r6, r0 */
/* @0x1d4a80 mov r7, r1 */
/* @0x1d4a84 mov r0, r9 */
/* @0x1d4a88 mov r1, r11 */
/* @0x1d4a8c bl 0x319414 <__aeabi_ldivmod> */
/* @0x1d4a90 ldr r3, [pc, #0x258] */
/* @0x1d4a94 cmp r0, r6 */
/* @0x1d4a98 sbcs r2, r1, r7 */
/* @0x1d4a9c blt 0x1d4bec <_Z16MainLoop_Processv+0x474> */
/* @0x1d4aa0 ldr r3, [r8, r3] */
/* @0x1d4aa4 ldr r2, [r3] */
/* @0x1d4aa8 add r2, r2, #1 */
/* @0x1d4aac str r2, [r3] */
/* @0x1d4ab0 bl 0x21f17c <_Z10Sound_Tickv> */
/* @0x1d4ab4 ldr r3, [pc, #0x238] */
/* @0x1d4ab8 ldr r3, [r8, r3] */
/* @0x1d4abc ldrb r5, [r3] */
/* @0x1d4ac0 cmp r5, #0 */
/* @0x1d4ac4 bne 0x1d4b94 <_Z16MainLoop_Processv+0x41c> */
/* @0x1d4ac8 ldr r3, [pc, #0x228] */
/* @0x1d4acc ldr r4, [r8, r3] */
/* @0x1d4ad0 ldr r3, [r4] */
/* @0x1d4ad4 cmp r3, #1 */
/* @0x1d4ad8 ble 0x1d4c10 <_Z16MainLoop_Processv+0x498> */
/* @0x1d4adc bl 0x168c20 <_Z19GR_D3D_PartialResetv> */
/* @0x1d4ae0 ldr r3, [r4] */
/* @0x1d4ae4 sub r3, r3, #1 */
/* @0x1d4ae8 str r3, [r4] */
/* @0x1d4aec bl 0x1699c0 <_Z18GR_D3D_Start_Framev> */
/* @0x1d4af0 ldrb r3, [r10] */
/* @0x1d4af4 cmp r3, #0 */
/* @0x1d4af8 bne 0x1d4c84 <_Z16MainLoop_Processv+0x50c> */
/* @0x1d4afc bl 0x1d32c0 <_Z7DoAStepv> */
/* @0x1d4b00 ldrb r3, [r10] */
/* @0x1d4b04 cmp r3, #0 */
/* @0x1d4b08 bne 0x1d4c78 <_Z16MainLoop_Processv+0x500> */
/* @0x1d4b0c bl 0x18d488 <_Z9IO_Renderv> */
/* @0x1d4b10 ldr r3, [pc, #0x1e4] */
/* @0x1d4b14 ldr r4, [r8, r3] */
/* @0x1d4b18 ldr r3, [r4] */
/* @0x1d4b1c cmp r3, #0 */
/* @0x1d4b20 movge r0, #0 */
/* @0x1d4b24 blt 0x1d4d44 <_Z16MainLoop_Processv+0x5cc> */
/* @0x1d4b28 bl 0x169a58 <_Z19GR_D3D_Finish_Frameb> */
/* @0x1d4b2c ldr r3, [pc, #0x1cc] */
/* @0x1d4b30 ldr r3, [r8, r3] */
/* @0x1d4b34 ldr r3, [r3] */
/* @0x1d4b38 cmp r3, #0 */
/* @0x1d4b3c beq 0x1d4b70 <_Z16MainLoop_Processv+0x3f8> */
/* @0x1d4b40 movw r3, #0xfe70 */
/* @0x1d4b44 movt r3, #0xffff */
/* @0x1d4b48 str r3, [r4] */
/* @0x1d4b4c ldr r3, [pc, #0x1b0] */
/* @0x1d4b50 mov r2, #0 */
/* @0x1d4b54 mov r0, #60 */
/* @0x1d4b58 mov r1, #0 */
/* @0x1d4b5c ldr r3, [r8, r3] */
/* @0x1d4b60 strb r2, [r3] */
/* @0x1d4b64 add sp, sp, #20 */
/* @0x1d4b68 vpop {d8} */
/* @0x1d4b6c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d4b70 ldr r0, [r4] */
/* @0x1d4b74 cmn r0, #200 */
/* @0x1d4b78 beq 0x1d4d90 <_Z16MainLoop_Processv+0x618> */
/* @0x1d4b7c ble 0x1d4db8 <_Z16MainLoop_Processv+0x640> */
/* @0x1d4b80 cmn r0, #100 */
/* @0x1d4b84 beq 0x1d4b4c <_Z16MainLoop_Processv+0x3d4> */
/* @0x1d4b88 cmn r0, #1 */
/* @0x1d4b8c beq 0x1d4b94 <_Z16MainLoop_Processv+0x41c> */
/* @0x1d4b90 bl 0x1d4450 <_Z10SwitchRoomi> */
/* @0x1d4b94 ldr r0, [sp, #0x8] */
/* @0x1d4b98 bl 0x2a1498 <_ZN9CProfiler8EndFrameEv> */
/* @0x1d4b9c bl 0x29d770 <_Z12TickDebuggerv> */
/* @0x1d4ba0 ldr r12, [sp, #0x4] */
/* @0x1d4ba4 ldrb r3, [r12] */
/* @0x1d4ba8 cmp r3, #0 */
/* @0x1d4bac bne 0x1d4d68 <_Z16MainLoop_Processv+0x5f0> */
/* @0x1d4bb0 ldr r3, [pc, #0x100] */
/* @0x1d4bb4 ldr r3, [r8, r3] */
/* @0x1d4bb8 ldr r3, [r3] */
/* @0x1d4bbc cmp r3, #0 */
/* @0x1d4bc0 beq 0x1d4d54 <_Z16MainLoop_Processv+0x5dc> */
/* @0x1d4bc4 ldr r0, [r3, #0xc] */
/* @0x1d4bc8 cmp r0, #0 */
/* @0x1d4bcc asrgt r1, r0, #31 */
/* @0x1d4bd0 movle r2, #1 */
/* @0x1d4bd4 movle r0, #1 */
/* @0x1d4bd8 movle r1, #0 */
/* @0x1d4bdc strle r2, [r3, #0xc] */
/* @0x1d4be0 add sp, sp, #20 */
/* @0x1d4be4 vpop {d8} */
/* @0x1d4be8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d4bec ldr r3, [r8, r3] */
/* @0x1d4bf0 mov r2, #1 */
/* @0x1d4bf4 ldr r1, [pc, #0x10c] */
/* @0x1d4bf8 ldr r12, [sp, #0xc] */
/* @0x1d4bfc ldr r0, [r3] */
/* @0x1d4c00 ldr r1, [r8, r1] */
/* @0x1d4c04 strd r4, r5, [r12] */
/* @0x1d4c08 str r0, [r1] */
/* @0x1d4c0c b 0x1d4aac <_Z16MainLoop_Processv+0x334> */
/* @0x1d4c10 bne 0x1d4aec <_Z16MainLoop_Processv+0x374> */
/* @0x1d4c14 bl 0x168c24 <_Z12GR_D3D_Resetv> */
/* @0x1d4c18 str r5, [r4] */
/* @0x1d4c1c b 0x1d4aec <_Z16MainLoop_Processv+0x374> */
/* @0x1d4c20 ldr r3, [pc, #0xec] */
/* @0x1d4c24 ldr r5, [r8, r3] */
/* @0x1d4c28 mov r0, r5 */
/* @0x1d4c2c bl 0x214770 <_ZN13CTimingSource6UpdateEv> */
/* @0x1d4c30 vldr d7, [r5, #24] */
/* @0x1d4c34 vcmpe.f64 d7, #0 */
/* @0x1d4c38 vmrs APSR_nzcv, fpscr */
/* @0x1d4c3c movle r7, #0 */
/* @0x1d4c40 movle r11, #60 */
/* @0x1d4c44 ble 0x1d480c <_Z16MainLoop_Processv+0x94> */
/* @0x1d4c48 mov r0, r5 */
/* @0x1d4c4c mov r7, #1 */
/* @0x1d4c50 bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0x1d4c54 vmov d7, r0, r1 */
/* @0x1d4c58 vcvt.s32.f64 s15, d7 */
/* @0x1d4c5c vmov r11, s15 */
/* @0x1d4c60 b 0x1d480c <_Z16MainLoop_Processv+0x94> */
/* @0x1d4c64 ldr r3, [pc, #0xa0] */
/* @0x1d4c68 mov r0, #0 */
/* @0x1d4c6c mov r1, r0 */
/* @0x1d4c70 ldr r4, [r8, r3] */
/* @0x1d4c74 b 0x1d4904 <_Z16MainLoop_Processv+0x18c> */
/* @0x1d4c78 ldr r0, [sp, #0x8] */
/* @0x1d4c7c bl 0x2a0960 <_ZN9CProfiler7EndStepEv> */
/* @0x1d4c80 b 0x1d4b0c <_Z16MainLoop_Processv+0x394> */
/* @0x1d4c84 ldr r0, [sp, #0x8] */
/* @0x1d4c88 bl 0x2a0870 <_ZN9CProfiler9BeginStepEv> */
/* @0x1d4c8c b 0x1d4afc <_Z16MainLoop_Processv+0x384> */
/* @0x1d4c90 ldr r0, [sp, #0x8] */
/* @0x1d4c94 bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x1d4c98 b 0x1d4a18 <_Z16MainLoop_Processv+0x2a0> */
/* @0x1d4c9c ldmdbmi r4!, {r10, sp} ^ */
/* @0x1d4ca0 stcllo p12, c12, [r12, #820] */
/* @0x1d4ca4 eoreq sp, r1, r4, asr #9 */
/* @0x1d4ca8 .word 0xffffbf1c */
/* @0x1d4cac .word 0xffffef40 */
/* @0x1d4cb0 .word 0xffffef28 */
/* @0x1d4cb4 .word 0xffffbcd4 */
/* @0x1d4cb8 .word 0xffffbcd8 */
/* @0x1d4cbc .word 0xffffef44 */
/* @0x1d4cc0 .word 0xffffef1c */
/* @0x1d4cc4 .word 0xffffef48 */
/* @0x1d4cc8 .word 0xffffbf18 */
/* @0x1d4ccc .word 0xffffef4c */
/* @0x1d4cd0 .word 0xffffef50 */
/* @0x1d4cd4 .word 0xffffc960 */
/* @0x1d4cd8 .word 0xffffef54 */
/* @0x1d4cdc .word 0xffffe7f0 */
/* @0x1d4ce0 .word 0xffffef58 */
/* @0x1d4ce4 .word 0xffffef5c */
/* @0x1d4ce8 andseq r12, r7, r0, asr #14 */
/* @0x1d4cec .word 0xffffef30 */
/* @0x1d4cf0 .word 0xffffef2c */
/* @0x1d4cf4 .word 0xffffdfa0 */
/* @0x1d4cf8 .word 0xffffc97c */
/* @0x1d4cfc .word 0xffffc154 */
/* @0x1d4d00 .word 0xffffdf58 */
/* @0x1d4d04 .word 0xffffeebc */
/* @0x1d4d08 .word 0xffffeb1c */
/* @0x1d4d0c .word 0xffffef60 */
/* @0x1d4d10 .word 0xffffc974 */
/* @0x1d4d14 .word 0xffffbcdc */
/* @0x1d4d18 ldr r0, [sp, #0x8] */
/* @0x1d4d1c mov r1, #6 */
/* @0x1d4d20 mov r2, #20 */
/* @0x1d4d24 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x1d4d28 b 0x1d4a04 <_Z16MainLoop_Processv+0x28c> */
/* @0x1d4d2c ldr r1, [pc, #-0x28] */
/* @0x1d4d30 mov r2, #0 */
/* @0x1d4d34 mov r3, #0 */
/* @0x1d4d38 ldr r4, [r8, r1] */
/* @0x1d4d3c strd r2, r3, [r4] */
/* @0x1d4d40 b 0x1d4908 <_Z16MainLoop_Processv+0x190> */
/* @0x1d4d44 ldr r3, [pc, #-0x3c] */
/* @0x1d4d48 ldr r3, [r8, r3] */
/* @0x1d4d4c ldrb r0, [r3] */
/* @0x1d4d50 b 0x1d4b28 <_Z16MainLoop_Processv+0x3b0> */
/* @0x1d4d54 mov r0, #60 */
/* @0x1d4d58 mov r1, #0 */
/* @0x1d4d5c add sp, sp, #20 */
/* @0x1d4d60 vpop {d8} */
/* @0x1d4d64 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d4d68 ldr r3, [pc, #-0x5c] */
/* @0x1d4d6c ldr r0, [r8, r3] */
/* @0x1d4d70 bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0x1d4d74 vmov d7, r0, r1 */
/* @0x1d4d78 vcvt.s32.f64 s15, d7 */
/* @0x1d4d7c vmov r0, s15 */
/* @0x1d4d80 asr r1, r0, #31 */
/* @0x1d4d84 add sp, sp, #20 */
/* @0x1d4d88 vpop {d8} */
/* @0x1d4d8c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d4d90 bl 0x1d1b38 <_Z11Run_EndGamev> */
/* @0x1d4d94 bl 0x18e58c <_Z14GamePadRestartv> */
/* @0x1d4d98 bl 0x1d44fc <_Z9StartGamev> */
/* @0x1d4d9c movw r0, #0x12e4 */
/* @0x1d4da0 movt r0, #0x20 */
/* @0x1d4da4 bl 0xb69c4 <srand48@plt> */
/* @0x1d4da8 b 0x1d4b94 <_Z16MainLoop_Processv+0x41c> */
/* @0x1d4dac mov r7, #1 */
/* @0x1d4db0 mov r11, #60 */
/* @0x1d4db4 b 0x1d480c <_Z16MainLoop_Processv+0x94> */
/* @0x1d4db8 cmn r0, #400 */
/* @0x1d4dbc beq 0x1d4b4c <_Z16MainLoop_Processv+0x3d4> */
/* @0x1d4dc0 cmn r0, #300 */
/* @0x1d4dc4 bne 0x1d4b90 <_Z16MainLoop_Processv+0x418> */
/* @0x1d4dc8 bl 0x1d1cb4 <_Z8LoadGamev> */
/* @0x1d4dcc b 0x1d4b94 <_Z16MainLoop_Processv+0x41c> */
/* @0x1d4dd0 bl 0x319468 <__fixsfdi> */
/* @0x1d4dd4 b 0x1d4904 <_Z16MainLoop_Processv+0x18c> */

/* ── FUNC 0x1d4dd8 · SingleStep() · size=204 · insn=51 */
/* @0x1d4dd8 push {r4, lr} */
/* @0x1d4ddc bl 0x28fe64 <_Z15ProcessMessagesv> */
/* @0x1d4de0 ldr r4, [pc, #0xb0] */
/* @0x1d4de4 bl 0x1d32c0 <_Z7DoAStepv> */
/* @0x1d4de8 ldr r4, [pc, r4] */
/* @0x1d4dec ldr r0, [r4] */
/* @0x1d4df0 cmn r0, #1 */
/* @0x1d4df4 beq 0x1d4e50 <_Z10SingleStepv+0x78> */
/* @0x1d4df8 cmn r0, #200 */
/* @0x1d4dfc beq 0x1d4e78 <_Z10SingleStepv+0xa0> */
/* @0x1d4e00 bgt 0x1d4e20 <_Z10SingleStepv+0x48> */
/* @0x1d4e04 cmn r0, #400 */
/* @0x1d4e08 beq 0x1d4e3c <_Z10SingleStepv+0x64> */
/* @0x1d4e0c cmn r0, #300 */
/* @0x1d4e10 bne 0x1d4e30 <_Z10SingleStepv+0x58> */
/* @0x1d4e14 bl 0x1d1cb4 <_Z8LoadGamev> */
/* @0x1d4e18 pop {r4, lr} */
/* @0x1d4e1c b 0x28fe64 <_Z15ProcessMessagesv> */
/* @0x1d4e20 cmn r0, #100 */
/* @0x1d4e24 beq 0x1d4e3c <_Z10SingleStepv+0x64> */
/* @0x1d4e28 cmn r0, #1 */
/* @0x1d4e2c beq 0x1d4e18 <_Z10SingleStepv+0x40> */
/* @0x1d4e30 bl 0x1d4450 <_Z10SwitchRoomi> */
/* @0x1d4e34 pop {r4, lr} */
/* @0x1d4e38 b 0x28fe64 <_Z15ProcessMessagesv> */
/* @0x1d4e3c ldr r3, [pc, #0x58] */
/* @0x1d4e40 mov r2, #0 */
/* @0x1d4e44 ldr r3, [pc, r3] */
/* @0x1d4e48 strb r2, [r3] */
/* @0x1d4e4c pop {r4, pc} */
/* @0x1d4e50 ldr r3, [pc, #0x48] */
/* @0x1d4e54 ldr r3, [pc, r3] */
/* @0x1d4e58 ldrb r3, [r3] */
/* @0x1d4e5c cmp r3, #0 */
/* @0x1d4e60 beq 0x1d4e18 <_Z10SingleStepv+0x40> */
/* @0x1d4e64 mov r0, #1 */
/* @0x1d4e68 bl 0x169a58 <_Z19GR_D3D_Finish_Frameb> */
/* @0x1d4e6c bl 0x1699c0 <_Z18GR_D3D_Start_Framev> */
/* @0x1d4e70 ldr r0, [r4] */
/* @0x1d4e74 b 0x1d4df8 <_Z10SingleStepv+0x20> */
/* @0x1d4e78 bl 0x1d1b38 <_Z11Run_EndGamev> */
/* @0x1d4e7c bl 0x18e58c <_Z14GamePadRestartv> */
/* @0x1d4e80 bl 0x1d44fc <_Z9StartGamev> */
/* @0x1d4e84 movw r0, #0x12e4 */
/* @0x1d4e88 movt r0, #0x20 */
/* @0x1d4e8c bl 0xb69c4 <srand48@plt> */
/* @0x1d4e90 pop {r4, lr} */
/* @0x1d4e94 b 0x28fe64 <_Z15ProcessMessagesv> */
/* @0x1d4e98 .word 0x00218fbc */
/* @0x1d4e9c eoreq r11, r1, r8, asr #25 */
/* @0x1d4ea0 eoreq r9, r1, r0, ror r7 */

/* ── FUNC 0x1d4ea4 · Run_Step() · size=52 · insn=13 */
/* @0x1d4ea4 ldr r3, [pc, #0x24] */
/* @0x1d4ea8 ldr r3, [pc, r3] */
/* @0x1d4eac ldrb r3, [r3] */
/* @0x1d4eb0 cmp r3, #0 */
/* @0x1d4eb4 bxeq lr */
/* @0x1d4eb8 ldr r3, [pc, #0x14] */
/* @0x1d4ebc ldr r3, [pc, r3] */
/* @0x1d4ec0 ldrb r3, [r3] */
/* @0x1d4ec4 cmp r3, #0 */
/* @0x1d4ec8 bxeq lr */
/* @0x1d4ecc b 0x1d4dd8 <_Z10SingleStepv> */
/* @0x1d4ed0 eoreq r11, r1, r4, ror #24 */
/* @0x1d4ed4 eoreq r10, r1, r4, lsr sp */

/* ── FUNC 0x1d4ed8 · Run_Start() · size=264 · insn=66 */
/* @0x1d4ed8 push {r3, r4, r5, lr} */
/* @0x1d4edc ldr r4, [pc, #0xd4] */
/* @0x1d4ee0 ldr r3, [pc, #0xd4] */
/* @0x1d4ee4 add r4, pc, r4 */
/* @0x1d4ee8 ldr r5, [r4, r3] */
/* @0x1d4eec ldrb r3, [r5] */
/* @0x1d4ef0 cmp r3, #0 */
/* @0x1d4ef4 beq 0x1d4f94 <_Z9Run_Startv+0xbc> */
/* @0x1d4ef8 ldr r2, [pc, #0xc0] */
/* @0x1d4efc mov r3, #1 */
/* @0x1d4f00 strb r3, [r5] */
/* @0x1d4f04 mov r3, #0 */
/* @0x1d4f08 ldr r5, [r4, r2] */
/* @0x1d4f0c strb r3, [r5] */
/* @0x1d4f10 bl 0x1d3658 <_Z13MainLoop_Initv> */
/* @0x1d4f14 ldr r3, [pc, #0xa8] */
/* @0x1d4f18 ldr r3, [r4, r3] */
/* @0x1d4f1c ldr r3, [r3] */
/* @0x1d4f20 cmp r3, #0 */
/* @0x1d4f24 bne 0x1d4f54 <_Z9Run_Startv+0x7c> */
/* @0x1d4f28 ldr r3, [pc, #0x98] */
/* @0x1d4f2c ldr r3, [r4, r3] */
/* @0x1d4f30 ldr r1, [r3] */
/* @0x1d4f34 cmp r1, #0 */
/* @0x1d4f38 beq 0x1d4fa4 <_Z9Run_Startv+0xcc> */
/* @0x1d4f3c ldr r3, [pc, #0x88] */
/* @0x1d4f40 ldr r2, [pc, #0x88] */
/* @0x1d4f44 ldr r3, [r4, r3] */
/* @0x1d4f48 ldr r0, [r4, r2] */
/* @0x1d4f4c ldr r2, [r3] */
/* @0x1d4f50 bl 0x2a00b0 <_ZN9CProfiler4InitEPKci> */
/* @0x1d4f54 ldr r3, [pc, #0x78] */
/* @0x1d4f58 ldr r3, [r4, r3] */
/* @0x1d4f5c ldrb r3, [r3] */
/* @0x1d4f60 cmp r3, #0 */
/* @0x1d4f64 popeq {r3, r4, r5, pc} */
/* @0x1d4f68 ldr r3, [pc, #0x68] */
/* @0x1d4f6c mov r2, #1 */
/* @0x1d4f70 strb r2, [r5] */
/* @0x1d4f74 ldr r1, [pc, #0x60] */
/* @0x1d4f78 ldr r3, [r4, r3] */
/* @0x1d4f7c add r1, pc, r1 */
/* @0x1d4f80 ldr r0, [r3] */
/* @0x1d4f84 ldr r3, [r0] */
/* @0x1d4f88 ldr r3, [r3, #0xc] */
/* @0x1d4f8c blx r3 */
/* @0x1d4f90 pop {r3, r4, r5, pc} */
/* @0x1d4f94 mov r3, #1 */
/* @0x1d4f98 strb r3, [r5] */
/* @0x1d4f9c bl 0x1d44fc <_Z9StartGamev> */
/* @0x1d4fa0 b 0x1d4ef8 <_Z9Run_Startv+0x20> */
/* @0x1d4fa4 ldr r3, [pc, #0x24] */
/* @0x1d4fa8 mov r2, r1 */
/* @0x1d4fac ldr r0, [r4, r3] */
/* @0x1d4fb0 bl 0x2a00b0 <_ZN9CProfiler4InitEPKci> */
/* @0x1d4fb4 b 0x1d4f54 <_Z9Run_Startv+0x7c> */
/* @0x1d4fb8 eoreq r12, r1, r12, ror #26 */
/* @0x1d4fbc .word 0xffffeebc */
/* @0x1d4fc0 .word 0xffffdfa0 */
/* @0x1d4fc4 .word 0xffffc7d0 */
/* @0x1d4fc8 .word 0xffffef64 */
/* @0x1d4fcc .word 0xffffef68 */
/* @0x1d4fd0 .word 0xffffbf1c */
/* @0x1d4fd4 .word 0xffffdf9c */
/* @0x1d4fd8 .word 0xffffbcf0 */
/* @0x1d4fdc andseq r12, r7, r0, asr #3 */

/* ── FUNC 0x1d4fe0 · CSingleFingerGesture::IsUsingTouch(int) · size=20 · insn=5 */
/* @0x1d4fe0 ldr r0, [r0, #0x28] */
/* @0x1d4fe4 subs r3, r0, r1 */
/* @0x1d4fe8 rsbs r0, r3, #0 */
/* @0x1d4fec adcs r0, r0, r3 */
/* @0x1d4ff0 bx lr */

/* ── FUNC 0x1d4ff4 · CSingleFingerGesture::IsUsingTouchUID(int) · size=8 · insn=2 */
/* @0x1d4ff4 mov r0, #0 */
/* @0x1d4ff8 bx lr */

/* ── FUNC 0x1d4ffc · CSingleFingerGesture::NumUsedTouches() · size=8 · insn=2 */
/* @0x1d4ffc mov r0, #1 */
/* @0x1d5000 bx lr */

/* ── FUNC 0x1d5004 · CGesturePinch::NumUsedTouches() · size=8 · insn=2 */
/* @0x1d5004 mov r0, #2 */
/* @0x1d5008 bx lr */

/* ── FUNC 0x1d500c · CGestureRotate::NumUsedTouches() · size=8 · insn=2 */
/* @0x1d500c mov r0, #2 */
/* @0x1d5010 bx lr */

/* ── FUNC 0x1d5014 · CGesturePinch::IsUsingTouchUID(int) · size=40 · insn=10 */
/* @0x1d5014 ldr r3, [r0, #0x28] */
/* @0x1d5018 cmp r3, r1 */
/* @0x1d501c beq 0x1d5034 <_ZN13CGesturePinch15IsUsingTouchUIDEi+0x20> */
/* @0x1d5020 ldr r0, [r0, #0x2c] */
/* @0x1d5024 subs r3, r1, r0 */
/* @0x1d5028 rsbs r0, r3, #0 */
/* @0x1d502c adcs r0, r0, r3 */
/* @0x1d5030 bx lr */
/* @0x1d5034 mov r0, #1 */
/* @0x1d5038 bx lr */

/* ── FUNC 0x1d503c · CGestureRotate::IsUsingTouchUID(int) · size=40 · insn=10 */
/* @0x1d503c ldr r3, [r0, #0x28] */
/* @0x1d5040 cmp r3, r1 */
/* @0x1d5044 beq 0x1d505c <_ZN14CGestureRotate15IsUsingTouchUIDEi+0x20> */
/* @0x1d5048 ldr r0, [r0, #0x2c] */
/* @0x1d504c subs r3, r1, r0 */
/* @0x1d5050 rsbs r0, r3, #0 */
/* @0x1d5054 adcs r0, r0, r3 */
/* @0x1d5058 bx lr */
/* @0x1d505c mov r0, #1 */
/* @0x1d5060 bx lr */

/* ── FUNC 0x1d5064 · anon_1d5064 · size=4 · insn=1 */
/* @0x1d5064 andeq r0, r0, r0 */

/* ── FUNC 0x1d5068 · F_GestureGetDragTime(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1d5068 ldr r3, [pc, #0x40] */
/* @0x1d506c mov r2, #0 */
/* @0x1d5070 push {r4, lr} */
/* @0x1d5074 ldr r3, [pc, r3] */
/* @0x1d5078 str r2, [r0, #0xc] */
/* @0x1d507c mov r4, r0 */
/* @0x1d5080 ldrd r0, r1, [r3] */
/* @0x1d5084 bl 0x319164 <__floatdidf> */
/* @0x1d5088 vldr d7, [pc, #24] */
/* @0x1d508c vmov d6, r0, r1 */
/* @0x1d5090 vdiv.f64 d6, d6, d7 */
/* @0x1d5094 vmov r0, r1, d6 */
/* @0x1d5098 vmov r2, s12 */
/* @0x1d509c mov r3, r1 */
/* @0x1d50a0 stm r4, {r2, r3} */
/* @0x1d50a4 pop {r4, pc} */
/* @0x1d50a8 andeq r0, r0, r0 */
/* @0x1d50ac smlawbmi lr, r0, r4, r8 */
/* @0x1d50b0 eoreq r11, r1, r0, asr r11 */

/* ── FUNC 0x1d50b4 · anon_1d50b4 · size=4 · insn=1 */
/* @0x1d50b4 nop */

/* ── FUNC 0x1d50b8 · F_GestureGetDragDistance(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x1d50b8 ldr r3, [pc, #0x1c] */
/* @0x1d50bc mov r2, #0 */
/* @0x1d50c0 str r2, [r0, #0xc] */
/* @0x1d50c4 ldr r3, [pc, r3] */
/* @0x1d50c8 vldr s15, [r3] */
/* @0x1d50cc vcvt.f64.f32 d6, s15 */
/* @0x1d50d0 vmov r2, r3, d6 */
/* @0x1d50d4 stm r0, {r2, r3} */
/* @0x1d50d8 bx lr */
/* @0x1d50dc eoreq r11, r1, r4, lsl #22 */

/* ── FUNC 0x1d50e0 · F_GestureGetFlickSpeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x1d50e0 ldr r3, [pc, #0x1c] */
/* @0x1d50e4 mov r2, #0 */
/* @0x1d50e8 str r2, [r0, #0xc] */
/* @0x1d50ec ldr r3, [pc, r3] */
/* @0x1d50f0 vldr s15, [r3] */
/* @0x1d50f4 vcvt.f64.f32 d6, s15 */
/* @0x1d50f8 vmov r2, r3, d6 */
/* @0x1d50fc stm r0, {r2, r3} */
/* @0x1d5100 bx lr */
/* @0x1d5104 eoreq r11, r1, r0, ror #21 */

/* ── FUNC 0x1d5108 · F_GestureGetDoubleTapTime(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1d5108 ldr r3, [pc, #0x40] */
/* @0x1d510c mov r2, #0 */
/* @0x1d5110 push {r4, lr} */
/* @0x1d5114 ldr r3, [pc, r3] */
/* @0x1d5118 str r2, [r0, #0xc] */
/* @0x1d511c mov r4, r0 */
/* @0x1d5120 ldrd r0, r1, [r3] */
/* @0x1d5124 bl 0x319164 <__floatdidf> */
/* @0x1d5128 vldr d7, [pc, #24] */
/* @0x1d512c vmov d6, r0, r1 */
/* @0x1d5130 vdiv.f64 d6, d6, d7 */
/* @0x1d5134 vmov r0, r1, d6 */
/* @0x1d5138 vmov r2, s12 */
/* @0x1d513c mov r3, r1 */
/* @0x1d5140 stm r4, {r2, r3} */
/* @0x1d5144 pop {r4, pc} */
/* @0x1d5148 andeq r0, r0, r0 */
/* @0x1d514c smlawbmi lr, r0, r4, r8 */
/* @0x1d5150 .word 0x0021babc */

/* ── FUNC 0x1d5154 · anon_1d5154 · size=4 · insn=1 */
/* @0x1d5154 nop */

/* ── FUNC 0x1d5158 · F_GestureGetDoubleTapDistance(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x1d5158 ldr r3, [pc, #0x1c] */
/* @0x1d515c mov r2, #0 */
/* @0x1d5160 str r2, [r0, #0xc] */
/* @0x1d5164 ldr r3, [pc, r3] */
/* @0x1d5168 vldr s15, [r3] */
/* @0x1d516c vcvt.f64.f32 d6, s15 */
/* @0x1d5170 vmov r2, r3, d6 */
/* @0x1d5174 stm r0, {r2, r3} */
/* @0x1d5178 bx lr */
/* @0x1d517c eoreq r11, r1, r0, ror r10 */

/* ── FUNC 0x1d5180 · F_GestureGetPinchDistance(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x1d5180 ldr r3, [pc, #0x1c] */
/* @0x1d5184 mov r2, #0 */
/* @0x1d5188 str r2, [r0, #0xc] */
/* @0x1d518c ldr r3, [pc, r3] */
/* @0x1d5190 vldr s15, [r3] */
/* @0x1d5194 vcvt.f64.f32 d6, s15 */
/* @0x1d5198 vmov r2, r3, d6 */
/* @0x1d519c stm r0, {r2, r3} */
/* @0x1d51a0 bx lr */
/* @0x1d51a4 eoreq r11, r1, r12, asr #20 */

/* ── FUNC 0x1d51a8 · F_GestureGetPinchAngleTowards(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x1d51a8 ldr r3, [pc, #0x1c] */
/* @0x1d51ac mov r2, #0 */
/* @0x1d51b0 str r2, [r0, #0xc] */
/* @0x1d51b4 ldr r3, [pc, r3] */
/* @0x1d51b8 vldr s15, [r3] */
/* @0x1d51bc vcvt.f64.f32 d6, s15 */
/* @0x1d51c0 vmov r2, r3, d6 */
/* @0x1d51c4 stm r0, {r2, r3} */
/* @0x1d51c8 bx lr */
/* @0x1d51cc eoreq r11, r1, r8, lsr #20 */

/* ── FUNC 0x1d51d0 · F_GestureGetPinchAngleAway(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x1d51d0 ldr r3, [pc, #0x1c] */
/* @0x1d51d4 mov r2, #0 */
/* @0x1d51d8 str r2, [r0, #0xc] */
/* @0x1d51dc ldr r3, [pc, r3] */
/* @0x1d51e0 vldr s15, [r3] */
/* @0x1d51e4 vcvt.f64.f32 d6, s15 */
/* @0x1d51e8 vmov r2, r3, d6 */
/* @0x1d51ec stm r0, {r2, r3} */
/* @0x1d51f0 bx lr */
/* @0x1d51f4 eoreq r11, r1, r4, lsl #20 */

/* ── FUNC 0x1d51f8 · F_GestureGetRotateTime(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1d51f8 ldr r3, [pc, #0x40] */
/* @0x1d51fc mov r2, #0 */
/* @0x1d5200 push {r4, lr} */
/* @0x1d5204 ldr r3, [pc, r3] */
/* @0x1d5208 str r2, [r0, #0xc] */
/* @0x1d520c mov r4, r0 */
/* @0x1d5210 ldrd r0, r1, [r3] */
/* @0x1d5214 bl 0x319164 <__floatdidf> */
/* @0x1d5218 vldr d7, [pc, #24] */
/* @0x1d521c vmov d6, r0, r1 */
/* @0x1d5220 vdiv.f64 d6, d6, d7 */
/* @0x1d5224 vmov r0, r1, d6 */
/* @0x1d5228 vmov r2, s12 */
/* @0x1d522c mov r3, r1 */
/* @0x1d5230 stm r4, {r2, r3} */
/* @0x1d5234 pop {r4, pc} */
/* @0x1d5238 andeq r0, r0, r0 */
/* @0x1d523c smlawbmi lr, r0, r4, r8 */
/* @0x1d5240 eoreq r11, r1, r0, ror #19 */
