/* libyoyo.so 覆盖卡组 0199
 * 函数 0x2203fc..0x221648，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2203fc · SoundHardware::FindDataChunk(void*, int) · size=92 · insn=23 */
/* @0x2203fc push {r3, lr} */
/* @0x220400 ldr r3, [pc, #0x40] */
/* @0x220404 ldr r3, [pc, r3] */
/* @0x220408 ldrb r3, [r3] */
/* @0x22040c cmp r3, #0 */
/* @0x220410 beq 0x220440 <_ZN13SoundHardware13FindDataChunkEPvi+0x44> */
/* @0x220414 ldr r3, [pc, #0x30] */
/* @0x220418 ldr r2, [pc, #0x30] */
/* @0x22041c ldr r3, [pc, r3] */
/* @0x220420 ldr r1, [pc, #0x2c] */
/* @0x220424 add r2, pc, r2 */
/* @0x220428 ldr r0, [r3] */
/* @0x22042c add r1, pc, r1 */
/* @0x220430 add r2, r2, #16 */
/* @0x220434 ldr r3, [r0] */
/* @0x220438 ldr r3, [r3, #0xc] */
/* @0x22043c blx r3 */
/* @0x220440 mov r0, #0 */
/* @0x220444 pop {r3, pc} */
/* @0x220448 andseq r1, sp, r4, lsr #32 */
/* @0x22044c ldrsheq sp, [r12], -r8 */
/* @0x220450 andseq sp, r3, r4, lsr #23 */
/* @0x220454 andseq r4, r3, r0, lsl r4 */

/* ── FUNC 0x220458 · SoundHardware::FindSampleStart(void*, int) · size=120 · insn=30 */
/* @0x220458 ldr r3, [pc, #0x60] */
/* @0x22045c push {r4, r5, r6, lr} */
/* @0x220460 ldr r3, [pc, r3] */
/* @0x220464 mov r6, r0 */
/* @0x220468 mov r5, r1 */
/* @0x22046c ldrb r3, [r3] */
/* @0x220470 mov r4, r2 */
/* @0x220474 cmp r3, #0 */
/* @0x220478 beq 0x2204a8 <_ZN13SoundHardware15FindSampleStartEPvi+0x50> */
/* @0x22047c ldr r3, [pc, #0x40] */
/* @0x220480 ldr r2, [pc, #0x40] */
/* @0x220484 ldr r3, [pc, r3] */
/* @0x220488 ldr r1, [pc, #0x3c] */
/* @0x22048c add r2, pc, r2 */
/* @0x220490 ldr r0, [r3] */
/* @0x220494 add r1, pc, r1 */
/* @0x220498 add r2, r2, #32 */
/* @0x22049c ldr r3, [r0] */
/* @0x2204a0 ldr r3, [r3, #0xc] */
/* @0x2204a4 blx r3 */
/* @0x2204a8 mov r0, r6 */
/* @0x2204ac mov r1, r5 */
/* @0x2204b0 mov r2, r4 */
/* @0x2204b4 bl 0x2203fc <_ZN13SoundHardware13FindDataChunkEPvi> */
/* @0x2204b8 add r0, r0, #8 */
/* @0x2204bc pop {r4, r5, r6, pc} */
/* @0x2204c0 andseq r0, sp, r8, asr #31 */
/* @0x2204c4 mulseq r12, r0, r2 */
/* @0x2204c8 andseq sp, r3, r12, lsr r11 */
/* @0x2204cc andseq r4, r3, r8, lsr #7 */

/* ── FUNC 0x2204d0 · SoundHardware::GetDataChunkSize(void*, int) · size=124 · insn=31 */
/* @0x2204d0 ldr r3, [pc, #0x64] */
/* @0x2204d4 push {r4, r5, r6, lr} */
/* @0x2204d8 ldr r3, [pc, r3] */
/* @0x2204dc mov r6, r0 */
/* @0x2204e0 mov r5, r1 */
/* @0x2204e4 ldrb r3, [r3] */
/* @0x2204e8 mov r4, r2 */
/* @0x2204ec cmp r3, #0 */
/* @0x2204f0 beq 0x220520 <_ZN13SoundHardware16GetDataChunkSizeEPvi+0x50> */
/* @0x2204f4 ldr r3, [pc, #0x44] */
/* @0x2204f8 ldr r2, [pc, #0x44] */
/* @0x2204fc ldr r3, [pc, r3] */
/* @0x220500 ldr r1, [pc, #0x40] */
/* @0x220504 add r2, pc, r2 */
/* @0x220508 ldr r0, [r3] */
/* @0x22050c add r1, pc, r1 */
/* @0x220510 add r2, r2, #48 */
/* @0x220514 ldr r3, [r0] */
/* @0x220518 ldr r3, [r3, #0xc] */
/* @0x22051c blx r3 */
/* @0x220520 mov r0, r6 */
/* @0x220524 mov r1, r5 */
/* @0x220528 mov r2, r4 */
/* @0x22052c bl 0x2203fc <_ZN13SoundHardware13FindDataChunkEPvi> */
/* @0x220530 pop {r4, r5, r6, lr} */
/* @0x220534 add r0, r0, #4 */
/* @0x220538 b 0x220164 <_Z7ReadU32Pv> */
/* @0x22053c andseq r0, sp, r0, asr pc */
/* @0x220540 andseq sp, r12, r8, lsl r2 */
/* @0x220544 andseq sp, r3, r4, asr #21 */
/* @0x220548 andseq r4, r3, r0, lsr r3 */

/* ── FUNC 0x22054c · SoundHardware::Load(void*, int, int) · size=536 · insn=134 */
/* @0x22054c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x220550 mov r8, r1 */
/* @0x220554 ldr r4, [pc, #0x1dc] */
/* @0x220558 sub sp, sp, #12 */
/* @0x22055c ldr r3, [pc, #0x1d8] */
/* @0x220560 mov r7, r2 */
/* @0x220564 add r4, pc, r4 */
/* @0x220568 ldr r6, [r4, r3] */
/* @0x22056c ldrb r3, [r6] */
/* @0x220570 cmp r3, #0 */
/* @0x220574 bne 0x2206a4 <_ZN13SoundHardware4LoadEPvii+0x158> */
/* @0x220578 ldr r3, [pc, #0x1c0] */
/* @0x22057c ldr r3, [r4, r3] */
/* @0x220580 ldrb r3, [r3] */
/* @0x220584 cmp r3, #0 */
/* @0x220588 bne 0x220698 <_ZN13SoundHardware4LoadEPvii+0x14c> */
/* @0x22058c ldr r2, [pc, #0x1b0] */
/* @0x220590 ldr r2, [r4, r2] */
/* @0x220594 ldrb r2, [r2] */
/* @0x220598 cmp r2, #0 */
/* @0x22059c bne 0x220698 <_ZN13SoundHardware4LoadEPvii+0x14c> */
/* @0x2205a0 ldr r3, [pc, #0x1a0] */
/* @0x2205a4 ldr r3, [r4, r3] */
/* @0x2205a8 ldrb r5, [r3] */
/* @0x2205ac cmp r5, #0 */
/* @0x2205b0 bne 0x220698 <_ZN13SoundHardware4LoadEPvii+0x14c> */
/* @0x2205b4 mov r1, r7 */
/* @0x2205b8 mov r0, r8 */
/* @0x2205bc bl 0x222638 <alutCreateBufferFromFileImage> */
/* @0x2205c0 mov r8, r0 */
/* @0x2205c4 bl 0x221714 <alutGetError> */
/* @0x2205c8 subs r7, r0, #0 */
/* @0x2205cc beq 0x220610 <_ZN13SoundHardware4LoadEPvii+0xc4> */
/* @0x2205d0 ldr r3, [pc, #0x174] */
/* @0x2205d4 ldr r3, [r4, r3] */
/* @0x2205d8 ldr r4, [r3] */
/* @0x2205dc ldr r3, [r4] */
/* @0x2205e0 ldr r6, [r3, #0xc] */
/* @0x2205e4 bl 0x221730 <alutGetErrorString> */
/* @0x2205e8 ldr r1, [pc, #0x160] */
/* @0x2205ec mov r2, r7 */
/* @0x2205f0 mov r3, r7 */
/* @0x2205f4 add r1, pc, r1 */
/* @0x2205f8 str r0, [sp] */
/* @0x2205fc mov r0, r4 */
/* @0x220600 blx r6 */
/* @0x220604 mov r0, r5 */
/* @0x220608 add sp, sp, #12 */
/* @0x22060c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x220610 bl 0xb6a54 <alGetError@plt> */
/* @0x220614 subs r9, r0, #0 */
/* @0x220618 bne 0x2206d4 <_ZN13SoundHardware4LoadEPvii+0x188> */
/* @0x22061c mov r0, #36 */
/* @0x220620 bl 0x27c524 <_Znwj> */
/* @0x220624 ldrb r3, [r6] */
/* @0x220628 mov r2, #1065353216 */
/* @0x22062c mov r1, #0 */
/* @0x220630 cmp r3, #0 */
/* @0x220634 mov r5, r0 */
/* @0x220638 str r9, [r0, #0x14] */
/* @0x22063c str r8, [r0] */
/* @0x220640 addeq r6, r0, #4 */
/* @0x220644 str r9, [r0, #0x20] */
/* @0x220648 str r1, [r0, #0x1c] */
/* @0x22064c str r2, [r0, #0x18] */
/* @0x220650 bne 0x220708 <_ZN13SoundHardware4LoadEPvii+0x1bc> */
/* @0x220654 mov r1, r6 */
/* @0x220658 mov r0, #4 */
/* @0x22065c bl 0xb6a90 <alGenSources@plt> */
/* @0x220660 sub r4, r5, #4 */
/* @0x220664 bl 0x220198 <_Z12CheckALErrorv> */
/* @0x220668 add r6, r5, #12 */
/* @0x22066c add r4, r4, #4 */
/* @0x220670 movw r1, #0x1009 */
/* @0x220674 ldr r2, [r5] */
/* @0x220678 ldr r0, [r4, #0x4] */
/* @0x22067c bl 0xb6a6c <alSourcei@plt> */
/* @0x220680 bl 0x220198 <_Z12CheckALErrorv> */
/* @0x220684 cmp r4, r6 */
/* @0x220688 bne 0x22066c <_ZN13SoundHardware4LoadEPvii+0x120> */
/* @0x22068c mov r0, r5 */
/* @0x220690 add sp, sp, #12 */
/* @0x220694 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x220698 mov r0, #0 */
/* @0x22069c add sp, sp, #12 */
/* @0x2206a0 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2206a4 ldr r3, [pc, #0xa0] */
/* @0x2206a8 ldr r2, [pc, #0xa4] */
/* @0x2206ac ldr r1, [pc, #0xa4] */
/* @0x2206b0 ldr r3, [r4, r3] */
/* @0x2206b4 add r2, pc, r2 */
/* @0x2206b8 add r1, pc, r1 */
/* @0x2206bc add r2, r2, #68 */
/* @0x2206c0 ldr r0, [r3] */
/* @0x2206c4 ldr r3, [r0] */
/* @0x2206c8 ldr r3, [r3, #0xc] */
/* @0x2206cc blx r3 */
/* @0x2206d0 b 0x220578 <_ZN13SoundHardware4LoadEPvii+0x2c> */
/* @0x2206d4 ldr r0, [pc, #0x70] */
/* @0x2206d8 mov r2, r9 */
/* @0x2206dc ldr r1, [pc, #0x78] */
/* @0x2206e0 mov r3, r9 */
/* @0x2206e4 ldr r0, [r4, r0] */
/* @0x2206e8 add r1, pc, r1 */
/* @0x2206ec ldr r0, [r0] */
/* @0x2206f0 ldr r12, [r0] */
/* @0x2206f4 ldr r12, [r12, #0xc] */
/* @0x2206f8 blx r12 */
/* @0x2206fc mov r0, r7 */
/* @0x220700 add sp, sp, #12 */
/* @0x220704 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x220708 ldr r0, [pc, #0x3c] */
/* @0x22070c add r6, r5, #4 */
/* @0x220710 ldr r1, [pc, #0x48] */
/* @0x220714 mov r2, #4 */
/* @0x220718 mov r3, r6 */
/* @0x22071c ldr r0, [r4, r0] */
/* @0x220720 add r1, pc, r1 */
/* @0x220724 ldr r0, [r0] */
/* @0x220728 ldr r12, [r0] */
/* @0x22072c ldr r12, [r12, #0xc] */
/* @0x220730 blx r12 */
/* @0x220734 b 0x220654 <_ZN13SoundHardware4LoadEPvii+0x108> */
/* @0x220738 andseq r1, sp, r12, ror #13 */
/* @0x22073c .word 0xfffff7d8 */
/* @0x220740 .word 0xffffd3fc */
/* @0x220744 .word 0xfffff7e0 */
/* @0x220748 .word 0xfffff7e4 */
/* @0x22074c .word 0xffffbac4 */
/* @0x220750 andseq r4, r3, r8, ror r2 */
/* @0x220754 andseq sp, r3, r4, lsl r9 */
/* @0x220758 andseq r4, r3, r4, lsl #3 */
/* @0x22075c andseq r4, r3, r8, ror #2 */
/* @0x220760 andseq r4, r3, r4, lsr #2 */

/* ── FUNC 0x220764 · SoundHardware::Play(void*, bool) · size=288 · insn=72 */
/* @0x220764 push {r3, r4, r5, r6, r7, lr} */
/* @0x220768 mov r7, r0 */
/* @0x22076c ldr r4, [pc, #0xf0] */
/* @0x220770 mov r5, r1 */
/* @0x220774 ldr r3, [pc, #0xec] */
/* @0x220778 mov r6, r2 */
/* @0x22077c add r4, pc, r4 */
/* @0x220780 ldr r3, [r4, r3] */
/* @0x220784 ldrb r3, [r3] */
/* @0x220788 cmp r3, #0 */
/* @0x22078c bne 0x220834 <_ZN13SoundHardware4PlayEPvb+0xd0> */
/* @0x220790 ldr r3, [pc, #0xd4] */
/* @0x220794 ldr r3, [r4, r3] */
/* @0x220798 ldrb r3, [r3] */
/* @0x22079c cmp r3, #0 */
/* @0x2207a0 popne {r3, r4, r5, r6, r7, pc} */
/* @0x2207a4 ldr r3, [pc, #0xc4] */
/* @0x2207a8 ldr r3, [r4, r3] */
/* @0x2207ac ldrb r3, [r3] */
/* @0x2207b0 cmp r3, #0 */
/* @0x2207b4 popne {r3, r4, r5, r6, r7, pc} */
/* @0x2207b8 ldr r3, [pc, #0xb4] */
/* @0x2207bc ldr r3, [r4, r3] */
/* @0x2207c0 ldrb r3, [r3] */
/* @0x2207c4 cmp r3, #0 */
/* @0x2207c8 popne {r3, r4, r5, r6, r7, pc} */
/* @0x2207cc cmp r5, #0 */
/* @0x2207d0 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x2207d4 vldr s14, [r5, #24] */
/* @0x2207d8 vldr s15, [r7] */
/* @0x2207dc vmul.f32 s15, s14, s15 */
/* @0x2207e0 ldr r2, [r5, #0x14] */
/* @0x2207e4 add r1, r2, #1 */
/* @0x2207e8 str r1, [r5, #0x14] */
/* @0x2207ec add r2, r5, r2, lsl #2 */
/* @0x2207f0 cmp r1, #3 */
/* @0x2207f4 movw r1, #0x100a */
/* @0x2207f8 ldr r4, [r2, #0x4] */
/* @0x2207fc strgt r3, [r5, #0x14] */
/* @0x220800 mov r0, r4 */
/* @0x220804 vmov r2, s15 */
/* @0x220808 bl 0xb6a78 <alSourcef@plt> */
/* @0x22080c bl 0x220198 <_Z12CheckALErrorv> */
/* @0x220810 mov r0, r4 */
/* @0x220814 mov r2, r6 */
/* @0x220818 movw r1, #0x1007 */
/* @0x22081c bl 0xb6a6c <alSourcei@plt> */
/* @0x220820 bl 0x220198 <_Z12CheckALErrorv> */
/* @0x220824 mov r0, r4 */
/* @0x220828 bl 0xb6a84 <alSourcePlay@plt> */
/* @0x22082c pop {r3, r4, r5, r6, r7, lr} */
/* @0x220830 b 0x220198 <_Z12CheckALErrorv> */
/* @0x220834 ldr r3, [pc, #0x3c] */
/* @0x220838 ldr r2, [pc, #0x3c] */
/* @0x22083c ldr r1, [pc, #0x3c] */
/* @0x220840 ldr r3, [r4, r3] */
/* @0x220844 add r2, pc, r2 */
/* @0x220848 add r1, pc, r1 */
/* @0x22084c add r2, r2, #76 */
/* @0x220850 ldr r0, [r3] */
/* @0x220854 ldr r3, [r0] */
/* @0x220858 ldr r3, [r3, #0xc] */
/* @0x22085c blx r3 */
/* @0x220860 b 0x220790 <_ZN13SoundHardware4PlayEPvb+0x2c> */
/* @0x220864 ldrsbeq r1, [sp], -r4 */
/* @0x220868 .word 0xfffff7d8 */
/* @0x22086c .word 0xffffd3fc */
/* @0x220870 .word 0xfffff7e0 */
/* @0x220874 .word 0xfffff7e4 */
/* @0x220878 .word 0xffffbac4 */
/* @0x22087c andseq sp, r3, r4, lsl #15 */
/* @0x220880 ldrsheq r3, [r3], -r4 */

/* ── FUNC 0x220884 · SoundHardware::SetMasterVolume(float) · size=100 · insn=25 */
/* @0x220884 push {r3, r4, r5, lr} */
/* @0x220888 mov r4, r0 */
/* @0x22088c ldr r3, [pc, #0x44] */
/* @0x220890 mov r5, r1 */
/* @0x220894 ldr r3, [pc, r3] */
/* @0x220898 ldrb r3, [r3] */
/* @0x22089c cmp r3, #0 */
/* @0x2208a0 beq 0x2208d0 <_ZN13SoundHardware15SetMasterVolumeEf+0x4c> */
/* @0x2208a4 ldr r3, [pc, #0x30] */
/* @0x2208a8 ldr r2, [pc, #0x30] */
/* @0x2208ac ldr r3, [pc, r3] */
/* @0x2208b0 ldr r1, [pc, #0x2c] */
/* @0x2208b4 add r2, pc, r2 */
/* @0x2208b8 ldr r0, [r3] */
/* @0x2208bc add r1, pc, r1 */
/* @0x2208c0 add r2, r2, #84 */
/* @0x2208c4 ldr r3, [r0] */
/* @0x2208c8 ldr r3, [r3, #0xc] */
/* @0x2208cc blx r3 */
/* @0x2208d0 str r5, [r4] */
/* @0x2208d4 pop {r3, r4, r5, pc} */
/* @0x2208d8 mulseq sp, r4, r11 */
/* @0x2208dc andseq r12, r12, r8, ror #28 */
/* @0x2208e0 andseq sp, r3, r4, lsl r7 */
/* @0x2208e4 andseq r3, r3, r0, lsl #31 */

/* ── FUNC 0x2208e8 · SoundHardware::PauseMusic() · size=52 · insn=13 */
/* @0x2208e8 ldr r3, [pc, #0x24] */
/* @0x2208ec ldr r3, [pc, r3] */
/* @0x2208f0 ldrb r3, [r3] */
/* @0x2208f4 cmp r3, #0 */
/* @0x2208f8 bxne lr */
/* @0x2208fc ldr r3, [pc, #0x14] */
/* @0x220900 ldr r3, [pc, r3] */
/* @0x220904 ldrb r3, [r3] */
/* @0x220908 cmp r3, #0 */
/* @0x22090c bxne lr */
/* @0x220910 b 0x2231c4 <_Z15OpenAL_PauseMP3v> */
/* @0x220914 andseq lr, r12, r0, ror #14 */
/* @0x220918 andseq r0, sp, r0, lsr r11 */

/* ── FUNC 0x22091c · SoundHardware::ResumeMusic() · size=52 · insn=13 */
/* @0x22091c ldr r3, [pc, #0x24] */
/* @0x220920 ldr r3, [pc, r3] */
/* @0x220924 ldrb r3, [r3] */
/* @0x220928 cmp r3, #0 */
/* @0x22092c bxne lr */
/* @0x220930 ldr r3, [pc, #0x14] */
/* @0x220934 ldr r3, [pc, r3] */
/* @0x220938 ldrb r3, [r3] */
/* @0x22093c cmp r3, #0 */
/* @0x220940 bxne lr */
/* @0x220944 b 0x2231f4 <_Z16OpenAL_ResumeMP3v> */
/* @0x220948 andseq lr, r12, r12, lsr #14 */
/* @0x22094c ldrsheq r0, [sp], -r12 */

/* ── FUNC 0x220950 · SoundHardware::StopMusic() · size=172 · insn=43 */
/* @0x220950 push {r4, lr} */
/* @0x220954 ldr r4, [pc, #0x80] */
/* @0x220958 ldr r3, [pc, #0x80] */
/* @0x22095c add r4, pc, r4 */
/* @0x220960 ldr r3, [r4, r3] */
/* @0x220964 ldrb r3, [r3] */
/* @0x220968 cmp r3, #0 */
/* @0x22096c bne 0x2209ac <_ZN13SoundHardware9StopMusicEv+0x5c> */
/* @0x220970 ldr r3, [pc, #0x6c] */
/* @0x220974 ldr r3, [r4, r3] */
/* @0x220978 ldrb r3, [r3] */
/* @0x22097c cmp r3, #0 */
/* @0x220980 popne {r4, pc} */
/* @0x220984 ldr r3, [pc, #0x5c] */
/* @0x220988 ldr r3, [r4, r3] */
/* @0x22098c ldrb r3, [r3] */
/* @0x220990 cmp r3, #0 */
/* @0x220994 popne {r4, pc} */
/* @0x220998 ldr r2, [pc, #0x4c] */
/* @0x22099c ldr r2, [r4, r2] */
/* @0x2209a0 strb r3, [r2] */
/* @0x2209a4 pop {r4, lr} */
/* @0x2209a8 b 0x223224 <_Z14OpenAL_StopMP3v> */
/* @0x2209ac ldr r3, [pc, #0x3c] */
/* @0x2209b0 ldr r2, [pc, #0x3c] */
/* @0x2209b4 ldr r1, [pc, #0x3c] */
/* @0x2209b8 ldr r3, [r4, r3] */
/* @0x2209bc add r2, pc, r2 */
/* @0x2209c0 add r1, pc, r1 */
/* @0x2209c4 add r2, r2, #100 */
/* @0x2209c8 ldr r0, [r3] */
/* @0x2209cc ldr r3, [r0] */
/* @0x2209d0 ldr r3, [r3, #0xc] */
/* @0x2209d4 blx r3 */
/* @0x2209d8 b 0x220970 <_ZN13SoundHardware9StopMusicEv+0x20> */
/* @0x2209dc ldrsheq r1, [sp], -r4 */
/* @0x2209e0 .word 0xfffff7d8 */
/* @0x2209e4 .word 0xffffd3fc */
/* @0x2209e8 .word 0xfffff7e0 */
/* @0x2209ec .word 0xfffff7dc */
/* @0x2209f0 .word 0xffffbac4 */
/* @0x2209f4 andseq sp, r3, r12, lsl #12 */
/* @0x2209f8 andseq r3, r3, r12, ror lr */

/* ── FUNC 0x2209fc · SoundHardware::PlayMP3(char const*, bool) · size=224 · insn=56 */
/* @0x2209fc push {r3, r4, r5, r6, r7, lr} */
/* @0x220a00 mov r7, r0 */
/* @0x220a04 ldr r4, [pc, #0xb0] */
/* @0x220a08 mov r6, r1 */
/* @0x220a0c ldr r3, [pc, #0xac] */
/* @0x220a10 mov r5, r2 */
/* @0x220a14 add r4, pc, r4 */
/* @0x220a18 ldr r3, [r4, r3] */
/* @0x220a1c ldrb r3, [r3] */
/* @0x220a20 cmp r3, #0 */
/* @0x220a24 bne 0x220a80 <_ZN13SoundHardware7PlayMP3EPKcb+0x84> */
/* @0x220a28 ldr r3, [pc, #0x94] */
/* @0x220a2c ldr r3, [r4, r3] */
/* @0x220a30 ldrb r3, [r3] */
/* @0x220a34 cmp r3, #0 */
/* @0x220a38 popne {r3, r4, r5, r6, r7, pc} */
/* @0x220a3c ldr r3, [pc, #0x84] */
/* @0x220a40 ldr r3, [r4, r3] */
/* @0x220a44 ldrb r3, [r3] */
/* @0x220a48 cmp r3, #0 */
/* @0x220a4c popne {r3, r4, r5, r6, r7, pc} */
/* @0x220a50 ldr r3, [pc, #0x74] */
/* @0x220a54 ldr r4, [r4, r3] */
/* @0x220a58 ldrb r3, [r4] */
/* @0x220a5c cmp r3, #0 */
/* @0x220a60 bne 0x220ab0 <_ZN13SoundHardware7PlayMP3EPKcb+0xb4> */
/* @0x220a64 mov r1, r6 */
/* @0x220a68 mov r0, r4 */
/* @0x220a6c bl 0xb65a4 <strcpy@plt> */
/* @0x220a70 mov r0, r6 */
/* @0x220a74 mov r1, r5 */
/* @0x220a78 pop {r3, r4, r5, r6, r7, lr} */
/* @0x220a7c b 0x223098 <_Z14OpenAL_PlayMP3PKcb> */
/* @0x220a80 ldr r3, [pc, #0x48] */
/* @0x220a84 ldr r2, [pc, #0x48] */
/* @0x220a88 ldr r1, [pc, #0x48] */
/* @0x220a8c ldr r3, [r4, r3] */
/* @0x220a90 add r2, pc, r2 */
/* @0x220a94 add r1, pc, r1 */
/* @0x220a98 add r2, r2, #112 */
/* @0x220a9c ldr r0, [r3] */
/* @0x220aa0 ldr r3, [r0] */
/* @0x220aa4 ldr r3, [r3, #0xc] */
/* @0x220aa8 blx r3 */
/* @0x220aac b 0x220a28 <_ZN13SoundHardware7PlayMP3EPKcb+0x2c> */
/* @0x220ab0 mov r0, r7 */
/* @0x220ab4 bl 0x220950 <_ZN13SoundHardware9StopMusicEv> */
/* @0x220ab8 b 0x220a64 <_ZN13SoundHardware7PlayMP3EPKcb+0x68> */
/* @0x220abc andseq r1, sp, r12, lsr r2 */
/* @0x220ac0 .word 0xfffff7d8 */
/* @0x220ac4 .word 0xffffd3fc */
/* @0x220ac8 .word 0xfffff7e0 */
/* @0x220acc .word 0xfffff7dc */
/* @0x220ad0 .word 0xffffbac4 */
/* @0x220ad4 andseq sp, r3, r8, lsr r5 */
/* @0x220ad8 andseq r3, r3, r8, lsr #27 */

/* ── FUNC 0x220adc · SoundHardware::PlayMIDI(char const*, bool) · size=260 · insn=65 */
/* @0x220adc push {r3, r4, r5, r6, r7, lr} */
/* @0x220ae0 mov r7, r0 */
/* @0x220ae4 ldr r4, [pc, #0xd4] */
/* @0x220ae8 mov r6, r1 */
/* @0x220aec ldr r3, [pc, #0xd0] */
/* @0x220af0 mov r5, r2 */
/* @0x220af4 add r4, pc, r4 */
/* @0x220af8 ldr r3, [r4, r3] */
/* @0x220afc ldrb r3, [r3] */
/* @0x220b00 cmp r3, #0 */
/* @0x220b04 bne 0x220b84 <_ZN13SoundHardware8PlayMIDIEPKcb+0xa8> */
/* @0x220b08 ldr r3, [pc, #0xb8] */
/* @0x220b0c ldr r3, [r4, r3] */
/* @0x220b10 ldrb r3, [r3] */
/* @0x220b14 cmp r3, #0 */
/* @0x220b18 popne {r3, r4, r5, r6, r7, pc} */
/* @0x220b1c ldr r3, [pc, #0xa8] */
/* @0x220b20 ldr r3, [r4, r3] */
/* @0x220b24 ldrb r3, [r3] */
/* @0x220b28 cmp r3, #0 */
/* @0x220b2c popne {r3, r4, r5, r6, r7, pc} */
/* @0x220b30 ldr r3, [pc, #0x98] */
/* @0x220b34 ldr r4, [r4, r3] */
/* @0x220b38 ldrb r3, [r4] */
/* @0x220b3c cmp r3, #0 */
/* @0x220b40 bne 0x220bb4 <_ZN13SoundHardware8PlayMIDIEPKcb+0xd8> */
/* @0x220b44 mov r1, r6 */
/* @0x220b48 mov r0, r4 */
/* @0x220b4c bl 0xb65a4 <strcpy@plt> */
/* @0x220b50 mov r0, r4 */
/* @0x220b54 bl 0xb6538 <strlen@plt> */
/* @0x220b58 mov r1, r5 */
/* @0x220b5c mov r12, #112 */
/* @0x220b60 mov r5, #109 */
/* @0x220b64 mov r2, #51 */
/* @0x220b68 add r3, r4, r0 */
/* @0x220b6c mov r0, r4 */
/* @0x220b70 strb r5, [r3, #-0x3] */
/* @0x220b74 strb r12, [r3, #-0x2] */
/* @0x220b78 strb r2, [r3, #-0x1] */
/* @0x220b7c pop {r3, r4, r5, r6, r7, lr} */
/* @0x220b80 b 0x223098 <_Z14OpenAL_PlayMP3PKcb> */
/* @0x220b84 ldr r3, [pc, #0x48] */
/* @0x220b88 ldr r2, [pc, #0x48] */
/* @0x220b8c ldr r1, [pc, #0x48] */
/* @0x220b90 ldr r3, [r4, r3] */
/* @0x220b94 add r2, pc, r2 */
/* @0x220b98 add r1, pc, r1 */
/* @0x220b9c add r2, r2, #120 */
/* @0x220ba0 ldr r0, [r3] */
/* @0x220ba4 ldr r3, [r0] */
/* @0x220ba8 ldr r3, [r3, #0xc] */
/* @0x220bac blx r3 */
/* @0x220bb0 b 0x220b08 <_ZN13SoundHardware8PlayMIDIEPKcb+0x2c> */
/* @0x220bb4 mov r0, r7 */
/* @0x220bb8 bl 0x220950 <_ZN13SoundHardware9StopMusicEv> */
/* @0x220bbc b 0x220b44 <_ZN13SoundHardware8PlayMIDIEPKcb+0x68> */
/* @0x220bc0 andseq r1, sp, r12, asr r1 */
/* @0x220bc4 .word 0xfffff7d8 */
/* @0x220bc8 .word 0xffffd3fc */
/* @0x220bcc .word 0xfffff7e0 */
/* @0x220bd0 .word 0xfffff7dc */
/* @0x220bd4 .word 0xffffbac4 */
/* @0x220bd8 andseq sp, r3, r4, lsr r4 */
/* @0x220bdc andseq r3, r3, r4, lsr #25 */

/* ── FUNC 0x220be0 · SoundHardware::SetVolume(void*, float, int) · size=432 · insn=108 */
/* @0x220be0 push {r4, r5, r6, lr} */
/* @0x220be4 vpush {d8} */
/* @0x220be8 mov r5, r1 */
/* @0x220bec ldr r4, [pc, #0x164] */
/* @0x220bf0 vmov s16, r2 */
/* @0x220bf4 ldr r1, [pc, #0x160] */
/* @0x220bf8 mov r6, r3 */
/* @0x220bfc add r4, pc, r4 */
/* @0x220c00 ldr r2, [r4, r1] */
/* @0x220c04 ldrb r2, [r2] */
/* @0x220c08 cmp r2, #0 */
/* @0x220c0c bne 0x220cd4 <_ZN13SoundHardware9SetVolumeEPvfi+0xf4> */
/* @0x220c10 ldr r2, [pc, #0x148] */
/* @0x220c14 ldr r2, [r4, r2] */
/* @0x220c18 ldrb r2, [r2] */
/* @0x220c1c cmp r2, #0 */
/* @0x220c20 bne 0x220ccc <_ZN13SoundHardware9SetVolumeEPvfi+0xec> */
/* @0x220c24 ldr r3, [pc, #0x138] */
/* @0x220c28 ldr r3, [r4, r3] */
/* @0x220c2c ldrb r3, [r3] */
/* @0x220c30 cmp r3, #0 */
/* @0x220c34 bne 0x220ccc <_ZN13SoundHardware9SetVolumeEPvfi+0xec> */
/* @0x220c38 cmp r5, #0 */
/* @0x220c3c beq 0x220ccc <_ZN13SoundHardware9SetVolumeEPvfi+0xec> */
/* @0x220c40 ldr r3, [pc, #0x120] */
/* @0x220c44 ldr r3, [r4, r3] */
/* @0x220c48 ldrb r3, [r3] */
/* @0x220c4c cmp r3, #0 */
/* @0x220c50 bne 0x220d04 <_ZN13SoundHardware9SetVolumeEPvfi+0x124> */
/* @0x220c54 ldr r3, [pc, #0x110] */
/* @0x220c58 ldr r3, [r4, r3] */
/* @0x220c5c ldr r3, [r3] */
/* @0x220c60 cmp r3, #0 */
/* @0x220c64 moveq r1, #33 */
/* @0x220c68 beq 0x220c84 <_ZN13SoundHardware9SetVolumeEPvfi+0xa4> */
/* @0x220c6c ldr r1, [r3, #0xc] */
/* @0x220c70 mov r0, #1000 */
/* @0x220c74 bl 0x318d10 <__divsi3> */
/* @0x220c78 cmp r0, #1 */
/* @0x220c7c movge r1, r0 */
/* @0x220c80 movlt r1, #1 */
/* @0x220c84 mov r0, r6 */
/* @0x220c88 bl 0x318d10 <__divsi3> */
/* @0x220c8c cmp r0, #1 */
/* @0x220c90 movlt r0, #1 */
/* @0x220c94 cmp r5, #1 */
/* @0x220c98 beq 0x220d20 <_ZN13SoundHardware9SetVolumeEPvfi+0x140> */
/* @0x220c9c ldr r3, [pc, #0xcc] */
/* @0x220ca0 ldr r3, [r4, r3] */
/* @0x220ca4 ldrb r3, [r3] */
/* @0x220ca8 cmp r3, #0 */
/* @0x220cac bne 0x220ccc <_ZN13SoundHardware9SetVolumeEPvfi+0xec> */
/* @0x220cb0 vldr s15, [r5, #24] */
/* @0x220cb4 vsub.f32 s16, s16, s15 */
/* @0x220cb8 vmov s14, r0 */
/* @0x220cbc str r0, [r5, #0x20] */
/* @0x220cc0 vcvt.f32.s32 s15, s14 */
/* @0x220cc4 vdiv.f32 s16, s16, s15 */
/* @0x220cc8 vstr s16, [r5, #28] */
/* @0x220ccc vpop {d8} */
/* @0x220cd0 pop {r4, r5, r6, pc} */
/* @0x220cd4 ldr r3, [pc, #0x98] */
/* @0x220cd8 ldr r2, [pc, #0x98] */
/* @0x220cdc ldr r1, [pc, #0x98] */
/* @0x220ce0 ldr r3, [r4, r3] */
/* @0x220ce4 add r2, pc, r2 */
/* @0x220ce8 add r1, pc, r1 */
/* @0x220cec add r2, r2, #132 */
/* @0x220cf0 ldr r0, [r3] */
/* @0x220cf4 ldr r3, [r0] */
/* @0x220cf8 ldr r3, [r3, #0xc] */
/* @0x220cfc blx r3 */
/* @0x220d00 b 0x220c10 <_ZN13SoundHardware9SetVolumeEPvfi+0x30> */
/* @0x220d04 ldr r3, [pc, #0x74] */
/* @0x220d08 ldr r0, [r4, r3] */
/* @0x220d0c bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0x220d10 vmov d7, r0, r1 */
/* @0x220d14 vcvt.s32.f64 s15, d7 */
/* @0x220d18 vmov r1, s15 */
/* @0x220d1c b 0x220c70 <_ZN13SoundHardware9SetVolumeEPvfi+0x90> */
/* @0x220d20 ldr r1, [pc, #0x5c] */
/* @0x220d24 vmov s14, r0 */
/* @0x220d28 ldr r2, [pc, #0x58] */
/* @0x220d2c vcvt.f32.s32 s15, s14 */
/* @0x220d30 ldr r3, [pc, #0x54] */
/* @0x220d34 ldr r1, [r4, r1] */
/* @0x220d38 vldr s14, [r1] */
/* @0x220d3c ldr r2, [r4, r2] */
/* @0x220d40 vsub.f32 s16, s16, s14 */
/* @0x220d44 vdiv.f32 s16, s16, s15 */
/* @0x220d48 vstr s16, [r2] */
/* @0x220d4c ldr r3, [r4, r3] */
/* @0x220d50 str r0, [r3] */
/* @0x220d54 b 0x220ccc <_ZN13SoundHardware9SetVolumeEPvfi+0xec> */
/* @0x220d58 andseq r1, sp, r4, asr r0 */
/* @0x220d5c .word 0xfffff7d8 */
/* @0x220d60 .word 0xffffd3fc */
/* @0x220d64 .word 0xfffff7e0 */
/* @0x220d68 .word 0xffffbcd4 */
/* @0x220d6c .word 0xffffbcd8 */
/* @0x220d70 .word 0xfffff7e4 */
/* @0x220d74 .word 0xffffbac4 */
/* @0x220d78 andseq sp, r3, r4, ror #5 */
/* @0x220d7c andseq r3, r3, r4, asr r11 */
/* @0x220d80 .word 0xffffbcdc */
/* @0x220d84 .word 0xfffff7e8 */
/* @0x220d88 .word 0xfffff7ec */
/* @0x220d8c .word 0xfffff7f0 */

/* ── FUNC 0x220d90 · SoundHardware::Stop(void*) · size=216 · insn=54 */
/* @0x220d90 push {r3, r4, r5, lr} */
/* @0x220d94 mov r5, r1 */
/* @0x220d98 ldr r4, [pc, #0xa8] */
/* @0x220d9c ldr r3, [pc, #0xa8] */
/* @0x220da0 add r4, pc, r4 */
/* @0x220da4 ldr r3, [r4, r3] */
/* @0x220da8 ldrb r3, [r3] */
/* @0x220dac cmp r3, #0 */
/* @0x220db0 bne 0x220e18 <_ZN13SoundHardware4StopEPv+0x88> */
/* @0x220db4 ldr r3, [pc, #0x94] */
/* @0x220db8 ldr r3, [r4, r3] */
/* @0x220dbc ldrb r3, [r3] */
/* @0x220dc0 cmp r3, #0 */
/* @0x220dc4 popne {r3, r4, r5, pc} */
/* @0x220dc8 ldr r3, [pc, #0x84] */
/* @0x220dcc ldr r3, [r4, r3] */
/* @0x220dd0 ldrb r3, [r3] */
/* @0x220dd4 cmp r3, #0 */
/* @0x220dd8 popne {r3, r4, r5, pc} */
/* @0x220ddc ldr r3, [pc, #0x74] */
/* @0x220de0 ldr r3, [r4, r3] */
/* @0x220de4 ldrb r4, [r3] */
/* @0x220de8 cmp r4, #0 */
/* @0x220dec popne {r3, r4, r5, pc} */
/* @0x220df0 cmp r5, #0 */
/* @0x220df4 popeq {r3, r4, r5, pc} */
/* @0x220df8 add r3, r5, r4 */
/* @0x220dfc add r4, r4, #4 */
/* @0x220e00 ldr r0, [r3, #0x4] */
/* @0x220e04 bl 0xb6b14 <alSourceStop@plt> */
/* @0x220e08 bl 0x220198 <_Z12CheckALErrorv> */
/* @0x220e0c cmp r4, #16 */
/* @0x220e10 bne 0x220df8 <_ZN13SoundHardware4StopEPv+0x68> */
/* @0x220e14 pop {r3, r4, r5, pc} */
/* @0x220e18 ldr r3, [pc, #0x3c] */
/* @0x220e1c ldr r2, [pc, #0x3c] */
/* @0x220e20 ldr r1, [pc, #0x3c] */
/* @0x220e24 ldr r3, [r4, r3] */
/* @0x220e28 add r2, pc, r2 */
/* @0x220e2c add r1, pc, r1 */
/* @0x220e30 add r2, r2, #144 */
/* @0x220e34 ldr r0, [r3] */
/* @0x220e38 ldr r3, [r0] */
/* @0x220e3c ldr r3, [r3, #0xc] */
/* @0x220e40 blx r3 */
/* @0x220e44 b 0x220db4 <_ZN13SoundHardware4StopEPv+0x24> */
/* @0x220e48 ldrheq r0, [sp], -r0 */
/* @0x220e4c .word 0xfffff7d8 */
/* @0x220e50 .word 0xffffd3fc */
/* @0x220e54 .word 0xfffff7e0 */
/* @0x220e58 .word 0xfffff7e4 */
/* @0x220e5c .word 0xffffbac4 */
/* @0x220e60 andseq sp, r3, r0, lsr #3 */
/* @0x220e64 andseq r3, r3, r0, lsl r10 */

/* ── FUNC 0x220e68 · SoundHardware::Resume(void*) · size=120 · insn=30 */
/* @0x220e68 push {r3, r4, r5, lr} */
/* @0x220e6c mov r5, r1 */
/* @0x220e70 ldr r3, [pc, #0x5c] */
/* @0x220e74 ldr r3, [pc, r3] */
/* @0x220e78 ldrb r3, [r3] */
/* @0x220e7c cmp r3, #0 */
/* @0x220e80 popne {r3, r4, r5, pc} */
/* @0x220e84 ldr r3, [pc, #0x4c] */
/* @0x220e88 ldr r3, [pc, r3] */
/* @0x220e8c ldrb r3, [r3] */
/* @0x220e90 cmp r3, #0 */
/* @0x220e94 popne {r3, r4, r5, pc} */
/* @0x220e98 ldr r3, [pc, #0x3c] */
/* @0x220e9c ldr r3, [pc, r3] */
/* @0x220ea0 ldrb r4, [r3] */
/* @0x220ea4 cmp r4, #0 */
/* @0x220ea8 popne {r3, r4, r5, pc} */
/* @0x220eac cmp r1, #0 */
/* @0x220eb0 popeq {r3, r4, r5, pc} */
/* @0x220eb4 add r3, r5, r4 */
/* @0x220eb8 add r4, r4, #4 */
/* @0x220ebc ldr r0, [r3, #0x4] */
/* @0x220ec0 bl 0xb6a84 <alSourcePlay@plt> */
/* @0x220ec4 bl 0x220198 <_Z12CheckALErrorv> */
/* @0x220ec8 cmp r4, #16 */
/* @0x220ecc bne 0x220eb4 <_ZN13SoundHardware6ResumeEPv+0x4c> */
/* @0x220ed0 pop {r3, r4, r5, pc} */
/* @0x220ed4 ldrsbeq lr, [r12], -r8 */
/* @0x220ed8 andseq r0, sp, r8, lsr #11 */
/* @0x220edc mulseq sp, r8, r5 */

/* ── FUNC 0x220ee0 · SoundHardware::Playing(void*) · size=264 · insn=66 */
/* @0x220ee0 push {r4, r5, r6, r7, lr} */
/* @0x220ee4 mov r5, r1 */
/* @0x220ee8 ldr r4, [pc, #0xd8] */
/* @0x220eec sub sp, sp, #12 */
/* @0x220ef0 ldr r3, [pc, #0xd4] */
/* @0x220ef4 add r4, pc, r4 */
/* @0x220ef8 ldr r3, [r4, r3] */
/* @0x220efc ldrb r3, [r3] */
/* @0x220f00 cmp r3, #0 */
/* @0x220f04 bne 0x220f90 <_ZN13SoundHardware7PlayingEPv+0xb0> */
/* @0x220f08 ldr r3, [pc, #0xc0] */
/* @0x220f0c ldr r3, [r4, r3] */
/* @0x220f10 ldrb r3, [r3] */
/* @0x220f14 cmp r3, #0 */
/* @0x220f18 bne 0x220f84 <_ZN13SoundHardware7PlayingEPv+0xa4> */
/* @0x220f1c ldr r3, [pc, #0xb0] */
/* @0x220f20 ldr r3, [r4, r3] */
/* @0x220f24 ldrb r3, [r3] */
/* @0x220f28 cmp r3, #0 */
/* @0x220f2c bne 0x220f84 <_ZN13SoundHardware7PlayingEPv+0xa4> */
/* @0x220f30 ldr r3, [pc, #0xa0] */
/* @0x220f34 ldr r3, [r4, r3] */
/* @0x220f38 ldrb r4, [r3] */
/* @0x220f3c cmp r4, #0 */
/* @0x220f40 bne 0x220f84 <_ZN13SoundHardware7PlayingEPv+0xa4> */
/* @0x220f44 cmp r5, #0 */
/* @0x220f48 beq 0x220f84 <_ZN13SoundHardware7PlayingEPv+0xa4> */
/* @0x220f4c add r7, sp, #4 */
/* @0x220f50 movw r6, #0x1012 */
/* @0x220f54 add r3, r5, r4 */
/* @0x220f58 movw r1, #0x1010 */
/* @0x220f5c mov r2, r7 */
/* @0x220f60 add r4, r4, #4 */
/* @0x220f64 ldr r0, [r3, #0x4] */
/* @0x220f68 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x220f6c bl 0x220198 <_Z12CheckALErrorv> */
/* @0x220f70 ldr r3, [sp, #0x4] */
/* @0x220f74 cmp r3, r6 */
/* @0x220f78 beq 0x220fc0 <_ZN13SoundHardware7PlayingEPv+0xe0> */
/* @0x220f7c cmp r4, #16 */
/* @0x220f80 bne 0x220f54 <_ZN13SoundHardware7PlayingEPv+0x74> */
/* @0x220f84 mov r0, #0 */
/* @0x220f88 add sp, sp, #12 */
/* @0x220f8c pop {r4, r5, r6, r7, pc} */
/* @0x220f90 ldr r3, [pc, #0x44] */
/* @0x220f94 ldr r2, [pc, #0x44] */
/* @0x220f98 ldr r1, [pc, #0x44] */
/* @0x220f9c ldr r3, [r4, r3] */
/* @0x220fa0 add r2, pc, r2 */
/* @0x220fa4 add r1, pc, r1 */
/* @0x220fa8 add r2, r2, #152 */
/* @0x220fac ldr r0, [r3] */
/* @0x220fb0 ldr r3, [r0] */
/* @0x220fb4 ldr r3, [r3, #0xc] */
/* @0x220fb8 blx r3 */
/* @0x220fbc b 0x220f08 <_ZN13SoundHardware7PlayingEPv+0x28> */
/* @0x220fc0 mov r0, #1 */
/* @0x220fc4 b 0x220f88 <_ZN13SoundHardware7PlayingEPv+0xa8> */
/* @0x220fc8 andseq r0, sp, r12, asr sp */
/* @0x220fcc .word 0xfffff7d8 */
/* @0x220fd0 .word 0xffffd3fc */
/* @0x220fd4 .word 0xfffff7e0 */
/* @0x220fd8 .word 0xfffff7e4 */
/* @0x220fdc .word 0xffffbac4 */
/* @0x220fe0 andseq sp, r3, r8, lsr #32 */
/* @0x220fe4 mulseq r3, r8, r8 */

/* ── FUNC 0x220fe8 · SoundHardware::Pause(void*) · size=144 · insn=36 */
/* @0x220fe8 push {r3, r4, r5, lr} */
/* @0x220fec mov r5, r1 */
/* @0x220ff0 ldr r3, [pc, #0x74] */
/* @0x220ff4 ldr r3, [pc, r3] */
/* @0x220ff8 ldrb r3, [r3] */
/* @0x220ffc cmp r3, #0 */
/* @0x221000 bne 0x221064 <_ZN13SoundHardware5PauseEPv+0x7c> */
/* @0x221004 ldr r3, [pc, #0x64] */
/* @0x221008 ldr r3, [pc, r3] */
/* @0x22100c ldrb r3, [r3] */
/* @0x221010 cmp r3, #0 */
/* @0x221014 bne 0x221064 <_ZN13SoundHardware5PauseEPv+0x7c> */
/* @0x221018 ldr r3, [pc, #0x54] */
/* @0x22101c ldr r3, [pc, r3] */
/* @0x221020 ldrb r4, [r3] */
/* @0x221024 cmp r4, #0 */
/* @0x221028 bne 0x221064 <_ZN13SoundHardware5PauseEPv+0x7c> */
/* @0x22102c cmp r1, #0 */
/* @0x221030 beq 0x221064 <_ZN13SoundHardware5PauseEPv+0x7c> */
/* @0x221034 bl 0x220ee0 <_ZN13SoundHardware7PlayingEPv> */
/* @0x221038 cmp r0, #0 */
/* @0x22103c beq 0x221064 <_ZN13SoundHardware5PauseEPv+0x7c> */
/* @0x221040 add r3, r5, r4 */
/* @0x221044 add r4, r4, #4 */
/* @0x221048 ldr r0, [r3, #0x4] */
/* @0x22104c bl 0xb6ab4 <alSourcePause@plt> */
/* @0x221050 bl 0x220198 <_Z12CheckALErrorv> */
/* @0x221054 cmp r4, #16 */
/* @0x221058 bne 0x221040 <_ZN13SoundHardware5PauseEPv+0x58> */
/* @0x22105c mov r0, #1 */
/* @0x221060 pop {r3, r4, r5, pc} */
/* @0x221064 mov r0, #0 */
/* @0x221068 pop {r3, r4, r5, pc} */
/* @0x22106c andseq lr, r12, r8, asr r0 */
/* @0x221070 andseq r0, sp, r8, lsr #8 */
/* @0x221074 andseq r0, sp, r8, lsl r4 */

/* ── FUNC 0x221078 · SoundHardware::PlayingMP3() · size=188 · insn=47 */
/* @0x221078 push {r4, lr} */
/* @0x22107c ldr r4, [pc, #0x90] */
/* @0x221080 ldr r3, [pc, #0x90] */
/* @0x221084 add r4, pc, r4 */
/* @0x221088 ldr r3, [r4, r3] */
/* @0x22108c ldrb r3, [r3] */
/* @0x221090 cmp r3, #0 */
/* @0x221094 bne 0x2210dc <_ZN13SoundHardware10PlayingMP3Ev+0x64> */
/* @0x221098 ldr r3, [pc, #0x7c] */
/* @0x22109c ldr r3, [r4, r3] */
/* @0x2210a0 ldrb r3, [r3] */
/* @0x2210a4 cmp r3, #0 */
/* @0x2210a8 bne 0x2210d4 <_ZN13SoundHardware10PlayingMP3Ev+0x5c> */
/* @0x2210ac ldr r3, [pc, #0x6c] */
/* @0x2210b0 ldr r3, [r4, r3] */
/* @0x2210b4 ldrb r3, [r3] */
/* @0x2210b8 cmp r3, #0 */
/* @0x2210bc bne 0x2210d4 <_ZN13SoundHardware10PlayingMP3Ev+0x5c> */
/* @0x2210c0 ldr r3, [pc, #0x5c] */
/* @0x2210c4 ldr r3, [r4, r3] */
/* @0x2210c8 ldrb r3, [r3] */
/* @0x2210cc cmp r3, #0 */
/* @0x2210d0 beq 0x22110c <_ZN13SoundHardware10PlayingMP3Ev+0x94> */
/* @0x2210d4 mov r0, #0 */
/* @0x2210d8 pop {r4, pc} */
/* @0x2210dc ldr r3, [pc, #0x44] */
/* @0x2210e0 ldr r2, [pc, #0x44] */
/* @0x2210e4 ldr r1, [pc, #0x44] */
/* @0x2210e8 ldr r3, [r4, r3] */
/* @0x2210ec add r2, pc, r2 */
/* @0x2210f0 add r1, pc, r1 */
/* @0x2210f4 add r2, r2, #160 */
/* @0x2210f8 ldr r0, [r3] */
/* @0x2210fc ldr r3, [r0] */
/* @0x221100 ldr r3, [r3, #0xc] */
/* @0x221104 blx r3 */
/* @0x221108 b 0x221098 <_ZN13SoundHardware10PlayingMP3Ev+0x20> */
/* @0x22110c pop {r4, lr} */
/* @0x221110 b 0x2232a0 <_Z17OpenAL_PlayingMP3v> */
/* @0x221114 andseq r0, sp, r12, asr #23 */
/* @0x221118 .word 0xfffff7d8 */
/* @0x22111c .word 0xffffd3fc */
/* @0x221120 .word 0xfffff7e0 */
/* @0x221124 .word 0xfffff7e4 */
/* @0x221128 .word 0xffffbac4 */
/* @0x22112c ldrsbeq r12, [r3], -r12 */
/* @0x221130 andseq r3, r3, r12, asr #14 */

/* ── FUNC 0x221134 · SoundHardware::Tick() · size=576 · insn=144 */
/* @0x221134 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x221138 vpush {d8} */
/* @0x22113c sub sp, sp, #20 */
/* @0x221140 ldr r6, [pc, #0x1f4] */
/* @0x221144 ldr r3, [pc, #0x1f4] */
/* @0x221148 add r6, pc, r6 */
/* @0x22114c str r0, [sp] */
/* @0x221150 ldr r3, [r6, r3] */
/* @0x221154 ldrb r3, [r3] */
/* @0x221158 cmp r3, #0 */
/* @0x22115c bne 0x2212f8 <_ZN13SoundHardware4TickEv+0x1c4> */
/* @0x221160 ldr r3, [pc, #0x1dc] */
/* @0x221164 ldr r3, [r6, r3] */
/* @0x221168 ldrb r3, [r3] */
/* @0x22116c cmp r3, #0 */
/* @0x221170 bne 0x2212c4 <_ZN13SoundHardware4TickEv+0x190> */
/* @0x221174 ldr r3, [pc, #0x1cc] */
/* @0x221178 ldr r3, [r6, r3] */
/* @0x22117c ldrb r3, [r3] */
/* @0x221180 cmp r3, #0 */
/* @0x221184 bne 0x2212c4 <_ZN13SoundHardware4TickEv+0x190> */
/* @0x221188 ldr r3, [pc, #0x1bc] */
/* @0x22118c ldr r3, [r6, r3] */
/* @0x221190 ldrb r3, [r3] */
/* @0x221194 cmp r3, #0 */
/* @0x221198 beq 0x221328 <_ZN13SoundHardware4TickEv+0x1f4> */
/* @0x22119c bl 0x2232d8 <_Z11OpenAL_Tickv> */
/* @0x2211a0 ldr r3, [pc, #0x1a8] */
/* @0x2211a4 ldr r10, [r6, r3] */
/* @0x2211a8 ldr r3, [r10] */
/* @0x2211ac cmp r3, #0 */
/* @0x2211b0 ble 0x221280 <_ZN13SoundHardware4TickEv+0x14c> */
/* @0x2211b4 vmov.f32 s16, #1.000000e+00 */
/* @0x2211b8 ldr r3, [pc, #0x194] */
/* @0x2211bc mov r5, #0 */
/* @0x2211c0 add r9, sp, #12 */
/* @0x2211c4 vldr s17, [pc, #364] */
/* @0x2211c8 ldr r11, [r6, r3] */
/* @0x2211cc str r6, [sp, #0x4] */
/* @0x2211d0 mov r6, r5 */
/* @0x2211d4 ldr r3, [r11, #0x4] */
/* @0x2211d8 add r2, r3, r5 */
/* @0x2211dc ldrb r3, [r3, r5] */
/* @0x2211e0 cmp r3, #0 */
/* @0x2211e4 beq 0x221268 <_ZN13SoundHardware4TickEv+0x134> */
/* @0x2211e8 ldr r8, [r2, #0x8] */
/* @0x2211ec cmp r8, #0 */
/* @0x2211f0 beq 0x221268 <_ZN13SoundHardware4TickEv+0x134> */
/* @0x2211f4 ldr r2, [r8, #0x20] */
/* @0x2211f8 cmp r2, #0 */
/* @0x2211fc ble 0x221268 <_ZN13SoundHardware4TickEv+0x134> */
/* @0x221200 vldr s14, [r8, #24] */
/* @0x221204 vldr s15, [r8, #28] */
/* @0x221208 vadd.f32 s15, s14, s15 */
/* @0x22120c vcmpe.f32 s15, #0 */
/* @0x221210 vmrs APSR_nzcv, fpscr */
/* @0x221214 vstrmi s17, [r8, #24] */
/* @0x221218 bmi 0x22122c <_ZN13SoundHardware4TickEv+0xf8> */
/* @0x22121c vcmpe.f32 s15, s16 */
/* @0x221220 vmrs APSR_nzcv, fpscr */
/* @0x221224 vmovgt.f32 s15, s16 */
/* @0x221228 vstr s15, [r8, #24] */
/* @0x22122c add r7, r8, #16 */
/* @0x221230 mov r4, r8 */
/* @0x221234 sub r2, r2, #1 */
/* @0x221238 str r2, [r8, #0x20] */
/* @0x22123c mov r2, r9 */
/* @0x221240 ldr r0, [r4, #0x4]! */
/* @0x221244 movw r1, #0x1010 */
/* @0x221248 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x22124c bl 0x220198 <_Z12CheckALErrorv> */
/* @0x221250 ldr r3, [sp, #0xc] */
/* @0x221254 movw r2, #0x1012 */
/* @0x221258 cmp r3, r2 */
/* @0x22125c beq 0x2212d0 <_ZN13SoundHardware4TickEv+0x19c> */
/* @0x221260 cmp r4, r7 */
/* @0x221264 bne 0x22123c <_ZN13SoundHardware4TickEv+0x108> */
/* @0x221268 ldr r3, [r10] */
/* @0x22126c add r6, r6, #1 */
/* @0x221270 add r5, r5, #20 */
/* @0x221274 cmp r3, r6 */
/* @0x221278 bgt 0x2211d4 <_ZN13SoundHardware4TickEv+0xa0> */
/* @0x22127c ldr r6, [sp, #0x4] */
/* @0x221280 ldr r3, [pc, #0xd0] */
/* @0x221284 ldr r3, [r6, r3] */
/* @0x221288 ldr r2, [r3] */
/* @0x22128c cmp r2, #0 */
/* @0x221290 ble 0x2212c4 <_ZN13SoundHardware4TickEv+0x190> */
/* @0x221294 ldr r1, [pc, #0xc0] */
/* @0x221298 sub r2, r2, #1 */
/* @0x22129c ldr r0, [pc, #0xbc] */
/* @0x2212a0 ldr r1, [r6, r1] */
/* @0x2212a4 vldr s14, [r1] */
/* @0x2212a8 ldr r0, [r6, r0] */
/* @0x2212ac vldr s15, [r0] */
/* @0x2212b0 vadd.f32 s15, s14, s15 */
/* @0x2212b4 str r2, [r3] */
/* @0x2212b8 vmov r0, s15 */
/* @0x2212bc vstr s15, [r1] */
/* @0x2212c0 bl 0x223254 <_Z20OpenAL_MP3_SetVolumef> */
/* @0x2212c4 add sp, sp, #20 */
/* @0x2212c8 vpop {d8} */
/* @0x2212cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2212d0 vldr s14, [r8, #24] */
/* @0x2212d4 ldr r3, [sp] */
/* @0x2212d8 vldr s15, [r3] */
/* @0x2212dc vmul.f32 s15, s14, s15 */
/* @0x2212e0 ldr r0, [r4] */
/* @0x2212e4 movw r1, #0x100a */
/* @0x2212e8 vmov r2, s15 */
/* @0x2212ec bl 0xb6a78 <alSourcef@plt> */
/* @0x2212f0 bl 0x220198 <_Z12CheckALErrorv> */
/* @0x2212f4 b 0x221260 <_ZN13SoundHardware4TickEv+0x12c> */
/* @0x2212f8 ldr r3, [pc, #0x64] */
/* @0x2212fc ldr r2, [pc, #0x64] */
/* @0x221300 ldr r1, [pc, #0x64] */
/* @0x221304 ldr r3, [r6, r3] */
/* @0x221308 add r2, pc, r2 */
/* @0x22130c add r1, pc, r1 */
/* @0x221310 add r2, r2, #172 */
/* @0x221314 ldr r0, [r3] */
/* @0x221318 ldr r3, [r0] */
/* @0x22131c ldr r3, [r3, #0xc] */
/* @0x221320 blx r3 */
/* @0x221324 b 0x221160 <_ZN13SoundHardware4TickEv+0x2c> */
/* @0x221328 ldr r0, [pc, #0x40] */
/* @0x22132c add r0, pc, r0 */
/* @0x221330 bl 0x215fd0 <_Z7checkALPKc> */
/* @0x221334 b 0x22119c <_ZN13SoundHardware4TickEv+0x68> */
/* @0x221338 andeq r0, r0, r0 */
/* @0x22133c andseq r0, sp, r8, lsl #22 */
/* @0x221340 .word 0xfffff7d8 */
/* @0x221344 .word 0xffffd3fc */
/* @0x221348 .word 0xfffff79c */
/* @0x22134c .word 0xfffff7e4 */
/* @0x221350 .word 0xfffff7c4 */
/* @0x221354 .word 0xfffff7c8 */
/* @0x221358 .word 0xfffff7f0 */
/* @0x22135c .word 0xfffff7e8 */
/* @0x221360 .word 0xfffff7ec */
/* @0x221364 .word 0xffffbac4 */
/* @0x221368 andseq r12, r3, r0, asr #25 */
/* @0x22136c andseq r3, r3, r0, lsr r5 */
/* @0x221370 andseq r3, r3, r4, ror #10 */

/* ── FUNC 0x221374 · Sound_Setup(IniFile*) · size=4 · insn=1 */
/* @0x221374 b 0x2232e8 <_Z12OpenAL_SetupP7IniFile> */

/* ── FUNC 0x221378 · _alutBufferDataConstruct · size=64 · insn=16 */
/* @0x221378 push {r3, r4, r5, r6, r7, lr} */
/* @0x22137c mov r4, r0 */
/* @0x221380 mov r0, #20 */
/* @0x221384 mov r7, r1 */
/* @0x221388 mov r6, r2 */
/* @0x22138c mov r5, r3 */
/* @0x221390 bl 0x222a98 <_alutMalloc> */
/* @0x221394 cmp r0, #0 */
/* @0x221398 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x22139c vldr s15, [sp, #24] */
/* @0x2213a0 str r4, [r0] */
/* @0x2213a4 vstr s15, [r0, #16] */
/* @0x2213a8 str r7, [r0, #0x4] */
/* @0x2213ac str r6, [r0, #0x8] */
/* @0x2213b0 str r5, [r0, #0xc] */
/* @0x2213b4 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2213b8 · _alutBufferDataDestroy · size=16 · insn=4 */
/* @0x2213b8 push {r3, lr} */
/* @0x2213bc bl 0xb655c <free@plt> */
/* @0x2213c0 mov r0, #1 */
/* @0x2213c4 pop {r3, pc} */

/* ── FUNC 0x2213c8 · _alutBufferDataGetData · size=8 · insn=2 */
/* @0x2213c8 ldr r0, [r0] */
/* @0x2213cc bx lr */

/* ── FUNC 0x2213d0 · _alutBufferDataDetachData · size=12 · insn=3 */
/* @0x2213d0 mov r3, #0 */
/* @0x2213d4 str r3, [r0] */
/* @0x2213d8 bx lr */

/* ── FUNC 0x2213dc · _alutBufferDataGetLength · size=8 · insn=2 */
/* @0x2213dc ldr r0, [r0, #0x4] */
/* @0x2213e0 bx lr */

/* ── FUNC 0x2213e4 · _alutBufferDataGetSampleFrequency · size=8 · insn=2 */
/* @0x2213e4 ldr r0, [r0, #0x10] */
/* @0x2213e8 bx lr */

/* ── FUNC 0x2213ec · _alutGetFormat · size=56 · insn=14 */
/* @0x2213ec mov r3, r0 */
/* @0x2213f0 mov r2, r1 */
/* @0x2213f4 push {r4, lr} */
/* @0x2213f8 ldr r0, [r0, #0x8] */
/* @0x2213fc ldr r1, [r3, #0xc] */
/* @0x221400 bl 0x222ac8 <_alutFormatConstruct> */
/* @0x221404 subs r4, r0, #0 */
/* @0x221408 beq 0x221414 <_alutGetFormat+0x28> */
/* @0x22140c mov r0, #1 */
/* @0x221410 pop {r4, pc} */
/* @0x221414 mov r0, #528 */
/* @0x221418 bl 0x221940 <_alutSetError> */
/* @0x22141c mov r0, r4 */
/* @0x221420 pop {r4, pc} */

/* ── FUNC 0x221424 · _alutPassBufferData · size=228 · insn=57 */
/* @0x221424 push {r4, r5, r6, r7, lr} */
/* @0x221428 vpush {d8} */
/* @0x22142c sub sp, sp, #20 */
/* @0x221430 add r5, sp, #12 */
/* @0x221434 mov r6, r0 */
/* @0x221438 mov r0, #1 */
/* @0x22143c mov r1, r5 */
/* @0x221440 bl 0xb6af0 <alGenBuffers@plt> */
/* @0x221444 bl 0xb6a54 <alGetError@plt> */
/* @0x221448 cmp r0, #0 */
/* @0x22144c bne 0x221494 <_alutPassBufferData+0x70> */
/* @0x221450 ldr r4, [sp, #0xc] */
/* @0x221454 cmp r4, #0 */
/* @0x221458 bne 0x22146c <_alutPassBufferData+0x48> */
/* @0x22145c mov r0, r4 */
/* @0x221460 add sp, sp, #20 */
/* @0x221464 vpop {d8} */
/* @0x221468 pop {r4, r5, r6, r7, pc} */
/* @0x22146c mov r1, r5 */
/* @0x221470 mov r0, r6 */
/* @0x221474 bl 0x2213ec <_alutGetFormat> */
/* @0x221478 cmp r0, #0 */
/* @0x22147c bne 0x2214b0 <_alutPassBufferData+0x8c> */
/* @0x221480 mov r4, #0 */
/* @0x221484 mov r0, r4 */
/* @0x221488 add sp, sp, #20 */
/* @0x22148c vpop {d8} */
/* @0x221490 pop {r4, r5, r6, r7, pc} */
/* @0x221494 mov r0, #524 */
/* @0x221498 mov r4, #0 */
/* @0x22149c bl 0x221940 <_alutSetError> */
/* @0x2214a0 mov r0, r4 */
/* @0x2214a4 add sp, sp, #20 */
/* @0x2214a8 vpop {d8} */
/* @0x2214ac pop {r4, r5, r6, r7, pc} */
/* @0x2214b0 mov r0, r6 */
/* @0x2214b4 bl 0x2213dc <_alutBufferDataGetLength> */
/* @0x2214b8 mov r7, r0 */
/* @0x2214bc mov r0, r6 */
/* @0x2214c0 bl 0x2213e4 <_alutBufferDataGetSampleFrequency> */
/* @0x2214c4 ldr r5, [sp, #0xc] */
/* @0x2214c8 vmov s16, r0 */
/* @0x2214cc mov r0, r6 */
/* @0x2214d0 bl 0x2213c8 <_alutBufferDataGetData> */
/* @0x2214d4 mov r3, r7 */
/* @0x2214d8 vcvt.s32.f32 s16, s16 */
/* @0x2214dc mov r1, r5 */
/* @0x2214e0 vstr s16, [sp] */
/* @0x2214e4 mov r2, r0 */
/* @0x2214e8 mov r0, r4 */
/* @0x2214ec bl 0xb6afc <alBufferData@plt> */
/* @0x2214f0 bl 0xb6a54 <alGetError@plt> */
/* @0x2214f4 cmp r0, #0 */
/* @0x2214f8 beq 0x22145c <_alutPassBufferData+0x38> */
/* @0x2214fc movw r0, #0x20d */
/* @0x221500 bl 0x221940 <_alutSetError> */
/* @0x221504 b 0x221480 <_alutPassBufferData+0x5c> */

/* ── FUNC 0x221508 · _alutCodecLinear · size=4 · insn=1 */
/* @0x221508 b 0x221378 <_alutBufferDataConstruct> */

/* ── FUNC 0x22150c · _alutCodecPCM8s · size=56 · insn=14 */
/* @0x22150c cmp r1, #0 */
/* @0x221510 push {r4, r5, r6} */
/* @0x221514 movne r12, r0 */
/* @0x221518 ldr r6, [sp, #0xc] */
/* @0x22151c addne r5, r1, r0 */
/* @0x221520 beq 0x221538 <_alutCodecPCM8s+0x2c> */
/* @0x221524 ldrb r4, [r12] */
/* @0x221528 sub r4, r4, #128 */
/* @0x22152c strb r4, [r12], #1 */
/* @0x221530 cmp r12, r5 */
/* @0x221534 bne 0x221524 <_alutCodecPCM8s+0x18> */
/* @0x221538 str r6, [sp, #0xc] */
/* @0x22153c pop {r4, r5, r6} */
/* @0x221540 b 0x221378 <_alutBufferDataConstruct> */

/* ── FUNC 0x221544 · _alutCodecPCM16 · size=56 · insn=14 */
/* @0x221544 push {r4, r5, r6} */
/* @0x221548 lsrs r5, r1, #1 */
/* @0x22154c ldr r6, [sp, #0xc] */
/* @0x221550 addne r5, r0, r5, lsl #1 */
/* @0x221554 movne r12, r0 */
/* @0x221558 beq 0x221570 <_alutCodecPCM16+0x2c> */
/* @0x22155c ldrh r4, [r12] */
/* @0x221560 rev16 r4, r4 */
/* @0x221564 strh r4, [r12], #2 */
/* @0x221568 cmp r12, r5 */
/* @0x22156c bne 0x22155c <_alutCodecPCM16+0x18> */
/* @0x221570 str r6, [sp, #0xc] */
/* @0x221574 pop {r4, r5, r6} */
/* @0x221578 b 0x221378 <_alutBufferDataConstruct> */

/* ── FUNC 0x22157c · _alutCodecULaw · size=204 · insn=51 */
/* @0x22157c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x221580 vpush {d8} */
/* @0x221584 lsl r6, r1, #1 */
/* @0x221588 sub sp, sp, #4 */
/* @0x22158c mov r9, r0 */
/* @0x221590 mov r0, r6 */
/* @0x221594 mov r4, r1 */
/* @0x221598 mov r7, r2 */
/* @0x22159c mov r8, r3 */
/* @0x2215a0 vldr s16, [sp, #48] */
/* @0x2215a4 bl 0x222a98 <_alutMalloc> */
/* @0x2215a8 subs r10, r0, #0 */
/* @0x2215ac beq 0x221638 <_alutCodecULaw+0xbc> */
/* @0x2215b0 cmp r4, #0 */
/* @0x2215b4 beq 0x22160c <_alutCodecULaw+0x90> */
/* @0x2215b8 ldr r3, [pc, #0x84] */
/* @0x2215bc add r1, r4, r9 */
/* @0x2215c0 sub r5, r10, #2 */
/* @0x2215c4 mov lr, r9 */
/* @0x2215c8 add r3, pc, r3 */
/* @0x2215cc ldrb r12, [lr], #1 */
/* @0x2215d0 mvn r12, r12 */
/* @0x2215d4 uxtb r12, r12 */
/* @0x2215d8 ubfx r4, r12, #0x4, #0x3 */
/* @0x2215dc and r11, r12, #15 */
/* @0x2215e0 add r0, r4, #3 */
/* @0x2215e4 tst r12, #128 */
/* @0x2215e8 lsl r4, r4, #1 */
/* @0x2215ec ldrh r2, [r3, r4] */
/* @0x2215f0 add r12, r2, r11, lsl r0 */
/* @0x2215f4 uxth r12, r12 */
/* @0x2215f8 rsbne r12, r12, #0 */
/* @0x2215fc cmp lr, r1 */
/* @0x221600 uxth r12, r12 */
/* @0x221604 strh r12, [r5, #2]! */
/* @0x221608 bne 0x2215cc <_alutCodecULaw+0x50> */
/* @0x22160c mov r0, r9 */
/* @0x221610 bl 0xb655c <free@plt> */
/* @0x221614 vstr s16, [sp, #48] */
/* @0x221618 mov r0, r10 */
/* @0x22161c mov r1, r6 */
/* @0x221620 mov r2, r7 */
/* @0x221624 mov r3, r8 */
/* @0x221628 add sp, sp, #4 */
/* @0x22162c vpop {d8} */
/* @0x221630 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x221634 b 0x221378 <_alutBufferDataConstruct> */
/* @0x221638 add sp, sp, #4 */
/* @0x22163c vpop {d8} */
/* @0x221640 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x221644 ldrheq r12, [r3], -r4 */

/* ── FUNC 0x221648 · _alutCodecALaw · size=204 · insn=51 */
/* @0x221648 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x22164c lsl r6, r1, #1 */
/* @0x221650 sub sp, sp, #4 */
/* @0x221654 mov r9, r0 */
/* @0x221658 mov r0, r6 */
/* @0x22165c mov r4, r1 */
/* @0x221660 mov r7, r2 */
/* @0x221664 mov r8, r3 */
/* @0x221668 ldr r11, [sp, #0x28] */
/* @0x22166c bl 0x222a98 <_alutMalloc> */
/* @0x221670 subs r10, r0, #0 */
/* @0x221674 beq 0x22170c <_alutCodecALaw+0xc4> */
/* @0x221678 cmp r4, #0 */
/* @0x22167c addne r1, r4, r9 */
/* @0x221680 subne r2, r10, #2 */
/* @0x221684 movne lr, r9 */
/* @0x221688 beq 0x2216e4 <_alutCodecALaw+0x9c> */
/* @0x22168c ldrb r12, [lr], #1 */
/* @0x221690 eor r12, r12, #85 */
/* @0x221694 ubfx r5, r12, #0x4, #0x3 */
/* @0x221698 lsl r3, r12, #4 */
/* @0x22169c sxth r4, r5 */
/* @0x2216a0 and r3, r3, #240 */
/* @0x2216a4 cmp r4, #0 */
/* @0x2216a8 addeq r4, r3, #8 */
/* @0x2216ac beq 0x2216c8 <_alutCodecALaw+0x80> */
/* @0x2216b0 cmp r4, #1 */
/* @0x2216b4 add r4, r3, #264 */
/* @0x2216b8 addne r4, r3, #264 */
/* @0x2216bc subne r5, r5, #1 */
/* @0x2216c0 lslne r4, r4, r5 */
/* @0x2216c4 uxthne r4, r4 */
/* @0x2216c8 tst r12, #128 */
/* @0x2216cc rsb r3, r4, #0 */
/* @0x2216d0 uxth r3, r3 */
/* @0x2216d4 movne r3, r4 */
/* @0x2216d8 cmp lr, r1 */
/* @0x2216dc strh r3, [r2, #2]! */
/* @0x2216e0 bne 0x22168c <_alutCodecALaw+0x44> */
/* @0x2216e4 mov r0, r9 */
/* @0x2216e8 bl 0xb655c <free@plt> */
/* @0x2216ec str r11, [sp, #0x28] */
/* @0x2216f0 mov r0, r10 */
/* @0x2216f4 mov r1, r6 */
/* @0x2216f8 mov r2, r7 */
/* @0x2216fc mov r3, r8 */
/* @0x221700 add sp, sp, #4 */
/* @0x221704 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x221708 b 0x221378 <_alutBufferDataConstruct> */
/* @0x22170c add sp, sp, #4 */
/* @0x221710 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
