/* libyoyo.so 覆盖卡组 0019
 * 函数 0xf27b4..0xf2c58，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xf27b4 · InputQuery::SetUserNamePassword(int, int, char const*) · size=140 · insn=35 */
/* @0xf27b4 ldr r3, [pc, #0x80] */
/* @0xf27b8 push {r4, r5, r6, lr} */
/* @0xf27bc ldr r3, [pc, r3] */
/* @0xf27c0 mov r5, r1 */
/* @0xf27c4 mov r6, r2 */
/* @0xf27c8 ldr r4, [r3] */
/* @0xf27cc cmp r4, #0 */
/* @0xf27d0 bne 0xf27e4 <_ZN10InputQuery19SetUserNamePasswordEiiPKc+0x30> */
/* @0xf27d4 pop {r4, r5, r6, pc} */
/* @0xf27d8 ldr r4, [r4, #0x4] */
/* @0xf27dc cmp r4, #0 */
/* @0xf27e0 beq 0xf2838 <_ZN10InputQuery19SetUserNamePasswordEiiPKc+0x84> */
/* @0xf27e4 ldr r3, [r4, #0x24] */
/* @0xf27e8 cmp r3, r0 */
/* @0xf27ec bne 0xf27d8 <_ZN10InputQuery19SetUserNamePasswordEiiPKc+0x24> */
/* @0xf27f0 cmp r6, #0 */
/* @0xf27f4 mov r3, #7 */
/* @0xf27f8 str r5, [r4, #0x28] */
/* @0xf27fc str r3, [r4, #0xc] */
/* @0xf2800 moveq r0, #1 */
/* @0xf2804 beq 0xf2814 <_ZN10InputQuery19SetUserNamePasswordEiiPKc+0x60> */
/* @0xf2808 mov r0, r6 */
/* @0xf280c bl 0xb6538 <strlen@plt> */
/* @0xf2810 add r0, r0, #1 */
/* @0xf2814 cmp r5, #0 */
/* @0xf2818 str r0, [r4, #0x38] */
/* @0xf281c str r6, [r4, #0x34] */
/* @0xf2820 addne r3, r5, #1 */
/* @0xf2824 str r5, [r4, #0x3c] */
/* @0xf2828 movne r2, #0 */
/* @0xf282c strbne r2, [r6, r5] */
/* @0xf2830 strne r3, [r4, #0x28] */
/* @0xf2834 pop {r4, r5, r6, pc} */
/* @0xf2838 pop {r4, r5, r6, pc} */
/* @0xf283c eoreq r11, pc, r12, lsr r6 */

/* ── FUNC 0xf2840 · _JNIEnv::CallStaticObjectMethod(_jclass*, _jmethodID*, ...) · size=56 · insn=14 */
/* @0xf2840 push {r2, r3} */
/* @0xf2844 str lr, [sp, #-0x4]! */
/* @0xf2848 sub sp, sp, #12 */
/* @0xf284c ldr lr, [r0] */
/* @0xf2850 add r12, sp, #20 */
/* @0xf2854 ldr r2, [sp, #0x10] */
/* @0xf2858 mov r3, r12 */
/* @0xf285c str r12, [sp, #0x4] */
/* @0xf2860 ldr r12, [lr, #0x1cc] */
/* @0xf2864 blx r12 */
/* @0xf2868 add sp, sp, #12 */
/* @0xf286c ldr lr, [sp], #4 */
/* @0xf2870 add sp, sp, #8 */
/* @0xf2874 bx lr */

/* ── FUNC 0xf2878 · _JNIEnv::CallStaticIntMethod(_jclass*, _jmethodID*, ...) · size=56 · insn=14 */
/* @0xf2878 push {r2, r3} */
/* @0xf287c str lr, [sp, #-0x4]! */
/* @0xf2880 sub sp, sp, #12 */
/* @0xf2884 ldr lr, [r0] */
/* @0xf2888 add r12, sp, #20 */
/* @0xf288c ldr r2, [sp, #0x10] */
/* @0xf2890 mov r3, r12 */
/* @0xf2894 str r12, [sp, #0x4] */
/* @0xf2898 ldr r12, [lr, #0x208] */
/* @0xf289c blx r12 */
/* @0xf28a0 add sp, sp, #12 */
/* @0xf28a4 ldr lr, [sp], #4 */
/* @0xf28a8 add sp, sp, #8 */
/* @0xf28ac bx lr */

/* ── FUNC 0xf28b0 · InputQuery::Input(char const*, char const*, char const*, char*&) · size=244 · insn=61 */
/* @0xf28b0 push {r4, r5, r6, lr} */
/* @0xf28b4 sub sp, sp, #8 */
/* @0xf28b8 mov r5, r2 */
/* @0xf28bc mov r4, r3 */
/* @0xf28c0 mov r6, r1 */
/* @0xf28c4 bl 0x290274 <getJNIEnv> */
/* @0xf28c8 mov r1, r6 */
/* @0xf28cc ldr r3, [r0] */
/* @0xf28d0 ldr r3, [r3, #0x29c] */
/* @0xf28d4 blx r3 */
/* @0xf28d8 mov r6, r0 */
/* @0xf28dc bl 0x290274 <getJNIEnv> */
/* @0xf28e0 mov r1, r5 */
/* @0xf28e4 ldr r3, [r0] */
/* @0xf28e8 ldr r3, [r3, #0x29c] */
/* @0xf28ec blx r3 */
/* @0xf28f0 mov r5, r0 */
/* @0xf28f4 bl 0x290274 <getJNIEnv> */
/* @0xf28f8 ldr r1, [pc, #0x9c] */
/* @0xf28fc mov r3, r6 */
/* @0xf2900 ldr r2, [pc, #0x98] */
/* @0xf2904 ldr r1, [pc, r1] */
/* @0xf2908 ldr r2, [pc, r2] */
/* @0xf290c ldr r1, [r1] */
/* @0xf2910 ldr r2, [r2] */
/* @0xf2914 str r5, [sp] */
/* @0xf2918 bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz> */
/* @0xf291c mov r5, r0 */
/* @0xf2920 bl 0x290274 <getJNIEnv> */
/* @0xf2924 mov r1, r5 */
/* @0xf2928 mov r2, #0 */
/* @0xf292c ldr r3, [r0] */
/* @0xf2930 ldr r3, [r3, #0x2a4] */
/* @0xf2934 blx r3 */
/* @0xf2938 mov r6, r0 */
/* @0xf293c ldr r0, [r4] */
/* @0xf2940 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf2944 mov r3, #0 */
/* @0xf2948 mov r0, r6 */
/* @0xf294c str r3, [r4] */
/* @0xf2950 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf2954 cmp r6, #0 */
/* @0xf2958 cmpne r5, #0 */
/* @0xf295c str r0, [r4] */
/* @0xf2960 beq 0xf2990 <_ZN10InputQuery5InputEPKcS1_S1_RPc+0xe0> */
/* @0xf2964 bl 0x290274 <getJNIEnv> */
/* @0xf2968 mov r1, r5 */
/* @0xf296c mov r2, r6 */
/* @0xf2970 ldr r3, [r0] */
/* @0xf2974 ldr r3, [r3, #0x2a8] */
/* @0xf2978 blx r3 */
/* @0xf297c bl 0x290274 <getJNIEnv> */
/* @0xf2980 mov r1, r5 */
/* @0xf2984 ldr r3, [r0] */
/* @0xf2988 ldr r3, [r3, #0x5c] */
/* @0xf298c blx r3 */
/* @0xf2990 mov r0, #1 */
/* @0xf2994 add sp, sp, #8 */
/* @0xf2998 pop {r4, r5, r6, pc} */
/* @0xf299c eoreq r11, pc, r0, lsr #1 */
/* @0xf29a0 .word 0x002fb4f4 */

/* ── FUNC 0xf29a4 · InputQuery::Question(char const*, char const*) · size=80 · insn=20 */
/* @0xf29a4 push {r4, lr} */
/* @0xf29a8 mov r4, r1 */
/* @0xf29ac bl 0x290274 <getJNIEnv> */
/* @0xf29b0 mov r1, r4 */
/* @0xf29b4 ldr r3, [r0] */
/* @0xf29b8 ldr r3, [r3, #0x29c] */
/* @0xf29bc blx r3 */
/* @0xf29c0 mov r4, r0 */
/* @0xf29c4 bl 0x290274 <getJNIEnv> */
/* @0xf29c8 ldr r1, [pc, #0x1c] */
/* @0xf29cc mov r3, r4 */
/* @0xf29d0 ldr r2, [pc, #0x18] */
/* @0xf29d4 ldr r1, [pc, r1] */
/* @0xf29d8 ldr r2, [pc, r2] */
/* @0xf29dc ldr r1, [r1] */
/* @0xf29e0 ldr r2, [r2] */
/* @0xf29e4 pop {r4, lr} */
/* @0xf29e8 b 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0xf29ec .word 0x002fafd0 */
/* @0xf29f0 eoreq r11, pc, r8, lsr #8 */

/* ── FUNC 0xf29f4 · inputDialogAsync · size=124 · insn=31 */
/* @0xf29f4 push {r4, r5, r6, lr} */
/* @0xf29f8 sub sp, sp, #8 */
/* @0xf29fc mov r4, r2 */
/* @0xf2a00 mov r5, r3 */
/* @0xf2a04 mov r6, r1 */
/* @0xf2a08 bl 0x290274 <getJNIEnv> */
/* @0xf2a0c mov r1, r6 */
/* @0xf2a10 ldr r3, [r0] */
/* @0xf2a14 ldr r3, [r3, #0x29c] */
/* @0xf2a18 blx r3 */
/* @0xf2a1c mov r6, r0 */
/* @0xf2a20 bl 0x290274 <getJNIEnv> */
/* @0xf2a24 mov r1, r4 */
/* @0xf2a28 ldr r3, [r0] */
/* @0xf2a2c ldr r3, [r3, #0x29c] */
/* @0xf2a30 blx r3 */
/* @0xf2a34 mov r4, r0 */
/* @0xf2a38 bl 0x290274 <getJNIEnv> */
/* @0xf2a3c ldr r1, [pc, #0x24] */
/* @0xf2a40 mov r3, r6 */
/* @0xf2a44 ldr r2, [pc, #0x20] */
/* @0xf2a48 ldr r1, [pc, r1] */
/* @0xf2a4c ldr r2, [pc, r2] */
/* @0xf2a50 ldr r1, [r1] */
/* @0xf2a54 ldr r2, [r2] */
/* @0xf2a58 stm sp, {r4, r5} */
/* @0xf2a5c bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0xf2a60 add sp, sp, #8 */
/* @0xf2a64 pop {r4, r5, r6, pc} */
/* @0xf2a68 eoreq r10, pc, r12, asr pc */
/* @0xf2a6c .word 0x002fb3b8 */

/* ── FUNC 0xf2a70 · questionDialogAsync · size=96 · insn=24 */
/* @0xf2a70 push {r4, r5, lr} */
/* @0xf2a74 sub sp, sp, #12 */
/* @0xf2a78 mov r4, r2 */
/* @0xf2a7c mov r5, r1 */
/* @0xf2a80 bl 0x290274 <getJNIEnv> */
/* @0xf2a84 mov r1, r5 */
/* @0xf2a88 ldr r3, [r0] */
/* @0xf2a8c ldr r3, [r3, #0x29c] */
/* @0xf2a90 blx r3 */
/* @0xf2a94 mov r5, r0 */
/* @0xf2a98 bl 0x290274 <getJNIEnv> */
/* @0xf2a9c ldr r1, [pc, #0x24] */
/* @0xf2aa0 mov r3, r5 */
/* @0xf2aa4 ldr r12, [pc, #0x20] */
/* @0xf2aa8 ldr r1, [pc, r1] */
/* @0xf2aac ldr r12, [pc, r12] */
/* @0xf2ab0 ldr r1, [r1] */
/* @0xf2ab4 ldr r2, [r12] */
/* @0xf2ab8 str r4, [sp] */
/* @0xf2abc bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0xf2ac0 add sp, sp, #12 */
/* @0xf2ac4 pop {r4, r5, pc} */
/* @0xf2ac8 .word 0x002faefc */
/* @0xf2acc eoreq r11, pc, r12, asr r3 */

/* ── FUNC 0xf2ad0 · loginDialogAsync · size=124 · insn=31 */
/* @0xf2ad0 push {r4, r5, r6, lr} */
/* @0xf2ad4 sub sp, sp, #8 */
/* @0xf2ad8 mov r5, r2 */
/* @0xf2adc mov r4, r1 */
/* @0xf2ae0 mov r6, r0 */
/* @0xf2ae4 bl 0x290274 <getJNIEnv> */
/* @0xf2ae8 mov r1, r6 */
/* @0xf2aec ldr r3, [r0] */
/* @0xf2af0 ldr r3, [r3, #0x29c] */
/* @0xf2af4 blx r3 */
/* @0xf2af8 mov r6, r0 */
/* @0xf2afc bl 0x290274 <getJNIEnv> */
/* @0xf2b00 mov r1, r4 */
/* @0xf2b04 ldr r3, [r0] */
/* @0xf2b08 ldr r3, [r3, #0x29c] */
/* @0xf2b0c blx r3 */
/* @0xf2b10 mov r4, r0 */
/* @0xf2b14 bl 0x290274 <getJNIEnv> */
/* @0xf2b18 ldr r1, [pc, #0x24] */
/* @0xf2b1c mov r3, r6 */
/* @0xf2b20 ldr r12, [pc, #0x20] */
/* @0xf2b24 ldr r1, [pc, r1] */
/* @0xf2b28 ldr r12, [pc, r12] */
/* @0xf2b2c ldr r1, [r1] */
/* @0xf2b30 ldr r2, [r12] */
/* @0xf2b34 stm sp, {r4, r5} */
/* @0xf2b38 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0xf2b3c add sp, sp, #8 */
/* @0xf2b40 pop {r4, r5, r6, pc} */
/* @0xf2b44 eoreq r10, pc, r0, lsl #29 */
/* @0xf2b48 eoreq r11, pc, r4, ror #5 */

/* ── FUNC 0xf2b4c · showMessage · size=96 · insn=24 */
/* @0xf2b4c push {r4, r5, lr} */
/* @0xf2b50 sub sp, sp, #12 */
/* @0xf2b54 mov r4, r2 */
/* @0xf2b58 mov r5, r1 */
/* @0xf2b5c bl 0x290274 <getJNIEnv> */
/* @0xf2b60 mov r1, r5 */
/* @0xf2b64 ldr r3, [r0] */
/* @0xf2b68 ldr r3, [r3, #0x29c] */
/* @0xf2b6c blx r3 */
/* @0xf2b70 mov r5, r0 */
/* @0xf2b74 bl 0x290274 <getJNIEnv> */
/* @0xf2b78 ldr r1, [pc, #0x24] */
/* @0xf2b7c mov r3, r5 */
/* @0xf2b80 ldr r12, [pc, #0x20] */
/* @0xf2b84 ldr r1, [pc, r1] */
/* @0xf2b88 ldr r12, [pc, r12] */
/* @0xf2b8c ldr r1, [r1] */
/* @0xf2b90 ldr r2, [r12] */
/* @0xf2b94 str r4, [sp] */
/* @0xf2b98 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0xf2b9c add sp, sp, #12 */
/* @0xf2ba0 pop {r4, r5, pc} */
/* @0xf2ba4 eoreq r10, pc, r0, lsr #28 */
/* @0xf2ba8 eoreq r11, pc, r8, lsl #5 */

/* ── FUNC 0xf2bac · InitDPlay() · size=8 · insn=2 */
/* @0xf2bac mov r0, #0 */
/* @0xf2bb0 bx lr */

/* ── FUNC 0xf2bb4 · DPlay_Init_IPX() · size=8 · insn=2 */
/* @0xf2bb4 mov r0, #0 */
/* @0xf2bb8 bx lr */

/* ── FUNC 0xf2bbc · DPlay_Init_TCPIP(char const*) · size=8 · insn=2 */
/* @0xf2bbc mov r0, #0 */
/* @0xf2bc0 bx lr */

/* ── FUNC 0xf2bc4 · DPlay_Init_Modem(char const*, char const*) · size=8 · insn=2 */
/* @0xf2bc4 mov r0, #0 */
/* @0xf2bc8 bx lr */

/* ── FUNC 0xf2bcc · DPlay_Init_Serial(int, int, int, int, int) · size=8 · insn=2 */
/* @0xf2bcc mov r0, #0 */
/* @0xf2bd0 bx lr */

/* ── FUNC 0xf2bd4 · DPlay_End() · size=4 · insn=1 */
/* @0xf2bd4 bx lr */

/* ── FUNC 0xf2bd8 · DPlay_Session_Mode(bool) · size=20 · insn=5 */
/* @0xf2bd8 ldr r3, [pc, #0x8] */
/* @0xf2bdc ldr r3, [pc, r3] */
/* @0xf2be0 strb r0, [r3] */
/* @0xf2be4 bx lr */
/* @0xf2be8 eoreq r11, pc, r8, lsr r2 */

/* ── FUNC 0xf2bec · DPlay_Session_Create(char const*, int, char const*) · size=8 · insn=2 */
/* @0xf2bec mov r0, #0 */
/* @0xf2bf0 bx lr */

/* ── FUNC 0xf2bf4 · DPlay_Session_End() · size=4 · insn=1 */
/* @0xf2bf4 bx lr */

/* ── FUNC 0xf2bf8 · DPlay_Session_Find() · size=8 · insn=2 */
/* @0xf2bf8 mov r0, #0 */
/* @0xf2bfc bx lr */

/* ── FUNC 0xf2c00 · DPlay_Session_Name(int) · size=8 · insn=2 */
/* @0xf2c00 mov r0, #0 */
/* @0xf2c04 bx lr */

/* ── FUNC 0xf2c08 · DPlay_Session_Join(int, char const*) · size=8 · insn=2 */
/* @0xf2c08 mov r0, #0 */
/* @0xf2c0c bx lr */

/* ── FUNC 0xf2c10 · DPlay_Player_Find() · size=8 · insn=2 */
/* @0xf2c10 mov r0, #0 */
/* @0xf2c14 bx lr */

/* ── FUNC 0xf2c18 · DPlay_Player_Name(int) · size=8 · insn=2 */
/* @0xf2c18 mov r0, #0 */
/* @0xf2c1c bx lr */

/* ── FUNC 0xf2c20 · DPlay_Player_Id(int) · size=8 · insn=2 */
/* @0xf2c20 mov r0, #0 */
/* @0xf2c24 bx lr */

/* ── FUNC 0xf2c28 · DPlay_Data_Write(int, RValue*) · size=8 · insn=2 */
/* @0xf2c28 mov r0, #0 */
/* @0xf2c2c bx lr */

/* ── FUNC 0xf2c30 · DPlay_Data_Read(int, RValue*) · size=4 · insn=1 */
/* @0xf2c30 bx lr */

/* ── FUNC 0xf2c34 · DPlay_Data_Mode(bool) · size=4 · insn=1 */
/* @0xf2c34 bx lr */

/* ── FUNC 0xf2c38 · DPlay_Message_Send(unsigned int, int, RValue*) · size=8 · insn=2 */
/* @0xf2c38 mov r0, #0 */
/* @0xf2c3c bx lr */

/* ── FUNC 0xf2c40 · DPlay_Message_Send_Guaranteed(int, int, RValue*) · size=8 · insn=2 */
/* @0xf2c40 mov r0, #0 */
/* @0xf2c44 bx lr */

/* ── FUNC 0xf2c48 · DPlay_Message_Send_Name(char const*, int, RValue*) · size=8 · insn=2 */
/* @0xf2c48 mov r0, #0 */
/* @0xf2c4c bx lr */

/* ── FUNC 0xf2c50 · DPlay_Message_Send_Name_Guaranteed(char const*, int, RValue*) · size=8 · insn=2 */
/* @0xf2c50 mov r0, #0 */
/* @0xf2c54 bx lr */

/* ── FUNC 0xf2c58 · DPlay_Message_Receive(int) · size=8 · insn=2 */
/* @0xf2c58 mov r0, #0 */
/* @0xf2c5c bx lr */
