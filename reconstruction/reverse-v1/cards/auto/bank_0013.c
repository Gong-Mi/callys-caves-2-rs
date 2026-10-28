/* libyoyo.so 覆盖卡组 0013
 * 函数 0xd34ac..0xd5560，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xd34ac · GCThreadFunc(CThread*) · size=732 · insn=183 */
/* @0xd34ac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd34b0 vpush {d8, d9} */
/* @0xd34b4 sub sp, sp, #60 */
/* @0xd34b8 ldr r9, [pc, #0x294] */
/* @0xd34bc mvn r4, #0 */
/* @0xd34c0 mvn r5, #0 */
/* @0xd34c4 mov r10, r0 */
/* @0xd34c8 strd r4, r5, [sp, #24] */
/* @0xd34cc add r9, pc, r9 */
/* @0xd34d0 strd r4, r5, [sp, #40] */
/* @0xd34d4 b 0xd34fc <_Z12GCThreadFuncP7CThread+0x50> */
/* @0xd34d8 ldr r2, [pc, #0x278] */
/* @0xd34dc ldr r3, [pc, #0x278] */
/* @0xd34e0 ldr r2, [r9, r2] */
/* @0xd34e4 str r2, [sp, #0xc] */
/* @0xd34e8 ldr r3, [r9, r3] */
/* @0xd34ec ldr r2, [r2] */
/* @0xd34f0 ldr r3, [r3] */
/* @0xd34f4 cmp r2, r3 */
/* @0xd34f8 blt 0xd3518 <_Z12GCThreadFuncP7CThread+0x6c> */
/* @0xd34fc ldrb r3, [r10, #0x8] */
/* @0xd3500 cmp r3, #0 */
/* @0xd3504 beq 0xd34d8 <_Z12GCThreadFuncP7CThread+0x2c> */
/* @0xd3508 mov r0, #0 */
/* @0xd350c add sp, sp, #60 */
/* @0xd3510 vpop {d8, d9} */
/* @0xd3514 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd3518 bl 0x215148 <Timing_Time> */
/* @0xd351c strd r0, r1, [sp, #32] */
/* @0xd3520 mvn r0, #0 */
/* @0xd3524 mvn r1, #0 */
/* @0xd3528 cmp r5, r1 */
/* @0xd352c cmpeq r4, r0 */
/* @0xd3530 beq 0xd3568 <_Z12GCThreadFuncP7CThread+0xbc> */
/* @0xd3534 ldrd r2, r3, [sp, #32] */
/* @0xd3538 movw r0, #0x9c40 */
/* @0xd353c mov r1, #0 */
/* @0xd3540 subs r4, r2, r4 */
/* @0xd3544 sbc r5, r3, r5 */
/* @0xd3548 ldrd r2, r3, [sp, #32] */
/* @0xd354c cmp r0, r4 */
/* @0xd3550 sbcs r1, r1, r5 */
/* @0xd3554 movlt r5, #0 */
/* @0xd3558 movwlt r4, #0x9c40 */
/* @0xd355c adds r2, r2, r4 */
/* @0xd3560 adc r3, r3, r5 */
/* @0xd3564 strd r2, r3, [sp, #40] */
/* @0xd3568 ldr r3, [pc, #0x1f0] */
/* @0xd356c ldr r11, [r9, r3] */
/* @0xd3570 ldr r3, [r11] */
/* @0xd3574 cmp r3, #0 */
/* @0xd3578 beq 0xd365c <_Z12GCThreadFuncP7CThread+0x1b0> */
/* @0xd357c ldr r12, [pc, #0x1e0] */
/* @0xd3580 mov r5, #0 */
/* @0xd3584 ldr r3, [pc, #0x1dc] */
/* @0xd3588 mov r4, r5 */
/* @0xd358c ldr lr, [pc, #0x1d8] */
/* @0xd3590 ldr r12, [r9, r12] */
/* @0xd3594 ldr r0, [pc, #0x1d4] */
/* @0xd3598 ldr r2, [pc, #0x1d4] */
/* @0xd359c ldr r7, [r9, r3] */
/* @0xd35a0 ldr r8, [r9, lr] */
/* @0xd35a4 ldr r3, [pc, #0x1cc] */
/* @0xd35a8 str r12, [sp, #0x10] */
/* @0xd35ac ldr r12, [r9, r0] */
/* @0xd35b0 ldr r2, [r9, r2] */
/* @0xd35b4 ldr r1, [r7] */
/* @0xd35b8 str r2, [sp, #0x14] */
/* @0xd35bc ldr r6, [r9, r3] */
/* @0xd35c0 str r10, [sp, #0x34] */
/* @0xd35c4 mov r10, r8 */
/* @0xd35c8 str r9, [sp, #0x30] */
/* @0xd35cc mov r9, r12 */
/* @0xd35d0 b 0xd3604 <_Z12GCThreadFuncP7CThread+0x158> */
/* @0xd35d4 ldr r12, [r2] */
/* @0xd35d8 add r4, r4, #1 */
/* @0xd35dc ldr r0, [r11] */
/* @0xd35e0 mov r5, r4 */
/* @0xd35e4 str r3, [r12, #0x8] */
/* @0xd35e8 cmp r4, r0 */
/* @0xd35ec ldr r3, [r2] */
/* @0xd35f0 mov r0, #0 */
/* @0xd35f4 str r0, [r3, #0xc] */
/* @0xd35f8 ldr r3, [r2] */
/* @0xd35fc str r3, [r6] */
/* @0xd3600 bhs 0xd3654 <_Z12GCThreadFuncP7CThread+0x1a8> */
/* @0xd3604 ldr r2, [sp, #0x14] */
/* @0xd3608 mov r3, r9 */
/* @0xd360c ldr r0, [r1, r5, lsl #2] */
/* @0xd3610 mov r1, r10 */
/* @0xd3614 lsl r8, r5, #2 */
/* @0xd3618 str r2, [sp] */
/* @0xd361c ldr r2, [sp, #0x10] */
/* @0xd3620 bl 0x198dac <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_> */
/* @0xd3624 ldr r3, [r6] */
/* @0xd3628 ldr r1, [r7] */
/* @0xd362c cmp r3, #0 */
/* @0xd3630 addne r2, r1, r8 */
/* @0xd3634 bne 0xd35d4 <_Z12GCThreadFuncP7CThread+0x128> */
/* @0xd3638 ldr r12, [r1, r5, lsl #2] */
/* @0xd363c add r2, r1, r8 */
/* @0xd3640 ldr r0, [pc, #0x134] */
/* @0xd3644 ldr r5, [sp, #0x30] */
/* @0xd3648 ldr r0, [r5, r0] */
/* @0xd364c str r12, [r0] */
/* @0xd3650 b 0xd35d4 <_Z12GCThreadFuncP7CThread+0x128> */
/* @0xd3654 ldr r10, [sp, #0x34] */
/* @0xd3658 ldr r9, [sp, #0x30] */
/* @0xd365c ldrd r4, r5, [sp, #40] */
/* @0xd3660 mvn r0, #0 */
/* @0xd3664 mvn r1, #0 */
/* @0xd3668 cmp r5, r1 */
/* @0xd366c cmpeq r4, r0 */
/* @0xd3670 ldr r4, [sp, #0xc] */
/* @0xd3674 ldr r3, [r4] */
/* @0xd3678 add r3, r3, #1 */
/* @0xd367c str r3, [r4] */
/* @0xd3680 beq 0xd373c <_Z12GCThreadFuncP7CThread+0x290> */
/* @0xd3684 bl 0x215148 <Timing_Time> */
/* @0xd3688 ldrd r4, r5, [sp, #24] */
/* @0xd368c mvn r2, #0 */
/* @0xd3690 mvn r3, #0 */
/* @0xd3694 cmp r5, r3 */
/* @0xd3698 cmpeq r4, r2 */
/* @0xd369c beq 0xd3728 <_Z12GCThreadFuncP7CThread+0x27c> */
/* @0xd36a0 ldrd r4, r5, [sp, #40] */
/* @0xd36a4 subs r4, r4, r0 */
/* @0xd36a8 sbc r5, r5, r1 */
/* @0xd36ac mov r0, r4 */
/* @0xd36b0 mov r1, r5 */
/* @0xd36b4 bl 0x319164 <__floatdidf> */
/* @0xd36b8 ldr r3, [pc, #0xc0] */
/* @0xd36bc ldr r3, [r9, r3] */
/* @0xd36c0 vldr d9, [r3] */
/* @0xd36c4 vmov d5, r0, r1 */
/* @0xd36c8 ldrd r0, r1, [sp, #24] */
/* @0xd36cc vmul.f64 d9, d5, d9 */
/* @0xd36d0 bl 0x319164 <__floatdidf> */
/* @0xd36d4 vmov d8, r0, r1 */
/* @0xd36d8 vcmpe.f64 d9, d8 */
/* @0xd36dc vmrs APSR_nzcv, fpscr */
/* @0xd36e0 bmi 0xd3744 <_Z12GCThreadFuncP7CThread+0x298> */
/* @0xd36e4 ldrd r0, r1, [sp, #24] */
/* @0xd36e8 subs r0, r4, r0 */
/* @0xd36ec sbc r1, r5, r1 */
/* @0xd36f0 bl 0x319164 <__floatdidf> */
/* @0xd36f4 vmov.f64 d6, d8 */
/* @0xd36f8 ldr r3, [pc, #0x84] */
/* @0xd36fc ldr r3, [r9, r3] */
/* @0xd3700 vldr d7, [r3] */
/* @0xd3704 vmov d5, r0, r1 */
/* @0xd3708 vmla.f64 d6, d5, d7 */
/* @0xd370c vmov r0, r1, d6 */
/* @0xd3710 bl 0x3194a0 <__fixdfdi> */
/* @0xd3714 strd r0, r1, [sp, #24] */
/* @0xd3718 ldrd r4, r5, [sp, #24] */
/* @0xd371c cmp r4, #0 */
/* @0xd3720 sbcs r5, r5, #0 */
/* @0xd3724 bge 0xd3734 <_Z12GCThreadFuncP7CThread+0x288> */
/* @0xd3728 mov r4, #0 */
/* @0xd372c mov r5, #0 */
/* @0xd3730 strd r4, r5, [sp, #24] */
/* @0xd3734 ldrd r0, r1, [sp, #24] */
/* @0xd3738 bl 0x212da4 <Timing_Wait> */
/* @0xd373c ldrd r4, r5, [sp, #32] */
/* @0xd3740 b 0xd34fc <_Z12GCThreadFuncP7CThread+0x50> */
/* @0xd3744 vmov r0, r1, d9 */
/* @0xd3748 bl 0x3194a0 <__fixdfdi> */
/* @0xd374c strd r0, r1, [sp, #24] */
/* @0xd3750 b 0xd3718 <_Z12GCThreadFuncP7CThread+0x26c> */
/* @0xd3754 eorseq lr, r1, r4, lsl #15 */
/* @0xd3758 .word 0xffffbf7c */
/* @0xd375c .word 0xffffbf80 */
/* @0xd3760 .word 0xffffbf84 */
/* @0xd3764 .word 0xffffbf88 */
/* @0xd3768 .word 0xffffbf8c */
/* @0xd376c .word 0xffffbf90 */
/* @0xd3770 .word 0xffffbf94 */
/* @0xd3774 .word 0xffffbf98 */
/* @0xd3778 .word 0xffffbf9c */
/* @0xd377c .word 0xffffbfa0 */
/* @0xd3780 .word 0xffffbfa4 */
/* @0xd3784 .word 0xffffbfa8 */

/* ── FUNC 0xd3788 · TErrStreamConsole::Output(char const*, ...) · size=184 · insn=46 */
/* @0xd3788 push {r1, r2, r3} */
/* @0xd378c mov r1, #16384 */
/* @0xd3790 push {r4, r5, r6, r7, lr} */
/* @0xd3794 sub sp, sp, #16 */
/* @0xd3798 ldr r4, [pc, #0x98] */
/* @0xd379c add r12, sp, #40 */
/* @0xd37a0 ldr r2, [sp, #0x24] */
/* @0xd37a4 mov r5, r0 */
/* @0xd37a8 ldr r4, [pc, r4] */
/* @0xd37ac mov r3, r12 */
/* @0xd37b0 str r12, [sp, #0xc] */
/* @0xd37b4 mov r0, r4 */
/* @0xd37b8 bl 0xb6610 <vsnprintf@plt> */
/* @0xd37bc ldr r6, [r5, #0x8] */
/* @0xd37c0 mov r0, r6 */
/* @0xd37c4 bl 0xb6538 <strlen@plt> */
/* @0xd37c8 mov r7, r0 */
/* @0xd37cc mov r0, r4 */
/* @0xd37d0 bl 0xb6538 <strlen@plt> */
/* @0xd37d4 ldr r2, [r5, #0x4] */
/* @0xd37d8 add r7, r7, r0 */
/* @0xd37dc mov r3, r0 */
/* @0xd37e0 add r7, r7, #2 */
/* @0xd37e4 cmp r7, r2 */
/* @0xd37e8 blo 0xd381c <_ZN17TErrStreamConsole6OutputEPKcz+0x94> */
/* @0xd37ec add r2, r2, #1024 */
/* @0xd37f0 mov r0, r6 */
/* @0xd37f4 add r1, r2, r3 */
/* @0xd37f8 mov r2, #0 */
/* @0xd37fc str r1, [r5, #0x4] */
/* @0xd3800 movw r3, #0x213 */
/* @0xd3804 str r2, [sp] */
/* @0xd3808 ldr r2, [pc, #0x2c] */
/* @0xd380c add r2, pc, r2 */
/* @0xd3810 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xd3814 mov r6, r0 */
/* @0xd3818 str r0, [r5, #0x8] */
/* @0xd381c mov r0, r6 */
/* @0xd3820 mov r1, r4 */
/* @0xd3824 bl 0xb6628 <strcat@plt> */
/* @0xd3828 add sp, sp, #16 */
/* @0xd382c pop {r4, r5, r6, r7, lr} */
/* @0xd3830 add sp, sp, #12 */
/* @0xd3834 bx lr */
/* @0xd3838 eorseq r10, r1, r4, asr r4 */
/* @0xd383c eoreq lr, r5, r0, ror pc */

/* ── FUNC 0xd3840 · DoPopEnv(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=296 · insn=74 */
/* @0xd3840 ubfx r2, r0, #0x10, #0x8 */
/* @0xd3844 cmp r2, #240 */
/* @0xd3848 push {r4, lr} */
/* @0xd384c sub sp, sp, #8 */
/* @0xd3850 beq 0xd38ac <_Z8DoPopEnvjPhPKhP6VMExec+0x6c> */
/* @0xd3854 ldr r2, [r1] */
/* @0xd3858 cmn r2, #1 */
/* @0xd385c beq 0xd38f4 <_Z8DoPopEnvjPhPKhP6VMExec+0xb4> */
/* @0xd3860 cmp r2, #0 */
/* @0xd3864 add r1, r1, #4 */
/* @0xd3868 beq 0xd3928 <_Z8DoPopEnvjPhPKhP6VMExec+0xe8> */
/* @0xd386c ldr r4, [r3, #0x44] */
/* @0xd3870 lsl r0, r0, #9 */
/* @0xd3874 str r2, [r3, #0x14] */
/* @0xd3878 sub r4, r4, #4 */
/* @0xd387c ldr r12, [r3, #0x5c] */
/* @0xd3880 add r0, r4, r0, asr #7 */
/* @0xd3884 str r0, [r3, #0x44] */
/* @0xd3888 add r2, r0, #3 */
/* @0xd388c cmp r0, #0 */
/* @0xd3890 movlt r0, r2 */
/* @0xd3894 asr r0, r0, #2 */
/* @0xd3898 ldr r2, [r12, r0, lsl #2] */
/* @0xd389c mov r0, r1 */
/* @0xd38a0 str r2, [r3, #0x48] */
/* @0xd38a4 add sp, sp, #8 */
/* @0xd38a8 pop {r4, pc} */
/* @0xd38ac ldr r0, [r1] */
/* @0xd38b0 cmn r0, #1 */
/* @0xd38b4 bne 0xd38c4 <_Z8DoPopEnvjPhPKhP6VMExec+0x84> */
/* @0xd38b8 b 0xd3948 <_Z8DoPopEnvjPhPKhP6VMExec+0x108> */
/* @0xd38bc ldr r0, [r1, #0x4] */
/* @0xd38c0 mov r1, r2 */
/* @0xd38c4 cmp r0, #0 */
/* @0xd38c8 add r2, r1, #4 */
/* @0xd38cc mov r0, r2 */
/* @0xd38d0 bne 0xd38bc <_Z8DoPopEnvjPhPKhP6VMExec+0x7c> */
/* @0xd38d4 ldr r2, [r0] */
/* @0xd38d8 add r1, r0, #8 */
/* @0xd38dc str r2, [r3, #0x18] */
/* @0xd38e0 ldr r2, [r0, #0x4] */
/* @0xd38e4 mov r0, r1 */
/* @0xd38e8 str r2, [r3, #0x14] */
/* @0xd38ec add sp, sp, #8 */
/* @0xd38f0 pop {r4, pc} */
/* @0xd38f4 ldr r12, [r1, #0x4] */
/* @0xd38f8 ldr r4, [r1, #0x8] */
/* @0xd38fc ldr r2, [r12, #-0x4]! */
/* @0xd3900 cmp r2, #0 */
/* @0xd3904 str r12, [r1, #0x4] */
/* @0xd3908 bne 0xd386c <_Z8DoPopEnvjPhPKhP6VMExec+0x2c> */
/* @0xd390c mov r0, r4 */
/* @0xd3910 add r1, r1, #12 */
/* @0xd3914 str r3, [sp] */
/* @0xd3918 str r1, [sp, #0x4] */
/* @0xd391c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd3920 ldr r1, [sp, #0x4] */
/* @0xd3924 ldr r3, [sp] */
/* @0xd3928 ldr r2, [r1] */
/* @0xd392c add r1, r1, #8 */
/* @0xd3930 str r2, [r3, #0x18] */
/* @0xd3934 ldr r2, [r1, #-0x4] */
/* @0xd3938 mov r0, r1 */
/* @0xd393c str r2, [r3, #0x14] */
/* @0xd3940 add sp, sp, #8 */
/* @0xd3944 pop {r4, pc} */
/* @0xd3948 ldr r0, [r1, #0x8] */
/* @0xd394c str r1, [sp, #0x4] */
/* @0xd3950 str r3, [sp] */
/* @0xd3954 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd3958 ldr r1, [sp, #0x4] */
/* @0xd395c ldr r3, [sp] */
/* @0xd3960 add r0, r1, #12 */
/* @0xd3964 b 0xd38d4 <_Z8DoPopEnvjPhPKhP6VMExec+0x94> */

/* ── FUNC 0xd3968 · PushContextStack(YYObjectBase*) · size=204 · insn=51 */
/* @0xd3968 ldr r12, [pc, #0xac] */
/* @0xd396c ldr r3, [pc, #0xac] */
/* @0xd3970 add r12, pc, r12 */
/* @0xd3974 push {r4, r5, r6, lr} */
/* @0xd3978 mov r5, r0 */
/* @0xd397c ldr r3, [r12, r3] */
/* @0xd3980 sub sp, sp, #8 */
/* @0xd3984 ldrb r3, [r3] */
/* @0xd3988 cmp r3, #0 */
/* @0xd398c beq 0xd39c8 <_Z16PushContextStackP12YYObjectBase+0x60> */
/* @0xd3990 ldr r2, [pc, #0x8c] */
/* @0xd3994 ldr r3, [pc, #0x8c] */
/* @0xd3998 ldr r4, [r12, r2] */
/* @0xd399c ldr r3, [r12, r3] */
/* @0xd39a0 ldr r1, [r4] */
/* @0xd39a4 ldr r2, [r3] */
/* @0xd39a8 cmp r1, r2 */
/* @0xd39ac beq 0xd39d0 <_Z16PushContextStackP12YYObjectBase+0x68> */
/* @0xd39b0 ldr r3, [pc, #0x74] */
/* @0xd39b4 ldr r3, [r12, r3] */
/* @0xd39b8 ldr r2, [r3] */
/* @0xd39bc add r3, r1, #1 */
/* @0xd39c0 str r3, [r4] */
/* @0xd39c4 str r5, [r2, r1, lsl #2] */
/* @0xd39c8 add sp, sp, #8 */
/* @0xd39cc pop {r4, r5, r6, pc} */
/* @0xd39d0 ldr lr, [pc, #0x54] */
/* @0xd39d4 lsls r2, r1, #1 */
/* @0xd39d8 strne r2, [r3] */
/* @0xd39dc lslne r1, r1, #3 */
/* @0xd39e0 moveq r2, #1 */
/* @0xd39e4 streq r2, [r3] */
/* @0xd39e8 ldr r6, [r12, lr] */
/* @0xd39ec moveq r1, #4 */
/* @0xd39f0 ldr r2, [pc, #0x38] */
/* @0xd39f4 mov r0, #0 */
/* @0xd39f8 mov r3, #74 */
/* @0xd39fc str r0, [sp] */
/* @0xd3a00 add r2, pc, r2 */
/* @0xd3a04 ldr r0, [r6] */
/* @0xd3a08 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xd3a0c ldr r1, [r4] */
/* @0xd3a10 mov r2, r0 */
/* @0xd3a14 str r0, [r6] */
/* @0xd3a18 b 0xd39bc <_Z16PushContextStackP12YYObjectBase+0x54> */
/* @0xd3a1c eorseq lr, r1, r0, ror #5 */
/* @0xd3a20 .word 0xffffbf68 */
/* @0xd3a24 .word 0xffffbfb0 */
/* @0xd3a28 .word 0xffffbfb4 */
/* @0xd3a2c .word 0xffffbfb8 */
/* @0xd3a30 eoreq sp, r5, r0, lsr r6 */

/* ── FUNC 0xd3a34 · PopContextStack() · size=32 · insn=8 */
/* @0xd3a34 ldr r3, [pc, #0x14] */
/* @0xd3a38 ldr r3, [pc, r3] */
/* @0xd3a3c ldr r2, [r3] */
/* @0xd3a40 cmp r2, #0 */
/* @0xd3a44 subgt r2, r2, #1 */
/* @0xd3a48 strgt r2, [r3] */
/* @0xd3a4c bx lr */
/* @0xd3a50 eorseq r10, r1, r8, asr #3 */

/* ── FUNC 0xd3a54 · GetContextStackTop() · size=60 · insn=15 */
/* @0xd3a54 ldr r3, [pc, #0x2c] */
/* @0xd3a58 ldr r3, [pc, r3] */
/* @0xd3a5c ldr r2, [r3] */
/* @0xd3a60 cmp r2, #0 */
/* @0xd3a64 ble 0xd3a80 <_Z18GetContextStackTopv+0x2c> */
/* @0xd3a68 ldr r3, [pc, #0x1c] */
/* @0xd3a6c sub r2, r2, #-1073741823 */
/* @0xd3a70 ldr r3, [pc, r3] */
/* @0xd3a74 ldr r3, [r3] */
/* @0xd3a78 ldr r0, [r3, r2, lsl #2] */
/* @0xd3a7c bx lr */
/* @0xd3a80 mov r0, #0 */
/* @0xd3a84 bx lr */
/* @0xd3a88 eorseq r10, r1, r8, lsr #3 */
/* @0xd3a8c mlaseq r1, r8, r1, r10 */

/* ── FUNC 0xd3a90 · AddObjectToGCFreeList(YYObjectBase*) · size=184 · insn=46 */
/* @0xd3a90 push {r4, r5, r6, lr} */
/* @0xd3a94 subs r5, r0, #0 */
/* @0xd3a98 ldr r12, [pc, #0x94] */
/* @0xd3a9c sub sp, sp, #8 */
/* @0xd3aa0 add r12, pc, r12 */
/* @0xd3aa4 beq 0xd3ae0 <_Z21AddObjectToGCFreeListP12YYObjectBase+0x50> */
/* @0xd3aa8 ldr r2, [pc, #0x88] */
/* @0xd3aac ldr r3, [pc, #0x88] */
/* @0xd3ab0 ldr r4, [r12, r2] */
/* @0xd3ab4 ldr r3, [r12, r3] */
/* @0xd3ab8 ldr r1, [r4] */
/* @0xd3abc ldr r2, [r3] */
/* @0xd3ac0 cmp r1, r2 */
/* @0xd3ac4 beq 0xd3ae8 <_Z21AddObjectToGCFreeListP12YYObjectBase+0x58> */
/* @0xd3ac8 ldr r3, [pc, #0x70] */
/* @0xd3acc ldr r3, [r12, r3] */
/* @0xd3ad0 ldr r3, [r3] */
/* @0xd3ad4 add r2, r1, #1 */
/* @0xd3ad8 str r2, [r4] */
/* @0xd3adc str r5, [r3, r1, lsl #2] */
/* @0xd3ae0 add sp, sp, #8 */
/* @0xd3ae4 pop {r4, r5, r6, pc} */
/* @0xd3ae8 ldr lr, [pc, #0x50] */
/* @0xd3aec lsls r2, r1, #1 */
/* @0xd3af0 strne r2, [r3] */
/* @0xd3af4 lslne r1, r1, #3 */
/* @0xd3af8 moveq r2, #1 */
/* @0xd3afc streq r2, [r3] */
/* @0xd3b00 ldr r6, [r12, lr] */
/* @0xd3b04 moveq r1, #4 */
/* @0xd3b08 ldr r2, [pc, #0x34] */
/* @0xd3b0c mov r0, #0 */
/* @0xd3b10 mov r3, #74 */
/* @0xd3b14 str r0, [sp] */
/* @0xd3b18 add r2, pc, r2 */
/* @0xd3b1c ldr r0, [r6] */
/* @0xd3b20 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xd3b24 ldr r1, [r4] */
/* @0xd3b28 mov r3, r0 */
/* @0xd3b2c str r0, [r6] */
/* @0xd3b30 b 0xd3ad4 <_Z21AddObjectToGCFreeListP12YYObjectBase+0x44> */
/* @0xd3b34 ldrhteq lr, [r1], -r0 */
/* @0xd3b38 .word 0xffffbf84 */
/* @0xd3b3c .word 0xffffbfbc */
/* @0xd3b40 .word 0xffffbf8c */
/* @0xd3b44 eoreq sp, r5, r8, lsl r5 */

/* ── FUNC 0xd3b48 · ResetObjectGCList() · size=212 · insn=53 */
/* @0xd3b48 ldr r3, [pc, #0xac] */
/* @0xd3b4c ldr r2, [pc, #0xac] */
/* @0xd3b50 add r3, pc, r3 */
/* @0xd3b54 push {r4, r5, r6} */
/* @0xd3b58 ldr r1, [r3, r2] */
/* @0xd3b5c ldr r2, [r1] */
/* @0xd3b60 cmp r2, #0 */
/* @0xd3b64 beq 0xd3b9c <_Z17ResetObjectGCListv+0x54> */
/* @0xd3b68 ldr r0, [pc, #0x94] */
/* @0xd3b6c ldr r12, [r3, r0] */
/* @0xd3b70 ldr r0, [r12] */
/* @0xd3b74 cmp r0, #0 */
/* @0xd3b78 beq 0xd3b9c <_Z17ResetObjectGCListv+0x54> */
/* @0xd3b7c ldr r4, [pc, #0x84] */
/* @0xd3b80 mov r5, #0 */
/* @0xd3b84 ldr r4, [r3, r4] */
/* @0xd3b88 str r5, [r1] */
/* @0xd3b8c str r5, [r12] */
/* @0xd3b90 ldr r1, [r4] */
/* @0xd3b94 str r0, [r4] */
/* @0xd3b98 str r1, [r2, #0x8] */
/* @0xd3b9c ldr r2, [pc, #0x68] */
/* @0xd3ba0 ldr r2, [r3, r2] */
/* @0xd3ba4 ldr r1, [r2] */
/* @0xd3ba8 cmp r1, #0 */
/* @0xd3bac beq 0xd3be4 <_Z17ResetObjectGCListv+0x9c> */
/* @0xd3bb0 ldr r0, [pc, #0x58] */
/* @0xd3bb4 ldr r0, [r3, r0] */
/* @0xd3bb8 ldr r12, [r0] */
/* @0xd3bbc cmp r12, #0 */
/* @0xd3bc0 beq 0xd3be4 <_Z17ResetObjectGCListv+0x9c> */
/* @0xd3bc4 ldr r5, [pc, #0x48] */
/* @0xd3bc8 mov r4, #0 */
/* @0xd3bcc ldr r5, [r3, r5] */
/* @0xd3bd0 ldr r6, [r5] */
/* @0xd3bd4 str r6, [r12] */
/* @0xd3bd8 str r1, [r5] */
/* @0xd3bdc str r4, [r2] */
/* @0xd3be0 str r4, [r0] */
/* @0xd3be4 ldr r1, [pc, #0x2c] */
/* @0xd3be8 mov r2, #0 */
/* @0xd3bec pop {r4, r5, r6} */
/* @0xd3bf0 ldr r3, [r3, r1] */
/* @0xd3bf4 str r2, [r3] */
/* @0xd3bf8 bx lr */
/* @0xd3bfc eorseq lr, r1, r0, lsl #2 */
/* @0xd3c00 .word 0xffffbfa0 */
/* @0xd3c04 .word 0xffffbf9c */
/* @0xd3c08 .word 0xffffbfc0 */
/* @0xd3c0c .word 0xffffbf90 */
/* @0xd3c10 .word 0xffffbf88 */
/* @0xd3c14 .word 0xffffbfc4 */
/* @0xd3c18 .word 0xffffbf84 */

/* ── FUNC 0xd3c1c · AddObjectToDisposeList(YYObjectBase*) · size=184 · insn=46 */
/* @0xd3c1c push {r4, r5, r6, lr} */
/* @0xd3c20 subs r5, r0, #0 */
/* @0xd3c24 ldr r12, [pc, #0x94] */
/* @0xd3c28 sub sp, sp, #8 */
/* @0xd3c2c add r12, pc, r12 */
/* @0xd3c30 beq 0xd3c6c <_Z22AddObjectToDisposeListP12YYObjectBase+0x50> */
/* @0xd3c34 ldr r2, [pc, #0x88] */
/* @0xd3c38 ldr r3, [pc, #0x88] */
/* @0xd3c3c ldr r4, [r12, r2] */
/* @0xd3c40 ldr r3, [r12, r3] */
/* @0xd3c44 ldr r1, [r4] */
/* @0xd3c48 ldr r2, [r3] */
/* @0xd3c4c cmp r1, r2 */
/* @0xd3c50 beq 0xd3c74 <_Z22AddObjectToDisposeListP12YYObjectBase+0x58> */
/* @0xd3c54 ldr r3, [pc, #0x70] */
/* @0xd3c58 ldr r3, [r12, r3] */
/* @0xd3c5c ldr r3, [r3] */
/* @0xd3c60 add r2, r1, #1 */
/* @0xd3c64 str r2, [r4] */
/* @0xd3c68 str r5, [r3, r1, lsl #2] */
/* @0xd3c6c add sp, sp, #8 */
/* @0xd3c70 pop {r4, r5, r6, pc} */
/* @0xd3c74 ldr lr, [pc, #0x50] */
/* @0xd3c78 lsls r2, r1, #1 */
/* @0xd3c7c strne r2, [r3] */
/* @0xd3c80 lslne r1, r1, #3 */
/* @0xd3c84 moveq r2, #1 */
/* @0xd3c88 streq r2, [r3] */
/* @0xd3c8c ldr r6, [r12, lr] */
/* @0xd3c90 moveq r1, #4 */
/* @0xd3c94 ldr r2, [pc, #0x34] */
/* @0xd3c98 mov r0, #0 */
/* @0xd3c9c mov r3, #74 */
/* @0xd3ca0 str r0, [sp] */
/* @0xd3ca4 add r2, pc, r2 */
/* @0xd3ca8 ldr r0, [r6] */
/* @0xd3cac bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xd3cb0 ldr r1, [r4] */
/* @0xd3cb4 mov r3, r0 */
/* @0xd3cb8 str r0, [r6] */
/* @0xd3cbc b 0xd3c60 <_Z22AddObjectToDisposeListP12YYObjectBase+0x44> */
/* @0xd3cc0 eorseq lr, r1, r4, lsr #32 */
/* @0xd3cc4 .word 0xffffbfc8 */
/* @0xd3cc8 .word 0xffffbfcc */
/* @0xd3ccc .word 0xffffbfd0 */
/* @0xd3cd0 eoreq sp, r5, r12, lsl #7 */

/* ── FUNC 0xd3cd4 · ProcessObjectDisposeList() · size=196 · insn=49 */
/* @0xd3cd4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd3cd8 sub sp, sp, #36 */
/* @0xd3cdc ldr r8, [pc, #0xa8] */
/* @0xd3ce0 ldr r8, [pc, r8] */
/* @0xd3ce4 ldr r3, [r8] */
/* @0xd3ce8 cmp r3, #0 */
/* @0xd3cec beq 0xd3d7c <_Z24ProcessObjectDisposeListv+0xa8> */
/* @0xd3cf0 ldr r9, [pc, #0x98] */
/* @0xd3cf4 mov r3, #0 */
/* @0xd3cf8 ldr r11, [pc, #0x94] */
/* @0xd3cfc add r7, sp, #16 */
/* @0xd3d00 ldr r9, [pc, r9] */
/* @0xd3d04 mov r5, r3 */
/* @0xd3d08 mov r6, r3 */
/* @0xd3d0c add r11, pc, r11 */
/* @0xd3d10 str r11, [sp, #0xc] */
/* @0xd3d14 ldr r0, [r9] */
/* @0xd3d18 mov r1, r7 */
/* @0xd3d1c ldr r2, [sp, #0xc] */
/* @0xd3d20 mov r11, #0 */
/* @0xd3d24 mov r10, #0 */
/* @0xd3d28 add r5, r5, #1 */
/* @0xd3d2c ldr r4, [r0, r3, lsl #2] */
/* @0xd3d30 strd r10, r11, [sp, #16] */
/* @0xd3d34 mvn r11, #-16777216 */
/* @0xd3d38 str r6, [sp, #0x18] */
/* @0xd3d3c mov r0, r4 */
/* @0xd3d40 str r11, [sp, #0x1c] */
/* @0xd3d44 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* @0xd3d48 mov r1, #0 */
/* @0xd3d4c mov r3, r1 */
/* @0xd3d50 mov r2, r7 */
/* @0xd3d54 str r6, [sp] */
/* @0xd3d58 mov r0, r4 */
/* @0xd3d5c bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0xd3d60 ldr r1, [r8] */
/* @0xd3d64 ldr r2, [r4, #0x28] */
/* @0xd3d68 mov r3, r5 */
/* @0xd3d6c cmp r5, r1 */
/* @0xd3d70 orr r2, r2, #2 */
/* @0xd3d74 str r2, [r4, #0x28] */
/* @0xd3d78 blo 0xd3d14 <_Z24ProcessObjectDisposeListv+0x40> */
/* @0xd3d7c mov r3, #0 */
/* @0xd3d80 str r3, [r8] */
/* @0xd3d84 add sp, sp, #36 */
/* @0xd3d88 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd3d8c eorseq r9, r1, r8, lsr pc */
/* @0xd3d90 eorseq r9, r1, r0, lsr #30 */
/* @0xd3d94 eoreq lr, r5, r0, lsr #21 */

/* ── FUNC 0xd3d98 · StartGCThread() · size=132 · insn=33 */
/* @0xd3d98 push {r4, r5, r6, r7, r8, lr} */
/* @0xd3d9c ldr r4, [pc, #0x6c] */
/* @0xd3da0 ldr r4, [pc, r4] */
/* @0xd3da4 ldr r5, [r4] */
/* @0xd3da8 cmp r5, #0 */
/* @0xd3dac popne {r4, r5, r6, r7, r8, pc} */
/* @0xd3db0 mov r0, #24 */
/* @0xd3db4 bl 0x27c524 <_Znwj> */
/* @0xd3db8 mov r6, r0 */
/* @0xd3dbc strb r5, [r0, #0x8] */
/* @0xd3dc0 str r5, [r6] */
/* @0xd3dc4 mov r0, #8 */
/* @0xd3dc8 str r5, [r6, #0x4] */
/* @0xd3dcc strb r5, [r6, #0x9] */
/* @0xd3dd0 str r5, [r6, #0xc] */
/* @0xd3dd4 str r5, [r6, #0x10] */
/* @0xd3dd8 bl 0x27c524 <_Znwj> */
/* @0xd3ddc ldr r1, [pc, #0x30] */
/* @0xd3de0 add r1, pc, r1 */
/* @0xd3de4 mov r7, r0 */
/* @0xd3de8 bl 0x27e070 <_ZN5MutexC2EPKc> */
/* @0xd3dec ldr r1, [pc, #0x24] */
/* @0xd3df0 mov r0, r6 */
/* @0xd3df4 str r7, [r6, #0x14] */
/* @0xd3df8 mov r2, r5 */
/* @0xd3dfc str r6, [r4] */
/* @0xd3e00 ldr r1, [pc, r1] */
/* @0xd3e04 mov r3, #1 */
/* @0xd3e08 pop {r4, r5, r6, r7, r8, lr} */
/* @0xd3e0c b 0x27e0c0 <_ZN7CThread5StartEPFPvS0_ES0_NS_9ePriorityE> */
/* @0xd3e10 eorseq r9, r1, r4, lsl #29 */
/* @0xd3e14 .word 0x0025e9d4 */
/* @0xd3e18 eorseq r9, r1, r8, lsr #28 */

/* ── FUNC 0xd3e1c · EndGCThread() · size=120 · insn=30 */
/* @0xd3e1c push {r4, r5, r6, lr} */
/* @0xd3e20 ldr r4, [pc, #0x68] */
/* @0xd3e24 ldr r4, [pc, r4] */
/* @0xd3e28 ldr r5, [r4] */
/* @0xd3e2c cmp r5, #0 */
/* @0xd3e30 popeq {r4, r5, r6, pc} */
/* @0xd3e34 ldr r0, [r5, #0x14] */
/* @0xd3e38 bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0xd3e3c mov r3, #1 */
/* @0xd3e40 ldr r0, [r5, #0x14] */
/* @0xd3e44 strb r3, [r5, #0x8] */
/* @0xd3e48 bl 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0xd3e4c ldr r0, [r4] */
/* @0xd3e50 bl 0x27e108 <_ZN7CThread11WaitForExitEv> */
/* @0xd3e54 ldr r5, [r4] */
/* @0xd3e58 cmp r5, #0 */
/* @0xd3e5c beq 0xd3e84 <_Z11EndGCThreadv+0x68> */
/* @0xd3e60 ldr r6, [r5, #0x14] */
/* @0xd3e64 cmp r6, #0 */
/* @0xd3e68 beq 0xd3e7c <_Z11EndGCThreadv+0x60> */
/* @0xd3e6c mov r0, r6 */
/* @0xd3e70 bl 0x27e020 <_ZN5MutexD2Ev> */
/* @0xd3e74 mov r0, r6 */
/* @0xd3e78 bl 0x27d1d0 <_ZdlPv> */
/* @0xd3e7c mov r0, r5 */
/* @0xd3e80 bl 0x27d1d0 <_ZdlPv> */
/* @0xd3e84 mov r3, #0 */
/* @0xd3e88 str r3, [r4] */
/* @0xd3e8c pop {r4, r5, r6, pc} */
/* @0xd3e90 eorseq r9, r1, r0, lsl #28 */

/* ── FUNC 0xd3e94 · WaitForGCThread() · size=44 · insn=11 */
/* @0xd3e94 ldr r0, [pc, #0x1c] */
/* @0xd3e98 ldr r1, [pc, #0x1c] */
/* @0xd3e9c ldr r0, [pc, r0] */
/* @0xd3ea0 ldr r1, [pc, r1] */
/* @0xd3ea4 ldr r2, [r0] */
/* @0xd3ea8 ldr r3, [r1] */
/* @0xd3eac cmp r2, r3 */
/* @0xd3eb0 blt 0xd3ea4 <_Z15WaitForGCThreadv+0x10> */
/* @0xd3eb4 bx lr */
/* @0xd3eb8 eorseq r9, r1, r0, lsr sp */
/* @0xd3ebc eorseq r9, r1, r0, lsr sp */

/* ── FUNC 0xd3ec0 · KickOffGCThread() · size=28 · insn=7 */
/* @0xd3ec0 ldr r3, [pc, #0x10] */
/* @0xd3ec4 ldr r3, [pc, r3] */
/* @0xd3ec8 ldr r2, [r3] */
/* @0xd3ecc add r2, r2, #1 */
/* @0xd3ed0 str r2, [r3] */
/* @0xd3ed4 bx lr */
/* @0xd3ed8 eorseq r9, r1, r12, lsl #26 */

/* ── FUNC 0xd3edc · InitialiseHandledContainer() · size=4 · insn=1 */
/* @0xd3edc bx lr */

/* ── FUNC 0xd3ee0 · ClearHandledContainer() · size=112 · insn=28 */
/* @0xd3ee0 ldr r2, [pc, #0x5c] */
/* @0xd3ee4 add r2, pc, r2 */
/* @0xd3ee8 ldr r3, [r2] */
/* @0xd3eec cmp r3, #0 */
/* @0xd3ef0 beq 0xd3f08 <_Z21ClearHandledContainerv+0x28> */
/* @0xd3ef4 cmp r3, r2 */
/* @0xd3ef8 strne r3, [r3] */
/* @0xd3efc strne r3, [r3, #0x4] */
/* @0xd3f00 movne r2, #0 */
/* @0xd3f04 strne r2, [r3, #0x8] */
/* @0xd3f08 ldr r2, [pc, #0x38] */
/* @0xd3f0c add r2, pc, r2 */
/* @0xd3f10 ldr r3, [r2, #0x4] */
/* @0xd3f14 cmp r3, #0 */
/* @0xd3f18 beq 0xd3f30 <_Z21ClearHandledContainerv+0x50> */
/* @0xd3f1c cmp r3, r2 */
/* @0xd3f20 strne r3, [r3] */
/* @0xd3f24 strne r3, [r3, #0x4] */
/* @0xd3f28 movne r2, #0 */
/* @0xd3f2c strne r2, [r3, #0x8] */
/* @0xd3f30 ldr r3, [pc, #0x14] */
/* @0xd3f34 add r3, pc, r3 */
/* @0xd3f38 str r3, [r3] */
/* @0xd3f3c str r3, [r3, #0x4] */
/* @0xd3f40 bx lr */
/* @0xd3f44 ldrsbteq r6, [r10], -r0 */
/* @0xd3f48 eorseq r6, r10, r8, lsr #5 */
/* @0xd3f4c eorseq r6, r10, r0, lsl #5 */

/* ── FUNC 0xd3f50 · InstanceHandled(CInstance*) · size=128 · insn=32 */
/* @0xd3f50 mov r3, r0 */
/* @0xd3f54 ldr r0, [pc, #0x6c] */
/* @0xd3f58 ldr r1, [r3, #0x1ac] */
/* @0xd3f5c add r2, r3, #420 */
/* @0xd3f60 add r0, pc, r0 */
/* @0xd3f64 subs r1, r1, r0 */
/* @0xd3f68 rsbs r0, r1, #0 */
/* @0xd3f6c adcs r0, r0, r1 */
/* @0xd3f70 cmp r0, #0 */
/* @0xd3f74 str r4, [sp, #-0x4]! */
/* @0xd3f78 mov r4, #0 */
/* @0xd3f7c ldrne r12, [r3, #0x1a8] */
/* @0xd3f80 ldrne r1, [r3, #0x1a4] */
/* @0xd3f84 strne r12, [r1, #0x4] */
/* @0xd3f88 ldrne r12, [r3, #0x1a8] */
/* @0xd3f8c strne r1, [r12] */
/* @0xd3f90 ldr r1, [pc, #0x34] */
/* @0xd3f94 str r4, [r3, #0x1ac] */
/* @0xd3f98 add r1, pc, r1 */
/* @0xd3f9c str r2, [r3, #0x1a4] */
/* @0xd3fa0 str r2, [r3, #0x1a8] */
/* @0xd3fa4 ldr r12, [r1, #0x4] */
/* @0xd3fa8 ldr r4, [sp], #4 */
/* @0xd3fac cmp r2, r12 */
/* @0xd3fb0 strne r1, [r3, #0x1a4] */
/* @0xd3fb4 strne r12, [r3, #0x1a8] */
/* @0xd3fb8 strne r2, [r1, #0x4] */
/* @0xd3fbc strne r2, [r12] */
/* @0xd3fc0 strne r1, [r3, #0x1ac] */
/* @0xd3fc4 bx lr */
/* @0xd3fc8 eorseq r6, r10, r4, asr r2 */
/* @0xd3fcc eorseq r6, r10, r12, lsl r2 */

/* ── FUNC 0xd3fd0 · HandleInstance(CInstance*) · size=104 · insn=26 */
/* @0xd3fd0 ldr r2, [pc, #0x58] */
/* @0xd3fd4 add r3, r0, #420 */
/* @0xd3fd8 ldr r1, [r0, #0x1ac] */
/* @0xd3fdc mov r12, #0 */
/* @0xd3fe0 add r2, pc, r2 */
/* @0xd3fe4 cmp r1, r2 */
/* @0xd3fe8 ldreq r1, [r0, #0x1a8] */
/* @0xd3fec ldreq r2, [r0, #0x1a4] */
/* @0xd3ff0 streq r1, [r2, #0x4] */
/* @0xd3ff4 ldreq r1, [r0, #0x1a8] */
/* @0xd3ff8 streq r2, [r1] */
/* @0xd3ffc ldr r2, [pc, #0x30] */
/* @0xd4000 str r3, [r0, #0x1a4] */
/* @0xd4004 add r2, pc, r2 */
/* @0xd4008 str r3, [r0, #0x1a8] */
/* @0xd400c str r12, [r0, #0x1ac] */
/* @0xd4010 ldr r1, [r2, #0x4] */
/* @0xd4014 cmp r3, r1 */
/* @0xd4018 strne r2, [r0, #0x1a4] */
/* @0xd401c strne r1, [r0, #0x1a8] */
/* @0xd4020 strne r3, [r2, #0x4] */
/* @0xd4024 strne r3, [r1] */
/* @0xd4028 strne r2, [r0, #0x1ac] */
/* @0xd402c bx lr */
/* @0xd4030 ldrsbteq r6, [r10], -r4 */
/* @0xd4034 ldrhteq r6, [r10], -r0 */

/* ── FUNC 0xd4038 · CheckInstances(int) · size=160 · insn=40 */
/* @0xd4038 ldr r12, [pc, #0x84] */
/* @0xd403c mov r2, #0 */
/* @0xd4040 push {r3, lr} */
/* @0xd4044 add r12, pc, r12 */
/* @0xd4048 ldr r3, [r12] */
/* @0xd404c cmp r3, r12 */
/* @0xd4050 beq 0xd4064 <_Z14CheckInstancesi+0x2c> */
/* @0xd4054 ldr r3, [r3] */
/* @0xd4058 add r2, r2, #1 */
/* @0xd405c cmp r3, r12 */
/* @0xd4060 bne 0xd4054 <_Z14CheckInstancesi+0x1c> */
/* @0xd4064 cmp r2, r0 */
/* @0xd4068 beq 0xd40a0 <_Z14CheckInstancesi+0x68> */
/* @0xd406c ldr r3, [pc, #0x54] */
/* @0xd4070 mov r2, r0 */
/* @0xd4074 ldr r1, [pc, #0x50] */
/* @0xd4078 ldr r3, [pc, r3] */
/* @0xd407c add r1, pc, r1 */
/* @0xd4080 ldr r0, [r3] */
/* @0xd4084 ldr r3, [r0] */
/* @0xd4088 ldr r3, [r3, #0xc] */
/* @0xd408c blx r3 */
/* @0xd4090 mov r3, #0 */
/* @0xd4094 mov r2, #42 */
/* @0xd4098 str r2, [r3] */
/* @0xd409c pop {r3, pc} */
/* @0xd40a0 ldr r3, [pc, #0x28] */
/* @0xd40a4 ldr r1, [pc, #0x28] */
/* @0xd40a8 ldr r3, [pc, r3] */
/* @0xd40ac add r1, pc, r1 */
/* @0xd40b0 ldr r0, [r3] */
/* @0xd40b4 ldr r3, [r0] */
/* @0xd40b8 ldr r3, [r3, #0xc] */
/* @0xd40bc blx r3 */
/* @0xd40c0 pop {r3, pc} */
/* @0xd40c4 eorseq r6, r10, r0, ror r1 */
/* @0xd40c8 mlaseq r1, r12, r6, r9 */
/* @0xd40cc eoreq lr, r5, r4, asr #14 */
/* @0xd40d0 eorseq r9, r1, r12, ror #12 */
/* @0xd40d4 eoreq lr, r5, r0, lsr r7 */

/* ── FUNC 0xd40d8 · CountInstances() · size=52 · insn=13 */
/* @0xd40d8 ldr r2, [pc, #0x28] */
/* @0xd40dc mov r0, #0 */
/* @0xd40e0 add r2, pc, r2 */
/* @0xd40e4 ldr r3, [r2] */
/* @0xd40e8 cmp r3, r2 */
/* @0xd40ec beq 0xd4104 <_Z14CountInstancesv+0x2c> */
/* @0xd40f0 ldr r3, [r3] */
/* @0xd40f4 add r0, r0, #1 */
/* @0xd40f8 cmp r3, r2 */
/* @0xd40fc bne 0xd40f0 <_Z14CountInstancesv+0x18> */
/* @0xd4100 bx lr */
/* @0xd4104 bx lr */
/* @0xd4108 ldrsbteq r6, [r10], -r4 */

/* ── FUNC 0xd410c · IterateInstances(YYObjectBase**, VMExec*) · size=132 · insn=33 */
/* @0xd410c push {r4, r5, r6, r7, r8, r9, r10} */
/* @0xd4110 ldr r6, [pc, #0x74] */
/* @0xd4114 add r6, pc, r6 */
/* @0xd4118 ldr r2, [r6] */
/* @0xd411c cmp r2, r6 */
/* @0xd4120 beq 0xd4184 <_Z16IterateInstancesPP12YYObjectBaseP6VMExec+0x78> */
/* @0xd4124 mov r5, #0 */
/* @0xd4128 mov r12, r0 */
/* @0xd412c mov r9, r6 */
/* @0xd4130 mov r8, r5 */
/* @0xd4134 ldr r3, [r6, #0x8] */
/* @0xd4138 str r5, [r12], #4 */
/* @0xd413c mov r0, r12 */
/* @0xd4140 rsb r3, r3, r2 */
/* @0xd4144 ldr r2, [r2] */
/* @0xd4148 str r3, [r1, #0x14] */
/* @0xd414c add r4, r3, #420 */
/* @0xd4150 ldr r7, [r3, #0x1ac] */
/* @0xd4154 mov r5, r3 */
/* @0xd4158 cmp r7, r6 */
/* @0xd415c ldreq r10, [r3, #0x1a8] */
/* @0xd4160 ldreq r7, [r3, #0x1a4] */
/* @0xd4164 streq r10, [r7, #0x4] */
/* @0xd4168 ldreq r10, [r3, #0x1a8] */
/* @0xd416c streq r7, [r10] */
/* @0xd4170 cmp r2, r9 */
/* @0xd4174 str r4, [r3, #0x1a4] */
/* @0xd4178 str r4, [r3, #0x1a8] */
/* @0xd417c str r8, [r3, #0x1ac] */
/* @0xd4180 bne 0xd4134 <_Z16IterateInstancesPP12YYObjectBaseP6VMExec+0x28> */
/* @0xd4184 pop {r4, r5, r6, r7, r8, r9, r10} */
/* @0xd4188 bx lr */
/* @0xd418c eorseq r6, r10, r0, lsr #1 */

/* ── FUNC 0xd4190 · TErrStreamConsole::TErrStreamConsole() · size=84 · insn=21 */
/* @0xd4190 ldr r3, [pc, #0x44] */
/* @0xd4194 mov r2, #516 */
/* @0xd4198 ldr r1, [pc, #0x40] */
/* @0xd419c push {r4, lr} */
/* @0xd41a0 ldr r3, [pc, r3] */
/* @0xd41a4 mov r4, r0 */
/* @0xd41a8 add r1, pc, r1 */
/* @0xd41ac mov r0, #102400 */
/* @0xd41b0 add r3, r3, #8 */
/* @0xd41b4 str r0, [r4, #0x4] */
/* @0xd41b8 str r3, [r4] */
/* @0xd41bc mov r3, #0 */
/* @0xd41c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd41c4 mov r2, #0 */
/* @0xd41c8 mov r3, r0 */
/* @0xd41cc str r0, [r4, #0x8] */
/* @0xd41d0 mov r0, r4 */
/* @0xd41d4 strb r2, [r3] */
/* @0xd41d8 pop {r4, pc} */
/* @0xd41dc eorseq r9, r1, r8, lsr #20 */
/* @0xd41e0 .word 0x0025e5d4 */

/* ── FUNC 0xd4190 · TErrStreamConsole::TErrStreamConsole() · alias of the symbol above · insn=0 */

/* ── FUNC 0xd41e4 · YYAllocLocalStackNew(int) · size=44 · insn=11 */
/* @0xd41e4 push {r3, lr} */
/* @0xd41e8 mvn r1, #-16777216 */
/* @0xd41ec mov r2, #0 */
/* @0xd41f0 bl 0x19198c <_ZN12YYObjectBase5AllocEjib> */
/* @0xd41f4 ldr r2, [pc, #0x10] */
/* @0xd41f8 mov r1, #0 */
/* @0xd41fc add r2, pc, r2 */
/* @0xd4200 str r1, [r0, #0xc] */
/* @0xd4204 str r2, [r0, #0x40] */
/* @0xd4208 pop {r3, pc} */
/* @0xd420c .word 0x0025e5fc */

/* ── FUNC 0xd4210 · VMError(VMExec*, char const*, ...) · size=244 · insn=61 */
/* @0xd4210 push {r1, r2, r3} */
/* @0xd4214 push {r4, r5, r6, r7, r8, lr} */
/* @0xd4218 sub sp, sp, #1024 */
/* @0xd421c ldr r4, [pc, #0xcc] */
/* @0xd4220 sub sp, sp, #12 */
/* @0xd4224 ldr r3, [pc, #0xc8] */
/* @0xd4228 mov r7, #1 */
/* @0xd422c add r4, pc, r4 */
/* @0xd4230 ldr r12, [pc, #0xc0] */
/* @0xd4234 ldr r2, [pc, #0xc0] */
/* @0xd4238 ldr r5, [r4, r3] */
/* @0xd423c ldr r1, [sp, #0x424] */
/* @0xd4240 ldr r3, [r5] */
/* @0xd4244 str r3, [sp, #0x404] */
/* @0xd4248 ldr r3, [r4, r12] */
/* @0xd424c strb r7, [r3] */
/* @0xd4250 ldr r6, [r4, r2] */
/* @0xd4254 ldrb r3, [r6] */
/* @0xd4258 cmp r3, #0 */
/* @0xd425c beq 0xd4294 <_Z7VMErrorP6VMExecPKcz+0x84> */
/* @0xd4260 ldr r3, [r0, #0x50] */
/* @0xd4264 mov r2, #0 */
/* @0xd4268 str r2, [r0, #0x4c] */
/* @0xd426c str r3, [r0, #0x44] */
/* @0xd4270 ldr r2, [sp, #0x404] */
/* @0xd4274 ldr r3, [r5] */
/* @0xd4278 cmp r2, r3 */
/* @0xd427c bne 0xd42e4 <_Z7VMErrorP6VMExecPKcz+0xd4> */
/* @0xd4280 add sp, sp, #1024 */
/* @0xd4284 add sp, sp, #12 */
/* @0xd4288 pop {r4, r5, r6, r7, r8, lr} */
/* @0xd428c add sp, sp, #12 */
/* @0xd4290 bx lr */
/* @0xd4294 add r3, sp, #1056 */
/* @0xd4298 add r8, sp, #4 */
/* @0xd429c add r3, r3, #8 */
/* @0xd42a0 str r3, [sp] */
/* @0xd42a4 mov r0, r8 */
/* @0xd42a8 mov r2, r3 */
/* @0xd42ac bl 0xb667c <vsprintf@plt> */
/* @0xd42b0 ldrb r3, [r6] */
/* @0xd42b4 cmp r3, #0 */
/* @0xd42b8 bne 0xd4270 <_Z7VMErrorP6VMExecPKcz+0x60> */
/* @0xd42bc mov r0, r8 */
/* @0xd42c0 mov r1, r7 */
/* @0xd42c4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xd42c8 ldr r3, [pc, #0x30] */
/* @0xd42cc ldr r3, [r4, r3] */
/* @0xd42d0 ldrb r3, [r3] */
/* @0xd42d4 cmp r3, #0 */
/* @0xd42d8 beq 0xd42e8 <_Z7VMErrorP6VMExecPKcz+0xd8> */
/* @0xd42dc bl 0x10c320 <_Z14YYGML_game_endv> */
/* @0xd42e0 b 0xd4270 <_Z7VMErrorP6VMExecPKcz+0x60> */
/* @0xd42e4 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xd42e8 mvn r0, #0 */
/* @0xd42ec bl 0xb6688 <exit@plt> */
/* @0xd42f0 eorseq sp, r1, r4, lsr #20 */
/* @0xd42f4 .word 0xffffbd00 */
/* @0xd42f8 .word 0xffffbf14 */
/* @0xd42fc .word 0xffffbfdc */
/* @0xd4300 .word 0xffffbfe0 */

/* ── FUNC 0xd4304 · DoRem(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=1840 · insn=460 */
/* @0xd4304 lsr r0, r0, #16 */
/* @0xd4308 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd430c vpush {d8} */
/* @0xd4310 uxtb r4, r0 */
/* @0xd4314 mov r10, r3 */
/* @0xd4318 and r3, r4, #15 */
/* @0xd431c mov r11, r1 */
/* @0xd4320 cmp r3, #6 */
/* @0xd4324 addls pc, pc, r3, lsl #2 */
/* @0xd4328 b 0xd49e8 <_Z5DoRemjPhPKhP6VMExec+0x6e4> */
/* @0xd432c b 0xd46b8 <_Z5DoRemjPhPKhP6VMExec+0x3b4> */
/* @0xd4330 b 0xd46ac <_Z5DoRemjPhPKhP6VMExec+0x3a8> */
/* @0xd4334 b 0xd46ac <_Z5DoRemjPhPKhP6VMExec+0x3a8> */
/* @0xd4338 b 0xd46b8 <_Z5DoRemjPhPKhP6VMExec+0x3b4> */
/* @0xd433c b 0xd46ac <_Z5DoRemjPhPKhP6VMExec+0x3a8> */
/* @0xd4340 b 0xd4664 <_Z5DoRemjPhPKhP6VMExec+0x360> */
/* @0xd4344 b 0xd4348 <_Z5DoRemjPhPKhP6VMExec+0x44> */
/* @0xd4348 ldr r1, [pc, #0x6ac] */
/* @0xd434c mov r0, r10 */
/* @0xd4350 mov r5, r4 */
/* @0xd4354 mov r8, r11 */
/* @0xd4358 add r1, pc, r1 */
/* @0xd435c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd4360 asr r3, r5, #4 */
/* @0xd4364 cmp r3, #6 */
/* @0xd4368 addls pc, pc, r3, lsl #2 */
/* @0xd436c b 0xd49f4 <_Z5DoRemjPhPKhP6VMExec+0x6f0> */
/* @0xd4370 b 0xd465c <_Z5DoRemjPhPKhP6VMExec+0x358> */
/* @0xd4374 b 0xd4654 <_Z5DoRemjPhPKhP6VMExec+0x350> */
/* @0xd4378 b 0xd4654 <_Z5DoRemjPhPKhP6VMExec+0x350> */
/* @0xd437c b 0xd465c <_Z5DoRemjPhPKhP6VMExec+0x358> */
/* @0xd4380 b 0xd4654 <_Z5DoRemjPhPKhP6VMExec+0x350> */
/* @0xd4384 b 0xd460c <_Z5DoRemjPhPKhP6VMExec+0x308> */
/* @0xd4388 b 0xd438c <_Z5DoRemjPhPKhP6VMExec+0x88> */
/* @0xd438c ldr r1, [pc, #0x66c] */
/* @0xd4390 mov r0, r10 */
/* @0xd4394 mov r6, r8 */
/* @0xd4398 add r1, pc, r1 */
/* @0xd439c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd43a0 cmp r4, #85 */
/* @0xd43a4 addls pc, pc, r4, lsl #2 */
/* @0xd43a8 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43ac b 0xd45fc <_Z5DoRemjPhPKhP6VMExec+0x2f8> */
/* @0xd43b0 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43b4 b 0xd45fc <_Z5DoRemjPhPKhP6VMExec+0x2f8> */
/* @0xd43b8 b 0xd45fc <_Z5DoRemjPhPKhP6VMExec+0x2f8> */
/* @0xd43bc b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43c0 b 0xd45ec <_Z5DoRemjPhPKhP6VMExec+0x2e8> */
/* @0xd43c4 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43c8 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43cc b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43d0 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43d4 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43d8 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43dc b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43e0 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43e4 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43e8 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43ec b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43f0 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43f4 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43f8 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43fc b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4400 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4404 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4408 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd440c b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4410 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4414 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4418 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd441c b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4420 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4424 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4428 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd442c b 0xd45fc <_Z5DoRemjPhPKhP6VMExec+0x2f8> */
/* @0xd4430 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4434 b 0xd4504 <_Z5DoRemjPhPKhP6VMExec+0x200> */
/* @0xd4438 b 0xd45fc <_Z5DoRemjPhPKhP6VMExec+0x2f8> */
/* @0xd443c b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4440 b 0xd45ec <_Z5DoRemjPhPKhP6VMExec+0x2e8> */
/* @0xd4444 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4448 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd444c b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4450 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4454 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4458 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd445c b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4460 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4464 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4468 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd446c b 0xd45fc <_Z5DoRemjPhPKhP6VMExec+0x2f8> */
/* @0xd4470 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4474 b 0xd45fc <_Z5DoRemjPhPKhP6VMExec+0x2f8> */
/* @0xd4478 b 0xd45fc <_Z5DoRemjPhPKhP6VMExec+0x2f8> */
/* @0xd447c b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4480 b 0xd45ec <_Z5DoRemjPhPKhP6VMExec+0x2e8> */
/* @0xd4484 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4488 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd448c b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4490 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4494 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4498 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd449c b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44a0 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44a4 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44a8 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44ac b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44b0 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44b4 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44b8 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44bc b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44c0 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44c4 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44c8 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44cc b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44d0 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44d4 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44d8 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44dc b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44e0 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44e4 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44e8 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44ec b 0xd45ec <_Z5DoRemjPhPKhP6VMExec+0x2e8> */
/* @0xd44f0 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44f4 b 0xd45ec <_Z5DoRemjPhPKhP6VMExec+0x2e8> */
/* @0xd44f8 b 0xd45ec <_Z5DoRemjPhPKhP6VMExec+0x2e8> */
/* @0xd44fc b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4500 b 0xd45ec <_Z5DoRemjPhPKhP6VMExec+0x2e8> */
/* @0xd4504 sub r6, r6, #4 */
/* @0xd4508 mov r7, #0 */
/* @0xd450c mov r9, r6 */
/* @0xd4510 cmp r5, #51 */
/* @0xd4514 addls pc, pc, r5, lsl #2 */
/* @0xd4518 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd451c b 0xd4840 <_Z5DoRemjPhPKhP6VMExec+0x53c> */
/* @0xd4520 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4524 b 0xd4810 <_Z5DoRemjPhPKhP6VMExec+0x50c> */
/* @0xd4528 b 0xd47e4 <_Z5DoRemjPhPKhP6VMExec+0x4e0> */
/* @0xd452c b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4530 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4534 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4538 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd453c b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4540 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4544 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4548 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd454c b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4550 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4554 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4558 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd455c b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4560 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4564 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4568 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd456c b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4570 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4574 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4578 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd457c b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4580 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4584 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4588 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd458c b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4590 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4594 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4598 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd459c b 0xd47a8 <_Z5DoRemjPhPKhP6VMExec+0x4a4> */
/* @0xd45a0 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45a4 b 0xd4788 <_Z5DoRemjPhPKhP6VMExec+0x484> */
/* @0xd45a8 b 0xd4764 <_Z5DoRemjPhPKhP6VMExec+0x460> */
/* @0xd45ac b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45b0 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45b4 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45b8 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45bc b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45c0 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45c4 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45c8 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45cc b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45d0 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45d4 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45d8 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45dc b 0xd4724 <_Z5DoRemjPhPKhP6VMExec+0x420> */
/* @0xd45e0 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45e4 b 0xd4700 <_Z5DoRemjPhPKhP6VMExec+0x3fc> */
/* @0xd45e8 b 0xd46d0 <_Z5DoRemjPhPKhP6VMExec+0x3cc> */
/* @0xd45ec sub r7, r6, #16 */
/* @0xd45f0 mov r9, r7 */
/* @0xd45f4 mov r6, r7 */
/* @0xd45f8 b 0xd4510 <_Z5DoRemjPhPKhP6VMExec+0x20c> */
/* @0xd45fc sub r6, r6, #8 */
/* @0xd4600 mov r7, #0 */
/* @0xd4604 mov r9, r6 */
/* @0xd4608 b 0xd4510 <_Z5DoRemjPhPKhP6VMExec+0x20c> */
/* @0xd460c ldr r3, [r8, #0xc] */
/* @0xd4610 cmp r3, #13 */
/* @0xd4614 addls pc, pc, r3, lsl #2 */
/* @0xd4618 b 0xd49d4 <_Z5DoRemjPhPKhP6VMExec+0x6d0> */
/* @0xd461c b 0xd48c4 <_Z5DoRemjPhPKhP6VMExec+0x5c0> */
/* @0xd4620 b 0xd48d0 <_Z5DoRemjPhPKhP6VMExec+0x5cc> */
/* @0xd4624 b 0xd48e4 <_Z5DoRemjPhPKhP6VMExec+0x5e0> */
/* @0xd4628 b 0xd48f8 <_Z5DoRemjPhPKhP6VMExec+0x5f4> */
/* @0xd462c b 0xd49d4 <_Z5DoRemjPhPKhP6VMExec+0x6d0> */
/* @0xd4630 b 0xd490c <_Z5DoRemjPhPKhP6VMExec+0x608> */
/* @0xd4634 b 0xd49d4 <_Z5DoRemjPhPKhP6VMExec+0x6d0> */
/* @0xd4638 b 0xd493c <_Z5DoRemjPhPKhP6VMExec+0x638> */
/* @0xd463c b 0xd49d4 <_Z5DoRemjPhPKhP6VMExec+0x6d0> */
/* @0xd4640 b 0xd49d4 <_Z5DoRemjPhPKhP6VMExec+0x6d0> */
/* @0xd4644 b 0xd4948 <_Z5DoRemjPhPKhP6VMExec+0x644> */
/* @0xd4648 b 0xd49d4 <_Z5DoRemjPhPKhP6VMExec+0x6d0> */
/* @0xd464c b 0xd49d4 <_Z5DoRemjPhPKhP6VMExec+0x6d0> */
/* @0xd4650 b 0xd48c4 <_Z5DoRemjPhPKhP6VMExec+0x5c0> */
/* @0xd4654 add r6, r8, #4 */
/* @0xd4658 b 0xd43a0 <_Z5DoRemjPhPKhP6VMExec+0x9c> */
/* @0xd465c add r6, r8, #8 */
/* @0xd4660 b 0xd43a0 <_Z5DoRemjPhPKhP6VMExec+0x9c> */
/* @0xd4664 ldr r3, [r1, #0xc] */
/* @0xd4668 cmp r3, #13 */
/* @0xd466c addls pc, pc, r3, lsl #2 */
/* @0xd4670 b 0xd49bc <_Z5DoRemjPhPKhP6VMExec+0x6b8> */
/* @0xd4674 b 0xd4954 <_Z5DoRemjPhPKhP6VMExec+0x650> */
/* @0xd4678 b 0xd495c <_Z5DoRemjPhPKhP6VMExec+0x658> */
/* @0xd467c b 0xd4974 <_Z5DoRemjPhPKhP6VMExec+0x670> */
/* @0xd4680 b 0xd498c <_Z5DoRemjPhPKhP6VMExec+0x688> */
/* @0xd4684 b 0xd49bc <_Z5DoRemjPhPKhP6VMExec+0x6b8> */
/* @0xd4688 b 0xd49a4 <_Z5DoRemjPhPKhP6VMExec+0x6a0> */
/* @0xd468c b 0xd49bc <_Z5DoRemjPhPKhP6VMExec+0x6b8> */
/* @0xd4690 b 0xd4920 <_Z5DoRemjPhPKhP6VMExec+0x61c> */
/* @0xd4694 b 0xd49bc <_Z5DoRemjPhPKhP6VMExec+0x6b8> */
/* @0xd4698 b 0xd49bc <_Z5DoRemjPhPKhP6VMExec+0x6b8> */
/* @0xd469c b 0xd4930 <_Z5DoRemjPhPKhP6VMExec+0x62c> */
/* @0xd46a0 b 0xd49bc <_Z5DoRemjPhPKhP6VMExec+0x6b8> */
/* @0xd46a4 b 0xd49bc <_Z5DoRemjPhPKhP6VMExec+0x6b8> */
/* @0xd46a8 b 0xd4954 <_Z5DoRemjPhPKhP6VMExec+0x650> */
/* @0xd46ac add r8, r1, #4 */
/* @0xd46b0 mov r5, r4 */
/* @0xd46b4 b 0xd4360 <_Z5DoRemjPhPKhP6VMExec+0x5c> */
/* @0xd46b8 add r8, r1, #8 */
/* @0xd46bc mov r5, r4 */
/* @0xd46c0 b 0xd4360 <_Z5DoRemjPhPKhP6VMExec+0x5c> */
/* @0xd46c4 mov r9, #0 */
/* @0xd46c8 mov r7, r9 */
/* @0xd46cc b 0xd4510 <_Z5DoRemjPhPKhP6VMExec+0x20c> */
/* @0xd46d0 ldrd r2, r3, [r11] */
/* @0xd46d4 orrs r1, r2, r3 */
/* @0xd46d8 beq 0xd48ac <_Z5DoRemjPhPKhP6VMExec+0x5a8> */
/* @0xd46dc ldrd r0, r1, [r8] */
/* @0xd46e0 bl 0x319414 <__aeabi_ldivmod> */
/* @0xd46e4 mov r3, #10 */
/* @0xd46e8 strd r0, r1, [r9] */
/* @0xd46ec vpop {d8} */
/* @0xd46f0 cmp r7, #0 */
/* @0xd46f4 mov r0, r6 */
/* @0xd46f8 strne r3, [r7, #0xc] */
/* @0xd46fc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd4700 ldr r2, [r11] */
/* @0xd4704 cmp r2, #0 */
/* @0xd4708 beq 0xd48ac <_Z5DoRemjPhPKhP6VMExec+0x5a8> */
/* @0xd470c ldrd r0, r1, [r8] */
/* @0xd4710 asr r3, r2, #31 */
/* @0xd4714 bl 0x319414 <__aeabi_ldivmod> */
/* @0xd4718 mov r3, #7 */
/* @0xd471c str r0, [r9] */
/* @0xd4720 b 0xd46ec <_Z5DoRemjPhPKhP6VMExec+0x3e8> */
/* @0xd4724 vldr d7, [r11] */
/* @0xd4728 vabs.f64 d6, d7 */
/* @0xd472c vcvt.s32.f64 s12, d6 */
/* @0xd4730 vmov r1, s12 */
/* @0xd4734 cmp r1, #0 */
/* @0xd4738 beq 0xd48ac <_Z5DoRemjPhPKhP6VMExec+0x5a8> */
/* @0xd473c vmov r0, r1, d7 */
/* @0xd4740 bl 0x3194a0 <__fixdfdi> */
/* @0xd4744 mov r3, r1 */
/* @0xd4748 mov r2, r0 */
/* @0xd474c ldrd r0, r1, [r8] */
/* @0xd4750 bl 0x319414 <__aeabi_ldivmod> */
/* @0xd4754 bl 0x319164 <__floatdidf> */
/* @0xd4758 mov r3, #0 */
/* @0xd475c strd r0, r1, [r9] */
/* @0xd4760 b 0xd46ec <_Z5DoRemjPhPKhP6VMExec+0x3e8> */
/* @0xd4764 ldrd r2, r3, [r11] */
/* @0xd4768 orrs r1, r2, r3 */
/* @0xd476c beq 0xd48ac <_Z5DoRemjPhPKhP6VMExec+0x5a8> */
/* @0xd4770 ldr r0, [r8] */
/* @0xd4774 asr r1, r0, #31 */
/* @0xd4778 bl 0x319414 <__aeabi_ldivmod> */
/* @0xd477c mov r3, #10 */
/* @0xd4780 strd r0, r1, [r9] */
/* @0xd4784 b 0xd46ec <_Z5DoRemjPhPKhP6VMExec+0x3e8> */
/* @0xd4788 ldr r1, [r11] */
/* @0xd478c cmp r1, #0 */
/* @0xd4790 beq 0xd48ac <_Z5DoRemjPhPKhP6VMExec+0x5a8> */
/* @0xd4794 ldr r0, [r8] */
/* @0xd4798 bl 0x318d10 <__divsi3> */
/* @0xd479c mov r3, #7 */
/* @0xd47a0 str r0, [r9] */
/* @0xd47a4 b 0xd46ec <_Z5DoRemjPhPKhP6VMExec+0x3e8> */
/* @0xd47a8 vldr d7, [r11] */
/* @0xd47ac vabs.f64 d6, d7 */
/* @0xd47b0 vcvt.s32.f64 s12, d6 */
/* @0xd47b4 vmov r3, s12 */
/* @0xd47b8 cmp r3, #0 */
/* @0xd47bc beq 0xd48ac <_Z5DoRemjPhPKhP6VMExec+0x5a8> */
/* @0xd47c0 vcvt.s32.f64 s13, d7 */
/* @0xd47c4 ldr r0, [r8] */
/* @0xd47c8 vmov r1, s13 */
/* @0xd47cc bl 0x318d10 <__divsi3> */
/* @0xd47d0 mov r3, #0 */
/* @0xd47d4 vmov s13, r0 */
/* @0xd47d8 vcvt.f64.s32 d7, s13 */
/* @0xd47dc vstr d7, [r9] */
/* @0xd47e0 b 0xd46ec <_Z5DoRemjPhPKhP6VMExec+0x3e8> */
/* @0xd47e4 ldrd r4, r5, [r11] */
/* @0xd47e8 orrs r3, r4, r5 */
/* @0xd47ec beq 0xd48ac <_Z5DoRemjPhPKhP6VMExec+0x5a8> */
/* @0xd47f0 ldrd r0, r1, [r8] */
/* @0xd47f4 bl 0x3194a0 <__fixdfdi> */
/* @0xd47f8 mov r3, r5 */
/* @0xd47fc mov r2, r4 */
/* @0xd4800 bl 0x319414 <__aeabi_ldivmod> */
/* @0xd4804 mov r3, #10 */
/* @0xd4808 strd r0, r1, [r9] */
/* @0xd480c b 0xd46ec <_Z5DoRemjPhPKhP6VMExec+0x3e8> */
/* @0xd4810 ldr r4, [r11] */
/* @0xd4814 cmp r4, #0 */
/* @0xd4818 beq 0xd48ac <_Z5DoRemjPhPKhP6VMExec+0x5a8> */
/* @0xd481c ldrd r0, r1, [r8] */
/* @0xd4820 bl 0x3194a0 <__fixdfdi> */
/* @0xd4824 asr r3, r4, #31 */
/* @0xd4828 mov r2, r4 */
/* @0xd482c bl 0x319414 <__aeabi_ldivmod> */
/* @0xd4830 bl 0x319164 <__floatdidf> */
/* @0xd4834 mov r3, #0 */
/* @0xd4838 strd r0, r1, [r9] */
/* @0xd483c b 0xd46ec <_Z5DoRemjPhPKhP6VMExec+0x3e8> */
/* @0xd4840 vldr d8, [r11] */
/* @0xd4844 vabs.f64 d7, d8 */
/* @0xd4848 vcvt.s32.f64 s14, d7 */
/* @0xd484c vmov r1, s14 */
/* @0xd4850 cmp r1, #0 */
/* @0xd4854 beq 0xd48ac <_Z5DoRemjPhPKhP6VMExec+0x5a8> */
/* @0xd4858 ldrd r0, r1, [r8] */
/* @0xd485c bl 0x3194a0 <__fixdfdi> */
/* @0xd4860 mov r4, r0 */
/* @0xd4864 mov r5, r1 */
/* @0xd4868 vmov r0, r1, d8 */
/* @0xd486c bl 0x3194a0 <__fixdfdi> */
/* @0xd4870 mov r3, r1 */
/* @0xd4874 mov r2, r0 */
/* @0xd4878 mov r1, r5 */
/* @0xd487c mov r0, r4 */
/* @0xd4880 bl 0x319414 <__aeabi_ldivmod> */
/* @0xd4884 bl 0x319164 <__floatdidf> */
/* @0xd4888 mov r3, #0 */
/* @0xd488c strd r0, r1, [r9] */
/* @0xd4890 b 0xd46ec <_Z5DoRemjPhPKhP6VMExec+0x3e8> */
/* @0xd4894 ldr r1, [pc, #0x168] */
/* @0xd4898 mov r0, r10 */
/* @0xd489c add r1, pc, r1 */
/* @0xd48a0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd48a4 mov r3, #0 */
/* @0xd48a8 b 0xd46ec <_Z5DoRemjPhPKhP6VMExec+0x3e8> */
/* @0xd48ac ldr r1, [pc, #0x154] */
/* @0xd48b0 mov r0, r10 */
/* @0xd48b4 add r1, pc, r1 */
/* @0xd48b8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd48bc mov r3, #0 */
/* @0xd48c0 b 0xd46ec <_Z5DoRemjPhPKhP6VMExec+0x3e8> */
/* @0xd48c4 and r5, r5, #15 */
/* @0xd48c8 add r6, r8, #16 */
/* @0xd48cc b 0xd43a0 <_Z5DoRemjPhPKhP6VMExec+0x9c> */
/* @0xd48d0 ldr r1, [pc, #0x134] */
/* @0xd48d4 mov r0, r10 */
/* @0xd48d8 add r1, pc, r1 */
/* @0xd48dc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd48e0 b 0xd48c8 <_Z5DoRemjPhPKhP6VMExec+0x5c4> */
/* @0xd48e4 ldr r1, [pc, #0x124] */
/* @0xd48e8 mov r0, r10 */
/* @0xd48ec add r1, pc, r1 */
/* @0xd48f0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd48f4 b 0xd48c8 <_Z5DoRemjPhPKhP6VMExec+0x5c4> */
/* @0xd48f8 ldr r1, [pc, #0x114] */
/* @0xd48fc mov r0, r10 */
/* @0xd4900 add r1, pc, r1 */
/* @0xd4904 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd4908 b 0xd48c8 <_Z5DoRemjPhPKhP6VMExec+0x5c4> */
/* @0xd490c ldr r1, [pc, #0x104] */
/* @0xd4910 mov r0, r10 */
/* @0xd4914 add r1, pc, r1 */
/* @0xd4918 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd491c b 0xd48c8 <_Z5DoRemjPhPKhP6VMExec+0x5c4> */
/* @0xd4920 and r0, r0, #240 */
/* @0xd4924 orr r5, r0, #2 */
/* @0xd4928 add r8, r11, #16 */
/* @0xd492c b 0xd4360 <_Z5DoRemjPhPKhP6VMExec+0x5c> */
/* @0xd4930 and r0, r0, #240 */
/* @0xd4934 orr r5, r0, #3 */
/* @0xd4938 b 0xd4928 <_Z5DoRemjPhPKhP6VMExec+0x624> */
/* @0xd493c and r5, r5, #15 */
/* @0xd4940 orr r5, r5, #32 */
/* @0xd4944 b 0xd48c8 <_Z5DoRemjPhPKhP6VMExec+0x5c4> */
/* @0xd4948 and r5, r5, #15 */
/* @0xd494c orr r5, r5, #48 */
/* @0xd4950 b 0xd48c8 <_Z5DoRemjPhPKhP6VMExec+0x5c4> */
/* @0xd4954 and r5, r4, #240 */
/* @0xd4958 b 0xd4928 <_Z5DoRemjPhPKhP6VMExec+0x624> */
/* @0xd495c ldr r1, [pc, #0xb8] */
/* @0xd4960 mov r0, r10 */
/* @0xd4964 mov r5, r4 */
/* @0xd4968 add r1, pc, r1 */
/* @0xd496c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd4970 b 0xd4928 <_Z5DoRemjPhPKhP6VMExec+0x624> */
/* @0xd4974 ldr r1, [pc, #0xa4] */
/* @0xd4978 mov r0, r10 */
/* @0xd497c mov r5, r4 */
/* @0xd4980 add r1, pc, r1 */
/* @0xd4984 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd4988 b 0xd4928 <_Z5DoRemjPhPKhP6VMExec+0x624> */
/* @0xd498c ldr r1, [pc, #0x90] */
/* @0xd4990 mov r0, r10 */
/* @0xd4994 mov r5, r4 */
/* @0xd4998 add r1, pc, r1 */
/* @0xd499c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd49a0 b 0xd4928 <_Z5DoRemjPhPKhP6VMExec+0x624> */
/* @0xd49a4 ldr r1, [pc, #0x7c] */
/* @0xd49a8 mov r0, r10 */
/* @0xd49ac mov r5, r4 */
/* @0xd49b0 add r1, pc, r1 */
/* @0xd49b4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd49b8 b 0xd4928 <_Z5DoRemjPhPKhP6VMExec+0x624> */
/* @0xd49bc ldr r1, [pc, #0x68] */
/* @0xd49c0 mov r0, r10 */
/* @0xd49c4 mov r5, r4 */
/* @0xd49c8 add r1, pc, r1 */
/* @0xd49cc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd49d0 b 0xd4928 <_Z5DoRemjPhPKhP6VMExec+0x624> */
/* @0xd49d4 ldr r1, [pc, #0x54] */
/* @0xd49d8 mov r0, r10 */
/* @0xd49dc add r1, pc, r1 */
/* @0xd49e0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd49e4 b 0xd48c8 <_Z5DoRemjPhPKhP6VMExec+0x5c4> */
/* @0xd49e8 mov r5, r4 */
/* @0xd49ec mov r8, r1 */
/* @0xd49f0 b 0xd4360 <_Z5DoRemjPhPKhP6VMExec+0x5c> */
/* @0xd49f4 mov r6, r8 */
/* @0xd49f8 b 0xd43a0 <_Z5DoRemjPhPKhP6VMExec+0x9c> */
/* @0xd49fc eoreq lr, r5, r8, lsr #9 */
/* @0xd4a00 eoreq lr, r5, r8, ror #8 */
/* @0xd4a04 eoreq lr, r5, r4, ror #1 */
/* @0xd4a08 strhteq lr, [r5], -r4 */
/* @0xd4a0c eoreq sp, r5, r8, lsr #30 */
/* @0xd4a10 eoreq lr, r5, r0, asr #32 */
/* @0xd4a14 .word 0x0025dff0 */
/* @0xd4a18 .word 0x0025dffc */
/* @0xd4a1c eoreq sp, r5, r0, lsl pc */
/* @0xd4a20 eoreq sp, r5, r4, lsr pc */
/* @0xd4a24 eoreq sp, r5, r4, lsr #29 */
/* @0xd4a28 eoreq sp, r5, r12, lsr #29 */
/* @0xd4a2c eoreq sp, r5, r8, lsl #30 */
/* @0xd4a30 eoreq sp, r5, r12, ror #30 */

/* ── FUNC 0xd4a34 · DoPushLocal(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=420 · insn=105 */
/* @0xd4a34 ldr r0, [r3, #0x10] */
/* @0xd4a38 mov r12, #0 */
/* @0xd4a3c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xd4a40 mov r4, r1 */
/* @0xd4a44 ldr r7, [r2] */
/* @0xd4a48 mov r8, r3 */
/* @0xd4a4c ldr r6, [r0, #0x4] */
/* @0xd4a50 mvn r3, #-16777216 */
/* @0xd4a54 bic r7, r7, #-268435456 */
/* @0xd4a58 str r3, [r1, #-0x4] */
/* @0xd4a5c cmp r6, r12 */
/* @0xd4a60 sub r5, r7, #99328 */
/* @0xd4a64 sub sp, sp, #12 */
/* @0xd4a68 sub r1, r5, #672 */
/* @0xd4a6c sub r9, r4, #16 */
/* @0xd4a70 str r12, [r4, #-0x8] */
/* @0xd4a74 str r12, [r4, #-0xc] */
/* @0xd4a78 str r12, [r4, #-0x10] */
/* @0xd4a7c beq 0xd4bc8 <_Z11DoPushLocaljPhPKhP6VMExec+0x194> */
/* @0xd4a80 add r5, r6, r1, lsl #4 */
/* @0xd4a84 ldr r1, [r5, #0xc] */
/* @0xd4a88 ldr r3, [r5, #0x8] */
/* @0xd4a8c str r1, [r4, #-0x4] */
/* @0xd4a90 ldr r12, [r5, #0xc] */
/* @0xd4a94 str r3, [r4, #-0x8] */
/* @0xd4a98 bic r12, r12, #-16777216 */
/* @0xd4a9c cmp r12, #14 */
/* @0xd4aa0 addls pc, pc, r12, lsl #2 */
/* @0xd4aa4 b 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4aa8 b 0xd4b04 <_Z11DoPushLocaljPhPKhP6VMExec+0xd0> */
/* @0xd4aac b 0xd4b80 <_Z11DoPushLocaljPhPKhP6VMExec+0x14c> */
/* @0xd4ab0 b 0xd4b9c <_Z11DoPushLocaljPhPKhP6VMExec+0x168> */
/* @0xd4ab4 b 0xd4ae4 <_Z11DoPushLocaljPhPKhP6VMExec+0xb0> */
/* @0xd4ab8 b 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4abc b 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4ac0 b 0xd4b58 <_Z11DoPushLocaljPhPKhP6VMExec+0x124> */
/* @0xd4ac4 b 0xd4ae4 <_Z11DoPushLocaljPhPKhP6VMExec+0xb0> */
/* @0xd4ac8 b 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4acc b 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4ad0 b 0xd4b04 <_Z11DoPushLocaljPhPKhP6VMExec+0xd0> */
/* @0xd4ad4 b 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4ad8 b 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4adc b 0xd4b04 <_Z11DoPushLocaljPhPKhP6VMExec+0xd0> */
/* @0xd4ae0 b 0xd4ae4 <_Z11DoPushLocaljPhPKhP6VMExec+0xb0> */
/* @0xd4ae4 ldr r3, [r5] */
/* @0xd4ae8 str r3, [r4, #-0x10] */
/* @0xd4aec mvn r3, #-16777216 */
/* @0xd4af0 cmp r1, r3 */
/* @0xd4af4 beq 0xd4b1c <_Z11DoPushLocaljPhPKhP6VMExec+0xe8> */
/* @0xd4af8 mov r0, r9 */
/* @0xd4afc add sp, sp, #12 */
/* @0xd4b00 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xd4b04 ldm r5, {r2, r3} */
/* @0xd4b08 str r3, [r4, #-0xc] */
/* @0xd4b0c mvn r3, #-16777216 */
/* @0xd4b10 cmp r1, r3 */
/* @0xd4b14 str r2, [r4, #-0x10] */
/* @0xd4b18 bne 0xd4af8 <_Z11DoPushLocaljPhPKhP6VMExec+0xc4> */
/* @0xd4b1c mov r2, r7 */
/* @0xd4b20 ldr r0, [r8, #0x34] */
/* @0xd4b24 mvn r1, #6 */
/* @0xd4b28 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xd4b2c ldr r1, [pc, #0xa0] */
/* @0xd4b30 mov r12, #-2147483648 */
/* @0xd4b34 mov r3, r7 */
/* @0xd4b38 add r1, pc, r1 */
/* @0xd4b3c str r12, [sp] */
/* @0xd4b40 mov r2, r0 */
/* @0xd4b44 mov r0, r8 */
/* @0xd4b48 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd4b4c mov r0, r9 */
/* @0xd4b50 add sp, sp, #12 */
/* @0xd4b54 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xd4b58 ldr r3, [r5] */
/* @0xd4b5c str r3, [r4, #-0x10] */
/* @0xd4b60 ldr r3, [r5] */
/* @0xd4b64 cmp r3, #0 */
/* @0xd4b68 beq 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4b6c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xd4b70 ldr r1, [r5] */
/* @0xd4b74 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xd4b78 ldr r1, [r4, #-0x4] */
/* @0xd4b7c b 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4b80 ldr r3, [r5] */
/* @0xd4b84 cmp r3, #0 */
/* @0xd4b88 ldrne r2, [r3, #0x4] */
/* @0xd4b8c addne r2, r2, #1 */
/* @0xd4b90 strne r2, [r3, #0x4] */
/* @0xd4b94 ldrne r1, [r4, #-0x4] */
/* @0xd4b98 b 0xd4ae8 <_Z11DoPushLocaljPhPKhP6VMExec+0xb4> */
/* @0xd4b9c ldr r3, [r5] */
/* @0xd4ba0 cmp r3, #0 */
/* @0xd4ba4 str r3, [r4, #-0x10] */
/* @0xd4ba8 beq 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4bac ldr r0, [r3, #0x8] */
/* @0xd4bb0 ldr r2, [r3] */
/* @0xd4bb4 cmp r0, #0 */
/* @0xd4bb8 streq r9, [r3, #0x8] */
/* @0xd4bbc add r2, r2, #1 */
/* @0xd4bc0 str r2, [r3] */
/* @0xd4bc4 b 0xd4aec <_Z11DoPushLocaljPhPKhP6VMExec+0xb8> */
/* @0xd4bc8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xd4bcc mov r5, r0 */
/* @0xd4bd0 b 0xd4a84 <_Z11DoPushLocaljPhPKhP6VMExec+0x50> */
/* @0xd4bd4 eoreq sp, r5, r4, ror #28 */

/* ── FUNC 0xd4bd8 · DoPushGlobal(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=412 · insn=103 */
/* @0xd4bd8 ldr r12, [pc, #0x18c] */
/* @0xd4bdc push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xd4be0 ldr r12, [pc, r12] */
/* @0xd4be4 ldr r7, [r2] */
/* @0xd4be8 mov r4, r1 */
/* @0xd4bec ldr r0, [r12] */
/* @0xd4bf0 mov r12, #0 */
/* @0xd4bf4 bic r7, r7, #-268435456 */
/* @0xd4bf8 mov r9, r3 */
/* @0xd4bfc sub r5, r7, #99328 */
/* @0xd4c00 mvn r3, #-16777216 */
/* @0xd4c04 ldr r6, [r0, #0x4] */
/* @0xd4c08 sub r8, r4, #16 */
/* @0xd4c0c str r3, [r1, #-0x4] */
/* @0xd4c10 sub r1, r5, #672 */
/* @0xd4c14 cmp r6, r12 */
/* @0xd4c18 str r12, [r4, #-0x8] */
/* @0xd4c1c str r12, [r4, #-0xc] */
/* @0xd4c20 str r12, [r4, #-0x10] */
/* @0xd4c24 beq 0xd4d60 <_Z12DoPushGlobaljPhPKhP6VMExec+0x188> */
/* @0xd4c28 add r5, r6, r1, lsl #4 */
/* @0xd4c2c ldr r1, [r5, #0xc] */
/* @0xd4c30 ldr r3, [r5, #0x8] */
/* @0xd4c34 str r1, [r4, #-0x4] */
/* @0xd4c38 ldr r12, [r5, #0xc] */
/* @0xd4c3c str r3, [r4, #-0x8] */
/* @0xd4c40 bic r12, r12, #-16777216 */
/* @0xd4c44 cmp r12, #14 */
/* @0xd4c48 addls pc, pc, r12, lsl #2 */
/* @0xd4c4c b 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4c50 b 0xd4ca8 <_Z12DoPushGlobaljPhPKhP6VMExec+0xd0> */
/* @0xd4c54 b 0xd4d18 <_Z12DoPushGlobaljPhPKhP6VMExec+0x140> */
/* @0xd4c58 b 0xd4d34 <_Z12DoPushGlobaljPhPKhP6VMExec+0x15c> */
/* @0xd4c5c b 0xd4c8c <_Z12DoPushGlobaljPhPKhP6VMExec+0xb4> */
/* @0xd4c60 b 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4c64 b 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4c68 b 0xd4cf0 <_Z12DoPushGlobaljPhPKhP6VMExec+0x118> */
/* @0xd4c6c b 0xd4c8c <_Z12DoPushGlobaljPhPKhP6VMExec+0xb4> */
/* @0xd4c70 b 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4c74 b 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4c78 b 0xd4ca8 <_Z12DoPushGlobaljPhPKhP6VMExec+0xd0> */
/* @0xd4c7c b 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4c80 b 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4c84 b 0xd4ca8 <_Z12DoPushGlobaljPhPKhP6VMExec+0xd0> */
/* @0xd4c88 b 0xd4c8c <_Z12DoPushGlobaljPhPKhP6VMExec+0xb4> */
/* @0xd4c8c ldr r3, [r5] */
/* @0xd4c90 str r3, [r4, #-0x10] */
/* @0xd4c94 mvn r3, #-16777216 */
/* @0xd4c98 cmp r1, r3 */
/* @0xd4c9c beq 0xd4cc0 <_Z12DoPushGlobaljPhPKhP6VMExec+0xe8> */
/* @0xd4ca0 mov r0, r8 */
/* @0xd4ca4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xd4ca8 ldm r5, {r2, r3} */
/* @0xd4cac str r3, [r4, #-0xc] */
/* @0xd4cb0 mvn r3, #-16777216 */
/* @0xd4cb4 cmp r1, r3 */
/* @0xd4cb8 str r2, [r4, #-0x10] */
/* @0xd4cbc bne 0xd4ca0 <_Z12DoPushGlobaljPhPKhP6VMExec+0xc8> */
/* @0xd4cc0 mov r2, r7 */
/* @0xd4cc4 ldr r0, [r9, #0x34] */
/* @0xd4cc8 mvn r1, #4 */
/* @0xd4ccc bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xd4cd0 ldr r1, [pc, #0x98] */
/* @0xd4cd4 mov r3, r7 */
/* @0xd4cd8 add r1, pc, r1 */
/* @0xd4cdc mov r2, r0 */
/* @0xd4ce0 mov r0, r9 */
/* @0xd4ce4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd4ce8 mov r0, r8 */
/* @0xd4cec pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xd4cf0 ldr r3, [r5] */
/* @0xd4cf4 str r3, [r4, #-0x10] */
/* @0xd4cf8 ldr r3, [r5] */
/* @0xd4cfc cmp r3, #0 */
/* @0xd4d00 beq 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4d04 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xd4d08 ldr r1, [r5] */
/* @0xd4d0c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xd4d10 ldr r1, [r4, #-0x4] */
/* @0xd4d14 b 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4d18 ldr r3, [r5] */
/* @0xd4d1c cmp r3, #0 */
/* @0xd4d20 ldrne r2, [r3, #0x4] */
/* @0xd4d24 addne r2, r2, #1 */
/* @0xd4d28 strne r2, [r3, #0x4] */
/* @0xd4d2c ldrne r1, [r4, #-0x4] */
/* @0xd4d30 b 0xd4c90 <_Z12DoPushGlobaljPhPKhP6VMExec+0xb8> */
/* @0xd4d34 ldr r3, [r5] */
/* @0xd4d38 cmp r3, #0 */
/* @0xd4d3c str r3, [r4, #-0x10] */
/* @0xd4d40 beq 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4d44 ldr r0, [r3, #0x8] */
/* @0xd4d48 ldr r2, [r3] */
/* @0xd4d4c cmp r0, #0 */
/* @0xd4d50 streq r8, [r3, #0x8] */
/* @0xd4d54 add r2, r2, #1 */
/* @0xd4d58 str r2, [r3] */
/* @0xd4d5c b 0xd4c94 <_Z12DoPushGlobaljPhPKhP6VMExec+0xbc> */
/* @0xd4d60 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xd4d64 mov r5, r0 */
/* @0xd4d68 b 0xd4c2c <_Z12DoPushGlobaljPhPKhP6VMExec+0x54> */
/* @0xd4d6c ldrsbteq r8, [r1], -r4 */
/* @0xd4d70 .word 0x0025dcfc */

/* ── FUNC 0xd4d74 · DoPushBuiltin(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=136 · insn=34 */
/* @0xd4d74 push {r3, r4, r5, lr} */
/* @0xd4d78 mov r0, #0 */
/* @0xd4d7c ldr lr, [pc, #0x6c] */
/* @0xd4d80 sub r5, r1, #16 */
/* @0xd4d84 ldr r4, [r2] */
/* @0xd4d88 ldr lr, [pc, lr] */
/* @0xd4d8c str r0, [r1, #-0x4] */
/* @0xd4d90 str r0, [r1, #-0x8] */
/* @0xd4d94 bic r4, r4, #-268435456 */
/* @0xd4d98 str r0, [r1, #-0xc] */
/* @0xd4d9c str r0, [r1, #-0x10] */
/* @0xd4da0 ldr lr, [lr] */
/* @0xd4da4 cmp r4, lr */
/* @0xd4da8 blt 0xd4dcc <_Z13DoPushBuiltinjPhPKhP6VMExec+0x58> */
/* @0xd4dac ldr r1, [pc, #0x40] */
/* @0xd4db0 mov r0, r3 */
/* @0xd4db4 mov r2, r4 */
/* @0xd4db8 mov r3, lr */
/* @0xd4dbc add r1, pc, r1 */
/* @0xd4dc0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd4dc4 mov r0, r5 */
/* @0xd4dc8 pop {r3, r4, r5, pc} */
/* @0xd4dcc ldr r3, [pc, #0x24] */
/* @0xd4dd0 mov r1, #-2147483648 */
/* @0xd4dd4 mov r2, r5 */
/* @0xd4dd8 ldr r3, [pc, r3] */
/* @0xd4ddc add r4, r3, r4, lsl #4 */
/* @0xd4de0 ldr r3, [r4, #0x4] */
/* @0xd4de4 blx r3 */
/* @0xd4de8 mov r0, r5 */
/* @0xd4dec pop {r3, r4, r5, pc} */
/* @0xd4df0 eorseq r8, r1, r12, lsr #29 */
/* @0xd4df4 eoreq sp, r5, r8, asr r12 */
/* @0xd4df8 eorseq r8, r1, r0, ror #28 */

/* ── FUNC 0xd4dfc · DoPushEnv(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=1664 · insn=416 */
/* @0xd4dfc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd4e00 tst r0, #8388608 */
/* @0xd4e04 ldr r7, [pc, #0x644] */
/* @0xd4e08 sub sp, sp, #12 */
/* @0xd4e0c mov r8, r0 */
/* @0xd4e10 mov r4, r1 */
/* @0xd4e14 mov r5, r3 */
/* @0xd4e18 add r7, pc, r7 */
/* @0xd4e1c beq 0xd4e50 <_Z9DoPushEnvjPhPKhP6VMExec+0x54> */
/* @0xd4e20 ldr r3, [r1, #0xc] */
/* @0xd4e24 bic r3, r3, #-16777216 */
/* @0xd4e28 cmp r3, #6 */
/* @0xd4e2c beq 0xd4e84 <_Z9DoPushEnvjPhPKhP6VMExec+0x88> */
/* @0xd4e30 ldr r1, [pc, #0x61c] */
/* @0xd4e34 mov r0, r5 */
/* @0xd4e38 add r6, r4, #16 */
/* @0xd4e3c add r1, pc, r1 */
/* @0xd4e40 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd4e44 mov r0, r6 */
/* @0xd4e48 add sp, sp, #12 */
/* @0xd4e4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd4e50 mov r6, r1 */
/* @0xd4e54 ldr r2, [r6], #4 */
/* @0xd4e58 add r3, r2, #7 */
/* @0xd4e5c cmp r3, #6 */
/* @0xd4e60 addls pc, pc, r3, lsl #2 */
/* @0xd4e64 b 0xd5034 <_Z9DoPushEnvjPhPKhP6VMExec+0x238> */
/* @0xd4e68 b 0xd4ed8 <_Z9DoPushEnvjPhPKhP6VMExec+0xdc> */
/* @0xd4e6c b 0xd4eec <_Z9DoPushEnvjPhPKhP6VMExec+0xf0> */
/* @0xd4e70 b 0xd4f08 <_Z9DoPushEnvjPhPKhP6VMExec+0x10c> */
/* @0xd4e74 b 0xd4f1c <_Z9DoPushEnvjPhPKhP6VMExec+0x120> */
/* @0xd4e78 b 0xd4f6c <_Z9DoPushEnvjPhPKhP6VMExec+0x170> */
/* @0xd4e7c b 0xd4eb8 <_Z9DoPushEnvjPhPKhP6VMExec+0xbc> */
/* @0xd4e80 b 0xd4eec <_Z9DoPushEnvjPhPKhP6VMExec+0xf0> */
/* @0xd4e84 ldr r3, [r5, #0x14] */
/* @0xd4e88 mov r2, #0 */
/* @0xd4e8c add r6, r1, #4 */
/* @0xd4e90 str r3, [r1, #0xc] */
/* @0xd4e94 mov r0, r6 */
/* @0xd4e98 ldr r3, [r5, #0x18] */
/* @0xd4e9c stmib r1, {r2, r3} */
/* @0xd4ea0 ldr r3, [r5, #0x14] */
/* @0xd4ea4 str r3, [r5, #0x18] */
/* @0xd4ea8 ldr r3, [r1] */
/* @0xd4eac str r3, [r5, #0x14] */
/* @0xd4eb0 add sp, sp, #12 */
/* @0xd4eb4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd4eb8 ldr r3, [r5, #0x14] */
/* @0xd4ebc mov r1, #0 */
/* @0xd4ec0 ldr r2, [r5, #0x18] */
/* @0xd4ec4 sub r6, r4, #8 */
/* @0xd4ec8 stmda r4, {r1, r2, r3} */
/* @0xd4ecc str r2, [r5, #0x14] */
/* @0xd4ed0 str r3, [r5, #0x18] */
/* @0xd4ed4 b 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */
/* @0xd4ed8 ldr r1, [pc, #0x578] */
/* @0xd4edc mov r0, r5 */
/* @0xd4ee0 add r1, pc, r1 */
/* @0xd4ee4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd4ee8 b 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */
/* @0xd4eec ldr r3, [r5, #0x14] */
/* @0xd4ef0 mov r1, #0 */
/* @0xd4ef4 ldr r2, [r5, #0x18] */
/* @0xd4ef8 sub r6, r4, #8 */
/* @0xd4efc stmda r4, {r1, r2, r3} */
/* @0xd4f00 str r3, [r5, #0x18] */
/* @0xd4f04 b 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */
/* @0xd4f08 ldr r1, [pc, #0x54c] */
/* @0xd4f0c mov r0, r5 */
/* @0xd4f10 add r1, pc, r1 */
/* @0xd4f14 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd4f18 b 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */
/* @0xd4f1c ldr r0, [r5, #0x44] */
/* @0xd4f20 lsl r8, r8, #9 */
/* @0xd4f24 ldr r3, [r5, #0x18] */
/* @0xd4f28 mov r2, #0 */
/* @0xd4f2c sub r0, r0, #4 */
/* @0xd4f30 ldr r1, [r5, #0x14] */
/* @0xd4f34 add r8, r0, r8, asr #7 */
/* @0xd4f38 str r2, [r4, #-0x8] */
/* @0xd4f3c cmp r8, #0 */
/* @0xd4f40 add r2, r8, #3 */
/* @0xd4f44 str r1, [r4] */
/* @0xd4f48 sub r6, r4, #8 */
/* @0xd4f4c str r3, [r4, #-0x4] */
/* @0xd4f50 movge r2, r8 */
/* @0xd4f54 ldr r3, [r5, #0x5c] */
/* @0xd4f58 asr r2, r2, #2 */
/* @0xd4f5c str r8, [r5, #0x44] */
/* @0xd4f60 ldr r3, [r3, r2, lsl #2] */
/* @0xd4f64 str r3, [r5, #0x48] */
/* @0xd4f68 b 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */
/* @0xd4f6c ldr r3, [r5, #0x14] */
/* @0xd4f70 ldr r1, [r5, #0x18] */
/* @0xd4f74 ldr r2, [pc, #0x4e4] */
/* @0xd4f78 stmda r4, {r1, r3} */
/* @0xd4f7c str r3, [r5, #0x18] */
/* @0xd4f80 ldr r7, [r7, r2] */
/* @0xd4f84 ldr r3, [r7] */
/* @0xd4f88 ldr r3, [r3, #0x80] */
/* @0xd4f8c cmp r3, #0 */
/* @0xd4f90 beq 0xd53e8 <_Z9DoPushEnvjPhPKhP6VMExec+0x5ec> */
/* @0xd4f94 mov r0, #0 */
/* @0xd4f98 mov r1, r0 */
/* @0xd4f9c ldrb r2, [r3, #0x68] */
/* @0xd4fa0 ldr r6, [r3, #0x178] */
/* @0xd4fa4 cmp r2, #0 */
/* @0xd4fa8 bne 0xd4fc0 <_Z9DoPushEnvjPhPKhP6VMExec+0x1c4> */
/* @0xd4fac ldrb r2, [r3, #0x69] */
/* @0xd4fb0 cmp r2, #0 */
/* @0xd4fb4 addeq r0, r0, #1 */
/* @0xd4fb8 streq r1, [r5, #0x14] */
/* @0xd4fbc moveq r1, r3 */
/* @0xd4fc0 cmp r6, #0 */
/* @0xd4fc4 mov r3, r6 */
/* @0xd4fc8 bne 0xd4f9c <_Z9DoPushEnvjPhPKhP6VMExec+0x1a0> */
/* @0xd4fcc cmp r0, #2 */
/* @0xd4fd0 bgt 0xd5324 <_Z9DoPushEnvjPhPKhP6VMExec+0x528> */
/* @0xd4fd4 streq r6, [r4, #-0x8] */
/* @0xd4fd8 subeq r6, r4, #12 */
/* @0xd4fdc streq r1, [r4, #-0xc] */
/* @0xd4fe0 beq 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */
/* @0xd4fe4 cmp r0, #1 */
/* @0xd4fe8 streq r6, [r4, #-0x8] */
/* @0xd4fec subeq r6, r4, #8 */
/* @0xd4ff0 streq r1, [r5, #0x14] */
/* @0xd4ff4 beq 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */
/* @0xd4ff8 ldr r2, [r5, #0x44] */
/* @0xd4ffc lsl r8, r8, #9 */
/* @0xd5000 str r1, [r4, #-0x8] */
/* @0xd5004 sub r6, r4, #8 */
/* @0xd5008 sub r2, r2, #4 */
/* @0xd500c ldr r3, [r5, #0x5c] */
/* @0xd5010 add r8, r2, r8, asr #7 */
/* @0xd5014 str r8, [r5, #0x44] */
/* @0xd5018 add r2, r8, #3 */
/* @0xd501c cmp r8, #0 */
/* @0xd5020 movlt r8, r2 */
/* @0xd5024 asr r8, r8, #2 */
/* @0xd5028 ldr r3, [r3, r8, lsl #2] */
/* @0xd502c str r3, [r5, #0x48] */
/* @0xd5030 b 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */
/* @0xd5034 ldr r0, [r5, #0x14] */
/* @0xd5038 cmp r2, #0 */
/* @0xd503c ldr r3, [r5, #0x18] */
/* @0xd5040 str r0, [r1] */
/* @0xd5044 str r3, [r1, #-0x4] */
/* @0xd5048 blt 0xd52f8 <_Z9DoPushEnvjPhPKhP6VMExec+0x4fc> */
/* @0xd504c movw r3, #0x869f */
/* @0xd5050 movt r3, #0x1 */
/* @0xd5054 cmp r2, r3 */
/* @0xd5058 bgt 0xd51b4 <_Z9DoPushEnvjPhPKhP6VMExec+0x3b8> */
/* @0xd505c ldr r3, [pc, #0x400] */
/* @0xd5060 str r0, [r5, #0x18] */
/* @0xd5064 ldr r3, [r7, r3] */
/* @0xd5068 ldr r3, [r3] */
/* @0xd506c ldr r1, [r3, #0x4] */
/* @0xd5070 ldr r3, [r3] */
/* @0xd5074 and r1, r2, r1 */
/* @0xd5078 ldr r3, [r3, r1, lsl #3] */
/* @0xd507c cmp r3, #0 */
/* @0xd5080 bne 0xd5094 <_Z9DoPushEnvjPhPKhP6VMExec+0x298> */
/* @0xd5084 b 0xd5404 <_Z9DoPushEnvjPhPKhP6VMExec+0x608> */
/* @0xd5088 ldr r3, [r3, #0x4] */
/* @0xd508c cmp r3, #0 */
/* @0xd5090 beq 0xd5404 <_Z9DoPushEnvjPhPKhP6VMExec+0x608> */
/* @0xd5094 ldr r1, [r3, #0x8] */
/* @0xd5098 cmp r2, r1 */
/* @0xd509c bne 0xd5088 <_Z9DoPushEnvjPhPKhP6VMExec+0x28c> */
/* @0xd50a0 ldr r11, [r3, #0xc] */
/* @0xd50a4 cmp r11, #0 */
/* @0xd50a8 beq 0xd5404 <_Z9DoPushEnvjPhPKhP6VMExec+0x608> */
/* @0xd50ac ldr r6, [r11, #0xd0] */
/* @0xd50b0 cmp r6, #0 */
/* @0xd50b4 beq 0xd5444 <_Z9DoPushEnvjPhPKhP6VMExec+0x648> */
/* @0xd50b8 ldr r3, [r6, #0x8] */
/* @0xd50bc cmp r3, #0 */
/* @0xd50c0 moveq r10, r3 */
/* @0xd50c4 beq 0xd512c <_Z9DoPushEnvjPhPKhP6VMExec+0x330> */
/* @0xd50c8 mov r3, #0 */
/* @0xd50cc mov r10, r3 */
/* @0xd50d0 b 0xd50e0 <_Z9DoPushEnvjPhPKhP6VMExec+0x2e4> */
/* @0xd50d4 ldr r2, [r6, #0x8] */
/* @0xd50d8 cmp r2, #0 */
/* @0xd50dc beq 0xd512c <_Z9DoPushEnvjPhPKhP6VMExec+0x330> */
/* @0xd50e0 ldr r9, [r6, #0x8] */
/* @0xd50e4 ldr r6, [r6] */
/* @0xd50e8 cmp r9, #0 */
/* @0xd50ec beq 0xd5124 <_Z9DoPushEnvjPhPKhP6VMExec+0x328> */
/* @0xd50f0 ldrb r2, [r9, #0x68] */
/* @0xd50f4 cmp r2, #0 */
/* @0xd50f8 bne 0xd5124 <_Z9DoPushEnvjPhPKhP6VMExec+0x328> */
/* @0xd50fc ldrb r2, [r9, #0x69] */
/* @0xd5100 mov r0, r9 */
/* @0xd5104 cmp r2, #0 */
/* @0xd5108 bne 0xd5124 <_Z9DoPushEnvjPhPKhP6VMExec+0x328> */
/* @0xd510c str r3, [sp] */
/* @0xd5110 bl 0xd3fd0 <_Z14HandleInstanceP9CInstance> */
/* @0xd5114 ldr r3, [sp] */
/* @0xd5118 str r10, [r5, #0x14] */
/* @0xd511c mov r10, r9 */
/* @0xd5120 add r3, r3, #1 */
/* @0xd5124 cmp r6, #0 */
/* @0xd5128 bne 0xd50d4 <_Z9DoPushEnvjPhPKhP6VMExec+0x2d8> */
/* @0xd512c ldr r2, [pc, #0x334] */
/* @0xd5130 ldr r11, [r11, #0x18] */
/* @0xd5134 ldr r2, [r7, r2] */
/* @0xd5138 ldr r1, [r2, #0x8] */
/* @0xd513c cmp r1, #0 */
/* @0xd5140 ble 0xd5228 <_Z9DoPushEnvjPhPKhP6VMExec+0x42c> */
/* @0xd5144 mov r6, #0 */
/* @0xd5148 b 0xd515c <_Z9DoPushEnvjPhPKhP6VMExec+0x360> */
/* @0xd514c ldr r1, [r2, #0x8] */
/* @0xd5150 add r6, r6, #1 */
/* @0xd5154 cmp r1, r6 */
/* @0xd5158 ble 0xd5228 <_Z9DoPushEnvjPhPKhP6VMExec+0x42c> */
/* @0xd515c ldr r1, [r2] */
/* @0xd5160 ldr r9, [r1, r6, lsl #2] */
/* @0xd5164 ldr r1, [r9, #0x7c] */
/* @0xd5168 cmp r11, r1 */
/* @0xd516c bne 0xd514c <_Z9DoPushEnvjPhPKhP6VMExec+0x350> */
/* @0xd5170 ldrb r1, [r9, #0x68] */
/* @0xd5174 cmp r1, #0 */
/* @0xd5178 bne 0xd514c <_Z9DoPushEnvjPhPKhP6VMExec+0x350> */
/* @0xd517c ldrb r1, [r9, #0x69] */
/* @0xd5180 cmp r1, #0 */
/* @0xd5184 bne 0xd514c <_Z9DoPushEnvjPhPKhP6VMExec+0x350> */
/* @0xd5188 mov r0, r9 */
/* @0xd518c str r2, [sp, #0x4] */
/* @0xd5190 str r3, [sp] */
/* @0xd5194 bl 0xd3f50 <_Z15InstanceHandledP9CInstance> */
/* @0xd5198 ldr r2, [sp, #0x4] */
/* @0xd519c ldr r3, [sp] */
/* @0xd51a0 cmp r0, #0 */
/* @0xd51a4 streq r10, [r5, #0x14] */
/* @0xd51a8 addeq r3, r3, #1 */
/* @0xd51ac moveq r10, r9 */
/* @0xd51b0 b 0xd514c <_Z9DoPushEnvjPhPKhP6VMExec+0x350> */
/* @0xd51b4 ldr r3, [pc, #0x2b0] */
/* @0xd51b8 ldr r3, [r7, r3] */
/* @0xd51bc ldr r1, [r3, #0x4] */
/* @0xd51c0 ldr r3, [r3] */
/* @0xd51c4 and r1, r2, r1 */
/* @0xd51c8 ldr r3, [r3, r1, lsl #3] */
/* @0xd51cc cmp r3, #0 */
/* @0xd51d0 bne 0xd51e4 <_Z9DoPushEnvjPhPKhP6VMExec+0x3e8> */
/* @0xd51d4 b 0xd52f8 <_Z9DoPushEnvjPhPKhP6VMExec+0x4fc> */
/* @0xd51d8 ldr r3, [r3, #0x4] */
/* @0xd51dc cmp r3, #0 */
/* @0xd51e0 beq 0xd52f8 <_Z9DoPushEnvjPhPKhP6VMExec+0x4fc> */
/* @0xd51e4 ldr r1, [r3, #0x8] */
/* @0xd51e8 cmp r2, r1 */
/* @0xd51ec bne 0xd51d8 <_Z9DoPushEnvjPhPKhP6VMExec+0x3dc> */
/* @0xd51f0 ldr r3, [r3, #0xc] */
/* @0xd51f4 cmp r3, #0 */
/* @0xd51f8 beq 0xd52f8 <_Z9DoPushEnvjPhPKhP6VMExec+0x4fc> */
/* @0xd51fc ldrb r2, [r3, #0x68] */
/* @0xd5200 cmp r2, #0 */
/* @0xd5204 bne 0xd52f8 <_Z9DoPushEnvjPhPKhP6VMExec+0x4fc> */
/* @0xd5208 ldrb r2, [r3, #0x69] */
/* @0xd520c cmp r2, #0 */
/* @0xd5210 bne 0xd52f8 <_Z9DoPushEnvjPhPKhP6VMExec+0x4fc> */
/* @0xd5214 str r2, [r4, #-0x8] */
/* @0xd5218 sub r6, r4, #8 */
/* @0xd521c str r3, [r5, #0x14] */
/* @0xd5220 str r0, [r5, #0x18] */
/* @0xd5224 b 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */
/* @0xd5228 ldr r2, [pc, #0x240] */
/* @0xd522c ldr r9, [r7, r2] */
/* @0xd5230 ldr r2, [r9, #0x8] */
/* @0xd5234 cmp r2, #0 */
/* @0xd5238 ble 0xd52a4 <_Z9DoPushEnvjPhPKhP6VMExec+0x4a8> */
/* @0xd523c mov r6, #0 */
/* @0xd5240 b 0xd5254 <_Z9DoPushEnvjPhPKhP6VMExec+0x458> */
/* @0xd5244 ldr r2, [r9, #0x8] */
/* @0xd5248 add r6, r6, #1 */
/* @0xd524c cmp r2, r6 */
/* @0xd5250 ble 0xd52a4 <_Z9DoPushEnvjPhPKhP6VMExec+0x4a8> */
/* @0xd5254 ldr r2, [r9] */
/* @0xd5258 ldr r7, [r2, r6, lsl #2] */
/* @0xd525c ldr r2, [r7, #0x7c] */
/* @0xd5260 cmp r11, r2 */
/* @0xd5264 bne 0xd5244 <_Z9DoPushEnvjPhPKhP6VMExec+0x448> */
/* @0xd5268 ldrb r2, [r7, #0x68] */
/* @0xd526c cmp r2, #0 */
/* @0xd5270 bne 0xd5244 <_Z9DoPushEnvjPhPKhP6VMExec+0x448> */
/* @0xd5274 ldrb r2, [r7, #0x69] */
/* @0xd5278 cmp r2, #0 */
/* @0xd527c bne 0xd5244 <_Z9DoPushEnvjPhPKhP6VMExec+0x448> */
/* @0xd5280 mov r0, r7 */
/* @0xd5284 str r3, [sp] */
/* @0xd5288 bl 0xd3f50 <_Z15InstanceHandledP9CInstance> */
/* @0xd528c ldr r3, [sp] */
/* @0xd5290 cmp r0, #0 */
/* @0xd5294 streq r10, [r5, #0x14] */
/* @0xd5298 addeq r3, r3, #1 */
/* @0xd529c moveq r10, r7 */
/* @0xd52a0 b 0xd5244 <_Z9DoPushEnvjPhPKhP6VMExec+0x448> */
/* @0xd52a4 cmp r3, #2 */
/* @0xd52a8 bgt 0xd5398 <_Z9DoPushEnvjPhPKhP6VMExec+0x59c> */
/* @0xd52ac beq 0xd53d4 <_Z9DoPushEnvjPhPKhP6VMExec+0x5d8> */
/* @0xd52b0 cmp r3, #1 */
/* @0xd52b4 beq 0xd53f0 <_Z9DoPushEnvjPhPKhP6VMExec+0x5f4> */
/* @0xd52b8 ldr r3, [r5, #0x44] */
/* @0xd52bc lsl r8, r8, #9 */
/* @0xd52c0 str r10, [r4, #-0x8] */
/* @0xd52c4 sub r6, r4, #8 */
/* @0xd52c8 sub r3, r3, #4 */
/* @0xd52cc ldr r2, [r5, #0x5c] */
/* @0xd52d0 add r3, r3, r8, asr #7 */
/* @0xd52d4 str r3, [r5, #0x44] */
/* @0xd52d8 add r1, r3, #3 */
/* @0xd52dc cmp r3, #0 */
/* @0xd52e0 movlt r3, r1 */
/* @0xd52e4 asr r3, r3, #2 */
/* @0xd52e8 ldr r3, [r2, r3, lsl #2] */
/* @0xd52ec str r3, [r5, #0x48] */
/* @0xd52f0 bl 0xd3ee0 <_Z21ClearHandledContainerv> */
/* @0xd52f4 b 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */
/* @0xd52f8 ldr r2, [r5, #0x44] */
/* @0xd52fc lsl r8, r8, #9 */
/* @0xd5300 mov r3, #0 */
/* @0xd5304 sub r6, r4, #8 */
/* @0xd5308 sub r2, r2, #4 */
/* @0xd530c str r3, [r4, #-0x8] */
/* @0xd5310 add r8, r2, r8, asr #7 */
/* @0xd5314 ldr r3, [r5, #0x5c] */
/* @0xd5318 str r8, [r5, #0x44] */
/* @0xd531c add r2, r8, #3 */
/* @0xd5320 b 0xd501c <_Z9DoPushEnvjPhPKhP6VMExec+0x220> */
/* @0xd5324 ldr r1, [pc, #0x148] */
/* @0xd5328 mov r3, #1 */
/* @0xd532c lsl r0, r0, #2 */
/* @0xd5330 movw r2, #0x2241 */
/* @0xd5334 add r1, pc, r1 */
/* @0xd5338 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd533c ldr r3, [r7] */
/* @0xd5340 ldr r3, [r3, #0x80] */
/* @0xd5344 cmp r3, #0 */
/* @0xd5348 mov r12, r0 */
/* @0xd534c beq 0xd5380 <_Z9DoPushEnvjPhPKhP6VMExec+0x584> */
/* @0xd5350 ldrb r1, [r3, #0x68] */
/* @0xd5354 ldr r2, [r3, #0x178] */
/* @0xd5358 cmp r1, #0 */
/* @0xd535c bne 0xd5374 <_Z9DoPushEnvjPhPKhP6VMExec+0x578> */
/* @0xd5360 ldrb r1, [r3, #0x69] */
/* @0xd5364 cmp r1, #0 */
/* @0xd5368 streq r6, [r12], #4 */
/* @0xd536c moveq r6, r3 */
/* @0xd5370 streq r3, [r5, #0x14] */
/* @0xd5374 cmp r2, #0 */
/* @0xd5378 mov r3, r2 */
/* @0xd537c bne 0xd5350 <_Z9DoPushEnvjPhPKhP6VMExec+0x554> */
/* @0xd5380 mvn r3, #0 */
/* @0xd5384 str r0, [r4, #-0x8] */
/* @0xd5388 str r12, [r4, #-0xc] */
/* @0xd538c sub r6, r4, #16 */
/* @0xd5390 str r3, [r4, #-0x10] */
/* @0xd5394 b 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */
/* @0xd5398 ldr r1, [pc, #0xd8] */
/* @0xd539c lsl r0, r3, #2 */
/* @0xd53a0 movw r2, #0x22c8 */
/* @0xd53a4 mov r3, #1 */
/* @0xd53a8 add r1, pc, r1 */
/* @0xd53ac sub r6, r4, #16 */
/* @0xd53b0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd53b4 mov r1, r5 */
/* @0xd53b8 mov r7, r0 */
/* @0xd53bc bl 0xd410c <_Z16IterateInstancesPP12YYObjectBaseP6VMExec> */
/* @0xd53c0 mvn r3, #0 */
/* @0xd53c4 str r7, [r4, #-0x8] */
/* @0xd53c8 str r3, [r4, #-0x10] */
/* @0xd53cc str r0, [r4, #-0xc] */
/* @0xd53d0 b 0xd52f0 <_Z9DoPushEnvjPhPKhP6VMExec+0x4f4> */
/* @0xd53d4 mov r3, #0 */
/* @0xd53d8 str r10, [r4, #-0xc] */
/* @0xd53dc sub r6, r4, #12 */
/* @0xd53e0 str r3, [r4, #-0x8] */
/* @0xd53e4 b 0xd52f0 <_Z9DoPushEnvjPhPKhP6VMExec+0x4f4> */
/* @0xd53e8 mov r1, r3 */
/* @0xd53ec b 0xd4ff8 <_Z9DoPushEnvjPhPKhP6VMExec+0x1fc> */
/* @0xd53f0 mov r3, #0 */
/* @0xd53f4 sub r6, r4, #8 */
/* @0xd53f8 str r3, [r4, #-0x8] */
/* @0xd53fc str r10, [r5, #0x14] */
/* @0xd5400 b 0xd52f0 <_Z9DoPushEnvjPhPKhP6VMExec+0x4f4> */
/* @0xd5404 ldr r3, [r5, #0x44] */
/* @0xd5408 lsl r8, r8, #9 */
/* @0xd540c mov r2, #0 */
/* @0xd5410 str r2, [r4, #-0x8] */
/* @0xd5414 sub r3, r3, #4 */
/* @0xd5418 ldr r2, [r5, #0x5c] */
/* @0xd541c add r3, r3, r8, asr #7 */
/* @0xd5420 str r3, [r5, #0x44] */
/* @0xd5424 add r1, r3, #3 */
/* @0xd5428 cmp r3, #0 */
/* @0xd542c sub r6, r4, #8 */
/* @0xd5430 movlt r3, r1 */
/* @0xd5434 asr r3, r3, #2 */
/* @0xd5438 ldr r3, [r2, r3, lsl #2] */
/* @0xd543c str r3, [r5, #0x48] */
/* @0xd5440 b 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */
/* @0xd5444 mov r3, r6 */
/* @0xd5448 mov r10, r6 */
/* @0xd544c b 0xd512c <_Z9DoPushEnvjPhPKhP6VMExec+0x330> */
/* @0xd5450 eorseq r12, r1, r8, lsr lr */
/* @0xd5454 eoreq sp, r5, r8, lsl r12 */
/* @0xd5458 mlaeq r5, r12, r11, sp */
/* @0xd545c eoreq sp, r5, r8, asr #22 */
/* @0xd5460 .word 0xffffbcd8 */
/* @0xd5464 .word 0xffffbfec */
/* @0xd5468 .word 0xffffbff0 */
/* @0xd546c .word 0xffffbff4 */
/* @0xd5470 .word 0xffffbff8 */
/* @0xd5474 eoreq sp, r5, r8, asr #8 */
/* @0xd5478 .word 0x0025d3d4 */

/* ── FUNC 0xd547c · YYError(char const*, ...) · size=228 · insn=57 */
/* @0xd547c push {r0, r1, r2, r3} */
/* @0xd5480 push {r4, r5, r6, r7, lr} */
/* @0xd5484 sub sp, sp, #1024 */
/* @0xd5488 ldr r4, [pc, #0xbc] */
/* @0xd548c sub sp, sp, #12 */
/* @0xd5490 ldr r2, [pc, #0xb8] */
/* @0xd5494 add r4, pc, r4 */
/* @0xd5498 ldr r3, [pc, #0xb4] */
/* @0xd549c ldr r1, [sp, #0x420] */
/* @0xd54a0 ldr r5, [r4, r2] */
/* @0xd54a4 ldr r2, [r5] */
/* @0xd54a8 str r2, [sp, #0x404] */
/* @0xd54ac ldr r6, [r4, r3] */
/* @0xd54b0 ldrb r3, [r6] */
/* @0xd54b4 cmp r3, #0 */
/* @0xd54b8 beq 0xd54f0 <_Z7YYErrorPKcz+0x74> */
/* @0xd54bc ldr r3, [pc, #0x94] */
/* @0xd54c0 mov r2, #1 */
/* @0xd54c4 ldr r3, [r4, r3] */
/* @0xd54c8 strb r2, [r3] */
/* @0xd54cc ldr r2, [sp, #0x404] */
/* @0xd54d0 ldr r3, [r5] */
/* @0xd54d4 cmp r2, r3 */
/* @0xd54d8 bne 0xd5540 <_Z7YYErrorPKcz+0xc4> */
/* @0xd54dc add sp, sp, #1024 */
/* @0xd54e0 add sp, sp, #12 */
/* @0xd54e4 pop {r4, r5, r6, r7, lr} */
/* @0xd54e8 add sp, sp, #16 */
/* @0xd54ec bx lr */
/* @0xd54f0 add r3, sp, #1056 */
/* @0xd54f4 add r7, sp, #4 */
/* @0xd54f8 add r3, r3, #4 */
/* @0xd54fc str r3, [sp] */
/* @0xd5500 mov r0, r7 */
/* @0xd5504 mov r2, r3 */
/* @0xd5508 bl 0xb667c <vsprintf@plt> */
/* @0xd550c ldrb r3, [r6] */
/* @0xd5510 cmp r3, #0 */
/* @0xd5514 bne 0xd54cc <_Z7YYErrorPKcz+0x50> */
/* @0xd5518 mov r0, r7 */
/* @0xd551c mov r1, #1 */
/* @0xd5520 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xd5524 ldr r3, [pc, #0x30] */
/* @0xd5528 ldr r3, [r4, r3] */
/* @0xd552c ldrb r3, [r3] */
/* @0xd5530 cmp r3, #0 */
/* @0xd5534 beq 0xd5544 <_Z7YYErrorPKcz+0xc8> */
/* @0xd5538 bl 0x10c320 <_Z14YYGML_game_endv> */
/* @0xd553c b 0xd54cc <_Z7YYErrorPKcz+0x50> */
/* @0xd5540 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xd5544 mov r0, #1 */
/* @0xd5548 bl 0xb6688 <exit@plt> */
/* @0xd554c ldrhteq r12, [r1], -r12 */
/* @0xd5550 .word 0xffffbd00 */
/* @0xd5554 .word 0xffffbfdc */
/* @0xd5558 .word 0xffffbf14 */
/* @0xd555c .word 0xffffbfe0 */

/* ── FUNC 0xd5560 · DoDup(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=728 · insn=182 */
/* @0xd5560 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd5564 add r11, sp, #32 */
/* @0xd5568 ldr r6, [pc, #0x2bc] */
/* @0xd556c sub sp, sp, #20 */
/* @0xd5570 tst r0, #65280 */
/* @0xd5574 ldr r6, [pc, r6] */
/* @0xd5578 mov r7, r1 */
/* @0xd557c lsr r3, r0, #16 */
/* @0xd5580 ldr r2, [r6] */
/* @0xd5584 str r2, [r11, #-0x28] */
/* @0xd5588 beq 0xd55e0 <_Z5DoDupjPhPKhP6VMExec+0x80> */
/* @0xd558c uxtb r1, r3 */
/* @0xd5590 cmp r1, #6 */
/* @0xd5594 addls pc, pc, r1, lsl #2 */
/* @0xd5598 b 0xd55c4 <_Z5DoDupjPhPKhP6VMExec+0x64> */
/* @0xd559c b 0xd55b8 <_Z5DoDupjPhPKhP6VMExec+0x58> */
/* @0xd55a0 b 0xd55b8 <_Z5DoDupjPhPKhP6VMExec+0x58> */
/* @0xd55a4 b 0xd55b8 <_Z5DoDupjPhPKhP6VMExec+0x58> */
/* @0xd55a8 b 0xd55b8 <_Z5DoDupjPhPKhP6VMExec+0x58> */
/* @0xd55ac b 0xd55b8 <_Z5DoDupjPhPKhP6VMExec+0x58> */
/* @0xd55b0 b 0xd5620 <_Z5DoDupjPhPKhP6VMExec+0xc0> */
/* @0xd55b4 b 0xd55b8 <_Z5DoDupjPhPKhP6VMExec+0x58> */
/* @0xd55b8 ldr r0, [pc, #0x270] */
/* @0xd55bc add r0, pc, r0 */
/* @0xd55c0 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xd55c4 ldr r2, [r11, #-0x28] */
/* @0xd55c8 mov r0, r7 */
/* @0xd55cc ldr r3, [r6] */
/* @0xd55d0 cmp r2, r3 */
/* @0xd55d4 bne 0xd5828 <_Z5DoDupjPhPKhP6VMExec+0x2c8> */
/* @0xd55d8 sub sp, r11, #32 */
/* @0xd55dc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd55e0 ands r2, r0, #32768 */
/* @0xd55e4 ubfx r5, r0, #0x0, #0xf */
/* @0xd55e8 uxtb r3, r3 */
/* @0xd55ec addeq r9, r5, #1 */
/* @0xd55f0 movne r9, #1 */
/* @0xd55f4 moveq r5, r2 */
/* @0xd55f8 cmp r3, #6 */
/* @0xd55fc addls pc, pc, r3, lsl #2 */
/* @0xd5600 b 0xd55c4 <_Z5DoDupjPhPKhP6VMExec+0x64> */
/* @0xd5604 b 0xd56c8 <_Z5DoDupjPhPKhP6VMExec+0x168> */
/* @0xd5608 b 0xd56e0 <_Z5DoDupjPhPKhP6VMExec+0x180> */
/* @0xd560c b 0xd56e0 <_Z5DoDupjPhPKhP6VMExec+0x180> */
/* @0xd5610 b 0xd56c8 <_Z5DoDupjPhPKhP6VMExec+0x168> */
/* @0xd5614 b 0xd56e0 <_Z5DoDupjPhPKhP6VMExec+0x180> */
/* @0xd5618 b 0xd56f8 <_Z5DoDupjPhPKhP6VMExec+0x198> */
/* @0xd561c b 0xd566c <_Z5DoDupjPhPKhP6VMExec+0x10c> */
/* @0xd5620 and r4, r0, #240 */
/* @0xd5624 and r5, r0, #15 */
/* @0xd5628 add r3, r4, #14 */
/* @0xd562c mov r1, r7 */
/* @0xd5630 and r3, r3, #504 */
/* @0xd5634 lsl r5, r5, #4 */
/* @0xd5638 sub sp, sp, r3 */
/* @0xd563c mov r2, r4 */
/* @0xd5640 mov r0, sp */
/* @0xd5644 bl 0xb65bc <memcpy@plt> */
/* @0xd5648 mov r2, r5 */
/* @0xd564c add r1, r7, r4 */
/* @0xd5650 mov r0, r7 */
/* @0xd5654 bl 0xb6694 <memmove@plt> */
/* @0xd5658 mov r1, sp */
/* @0xd565c add r0, r7, r5 */
/* @0xd5660 mov r2, r4 */
/* @0xd5664 bl 0xb65bc <memcpy@plt> */
/* @0xd5668 b 0xd55c4 <_Z5DoDupjPhPKhP6VMExec+0x64> */
/* @0xd566c add r12, r1, r5, lsl #2 */
/* @0xd5670 sub r7, r1, r9, lsl #2 */
/* @0xd5674 ldr r3, [pc, #0x1b8] */
/* @0xd5678 sub r5, r12, #4 */
/* @0xd567c mov r4, #0 */
/* @0xd5680 mov r10, r7 */
/* @0xd5684 add r3, pc, r3 */
/* @0xd5688 str r3, [r11, #-0x30] */
/* @0xd568c ldr r8, [r5, #0x4]! */
/* @0xd5690 add r4, r4, #1 */
/* @0xd5694 mov r0, r8 */
/* @0xd5698 bl 0xb6538 <strlen@plt> */
/* @0xd569c mov r3, #1 */
/* @0xd56a0 ldr r1, [r11, #-0x30] */
/* @0xd56a4 movw r2, #0x2075 */
/* @0xd56a8 add r0, r0, r3 */
/* @0xd56ac bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd56b0 mov r1, r8 */
/* @0xd56b4 bl 0xb65a4 <strcpy@plt> */
/* @0xd56b8 cmp r9, r4 */
/* @0xd56bc str r0, [r10], #4 */
/* @0xd56c0 bgt 0xd568c <_Z5DoDupjPhPKhP6VMExec+0x12c> */
/* @0xd56c4 b 0xd55c4 <_Z5DoDupjPhPKhP6VMExec+0x64> */
/* @0xd56c8 lsl r2, r9, #3 */
/* @0xd56cc add r1, r1, r5, lsl #3 */
/* @0xd56d0 rsb r7, r2, r7 */
/* @0xd56d4 mov r0, r7 */
/* @0xd56d8 bl 0xb65bc <memcpy@plt> */
/* @0xd56dc b 0xd55c4 <_Z5DoDupjPhPKhP6VMExec+0x64> */
/* @0xd56e0 lsl r2, r9, #2 */
/* @0xd56e4 add r1, r1, r5, lsl #2 */
/* @0xd56e8 rsb r7, r2, r7 */
/* @0xd56ec mov r0, r7 */
/* @0xd56f0 bl 0xb65bc <memcpy@plt> */
/* @0xd56f4 b 0xd55c4 <_Z5DoDupjPhPKhP6VMExec+0x64> */
/* @0xd56f8 add r5, r1, r5, lsl #4 */
/* @0xd56fc sub r7, r1, r9, lsl #4 */
/* @0xd5700 mov r8, #0 */
/* @0xd5704 add r5, r5, #16 */
/* @0xd5708 add r4, r7, #16 */
/* @0xd570c mov r2, #5 */
/* @0xd5710 mov r10, r8 */
/* @0xd5714 str r2, [r4, #-0x4] */
/* @0xd5718 sub r0, r5, #16 */
/* @0xd571c str r10, [r4, #-0x10] */
/* @0xd5720 sub r1, r4, #16 */
/* @0xd5724 ldr r3, [r5, #-0x4] */
/* @0xd5728 str r3, [r4, #-0x4] */
/* @0xd572c ldr r3, [r5, #-0x8] */
/* @0xd5730 str r3, [r4, #-0x8] */
/* @0xd5734 ldr r3, [r5, #-0x4] */
/* @0xd5738 bic r3, r3, #-16777216 */
/* @0xd573c cmp r3, #14 */
/* @0xd5740 addls pc, pc, r3, lsl #2 */
/* @0xd5744 b 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd5748 b 0xd57a4 <_Z5DoDupjPhPKhP6VMExec+0x244> */
/* @0xd574c b 0xd5810 <_Z5DoDupjPhPKhP6VMExec+0x2b0> */
/* @0xd5750 b 0xd57e4 <_Z5DoDupjPhPKhP6VMExec+0x284> */
/* @0xd5754 b 0xd5784 <_Z5DoDupjPhPKhP6VMExec+0x224> */
/* @0xd5758 b 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd575c b 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd5760 b 0xd57b8 <_Z5DoDupjPhPKhP6VMExec+0x258> */
/* @0xd5764 b 0xd5784 <_Z5DoDupjPhPKhP6VMExec+0x224> */
/* @0xd5768 b 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd576c b 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd5770 b 0xd57a4 <_Z5DoDupjPhPKhP6VMExec+0x244> */
/* @0xd5774 b 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd5778 b 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd577c b 0xd57a4 <_Z5DoDupjPhPKhP6VMExec+0x244> */
/* @0xd5780 b 0xd5784 <_Z5DoDupjPhPKhP6VMExec+0x224> */
/* @0xd5784 ldr r3, [r5, #-0x10] */
/* @0xd5788 str r3, [r4, #-0x10] */
/* @0xd578c add r8, r8, #1 */
/* @0xd5790 add r4, r4, #16 */
/* @0xd5794 cmp r9, r8 */
/* @0xd5798 add r5, r5, #16 */
/* @0xd579c bgt 0xd5714 <_Z5DoDupjPhPKhP6VMExec+0x1b4> */
/* @0xd57a0 b 0xd55c4 <_Z5DoDupjPhPKhP6VMExec+0x64> */
/* @0xd57a4 ldr r3, [r0, #0x4] */
/* @0xd57a8 ldr r0, [r5, #-0x10] */
/* @0xd57ac str r0, [r4, #-0x10] */
/* @0xd57b0 str r3, [r1, #0x4] */
/* @0xd57b4 b 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd57b8 ldr r3, [r5, #-0x10] */
/* @0xd57bc str r3, [r4, #-0x10] */
/* @0xd57c0 ldr r3, [r5, #-0x10] */
/* @0xd57c4 cmp r3, #0 */
/* @0xd57c8 beq 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd57cc str r2, [r11, #-0x34] */
/* @0xd57d0 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xd57d4 ldr r1, [r5, #-0x10] */
/* @0xd57d8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xd57dc ldr r2, [r11, #-0x34] */
/* @0xd57e0 b 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd57e4 ldr r3, [r5, #-0x10] */
/* @0xd57e8 cmp r3, #0 */
/* @0xd57ec str r3, [r4, #-0x10] */
/* @0xd57f0 beq 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd57f4 ldr r12, [r3, #0x8] */
/* @0xd57f8 ldr r0, [r3] */
/* @0xd57fc cmp r12, #0 */
/* @0xd5800 streq r1, [r3, #0x8] */
/* @0xd5804 add r0, r0, #1 */
/* @0xd5808 str r0, [r3] */
/* @0xd580c b 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd5810 ldr r3, [r5, #-0x10] */
/* @0xd5814 cmp r3, #0 */
/* @0xd5818 ldrne r1, [r3, #0x4] */
/* @0xd581c addne r1, r1, #1 */
/* @0xd5820 strne r1, [r3, #0x4] */
/* @0xd5824 b 0xd5788 <_Z5DoDupjPhPKhP6VMExec+0x228> */
/* @0xd5828 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xd582c ldrsbteq r8, [r1], -r12 */
/* @0xd5830 eoreq sp, r5, r4, ror #9 */
/* @0xd5834 .word 0x0025d0f8 */
