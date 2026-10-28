/* libyoyo.so 覆盖卡组 0139
 * 函数 0x1a7be8..0x1a8728，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1a7be8 · Path_Quit() · size=192 · insn=48 */
/* @0x1a7be8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1a7bec ldr r3, [pc, #0xa0] */
/* @0x1a7bf0 add r3, pc, r3 */
/* @0x1a7bf4 ldr r3, [r3, #0x4] */
/* @0x1a7bf8 cmp r3, #0 */
/* @0x1a7bfc popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1a7c00 ldr r5, [pc, #0x90] */
/* @0x1a7c04 ldr r5, [pc, r5] */
/* @0x1a7c08 ldr r2, [r5] */
/* @0x1a7c0c cmp r2, #0 */
/* @0x1a7c10 ble 0x1a7c50 <_Z9Path_Quitv+0x68> */
/* @0x1a7c14 ldr r6, [pc, #0x80] */
/* @0x1a7c18 mov r4, #0 */
/* @0x1a7c1c mov r7, r4 */
/* @0x1a7c20 add r6, pc, r6 */
/* @0x1a7c24 ldr r0, [r3, r4, lsl #2] */
/* @0x1a7c28 cmp r0, #0 */
/* @0x1a7c2c beq 0x1a7c40 <_Z9Path_Quitv+0x58> */
/* @0x1a7c30 bl 0x1a6ffc <_ZN5CPath4FreeEv> */
/* @0x1a7c34 ldr r3, [r6, #0x4] */
/* @0x1a7c38 str r7, [r3, r4, lsl #2] */
/* @0x1a7c3c ldr r3, [r6, #0x4] */
/* @0x1a7c40 ldr r2, [r5] */
/* @0x1a7c44 add r4, r4, #1 */
/* @0x1a7c48 cmp r2, r4 */
/* @0x1a7c4c bgt 0x1a7c24 <_Z9Path_Quitv+0x3c> */
/* @0x1a7c50 ldr r4, [pc, #0x48] */
/* @0x1a7c54 mov r0, r3 */
/* @0x1a7c58 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a7c5c ldr r3, [pc, #0x40] */
/* @0x1a7c60 ldr r4, [pc, r4] */
/* @0x1a7c64 mov r2, #0 */
/* @0x1a7c68 add r3, pc, r3 */
/* @0x1a7c6c ldr r0, [r4] */
/* @0x1a7c70 str r2, [r3, #0x4] */
/* @0x1a7c74 cmp r0, r2 */
/* @0x1a7c78 str r2, [r3] */
/* @0x1a7c7c beq 0x1a7c84 <_Z9Path_Quitv+0x9c> */
/* @0x1a7c80 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a7c84 mov r3, #0 */
/* @0x1a7c88 str r3, [r4] */
/* @0x1a7c8c str r3, [r5] */
/* @0x1a7c90 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1a7c94 eorseq r10, r9, r8, lsr r9 */
/* @0x1a7c98 eoreq r8, r4, r8, asr #23 */
/* @0x1a7c9c eorseq r10, r9, r8, lsl #18 */
/* @0x1a7ca0 eoreq r8, r4, r0, ror r11 */
/* @0x1a7ca4 eorseq r10, r9, r0, asr #17 */

/* ── FUNC 0x1a7ca8 · Path_Init() · size=4 · insn=1 */
/* @0x1a7ca8 b 0x1a7be8 <_Z9Path_Quitv> */

/* ── FUNC 0x1a7cac · Path_Load(CStream*) · size=456 · insn=114 */
/* @0x1a7cac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1a7cb0 sub sp, sp, #20 */
/* @0x1a7cb4 str r0, [sp, #0x8] */
/* @0x1a7cb8 bl 0x1a7ca8 <_Z9Path_Initv> */
/* @0x1a7cbc ldr r0, [sp, #0x8] */
/* @0x1a7cc0 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1a7cc4 cmp r0, #800 */
/* @0x1a7cc8 cmpne r0, #420 */
/* @0x1a7ccc mov r6, r0 */
/* @0x1a7cd0 moveq r4, #0 */
/* @0x1a7cd4 movne r4, #1 */
/* @0x1a7cd8 beq 0x1a7ce8 <_Z9Path_LoadP7CStream+0x3c> */
/* @0x1a7cdc mov r0, #0 */
/* @0x1a7ce0 add sp, sp, #20 */
/* @0x1a7ce4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1a7ce8 ldr r0, [sp, #0x8] */
/* @0x1a7cec bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1a7cf0 ldr r5, [pc, #0x168] */
/* @0x1a7cf4 ldr r9, [pc, #0x168] */
/* @0x1a7cf8 mov r3, #106 */
/* @0x1a7cfc ldr r10, [pc, #0x164] */
/* @0x1a7d00 add r5, pc, r5 */
/* @0x1a7d04 ldr r9, [pc, r9] */
/* @0x1a7d08 ldr r11, [pc, #0x15c] */
/* @0x1a7d0c add r10, pc, r10 */
/* @0x1a7d10 mov r2, r5 */
/* @0x1a7d14 mov lr, r0 */
/* @0x1a7d18 lsl r1, r0, #2 */
/* @0x1a7d1c add r0, r10, #4 */
/* @0x1a7d20 str lr, [r9] */
/* @0x1a7d24 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1a7d28 ldr lr, [r9] */
/* @0x1a7d2c ldr r11, [pc, r11] */
/* @0x1a7d30 mov r3, #108 */
/* @0x1a7d34 mov r2, r5 */
/* @0x1a7d38 mov r0, r11 */
/* @0x1a7d3c lsl r1, lr, #2 */
/* @0x1a7d40 str lr, [r10] */
/* @0x1a7d44 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1a7d48 ldr r3, [r9] */
/* @0x1a7d4c cmp r3, #0 */
/* @0x1a7d50 ble 0x1a7e44 <_Z9Path_LoadP7CStream+0x198> */
/* @0x1a7d54 ldr r3, [pc, #0x114] */
/* @0x1a7d58 mov r8, r4 */
/* @0x1a7d5c mov r7, r4 */
/* @0x1a7d60 add r3, pc, r3 */
/* @0x1a7d64 str r3, [sp, #0xc] */
/* @0x1a7d68 b 0x1a7d7c <_Z9Path_LoadP7CStream+0xd0> */
/* @0x1a7d6c ldr r2, [r9] */
/* @0x1a7d70 add r8, r8, #1 */
/* @0x1a7d74 cmp r2, r8 */
/* @0x1a7d78 ble 0x1a7e44 <_Z9Path_LoadP7CStream+0x198> */
/* @0x1a7d7c cmp r6, #800 */
/* @0x1a7d80 ldrne r4, [sp, #0x8] */
/* @0x1a7d84 beq 0x1a7e50 <_Z9Path_LoadP7CStream+0x1a4> */
/* @0x1a7d88 mov r0, r4 */
/* @0x1a7d8c lsl r5, r8, #2 */
/* @0x1a7d90 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1a7d94 ldr r2, [r10, #0x4] */
/* @0x1a7d98 str r7, [r2, r8, lsl #2] */
/* @0x1a7d9c ldr r2, [r11] */
/* @0x1a7da0 str r7, [r2, r8, lsl #2] */
/* @0x1a7da4 cmp r0, #0 */
/* @0x1a7da8 beq 0x1a7e14 <_Z9Path_LoadP7CStream+0x168> */
/* @0x1a7dac ldr r2, [r11] */
/* @0x1a7db0 add r1, r2, r5 */
/* @0x1a7db4 ldr r0, [r2, r8, lsl #2] */
/* @0x1a7db8 cmp r0, #0 */
/* @0x1a7dbc beq 0x1a7dd4 <_Z9Path_LoadP7CStream+0x128> */
/* @0x1a7dc0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a7dc4 ldr r2, [r11] */
/* @0x1a7dc8 str r7, [r2, r5] */
/* @0x1a7dcc ldr r1, [r11] */
/* @0x1a7dd0 add r1, r1, r5 */
/* @0x1a7dd4 mov r0, r4 */
/* @0x1a7dd8 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* @0x1a7ddc mov r0, #44 */
/* @0x1a7de0 bl 0x27c524 <_Znwj> */
/* @0x1a7de4 str r0, [sp, #0x4] */
/* @0x1a7de8 bl 0x1a6e9c <_ZN5CPathC2Ev> */
/* @0x1a7dec ldr r3, [sp, #0xc] */
/* @0x1a7df0 mov r1, r4 */
/* @0x1a7df4 ldr r2, [sp, #0x4] */
/* @0x1a7df8 ldr r0, [r3, #0x4] */
/* @0x1a7dfc str r2, [r0, r5] */
/* @0x1a7e00 ldr r2, [r3, #0x4] */
/* @0x1a7e04 ldr r0, [r2, r5] */
/* @0x1a7e08 bl 0x1a7018 <_ZN5CPath14LoadFromStreamEP7CStream> */
/* @0x1a7e0c cmp r0, #0 */
/* @0x1a7e10 beq 0x1a7cdc <_Z9Path_LoadP7CStream+0x30> */
/* @0x1a7e14 cmp r6, #800 */
/* @0x1a7e18 bne 0x1a7d6c <_Z9Path_LoadP7CStream+0xc0> */
/* @0x1a7e1c cmp r4, #0 */
/* @0x1a7e20 beq 0x1a7d6c <_Z9Path_LoadP7CStream+0xc0> */
/* @0x1a7e24 mov r0, r4 */
/* @0x1a7e28 add r8, r8, #1 */
/* @0x1a7e2c bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x1a7e30 mov r0, r4 */
/* @0x1a7e34 bl 0x27d1d0 <_ZdlPv> */
/* @0x1a7e38 ldr r2, [r9] */
/* @0x1a7e3c cmp r2, r8 */
/* @0x1a7e40 bgt 0x1a7d7c <_Z9Path_LoadP7CStream+0xd0> */
/* @0x1a7e44 mov r0, #1 */
/* @0x1a7e48 add sp, sp, #20 */
/* @0x1a7e4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1a7e50 ldr r0, [sp, #0x8] */
/* @0x1a7e54 bl 0x201db0 <_ZN7CStream20ReadCompressedStreamEv> */
/* @0x1a7e58 mov r4, r0 */
/* @0x1a7e5c b 0x1a7d88 <_Z9Path_LoadP7CStream+0xdc> */
/* @0x1a7e60 andseq r5, r10, r12, lsl #8 */
/* @0x1a7e64 eoreq r8, r4, r8, asr #21 */
/* @0x1a7e68 eorseq r10, r9, r12, lsl r8 */
/* @0x1a7e6c eoreq r8, r4, r4, lsr #21 */
/* @0x1a7e70 eorseq r10, r9, r8, asr #15 */

/* ── FUNC 0x1a7e74 · Path_Load(unsigned char*, unsigned int, unsigned char*) · size=384 · insn=96 */
/* @0x1a7e74 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1a7e78 sub sp, sp, #20 */
/* @0x1a7e7c ldr r9, [r0] */
/* @0x1a7e80 mov r3, #138 */
/* @0x1a7e84 ldr r4, [pc, #0x150] */
/* @0x1a7e88 mov r8, r0 */
/* @0x1a7e8c ldr r12, [pc, #0x14c] */
/* @0x1a7e90 ldr r10, [pc, #0x14c] */
/* @0x1a7e94 add r4, pc, r4 */
/* @0x1a7e98 lsl r5, r9, #2 */
/* @0x1a7e9c ldr r12, [pc, r12] */
/* @0x1a7ea0 add r10, pc, r10 */
/* @0x1a7ea4 ldr r6, [pc, #0x13c] */
/* @0x1a7ea8 str r2, [sp, #0x8] */
/* @0x1a7eac add r0, r10, #4 */
/* @0x1a7eb0 mov r2, r4 */
/* @0x1a7eb4 mov r1, r5 */
/* @0x1a7eb8 str r9, [r12] */
/* @0x1a7ebc bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1a7ec0 ldr r6, [pc, r6] */
/* @0x1a7ec4 mov r1, r5 */
/* @0x1a7ec8 mov r2, r4 */
/* @0x1a7ecc mov r3, #140 */
/* @0x1a7ed0 mov r0, r6 */
/* @0x1a7ed4 str r9, [r10] */
/* @0x1a7ed8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1a7edc cmp r9, #0 */
/* @0x1a7ee0 beq 0x1a7fc8 <_Z9Path_LoadPhjS_+0x154> */
/* @0x1a7ee4 ldr r3, [pc, #0x100] */
/* @0x1a7ee8 mov r4, #0 */
/* @0x1a7eec str r9, [sp, #0x4] */
/* @0x1a7ef0 add r3, pc, r3 */
/* @0x1a7ef4 str r3, [sp, #0xc] */
/* @0x1a7ef8 b 0x1a7fb4 <_Z9Path_LoadPhjS_+0x140> */
/* @0x1a7efc ldr r9, [pc, #0xec] */
/* @0x1a7f00 ldr r9, [pc, r9] */
/* @0x1a7f04 ldr r11, [r9] */
/* @0x1a7f08 adds r1, r11, r5 */
/* @0x1a7f0c beq 0x1a7fd4 <_Z9Path_LoadPhjS_+0x160> */
/* @0x1a7f10 mov r0, #44 */
/* @0x1a7f14 str r1, [sp] */
/* @0x1a7f18 bl 0x27c524 <_Znwj> */
/* @0x1a7f1c mov r7, r0 */
/* @0x1a7f20 bl 0x1a6e9c <_ZN5CPathC2Ev> */
/* @0x1a7f24 ldr r1, [sp] */
/* @0x1a7f28 mov r0, r7 */
/* @0x1a7f2c ldr r2, [sp, #0x8] */
/* @0x1a7f30 bl 0x1a7120 <_ZN5CPath13LoadFromChunkEP6YYPathPh> */
/* @0x1a7f34 ldr r12, [r11, r5] */
/* @0x1a7f38 cmp r12, #0 */
/* @0x1a7f3c ldrne r3, [r9] */
/* @0x1a7f40 moveq r11, r12 */
/* @0x1a7f44 addne r11, r3, r12 */
/* @0x1a7f48 mov r0, r11 */
/* @0x1a7f4c bl 0xb6538 <strlen@plt> */
/* @0x1a7f50 ldr r1, [sp, #0xc] */
/* @0x1a7f54 mov r3, #1 */
/* @0x1a7f58 mov r2, #151 */
/* @0x1a7f5c add r0, r0, r3 */
/* @0x1a7f60 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1a7f64 mov r1, r11 */
/* @0x1a7f68 mov r5, r0 */
/* @0x1a7f6c bl 0xb65a4 <strcpy@plt> */
/* @0x1a7f70 ldr r2, [r6] */
/* @0x1a7f74 lsl r11, r4, #2 */
/* @0x1a7f78 ldr r0, [r2, r4, lsl #2] */
/* @0x1a7f7c cmp r0, #0 */
/* @0x1a7f80 beq 0x1a7f94 <_Z9Path_LoadPhjS_+0x120> */
/* @0x1a7f84 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a7f88 ldr r2, [r6] */
/* @0x1a7f8c mov r3, #0 */
/* @0x1a7f90 str r3, [r2, r4, lsl #2] */
/* @0x1a7f94 ldr r2, [r10, #0x4] */
/* @0x1a7f98 add r4, r4, #1 */
/* @0x1a7f9c ldr r3, [sp, #0x4] */
/* @0x1a7fa0 str r7, [r2, r11] */
/* @0x1a7fa4 cmp r4, r3 */
/* @0x1a7fa8 ldr r2, [r6] */
/* @0x1a7fac str r5, [r2, r11] */
/* @0x1a7fb0 beq 0x1a7fc8 <_Z9Path_LoadPhjS_+0x154> */
/* @0x1a7fb4 ldr r5, [r8, #0x4]! */
/* @0x1a7fb8 cmp r5, #0 */
/* @0x1a7fbc bne 0x1a7efc <_Z9Path_LoadPhjS_+0x88> */
/* @0x1a7fc0 mov r7, r5 */
/* @0x1a7fc4 b 0x1a7f70 <_Z9Path_LoadPhjS_+0xfc> */
/* @0x1a7fc8 mov r0, #1 */
/* @0x1a7fcc add sp, sp, #20 */
/* @0x1a7fd0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1a7fd4 mov r5, r1 */
/* @0x1a7fd8 b 0x1a7fc0 <_Z9Path_LoadPhjS_+0x14c> */
/* @0x1a7fdc andseq r5, r10, r8, ror r2 */
/* @0x1a7fe0 eoreq r8, r4, r0, lsr r9 */
/* @0x1a7fe4 eorseq r10, r9, r8, lsl #13 */
/* @0x1a7fe8 eoreq r8, r4, r0, lsl r9 */
/* @0x1a7fec andseq r5, r10, r12, lsl r2 */
/* @0x1a7ff0 eoreq r5, r4, r4, asr #20 */

/* ── FUNC 0x1a7ff4 · Path_Number() · size=20 · insn=5 */
/* @0x1a7ff4 ldr r3, [pc, #0x8] */
/* @0x1a7ff8 ldr r3, [pc, r3] */
/* @0x1a7ffc ldr r0, [r3] */
/* @0x1a8000 bx lr */
/* @0x1a8004 .word 0x002487d4 */

/* ── FUNC 0x1a8008 · Path_Exists(int) · size=72 · insn=18 */
/* @0x1a8008 cmp r0, #0 */
/* @0x1a800c blt 0x1a8040 <_Z11Path_Existsi+0x38> */
/* @0x1a8010 ldr r3, [pc, #0x30] */
/* @0x1a8014 ldr r3, [pc, r3] */
/* @0x1a8018 ldr r3, [r3] */
/* @0x1a801c cmp r0, r3 */
/* @0x1a8020 bge 0x1a8040 <_Z11Path_Existsi+0x38> */
/* @0x1a8024 ldr r3, [pc, #0x20] */
/* @0x1a8028 add r3, pc, r3 */
/* @0x1a802c ldr r3, [r3, #0x4] */
/* @0x1a8030 ldr r0, [r3, r0, lsl #2] */
/* @0x1a8034 adds r0, r0, #0 */
/* @0x1a8038 movne r0, #1 */
/* @0x1a803c bx lr */
/* @0x1a8040 mov r0, #0 */
/* @0x1a8044 bx lr */
/* @0x1a8048 .word 0x002487b8 */
/* @0x1a804c eorseq r10, r9, r0, lsl #10 */

/* ── FUNC 0x1a8050 · Path_Name(int) · size=132 · insn=33 */
/* @0x1a8050 cmp r0, #0 */
/* @0x1a8054 blt 0x1a80a4 <_Z9Path_Namei+0x54> */
/* @0x1a8058 ldr r3, [pc, #0x5c] */
/* @0x1a805c ldr r3, [pc, r3] */
/* @0x1a8060 ldr r3, [r3] */
/* @0x1a8064 cmp r0, r3 */
/* @0x1a8068 bge 0x1a8098 <_Z9Path_Namei+0x48> */
/* @0x1a806c ldr r3, [pc, #0x4c] */
/* @0x1a8070 add r3, pc, r3 */
/* @0x1a8074 ldr r3, [r3, #0x4] */
/* @0x1a8078 ldr r3, [r3, r0, lsl #2] */
/* @0x1a807c cmp r3, #0 */
/* @0x1a8080 beq 0x1a80b0 <_Z9Path_Namei+0x60> */
/* @0x1a8084 ldr r3, [pc, #0x38] */
/* @0x1a8088 ldr r3, [pc, r3] */
/* @0x1a808c ldr r3, [r3] */
/* @0x1a8090 ldr r0, [r3, r0, lsl #2] */
/* @0x1a8094 bx lr */
/* @0x1a8098 ldr r0, [pc, #0x28] */
/* @0x1a809c add r0, pc, r0 */
/* @0x1a80a0 bx lr */
/* @0x1a80a4 ldr r0, [pc, #0x20] */
/* @0x1a80a8 add r0, pc, r0 */
/* @0x1a80ac bx lr */
/* @0x1a80b0 ldr r0, [pc, #0x18] */
/* @0x1a80b4 add r0, pc, r0 */
/* @0x1a80b8 bx lr */
/* @0x1a80bc eoreq r8, r4, r0, ror r7 */
/* @0x1a80c0 ldrhteq r10, [r9], -r8 */
/* @0x1a80c4 eoreq r8, r4, r8, asr #14 */
/* @0x1a80c8 andseq r8, r8, r4, lsr #20 */
/* @0x1a80cc andseq r8, r8, r8, lsl r10 */
/* @0x1a80d0 andseq r8, r8, r12, lsl #20 */

/* ── FUNC 0x1a80d4 · Path_Find(char const*) · size=136 · insn=34 */
/* @0x1a80d4 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1a80d8 mov r7, r0 */
/* @0x1a80dc ldr r3, [pc, #0x6c] */
/* @0x1a80e0 ldr r3, [pc, r3] */
/* @0x1a80e4 ldr r6, [r3] */
/* @0x1a80e8 cmp r6, #0 */
/* @0x1a80ec ble 0x1a8140 <_Z9Path_FindPKc+0x6c> */
/* @0x1a80f0 ldr r3, [pc, #0x5c] */
/* @0x1a80f4 mov r4, #0 */
/* @0x1a80f8 ldr r2, [pc, #0x58] */
/* @0x1a80fc mov r5, r4 */
/* @0x1a8100 ldr r3, [pc, r3] */
/* @0x1a8104 add r2, pc, r2 */
/* @0x1a8108 ldr r9, [r3] */
/* @0x1a810c ldr r8, [r2, #0x4] */
/* @0x1a8110 ldr r3, [r8, r4] */
/* @0x1a8114 mov r1, r7 */
/* @0x1a8118 cmp r3, #0 */
/* @0x1a811c beq 0x1a8130 <_Z9Path_FindPKc+0x5c> */
/* @0x1a8120 ldr r0, [r9, r4] */
/* @0x1a8124 bl 0xb6574 <strcmp@plt> */
/* @0x1a8128 cmp r0, #0 */
/* @0x1a812c beq 0x1a8148 <_Z9Path_FindPKc+0x74> */
/* @0x1a8130 add r5, r5, #1 */
/* @0x1a8134 add r4, r4, #4 */
/* @0x1a8138 cmp r5, r6 */
/* @0x1a813c bne 0x1a8110 <_Z9Path_FindPKc+0x3c> */
/* @0x1a8140 mvn r0, #0 */
/* @0x1a8144 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1a8148 mov r0, r5 */
/* @0x1a814c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1a8150 eoreq r8, r4, r12, ror #13 */
/* @0x1a8154 .word 0x002486d0 */
/* @0x1a8158 eorseq r10, r9, r4, lsr #8 */

/* ── FUNC 0x1a815c · Path_Data(int) · size=64 · insn=16 */
/* @0x1a815c cmp r0, #0 */
/* @0x1a8160 blt 0x1a818c <_Z9Path_Datai+0x30> */
/* @0x1a8164 ldr r3, [pc, #0x28] */
/* @0x1a8168 ldr r3, [pc, r3] */
/* @0x1a816c ldr r3, [r3] */
/* @0x1a8170 cmp r0, r3 */
/* @0x1a8174 bge 0x1a818c <_Z9Path_Datai+0x30> */
/* @0x1a8178 ldr r3, [pc, #0x18] */
/* @0x1a817c add r3, pc, r3 */
/* @0x1a8180 ldr r3, [r3, #0x4] */
/* @0x1a8184 ldr r0, [r3, r0, lsl #2] */
/* @0x1a8188 bx lr */
/* @0x1a818c mov r0, #0 */
/* @0x1a8190 bx lr */
/* @0x1a8194 eoreq r8, r4, r4, ror #12 */
/* @0x1a8198 eorseq r10, r9, r12, lsr #7 */

/* ── FUNC 0x1a819c · Path_Add() · size=260 · insn=65 */
/* @0x1a819c push {r4, r5, r6, r7, r8, lr} */
/* @0x1a81a0 sub sp, sp, #264 */
/* @0x1a81a4 ldr r4, [pc, #0xdc] */
/* @0x1a81a8 movw r3, #0x112 */
/* @0x1a81ac ldr r5, [pc, #0xd8] */
/* @0x1a81b0 ldr r4, [pc, r4] */
/* @0x1a81b4 ldr r8, [pc, #0xd4] */
/* @0x1a81b8 ldr r5, [pc, r5] */
/* @0x1a81bc ldr r7, [pc, #0xd0] */
/* @0x1a81c0 ldr r12, [r4] */
/* @0x1a81c4 add r8, pc, r8 */
/* @0x1a81c8 ldr lr, [r5] */
/* @0x1a81cc add r7, pc, r7 */
/* @0x1a81d0 add r12, r12, #1 */
/* @0x1a81d4 mov r2, r8 */
/* @0x1a81d8 add r0, r7, #4 */
/* @0x1a81dc ldr r6, [pc, #0xb4] */
/* @0x1a81e0 lsl r1, r12, #2 */
/* @0x1a81e4 str lr, [sp, #0x104] */
/* @0x1a81e8 str r12, [r4] */
/* @0x1a81ec bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1a81f0 ldr r12, [r4] */
/* @0x1a81f4 ldr r6, [pc, r6] */
/* @0x1a81f8 mov r2, r8 */
/* @0x1a81fc mov r3, #276 */
/* @0x1a8200 mov r0, r6 */
/* @0x1a8204 add r8, sp, #4 */
/* @0x1a8208 lsl r1, r12, #2 */
/* @0x1a820c str r12, [r7] */
/* @0x1a8210 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1a8214 ldr r3, [r4] */
/* @0x1a8218 ldr r2, [pc, #0x7c] */
/* @0x1a821c mov r1, #256 */
/* @0x1a8220 mov r0, r8 */
/* @0x1a8224 sub r3, r3, #1 */
/* @0x1a8228 add r2, pc, r2 */
/* @0x1a822c bl 0xb65c8 <snprintf@plt> */
/* @0x1a8230 ldr r3, [r4] */
/* @0x1a8234 mov r0, r8 */
/* @0x1a8238 ldr r6, [r6] */
/* @0x1a823c sub r8, r3, #-1073741823 */
/* @0x1a8240 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1a8244 str r0, [r6, r8, lsl #2] */
/* @0x1a8248 mov r0, #44 */
/* @0x1a824c bl 0x27c524 <_Znwj> */
/* @0x1a8250 mov r6, r0 */
/* @0x1a8254 bl 0x1a6e9c <_ZN5CPathC2Ev> */
/* @0x1a8258 ldr r0, [r4] */
/* @0x1a825c ldr r1, [r7, #0x4] */
/* @0x1a8260 sub r12, r0, #-1073741823 */
/* @0x1a8264 ldr r2, [sp, #0x104] */
/* @0x1a8268 sub r0, r0, #1 */
/* @0x1a826c str r6, [r1, r12, lsl #2] */
/* @0x1a8270 ldr r3, [r5] */
/* @0x1a8274 cmp r2, r3 */
/* @0x1a8278 bne 0x1a8284 <_Z8Path_Addv+0xe8> */
/* @0x1a827c add sp, sp, #264 */
/* @0x1a8280 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1a8284 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1a8288 eoreq r8, r4, r12, lsl r6 */
/* @0x1a828c mlaeq r4, r8, r7, r5 */
/* @0x1a8290 andseq r4, r10, r8, asr #30 */
/* @0x1a8294 eorseq r10, r9, r12, asr r3 */
/* @0x1a8298 .word 0x002485dc */
/* @0x1a829c andseq r4, r10, r8, lsl pc */

/* ── FUNC 0x1a82a0 · Path_Delete(int) · size=128 · insn=32 */
/* @0x1a82a0 push {r4, r5, r6, lr} */
/* @0x1a82a4 subs r4, r0, #0 */
/* @0x1a82a8 blt 0x1a830c <_Z11Path_Deletei+0x6c> */
/* @0x1a82ac ldr r3, [pc, #0x60] */
/* @0x1a82b0 ldr r3, [pc, r3] */
/* @0x1a82b4 ldr r3, [r3] */
/* @0x1a82b8 cmp r4, r3 */
/* @0x1a82bc bge 0x1a830c <_Z11Path_Deletei+0x6c> */
/* @0x1a82c0 ldr r6, [pc, #0x50] */
/* @0x1a82c4 add r6, pc, r6 */
/* @0x1a82c8 ldr r3, [r6, #0x4] */
/* @0x1a82cc ldr r0, [r3, r4, lsl #2] */
/* @0x1a82d0 cmp r0, #0 */
/* @0x1a82d4 popeq {r4, r5, r6, pc} */
/* @0x1a82d8 ldr r5, [pc, #0x3c] */
/* @0x1a82dc bl 0x1a6ffc <_ZN5CPath4FreeEv> */
/* @0x1a82e0 ldr r3, [r6, #0x4] */
/* @0x1a82e4 mov r6, #0 */
/* @0x1a82e8 ldr r5, [pc, r5] */
/* @0x1a82ec str r6, [r3, r4, lsl #2] */
/* @0x1a82f0 ldr r3, [r5] */
/* @0x1a82f4 ldr r0, [r3, r4, lsl #2] */
/* @0x1a82f8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a82fc ldr r3, [r5] */
/* @0x1a8300 mov r0, #1 */
/* @0x1a8304 str r6, [r3, r4, lsl #2] */
/* @0x1a8308 pop {r4, r5, r6, pc} */
/* @0x1a830c mov r0, #0 */
/* @0x1a8310 pop {r4, r5, r6, pc} */
/* @0x1a8314 eoreq r8, r4, r12, lsl r5 */
/* @0x1a8318 eorseq r10, r9, r4, ror #4 */
/* @0x1a831c eoreq r8, r4, r8, ror #9 */

/* ── FUNC 0x1a8320 · Path_Duplicate(int) · size=320 · insn=80 */
/* @0x1a8320 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1a8324 subs r8, r0, #0 */
/* @0x1a8328 ldr r6, [pc, #0x118] */
/* @0x1a832c sub sp, sp, #268 */
/* @0x1a8330 ldr r6, [pc, r6] */
/* @0x1a8334 ldr r3, [r6] */
/* @0x1a8338 str r3, [sp, #0x104] */
/* @0x1a833c blt 0x1a843c <_Z14Path_Duplicatei+0x11c> */
/* @0x1a8340 ldr r4, [pc, #0x104] */
/* @0x1a8344 ldr r4, [pc, r4] */
/* @0x1a8348 ldr r3, [r4] */
/* @0x1a834c cmp r8, r3 */
/* @0x1a8350 bge 0x1a843c <_Z14Path_Duplicatei+0x11c> */
/* @0x1a8354 ldr r5, [pc, #0xf4] */
/* @0x1a8358 add r5, pc, r5 */
/* @0x1a835c ldr r2, [r5, #0x4] */
/* @0x1a8360 ldr r2, [r2, r8, lsl #2] */
/* @0x1a8364 cmp r2, #0 */
/* @0x1a8368 beq 0x1a843c <_Z14Path_Duplicatei+0x11c> */
/* @0x1a836c ldr r9, [pc, #0xe0] */
/* @0x1a8370 add r12, r3, #1 */
/* @0x1a8374 add r0, r5, #4 */
/* @0x1a8378 mov r3, #336 */
/* @0x1a837c add r9, pc, r9 */
/* @0x1a8380 lsl r1, r12, #2 */
/* @0x1a8384 ldr r7, [pc, #0xcc] */
/* @0x1a8388 mov r2, r9 */
/* @0x1a838c str r12, [r4] */
/* @0x1a8390 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1a8394 ldr r12, [r4] */
/* @0x1a8398 ldr r7, [pc, r7] */
/* @0x1a839c mov r2, r9 */
/* @0x1a83a0 movw r3, #0x152 */
/* @0x1a83a4 add r9, sp, #4 */
/* @0x1a83a8 lsl r1, r12, #2 */
/* @0x1a83ac mov r0, r7 */
/* @0x1a83b0 str r12, [r5] */
/* @0x1a83b4 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1a83b8 ldr r3, [r4] */
/* @0x1a83bc mov r1, #256 */
/* @0x1a83c0 ldr r2, [pc, #0x94] */
/* @0x1a83c4 mov r0, r9 */
/* @0x1a83c8 sub r3, r3, #1 */
/* @0x1a83cc add r2, pc, r2 */
/* @0x1a83d0 bl 0xb65c8 <snprintf@plt> */
/* @0x1a83d4 ldr r3, [r4] */
/* @0x1a83d8 mov r0, r9 */
/* @0x1a83dc ldr r7, [r7] */
/* @0x1a83e0 sub r9, r3, #-1073741823 */
/* @0x1a83e4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1a83e8 str r0, [r7, r9, lsl #2] */
/* @0x1a83ec mov r0, #44 */
/* @0x1a83f0 bl 0x27c524 <_Znwj> */
/* @0x1a83f4 mov r7, r0 */
/* @0x1a83f8 bl 0x1a6e9c <_ZN5CPathC2Ev> */
/* @0x1a83fc ldr r2, [r4] */
/* @0x1a8400 ldr r3, [r5, #0x4] */
/* @0x1a8404 sub r2, r2, #-1073741823 */
/* @0x1a8408 str r7, [r3, r2, lsl #2] */
/* @0x1a840c ldr r3, [r5, #0x4] */
/* @0x1a8410 ldr r0, [r3, r2, lsl #2] */
/* @0x1a8414 ldr r1, [r3, r8, lsl #2] */
/* @0x1a8418 bl 0x1a6ed0 <_ZN5CPath6AssignEPS_> */
/* @0x1a841c ldr r0, [r4] */
/* @0x1a8420 sub r0, r0, #1 */
/* @0x1a8424 ldr r2, [sp, #0x104] */
/* @0x1a8428 ldr r3, [r6] */
/* @0x1a842c cmp r2, r3 */
/* @0x1a8430 bne 0x1a8444 <_Z14Path_Duplicatei+0x124> */
/* @0x1a8434 add sp, sp, #268 */
/* @0x1a8438 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1a843c mvn r0, #0 */
/* @0x1a8440 b 0x1a8424 <_Z14Path_Duplicatei+0x104> */
/* @0x1a8444 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1a8448 eoreq r5, r4, r0, lsr #12 */
/* @0x1a844c eoreq r8, r4, r8, lsl #9 */
/* @0x1a8450 ldrsbteq r10, [r9], -r0 */
/* @0x1a8454 mulseq r10, r0, sp */
/* @0x1a8458 eoreq r8, r4, r8, lsr r4 */
/* @0x1a845c andseq r4, r10, r4, ror sp */

/* ── FUNC 0x1a8460 · Path_Assign(int, int) · size=184 · insn=46 */
/* @0x1a8460 push {r3, r4, r5, r6, r7, lr} */
/* @0x1a8464 subs r4, r1, #0 */
/* @0x1a8468 mov r5, r0 */
/* @0x1a846c blt 0x1a84dc <_Z11Path_Assignii+0x7c> */
/* @0x1a8470 ldr r3, [pc, #0x94] */
/* @0x1a8474 ldr r3, [pc, r3] */
/* @0x1a8478 ldr r3, [r3] */
/* @0x1a847c cmp r4, r3 */
/* @0x1a8480 bge 0x1a84dc <_Z11Path_Assignii+0x7c> */
/* @0x1a8484 ldr r6, [pc, #0x84] */
/* @0x1a8488 add r6, pc, r6 */
/* @0x1a848c ldr r2, [r6, #0x4] */
/* @0x1a8490 ldr r1, [r2, r4, lsl #2] */
/* @0x1a8494 cmp r1, #0 */
/* @0x1a8498 beq 0x1a84dc <_Z11Path_Assignii+0x7c> */
/* @0x1a849c cmp r0, #0 */
/* @0x1a84a0 blt 0x1a84dc <_Z11Path_Assignii+0x7c> */
/* @0x1a84a4 cmp r3, r0 */
/* @0x1a84a8 ble 0x1a84dc <_Z11Path_Assignii+0x7c> */
/* @0x1a84ac cmp r0, r4 */
/* @0x1a84b0 beq 0x1a84cc <_Z11Path_Assignii+0x6c> */
/* @0x1a84b4 ldr r0, [r2, r0, lsl #2] */
/* @0x1a84b8 cmp r0, #0 */
/* @0x1a84bc beq 0x1a84e4 <_Z11Path_Assignii+0x84> */
/* @0x1a84c0 bl 0x1a6ed0 <_ZN5CPath6AssignEPS_> */
/* @0x1a84c4 mov r0, #1 */
/* @0x1a84c8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1a84cc ldr r0, [pc, #0x40] */
/* @0x1a84d0 mov r1, #0 */
/* @0x1a84d4 add r0, pc, r0 */
/* @0x1a84d8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1a84dc mov r0, #0 */
/* @0x1a84e0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1a84e4 mov r0, #44 */
/* @0x1a84e8 bl 0x27c524 <_Znwj> */
/* @0x1a84ec mov r7, r0 */
/* @0x1a84f0 bl 0x1a6e9c <_ZN5CPathC2Ev> */
/* @0x1a84f4 ldr r3, [r6, #0x4] */
/* @0x1a84f8 str r7, [r3, r5, lsl #2] */
/* @0x1a84fc ldr r3, [r6, #0x4] */
/* @0x1a8500 ldr r0, [r3, r5, lsl #2] */
/* @0x1a8504 ldr r1, [r3, r4, lsl #2] */
/* @0x1a8508 b 0x1a84c0 <_Z11Path_Assignii+0x60> */
/* @0x1a850c eoreq r8, r4, r8, asr r3 */
/* @0x1a8510 eorseq r10, r9, r0, lsr #1 */
/* @0x1a8514 andseq r4, r10, r8, ror r12 */

/* ── FUNC 0x1a8518 · INITIALIZE_Path() · size=28 · insn=7 */
/* @0x1a8518 ldr r3, [pc, #0x10] */
/* @0x1a851c mov r2, #0 */
/* @0x1a8520 add r3, pc, r3 */
/* @0x1a8524 str r2, [r3, #0x4] */
/* @0x1a8528 str r2, [r3] */
/* @0x1a852c bx lr */
/* @0x1a8530 eorseq r10, r9, r8 */

/* ── FUNC 0x1a8534 · IYYFont::~IYYFont() · size=24 · insn=6 */
/* @0x1a8534 ldr r3, [pc, #0xc] */
/* @0x1a8538 ldr r3, [pc, r3] */
/* @0x1a853c add r3, r3, #8 */
/* @0x1a8540 str r3, [r0] */
/* @0x1a8544 bx lr */
/* @0x1a8548 mlaeq r4, r12, r2, r8 */

/* ── FUNC 0x1a8534 · IYYFont::~IYYFont() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1a854c · TFont::GetColor() · size=8 · insn=2 */
/* @0x1a854c ldr r0, [r0, #0x4] */
/* @0x1a8550 bx lr */

/* ── FUNC 0x1a8554 · TFont::GetName() · size=8 · insn=2 */
/* @0x1a8554 ldr r0, [r0, #0x8] */
/* @0x1a8558 bx lr */

/* ── FUNC 0x1a855c · TFont::GetSize() · size=8 · insn=2 */
/* @0x1a855c ldr r0, [r0, #0xc] */
/* @0x1a8560 bx lr */

/* ── FUNC 0x1a8564 · TFont::GetStyle() · size=8 · insn=2 */
/* @0x1a8564 ldr r0, [r0, #0x10] */
/* @0x1a8568 bx lr */

/* ── FUNC 0x1a856c · TFont::GetYYHandle() · size=8 · insn=2 */
/* @0x1a856c ldr r0, [r0, #0x14] */
/* @0x1a8570 bx lr */

/* ── FUNC 0x1a8574 · IYYFont::~IYYFont() · size=40 · insn=10 */
/* @0x1a8574 ldr r3, [pc, #0x1c] */
/* @0x1a8578 push {r4, lr} */
/* @0x1a857c ldr r3, [pc, r3] */
/* @0x1a8580 mov r4, r0 */
/* @0x1a8584 add r3, r3, #8 */
/* @0x1a8588 str r3, [r0] */
/* @0x1a858c bl 0x27d1d0 <_ZdlPv> */
/* @0x1a8590 mov r0, r4 */
/* @0x1a8594 pop {r4, pc} */
/* @0x1a8598 eoreq r8, r4, r8, asr r2 */

/* ── FUNC 0x1a859c · TFont::SetColor(unsigned int) · size=8 · insn=2 */
/* @0x1a859c str r1, [r0, #0x4] */
/* @0x1a85a0 b 0x1a8850 <_ZN5TFont6CreateEv> */

/* ── FUNC 0x1a85a4 · TFont::SetSize(int) · size=8 · insn=2 */
/* @0x1a85a4 str r1, [r0, #0xc] */
/* @0x1a85a8 b 0x1a8850 <_ZN5TFont6CreateEv> */

/* ── FUNC 0x1a85ac · TFont::SetStyle(unsigned int) · size=8 · insn=2 */
/* @0x1a85ac str r1, [r0, #0x10] */
/* @0x1a85b0 b 0x1a8850 <_ZN5TFont6CreateEv> */

/* ── FUNC 0x1a85b4 · TFont::SetName(char const*) · size=52 · insn=13 */
/* @0x1a85b4 push {r3, r4, r5, lr} */
/* @0x1a85b8 mov r4, r0 */
/* @0x1a85bc ldr r0, [r0, #0x8] */
/* @0x1a85c0 mov r5, r1 */
/* @0x1a85c4 cmp r0, #0 */
/* @0x1a85c8 beq 0x1a85d0 <_ZN5TFont7SetNameEPKc+0x1c> */
/* @0x1a85cc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1a85d0 mov r0, r5 */
/* @0x1a85d4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1a85d8 str r0, [r4, #0x8] */
/* @0x1a85dc mov r0, r4 */
/* @0x1a85e0 pop {r3, r4, r5, lr} */
/* @0x1a85e4 b 0x1a8850 <_ZN5TFont6CreateEv> */

/* ── FUNC 0x1a85e8 · TFont::Assign(IYYFont*) · size=148 · insn=37 */
/* @0x1a85e8 push {r3, r4, r5, lr} */
/* @0x1a85ec mov r5, r0 */
/* @0x1a85f0 ldr r3, [r1] */
/* @0x1a85f4 mov r0, r1 */
/* @0x1a85f8 mov r4, r1 */
/* @0x1a85fc ldr r3, [r3, #0x8] */
/* @0x1a8600 blx r3 */
/* @0x1a8604 ldr r3, [r5, #0x8] */
/* @0x1a8608 cmp r3, #0 */
/* @0x1a860c str r0, [r5, #0x4] */
/* @0x1a8610 beq 0x1a861c <_ZN5TFont6AssignEP7IYYFont+0x34> */
/* @0x1a8614 mov r0, r3 */
/* @0x1a8618 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1a861c ldr r3, [r4] */
/* @0x1a8620 mov r0, r4 */
/* @0x1a8624 ldr r3, [r3, #0x10] */
/* @0x1a8628 blx r3 */
/* @0x1a862c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1a8630 ldr r3, [r4] */
/* @0x1a8634 str r0, [r5, #0x8] */
/* @0x1a8638 mov r0, r4 */
/* @0x1a863c ldr r3, [r3, #0x18] */
/* @0x1a8640 blx r3 */
/* @0x1a8644 ldr r3, [r4] */
/* @0x1a8648 ldr r3, [r3, #0x24] */
/* @0x1a864c str r0, [r5, #0xc] */
/* @0x1a8650 mov r0, r4 */
/* @0x1a8654 blx r3 */
/* @0x1a8658 str r0, [r5, #0x10] */
/* @0x1a865c mov r0, r5 */
/* @0x1a8660 bl 0x1a8850 <_ZN5TFont6CreateEv> */
/* @0x1a8664 ldr r3, [r4] */
/* @0x1a8668 mov r0, r4 */
/* @0x1a866c ldr r3, [r3, #0x2c] */
/* @0x1a8670 blx r3 */
/* @0x1a8674 str r0, [r5, #0x14] */
/* @0x1a8678 pop {r3, r4, r5, pc} */

/* ── FUNC 0x1a867c · TFont::TFont() · size=48 · insn=12 */
/* @0x1a867c ldr r1, [pc, #0x24] */
/* @0x1a8680 mov r2, #0 */
/* @0x1a8684 str r2, [r0, #0x4] */
/* @0x1a8688 ldr r1, [pc, r1] */
/* @0x1a868c str r2, [r0, #0x8] */
/* @0x1a8690 add r1, r1, #8 */
/* @0x1a8694 str r2, [r0, #0xc] */
/* @0x1a8698 str r1, [r0] */
/* @0x1a869c str r2, [r0, #0x10] */
/* @0x1a86a0 str r2, [r0, #0x14] */
/* @0x1a86a4 bx lr */
/* @0x1a86a8 eoreq r8, r4, r0, asr r1 */

/* ── FUNC 0x1a867c · TFont::TFont() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1a86ac · RomDisk::Init(unsigned char*) · size=80 · insn=20 */
/* @0x1a86ac ldr r1, [pc, #0x40] */
/* @0x1a86b0 mov r3, #0 */
/* @0x1a86b4 ldr r2, [pc, #0x3c] */
/* @0x1a86b8 ldr r1, [pc, r1] */
/* @0x1a86bc ldr r2, [pc, r2] */
/* @0x1a86c0 str r3, [r1] */
/* @0x1a86c4 ldr r12, [r0] */
/* @0x1a86c8 str r0, [r2] */
/* @0x1a86cc cmp r12, r3 */
/* @0x1a86d0 bxle lr */
/* @0x1a86d4 add r12, r0, r12, lsl #3 */
/* @0x1a86d8 ldr r2, [r0, #0x4] */
/* @0x1a86dc add r0, r0, #8 */
/* @0x1a86e0 cmp r0, r12 */
/* @0x1a86e4 add r3, r3, r2 */
/* @0x1a86e8 str r3, [r1] */
/* @0x1a86ec bne 0x1a86d8 <_ZN7RomDisk4InitEPh+0x2c> */
/* @0x1a86f0 bx lr */
/* @0x1a86f4 eoreq r8, r4, r4, lsr #2 */
/* @0x1a86f8 eoreq r8, r4, r4, lsr #2 */

/* ── FUNC 0x1a86fc · RomDisk::Load(int) · size=44 · insn=11 */
/* @0x1a86fc ldr r3, [pc, #0x20] */
/* @0x1a8700 ldr r3, [pc, r3] */
/* @0x1a8704 ldr r3, [r3] */
/* @0x1a8708 ldr r2, [r3] */
/* @0x1a870c cmp r2, r0 */
/* @0x1a8710 addgt r0, r3, r0, lsl #3 */
/* @0x1a8714 ldrgt r0, [r0, #0x8] */
/* @0x1a8718 addgt r0, r3, r0 */
/* @0x1a871c movle r0, #0 */
/* @0x1a8720 bx lr */
/* @0x1a8724 eoreq r8, r4, r0, ror #1 */

/* ── FUNC 0x1a8728 · RomDisk::Size(int) · size=40 · insn=10 */
/* @0x1a8728 ldr r3, [pc, #0x1c] */
/* @0x1a872c ldr r3, [pc, r3] */
/* @0x1a8730 ldr r3, [r3] */
/* @0x1a8734 ldr r2, [r3] */
/* @0x1a8738 cmp r2, r0 */
/* @0x1a873c addgt r3, r3, r0, lsl #3 */
/* @0x1a8740 ldrgt r0, [r3, #0x4] */
/* @0x1a8744 movle r0, #0 */
/* @0x1a8748 bx lr */
/* @0x1a874c strhteq r8, [r4], -r4 */
