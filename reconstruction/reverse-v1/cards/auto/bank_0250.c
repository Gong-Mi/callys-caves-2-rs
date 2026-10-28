/* libyoyo.so 覆盖卡组 0250
 * 函数 0x2a297c..0x2a434f，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2a297c · InitGMLFunctions() · size=684 · insn=171 */
/* @0x2a297c ldr r3, [pc, #0x250] */
/* @0x2a2980 push {r4, lr} */
/* @0x2a2984 ldr r3, [pc, r3] */
/* @0x2a2988 ldr r1, [pc, #0x248] */
/* @0x2a298c ldr r4, [r3] */
/* @0x2a2990 add r1, pc, r1 */
/* @0x2a2994 ldr r3, [r4] */
/* @0x2a2998 mov r0, r4 */
/* @0x2a299c ldr r3, [r3, #0xc] */
/* @0x2a29a0 blx r3 */
/* @0x2a29a4 bl 0x1dc600 <_Z18HighScore_InitLoadv> */
/* @0x2a29a8 ldr r3, [r4] */
/* @0x2a29ac ldr r1, [pc, #0x228] */
/* @0x2a29b0 mov r0, r4 */
/* @0x2a29b4 add r1, pc, r1 */
/* @0x2a29b8 ldr r3, [r3, #0xc] */
/* @0x2a29bc blx r3 */
/* @0x2a29c0 bl 0x10c7d8 <_Z17InitGameFunctionsv> */
/* @0x2a29c4 ldr r3, [r4] */
/* @0x2a29c8 ldr r1, [pc, #0x210] */
/* @0x2a29cc mov r0, r4 */
/* @0x2a29d0 add r1, pc, r1 */
/* @0x2a29d4 ldr r3, [r3, #0xc] */
/* @0x2a29d8 blx r3 */
/* @0x2a29dc bl 0x111c5c <_Z17InitMathFunctionsv> */
/* @0x2a29e0 ldr r3, [r4] */
/* @0x2a29e4 ldr r1, [pc, #0x1f8] */
/* @0x2a29e8 mov r0, r4 */
/* @0x2a29ec add r1, pc, r1 */
/* @0x2a29f0 ldr r3, [r3, #0xc] */
/* @0x2a29f4 blx r3 */
/* @0x2a29f8 bl 0x12326c <_Z20InitGraphicFunctionsv> */
/* @0x2a29fc ldr r3, [r4] */
/* @0x2a2a00 ldr r1, [pc, #0x1e0] */
/* @0x2a2a04 mov r0, r4 */
/* @0x2a2a08 add r1, pc, r1 */
/* @0x2a2a0c ldr r3, [r3, #0xc] */
/* @0x2a2a10 blx r3 */
/* @0x2a2a14 bl 0x141e60 <_Z19InitActionFunctionsv> */
/* @0x2a2a18 ldr r3, [r4] */
/* @0x2a2a1c ldr r1, [pc, #0x1c8] */
/* @0x2a2a20 mov r0, r4 */
/* @0x2a2a24 add r1, pc, r1 */
/* @0x2a2a28 ldr r3, [r3, #0xc] */
/* @0x2a2a2c blx r3 */
/* @0x2a2a30 bl 0x13c4a0 <_Z17InitFileFunctionsv> */
/* @0x2a2a34 ldr r3, [r4] */
/* @0x2a2a38 ldr r1, [pc, #0x1b0] */
/* @0x2a2a3c mov r0, r4 */
/* @0x2a2a40 add r1, pc, r1 */
/* @0x2a2a44 ldr r3, [r3, #0xc] */
/* @0x2a2a48 blx r3 */
/* @0x2a2a4c bl 0x130ffc <_Z21InitResourceFunctionsv> */
/* @0x2a2a50 ldr r3, [r4] */
/* @0x2a2a54 ldr r1, [pc, #0x198] */
/* @0x2a2a58 mov r0, r4 */
/* @0x2a2a5c add r1, pc, r1 */
/* @0x2a2a60 ldr r3, [r3, #0xc] */
/* @0x2a2a64 blx r3 */
/* @0x2a2a68 bl 0x1278c4 <_Z24InitInteractionFunctionsv> */
/* @0x2a2a6c ldr r3, [r4] */
/* @0x2a2a70 ldr r1, [pc, #0x180] */
/* @0x2a2a74 mov r0, r4 */
/* @0x2a2a78 add r1, pc, r1 */
/* @0x2a2a7c ldr r3, [r3, #0xc] */
/* @0x2a2a80 blx r3 */
/* @0x2a2a84 bl 0x149f4c <_Z15Init3DFunctionsv> */
/* @0x2a2a88 ldr r3, [r4] */
/* @0x2a2a8c ldr r1, [pc, #0x168] */
/* @0x2a2a90 mov r0, r4 */
/* @0x2a2a94 add r1, pc, r1 */
/* @0x2a2a98 ldr r3, [r3, #0xc] */
/* @0x2a2a9c blx r3 */
/* @0x2a2aa0 bl 0x129f74 <_Z22InitParticlesFunctionsv> */
/* @0x2a2aa4 ldr r3, [r4] */
/* @0x2a2aa8 ldr r1, [pc, #0x150] */
/* @0x2a2aac mov r0, r4 */
/* @0x2a2ab0 add r1, pc, r1 */
/* @0x2a2ab4 ldr r3, [r3, #0xc] */
/* @0x2a2ab8 blx r3 */
/* @0x2a2abc bl 0x118720 <_Z17InitMiscFunctionsv> */
/* @0x2a2ac0 ldr r3, [r4] */
/* @0x2a2ac4 ldr r1, [pc, #0x138] */
/* @0x2a2ac8 mov r0, r4 */
/* @0x2a2acc add r1, pc, r1 */
/* @0x2a2ad0 ldr r3, [r3, #0xc] */
/* @0x2a2ad4 blx r3 */
/* @0x2a2ad8 bl 0x10057c <_Z27InitDataStructuresFunctionsv> */
/* @0x2a2adc ldr r3, [r4] */
/* @0x2a2ae0 ldr r1, [pc, #0x120] */
/* @0x2a2ae4 mov r0, r4 */
/* @0x2a2ae8 add r1, pc, r1 */
/* @0x2a2aec ldr r3, [r3, #0xc] */
/* @0x2a2af0 blx r3 */
/* @0x2a2af4 bl 0x13672c <_Z18InitSoundFunctionsv> */
/* @0x2a2af8 ldr r3, [r4] */
/* @0x2a2afc ldr r1, [pc, #0x108] */
/* @0x2a2b00 mov r0, r4 */
/* @0x2a2b04 add r1, pc, r1 */
/* @0x2a2b08 ldr r3, [r3, #0xc] */
/* @0x2a2b0c blx r3 */
/* @0x2a2b10 bl 0x150434 <InitPhysicsFunctions> */
/* @0x2a2b14 ldr r3, [r4] */
/* @0x2a2b18 ldr r1, [pc, #0xf0] */
/* @0x2a2b1c mov r0, r4 */
/* @0x2a2b20 add r1, pc, r1 */
/* @0x2a2b24 ldr r3, [r3, #0xc] */
/* @0x2a2b28 blx r3 */
/* @0x2a2b2c bl 0x152c9c <_Z20InitGamepadFunctionsv> */
/* @0x2a2b30 ldr r3, [r4] */
/* @0x2a2b34 ldr r1, [pc, #0xd8] */
/* @0x2a2b38 mov r0, r4 */
/* @0x2a2b3c add r1, pc, r1 */
/* @0x2a2b40 ldr r3, [r3, #0xc] */
/* @0x2a2b44 blx r3 */
/* @0x2a2b48 bl 0xc75fc <_Z19InitBufferFunctionsv> */
/* @0x2a2b4c bl 0xca9a0 <_Z25InitBufferVertexFunctionsv> */
/* @0x2a2b50 ldr r3, [r4] */
/* @0x2a2b54 ldr r1, [pc, #0xbc] */
/* @0x2a2b58 mov r0, r4 */
/* @0x2a2b5c add r1, pc, r1 */
/* @0x2a2b60 ldr r3, [r3, #0xc] */
/* @0x2a2b64 blx r3 */
/* @0x2a2b68 bl 0x299684 <_Z23InitNetworkingFunctionsv> */
/* @0x2a2b6c ldr r3, [r4] */
/* @0x2a2b70 ldr r1, [pc, #0xa4] */
/* @0x2a2b74 mov r0, r4 */
/* @0x2a2b78 add r1, pc, r1 */
/* @0x2a2b7c ldr r3, [r3, #0xc] */
/* @0x2a2b80 blx r3 */
/* @0x2a2b84 bl 0x1e2184 <_Z19InitShaderFunctionsv> */
/* @0x2a2b88 bl 0x1e2fe8 <_Z17InitVertexFormatsv> */
/* @0x2a2b8c bl 0x16258c <_Z18InitSteamFunctionsv> */
/* @0x2a2b90 bl 0x155ea0 <_Z17InitPushFunctionsv> */
/* @0x2a2b94 ldr r3, [r4] */
/* @0x2a2b98 ldr r1, [pc, #0x80] */
/* @0x2a2b9c mov r0, r4 */
/* @0x2a2ba0 add r1, pc, r1 */
/* @0x2a2ba4 ldr r3, [r3, #0xc] */
/* @0x2a2ba8 blx r3 */
/* @0x2a2bac bl 0x15a0d0 <_Z17InitYoYoFunctionsv> */
/* @0x2a2bb0 bl 0x128b58 <_Z18InitMetroFunctionsv> */
/* @0x2a2bb4 bl 0x1c1540 <_ZN13CLayerManager18InitLayerFunctionsEv> */
/* @0x2a2bb8 ldr r3, [r4] */
/* @0x2a2bbc ldr r1, [pc, #0x60] */
/* @0x2a2bc0 mov r0, r4 */
/* @0x2a2bc4 add r1, pc, r1 */
/* @0x2a2bc8 ldr r3, [r3, #0xc] */
/* @0x2a2bcc blx r3 */
/* @0x2a2bd0 pop {r4, pc} */
/* @0x2a2bd4 mulseq r4, r8, r1 */
/* @0x2a2bd8 andeq r7, r11, r4, lsl r10 */
/* @0x2a2bdc strdeq r7, r8, [r11], -r12 */
/* @0x2a2be0 andeq r7, r11, r8, ror #19 */
/* @0x2a2be4 ldrdeq r7, r8, [r11], -r4 */
/* @0x2a2be8 andeq r7, r11, r4, asr #19 */
/* @0x2a2bec strheq r7, [r11], -r4 */
/* @0x2a2bf0 andeq r7, r11, r0, lsr #19 */
/* @0x2a2bf4 muleq r11, r0, r9 */
/* @0x2a2bf8 andeq r7, r11, r4, lsl #19 */
/* @0x2a2bfc andeq r7, r11, r0, ror r9 */
/* @0x2a2c00 andeq r7, r11, r0, ror #18 */
/* @0x2a2c04 andeq r7, r11, r12, asr #18 */
/* @0x2a2c08 andeq r7, r11, r8, lsr r9 */
/* @0x2a2c0c andeq r7, r11, r4, lsr #18 */
/* @0x2a2c10 andeq r7, r11, r4, lsl r9 */
/* @0x2a2c14 andeq r7, r11, r4, lsl #18 */
/* @0x2a2c18 strdeq r7, r8, [r11], -r0 */
/* @0x2a2c1c andeq r7, r11, r4, ror #17 */
/* @0x2a2c20 andeq r7, r11, r8, asr #17 */
/* @0x2a2c24 andeq r7, r11, r12, lsr #17 */

/* ── FUNC 0x2a2c28 · SetLaunchedFromPlayer(char const*, bool) · size=20 · insn=5 */
/* @0x2a2c28 ldr r3, [pc, #0x8] */
/* @0x2a2c2c ldr r3, [pc, r3] */
/* @0x2a2c30 strb r1, [r3] */
/* @0x2a2c34 b 0x15f61c <_Z28SetAndroidLaunchedFromPlayerPKcb> */
/* @0x2a2c38 andseq r11, r4, r4 */

/* ── FUNC 0x2a2c3c · RunGame() · size=560 · insn=140 */
/* @0x2a2c3c push {r4, r5, r6, r7, r8, lr} */
/* @0x2a2c40 sub sp, sp, #8 */
/* @0x2a2c44 ldr r4, [pc, #0x1e0] */
/* @0x2a2c48 ldr r3, [pc, #0x1e0] */
/* @0x2a2c4c add r4, pc, r4 */
/* @0x2a2c50 ldr r5, [r4, r3] */
/* @0x2a2c54 ldr r6, [r5] */
/* @0x2a2c58 cmp r6, #0 */
/* @0x2a2c5c beq 0x2a2d3c <_Z7RunGamev+0x100> */
/* @0x2a2c60 ldr r3, [pc, #0x1cc] */
/* @0x2a2c64 ldr r6, [r4, r3] */
/* @0x2a2c68 ldr r0, [r6] */
/* @0x2a2c6c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a2c70 ldr r1, [pc, #0x1c0] */
/* @0x2a2c74 mov r3, #1 */
/* @0x2a2c78 mov r0, #4096 */
/* @0x2a2c7c add r1, pc, r1 */
/* @0x2a2c80 movw r2, #0x38a */
/* @0x2a2c84 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2a2c88 ldr r3, [pc, #0x1ac] */
/* @0x2a2c8c str r0, [r6] */
/* @0x2a2c90 ldr r6, [r4, r3] */
/* @0x2a2c94 ldr r12, [r6] */
/* @0x2a2c98 cmp r12, #0 */
/* @0x2a2c9c beq 0x2a2e14 <_Z7RunGamev+0x1d8> */
/* @0x2a2ca0 ldr r7, [pc, #0x198] */
/* @0x2a2ca4 mov r1, #4096 */
/* @0x2a2ca8 ldr r3, [r5] */
/* @0x2a2cac add r7, pc, r7 */
/* @0x2a2cb0 str r12, [sp] */
/* @0x2a2cb4 mov r2, r7 */
/* @0x2a2cb8 bl 0xb65c8 <snprintf@plt> */
/* @0x2a2cbc ldr r1, [r5] */
/* @0x2a2cc0 mov r0, r7 */
/* @0x2a2cc4 ldr r2, [r6] */
/* @0x2a2cc8 bl 0xb6964 <printf@plt> */
/* @0x2a2ccc ldr r0, [r5] */
/* @0x2a2cd0 mov r1, #1 */
/* @0x2a2cd4 bl 0x2a2c28 <_Z21SetLaunchedFromPlayerPKcb> */
/* @0x2a2cd8 ldr r3, [pc, #0x164] */
/* @0x2a2cdc mov r2, #1 */
/* @0x2a2ce0 ldr r0, [r5] */
/* @0x2a2ce4 ldr r3, [r4, r3] */
/* @0x2a2ce8 strb r2, [r3] */
/* @0x2a2cec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a2cf0 ldr r0, [r6] */
/* @0x2a2cf4 cmp r0, #0 */
/* @0x2a2cf8 beq 0x2a2d00 <_Z7RunGamev+0xc4> */
/* @0x2a2cfc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a2d00 ldr r3, [pc, #0x140] */
/* @0x2a2d04 mov r7, #0 */
/* @0x2a2d08 str r7, [r5] */
/* @0x2a2d0c str r7, [r6] */
/* @0x2a2d10 ldr r5, [r4, r3] */
/* @0x2a2d14 ldr r0, [r5] */
/* @0x2a2d18 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a2d1c ldr r3, [pc, #0x128] */
/* @0x2a2d20 str r7, [r5] */
/* @0x2a2d24 ldr r3, [r4, r3] */
/* @0x2a2d28 ldr r0, [r3] */
/* @0x2a2d2c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x2a2d30 str r0, [r5] */
/* @0x2a2d34 add sp, sp, #8 */
/* @0x2a2d38 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2a2d3c ldr r3, [pc, #0x10c] */
/* @0x2a2d40 ldr r5, [r4, r3] */
/* @0x2a2d44 ldr r3, [r5] */
/* @0x2a2d48 cmp r3, #0 */
/* @0x2a2d4c beq 0x2a2d34 <_Z7RunGamev+0xf8> */
/* @0x2a2d50 ldr r2, [pc, #0xfc] */
/* @0x2a2d54 ldr r3, [pc, #0xd8] */
/* @0x2a2d58 ldr r7, [pc, #0xf8] */
/* @0x2a2d5c ldr r2, [r4, r2] */
/* @0x2a2d60 add r7, pc, r7 */
/* @0x2a2d64 strb r6, [r2] */
/* @0x2a2d68 ldr r8, [r4, r3] */
/* @0x2a2d6c ldr r0, [r8] */
/* @0x2a2d70 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a2d74 ldr r1, [pc, #0xe0] */
/* @0x2a2d78 mov r2, #948 */
/* @0x2a2d7c mov r3, #1 */
/* @0x2a2d80 add r1, pc, r1 */
/* @0x2a2d84 mov r0, #4096 */
/* @0x2a2d88 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2a2d8c ldr r2, [pc, #0xcc] */
/* @0x2a2d90 ldr r3, [r5] */
/* @0x2a2d94 mov r1, #4096 */
/* @0x2a2d98 add r2, pc, r2 */
/* @0x2a2d9c str r0, [r8] */
/* @0x2a2da0 bl 0xb65c8 <snprintf@plt> */
/* @0x2a2da4 mov r1, r6 */
/* @0x2a2da8 mov r0, r7 */
/* @0x2a2dac bl 0x2a2c28 <_Z21SetLaunchedFromPlayerPKcb> */
/* @0x2a2db0 ldr r3, [pc, #0x8c] */
/* @0x2a2db4 ldr r0, [r5] */
/* @0x2a2db8 mov r2, #1 */
/* @0x2a2dbc ldr r3, [r4, r3] */
/* @0x2a2dc0 strb r2, [r3] */
/* @0x2a2dc4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a2dc8 ldr r3, [pc, #0x78] */
/* @0x2a2dcc str r6, [r5] */
/* @0x2a2dd0 ldr r5, [r4, r3] */
/* @0x2a2dd4 ldr r0, [r5] */
/* @0x2a2dd8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a2ddc mov r0, r7 */
/* @0x2a2de0 str r6, [r5] */
/* @0x2a2de4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x2a2de8 ldr r3, [pc, #0x74] */
/* @0x2a2dec str r0, [r5] */
/* @0x2a2df0 ldr r4, [r4, r3] */
/* @0x2a2df4 ldr r0, [r4] */
/* @0x2a2df8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a2dfc mov r0, r7 */
/* @0x2a2e00 str r6, [r4] */
/* @0x2a2e04 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x2a2e08 str r0, [r4] */
/* @0x2a2e0c add sp, sp, #8 */
/* @0x2a2e10 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2a2e14 ldr r2, [pc, #0x4c] */
/* @0x2a2e18 mov r1, #4096 */
/* @0x2a2e1c ldr r3, [r5] */
/* @0x2a2e20 add r2, pc, r2 */
/* @0x2a2e24 bl 0xb65c8 <snprintf@plt> */
/* @0x2a2e28 b 0x2a2cd8 <_Z7RunGamev+0x9c> */
/* @0x2a2e2c andseq pc, r4, r4 */
/* @0x2a2e30 .word 0xffffdf58 */
/* @0x2a2e34 .word 0xfffffd10 */
/* @0x2a2e38 andeq r7, r11, r4, ror #11 */
/* @0x2a2e3c .word 0xffffdf60 */
/* @0x2a2e40 ldrdeq r7, r8, [r11], -r8 */
/* @0x2a2e44 .word 0xfffffcf0 */
/* @0x2a2e48 .word 0xfffffcc4 */
/* @0x2a2e4c .word 0xffffdf54 */
/* @0x2a2e50 .word 0xfffffde0 */
/* @0x2a2e54 .word 0xffffc140 */
/* @0x2a2e58 ldrdeq r11, r12, [r8], -r6 */
/* @0x2a2e5c andeq r7, r11, r0, ror #9 */
/* @0x2a2e60 andeq r7, r11, r0, ror #13 */
/* @0x2a2e64 .word 0xffffef18 */
/* @0x2a2e68 andeq r7, r11, r8, asr r6 */

/* ── FUNC 0x2a2e6c · anon_2a2e6c · size=36 · insn=9 */
/* @0x2a2e6c ldr r1, [pc, #0x18] */
/* @0x2a2e70 mov r0, #0 */
/* @0x2a2e74 mov r2, #0 */
/* @0x2a2e78 mov r3, #0 */
/* @0x2a2e7c add r1, pc, r1 */
/* @0x2a2e80 str r0, [r1] */
/* @0x2a2e84 strd r2, r3, [r1, #8] */
/* @0x2a2e88 bx lr */
/* @0x2a2e8c subeq r6, r11, r4, asr r2 */

/* ── FUNC 0x2a2e90 · android_getCpuFamily · size=44 · insn=11 */
/* @0x2a2e90 push {r4, lr} */
/* @0x2a2e94 ldr r4, [pc, #0x18] */
/* @0x2a2e98 ldr r1, [pc, #0x18] */
/* @0x2a2e9c add r4, pc, r4 */
/* @0x2a2ea0 add r1, pc, r1 */
/* @0x2a2ea4 add r0, r4, #16 */
/* @0x2a2ea8 bl 0xb6e98 <pthread_once@plt> */
/* @0x2a2eac ldr r0, [r4] */
/* @0x2a2eb0 pop {r4, pc} */
/* @0x2a2eb4 subeq r6, r11, r4, lsr r2 */
/* @0x2a2eb8 .word 0xffffffc4 */

/* ── FUNC 0x2a2ebc · android_getCpuFeatures · size=44 · insn=11 */
/* @0x2a2ebc push {r4, lr} */
/* @0x2a2ec0 ldr r4, [pc, #0x18] */
/* @0x2a2ec4 ldr r1, [pc, #0x18] */
/* @0x2a2ec8 add r4, pc, r4 */
/* @0x2a2ecc add r1, pc, r1 */
/* @0x2a2ed0 add r0, r4, #16 */
/* @0x2a2ed4 bl 0xb6e98 <pthread_once@plt> */
/* @0x2a2ed8 ldrd r0, r1, [r4, #8] */
/* @0x2a2edc pop {r4, pc} */
/* @0x2a2ee0 subeq r6, r11, r8, lsl #4 */
/* @0x2a2ee4 .word 0xffffff98 */

/* ── FUNC 0x2a2ee8 · anon_2a2ee8 · size=3176 · insn=794 */
/* @0x2a2ee8 movwhs r11, #0x4537 */
/* @0x2a2eec strmi r4, [r4], -sp, lsl #12 */
/* @0x2a2ef0 ldrmi r4, [r0], -r9, ror #12 */
/* @0x2a2ef4 strmi r2, [r8, r8, lsl #4]! */
/* @0x2a2ef8 .word 0xdc032807 */
/* @0x2a2efc eorvs r2, r3, r4, lsl r3 */
/* @0x2a2f00 and r2, r2, r0, lsl #6 */
/* @0x2a2f04 eorvs r9, r3, r0, lsl #22 */
/* @0x2a2f08 rsbvs r9, r3, r1, lsl #22 */
/* @0x2a2f0c ldclt p0, c11, [r0, #-12]! */
/* @0x2a2f10 stmdavs r9, {r6, r11, sp, lr} ^ */
/* @0x2a2f14 stcllt p0, c15, [r2, #480] */
/* @0x2a2f18 svcmi #0xf0e92d */
/* @0x2a2f1c stcmi p5, c15, [r0, #692] */
/* @0x2a2f20 mrrcmi p0, #0x9, r11, lr, c11 */
/* @0x2a2f24 strmi pc, [r1, sp, lsl #10] */
/* @0x2a2f28 .word 0x3710461d */
/* @0x2a2f2c stmdavs r4!, {r2, r3, r4, r5, r6, r10, lr} */
/* @0x2a2f30 .word 0xf50d9107 */
/* @0x2a2f34 ldmdavs pc!, {r7, r8, lr} */
/* @0x2a2f38 stmdavs r3!, {r2, r5, r6, r8, r12, sp} */
/* @0x2a2f3c stmdaeq r8, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2a2f40 .word 0xf8a54606 */
/* @0x2a2f44 smladls r8, r8, r0, r8 */
/* @0x2a2f48 andvs r2, r11, r0, lsl #14 */
/* @0x2a2f4c shadd8mi r4, r9, r3 */
/* @0x2a2f50 .word 0x612f463a */
/* @0x2a2f54 .word 0x616f4638 */
/* @0x2a2f58 stmdbeq r8!, {r0, r2, r3, r8, r12, sp, lr, pc} ^ */
/* @0x2a2f5c svc #0xa2f613 */
/* @0x2a2f60 ldrtmi r2, [r10], -r1, lsl #2 */
/* @0x2a2f64 .word 0x97149713 */
/* @0x2a2f68 smladls r12, r5, r7, r9 */
/* @0x2a2f6c adcvs r9, r8, pc, lsl #14 */
/* @0x2a2f70 .word 0xf0014630 */
/* @0x2a2f74 strls pc, [r9], #-3267 */
/* @0x2a2f78 .word 0xf1a94b49 */
/* @0x2a2f7c .word 0x4642043c */
/* @0x2a2f80 ldrbtmi r2, [r11], #-265 */
/* @0x2a2f84 teqhs r8, #134217728 */
/* @0x2a2f88 .word 0xf06f9303 */
/* @0x2a2f8c adcsmi r0, r8, #939524096 */
/* @0x2a2f90 andhs r11, r9, r12, lsl #30 */
/* @0x2a2f94 .word 0xf50d4640 */
/* @0x2a2f98 stm sp, {r0, r11, r12, lr} */
/* @0x2a2f9c strtmi r0, [r0], -r1, lsl #1 */
/* @0x2a2fa0 svc #0x86f613 */
/* @0x2a2fa4 stmdaeq r4!, {r3, r8, r12, sp, lr, pc} */
/* @0x2a2fa8 movwpl pc, #0x44f */
/* @0x2a2fac ldchi p8, c15, [r0], #-292 */
/* @0x2a2fb0 stclo p8, c15, [r12], #-292 */
/* @0x2a2fb4 ldcvc p8, c15, [r12], #-292 */
/* @0x2a2fb8 ldcvc p8, c15, [r8], #-292 */
/* @0x2a2fbc stmdbeq r4, {r0, r3, r5, r7, r8, r12, sp, lr, pc} */
/* @0x2a2fc0 stmdavs r3!, {r0, r2, r8, r9, r10, r12, pc} ^ */
/* @0x2a2fc4 svcls #0x5bb1b */
/* @0x2a2fc8 .word 0xf44fbb0f */
/* @0x2a2fcc ldrbmi r5, [r8], -r0, lsl #4 */
/* @0x2a2fd0 movwhs r4, #0x1649 */
/* @0x2a2fd4 ldrmi r9, [r8, r7, lsl #30]! */
/* @0x2a2fd8 ble 0x4ea7e8 <SrcVerts+0x4782c> */
/* @0x2a2fdc andeq pc, r12, r6, lsl #2 */
/* @0x2a2fe0 ldrbmi r9, [r10], -r7, lsl #18 */
/* @0x2a2fe4 .word 0xff80f7ff */
/* @0x2a2fe8 .word 0xf6134620 */
/* @0x2a2fec ands lr, r11, r6, ror #25 */
/* @0x2a2ff0 stmdbvs r11!, {r0, r1, r3, r12, lr, pc} */
/* @0x2a2ff4 stmvs r8!, {r0, r3, r6, r9, r10, lr} */
/* @0x2a2ff8 .word 0x612b4413 */
/* @0x2a2ffc .word 0xf8c46062 */
/* @0x2a3000 .word 0xf6139000 */
/* @0x2a3004 adcvs lr, r8, r0, asr pc */
/* @0x2a3008 strhs lr, [r4, -r1] */
/* @0x2a300c strtmi r9, [r0], -r5, lsl #14 */
/* @0x2a3010 .word 0xf6139905 */
/* @0x2a3014 stmdahs r1, {r2, r3, r6, r7, r10, r11, sp, lr, pc} */
/* @0x2a3018 stmdble r8, {r1, r7, r9, r10, lr} */
/* @0x2a301c andeq pc, r12, r6, lsl #2 */
/* @0x2a3020 ldrbmi r2, [r2], -sp, lsl #2 */
/* @0x2a3024 .word 0xf998f001 */
/* @0x2a3028 rscslo pc, pc, pc, asr #32 */
/* @0x2a302c stmdbvs r3!, {r0, r1, r2, r5, sp, lr, pc} */
/* @0x2a3030 svcpl #0xf5b3 */
/* @0x2a3034 .word 0xf5c3d01c */
/* @0x2a3038 strbmi r5, [r0], -r0, lsl #24 */
/* @0x2a303c blls 0x4ab448 <SrcVerts+0x848c> */
/* @0x2a3040 .word 0xf8cd4662 */
/* @0x2a3044 .word 0xf613c018 */
/* @0x2a3048 .word 0xf8ddec3a */
/* @0x2a304c strbmi r12, [r0, #-0x18]! */
/* @0x2a3050 .word 0xf613d006 */
/* @0x2a3054 ldrdhs lr, pc, [r6, -r2] */
/* @0x2a3058 .word 0xf1066802 */
/* @0x2a305c strb r0, [r1, r12]! */
/* @0x2a3060 vst2.16 {d22, d24}, [pc:128], r11 */
/* @0x2a3064 .word 0xf8c45100 */
/* @0x2a3068 ldrmi r8, [r8], #-12 */
/* @0x2a306c .word 0x61686121 */
/* @0x2a3070 svceq #0x1f1ba */
/* @0x2a3074 strtmi sp, [r0], -r5, lsr #3 */
/* @0x2a3078 ldc p6, c15, [lr], {19} */
/* @0x2a307c .word 0xf50d2000 */
/* @0x2a3080 svcls #0x94380 */
/* @0x2a3084 ldmdavs r10, {r2, r5, r6, r8, r9, r12, sp} */
/* @0x2a3088 addsmi r6, r10, #3866624 */
/* @0x2a308c .word 0xf613d001 */
/* @0x2a3090 .word 0xf50deaa2 */
/* @0x2a3094 andslt r4, r11, r0, lsl #27 */
/* @0x2a3098 svchi #0xf0e8bd */
/* @0x2a309c andseq r10, r4, r8, lsr #20 */
/* @0x2a30a0 andeq r9, lr, r6, asr #32 */
/* @0x2a30a4 svcmi #0xf0e92d */
/* @0x2a30a8 stcpl p5, c15, [r0, #-692] */
/* @0x2a30ac addlt r4, r3, r6, lsr #26 */
/* @0x2a30b0 sadd8mi r4, lr, r2 */
/* @0x2a30b4 stmdavs sp!, {r0, r2, r3, r4, r5, r6, r10, lr} */
/* @0x2a30b8 andpl pc, r0, #54525952 */
/* @0x2a30bc strmi r3, [r1], r4, lsl #4 */
/* @0x2a30c0 strmi r6, [r12], -r11, lsr #16 */
/* @0x2a30c4 teqlt r9, r3, lsl r0 */
/* @0x2a30c8 bleq 0x31f9d8 */
/* @0x2a30cc stmdaeq r4, {r0, r2, r3, r8, r12, sp, lr, pc} */
/* @0x2a30d0 bne 0xbdb0d8 <b2_toiTime+0x481c34> */
/* @0x2a30d4 .word 0xdc012c00 */
/* @0x2a30d8 eor r2, r7, r0 */
/* @0x2a30dc svclt #0x34455c */
/* @0x2a30e0 .word 0xf44f4622 */
/* @0x2a30e4 strbmi r5, [r0], -r0, lsl #4 */
/* @0x2a30e8 strbmi r2, [r11], -r1, lsl #2 */
/* @0x2a30ec bl 0xffde0940 <b2_toiTime+0xffffffffff68749c> */
/* @0x2a30f0 ble 0x3ea914 <af_cjk_writing_system_class+0x31c> */
/* @0x2a30f4 stc p6, c15, [r0, #76] */
/* @0x2a30f8 stmdavs r2, {r0, r2, r8, sp} */
/* @0x2a30fc ands r4, r1, r0, lsr r6 */
/* @0x2a3100 ldrtmi sp, [r0], -r3, lsl #2 */
/* @0x2a3104 shadd16mi r2, r10, r1 */
/* @0x2a3108 strbmi lr, [r0], -r12 */
/* @0x2a310c ldrtmi r2, [r10], -r1, lsl #2 */
/* @0x2a3110 .word 0xf6134653 */
/* @0x2a3114 adcsmi lr, r8, #212, #22 */
/* @0x2a3118 .word 0xf613d0db */
/* @0x2a311c .word 0x2106ed6e */
/* @0x2a3120 ldrtmi r6, [r0], -r2, lsl #16 */
/* @0x2a3124 .word 0xf918f001 */
/* @0x2a3128 rscslo pc, pc, pc, asr #32 */
/* @0x2a312c movwpl pc, #0x50d */
/* @0x2a3130 ldmdavs r10, {r2, r8, r9, r12, sp} */
/* @0x2a3134 addsmi r6, r10, #2818048 */
/* @0x2a3138 .word 0xf613d001 */
/* @0x2a313c .word 0xf50dea4c */
/* @0x2a3140 andlt r5, r3, r0, lsl #26 */
/* @0x2a3144 svchi #0xf0e8bd */
/* @0x2a3148 andseq r10, r4, r0, lsr #17 */
/* @0x2a314c svcmi #0xf0e92d */
/* @0x2a3150 stcpl p5, c15, [r0, #-692] */
/* @0x2a3154 stcmi p0, c11, [r4], #-524 */
/* @0x2a3158 .word 0xf50d4616 */
/* @0x2a315c eorslo r5, r0, #0, #4 */
/* @0x2a3160 stmdavs r4!, {r2, r3, r4, r5, r6, r10, lr} */
/* @0x2a3164 .word 0x9000f8d2 */
/* @0x2a3168 .word 0xf50d469a */
/* @0x2a316c stmdavs r3!, {r9, r12, lr} */
/* @0x2a3170 .word 0xf10d3204 */
/* @0x2a3174 strmi r0, [r0], r4, lsl #22 */
/* @0x2a3178 andsvs r4, r3, pc, lsl #12 */
/* @0x2a317c eorsvs r2, r3, r0, lsl #6 */
/* @0x2a3180 uasxmi r4, r9, r8 */
/* @0x2a3184 andpl pc, r0, #1325400064 */
/* @0x2a3188 strbmi r2, [r0, r1, lsl #6] */
/* @0x2a318c ldcle p14, c1, [r3, #-20] */
/* @0x2a3190 qaddhs r4, r8, r1 */
/* @0x2a3194 ldrbmi r4, [r3], -r10, lsr #12 */
/* @0x2a3198 bl 0xfe6e09ec <b2_toiTime+0xfffffffffdf87548> */
/* @0x2a319c andle r4, r7, r8, lsr #5 */
/* @0x2a31a0 stc p6, c15, [r10, #-76]! */
/* @0x2a31a4 stmdavs r2, {r1, r2, r8, sp} */
/* @0x2a31a8 .word 0xf0014648 */
/* @0x2a31ac .word 0xe00bf8d5 */
/* @0x2a31b0 ldrmi r6, [r8], #-2099 */
/* @0x2a31b4 .word 0xe7e36030 */
/* @0x2a31b8 strtmi r11, [r8], -r8, lsl #30 */
/* @0x2a31bc strbmi sp, [r8], -r6 */
/* @0x2a31c0 ldrtmi r4, [r10], -r1, asr #12 */
/* @0x2a31c4 mrc2 p7, #0x4, apsr_nzcv, c0, c15, #0x7 */
/* @0x2a31c8 rscslo pc, pc, pc, asr #32 */
/* @0x2a31cc movwpl pc, #0x50d */
/* @0x2a31d0 ldmdavs r10, {r2, r8, r9, r12, sp} */
/* @0x2a31d4 addsmi r6, r10, #2293760 */
/* @0x2a31d8 .word 0xf613d001 */
/* @0x2a31dc .word 0xf50de9fc */
/* @0x2a31e0 andlt r5, r3, r0, lsl #26 */
/* @0x2a31e4 svchi #0xf0e8bd */
/* @0x2a31e8 ldrsheq r10, [r4], -r4 */
/* @0x2a31ec .word 0x378cf8df */
/* @0x2a31f0 svcmi #0xf0e92d */
/* @0x2a31f4 ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr} */
/* @0x2a31f8 strmi r11, [r4], -r9, lsr #1 */
/* @0x2a31fc movwls r6, #0xc81a */
/* @0x2a3200 stmdahs r0, {r0, r1, r2, r5, r9, r12, pc} */
/* @0x2a3204 msrhi SPSR_fsc, #0 */
/* @0x2a3208 movwlo r6, #0x1a83 */
/* @0x2a320c stmibvs r2, {r0, r2, r8, r12, lr, pc} ^ */
/* @0x2a3210 bne 0xff77d824 <b2_toiTime+0xffffffffff024380> */
/* @0x2a3214 movwhs r11, #0x1f18 */
/* @0x2a3218 movwhs lr, #0x1000 */
/* @0x2a321c smlatths r0, r5, r10, r6 */
/* @0x2a3220 ldrhs r4, [r4], -r10, lsl #12 */
/* @0x2a3224 adcmi r9, r10, #-1073741823 */
/* @0x2a3228 blx 0x459a86 <g_RomDisk+0x62266> */
/* @0x2a322c blvs 0x1adf63c <b2_toiTime+0x1386198> */
/* @0x2a3230 stmdapl r1, {r0, r1, r2, r6, r11, r12} ^ */
/* @0x2a3234 ldmdbvs r9!, {r0, r3, r5, r8, r11, r12, sp, pc} */
/* @0x2a3238 svclo #0xfff1b1 */
/* @0x2a323c movwhs r11, #0x1f18 */
/* @0x2a3240 stmdbhs r1, {r1, sp, lr, pc} */
/* @0x2a3244 movwhs sp, #0x1004 */
/* @0x2a3248 mrslo r9, apsr */
/* @0x2a324c and r9, r0, r7, lsl #2 */
/* @0x2a3250 andlo r4, r1, #11534336 */
/* @0x2a3254 stmdblt r3!, {r0, r1, r2, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2a3258 strhs r4, [r0, #-0x620] */
/* @0x2a325c blx 0x75f26a <b2_toiTime+0x5dc6> */
/* @0x2a3260 bls 0x49c01c <TimingData+0x2004> */
/* @0x2a3264 stmdavs r0!, {r1, r5, r7, r8, r11, r12, sp, pc} */
/* @0x2a3268 rscsle r2, r5, r0, lsl #16 */
/* @0x2a326c ldmdblt r3, {r0, r1, r5, r6, r11, sp, lr} */
/* @0x2a3270 blhs 0x2bd504 <jpeg_alloc_huff_table+0xbfc> */
/* @0x2a3274 .word 0xf613d0f0 */
/* @0x2a3278 stmdahs r0, {r2, r3, r4, r5, r6, r8, r9, r11, sp, lr, pc} */
/* @0x2a327c .word 0xf613d0ec */
/* @0x2a3280 ldrhhs lr, [r6, -r12] */
/* @0x2a3284 .word 0xf1046802 */
/* @0x2a3288 .word 0xf001000c */
/* @0x2a328c msr APSR_nzcvq, #6619136 */
/* @0x2a3290 sbcseq r9, r8, r7, lsl #22 */
/* @0x2a3294 ldmdb r6, {r0, r1, r4, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2a3298 stmdahs r0, {r2, r12, pc} */
/* @0x2a329c msrhi CPSR_c, #0 */
/* @0x2a32a0 streq pc, [r12], -r4, lsl #2 */
/* @0x2a32a4 ldrtmi r9, [r1], -r7, lsl #16 */
/* @0x2a32a8 stc2l p0, c15, [lr], #-0 */
/* @0x2a32ac stmdahs r0, {r0, r2, r9, r10, lr} */
/* @0x2a32b0 cmphi lr, #0 */
/* @0x2a32b4 .word 0xf04f2700 */
/* @0x2a32b8 stmdavs r8!, {r2, r3, r4, r5, r11} */
/* @0x2a32bc andeq pc, r7, r8, lsl #22 */
/* @0x2a32c0 ldc2 p0, c15, [r4], #0 */
/* @0x2a32c4 strlo r9, [r1, -r7, lsl #18] */
/* @0x2a32c8 blle 0x33d0c */
/* @0x2a32cc .word 0x21014620 */
/* @0x2a32d0 .word 0xf0012200 */
/* @0x2a32d4 cmplt r0, r3, lsl r11 */
/* @0x2a32d8 ssateq pc, #0x5, pc, asr #17 */
/* @0x2a32dc shadd16mi r2, r2, r6 */
/* @0x2a32e0 .word 0xf0014478 */
/* @0x2a32e4 tsths r6, #74752 */
/* @0x2a32e8 bllt 0x4bb790 <SrcVerts+0x187d4> */
/* @0x2a32ec qasxmi lr, r0, sp */
/* @0x2a32f0 andhs r2, r8, #1073741824 */
/* @0x2a32f4 blx 0x35f302 <_ZTS12CDS_Priority+0x135a> */
/* @0x2a32f8 bvs 0xfeb11a60 <b2_toiTime+0xfffffffffe3b85bc> */
/* @0x2a32fc andle r1, r9, r8, asr #24 */
/* @0x2a3300 ldrtmi r6, [r2], -r0, ror #20 */
/* @0x2a3304 blx 0x10df312 <b2_toiTime+0x985e6e> */
/* @0x2a3308 stmdahs r0, {r3, r5, r8, sp, lr} */
/* @0x2a330c msrhi CPSR_fsc, #0 */
/* @0x2a3310 and r6, sp, r3, lsr #21 */
/* @0x2a3314 .word 0xb1636a23 */
/* @0x2a3318 cmplt r0, r8, lsl r9 */
/* @0x2a331c shadd8mi r8, r2, r9 */
/* @0x2a3320 blx 0xd5f32e <b2_toiTime+0x605e8a> */
/* @0x2a3324 stmdahs r0, {r3, r5, r8, sp, lr} */
/* @0x2a3328 tsthi pc, #0 */
/* @0x2a332c bhi 0xfe97dbc0 <b2_toiTime+0xfffffffffe22471c> */
/* @0x2a3330 stmdavs r7!, {r0, r1, r3, r5, r7, r9, pc} */
/* @0x2a3334 .word 0xf6134638 */
/* @0x2a3338 andlo lr, r8, r0, lsl #18 */
/* @0x2a333c stmdb r2, {r0, r1, r4, r9, r10, r12, sp, lr, pc} */
/* @0x2a3340 stmdblt r8!, {r0, r1, r7, r9, r10, lr} */
/* @0x2a3344 .word 0x210e4630 */
/* @0x2a3348 .word 0xf001465a */
/* @0x2a334c movw pc, #0xc805 */
/* @0x2a3350 .word 0x1630f8df */
/* @0x2a3354 ldrbtmi r4, [r9], #-1594 */
/* @0x2a3358 ldm r10!, {r0, r1, r4, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2a335c .word 0xf6134658 */
/* @0x2a3360 mcrrne p13, #0xa, lr, r1, c14 */
/* @0x2a3364 .word 0xf613d107 */
/* @0x2a3368 .word 0x210cec48 */
/* @0x2a336c ldrtmi r6, [r0], -r2, lsl #16 */
/* @0x2a3370 .word 0xfff2f000 */
/* @0x2a3374 .word 0xf8dfe016 */
/* @0x2a3378 ldrbtmi r1, [r9], #-1552 */
/* @0x2a337c stc p6, c15, [r4, #76]! */
/* @0x2a3380 .word 0xb1284607 */
/* @0x2a3384 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2a3388 beq 0x7df4cc <b2_toiTime+0x86028> */
/* @0x2a338c eor r4, r4, r8, asr #13 */
/* @0x2a3390 ldc p6, c15, [r2], #-76 */
/* @0x2a3394 stmdavs r2, {r2, r3, r8, sp} */
/* @0x2a3398 .word 0xf0004630 */
/* @0x2a339c .word 0x4658ffdd */
/* @0x2a33a0 b 0xffc60bf4 <b2_toiTime+0xffffffffff507750> */
/* @0x2a33a4 .word 0xf6134658 */
/* @0x2a33a8 sbcs lr, lr, #14286848 */
/* @0x2a33ac .word 0xf208fb0a */
/* @0x2a33b0 ldmpl r11, {r0, r1, r5, r6, r8, r9, r11, sp, lr} */
/* @0x2a33b4 andle r2, lr, r1, lsl #22 */
/* @0x2a33b8 strtmi r9, [r0], -r4, lsl #20 */
/* @0x2a33bc bl 0x334cc8 */
/* @0x2a33c0 .word 0xf84203c9 */
/* @0x2a33c4 andhs r8, r0, #57 */
/* @0x2a33c8 .word 0xf0019302 */
/* @0x2a33cc blls 0x361f18 <_ZTS12CDS_Priority+0x3f70> */
/* @0x2a33d0 stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc} */
/* @0x2a33d4 cpsie f */
/* @0x2a33d8 bvs 0xffb653e4 <b2_toiTime+0xffffffffff40bf40> */
/* @0x2a33dc blle 0xffbf4a44 <b2_toiTime+0xffffffffff49b5a0> */
/* @0x2a33e0 .word 0x21014620 */
/* @0x2a33e4 .word 0xf0012200 */
/* @0x2a33e8 teqlt r8, r9, lsl #21 */
/* @0x2a33ec ldrlo pc, [r12, #0x8df] */
/* @0x2a33f0 stmdals r4, {r3, r9, sp} */
/* @0x2a33f4 ldrbtmi r9, [r11], #-2311 */
/* @0x2a33f8 ldmdb r0!, {r0, r1, r4, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2a33fc strtmi r2, [r0], -r1, lsl #2 */
/* @0x2a3400 .word 0xf0012200 */
/* @0x2a3404 stmdahs r1, {r0, r1, r3, r4, r5, r6, r9, r11, r12, sp, lr, pc} */
/* @0x2a3408 .word 0xd1094601 */
/* @0x2a340c andhs r4, r8, #32, #12 */
/* @0x2a3410 blx 0x1fdf41c <b2_toiTime+0x1885f78> */
/* @0x2a3414 .word 0x0001f1d0 */
/* @0x2a3418 andhs r11, r0, r8, lsr pc */
/* @0x2a341c and r9, r1, r5 */
/* @0x2a3420 movwls r2, #0x5300 */
/* @0x2a3424 strbhs pc, [r8, #-0x8df]! */
/* @0x2a3428 .word 0x2100ab0e */
/* @0x2a342c .word 0x91069309 */
/* @0x2a3430 .word 0xf103447a */
/* @0x2a3434 andls r0, r10, #20, #2 */
/* @0x2a3438 blls 0x447874 <g_RomDisk+0x50054> */
/* @0x2a343c ldmdaeq r4, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2a3440 .word 0xf8529a04 */
/* @0x2a3444 blvs 0x1b8b518 <b2_toiTime+0x1432074> */
/* @0x2a3448 .word 0xf80afb08 */
/* @0x2a344c andlo pc, r8, r3, asr r8 */
/* @0x2a3450 blhs 0x2f2060 <ps_hints_apply+0xc60> */
/* @0x2a3454 stmdbls r5, {r1, r8, r11, r12, lr, pc} */
/* @0x2a3458 rsble r2, r1, r0, lsl #18 */
/* @0x2a345c mrrceq p1, #0x0, pc, r4, c13 */
/* @0x2a3460 andgt pc, r12, sp, asr #17 */
/* @0x2a3464 .word 0xf0004660 */
/* @0x2a3468 strtmi pc, [r0], -r1, ror #23 */
/* @0x2a346c andhs r2, r0, #1073741824 */
/* @0x2a3470 blx 0x13df47c <b2_toiTime+0xc85fd8> */
/* @0x2a3474 .word 0xc00cf8dd */
/* @0x2a3478 strbtmi r11, [r0], -r0, lsr #2 */
/* @0x2a347c blx 0xffddf486 <b2_toiTime+0xffffffffff685fe2> */
/* @0x2a3480 .word 0xc00cf8dd */
/* @0x2a3484 .word 0xf04f9a06 */
/* @0x2a3488 stmdavs r11!, {r2, r3, r4, r5, r8, r11} */
/* @0x2a348c .word 0xf902fb09 */
/* @0x2a3490 .word 0xf10c4662 */
/* @0x2a3494 strbmi r0, [r11], #-3128 */
/* @0x2a3498 movwlo r4, #0x8696 */
/* @0x2a349c strheq lr, [r3], -lr */
/* @0x2a34a0 .word 0xf84345e6 */
/* @0x2a34a4 ldrbtmi r0, [r2], -r8, lsl #24 */
/* @0x2a34a8 .word 0x1c04f843 */
/* @0x2a34ac ldmdavs r0, {r2, r4, r5, r6, r7, r8, r12, lr, pc} */
/* @0x2a34b0 blvs 0x1b7b518 <b2_toiTime+0x1422074> */
/* @0x2a34b4 andeq lr, r8, #3072 */
/* @0x2a34b8 bhs 0x2bd708 <jpeg_alloc_huff_table+0xe00> */
/* @0x2a34bc .word 0xf853d179 */
/* @0x2a34c0 blhs 0x36f4e8 <_ZTS13C_UTF16String+0x6594> */
/* @0x2a34c4 stmdals r10, {r1, r2, r3, r8, r12, lr, pc} */
/* @0x2a34c8 ldm r10!, {r0, r1, r4, r9, r10, r12, sp, lr, pc} */
/* @0x2a34cc .word 0xf8ad2301 */
/* @0x2a34d0 stmdbls r10, {r4, r5, r6, r12, sp} */
/* @0x2a34d4 stmdavs r10!, {r0, r1, r3, r4, r12, pc} */
/* @0x2a34d8 orrsvs r4, r1, r10, asr #8 */
/* @0x2a34dc strbmi r6, [r10], #-2090 */
/* @0x2a34e0 mls r6, r3, r3, r8 */
/* @0x2a34e4 eorshs r6, r12, #143360 */
/* @0x2a34e8 .word 0xf10afb02 */
/* @0x2a34ec strmi r6, [r10], #-2074 */
/* @0x2a34f0 swpls r6, r0, [r3] */
/* @0x2a34f4 .word 0xf6139302 */
/* @0x2a34f8 andsls lr, r11, r4, lsr #17 */
/* @0x2a34fc ldmda r12, {r0, r1, r4, r9, r10, r12, sp, lr, pc} */
/* @0x2a3500 stmdbls r3, {r1, r8, r9, r11, r12, pc} */
/* @0x2a3504 rsbseq pc, r0, sp, lsr #17 */
/* @0x2a3508 strmi r6, [r11], #-2075 */
/* @0x2a350c stmdavs r11!, {r1, r3, r4, r7, r8, r11, sp, lr} */
/* @0x2a3510 orrsvs r4, r10, r11, asr #8 */
/* @0x2a3514 rfeia sp! */
/* @0x2a3518 strbmi r2, [r11], #-112 */
/* @0x2a351c umaal r8, r8, r10, r3 */
/* @0x2a3520 stmdahs r0, {r5, r6, r11, sp, lr} */
/* @0x2a3524 bvs 0xb97714 <b2_toiTime+0x43e270> */
/* @0x2a3528 ldmdavs r11, {r2, r3, r4, r5, r9, sp} */
/* @0x2a352c movwlo pc, #0xab02 */
/* @0x2a3530 blvs 0xfe909d4c <b2_toiTime+0xfffffffffe1b08a8> */
/* @0x2a3534 stcl p6, c15, [lr], {19} */
/* @0x2a3538 .word 0xf0402800 */
/* @0x2a353c bls 0x4039bc <g_RomDisk+0xc19c> */
/* @0x2a3540 ldmdage r5, {r0, r8, r9, sp} */
/* @0x2a3544 subeq lr, r8, sp, lsl #17 */
/* @0x2a3548 ldrmi r6, [r3], -r1, ror #16 */
/* @0x2a354c ldc2l p0, c15, [r0], {0} */
/* @0x2a3550 .word 0xd1602800 */
/* @0x2a3554 teqhs r12, #24576 */
/* @0x2a3558 blx 0x37d602 <_ZTS13C_UTF16String+0x146ae> */
/* @0x2a355c bvs 0xb5f96c <b2_toiTime+0x4064c8> */
/* @0x2a3560 .word 0xf30afb03 */
/* @0x2a3564 strmi r6, [r8], #-2066 */
/* @0x2a3568 .word 0xf102441a */
/* @0x2a356c .word 0xf8520e3c */
/* @0x2a3570 ldrbmi r12, [r2, #-0xb04]! */
/* @0x2a3574 blgt 0x3e167c <error_g0017+0x3a320> */
/* @0x2a3578 rfeia sp! */
/* @0x2a357c .word 0xf01ee058 */
/* @0x2a3580 andsle r0, r6, r8, lsl #30 */
/* @0x2a3584 .word 0xf02e6a22 */
/* @0x2a3588 ldmdavs r0, {r3, r9, r10, r11} */
/* @0x2a358c stmvs r0, {r3, r4, r10, lr} ^ */
/* @0x2a3590 ldmdavs r0, {r3, r4, r12, pc} */
/* @0x2a3594 stmdbvs r0, {r3, r4, r10, lr} */
/* @0x2a3598 ldmdavs r2, {r0, r3, r4, r12, pc} */
/* @0x2a359c subs pc, r8, sp, lsr #17 */
/* @0x2a35a0 ldmdbvs r11, {r0, r1, r4, r10, lr} ^ */
/* @0x2a35a4 stmdavs r11!, {r1, r3, r4, r8, r9, r12, pc} */
/* @0x2a35a8 stmhi r11, {r0, r3, r4, r10, lr} */
/* @0x2a35ac movweq pc, #0x8023 */
/* @0x2a35b0 blvs 0x1b837e4 <b2_toiTime+0x142a340> */
/* @0x2a35b4 ldmvs r11, {r0, r1, r6, r10, lr} */
/* @0x2a35b8 .word 0xd1462b00 */
/* @0x2a35bc .word 0x21014620 */
/* @0x2a35c0 .word 0xf0012200 */
/* @0x2a35c4 stmdahs r0, {r0, r1, r3, r4, r7, r8, r11, r12, sp, lr, pc} */
/* @0x2a35c8 bls 0x457748 <g_RomDisk+0x5ff28> */
/* @0x2a35cc shasxmi r2, r8, r12 */
/* @0x2a35d0 movwls r4, #0x8353 */
/* @0x2a35d4 .word 0x9020f8dd */
/* @0x2a35d8 ldrmi r6, [r9], #2091 */
/* @0x2a35dc stc p6, c15, [r0], {19} */
/* @0x2a35e0 eorseq pc, r8, r9, asr #17 */
/* @0x2a35e4 bl 0x37e378 <_ZTS13C_UTF16String+0x15424> */
/* @0x2a35e8 .word 0xf8530208 */
/* @0x2a35ec bllo 0x32f614 */
/* @0x2a35f0 ldmdble r0, {r0, r8, r9, r11, sp} ^ */
/* @0x2a35f4 blhs 0x2ca210 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x75c> */
/* @0x2a35f8 rschi pc, r2, r0 */
/* @0x2a35fc .word 0xf04f2200 */
/* @0x2a3600 qsub8mi r3, r0, pc */
/* @0x2a3604 andeq lr, r12, sp, lsl #17 */
/* @0x2a3608 ldrbmi r4, [r2], -r1, lsr #12 */
/* @0x2a360c .word 0xf0012310 */
/* @0x2a3610 stmdahs r0, {r0, r2, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2a3614 .word 0xf04fd140 */
/* @0x2a3618 rscs r0, r2, r1, lsl #16 */
/* @0x2a361c stmdahs r0, {r5, r7, r11, sp, lr} */
/* @0x2a3620 bvs 0xb57888 <b2_toiTime+0x3fe3e4> */
/* @0x2a3624 stmdavs r3, {r2, r3, r4, r5, r8, sp} */
/* @0x2a3628 ldmdbvs r11, {r1, r4, r11, sp, lr} */
/* @0x2a362c andhs pc, r10, #1024 */
/* @0x2a3630 blvs 0xfe749a4c <b2_toiTime+0xfffffffffdff05a8> */
/* @0x2a3634 bls 0x3f549c <g_MP3UpdateVolume+0x1c0> */
/* @0x2a3638 ldmdage r5, {r0, r8, r9, sp} */
/* @0x2a363c subeq lr, r8, sp, lsl #17 */
/* @0x2a3640 stmvs r1!, {r0, r1, r4, r9, r10, lr} */
/* @0x2a3644 stc2l p0, c15, [r0, #-0]! */
/* @0x2a3648 ldmdals r11, {r1, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2a364c svc #0x86f612 */
/* @0x2a3650 bl 0x37e3e4 <_ZTS13C_UTF16String+0x15490> */
/* @0x2a3654 .word 0xf8d90908 */
/* @0x2a3658 .word 0xf6120008 */
/* @0x2a365c ldrshls lr, [r11], -r2 */
/* @0x2a3660 sbcsle r2, r8, r0, lsl #16 */
/* @0x2a3664 svc #0x68f612 */
/* @0x2a3668 teqhs r12, #98304 */
/* @0x2a366c .word 0xf8ad434b */
/* @0x2a3670 stmdavs r10!, {r4, r5, r6} */
/* @0x2a3674 .word 0x1008f8d9 */
/* @0x2a3678 orrsvs r4, r1, r10, lsl r4 */
/* @0x2a367c rfeia sp! */
/* @0x2a3680 ldrmi r1, [r3], #-112 */
/* @0x2a3684 .word 0xe7998399 */
/* @0x2a3688 strbmi r6, [r2], #-2914 */
/* @0x2a368c movwlo r6, #0x1913 */
/* @0x2a3690 cmphi sp, r0, asr #32 */
/* @0x2a3694 ldmdavs r0, {r0, r3, r4, r7, r8, r9, r10, sp, lr, pc} ^ */
/* @0x2a3698 .word 0x8004f8d0 */
/* @0x2a369c .word 0xf8d0a90e */
/* @0x2a36a0 andshs r9, r12, #0 */
/* @0x2a36a4 strbmi r2, [r0], -r3, lsl #6 */
/* @0x2a36a8 ldmdahs r11, {r3, r6, r7, r8, r9, r10, lr} */
/* @0x2a36ac .word 0x2100dd2f */
/* @0x2a36b0 strmi r4, [r10], -r0, asr #12 */
/* @0x2a36b4 strbmi r4, [r8, r11, lsl #12] */
/* @0x2a36b8 blle 0xcad6c0 <b2_toiTime+0x55421c> */
/* @0x2a36bc .word 0xf10d4638 */
/* @0x2a36c0 .word 0xf6130a54 */
/* @0x2a36c4 ldrtmi lr, [r9], -lr, lsl #24 */
/* @0x2a36c8 ldrtmi r2, [r3], -r1, lsl #4 */
/* @0x2a36cc ldrbmi r9, [r0], -r11 */
/* @0x2a36d0 blx 0x45f6da <g_RomDisk+0x67eba> */
/* @0x2a36d4 blle 0xfea2d6dc <b2_toiTime+0xfffffffffe2d4238> */
/* @0x2a36d8 ldrhlo pc, [r0], #-141 */
/* @0x2a36dc .word 0x9600b13b */
/* @0x2a36e0 strbmi r4, [r1], -r8, asr #12 */
/* @0x2a36e4 ldrtmi r9, [r11], -sp, lsl #20 */
/* @0x2a36e8 ldc2 p7, c15, [r0, #-1020]! */
/* @0x2a36ec strls lr, [r0, -r6] */
/* @0x2a36f0 strbmi r4, [r9], -r0, lsr #12 */
/* @0x2a36f4 blge 0x635004 <g_SWFaavertbuff+0x61f3c> */
/* @0x2a36f8 .word 0xfc0ef7ff */
/* @0x2a36fc blle 0xfe52d704 <b2_toiTime+0xfffffffffddd4260> */
/* @0x2a3700 strbmi r2, [r0], -r0, lsl #2 */
/* @0x2a3704 movwhs r4, #0x260a */
/* @0x2a3708 stmdahs r0, {r3, r6, r7, r8, r9, r10, lr} */
/* @0x2a370c ldrtmi sp, [r0], -r5, lsl #20 */
/* @0x2a3710 strbmi r4, [r2], -r9, asr #12 */
/* @0x2a3714 blx 0xffce171a <b2_toiTime+0xffffffffff588276> */
/* @0x2a3718 shsub16mi lr, r8, sp */
/* @0x2a371c bl 0xffae0f70 <b2_toiTime+0xffffffffff387acc> */
/* @0x2a3720 andhs r9, r0, #180224 */
/* @0x2a3724 ldrtmi r4, [r8], -r0, lsl #13 */
/* @0x2a3728 bl 0xff7e0f7c <b2_toiTime+0xffffffffff087ad8> */
/* @0x2a372c blle 0xbad734 <b2_toiTime+0x454290> */
/* @0x2a3730 qadd16mi r9, r0, r1 */
/* @0x2a3734 andhs r2, r0, #1073741824 */
/* @0x2a3738 rfeia sp! */
/* @0x2a373c .word 0xf8ad3050 */
/* @0x2a3740 blls 0x6af8b0 <g_SWFlinevertbuff+0x5c7e8> */
/* @0x2a3744 blls 0x7483ac <g_SWFvertbuff+0x752e4> */
/* @0x2a3748 blls 0x7883b8 <b2_toiTime+0x2ef14> */
/* @0x2a374c .word 0xf0019319 */
/* @0x2a3750 ldrsblt pc, [r0, -r5] */
/* @0x2a3754 .word 0xf0004650 */
/* @0x2a3758 usub16mi pc, r0, pc */
/* @0x2a375c andhs r4, r1, #59768832 */
/* @0x2a3760 .word 0xf0004633 */
/* @0x2a3764 stmdahs r0, {r0, r2, r3, r4, r5, r7, r9, r11, r12, sp, lr, pc} */
/* @0x2a3768 svcge #0x55f6ff */
/* @0x2a376c .word 0x46414638 */
/* @0x2a3770 .word 0xf6132200 */
/* @0x2a3774 stmdahs r0, {r4, r5, r7, r8, r9, r11, sp, lr, pc} */
/* @0x2a3778 .word 0xf613da07 */
/* @0x2a377c .word 0x2104ea3e */
/* @0x2a3780 ldrtmi r6, [r0], -r2, lsl #16 */
/* @0x2a3784 stc2l p0, c15, [r8, #0]! */
/* @0x2a3788 stmdavs r11!, {r0, r2, r6, r8, r9, r10, sp, lr, pc} */
/* @0x2a378c stmdbls r8, {r3, r9, r11, r12, pc} */
/* @0x2a3790 blls 0x874800 <b2_toiTime+0x11b35c> */
/* @0x2a3794 stmdavs r11!, {r0, r1, r4, r7, sp, lr} */
/* @0x2a3798 ldrhhs pc, [r10], #-141 */
/* @0x2a379c sbcshi r4, r10, r11, lsl #8 */
/* @0x2a37a0 stmdavs r11!, {r1, r3, r9, r10, lr} */
/* @0x2a37a4 blls 0x8f4814 <b2_toiTime+0x19b370> */
/* @0x2a37a8 .word 0x460a6113 */
/* @0x2a37ac ldrmi r6, [r10], #-2091 */
/* @0x2a37b0 cmpvs r3, r10, lsl r11 */
/* @0x2a37b4 stmdavs r11!, {r1, r3, r9, r10, lr} */
/* @0x2a37b8 blls 0x8b4828 <b2_toiTime+0x15b384> */
/* @0x2a37bc ldrsb r6, [r4], -r3 */
/* @0x2a37c0 shadd16mi r10, r9, r5 */
/* @0x2a37c4 ldrtmi r2, [r3], -r1, lsl #4 */
/* @0x2a37c8 blx 0xfe55f7d0 <b2_toiTime+0xfffffffffde0632c> */
/* @0x2a37cc .word 0xf6ff2800 */
/* @0x2a37d0 bls 0x4cf460 <SrcVerts+0x2c4a4> */
/* @0x2a37d4 stmdavs r0!, {r0, r1, r3, r5, r11, sp, lr} ^ */
/* @0x2a37d8 shadd16mi r4, r10, r3 */
/* @0x2a37dc shadd16mi r6, r3, r9 */
/* @0x2a37e0 stc2l p7, c15, [r0], #-1020 */
/* @0x2a37e4 .word 0xf6ff2800 */
/* @0x2a37e8 ldmdage r5, {r1, r2, r4, r8, r9, r10, r11, sp, pc} */
/* @0x2a37ec .word 0xf9f3f000 */
/* @0x2a37f0 stmdbls r7, {r1, r2, r8, r9, r11, r12, pc} */
/* @0x2a37f4 movwls r3, #0x6301 */
/* @0x2a37f8 .word 0xf6ff428b */
/* @0x2a37fc .word 0xf04fae1e */
/* @0x2a3800 stmdals r4, {r11} */
/* @0x2a3804 mcr p6, #0x5, pc, c10, c2, #0x0 */
/* @0x2a3808 svceq #0xf1b8 */
/* @0x2a380c strtmi sp, [r8], -r7, asr #2 */
/* @0x2a3810 shasxmi r4, r2, r9 */
/* @0x2a3814 blx 0x1df81c <_Z11PrepareGamev+0x108> */
/* @0x2a3818 blle 0x116d820 <b2_toiTime+0xa1437c> */
/* @0x2a381c .word 0x21014620 */
/* @0x2a3820 .word 0xf0014642 */
/* @0x2a3824 ldmdblt r0, {r0, r1, r3, r5, r6, r11, r12, sp, lr, pc} */
/* @0x2a3828 stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2a382c shasxmi lr, r8, r4 */
/* @0x2a3830 bl 0x1861084 <b2_toiTime+0x1107be0> */
/* @0x2a3834 blge 0x64903c <g_SWFaavertbuff+0x75f74> */
/* @0x2a3838 stmvs r10!, {r0, r3, r5, r6, r7, r11, sp, lr} */
/* @0x2a383c ldrtmi r4, [r8], -r1, lsl #13 */
/* @0x2a3840 ldc2l p0, c15, [r10] */
/* @0x2a3844 blle 0xbed84c <b2_toiTime+0x4943a8> */
/* @0x2a3848 beq 0xfe6dfc84 <b2_toiTime+0xfffffffffdf867e0> */
/* @0x2a384c qaddhs r4, r1, r9 */
/* @0x2a3850 ldrbtmi r9, [r10], #-2830 */
/* @0x2a3854 .word 0xf6124650 */
/* @0x2a3858 .word 0x4638eeb8 */
/* @0x2a385c smlatbeq r8, r9, r1, pc */
/* @0x2a3860 .word 0xf6134642 */
/* @0x2a3864 stmdahs r0, {r3, r4, r5, r8, r9, r11, sp, lr, pc} */
/* @0x2a3868 .word 0xf613da05 */
/* @0x2a386c smlabths r4, r6, r9, lr */
/* @0x2a3870 ldrtmi r6, [r0], -r2, lsl #16 */
/* @0x2a3874 ldrbmi lr, [r0], -r12 */
/* @0x2a3878 andhs r2, r1, #8, #2 */
/* @0x2a387c .word 0xf613463b */
/* @0x2a3880 stmdahs r1, {r1, r2, r3, r4, r11, sp, lr, pc} */
/* @0x2a3884 .word 0xf613d0d0 */
/* @0x2a3888 strhhs lr, [r6, -r8] */
/* @0x2a388c ldrtmi r6, [r0], -r2, lsl #16 */
/* @0x2a3890 stc2l p0, c15, [r2, #-0]! */
/* @0x2a3894 ldmlo pc!, {r0, r1, r2, r3, r6, r12, sp, lr, pc} ^ */
/* @0x2a3898 stmdaeq r0, {r3, r6, r7, r8, r12, sp, lr, pc} */
/* @0x2a389c .word 0xf04fe001 */
/* @0x2a38a0 movwhs r0, #0x801 */
/* @0x2a38a4 rsbvs r4, r11, r8, lsr #12 */
/* @0x2a38a8 .word 0xf9a5f000 */
/* @0x2a38ac svceq #0xf1b8 */
/* @0x2a38b0 ldmdage r5, {r1, r2, r12, lr, pc} */
/* @0x2a38b4 .word 0xf98ff000 */
/* @0x2a38b8 .word 0xf6124638 */
/* @0x2a38bc and lr, r10, r10, asr #31 */
/* @0x2a38c0 .word 0xf6124638 */
/* @0x2a38c4 cmnlt r8, r6, asr #31 */
/* @0x2a38c8 ldmib r6, {r0, r1, r4, r9, r10, r12, sp, lr, pc} */
/* @0x2a38cc stmdavs r2, {r0, r1, r8, sp} */
/* @0x2a38d0 .word 0xf0004630 */
/* @0x2a38d4 ldrbmi pc, [r8], -r1, asr #26 */
/* @0x2a38d8 stmda r10, {r0, r1, r4, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2a38dc .word 0xf6124658 */
/* @0x2a38e0 .word 0xf04fee3e */
/* @0x2a38e4 .word 0xe02a35ff */
/* @0x2a38e8 .word 0xb1286860 */
/* @0x2a38ec svc #0xb0f612 */
/* @0x2a38f0 .word 0xf8c42701 */
/* @0x2a38f4 and r8, r0, r4 */
/* @0x2a38f8 ldrbmi r4, [r8], -r7, asr #12 */
/* @0x2a38fc .word 0xf6126821 */
/* @0x2a3900 strmi lr, [r5], -lr, lsr #31 */
/* @0x2a3904 .word 0xf613b1a8 */
/* @0x2a3908 .word 0x2102e978 */
/* @0x2a390c ldrtmi r6, [r0], -r2, lsl #16 */
/* @0x2a3910 stc2 p0, c15, [r2, #-0]! */
/* @0x2a3914 .word 0xf6134658 */
/* @0x2a3918 ldrbmi lr, [r8], -r12, lsr #16 */
/* @0x2a391c mrc p6, #0x0, apsr_nzcv, c14, c2, #0x0 */
/* @0x2a3920 sbcsle r2, lr, r0, lsl #30 */
/* @0x2a3924 stmdavs r0!, {r2, r3, r4, r8, r11, lr} */
/* @0x2a3928 .word 0xf6124479 */
/* @0x2a392c rsbvs lr, r0, r12, lsl #31 */
/* @0x2a3930 .word 0x4620e7d7 */
/* @0x2a3934 .word 0xffa6f000 */
/* @0x2a3938 .word 0xf6124658 */
/* @0x2a393c stmdbls r12, {r4, r9, r10, r11, sp, lr, pc} */
/* @0x2a3940 bls 0xc751e8 <b2_toiTime+0x51bd44> */
/* @0x2a3944 addsmi r6, r10, #720896 */
/* @0x2a3948 .word 0xf612d014 */
/* @0x2a394c stmdbls r6, {r2, r6, r9, r10, r11, sp, lr, pc} */
/* @0x2a3950 movtmi r2, #0xb33c */
/* @0x2a3954 stmdavs r10!, {r0, r4, r6, r7, r11, sp, lr} */
/* @0x2a3958 addsvs r4, r1, #436207616 */
/* @0x2a395c ldrmi r6, [r3], #-2090 */
/* @0x2a3960 strbmi r6, [r2], #-2914 */
/* @0x2a3964 ldrhi r6, [r10, #0x912] */
/* @0x2a3968 strtmi lr, [r8], -pc, lsr #12 */
/* @0x2a396c .word 0xf943f000 */
/* @0x2a3970 ldr r9, [r4, r4, lsl #16]! */
/* @0x2a3974 pop {r0, r3, r5, r12, sp, pc} */
/* @0x2a3978 svclt #0x8ff0 */
/* @0x2a397c andseq r10, r4, r0, ror #14 */
/* @0x2a3980 andeq r8, lr, lr, ror #25 */
/* @0x2a3984 andeq r8, lr, pc, lsl #25 */
/* @0x2a3988 andeq r8, lr, r5, ror r12 */
/* @0x2a398c .word 0xfffffb17 */
/* @0x2a3990 andeq r8, lr, r3, asr #23 */
/* @0x2a3994 andeq r8, lr, r3, lsr #15 */
/* @0x2a3998 ldrdeq r8, r9, [lr], -r3 */
/* @0x2a399c .word 0x4604b538 */
/* @0x2a39a0 sbclt r4, r0, #13631488 */
/* @0x2a39a4 b 0xfeb611f8 <b2_toiTime+0xfffffffffe407d54> */
/* @0x2a39a8 .word 0xf3c44629 */
/* @0x2a39ac .word 0xf6132007 */
/* @0x2a39b0 qadd8mi lr, r9, lr */
/* @0x2a39b4 andmi pc, r7, r4, asr #7 */
/* @0x2a39b8 b 0xfe8e120c <b2_toiTime+0xfffffffffe187d68> */
/* @0x2a39bc strtmi r0, [r9], -r0, lsr #28 */
/* @0x2a39c0 ldrhtmi lr, [r8], -sp */
/* @0x2a39c4 ldmdalt r2!, {r3, r4, r5, r6, r12, sp, lr, pc} ^ */
/* @0x2a39c8 .word 0x4604b538 */
/* @0x2a39cc sbclt r4, r0, #13631488 */
/* @0x2a39d0 b 0xfe5e1224 <b2_toiTime+0xfffffffffde87d80> */
/* @0x2a39d4 strtmi r0, [r9], -r0, lsr #20 */
/* @0x2a39d8 ldrhtmi lr, [r8], -sp */
/* @0x2a39dc stmdalt r6!, {r3, r4, r5, r6, r12, sp, lr, pc} ^ */
/* @0x2a39e0 mvnsmi lr, sp, lsr #18 */
/* @0x2a39e4 strmi r4, [sp], -r0, lsl #13 */
/* @0x2a39e8 sadd16mi r4, r6, pc */
/* @0x2a39ec mcrrne p1, #0x0, r11, r8, c10 */
/* @0x2a39f0 strmi lr, [r8], -r0 */
/* @0x2a39f4 stc p6, c15, [r6, #72]! */
/* @0x2a39f8 stmdblt r8!, {r2, r9, r10, lr} */
/* @0x2a39fc .word 0x210e4638 */
/* @0x2a3a00 .word 0xf0004622 */
/* @0x2a3a04 eor pc, r3, r9, lsr #25 */
/* @0x2a3a08 strtmi r2, [r10], -r1, lsl #2 */
/* @0x2a3a0c .word 0xf6124643 */
/* @0x2a3a10 adcmi lr, r8, #92, #30 */
/* @0x2a3a14 strtmi sp, [r0], -r12, lsl #4 */
/* @0x2a3a18 stc p6, c15, [r0, #72]! */
/* @0x2a3a1c stm r12!, {r0, r1, r4, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2a3a20 stmdavs r2, {r0, r2, r8, sp} */
/* @0x2a3a24 .word 0xf0004638 */
/* @0x2a3a28 mulhs r0, r7, r12 */
/* @0x2a3a2c ldrhhi lr, [r0, #141]! */
/* @0x2a3a30 stmdbne r2!, {r1, r2, r4, r5, r6, r8, r12, sp, pc} ^ */
/* @0x2a3a34 eorhs r2, r0, r0, lsl #6 */
/* @0x2a3a38 strtmi r5, [r3], -r3, ror #10 */
/* @0x2a3a3c sadd8mi r4, r9, r3 */
/* @0x2a3a40 stmdavc r9, {r1, r2, r9, r12, lr, pc} */
/* @0x2a3a44 stmdbhs r0, {r0, r8, r9, r12, sp} */
/* @0x2a3a48 .word 0xf803d1f8 */
/* @0x2a3a4c ldrb r0, [r5, r1, lsl #24]! */
/* @0x2a3a50 pop {r5, r9, r10, lr} */
/* @0x2a3a54 strlt r8, [r0, #-0x1f0] */
/* @0x2a3a58 .word 0xf04fb08d */
/* @0x2a3a5c movwls r3, #0x93ff */
/* @0x2a3a60 movths pc, #0x63c1 */
/* @0x2a3a64 movwls r3, #0x6350 */
/* @0x2a3a68 movtne pc, #0x33c1 */
/* @0x2a3a6c tsteq pc, r1 */
/* @0x2a3a70 movwls r3, #0x5b01 */
/* @0x2a3a74 bichs pc, r4, #192, #6 */
/* @0x2a3a78 .word 0xf3c09303 */
/* @0x2a3a7c subeq r1, r0, r5, asr #6 */
/* @0x2a3a80 .word 0xf0009302 */
/* @0x2a3a84 stmdage r12, {r1, r2, r3, r4, r5, r8, r9} */
/* @0x2a3a88 .word 0xf8409104 */
/* @0x2a3a8c .word 0xf6133d2c */
/* @0x2a3a90 andlt lr, sp, r4, lsr r10 */
/* @0x2a3a94 blx 0x3e1c12 <error_g0017+0x3a8b6> */
/* @0x2a3a98 mvnsmi lr, sp, lsr #18 */
/* @0x2a3a9c strmi r4, [r12], -r6, lsl #12 */
/* @0x2a3aa0 sadd8mi r4, r7, r8 */
/* @0x2a3aa4 mcrrne p1, #0x0, r11, r8, c10 */
/* @0x2a3aa8 strmi lr, [r8], -r0 */
/* @0x2a3aac stcl p6, c15, [r10, #-72] */
/* @0x2a3ab0 stmdblt r8!, {r0, r2, r9, r10, lr} */
/* @0x2a3ab4 .word 0x210e4640 */
/* @0x2a3ab8 .word 0xf000462a */
/* @0x2a3abc ands pc, r6, sp, asr #24 */
/* @0x2a3ac0 qasxmi r6, r2, r1 */
/* @0x2a3ac4 ldcl p6, c15, [r10, #-72]! */
/* @0x2a3ac8 strtmi r6, [r3], #-2099 */
/* @0x2a3acc cmnlt r7, r3, lsr r0 */
/* @0x2a3ad0 movwhs r1, #0x92a */
/* @0x2a3ad4 strpl r2, [r11, #-0x20]! */
/* @0x2a3ad8 addsmi r4, r3, #45088768 */
/* @0x2a3adc andle r4, r6, #26214400 */
/* @0x2a3ae0 movwlo r7, #0x1809 */
/* @0x2a3ae4 mvnsle r2, r0, lsl #18 */
/* @0x2a3ae8 .word 0x0c01f803 */
/* @0x2a3aec qsub8mi lr, r8, r5 */
/* @0x2a3af0 ldrhhi lr, [r0, #141]! */
/* @0x2a3af4 mvnsmi lr, sp, lsr #18 */
/* @0x2a3af8 strmi r4, [sp], -r7, lsl #12 */
/* @0x2a3afc sadd8mi r4, r6, r8 */
/* @0x2a3b00 mcrrne p1, #0x0, r11, r8, c10 */
/* @0x2a3b04 strmi lr, [r8], -r0 */
/* @0x2a3b08 ldc p6, c15, [r12, #-72] */
/* @0x2a3b0c stmdblt r8!, {r2, r9, r10, lr} */
/* @0x2a3b10 .word 0x210e4640 */
/* @0x2a3b14 .word 0xf0004622 */
/* @0x2a3b18 ands pc, r5, pc, lsl r12 */
/* @0x2a3b1c qasxmi r4, r1, r8 */
/* @0x2a3b20 strtmi r2, [r11], -r1, lsl #4 */
/* @0x2a3b24 ldm r10!, {r1, r3, r5, r9, r10, r12, sp, lr, pc} */
/* @0x2a3b28 stmdbne r2!, {r1, r2, r4, r5, r6, r8, r12, sp, pc} ^ */
/* @0x2a3b2c eorhs r2, r0, r0, lsl #6 */
/* @0x2a3b30 strtmi r5, [r3], -r3, ror #10 */
/* @0x2a3b34 sadd8mi r4, r9, r3 */
/* @0x2a3b38 stmdavc r9, {r1, r2, r9, r12, lr, pc} */
/* @0x2a3b3c stmdbhs r0, {r0, r8, r9, r12, sp} */
/* @0x2a3b40 .word 0xf803d1f8 */
/* @0x2a3b44 ldrb r0, [r5, r1, lsl #24]! */
/* @0x2a3b48 pop {r5, r9, r10, lr} */
/* @0x2a3b4c ldrblt r8, [r0, #-0x1f0]! */

/* ── FUNC 0x2a31ed · zip_close · size=1968 · insn=0 */

/* ── FUNC 0x2a3b4e · anon_2a3b4e · size=60 · insn=15 */
/* @0x2a3b4e .word 0x4604b570 */
/* @0x2a3b52 strmi r6, [sp], -r3, asr #16 */
/* @0x2a3b56 addsmi r4, r9, #23068672 */
/* @0x2a3b5a ldrmi sp, [r0], -r3, lsl #20 */
/* @0x2a3b5e andhs r2, r0, #20, #2 */
/* @0x2a3b62 teqhs r12, r8 */
/* @0x2a3b66 .word 0x43696800 */
/* @0x2a3b6a ldmda lr, {r0, r1, r4, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2a3b6e ldmdblt r0!, {r1, r9, r10, lr} */
/* @0x2a3b72 .word 0x210e4630 */
/* @0x2a3b76 blx 0xffe9fb80 <b2_toiTime+0xffffffffff7466dc> */
/* @0x2a3b7a rscslo pc, pc, pc, asr #32 */
/* @0x2a3b7e stm r4, {r4, r5, r6, r8, r10, r11, r12, sp, pc} */
/* @0x2a3b82 andhs r0, r0, r4, lsr #32 */
/* @0x2a3b86 ldrblt r11, [r8, #0xd70]! */

/* ── FUNC 0x2a3b4f · _zip_cdir_grow(zip_cdir*, int, zip_error*) · size=58 · insn=0 */

/* ── FUNC 0x2a3b88 · anon_2a3b88 · size=80 · insn=20 */
/* @0x2a3b88 .word 0x4606b5f8 */
/* @0x2a3b8c .word 0x460f2018 */
/* @0x2a3b90 ldcl p6, c15, [r8], {18} */
/* @0x2a3b94 stmdblt r8!, {r2, r9, r10, lr} */
/* @0x2a3b98 .word 0x210e4638 */
/* @0x2a3b9c .word 0xf0004622 */
/* @0x2a3ba0 ldrsb pc, [r6], -r11 */
/* @0x2a3ba4 cmnmi r0, #60 */
/* @0x2a3ba8 stcl p6, c15, [r12], {18} */
/* @0x2a3bac eorvs r4, r0, r5, lsl #12 */
/* @0x2a3bb0 ldrtmi r11, [r8], -r8, asr #18 */
/* @0x2a3bb4 strtmi r2, [r10], -lr, lsl #2 */
/* @0x2a3bb8 blx 0xff65fbc2 <b2_toiTime+0xfffffffffef0671e> */
/* @0x2a3bbc .word 0xf6124620 */
/* @0x2a3bc0 strtmi lr, [r8], -lr, asr #25 */
/* @0x2a3bc4 movwhs r11, #0xdf8 */
/* @0x2a3bc8 rscvs r6, r3, r6, rrx */
/* @0x2a3bcc smulwbvs r3, r3, r0 */
/* @0x2a3bd0 strtmi r8, [r0], -r3, lsr #5 */
/* @0x2a3bd4 ldrlt r11, [r8, #-0xdf8]! */

/* ── FUNC 0x2a3b89 · _zip_cdir_new(int, zip_error*) · size=78 · insn=0 */

/* ── FUNC 0x2a3bd6 · anon_2a3bd6 · size=88 · insn=22 */
/* @0x2a3bd6 .word 0x4604b538 */
/* @0x2a3bda strhs r6, [r0, #-0x980] */
/* @0x2a3bde ldc p6, c15, [lr], #72 */
/* @0x2a3be2 .word 0x61a56a20 */
/* @0x2a3be6 ldc p6, c15, [r10], #72 */
/* @0x2a3bea bvs 0xfeabc486 <b2_toiTime+0xfffffffffe362fe2> */
/* @0x2a3bee ldc p6, c15, [r6], #72 */
/* @0x2a3bf2 ldclt p2, c6, [r8, #-660]! */
/* @0x2a3bf6 .word 0x4604b570 */
/* @0x2a3bfa strhs r11, [r0, #-0x1b0] */
/* @0x2a3bfe stmdavs r3!, {r2, r3, r4, r5, r9, r10, sp} ^ */
/* @0x2a3c02 ble 0x43467e <g_RomDisk+0x3ce5e> */
/* @0x2a3c06 blx 0x43dc90 <g_RomDisk+0x46470> */
/* @0x2a3c0a .word 0xf7ff0005 */
/* @0x2a3c0e strlo pc, [r1, #-0xfe3] */
/* @0x2a3c12 stmdbvs r0!, {r0, r2, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2a3c16 stc p6, c15, [r2], #72 */
/* @0x2a3c1a .word 0xf6126820 */
/* @0x2a3c1e qadd8mi lr, r0, lr */
/* @0x2a3c22 ldrhtmi lr, [r0], #-141 */
/* @0x2a3c26 svclt #0x49f077 */
/* @0x2a3c2a movwhs r11, #0xd70 */

/* ── FUNC 0x2a3bd7 · _zip_dirent_finalize(zip_dirent*) · size=32 · insn=0 */

/* ── FUNC 0x2a3bf7 · _zip_cdir_free(zip_cdir*) · size=54 · insn=0 */

/* ── FUNC 0x2a3c2c · anon_2a3c2c · size=680 · insn=170 */
/* @0x2a3c2c andshs r2, r4, #0, #6 */
/* @0x2a3c30 subhi r8, r2, r3 */
/* @0x2a3c34 sbchi r8, r3, r3, lsl #1 */
/* @0x2a3c38 sbcvs r6, r3, r3, lsl #1 */
/* @0x2a3c3c mrsvs r6, spsr */
/* @0x2a3c40 orrhi r6, r3, #-1073741792 */
/* @0x2a3c44 strhi r6, [r3], #515 */
/* @0x2a3c48 strhi r6, [r3, #0x283] */
/* @0x2a3c4c strhi r8, [r3], -r3, asr #11 */
/* @0x2a3c50 orrvs r6, r3, #201326593 */
/* @0x2a3c54 andeq r4, r0, r0, ror r7 */
/* @0x2a3c58 .word 0x4604b573 */
/* @0x2a3c5c ldrbtmi r4, [sp], #-3358 */
/* @0x2a3c60 stmiblt r3!, {r0, r1, r3, r5, r11, sp, lr} ^ */
/* @0x2a3c64 rsbvs r10, r11, r1, lsl #28 */
/* @0x2a3c68 eorhs r6, r0, #-1073741766 */
/* @0x2a3c6c eorvs r4, r11, #48, #12 */
/* @0x2a3c70 adcvs r6, r10, r11, ror #4 */
/* @0x2a3c74 rscvs r2, r10, r7, lsl r2 */
/* @0x2a3c78 .word 0x612a2218 */
/* @0x2a3c7c .word 0x616a220b */
/* @0x2a3c80 .word 0x61aa2260 */
/* @0x2a3c84 ldc p6, c15, [r10, #72]! */
/* @0x2a3c88 .word 0xf6134630 */
/* @0x2a3c8c bvs 0x139e184 <b2_toiTime+0xc44ce0> */
/* @0x2a3c90 bvs 0xfe37c744 <b2_toiTime+0xfffffffffdc232a0> */
/* @0x2a3c94 rscvs r1, r11, #40, #26 */
/* @0x2a3c98 stmdb lr!, {r0, r1, r4, r9, r10, r12, sp, lr, pc} */
/* @0x2a3c9c tsths r4, #40 */
/* @0x2a3ca0 movwhs r8, #0x2063 */
/* @0x2a3ca4 movwhs r8, #0x80a3 */
/* @0x2a3ca8 blmi 0x5c403c <g_SWFlineaavertbuff+0x70f74> */
/* @0x2a3cac bvs 0xaad0b4 <b2_toiTime+0x353c10> */
/* @0x2a3cb0 eorhi r4, r5, r11, ror r4 */
/* @0x2a3cb4 ldmdavs r11, {r0, r2, r5, r6, r7, r8, r10, pc} */
/* @0x2a3cb8 .word 0x63658625 */
/* @0x2a3cbc .word 0x63a560a3 */
/* @0x2a3cc0 mcrr p6, #0x1, pc, r12, c2 */
/* @0x2a3cc4 strthi r6, [r5], #549 */
/* @0x2a3cc8 .word 0xf6126aa0 */
/* @0x2a3ccc adcvs lr, r5, #72, #24 */
/* @0x2a3cd0 andlt r8, r2, r5, lsr #11 */
/* @0x2a3cd4 svclt #0xbd70 */
/* @0x2a3cd8 subeq r5, r11, lr, lsl #9 */
/* @0x2a3cdc subeq r5, r11, r12, lsr r4 */
/* @0x2a3ce0 mvnsmi lr, sp, lsr #18 */
/* @0x2a3ce4 strmi r4, [r12], -r5, lsl #12 */
/* @0x2a3ce8 sadd16mi r4, r6, pc */
/* @0x2a3cec stmdami r6, {r1, r4, r8, r12, sp, pc} ^ */
/* @0x2a3cf0 and r4, r1, r8, ror r4 */
/* @0x2a3cf4 ldrbtmi r4, [r8], #-2117 */
/* @0x2a3cf8 andhs r2, r4, #1073741824 */
/* @0x2a3cfc .word 0xf6124623 */
/* @0x2a3d00 ldmdblt lr, {r1, r2, r3, r4, r6, r7, r8, r10, r11, sp, lr, pc} */
/* @0x2a3d04 strtmi r8, [r1], -r8, lsr #16 */
/* @0x2a3d08 mrc2 p7, #0x2, apsr_nzcv, c14, c15, #0x7 */
/* @0x2a3d0c strtmi r8, [r1], -r8, ror #16 */
/* @0x2a3d10 mrc2 p7, #0x2, apsr_nzcv, c10, c15, #0x7 */
/* @0x2a3d14 strtmi r8, [r1], -r8, lsr #17 */
/* @0x2a3d18 mrc2 p7, #0x2, apsr_nzcv, c6, c15, #0x7 */
/* @0x2a3d1c stmhi r8!, {r0, r5, r9, r10, lr} ^ */
/* @0x2a3d20 mrc2 p7, #0x2, apsr_nzcv, c2, c15, #0x7 */
/* @0x2a3d24 stmdage r2, {r0, r1, r3, r5, r7, r11, sp, lr} */
/* @0x2a3d28 stclo p8, c15, [r4, #-256] */
/* @0x2a3d2c stm r10!, {r0, r1, r4, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2a3d30 stmdbvs r2, {r0, r5, r9, r10, lr} */
/* @0x2a3d34 andlo r6, r1, #1097728 */
/* @0x2a3d38 cmpeq r2, r0, asr r11 */
/* @0x2a3d3c stmdahs r3, {r1, r8, r9, r11, sp, lr, pc} ^ */
/* @0x2a3d40 stmvs r2, {r0, r1, r6, r7, r11, sp, lr} */
/* @0x2a3d44 blx 0xa74e58 <b2_toiTime+0x31b9b4> */
/* @0x2a3d48 stmdavs r3, {r0, r1, r7, r11, r12, sp, lr, pc} ^ */
/* @0x2a3d4c sbcseq r6, r2, #0, #16 */
/* @0x2a3d50 movtne lr, #0x3b02 */
/* @0x2a3d54 rsbeq lr, r0, r3, lsl #22 */
/* @0x2a3d58 .word 0xf7ffb280 */
/* @0x2a3d5c .word 0x4640fe35 */
/* @0x2a3d60 .word 0xf7ff4621 */
/* @0x2a3d64 stmvs r8!, {r0, r4, r5, r9, r10, r11, r12, sp, lr, pc} ^ */
/* @0x2a3d68 .word 0xf7ff4621 */
/* @0x2a3d6c stmdbvs r8!, {r0, r1, r2, r4, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2a3d70 .word 0xf7ff4621 */
/* @0x2a3d74 stmdbvs r8!, {r0, r1, r4, r9, r10, r11, r12, sp, lr, pc} ^ */
/* @0x2a3d78 .word 0xf7ff4621 */
/* @0x2a3d7c blhi 0xfece35c0 <b2_toiTime+0xfffffffffe58a11c> */
/* @0x2a3d80 .word 0xf7ff4621 */
/* @0x2a3d84 stchi p14, c15, [r8], #132 */
/* @0x2a3d88 .word 0xf7ff4621 */
/* @0x2a3d8c ldmiblt lr, {r0, r2, r3, r4, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2a3d90 strtmi r8, [r1], -r8, lsr #27 */
/* @0x2a3d94 mrc2 p7, #0x0, apsr_nzcv, c8, c15, #0x7 */
/* @0x2a3d98 strtmi r8, [r1], -r8, ror #27 */
/* @0x2a3d9c mrc2 p7, #0x0, apsr_nzcv, c4, c15, #0x7 */
/* @0x2a3da0 strtmi r8, [r1], -r8, lsr #28 */
/* @0x2a3da4 mrc2 p7, #0x0, apsr_nzcv, c0, c15, #0x7 */
/* @0x2a3da8 strtmi r6, [r1], -r8, ror #22 */
/* @0x2a3dac ldc2l p7, c15, [r6, #1020]! */
/* @0x2a3db0 strtmi r6, [r1], -r8, lsr #23 */
/* @0x2a3db4 ldc2l p7, c15, [r2, #1020]! */
/* @0x2a3db8 smulwblt r2, r10, r11 */
/* @0x2a3dbc smlatbhs r1, r8, r9, r6 */
/* @0x2a3dc0 .word 0xf6124623 */
/* @0x2a3dc4 stchi p13, c14, [r10], #496 */
/* @0x2a3dc8 bvs 0xcd0258 <b2_toiTime+0x576db4> */
/* @0x2a3dcc strtmi r2, [r3], -r1, lsl #2 */
/* @0x2a3dd0 ldcl p6, c15, [r4, #-72]! */
/* @0x2a3dd4 stchi p9, c11, [r10, #216]! */
/* @0x2a3dd8 bvs 0xfecd0268 <b2_toiTime+0xfffffffffe576dc4> */
/* @0x2a3ddc strtmi r2, [r3], -r1, lsl #2 */
/* @0x2a3de0 stcl p6, c15, [r12, #-72]! */
/* @0x2a3de4 .word 0xf00089a0 */
/* @0x2a3de8 addlt r0, r0, #64 */
/* @0x2a3dec .word 0xf612b140 */
/* @0x2a3df0 .word 0x2106ef04 */
/* @0x2a3df4 ldrtmi r6, [r8], -r2, lsl #16 */
/* @0x2a3df8 blx 0xfee5fe00 <b2_toiTime+0xfffffffffe70695c> */
/* @0x2a3dfc rscslo pc, pc, pc, asr #32 */
/* @0x2a3e00 pop {r1, r12, sp, pc} */
/* @0x2a3e04 svclt #0x81f0 */
/* @0x2a3e08 andeq r8, lr, lr, lsl #6 */
/* @0x2a3e0c andeq r8, lr, sp, lsl #6 */
/* @0x2a3e10 mvnsmi lr, sp, lsr #18 */
/* @0x2a3e14 strmi r4, [r8], -r5, lsl #12 */
/* @0x2a3e18 ldrmi r4, [r7], -r12, lsl #12 */
/* @0x2a3e1c stmda r0!, {r0, r1, r4, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2a3e20 .word 0xf04f2600 */
/* @0x2a3e24 rscvs r0, r8, r12, lsr r8 */
/* @0x2a3e28 addsmi r6, lr, #7012352 */
/* @0x2a3e2c stmdavs r8!, {r0, r1, r3, r9, r11, r12, lr, pc} */
/* @0x2a3e30 andhs r4, r0, #34603008 */
/* @0x2a3e34 blx 0x4b572a <SrcVerts+0x1276e> */
/* @0x2a3e38 .word 0xf7ff0006 */
/* @0x2a3e3c stmdahs r0, {r0, r4, r6, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2a3e40 .word 0x3601d138 */
/* @0x2a3e44 qsub8mi lr, r0, r0 */
/* @0x2a3e48 stmda r10, {r0, r1, r4, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2a3e4c andhs r6, r4, #15400960 */
/* @0x2a3e50 bne 0xff2ac25c <b2_toiTime+0xfffffffffeb52db8> */
/* @0x2a3e54 ldmdami r9, {r3, r5, r7, sp, lr} */
/* @0x2a3e58 ldrbtmi r4, [r8], #-1571 */
/* @0x2a3e5c stc p6, c15, [lr, #-72]! */
/* @0x2a3e60 strtmi r2, [r1], -r0 */
/* @0x2a3e64 ldc2 p7, c15, [r10, #1020] */
/* @0x2a3e68 strtmi r8, [r1], -r8, lsr #17 */
/* @0x2a3e6c stc2 p7, c15, [r12, #1020]! */
/* @0x2a3e70 strtmi r8, [r1], -r8, lsr #17 */
/* @0x2a3e74 stc2 p7, c15, [r8, #1020]! */
/* @0x2a3e78 strtmi r6, [r1], -r8, lsr #17 */
/* @0x2a3e7c stc2 p7, c15, [lr, #1020] */
/* @0x2a3e80 strtmi r6, [r1], -r8, ror #17 */
/* @0x2a3e84 stc2 p7, c15, [r10, #1020] */
/* @0x2a3e88 strtmi r8, [r1], -r8, lsr #21 */
/* @0x2a3e8c ldc2 p7, c15, [r12, #1020] */
/* @0x2a3e90 .word 0x21016928 */
/* @0x2a3e94 strtmi r8, [r3], -r10, lsr #21 */
/* @0x2a3e98 ldc p6, c15, [r0, #-72] */
/* @0x2a3e9c .word 0xf00089a0 */
/* @0x2a3ea0 addlt r0, r0, #64 */
/* @0x2a3ea4 .word 0xf612b140 */
/* @0x2a3ea8 smlatbhs r6, r8, lr, lr */
/* @0x2a3eac ldrtmi r6, [r8], -r2, lsl #16 */
/* @0x2a3eb0 blx 0x175feb8 <b2_toiTime+0x1006a14> */
/* @0x2a3eb4 rscslo pc, pc, pc, asr #32 */
/* @0x2a3eb8 ldrhhi lr, [r0, #141]! */
/* @0x2a3ebc andeq r8, lr, lr, lsr #3 */
/* @0x2a3ec0 ldmdavc r9, {r0, r1, r11, sp, lr} ^ */
/* @0x2a3ec4 blhs 0x361f18 <_ZTS12CDS_Priority+0x3f70> */
/* @0x2a3ec8 andhs lr, r1, #2048 */
/* @0x2a3ecc addslt r6, r0, #3 */
/* @0x2a3ed0 stmdavs r3, {r4, r5, r6, r8, r9, r10, lr} */

/* ── FUNC 0x2a3c2d · _zip_dirent_init(zip_dirent*) · size=42 · insn=0 */

/* ── FUNC 0x2a3c59 · _zip_dirent_torrent_normalize(zip_dirent*) · size=136 · insn=0 */

/* ── FUNC 0x2a3ce1 · _zip_dirent_write(zip_dirent*, __sFILE*, int, zip_error*) · size=304 · insn=0 */

/* ── FUNC 0x2a3e11 · _zip_cdir_write(zip_cdir*, __sFILE*, zip_error*) · size=176 · insn=0 */

/* ── FUNC 0x2a3ec1 · _zip_read2(unsigned char**) · size=18 · insn=0 */

/* ── FUNC 0x2a3ed2 · anon_2a3ed2 · size=32 · insn=8 */
/* @0x2a3ed2 ldmvc r9, {r0, r1, r11, sp, lr} ^ */
/* @0x2a3ed6 bl 0x342146 */
/* @0x2a3eda ldmdavc r10, {r0, r8, sp} ^ */
/* @0x2a3ede .word 0x2101eb02 */
/* @0x2a3ee2 blhs 0x3e1f36 <error_g0017+0x3abda> */
/* @0x2a3ee6 bl 0x33befa */
/* @0x2a3eea ldrbmi r2, [r0, -r1]! */
/* @0x2a3eee .word 0xe92d0000 */

/* ── FUNC 0x2a3ed3 · _zip_read4(unsigned char**) · size=28 · insn=0 */

/* ── FUNC 0x2a3ef0 · anon_2a3ef0 · size=1072 · insn=268 */
/* @0x2a3ef0 svcmi #0xf0e92d */
/* @0x2a3ef4 bmi 0xfe2f5940 <b2_toiTime+0xfffffffffdb9c49c> */
/* @0x2a3ef8 addslt r4, r1, r10, lsl #13 */
/* @0x2a3efc ldrbtmi r4, [r10], #-1540 */
/* @0x2a3f00 sadd16mi r6, pc, r2 */
/* @0x2a3f04 ldmdavs r1, {r0, r1, r3, r4, r9, r10, r11, r12, pc} */
/* @0x2a3f08 .word 0x910f9201 */
/* @0x2a3f0c stmdbhs r0, {r1, r3, r4, r8, r11, r12, pc} */
/* @0x2a3f10 .word 0xf04fbf0c */
/* @0x2a3f14 .word 0xf04f0b2e */
/* @0x2a3f18 teqlt r3, lr, lsl r11 */
/* @0x2a3f1c ldrbmi r6, [r11, #-0x81b] */
/* @0x2a3f20 ldrtmi sp, [r0], -r3, lsl #4 */
/* @0x2a3f24 andhs r2, r0, #-1073741820 */
/* @0x2a3f28 .word 0xf1b9e016 */
/* @0x2a3f2c andle r0, r3, r0, lsl #30 */
/* @0x2a3f30 .word 0x3000f8d9 */
/* @0x2a3f34 ands r9, r2, r2, lsl #6 */
/* @0x2a3f38 mrshs r10, apsr */
/* @0x2a3f3c usaxmi r4, r3, r10 */
/* @0x2a3f40 .word 0xf6124628 */
/* @0x2a3f44 ldrbmi lr, [r8, #-0xcc2] */
/* @0x2a3f48 strls r11, [r2, #-0xf28] */
/* @0x2a3f4c .word 0xf612d207 */
/* @0x2a3f50 qaddhs lr, r4, r5 */
/* @0x2a3f54 ldrtmi r6, [r0], -r2, lsl #16 */
/* @0x2a3f58 .word 0xf9fef000 */
/* @0x2a3f5c bls 0x95c170 <b2_toiTime+0x202ccc> */
/* @0x2a3f60 tstlt r2, r2, lsl #26 */
/* @0x2a3f64 ldrbtmi r4, [r9], #-2406 */
/* @0x2a3f68 stmdbmi r6!, {r0, sp, lr, pc} ^ */
/* @0x2a3f6c qsub16mi r4, r8, r9 */
/* @0x2a3f70 .word 0xf6122204 */
/* @0x2a3f74 strmi lr, [r0], r6, ror #28 */
/* @0x2a3f78 bicsle r2, r2, r0, lsl #16 */
/* @0x2a3f7c ldcge p13, c1, [r0, #-172] */
/* @0x2a3f80 ldclo p8, c15, [r8, #-276]! */
/* @0x2a3f84 stmdblt r3!, {r1, r3, r4, r8, r9, r11, r12, pc} */
/* @0x2a3f88 .word 0xf7ff4628 */
/* @0x2a3f8c mlahi r0, r9, pc, pc */
/* @0x2a3f90 eorhi lr, r0, r0 */
/* @0x2a3f94 .word 0xf7ff4628 */
/* @0x2a3f98 mlshi r0, r3, pc, pc */
/* @0x2a3f9c .word 0xf7ff4628 */
/* @0x2a3fa0 adchi pc, r0, pc, lsl #31 */
/* @0x2a3fa4 .word 0xf7ff4628 */
/* @0x2a3fa8 rschi pc, r0, r11, lsl #31 */
/* @0x2a3fac .word 0xf7ff4628 */
/* @0x2a3fb0 strmi pc, [r3], -r7, lsl #31 */
/* @0x2a3fb4 movwls r4, #0x628 */
/* @0x2a3fb8 .word 0xff82f7ff */
/* @0x2a3fbc strmi r9, [r1], -r0, lsl #22 */
/* @0x2a3fc0 .word 0xf7ff4618 */
/* @0x2a3fc4 adcvs pc, r0, r8, asr #26 */
/* @0x2a3fc8 .word 0xf7ff4628 */
/* @0x2a3fcc rscvs pc, r0, r2, lsl #31 */
/* @0x2a3fd0 .word 0xf7ff4628 */
/* @0x2a3fd4 .word 0x6120ff7e */
/* @0x2a3fd8 .word 0xf7ff4628 */
/* @0x2a3fdc .word 0x6160ff7a */
/* @0x2a3fe0 .word 0xf7ff4628 */
/* @0x2a3fe4 movhi pc, #436 */
/* @0x2a3fe8 .word 0xf7ff4628 */
/* @0x2a3fec ldmdbls r10, {r0, r3, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2a3ff0 teqlt r1, r0, lsr #9 */
/* @0x2a3ff4 strhi r2, [r3, #0x300]! */
/* @0x2a3ff8 strthi r8, [r3], -r3, ror #11 */
/* @0x2a3ffc .word 0x63a36363 */
/* @0x2a4000 qadd16mi lr, r8, r3 */
/* @0x2a4004 .word 0xff5cf7ff */
/* @0x2a4008 strtmi r8, [r8], -r0, lsr #11 */
/* @0x2a400c .word 0xff58f7ff */
/* @0x2a4010 strtmi r8, [r8], -r0, ror #11 */
/* @0x2a4014 .word 0xff54f7ff */
/* @0x2a4018 strtmi r8, [r8], -r0, lsr #12 */
/* @0x2a401c .word 0xff59f7ff */
/* @0x2a4020 strtmi r6, [r8], -r0, ror #6 */
/* @0x2a4024 .word 0xff55f7ff */
/* @0x2a4028 movwhs r6, #0x3a0 */
/* @0x2a402c .word 0x61a38ba1 */
/* @0x2a4030 adcvs r6, r3, #805306370 */
/* @0x2a4034 stchi p12, c8, [r2, #652]! */
/* @0x2a4038 ldrmi r4, [r3], #-1035 */
/* @0x2a403c .word 0xb11f449b */
/* @0x2a4040 ldrbmi r6, [r11, #-0x83b] */
/* @0x2a4044 svcge #0x6df4ff */
/* @0x2a4048 svceq #0xf1b9 */
/* @0x2a404c ldmdblt r1, {r1, r5, r12, lr, pc} */
/* @0x2a4050 orrslt r8, r9, r1, lsr #25 */
/* @0x2a4054 strtmi lr, [r8], -r10 */
/* @0x2a4058 ldrtmi r2, [r3], -r1, lsl #4 */
/* @0x2a405c ldc2 p7, c15, [r12, #-1020] */
/* @0x2a4060 stmdahs r0, {r5, r7, r8, sp, lr} */
/* @0x2a4064 .word 0xf04fd1f4 */
/* @0x2a4068 ldrsht r3, [r7], -pc */
/* @0x2a406c andhs r4, r0, #40, #12 */
/* @0x2a4070 .word 0xf7ff4633 */
/* @0x2a4074 eorvs pc, r0, #1088 */
/* @0x2a4078 rscsle r2, r4, r0, lsl #16 */
/* @0x2a407c stmdbhs r0, {r0, r5, r7, r8, r10, r11, pc} */
/* @0x2a4080 qasxmi sp, r8, r4 */
/* @0x2a4084 ldrtmi r2, [r3], -r0, lsl #4 */
/* @0x2a4088 stc2 p7, c15, [r6, #-1020] */
/* @0x2a408c stmdahs r0, {r5, r7, r9, sp, lr} */
/* @0x2a4090 strb sp, [r8, r12, lsr #2]! */
/* @0x2a4094 stchi p9, c11, [r1], #68 */
/* @0x2a4098 and r11, r8, r9, lsl #3 */
/* @0x2a409c andhs r4, r1, #80, #12 */
/* @0x2a40a0 .word 0xf7ff4633 */
/* @0x2a40a4 .word 0x61a0fc9d */
/* @0x2a40a8 mvnsle r2, r0, lsl #16 */
/* @0x2a40ac .word 0x4650e7db */
/* @0x2a40b0 ldrtmi r2, [r3], -r0, lsl #4 */
/* @0x2a40b4 ldc2 p7, c15, [r4], {255} */
/* @0x2a40b8 stmdahs r0, {r5, r9, sp, lr} */
/* @0x2a40bc stchi p0, c13, [r1, #844]! */
/* @0x2a40c0 uasxmi r11, r0, r9 */
/* @0x2a40c4 ldrtmi r2, [r3], -r0, lsl #4 */
/* @0x2a40c8 stc2 p7, c15, [r10], {255} */
/* @0x2a40cc stmdahs r0, {r5, r7, r9, sp, lr} */
/* @0x2a40d0 tstlt pc, r9, asr #1 */
/* @0x2a40d4 bl 0xff57e1c8 <b2_toiTime+0xfffffffffee24d24> */
/* @0x2a40d8 eorsvs r0, r11, r3, lsl #6 */
/* @0x2a40dc strbmi r9, [r0], -r1, lsl #18 */
/* @0x2a40e0 stmdavs r11, {r0, r1, r2, r3, r9, r11, r12, pc} */
/* @0x2a40e4 mulle r5, r10, r2 */
/* @0x2a40e8 b 0x1fe1938 <b2_toiTime+0x1888494> */
/* @0x2a40ec .word 0xf8c99b02 */
/* @0x2a40f0 strb r3, [lr, r0]! */
/* @0x2a40f4 pop {r0, r4, r12, sp, pc} */
/* @0x2a40f8 svclt #0x8ff0 */
/* @0x2a40fc andseq r9, r4, r6, asr r10 */
/* @0x2a4100 muleq lr, r8, r0 */
/* @0x2a4104 muleq lr, r7, r0 */
/* @0x2a4108 svcmi #0xf0e92d */
/* @0x2a410c bmi 0x21b5b58 <b2_toiTime+0x1a5c6b4> */
/* @0x2a4110 addslt r4, r1, r10, lsl #13 */
/* @0x2a4114 ldrbtmi r4, [r10], #-1540 */
/* @0x2a4118 sadd16mi r6, lr, r2 */
/* @0x2a411c ldmdavs r1, {r0, r1, r3, r4, r8, r9, r10, r11, r12, pc} */
/* @0x2a4120 .word 0x910f9201 */
/* @0x2a4124 stmdbhs r0, {r1, r3, r4, r8, r11, r12, pc} */
/* @0x2a4128 .word 0xf04fbf0c */
/* @0x2a412c .word 0xf04f0b2e */
/* @0x2a4130 .word 0xb1430b1e */
/* @0x2a4134 ldrbmi r6, [r11, #-0x81b] */
/* @0x2a4138 ldrtmi sp, [r8], -r5, lsl #4 */
/* @0x2a413c andhs r2, r0, #-1073741820 */
/* @0x2a4140 .word 0xf90af000 */
/* @0x2a4144 .word 0xf1b9e092 */
/* @0x2a4148 andle r0, r3, r0, lsl #30 */
/* @0x2a414c .word 0x3000f8d9 */
/* @0x2a4150 and r9, r7, r2, lsl #6 */
/* @0x2a4154 ldrbmi r10, [r0], -r3, lsl #26 */
/* @0x2a4158 ldrbmi r2, [r11], -r1, lsl #4 */
/* @0x2a415c .word 0xf6294629 */
/* @0x2a4160 strls lr, [r2, #-0xd9e] */
/* @0x2a4164 vstrls s18, [r2, #-104] */
/* @0x2a4168 stmdbmi r6!, {r1, r4, r8, r12, sp, pc} ^ */
/* @0x2a416c and r4, r1, r9, ror r4 */
/* @0x2a4170 ldrbtmi r4, [r9], #-2405 */
/* @0x2a4174 andhs r4, r4, #40, #12 */
/* @0x2a4178 stcl p6, c15, [r2, #-72]! */
/* @0x2a417c stmdahs r0, {r7, r9, r10, lr} */
/* @0x2a4180 stcne p1, c13, [r11, #-876]! */
/* @0x2a4184 .word 0xf845ad10 */
/* @0x2a4188 blls 0x933670 <b2_toiTime+0x1da1cc> */
/* @0x2a418c strtmi r11, [r8], -r3, lsr #18 */
/* @0x2a4190 mrc2 p7, #0x4, apsr_nzcv, c6, c15, #0x7 */
/* @0x2a4194 and r8, r0, r0, lsr #32 */
/* @0x2a4198 strtmi r8, [r8], -r0, lsr #32 */
/* @0x2a419c mrc2 p7, #0x4, apsr_nzcv, c0, c15, #0x7 */
/* @0x2a41a0 strtmi r8, [r8], -r0, rrx */
/* @0x2a41a4 mcr2 p7, #0x4, pc, c12, c15, #0x7 */
/* @0x2a41a8 strtmi r8, [r8], -r0, lsr #1 */
/* @0x2a41ac mcr2 p7, #0x4, pc, c8, c15, #0x7 */
/* @0x2a41b0 strtmi r8, [r8], -r0, ror #1 */
/* @0x2a41b4 mcr2 p7, #0x4, pc, c4, c15, #0x7 */
/* @0x2a41b8 strtmi r4, [r8], -r3, lsl #12 */
/* @0x2a41bc .word 0xf7ff9300 */
/* @0x2a41c0 blls 0x2e3bc4 <_ZN11b2GearJoint4DumpEv+0xb8> */
/* @0x2a41c4 ldrmi r4, [r8], -r1, lsl #12 */
/* @0x2a41c8 mcrr2 p7, #0xf, pc, r5, c15 */
/* @0x2a41cc strtmi r6, [r8], -r0, lsr #1 */
/* @0x2a41d0 mrc2 p7, #0x3, apsr_nzcv, c15, c15, #0x7 */
/* @0x2a41d4 strtmi r6, [r8], -r0, ror #1 */
/* @0x2a41d8 mrc2 p7, #0x3, apsr_nzcv, c11, c15, #0x7 */
/* @0x2a41dc strtmi r6, [r8], -r0, lsr #2 */
/* @0x2a41e0 mrc2 p7, #0x3, apsr_nzcv, c7, c15, #0x7 */
/* @0x2a41e4 strtmi r6, [r8], -r0, ror #2 */
/* @0x2a41e8 mcr2 p7, #0x3, pc, c10, c15, #0x7 */
/* @0x2a41ec strtmi r8, [r8], -r0, lsr #7 */
/* @0x2a41f0 mcr2 p7, #0x3, pc, c6, c15, #0x7 */
/* @0x2a41f4 strthi r9, [r0], #2330 */
/* @0x2a41f8 movwhs r11, #0x131 */
/* @0x2a41fc strbhi r8, [r3, #0x5a3]! */
/* @0x2a4200 .word 0x63638623 */
/* @0x2a4204 ands r6, r3, r3, lsr #7 */
/* @0x2a4208 .word 0xf7ff4628 */
/* @0x2a420c strhi pc, [r0, #0xe59]! */
/* @0x2a4210 .word 0xf7ff4628 */
/* @0x2a4214 strbhi pc, [r0, #0xe55]! */
/* @0x2a4218 .word 0xf7ff4628 */
/* @0x2a421c qsaxhi pc, r0, r1 */
/* @0x2a4220 .word 0xf7ff4628 */
/* @0x2a4224 msrvs SPSR, #1376 */
/* @0x2a4228 .word 0xf7ff4628 */
/* @0x2a422c movvs pc, #1312 */
/* @0x2a4230 blhi 0xfeaece38 <b2_toiTime+0xfffffffffe393994> */
/* @0x2a4234 eorvs r6, r3, #-1073741784 */
/* @0x2a4238 stchi p2, c6, [r3], #652 */
/* @0x2a423c strmi r8, [r11], #-3490 */
/* @0x2a4240 ldrmi r4, [r11], #1043 */
/* @0x2a4244 ldmdavs r3!, {r1, r2, r3, r4, r8, r12, sp, pc} */
/* @0x2a4248 .word 0xf4ff455b */
/* @0x2a424c .word 0xf1b9af76 */
/* @0x2a4250 eorle r0, r2, r0, lsl #30 */
/* @0x2a4254 stchi p9, c11, [r1], #68 */
/* @0x2a4258 mul r10, r9, r1 */
/* @0x2a425c andhs r4, r1, #40, #12 */
/* @0x2a4260 .word 0xf7ff463b */
/* @0x2a4264 lslvs pc, r9, r12 */
/* @0x2a4268 mvnsle r2, r0, lsl #16 */
/* @0x2a426c ldmlo pc!, {r0, r1, r2, r3, r6, r12, sp, lr, pc} ^ */
/* @0x2a4270 qasxmi lr, r8, r7 */
/* @0x2a4274 ldrtmi r2, [r11], -r0, lsl #4 */
/* @0x2a4278 .word 0xfc0ef7ff */
/* @0x2a427c stmdahs r0, {r5, r9, sp, lr} */
/* @0x2a4280 stchi p0, c13, [r1, #976]! */
/* @0x2a4284 eorsle r2, r4, r0, lsl #18 */
/* @0x2a4288 andhs r4, r0, #40, #12 */
/* @0x2a428c .word 0xf7ff463b */
/* @0x2a4290 adcvs pc, r0, #768 */
/* @0x2a4294 .word 0xd12c2800 */
/* @0x2a4298 ldmdblt r1, {r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2a429c orrlt r8, r9, r1, lsr #25 */
/* @0x2a42a0 ldrbmi lr, [r0], -r8 */
/* @0x2a42a4 ldrtmi r2, [r11], -r1, lsl #4 */
/* @0x2a42a8 stc2 p7, c15, [r4], #-1020 */
/* @0x2a42ac stmdahs r0, {r5, r7, r8, sp, lr} */
/* @0x2a42b0 .word 0xe7dbd1f4 */
/* @0x2a42b4 andhs r4, r0, #80, #12 */
/* @0x2a42b8 .word 0xf7ff463b */
/* @0x2a42bc eorvs pc, r0, #6912 */
/* @0x2a42c0 sbcsle r2, r3, r0, lsl #16 */
/* @0x2a42c4 teqlt r9, r1, lsr #27 */
/* @0x2a42c8 andhs r4, r0, #80, #12 */
/* @0x2a42cc .word 0xf7ff463b */
/* @0x2a42d0 adcvs pc, r0, #4352 */
/* @0x2a42d4 sbcle r2, r9, r0, lsl #16 */
/* @0x2a42d8 ldmdavs r3!, {r1, r2, r3, r4, r8, r12, sp, pc} */
/* @0x2a42dc movweq lr, #0x3bcb */
/* @0x2a42e0 stmdbls r1, {r0, r1, r4, r5, sp, lr} */
/* @0x2a42e4 bls 0x675bec <g_SWFlinevertbuff+0x22b24> */
/* @0x2a42e8 addsmi r6, r10, #720896 */
/* @0x2a42ec .word 0xf612d005 */
/* @0x2a42f0 blls 0x35e8c0 <_ZTS12CDS_Priority+0x918> */
/* @0x2a42f4 andlo pc, r0, r9, asr #17 */
/* @0x2a42f8 andslt lr, r1, lr, ror #15 */
/* @0x2a42fc svchi #0xf0e8bd */
/* @0x2a4300 andseq r9, r4, lr, lsr r8 */
/* @0x2a4304 muleq lr, r2, lr */
/* @0x2a4308 muleq lr, r1, lr */
/* @0x2a430c andvs r2, r3, r0, lsl #6 */
/* @0x2a4310 ldrbmi r6, [r0, -r3, asr #32]! */
/* @0x2a4314 andvs r6, r3, r11, lsl #16 */
/* @0x2a4318 subvs r6, r3, r11, asr #16 */
/* @0x2a431c ldrlt r4, [r0, #-0x770] */

/* ── FUNC 0x2a3ef1 · _zip_dirent_read(zip_dirent*, __sFILE*, unsigned char**, unsigned int*, int, zip_error*) · size=536 · insn=0 */

/* ── FUNC 0x2a4109 · _zip_dirent_read_buff(zip_dirent*, IBuffer*, unsigned char**, unsigned int*, int, zip_error*) · size=516 · insn=0 */

/* ── FUNC 0x2a430d · _zip_error_clear(zip_error*) · size=8 · insn=0 */

/* ── FUNC 0x2a4315 · _zip_error_copy(zip_error*, zip_error*) · size=10 · insn=0 */

/* ── FUNC 0x2a431e · anon_2a431e · size=60 · insn=15 */
/* @0x2a431e .word 0x4604b510 */
/* @0x2a4322 .word 0xf6126880 */
/* @0x2a4326 movwhs lr, #0x91a */
/* @0x2a432a ldclt p0, c6, [r0, #-652] */
/* @0x2a432e .word 0x4604b538 */
/* @0x2a4332 .word 0xb1094615 */
/* @0x2a4336 andvs r6, r11, r3, lsl #16 */
/* @0x2a433a stmdavs r0!, {r0, r2, r3, r4, r5, r8, r12, sp, pc} */
/* @0x2a433e .word 0xf80ff000 */
/* @0x2a4342 stmdavs r3!, {r4, r8, r12, sp, pc} ^ */
/* @0x2a4346 ldclt p0, c6, [r8, #-172]! */
/* @0x2a434a ldclt p0, c6, [r8, #-160]! */
/* @0x2a434e andvs r2, r3, r0, lsl #6 */
/* @0x2a4352 addvs r6, r3, r3, asr #32 */
/* @0x2a4356 .word 0xb1084770 */

/* ── FUNC 0x2a431f · _zip_error_fini(zip_error*) · size=16 · insn=0 */

/* ── FUNC 0x2a432f · _zip_error_get(zip_error*, int*, int*) · size=32 · insn=0 */

/* ── FUNC 0x2a434f · _zip_error_init(zip_error*) · size=10 · insn=0 */
