/* libyoyo.so 覆盖卡组 0094
 * 函数 0x15e5f8..0x15f61c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x15e5f8 · GetVersionM() · size=20 · insn=5 */
/* @0x15e5f8 ldr r3, [pc, #0x8] */
/* @0x15e5fc ldr r3, [pc, r3] */
/* @0x15e600 ldrd r0, r1, [r3] */
/* @0x15e604 bx lr */
/* @0x15e608 mlaeq r9, r12, r8, r1 */

/* ── FUNC 0x15e60c · GetBrowserWidthM() · size=32 · insn=8 */
/* @0x15e60c ldr r3, [pc, #0x14] */
/* @0x15e610 ldr r3, [pc, r3] */
/* @0x15e614 ldr r0, [r3] */
/* @0x15e618 vmov s15, r0 */
/* @0x15e61c vcvt.f64.s32 d7, s15 */
/* @0x15e620 vmov r0, r1, d7 */
/* @0x15e624 bx lr */
/* @0x15e628 eoreq r1, r9, r12, lsl #17 */

/* ── FUNC 0x15e62c · GetBrowserHeightM() · size=32 · insn=8 */
/* @0x15e62c ldr r3, [pc, #0x14] */
/* @0x15e630 ldr r3, [pc, r3] */
/* @0x15e634 ldr r0, [r3] */
/* @0x15e638 vmov s15, r0 */
/* @0x15e63c vcvt.f64.s32 d7, s15 */
/* @0x15e640 vmov r0, r1, d7 */
/* @0x15e644 bx lr */
/* @0x15e648 eoreq r1, r9, r0, ror r8 */

/* ── FUNC 0x15e64c · GetDeviceM() · size=32 · insn=8 */
/* @0x15e64c ldr r3, [pc, #0x14] */
/* @0x15e650 ldr r3, [pc, r3] */
/* @0x15e654 ldrb r0, [r3] */
/* @0x15e658 cmp r0, #0 */
/* @0x15e65c movne r0, #2 */
/* @0x15e660 moveq r0, #0 */
/* @0x15e664 bx lr */
/* @0x15e668 eoreq r1, r9, r4, asr r8 */

/* ── FUNC 0x15e66c · GetCPUDetailsM() · size=36 · insn=9 */
/* @0x15e66c push {r4, lr} */
/* @0x15e670 bl 0x2a2e90 <android_getCpuFamily> */
/* @0x15e674 mov r4, r0 */
/* @0x15e678 bl 0x2a2ebc <android_getCpuFeatures> */
/* @0x15e67c uxtb r4, r4 */
/* @0x15e680 lsl r0, r0, #8 */
/* @0x15e684 uxth r0, r0 */
/* @0x15e688 orr r0, r0, r4 */
/* @0x15e68c pop {r4, pc} */

/* ── FUNC 0x15e690 · F_YoYo_MouseCheckButton(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x15e690 push {r4, r5, r6, r7, r8, lr} */
/* @0x15e694 mov r5, r0 */
/* @0x15e698 ldr r4, [sp, #0x18] */
/* @0x15e69c mov r7, r1 */
/* @0x15e6a0 mov r1, #1 */
/* @0x15e6a4 mov r8, r2 */
/* @0x15e6a8 mov r0, r4 */
/* @0x15e6ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x15e6b0 mov r1, #0 */
/* @0x15e6b4 mov r6, r0 */
/* @0x15e6b8 mov r0, r4 */
/* @0x15e6bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x15e6c0 mov r1, r7 */
/* @0x15e6c4 mov r2, r8 */
/* @0x15e6c8 mov r3, r6 */
/* @0x15e6cc str r0, [sp, #0x18] */
/* @0x15e6d0 mov r0, r5 */
/* @0x15e6d4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x15e6d8 b 0x160b2c <_Z25F_CheckMouseButton_CommonR6RValueP9CInstanceS2_ii> */

/* ── FUNC 0x15e6dc · F_YoYo_MouseCheckButtonPressed(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x15e6dc push {r4, r5, r6, r7, r8, lr} */
/* @0x15e6e0 mov r5, r0 */
/* @0x15e6e4 ldr r4, [sp, #0x18] */
/* @0x15e6e8 mov r7, r1 */
/* @0x15e6ec mov r1, #1 */
/* @0x15e6f0 mov r8, r2 */
/* @0x15e6f4 mov r0, r4 */
/* @0x15e6f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x15e6fc mov r1, #0 */
/* @0x15e700 mov r6, r0 */
/* @0x15e704 mov r0, r4 */
/* @0x15e708 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x15e70c mov r1, r7 */
/* @0x15e710 mov r2, r8 */
/* @0x15e714 mov r3, r6 */
/* @0x15e718 str r0, [sp, #0x18] */
/* @0x15e71c mov r0, r5 */
/* @0x15e720 pop {r4, r5, r6, r7, r8, lr} */
/* @0x15e724 b 0x160c0c <_Z32F_CheckMouseButtonPressed_CommonR6RValueP9CInstanceS2_ii> */

/* ── FUNC 0x15e728 · F_YoYo_MouseCheckButtonReleased(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x15e728 push {r4, r5, r6, r7, r8, lr} */
/* @0x15e72c mov r5, r0 */
/* @0x15e730 ldr r4, [sp, #0x18] */
/* @0x15e734 mov r7, r1 */
/* @0x15e738 mov r1, #1 */
/* @0x15e73c mov r8, r2 */
/* @0x15e740 mov r0, r4 */
/* @0x15e744 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x15e748 mov r1, #0 */
/* @0x15e74c mov r6, r0 */
/* @0x15e750 mov r0, r4 */
/* @0x15e754 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x15e758 mov r1, r7 */
/* @0x15e75c mov r2, r8 */
/* @0x15e760 mov r3, r6 */
/* @0x15e764 str r0, [sp, #0x18] */
/* @0x15e768 mov r0, r5 */
/* @0x15e76c pop {r4, r5, r6, r7, r8, lr} */
/* @0x15e770 b 0x160cec <_Z33F_CheckMouseButtonReleased_CommonR6RValueP9CInstanceS2_ii> */

/* ── FUNC 0x15e774 · F_YoYo_MouseX(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x15e774 push {r4, lr} */
/* @0x15e778 mov r3, #0 */
/* @0x15e77c mov r1, r3 */
/* @0x15e780 str r3, [r0, #0xc] */
/* @0x15e784 mov r4, r0 */
/* @0x15e788 ldr r0, [sp, #0x8] */
/* @0x15e78c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x15e790 bl 0x17ad8c <_Z27GR_Window_Views_Mouse_Get_Xi> */
/* @0x15e794 vmov s15, r0 */
/* @0x15e798 vcvt.f64.s32 d7, s15 */
/* @0x15e79c vmov r0, r1, d7 */
/* @0x15e7a0 vmov r2, s14 */
/* @0x15e7a4 mov r3, r1 */
/* @0x15e7a8 stm r4, {r2, r3} */
/* @0x15e7ac pop {r4, pc} */

/* ── FUNC 0x15e7b0 · F_YoYo_MouseY(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x15e7b0 push {r4, lr} */
/* @0x15e7b4 mov r3, #0 */
/* @0x15e7b8 mov r1, r3 */
/* @0x15e7bc str r3, [r0, #0xc] */
/* @0x15e7c0 mov r4, r0 */
/* @0x15e7c4 ldr r0, [sp, #0x8] */
/* @0x15e7c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x15e7cc bl 0x17adb0 <_Z27GR_Window_Views_Mouse_Get_Yi> */
/* @0x15e7d0 vmov s15, r0 */
/* @0x15e7d4 vcvt.f64.s32 d7, s15 */
/* @0x15e7d8 vmov r0, r1, d7 */
/* @0x15e7dc vmov r2, s14 */
/* @0x15e7e0 mov r3, r1 */
/* @0x15e7e4 stm r4, {r2, r3} */
/* @0x15e7e8 pop {r4, pc} */

/* ── FUNC 0x15e7ec · FacebookInitM() · size=92 · insn=23 */
/* @0x15e7ec push {r4, lr} */
/* @0x15e7f0 bl 0x290274 <getJNIEnv> */
/* @0x15e7f4 ldr r3, [pc, #0x40] */
/* @0x15e7f8 ldr r3, [pc, r3] */
/* @0x15e7fc ldr r1, [r3] */
/* @0x15e800 ldr r3, [r0] */
/* @0x15e804 ldr r3, [r3, #0x29c] */
/* @0x15e808 blx r3 */
/* @0x15e80c mov r4, r0 */
/* @0x15e810 bl 0x290274 <getJNIEnv> */
/* @0x15e814 ldr r1, [pc, #0x24] */
/* @0x15e818 mov r3, r4 */
/* @0x15e81c ldr r2, [pc, #0x20] */
/* @0x15e820 ldr r1, [pc, r1] */
/* @0x15e824 ldr r2, [pc, r2] */
/* @0x15e828 ldr r1, [r1] */
/* @0x15e82c ldr r2, [r2] */
/* @0x15e830 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x15e834 mov r0, #1 */
/* @0x15e838 pop {r4, pc} */
/* @0x15e83c .word 0x002916b0 */
/* @0x15e840 eoreq pc, r8, r4, lsl #3 */
/* @0x15e844 eoreq r1, r9, r8, lsl #13 */

/* ── FUNC 0x15e848 · FacebookCheckPermissionM(char*) · size=88 · insn=22 */
/* @0x15e848 push {r4, lr} */
/* @0x15e84c mov r4, r0 */
/* @0x15e850 bl 0x290274 <getJNIEnv> */
/* @0x15e854 mov r1, r4 */
/* @0x15e858 ldr r3, [r0] */
/* @0x15e85c ldr r3, [r3, #0x29c] */
/* @0x15e860 blx r3 */
/* @0x15e864 mov r4, r0 */
/* @0x15e868 bl 0x290274 <getJNIEnv> */
/* @0x15e86c ldr r1, [pc, #0x24] */
/* @0x15e870 mov r3, r4 */
/* @0x15e874 ldr r2, [pc, #0x20] */
/* @0x15e878 ldr r1, [pc, r1] */
/* @0x15e87c ldr r2, [pc, r2] */
/* @0x15e880 ldr r1, [r1] */
/* @0x15e884 ldr r2, [r2] */
/* @0x15e888 bl 0x15e0b0 <_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz> */
/* @0x15e88c adds r0, r0, #0 */
/* @0x15e890 movne r0, #1 */
/* @0x15e894 pop {r4, pc} */
/* @0x15e898 eoreq pc, r8, r12, lsr #2 */
/* @0x15e89c eoreq r1, r9, r4, lsr r6 */

/* ── FUNC 0x15e8a0 · FacebookPostMessageM(char*, char*, char*, char*, char*, char*, char*) · size=1092 · insn=273 */
/* @0x15e8a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x15e8a4 sub sp, sp, #300 */
/* @0x15e8a8 ldr r5, [pc, #0x3fc] */
/* @0x15e8ac mov r7, r3 */
/* @0x15e8b0 ldr r6, [sp, #0x154] */
/* @0x15e8b4 mov r9, r1 */
/* @0x15e8b8 ldr r5, [pc, r5] */
/* @0x15e8bc mov r8, r2 */
/* @0x15e8c0 ldr r1, [sp, #0x158] */
/* @0x15e8c4 mov r11, r0 */
/* @0x15e8c8 ldrb r3, [r6] */
/* @0x15e8cc ldr r2, [r5] */
/* @0x15e8d0 cmp r3, #0 */
/* @0x15e8d4 ldr r10, [sp, #0x150] */
/* @0x15e8d8 str r1, [sp, #0x1c] */
/* @0x15e8dc str r2, [sp, #0x124] */
/* @0x15e8e0 moveq r12, #10 */
/* @0x15e8e4 streq r3, [sp, #0x18] */
/* @0x15e8e8 beq 0x15e908 <_Z20FacebookPostMessageMPcS_S_S_S_S_S_+0x68> */
/* @0x15e8ec ldrb r3, [r1] */
/* @0x15e8f0 cmp r3, #0 */
/* @0x15e8f4 movne r12, #12 */
/* @0x15e8f8 moveq r12, #10 */
/* @0x15e8fc moveq r2, #0 */
/* @0x15e900 movne r2, #1 */
/* @0x15e904 str r2, [sp, #0x18] */
/* @0x15e908 str r12, [sp, #0x10] */
/* @0x15e90c bl 0x290274 <getJNIEnv> */
/* @0x15e910 mov r4, r0 */
/* @0x15e914 bl 0x290274 <getJNIEnv> */
/* @0x15e918 ldr r1, [pc, #0x390] */
/* @0x15e91c add r1, pc, r1 */
/* @0x15e920 ldr r3, [r0] */
/* @0x15e924 ldr r3, [r3, #0x18] */
/* @0x15e928 blx r3 */
/* @0x15e92c str r0, [sp, #0x14] */
/* @0x15e930 bl 0x290274 <getJNIEnv> */
/* @0x15e934 ldr r1, [pc, #0x378] */
/* @0x15e938 add r1, pc, r1 */
/* @0x15e93c ldr r3, [r0] */
/* @0x15e940 ldr r3, [r3, #0x29c] */
/* @0x15e944 blx r3 */
/* @0x15e948 ldr lr, [r4] */
/* @0x15e94c ldr r12, [sp, #0x10] */
/* @0x15e950 ldr r2, [sp, #0x14] */
/* @0x15e954 mov r1, r12 */
/* @0x15e958 ldr r12, [lr, #0x2b0] */
/* @0x15e95c mov r3, r0 */
/* @0x15e960 mov r0, r4 */
/* @0x15e964 blx r12 */
/* @0x15e968 mov r4, r0 */
/* @0x15e96c bl 0x290274 <getJNIEnv> */
/* @0x15e970 ldr r1, [pc, #0x340] */
/* @0x15e974 add r1, pc, r1 */
/* @0x15e978 ldr r3, [r0] */
/* @0x15e97c ldr r3, [r3, #0x29c] */
/* @0x15e980 blx r3 */
/* @0x15e984 str r0, [sp, #0x14] */
/* @0x15e988 bl 0x290274 <getJNIEnv> */
/* @0x15e98c mov r2, #0 */
/* @0x15e990 ldr r3, [sp, #0x14] */
/* @0x15e994 mov r1, r4 */
/* @0x15e998 ldr r12, [r0] */
/* @0x15e99c ldr r12, [r12, #0x2b8] */
/* @0x15e9a0 blx r12 */
/* @0x15e9a4 bl 0x290274 <getJNIEnv> */
/* @0x15e9a8 mov r1, r11 */
/* @0x15e9ac ldr r3, [r0] */
/* @0x15e9b0 ldr r3, [r3, #0x29c] */
/* @0x15e9b4 blx r3 */
/* @0x15e9b8 mov r11, r0 */
/* @0x15e9bc bl 0x290274 <getJNIEnv> */
/* @0x15e9c0 mov r2, #1 */
/* @0x15e9c4 mov r3, r11 */
/* @0x15e9c8 mov r1, r4 */
/* @0x15e9cc ldr r12, [r0] */
/* @0x15e9d0 ldr r12, [r12, #0x2b8] */
/* @0x15e9d4 blx r12 */
/* @0x15e9d8 bl 0x290274 <getJNIEnv> */
/* @0x15e9dc ldr r1, [pc, #0x2d8] */
/* @0x15e9e0 add r1, pc, r1 */
/* @0x15e9e4 ldr r3, [r0] */
/* @0x15e9e8 ldr r3, [r3, #0x29c] */
/* @0x15e9ec blx r3 */
/* @0x15e9f0 mov r11, r0 */
/* @0x15e9f4 bl 0x290274 <getJNIEnv> */
/* @0x15e9f8 mov r2, #2 */
/* @0x15e9fc mov r3, r11 */
/* @0x15ea00 mov r1, r4 */
/* @0x15ea04 ldr r12, [r0] */
/* @0x15ea08 ldr r12, [r12, #0x2b8] */
/* @0x15ea0c blx r12 */
/* @0x15ea10 bl 0x290274 <getJNIEnv> */
/* @0x15ea14 mov r1, r10 */
/* @0x15ea18 ldr r3, [r0] */
/* @0x15ea1c ldr r3, [r3, #0x29c] */
/* @0x15ea20 blx r3 */
/* @0x15ea24 mov r10, r0 */
/* @0x15ea28 bl 0x290274 <getJNIEnv> */
/* @0x15ea2c mov r2, #3 */
/* @0x15ea30 mov r3, r10 */
/* @0x15ea34 mov r1, r4 */
/* @0x15ea38 ldr r12, [r0] */
/* @0x15ea3c ldr r12, [r12, #0x2b8] */
/* @0x15ea40 blx r12 */
/* @0x15ea44 bl 0x290274 <getJNIEnv> */
/* @0x15ea48 ldr r1, [pc, #0x270] */
/* @0x15ea4c add r1, pc, r1 */
/* @0x15ea50 ldr r3, [r0] */
/* @0x15ea54 ldr r3, [r3, #0x29c] */
/* @0x15ea58 blx r3 */
/* @0x15ea5c mov r10, r0 */
/* @0x15ea60 bl 0x290274 <getJNIEnv> */
/* @0x15ea64 mov r2, #4 */
/* @0x15ea68 mov r3, r10 */
/* @0x15ea6c mov r1, r4 */
/* @0x15ea70 ldr r12, [r0] */
/* @0x15ea74 ldr r12, [r12, #0x2b8] */
/* @0x15ea78 blx r12 */
/* @0x15ea7c bl 0x290274 <getJNIEnv> */
/* @0x15ea80 mov r1, r9 */
/* @0x15ea84 ldr r3, [r0] */
/* @0x15ea88 ldr r3, [r3, #0x29c] */
/* @0x15ea8c blx r3 */
/* @0x15ea90 mov r9, r0 */
/* @0x15ea94 bl 0x290274 <getJNIEnv> */
/* @0x15ea98 mov r2, #5 */
/* @0x15ea9c mov r3, r9 */
/* @0x15eaa0 mov r1, r4 */
/* @0x15eaa4 ldr r12, [r0] */
/* @0x15eaa8 ldr r12, [r12, #0x2b8] */
/* @0x15eaac blx r12 */
/* @0x15eab0 bl 0x290274 <getJNIEnv> */
/* @0x15eab4 ldr r1, [pc, #0x208] */
/* @0x15eab8 add r1, pc, r1 */
/* @0x15eabc ldr r3, [r0] */
/* @0x15eac0 ldr r3, [r3, #0x29c] */
/* @0x15eac4 blx r3 */
/* @0x15eac8 mov r9, r0 */
/* @0x15eacc bl 0x290274 <getJNIEnv> */
/* @0x15ead0 mov r2, #6 */
/* @0x15ead4 mov r3, r9 */
/* @0x15ead8 mov r1, r4 */
/* @0x15eadc ldr r12, [r0] */
/* @0x15eae0 ldr r12, [r12, #0x2b8] */
/* @0x15eae4 blx r12 */
/* @0x15eae8 bl 0x290274 <getJNIEnv> */
/* @0x15eaec mov r1, r8 */
/* @0x15eaf0 ldr r3, [r0] */
/* @0x15eaf4 ldr r3, [r3, #0x29c] */
/* @0x15eaf8 blx r3 */
/* @0x15eafc mov r8, r0 */
/* @0x15eb00 bl 0x290274 <getJNIEnv> */
/* @0x15eb04 mov r2, #7 */
/* @0x15eb08 mov r3, r8 */
/* @0x15eb0c mov r1, r4 */
/* @0x15eb10 ldr r12, [r0] */
/* @0x15eb14 ldr r12, [r12, #0x2b8] */
/* @0x15eb18 blx r12 */
/* @0x15eb1c bl 0x290274 <getJNIEnv> */
/* @0x15eb20 ldr r1, [pc, #0x1a0] */
/* @0x15eb24 add r1, pc, r1 */
/* @0x15eb28 ldr r3, [r0] */
/* @0x15eb2c ldr r3, [r3, #0x29c] */
/* @0x15eb30 blx r3 */
/* @0x15eb34 mov r8, r0 */
/* @0x15eb38 bl 0x290274 <getJNIEnv> */
/* @0x15eb3c mov r2, #8 */
/* @0x15eb40 mov r3, r8 */
/* @0x15eb44 mov r1, r4 */
/* @0x15eb48 ldr r12, [r0] */
/* @0x15eb4c ldr r12, [r12, #0x2b8] */
/* @0x15eb50 blx r12 */
/* @0x15eb54 bl 0x290274 <getJNIEnv> */
/* @0x15eb58 mov r1, r7 */
/* @0x15eb5c ldr r3, [r0] */
/* @0x15eb60 ldr r3, [r3, #0x29c] */
/* @0x15eb64 blx r3 */
/* @0x15eb68 mov r7, r0 */
/* @0x15eb6c bl 0x290274 <getJNIEnv> */
/* @0x15eb70 mov r3, r7 */
/* @0x15eb74 mov r1, r4 */
/* @0x15eb78 mov r2, #9 */
/* @0x15eb7c ldr r12, [r0] */
/* @0x15eb80 ldr r12, [r12, #0x2b8] */
/* @0x15eb84 blx r12 */
/* @0x15eb88 ldr r3, [sp, #0x18] */
/* @0x15eb8c cmp r3, #0 */
/* @0x15eb90 beq 0x15ec24 <_Z20FacebookPostMessageMPcS_S_S_S_S_S_+0x384> */
/* @0x15eb94 bl 0x290274 <getJNIEnv> */
/* @0x15eb98 ldr r1, [pc, #0x12c] */
/* @0x15eb9c add r1, pc, r1 */
/* @0x15eba0 ldr r3, [r0] */
/* @0x15eba4 ldr r3, [r3, #0x29c] */
/* @0x15eba8 blx r3 */
/* @0x15ebac mov r7, r0 */
/* @0x15ebb0 bl 0x290274 <getJNIEnv> */
/* @0x15ebb4 mov r3, r7 */
/* @0x15ebb8 mov r1, r4 */
/* @0x15ebbc mov r2, #10 */
/* @0x15ebc0 ldr r12, [r0] */
/* @0x15ebc4 ldr r12, [r12, #0x2b8] */
/* @0x15ebc8 blx r12 */
/* @0x15ebcc ldr r1, [sp, #0x1c] */
/* @0x15ebd0 mov r3, r6 */
/* @0x15ebd4 ldr r2, [pc, #0xf4] */
/* @0x15ebd8 add r6, sp, #36 */
/* @0x15ebdc add r2, pc, r2 */
/* @0x15ebe0 str r1, [sp] */
/* @0x15ebe4 mov r0, r6 */
/* @0x15ebe8 mov r1, #256 */
/* @0x15ebec bl 0xb65c8 <snprintf@plt> */
/* @0x15ebf0 bl 0x290274 <getJNIEnv> */
/* @0x15ebf4 mov r1, r6 */
/* @0x15ebf8 ldr r3, [r0] */
/* @0x15ebfc ldr r3, [r3, #0x29c] */
/* @0x15ec00 blx r3 */
/* @0x15ec04 mov r6, r0 */
/* @0x15ec08 bl 0x290274 <getJNIEnv> */
/* @0x15ec0c mov r3, r6 */
/* @0x15ec10 mov r1, r4 */
/* @0x15ec14 mov r2, #11 */
/* @0x15ec18 ldr r12, [r0] */
/* @0x15ec1c ldr r12, [r12, #0x2b8] */
/* @0x15ec20 blx r12 */
/* @0x15ec24 bl 0x290274 <getJNIEnv> */
/* @0x15ec28 ldr r1, [pc, #0xa4] */
/* @0x15ec2c add r1, pc, r1 */
/* @0x15ec30 ldr r3, [r0] */
/* @0x15ec34 ldr r3, [r3, #0x29c] */
/* @0x15ec38 blx r3 */
/* @0x15ec3c mov r7, r0 */
/* @0x15ec40 bl 0x290274 <getJNIEnv> */
/* @0x15ec44 ldr r1, [pc, #0x8c] */
/* @0x15ec48 add r1, pc, r1 */
/* @0x15ec4c ldr r3, [r0] */
/* @0x15ec50 ldr r3, [r3, #0x29c] */
/* @0x15ec54 blx r3 */
/* @0x15ec58 mov r6, r0 */
/* @0x15ec5c bl 0x290274 <getJNIEnv> */
/* @0x15ec60 ldr r1, [pc, #0x74] */
/* @0x15ec64 mov r3, r7 */
/* @0x15ec68 ldr r2, [pc, #0x70] */
/* @0x15ec6c mvn r12, #0 */
/* @0x15ec70 ldr r1, [pc, r1] */
/* @0x15ec74 ldr r2, [pc, r2] */
/* @0x15ec78 ldr r1, [r1] */
/* @0x15ec7c ldr r2, [r2] */
/* @0x15ec80 str r6, [sp] */
/* @0x15ec84 stmib sp, {r4, r12} */
/* @0x15ec88 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x15ec8c ldr r2, [sp, #0x124] */
/* @0x15ec90 ldr r3, [r5] */
/* @0x15ec94 mov r0, #1 */
/* @0x15ec98 cmp r2, r3 */
/* @0x15ec9c bne 0x15eca8 <_Z20FacebookPostMessageMPcS_S_S_S_S_S_+0x408> */
/* @0x15eca0 add sp, sp, #300 */
/* @0x15eca4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x15eca8 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x15ecac mlaeq r8, r8, r0, pc */
/* @0x15ecb0 andseq r10, lr, r4, asr #28 */
/* @0x15ecb4 ldrsheq r0, [sp], -lr */
/* @0x15ecb8 mulseq sp, r4, lr */
/* @0x15ecbc mulseq lr, r4, sp */
/* @0x15ecc0 andseq r10, lr, r0, lsr sp */
/* @0x15ecc4 andseq r10, lr, r12, asr #25 */
/* @0x15ecc8 andseq r10, lr, r8, ror #24 */
/* @0x15eccc ldrsheq r10, [lr], -r8 */
/* @0x15ecd0 andseq r10, lr, r0, asr #23 */
/* @0x15ecd4 mulseq lr, r0, r11 */
/* @0x15ecd8 andseq r10, lr, r12, ror r11 */
/* @0x15ecdc eoreq lr, r8, r4, lsr sp */
/* @0x15ece0 eoreq r1, r9, r0, asr #4 */

/* ── FUNC 0x15ece4 · FacebookSendInviteM(char*, char*, char*, char*, int) · size=612 · insn=153 */
/* @0x15ece4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x15ece8 sub sp, sp, #28 */
/* @0x15ecec mov r6, r2 */
/* @0x15ecf0 mov r7, r1 */
/* @0x15ecf4 mov r8, r0 */
/* @0x15ecf8 ldr r5, [sp, #0x38] */
/* @0x15ecfc bl 0x290274 <getJNIEnv> */
/* @0x15ed00 mov r4, r0 */
/* @0x15ed04 bl 0x290274 <getJNIEnv> */
/* @0x15ed08 ldr r1, [pc, #0x218] */
/* @0x15ed0c add r1, pc, r1 */
/* @0x15ed10 ldr r3, [r0] */
/* @0x15ed14 ldr r3, [r3, #0x18] */
/* @0x15ed18 blx r3 */
/* @0x15ed1c mov r9, r0 */
/* @0x15ed20 bl 0x290274 <getJNIEnv> */
/* @0x15ed24 ldr r1, [pc, #0x200] */
/* @0x15ed28 add r1, pc, r1 */
/* @0x15ed2c ldr r3, [r0] */
/* @0x15ed30 ldr r3, [r3, #0x29c] */
/* @0x15ed34 blx r3 */
/* @0x15ed38 ldr r12, [r4] */
/* @0x15ed3c mov r2, r9 */
/* @0x15ed40 mov r1, #6 */
/* @0x15ed44 ldr r12, [r12, #0x2b0] */
/* @0x15ed48 mov r3, r0 */
/* @0x15ed4c mov r0, r4 */
/* @0x15ed50 blx r12 */
/* @0x15ed54 mov r4, r0 */
/* @0x15ed58 bl 0x290274 <getJNIEnv> */
/* @0x15ed5c ldr r1, [pc, #0x1cc] */
/* @0x15ed60 add r1, pc, r1 */
/* @0x15ed64 ldr r3, [r0] */
/* @0x15ed68 ldr r3, [r3, #0x29c] */
/* @0x15ed6c blx r3 */
/* @0x15ed70 mov r9, r0 */
/* @0x15ed74 bl 0x290274 <getJNIEnv> */
/* @0x15ed78 mov r2, #0 */
/* @0x15ed7c mov r3, r9 */
/* @0x15ed80 mov r1, r4 */
/* @0x15ed84 ldr r12, [r0] */
/* @0x15ed88 ldr r12, [r12, #0x2b8] */
/* @0x15ed8c blx r12 */
/* @0x15ed90 bl 0x290274 <getJNIEnv> */
/* @0x15ed94 mov r1, r8 */
/* @0x15ed98 ldr r3, [r0] */
/* @0x15ed9c ldr r3, [r3, #0x29c] */
/* @0x15eda0 blx r3 */
/* @0x15eda4 mov r8, r0 */
/* @0x15eda8 bl 0x290274 <getJNIEnv> */
/* @0x15edac mov r2, #1 */
/* @0x15edb0 mov r3, r8 */
/* @0x15edb4 mov r1, r4 */
/* @0x15edb8 ldr r12, [r0] */
/* @0x15edbc ldr r12, [r12, #0x2b8] */
/* @0x15edc0 blx r12 */
/* @0x15edc4 bl 0x290274 <getJNIEnv> */
/* @0x15edc8 ldr r1, [pc, #0x164] */
/* @0x15edcc add r1, pc, r1 */
/* @0x15edd0 ldr r3, [r0] */
/* @0x15edd4 ldr r3, [r3, #0x29c] */
/* @0x15edd8 blx r3 */
/* @0x15eddc mov r8, r0 */
/* @0x15ede0 bl 0x290274 <getJNIEnv> */
/* @0x15ede4 mov r2, #2 */
/* @0x15ede8 mov r3, r8 */
/* @0x15edec mov r1, r4 */
/* @0x15edf0 ldr r12, [r0] */
/* @0x15edf4 ldr r12, [r12, #0x2b8] */
/* @0x15edf8 blx r12 */
/* @0x15edfc bl 0x290274 <getJNIEnv> */
/* @0x15ee00 mov r1, r7 */
/* @0x15ee04 ldr r3, [r0] */
/* @0x15ee08 ldr r3, [r3, #0x29c] */
/* @0x15ee0c blx r3 */
/* @0x15ee10 mov r7, r0 */
/* @0x15ee14 bl 0x290274 <getJNIEnv> */
/* @0x15ee18 mov r2, #3 */
/* @0x15ee1c mov r3, r7 */
/* @0x15ee20 mov r1, r4 */
/* @0x15ee24 ldr r12, [r0] */
/* @0x15ee28 ldr r12, [r12, #0x2b8] */
/* @0x15ee2c blx r12 */
/* @0x15ee30 bl 0x290274 <getJNIEnv> */
/* @0x15ee34 ldr r1, [pc, #0xfc] */
/* @0x15ee38 add r1, pc, r1 */
/* @0x15ee3c ldr r3, [r0] */
/* @0x15ee40 ldr r3, [r3, #0x29c] */
/* @0x15ee44 blx r3 */
/* @0x15ee48 mov r7, r0 */
/* @0x15ee4c bl 0x290274 <getJNIEnv> */
/* @0x15ee50 mov r2, #4 */
/* @0x15ee54 mov r3, r7 */
/* @0x15ee58 mov r1, r4 */
/* @0x15ee5c ldr r12, [r0] */
/* @0x15ee60 ldr r12, [r12, #0x2b8] */
/* @0x15ee64 blx r12 */
/* @0x15ee68 bl 0x290274 <getJNIEnv> */
/* @0x15ee6c mov r1, r6 */
/* @0x15ee70 ldr r3, [r0] */
/* @0x15ee74 ldr r3, [r3, #0x29c] */
/* @0x15ee78 blx r3 */
/* @0x15ee7c mov r6, r0 */
/* @0x15ee80 bl 0x290274 <getJNIEnv> */
/* @0x15ee84 mov r3, r6 */
/* @0x15ee88 mov r1, r4 */
/* @0x15ee8c mov r2, #5 */
/* @0x15ee90 ldr r12, [r0] */
/* @0x15ee94 ldr r12, [r12, #0x2b8] */
/* @0x15ee98 blx r12 */
/* @0x15ee9c bl 0x290274 <getJNIEnv> */
/* @0x15eea0 ldr r1, [pc, #0x94] */
/* @0x15eea4 add r1, pc, r1 */
/* @0x15eea8 ldr r3, [r0] */
/* @0x15eeac ldr r3, [r3, #0x29c] */
/* @0x15eeb0 blx r3 */
/* @0x15eeb4 cmp r5, #0 */
/* @0x15eeb8 mov r6, r0 */
/* @0x15eebc blt 0x15eef4 <_Z19FacebookSendInviteMPcS_S_S_i+0x210> */
/* @0x15eec0 vmov s13, r5 */
/* @0x15eec4 add r12, sp, #24 */
/* @0x15eec8 mov r0, #0 */
/* @0x15eecc mov r3, #1 */
/* @0x15eed0 vcvt.f64.s32 d7, s13 */
/* @0x15eed4 mov r1, r0 */
/* @0x15eed8 mov r2, r0 */
/* @0x15eedc str r0, [sp, #0x14] */
/* @0x15eee0 vmov r8, r9, d7 */
/* @0x15eee4 strd r8, r9, [r12, #-16]! */
/* @0x15eee8 mov r0, r12 */
/* @0x15eeec str r12, [sp] */
/* @0x15eef0 bl 0xfed40 <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_> */
/* @0x15eef4 bl 0x290274 <getJNIEnv> */
/* @0x15eef8 ldr r1, [pc, #0x40] */
/* @0x15eefc ldr r2, [pc, #0x40] */
/* @0x15ef00 mov r3, r6 */
/* @0x15ef04 ldr r1, [pc, r1] */
/* @0x15ef08 ldr r2, [pc, r2] */
/* @0x15ef0c ldr r1, [r1] */
/* @0x15ef10 ldr r2, [r2] */
/* @0x15ef14 stm sp, {r4, r5} */
/* @0x15ef18 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x15ef1c mov r0, #1 */
/* @0x15ef20 add sp, sp, #28 */
/* @0x15ef24 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x15ef28 andseq r10, lr, r4, asr r10 */
/* @0x15ef2c andseq pc, r12, lr, lsl #28 */
/* @0x15ef30 andseq r10, lr, r12, ror #20 */
/* @0x15ef34 ldrheq r10, [lr], -r8 */
/* @0x15ef38 andseq r10, lr, r4, asr r9 */
/* @0x15ef3c andseq r10, lr, r0, lsr r9 */
/* @0x15ef40 eoreq lr, r8, r0, lsr #21 */
/* @0x15ef44 .word 0x00290fb0 */

/* ── FUNC 0x15ef48 · FacebookLogoutM() · size=52 · insn=13 */
/* @0x15ef48 push {r3, lr} */
/* @0x15ef4c bl 0x290274 <getJNIEnv> */
/* @0x15ef50 ldr r2, [pc, #0x1c] */
/* @0x15ef54 ldr r3, [pc, #0x1c] */
/* @0x15ef58 ldr r2, [pc, r2] */
/* @0x15ef5c ldr r3, [pc, r3] */
/* @0x15ef60 ldr r1, [r2] */
/* @0x15ef64 ldr r2, [r3] */
/* @0x15ef68 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x15ef6c mov r0, #1 */
/* @0x15ef70 pop {r3, pc} */
/* @0x15ef74 eoreq lr, r8, r12, asr #20 */
/* @0x15ef78 eoreq r0, r9, r0, ror #30 */

/* ── FUNC 0x15ef7c · FacebookUserIdM() · size=172 · insn=43 */
/* @0x15ef7c push {r3, r4, r5, lr} */
/* @0x15ef80 bl 0x290274 <getJNIEnv> */
/* @0x15ef84 ldr r2, [pc, #0x8c] */
/* @0x15ef88 ldr r3, [pc, #0x8c] */
/* @0x15ef8c ldr r2, [pc, r2] */
/* @0x15ef90 ldr r3, [pc, r3] */
/* @0x15ef94 ldr r1, [r2] */
/* @0x15ef98 ldr r2, [r3] */
/* @0x15ef9c bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz> */
/* @0x15efa0 mov r4, r0 */
/* @0x15efa4 bl 0x290274 <getJNIEnv> */
/* @0x15efa8 mov r1, r4 */
/* @0x15efac mov r2, #0 */
/* @0x15efb0 ldr r3, [r0] */
/* @0x15efb4 ldr r3, [r3, #0x2a4] */
/* @0x15efb8 blx r3 */
/* @0x15efbc mov r2, #255 */
/* @0x15efc0 mov r5, r0 */
/* @0x15efc4 mov r1, r0 */
/* @0x15efc8 ldr r0, [pc, #0x50] */
/* @0x15efcc add r0, pc, r0 */
/* @0x15efd0 bl 0xb6568 <strncpy@plt> */
/* @0x15efd4 cmp r5, #0 */
/* @0x15efd8 cmpne r4, #0 */
/* @0x15efdc beq 0x15f00c <_Z15FacebookUserIdMv+0x90> */
/* @0x15efe0 bl 0x290274 <getJNIEnv> */
/* @0x15efe4 mov r1, r4 */
/* @0x15efe8 mov r2, r5 */
/* @0x15efec ldr r3, [r0] */
/* @0x15eff0 ldr r3, [r3, #0x2a8] */
/* @0x15eff4 blx r3 */
/* @0x15eff8 bl 0x290274 <getJNIEnv> */
/* @0x15effc mov r1, r4 */
/* @0x15f000 ldr r3, [r0] */
/* @0x15f004 ldr r3, [r3, #0x5c] */
/* @0x15f008 blx r3 */
/* @0x15f00c ldr r0, [pc, #0x10] */
/* @0x15f010 add r0, pc, r0 */
/* @0x15f014 pop {r3, r4, r5, pc} */
/* @0x15f018 eoreq lr, r8, r8, lsl r10 */
/* @0x15f01c eoreq r0, r9, r0, lsr pc */
/* @0x15f020 eorseq r5, r2, r12, ror #21 */
/* @0x15f024 eorseq r5, r2, r8, lsr #21 */

/* ── FUNC 0x15f028 · FacebookAccessTokenM() · size=180 · insn=45 */
/* @0x15f028 push {r3, r4, r5, lr} */
/* @0x15f02c bl 0x290274 <getJNIEnv> */
/* @0x15f030 ldr r2, [pc, #0x94] */
/* @0x15f034 ldr r3, [pc, #0x94] */
/* @0x15f038 ldr r2, [pc, r2] */
/* @0x15f03c ldr r3, [pc, r3] */
/* @0x15f040 ldr r1, [r2] */
/* @0x15f044 ldr r2, [r3] */
/* @0x15f048 bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz> */
/* @0x15f04c mov r4, r0 */
/* @0x15f050 bl 0x290274 <getJNIEnv> */
/* @0x15f054 mov r1, r4 */
/* @0x15f058 mov r2, #0 */
/* @0x15f05c ldr r3, [r0] */
/* @0x15f060 ldr r3, [r3, #0x2a4] */
/* @0x15f064 blx r3 */
/* @0x15f068 mov r2, #255 */
/* @0x15f06c mov r5, r0 */
/* @0x15f070 ldr r0, [pc, #0x5c] */
/* @0x15f074 mov r1, r5 */
/* @0x15f078 add r0, pc, r0 */
/* @0x15f07c add r0, r0, #256 */
/* @0x15f080 bl 0xb6568 <strncpy@plt> */
/* @0x15f084 cmp r5, #0 */
/* @0x15f088 cmpne r4, #0 */
/* @0x15f08c beq 0x15f0bc <_Z20FacebookAccessTokenMv+0x94> */
/* @0x15f090 bl 0x290274 <getJNIEnv> */
/* @0x15f094 mov r1, r4 */
/* @0x15f098 mov r2, r5 */
/* @0x15f09c ldr r3, [r0] */
/* @0x15f0a0 ldr r3, [r3, #0x2a8] */
/* @0x15f0a4 blx r3 */
/* @0x15f0a8 bl 0x290274 <getJNIEnv> */
/* @0x15f0ac mov r1, r4 */
/* @0x15f0b0 ldr r3, [r0] */
/* @0x15f0b4 ldr r3, [r3, #0x5c] */
/* @0x15f0b8 blx r3 */
/* @0x15f0bc ldr r0, [pc, #0x14] */
/* @0x15f0c0 add r0, pc, r0 */
/* @0x15f0c4 add r0, r0, #256 */
/* @0x15f0c8 pop {r3, r4, r5, pc} */
/* @0x15f0cc eoreq lr, r8, r12, ror #18 */
/* @0x15f0d0 eoreq r0, r9, r8, lsl #29 */
/* @0x15f0d4 eorseq r5, r2, r0, asr #20 */
/* @0x15f0d8 ldrshteq r5, [r2], -r8 */

/* ── FUNC 0x15f0dc · FacebookLoginStatusM() · size=224 · insn=56 */
/* @0x15f0dc push {r3, r4, r5, lr} */
/* @0x15f0e0 bl 0x290274 <getJNIEnv> */
/* @0x15f0e4 ldr r2, [pc, #0xb8] */
/* @0x15f0e8 ldr r3, [pc, #0xb8] */
/* @0x15f0ec ldr r2, [pc, r2] */
/* @0x15f0f0 ldr r3, [pc, r3] */
/* @0x15f0f4 ldr r1, [r2] */
/* @0x15f0f8 ldr r2, [r3] */
/* @0x15f0fc bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz> */
/* @0x15f100 subs r5, r0, #0 */
/* @0x15f104 beq 0x15f180 <_Z20FacebookLoginStatusMv+0xa4> */
/* @0x15f108 bl 0x290274 <getJNIEnv> */
/* @0x15f10c mov r1, r5 */
/* @0x15f110 mov r2, #0 */
/* @0x15f114 ldr r3, [r0] */
/* @0x15f118 ldr r3, [r3, #0x2a4] */
/* @0x15f11c blx r3 */
/* @0x15f120 mov r2, #31 */
/* @0x15f124 mov r4, r0 */
/* @0x15f128 ldr r0, [pc, #0x7c] */
/* @0x15f12c mov r1, r4 */
/* @0x15f130 add r0, pc, r0 */
/* @0x15f134 add r0, r0, #512 */
/* @0x15f138 bl 0xb6568 <strncpy@plt> */
/* @0x15f13c cmp r4, #0 */
/* @0x15f140 beq 0x15f170 <_Z20FacebookLoginStatusMv+0x94> */
/* @0x15f144 bl 0x290274 <getJNIEnv> */
/* @0x15f148 mov r1, r5 */
/* @0x15f14c mov r2, r4 */
/* @0x15f150 ldr r3, [r0] */
/* @0x15f154 ldr r3, [r3, #0x2a8] */
/* @0x15f158 blx r3 */
/* @0x15f15c bl 0x290274 <getJNIEnv> */
/* @0x15f160 mov r1, r5 */
/* @0x15f164 ldr r3, [r0] */
/* @0x15f168 ldr r3, [r3, #0x5c] */
/* @0x15f16c blx r3 */
/* @0x15f170 ldr r0, [pc, #0x38] */
/* @0x15f174 add r0, pc, r0 */
/* @0x15f178 add r0, r0, #512 */
/* @0x15f17c pop {r3, r4, r5, pc} */
/* @0x15f180 ldr r3, [pc, #0x2c] */
/* @0x15f184 ldr r1, [pc, #0x2c] */
/* @0x15f188 ldr r3, [pc, r3] */
/* @0x15f18c add r1, pc, r1 */
/* @0x15f190 ldr r0, [r3] */
/* @0x15f194 ldr r3, [r0] */
/* @0x15f198 ldr r3, [r3, #0xc] */
/* @0x15f19c blx r3 */
/* @0x15f1a0 b 0x15f170 <_Z20FacebookLoginStatusMv+0x94> */
/* @0x15f1a4 .word 0x0028e8b8 */
/* @0x15f1a8 .word 0x00290dd8 */
/* @0x15f1ac eorseq r5, r2, r8, lsl #19 */
/* @0x15f1b0 eorseq r5, r2, r4, asr #18 */
/* @0x15f1b4 eoreq lr, r8, r12, lsl #11 */
/* @0x15f1b8 andseq r10, lr, r4, asr r6 */

/* ── FUNC 0x15f1bc · RestrictOrientation(bool, bool, bool, bool) · size=96 · insn=24 */
/* @0x15f1bc push {r4, r5, r6, r7, lr} */
/* @0x15f1c0 sub sp, sp, #20 */
/* @0x15f1c4 mov r7, r1 */
/* @0x15f1c8 mov r6, r2 */
/* @0x15f1cc mov r4, r3 */
/* @0x15f1d0 mov r5, r0 */
/* @0x15f1d4 bl 0x290274 <getJNIEnv> */
/* @0x15f1d8 ldr lr, [pc, #0x34] */
/* @0x15f1dc ldr r12, [pc, #0x34] */
/* @0x15f1e0 mov r3, r5 */
/* @0x15f1e4 ldr lr, [pc, lr] */
/* @0x15f1e8 mov r5, #0 */
/* @0x15f1ec ldr r12, [pc, r12] */
/* @0x15f1f0 ldr r1, [lr] */
/* @0x15f1f4 ldr r2, [r12] */
/* @0x15f1f8 str r7, [sp] */
/* @0x15f1fc str r6, [sp, #0x4] */
/* @0x15f200 str r4, [sp, #0x8] */
/* @0x15f204 str r5, [sp, #0xc] */
/* @0x15f208 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x15f20c add sp, sp, #20 */
/* @0x15f210 pop {r4, r5, r6, r7, pc} */
/* @0x15f214 eoreq lr, r8, r0, asr #15 */
/* @0x15f218 eoreq r0, r9, r0, ror #25 */

/* ── FUNC 0x15f21c · GetLanguageString() · size=20 · insn=5 */
/* @0x15f21c ldr r3, [pc, #0x8] */
/* @0x15f220 ldr r3, [pc, r3] */
/* @0x15f224 ldr r0, [r3] */
/* @0x15f228 bx lr */
/* @0x15f22c .word 0x00290cb0 */

/* ── FUNC 0x15f230 · GetRegionString() · size=20 · insn=5 */
/* @0x15f230 ldr r3, [pc, #0x8] */
/* @0x15f234 ldr r3, [pc, r3] */
/* @0x15f238 ldr r0, [r3] */
/* @0x15f23c bx lr */
/* @0x15f240 eoreq r0, r9, r0, lsr #25 */

/* ── FUNC 0x15f244 · GetDPIX() · size=20 · insn=5 */
/* @0x15f244 ldr r3, [pc, #0x8] */
/* @0x15f248 ldr r3, [pc, r3] */
/* @0x15f24c ldr r0, [r3] */
/* @0x15f250 bx lr */
/* @0x15f254 mlaeq r9, r0, r12, r0 */

/* ── FUNC 0x15f258 · GetDPIY() · size=20 · insn=5 */
/* @0x15f258 ldr r3, [pc, #0x8] */
/* @0x15f25c ldr r3, [pc, r3] */
/* @0x15f260 ldr r0, [r3] */
/* @0x15f264 bx lr */
/* @0x15f268 eoreq r0, r9, r0, lsl #25 */

/* ── FUNC 0x15f26c · GetIsNetworkConnected() · size=56 · insn=14 */
/* @0x15f26c push {r3, lr} */
/* @0x15f270 bl 0x290274 <getJNIEnv> */
/* @0x15f274 ldr r2, [pc, #0x20] */
/* @0x15f278 ldr r3, [pc, #0x20] */
/* @0x15f27c ldr r2, [pc, r2] */
/* @0x15f280 ldr r3, [pc, r3] */
/* @0x15f284 ldr r1, [r2] */
/* @0x15f288 ldr r2, [r3] */
/* @0x15f28c bl 0x15e0b0 <_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz> */
/* @0x15f290 adds r0, r0, #0 */
/* @0x15f294 movne r0, #1 */
/* @0x15f298 pop {r3, pc} */
/* @0x15f29c eoreq lr, r8, r8, lsr #14 */
/* @0x15f2a0 eoreq r0, r9, r0, ror #24 */

/* ── FUNC 0x15f2a4 · YYPowersaveEnable(bool) · size=56 · insn=14 */
/* @0x15f2a4 push {r4, lr} */
/* @0x15f2a8 mov r4, r0 */
/* @0x15f2ac bl 0x290274 <getJNIEnv> */
/* @0x15f2b0 ldr r1, [pc, #0x1c] */
/* @0x15f2b4 mov r3, r4 */
/* @0x15f2b8 ldr r2, [pc, #0x18] */
/* @0x15f2bc ldr r1, [pc, r1] */
/* @0x15f2c0 ldr r2, [pc, r2] */
/* @0x15f2c4 ldr r1, [r1] */
/* @0x15f2c8 ldr r2, [r2] */
/* @0x15f2cc pop {r4, lr} */
/* @0x15f2d0 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x15f2d4 eoreq lr, r8, r8, ror #13 */
/* @0x15f2d8 eoreq r0, r9, r4, lsr #24 */

/* ── FUNC 0x15f2dc · YYCheckPermission(char const*) · size=80 · insn=20 */
/* @0x15f2dc push {r4, lr} */
/* @0x15f2e0 mov r4, r0 */
/* @0x15f2e4 bl 0x290274 <getJNIEnv> */
/* @0x15f2e8 mov r1, r4 */
/* @0x15f2ec ldr r3, [r0] */
/* @0x15f2f0 ldr r3, [r3, #0x29c] */
/* @0x15f2f4 blx r3 */
/* @0x15f2f8 mov r4, r0 */
/* @0x15f2fc bl 0x290274 <getJNIEnv> */
/* @0x15f300 ldr r1, [pc, #0x1c] */
/* @0x15f304 mov r3, r4 */
/* @0x15f308 ldr r2, [pc, #0x18] */
/* @0x15f30c ldr r1, [pc, r1] */
/* @0x15f310 ldr r2, [pc, r2] */
/* @0x15f314 ldr r1, [r1] */
/* @0x15f318 ldr r2, [r2] */
/* @0x15f31c pop {r4, lr} */
/* @0x15f320 b 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x15f324 mlaeq r8, r8, r6, lr */
/* @0x15f328 .word 0x00290bd8 */

/* ── FUNC 0x15f32c · YYRequestPermission(char const*) · size=80 · insn=20 */
/* @0x15f32c push {r4, lr} */
/* @0x15f330 mov r4, r0 */
/* @0x15f334 bl 0x290274 <getJNIEnv> */
/* @0x15f338 mov r1, r4 */
/* @0x15f33c ldr r3, [r0] */
/* @0x15f340 ldr r3, [r3, #0x29c] */
/* @0x15f344 blx r3 */
/* @0x15f348 mov r4, r0 */
/* @0x15f34c bl 0x290274 <getJNIEnv> */
/* @0x15f350 ldr r1, [pc, #0x1c] */
/* @0x15f354 mov r3, r4 */
/* @0x15f358 ldr r2, [pc, #0x18] */
/* @0x15f35c ldr r1, [pc, r1] */
/* @0x15f360 ldr r2, [pc, r2] */
/* @0x15f364 ldr r1, [r1] */
/* @0x15f368 ldr r2, [r2] */
/* @0x15f36c pop {r4, lr} */
/* @0x15f370 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x15f374 eoreq lr, r8, r8, asr #12 */
/* @0x15f378 eoreq r0, r9, r12, lsl #23 */

/* ── FUNC 0x15f37c · YYLockOrientation(bool) · size=4 · insn=1 */
/* @0x15f37c bx lr */

/* ── FUNC 0x15f380 · YYAnalyticsEvent(char const*) · size=80 · insn=20 */
/* @0x15f380 push {r4, lr} */
/* @0x15f384 mov r4, r0 */
/* @0x15f388 bl 0x290274 <getJNIEnv> */
/* @0x15f38c mov r1, r4 */
/* @0x15f390 ldr r3, [r0] */
/* @0x15f394 ldr r3, [r3, #0x29c] */
/* @0x15f398 blx r3 */
/* @0x15f39c mov r4, r0 */
/* @0x15f3a0 bl 0x290274 <getJNIEnv> */
/* @0x15f3a4 ldr r1, [pc, #0x1c] */
/* @0x15f3a8 mov r3, r4 */
/* @0x15f3ac ldr r2, [pc, #0x18] */
/* @0x15f3b0 ldr r1, [pc, r1] */
/* @0x15f3b4 ldr r2, [pc, r2] */
/* @0x15f3b8 ldr r1, [r1] */
/* @0x15f3bc ldr r2, [r2] */
/* @0x15f3c0 pop {r4, lr} */
/* @0x15f3c4 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x15f3c8 .word 0x0028e5f4 */
/* @0x15f3cc eoreq r0, r9, r12, lsr r11 */

/* ── FUNC 0x15f3d0 · YYAnalyticsEventExt(char const*, int, SKeyValueNumber const*) · size=420 · insn=105 */
/* @0x15f3d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x15f3d4 sub sp, sp, #60 */
/* @0x15f3d8 ldr r10, [pc, #0x17c] */
/* @0x15f3dc mov r5, r2 */
/* @0x15f3e0 lsl r8, r1, #1 */
/* @0x15f3e4 str r0, [sp, #0xc] */
/* @0x15f3e8 ldr r10, [pc, r10] */
/* @0x15f3ec ldr r3, [r10] */
/* @0x15f3f0 str r3, [sp, #0x34] */
/* @0x15f3f4 bl 0x290274 <getJNIEnv> */
/* @0x15f3f8 mov r4, r0 */
/* @0x15f3fc bl 0x290274 <getJNIEnv> */
/* @0x15f400 ldr r1, [pc, #0x158] */
/* @0x15f404 add r1, pc, r1 */
/* @0x15f408 ldr r3, [r0] */
/* @0x15f40c ldr r3, [r3, #0x18] */
/* @0x15f410 blx r3 */
/* @0x15f414 mov r6, r0 */
/* @0x15f418 bl 0x290274 <getJNIEnv> */
/* @0x15f41c ldr r1, [pc, #0x140] */
/* @0x15f420 add r1, pc, r1 */
/* @0x15f424 ldr r3, [r0] */
/* @0x15f428 ldr r3, [r3, #0x29c] */
/* @0x15f42c blx r3 */
/* @0x15f430 ldr r12, [r4] */
/* @0x15f434 mov r2, r6 */
/* @0x15f438 mov r1, r8 */
/* @0x15f43c ldr r12, [r12, #0x2b0] */
/* @0x15f440 mov r3, r0 */
/* @0x15f444 mov r0, r4 */
/* @0x15f448 blx r12 */
/* @0x15f44c cmp r8, #0 */
/* @0x15f450 mov r6, r0 */
/* @0x15f454 ble 0x15f500 <_Z19YYAnalyticsEventExtPKciPK15SKeyValueNumber+0x130> */
/* @0x15f458 ldr r9, [pc, #0x108] */
/* @0x15f45c add r5, r5, #16 */
/* @0x15f460 add r7, sp, #20 */
/* @0x15f464 mov r4, #0 */
/* @0x15f468 add r9, pc, r9 */
/* @0x15f46c bl 0x290274 <getJNIEnv> */
/* @0x15f470 ldr r1, [r5, #-0x10] */
/* @0x15f474 add r5, r5, #16 */
/* @0x15f478 ldr r3, [r0] */
/* @0x15f47c ldr r3, [r3, #0x29c] */
/* @0x15f480 blx r3 */
/* @0x15f484 mov r11, r0 */
/* @0x15f488 bl 0x290274 <getJNIEnv> */
/* @0x15f48c mov r3, r11 */
/* @0x15f490 mov r2, r4 */
/* @0x15f494 mov r1, r6 */
/* @0x15f498 ldr r12, [r0] */
/* @0x15f49c ldr r12, [r12, #0x2b8] */
/* @0x15f4a0 blx r12 */
/* @0x15f4a4 vldr d7, [r5, #-24] */
/* @0x15f4a8 vcvt.s32.f64 s13, d7 */
/* @0x15f4ac mov r2, r9 */
/* @0x15f4b0 mov r1, #32 */
/* @0x15f4b4 mov r0, r7 */
/* @0x15f4b8 vmov r3, s13 */
/* @0x15f4bc bl 0xb65c8 <snprintf@plt> */
/* @0x15f4c0 bl 0x290274 <getJNIEnv> */
/* @0x15f4c4 mov r1, r7 */
/* @0x15f4c8 ldr r3, [r0] */
/* @0x15f4cc ldr r3, [r3, #0x29c] */
/* @0x15f4d0 blx r3 */
/* @0x15f4d4 mov r11, r0 */
/* @0x15f4d8 bl 0x290274 <getJNIEnv> */
/* @0x15f4dc add r2, r4, #1 */
/* @0x15f4e0 mov r3, r11 */
/* @0x15f4e4 mov r1, r6 */
/* @0x15f4e8 add r4, r4, #2 */
/* @0x15f4ec ldr r12, [r0] */
/* @0x15f4f0 ldr r12, [r12, #0x2b8] */
/* @0x15f4f4 blx r12 */
/* @0x15f4f8 cmp r8, r4 */
/* @0x15f4fc bgt 0x15f46c <_Z19YYAnalyticsEventExtPKciPK15SKeyValueNumber+0x9c> */
/* @0x15f500 bl 0x290274 <getJNIEnv> */
/* @0x15f504 ldr r1, [sp, #0xc] */
/* @0x15f508 ldr r3, [r0] */
/* @0x15f50c ldr r3, [r3, #0x29c] */
/* @0x15f510 blx r3 */
/* @0x15f514 mov r4, r0 */
/* @0x15f518 bl 0x290274 <getJNIEnv> */
/* @0x15f51c ldr r1, [pc, #0x48] */
/* @0x15f520 mov r3, r4 */
/* @0x15f524 ldr r2, [pc, #0x44] */
/* @0x15f528 ldr r1, [pc, r1] */
/* @0x15f52c ldr r2, [pc, r2] */
/* @0x15f530 ldr r1, [r1] */
/* @0x15f534 ldr r2, [r2] */
/* @0x15f538 str r6, [sp] */
/* @0x15f53c bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x15f540 ldr r2, [sp, #0x34] */
/* @0x15f544 ldr r3, [r10] */
/* @0x15f548 cmp r2, r3 */
/* @0x15f54c bne 0x15f558 <_Z19YYAnalyticsEventExtPKciPK15SKeyValueNumber+0x188> */
/* @0x15f550 add sp, sp, #60 */
/* @0x15f554 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x15f558 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x15f55c eoreq lr, r8, r8, ror #10 */
/* @0x15f560 andseq r10, lr, r12, asr r3 */
/* @0x15f564 andseq pc, r12, r6, lsl r7 */
/* @0x15f568 andseq r3, sp, r4, lsr #1 */
/* @0x15f56c eoreq lr, r8, r12, ror r4 */
/* @0x15f570 eoreq r0, r9, r8, asr #19 */

/* ── FUNC 0x15f574 · YYUDID(char**) · size=168 · insn=42 */
/* @0x15f574 push {r4, r5, r6, lr} */
/* @0x15f578 mov r4, r0 */
/* @0x15f57c bl 0x290274 <getJNIEnv> */
/* @0x15f580 ldr r2, [pc, #0x8c] */
/* @0x15f584 ldr r3, [pc, #0x8c] */
/* @0x15f588 ldr r2, [pc, r2] */
/* @0x15f58c ldr r3, [pc, r3] */
/* @0x15f590 ldr r1, [r2] */
/* @0x15f594 ldr r2, [r3] */
/* @0x15f598 bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz> */
/* @0x15f59c mov r5, r0 */
/* @0x15f5a0 bl 0x290274 <getJNIEnv> */
/* @0x15f5a4 mov r1, r5 */
/* @0x15f5a8 mov r2, #0 */
/* @0x15f5ac ldr r3, [r0] */
/* @0x15f5b0 ldr r3, [r3, #0x2a4] */
/* @0x15f5b4 blx r3 */
/* @0x15f5b8 mov r6, r0 */
/* @0x15f5bc ldr r0, [r4] */
/* @0x15f5c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x15f5c4 mov r3, #0 */
/* @0x15f5c8 mov r0, r6 */
/* @0x15f5cc str r3, [r4] */
/* @0x15f5d0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x15f5d4 cmp r6, #0 */
/* @0x15f5d8 cmpne r5, #0 */
/* @0x15f5dc str r0, [r4] */
/* @0x15f5e0 popeq {r4, r5, r6, pc} */
/* @0x15f5e4 bl 0x290274 <getJNIEnv> */
/* @0x15f5e8 mov r1, r5 */
/* @0x15f5ec mov r2, r6 */
/* @0x15f5f0 ldr r3, [r0] */
/* @0x15f5f4 ldr r3, [r3, #0x2a8] */
/* @0x15f5f8 blx r3 */
/* @0x15f5fc bl 0x290274 <getJNIEnv> */
/* @0x15f600 mov r1, r5 */
/* @0x15f604 ldr r3, [r0] */
/* @0x15f608 ldr r3, [r3, #0x5c] */
/* @0x15f60c blx r3 */
/* @0x15f610 pop {r4, r5, r6, pc} */
/* @0x15f614 eoreq lr, r8, r12, lsl r4 */
/* @0x15f618 eoreq r0, r9, r12, ror #18 */

/* ── FUNC 0x15f61c · SetAndroidLaunchedFromPlayer(char const*, bool) · size=96 · insn=24 */
/* @0x15f61c push {r4, r5, lr} */
/* @0x15f620 sub sp, sp, #12 */
/* @0x15f624 mov r4, r1 */
/* @0x15f628 mov r5, r0 */
/* @0x15f62c bl 0x290274 <getJNIEnv> */
/* @0x15f630 mov r1, r5 */
/* @0x15f634 ldr r3, [r0] */
/* @0x15f638 ldr r3, [r3, #0x29c] */
/* @0x15f63c blx r3 */
/* @0x15f640 mov r5, r0 */
/* @0x15f644 bl 0x290274 <getJNIEnv> */
/* @0x15f648 ldr r12, [pc, #0x24] */
/* @0x15f64c mov r3, r5 */
/* @0x15f650 ldr r2, [pc, #0x20] */
/* @0x15f654 ldr r12, [pc, r12] */
/* @0x15f658 ldr r2, [pc, r2] */
/* @0x15f65c ldr r1, [r12] */
/* @0x15f660 ldr r2, [r2] */
/* @0x15f664 str r4, [sp] */
/* @0x15f668 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x15f66c add sp, sp, #12 */
/* @0x15f670 pop {r4, r5, pc} */
/* @0x15f674 eoreq lr, r8, r0, asr r3 */
/* @0x15f678 eoreq r0, r9, r4, lsr #17 */
