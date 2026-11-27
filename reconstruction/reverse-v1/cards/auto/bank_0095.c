/* libyoyo.so 覆盖卡组 0095
 * 函数 0x15f67c..0x160ea4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x15f67c · FacebookLoginM(int, int) · size=572 · insn=143 */
/* @0x15f67c cmp r0, #0 */
/* @0x15f680 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x15f684 sub sp, sp, #68 */
/* @0x15f688 blt 0x15f810 <_Z14FacebookLoginMii+0x194> */
/* @0x15f68c vmov s13, r0 */
/* @0x15f690 add r7, sp, #16 */
/* @0x15f694 mov r4, #0 */
/* @0x15f698 mov r3, #1 */
/* @0x15f69c vcvt.f64.s32 d7, s13 */
/* @0x15f6a0 mov r2, r4 */
/* @0x15f6a4 mov r1, r4 */
/* @0x15f6a8 mov r0, r7 */
/* @0x15f6ac add r10, sp, #32 */
/* @0x15f6b0 str r10, [sp] */
/* @0x15f6b4 str r4, [sp, #0x10] */
/* @0x15f6b8 str r4, [sp, #0x2c] */
/* @0x15f6bc vstr d7, [sp, #32] */
/* @0x15f6c0 bl 0xfc350 <_Z12F_DsListSizeR6RValueP9CInstanceS2_iPS_> */
/* @0x15f6c4 vldr d7, [sp, #16] */
/* @0x15f6c8 vcvt.s32.f64 s13, d7 */
/* @0x15f6cc vmov r8, s13 */
/* @0x15f6d0 bl 0x290274 <getJNIEnv> */
/* @0x15f6d4 mov r5, r0 */
/* @0x15f6d8 bl 0x290274 <getJNIEnv> */
/* @0x15f6dc ldr r1, [pc, #0x1b4] */
/* @0x15f6e0 add r1, pc, r1 */
/* @0x15f6e4 ldr r3, [r0] */
/* @0x15f6e8 ldr r3, [r3, #0x18] */
/* @0x15f6ec blx r3 */
/* @0x15f6f0 mov r6, r0 */
/* @0x15f6f4 bl 0x290274 <getJNIEnv> */
/* @0x15f6f8 ldr r1, [pc, #0x19c] */
/* @0x15f6fc add r1, pc, r1 */
/* @0x15f700 ldr r3, [r0] */
/* @0x15f704 ldr r3, [r3, #0x29c] */
/* @0x15f708 blx r3 */
/* @0x15f70c ldr r12, [r5] */
/* @0x15f710 mov r2, r6 */
/* @0x15f714 mov r1, r8 */
/* @0x15f718 ldr r12, [r12, #0x2b0] */
/* @0x15f71c mov r3, r0 */
/* @0x15f720 mov r0, r5 */
/* @0x15f724 blx r12 */
/* @0x15f728 cmp r8, r4 */
/* @0x15f72c mov r9, r0 */
/* @0x15f730 ble 0x15f868 <_Z14FacebookLoginMii+0x1ec> */
/* @0x15f734 ldr r3, [pc, #0x164] */
/* @0x15f738 mov r5, r4 */
/* @0x15f73c ldr r2, [pc, #0x160] */
/* @0x15f740 ldr r3, [pc, r3] */
/* @0x15f744 add r2, pc, r2 */
/* @0x15f748 str r2, [sp, #0xc] */
/* @0x15f74c ldr r6, [r3] */
/* @0x15f750 b 0x15f76c <_Z14FacebookLoginMii+0xf0> */
/* @0x15f754 cmp r4, r8 */
/* @0x15f758 mov r2, #5 */
/* @0x15f75c str r5, [sp, #0x18] */
/* @0x15f760 str r2, [sp, #0x1c] */
/* @0x15f764 str r5, [sp, #0x10] */
/* @0x15f768 beq 0x15f868 <_Z14FacebookLoginMii+0x1ec> */
/* @0x15f76c vmov s13, r4 */
/* @0x15f770 mov r1, #0 */
/* @0x15f774 mov r2, r1 */
/* @0x15f778 mov r0, r7 */
/* @0x15f77c vcvt.f64.s32 d7, s13 */
/* @0x15f780 mov r3, #2 */
/* @0x15f784 str r10, [sp] */
/* @0x15f788 str r5, [sp, #0x3c] */
/* @0x15f78c vstr d7, [sp, #48] */
/* @0x15f790 bl 0x106634 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_> */
/* @0x15f794 ldr r3, [r6] */
/* @0x15f798 mov r0, r6 */
/* @0x15f79c ldr r2, [sp, #0x10] */
/* @0x15f7a0 ldr r1, [sp, #0xc] */
/* @0x15f7a4 ldr r3, [r3, #0xc] */
/* @0x15f7a8 ldr r2, [r2] */
/* @0x15f7ac blx r3 */
/* @0x15f7b0 bl 0x290274 <getJNIEnv> */
/* @0x15f7b4 ldr r3, [sp, #0x10] */
/* @0x15f7b8 ldr r1, [r3] */
/* @0x15f7bc ldr r3, [r0] */
/* @0x15f7c0 ldr r3, [r3, #0x29c] */
/* @0x15f7c4 blx r3 */
/* @0x15f7c8 mov r11, r0 */
/* @0x15f7cc bl 0x290274 <getJNIEnv> */
/* @0x15f7d0 mov r3, r11 */
/* @0x15f7d4 mov r2, r4 */
/* @0x15f7d8 mov r1, r9 */
/* @0x15f7dc add r4, r4, #1 */
/* @0x15f7e0 ldr r12, [r0] */
/* @0x15f7e4 ldr r12, [r12, #0x2b8] */
/* @0x15f7e8 blx r12 */
/* @0x15f7ec ldr r3, [sp, #0x1c] */
/* @0x15f7f0 sub r3, r3, #1 */
/* @0x15f7f4 bic r3, r3, #-16777216 */
/* @0x15f7f8 bic r3, r3, #3 */
/* @0x15f7fc cmp r3, #0 */
/* @0x15f800 bne 0x15f754 <_Z14FacebookLoginMii+0xd8> */
/* @0x15f804 mov r0, r7 */
/* @0x15f808 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x15f80c b 0x15f754 <_Z14FacebookLoginMii+0xd8> */
/* @0x15f810 bl 0x290274 <getJNIEnv> */
/* @0x15f814 mov r4, r0 */
/* @0x15f818 bl 0x290274 <getJNIEnv> */
/* @0x15f81c ldr r1, [pc, #0x84] */
/* @0x15f820 add r1, pc, r1 */
/* @0x15f824 ldr r3, [r0] */
/* @0x15f828 ldr r3, [r3, #0x18] */
/* @0x15f82c blx r3 */
/* @0x15f830 mov r5, r0 */
/* @0x15f834 bl 0x290274 <getJNIEnv> */
/* @0x15f838 ldr r1, [pc, #0x6c] */
/* @0x15f83c add r1, pc, r1 */
/* @0x15f840 ldr r3, [r0] */
/* @0x15f844 ldr r3, [r3, #0x29c] */
/* @0x15f848 blx r3 */
/* @0x15f84c ldr r12, [r4] */
/* @0x15f850 mov r2, r5 */
/* @0x15f854 mov r1, #1 */
/* @0x15f858 ldr r12, [r12, #0x2b0] */
/* @0x15f85c mov r3, r0 */
/* @0x15f860 mov r0, r4 */
/* @0x15f864 blx r12 */
/* @0x15f868 bl 0x290274 <getJNIEnv> */
/* @0x15f86c ldr r1, [pc, #0x3c] */
/* @0x15f870 ldr r2, [pc, #0x3c] */
/* @0x15f874 mov r3, r9 */
/* @0x15f878 ldr r1, [pc, r1] */
/* @0x15f87c ldr r2, [pc, r2] */
/* @0x15f880 ldr r1, [r1] */
/* @0x15f884 ldr r2, [r2] */
/* @0x15f888 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x15f88c mov r0, #1 */
/* @0x15f890 add sp, sp, #68 */
/* @0x15f894 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x15f898 andseq r10, lr, r0, lsl #1 */
/* @0x15f89c andseq pc, r12, r10, lsr r4 */
/* @0x15f8a0 .word 0x0028dfd4 */
/* @0x15f8a4 andseq r10, lr, r12, asr #1 */
/* @0x15f8a8 andseq r9, lr, r0, asr #30 */
/* @0x15f8ac ldrsheq pc, [r12], -r10 */
/* @0x15f8b0 eoreq lr, r8, r12, lsr #2 */
/* @0x15f8b4 eoreq r0, r9, r4, lsl #13 */

/* ── FUNC 0x15f8b8 · FacebookRequestPermissionsM(int, bool) · size=496 · insn=124 */
/* @0x15f8b8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x15f8bc cmp r0, #0 */
/* @0x15f8c0 sub sp, sp, #68 */
/* @0x15f8c4 str r1, [sp, #0xc] */
/* @0x15f8c8 blt 0x15fa84 <_Z27FacebookRequestPermissionsMib+0x1cc> */
/* @0x15f8cc vmov s13, r0 */
/* @0x15f8d0 add r7, sp, #16 */
/* @0x15f8d4 mov r4, #0 */
/* @0x15f8d8 add r9, sp, #32 */
/* @0x15f8dc vcvt.f64.s32 d7, s13 */
/* @0x15f8e0 mov r0, r7 */
/* @0x15f8e4 mov r1, r4 */
/* @0x15f8e8 mov r2, r4 */
/* @0x15f8ec str r9, [sp] */
/* @0x15f8f0 mov r3, #1 */
/* @0x15f8f4 str r4, [sp, #0x10] */
/* @0x15f8f8 str r4, [sp, #0x2c] */
/* @0x15f8fc vstr d7, [sp, #32] */
/* @0x15f900 bl 0xfc350 <_Z12F_DsListSizeR6RValueP9CInstanceS2_iPS_> */
/* @0x15f904 vldr d7, [sp, #16] */
/* @0x15f908 vcvt.s32.f64 s13, d7 */
/* @0x15f90c vmov r8, s13 */
/* @0x15f910 cmp r8, r4 */
/* @0x15f914 ble 0x15fa84 <_Z27FacebookRequestPermissionsMib+0x1cc> */
/* @0x15f918 bl 0x290274 <getJNIEnv> */
/* @0x15f91c mov r5, r4 */
/* @0x15f920 mov r6, r0 */
/* @0x15f924 bl 0x290274 <getJNIEnv> */
/* @0x15f928 ldr r1, [pc, #0x160] */
/* @0x15f92c ldr r12, [pc, #0x160] */
/* @0x15f930 add r1, pc, r1 */
/* @0x15f934 add r12, pc, r12 */
/* @0x15f938 str r12, [sp, #0x8] */
/* @0x15f93c ldr r3, [r0] */
/* @0x15f940 ldr r3, [r3, #0x18] */
/* @0x15f944 blx r3 */
/* @0x15f948 mov r10, r0 */
/* @0x15f94c bl 0x290274 <getJNIEnv> */
/* @0x15f950 ldr r1, [pc, #0x140] */
/* @0x15f954 add r1, pc, r1 */
/* @0x15f958 ldr r3, [r0] */
/* @0x15f95c ldr r3, [r3, #0x29c] */
/* @0x15f960 blx r3 */
/* @0x15f964 ldr r12, [r6] */
/* @0x15f968 mov r2, r10 */
/* @0x15f96c mov r1, r8 */
/* @0x15f970 ldr r12, [r12, #0x2b0] */
/* @0x15f974 mov r3, r0 */
/* @0x15f978 mov r0, r6 */
/* @0x15f97c blx r12 */
/* @0x15f980 ldr r3, [pc, #0x114] */
/* @0x15f984 ldr r3, [pc, r3] */
/* @0x15f988 ldr r6, [r3] */
/* @0x15f98c mov r10, r0 */
/* @0x15f990 b 0x15f9ac <_Z27FacebookRequestPermissionsMib+0xf4> */
/* @0x15f994 cmp r4, r8 */
/* @0x15f998 mov r3, #5 */
/* @0x15f99c str r5, [sp, #0x18] */
/* @0x15f9a0 str r3, [sp, #0x1c] */
/* @0x15f9a4 str r5, [sp, #0x10] */
/* @0x15f9a8 beq 0x15fa50 <_Z27FacebookRequestPermissionsMib+0x198> */
/* @0x15f9ac vmov s13, r4 */
/* @0x15f9b0 mov r1, #0 */
/* @0x15f9b4 mov r2, r1 */
/* @0x15f9b8 mov r0, r7 */
/* @0x15f9bc vcvt.f64.s32 d7, s13 */
/* @0x15f9c0 mov r3, #2 */
/* @0x15f9c4 str r9, [sp] */
/* @0x15f9c8 str r5, [sp, #0x3c] */
/* @0x15f9cc vstr d7, [sp, #48] */
/* @0x15f9d0 bl 0x106634 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_> */
/* @0x15f9d4 ldr r3, [r6] */
/* @0x15f9d8 mov r0, r6 */
/* @0x15f9dc ldr r2, [sp, #0x10] */
/* @0x15f9e0 ldr r1, [sp, #0x8] */
/* @0x15f9e4 ldr r3, [r3, #0xc] */
/* @0x15f9e8 ldr r2, [r2] */
/* @0x15f9ec blx r3 */
/* @0x15f9f0 bl 0x290274 <getJNIEnv> */
/* @0x15f9f4 ldr r3, [sp, #0x10] */
/* @0x15f9f8 ldr r1, [r3] */
/* @0x15f9fc ldr r3, [r0] */
/* @0x15fa00 ldr r3, [r3, #0x29c] */
/* @0x15fa04 blx r3 */
/* @0x15fa08 mov r11, r0 */
/* @0x15fa0c bl 0x290274 <getJNIEnv> */
/* @0x15fa10 mov r3, r11 */
/* @0x15fa14 mov r2, r4 */
/* @0x15fa18 mov r1, r10 */
/* @0x15fa1c add r4, r4, #1 */
/* @0x15fa20 ldr r12, [r0] */
/* @0x15fa24 ldr r12, [r12, #0x2b8] */
/* @0x15fa28 blx r12 */
/* @0x15fa2c ldr r3, [sp, #0x1c] */
/* @0x15fa30 sub r3, r3, #1 */
/* @0x15fa34 bic r3, r3, #-16777216 */
/* @0x15fa38 bic r3, r3, #3 */
/* @0x15fa3c cmp r3, #0 */
/* @0x15fa40 bne 0x15f994 <_Z27FacebookRequestPermissionsMib+0xdc> */
/* @0x15fa44 mov r0, r7 */
/* @0x15fa48 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x15fa4c b 0x15f994 <_Z27FacebookRequestPermissionsMib+0xdc> */
/* @0x15fa50 bl 0x290274 <getJNIEnv> */
/* @0x15fa54 ldr r1, [pc, #0x44] */
/* @0x15fa58 ldr r2, [pc, #0x44] */
/* @0x15fa5c mov r3, r10 */
/* @0x15fa60 ldr r12, [sp, #0xc] */
/* @0x15fa64 ldr r1, [pc, r1] */
/* @0x15fa68 ldr r2, [pc, r2] */
/* @0x15fa6c ldr r1, [r1] */
/* @0x15fa70 ldr r2, [r2] */
/* @0x15fa74 str r12, [sp] */
/* @0x15fa78 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x15fa7c add sp, sp, #68 */
/* @0x15fa80 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x15fa84 mvn r0, #0 */
/* @0x15fa88 add sp, sp, #68 */
/* @0x15fa8c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x15fa90 andseq r9, lr, r0, lsr lr */
/* @0x15fa94 ldrsbeq r9, [lr], -r12 */
/* @0x15fa98 andseq pc, r12, r2, ror #3 */
/* @0x15fa9c mlaeq r8, r0, sp, sp */
/* @0x15faa0 eoreq sp, r8, r0, asr #30 */
/* @0x15faa4 mlaeq r9, r12, r4, r0 */

/* ── FUNC 0x15faa8 · BuildFacebookWallPost(int, _jobjectArray*&) · size=1012 · insn=253 */
/* @0x15faa8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x15faac sub sp, sp, #620 */
/* @0x15fab0 ldr r7, [pc, #0x3bc] */
/* @0x15fab4 cmp r0, #0 */
/* @0x15fab8 ldr r3, [pc, #0x3b8] */
/* @0x15fabc mov r6, #0 */
/* @0x15fac0 add r7, pc, r7 */
/* @0x15fac4 mov r9, r1 */
/* @0x15fac8 ldr r3, [r7, r3] */
/* @0x15facc str r6, [sp, #0x24] */
/* @0x15fad0 str r3, [sp, #0x18] */
/* @0x15fad4 ldr r3, [r3] */
/* @0x15fad8 str r3, [sp, #0x264] */
/* @0x15fadc blt 0x15fb44 <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x9c> */
/* @0x15fae0 vmov s15, r0 */
/* @0x15fae4 add r8, sp, #36 */
/* @0x15fae8 mov r3, #1 */
/* @0x15faec add r10, sp, #68 */
/* @0x15faf0 vcvt.f64.s32 d7, s15 */
/* @0x15faf4 mov r1, r6 */
/* @0x15faf8 mov r0, r8 */
/* @0x15fafc str r10, [sp] */
/* @0x15fb00 mov r2, r6 */
/* @0x15fb04 str r6, [sp, #0x50] */
/* @0x15fb08 vmov r4, r5, d7 */
/* @0x15fb0c vstr s14, [sp, #68] */
/* @0x15fb10 str r5, [sp, #0x48] */
/* @0x15fb14 bl 0x104394 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_> */
/* @0x15fb18 ldr r3, [sp, #0x30] */
/* @0x15fb1c cmp r3, #1 */
/* @0x15fb20 beq 0x15fc00 <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x158> */
/* @0x15fb24 ldr r3, [pc, #0x350] */
/* @0x15fb28 ldr r1, [pc, #0x350] */
/* @0x15fb2c ldr r3, [r7, r3] */
/* @0x15fb30 add r1, pc, r1 */
/* @0x15fb34 ldr r0, [r3] */
/* @0x15fb38 ldr r3, [r0] */
/* @0x15fb3c ldr r3, [r3, #0xc] */
/* @0x15fb40 blx r3 */
/* @0x15fb44 bl 0x290274 <getJNIEnv> */
/* @0x15fb48 ldr r4, [pc, #0x334] */
/* @0x15fb4c add r4, pc, r4 */
/* @0x15fb50 mov r5, r0 */
/* @0x15fb54 bl 0x290274 <getJNIEnv> */
/* @0x15fb58 ldr r1, [pc, #0x328] */
/* @0x15fb5c add r1, pc, r1 */
/* @0x15fb60 ldr r3, [r0] */
/* @0x15fb64 ldr r3, [r3, #0x18] */
/* @0x15fb68 blx r3 */
/* @0x15fb6c mov r6, r0 */
/* @0x15fb70 bl 0x290274 <getJNIEnv> */
/* @0x15fb74 mov r1, r4 */
/* @0x15fb78 ldr r3, [r0] */
/* @0x15fb7c ldr r3, [r3, #0x29c] */
/* @0x15fb80 blx r3 */
/* @0x15fb84 ldr r12, [r5] */
/* @0x15fb88 mov r2, r6 */
/* @0x15fb8c mov r1, #2 */
/* @0x15fb90 ldr r12, [r12, #0x2b0] */
/* @0x15fb94 mov r3, r0 */
/* @0x15fb98 mov r0, r5 */
/* @0x15fb9c blx r12 */
/* @0x15fba0 str r0, [r9] */
/* @0x15fba4 bl 0x290274 <getJNIEnv> */
/* @0x15fba8 ldr r6, [r9] */
/* @0x15fbac mov r5, r0 */
/* @0x15fbb0 bl 0x290274 <getJNIEnv> */
/* @0x15fbb4 mov r1, r4 */
/* @0x15fbb8 ldr r3, [r0] */
/* @0x15fbbc ldr r3, [r3, #0x29c] */
/* @0x15fbc0 blx r3 */
/* @0x15fbc4 ldr r12, [r5] */
/* @0x15fbc8 mov r1, r6 */
/* @0x15fbcc mov r2, #1 */
/* @0x15fbd0 ldr r12, [r12, #0x2b8] */
/* @0x15fbd4 mov r3, r0 */
/* @0x15fbd8 mov r0, r5 */
/* @0x15fbdc blx r12 */
/* @0x15fbe0 mov r0, #0 */
/* @0x15fbe4 ldr r12, [sp, #0x18] */
/* @0x15fbe8 ldr r2, [sp, #0x264] */
/* @0x15fbec ldr r3, [r12] */
/* @0x15fbf0 cmp r2, r3 */
/* @0x15fbf4 bne 0x15fe70 <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x3c8> */
/* @0x15fbf8 add sp, sp, #620 */
/* @0x15fbfc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x15fc00 ldr r2, [sp, #0x24] */
/* @0x15fc04 cmp r2, r6 */
/* @0x15fc08 beq 0x15fb24 <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x7c> */
/* @0x15fc0c mov r1, r6 */
/* @0x15fc10 mov r2, r6 */
/* @0x15fc14 add r0, sp, #52 */
/* @0x15fc18 str r10, [sp] */
/* @0x15fc1c str r6, [sp, #0x34] */
/* @0x15fc20 mov r5, r6 */
/* @0x15fc24 str r6, [sp, #0x38] */
/* @0x15fc28 bl 0xfeea0 <_Z11F_DsMapSizeR6RValueP9CInstanceS2_iPS_> */
/* @0x15fc2c bl 0x290274 <getJNIEnv> */
/* @0x15fc30 ldr r2, [sp, #0x34] */
/* @0x15fc34 ldr r3, [sp, #0x38] */
/* @0x15fc38 add r12, sp, #84 */
/* @0x15fc3c str r12, [sp, #0x10] */
/* @0x15fc40 mov r4, r6 */
/* @0x15fc44 ldr r1, [pc, #0x240] */
/* @0x15fc48 add r6, sp, #100 */
/* @0x15fc4c vmov d7, r2, r3 */
/* @0x15fc50 ldr r2, [pc, #0x238] */
/* @0x15fc54 add r1, pc, r1 */
/* @0x15fc58 str r1, [sp, #0x1c] */
/* @0x15fc5c vcvt.s32.f64 s15, d7 */
/* @0x15fc60 add r2, pc, r2 */
/* @0x15fc64 str r2, [sp, #0x14] */
/* @0x15fc68 vmov r12, s15 */
/* @0x15fc6c mov r11, r0 */
/* @0x15fc70 lsl r12, r12, #1 */
/* @0x15fc74 str r12, [sp, #0x8] */
/* @0x15fc78 bl 0x290274 <getJNIEnv> */
/* @0x15fc7c ldr r1, [pc, #0x210] */
/* @0x15fc80 add r1, pc, r1 */
/* @0x15fc84 ldr r3, [r0] */
/* @0x15fc88 ldr r3, [r3, #0x18] */
/* @0x15fc8c blx r3 */
/* @0x15fc90 str r0, [sp, #0xc] */
/* @0x15fc94 bl 0x290274 <getJNIEnv> */
/* @0x15fc98 ldr r1, [pc, #0x1f8] */
/* @0x15fc9c add r1, pc, r1 */
/* @0x15fca0 ldr r3, [r0] */
/* @0x15fca4 ldr r3, [r3, #0x29c] */
/* @0x15fca8 blx r3 */
/* @0x15fcac ldr lr, [r11] */
/* @0x15fcb0 ldr r12, [sp, #0x8] */
/* @0x15fcb4 ldr r2, [sp, #0xc] */
/* @0x15fcb8 mov r1, r12 */
/* @0x15fcbc ldr r12, [lr, #0x2b0] */
/* @0x15fcc0 mov r3, r0 */
/* @0x15fcc4 mov r0, r11 */
/* @0x15fcc8 blx r12 */
/* @0x15fccc ldr r2, [pc, #0x1a8] */
/* @0x15fcd0 ldr r3, [sp, #0x24] */
/* @0x15fcd4 ldr r11, [sp, #0x30] */
/* @0x15fcd8 str r0, [r9] */
/* @0x15fcdc ldr r2, [r7, r2] */
/* @0x15fce0 ldr r7, [r2] */
/* @0x15fce4 b 0x15fe2c <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x384> */
/* @0x15fce8 mov r1, #5 */
/* @0x15fcec str r4, [sp, #0x2c] */
/* @0x15fcf0 str r1, [sp, #0x30] */
/* @0x15fcf4 add r11, r5, #1 */
/* @0x15fcf8 str r4, [sp, #0x24] */
/* @0x15fcfc bl 0x290274 <getJNIEnv> */
/* @0x15fd00 mov r1, r6 */
/* @0x15fd04 ldr r3, [r0] */
/* @0x15fd08 ldr r3, [r3, #0x29c] */
/* @0x15fd0c blx r3 */
/* @0x15fd10 str r0, [sp, #0xc] */
/* @0x15fd14 bl 0x290274 <getJNIEnv> */
/* @0x15fd18 ldr r3, [sp, #0xc] */
/* @0x15fd1c mov r2, r5 */
/* @0x15fd20 ldr r1, [r9] */
/* @0x15fd24 ldr r12, [r0] */
/* @0x15fd28 ldr r12, [r12, #0x2b8] */
/* @0x15fd2c blx r12 */
/* @0x15fd30 add r0, sp, #84 */
/* @0x15fd34 mov r1, r6 */
/* @0x15fd38 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x15fd3c mov r1, #0 */
/* @0x15fd40 mov r3, #2 */
/* @0x15fd44 str r10, [sp] */
/* @0x15fd48 mov r2, r1 */
/* @0x15fd4c mov r0, r8 */
/* @0x15fd50 bl 0x106bcc <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_> */
/* @0x15fd54 ldr r3, [sp, #0x30] */
/* @0x15fd58 cmp r3, #1 */
/* @0x15fd5c beq 0x15fd78 <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x2d0> */
/* @0x15fd60 ldr r3, [r7] */
/* @0x15fd64 mov r0, r7 */
/* @0x15fd68 ldr r1, [sp, #0x1c] */
/* @0x15fd6c ldr r3, [r3, #0xc] */
/* @0x15fd70 blx r3 */
/* @0x15fd74 str r4, [sp, #0x24] */
/* @0x15fd78 bl 0x290274 <getJNIEnv> */
/* @0x15fd7c ldr r3, [sp, #0x24] */
/* @0x15fd80 add r5, r5, #2 */
/* @0x15fd84 ldr r1, [r3] */
/* @0x15fd88 ldr r3, [r0] */
/* @0x15fd8c ldr r3, [r3, #0x29c] */
/* @0x15fd90 blx r3 */
/* @0x15fd94 str r0, [sp, #0xc] */
/* @0x15fd98 bl 0x290274 <getJNIEnv> */
/* @0x15fd9c ldr r3, [sp, #0xc] */
/* @0x15fda0 mov r2, r11 */
/* @0x15fda4 ldr r1, [r9] */
/* @0x15fda8 ldr r12, [r0] */
/* @0x15fdac ldr r12, [r12, #0x2b8] */
/* @0x15fdb0 blx r12 */
/* @0x15fdb4 ldr r12, [r7] */
/* @0x15fdb8 ldr r3, [sp, #0x24] */
/* @0x15fdbc mov r0, r7 */
/* @0x15fdc0 ldr r1, [sp, #0x14] */
/* @0x15fdc4 mov r2, r6 */
/* @0x15fdc8 ldr r12, [r12, #0xc] */
/* @0x15fdcc ldr r3, [r3] */
/* @0x15fdd0 blx r12 */
/* @0x15fdd4 ldr r3, [sp, #0x30] */
/* @0x15fdd8 sub r3, r3, #1 */
/* @0x15fddc bic r3, r3, #-16777216 */
/* @0x15fde0 bic r3, r3, #3 */
/* @0x15fde4 cmp r3, #0 */
/* @0x15fde8 beq 0x15fe5c <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x3b4> */
/* @0x15fdec mov r1, #0 */
/* @0x15fdf0 str r10, [sp] */
/* @0x15fdf4 mov r2, r1 */
/* @0x15fdf8 mov r0, r8 */
/* @0x15fdfc mov r3, #2 */
/* @0x15fe00 mov r12, #5 */
/* @0x15fe04 str r4, [sp, #0x2c] */
/* @0x15fe08 str r12, [sp, #0x30] */
/* @0x15fe0c str r4, [sp, #0x24] */
/* @0x15fe10 bl 0x104080 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_> */
/* @0x15fe14 ldr r11, [sp, #0x30] */
/* @0x15fe18 cmp r11, #1 */
/* @0x15fe1c bne 0x15fe68 <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x3c0> */
/* @0x15fe20 ldr r3, [sp, #0x24] */
/* @0x15fe24 cmp r3, #0 */
/* @0x15fe28 beq 0x15fe68 <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x3c0> */
/* @0x15fe2c sub r11, r11, #1 */
/* @0x15fe30 ldr r1, [r3] */
/* @0x15fe34 bic r11, r11, #-16777216 */
/* @0x15fe38 mov r0, r6 */
/* @0x15fe3c movw r2, #0x1ff */
/* @0x15fe40 bic r11, r11, #3 */
/* @0x15fe44 bl 0xb6568 <strncpy@plt> */
/* @0x15fe48 cmp r11, #0 */
/* @0x15fe4c bne 0x15fce8 <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x240> */
/* @0x15fe50 mov r0, r8 */
/* @0x15fe54 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x15fe58 b 0x15fce8 <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x240> */
/* @0x15fe5c mov r0, r8 */
/* @0x15fe60 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x15fe64 b 0x15fdec <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x344> */
/* @0x15fe68 mov r0, #1 */
/* @0x15fe6c b 0x15fbe4 <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x13c> */
/* @0x15fe70 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x15fe74 mlaeq r9, r0, r1, r2 */
/* @0x15fe78 .word 0xffffbd00 */
/* @0x15fe7c .word 0xffffbac4 */
/* @0x15fe80 andseq r9, lr, r12, ror #26 */
/* @0x15fe84 andseq lr, r12, r10, ror #31 */
/* @0x15fe88 andseq r9, lr, r4, lsl #24 */
/* @0x15fe8c ldrsbeq r9, [lr], -r12 */
/* @0x15fe90 andseq r9, lr, r4, lsl #24 */
/* @0x15fe94 andseq r9, lr, r0, ror #21 */
/* @0x15fe98 mulseq r12, r10, lr */

/* ── FUNC 0x15fe9c · FacebookGraphRequestM(char*, char*, int, int) · size=212 · insn=53 */
/* @0x15fe9c push {r4, r5, r6, r8, r9, lr} */
/* @0x15fea0 sub sp, sp, #40 */
/* @0x15fea4 mov r6, r0 */
/* @0x15fea8 mov r5, r1 */
/* @0x15feac mov r0, r2 */
/* @0x15feb0 add r1, sp, #20 */
/* @0x15feb4 mov r4, r3 */
/* @0x15feb8 bl 0x15faa8 <_Z21BuildFacebookWallPostiRP13_jobjectArray> */
/* @0x15febc cmp r4, #0 */
/* @0x15fec0 blt 0x15fef8 <_Z21FacebookGraphRequestMPcS_ii+0x5c> */
/* @0x15fec4 vmov s13, r4 */
/* @0x15fec8 add r12, sp, #40 */
/* @0x15fecc mov r0, #0 */
/* @0x15fed0 mov r3, #1 */
/* @0x15fed4 vcvt.f64.s32 d7, s13 */
/* @0x15fed8 mov r1, r0 */
/* @0x15fedc mov r2, r0 */
/* @0x15fee0 str r0, [sp, #0x24] */
/* @0x15fee4 vmov r8, r9, d7 */
/* @0x15fee8 strd r8, r9, [r12, #-16]! */
/* @0x15feec mov r0, r12 */
/* @0x15fef0 str r12, [sp] */
/* @0x15fef4 bl 0xfed40 <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_> */
/* @0x15fef8 bl 0x290274 <getJNIEnv> */
/* @0x15fefc mov r1, r6 */
/* @0x15ff00 ldr r3, [r0] */
/* @0x15ff04 ldr r3, [r3, #0x29c] */
/* @0x15ff08 blx r3 */
/* @0x15ff0c mov r6, r0 */
/* @0x15ff10 bl 0x290274 <getJNIEnv> */
/* @0x15ff14 mov r1, r5 */
/* @0x15ff18 ldr r3, [r0] */
/* @0x15ff1c ldr r3, [r3, #0x29c] */
/* @0x15ff20 blx r3 */
/* @0x15ff24 mov r5, r0 */
/* @0x15ff28 bl 0x290274 <getJNIEnv> */
/* @0x15ff2c ldr r1, [pc, #0x34] */
/* @0x15ff30 mov r3, r6 */
/* @0x15ff34 ldr r2, [pc, #0x30] */
/* @0x15ff38 ldr r12, [sp, #0x14] */
/* @0x15ff3c ldr r1, [pc, r1] */
/* @0x15ff40 ldr r2, [pc, r2] */
/* @0x15ff44 ldr r1, [r1] */
/* @0x15ff48 ldr r2, [r2] */
/* @0x15ff4c str r5, [sp] */
/* @0x15ff50 str r4, [sp, #0x8] */
/* @0x15ff54 str r12, [sp, #0x4] */
/* @0x15ff58 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x15ff5c mov r0, #1 */
/* @0x15ff60 add sp, sp, #40 */
/* @0x15ff64 pop {r4, r5, r6, r8, r9, pc} */
/* @0x15ff68 eoreq sp, r8, r8, ror #20 */
/* @0x15ff6c eoreq pc, r8, r4, ror pc */

/* ── FUNC 0x15ff70 · FacebookDialogM(char*, int, int) · size=180 · insn=45 */
/* @0x15ff70 push {r4, r5, r6, r7, lr} */
/* @0x15ff74 sub sp, sp, #36 */
/* @0x15ff78 mov r5, r0 */
/* @0x15ff7c mov r0, r1 */
/* @0x15ff80 add r1, sp, #12 */
/* @0x15ff84 mov r4, r2 */
/* @0x15ff88 bl 0x15faa8 <_Z21BuildFacebookWallPostiRP13_jobjectArray> */
/* @0x15ff8c cmp r4, #0 */
/* @0x15ff90 blt 0x15ffc8 <_Z15FacebookDialogMPcii+0x58> */
/* @0x15ff94 vmov s13, r4 */
/* @0x15ff98 add r12, sp, #32 */
/* @0x15ff9c mov r0, #0 */
/* @0x15ffa0 mov r3, #1 */
/* @0x15ffa4 vcvt.f64.s32 d7, s13 */
/* @0x15ffa8 mov r1, r0 */
/* @0x15ffac mov r2, r0 */
/* @0x15ffb0 str r0, [sp, #0x1c] */
/* @0x15ffb4 vmov r6, r7, d7 */
/* @0x15ffb8 strd r6, r7, [r12, #-16]! */
/* @0x15ffbc mov r0, r12 */
/* @0x15ffc0 str r12, [sp] */
/* @0x15ffc4 bl 0xfed40 <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_> */
/* @0x15ffc8 bl 0x290274 <getJNIEnv> */
/* @0x15ffcc mov r1, r5 */
/* @0x15ffd0 ldr r3, [r0] */
/* @0x15ffd4 ldr r3, [r3, #0x29c] */
/* @0x15ffd8 blx r3 */
/* @0x15ffdc mov r5, r0 */
/* @0x15ffe0 bl 0x290274 <getJNIEnv> */
/* @0x15ffe4 ldr r1, [pc, #0x30] */
/* @0x15ffe8 mov r3, r5 */
/* @0x15ffec ldr r12, [pc, #0x2c] */
/* @0x15fff0 ldr lr, [sp, #0xc] */
/* @0x15fff4 ldr r1, [pc, r1] */
/* @0x15fff8 ldr r12, [pc, r12] */
/* @0x15fffc ldr r1, [r1] */
/* @0x160000 ldr r2, [r12] */
/* @0x160004 str r4, [sp, #0x4] */
/* @0x160008 str lr, [sp] */
/* @0x16000c bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x160010 mov r0, #1 */
/* @0x160014 add sp, sp, #36 */
/* @0x160018 pop {r4, r5, r6, r7, pc} */
/* @0x16001c .word 0x0028d9b0 */
/* @0x160020 eoreq pc, r8, r0, lsl pc */

/* ── FUNC 0x160024 · FindDSMap(CDS_Map*, char const*) · size=540 · insn=135 */
/* @0x160024 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x160028 sub sp, sp, #20 */
/* @0x16002c mov r5, r0 */
/* @0x160030 mov r3, #0 */
/* @0x160034 mov r0, sp */
/* @0x160038 str r3, [sp] */
/* @0x16003c str r3, [sp, #0x4] */
/* @0x160040 mov r4, sp */
/* @0x160044 str r3, [sp, #0x8] */
/* @0x160048 str r3, [sp, #0xc] */
/* @0x16004c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x160050 mov r0, r5 */
/* @0x160054 mov r1, sp */
/* @0x160058 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x16005c ldr r2, [sp, #0xc] */
/* @0x160060 sub r3, r2, #1 */
/* @0x160064 bic r3, r3, #-16777216 */
/* @0x160068 cmp r0, #0 */
/* @0x16006c addne r6, r0, #16 */
/* @0x160070 moveq r6, r0 */
/* @0x160074 bics r5, r3, #3 */
/* @0x160078 beq 0x160088 <_Z9FindDSMapP7CDS_MapPKc+0x64> */
/* @0x16007c mov r0, r6 */
/* @0x160080 add sp, sp, #20 */
/* @0x160084 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x160088 bic r2, r2, #-16777216 */
/* @0x16008c cmp r2, #2 */
/* @0x160090 beq 0x160100 <_Z9FindDSMapP7CDS_MapPKc+0xdc> */
/* @0x160094 cmp r2, #3 */
/* @0x160098 beq 0x1600d8 <_Z9FindDSMapP7CDS_MapPKc+0xb4> */
/* @0x16009c cmp r2, #1 */
/* @0x1600a0 bne 0x16007c <_Z9FindDSMapP7CDS_MapPKc+0x58> */
/* @0x1600a4 ldr r4, [sp] */
/* @0x1600a8 cmp r4, #0 */
/* @0x1600ac beq 0x16007c <_Z9FindDSMapP7CDS_MapPKc+0x58> */
/* @0x1600b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1600b4 ldr r5, [r4, #0x4] */
/* @0x1600b8 sub r5, r5, #1 */
/* @0x1600bc str r5, [r4, #0x4] */
/* @0x1600c0 cmp r5, #0 */
/* @0x1600c4 beq 0x1601a0 <_Z9FindDSMapP7CDS_MapPKc+0x17c> */
/* @0x1600c8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1600cc mov r0, r6 */
/* @0x1600d0 add sp, sp, #20 */
/* @0x1600d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1600d8 ldr r3, [sp, #0x8] */
/* @0x1600dc tst r3, #8 */
/* @0x1600e0 beq 0x16007c <_Z9FindDSMapP7CDS_MapPKc+0x58> */
/* @0x1600e4 ldr r0, [sp] */
/* @0x1600e8 cmp r0, #0 */
/* @0x1600ec beq 0x16007c <_Z9FindDSMapP7CDS_MapPKc+0x58> */
/* @0x1600f0 ldr r3, [r0] */
/* @0x1600f4 ldr r3, [r3, #0x4] */
/* @0x1600f8 blx r3 */
/* @0x1600fc b 0x16007c <_Z9FindDSMapP7CDS_MapPKc+0x58> */
/* @0x160100 ldr r8, [sp] */
/* @0x160104 cmp r8, #0 */
/* @0x160108 beq 0x16007c <_Z9FindDSMapP7CDS_MapPKc+0x58> */
/* @0x16010c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x160110 ldr r3, [r8] */
/* @0x160114 ldr r2, [r8, #0x8] */
/* @0x160118 sub r3, r3, #1 */
/* @0x16011c str r3, [r8] */
/* @0x160120 cmp r2, r4 */
/* @0x160124 streq r5, [r8, #0x8] */
/* @0x160128 cmp r3, #0 */
/* @0x16012c bgt 0x1600c8 <_Z9FindDSMapP7CDS_MapPKc+0xa4> */
/* @0x160130 ldr r3, [r8, #0x10] */
/* @0x160134 cmp r3, #0 */
/* @0x160138 movgt r7, #0 */
/* @0x16013c movgt r11, #5 */
/* @0x160140 movgt r5, r7 */
/* @0x160144 ble 0x1601f4 <_Z9FindDSMapP7CDS_MapPKc+0x1d0> */
/* @0x160148 ldr r3, [r8, #0x4] */
/* @0x16014c add r9, r3, r7, lsl #3 */
/* @0x160150 ldr r10, [r3, r7, lsl #3] */
/* @0x160154 ldr r4, [r9, #0x4] */
/* @0x160158 add r10, r4, r10, lsl #4 */
/* @0x16015c cmp r4, r10 */
/* @0x160160 blo 0x16017c <_Z9FindDSMapP7CDS_MapPKc+0x158> */
/* @0x160164 b 0x160214 <_Z9FindDSMapP7CDS_MapPKc+0x1f0> */
/* @0x160168 str r5, [r4, #0x8] */
/* @0x16016c str r11, [r4, #0xc] */
/* @0x160170 str r5, [r4], #16 */
/* @0x160174 cmp r10, r4 */
/* @0x160178 bls 0x1601d8 <_Z9FindDSMapP7CDS_MapPKc+0x1b4> */
/* @0x16017c ldr r3, [r4, #0xc] */
/* @0x160180 sub r3, r3, #1 */
/* @0x160184 bic r3, r3, #-16777216 */
/* @0x160188 bic r3, r3, #3 */
/* @0x16018c cmp r3, #0 */
/* @0x160190 bne 0x160168 <_Z9FindDSMapP7CDS_MapPKc+0x144> */
/* @0x160194 mov r0, r4 */
/* @0x160198 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x16019c b 0x160168 <_Z9FindDSMapP7CDS_MapPKc+0x144> */
/* @0x1601a0 ldr r0, [r4] */
/* @0x1601a4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1601a8 str r5, [r4] */
/* @0x1601ac str r5, [r4, #0x8] */
/* @0x1601b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1601b4 ldr r5, [r4, #0x4] */
/* @0x1601b8 sub r5, r5, #1 */
/* @0x1601bc str r5, [r4, #0x4] */
/* @0x1601c0 cmp r5, #0 */
/* @0x1601c4 beq 0x16021c <_Z9FindDSMapP7CDS_MapPKc+0x1f8> */
/* @0x1601c8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1601cc mov r0, r4 */
/* @0x1601d0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1601d4 b 0x1600c8 <_Z9FindDSMapP7CDS_MapPKc+0xa4> */
/* @0x1601d8 ldr r0, [r9, #0x4] */
/* @0x1601dc bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x1601e0 ldr r3, [r8, #0x10] */
/* @0x1601e4 add r7, r7, #1 */
/* @0x1601e8 str r5, [r9, #0x4] */
/* @0x1601ec cmp r7, r3 */
/* @0x1601f0 blt 0x160148 <_Z9FindDSMapP7CDS_MapPKc+0x124> */
/* @0x1601f4 ldr r0, [r8, #0x4] */
/* @0x1601f8 mov r4, #0 */
/* @0x1601fc bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x160200 str r4, [r8, #0x4] */
/* @0x160204 mov r0, r8 */
/* @0x160208 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x16020c str r4, [sp] */
/* @0x160210 b 0x1600c8 <_Z9FindDSMapP7CDS_MapPKc+0xa4> */
/* @0x160214 mov r0, r4 */
/* @0x160218 b 0x1601dc <_Z9FindDSMapP7CDS_MapPKc+0x1b8> */
/* @0x16021c ldr r0, [r4] */
/* @0x160220 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x160224 mov r0, r4 */
/* @0x160228 str r5, [r4] */
/* @0x16022c str r5, [r4, #0x8] */
/* @0x160230 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x160234 mov r0, r4 */
/* @0x160238 bl 0x27d1d0 <_ZdlPv> */
/* @0x16023c b 0x1601c8 <_Z9FindDSMapP7CDS_MapPKc+0x1a4> */

/* ── FUNC 0x160240 · GetOSSpecificJSON() · size=1092 · insn=273 */
/* @0x160240 push {r4, r5, r6, r7, r8, lr} */
/* @0x160244 sub sp, sp, #16 */
/* @0x160248 mov r0, #1 */
/* @0x16024c mov r4, #0 */
/* @0x160250 str r4, [sp, #0xc] */
/* @0x160254 bl 0xb6544 <malloc@plt> */
/* @0x160258 mov r3, #1 */
/* @0x16025c str r3, [sp, #0x8] */
/* @0x160260 add r5, sp, #4 */
/* @0x160264 strb r4, [r0] */
/* @0x160268 str r0, [sp, #0x4] */
/* @0x16026c bl 0x290274 <getJNIEnv> */
/* @0x160270 ldr r2, [pc, #0x374] */
/* @0x160274 ldr r3, [pc, #0x374] */
/* @0x160278 ldr r2, [pc, r2] */
/* @0x16027c ldr r3, [pc, r3] */
/* @0x160280 ldr r1, [r2] */
/* @0x160284 ldr r2, [r3] */
/* @0x160288 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x16028c mov r7, r0 */
/* @0x160290 mov r0, sp */
/* @0x160294 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x160298 mov r0, r7 */
/* @0x16029c bl 0x2052d4 <_Z8GetDsMapi> */
/* @0x1602a0 mov r6, r0 */
/* @0x1602a4 bl 0x17d284 <_Z15AddGraphicsInfoP7CDS_Map> */
/* @0x1602a8 ldr r3, [pc, #0x344] */
/* @0x1602ac mov r0, r5 */
/* @0x1602b0 ldr r1, [pc, #0x340] */
/* @0x1602b4 ldr r3, [pc, r3] */
/* @0x1602b8 add r1, pc, r1 */
/* @0x1602bc ldr r2, [r3] */
/* @0x1602c0 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1602c4 ldr r1, [pc, #0x330] */
/* @0x1602c8 mov r0, r6 */
/* @0x1602cc add r1, pc, r1 */
/* @0x1602d0 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc> */
/* @0x1602d4 mov r1, r4 */
/* @0x1602d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1602dc ldr r1, [pc, #0x31c] */
/* @0x1602e0 add r1, pc, r1 */
/* @0x1602e4 mov r2, r0 */
/* @0x1602e8 mov r0, r5 */
/* @0x1602ec bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1602f0 ldr r1, [pc, #0x30c] */
/* @0x1602f4 mov r0, r6 */
/* @0x1602f8 add r1, pc, r1 */
/* @0x1602fc bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc> */
/* @0x160300 mov r1, r4 */
/* @0x160304 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x160308 ldr r1, [pc, #0x2f8] */
/* @0x16030c add r1, pc, r1 */
/* @0x160310 mov r2, r0 */
/* @0x160314 mov r0, r5 */
/* @0x160318 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x16031c ldr r1, [pc, #0x2e8] */
/* @0x160320 mov r0, r6 */
/* @0x160324 add r1, pc, r1 */
/* @0x160328 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc> */
/* @0x16032c mov r1, r4 */
/* @0x160330 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x160334 ldr r1, [pc, #0x2d4] */
/* @0x160338 add r1, pc, r1 */
/* @0x16033c mov r2, r0 */
/* @0x160340 mov r0, r5 */
/* @0x160344 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x160348 ldr r1, [pc, #0x2c4] */
/* @0x16034c mov r0, r6 */
/* @0x160350 add r1, pc, r1 */
/* @0x160354 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc> */
/* @0x160358 mov r1, r4 */
/* @0x16035c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x160360 ldr r1, [pc, #0x2b0] */
/* @0x160364 add r1, pc, r1 */
/* @0x160368 mov r2, r0 */
/* @0x16036c mov r0, r5 */
/* @0x160370 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x160374 ldr r1, [pc, #0x2a0] */
/* @0x160378 mov r0, r6 */
/* @0x16037c add r1, pc, r1 */
/* @0x160380 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc> */
/* @0x160384 mov r1, r4 */
/* @0x160388 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x16038c ldr r1, [pc, #0x28c] */
/* @0x160390 add r1, pc, r1 */
/* @0x160394 mov r2, r0 */
/* @0x160398 mov r0, r5 */
/* @0x16039c bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1603a0 ldr r1, [pc, #0x27c] */
/* @0x1603a4 mov r0, r6 */
/* @0x1603a8 add r1, pc, r1 */
/* @0x1603ac bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc> */
/* @0x1603b0 mov r1, r4 */
/* @0x1603b4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1603b8 ldr r1, [pc, #0x268] */
/* @0x1603bc add r1, pc, r1 */
/* @0x1603c0 mov r2, r0 */
/* @0x1603c4 mov r0, r5 */
/* @0x1603c8 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1603cc ldr r1, [pc, #0x258] */
/* @0x1603d0 mov r0, r6 */
/* @0x1603d4 add r1, pc, r1 */
/* @0x1603d8 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc> */
/* @0x1603dc mov r1, r4 */
/* @0x1603e0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1603e4 ldr r1, [pc, #0x244] */
/* @0x1603e8 add r1, pc, r1 */
/* @0x1603ec mov r2, r0 */
/* @0x1603f0 mov r0, r5 */
/* @0x1603f4 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1603f8 ldr r1, [pc, #0x234] */
/* @0x1603fc mov r0, r6 */
/* @0x160400 add r1, pc, r1 */
/* @0x160404 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc> */
/* @0x160408 mov r1, r4 */
/* @0x16040c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x160410 ldr r1, [pc, #0x220] */
/* @0x160414 add r1, pc, r1 */
/* @0x160418 mov r2, r0 */
/* @0x16041c mov r0, r5 */
/* @0x160420 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x160424 ldr r1, [pc, #0x210] */
/* @0x160428 mov r0, r6 */
/* @0x16042c add r1, pc, r1 */
/* @0x160430 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc> */
/* @0x160434 mov r1, r4 */
/* @0x160438 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x16043c ldr r1, [pc, #0x1fc] */
/* @0x160440 add r1, pc, r1 */
/* @0x160444 mov r2, r0 */
/* @0x160448 mov r0, r5 */
/* @0x16044c bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x160450 ldr r1, [pc, #0x1ec] */
/* @0x160454 mov r0, r6 */
/* @0x160458 add r1, pc, r1 */
/* @0x16045c bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc> */
/* @0x160460 mov r1, r4 */
/* @0x160464 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x160468 ldr r1, [pc, #0x1d8] */
/* @0x16046c add r1, pc, r1 */
/* @0x160470 mov r2, r0 */
/* @0x160474 mov r0, r5 */
/* @0x160478 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x16047c ldr r1, [pc, #0x1c8] */
/* @0x160480 mov r0, r6 */
/* @0x160484 add r1, pc, r1 */
/* @0x160488 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc> */
/* @0x16048c mov r1, r4 */
/* @0x160490 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x160494 ldr r1, [pc, #0x1b4] */
/* @0x160498 add r1, pc, r1 */
/* @0x16049c mov r2, r0 */
/* @0x1604a0 mov r0, r5 */
/* @0x1604a4 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1604a8 ldr r1, [pc, #0x1a4] */
/* @0x1604ac mov r0, r6 */
/* @0x1604b0 add r1, pc, r1 */
/* @0x1604b4 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc> */
/* @0x1604b8 mov r1, r4 */
/* @0x1604bc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1604c0 ldr r1, [pc, #0x190] */
/* @0x1604c4 add r1, pc, r1 */
/* @0x1604c8 mov r2, r0 */
/* @0x1604cc mov r0, r5 */
/* @0x1604d0 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1604d4 ldr r1, [pc, #0x180] */
/* @0x1604d8 mov r0, r6 */
/* @0x1604dc add r1, pc, r1 */
/* @0x1604e0 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc> */
/* @0x1604e4 mov r1, r4 */
/* @0x1604e8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1604ec ldr r1, [pc, #0x16c] */
/* @0x1604f0 add r1, pc, r1 */
/* @0x1604f4 mov r2, r0 */
/* @0x1604f8 mov r0, r5 */
/* @0x1604fc bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x160500 ldr r1, [pc, #0x15c] */
/* @0x160504 mov r0, r6 */
/* @0x160508 add r1, pc, r1 */
/* @0x16050c bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc> */
/* @0x160510 mov r1, r4 */
/* @0x160514 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x160518 ldr r1, [pc, #0x148] */
/* @0x16051c add r1, pc, r1 */
/* @0x160520 mov r2, r0 */
/* @0x160524 mov r0, r5 */
/* @0x160528 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x16052c ldr r1, [pc, #0x138] */
/* @0x160530 mov r0, r6 */
/* @0x160534 add r1, pc, r1 */
/* @0x160538 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc> */
/* @0x16053c mov r1, r4 */
/* @0x160540 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x160544 ldr r1, [pc, #0x124] */
/* @0x160548 add r1, pc, r1 */
/* @0x16054c mov r2, r0 */
/* @0x160550 mov r0, r5 */
/* @0x160554 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x160558 ldr r1, [pc, #0x114] */
/* @0x16055c mov r0, r6 */
/* @0x160560 add r1, pc, r1 */
/* @0x160564 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc> */
/* @0x160568 mov r1, r4 */
/* @0x16056c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x160570 ldr r1, [pc, #0x100] */
/* @0x160574 add r1, pc, r1 */
/* @0x160578 mov r2, r0 */
/* @0x16057c mov r0, r5 */
/* @0x160580 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x160584 ldr r1, [pc, #0xf0] */
/* @0x160588 mov r0, r6 */
/* @0x16058c add r1, pc, r1 */
/* @0x160590 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc> */
/* @0x160594 mov r1, r4 */
/* @0x160598 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16059c ldr r1, [pc, #0xdc] */
/* @0x1605a0 add r1, pc, r1 */
/* @0x1605a4 mov r2, r0 */
/* @0x1605a8 mov r0, r5 */
/* @0x1605ac bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1605b0 mov r0, r7 */
/* @0x1605b4 bl 0x205334 <_Z12DestroyDsMapi> */
/* @0x1605b8 ldr r0, [sp, #0x4] */
/* @0x1605bc str r4, [sp, #0xc] */
/* @0x1605c0 bl 0xb6640 <strdup@plt> */
/* @0x1605c4 mov r4, r0 */
/* @0x1605c8 mov r0, sp */
/* @0x1605cc bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x1605d0 ldr r0, [sp, #0x4] */
/* @0x1605d4 cmp r0, #0 */
/* @0x1605d8 beq 0x1605e0 <_Z17GetOSSpecificJSONv+0x3a0> */
/* @0x1605dc bl 0xb655c <free@plt> */
/* @0x1605e0 mov r0, r4 */
/* @0x1605e4 add sp, sp, #16 */
/* @0x1605e8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1605ec eoreq sp, r8, r12, lsr #14 */
/* @0x1605f0 mlaeq r8, r0, r12, pc */
/* @0x1605f4 eoreq pc, r8, r12, asr r12 */
/* @0x1605f8 andseq r9, lr, r8, lsl r6 */
/* @0x1605fc andseq r9, lr, r0, lsl r6 */
/* @0x160600 andseq r9, lr, r4, lsl #12 */
/* @0x160604 ldrsheq r9, [lr], -r12 */
/* @0x160608 ldrsheq r9, [lr], -r0 */
/* @0x16060c andseq r9, lr, r8, ror #11 */
/* @0x160610 ldrsbeq r9, [lr], -r12 */
/* @0x160614 ldrsbeq r9, [lr], -r4 */
/* @0x160618 andseq r9, lr, r8, asr #11 */
/* @0x16061c andseq r9, lr, r0, asr #11 */
/* @0x160620 ldrheq r9, [lr], -r12 */
/* @0x160624 ldrheq r9, [lr], -r4 */
/* @0x160628 andseq r9, lr, r8, lsr #11 */
/* @0x16062c andseq r9, lr, r0, lsr #11 */
/* @0x160630 mulseq lr, r8, r5 */
/* @0x160634 mulseq lr, r0, r5 */
/* @0x160638 andseq r9, lr, r8, lsl #11 */
/* @0x16063c andseq r9, lr, r0, lsl #11 */
/* @0x160640 andseq r9, lr, r4, ror r5 */
/* @0x160644 andseq r9, lr, r12, ror #10 */
/* @0x160648 andseq r9, lr, r0, ror #10 */
/* @0x16064c andseq r9, lr, r8, asr r5 */
/* @0x160650 andseq r9, lr, r4, asr r5 */
/* @0x160654 andseq r9, lr, r8, asr #10 */
/* @0x160658 andseq r9, lr, r12, lsr r5 */
/* @0x16065c andseq r9, lr, r4, lsr r5 */
/* @0x160660 andseq r9, lr, r12, lsr #10 */
/* @0x160664 andseq r9, lr, r4, lsr #10 */
/* @0x160668 andseq r9, lr, r12, lsl r5 */
/* @0x16066c andseq r9, lr, r0, lsl r5 */
/* @0x160670 andseq r9, lr, r8, lsl #10 */
/* @0x160674 ldrsheq r9, [lr], -r12 */
/* @0x160678 andseq r9, lr, r4, lsl #10 */
/* @0x16067c ldrsheq r9, [lr], -r12 */
/* @0x160680 ldrsheq r9, [lr], -r12 */

/* ── FUNC 0x160684 · CheckAttrib(double) · size=8 · insn=2 */
/* @0x160684 mov r0, #1 */
/* @0x160688 bx lr */

/* ── FUNC 0x16068c · CompareFileNames(char const*, char const*) · size=396 · insn=99 */
/* @0x16068c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x160690 mov r9, r1 */
/* @0x160694 mov r10, r0 */
/* @0x160698 bl 0xb6538 <strlen@plt> */
/* @0x16069c mvn r6, #0 */
/* @0x1606a0 mov r7, r0 */
/* @0x1606a4 mov r0, r9 */
/* @0x1606a8 bl 0xb6538 <strlen@plt> */
/* @0x1606ac mov r12, #0 */
/* @0x1606b0 mov r4, r12 */
/* @0x1606b4 mov r8, r0 */
/* @0x1606b8 subs r0, r12, r8 */
/* @0x1606bc rsbs r3, r0, #0 */
/* @0x1606c0 adcs r3, r3, r0 */
/* @0x1606c4 subs r1, r4, r7 */
/* @0x1606c8 rsbs r2, r1, #0 */
/* @0x1606cc adcs r2, r2, r1 */
/* @0x1606d0 ands r0, r2, r3 */
/* @0x1606d4 popne {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1606d8 cmp r7, r4 */
/* @0x1606dc moveq r5, #0 */
/* @0x1606e0 andne r5, r3, #1 */
/* @0x1606e4 cmp r5, #0 */
/* @0x1606e8 beq 0x160704 <_Z16CompareFileNamesPKcS0_+0x78> */
/* @0x1606ec cmn r6, #1 */
/* @0x1606f0 beq 0x1607b0 <_Z16CompareFileNamesPKcS0_+0x124> */
/* @0x1606f4 subs r1, r6, r8 */
/* @0x1606f8 mov r12, r6 */
/* @0x1606fc rsbs r3, r1, #0 */
/* @0x160700 adcs r3, r3, r1 */
/* @0x160704 orrs r3, r3, r2 */
/* @0x160708 bne 0x1607b0 <_Z16CompareFileNamesPKcS0_+0x124> */
/* @0x16070c ldrb r5, [r9, r12] */
/* @0x160710 cmp r5, #42 */
/* @0x160714 beq 0x160754 <_Z16CompareFileNamesPKcS0_+0xc8> */
/* @0x160718 cmp r5, #63 */
/* @0x16071c bne 0x160738 <_Z16CompareFileNamesPKcS0_+0xac> */
/* @0x160720 ldrb r2, [r10, r4] */
/* @0x160724 cmp r2, #46 */
/* @0x160728 beq 0x16079c <_Z16CompareFileNamesPKcS0_+0x110> */
/* @0x16072c add r12, r12, #1 */
/* @0x160730 add r4, r4, #1 */
/* @0x160734 b 0x1606b8 <_Z16CompareFileNamesPKcS0_+0x2c> */
/* @0x160738 ldrb r2, [r10, r4] */
/* @0x16073c cmp r2, r5 */
/* @0x160740 beq 0x16072c <_Z16CompareFileNamesPKcS0_+0xa0> */
/* @0x160744 cmn r6, #1 */
/* @0x160748 beq 0x160808 <_Z16CompareFileNamesPKcS0_+0x17c> */
/* @0x16074c mov r12, r6 */
/* @0x160750 b 0x1606b8 <_Z16CompareFileNamesPKcS0_+0x2c> */
/* @0x160754 add r1, r12, #1 */
/* @0x160758 cmp r1, r8 */
/* @0x16075c beq 0x160810 <_Z16CompareFileNamesPKcS0_+0x184> */
/* @0x160760 add r3, r9, r12 */
/* @0x160764 ldrb r2, [r10, r4] */
/* @0x160768 ldrb r3, [r3, #0x1] */
/* @0x16076c cmp r3, r2 */
/* @0x160770 beq 0x160790 <_Z16CompareFileNamesPKcS0_+0x104> */
/* @0x160774 cmp r3, #63 */
/* @0x160778 beq 0x160788 <_Z16CompareFileNamesPKcS0_+0xfc> */
/* @0x16077c add r4, r4, #1 */
/* @0x160780 mov r6, r12 */
/* @0x160784 b 0x1606b8 <_Z16CompareFileNamesPKcS0_+0x2c> */
/* @0x160788 cmp r2, #46 */
/* @0x16078c beq 0x16077c <_Z16CompareFileNamesPKcS0_+0xf0> */
/* @0x160790 mov r6, r12 */
/* @0x160794 mov r12, r1 */
/* @0x160798 b 0x1606b8 <_Z16CompareFileNamesPKcS0_+0x2c> */
/* @0x16079c cmn r6, #1 */
/* @0x1607a0 beq 0x160808 <_Z16CompareFileNamesPKcS0_+0x17c> */
/* @0x1607a4 add r4, r4, #1 */
/* @0x1607a8 mov r12, r6 */
/* @0x1607ac b 0x1606b8 <_Z16CompareFileNamesPKcS0_+0x2c> */
/* @0x1607b0 cmp r4, r7 */
/* @0x1607b4 popne {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1607b8 cmp r12, r8 */
/* @0x1607bc beq 0x160810 <_Z16CompareFileNamesPKcS0_+0x184> */
/* @0x1607c0 ldrb r0, [r9, r12] */
/* @0x1607c4 add r9, r9, r12 */
/* @0x1607c8 cmp r0, #42 */
/* @0x1607cc cmpne r0, #63 */
/* @0x1607d0 movne r0, #0 */
/* @0x1607d4 moveq r0, #1 */
/* @0x1607d8 beq 0x1607f8 <_Z16CompareFileNamesPKcS0_+0x16c> */
/* @0x1607dc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1607e0 ldrb r3, [r9, #0x1]! */
/* @0x1607e4 cmp r3, #42 */
/* @0x1607e8 cmpne r3, #63 */
/* @0x1607ec movne r3, #0 */
/* @0x1607f0 moveq r3, #1 */
/* @0x1607f4 bne 0x160808 <_Z16CompareFileNamesPKcS0_+0x17c> */
/* @0x1607f8 add r12, r12, #1 */
/* @0x1607fc cmp r8, r12 */
/* @0x160800 bne 0x1607e0 <_Z16CompareFileNamesPKcS0_+0x154> */
/* @0x160804 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x160808 mov r0, r3 */
/* @0x16080c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x160810 mov r0, #1 */
/* @0x160814 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x160818 · CreateFindData(yyFindData*, char const*, char const*, double) · size=704 · insn=176 */
/* @0x160818 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x16081c sub sp, sp, #2080 */
/* @0x160820 ldr r6, [pc, #0x298] */
/* @0x160824 sub sp, sp, #4 */
/* @0x160828 ldr r3, [pc, #0x294] */
/* @0x16082c mov r4, r1 */
/* @0x160830 add r6, pc, r6 */
/* @0x160834 str r0, [sp, #0x4] */
/* @0x160838 mov r1, #47 */
/* @0x16083c mov r0, r4 */
/* @0x160840 ldr r3, [r6, r3] */
/* @0x160844 mov r10, r2 */
/* @0x160848 add r9, sp, #32 */
/* @0x16084c str r3, [sp, #0x8] */
/* @0x160850 ldr r3, [r3] */
/* @0x160854 str r3, [sp, #0x81c] */
/* @0x160858 bl 0xb6868 <strrchr@plt> */
/* @0x16085c mov r3, #0 */
/* @0x160860 sub r1, r9, #12 */
/* @0x160864 mov r2, r3 */
/* @0x160868 mov r7, r0 */
/* @0x16086c mov r0, r4 */
/* @0x160870 strb r3, [r7] */
/* @0x160874 bl 0xb68ec <scandir@plt> */
/* @0x160878 cmp r0, #0 */
/* @0x16087c blt 0x160920 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x108> */
/* @0x160880 sub r4, r0, #1 */
/* @0x160884 beq 0x160918 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x100> */
/* @0x160888 ldr r11, [sp, #0x4] */
/* @0x16088c lsl r4, r4, #2 */
/* @0x160890 add r7, r7, #1 */
/* @0x160894 sub r8, r9, #4 */
/* @0x160898 mov r5, r0 */
/* @0x16089c ldr r3, [sp, #0x14] */
/* @0x1608a0 mov r1, r7 */
/* @0x1608a4 ldr r0, [r3, r4] */
/* @0x1608a8 add r0, r0, #19 */
/* @0x1608ac bl 0x16068c <_Z16CompareFileNamesPKcS0_> */
/* @0x1608b0 cmp r0, #0 */
/* @0x1608b4 beq 0x160900 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0xe8> */
/* @0x1608b8 ldr r3, [sp, #0x14] */
/* @0x1608bc mov r2, r8 */
/* @0x1608c0 ldr r1, [r3, r4] */
/* @0x1608c4 add r1, r1, #19 */
/* @0x1608c8 ldrb r3, [r1], #1 */
/* @0x1608cc cmp r3, #0 */
/* @0x1608d0 beq 0x1608f0 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0xd8> */
/* @0x1608d4 tst r3, #128 */
/* @0x1608d8 bne 0x160a44 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x22c> */
/* @0x1608dc strb r3, [r2] */
/* @0x1608e0 add r2, r2, #1 */
/* @0x1608e4 ldrb r3, [r1], #1 */
/* @0x1608e8 cmp r3, #0 */
/* @0x1608ec bne 0x1608d4 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0xbc> */
/* @0x1608f0 strb r3, [r2] */
/* @0x1608f4 mov r0, r11 */
/* @0x1608f8 mov r1, r8 */
/* @0x1608fc bl 0x13ac60 <_ZN10yyFindData7AddFileEPKc> */
/* @0x160900 ldr r3, [sp, #0x14] */
/* @0x160904 ldr r0, [r3, r4] */
/* @0x160908 sub r4, r4, #4 */
/* @0x16090c bl 0xb655c <free@plt> */
/* @0x160910 subs r5, r5, #1 */
/* @0x160914 bne 0x16089c <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x84> */
/* @0x160918 ldr r0, [sp, #0x14] */
/* @0x16091c bl 0xb655c <free@plt> */
/* @0x160920 ldr r3, [pc, #0x1a0] */
/* @0x160924 ldr r7, [r6, r3] */
/* @0x160928 ldr r0, [r7] */
/* @0x16092c blx 0x2a490e <zip_get_num_files> */
/* @0x160930 subs r8, r0, #0 */
/* @0x160934 ble 0x160a24 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x20c> */
/* @0x160938 ldr r1, [pc, #0x18c] */
/* @0x16093c sub r9, r9, #4 */
/* @0x160940 add r4, sp, #24 */
/* @0x160944 mov r5, #0 */
/* @0x160948 add r1, pc, r1 */
/* @0x16094c str r1, [sp, #0xc] */
/* @0x160950 ldr r0, [r7] */
/* @0x160954 mov r1, r5 */
/* @0x160958 mov r2, #0 */
/* @0x16095c blx 0x2a4970 <zip_get_name> */
/* @0x160960 subs r11, r0, #0 */
/* @0x160964 beq 0x160a78 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x260> */
/* @0x160968 mov r1, r10 */
/* @0x16096c bl 0x16068c <_Z16CompareFileNamesPKcS0_> */
/* @0x160970 cmp r0, #0 */
/* @0x160974 beq 0x160a18 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x200> */
/* @0x160978 mov r0, r11 */
/* @0x16097c bl 0xb6538 <strlen@plt> */
/* @0x160980 cmp r0, #0 */
/* @0x160984 blt 0x1609b0 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x198> */
/* @0x160988 ldrb r1, [r11, r0] */
/* @0x16098c add r2, r11, r0 */
/* @0x160990 cmp r1, #47 */
/* @0x160994 bne 0x1609a8 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x190> */
/* @0x160998 b 0x160a70 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x258> */
/* @0x16099c ldrb r3, [r2, #-0x1]! */
/* @0x1609a0 cmp r3, #47 */
/* @0x1609a4 beq 0x160a70 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x258> */
/* @0x1609a8 subs r0, r0, #1 */
/* @0x1609ac bhs 0x16099c <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x184> */
/* @0x1609b0 str r9, [sp, #0x18] */
/* @0x1609b4 add r2, r11, r0 */
/* @0x1609b8 ldrb r1, [r11, r0] */
/* @0x1609bc cmp r1, #0 */
/* @0x1609c0 beq 0x160ab4 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x29c> */
/* @0x1609c4 mov r11, r2 */
/* @0x1609c8 cmp r1, #127 */
/* @0x1609cc ble 0x1609e8 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x1d0> */
/* @0x1609d0 ldr r3, [pc, #0xf8] */
/* @0x1609d4 add r1, r1, #1073741824 */
/* @0x1609d8 sub r1, r1, #128 */
/* @0x1609dc ldr r3, [r6, r3] */
/* @0x1609e0 ldr r3, [r3] */
/* @0x1609e4 ldr r1, [r3, r1, lsl #2] */
/* @0x1609e8 uxth r1, r1 */
/* @0x1609ec mov r0, r4 */
/* @0x1609f0 bl 0x10fe28 <utf8_add_char> */
/* @0x1609f4 ldrb r1, [r11, #0x1]! */
/* @0x1609f8 cmp r1, #0 */
/* @0x1609fc bne 0x1609c8 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x1b0> */
/* @0x160a00 ldr r3, [sp, #0x18] */
/* @0x160a04 mov r2, #0 */
/* @0x160a08 ldr r0, [sp, #0x4] */
/* @0x160a0c strb r2, [r3] */
/* @0x160a10 mov r1, r9 */
/* @0x160a14 bl 0x13ac60 <_ZN10yyFindData7AddFileEPKc> */
/* @0x160a18 add r5, r5, #1 */
/* @0x160a1c cmp r5, r8 */
/* @0x160a20 bne 0x160950 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x138> */
/* @0x160a24 ldr r1, [sp, #0x8] */
/* @0x160a28 ldr r2, [sp, #0x81c] */
/* @0x160a2c ldr r3, [r1] */
/* @0x160a30 cmp r2, r3 */
/* @0x160a34 bne 0x160abc <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x2a4> */
/* @0x160a38 add sp, sp, #2080 */
/* @0x160a3c add sp, sp, #4 */
/* @0x160a40 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x160a44 cmp r3, #191 */
/* @0x160a48 mov r0, r2 */
/* @0x160a4c movls r3, #194 */
/* @0x160a50 movhi r3, #195 */
/* @0x160a54 strb r3, [r0], #2 */
/* @0x160a58 ldrb r3, [r1, #-0x1] */
/* @0x160a5c and r3, r3, #63 */
/* @0x160a60 sub r3, r3, #128 */
/* @0x160a64 strb r3, [r2, #0x1] */
/* @0x160a68 mov r2, r0 */
/* @0x160a6c b 0x1608c8 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0xb0> */
/* @0x160a70 add r0, r0, #1 */
/* @0x160a74 b 0x1609b0 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x198> */
/* @0x160a78 ldr r3, [pc, #0x54] */
/* @0x160a7c ldr r0, [r7] */
/* @0x160a80 ldr r3, [r6, r3] */
/* @0x160a84 ldr r2, [r3] */
/* @0x160a88 ldr r3, [r2] */
/* @0x160a8c ldr r11, [r3, #0xc] */
/* @0x160a90 str r2, [sp] */
/* @0x160a94 blx 0x2a5764 <zip_strerror> */
/* @0x160a98 ldr r2, [sp] */
/* @0x160a9c ldr r1, [sp, #0xc] */
/* @0x160aa0 mov r3, r0 */
/* @0x160aa4 mov r0, r2 */
/* @0x160aa8 mov r2, r5 */
/* @0x160aac blx r11 */
/* @0x160ab0 b 0x160a18 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x200> */
/* @0x160ab4 mov r3, r9 */
/* @0x160ab8 b 0x160a04 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x1ec> */
/* @0x160abc bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x160ac0 eoreq r1, r9, r0, lsr #8 */
/* @0x160ac4 .word 0xffffbd00 */
/* @0x160ac8 .word 0xffffe2c4 */
/* @0x160acc andseq r9, lr, r4, ror #2 */
/* @0x160ad0 .word 0xffffe2c8 */
/* @0x160ad4 .word 0xffffbac4 */

/* ── FUNC 0x160ad8 · YYGetFileAttributes(char const*, bool) · size=8 · insn=2 */
/* @0x160ad8 mov r0, #0 */
/* @0x160adc bx lr */

/* ── FUNC 0x160ae0 · F_KeyboardGetNumlock(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160ae0 bx lr */

/* ── FUNC 0x160ae4 · F_KeyboardSetNumlock(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160ae4 bx lr */

/* ── FUNC 0x160ae8 · F_KeyboardKeyPress(RValue&, CInstance*, CInstance*, int, RValue*) · size=32 · insn=8 */
/* @0x160ae8 push {r3, lr} */
/* @0x160aec mov r1, #0 */
/* @0x160af0 ldr r0, [sp, #0x8] */
/* @0x160af4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x160af8 pop {r3, lr} */
/* @0x160afc mov r1, r0 */
/* @0x160b00 mov r0, #0 */
/* @0x160b04 b 0x18ef50 <_Z23RegisterAndroidKeyEventii> */

/* ── FUNC 0x160b08 · F_KeyboardKeyRelease(RValue&, CInstance*, CInstance*, int, RValue*) · size=32 · insn=8 */
/* @0x160b08 push {r3, lr} */
/* @0x160b0c mov r1, #0 */
/* @0x160b10 ldr r0, [sp, #0x8] */
/* @0x160b14 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x160b18 pop {r3, lr} */
/* @0x160b1c mov r1, r0 */
/* @0x160b20 mov r0, #1 */
/* @0x160b24 b 0x18ef50 <_Z23RegisterAndroidKeyEventii> */

/* ── FUNC 0x160b28 · F_CheckKeyDirect(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160b28 bx lr */

/* ── FUNC 0x160b2c · F_CheckMouseButton_Common(RValue&, CInstance*, CInstance*, int, int) · size=224 · insn=56 */
/* @0x160b2c cmn r3, #1 */
/* @0x160b30 mov r2, #0 */
/* @0x160b34 push {r4, r5, r6, r7, r8, lr} */
/* @0x160b38 mov r4, r0 */
/* @0x160b3c ldr r6, [sp, #0x18] */
/* @0x160b40 str r2, [r0, #0xc] */
/* @0x160b44 str r2, [r0] */
/* @0x160b48 str r2, [r0, #0x4] */
/* @0x160b4c beq 0x160bd4 <_Z25F_CheckMouseButton_CommonR6RValueP9CInstanceS2_ii+0xa8> */
/* @0x160b50 cmp r3, #0 */
/* @0x160b54 bne 0x160b94 <_Z25F_CheckMouseButton_CommonR6RValueP9CInstanceS2_ii+0x68> */
/* @0x160b58 mov r5, #1 */
/* @0x160b5c mov r7, r3 */
/* @0x160b60 str r3, [r0] */
/* @0x160b64 movt r3, #0x3ff0 */
/* @0x160b68 str r3, [r0, #0x4] */
/* @0x160b6c mov r0, r5 */
/* @0x160b70 mov r1, r6 */
/* @0x160b74 bl 0x18c0b4 <_Z14IO_Button_Downii> */
/* @0x160b78 add r5, r5, #1 */
/* @0x160b7c cmp r0, #0 */
/* @0x160b80 strne r7, [r4] */
/* @0x160b84 strne r7, [r4, #0x4] */
/* @0x160b88 cmp r5, #4 */
/* @0x160b8c bne 0x160b6c <_Z25F_CheckMouseButton_CommonR6RValueP9CInstanceS2_ii+0x40> */
/* @0x160b90 pop {r4, r5, r6, r7, r8, pc} */
/* @0x160b94 cmp r3, #2 */
/* @0x160b98 beq 0x160bac <_Z25F_CheckMouseButton_CommonR6RValueP9CInstanceS2_ii+0x80> */
/* @0x160b9c cmp r3, #3 */
/* @0x160ba0 beq 0x160bac <_Z25F_CheckMouseButton_CommonR6RValueP9CInstanceS2_ii+0x80> */
/* @0x160ba4 cmp r3, #1 */
/* @0x160ba8 popne {r4, r5, r6, r7, r8, pc} */
/* @0x160bac mov r0, r3 */
/* @0x160bb0 mov r1, r6 */
/* @0x160bb4 bl 0x18c0b4 <_Z14IO_Button_Downii> */
/* @0x160bb8 vmov s15, r0 */
/* @0x160bbc vcvt.f64.u32 d7, s15 */
/* @0x160bc0 vmov r0, r1, d7 */
/* @0x160bc4 vmov r2, s14 */
/* @0x160bc8 mov r3, r1 */
/* @0x160bcc stm r4, {r2, r3} */
/* @0x160bd0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x160bd4 mov r7, r2 */
/* @0x160bd8 movt r7, #0x3ff0 */
/* @0x160bdc mov r8, r2 */
/* @0x160be0 mov r5, #1 */
/* @0x160be4 mov r0, r5 */
/* @0x160be8 mov r1, r6 */
/* @0x160bec bl 0x18c0b4 <_Z14IO_Button_Downii> */
/* @0x160bf0 add r5, r5, #1 */
/* @0x160bf4 cmp r0, #0 */
/* @0x160bf8 strne r8, [r4] */
/* @0x160bfc strne r7, [r4, #0x4] */
/* @0x160c00 cmp r5, #4 */
/* @0x160c04 bne 0x160be4 <_Z25F_CheckMouseButton_CommonR6RValueP9CInstanceS2_ii+0xb8> */
/* @0x160c08 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x160c0c · F_CheckMouseButtonPressed_Common(RValue&, CInstance*, CInstance*, int, int) · size=224 · insn=56 */
/* @0x160c0c cmn r3, #1 */
/* @0x160c10 mov r2, #0 */
/* @0x160c14 push {r4, r5, r6, r7, r8, lr} */
/* @0x160c18 mov r4, r0 */
/* @0x160c1c ldr r6, [sp, #0x18] */
/* @0x160c20 str r2, [r0, #0xc] */
/* @0x160c24 str r2, [r0] */
/* @0x160c28 str r2, [r0, #0x4] */
/* @0x160c2c beq 0x160cb4 <_Z32F_CheckMouseButtonPressed_CommonR6RValueP9CInstanceS2_ii+0xa8> */
/* @0x160c30 cmp r3, #0 */
/* @0x160c34 bne 0x160c74 <_Z32F_CheckMouseButtonPressed_CommonR6RValueP9CInstanceS2_ii+0x68> */
/* @0x160c38 mov r5, #1 */
/* @0x160c3c mov r7, r3 */
/* @0x160c40 str r3, [r0] */
/* @0x160c44 movt r3, #0x3ff0 */
/* @0x160c48 str r3, [r0, #0x4] */
/* @0x160c4c mov r0, r5 */
/* @0x160c50 mov r1, r6 */
/* @0x160c54 bl 0x18c0f0 <_Z17IO_Button_Pressedii> */
/* @0x160c58 add r5, r5, #1 */
/* @0x160c5c cmp r0, #0 */
/* @0x160c60 strne r7, [r4] */
/* @0x160c64 strne r7, [r4, #0x4] */
/* @0x160c68 cmp r5, #4 */
/* @0x160c6c bne 0x160c4c <_Z32F_CheckMouseButtonPressed_CommonR6RValueP9CInstanceS2_ii+0x40> */
/* @0x160c70 pop {r4, r5, r6, r7, r8, pc} */
/* @0x160c74 cmp r3, #2 */
/* @0x160c78 beq 0x160c8c <_Z32F_CheckMouseButtonPressed_CommonR6RValueP9CInstanceS2_ii+0x80> */
/* @0x160c7c cmp r3, #3 */
/* @0x160c80 beq 0x160c8c <_Z32F_CheckMouseButtonPressed_CommonR6RValueP9CInstanceS2_ii+0x80> */
/* @0x160c84 cmp r3, #1 */
/* @0x160c88 popne {r4, r5, r6, r7, r8, pc} */
/* @0x160c8c mov r0, r3 */
/* @0x160c90 mov r1, r6 */
/* @0x160c94 bl 0x18c0f0 <_Z17IO_Button_Pressedii> */
/* @0x160c98 vmov s15, r0 */
/* @0x160c9c vcvt.f64.u32 d7, s15 */
/* @0x160ca0 vmov r0, r1, d7 */
/* @0x160ca4 vmov r2, s14 */
/* @0x160ca8 mov r3, r1 */
/* @0x160cac stm r4, {r2, r3} */
/* @0x160cb0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x160cb4 mov r7, r2 */
/* @0x160cb8 movt r7, #0x3ff0 */
/* @0x160cbc mov r8, r2 */
/* @0x160cc0 mov r5, #1 */
/* @0x160cc4 mov r0, r5 */
/* @0x160cc8 mov r1, r6 */
/* @0x160ccc bl 0x18c0f0 <_Z17IO_Button_Pressedii> */
/* @0x160cd0 add r5, r5, #1 */
/* @0x160cd4 cmp r0, #0 */
/* @0x160cd8 strne r8, [r4] */
/* @0x160cdc strne r7, [r4, #0x4] */
/* @0x160ce0 cmp r5, #4 */
/* @0x160ce4 bne 0x160cc4 <_Z32F_CheckMouseButtonPressed_CommonR6RValueP9CInstanceS2_ii+0xb8> */
/* @0x160ce8 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x160cec · F_CheckMouseButtonReleased_Common(RValue&, CInstance*, CInstance*, int, int) · size=224 · insn=56 */
/* @0x160cec cmn r3, #1 */
/* @0x160cf0 mov r2, #0 */
/* @0x160cf4 push {r4, r5, r6, r7, r8, lr} */
/* @0x160cf8 mov r4, r0 */
/* @0x160cfc ldr r6, [sp, #0x18] */
/* @0x160d00 str r2, [r0, #0xc] */
/* @0x160d04 str r2, [r0] */
/* @0x160d08 str r2, [r0, #0x4] */
/* @0x160d0c beq 0x160d94 <_Z33F_CheckMouseButtonReleased_CommonR6RValueP9CInstanceS2_ii+0xa8> */
/* @0x160d10 cmp r3, #0 */
/* @0x160d14 bne 0x160d54 <_Z33F_CheckMouseButtonReleased_CommonR6RValueP9CInstanceS2_ii+0x68> */
/* @0x160d18 mov r5, #1 */
/* @0x160d1c mov r7, r3 */
/* @0x160d20 str r3, [r0] */
/* @0x160d24 movt r3, #0x3ff0 */
/* @0x160d28 str r3, [r0, #0x4] */
/* @0x160d2c mov r0, r5 */
/* @0x160d30 mov r1, r6 */
/* @0x160d34 bl 0x18c12c <_Z18IO_Button_Releasedii> */
/* @0x160d38 add r5, r5, #1 */
/* @0x160d3c cmp r0, #0 */
/* @0x160d40 strne r7, [r4] */
/* @0x160d44 strne r7, [r4, #0x4] */
/* @0x160d48 cmp r5, #4 */
/* @0x160d4c bne 0x160d2c <_Z33F_CheckMouseButtonReleased_CommonR6RValueP9CInstanceS2_ii+0x40> */
/* @0x160d50 pop {r4, r5, r6, r7, r8, pc} */
/* @0x160d54 cmp r3, #2 */
/* @0x160d58 beq 0x160d6c <_Z33F_CheckMouseButtonReleased_CommonR6RValueP9CInstanceS2_ii+0x80> */
/* @0x160d5c cmp r3, #3 */
/* @0x160d60 beq 0x160d6c <_Z33F_CheckMouseButtonReleased_CommonR6RValueP9CInstanceS2_ii+0x80> */
/* @0x160d64 cmp r3, #1 */
/* @0x160d68 popne {r4, r5, r6, r7, r8, pc} */
/* @0x160d6c mov r0, r3 */
/* @0x160d70 mov r1, r6 */
/* @0x160d74 bl 0x18c12c <_Z18IO_Button_Releasedii> */
/* @0x160d78 vmov s15, r0 */
/* @0x160d7c vcvt.f64.u32 d7, s15 */
/* @0x160d80 vmov r0, r1, d7 */
/* @0x160d84 vmov r2, s14 */
/* @0x160d88 mov r3, r1 */
/* @0x160d8c stm r4, {r2, r3} */
/* @0x160d90 pop {r4, r5, r6, r7, r8, pc} */
/* @0x160d94 mov r7, r2 */
/* @0x160d98 movt r7, #0x3ff0 */
/* @0x160d9c mov r8, r2 */
/* @0x160da0 mov r5, #1 */
/* @0x160da4 mov r0, r5 */
/* @0x160da8 mov r1, r6 */
/* @0x160dac bl 0x18c12c <_Z18IO_Button_Releasedii> */
/* @0x160db0 add r5, r5, #1 */
/* @0x160db4 cmp r0, #0 */
/* @0x160db8 strne r8, [r4] */
/* @0x160dbc strne r7, [r4, #0x4] */
/* @0x160dc0 cmp r5, #4 */
/* @0x160dc4 bne 0x160da4 <_Z33F_CheckMouseButtonReleased_CommonR6RValueP9CInstanceS2_ii+0xb8> */
/* @0x160dc8 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x160dcc · F_CheckMouseButton(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x160dcc push {r4, r5, r6, lr} */
/* @0x160dd0 mov r5, r0 */
/* @0x160dd4 mov r4, r1 */
/* @0x160dd8 ldr r0, [sp, #0x10] */
/* @0x160ddc mov r1, #0 */
/* @0x160de0 mov r6, r2 */
/* @0x160de4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x160de8 mov r1, r4 */
/* @0x160dec mov r2, r6 */
/* @0x160df0 mov r12, #0 */
/* @0x160df4 str r12, [sp, #0x10] */
/* @0x160df8 mov r3, r0 */
/* @0x160dfc mov r0, r5 */
/* @0x160e00 pop {r4, r5, r6, lr} */
/* @0x160e04 b 0x160b2c <_Z25F_CheckMouseButton_CommonR6RValueP9CInstanceS2_ii> */

/* ── FUNC 0x160e08 · F_CheckMouseButtonPressed(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x160e08 push {r4, r5, r6, lr} */
/* @0x160e0c mov r5, r0 */
/* @0x160e10 mov r4, r1 */
/* @0x160e14 ldr r0, [sp, #0x10] */
/* @0x160e18 mov r1, #0 */
/* @0x160e1c mov r6, r2 */
/* @0x160e20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x160e24 mov r1, r4 */
/* @0x160e28 mov r2, r6 */
/* @0x160e2c mov r12, #0 */
/* @0x160e30 str r12, [sp, #0x10] */
/* @0x160e34 mov r3, r0 */
/* @0x160e38 mov r0, r5 */
/* @0x160e3c pop {r4, r5, r6, lr} */
/* @0x160e40 b 0x160c0c <_Z32F_CheckMouseButtonPressed_CommonR6RValueP9CInstanceS2_ii> */

/* ── FUNC 0x160e44 · F_CheckMouseButtonReleased(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x160e44 push {r4, r5, r6, lr} */
/* @0x160e48 mov r5, r0 */
/* @0x160e4c mov r4, r1 */
/* @0x160e50 ldr r0, [sp, #0x10] */
/* @0x160e54 mov r1, #0 */
/* @0x160e58 mov r6, r2 */
/* @0x160e5c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x160e60 mov r1, r4 */
/* @0x160e64 mov r2, r6 */
/* @0x160e68 mov r12, #0 */
/* @0x160e6c str r12, [sp, #0x10] */
/* @0x160e70 mov r3, r0 */
/* @0x160e74 mov r0, r5 */
/* @0x160e78 pop {r4, r5, r6, lr} */
/* @0x160e7c b 0x160cec <_Z33F_CheckMouseButtonReleased_CommonR6RValueP9CInstanceS2_ii> */

/* ── FUNC 0x160e80 · F_JoystickExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160e80 bx lr */

/* ── FUNC 0x160e84 · F_JoystickDirection(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160e84 bx lr */

/* ── FUNC 0x160e88 · F_JoystickName(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160e88 bx lr */

/* ── FUNC 0x160e8c · F_JoystickAxes(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160e8c bx lr */

/* ── FUNC 0x160e90 · F_JoystickButtons(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160e90 bx lr */

/* ── FUNC 0x160e94 · F_JoystickHasPov(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160e94 bx lr */

/* ── FUNC 0x160e98 · F_JoystickCheckButton(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160e98 bx lr */

/* ── FUNC 0x160e9c · F_JoystickXpos(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160e9c bx lr */

/* ── FUNC 0x160ea0 · F_JoystickYpos(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160ea0 bx lr */

/* ── FUNC 0x160ea4 · F_JoystickZpos(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160ea4 bx lr */
