/* libyoyo.so 覆盖卡组 0116
 * 函数 0x17b4cc..0x17da94，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x17b4cc · CheckSequence(int*, int*, int) · size=256 · insn=64 */
/* @0x17b4cc push {r3, r4, r5, r6, r7, lr} */
/* @0x17b4d0 vpush {d8, d9} */
/* @0x17b4d4 mov r6, r1 */
/* @0x17b4d8 ldr r3, [pc, #0xe0] */
/* @0x17b4dc mov r7, r2 */
/* @0x17b4e0 mov r5, r0 */
/* @0x17b4e4 vmov.f32 s16, #1.000000e+01 */
/* @0x17b4e8 ldr r3, [pc, r3] */
/* @0x17b4ec vldr s18, [r3] */
/* @0x17b4f0 bl 0x179988 <_Z26GR_Window_Get_Region_Widthv> */
/* @0x17b4f4 ldr r3, [pc, #0xc8] */
/* @0x17b4f8 ldr r3, [pc, r3] */
/* @0x17b4fc vldr s17, [r3] */
/* @0x17b500 vcvt.f32.s32 s18, s18 */
/* @0x17b504 vcvt.f32.s32 s17, s17 */
/* @0x17b508 vmov s14, r0 */
/* @0x17b50c vcvt.f32.s32 s15, s14 */
/* @0x17b510 vdiv.f32 s18, s18, s15 */
/* @0x17b514 bl 0x17999c <_Z27GR_Window_Get_Region_Heightv> */
/* @0x17b518 vmov s14, r0 */
/* @0x17b51c vcvt.f32.s32 s15, s14 */
/* @0x17b520 vdiv.f32 s17, s17, s15 */
/* @0x17b524 vmul.f32 s18, s18, s16 */
/* @0x17b528 vmul.f32 s16, s17, s16 */
/* @0x17b52c vcvt.s32.f32 s18, s18 */
/* @0x17b530 vcvt.s32.f32 s16, s16 */
/* @0x17b534 vmov r4, s18 */
/* @0x17b538 vmov r3, s16 */
/* @0x17b53c cmp r3, #9 */
/* @0x17b540 cmpls r4, #9 */
/* @0x17b544 movhi r0, #0 */
/* @0x17b548 movls r0, #1 */
/* @0x17b54c bhi 0x17b5b8 <_Z13CheckSequencePiS_i+0xec> */
/* @0x17b550 ldr r2, [pc, #0x70] */
/* @0x17b554 ldr r2, [pc, r2] */
/* @0x17b558 ldr r2, [r2] */
/* @0x17b55c ldr r1, [r6, r2, lsl #2] */
/* @0x17b560 ubfx r0, r1, #0x8, #0x8 */
/* @0x17b564 ubfx r2, r1, #0x10, #0x8 */
/* @0x17b568 uxtb r1, r1 */
/* @0x17b56c rsb r3, r0, r3 */
/* @0x17b570 rsb r4, r1, r4 */
/* @0x17b574 cmp r3, #0 */
/* @0x17b578 rsblt r3, r3, #0 */
/* @0x17b57c cmp r4, #0 */
/* @0x17b580 rsblt r4, r4, #0 */
/* @0x17b584 cmp r2, r3 */
/* @0x17b588 cmpge r2, r4 */
/* @0x17b58c movlt r0, #0 */
/* @0x17b590 movge r0, #1 */
/* @0x17b594 strlt r0, [r5] */
/* @0x17b598 blt 0x17b5b8 <_Z13CheckSequencePiS_i+0xec> */
/* @0x17b59c ldr r3, [r5] */
/* @0x17b5a0 add r3, r3, #1 */
/* @0x17b5a4 cmp r7, r3 */
/* @0x17b5a8 movne r0, #0 */
/* @0x17b5ac moveq r0, #1 */
/* @0x17b5b0 moveq r3, #0 */
/* @0x17b5b4 str r3, [r5] */
/* @0x17b5b8 vpop {d8, d9} */
/* @0x17b5bc pop {r3, r4, r5, r6, r7, pc} */
/* @0x17b5c0 eoreq r4, r7, r12, ror lr */
/* @0x17b5c4 eoreq r4, r7, r0, ror lr */
/* @0x17b5c8 eoreq r4, r7, r8, lsl lr */

/* ── FUNC 0x17b5cc · CheckInRect(int, int, int, int) · size=88 · insn=22 */
/* @0x17b5cc ldr r12, [pc, #0x48] */
/* @0x17b5d0 ldr r12, [pc, r12] */
/* @0x17b5d4 ldr r12, [r12] */
/* @0x17b5d8 cmp r12, r0 */
/* @0x17b5dc ble 0x17b614 <_Z11CheckInRectiiii+0x48> */
/* @0x17b5e0 add r0, r0, r2 */
/* @0x17b5e4 cmp r12, r0 */
/* @0x17b5e8 bge 0x17b614 <_Z11CheckInRectiiii+0x48> */
/* @0x17b5ec ldr r2, [pc, #0x2c] */
/* @0x17b5f0 ldr r2, [pc, r2] */
/* @0x17b5f4 ldr r2, [r2] */
/* @0x17b5f8 cmp r2, r1 */
/* @0x17b5fc ble 0x17b614 <_Z11CheckInRectiiii+0x48> */
/* @0x17b600 add r0, r1, r3 */
/* @0x17b604 cmp r2, r0 */
/* @0x17b608 movge r0, #0 */
/* @0x17b60c movlt r0, #1 */
/* @0x17b610 bx lr */
/* @0x17b614 mov r0, #0 */
/* @0x17b618 bx lr */
/* @0x17b61c mlaeq r7, r4, sp, r4 */
/* @0x17b620 eoreq r4, r7, r8, ror sp */

/* ── FUNC 0x17b624 · GraphicsPerf::HandleInput() · size=536 · insn=134 */
/* @0x17b624 push {r3, r4, r5, r6, r7, lr} */
/* @0x17b628 ldr r4, [pc, #0x1dc] */
/* @0x17b62c ldr r3, [pc, #0x1dc] */
/* @0x17b630 add r4, pc, r4 */
/* @0x17b634 ldr r1, [pc, #0x1d8] */
/* @0x17b638 ldr r2, [pc, #0x1d8] */
/* @0x17b63c ldr r3, [r4, r3] */
/* @0x17b640 ldr r1, [r4, r1] */
/* @0x17b644 ldr r2, [r4, r2] */
/* @0x17b648 ldr r3, [r3] */
/* @0x17b64c ldr r1, [r1] */
/* @0x17b650 cmp r3, #0 */
/* @0x17b654 ldr r6, [r2] */
/* @0x17b658 beq 0x17b7d8 <_ZN12GraphicsPerf11HandleInputEv+0x1b4> */
/* @0x17b65c ldrb r2, [r3, #0x44] */
/* @0x17b660 ldr r0, [r3, #0x48] */
/* @0x17b664 cmp r2, #0 */
/* @0x17b668 ldr r5, [r3, #0x14] */
/* @0x17b66c ldr r2, [r3, #0x10] */
/* @0x17b670 beq 0x17b684 <_ZN12GraphicsPerf11HandleInputEv+0x60> */
/* @0x17b674 ldrb r3, [r0] */
/* @0x17b678 cmp r3, #0 */
/* @0x17b67c ldrne r2, [r0, #0x1c] */
/* @0x17b680 ldrne r5, [r0, #0x20] */
/* @0x17b684 ldr r3, [pc, #0x190] */
/* @0x17b688 ldr r0, [pc, #0x190] */
/* @0x17b68c ldr r3, [r4, r3] */
/* @0x17b690 ldr r7, [r4, r0] */
/* @0x17b694 ldr r0, [r3] */
/* @0x17b698 mul r0, r0, r2 */
/* @0x17b69c bl 0x318d10 <__divsi3> */
/* @0x17b6a0 ldr r2, [pc, #0x17c] */
/* @0x17b6a4 ldr r3, [pc, #0x17c] */
/* @0x17b6a8 mov r1, r6 */
/* @0x17b6ac str r0, [r7] */
/* @0x17b6b0 ldr r2, [r4, r2] */
/* @0x17b6b4 ldr r6, [r4, r3] */
/* @0x17b6b8 ldr r0, [r2] */
/* @0x17b6bc mul r0, r0, r5 */
/* @0x17b6c0 bl 0x318d10 <__divsi3> */
/* @0x17b6c4 ldr r3, [pc, #0x160] */
/* @0x17b6c8 str r0, [r6] */
/* @0x17b6cc mov r0, #1 */
/* @0x17b6d0 ldr r5, [r4, r3] */
/* @0x17b6d4 ldr r1, [r5] */
/* @0x17b6d8 ands r1, r1, #1 */
/* @0x17b6dc bne 0x17b718 <_ZN12GraphicsPerf11HandleInputEv+0xf4> */
/* @0x17b6e0 bl 0x18c12c <_Z18IO_Button_Releasedii> */
/* @0x17b6e4 cmp r0, #0 */
/* @0x17b6e8 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x17b6ec ldr r3, [pc, #0x13c] */
/* @0x17b6f0 mov r2, #7 */
/* @0x17b6f4 ldr r1, [pc, #0x138] */
/* @0x17b6f8 ldr r0, [r4, r1] */
/* @0x17b6fc ldr r1, [r4, r3] */
/* @0x17b700 bl 0x17b4cc <_Z13CheckSequencePiS_i> */
/* @0x17b704 cmp r0, #0 */
/* @0x17b708 ldrne r3, [r5] */
/* @0x17b70c orrne r3, r3, #1 */
/* @0x17b710 strne r3, [r5] */
/* @0x17b714 pop {r3, r4, r5, r6, r7, pc} */
/* @0x17b718 mov r1, #0 */
/* @0x17b71c bl 0x18c12c <_Z18IO_Button_Releasedii> */
/* @0x17b720 cmp r0, #0 */
/* @0x17b724 bne 0x17b7ac <_ZN12GraphicsPerf11HandleInputEv+0x188> */
/* @0x17b728 ldr r1, [r5] */
/* @0x17b72c ands r1, r1, #8 */
/* @0x17b730 mov r0, #1 */
/* @0x17b734 bne 0x17b770 <_ZN12GraphicsPerf11HandleInputEv+0x14c> */
/* @0x17b738 bl 0x18c12c <_Z18IO_Button_Releasedii> */
/* @0x17b73c cmp r0, #0 */
/* @0x17b740 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x17b744 ldr r3, [pc, #0xec] */
/* @0x17b748 mov r2, #8 */
/* @0x17b74c ldr r1, [pc, #0xe0] */
/* @0x17b750 ldr r0, [r4, r1] */
/* @0x17b754 ldr r1, [r4, r3] */
/* @0x17b758 bl 0x17b4cc <_Z13CheckSequencePiS_i> */
/* @0x17b75c cmp r0, #0 */
/* @0x17b760 ldrne r3, [r5] */
/* @0x17b764 orrne r3, r3, #8 */
/* @0x17b768 strne r3, [r5] */
/* @0x17b76c pop {r3, r4, r5, r6, r7, pc} */
/* @0x17b770 mov r1, #0 */
/* @0x17b774 bl 0x18c12c <_Z18IO_Button_Releasedii> */
/* @0x17b778 cmp r0, #0 */
/* @0x17b77c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x17b780 mov r0, #10 */
/* @0x17b784 mov r2, #64 */
/* @0x17b788 mov r1, r0 */
/* @0x17b78c mov r3, #16 */
/* @0x17b790 bl 0x17b5cc <_Z11CheckInRectiiii> */
/* @0x17b794 cmp r0, #0 */
/* @0x17b798 beq 0x17b7e4 <_ZN12GraphicsPerf11HandleInputEv+0x1c0> */
/* @0x17b79c ldr r3, [r5] */
/* @0x17b7a0 eor r3, r3, #2 */
/* @0x17b7a4 str r3, [r5] */
/* @0x17b7a8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x17b7ac bl 0x179988 <_Z26GR_Window_Get_Region_Widthv> */
/* @0x17b7b0 mov r1, #80 */
/* @0x17b7b4 mov r2, #64 */
/* @0x17b7b8 mov r3, #16 */
/* @0x17b7bc sub r0, r0, #80 */
/* @0x17b7c0 bl 0x17b5cc <_Z11CheckInRectiiii> */
/* @0x17b7c4 ldr r1, [r5] */
/* @0x17b7c8 cmp r0, #0 */
/* @0x17b7cc bicne r1, r1, #9 */
/* @0x17b7d0 strne r1, [r5] */
/* @0x17b7d4 b 0x17b72c <_ZN12GraphicsPerf11HandleInputEv+0x108> */
/* @0x17b7d8 mov r5, r6 */
/* @0x17b7dc mov r2, r1 */
/* @0x17b7e0 b 0x17b684 <_ZN12GraphicsPerf11HandleInputEv+0x60> */
/* @0x17b7e4 mov r3, #16 */
/* @0x17b7e8 mov r0, #10 */
/* @0x17b7ec mov r1, #30 */
/* @0x17b7f0 mov r2, #64 */
/* @0x17b7f4 bl 0x17b5cc <_Z11CheckInRectiiii> */
/* @0x17b7f8 cmp r0, #0 */
/* @0x17b7fc ldrne r3, [r5] */
/* @0x17b800 eorne r3, r3, #16 */
/* @0x17b804 strne r3, [r5] */
/* @0x17b808 pop {r3, r4, r5, r6, r7, pc} */
/* @0x17b80c eoreq r6, r7, r0, lsr #12 */
/* @0x17b810 .word 0xffffbcd8 */
/* @0x17b814 .word 0xffffe24c */
/* @0x17b818 .word 0xffffe250 */
/* @0x17b81c .word 0xffffe720 */
/* @0x17b820 .word 0xffffe714 */
/* @0x17b824 .word 0xffffe724 */
/* @0x17b828 .word 0xffffe718 */
/* @0x17b82c .word 0xffffc7dc */
/* @0x17b830 .word 0xffffe728 */
/* @0x17b834 .word 0xffffe71c */
/* @0x17b838 .word 0xffffe72c */

/* ── FUNC 0x17b83c · GraphicsPerf::RenderRectangle(float, float, float, float, unsigned int) · size=164 · insn=41 */
/* @0x17b83c push {r4, lr} */
/* @0x17b840 vpush {d8, d9} */
/* @0x17b844 vmov s17, r1 */
/* @0x17b848 vmov s16, r0 */
/* @0x17b84c mov r1, #0 */
/* @0x17b850 vmov s18, r2 */
/* @0x17b854 mov r0, #5 */
/* @0x17b858 vmov s19, r3 */
/* @0x17b85c mov r2, #24 */
/* @0x17b860 mov r3, #4 */
/* @0x17b864 ldr r4, [sp, #0x18] */
/* @0x17b868 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x17b86c vadd.f32 s15, s17, s19 */
/* @0x17b870 mov r3, #0 */
/* @0x17b874 vstr s16, [r0] */
/* @0x17b878 vstr s16, [r0, #24] */
/* @0x17b87c vadd.f32 s16, s16, s18 */
/* @0x17b880 vstr s17, [r0, #28] */
/* @0x17b884 vstr s17, [r0, #76] */
/* @0x17b888 str r3, [r0, #0x14] */
/* @0x17b88c str r3, [r0, #0x10] */
/* @0x17b890 vstr s15, [r0, #4] */
/* @0x17b894 str r3, [r0, #0x2c] */
/* @0x17b898 vstr s15, [r0, #52] */
/* @0x17b89c str r3, [r0, #0x28] */
/* @0x17b8a0 str r3, [r0, #0x44] */
/* @0x17b8a4 str r3, [r0, #0x40] */
/* @0x17b8a8 str r3, [r0, #0x5c] */
/* @0x17b8ac str r3, [r0, #0x58] */
/* @0x17b8b0 str r4, [r0, #0xc] */
/* @0x17b8b4 vstr s16, [r0, #48] */
/* @0x17b8b8 vstr s16, [r0, #72] */
/* @0x17b8bc vpop {d8, d9} */
/* @0x17b8c0 str r4, [r0, #0x24] */
/* @0x17b8c4 str r4, [r0, #0x3c] */
/* @0x17b8c8 str r4, [r0, #0x54] */
/* @0x17b8cc str r3, [r0, #0x8] */
/* @0x17b8d0 str r3, [r0, #0x20] */
/* @0x17b8d4 str r3, [r0, #0x38] */
/* @0x17b8d8 str r3, [r0, #0x50] */
/* @0x17b8dc pop {r4, pc} */

/* ── FUNC 0x17b8e0 · GraphicsPerf::DisplayConsole() · size=4 · insn=1 */
/* @0x17b8e0 bx lr */

/* ── FUNC 0x17b8e4 · GraphicsPerf::DisplayAudio() · size=4 · insn=1 */
/* @0x17b8e4 b 0x21e384 <_Z16YYAudioDrawDebugv> */

/* ── FUNC 0x17b8e8 · GraphicsPerf::DisplayXBGameChat() · size=4 · insn=1 */
/* @0x17b8e8 bx lr */

/* ── FUNC 0x17b8ec · GraphicsPerf::DisplayAudioSync() · size=4 · insn=1 */
/* @0x17b8ec b 0x215fc0 <_Z21OggAudioSyncDrawDebugv> */

/* ── FUNC 0x17b8f0 · GraphicsPerf::Push(unsigned int, char const*) · size=176 · insn=44 */
/* @0x17b8f0 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x17b8f4 mov r7, r0 */
/* @0x17b8f8 ldr r4, [pc, #0x88] */
/* @0x17b8fc mov r6, r1 */
/* @0x17b900 ldr r3, [pc, #0x84] */
/* @0x17b904 add r4, pc, r4 */
/* @0x17b908 ldr r3, [r4, r3] */
/* @0x17b90c ldr r3, [r3] */
/* @0x17b910 cmp r3, #0 */
/* @0x17b914 beq 0x17b980 <_ZN12GraphicsPerf4PushEjPKc+0x90> */
/* @0x17b918 ldr r3, [pc, #0x70] */
/* @0x17b91c ldr r2, [r4, r3] */
/* @0x17b920 ldr r3, [r2] */
/* @0x17b924 cmp r3, #1024 */
/* @0x17b928 pophs {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x17b92c ldr lr, [pc, #0x60] */
/* @0x17b930 add r12, r3, #1 */
/* @0x17b934 ldr r0, [pc, #0x5c] */
/* @0x17b938 lsl r9, r3, #5 */
/* @0x17b93c ldr r1, [pc, #0x58] */
/* @0x17b940 ldr r5, [r4, lr] */
/* @0x17b944 str r12, [r2] */
/* @0x17b948 ldr r8, [r4, r0] */
/* @0x17b94c ldr r3, [r5] */
/* @0x17b950 ldr r4, [r4, r1] */
/* @0x17b954 add r2, r9, r4 */
/* @0x17b958 str r2, [r8, r3, lsl #2] */
/* @0x17b95c bl 0x215148 <Timing_Time> */
/* @0x17b960 ldr r3, [r5] */
/* @0x17b964 add r2, r3, #1 */
/* @0x17b968 str r2, [r5] */
/* @0x17b96c ldr r2, [r8, r3, lsl #2] */
/* @0x17b970 strd r0, r1, [r4, r9] */
/* @0x17b974 str r7, [r2, #0x10] */
/* @0x17b978 str r6, [r2, #0x18] */
/* @0x17b97c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x17b980 bl 0x17b9a0 <_ZN12GraphicsPerf10BeginFrameEv> */
/* @0x17b984 b 0x17b918 <_ZN12GraphicsPerf4PushEjPKc+0x28> */
/* @0x17b988 eoreq r6, r7, r12, asr #6 */
/* @0x17b98c .word 0xffffe6e0 */
/* @0x17b990 .word 0xffffe730 */
/* @0x17b994 .word 0xffffe6dc */
/* @0x17b998 .word 0xffffe734 */
/* @0x17b99c .word 0xffffe738 */

/* ── FUNC 0x17b9a0 · GraphicsPerf::BeginFrame() · size=368 · insn=92 */
/* @0x17b9a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17b9a4 mov r5, #0 */
/* @0x17b9a8 ldr r4, [pc, #0x110] */
/* @0x17b9ac sub sp, sp, #12 */
/* @0x17b9b0 ldr r1, [pc, #0x10c] */
/* @0x17b9b4 mov r2, #1 */
/* @0x17b9b8 add r4, pc, r4 */
/* @0x17b9bc ldr r3, [pc, #0x104] */
/* @0x17b9c0 ldr r10, [pc, #0x104] */
/* @0x17b9c4 ldr r1, [r4, r1] */
/* @0x17b9c8 ldr r9, [pc, #0x100] */
/* @0x17b9cc ldr r8, [pc, #0x100] */
/* @0x17b9d0 str r5, [r1] */
/* @0x17b9d4 ldr r3, [r4, r3] */
/* @0x17b9d8 ldr r7, [pc, #0xf8] */
/* @0x17b9dc ldr r6, [pc, #0xf8] */
/* @0x17b9e0 str r2, [r3] */
/* @0x17b9e4 bl 0x215148 <Timing_Time> */
/* @0x17b9e8 ldr r3, [pc, #0xf0] */
/* @0x17b9ec ldr r12, [pc, #0xf0] */
/* @0x17b9f0 ldr r2, [pc, #0xf0] */
/* @0x17b9f4 ldr r3, [r4, r3] */
/* @0x17b9f8 str r3, [sp, #0x4] */
/* @0x17b9fc ldr r11, [sp, #0x4] */
/* @0x17ba00 ldr r3, [pc, #0xe4] */
/* @0x17ba04 str r3, [sp] */
/* @0x17ba08 ldr r3, [pc, #0xe0] */
/* @0x17ba0c strd r0, r1, [r11] */
/* @0x17ba10 mov r0, #128 */
/* @0x17ba14 ldr r1, [r4, r10] */
/* @0x17ba18 movt r0, #0xff00 */
/* @0x17ba1c str r5, [r1] */
/* @0x17ba20 ldr r1, [r4, r9] */
/* @0x17ba24 str r5, [r1] */
/* @0x17ba28 ldr r1, [r4, r8] */
/* @0x17ba2c str r5, [r1] */
/* @0x17ba30 ldr r1, [r4, r7] */
/* @0x17ba34 str r5, [r1] */
/* @0x17ba38 ldr r6, [r4, r6] */
/* @0x17ba3c ldr r1, [pc, #0xb0] */
/* @0x17ba40 str r5, [r6] */
/* @0x17ba44 add r1, pc, r1 */
/* @0x17ba48 ldr r6, [pc, #0xa8] */
/* @0x17ba4c ldr r6, [r4, r6] */
/* @0x17ba50 str r5, [r6] */
/* @0x17ba54 ldr r6, [pc, #0xa0] */
/* @0x17ba58 ldr r6, [r4, r6] */
/* @0x17ba5c str r5, [r6] */
/* @0x17ba60 ldr r6, [pc, #0x98] */
/* @0x17ba64 ldr r6, [r4, r6] */
/* @0x17ba68 str r5, [r6] */
/* @0x17ba6c ldr r6, [pc, #0x90] */
/* @0x17ba70 ldr r6, [r4, r6] */
/* @0x17ba74 str r5, [r6] */
/* @0x17ba78 ldr r6, [pc, #0x88] */
/* @0x17ba7c ldr r6, [r4, r6] */
/* @0x17ba80 str r5, [r6] */
/* @0x17ba84 ldr r6, [pc, #0x80] */
/* @0x17ba88 ldr r6, [r4, r6] */
/* @0x17ba8c str r5, [r6] */
/* @0x17ba90 ldr r6, [sp] */
/* @0x17ba94 ldr r6, [r4, r6] */
/* @0x17ba98 str r5, [r6] */
/* @0x17ba9c ldr r12, [r4, r12] */
/* @0x17baa0 str r5, [r12] */
/* @0x17baa4 ldr r2, [r4, r2] */
/* @0x17baa8 str r5, [r2] */
/* @0x17baac ldr r3, [r4, r3] */
/* @0x17bab0 str r5, [r3] */
/* @0x17bab4 add sp, sp, #12 */
/* @0x17bab8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17babc b 0x17b8f0 <_ZN12GraphicsPerf4PushEjPKc> */
/* @0x17bac0 mlaeq r7, r8, r2, r6 */
/* @0x17bac4 .word 0xffffe6dc */
/* @0x17bac8 .word 0xffffe6e0 */
/* @0x17bacc .word 0xffffe730 */
/* @0x17bad0 .word 0xffffe73c */
/* @0x17bad4 .word 0xffffe740 */
/* @0x17bad8 .word 0xffffe744 */
/* @0x17badc .word 0xffffe748 */
/* @0x17bae0 .word 0xffffe74c */
/* @0x17bae4 .word 0xffffe750 */
/* @0x17bae8 .word 0xffffe754 */
/* @0x17baec .word 0xffffe758 */
/* @0x17baf0 .word 0xffffe75c */
/* @0x17baf4 ldrheq pc, [r12], -r4 */
/* @0x17baf8 .word 0xffffe760 */
/* @0x17bafc .word 0xffffe764 */
/* @0x17bb00 .word 0xffffe768 */
/* @0x17bb04 .word 0xffffe76c */
/* @0x17bb08 .word 0xffffe770 */
/* @0x17bb0c .word 0xffffe774 */

/* ── FUNC 0x17bb10 · GraphicsPerf::Pop() · size=64 · insn=16 */
/* @0x17bb10 ldr r3, [pc, #0x30] */
/* @0x17bb14 push {r4, lr} */
/* @0x17bb18 ldr r3, [pc, r3] */
/* @0x17bb1c ldr r2, [r3] */
/* @0x17bb20 cmp r2, #0 */
/* @0x17bb24 pople {r4, pc} */
/* @0x17bb28 ldr r1, [pc, #0x1c] */
/* @0x17bb2c sub r2, r2, #1 */
/* @0x17bb30 str r2, [r3] */
/* @0x17bb34 ldr r1, [pc, r1] */
/* @0x17bb38 ldr r4, [r1, r2, lsl #2] */
/* @0x17bb3c bl 0x215148 <Timing_Time> */
/* @0x17bb40 strd r0, r1, [r4, #8] */
/* @0x17bb44 pop {r4, pc} */
/* @0x17bb48 eoreq r4, r7, r4, lsl r8 */
/* @0x17bb4c eoreq r4, r7, r0, asr r8 */

/* ── FUNC 0x17bb50 · AddPerfBar(SVertex_Float*, float, float, unsigned int) · size=172 · insn=43 */
/* @0x17bb50 str r1, [r0] */
/* @0x17bb54 mov r12, #0 */
/* @0x17bb58 str r1, [r0, #0x60] */
/* @0x17bb5c movt r12, #0x4120 */
/* @0x17bb60 str r1, [r0, #0x78] */
/* @0x17bb64 mov r1, #0 */
/* @0x17bb68 str r3, [r0, #0x84] */
/* @0x17bb6c movt r1, #0x41a0 */
/* @0x17bb70 str r2, [r0, #0x18] */
/* @0x17bb74 str r2, [r0, #0x30] */
/* @0x17bb78 str r2, [r0, #0x48] */
/* @0x17bb7c mov r2, #0 */
/* @0x17bb80 str r3, [r0, #0x6c] */
/* @0x17bb84 str r3, [r0, #0x54] */
/* @0x17bb88 str r3, [r0, #0x3c] */
/* @0x17bb8c str r3, [r0, #0x24] */
/* @0x17bb90 str r3, [r0, #0xc] */
/* @0x17bb94 mov r3, #1056964608 */
/* @0x17bb98 str r2, [r0, #0x88] */
/* @0x17bb9c str r2, [r0, #0x70] */
/* @0x17bba0 str r2, [r0, #0x58] */
/* @0x17bba4 str r12, [r0, #0x4] */
/* @0x17bba8 str r12, [r0, #0x1c] */
/* @0x17bbac str r12, [r0, #0x7c] */
/* @0x17bbb0 str r2, [r0, #0x40] */
/* @0x17bbb4 str r2, [r0, #0x28] */
/* @0x17bbb8 str r2, [r0, #0x10] */
/* @0x17bbbc str r2, [r0, #0x8c] */
/* @0x17bbc0 str r2, [r0, #0x74] */
/* @0x17bbc4 str r2, [r0, #0x5c] */
/* @0x17bbc8 str r1, [r0, #0x34] */
/* @0x17bbcc str r1, [r0, #0x4c] */
/* @0x17bbd0 str r1, [r0, #0x64] */
/* @0x17bbd4 str r3, [r0, #0x80] */
/* @0x17bbd8 str r3, [r0, #0x68] */
/* @0x17bbdc str r3, [r0, #0x50] */
/* @0x17bbe0 str r3, [r0, #0x38] */
/* @0x17bbe4 str r3, [r0, #0x20] */
/* @0x17bbe8 str r3, [r0, #0x8] */
/* @0x17bbec str r2, [r0, #0x44] */
/* @0x17bbf0 str r2, [r0, #0x2c] */
/* @0x17bbf4 str r2, [r0, #0x14] */
/* @0x17bbf8 bx lr */

/* ── FUNC 0x17bbfc · GraphicsPerf::BuildPerfDisplay() · size=504 · insn=126 */
/* @0x17bbfc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x17bc00 vpush {d8, d9} */
/* @0x17bc04 ldr r4, [pc, #0x1cc] */
/* @0x17bc08 ldr r3, [pc, #0x1cc] */
/* @0x17bc0c add r4, pc, r4 */
/* @0x17bc10 ldr r3, [r4, r3] */
/* @0x17bc14 ldrb r1, [r3] */
/* @0x17bc18 cmp r1, #0 */
/* @0x17bc1c beq 0x17bc28 <_ZN12GraphicsPerf16BuildPerfDisplayEv+0x2c> */
/* @0x17bc20 vpop {d8, d9} */
/* @0x17bc24 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x17bc28 ldr r3, [pc, #0x1b0] */
/* @0x17bc2c mov r2, #24 */
/* @0x17bc30 mov r0, #4 */
/* @0x17bc34 ldr r6, [r4, r3] */
/* @0x17bc38 ldr r3, [r6] */
/* @0x17bc3c add r3, r3, #1 */
/* @0x17bc40 add r3, r3, r3, lsl #1 */
/* @0x17bc44 lsl r3, r3, #1 */
/* @0x17bc48 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x17bc4c mov r5, r0 */
/* @0x17bc50 bl 0x179988 <_Z26GR_Window_Get_Region_Widthv> */
/* @0x17bc54 ldr r3, [pc, #0x188] */
/* @0x17bc58 add r7, r5, #144 */
/* @0x17bc5c ldr r3, [r4, r3] */
/* @0x17bc60 vmov s14, r0 */
/* @0x17bc64 ldrd r0, r1, [r3] */
/* @0x17bc68 vcvt.f32.s32 s17, s14 */
/* @0x17bc6c bl 0x319398 <__floatdisf> */
/* @0x17bc70 ldr r2, [pc, #0x170] */
/* @0x17bc74 mov r1, #0 */
/* @0x17bc78 mvn r3, #0 */
/* @0x17bc7c ldr r8, [r4, r2] */
/* @0x17bc80 vldr s15, [r8] */
/* @0x17bc84 vmov s14, r0 */
/* @0x17bc88 mov r0, r5 */
/* @0x17bc8c vdiv.f32 s15, s14, s15 */
/* @0x17bc90 vmul.f32 s15, s15, s17 */
/* @0x17bc94 vmov r2, s15 */
/* @0x17bc98 bl 0x17bb50 <_Z10AddPerfBarP13SVertex_Floatffj> */
/* @0x17bc9c ldr r10, [r6] */
/* @0x17bca0 subs r10, r10, #1 */
/* @0x17bca4 bmi 0x17bd2c <_ZN12GraphicsPerf16BuildPerfDisplayEv+0x130> */
/* @0x17bca8 ldr r2, [pc, #0x13c] */
/* @0x17bcac ldr r3, [pc, #0x13c] */
/* @0x17bcb0 ldr r6, [r4, r2] */
/* @0x17bcb4 ldr r9, [r4, r3] */
/* @0x17bcb8 add r6, r6, #32 */
/* @0x17bcbc ldrd r4, r5, [r9] */
/* @0x17bcc0 vldr s16, [r8] */
/* @0x17bcc4 ldrd r0, r1, [r6, #-32] */
/* @0x17bcc8 sub r10, r10, #1 */
/* @0x17bccc add r6, r6, #32 */
/* @0x17bcd0 subs r0, r0, r4 */
/* @0x17bcd4 sbc r1, r1, r5 */
/* @0x17bcd8 bl 0x319398 <__floatdisf> */
/* @0x17bcdc ldrd r2, r3, [r6, #-56] */
/* @0x17bce0 mov r1, r3 */
/* @0x17bce4 vmov s15, r0 */
/* @0x17bce8 mov r0, r2 */
/* @0x17bcec subs r0, r0, r4 */
/* @0x17bcf0 sbc r1, r1, r5 */
/* @0x17bcf4 vdiv.f32 s18, s15, s16 */
/* @0x17bcf8 bl 0x319398 <__floatdisf> */
/* @0x17bcfc ldr r3, [r6, #-0x30] */
/* @0x17bd00 vmov s14, r0 */
/* @0x17bd04 mov r0, r7 */
/* @0x17bd08 add r7, r7, #144 */
/* @0x17bd0c vdiv.f32 s16, s14, s16 */
/* @0x17bd10 vmul.f32 s18, s18, s17 */
/* @0x17bd14 vmul.f32 s16, s16, s17 */
/* @0x17bd18 vmov r1, s18 */
/* @0x17bd1c vmov r2, s16 */
/* @0x17bd20 bl 0x17bb50 <_Z10AddPerfBarP13SVertex_Floatffj> */
/* @0x17bd24 cmn r10, #1 */
/* @0x17bd28 bne 0x17bcbc <_ZN12GraphicsPerf16BuildPerfDisplayEv+0xc0> */
/* @0x17bd2c mov r1, #0 */
/* @0x17bd30 mov r2, #24 */
/* @0x17bd34 mov r3, #10 */
/* @0x17bd38 mov r0, #2 */
/* @0x17bd3c bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x17bd40 vcvt.s32.f32 s17, s17 */
/* @0x17bd44 mov r12, #0 */
/* @0x17bd48 movw r5, #0xcccd */
/* @0x17bd4c movt r5, #0x3ecc */
/* @0x17bd50 mvn r4, #0 */
/* @0x17bd54 mov r1, #0 */
/* @0x17bd58 mov r8, #1090519040 */
/* @0x17bd5c vmov r6, s17 */
/* @0x17bd60 add r7, r6, #3 */
/* @0x17bd64 cmp r6, r12 */
/* @0x17bd68 movlt r6, r7 */
/* @0x17bd6c mov r7, #0 */
/* @0x17bd70 asr r6, r6, #2 */
/* @0x17bd74 movt r7, #0x41a0 */
/* @0x17bd78 add r3, r0, #48 */
/* @0x17bd7c add r2, r0, #44 */
/* @0x17bd80 add r0, r0, #288 */
/* @0x17bd84 vmov s14, r12 */
/* @0x17bd88 add r3, r3, #48 */
/* @0x17bd8c add r12, r12, r6 */
/* @0x17bd90 add r2, r2, #48 */
/* @0x17bd94 vcvt.f32.s32 s15, s14 */
/* @0x17bd98 vstr s15, [r3, #-96] */
/* @0x17bd9c vstr s15, [r2, #-68] */
/* @0x17bda0 str r8, [r3, #-0x5c] */
/* @0x17bda4 str r7, [r2, #-0x40] */
/* @0x17bda8 str r5, [r2, #-0x3c] */
/* @0x17bdac str r5, [r3, #-0x58] */
/* @0x17bdb0 str r4, [r2, #-0x38] */
/* @0x17bdb4 str r4, [r3, #-0x54] */
/* @0x17bdb8 str r1, [r2, #-0x30] */
/* @0x17bdbc str r1, [r3, #-0x4c] */
/* @0x17bdc0 str r1, [r2, #-0x34] */
/* @0x17bdc4 str r1, [r3, #-0x50] */
/* @0x17bdc8 cmp r3, r0 */
/* @0x17bdcc bne 0x17bd84 <_ZN12GraphicsPerf16BuildPerfDisplayEv+0x188> */
/* @0x17bdd0 vpop {d8, d9} */
/* @0x17bdd4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x17bdd8 eoreq r6, r7, r4, asr #32 */
/* @0x17bddc .word 0xffffdfa0 */
/* @0x17bde0 .word 0xffffe730 */
/* @0x17bde4 .word 0xffffe778 */
/* @0x17bde8 .word 0xffffe6d8 */
/* @0x17bdec .word 0xffffe738 */
/* @0x17bdf0 .word 0xffffe74c */

/* ── FUNC 0x17bdf4 · GraphicsPerf::AddMemoryBar(int, unsigned int, void*) · size=292 · insn=73 */
/* @0x17bdf4 vmov.f32 s15, #1.000000e+00 */
/* @0x17bdf8 push {r3, r4, r5, lr} */
/* @0x17bdfc vpush {d8} */
/* @0x17be00 vmov s13, r0 */
/* @0x17be04 ldr r3, [pc, #0x100] */
/* @0x17be08 mov r4, r2 */
/* @0x17be0c mov r5, r1 */
/* @0x17be10 ldr r3, [pc, r3] */
/* @0x17be14 vldr s16, [r3] */
/* @0x17be18 vcvt.f32.s32 s16, s16 */
/* @0x17be1c vdiv.f32 s16, s15, s16 */
/* @0x17be20 vcvt.f32.s32 s15, s13 */
/* @0x17be24 vmul.f32 s16, s15, s16 */
/* @0x17be28 bl 0x179988 <_Z26GR_Window_Get_Region_Widthv> */
/* @0x17be2c ldr r12, [pc, #0xdc] */
/* @0x17be30 mov r2, #1056964608 */
/* @0x17be34 ldr r1, [pc, #0xd8] */
/* @0x17be38 mov r3, #0 */
/* @0x17be3c ldr r12, [pc, r12] */
/* @0x17be40 vldr s15, [r12] */
/* @0x17be44 vstr s15, [r4] */
/* @0x17be48 vstr s15, [r4, #96] */
/* @0x17be4c vstr s15, [r4, #120] */
/* @0x17be50 movt r3, #0x4220 */
/* @0x17be54 str r5, [r4, #0x84] */
/* @0x17be58 str r3, [r4, #0x34] */
/* @0x17be5c str r5, [r4, #0x6c] */
/* @0x17be60 str r5, [r4, #0x54] */
/* @0x17be64 str r5, [r4, #0x3c] */
/* @0x17be68 str r3, [r4, #0x4c] */
/* @0x17be6c str r5, [r4, #0x24] */
/* @0x17be70 str r3, [r4, #0x64] */
/* @0x17be74 mov r3, #0 */
/* @0x17be78 str r5, [r4, #0xc] */
/* @0x17be7c mov r5, #0 */
/* @0x17be80 str r3, [r4, #0x88] */
/* @0x17be84 movt r5, #0x41f0 */
/* @0x17be88 str r3, [r4, #0x70] */
/* @0x17be8c str r3, [r4, #0x58] */
/* @0x17be90 str r3, [r4, #0x40] */
/* @0x17be94 str r3, [r4, #0x28] */
/* @0x17be98 str r3, [r4, #0x10] */
/* @0x17be9c str r3, [r4, #0x8c] */
/* @0x17bea0 str r2, [r4, #0x80] */
/* @0x17bea4 str r2, [r4, #0x68] */
/* @0x17bea8 str r2, [r4, #0x50] */
/* @0x17beac str r2, [r4, #0x38] */
/* @0x17beb0 str r2, [r4, #0x20] */
/* @0x17beb4 str r2, [r4, #0x8] */
/* @0x17beb8 str r5, [r4, #0x4] */
/* @0x17bebc str r5, [r4, #0x1c] */
/* @0x17bec0 str r5, [r4, #0x7c] */
/* @0x17bec4 vmov s13, r0 */
/* @0x17bec8 vcvt.f32.s32 s14, s13 */
/* @0x17becc vmla.f32 s15, s14, s16 */
/* @0x17bed0 vstr s15, [r4, #24] */
/* @0x17bed4 vstr s15, [r4, #48] */
/* @0x17bed8 vstr s15, [r4, #72] */
/* @0x17bedc str r3, [r4, #0x74] */
/* @0x17bee0 str r3, [r4, #0x5c] */
/* @0x17bee4 ldr r1, [pc, r1] */
/* @0x17bee8 str r3, [r4, #0x44] */
/* @0x17beec vstr s15, [r12] */
/* @0x17bef0 str r3, [r4, #0x2c] */
/* @0x17bef4 str r3, [r4, #0x14] */
/* @0x17bef8 vpop {d8} */
/* @0x17befc ldr r2, [r1] */
/* @0x17bf00 add r3, r2, #2 */
/* @0x17bf04 str r3, [r1] */
/* @0x17bf08 pop {r3, r4, r5, pc} */
/* @0x17bf0c .word 0x002745bc */
/* @0x17bf10 mlaeq r7, r4, r5, r4 */
/* @0x17bf14 .word 0x002744f0 */

/* ── FUNC 0x17bf18 · GraphicsPerf::GenerateMemoryPerf() · size=280 · insn=70 */
/* @0x17bf18 push {r3, r4, r5, r6, r7, lr} */
/* @0x17bf1c ldr r4, [pc, #0xec] */
/* @0x17bf20 ldr r3, [pc, #0xec] */
/* @0x17bf24 ldr r2, [pc, #0xec] */
/* @0x17bf28 add r4, pc, r4 */
/* @0x17bf2c ldr r6, [r4, r3] */
/* @0x17bf30 ldr r0, [r4, r2] */
/* @0x17bf34 ldr r1, [r6] */
/* @0x17bf38 ldr r3, [r0] */
/* @0x17bf3c cmp r3, r1 */
/* @0x17bf40 bhs 0x17bf58 <_ZN12GraphicsPerf18GenerateMemoryPerfEv+0x40> */
/* @0x17bf44 add r2, r3, r3, lsl #1 */
/* @0x17bf48 cmp r2, r1 */
/* @0x17bf4c mov r3, r2 */
/* @0x17bf50 blo 0x17bf44 <_ZN12GraphicsPerf18GenerateMemoryPerfEv+0x2c> */
/* @0x17bf54 str r2, [r0] */
/* @0x17bf58 ldr r0, [pc, #0xbc] */
/* @0x17bf5c mov r12, #0 */
/* @0x17bf60 ldr lr, [pc, #0xb8] */
/* @0x17bf64 mov r1, r12 */
/* @0x17bf68 mov r2, #24 */
/* @0x17bf6c mov r7, #0 */
/* @0x17bf70 ldr r5, [r4, r0] */
/* @0x17bf74 mov r3, r2 */
/* @0x17bf78 mov r0, #4 */
/* @0x17bf7c str r12, [r5] */
/* @0x17bf80 ldr r12, [r4, lr] */
/* @0x17bf84 str r7, [r12] */
/* @0x17bf88 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x17bf8c ldr r3, [pc, #0x90] */
/* @0x17bf90 mov r1, #0 */
/* @0x17bf94 movt r1, #0xffff */
/* @0x17bf98 ldr r7, [r4, r3] */
/* @0x17bf9c mov r5, r0 */
/* @0x17bfa0 mov r2, r0 */
/* @0x17bfa4 ldr r0, [r7] */
/* @0x17bfa8 bl 0x17bdf4 <_ZN12GraphicsPerf12AddMemoryBarEijPv> */
/* @0x17bfac ldr r0, [pc, #0x74] */
/* @0x17bfb0 ldr r3, [r7] */
/* @0x17bfb4 add r2, r5, #144 */
/* @0x17bfb8 mov r1, #65280 */
/* @0x17bfbc movt r1, #0xff00 */
/* @0x17bfc0 ldr r7, [r4, r0] */
/* @0x17bfc4 ldr r0, [r7] */
/* @0x17bfc8 rsb r0, r3, r0 */
/* @0x17bfcc bl 0x17bdf4 <_ZN12GraphicsPerf12AddMemoryBarEijPv> */
/* @0x17bfd0 ldr r0, [pc, #0x54] */
/* @0x17bfd4 ldr r3, [r7] */
/* @0x17bfd8 add r2, r5, #288 */
/* @0x17bfdc mvn r1, #255 */
/* @0x17bfe0 ldr r4, [r4, r0] */
/* @0x17bfe4 ldr r0, [r4] */
/* @0x17bfe8 rsb r0, r3, r0 */
/* @0x17bfec bl 0x17bdf4 <_ZN12GraphicsPerf12AddMemoryBarEijPv> */
/* @0x17bff0 ldr r3, [r4] */
/* @0x17bff4 ldr r0, [r6] */
/* @0x17bff8 add r2, r5, #432 */
/* @0x17bffc movw r1, #0x8080 */
/* @0x17c000 movt r1, #0xff80 */
/* @0x17c004 rsb r0, r3, r0 */
/* @0x17c008 pop {r3, r4, r5, r6, r7, lr} */
/* @0x17c00c b 0x17bdf4 <_ZN12GraphicsPerf12AddMemoryBarEijPv> */
/* @0x17c010 eoreq r5, r7, r8, lsr #26 */
/* @0x17c014 .word 0xffffe788 */
/* @0x17c018 .word 0xffffe77c */
/* @0x17c01c .word 0xffffe784 */
/* @0x17c020 .word 0xffffe780 */
/* @0x17c024 .word 0xffffe78c */
/* @0x17c028 .word 0xffffe790 */
/* @0x17c02c .word 0xffffe794 */

/* ── FUNC 0x17c030 · GraphicsPerf::Print(float, float, float, float, unsigned int, char*, int) · size=552 · insn=138 */
/* @0x17c030 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x17c034 vpush {d8, d9} */
/* @0x17c038 vmov s19, r0 */
/* @0x17c03c ldr r4, [sp, #0x34] */
/* @0x17c040 vmov s16, r1 */
/* @0x17c044 vmov s17, r2 */
/* @0x17c048 ldr r7, [sp, #0x38] */
/* @0x17c04c vmov s18, r3 */
/* @0x17c050 ldr r5, [sp, #0x30] */
/* @0x17c054 mov r0, r4 */
/* @0x17c058 movw r6, #0x3333 */
/* @0x17c05c bl 0xb6538 <strlen@plt> */
/* @0x17c060 ldr r3, [pc, #0x1e8] */
/* @0x17c064 mov r2, #24 */
/* @0x17c068 movt r6, #0x3f33 */
/* @0x17c06c ldr r3, [pc, r3] */
/* @0x17c070 ldr r1, [r3] */
/* @0x17c074 cmp r0, r7 */
/* @0x17c078 movlt r3, r0 */
/* @0x17c07c movge r3, r7 */
/* @0x17c080 mov r0, #4 */
/* @0x17c084 add r3, r3, r3, lsl #1 */
/* @0x17c088 lsl r3, r3, #1 */
/* @0x17c08c bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x17c090 vcvt.s32.f32 s12, s16 */
/* @0x17c094 mov r12, #0 */
/* @0x17c098 vldr s8, [pc, #412] */
/* @0x17c09c mov r9, r12 */
/* @0x17c0a0 vldr s9, [pc, #408] */
/* @0x17c0a4 vldr s5, [pc, #408] */
/* @0x17c0a8 vldr s6, [pc, #408] */
/* @0x17c0ac vldr s7, [pc, #408] */
/* @0x17c0b0 vcvt.s32.f32 s15, s19 */
/* @0x17c0b4 vcvt.f32.s32 s12, s12 */
/* @0x17c0b8 vcvt.f32.s32 s16, s15 */
/* @0x17c0bc b 0x17c1d4 <_ZN12GraphicsPerf5PrintEffffjPci+0x1a4> */
/* @0x17c0c0 cmp r2, #104 */
/* @0x17c0c4 ldr r1, [pc, r1] */
/* @0x17c0c8 add r3, r1, r2, lsl #2 */
/* @0x17c0cc movgt r12, #0 */
/* @0x17c0d0 movle r12, #1 */
/* @0x17c0d4 cmp r2, #0 */
/* @0x17c0d8 moveq r12, #0 */
/* @0x17c0dc cmp r12, #0 */
/* @0x17c0e0 ldrb r12, [r3, #0x2] */
/* @0x17c0e4 addeq r9, r9, #6 */
/* @0x17c0e8 vmov s13, r12 */
/* @0x17c0ec vcvt.f32.u32 s13, s13 */
/* @0x17c0f0 vmul.f32 s11, s13, s17 */
/* @0x17c0f4 vaddeq.f32 s16, s16, s11 */
/* @0x17c0f8 beq 0x17c1d0 <_ZN12GraphicsPerf5PrintEffffjPci+0x1a0> */
/* @0x17c0fc ldrb r1, [r1, r2, lsl #2] */
/* @0x17c100 add r0, r0, #144 */
/* @0x17c104 ldrb r2, [r3, #0x1] */
/* @0x17c108 ldrb r3, [r3, #0x3] */
/* @0x17c10c vstr s16, [r0, #-144] */
/* @0x17c110 vmov s14, r1 */
/* @0x17c114 vstr s16, [r0, #-48] */
/* @0x17c118 vmov s15, r2 */
/* @0x17c11c vstr s16, [r0, #-24] */
/* @0x17c120 vmov s10, r3 */
/* @0x17c124 vstr s12, [r0, #-140] */
/* @0x17c128 vstr s12, [r0, #-116] */
/* @0x17c12c vstr s12, [r0, #-20] */
/* @0x17c130 str r6, [r0, #-0x10] */
/* @0x17c134 vcvt.f32.u32 s14, s14 */
/* @0x17c138 str r6, [r0, #-0x28] */
/* @0x17c13c str r6, [r0, #-0x40] */
/* @0x17c140 str r6, [r0, #-0x58] */
/* @0x17c144 str r6, [r0, #-0x70] */
/* @0x17c148 str r6, [r0, #-0x88] */
/* @0x17c14c vmul.f32 s14, s14, s8 */
/* @0x17c150 vstr s14, [r0, #-128] */
/* @0x17c154 vstr s14, [r0, #-32] */
/* @0x17c158 vstr s14, [r0, #-8] */
/* @0x17c15c vmla.f32 s14, s13, s8 */
/* @0x17c160 vcvt.f32.u32 s15, s15 */
/* @0x17c164 vstr s14, [r0, #-104] */
/* @0x17c168 vstr s14, [r0, #-80] */
/* @0x17c16c vstr s14, [r0, #-56] */
/* @0x17c170 vmul.f32 s15, s15, s9 */
/* @0x17c174 vcvt.f32.u32 s10, s10 */
/* @0x17c178 vstr s15, [r0, #-124] */
/* @0x17c17c vstr s15, [r0, #-100] */
/* @0x17c180 vstr s15, [r0, #-4] */
/* @0x17c184 vmov.f32 s14, s12 */
/* @0x17c188 vmla.f32 s15, s10, s9 */
/* @0x17c18c vmla.f32 s14, s10, s18 */
/* @0x17c190 vstr s15, [r0, #-76] */
/* @0x17c194 vstr s15, [r0, #-52] */
/* @0x17c198 vstr s15, [r0, #-28] */
/* @0x17c19c vadd.f32 s16, s16, s11 */
/* @0x17c1a0 vstr s14, [r0, #-92] */
/* @0x17c1a4 vstr s14, [r0, #-68] */
/* @0x17c1a8 vstr s14, [r0, #-44] */
/* @0x17c1ac vstr s16, [r0, #-120] */
/* @0x17c1b0 vstr s16, [r0, #-96] */
/* @0x17c1b4 vstr s16, [r0, #-72] */
/* @0x17c1b8 str r5, [r0, #-0xc] */
/* @0x17c1bc str r5, [r0, #-0x24] */
/* @0x17c1c0 str r5, [r0, #-0x3c] */
/* @0x17c1c4 str r5, [r0, #-0x54] */
/* @0x17c1c8 str r5, [r0, #-0x6c] */
/* @0x17c1cc str r5, [r0, #-0x84] */
/* @0x17c1d0 mov r12, r8 */
/* @0x17c1d4 ldrb r3, [r4], #1 */
/* @0x17c1d8 add r8, r12, #1 */
/* @0x17c1dc ldr r1, [pc, #0x70] */
/* @0x17c1e0 cmp r3, #0 */
/* @0x17c1e4 sub r2, r3, #32 */
/* @0x17c1e8 beq 0x17c218 <_ZN12GraphicsPerf5PrintEffffjPci+0x1e8> */
/* @0x17c1ec cmp r7, r12 */
/* @0x17c1f0 ble 0x17c218 <_ZN12GraphicsPerf5PrintEffffjPci+0x1e8> */
/* @0x17c1f4 cmp r3, #9 */
/* @0x17c1f8 bne 0x17c0c0 <_ZN12GraphicsPerf5PrintEffffjPci+0x90> */
/* @0x17c1fc vadd.f32 s16, s16, s5 */
/* @0x17c200 add r9, r9, #6 */
/* @0x17c204 vmul.f32 s16, s16, s6 */
/* @0x17c208 vcvt.s32.f32 s16, s16 */
/* @0x17c20c vcvt.f32.s32 s16, s16 */
/* @0x17c210 vmul.f32 s16, s16, s7 */
/* @0x17c214 b 0x17c1d0 <_ZN12GraphicsPerf5PrintEffffjPci+0x1a0> */
/* @0x17c218 cmp r9, #0 */
/* @0x17c21c beq 0x17c228 <_ZN12GraphicsPerf5PrintEffffjPci+0x1f8> */
/* @0x17c220 mov r0, r9 */
/* @0x17c224 bl 0x185600 <_ZN8Graphics9FreeVertsEi> */
/* @0x17c228 vsub.f32 s16, s16, s19 */
/* @0x17c22c vcvt.s32.f32 s16, s16 */
/* @0x17c230 vmov r0, s16 */
/* @0x17c234 vpop {d8, d9} */
/* @0x17c238 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x17c23c bllo 0xfe17c244 <b2_toiTime+0xfffffffffda22da0> */
/* @0x17c240 .word 0x3c000000 */
/* @0x17c244 rsbsmi r0, r12, #0 */
/* @0x17c248 stclo p0, c0, [r0], {0} */
/* @0x17c24c addmi r0, r0, #0 */
/* @0x17c250 eoreq r4, r7, r12, lsr #4 */
/* @0x17c254 .word 0x002741d8 */

/* ── FUNC 0x17c258 · GraphicsPerf::printf(float, float, unsigned int, char const*, ...) · size=160 · insn=40 */
/* @0x17c258 str r3, [sp, #-0x4]! */
/* @0x17c25c push {r4, r5, r6, r7, r8, lr} */
/* @0x17c260 sub sp, sp, #2064 */
/* @0x17c264 ldr r4, [pc, #0x88] */
/* @0x17c268 sub sp, sp, #12 */
/* @0x17c26c add r3, sp, #2096 */
/* @0x17c270 add r5, sp, #20 */
/* @0x17c274 ldr r4, [pc, r4] */
/* @0x17c278 ldr lr, [sp, #0x834] */
/* @0x17c27c add r3, r3, #8 */
/* @0x17c280 mov r7, r0 */
/* @0x17c284 ldr r12, [r4] */
/* @0x17c288 mov r8, r2 */
/* @0x17c28c mov r6, r1 */
/* @0x17c290 mov r2, r3 */
/* @0x17c294 mov r1, lr */
/* @0x17c298 mov r0, r5 */
/* @0x17c29c str r3, [sp, #0x10] */
/* @0x17c2a0 str r12, [sp, #0x814] */
/* @0x17c2a4 bl 0xb667c <vsprintf@plt> */
/* @0x17c2a8 mov r2, #1065353216 */
/* @0x17c2ac mvn r12, #-2147483648 */
/* @0x17c2b0 mov r3, r2 */
/* @0x17c2b4 str r8, [sp] */
/* @0x17c2b8 str r5, [sp, #0x4] */
/* @0x17c2bc mov r0, r7 */
/* @0x17c2c0 mov r1, r6 */
/* @0x17c2c4 str r12, [sp, #0x8] */
/* @0x17c2c8 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci> */
/* @0x17c2cc ldr r2, [sp, #0x814] */
/* @0x17c2d0 ldr r3, [r4] */
/* @0x17c2d4 cmp r2, r3 */
/* @0x17c2d8 bne 0x17c2f0 <_ZN12GraphicsPerf6printfEffjPKcz+0x98> */
/* @0x17c2dc add sp, sp, #2064 */
/* @0x17c2e0 add sp, sp, #12 */
/* @0x17c2e4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x17c2e8 add sp, sp, #4 */
/* @0x17c2ec bx lr */
/* @0x17c2f0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x17c2f4 .word 0x002716dc */

/* ── FUNC 0x17c2f8 · GraphicsPerf::oprintf(float, float, unsigned int, unsigned int, char const*, ...) · size=304 · insn=76 */
/* @0x17c2f8 push {r4, r5, r6, r7, r8, lr} */
/* @0x17c2fc vpush {d8, d9, d10} */
/* @0x17c300 sub sp, sp, #2064 */
/* @0x17c304 ldr r5, [pc, #0x118] */
/* @0x17c308 sub sp, sp, #8 */
/* @0x17c30c mov r7, r2 */
/* @0x17c310 vmov s18, r0 */
/* @0x17c314 ldr r5, [pc, r5] */
/* @0x17c318 ldr r12, [sp, #0x848] */
/* @0x17c31c mov r8, r3 */
/* @0x17c320 vmov s17, r1 */
/* @0x17c324 ldr r2, [r5] */
/* @0x17c328 cmp r12, #0 */
/* @0x17c32c moveq r0, r12 */
/* @0x17c330 str r2, [sp, #0x814] */
/* @0x17c334 beq 0x17c400 <_ZN12GraphicsPerf7oprintfEffjjPKcz+0x108> */
/* @0x17c338 vmov.f32 s16, #1.000000e+00 */
/* @0x17c33c add r4, sp, #20 */
/* @0x17c340 add r2, sp, #2112 */
/* @0x17c344 mov r1, r12 */
/* @0x17c348 add r2, r2, #12 */
/* @0x17c34c mov r0, r4 */
/* @0x17c350 str r2, [sp, #0x10] */
/* @0x17c354 bl 0xb667c <vsprintf@plt> */
/* @0x17c358 mvn r6, #-2147483648 */
/* @0x17c35c str r4, [sp, #0x4] */
/* @0x17c360 str r7, [sp] */
/* @0x17c364 str r6, [sp, #0x8] */
/* @0x17c368 vsub.f32 s19, s17, s16 */
/* @0x17c36c vmov r2, s16 */
/* @0x17c370 vmov r3, s16 */
/* @0x17c374 vsub.f32 s21, s18, s16 */
/* @0x17c378 vmov r1, s19 */
/* @0x17c37c vmov r0, s21 */
/* @0x17c380 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci> */
/* @0x17c384 vadd.f32 s20, s18, s16 */
/* @0x17c388 vmov r1, s19 */
/* @0x17c38c vmov r2, s16 */
/* @0x17c390 vmov r3, s16 */
/* @0x17c394 stmib sp, {r4, r6} */
/* @0x17c398 str r7, [sp] */
/* @0x17c39c vmov r0, s20 */
/* @0x17c3a0 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci> */
/* @0x17c3a4 vadd.f32 s19, s17, s16 */
/* @0x17c3a8 vmov r2, s16 */
/* @0x17c3ac vmov r3, s16 */
/* @0x17c3b0 stmib sp, {r4, r6} */
/* @0x17c3b4 str r7, [sp] */
/* @0x17c3b8 vmov r0, s21 */
/* @0x17c3bc vmov r1, s19 */
/* @0x17c3c0 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci> */
/* @0x17c3c4 vmov r1, s19 */
/* @0x17c3c8 vmov r2, s16 */
/* @0x17c3cc vmov r3, s16 */
/* @0x17c3d0 stmib sp, {r4, r6} */
/* @0x17c3d4 str r7, [sp] */
/* @0x17c3d8 vmov r0, s20 */
/* @0x17c3dc bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci> */
/* @0x17c3e0 vmov r2, s16 */
/* @0x17c3e4 stmib sp, {r4, r6} */
/* @0x17c3e8 str r8, [sp] */
/* @0x17c3ec vmov r0, s18 */
/* @0x17c3f0 vmov r1, s17 */
/* @0x17c3f4 vmov r3, s16 */
/* @0x17c3f8 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci> */
/* @0x17c3fc add r0, r0, #2 */
/* @0x17c400 ldr r2, [sp, #0x814] */
/* @0x17c404 ldr r3, [r5] */
/* @0x17c408 cmp r2, r3 */
/* @0x17c40c bne 0x17c420 <_ZN12GraphicsPerf7oprintfEffjjPKcz+0x128> */
/* @0x17c410 add sp, sp, #2064 */
/* @0x17c414 add sp, sp, #8 */
/* @0x17c418 vpop {d8, d9, d10} */
/* @0x17c41c pop {r4, r5, r6, r7, r8, pc} */
/* @0x17c420 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x17c424 eoreq r1, r7, r12, lsr r6 */

/* ── FUNC 0x17c428 · GraphicsPerf::DisplayFPS(float) · size=116 · insn=29 */
/* @0x17c428 str lr, [sp, #-0x4]! */
/* @0x17c42c vpush {d8} */
/* @0x17c430 vmov s16, r0 */
/* @0x17c434 sub sp, sp, #20 */
/* @0x17c438 bl 0x17bbfc <_ZN12GraphicsPerf16BuildPerfDisplayEv> */
/* @0x17c43c vcvt.s32.f32 s16, s16 */
/* @0x17c440 ldr r12, [pc, #0x48] */
/* @0x17c444 mov r0, #0 */
/* @0x17c448 ldr lr, [pc, #0x44] */
/* @0x17c44c mov r2, #-16777216 */
/* @0x17c450 ldr r12, [pc, r12] */
/* @0x17c454 ldr r1, [pc, #0x3c] */
/* @0x17c458 add lr, pc, lr */
/* @0x17c45c str lr, [sp] */
/* @0x17c460 ldr r1, [pc, r1] */
/* @0x17c464 mvn r3, #0 */
/* @0x17c468 vstr s16, [sp, #4] */
/* @0x17c46c ldr r12, [r12] */
/* @0x17c470 str r12, [sp, #0x8] */
/* @0x17c474 ldr r1, [r1] */
/* @0x17c478 str r1, [sp, #0xc] */
/* @0x17c47c mov r1, r0 */
/* @0x17c480 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz> */
/* @0x17c484 add sp, sp, #20 */
/* @0x17c488 vpop {d8} */
/* @0x17c48c ldr pc, [sp], #4 */
/* @0x17c490 eoreq r3, r7, r0, asr #30 */
/* @0x17c494 andseq pc, r12, r8, lsr #3 */
/* @0x17c498 eoreq r3, r7, r4, lsr pc */

/* ── FUNC 0x17c49c · GraphicsPerf::strwidth(char const*, int) · size=108 · insn=27 */
/* @0x17c49c str r4, [sp, #-0x4]! */
/* @0x17c4a0 ldrb r3, [r0] */
/* @0x17c4a4 cmp r3, #0 */
/* @0x17c4a8 beq 0x17c4f4 <_ZN12GraphicsPerf8strwidthEPKci+0x58> */
/* @0x17c4ac cmp r1, #0 */
/* @0x17c4b0 ble 0x17c4fc <_ZN12GraphicsPerf8strwidthEPKci+0x60> */
/* @0x17c4b4 ldr r4, [pc, #0x48] */
/* @0x17c4b8 mov r2, r0 */
/* @0x17c4bc add r1, r0, r1 */
/* @0x17c4c0 mov r0, #0 */
/* @0x17c4c4 ldr r4, [pc, r4] */
/* @0x17c4c8 b 0x17c4d4 <_ZN12GraphicsPerf8strwidthEPKci+0x38> */
/* @0x17c4cc cmp r2, r1 */
/* @0x17c4d0 beq 0x17c4ec <_ZN12GraphicsPerf8strwidthEPKci+0x50> */
/* @0x17c4d4 add r12, r4, r3, lsl #2 */
/* @0x17c4d8 ldrb r3, [r2, #0x1]! */
/* @0x17c4dc ldrb r12, [r12, #-0x7e] */
/* @0x17c4e0 cmp r3, #0 */
/* @0x17c4e4 add r0, r0, r12 */
/* @0x17c4e8 bne 0x17c4cc <_ZN12GraphicsPerf8strwidthEPKci+0x30> */
/* @0x17c4ec ldr r4, [sp], #4 */
/* @0x17c4f0 bx lr */
/* @0x17c4f4 mov r0, r3 */
/* @0x17c4f8 b 0x17c4ec <_ZN12GraphicsPerf8strwidthEPKci+0x50> */
/* @0x17c4fc mov r0, #0 */
/* @0x17c500 b 0x17c4ec <_ZN12GraphicsPerf8strwidthEPKci+0x50> */
/* @0x17c504 .word 0x00273dd8 */

/* ── FUNC 0x17c508 · GraphicsPerf::cprintf(float, float, unsigned int, char const*, ...) · size=208 · insn=52 */
/* @0x17c508 str r3, [sp, #-0x4]! */
/* @0x17c50c push {r4, r5, r6, r7, lr} */
/* @0x17c510 vpush {d8} */
/* @0x17c514 sub sp, sp, #2064 */
/* @0x17c518 ldr r4, [pc, #0xb4] */
/* @0x17c51c sub sp, sp, #8 */
/* @0x17c520 add r3, sp, #2096 */
/* @0x17c524 add r5, sp, #20 */
/* @0x17c528 ldr r4, [pc, r4] */
/* @0x17c52c ldr lr, [sp, #0x834] */
/* @0x17c530 add r3, r3, #8 */
/* @0x17c534 mov r6, r0 */
/* @0x17c538 ldr r12, [r4] */
/* @0x17c53c mov r7, r2 */
/* @0x17c540 vmov s16, r1 */
/* @0x17c544 mov r2, r3 */
/* @0x17c548 mov r1, lr */
/* @0x17c54c mov r0, r5 */
/* @0x17c550 str r3, [sp, #0x10] */
/* @0x17c554 str r12, [sp, #0x814] */
/* @0x17c558 bl 0xb667c <vsprintf@plt> */
/* @0x17c55c mvn r1, #-2147483648 */
/* @0x17c560 mov r0, r5 */
/* @0x17c564 bl 0x17c49c <_ZN12GraphicsPerf8strwidthEPKci> */
/* @0x17c568 vmov.f32 s15, #1.000000e+00 */
/* @0x17c56c mvn r3, #-2147483648 */
/* @0x17c570 str r7, [sp] */
/* @0x17c574 str r3, [sp, #0x8] */
/* @0x17c578 mov r1, r6 */
/* @0x17c57c str r5, [sp, #0x4] */
/* @0x17c580 vadd.f32 s16, s16, s15 */
/* @0x17c584 vmov r2, s15 */
/* @0x17c588 vmov.f32 s15, #5.000000e-01 */
/* @0x17c58c mov r3, r2 */
/* @0x17c590 vmov s13, r0 */
/* @0x17c594 vcvt.f32.s32 s14, s13 */
/* @0x17c598 vsub.f32 s16, s16, s14 */
/* @0x17c59c vmul.f32 s15, s16, s15 */
/* @0x17c5a0 vmov r0, s15 */
/* @0x17c5a4 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci> */
/* @0x17c5a8 ldr r2, [sp, #0x814] */
/* @0x17c5ac ldr r3, [r4] */
/* @0x17c5b0 cmp r2, r3 */
/* @0x17c5b4 bne 0x17c5d0 <_ZN12GraphicsPerf7cprintfEffjPKcz+0xc8> */
/* @0x17c5b8 add sp, sp, #2064 */
/* @0x17c5bc add sp, sp, #8 */
/* @0x17c5c0 vpop {d8} */
/* @0x17c5c4 pop {r4, r5, r6, r7, lr} */
/* @0x17c5c8 add sp, sp, #4 */
/* @0x17c5cc bx lr */
/* @0x17c5d0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x17c5d4 eoreq r1, r7, r8, lsr #8 */

/* ── FUNC 0x17c5d8 · GraphicsPerf::DisplayVersionInfo() · size=528 · insn=132 */
/* @0x17c5d8 push {r4, lr} */
/* @0x17c5dc vpush {d8} */
/* @0x17c5e0 sub sp, sp, #24 */
/* @0x17c5e4 bl 0x179988 <_Z26GR_Window_Get_Region_Widthv> */
/* @0x17c5e8 ldr r4, [pc, #0x1bc] */
/* @0x17c5ec mov r2, #-1073741824 */
/* @0x17c5f0 mov r3, #0 */
/* @0x17c5f4 str r2, [sp] */
/* @0x17c5f8 movt r3, #0x42c8 */
/* @0x17c5fc add r4, pc, r4 */
/* @0x17c600 vmov s15, r0 */
/* @0x17c604 mov r0, #0 */
/* @0x17c608 mov r1, r0 */
/* @0x17c60c vcvt.f32.s32 s16, s15 */
/* @0x17c610 vmov r2, s16 */
/* @0x17c614 bl 0x17b83c <_ZN12GraphicsPerf15RenderRectangleEffffj> */
/* @0x17c618 ldr r3, [pc, #0x190] */
/* @0x17c61c ldr r2, [pc, #0x190] */
/* @0x17c620 mov lr, #1 */
/* @0x17c624 mov r12, #0 */
/* @0x17c628 movw r0, #0x70c */
/* @0x17c62c ldr r3, [r4, r3] */
/* @0x17c630 add r2, pc, r2 */
/* @0x17c634 str lr, [sp] */
/* @0x17c638 str r2, [sp, #0xc] */
/* @0x17c63c mvn r2, #0 */
/* @0x17c640 ldr r3, [r3] */
/* @0x17c644 vmov r1, s16 */
/* @0x17c648 cmp r3, r12 */
/* @0x17c64c str r0, [sp, #0x8] */
/* @0x17c650 str r12, [sp, #0x4] */
/* @0x17c654 mov r0, #0 */
/* @0x17c658 movne r3, #42 */
/* @0x17c65c moveq r3, #32 */
/* @0x17c660 str r3, [sp, #0x10] */
/* @0x17c664 movt r0, #0x4220 */
/* @0x17c668 ldr r3, [pc, #0x148] */
/* @0x17c66c add r3, pc, r3 */
/* @0x17c670 bl 0x17c508 <_ZN12GraphicsPerf7cprintfEffjPKcz> */
/* @0x17c674 ldr r3, [pc, #0x140] */
/* @0x17c678 ldr r3, [r4, r3] */
/* @0x17c67c ldr r3, [r3] */
/* @0x17c680 cmp r3, #0 */
/* @0x17c684 beq 0x17c6d8 <_ZN12GraphicsPerf18DisplayVersionInfoEv+0x100> */
/* @0x17c688 ldr r3, [r3, #0x4] */
/* @0x17c68c cmp r3, #0 */
/* @0x17c690 moveq r1, r3 */
/* @0x17c694 bne 0x17c774 <_ZN12GraphicsPerf18DisplayVersionInfoEv+0x19c> */
/* @0x17c698 ldr r3, [pc, #0x120] */
/* @0x17c69c mov r0, #0 */
/* @0x17c6a0 str r1, [sp] */
/* @0x17c6a4 mvn r2, #0 */
/* @0x17c6a8 ldr r12, [pc, #0x114] */
/* @0x17c6ac movt r0, #0x4258 */
/* @0x17c6b0 ldr r3, [r4, r3] */
/* @0x17c6b4 vmov r1, s16 */
/* @0x17c6b8 ldr lr, [r3] */
/* @0x17c6bc ldr r3, [pc, #0x104] */
/* @0x17c6c0 str lr, [sp, #0x4] */
/* @0x17c6c4 add r3, pc, r3 */
/* @0x17c6c8 ldr r12, [r4, r12] */
/* @0x17c6cc ldr r12, [r12] */
/* @0x17c6d0 str r12, [sp, #0x8] */
/* @0x17c6d4 bl 0x17c508 <_ZN12GraphicsPerf7cprintfEffjPKcz> */
/* @0x17c6d8 bl 0x179988 <_Z26GR_Window_Get_Region_Widthv> */
/* @0x17c6dc ldr r3, [pc, #0xe8] */
/* @0x17c6e0 mov r1, #0 */
/* @0x17c6e4 mvn r2, #0 */
/* @0x17c6e8 add r3, pc, r3 */
/* @0x17c6ec movt r1, #0x42a0 */
/* @0x17c6f0 sub r0, r0, #80 */
/* @0x17c6f4 vmov s15, r0 */
/* @0x17c6f8 vcvt.f32.s32 s15, s15 */
/* @0x17c6fc vmov r0, s15 */
/* @0x17c700 bl 0x17c258 <_ZN12GraphicsPerf6printfEffjPKcz> */
/* @0x17c704 ldr r3, [pc, #0xc4] */
/* @0x17c708 ldr r4, [r4, r3] */
/* @0x17c70c ldr r3, [r4] */
/* @0x17c710 tst r3, #8 */
/* @0x17c714 beq 0x17c794 <_ZN12GraphicsPerf18DisplayVersionInfoEv+0x1bc> */
/* @0x17c718 tst r3, #2 */
/* @0x17c71c bne 0x17c788 <_ZN12GraphicsPerf18DisplayVersionInfoEv+0x1b0> */
/* @0x17c720 ldr r3, [pc, #0xac] */
/* @0x17c724 add r3, pc, r3 */
/* @0x17c728 mov r0, #0 */
/* @0x17c72c movt r0, #0x4120 */
/* @0x17c730 mvn r2, #0 */
/* @0x17c734 mov r1, r0 */
/* @0x17c738 bl 0x17c258 <_ZN12GraphicsPerf6printfEffjPKcz> */
/* @0x17c73c ldr r3, [r4] */
/* @0x17c740 tst r3, #16 */
/* @0x17c744 beq 0x17c7a0 <_ZN12GraphicsPerf18DisplayVersionInfoEv+0x1c8> */
/* @0x17c748 ldr r3, [pc, #0x88] */
/* @0x17c74c add r3, pc, r3 */
/* @0x17c750 mov r0, #0 */
/* @0x17c754 mov r1, #0 */
/* @0x17c758 movt r0, #0x4120 */
/* @0x17c75c movt r1, #0x41f0 */
/* @0x17c760 mvn r2, #0 */
/* @0x17c764 add sp, sp, #24 */
/* @0x17c768 vpop {d8} */
/* @0x17c76c pop {r4, lr} */
/* @0x17c770 b 0x17c258 <_ZN12GraphicsPerf6printfEffjPKcz> */
/* @0x17c774 ldr r2, [pc, #0x60] */
/* @0x17c778 ldr r2, [r4, r2] */
/* @0x17c77c ldr r1, [r2] */
/* @0x17c780 add r1, r1, r3 */
/* @0x17c784 b 0x17c698 <_ZN12GraphicsPerf18DisplayVersionInfoEv+0xc0> */
/* @0x17c788 ldr r3, [pc, #0x50] */
/* @0x17c78c add r3, pc, r3 */
/* @0x17c790 b 0x17c728 <_ZN12GraphicsPerf18DisplayVersionInfoEv+0x150> */
/* @0x17c794 add sp, sp, #24 */
/* @0x17c798 vpop {d8} */
/* @0x17c79c pop {r4, pc} */
/* @0x17c7a0 ldr r3, [pc, #0x3c] */
/* @0x17c7a4 add r3, pc, r3 */
/* @0x17c7a8 b 0x17c750 <_ZN12GraphicsPerf18DisplayVersionInfoEv+0x178> */
/* @0x17c7ac eoreq r5, r7, r4, asr r6 */
/* @0x17c7b0 .word 0xffffe798 */
/* @0x17c7b4 andseq pc, r12, r4, lsr r0 */
/* @0x17c7b8 ldrsbeq lr, [r12], -r4 */
/* @0x17c7bc .word 0xffffe79c */
/* @0x17c7c0 .word 0xffffe7a0 */
/* @0x17c7c4 .word 0xffffe7a4 */
/* @0x17c7c8 andseq lr, r12, r8, lsr #31 */
/* @0x17c7cc mulseq r12, r8, pc */
/* @0x17c7d0 .word 0xffffc7dc */
/* @0x17c7d4 ldrsheq lr, [r12], -r8 */
/* @0x17c7d8 ldrsbeq lr, [r12], -r12 */
/* @0x17c7dc .word 0xffffbcf4 */
/* @0x17c7e0 andseq lr, r12, r4, lsl #29 */
/* @0x17c7e4 mulseq r12, r0, lr */

/* ── FUNC 0x17c7e8 · GraphicsPerf::EndFrame() · size=464 · insn=116 */
/* @0x17c7e8 push {r3, r4, r5, r6, r7, lr} */
/* @0x17c7ec vpush {d8} */
/* @0x17c7f0 ldr r6, [pc, #0x194] */
/* @0x17c7f4 ldr r3, [pc, #0x194] */
/* @0x17c7f8 add r6, pc, r6 */
/* @0x17c7fc ldr r7, [r6, r3] */
/* @0x17c800 ldr r3, [r7] */
/* @0x17c804 cmp r3, #0 */
/* @0x17c808 beq 0x17c980 <_ZN12GraphicsPerf8EndFrameEv+0x198> */
/* @0x17c80c bl 0x17bb10 <_ZN12GraphicsPerf3PopEv> */
/* @0x17c810 ldr r1, [pc, #0x17c] */
/* @0x17c814 ldr r3, [pc, #0x17c] */
/* @0x17c818 mov r0, #0 */
/* @0x17c81c ldr r2, [pc, #0x178] */
/* @0x17c820 vldr s16, [pc, #352] */
/* @0x17c824 ldr r1, [r6, r1] */
/* @0x17c828 str r0, [r1] */
/* @0x17c82c ldr r3, [r6, r3] */
/* @0x17c830 ldr r1, [r6, r2] */
/* @0x17c834 ldrd r4, r5, [r3, #8] */
/* @0x17c838 ldrd r2, r3, [r3] */
/* @0x17c83c ldrd r0, r1, [r1] */
/* @0x17c840 subs r4, r4, r2 */
/* @0x17c844 sbc r5, r5, r3 */
/* @0x17c848 adds r0, r0, r4 */
/* @0x17c84c adc r1, r1, r5 */
/* @0x17c850 bl 0x319398 <__floatdisf> */
/* @0x17c854 mov r1, r5 */
/* @0x17c858 vmov s15, r0 */
/* @0x17c85c mov r0, r4 */
/* @0x17c860 vdiv.f32 s17, s16, s15 */
/* @0x17c864 bl 0x319398 <__floatdisf> */
/* @0x17c868 ldr r3, [pc, #0x130] */
/* @0x17c86c ldr r3, [r6, r3] */
/* @0x17c870 ldr r2, [r3] */
/* @0x17c874 cmp r2, #100 */
/* @0x17c878 vmov s15, r0 */
/* @0x17c87c vdiv.f32 s16, s16, s15 */
/* @0x17c880 ble 0x17c8d0 <_ZN12GraphicsPerf8EndFrameEv+0xe8> */
/* @0x17c884 ldr r1, [pc, #0x118] */
/* @0x17c888 ldr r0, [r6, r1] */
/* @0x17c88c ldr r12, [r0] */
/* @0x17c890 vcvt.s32.f32 s15, s17 */
/* @0x17c894 vmov r1, s15 */
/* @0x17c898 cmp r1, r12 */
/* @0x17c89c strlt r1, [r0] */
/* @0x17c8a0 ldr r0, [pc, #0x100] */
/* @0x17c8a4 ldr r0, [r6, r0] */
/* @0x17c8a8 ldr r12, [r0] */
/* @0x17c8ac cmp r1, r12 */
/* @0x17c8b0 strgt r1, [r0] */
/* @0x17c8b4 ldr r0, [pc, #0xf0] */
/* @0x17c8b8 ldr r0, [r6, r0] */
/* @0x17c8bc ldr r12, [r0] */
/* @0x17c8c0 add r1, r1, r12 */
/* @0x17c8c4 add r1, r1, r1, lsr #31 */
/* @0x17c8c8 asr r1, r1, #1 */
/* @0x17c8cc str r1, [r0] */
/* @0x17c8d0 add r2, r2, #1 */
/* @0x17c8d4 str r2, [r3] */
/* @0x17c8d8 bl 0x17b624 <_ZN12GraphicsPerf11HandleInputEv> */
/* @0x17c8dc bl 0x17b114 <_ZN12GraphicsPerf14BeginDebugDrawEv> */
/* @0x17c8e0 ldr r3, [pc, #0xc8] */
/* @0x17c8e4 ldr r2, [pc, #0xc8] */
/* @0x17c8e8 ldr r2, [r6, r2] */
/* @0x17c8ec vstr s16, [r2] */
/* @0x17c8f0 ldr r4, [r6, r3] */
/* @0x17c8f4 ldr r3, [r4] */
/* @0x17c8f8 tst r3, #2 */
/* @0x17c8fc bne 0x17c970 <_ZN12GraphicsPerf8EndFrameEv+0x188> */
/* @0x17c900 tst r3, #1 */
/* @0x17c904 bne 0x17c964 <_ZN12GraphicsPerf8EndFrameEv+0x17c> */
/* @0x17c908 tst r3, #4 */
/* @0x17c90c bne 0x17c958 <_ZN12GraphicsPerf8EndFrameEv+0x170> */
/* @0x17c910 tst r3, #16 */
/* @0x17c914 bne 0x17c94c <_ZN12GraphicsPerf8EndFrameEv+0x164> */
/* @0x17c918 tst r3, #64 */
/* @0x17c91c bne 0x17c940 <_ZN12GraphicsPerf8EndFrameEv+0x158> */
/* @0x17c920 tst r3, #32 */
/* @0x17c924 beq 0x17c92c <_ZN12GraphicsPerf8EndFrameEv+0x144> */
/* @0x17c928 bl 0x17b8ec <_ZN12GraphicsPerf16DisplayAudioSyncEv> */
/* @0x17c92c bl 0x17b3e4 <_ZN12GraphicsPerf12EndDebugDrawEv> */
/* @0x17c930 vpop {d8} */
/* @0x17c934 mov r3, #0 */
/* @0x17c938 str r3, [r7] */
/* @0x17c93c pop {r3, r4, r5, r6, r7, pc} */
/* @0x17c940 bl 0x17b8e8 <_ZN12GraphicsPerf17DisplayXBGameChatEv> */
/* @0x17c944 ldr r3, [r4] */
/* @0x17c948 b 0x17c920 <_ZN12GraphicsPerf8EndFrameEv+0x138> */
/* @0x17c94c bl 0x17b8e4 <_ZN12GraphicsPerf12DisplayAudioEv> */
/* @0x17c950 ldr r3, [r4] */
/* @0x17c954 b 0x17c918 <_ZN12GraphicsPerf8EndFrameEv+0x130> */
/* @0x17c958 bl 0x17b8e0 <_ZN12GraphicsPerf14DisplayConsoleEv> */
/* @0x17c95c ldr r3, [r4] */
/* @0x17c960 b 0x17c910 <_ZN12GraphicsPerf8EndFrameEv+0x128> */
/* @0x17c964 bl 0x17c5d8 <_ZN12GraphicsPerf18DisplayVersionInfoEv> */
/* @0x17c968 ldr r3, [r4] */
/* @0x17c96c b 0x17c908 <_ZN12GraphicsPerf8EndFrameEv+0x120> */
/* @0x17c970 vmov r0, s17 */
/* @0x17c974 bl 0x17c428 <_ZN12GraphicsPerf10DisplayFPSEf> */
/* @0x17c978 ldr r3, [r4] */
/* @0x17c97c b 0x17c900 <_ZN12GraphicsPerf8EndFrameEv+0x118> */
/* @0x17c980 bl 0x17b9a0 <_ZN12GraphicsPerf10BeginFrameEv> */
/* @0x17c984 b 0x17c80c <_ZN12GraphicsPerf8EndFrameEv+0x24> */
/* @0x17c988 ldmdbmi r4!, {r10, sp} ^ */
/* @0x17c98c eoreq r5, r7, r8, asr r4 */
/* @0x17c990 .word 0xffffe6e0 */
/* @0x17c994 .word 0xffffe6dc */
/* @0x17c998 .word 0xffffe738 */
/* @0x17c99c .word 0xffffe518 */
/* @0x17c9a0 .word 0xffffc1f4 */
/* @0x17c9a4 .word 0xffffe6ec */
/* @0x17c9a8 .word 0xffffe6f0 */
/* @0x17c9ac .word 0xffffe6e8 */
/* @0x17c9b0 .word 0xffffc7dc */
/* @0x17c9b4 .word 0xffffe7a8 */

/* ── FUNC 0x17c9b8 · GraphicsPerf::coprintf(float, unsigned int, unsigned int, char const*, ...) · size=120 · insn=30 */
/* @0x17c9b8 str r3, [sp, #-0x4]! */
/* @0x17c9bc push {r4, r5, r6, r7, lr} */
/* @0x17c9c0 sub sp, sp, #8 */
/* @0x17c9c4 mov r7, r0 */
/* @0x17c9c8 mov r6, r1 */
/* @0x17c9cc ldr r4, [sp, #0x1c] */
/* @0x17c9d0 mvn r1, #-2147483648 */
/* @0x17c9d4 mov r5, r2 */
/* @0x17c9d8 mov r0, r4 */
/* @0x17c9dc bl 0x17c49c <_ZN12GraphicsPerf8strwidthEPKci> */
/* @0x17c9e0 ldr r12, [pc, #0x44] */
/* @0x17c9e4 mov r1, r7 */
/* @0x17c9e8 mov r2, r6 */
/* @0x17c9ec ldr r12, [pc, r12] */
/* @0x17c9f0 mov r3, r5 */
/* @0x17c9f4 ldr r12, [r12] */
/* @0x17c9f8 str r4, [sp] */
/* @0x17c9fc add r12, r12, #1 */
/* @0x17ca00 rsb r0, r0, r12 */
/* @0x17ca04 add r0, r0, r0, lsr #31 */
/* @0x17ca08 asr r0, r0, #1 */
/* @0x17ca0c vmov s15, r0 */
/* @0x17ca10 vcvt.f32.s32 s15, s15 */
/* @0x17ca14 vmov r0, s15 */
/* @0x17ca18 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz> */
/* @0x17ca1c add sp, sp, #8 */
/* @0x17ca20 pop {r4, r5, r6, r7, lr} */
/* @0x17ca24 add sp, sp, #4 */
/* @0x17ca28 bx lr */
/* @0x17ca2c .word 0x002734b0 */

/* ── FUNC 0x17ca30 · GraphicsPerf::oprintf_wrap(int, int, unsigned int, unsigned int, char const*, ...) · size=972 · insn=243 */
/* @0x17ca30 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17ca34 vpush {d8, d9} */
/* @0x17ca38 sub sp, sp, #2096 */
/* @0x17ca3c sub sp, sp, #12 */
/* @0x17ca40 ldr r10, [pc, #0x3a4] */
/* @0x17ca44 mov r8, r1 */
/* @0x17ca48 str r0, [sp, #0x20] */
/* @0x17ca4c add r10, pc, r10 */
/* @0x17ca50 ldr r0, [pc, #0x398] */
/* @0x17ca54 str r10, [sp, #0x14] */
/* @0x17ca58 str r3, [sp, #0x28] */
/* @0x17ca5c str r2, [sp, #0x1c] */
/* @0x17ca60 ldr r0, [r10, r0] */
/* @0x17ca64 ldr r1, [sp, #0x870] */
/* @0x17ca68 ldr r3, [r0] */
/* @0x17ca6c cmp r1, #0 */
/* @0x17ca70 str r0, [sp, #0x2c] */
/* @0x17ca74 str r3, [sp, #0x834] */
/* @0x17ca78 beq 0x17ccc0 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x290> */
/* @0x17ca7c add r3, sp, #2160 */
/* @0x17ca80 add r2, sp, #52 */
/* @0x17ca84 add r3, r3, #4 */
/* @0x17ca88 str r2, [sp, #0x18] */
/* @0x17ca8c add r0, sp, #52 */
/* @0x17ca90 str r3, [sp, #0x30] */
/* @0x17ca94 mov r2, r3 */
/* @0x17ca98 bl 0xb667c <vsprintf@plt> */
/* @0x17ca9c ldr r2, [pc, #0x350] */
/* @0x17caa0 ldrb r3, [sp, #0x34] */
/* @0x17caa4 ldr r2, [r10, r2] */
/* @0x17caa8 cmp r3, #0 */
/* @0x17caac ldr r7, [r2] */
/* @0x17cab0 sub r7, r7, #4 */
/* @0x17cab4 beq 0x17ccc0 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x290> */
/* @0x17cab8 vmov.f32 s19, #1.000000e+00 */
/* @0x17cabc mvn r6, #0 */
/* @0x17cac0 str r8, [sp, #0x10] */
/* @0x17cac4 mov r4, #0 */
/* @0x17cac8 mov r8, r6 */
/* @0x17cacc movw r10, #0x4567 */
/* @0x17cad0 movt r10, #0x8123 */
/* @0x17cad4 str r10, [sp, #0x24] */
/* @0x17cad8 vmov.f32 s18, #2.000000e+00 */
/* @0x17cadc cmp r3, #32 */
/* @0x17cae0 cmpne r3, #10 */
/* @0x17cae4 mov r0, r4 */
/* @0x17cae8 beq 0x17cb78 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x148> */
/* @0x17caec cmp r3, #0 */
/* @0x17caf0 beq 0x17cdd4 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x3a4> */
/* @0x17caf4 cmp r7, #0 */
/* @0x17caf8 blt 0x17cca4 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x274> */
/* @0x17cafc cmp r3, #10 */
/* @0x17cb00 beq 0x17cce8 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x2b8> */
/* @0x17cb04 ldr r9, [pc, #0x2ec] */
/* @0x17cb08 add r1, sp, #52 */
/* @0x17cb0c ldr r10, [sp, #0x14] */
/* @0x17cb10 add r12, r1, r4 */
/* @0x17cb14 mov r2, r4 */
/* @0x17cb18 mov r5, #0 */
/* @0x17cb1c mvn r1, #0 */
/* @0x17cb20 ldr r11, [r10, r9] */
/* @0x17cb24 b 0x17cb58 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x128> */
/* @0x17cb28 add r9, r11, r3, lsl #2 */
/* @0x17cb2c ldrb r3, [r12, #0x1]! */
/* @0x17cb30 add r10, r2, #1 */
/* @0x17cb34 ldrb r9, [r9, #-0x7e] */
/* @0x17cb38 cmp r3, #0 */
/* @0x17cb3c add r5, r5, r9 */
/* @0x17cb40 beq 0x17cd08 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x2d8> */
/* @0x17cb44 cmp r7, r5 */
/* @0x17cb48 blt 0x17ccb0 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x280> */
/* @0x17cb4c cmp r3, #10 */
/* @0x17cb50 beq 0x17ccf0 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x2c0> */
/* @0x17cb54 mov r2, r10 */
/* @0x17cb58 cmp r3, #32 */
/* @0x17cb5c movne r6, r2 */
/* @0x17cb60 bne 0x17cb28 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0xf8> */
/* @0x17cb64 cmp r6, #0 */
/* @0x17cb68 movgt r1, r5 */
/* @0x17cb6c movgt r8, r2 */
/* @0x17cb70 mvngt r6, #0 */
/* @0x17cb74 b 0x17cb28 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0xf8> */
/* @0x17cb78 cmp r3, #0 */
/* @0x17cb7c beq 0x17cba8 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x178> */
/* @0x17cb80 add r12, sp, #52 */
/* @0x17cb84 add r2, r12, r4 */
/* @0x17cb88 ldrb r3, [r2, #0x1]! */
/* @0x17cb8c add r4, r4, #1 */
/* @0x17cb90 cmp r3, #32 */
/* @0x17cb94 cmpne r3, #10 */
/* @0x17cb98 mov r0, r4 */
/* @0x17cb9c bne 0x17caec <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0xbc> */
/* @0x17cba0 cmp r3, #0 */
/* @0x17cba4 bne 0x17cb88 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x158> */
/* @0x17cba8 mvn r2, #0 */
/* @0x17cbac mov r3, r4 */
/* @0x17cbb0 mov r1, r2 */
/* @0x17cbb4 mov r5, #0 */
/* @0x17cbb8 cmp r7, r5 */
/* @0x17cbbc movlt r4, r2 */
/* @0x17cbc0 cmp r5, #0 */
/* @0x17cbc4 beq 0x17ccc0 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x290> */
/* @0x17cbc8 add r12, sp, #2096 */
/* @0x17cbcc add r12, r12, #8 */
/* @0x17cbd0 add r2, r12, r4 */
/* @0x17cbd4 ldrb r2, [r2, #-0x804] */
/* @0x17cbd8 tst r2, #223 */
/* @0x17cbdc beq 0x17cc9c <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x26c> */
/* @0x17cbe0 cmp r2, #10 */
/* @0x17cbe4 movne r5, r1 */
/* @0x17cbe8 movne r9, r8 */
/* @0x17cbec movne r4, r8 */
/* @0x17cbf0 beq 0x17cc9c <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x26c> */
/* @0x17cbf4 ldr r10, [sp, #0x20] */
/* @0x17cbf8 add r1, sp, #52 */
/* @0x17cbfc ldr r12, [sp, #0x24] */
/* @0x17cc00 vldr s15, [sp, #16] */
/* @0x17cc04 add r11, r1, r0 */
/* @0x17cc08 vcvt.f32.s32 s16, s15 */
/* @0x17cc0c cmp r10, r12 */
/* @0x17cc10 rsb r10, r3, r4 */
/* @0x17cc14 rsbeq r3, r5, r7 */
/* @0x17cc18 ldr r12, [sp, #0x1c] */
/* @0x17cc1c vldrne s17, [sp, #32] */
/* @0x17cc20 addeq r3, r3, r3, lsr #31 */
/* @0x17cc24 asreq r3, r3, #1 */
/* @0x17cc28 vmoveq s17, r3 */
/* @0x17cc2c cmp r12, #0 */
/* @0x17cc30 bne 0x17cd14 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x2e4> */
/* @0x17cc34 vcvt.f32.s32 s17, s17 */
/* @0x17cc38 ldr r12, [sp, #0x28] */
/* @0x17cc3c mov r2, #1065353216 */
/* @0x17cc40 mov r3, r2 */
/* @0x17cc44 str r11, [sp, #0x4] */
/* @0x17cc48 str r10, [sp, #0x8] */
/* @0x17cc4c str r12, [sp] */
/* @0x17cc50 vmov r1, s16 */
/* @0x17cc54 vmov r0, s17 */
/* @0x17cc58 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci> */
/* @0x17cc5c ldr r3, [pc, #0x194] */
/* @0x17cc60 ldr r10, [sp, #0x14] */
/* @0x17cc64 add r1, sp, #2096 */
/* @0x17cc68 add r1, r1, #8 */
/* @0x17cc6c ldr r12, [sp, #0x10] */
/* @0x17cc70 add r9, r1, r9 */
/* @0x17cc74 ldr r11, [r10, r3] */
/* @0x17cc78 ldrb r3, [r9, #-0x804] */
/* @0x17cc7c ldrb r2, [r11, #0x83] */
/* @0x17cc80 cmp r3, #0 */
/* @0x17cc84 add r2, r2, #2 */
/* @0x17cc88 add r12, r12, r2 */
/* @0x17cc8c str r12, [sp, #0x10] */
/* @0x17cc90 bne 0x17cadc <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0xac> */
/* @0x17cc94 mov r0, r5 */
/* @0x17cc98 b 0x17ccc4 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x294> */
/* @0x17cc9c mov r9, r4 */
/* @0x17cca0 b 0x17cbf4 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x1c4> */
/* @0x17cca4 mvn r2, #0 */
/* @0x17cca8 mov r5, #0 */
/* @0x17ccac mov r1, r2 */
/* @0x17ccb0 cmp r5, #0 */
/* @0x17ccb4 mov r3, r4 */
/* @0x17ccb8 mov r4, r2 */
/* @0x17ccbc bne 0x17cbc8 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x198> */
/* @0x17ccc0 mov r0, #0 */
/* @0x17ccc4 ldr r10, [sp, #0x2c] */
/* @0x17ccc8 ldr r2, [sp, #0x834] */
/* @0x17cccc ldr r3, [r10] */
/* @0x17ccd0 cmp r2, r3 */
/* @0x17ccd4 bne 0x17cde8 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x3b8> */
/* @0x17ccd8 add sp, sp, #2096 */
/* @0x17ccdc add sp, sp, #12 */
/* @0x17cce0 vpop {d8, d9} */
/* @0x17cce4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17cce8 mov r10, r4 */
/* @0x17ccec mov r5, #0 */
/* @0x17ccf0 mov r3, r4 */
/* @0x17ccf4 mov r8, r10 */
/* @0x17ccf8 mov r4, r10 */
/* @0x17ccfc mov r1, r5 */
/* @0x17cd00 mvn r6, #0 */
/* @0x17cd04 b 0x17cbc0 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x190> */
/* @0x17cd08 mov r3, r4 */
/* @0x17cd0c mov r4, r10 */
/* @0x17cd10 b 0x17cbb8 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x188> */
/* @0x17cd14 vmov r1, s17 */
/* @0x17cd18 mov r2, #1065353216 */
/* @0x17cd1c ldr r12, [sp, #0x1c] */
/* @0x17cd20 mov r3, r2 */
/* @0x17cd24 str r11, [sp, #0x4] */
/* @0x17cd28 str r10, [sp, #0x8] */
/* @0x17cd2c str r12, [sp] */
/* @0x17cd30 sub r0, r1, #1 */
/* @0x17cd34 vmov r1, s16 */
/* @0x17cd38 vmov s15, r0 */
/* @0x17cd3c vcvt.f32.s32 s15, s15 */
/* @0x17cd40 vmov r0, s15 */
/* @0x17cd44 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci> */
/* @0x17cd48 vmov r1, s17 */
/* @0x17cd4c ldr r12, [sp, #0x1c] */
/* @0x17cd50 mov r2, #1065353216 */
/* @0x17cd54 mov r3, r2 */
/* @0x17cd58 str r11, [sp, #0x4] */
/* @0x17cd5c str r10, [sp, #0x8] */
/* @0x17cd60 str r12, [sp] */
/* @0x17cd64 add r0, r1, #1 */
/* @0x17cd68 vmov r1, s16 */
/* @0x17cd6c vmov s15, r0 */
/* @0x17cd70 vcvt.f32.s32 s15, s15 */
/* @0x17cd74 vmov r0, s15 */
/* @0x17cd78 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci> */
/* @0x17cd7c vsub.f32 s15, s16, s19 */
/* @0x17cd80 ldr r12, [sp, #0x1c] */
/* @0x17cd84 mov r2, #1065353216 */
/* @0x17cd88 mov r3, r2 */
/* @0x17cd8c str r11, [sp, #0x4] */
/* @0x17cd90 str r10, [sp, #0x8] */
/* @0x17cd94 str r12, [sp] */
/* @0x17cd98 vcvt.f32.s32 s17, s17 */
/* @0x17cd9c vmov r1, s15 */
/* @0x17cda0 vmov r0, s17 */
/* @0x17cda4 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci> */
/* @0x17cda8 vadd.f32 s15, s16, s18 */
/* @0x17cdac ldr r12, [sp, #0x1c] */
/* @0x17cdb0 mov r2, #1065353216 */
/* @0x17cdb4 str r11, [sp, #0x4] */
/* @0x17cdb8 mov r3, r2 */
/* @0x17cdbc str r10, [sp, #0x8] */
/* @0x17cdc0 str r12, [sp] */
/* @0x17cdc4 vmov r0, s17 */
/* @0x17cdc8 vmov r1, s15 */
/* @0x17cdcc bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci> */
/* @0x17cdd0 b 0x17cc38 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x208> */
/* @0x17cdd4 mvn r2, #0 */
/* @0x17cdd8 mov r5, r3 */
/* @0x17cddc mov r1, r2 */
/* @0x17cde0 mov r3, r4 */
/* @0x17cde4 b 0x17cbb8 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x188> */
/* @0x17cde8 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x17cdec eoreq r5, r7, r4, lsl #4 */
/* @0x17cdf0 .word 0xffffbd00 */
/* @0x17cdf4 .word 0xffffe24c */
/* @0x17cdf8 .word 0xffffe64c */

/* ── FUNC 0x17cdfc · GraphicsPerf::oprintf_wrap_decode(int, int, unsigned int, unsigned int, char const*, ...) · size=1076 · insn=269 */
/* @0x17cdfc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17ce00 vpush {d8, d9} */
/* @0x17ce04 sub sp, sp, #4096 */
/* @0x17ce08 ldr r10, [pc, #0x40c] */
/* @0x17ce0c sub sp, sp, #60 */
/* @0x17ce10 ldr r12, [pc, #0x408] */
/* @0x17ce14 add r10, pc, r10 */
/* @0x17ce18 str r0, [sp, #0x20] */
/* @0x17ce1c str r10, [sp, #0x14] */
/* @0x17ce20 str r1, [sp, #0x18] */
/* @0x17ce24 add r1, sp, #8192 */
/* @0x17ce28 str r3, [sp, #0x28] */
/* @0x17ce2c str r2, [sp, #0x1c] */
/* @0x17ce30 ldr r12, [r10, r12] */
/* @0x17ce34 ldr r0, [r1, #-0xf90] */
/* @0x17ce38 ldr r3, [r12] */
/* @0x17ce3c cmp r0, #0 */
/* @0x17ce40 str r12, [sp, #0x2c] */
/* @0x17ce44 str r3, [r1, #-0xfcc] */
/* @0x17ce48 beq 0x17d0e0 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x2e4> */
/* @0x17ce4c ldrb r3, [r0] */
/* @0x17ce50 add lr, sp, #56 */
/* @0x17ce54 cmp r3, #0 */
/* @0x17ce58 beq 0x17d210 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x414> */
/* @0x17ce5c sub r8, lr, #4 */
/* @0x17ce60 mov r1, #0 */
/* @0x17ce64 add r2, r8, #2032 */
/* @0x17ce68 add r2, r2, #15 */
/* @0x17ce6c eor r12, r3, #26 */
/* @0x17ce70 ldrb r3, [r0, #0x1]! */
/* @0x17ce74 strb r12, [r2, #0x1]! */
/* @0x17ce78 add r1, r1, #1 */
/* @0x17ce7c cmp r3, #0 */
/* @0x17ce80 bne 0x17ce6c <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x70> */
/* @0x17ce84 add r1, r1, #2048 */
/* @0x17ce88 add r12, sp, #4160 */
/* @0x17ce8c add r10, sp, #4096 */
/* @0x17ce90 add r12, r12, #52 */
/* @0x17ce94 mov r4, #0 */
/* @0x17ce98 movw r3, #0xeff8 */
/* @0x17ce9c strb r4, [r8, r1] */
/* @0x17cea0 movt r3, #0xffff */
/* @0x17cea4 sub r8, lr, #4 */
/* @0x17cea8 add r10, r10, #56 */
/* @0x17ceac mov r2, r12 */
/* @0x17ceb0 mov r0, r8 */
/* @0x17ceb4 add r1, r8, #2048 */
/* @0x17ceb8 str r12, [r10, r3] */
/* @0x17cebc bl 0xb667c <vsprintf@plt> */
/* @0x17cec0 ldr r2, [pc, #0x35c] */
/* @0x17cec4 ldr r12, [sp, #0x14] */
/* @0x17cec8 add r0, sp, #4096 */
/* @0x17cecc movw r3, #0xeffc */
/* @0x17ced0 add r0, r0, #56 */
/* @0x17ced4 movt r3, #0xffff */
/* @0x17ced8 ldr r2, [r12, r2] */
/* @0x17cedc ldrb r3, [r0, r3] */
/* @0x17cee0 ldr r7, [r2] */
/* @0x17cee4 cmp r3, r4 */
/* @0x17cee8 sub r7, r7, #4 */
/* @0x17ceec beq 0x17d0e0 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x2e4> */
/* @0x17cef0 vmov.f32 s19, #1.000000e+00 */
/* @0x17cef4 mvn r6, #0 */
/* @0x17cef8 movw r10, #0x4567 */
/* @0x17cefc str r6, [sp, #0x10] */
/* @0x17cf00 movt r10, #0x8123 */
/* @0x17cf04 str r10, [sp, #0x24] */
/* @0x17cf08 vmov.f32 s18, #2.000000e+00 */
/* @0x17cf0c cmp r3, #32 */
/* @0x17cf10 cmpne r3, #10 */
/* @0x17cf14 mov r0, r4 */
/* @0x17cf18 beq 0x17cfa4 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x1a8> */
/* @0x17cf1c cmp r3, #0 */
/* @0x17cf20 beq 0x17d1f8 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x3fc> */
/* @0x17cf24 cmp r7, #0 */
/* @0x17cf28 blt 0x17d0c4 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x2c8> */
/* @0x17cf2c cmp r3, #10 */
/* @0x17cf30 beq 0x17d10c <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x310> */
/* @0x17cf34 ldr r9, [pc, #0x2ec] */
/* @0x17cf38 add r12, r8, r4 */
/* @0x17cf3c ldr r10, [sp, #0x14] */
/* @0x17cf40 mov r2, r4 */
/* @0x17cf44 mov r5, #0 */
/* @0x17cf48 mvn r1, #0 */
/* @0x17cf4c ldr r11, [r10, r9] */
/* @0x17cf50 b 0x17cf84 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x188> */
/* @0x17cf54 add r9, r11, r3, lsl #2 */
/* @0x17cf58 ldrb r3, [r12, #0x1]! */
/* @0x17cf5c add r10, r2, #1 */
/* @0x17cf60 ldrb r9, [r9, #-0x7e] */
/* @0x17cf64 cmp r3, #0 */
/* @0x17cf68 add r5, r5, r9 */
/* @0x17cf6c beq 0x17d12c <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x330> */
/* @0x17cf70 cmp r7, r5 */
/* @0x17cf74 blt 0x17d0d0 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x2d4> */
/* @0x17cf78 cmp r3, #10 */
/* @0x17cf7c beq 0x17d114 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x318> */
/* @0x17cf80 mov r2, r10 */
/* @0x17cf84 cmp r3, #32 */
/* @0x17cf88 movne r6, r2 */
/* @0x17cf8c bne 0x17cf54 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x158> */
/* @0x17cf90 cmp r6, #0 */
/* @0x17cf94 strgt r2, [sp, #0x10] */
/* @0x17cf98 movgt r1, r5 */
/* @0x17cf9c mvngt r6, #0 */
/* @0x17cfa0 b 0x17cf54 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x158> */
/* @0x17cfa4 cmp r3, #0 */
/* @0x17cfa8 beq 0x17cfd0 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x1d4> */
/* @0x17cfac add r2, r8, r4 */
/* @0x17cfb0 ldrb r3, [r2, #0x1]! */
/* @0x17cfb4 add r4, r4, #1 */
/* @0x17cfb8 cmp r3, #32 */
/* @0x17cfbc cmpne r3, #10 */
/* @0x17cfc0 mov r0, r4 */
/* @0x17cfc4 bne 0x17cf1c <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x120> */
/* @0x17cfc8 cmp r3, #0 */
/* @0x17cfcc bne 0x17cfb0 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x1b4> */
/* @0x17cfd0 mvn r2, #0 */
/* @0x17cfd4 mov r3, r4 */
/* @0x17cfd8 mov r1, r2 */
/* @0x17cfdc mov r5, #0 */
/* @0x17cfe0 cmp r7, r5 */
/* @0x17cfe4 movlt r4, r2 */
/* @0x17cfe8 cmp r5, #0 */
/* @0x17cfec beq 0x17d0e0 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x2e4> */
/* @0x17cff0 ldrb r2, [r8, r4] */
/* @0x17cff4 tst r2, #223 */
/* @0x17cff8 beq 0x17d0bc <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x2c0> */
/* @0x17cffc cmp r2, #10 */
/* @0x17d000 beq 0x17d0bc <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x2c0> */
/* @0x17d004 ldr r9, [sp, #0x10] */
/* @0x17d008 mov r5, r1 */
/* @0x17d00c mov r4, r9 */
/* @0x17d010 ldr r12, [sp, #0x20] */
/* @0x17d014 vldr s15, [sp, #24] */
/* @0x17d018 ldr r10, [sp, #0x24] */
/* @0x17d01c add r11, r8, r0 */
/* @0x17d020 vcvt.f32.s32 s16, s15 */
/* @0x17d024 cmp r12, r10 */
/* @0x17d028 rsb r10, r3, r4 */
/* @0x17d02c rsbeq r3, r5, r7 */
/* @0x17d030 ldr r12, [sp, #0x1c] */
/* @0x17d034 vldrne s17, [sp, #32] */
/* @0x17d038 addeq r3, r3, r3, lsr #31 */
/* @0x17d03c asreq r3, r3, #1 */
/* @0x17d040 vmoveq s17, r3 */
/* @0x17d044 cmp r12, #0 */
/* @0x17d048 bne 0x17d138 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x33c> */
/* @0x17d04c vcvt.f32.s32 s17, s17 */
/* @0x17d050 ldr r12, [sp, #0x28] */
/* @0x17d054 mov r2, #1065353216 */
/* @0x17d058 mov r3, r2 */
/* @0x17d05c str r11, [sp, #0x4] */
/* @0x17d060 str r10, [sp, #0x8] */
/* @0x17d064 str r12, [sp] */
/* @0x17d068 vmov r1, s16 */
/* @0x17d06c vmov r0, s17 */
/* @0x17d070 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci> */
/* @0x17d074 ldr r10, [sp, #0x14] */
/* @0x17d078 ldr r2, [pc, #0x1ac] */
/* @0x17d07c ldr r1, [pc, #0x1a4] */
/* @0x17d080 ldrb r3, [r8, r9] */
/* @0x17d084 ldr r2, [r10, r2] */
/* @0x17d088 ldr r12, [sp, #0x18] */
/* @0x17d08c cmp r3, #0 */
/* @0x17d090 ldr r0, [r2] */
/* @0x17d094 add r0, r0, #1 */
/* @0x17d098 str r0, [r2] */
/* @0x17d09c ldr r11, [r10, r1] */
/* @0x17d0a0 ldrb r2, [r11, #0x83] */
/* @0x17d0a4 add r2, r2, #2 */
/* @0x17d0a8 add r12, r12, r2 */
/* @0x17d0ac str r12, [sp, #0x18] */
/* @0x17d0b0 bne 0x17cf0c <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x110> */
/* @0x17d0b4 mov r0, r5 */
/* @0x17d0b8 b 0x17d0e4 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x2e8> */
/* @0x17d0bc mov r9, r4 */
/* @0x17d0c0 b 0x17d010 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x214> */
/* @0x17d0c4 mvn r2, #0 */
/* @0x17d0c8 mov r5, #0 */
/* @0x17d0cc mov r1, r2 */
/* @0x17d0d0 cmp r5, #0 */
/* @0x17d0d4 mov r3, r4 */
/* @0x17d0d8 mov r4, r2 */
/* @0x17d0dc bne 0x17cff0 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x1f4> */
/* @0x17d0e0 mov r0, #0 */
/* @0x17d0e4 ldr r10, [sp, #0x2c] */
/* @0x17d0e8 add r1, sp, #8192 */
/* @0x17d0ec ldr r2, [r1, #-0xfcc] */
/* @0x17d0f0 ldr r3, [r10] */
/* @0x17d0f4 cmp r2, r3 */
/* @0x17d0f8 bne 0x17d20c <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x410> */
/* @0x17d0fc add sp, sp, #4096 */
/* @0x17d100 add sp, sp, #60 */
/* @0x17d104 vpop {d8, d9} */
/* @0x17d108 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17d10c mov r10, r4 */
/* @0x17d110 mov r5, #0 */
/* @0x17d114 mov r3, r4 */
/* @0x17d118 str r10, [sp, #0x10] */
/* @0x17d11c mov r4, r10 */
/* @0x17d120 mov r1, r5 */
/* @0x17d124 mvn r6, #0 */
/* @0x17d128 b 0x17cfe8 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x1ec> */
/* @0x17d12c mov r3, r4 */
/* @0x17d130 mov r4, r10 */
/* @0x17d134 b 0x17cfe0 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x1e4> */
/* @0x17d138 vmov r1, s17 */
/* @0x17d13c mov r2, #1065353216 */
/* @0x17d140 ldr r12, [sp, #0x1c] */
/* @0x17d144 mov r3, r2 */
/* @0x17d148 str r11, [sp, #0x4] */
/* @0x17d14c str r10, [sp, #0x8] */
/* @0x17d150 str r12, [sp] */
/* @0x17d154 sub r0, r1, #1 */
/* @0x17d158 vmov r1, s16 */
/* @0x17d15c vmov s15, r0 */
/* @0x17d160 vcvt.f32.s32 s15, s15 */
/* @0x17d164 vmov r0, s15 */
/* @0x17d168 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci> */
/* @0x17d16c vmov r1, s17 */
/* @0x17d170 ldr r12, [sp, #0x1c] */
/* @0x17d174 mov r2, #1065353216 */
/* @0x17d178 mov r3, r2 */
/* @0x17d17c str r11, [sp, #0x4] */
/* @0x17d180 str r10, [sp, #0x8] */
/* @0x17d184 str r12, [sp] */
/* @0x17d188 add r0, r1, #1 */
/* @0x17d18c vmov r1, s16 */
/* @0x17d190 vmov s15, r0 */
/* @0x17d194 vcvt.f32.s32 s15, s15 */
/* @0x17d198 vmov r0, s15 */
/* @0x17d19c bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci> */
/* @0x17d1a0 vsub.f32 s15, s16, s19 */
/* @0x17d1a4 ldr r12, [sp, #0x1c] */
/* @0x17d1a8 mov r2, #1065353216 */
/* @0x17d1ac mov r3, r2 */
/* @0x17d1b0 str r11, [sp, #0x4] */
/* @0x17d1b4 str r10, [sp, #0x8] */
/* @0x17d1b8 str r12, [sp] */
/* @0x17d1bc vcvt.f32.s32 s17, s17 */
/* @0x17d1c0 vmov r1, s15 */
/* @0x17d1c4 vmov r0, s17 */
/* @0x17d1c8 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci> */
/* @0x17d1cc vadd.f32 s15, s16, s18 */
/* @0x17d1d0 ldr r12, [sp, #0x1c] */
/* @0x17d1d4 mov r2, #1065353216 */
/* @0x17d1d8 str r11, [sp, #0x4] */
/* @0x17d1dc mov r3, r2 */
/* @0x17d1e0 str r10, [sp, #0x8] */
/* @0x17d1e4 str r12, [sp] */
/* @0x17d1e8 vmov r0, s17 */
/* @0x17d1ec vmov r1, s15 */
/* @0x17d1f0 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci> */
/* @0x17d1f4 b 0x17d050 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x254> */
/* @0x17d1f8 mvn r2, #0 */
/* @0x17d1fc mov r5, r3 */
/* @0x17d200 mov r1, r2 */
/* @0x17d204 mov r3, r4 */
/* @0x17d208 b 0x17cfe0 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x1e4> */
/* @0x17d20c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x17d210 add r8, sp, #52 */
/* @0x17d214 mov r1, #2048 */
/* @0x17d218 b 0x17ce88 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x8c> */
/* @0x17d21c eoreq r4, r7, r12, lsr lr */
/* @0x17d220 .word 0xffffbd00 */
/* @0x17d224 .word 0xffffe24c */
/* @0x17d228 .word 0xffffe64c */
/* @0x17d22c .word 0xffffe7ac */

/* ── FUNC 0x17d230 · Graphics::CheckDoFrameFirst() · size=8 · insn=2 */
/* @0x17d230 mov r0, #0 */
/* @0x17d234 bx lr */

/* ── FUNC 0x17d238 · CheckGLVersion(int, int) · size=76 · insn=19 */
/* @0x17d238 ldr r3, [pc, #0x3c] */
/* @0x17d23c ldr r3, [pc, r3] */
/* @0x17d240 ldr r3, [r3] */
/* @0x17d244 cmp r3, r0 */
/* @0x17d248 bgt 0x17d258 <_Z14CheckGLVersionii+0x20> */
/* @0x17d24c beq 0x17d260 <_Z14CheckGLVersionii+0x28> */
/* @0x17d250 mov r0, #0 */
/* @0x17d254 bx lr */
/* @0x17d258 mov r0, #1 */
/* @0x17d25c bx lr */
/* @0x17d260 ldr r3, [pc, #0x18] */
/* @0x17d264 ldr r3, [pc, r3] */
/* @0x17d268 ldr r0, [r3] */
/* @0x17d26c cmp r0, r1 */
/* @0x17d270 movlt r0, #0 */
/* @0x17d274 movge r0, #1 */
/* @0x17d278 bx lr */
/* @0x17d27c eoreq r3, r7, r4, asr #3 */
/* @0x17d280 eoreq r3, r7, r0, lsr #3 */

/* ── FUNC 0x17d284 · AddGraphicsInfo(CDS_Map*) · size=420 · insn=105 */
/* @0x17d284 push {r4, r5, r6, lr} */
/* @0x17d288 subs r5, r0, #0 */
/* @0x17d28c sub sp, sp, #16 */
/* @0x17d290 beq 0x17d39c <_Z15AddGraphicsInfoP7CDS_Map+0x118> */
/* @0x17d294 ldr r4, [pc, #0x160] */
/* @0x17d298 movw r0, #0x1f02 */
/* @0x17d29c ldr r6, [pc, #0x15c] */
/* @0x17d2a0 ldr r4, [pc, r4] */
/* @0x17d2a4 ldr r3, [r4] */
/* @0x17d2a8 blx r3 */
/* @0x17d2ac ldr r1, [pc, #0x150] */
/* @0x17d2b0 mov r2, #0 */
/* @0x17d2b4 mov r3, #0 */
/* @0x17d2b8 add r1, pc, r1 */
/* @0x17d2bc str r0, [sp] */
/* @0x17d2c0 mov r0, r5 */
/* @0x17d2c4 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0x17d2c8 ldr r3, [r4] */
/* @0x17d2cc mov r0, #7936 */
/* @0x17d2d0 blx r3 */
/* @0x17d2d4 ldr r1, [pc, #0x12c] */
/* @0x17d2d8 mov r2, #0 */
/* @0x17d2dc mov r3, #0 */
/* @0x17d2e0 add r1, pc, r1 */
/* @0x17d2e4 str r0, [sp] */
/* @0x17d2e8 mov r0, r5 */
/* @0x17d2ec bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0x17d2f0 ldr r3, [r4] */
/* @0x17d2f4 movw r0, #0x1f01 */
/* @0x17d2f8 blx r3 */
/* @0x17d2fc ldr r1, [pc, #0x108] */
/* @0x17d300 mov r2, #0 */
/* @0x17d304 mov r3, #0 */
/* @0x17d308 add r1, pc, r1 */
/* @0x17d30c str r0, [sp] */
/* @0x17d310 mov r0, r5 */
/* @0x17d314 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0x17d318 ldr r3, [r4] */
/* @0x17d31c movw r0, #0x1f03 */
/* @0x17d320 blx r3 */
/* @0x17d324 ldr r1, [pc, #0xe4] */
/* @0x17d328 mov r3, #0 */
/* @0x17d32c mov r2, #0 */
/* @0x17d330 add r1, pc, r1 */
/* @0x17d334 str r0, [sp] */
/* @0x17d338 mov r0, r5 */
/* @0x17d33c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0x17d340 ldr r6, [pc, r6] */
/* @0x17d344 ldr r3, [r6] */
/* @0x17d348 cmp r3, #1 */
/* @0x17d34c beq 0x17d3cc <_Z15AddGraphicsInfoP7CDS_Map+0x148> */
/* @0x17d350 cmp r3, #0 */
/* @0x17d354 beq 0x17d3a4 <_Z15AddGraphicsInfoP7CDS_Map+0x120> */
/* @0x17d358 ldr r3, [pc, #0xb4] */
/* @0x17d35c add r1, sp, #16 */
/* @0x17d360 mov r2, #1024 */
/* @0x17d364 movw r0, #0xd33 */
/* @0x17d368 ldr r3, [pc, r3] */
/* @0x17d36c str r2, [r1, #-0x4]! */
/* @0x17d370 ldr r3, [r3] */
/* @0x17d374 blx r3 */
/* @0x17d378 vldr s15, [sp, #12] */
/* @0x17d37c vcvt.f64.s32 d7, s15 */
/* @0x17d380 ldr r1, [pc, #0x90] */
/* @0x17d384 mov r12, #0 */
/* @0x17d388 mov r0, r5 */
/* @0x17d38c add r1, pc, r1 */
/* @0x17d390 str r12, [sp] */
/* @0x17d394 vmov r2, r3, d7 */
/* @0x17d398 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0x17d39c add sp, sp, #16 */
/* @0x17d3a0 pop {r4, r5, r6, pc} */
/* @0x17d3a4 ldr r12, [pc, #0x70] */
/* @0x17d3a8 mov r0, r5 */
/* @0x17d3ac ldr r1, [pc, #0x6c] */
/* @0x17d3b0 mov r2, #0 */
/* @0x17d3b4 add r12, pc, r12 */
/* @0x17d3b8 mov r3, #0 */
/* @0x17d3bc add r1, pc, r1 */
/* @0x17d3c0 str r12, [sp] */
/* @0x17d3c4 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0x17d3c8 b 0x17d358 <_Z15AddGraphicsInfoP7CDS_Map+0xd4> */
/* @0x17d3cc ldr r3, [r4] */
/* @0x17d3d0 movw r0, #0x8b8c */
/* @0x17d3d4 blx r3 */
/* @0x17d3d8 ldr r1, [pc, #0x44] */
/* @0x17d3dc mov r3, #0 */
/* @0x17d3e0 mov r2, #0 */
/* @0x17d3e4 add r1, pc, r1 */
/* @0x17d3e8 str r0, [sp] */
/* @0x17d3ec mov r0, r5 */
/* @0x17d3f0 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0x17d3f4 ldr r3, [r6] */
/* @0x17d3f8 b 0x17d350 <_Z15AddGraphicsInfoP7CDS_Map+0xcc> */
/* @0x17d3fc mlaeq r7, r0, r4, r0 */
/* @0x17d400 eoreq r3, r7, r8, asr #1 */
/* @0x17d404 andseq r12, r12, r8, asr r7 */
/* @0x17d408 andseq r12, r12, r4, ror #14 */
/* @0x17d40c andseq r12, r12, r4, lsr #14 */
/* @0x17d410 andseq lr, r12, r8, asr r3 */
/* @0x17d414 eoreq r0, r7, r0, lsr r4 */
/* @0x17d418 ldrsheq r12, [r12], -r12 */
/* @0x17d41c andseq r5, r11, r8, lsr r1 */
/* @0x17d420 andseq r12, r12, r0, lsr #13 */
/* @0x17d424 andseq r12, r12, r8, ror r6 */

/* ── FUNC 0x17d428 · HasExtension(char*, char*) · size=40 · insn=10 */
/* @0x17d428 cmp r1, #0 */
/* @0x17d42c cmpne r0, #0 */
/* @0x17d430 push {r3, lr} */
/* @0x17d434 beq 0x17d448 <_Z12HasExtensionPcS_+0x20> */
/* @0x17d438 bl 0xb6604 <strstr@plt> */
/* @0x17d43c adds r0, r0, #0 */
/* @0x17d440 movne r0, #1 */
/* @0x17d444 pop {r3, pc} */
/* @0x17d448 mov r0, #0 */
/* @0x17d44c pop {r3, pc} */

/* ── FUNC 0x17d450 · GetOpenGLInfo() · size=1604 · insn=401 */
/* @0x17d450 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17d454 movw r0, #0x1f02 */
/* @0x17d458 ldr r4, [pc, #0x57c] */
/* @0x17d45c sub sp, sp, #12 */
/* @0x17d460 ldr r3, [pc, #0x578] */
/* @0x17d464 add r4, pc, r4 */
/* @0x17d468 ldr r6, [r4, r3] */
/* @0x17d46c ldr r3, [r6] */
/* @0x17d470 blx r3 */
/* @0x17d474 ldr r3, [pc, #0x568] */
/* @0x17d478 ldr r1, [pc, #0x568] */
/* @0x17d47c ldr r3, [r4, r3] */
/* @0x17d480 add r1, pc, r1 */
/* @0x17d484 ldr r5, [r3] */
/* @0x17d488 ldr r3, [r5] */
/* @0x17d48c ldr r3, [r3, #0xc] */
/* @0x17d490 mov r2, r0 */
/* @0x17d494 mov r7, r0 */
/* @0x17d498 mov r0, r5 */
/* @0x17d49c blx r3 */
/* @0x17d4a0 ldr r3, [pc, #0x544] */
/* @0x17d4a4 ldr r9, [r4, r3] */
/* @0x17d4a8 ldr r0, [r9] */
/* @0x17d4ac cmp r0, #0 */
/* @0x17d4b0 beq 0x17d4b8 <_Z13GetOpenGLInfov+0x68> */
/* @0x17d4b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x17d4b8 ldr r2, [r5] */
/* @0x17d4bc mov r0, #7936 */
/* @0x17d4c0 ldr r3, [r6] */
/* @0x17d4c4 ldr r8, [r2, #0xc] */
/* @0x17d4c8 blx r3 */
/* @0x17d4cc ldr r1, [pc, #0x51c] */
/* @0x17d4d0 add r1, pc, r1 */
/* @0x17d4d4 mov r2, r0 */
/* @0x17d4d8 mov r0, r5 */
/* @0x17d4dc blx r8 */
/* @0x17d4e0 ldr r2, [pc, #0x50c] */
/* @0x17d4e4 ldr r3, [pc, #0x50c] */
/* @0x17d4e8 movw r0, #0xd33 */
/* @0x17d4ec ldr r10, [r4, r2] */
/* @0x17d4f0 ldr r1, [r4, r3] */
/* @0x17d4f4 ldr r3, [r10] */
/* @0x17d4f8 blx r3 */
/* @0x17d4fc ldr r3, [pc, #0x4f8] */
/* @0x17d500 ldr r11, [r4, r3] */
/* @0x17d504 ldr r8, [r11] */
/* @0x17d508 cmp r8, #1 */
/* @0x17d50c beq 0x17d884 <_Z13GetOpenGLInfov+0x434> */
/* @0x17d510 cmp r8, #0 */
/* @0x17d514 beq 0x17d83c <_Z13GetOpenGLInfov+0x3ec> */
/* @0x17d518 ldr r1, [pc, #0x4e0] */
/* @0x17d51c mov r0, r7 */
/* @0x17d520 add r1, pc, r1 */
/* @0x17d524 bl 0xb6604 <strstr@plt> */
/* @0x17d528 cmp r0, #0 */
/* @0x17d52c beq 0x17d54c <_Z13GetOpenGLInfov+0xfc> */
/* @0x17d530 ldr r1, [pc, #0x4cc] */
/* @0x17d534 mov r3, #1 */
/* @0x17d538 ldr r2, [pc, #0x4c8] */
/* @0x17d53c ldr r1, [r4, r1] */
/* @0x17d540 str r3, [r1] */
/* @0x17d544 ldr r2, [r4, r2] */
/* @0x17d548 str r3, [r2] */
/* @0x17d54c ldr r1, [pc, #0x4b8] */
/* @0x17d550 mov r0, r7 */
/* @0x17d554 add r1, pc, r1 */
/* @0x17d558 bl 0xb6604 <strstr@plt> */
/* @0x17d55c cmp r0, #0 */
/* @0x17d560 beq 0x17d584 <_Z13GetOpenGLInfov+0x134> */
/* @0x17d564 ldr r1, [pc, #0x498] */
/* @0x17d568 mov r0, #2 */
/* @0x17d56c ldr r3, [pc, #0x494] */
/* @0x17d570 mov r2, #0 */
/* @0x17d574 ldr r1, [r4, r1] */
/* @0x17d578 str r0, [r1] */
/* @0x17d57c ldr r3, [r4, r3] */
/* @0x17d580 str r2, [r3] */
/* @0x17d584 mov r0, #1 */
/* @0x17d588 mov r1, r0 */
/* @0x17d58c bl 0x17d238 <_Z14CheckGLVersionii> */
/* @0x17d590 cmp r0, #0 */
/* @0x17d594 bne 0x17d810 <_Z13GetOpenGLInfov+0x3c0> */
/* @0x17d598 mov r0, #2 */
/* @0x17d59c mov r1, #0 */
/* @0x17d5a0 bl 0x17d238 <_Z14CheckGLVersionii> */
/* @0x17d5a4 cmp r0, #0 */
/* @0x17d5a8 bne 0x17d7e4 <_Z13GetOpenGLInfov+0x394> */
/* @0x17d5ac ldr r3, [r6] */
/* @0x17d5b0 movw r0, #0x1f03 */
/* @0x17d5b4 blx r3 */
/* @0x17d5b8 ldr r3, [r5] */
/* @0x17d5bc ldr r1, [pc, #0x44c] */
/* @0x17d5c0 ldr r3, [r3, #0xc] */
/* @0x17d5c4 add r1, pc, r1 */
/* @0x17d5c8 mov r2, r0 */
/* @0x17d5cc mov r6, r0 */
/* @0x17d5d0 mov r0, r5 */
/* @0x17d5d4 blx r3 */
/* @0x17d5d8 ldr r1, [pc, #0x434] */
/* @0x17d5dc mov r0, r6 */
/* @0x17d5e0 add r1, pc, r1 */
/* @0x17d5e4 bl 0x17d428 <_Z12HasExtensionPcS_> */
/* @0x17d5e8 cmp r0, #0 */
/* @0x17d5ec bne 0x17d7b8 <_Z13GetOpenGLInfov+0x368> */
/* @0x17d5f0 ldr r1, [pc, #0x420] */
/* @0x17d5f4 mov r0, r6 */
/* @0x17d5f8 add r1, pc, r1 */
/* @0x17d5fc bl 0x17d428 <_Z12HasExtensionPcS_> */
/* @0x17d600 cmp r0, #0 */
/* @0x17d604 bne 0x17d78c <_Z13GetOpenGLInfov+0x33c> */
/* @0x17d608 ldr r1, [pc, #0x40c] */
/* @0x17d60c mov r0, r6 */
/* @0x17d610 add r1, pc, r1 */
/* @0x17d614 bl 0x17d428 <_Z12HasExtensionPcS_> */
/* @0x17d618 subs r1, r0, #0 */
/* @0x17d61c beq 0x17d778 <_Z13GetOpenGLInfov+0x328> */
/* @0x17d620 ldr r2, [pc, #0x3f8] */
/* @0x17d624 mov r12, #1 */
/* @0x17d628 ldr r3, [r5] */
/* @0x17d62c mov r0, r5 */
/* @0x17d630 ldr r1, [pc, #0x3ec] */
/* @0x17d634 ldr r2, [r4, r2] */
/* @0x17d638 add r1, pc, r1 */
/* @0x17d63c ldr r3, [r3, #0xc] */
/* @0x17d640 strb r12, [r2] */
/* @0x17d644 blx r3 */
/* @0x17d648 ldr r3, [pc, #0x3d8] */
/* @0x17d64c ldr r7, [r4, r3] */
/* @0x17d650 ldrb r3, [r7] */
/* @0x17d654 cmp r3, #0 */
/* @0x17d658 bne 0x17d754 <_Z13GetOpenGLInfov+0x304> */
/* @0x17d65c mov r0, #1 */
/* @0x17d660 mov r1, #4 */
/* @0x17d664 bl 0x17d238 <_Z14CheckGLVersionii> */
/* @0x17d668 cmp r0, #0 */
/* @0x17d66c bne 0x17d86c <_Z13GetOpenGLInfov+0x41c> */
/* @0x17d670 ldr r1, [pc, #0x3b4] */
/* @0x17d674 mov r0, r6 */
/* @0x17d678 add r1, pc, r1 */
/* @0x17d67c bl 0x17d428 <_Z12HasExtensionPcS_> */
/* @0x17d680 cmp r0, #0 */
/* @0x17d684 bne 0x17d6d0 <_Z13GetOpenGLInfov+0x280> */
/* @0x17d688 ldr r1, [pc, #0x3a0] */
/* @0x17d68c mov r0, r6 */
/* @0x17d690 add r1, pc, r1 */
/* @0x17d694 bl 0x17d428 <_Z12HasExtensionPcS_> */
/* @0x17d698 cmp r0, #0 */
/* @0x17d69c beq 0x17d6c8 <_Z13GetOpenGLInfov+0x278> */
/* @0x17d6a0 ldr r2, [pc, #0x38c] */
/* @0x17d6a4 mov r12, #1 */
/* @0x17d6a8 ldr r3, [r5] */
/* @0x17d6ac mov r0, r5 */
/* @0x17d6b0 ldr r1, [pc, #0x380] */
/* @0x17d6b4 ldr r2, [r4, r2] */
/* @0x17d6b8 add r1, pc, r1 */
/* @0x17d6bc ldr r3, [r3, #0xc] */
/* @0x17d6c0 strb r12, [r2] */
/* @0x17d6c4 blx r3 */
/* @0x17d6c8 add sp, sp, #12 */
/* @0x17d6cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17d6d0 ldr r3, [pc, #0x364] */
/* @0x17d6d4 ldr r7, [r4, r3] */
/* @0x17d6d8 ldr r3, [r7] */
/* @0x17d6dc blx r3 */
/* @0x17d6e0 ldr r3, [pc, #0x358] */
/* @0x17d6e4 movw r0, #0xde1 */
/* @0x17d6e8 movw r1, #0x84fe */
/* @0x17d6ec mov r2, #1065353216 */
/* @0x17d6f0 ldr r3, [r4, r3] */
/* @0x17d6f4 ldr r3, [r3] */
/* @0x17d6f8 blx r3 */
/* @0x17d6fc ldr r3, [r7] */
/* @0x17d700 blx r3 */
/* @0x17d704 cmp r0, #0 */
/* @0x17d708 bne 0x17d688 <_Z13GetOpenGLInfov+0x238> */
/* @0x17d70c ldr r1, [pc, #0x330] */
/* @0x17d710 mov r12, #1 */
/* @0x17d714 ldr r2, [pc, #0x32c] */
/* @0x17d718 movw r0, #0x84ff */
/* @0x17d71c ldr r3, [r10] */
/* @0x17d720 ldr r1, [r4, r1] */
/* @0x17d724 strb r12, [r1] */
/* @0x17d728 ldr r7, [r4, r2] */
/* @0x17d72c mov r1, r7 */
/* @0x17d730 blx r3 */
/* @0x17d734 ldr r3, [r5] */
/* @0x17d738 ldr r1, [pc, #0x30c] */
/* @0x17d73c mov r0, r5 */
/* @0x17d740 ldr r2, [r7] */
/* @0x17d744 add r1, pc, r1 */
/* @0x17d748 ldr r3, [r3, #0xc] */
/* @0x17d74c blx r3 */
/* @0x17d750 b 0x17d688 <_Z13GetOpenGLInfov+0x238> */
/* @0x17d754 mov r0, #1 */
/* @0x17d758 mov r1, r0 */
/* @0x17d75c bl 0x17d238 <_Z14CheckGLVersionii> */
/* @0x17d760 cmp r0, #0 */
/* @0x17d764 bne 0x17d904 <_Z13GetOpenGLInfov+0x4b4> */
/* @0x17d768 ldrb r3, [r7] */
/* @0x17d76c cmp r3, #0 */
/* @0x17d770 bne 0x17d670 <_Z13GetOpenGLInfov+0x220> */
/* @0x17d774 b 0x17d65c <_Z13GetOpenGLInfov+0x20c> */
/* @0x17d778 mov r0, #2 */
/* @0x17d77c bl 0x17d238 <_Z14CheckGLVersionii> */
/* @0x17d780 cmp r0, #0 */
/* @0x17d784 bne 0x17d620 <_Z13GetOpenGLInfov+0x1d0> */
/* @0x17d788 b 0x17d648 <_Z13GetOpenGLInfov+0x1f8> */
/* @0x17d78c ldr r2, [pc, #0x2bc] */
/* @0x17d790 mov r12, #1 */
/* @0x17d794 ldr r3, [r5] */
/* @0x17d798 mov r0, r5 */
/* @0x17d79c ldr r1, [pc, #0x2b0] */
/* @0x17d7a0 ldr r2, [r4, r2] */
/* @0x17d7a4 add r1, pc, r1 */
/* @0x17d7a8 ldr r3, [r3, #0xc] */
/* @0x17d7ac strb r12, [r2] */
/* @0x17d7b0 blx r3 */
/* @0x17d7b4 b 0x17d608 <_Z13GetOpenGLInfov+0x1b8> */
/* @0x17d7b8 ldr r2, [pc, #0x298] */
/* @0x17d7bc mov r12, #1 */
/* @0x17d7c0 ldr r3, [r5] */
/* @0x17d7c4 mov r0, r5 */
/* @0x17d7c8 ldr r1, [pc, #0x28c] */
/* @0x17d7cc ldr r2, [r4, r2] */
/* @0x17d7d0 add r1, pc, r1 */
/* @0x17d7d4 ldr r3, [r3, #0xc] */
/* @0x17d7d8 strb r12, [r2] */
/* @0x17d7dc blx r3 */
/* @0x17d7e0 b 0x17d5f0 <_Z13GetOpenGLInfov+0x1a0> */
/* @0x17d7e4 ldr r2, [pc, #0x248] */
/* @0x17d7e8 mov r12, #1 */
/* @0x17d7ec ldr r3, [r5] */
/* @0x17d7f0 mov r0, r5 */
/* @0x17d7f4 ldr r1, [pc, #0x264] */
/* @0x17d7f8 ldr r2, [r4, r2] */
/* @0x17d7fc add r1, pc, r1 */
/* @0x17d800 ldr r3, [r3, #0xc] */
/* @0x17d804 strb r12, [r2] */
/* @0x17d808 blx r3 */
/* @0x17d80c b 0x17d5ac <_Z13GetOpenGLInfov+0x15c> */
/* @0x17d810 ldr r2, [pc, #0x24c] */
/* @0x17d814 mov r12, #1 */
/* @0x17d818 ldr r3, [r5] */
/* @0x17d81c mov r0, r5 */
/* @0x17d820 ldr r1, [pc, #0x240] */
/* @0x17d824 ldr r2, [r4, r2] */
/* @0x17d828 add r1, pc, r1 */
/* @0x17d82c ldr r3, [r3, #0xc] */
/* @0x17d830 strb r12, [r2] */
/* @0x17d834 blx r3 */
/* @0x17d838 b 0x17d598 <_Z13GetOpenGLInfov+0x148> */
/* @0x17d83c ldr r1, [pc, #0x228] */
/* @0x17d840 mov r3, #1 */
/* @0x17d844 mov r0, #2 */
/* @0x17d848 mov r2, #70 */
/* @0x17d84c add r1, pc, r1 */
/* @0x17d850 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x17d854 mov r3, #48 */
/* @0x17d858 str r0, [r9] */
/* @0x17d85c strb r3, [r0] */
/* @0x17d860 ldr r3, [r9] */
/* @0x17d864 strb r8, [r3, #0x1] */
/* @0x17d868 b 0x17d518 <_Z13GetOpenGLInfov+0xc8> */
/* @0x17d86c ldr r3, [pc, #0x1fc] */
/* @0x17d870 mov r2, #0 */
/* @0x17d874 movt r2, #0x4180 */
/* @0x17d878 ldr r3, [r4, r3] */
/* @0x17d87c str r2, [r3] */
/* @0x17d880 b 0x17d670 <_Z13GetOpenGLInfov+0x220> */
/* @0x17d884 ldr r3, [r6] */
/* @0x17d888 movw r0, #0x8b8c */
/* @0x17d88c blx r3 */
/* @0x17d890 subs r12, r0, #0 */
/* @0x17d894 beq 0x17d988 <_Z13GetOpenGLInfov+0x538> */
/* @0x17d898 ldr r3, [r6] */
/* @0x17d89c movw r0, #0x8b8c */
/* @0x17d8a0 blx r3 */
/* @0x17d8a4 bl 0xb6538 <strlen@plt> */
/* @0x17d8a8 ldr r1, [pc, #0x1c4] */
/* @0x17d8ac mov r2, #70 */
/* @0x17d8b0 mov r3, r8 */
/* @0x17d8b4 add r1, pc, r1 */
/* @0x17d8b8 add r0, r0, #1 */
/* @0x17d8bc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x17d8c0 ldr r3, [r6] */
/* @0x17d8c4 mov r8, r0 */
/* @0x17d8c8 movw r0, #0x8b8c */
/* @0x17d8cc str r8, [r9] */
/* @0x17d8d0 blx r3 */
/* @0x17d8d4 mov r1, r0 */
/* @0x17d8d8 mov r0, r8 */
/* @0x17d8dc bl 0xb65a4 <strcpy@plt> */
/* @0x17d8e0 ldr r3, [r5] */
/* @0x17d8e4 ldr r1, [pc, #0x18c] */
/* @0x17d8e8 mov r0, r5 */
/* @0x17d8ec ldr r2, [r9] */
/* @0x17d8f0 add r1, pc, r1 */
/* @0x17d8f4 ldr r3, [r3, #0xc] */
/* @0x17d8f8 blx r3 */
/* @0x17d8fc ldr r8, [r11] */
/* @0x17d900 b 0x17d510 <_Z13GetOpenGLInfov+0xc0> */
/* @0x17d904 mov r0, #2 */
/* @0x17d908 mov r1, #0 */
/* @0x17d90c bl 0x17d238 <_Z14CheckGLVersionii> */
/* @0x17d910 cmp r0, #0 */
/* @0x17d914 bne 0x17d768 <_Z13GetOpenGLInfov+0x318> */
/* @0x17d918 ldr r1, [pc, #0x15c] */
/* @0x17d91c mov r0, r6 */
/* @0x17d920 add r1, pc, r1 */
/* @0x17d924 bl 0x17d428 <_Z12HasExtensionPcS_> */
/* @0x17d928 cmp r0, #0 */
/* @0x17d92c beq 0x17d768 <_Z13GetOpenGLInfov+0x318> */
/* @0x17d930 ldr r1, [pc, #0x148] */
/* @0x17d934 mov r12, #1 */
/* @0x17d938 ldr r2, [pc, #0x130] */
/* @0x17d93c movw r0, #0x84fd */
/* @0x17d940 ldr r3, [pc, #0x13c] */
/* @0x17d944 ldr r1, [r4, r1] */
/* @0x17d948 strb r12, [r1] */
/* @0x17d94c ldr r8, [r4, r2] */
/* @0x17d950 ldr r3, [r4, r3] */
/* @0x17d954 mov r1, r8 */
/* @0x17d958 ldr r3, [r3] */
/* @0x17d95c blx r3 */
/* @0x17d960 vldr s15, [r8] */
/* @0x17d964 vcvt.f64.f32 d6, s15 */
/* @0x17d968 ldr r12, [r5] */
/* @0x17d96c ldr r1, [pc, #0x114] */
/* @0x17d970 mov r0, r5 */
/* @0x17d974 add r1, pc, r1 */
/* @0x17d978 ldr r12, [r12, #0xc] */
/* @0x17d97c vmov r2, r3, d6 */
/* @0x17d980 blx r12 */
/* @0x17d984 b 0x17d768 <_Z13GetOpenGLInfov+0x318> */
/* @0x17d988 ldr r3, [r5] */
/* @0x17d98c mov r0, r5 */
/* @0x17d990 ldr r1, [pc, #0xf4] */
/* @0x17d994 ldr r3, [r3, #0xc] */
/* @0x17d998 add r1, pc, r1 */
/* @0x17d99c str r12, [sp, #0x4] */
/* @0x17d9a0 blx r3 */
/* @0x17d9a4 ldr r1, [pc, #0xe4] */
/* @0x17d9a8 mov r3, r8 */
/* @0x17d9ac mov r0, #2 */
/* @0x17d9b0 add r1, pc, r1 */
/* @0x17d9b4 mov r2, #70 */
/* @0x17d9b8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x17d9bc mov r3, #48 */
/* @0x17d9c0 str r0, [r9] */
/* @0x17d9c4 strb r3, [r0] */
/* @0x17d9c8 ldr r12, [sp, #0x4] */
/* @0x17d9cc ldr r3, [r9] */
/* @0x17d9d0 strb r12, [r3, #0x1] */
/* @0x17d9d4 ldr r8, [r11] */
/* @0x17d9d8 b 0x17d510 <_Z13GetOpenGLInfov+0xc0> */
/* @0x17d9dc eoreq r4, r7, r12, ror #15 */
/* @0x17d9e0 .word 0xffffbae0 */
/* @0x17d9e4 .word 0xffffbac4 */
/* @0x17d9e8 andseq lr, r12, r8, lsl r2 */
/* @0x17d9ec .word 0xffffe7bc */
/* @0x17d9f0 andseq lr, r12, r4, ror #3 */
/* @0x17d9f4 .word 0xffffbb48 */
/* @0x17d9f8 .word 0xffffe7c0 */
/* @0x17d9fc .word 0xffffe7b8 */
/* @0x17da00 ldrsheq lr, [r12], -r8 */
/* @0x17da04 .word 0xffffe7b0 */
/* @0x17da08 .word 0xffffe7b4 */
/* @0x17da0c ldrsbeq lr, [r12], -r8 */
/* @0x17da10 andseq lr, r12, r0, asr #3 */
/* @0x17da14 ldrheq lr, [r12], -r4 */
/* @0x17da18 andseq lr, r12, r12, asr #3 */
/* @0x17da1c andseq lr, r12, r4, lsl #4 */
/* @0x17da20 .word 0xffffe7c4 */
/* @0x17da24 andseq lr, r12, r12, lsr #5 */
/* @0x17da28 .word 0xffffe7c8 */
/* @0x17da2c andseq lr, r12, r0, asr #3 */
/* @0x17da30 ldrsheq lr, [r12], -r12 */
/* @0x17da34 .word 0xffffe7cc */
/* @0x17da38 andseq lr, r12, r8, ror #3 */
/* @0x17da3c .word 0xffffbadc */
/* @0x17da40 .word 0xffffbb1c */
/* @0x17da44 .word 0xffffe7d0 */
/* @0x17da48 .word 0xffffe7d4 */
/* @0x17da4c andseq lr, r12, r8, lsl r1 */
/* @0x17da50 .word 0xffffe7d8 */
/* @0x17da54 andseq lr, r12, r12, lsr r0 */
/* @0x17da58 .word 0xffffe7dc */
/* @0x17da5c ldrsbeq sp, [r12], -r4 */
/* @0x17da60 andseq sp, r12, r8, asr pc */
/* @0x17da64 .word 0xffffe7e0 */
/* @0x17da68 andseq sp, r12, r4, lsl pc */
/* @0x17da6c andseq r3, r11, r4, ror #15 */
/* @0x17da70 .word 0xffffe7e4 */
/* @0x17da74 andseq r3, r11, r12, ror r7 */
/* @0x17da78 andseq sp, r12, r0, ror #27 */
/* @0x17da7c ldrsheq sp, [r12], -r0 */
/* @0x17da80 .word 0xffffe7e8 */
/* @0x17da84 .word 0xffffbb4c */
/* @0x17da88 ldrheq sp, [r12], -r0 */
/* @0x17da8c andseq sp, r12, r8, asr sp */
/* @0x17da90 andseq r3, r11, r0, lsl #13 */

/* ── FUNC 0x17da94 · InitOGLResources() · size=20 · insn=5 */
/* @0x17da94 push {r3, lr} */
/* @0x17da98 bl 0x183178 <_Z20InitTextureResourcesv> */
/* @0x17da9c bl 0x188144 <_Z26InitShaderManagerResourcesv> */
/* @0x17daa0 pop {r3, lr} */
/* @0x17daa4 b 0x183c80 <_Z26InitVertexBuilderResourcesv> */
