/* libyoyo.so 覆盖卡组 0191
 * 函数 0x215808..0x2164bc，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x215808 · CEmitter::Clear() · size=4 · insn=1 */
/* @0x215808 bx lr */

/* ── FUNC 0x21580c · CEmitter::~CEmitter() · size=208 · insn=52 */
/* @0x21580c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x215810 mov r7, r0 */
/* @0x215814 bl 0x215808 <_ZN8CEmitter5ClearEv> */
/* @0x215818 ldr r12, [r7, #0x34] */
/* @0x21581c cmp r12, #0 */
/* @0x215820 beq 0x2158c4 <_ZN8CEmitterD2Ev+0xb8> */
/* @0x215824 ldr r5, [r7, #0x38] */
/* @0x215828 cmp r5, #0 */
/* @0x21582c beq 0x2158cc <_ZN8CEmitterD2Ev+0xc0> */
/* @0x215830 cmp r12, #0 */
/* @0x215834 ble 0x2158ac <_ZN8CEmitterD2Ev+0xa0> */
/* @0x215838 mov r4, #0 */
/* @0x21583c mov r9, r4 */
/* @0x215840 ldr r1, [r5] */
/* @0x215844 movw r3, #0xfeee */
/* @0x215848 movt r3, #0xfeee */
/* @0x21584c movw r2, #0xfeee */
/* @0x215850 cmp r1, r3 */
/* @0x215854 movt r2, #0xfeee */
/* @0x215858 lsl r8, r4, #2 */
/* @0x21585c beq 0x2158a0 <_ZN8CEmitterD2Ev+0x94> */
/* @0x215860 ldr r6, [r5, r4, lsl #2] */
/* @0x215864 add r3, r5, r8 */
/* @0x215868 cmp r6, #0 */
/* @0x21586c mov r0, r6 */
/* @0x215870 beq 0x2158a0 <_ZN8CEmitterD2Ev+0x94> */
/* @0x215874 ldr r1, [r6] */
/* @0x215878 cmp r1, r2 */
/* @0x21587c beq 0x215898 <_ZN8CEmitterD2Ev+0x8c> */
/* @0x215880 bl 0x21db28 <_ZN6CNoiseD2Ev> */
/* @0x215884 mov r0, r6 */
/* @0x215888 bl 0x27d1d0 <_ZdlPv> */
/* @0x21588c ldr r3, [r7, #0x38] */
/* @0x215890 ldr r12, [r7, #0x34] */
/* @0x215894 add r3, r3, r8 */
/* @0x215898 str r9, [r3] */
/* @0x21589c ldr r5, [r7, #0x38] */
/* @0x2158a0 add r4, r4, #1 */
/* @0x2158a4 cmp r4, r12 */
/* @0x2158a8 blt 0x215840 <_ZN8CEmitterD2Ev+0x34> */
/* @0x2158ac mov r0, r5 */
/* @0x2158b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2158b4 mov r3, #0 */
/* @0x2158b8 str r3, [r7, #0x38] */
/* @0x2158bc mov r3, #0 */
/* @0x2158c0 str r3, [r7, #0x34] */
/* @0x2158c4 mov r0, r7 */
/* @0x2158c8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2158cc mov r0, r5 */
/* @0x2158d0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2158d4 str r5, [r7, #0x38] */
/* @0x2158d8 b 0x2158bc <_ZN8CEmitterD2Ev+0xb0> */

/* ── FUNC 0x21580c · CEmitter::~CEmitter() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2158dc · CEmitter::RemoveNoiseFromEmitter(CNoise*) · size=104 · insn=26 */
/* @0x2158dc str r4, [sp, #-0x4]! */
/* @0x2158e0 ldr r4, [r0, #0x34] */
/* @0x2158e4 cmp r4, #0 */
/* @0x2158e8 ble 0x215928 <_ZN8CEmitter22RemoveNoiseFromEmitterEP6CNoise+0x4c> */
/* @0x2158ec ldr r0, [r0, #0x38] */
/* @0x2158f0 ldr r3, [r0] */
/* @0x2158f4 cmp r1, r3 */
/* @0x2158f8 addne r2, r0, #4 */
/* @0x2158fc movne r3, #0 */
/* @0x215900 bne 0x215914 <_ZN8CEmitter22RemoveNoiseFromEmitterEP6CNoise+0x38> */
/* @0x215904 b 0x215930 <_ZN8CEmitter22RemoveNoiseFromEmitterEP6CNoise+0x54> */
/* @0x215908 ldr r12, [r0] */
/* @0x21590c cmp r1, r12 */
/* @0x215910 beq 0x215930 <_ZN8CEmitter22RemoveNoiseFromEmitterEP6CNoise+0x54> */
/* @0x215914 add r3, r3, #1 */
/* @0x215918 mov r0, r2 */
/* @0x21591c cmp r3, r4 */
/* @0x215920 add r2, r2, #4 */
/* @0x215924 bne 0x215908 <_ZN8CEmitter22RemoveNoiseFromEmitterEP6CNoise+0x2c> */
/* @0x215928 ldr r4, [sp], #4 */
/* @0x21592c bx lr */
/* @0x215930 mov r3, #0 */
/* @0x215934 ldr r4, [sp], #4 */
/* @0x215938 str r3, [r1, #0x38] */
/* @0x21593c str r3, [r0] */
/* @0x215940 bx lr */

/* ── FUNC 0x215944 · CEmitter::AddNoiseToEmitter(CNoise*) · size=372 · insn=93 */
/* @0x215944 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x215948 mov r8, r1 */
/* @0x21594c ldr r4, [r0, #0x34] */
/* @0x215950 sub sp, sp, #20 */
/* @0x215954 ldr r3, [r0, #0x30] */
/* @0x215958 mov r6, r0 */
/* @0x21595c cmp r4, #0 */
/* @0x215960 str r0, [r8, #0x38] */
/* @0x215964 str r3, [r1, #0x34] */
/* @0x215968 ldr r7, [r0, #0x38] */
/* @0x21596c ble 0x2159bc <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x78> */
/* @0x215970 ldr r3, [r7] */
/* @0x215974 cmp r3, #0 */
/* @0x215978 beq 0x215a68 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x124> */
/* @0x21597c ldrb r3, [r3, #0x5] */
/* @0x215980 cmp r3, #0 */
/* @0x215984 addne r2, r7, #4 */
/* @0x215988 movne r3, #0 */
/* @0x21598c bne 0x2159ac <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x68> */
/* @0x215990 b 0x215a68 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x124> */
/* @0x215994 ldr r12, [r2], #4 */
/* @0x215998 cmp r12, #0 */
/* @0x21599c beq 0x215a6c <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x128> */
/* @0x2159a0 ldrb r12, [r12, #0x5] */
/* @0x2159a4 cmp r12, #0 */
/* @0x2159a8 beq 0x215a6c <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x128> */
/* @0x2159ac add r3, r3, #1 */
/* @0x2159b0 mov r5, r2 */
/* @0x2159b4 cmp r3, r4 */
/* @0x2159b8 bne 0x215994 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x50> */
/* @0x2159bc adds r10, r4, #1 */
/* @0x2159c0 bne 0x215a78 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x134> */
/* @0x2159c4 cmp r7, #0 */
/* @0x2159c8 beq 0x215a50 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x10c> */
/* @0x2159cc cmp r4, #0 */
/* @0x2159d0 ble 0x215a50 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x10c> */
/* @0x2159d4 mov r5, r10 */
/* @0x2159d8 mov r1, r10 */
/* @0x2159dc ldr r0, [r7] */
/* @0x2159e0 movw r3, #0xfeee */
/* @0x2159e4 movt r3, #0xfeee */
/* @0x2159e8 movw r2, #0xfeee */
/* @0x2159ec cmp r0, r3 */
/* @0x2159f0 movt r2, #0xfeee */
/* @0x2159f4 lsl r11, r5, #2 */
/* @0x2159f8 beq 0x215a40 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0xfc> */
/* @0x2159fc ldr r9, [r7, r5, lsl #2] */
/* @0x215a00 add r3, r7, r11 */
/* @0x215a04 cmp r9, #0 */
/* @0x215a08 mov r0, r9 */
/* @0x215a0c beq 0x215a40 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0xfc> */
/* @0x215a10 ldr r12, [r9] */
/* @0x215a14 cmp r12, r2 */
/* @0x215a18 beq 0x215a38 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0xf4> */
/* @0x215a1c str r1, [sp, #0xc] */
/* @0x215a20 bl 0x21db28 <_ZN6CNoiseD2Ev> */
/* @0x215a24 mov r0, r9 */
/* @0x215a28 bl 0x27d1d0 <_ZdlPv> */
/* @0x215a2c ldr r3, [r6, #0x38] */
/* @0x215a30 ldr r1, [sp, #0xc] */
/* @0x215a34 add r3, r3, r11 */
/* @0x215a38 str r1, [r3] */
/* @0x215a3c ldr r7, [r6, #0x38] */
/* @0x215a40 ldr r3, [r6, #0x34] */
/* @0x215a44 add r5, r5, #1 */
/* @0x215a48 cmp r5, r3 */
/* @0x215a4c blt 0x2159dc <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x98> */
/* @0x215a50 mov r0, r7 */
/* @0x215a54 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x215a58 mov r2, #0 */
/* @0x215a5c mov r3, r2 */
/* @0x215a60 str r2, [r6, #0x38] */
/* @0x215a64 b 0x215aa4 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x160> */
/* @0x215a68 mov r5, r7 */
/* @0x215a6c str r8, [r5] */
/* @0x215a70 add sp, sp, #20 */
/* @0x215a74 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x215a78 lsls r1, r10, #2 */
/* @0x215a7c beq 0x215a50 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x10c> */
/* @0x215a80 ldr r2, [pc, #0x2c] */
/* @0x215a84 mov r3, #0 */
/* @0x215a88 mov r0, r7 */
/* @0x215a8c str r3, [sp] */
/* @0x215a90 add r2, pc, r2 */
/* @0x215a94 mov r3, #135 */
/* @0x215a98 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x215a9c mov r3, r0 */
/* @0x215aa0 str r0, [r6, #0x38] */
/* @0x215aa4 str r10, [r6, #0x34] */
/* @0x215aa8 str r8, [r3, r4, lsl #2] */
/* @0x215aac add sp, sp, #20 */
/* @0x215ab0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x215ab4 andseq r7, r3, r0, ror #16 */

/* ── FUNC 0x215ab8 · CListener::Reset() · size=48 · insn=12 */
/* @0x215ab8 push {r4, lr} */
/* @0x215abc mov r2, #52 */
/* @0x215ac0 mov r4, r0 */
/* @0x215ac4 mov r1, #0 */
/* @0x215ac8 bl 0xb65b0 <memset@plt> */
/* @0x215acc mov r3, #1065353216 */
/* @0x215ad0 mov r2, #0 */
/* @0x215ad4 str r3, [r4, #0x2c] */
/* @0x215ad8 movt r2, #0xbf80 */
/* @0x215adc str r3, [r4, #0x30] */
/* @0x215ae0 str r2, [r4, #0x20] */
/* @0x215ae4 pop {r4, pc} */

/* ── FUNC 0x215ae8 · CListener::CListener() · size=52 · insn=13 */
/* @0x215ae8 push {r4, lr} */
/* @0x215aec movw r3, #0x4f80 */
/* @0x215af0 mov r4, r0 */
/* @0x215af4 movt r3, #0xc7c3 */
/* @0x215af8 str r3, [r0] */
/* @0x215afc str r3, [r0, #0x4] */
/* @0x215b00 str r3, [r0, #0x8] */
/* @0x215b04 str r3, [r0, #0xc] */
/* @0x215b08 str r3, [r0, #0x10] */
/* @0x215b0c str r3, [r0, #0x14] */
/* @0x215b10 bl 0x215ab8 <_ZN9CListener5ResetEv> */
/* @0x215b14 mov r0, r4 */
/* @0x215b18 pop {r4, pc} */

/* ── FUNC 0x215ae8 · CListener::CListener() · alias of the symbol above · insn=0 */

/* ── FUNC 0x215b1c · CListener::Clear() · size=4 · insn=1 */
/* @0x215b1c bx lr */

/* ── FUNC 0x215b20 · CListener::~CListener() · size=20 · insn=5 */
/* @0x215b20 push {r4, lr} */
/* @0x215b24 mov r4, r0 */
/* @0x215b28 bl 0x215b1c <_ZN9CListener5ClearEv> */
/* @0x215b2c mov r0, r4 */
/* @0x215b30 pop {r4, pc} */

/* ── FUNC 0x215b20 · CListener::~CListener() · alias of the symbol above · insn=0 */

/* ── FUNC 0x215b34 · CListener::SetGain(float) · size=12 · insn=3 */
/* @0x215b34 str r1, [r0, #0x30] */
/* @0x215b38 movw r0, #0x100a */
/* @0x215b3c b 0xb6a30 <alListenerf@plt> */

/* ── FUNC 0x215b40 · CListener::GetGain() · size=8 · insn=2 */
/* @0x215b40 ldr r0, [r0, #0x30] */
/* @0x215b44 bx lr */

/* ── FUNC 0x215b48 · CListener::Update() · size=244 · insn=61 */
/* @0x215b48 push {r3, r4, r5, lr} */
/* @0x215b4c mov r4, r0 */
/* @0x215b50 bl 0xb6a3c <alcGetCurrentContext@plt> */
/* @0x215b54 ldr r5, [pc, #0xcc] */
/* @0x215b58 add r5, pc, r5 */
/* @0x215b5c cmp r0, #0 */
/* @0x215b60 popeq {r3, r4, r5, pc} */
/* @0x215b64 ldr r2, [r4, #0x4] */
/* @0x215b68 movw r0, #0x1004 */
/* @0x215b6c ldr r1, [r4] */
/* @0x215b70 ldr r3, [r4, #0x8] */
/* @0x215b74 bl 0xb6a48 <alListener3f@plt> */
/* @0x215b78 bl 0xb6a54 <alGetError@plt> */
/* @0x215b7c subs r2, r0, #0 */
/* @0x215b80 bne 0x215c04 <_ZN9CListener6UpdateEv+0xbc> */
/* @0x215b84 ldr r2, [r4, #0x10] */
/* @0x215b88 movw r0, #0x1006 */
/* @0x215b8c ldr r1, [r4, #0xc] */
/* @0x215b90 ldr r3, [r4, #0x14] */
/* @0x215b94 bl 0xb6a48 <alListener3f@plt> */
/* @0x215b98 bl 0xb6a54 <alGetError@plt> */
/* @0x215b9c subs r2, r0, #0 */
/* @0x215ba0 bne 0x215be0 <_ZN9CListener6UpdateEv+0x98> */
/* @0x215ba4 add r1, r4, #24 */
/* @0x215ba8 movw r0, #0x100f */
/* @0x215bac bl 0xb6a60 <alListenerfv@plt> */
/* @0x215bb0 bl 0xb6a54 <alGetError@plt> */
/* @0x215bb4 subs r2, r0, #0 */
/* @0x215bb8 popeq {r3, r4, r5, pc} */
/* @0x215bbc ldr r3, [pc, #0x68] */
/* @0x215bc0 ldr r1, [pc, #0x68] */
/* @0x215bc4 ldr r3, [r5, r3] */
/* @0x215bc8 add r1, pc, r1 */
/* @0x215bcc ldr r0, [r3] */
/* @0x215bd0 ldr r3, [r0] */
/* @0x215bd4 ldr r3, [r3, #0xc] */
/* @0x215bd8 blx r3 */
/* @0x215bdc pop {r3, r4, r5, pc} */
/* @0x215be0 ldr r3, [pc, #0x44] */
/* @0x215be4 ldr r1, [pc, #0x48] */
/* @0x215be8 ldr r3, [r5, r3] */
/* @0x215bec add r1, pc, r1 */
/* @0x215bf0 ldr r0, [r3] */
/* @0x215bf4 ldr r3, [r0] */
/* @0x215bf8 ldr r3, [r3, #0xc] */
/* @0x215bfc blx r3 */
/* @0x215c00 b 0x215ba4 <_ZN9CListener6UpdateEv+0x5c> */
/* @0x215c04 ldr r3, [pc, #0x20] */
/* @0x215c08 ldr r1, [pc, #0x28] */
/* @0x215c0c ldr r3, [r5, r3] */
/* @0x215c10 add r1, pc, r1 */
/* @0x215c14 ldr r0, [r3] */
/* @0x215c18 ldr r3, [r0] */
/* @0x215c1c ldr r3, [r3, #0xc] */
/* @0x215c20 blx r3 */
/* @0x215c24 b 0x215b84 <_ZN9CListener6UpdateEv+0x3c> */
/* @0x215c28 ldrsheq r12, [sp], -r8 */
/* @0x215c2c .word 0xffffbac4 */
/* @0x215c30 andseq sp, r3, r4, lsr #30 */
/* @0x215c34 ldrsbeq sp, [r3], -r12 */
/* @0x215c38 mulseq r3, r4, lr */

/* ── FUNC 0x215c3c · COggAudio::~COggAudio() · size=80 · insn=20 */
/* @0x215c3c push {r3, r4, r5, lr} */
/* @0x215c40 mov r4, r0 */
/* @0x215c44 ldr r3, [r0, #0x4] */
/* @0x215c48 cmp r3, #0 */
/* @0x215c4c beq 0x215c74 <_ZN9COggAudioD2Ev+0x38> */
/* @0x215c50 ldr r5, [r0, #0x10] */
/* @0x215c54 subs r0, r5, #0 */
/* @0x215c58 beq 0x215c7c <_ZN9COggAudioD2Ev+0x40> */
/* @0x215c5c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x215c60 mov r3, #0 */
/* @0x215c64 str r3, [r4, #0x10] */
/* @0x215c68 str r3, [r4, #0x8] */
/* @0x215c6c mov r3, #0 */
/* @0x215c70 str r3, [r4, #0x4] */
/* @0x215c74 mov r0, r4 */
/* @0x215c78 pop {r3, r4, r5, pc} */
/* @0x215c7c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x215c80 str r5, [r4, #0x10] */
/* @0x215c84 str r5, [r4, #0x8] */
/* @0x215c88 b 0x215c6c <_ZN9COggAudioD2Ev+0x30> */

/* ── FUNC 0x215c3c · COggAudio::~COggAudio() · alias of the symbol above · insn=0 */

/* ── FUNC 0x215c8c · cARRAY_CLASS<SRecordingInfo*>::~cARRAY_CLASS() · size=196 · insn=49 */
/* @0x215c8c ldr r12, [r0] */
/* @0x215c90 push {r4, r5, r6, r7, r8, lr} */
/* @0x215c94 cmp r12, #0 */
/* @0x215c98 mov r6, r0 */
/* @0x215c9c beq 0x215d38 <_ZN12cARRAY_CLASSIP14SRecordingInfoED2Ev+0xac> */
/* @0x215ca0 ldr r5, [r0, #0x4] */
/* @0x215ca4 cmp r5, #0 */
/* @0x215ca8 beq 0x215d40 <_ZN12cARRAY_CLASSIP14SRecordingInfoED2Ev+0xb4> */
/* @0x215cac cmp r12, #0 */
/* @0x215cb0 ble 0x215d20 <_ZN12cARRAY_CLASSIP14SRecordingInfoED2Ev+0x94> */
/* @0x215cb4 mov r4, #0 */
/* @0x215cb8 mov r8, r4 */
/* @0x215cbc ldr r1, [r5] */
/* @0x215cc0 movw r3, #0xfeee */
/* @0x215cc4 movt r3, #0xfeee */
/* @0x215cc8 movw r2, #0xfeee */
/* @0x215ccc cmp r1, r3 */
/* @0x215cd0 movt r2, #0xfeee */
/* @0x215cd4 lsl r7, r4, #2 */
/* @0x215cd8 beq 0x215d14 <_ZN12cARRAY_CLASSIP14SRecordingInfoED2Ev+0x88> */
/* @0x215cdc ldr r3, [r5, r4, lsl #2] */
/* @0x215ce0 add r1, r5, r7 */
/* @0x215ce4 cmp r3, #0 */
/* @0x215ce8 mov r0, r3 */
/* @0x215cec beq 0x215d14 <_ZN12cARRAY_CLASSIP14SRecordingInfoED2Ev+0x88> */
/* @0x215cf0 ldr r3, [r3] */
/* @0x215cf4 cmp r3, r2 */
/* @0x215cf8 beq 0x215d0c <_ZN12cARRAY_CLASSIP14SRecordingInfoED2Ev+0x80> */
/* @0x215cfc bl 0x27d1d0 <_ZdlPv> */
/* @0x215d00 ldr r1, [r6, #0x4] */
/* @0x215d04 ldr r12, [r6] */
/* @0x215d08 add r1, r1, r7 */
/* @0x215d0c str r8, [r1] */
/* @0x215d10 ldr r5, [r6, #0x4] */
/* @0x215d14 add r4, r4, #1 */
/* @0x215d18 cmp r4, r12 */
/* @0x215d1c blt 0x215cbc <_ZN12cARRAY_CLASSIP14SRecordingInfoED2Ev+0x30> */
/* @0x215d20 mov r0, r5 */
/* @0x215d24 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x215d28 mov r3, #0 */
/* @0x215d2c str r3, [r6, #0x4] */
/* @0x215d30 mov r3, #0 */
/* @0x215d34 str r3, [r6] */
/* @0x215d38 mov r0, r6 */
/* @0x215d3c pop {r4, r5, r6, r7, r8, pc} */
/* @0x215d40 mov r0, r5 */
/* @0x215d44 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x215d48 str r5, [r6, #0x4] */
/* @0x215d4c b 0x215d30 <_ZN12cARRAY_CLASSIP14SRecordingInfoED2Ev+0xa4> */

/* ── FUNC 0x215c8c · cARRAY_CLASS<SRecordingInfo*>::~cARRAY_CLASS() · alias of the symbol above · insn=0 */

/* ── FUNC 0x215d50 · cARRAY_CLASS<CEmitter*>::~cARRAY_CLASS() · size=204 · insn=51 */
/* @0x215d50 ldr r12, [r0] */
/* @0x215d54 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x215d58 cmp r12, #0 */
/* @0x215d5c mov r7, r0 */
/* @0x215d60 beq 0x215e04 <_ZN12cARRAY_CLASSIP8CEmitterED2Ev+0xb4> */
/* @0x215d64 ldr r5, [r0, #0x4] */
/* @0x215d68 cmp r5, #0 */
/* @0x215d6c beq 0x215e0c <_ZN12cARRAY_CLASSIP8CEmitterED2Ev+0xbc> */
/* @0x215d70 cmp r12, #0 */
/* @0x215d74 ble 0x215dec <_ZN12cARRAY_CLASSIP8CEmitterED2Ev+0x9c> */
/* @0x215d78 mov r4, #0 */
/* @0x215d7c mov r9, r4 */
/* @0x215d80 ldr r1, [r5] */
/* @0x215d84 movw r3, #0xfeee */
/* @0x215d88 movt r3, #0xfeee */
/* @0x215d8c movw r2, #0xfeee */
/* @0x215d90 cmp r1, r3 */
/* @0x215d94 movt r2, #0xfeee */
/* @0x215d98 lsl r8, r4, #2 */
/* @0x215d9c beq 0x215de0 <_ZN12cARRAY_CLASSIP8CEmitterED2Ev+0x90> */
/* @0x215da0 ldr r6, [r5, r4, lsl #2] */
/* @0x215da4 add r3, r5, r8 */
/* @0x215da8 cmp r6, #0 */
/* @0x215dac mov r0, r6 */
/* @0x215db0 beq 0x215de0 <_ZN12cARRAY_CLASSIP8CEmitterED2Ev+0x90> */
/* @0x215db4 ldr r1, [r6] */
/* @0x215db8 cmp r1, r2 */
/* @0x215dbc beq 0x215dd8 <_ZN12cARRAY_CLASSIP8CEmitterED2Ev+0x88> */
/* @0x215dc0 bl 0x21580c <_ZN8CEmitterD2Ev> */
/* @0x215dc4 mov r0, r6 */
/* @0x215dc8 bl 0x27d1d0 <_ZdlPv> */
/* @0x215dcc ldr r3, [r7, #0x4] */
/* @0x215dd0 ldr r12, [r7] */
/* @0x215dd4 add r3, r3, r8 */
/* @0x215dd8 str r9, [r3] */
/* @0x215ddc ldr r5, [r7, #0x4] */
/* @0x215de0 add r4, r4, #1 */
/* @0x215de4 cmp r4, r12 */
/* @0x215de8 blt 0x215d80 <_ZN12cARRAY_CLASSIP8CEmitterED2Ev+0x30> */
/* @0x215dec mov r0, r5 */
/* @0x215df0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x215df4 mov r3, #0 */
/* @0x215df8 str r3, [r7, #0x4] */
/* @0x215dfc mov r3, #0 */
/* @0x215e00 str r3, [r7] */
/* @0x215e04 mov r0, r7 */
/* @0x215e08 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x215e0c mov r0, r5 */
/* @0x215e10 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x215e14 str r5, [r7, #0x4] */
/* @0x215e18 b 0x215dfc <_ZN12cARRAY_CLASSIP8CEmitterED2Ev+0xac> */

/* ── FUNC 0x215d50 · cARRAY_CLASS<CEmitter*>::~cARRAY_CLASS() · alias of the symbol above · insn=0 */

/* ── FUNC 0x215e1c · cARRAY_CLASS<SRecordingDevice*>::~cARRAY_CLASS() · size=216 · insn=54 */
/* @0x215e1c ldr r12, [r0] */
/* @0x215e20 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x215e24 cmp r12, #0 */
/* @0x215e28 mov r7, r0 */
/* @0x215e2c beq 0x215edc <_ZN12cARRAY_CLASSIP16SRecordingDeviceED2Ev+0xc0> */
/* @0x215e30 ldr r5, [r0, #0x4] */
/* @0x215e34 cmp r5, #0 */
/* @0x215e38 beq 0x215ee4 <_ZN12cARRAY_CLASSIP16SRecordingDeviceED2Ev+0xc8> */
/* @0x215e3c cmp r12, #0 */
/* @0x215e40 ble 0x215ec4 <_ZN12cARRAY_CLASSIP16SRecordingDeviceED2Ev+0xa8> */
/* @0x215e44 mov r4, #0 */
/* @0x215e48 mov r8, r4 */
/* @0x215e4c ldr r1, [r5] */
/* @0x215e50 movw r3, #0xfeee */
/* @0x215e54 movt r3, #0xfeee */
/* @0x215e58 movw r2, #0xfeee */
/* @0x215e5c cmp r1, r3 */
/* @0x215e60 movt r2, #0xfeee */
/* @0x215e64 lsl r9, r4, #2 */
/* @0x215e68 beq 0x215eb8 <_ZN12cARRAY_CLASSIP16SRecordingDeviceED2Ev+0x9c> */
/* @0x215e6c ldr r6, [r5, r4, lsl #2] */
/* @0x215e70 add r1, r5, r9 */
/* @0x215e74 cmp r6, #0 */
/* @0x215e78 beq 0x215eb8 <_ZN12cARRAY_CLASSIP16SRecordingDeviceED2Ev+0x9c> */
/* @0x215e7c ldr r3, [r6] */
/* @0x215e80 cmp r3, r2 */
/* @0x215e84 mov r0, r3 */
/* @0x215e88 beq 0x215eb0 <_ZN12cARRAY_CLASSIP16SRecordingDeviceED2Ev+0x94> */
/* @0x215e8c cmp r3, #0 */
/* @0x215e90 beq 0x215e9c <_ZN12cARRAY_CLASSIP16SRecordingDeviceED2Ev+0x80> */
/* @0x215e94 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x215e98 str r8, [r6] */
/* @0x215e9c mov r0, r6 */
/* @0x215ea0 bl 0x27d1d0 <_ZdlPv> */
/* @0x215ea4 ldr r1, [r7, #0x4] */
/* @0x215ea8 ldr r12, [r7] */
/* @0x215eac add r1, r1, r9 */
/* @0x215eb0 str r8, [r1] */
/* @0x215eb4 ldr r5, [r7, #0x4] */
/* @0x215eb8 add r4, r4, #1 */
/* @0x215ebc cmp r4, r12 */
/* @0x215ec0 blt 0x215e4c <_ZN12cARRAY_CLASSIP16SRecordingDeviceED2Ev+0x30> */
/* @0x215ec4 mov r0, r5 */
/* @0x215ec8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x215ecc mov r3, #0 */
/* @0x215ed0 str r3, [r7, #0x4] */
/* @0x215ed4 mov r3, #0 */
/* @0x215ed8 str r3, [r7] */
/* @0x215edc mov r0, r7 */
/* @0x215ee0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x215ee4 mov r0, r5 */
/* @0x215ee8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x215eec str r5, [r7, #0x4] */
/* @0x215ef0 b 0x215ed4 <_ZN12cARRAY_CLASSIP16SRecordingDeviceED2Ev+0xb8> */

/* ── FUNC 0x215e1c · cARRAY_CLASS<SRecordingDevice*>::~cARRAY_CLASS() · alias of the symbol above · insn=0 */

/* ── FUNC 0x215ef4 · cARRAY_CLASS<CNoise*>::~cARRAY_CLASS() · size=204 · insn=51 */
/* @0x215ef4 ldr r12, [r0] */
/* @0x215ef8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x215efc cmp r12, #0 */
/* @0x215f00 mov r7, r0 */
/* @0x215f04 beq 0x215fa8 <_ZN12cARRAY_CLASSIP6CNoiseED2Ev+0xb4> */
/* @0x215f08 ldr r5, [r0, #0x4] */
/* @0x215f0c cmp r5, #0 */
/* @0x215f10 beq 0x215fb0 <_ZN12cARRAY_CLASSIP6CNoiseED2Ev+0xbc> */
/* @0x215f14 cmp r12, #0 */
/* @0x215f18 ble 0x215f90 <_ZN12cARRAY_CLASSIP6CNoiseED2Ev+0x9c> */
/* @0x215f1c mov r4, #0 */
/* @0x215f20 mov r9, r4 */
/* @0x215f24 ldr r1, [r5] */
/* @0x215f28 movw r3, #0xfeee */
/* @0x215f2c movt r3, #0xfeee */
/* @0x215f30 movw r2, #0xfeee */
/* @0x215f34 cmp r1, r3 */
/* @0x215f38 movt r2, #0xfeee */
/* @0x215f3c lsl r8, r4, #2 */
/* @0x215f40 beq 0x215f84 <_ZN12cARRAY_CLASSIP6CNoiseED2Ev+0x90> */
/* @0x215f44 ldr r6, [r5, r4, lsl #2] */
/* @0x215f48 add r3, r5, r8 */
/* @0x215f4c cmp r6, #0 */
/* @0x215f50 mov r0, r6 */
/* @0x215f54 beq 0x215f84 <_ZN12cARRAY_CLASSIP6CNoiseED2Ev+0x90> */
/* @0x215f58 ldr r1, [r6] */
/* @0x215f5c cmp r1, r2 */
/* @0x215f60 beq 0x215f7c <_ZN12cARRAY_CLASSIP6CNoiseED2Ev+0x88> */
/* @0x215f64 bl 0x21db28 <_ZN6CNoiseD2Ev> */
/* @0x215f68 mov r0, r6 */
/* @0x215f6c bl 0x27d1d0 <_ZdlPv> */
/* @0x215f70 ldr r3, [r7, #0x4] */
/* @0x215f74 ldr r12, [r7] */
/* @0x215f78 add r3, r3, r8 */
/* @0x215f7c str r9, [r3] */
/* @0x215f80 ldr r5, [r7, #0x4] */
/* @0x215f84 add r4, r4, #1 */
/* @0x215f88 cmp r4, r12 */
/* @0x215f8c blt 0x215f24 <_ZN12cARRAY_CLASSIP6CNoiseED2Ev+0x30> */
/* @0x215f90 mov r0, r5 */
/* @0x215f94 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x215f98 mov r3, #0 */
/* @0x215f9c str r3, [r7, #0x4] */
/* @0x215fa0 mov r3, #0 */
/* @0x215fa4 str r3, [r7] */
/* @0x215fa8 mov r0, r7 */
/* @0x215fac pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x215fb0 mov r0, r5 */
/* @0x215fb4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x215fb8 str r5, [r7, #0x4] */
/* @0x215fbc b 0x215fa0 <_ZN12cARRAY_CLASSIP6CNoiseED2Ev+0xac> */

/* ── FUNC 0x215ef4 · cARRAY_CLASS<CNoise*>::~cARRAY_CLASS() · alias of the symbol above · insn=0 */

/* ── FUNC 0x215fc0 · OggAudioSyncDrawDebug() · size=16 · insn=4 */
/* @0x215fc0 ldr r0, [pc, #0x4] */
/* @0x215fc4 add r0, pc, r0 */
/* @0x215fc8 b 0x226a10 <_ZN9COggAudio13SyncDrawDebugEv> */
/* @0x215fcc ldrsbeq pc, [r3], #-32 */

/* ── FUNC 0x215fd0 · checkAL(char const*) · size=120 · insn=30 */
/* @0x215fd0 push {r4, lr} */
/* @0x215fd4 mov r4, r0 */
/* @0x215fd8 bl 0xb6a54 <alGetError@plt> */
/* @0x215fdc subs r2, r0, #0 */
/* @0x215fe0 popeq {r4, pc} */
/* @0x215fe4 cmp r4, #0 */
/* @0x215fe8 beq 0x216014 <_Z7checkALPKc+0x44> */
/* @0x215fec ldr r12, [pc, #0x44] */
/* @0x215ff0 mov r3, r4 */
/* @0x215ff4 ldr r1, [pc, #0x40] */
/* @0x215ff8 ldr r12, [pc, r12] */
/* @0x215ffc add r1, pc, r1 */
/* @0x216000 ldr r0, [r12] */
/* @0x216004 ldr r12, [r0] */
/* @0x216008 ldr r12, [r12, #0xc] */
/* @0x21600c blx r12 */
/* @0x216010 pop {r4, pc} */
/* @0x216014 ldr r3, [pc, #0x24] */
/* @0x216018 ldr r1, [pc, #0x24] */
/* @0x21601c ldr r3, [pc, r3] */
/* @0x216020 add r1, pc, r1 */
/* @0x216024 ldr r0, [r3] */
/* @0x216028 ldr r3, [r0] */
/* @0x21602c ldr r3, [r3, #0xc] */
/* @0x216030 blx r3 */
/* @0x216034 pop {r4, pc} */
/* @0x216038 andseq r7, sp, r12, lsl r7 */
/* @0x21603c andseq sp, r3, r8, lsl r11 */
/* @0x216040 ldrsheq r7, [sp], -r8 */
/* @0x216044 andseq sp, r3, r12, lsl #22 */

/* ── FUNC 0x216048 · anon_216048 · size=528 · insn=133 */
/* @0x216048 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x21604c mov r5, r1 */
/* @0x216050 ldr r6, [pc, #0x1e8] */
/* @0x216054 sub sp, sp, #1040 */
/* @0x216058 ldr r3, [pc, #0x1e4] */
/* @0x21605c sub sp, sp, #8 */
/* @0x216060 add r6, pc, r6 */
/* @0x216064 ldrb r2, [r0, #0x5c] */
/* @0x216068 ldr r8, [r1, #0x10] */
/* @0x21606c mov r4, r0 */
/* @0x216070 ldr r7, [r6, r3] */
/* @0x216074 cmp r2, #0 */
/* @0x216078 ldrb r9, [r1, #0x4] */
/* @0x21607c ldr r1, [r7] */
/* @0x216080 str r1, [sp, #0x414] */
/* @0x216084 bne 0x2161bc <_Z7checkALPKc+0x1ec> */
/* @0x216088 ldrb r3, [r0, #0x24] */
/* @0x21608c cmp r3, #0 */
/* @0x216090 beq 0x2160f8 <_Z7checkALPKc+0x128> */
/* @0x216094 ldr r3, [r0, #0x30] */
/* @0x216098 cmp r3, #0 */
/* @0x21609c beq 0x2161f8 <_Z7checkALPKc+0x228> */
/* @0x2160a0 ldr r2, [r5, #0x34] */
/* @0x2160a4 mvn r0, #0 */
/* @0x2160a8 ldr r12, [r4, #0x48] */
/* @0x2160ac mov r1, r8 */
/* @0x2160b0 str r0, [sp, #0x8] */
/* @0x2160b4 mov r3, r9 */
/* @0x2160b8 ldr r0, [pc, #0x188] */
/* @0x2160bc str r2, [sp, #0x4] */
/* @0x2160c0 mov r2, r4 */
/* @0x2160c4 str r12, [sp] */
/* @0x2160c8 add r0, pc, r0 */
/* @0x2160cc bl 0x22630c <_ZN9COggAudio10Play_SoundEiP12cAudio_Soundbfii> */
/* @0x2160d0 cmn r0, #1 */
/* @0x2160d4 bne 0x216190 <_Z7checkALPKc+0x1c0> */
/* @0x2160d8 mov r0, #0 */
/* @0x2160dc ldr r2, [sp, #0x414] */
/* @0x2160e0 ldr r3, [r7] */
/* @0x2160e4 cmp r2, r3 */
/* @0x2160e8 bne 0x21623c <_Z7checkALPKc+0x26c> */
/* @0x2160ec add sp, sp, #1040 */
/* @0x2160f0 add sp, sp, #8 */
/* @0x2160f4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2160f8 ldrb r0, [r0, #0x25] */
/* @0x2160fc cmp r0, #0 */
/* @0x216100 bne 0x2160a0 <_Z7checkALPKc+0xd0> */
/* @0x216104 ldr r2, [r4, #0x18] */
/* @0x216108 cmp r2, #0 */
/* @0x21610c ble 0x2160dc <_Z7checkALPKc+0x10c> */
/* @0x216110 ldr r3, [pc, #0x134] */
/* @0x216114 movw r1, #0x1009 */
/* @0x216118 ldr r10, [r6, r3] */
/* @0x21611c ldr r3, [r10] */
/* @0x216120 ldr r0, [r3, r8, lsl #2] */
/* @0x216124 bl 0xb6a6c <alSourcei@plt> */
/* @0x216128 bl 0xb6a54 <alGetError@plt> */
/* @0x21612c subs r2, r0, #0 */
/* @0x216130 bne 0x2161d4 <_Z7checkALPKc+0x204> */
/* @0x216134 ldr r3, [r10] */
/* @0x216138 cmp r9, #0 */
/* @0x21613c movwne r1, #0x1007 */
/* @0x216140 movne r2, #1 */
/* @0x216144 moveq r2, r9 */
/* @0x216148 movweq r1, #0x1007 */
/* @0x21614c ldr r0, [r3, r8, lsl #2] */
/* @0x216150 bl 0xb6a6c <alSourcei@plt> */
/* @0x216154 vldr s15, [r4, #72] */
/* @0x216158 vcmpe.f32 s15, #0 */
/* @0x21615c vmrs APSR_nzcv, fpscr */
/* @0x216160 ble 0x216184 <_Z7checkALPKc+0x1b4> */
/* @0x216164 ldr r3, [r10] */
/* @0x216168 movw r1, #0x1024 */
/* @0x21616c vmov r2, s15 */
/* @0x216170 ldr r0, [r3, r8, lsl #2] */
/* @0x216174 bl 0xb6a78 <alSourcef@plt> */
/* @0x216178 ldr r0, [pc, #0xd0] */
/* @0x21617c add r0, pc, r0 */
/* @0x216180 bl 0x215fd0 <_Z7checkALPKc> */
/* @0x216184 ldr r3, [r10] */
/* @0x216188 ldr r0, [r3, r8, lsl #2] */
/* @0x21618c bl 0xb6a84 <alSourcePlay@plt> */
/* @0x216190 ldrb r3, [r4, #0x24] */
/* @0x216194 mov r2, #0 */
/* @0x216198 strb r2, [r5, #0xd] */
/* @0x21619c cmp r3, r2 */
/* @0x2161a0 mov r3, #1 */
/* @0x2161a4 mov r0, r3 */
/* @0x2161a8 ldrbeq r2, [r4, #0x25] */
/* @0x2161ac movne r2, #1 */
/* @0x2161b0 strb r3, [r5, #0x5] */
/* @0x2161b4 strb r2, [r5, #0xc] */
/* @0x2161b8 b 0x2160dc <_Z7checkALPKc+0x10c> */
/* @0x2161bc ldr r3, [pc, #0x88] */
/* @0x2161c0 ldr r3, [r6, r3] */
/* @0x2161c4 ldr r3, [r3] */
/* @0x2161c8 ldr r0, [r3, r8, lsl #2] */
/* @0x2161cc bl 0xb6a84 <alSourcePlay@plt> */
/* @0x2161d0 b 0x216190 <_Z7checkALPKc+0x1c0> */
/* @0x2161d4 ldr r3, [pc, #0x78] */
/* @0x2161d8 ldr r1, [pc, #0x78] */
/* @0x2161dc ldr r3, [r6, r3] */
/* @0x2161e0 add r1, pc, r1 */
/* @0x2161e4 ldr r0, [r3] */
/* @0x2161e8 ldr r3, [r0] */
/* @0x2161ec ldr r3, [r3, #0xc] */
/* @0x2161f0 blx r3 */
/* @0x2161f4 b 0x216134 <_Z7checkALPKc+0x164> */
/* @0x2161f8 add r6, sp, #20 */
/* @0x2161fc ldr r2, [r0] */
/* @0x216200 mov r1, #1024 */
/* @0x216204 mov r0, r6 */
/* @0x216208 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x21620c mov r0, r6 */
/* @0x216210 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x216214 cmp r0, #0 */
/* @0x216218 beq 0x2160a0 <_Z7checkALPKc+0xd0> */
/* @0x21621c ldr r0, [r4, #0x30] */
/* @0x216220 cmp r0, #0 */
/* @0x216224 beq 0x21622c <_Z7checkALPKc+0x25c> */
/* @0x216228 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x21622c mov r0, r6 */
/* @0x216230 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x216234 str r0, [r4, #0x30] */
/* @0x216238 b 0x2160a0 <_Z7checkALPKc+0xd0> */
/* @0x21623c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x216240 ldrsheq r11, [sp], -r0 */
/* @0x216244 .word 0xffffbd00 */
/* @0x216248 subseq pc, r3, r12, asr #3 */
/* @0x21624c .word 0xfffff77c */
/* @0x216250 andseq sp, r3, r4, ror #19 */
/* @0x216254 .word 0xffffbac4 */
/* @0x216258 andseq sp, r3, r0, ror #18 */

/* ── FUNC 0x21625c · Audio_CreateSources(int) · size=204 · insn=51 */
/* @0x21625c push {r4, r5, r6, lr} */
/* @0x216260 cmp r0, #532676608 */
/* @0x216264 ldr r5, [pc, #0x9c] */
/* @0x216268 sub r3, r0, #1 */
/* @0x21626c ldr r1, [pc, #0x98] */
/* @0x216270 mov r4, r0 */
/* @0x216274 add r5, pc, r5 */
/* @0x216278 ldr r2, [pc, #0x90] */
/* @0x21627c ldr r1, [r5, r1] */
/* @0x216280 str r0, [r1] */
/* @0x216284 lslls r0, r0, #2 */
/* @0x216288 ldr r6, [r5, r2] */
/* @0x21628c mvnhi r0, #0 */
/* @0x216290 str r3, [r6] */
/* @0x216294 bl 0x27d14c <_Znaj> */
/* @0x216298 ldr r2, [pc, #0x74] */
/* @0x21629c ldr r2, [r5, r2] */
/* @0x2162a0 mov r3, r0 */
/* @0x2162a4 mov r1, r0 */
/* @0x2162a8 mov r0, r4 */
/* @0x2162ac str r3, [r2] */
/* @0x2162b0 bl 0xb6a90 <alGenSources@plt> */
/* @0x2162b4 bl 0xb6a54 <alGetError@plt> */
/* @0x2162b8 subs r2, r0, #0 */
/* @0x2162bc beq 0x2162e0 <_Z19Audio_CreateSourcesi+0x84> */
/* @0x2162c0 ldr r3, [pc, #0x50] */
/* @0x2162c4 ldr r1, [pc, #0x50] */
/* @0x2162c8 ldr r3, [r5, r3] */
/* @0x2162cc add r1, pc, r1 */
/* @0x2162d0 ldr r0, [r3] */
/* @0x2162d4 ldr r3, [r0] */
/* @0x2162d8 ldr r3, [r3, #0xc] */
/* @0x2162dc blx r3 */
/* @0x2162e0 ldr r0, [pc, #0x38] */
/* @0x2162e4 mov r2, r4 */
/* @0x2162e8 mov r1, #4 */
/* @0x2162ec add r0, pc, r0 */
/* @0x2162f0 bl 0x225d18 <_ZN9COggAudio4InitEii> */
/* @0x2162f4 ldr r0, [pc, #0x28] */
/* @0x2162f8 str r4, [r6] */
/* @0x2162fc add r0, pc, r0 */
/* @0x216300 pop {r4, r5, r6, lr} */
/* @0x216304 b 0x215fd0 <_Z7checkALPKc> */
/* @0x216308 ldrsbeq r11, [sp], -r12 */
/* @0x21630c .word 0xfffff780 */
/* @0x216310 .word 0xfffff784 */
/* @0x216314 .word 0xfffff77c */
/* @0x216318 .word 0xffffbac4 */
/* @0x21631c ldrheq sp, [r3], -r8 */
/* @0x216320 subseq lr, r3, r8, lsr #31 */
/* @0x216324 andseq sp, r3, r12, lsr #17 */

/* ── FUNC 0x216328 · Audio_Clean() · size=4 · insn=1 */
/* @0x216328 bx lr */

/* ── FUNC 0x21632c · Audio_GetSound(int) · size=292 · insn=73 */
/* @0x21632c cmp r0, #0 */
/* @0x216330 blt 0x2163f4 <_Z14Audio_GetSoundi+0xc8> */
/* @0x216334 ldr r3, [pc, #0x10c] */
/* @0x216338 add r3, pc, r3 */
/* @0x21633c ldr r2, [r3, #0x20] */
/* @0x216340 cmp r0, r2 */
/* @0x216344 ble 0x2163fc <_Z14Audio_GetSoundi+0xd0> */
/* @0x216348 movw r2, #0x869f */
/* @0x21634c movt r2, #0x1 */
/* @0x216350 cmp r0, r2 */
/* @0x216354 ble 0x2163f4 <_Z14Audio_GetSoundi+0xc8> */
/* @0x216358 movw r2, #0x7961 */
/* @0x21635c ldr r1, [r3, #0x28] */
/* @0x216360 movt r2, #0xfffe */
/* @0x216364 add r2, r0, r2 */
/* @0x216368 cmp r2, r1 */
/* @0x21636c ble 0x21640c <_Z14Audio_GetSoundi+0xe0> */
/* @0x216370 movw r2, #0xd3f */
/* @0x216374 movt r2, #0x3 */
/* @0x216378 cmp r0, r2 */
/* @0x21637c ble 0x2163f4 <_Z14Audio_GetSoundi+0xc8> */
/* @0x216380 movw r2, #0xf2c1 */
/* @0x216384 ldr r1, [r3, #0x30] */
/* @0x216388 movt r2, #0xfffc */
/* @0x21638c add r2, r0, r2 */
/* @0x216390 cmp r2, r1 */
/* @0x216394 bgt 0x2163b4 <_Z14Audio_GetSoundi+0x88> */
/* @0x216398 sub r0, r0, #199680 */
/* @0x21639c sub r0, r0, #320 */
/* @0x2163a0 cmp r1, r0 */
/* @0x2163a4 ble 0x2163f4 <_Z14Audio_GetSoundi+0xc8> */
/* @0x2163a8 ldr r3, [r3, #0x34] */
/* @0x2163ac ldr r0, [r3, r0, lsl #2] */
/* @0x2163b0 bx lr */
/* @0x2163b4 movw r3, #0x93df */
/* @0x2163b8 movt r3, #0x4 */
/* @0x2163bc cmp r0, r3 */
/* @0x2163c0 ble 0x2163f4 <_Z14Audio_GetSoundi+0xc8> */
/* @0x2163c4 ldr r2, [pc, #0x80] */
/* @0x2163c8 movw r3, #0x6c21 */
/* @0x2163cc movt r3, #0xfffb */
/* @0x2163d0 ldr r2, [pc, r2] */
/* @0x2163d4 add r3, r0, r3 */
/* @0x2163d8 ldr r1, [r2] */
/* @0x2163dc cmp r3, r1 */
/* @0x2163e0 bgt 0x2163f4 <_Z14Audio_GetSoundi+0xc8> */
/* @0x2163e4 sub r0, r0, #299008 */
/* @0x2163e8 sub r0, r0, #992 */
/* @0x2163ec cmp r1, r0 */
/* @0x2163f0 bgt 0x216428 <_Z14Audio_GetSoundi+0xfc> */
/* @0x2163f4 mov r0, #0 */
/* @0x2163f8 bx lr */
/* @0x2163fc bge 0x2163f4 <_Z14Audio_GetSoundi+0xc8> */
/* @0x216400 ldr r3, [r3, #0x24] */
/* @0x216404 ldr r0, [r3, r0, lsl #2] */
/* @0x216408 bx lr */
/* @0x21640c sub r0, r0, #99328 */
/* @0x216410 sub r0, r0, #672 */
/* @0x216414 cmp r1, r0 */
/* @0x216418 ble 0x2163f4 <_Z14Audio_GetSoundi+0xc8> */
/* @0x21641c ldr r3, [r3, #0x2c] */
/* @0x216420 ldr r0, [r3, r0, lsl #2] */
/* @0x216424 bx lr */
/* @0x216428 ldr r3, [r2, #0x4] */
/* @0x21642c ldr r0, [r3, r0, lsl #2] */
/* @0x216430 cmp r0, #0 */
/* @0x216434 bxeq lr */
/* @0x216438 ldrb r3, [r0, #0x27] */
/* @0x21643c cmp r3, #0 */
/* @0x216440 movne r0, #0 */
/* @0x216444 bx lr */
/* @0x216448 subseq lr, r3, r12, asr pc */
/* @0x21644c andseq r11, sp, r8 */

/* ── FUNC 0x216450 · Audio_NoiseIsPaused(CNoise*) · size=108 · insn=27 */
/* @0x216450 cmp r0, #0 */
/* @0x216454 push {r4, lr} */
/* @0x216458 sub sp, sp, #8 */
/* @0x21645c beq 0x2164a8 <_Z19Audio_NoiseIsPausedP6CNoise+0x58> */
/* @0x216460 ldrb r4, [r0, #0x5] */
/* @0x216464 cmp r4, #0 */
/* @0x216468 beq 0x21649c <_Z19Audio_NoiseIsPausedP6CNoise+0x4c> */
/* @0x21646c ldr r3, [pc, #0x44] */
/* @0x216470 add r2, sp, #4 */
/* @0x216474 ldr r0, [r0, #0x10] */
/* @0x216478 movw r1, #0x1010 */
/* @0x21647c ldr r3, [pc, r3] */
/* @0x216480 ldr r3, [r3] */
/* @0x216484 ldr r0, [r3, r0, lsl #2] */
/* @0x216488 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x21648c ldr r2, [sp, #0x4] */
/* @0x216490 movw r3, #0x1013 */
/* @0x216494 cmp r2, r3 */
/* @0x216498 movne r4, #0 */
/* @0x21649c mov r0, r4 */
/* @0x2164a0 add sp, sp, #8 */
/* @0x2164a4 pop {r4, pc} */
/* @0x2164a8 mov r4, r0 */
/* @0x2164ac mov r0, r4 */
/* @0x2164b0 add sp, sp, #8 */
/* @0x2164b4 pop {r4, pc} */
/* @0x2164b8 andseq r10, sp, r0, asr pc */

/* ── FUNC 0x2164bc · Audio_NoiseIsPlaying(CNoise*) · size=164 · insn=41 */
/* @0x2164bc push {r4, r5, lr} */
/* @0x2164c0 subs r5, r0, #0 */
/* @0x2164c4 sub sp, sp, #12 */
/* @0x2164c8 beq 0x21654c <_Z20Audio_NoiseIsPlayingP6CNoise+0x90> */
/* @0x2164cc ldrb r4, [r5, #0x5] */
/* @0x2164d0 cmp r4, #0 */
/* @0x2164d4 bne 0x2164e4 <_Z20Audio_NoiseIsPlayingP6CNoise+0x28> */
/* @0x2164d8 mov r0, r4 */
/* @0x2164dc add sp, sp, #12 */
/* @0x2164e0 pop {r4, r5, pc} */
/* @0x2164e4 ldr r0, [r5, #0x18] */
/* @0x2164e8 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x2164ec ldrb r3, [r0, #0x24] */
/* @0x2164f0 cmp r3, #0 */
/* @0x2164f4 bne 0x21653c <_Z20Audio_NoiseIsPlayingP6CNoise+0x80> */
/* @0x2164f8 ldrb r3, [r0, #0x25] */
/* @0x2164fc cmp r3, #0 */
/* @0x216500 bne 0x21653c <_Z20Audio_NoiseIsPlayingP6CNoise+0x80> */
/* @0x216504 ldr r3, [pc, #0x50] */
/* @0x216508 movw r1, #0x1010 */
/* @0x21650c ldr r0, [r5, #0x10] */
/* @0x216510 add r2, sp, #4 */
/* @0x216514 ldr r3, [pc, r3] */
/* @0x216518 ldr r3, [r3] */
/* @0x21651c ldr r0, [r3, r0, lsl #2] */
/* @0x216520 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x216524 ldr r3, [sp, #0x4] */
/* @0x216528 sub r3, r3, #4096 */
/* @0x21652c sub r3, r3, #18 */
/* @0x216530 cmp r3, #1 */
/* @0x216534 movhi r4, #0 */
/* @0x216538 b 0x2164d8 <_Z20Audio_NoiseIsPlayingP6CNoise+0x1c> */
/* @0x21653c mov r4, r3 */
/* @0x216540 mov r0, r4 */
/* @0x216544 add sp, sp, #12 */
/* @0x216548 pop {r4, r5, pc} */
/* @0x21654c mov r4, r5 */
/* @0x216550 mov r0, r4 */
/* @0x216554 add sp, sp, #12 */
/* @0x216558 pop {r4, r5, pc} */
/* @0x21655c ldrheq r10, [sp], -r8 */
