/* libyoyo.so 覆盖卡组 0159
 * 函数 0x1d755c..0x1dbe94，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1d755c · GetTouchAction(int, int) · size=152 · insn=38 */
/* @0x1d755c ldr r3, [pc, #0x8c] */
/* @0x1d7560 cmn r1, #1 */
/* @0x1d7564 mov r12, r0 */
/* @0x1d7568 ldr r3, [pc, r3] */
/* @0x1d756c ldr r2, [r3] */
/* @0x1d7570 beq 0x1d75b8 <_Z14GetTouchActionii+0x5c> */
/* @0x1d7574 cmp r2, #0 */
/* @0x1d7578 beq 0x1d75a0 <_Z14GetTouchActionii+0x44> */
/* @0x1d757c ldr r0, [r2, #0x8] */
/* @0x1d7580 cmp r0, #0 */
/* @0x1d7584 bxeq lr */
/* @0x1d7588 ldr r3, [r0] */
/* @0x1d758c cmp r3, r12 */
/* @0x1d7590 beq 0x1d75a8 <_Z14GetTouchActionii+0x4c> */
/* @0x1d7594 ldr r2, [r2] */
/* @0x1d7598 cmp r2, #0 */
/* @0x1d759c bne 0x1d757c <_Z14GetTouchActionii+0x20> */
/* @0x1d75a0 mov r0, r2 */
/* @0x1d75a4 bx lr */
/* @0x1d75a8 ldr r3, [r0, #0x4] */
/* @0x1d75ac cmp r3, r1 */
/* @0x1d75b0 bne 0x1d7594 <_Z14GetTouchActionii+0x38> */
/* @0x1d75b4 bx lr */
/* @0x1d75b8 cmp r2, #0 */
/* @0x1d75bc beq 0x1d75a0 <_Z14GetTouchActionii+0x44> */
/* @0x1d75c0 ldr r0, [r2, #0x8] */
/* @0x1d75c4 cmp r0, #0 */
/* @0x1d75c8 beq 0x1d75ec <_Z14GetTouchActionii+0x90> */
/* @0x1d75cc ldr r3, [r0] */
/* @0x1d75d0 cmp r3, r12 */
/* @0x1d75d4 beq 0x1d75e8 <_Z14GetTouchActionii+0x8c> */
/* @0x1d75d8 ldr r2, [r2] */
/* @0x1d75dc cmp r2, #0 */
/* @0x1d75e0 bne 0x1d75c0 <_Z14GetTouchActionii+0x64> */
/* @0x1d75e4 b 0x1d75a0 <_Z14GetTouchActionii+0x44> */
/* @0x1d75e8 bx lr */
/* @0x1d75ec bx lr */
/* @0x1d75f0 mlaeq r1, r12, r6, r9 */

/* ── FUNC 0x1d75f4 · GetTouchActionFromUID(int) · size=80 · insn=20 */
/* @0x1d75f4 ldr r3, [pc, #0x44] */
/* @0x1d75f8 mov r1, r0 */
/* @0x1d75fc ldr r3, [pc, r3] */
/* @0x1d7600 ldr r3, [r3] */
/* @0x1d7604 cmp r3, #0 */
/* @0x1d7608 beq 0x1d7630 <_Z21GetTouchActionFromUIDi+0x3c> */
/* @0x1d760c ldr r0, [r3, #0x8] */
/* @0x1d7610 cmp r0, #0 */
/* @0x1d7614 beq 0x1d763c <_Z21GetTouchActionFromUIDi+0x48> */
/* @0x1d7618 ldr r2, [r0, #0x4] */
/* @0x1d761c cmp r2, r1 */
/* @0x1d7620 beq 0x1d7638 <_Z21GetTouchActionFromUIDi+0x44> */
/* @0x1d7624 ldr r3, [r3] */
/* @0x1d7628 cmp r3, #0 */
/* @0x1d762c bne 0x1d760c <_Z21GetTouchActionFromUIDi+0x18> */
/* @0x1d7630 mov r0, r3 */
/* @0x1d7634 bx lr */
/* @0x1d7638 bx lr */
/* @0x1d763c bx lr */
/* @0x1d7640 eoreq r9, r1, r8, lsl #12 */

/* ── FUNC 0x1d7644 · CGesturePinch::IsUsingTouch(int) · size=88 · insn=22 */
/* @0x1d7644 push {r4, r5, r6, lr} */
/* @0x1d7648 mov r4, r0 */
/* @0x1d764c ldr r0, [r0, #0x28] */
/* @0x1d7650 mov r6, r1 */
/* @0x1d7654 bl 0x1d75f4 <_Z21GetTouchActionFromUIDi> */
/* @0x1d7658 mov r5, r0 */
/* @0x1d765c ldr r0, [r4, #0x2c] */
/* @0x1d7660 bl 0x1d75f4 <_Z21GetTouchActionFromUIDi> */
/* @0x1d7664 cmp r5, #0 */
/* @0x1d7668 beq 0x1d7678 <_ZN13CGesturePinch12IsUsingTouchEi+0x34> */
/* @0x1d766c ldr r3, [r5] */
/* @0x1d7670 cmp r3, r6 */
/* @0x1d7674 beq 0x1d7694 <_ZN13CGesturePinch12IsUsingTouchEi+0x50> */
/* @0x1d7678 cmp r0, #0 */
/* @0x1d767c popeq {r4, r5, r6, pc} */
/* @0x1d7680 ldr r0, [r0] */
/* @0x1d7684 subs r3, r6, r0 */
/* @0x1d7688 rsbs r0, r3, #0 */
/* @0x1d768c adcs r0, r0, r3 */
/* @0x1d7690 pop {r4, r5, r6, pc} */
/* @0x1d7694 mov r0, #1 */
/* @0x1d7698 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1d769c · CGestureRotate::IsUsingTouch(int) · size=88 · insn=22 */
/* @0x1d769c push {r4, r5, r6, lr} */
/* @0x1d76a0 mov r4, r0 */
/* @0x1d76a4 ldr r0, [r0, #0x28] */
/* @0x1d76a8 mov r6, r1 */
/* @0x1d76ac bl 0x1d75f4 <_Z21GetTouchActionFromUIDi> */
/* @0x1d76b0 mov r5, r0 */
/* @0x1d76b4 ldr r0, [r4, #0x2c] */
/* @0x1d76b8 bl 0x1d75f4 <_Z21GetTouchActionFromUIDi> */
/* @0x1d76bc cmp r5, #0 */
/* @0x1d76c0 beq 0x1d76d0 <_ZN14CGestureRotate12IsUsingTouchEi+0x34> */
/* @0x1d76c4 ldr r3, [r5] */
/* @0x1d76c8 cmp r3, r6 */
/* @0x1d76cc beq 0x1d76ec <_ZN14CGestureRotate12IsUsingTouchEi+0x50> */
/* @0x1d76d0 cmp r0, #0 */
/* @0x1d76d4 popeq {r4, r5, r6, pc} */
/* @0x1d76d8 ldr r0, [r0] */
/* @0x1d76dc subs r3, r6, r0 */
/* @0x1d76e0 rsbs r0, r3, #0 */
/* @0x1d76e4 adcs r0, r0, r3 */
/* @0x1d76e8 pop {r4, r5, r6, pc} */
/* @0x1d76ec mov r0, #1 */
/* @0x1d76f0 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1d76f4 · CTouchAction::CTouchAction() · size=112 · insn=28 */
/* @0x1d76f4 ldr r12, [pc, #0x64] */
/* @0x1d76f8 mvn r2, #0 */
/* @0x1d76fc push {r4, r5, r6, r7, r8} */
/* @0x1d7700 ldr r12, [pc, r12] */
/* @0x1d7704 movw r7, #0x838 */
/* @0x1d7708 mvn r5, #0 */
/* @0x1d770c ldr r4, [r12] */
/* @0x1d7710 mov r6, #0 */
/* @0x1d7714 str r5, [r0] */
/* @0x1d7718 mvn r3, #0 */
/* @0x1d771c str r5, [r0, #0x10] */
/* @0x1d7720 mov r8, #0 */
/* @0x1d7724 str r6, [r0, #0x20] */
/* @0x1d7728 movt r8, #0xbf80 */
/* @0x1d772c strd r2, r3, [r0, r7] */
/* @0x1d7730 add r5, r4, #1 */
/* @0x1d7734 str r4, [r0, #0x4] */
/* @0x1d7738 str r5, [r12] */
/* @0x1d773c mov r12, #0 */
/* @0x1d7740 str r6, [r0, #0x24] */
/* @0x1d7744 str r8, [r0, #0x18] */
/* @0x1d7748 strd r2, r3, [r0, #8] */
/* @0x1d774c str r12, [r0, #0x828] */
/* @0x1d7750 str r12, [r0, #0x82c] */
/* @0x1d7754 strb r12, [r0, #0x830] */
/* @0x1d7758 pop {r4, r5, r6, r7, r8} */
/* @0x1d775c bx lr */
/* @0x1d7760 eoreq r9, r1, r8, lsl #10 */

/* ── FUNC 0x1d76f4 · CTouchAction::CTouchAction() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1d7764 · CTouchAction::AddRecord(long long, int, int) · size=420 · insn=105 */
/* @0x1d7764 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d7768 sub sp, sp, #28 */
/* @0x1d776c vldr s14, [sp, #64] */
/* @0x1d7770 vcvt.f32.s32 s14, s14 */
/* @0x1d7774 ldr r9, [r0, #0x828] */
/* @0x1d7778 ldr r1, [sp, #0x40] */
/* @0x1d777c mov r5, r3 */
/* @0x1d7780 ldr r3, [sp, #0x44] */
/* @0x1d7784 mov r8, r0 */
/* @0x1d7788 lsl r7, r9, #5 */
/* @0x1d778c mov r4, r2 */
/* @0x1d7790 add r6, r8, r7 */
/* @0x1d7794 str r1, [r6, #0x30] */
/* @0x1d7798 str r3, [r6, #0x34] */
/* @0x1d779c vmov r0, s14 */
/* @0x1d77a0 strd r4, r5, [r6, #40] */
/* @0x1d77a4 bl 0x1d66c0 <_Z11ConvertXDPIf> */
/* @0x1d77a8 vldr s14, [sp, #68] */
/* @0x1d77ac vcvt.f32.s32 s14, s14 */
/* @0x1d77b0 str r0, [r6, #0x38] */
/* @0x1d77b4 vmov r0, s14 */
/* @0x1d77b8 bl 0x1d66e4 <_Z11ConvertYDPIf> */
/* @0x1d77bc ldr r1, [r8, #0x82c] */
/* @0x1d77c0 mov r10, r0 */
/* @0x1d77c4 ldr r0, [r8, #0x828] */
/* @0x1d77c8 str r10, [r6, #0x3c] */
/* @0x1d77cc add r0, r0, #1 */
/* @0x1d77d0 asr r3, r0, #31 */
/* @0x1d77d4 lsr r3, r3, #26 */
/* @0x1d77d8 add r2, r0, r3 */
/* @0x1d77dc and r2, r2, #63 */
/* @0x1d77e0 rsb r2, r3, r2 */
/* @0x1d77e4 str r2, [r8, #0x828] */
/* @0x1d77e8 cmp r2, r1 */
/* @0x1d77ec addne r3, r7, #40 */
/* @0x1d77f0 addne r3, r8, r3 */
/* @0x1d77f4 beq 0x1d78d4 <_ZN12CTouchAction9AddRecordExii+0x170> */
/* @0x1d77f8 add r0, r8, #40 */
/* @0x1d77fc rsb r3, r0, r3 */
/* @0x1d7800 lsr r3, r3, #5 */
/* @0x1d7804 cmp r3, #63 */
/* @0x1d7808 bhi 0x1d78bc <_ZN12CTouchAction9AddRecordExii+0x158> */
/* @0x1d780c cmp r2, r1 */
/* @0x1d7810 add r3, r3, #63 */
/* @0x1d7814 and r3, r3, #63 */
/* @0x1d7818 blt 0x1d78ac <_ZN12CTouchAction9AddRecordExii+0x148> */
/* @0x1d781c cmp r1, r3 */
/* @0x1d7820 bgt 0x1d78bc <_ZN12CTouchAction9AddRecordExii+0x158> */
/* @0x1d7824 cmp r2, r3 */
/* @0x1d7828 ble 0x1d78bc <_ZN12CTouchAction9AddRecordExii+0x158> */
/* @0x1d782c lsl r3, r3, #5 */
/* @0x1d7830 add r7, r8, r7 */
/* @0x1d7834 add r3, r3, #40 */
/* @0x1d7838 mov r0, r4 */
/* @0x1d783c add r1, r8, r3 */
/* @0x1d7840 ldr r2, [r7, #0x38] */
/* @0x1d7844 ldrd r6, r7, [r8, r3] */
/* @0x1d7848 add r9, r9, #2 */
/* @0x1d784c ldr r3, [r1, #0x14] */
/* @0x1d7850 ldr r11, [r1, #0x10] */
/* @0x1d7854 mov r1, r5 */
/* @0x1d7858 subs r0, r0, r6 */
/* @0x1d785c sbc r1, r1, r7 */
/* @0x1d7860 str r2, [sp, #0x10] */
/* @0x1d7864 str r3, [sp, #0x14] */
/* @0x1d7868 bl 0x319398 <__floatdisf> */
/* @0x1d786c vldr s15, [pc, #144] */
/* @0x1d7870 ldr r3, [sp, #0x14] */
/* @0x1d7874 add r8, r8, r9, lsl #5 */
/* @0x1d7878 ldr r2, [sp, #0x10] */
/* @0x1d787c str r8, [sp, #0x4] */
/* @0x1d7880 add r8, r8, #4 */
/* @0x1d7884 mov r1, r3 */
/* @0x1d7888 str r8, [sp, #0x8] */
/* @0x1d788c mov r3, r10 */
/* @0x1d7890 vmov s14, r0 */
/* @0x1d7894 mov r0, r11 */
/* @0x1d7898 vdiv.f32 s15, s14, s15 */
/* @0x1d789c vstr s15, [sp] */
/* @0x1d78a0 bl 0x1d6854 <_Z12CalcVelocityfffffRfS_> */
/* @0x1d78a4 add sp, sp, #28 */
/* @0x1d78a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d78ac cmp r2, r3 */
/* @0x1d78b0 bgt 0x1d782c <_ZN12CTouchAction9AddRecordExii+0xc8> */
/* @0x1d78b4 cmp r1, r3 */
/* @0x1d78b8 ble 0x1d782c <_ZN12CTouchAction9AddRecordExii+0xc8> */
/* @0x1d78bc add r8, r8, r7 */
/* @0x1d78c0 mov r3, #0 */
/* @0x1d78c4 str r3, [r8, #0x40] */
/* @0x1d78c8 str r3, [r8, #0x44] */
/* @0x1d78cc add sp, sp, #28 */
/* @0x1d78d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d78d4 add r12, r2, #1 */
/* @0x1d78d8 add r3, r7, #40 */
/* @0x1d78dc add r3, r8, r3 */
/* @0x1d78e0 asr r0, r12, #31 */
/* @0x1d78e4 lsr r0, r0, #26 */
/* @0x1d78e8 add r1, r12, r0 */
/* @0x1d78ec and r1, r1, #63 */
/* @0x1d78f0 rsb r1, r0, r1 */
/* @0x1d78f4 str r1, [r8, #0x82c] */
/* @0x1d78f8 cmp r2, r1 */
/* @0x1d78fc bne 0x1d77f8 <_ZN12CTouchAction9AddRecordExii+0x94> */
/* @0x1d7900 b 0x1d78bc <_ZN12CTouchAction9AddRecordExii+0x158> */
/* @0x1d7904 ldmdbmi r4!, {r10, sp} ^ */

/* ── FUNC 0x1d7908 · UpdateTouchActions(long long) · size=772 · insn=193 */
/* @0x1d7908 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d790c mov r10, r0 */
/* @0x1d7910 ldr r6, [pc, #0x2e8] */
/* @0x1d7914 sub sp, sp, #20 */
/* @0x1d7918 mov r11, r1 */
/* @0x1d791c ldr r6, [pc, r6] */
/* @0x1d7920 ldr r4, [r6] */
/* @0x1d7924 cmp r4, #0 */
/* @0x1d7928 beq 0x1d7a78 <_Z18UpdateTouchActionsx+0x170> */
/* @0x1d792c ldr r3, [r4, #0x8] */
/* @0x1d7930 cmp r3, #0 */
/* @0x1d7934 beq 0x1d7a78 <_Z18UpdateTouchActionsx+0x170> */
/* @0x1d7938 ldr r8, [pc, #0x2c4] */
/* @0x1d793c mov r7, #0 */
/* @0x1d7940 mov r9, r7 */
/* @0x1d7944 str r6, [sp, #0xc] */
/* @0x1d7948 add r8, pc, r8 */
/* @0x1d794c b 0x1d799c <_Z18UpdateTouchActionsx+0x94> */
/* @0x1d7950 mov r0, #12 */
/* @0x1d7954 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d7958 cmp r7, #0 */
/* @0x1d795c movne r3, #0 */
/* @0x1d7960 streq r7, [r0, #0x4] */
/* @0x1d7964 streq r7, [r0] */
/* @0x1d7968 moveq r7, r0 */
/* @0x1d796c str r5, [r0, #0x8] */
/* @0x1d7970 moveq r9, r7 */
/* @0x1d7974 strne r0, [r7] */
/* @0x1d7978 strne r7, [r0, #0x4] */
/* @0x1d797c movne r7, r0 */
/* @0x1d7980 strne r3, [r0] */
/* @0x1d7984 ldr r4, [r4] */
/* @0x1d7988 cmp r4, #0 */
/* @0x1d798c beq 0x1d7ba8 <_Z18UpdateTouchActionsx+0x2a0> */
/* @0x1d7990 ldr r3, [r4, #0x8] */
/* @0x1d7994 cmp r3, #0 */
/* @0x1d7998 beq 0x1d7ba8 <_Z18UpdateTouchActionsx+0x2a0> */
/* @0x1d799c ldr r5, [r4, #0x8] */
/* @0x1d79a0 mov r0, #1 */
/* @0x1d79a4 mov r1, r8 */
/* @0x1d79a8 mov r2, #143 */
/* @0x1d79ac mov r3, r0 */
/* @0x1d79b0 ldrb r12, [r5, #0x830] */
/* @0x1d79b4 cmp r12, #0 */
/* @0x1d79b8 bne 0x1d7950 <_Z18UpdateTouchActionsx+0x48> */
/* @0x1d79bc ldr r1, [r5] */
/* @0x1d79c0 bl 0x18c0b4 <_Z14IO_Button_Downii> */
/* @0x1d79c4 cmp r0, #0 */
/* @0x1d79c8 bne 0x1d79e0 <_Z18UpdateTouchActionsx+0xd8> */
/* @0x1d79cc mov r3, #1 */
/* @0x1d79d0 strb r3, [r5, #0x830] */
/* @0x1d79d4 movw r3, #0x838 */
/* @0x1d79d8 strd r10, r11, [r5, r3] */
/* @0x1d79dc b 0x1d7984 <_Z18UpdateTouchActionsx+0x7c> */
/* @0x1d79e0 ldr r0, [r5] */
/* @0x1d79e4 bl 0x159e8c <_Z12GetRawMouseXi> */
/* @0x1d79e8 mov r6, r0 */
/* @0x1d79ec ldr r0, [r5] */
/* @0x1d79f0 bl 0x159eec <_Z12GetRawMouseYi> */
/* @0x1d79f4 str r6, [sp] */
/* @0x1d79f8 mov r2, r10 */
/* @0x1d79fc mov r3, r11 */
/* @0x1d7a00 str r0, [sp, #0x4] */
/* @0x1d7a04 mov r0, r5 */
/* @0x1d7a08 bl 0x1d7764 <_ZN12CTouchAction9AddRecordExii> */
/* @0x1d7a0c b 0x1d7984 <_Z18UpdateTouchActionsx+0x7c> */
/* @0x1d7a10 ldm r4, {r2, r3} */
/* @0x1d7a14 cmp r3, #0 */
/* @0x1d7a18 strne r2, [r3] */
/* @0x1d7a1c ldrne r2, [r4] */
/* @0x1d7a20 streq r2, [r6] */
/* @0x1d7a24 cmp r2, #0 */
/* @0x1d7a28 streq r3, [r6, #0x4] */
/* @0x1d7a2c strne r3, [r2, #0x4] */
/* @0x1d7a30 bl 0x27d1d0 <_ZdlPv> */
/* @0x1d7a34 mov r0, r4 */
/* @0x1d7a38 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d7a3c ldr r3, [r6, #0x8] */
/* @0x1d7a40 sub r3, r3, #1 */
/* @0x1d7a44 str r3, [r6, #0x8] */
/* @0x1d7a48 ldr r5, [r5] */
/* @0x1d7a4c cmp r5, #0 */
/* @0x1d7a50 beq 0x1d7a60 <_Z18UpdateTouchActionsx+0x158> */
/* @0x1d7a54 ldr r3, [r5, #0x8] */
/* @0x1d7a58 cmp r3, #0 */
/* @0x1d7a5c bne 0x1d7bc4 <_Z18UpdateTouchActionsx+0x2bc> */
/* @0x1d7a60 mov r0, r9 */
/* @0x1d7a64 ldr r4, [r0] */
/* @0x1d7a68 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d7a6c cmp r4, #0 */
/* @0x1d7a70 mov r0, r4 */
/* @0x1d7a74 bne 0x1d7a64 <_Z18UpdateTouchActionsx+0x15c> */
/* @0x1d7a78 ldr r7, [pc, #0x188] */
/* @0x1d7a7c mov r4, #0 */
/* @0x1d7a80 mov r8, r4 */
/* @0x1d7a84 add r7, pc, r7 */
/* @0x1d7a88 mov r0, #1 */
/* @0x1d7a8c mov r1, r4 */
/* @0x1d7a90 bl 0x18c0b4 <_Z14IO_Button_Downii> */
/* @0x1d7a94 cmp r0, #0 */
/* @0x1d7a98 beq 0x1d7b8c <_Z18UpdateTouchActionsx+0x284> */
/* @0x1d7a9c ldr r3, [r6] */
/* @0x1d7aa0 cmp r3, #0 */
/* @0x1d7aa4 beq 0x1d7acc <_Z18UpdateTouchActionsx+0x1c4> */
/* @0x1d7aa8 ldr r2, [r3, #0x8] */
/* @0x1d7aac cmp r2, #0 */
/* @0x1d7ab0 beq 0x1d7acc <_Z18UpdateTouchActionsx+0x1c4> */
/* @0x1d7ab4 ldr r2, [r2] */
/* @0x1d7ab8 cmp r2, r4 */
/* @0x1d7abc beq 0x1d7b8c <_Z18UpdateTouchActionsx+0x284> */
/* @0x1d7ac0 ldr r3, [r3] */
/* @0x1d7ac4 cmp r3, #0 */
/* @0x1d7ac8 bne 0x1d7aa8 <_Z18UpdateTouchActionsx+0x1a0> */
/* @0x1d7acc mov r0, #2112 */
/* @0x1d7ad0 bl 0x27c524 <_Znwj> */
/* @0x1d7ad4 mov r5, r0 */
/* @0x1d7ad8 bl 0x1d76f4 <_ZN12CTouchActionC2Ev> */
/* @0x1d7adc str r4, [r5] */
/* @0x1d7ae0 mov r0, r4 */
/* @0x1d7ae4 bl 0x159e8c <_Z12GetRawMouseXi> */
/* @0x1d7ae8 mov r9, r0 */
/* @0x1d7aec mov r0, r4 */
/* @0x1d7af0 bl 0x159eec <_Z12GetRawMouseYi> */
/* @0x1d7af4 mov r2, r10 */
/* @0x1d7af8 mov r3, r11 */
/* @0x1d7afc str r9, [sp] */
/* @0x1d7b00 str r0, [sp, #0x4] */
/* @0x1d7b04 mov r0, r5 */
/* @0x1d7b08 bl 0x1d7764 <_ZN12CTouchAction9AddRecordExii> */
/* @0x1d7b0c ldr r3, [r5, #0x828] */
/* @0x1d7b10 ldr r2, [r5, #0x82c] */
/* @0x1d7b14 cmp r3, r2 */
/* @0x1d7b18 beq 0x1d7ba0 <_Z18UpdateTouchActionsx+0x298> */
/* @0x1d7b1c add r3, r3, #63 */
/* @0x1d7b20 and lr, r3, #63 */
/* @0x1d7b24 add lr, r5, lr, lsl #5 */
/* @0x1d7b28 add lr, lr, #40 */
/* @0x1d7b2c ldm lr!, {r0, r1, r2, r3} */
/* @0x1d7b30 add r12, r5, #8 */
/* @0x1d7b34 ldr r9, [r6, #0x8] */
/* @0x1d7b38 add r9, r9, #1 */
/* @0x1d7b3c stm r12!, {r0, r1, r2, r3} */
/* @0x1d7b40 ldm lr, {r0, r1, r2, r3} */
/* @0x1d7b44 str r9, [r6, #0x8] */
/* @0x1d7b48 stm r12, {r0, r1, r2, r3} */
/* @0x1d7b4c mov r3, #1 */
/* @0x1d7b50 mov r0, #12 */
/* @0x1d7b54 mov r1, r7 */
/* @0x1d7b58 mov r2, #143 */
/* @0x1d7b5c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d7b60 ldr r3, [r6, #0x4] */
/* @0x1d7b64 cmp r3, #0 */
/* @0x1d7b68 str r5, [r0, #0x8] */
/* @0x1d7b6c streq r0, [r6, #0x4] */
/* @0x1d7b70 strne r0, [r3] */
/* @0x1d7b74 streq r0, [r6] */
/* @0x1d7b78 strne r3, [r0, #0x4] */
/* @0x1d7b7c streq r3, [r0, #0x4] */
/* @0x1d7b80 strne r0, [r6, #0x4] */
/* @0x1d7b84 streq r3, [r0] */
/* @0x1d7b88 strne r8, [r0] */
/* @0x1d7b8c add r4, r4, #1 */
/* @0x1d7b90 cmp r4, #10 */
/* @0x1d7b94 bne 0x1d7a88 <_Z18UpdateTouchActionsx+0x180> */
/* @0x1d7b98 add sp, sp, #20 */
/* @0x1d7b9c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d7ba0 mov lr, #0 */
/* @0x1d7ba4 b 0x1d7b2c <_Z18UpdateTouchActionsx+0x224> */
/* @0x1d7ba8 cmp r9, #0 */
/* @0x1d7bac ldr r6, [sp, #0xc] */
/* @0x1d7bb0 beq 0x1d7a78 <_Z18UpdateTouchActionsx+0x170> */
/* @0x1d7bb4 ldr r3, [r9, #0x8] */
/* @0x1d7bb8 cmp r3, #0 */
/* @0x1d7bbc beq 0x1d7a60 <_Z18UpdateTouchActionsx+0x158> */
/* @0x1d7bc0 mov r5, r9 */
/* @0x1d7bc4 ldr r4, [r6] */
/* @0x1d7bc8 ldr r3, [r5, #0x8] */
/* @0x1d7bcc cmp r4, #0 */
/* @0x1d7bd0 beq 0x1d7a48 <_Z18UpdateTouchActionsx+0x140> */
/* @0x1d7bd4 ldr r0, [r4, #0x8] */
/* @0x1d7bd8 cmp r0, r3 */
/* @0x1d7bdc bne 0x1d7bf0 <_Z18UpdateTouchActionsx+0x2e8> */
/* @0x1d7be0 b 0x1d7a10 <_Z18UpdateTouchActionsx+0x108> */
/* @0x1d7be4 ldr r0, [r4, #0x8] */
/* @0x1d7be8 cmp r3, r0 */
/* @0x1d7bec beq 0x1d7a10 <_Z18UpdateTouchActionsx+0x108> */
/* @0x1d7bf0 ldr r4, [r4] */
/* @0x1d7bf4 cmp r4, #0 */
/* @0x1d7bf8 bne 0x1d7be4 <_Z18UpdateTouchActionsx+0x2dc> */
/* @0x1d7bfc b 0x1d7a48 <_Z18UpdateTouchActionsx+0x140> */
/* @0x1d7c00 eoreq r9, r1, r8, ror #5 */
/* @0x1d7c04 andseq r5, r7, r8, ror #9 */
/* @0x1d7c08 andseq r5, r7, r12, lsr #7 */

/* ── FUNC 0x1d7c0c · CGesture::CGesture() · size=100 · insn=25 */
/* @0x1d7c0c ldr r12, [pc, #0x54] */
/* @0x1d7c10 mvn r2, #0 */
/* @0x1d7c14 push {r4, r5, r6} */
/* @0x1d7c18 ldr r12, [pc, r12] */
/* @0x1d7c1c ldr r3, [pc, #0x48] */
/* @0x1d7c20 ldr r4, [r12] */
/* @0x1d7c24 ldr r3, [pc, r3] */
/* @0x1d7c28 str r2, [r0, #0x8] */
/* @0x1d7c2c add r6, r3, #8 */
/* @0x1d7c30 add r5, r4, #1 */
/* @0x1d7c34 mvn r2, #1 */
/* @0x1d7c38 str r6, [r0] */
/* @0x1d7c3c str r2, [r0, #0x14] */
/* @0x1d7c40 mvn r3, #0 */
/* @0x1d7c44 mvn r2, #0 */
/* @0x1d7c48 str r4, [r0, #0x4] */
/* @0x1d7c4c str r5, [r12] */
/* @0x1d7c50 mov r4, #0 */
/* @0x1d7c54 strd r2, r3, [r0, #24] */
/* @0x1d7c58 str r4, [r0, #0xc] */
/* @0x1d7c5c str r4, [r0, #0x10] */
/* @0x1d7c60 pop {r4, r5, r6} */
/* @0x1d7c64 bx lr */
/* @0x1d7c68 .word 0x00218ff4 */
/* @0x1d7c6c eoreq r8, r1, r12, asr #31 */

/* ── FUNC 0x1d7c0c · CGesture::CGesture() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1d7c70 · TestForNewPinches(long long) · size=1388 · insn=347 */
/* @0x1d7c70 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d7c74 vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x1d7c78 sub sp, sp, #28 */
/* @0x1d7c7c vldr s16, [pc, #492] */
/* @0x1d7c80 ldr r10, [pc, #0x1f0] */
/* @0x1d7c84 ldr r3, [pc, #0x1f0] */
/* @0x1d7c88 add r10, pc, r10 */
/* @0x1d7c8c strd r0, r1, [sp, #8] */
/* @0x1d7c90 ldr r3, [r10, r3] */
/* @0x1d7c94 vldr s15, [r3] */
/* @0x1d7c98 vmul.f32 s15, s15, s16 */
/* @0x1d7c9c vmov r0, s15 */
/* @0x1d7ca0 bl 0xb658c <cosf@plt> */
/* @0x1d7ca4 ldr r3, [pc, #0x1d4] */
/* @0x1d7ca8 ldr r3, [r10, r3] */
/* @0x1d7cac vldr s15, [r3] */
/* @0x1d7cb0 vmul.f32 s15, s15, s16 */
/* @0x1d7cb4 vmov s26, r0 */
/* @0x1d7cb8 vmov r0, s15 */
/* @0x1d7cbc bl 0xb658c <cosf@plt> */
/* @0x1d7cc0 ldr r3, [pc, #0x1bc] */
/* @0x1d7cc4 ldr r3, [r10, r3] */
/* @0x1d7cc8 vldr s15, [r3] */
/* @0x1d7ccc vmul.f32 s15, s15, s16 */
/* @0x1d7cd0 vmov s14, r0 */
/* @0x1d7cd4 vmov r0, s15 */
/* @0x1d7cd8 vneg.f32 s27, s14 */
/* @0x1d7cdc bl 0xb658c <cosf@plt> */
/* @0x1d7ce0 ldr r3, [pc, #0x1a0] */
/* @0x1d7ce4 ldr r2, [pc, #0x1a0] */
/* @0x1d7ce8 ldr r3, [r10, r3] */
/* @0x1d7cec ldr r2, [r10, r2] */
/* @0x1d7cf0 vldr s23, [r2] */
/* @0x1d7cf4 vmul.f32 s23, s23, s23 */
/* @0x1d7cf8 ldr r8, [r3] */
/* @0x1d7cfc cmp r8, #0 */
/* @0x1d7d00 vmov s15, r0 */
/* @0x1d7d04 vneg.f32 s28, s15 */
/* @0x1d7d08 beq 0x1d7e64 <_Z17TestForNewPinchesx+0x1f4> */
/* @0x1d7d0c ldr r3, [r8, #0x8] */
/* @0x1d7d10 cmp r3, #0 */
/* @0x1d7d14 beq 0x1d7e64 <_Z17TestForNewPinchesx+0x1f4> */
/* @0x1d7d18 ldr r5, [pc, #0x170] */
/* @0x1d7d1c vldr s24, [pc, #336] */
/* @0x1d7d20 vldr s25, [pc, #376] */
/* @0x1d7d24 add r5, pc, r5 */
/* @0x1d7d28 str r5, [sp, #0x14] */
/* @0x1d7d2c ldr r4, [r8, #0x8] */
/* @0x1d7d30 ldrb r3, [r4, #0x830] */
/* @0x1d7d34 cmp r3, #0 */
/* @0x1d7d38 bne 0x1d7e4c <_Z17TestForNewPinchesx+0x1dc> */
/* @0x1d7d3c ldr r6, [r8] */
/* @0x1d7d40 cmp r6, #0 */
/* @0x1d7d44 beq 0x1d7e64 <_Z17TestForNewPinchesx+0x1f4> */
/* @0x1d7d48 ldr r3, [r6, #0x8] */
/* @0x1d7d4c cmp r3, #0 */
/* @0x1d7d50 beq 0x1d81d4 <_Z17TestForNewPinchesx+0x564> */
/* @0x1d7d54 str r8, [sp, #0x10] */
/* @0x1d7d58 ldr r5, [r6, #0x8] */
/* @0x1d7d5c ldrb r3, [r5, #0x830] */
/* @0x1d7d60 cmp r3, #0 */
/* @0x1d7d64 bne 0x1d7e30 <_Z17TestForNewPinchesx+0x1c0> */
/* @0x1d7d68 ldr r3, [pc, #0x124] */
/* @0x1d7d6c ldr r7, [r10, r3] */
/* @0x1d7d70 ldr r11, [r7] */
/* @0x1d7d74 cmp r11, #0 */
/* @0x1d7d78 bne 0x1d7ddc <_Z17TestForNewPinchesx+0x16c> */
/* @0x1d7d7c b 0x1d7ea4 <_Z17TestForNewPinchesx+0x234> */
/* @0x1d7d80 ldr r3, [r8] */
/* @0x1d7d84 mov r0, r8 */
/* @0x1d7d88 ldr r3, [r3, #0x14] */
/* @0x1d7d8c blx r3 */
/* @0x1d7d90 cmp r0, #1 */
/* @0x1d7d94 mov r0, r8 */
/* @0x1d7d98 ble 0x1d7dd0 <_Z17TestForNewPinchesx+0x160> */
/* @0x1d7d9c ldr r3, [r8] */
/* @0x1d7da0 ldr r1, [r4, #0x4] */
/* @0x1d7da4 ldr r3, [r3, #0x10] */
/* @0x1d7da8 blx r3 */
/* @0x1d7dac ldr r3, [r8] */
/* @0x1d7db0 ldr r1, [r5, #0x4] */
/* @0x1d7db4 ldr r3, [r3, #0x10] */
/* @0x1d7db8 mov r9, r0 */
/* @0x1d7dbc mov r0, r8 */
/* @0x1d7dc0 blx r3 */
/* @0x1d7dc4 eor r0, r0, r9 */
/* @0x1d7dc8 tst r0, #255 */
/* @0x1d7dcc bne 0x1d7e30 <_Z17TestForNewPinchesx+0x1c0> */
/* @0x1d7dd0 ldr r11, [r11] */
/* @0x1d7dd4 cmp r11, #0 */
/* @0x1d7dd8 beq 0x1d7ea4 <_Z17TestForNewPinchesx+0x234> */
/* @0x1d7ddc ldr r3, [r11, #0x8] */
/* @0x1d7de0 cmp r3, #0 */
/* @0x1d7de4 beq 0x1d7ea4 <_Z17TestForNewPinchesx+0x234> */
/* @0x1d7de8 ldr r8, [r11, #0x8] */
/* @0x1d7dec ldr r3, [r8, #0x8] */
/* @0x1d7df0 cmp r3, #4 */
/* @0x1d7df4 bne 0x1d7d80 <_Z17TestForNewPinchesx+0x110> */
/* @0x1d7df8 ldr r3, [r8] */
/* @0x1d7dfc mov r0, r8 */
/* @0x1d7e00 ldr r1, [r4, #0x4] */
/* @0x1d7e04 ldr r3, [r3, #0x10] */
/* @0x1d7e08 blx r3 */
/* @0x1d7e0c cmp r0, #0 */
/* @0x1d7e10 beq 0x1d7d80 <_Z17TestForNewPinchesx+0x110> */
/* @0x1d7e14 ldr r3, [r8] */
/* @0x1d7e18 mov r0, r8 */
/* @0x1d7e1c ldr r1, [r5, #0x4] */
/* @0x1d7e20 ldr r3, [r3, #0x10] */
/* @0x1d7e24 blx r3 */
/* @0x1d7e28 cmp r0, #0 */
/* @0x1d7e2c beq 0x1d7d80 <_Z17TestForNewPinchesx+0x110> */
/* @0x1d7e30 ldr r6, [r6] */
/* @0x1d7e34 cmp r6, #0 */
/* @0x1d7e38 beq 0x1d7e48 <_Z17TestForNewPinchesx+0x1d8> */
/* @0x1d7e3c ldr r3, [r6, #0x8] */
/* @0x1d7e40 cmp r3, #0 */
/* @0x1d7e44 bne 0x1d7d58 <_Z17TestForNewPinchesx+0xe8> */
/* @0x1d7e48 ldr r8, [sp, #0x10] */
/* @0x1d7e4c ldr r8, [r8] */
/* @0x1d7e50 cmp r8, #0 */
/* @0x1d7e54 beq 0x1d7e64 <_Z17TestForNewPinchesx+0x1f4> */
/* @0x1d7e58 ldr r3, [r8, #0x8] */
/* @0x1d7e5c cmp r3, #0 */
/* @0x1d7e60 bne 0x1d7d2c <_Z17TestForNewPinchesx+0xbc> */
/* @0x1d7e64 add sp, sp, #28 */
/* @0x1d7e68 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x1d7e6c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d7e70 vstmialo lr, {s30, s31} */
/* @0x1d7e74 blo 0xfe29c838 <b2_toiTime+0xfffffffffdb43394> */
/* @0x1d7e78 eoreq r9, r1, r8, asr #31 */
/* @0x1d7e7c .word 0xffffef8c */
/* @0x1d7e80 .word 0xffffef90 */
/* @0x1d7e84 .word 0xffffefc0 */
/* @0x1d7e88 .word 0xffffefb4 */
/* @0x1d7e8c .word 0xffffef88 */
/* @0x1d7e90 andseq r5, r7, r12, lsl #2 */
/* @0x1d7e94 .word 0xffffefc4 */
/* @0x1d7e98 .word 0xffffefa8 */
/* @0x1d7e9c andhi r0, r0, r0 */
/* @0x1d7ea0 andeq r0, r0, r0 */
/* @0x1d7ea4 ldr r3, [r4, #0x828] */
/* @0x1d7ea8 ldr r2, [r4, #0x82c] */
/* @0x1d7eac cmp r3, r2 */
/* @0x1d7eb0 beq 0x1d812c <_Z17TestForNewPinchesx+0x4bc> */
/* @0x1d7eb4 add r3, r3, #63 */
/* @0x1d7eb8 vldr s15, [r4, #24] */
/* @0x1d7ebc and r3, r3, #63 */
/* @0x1d7ec0 vldr s14, [r4, #28] */
/* @0x1d7ec4 ldr r2, [r5, #0x82c] */
/* @0x1d7ec8 add r3, r4, r3, lsl #5 */
/* @0x1d7ecc vldr s16, [r3, #56] */
/* @0x1d7ed0 vsub.f32 s16, s16, s15 */
/* @0x1d7ed4 vldr s17, [r3, #60] */
/* @0x1d7ed8 ldr r3, [r5, #0x828] */
/* @0x1d7edc cmp r3, r2 */
/* @0x1d7ee0 vmul.f32 s15, s16, s16 */
/* @0x1d7ee4 vsub.f32 s17, s17, s14 */
/* @0x1d7ee8 vmla.f32 s15, s17, s17 */
/* @0x1d7eec beq 0x1d8148 <_Z17TestForNewPinchesx+0x4d8> */
/* @0x1d7ef0 add r3, r3, #63 */
/* @0x1d7ef4 vldr s13, [r5, #28] */
/* @0x1d7ef8 and r3, r3, #63 */
/* @0x1d7efc vldr s14, [r5, #24] */
/* @0x1d7f00 add r3, r5, r3, lsl #5 */
/* @0x1d7f04 vldr s22, [r3, #60] */
/* @0x1d7f08 vldr s21, [r3, #56] */
/* @0x1d7f0c vsub.f32 s22, s22, s13 */
/* @0x1d7f10 vmul.f32 s18, s22, s22 */
/* @0x1d7f14 vsub.f32 s21, s21, s14 */
/* @0x1d7f18 vmla.f32 s18, s21, s21 */
/* @0x1d7f1c vcmpe.f32 s23, s15 */
/* @0x1d7f20 vmrs APSR_nzcv, fpscr */
/* @0x1d7f24 bmi 0x1d7f34 <_Z17TestForNewPinchesx+0x2c4> */
/* @0x1d7f28 vcmpe.f32 s23, s18 */
/* @0x1d7f2c vmrs APSR_nzcv, fpscr */
/* @0x1d7f30 bpl 0x1d7e30 <_Z17TestForNewPinchesx+0x1c0> */
/* @0x1d7f34 vsqrt.f32 s19, s15 */
/* @0x1d7f38 vcmp.f32 s19, s19 */
/* @0x1d7f3c vmrs APSR_nzcv, fpscr */
/* @0x1d7f40 bne 0x1d81c4 <_Z17TestForNewPinchesx+0x554> */
/* @0x1d7f44 vsqrt.f32 s20, s18 */
/* @0x1d7f48 vcmp.f32 s20, s20 */
/* @0x1d7f4c vmrs APSR_nzcv, fpscr */
/* @0x1d7f50 bne 0x1d81b4 <_Z17TestForNewPinchesx+0x544> */
/* @0x1d7f54 ldr r3, [r4, #0x828] */
/* @0x1d7f58 ldr r2, [r4, #0x82c] */
/* @0x1d7f5c ldr r1, [r5, #0x82c] */
/* @0x1d7f60 cmp r3, r2 */
/* @0x1d7f64 ldr r2, [r5, #0x828] */
/* @0x1d7f68 addne r3, r3, #63 */
/* @0x1d7f6c andne r3, r3, #63 */
/* @0x1d7f70 moveq r3, #0 */
/* @0x1d7f74 addne r3, r4, r3, lsl #5 */
/* @0x1d7f78 addne r3, r3, #40 */
/* @0x1d7f7c cmp r2, r1 */
/* @0x1d7f80 addne r2, r2, #63 */
/* @0x1d7f84 vldr s15, [r3, #20] */
/* @0x1d7f88 andne r2, r2, #63 */
/* @0x1d7f8c moveq r2, #0 */
/* @0x1d7f90 addne r2, r5, r2, lsl #5 */
/* @0x1d7f94 addne r2, r2, #40 */
/* @0x1d7f98 vldr s18, [r2, #20] */
/* @0x1d7f9c vsub.f32 s18, s18, s15 */
/* @0x1d7fa0 vldr s29, [r2, #16] */
/* @0x1d7fa4 vldr s15, [r3, #16] */
/* @0x1d7fa8 vmul.f32 s14, s18, s18 */
/* @0x1d7fac vsub.f32 s29, s29, s15 */
/* @0x1d7fb0 vmla.f32 s14, s29, s29 */
/* @0x1d7fb4 vsqrt.f32 s15, s14 */
/* @0x1d7fb8 vcmp.f32 s15, s15 */
/* @0x1d7fbc vmrs APSR_nzcv, fpscr */
/* @0x1d7fc0 bne 0x1d81a4 <_Z17TestForNewPinchesx+0x534> */
/* @0x1d7fc4 vcmpe.f32 s15, #0 */
/* @0x1d7fc8 vmrs APSR_nzcv, fpscr */
/* @0x1d7fcc vdivgt.f32 s29, s29, s15 */
/* @0x1d7fd0 vldrle s14, [pc, #-316] */
/* @0x1d7fd4 vldrle s15, [pc, #-316] */
/* @0x1d7fd8 vdivgt.f32 s15, s18, s15 */
/* @0x1d7fdc vdiv.f32 s17, s17, s19 */
/* @0x1d7fe0 vdiv.f32 s22, s22, s20 */
/* @0x1d7fe4 vdiv.f32 s16, s16, s19 */
/* @0x1d7fe8 vdiv.f32 s21, s21, s20 */
/* @0x1d7fec vneggt.f32 s14, s15 */
/* @0x1d7ff0 vmovle.f32 s13, s14 */
/* @0x1d7ff4 vmovle.f32 s29, s15 */
/* @0x1d7ff8 vmul.f32 s14, s22, s14 */
/* @0x1d7ffc vmul.f32 s15, s17, s15 */
/* @0x1d8000 vneggt.f32 s13, s29 */
/* @0x1d8004 vcmpe.f32 s19, s24 */
/* @0x1d8008 vmla.f32 s15, s16, s29 */
/* @0x1d800c vmrs APSR_nzcv, fpscr */
/* @0x1d8010 vmla.f32 s14, s21, s13 */
/* @0x1d8014 vcmpe.f32 s20, s24 */
/* @0x1d8018 bmi 0x1d8158 <_Z17TestForNewPinchesx+0x4e8> */
/* @0x1d801c vmrs APSR_nzcv, fpscr */
/* @0x1d8020 bmi 0x1d817c <_Z17TestForNewPinchesx+0x50c> */
/* @0x1d8024 vmul.f32 s17, s17, s22 */
/* @0x1d8028 vmla.f32 s17, s16, s21 */
/* @0x1d802c vcmpe.f32 s28, s17 */
/* @0x1d8030 vmrs APSR_nzcv, fpscr */
/* @0x1d8034 ble 0x1d7e30 <_Z17TestForNewPinchesx+0x1c0> */
/* @0x1d8038 vcmpe.f32 s26, s15 */
/* @0x1d803c vmrs APSR_nzcv, fpscr */
/* @0x1d8040 movmi r3, #1 */
/* @0x1d8044 bmi 0x1d8058 <_Z17TestForNewPinchesx+0x3e8> */
/* @0x1d8048 vcmpe.f32 s27, s15 */
/* @0x1d804c vmrs APSR_nzcv, fpscr */
/* @0x1d8050 movle r3, #0 */
/* @0x1d8054 movgt r3, #1 */
/* @0x1d8058 vcmpe.f32 s26, s14 */
/* @0x1d805c vmrs APSR_nzcv, fpscr */
/* @0x1d8060 bmi 0x1d8070 <_Z17TestForNewPinchesx+0x400> */
/* @0x1d8064 vcmpe.f32 s27, s14 */
/* @0x1d8068 vmrs APSR_nzcv, fpscr */
/* @0x1d806c ble 0x1d8198 <_Z17TestForNewPinchesx+0x528> */
/* @0x1d8070 mov r0, #72 */
/* @0x1d8074 mov r9, #4 */
/* @0x1d8078 bl 0x27c524 <_Znwj> */
/* @0x1d807c mov r11, #0 */
/* @0x1d8080 str r0, [sp, #0x4] */
/* @0x1d8084 bl 0x1d7c0c <_ZN8CGestureC2Ev> */
/* @0x1d8088 ldr r12, [pc, #-0x1f8] */
/* @0x1d808c mvn r1, #0 */
/* @0x1d8090 ldr r2, [r4, #0x4] */
/* @0x1d8094 mov r0, #12 */
/* @0x1d8098 ldr r3, [r5, #0x4] */
/* @0x1d809c ldr r8, [sp, #0x4] */
/* @0x1d80a0 ldr r12, [r10, r12] */
/* @0x1d80a4 vstr s25, [r8, #52] */
/* @0x1d80a8 vstr s25, [r8, #48] */
/* @0x1d80ac vstr s25, [r8, #56] */
/* @0x1d80b0 str r9, [r8, #0x8] */
/* @0x1d80b4 vstr s25, [r8, #60] */
/* @0x1d80b8 str r1, [r8, #0x40] */
/* @0x1d80bc add r12, r12, #8 */
/* @0x1d80c0 str r2, [r8, #0x28] */
/* @0x1d80c4 mov r2, #143 */
/* @0x1d80c8 str r12, [r8] */
/* @0x1d80cc str r3, [r8, #0x2c] */
/* @0x1d80d0 mov r3, #1 */
/* @0x1d80d4 ldr r5, [sp, #0x4] */
/* @0x1d80d8 ldrd r8, r9, [sp, #8] */
/* @0x1d80dc ldr r12, [r7, #0x8] */
/* @0x1d80e0 ldr r1, [sp, #0x14] */
/* @0x1d80e4 strd r8, r9, [r5, #24] */
/* @0x1d80e8 add r12, r12, r3 */
/* @0x1d80ec strd r8, r9, [r5, #32] */
/* @0x1d80f0 str r11, [r5, #0x14] */
/* @0x1d80f4 str r12, [r7, #0x8] */
/* @0x1d80f8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d80fc ldr r3, [r7, #0x4] */
/* @0x1d8100 cmp r3, r11 */
/* @0x1d8104 str r5, [r0, #0x8] */
/* @0x1d8108 streq r0, [r7, #0x4] */
/* @0x1d810c strne r0, [r3] */
/* @0x1d8110 streq r0, [r7] */
/* @0x1d8114 strne r3, [r0, #0x4] */
/* @0x1d8118 streq r3, [r0, #0x4] */
/* @0x1d811c strne r0, [r7, #0x4] */
/* @0x1d8120 streq r3, [r0] */
/* @0x1d8124 strne r11, [r0] */
/* @0x1d8128 b 0x1d7e30 <_Z17TestForNewPinchesx+0x1c0> */
/* @0x1d812c ldr r3, [r5, #0x828] */
/* @0x1d8130 vldr s15, [pc, #-664] */
/* @0x1d8134 ldr r2, [r5, #0x82c] */
/* @0x1d8138 vmov.f32 s17, s15 */
/* @0x1d813c cmp r3, r2 */
/* @0x1d8140 vmov.f32 s16, s15 */
/* @0x1d8144 bne 0x1d7ef0 <_Z17TestForNewPinchesx+0x280> */
/* @0x1d8148 vldr s18, [pc, #-688] */
/* @0x1d814c vmov.f32 s22, s18 */
/* @0x1d8150 vmov.f32 s21, s18 */
/* @0x1d8154 b 0x1d7f1c <_Z17TestForNewPinchesx+0x2ac> */
/* @0x1d8158 vmrs APSR_nzcv, fpscr */
/* @0x1d815c bmi 0x1d817c <_Z17TestForNewPinchesx+0x50c> */
/* @0x1d8160 vcmpe.f32 s26, s14 */
/* @0x1d8164 vmrs APSR_nzcv, fpscr */
/* @0x1d8168 bmi 0x1d8070 <_Z17TestForNewPinchesx+0x400> */
/* @0x1d816c vcmpe.f32 s27, s14 */
/* @0x1d8170 vmrs APSR_nzcv, fpscr */
/* @0x1d8174 bgt 0x1d8070 <_Z17TestForNewPinchesx+0x400> */
/* @0x1d8178 b 0x1d7e30 <_Z17TestForNewPinchesx+0x1c0> */
/* @0x1d817c vcmpe.f32 s26, s15 */
/* @0x1d8180 vmrs APSR_nzcv, fpscr */
/* @0x1d8184 bmi 0x1d8070 <_Z17TestForNewPinchesx+0x400> */
/* @0x1d8188 vcmpe.f32 s27, s15 */
/* @0x1d818c vmrs APSR_nzcv, fpscr */
/* @0x1d8190 bgt 0x1d8070 <_Z17TestForNewPinchesx+0x400> */
/* @0x1d8194 b 0x1d7e30 <_Z17TestForNewPinchesx+0x1c0> */
/* @0x1d8198 cmp r3, #0 */
/* @0x1d819c beq 0x1d7e30 <_Z17TestForNewPinchesx+0x1c0> */
/* @0x1d81a0 b 0x1d8070 <_Z17TestForNewPinchesx+0x400> */
/* @0x1d81a4 vmov r0, s14 */
/* @0x1d81a8 bl 0xb6700 <sqrtf@plt> */
/* @0x1d81ac vmov s15, r0 */
/* @0x1d81b0 b 0x1d7fc4 <_Z17TestForNewPinchesx+0x354> */
/* @0x1d81b4 vmov r0, s18 */
/* @0x1d81b8 bl 0xb6700 <sqrtf@plt> */
/* @0x1d81bc vmov s20, r0 */
/* @0x1d81c0 b 0x1d7f54 <_Z17TestForNewPinchesx+0x2e4> */
/* @0x1d81c4 vmov r0, s15 */
/* @0x1d81c8 bl 0xb6700 <sqrtf@plt> */
/* @0x1d81cc vmov s19, r0 */
/* @0x1d81d0 b 0x1d7f44 <_Z17TestForNewPinchesx+0x2d4> */
/* @0x1d81d4 mov r8, r6 */
/* @0x1d81d8 b 0x1d7e58 <_Z17TestForNewPinchesx+0x1e8> */

/* ── FUNC 0x1d81dc · TestForNewRotates(long long) · size=1504 · insn=376 */
/* @0x1d81dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d81e0 vpush {d8, d9, d10, d11, d12} */
/* @0x1d81e4 sub sp, sp, #68 */
/* @0x1d81e8 vldr s15, [pc, #448] */
/* @0x1d81ec ldr r6, [pc, #0x1c8] */
/* @0x1d81f0 ldr r3, [pc, #0x1c8] */
/* @0x1d81f4 add r6, pc, r6 */
/* @0x1d81f8 strd r0, r1, [sp, #48] */
/* @0x1d81fc str r6, [sp, #0x38] */
/* @0x1d8200 ldr r3, [r6, r3] */
/* @0x1d8204 ldr r2, [pc, #0x1b8] */
/* @0x1d8208 ldr r3, [r3] */
/* @0x1d820c ldr r2, [r6, r2] */
/* @0x1d8210 vldr s23, [r2] */
/* @0x1d8214 cmp r3, #0 */
/* @0x1d8218 vmul.f32 s23, s23, s15 */
/* @0x1d821c str r3, [sp, #0x28] */
/* @0x1d8220 beq 0x1d83a4 <_Z17TestForNewRotatesx+0x1c8> */
/* @0x1d8224 ldr r3, [r3, #0x8] */
/* @0x1d8228 cmp r3, #0 */
/* @0x1d822c beq 0x1d83a4 <_Z17TestForNewRotatesx+0x1c8> */
/* @0x1d8230 ldr r7, [pc, #0x190] */
/* @0x1d8234 vldr s22, [pc, #412] */
/* @0x1d8238 vldr s20, [pc, #372] */
/* @0x1d823c vldr s21, [pc, #372] */
/* @0x1d8240 add r7, pc, r7 */
/* @0x1d8244 str r7, [sp, #0x3c] */
/* @0x1d8248 ldr r8, [sp, #0x28] */
/* @0x1d824c ldr r11, [r8, #0x8] */
/* @0x1d8250 ldrb r3, [r11, #0x830] */
/* @0x1d8254 cmp r3, #0 */
/* @0x1d8258 bne 0x1d8380 <_Z17TestForNewRotatesx+0x1a4> */
/* @0x1d825c ldr r12, [sp, #0x28] */
/* @0x1d8260 ldr r12, [r12] */
/* @0x1d8264 cmp r12, #0 */
/* @0x1d8268 str r12, [sp, #0x18] */
/* @0x1d826c beq 0x1d83a4 <_Z17TestForNewRotatesx+0x1c8> */
/* @0x1d8270 ldr r3, [r12, #0x8] */
/* @0x1d8274 cmp r3, #0 */
/* @0x1d8278 beq 0x1d87b0 <_Z17TestForNewRotatesx+0x5d4> */
/* @0x1d827c ldr r6, [sp, #0x18] */
/* @0x1d8280 ldr r8, [r6, #0x8] */
/* @0x1d8284 ldrb r3, [r8, #0x830] */
/* @0x1d8288 cmp r3, #0 */
/* @0x1d828c bne 0x1d8360 <_Z17TestForNewRotatesx+0x184> */
/* @0x1d8290 ldr r3, [pc, #0x134] */
/* @0x1d8294 ldr r7, [sp, #0x38] */
/* @0x1d8298 ldr r3, [r7, r3] */
/* @0x1d829c ldr r5, [r3] */
/* @0x1d82a0 str r3, [sp, #0x2c] */
/* @0x1d82a4 cmp r5, #0 */
/* @0x1d82a8 bne 0x1d830c <_Z17TestForNewRotatesx+0x130> */
/* @0x1d82ac b 0x1d83dc <_Z17TestForNewRotatesx+0x200> */
/* @0x1d82b0 ldr r3, [r4] */
/* @0x1d82b4 mov r0, r4 */
/* @0x1d82b8 ldr r3, [r3, #0x14] */
/* @0x1d82bc blx r3 */
/* @0x1d82c0 cmp r0, #1 */
/* @0x1d82c4 mov r0, r4 */
/* @0x1d82c8 ble 0x1d8300 <_Z17TestForNewRotatesx+0x124> */
/* @0x1d82cc ldr r3, [r4] */
/* @0x1d82d0 ldr r1, [r11, #0x4] */
/* @0x1d82d4 ldr r3, [r3, #0x10] */
/* @0x1d82d8 blx r3 */
/* @0x1d82dc ldr r3, [r4] */
/* @0x1d82e0 ldr r1, [r8, #0x4] */
/* @0x1d82e4 ldr r3, [r3, #0x10] */
/* @0x1d82e8 mov r6, r0 */
/* @0x1d82ec mov r0, r4 */
/* @0x1d82f0 blx r3 */
/* @0x1d82f4 eor r0, r0, r6 */
/* @0x1d82f8 tst r0, #255 */
/* @0x1d82fc bne 0x1d8360 <_Z17TestForNewRotatesx+0x184> */
/* @0x1d8300 ldr r5, [r5] */
/* @0x1d8304 cmp r5, #0 */
/* @0x1d8308 beq 0x1d83dc <_Z17TestForNewRotatesx+0x200> */
/* @0x1d830c ldr r3, [r5, #0x8] */
/* @0x1d8310 cmp r3, #0 */
/* @0x1d8314 beq 0x1d83dc <_Z17TestForNewRotatesx+0x200> */
/* @0x1d8318 ldr r4, [r5, #0x8] */
/* @0x1d831c ldr r3, [r4, #0x8] */
/* @0x1d8320 cmp r3, #5 */
/* @0x1d8324 bne 0x1d82b0 <_Z17TestForNewRotatesx+0xd4> */
/* @0x1d8328 ldr r3, [r4] */
/* @0x1d832c mov r0, r4 */
/* @0x1d8330 ldr r1, [r11, #0x4] */
/* @0x1d8334 ldr r3, [r3, #0x10] */
/* @0x1d8338 blx r3 */
/* @0x1d833c cmp r0, #0 */
/* @0x1d8340 beq 0x1d82b0 <_Z17TestForNewRotatesx+0xd4> */
/* @0x1d8344 ldr r3, [r4] */
/* @0x1d8348 mov r0, r4 */
/* @0x1d834c ldr r1, [r8, #0x4] */
/* @0x1d8350 ldr r3, [r3, #0x10] */
/* @0x1d8354 blx r3 */
/* @0x1d8358 cmp r0, #0 */
/* @0x1d835c beq 0x1d82b0 <_Z17TestForNewRotatesx+0xd4> */
/* @0x1d8360 ldr r9, [sp, #0x18] */
/* @0x1d8364 ldr r9, [r9] */
/* @0x1d8368 cmp r9, #0 */
/* @0x1d836c str r9, [sp, #0x18] */
/* @0x1d8370 beq 0x1d8380 <_Z17TestForNewRotatesx+0x1a4> */
/* @0x1d8374 ldr r3, [r9, #0x8] */
/* @0x1d8378 cmp r3, #0 */
/* @0x1d837c bne 0x1d827c <_Z17TestForNewRotatesx+0xa0> */
/* @0x1d8380 ldr r9, [sp, #0x28] */
/* @0x1d8384 ldr r9, [r9] */
/* @0x1d8388 cmp r9, #0 */
/* @0x1d838c str r9, [sp, #0x28] */
/* @0x1d8390 beq 0x1d83a4 <_Z17TestForNewRotatesx+0x1c8> */
/* @0x1d8394 ldr r12, [sp, #0x28] */
/* @0x1d8398 ldr r3, [r12, #0x8] */
/* @0x1d839c cmp r3, #0 */
/* @0x1d83a0 bne 0x1d8248 <_Z17TestForNewRotatesx+0x6c> */
/* @0x1d83a4 add sp, sp, #68 */
/* @0x1d83a8 vpop {d8, d9, d10, d11, d12} */
/* @0x1d83ac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d83b0 vstmialo lr, {s30, s31} */
/* @0x1d83b4 ldrdmi r0, r1, [r9], #-251 */
/* @0x1d83b8 ldrdmi r0, r1, [r9], #251 */
/* @0x1d83bc eoreq r9, r1, r12, asr r10 */
/* @0x1d83c0 .word 0xffffefb4 */
/* @0x1d83c4 .word 0xffffef98 */
/* @0x1d83c8 ldrsheq r4, [r7], -r0 */
/* @0x1d83cc .word 0xffffefc4 */
/* @0x1d83d0 .word 0xffffef94 */
/* @0x1d83d4 .word 0xffffefac */
/* @0x1d83d8 andeq r0, r0, r0 */
/* @0x1d83dc ldr r12, [r11, #0x828] */
/* @0x1d83e0 ldr r6, [r11, #0x82c] */
/* @0x1d83e4 cmp r12, r6 */
/* @0x1d83e8 beq 0x1d8798 <_Z17TestForNewRotatesx+0x5bc> */
/* @0x1d83ec add r4, r12, #63 */
/* @0x1d83f0 and r4, r4, #63 */
/* @0x1d83f4 add r4, r11, r4, lsl #5 */
/* @0x1d83f8 add r4, r4, #40 */
/* @0x1d83fc ldr r9, [r8, #0x82c] */
/* @0x1d8400 add r2, r11, #40 */
/* @0x1d8404 ldr r7, [r8, #0x828] */
/* @0x1d8408 vldr s19, [pc, #-56] */
/* @0x1d840c ldrd r0, r1, [sp, #48] */
/* @0x1d8410 vmov.f32 s24, s19 */
/* @0x1d8414 cmp r7, r9 */
/* @0x1d8418 str r9, [sp, #0xc] */
/* @0x1d841c ldr r3, [pc, #-0x54] */
/* @0x1d8420 addne r5, r7, #63 */
/* @0x1d8424 ldr r9, [sp, #0x38] */
/* @0x1d8428 andne r5, r5, #63 */
/* @0x1d842c strd r0, r1, [sp] */
/* @0x1d8430 mov r1, #1 */
/* @0x1d8434 str r2, [sp, #0x1c] */
/* @0x1d8438 addne r5, r8, r5, lsl #5 */
/* @0x1d843c str r1, [sp, #0x24] */
/* @0x1d8440 add r1, r8, #40 */
/* @0x1d8444 ldr r3, [r9, r3] */
/* @0x1d8448 addne r5, r5, #40 */
/* @0x1d844c str r1, [sp, #0x20] */
/* @0x1d8450 moveq r5, #0 */
/* @0x1d8454 ldrd r0, r1, [sp, #48] */
/* @0x1d8458 ldrd r2, r3, [r3] */
/* @0x1d845c str r8, [sp, #0x8] */
/* @0x1d8460 subs r0, r0, r2 */
/* @0x1d8464 sbc r1, r1, r3 */
/* @0x1d8468 strd r0, r1, [sp, #16] */
/* @0x1d846c cmp r5, #0 */
/* @0x1d8470 cmpne r4, #0 */
/* @0x1d8474 beq 0x1d860c <_Z17TestForNewRotatesx+0x430> */
/* @0x1d8478 ldrd r8, r9, [r5] */
/* @0x1d847c ldrd r2, r3, [r4] */
/* @0x1d8480 strd r8, r9, [sp] */
/* @0x1d8484 cmp r2, r8 */
/* @0x1d8488 sbcs r9, r3, r9 */
/* @0x1d848c ldrd r8, r9, [sp, #16] */
/* @0x1d8490 ldrd r0, r1, [sp] */
/* @0x1d8494 strdlt r2, r3, [sp] */
/* @0x1d8498 cmp r2, r8 */
/* @0x1d849c sbcs r9, r3, r9 */
/* @0x1d84a0 bge 0x1d84b4 <_Z17TestForNewRotatesx+0x2d8> */
/* @0x1d84a4 ldrd r8, r9, [sp, #16] */
/* @0x1d84a8 cmp r0, r8 */
/* @0x1d84ac sbcs r9, r1, r9 */
/* @0x1d84b0 blt 0x1d860c <_Z17TestForNewRotatesx+0x430> */
/* @0x1d84b4 vldr s15, [r4, #20] */
/* @0x1d84b8 vldr s17, [r5, #20] */
/* @0x1d84bc vsub.f32 s17, s17, s15 */
/* @0x1d84c0 vldr s16, [r5, #16] */
/* @0x1d84c4 vldr s14, [r4, #16] */
/* @0x1d84c8 vmul.f32 s15, s17, s17 */
/* @0x1d84cc vsub.f32 s16, s16, s14 */
/* @0x1d84d0 vmla.f32 s15, s16, s16 */
/* @0x1d84d4 vcmpe.f32 s15, #0 */
/* @0x1d84d8 vmrs APSR_nzcv, fpscr */
/* @0x1d84dc ble 0x1d8550 <_Z17TestForNewRotatesx+0x374> */
/* @0x1d84e0 vsqrt.f32 s18, s15 */
/* @0x1d84e4 vcmp.f32 s18, s18 */
/* @0x1d84e8 vmrs APSR_nzcv, fpscr */
/* @0x1d84ec bne 0x1d87a0 <_Z17TestForNewRotatesx+0x5c4> */
/* @0x1d84f0 vdiv.f32 s17, s17, s18 */
/* @0x1d84f4 vmov r0, s17 */
/* @0x1d84f8 bl 0xb6760 <acosf@plt> */
/* @0x1d84fc vdiv.f32 s16, s16, s18 */
/* @0x1d8500 ldr r12, [sp, #0x24] */
/* @0x1d8504 vmov s15, r0 */
/* @0x1d8508 vcmpe.f32 s16, #0 */
/* @0x1d850c vmrs APSR_nzcv, fpscr */
/* @0x1d8510 vsubmi.f32 s15, s20, s15 */
/* @0x1d8514 vaddmi.f32 s15, s15, s20 */
/* @0x1d8518 cmp r12, #0 */
/* @0x1d851c beq 0x1d8744 <_Z17TestForNewRotatesx+0x568> */
/* @0x1d8520 ldr r8, [sp, #0x8] */
/* @0x1d8524 mov r6, #0 */
/* @0x1d8528 ldrd r2, r3, [r4] */
/* @0x1d852c vldr s19, [pc, #-348] */
/* @0x1d8530 str r6, [sp, #0x24] */
/* @0x1d8534 ldr r9, [r8, #0x82c] */
/* @0x1d8538 ldrd r0, r1, [r5] */
/* @0x1d853c ldr r7, [r8, #0x828] */
/* @0x1d8540 vmov.f32 s24, s15 */
/* @0x1d8544 ldr r12, [r11, #0x828] */
/* @0x1d8548 ldr r6, [r11, #0x82c] */
/* @0x1d854c str r9, [sp, #0xc] */
/* @0x1d8550 cmp r12, r6 */
/* @0x1d8554 beq 0x1d873c <_Z17TestForNewRotatesx+0x560> */
/* @0x1d8558 ldr r8, [sp, #0x1c] */
/* @0x1d855c rsb r10, r8, r4 */
/* @0x1d8560 lsr r10, r10, #5 */
/* @0x1d8564 cmp r10, #63 */
/* @0x1d8568 bhi 0x1d873c <_Z17TestForNewRotatesx+0x560> */
/* @0x1d856c cmp r12, r6 */
/* @0x1d8570 add r10, r10, #63 */
/* @0x1d8574 and r10, r10, #63 */
/* @0x1d8578 bge 0x1d872c <_Z17TestForNewRotatesx+0x550> */
/* @0x1d857c cmp r12, r10 */
/* @0x1d8580 bgt 0x1d858c <_Z17TestForNewRotatesx+0x3b0> */
/* @0x1d8584 cmp r6, r10 */
/* @0x1d8588 bgt 0x1d873c <_Z17TestForNewRotatesx+0x560> */
/* @0x1d858c add r10, r11, r10, lsl #5 */
/* @0x1d8590 add r10, r10, #40 */
/* @0x1d8594 ldr r9, [sp, #0xc] */
/* @0x1d8598 cmp r7, r9 */
/* @0x1d859c beq 0x1d8710 <_Z17TestForNewRotatesx+0x534> */
/* @0x1d85a0 ldr r8, [sp, #0x20] */
/* @0x1d85a4 rsb r9, r8, r5 */
/* @0x1d85a8 lsr r9, r9, #5 */
/* @0x1d85ac cmp r9, #63 */
/* @0x1d85b0 bhi 0x1d8710 <_Z17TestForNewRotatesx+0x534> */
/* @0x1d85b4 ldr r8, [sp, #0xc] */
/* @0x1d85b8 add r9, r9, #63 */
/* @0x1d85bc and r9, r9, #63 */
/* @0x1d85c0 cmp r7, r8 */
/* @0x1d85c4 bge 0x1d86fc <_Z17TestForNewRotatesx+0x520> */
/* @0x1d85c8 cmp r7, r9 */
/* @0x1d85cc bgt 0x1d85d8 <_Z17TestForNewRotatesx+0x3fc> */
/* @0x1d85d0 cmp r8, r9 */
/* @0x1d85d4 bgt 0x1d8710 <_Z17TestForNewRotatesx+0x534> */
/* @0x1d85d8 ldr r8, [sp, #0x8] */
/* @0x1d85dc cmp r3, r1 */
/* @0x1d85e0 cmpeq r2, r0 */
/* @0x1d85e4 add r9, r8, r9, lsl #5 */
/* @0x1d85e8 add r9, r9, #40 */
/* @0x1d85ec beq 0x1d8720 <_Z17TestForNewRotatesx+0x544> */
/* @0x1d85f0 cmp r0, r2 */
/* @0x1d85f4 sbcs r8, r1, r3 */
/* @0x1d85f8 movge r5, r9 */
/* @0x1d85fc movlt r4, r10 */
/* @0x1d8600 cmp r5, #0 */
/* @0x1d8604 cmpne r4, #0 */
/* @0x1d8608 bne 0x1d8478 <_Z17TestForNewRotatesx+0x29c> */
/* @0x1d860c ldrd r2, r3, [sp, #16] */
/* @0x1d8610 ldrd r6, r7, [sp] */
/* @0x1d8614 ldr r8, [sp, #0x8] */
/* @0x1d8618 cmp r2, r6 */
/* @0x1d861c sbcs r7, r3, r7 */
/* @0x1d8620 blt 0x1d8360 <_Z17TestForNewRotatesx+0x184> */
/* @0x1d8624 vabs.f32 s19, s19 */
/* @0x1d8628 vcmpe.f32 s23, s19 */
/* @0x1d862c vmrs APSR_nzcv, fpscr */
/* @0x1d8630 bpl 0x1d8360 <_Z17TestForNewRotatesx+0x184> */
/* @0x1d8634 mov r0, #72 */
/* @0x1d8638 bl 0x27c524 <_Znwj> */
/* @0x1d863c mov r4, r0 */
/* @0x1d8640 bl 0x1d7c0c <_ZN8CGestureC2Ev> */
/* @0x1d8644 ldr r3, [r8, #0x4] */
/* @0x1d8648 mov r0, #5 */
/* @0x1d864c ldr r8, [sp, #0x38] */
/* @0x1d8650 mvn r1, #0 */
/* @0x1d8654 ldr r12, [pc, #-0x288] */
/* @0x1d8658 mov lr, #0 */
/* @0x1d865c ldr r9, [sp, #0x2c] */
/* @0x1d8660 ldr r2, [r11, #0x4] */
/* @0x1d8664 ldr r12, [r8, r12] */
/* @0x1d8668 vstr s22, [r4, #52] */
/* @0x1d866c ldrd r6, r7, [sp, #48] */
/* @0x1d8670 vstr s22, [r4, #48] */
/* @0x1d8674 add r12, r12, #8 */
/* @0x1d8678 str r12, [r4] */
/* @0x1d867c ldr r12, [r9, #0x8] */
/* @0x1d8680 vstr s22, [r4, #56] */
/* @0x1d8684 str r0, [r4, #0x8] */
/* @0x1d8688 vstr s22, [r4, #60] */
/* @0x1d868c str r1, [r4, #0x44] */
/* @0x1d8690 vstr s22, [r4, #64] */
/* @0x1d8694 str r2, [r4, #0x28] */
/* @0x1d8698 mov r0, #12 */
/* @0x1d869c str r3, [r4, #0x2c] */
/* @0x1d86a0 mov r2, #143 */
/* @0x1d86a4 mov r3, #1 */
/* @0x1d86a8 strd r6, r7, [r4, #24] */
/* @0x1d86ac strd r6, r7, [r4, #32] */
/* @0x1d86b0 add r12, r12, r3 */
/* @0x1d86b4 ldr r1, [sp, #0x3c] */
/* @0x1d86b8 str lr, [r4, #0x14] */
/* @0x1d86bc str r12, [r9, #0x8] */
/* @0x1d86c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d86c4 ldr r3, [r9, #0x4] */
/* @0x1d86c8 cmp r3, #0 */
/* @0x1d86cc ldrne r7, [sp, #0x2c] */
/* @0x1d86d0 movne r8, #0 */
/* @0x1d86d4 streq r0, [r9, #0x4] */
/* @0x1d86d8 str r4, [r0, #0x8] */
/* @0x1d86dc streq r0, [r9] */
/* @0x1d86e0 strne r0, [r3] */
/* @0x1d86e4 streq r3, [r0, #0x4] */
/* @0x1d86e8 strne r3, [r0, #0x4] */
/* @0x1d86ec streq r3, [r0] */
/* @0x1d86f0 strne r0, [r7, #0x4] */
/* @0x1d86f4 strne r8, [r0] */
/* @0x1d86f8 b 0x1d8360 <_Z17TestForNewRotatesx+0x184> */
/* @0x1d86fc ldr r8, [sp, #0xc] */
/* @0x1d8700 cmp r8, r9 */
/* @0x1d8704 bgt 0x1d8710 <_Z17TestForNewRotatesx+0x534> */
/* @0x1d8708 cmp r7, r9 */
/* @0x1d870c bgt 0x1d85d8 <_Z17TestForNewRotatesx+0x3fc> */
/* @0x1d8710 cmp r3, r1 */
/* @0x1d8714 cmpeq r2, r0 */
/* @0x1d8718 mov r9, #0 */
/* @0x1d871c bne 0x1d85f0 <_Z17TestForNewRotatesx+0x414> */
/* @0x1d8720 mov r5, r9 */
/* @0x1d8724 mov r4, r10 */
/* @0x1d8728 b 0x1d846c <_Z17TestForNewRotatesx+0x290> */
/* @0x1d872c cmp r6, r10 */
/* @0x1d8730 bgt 0x1d873c <_Z17TestForNewRotatesx+0x560> */
/* @0x1d8734 cmp r12, r10 */
/* @0x1d8738 bgt 0x1d858c <_Z17TestForNewRotatesx+0x3b0> */
/* @0x1d873c mov r10, #0 */
/* @0x1d8740 b 0x1d8594 <_Z17TestForNewRotatesx+0x3b8> */
/* @0x1d8744 vsub.f32 s14, s15, s24 */
/* @0x1d8748 vcmpe.f32 s14, s20 */
/* @0x1d874c vmrs APSR_nzcv, fpscr */
/* @0x1d8750 vsubgt.f32 s14, s21, s14 */
/* @0x1d8754 vneggt.f32 s14, s14 */
/* @0x1d8758 vadd.f32 s14, s19, s14 */
/* @0x1d875c vmul.f32 s13, s14, s19 */
/* @0x1d8760 vcmpe.f32 s13, #0 */
/* @0x1d8764 vmrs APSR_nzcv, fpscr */
/* @0x1d8768 bmi 0x1d860c <_Z17TestForNewRotatesx+0x430> */
/* @0x1d876c ldr r12, [sp, #0x8] */
/* @0x1d8770 vmov.f32 s19, s14 */
/* @0x1d8774 ldrd r2, r3, [r4] */
/* @0x1d8778 ldrd r0, r1, [r5] */
/* @0x1d877c ldr r6, [r12, #0x82c] */
/* @0x1d8780 ldr r7, [r12, #0x828] */
/* @0x1d8784 vmov.f32 s24, s15 */
/* @0x1d8788 ldr r12, [r11, #0x828] */
/* @0x1d878c str r6, [sp, #0xc] */
/* @0x1d8790 ldr r6, [r11, #0x82c] */
/* @0x1d8794 b 0x1d8550 <_Z17TestForNewRotatesx+0x374> */
/* @0x1d8798 mov r4, #0 */
/* @0x1d879c b 0x1d83fc <_Z17TestForNewRotatesx+0x220> */
/* @0x1d87a0 vmov r0, s15 */
/* @0x1d87a4 bl 0xb6700 <sqrtf@plt> */
/* @0x1d87a8 vmov s18, r0 */
/* @0x1d87ac b 0x1d84f0 <_Z17TestForNewRotatesx+0x314> */
/* @0x1d87b0 ldr r6, [sp, #0x18] */
/* @0x1d87b4 str r6, [sp, #0x28] */
/* @0x1d87b8 b 0x1d8394 <_Z17TestForNewRotatesx+0x1b8> */

/* ── FUNC 0x1d87bc · AddMultiFingerGestures(long long) · size=32 · insn=8 */
/* @0x1d87bc push {r3, r4, r5, lr} */
/* @0x1d87c0 mov r4, r0 */
/* @0x1d87c4 mov r5, r1 */
/* @0x1d87c8 bl 0x1d7c70 <_Z17TestForNewPinchesx> */
/* @0x1d87cc mov r0, r4 */
/* @0x1d87d0 mov r1, r5 */
/* @0x1d87d4 pop {r3, r4, r5, lr} */
/* @0x1d87d8 b 0x1d81dc <_Z17TestForNewRotatesx> */

/* ── FUNC 0x1d87dc · CGestureUnknown::Update(long long) · size=648 · insn=162 */
/* @0x1d87dc ldr r1, [r0] */
/* @0x1d87e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d87e4 mov r4, r0 */
/* @0x1d87e8 sub sp, sp, #12 */
/* @0x1d87ec ldr r1, [r1, #0x18] */
/* @0x1d87f0 mov r10, r2 */
/* @0x1d87f4 mov r11, r3 */
/* @0x1d87f8 blx r1 */
/* @0x1d87fc ldr r1, [r4, #0x28] */
/* @0x1d8800 mov r0, #1 */
/* @0x1d8804 ldr r6, [pc, #0x238] */
/* @0x1d8808 bl 0x18c0b4 <_Z14IO_Button_Downii> */
/* @0x1d880c add r6, pc, r6 */
/* @0x1d8810 subs r7, r0, #0 */
/* @0x1d8814 beq 0x1d8934 <_ZN15CGestureUnknown6UpdateEx+0x158> */
/* @0x1d8818 ldr r1, [r4, #0x4c] */
/* @0x1d881c ldr r0, [r4, #0x48] */
/* @0x1d8820 bl 0x1d6708 <_Z14CalcDistInchesii> */
/* @0x1d8824 ldr r1, [pc, #0x21c] */
/* @0x1d8828 ldrd r2, r3, [r4, #24] */
/* @0x1d882c ldr r1, [r6, r1] */
/* @0x1d8830 subs r2, r10, r2 */
/* @0x1d8834 sbc r3, r11, r3 */
/* @0x1d8838 vmov s15, r0 */
/* @0x1d883c ldrd r0, r1, [r1] */
/* @0x1d8840 cmp r0, r2 */
/* @0x1d8844 sbcs r9, r1, r3 */
/* @0x1d8848 bge 0x1d8a28 <_ZN15CGestureUnknown6UpdateEx+0x24c> */
/* @0x1d884c mov r0, #96 */
/* @0x1d8850 mov r7, #0 */
/* @0x1d8854 bl 0x27c524 <_Znwj> */
/* @0x1d8858 mov r5, r0 */
/* @0x1d885c bl 0x1d7c0c <_ZN8CGestureC2Ev> */
/* @0x1d8860 ldr lr, [pc, #0x1e4] */
/* @0x1d8864 mvn r3, #0 */
/* @0x1d8868 str r7, [r5, #0x40] */
/* @0x1d886c mov r2, #0 */
/* @0x1d8870 ldr r12, [r4, #0x40] */
/* @0x1d8874 mov r0, #12 */
/* @0x1d8878 str r3, [r5, #0x28] */
/* @0x1d887c str r7, [r5, #0x44] */
/* @0x1d8880 ldr r8, [r4, #0x28] */
/* @0x1d8884 ldr r1, [r4, #0x44] */
/* @0x1d8888 str r2, [r5, #0x58] */
/* @0x1d888c mov r2, #143 */
/* @0x1d8890 str r3, [r5, #0x2c] */
/* @0x1d8894 mov r3, #1 */
/* @0x1d8898 str r7, [r5, #0x38] */
/* @0x1d889c str r7, [r5, #0x3c] */
/* @0x1d88a0 str r7, [r5, #0x48] */
/* @0x1d88a4 str r7, [r5, #0x4c] */
/* @0x1d88a8 ldr r9, [r6, lr] */
/* @0x1d88ac ldr lr, [pc, #0x19c] */
/* @0x1d88b0 str r12, [r5, #0x30] */
/* @0x1d88b4 add r9, r9, #8 */
/* @0x1d88b8 str r12, [r5, #0x40] */
/* @0x1d88bc str lr, [sp, #0x4] */
/* @0x1d88c0 mov lr, #3 */
/* @0x1d88c4 str lr, [r5, #0x8] */
/* @0x1d88c8 ldr lr, [sp, #0x4] */
/* @0x1d88cc str r9, [r5] */
/* @0x1d88d0 str r1, [r5, #0x34] */
/* @0x1d88d4 str r1, [r5, #0x44] */
/* @0x1d88d8 str r8, [r5, #0x28] */
/* @0x1d88dc str r7, [r5, #0x14] */
/* @0x1d88e0 strd r10, r11, [r5, #24] */
/* @0x1d88e4 strd r10, r11, [r5, #32] */
/* @0x1d88e8 ldr r6, [r6, lr] */
/* @0x1d88ec ldr r1, [pc, #0x160] */
/* @0x1d88f0 ldr r12, [r6, #0x8] */
/* @0x1d88f4 add r1, pc, r1 */
/* @0x1d88f8 add r12, r12, r3 */
/* @0x1d88fc str r12, [r6, #0x8] */
/* @0x1d8900 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d8904 ldr r3, [r6, #0x4] */
/* @0x1d8908 cmp r3, r7 */
/* @0x1d890c str r5, [r0, #0x8] */
/* @0x1d8910 beq 0x1d8a14 <_ZN15CGestureUnknown6UpdateEx+0x238> */
/* @0x1d8914 str r0, [r3] */
/* @0x1d8918 str r3, [r0, #0x4] */
/* @0x1d891c str r0, [r6, #0x4] */
/* @0x1d8920 str r7, [r0] */
/* @0x1d8924 mvn r3, #0 */
/* @0x1d8928 str r3, [r4, #0x14] */
/* @0x1d892c add sp, sp, #12 */
/* @0x1d8930 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d8934 mov r0, #96 */
/* @0x1d8938 ldr r9, [pc, #0x118] */
/* @0x1d893c bl 0x27c524 <_Znwj> */
/* @0x1d8940 mov r5, r0 */
/* @0x1d8944 bl 0x1d7c0c <_ZN8CGestureC2Ev> */
/* @0x1d8948 str r7, [r5, #0x30] */
/* @0x1d894c mvn r12, #0 */
/* @0x1d8950 ldr lr, [r4, #0x30] */
/* @0x1d8954 mov r3, #0 */
/* @0x1d8958 str r12, [r5, #0x28] */
/* @0x1d895c mov r1, #1 */
/* @0x1d8960 ldr r8, [r4, #0x28] */
/* @0x1d8964 mov r0, #12 */
/* @0x1d8968 str r7, [r5, #0x34] */
/* @0x1d896c mov r2, #143 */
/* @0x1d8970 str r12, [r5, #0x2c] */
/* @0x1d8974 ldr r12, [r4, #0x34] */
/* @0x1d8978 str r7, [r5, #0x40] */
/* @0x1d897c str r7, [r5, #0x44] */
/* @0x1d8980 str r12, [sp] */
/* @0x1d8984 str r3, [r5, #0x58] */
/* @0x1d8988 mov r3, r1 */
/* @0x1d898c str r7, [r5, #0x38] */
/* @0x1d8990 str r7, [r5, #0x3c] */
/* @0x1d8994 str r7, [r5, #0x48] */
/* @0x1d8998 str r7, [r5, #0x4c] */
/* @0x1d899c ldr r9, [r6, r9] */
/* @0x1d89a0 str r9, [sp, #0x4] */
/* @0x1d89a4 ldr r9, [r4, #0x40] */
/* @0x1d89a8 ldr r12, [sp, #0x4] */
/* @0x1d89ac str r7, [r5, #0x5c] */
/* @0x1d89b0 str r9, [r5, #0x40] */
/* @0x1d89b4 add r9, r12, #8 */
/* @0x1d89b8 str r9, [r5] */
/* @0x1d89bc ldr r9, [r4, #0x44] */
/* @0x1d89c0 str r8, [r5, #0x28] */
/* @0x1d89c4 str lr, [r5, #0x30] */
/* @0x1d89c8 ldr r8, [pc, #0x80] */
/* @0x1d89cc ldr lr, [sp] */
/* @0x1d89d0 str r1, [r5, #0x8] */
/* @0x1d89d4 str r7, [r5, #0x14] */
/* @0x1d89d8 str lr, [r5, #0x34] */
/* @0x1d89dc strd r10, r11, [r5, #24] */
/* @0x1d89e0 strd r10, r11, [r5, #32] */
/* @0x1d89e4 str r9, [r5, #0x44] */
/* @0x1d89e8 ldr r6, [r6, r8] */
/* @0x1d89ec ldr r1, [pc, #0x68] */
/* @0x1d89f0 ldr r12, [r6, #0x8] */
/* @0x1d89f4 add r1, pc, r1 */
/* @0x1d89f8 add r12, r12, r3 */
/* @0x1d89fc str r12, [r6, #0x8] */
/* @0x1d8a00 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d8a04 ldr r3, [r6, #0x4] */
/* @0x1d8a08 cmp r3, #0 */
/* @0x1d8a0c str r5, [r0, #0x8] */
/* @0x1d8a10 bne 0x1d8914 <_ZN15CGestureUnknown6UpdateEx+0x138> */
/* @0x1d8a14 str r0, [r6, #0x4] */
/* @0x1d8a18 str r0, [r6] */
/* @0x1d8a1c str r3, [r0, #0x4] */
/* @0x1d8a20 str r3, [r0] */
/* @0x1d8a24 b 0x1d8924 <_ZN15CGestureUnknown6UpdateEx+0x148> */
/* @0x1d8a28 ldr r3, [pc, #0x30] */
/* @0x1d8a2c ldr r3, [r6, r3] */
/* @0x1d8a30 vldr s14, [r3] */
/* @0x1d8a34 vcmpe.f32 s15, s14 */
/* @0x1d8a38 vmrs APSR_nzcv, fpscr */
/* @0x1d8a3c bgt 0x1d884c <_ZN15CGestureUnknown6UpdateEx+0x70> */
/* @0x1d8a40 b 0x1d892c <_ZN15CGestureUnknown6UpdateEx+0x150> */
/* @0x1d8a44 eoreq r9, r1, r4, asr #8 */
/* @0x1d8a48 .word 0xffffef74 */
/* @0x1d8a4c .word 0xffffefc8 */
/* @0x1d8a50 .word 0xffffefc4 */
/* @0x1d8a54 andseq r4, r7, r12, lsr r5 */
/* @0x1d8a58 .word 0xffffefcc */
/* @0x1d8a5c andseq r4, r7, r12, lsr r4 */
/* @0x1d8a60 .word 0xffffef78 */

/* ── FUNC 0x1d8a64 · CGestureDoubleTap::Update(long long) · size=952 · insn=238 */
/* @0x1d8a64 ldr r1, [r0] */
/* @0x1d8a68 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d8a6c mov r6, r0 */
/* @0x1d8a70 sub sp, sp, #20 */
/* @0x1d8a74 ldr r1, [r1, #0x18] */
/* @0x1d8a78 mov r4, r2 */
/* @0x1d8a7c mov r5, r3 */
/* @0x1d8a80 blx r1 */
/* @0x1d8a84 ldr r1, [r6, #0x28] */
/* @0x1d8a88 mov r0, #1 */
/* @0x1d8a8c ldr r7, [pc, #0x35c] */
/* @0x1d8a90 bl 0x18c0b4 <_Z14IO_Button_Downii> */
/* @0x1d8a94 add r7, pc, r7 */
/* @0x1d8a98 subs r9, r0, #0 */
/* @0x1d8a9c beq 0x1d8ce0 <_ZN17CGestureDoubleTap6UpdateEx+0x27c> */
/* @0x1d8aa0 ldr r1, [r6, #0x4c] */
/* @0x1d8aa4 ldr r0, [r6, #0x48] */
/* @0x1d8aa8 bl 0x1d6708 <_Z14CalcDistInchesii> */
/* @0x1d8aac ldr r1, [pc, #0x340] */
/* @0x1d8ab0 ldrd r2, r3, [r6, #24] */
/* @0x1d8ab4 ldr r1, [r7, r1] */
/* @0x1d8ab8 subs r2, r4, r2 */
/* @0x1d8abc sbc r3, r5, r3 */
/* @0x1d8ac0 vmov s15, r0 */
/* @0x1d8ac4 ldrd r0, r1, [r1] */
/* @0x1d8ac8 cmp r0, r2 */
/* @0x1d8acc sbcs r12, r1, r3 */
/* @0x1d8ad0 bge 0x1d8dd4 <_ZN17CGestureDoubleTap6UpdateEx+0x370> */
/* @0x1d8ad4 ldr r3, [pc, #0x31c] */
/* @0x1d8ad8 ldr r3, [r7, r3] */
/* @0x1d8adc ldrb r9, [r3] */
/* @0x1d8ae0 cmp r9, #0 */
/* @0x1d8ae4 bne 0x1d8cd0 <_ZN17CGestureDoubleTap6UpdateEx+0x26c> */
/* @0x1d8ae8 mov r0, #96 */
/* @0x1d8aec ldr r10, [pc, #0x308] */
/* @0x1d8af0 bl 0x27c524 <_Znwj> */
/* @0x1d8af4 mov r11, #3 */
/* @0x1d8af8 mov r8, r0 */
/* @0x1d8afc bl 0x1d7c0c <_ZN8CGestureC2Ev> */
/* @0x1d8b00 str r9, [r8, #0x44] */
/* @0x1d8b04 mvn r3, #0 */
/* @0x1d8b08 ldr r1, [r6, #0x44] */
/* @0x1d8b0c mov r2, #0 */
/* @0x1d8b10 str r9, [r8, #0x40] */
/* @0x1d8b14 mov r0, #12 */
/* @0x1d8b18 ldr r12, [r6, #0x40] */
/* @0x1d8b1c str r3, [r8, #0x28] */
/* @0x1d8b20 str r2, [r8, #0x58] */
/* @0x1d8b24 mov r2, #143 */
/* @0x1d8b28 ldr lr, [r6, #0x28] */
/* @0x1d8b2c str r9, [r8, #0x38] */
/* @0x1d8b30 str r9, [r8, #0x3c] */
/* @0x1d8b34 str r9, [r8, #0x48] */
/* @0x1d8b38 str r9, [r8, #0x4c] */
/* @0x1d8b3c str r3, [r8, #0x2c] */
/* @0x1d8b40 mov r3, #1 */
/* @0x1d8b44 ldr r10, [r7, r10] */
/* @0x1d8b48 str r1, [r8, #0x34] */
/* @0x1d8b4c str r1, [r8, #0x44] */
/* @0x1d8b50 add r10, r10, #8 */
/* @0x1d8b54 ldr r1, [pc, #0x2a4] */
/* @0x1d8b58 str lr, [r8, #0x28] */
/* @0x1d8b5c str r11, [r8, #0x8] */
/* @0x1d8b60 str r10, [r8] */
/* @0x1d8b64 str r9, [r8, #0x14] */
/* @0x1d8b68 strd r4, r5, [r8, #24] */
/* @0x1d8b6c strd r4, r5, [r8, #32] */
/* @0x1d8b70 str r12, [r8, #0x30] */
/* @0x1d8b74 str r12, [r8, #0x40] */
/* @0x1d8b78 ldr r10, [r7, r1] */
/* @0x1d8b7c ldr r1, [pc, #0x280] */
/* @0x1d8b80 ldr r12, [r10, #0x8] */
/* @0x1d8b84 add r1, pc, r1 */
/* @0x1d8b88 add r12, r12, r3 */
/* @0x1d8b8c str r12, [r10, #0x8] */
/* @0x1d8b90 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d8b94 ldr r3, [r10, #0x4] */
/* @0x1d8b98 cmp r3, #0 */
/* @0x1d8b9c str r8, [r0, #0x8] */
/* @0x1d8ba0 streq r0, [r10, #0x4] */
/* @0x1d8ba4 strne r0, [r3] */
/* @0x1d8ba8 streq r0, [r10] */
/* @0x1d8bac strne r3, [r0, #0x4] */
/* @0x1d8bb0 streq r3, [r0, #0x4] */
/* @0x1d8bb4 strne r0, [r10, #0x4] */
/* @0x1d8bb8 mvn r10, #0 */
/* @0x1d8bbc streq r3, [r0] */
/* @0x1d8bc0 strne r9, [r0] */
/* @0x1d8bc4 mov r0, #16 */
/* @0x1d8bc8 bl 0x27c524 <_Znwj> */
/* @0x1d8bcc ldr lr, [r6, #0x3c] */
/* @0x1d8bd0 ldr r12, [r6] */
/* @0x1d8bd4 mov r9, #0 */
/* @0x1d8bd8 ldr r1, [r6, #0x40] */
/* @0x1d8bdc ldr r2, [r6, #0x44] */
/* @0x1d8be0 ldr r3, [r6, #0x38] */
/* @0x1d8be4 mov r8, r0 */
/* @0x1d8be8 mov r0, r6 */
/* @0x1d8bec str r9, [r8, #0x8] */
/* @0x1d8bf0 str r10, [r8, #0x4] */
/* @0x1d8bf4 str r9, [r8, #0xc] */
/* @0x1d8bf8 str r9, [r8] */
/* @0x1d8bfc str lr, [sp] */
/* @0x1d8c00 strd r4, r5, [sp, #8] */
/* @0x1d8c04 ldr r12, [r12, #0x1c] */
/* @0x1d8c08 blx r12 */
/* @0x1d8c0c ldr r1, [pc, #0x1f4] */
/* @0x1d8c10 mov r2, #0 */
/* @0x1d8c14 mov r3, #0 */
/* @0x1d8c18 add r1, pc, r1 */
/* @0x1d8c1c movt r3, #0x3ff0 */
/* @0x1d8c20 str r0, [r8, #0x4] */
/* @0x1d8c24 bl 0x20bf40 <_Z10AddToDsMapiPcd> */
/* @0x1d8c28 mov r1, r9 */
/* @0x1d8c2c ldr r0, [r8] */
/* @0x1d8c30 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib> */
/* @0x1d8c34 ldr r2, [r6, #0x40] */
/* @0x1d8c38 ldr r3, [r6, #0x44] */
/* @0x1d8c3c add r12, r6, #12 */
/* @0x1d8c40 str r9, [sp, #0x8] */
/* @0x1d8c44 vmov s15, r2 */
/* @0x1d8c48 str r12, [sp] */
/* @0x1d8c4c vcvt.f32.s32 s15, s15 */
/* @0x1d8c50 vmov r2, s15 */
/* @0x1d8c54 vmov s15, r3 */
/* @0x1d8c58 vcvt.f32.s32 s15, s15 */
/* @0x1d8c5c vmov r3, s15 */
/* @0x1d8c60 mov r1, r0 */
/* @0x1d8c64 add r0, r6, #16 */
/* @0x1d8c68 str r0, [sp, #0x4] */
/* @0x1d8c6c mov r0, #13 */
/* @0x1d8c70 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b> */
/* @0x1d8c74 ldr r3, [r6, #0xc] */
/* @0x1d8c78 ldr r12, [r6, #0x10] */
/* @0x1d8c7c mov r0, #12 */
/* @0x1d8c80 ldr r1, [pc, #0x184] */
/* @0x1d8c84 mov r2, #143 */
/* @0x1d8c88 str r3, [r8, #0x8] */
/* @0x1d8c8c mov r3, #1 */
/* @0x1d8c90 str r12, [r8, #0xc] */
/* @0x1d8c94 ldr r4, [r7, r1] */
/* @0x1d8c98 ldr r1, [pc, #0x170] */
/* @0x1d8c9c ldr r12, [r4, #0x8] */
/* @0x1d8ca0 add r1, pc, r1 */
/* @0x1d8ca4 add r12, r12, r3 */
/* @0x1d8ca8 str r12, [r4, #0x8] */
/* @0x1d8cac bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d8cb0 ldr r3, [r4, #0x4] */
/* @0x1d8cb4 cmp r3, r9 */
/* @0x1d8cb8 str r8, [r0, #0x8] */
/* @0x1d8cbc beq 0x1d8dc0 <_ZN17CGestureDoubleTap6UpdateEx+0x35c> */
/* @0x1d8cc0 str r0, [r3] */
/* @0x1d8cc4 str r3, [r0, #0x4] */
/* @0x1d8cc8 str r0, [r4, #0x4] */
/* @0x1d8ccc str r9, [r0] */
/* @0x1d8cd0 mvn r3, #0 */
/* @0x1d8cd4 str r3, [r6, #0x14] */
/* @0x1d8cd8 add sp, sp, #20 */
/* @0x1d8cdc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d8ce0 mov r0, #16 */
/* @0x1d8ce4 mov r10, #1 */
/* @0x1d8ce8 bl 0x27c524 <_Znwj> */
/* @0x1d8cec ldr lr, [r6, #0x3c] */
/* @0x1d8cf0 ldr r12, [r6] */
/* @0x1d8cf4 add r1, r6, #48 */
/* @0x1d8cf8 mvn r11, #0 */
/* @0x1d8cfc ldm r1, {r1, r2, r3} */
/* @0x1d8d00 mov r8, r0 */
/* @0x1d8d04 mov r0, r6 */
/* @0x1d8d08 str r9, [r8, #0x8] */
/* @0x1d8d0c str r9, [r8, #0xc] */
/* @0x1d8d10 stm r8, {r10, r11} */
/* @0x1d8d14 str lr, [sp] */
/* @0x1d8d18 strd r4, r5, [sp, #8] */
/* @0x1d8d1c ldr r12, [r12, #0x1c] */
/* @0x1d8d20 blx r12 */
/* @0x1d8d24 mov r1, r9 */
/* @0x1d8d28 str r0, [r8, #0x4] */
/* @0x1d8d2c ldr r0, [r8] */
/* @0x1d8d30 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib> */
/* @0x1d8d34 ldr r2, [r6, #0x30] */
/* @0x1d8d38 ldr r3, [r6, #0x34] */
/* @0x1d8d3c add r12, r6, #12 */
/* @0x1d8d40 str r9, [sp, #0x8] */
/* @0x1d8d44 vmov s15, r2 */
/* @0x1d8d48 str r12, [sp] */
/* @0x1d8d4c vcvt.f32.s32 s15, s15 */
/* @0x1d8d50 vmov r2, s15 */
/* @0x1d8d54 vmov s15, r3 */
/* @0x1d8d58 vcvt.f32.s32 s15, s15 */
/* @0x1d8d5c vmov r3, s15 */
/* @0x1d8d60 mov r1, r0 */
/* @0x1d8d64 add r0, r6, #16 */
/* @0x1d8d68 str r0, [sp, #0x4] */
/* @0x1d8d6c mov r0, #13 */
/* @0x1d8d70 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b> */
/* @0x1d8d74 ldr r2, [r6, #0xc] */
/* @0x1d8d78 ldr r12, [r6, #0x10] */
/* @0x1d8d7c mov r3, r10 */
/* @0x1d8d80 ldr r1, [pc, #0x84] */
/* @0x1d8d84 mov r0, #12 */
/* @0x1d8d88 str r2, [r8, #0x8] */
/* @0x1d8d8c mov r2, #143 */
/* @0x1d8d90 str r12, [r8, #0xc] */
/* @0x1d8d94 ldr r4, [r7, r1] */
/* @0x1d8d98 ldr r1, [pc, #0x74] */
/* @0x1d8d9c ldr r12, [r4, #0x8] */
/* @0x1d8da0 add r1, pc, r1 */
/* @0x1d8da4 add r12, r12, r10 */
/* @0x1d8da8 str r12, [r4, #0x8] */
/* @0x1d8dac bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d8db0 ldr r3, [r4, #0x4] */
/* @0x1d8db4 cmp r3, #0 */
/* @0x1d8db8 str r8, [r0, #0x8] */
/* @0x1d8dbc bne 0x1d8cc0 <_ZN17CGestureDoubleTap6UpdateEx+0x25c> */
/* @0x1d8dc0 str r0, [r4, #0x4] */
/* @0x1d8dc4 str r0, [r4] */
/* @0x1d8dc8 str r3, [r0, #0x4] */
/* @0x1d8dcc str r3, [r0] */
/* @0x1d8dd0 b 0x1d8cd0 <_ZN17CGestureDoubleTap6UpdateEx+0x26c> */
/* @0x1d8dd4 ldr r3, [pc, #0x3c] */
/* @0x1d8dd8 ldr r3, [r7, r3] */
/* @0x1d8ddc vldr s14, [r3] */
/* @0x1d8de0 vcmpe.f32 s15, s14 */
/* @0x1d8de4 vmrs APSR_nzcv, fpscr */
/* @0x1d8de8 bgt 0x1d8ad4 <_ZN17CGestureDoubleTap6UpdateEx+0x70> */
/* @0x1d8dec b 0x1d8cd8 <_ZN17CGestureDoubleTap6UpdateEx+0x274> */
/* @0x1d8df0 .word 0x002191bc */
/* @0x1d8df4 .word 0xffffef74 */
/* @0x1d8df8 .word 0xffffef9c */
/* @0x1d8dfc .word 0xffffefc8 */
/* @0x1d8e00 .word 0xffffefc4 */
/* @0x1d8e04 andseq r4, r7, r12, lsr #5 */
/* @0x1d8e08 andseq r8, r7, r4, asr r5 */
/* @0x1d8e0c .word 0xffffefb0 */
/* @0x1d8e10 mulseq r7, r0, r1 */
/* @0x1d8e14 mulseq r7, r0, r0 */
/* @0x1d8e18 .word 0xffffef78 */

/* ── FUNC 0x1d8e1c · AddSingleFingerGestures(long long) · size=400 · insn=100 */
/* @0x1d8e1c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d8e20 vpush {d8} */
/* @0x1d8e24 mov r7, #0 */
/* @0x1d8e28 vldr s16, [pc, #364] */
/* @0x1d8e2c ldr r11, [pc, #0x16c] */
/* @0x1d8e30 mov r4, r0 */
/* @0x1d8e34 mov r5, r1 */
/* @0x1d8e38 mvn r10, #0 */
/* @0x1d8e3c add r11, pc, r11 */
/* @0x1d8e40 mov r9, r7 */
/* @0x1d8e44 mov r0, #1 */
/* @0x1d8e48 mov r1, r7 */
/* @0x1d8e4c bl 0x18c0b4 <_Z14IO_Button_Downii> */
/* @0x1d8e50 cmp r0, #0 */
/* @0x1d8e54 beq 0x1d8ea4 <_Z23AddSingleFingerGesturesx+0x88> */
/* @0x1d8e58 ldr r8, [pc, #0x144] */
/* @0x1d8e5c ldr r8, [pc, r8] */
/* @0x1d8e60 ldr r6, [r8] */
/* @0x1d8e64 cmp r6, #0 */
/* @0x1d8e68 bne 0x1d8e7c <_Z23AddSingleFingerGesturesx+0x60> */
/* @0x1d8e6c b 0x1d8eb8 <_Z23AddSingleFingerGesturesx+0x9c> */
/* @0x1d8e70 ldr r6, [r6] */
/* @0x1d8e74 cmp r6, #0 */
/* @0x1d8e78 beq 0x1d8eb8 <_Z23AddSingleFingerGesturesx+0x9c> */
/* @0x1d8e7c ldr r3, [r6, #0x8] */
/* @0x1d8e80 cmp r3, #0 */
/* @0x1d8e84 beq 0x1d8eb8 <_Z23AddSingleFingerGesturesx+0x9c> */
/* @0x1d8e88 ldr r0, [r6, #0x8] */
/* @0x1d8e8c mov r1, r7 */
/* @0x1d8e90 ldr r3, [r0] */
/* @0x1d8e94 ldr r3, [r3, #0xc] */
/* @0x1d8e98 blx r3 */
/* @0x1d8e9c cmp r0, #0 */
/* @0x1d8ea0 beq 0x1d8e70 <_Z23AddSingleFingerGesturesx+0x54> */
/* @0x1d8ea4 add r7, r7, #1 */
/* @0x1d8ea8 cmp r7, #10 */
/* @0x1d8eac bne 0x1d8e44 <_Z23AddSingleFingerGesturesx+0x28> */
/* @0x1d8eb0 vpop {d8} */
/* @0x1d8eb4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d8eb8 mov r0, #96 */
/* @0x1d8ebc bl 0x27c524 <_Znwj> */
/* @0x1d8ec0 mov r6, r0 */
/* @0x1d8ec4 bl 0x1d7c0c <_ZN8CGestureC2Ev> */
/* @0x1d8ec8 ldr r3, [pc, #0xd8] */
/* @0x1d8ecc vstr s16, [r6, #88] */
/* @0x1d8ed0 str r10, [r6, #0x2c] */
/* @0x1d8ed4 mov r0, r7 */
/* @0x1d8ed8 ldr r3, [pc, r3] */
/* @0x1d8edc str r9, [r6, #0x30] */
/* @0x1d8ee0 add r3, r3, #8 */
/* @0x1d8ee4 str r9, [r6, #0x34] */
/* @0x1d8ee8 str r3, [r6] */
/* @0x1d8eec str r9, [r6, #0x38] */
/* @0x1d8ef0 str r9, [r6, #0x3c] */
/* @0x1d8ef4 str r9, [r6, #0x48] */
/* @0x1d8ef8 str r9, [r6, #0x4c] */
/* @0x1d8efc str r9, [r6, #0x40] */
/* @0x1d8f00 str r9, [r6, #0x44] */
/* @0x1d8f04 str r9, [r6, #0x8] */
/* @0x1d8f08 str r7, [r6, #0x28] */
/* @0x1d8f0c str r9, [r6, #0x14] */
/* @0x1d8f10 strd r4, r5, [r6, #24] */
/* @0x1d8f14 strd r4, r5, [r6, #32] */
/* @0x1d8f18 bl 0x159e8c <_Z12GetRawMouseXi> */
/* @0x1d8f1c str r0, [r6, #0x40] */
/* @0x1d8f20 mov r0, r7 */
/* @0x1d8f24 bl 0x159eec <_Z12GetRawMouseYi> */
/* @0x1d8f28 ldr r3, [r6, #0x40] */
/* @0x1d8f2c ldr r12, [r8, #0x8] */
/* @0x1d8f30 mov r1, r11 */
/* @0x1d8f34 str r3, [r6, #0x30] */
/* @0x1d8f38 mov r3, #1 */
/* @0x1d8f3c add r12, r12, r3 */
/* @0x1d8f40 str r12, [r8, #0x8] */
/* @0x1d8f44 mov r2, r0 */
/* @0x1d8f48 mov r0, #12 */
/* @0x1d8f4c str r2, [r6, #0x44] */
/* @0x1d8f50 str r2, [r6, #0x34] */
/* @0x1d8f54 mov r2, #143 */
/* @0x1d8f58 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d8f5c ldr r3, [r8, #0x4] */
/* @0x1d8f60 cmp r3, #0 */
/* @0x1d8f64 str r6, [r0, #0x8] */
/* @0x1d8f68 strne r0, [r3] */
/* @0x1d8f6c strne r3, [r0, #0x4] */
/* @0x1d8f70 strne r0, [r8, #0x4] */
/* @0x1d8f74 strne r9, [r0] */
/* @0x1d8f78 bne 0x1d8ea4 <_Z23AddSingleFingerGesturesx+0x88> */
/* @0x1d8f7c add r7, r7, #1 */
/* @0x1d8f80 str r0, [r8, #0x4] */
/* @0x1d8f84 cmp r7, #10 */
/* @0x1d8f88 str r0, [r8] */
/* @0x1d8f8c str r3, [r0, #0x4] */
/* @0x1d8f90 str r3, [r0] */
/* @0x1d8f94 bne 0x1d8e44 <_Z23AddSingleFingerGesturesx+0x28> */
/* @0x1d8f98 b 0x1d8eb0 <_Z23AddSingleFingerGesturesx+0x94> */
/* @0x1d8f9c andeq r0, r0, r0 */
/* @0x1d8fa0 ldrsheq r3, [r7], -r4 */
/* @0x1d8fa4 .word 0x00217db8 */
/* @0x1d8fa8 eoreq r7, r1, r8, asr #26 */

/* ── FUNC 0x1d8fac · CGestureTap::Update(long long) · size=2232 · insn=558 */
/* @0x1d8fac ldr r1, [r0] */
/* @0x1d8fb0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d8fb4 sub sp, sp, #28 */
/* @0x1d8fb8 ldr r7, [pc, #0x850] */
/* @0x1d8fbc mov r5, r3 */
/* @0x1d8fc0 ldr r1, [r1, #0x18] */
/* @0x1d8fc4 mov r6, r0 */
/* @0x1d8fc8 mov r4, r2 */
/* @0x1d8fcc blx r1 */
/* @0x1d8fd0 ldr r3, [pc, #0x83c] */
/* @0x1d8fd4 add r7, pc, r7 */
/* @0x1d8fd8 ldr r3, [r7, r3] */
/* @0x1d8fdc ldrb r8, [r3] */
/* @0x1d8fe0 cmp r8, #0 */
/* @0x1d8fe4 beq 0x1d900c <_ZN11CGestureTap6UpdateEx+0x60> */
/* @0x1d8fe8 ldr r10, [r6, #0x14] */
/* @0x1d8fec cmp r10, #0 */
/* @0x1d8ff0 beq 0x1d9268 <_ZN11CGestureTap6UpdateEx+0x2bc> */
/* @0x1d8ff4 cmp r10, #1 */
/* @0x1d8ff8 beq 0x1d9388 <_ZN11CGestureTap6UpdateEx+0x3dc> */
/* @0x1d8ffc cmp r10, #2 */
/* @0x1d9000 beq 0x1d94fc <_ZN11CGestureTap6UpdateEx+0x550> */
/* @0x1d9004 add sp, sp, #28 */
/* @0x1d9008 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d900c ldr r1, [pc, #0x804] */
/* @0x1d9010 ldrd r2, r3, [r6, #24] */
/* @0x1d9014 ldr r1, [r7, r1] */
/* @0x1d9018 subs r2, r4, r2 */
/* @0x1d901c sbc r3, r5, r3 */
/* @0x1d9020 ldrd r0, r1, [r1] */
/* @0x1d9024 cmp r0, r2 */
/* @0x1d9028 sbcs r12, r1, r3 */
/* @0x1d902c blt 0x1d9154 <_ZN11CGestureTap6UpdateEx+0x1a8> */
/* @0x1d9030 mov r0, #1 */
/* @0x1d9034 ldr r1, [r6, #0x28] */
/* @0x1d9038 bl 0x18c0b4 <_Z14IO_Button_Downii> */
/* @0x1d903c cmp r0, #0 */
/* @0x1d9040 beq 0x1d9004 <_ZN11CGestureTap6UpdateEx+0x58> */
/* @0x1d9044 ldr r3, [r6, #0x44] */
/* @0x1d9048 ldr r0, [r6, #0x30] */
/* @0x1d904c ldr r2, [r6, #0x40] */
/* @0x1d9050 ldr r1, [r6, #0x34] */
/* @0x1d9054 rsb r0, r2, r0 */
/* @0x1d9058 rsb r1, r3, r1 */
/* @0x1d905c bl 0x1d6708 <_Z14CalcDistInchesii> */
/* @0x1d9060 ldr r3, [pc, #0x7b4] */
/* @0x1d9064 ldr r3, [r7, r3] */
/* @0x1d9068 vldr s15, [r3] */
/* @0x1d906c vmov s14, r0 */
/* @0x1d9070 vcmpe.f32 s14, s15 */
/* @0x1d9074 vmrs APSR_nzcv, fpscr */
/* @0x1d9078 bmi 0x1d9764 <_ZN11CGestureTap6UpdateEx+0x7b8> */
/* @0x1d907c mov r0, #16 */
/* @0x1d9080 mvn r10, #0 */
/* @0x1d9084 bl 0x27c524 <_Znwj> */
/* @0x1d9088 ldr lr, [r6, #0x3c] */
/* @0x1d908c ldr r12, [r6] */
/* @0x1d9090 add r1, r6, #48 */
/* @0x1d9094 ldm r1, {r1, r2, r3} */
/* @0x1d9098 mov r9, r0 */
/* @0x1d909c mov r0, r6 */
/* @0x1d90a0 str r8, [r9, #0x8] */
/* @0x1d90a4 str r8, [r9, #0xc] */
/* @0x1d90a8 stm r9, {r8, r10} */
/* @0x1d90ac str lr, [sp] */
/* @0x1d90b0 strd r4, r5, [sp, #8] */
/* @0x1d90b4 ldr r12, [r12, #0x1c] */
/* @0x1d90b8 blx r12 */
/* @0x1d90bc ldr r1, [pc, #0x75c] */
/* @0x1d90c0 mov r2, #0 */
/* @0x1d90c4 mov r3, #0 */
/* @0x1d90c8 add r1, pc, r1 */
/* @0x1d90cc movt r3, #0x3ff0 */
/* @0x1d90d0 str r0, [r9, #0x4] */
/* @0x1d90d4 bl 0x20bf40 <_Z10AddToDsMapiPcd> */
/* @0x1d90d8 mov r1, r8 */
/* @0x1d90dc ldr r0, [r9] */
/* @0x1d90e0 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib> */
/* @0x1d90e4 ldr r2, [r6, #0x30] */
/* @0x1d90e8 ldr r3, [r6, #0x34] */
/* @0x1d90ec add r12, r6, #12 */
/* @0x1d90f0 str r8, [sp, #0x8] */
/* @0x1d90f4 vmov s14, r2 */
/* @0x1d90f8 str r12, [sp] */
/* @0x1d90fc vmov s15, r3 */
/* @0x1d9100 vcvt.f32.s32 s14, s14 */
/* @0x1d9104 vcvt.f32.s32 s15, s15 */
/* @0x1d9108 vmov r2, s14 */
/* @0x1d910c vmov r3, s15 */
/* @0x1d9110 mov r1, r0 */
/* @0x1d9114 add r0, r6, #16 */
/* @0x1d9118 str r0, [sp, #0x4] */
/* @0x1d911c mov r0, #13 */
/* @0x1d9120 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b> */
/* @0x1d9124 ldr r3, [r6, #0xc] */
/* @0x1d9128 ldr r12, [r6, #0x10] */
/* @0x1d912c mov r0, #12 */
/* @0x1d9130 ldr r1, [pc, #0x6ec] */
/* @0x1d9134 mov r2, #143 */
/* @0x1d9138 str r3, [r9, #0x8] */
/* @0x1d913c mov r3, #1 */
/* @0x1d9140 str r12, [r9, #0xc] */
/* @0x1d9144 ldr r4, [r7, r1] */
/* @0x1d9148 ldr r1, [pc, #0x6d8] */
/* @0x1d914c add r1, pc, r1 */
/* @0x1d9150 b 0x1d9228 <_ZN11CGestureTap6UpdateEx+0x27c> */
/* @0x1d9154 mov r0, #16 */
/* @0x1d9158 mvn r10, #0 */
/* @0x1d915c bl 0x27c524 <_Znwj> */
/* @0x1d9160 ldr lr, [r6, #0x3c] */
/* @0x1d9164 ldr r12, [r6] */
/* @0x1d9168 add r1, r6, #48 */
/* @0x1d916c ldm r1, {r1, r2, r3} */
/* @0x1d9170 mov r9, r0 */
/* @0x1d9174 mov r0, r6 */
/* @0x1d9178 str r8, [r9, #0x8] */
/* @0x1d917c str r8, [r9, #0xc] */
/* @0x1d9180 stm r9, {r8, r10} */
/* @0x1d9184 str lr, [sp] */
/* @0x1d9188 strd r4, r5, [sp, #8] */
/* @0x1d918c ldr r12, [r12, #0x1c] */
/* @0x1d9190 blx r12 */
/* @0x1d9194 ldr r1, [pc, #0x690] */
/* @0x1d9198 mov r2, #0 */
/* @0x1d919c mov r3, #0 */
/* @0x1d91a0 add r1, pc, r1 */
/* @0x1d91a4 movt r3, #0x3ff0 */
/* @0x1d91a8 str r0, [r9, #0x4] */
/* @0x1d91ac bl 0x20bf40 <_Z10AddToDsMapiPcd> */
/* @0x1d91b0 mov r1, r8 */
/* @0x1d91b4 ldr r0, [r9] */
/* @0x1d91b8 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib> */
/* @0x1d91bc ldr r2, [r6, #0x30] */
/* @0x1d91c0 ldr r3, [r6, #0x34] */
/* @0x1d91c4 add r12, r6, #12 */
/* @0x1d91c8 str r8, [sp, #0x8] */
/* @0x1d91cc vmov s14, r2 */
/* @0x1d91d0 str r12, [sp] */
/* @0x1d91d4 vmov s15, r3 */
/* @0x1d91d8 vcvt.f32.s32 s14, s14 */
/* @0x1d91dc vcvt.f32.s32 s15, s15 */
/* @0x1d91e0 vmov r2, s14 */
/* @0x1d91e4 vmov r3, s15 */
/* @0x1d91e8 mov r1, r0 */
/* @0x1d91ec add r0, r6, #16 */
/* @0x1d91f0 str r0, [sp, #0x4] */
/* @0x1d91f4 mov r0, #13 */
/* @0x1d91f8 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b> */
/* @0x1d91fc ldr r3, [r6, #0xc] */
/* @0x1d9200 ldr r12, [r6, #0x10] */
/* @0x1d9204 mov r0, #12 */
/* @0x1d9208 ldr r1, [pc, #0x614] */
/* @0x1d920c mov r2, #143 */
/* @0x1d9210 str r3, [r9, #0x8] */
/* @0x1d9214 mov r3, #1 */
/* @0x1d9218 str r12, [r9, #0xc] */
/* @0x1d921c ldr r4, [r7, r1] */
/* @0x1d9220 ldr r1, [pc, #0x608] */
/* @0x1d9224 add r1, pc, r1 */
/* @0x1d9228 ldr r12, [r4, #0x8] */
/* @0x1d922c add r12, r12, r3 */
/* @0x1d9230 str r12, [r4, #0x8] */
/* @0x1d9234 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d9238 ldr r3, [r4, #0x4] */
/* @0x1d923c cmp r3, #0 */
/* @0x1d9240 str r9, [r0, #0x8] */
/* @0x1d9244 strne r0, [r3] */
/* @0x1d9248 strne r3, [r0, #0x4] */
/* @0x1d924c strne r0, [r4, #0x4] */
/* @0x1d9250 strne r8, [r0] */
/* @0x1d9254 beq 0x1d962c <_ZN11CGestureTap6UpdateEx+0x680> */
/* @0x1d9258 mvn r3, #0 */
/* @0x1d925c str r3, [r6, #0x14] */
/* @0x1d9260 add sp, sp, #28 */
/* @0x1d9264 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d9268 mov r9, #1 */
/* @0x1d926c mov r0, #16 */
/* @0x1d9270 str r9, [r6, #0x5c] */
/* @0x1d9274 mvn r11, #0 */
/* @0x1d9278 bl 0x27c524 <_Znwj> */
/* @0x1d927c ldr lr, [r6, #0x3c] */
/* @0x1d9280 ldr r12, [r6] */
/* @0x1d9284 add r1, r6, #48 */
/* @0x1d9288 ldm r1, {r1, r2, r3} */
/* @0x1d928c mov r8, r0 */
/* @0x1d9290 mov r0, r6 */
/* @0x1d9294 str r10, [r8, #0x8] */
/* @0x1d9298 str r10, [r8, #0xc] */
/* @0x1d929c stm r8, {r10, r11} */
/* @0x1d92a0 str lr, [sp] */
/* @0x1d92a4 strd r4, r5, [sp, #8] */
/* @0x1d92a8 ldr r12, [r12, #0x1c] */
/* @0x1d92ac blx r12 */
/* @0x1d92b0 vldr s15, [r6, #92] */
/* @0x1d92b4 vcvt.f64.s32 d7, s15 */
/* @0x1d92b8 ldr r1, [pc, #0x574] */
/* @0x1d92bc add r1, pc, r1 */
/* @0x1d92c0 vmov r2, r3, d7 */
/* @0x1d92c4 str r0, [r8, #0x4] */
/* @0x1d92c8 bl 0x20bf40 <_Z10AddToDsMapiPcd> */
/* @0x1d92cc mov r1, r10 */
/* @0x1d92d0 ldr r0, [r8] */
/* @0x1d92d4 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib> */
/* @0x1d92d8 ldr r2, [r6, #0x30] */
/* @0x1d92dc ldr r3, [r6, #0x34] */
/* @0x1d92e0 add r12, r6, #12 */
/* @0x1d92e4 str r10, [sp, #0x8] */
/* @0x1d92e8 vmov s14, r2 */
/* @0x1d92ec str r12, [sp] */
/* @0x1d92f0 vmov s15, r3 */
/* @0x1d92f4 vcvt.f32.s32 s14, s14 */
/* @0x1d92f8 vcvt.f32.s32 s15, s15 */
/* @0x1d92fc vmov r2, s14 */
/* @0x1d9300 vmov r3, s15 */
/* @0x1d9304 mov r1, r0 */
/* @0x1d9308 add r0, r6, #16 */
/* @0x1d930c str r0, [sp, #0x4] */
/* @0x1d9310 mov r0, #13 */
/* @0x1d9314 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b> */
/* @0x1d9318 ldr r2, [r6, #0xc] */
/* @0x1d931c ldr r12, [r6, #0x10] */
/* @0x1d9320 mov r3, r9 */
/* @0x1d9324 ldr r1, [pc, #0x4f8] */
/* @0x1d9328 mov r0, #12 */
/* @0x1d932c str r2, [r8, #0x8] */
/* @0x1d9330 mov r2, #143 */
/* @0x1d9334 str r12, [r8, #0xc] */
/* @0x1d9338 ldr r7, [r7, r1] */
/* @0x1d933c ldr r1, [pc, #0x4f4] */
/* @0x1d9340 ldr r12, [r7, #0x8] */
/* @0x1d9344 add r1, pc, r1 */
/* @0x1d9348 add r12, r12, r9 */
/* @0x1d934c str r12, [r7, #0x8] */
/* @0x1d9350 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d9354 ldr r3, [r7, #0x4] */
/* @0x1d9358 cmp r3, #0 */
/* @0x1d935c str r8, [r0, #0x8] */
/* @0x1d9360 strne r0, [r3] */
/* @0x1d9364 strne r3, [r0, #0x4] */
/* @0x1d9368 strne r0, [r7, #0x4] */
/* @0x1d936c strne r10, [r0] */
/* @0x1d9370 beq 0x1d9750 <_ZN11CGestureTap6UpdateEx+0x7a4> */
/* @0x1d9374 mov r3, #1 */
/* @0x1d9378 strd r4, r5, [r6, #24] */
/* @0x1d937c str r3, [r6, #0x14] */
/* @0x1d9380 add sp, sp, #28 */
/* @0x1d9384 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d9388 ldr r1, [pc, #0x488] */
/* @0x1d938c ldrd r2, r3, [r6, #24] */
/* @0x1d9390 ldr r1, [r7, r1] */
/* @0x1d9394 subs r2, r4, r2 */
/* @0x1d9398 sbc r3, r5, r3 */
/* @0x1d939c ldrd r8, r9, [r1] */
/* @0x1d93a0 cmp r8, r2 */
/* @0x1d93a4 sbcs r1, r9, r3 */
/* @0x1d93a8 blt 0x1d9258 <_ZN11CGestureTap6UpdateEx+0x2ac> */
/* @0x1d93ac mov r0, r10 */
/* @0x1d93b0 ldr r1, [r6, #0x28] */
/* @0x1d93b4 bl 0x18c0b4 <_Z14IO_Button_Downii> */
/* @0x1d93b8 cmp r0, #0 */
/* @0x1d93bc beq 0x1d9004 <_ZN11CGestureTap6UpdateEx+0x58> */
/* @0x1d93c0 ldr r3, [r6, #0x44] */
/* @0x1d93c4 ldr r0, [r6, #0x30] */
/* @0x1d93c8 ldr r2, [r6, #0x40] */
/* @0x1d93cc ldr r1, [r6, #0x34] */
/* @0x1d93d0 rsb r0, r2, r0 */
/* @0x1d93d4 rsb r1, r3, r1 */
/* @0x1d93d8 bl 0x1d6708 <_Z14CalcDistInchesii> */
/* @0x1d93dc ldr r3, [pc, #0x438] */
/* @0x1d93e0 ldr r3, [r7, r3] */
/* @0x1d93e4 vldr s15, [r3] */
/* @0x1d93e8 vmov s14, r0 */
/* @0x1d93ec vcmpe.f32 s14, s15 */
/* @0x1d93f0 vmrs APSR_nzcv, fpscr */
/* @0x1d93f4 bpl 0x1d9258 <_ZN11CGestureTap6UpdateEx+0x2ac> */
/* @0x1d93f8 ldr r3, [r6, #0x5c] */
/* @0x1d93fc mov r9, #2 */
/* @0x1d9400 strd r4, r5, [r6, #24] */
/* @0x1d9404 cmp r3, #1 */
/* @0x1d9408 str r9, [r6, #0x14] */
/* @0x1d940c bne 0x1d9004 <_ZN11CGestureTap6UpdateEx+0x58> */
/* @0x1d9410 mov r0, #96 */
/* @0x1d9414 str r3, [sp, #0x14] */
/* @0x1d9418 bl 0x27c524 <_Znwj> */
/* @0x1d941c ldr r11, [pc, #0x418] */
/* @0x1d9420 mov r10, #0 */
/* @0x1d9424 mov r8, r0 */
/* @0x1d9428 bl 0x1d7c0c <_ZN8CGestureC2Ev> */
/* @0x1d942c ldr r3, [sp, #0x14] */
/* @0x1d9430 mvn r1, #0 */
/* @0x1d9434 str r10, [r8, #0x30] */
/* @0x1d9438 mov r2, #0 */
/* @0x1d943c ldr lr, [r6, #0x30] */
/* @0x1d9440 mov r0, #12 */
/* @0x1d9444 str r10, [r8, #0x34] */
/* @0x1d9448 str r2, [r8, #0x58] */
/* @0x1d944c mov r2, #143 */
/* @0x1d9450 ldr r12, [r6, #0x34] */
/* @0x1d9454 str r1, [r8, #0x28] */
/* @0x1d9458 str r10, [r8, #0x38] */
/* @0x1d945c str r10, [r8, #0x3c] */
/* @0x1d9460 str r10, [r8, #0x48] */
/* @0x1d9464 str r10, [r8, #0x4c] */
/* @0x1d9468 str r10, [r8, #0x5c] */
/* @0x1d946c str r1, [r8, #0x2c] */
/* @0x1d9470 ldr r1, [r7, r11] */
/* @0x1d9474 ldr r11, [r6, #0x28] */
/* @0x1d9478 str lr, [r8, #0x30] */
/* @0x1d947c add lr, r1, #8 */
/* @0x1d9480 str r12, [r8, #0x34] */
/* @0x1d9484 ldr r1, [pc, #0x3b4] */
/* @0x1d9488 ldr r12, [r6, #0x30] */
/* @0x1d948c ldr r6, [r6, #0x34] */
/* @0x1d9490 str lr, [r8] */
/* @0x1d9494 str r9, [r8, #0x8] */
/* @0x1d9498 str r12, [r8, #0x40] */
/* @0x1d949c str r11, [r8, #0x28] */
/* @0x1d94a0 str r10, [r8, #0x14] */
/* @0x1d94a4 strd r4, r5, [r8, #24] */
/* @0x1d94a8 strd r4, r5, [r8, #32] */
/* @0x1d94ac str r6, [r8, #0x44] */
/* @0x1d94b0 ldr r4, [r7, r1] */
/* @0x1d94b4 ldr r1, [pc, #0x388] */
/* @0x1d94b8 ldr r12, [r4, #0x8] */
/* @0x1d94bc add r1, pc, r1 */
/* @0x1d94c0 add r12, r12, #1 */
/* @0x1d94c4 str r12, [r4, #0x8] */
/* @0x1d94c8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d94cc ldr r3, [r4, #0x4] */
/* @0x1d94d0 cmp r3, r10 */
/* @0x1d94d4 str r8, [r0, #0x8] */
/* @0x1d94d8 streq r0, [r4, #0x4] */
/* @0x1d94dc strne r0, [r3] */
/* @0x1d94e0 streq r0, [r4] */
/* @0x1d94e4 strne r3, [r0, #0x4] */
/* @0x1d94e8 streq r3, [r0, #0x4] */
/* @0x1d94ec strne r0, [r4, #0x4] */
/* @0x1d94f0 streq r3, [r0] */
/* @0x1d94f4 strne r10, [r0] */
/* @0x1d94f8 b 0x1d9004 <_ZN11CGestureTap6UpdateEx+0x58> */
/* @0x1d94fc mov r0, #1 */
/* @0x1d9500 ldr r1, [r6, #0x28] */
/* @0x1d9504 bl 0x18c0b4 <_Z14IO_Button_Downii> */
/* @0x1d9508 subs r9, r0, #0 */
/* @0x1d950c beq 0x1d9640 <_ZN11CGestureTap6UpdateEx+0x694> */
/* @0x1d9510 ldr r1, [r6, #0x4c] */
/* @0x1d9514 ldr r0, [r6, #0x48] */
/* @0x1d9518 bl 0x1d6708 <_Z14CalcDistInchesii> */
/* @0x1d951c ldr r1, [pc, #0x324] */
/* @0x1d9520 ldrd r2, r3, [r6, #24] */
/* @0x1d9524 ldr r1, [r7, r1] */
/* @0x1d9528 subs r2, r4, r2 */
/* @0x1d952c sbc r3, r5, r3 */
/* @0x1d9530 vmov s15, r0 */
/* @0x1d9534 ldrd r0, r1, [r1] */
/* @0x1d9538 cmp r0, r2 */
/* @0x1d953c sbcs r12, r1, r3 */
/* @0x1d9540 blt 0x1d955c <_ZN11CGestureTap6UpdateEx+0x5b0> */
/* @0x1d9544 ldr r3, [pc, #0x300] */
/* @0x1d9548 ldr r3, [r7, r3] */
/* @0x1d954c vldr s14, [r3] */
/* @0x1d9550 vcmpe.f32 s15, s14 */
/* @0x1d9554 vmrs APSR_nzcv, fpscr */
/* @0x1d9558 ble 0x1d9004 <_ZN11CGestureTap6UpdateEx+0x58> */
/* @0x1d955c mov r0, #96 */
/* @0x1d9560 mov r9, #0 */
/* @0x1d9564 bl 0x27c524 <_Znwj> */
/* @0x1d9568 ldr r10, [pc, #0x2e0] */
/* @0x1d956c mov r11, #3 */
/* @0x1d9570 mov r8, r0 */
/* @0x1d9574 bl 0x1d7c0c <_ZN8CGestureC2Ev> */
/* @0x1d9578 str r9, [r8, #0x44] */
/* @0x1d957c mvn r3, #0 */
/* @0x1d9580 ldr r1, [r6, #0x44] */
/* @0x1d9584 mov r2, #0 */
/* @0x1d9588 str r3, [r8, #0x28] */
/* @0x1d958c mov r0, #12 */
/* @0x1d9590 ldr lr, [r6, #0x28] */
/* @0x1d9594 str r9, [r8, #0x40] */
/* @0x1d9598 str r2, [r8, #0x58] */
/* @0x1d959c mov r2, #143 */
/* @0x1d95a0 ldr r12, [r6, #0x40] */
/* @0x1d95a4 str r3, [r8, #0x2c] */
/* @0x1d95a8 mov r3, #1 */
/* @0x1d95ac str r9, [r8, #0x38] */
/* @0x1d95b0 str r9, [r8, #0x3c] */
/* @0x1d95b4 str r9, [r8, #0x48] */
/* @0x1d95b8 str r9, [r8, #0x4c] */
/* @0x1d95bc ldr r10, [r7, r10] */
/* @0x1d95c0 str r1, [r8, #0x34] */
/* @0x1d95c4 str r1, [r8, #0x44] */
/* @0x1d95c8 add r10, r10, #8 */
/* @0x1d95cc ldr r1, [pc, #0x26c] */
/* @0x1d95d0 str r11, [r8, #0x8] */
/* @0x1d95d4 str r10, [r8] */
/* @0x1d95d8 str r12, [r8, #0x30] */
/* @0x1d95dc str r12, [r8, #0x40] */
/* @0x1d95e0 str lr, [r8, #0x28] */
/* @0x1d95e4 str r9, [r8, #0x14] */
/* @0x1d95e8 strd r4, r5, [r8, #24] */
/* @0x1d95ec strd r4, r5, [r8, #32] */
/* @0x1d95f0 ldr r4, [r7, r1] */
/* @0x1d95f4 ldr r1, [pc, #0x258] */
/* @0x1d95f8 ldr r12, [r4, #0x8] */
/* @0x1d95fc add r1, pc, r1 */
/* @0x1d9600 add r12, r12, r3 */
/* @0x1d9604 str r12, [r4, #0x8] */
/* @0x1d9608 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d960c ldr r3, [r4, #0x4] */
/* @0x1d9610 cmp r3, r9 */
/* @0x1d9614 str r8, [r0, #0x8] */
/* @0x1d9618 strne r0, [r3] */
/* @0x1d961c strne r3, [r0, #0x4] */
/* @0x1d9620 strne r0, [r4, #0x4] */
/* @0x1d9624 strne r9, [r0] */
/* @0x1d9628 bne 0x1d9258 <_ZN11CGestureTap6UpdateEx+0x2ac> */
/* @0x1d962c str r0, [r4, #0x4] */
/* @0x1d9630 str r0, [r4] */
/* @0x1d9634 str r3, [r0, #0x4] */
/* @0x1d9638 str r3, [r0] */
/* @0x1d963c b 0x1d9258 <_ZN11CGestureTap6UpdateEx+0x2ac> */
/* @0x1d9640 ldr r3, [r6, #0x5c] */
/* @0x1d9644 mov r0, #16 */
/* @0x1d9648 mvn r10, #0 */
/* @0x1d964c add r3, r3, #1 */
/* @0x1d9650 str r3, [r6, #0x5c] */
/* @0x1d9654 bl 0x27c524 <_Znwj> */
/* @0x1d9658 ldr lr, [r6, #0x3c] */
/* @0x1d965c ldr r12, [r6] */
/* @0x1d9660 add r1, r6, #48 */
/* @0x1d9664 ldm r1, {r1, r2, r3} */
/* @0x1d9668 mov r8, r0 */
/* @0x1d966c mov r0, r6 */
/* @0x1d9670 str r9, [r8, #0x8] */
/* @0x1d9674 str r9, [r8, #0xc] */
/* @0x1d9678 stm r8, {r9, r10} */
/* @0x1d967c str lr, [sp] */
/* @0x1d9680 strd r4, r5, [sp, #8] */
/* @0x1d9684 ldr r12, [r12, #0x1c] */
/* @0x1d9688 blx r12 */
/* @0x1d968c vldr s15, [r6, #92] */
/* @0x1d9690 vcvt.f64.s32 d7, s15 */
/* @0x1d9694 ldr r1, [pc, #0x1bc] */
/* @0x1d9698 add r1, pc, r1 */
/* @0x1d969c vmov r2, r3, d7 */
/* @0x1d96a0 str r0, [r8, #0x4] */
/* @0x1d96a4 bl 0x20bf40 <_Z10AddToDsMapiPcd> */
/* @0x1d96a8 mov r1, r9 */
/* @0x1d96ac ldr r0, [r8] */
/* @0x1d96b0 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib> */
/* @0x1d96b4 ldr r2, [r6, #0x30] */
/* @0x1d96b8 ldr r3, [r6, #0x34] */
/* @0x1d96bc add r12, r6, #12 */
/* @0x1d96c0 str r9, [sp, #0x8] */
/* @0x1d96c4 vmov s14, r2 */
/* @0x1d96c8 str r12, [sp] */
/* @0x1d96cc vmov s15, r3 */
/* @0x1d96d0 vcvt.f32.s32 s14, s14 */
/* @0x1d96d4 vcvt.f32.s32 s15, s15 */
/* @0x1d96d8 vmov r2, s14 */
/* @0x1d96dc vmov r3, s15 */
/* @0x1d96e0 mov r1, r0 */
/* @0x1d96e4 add r0, r6, #16 */
/* @0x1d96e8 str r0, [sp, #0x4] */
/* @0x1d96ec mov r0, #13 */
/* @0x1d96f0 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b> */
/* @0x1d96f4 ldr r3, [r6, #0xc] */
/* @0x1d96f8 ldr r12, [r6, #0x10] */
/* @0x1d96fc mov r0, #12 */
/* @0x1d9700 ldr r1, [pc, #0x11c] */
/* @0x1d9704 mov r2, #143 */
/* @0x1d9708 str r3, [r8, #0x8] */
/* @0x1d970c mov r3, #1 */
/* @0x1d9710 str r12, [r8, #0xc] */
/* @0x1d9714 ldr r7, [r7, r1] */
/* @0x1d9718 ldr r1, [pc, #0x13c] */
/* @0x1d971c ldr r12, [r7, #0x8] */
/* @0x1d9720 add r1, pc, r1 */
/* @0x1d9724 add r12, r12, r3 */
/* @0x1d9728 str r12, [r7, #0x8] */
/* @0x1d972c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d9730 ldr r3, [r7, #0x4] */
/* @0x1d9734 cmp r3, #0 */
/* @0x1d9738 str r8, [r0, #0x8] */
/* @0x1d973c strne r0, [r3] */
/* @0x1d9740 strne r3, [r0, #0x4] */
/* @0x1d9744 strne r0, [r7, #0x4] */
/* @0x1d9748 strne r9, [r0] */
/* @0x1d974c bne 0x1d9374 <_ZN11CGestureTap6UpdateEx+0x3c8> */
/* @0x1d9750 str r0, [r7, #0x4] */
/* @0x1d9754 str r0, [r7] */
/* @0x1d9758 str r3, [r0, #0x4] */
/* @0x1d975c str r3, [r0] */
/* @0x1d9760 b 0x1d9374 <_ZN11CGestureTap6UpdateEx+0x3c8> */
/* @0x1d9764 mov r0, #96 */
/* @0x1d9768 ldr r10, [pc, #0xcc] */
/* @0x1d976c bl 0x27c524 <_Znwj> */
/* @0x1d9770 mov r9, r0 */
/* @0x1d9774 bl 0x1d7c0c <_ZN8CGestureC2Ev> */
/* @0x1d9778 str r8, [r9, #0x30] */
/* @0x1d977c mvn r1, #0 */
/* @0x1d9780 ldr r11, [r6, #0x30] */
/* @0x1d9784 mov r3, #0 */
/* @0x1d9788 str r8, [r9, #0x34] */
/* @0x1d978c mov lr, #2 */
/* @0x1d9790 ldr r12, [r6, #0x34] */
/* @0x1d9794 mov r0, #12 */
/* @0x1d9798 str r1, [r9, #0x28] */
/* @0x1d979c mov r2, #143 */
/* @0x1d97a0 str r3, [r9, #0x58] */
/* @0x1d97a4 mov r3, #1 */
/* @0x1d97a8 str r8, [r9, #0x38] */
/* @0x1d97ac str r8, [r9, #0x3c] */
/* @0x1d97b0 str r8, [r9, #0x48] */
/* @0x1d97b4 str r8, [r9, #0x4c] */
/* @0x1d97b8 str r8, [r9, #0x5c] */
/* @0x1d97bc str r1, [r9, #0x2c] */
/* @0x1d97c0 ldr r1, [r7, r10] */
/* @0x1d97c4 ldr r10, [r6, #0x28] */
/* @0x1d97c8 str r11, [r9, #0x30] */
/* @0x1d97cc add r11, r1, #8 */
/* @0x1d97d0 str r12, [r9, #0x34] */
/* @0x1d97d4 ldr r1, [r6, #0x34] */
/* @0x1d97d8 ldr r12, [r6, #0x30] */
/* @0x1d97dc str r11, [r9] */
/* @0x1d97e0 str r1, [r9, #0x44] */
/* @0x1d97e4 ldr r1, [pc, #0x54] */
/* @0x1d97e8 str r10, [r9, #0x28] */
/* @0x1d97ec str r8, [r9, #0x14] */
/* @0x1d97f0 strd r4, r5, [r9, #24] */
/* @0x1d97f4 strd r4, r5, [r9, #32] */
/* @0x1d97f8 str lr, [r9, #0x8] */
/* @0x1d97fc str r12, [r9, #0x40] */
/* @0x1d9800 ldr r4, [r7, r1] */
/* @0x1d9804 ldr r1, [pc, #0x54] */
/* @0x1d9808 add r1, pc, r1 */
/* @0x1d980c b 0x1d9228 <_ZN11CGestureTap6UpdateEx+0x27c> */
/* @0x1d9810 eoreq r8, r1, r12, ror r12 */
/* @0x1d9814 .word 0xffffef9c */
/* @0x1d9818 .word 0xffffef80 */
/* @0x1d981c .word 0xffffef84 */
/* @0x1d9820 andseq r8, r7, r4, lsr #1 */
/* @0x1d9824 .word 0xffffefb0 */
/* @0x1d9828 andseq r3, r7, r4, ror #25 */
/* @0x1d982c andseq r7, r7, r12, asr #31 */
/* @0x1d9830 andseq r3, r7, r12, lsl #24 */
/* @0x1d9834 ldrheq r7, [r7], -r0 */
/* @0x1d9838 andseq r3, r7, r12, ror #21 */
/* @0x1d983c .word 0xffffefd4 */
/* @0x1d9840 .word 0xffffefc4 */
/* @0x1d9844 andseq r3, r7, r4, ror r9 */
/* @0x1d9848 .word 0xffffef74 */
/* @0x1d984c .word 0xffffef78 */
/* @0x1d9850 .word 0xffffefc8 */
/* @0x1d9854 andseq r3, r7, r4, lsr r8 */
/* @0x1d9858 ldrsbeq r7, [r7], -r4 */
/* @0x1d985c andseq r3, r7, r0, lsl r7 */
/* @0x1d9860 andseq r3, r7, r8, lsr #12 */

/* ── FUNC 0x1d9864 · ConvertRawPos(float, float, int, float&, float&, float&, float&) · size=168 · insn=42 */
/* @0x1d9864 push {r4, r5, r6, r7, lr} */
/* @0x1d9868 vpush {d8} */
/* @0x1d986c cmn r2, #1 */
/* @0x1d9870 sub sp, sp, #20 */
/* @0x1d9874 mov r7, r3 */
/* @0x1d9878 vmov s17, r0 */
/* @0x1d987c vmov s16, r1 */
/* @0x1d9880 ldr r4, [sp, #0x30] */
/* @0x1d9884 ldr r6, [sp, #0x34] */
/* @0x1d9888 ldr r5, [sp, #0x38] */
/* @0x1d988c beq 0x1d98ec <_Z13ConvertRawPosffiRfS_S_S_+0x88> */
/* @0x1d9890 vcvt.s32.f32 s13, s17 */
/* @0x1d9894 add r3, sp, #12 */
/* @0x1d9898 mov r0, r2 */
/* @0x1d989c str r3, [sp] */
/* @0x1d98a0 add r3, sp, #8 */
/* @0x1d98a4 vcvt.s32.f32 s15, s16 */
/* @0x1d98a8 vmov r1, s13 */
/* @0x1d98ac vmov r2, s15 */
/* @0x1d98b0 bl 0x179d64 <_Z22GR_Window_View_ConvertiiiRiS_> */
/* @0x1d98b4 vldr s13, [sp, #8] */
/* @0x1d98b8 vcvt.f32.s32 s14, s13 */
/* @0x1d98bc vldr s13, [sp, #12] */
/* @0x1d98c0 mov r2, r6 */
/* @0x1d98c4 mov r3, r5 */
/* @0x1d98c8 vmov r0, s17 */
/* @0x1d98cc vmov r1, s16 */
/* @0x1d98d0 vcvt.f32.s32 s15, s13 */
/* @0x1d98d4 vstr s14, [r7] */
/* @0x1d98d8 vstr s15, [r4] */
/* @0x1d98dc bl 0x159f4c <_Z15ConvertRawToGUIffRfS_> */
/* @0x1d98e0 add sp, sp, #20 */
/* @0x1d98e4 vpop {d8} */
/* @0x1d98e8 pop {r4, r5, r6, r7, pc} */
/* @0x1d98ec vcvt.s32.f32 s13, s17 */
/* @0x1d98f0 add r2, sp, #8 */
/* @0x1d98f4 add r3, sp, #12 */
/* @0x1d98f8 vcvt.s32.f32 s15, s16 */
/* @0x1d98fc vmov r0, s13 */
/* @0x1d9900 vmov r1, s15 */
/* @0x1d9904 bl 0x17a6a0 <_Z23GR_Window_Views_ConvertiiRiS_> */
/* @0x1d9908 b 0x1d98b4 <_Z13ConvertRawPosffiRfS_S_S_+0x50> */

/* ── FUNC 0x1d990c · CSingleFingerGesture::GenerateMap(int, int, int, int, long long) · size=912 · insn=228 */
/* @0x1d990c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d9910 vpush {d8, d9, d10} */
/* @0x1d9914 mov r6, r1 */
/* @0x1d9918 mov r5, r2 */
/* @0x1d991c vmov s12, r6 */
/* @0x1d9920 vmov s13, r5 */
/* @0x1d9924 ldr r1, [r0, #0x2c] */
/* @0x1d9928 vcvt.f32.s32 s12, s12 */
/* @0x1d992c sub sp, sp, #364 */
/* @0x1d9930 mov r4, r0 */
/* @0x1d9934 mov r7, r3 */
/* @0x1d9938 mov r2, r1 */
/* @0x1d993c add r3, sp, #332 */
/* @0x1d9940 add r1, sp, #316 */
/* @0x1d9944 str r3, [sp] */
/* @0x1d9948 str r1, [sp, #0x8] */
/* @0x1d994c add r3, sp, #312 */
/* @0x1d9950 str r3, [sp, #0x4] */
/* @0x1d9954 add r3, sp, #328 */
/* @0x1d9958 ldr r8, [pc, #0x2ec] */
/* @0x1d995c vcvt.f32.s32 s13, s13 */
/* @0x1d9960 ldr r11, [pc, #0x2e8] */
/* @0x1d9964 vmov r0, s12 */
/* @0x1d9968 add r8, pc, r8 */
/* @0x1d996c ldr r10, [pc, #0x2e0] */
/* @0x1d9970 add r11, pc, r11 */
/* @0x1d9974 ldr r9, [pc, #0x2dc] */
/* @0x1d9978 add r10, pc, r10 */
/* @0x1d997c add r9, pc, r9 */
/* @0x1d9980 vmov r1, s13 */
/* @0x1d9984 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_> */
/* @0x1d9988 vmov s15, r7 */
/* @0x1d998c vldr s12, [sp, #424] */
/* @0x1d9990 vcvt.f32.s32 s12, s12 */
/* @0x1d9994 ldr r2, [r4, #0x2c] */
/* @0x1d9998 add r3, sp, #340 */
/* @0x1d999c str r3, [sp] */
/* @0x1d99a0 add r3, sp, #320 */
/* @0x1d99a4 str r3, [sp, #0x4] */
/* @0x1d99a8 add r3, sp, #324 */
/* @0x1d99ac str r3, [sp, #0x8] */
/* @0x1d99b0 add r3, sp, #336 */
/* @0x1d99b4 rsb r7, r7, r6 */
/* @0x1d99b8 vcvt.f32.s32 s15, s15 */
/* @0x1d99bc vmov r1, s12 */
/* @0x1d99c0 vmov r0, s15 */
/* @0x1d99c4 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_> */
/* @0x1d99c8 ldr r0, [r4, #0x40] */
/* @0x1d99cc ldr r1, [r4, #0x44] */
/* @0x1d99d0 add r12, sp, #348 */
/* @0x1d99d4 ldr r2, [r4, #0x2c] */
/* @0x1d99d8 add r3, sp, #356 */
/* @0x1d99dc vmov s13, r0 */
/* @0x1d99e0 str r3, [sp] */
/* @0x1d99e4 vmov s15, r1 */
/* @0x1d99e8 add r3, sp, #344 */
/* @0x1d99ec vcvt.f32.s32 s13, s13 */
/* @0x1d99f0 str r3, [sp, #0x4] */
/* @0x1d99f4 str r12, [sp, #0x8] */
/* @0x1d99f8 add r3, sp, #352 */
/* @0x1d99fc vcvt.f32.s32 s15, s15 */
/* @0x1d9a00 vmov r0, s13 */
/* @0x1d9a04 vmov r1, s15 */
/* @0x1d9a08 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_> */
/* @0x1d9a0c vldr s16, [sp, #328] */
/* @0x1d9a10 vldr s18, [sp, #336] */
/* @0x1d9a14 vsub.f32 s18, s16, s18 */
/* @0x1d9a18 vmov s15, r5 */
/* @0x1d9a1c ldr r1, [sp, #0x1a8] */
/* @0x1d9a20 vmov s13, r6 */
/* @0x1d9a24 ldr lr, [pc, #0x230] */
/* @0x1d9a28 rsb r1, r1, r5 */
/* @0x1d9a2c ldr r3, [pc, #0x22c] */
/* @0x1d9a30 ldr r2, [pc, #0x22c] */
/* @0x1d9a34 vldr s20, [r4, #40] */
/* @0x1d9a38 vmov s0, r1 */
/* @0x1d9a3c ldr r1, [pc, #0x224] */
/* @0x1d9a40 vldr s3, [sp, #312] */
/* @0x1d9a44 vldr s12, [sp, #332] */
/* @0x1d9a48 str r8, [sp, #0x4] */
/* @0x1d9a4c vldr s14, [sp, #340] */
/* @0x1d9a50 add lr, pc, lr */
/* @0x1d9a54 add r1, pc, r1 */
/* @0x1d9a58 str lr, [sp, #0x14] */
/* @0x1d9a5c add r3, pc, r3 */
/* @0x1d9a60 vcvt.f64.s32 d5, s15 */
/* @0x1d9a64 str r1, [sp, #0x24] */
/* @0x1d9a68 str r3, [sp, #0x34] */
/* @0x1d9a6c add r2, pc, r2 */
/* @0x1d9a70 str r2, [sp, #0x44] */
/* @0x1d9a74 mov r12, #0 */
/* @0x1d9a78 ldr r2, [r4, #0x4] */
/* @0x1d9a7c vldr s5, [sp, #316] */
/* @0x1d9a80 ldr r8, [pc, #0x1e4] */
/* @0x1d9a84 vmov s8, r7 */
/* @0x1d9a88 ldr lr, [pc, #0x1e0] */
/* @0x1d9a8c mov r0, #20 */
/* @0x1d9a90 ldr r1, [pc, #0x1dc] */
/* @0x1d9a94 add r8, pc, r8 */
/* @0x1d9a98 vcvt.f64.s32 d3, s13 */
/* @0x1d9a9c vstr d5, [sp, #72] */
/* @0x1d9aa0 ldr r3, [pc, #0x1d0] */
/* @0x1d9aa4 add lr, pc, lr */
/* @0x1d9aa8 str r8, [sp, #0x54] */
/* @0x1d9aac add r1, pc, r1 */
/* @0x1d9ab0 str lr, [sp, #0x64] */
/* @0x1d9ab4 add r3, pc, r3 */
/* @0x1d9ab8 str r1, [sp, #0x74] */
/* @0x1d9abc str r3, [sp, #0x84] */
/* @0x1d9ac0 str r12, [sp] */
/* @0x1d9ac4 vcvt.f64.f32 d5, s3 */
/* @0x1d9ac8 vstr d3, [sp, #56] */
/* @0x1d9acc str r12, [sp, #0x10] */
/* @0x1d9ad0 str r12, [sp, #0x20] */
/* @0x1d9ad4 str r12, [sp, #0x30] */
/* @0x1d9ad8 str r12, [sp, #0x40] */
/* @0x1d9adc str r12, [sp, #0x50] */
/* @0x1d9ae0 str r12, [sp, #0x60] */
/* @0x1d9ae4 vsub.f32 s14, s12, s14 */
/* @0x1d9ae8 str r12, [sp, #0x70] */
/* @0x1d9aec str r12, [sp, #0x80] */
/* @0x1d9af0 ldr r7, [pc, #0x184] */
/* @0x1d9af4 ldr r3, [pc, #0x184] */
/* @0x1d9af8 add r7, pc, r7 */
/* @0x1d9afc ldr r8, [pc, #0x180] */
/* @0x1d9b00 add r3, pc, r3 */
/* @0x1d9b04 ldr lr, [pc, #0x17c] */
/* @0x1d9b08 ldr r1, [pc, #0x17c] */
/* @0x1d9b0c add r8, pc, r8 */
/* @0x1d9b10 add lr, pc, lr */
/* @0x1d9b14 add r1, pc, r1 */
/* @0x1d9b18 vcvt.f64.s32 d10, s20 */
/* @0x1d9b1c vcvt.f64.f32 d9, s18 */
/* @0x1d9b20 vstr d10, [sp, #8] */
/* @0x1d9b24 vcvt.f64.f32 d8, s16 */
/* @0x1d9b28 vstr d9, [sp, #120] */
/* @0x1d9b2c vcvt.f64.f32 d6, s12 */
/* @0x1d9b30 vstr d8, [sp, #24] */
/* @0x1d9b34 vstr d6, [sp, #40] */
/* @0x1d9b38 vstr d5, [sp, #88] */
/* @0x1d9b3c vldr s2, [sp, #320] */
/* @0x1d9b40 vldr s4, [sp, #324] */
/* @0x1d9b44 vsub.f32 s2, s3, s2 */
/* @0x1d9b48 str r12, [sp, #0x90] */
/* @0x1d9b4c str r12, [sp, #0xa0] */
/* @0x1d9b50 vldr s10, [sp, #344] */
/* @0x1d9b54 str r12, [sp, #0xb0] */
/* @0x1d9b58 str r12, [sp, #0xc0] */
/* @0x1d9b5c str r12, [sp, #0xd0] */
/* @0x1d9b60 str r12, [sp, #0xe0] */
/* @0x1d9b64 str r12, [sp, #0xf0] */
/* @0x1d9b68 str r12, [sp, #0x100] */
/* @0x1d9b6c str r12, [sp, #0x110] */
/* @0x1d9b70 str r7, [sp, #0x94] */
/* @0x1d9b74 vsub.f32 s4, s5, s4 */
/* @0x1d9b78 vcvt.f64.f32 d6, s5 */
/* @0x1d9b7c vcvt.f64.f32 d7, s14 */
/* @0x1d9b80 vstr d6, [sp, #104] */
/* @0x1d9b84 vldr s12, [sp, #348] */
/* @0x1d9b88 vcvt.f64.s32 d4, s8 */
/* @0x1d9b8c vstr d7, [sp, #136] */
/* @0x1d9b90 vldr s14, [sp, #352] */
/* @0x1d9b94 vstr d4, [sp, #152] */
/* @0x1d9b98 vcvt.f64.s32 d0, s0 */
/* @0x1d9b9c vldr s6, [r4, #64] */
/* @0x1d9ba0 vldr s8, [r4, #68] */
/* @0x1d9ba4 str r3, [sp, #0xa4] */
/* @0x1d9ba8 ldr r3, [pc, #0xe0] */
/* @0x1d9bac str lr, [sp, #0xf4] */
/* @0x1d9bb0 str r1, [sp, #0x104] */
/* @0x1d9bb4 add r3, pc, r3 */
/* @0x1d9bb8 str r11, [sp, #0xb4] */
/* @0x1d9bbc vcvt.f64.f32 d1, s2 */
/* @0x1d9bc0 str r3, [sp, #0x114] */
/* @0x1d9bc4 vstr d0, [sp, #168] */
/* @0x1d9bc8 str r10, [sp, #0xc4] */
/* @0x1d9bcc str r9, [sp, #0xd4] */
/* @0x1d9bd0 str r8, [sp, #0xe4] */
/* @0x1d9bd4 ldr lr, [pc, #0xb8] */
/* @0x1d9bd8 ldr r1, [pc, #0xb8] */
/* @0x1d9bdc add lr, pc, lr */
/* @0x1d9be0 vcvt.f64.f32 d2, s4 */
/* @0x1d9be4 vstr d1, [sp, #184] */
/* @0x1d9be8 add r1, pc, r1 */
/* @0x1d9bec vcvt.f64.s32 d3, s6 */
/* @0x1d9bf0 vstr d2, [sp, #200] */
/* @0x1d9bf4 vcvt.f64.s32 d4, s8 */
/* @0x1d9bf8 vstr d3, [sp, #216] */
/* @0x1d9bfc vcvt.f64.f32 d5, s10 */
/* @0x1d9c00 vstr d4, [sp, #232] */
/* @0x1d9c04 vcvt.f64.f32 d6, s12 */
/* @0x1d9c08 vstr d5, [sp, #248] */
/* @0x1d9c0c str r12, [sp, #0x120] */
/* @0x1d9c10 str r12, [sp, #0x130] */
/* @0x1d9c14 str lr, [sp, #0x124] */
/* @0x1d9c18 vcvt.f64.f32 d7, s14 */
/* @0x1d9c1c vstr d6, [sp, #264] */
/* @0x1d9c20 vmov s13, r2 */
/* @0x1d9c24 vstr d7, [sp, #280] */
/* @0x1d9c28 vcvt.f64.s32 d6, s13 */
/* @0x1d9c2c vldr s14, [sp, #356] */
/* @0x1d9c30 vcvt.f64.f32 d7, s14 */
/* @0x1d9c34 vmov r2, r3, d6 */
/* @0x1d9c38 vstr d7, [sp, #296] */
/* @0x1d9c3c bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x1d9c40 add sp, sp, #364 */
/* @0x1d9c44 vpop {d8, d9, d10} */
/* @0x1d9c48 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d9c4c andseq r7, r7, r8, lsl r8 */
/* @0x1d9c50 andseq r7, r7, r0, ror r8 */
/* @0x1d9c54 andseq r7, r7, r4, ror r8 */
/* @0x1d9c58 andseq r7, r7, r12, ror r8 */
/* @0x1d9c5c andseq r7, r7, r8, lsr r7 */
/* @0x1d9c60 andseq r7, r7, r12, lsr r7 */
/* @0x1d9c64 andseq r7, r7, r4, lsr r7 */
/* @0x1d9c68 andseq r7, r7, r12, lsr r7 */
/* @0x1d9c6c andseq r7, r7, r4, lsl r7 */
/* @0x1d9c70 andseq r7, r7, r12, lsl #14 */
/* @0x1d9c74 andseq r7, r7, r12, lsl #14 */
/* @0x1d9c78 andseq r7, r7, r12, lsl #14 */
/* @0x1d9c7c ldrsbeq r7, [r7], -r0 */
/* @0x1d9c80 ldrsbeq r7, [r7], -r4 */
/* @0x1d9c84 ldrsheq r7, [r7], -r12 */
/* @0x1d9c88 andseq r7, r7, r8, lsl #14 */
/* @0x1d9c8c andseq r7, r7, r4, lsl r7 */
/* @0x1d9c90 andseq r7, r7, r4, lsl #13 */
/* @0x1d9c94 andseq r7, r7, r12, ror #12 */
/* @0x1d9c98 mulseq r7, r0, r5 */

/* ── FUNC 0x1d9c9c · CGesturePinch::Update(long long) · size=3232 · insn=808 */
/* @0x1d9c9c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d9ca0 vpush {d8, d9} */
/* @0x1d9ca4 mov r4, r0 */
/* @0x1d9ca8 sub sp, sp, #436 */
/* @0x1d9cac ldr r0, [r0, #0x28] */
/* @0x1d9cb0 bl 0x1d75f4 <_Z21GetTouchActionFromUIDi> */
/* @0x1d9cb4 mov r7, r0 */
/* @0x1d9cb8 ldr r0, [r4, #0x2c] */
/* @0x1d9cbc bl 0x1d75f4 <_Z21GetTouchActionFromUIDi> */
/* @0x1d9cc0 cmp r7, #0 */
/* @0x1d9cc4 mov r6, r0 */
/* @0x1d9cc8 beq 0x1da778 <_ZN13CGesturePinch6UpdateEx+0xadc> */
/* @0x1d9ccc ldr r12, [r7, #0x828] */
/* @0x1d9cd0 ldr r3, [r7, #0x82c] */
/* @0x1d9cd4 ldr r1, [r7] */
/* @0x1d9cd8 cmp r12, r3 */
/* @0x1d9cdc ldrb r8, [r7, #0x830] */
/* @0x1d9ce0 addne r12, r12, #63 */
/* @0x1d9ce4 andne r12, r12, #63 */
/* @0x1d9ce8 moveq r12, #0 */
/* @0x1d9cec moveq r11, r12 */
/* @0x1d9cf0 moveq r10, r12 */
/* @0x1d9cf4 addne r12, r7, r12, lsl #5 */
/* @0x1d9cf8 str r1, [sp, #0x178] */
/* @0x1d9cfc addne r12, r12, #40 */
/* @0x1d9d00 ldrne r10, [r12, #0x8] */
/* @0x1d9d04 ldrne r11, [r12, #0xc] */
/* @0x1d9d08 cmp r6, #0 */
/* @0x1d9d0c beq 0x1da798 <_ZN13CGesturePinch6UpdateEx+0xafc> */
/* @0x1d9d10 ldr r9, [r6, #0x828] */
/* @0x1d9d14 ldr r3, [r6, #0x82c] */
/* @0x1d9d18 cmp r9, r3 */
/* @0x1d9d1c beq 0x1d9d74 <_ZN13CGesturePinch6UpdateEx+0xd8> */
/* @0x1d9d20 add r9, r9, #63 */
/* @0x1d9d24 and r9, r9, #63 */
/* @0x1d9d28 add r9, r6, r9, lsl #5 */
/* @0x1d9d2c add r9, r9, #40 */
/* @0x1d9d30 ldr r3, [r9, #0x8] */
/* @0x1d9d34 ldr r1, [r9, #0xc] */
/* @0x1d9d38 str r3, [sp, #0x170] */
/* @0x1d9d3c str r1, [sp, #0x174] */
/* @0x1d9d40 ldrb r3, [r6, #0x830] */
/* @0x1d9d44 ldr r2, [r6] */
/* @0x1d9d48 cmp r3, #0 */
/* @0x1d9d4c movne r8, #1 */
/* @0x1d9d50 str r2, [sp, #0x17c] */
/* @0x1d9d54 ldr r5, [r4, #0x14] */
/* @0x1d9d58 cmp r5, #0 */
/* @0x1d9d5c beq 0x1d9d84 <_ZN13CGesturePinch6UpdateEx+0xe8> */
/* @0x1d9d60 cmp r5, #1 */
/* @0x1d9d64 beq 0x1da278 <_ZN13CGesturePinch6UpdateEx+0x5dc> */
/* @0x1d9d68 add sp, sp, #436 */
/* @0x1d9d6c vpop {d8, d9} */
/* @0x1d9d70 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d9d74 mov r9, #0 */
/* @0x1d9d78 str r9, [sp, #0x174] */
/* @0x1d9d7c str r9, [sp, #0x170] */
/* @0x1d9d80 b 0x1d9d40 <_ZN13CGesturePinch6UpdateEx+0xa4> */
/* @0x1d9d84 ldr r1, [sp, #0x170] */
/* @0x1d9d88 vmov.f32 s15, #5.000000e-01 */
/* @0x1d9d8c ldr r2, [sp, #0x174] */
/* @0x1d9d90 mov r0, #7 */
/* @0x1d9d94 add r1, r10, r1 */
/* @0x1d9d98 add r8, r4, #12 */
/* @0x1d9d9c add r2, r11, r2 */
/* @0x1d9da0 add r7, r4, #16 */
/* @0x1d9da4 vmov s14, r1 */
/* @0x1d9da8 mov r1, r5 */
/* @0x1d9dac vmov s13, r2 */
/* @0x1d9db0 mov r6, #1 */
/* @0x1d9db4 ldr r9, [pc, #0xab8] */
/* @0x1d9db8 vcvt.f32.s32 s13, s13 */
/* @0x1d9dbc vcvt.f32.s32 s14, s14 */
/* @0x1d9dc0 vmul.f32 s14, s14, s15 */
/* @0x1d9dc4 vmul.f32 s15, s13, s15 */
/* @0x1d9dc8 vstr s14, [r4, #48] */
/* @0x1d9dcc vstr s15, [r4, #52] */
/* @0x1d9dd0 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib> */
/* @0x1d9dd4 str r8, [sp] */
/* @0x1d9dd8 str r5, [sp, #0x8] */
/* @0x1d9ddc ldr r2, [r4, #0x30] */
/* @0x1d9de0 str r7, [sp, #0x4] */
/* @0x1d9de4 ldr r3, [r4, #0x34] */
/* @0x1d9de8 mov r1, r0 */
/* @0x1d9dec mov r0, #13 */
/* @0x1d9df0 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b> */
/* @0x1d9df4 mov r1, r5 */
/* @0x1d9df8 mov r0, #8 */
/* @0x1d9dfc bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib> */
/* @0x1d9e00 str r8, [sp] */
/* @0x1d9e04 str r7, [sp, #0x4] */
/* @0x1d9e08 ldr r2, [r4, #0x30] */
/* @0x1d9e0c ldr r3, [r4, #0x34] */
/* @0x1d9e10 str r6, [sp, #0x8] */
/* @0x1d9e14 mov r1, r0 */
/* @0x1d9e18 mov r0, #13 */
/* @0x1d9e1c bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b> */
/* @0x1d9e20 mov r1, r5 */
/* @0x1d9e24 mov r0, #6 */
/* @0x1d9e28 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib> */
/* @0x1d9e2c str r8, [sp] */
/* @0x1d9e30 str r7, [sp, #0x4] */
/* @0x1d9e34 ldr r2, [r4, #0x30] */
/* @0x1d9e38 str r6, [sp, #0x8] */
/* @0x1d9e3c ldr r3, [r4, #0x34] */
/* @0x1d9e40 mov r1, r0 */
/* @0x1d9e44 mov r0, #13 */
/* @0x1d9e48 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b> */
/* @0x1d9e4c mov r1, r5 */
/* @0x1d9e50 mov r0, #9 */
/* @0x1d9e54 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib> */
/* @0x1d9e58 str r8, [sp] */
/* @0x1d9e5c str r7, [sp, #0x4] */
/* @0x1d9e60 ldr r2, [r4, #0x30] */
/* @0x1d9e64 str r6, [sp, #0x8] */
/* @0x1d9e68 ldr r3, [r4, #0x34] */
/* @0x1d9e6c ldr r8, [pc, #0xa04] */
/* @0x1d9e70 add r8, pc, r8 */
/* @0x1d9e74 mov r1, r0 */
/* @0x1d9e78 mov r0, #13 */
/* @0x1d9e7c bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b> */
/* @0x1d9e80 ldr r3, [sp, #0x170] */
/* @0x1d9e84 ldr r2, [sp, #0x174] */
/* @0x1d9e88 rsb r0, r10, r3 */
/* @0x1d9e8c rsb r1, r11, r2 */
/* @0x1d9e90 bl 0x1d6708 <_Z14CalcDistInchesii> */
/* @0x1d9e94 vldr s15, [r4, #48] */
/* @0x1d9e98 vcvt.s32.f32 s15, s15 */
/* @0x1d9e9c str r0, [r4, #0x38] */
/* @0x1d9ea0 str r0, [r4, #0x3c] */
/* @0x1d9ea4 vmov r0, s15 */
/* @0x1d9ea8 vldr s15, [r4, #52] */
/* @0x1d9eac vcvt.s32.f32 s15, s15 */
/* @0x1d9eb0 vmov r1, s15 */
/* @0x1d9eb4 bl 0x17a3b8 <_Z22GR_Window_Views_Get_IDii> */
/* @0x1d9eb8 vmov s9, r10 */
/* @0x1d9ebc vmov s11, r11 */
/* @0x1d9ec0 add r3, sp, #388 */
/* @0x1d9ec4 vcvt.f32.s32 s9, s9 */
/* @0x1d9ec8 add r1, sp, #404 */
/* @0x1d9ecc vcvt.f32.s32 s11, s11 */
/* @0x1d9ed0 str r0, [r4, #0x40] */
/* @0x1d9ed4 mov r2, r0 */
/* @0x1d9ed8 str r3, [sp] */
/* @0x1d9edc add r3, sp, #400 */
/* @0x1d9ee0 vmov r0, s9 */
/* @0x1d9ee4 str r3, [sp, #0x4] */
/* @0x1d9ee8 add r3, sp, #384 */
/* @0x1d9eec str r1, [sp, #0x8] */
/* @0x1d9ef0 vmov r1, s11 */
/* @0x1d9ef4 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_> */
/* @0x1d9ef8 vldr s13, [sp, #368] */
/* @0x1d9efc vldr s14, [sp, #372] */
/* @0x1d9f00 vcvt.f32.s32 s13, s13 */
/* @0x1d9f04 ldr r2, [r4, #0x40] */
/* @0x1d9f08 add r3, sp, #396 */
/* @0x1d9f0c str r3, [sp] */
/* @0x1d9f10 add r3, sp, #408 */
/* @0x1d9f14 str r3, [sp, #0x4] */
/* @0x1d9f18 add r3, sp, #412 */
/* @0x1d9f1c str r3, [sp, #0x8] */
/* @0x1d9f20 add r3, sp, #392 */
/* @0x1d9f24 vcvt.f32.s32 s14, s14 */
/* @0x1d9f28 vmov r0, s13 */
/* @0x1d9f2c vmov r1, s14 */
/* @0x1d9f30 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_> */
/* @0x1d9f34 ldr r2, [r4, #0x40] */
/* @0x1d9f38 ldr r1, [r4, #0x34] */
/* @0x1d9f3c add r3, sp, #420 */
/* @0x1d9f40 ldr r0, [r4, #0x30] */
/* @0x1d9f44 str r3, [sp] */
/* @0x1d9f48 add r3, sp, #424 */
/* @0x1d9f4c str r3, [sp, #0x4] */
/* @0x1d9f50 add r3, sp, #428 */
/* @0x1d9f54 str r3, [sp, #0x8] */
/* @0x1d9f58 add r3, sp, #416 */
/* @0x1d9f5c bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_> */
/* @0x1d9f60 mov r0, #16 */
/* @0x1d9f64 bl 0x27c524 <_Znwj> */
/* @0x1d9f68 vldr s8, [sp, #384] */
/* @0x1d9f6c vldr s14, [sp, #400] */
/* @0x1d9f70 vldr s15, [sp, #376] */
/* @0x1d9f74 vcvt.f64.f32 d4, s8 */
/* @0x1d9f78 vldr s10, [sp, #388] */
/* @0x1d9f7c vldr s12, [sp, #404] */
/* @0x1d9f80 mvn r2, #0 */
/* @0x1d9f84 mov r3, #6 */
/* @0x1d9f88 ldr r12, [pc, #0x8ec] */
/* @0x1d9f8c ldr r1, [pc, #0x8ec] */
/* @0x1d9f90 add r12, pc, r12 */
/* @0x1d9f94 ldr lr, [pc, #0x8e8] */
/* @0x1d9f98 add r1, pc, r1 */
/* @0x1d9f9c add lr, pc, lr */
/* @0x1d9fa0 vcvt.f64.s32 d3, s15 */
/* @0x1d9fa4 vcvt.f64.f32 d7, s14 */
/* @0x1d9fa8 vcvt.f64.f32 d5, s10 */
/* @0x1d9fac vcvt.f64.f32 d6, s12 */
/* @0x1d9fb0 mov r7, r0 */
/* @0x1d9fb4 mov r0, #23 */
/* @0x1d9fb8 str r2, [r7, #0x4] */
/* @0x1d9fbc str r3, [r7] */
/* @0x1d9fc0 str r5, [r7, #0x8] */
/* @0x1d9fc4 str r5, [r7, #0xc] */
/* @0x1d9fc8 vstr d4, [sp, #40] */
/* @0x1d9fcc vstr d7, [sp, #104] */
/* @0x1d9fd0 vldr s9, [sp, #380] */
/* @0x1d9fd4 vcvt.f64.s32 d7, s9 */
/* @0x1d9fd8 ldr r2, [pc, #0x8a8] */
/* @0x1d9fdc ldr r3, [pc, #0x8a8] */
/* @0x1d9fe0 vstr d5, [sp, #56] */
/* @0x1d9fe4 str r12, [sp, #0x4] */
/* @0x1d9fe8 vmov s11, r10 */
/* @0x1d9fec str r1, [sp, #0x14] */
/* @0x1d9ff0 vmov s9, r11 */
/* @0x1d9ff4 add r2, pc, r2 */
/* @0x1d9ff8 add r3, pc, r3 */
/* @0x1d9ffc str r2, [sp, #0x24] */
/* @0x1da000 vstr d3, [sp, #8] */
/* @0x1da004 str r3, [sp, #0x34] */
/* @0x1da008 ldr r12, [pc, #0x880] */
/* @0x1da00c ldr r1, [pc, #0x880] */
/* @0x1da010 ldr r2, [pc, #0x880] */
/* @0x1da014 add r12, pc, r12 */
/* @0x1da018 ldr r3, [pc, #0x87c] */
/* @0x1da01c add r1, pc, r1 */
/* @0x1da020 str r12, [sp, #0x44] */
/* @0x1da024 add r2, pc, r2 */
/* @0x1da028 str r1, [sp, #0x54] */
/* @0x1da02c add r3, pc, r3 */
/* @0x1da030 str r5, [sp] */
/* @0x1da034 str r3, [sp, #0x74] */
/* @0x1da038 str r5, [sp, #0x10] */
/* @0x1da03c str r5, [sp, #0x20] */
/* @0x1da040 str r5, [sp, #0x30] */
/* @0x1da044 str r5, [sp, #0x40] */
/* @0x1da048 str r5, [sp, #0x50] */
/* @0x1da04c str r5, [sp, #0x60] */
/* @0x1da050 str r5, [sp, #0x70] */
/* @0x1da054 str r2, [sp, #0x64] */
/* @0x1da058 ldr r2, [r4, #0x4] */
/* @0x1da05c vstr d6, [sp, #120] */
/* @0x1da060 vstr d7, [sp, #24] */
/* @0x1da064 vcvt.f64.s32 d6, s11 */
/* @0x1da068 ldr r12, [pc, #0x830] */
/* @0x1da06c ldr r1, [pc, #0x830] */
/* @0x1da070 add r12, pc, r12 */
/* @0x1da074 ldr r3, [pc, #0x82c] */
/* @0x1da078 ldr r10, [pc, #0x82c] */
/* @0x1da07c add r1, pc, r1 */
/* @0x1da080 ldr r11, [pc, #0x828] */
/* @0x1da084 add r3, pc, r3 */
/* @0x1da088 add r10, pc, r10 */
/* @0x1da08c vcvt.f64.s32 d7, s9 */
/* @0x1da090 vstr d6, [sp, #72] */
/* @0x1da094 str r5, [sp, #0x80] */
/* @0x1da098 vldr s4, [sp, #392] */
/* @0x1da09c vldr s6, [sp, #396] */
/* @0x1da0a0 vldr s8, [sp, #408] */
/* @0x1da0a4 vldr s10, [sp, #412] */
/* @0x1da0a8 vldr s12, [sp, #416] */
/* @0x1da0ac add r11, pc, r11 */
/* @0x1da0b0 vstr d7, [sp, #88] */
/* @0x1da0b4 vcvt.f64.f32 d4, s8 */
/* @0x1da0b8 vldr s2, [r4, #48] */
/* @0x1da0bc vldr s14, [sp, #420] */
/* @0x1da0c0 str lr, [sp, #0x84] */
/* @0x1da0c4 str r12, [sp, #0xa4] */
/* @0x1da0c8 ldr lr, [pc, #0x7e4] */
/* @0x1da0cc ldr r12, [pc, #0x7e4] */
/* @0x1da0d0 str r8, [sp, #0x94] */
/* @0x1da0d4 add lr, pc, lr */
/* @0x1da0d8 vcvt.f64.f32 d1, s2 */
/* @0x1da0dc vstr d4, [sp, #200] */
/* @0x1da0e0 str r1, [sp, #0xb4] */
/* @0x1da0e4 add r12, pc, r12 */
/* @0x1da0e8 str r3, [sp, #0xc4] */
/* @0x1da0ec str r10, [sp, #0xd4] */
/* @0x1da0f0 str lr, [sp, #0xf4] */
/* @0x1da0f4 str r12, [sp, #0x104] */
/* @0x1da0f8 str r5, [sp, #0x90] */
/* @0x1da0fc vcvt.f64.f32 d2, s4 */
/* @0x1da100 vstr d1, [sp, #264] */
/* @0x1da104 str r5, [sp, #0xa0] */
/* @0x1da108 str r5, [sp, #0xb0] */
/* @0x1da10c str r5, [sp, #0xc0] */
/* @0x1da110 str r5, [sp, #0xd0] */
/* @0x1da114 str r5, [sp, #0xe0] */
/* @0x1da118 str r5, [sp, #0xf0] */
/* @0x1da11c vcvt.f64.f32 d3, s6 */
/* @0x1da120 vstr d2, [sp, #136] */
/* @0x1da124 str r5, [sp, #0x100] */
/* @0x1da128 str r11, [sp, #0xe4] */
/* @0x1da12c ldr r10, [pc, #0x788] */
/* @0x1da130 ldr r8, [pc, #0x788] */
/* @0x1da134 ldr lr, [pc, #0x788] */
/* @0x1da138 add r10, pc, r10 */
/* @0x1da13c ldr r12, [pc, #0x784] */
/* @0x1da140 add r8, pc, r8 */
/* @0x1da144 vcvt.f64.f32 d5, s10 */
/* @0x1da148 vstr d3, [sp, #152] */
/* @0x1da14c ldr r3, [pc, #0x778] */
/* @0x1da150 add lr, pc, lr */
/* @0x1da154 ldr r1, [pc, #0x774] */
/* @0x1da158 add r12, pc, r12 */
/* @0x1da15c add r3, pc, r3 */
/* @0x1da160 add r1, pc, r1 */
/* @0x1da164 vcvt.f64.f32 d6, s12 */
/* @0x1da168 vstr d5, [sp, #216] */
/* @0x1da16c vldr s11, [sp, #368] */
/* @0x1da170 vcvt.f64.f32 d7, s14 */
/* @0x1da174 vstr d6, [sp, #232] */
/* @0x1da178 vstr d7, [sp, #248] */
/* @0x1da17c vldr s9, [sp, #372] */
/* @0x1da180 vcvt.f64.s32 d7, s9 */
/* @0x1da184 str r5, [sp, #0x110] */
/* @0x1da188 vldr s10, [sp, #424] */
/* @0x1da18c vstr d7, [sp, #184] */
/* @0x1da190 vmov.f64 d7, #1.000000e+00 */
/* @0x1da194 vcvt.f64.s32 d6, s11 */
/* @0x1da198 vstr d6, [sp, #168] */
/* @0x1da19c vldr s9, [r4, #52] */
/* @0x1da1a0 vstr d7, [sp, #328] */
/* @0x1da1a4 vstr d7, [sp, #344] */
/* @0x1da1a8 vcvt.f64.f32 d7, s9 */
/* @0x1da1ac vldr s12, [sp, #428] */
/* @0x1da1b0 str r8, [sp, #0x124] */
/* @0x1da1b4 str lr, [sp, #0x134] */
/* @0x1da1b8 str r12, [sp, #0x144] */
/* @0x1da1bc str r3, [sp, #0x154] */
/* @0x1da1c0 str r5, [sp, #0x120] */
/* @0x1da1c4 str r5, [sp, #0x130] */
/* @0x1da1c8 vstr d7, [sp, #280] */
/* @0x1da1cc vmov s15, r2 */
/* @0x1da1d0 vcvt.f64.f32 d5, s10 */
/* @0x1da1d4 str r5, [sp, #0x140] */
/* @0x1da1d8 str r5, [sp, #0x150] */
/* @0x1da1dc str r5, [sp, #0x160] */
/* @0x1da1e0 str r10, [sp, #0x114] */
/* @0x1da1e4 vcvt.f64.f32 d6, s12 */
/* @0x1da1e8 vstr d5, [sp, #296] */
/* @0x1da1ec vcvt.f64.s32 d7, s15 */
/* @0x1da1f0 vstr d6, [sp, #312] */
/* @0x1da1f4 vmov r2, r3, d7 */
/* @0x1da1f8 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x1da1fc ldr r9, [pc, r9] */
/* @0x1da200 ldr r8, [r4, #0xc] */
/* @0x1da204 mov r3, r6 */
/* @0x1da208 ldr lr, [r4, #0x10] */
/* @0x1da20c mov r2, #143 */
/* @0x1da210 ldr r1, [pc, #0x6bc] */
/* @0x1da214 ldr r12, [r9, #0x8] */
/* @0x1da218 add r1, pc, r1 */
/* @0x1da21c str r8, [r7, #0x8] */
/* @0x1da220 str lr, [r7, #0xc] */
/* @0x1da224 add r12, r12, r6 */
/* @0x1da228 str r0, [r7, #0x4] */
/* @0x1da22c mov r0, #12 */
/* @0x1da230 str r12, [r9, #0x8] */
/* @0x1da234 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1da238 ldr r3, [r9, #0x4] */
/* @0x1da23c cmp r3, #0 */
/* @0x1da240 str r7, [r0, #0x8] */
/* @0x1da244 streq r0, [r9, #0x4] */
/* @0x1da248 strne r0, [r3] */
/* @0x1da24c streq r3, [r0, #0x4] */
/* @0x1da250 strne r3, [r0, #0x4] */
/* @0x1da254 streq r0, [r9] */
/* @0x1da258 strne r0, [r9, #0x4] */
/* @0x1da25c streq r3, [r0] */
/* @0x1da260 mov r3, #1 */
/* @0x1da264 strne r5, [r0] */
/* @0x1da268 str r3, [r4, #0x14] */
/* @0x1da26c add sp, sp, #436 */
/* @0x1da270 vpop {d8, d9} */
/* @0x1da274 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1da278 vmov s9, r10 */
/* @0x1da27c ldr r2, [r4, #0x40] */
/* @0x1da280 vmov s11, r11 */
/* @0x1da284 add r3, sp, #388 */
/* @0x1da288 vcvt.f32.s32 s9, s9 */
/* @0x1da28c str r3, [sp] */
/* @0x1da290 add r3, sp, #400 */
/* @0x1da294 str r3, [sp, #0x4] */
/* @0x1da298 add r3, sp, #404 */
/* @0x1da29c str r3, [sp, #0x8] */
/* @0x1da2a0 add r3, sp, #384 */
/* @0x1da2a4 str r12, [sp, #0x16c] */
/* @0x1da2a8 vcvt.f32.s32 s11, s11 */
/* @0x1da2ac vmov r0, s9 */
/* @0x1da2b0 vmov r1, s11 */
/* @0x1da2b4 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_> */
/* @0x1da2b8 vldr s13, [sp, #368] */
/* @0x1da2bc vldr s14, [sp, #372] */
/* @0x1da2c0 vcvt.f32.s32 s13, s13 */
/* @0x1da2c4 ldr r2, [r4, #0x40] */
/* @0x1da2c8 add r3, sp, #396 */
/* @0x1da2cc str r3, [sp] */
/* @0x1da2d0 add r3, sp, #408 */
/* @0x1da2d4 str r3, [sp, #0x4] */
/* @0x1da2d8 add r3, sp, #412 */
/* @0x1da2dc str r3, [sp, #0x8] */
/* @0x1da2e0 add r3, sp, #392 */
/* @0x1da2e4 vcvt.f32.s32 s14, s14 */
/* @0x1da2e8 vmov r0, s13 */
/* @0x1da2ec vmov r1, s14 */
/* @0x1da2f0 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_> */
/* @0x1da2f4 ldr r2, [r4, #0x40] */
/* @0x1da2f8 ldr r0, [r4, #0x30] */
/* @0x1da2fc add r3, sp, #420 */
/* @0x1da300 ldr r1, [r4, #0x34] */
/* @0x1da304 str r3, [sp] */
/* @0x1da308 add r3, sp, #424 */
/* @0x1da30c str r3, [sp, #0x4] */
/* @0x1da310 add r3, sp, #428 */
/* @0x1da314 str r3, [sp, #0x8] */
/* @0x1da318 add r3, sp, #416 */
/* @0x1da31c bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_> */
/* @0x1da320 cmp r8, #0 */
/* @0x1da324 ldr r12, [sp, #0x16c] */
/* @0x1da328 bne 0x1da800 <_ZN13CGesturePinch6UpdateEx+0xb64> */
/* @0x1da32c cmp r12, #0 */
/* @0x1da330 beq 0x1da86c <_ZN13CGesturePinch6UpdateEx+0xbd0> */
/* @0x1da334 ldr r3, [r7, #0x828] */
/* @0x1da338 ldr r2, [r7, #0x82c] */
/* @0x1da33c cmp r3, r2 */
/* @0x1da340 beq 0x1da380 <_ZN13CGesturePinch6UpdateEx+0x6e4> */
/* @0x1da344 add r1, r7, #40 */
/* @0x1da348 rsb r12, r1, r12 */
/* @0x1da34c lsr r12, r12, #5 */
/* @0x1da350 cmp r12, #63 */
/* @0x1da354 bhi 0x1da380 <_ZN13CGesturePinch6UpdateEx+0x6e4> */
/* @0x1da358 cmp r3, r2 */
/* @0x1da35c add r12, r12, #63 */
/* @0x1da360 and r12, r12, #63 */
/* @0x1da364 blt 0x1da7ec <_ZN13CGesturePinch6UpdateEx+0xb50> */
/* @0x1da368 cmp r2, r12 */
/* @0x1da36c bgt 0x1da380 <_ZN13CGesturePinch6UpdateEx+0x6e4> */
/* @0x1da370 cmp r3, r12 */
/* @0x1da374 ble 0x1da380 <_ZN13CGesturePinch6UpdateEx+0x6e4> */
/* @0x1da378 add r8, r7, r12, lsl #5 */
/* @0x1da37c add r8, r8, #40 */
/* @0x1da380 cmp r9, #0 */
/* @0x1da384 beq 0x1da3d0 <_ZN13CGesturePinch6UpdateEx+0x734> */
/* @0x1da388 ldr r3, [r6, #0x828] */
/* @0x1da38c ldr r2, [r6, #0x82c] */
/* @0x1da390 cmp r3, r2 */
/* @0x1da394 beq 0x1da3cc <_ZN13CGesturePinch6UpdateEx+0x730> */
/* @0x1da398 add r1, r6, #40 */
/* @0x1da39c rsb r9, r1, r9 */
/* @0x1da3a0 lsr r9, r9, #5 */
/* @0x1da3a4 cmp r9, #63 */
/* @0x1da3a8 bhi 0x1da3cc <_ZN13CGesturePinch6UpdateEx+0x730> */
/* @0x1da3ac cmp r3, r2 */
/* @0x1da3b0 add r9, r9, #63 */
/* @0x1da3b4 and r9, r9, #63 */
/* @0x1da3b8 bge 0x1da7d0 <_ZN13CGesturePinch6UpdateEx+0xb34> */
/* @0x1da3bc cmp r3, r9 */
/* @0x1da3c0 bgt 0x1da7e0 <_ZN13CGesturePinch6UpdateEx+0xb44> */
/* @0x1da3c4 cmp r2, r9 */
/* @0x1da3c8 ble 0x1da7e0 <_ZN13CGesturePinch6UpdateEx+0xb44> */
/* @0x1da3cc mov r9, #0 */
/* @0x1da3d0 cmp r8, #0 */
/* @0x1da3d4 beq 0x1da840 <_ZN13CGesturePinch6UpdateEx+0xba4> */
/* @0x1da3d8 ldr r3, [r8, #0x8] */
/* @0x1da3dc cmp r3, r10 */
/* @0x1da3e0 beq 0x1da834 <_ZN13CGesturePinch6UpdateEx+0xb98> */
/* @0x1da3e4 ldr r3, [sp, #0x170] */
/* @0x1da3e8 ldr r1, [sp, #0x174] */
/* @0x1da3ec rsb r2, r10, r3 */
/* @0x1da3f0 rsb r3, r11, r1 */
/* @0x1da3f4 vmov s9, r2 */
/* @0x1da3f8 vmov s11, r3 */
/* @0x1da3fc vcvt.f32.s32 s14, s9 */
/* @0x1da400 vcvt.f32.s32 s15, s11 */
/* @0x1da404 vcvt.s32.f32 s14, s14 */
/* @0x1da408 vcvt.s32.f32 s15, s15 */
/* @0x1da40c vmov r0, s14 */
/* @0x1da410 vmov r1, s15 */
/* @0x1da414 bl 0x1d6708 <_Z14CalcDistInchesii> */
/* @0x1da418 vldr s14, [r4, #56] */
/* @0x1da41c vcmpe.f32 s14, #0 */
/* @0x1da420 vldr s16, [r4, #60] */
/* @0x1da424 vmrs APSR_nzcv, fpscr */
/* @0x1da428 vcmpe.f32 s16, #0 */
/* @0x1da42c vmovle.f32 s18, #1.000000e+00 */
/* @0x1da430 vmov s15, r0 */
/* @0x1da434 vdivgt.f32 s18, s15, s14 */
/* @0x1da438 vmrs APSR_nzcv, fpscr */
/* @0x1da43c ble 0x1d9d68 <_ZN13CGesturePinch6UpdateEx+0xcc> */
/* @0x1da440 str r0, [r4, #0x3c] */
/* @0x1da444 vdiv.f32 s16, s15, s16 */
/* @0x1da448 vmov.f32 s15, #1.000000e+00 */
/* @0x1da44c vcmpe.f32 s16, s15 */
/* @0x1da450 vmrs APSR_nzcv, fpscr */
/* @0x1da454 ble 0x1da7b4 <_ZN13CGesturePinch6UpdateEx+0xb18> */
/* @0x1da458 mov r0, #16 */
/* @0x1da45c bl 0x27c524 <_Znwj> */
/* @0x1da460 mvn r3, #0 */
/* @0x1da464 mov r2, #8 */
/* @0x1da468 mov r6, r0 */
/* @0x1da46c vcvt.f64.f32 d8, s16 */
/* @0x1da470 str r3, [r6, #0x4] */
/* @0x1da474 str r2, [r6] */
/* @0x1da478 mov r3, #0 */
/* @0x1da47c str r3, [r6, #0x8] */
/* @0x1da480 str r3, [r6, #0xc] */
/* @0x1da484 vcvt.f64.f32 d7, s18 */
/* @0x1da488 vldr s13, [sp, #376] */
/* @0x1da48c vldr s4, [sp, #384] */
/* @0x1da490 vldr s6, [sp, #388] */
/* @0x1da494 vldr s8, [sp, #400] */
/* @0x1da498 vldr s12, [sp, #404] */
/* @0x1da49c ldr r3, [pc, #0x434] */
/* @0x1da4a0 ldr r12, [pc, #0x434] */
/* @0x1da4a4 vldr s10, [sp, #392] */
/* @0x1da4a8 add r3, pc, r3 */
/* @0x1da4ac ldr r1, [pc, #0x42c] */
/* @0x1da4b0 vcvt.f64.s32 d1, s13 */
/* @0x1da4b4 str r3, [sp, #0x4] */
/* @0x1da4b8 ldr r2, [pc, #0x424] */
/* @0x1da4bc add r12, pc, r12 */
/* @0x1da4c0 ldr r3, [pc, #0x420] */
/* @0x1da4c4 add r1, pc, r1 */
/* @0x1da4c8 str r12, [sp, #0x14] */
/* @0x1da4cc add r2, pc, r2 */
/* @0x1da4d0 str r1, [sp, #0x24] */
/* @0x1da4d4 add r3, pc, r3 */
/* @0x1da4d8 str r2, [sp, #0x34] */
/* @0x1da4dc mov r5, #0 */
/* @0x1da4e0 str r3, [sp, #0x44] */
/* @0x1da4e4 mov r0, #23 */
/* @0x1da4e8 vcvt.f64.f32 d2, s4 */
/* @0x1da4ec ldr r12, [pc, #0x3f8] */
/* @0x1da4f0 ldr r1, [pc, #0x3f8] */
/* @0x1da4f4 vstr d1, [sp, #8] */
/* @0x1da4f8 ldr r2, [pc, #0x3f4] */
/* @0x1da4fc add r12, pc, r12 */
/* @0x1da500 ldr r3, [pc, #0x3f0] */
/* @0x1da504 add r1, pc, r1 */
/* @0x1da508 str r12, [sp, #0x54] */
/* @0x1da50c add r2, pc, r2 */
/* @0x1da510 str r1, [sp, #0x64] */
/* @0x1da514 add r3, pc, r3 */
/* @0x1da518 str r2, [sp, #0x74] */
/* @0x1da51c vcvt.f64.f32 d3, s6 */
/* @0x1da520 vstr d2, [sp, #40] */
/* @0x1da524 str r3, [sp, #0x84] */
/* @0x1da528 str r5, [sp] */
/* @0x1da52c str r5, [sp, #0x10] */
/* @0x1da530 str r5, [sp, #0x20] */
/* @0x1da534 str r5, [sp, #0x30] */
/* @0x1da538 str r5, [sp, #0x40] */
/* @0x1da53c vcvt.f64.f32 d4, s8 */
/* @0x1da540 vstr d3, [sp, #56] */
/* @0x1da544 str r5, [sp, #0x50] */
/* @0x1da548 str r5, [sp, #0x60] */
/* @0x1da54c str r5, [sp, #0x70] */
/* @0x1da550 str r5, [sp, #0x80] */
/* @0x1da554 ldr r12, [pc, #0x3a0] */
/* @0x1da558 ldr r3, [pc, #0x3a0] */
/* @0x1da55c vcvt.f64.f32 d6, s12 */
/* @0x1da560 vstr d4, [sp, #104] */
/* @0x1da564 vldr s9, [sp, #380] */
/* @0x1da568 ldr r2, [r4, #0x4] */
/* @0x1da56c add r12, pc, r12 */
/* @0x1da570 add r3, pc, r3 */
/* @0x1da574 ldr lr, [pc, #0x388] */
/* @0x1da578 ldr r1, [pc, #0x388] */
/* @0x1da57c ldr r7, [pc, #0x388] */
/* @0x1da580 add lr, pc, lr */
/* @0x1da584 ldr r8, [pc, #0x384] */
/* @0x1da588 add r1, pc, r1 */
/* @0x1da58c vcvt.f64.f32 d5, s10 */
/* @0x1da590 vstr d6, [sp, #120] */
/* @0x1da594 ldr r9, [pc, #0x378] */
/* @0x1da598 add r7, pc, r7 */
/* @0x1da59c add r8, pc, r8 */
/* @0x1da5a0 add r9, pc, r9 */
/* @0x1da5a4 vcvt.f64.s32 d6, s9 */
/* @0x1da5a8 vstr d5, [sp, #136] */
/* @0x1da5ac vmov s9, r10 */
/* @0x1da5b0 vcvt.f64.s32 d5, s9 */
/* @0x1da5b4 vstr d6, [sp, #24] */
/* @0x1da5b8 vmov s9, r11 */
/* @0x1da5bc vcvt.f64.s32 d6, s9 */
/* @0x1da5c0 vstr d5, [sp, #72] */
/* @0x1da5c4 str r5, [sp, #0x90] */
/* @0x1da5c8 vldr s2, [sp, #396] */
/* @0x1da5cc vldr s4, [sp, #408] */
/* @0x1da5d0 vldr s6, [sp, #412] */
/* @0x1da5d4 vldr s8, [sp, #416] */
/* @0x1da5d8 vldr s10, [sp, #420] */
/* @0x1da5dc vstr d6, [sp, #88] */
/* @0x1da5e0 vcvt.f64.f32 d4, s8 */
/* @0x1da5e4 vldr s0, [r4, #48] */
/* @0x1da5e8 vldr s12, [r4, #52] */
/* @0x1da5ec str r12, [sp, #0xa4] */
/* @0x1da5f0 str r3, [sp, #0xb4] */
/* @0x1da5f4 ldr r12, [pc, #0x31c] */
/* @0x1da5f8 ldr r3, [pc, #0x31c] */
/* @0x1da5fc str lr, [sp, #0x94] */
/* @0x1da600 add r12, pc, r12 */
/* @0x1da604 vcvt.f64.f32 d0, s0 */
/* @0x1da608 vstr d4, [sp, #232] */
/* @0x1da60c add r3, pc, r3 */
/* @0x1da610 vldr s9, [sp, #368] */
/* @0x1da614 str r1, [sp, #0xc4] */
/* @0x1da618 str r7, [sp, #0xd4] */
/* @0x1da61c str r8, [sp, #0xe4] */
/* @0x1da620 str r9, [sp, #0xf4] */
/* @0x1da624 str r12, [sp, #0x104] */
/* @0x1da628 vcvt.f64.f32 d1, s2 */
/* @0x1da62c vstr d0, [sp, #264] */
/* @0x1da630 str r3, [sp, #0x114] */
/* @0x1da634 str r5, [sp, #0xa0] */
/* @0x1da638 str r5, [sp, #0xb0] */
/* @0x1da63c str r5, [sp, #0xc0] */
/* @0x1da640 str r5, [sp, #0xd0] */
/* @0x1da644 str r5, [sp, #0xe0] */
/* @0x1da648 vcvt.f64.f32 d2, s4 */
/* @0x1da64c vstr d1, [sp, #152] */
/* @0x1da650 str r5, [sp, #0xf0] */
/* @0x1da654 str r5, [sp, #0x100] */
/* @0x1da658 str r5, [sp, #0x110] */
/* @0x1da65c ldr r9, [pc, #0x2bc] */
/* @0x1da660 ldr r8, [pc, #0x2bc] */
/* @0x1da664 ldr lr, [pc, #0x2bc] */
/* @0x1da668 add r9, pc, r9 */
/* @0x1da66c vcvt.f64.f32 d3, s6 */
/* @0x1da670 vstr d2, [sp, #200] */
/* @0x1da674 ldr r12, [pc, #0x2b0] */
/* @0x1da678 add lr, pc, lr */
/* @0x1da67c ldr r1, [pc, #0x2ac] */
/* @0x1da680 add r8, pc, r8 */
/* @0x1da684 add r12, pc, r12 */
/* @0x1da688 ldr r7, [pc, #0x2a4] */
/* @0x1da68c add r1, pc, r1 */
/* @0x1da690 vcvt.f64.f32 d5, s10 */
/* @0x1da694 vstr d3, [sp, #216] */
/* @0x1da698 vcvt.f64.f32 d6, s12 */
/* @0x1da69c vstr d5, [sp, #248] */
/* @0x1da6a0 vstr d6, [sp, #280] */
/* @0x1da6a4 vstr d7, [sp, #344] */
/* @0x1da6a8 vmov s15, r2 */
/* @0x1da6ac str lr, [sp, #0x144] */
/* @0x1da6b0 vcvt.f64.s32 d5, s9 */
/* @0x1da6b4 vldr s9, [sp, #372] */
/* @0x1da6b8 str r12, [sp, #0x154] */
/* @0x1da6bc vstr d8, [sp, #328] */
/* @0x1da6c0 str r5, [sp, #0x120] */
/* @0x1da6c4 str r5, [sp, #0x130] */
/* @0x1da6c8 str r5, [sp, #0x140] */
/* @0x1da6cc str r5, [sp, #0x150] */
/* @0x1da6d0 str r5, [sp, #0x160] */
/* @0x1da6d4 vcvt.f64.s32 d6, s9 */
/* @0x1da6d8 vstr d5, [sp, #168] */
/* @0x1da6dc vldr s11, [sp, #428] */
/* @0x1da6e0 str r9, [sp, #0x124] */
/* @0x1da6e4 str r8, [sp, #0x134] */
/* @0x1da6e8 vcvt.f64.s32 d7, s15 */
/* @0x1da6ec vstr d6, [sp, #184] */
/* @0x1da6f0 vldr s12, [sp, #424] */
/* @0x1da6f4 vmov r2, r3, d7 */
/* @0x1da6f8 vcvt.f64.f32 d6, s12 */
/* @0x1da6fc vcvt.f64.f32 d7, s11 */
/* @0x1da700 vstr d6, [sp, #296] */
/* @0x1da704 vstr d7, [sp, #312] */
/* @0x1da708 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x1da70c ldr r1, [r4, #0x10] */
/* @0x1da710 ldr r7, [pc, r7] */
/* @0x1da714 ldr lr, [r4, #0xc] */
/* @0x1da718 mov r3, #1 */
/* @0x1da71c mov r2, #143 */
/* @0x1da720 str r1, [r6, #0xc] */
/* @0x1da724 ldr r1, [pc, #0x20c] */
/* @0x1da728 ldr r12, [r7, #0x8] */
/* @0x1da72c add r1, pc, r1 */
/* @0x1da730 str lr, [r6, #0x8] */
/* @0x1da734 add r12, r12, r3 */
/* @0x1da738 str r0, [r6, #0x4] */
/* @0x1da73c mov r0, #12 */
/* @0x1da740 str r12, [r7, #0x8] */
/* @0x1da744 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1da748 ldr r3, [r7, #0x4] */
/* @0x1da74c cmp r3, r5 */
/* @0x1da750 str r6, [r0, #0x8] */
/* @0x1da754 strne r0, [r3] */
/* @0x1da758 strne r3, [r0, #0x4] */
/* @0x1da75c strne r0, [r7, #0x4] */
/* @0x1da760 strne r5, [r0] */
/* @0x1da764 streq r0, [r7, #0x4] */
/* @0x1da768 streq r0, [r7] */
/* @0x1da76c streq r3, [r0, #0x4] */
/* @0x1da770 streq r3, [r0] */
/* @0x1da774 b 0x1d9d68 <_ZN13CGesturePinch6UpdateEx+0xcc> */
/* @0x1da778 cmp r6, #0 */
/* @0x1da77c mvn r2, #0 */
/* @0x1da780 mov r12, r7 */
/* @0x1da784 str r2, [sp, #0x178] */
/* @0x1da788 mov r8, #1 */
/* @0x1da78c mov r11, r7 */
/* @0x1da790 mov r10, r7 */
/* @0x1da794 bne 0x1d9d10 <_ZN13CGesturePinch6UpdateEx+0x74> */
/* @0x1da798 mvn r3, #0 */
/* @0x1da79c mov r9, r6 */
/* @0x1da7a0 str r3, [sp, #0x17c] */
/* @0x1da7a4 mov r8, #1 */
/* @0x1da7a8 str r6, [sp, #0x174] */
/* @0x1da7ac str r6, [sp, #0x170] */
/* @0x1da7b0 b 0x1d9d54 <_ZN13CGesturePinch6UpdateEx+0xb8> */
/* @0x1da7b4 bpl 0x1d9d68 <_ZN13CGesturePinch6UpdateEx+0xcc> */
/* @0x1da7b8 mov r0, #16 */
/* @0x1da7bc bl 0x27c524 <_Znwj> */
/* @0x1da7c0 mvn r3, #0 */
/* @0x1da7c4 mov r2, #7 */
/* @0x1da7c8 mov r6, r0 */
/* @0x1da7cc b 0x1da46c <_ZN13CGesturePinch6UpdateEx+0x7d0> */
/* @0x1da7d0 cmp r2, r9 */
/* @0x1da7d4 bgt 0x1da3cc <_ZN13CGesturePinch6UpdateEx+0x730> */
/* @0x1da7d8 cmp r3, r9 */
/* @0x1da7dc ble 0x1da3cc <_ZN13CGesturePinch6UpdateEx+0x730> */
/* @0x1da7e0 add r9, r6, r9, lsl #5 */
/* @0x1da7e4 add r9, r9, #40 */
/* @0x1da7e8 b 0x1da3d0 <_ZN13CGesturePinch6UpdateEx+0x734> */
/* @0x1da7ec cmp r3, r12 */
/* @0x1da7f0 bgt 0x1da378 <_ZN13CGesturePinch6UpdateEx+0x6dc> */
/* @0x1da7f4 cmp r2, r12 */
/* @0x1da7f8 ble 0x1da378 <_ZN13CGesturePinch6UpdateEx+0x6dc> */
/* @0x1da7fc b 0x1da380 <_ZN13CGesturePinch6UpdateEx+0x6e4> */
/* @0x1da800 mov r0, #16 */
/* @0x1da804 bl 0x27c524 <_Znwj> */
/* @0x1da808 vmov.f64 d7, #1.000000e+00 */
/* @0x1da80c mov r2, #9 */
/* @0x1da810 mvn r3, #0 */
/* @0x1da814 vmov.f64 d8, d7 */
/* @0x1da818 stm r0, {r2, r3} */
/* @0x1da81c mov r6, r0 */
/* @0x1da820 mov r2, #0 */
/* @0x1da824 str r2, [r0, #0x8] */
/* @0x1da828 str r2, [r0, #0xc] */
/* @0x1da82c str r3, [r4, #0x14] */
/* @0x1da830 b 0x1da488 <_ZN13CGesturePinch6UpdateEx+0x7ec> */
/* @0x1da834 ldr r3, [r8, #0xc] */
/* @0x1da838 cmp r3, r11 */
/* @0x1da83c bne 0x1da3e4 <_ZN13CGesturePinch6UpdateEx+0x748> */
/* @0x1da840 cmp r9, #0 */
/* @0x1da844 beq 0x1d9d68 <_ZN13CGesturePinch6UpdateEx+0xcc> */
/* @0x1da848 ldr r3, [r9, #0x8] */
/* @0x1da84c ldr r1, [sp, #0x170] */
/* @0x1da850 cmp r3, r1 */
/* @0x1da854 bne 0x1da3e4 <_ZN13CGesturePinch6UpdateEx+0x748> */
/* @0x1da858 ldr r3, [r9, #0xc] */
/* @0x1da85c ldr r2, [sp, #0x174] */
/* @0x1da860 cmp r3, r2 */
/* @0x1da864 bne 0x1da3e4 <_ZN13CGesturePinch6UpdateEx+0x748> */
/* @0x1da868 b 0x1d9d68 <_ZN13CGesturePinch6UpdateEx+0xcc> */
/* @0x1da86c mov r8, r12 */
/* @0x1da870 b 0x1da380 <_ZN13CGesturePinch6UpdateEx+0x6e4> */
/* @0x1da874 eoreq r6, r1, r4, lsl #20 */
/* @0x1da878 andseq r7, r7, r0, asr #8 */
/* @0x1da87c andseq r7, r7, r8, asr #5 */
/* @0x1da880 andseq r7, r7, r8, asr #5 */
/* @0x1da884 andseq r7, r7, r12, lsl #6 */
/* @0x1da888 andseq r7, r7, r4, ror r2 */
/* @0x1da88c andseq r7, r7, r8, ror r2 */
/* @0x1da890 andseq r7, r7, r4, ror #4 */
/* @0x1da894 andseq r7, r7, r8, ror #4 */
/* @0x1da898 andseq r7, r7, r12, ror #4 */
/* @0x1da89c andseq r7, r7, r0, ror r2 */
/* @0x1da8a0 andseq r7, r7, r8, asr #4 */
/* @0x1da8a4 andseq r7, r7, r8, asr #4 */
/* @0x1da8a8 andseq r7, r7, r12, asr #4 */
/* @0x1da8ac andseq r7, r7, r4, asr r2 */
/* @0x1da8b0 andseq r7, r7, r12, lsr r2 */
/* @0x1da8b4 andseq r7, r7, r0, lsr #4 */
/* @0x1da8b8 andseq r7, r7, r12, lsl r2 */
/* @0x1da8bc ldrsbeq r7, [r7], -r8 */
/* @0x1da8c0 andseq r7, r7, r0, ror #3 */
/* @0x1da8c4 andseq r7, r7, r0, ror #3 */
/* @0x1da8c8 andseq r7, r7, r8, ror #3 */
/* @0x1da8cc ldrsheq r7, [r7], -r4 */
/* @0x1da8d0 andseq r7, r7, r8, lsl r0 */
/* @0x1da8d4 andseq r2, r7, r8, lsl r12 */
/* @0x1da8d8 ldrheq r6, [r7], -r0 */
/* @0x1da8dc andseq r6, r7, r4, lsr #27 */
/* @0x1da8e0 andseq r6, r7, r4, lsr #27 */
/* @0x1da8e4 andseq r6, r7, r4, lsr #27 */
/* @0x1da8e8 andseq r6, r7, r4, lsr #27 */
/* @0x1da8ec andseq r6, r7, r8, lsl #27 */
/* @0x1da8f0 andseq r6, r7, r12, lsl #27 */
/* @0x1da8f4 mulseq r7, r0, sp */
/* @0x1da8f8 mulseq r7, r4, sp */
/* @0x1da8fc andseq r6, r7, r12, asr #26 */
/* @0x1da900 andseq r6, r7, r4, asr sp */
/* @0x1da904 andseq r6, r7, r0, lsr sp */
/* @0x1da908 andseq r6, r7, r8, asr #26 */
/* @0x1da90c andseq r6, r7, r4, asr #26 */
/* @0x1da910 andseq r6, r7, r12, asr #26 */
/* @0x1da914 andseq r6, r7, r4, asr sp */
/* @0x1da918 andseq r6, r7, r0, lsl #26 */
/* @0x1da91c andseq r6, r7, r4, lsl #26 */
/* @0x1da920 ldrheq r6, [r7], -r8 */
/* @0x1da924 ldrheq r6, [r7], -r0 */
/* @0x1da928 andseq r6, r7, r8, asr #25 */
/* @0x1da92c andseq r6, r7, r12, asr #25 */
/* @0x1da930 andseq r6, r7, r12, ror #21 */
/* @0x1da934 .word 0x002164f0 */
/* @0x1da938 andseq r2, r7, r4, lsl #14 */

/* ── FUNC 0x1da93c · anon_1da93c · size=0 · insn=1 */
/* @0x1da93c andeq r0, r0, r0 */

/* ── FUNC 0x1da940 · CGestureRotate::Update(long long) · size=3024 · insn=754 */
/* @0x1da940 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1da944 vpush {d8, d9, d10, d11} */
/* @0x1da948 mov r6, r0 */
/* @0x1da94c sub sp, sp, #420 */
/* @0x1da950 ldr r0, [r0, #0x28] */
/* @0x1da954 bl 0x1d75f4 <_Z21GetTouchActionFromUIDi> */
/* @0x1da958 mov r4, r0 */
/* @0x1da95c ldr r0, [r6, #0x2c] */
/* @0x1da960 bl 0x1d75f4 <_Z21GetTouchActionFromUIDi> */
/* @0x1da964 cmp r4, #0 */
/* @0x1da968 beq 0x1dafa0 <_ZN14CGestureRotate6UpdateEx+0x660> */
/* @0x1da96c ldr r3, [r4, #0x828] */
/* @0x1da970 ldr r2, [r4, #0x82c] */
/* @0x1da974 cmp r3, r2 */
/* @0x1da978 beq 0x1daf8c <_ZN14CGestureRotate6UpdateEx+0x64c> */
/* @0x1da97c add r3, r3, #63 */
/* @0x1da980 and r3, r3, #63 */
/* @0x1da984 add r3, r4, r3, lsl #5 */
/* @0x1da988 vldr s20, [r3, #56] */
/* @0x1da98c vldr s18, [r3, #60] */
/* @0x1da990 vldr s17, [r3, #48] */
/* @0x1da994 ldr r10, [r3, #0x34] */
/* @0x1da998 cmp r0, #0 */
/* @0x1da99c ldr r5, [r4] */
/* @0x1da9a0 ldrb r8, [r4, #0x830] */
/* @0x1da9a4 beq 0x1dafc0 <_ZN14CGestureRotate6UpdateEx+0x680> */
/* @0x1da9a8 ldr r3, [r0, #0x828] */
/* @0x1da9ac ldr r2, [r0, #0x82c] */
/* @0x1da9b0 cmp r3, r2 */
/* @0x1da9b4 beq 0x1daf78 <_ZN14CGestureRotate6UpdateEx+0x638> */
/* @0x1da9b8 add r3, r3, #63 */
/* @0x1da9bc and r3, r3, #63 */
/* @0x1da9c0 add r3, r0, r3, lsl #5 */
/* @0x1da9c4 vldr s21, [r3, #56] */
/* @0x1da9c8 vldr s19, [r3, #60] */
/* @0x1da9cc vldr s16, [r3, #48] */
/* @0x1da9d0 ldr r9, [r3, #0x34] */
/* @0x1da9d4 ldrb r3, [r0, #0x830] */
/* @0x1da9d8 ldr r0, [r0] */
/* @0x1da9dc cmp r3, #0 */
/* @0x1da9e0 movne r8, #1 */
/* @0x1da9e4 str r0, [sp, #0x16c] */
/* @0x1da9e8 ldr r7, [r6, #0x14] */
/* @0x1da9ec cmp r7, #0 */
/* @0x1da9f0 beq 0x1daa08 <_ZN14CGestureRotate6UpdateEx+0xc8> */
/* @0x1da9f4 cmp r7, #1 */
/* @0x1da9f8 beq 0x1dafe0 <_ZN14CGestureRotate6UpdateEx+0x6a0> */
/* @0x1da9fc add sp, sp, #420 */
/* @0x1daa00 vpop {d8, d9, d10, d11} */
/* @0x1daa04 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1daa08 vmov r1, s17 */
/* @0x1daa0c mov r0, #11 */
/* @0x1daa10 vmov r3, s16 */
/* @0x1daa14 add r4, r6, #12 */
/* @0x1daa18 vmov.f32 s15, #5.000000e-01 */
/* @0x1daa1c add r8, r6, #16 */
/* @0x1daa20 mov r11, #1 */
/* @0x1daa24 add r2, r1, r3 */
/* @0x1daa28 add r3, r10, r9 */
/* @0x1daa2c mov r1, r7 */
/* @0x1daa30 vmov s10, r2 */
/* @0x1daa34 vmov s11, r3 */
/* @0x1daa38 vcvt.f32.s32 s14, s10 */
/* @0x1daa3c vcvt.f32.s32 s13, s11 */
/* @0x1daa40 vmul.f32 s14, s14, s15 */
/* @0x1daa44 vmul.f32 s15, s13, s15 */
/* @0x1daa48 vstr s14, [r6, #48] */
/* @0x1daa4c vstr s15, [r6, #52] */
/* @0x1daa50 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib> */
/* @0x1daa54 str r7, [sp, #0x8] */
/* @0x1daa58 str r4, [sp] */
/* @0x1daa5c ldr r2, [r6, #0x30] */
/* @0x1daa60 str r8, [sp, #0x4] */
/* @0x1daa64 ldr r3, [r6, #0x34] */
/* @0x1daa68 mov r1, r0 */
/* @0x1daa6c mov r0, #13 */
/* @0x1daa70 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b> */
/* @0x1daa74 mov r1, r7 */
/* @0x1daa78 mov r0, #10 */
/* @0x1daa7c bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib> */
/* @0x1daa80 stm sp, {r4, r8} */
/* @0x1daa84 ldr r2, [r6, #0x30] */
/* @0x1daa88 ldr r3, [r6, #0x34] */
/* @0x1daa8c str r11, [sp, #0x8] */
/* @0x1daa90 mov r1, r0 */
/* @0x1daa94 mov r0, #13 */
/* @0x1daa98 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b> */
/* @0x1daa9c mov r1, r7 */
/* @0x1daaa0 mov r0, #12 */
/* @0x1daaa4 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib> */
/* @0x1daaa8 stm sp, {r4, r8} */
/* @0x1daaac ldr r2, [r6, #0x30] */
/* @0x1daab0 str r11, [sp, #0x8] */
/* @0x1daab4 ldr r3, [r6, #0x34] */
/* @0x1daab8 mov r1, r0 */
/* @0x1daabc mov r0, #13 */
/* @0x1daac0 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b> */
/* @0x1daac4 vsub.f32 s18, s19, s18 */
/* @0x1daac8 vmul.f32 s15, s18, s18 */
/* @0x1daacc vsub.f32 s21, s21, s20 */
/* @0x1daad0 vmla.f32 s15, s21, s21 */
/* @0x1daad4 vsqrt.f32 s20, s15 */
/* @0x1daad8 vcmp.f32 s20, s20 */
/* @0x1daadc vmrs APSR_nzcv, fpscr */
/* @0x1daae0 bne 0x1db474 <_ZN14CGestureRotate6UpdateEx+0xb34> */
/* @0x1daae4 vcmpe.f32 s20, #0 */
/* @0x1daae8 vmrs APSR_nzcv, fpscr */
/* @0x1daaec ble 0x1dab20 <_ZN14CGestureRotate6UpdateEx+0x1e0> */
/* @0x1daaf0 vdiv.f32 s18, s18, s20 */
/* @0x1daaf4 vmov r0, s18 */
/* @0x1daaf8 bl 0xb6760 <acosf@plt> */
/* @0x1daafc vdiv.f32 s20, s21, s20 */
/* @0x1dab00 vmov s15, r0 */
/* @0x1dab04 vcmpe.f32 s20, #0 */
/* @0x1dab08 vmrs APSR_nzcv, fpscr */
/* @0x1dab0c vldrmi s14, [pc, #1008] */
/* @0x1dab10 vsubmi.f32 s15, s14, s15 */
/* @0x1dab14 vaddmi.f32 s15, s15, s14 */
/* @0x1dab18 vstr s15, [r6, #56] */
/* @0x1dab1c vstr s15, [r6, #60] */
/* @0x1dab20 vldr s14, [r6, #48] */
/* @0x1dab24 vldr s15, [r6, #52] */
/* @0x1dab28 vcvt.s32.f32 s14, s14 */
/* @0x1dab2c mov r7, #0 */
/* @0x1dab30 mov r4, #0 */
/* @0x1dab34 ldr r11, [pc, #0x3cc] */
/* @0x1dab38 vcvt.s32.f32 s15, s15 */
/* @0x1dab3c vmov r0, s14 */
/* @0x1dab40 vmov r1, s15 */
/* @0x1dab44 bl 0x17a3b8 <_Z22GR_Window_Views_Get_IDii> */
/* @0x1dab48 vmov s13, r10 */
/* @0x1dab4c vcvt.f32.s32 s12, s17 */
/* @0x1dab50 add r3, sp, #372 */
/* @0x1dab54 add r1, sp, #388 */
/* @0x1dab58 vcvt.f32.s32 s13, s13 */
/* @0x1dab5c str r0, [r6, #0x44] */
/* @0x1dab60 mov r2, r0 */
/* @0x1dab64 str r3, [sp] */
/* @0x1dab68 add r3, sp, #384 */
/* @0x1dab6c vmov r0, s12 */
/* @0x1dab70 str r3, [sp, #0x4] */
/* @0x1dab74 add r3, sp, #368 */
/* @0x1dab78 str r1, [sp, #0x8] */
/* @0x1dab7c vmov r1, s13 */
/* @0x1dab80 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_> */
/* @0x1dab84 vmov s15, r9 */
/* @0x1dab88 vcvt.f32.s32 s14, s16 */
/* @0x1dab8c ldr r2, [r6, #0x44] */
/* @0x1dab90 add r3, sp, #380 */
/* @0x1dab94 str r3, [sp] */
/* @0x1dab98 add r3, sp, #392 */
/* @0x1dab9c str r3, [sp, #0x4] */
/* @0x1daba0 add r3, sp, #396 */
/* @0x1daba4 str r3, [sp, #0x8] */
/* @0x1daba8 add r3, sp, #376 */
/* @0x1dabac vcvt.f32.s32 s15, s15 */
/* @0x1dabb0 vmov r0, s14 */
/* @0x1dabb4 vmov r1, s15 */
/* @0x1dabb8 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_> */
/* @0x1dabbc ldr r2, [r6, #0x44] */
/* @0x1dabc0 ldr r1, [r6, #0x34] */
/* @0x1dabc4 add r3, sp, #404 */
/* @0x1dabc8 ldr r0, [r6, #0x30] */
/* @0x1dabcc str r3, [sp] */
/* @0x1dabd0 add r3, sp, #408 */
/* @0x1dabd4 str r3, [sp, #0x4] */
/* @0x1dabd8 add r3, sp, #412 */
/* @0x1dabdc str r3, [sp, #0x8] */
/* @0x1dabe0 add r3, sp, #400 */
/* @0x1dabe4 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_> */
/* @0x1dabe8 mov r0, #16 */
/* @0x1dabec bl 0x27c524 <_Znwj> */
/* @0x1dabf0 vldr s14, [sp, #384] */
/* @0x1dabf4 vcvt.f64.f32 d7, s14 */
/* @0x1dabf8 vldr s6, [sp, #368] */
/* @0x1dabfc vmov s10, r5 */
/* @0x1dac00 vldr s8, [sp, #372] */
/* @0x1dac04 mvn r3, #0 */
/* @0x1dac08 ldr r2, [pc, #0x2fc] */
/* @0x1dac0c vldr s12, [sp, #364] */
/* @0x1dac10 mov r1, #10 */
/* @0x1dac14 add r2, pc, r2 */
/* @0x1dac18 ldr r12, [pc, #0x2f0] */
/* @0x1dac1c ldr lr, [pc, #0x2f0] */
/* @0x1dac20 mov r5, #0 */
/* @0x1dac24 add r12, pc, r12 */
/* @0x1dac28 vcvt.f64.s32 d2, s10 */
/* @0x1dac2c vldr s10, [sp, #388] */
/* @0x1dac30 add lr, pc, lr */
/* @0x1dac34 vcvt.f64.f32 d3, s6 */
/* @0x1dac38 vcvt.f64.f32 d4, s8 */
/* @0x1dac3c vcvt.f64.f32 d5, s10 */
/* @0x1dac40 mov r8, r0 */
/* @0x1dac44 mov r0, #23 */
/* @0x1dac48 str r3, [r8, #0x4] */
/* @0x1dac4c ldr r3, [pc, #0x2c4] */
/* @0x1dac50 str r1, [r8] */
/* @0x1dac54 str r7, [r8, #0x8] */
/* @0x1dac58 add r3, pc, r3 */
/* @0x1dac5c str r7, [r8, #0xc] */
/* @0x1dac60 vstr d7, [sp, #104] */
/* @0x1dac64 vcvt.f64.s32 d7, s12 */
/* @0x1dac68 str r2, [sp, #0x4] */
/* @0x1dac6c str r3, [sp, #0x14] */
/* @0x1dac70 vstr d2, [sp, #8] */
/* @0x1dac74 ldr r1, [pc, #0x2a0] */
/* @0x1dac78 vstr d3, [sp, #40] */
/* @0x1dac7c ldr r2, [pc, #0x29c] */
/* @0x1dac80 vstr d4, [sp, #56] */
/* @0x1dac84 ldr r3, [pc, #0x298] */
/* @0x1dac88 add r1, pc, r1 */
/* @0x1dac8c add r2, pc, r2 */
/* @0x1dac90 str r1, [sp, #0x24] */
/* @0x1dac94 str r2, [sp, #0x34] */
/* @0x1dac98 add r3, pc, r3 */
/* @0x1dac9c ldr r1, [pc, #0x284] */
/* @0x1daca0 vcvt.f64.s32 d6, s17 */
/* @0x1daca4 str r3, [sp, #0x44] */
/* @0x1daca8 ldr r2, [pc, #0x27c] */
/* @0x1dacac add r1, pc, r1 */
/* @0x1dacb0 ldr r3, [pc, #0x278] */
/* @0x1dacb4 str r1, [sp, #0x54] */
/* @0x1dacb8 add r2, pc, r2 */
/* @0x1dacbc str r7, [sp] */
/* @0x1dacc0 add r3, pc, r3 */
/* @0x1dacc4 str r7, [sp, #0x10] */
/* @0x1dacc8 str r3, [sp, #0x74] */
/* @0x1daccc str r7, [sp, #0x20] */
/* @0x1dacd0 str r7, [sp, #0x30] */
/* @0x1dacd4 str r7, [sp, #0x40] */
/* @0x1dacd8 str r7, [sp, #0x50] */
/* @0x1dacdc str r7, [sp, #0x60] */
/* @0x1dace0 str r7, [sp, #0x70] */
/* @0x1dace4 str r2, [sp, #0x64] */
/* @0x1dace8 ldr r2, [r6, #0x4] */
/* @0x1dacec vstr d5, [sp, #120] */
/* @0x1dacf0 vmov s10, r10 */
/* @0x1dacf4 vstr d7, [sp, #24] */
/* @0x1dacf8 vstr d6, [sp, #72] */
/* @0x1dacfc ldr r3, [pc, #0x230] */
/* @0x1dad00 vcvt.f64.s32 d7, s10 */
/* @0x1dad04 ldr r1, [pc, #0x22c] */
/* @0x1dad08 add r3, pc, r3 */
/* @0x1dad0c ldr r10, [pc, #0x228] */
/* @0x1dad10 add r1, pc, r1 */
/* @0x1dad14 add r10, pc, r10 */
/* @0x1dad18 vstr d7, [sp, #88] */
/* @0x1dad1c vldr s10, [sp, #400] */
/* @0x1dad20 vcvt.f64.f32 d5, s10 */
/* @0x1dad24 str r7, [sp, #0x80] */
/* @0x1dad28 vldr s14, [sp, #404] */
/* @0x1dad2c vldr s12, [r6, #48] */
/* @0x1dad30 vldr s2, [sp, #376] */
/* @0x1dad34 vldr s4, [sp, #380] */
/* @0x1dad38 vldr s6, [sp, #392] */
/* @0x1dad3c vldr s8, [sp, #396] */
/* @0x1dad40 str r3, [sp, #0x94] */
/* @0x1dad44 ldr r3, [pc, #0x1f4] */
/* @0x1dad48 str r1, [sp, #0x84] */
/* @0x1dad4c vcvt.f64.f32 d6, s12 */
/* @0x1dad50 vstr d5, [sp, #232] */
/* @0x1dad54 vmov s11, r9 */
/* @0x1dad58 str r12, [sp, #0xa4] */
/* @0x1dad5c add r3, pc, r3 */
/* @0x1dad60 ldr r12, [pc, #0x1dc] */
/* @0x1dad64 str r3, [sp, #0xc4] */
/* @0x1dad68 ldr r1, [pc, #0x1d8] */
/* @0x1dad6c add r12, pc, r12 */
/* @0x1dad70 ldr r3, [pc, #0x1d4] */
/* @0x1dad74 str lr, [sp, #0xb4] */
/* @0x1dad78 add r1, pc, r1 */
/* @0x1dad7c vcvt.f64.f32 d7, s14 */
/* @0x1dad80 vstr d6, [sp, #264] */
/* @0x1dad84 str r10, [sp, #0xd4] */
/* @0x1dad88 add r3, pc, r3 */
/* @0x1dad8c str r12, [sp, #0xe4] */
/* @0x1dad90 str r1, [sp, #0xf4] */
/* @0x1dad94 str r3, [sp, #0x104] */
/* @0x1dad98 str r7, [sp, #0x90] */
/* @0x1dad9c str r7, [sp, #0xa0] */
/* @0x1dada0 vcvt.f64.f32 d1, s2 */
/* @0x1dada4 vstr d7, [sp, #248] */
/* @0x1dada8 str r7, [sp, #0xb0] */
/* @0x1dadac str r7, [sp, #0xc0] */
/* @0x1dadb0 str r7, [sp, #0xd0] */
/* @0x1dadb4 str r7, [sp, #0xe0] */
/* @0x1dadb8 str r7, [sp, #0xf0] */
/* @0x1dadbc str r7, [sp, #0x100] */
/* @0x1dadc0 vcvt.f64.f32 d2, s4 */
/* @0x1dadc4 vstr d1, [sp, #136] */
/* @0x1dadc8 ldr r1, [pc, #0x180] */
/* @0x1dadcc ldr r10, [pc, #0x180] */
/* @0x1dadd0 add r1, pc, r1 */
/* @0x1dadd4 ldr lr, [pc, #0x17c] */
/* @0x1dadd8 ldr r12, [pc, #0x17c] */
/* @0x1daddc add r10, pc, r10 */
/* @0x1dade0 ldr r3, [pc, #0x178] */
/* @0x1dade4 add lr, pc, lr */
/* @0x1dade8 add r12, pc, r12 */
/* @0x1dadec vcvt.f64.f32 d3, s6 */
/* @0x1dadf0 vstr d2, [sp, #152] */
/* @0x1dadf4 add r3, pc, r3 */
/* @0x1dadf8 vcvt.f64.f32 d4, s8 */
/* @0x1dadfc vstr d3, [sp, #200] */
/* @0x1dae00 vcvt.f64.s32 d6, s16 */
/* @0x1dae04 vstr d4, [sp, #216] */
/* @0x1dae08 vcvt.f64.s32 d7, s11 */
/* @0x1dae0c vstr d6, [sp, #168] */
/* @0x1dae10 vstr d7, [sp, #184] */
/* @0x1dae14 vldr s12, [sp, #408] */
/* @0x1dae18 vcvt.f64.f32 d6, s12 */
/* @0x1dae1c str r7, [sp, #0x110] */
/* @0x1dae20 vldr s10, [r6, #52] */
/* @0x1dae24 vldr s14, [sp, #412] */
/* @0x1dae28 str r1, [sp, #0x144] */
/* @0x1dae2c ldr r1, [pc, #0x130] */
/* @0x1dae30 str r4, [sp, #0x148] */
/* @0x1dae34 str r5, [sp, #0x14c] */
/* @0x1dae38 str r4, [sp, #0x158] */
/* @0x1dae3c str r5, [sp, #0x15c] */
/* @0x1dae40 add r1, pc, r1 */
/* @0x1dae44 str lr, [sp, #0x124] */
/* @0x1dae48 vstr d6, [sp, #296] */
/* @0x1dae4c vmov s13, r2 */
/* @0x1dae50 vcvt.f64.f32 d5, s10 */
/* @0x1dae54 str r12, [sp, #0x134] */
/* @0x1dae58 str r3, [sp, #0x154] */
/* @0x1dae5c str r7, [sp, #0x120] */
/* @0x1dae60 str r7, [sp, #0x130] */
/* @0x1dae64 str r7, [sp, #0x140] */
/* @0x1dae68 str r7, [sp, #0x150] */
/* @0x1dae6c str r7, [sp, #0x160] */
/* @0x1dae70 vcvt.f64.f32 d7, s14 */
/* @0x1dae74 vstr d5, [sp, #280] */
/* @0x1dae78 str r10, [sp, #0x114] */
/* @0x1dae7c vcvt.f64.s32 d6, s13 */
/* @0x1dae80 vstr d7, [sp, #312] */
/* @0x1dae84 vmov r2, r3, d6 */
/* @0x1dae88 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x1dae8c ldr r11, [pc, r11] */
/* @0x1dae90 ldr r4, [r6, #0xc] */
/* @0x1dae94 mov r3, #1 */
/* @0x1dae98 ldr lr, [r6, #0x10] */
/* @0x1dae9c mov r2, #143 */
/* @0x1daea0 ldr r1, [pc, #0xc0] */
/* @0x1daea4 ldr r12, [r11, #0x8] */
/* @0x1daea8 add r1, pc, r1 */
/* @0x1daeac str r4, [r8, #0x8] */
/* @0x1daeb0 str lr, [r8, #0xc] */
/* @0x1daeb4 add r12, r12, r3 */
/* @0x1daeb8 str r0, [r8, #0x4] */
/* @0x1daebc mov r0, #12 */
/* @0x1daec0 str r12, [r11, #0x8] */
/* @0x1daec4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1daec8 ldr r3, [r11, #0x4] */
/* @0x1daecc cmp r3, r7 */
/* @0x1daed0 str r8, [r0, #0x8] */
/* @0x1daed4 streq r0, [r11, #0x4] */
/* @0x1daed8 strne r0, [r3] */
/* @0x1daedc streq r3, [r0, #0x4] */
/* @0x1daee0 strne r3, [r0, #0x4] */
/* @0x1daee4 streq r0, [r11] */
/* @0x1daee8 strne r0, [r11, #0x4] */
/* @0x1daeec streq r3, [r0] */
/* @0x1daef0 mov r3, #1 */
/* @0x1daef4 strne r7, [r0] */
/* @0x1daef8 str r3, [r6, #0x14] */
/* @0x1daefc add sp, sp, #420 */
/* @0x1daf00 b 0x1daf70 <_ZN14CGestureRotate6UpdateEx+0x630> */
/* @0x1daf04 ldrdmi r0, r1, [r9], #-251 */
/* @0x1daf08 eoreq r5, r1, r4, ror sp */
/* @0x1daf0c andseq r6, r7, r4, asr #12 */
/* @0x1daf10 mulseq r7, r4, r6 */
/* @0x1daf14 mulseq r7, r4, r6 */
/* @0x1daf18 andseq r6, r7, r8, lsl #12 */
/* @0x1daf1c andseq r6, r7, r0, ror #11 */
/* @0x1daf20 andseq r6, r7, r4, ror #11 */
/* @0x1daf24 andseq r6, r7, r0, ror #11 */
/* @0x1daf28 ldrsbeq r6, [r7], -r8 */
/* @0x1daf2c ldrsbeq r6, [r7], -r8 */
/* @0x1daf30 ldrsbeq r6, [r7], -r12 */
/* @0x1daf34 andseq r6, r7, r8, lsr #11 */
/* @0x1daf38 mulseq r7, r8, r5 */
/* @0x1daf3c andseq r6, r7, r8, asr #11 */
/* @0x1daf40 andseq r6, r7, r4, ror r5 */
/* @0x1daf44 ldrsheq r6, [r7], -r4 */
/* @0x1daf48 ldrsheq r6, [r7], -r0 */
/* @0x1daf4c andseq r6, r7, r8, ror #11 */
/* @0x1daf50 ldrsbeq r6, [r7], -r0 */
/* @0x1daf54 andseq r6, r7, r0, lsr #11 */
/* @0x1daf58 andseq r6, r7, r4, lsr #11 */
/* @0x1daf5c andseq r6, r7, r12, lsr #11 */
/* @0x1daf60 ldrheq r6, [r7], -r12 */
/* @0x1daf64 andseq r6, r7, r8, lsr r3 */
/* @0x1daf68 andseq r1, r7, r8, lsl #31 */
/* @0x1daf6c andeq r0, r0, r0 */
/* @0x1daf70 vpop {d8, d9, d10, d11} */
/* @0x1daf74 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1daf78 mov r9, #0 */
/* @0x1daf7c vldr s19, [pc, #-24] */
/* @0x1daf80 vmov s16, r9 */
/* @0x1daf84 vmov.f32 s21, s19 */
/* @0x1daf88 b 0x1da9d4 <_ZN14CGestureRotate6UpdateEx+0x94> */
/* @0x1daf8c mov r10, #0 */
/* @0x1daf90 vldr s18, [pc, #-44] */
/* @0x1daf94 vmov s17, r10 */
/* @0x1daf98 vmov.f32 s20, s18 */
/* @0x1daf9c b 0x1da998 <_ZN14CGestureRotate6UpdateEx+0x58> */
/* @0x1dafa0 cmp r0, #0 */
/* @0x1dafa4 vldr s18, [pc, #-64] */
/* @0x1dafa8 mov r10, r4 */
/* @0x1dafac vmov.f32 s20, s18 */
/* @0x1dafb0 vmov s17, r4 */
/* @0x1dafb4 mvn r5, #0 */
/* @0x1dafb8 mov r8, #1 */
/* @0x1dafbc bne 0x1da9a8 <_ZN14CGestureRotate6UpdateEx+0x68> */
/* @0x1dafc0 vldr s19, [pc, #-92] */
/* @0x1dafc4 mvn r1, #0 */
/* @0x1dafc8 mov r9, r0 */
/* @0x1dafcc vmov.f32 s21, s19 */
/* @0x1dafd0 vmov s16, r0 */
/* @0x1dafd4 str r1, [sp, #0x16c] */
/* @0x1dafd8 mov r8, #1 */
/* @0x1dafdc b 0x1da9e8 <_ZN14CGestureRotate6UpdateEx+0xa8> */
/* @0x1dafe0 vmov s15, r10 */
/* @0x1dafe4 ldr r2, [r6, #0x44] */
/* @0x1dafe8 vcvt.f32.s32 s14, s17 */
/* @0x1dafec add r3, sp, #372 */
/* @0x1daff0 str r3, [sp] */
/* @0x1daff4 add r3, sp, #384 */
/* @0x1daff8 str r3, [sp, #0x4] */
/* @0x1daffc add r3, sp, #388 */
/* @0x1db000 str r3, [sp, #0x8] */
/* @0x1db004 add r3, sp, #368 */
/* @0x1db008 vcvt.f32.s32 s15, s15 */
/* @0x1db00c vmov r0, s14 */
/* @0x1db010 vmov r1, s15 */
/* @0x1db014 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_> */
/* @0x1db018 vmov s11, r9 */
/* @0x1db01c vcvt.f32.s32 s10, s16 */
/* @0x1db020 ldr r2, [r6, #0x44] */
/* @0x1db024 add r3, sp, #380 */
/* @0x1db028 str r3, [sp] */
/* @0x1db02c add r3, sp, #392 */
/* @0x1db030 str r3, [sp, #0x4] */
/* @0x1db034 add r3, sp, #396 */
/* @0x1db038 str r3, [sp, #0x8] */
/* @0x1db03c add r3, sp, #376 */
/* @0x1db040 vcvt.f32.s32 s11, s11 */
/* @0x1db044 vmov r0, s10 */
/* @0x1db048 vmov r1, s11 */
/* @0x1db04c bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_> */
/* @0x1db050 ldr r2, [r6, #0x44] */
/* @0x1db054 ldr r0, [r6, #0x30] */
/* @0x1db058 add r3, sp, #404 */
/* @0x1db05c ldr r1, [r6, #0x34] */
/* @0x1db060 str r3, [sp] */
/* @0x1db064 add r3, sp, #408 */
/* @0x1db068 str r3, [sp, #0x4] */
/* @0x1db06c add r3, sp, #412 */
/* @0x1db070 str r3, [sp, #0x8] */
/* @0x1db074 add r3, sp, #400 */
/* @0x1db078 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_> */
/* @0x1db07c cmp r8, #0 */
/* @0x1db080 beq 0x1db3ac <_ZN14CGestureRotate6UpdateEx+0xa6c> */
/* @0x1db084 mov r0, #16 */
/* @0x1db088 bl 0x27c524 <_Znwj> */
/* @0x1db08c mov r2, #12 */
/* @0x1db090 mvn r3, #0 */
/* @0x1db094 vldr d0, [pc, #1004] */
/* @0x1db098 mov r7, r0 */
/* @0x1db09c str r2, [r0] */
/* @0x1db0a0 str r3, [r0, #0x4] */
/* @0x1db0a4 mov r2, #0 */
/* @0x1db0a8 str r2, [r0, #0x8] */
/* @0x1db0ac str r2, [r0, #0xc] */
/* @0x1db0b0 str r3, [r6, #0x14] */
/* @0x1db0b4 vmov s12, r5 */
/* @0x1db0b8 vldr s4, [sp, #368] */
/* @0x1db0bc vldr s6, [sp, #372] */
/* @0x1db0c0 vcvt.f64.f32 d2, s4 */
/* @0x1db0c4 vldr s8, [sp, #384] */
/* @0x1db0c8 vldr s14, [sp, #388] */
/* @0x1db0cc ldr r3, [pc, #0x3c8] */
/* @0x1db0d0 mov r5, #0 */
/* @0x1db0d4 ldr r12, [pc, #0x3c4] */
/* @0x1db0d8 vldr s10, [sp, #364] */
/* @0x1db0dc add r3, pc, r3 */
/* @0x1db0e0 ldr r1, [pc, #0x3bc] */
/* @0x1db0e4 str r3, [sp, #0x4] */
/* @0x1db0e8 add r12, pc, r12 */
/* @0x1db0ec ldr r2, [pc, #0x3b4] */
/* @0x1db0f0 add r1, pc, r1 */
/* @0x1db0f4 vcvt.f64.s32 d1, s12 */
/* @0x1db0f8 ldr r3, [pc, #0x3ac] */
/* @0x1db0fc str r12, [sp, #0x14] */
/* @0x1db100 add r2, pc, r2 */
/* @0x1db104 str r1, [sp, #0x24] */
/* @0x1db108 add r3, pc, r3 */
/* @0x1db10c str r2, [sp, #0x34] */
/* @0x1db110 vstr d2, [sp, #40] */
/* @0x1db114 str r3, [sp, #0x44] */
/* @0x1db118 vldr s12, [sp, #376] */
/* @0x1db11c ldr r12, [pc, #0x38c] */
/* @0x1db120 vldr s11, [pc, #872] */
/* @0x1db124 ldr r1, [pc, #0x388] */
/* @0x1db128 mov r0, #23 */
/* @0x1db12c vcvt.f64.f32 d3, s6 */
/* @0x1db130 ldr r2, [pc, #0x380] */
/* @0x1db134 ldr r3, [pc, #0x380] */
/* @0x1db138 vstr d1, [sp, #8] */
/* @0x1db13c add r12, pc, r12 */
/* @0x1db140 add r1, pc, r1 */
/* @0x1db144 str r12, [sp, #0x54] */
/* @0x1db148 add r2, pc, r2 */
/* @0x1db14c str r1, [sp, #0x64] */
/* @0x1db150 add r3, pc, r3 */
/* @0x1db154 str r2, [sp, #0x74] */
/* @0x1db158 str r3, [sp, #0x84] */
/* @0x1db15c vcvt.f64.f32 d4, s8 */
/* @0x1db160 vstr d3, [sp, #56] */
/* @0x1db164 str r5, [sp] */
/* @0x1db168 str r5, [sp, #0x10] */
/* @0x1db16c str r5, [sp, #0x20] */
/* @0x1db170 str r5, [sp, #0x30] */
/* @0x1db174 str r5, [sp, #0x40] */
/* @0x1db178 str r5, [sp, #0x50] */
/* @0x1db17c vcvt.f64.f32 d7, s14 */
/* @0x1db180 vstr d4, [sp, #104] */
/* @0x1db184 str r5, [sp, #0x60] */
/* @0x1db188 str r5, [sp, #0x70] */
/* @0x1db18c str r5, [sp, #0x80] */
/* @0x1db190 ldr r2, [r6, #0x4] */
/* @0x1db194 ldr r12, [pc, #0x324] */
/* @0x1db198 ldr r3, [pc, #0x324] */
/* @0x1db19c vcvt.f64.f32 d6, s12 */
/* @0x1db1a0 vstr d7, [sp, #120] */
/* @0x1db1a4 add r12, pc, r12 */
/* @0x1db1a8 add r3, pc, r3 */
/* @0x1db1ac ldr lr, [pc, #0x314] */
/* @0x1db1b0 ldr r1, [pc, #0x314] */
/* @0x1db1b4 ldr r4, [pc, #0x314] */
/* @0x1db1b8 add lr, pc, lr */
/* @0x1db1bc ldr r8, [pc, #0x310] */
/* @0x1db1c0 add r1, pc, r1 */
/* @0x1db1c4 add r4, pc, r4 */
/* @0x1db1c8 vcvt.f64.s32 d7, s10 */
/* @0x1db1cc vstr d6, [sp, #136] */
/* @0x1db1d0 vmov s10, r10 */
/* @0x1db1d4 ldr r10, [pc, #0x2fc] */
/* @0x1db1d8 add r8, pc, r8 */
/* @0x1db1dc add r10, pc, r10 */
/* @0x1db1e0 vcvt.f64.s32 d6, s17 */
/* @0x1db1e4 vstr d7, [sp, #24] */
/* @0x1db1e8 vcvt.f64.s32 d7, s10 */
/* @0x1db1ec vstr d6, [sp, #72] */
/* @0x1db1f0 vstr d7, [sp, #88] */
/* @0x1db1f4 vldr s12, [sp, #404] */
/* @0x1db1f8 vcvt.f64.f32 d6, s12 */
/* @0x1db1fc str r5, [sp, #0x90] */
/* @0x1db200 vldr s14, [r6, #52] */
/* @0x1db204 vldr s18, [r6, #48] */
/* @0x1db208 vldr s2, [sp, #380] */
/* @0x1db20c vldr s4, [sp, #392] */
/* @0x1db210 vldr s6, [sp, #396] */
/* @0x1db214 vldr s8, [sp, #400] */
/* @0x1db218 str r12, [sp, #0xa4] */
/* @0x1db21c str r3, [sp, #0xb4] */
/* @0x1db220 ldr r12, [pc, #0x2b4] */
/* @0x1db224 vcvt.f64.f32 d7, s14 */
/* @0x1db228 vstr d6, [sp, #248] */
/* @0x1db22c vmov s12, r9 */
/* @0x1db230 ldr r3, [pc, #0x2a8] */
/* @0x1db234 str lr, [sp, #0x94] */
/* @0x1db238 add r12, pc, r12 */
/* @0x1db23c add r3, pc, r3 */
/* @0x1db240 str r1, [sp, #0xc4] */
/* @0x1db244 str r4, [sp, #0xd4] */
/* @0x1db248 str r8, [sp, #0xe4] */
/* @0x1db24c str r12, [sp, #0x104] */
/* @0x1db250 vcvt.f64.f32 d1, s2 */
/* @0x1db254 vstr d7, [sp, #280] */
/* @0x1db258 str r3, [sp, #0x114] */
/* @0x1db25c str r5, [sp, #0xa0] */
/* @0x1db260 str r5, [sp, #0xb0] */
/* @0x1db264 str r5, [sp, #0xc0] */
/* @0x1db268 str r5, [sp, #0xd0] */
/* @0x1db26c str r5, [sp, #0xe0] */
/* @0x1db270 vcvt.f64.s32 d7, s12 */
/* @0x1db274 vstr d1, [sp, #152] */
/* @0x1db278 str r5, [sp, #0xf0] */
/* @0x1db27c str r5, [sp, #0x100] */
/* @0x1db280 str r5, [sp, #0x110] */
/* @0x1db284 str r10, [sp, #0xf4] */
/* @0x1db288 ldr r8, [pc, #0x254] */
/* @0x1db28c ldr lr, [pc, #0x254] */
/* @0x1db290 vcvt.f64.f32 d2, s4 */
/* @0x1db294 ldr r12, [pc, #0x250] */
/* @0x1db298 ldr r3, [pc, #0x250] */
/* @0x1db29c add lr, pc, lr */
/* @0x1db2a0 ldr r1, [pc, #0x24c] */
/* @0x1db2a4 add r12, pc, r12 */
/* @0x1db2a8 add r3, pc, r3 */
/* @0x1db2ac add r8, pc, r8 */
/* @0x1db2b0 add r1, pc, r1 */
/* @0x1db2b4 ldr r4, [pc, #0x23c] */
/* @0x1db2b8 vcvt.f64.f32 d3, s6 */
/* @0x1db2bc vstr d2, [sp, #200] */
/* @0x1db2c0 vcvt.f64.f32 d4, s8 */
/* @0x1db2c4 vstr d3, [sp, #216] */
/* @0x1db2c8 vcvt.f64.f32 d9, s18 */
/* @0x1db2cc vstr d4, [sp, #232] */
/* @0x1db2d0 vcvt.f64.s32 d8, s16 */
/* @0x1db2d4 vstr d9, [sp, #264] */
/* @0x1db2d8 vstr d8, [sp, #168] */
/* @0x1db2dc vstr d7, [sp, #184] */
/* @0x1db2e0 str r5, [sp, #0x120] */
/* @0x1db2e4 vldr s10, [r6, #64] */
/* @0x1db2e8 vmul.f32 s10, s10, s11 */
/* @0x1db2ec vldr s14, [sp, #412] */
/* @0x1db2f0 vldr s12, [sp, #408] */
/* @0x1db2f4 vstr d0, [sp, #328] */
/* @0x1db2f8 str lr, [sp, #0x134] */
/* @0x1db2fc str r12, [sp, #0x144] */
/* @0x1db300 str r3, [sp, #0x154] */
/* @0x1db304 str r5, [sp, #0x130] */
/* @0x1db308 str r5, [sp, #0x140] */
/* @0x1db30c str r5, [sp, #0x150] */
/* @0x1db310 str r5, [sp, #0x160] */
/* @0x1db314 str r8, [sp, #0x124] */
/* @0x1db318 vcvt.f64.f32 d7, s14 */
/* @0x1db31c vstr d7, [sp, #312] */
/* @0x1db320 vmov s15, r2 */
/* @0x1db324 vcvt.f64.f32 d5, s10 */
/* @0x1db328 vcvt.f64.f32 d6, s12 */
/* @0x1db32c vstr d5, [sp, #344] */
/* @0x1db330 vcvt.f64.s32 d7, s15 */
/* @0x1db334 vstr d6, [sp, #296] */
/* @0x1db338 vmov r2, r3, d7 */
/* @0x1db33c bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x1db340 ldr r1, [r6, #0x10] */
/* @0x1db344 ldr r4, [pc, r4] */
/* @0x1db348 ldr lr, [r6, #0xc] */
/* @0x1db34c mov r3, #1 */
/* @0x1db350 mov r2, #143 */
/* @0x1db354 str r1, [r7, #0xc] */
/* @0x1db358 ldr r1, [pc, #0x19c] */
/* @0x1db35c ldr r12, [r4, #0x8] */
/* @0x1db360 add r1, pc, r1 */
/* @0x1db364 str lr, [r7, #0x8] */
/* @0x1db368 add r12, r12, r3 */
/* @0x1db36c str r0, [r7, #0x4] */
/* @0x1db370 mov r0, #12 */
/* @0x1db374 str r12, [r4, #0x8] */
/* @0x1db378 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1db37c ldr r3, [r4, #0x4] */
/* @0x1db380 cmp r3, r5 */
/* @0x1db384 str r7, [r0, #0x8] */
/* @0x1db388 strne r0, [r3] */
/* @0x1db38c strne r3, [r0, #0x4] */
/* @0x1db390 strne r0, [r4, #0x4] */
/* @0x1db394 strne r5, [r0] */
/* @0x1db398 streq r0, [r4, #0x4] */
/* @0x1db39c streq r0, [r4] */
/* @0x1db3a0 streq r3, [r0, #0x4] */
/* @0x1db3a4 streq r3, [r0] */
/* @0x1db3a8 b 0x1da9fc <_ZN14CGestureRotate6UpdateEx+0xbc> */
/* @0x1db3ac vsub.f32 s18, s19, s18 */
/* @0x1db3b0 vmul.f32 s15, s18, s18 */
/* @0x1db3b4 vsub.f32 s20, s21, s20 */
/* @0x1db3b8 vmla.f32 s15, s20, s20 */
/* @0x1db3bc vsqrt.f32 s22, s15 */
/* @0x1db3c0 vcmp.f32 s22, s22 */
/* @0x1db3c4 vmrs APSR_nzcv, fpscr */
/* @0x1db3c8 bne 0x1db500 <_ZN14CGestureRotate6UpdateEx+0xbc0> */
/* @0x1db3cc vcmpe.f32 s22, #0 */
/* @0x1db3d0 vmrs APSR_nzcv, fpscr */
/* @0x1db3d4 ble 0x1da9fc <_ZN14CGestureRotate6UpdateEx+0xbc> */
/* @0x1db3d8 vdiv.f32 s18, s18, s22 */
/* @0x1db3dc vmov r0, s18 */
/* @0x1db3e0 bl 0xb6760 <acosf@plt> */
/* @0x1db3e4 vdiv.f32 s20, s20, s22 */
/* @0x1db3e8 vmov s18, r0 */
/* @0x1db3ec vcmpe.f32 s20, #0 */
/* @0x1db3f0 vmrs APSR_nzcv, fpscr */
/* @0x1db3f4 vldrmi s15, [pc, #152] */
/* @0x1db3f8 vsubmi.f32 s18, s15, s18 */
/* @0x1db3fc vaddmi.f32 s18, s18, s15 */
/* @0x1db400 vldr s15, [r6, #60] */
/* @0x1db404 vcmp.f32 s15, s18 */
/* @0x1db408 vmrs APSR_nzcv, fpscr */
/* @0x1db40c beq 0x1da9fc <_ZN14CGestureRotate6UpdateEx+0xbc> */
/* @0x1db410 vsub.f32 s19, s18, s15 */
/* @0x1db414 vldr s15, [pc, #120] */
/* @0x1db418 mov r0, #16 */
/* @0x1db41c vcmpe.f32 s19, s15 */
/* @0x1db420 vmrs APSR_nzcv, fpscr */
/* @0x1db424 vldrgt s15, [pc, #108] */
/* @0x1db428 vsubgt.f32 s19, s15, s19 */
/* @0x1db42c vldr s15, [r6, #64] */
/* @0x1db430 vneggt.f32 s19, s19 */
/* @0x1db434 vadd.f32 s15, s15, s19 */
/* @0x1db438 vstr s15, [r6, #64] */
/* @0x1db43c bl 0x27c524 <_Znwj> */
/* @0x1db440 vldr s0, [pc, #72] */
/* @0x1db444 vmul.f32 s0, s19, s0 */
/* @0x1db448 mvn r3, #0 */
/* @0x1db44c mov r2, #11 */
/* @0x1db450 vcvt.f64.f32 d0, s0 */
/* @0x1db454 str r3, [r0, #0x4] */
/* @0x1db458 mov r7, r0 */
/* @0x1db45c mov r3, #0 */
/* @0x1db460 str r2, [r0] */
/* @0x1db464 str r3, [r0, #0x8] */
/* @0x1db468 str r3, [r0, #0xc] */
/* @0x1db46c vstr s18, [r6, #60] */
/* @0x1db470 b 0x1db0b4 <_ZN14CGestureRotate6UpdateEx+0x774> */
/* @0x1db474 vmov r0, s15 */
/* @0x1db478 bl 0xb6700 <sqrtf@plt> */
/* @0x1db47c vmov s20, r0 */
/* @0x1db480 b 0x1daae4 <_ZN14CGestureRotate6UpdateEx+0x1a4> */
/* @0x1db484 nop */
/* @0x1db490 rsbmi r2, r5, #224, #28 */
/* @0x1db494 ldrdmi r0, r1, [r9], #-251 */
/* @0x1db498 ldrdmi r0, r1, [r9], #251 */
/* @0x1db49c andseq r6, r7, r12, ror r1 */
/* @0x1db4a0 andseq r6, r7, r8, ror r1 */
/* @0x1db4a4 andseq r6, r7, r8, ror r1 */
/* @0x1db4a8 andseq r6, r7, r0, ror r1 */
/* @0x1db4ac andseq r6, r7, r0, ror r1 */
/* @0x1db4b0 andseq r6, r7, r8, asr #2 */
/* @0x1db4b4 andseq r6, r7, r0, asr r1 */
/* @0x1db4b8 andseq r6, r7, r4, asr r1 */
/* @0x1db4bc andseq r6, r7, r8, asr r1 */
/* @0x1db4c0 andseq r6, r7, r4, lsl r1 */
/* @0x1db4c4 andseq r6, r7, r12, lsl r1 */
/* @0x1db4c8 ldrsheq r6, [r7], -r8 */
/* @0x1db4cc andseq r6, r7, r0, lsl r1 */
/* @0x1db4d0 andseq r6, r7, r8, lsl r1 */
/* @0x1db4d4 andseq r6, r7, r8, lsl #3 */
/* @0x1db4d8 andseq r6, r7, r12, lsl #3 */
/* @0x1db4dc andseq r6, r7, r8, lsr r1 */
/* @0x1db4e0 andseq r6, r7, r0, asr #2 */
/* @0x1db4e4 ldrsbeq r6, [r7], -r12 */
/* @0x1db4e8 ldrsheq r6, [r7], -r8 */
/* @0x1db4ec ldrsheq r6, [r7], -r12 */
/* @0x1db4f0 andseq r6, r7, r8, lsl #2 */
/* @0x1db4f4 andseq r5, r7, r8, asr #29 */
/* @0x1db4f8 .word 0x002158bc */
/* @0x1db4fc ldrsbeq r1, [r7], -r0 */
/* @0x1db500 vmov r0, s15 */
/* @0x1db504 bl 0xb6700 <sqrtf@plt> */
/* @0x1db508 vmov s22, r0 */
/* @0x1db50c b 0x1db3cc <_ZN14CGestureRotate6UpdateEx+0xa8c> */

/* ── FUNC 0x1db510 · CGestureEvent::~CGestureEvent() · size=128 · insn=32 */
/* @0x1db510 ldr r3, [r0, #0x4] */
/* @0x1db514 push {r4, r5, r6, r7, lr} */
/* @0x1db518 cmn r3, #1 */
/* @0x1db51c sub sp, sp, #12 */
/* @0x1db520 mov r4, r0 */
/* @0x1db524 beq 0x1db580 <_ZN13CGestureEventD2Ev+0x70> */
/* @0x1db528 add r7, sp, #4 */
/* @0x1db52c ldr r5, [pc, #0x58] */
/* @0x1db530 mov r0, r7 */
/* @0x1db534 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x1db538 ldr r5, [pc, r5] */
/* @0x1db53c ldr r2, [r4, #0x4] */
/* @0x1db540 ldr r3, [r5, #0x4] */
/* @0x1db544 add r1, r3, r2, lsl #2 */
/* @0x1db548 ldr r6, [r3, r2, lsl #2] */
/* @0x1db54c cmp r6, #0 */
/* @0x1db550 beq 0x1db570 <_ZN13CGestureEventD2Ev+0x60> */
/* @0x1db554 mov r0, r6 */
/* @0x1db558 bl 0x20d9e8 <_ZN7CDS_MapD2Ev> */
/* @0x1db55c mov r0, r6 */
/* @0x1db560 bl 0x27d1d0 <_ZdlPv> */
/* @0x1db564 ldr r1, [r4, #0x4] */
/* @0x1db568 ldr r3, [r5, #0x4] */
/* @0x1db56c add r1, r3, r1, lsl #2 */
/* @0x1db570 mov r3, #0 */
/* @0x1db574 mov r0, r7 */
/* @0x1db578 str r3, [r1] */
/* @0x1db57c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x1db580 mov r0, r4 */
/* @0x1db584 add sp, sp, #12 */
/* @0x1db588 pop {r4, r5, r6, r7, pc} */
/* @0x1db58c eoreq r2, r1, r4, lsl #8 */

/* ── FUNC 0x1db510 · CGestureEvent::~CGestureEvent() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1db590 · HandleGestures() · size=556 · insn=139 */
/* @0x1db590 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1db594 ldr r3, [pc, #0x210] */
/* @0x1db598 ldr r3, [pc, r3] */
/* @0x1db59c ldrb r3, [r3] */
/* @0x1db5a0 cmp r3, #0 */
/* @0x1db5a4 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1db5a8 ldr r7, [pc, #0x200] */
/* @0x1db5ac ldr r7, [pc, r7] */
/* @0x1db5b0 ldr r4, [r7] */
/* @0x1db5b4 cmp r4, #0 */
/* @0x1db5b8 beq 0x1db5f0 <_Z14HandleGesturesv+0x60> */
/* @0x1db5bc ldr r5, [r4, #0x8] */
/* @0x1db5c0 ldr r6, [r4] */
/* @0x1db5c4 cmp r5, #0 */
/* @0x1db5c8 mov r0, r5 */
/* @0x1db5cc beq 0x1db5dc <_Z14HandleGesturesv+0x4c> */
/* @0x1db5d0 bl 0x1db510 <_ZN13CGestureEventD2Ev> */
/* @0x1db5d4 mov r0, r5 */
/* @0x1db5d8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1db5dc mov r0, r4 */
/* @0x1db5e0 mov r4, r6 */
/* @0x1db5e4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1db5e8 cmp r6, #0 */
/* @0x1db5ec bne 0x1db5bc <_Z14HandleGesturesv+0x2c> */
/* @0x1db5f0 mov r9, #0 */
/* @0x1db5f4 str r9, [r7, #0x8] */
/* @0x1db5f8 str r9, [r7, #0x4] */
/* @0x1db5fc str r9, [r7] */
/* @0x1db600 bl 0x215148 <Timing_Time> */
/* @0x1db604 ldr r8, [pc, #0x1a8] */
/* @0x1db608 mov r4, r0 */
/* @0x1db60c mov r5, r1 */
/* @0x1db610 bl 0x1d7908 <_Z18UpdateTouchActionsx> */
/* @0x1db614 ldr r8, [pc, r8] */
/* @0x1db618 ldr r6, [r8] */
/* @0x1db61c cmp r6, r9 */
/* @0x1db620 beq 0x1db7a4 <_Z14HandleGesturesv+0x214> */
/* @0x1db624 ldr r3, [r6, #0x8] */
/* @0x1db628 cmp r3, #0 */
/* @0x1db62c beq 0x1db7a4 <_Z14HandleGesturesv+0x214> */
/* @0x1db630 ldr r10, [pc, #0x180] */
/* @0x1db634 mov r7, r9 */
/* @0x1db638 add r10, pc, r10 */
/* @0x1db63c b 0x1db658 <_Z14HandleGesturesv+0xc8> */
/* @0x1db640 ldr r6, [r6] */
/* @0x1db644 cmp r6, #0 */
/* @0x1db648 beq 0x1db6c8 <_Z14HandleGesturesv+0x138> */
/* @0x1db64c ldr r3, [r6, #0x8] */
/* @0x1db650 cmp r3, #0 */
/* @0x1db654 beq 0x1db6c8 <_Z14HandleGesturesv+0x138> */
/* @0x1db658 ldr r11, [r6, #0x8] */
/* @0x1db65c mov r3, r5 */
/* @0x1db660 mov r2, r4 */
/* @0x1db664 ldr r1, [r11] */
/* @0x1db668 mov r0, r11 */
/* @0x1db66c ldr r1, [r1, #0x8] */
/* @0x1db670 blx r1 */
/* @0x1db674 ldr r3, [r11, #0x14] */
/* @0x1db678 strd r4, r5, [r11, #32] */
/* @0x1db67c cmn r3, #1 */
/* @0x1db680 bne 0x1db640 <_Z14HandleGesturesv+0xb0> */
/* @0x1db684 mov r3, #1 */
/* @0x1db688 mov r0, #12 */
/* @0x1db68c mov r1, r10 */
/* @0x1db690 mov r2, #143 */
/* @0x1db694 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1db698 cmp r9, #0 */
/* @0x1db69c movne r3, #0 */
/* @0x1db6a0 streq r9, [r0, #0x4] */
/* @0x1db6a4 streq r9, [r0] */
/* @0x1db6a8 moveq r9, r0 */
/* @0x1db6ac str r11, [r0, #0x8] */
/* @0x1db6b0 moveq r7, r9 */
/* @0x1db6b4 strne r0, [r9] */
/* @0x1db6b8 strne r9, [r0, #0x4] */
/* @0x1db6bc movne r9, r0 */
/* @0x1db6c0 strne r3, [r0] */
/* @0x1db6c4 b 0x1db640 <_Z14HandleGesturesv+0xb0> */
/* @0x1db6c8 bl 0x1d719c <_Z20ProcessGestureEventsv> */
/* @0x1db6cc cmp r7, #0 */
/* @0x1db6d0 beq 0x1db788 <_Z14HandleGesturesv+0x1f8> */
/* @0x1db6d4 ldr r3, [r7, #0x8] */
/* @0x1db6d8 cmp r3, #0 */
/* @0x1db6dc beq 0x1db770 <_Z14HandleGesturesv+0x1e0> */
/* @0x1db6e0 mov r9, r7 */
/* @0x1db6e4 ldr r6, [r8] */
/* @0x1db6e8 ldr r2, [r9, #0x8] */
/* @0x1db6ec cmp r6, #0 */
/* @0x1db6f0 bne 0x1db704 <_Z14HandleGesturesv+0x174> */
/* @0x1db6f4 b 0x1db758 <_Z14HandleGesturesv+0x1c8> */
/* @0x1db6f8 ldr r6, [r6] */
/* @0x1db6fc cmp r6, #0 */
/* @0x1db700 beq 0x1db758 <_Z14HandleGesturesv+0x1c8> */
/* @0x1db704 ldr r0, [r6, #0x8] */
/* @0x1db708 cmp r2, r0 */
/* @0x1db70c bne 0x1db6f8 <_Z14HandleGesturesv+0x168> */
/* @0x1db710 ldm r6, {r1, r2} */
/* @0x1db714 cmp r2, #0 */
/* @0x1db718 strne r1, [r2] */
/* @0x1db71c ldrne r1, [r6] */
/* @0x1db720 streq r1, [r8] */
/* @0x1db724 cmp r1, #0 */
/* @0x1db728 streq r2, [r8, #0x4] */
/* @0x1db72c strne r2, [r1, #0x4] */
/* @0x1db730 cmp r0, #0 */
/* @0x1db734 beq 0x1db744 <_Z14HandleGesturesv+0x1b4> */
/* @0x1db738 ldr r2, [r0] */
/* @0x1db73c ldr r3, [r2, #0x4] */
/* @0x1db740 blx r3 */
/* @0x1db744 mov r0, r6 */
/* @0x1db748 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1db74c ldr r3, [r8, #0x8] */
/* @0x1db750 sub r3, r3, #1 */
/* @0x1db754 str r3, [r8, #0x8] */
/* @0x1db758 ldr r9, [r9] */
/* @0x1db75c cmp r9, #0 */
/* @0x1db760 beq 0x1db770 <_Z14HandleGesturesv+0x1e0> */
/* @0x1db764 ldr r3, [r9, #0x8] */
/* @0x1db768 cmp r3, #0 */
/* @0x1db76c bne 0x1db6e4 <_Z14HandleGesturesv+0x154> */
/* @0x1db770 ldr r6, [r7] */
/* @0x1db774 mov r0, r7 */
/* @0x1db778 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1db77c cmp r6, #0 */
/* @0x1db780 mov r7, r6 */
/* @0x1db784 bne 0x1db770 <_Z14HandleGesturesv+0x1e0> */
/* @0x1db788 mov r0, r4 */
/* @0x1db78c mov r1, r5 */
/* @0x1db790 bl 0x1d8e1c <_Z23AddSingleFingerGesturesx> */
/* @0x1db794 mov r0, r4 */
/* @0x1db798 mov r1, r5 */
/* @0x1db79c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1db7a0 b 0x1d87bc <_Z22AddMultiFingerGesturesx> */
/* @0x1db7a4 bl 0x1d719c <_Z20ProcessGestureEventsv> */
/* @0x1db7a8 b 0x1db788 <_Z14HandleGesturesv+0x1f8> */
/* @0x1db7ac eoreq r2, r1, r12, lsl #7 */
/* @0x1db7b0 eoreq r5, r1, r4, asr r6 */
/* @0x1db7b4 eoreq r5, r1, r0, lsl #12 */
/* @0x1db7b8 ldrsheq r1, [r7], -r8 */

/* ── FUNC 0x1db7bc · HandleMouse() · size=596 · insn=149 */
/* @0x1db7bc push {r4, r5, r6, r7, r8, lr} */
/* @0x1db7c0 ldr r4, [pc, #0x230] */
/* @0x1db7c4 ldr r3, [pc, #0x230] */
/* @0x1db7c8 add r4, pc, r4 */
/* @0x1db7cc ldr r6, [r4, r3] */
/* @0x1db7d0 ldrb r3, [r6] */
/* @0x1db7d4 cmp r3, #0 */
/* @0x1db7d8 bne 0x1db95c <_Z11HandleMousev+0x1a0> */
/* @0x1db7dc ldr r3, [pc, #0x21c] */
/* @0x1db7e0 ldr r3, [r4, r3] */
/* @0x1db7e4 ldrb r3, [r3] */
/* @0x1db7e8 cmp r3, #0 */
/* @0x1db7ec bne 0x1db80c <_Z11HandleMousev+0x50> */
/* @0x1db7f0 ldrb r3, [r6] */
/* @0x1db7f4 cmp r3, #0 */
/* @0x1db7f8 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1db7fc ldr r3, [pc, #0x200] */
/* @0x1db800 ldr r0, [r4, r3] */
/* @0x1db804 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1db808 b 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x1db80c ldr r5, [pc, #0x1f4] */
/* @0x1db810 bl 0x1db590 <_Z14HandleGesturesv> */
/* @0x1db814 mov r0, #0 */
/* @0x1db818 add r5, pc, r5 */
/* @0x1db81c ldm r5, {r2, r3} */
/* @0x1db820 str r3, [r5, #0xc] */
/* @0x1db824 str r2, [r5, #0x8] */
/* @0x1db828 bl 0x17ad8c <_Z27GR_Window_Views_Mouse_Get_Xi> */
/* @0x1db82c str r0, [r5] */
/* @0x1db830 mov r0, #0 */
/* @0x1db834 bl 0x17adb0 <_Z27GR_Window_Views_Mouse_Get_Yi> */
/* @0x1db838 ldr r3, [pc, #0x1cc] */
/* @0x1db83c str r0, [r5, #0x4] */
/* @0x1db840 ldr r7, [r4, r3] */
/* @0x1db844 ldrb r3, [r7] */
/* @0x1db848 cmp r3, #0 */
/* @0x1db84c bne 0x1db894 <_Z11HandleMousev+0xd8> */
/* @0x1db850 mov r8, #1 */
/* @0x1db854 mov r5, r8 */
/* @0x1db858 mov r1, #0 */
/* @0x1db85c mov r0, r5 */
/* @0x1db860 bl 0x18c0b4 <_Z14IO_Button_Downii> */
/* @0x1db864 subs r1, r0, #0 */
/* @0x1db868 beq 0x1db9ac <_Z11HandleMousev+0x1f0> */
/* @0x1db86c sub r0, r5, #1 */
/* @0x1db870 mov r8, #0 */
/* @0x1db874 bl 0x1d5e70 <_Z12HandleButtoni> */
/* @0x1db878 add r0, r5, #49 */
/* @0x1db87c bl 0x1d5d00 <_Z17HandleMouseGlobali> */
/* @0x1db880 add r5, r5, #1 */
/* @0x1db884 cmp r5, #4 */
/* @0x1db888 bne 0x1db858 <_Z11HandleMousev+0x9c> */
/* @0x1db88c cmp r8, #0 */
/* @0x1db890 bne 0x1db9e0 <_Z11HandleMousev+0x224> */
/* @0x1db894 mov r5, #1 */
/* @0x1db898 mov r0, r5 */
/* @0x1db89c mov r1, #0 */
/* @0x1db8a0 bl 0x18c0f0 <_Z17IO_Button_Pressedii> */
/* @0x1db8a4 cmp r0, #0 */
/* @0x1db8a8 bne 0x1db990 <_Z11HandleMousev+0x1d4> */
/* @0x1db8ac add r5, r5, #1 */
/* @0x1db8b0 cmp r5, #4 */
/* @0x1db8b4 bne 0x1db898 <_Z11HandleMousev+0xdc> */
/* @0x1db8b8 ldrb r3, [r7] */
/* @0x1db8bc cmp r3, #0 */
/* @0x1db8c0 beq 0x1db908 <_Z11HandleMousev+0x14c> */
/* @0x1db8c4 mov r7, #1 */
/* @0x1db8c8 mov r5, r7 */
/* @0x1db8cc mov r1, #0 */
/* @0x1db8d0 mov r0, r5 */
/* @0x1db8d4 bl 0x18c0b4 <_Z14IO_Button_Downii> */
/* @0x1db8d8 subs r1, r0, #0 */
/* @0x1db8dc beq 0x1db9c0 <_Z11HandleMousev+0x204> */
/* @0x1db8e0 sub r0, r5, #1 */
/* @0x1db8e4 mov r7, #0 */
/* @0x1db8e8 bl 0x1d5e70 <_Z12HandleButtoni> */
/* @0x1db8ec add r0, r5, #49 */
/* @0x1db8f0 bl 0x1d5d00 <_Z17HandleMouseGlobali> */
/* @0x1db8f4 add r5, r5, #1 */
/* @0x1db8f8 cmp r5, #4 */
/* @0x1db8fc bne 0x1db8cc <_Z11HandleMousev+0x110> */
/* @0x1db900 cmp r7, #0 */
/* @0x1db904 bne 0x1db9ec <_Z11HandleMousev+0x230> */
/* @0x1db908 mov r5, #1 */
/* @0x1db90c mov r0, r5 */
/* @0x1db910 mov r1, #0 */
/* @0x1db914 bl 0x18c12c <_Z18IO_Button_Releasedii> */
/* @0x1db918 cmp r0, #0 */
/* @0x1db91c bne 0x1db974 <_Z11HandleMousev+0x1b8> */
/* @0x1db920 add r5, r5, #1 */
/* @0x1db924 cmp r5, #4 */
/* @0x1db928 bne 0x1db90c <_Z11HandleMousev+0x150> */
/* @0x1db92c bl 0x1d5fe8 <_Z11HandleEnterv> */
/* @0x1db930 mov r0, #0 */
/* @0x1db934 bl 0x18c168 <_Z11IO_Wheel_Upi> */
/* @0x1db938 cmp r0, #0 */
/* @0x1db93c bne 0x1db9d4 <_Z11HandleMousev+0x218> */
/* @0x1db940 mov r0, #0 */
/* @0x1db944 bl 0x18c18c <_Z13IO_Wheel_Downi> */
/* @0x1db948 cmp r0, #0 */
/* @0x1db94c beq 0x1db7f0 <_Z11HandleMousev+0x34> */
/* @0x1db950 mov r0, #61 */
/* @0x1db954 bl 0x1d5d00 <_Z17HandleMouseGlobali> */
/* @0x1db958 b 0x1db7f0 <_Z11HandleMousev+0x34> */
/* @0x1db95c ldr r3, [pc, #0xa0] */
/* @0x1db960 mov r1, #6 */
/* @0x1db964 mov r2, #9 */
/* @0x1db968 ldr r0, [r4, r3] */
/* @0x1db96c bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x1db970 b 0x1db7dc <_Z11HandleMousev+0x20> */
/* @0x1db974 add r0, r5, #6 */
/* @0x1db978 bl 0x1d5e70 <_Z12HandleButtoni> */
/* @0x1db97c mov r0, #13 */
/* @0x1db980 bl 0x1d5d00 <_Z17HandleMouseGlobali> */
/* @0x1db984 add r0, r5, #55 */
/* @0x1db988 bl 0x1d5d00 <_Z17HandleMouseGlobali> */
/* @0x1db98c b 0x1db920 <_Z11HandleMousev+0x164> */
/* @0x1db990 add r0, r5, #3 */
/* @0x1db994 bl 0x1d5e70 <_Z12HandleButtoni> */
/* @0x1db998 mov r0, #12 */
/* @0x1db99c bl 0x1d5d00 <_Z17HandleMouseGlobali> */
/* @0x1db9a0 add r0, r5, #52 */
/* @0x1db9a4 bl 0x1d5d00 <_Z17HandleMouseGlobali> */
/* @0x1db9a8 b 0x1db8ac <_Z11HandleMousev+0xf0> */
/* @0x1db9ac mov r0, r5 */
/* @0x1db9b0 bl 0x18c0f0 <_Z17IO_Button_Pressedii> */
/* @0x1db9b4 cmp r0, #0 */
/* @0x1db9b8 bne 0x1db86c <_Z11HandleMousev+0xb0> */
/* @0x1db9bc b 0x1db880 <_Z11HandleMousev+0xc4> */
/* @0x1db9c0 mov r0, r5 */
/* @0x1db9c4 bl 0x18c0f0 <_Z17IO_Button_Pressedii> */
/* @0x1db9c8 cmp r0, #0 */
/* @0x1db9cc bne 0x1db8e0 <_Z11HandleMousev+0x124> */
/* @0x1db9d0 b 0x1db8f4 <_Z11HandleMousev+0x138> */
/* @0x1db9d4 mov r0, #60 */
/* @0x1db9d8 bl 0x1d5d00 <_Z17HandleMouseGlobali> */
/* @0x1db9dc b 0x1db940 <_Z11HandleMousev+0x184> */
/* @0x1db9e0 mov r0, #3 */
/* @0x1db9e4 bl 0x1d5e70 <_Z12HandleButtoni> */
/* @0x1db9e8 b 0x1db894 <_Z11HandleMousev+0xd8> */
/* @0x1db9ec mov r0, #3 */
/* @0x1db9f0 bl 0x1d5e70 <_Z12HandleButtoni> */
/* @0x1db9f4 b 0x1db908 <_Z11HandleMousev+0x14c> */
/* @0x1db9f8 eoreq r6, r1, r8, lsl #9 */
/* @0x1db9fc .word 0xffffbf18 */
/* @0x1dba00 .word 0xffffc96c */
/* @0x1dba04 .word 0xffffbf1c */
/* @0x1dba08 eorseq r9, r6, r8, asr r2 */
/* @0x1dba0c .word 0xffffbcd4 */

/* ── FUNC 0x1dba10 · SLinkedList<CGestureEvent>::~SLinkedList() · size=96 · insn=24 */
/* @0x1dba10 push {r3, r4, r5, r6, r7, lr} */
/* @0x1dba14 mov r7, r0 */
/* @0x1dba18 ldr r4, [r0] */
/* @0x1dba1c cmp r4, #0 */
/* @0x1dba20 beq 0x1dba58 <_ZN11SLinkedListI13CGestureEventED2Ev+0x48> */
/* @0x1dba24 ldr r5, [r4, #0x8] */
/* @0x1dba28 ldr r6, [r4] */
/* @0x1dba2c cmp r5, #0 */
/* @0x1dba30 mov r0, r5 */
/* @0x1dba34 beq 0x1dba44 <_ZN11SLinkedListI13CGestureEventED2Ev+0x34> */
/* @0x1dba38 bl 0x1db510 <_ZN13CGestureEventD2Ev> */
/* @0x1dba3c mov r0, r5 */
/* @0x1dba40 bl 0x27d1d0 <_ZdlPv> */
/* @0x1dba44 mov r0, r4 */
/* @0x1dba48 mov r4, r6 */
/* @0x1dba4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1dba50 cmp r6, #0 */
/* @0x1dba54 bne 0x1dba24 <_ZN11SLinkedListI13CGestureEventED2Ev+0x14> */
/* @0x1dba58 mov r3, #0 */
/* @0x1dba5c mov r0, r7 */
/* @0x1dba60 str r3, [r7, #0x8] */
/* @0x1dba64 str r3, [r7, #0x4] */
/* @0x1dba68 str r3, [r7] */
/* @0x1dba6c pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x1dba10 · SLinkedList<CGestureEvent>::~SLinkedList() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1dba70 · CleanGestures() · size=192 · insn=48 */
/* @0x1dba70 push {r3, r4, r5, r6, r7, lr} */
/* @0x1dba74 ldr r6, [pc, #0xac] */
/* @0x1dba78 ldr r6, [pc, r6] */
/* @0x1dba7c ldr r4, [r6] */
/* @0x1dba80 cmp r4, #0 */
/* @0x1dba84 beq 0x1dbabc <_Z13CleanGesturesv+0x4c> */
/* @0x1dba88 ldr r3, [r4, #0x8] */
/* @0x1dba8c ldr r5, [r4] */
/* @0x1dba90 cmp r3, #0 */
/* @0x1dba94 mov r0, r3 */
/* @0x1dba98 beq 0x1dbaa8 <_Z13CleanGesturesv+0x38> */
/* @0x1dba9c ldr r3, [r3] */
/* @0x1dbaa0 ldr r3, [r3, #0x4] */
/* @0x1dbaa4 blx r3 */
/* @0x1dbaa8 mov r0, r4 */
/* @0x1dbaac mov r4, r5 */
/* @0x1dbab0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1dbab4 cmp r5, #0 */
/* @0x1dbab8 bne 0x1dba88 <_Z13CleanGesturesv+0x18> */
/* @0x1dbabc ldr r7, [pc, #0x68] */
/* @0x1dbac0 mov r3, #0 */
/* @0x1dbac4 str r3, [r6, #0x8] */
/* @0x1dbac8 ldr r7, [pc, r7] */
/* @0x1dbacc str r3, [r6, #0x4] */
/* @0x1dbad0 str r3, [r6] */
/* @0x1dbad4 ldr r4, [r7] */
/* @0x1dbad8 cmp r4, r3 */
/* @0x1dbadc beq 0x1dbb14 <_Z13CleanGesturesv+0xa4> */
/* @0x1dbae0 ldr r5, [r4, #0x8] */
/* @0x1dbae4 ldr r6, [r4] */
/* @0x1dbae8 cmp r5, #0 */
/* @0x1dbaec mov r0, r5 */
/* @0x1dbaf0 beq 0x1dbb00 <_Z13CleanGesturesv+0x90> */
/* @0x1dbaf4 bl 0x1db510 <_ZN13CGestureEventD2Ev> */
/* @0x1dbaf8 mov r0, r5 */
/* @0x1dbafc bl 0x27d1d0 <_ZdlPv> */
/* @0x1dbb00 mov r0, r4 */
/* @0x1dbb04 mov r4, r6 */
/* @0x1dbb08 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1dbb0c cmp r6, #0 */
/* @0x1dbb10 bne 0x1dbae0 <_Z13CleanGesturesv+0x70> */
/* @0x1dbb14 mov r3, #0 */
/* @0x1dbb18 str r3, [r7, #0x8] */
/* @0x1dbb1c str r3, [r7, #0x4] */
/* @0x1dbb20 str r3, [r7] */
/* @0x1dbb24 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1dbb28 mlaeq r1, r12, r1, r5 */
/* @0x1dbb2c eoreq r5, r1, r8, lsr r1 */

/* ── FUNC 0x1dbb30 · AddGestureFunctions() · size=812 · insn=203 */
/* @0x1dbb30 push {r4, lr} */
/* @0x1dbb34 mov r2, #1 */
/* @0x1dbb38 ldr r4, [pc, #0x268] */
/* @0x1dbb3c mov r3, #0 */
/* @0x1dbb40 ldr r1, [pc, #0x264] */
/* @0x1dbb44 add r4, pc, r4 */
/* @0x1dbb48 ldr r0, [pc, #0x260] */
/* @0x1dbb4c ldr r1, [r4, r1] */
/* @0x1dbb50 add r0, pc, r0 */
/* @0x1dbb54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbb58 ldr r1, [pc, #0x254] */
/* @0x1dbb5c ldr r0, [pc, #0x254] */
/* @0x1dbb60 mov r2, #1 */
/* @0x1dbb64 mov r3, #0 */
/* @0x1dbb68 ldr r1, [r4, r1] */
/* @0x1dbb6c add r0, pc, r0 */
/* @0x1dbb70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbb74 ldr r1, [pc, #0x240] */
/* @0x1dbb78 ldr r0, [pc, #0x240] */
/* @0x1dbb7c mov r2, #1 */
/* @0x1dbb80 mov r3, #0 */
/* @0x1dbb84 ldr r1, [r4, r1] */
/* @0x1dbb88 add r0, pc, r0 */
/* @0x1dbb8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbb90 ldr r1, [pc, #0x22c] */
/* @0x1dbb94 ldr r0, [pc, #0x22c] */
/* @0x1dbb98 mov r2, #1 */
/* @0x1dbb9c mov r3, #0 */
/* @0x1dbba0 ldr r1, [r4, r1] */
/* @0x1dbba4 add r0, pc, r0 */
/* @0x1dbba8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbbac ldr r1, [pc, #0x218] */
/* @0x1dbbb0 ldr r0, [pc, #0x218] */
/* @0x1dbbb4 mov r2, #1 */
/* @0x1dbbb8 mov r3, #0 */
/* @0x1dbbbc ldr r1, [r4, r1] */
/* @0x1dbbc0 add r0, pc, r0 */
/* @0x1dbbc4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbbc8 ldr r1, [pc, #0x204] */
/* @0x1dbbcc ldr r0, [pc, #0x204] */
/* @0x1dbbd0 mov r2, #1 */
/* @0x1dbbd4 mov r3, #0 */
/* @0x1dbbd8 ldr r1, [r4, r1] */
/* @0x1dbbdc add r0, pc, r0 */
/* @0x1dbbe0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbbe4 ldr r1, [pc, #0x1f0] */
/* @0x1dbbe8 ldr r0, [pc, #0x1f0] */
/* @0x1dbbec mov r2, #1 */
/* @0x1dbbf0 mov r3, #0 */
/* @0x1dbbf4 ldr r1, [r4, r1] */
/* @0x1dbbf8 add r0, pc, r0 */
/* @0x1dbbfc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbc00 ldr r1, [pc, #0x1dc] */
/* @0x1dbc04 ldr r0, [pc, #0x1dc] */
/* @0x1dbc08 mov r2, #1 */
/* @0x1dbc0c mov r3, #0 */
/* @0x1dbc10 ldr r1, [r4, r1] */
/* @0x1dbc14 add r0, pc, r0 */
/* @0x1dbc18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbc1c ldr r1, [pc, #0x1c8] */
/* @0x1dbc20 ldr r0, [pc, #0x1c8] */
/* @0x1dbc24 mov r2, #1 */
/* @0x1dbc28 mov r3, #0 */
/* @0x1dbc2c ldr r1, [r4, r1] */
/* @0x1dbc30 add r0, pc, r0 */
/* @0x1dbc34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbc38 ldr r1, [pc, #0x1b4] */
/* @0x1dbc3c ldr r0, [pc, #0x1b4] */
/* @0x1dbc40 mov r2, #1 */
/* @0x1dbc44 mov r3, #0 */
/* @0x1dbc48 ldr r1, [r4, r1] */
/* @0x1dbc4c add r0, pc, r0 */
/* @0x1dbc50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbc54 ldr r1, [pc, #0x1a0] */
/* @0x1dbc58 ldr r0, [pc, #0x1a0] */
/* @0x1dbc5c mov r2, #1 */
/* @0x1dbc60 mov r3, #0 */
/* @0x1dbc64 ldr r1, [r4, r1] */
/* @0x1dbc68 add r0, pc, r0 */
/* @0x1dbc6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbc70 ldr r1, [pc, #0x18c] */
/* @0x1dbc74 ldr r0, [pc, #0x18c] */
/* @0x1dbc78 mov r2, #0 */
/* @0x1dbc7c mov r3, r2 */
/* @0x1dbc80 ldr r1, [r4, r1] */
/* @0x1dbc84 add r0, pc, r0 */
/* @0x1dbc88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbc8c ldr r1, [pc, #0x178] */
/* @0x1dbc90 ldr r0, [pc, #0x178] */
/* @0x1dbc94 mov r2, #0 */
/* @0x1dbc98 mov r3, r2 */
/* @0x1dbc9c ldr r1, [r4, r1] */
/* @0x1dbca0 add r0, pc, r0 */
/* @0x1dbca4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbca8 ldr r1, [pc, #0x164] */
/* @0x1dbcac ldr r0, [pc, #0x164] */
/* @0x1dbcb0 mov r2, #0 */
/* @0x1dbcb4 mov r3, r2 */
/* @0x1dbcb8 ldr r1, [r4, r1] */
/* @0x1dbcbc add r0, pc, r0 */
/* @0x1dbcc0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbcc4 ldr r1, [pc, #0x150] */
/* @0x1dbcc8 ldr r0, [pc, #0x150] */
/* @0x1dbccc mov r2, #0 */
/* @0x1dbcd0 mov r3, r2 */
/* @0x1dbcd4 ldr r1, [r4, r1] */
/* @0x1dbcd8 add r0, pc, r0 */
/* @0x1dbcdc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbce0 ldr r1, [pc, #0x13c] */
/* @0x1dbce4 ldr r0, [pc, #0x13c] */
/* @0x1dbce8 mov r2, #0 */
/* @0x1dbcec mov r3, r2 */
/* @0x1dbcf0 ldr r1, [r4, r1] */
/* @0x1dbcf4 add r0, pc, r0 */
/* @0x1dbcf8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbcfc ldr r1, [pc, #0x128] */
/* @0x1dbd00 ldr r0, [pc, #0x128] */
/* @0x1dbd04 mov r2, #0 */
/* @0x1dbd08 mov r3, r2 */
/* @0x1dbd0c ldr r1, [r4, r1] */
/* @0x1dbd10 add r0, pc, r0 */
/* @0x1dbd14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbd18 ldr r1, [pc, #0x114] */
/* @0x1dbd1c ldr r0, [pc, #0x114] */
/* @0x1dbd20 mov r2, #0 */
/* @0x1dbd24 mov r3, r2 */
/* @0x1dbd28 ldr r1, [r4, r1] */
/* @0x1dbd2c add r0, pc, r0 */
/* @0x1dbd30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbd34 ldr r1, [pc, #0x100] */
/* @0x1dbd38 ldr r0, [pc, #0x100] */
/* @0x1dbd3c mov r2, #0 */
/* @0x1dbd40 mov r3, r2 */
/* @0x1dbd44 ldr r1, [r4, r1] */
/* @0x1dbd48 add r0, pc, r0 */
/* @0x1dbd4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbd50 ldr r1, [pc, #0xec] */
/* @0x1dbd54 ldr r0, [pc, #0xec] */
/* @0x1dbd58 mov r2, #0 */
/* @0x1dbd5c mov r3, r2 */
/* @0x1dbd60 ldr r1, [r4, r1] */
/* @0x1dbd64 add r0, pc, r0 */
/* @0x1dbd68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbd6c ldr r1, [pc, #0xd8] */
/* @0x1dbd70 ldr r0, [pc, #0xd8] */
/* @0x1dbd74 mov r2, #0 */
/* @0x1dbd78 mov r3, r2 */
/* @0x1dbd7c ldr r1, [r4, r1] */
/* @0x1dbd80 add r0, pc, r0 */
/* @0x1dbd84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbd88 ldr r1, [pc, #0xc4] */
/* @0x1dbd8c ldr r0, [pc, #0xc4] */
/* @0x1dbd90 mov r2, #0 */
/* @0x1dbd94 mov r3, r2 */
/* @0x1dbd98 ldr r1, [r4, r1] */
/* @0x1dbd9c add r0, pc, r0 */
/* @0x1dbda0 pop {r4, lr} */
/* @0x1dbda4 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1dbda8 eoreq r6, r1, r12, lsl #2 */
/* @0x1dbdac .word 0xffffefd8 */
/* @0x1dbdb0 andseq r5, r7, r0, ror r8 */
/* @0x1dbdb4 .word 0xffffefdc */
/* @0x1dbdb8 andseq r5, r7, r8, ror #16 */
/* @0x1dbdbc .word 0xffffefe0 */
/* @0x1dbdc0 andseq r5, r7, r4, ror #16 */
/* @0x1dbdc4 .word 0xffffefe4 */
/* @0x1dbdc8 andseq r5, r7, r12, asr r8 */
/* @0x1dbdcc .word 0xffffefe8 */
/* @0x1dbdd0 andseq r5, r7, r8, asr r8 */
/* @0x1dbdd4 .word 0xffffefec */
/* @0x1dbdd8 andseq r5, r7, r8, asr r8 */
/* @0x1dbddc .word 0xffffeff0 */
/* @0x1dbde0 andseq r5, r7, r4, asr r8 */
/* @0x1dbde4 .word 0xffffeff4 */
/* @0x1dbde8 andseq r5, r7, r4, asr r8 */
/* @0x1dbdec .word 0xffffeff8 */
/* @0x1dbdf0 andseq r5, r7, r4, asr r8 */
/* @0x1dbdf4 .word 0xffffeffc */
/* @0x1dbdf8 andseq r5, r7, r12, asr #16 */
/* @0x1dbdfc .word 0xfffff000 */
/* @0x1dbe00 andseq r5, r7, r8, asr #16 */
/* @0x1dbe04 .word 0xfffff004 */
/* @0x1dbe08 andseq r5, r7, r0, asr #16 */
/* @0x1dbe0c .word 0xfffff008 */
/* @0x1dbe10 andseq r5, r7, r12, lsr r8 */
/* @0x1dbe14 .word 0xfffff00c */
/* @0x1dbe18 andseq r5, r7, r12, lsr r8 */
/* @0x1dbe1c .word 0xfffff010 */
/* @0x1dbe20 andseq r5, r7, r8, lsr r8 */
/* @0x1dbe24 .word 0xfffff014 */
/* @0x1dbe28 andseq r5, r7, r8, lsr r8 */
/* @0x1dbe2c .word 0xfffff018 */
/* @0x1dbe30 andseq r5, r7, r12, lsr r8 */
/* @0x1dbe34 .word 0xfffff01c */
/* @0x1dbe38 andseq r5, r7, r12, lsr r8 */
/* @0x1dbe3c .word 0xfffff020 */
/* @0x1dbe40 andseq r5, r7, r0, asr #16 */
/* @0x1dbe44 .word 0xfffff024 */
/* @0x1dbe48 andseq r5, r7, r4, asr #16 */
/* @0x1dbe4c .word 0xfffff028 */
/* @0x1dbe50 andseq r5, r7, r0, asr #16 */
/* @0x1dbe54 .word 0xfffff02c */
/* @0x1dbe58 andseq r5, r7, r0, asr #16 */

/* ── FUNC 0x1dbe5c · _RefFactory<char const*>::Create(char const*, int&) · size=56 · insn=14 */
/* @0x1dbe5c push {r3, r4, r5, lr} */
/* @0x1dbe60 subs r4, r0, #0 */
/* @0x1dbe64 mov r5, r1 */
/* @0x1dbe68 beq 0x1dbe80 <_ZN11_RefFactoryIPKcE6CreateES1_Ri+0x24> */
/* @0x1dbe6c bl 0xb6538 <strlen@plt> */
/* @0x1dbe70 str r0, [r5] */
/* @0x1dbe74 mov r0, r4 */
/* @0x1dbe78 pop {r3, r4, r5, lr} */
/* @0x1dbe7c b 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1dbe80 mov r0, r4 */
/* @0x1dbe84 str r0, [r5] */
/* @0x1dbe88 mov r0, r4 */
/* @0x1dbe8c pop {r3, r4, r5, lr} */
/* @0x1dbe90 b 0xdb8c8 <_Z8YYStrDupPKc> */

/* ── FUNC 0x1dbe94 · Run_Score::Create() · size=4 · insn=1 */
/* @0x1dbe94 bx lr */
