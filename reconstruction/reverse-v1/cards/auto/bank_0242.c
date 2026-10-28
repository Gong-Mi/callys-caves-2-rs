/* libyoyo.so 覆盖卡组 0242
 * 函数 0x290288..0x293d40，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x290288 · PackageManagerHasSystemFeature(char const*) · size=368 · insn=92 */
/* @0x290288 push {r4, r5, r6, r7, r8, lr} */
/* @0x29028c mov r7, r0 */
/* @0x290290 bl 0x290274 <getJNIEnv> */
/* @0x290294 ldr r1, [pc, #0x138] */
/* @0x290298 add r1, pc, r1 */
/* @0x29029c ldr r3, [r0] */
/* @0x2902a0 mov r4, r0 */
/* @0x2902a4 ldr r3, [r3, #0x18] */
/* @0x2902a8 blx r3 */
/* @0x2902ac ldr r12, [r4] */
/* @0x2902b0 ldr r2, [pc, #0x120] */
/* @0x2902b4 ldr r3, [pc, #0x120] */
/* @0x2902b8 add r2, pc, r2 */
/* @0x2902bc ldr r12, [r12, #0x84] */
/* @0x2902c0 add r3, pc, r3 */
/* @0x2902c4 mov r1, r0 */
/* @0x2902c8 mov r0, r4 */
/* @0x2902cc blx r12 */
/* @0x2902d0 ldr r3, [r4] */
/* @0x2902d4 ldr r1, [pc, #0x104] */
/* @0x2902d8 ldr r3, [r3, #0x18] */
/* @0x2902dc add r1, pc, r1 */
/* @0x2902e0 mov r6, r0 */
/* @0x2902e4 mov r0, r4 */
/* @0x2902e8 blx r3 */
/* @0x2902ec ldr r12, [r4] */
/* @0x2902f0 ldr r2, [pc, #0xec] */
/* @0x2902f4 ldr r3, [pc, #0xec] */
/* @0x2902f8 ldr r12, [r12, #0x240] */
/* @0x2902fc add r2, pc, r2 */
/* @0x290300 add r3, pc, r3 */
/* @0x290304 mov r5, r0 */
/* @0x290308 mov r0, r4 */
/* @0x29030c mov r1, r5 */
/* @0x290310 blx r12 */
/* @0x290314 ldr r3, [r4] */
/* @0x290318 mov r1, r5 */
/* @0x29031c ldr r3, [r3, #0x244] */
/* @0x290320 mov r2, r0 */
/* @0x290324 mov r0, r4 */
/* @0x290328 blx r3 */
/* @0x29032c mov r2, r6 */
/* @0x290330 mov r1, r0 */
/* @0x290334 mov r0, r4 */
/* @0x290338 bl 0x28fc74 <_ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz> */
/* @0x29033c ldr r3, [r4] */
/* @0x290340 ldr r1, [pc, #0xa4] */
/* @0x290344 ldr r3, [r3, #0x18] */
/* @0x290348 add r1, pc, r1 */
/* @0x29034c mov r6, r0 */
/* @0x290350 mov r0, r4 */
/* @0x290354 blx r3 */
/* @0x290358 ldr r12, [r4] */
/* @0x29035c ldr r2, [pc, #0x8c] */
/* @0x290360 ldr r3, [pc, #0x8c] */
/* @0x290364 ldr r12, [r12, #0x84] */
/* @0x290368 add r2, pc, r2 */
/* @0x29036c add r3, pc, r3 */
/* @0x290370 mov r1, r0 */
/* @0x290374 mov r0, r4 */
/* @0x290378 blx r12 */
/* @0x29037c ldr r3, [r4] */
/* @0x290380 mov r1, r7 */
/* @0x290384 ldr r3, [r3, #0x29c] */
/* @0x290388 mov r8, r0 */
/* @0x29038c mov r0, r4 */
/* @0x290390 blx r3 */
/* @0x290394 mov r1, r6 */
/* @0x290398 mov r2, r8 */
/* @0x29039c mov r5, r0 */
/* @0x2903a0 mov r0, r4 */
/* @0x2903a4 mov r3, r5 */
/* @0x2903a8 bl 0x28fcac <_ZN7_JNIEnv17CallBooleanMethodEP8_jobjectP10_jmethodIDz> */
/* @0x2903ac ldr r3, [r4] */
/* @0x2903b0 mov r1, r5 */
/* @0x2903b4 ldr r3, [r3, #0x5c] */
/* @0x2903b8 mov r6, r0 */
/* @0x2903bc mov r0, r4 */
/* @0x2903c0 blx r3 */
/* @0x2903c4 subs r3, r6, #1 */
/* @0x2903c8 rsbs r0, r3, #0 */
/* @0x2903cc adcs r0, r0, r3 */
/* @0x2903d0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2903d4 andeq r7, r12, r8, lsl pc */
/* @0x2903d8 andeq r7, r12, r0, lsl pc */
/* @0x2903dc andeq r7, r12, r12, lsl pc */
/* @0x2903e0 andeq r7, r12, r8, lsr #30 */
/* @0x2903e4 andeq r7, r12, r12, lsr #30 */
/* @0x2903e8 andeq r7, r12, r4, lsr pc */
/* @0x2903ec andeq r7, r12, r8, lsl #30 */
/* @0x2903f0 andeq r7, r12, r12, lsl #30 */
/* @0x2903f4 andeq r7, r12, r12, lsl pc */

/* ── FUNC 0x2903f8 · DoFrameTiming() · size=540 · insn=135 */
/* @0x2903f8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2903fc vpush {d8, d9} */
/* @0x290400 vldr s16, [pc, #480] */
/* @0x290404 ldr r6, [pc, #0x1e0] */
/* @0x290408 ldr r2, [pc, #0x1e0] */
/* @0x29040c add r6, pc, r6 */
/* @0x290410 ldr r3, [pc, #0x1dc] */
/* @0x290414 ldr r8, [r6, r2] */
/* @0x290418 ldr r9, [r6, r3] */
/* @0x29041c ldrd r2, r3, [r8] */
/* @0x290420 strd r2, r3, [r9] */
/* @0x290424 bl 0x215148 <Timing_Time> */
/* @0x290428 ldrd r2, r3, [r8] */
/* @0x29042c mov r4, r0 */
/* @0x290430 mov r5, r1 */
/* @0x290434 mvn r0, #0 */
/* @0x290438 mvn r1, #0 */
/* @0x29043c cmp r3, r1 */
/* @0x290440 cmpeq r2, r0 */
/* @0x290444 ldr r3, [pc, #0x1ac] */
/* @0x290448 strdeq r4, r5, [r8] */
/* @0x29044c ldr r2, [pc, #0x1a8] */
/* @0x290450 ldr r3, [r6, r3] */
/* @0x290454 ldr r2, [r6, r2] */
/* @0x290458 vldr s17, [r2] */
/* @0x29045c ldr r3, [r3] */
/* @0x290460 vdiv.f32 s17, s16, s17 */
/* @0x290464 cmp r3, #0 */
/* @0x290468 movle r7, #1 */
/* @0x29046c ble 0x290558 <_Z13DoFrameTimingv+0x160> */
/* @0x290470 ldr r3, [pc, #0x188] */
/* @0x290474 ldr r3, [r6, r3] */
/* @0x290478 vldr s15, [r3] */
/* @0x29047c vcvt.f32.s32 s15, s15 */
/* @0x290480 vdiv.f32 s15, s16, s15 */
/* @0x290484 vmov r0, s15 */
/* @0x290488 bl 0x319468 <__fixsfdi> */
/* @0x29048c bl 0x319398 <__floatdisf> */
/* @0x290490 vmov.f32 s15, #5.000000e-01 */
/* @0x290494 ldrd r2, r3, [r8] */
/* @0x290498 mov r1, r5 */
/* @0x29049c vmov s18, r0 */
/* @0x2904a0 mov r0, r4 */
/* @0x2904a4 subs r0, r0, r2 */
/* @0x2904a8 sbc r1, r1, r3 */
/* @0x2904ac vmls.f32 s18, s17, s15 */
/* @0x2904b0 bl 0x319398 <__floatdisf> */
/* @0x2904b4 ldr r3, [pc, #0x148] */
/* @0x2904b8 ldr r3, [r6, r3] */
/* @0x2904bc vmov s15, r0 */
/* @0x2904c0 ldrd r0, r1, [r3] */
/* @0x2904c4 vsub.f32 s18, s18, s15 */
/* @0x2904c8 bl 0x319398 <__floatdisf> */
/* @0x2904cc vmov s15, r0 */
/* @0x2904d0 vadd.f32 s15, s18, s15 */
/* @0x2904d4 vmov r0, s15 */
/* @0x2904d8 bl 0x319468 <__fixsfdi> */
/* @0x2904dc bl 0x319398 <__floatdisf> */
/* @0x2904e0 vmov s15, r0 */
/* @0x2904e4 vcmpe.f32 s15, #0 */
/* @0x2904e8 vmrs APSR_nzcv, fpscr */
/* @0x2904ec bmi 0x2905dc <_Z13DoFrameTimingv+0x1e4> */
/* @0x2904f0 bl 0x319468 <__fixsfdi> */
/* @0x2904f4 bl 0x319398 <__floatdisf> */
/* @0x2904f8 vmov s15, r0 */
/* @0x2904fc vcmpe.f32 s15, s16 */
/* @0x290500 vmrs APSR_nzcv, fpscr */
/* @0x290504 movwpl r0, #0x4240 */
/* @0x290508 movpl r1, #0 */
/* @0x29050c movtpl r0, #0xf */
/* @0x290510 bmi 0x2905d4 <_Z13DoFrameTimingv+0x1dc> */
/* @0x290514 bl 0x212da4 <Timing_Wait> */
/* @0x290518 mov r7, #0 */
/* @0x29051c bl 0x215148 <Timing_Time> */
/* @0x290520 bl 0x290274 <getJNIEnv> */
/* @0x290524 ldr r2, [pc, #0xdc] */
/* @0x290528 ldr r3, [pc, #0xdc] */
/* @0x29052c ldr r2, [r6, r2] */
/* @0x290530 ldr r3, [r6, r3] */
/* @0x290534 ldr r1, [r2] */
/* @0x290538 ldr r2, [r3] */
/* @0x29053c bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x290540 bl 0x215148 <Timing_Time> */
/* @0x290544 ldr r3, [pc, #0xc4] */
/* @0x290548 ldr r3, [r6, r3] */
/* @0x29054c ldr r2, [r3] */
/* @0x290550 add r2, r2, #1 */
/* @0x290554 str r2, [r3] */
/* @0x290558 bl 0x215148 <Timing_Time> */
/* @0x29055c ldrd r4, r5, [r9] */
/* @0x290560 mvn r2, #0 */
/* @0x290564 mvn r3, #0 */
/* @0x290568 cmp r5, r3 */
/* @0x29056c cmpeq r4, r2 */
/* @0x290570 strd r0, r1, [r8] */
/* @0x290574 beq 0x2905c8 <_Z13DoFrameTimingv+0x1d0> */
/* @0x290578 vmov r0, s17 */
/* @0x29057c bl 0x319468 <__fixsfdi> */
/* @0x290580 mov r5, r1 */
/* @0x290584 ldr r1, [pc, #0x78] */
/* @0x290588 mov r4, r0 */
/* @0x29058c mov r3, r5 */
/* @0x290590 mov r2, r4 */
/* @0x290594 rsbs r4, r4, #0 */
/* @0x290598 rsc r5, r5, #0 */
/* @0x29059c ldr r12, [r6, r1] */
/* @0x2905a0 ldrd r0, r1, [r12] */
/* @0x2905a4 cmp r0, r2 */
/* @0x2905a8 sbcs r6, r1, r3 */
/* @0x2905ac movlt r2, r0 */
/* @0x2905b0 movlt r3, r1 */
/* @0x2905b4 cmp r4, r2 */
/* @0x2905b8 sbcs r1, r5, r3 */
/* @0x2905bc movlt r4, r2 */
/* @0x2905c0 movlt r5, r3 */
/* @0x2905c4 strd r4, r5, [r12] */
/* @0x2905c8 vpop {d8, d9} */
/* @0x2905cc mov r0, r7 */
/* @0x2905d0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2905d4 bl 0x319468 <__fixsfdi> */
/* @0x2905d8 b 0x290514 <_Z13DoFrameTimingv+0x11c> */
/* @0x2905dc mov r0, #0 */
/* @0x2905e0 mov r1, #0 */
/* @0x2905e4 b 0x290514 <_Z13DoFrameTimingv+0x11c> */
/* @0x2905e8 ldmdbmi r4!, {r10, sp} ^ */
/* @0x2905ec andseq r1, r6, r4, asr #16 */
/* @0x2905f0 .word 0xfffffcd8 */
/* @0x2905f4 .word 0xfffffcdc */
/* @0x2905f8 .word 0xffffef58 */
/* @0x2905fc .word 0xffffef5c */
/* @0x290600 .word 0xffffef44 */
/* @0x290604 .word 0xfffffce0 */
/* @0x290608 .word 0xffffbd54 */
/* @0x29060c .word 0xfffffce4 */
/* @0x290610 .word 0xfffffce8 */

/* ── FUNC 0x290614 · setJNIEnv · size=24 · insn=6 */
/* @0x290614 ldr r3, [pc, #0xc] */
/* @0x290618 mov r1, r0 */
/* @0x29061c ldr r3, [pc, r3] */
/* @0x290620 ldr r0, [r3] */
/* @0x290624 b 0xb6d3c <pthread_setspecific@plt> */
/* @0x290628 andseq r1, r6, r8, lsl #6 */

/* ── FUNC 0x29062c · Java_com_yoyogames_runner_RunnerJNILib_Startup · size=5696 · insn=1424 */
/* @0x29062c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x290630 mov r4, r0 */
/* @0x290634 ldr r5, [pc, #0x244] */
/* @0x290638 mov r10, r3 */
/* @0x29063c ldr r0, [pc, #0x240] */
/* @0x290640 sub sp, sp, #52 */
/* @0x290644 add r5, pc, r5 */
/* @0x290648 ldr r1, [pc, #0x238] */
/* @0x29064c mov r8, r2 */
/* @0x290650 mov r6, #0 */
/* @0x290654 ldr r3, [r5, r0] */
/* @0x290658 add r1, pc, r1 */
/* @0x29065c ldr r7, [r3] */
/* @0x290660 ldr r3, [r7] */
/* @0x290664 mov r0, r7 */
/* @0x290668 ldr r3, [r3, #0xc] */
/* @0x29066c blx r3 */
/* @0x290670 ldr r2, [pc, #0x214] */
/* @0x290674 ldr r3, [pc, #0x214] */
/* @0x290678 ldr r2, [r5, r2] */
/* @0x29067c strb r6, [r2] */
/* @0x290680 ldr r3, [r5, r3] */
/* @0x290684 strb r6, [r3] */
/* @0x290688 bl 0x28fce4 <_Z15ImportGLLibraryv> */
/* @0x29068c ldr r3, [pc, #0x200] */
/* @0x290690 mov r1, r6 */
/* @0x290694 ldr r0, [r5, r3] */
/* @0x290698 bl 0xb6d48 <pthread_key_create@plt> */
/* @0x29069c mov r0, r4 */
/* @0x2906a0 bl 0x290614 <setJNIEnv> */
/* @0x2906a4 ldr r3, [r4] */
/* @0x2906a8 ldr r1, [pc, #0x1e8] */
/* @0x2906ac mov r0, r4 */
/* @0x2906b0 ldr r3, [r3, #0x18] */
/* @0x2906b4 add r1, pc, r1 */
/* @0x2906b8 blx r3 */
/* @0x2906bc ldr r3, [pc, #0x1d8] */
/* @0x2906c0 ldr r6, [r5, r3] */
/* @0x2906c4 ldr r3, [r6] */
/* @0x2906c8 cmp r3, #0 */
/* @0x2906cc beq 0x290c00 <Java_com_yoyogames_runner_RunnerJNILib_Startup+0x5d4> */
/* @0x2906d0 ldr r3, [pc, #0x514] */
/* @0x2906d4 ldr r8, [r5, r3] */
/* @0x2906d8 ldr r0, [r8] */
/* @0x2906dc bl 0x2a1cf0 <_Z18ProcessCommandLinePc> */
/* @0x2906e0 bl 0x2a2914 <_Z4Initv> */
/* @0x2906e4 cmp r0, #0 */
/* @0x2906e8 beq 0x290878 <Java_com_yoyogames_runner_RunnerJNILib_Startup+0x24c> */
/* @0x2906ec ldr r3, [r7] */
/* @0x2906f0 mov r0, r7 */
/* @0x2906f4 ldr r1, [pc, #0x1a4] */
/* @0x2906f8 ldr r3, [r3, #0xc] */
/* @0x2906fc add r1, pc, r1 */
/* @0x290700 blx r3 */
/* @0x290704 bl 0x2a180c <_Z10BeginToEndv> */
/* @0x290708 ldr r3, [pc, #0x194] */
/* @0x29070c mov r1, #0 */
/* @0x290710 mov r2, #2560 */
/* @0x290714 ldr r0, [r5, r3] */
/* @0x290718 bl 0xb65b0 <memset@plt> */
/* @0x29071c bl 0x290274 <getJNIEnv> */
/* @0x290720 ldr r3, [pc, #0x3bc] */
/* @0x290724 ldr r1, [r6] */
/* @0x290728 ldr r3, [r5, r3] */
/* @0x29072c ldr r2, [r3] */
/* @0x290730 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x290734 ldr lr, [pc, #0x16c] */
/* @0x290738 ldr r12, [r7] */
/* @0x29073c ldr r1, [pc, #0x168] */
/* @0x290740 ldr lr, [r5, lr] */
/* @0x290744 add r1, pc, r1 */
/* @0x290748 ldr r12, [r12, #0xc] */
/* @0x29074c mov r3, r0 */
/* @0x290750 mov r2, r0 */
/* @0x290754 str r3, [lr] */
/* @0x290758 mov r0, r7 */
/* @0x29075c blx r12 */
/* @0x290760 ldr r3, [pc, #0x148] */
/* @0x290764 ldr r0, [pc, #0x148] */
/* @0x290768 mov r2, #0 */
/* @0x29076c ldr r3, [r5, r3] */
/* @0x290770 add r0, pc, r0 */
/* @0x290774 str r2, [r3] */
/* @0x290778 bl 0x290288 <_Z30PackageManagerHasSystemFeaturePKc> */
/* @0x29077c ldr r12, [pc, #0x134] */
/* @0x290780 ldr r3, [pc, #0x134] */
/* @0x290784 ldr r1, [pc, #0x134] */
/* @0x290788 ldr r12, [r5, r12] */
/* @0x29078c add r1, pc, r1 */
/* @0x290790 str r0, [r12] */
/* @0x290794 mov r2, r0 */
/* @0x290798 ldr r3, [r5, r3] */
/* @0x29079c ldr r6, [r3] */
/* @0x2907a0 ldr r3, [r6] */
/* @0x2907a4 mov r0, r6 */
/* @0x2907a8 ldr r3, [r3, #0xc] */
/* @0x2907ac blx r3 */
/* @0x2907b0 ldr r3, [r4] */
/* @0x2907b4 ldr r1, [pc, #0x108] */
/* @0x2907b8 mov r0, r4 */
/* @0x2907bc add r1, pc, r1 */
/* @0x2907c0 ldr r3, [r3, #0x18] */
/* @0x2907c4 blx r3 */
/* @0x2907c8 ldr r12, [r4] */
/* @0x2907cc ldr r2, [pc, #0xf4] */
/* @0x2907d0 ldr r3, [pc, #0xf4] */
/* @0x2907d4 ldr r12, [r12, #0x240] */
/* @0x2907d8 add r2, pc, r2 */
/* @0x2907dc add r3, pc, r3 */
/* @0x2907e0 mov r1, r0 */
/* @0x2907e4 mov r7, r0 */
/* @0x2907e8 mov r0, r4 */
/* @0x2907ec blx r12 */
/* @0x2907f0 ldr r3, [r4] */
/* @0x2907f4 mov r1, r7 */
/* @0x2907f8 ldr r3, [r3, #0x244] */
/* @0x2907fc mov r2, r0 */
/* @0x290800 mov r0, r4 */
/* @0x290804 blx r3 */
/* @0x290808 ldr r3, [r4] */
/* @0x29080c add r2, sp, #47 */
/* @0x290810 ldr r3, [r3, #0x2a4] */
/* @0x290814 mov r1, r0 */
/* @0x290818 mov r0, r4 */
/* @0x29081c blx r3 */
/* @0x290820 ldr r3, [r6] */
/* @0x290824 ldr r1, [pc, #0xa4] */
/* @0x290828 ldr r3, [r3, #0xc] */
/* @0x29082c add r1, pc, r1 */
/* @0x290830 mov r4, r0 */
/* @0x290834 mov r0, r6 */
/* @0x290838 mov r2, r4 */
/* @0x29083c blx r3 */
/* @0x290840 mov r0, r4 */
/* @0x290844 bl 0xc4a74 <_Z6struprPc> */
/* @0x290848 ldr r1, [pc, #0x84] */
/* @0x29084c add r1, pc, r1 */
/* @0x290850 bl 0xb6574 <strcmp@plt> */
/* @0x290854 ldr r2, [pc, #0x7c] */
/* @0x290858 ldr r3, [pc, #0x7c] */
/* @0x29085c ldr r2, [r5, r2] */
/* @0x290860 rsbs r0, r0, #1 */
/* @0x290864 movlo r0, #0 */
/* @0x290868 str r0, [r2] */
/* @0x29086c ldr r2, [sp, #0x5c] */
/* @0x290870 ldr r3, [r5, r3] */
/* @0x290874 str r2, [r3] */
/* @0x290878 add sp, sp, #52 */
/* @0x29087c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x290880 andseq r1, r6, r12, lsl #12 */
/* @0x290884 .word 0xffffbac4 */
/* @0x290888 andeq r7, r12, r8, asr #24 */
/* @0x29088c .word 0xfffffcec */
/* @0x290890 .word 0xfffffcf0 */
/* @0x290894 .word 0xfffffcd4 */
/* @0x290898 andeq r7, r12, r0, asr r11 */
/* @0x29089c .word 0xffffbd54 */
/* @0x2908a0 andeq r8, r12, r8, lsl #11 */
/* @0x2908a4 .word 0xfffffcf4 */
/* @0x2908a8 .word 0xffffe908 */
/* @0x2908ac andeq r8, r12, r0, asr r5 */
/* @0x2908b0 .word 0xffffe90c */
/* @0x2908b4 andeq r8, r12, r8, asr r5 */
/* @0x2908b8 .word 0xfffffcf8 */
/* @0x2908bc .word 0xffffbcf0 */
/* @0x2908c0 andeq r8, r12, r8, asr r5 */
/* @0x2908c4 andeq r8, r12, r8, asr #10 */
/* @0x2908c8 andeq r9, r11, r4, ror #2 */
/* @0x2908cc andeq r8, r12, r12, lsr r5 */
/* @0x2908d0 andeq r8, r12, r0, lsl #10 */
/* @0x2908d4 strdeq r8, r9, [r12], -r4 */
/* @0x2908d8 .word 0xfffffcfc */
/* @0x2908dc .word 0xffffc964 */
/* @0x2908e0 andeq r7, r12, r0, lsl #14 */
/* @0x2908e4 strdeq r7, r8, [r12], -r0 */
/* @0x2908e8 andeq r7, r12, r0, lsl r7 */
/* @0x2908ec andeq r7, r12, r4, lsr r7 */
/* @0x2908f0 .word 0xffffe2cc */
/* @0x2908f4 andeq r7, r12, r8, asr #13 */
/* @0x2908f8 andeq r7, r12, r12, lsr r7 */
/* @0x2908fc .word 0xffffe304 */
/* @0x290900 strheq r7, [r12], -r12 */
/* @0x290904 .word 0xffffe30c */
/* @0x290908 strheq r7, [r12], -r8 */
/* @0x29090c andeq r7, r12, r8, ror #16 */
/* @0x290910 .word 0xffffe308 */
/* @0x290914 muleq r12, r12, r6 */
/* @0x290918 .word 0xffffe2dc */
/* @0x29091c andeq r7, r12, r8, lsl #13 */
/* @0x290920 .word 0xffffe2f8 */
/* @0x290924 andeq r11, r11, r0, lsr #15 */
/* @0x290928 andeq r7, r12, r12, ror #12 */
/* @0x29092c .word 0xffffe2bc */
/* @0x290930 andeq r7, r12, r8, asr #12 */
/* @0x290934 .word 0xffffe2ec */
/* @0x290938 andeq r7, r12, r8, lsr r6 */
/* @0x29093c andeq r7, r12, r12, asr #12 */
/* @0x290940 .word 0xffffe2e4 */
/* @0x290944 andeq r7, r12, r0, asr #12 */
/* @0x290948 andeq r7, r12, r0, asr r6 */
/* @0x29094c .word 0xfffff76c */
/* @0x290950 andeq r7, r12, r8, ror r6 */
/* @0x290954 .word 0xffffe2f0 */
/* @0x290958 andeq r7, r12, r0, ror #12 */
/* @0x29095c andeq r7, r12, r8, ror #12 */
/* @0x290960 .word 0xffffe2e0 */
/* @0x290964 andeq r7, r12, r8, asr r6 */
/* @0x290968 .word 0xffffe2f4 */
/* @0x29096c andeq r7, r12, r0, asr #12 */
/* @0x290970 .word 0xffffe2e8 */
/* @0x290974 andeq r7, r12, r4, lsr #12 */
/* @0x290978 .word 0xffffe2d4 */
/* @0x29097c andeq r7, r12, r0, lsl r6 */
/* @0x290980 .word 0xffffe2d0 */
/* @0x290984 strdeq r7, r8, [r12], -r8 */
/* @0x290988 .word 0xffffe2d8 */
/* @0x29098c andeq r7, r12, r0, ror #11 */
/* @0x290990 .word 0xffffe22c */
/* @0x290994 andeq r7, r12, r8, asr #11 */
/* @0x290998 muleq r12, r12, r6 */
/* @0x29099c .word 0xffffe228 */
/* @0x2909a0 andeq r7, r12, r0, lsr #11 */
/* @0x2909a4 .word 0xffffe224 */
/* @0x2909a8 muleq r12, r0, r5 */
/* @0x2909ac andeq r7, r12, r0, ror r5 */
/* @0x2909b0 .word 0xffffe230 */
/* @0x2909b4 andeq r7, r12, r12, asr r5 */
/* @0x2909b8 .word 0xffffe234 */
/* @0x2909bc andeq r7, r12, r12, lsr r5 */
/* @0x2909c0 .word 0xffffe238 */
/* @0x2909c4 andeq r7, r12, r4, lsr r5 */
/* @0x2909c8 andeq r7, r12, r8, lsl r5 */
/* @0x2909cc .word 0xffffe23c */
/* @0x2909d0 andeq r7, r12, r4, lsl #10 */
/* @0x2909d4 .word 0xffffe240 */
/* @0x2909d8 andeq r7, r12, r12, ror #9 */
/* @0x2909dc strdeq r7, r8, [r12], -r0 */
/* @0x2909e0 .word 0xffffe244 */
/* @0x2909e4 andeq r7, r12, r0, lsl r5 */
/* @0x2909e8 .word 0xffffe310 */
/* @0x2909ec andeq r7, r12, r0, lsl r5 */
/* @0x2909f0 .word 0xffffe314 */
/* @0x2909f4 andeq r7, r12, r12, lsl r5 */
/* @0x2909f8 strdeq r7, r8, [r12], -r0 */
/* @0x2909fc .word 0xffffe318 */
/* @0x290a00 andeq r7, r12, r12, lsl #10 */
/* @0x290a04 andeq r7, r12, r12, lsl r5 */
/* @0x290a08 .word 0xffffe31c */
/* @0x290a0c andeq r7, r12, r12, lsl r5 */
/* @0x290a10 .word 0xffffe320 */
/* @0x290a14 andeq r7, r12, r8, lsl #10 */
/* @0x290a18 .word 0xffffe25c */
/* @0x290a1c andeq r7, r12, r8, ror #9 */
/* @0x290a20 muleq r12, r0, r5 */
/* @0x290a24 .word 0xffffe2b0 */
/* @0x290a28 andeq r7, r12, r0, ror #9 */
/* @0x290a2c andeq r7, r12, r0, asr #9 */
/* @0x290a30 .word 0xffffe274 */
/* @0x290a34 andeq r7, r12, r0, asr #9 */
/* @0x290a38 .word 0xffffe270 */
/* @0x290a3c andeq r7, r12, r4, lsr #9 */
/* @0x290a40 strheq r7, [r12], -r4 */
/* @0x290a44 .word 0xffffe264 */
/* @0x290a48 andeq r7, r12, r4, asr #9 */
/* @0x290a4c .word 0xffffe2b8 */
/* @0x290a50 ldrdeq r7, r8, [r12], -r4 */
/* @0x290a54 andeq r7, r12, r12, lsr #13 */
/* @0x290a58 .word 0xffffe268 */
/* @0x290a5c strheq r7, [r12], -r8 */
/* @0x290a60 .word 0xffffe26c */
/* @0x290a64 andeq r7, r12, r0, lsr #9 */
/* @0x290a68 .word 0xffffe278 */
/* @0x290a6c andeq r7, r12, r8, lsl #9 */
/* @0x290a70 andeq r6, r12, r12, ror #29 */
/* @0x290a74 .word 0xffffe260 */
/* @0x290a78 andeq r7, r12, r0, ror r4 */
/* @0x290a7c andeq r7, r12, r4, lsl #9 */
/* @0x290a80 .word 0xffffe2b4 */
/* @0x290a84 andeq r7, r12, r4, ror r4 */
/* @0x290a88 .word 0xffffea0c */
/* @0x290a8c andeq r7, r12, r0, asr r4 */
/* @0x290a90 .word 0xffffea10 */
/* @0x290a94 andeq r7, r12, r0, lsr r4 */
/* @0x290a98 andeq r7, r12, r4, lsr r4 */
/* @0x290a9c .word 0xffffea14 */
/* @0x290aa0 andeq r7, r12, r8, asr #8 */
/* @0x290aa4 .word 0xffffea18 */
/* @0x290aa8 andeq r7, r12, r0, lsr r4 */
/* @0x290aac .word 0xfffff80c */
/* @0x290ab0 andeq r7, r12, r8, lsl #8 */
/* @0x290ab4 .word 0xfffff818 */
/* @0x290ab8 andeq r7, r12, r4, ror #7 */
/* @0x290abc .word 0xfffff810 */
/* @0x290ac0 andeq r7, r12, r4, asr #7 */
/* @0x290ac4 .word 0xfffff814 */
/* @0x290ac8 andeq r7, r12, r8, lsr #7 */
/* @0x290acc strheq r7, [r12], -r0 */
/* @0x290ad0 .word 0xfffff81c */
/* @0x290ad4 andeq r7, r12, r0, lsr #7 */
/* @0x290ad8 andeq r7, r12, r0, lsl #7 */
/* @0x290adc .word 0xfffff820 */
/* @0x290ae0 andeq r7, r12, r8, ror #6 */
/* @0x290ae4 .word 0xfffffd00 */
/* @0x290ae8 andeq r7, r12, r4, asr r3 */
/* @0x290aec .word 0xffffbd58 */
/* @0x290af0 andeq r7, r12, r4, lsr r3 */
/* @0x290af4 .word 0xffffe220 */
/* @0x290af8 andeq r7, r12, r4, lsr #6 */
/* @0x290afc andeq r7, r12, r8, lsr #6 */
/* @0x290b00 .word 0xffffc1ac */
/* @0x290b04 andeq r7, r12, r8, lsr r3 */
/* @0x290b08 .word 0xffffc1b0 */
/* @0x290b0c andeq r7, r12, r8, lsr r3 */
/* @0x290b10 .word 0xffffc1c0 */
/* @0x290b14 andeq r7, r12, r0, lsr #6 */
/* @0x290b18 .word 0xffffc1b4 */
/* @0x290b1c andeq r7, r12, r8, lsl #6 */
/* @0x290b20 .word 0xffffc1b8 */
/* @0x290b24 strdeq r7, r8, [r12], -r0 */
/* @0x290b28 .word 0xffffc1bc */
/* @0x290b2c ldrdeq r7, r8, [r12], -r0 */
/* @0x290b30 ldrdeq r7, r8, [r12], -r12 */
/* @0x290b34 .word 0xffffe27c */
/* @0x290b38 andeq r7, r12, r0, asr #5 */
/* @0x290b3c .word 0xffffe290 */
/* @0x290b40 andeq r7, r12, r4, lsr #5 */
/* @0x290b44 .word 0xffffe298 */
/* @0x290b48 andeq r7, r12, r12, lsl #5 */
/* @0x290b4c .word 0xffffe29c */
/* @0x290b50 andeq r7, r12, r4, ror r2 */
/* @0x290b54 andeq r7, r12, r12, ror r2 */
/* @0x290b58 .word 0xffffe294 */
/* @0x290b5c andeq r7, r12, r12, asr r2 */
/* @0x290b60 .word 0xffffe2a0 */
/* @0x290b64 andeq r7, r12, r0, asr #4 */
/* @0x290b68 andeq r7, r12, r12, asr #4 */
/* @0x290b6c .word 0xffffe2a4 */
/* @0x290b70 andeq r7, r12, r0, asr r2 */
/* @0x290b74 .word 0xffffe2fc */
/* @0x290b78 andeq r7, r12, r4, lsr r2 */
/* @0x290b7c .word 0xffffe300 */
/* @0x290b80 andeq r7, r12, r8, lsl r2 */
/* @0x290b84 .word 0xfffffd04 */
/* @0x290b88 andeq r7, r12, r0, lsl #4 */
/* @0x290b8c andeq r7, r12, r0, lsl r2 */
/* @0x290b90 .word 0xffffe2ac */
/* @0x290b94 andeq r7, r12, r0, lsl #4 */
/* @0x290b98 .word 0xfffffd08 */
/* @0x290b9c andeq r7, r12, r0, ror #3 */
/* @0x290ba0 strdeq r7, r8, [r12], -r0 */
/* @0x290ba4 .word 0xffffe324 */
/* @0x290ba8 andeq r7, r12, r4, lsl #4 */
/* @0x290bac andeq r10, r11, r0, ror #23 */
/* @0x290bb0 .word 0xffffe328 */
/* @0x290bb4 strdeq r7, r8, [r12], -r0 */
/* @0x290bb8 .word 0xffffe32c */
/* @0x290bbc andeq r7, r12, r0, ror #3 */
/* @0x290bc0 .word 0xffffe2a8 */
/* @0x290bc4 strheq r7, [r12], -r8 */
/* @0x290bc8 .word 0xfffffce4 */
/* @0x290bcc andeq r7, r12, r0, lsr #3 */
/* @0x290bd0 .word 0xfffffd0c */
/* @0x290bd4 andeq r7, r12, r4, ror #2 */
/* @0x290bd8 .word 0xfffffccc */
/* @0x290bdc .word 0xffffe2c4 */
/* @0x290be0 .word 0xffffe2c0 */
/* @0x290be4 .word 0xfffffcc8 */
/* @0x290be8 strheq r7, [r12], -r4 */
/* @0x290bec .word 0xfffffd10 */
/* @0x290bf0 andeq r7, r12, r12, lsr #1 */
/* @0x290bf4 andeq r7, r12, r12, lsl #1 */
/* @0x290bf8 .word 0xffffe788 */
/* @0x290bfc andeq r7, r12, r0, lsl #1 */
/* @0x290c00 ldr r3, [r4] */
/* @0x290c04 mov r1, r0 */
/* @0x290c08 mov r0, r4 */
/* @0x290c0c add r2, sp, #47 */
/* @0x290c10 str r2, [sp, #0x24] */
/* @0x290c14 ldr r3, [r3, #0x54] */
/* @0x290c18 blx r3 */
/* @0x290c1c ldr r9, [pc, #-0x344] */
/* @0x290c20 ldr r2, [pc, #-0x344] */
/* @0x290c24 add r9, pc, r9 */
/* @0x290c28 str r9, [sp, #0x4] */
/* @0x290c2c add r2, pc, r2 */
/* @0x290c30 ldr r11, [pc, #-0x350] */
/* @0x290c34 mov r3, r9 */
/* @0x290c38 ldr r9, [pc, #-0x354] */
/* @0x290c3c add r11, pc, r11 */
/* @0x290c40 add r9, pc, r9 */
/* @0x290c44 str r0, [r6] */
/* @0x290c48 mov r1, r0 */
/* @0x290c4c ldr r12, [r4] */
/* @0x290c50 mov r0, r4 */
/* @0x290c54 ldr r12, [r12, #0x1c4] */
/* @0x290c58 blx r12 */
/* @0x290c5c ldr r12, [pc, #-0x374] */
/* @0x290c60 str r11, [sp, #0x18] */
/* @0x290c64 mov r3, r11 */
/* @0x290c68 ldr r2, [pc, #-0x37c] */
/* @0x290c6c ldr r12, [r5, r12] */
/* @0x290c70 ldr r1, [r6] */
/* @0x290c74 add r2, pc, r2 */
/* @0x290c78 ldr r11, [pc, #-0x388] */
/* @0x290c7c add r11, pc, r11 */
/* @0x290c80 str r0, [r12] */
/* @0x290c84 mov r0, r4 */
/* @0x290c88 ldr r12, [r4] */
/* @0x290c8c ldr r12, [r12, #0x1c4] */
/* @0x290c90 blx r12 */
/* @0x290c94 ldr r12, [pc, #-0x3a0] */
/* @0x290c98 ldr r2, [pc, #-0x3a0] */
/* @0x290c9c mov r3, r9 */
/* @0x290ca0 ldr r1, [r6] */
/* @0x290ca4 ldr r12, [r5, r12] */
/* @0x290ca8 add r2, pc, r2 */
/* @0x290cac str r0, [r12] */
/* @0x290cb0 mov r0, r4 */
/* @0x290cb4 ldr r12, [r4] */
/* @0x290cb8 ldr r12, [r12, #0x1c4] */
/* @0x290cbc blx r12 */
/* @0x290cc0 ldr r12, [pc, #-0x3c4] */
/* @0x290cc4 ldr r2, [pc, #-0x3c4] */
/* @0x290cc8 mov r3, r9 */
/* @0x290ccc ldr r1, [r6] */
/* @0x290cd0 ldr r12, [r5, r12] */
/* @0x290cd4 add r2, pc, r2 */
/* @0x290cd8 ldr r9, [pc, #-0x3d4] */
/* @0x290cdc add r9, pc, r9 */
/* @0x290ce0 str r0, [r12] */
/* @0x290ce4 mov r0, r4 */
/* @0x290ce8 ldr r12, [r4] */
/* @0x290cec ldr r12, [r12, #0x1c4] */
/* @0x290cf0 blx r12 */
/* @0x290cf4 ldr r12, [pc, #-0x3ec] */
/* @0x290cf8 ldr r2, [pc, #-0x3ec] */
/* @0x290cfc mov r3, r11 */
/* @0x290d00 ldr r1, [r6] */
/* @0x290d04 ldr r12, [r5, r12] */
/* @0x290d08 add r2, pc, r2 */
/* @0x290d0c str r0, [r12] */
/* @0x290d10 mov r0, r4 */
/* @0x290d14 ldr r12, [r4] */
/* @0x290d18 ldr r12, [r12, #0x1c4] */
/* @0x290d1c blx r12 */
/* @0x290d20 ldr r12, [pc, #-0x410] */
/* @0x290d24 ldr r2, [pc, #-0x410] */
/* @0x290d28 mov r3, r11 */
/* @0x290d2c ldr r1, [r6] */
/* @0x290d30 ldr r12, [r5, r12] */
/* @0x290d34 add r2, pc, r2 */
/* @0x290d38 str r0, [r12] */
/* @0x290d3c mov r0, r4 */
/* @0x290d40 ldr r12, [r4] */
/* @0x290d44 ldr r12, [r12, #0x1c4] */
/* @0x290d48 blx r12 */
/* @0x290d4c ldr r12, [pc, #-0x434] */
/* @0x290d50 ldr r3, [pc, #-0x434] */
/* @0x290d54 ldr r2, [pc, #-0x434] */
/* @0x290d58 add r3, pc, r3 */
/* @0x290d5c str r3, [sp, #0xc] */
/* @0x290d60 ldr r12, [r5, r12] */
/* @0x290d64 add r2, pc, r2 */
/* @0x290d68 ldr r1, [r6] */
/* @0x290d6c str r0, [r12] */
/* @0x290d70 mov r0, r4 */
/* @0x290d74 ldr r12, [r4] */
/* @0x290d78 ldr r12, [r12, #0x1c4] */
/* @0x290d7c blx r12 */
/* @0x290d80 ldr r12, [pc, #-0x45c] */
/* @0x290d84 ldr r2, [pc, #-0x45c] */
/* @0x290d88 mov r3, r11 */
/* @0x290d8c ldr r1, [r6] */
/* @0x290d90 ldr r12, [r5, r12] */
/* @0x290d94 add r2, pc, r2 */
/* @0x290d98 str r0, [r12] */
/* @0x290d9c mov r0, r4 */
/* @0x290da0 ldr r12, [r4] */
/* @0x290da4 ldr r12, [r12, #0x1c4] */
/* @0x290da8 blx r12 */
/* @0x290dac ldr r3, [pc, #-0x480] */
/* @0x290db0 ldr r2, [pc, #-0x480] */
/* @0x290db4 ldr r1, [r6] */
/* @0x290db8 ldr r12, [r5, r3] */
/* @0x290dbc add r2, pc, r2 */
/* @0x290dc0 ldr r3, [pc, #-0x48c] */
/* @0x290dc4 add r3, pc, r3 */
/* @0x290dc8 str r0, [r12] */
/* @0x290dcc mov r0, r4 */
/* @0x290dd0 ldr r12, [r4] */
/* @0x290dd4 ldr r12, [r12, #0x1c4] */
/* @0x290dd8 blx r12 */
/* @0x290ddc ldr r3, [pc, #-0x4a4] */
/* @0x290de0 ldr r2, [pc, #-0x4a4] */
/* @0x290de4 ldr r1, [r6] */
/* @0x290de8 ldr r12, [r5, r3] */
/* @0x290dec add r2, pc, r2 */
/* @0x290df0 ldr r3, [pc, #-0x4b0] */
/* @0x290df4 add r3, pc, r3 */
/* @0x290df8 str r0, [r12] */
/* @0x290dfc mov r0, r4 */
/* @0x290e00 ldr r12, [r4] */
/* @0x290e04 ldr r12, [r12, #0x1c4] */
/* @0x290e08 blx r12 */
/* @0x290e0c ldr r12, [pc, #-0x4c8] */
/* @0x290e10 ldr r2, [pc, #-0x4c8] */
/* @0x290e14 ldr r3, [sp, #0x4] */
/* @0x290e18 ldr r12, [r5, r12] */
/* @0x290e1c add r2, pc, r2 */
/* @0x290e20 ldr r1, [r6] */
/* @0x290e24 str r0, [r12] */
/* @0x290e28 mov r0, r4 */
/* @0x290e2c ldr r12, [r4] */
/* @0x290e30 ldr r12, [r12, #0x1c4] */
/* @0x290e34 blx r12 */
/* @0x290e38 ldr r3, [pc, #-0x4ec] */
/* @0x290e3c ldr r2, [pc, #-0x4ec] */
/* @0x290e40 ldr r1, [r6] */
/* @0x290e44 ldr r12, [r5, r3] */
/* @0x290e48 add r2, pc, r2 */
/* @0x290e4c ldr r3, [pc, #-0x4f8] */
/* @0x290e50 add r3, pc, r3 */
/* @0x290e54 str r0, [r12] */
/* @0x290e58 mov r0, r4 */
/* @0x290e5c ldr r12, [r4] */
/* @0x290e60 ldr r12, [r12, #0x1c4] */
/* @0x290e64 blx r12 */
/* @0x290e68 ldr r12, [pc, #-0x510] */
/* @0x290e6c ldr r2, [pc, #-0x510] */
/* @0x290e70 ldr r3, [sp, #0x4] */
/* @0x290e74 ldr r12, [r5, r12] */
/* @0x290e78 add r2, pc, r2 */
/* @0x290e7c ldr r1, [r6] */
/* @0x290e80 str r0, [r12] */
/* @0x290e84 mov r0, r4 */
/* @0x290e88 ldr r12, [r4] */
/* @0x290e8c ldr r12, [r12, #0x1c4] */
/* @0x290e90 blx r12 */
/* @0x290e94 ldr r12, [pc, #-0x534] */
/* @0x290e98 ldr r2, [pc, #-0x534] */
/* @0x290e9c ldr r3, [sp, #0x4] */
/* @0x290ea0 ldr r12, [r5, r12] */
/* @0x290ea4 add r2, pc, r2 */
/* @0x290ea8 ldr r1, [r6] */
/* @0x290eac str r0, [r12] */
/* @0x290eb0 mov r0, r4 */
/* @0x290eb4 ldr r12, [r4] */
/* @0x290eb8 ldr r12, [r12, #0x1c4] */
/* @0x290ebc blx r12 */
/* @0x290ec0 ldr r12, [pc, #-0x558] */
/* @0x290ec4 ldr r2, [pc, #-0x558] */
/* @0x290ec8 mov r3, r11 */
/* @0x290ecc ldr r1, [r6] */
/* @0x290ed0 ldr r12, [r5, r12] */
/* @0x290ed4 add r2, pc, r2 */
/* @0x290ed8 str r0, [r12] */
/* @0x290edc mov r0, r4 */
/* @0x290ee0 ldr r12, [r4] */
/* @0x290ee4 ldr r12, [r12, #0x1c4] */
/* @0x290ee8 blx r12 */
/* @0x290eec ldr r12, [pc, #-0x57c] */
/* @0x290ef0 ldr r2, [pc, #-0x57c] */
/* @0x290ef4 ldr r3, [sp, #0xc] */
/* @0x290ef8 ldr r12, [r5, r12] */
/* @0x290efc add r2, pc, r2 */
/* @0x290f00 ldr r1, [r6] */
/* @0x290f04 str r0, [r12] */
/* @0x290f08 mov r0, r4 */
/* @0x290f0c ldr r12, [r4] */
/* @0x290f10 ldr r12, [r12, #0x1c4] */
/* @0x290f14 blx r12 */
/* @0x290f18 ldr r12, [pc, #-0x5a0] */
/* @0x290f1c ldr r2, [pc, #-0x5a0] */
/* @0x290f20 mov r3, r11 */
/* @0x290f24 ldr r1, [r6] */
/* @0x290f28 ldr r12, [r5, r12] */
/* @0x290f2c add r2, pc, r2 */
/* @0x290f30 str r0, [r12] */
/* @0x290f34 mov r0, r4 */
/* @0x290f38 ldr r12, [r4] */
/* @0x290f3c ldr r12, [r12, #0x1c4] */
/* @0x290f40 blx r12 */
/* @0x290f44 ldr r12, [pc, #-0x5c4] */
/* @0x290f48 ldr r2, [pc, #-0x5c4] */
/* @0x290f4c mov r3, r9 */
/* @0x290f50 ldr r1, [r6] */
/* @0x290f54 ldr r12, [r5, r12] */
/* @0x290f58 add r2, pc, r2 */
/* @0x290f5c str r0, [r12] */
/* @0x290f60 mov r0, r4 */
/* @0x290f64 ldr r12, [r4] */
/* @0x290f68 ldr r12, [r12, #0x1c4] */
/* @0x290f6c blx r12 */
/* @0x290f70 ldr r12, [pc, #-0x5e8] */
/* @0x290f74 ldr r2, [pc, #-0x5e8] */
/* @0x290f78 mov r3, r9 */
/* @0x290f7c ldr r1, [r6] */
/* @0x290f80 ldr r12, [r5, r12] */
/* @0x290f84 add r2, pc, r2 */
/* @0x290f88 ldr r9, [pc, #-0x5f8] */
/* @0x290f8c add r9, pc, r9 */
/* @0x290f90 str r0, [r12] */
/* @0x290f94 mov r0, r4 */
/* @0x290f98 ldr r12, [r4] */
/* @0x290f9c ldr r12, [r12, #0x1c4] */
/* @0x290fa0 blx r12 */
/* @0x290fa4 ldr r12, [pc, #-0x610] */
/* @0x290fa8 ldr r2, [pc, #-0x610] */
/* @0x290fac ldr r3, [sp, #0x4] */
/* @0x290fb0 ldr r12, [r5, r12] */
/* @0x290fb4 add r2, pc, r2 */
/* @0x290fb8 ldr r1, [r6] */
/* @0x290fbc str r0, [r12] */
/* @0x290fc0 mov r0, r4 */
/* @0x290fc4 ldr r12, [r4] */
/* @0x290fc8 ldr r12, [r12, #0x1c4] */
/* @0x290fcc blx r12 */
/* @0x290fd0 ldr r12, [pc, #-0x634] */
/* @0x290fd4 ldr r2, [pc, #-0x634] */
/* @0x290fd8 ldr r1, [r6] */
/* @0x290fdc add r2, pc, r2 */
/* @0x290fe0 str r2, [sp, #0x1c] */
/* @0x290fe4 ldr r12, [r5, r12] */
/* @0x290fe8 mov r3, r2 */
/* @0x290fec ldr r2, [pc, #-0x648] */
/* @0x290ff0 add r2, pc, r2 */
/* @0x290ff4 str r0, [r12] */
/* @0x290ff8 mov r0, r4 */
/* @0x290ffc ldr r12, [r4] */
/* @0x291000 ldr r12, [r12, #0x1c4] */
/* @0x291004 blx r12 */
/* @0x291008 ldr r12, [pc, #-0x660] */
/* @0x29100c ldr r2, [pc, #-0x660] */
/* @0x291010 ldr r3, [sp, #0x4] */
/* @0x291014 ldr r12, [r5, r12] */
/* @0x291018 add r2, pc, r2 */
/* @0x29101c ldr r1, [r6] */
/* @0x291020 str r0, [r12] */
/* @0x291024 mov r0, r4 */
/* @0x291028 ldr r12, [r4] */
/* @0x29102c ldr r12, [r12, #0x1c4] */
/* @0x291030 blx r12 */
/* @0x291034 ldr r12, [pc, #-0x684] */
/* @0x291038 ldr r2, [pc, #-0x684] */
/* @0x29103c ldr r3, [sp, #0x4] */
/* @0x291040 ldr r12, [r5, r12] */
/* @0x291044 add r2, pc, r2 */
/* @0x291048 ldr r1, [r6] */
/* @0x29104c str r0, [r12] */
/* @0x291050 mov r0, r4 */
/* @0x291054 ldr r12, [r4] */
/* @0x291058 ldr r12, [r12, #0x1c4] */
/* @0x29105c blx r12 */
/* @0x291060 ldr r12, [pc, #-0x6a8] */
/* @0x291064 ldr r3, [pc, #-0x6a8] */
/* @0x291068 ldr r2, [pc, #-0x6a8] */
/* @0x29106c add r3, pc, r3 */
/* @0x291070 str r3, [sp, #0x20] */
/* @0x291074 ldr r12, [r5, r12] */
/* @0x291078 add r2, pc, r2 */
/* @0x29107c ldr r1, [r6] */
/* @0x291080 str r0, [r12] */
/* @0x291084 mov r0, r4 */
/* @0x291088 ldr r12, [r4] */
/* @0x29108c ldr r12, [r12, #0x1c4] */
/* @0x291090 blx r12 */
/* @0x291094 ldr r12, [pc, #-0x6d0] */
/* @0x291098 ldr r2, [pc, #-0x6d0] */
/* @0x29109c ldr r3, [sp, #0x20] */
/* @0x2910a0 ldr r12, [r5, r12] */
/* @0x2910a4 add r2, pc, r2 */
/* @0x2910a8 ldr r1, [r6] */
/* @0x2910ac str r0, [r12] */
/* @0x2910b0 mov r0, r4 */
/* @0x2910b4 ldr r12, [r4] */
/* @0x2910b8 ldr r12, [r12, #0x1c4] */
/* @0x2910bc blx r12 */
/* @0x2910c0 ldr r3, [pc, #-0x6f4] */
/* @0x2910c4 ldr r2, [pc, #-0x6f4] */
/* @0x2910c8 ldr r1, [r6] */
/* @0x2910cc ldr r12, [r5, r3] */
/* @0x2910d0 add r2, pc, r2 */
/* @0x2910d4 ldr r3, [pc, #-0x700] */
/* @0x2910d8 add r3, pc, r3 */
/* @0x2910dc str r0, [r12] */
/* @0x2910e0 mov r0, r4 */
/* @0x2910e4 ldr r12, [r4] */
/* @0x2910e8 ldr r12, [r12, #0x1c4] */
/* @0x2910ec blx r12 */
/* @0x2910f0 ldr r12, [pc, #-0x718] */
/* @0x2910f4 ldr r2, [pc, #-0x718] */
/* @0x2910f8 mov r3, r9 */
/* @0x2910fc ldr r1, [r6] */
/* @0x291100 ldr r12, [r5, r12] */
/* @0x291104 add r2, pc, r2 */
/* @0x291108 str r0, [r12] */
/* @0x29110c mov r0, r4 */
/* @0x291110 ldr r12, [r4] */
/* @0x291114 ldr r12, [r12, #0x1c4] */
/* @0x291118 blx r12 */
/* @0x29111c ldr r12, [pc, #-0x73c] */
/* @0x291120 ldr r2, [pc, #-0x73c] */
/* @0x291124 mov r3, r11 */
/* @0x291128 ldr r1, [r6] */
/* @0x29112c ldr r12, [r5, r12] */
/* @0x291130 add r2, pc, r2 */
/* @0x291134 str r0, [r12] */
/* @0x291138 mov r0, r4 */
/* @0x29113c ldr r12, [r4] */
/* @0x291140 ldr r12, [r12, #0x1c4] */
/* @0x291144 blx r12 */
/* @0x291148 ldr r12, [pc, #-0x760] */
/* @0x29114c ldr r2, [pc, #-0x760] */
/* @0x291150 ldr r1, [r6] */
/* @0x291154 add r2, pc, r2 */
/* @0x291158 str r2, [sp, #0x10] */
/* @0x29115c ldr r12, [r5, r12] */
/* @0x291160 mov r3, r2 */
/* @0x291164 ldr r2, [pc, #-0x774] */
/* @0x291168 add r2, pc, r2 */
/* @0x29116c str r0, [r12] */
/* @0x291170 mov r0, r4 */
/* @0x291174 ldr r12, [r4] */
/* @0x291178 ldr r12, [r12, #0x1c4] */
/* @0x29117c blx r12 */
/* @0x291180 ldr r3, [pc, #-0x78c] */
/* @0x291184 ldr r2, [pc, #-0x78c] */
/* @0x291188 ldr r1, [r6] */
/* @0x29118c ldr r12, [r5, r3] */
/* @0x291190 add r2, pc, r2 */
/* @0x291194 ldr r3, [pc, #-0x798] */
/* @0x291198 add r3, pc, r3 */
/* @0x29119c str r0, [r12] */
/* @0x2911a0 mov r0, r4 */
/* @0x2911a4 ldr r12, [r4] */
/* @0x2911a8 ldr r12, [r12, #0x1c4] */
/* @0x2911ac blx r12 */
/* @0x2911b0 ldr r12, [pc, #-0x7b0] */
/* @0x2911b4 ldr r2, [pc, #-0x7b0] */
/* @0x2911b8 ldr r3, [sp, #0x4] */
/* @0x2911bc ldr r12, [r5, r12] */
/* @0x2911c0 add r2, pc, r2 */
/* @0x2911c4 ldr r1, [r6] */
/* @0x2911c8 str r0, [r12] */
/* @0x2911cc mov r0, r4 */
/* @0x2911d0 ldr r12, [r4] */
/* @0x2911d4 ldr r12, [r12, #0x1c4] */
/* @0x2911d8 blx r12 */
/* @0x2911dc ldr r12, [pc, #-0x7d4] */
/* @0x2911e0 ldr r2, [pc, #-0x7d4] */
/* @0x2911e4 ldr r3, [sp, #0x4] */
/* @0x2911e8 ldr r12, [r5, r12] */
/* @0x2911ec add r2, pc, r2 */
/* @0x2911f0 ldr r1, [r6] */
/* @0x2911f4 str r0, [r12] */
/* @0x2911f8 mov r0, r4 */
/* @0x2911fc ldr r12, [r4] */
/* @0x291200 ldr r12, [r12, #0x1c4] */
/* @0x291204 blx r12 */
/* @0x291208 ldr r12, [pc, #-0x7f8] */
/* @0x29120c ldr r2, [pc, #-0x7f8] */
/* @0x291210 mov r3, r9 */
/* @0x291214 ldr r1, [r6] */
/* @0x291218 ldr r12, [r5, r12] */
/* @0x29121c add r2, pc, r2 */
/* @0x291220 ldr r9, [pc, #-0x808] */
/* @0x291224 add r9, pc, r9 */
/* @0x291228 str r0, [r12] */
/* @0x29122c mov r0, r4 */
/* @0x291230 ldr r12, [r4] */
/* @0x291234 ldr r12, [r12, #0x1c4] */
/* @0x291238 blx r12 */
/* @0x29123c ldr r12, [pc, #-0x820] */
/* @0x291240 ldr r3, [pc, #-0x820] */
/* @0x291244 ldr r2, [pc, #-0x820] */
/* @0x291248 add r3, pc, r3 */
/* @0x29124c str r3, [sp, #0x14] */
/* @0x291250 ldr r12, [r5, r12] */
/* @0x291254 add r2, pc, r2 */
/* @0x291258 ldr r1, [r6] */
/* @0x29125c str r0, [r12] */
/* @0x291260 mov r0, r4 */
/* @0x291264 ldr r12, [r4] */
/* @0x291268 ldr r12, [r12, #0x1c4] */
/* @0x29126c blx r12 */
/* @0x291270 ldr r12, [pc, #-0x848] */
/* @0x291274 ldr r2, [pc, #-0x848] */
/* @0x291278 ldr r3, [sp, #0x14] */
/* @0x29127c ldr r12, [r5, r12] */
/* @0x291280 add r2, pc, r2 */
/* @0x291284 ldr r1, [r6] */
/* @0x291288 str r0, [r12] */
/* @0x29128c mov r0, r4 */
/* @0x291290 ldr r12, [r4] */
/* @0x291294 ldr r12, [r12, #0x1c4] */
/* @0x291298 blx r12 */
/* @0x29129c ldr r3, [pc, #-0x86c] */
/* @0x2912a0 ldr r2, [pc, #-0x86c] */
/* @0x2912a4 ldr r1, [r6] */
/* @0x2912a8 ldr r12, [r5, r3] */
/* @0x2912ac add r2, pc, r2 */
/* @0x2912b0 ldr r3, [pc, #-0x878] */
/* @0x2912b4 add r3, pc, r3 */
/* @0x2912b8 str r0, [r12] */
/* @0x2912bc mov r0, r4 */
/* @0x2912c0 ldr r12, [r4] */
/* @0x2912c4 ldr r12, [r12, #0x1c4] */
/* @0x2912c8 blx r12 */
/* @0x2912cc ldr r12, [pc, #-0x890] */
/* @0x2912d0 ldr r2, [pc, #-0x890] */
/* @0x2912d4 mov r3, r9 */
/* @0x2912d8 ldr r1, [r6] */
/* @0x2912dc ldr r12, [r5, r12] */
/* @0x2912e0 add r2, pc, r2 */
/* @0x2912e4 str r0, [r12] */
/* @0x2912e8 mov r0, r4 */
/* @0x2912ec ldr r12, [r4] */
/* @0x2912f0 ldr r12, [r12, #0x1c4] */
/* @0x2912f4 blx r12 */
/* @0x2912f8 ldr r12, [pc, #-0x8b4] */
/* @0x2912fc ldr r2, [pc, #-0x8b4] */
/* @0x291300 mov r3, r9 */
/* @0x291304 ldr r1, [r6] */
/* @0x291308 ldr r12, [r5, r12] */
/* @0x29130c add r2, pc, r2 */
/* @0x291310 ldr r9, [pc, #-0x8c4] */
/* @0x291314 add r9, pc, r9 */
/* @0x291318 str r0, [r12] */
/* @0x29131c mov r0, r4 */
/* @0x291320 ldr r12, [r4] */
/* @0x291324 ldr r12, [r12, #0x1c4] */
/* @0x291328 blx r12 */
/* @0x29132c ldr r12, [pc, #-0x8dc] */
/* @0x291330 ldr r2, [pc, #-0x8dc] */
/* @0x291334 mov r3, r11 */
/* @0x291338 ldr r1, [r6] */
/* @0x29133c ldr r12, [r5, r12] */
/* @0x291340 add r2, pc, r2 */
/* @0x291344 str r0, [r12] */
/* @0x291348 mov r0, r4 */
/* @0x29134c ldr r12, [r4] */
/* @0x291350 ldr r12, [r12, #0x1c4] */
/* @0x291354 blx r12 */
/* @0x291358 ldr r12, [pc, #-0x900] */
/* @0x29135c ldr r2, [pc, #-0x900] */
/* @0x291360 ldr r3, [sp, #0x14] */
/* @0x291364 ldr r12, [r5, r12] */
/* @0x291368 add r2, pc, r2 */
/* @0x29136c ldr r1, [r6] */
/* @0x291370 str r0, [r12] */
/* @0x291374 mov r0, r4 */
/* @0x291378 ldr r12, [r4] */
/* @0x29137c ldr r12, [r12, #0x1c4] */
/* @0x291380 blx r12 */
/* @0x291384 ldr r3, [pc, #-0x924] */
/* @0x291388 ldr r2, [pc, #-0x924] */
/* @0x29138c ldr r1, [r6] */
/* @0x291390 ldr r12, [r5, r3] */
/* @0x291394 add r2, pc, r2 */
/* @0x291398 ldr r3, [pc, #-0x930] */
/* @0x29139c add r3, pc, r3 */
/* @0x2913a0 str r0, [r12] */
/* @0x2913a4 mov r0, r4 */
/* @0x2913a8 ldr r12, [r4] */
/* @0x2913ac ldr r12, [r12, #0x1c4] */
/* @0x2913b0 blx r12 */
/* @0x2913b4 ldr r3, [pc, #-0x948] */
/* @0x2913b8 ldr r2, [pc, #-0x948] */
/* @0x2913bc ldr r1, [r6] */
/* @0x2913c0 ldr r12, [r5, r3] */
/* @0x2913c4 add r2, pc, r2 */
/* @0x2913c8 ldr r3, [pc, #-0x954] */
/* @0x2913cc add r3, pc, r3 */
/* @0x2913d0 str r0, [r12] */
/* @0x2913d4 mov r0, r4 */
/* @0x2913d8 ldr r12, [r4] */
/* @0x2913dc ldr r12, [r12, #0x1c4] */
/* @0x2913e0 blx r12 */
/* @0x2913e4 ldr r12, [pc, #-0x96c] */
/* @0x2913e8 ldr r2, [pc, #-0x96c] */
/* @0x2913ec ldr r3, [sp, #0x18] */
/* @0x2913f0 ldr r12, [r5, r12] */
/* @0x2913f4 add r2, pc, r2 */
/* @0x2913f8 ldr r1, [r6] */
/* @0x2913fc str r0, [r12] */
/* @0x291400 mov r0, r4 */
/* @0x291404 ldr r12, [r4] */
/* @0x291408 ldr r12, [r12, #0x1c4] */
/* @0x29140c blx r12 */
/* @0x291410 ldr r12, [pc, #-0x990] */
/* @0x291414 ldr r2, [pc, #-0x990] */
/* @0x291418 ldr r3, [sp, #0x10] */
/* @0x29141c ldr r12, [r5, r12] */
/* @0x291420 add r2, pc, r2 */
/* @0x291424 ldr r1, [r6] */
/* @0x291428 str r0, [r12] */
/* @0x29142c mov r0, r4 */
/* @0x291430 ldr r12, [r4] */
/* @0x291434 ldr r12, [r12, #0x1c4] */
/* @0x291438 blx r12 */
/* @0x29143c ldr r3, [pc, #-0x9b4] */
/* @0x291440 ldr r2, [pc, #-0x9b4] */
/* @0x291444 ldr r1, [r6] */
/* @0x291448 ldr r12, [r5, r3] */
/* @0x29144c add r2, pc, r2 */
/* @0x291450 ldr r3, [pc, #-0x9c0] */
/* @0x291454 add r3, pc, r3 */
/* @0x291458 str r0, [r12] */
/* @0x29145c mov r0, r4 */
/* @0x291460 ldr r12, [r4] */
/* @0x291464 ldr r12, [r12, #0x1c4] */
/* @0x291468 blx r12 */
/* @0x29146c ldr r12, [pc, #-0x9d8] */
/* @0x291470 ldr r2, [pc, #-0x9d8] */
/* @0x291474 mov r3, r11 */
/* @0x291478 ldr r1, [r6] */
/* @0x29147c ldr r12, [r5, r12] */
/* @0x291480 add r2, pc, r2 */
/* @0x291484 str r0, [r12] */
/* @0x291488 mov r0, r4 */
/* @0x29148c ldr r12, [r4] */
/* @0x291490 ldr r12, [r12, #0x1c4] */
/* @0x291494 blx r12 */
/* @0x291498 ldr r12, [pc, #-0x9fc] */
/* @0x29149c ldr r2, [pc, #-0x9fc] */
/* @0x2914a0 ldr r3, [sp, #0x18] */
/* @0x2914a4 ldr r12, [r5, r12] */
/* @0x2914a8 add r2, pc, r2 */
/* @0x2914ac ldr r1, [r6] */
/* @0x2914b0 str r0, [r12] */
/* @0x2914b4 mov r0, r4 */
/* @0x2914b8 ldr r12, [r4] */
/* @0x2914bc ldr r12, [r12, #0x1c4] */
/* @0x2914c0 blx r12 */
/* @0x2914c4 ldr r12, [pc, #-0xa20] */
/* @0x2914c8 ldr r2, [pc, #-0xa20] */
/* @0x2914cc mov r3, r11 */
/* @0x2914d0 ldr r1, [r6] */
/* @0x2914d4 ldr r12, [r5, r12] */
/* @0x2914d8 add r2, pc, r2 */
/* @0x2914dc str r0, [r12] */
/* @0x2914e0 mov r0, r4 */
/* @0x2914e4 ldr r12, [r4] */
/* @0x2914e8 ldr r12, [r12, #0x1c4] */
/* @0x2914ec blx r12 */
/* @0x2914f0 ldr r12, [pc, #-0xa44] */
/* @0x2914f4 ldr r2, [pc, #-0xa44] */
/* @0x2914f8 mov r3, r11 */
/* @0x2914fc ldr r1, [r6] */
/* @0x291500 ldr r12, [r5, r12] */
/* @0x291504 add r2, pc, r2 */
/* @0x291508 str r0, [r12] */
/* @0x29150c mov r0, r4 */
/* @0x291510 ldr r12, [r4] */
/* @0x291514 ldr r12, [r12, #0x1c4] */
/* @0x291518 blx r12 */
/* @0x29151c ldr r12, [pc, #-0xa68] */
/* @0x291520 ldr r2, [pc, #-0xa68] */
/* @0x291524 mov r3, r11 */
/* @0x291528 ldr r1, [r6] */
/* @0x29152c ldr r12, [r5, r12] */
/* @0x291530 add r2, pc, r2 */
/* @0x291534 str r0, [r12] */
/* @0x291538 mov r0, r4 */
/* @0x29153c ldr r12, [r4] */
/* @0x291540 ldr r12, [r12, #0x1c4] */
/* @0x291544 blx r12 */
/* @0x291548 ldr r3, [pc, #-0xa8c] */
/* @0x29154c ldr r2, [pc, #-0xa8c] */
/* @0x291550 ldr r1, [r6] */
/* @0x291554 ldr r12, [r5, r3] */
/* @0x291558 add r2, pc, r2 */
/* @0x29155c ldr r3, [pc, #-0xa98] */
/* @0x291560 add r3, pc, r3 */
/* @0x291564 str r0, [r12] */
/* @0x291568 mov r0, r4 */
/* @0x29156c ldr r12, [r4] */
/* @0x291570 ldr r12, [r12, #0x1c4] */
/* @0x291574 blx r12 */
/* @0x291578 ldr r12, [pc, #-0xab0] */
/* @0x29157c ldr r2, [pc, #-0xab0] */
/* @0x291580 ldr r1, [r6] */
/* @0x291584 add r2, pc, r2 */
/* @0x291588 str r2, [sp, #0x8] */
/* @0x29158c ldr r12, [r5, r12] */
/* @0x291590 mov r3, r2 */
/* @0x291594 ldr r2, [pc, #-0xac4] */
/* @0x291598 add r2, pc, r2 */
/* @0x29159c str r0, [r12] */
/* @0x2915a0 mov r0, r4 */
/* @0x2915a4 ldr r12, [r4] */
/* @0x2915a8 ldr r12, [r12, #0x1c4] */
/* @0x2915ac blx r12 */
/* @0x2915b0 ldr r12, [pc, #-0xadc] */
/* @0x2915b4 ldr r2, [pc, #-0xadc] */
/* @0x2915b8 ldr r3, [sp, #0xc] */
/* @0x2915bc ldr r12, [r5, r12] */
/* @0x2915c0 add r2, pc, r2 */
/* @0x2915c4 ldr r1, [r6] */
/* @0x2915c8 str r0, [r12] */
/* @0x2915cc mov r0, r4 */
/* @0x2915d0 ldr r12, [r4] */
/* @0x2915d4 ldr r12, [r12, #0x1c4] */
/* @0x2915d8 blx r12 */
/* @0x2915dc ldr r12, [pc, #-0xb00] */
/* @0x2915e0 ldr r2, [pc, #-0xb00] */
/* @0x2915e4 ldr r3, [sp, #0x4] */
/* @0x2915e8 ldr r12, [r5, r12] */
/* @0x2915ec add r2, pc, r2 */
/* @0x2915f0 ldr r1, [r6] */
/* @0x2915f4 str r0, [r12] */
/* @0x2915f8 mov r0, r4 */
/* @0x2915fc ldr r12, [r4] */
/* @0x291600 ldr r12, [r12, #0x1c4] */
/* @0x291604 blx r12 */
/* @0x291608 ldr r12, [pc, #-0xb24] */
/* @0x29160c ldr r2, [pc, #-0xb24] */
/* @0x291610 ldr r3, [sp, #0x1c] */
/* @0x291614 ldr r12, [r5, r12] */
/* @0x291618 add r2, pc, r2 */
/* @0x29161c ldr r1, [r6] */
/* @0x291620 str r0, [r12] */
/* @0x291624 mov r0, r4 */
/* @0x291628 ldr r12, [r4] */
/* @0x29162c ldr r12, [r12, #0x1c4] */
/* @0x291630 blx r12 */
/* @0x291634 ldr r3, [pc, #-0xb48] */
/* @0x291638 ldr r2, [pc, #-0xb48] */
/* @0x29163c ldr r1, [r6] */
/* @0x291640 ldr r12, [r5, r3] */
/* @0x291644 add r2, pc, r2 */
/* @0x291648 ldr r3, [pc, #-0xb54] */
/* @0x29164c add r3, pc, r3 */
/* @0x291650 str r0, [r12] */
/* @0x291654 mov r0, r4 */
/* @0x291658 ldr r12, [r4] */
/* @0x29165c ldr r12, [r12, #0x1c4] */
/* @0x291660 blx r12 */
/* @0x291664 ldr r12, [pc, #-0xb6c] */
/* @0x291668 ldr r2, [pc, #-0xb6c] */
/* @0x29166c mov r3, r9 */
/* @0x291670 ldr r1, [r6] */
/* @0x291674 ldr r12, [r5, r12] */
/* @0x291678 add r2, pc, r2 */
/* @0x29167c str r0, [r12] */
/* @0x291680 mov r0, r4 */
/* @0x291684 ldr r12, [r4] */
/* @0x291688 ldr r12, [r12, #0x1c4] */
/* @0x29168c blx r12 */
/* @0x291690 ldr r12, [pc, #-0xb90] */
/* @0x291694 ldr r2, [pc, #-0xb90] */
/* @0x291698 ldr r3, [sp, #0x18] */
/* @0x29169c ldr r12, [r5, r12] */
/* @0x2916a0 add r2, pc, r2 */
/* @0x2916a4 ldr r1, [r6] */
/* @0x2916a8 str r0, [r12] */
/* @0x2916ac mov r0, r4 */
/* @0x2916b0 ldr r12, [r4] */
/* @0x2916b4 ldr r12, [r12, #0x1c4] */
/* @0x2916b8 blx r12 */
/* @0x2916bc ldr r12, [pc, #-0xbb4] */
/* @0x2916c0 ldr r2, [pc, #-0xbb4] */
/* @0x2916c4 ldr r3, [sp, #0x10] */
/* @0x2916c8 ldr r12, [r5, r12] */
/* @0x2916cc add r2, pc, r2 */
/* @0x2916d0 ldr r1, [r6] */
/* @0x2916d4 str r0, [r12] */
/* @0x2916d8 mov r0, r4 */
/* @0x2916dc ldr r12, [r4] */
/* @0x2916e0 ldr r12, [r12, #0x1c4] */
/* @0x2916e4 blx r12 */
/* @0x2916e8 ldr r12, [pc, #-0xbd8] */
/* @0x2916ec ldr r2, [pc, #-0xbd8] */
/* @0x2916f0 ldr r3, [sp, #0x18] */
/* @0x2916f4 ldr r12, [r5, r12] */
/* @0x2916f8 add r2, pc, r2 */
/* @0x2916fc ldr r1, [r6] */
/* @0x291700 str r0, [r12] */
/* @0x291704 mov r0, r4 */
/* @0x291708 ldr r12, [r4] */
/* @0x29170c ldr r12, [r12, #0x1c4] */
/* @0x291710 blx r12 */
/* @0x291714 ldr r12, [pc, #-0xbfc] */
/* @0x291718 ldr r2, [pc, #-0xbfc] */
/* @0x29171c ldr r3, [sp, #0x10] */
/* @0x291720 ldr r12, [r5, r12] */
/* @0x291724 add r2, pc, r2 */
/* @0x291728 ldr r1, [r6] */
/* @0x29172c str r0, [r12] */
/* @0x291730 mov r0, r4 */
/* @0x291734 ldr r12, [r4] */
/* @0x291738 ldr r12, [r12, #0x1c4] */
/* @0x29173c blx r12 */
/* @0x291740 ldr r3, [pc, #-0xc20] */
/* @0x291744 ldr r2, [pc, #-0xc20] */
/* @0x291748 ldr r1, [r6] */
/* @0x29174c ldr r12, [r5, r3] */
/* @0x291750 add r2, pc, r2 */
/* @0x291754 ldr r3, [pc, #-0xc2c] */
/* @0x291758 add r3, pc, r3 */
/* @0x29175c str r0, [r12] */
/* @0x291760 mov r0, r4 */
/* @0x291764 ldr r12, [r4] */
/* @0x291768 ldr r12, [r12, #0x1c4] */
/* @0x29176c blx r12 */
/* @0x291770 ldr r12, [pc, #-0xc44] */
/* @0x291774 ldr r2, [pc, #-0xc44] */
/* @0x291778 ldr r3, [sp, #0x8] */
/* @0x29177c ldr r12, [r5, r12] */
/* @0x291780 add r2, pc, r2 */
/* @0x291784 ldr r1, [r6] */
/* @0x291788 str r0, [r12] */
/* @0x29178c mov r0, r4 */
/* @0x291790 ldr r12, [r4] */
/* @0x291794 ldr r12, [r12, #0x1c4] */
/* @0x291798 blx r12 */
/* @0x29179c ldr r12, [pc, #-0xc68] */
/* @0x2917a0 ldr r2, [pc, #-0xc68] */
/* @0x2917a4 mov r3, r9 */
/* @0x2917a8 ldr r1, [r6] */
/* @0x2917ac ldr r12, [r5, r12] */
/* @0x2917b0 add r2, pc, r2 */
/* @0x2917b4 str r0, [r12] */
/* @0x2917b8 mov r0, r4 */
/* @0x2917bc ldr r12, [r4] */
/* @0x2917c0 ldr r12, [r12, #0x1c4] */
/* @0x2917c4 blx r12 */
/* @0x2917c8 ldr r12, [pc, #-0xc8c] */
/* @0x2917cc ldr r2, [pc, #-0xc8c] */
/* @0x2917d0 ldr r3, [sp, #0x4] */
/* @0x2917d4 ldr r12, [r5, r12] */
/* @0x2917d8 add r2, pc, r2 */
/* @0x2917dc ldr r1, [r6] */
/* @0x2917e0 str r0, [r12] */
/* @0x2917e4 mov r0, r4 */
/* @0x2917e8 ldr r12, [r4] */
/* @0x2917ec ldr r12, [r12, #0x1c4] */
/* @0x2917f0 blx r12 */
/* @0x2917f4 ldr r3, [pc, #-0xcb0] */
/* @0x2917f8 ldr r2, [pc, #-0xcb0] */
/* @0x2917fc ldr r1, [r6] */
/* @0x291800 ldr r12, [r5, r3] */
/* @0x291804 add r2, pc, r2 */
/* @0x291808 ldr r3, [pc, #-0xcbc] */
/* @0x29180c add r3, pc, r3 */
/* @0x291810 str r0, [r12] */
/* @0x291814 mov r0, r4 */
/* @0x291818 ldr r12, [r4] */
/* @0x29181c ldr r12, [r12, #0x1c4] */
/* @0x291820 blx r12 */
/* @0x291824 ldr r12, [pc, #-0xcd4] */
/* @0x291828 ldr r2, [pc, #-0xcd4] */
/* @0x29182c ldr r3, [sp, #0x4] */
/* @0x291830 ldr r12, [r5, r12] */
/* @0x291834 add r2, pc, r2 */
/* @0x291838 ldr r1, [r6] */
/* @0x29183c str r0, [r12] */
/* @0x291840 mov r0, r4 */
/* @0x291844 ldr r12, [r4] */
/* @0x291848 ldr r12, [r12, #0x1c4] */
/* @0x29184c blx r12 */
/* @0x291850 ldr r3, [pc, #-0xcf8] */
/* @0x291854 ldr r2, [pc, #-0xcf8] */
/* @0x291858 ldr r1, [r6] */
/* @0x29185c ldr r12, [r5, r3] */
/* @0x291860 add r2, pc, r2 */
/* @0x291864 ldr r3, [pc, #-0xd04] */
/* @0x291868 add r3, pc, r3 */
/* @0x29186c str r0, [r12] */
/* @0x291870 mov r0, r4 */
/* @0x291874 ldr r12, [r4] */
/* @0x291878 ldr r12, [r12, #0x1c4] */
/* @0x29187c blx r12 */
/* @0x291880 ldr r12, [pc, #-0xd1c] */
/* @0x291884 ldr r2, [pc, #-0xd1c] */
/* @0x291888 ldr r3, [sp, #0x10] */
/* @0x29188c ldr r12, [r5, r12] */
/* @0x291890 add r2, pc, r2 */
/* @0x291894 ldr r1, [r6] */
/* @0x291898 str r0, [r12] */
/* @0x29189c mov r0, r4 */
/* @0x2918a0 ldr r12, [r4] */
/* @0x2918a4 ldr r12, [r12, #0x1c4] */
/* @0x2918a8 blx r12 */
/* @0x2918ac ldr r12, [pc, #-0xd40] */
/* @0x2918b0 ldr r2, [pc, #-0xd40] */
/* @0x2918b4 ldr r3, [sp, #0x1c] */
/* @0x2918b8 ldr r12, [r5, r12] */
/* @0x2918bc add r2, pc, r2 */
/* @0x2918c0 ldr r1, [r6] */
/* @0x2918c4 str r0, [r12] */
/* @0x2918c8 mov r0, r4 */
/* @0x2918cc ldr r12, [r4] */
/* @0x2918d0 ldr r12, [r12, #0x1c4] */
/* @0x2918d4 blx r12 */
/* @0x2918d8 ldr r12, [pc, #-0xd64] */
/* @0x2918dc ldr r2, [pc, #-0xd64] */
/* @0x2918e0 mov r3, r11 */
/* @0x2918e4 ldr r1, [r6] */
/* @0x2918e8 ldr r12, [r5, r12] */
/* @0x2918ec add r2, pc, r2 */
/* @0x2918f0 str r0, [r12] */
/* @0x2918f4 mov r0, r4 */
/* @0x2918f8 ldr r12, [r4] */
/* @0x2918fc ldr r12, [r12, #0x1c4] */
/* @0x291900 blx r12 */
/* @0x291904 ldr r3, [pc, #-0xd88] */
/* @0x291908 ldr r2, [pc, #-0xd88] */
/* @0x29190c ldr r1, [r6] */
/* @0x291910 ldr r12, [r5, r3] */
/* @0x291914 add r2, pc, r2 */
/* @0x291918 ldr r3, [pc, #-0xd94] */
/* @0x29191c add r3, pc, r3 */
/* @0x291920 str r0, [r12] */
/* @0x291924 mov r0, r4 */
/* @0x291928 ldr r12, [r4] */
/* @0x29192c ldr r12, [r12, #0x1c4] */
/* @0x291930 blx r12 */
/* @0x291934 ldr r12, [pc, #-0xdac] */
/* @0x291938 ldr r2, [pc, #-0xdac] */
/* @0x29193c ldr r3, [sp, #0xc] */
/* @0x291940 ldr r12, [r5, r12] */
/* @0x291944 add r2, pc, r2 */
/* @0x291948 ldr r1, [r6] */
/* @0x29194c str r0, [r12] */
/* @0x291950 mov r0, r4 */
/* @0x291954 ldr r12, [r4] */
/* @0x291958 ldr r12, [r12, #0x1c4] */
/* @0x29195c blx r12 */
/* @0x291960 ldr r3, [pc, #-0xdd0] */
/* @0x291964 ldr r2, [pc, #-0xdd0] */
/* @0x291968 ldr r1, [r6] */
/* @0x29196c ldr r12, [r5, r3] */
/* @0x291970 add r2, pc, r2 */
/* @0x291974 ldr r3, [pc, #-0xddc] */
/* @0x291978 add r3, pc, r3 */
/* @0x29197c str r0, [r12] */
/* @0x291980 mov r0, r4 */
/* @0x291984 ldr r12, [r4] */
/* @0x291988 ldr r12, [r12, #0x1c4] */
/* @0x29198c blx r12 */
/* @0x291990 ldr r3, [pc, #-0xdf4] */
/* @0x291994 ldr r2, [pc, #-0xdf4] */
/* @0x291998 ldr r1, [r6] */
/* @0x29199c ldr r12, [r5, r3] */
/* @0x2919a0 add r2, pc, r2 */
/* @0x2919a4 ldr r3, [pc, #-0xe00] */
/* @0x2919a8 add r3, pc, r3 */
/* @0x2919ac str r0, [r12] */
/* @0x2919b0 mov r0, r4 */
/* @0x2919b4 ldr r12, [r4] */
/* @0x2919b8 ldr r12, [r12, #0x1c4] */
/* @0x2919bc blx r12 */
/* @0x2919c0 ldr r12, [pc, #-0xe18] */
/* @0x2919c4 ldr r2, [pc, #-0xe18] */
/* @0x2919c8 ldr r3, [sp, #0x20] */
/* @0x2919cc ldr r12, [r5, r12] */
/* @0x2919d0 add r2, pc, r2 */
/* @0x2919d4 ldr r1, [r6] */
/* @0x2919d8 str r0, [r12] */
/* @0x2919dc mov r0, r4 */
/* @0x2919e0 ldr r12, [r4] */
/* @0x2919e4 ldr r12, [r12, #0x1c4] */
/* @0x2919e8 blx r12 */
/* @0x2919ec ldr r12, [pc, #-0xe3c] */
/* @0x2919f0 ldr r2, [pc, #-0xe3c] */
/* @0x2919f4 ldr r3, [sp, #0x14] */
/* @0x2919f8 ldr r12, [r5, r12] */
/* @0x2919fc add r2, pc, r2 */
/* @0x291a00 ldr r1, [r6] */
/* @0x291a04 str r0, [r12] */
/* @0x291a08 mov r0, r4 */
/* @0x291a0c ldr r12, [r4] */
/* @0x291a10 ldr r12, [r12, #0x1c4] */
/* @0x291a14 blx r12 */
/* @0x291a18 ldr r12, [pc, #-0xe60] */
/* @0x291a1c ldr r2, [pc, #-0xe60] */
/* @0x291a20 mov r3, r11 */
/* @0x291a24 ldr r1, [r6] */
/* @0x291a28 ldr r12, [r5, r12] */
/* @0x291a2c add r2, pc, r2 */
/* @0x291a30 str r0, [r12] */
/* @0x291a34 mov r0, r4 */
/* @0x291a38 ldr r12, [r4] */
/* @0x291a3c ldr r12, [r12, #0x1c4] */
/* @0x291a40 blx r12 */
/* @0x291a44 ldr r12, [pc, #-0xe84] */
/* @0x291a48 ldr r2, [pc, #-0xe84] */
/* @0x291a4c ldr r3, [sp, #0xc] */
/* @0x291a50 ldr r12, [r5, r12] */
/* @0x291a54 add r2, pc, r2 */
/* @0x291a58 ldr r1, [r6] */
/* @0x291a5c str r0, [r12] */
/* @0x291a60 mov r0, r4 */
/* @0x291a64 ldr r12, [r4] */
/* @0x291a68 ldr r12, [r12, #0x1c4] */
/* @0x291a6c blx r12 */
/* @0x291a70 ldr r3, [pc, #-0xea8] */
/* @0x291a74 add r2, sp, #47 */
/* @0x291a78 mov r1, r8 */
/* @0x291a7c ldr r3, [r5, r3] */
/* @0x291a80 str r0, [r3] */
/* @0x291a84 mov r0, r4 */
/* @0x291a88 ldr r3, [r4] */
/* @0x291a8c ldr r3, [r3, #0x2a4] */
/* @0x291a90 blx r3 */
/* @0x291a94 ldr r3, [r7] */
/* @0x291a98 ldr r1, [pc, #-0xecc] */
/* @0x291a9c ldr r3, [r3, #0xc] */
/* @0x291aa0 add r1, pc, r1 */
/* @0x291aa4 mov r9, r0 */
/* @0x291aa8 mov r2, r0 */
/* @0x291aac mov r0, r7 */
/* @0x291ab0 blx r3 */
/* @0x291ab4 ldr r3, [pc, #-0xee4] */
/* @0x291ab8 mov r1, #0 */
/* @0x291abc mov r0, r9 */
/* @0x291ac0 mov r2, r1 */
/* @0x291ac4 ldr r3, [r5, r3] */
/* @0x291ac8 str r9, [r3] */
/* @0x291acc blx 0x2a4de0 <zip_open> */
/* @0x291ad0 cmp r0, #0 */
/* @0x291ad4 beq 0x291c4c <Java_com_yoyogames_runner_RunnerJNILib_Startup+0x1620> */
/* @0x291ad8 ldr r3, [pc, #-0xf04] */
/* @0x291adc ldr r3, [r5, r3] */
/* @0x291ae0 str r0, [r3] */
/* @0x291ae4 cmp r9, #0 */
/* @0x291ae8 cmpne r8, #0 */
/* @0x291aec bne 0x291c30 <Java_com_yoyogames_runner_RunnerJNILib_Startup+0x1604> */
/* @0x291af0 ldr r3, [r4] */
/* @0x291af4 add r2, sp, #47 */
/* @0x291af8 ldr r1, [sp, #0x58] */
/* @0x291afc mov r0, r4 */
/* @0x291b00 ldr r3, [r3, #0x2a4] */
/* @0x291b04 blx r3 */
/* @0x291b08 mov r8, r0 */
/* @0x291b0c bl 0xb6640 <strdup@plt> */
/* @0x291b10 ldr r3, [pc, #-0xf38] */
/* @0x291b14 ldr r2, [sp, #0x58] */
/* @0x291b18 ldr r3, [r5, r3] */
/* @0x291b1c cmp r8, #0 */
/* @0x291b20 cmpne r2, #0 */
/* @0x291b24 str r0, [r3] */
/* @0x291b28 bne 0x291c14 <Java_com_yoyogames_runner_RunnerJNILib_Startup+0x15e8> */
/* @0x291b2c ldr r3, [r4] */
/* @0x291b30 add r2, sp, #47 */
/* @0x291b34 mov r1, r10 */
/* @0x291b38 mov r0, r4 */
/* @0x291b3c ldr r3, [r3, #0x2a4] */
/* @0x291b40 blx r3 */
/* @0x291b44 mov r8, r0 */
/* @0x291b48 bl 0xb6640 <strdup@plt> */
/* @0x291b4c ldr r3, [pc, #-0xf70] */
/* @0x291b50 cmp r8, #0 */
/* @0x291b54 cmpne r10, #0 */
/* @0x291b58 ldr r3, [r5, r3] */
/* @0x291b5c str r0, [r3] */
/* @0x291b60 bne 0x291bf8 <Java_com_yoyogames_runner_RunnerJNILib_Startup+0x15cc> */
/* @0x291b64 ldr r3, [r7] */
/* @0x291b68 mov r0, r7 */
/* @0x291b6c ldr r1, [pc, #-0xf8c] */
/* @0x291b70 ldr r8, [pc, #-0xf8c] */
/* @0x291b74 add r1, pc, r1 */
/* @0x291b78 ldr r3, [r3, #0xc] */
/* @0x291b7c blx r3 */
/* @0x291b80 mov r0, #8192 */
/* @0x291b84 bl 0xb6544 <malloc@plt> */
/* @0x291b88 ldr lr, [pc, #-0xfa0] */
/* @0x291b8c ldr r8, [r5, r8] */
/* @0x291b90 add lr, pc, lr */
/* @0x291b94 mov r9, r0 */
/* @0x291b98 mov r12, r0 */
/* @0x291b9c ldm lr!, {r0, r1, r2, r3} */
/* @0x291ba0 str r9, [r8] */
/* @0x291ba4 ldr lr, [lr] */
/* @0x291ba8 stm r12!, {r0, r1, r2, r3} */
/* @0x291bac mov r2, r9 */
/* @0x291bb0 strb lr, [r12] */
/* @0x291bb4 mov r0, r7 */
/* @0x291bb8 ldr r3, [r7] */
/* @0x291bbc ldr r1, [pc, #-0xfd0] */
/* @0x291bc0 ldr r3, [r3, #0xc] */
/* @0x291bc4 add r1, pc, r1 */
/* @0x291bc8 blx r3 */
/* @0x291bcc bl 0x27c23c <_ZN13MemoryManager4InitEv> */
/* @0x291bd0 ldr r2, [pc, #-0xfe0] */
/* @0x291bd4 ldr r3, [r7] */
/* @0x291bd8 mov r0, r7 */
/* @0x291bdc ldr r1, [pc, #-0xfe8] */
/* @0x291be0 ldr r2, [r5, r2] */
/* @0x291be4 add r1, pc, r1 */
/* @0x291be8 ldr r3, [r3, #0xc] */
/* @0x291bec ldr r2, [r2] */
/* @0x291bf0 blx r3 */
/* @0x291bf4 b 0x2906d8 <Java_com_yoyogames_runner_RunnerJNILib_Startup+0xac> */
/* @0x291bf8 ldr r3, [r4] */
/* @0x291bfc mov r1, r10 */
/* @0x291c00 mov r2, r8 */
/* @0x291c04 mov r0, r4 */
/* @0x291c08 ldr r3, [r3, #0x2a8] */
/* @0x291c0c blx r3 */
/* @0x291c10 b 0x291b64 <Java_com_yoyogames_runner_RunnerJNILib_Startup+0x1538> */
/* @0x291c14 ldr r3, [r4] */
/* @0x291c18 mov r2, r8 */
/* @0x291c1c mov r0, r4 */
/* @0x291c20 ldr r1, [sp, #0x58] */
/* @0x291c24 ldr r3, [r3, #0x2a8] */
/* @0x291c28 blx r3 */
/* @0x291c2c b 0x291b2c <Java_com_yoyogames_runner_RunnerJNILib_Startup+0x1500> */
/* @0x291c30 ldr r3, [r4] */
/* @0x291c34 mov r1, r8 */
/* @0x291c38 mov r2, r9 */
/* @0x291c3c mov r0, r4 */
/* @0x291c40 ldr r3, [r3, #0x2a8] */
/* @0x291c44 blx r3 */
/* @0x291c48 b 0x291af0 <Java_com_yoyogames_runner_RunnerJNILib_Startup+0x14c4> */
/* @0x291c4c ldr r3, [r7] */
/* @0x291c50 mov r0, r7 */
/* @0x291c54 ldr r1, [pc, #0xc] */
/* @0x291c58 ldr r3, [r3, #0xc] */
/* @0x291c5c add r1, pc, r1 */
/* @0x291c60 blx r3 */
/* @0x291c64 b 0x291ae4 <Java_com_yoyogames_runner_RunnerJNILib_Startup+0x14b8> */
/* @0x291c68 strheq r6, [r12], -r8 */

/* ── FUNC 0x291c6c · Java_com_yoyogames_runner_RunnerJNILib_TouchEvent · size=468 · insn=117 */
/* @0x291c6c push {r4, r5, r6, lr} */
/* @0x291c70 vpush {d8} */
/* @0x291c74 mov r4, r3 */
/* @0x291c78 vldr s17, [sp, #24] */
/* @0x291c7c vldr s16, [sp, #28] */
/* @0x291c80 mov r5, r2 */
/* @0x291c84 bl 0x290614 <setJNIEnv> */
/* @0x291c88 ldr r3, [pc, #0x18c] */
/* @0x291c8c ldr r2, [pc, #0x18c] */
/* @0x291c90 vldr s15, [pc, #384] */
/* @0x291c94 add r3, pc, r3 */
/* @0x291c98 vcmp.f32 s17, s15 */
/* @0x291c9c vldr s14, [pc, #372] */
/* @0x291ca0 ldr r2, [r3, r2] */
/* @0x291ca4 vmrs APSR_nzcv, fpscr */
/* @0x291ca8 vmovmi.f32 s17, s15 */
/* @0x291cac ldr r2, [r2] */
/* @0x291cb0 vmov s13, r2 */
/* @0x291cb4 vcvt.f32.s32 s15, s13 */
/* @0x291cb8 vcmpe.f32 s17, s15 */
/* @0x291cbc vmrs APSR_nzcv, fpscr */
/* @0x291cc0 subge r2, r2, #1 */
/* @0x291cc4 vcmp.f32 s16, s14 */
/* @0x291cc8 vmovge s17, r2 */
/* @0x291ccc ldr r2, [pc, #0x150] */
/* @0x291cd0 ldr r2, [r3, r2] */
/* @0x291cd4 vcvtge.f32.s32 s17, s17 */
/* @0x291cd8 vmrs APSR_nzcv, fpscr */
/* @0x291cdc ldr r2, [r2] */
/* @0x291ce0 vmov s13, r2 */
/* @0x291ce4 vmovmi.f32 s16, s14 */
/* @0x291ce8 vcvt.f32.s32 s15, s13 */
/* @0x291cec vcmpe.f32 s16, s15 */
/* @0x291cf0 vcvt.s32.f32 s17, s17 */
/* @0x291cf4 vmrs APSR_nzcv, fpscr */
/* @0x291cf8 subge r2, r2, #1 */
/* @0x291cfc vmovge s16, r2 */
/* @0x291d00 vcvtge.f32.s32 s16, s16 */
/* @0x291d04 cmp r4, #9 */
/* @0x291d08 vmov r6, s17 */
/* @0x291d0c bls 0x291d7c <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x110> */
/* @0x291d10 vcvt.s32.f32 s16, s16 */
/* @0x291d14 vmov r12, s16 */
/* @0x291d18 ldr r2, [pc, #0x108] */
/* @0x291d1c add r0, r4, r4, lsl #2 */
/* @0x291d20 lsl r0, r0, #2 */
/* @0x291d24 ldr r2, [r3, r2] */
/* @0x291d28 add r1, r0, r2 */
/* @0x291d2c stmib r1, {r6, r12} */
/* @0x291d30 str r4, [r1, #0x10] */
/* @0x291d34 cmp r5, #6 */
/* @0x291d38 addls pc, pc, r5, lsl #2 */
/* @0x291d3c b 0x291d74 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x108> */
/* @0x291d40 b 0x291dd0 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x164> */
/* @0x291d44 b 0x291d5c <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0xf0> */
/* @0x291d48 b 0x291da8 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x13c> */
/* @0x291d4c b 0x291d74 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x108> */
/* @0x291d50 b 0x291d74 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x108> */
/* @0x291d54 b 0x291dd0 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x164> */
/* @0x291d58 b 0x291d5c <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0xf0> */
/* @0x291d5c cmp r4, #9 */
/* @0x291d60 mov r1, #0 */
/* @0x291d64 str r1, [r0, r2] */
/* @0x291d68 ldrls r2, [pc, #0xbc] */
/* @0x291d6c ldrls r3, [r3, r2] */
/* @0x291d70 strls r1, [r3, r4, lsl #2] */
/* @0x291d74 vpop {d8} */
/* @0x291d78 pop {r4, r5, r6, pc} */
/* @0x291d7c cmp r4, #0 */
/* @0x291d80 beq 0x291df4 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x188> */
/* @0x291d84 vcvt.s32.f32 s16, s16 */
/* @0x291d88 vmov r12, s16 */
/* @0x291d8c ldr r1, [pc, #0x9c] */
/* @0x291d90 ldr r2, [pc, #0x9c] */
/* @0x291d94 ldr r1, [r3, r1] */
/* @0x291d98 str r6, [r1, r4, lsl #2] */
/* @0x291d9c ldr r2, [r3, r2] */
/* @0x291da0 str r12, [r2, r4, lsl #2] */
/* @0x291da4 b 0x291d18 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0xac> */
/* @0x291da8 cmp r4, #9 */
/* @0x291dac mov r1, #-2147483646 */
/* @0x291db0 str r1, [r0, r2] */
/* @0x291db4 bhi 0x291d74 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x108> */
/* @0x291db8 ldr r1, [pc, #0x6c] */
/* @0x291dbc mov r2, #1 */
/* @0x291dc0 ldr r3, [r3, r1] */
/* @0x291dc4 str r2, [r3, r4, lsl #2] */
/* @0x291dc8 vpop {d8} */
/* @0x291dcc pop {r4, r5, r6, pc} */
/* @0x291dd0 cmp r4, #9 */
/* @0x291dd4 mov r1, #-2147483645 */
/* @0x291dd8 str r1, [r0, r2] */
/* @0x291ddc bhi 0x291d74 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x108> */
/* @0x291de0 ldr r1, [pc, #0x44] */
/* @0x291de4 mov r2, #1 */
/* @0x291de8 ldr r3, [r3, r1] */
/* @0x291dec str r2, [r3, r4, lsl #2] */
/* @0x291df0 b 0x291dc8 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x15c> */
/* @0x291df4 vcvt.s32.f32 s16, s16 */
/* @0x291df8 ldr r2, [pc, #0x38] */
/* @0x291dfc ldr r1, [pc, #0x38] */
/* @0x291e00 ldr r0, [r3, r2] */
/* @0x291e04 vstr s17, [r0] */
/* @0x291e08 ldr r1, [r3, r1] */
/* @0x291e0c vmov r12, s16 */
/* @0x291e10 vstr s16, [r1] */
/* @0x291e14 b 0x291d8c <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x120> */
/* @0x291e18 andeq r0, r0, r0 */
/* @0x291e1c ldrheq pc, [r5], -r12 */
/* @0x291e20 .word 0xffffe24c */
/* @0x291e24 .word 0xffffe250 */
/* @0x291e28 .word 0xfffffcf4 */
/* @0x291e2c .word 0xffffe9dc */
/* @0x291e30 .word 0xffffdf4c */
/* @0x291e34 .word 0xffffdf48 */
/* @0x291e38 .word 0xffffe720 */
/* @0x291e3c .word 0xffffe724 */

/* ── FUNC 0x291e40 · Java_com_yoyogames_runner_RunnerJNILib_RenderSplash · size=1864 · insn=466 */
/* @0x291e40 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x291e44 vpush {d8} */
/* @0x291e48 sub sp, sp, #576 */
/* @0x291e4c ldr r4, [pc, #0x34c] */
/* @0x291e50 mov r5, r0 */
/* @0x291e54 ldr r3, [pc, #0x348] */
/* @0x291e58 add r4, pc, r4 */
/* @0x291e5c ldr r6, [r4, r3] */
/* @0x291e60 ldr r3, [r6] */
/* @0x291e64 str r3, [sp, #0x23c] */
/* @0x291e68 bl 0x28fce4 <_Z15ImportGLLibraryv> */
/* @0x291e6c mov r0, r5 */
/* @0x291e70 bl 0x290614 <setJNIEnv> */
/* @0x291e74 ldr r3, [pc, #0x32c] */
/* @0x291e78 ldr r7, [r4, r3] */
/* @0x291e7c ldr r5, [r7] */
/* @0x291e80 cmp r5, #1 */
/* @0x291e84 beq 0x29212c <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x2ec> */
/* @0x291e88 cmp r5, #0 */
/* @0x291e8c beq 0x291eac <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x6c> */
/* @0x291e90 ldr r2, [sp, #0x23c] */
/* @0x291e94 ldr r3, [r6] */
/* @0x291e98 cmp r2, r3 */
/* @0x291e9c bne 0x292584 <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x744> */
/* @0x291ea0 add sp, sp, #576 */
/* @0x291ea4 vpop {d8} */
/* @0x291ea8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x291eac ldr r2, [pc, #0x368] */
/* @0x291eb0 mov r0, #1065353216 */
/* @0x291eb4 ldr r7, [sp, #0x268] */
/* @0x291eb8 ldr r3, [pc, #0x360] */
/* @0x291ebc ldr r1, [r4, r2] */
/* @0x291ec0 mov r2, #0 */
/* @0x291ec4 ldr r10, [sp, #0x26c] */
/* @0x291ec8 ldr r12, [pc, #0x2dc] */
/* @0x291ecc str r7, [r1] */
/* @0x291ed0 mov r1, r0 */
/* @0x291ed4 ldr lr, [r4, r3] */
/* @0x291ed8 mov r3, r0 */
/* @0x291edc str r10, [lr] */
/* @0x291ee0 ldr r12, [r4, r12] */
/* @0x291ee4 ldr r12, [r12] */
/* @0x291ee8 blx r12 */
/* @0x291eec ldr r3, [pc, #0x2bc] */
/* @0x291ef0 mov r0, #16384 */
/* @0x291ef4 ldr r3, [r4, r3] */
/* @0x291ef8 ldr r3, [r3] */
/* @0x291efc blx r3 */
/* @0x291f00 rsb r2, r10, #0 */
/* @0x291f04 vldr s8, [sp, #616] */
/* @0x291f08 vcvt.f32.s32 s16, s8 */
/* @0x291f0c vmov s11, r2 */
/* @0x291f10 ldr r1, [pc, #0x29c] */
/* @0x291f14 mov r3, #1065353216 */
/* @0x291f18 mov r0, #0 */
/* @0x291f1c movt r0, #0x46fa */
/* @0x291f20 ldr r9, [r4, r1] */
/* @0x291f24 str r0, [sp] */
/* @0x291f28 vcvt.f32.s32 s11, s11 */
/* @0x291f2c mov r0, r9 */
/* @0x291f30 vmov r1, s16 */
/* @0x291f34 vmov r2, s11 */
/* @0x291f38 bl 0x27b274 <_ZN8yyMatrix7OrthoLHEPS_ffff> */
/* @0x291f3c ldr r3, [pc, #0x274] */
/* @0x291f40 movw r0, #0x1701 */
/* @0x291f44 ldr r8, [r4, r3] */
/* @0x291f48 ldr r3, [r8] */
/* @0x291f4c blx r3 */
/* @0x291f50 ldr r3, [pc, #0x264] */
/* @0x291f54 ldr r7, [r4, r3] */
/* @0x291f58 ldr r3, [r7] */
/* @0x291f5c blx r3 */
/* @0x291f60 ldr r3, [pc, #0x258] */
/* @0x291f64 mov r0, r9 */
/* @0x291f68 ldr r9, [pc, #0x254] */
/* @0x291f6c ldr r3, [r4, r3] */
/* @0x291f70 ldr r3, [r3] */
/* @0x291f74 blx r3 */
/* @0x291f78 ldr r3, [r8] */
/* @0x291f7c mov r0, #5888 */
/* @0x291f80 blx r3 */
/* @0x291f84 ldr r3, [r7] */
/* @0x291f88 blx r3 */
/* @0x291f8c vmov.f32 s14, #1.000000e+00 */
/* @0x291f90 vldr s12, [sp, #624] */
/* @0x291f94 vldr s13, [sp, #628] */
/* @0x291f98 vldr s8, [sp, #632] */
/* @0x291f9c vldr s15, [pc, #504] */
/* @0x291fa0 mvn r12, #0 */
/* @0x291fa4 str r5, [sp, #0x14] */
/* @0x291fa8 str r5, [sp, #0x18] */
/* @0x291fac movw r1, #0x140c */
/* @0x291fb0 str r5, [sp, #0x2c] */
/* @0x291fb4 mov r2, #20 */
/* @0x291fb8 str r5, [sp, #0x3c] */
/* @0x291fbc add r3, sp, #12 */
/* @0x291fc0 str r12, [sp, #0x1c] */
/* @0x291fc4 mov r0, #2 */
/* @0x291fc8 str r12, [sp, #0x30] */
/* @0x291fcc str r12, [sp, #0x44] */
/* @0x291fd0 vcvt.f32.s32 s10, s12 */
/* @0x291fd4 str r12, [sp, #0x58] */
/* @0x291fd8 vcvt.f32.s32 s11, s13 */
/* @0x291fdc vldr s13, [sp, #636] */
/* @0x291fe0 vdiv.f32 s10, s14, s10 */
/* @0x291fe4 vdiv.f32 s11, s14, s11 */
/* @0x291fe8 vmov.f32 s14, #5.000000e-01 */
/* @0x291fec vcvt.f32.s32 s9, s8 */
/* @0x291ff0 vldr s8, [sp, #620] */
/* @0x291ff4 vcvt.f32.s32 s12, s13 */
/* @0x291ff8 vcvt.f32.s32 s13, s8 */
/* @0x291ffc vmul.f32 s10, s9, s10 */
/* @0x292000 vmul.f32 s16, s16, s14 */
/* @0x292004 vmul.f32 s11, s12, s11 */
/* @0x292008 vmul.f32 s14, s13, s14 */
/* @0x29200c vnmul.f32 s12, s16, s15 */
/* @0x292010 vnmul.f32 s13, s14, s15 */
/* @0x292014 vmul.f32 s10, s10, s15 */
/* @0x292018 vmul.f32 s11, s11, s15 */
/* @0x29201c vmul.f32 s16, s16, s15 */
/* @0x292020 vmul.f32 s15, s14, s15 */
/* @0x292024 vcvt.s32.f32 s10, s10 */
/* @0x292028 vcvt.s32.f32 s11, s11 */
/* @0x29202c vstr s10, [sp, #40] */
/* @0x292030 vstr s10, [sp, #80] */
/* @0x292034 vcvt.s32.f32 s12, s12 */
/* @0x292038 vstr s11, [sp, #64] */
/* @0x29203c vstr s11, [sp, #84] */
/* @0x292040 vcvt.s32.f32 s13, s13 */
/* @0x292044 vstr s12, [sp, #12] */
/* @0x292048 vstr s12, [sp, #52] */
/* @0x29204c vcvt.s32.f32 s15, s15 */
/* @0x292050 vstr s13, [sp, #16] */
/* @0x292054 vstr s13, [sp, #36] */
/* @0x292058 vcvt.s32.f32 s16, s16 */
/* @0x29205c vstr s15, [sp, #56] */
/* @0x292060 vstr s15, [sp, #76] */
/* @0x292064 vstr s16, [sp, #32] */
/* @0x292068 vstr s16, [sp, #72] */
/* @0x29206c ldr r12, [r4, r9] */
/* @0x292070 ldr r12, [r12] */
/* @0x292074 blx r12 */
/* @0x292078 ldr r3, [pc, #0x148] */
/* @0x29207c movw r0, #0x8074 */
/* @0x292080 ldr r9, [r4, r3] */
/* @0x292084 ldr r3, [r9] */
/* @0x292088 blx r3 */
/* @0x29208c ldr r12, [pc, #0x138] */
/* @0x292090 mov r2, #20 */
/* @0x292094 movw r1, #0x140c */
/* @0x292098 add r3, sp, r2 */
/* @0x29209c mov r0, #2 */
/* @0x2920a0 ldr r12, [r4, r12] */
/* @0x2920a4 ldr r12, [r12] */
/* @0x2920a8 blx r12 */
/* @0x2920ac ldr r3, [r9] */
/* @0x2920b0 movw r0, #0x8078 */
/* @0x2920b4 blx r3 */
/* @0x2920b8 ldr r12, [pc, #0x110] */
/* @0x2920bc movw r1, #0x1401 */
/* @0x2920c0 mov r2, #20 */
/* @0x2920c4 add r3, sp, #28 */
/* @0x2920c8 mov r0, #4 */
/* @0x2920cc ldr r12, [r4, r12] */
/* @0x2920d0 ldr r12, [r12] */
/* @0x2920d4 blx r12 */
/* @0x2920d8 ldr r3, [r9] */
/* @0x2920dc movw r0, #0x8076 */
/* @0x2920e0 blx r3 */
/* @0x2920e4 ldr r3, [r8] */
/* @0x2920e8 movw r0, #0x1702 */
/* @0x2920ec blx r3 */
/* @0x2920f0 ldr r3, [r7] */
/* @0x2920f4 blx r3 */
/* @0x2920f8 ldr r3, [pc, #0xd4] */
/* @0x2920fc movw r0, #0xde1 */
/* @0x292100 ldr r3, [r4, r3] */
/* @0x292104 ldr r3, [r3] */
/* @0x292108 blx r3 */
/* @0x29210c ldr r3, [pc, #0x120] */
/* @0x292110 mov r1, r5 */
/* @0x292114 mov r0, #5 */
/* @0x292118 mov r2, #4 */
/* @0x29211c ldr r3, [r4, r3] */
/* @0x292120 ldr r3, [r3] */
/* @0x292124 blx r3 */
/* @0x292128 b 0x291e90 <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x50> */
/* @0x29212c add r5, sp, #316 */
/* @0x292130 ldr r1, [pc, #0xa0] */
/* @0x292134 mov r2, #254 */
/* @0x292138 add r8, sp, #92 */
/* @0x29213c add r1, pc, r1 */
/* @0x292140 mov r0, r5 */
/* @0x292144 bl 0xb65bc <memcpy@plt> */
/* @0x292148 ldr r1, [pc, #0x8c] */
/* @0x29214c mov r2, #224 */
/* @0x292150 mov r0, r8 */
/* @0x292154 add r1, pc, r1 */
/* @0x292158 bl 0xb65bc <memcpy@plt> */
/* @0x29215c ldr r3, [pc, #0x7c] */
/* @0x292160 add r3, pc, r3 */
/* @0x292164 ldr r2, [r3] */
/* @0x292168 cmp r2, #0 */
/* @0x29216c beq 0x29224c <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x40c> */
/* @0x292170 ldr r2, [r3, #0x4] */
/* @0x292174 cmp r2, #0 */
/* @0x292178 beq 0x29224c <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x40c> */
/* @0x29217c ldr r0, [r3, #0x8] */
/* @0x292180 cmp r0, #0 */
/* @0x292184 beq 0x29224c <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x40c> */
/* @0x292188 ldr r3, [r3, #0xc] */
/* @0x29218c cmp r3, #0 */
/* @0x292190 beq 0x29224c <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x40c> */
/* @0x292194 mov r2, r0 */
/* @0x292198 b 0x29235c <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x51c> */
/* @0x29219c strmi r0, [r0, r0] */
/* @0x2921a0 ldrsheq pc, [r5], -r8 */
/* @0x2921a4 .word 0xffffbd00 */
/* @0x2921a8 .word 0xffffe7b8 */
/* @0x2921ac .word 0xffffbb00 */
/* @0x2921b0 .word 0xffffbacc */
/* @0x2921b4 .word 0xfffffd14 */
/* @0x2921b8 .word 0xffffbc48 */
/* @0x2921bc .word 0xffffbc3c */
/* @0x2921c0 .word 0xffffbcac */
/* @0x2921c4 .word 0xffffbc6c */
/* @0x2921c8 .word 0xffffbc30 */
/* @0x2921cc .word 0xffffbca8 */
/* @0x2921d0 .word 0xffffbc28 */
/* @0x2921d4 .word 0xffffbad8 */
/* @0x2921d8 andeq r6, r12, r4, lsr r12 */
/* @0x2921dc andeq r6, r12, r12, lsl sp */
/* @0x2921e0 subeq r4, r12, r8, ror #20 */
/* @0x2921e4 subeq r4, r12, r4, ror #18 */
/* @0x2921e8 .word 0xffffbba8 */
/* @0x2921ec .word 0xffffbbac */
/* @0x2921f0 .word 0xffffbbb0 */
/* @0x2921f4 .word 0xffffbbb4 */
/* @0x2921f8 .word 0xffffbbbc */
/* @0x2921fc andeq r6, r12, r0, asr #20 */
/* @0x292200 andseq r5, r6, r12, ror r4 */
/* @0x292204 andeq r6, r12, r0, lsr r10 */
/* @0x292208 .word 0xffffbbc0 */
/* @0x29220c andeq r6, r12, r4, lsr #20 */
/* @0x292210 .word 0xffffbb80 */
/* @0x292214 .word 0xffffbadc */
/* @0x292218 subeq r4, r12, r12, lsr r8 */
/* @0x29221c .word 0xffffe24c */
/* @0x292220 .word 0xffffe250 */
/* @0x292224 .word 0xffffbb90 */
/* @0x292228 ldrheq r5, [r6], -r12 */
/* @0x29222c .word 0xffffbb88 */
/* @0x292230 .word 0xffffbb84 */
/* @0x292234 .word 0xffffbad4 */
/* @0x292238 .word 0xffffbbb8 */
/* @0x29223c .word 0xffffbac4 */
/* @0x292240 andeq r9, r11, r4, asr #20 */
/* @0x292244 .word 0xffffbb78 */
/* @0x292248 subeq r4, r12, r8, asr r6 */
/* @0x29224c mov r1, r5 */
/* @0x292250 mov r2, #0 */
/* @0x292254 movw r0, #0x8b31 */
/* @0x292258 ldr r5, [pc, #-0x7c] */
/* @0x29225c bl 0x1865bc <_Z10LoadShaderjPKcPPc> */
/* @0x292260 mov r1, r8 */
/* @0x292264 add r5, pc, r5 */
/* @0x292268 mov r2, #0 */
/* @0x29226c str r0, [r5] */
/* @0x292270 movw r0, #0x8b30 */
/* @0x292274 bl 0x1865bc <_Z10LoadShaderjPKcPPc> */
/* @0x292278 ldr r3, [pc, #-0x98] */
/* @0x29227c str r0, [r5, #0x4] */
/* @0x292280 ldr r3, [r4, r3] */
/* @0x292284 ldr r3, [r3] */
/* @0x292288 blx r3 */
/* @0x29228c cmp r0, #0 */
/* @0x292290 str r0, [r5, #0x8] */
/* @0x292294 beq 0x291e90 <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x50> */
/* @0x292298 ldr r3, [pc, #-0xb4] */
/* @0x29229c ldr r1, [r5] */
/* @0x2922a0 ldr r8, [r4, r3] */
/* @0x2922a4 ldr r3, [r8] */
/* @0x2922a8 blx r3 */
/* @0x2922ac ldr r3, [r8] */
/* @0x2922b0 ldr r1, [r5, #0x4] */
/* @0x2922b4 ldr r0, [r5, #0x8] */
/* @0x2922b8 blx r3 */
/* @0x2922bc ldr r3, [pc, #-0xd4] */
/* @0x2922c0 ldr r0, [r5, #0x8] */
/* @0x2922c4 ldr r3, [r4, r3] */
/* @0x2922c8 ldr r3, [r3] */
/* @0x2922cc blx r3 */
/* @0x2922d0 ldr r3, [pc, #-0xe4] */
/* @0x2922d4 ldr r0, [r5, #0x8] */
/* @0x2922d8 movw r1, #0x8b82 */
/* @0x2922dc add r2, r5, #12 */
/* @0x2922e0 ldr r9, [r4, r3] */
/* @0x2922e4 ldr r3, [r9] */
/* @0x2922e8 blx r3 */
/* @0x2922ec ldr r8, [r5, #0xc] */
/* @0x2922f0 cmp r8, #0 */
/* @0x2922f4 beq 0x2924ec <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x6ac> */
/* @0x2922f8 ldr r3, [pc, #-0x108] */
/* @0x2922fc ldr r1, [pc, #-0x108] */
/* @0x292300 ldr r0, [r5, #0x8] */
/* @0x292304 ldr r9, [r4, r3] */
/* @0x292308 add r1, pc, r1 */
/* @0x29230c ldr r8, [pc, #-0x114] */
/* @0x292310 ldr r3, [r9] */
/* @0x292314 add r8, pc, r8 */
/* @0x292318 blx r3 */
/* @0x29231c ldr r1, [pc, #-0x120] */
/* @0x292320 ldr r3, [r9] */
/* @0x292324 add r1, pc, r1 */
/* @0x292328 str r0, [r8] */
/* @0x29232c ldr r0, [r5, #0x8] */
/* @0x292330 blx r3 */
/* @0x292334 ldr r3, [pc, #-0x134] */
/* @0x292338 ldr r1, [pc, #-0x134] */
/* @0x29233c add r1, pc, r1 */
/* @0x292340 str r0, [r8, #0x4] */
/* @0x292344 ldr r3, [r4, r3] */
/* @0x292348 ldr r0, [r5, #0x8] */
/* @0x29234c ldr r3, [r3] */
/* @0x292350 blx r3 */
/* @0x292354 ldr r2, [r5, #0x8] */
/* @0x292358 str r0, [r8, #0x8] */
/* @0x29235c ldr r3, [pc, #-0x154] */
/* @0x292360 mov r0, r2 */
/* @0x292364 ldr r3, [r4, r3] */
/* @0x292368 ldr r3, [r3] */
/* @0x29236c blx r3 */
/* @0x292370 ldr r3, [pc, #-0x164] */
/* @0x292374 ldr r3, [r4, r3] */
/* @0x292378 ldr r3, [r3] */
/* @0x29237c blx r3 */
/* @0x292380 cmp r0, #0 */
/* @0x292384 ldrne r3, [pc, #-0x174] */
/* @0x292388 movne r2, #0 */
/* @0x29238c addne r3, pc, r3 */
/* @0x292390 strne r2, [r3, #0x8] */
/* @0x292394 vmov.f32 s15, #1.000000e+00 */
/* @0x292398 vldr s8, [sp, #624] */
/* @0x29239c ldr r3, [pc, #-0x188] */
/* @0x2923a0 vldr s11, [sp, #632] */
/* @0x2923a4 ldr r10, [sp, #0x268] */
/* @0x2923a8 mov r12, #0 */
/* @0x2923ac ldr r0, [pc, #-0x194] */
/* @0x2923b0 mov r8, #16 */
/* @0x2923b4 ldr r9, [r4, r3] */
/* @0x2923b8 mov r1, #2 */
/* @0x2923bc ldr lr, [pc, #-0x1a0] */
/* @0x2923c0 movw r2, #0x1406 */
/* @0x2923c4 ldr r5, [pc, #-0x1a4] */
/* @0x2923c8 mov r3, #0 */
/* @0x2923cc str r10, [r9] */
/* @0x2923d0 ldr r9, [r4, r0] */
/* @0x2923d4 add r5, pc, r5 */
/* @0x2923d8 ldr r10, [sp, #0x26c] */
/* @0x2923dc vcvt.f32.s32 s14, s8 */
/* @0x2923e0 vldr s8, [sp, #628] */
/* @0x2923e4 vstr s15, [sp, #16] */
/* @0x2923e8 vstr s15, [sp, #28] */
/* @0x2923ec vstr s15, [sp, #32] */
/* @0x2923f0 vstr s15, [sp, #60] */
/* @0x2923f4 str r10, [r9] */
/* @0x2923f8 str r12, [sp, #0x14] */
/* @0x2923fc str r12, [sp, #0x18] */
/* @0x292400 str r12, [sp, #0x28] */
/* @0x292404 vcvt.f32.s32 s13, s8 */
/* @0x292408 vldr s8, [sp, #636] */
/* @0x29240c str r12, [sp, #0x34] */
/* @0x292410 mov r12, #0 */
/* @0x292414 movt r12, #0xbf80 */
/* @0x292418 str r12, [sp, #0xc] */
/* @0x29241c str r12, [sp, #0x2c] */
/* @0x292420 str r12, [sp, #0x30] */
/* @0x292424 str r12, [sp, #0x40] */
/* @0x292428 add r12, sp, #12 */
/* @0x29242c ldr r0, [r5] */
/* @0x292430 vdiv.f32 s14, s15, s14 */
/* @0x292434 vdiv.f32 s15, s15, s13 */
/* @0x292438 vcvt.f32.s32 s12, s11 */
/* @0x29243c vcvt.f32.s32 s13, s8 */
/* @0x292440 vmul.f32 s14, s12, s14 */
/* @0x292444 vmul.f32 s15, s13, s15 */
/* @0x292448 vstr s14, [sp, #36] */
/* @0x29244c vstr s14, [sp, #68] */
/* @0x292450 vstr s15, [sp, #56] */
/* @0x292454 vstr s15, [sp, #72] */
/* @0x292458 ldr r9, [r4, lr] */
/* @0x29245c str r8, [sp] */
/* @0x292460 str r12, [sp, #0x4] */
/* @0x292464 ldr r12, [r9] */
/* @0x292468 blx r12 */
/* @0x29246c ldr r12, [r9] */
/* @0x292470 ldr r0, [r5, #0x4] */
/* @0x292474 movw r2, #0x1406 */
/* @0x292478 mov r1, #2 */
/* @0x29247c str r8, [sp] */
/* @0x292480 add r3, sp, #20 */
/* @0x292484 str r3, [sp, #0x4] */
/* @0x292488 mov r3, #0 */
/* @0x29248c blx r12 */
/* @0x292490 ldr r3, [pc, #-0x26c] */
/* @0x292494 ldr r0, [r5] */
/* @0x292498 ldr r8, [r4, r3] */
/* @0x29249c ldr r3, [r8] */
/* @0x2924a0 blx r3 */
/* @0x2924a4 ldr r0, [r5, #0x4] */
/* @0x2924a8 ldr r3, [r8] */
/* @0x2924ac blx r3 */
/* @0x2924b0 ldr r3, [pc, #-0x288] */
/* @0x2924b4 ldr r0, [r5, #0x8] */
/* @0x2924b8 mov r1, #0 */
/* @0x2924bc ldr r3, [r4, r3] */
/* @0x2924c0 ldr r3, [r3] */
/* @0x2924c4 blx r3 */
/* @0x2924c8 ldr r3, [pc, #-0x29c] */
/* @0x2924cc mov r0, #5 */
/* @0x2924d0 mov r1, #0 */
/* @0x2924d4 mov r2, #4 */
/* @0x2924d8 ldr r3, [r4, r3] */
/* @0x2924dc ldr r3, [r3] */
/* @0x2924e0 blx r3 */
/* @0x2924e4 ldr r5, [r7] */
/* @0x2924e8 b 0x291e88 <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x48> */
/* @0x2924ec add r2, sp, #576 */
/* @0x2924f0 ldr r0, [r5, #0x8] */
/* @0x2924f4 ldr r3, [r9] */
/* @0x2924f8 movw r1, #0x8b84 */
/* @0x2924fc str r8, [r2, #-0x234]! */
/* @0x292500 blx r3 */
/* @0x292504 ldr r0, [sp, #0xc] */
/* @0x292508 cmp r0, #1 */
/* @0x29250c ble 0x292564 <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x724> */
/* @0x292510 bl 0xb6544 <malloc@plt> */
/* @0x292514 ldr r12, [pc, #-0x2e4] */
/* @0x292518 mov r2, r8 */
/* @0x29251c ldr r1, [sp, #0xc] */
/* @0x292520 ldr r12, [r4, r12] */
/* @0x292524 ldr r12, [r12] */
/* @0x292528 mov r7, r0 */
/* @0x29252c ldr r0, [r5, #0x8] */
/* @0x292530 mov r3, r7 */
/* @0x292534 blx r12 */
/* @0x292538 ldr r3, [pc, #-0x304] */
/* @0x29253c ldr r1, [pc, #-0x304] */
/* @0x292540 mov r2, r7 */
/* @0x292544 ldr r3, [r4, r3] */
/* @0x292548 add r1, pc, r1 */
/* @0x29254c ldr r0, [r3] */
/* @0x292550 ldr r3, [r0] */
/* @0x292554 ldr r3, [r3, #0xc] */
/* @0x292558 blx r3 */
/* @0x29255c mov r0, r7 */
/* @0x292560 bl 0xb655c <free@plt> */
/* @0x292564 ldr r3, [pc, #-0x328] */
/* @0x292568 ldr r2, [pc, #-0x328] */
/* @0x29256c ldr r3, [r4, r3] */
/* @0x292570 add r2, pc, r2 */
/* @0x292574 ldr r0, [r2, #0x8] */
/* @0x292578 ldr r3, [r3] */
/* @0x29257c blx r3 */
/* @0x292580 b 0x291e90 <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x50> */
/* @0x292584 bl 0xb65d4 <__stack_chk_fail@plt> */

/* ── FUNC 0x292588 · Java_com_yoyogames_runner_RunnerJNILib_Resume · size=76 · insn=19 */
/* @0x292588 push {r3, lr} */
/* @0x29258c bl 0x290614 <setJNIEnv> */
/* @0x292590 bl 0xb6d54 <alcResumeCurrentDevice@plt> */
/* @0x292594 ldr r3, [pc, #0x2c] */
/* @0x292598 ldr r1, [pc, #0x2c] */
/* @0x29259c ldr r3, [pc, r3] */
/* @0x2925a0 add r1, pc, r1 */
/* @0x2925a4 ldr r0, [r3] */
/* @0x2925a8 ldr r3, [r0] */
/* @0x2925ac ldr r3, [r3, #0xc] */
/* @0x2925b0 blx r3 */
/* @0x2925b4 ldr r3, [pc, #0x14] */
/* @0x2925b8 mov r2, #1 */
/* @0x2925bc ldr r3, [pc, r3] */
/* @0x2925c0 strb r2, [r3] */
/* @0x2925c4 pop {r3, pc} */
/* @0x2925c8 andseq r11, r5, r8, ror r1 */
/* @0x2925cc strheq r6, [r12], -r0 */
/* @0x2925d0 andseq pc, r5, r0, lsl #7 */

/* ── FUNC 0x2925d4 · Java_com_yoyogames_runner_RunnerJNILib_Pause · size=64 · insn=16 */
/* @0x2925d4 push {r3, lr} */
/* @0x2925d8 bl 0x290614 <setJNIEnv> */
/* @0x2925dc ldr r3, [pc, #0x28] */
/* @0x2925e0 ldr r1, [pc, #0x28] */
/* @0x2925e4 ldr r3, [pc, r3] */
/* @0x2925e8 add r1, pc, r1 */
/* @0x2925ec ldr r0, [r3] */
/* @0x2925f0 ldr r3, [r0] */
/* @0x2925f4 ldr r3, [r3, #0xc] */
/* @0x2925f8 blx r3 */
/* @0x2925fc bl 0xb6d60 <alcPauseCurrentDevice@plt> */
/* @0x292600 bl 0x18e8ec <_Z17ForgetAllGamePadsv> */
/* @0x292604 pop {r3, lr} */
/* @0x292608 b 0x159d44 <RaiseOSPauseEvent> */
/* @0x29260c andseq r11, r5, r0, lsr r1 */
/* @0x292610 andeq r6, r12, r4, ror r9 */

/* ── FUNC 0x292614 · Java_com_yoyogames_runner_RunnerJNILib_GetAppID · size=44 · insn=11 */
/* @0x292614 push {r4, lr} */
/* @0x292618 mov r4, r0 */
/* @0x29261c bl 0x290614 <setJNIEnv> */
/* @0x292620 ldr r3, [r4] */
/* @0x292624 mov r0, r4 */
/* @0x292628 ldr r1, [pc, #0xc] */
/* @0x29262c ldr r3, [r3, #0x29c] */
/* @0x292630 add r1, pc, r1 */
/* @0x292634 blx r3 */
/* @0x292638 pop {r4, pc} */
/* @0x29263c andeq r6, r12, r8, lsr r9 */

/* ── FUNC 0x292640 · Java_com_yoyogames_runner_RunnerJNILib_KeyEvent · size=32 · insn=8 */
/* @0x292640 push {r3, r4, r5, lr} */
/* @0x292644 mov r4, r2 */
/* @0x292648 mov r5, r3 */
/* @0x29264c bl 0x290614 <setJNIEnv> */
/* @0x292650 mov r0, r4 */
/* @0x292654 mov r1, r5 */
/* @0x292658 pop {r3, r4, r5, lr} */
/* @0x29265c b 0x18ef50 <_Z23RegisterAndroidKeyEventii> */

/* ── FUNC 0x292660 · Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue · size=776 · insn=194 */
/* @0x292660 push {r4, r5, r6, r7, r8, lr} */
/* @0x292664 mov r5, r2 */
/* @0x292668 ldr r4, [pc, #0x2b4] */
/* @0x29266c mov r8, r3 */
/* @0x292670 mov r6, r0 */
/* @0x292674 ldr r7, [sp, #0x18] */
/* @0x292678 add r4, pc, r4 */
/* @0x29267c bl 0x290614 <setJNIEnv> */
/* @0x292680 cmp r5, #8 */
/* @0x292684 addls pc, pc, r5, lsl #2 */
/* @0x292688 b 0x292728 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0xc8> */
/* @0x29268c b 0x29272c <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0xcc> */
/* @0x292690 b 0x292768 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0x108> */
/* @0x292694 b 0x2927cc <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0x16c> */
/* @0x292698 b 0x292830 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0x1d0> */
/* @0x29269c b 0x29286c <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0x20c> */
/* @0x2926a0 b 0x2928a8 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0x248> */
/* @0x2926a4 b 0x292728 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0xc8> */
/* @0x2926a8 b 0x292728 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0xc8> */
/* @0x2926ac b 0x2926b0 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0x50> */
/* @0x2926b0 ldr r3, [r6] */
/* @0x2926b4 mov r1, r7 */
/* @0x2926b8 mov r2, #0 */
/* @0x2926bc mov r0, r6 */
/* @0x2926c0 ldr r3, [r3, #0x2a4] */
/* @0x2926c4 blx r3 */
/* @0x2926c8 ldr r3, [pc, #0x258] */
/* @0x2926cc ldr r1, [pc, #0x258] */
/* @0x2926d0 ldr r3, [r4, r3] */
/* @0x2926d4 add r1, pc, r1 */
/* @0x2926d8 mov r5, r0 */
/* @0x2926dc mov r2, r0 */
/* @0x2926e0 ldr r0, [r3] */
/* @0x2926e4 ldr r3, [r0] */
/* @0x2926e8 ldr r3, [r3, #0xc] */
/* @0x2926ec blx r3 */
/* @0x2926f0 mov r0, r5 */
/* @0x2926f4 bl 0xb6640 <strdup@plt> */
/* @0x2926f8 ldr r3, [pc, #0x230] */
/* @0x2926fc cmp r5, #0 */
/* @0x292700 cmpne r7, #0 */
/* @0x292704 ldr r3, [r4, r3] */
/* @0x292708 str r0, [r3] */
/* @0x29270c popeq {r4, r5, r6, r7, r8, pc} */
/* @0x292710 ldr r3, [r6] */
/* @0x292714 mov r1, r7 */
/* @0x292718 mov r2, r5 */
/* @0x29271c mov r0, r6 */
/* @0x292720 ldr r3, [r3, #0x2a8] */
/* @0x292724 blx r3 */
/* @0x292728 pop {r4, r5, r6, r7, r8, pc} */
/* @0x29272c ldr r3, [pc, #0x1f4] */
/* @0x292730 mov r2, r8 */
/* @0x292734 ldr r1, [pc, #0x1f8] */
/* @0x292738 ldr r3, [r4, r3] */
/* @0x29273c add r1, pc, r1 */
/* @0x292740 ldr r0, [r3] */
/* @0x292744 ldr r3, [r0] */
/* @0x292748 ldr r3, [r3, #0xc] */
/* @0x29274c blx r3 */
/* @0x292750 ldr r3, [pc, #0x1e0] */
/* @0x292754 adds r8, r8, #0 */
/* @0x292758 ldr r3, [r4, r3] */
/* @0x29275c movne r8, #1 */
/* @0x292760 strb r8, [r3] */
/* @0x292764 pop {r4, r5, r6, r7, r8, pc} */
/* @0x292768 ldr r3, [r6] */
/* @0x29276c mov r1, r7 */
/* @0x292770 mov r2, #0 */
/* @0x292774 mov r0, r6 */
/* @0x292778 ldr r3, [r3, #0x2a4] */
/* @0x29277c blx r3 */
/* @0x292780 ldr r3, [pc, #0x1a0] */
/* @0x292784 ldr r1, [pc, #0x1b0] */
/* @0x292788 ldr r3, [r4, r3] */
/* @0x29278c add r1, pc, r1 */
/* @0x292790 mov r5, r0 */
/* @0x292794 mov r2, r0 */
/* @0x292798 ldr r0, [r3] */
/* @0x29279c ldr r3, [r0] */
/* @0x2927a0 ldr r3, [r3, #0xc] */
/* @0x2927a4 blx r3 */
/* @0x2927a8 mov r0, r5 */
/* @0x2927ac bl 0xb6640 <strdup@plt> */
/* @0x2927b0 ldr r3, [pc, #0x188] */
/* @0x2927b4 cmp r5, #0 */
/* @0x2927b8 cmpne r7, #0 */
/* @0x2927bc ldr r3, [r4, r3] */
/* @0x2927c0 str r0, [r3] */
/* @0x2927c4 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x2927c8 b 0x292710 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0xb0> */
/* @0x2927cc ldr r3, [r6] */
/* @0x2927d0 mov r1, r7 */
/* @0x2927d4 mov r2, #0 */
/* @0x2927d8 mov r0, r6 */
/* @0x2927dc ldr r3, [r3, #0x2a4] */
/* @0x2927e0 blx r3 */
/* @0x2927e4 ldr r3, [pc, #0x13c] */
/* @0x2927e8 ldr r1, [pc, #0x154] */
/* @0x2927ec ldr r3, [r4, r3] */
/* @0x2927f0 add r1, pc, r1 */
/* @0x2927f4 mov r5, r0 */
/* @0x2927f8 mov r2, r0 */
/* @0x2927fc ldr r0, [r3] */
/* @0x292800 ldr r3, [r0] */
/* @0x292804 ldr r3, [r3, #0xc] */
/* @0x292808 blx r3 */
/* @0x29280c mov r0, r5 */
/* @0x292810 bl 0xb6640 <strdup@plt> */
/* @0x292814 ldr r3, [pc, #0x12c] */
/* @0x292818 cmp r5, #0 */
/* @0x29281c cmpne r7, #0 */
/* @0x292820 ldr r3, [r4, r3] */
/* @0x292824 str r0, [r3] */
/* @0x292828 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x29282c b 0x292710 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0xb0> */
/* @0x292830 ldr r3, [pc, #0xf0] */
/* @0x292834 mov r2, r8 */
/* @0x292838 ldr r1, [pc, #0x10c] */
/* @0x29283c ldr r3, [r4, r3] */
/* @0x292840 add r1, pc, r1 */
/* @0x292844 ldr r0, [r3] */
/* @0x292848 ldr r3, [r0] */
/* @0x29284c ldr r3, [r3, #0xc] */
/* @0x292850 blx r3 */
/* @0x292854 vmov s13, r8 */
/* @0x292858 ldr r3, [pc, #0xf0] */
/* @0x29285c vcvt.f32.s32 s15, s13 */
/* @0x292860 ldr r3, [r4, r3] */
/* @0x292864 vstr s15, [r3] */
/* @0x292868 pop {r4, r5, r6, r7, r8, pc} */
/* @0x29286c ldr r3, [pc, #0xb4] */
/* @0x292870 mov r2, r8 */
/* @0x292874 ldr r1, [pc, #0xd8] */
/* @0x292878 ldr r3, [r4, r3] */
/* @0x29287c add r1, pc, r1 */
/* @0x292880 ldr r0, [r3] */
/* @0x292884 ldr r3, [r0] */
/* @0x292888 ldr r3, [r3, #0xc] */
/* @0x29288c blx r3 */
/* @0x292890 vmov s14, r8 */
/* @0x292894 ldr r3, [pc, #0xbc] */
/* @0x292898 vcvt.f32.s32 s15, s14 */
/* @0x29289c ldr r3, [r4, r3] */
/* @0x2928a0 vstr s15, [r3] */
/* @0x2928a4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2928a8 ldr r3, [r6] */
/* @0x2928ac mov r1, r7 */
/* @0x2928b0 mov r2, #0 */
/* @0x2928b4 mov r0, r6 */
/* @0x2928b8 ldr r3, [r3, #0x2a4] */
/* @0x2928bc blx r3 */
/* @0x2928c0 ldr r1, [pc, #0x94] */
/* @0x2928c4 mov r2, r8 */
/* @0x2928c8 add r1, pc, r1 */
/* @0x2928cc mov r5, r0 */
/* @0x2928d0 ldr r0, [pc, #0x50] */
/* @0x2928d4 mov r3, r5 */
/* @0x2928d8 ldr r0, [r4, r0] */
/* @0x2928dc ldr r0, [r0] */
/* @0x2928e0 ldr r12, [r0] */
/* @0x2928e4 ldr r12, [r12, #0xc] */
/* @0x2928e8 blx r12 */
/* @0x2928ec vmov s13, r8 */
/* @0x2928f0 ldr r3, [pc, #0x68] */
/* @0x2928f4 mov r0, r5 */
/* @0x2928f8 vcvt.f64.s32 d7, s13 */
/* @0x2928fc ldr r3, [r4, r3] */
/* @0x292900 vstr d7, [r3] */
/* @0x292904 bl 0xb6640 <strdup@plt> */
/* @0x292908 ldr r3, [pc, #0x54] */
/* @0x29290c cmp r5, #0 */
/* @0x292910 cmpne r7, #0 */
/* @0x292914 ldr r3, [r4, r3] */
/* @0x292918 str r0, [r3] */
/* @0x29291c popeq {r4, r5, r6, r7, r8, pc} */
/* @0x292920 b 0x292710 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0xb0> */
/* @0x292924 ldrsbeq pc, [r5], -r8 */
/* @0x292928 .word 0xffffbac4 */
/* @0x29292c andeq r6, r12, r0, ror r9 */
/* @0x292930 .word 0xffffe284 */
/* @0x292934 andeq r6, r12, r4, asr #16 */
/* @0x292938 .word 0xffffe254 */
/* @0x29293c andeq r6, r12, r4, lsl r8 */
/* @0x292940 .word 0xfffff770 */
/* @0x292944 ldrdeq r6, r7, [r12], -r8 */
/* @0x292948 .word 0xffffe280 */
/* @0x29294c andeq r6, r12, r8, lsr #15 */
/* @0x292950 .word 0xffffe288 */
/* @0x292954 andeq r6, r12, r8, lsl #15 */
/* @0x292958 .word 0xffffe28c */
/* @0x29295c andeq r6, r12, r8, asr r7 */
/* @0x292960 .word 0xffffe248 */
/* @0x292964 .word 0xfffffd18 */

/* ── FUNC 0x292968 · Java_com_yoyogames_runner_RunnerJNILib_GetSaveFileName · size=172 · insn=43 */
/* @0x292968 push {r4, r5, r6, r7, r8, lr} */
/* @0x29296c sub sp, sp, #520 */
/* @0x292970 ldr r5, [pc, #0x98] */
/* @0x292974 mov r4, r0 */
/* @0x292978 mov r6, r2 */
/* @0x29297c add r8, sp, #4 */
/* @0x292980 ldr r5, [pc, r5] */
/* @0x292984 ldr r3, [r5] */
/* @0x292988 str r3, [sp, #0x204] */
/* @0x29298c bl 0x290614 <setJNIEnv> */
/* @0x292990 ldr r3, [r4] */
/* @0x292994 mov r1, r6 */
/* @0x292998 mov r2, #0 */
/* @0x29299c mov r0, r4 */
/* @0x2929a0 ldr r3, [r3, #0x2a4] */
/* @0x2929a4 blx r3 */
/* @0x2929a8 movw r1, #0x1ff */
/* @0x2929ac mov r7, r0 */
/* @0x2929b0 mov r2, r0 */
/* @0x2929b4 mov r0, r8 */
/* @0x2929b8 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x2929bc cmp r7, #0 */
/* @0x2929c0 cmpne r6, #0 */
/* @0x2929c4 beq 0x2929e0 <Java_com_yoyogames_runner_RunnerJNILib_GetSaveFileName+0x78> */
/* @0x2929c8 ldr r3, [r4] */
/* @0x2929cc mov r1, r6 */
/* @0x2929d0 mov r2, r7 */
/* @0x2929d4 mov r0, r4 */
/* @0x2929d8 ldr r3, [r3, #0x2a8] */
/* @0x2929dc blx r3 */
/* @0x2929e0 ldr r3, [r4] */
/* @0x2929e4 mov r1, r8 */
/* @0x2929e8 mov r0, r4 */
/* @0x2929ec ldr r3, [r3, #0x29c] */
/* @0x2929f0 blx r3 */
/* @0x2929f4 ldr r2, [sp, #0x204] */
/* @0x2929f8 ldr r3, [r5] */
/* @0x2929fc cmp r2, r3 */
/* @0x292a00 bne 0x292a0c <Java_com_yoyogames_runner_RunnerJNILib_GetSaveFileName+0xa4> */
/* @0x292a04 add sp, sp, #520 */
/* @0x292a08 pop {r4, r5, r6, r7, r8, pc} */
/* @0x292a0c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x292a10 ldrsbeq r10, [r5], -r0 */

/* ── FUNC 0x292a14 · Java_com_yoyogames_runner_RunnerJNILib_getGuiWidth · size=52 · insn=13 */
/* @0x292a14 push {r3, lr} */
/* @0x292a18 bl 0x290614 <setJNIEnv> */
/* @0x292a1c ldr r3, [pc, #0x1c] */
/* @0x292a20 ldr r3, [pc, r3] */
/* @0x292a24 ldr r0, [r3] */
/* @0x292a28 cmp r0, #0 */
/* @0x292a2c popge {r3, pc} */
/* @0x292a30 ldr r3, [pc, #0xc] */
/* @0x292a34 ldr r3, [pc, r3] */
/* @0x292a38 ldr r0, [r3] */
/* @0x292a3c pop {r3, pc} */
/* @0x292a40 andseq sp, r5, r8, asr #2 */
/* @0x292a44 andseq sp, r5, r8, ror #8 */

/* ── FUNC 0x292a48 · Java_com_yoyogames_runner_RunnerJNILib_getGuiHeight · size=52 · insn=13 */
/* @0x292a48 push {r3, lr} */
/* @0x292a4c bl 0x290614 <setJNIEnv> */
/* @0x292a50 ldr r3, [pc, #0x1c] */
/* @0x292a54 ldr r3, [pc, r3] */
/* @0x292a58 ldr r0, [r3] */
/* @0x292a5c cmp r0, #0 */
/* @0x292a60 popge {r3, pc} */
/* @0x292a64 ldr r3, [pc, #0xc] */
/* @0x292a68 ldr r3, [pc, r3] */
/* @0x292a6c ldr r0, [r3] */
/* @0x292a70 pop {r3, pc} */
/* @0x292a74 andseq sp, r5, r0, lsr #2 */
/* @0x292a78 andseq sp, r5, r8, lsr r4 */

/* ── FUNC 0x292a7c · Java_com_yoyogames_runner_RunnerJNILib_SetAchievementsAvailable · size=28 · insn=7 */
/* @0x292a7c push {r4, lr} */
/* @0x292a80 mov r4, r2 */
/* @0x292a84 bl 0x290614 <setJNIEnv> */
/* @0x292a88 adds r0, r4, #0 */
/* @0x292a8c pop {r4, lr} */
/* @0x292a90 movne r0, #1 */
/* @0x292a94 b 0x159a60 <_Z21Set_AchievementSystemb> */

/* ── FUNC 0x292a98 · Java_com_yoyogames_runner_RunnerJNILib_dsMapCreate · size=16 · insn=4 */
/* @0x292a98 push {r3, lr} */
/* @0x292a9c bl 0x290614 <setJNIEnv> */
/* @0x292aa0 pop {r3, lr} */
/* @0x292aa4 b 0x101818 <dsMapCreate> */

/* ── FUNC 0x292aa8 · Java_com_yoyogames_runner_RunnerJNILib_dsListCreate · size=16 · insn=4 */
/* @0x292aa8 push {r3, lr} */
/* @0x292aac bl 0x290614 <setJNIEnv> */
/* @0x292ab0 pop {r3, lr} */
/* @0x292ab4 b 0x101b9c <dsListCreate> */

/* ── FUNC 0x292ab8 · Java_com_yoyogames_runner_RunnerJNILib_dsMapAddString · size=176 · insn=44 */
/* @0x292ab8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x292abc mov r4, r0 */
/* @0x292ac0 mov r8, r3 */
/* @0x292ac4 mov r9, r2 */
/* @0x292ac8 ldr r5, [sp, #0x20] */
/* @0x292acc bl 0x290614 <setJNIEnv> */
/* @0x292ad0 ldr r3, [r4] */
/* @0x292ad4 mov r1, r8 */
/* @0x292ad8 mov r2, #0 */
/* @0x292adc mov r0, r4 */
/* @0x292ae0 ldr r3, [r3, #0x2a4] */
/* @0x292ae4 blx r3 */
/* @0x292ae8 ldr r3, [r4] */
/* @0x292aec mov r1, r5 */
/* @0x292af0 mov r2, #0 */
/* @0x292af4 ldr r3, [r3, #0x2a4] */
/* @0x292af8 mov r7, r0 */
/* @0x292afc mov r0, r4 */
/* @0x292b00 blx r3 */
/* @0x292b04 mov r1, r7 */
/* @0x292b08 mov r6, r0 */
/* @0x292b0c mov r0, r9 */
/* @0x292b10 mov r2, r6 */
/* @0x292b14 bl 0x1019f4 <dsMapAddString> */
/* @0x292b18 cmp r7, #0 */
/* @0x292b1c cmpne r8, #0 */
/* @0x292b20 bne 0x292b4c <Java_com_yoyogames_runner_RunnerJNILib_dsMapAddString+0x94> */
/* @0x292b24 cmp r6, #0 */
/* @0x292b28 cmpne r5, #0 */
/* @0x292b2c popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x292b30 ldr r3, [r4] */
/* @0x292b34 mov r1, r5 */
/* @0x292b38 mov r2, r6 */
/* @0x292b3c mov r0, r4 */
/* @0x292b40 ldr r3, [r3, #0x2a8] */
/* @0x292b44 blx r3 */
/* @0x292b48 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x292b4c ldr r3, [r4] */
/* @0x292b50 mov r1, r8 */
/* @0x292b54 mov r2, r7 */
/* @0x292b58 mov r0, r4 */
/* @0x292b5c ldr r3, [r3, #0x2a8] */
/* @0x292b60 blx r3 */
/* @0x292b64 b 0x292b24 <Java_com_yoyogames_runner_RunnerJNILib_dsMapAddString+0x6c> */

/* ── FUNC 0x292b68 · Java_com_yoyogames_runner_RunnerJNILib_dsMapAddInt · size=108 · insn=27 */
/* @0x292b68 push {r4, r5, r6, r7, r8, lr} */
/* @0x292b6c mov r4, r0 */
/* @0x292b70 mov r5, r3 */
/* @0x292b74 mov r8, r2 */
/* @0x292b78 ldr r7, [sp, #0x18] */
/* @0x292b7c bl 0x290614 <setJNIEnv> */
/* @0x292b80 ldr r3, [r4] */
/* @0x292b84 mov r1, r5 */
/* @0x292b88 mov r2, #0 */
/* @0x292b8c mov r0, r4 */
/* @0x292b90 ldr r3, [r3, #0x2a4] */
/* @0x292b94 blx r3 */
/* @0x292b98 mov r2, r7 */
/* @0x292b9c mov r6, r0 */
/* @0x292ba0 mov r0, r8 */
/* @0x292ba4 mov r1, r6 */
/* @0x292ba8 bl 0x101850 <dsMapAddInt> */
/* @0x292bac cmp r6, #0 */
/* @0x292bb0 cmpne r5, #0 */
/* @0x292bb4 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x292bb8 ldr r3, [r4] */
/* @0x292bbc mov r1, r5 */
/* @0x292bc0 mov r2, r6 */
/* @0x292bc4 mov r0, r4 */
/* @0x292bc8 ldr r3, [r3, #0x2a8] */
/* @0x292bcc blx r3 */
/* @0x292bd0 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x292bd4 · Java_com_yoyogames_runner_RunnerJNILib_dsListAddString · size=100 · insn=25 */
/* @0x292bd4 push {r3, r4, r5, r6, r7, lr} */
/* @0x292bd8 mov r4, r0 */
/* @0x292bdc mov r5, r3 */
/* @0x292be0 mov r7, r2 */
/* @0x292be4 bl 0x290614 <setJNIEnv> */
/* @0x292be8 ldr r3, [r4] */
/* @0x292bec mov r1, r5 */
/* @0x292bf0 mov r2, #0 */
/* @0x292bf4 mov r0, r4 */
/* @0x292bf8 ldr r3, [r3, #0x2a4] */
/* @0x292bfc blx r3 */
/* @0x292c00 mov r6, r0 */
/* @0x292c04 mov r0, r7 */
/* @0x292c08 mov r1, r6 */
/* @0x292c0c bl 0x101d20 <dsListAddString> */
/* @0x292c10 cmp r6, #0 */
/* @0x292c14 cmpne r5, #0 */
/* @0x292c18 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x292c1c ldr r3, [r4] */
/* @0x292c20 mov r1, r5 */
/* @0x292c24 mov r2, r6 */
/* @0x292c28 mov r0, r4 */
/* @0x292c2c ldr r3, [r3, #0x2a8] */
/* @0x292c30 blx r3 */
/* @0x292c34 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x292c38 · Java_com_yoyogames_runner_RunnerJNILib_dsListAddInt · size=32 · insn=8 */
/* @0x292c38 push {r3, r4, r5, lr} */
/* @0x292c3c mov r4, r2 */
/* @0x292c40 mov r5, r3 */
/* @0x292c44 bl 0x290614 <setJNIEnv> */
/* @0x292c48 mov r0, r4 */
/* @0x292c4c mov r1, r5 */
/* @0x292c50 pop {r3, r4, r5, lr} */
/* @0x292c54 b 0x101c18 <dsListAddInt> */

/* ── FUNC 0x292c58 · Java_com_yoyogames_runner_RunnerJNILib_InputResult · size=176 · insn=44 */
/* @0x292c58 push {r4, r5, r6, r7, r8, lr} */
/* @0x292c5c sub sp, sp, #8 */
/* @0x292c60 mov r5, r0 */
/* @0x292c64 mov r6, r2 */
/* @0x292c68 mov r7, r3 */
/* @0x292c6c ldr r8, [sp, #0x20] */
/* @0x292c70 bl 0x290614 <setJNIEnv> */
/* @0x292c74 ldr r3, [r5] */
/* @0x292c78 mov r1, r6 */
/* @0x292c7c mov r2, #0 */
/* @0x292c80 mov r0, r5 */
/* @0x292c84 ldr r3, [r3, #0x2a4] */
/* @0x292c88 blx r3 */
/* @0x292c8c ldr r12, [pc, #0x6c] */
/* @0x292c90 ldr r1, [pc, #0x6c] */
/* @0x292c94 mov r3, r7 */
/* @0x292c98 ldr r12, [pc, r12] */
/* @0x292c9c add r1, pc, r1 */
/* @0x292ca0 mov r2, r0 */
/* @0x292ca4 mov r4, r0 */
/* @0x292ca8 ldr r0, [r12] */
/* @0x292cac ldr r12, [r0] */
/* @0x292cb0 str r8, [sp] */
/* @0x292cb4 ldr r12, [r12, #0xc] */
/* @0x292cb8 blx r12 */
/* @0x292cbc mov r0, r4 */
/* @0x292cc0 bl 0xb6640 <strdup@plt> */
/* @0x292cc4 mov r1, r7 */
/* @0x292cc8 mov r2, r0 */
/* @0x292ccc mov r0, r8 */
/* @0x292cd0 bl 0xf274c <_ZN10InputQuery9SetResultEiiPKc> */
/* @0x292cd4 cmp r4, #0 */
/* @0x292cd8 cmpne r6, #0 */
/* @0x292cdc beq 0x292cf8 <Java_com_yoyogames_runner_RunnerJNILib_InputResult+0xa0> */
/* @0x292ce0 ldr r3, [r5] */
/* @0x292ce4 mov r1, r6 */
/* @0x292ce8 mov r2, r4 */
/* @0x292cec mov r0, r5 */
/* @0x292cf0 ldr r3, [r3, #0x2a8] */
/* @0x292cf4 blx r3 */
/* @0x292cf8 add sp, sp, #8 */
/* @0x292cfc pop {r4, r5, r6, r7, r8, pc} */
/* @0x292d00 andseq r10, r5, r12, ror r10 */
/* @0x292d04 andeq r6, r12, r4, asr #7 */

/* ── FUNC 0x292d08 · Java_com_yoyogames_runner_RunnerJNILib_HttpResult · size=596 · insn=149 */
/* @0x292d08 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x292d0c sub sp, sp, #28 */
/* @0x292d10 mov r7, r2 */
/* @0x292d14 mov r11, r0 */
/* @0x292d18 str r3, [sp, #0x14] */
/* @0x292d1c ldr r5, [sp, #0x40] */
/* @0x292d20 bl 0x290614 <setJNIEnv> */
/* @0x292d24 ldr r2, [pc, #0x21c] */
/* @0x292d28 ldr r1, [pc, #0x21c] */
/* @0x292d2c ldr r2, [pc, r2] */
/* @0x292d30 add r1, pc, r1 */
/* @0x292d34 ldr r6, [r2] */
/* @0x292d38 ldr r2, [r6] */
/* @0x292d3c mov r0, r6 */
/* @0x292d40 ldr r2, [r2, #0xc] */
/* @0x292d44 blx r2 */
/* @0x292d48 cmp r7, #0 */
/* @0x292d4c moveq r9, r7 */
/* @0x292d50 beq 0x292d6c <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x64> */
/* @0x292d54 ldr r2, [r11] */
/* @0x292d58 mov r0, r11 */
/* @0x292d5c mov r1, r7 */
/* @0x292d60 ldr r2, [r2, #0x2ac] */
/* @0x292d64 blx r2 */
/* @0x292d68 mov r9, r0 */
/* @0x292d6c ldr r3, [sp, #0x44] */
/* @0x292d70 cmp r3, #0 */
/* @0x292d74 beq 0x292f04 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x1fc> */
/* @0x292d78 ldr lr, [r11] */
/* @0x292d7c mov r0, r11 */
/* @0x292d80 mov r1, r3 */
/* @0x292d84 mov r2, #0 */
/* @0x292d88 ldr r4, [lr, #0x2a4] */
/* @0x292d8c blx r4 */
/* @0x292d90 mov r8, r0 */
/* @0x292d94 ldr r3, [sp, #0x48] */
/* @0x292d98 cmp r3, #0 */
/* @0x292d9c beq 0x292ef4 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x1ec> */
/* @0x292da0 ldr lr, [r11] */
/* @0x292da4 mov r1, r3 */
/* @0x292da8 mov r0, r11 */
/* @0x292dac mov r2, #0 */
/* @0x292db0 ldr r4, [lr, #0x2a4] */
/* @0x292db4 blx r4 */
/* @0x292db8 adds r3, r0, #0 */
/* @0x292dbc mov r10, r0 */
/* @0x292dc0 movne r3, #1 */
/* @0x292dc4 str r3, [sp, #0x10] */
/* @0x292dc8 ldr r2, [pc, #0x180] */
/* @0x292dcc ldr r2, [pc, r2] */
/* @0x292dd0 ldr r4, [r2] */
/* @0x292dd4 cmp r4, #0 */
/* @0x292dd8 beq 0x292e04 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0xfc> */
/* @0x292ddc ldr r2, [r4, #0x24] */
/* @0x292de0 cmp r2, r5 */
/* @0x292de4 bne 0x292df8 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0xf0> */
/* @0x292de8 b 0x292e58 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x150> */
/* @0x292dec ldr r3, [r4, #0x24] */
/* @0x292df0 cmp r3, r5 */
/* @0x292df4 beq 0x292e58 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x150> */
/* @0x292df8 ldr r4, [r4, #0x4] */
/* @0x292dfc cmp r4, #0 */
/* @0x292e00 bne 0x292dec <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0xe4> */
/* @0x292e04 ldr r3, [sp, #0x44] */
/* @0x292e08 cmp r8, #0 */
/* @0x292e0c cmpne r3, #0 */
/* @0x292e10 beq 0x292e2c <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x124> */
/* @0x292e14 ldr r3, [r11] */
/* @0x292e18 mov r2, r8 */
/* @0x292e1c ldr r1, [sp, #0x44] */
/* @0x292e20 mov r0, r11 */
/* @0x292e24 ldr r3, [r3, #0x2a8] */
/* @0x292e28 blx r3 */
/* @0x292e2c ldr r3, [sp, #0x10] */
/* @0x292e30 cmp r3, #0 */
/* @0x292e34 beq 0x292e50 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x148> */
/* @0x292e38 ldr r3, [r11] */
/* @0x292e3c mov r2, r10 */
/* @0x292e40 ldr r1, [sp, #0x48] */
/* @0x292e44 mov r0, r11 */
/* @0x292e48 ldr r3, [r3, #0x2a8] */
/* @0x292e4c blx r3 */
/* @0x292e50 add sp, sp, #28 */
/* @0x292e54 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x292e58 ldr r3, [r4, #0x38] */
/* @0x292e5c cmp r9, r3 */
/* @0x292e60 bgt 0x292f0c <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x204> */
/* @0x292e64 mov r0, r4 */
/* @0x292e68 mov r1, r10 */
/* @0x292e6c bl 0x18e2d4 <_ZN16HTTP_REQ_CONTEXT18SetResponseHeadersEPc> */
/* @0x292e70 ldr r3, [sp, #0x14] */
/* @0x292e74 cmp r9, #0 */
/* @0x292e78 str r3, [r4, #0x28] */
/* @0x292e7c mov r3, #7 */
/* @0x292e80 str r3, [r4, #0xc] */
/* @0x292e84 ble 0x292ecc <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x1c4> */
/* @0x292e88 ldr lr, [r11] */
/* @0x292e8c mov r1, r7 */
/* @0x292e90 ldr r12, [r4, #0x34] */
/* @0x292e94 mov r0, r11 */
/* @0x292e98 mov r2, #0 */
/* @0x292e9c mov r3, r9 */
/* @0x292ea0 str r12, [sp] */
/* @0x292ea4 ldr r7, [lr, #0x320] */
/* @0x292ea8 blx r7 */
/* @0x292eac ldr r3, [r6] */
/* @0x292eb0 ldr r1, [pc, #0x9c] */
/* @0x292eb4 mov r0, r6 */
/* @0x292eb8 mov r2, r9 */
/* @0x292ebc add r1, pc, r1 */
/* @0x292ec0 ldr r3, [r3, #0xc] */
/* @0x292ec4 blx r3 */
/* @0x292ec8 str r9, [r4, #0x3c] */
/* @0x292ecc cmp r8, #0 */
/* @0x292ed0 beq 0x292e2c <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x124> */
/* @0x292ed4 ldr r0, [r4, #0x20] */
/* @0x292ed8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x292edc mov r3, #0 */
/* @0x292ee0 mov r0, r8 */
/* @0x292ee4 str r3, [r4, #0x20] */
/* @0x292ee8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x292eec str r0, [r4, #0x20] */
/* @0x292ef0 b 0x292e04 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0xfc> */
/* @0x292ef4 ldr r3, [sp, #0x48] */
/* @0x292ef8 str r3, [sp, #0x10] */
/* @0x292efc mov r10, r3 */
/* @0x292f00 b 0x292dc8 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0xc0> */
/* @0x292f04 ldr r8, [sp, #0x44] */
/* @0x292f08 b 0x292d94 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x8c> */
/* @0x292f0c ldr r0, [r4, #0x34] */
/* @0x292f10 add r3, r9, #1 */
/* @0x292f14 str r3, [sp, #0xc] */
/* @0x292f18 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x292f1c ldr r3, [sp, #0xc] */
/* @0x292f20 mov r2, #70 */
/* @0x292f24 ldr r1, [pc, #0x2c] */
/* @0x292f28 mov r0, r3 */
/* @0x292f2c add r1, pc, r1 */
/* @0x292f30 mov r3, #1 */
/* @0x292f34 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x292f38 ldr r12, [sp, #0xc] */
/* @0x292f3c str r12, [r4, #0x38] */
/* @0x292f40 str r0, [r4, #0x34] */
/* @0x292f44 b 0x292e64 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x15c> */
/* @0x292f48 andseq r10, r5, r4, lsl r12 */
/* @0x292f4c andeq r6, r12, r0, asr r3 */
/* @0x292f50 andseq r11, r5, r12, lsr #32 */
/* @0x292f54 ldrdeq r6, r7, [r12], -r0 */
/* @0x292f58 andeq lr, r9, r4, lsl #2 */

/* ── FUNC 0x292f5c · Java_com_yoyogames_runner_RunnerJNILib_BackKeyLongPressEvent · size=40 · insn=10 */
/* @0x292f5c push {r3, lr} */
/* @0x292f60 bl 0x290614 <setJNIEnv> */
/* @0x292f64 ldr r3, [pc, #0x14] */
/* @0x292f68 ldr r3, [pc, r3] */
/* @0x292f6c ldrb r3, [r3] */
/* @0x292f70 cmp r3, #0 */
/* @0x292f74 popeq {r3, pc} */
/* @0x292f78 pop {r3, lr} */
/* @0x292f7c b 0x10c320 <_Z14YYGML_game_endv> */
/* @0x292f80 andseq r10, r5, r8, asr #25 */

/* ── FUNC 0x292f84 · Java_com_yoyogames_runner_RunnerJNILib_HttpProgress · size=496 · insn=124 */
/* @0x292f84 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x292f88 sub sp, sp, #12 */
/* @0x292f8c mov r9, r2 */
/* @0x292f90 mov r8, r3 */
/* @0x292f94 mov r6, r0 */
/* @0x292f98 ldr r5, [sp, #0x30] */
/* @0x292f9c ldr r7, [sp, #0x34] */
/* @0x292fa0 bl 0x290614 <setJNIEnv> */
/* @0x292fa4 cmp r9, #0 */
/* @0x292fa8 moveq r8, r9 */
/* @0x292fac beq 0x292ff4 <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0x70> */
/* @0x292fb0 ldr r3, [r6] */
/* @0x292fb4 mov r0, r6 */
/* @0x292fb8 mov r1, r9 */
/* @0x292fbc ldr r3, [r3, #0x2ac] */
/* @0x292fc0 blx r3 */
/* @0x292fc4 cmp r8, r0 */
/* @0x292fc8 beq 0x292ff4 <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0x70> */
/* @0x292fcc ldr r12, [pc, #0x190] */
/* @0x292fd0 mov r2, r0 */
/* @0x292fd4 ldr r1, [pc, #0x18c] */
/* @0x292fd8 mov r3, r8 */
/* @0x292fdc ldr r12, [pc, r12] */
/* @0x292fe0 add r1, pc, r1 */
/* @0x292fe4 ldr r0, [r12] */
/* @0x292fe8 ldr r12, [r0] */
/* @0x292fec ldr r12, [r12, #0xc] */
/* @0x292ff0 blx r12 */
/* @0x292ff4 cmp r7, #0 */
/* @0x292ff8 moveq r10, r7 */
/* @0x292ffc beq 0x29301c <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0x98> */
/* @0x293000 ldr r3, [r6] */
/* @0x293004 mov r0, r6 */
/* @0x293008 mov r1, r7 */
/* @0x29300c mov r2, #0 */
/* @0x293010 ldr r3, [r3, #0x2a4] */
/* @0x293014 blx r3 */
/* @0x293018 mov r10, r0 */
/* @0x29301c ldr r12, [pc, #0x148] */
/* @0x293020 ldr r12, [pc, r12] */
/* @0x293024 ldr r4, [r12] */
/* @0x293028 cmp r4, #0 */
/* @0x29302c beq 0x293058 <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0xd4> */
/* @0x293030 ldr r3, [r4, #0x24] */
/* @0x293034 cmp r3, r5 */
/* @0x293038 bne 0x29304c <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0xc8> */
/* @0x29303c b 0x29308c <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0x108> */
/* @0x293040 ldr r12, [r4, #0x24] */
/* @0x293044 cmp r12, r5 */
/* @0x293048 beq 0x29308c <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0x108> */
/* @0x29304c ldr r4, [r4, #0x4] */
/* @0x293050 cmp r4, #0 */
/* @0x293054 bne 0x293040 <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0xbc> */
/* @0x293058 cmp r10, #0 */
/* @0x29305c cmpne r7, #0 */
/* @0x293060 bne 0x29306c <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0xe8> */
/* @0x293064 add sp, sp, #12 */
/* @0x293068 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29306c ldr r3, [r6] */
/* @0x293070 mov r1, r7 */
/* @0x293074 mov r2, r10 */
/* @0x293078 mov r0, r6 */
/* @0x29307c ldr r3, [r3, #0x2a8] */
/* @0x293080 blx r3 */
/* @0x293084 add sp, sp, #12 */
/* @0x293088 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29308c ldr r3, [r4, #0x3c] */
/* @0x293090 ldr r2, [r4, #0x38] */
/* @0x293094 add r12, r3, r8 */
/* @0x293098 cmp r12, r2 */
/* @0x29309c ble 0x2930ec <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0x168> */
/* @0x2930a0 ldr r0, [sp, #0x3c] */
/* @0x2930a4 mov r3, #1 */
/* @0x2930a8 ldr r1, [pc, #0xc0] */
/* @0x2930ac cmp r2, r0 */
/* @0x2930b0 mov r2, #70 */
/* @0x2930b4 addge r11, r12, #65536 */
/* @0x2930b8 add r1, pc, r1 */
/* @0x2930bc ldrlt r11, [sp, #0x3c] */
/* @0x2930c0 ldr r5, [r4, #0x34] */
/* @0x2930c4 mov r0, r11 */
/* @0x2930c8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2930cc mov r1, r5 */
/* @0x2930d0 ldr r2, [r4, #0x3c] */
/* @0x2930d4 str r0, [r4, #0x34] */
/* @0x2930d8 bl 0xb65bc <memcpy@plt> */
/* @0x2930dc mov r0, r5 */
/* @0x2930e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2930e4 ldr r3, [r4, #0x3c] */
/* @0x2930e8 str r11, [r4, #0x38] */
/* @0x2930ec ldr r12, [r6] */
/* @0x2930f0 mov r2, #3 */
/* @0x2930f4 ldr r0, [sp, #0x3c] */
/* @0x2930f8 mov r1, r9 */
/* @0x2930fc ldr lr, [r4, #0x34] */
/* @0x293100 str r2, [r4, #0xc] */
/* @0x293104 mov r2, #0 */
/* @0x293108 str r0, [r4, #0x40] */
/* @0x29310c add r3, lr, r3 */
/* @0x293110 mov r0, r6 */
/* @0x293114 str r3, [sp] */
/* @0x293118 mov r3, r8 */
/* @0x29311c ldr r12, [r12, #0x320] */
/* @0x293120 blx r12 */
/* @0x293124 ldr r3, [r4, #0x3c] */
/* @0x293128 cmp r10, #0 */
/* @0x29312c add r8, r3, r8 */
/* @0x293130 str r8, [r4, #0x3c] */
/* @0x293134 beq 0x293064 <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0xe0> */
/* @0x293138 ldr r0, [r4, #0x20] */
/* @0x29313c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x293140 mov r3, #0 */
/* @0x293144 mov r0, r10 */
/* @0x293148 str r3, [r4, #0x20] */
/* @0x29314c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x293150 cmp r10, #0 */
/* @0x293154 cmpne r7, #0 */
/* @0x293158 str r0, [r4, #0x20] */
/* @0x29315c beq 0x293064 <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0xe0> */
/* @0x293160 b 0x29306c <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0xe8> */
/* @0x293164 andseq r10, r5, r4, ror #18 */
/* @0x293168 andeq r6, r12, r8, asr #1 */
/* @0x29316c ldrsbeq r10, [r5], -r8 */
/* @0x293170 andeq sp, r9, r8, ror pc */

/* ── FUNC 0x293174 · Java_com_yoyogames_runner_RunnerJNILib_HttpResultString · size=260 · insn=65 */
/* @0x293174 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x293178 sub sp, sp, #12 */
/* @0x29317c mov r6, r0 */
/* @0x293180 mov r7, r2 */
/* @0x293184 mov r8, r3 */
/* @0x293188 ldr r5, [sp, #0x28] */
/* @0x29318c bl 0x290614 <setJNIEnv> */
/* @0x293190 ldr r3, [r6] */
/* @0x293194 mov r1, r7 */
/* @0x293198 mov r2, #0 */
/* @0x29319c mov r0, r6 */
/* @0x2931a0 ldr r3, [r3, #0x2a4] */
/* @0x2931a4 blx r3 */
/* @0x2931a8 ldr r12, [pc, #0xbc] */
/* @0x2931ac ldr r1, [pc, #0xbc] */
/* @0x2931b0 mov r3, r8 */
/* @0x2931b4 ldr r12, [pc, r12] */
/* @0x2931b8 add r1, pc, r1 */
/* @0x2931bc mov r2, r0 */
/* @0x2931c0 mov r9, r0 */
/* @0x2931c4 ldr r0, [r12] */
/* @0x2931c8 ldr r12, [r0] */
/* @0x2931cc str r5, [sp] */
/* @0x2931d0 ldr r12, [r12, #0xc] */
/* @0x2931d4 blx r12 */
/* @0x2931d8 ldr r12, [pc, #0x94] */
/* @0x2931dc ldr r12, [pc, r12] */
/* @0x2931e0 ldr r4, [r12] */
/* @0x2931e4 cmp r4, #0 */
/* @0x2931e8 beq 0x293214 <Java_com_yoyogames_runner_RunnerJNILib_HttpResultString+0xa0> */
/* @0x2931ec ldr r3, [r4, #0x24] */
/* @0x2931f0 cmp r3, r5 */
/* @0x2931f4 bne 0x293208 <Java_com_yoyogames_runner_RunnerJNILib_HttpResultString+0x94> */
/* @0x2931f8 b 0x293240 <Java_com_yoyogames_runner_RunnerJNILib_HttpResultString+0xcc> */
/* @0x2931fc ldr r12, [r4, #0x24] */
/* @0x293200 cmp r12, r5 */
/* @0x293204 beq 0x293240 <Java_com_yoyogames_runner_RunnerJNILib_HttpResultString+0xcc> */
/* @0x293208 ldr r4, [r4, #0x4] */
/* @0x29320c cmp r4, #0 */
/* @0x293210 bne 0x2931fc <Java_com_yoyogames_runner_RunnerJNILib_HttpResultString+0x88> */
/* @0x293214 cmp r9, #0 */
/* @0x293218 cmpne r7, #0 */
/* @0x29321c beq 0x293238 <Java_com_yoyogames_runner_RunnerJNILib_HttpResultString+0xc4> */
/* @0x293220 ldr r3, [r6] */
/* @0x293224 mov r1, r7 */
/* @0x293228 mov r2, r9 */
/* @0x29322c mov r0, r6 */
/* @0x293230 ldr r3, [r3, #0x2a8] */
/* @0x293234 blx r3 */
/* @0x293238 add sp, sp, #12 */
/* @0x29323c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x293240 mov r3, #7 */
/* @0x293244 mov r1, r9 */
/* @0x293248 str r3, [r4, #0xc] */
/* @0x29324c str r8, [r4, #0x28] */
/* @0x293250 ldr r0, [r4, #0x34] */
/* @0x293254 bl 0xb65a4 <strcpy@plt> */
/* @0x293258 ldr r0, [r4, #0x34] */
/* @0x29325c bl 0xb6538 <strlen@plt> */
/* @0x293260 add r0, r0, #1 */
/* @0x293264 str r0, [r4, #0x3c] */
/* @0x293268 b 0x293214 <Java_com_yoyogames_runner_RunnerJNILib_HttpResultString+0xa0> */
/* @0x29326c andseq r10, r5, r0, ror #10 */
/* @0x293270 andeq r5, r12, r0, lsr #30 */
/* @0x293274 andseq r10, r5, r12, lsl r12 */

/* ── FUNC 0x293278 · Java_com_yoyogames_runner_RunnerJNILib_onItemPurchase · size=252 · insn=63 */
/* @0x293278 push {r4, r5, r6, r7, r8, lr} */
/* @0x29327c mov r5, r0 */
/* @0x293280 sub sp, sp, #16 */
/* @0x293284 mov r7, r2 */
/* @0x293288 mov r8, r3 */
/* @0x29328c bl 0x290614 <setJNIEnv> */
/* @0x293290 ldr r3, [r5] */
/* @0x293294 mov r1, r7 */
/* @0x293298 mov r2, #0 */
/* @0x29329c mov r0, r5 */
/* @0x2932a0 ldr r3, [r3, #0x2a4] */
/* @0x2932a4 blx r3 */
/* @0x2932a8 ldr r1, [pc, #0xb4] */
/* @0x2932ac movw r2, #0x89d */
/* @0x2932b0 mov r3, #1 */
/* @0x2932b4 add r1, pc, r1 */
/* @0x2932b8 mov r6, r0 */
/* @0x2932bc mov r0, #8 */
/* @0x2932c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2932c4 mov r4, r0 */
/* @0x2932c8 str r8, [r0] */
/* @0x2932cc mov r0, r6 */
/* @0x2932d0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x2932d4 ldr r12, [pc, #0x8c] */
/* @0x2932d8 ldr r1, [pc, #0x8c] */
/* @0x2932dc mov r3, r4 */
/* @0x2932e0 ldr r12, [pc, r12] */
/* @0x2932e4 add r1, pc, r1 */
/* @0x2932e8 mov r2, r0 */
/* @0x2932ec str r0, [r4, #0x4] */
/* @0x2932f0 ldr r0, [r12] */
/* @0x2932f4 ldr r12, [r0] */
/* @0x2932f8 ldr r12, [r12, #0xc] */
/* @0x2932fc blx r12 */
/* @0x293300 mov r0, #68 */
/* @0x293304 bl 0x27c524 <_Znwj> */
/* @0x293308 ldr r3, [pc, #0x60] */
/* @0x29330c mov r12, #0 */
/* @0x293310 str r4, [sp, #0x4] */
/* @0x293314 ldr r3, [pc, r3] */
/* @0x293318 mov r1, r12 */
/* @0x29331c str r12, [sp] */
/* @0x293320 mov r2, r12 */
/* @0x293324 str r12, [sp, #0x8] */
/* @0x293328 mov r8, r0 */
/* @0x29332c bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b> */
/* @0x293330 cmp r6, #0 */
/* @0x293334 cmpne r7, #0 */
/* @0x293338 mov r3, #7 */
/* @0x29333c str r3, [r8, #0xc] */
/* @0x293340 beq 0x29335c <Java_com_yoyogames_runner_RunnerJNILib_onItemPurchase+0xe4> */
/* @0x293344 ldr r3, [r5] */
/* @0x293348 mov r1, r7 */
/* @0x29334c mov r2, r6 */
/* @0x293350 mov r0, r5 */
/* @0x293354 ldr r3, [r3, #0x2a8] */
/* @0x293358 blx r3 */
/* @0x29335c add sp, sp, #16 */
/* @0x293360 pop {r4, r5, r6, r7, r8, pc} */
/* @0x293364 andeq r4, r12, r0, lsl #29 */
/* @0x293368 andseq r10, r5, r0, ror #12 */
/* @0x29336c andeq r5, r12, r8, lsl lr */
/* @0x293370 andseq lr, r5, r8, asr r6 */

/* ── FUNC 0x293374 · Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess · size=1028 · insn=257 */
/* @0x293374 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x293378 sub sp, sp, #60 */
/* @0x29337c mov r4, r0 */
/* @0x293380 ldr r5, [pc, #0x3cc] */
/* @0x293384 str r2, [sp, #0x30] */
/* @0x293388 str r3, [sp, #0x34] */
/* @0x29338c bl 0x290614 <setJNIEnv> */
/* @0x293390 ldr r3, [r4] */
/* @0x293394 mov r2, #0 */
/* @0x293398 ldr r1, [sp, #0x30] */
/* @0x29339c mov r0, r4 */
/* @0x2933a0 add r5, pc, r5 */
/* @0x2933a4 ldr r3, [r3, #0x2a4] */
/* @0x2933a8 blx r3 */
/* @0x2933ac ldr r3, [r4] */
/* @0x2933b0 ldr r1, [sp, #0x34] */
/* @0x2933b4 mov r2, #0 */
/* @0x2933b8 ldr r3, [r3, #0x2a4] */
/* @0x2933bc str r0, [sp, #0x2c] */
/* @0x2933c0 mov r0, r4 */
/* @0x2933c4 blx r3 */
/* @0x2933c8 ldr r3, [r4] */
/* @0x2933cc ldr r1, [sp, #0x60] */
/* @0x2933d0 mov r2, #0 */
/* @0x2933d4 ldr r3, [r3, #0x2a4] */
/* @0x2933d8 mov r9, r0 */
/* @0x2933dc mov r0, r4 */
/* @0x2933e0 blx r3 */
/* @0x2933e4 ldr r3, [r4] */
/* @0x2933e8 ldr r1, [sp, #0x64] */
/* @0x2933ec mov r2, #0 */
/* @0x2933f0 ldr r3, [r3, #0x2a4] */
/* @0x2933f4 mov r8, r0 */
/* @0x2933f8 mov r0, r4 */
/* @0x2933fc blx r3 */
/* @0x293400 ldr r3, [r4] */
/* @0x293404 ldr r1, [sp, #0x68] */
/* @0x293408 mov r2, #0 */
/* @0x29340c ldr r3, [r3, #0x2a4] */
/* @0x293410 mov r7, r0 */
/* @0x293414 mov r0, r4 */
/* @0x293418 blx r3 */
/* @0x29341c ldr r3, [r4] */
/* @0x293420 ldr r1, [sp, #0x6c] */
/* @0x293424 mov r2, #0 */
/* @0x293428 ldr r3, [r3, #0x2a4] */
/* @0x29342c mov r6, r0 */
/* @0x293430 mov r0, r4 */
/* @0x293434 blx r3 */
/* @0x293438 ldr r3, [r4] */
/* @0x29343c ldr r1, [sp, #0x70] */
/* @0x293440 mov r2, #0 */
/* @0x293444 ldr r3, [r3, #0x2a4] */
/* @0x293448 mov r11, r0 */
/* @0x29344c mov r0, r4 */
/* @0x293450 blx r3 */
/* @0x293454 ldr r3, [pc, #0x2fc] */
/* @0x293458 ldr r3, [r5, r3] */
/* @0x29345c str r3, [sp, #0x14] */
/* @0x293460 mov r10, r0 */
/* @0x293464 ldr r0, [r3] */
/* @0x293468 cmp r0, #0 */
/* @0x29346c beq 0x293480 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x10c> */
/* @0x293470 bl 0xb655c <free@plt> */
/* @0x293474 ldr r2, [sp, #0x14] */
/* @0x293478 mov r3, #0 */
/* @0x29347c str r3, [r2] */
/* @0x293480 ldr r3, [pc, #0x2d4] */
/* @0x293484 ldr r3, [r5, r3] */
/* @0x293488 ldr r0, [r3] */
/* @0x29348c str r3, [sp, #0x18] */
/* @0x293490 cmp r0, #0 */
/* @0x293494 beq 0x2934a8 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x134> */
/* @0x293498 bl 0xb655c <free@plt> */
/* @0x29349c ldr r2, [sp, #0x18] */
/* @0x2934a0 mov r3, #0 */
/* @0x2934a4 str r3, [r2] */
/* @0x2934a8 ldr r3, [pc, #0x2b0] */
/* @0x2934ac ldr r3, [r5, r3] */
/* @0x2934b0 ldr r0, [r3] */
/* @0x2934b4 str r3, [sp, #0x10] */
/* @0x2934b8 cmp r0, #0 */
/* @0x2934bc beq 0x2934d0 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x15c> */
/* @0x2934c0 bl 0xb655c <free@plt> */
/* @0x2934c4 ldr r2, [sp, #0x10] */
/* @0x2934c8 mov r3, #0 */
/* @0x2934cc str r3, [r2] */
/* @0x2934d0 ldr r3, [pc, #0x28c] */
/* @0x2934d4 ldr r3, [r5, r3] */
/* @0x2934d8 ldr r0, [r3] */
/* @0x2934dc str r3, [sp, #0x20] */
/* @0x2934e0 cmp r0, #0 */
/* @0x2934e4 beq 0x2934f8 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x184> */
/* @0x2934e8 bl 0xb655c <free@plt> */
/* @0x2934ec ldr r2, [sp, #0x20] */
/* @0x2934f0 mov r3, #0 */
/* @0x2934f4 str r3, [r2] */
/* @0x2934f8 ldr r3, [pc, #0x268] */
/* @0x2934fc ldr r3, [r5, r3] */
/* @0x293500 ldr r0, [r3] */
/* @0x293504 str r3, [sp, #0x1c] */
/* @0x293508 cmp r0, #0 */
/* @0x29350c beq 0x293520 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x1ac> */
/* @0x293510 bl 0xb655c <free@plt> */
/* @0x293514 ldr r2, [sp, #0x1c] */
/* @0x293518 mov r3, #0 */
/* @0x29351c str r3, [r2] */
/* @0x293520 ldr r3, [pc, #0x244] */
/* @0x293524 ldr r3, [r5, r3] */
/* @0x293528 ldr r0, [r3] */
/* @0x29352c str r3, [sp, #0x24] */
/* @0x293530 cmp r0, #0 */
/* @0x293534 beq 0x293548 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x1d4> */
/* @0x293538 bl 0xb655c <free@plt> */
/* @0x29353c ldr r2, [sp, #0x24] */
/* @0x293540 mov r3, #0 */
/* @0x293544 str r3, [r2] */
/* @0x293548 ldr r3, [pc, #0x220] */
/* @0x29354c ldr r3, [r5, r3] */
/* @0x293550 ldr r0, [r3] */
/* @0x293554 str r3, [sp, #0x28] */
/* @0x293558 cmp r0, #0 */
/* @0x29355c beq 0x293570 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x1fc> */
/* @0x293560 bl 0xb655c <free@plt> */
/* @0x293564 ldr r2, [sp, #0x28] */
/* @0x293568 mov r3, #0 */
/* @0x29356c str r3, [r2] */
/* @0x293570 ldr r0, [sp, #0x2c] */
/* @0x293574 bl 0xb6640 <strdup@plt> */
/* @0x293578 ldr r3, [sp, #0x14] */
/* @0x29357c str r0, [r3] */
/* @0x293580 mov r0, r9 */
/* @0x293584 bl 0xb6640 <strdup@plt> */
/* @0x293588 ldr r2, [sp, #0x18] */
/* @0x29358c str r0, [r2] */
/* @0x293590 mov r0, r8 */
/* @0x293594 bl 0xb6640 <strdup@plt> */
/* @0x293598 ldr r3, [sp, #0x10] */
/* @0x29359c str r0, [r3] */
/* @0x2935a0 mov r0, r7 */
/* @0x2935a4 bl 0xb6640 <strdup@plt> */
/* @0x2935a8 ldr r2, [sp, #0x20] */
/* @0x2935ac str r0, [r2] */
/* @0x2935b0 mov r0, r6 */
/* @0x2935b4 bl 0xb6640 <strdup@plt> */
/* @0x2935b8 ldr r3, [sp, #0x1c] */
/* @0x2935bc str r0, [r3] */
/* @0x2935c0 mov r0, r11 */
/* @0x2935c4 bl 0xb6640 <strdup@plt> */
/* @0x2935c8 ldr r2, [sp, #0x24] */
/* @0x2935cc str r0, [r2] */
/* @0x2935d0 mov r0, r10 */
/* @0x2935d4 bl 0xb6640 <strdup@plt> */
/* @0x2935d8 ldr r3, [sp, #0x2c] */
/* @0x2935dc ldr r2, [sp, #0x30] */
/* @0x2935e0 cmp r3, #0 */
/* @0x2935e4 cmpne r2, #0 */
/* @0x2935e8 ldr r3, [sp, #0x28] */
/* @0x2935ec str r0, [r3] */
/* @0x2935f0 bne 0x293738 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x3c4> */
/* @0x2935f4 ldr r3, [sp, #0x34] */
/* @0x2935f8 cmp r9, #0 */
/* @0x2935fc cmpne r3, #0 */
/* @0x293600 bne 0x29371c <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x3a8> */
/* @0x293604 ldr r3, [sp, #0x60] */
/* @0x293608 cmp r8, #0 */
/* @0x29360c cmpne r3, #0 */
/* @0x293610 bne 0x293700 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x38c> */
/* @0x293614 ldr r3, [sp, #0x64] */
/* @0x293618 cmp r7, #0 */
/* @0x29361c cmpne r3, #0 */
/* @0x293620 bne 0x2936e4 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x370> */
/* @0x293624 ldr r3, [sp, #0x68] */
/* @0x293628 cmp r6, #0 */
/* @0x29362c cmpne r3, #0 */
/* @0x293630 bne 0x2936c8 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x354> */
/* @0x293634 ldr r3, [sp, #0x6c] */
/* @0x293638 cmp r11, #0 */
/* @0x29363c cmpne r3, #0 */
/* @0x293640 bne 0x2936ac <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x338> */
/* @0x293644 ldr r3, [sp, #0x70] */
/* @0x293648 cmp r10, #0 */
/* @0x29364c cmpne r3, #0 */
/* @0x293650 beq 0x29366c <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x2f8> */
/* @0x293654 ldr r3, [r4] */
/* @0x293658 mov r2, r10 */
/* @0x29365c ldr r1, [sp, #0x70] */
/* @0x293660 mov r0, r4 */
/* @0x293664 ldr r3, [r3, #0x2a8] */
/* @0x293668 blx r3 */
/* @0x29366c mov r0, #68 */
/* @0x293670 bl 0x27c524 <_Znwj> */
/* @0x293674 ldr r3, [pc, #0xf8] */
/* @0x293678 mov r12, #0 */
/* @0x29367c mov r1, r12 */
/* @0x293680 mov r2, r12 */
/* @0x293684 ldr r3, [r5, r3] */
/* @0x293688 str r12, [sp] */
/* @0x29368c str r12, [sp, #0x4] */
/* @0x293690 str r12, [sp, #0x8] */
/* @0x293694 mov r4, r0 */
/* @0x293698 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b> */
/* @0x29369c mov r3, #7 */
/* @0x2936a0 str r3, [r4, #0xc] */
/* @0x2936a4 add sp, sp, #60 */
/* @0x2936a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2936ac ldr r3, [r4] */
/* @0x2936b0 mov r2, r11 */
/* @0x2936b4 ldr r1, [sp, #0x6c] */
/* @0x2936b8 mov r0, r4 */
/* @0x2936bc ldr r3, [r3, #0x2a8] */
/* @0x2936c0 blx r3 */
/* @0x2936c4 b 0x293644 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x2d0> */
/* @0x2936c8 ldr r3, [r4] */
/* @0x2936cc mov r2, r6 */
/* @0x2936d0 ldr r1, [sp, #0x68] */
/* @0x2936d4 mov r0, r4 */
/* @0x2936d8 ldr r3, [r3, #0x2a8] */
/* @0x2936dc blx r3 */
/* @0x2936e0 b 0x293634 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x2c0> */
/* @0x2936e4 ldr r3, [r4] */
/* @0x2936e8 mov r2, r7 */
/* @0x2936ec ldr r1, [sp, #0x64] */
/* @0x2936f0 mov r0, r4 */
/* @0x2936f4 ldr r3, [r3, #0x2a8] */
/* @0x2936f8 blx r3 */
/* @0x2936fc b 0x293624 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x2b0> */
/* @0x293700 ldr r3, [r4] */
/* @0x293704 mov r2, r8 */
/* @0x293708 ldr r1, [sp, #0x60] */
/* @0x29370c mov r0, r4 */
/* @0x293710 ldr r3, [r3, #0x2a8] */
/* @0x293714 blx r3 */
/* @0x293718 b 0x293614 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x2a0> */
/* @0x29371c ldr r3, [r4] */
/* @0x293720 mov r2, r9 */
/* @0x293724 ldr r1, [sp, #0x34] */
/* @0x293728 mov r0, r4 */
/* @0x29372c ldr r3, [r3, #0x2a8] */
/* @0x293730 blx r3 */
/* @0x293734 b 0x293604 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x290> */
/* @0x293738 ldr r3, [r4] */
/* @0x29373c mov r1, r2 */
/* @0x293740 mov r0, r4 */
/* @0x293744 ldr r2, [sp, #0x2c] */
/* @0x293748 ldr r3, [r3, #0x2a8] */
/* @0x29374c blx r3 */
/* @0x293750 b 0x2935f4 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x280> */
/* @0x293754 ldrheq lr, [r5], -r0 */
/* @0x293758 .word 0xfffffcbc */
/* @0x29375c .word 0xfffffcc0 */
/* @0x293760 .word 0xfffffd20 */
/* @0x293764 .word 0xfffffd24 */
/* @0x293768 .word 0xfffffd28 */
/* @0x29376c .word 0xfffffd2c */
/* @0x293770 .word 0xfffffd30 */
/* @0x293774 .word 0xfffffd34 */

/* ── FUNC 0x293778 · Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap · size=1192 · insn=296 */
/* @0x293778 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29377c mov r5, r0 */
/* @0x293780 sub sp, sp, #212 */
/* @0x293784 mov r11, r2 */
/* @0x293788 mov r10, r3 */
/* @0x29378c bl 0x290614 <setJNIEnv> */
/* @0x293790 ldr r3, [r5] */
/* @0x293794 mov r1, r10 */
/* @0x293798 mov r2, #0 */
/* @0x29379c mov r0, r5 */
/* @0x2937a0 ldr r3, [r3, #0x2a4] */
/* @0x2937a4 blx r3 */
/* @0x2937a8 ldr r3, [r5] */
/* @0x2937ac ldr r1, [sp, #0xf8] */
/* @0x2937b0 mov r2, #0 */
/* @0x2937b4 ldr r3, [r3, #0x2a4] */
/* @0x2937b8 mov r9, r0 */
/* @0x2937bc mov r0, r5 */
/* @0x2937c0 blx r3 */
/* @0x2937c4 ldr r3, [r5] */
/* @0x2937c8 ldr r1, [sp, #0xfc] */
/* @0x2937cc mov r2, #0 */
/* @0x2937d0 ldr r3, [r3, #0x2a4] */
/* @0x2937d4 mov r8, r0 */
/* @0x2937d8 mov r0, r5 */
/* @0x2937dc blx r3 */
/* @0x2937e0 ldr r3, [r5] */
/* @0x2937e4 ldr r1, [sp, #0x100] */
/* @0x2937e8 mov r2, #0 */
/* @0x2937ec ldr r3, [r3, #0x2a4] */
/* @0x2937f0 str r0, [sp, #0xb8] */
/* @0x2937f4 mov r0, r5 */
/* @0x2937f8 blx r3 */
/* @0x2937fc ldr r3, [r5] */
/* @0x293800 ldr r1, [sp, #0x104] */
/* @0x293804 mov r2, #0 */
/* @0x293808 ldr r3, [r3, #0x2a4] */
/* @0x29380c str r0, [sp, #0xbc] */
/* @0x293810 mov r0, r5 */
/* @0x293814 blx r3 */
/* @0x293818 ldr r3, [r5] */
/* @0x29381c ldr r1, [sp, #0x108] */
/* @0x293820 mov r2, #0 */
/* @0x293824 ldr r3, [r3, #0x2a4] */
/* @0x293828 str r0, [sp, #0xc0] */
/* @0x29382c mov r0, r5 */
/* @0x293830 blx r3 */
/* @0x293834 ldr r3, [r5] */
/* @0x293838 ldr r1, [sp, #0x10c] */
/* @0x29383c mov r2, #0 */
/* @0x293840 ldr r3, [r3, #0x2a4] */
/* @0x293844 str r0, [sp, #0xc4] */
/* @0x293848 mov r0, r5 */
/* @0x29384c blx r3 */
/* @0x293850 ldr r3, [r5] */
/* @0x293854 ldr r1, [sp, #0x110] */
/* @0x293858 mov r2, #0 */
/* @0x29385c ldr r3, [r3, #0x2a4] */
/* @0x293860 str r0, [sp, #0xc8] */
/* @0x293864 mov r0, r5 */
/* @0x293868 blx r3 */
/* @0x29386c ldr r3, [r5] */
/* @0x293870 ldr r1, [sp, #0x114] */
/* @0x293874 mov r2, #0 */
/* @0x293878 ldr r3, [r3, #0x2a4] */
/* @0x29387c mov r7, r0 */
/* @0x293880 mov r0, r5 */
/* @0x293884 blx r3 */
/* @0x293888 ldr r3, [r5] */
/* @0x29388c ldr r1, [sp, #0x11c] */
/* @0x293890 mov r2, #0 */
/* @0x293894 ldr r3, [r3, #0x2a4] */
/* @0x293898 mov r6, r0 */
/* @0x29389c mov r0, r5 */
/* @0x2938a0 blx r3 */
/* @0x2938a4 ldr r3, [r5] */
/* @0x2938a8 ldr r1, [sp, #0x118] */
/* @0x2938ac mov r2, #0 */
/* @0x2938b0 ldr r3, [r3, #0x2a4] */
/* @0x2938b4 mov r4, r0 */
/* @0x2938b8 mov r0, r5 */
/* @0x2938bc blx r3 */
/* @0x2938c0 ldr r12, [sp, #0xb8] */
/* @0x2938c4 ldr r1, [pc, #0x324] */
/* @0x2938c8 vmov s15, r11 */
/* @0x2938cc ldr lr, [pc, #0x320] */
/* @0x2938d0 str r12, [sp, #0x30] */
/* @0x2938d4 add r1, pc, r1 */
/* @0x2938d8 ldr r12, [sp, #0xbc] */
/* @0x2938dc vcvt.f64.s32 d7, s15 */
/* @0x2938e0 str r1, [sp, #0x14] */
/* @0x2938e4 add lr, pc, lr */
/* @0x2938e8 ldr r1, [pc, #0x308] */
/* @0x2938ec str r12, [sp, #0x40] */
/* @0x2938f0 ldr r12, [sp, #0xc0] */
/* @0x2938f4 add r1, pc, r1 */
/* @0x2938f8 str lr, [sp, #0x4] */
/* @0x2938fc str r1, [sp, #0x44] */
/* @0x293900 str r12, [sp, #0x50] */
/* @0x293904 ldr r12, [sp, #0xc4] */
/* @0x293908 ldr r11, [pc, #0x2ec] */
/* @0x29390c ldr lr, [pc, #0x2ec] */
/* @0x293910 str r12, [sp, #0x60] */
/* @0x293914 add r11, pc, r11 */
/* @0x293918 ldr r12, [sp, #0xc8] */
/* @0x29391c add lr, pc, lr */
/* @0x293920 ldr r1, [pc, #0x2dc] */
/* @0x293924 str r11, [sp, #0x24] */
/* @0x293928 str lr, [sp, #0x34] */
/* @0x29392c add r1, pc, r1 */
/* @0x293930 ldr r11, [pc, #0x2d0] */
/* @0x293934 str r1, [sp, #0x74] */
/* @0x293938 ldr lr, [pc, #0x2cc] */
/* @0x29393c add r11, pc, r11 */
/* @0x293940 ldr r1, [pc, #0x2c8] */
/* @0x293944 str r12, [sp, #0x70] */
/* @0x293948 add lr, pc, lr */
/* @0x29394c str r11, [sp, #0x54] */
/* @0x293950 add r1, pc, r1 */
/* @0x293954 str lr, [sp, #0x64] */
/* @0x293958 str r1, [sp, #0xa4] */
/* @0x29395c ldr r11, [pc, #0x2b0] */
/* @0x293960 ldr lr, [pc, #0x2b0] */
/* @0x293964 ldr r1, [pc, #0x2b0] */
/* @0x293968 add r11, pc, r11 */
/* @0x29396c vmov r2, r3, d7 */
/* @0x293970 add lr, pc, lr */
/* @0x293974 str r0, [sp, #0xcc] */
/* @0x293978 vldr d7, [pc, #616] */
/* @0x29397c ldr r12, [sp, #0xcc] */
/* @0x293980 vstr d7, [sp, #8] */
/* @0x293984 str r11, [sp, #0x84] */
/* @0x293988 vstr d7, [sp, #24] */
/* @0x29398c str lr, [sp, #0x94] */
/* @0x293990 vstr d7, [sp, #40] */
/* @0x293994 str r12, [sp, #0xa0] */
/* @0x293998 mov lr, #0 */
/* @0x29399c vstr d7, [sp, #56] */
/* @0x2939a0 str lr, [sp] */
/* @0x2939a4 mov r0, #12 */
/* @0x2939a8 str r9, [sp, #0x10] */
/* @0x2939ac str r8, [sp, #0x20] */
/* @0x2939b0 add r1, pc, r1 */
/* @0x2939b4 str r7, [sp, #0x80] */
/* @0x2939b8 str r6, [sp, #0x90] */
/* @0x2939bc vstr d7, [sp, #72] */
/* @0x2939c0 vstr d7, [sp, #88] */
/* @0x2939c4 vstr d7, [sp, #104] */
/* @0x2939c8 vstr d7, [sp, #120] */
/* @0x2939cc vstr d7, [sp, #136] */
/* @0x2939d0 vstr d7, [sp, #152] */
/* @0x2939d4 vstr d7, [sp, #168] */
/* @0x2939d8 str r4, [sp, #0xb0] */
/* @0x2939dc bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x2939e0 cmp r9, #0 */
/* @0x2939e4 cmpne r10, #0 */
/* @0x2939e8 mov r11, r0 */
/* @0x2939ec bne 0x293bc8 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x450> */
/* @0x2939f0 ldr r12, [sp, #0xf8] */
/* @0x2939f4 cmp r8, #0 */
/* @0x2939f8 cmpne r12, #0 */
/* @0x2939fc bne 0x293bac <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x434> */
/* @0x293a00 ldr r12, [sp, #0xb8] */
/* @0x293a04 ldr r2, [sp, #0xfc] */
/* @0x293a08 cmp r12, #0 */
/* @0x293a0c cmpne r2, #0 */
/* @0x293a10 bne 0x293b90 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x418> */
/* @0x293a14 ldr r12, [sp, #0xbc] */
/* @0x293a18 ldr r2, [sp, #0x100] */
/* @0x293a1c cmp r12, #0 */
/* @0x293a20 cmpne r2, #0 */
/* @0x293a24 bne 0x293b74 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x3fc> */
/* @0x293a28 ldr r12, [sp, #0xc0] */
/* @0x293a2c ldr r2, [sp, #0x104] */
/* @0x293a30 cmp r12, #0 */
/* @0x293a34 cmpne r2, #0 */
/* @0x293a38 bne 0x293b58 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x3e0> */
/* @0x293a3c ldr r12, [sp, #0xc4] */
/* @0x293a40 ldr r2, [sp, #0x108] */
/* @0x293a44 cmp r12, #0 */
/* @0x293a48 cmpne r2, #0 */
/* @0x293a4c bne 0x293b3c <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x3c4> */
/* @0x293a50 ldr r12, [sp, #0xc8] */
/* @0x293a54 ldr r2, [sp, #0x10c] */
/* @0x293a58 cmp r12, #0 */
/* @0x293a5c cmpne r2, #0 */
/* @0x293a60 bne 0x293b20 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x3a8> */
/* @0x293a64 ldr r12, [sp, #0x110] */
/* @0x293a68 cmp r7, #0 */
/* @0x293a6c cmpne r12, #0 */
/* @0x293a70 bne 0x293b04 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x38c> */
/* @0x293a74 ldr r12, [sp, #0x114] */
/* @0x293a78 cmp r6, #0 */
/* @0x293a7c cmpne r12, #0 */
/* @0x293a80 bne 0x293ae8 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x370> */
/* @0x293a84 ldr r12, [sp, #0xcc] */
/* @0x293a88 ldr r2, [sp, #0x118] */
/* @0x293a8c cmp r12, #0 */
/* @0x293a90 cmpne r2, #0 */
/* @0x293a94 bne 0x293acc <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x354> */
/* @0x293a98 ldr r12, [sp, #0x11c] */
/* @0x293a9c cmp r4, #0 */
/* @0x293aa0 cmpne r12, #0 */
/* @0x293aa4 beq 0x293ac0 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x348> */
/* @0x293aa8 ldr r3, [r5] */
/* @0x293aac mov r1, r12 */
/* @0x293ab0 mov r2, r4 */
/* @0x293ab4 mov r0, r5 */
/* @0x293ab8 ldr r3, [r3, #0x2a8] */
/* @0x293abc blx r3 */
/* @0x293ac0 mov r0, r11 */
/* @0x293ac4 add sp, sp, #212 */
/* @0x293ac8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x293acc ldr r3, [r5] */
/* @0x293ad0 mov r1, r2 */
/* @0x293ad4 mov r0, r5 */
/* @0x293ad8 mov r2, r12 */
/* @0x293adc ldr r3, [r3, #0x2a8] */
/* @0x293ae0 blx r3 */
/* @0x293ae4 b 0x293a98 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x320> */
/* @0x293ae8 ldr r3, [r5] */
/* @0x293aec mov r1, r12 */
/* @0x293af0 mov r2, r6 */
/* @0x293af4 mov r0, r5 */
/* @0x293af8 ldr r3, [r3, #0x2a8] */
/* @0x293afc blx r3 */
/* @0x293b00 b 0x293a84 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x30c> */
/* @0x293b04 ldr r3, [r5] */
/* @0x293b08 mov r1, r12 */
/* @0x293b0c mov r2, r7 */
/* @0x293b10 mov r0, r5 */
/* @0x293b14 ldr r3, [r3, #0x2a8] */
/* @0x293b18 blx r3 */
/* @0x293b1c b 0x293a74 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x2fc> */
/* @0x293b20 ldr r3, [r5] */
/* @0x293b24 mov r1, r2 */
/* @0x293b28 mov r0, r5 */
/* @0x293b2c mov r2, r12 */
/* @0x293b30 ldr r3, [r3, #0x2a8] */
/* @0x293b34 blx r3 */
/* @0x293b38 b 0x293a64 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x2ec> */
/* @0x293b3c ldr r3, [r5] */
/* @0x293b40 mov r1, r2 */
/* @0x293b44 mov r0, r5 */
/* @0x293b48 mov r2, r12 */
/* @0x293b4c ldr r3, [r3, #0x2a8] */
/* @0x293b50 blx r3 */
/* @0x293b54 b 0x293a50 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x2d8> */
/* @0x293b58 ldr r3, [r5] */
/* @0x293b5c mov r1, r2 */
/* @0x293b60 mov r0, r5 */
/* @0x293b64 mov r2, r12 */
/* @0x293b68 ldr r3, [r3, #0x2a8] */
/* @0x293b6c blx r3 */
/* @0x293b70 b 0x293a3c <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x2c4> */
/* @0x293b74 ldr r3, [r5] */
/* @0x293b78 mov r1, r2 */
/* @0x293b7c mov r0, r5 */
/* @0x293b80 mov r2, r12 */
/* @0x293b84 ldr r3, [r3, #0x2a8] */
/* @0x293b88 blx r3 */
/* @0x293b8c b 0x293a28 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x2b0> */
/* @0x293b90 ldr r3, [r5] */
/* @0x293b94 mov r1, r2 */
/* @0x293b98 mov r0, r5 */
/* @0x293b9c mov r2, r12 */
/* @0x293ba0 ldr r3, [r3, #0x2a8] */
/* @0x293ba4 blx r3 */
/* @0x293ba8 b 0x293a14 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x29c> */
/* @0x293bac ldr r3, [r5] */
/* @0x293bb0 mov r1, r12 */
/* @0x293bb4 mov r2, r8 */
/* @0x293bb8 mov r0, r5 */
/* @0x293bbc ldr r3, [r3, #0x2a8] */
/* @0x293bc0 blx r3 */
/* @0x293bc4 b 0x293a00 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x288> */
/* @0x293bc8 ldr r3, [r5] */
/* @0x293bcc mov r1, r10 */
/* @0x293bd0 mov r2, r9 */
/* @0x293bd4 mov r0, r5 */
/* @0x293bd8 ldr r3, [r3, #0x2a8] */
/* @0x293bdc blx r3 */
/* @0x293be0 b 0x2939f0 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x278> */
/* @0x293be4 nop */
/* @0x293bf0 andeq r6, r11, r8, lsr r0 */
/* @0x293bf4 andeq r6, r11, r0, lsl r0 */
/* @0x293bf8 andeq r6, r11, r8, rrx */
/* @0x293bfc andeq r6, r11, r0, lsl r0 */
/* @0x293c00 andeq r6, r11, r0, lsr #32 */
/* @0x293c04 andeq r6, r11, r0, lsl #1 */
/* @0x293c08 andeq r6, r11, r8, lsr r0 */
/* @0x293c0c andeq r6, r11, r8, asr #32 */
/* @0x293c10 andeq r6, r11, r12, lsl #1 */
/* @0x293c14 andeq r6, r11, r12, asr r0 */
/* @0x293c18 andeq r6, r11, r8, lsl #1 */
/* @0x293c1c andeq r5, r11, r12, lsr #30 */

/* ── FUNC 0x293c20 · Java_com_yoyogames_runner_RunnerJNILib_DsMapAddDouble · size=112 · insn=28 */
/* @0x293c20 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x293c24 mov r6, r0 */
/* @0x293c28 mov r7, r3 */
/* @0x293c2c mov r9, r2 */
/* @0x293c30 ldrd r4, r5, [sp, #32] */
/* @0x293c34 bl 0x290614 <setJNIEnv> */
/* @0x293c38 ldr r3, [r6] */
/* @0x293c3c mov r1, r7 */
/* @0x293c40 mov r2, #0 */
/* @0x293c44 mov r0, r6 */
/* @0x293c48 ldr r3, [r3, #0x2a4] */
/* @0x293c4c blx r3 */
/* @0x293c50 mov r2, r4 */
/* @0x293c54 mov r3, r5 */
/* @0x293c58 mov r8, r0 */
/* @0x293c5c mov r0, r9 */
/* @0x293c60 mov r1, r8 */
/* @0x293c64 bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd> */
/* @0x293c68 cmp r8, #0 */
/* @0x293c6c cmpne r7, #0 */
/* @0x293c70 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x293c74 ldr r3, [r6] */
/* @0x293c78 mov r1, r7 */
/* @0x293c7c mov r2, r8 */
/* @0x293c80 mov r0, r6 */
/* @0x293c84 ldr r3, [r3, #0x2a8] */
/* @0x293c88 blx r3 */
/* @0x293c8c pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x293c90 · Java_com_yoyogames_runner_RunnerJNILib_DsMapAddString · size=176 · insn=44 */
/* @0x293c90 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x293c94 mov r4, r0 */
/* @0x293c98 mov r8, r3 */
/* @0x293c9c mov r9, r2 */
/* @0x293ca0 ldr r5, [sp, #0x20] */
/* @0x293ca4 bl 0x290614 <setJNIEnv> */
/* @0x293ca8 ldr r3, [r4] */
/* @0x293cac mov r1, r8 */
/* @0x293cb0 mov r2, #0 */
/* @0x293cb4 mov r0, r4 */
/* @0x293cb8 ldr r3, [r3, #0x2a4] */
/* @0x293cbc blx r3 */
/* @0x293cc0 ldr r3, [r4] */
/* @0x293cc4 mov r1, r5 */
/* @0x293cc8 mov r2, #0 */
/* @0x293ccc ldr r3, [r3, #0x2a4] */
/* @0x293cd0 mov r7, r0 */
/* @0x293cd4 mov r0, r4 */
/* @0x293cd8 blx r3 */
/* @0x293cdc mov r1, r7 */
/* @0x293ce0 mov r6, r0 */
/* @0x293ce4 mov r0, r9 */
/* @0x293ce8 mov r2, r6 */
/* @0x293cec bl 0x104f64 <_Z19F_DsMapAdd_InternaliPcS_> */
/* @0x293cf0 cmp r7, #0 */
/* @0x293cf4 cmpne r8, #0 */
/* @0x293cf8 bne 0x293d24 <Java_com_yoyogames_runner_RunnerJNILib_DsMapAddString+0x94> */
/* @0x293cfc cmp r6, #0 */
/* @0x293d00 cmpne r5, #0 */
/* @0x293d04 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x293d08 ldr r3, [r4] */
/* @0x293d0c mov r1, r5 */
/* @0x293d10 mov r2, r6 */
/* @0x293d14 mov r0, r4 */
/* @0x293d18 ldr r3, [r3, #0x2a8] */
/* @0x293d1c blx r3 */
/* @0x293d20 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x293d24 ldr r3, [r4] */
/* @0x293d28 mov r1, r8 */
/* @0x293d2c mov r2, r7 */
/* @0x293d30 mov r0, r4 */
/* @0x293d34 ldr r3, [r3, #0x2a8] */
/* @0x293d38 blx r3 */
/* @0x293d3c b 0x293cfc <Java_com_yoyogames_runner_RunnerJNILib_DsMapAddString+0x6c> */

/* ── FUNC 0x293d40 · Java_com_yoyogames_runner_RunnerJNILib_CreateAsynEventWithDSMap · size=32 · insn=8 */
/* @0x293d40 push {r3, r4, r5, lr} */
/* @0x293d44 mov r4, r2 */
/* @0x293d48 mov r5, r3 */
/* @0x293d4c bl 0x290614 <setJNIEnv> */
/* @0x293d50 mov r0, r4 */
/* @0x293d54 mov r1, r5 */
/* @0x293d58 pop {r3, r4, r5, lr} */
/* @0x293d5c b 0x18da04 <_Z24CreateAsynEventWithDSMapii> */
