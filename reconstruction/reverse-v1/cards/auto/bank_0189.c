/* libyoyo.so 覆盖卡组 0189
 * 函数 0x21485c..0x214e18，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x21485c · CD_Present() · size=8 · insn=2 */
/* @0x21485c mov r0, #1 */
/* @0x214860 bx lr */

/* ── FUNC 0x214864 · CD_NumberOfTracks() · size=8 · insn=2 */
/* @0x214864 mov r0, #0 */
/* @0x214868 bx lr */

/* ── FUNC 0x21486c · CD_Playing() · size=8 · insn=2 */
/* @0x21486c mov r0, #0 */
/* @0x214870 bx lr */

/* ── FUNC 0x214874 · CD_Paused() · size=8 · insn=2 */
/* @0x214874 mov r0, #0 */
/* @0x214878 bx lr */

/* ── FUNC 0x21487c · CD_Track() · size=8 · insn=2 */
/* @0x21487c mov r0, #0 */
/* @0x214880 bx lr */

/* ── FUNC 0x214884 · CD_Length() · size=8 · insn=2 */
/* @0x214884 mov r0, #0 */
/* @0x214888 bx lr */

/* ── FUNC 0x21488c · CD_TrackLength(int) · size=8 · insn=2 */
/* @0x21488c mov r0, #0 */
/* @0x214890 bx lr */

/* ── FUNC 0x214894 · CD_Position() · size=8 · insn=2 */
/* @0x214894 mov r0, #0 */
/* @0x214898 bx lr */

/* ── FUNC 0x21489c · CD_TrackPosition() · size=8 · insn=2 */
/* @0x21489c mov r0, #0 */
/* @0x2148a0 bx lr */

/* ── FUNC 0x2148a4 · CD_Play(int, int) · size=4 · insn=1 */
/* @0x2148a4 bx lr */

/* ── FUNC 0x2148a8 · CD_Stop() · size=4 · insn=1 */
/* @0x2148a8 bx lr */

/* ── FUNC 0x2148ac · CD_Pause() · size=4 · insn=1 */
/* @0x2148ac bx lr */

/* ── FUNC 0x2148b0 · CD_Resume() · size=4 · insn=1 */
/* @0x2148b0 bx lr */

/* ── FUNC 0x2148b4 · CD_SetPosition(int) · size=4 · insn=1 */
/* @0x2148b4 bx lr */

/* ── FUNC 0x2148b8 · CD_SetTrackPosition(int) · size=4 · insn=1 */
/* @0x2148b8 bx lr */

/* ── FUNC 0x2148bc · CD_OpenDoor() · size=4 · insn=1 */
/* @0x2148bc bx lr */

/* ── FUNC 0x2148c0 · CD_CloseDoor() · size=4 · insn=1 */
/* @0x2148c0 bx lr */

/* ── FUNC 0x2148c4 · _JNIEnv::CallDoubleMethod(_jobject*, _jmethodID*, ...) · size=56 · insn=14 */
/* @0x2148c4 push {r2, r3} */
/* @0x2148c8 str lr, [sp, #-0x4]! */
/* @0x2148cc sub sp, sp, #12 */
/* @0x2148d0 ldr lr, [r0] */
/* @0x2148d4 add r12, sp, #20 */
/* @0x2148d8 ldr r2, [sp, #0x10] */
/* @0x2148dc mov r3, r12 */
/* @0x2148e0 str r12, [sp, #0x4] */
/* @0x2148e4 ldr r12, [lr, #0xec] */
/* @0x2148e8 blx r12 */
/* @0x2148ec add sp, sp, #12 */
/* @0x2148f0 ldr lr, [sp], #4 */
/* @0x2148f4 add sp, sp, #8 */
/* @0x2148f8 bx lr */

/* ── FUNC 0x2148fc · DLL_Define(char const*, char const*, int, int, int*, int) · size=8 · insn=2 */
/* @0x2148fc mvn r0, #0 */
/* @0x214900 bx lr */

/* ── FUNC 0x214904 · DLL_Free(char const*) · size=4 · insn=1 */
/* @0x214904 bx lr */

/* ── FUNC 0x214908 · GetJObjectToString(_jobject*) · size=96 · insn=24 */
/* @0x214908 push {r4, r5, r6, lr} */
/* @0x21490c sub sp, sp, #8 */
/* @0x214910 mov r4, r0 */
/* @0x214914 bl 0x290274 <getJNIEnv> */
/* @0x214918 mov r1, r4 */
/* @0x21491c add r2, sp, #7 */
/* @0x214920 ldr r3, [r0] */
/* @0x214924 ldr r3, [r3, #0x2a4] */
/* @0x214928 blx r3 */
/* @0x21492c mov r5, r0 */
/* @0x214930 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x214934 cmp r5, #0 */
/* @0x214938 cmpne r4, #0 */
/* @0x21493c mov r6, r0 */
/* @0x214940 beq 0x21495c <_Z18GetJObjectToStringP8_jobject+0x54> */
/* @0x214944 bl 0x290274 <getJNIEnv> */
/* @0x214948 mov r1, r4 */
/* @0x21494c mov r2, r5 */
/* @0x214950 ldr r3, [r0] */
/* @0x214954 ldr r3, [r3, #0x2a8] */
/* @0x214958 blx r3 */
/* @0x21495c mov r0, r6 */
/* @0x214960 add sp, sp, #8 */
/* @0x214964 pop {r4, r5, r6, pc} */

/* ── FUNC 0x214968 · GetJObjectToDouble(_jobject*) · size=176 · insn=44 */
/* @0x214968 push {r4, r5, r6, lr} */
/* @0x21496c mov r5, r0 */
/* @0x214970 bl 0x290274 <getJNIEnv> */
/* @0x214974 ldr r1, [pc, #0x90] */
/* @0x214978 add r1, pc, r1 */
/* @0x21497c ldr r3, [r0] */
/* @0x214980 ldr r3, [r3, #0x18] */
/* @0x214984 blx r3 */
/* @0x214988 subs r4, r0, #0 */
/* @0x21498c beq 0x214a00 <_Z18GetJObjectToDoubleP8_jobject+0x98> */
/* @0x214990 bl 0x290274 <getJNIEnv> */
/* @0x214994 mov r1, r5 */
/* @0x214998 mov r2, r4 */
/* @0x21499c ldr r3, [r0] */
/* @0x2149a0 ldr r3, [r3, #0x80] */
/* @0x2149a4 blx r3 */
/* @0x2149a8 cmp r0, #0 */
/* @0x2149ac beq 0x214a00 <_Z18GetJObjectToDoubleP8_jobject+0x98> */
/* @0x2149b0 bl 0x290274 <getJNIEnv> */
/* @0x2149b4 ldr r2, [pc, #0x54] */
/* @0x2149b8 ldr r3, [pc, #0x54] */
/* @0x2149bc mov r1, r4 */
/* @0x2149c0 add r2, pc, r2 */
/* @0x2149c4 add r3, pc, r3 */
/* @0x2149c8 ldr r12, [r0] */
/* @0x2149cc ldr r12, [r12, #0x84] */
/* @0x2149d0 blx r12 */
/* @0x2149d4 mov r6, r0 */
/* @0x2149d8 bl 0x290274 <getJNIEnv> */
/* @0x2149dc mov r1, r4 */
/* @0x2149e0 ldr r3, [r0] */
/* @0x2149e4 ldr r3, [r3, #0x5c] */
/* @0x2149e8 blx r3 */
/* @0x2149ec bl 0x290274 <getJNIEnv> */
/* @0x2149f0 mov r1, r5 */
/* @0x2149f4 mov r2, r6 */
/* @0x2149f8 pop {r4, r5, r6, lr} */
/* @0x2149fc b 0x2148c4 <_ZN7_JNIEnv16CallDoubleMethodEP8_jobjectP10_jmethodIDz> */
/* @0x214a00 mov r0, #0 */
/* @0x214a04 mov r1, #0 */
/* @0x214a08 pop {r4, r5, r6, pc} */
/* @0x214a0c andseq pc, r3, r12, asr #32 */
/* @0x214a10 andseq pc, r3, r8, lsl r0 */
/* @0x214a14 andseq pc, r3, r0, lsr #32 */

/* ── FUNC 0x214a18 · Ext_Call(int, int, RValue*, RValue*) · size=964 · insn=241 */
/* @0x214a18 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x214a1c mov r6, r1 */
/* @0x214a20 ldr r9, [pc, #0x394] */
/* @0x214a24 sub sp, sp, #60 */
/* @0x214a28 ldr r1, [pc, #0x390] */
/* @0x214a2c mov r7, r2 */
/* @0x214a30 add r9, pc, r9 */
/* @0x214a34 str r3, [sp, #0x28] */
/* @0x214a38 ldr r3, [r9, r1] */
/* @0x214a3c ldr r3, [r3] */
/* @0x214a40 ldr r3, [r3, r0, lsl #2] */
/* @0x214a44 str r3, [sp, #0x1c] */
/* @0x214a48 bl 0x290274 <getJNIEnv> */
/* @0x214a4c ldr r11, [sp, #0x1c] */
/* @0x214a50 mov r4, r0 */
/* @0x214a54 ldr r0, [r11, #0x60] */
/* @0x214a58 bl 0xf55c8 <_ZN17CExtensionPackage12GetClassNameEv> */
/* @0x214a5c ldr r3, [r4] */
/* @0x214a60 ldr r3, [r3, #0x29c] */
/* @0x214a64 mov r1, r0 */
/* @0x214a68 mov r0, r4 */
/* @0x214a6c blx r3 */
/* @0x214a70 str r0, [sp, #0x14] */
/* @0x214a74 bl 0x290274 <getJNIEnv> */
/* @0x214a78 mov r4, r0 */
/* @0x214a7c ldr r0, [sp, #0x1c] */
/* @0x214a80 bl 0xf4be4 <_ZN18CExtensionFunction15GetExternalNameEv> */
/* @0x214a84 ldr r3, [r4] */
/* @0x214a88 ldr r3, [r3, #0x29c] */
/* @0x214a8c mov r1, r0 */
/* @0x214a90 mov r0, r4 */
/* @0x214a94 blx r3 */
/* @0x214a98 str r0, [sp, #0x18] */
/* @0x214a9c bl 0x290274 <getJNIEnv> */
/* @0x214aa0 mov r4, r0 */
/* @0x214aa4 ldr r0, [sp, #0x1c] */
/* @0x214aa8 bl 0xf4c38 <_ZN18CExtensionFunction11GetArgCountEv> */
/* @0x214aac ldr r3, [r4] */
/* @0x214ab0 ldr r3, [r3, #0x2d8] */
/* @0x214ab4 mov r1, r0 */
/* @0x214ab8 mov r0, r4 */
/* @0x214abc blx r3 */
/* @0x214ac0 mov r8, r0 */
/* @0x214ac4 bl 0x290274 <getJNIEnv> */
/* @0x214ac8 ldr r1, [pc, #0x2f4] */
/* @0x214acc add r1, pc, r1 */
/* @0x214ad0 ldr r3, [r0] */
/* @0x214ad4 ldr r3, [r3, #0x18] */
/* @0x214ad8 blx r3 */
/* @0x214adc mov r5, r0 */
/* @0x214ae0 bl 0x290274 <getJNIEnv> */
/* @0x214ae4 mov r4, r0 */
/* @0x214ae8 ldr r0, [sp, #0x1c] */
/* @0x214aec bl 0xf4c38 <_ZN18CExtensionFunction11GetArgCountEv> */
/* @0x214af0 ldr r12, [r4] */
/* @0x214af4 mov r2, r5 */
/* @0x214af8 mov r3, #0 */
/* @0x214afc ldr r12, [r12, #0x2b0] */
/* @0x214b00 mov r1, r0 */
/* @0x214b04 mov r0, r4 */
/* @0x214b08 blx r12 */
/* @0x214b0c cmp r6, #0 */
/* @0x214b10 str r0, [sp, #0x24] */
/* @0x214b14 ble 0x214bec <_Z8Ext_CalliiP6RValueS0_+0x1d4> */
/* @0x214b18 ldr r12, [pc, #0x2a8] */
/* @0x214b1c add r10, sp, #48 */
/* @0x214b20 ldr r11, [pc, #0x2a4] */
/* @0x214b24 mov r5, r7 */
/* @0x214b28 add r12, pc, r12 */
/* @0x214b2c mov r4, #0 */
/* @0x214b30 add r11, pc, r11 */
/* @0x214b34 str r12, [sp, #0x20] */
/* @0x214b38 str r11, [sp, #0x2c] */
/* @0x214b3c b 0x214b9c <_Z8Ext_CalliiP6RValueS0_+0x184> */
/* @0x214b40 cmp r12, #7 */
/* @0x214b44 beq 0x214bac <_Z8Ext_CalliiP6RValueS0_+0x194> */
/* @0x214b48 cmp r12, #13 */
/* @0x214b4c beq 0x214bac <_Z8Ext_CalliiP6RValueS0_+0x194> */
/* @0x214b50 cmp r12, #1 */
/* @0x214b54 beq 0x214d64 <_Z8Ext_CalliiP6RValueS0_+0x34c> */
/* @0x214b58 cmp r12, #3 */
/* @0x214b5c beq 0x214cec <_Z8Ext_CalliiP6RValueS0_+0x2d4> */
/* @0x214b60 ldr r0, [pc, #0x268] */
/* @0x214b64 mov r2, r4 */
/* @0x214b68 ldr r11, [sp, #0x18] */
/* @0x214b6c ldr r1, [sp, #0x20] */
/* @0x214b70 ldr r0, [r9, r0] */
/* @0x214b74 ldr r3, [sp, #0x14] */
/* @0x214b78 ldr r0, [r0] */
/* @0x214b7c ldr lr, [r0] */
/* @0x214b80 stm sp, {r11, r12} */
/* @0x214b84 ldr r12, [lr, #0xc] */
/* @0x214b88 blx r12 */
/* @0x214b8c add r4, r4, #1 */
/* @0x214b90 add r5, r5, #16 */
/* @0x214b94 cmp r4, r6 */
/* @0x214b98 beq 0x214bec <_Z8Ext_CalliiP6RValueS0_+0x1d4> */
/* @0x214b9c ldr r12, [r5, #0xc] */
/* @0x214ba0 cmp r12, #10 */
/* @0x214ba4 cmpne r12, #0 */
/* @0x214ba8 bne 0x214b40 <_Z8Ext_CalliiP6RValueS0_+0x128> */
/* @0x214bac mov r1, r4 */
/* @0x214bb0 mov r0, r7 */
/* @0x214bb4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x214bb8 add r5, r5, #16 */
/* @0x214bbc strd r0, r1, [sp, #48] */
/* @0x214bc0 bl 0x290274 <getJNIEnv> */
/* @0x214bc4 mov r2, r4 */
/* @0x214bc8 mov r1, r8 */
/* @0x214bcc mov r3, #1 */
/* @0x214bd0 add r4, r4, #1 */
/* @0x214bd4 ldr r12, [r0] */
/* @0x214bd8 str r10, [sp] */
/* @0x214bdc ldr r12, [r12, #0x358] */
/* @0x214be0 blx r12 */
/* @0x214be4 cmp r4, r6 */
/* @0x214be8 bne 0x214b9c <_Z8Ext_CalliiP6RValueS0_+0x184> */
/* @0x214bec bl 0x290274 <getJNIEnv> */
/* @0x214bf0 ldr r2, [pc, #0x1dc] */
/* @0x214bf4 ldr r3, [pc, #0x1dc] */
/* @0x214bf8 ldr r2, [r9, r2] */
/* @0x214bfc ldr r3, [r9, r3] */
/* @0x214c00 ldr r6, [r2] */
/* @0x214c04 ldr r5, [r3] */
/* @0x214c08 mov r4, r0 */
/* @0x214c0c ldr r0, [sp, #0x1c] */
/* @0x214c10 bl 0xf4c38 <_ZN18CExtensionFunction11GetArgCountEv> */
/* @0x214c14 ldr r12, [sp, #0x18] */
/* @0x214c18 ldr r11, [sp, #0x24] */
/* @0x214c1c mov r2, r5 */
/* @0x214c20 ldr r3, [sp, #0x14] */
/* @0x214c24 mov r1, r6 */
/* @0x214c28 str r12, [sp] */
/* @0x214c2c str r8, [sp, #0x8] */
/* @0x214c30 str r11, [sp, #0xc] */
/* @0x214c34 str r0, [sp, #0x4] */
/* @0x214c38 mov r0, r4 */
/* @0x214c3c bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz> */
/* @0x214c40 mov r4, r0 */
/* @0x214c44 bl 0x290274 <getJNIEnv> */
/* @0x214c48 ldr r1, [sp, #0x14] */
/* @0x214c4c ldr r3, [r0] */
/* @0x214c50 ldr r3, [r3, #0x5c] */
/* @0x214c54 blx r3 */
/* @0x214c58 bl 0x290274 <getJNIEnv> */
/* @0x214c5c ldr r1, [sp, #0x18] */
/* @0x214c60 ldr r3, [r0] */
/* @0x214c64 ldr r3, [r3, #0x5c] */
/* @0x214c68 blx r3 */
/* @0x214c6c bl 0x290274 <getJNIEnv> */
/* @0x214c70 mov r1, r8 */
/* @0x214c74 ldr r3, [r0] */
/* @0x214c78 ldr r3, [r3, #0x5c] */
/* @0x214c7c blx r3 */
/* @0x214c80 bl 0x290274 <getJNIEnv> */
/* @0x214c84 ldr r1, [sp, #0x24] */
/* @0x214c88 ldr r3, [r0] */
/* @0x214c8c ldr r3, [r3, #0x5c] */
/* @0x214c90 blx r3 */
/* @0x214c94 cmp r4, #0 */
/* @0x214c98 beq 0x214dac <_Z8Ext_CalliiP6RValueS0_+0x394> */
/* @0x214c9c ldr r0, [sp, #0x1c] */
/* @0x214ca0 bl 0xf4c48 <_ZN18CExtensionFunction13GetReturnTypeEv> */
/* @0x214ca4 cmp r0, #1 */
/* @0x214ca8 beq 0x214d94 <_Z8Ext_CalliiP6RValueS0_+0x37c> */
/* @0x214cac cmp r0, #2 */
/* @0x214cb0 bne 0x214cd0 <_Z8Ext_CalliiP6RValueS0_+0x2b8> */
/* @0x214cb4 ldr r12, [sp, #0x28] */
/* @0x214cb8 mov r3, #0 */
/* @0x214cbc mov r0, r4 */
/* @0x214cc0 str r3, [r12, #0xc] */
/* @0x214cc4 bl 0x214968 <_Z18GetJObjectToDoubleP8_jobject> */
/* @0x214cc8 ldr r11, [sp, #0x28] */
/* @0x214ccc stm r11, {r0, r1} */
/* @0x214cd0 bl 0x290274 <getJNIEnv> */
/* @0x214cd4 mov r1, r4 */
/* @0x214cd8 ldr r3, [r0] */
/* @0x214cdc ldr r3, [r3, #0x5c] */
/* @0x214ce0 blx r3 */
/* @0x214ce4 add sp, sp, #60 */
/* @0x214ce8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x214cec mov r1, r4 */
/* @0x214cf0 mov r0, r7 */
/* @0x214cf4 bl 0xcec18 <_Z8YYGetPtrPK6RValuei> */
/* @0x214cf8 mov r11, r0 */
/* @0x214cfc bl 0xc6754 <_Z10GetIBufferPv> */
/* @0x214d00 subs r3, r0, #0 */
/* @0x214d04 beq 0x214b8c <_Z8Ext_CalliiP6RValueS0_+0x174> */
/* @0x214d08 str r3, [sp, #0x10] */
/* @0x214d0c bl 0x290274 <getJNIEnv> */
/* @0x214d10 ldr r3, [sp, #0x10] */
/* @0x214d14 mov r1, r11 */
/* @0x214d18 ldr r2, [r3, #0x10] */
/* @0x214d1c asr r3, r2, #31 */
/* @0x214d20 ldr r12, [r0] */
/* @0x214d24 ldr r12, [r12, #0x394] */
/* @0x214d28 blx r12 */
/* @0x214d2c mov r11, r0 */
/* @0x214d30 bl 0x290274 <getJNIEnv> */
/* @0x214d34 mov r3, r11 */
/* @0x214d38 ldr r1, [sp, #0x24] */
/* @0x214d3c mov r2, r4 */
/* @0x214d40 ldr r12, [r0] */
/* @0x214d44 ldr r12, [r12, #0x2b8] */
/* @0x214d48 blx r12 */
/* @0x214d4c bl 0x290274 <getJNIEnv> */
/* @0x214d50 mov r1, r11 */
/* @0x214d54 ldr r3, [r0] */
/* @0x214d58 ldr r3, [r3, #0x5c] */
/* @0x214d5c blx r3 */
/* @0x214d60 b 0x214b8c <_Z8Ext_CalliiP6RValueS0_+0x174> */
/* @0x214d64 mov r1, r4 */
/* @0x214d68 mov r0, r7 */
/* @0x214d6c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x214d70 ldr r12, [sp, #0x2c] */
/* @0x214d74 subs r11, r0, #0 */
/* @0x214d78 moveq r11, r12 */
/* @0x214d7c bl 0x290274 <getJNIEnv> */
/* @0x214d80 mov r1, r11 */
/* @0x214d84 ldr r3, [r0] */
/* @0x214d88 ldr r3, [r3, #0x29c] */
/* @0x214d8c blx r3 */
/* @0x214d90 b 0x214d2c <_Z8Ext_CalliiP6RValueS0_+0x314> */
/* @0x214d94 mov r0, r4 */
/* @0x214d98 bl 0x214908 <_Z18GetJObjectToStringP8_jobject> */
/* @0x214d9c mov r1, r0 */
/* @0x214da0 ldr r0, [sp, #0x28] */
/* @0x214da4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x214da8 b 0x214cd0 <_Z8Ext_CalliiP6RValueS0_+0x2b8> */
/* @0x214dac ldr r12, [sp, #0x28] */
/* @0x214db0 mov r3, #5 */
/* @0x214db4 str r3, [r12, #0xc] */
/* @0x214db8 b 0x214cd0 <_Z8Ext_CalliiP6RValueS0_+0x2b8> */
/* @0x214dbc andseq sp, sp, r0, lsr #4 */
/* @0x214dc0 .word 0xffffc1f0 */
/* @0x214dc4 andseq lr, r3, r12, lsl pc */
/* @0x214dc8 ldrsbeq lr, [r3], -r4 */
/* @0x214dcc andseq r10, r1, r6 */
/* @0x214dd0 .word 0xffffbcf0 */
/* @0x214dd4 .word 0xffffbd54 */
/* @0x214dd8 .word 0xfffff76c */

/* ── FUNC 0x214ddc · File_ShellExecute(char const*, char const*, char const*) · size=8 · insn=2 */
/* @0x214ddc mov r0, #0 */
/* @0x214de0 bx lr */

/* ── FUNC 0x214de4 · File_Execute(char const*, char const*, char const*, bool) · size=8 · insn=2 */
/* @0x214de4 mov r0, #0 */
/* @0x214de8 bx lr */

/* ── FUNC 0x214dec · CreateTempDir(char const*) · size=8 · insn=2 */
/* @0x214dec mov r0, #1 */
/* @0x214df0 bx lr */

/* ── FUNC 0x214df4 · MakeTempDir() · size=4 · insn=1 */
/* @0x214df4 bx lr */

/* ── FUNC 0x214df8 · DestroyTempDir() · size=4 · insn=1 */
/* @0x214df8 bx lr */

/* ── FUNC 0x214dfc · File_TempDir() · size=20 · insn=5 */
/* @0x214dfc ldr r3, [pc, #0x8] */
/* @0x214e00 ldr r3, [pc, r3] */
/* @0x214e04 ldr r0, [r3] */
/* @0x214e08 b 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x214e0c andseq r12, sp, r0, asr #11 */

/* ── FUNC 0x214e10 · INITIALIZE_Support_File() · size=4 · insn=1 */
/* @0x214e10 b 0x214df4 <_Z11MakeTempDirv> */

/* ── FUNC 0x214e14 · FINALIZE_Support_File() · size=4 · insn=1 */
/* @0x214e14 b 0x214df8 <_Z14DestroyTempDirv> */

/* ── FUNC 0x214e18 · DestroyDir(char const*) · size=4 · insn=1 */
/* @0x214e18 bx lr */
