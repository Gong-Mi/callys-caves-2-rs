/* libyoyo.so 覆盖卡组 0005
 * 函数 0xc4890..0xc57c0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xc4890 · TRelConsole::Output(char const*, ...) · size=212 · insn=53 */
/* @0xc4890 push {r1, r2, r3} */
/* @0xc4894 movw r1, #0xeff8 */
/* @0xc4898 push {r4, r5, r6, lr} */
/* @0xc489c sub sp, sp, #4096 */
/* @0xc48a0 sub sp, sp, #12 */
/* @0xc48a4 ldr r2, [pc, #0xac] */
/* @0xc48a8 ldr r4, [pc, #0xac] */
/* @0xc48ac add r0, sp, #4096 */
/* @0xc48b0 movt r1, #0xffff */
/* @0xc48b4 ldr r2, [pc, r2] */
/* @0xc48b8 add r0, r0, #8 */
/* @0xc48bc add r3, sp, #4096 */
/* @0xc48c0 ldr r4, [pc, r4] */
/* @0xc48c4 add r3, r3, #32 */
/* @0xc48c8 str r3, [r0, r1] */
/* @0xc48cc ldrb r1, [r2] */
/* @0xc48d0 ldr r2, [r4] */
/* @0xc48d4 cmp r1, #0 */
/* @0xc48d8 add r1, sp, #8192 */
/* @0xc48dc ldr r5, [r1, #-0xfe4] */
/* @0xc48e0 str r2, [r1, #-0xffc] */
/* @0xc48e4 beq 0xc4904 <_ZN11TRelConsole6OutputEPKcz+0x74> */
/* @0xc48e8 add r6, sp, #4 */
/* @0xc48ec mov r1, #4096 */
/* @0xc48f0 mov r2, r5 */
/* @0xc48f4 mov r0, r6 */
/* @0xc48f8 bl 0xb6610 <vsnprintf@plt> */
/* @0xc48fc mov r0, r6 */
/* @0xc4900 bl 0x29bfcc <_Z18Debug_BufferOutputPKc> */
/* @0xc4904 add r1, sp, #4096 */
/* @0xc4908 movw r3, #0xeff8 */
/* @0xc490c add r1, r1, #8 */
/* @0xc4910 movt r3, #0xffff */
/* @0xc4914 mov r2, r5 */
/* @0xc4918 mov r0, #4 */
/* @0xc491c ldr r3, [r1, r3] */
/* @0xc4920 ldr r1, [pc, #0x38] */
/* @0xc4924 add r1, pc, r1 */
/* @0xc4928 bl 0xb661c <__android_log_vprint@plt> */
/* @0xc492c add r3, sp, #8192 */
/* @0xc4930 ldr r2, [r3, #-0xffc] */
/* @0xc4934 ldr r3, [r4] */
/* @0xc4938 cmp r2, r3 */
/* @0xc493c bne 0xc4954 <_ZN11TRelConsole6OutputEPKcz+0xc4> */
/* @0xc4940 add sp, sp, #4096 */
/* @0xc4944 add sp, sp, #12 */
/* @0xc4948 pop {r4, r5, r6, lr} */
/* @0xc494c add sp, sp, #12 */
/* @0xc4950 bx lr */
/* @0xc4954 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xc4958 eorseq r9, r2, r8, asr #1 */
/* @0xc495c mlaseq r2, r0, r0, r9 */
/* @0xc4960 eoreq r12, r6, r0, lsl r2 */

/* ── FUNC 0xc4964 · _itoa(int, char*, int) · size=176 · insn=44 */
/* @0xc4964 sub r3, r2, #2 */
/* @0xc4968 cmp r3, #34 */
/* @0xc496c push {r4, r5, r6, r7, r8, lr} */
/* @0xc4970 movhi r3, #0 */
/* @0xc4974 mov r5, r2 */
/* @0xc4978 mov r4, r0 */
/* @0xc497c mov r7, r1 */
/* @0xc4980 strbhi r3, [r1] */
/* @0xc4984 bhi 0xc4a08 <_Z5_itoaiPci+0xa4> */
/* @0xc4988 ldr r8, [pc, #0x80] */
/* @0xc498c mov r6, r1 */
/* @0xc4990 add r8, pc, r8 */
/* @0xc4994 b 0xc49a0 <_Z5_itoaiPci+0x3c> */
/* @0xc4998 mov r4, r0 */
/* @0xc499c mov r6, r3 */
/* @0xc49a0 mov r0, r4 */
/* @0xc49a4 mov r1, r5 */
/* @0xc49a8 bl 0x318d10 <__divsi3> */
/* @0xc49ac mov r3, r6 */
/* @0xc49b0 mls r2, r5, r0, r4 */
/* @0xc49b4 cmp r0, #0 */
/* @0xc49b8 add r2, r8, r2 */
/* @0xc49bc ldrb r2, [r2, #0x23] */
/* @0xc49c0 strb r2, [r3], #1 */
/* @0xc49c4 bne 0xc4998 <_Z5_itoaiPci+0x34> */
/* @0xc49c8 cmp r4, #0 */
/* @0xc49cc mov r1, #0 */
/* @0xc49d0 addlt r3, r6, #2 */
/* @0xc49d4 movlt r2, #45 */
/* @0xc49d8 strblt r2, [r6, #0x1] */
/* @0xc49dc sub r2, r3, #1 */
/* @0xc49e0 strb r1, [r3] */
/* @0xc49e4 cmp r7, r2 */
/* @0xc49e8 bhs 0xc4a08 <_Z5_itoaiPci+0xa4> */
/* @0xc49ec mov r3, r7 */
/* @0xc49f0 ldrb r1, [r2] */
/* @0xc49f4 ldrb r0, [r3] */
/* @0xc49f8 strb r0, [r2], #-1 */
/* @0xc49fc strb r1, [r3], #1 */
/* @0xc4a00 cmp r2, r3 */
/* @0xc4a04 bhi 0xc49f0 <_Z5_itoaiPci+0x8c> */
/* @0xc4a08 mov r0, r7 */
/* @0xc4a0c pop {r4, r5, r6, r7, r8, pc} */
/* @0xc4a10 eoreq r12, r6, r12, lsr #3 */

/* ── FUNC 0xc4a14 · strlwr(char*) · size=96 · insn=24 */
/* @0xc4a14 ldrb r3, [r0] */
/* @0xc4a18 push {r4, r5} */
/* @0xc4a1c cmp r3, #0 */
/* @0xc4a20 beq 0xc4a64 <_Z6strlwrPc+0x50> */
/* @0xc4a24 ldr r5, [pc, #0x40] */
/* @0xc4a28 add r2, r0, #1 */
/* @0xc4a2c ldr r5, [pc, r5] */
/* @0xc4a30 ldr r12, [r5] */
/* @0xc4a34 add r3, r3, #1 */
/* @0xc4a38 ldr r1, [pc, #0x30] */
/* @0xc4a3c lsl r4, r3, #1 */
/* @0xc4a40 ldrb r3, [r12, r3] */
/* @0xc4a44 tst r3, #1 */
/* @0xc4a48 ldrne r1, [pc, r1] */
/* @0xc4a4c ldrne r3, [r1] */
/* @0xc4a50 ldrhne r3, [r3, r4] */
/* @0xc4a54 strbne r3, [r2, #-0x1] */
/* @0xc4a58 ldrb r3, [r2], #1 */
/* @0xc4a5c cmp r3, #0 */
/* @0xc4a60 bne 0xc4a30 <_Z6strlwrPc+0x1c> */
/* @0xc4a64 pop {r4, r5} */
/* @0xc4a68 bx lr */
/* @0xc4a6c eorseq r8, r2, r4, asr pc */
/* @0xc4a70 eorseq r8, r2, r12, lsr pc */

/* ── FUNC 0xc4a74 · strupr(char*) · size=96 · insn=24 */
/* @0xc4a74 ldrb r3, [r0] */
/* @0xc4a78 push {r4, r5} */
/* @0xc4a7c cmp r3, #0 */
/* @0xc4a80 beq 0xc4ac4 <_Z6struprPc+0x50> */
/* @0xc4a84 ldr r5, [pc, #0x40] */
/* @0xc4a88 add r2, r0, #1 */
/* @0xc4a8c ldr r5, [pc, r5] */
/* @0xc4a90 ldr r12, [r5] */
/* @0xc4a94 add r3, r3, #1 */
/* @0xc4a98 ldr r1, [pc, #0x30] */
/* @0xc4a9c lsl r4, r3, #1 */
/* @0xc4aa0 ldrb r3, [r12, r3] */
/* @0xc4aa4 tst r3, #2 */
/* @0xc4aa8 ldrne r1, [pc, r1] */
/* @0xc4aac ldrne r3, [r1] */
/* @0xc4ab0 ldrhne r3, [r3, r4] */
/* @0xc4ab4 strbne r3, [r2, #-0x1] */
/* @0xc4ab8 ldrb r3, [r2], #1 */
/* @0xc4abc cmp r3, #0 */
/* @0xc4ac0 bne 0xc4a90 <_Z6struprPc+0x1c> */
/* @0xc4ac4 pop {r4, r5} */
/* @0xc4ac8 bx lr */
/* @0xc4acc ldrshteq r8, [r2], -r4 */
/* @0xc4ad0 eorseq r8, r2, r0, ror #29 */

/* ── FUNC 0xc4ad4 · _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...) · size=56 · insn=14 */
/* @0xc4ad4 push {r2, r3} */
/* @0xc4ad8 str lr, [sp, #-0x4]! */
/* @0xc4adc sub sp, sp, #12 */
/* @0xc4ae0 ldr lr, [r0] */
/* @0xc4ae4 add r12, sp, #20 */
/* @0xc4ae8 ldr r2, [sp, #0x10] */
/* @0xc4aec mov r3, r12 */
/* @0xc4af0 str r12, [sp, #0x4] */
/* @0xc4af4 ldr r12, [lr, #0x238] */
/* @0xc4af8 blx r12 */
/* @0xc4afc add sp, sp, #12 */
/* @0xc4b00 ldr lr, [sp], #4 */
/* @0xc4b04 add sp, sp, #8 */
/* @0xc4b08 bx lr */

/* ── FUNC 0xc4b0c · ShowMessage(char const*) · size=80 · insn=20 */
/* @0xc4b0c push {r4, lr} */
/* @0xc4b10 mov r4, r0 */
/* @0xc4b14 bl 0x290274 <getJNIEnv> */
/* @0xc4b18 mov r1, r4 */
/* @0xc4b1c ldr r3, [r0] */
/* @0xc4b20 ldr r3, [r3, #0x29c] */
/* @0xc4b24 blx r3 */
/* @0xc4b28 mov r4, r0 */
/* @0xc4b2c bl 0x290274 <getJNIEnv> */
/* @0xc4b30 ldr r1, [pc, #0x1c] */
/* @0xc4b34 mov r3, r4 */
/* @0xc4b38 ldr r2, [pc, #0x18] */
/* @0xc4b3c ldr r1, [pc, r1] */
/* @0xc4b40 ldr r2, [pc, r2] */
/* @0xc4b44 ldr r1, [r1] */
/* @0xc4b48 ldr r2, [r2] */
/* @0xc4b4c pop {r4, lr} */
/* @0xc4b50 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0xc4b54 eorseq r8, r2, r8, ror #28 */
/* @0xc4b58 eorseq r8, r2, r8, ror #28 */

/* ── FUNC 0xc4b5c · Buffer_Fast::Read(eBuffer_Type, RValue*) · size=112 · insn=28 */
/* @0xc4b5c cmp r1, #1 */
/* @0xc4b60 mov r3, #0 */
/* @0xc4b64 push {r4, r5} */
/* @0xc4b68 str r3, [r2, #0xc] */
/* @0xc4b6c str r3, [r2] */
/* @0xc4b70 str r3, [r2, #0x4] */
/* @0xc4b74 bne 0xc4bbc <_ZN11Buffer_Fast4ReadE12eBuffer_TypeP6RValue+0x60> */
/* @0xc4b78 ldr r1, [r0, #0x1c] */
/* @0xc4b7c ldr r12, [r0, #0x10] */
/* @0xc4b80 cmp r1, r12 */
/* @0xc4b84 bge 0xc4bc4 <_ZN11Buffer_Fast4ReadE12eBuffer_TypeP6RValue+0x68> */
/* @0xc4b88 ldr r12, [r0, #0xc] */
/* @0xc4b8c add r4, r1, #1 */
/* @0xc4b90 str r4, [r0, #0x1c] */
/* @0xc4b94 mov r0, r3 */
/* @0xc4b98 ldrb r4, [r12, r1] */
/* @0xc4b9c vmov s15, r4 */
/* @0xc4ba0 vcvt.f64.u32 d7, s15 */
/* @0xc4ba4 vmov r4, r5, d7 */
/* @0xc4ba8 vmov r1, s14 */
/* @0xc4bac mov r3, r5 */
/* @0xc4bb0 stm r2, {r1, r3} */
/* @0xc4bb4 pop {r4, r5} */
/* @0xc4bb8 bx lr */
/* @0xc4bbc mvn r0, #3 */
/* @0xc4bc0 b 0xc4bb4 <_ZN11Buffer_Fast4ReadE12eBuffer_TypeP6RValue+0x58> */
/* @0xc4bc4 mvn r0, #1 */
/* @0xc4bc8 b 0xc4bb4 <_ZN11Buffer_Fast4ReadE12eBuffer_TypeP6RValue+0x58> */

/* ── FUNC 0xc4bcc · Buffer_Fast::~Buffer_Fast() · size=40 · insn=10 */
/* @0xc4bcc ldr r3, [pc, #0x1c] */
/* @0xc4bd0 push {r4, lr} */
/* @0xc4bd4 ldr r3, [pc, r3] */
/* @0xc4bd8 mov r4, r0 */
/* @0xc4bdc add r3, r3, #8 */
/* @0xc4be0 str r3, [r0] */
/* @0xc4be4 bl 0xcb818 <_ZN7IBufferD2Ev> */
/* @0xc4be8 mov r0, r4 */
/* @0xc4bec pop {r4, pc} */
/* @0xc4bf0 ldrsbteq r8, [r2], -r8 */

/* ── FUNC 0xc4bcc · Buffer_Fast::~Buffer_Fast() · alias of the symbol above · insn=0 */

/* ── FUNC 0xc4bf4 · Buffer_Fast::~Buffer_Fast() · size=48 · insn=12 */
/* @0xc4bf4 ldr r3, [pc, #0x24] */
/* @0xc4bf8 push {r4, lr} */
/* @0xc4bfc ldr r3, [pc, r3] */
/* @0xc4c00 mov r4, r0 */
/* @0xc4c04 add r3, r3, #8 */
/* @0xc4c08 str r3, [r0] */
/* @0xc4c0c bl 0xcb818 <_ZN7IBufferD2Ev> */
/* @0xc4c10 mov r0, r4 */
/* @0xc4c14 bl 0x27d1d0 <_ZdlPv> */
/* @0xc4c18 mov r0, r4 */
/* @0xc4c1c pop {r4, pc} */
/* @0xc4c20 ldrhteq r8, [r2], -r0 */

/* ── FUNC 0xc4c24 · Buffer_Fast::Write(eBuffer_Type, RValue*) · size=88 · insn=22 */
/* @0xc4c24 cmp r1, #1 */
/* @0xc4c28 push {r3, r4, r5, lr} */
/* @0xc4c2c mov r3, r0 */
/* @0xc4c30 bne 0xc4c6c <_ZN11Buffer_Fast5WriteE12eBuffer_TypeP6RValue+0x48> */
/* @0xc4c34 ldr r4, [r0, #0x1c] */
/* @0xc4c38 ldr r1, [r0, #0x10] */
/* @0xc4c3c cmp r4, r1 */
/* @0xc4c40 bge 0xc4c74 <_ZN11Buffer_Fast5WriteE12eBuffer_TypeP6RValue+0x50> */
/* @0xc4c44 mov r0, r2 */
/* @0xc4c48 mov r1, #0 */
/* @0xc4c4c add r2, r4, #1 */
/* @0xc4c50 str r2, [r3, #0x1c] */
/* @0xc4c54 ldr r5, [r3, #0xc] */
/* @0xc4c58 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc4c5c mov r3, #0 */
/* @0xc4c60 strb r0, [r5, r4] */
/* @0xc4c64 mov r0, r3 */
/* @0xc4c68 pop {r3, r4, r5, pc} */
/* @0xc4c6c mvn r3, #3 */
/* @0xc4c70 b 0xc4c64 <_ZN11Buffer_Fast5WriteE12eBuffer_TypeP6RValue+0x40> */
/* @0xc4c74 mvn r3, #1 */
/* @0xc4c78 b 0xc4c64 <_ZN11Buffer_Fast5WriteE12eBuffer_TypeP6RValue+0x40> */

/* ── FUNC 0xc4c7c · Buffer_Fast::Peek(int, eBuffer_Type, RValue*) · size=76 · insn=19 */
/* @0xc4c7c cmp r2, #1 */
/* @0xc4c80 mov r12, r3 */
/* @0xc4c84 mov r3, #0 */
/* @0xc4c88 str r3, [r12, #0xc] */
/* @0xc4c8c str r3, [r12] */
/* @0xc4c90 str r3, [r12, #0x4] */
/* @0xc4c94 bxne lr */
/* @0xc4c98 cmp r1, r3 */
/* @0xc4c9c bxlt lr */
/* @0xc4ca0 ldr r3, [r0, #0x10] */
/* @0xc4ca4 cmp r1, r3 */
/* @0xc4ca8 bxge lr */
/* @0xc4cac ldr r3, [r0, #0xc] */
/* @0xc4cb0 ldrb r2, [r3, r1] */
/* @0xc4cb4 vmov s15, r2 */
/* @0xc4cb8 vcvt.f64.u32 d7, s15 */
/* @0xc4cbc vmov r2, r3, d7 */
/* @0xc4cc0 stm r12, {r2, r3} */
/* @0xc4cc4 bx lr */

/* ── FUNC 0xc4cc8 · Buffer_Fast::Poke(int, eBuffer_Type, RValue*) · size=64 · insn=16 */
/* @0xc4cc8 cmp r2, #1 */
/* @0xc4ccc mov r2, r0 */
/* @0xc4cd0 push {r3, r4, r5, lr} */
/* @0xc4cd4 mov r4, r1 */
/* @0xc4cd8 popne {r3, r4, r5, pc} */
/* @0xc4cdc cmp r1, #0 */
/* @0xc4ce0 poplt {r3, r4, r5, pc} */
/* @0xc4ce4 ldr r1, [r0, #0x10] */
/* @0xc4ce8 cmp r4, r1 */
/* @0xc4cec popge {r3, r4, r5, pc} */
/* @0xc4cf0 mov r0, r3 */
/* @0xc4cf4 mov r1, #0 */
/* @0xc4cf8 ldr r5, [r2, #0xc] */
/* @0xc4cfc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc4d00 strb r0, [r5, r4] */
/* @0xc4d04 pop {r3, r4, r5, pc} */

/* ── FUNC 0xc4d08 · Buffer_Standard::~Buffer_Standard() · size=40 · insn=10 */
/* @0xc4d08 ldr r3, [pc, #0x1c] */
/* @0xc4d0c push {r4, lr} */
/* @0xc4d10 ldr r3, [pc, r3] */
/* @0xc4d14 mov r4, r0 */
/* @0xc4d18 add r3, r3, #8 */
/* @0xc4d1c str r3, [r0] */
/* @0xc4d20 bl 0xcb818 <_ZN7IBufferD2Ev> */
/* @0xc4d24 mov r0, r4 */
/* @0xc4d28 pop {r4, pc} */
/* @0xc4d2c eorseq r8, r2, r0, lsr #25 */

/* ── FUNC 0xc4d08 · Buffer_Standard::~Buffer_Standard() · alias of the symbol above · insn=0 */

/* ── FUNC 0xc4d30 · Buffer_Standard::~Buffer_Standard() · size=48 · insn=12 */
/* @0xc4d30 ldr r3, [pc, #0x24] */
/* @0xc4d34 push {r4, lr} */
/* @0xc4d38 ldr r3, [pc, r3] */
/* @0xc4d3c mov r4, r0 */
/* @0xc4d40 add r3, r3, #8 */
/* @0xc4d44 str r3, [r0] */
/* @0xc4d48 bl 0xcb818 <_ZN7IBufferD2Ev> */
/* @0xc4d4c mov r0, r4 */
/* @0xc4d50 bl 0x27d1d0 <_ZdlPv> */
/* @0xc4d54 mov r0, r4 */
/* @0xc4d58 pop {r4, pc} */
/* @0xc4d5c eorseq r8, r2, r8, ror r12 */

/* ── FUNC 0xc4d60 · ASYNC_SAVE_LOAD_REQ_CONTEXT::~ASYNC_SAVE_LOAD_REQ_CONTEXT() · size=108 · insn=27 */
/* @0xc4d60 push {r4, r5, r6, lr} */
/* @0xc4d64 mov r6, r0 */
/* @0xc4d68 ldr r4, [r0, #0x44] */
/* @0xc4d6c ldr r3, [pc, #0x54] */
/* @0xc4d70 cmp r4, #0 */
/* @0xc4d74 ldr r3, [pc, r3] */
/* @0xc4d78 add r3, r3, #8 */
/* @0xc4d7c str r3, [r0] */
/* @0xc4d80 beq 0xc4da4 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXTD2Ev+0x44> */
/* @0xc4d84 ldr r5, [r4] */
/* @0xc4d88 ldr r0, [r4, #0x8] */
/* @0xc4d8c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc4d90 ldr r0, [r4, #0xc] */
/* @0xc4d94 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc4d98 cmp r5, #0 */
/* @0xc4d9c mov r4, r5 */
/* @0xc4da0 bne 0xc4d84 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXTD2Ev+0x24> */
/* @0xc4da4 ldr r0, [r6, #0x48] */
/* @0xc4da8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc4dac mov r3, #0 */
/* @0xc4db0 mov r0, r6 */
/* @0xc4db4 str r3, [r6, #0x44] */
/* @0xc4db8 str r3, [r6, #0x48] */
/* @0xc4dbc bl 0x18d724 <_ZN16HTTP_REQ_CONTEXTD2Ev> */
/* @0xc4dc0 mov r0, r6 */
/* @0xc4dc4 pop {r4, r5, r6, pc} */
/* @0xc4dc8 eorseq r8, r2, r0, asr #24 */

/* ── FUNC 0xc4d60 · ASYNC_SAVE_LOAD_REQ_CONTEXT::~ASYNC_SAVE_LOAD_REQ_CONTEXT() · alias of the symbol above · insn=0 */

/* ── FUNC 0xc4dcc · AsyncSaveLoadCreateUpdateMap(HTTP_REQ_CONTEXT*, void*, int*) · size=136 · insn=34 */
/* @0xc4dcc vldr s14, [r0, #84] */
/* @0xc4dd0 vcvt.f64.s32 d7, s14 */
/* @0xc4dd4 push {r4, lr} */
/* @0xc4dd8 vldr s12, [r0, #80] */
/* @0xc4ddc mov r4, r2 */
/* @0xc4de0 ldr r2, [r0, #0x24] */
/* @0xc4de4 sub sp, sp, #40 */
/* @0xc4de8 ldr r1, [pc, #0x58] */
/* @0xc4dec mov r3, #0 */
/* @0xc4df0 ldr r12, [pc, #0x54] */
/* @0xc4df4 mov r0, #3 */
/* @0xc4df8 add r1, pc, r1 */
/* @0xc4dfc str r1, [sp, #0x4] */
/* @0xc4e00 vstr d7, [sp, #24] */
/* @0xc4e04 vmov s15, r2 */
/* @0xc4e08 vcvt.f64.s32 d6, s12 */
/* @0xc4e0c ldr r1, [pc, #0x3c] */
/* @0xc4e10 add r12, pc, r12 */
/* @0xc4e14 str r3, [sp] */
/* @0xc4e18 str r3, [sp, #0x10] */
/* @0xc4e1c add r1, pc, r1 */
/* @0xc4e20 str r3, [sp, #0x20] */
/* @0xc4e24 str r12, [sp, #0x14] */
/* @0xc4e28 vcvt.f64.s32 d7, s15 */
/* @0xc4e2c vstr d6, [sp, #8] */
/* @0xc4e30 vmov r2, r3, d7 */
/* @0xc4e34 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0xc4e38 str r0, [r4] */
/* @0xc4e3c mov r0, #72 */
/* @0xc4e40 add sp, sp, #40 */
/* @0xc4e44 pop {r4, pc} */
/* @0xc4e48 eoreq r11, r6, r8, asr r12 */
/* @0xc4e4c eoreq r11, r6, r4, ror sp */
/* @0xc4e50 eoreq r11, r6, r4, lsr #24 */

/* ── FUNC 0xc4e54 · ASYNC_SAVE_LOAD_REQ_CONTEXT::Process(HTTP_REQ_CONTEXT*) · size=604 · insn=151 */
/* @0xc4e54 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc4e58 sub sp, sp, #3120 */
/* @0xc4e5c ldr r10, [pc, #0x240] */
/* @0xc4e60 sub sp, sp, #4 */
/* @0xc4e64 ldr r3, [r0, #0xc] */
/* @0xc4e68 mov r9, r0 */
/* @0xc4e6c ldr r10, [pc, r10] */
/* @0xc4e70 cmp r3, #7 */
/* @0xc4e74 ldr r3, [r10] */
/* @0xc4e78 str r3, [sp, #0xc2c] */
/* @0xc4e7c beq 0xc4fb8 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x164> */
/* @0xc4e80 ldrb r7, [r0, #0x4c] */
/* @0xc4e84 cmp r7, #0 */
/* @0xc4e88 bne 0xc4fd4 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x180> */
/* @0xc4e8c add r6, sp, #44 */
/* @0xc4e90 ldr r1, [r0, #0x48] */
/* @0xc4e94 mov r0, r6 */
/* @0xc4e98 bl 0xb65a4 <strcpy@plt> */
/* @0xc4e9c mov r0, r6 */
/* @0xc4ea0 bl 0xb6538 <strlen@plt> */
/* @0xc4ea4 ldr r4, [r9, #0x44] */
/* @0xc4ea8 cmp r4, #0 */
/* @0xc4eac beq 0xc4fb0 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x15c> */
/* @0xc4eb0 ldr r2, [pc, #0x1f0] */
/* @0xc4eb4 add r5, sp, #1072 */
/* @0xc4eb8 add r12, sp, #40 */
/* @0xc4ebc sub r5, r5, #4 */
/* @0xc4ec0 add r2, pc, r2 */
/* @0xc4ec4 add r3, r0, #1 */
/* @0xc4ec8 add r3, r5, r3 */
/* @0xc4ecc str r9, [sp, #0x1c] */
/* @0xc4ed0 str r2, [sp, #0x20] */
/* @0xc4ed4 add r8, r5, r0 */
/* @0xc4ed8 str r3, [sp, #0x18] */
/* @0xc4edc mov r9, r12 */
/* @0xc4ee0 str r10, [sp, #0x24] */
/* @0xc4ee4 mov r11, r2 */
/* @0xc4ee8 b 0xc4f40 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0xec> */
/* @0xc4eec bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0xc4ef0 subs r10, r0, #0 */
/* @0xc4ef4 beq 0xc5070 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x21c> */
/* @0xc4ef8 ldr lr, [r4, #0x10] */
/* @0xc4efc mov r12, #1 */
/* @0xc4f00 ldr r0, [r4, #0x4] */
/* @0xc4f04 mov r1, r10 */
/* @0xc4f08 mov r3, #0 */
/* @0xc4f0c ldr r2, [sp, #0x28] */
/* @0xc4f10 str lr, [sp] */
/* @0xc4f14 ldr lr, [r4, #0x14] */
/* @0xc4f18 str r12, [sp, #0x8] */
/* @0xc4f1c str r7, [sp, #0xc] */
/* @0xc4f20 str lr, [sp, #0x4] */
/* @0xc4f24 str r7, [sp, #0x10] */
/* @0xc4f28 bl 0xccabc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb> */
/* @0xc4f2c mov r0, r10 */
/* @0xc4f30 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc4f34 ldr r4, [r4] */
/* @0xc4f38 cmp r4, #0 */
/* @0xc4f3c beq 0xc4fa8 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x154> */
/* @0xc4f40 mov r1, r6 */
/* @0xc4f44 mov r0, r5 */
/* @0xc4f48 bl 0xb65a4 <strcpy@plt> */
/* @0xc4f4c mov r0, r8 */
/* @0xc4f50 bl 0xb6538 <strlen@plt> */
/* @0xc4f54 ldrh r3, [r11] */
/* @0xc4f58 strh r3, [r8, r0] */
/* @0xc4f5c ldr r0, [sp, #0x18] */
/* @0xc4f60 ldr r1, [r4, #0x8] */
/* @0xc4f64 bl 0xb6628 <strcat@plt> */
/* @0xc4f68 mov r0, r5 */
/* @0xc4f6c str r7, [sp, #0x28] */
/* @0xc4f70 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0xc4f74 mov r1, r9 */
/* @0xc4f78 cmp r0, #0 */
/* @0xc4f7c mov r0, r5 */
/* @0xc4f80 beq 0xc4eec <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x98> */
/* @0xc4f84 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi> */
/* @0xc4f88 mov r10, r0 */
/* @0xc4f8c cmp r10, #0 */
/* @0xc4f90 bne 0xc4ef8 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0xa4> */
/* @0xc4f94 ldr r4, [r4] */
/* @0xc4f98 ldr r12, [sp, #0x1c] */
/* @0xc4f9c cmp r4, #0 */
/* @0xc4fa0 str r10, [r12, #0x50] */
/* @0xc4fa4 bne 0xc4f40 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0xec> */
/* @0xc4fa8 ldr r9, [sp, #0x1c] */
/* @0xc4fac ldr r10, [sp, #0x24] */
/* @0xc4fb0 mov r3, #7 */
/* @0xc4fb4 str r3, [r9, #0xc] */
/* @0xc4fb8 ldr r2, [sp, #0xc2c] */
/* @0xc4fbc ldr r3, [r10] */
/* @0xc4fc0 cmp r2, r3 */
/* @0xc4fc4 bne 0xc50a0 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x24c> */
/* @0xc4fc8 add sp, sp, #3120 */
/* @0xc4fcc add sp, sp, #4 */
/* @0xc4fd0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xc4fd4 add r6, sp, #44 */
/* @0xc4fd8 ldr r2, [r0, #0x48] */
/* @0xc4fdc mov r1, #1024 */
/* @0xc4fe0 mov r0, r6 */
/* @0xc4fe4 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0xc4fe8 mov r0, r6 */
/* @0xc4fec bl 0xb6538 <strlen@plt> */
/* @0xc4ff0 ldr r4, [r9, #0x44] */
/* @0xc4ff4 cmp r4, #0 */
/* @0xc4ff8 beq 0xc4fb0 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x15c> */
/* @0xc4ffc add r5, sp, #1072 */
/* @0xc5000 ldr r11, [pc, #0xa4] */
/* @0xc5004 sub r5, r5, #4 */
/* @0xc5008 add r8, r0, #1 */
/* @0xc500c add r11, pc, r11 */
/* @0xc5010 add r7, r5, r0 */
/* @0xc5014 add r8, r5, r8 */
/* @0xc5018 mov r1, r6 */
/* @0xc501c mov r0, r5 */
/* @0xc5020 bl 0xb65a4 <strcpy@plt> */
/* @0xc5024 mov r0, r7 */
/* @0xc5028 bl 0xb6538 <strlen@plt> */
/* @0xc502c ldrh r3, [r11] */
/* @0xc5030 strh r3, [r7, r0] */
/* @0xc5034 mov r0, r8 */
/* @0xc5038 ldr r1, [r4, #0x8] */
/* @0xc503c bl 0xb6628 <strcat@plt> */
/* @0xc5040 ldr r1, [r4, #0xc] */
/* @0xc5044 ldr r2, [r4, #0x10] */
/* @0xc5048 mov r0, r5 */
/* @0xc504c bl 0x18fa3c <_ZN8LoadSave9WriteFileEPKcS1_i> */
/* @0xc5050 ldr r4, [r4] */
/* @0xc5054 cmp r0, #0 */
/* @0xc5058 streq r0, [r9, #0x50] */
/* @0xc505c cmp r4, #0 */
/* @0xc5060 bne 0xc5018 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x1c4> */
/* @0xc5064 mov r3, #7 */
/* @0xc5068 str r3, [r9, #0xc] */
/* @0xc506c b 0xc4fb8 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x164> */
/* @0xc5070 ldr r1, [r4, #0x8] */
/* @0xc5074 mov r0, r5 */
/* @0xc5078 bl 0xb65a4 <strcpy@plt> */
/* @0xc507c mov r0, r5 */
/* @0xc5080 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0xc5084 mov r1, r9 */
/* @0xc5088 cmp r0, #0 */
/* @0xc508c mov r0, r5 */
/* @0xc5090 bne 0xc4f84 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x130> */
/* @0xc5094 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0xc5098 mov r10, r0 */
/* @0xc509c b 0xc4f8c <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x138> */
/* @0xc50a0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xc50a4 eorseq r8, r2, r4, ror #21 */
/* @0xc50a8 eoreq r11, r6, r12, asr #25 */
/* @0xc50ac eoreq r11, r6, r0, lsl #23 */

/* ── FUNC 0xc50b0 · F_BUFFER_SizeOf(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0xc50b0 push {r4, lr} */
/* @0xc50b4 mov r3, #0 */
/* @0xc50b8 mov r1, r3 */
/* @0xc50bc str r3, [r0, #0xc] */
/* @0xc50c0 mov r4, r0 */
/* @0xc50c4 ldr r0, [sp, #0x8] */
/* @0xc50c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc50cc bl 0xcd100 <_ZN7IBuffer6SizeOfE12eBuffer_Type> */
/* @0xc50d0 vmov s15, r0 */
/* @0xc50d4 vcvt.f64.s32 d7, s15 */
/* @0xc50d8 vmov r0, r1, d7 */
/* @0xc50dc vmov r2, s14 */
/* @0xc50e0 mov r3, r1 */
/* @0xc50e4 stm r4, {r2, r3} */
/* @0xc50e8 pop {r4, pc} */

/* ── FUNC 0xc50ec · F_BUFFER_Get_Type(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0xc50ec push {r4, lr} */
/* @0xc50f0 mov r1, #0 */
/* @0xc50f4 ldr r12, [sp, #0x8] */
/* @0xc50f8 mov r3, r1 */
/* @0xc50fc str r1, [r0, #0xc] */
/* @0xc5100 movt r3, #0xbff0 */
/* @0xc5104 mov r4, r0 */
/* @0xc5108 str r1, [r0] */
/* @0xc510c ldr r2, [r12, #0xc] */
/* @0xc5110 str r3, [r0, #0x4] */
/* @0xc5114 cmp r2, #13 */
/* @0xc5118 pophi {r4, pc} */
/* @0xc511c mov r0, #1 */
/* @0xc5120 movw r3, #0x2483 */
/* @0xc5124 lsl r2, r0, r2 */
/* @0xc5128 and r3, r2, r3 */
/* @0xc512c cmp r3, r1 */
/* @0xc5130 popeq {r4, pc} */
/* @0xc5134 mov r0, r12 */
/* @0xc5138 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc513c cmp r0, #0 */
/* @0xc5140 poplt {r4, pc} */
/* @0xc5144 ldr r3, [pc, #0x30] */
/* @0xc5148 add r3, pc, r3 */
/* @0xc514c ldr r2, [r3] */
/* @0xc5150 cmp r0, r2 */
/* @0xc5154 popge {r4, pc} */
/* @0xc5158 ldr r3, [r3, #0x4] */
/* @0xc515c ldr r3, [r3, r0, lsl #2] */
/* @0xc5160 cmp r3, #0 */
/* @0xc5164 ldrne r2, [r3, #0x18] */
/* @0xc5168 vmovne s15, r2 */
/* @0xc516c vcvtne.f64.u32 d7, s15 */
/* @0xc5170 vmovne r2, r3, d7 */
/* @0xc5174 stmne r4, {r2, r3} */
/* @0xc5178 pop {r4, pc} */
/* @0xc517c eorseq r4, r11, r12, asr #31 */

/* ── FUNC 0xc5180 · F_BUFFER_Get_Alignment(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0xc5180 push {r4, lr} */
/* @0xc5184 mov r1, #0 */
/* @0xc5188 ldr r12, [sp, #0x8] */
/* @0xc518c mov r3, r1 */
/* @0xc5190 str r1, [r0, #0xc] */
/* @0xc5194 movt r3, #0xbff0 */
/* @0xc5198 mov r4, r0 */
/* @0xc519c str r1, [r0] */
/* @0xc51a0 ldr r2, [r12, #0xc] */
/* @0xc51a4 str r3, [r0, #0x4] */
/* @0xc51a8 cmp r2, #13 */
/* @0xc51ac pophi {r4, pc} */
/* @0xc51b0 mov r0, #1 */
/* @0xc51b4 movw r3, #0x2483 */
/* @0xc51b8 lsl r2, r0, r2 */
/* @0xc51bc and r3, r2, r3 */
/* @0xc51c0 cmp r3, r1 */
/* @0xc51c4 popeq {r4, pc} */
/* @0xc51c8 mov r0, r12 */
/* @0xc51cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc51d0 cmp r0, #0 */
/* @0xc51d4 poplt {r4, pc} */
/* @0xc51d8 ldr r3, [pc, #0x30] */
/* @0xc51dc add r3, pc, r3 */
/* @0xc51e0 ldr r2, [r3] */
/* @0xc51e4 cmp r0, r2 */
/* @0xc51e8 popge {r4, pc} */
/* @0xc51ec ldr r3, [r3, #0x4] */
/* @0xc51f0 ldr r3, [r3, r0, lsl #2] */
/* @0xc51f4 cmp r3, #0 */
/* @0xc51f8 ldrne r2, [r3, #0x14] */
/* @0xc51fc vmovne s15, r2 */
/* @0xc5200 vcvtne.f64.s32 d7, s15 */
/* @0xc5204 vmovne r2, r3, d7 */
/* @0xc5208 stmne r4, {r2, r3} */
/* @0xc520c pop {r4, pc} */
/* @0xc5210 eorseq r4, r11, r8, lsr pc */

/* ── FUNC 0xc5214 · F_BUFFER_Exists(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0xc5214 push {r3, r4, r5, lr} */
/* @0xc5218 mov r3, #13 */
/* @0xc521c ldr r1, [sp, #0x10] */
/* @0xc5220 mov r5, #0 */
/* @0xc5224 str r3, [r0, #0xc] */
/* @0xc5228 mov r4, r0 */
/* @0xc522c str r5, [r0] */
/* @0xc5230 ldr r3, [r1, #0xc] */
/* @0xc5234 str r5, [r0, #0x4] */
/* @0xc5238 cmp r3, #13 */
/* @0xc523c pophi {r3, r4, r5, pc} */
/* @0xc5240 mov r0, #1 */
/* @0xc5244 movw r2, #0x2483 */
/* @0xc5248 lsl r3, r0, r3 */
/* @0xc524c and r2, r3, r2 */
/* @0xc5250 cmp r2, r5 */
/* @0xc5254 popeq {r3, r4, r5, pc} */
/* @0xc5258 mov r0, r1 */
/* @0xc525c mov r1, r5 */
/* @0xc5260 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5264 cmp r0, #0 */
/* @0xc5268 poplt {r3, r4, r5, pc} */
/* @0xc526c ldr r3, [pc, #0x2c] */
/* @0xc5270 add r3, pc, r3 */
/* @0xc5274 ldr r2, [r3] */
/* @0xc5278 cmp r0, r2 */
/* @0xc527c popge {r3, r4, r5, pc} */
/* @0xc5280 ldr r3, [r3, #0x4] */
/* @0xc5284 ldr r3, [r3, r0, lsl #2] */
/* @0xc5288 cmp r3, r5 */
/* @0xc528c strne r5, [r4] */
/* @0xc5290 movne r3, r5 */
/* @0xc5294 movtne r3, #0x3ff0 */
/* @0xc5298 strne r3, [r4, #0x4] */
/* @0xc529c pop {r3, r4, r5, pc} */
/* @0xc52a0 eorseq r4, r11, r4, lsr #29 */

/* ── FUNC 0xc52a4 · F_BUFFER_Delete(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0xc52a4 push {r3, r4, r5, lr} */
/* @0xc52a8 mov r1, #0 */
/* @0xc52ac ldr r0, [sp, #0x10] */
/* @0xc52b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc52b4 subs r4, r0, #0 */
/* @0xc52b8 poplt {r3, r4, r5, pc} */
/* @0xc52bc ldr r5, [pc, #0x58] */
/* @0xc52c0 add r5, pc, r5 */
/* @0xc52c4 ldr r3, [r5] */
/* @0xc52c8 cmp r4, r3 */
/* @0xc52cc popge {r3, r4, r5, pc} */
/* @0xc52d0 ldr r3, [r5, #0x4] */
/* @0xc52d4 ldr r0, [r3, r4, lsl #2] */
/* @0xc52d8 cmp r0, #0 */
/* @0xc52dc popeq {r3, r4, r5, pc} */
/* @0xc52e0 ldr r3, [r0, #0x28] */
/* @0xc52e4 cmp r3, #0 */
/* @0xc52e8 bgt 0xc5308 <_Z15F_BUFFER_DeleteR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0xc52ec ldr r3, [r0] */
/* @0xc52f0 ldr r3, [r3, #0x4] */
/* @0xc52f4 blx r3 */
/* @0xc52f8 ldr r3, [r5, #0x4] */
/* @0xc52fc mov r2, #0 */
/* @0xc5300 str r2, [r3, r4, lsl #2] */
/* @0xc5304 pop {r3, r4, r5, pc} */
/* @0xc5308 ldr r0, [pc, #0x10] */
/* @0xc530c mov r1, #0 */
/* @0xc5310 pop {r3, r4, r5, lr} */
/* @0xc5314 add r0, pc, r0 */
/* @0xc5318 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc531c eorseq r4, r11, r4, asr lr */
/* @0xc5320 eoreq r11, r6, r12, ror r8 */

/* ── FUNC 0xc5324 · F_BUFFER_Write(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0xc5324 push {r3, r4, r5, r6, r7, lr} */
/* @0xc5328 mov r1, #0 */
/* @0xc532c ldr r6, [sp, #0x18] */
/* @0xc5330 mov r3, r1 */
/* @0xc5334 str r1, [r0, #0xc] */
/* @0xc5338 movt r3, #0xbff0 */
/* @0xc533c mov r4, r0 */
/* @0xc5340 stm r0, {r1, r3} */
/* @0xc5344 mov r0, r6 */
/* @0xc5348 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc534c subs r5, r0, #0 */
/* @0xc5350 blt 0xc53bc <_Z14F_BUFFER_WriteR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0xc5354 ldr r7, [pc, #0x74] */
/* @0xc5358 add r7, pc, r7 */
/* @0xc535c ldr r3, [r7] */
/* @0xc5360 cmp r5, r3 */
/* @0xc5364 bge 0xc53bc <_Z14F_BUFFER_WriteR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0xc5368 ldr r3, [r7, #0x4] */
/* @0xc536c ldr r3, [r3, r5, lsl #2] */
/* @0xc5370 cmp r3, #0 */
/* @0xc5374 beq 0xc53bc <_Z14F_BUFFER_WriteR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0xc5378 mov r1, #1 */
/* @0xc537c mov r0, r6 */
/* @0xc5380 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5384 ldr r3, [r7, #0x4] */
/* @0xc5388 add r2, r6, #32 */
/* @0xc538c mov r1, r0 */
/* @0xc5390 ldr r0, [r3, r5, lsl #2] */
/* @0xc5394 ldr r3, [r0] */
/* @0xc5398 ldr r3, [r3, #0x8] */
/* @0xc539c blx r3 */
/* @0xc53a0 vmov s15, r0 */
/* @0xc53a4 vcvt.f64.s32 d7, s15 */
/* @0xc53a8 vmov r0, r1, d7 */
/* @0xc53ac vmov r2, s14 */
/* @0xc53b0 mov r3, r1 */
/* @0xc53b4 stm r4, {r2, r3} */
/* @0xc53b8 pop {r3, r4, r5, r6, r7, pc} */
/* @0xc53bc ldr r0, [pc, #0x10] */
/* @0xc53c0 mov r1, #0 */
/* @0xc53c4 pop {r3, r4, r5, r6, r7, lr} */
/* @0xc53c8 add r0, pc, r0 */
/* @0xc53cc b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc53d0 ldrhteq r4, [r11], -r12 */
/* @0xc53d4 eoreq r11, r6, r12, ror #15 */

/* ── FUNC 0xc53d8 · F_BUFFER_Read(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0xc53d8 push {r3, r4, r5, r6, r7, lr} */
/* @0xc53dc mov r6, #0 */
/* @0xc53e0 ldr r4, [sp, #0x18] */
/* @0xc53e4 mov r7, r0 */
/* @0xc53e8 str r6, [r0, #0xc] */
/* @0xc53ec mov r1, r6 */
/* @0xc53f0 str r6, [r0] */
/* @0xc53f4 str r6, [r0, #0x4] */
/* @0xc53f8 mov r0, r4 */
/* @0xc53fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5400 cmp r0, #0 */
/* @0xc5404 blt 0xc548c <_Z13F_BUFFER_ReadR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xc5408 ldr r2, [pc, #0x90] */
/* @0xc540c add r2, pc, r2 */
/* @0xc5410 ldr r1, [r2] */
/* @0xc5414 cmp r0, r1 */
/* @0xc5418 bge 0xc548c <_Z13F_BUFFER_ReadR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xc541c ldr r2, [r2, #0x4] */
/* @0xc5420 ldr r5, [r2, r0, lsl #2] */
/* @0xc5424 cmp r5, r6 */
/* @0xc5428 beq 0xc548c <_Z13F_BUFFER_ReadR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xc542c ldr r3, [r5] */
/* @0xc5430 mov r0, r4 */
/* @0xc5434 mov r1, #1 */
/* @0xc5438 ldr r4, [r3, #0xc] */
/* @0xc543c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5440 mov r2, r7 */
/* @0xc5444 mov r1, r0 */
/* @0xc5448 mov r0, r5 */
/* @0xc544c blx r4 */
/* @0xc5450 cmp r0, #0 */
/* @0xc5454 popge {r3, r4, r5, r6, r7, pc} */
/* @0xc5458 vmov.f64 d7, #-3.000000e+00 */
/* @0xc545c ldm r7, {r4, r5} */
/* @0xc5460 vmov d6, r4, r5 */
/* @0xc5464 vcmp.f64 d6, d7 */
/* @0xc5468 vmrs APSR_nzcv, fpscr */
/* @0xc546c popne {r3, r4, r5, r6, r7, pc} */
/* @0xc5470 ldr r0, [pc, #0x2c] */
/* @0xc5474 mov r1, r6 */
/* @0xc5478 add r0, pc, r0 */
/* @0xc547c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc5480 str r6, [r7] */
/* @0xc5484 str r6, [r7, #0x4] */
/* @0xc5488 pop {r3, r4, r5, r6, r7, pc} */
/* @0xc548c ldr r0, [pc, #0x14] */
/* @0xc5490 mov r1, #0 */
/* @0xc5494 pop {r3, r4, r5, r6, r7, lr} */
/* @0xc5498 add r0, pc, r0 */
/* @0xc549c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc54a0 eorseq r4, r11, r8, lsl #26 */
/* @0xc54a4 eoreq r11, r6, r4, asr r7 */
/* @0xc54a8 eoreq r11, r6, r12, lsl r7 */

/* ── FUNC 0xc54ac · F_BUFFER_Peek(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0xc54ac push {r4, r5, r6, r7, r8, lr} */
/* @0xc54b0 mov r1, #0 */
/* @0xc54b4 ldr r4, [sp, #0x18] */
/* @0xc54b8 mov r6, r0 */
/* @0xc54bc mov r0, r4 */
/* @0xc54c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc54c4 cmp r0, #0 */
/* @0xc54c8 blt 0xc552c <_Z13F_BUFFER_PeekR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xc54cc ldr r1, [pc, #0x6c] */
/* @0xc54d0 add r1, pc, r1 */
/* @0xc54d4 ldr r12, [r1] */
/* @0xc54d8 cmp r0, r12 */
/* @0xc54dc bge 0xc552c <_Z13F_BUFFER_PeekR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xc54e0 ldr r3, [r1, #0x4] */
/* @0xc54e4 ldr r5, [r3, r0, lsl #2] */
/* @0xc54e8 cmp r5, #0 */
/* @0xc54ec beq 0xc552c <_Z13F_BUFFER_PeekR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xc54f0 ldr r3, [r5] */
/* @0xc54f4 mov r0, r4 */
/* @0xc54f8 mov r1, #1 */
/* @0xc54fc ldr r7, [r3, #0x14] */
/* @0xc5500 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5504 mov r1, #2 */
/* @0xc5508 mov r8, r0 */
/* @0xc550c mov r0, r4 */
/* @0xc5510 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5514 mov r1, r8 */
/* @0xc5518 mov r3, r6 */
/* @0xc551c mov r2, r0 */
/* @0xc5520 mov r0, r5 */
/* @0xc5524 blx r7 */
/* @0xc5528 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc552c ldr r0, [pc, #0x10] */
/* @0xc5530 mov r1, #0 */
/* @0xc5534 pop {r4, r5, r6, r7, r8, lr} */
/* @0xc5538 add r0, pc, r0 */
/* @0xc553c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc5540 eorseq r4, r11, r4, asr #24 */
/* @0xc5544 eoreq r11, r6, r12, ror r6 */

/* ── FUNC 0xc5548 · F_BUFFER_Poke(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0xc5548 push {r3, r4, r5, r6, r7, lr} */
/* @0xc554c mov r1, #0 */
/* @0xc5550 ldr r4, [sp, #0x18] */
/* @0xc5554 mov r0, r4 */
/* @0xc5558 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc555c cmp r0, #0 */
/* @0xc5560 blt 0xc55c4 <_Z13F_BUFFER_PokeR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xc5564 ldr r3, [pc, #0x6c] */
/* @0xc5568 add r3, pc, r3 */
/* @0xc556c ldr r2, [r3] */
/* @0xc5570 cmp r0, r2 */
/* @0xc5574 bge 0xc55c4 <_Z13F_BUFFER_PokeR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xc5578 ldr r3, [r3, #0x4] */
/* @0xc557c ldr r5, [r3, r0, lsl #2] */
/* @0xc5580 cmp r5, #0 */
/* @0xc5584 beq 0xc55c4 <_Z13F_BUFFER_PokeR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xc5588 ldr r3, [r5] */
/* @0xc558c mov r0, r4 */
/* @0xc5590 mov r1, #1 */
/* @0xc5594 ldr r6, [r3, #0x18] */
/* @0xc5598 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc559c mov r1, #2 */
/* @0xc55a0 mov r7, r0 */
/* @0xc55a4 mov r0, r4 */
/* @0xc55a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc55ac mov r1, r7 */
/* @0xc55b0 add r3, r4, #48 */
/* @0xc55b4 mov r2, r0 */
/* @0xc55b8 mov r0, r5 */
/* @0xc55bc blx r6 */
/* @0xc55c0 pop {r3, r4, r5, r6, r7, pc} */
/* @0xc55c4 ldr r0, [pc, #0x10] */
/* @0xc55c8 mov r1, #0 */
/* @0xc55cc pop {r3, r4, r5, r6, r7, lr} */
/* @0xc55d0 add r0, pc, r0 */
/* @0xc55d4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc55d8 eorseq r4, r11, r12, lsr #23 */
/* @0xc55dc eoreq r11, r6, r4, ror #11 */

/* ── FUNC 0xc55e0 · F_BUFFER_Seek(RValue&, CInstance*, CInstance*, int, RValue*) · size=192 · insn=48 */
/* @0xc55e0 push {r4, r5, r6, r7, r8, lr} */
/* @0xc55e4 mov r1, #0 */
/* @0xc55e8 ldr r5, [sp, #0x18] */
/* @0xc55ec mov r3, r1 */
/* @0xc55f0 str r1, [r0, #0xc] */
/* @0xc55f4 movt r3, #0xbff0 */
/* @0xc55f8 mov r4, r0 */
/* @0xc55fc stm r0, {r1, r3} */
/* @0xc5600 mov r0, r5 */
/* @0xc5604 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5608 cmp r0, #0 */
/* @0xc560c blt 0xc5684 <_Z13F_BUFFER_SeekR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0xc5610 ldr r3, [pc, #0x80] */
/* @0xc5614 add r3, pc, r3 */
/* @0xc5618 ldr r2, [r3] */
/* @0xc561c cmp r0, r2 */
/* @0xc5620 bge 0xc5684 <_Z13F_BUFFER_SeekR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0xc5624 ldr r3, [r3, #0x4] */
/* @0xc5628 ldr r6, [r3, r0, lsl #2] */
/* @0xc562c cmp r6, #0 */
/* @0xc5630 beq 0xc5684 <_Z13F_BUFFER_SeekR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0xc5634 ldr r3, [r6] */
/* @0xc5638 mov r1, #1 */
/* @0xc563c mov r0, r5 */
/* @0xc5640 ldr r7, [r3, #0x10] */
/* @0xc5644 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5648 mov r1, #2 */
/* @0xc564c mov r8, r0 */
/* @0xc5650 mov r0, r5 */
/* @0xc5654 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5658 mov r1, r8 */
/* @0xc565c mov r2, r0 */
/* @0xc5660 mov r0, r6 */
/* @0xc5664 blx r7 */
/* @0xc5668 vmov s15, r0 */
/* @0xc566c vcvt.f64.s32 d7, s15 */
/* @0xc5670 vmov r0, r1, d7 */
/* @0xc5674 vmov r2, s14 */
/* @0xc5678 mov r3, r1 */
/* @0xc567c stm r4, {r2, r3} */
/* @0xc5680 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc5684 ldr r0, [pc, #0x10] */
/* @0xc5688 mov r1, #0 */
/* @0xc568c pop {r4, r5, r6, r7, r8, lr} */
/* @0xc5690 add r0, pc, r0 */
/* @0xc5694 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc5698 eorseq r4, r11, r0, lsl #22 */
/* @0xc569c eoreq r11, r6, r4, lsr #10 */

/* ── FUNC 0xc56a0 · F_BUFFER_Copy(RValue&, CInstance*, CInstance*, int, RValue*) · size=288 · insn=72 */
/* @0xc56a0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xc56a4 sub sp, sp, #8 */
/* @0xc56a8 mov r4, #0 */
/* @0xc56ac str r4, [r0, #0xc] */
/* @0xc56b0 ldr r6, [sp, #0x28] */
/* @0xc56b4 mov r1, r4 */
/* @0xc56b8 str r4, [r0] */
/* @0xc56bc str r4, [r0, #0x4] */
/* @0xc56c0 mov r0, r6 */
/* @0xc56c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc56c8 subs r7, r0, #0 */
/* @0xc56cc blt 0xc578c <_Z13F_BUFFER_CopyR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0xc56d0 ldr r5, [pc, #0xdc] */
/* @0xc56d4 add r5, pc, r5 */
/* @0xc56d8 ldr r3, [r5] */
/* @0xc56dc cmp r7, r3 */
/* @0xc56e0 bge 0xc578c <_Z13F_BUFFER_CopyR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0xc56e4 ldr r3, [r5, #0x4] */
/* @0xc56e8 ldr r3, [r3, r7, lsl #2] */
/* @0xc56ec cmp r3, #0 */
/* @0xc56f0 beq 0xc578c <_Z13F_BUFFER_CopyR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0xc56f4 mov r0, r6 */
/* @0xc56f8 mov r1, #3 */
/* @0xc56fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5700 subs r8, r0, #0 */
/* @0xc5704 blt 0xc578c <_Z13F_BUFFER_CopyR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0xc5708 ldr r3, [r5] */
/* @0xc570c cmp r8, r3 */
/* @0xc5710 bge 0xc578c <_Z13F_BUFFER_CopyR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0xc5714 ldr r3, [r5, #0x4] */
/* @0xc5718 ldr r2, [r3, r8, lsl #2] */
/* @0xc571c cmp r2, #0 */
/* @0xc5720 beq 0xc578c <_Z13F_BUFFER_CopyR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0xc5724 cmp r7, r8 */
/* @0xc5728 beq 0xc57a4 <_Z13F_BUFFER_CopyR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0xc572c ldr r4, [r3, r7, lsl #2] */
/* @0xc5730 mov r0, r6 */
/* @0xc5734 mov r1, #1 */
/* @0xc5738 ldr r3, [r4] */
/* @0xc573c ldr r7, [r3, #0x38] */
/* @0xc5740 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5744 mov r1, #2 */
/* @0xc5748 mov r10, r0 */
/* @0xc574c mov r0, r6 */
/* @0xc5750 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5754 ldr r3, [r5, #0x4] */
/* @0xc5758 mov r1, #4 */
/* @0xc575c ldr r5, [r3, r8, lsl #2] */
/* @0xc5760 mov r9, r0 */
/* @0xc5764 mov r0, r6 */
/* @0xc5768 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc576c mov r1, r10 */
/* @0xc5770 mov r2, r9 */
/* @0xc5774 mov r3, r5 */
/* @0xc5778 str r0, [sp] */
/* @0xc577c mov r0, r4 */
/* @0xc5780 blx r7 */
/* @0xc5784 add sp, sp, #8 */
/* @0xc5788 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xc578c ldr r0, [pc, #0x24] */
/* @0xc5790 mov r1, #0 */
/* @0xc5794 add r0, pc, r0 */
/* @0xc5798 add sp, sp, #8 */
/* @0xc579c pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xc57a0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc57a4 ldr r0, [pc, #0x10] */
/* @0xc57a8 mov r1, r4 */
/* @0xc57ac add r0, pc, r0 */
/* @0xc57b0 b 0xc5798 <_Z13F_BUFFER_CopyR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0xc57b4 eorseq r4, r11, r0, asr #20 */
/* @0xc57b8 eoreq r11, r6, r0, ror r4 */
/* @0xc57bc eoreq r11, r6, r4, ror r4 */

/* ── FUNC 0xc57c0 · F_BUFFER_Fill(RValue&, CInstance*, CInstance*, int, RValue*) · size=200 · insn=50 */
/* @0xc57c0 push {r4, r5, r6, r7, r8, lr} */
/* @0xc57c4 sub sp, sp, #16 */
/* @0xc57c8 mov r1, #0 */
/* @0xc57cc ldr r4, [sp, #0x28] */
/* @0xc57d0 mov r0, r4 */
/* @0xc57d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc57d8 cmp r0, #0 */
/* @0xc57dc blt 0xc5868 <_Z13F_BUFFER_FillR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0xc57e0 ldr r3, [pc, #0x98] */
/* @0xc57e4 add r3, pc, r3 */
/* @0xc57e8 ldr r2, [r3] */
/* @0xc57ec cmp r0, r2 */
/* @0xc57f0 bge 0xc5868 <_Z13F_BUFFER_FillR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0xc57f4 ldr r3, [r3, #0x4] */
/* @0xc57f8 ldr r5, [r3, r0, lsl #2] */
/* @0xc57fc cmp r5, #0 */
/* @0xc5800 beq 0xc5868 <_Z13F_BUFFER_FillR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0xc5804 ldr r3, [r5] */
/* @0xc5808 mov r0, r4 */
/* @0xc580c mov r1, #1 */
/* @0xc5810 ldr r6, [r3, #0x3c] */
/* @0xc5814 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5818 mov r1, #4 */
/* @0xc581c mov r8, r0 */
/* @0xc5820 mov r0, r4 */
/* @0xc5824 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5828 mov r1, #2 */
/* @0xc582c mov r7, r0 */
/* @0xc5830 mov r0, r4 */
/* @0xc5834 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5838 add r4, r4, #48 */
/* @0xc583c mvn r12, #0 */
/* @0xc5840 mov lr, #1 */
/* @0xc5844 mov r1, r8 */
/* @0xc5848 mov r2, r7 */
/* @0xc584c str r4, [sp] */
/* @0xc5850 stmib sp, {r12, lr} */
/* @0xc5854 mov r3, r0 */
/* @0xc5858 mov r0, r5 */
/* @0xc585c blx r6 */
/* @0xc5860 add sp, sp, #16 */
/* @0xc5864 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc5868 ldr r0, [pc, #0x14] */
/* @0xc586c mov r1, #0 */
/* @0xc5870 add r0, pc, r0 */
/* @0xc5874 add sp, sp, #16 */
/* @0xc5878 pop {r4, r5, r6, r7, r8, lr} */
/* @0xc587c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc5880 eorseq r4, r11, r0, lsr r9 */
/* @0xc5884 eoreq r11, r6, r4, asr #6 */
