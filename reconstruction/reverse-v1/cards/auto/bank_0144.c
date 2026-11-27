/* libyoyo.so 覆盖卡组 0144
 * 函数 0x1b4a64..0x1b5f44，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1b4a64 · cARRAY_MEMORY<char const*>::~cARRAY_MEMORY() · size=148 · insn=37 */
/* @0x1b4a64 push {r3, r4, r5, r6, r7, lr} */
/* @0x1b4a68 mov r5, r0 */
/* @0x1b4a6c ldr r6, [r0, #0x4] */
/* @0x1b4a70 cmp r6, #0 */
/* @0x1b4a74 beq 0x1b4ae8 <_ZN13cARRAY_MEMORYIPKcED2Ev+0x84> */
/* @0x1b4a78 ldr r3, [r0] */
/* @0x1b4a7c cmp r3, #0 */
/* @0x1b4a80 ble 0x1b4ac8 <_ZN13cARRAY_MEMORYIPKcED2Ev+0x64> */
/* @0x1b4a84 mov r4, #0 */
/* @0x1b4a88 mov r7, r4 */
/* @0x1b4a8c ldr r0, [r6, r4, lsl #2] */
/* @0x1b4a90 lsl r6, r4, #2 */
/* @0x1b4a94 bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x1b4a98 cmp r0, #0 */
/* @0x1b4a9c beq 0x1b4aac <_ZN13cARRAY_MEMORYIPKcED2Ev+0x48> */
/* @0x1b4aa0 ldr r3, [r5, #0x4] */
/* @0x1b4aa4 ldr r0, [r3, r4, lsl #2] */
/* @0x1b4aa8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b4aac ldr r2, [r5] */
/* @0x1b4ab0 add r4, r4, #1 */
/* @0x1b4ab4 ldr r3, [r5, #0x4] */
/* @0x1b4ab8 cmp r4, r2 */
/* @0x1b4abc str r7, [r3, r6] */
/* @0x1b4ac0 ldr r6, [r5, #0x4] */
/* @0x1b4ac4 blt 0x1b4a8c <_ZN13cARRAY_MEMORYIPKcED2Ev+0x28> */
/* @0x1b4ac8 mov r0, r6 */
/* @0x1b4acc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b4ad0 mov r3, #0 */
/* @0x1b4ad4 str r3, [r5, #0x4] */
/* @0x1b4ad8 mov r3, #0 */
/* @0x1b4adc mov r0, r5 */
/* @0x1b4ae0 str r3, [r5] */
/* @0x1b4ae4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1b4ae8 mov r0, r6 */
/* @0x1b4aec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b4af0 str r6, [r5, #0x4] */
/* @0x1b4af4 b 0x1b4ad8 <_ZN13cARRAY_MEMORYIPKcED2Ev+0x74> */

/* ── FUNC 0x1b4a64 · cARRAY_MEMORY<char const*>::~cARRAY_MEMORY() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1b4af8 · cARRAY_CLASS<CRoom*>::~cARRAY_CLASS() · size=204 · insn=51 */
/* @0x1b4af8 ldr r12, [r0] */
/* @0x1b4afc push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1b4b00 cmp r12, #0 */
/* @0x1b4b04 mov r7, r0 */
/* @0x1b4b08 beq 0x1b4bac <_ZN12cARRAY_CLASSIP5CRoomED2Ev+0xb4> */
/* @0x1b4b0c ldr r5, [r0, #0x4] */
/* @0x1b4b10 cmp r5, #0 */
/* @0x1b4b14 beq 0x1b4bb4 <_ZN12cARRAY_CLASSIP5CRoomED2Ev+0xbc> */
/* @0x1b4b18 cmp r12, #0 */
/* @0x1b4b1c ble 0x1b4b94 <_ZN12cARRAY_CLASSIP5CRoomED2Ev+0x9c> */
/* @0x1b4b20 mov r4, #0 */
/* @0x1b4b24 mov r9, r4 */
/* @0x1b4b28 ldr r1, [r5] */
/* @0x1b4b2c movw r3, #0xfeee */
/* @0x1b4b30 movt r3, #0xfeee */
/* @0x1b4b34 movw r2, #0xfeee */
/* @0x1b4b38 cmp r1, r3 */
/* @0x1b4b3c movt r2, #0xfeee */
/* @0x1b4b40 lsl r8, r4, #2 */
/* @0x1b4b44 beq 0x1b4b88 <_ZN12cARRAY_CLASSIP5CRoomED2Ev+0x90> */
/* @0x1b4b48 ldr r6, [r5, r4, lsl #2] */
/* @0x1b4b4c add r3, r5, r8 */
/* @0x1b4b50 cmp r6, #0 */
/* @0x1b4b54 mov r0, r6 */
/* @0x1b4b58 beq 0x1b4b88 <_ZN12cARRAY_CLASSIP5CRoomED2Ev+0x90> */
/* @0x1b4b5c ldr r1, [r6] */
/* @0x1b4b60 cmp r1, r2 */
/* @0x1b4b64 beq 0x1b4b80 <_ZN12cARRAY_CLASSIP5CRoomED2Ev+0x88> */
/* @0x1b4b68 bl 0x1afa00 <_ZN5CRoomD2Ev> */
/* @0x1b4b6c mov r0, r6 */
/* @0x1b4b70 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b4b74 ldr r3, [r7, #0x4] */
/* @0x1b4b78 ldr r12, [r7] */
/* @0x1b4b7c add r3, r3, r8 */
/* @0x1b4b80 str r9, [r3] */
/* @0x1b4b84 ldr r5, [r7, #0x4] */
/* @0x1b4b88 add r4, r4, #1 */
/* @0x1b4b8c cmp r4, r12 */
/* @0x1b4b90 blt 0x1b4b28 <_ZN12cARRAY_CLASSIP5CRoomED2Ev+0x30> */
/* @0x1b4b94 mov r0, r5 */
/* @0x1b4b98 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b4b9c mov r3, #0 */
/* @0x1b4ba0 str r3, [r7, #0x4] */
/* @0x1b4ba4 mov r3, #0 */
/* @0x1b4ba8 str r3, [r7] */
/* @0x1b4bac mov r0, r7 */
/* @0x1b4bb0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1b4bb4 mov r0, r5 */
/* @0x1b4bb8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b4bbc str r5, [r7, #0x4] */
/* @0x1b4bc0 b 0x1b4ba4 <_ZN12cARRAY_CLASSIP5CRoomED2Ev+0xac> */

/* ── FUNC 0x1b4af8 · cARRAY_CLASS<CRoom*>::~cARRAY_CLASS() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1b4bc4 · Room_Init() · size=268 · insn=67 */
/* @0x1b4bc4 ldr r1, [pc, #0xcc] */
/* @0x1b4bc8 mov r2, #0 */
/* @0x1b4bcc ldr r3, [pc, #0xc8] */
/* @0x1b4bd0 mov r0, #1065353216 */
/* @0x1b4bd4 push {r4, r5, r6, r7, r8, r9, r10} */
/* @0x1b4bd8 add r3, pc, r3 */
/* @0x1b4bdc ldr r8, [pc, #0xbc] */
/* @0x1b4be0 add r1, pc, r1 */
/* @0x1b4be4 ldr r7, [pc, #0xb8] */
/* @0x1b4be8 mvn r12, #0 */
/* @0x1b4bec str r2, [r1] */
/* @0x1b4bf0 mov r4, #1325400064 */
/* @0x1b4bf4 str r2, [r1, #0x4] */
/* @0x1b4bf8 str r2, [r1, #0x8] */
/* @0x1b4bfc str r2, [r1, #0xc] */
/* @0x1b4c00 str r2, [r1, #0x10] */
/* @0x1b4c04 str r2, [r1, #0x14] */
/* @0x1b4c08 ldr r1, [r3, r8] */
/* @0x1b4c0c ldr r5, [pc, #0x94] */
/* @0x1b4c10 ldr r6, [pc, #0x94] */
/* @0x1b4c14 str r0, [r1] */
/* @0x1b4c18 ldr r1, [r3, r7] */
/* @0x1b4c1c ldr r9, [pc, #0x8c] */
/* @0x1b4c20 ldr r8, [pc, #0x8c] */
/* @0x1b4c24 str r0, [r1] */
/* @0x1b4c28 ldr r7, [r3, r5] */
/* @0x1b4c2c ldr r5, [pc, #0x84] */
/* @0x1b4c30 ldr r1, [pc, #0x84] */
/* @0x1b4c34 str r2, [r7] */
/* @0x1b4c38 ldr r6, [r3, r6] */
/* @0x1b4c3c ldr r7, [pc, #0x7c] */
/* @0x1b4c40 str r2, [r6] */
/* @0x1b4c44 ldr r5, [r3, r5] */
/* @0x1b4c48 ldr r6, [pc, #0x74] */
/* @0x1b4c4c str r12, [r5] */
/* @0x1b4c50 ldr r10, [r3, r1] */
/* @0x1b4c54 ldr r5, [pc, #0x6c] */
/* @0x1b4c58 ldr r1, [pc, #0x6c] */
/* @0x1b4c5c str r12, [r10] */
/* @0x1b4c60 ldr r12, [r3, r9] */
/* @0x1b4c64 strb r2, [r12] */
/* @0x1b4c68 ldr r12, [r3, r8] */
/* @0x1b4c6c str r4, [r12] */
/* @0x1b4c70 ldr r12, [r3, r7] */
/* @0x1b4c74 str r4, [r12] */
/* @0x1b4c78 ldr r12, [r3, r6] */
/* @0x1b4c7c str r0, [r12] */
/* @0x1b4c80 ldr r12, [r3, r5] */
/* @0x1b4c84 pop {r4, r5, r6, r7, r8, r9, r10} */
/* @0x1b4c88 str r0, [r12] */
/* @0x1b4c8c ldr r3, [r3, r1] */
/* @0x1b4c90 strb r2, [r3] */
/* @0x1b4c94 bx lr */
/* @0x1b4c98 eorseq sp, r8, r8, ror #19 */
/* @0x1b4c9c eoreq sp, r3, r8, ror r0 */
/* @0x1b4ca0 .word 0xffffe6bc */
/* @0x1b4ca4 .word 0xffffe6c4 */
/* @0x1b4ca8 .word 0xffffe6a8 */
/* @0x1b4cac .word 0xffffe6ac */
/* @0x1b4cb0 .word 0xffffdf14 */
/* @0x1b4cb4 .word 0xffffdf1c */
/* @0x1b4cb8 .word 0xffffdf18 */
/* @0x1b4cbc .word 0xffffdf24 */
/* @0x1b4cc0 .word 0xffffdf20 */
/* @0x1b4cc4 .word 0xffffdf28 */
/* @0x1b4cc8 .word 0xffffdf2c */
/* @0x1b4ccc .word 0xffffdf30 */

/* ── FUNC 0x1b4cd0 · Room_Prepare() · size=8 · insn=2 */
/* @0x1b4cd0 mov r0, #1 */
/* @0x1b4cd4 bx lr */

/* ── FUNC 0x1b4cd8 · Room_Load(unsigned char*, unsigned int, unsigned char*) · size=876 · insn=219 */
/* @0x1b4cd8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b4cdc sub sp, sp, #28 */
/* @0x1b4ce0 ldr r6, [pc, #0x314] */
/* @0x1b4ce4 mov r8, r0 */
/* @0x1b4ce8 ldr r9, [r0] */
/* @0x1b4cec add r6, pc, r6 */
/* @0x1b4cf0 str r2, [sp, #0x10] */
/* @0x1b4cf4 ldr r2, [r6] */
/* @0x1b4cf8 cmp r9, r2 */
/* @0x1b4cfc beq 0x1b4df0 <_Z9Room_LoadPhjS_+0x118> */
/* @0x1b4d00 cmp r9, #0 */
/* @0x1b4d04 ldr r3, [r6, #0x4] */
/* @0x1b4d08 bne 0x1b4dc8 <_Z9Room_LoadPhjS_+0xf0> */
/* @0x1b4d0c cmp r3, #0 */
/* @0x1b4d10 beq 0x1b4dc8 <_Z9Room_LoadPhjS_+0xf0> */
/* @0x1b4d14 cmp r2, #0 */
/* @0x1b4d18 ble 0x1b4dac <_Z9Room_LoadPhjS_+0xd4> */
/* @0x1b4d1c ldr r12, [pc, #0x2dc] */
/* @0x1b4d20 mov r4, r9 */
/* @0x1b4d24 ldr r10, [pc, #0x2d8] */
/* @0x1b4d28 mov r7, r9 */
/* @0x1b4d2c add r12, pc, r12 */
/* @0x1b4d30 str r0, [sp, #0xc] */
/* @0x1b4d34 add r10, pc, r10 */
/* @0x1b4d38 mov r8, r12 */
/* @0x1b4d3c ldr r0, [r3] */
/* @0x1b4d40 movw r2, #0xfeee */
/* @0x1b4d44 movt r2, #0xfeee */
/* @0x1b4d48 movw r1, #0xfeee */
/* @0x1b4d4c cmp r0, r2 */
/* @0x1b4d50 movt r1, #0xfeee */
/* @0x1b4d54 lsl r11, r4, #2 */
/* @0x1b4d58 beq 0x1b4d98 <_Z9Room_LoadPhjS_+0xc0> */
/* @0x1b4d5c ldr r5, [r3, r4, lsl #2] */
/* @0x1b4d60 add r2, r3, r11 */
/* @0x1b4d64 cmp r5, #0 */
/* @0x1b4d68 mov r0, r5 */
/* @0x1b4d6c beq 0x1b4d98 <_Z9Room_LoadPhjS_+0xc0> */
/* @0x1b4d70 ldr r3, [r5] */
/* @0x1b4d74 cmp r3, r1 */
/* @0x1b4d78 beq 0x1b4d90 <_Z9Room_LoadPhjS_+0xb8> */
/* @0x1b4d7c bl 0x1afa00 <_ZN5CRoomD2Ev> */
/* @0x1b4d80 mov r0, r5 */
/* @0x1b4d84 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b4d88 ldr r2, [r8, #0x4] */
/* @0x1b4d8c add r2, r2, r11 */
/* @0x1b4d90 str r7, [r2] */
/* @0x1b4d94 ldr r3, [r10, #0x4] */
/* @0x1b4d98 ldr r2, [r6] */
/* @0x1b4d9c add r4, r4, #1 */
/* @0x1b4da0 cmp r4, r2 */
/* @0x1b4da4 blt 0x1b4d3c <_Z9Room_LoadPhjS_+0x64> */
/* @0x1b4da8 ldr r8, [sp, #0xc] */
/* @0x1b4dac mov r0, r3 */
/* @0x1b4db0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b4db4 ldr r3, [pc, #0x24c] */
/* @0x1b4db8 mov r2, #0 */
/* @0x1b4dbc add r3, pc, r3 */
/* @0x1b4dc0 str r2, [r3, #0x4] */
/* @0x1b4dc4 b 0x1b4de4 <_Z9Room_LoadPhjS_+0x10c> */
/* @0x1b4dc8 lsls r4, r9, #2 */
/* @0x1b4dcc mov r0, r3 */
/* @0x1b4dd0 bne 0x1b4fc8 <_Z9Room_LoadPhjS_+0x2f0> */
/* @0x1b4dd4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b4dd8 ldr r3, [pc, #0x22c] */
/* @0x1b4ddc add r3, pc, r3 */
/* @0x1b4de0 str r4, [r3, #0x4] */
/* @0x1b4de4 ldr r3, [pc, #0x224] */
/* @0x1b4de8 add r3, pc, r3 */
/* @0x1b4dec str r9, [r3] */
/* @0x1b4df0 cmp r9, #0 */
/* @0x1b4df4 bne 0x1b4f68 <_Z9Room_LoadPhjS_+0x290> */
/* @0x1b4df8 ldr r5, [pc, #0x214] */
/* @0x1b4dfc add r5, pc, r5 */
/* @0x1b4e00 ldr r0, [r5, #0xc] */
/* @0x1b4e04 cmp r0, #0 */
/* @0x1b4e08 beq 0x1b4f74 <_Z9Room_LoadPhjS_+0x29c> */
/* @0x1b4e0c ldr r3, [r5, #0x8] */
/* @0x1b4e10 cmp r3, #0 */
/* @0x1b4e14 ble 0x1b4e64 <_Z9Room_LoadPhjS_+0x18c> */
/* @0x1b4e18 ldr r7, [pc, #0x1f8] */
/* @0x1b4e1c mov r4, r9 */
/* @0x1b4e20 mov r6, r9 */
/* @0x1b4e24 add r7, pc, r7 */
/* @0x1b4e28 ldr r0, [r0, r4, lsl #2] */
/* @0x1b4e2c lsl r10, r4, #2 */
/* @0x1b4e30 bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x1b4e34 cmp r0, #0 */
/* @0x1b4e38 beq 0x1b4e48 <_Z9Room_LoadPhjS_+0x170> */
/* @0x1b4e3c ldr r3, [r7, #0xc] */
/* @0x1b4e40 ldr r0, [r3, r4, lsl #2] */
/* @0x1b4e44 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b4e48 ldr r2, [r5, #0x8] */
/* @0x1b4e4c add r4, r4, #1 */
/* @0x1b4e50 ldr r3, [r5, #0xc] */
/* @0x1b4e54 cmp r4, r2 */
/* @0x1b4e58 str r6, [r3, r10] */
/* @0x1b4e5c ldr r0, [r5, #0xc] */
/* @0x1b4e60 blt 0x1b4e28 <_Z9Room_LoadPhjS_+0x150> */
/* @0x1b4e64 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b4e68 ldr r3, [pc, #0x1ac] */
/* @0x1b4e6c mov r2, #0 */
/* @0x1b4e70 add r3, pc, r3 */
/* @0x1b4e74 str r2, [r3, #0xc] */
/* @0x1b4e78 ldr r10, [pc, #0x1a0] */
/* @0x1b4e7c cmp r9, #0 */
/* @0x1b4e80 add r10, pc, r10 */
/* @0x1b4e84 str r9, [r10, #0x8] */
/* @0x1b4e88 beq 0x1b4fbc <_Z9Room_LoadPhjS_+0x2e4> */
/* @0x1b4e8c ldr r3, [pc, #0x190] */
/* @0x1b4e90 mov r7, r10 */
/* @0x1b4e94 mov r4, #0 */
/* @0x1b4e98 str r9, [sp, #0xc] */
/* @0x1b4e9c add r3, pc, r3 */
/* @0x1b4ea0 str r3, [sp, #0x14] */
/* @0x1b4ea4 b 0x1b4f54 <_Z9Room_LoadPhjS_+0x27c> */
/* @0x1b4ea8 ldr r9, [pc, #0x178] */
/* @0x1b4eac ldr r9, [pc, r9] */
/* @0x1b4eb0 ldr r11, [r9] */
/* @0x1b4eb4 adds r1, r11, r5 */
/* @0x1b4eb8 beq 0x1b4ff4 <_Z9Room_LoadPhjS_+0x31c> */
/* @0x1b4ebc mov r0, #292 */
/* @0x1b4ec0 str r1, [sp, #0x8] */
/* @0x1b4ec4 bl 0x27c524 <_Znwj> */
/* @0x1b4ec8 mov r6, r0 */
/* @0x1b4ecc bl 0x1ad2cc <_ZN5CRoomC2Ev> */
/* @0x1b4ed0 ldr r1, [sp, #0x8] */
/* @0x1b4ed4 mov r0, r6 */
/* @0x1b4ed8 ldr r2, [sp, #0x10] */
/* @0x1b4edc bl 0x1aea3c <_ZN5CRoom13LoadFromChunkEP6YYRoomPh> */
/* @0x1b4ee0 ldr r12, [r11, r5] */
/* @0x1b4ee4 cmp r12, #0 */
/* @0x1b4ee8 ldrne r3, [r9] */
/* @0x1b4eec moveq r11, r12 */
/* @0x1b4ef0 addne r11, r3, r12 */
/* @0x1b4ef4 mov r0, r11 */
/* @0x1b4ef8 bl 0xb6538 <strlen@plt> */
/* @0x1b4efc ldr r1, [sp, #0x14] */
/* @0x1b4f00 mov r3, #1 */
/* @0x1b4f04 mov r2, #170 */
/* @0x1b4f08 add r0, r0, r3 */
/* @0x1b4f0c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1b4f10 mov r1, r11 */
/* @0x1b4f14 mov r5, r0 */
/* @0x1b4f18 bl 0xb65a4 <strcpy@plt> */
/* @0x1b4f1c ldr r2, [r10, #0xc] */
/* @0x1b4f20 lsl r11, r4, #2 */
/* @0x1b4f24 ldr r0, [r2, r4, lsl #2] */
/* @0x1b4f28 cmp r0, #0 */
/* @0x1b4f2c beq 0x1b4f34 <_Z9Room_LoadPhjS_+0x25c> */
/* @0x1b4f30 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b4f34 ldr r2, [r7, #0x4] */
/* @0x1b4f38 add r4, r4, #1 */
/* @0x1b4f3c ldr r3, [sp, #0xc] */
/* @0x1b4f40 str r6, [r2, r11] */
/* @0x1b4f44 cmp r4, r3 */
/* @0x1b4f48 ldr r2, [r7, #0xc] */
/* @0x1b4f4c str r5, [r2, r11] */
/* @0x1b4f50 beq 0x1b4fbc <_Z9Room_LoadPhjS_+0x2e4> */
/* @0x1b4f54 ldr r5, [r8, #0x4]! */
/* @0x1b4f58 cmp r5, #0 */
/* @0x1b4f5c bne 0x1b4ea8 <_Z9Room_LoadPhjS_+0x1d0> */
/* @0x1b4f60 mov r6, r5 */
/* @0x1b4f64 b 0x1b4f1c <_Z9Room_LoadPhjS_+0x244> */
/* @0x1b4f68 ldr r3, [pc, #0xbc] */
/* @0x1b4f6c add r3, pc, r3 */
/* @0x1b4f70 ldr r0, [r3, #0xc] */
/* @0x1b4f74 lsls r4, r9, #2 */
/* @0x1b4f78 beq 0x1b4fa8 <_Z9Room_LoadPhjS_+0x2d0> */
/* @0x1b4f7c ldr r2, [pc, #0xac] */
/* @0x1b4f80 mov r3, #0 */
/* @0x1b4f84 mov r1, r4 */
/* @0x1b4f88 str r3, [sp] */
/* @0x1b4f8c add r2, pc, r2 */
/* @0x1b4f90 mov r3, #92 */
/* @0x1b4f94 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1b4f98 ldr r3, [pc, #0x94] */
/* @0x1b4f9c add r3, pc, r3 */
/* @0x1b4fa0 str r0, [r3, #0xc] */
/* @0x1b4fa4 b 0x1b4e78 <_Z9Room_LoadPhjS_+0x1a0> */
/* @0x1b4fa8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b4fac ldr r3, [pc, #0x84] */
/* @0x1b4fb0 add r3, pc, r3 */
/* @0x1b4fb4 str r4, [r3, #0xc] */
/* @0x1b4fb8 b 0x1b4e78 <_Z9Room_LoadPhjS_+0x1a0> */
/* @0x1b4fbc mov r0, #1 */
/* @0x1b4fc0 add sp, sp, #28 */
/* @0x1b4fc4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b4fc8 ldr r2, [pc, #0x6c] */
/* @0x1b4fcc mov r3, #0 */
/* @0x1b4fd0 mov r1, r4 */
/* @0x1b4fd4 str r3, [sp] */
/* @0x1b4fd8 add r2, pc, r2 */
/* @0x1b4fdc mov r3, #135 */
/* @0x1b4fe0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1b4fe4 ldr r3, [pc, #0x54] */
/* @0x1b4fe8 add r3, pc, r3 */
/* @0x1b4fec str r0, [r3, #0x4] */
/* @0x1b4ff0 b 0x1b4de4 <_Z9Room_LoadPhjS_+0x10c> */
/* @0x1b4ff4 mov r5, r1 */
/* @0x1b4ff8 b 0x1b4f60 <_Z9Room_LoadPhjS_+0x288> */
/* @0x1b4ffc ldrsbteq sp, [r8], -r12 */
/* @0x1b5000 mlaseq r8, r12, r8, sp */
/* @0x1b5004 mlaseq r8, r4, r8, sp */
/* @0x1b5008 eorseq sp, r8, r12, lsl #16 */
/* @0x1b500c eorseq sp, r8, r12, ror #15 */
/* @0x1b5010 eorseq sp, r8, r0, ror #15 */
/* @0x1b5014 eorseq sp, r8, r12, asr #15 */
/* @0x1b5018 eorseq sp, r8, r4, lsr #15 */
/* @0x1b501c eorseq sp, r8, r8, asr r7 */
/* @0x1b5020 eorseq sp, r8, r8, asr #14 */
/* @0x1b5024 andseq r8, r9, r4, asr #9 */
/* @0x1b5028 mlaeq r3, r8, r10, r8 */
/* @0x1b502c eorseq sp, r8, r12, asr r6 */
/* @0x1b5030 mulseq r9, r12, r3 */
/* @0x1b5034 eorseq sp, r8, r12, lsr #12 */
/* @0x1b5038 eorseq sp, r8, r8, lsl r6 */
/* @0x1b503c andseq r8, r9, r8, lsl r3 */
/* @0x1b5040 eorseq sp, r8, r0, ror #11 */

/* ── FUNC 0x1b5044 · Room_Free() · size=504 · insn=126 */
/* @0x1b5044 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b5048 mov r4, #0 */
/* @0x1b504c ldr r8, [pc, #0x1bc] */
/* @0x1b5050 ldr r3, [pc, #0x1bc] */
/* @0x1b5054 add r8, pc, r8 */
/* @0x1b5058 ldr r3, [pc, r3] */
/* @0x1b505c ldr r2, [r8] */
/* @0x1b5060 str r4, [r3] */
/* @0x1b5064 cmp r2, r4 */
/* @0x1b5068 beq 0x1b5128 <_Z9Room_Freev+0xe4> */
/* @0x1b506c ldr r5, [r8, #0x4] */
/* @0x1b5070 cmp r5, r4 */
/* @0x1b5074 beq 0x1b5200 <_Z9Room_Freev+0x1bc> */
/* @0x1b5078 cmp r2, r4 */
/* @0x1b507c ble 0x1b5100 <_Z9Room_Freev+0xbc> */
/* @0x1b5080 ldr r10, [pc, #0x190] */
/* @0x1b5084 mov r9, r4 */
/* @0x1b5088 ldr r11, [pc, #0x18c] */
/* @0x1b508c add r10, pc, r10 */
/* @0x1b5090 add r11, pc, r11 */
/* @0x1b5094 ldr r1, [r5] */
/* @0x1b5098 movw r3, #0xfeee */
/* @0x1b509c movt r3, #0xfeee */
/* @0x1b50a0 movw r2, #0xfeee */
/* @0x1b50a4 cmp r1, r3 */
/* @0x1b50a8 movt r2, #0xfeee */
/* @0x1b50ac lsl r7, r4, #2 */
/* @0x1b50b0 beq 0x1b50f0 <_Z9Room_Freev+0xac> */
/* @0x1b50b4 ldr r6, [r5, r4, lsl #2] */
/* @0x1b50b8 add r3, r5, r7 */
/* @0x1b50bc cmp r6, #0 */
/* @0x1b50c0 mov r0, r6 */
/* @0x1b50c4 beq 0x1b50f0 <_Z9Room_Freev+0xac> */
/* @0x1b50c8 ldr r1, [r6] */
/* @0x1b50cc cmp r1, r2 */
/* @0x1b50d0 beq 0x1b50e8 <_Z9Room_Freev+0xa4> */
/* @0x1b50d4 bl 0x1afa00 <_ZN5CRoomD2Ev> */
/* @0x1b50d8 mov r0, r6 */
/* @0x1b50dc bl 0x27d1d0 <_ZdlPv> */
/* @0x1b50e0 ldr r3, [r11, #0x4] */
/* @0x1b50e4 add r3, r3, r7 */
/* @0x1b50e8 str r9, [r3] */
/* @0x1b50ec ldr r5, [r10, #0x4] */
/* @0x1b50f0 ldr r3, [r8] */
/* @0x1b50f4 add r4, r4, #1 */
/* @0x1b50f8 cmp r4, r3 */
/* @0x1b50fc blt 0x1b5094 <_Z9Room_Freev+0x50> */
/* @0x1b5100 mov r0, r5 */
/* @0x1b5104 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5108 ldr r3, [pc, #0x110] */
/* @0x1b510c mov r2, #0 */
/* @0x1b5110 add r3, pc, r3 */
/* @0x1b5114 str r2, [r3, #0x4] */
/* @0x1b5118 ldr r3, [pc, #0x104] */
/* @0x1b511c mov r2, #0 */
/* @0x1b5120 add r3, pc, r3 */
/* @0x1b5124 str r2, [r3] */
/* @0x1b5128 ldr r5, [pc, #0xf8] */
/* @0x1b512c add r5, pc, r5 */
/* @0x1b5130 ldr r4, [r5, #0x14] */
/* @0x1b5134 subs r0, r4, #0 */
/* @0x1b5138 beq 0x1b51e4 <_Z9Room_Freev+0x1a0> */
/* @0x1b513c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5140 mov r3, #0 */
/* @0x1b5144 str r3, [r5, #0x14] */
/* @0x1b5148 ldr r5, [pc, #0xdc] */
/* @0x1b514c mov r4, #0 */
/* @0x1b5150 add r5, pc, r5 */
/* @0x1b5154 ldr r6, [r5, #0xc] */
/* @0x1b5158 str r4, [r5, #0x10] */
/* @0x1b515c cmp r6, r4 */
/* @0x1b5160 beq 0x1b51f0 <_Z9Room_Freev+0x1ac> */
/* @0x1b5164 ldr r3, [r5, #0x8] */
/* @0x1b5168 cmp r3, r4 */
/* @0x1b516c ble 0x1b51b8 <_Z9Room_Freev+0x174> */
/* @0x1b5170 ldr r8, [pc, #0xb8] */
/* @0x1b5174 mov r7, r4 */
/* @0x1b5178 add r8, pc, r8 */
/* @0x1b517c ldr r0, [r6, r4, lsl #2] */
/* @0x1b5180 lsl r6, r4, #2 */
/* @0x1b5184 bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x1b5188 cmp r0, #0 */
/* @0x1b518c beq 0x1b519c <_Z9Room_Freev+0x158> */
/* @0x1b5190 ldr r3, [r8, #0xc] */
/* @0x1b5194 ldr r0, [r3, r4, lsl #2] */
/* @0x1b5198 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b519c ldr r2, [r5, #0x8] */
/* @0x1b51a0 add r4, r4, #1 */
/* @0x1b51a4 ldr r3, [r5, #0xc] */
/* @0x1b51a8 cmp r4, r2 */
/* @0x1b51ac str r7, [r3, r6] */
/* @0x1b51b0 ldr r6, [r5, #0xc] */
/* @0x1b51b4 blt 0x1b517c <_Z9Room_Freev+0x138> */
/* @0x1b51b8 mov r0, r6 */
/* @0x1b51bc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b51c0 ldr r3, [pc, #0x6c] */
/* @0x1b51c4 mov r2, #0 */
/* @0x1b51c8 add r3, pc, r3 */
/* @0x1b51cc str r2, [r3, #0xc] */
/* @0x1b51d0 ldr r3, [pc, #0x60] */
/* @0x1b51d4 mov r2, #0 */
/* @0x1b51d8 add r3, pc, r3 */
/* @0x1b51dc str r2, [r3, #0x8] */
/* @0x1b51e0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b51e4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b51e8 str r4, [r5, #0x14] */
/* @0x1b51ec b 0x1b5148 <_Z9Room_Freev+0x104> */
/* @0x1b51f0 mov r0, r6 */
/* @0x1b51f4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b51f8 str r6, [r5, #0xc] */
/* @0x1b51fc b 0x1b51d0 <_Z9Room_Freev+0x18c> */
/* @0x1b5200 mov r0, r5 */
/* @0x1b5204 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5208 str r5, [r8, #0x4] */
/* @0x1b520c b 0x1b5118 <_Z9Room_Freev+0xd4> */
/* @0x1b5210 eorseq sp, r8, r4, ror r5 */
/* @0x1b5214 .word 0x002388d0 */
/* @0x1b5218 eorseq sp, r8, r12, lsr r5 */
/* @0x1b521c eorseq sp, r8, r8, lsr r5 */
/* @0x1b5220 ldrhteq sp, [r8], -r8 */
/* @0x1b5224 eorseq sp, r8, r8, lsr #9 */
/* @0x1b5228 mlaseq r8, r12, r4, sp */
/* @0x1b522c eorseq sp, r8, r8, ror r4 */
/* @0x1b5230 eorseq sp, r8, r0, asr r4 */
/* @0x1b5234 eorseq sp, r8, r0, lsl #8 */
/* @0x1b5238 ldrshteq sp, [r8], -r0 */

/* ── FUNC 0x1b523c · Room_Number() · size=16 · insn=4 */
/* @0x1b523c ldr r3, [pc, #0x4] */
/* @0x1b5240 ldr r0, [pc, r3] */
/* @0x1b5244 bx lr */
/* @0x1b5248 eorseq sp, r8, r8, lsl #7 */

/* ── FUNC 0x1b524c · Room_Find(char const*) · size=120 · insn=30 */
/* @0x1b524c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1b5250 mov r8, r0 */
/* @0x1b5254 ldr r3, [pc, #0x64] */
/* @0x1b5258 add r3, pc, r3 */
/* @0x1b525c ldr r6, [r3] */
/* @0x1b5260 cmp r6, #0 */
/* @0x1b5264 ble 0x1b52b0 <_Z9Room_FindPKc+0x64> */
/* @0x1b5268 ldr r9, [r3, #0x4] */
/* @0x1b526c mov r4, #0 */
/* @0x1b5270 ldr r7, [r3, #0xc] */
/* @0x1b5274 mov r5, r4 */
/* @0x1b5278 ldr r3, [r9, r4] */
/* @0x1b527c mov r1, r8 */
/* @0x1b5280 cmp r3, #0 */
/* @0x1b5284 beq 0x1b52a0 <_Z9Room_FindPKc+0x54> */
/* @0x1b5288 ldr r0, [r7, r4] */
/* @0x1b528c cmp r0, #0 */
/* @0x1b5290 beq 0x1b52a0 <_Z9Room_FindPKc+0x54> */
/* @0x1b5294 bl 0xb6574 <strcmp@plt> */
/* @0x1b5298 cmp r0, #0 */
/* @0x1b529c beq 0x1b52b8 <_Z9Room_FindPKc+0x6c> */
/* @0x1b52a0 add r5, r5, #1 */
/* @0x1b52a4 add r4, r4, #4 */
/* @0x1b52a8 cmp r5, r6 */
/* @0x1b52ac bne 0x1b5278 <_Z9Room_FindPKc+0x2c> */
/* @0x1b52b0 mvn r0, #0 */
/* @0x1b52b4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1b52b8 mov r0, r5 */
/* @0x1b52bc pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1b52c0 eorseq sp, r8, r0, ror r3 */

/* ── FUNC 0x1b52c4 · Room_Data(int) · size=52 · insn=13 */
/* @0x1b52c4 cmp r0, #0 */
/* @0x1b52c8 blt 0x1b52e0 <_Z9Room_Datai+0x1c> */
/* @0x1b52cc ldr r3, [pc, #0x20] */
/* @0x1b52d0 add r3, pc, r3 */
/* @0x1b52d4 ldr r2, [r3] */
/* @0x1b52d8 cmp r0, r2 */
/* @0x1b52dc blt 0x1b52e8 <_Z9Room_Datai+0x24> */
/* @0x1b52e0 mov r0, #0 */
/* @0x1b52e4 bx lr */
/* @0x1b52e8 ldr r3, [r3, #0x4] */
/* @0x1b52ec ldr r0, [r3, r0, lsl #2] */
/* @0x1b52f0 bx lr */
/* @0x1b52f4 ldrshteq sp, [r8], -r8 */

/* ── FUNC 0x1b52f8 · Room_Exists(int) · size=20 · insn=5 */
/* @0x1b52f8 push {r3, lr} */
/* @0x1b52fc bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x1b5300 adds r0, r0, #0 */
/* @0x1b5304 movne r0, #1 */
/* @0x1b5308 pop {r3, pc} */

/* ── FUNC 0x1b530c · Room_Name(int) · size=60 · insn=15 */
/* @0x1b530c push {r4, lr} */
/* @0x1b5310 mov r4, r0 */
/* @0x1b5314 bl 0x1b52f8 <_Z11Room_Existsi> */
/* @0x1b5318 cmp r0, #0 */
/* @0x1b531c beq 0x1b5334 <_Z9Room_Namei+0x28> */
/* @0x1b5320 ldr r3, [pc, #0x18] */
/* @0x1b5324 add r3, pc, r3 */
/* @0x1b5328 ldr r3, [r3, #0xc] */
/* @0x1b532c ldr r0, [r3, r4, lsl #2] */
/* @0x1b5330 pop {r4, pc} */
/* @0x1b5334 ldr r0, [pc, #0x8] */
/* @0x1b5338 add r0, pc, r0 */
/* @0x1b533c pop {r4, pc} */
/* @0x1b5340 eorseq sp, r8, r4, lsr #5 */
/* @0x1b5344 andseq r11, r7, r8, lsl #15 */

/* ── FUNC 0x1b5348 · Room_Add() · size=920 · insn=230 */
/* @0x1b5348 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b534c sub sp, sp, #164 */
/* @0x1b5350 ldr r6, [pc, #0x33c] */
/* @0x1b5354 add r4, sp, #28 */
/* @0x1b5358 ldr r8, [pc, #0x338] */
/* @0x1b535c mov r1, #128 */
/* @0x1b5360 add r6, pc, r6 */
/* @0x1b5364 ldr r2, [pc, #0x330] */
/* @0x1b5368 ldr r8, [pc, r8] */
/* @0x1b536c mov r0, r4 */
/* @0x1b5370 ldr r5, [r6, #0x8] */
/* @0x1b5374 add r2, pc, r2 */
/* @0x1b5378 ldr r12, [r8] */
/* @0x1b537c mov r3, r5 */
/* @0x1b5380 str r12, [sp, #0x9c] */
/* @0x1b5384 bl 0xb65c8 <snprintf@plt> */
/* @0x1b5388 mov r0, r4 */
/* @0x1b538c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1b5390 ldr r4, [r6, #0x8] */
/* @0x1b5394 adds r1, r4, #1 */
/* @0x1b5398 str r1, [sp, #0xc] */
/* @0x1b539c str r0, [sp, #0x10] */
/* @0x1b53a0 bne 0x1b55f8 <_Z8Room_Addv+0x2b0> */
/* @0x1b53a4 ldr r0, [r6, #0xc] */
/* @0x1b53a8 cmp r0, #0 */
/* @0x1b53ac beq 0x1b562c <_Z8Room_Addv+0x2e4> */
/* @0x1b53b0 cmp r4, #0 */
/* @0x1b53b4 ble 0x1b5408 <_Z8Room_Addv+0xc0> */
/* @0x1b53b8 ldr r11, [pc, #0x2e0] */
/* @0x1b53bc mov r9, r6 */
/* @0x1b53c0 mov r10, r1 */
/* @0x1b53c4 mov r7, r1 */
/* @0x1b53c8 add r11, pc, r11 */
/* @0x1b53cc ldr r0, [r0, r10, lsl #2] */
/* @0x1b53d0 lsl r6, r10, #2 */
/* @0x1b53d4 bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x1b53d8 cmp r0, #0 */
/* @0x1b53dc beq 0x1b53ec <_Z8Room_Addv+0xa4> */
/* @0x1b53e0 ldr r3, [r11, #0xc] */
/* @0x1b53e4 ldr r0, [r3, r10, lsl #2] */
/* @0x1b53e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b53ec ldr r2, [r9, #0x8] */
/* @0x1b53f0 add r10, r10, #1 */
/* @0x1b53f4 ldr r3, [r9, #0xc] */
/* @0x1b53f8 cmp r10, r2 */
/* @0x1b53fc str r7, [r3, r6] */
/* @0x1b5400 ldr r0, [r9, #0xc] */
/* @0x1b5404 blt 0x1b53cc <_Z8Room_Addv+0x84> */
/* @0x1b5408 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b540c ldr r1, [pc, #0x290] */
/* @0x1b5410 mov r3, #0 */
/* @0x1b5414 add r1, pc, r1 */
/* @0x1b5418 mov r2, r3 */
/* @0x1b541c str r3, [r1, #0xc] */
/* @0x1b5420 ldr r3, [pc, #0x280] */
/* @0x1b5424 cmp r5, r4 */
/* @0x1b5428 ldr r1, [sp, #0xc] */
/* @0x1b542c add r3, pc, r3 */
/* @0x1b5430 str r1, [r3, #0x8] */
/* @0x1b5434 bge 0x1b5474 <_Z8Room_Addv+0x12c> */
/* @0x1b5438 ldr r0, [pc, #0x26c] */
/* @0x1b543c lsl r3, r4, #2 */
/* @0x1b5440 add r0, pc, r0 */
/* @0x1b5444 b 0x1b544c <_Z8Room_Addv+0x104> */
/* @0x1b5448 ldr r2, [r0, #0xc] */
/* @0x1b544c add r1, r2, r3 */
/* @0x1b5450 sub r4, r4, #1 */
/* @0x1b5454 cmp r4, r5 */
/* @0x1b5458 ldr r1, [r1, #-0x4] */
/* @0x1b545c str r1, [r2, r3] */
/* @0x1b5460 sub r3, r3, #4 */
/* @0x1b5464 bne 0x1b5448 <_Z8Room_Addv+0x100> */
/* @0x1b5468 ldr r3, [pc, #0x240] */
/* @0x1b546c add r3, pc, r3 */
/* @0x1b5470 ldr r2, [r3, #0xc] */
/* @0x1b5474 ldr r3, [sp, #0x10] */
/* @0x1b5478 mov r0, #292 */
/* @0x1b547c ldr r6, [pc, #0x230] */
/* @0x1b5480 str r3, [r2, r5, lsl #2] */
/* @0x1b5484 add r6, pc, r6 */
/* @0x1b5488 bl 0x27c524 <_Znwj> */
/* @0x1b548c mov r10, r0 */
/* @0x1b5490 bl 0x1ad2cc <_ZN5CRoomC2Ev> */
/* @0x1b5494 mov r0, r10 */
/* @0x1b5498 bl 0x1a92c0 <_ZN5CRoom16CreateWADStorageEv> */
/* @0x1b549c ldr r4, [r6] */
/* @0x1b54a0 ldr r0, [r6, #0x4] */
/* @0x1b54a4 adds r9, r4, #1 */
/* @0x1b54a8 bne 0x1b5648 <_Z8Room_Addv+0x300> */
/* @0x1b54ac cmp r0, #0 */
/* @0x1b54b0 beq 0x1b5674 <_Z8Room_Addv+0x32c> */
/* @0x1b54b4 cmp r4, #0 */
/* @0x1b54b8 ble 0x1b5570 <_Z8Room_Addv+0x228> */
/* @0x1b54bc ldr r1, [pc, #0x1f4] */
/* @0x1b54c0 mov r2, r6 */
/* @0x1b54c4 ldr r12, [pc, #0x1f0] */
/* @0x1b54c8 mov r6, r9 */
/* @0x1b54cc add r1, pc, r1 */
/* @0x1b54d0 str r5, [sp, #0xc] */
/* @0x1b54d4 add r12, pc, r12 */
/* @0x1b54d8 str r4, [sp, #0x10] */
/* @0x1b54dc mov r3, r0 */
/* @0x1b54e0 mov r4, r1 */
/* @0x1b54e4 mov r5, r12 */
/* @0x1b54e8 mov r11, r2 */
/* @0x1b54ec str r8, [sp, #0x14] */
/* @0x1b54f0 ldr r2, [r3] */
/* @0x1b54f4 movw r0, #0xfeee */
/* @0x1b54f8 movt r0, #0xfeee */
/* @0x1b54fc cmp r2, r0 */
/* @0x1b5500 beq 0x1b5550 <_Z8Room_Addv+0x208> */
/* @0x1b5504 ldr r7, [r3, r6, lsl #2] */
/* @0x1b5508 lsl r8, r6, #2 */
/* @0x1b550c add r0, r3, r8 */
/* @0x1b5510 cmp r7, #0 */
/* @0x1b5514 beq 0x1b5550 <_Z8Room_Addv+0x208> */
/* @0x1b5518 ldr lr, [r7] */
/* @0x1b551c movw r3, #0xfeee */
/* @0x1b5520 movt r3, #0xfeee */
/* @0x1b5524 cmp lr, r3 */
/* @0x1b5528 beq 0x1b5544 <_Z8Room_Addv+0x1fc> */
/* @0x1b552c mov r0, r7 */
/* @0x1b5530 bl 0x1afa00 <_ZN5CRoomD2Ev> */
/* @0x1b5534 mov r0, r7 */
/* @0x1b5538 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b553c ldr r0, [r5, #0x4] */
/* @0x1b5540 add r0, r0, r8 */
/* @0x1b5544 mov r1, #0 */
/* @0x1b5548 str r1, [r0] */
/* @0x1b554c ldr r3, [r4, #0x4] */
/* @0x1b5550 ldr r2, [r11] */
/* @0x1b5554 add r6, r6, #1 */
/* @0x1b5558 cmp r6, r2 */
/* @0x1b555c blt 0x1b54f0 <_Z8Room_Addv+0x1a8> */
/* @0x1b5560 ldr r5, [sp, #0xc] */
/* @0x1b5564 mov r0, r3 */
/* @0x1b5568 ldr r4, [sp, #0x10] */
/* @0x1b556c ldr r8, [sp, #0x14] */
/* @0x1b5570 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5574 ldr r2, [pc, #0x144] */
/* @0x1b5578 mov r3, #0 */
/* @0x1b557c add r2, pc, r2 */
/* @0x1b5580 mov r1, r3 */
/* @0x1b5584 str r3, [r2, #0x4] */
/* @0x1b5588 ldr r3, [pc, #0x134] */
/* @0x1b558c cmp r5, r4 */
/* @0x1b5590 add r3, pc, r3 */
/* @0x1b5594 str r9, [r3] */
/* @0x1b5598 bge 0x1b55d8 <_Z8Room_Addv+0x290> */
/* @0x1b559c ldr r0, [pc, #0x124] */
/* @0x1b55a0 lsl r3, r4, #2 */
/* @0x1b55a4 add r0, pc, r0 */
/* @0x1b55a8 b 0x1b55b0 <_Z8Room_Addv+0x268> */
/* @0x1b55ac ldr r1, [r0, #0x4] */
/* @0x1b55b0 add r2, r1, r3 */
/* @0x1b55b4 sub r4, r4, #1 */
/* @0x1b55b8 cmp r4, r5 */
/* @0x1b55bc ldr r2, [r2, #-0x4] */
/* @0x1b55c0 str r2, [r1, r3] */
/* @0x1b55c4 sub r3, r3, #4 */
/* @0x1b55c8 bne 0x1b55ac <_Z8Room_Addv+0x264> */
/* @0x1b55cc ldr r3, [pc, #0xf8] */
/* @0x1b55d0 add r3, pc, r3 */
/* @0x1b55d4 ldr r1, [r3, #0x4] */
/* @0x1b55d8 ldr r2, [sp, #0x9c] */
/* @0x1b55dc mov r0, r5 */
/* @0x1b55e0 str r10, [r1, r5, lsl #2] */
/* @0x1b55e4 ldr r3, [r8] */
/* @0x1b55e8 cmp r2, r3 */
/* @0x1b55ec bne 0x1b5690 <_Z8Room_Addv+0x348> */
/* @0x1b55f0 add sp, sp, #164 */
/* @0x1b55f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b55f8 ldr r3, [sp, #0xc] */
/* @0x1b55fc ldr r0, [r6, #0xc] */
/* @0x1b5600 lsls r1, r3, #2 */
/* @0x1b5604 beq 0x1b562c <_Z8Room_Addv+0x2e4> */
/* @0x1b5608 ldr r2, [pc, #0xc0] */
/* @0x1b560c mov r3, #0 */
/* @0x1b5610 str r3, [sp] */
/* @0x1b5614 mov r3, #92 */
/* @0x1b5618 add r2, pc, r2 */
/* @0x1b561c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1b5620 mov r2, r0 */
/* @0x1b5624 str r0, [r6, #0xc] */
/* @0x1b5628 b 0x1b5420 <_Z8Room_Addv+0xd8> */
/* @0x1b562c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5630 ldr r1, [pc, #0x9c] */
/* @0x1b5634 mov r3, #0 */
/* @0x1b5638 add r1, pc, r1 */
/* @0x1b563c mov r2, r3 */
/* @0x1b5640 str r3, [r1, #0xc] */
/* @0x1b5644 b 0x1b5420 <_Z8Room_Addv+0xd8> */
/* @0x1b5648 lsls r1, r9, #2 */
/* @0x1b564c beq 0x1b5674 <_Z8Room_Addv+0x32c> */
/* @0x1b5650 ldr r2, [pc, #0x80] */
/* @0x1b5654 mov r3, #0 */
/* @0x1b5658 str r3, [sp] */
/* @0x1b565c mov r3, #135 */
/* @0x1b5660 add r2, pc, r2 */
/* @0x1b5664 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1b5668 mov r1, r0 */
/* @0x1b566c str r0, [r6, #0x4] */
/* @0x1b5670 b 0x1b5588 <_Z8Room_Addv+0x240> */
/* @0x1b5674 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5678 ldr r2, [pc, #0x5c] */
/* @0x1b567c mov r3, #0 */
/* @0x1b5680 add r2, pc, r2 */
/* @0x1b5684 mov r1, r3 */
/* @0x1b5688 str r3, [r2, #0x4] */
/* @0x1b568c b 0x1b5588 <_Z8Room_Addv+0x240> */
/* @0x1b5690 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1b5694 eorseq sp, r8, r8, ror #4 */
/* @0x1b5698 eoreq r8, r3, r8, ror #11 */
/* @0x1b569c andseq r8, r9, r0, lsr #32 */
/* @0x1b56a0 eorseq sp, r8, r0, lsl #4 */
/* @0x1b56a4 ldrhteq sp, [r8], -r4 */
/* @0x1b56a8 mlaseq r8, r12, r1, sp */
/* @0x1b56ac eorseq sp, r8, r8, lsl #3 */
/* @0x1b56b0 eorseq sp, r8, r12, asr r1 */
/* @0x1b56b4 eorseq sp, r8, r4, asr #2 */
/* @0x1b56b8 ldrshteq sp, [r8], -r12 */
/* @0x1b56bc ldrshteq sp, [r8], -r4 */
/* @0x1b56c0 eorseq sp, r8, r12, asr #32 */
/* @0x1b56c4 eorseq sp, r8, r8, lsr r0 */
/* @0x1b56c8 eorseq sp, r8, r4, lsr #32 */
/* @0x1b56cc ldrshteq r12, [r8], -r8 */
/* @0x1b56d0 andseq r7, r9, r0, lsl sp */
/* @0x1b56d4 mlaseq r8, r0, pc, r12 */
/* @0x1b56d8 mulseq r9, r0, r12 */
/* @0x1b56dc eorseq r12, r8, r8, asr #30 */

/* ── FUNC 0x1b56e0 · Room_Duplicate(int) · size=1044 · insn=261 */
/* @0x1b56e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b56e4 sub sp, sp, #172 */
/* @0x1b56e8 ldr r10, [pc, #0x3b0] */
/* @0x1b56ec str r0, [sp, #0x14] */
/* @0x1b56f0 ldr r10, [pc, r10] */
/* @0x1b56f4 ldr r3, [r10] */
/* @0x1b56f8 str r3, [sp, #0xa4] */
/* @0x1b56fc bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x1b5700 cmp r0, #0 */
/* @0x1b5704 beq 0x1b5a94 <_Z14Room_Duplicatei+0x3b4> */
/* @0x1b5708 ldr r4, [pc, #0x394] */
/* @0x1b570c add r6, sp, #36 */
/* @0x1b5710 ldr r2, [pc, #0x390] */
/* @0x1b5714 mov r1, #128 */
/* @0x1b5718 add r4, pc, r4 */
/* @0x1b571c mov r0, r6 */
/* @0x1b5720 add r2, pc, r2 */
/* @0x1b5724 ldr r5, [r4] */
/* @0x1b5728 mov r3, r5 */
/* @0x1b572c bl 0xb65c8 <snprintf@plt> */
/* @0x1b5730 mov r0, r6 */
/* @0x1b5734 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1b5738 ldr r11, [r4, #0x8] */
/* @0x1b573c adds r1, r11, #1 */
/* @0x1b5740 str r1, [sp, #0xc] */
/* @0x1b5744 str r0, [sp, #0x10] */
/* @0x1b5748 bne 0x1b57cc <_Z14Room_Duplicatei+0xec> */
/* @0x1b574c ldr r0, [r4, #0xc] */
/* @0x1b5750 cmp r0, #0 */
/* @0x1b5754 beq 0x1b5a78 <_Z14Room_Duplicatei+0x398> */
/* @0x1b5758 cmp r11, #0 */
/* @0x1b575c ble 0x1b57b0 <_Z14Room_Duplicatei+0xd0> */
/* @0x1b5760 ldr r9, [pc, #0x344] */
/* @0x1b5764 mov r8, r4 */
/* @0x1b5768 mov r7, r1 */
/* @0x1b576c mov r6, r1 */
/* @0x1b5770 add r9, pc, r9 */
/* @0x1b5774 ldr r0, [r0, r7, lsl #2] */
/* @0x1b5778 lsl r4, r7, #2 */
/* @0x1b577c bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x1b5780 cmp r0, #0 */
/* @0x1b5784 beq 0x1b5794 <_Z14Room_Duplicatei+0xb4> */
/* @0x1b5788 ldr r3, [r9, #0xc] */
/* @0x1b578c ldr r0, [r3, r7, lsl #2] */
/* @0x1b5790 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5794 ldr r2, [r8, #0x8] */
/* @0x1b5798 add r7, r7, #1 */
/* @0x1b579c ldr r3, [r8, #0xc] */
/* @0x1b57a0 cmp r7, r2 */
/* @0x1b57a4 str r6, [r3, r4] */
/* @0x1b57a8 ldr r0, [r8, #0xc] */
/* @0x1b57ac blt 0x1b5774 <_Z14Room_Duplicatei+0x94> */
/* @0x1b57b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b57b4 ldr r1, [pc, #0x2f4] */
/* @0x1b57b8 mov r3, #0 */
/* @0x1b57bc add r1, pc, r1 */
/* @0x1b57c0 mov r2, r3 */
/* @0x1b57c4 str r3, [r1, #0xc] */
/* @0x1b57c8 b 0x1b57fc <_Z14Room_Duplicatei+0x11c> */
/* @0x1b57cc ldr r2, [sp, #0xc] */
/* @0x1b57d0 ldr r0, [r4, #0xc] */
/* @0x1b57d4 lsls r1, r2, #2 */
/* @0x1b57d8 beq 0x1b5a78 <_Z14Room_Duplicatei+0x398> */
/* @0x1b57dc ldr r2, [pc, #0x2d0] */
/* @0x1b57e0 mov r3, #0 */
/* @0x1b57e4 str r3, [sp] */
/* @0x1b57e8 mov r3, #92 */
/* @0x1b57ec add r2, pc, r2 */
/* @0x1b57f0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1b57f4 mov r2, r0 */
/* @0x1b57f8 str r0, [r4, #0xc] */
/* @0x1b57fc ldr r3, [pc, #0x2b4] */
/* @0x1b5800 cmp r5, r11 */
/* @0x1b5804 ldr r1, [sp, #0xc] */
/* @0x1b5808 add r3, pc, r3 */
/* @0x1b580c str r1, [r3, #0x8] */
/* @0x1b5810 bge 0x1b5850 <_Z14Room_Duplicatei+0x170> */
/* @0x1b5814 ldr r0, [pc, #0x2a0] */
/* @0x1b5818 lsl r3, r11, #2 */
/* @0x1b581c add r0, pc, r0 */
/* @0x1b5820 b 0x1b5828 <_Z14Room_Duplicatei+0x148> */
/* @0x1b5824 ldr r2, [r0, #0xc] */
/* @0x1b5828 add r1, r2, r3 */
/* @0x1b582c sub r11, r11, #1 */
/* @0x1b5830 cmp r11, r5 */
/* @0x1b5834 ldr r1, [r1, #-0x4] */
/* @0x1b5838 str r1, [r2, r3] */
/* @0x1b583c sub r3, r3, #4 */
/* @0x1b5840 bne 0x1b5824 <_Z14Room_Duplicatei+0x144> */
/* @0x1b5844 ldr r3, [pc, #0x274] */
/* @0x1b5848 add r3, pc, r3 */
/* @0x1b584c ldr r2, [r3, #0xc] */
/* @0x1b5850 ldr r3, [sp, #0x10] */
/* @0x1b5854 mov r0, #292 */
/* @0x1b5858 lsl r1, r5, #2 */
/* @0x1b585c str r1, [sp, #0xc] */
/* @0x1b5860 ldr r11, [pc, #0x25c] */
/* @0x1b5864 str r3, [r2, r5, lsl #2] */
/* @0x1b5868 bl 0x27c524 <_Znwj> */
/* @0x1b586c add r11, pc, r11 */
/* @0x1b5870 str r0, [sp, #0x10] */
/* @0x1b5874 bl 0x1ad2cc <_ZN5CRoomC2Ev> */
/* @0x1b5878 ldr r4, [r11] */
/* @0x1b587c ldr r0, [r11, #0x4] */
/* @0x1b5880 adds r9, r4, #1 */
/* @0x1b5884 bne 0x1b5a30 <_Z14Room_Duplicatei+0x350> */
/* @0x1b5888 cmp r0, #0 */
/* @0x1b588c beq 0x1b5a5c <_Z14Room_Duplicatei+0x37c> */
/* @0x1b5890 cmp r4, #0 */
/* @0x1b5894 ble 0x1b5944 <_Z14Room_Duplicatei+0x264> */
/* @0x1b5898 ldr r1, [pc, #0x228] */
/* @0x1b589c mov r6, r9 */
/* @0x1b58a0 ldr r12, [pc, #0x224] */
/* @0x1b58a4 mov r2, r9 */
/* @0x1b58a8 add r1, pc, r1 */
/* @0x1b58ac str r4, [sp, #0x1c] */
/* @0x1b58b0 add r12, pc, r12 */
/* @0x1b58b4 mov r3, r0 */
/* @0x1b58b8 mov r8, r1 */
/* @0x1b58bc str r5, [sp, #0x18] */
/* @0x1b58c0 mov r4, r12 */
/* @0x1b58c4 ldr r1, [r3] */
/* @0x1b58c8 movw r0, #0xfeee */
/* @0x1b58cc movt r0, #0xfeee */
/* @0x1b58d0 cmp r1, r0 */
/* @0x1b58d4 beq 0x1b5928 <_Z14Room_Duplicatei+0x248> */
/* @0x1b58d8 ldr r7, [r3, r6, lsl #2] */
/* @0x1b58dc lsl r5, r6, #2 */
/* @0x1b58e0 add r0, r3, r5 */
/* @0x1b58e4 cmp r7, #0 */
/* @0x1b58e8 beq 0x1b5928 <_Z14Room_Duplicatei+0x248> */
/* @0x1b58ec ldr lr, [r7] */
/* @0x1b58f0 movw r3, #0xfeee */
/* @0x1b58f4 movt r3, #0xfeee */
/* @0x1b58f8 cmp lr, r3 */
/* @0x1b58fc beq 0x1b5920 <_Z14Room_Duplicatei+0x240> */
/* @0x1b5900 mov r0, r7 */
/* @0x1b5904 str r2, [sp, #0x8] */
/* @0x1b5908 bl 0x1afa00 <_ZN5CRoomD2Ev> */
/* @0x1b590c mov r0, r7 */
/* @0x1b5910 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b5914 ldr r0, [r4, #0x4] */
/* @0x1b5918 ldr r2, [sp, #0x8] */
/* @0x1b591c add r0, r0, r5 */
/* @0x1b5920 str r2, [r0] */
/* @0x1b5924 ldr r3, [r8, #0x4] */
/* @0x1b5928 ldr r1, [r11] */
/* @0x1b592c add r6, r6, #1 */
/* @0x1b5930 cmp r6, r1 */
/* @0x1b5934 blt 0x1b58c4 <_Z14Room_Duplicatei+0x1e4> */
/* @0x1b5938 ldr r5, [sp, #0x18] */
/* @0x1b593c mov r0, r3 */
/* @0x1b5940 ldr r4, [sp, #0x1c] */
/* @0x1b5944 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5948 ldr r1, [pc, #0x180] */
/* @0x1b594c mov r3, #0 */
/* @0x1b5950 add r1, pc, r1 */
/* @0x1b5954 mov r2, r3 */
/* @0x1b5958 str r3, [r1, #0x4] */
/* @0x1b595c ldr r3, [pc, #0x170] */
/* @0x1b5960 cmp r5, r4 */
/* @0x1b5964 add r3, pc, r3 */
/* @0x1b5968 str r9, [r3] */
/* @0x1b596c bge 0x1b59ac <_Z14Room_Duplicatei+0x2cc> */
/* @0x1b5970 ldr r0, [pc, #0x160] */
/* @0x1b5974 lsl r3, r4, #2 */
/* @0x1b5978 add r0, pc, r0 */
/* @0x1b597c b 0x1b5984 <_Z14Room_Duplicatei+0x2a4> */
/* @0x1b5980 ldr r2, [r0, #0x4] */
/* @0x1b5984 add r1, r2, r3 */
/* @0x1b5988 sub r4, r4, #1 */
/* @0x1b598c cmp r4, r5 */
/* @0x1b5990 ldr r1, [r1, #-0x4] */
/* @0x1b5994 str r1, [r2, r3] */
/* @0x1b5998 sub r3, r3, #4 */
/* @0x1b599c bne 0x1b5980 <_Z14Room_Duplicatei+0x2a0> */
/* @0x1b59a0 ldr r3, [pc, #0x134] */
/* @0x1b59a4 add r3, pc, r3 */
/* @0x1b59a8 ldr r2, [r3, #0x4] */
/* @0x1b59ac ldr r1, [sp, #0x10] */
/* @0x1b59b0 cmp r5, r9 */
/* @0x1b59b4 ldr r3, [sp, #0xc] */
/* @0x1b59b8 str r1, [r2, r3] */
/* @0x1b59bc bge 0x1b5a1c <_Z14Room_Duplicatei+0x33c> */
/* @0x1b59c0 ldr r2, [pc, #0x118] */
/* @0x1b59c4 mov r3, #1 */
/* @0x1b59c8 ldr r1, [sp, #0xc] */
/* @0x1b59cc add r2, pc, r2 */
/* @0x1b59d0 ldr r2, [r2, #0x4] */
/* @0x1b59d4 ldr r0, [r2, r1] */
/* @0x1b59d8 strb r3, [r0, #0xd0] */
/* @0x1b59dc ldr r2, [sp, #0x14] */
/* @0x1b59e0 cmp r2, r9 */
/* @0x1b59e4 movge r1, #0 */
/* @0x1b59e8 ldrlt r3, [pc, #0xf4] */
/* @0x1b59ec addlt r3, pc, r3 */
/* @0x1b59f0 ldrlt r3, [r3, #0x4] */
/* @0x1b59f4 ldrlt r1, [r3, r2, lsl #2] */
/* @0x1b59f8 mov r2, #0 */
/* @0x1b59fc bl 0x1ad70c <_ZN5CRoom6AssignEPS_b> */
/* @0x1b5a00 ldr r2, [sp, #0xa4] */
/* @0x1b5a04 mov r0, r5 */
/* @0x1b5a08 ldr r3, [r10] */
/* @0x1b5a0c cmp r2, r3 */
/* @0x1b5a10 bne 0x1b5a9c <_Z14Room_Duplicatei+0x3bc> */
/* @0x1b5a14 add sp, sp, #172 */
/* @0x1b5a18 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b5a1c mov r3, #0 */
/* @0x1b5a20 mov r2, #1 */
/* @0x1b5a24 mov r0, r3 */
/* @0x1b5a28 strb r2, [r3, #0xd0] */
/* @0x1b5a2c b 0x1b59dc <_Z14Room_Duplicatei+0x2fc> */
/* @0x1b5a30 lsls r1, r9, #2 */
/* @0x1b5a34 beq 0x1b5a5c <_Z14Room_Duplicatei+0x37c> */
/* @0x1b5a38 ldr r2, [pc, #0xa8] */
/* @0x1b5a3c mov r3, #0 */
/* @0x1b5a40 str r3, [sp] */
/* @0x1b5a44 mov r3, #135 */
/* @0x1b5a48 add r2, pc, r2 */
/* @0x1b5a4c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1b5a50 mov r2, r0 */
/* @0x1b5a54 str r0, [r11, #0x4] */
/* @0x1b5a58 b 0x1b595c <_Z14Room_Duplicatei+0x27c> */
/* @0x1b5a5c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5a60 ldr r1, [pc, #0x84] */
/* @0x1b5a64 mov r3, #0 */
/* @0x1b5a68 add r1, pc, r1 */
/* @0x1b5a6c mov r2, r3 */
/* @0x1b5a70 str r3, [r1, #0x4] */
/* @0x1b5a74 b 0x1b595c <_Z14Room_Duplicatei+0x27c> */
/* @0x1b5a78 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5a7c ldr r1, [pc, #0x6c] */
/* @0x1b5a80 mov r3, #0 */
/* @0x1b5a84 add r1, pc, r1 */
/* @0x1b5a88 mov r2, r3 */
/* @0x1b5a8c str r3, [r1, #0xc] */
/* @0x1b5a90 b 0x1b57fc <_Z14Room_Duplicatei+0x11c> */
/* @0x1b5a94 mvn r5, #0 */
/* @0x1b5a98 b 0x1b5a00 <_Z14Room_Duplicatei+0x320> */
/* @0x1b5a9c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1b5aa0 eoreq r8, r3, r0, ror #4 */
/* @0x1b5aa4 ldrhteq r12, [r8], -r0 */
/* @0x1b5aa8 andseq r7, r9, r4, ror r12 */
/* @0x1b5aac eorseq r12, r8, r8, asr lr */
/* @0x1b5ab0 eorseq r12, r8, r12, lsl #28 */
/* @0x1b5ab4 andseq r7, r9, r12, lsr r11 */
/* @0x1b5ab8 eorseq r12, r8, r0, asr #27 */
/* @0x1b5abc eorseq r12, r8, r12, lsr #27 */
/* @0x1b5ac0 eorseq r12, r8, r0, lsl #27 */
/* @0x1b5ac4 eorseq r12, r8, r12, asr sp */
/* @0x1b5ac8 eorseq r12, r8, r0, lsr #26 */
/* @0x1b5acc eorseq r12, r8, r8, lsl sp */
/* @0x1b5ad0 eorseq r12, r8, r8, ror r12 */
/* @0x1b5ad4 eorseq r12, r8, r4, ror #24 */
/* @0x1b5ad8 eorseq r12, r8, r0, asr r12 */
/* @0x1b5adc eorseq r12, r8, r4, lsr #24 */
/* @0x1b5ae0 ldrshteq r12, [r8], -r12 */
/* @0x1b5ae4 ldrsbteq r12, [r8], -r12 */
/* @0x1b5ae8 andseq r7, r9, r8, lsr #17 */
/* @0x1b5aec eorseq r12, r8, r0, ror #22 */
/* @0x1b5af0 eorseq r12, r8, r4, asr #22 */

/* ── FUNC 0x1b5af4 · Room_Assign(int, int) · size=172 · insn=43 */
/* @0x1b5af4 push {r4, r5, r6, lr} */
/* @0x1b5af8 mov r5, r1 */
/* @0x1b5afc mov r4, r0 */
/* @0x1b5b00 bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x1b5b04 cmp r0, #0 */
/* @0x1b5b08 beq 0x1b5b78 <_Z11Room_Assignii+0x84> */
/* @0x1b5b0c mov r0, r5 */
/* @0x1b5b10 bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x1b5b14 cmp r0, #0 */
/* @0x1b5b18 beq 0x1b5b78 <_Z11Room_Assignii+0x84> */
/* @0x1b5b1c mov r0, #292 */
/* @0x1b5b20 bl 0x27c524 <_Znwj> */
/* @0x1b5b24 mov r6, r0 */
/* @0x1b5b28 bl 0x1ad2cc <_ZN5CRoomC2Ev> */
/* @0x1b5b2c ldr r3, [pc, #0x64] */
/* @0x1b5b30 add r3, pc, r3 */
/* @0x1b5b34 ldr r2, [r3] */
/* @0x1b5b38 ldr r1, [r3, #0x4] */
/* @0x1b5b3c cmp r4, r2 */
/* @0x1b5b40 str r6, [r1, r4, lsl #2] */
/* @0x1b5b44 movge r0, #0 */
/* @0x1b5b48 blt 0x1b5b80 <_Z11Room_Assignii+0x8c> */
/* @0x1b5b4c cmp r5, r2 */
/* @0x1b5b50 movge r1, #0 */
/* @0x1b5b54 bge 0x1b5b68 <_Z11Room_Assignii+0x74> */
/* @0x1b5b58 ldr r3, [pc, #0x3c] */
/* @0x1b5b5c add r3, pc, r3 */
/* @0x1b5b60 ldr r3, [r3, #0x4] */
/* @0x1b5b64 ldr r1, [r3, r5, lsl #2] */
/* @0x1b5b68 mov r2, #1 */
/* @0x1b5b6c bl 0x1ad70c <_ZN5CRoom6AssignEPS_b> */
/* @0x1b5b70 mov r0, #1 */
/* @0x1b5b74 pop {r4, r5, r6, pc} */
/* @0x1b5b78 mov r0, #0 */
/* @0x1b5b7c pop {r4, r5, r6, pc} */
/* @0x1b5b80 ldr r3, [r3, #0x4] */
/* @0x1b5b84 cmp r5, r2 */
/* @0x1b5b88 movge r1, #0 */
/* @0x1b5b8c ldr r0, [r3, r4, lsl #2] */
/* @0x1b5b90 bge 0x1b5b68 <_Z11Room_Assignii+0x74> */
/* @0x1b5b94 b 0x1b5b58 <_Z11Room_Assignii+0x64> */
/* @0x1b5b98 mlaseq r8, r8, r10, r12 */
/* @0x1b5b9c eorseq r12, r8, r12, ror #20 */

/* ── FUNC 0x1b5ba0 · Room_LoadOrder(YYHeader*, int) · size=360 · insn=90 */
/* @0x1b5ba0 ldrb r3, [r0, #0x1] */
/* @0x1b5ba4 push {r4, r5, r6, lr} */
/* @0x1b5ba8 cmp r3, #7 */
/* @0x1b5bac sub sp, sp, #8 */
/* @0x1b5bb0 bgt 0x1b5bf0 <_Z14Room_LoadOrderP8YYHeaderi+0x50> */
/* @0x1b5bb4 ldr r4, [r0, #0x24] */
/* @0x1b5bb8 add r5, r0, #40 */
/* @0x1b5bbc cmp r4, #0 */
/* @0x1b5bc0 bne 0x1b5c28 <_Z14Room_LoadOrderP8YYHeaderi+0x88> */
/* @0x1b5bc4 ldr r6, [pc, #0x124] */
/* @0x1b5bc8 add r6, pc, r6 */
/* @0x1b5bcc ldr r0, [r6, #0x14] */
/* @0x1b5bd0 cmp r0, #0 */
/* @0x1b5bd4 beq 0x1b5ca8 <_Z14Room_LoadOrderP8YYHeaderi+0x108> */
/* @0x1b5bd8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5bdc str r4, [r6, #0x14] */
/* @0x1b5be0 str r4, [r6, #0x10] */
/* @0x1b5be4 mov r0, #1 */
/* @0x1b5be8 add sp, sp, #8 */
/* @0x1b5bec pop {r4, r5, r6, pc} */
/* @0x1b5bf0 cmp r3, #10 */
/* @0x1b5bf4 beq 0x1b5cc0 <_Z14Room_LoadOrderP8YYHeaderi+0x120> */
/* @0x1b5bf8 cmp r3, #11 */
/* @0x1b5bfc beq 0x1b5cd8 <_Z14Room_LoadOrderP8YYHeaderi+0x138> */
/* @0x1b5c00 cmp r3, #12 */
/* @0x1b5c04 beq 0x1b5ccc <_Z14Room_LoadOrderP8YYHeaderi+0x12c> */
/* @0x1b5c08 cmp r3, #13 */
/* @0x1b5c0c beq 0x1b5ce4 <_Z14Room_LoadOrderP8YYHeaderi+0x144> */
/* @0x1b5c10 ldrgt r4, [r0, #0x80] */
/* @0x1b5c14 addgt r5, r0, #132 */
/* @0x1b5c18 ldrle r4, [r0, #0x64] */
/* @0x1b5c1c addle r5, r0, #104 */
/* @0x1b5c20 cmp r4, #0 */
/* @0x1b5c24 beq 0x1b5bc4 <_Z14Room_LoadOrderP8YYHeaderi+0x24> */
/* @0x1b5c28 lsls r1, r4, #2 */
/* @0x1b5c2c beq 0x1b5c9c <_Z14Room_LoadOrderP8YYHeaderi+0xfc> */
/* @0x1b5c30 ldr r6, [pc, #0xbc] */
/* @0x1b5c34 mov r3, #0 */
/* @0x1b5c38 ldr r2, [pc, #0xb8] */
/* @0x1b5c3c add r6, pc, r6 */
/* @0x1b5c40 str r3, [sp] */
/* @0x1b5c44 add r2, pc, r2 */
/* @0x1b5c48 mov r3, #106 */
/* @0x1b5c4c ldr r0, [r6, #0x14] */
/* @0x1b5c50 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1b5c54 str r0, [r6, #0x14] */
/* @0x1b5c58 ldr r0, [pc, #0x9c] */
/* @0x1b5c5c cmp r4, #0 */
/* @0x1b5c60 add r0, pc, r0 */
/* @0x1b5c64 str r4, [r0, #0x10] */
/* @0x1b5c68 ble 0x1b5be4 <_Z14Room_LoadOrderP8YYHeaderi+0x44> */
/* @0x1b5c6c mov r3, #0 */
/* @0x1b5c70 mov r2, r3 */
/* @0x1b5c74 ldr r12, [r5, r3] */
/* @0x1b5c78 add r2, r2, #1 */
/* @0x1b5c7c ldr r1, [r0, #0x14] */
/* @0x1b5c80 cmp r2, r4 */
/* @0x1b5c84 str r12, [r1, r3] */
/* @0x1b5c88 add r3, r3, #4 */
/* @0x1b5c8c bne 0x1b5c74 <_Z14Room_LoadOrderP8YYHeaderi+0xd4> */
/* @0x1b5c90 mov r0, #1 */
/* @0x1b5c94 add sp, sp, #8 */
/* @0x1b5c98 pop {r4, r5, r6, pc} */
/* @0x1b5c9c ldr r3, [pc, #0x5c] */
/* @0x1b5ca0 add r3, pc, r3 */
/* @0x1b5ca4 ldr r0, [r3, #0x14] */
/* @0x1b5ca8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5cac ldr r3, [pc, #0x50] */
/* @0x1b5cb0 mov r2, #0 */
/* @0x1b5cb4 add r3, pc, r3 */
/* @0x1b5cb8 str r2, [r3, #0x14] */
/* @0x1b5cbc b 0x1b5c58 <_Z14Room_LoadOrderP8YYHeaderi+0xb8> */
/* @0x1b5cc0 ldr r4, [r0, #0x68] */
/* @0x1b5cc4 add r5, r0, #108 */
/* @0x1b5cc8 b 0x1b5bbc <_Z14Room_LoadOrderP8YYHeaderi+0x1c> */
/* @0x1b5ccc ldr r4, [r0, #0x78] */
/* @0x1b5cd0 add r5, r0, #124 */
/* @0x1b5cd4 b 0x1b5bbc <_Z14Room_LoadOrderP8YYHeaderi+0x1c> */
/* @0x1b5cd8 ldr r4, [r0, #0x70] */
/* @0x1b5cdc add r5, r0, #116 */
/* @0x1b5ce0 b 0x1b5bbc <_Z14Room_LoadOrderP8YYHeaderi+0x1c> */
/* @0x1b5ce4 ldr r4, [r0, #0x7c] */
/* @0x1b5ce8 add r5, r0, #128 */
/* @0x1b5cec b 0x1b5bbc <_Z14Room_LoadOrderP8YYHeaderi+0x1c> */
/* @0x1b5cf0 eorseq r12, r8, r0, lsl #20 */
/* @0x1b5cf4 eorseq r12, r8, r12, lsl #19 */
/* @0x1b5cf8 ldrsheq r7, [r9], -r0 */
/* @0x1b5cfc eorseq r12, r8, r8, ror #18 */
/* @0x1b5d00 eorseq r12, r8, r8, lsr #18 */
/* @0x1b5d04 eorseq r12, r8, r4, lsl r9 */

/* ── FUNC 0x1b5d08 · Room_First() · size=24 · insn=6 */
/* @0x1b5d08 ldr r3, [pc, #0xc] */
/* @0x1b5d0c add r3, pc, r3 */
/* @0x1b5d10 ldr r3, [r3, #0x14] */
/* @0x1b5d14 ldr r0, [r3] */
/* @0x1b5d18 bx lr */
/* @0x1b5d1c ldrhteq r12, [r8], -r12 */

/* ── FUNC 0x1b5d20 · Room_Last() · size=32 · insn=8 */
/* @0x1b5d20 ldr r3, [pc, #0x14] */
/* @0x1b5d24 add r3, pc, r3 */
/* @0x1b5d28 ldr r2, [r3, #0x10] */
/* @0x1b5d2c ldr r3, [r3, #0x14] */
/* @0x1b5d30 sub r2, r2, #1 */
/* @0x1b5d34 ldr r0, [r3, r2, lsl #2] */
/* @0x1b5d38 bx lr */
/* @0x1b5d3c eorseq r12, r8, r4, lsr #17 */

/* ── FUNC 0x1b5d40 · Room_Previous(int) · size=100 · insn=25 */
/* @0x1b5d40 ldr r3, [pc, #0x58] */
/* @0x1b5d44 str r4, [sp, #-0x4]! */
/* @0x1b5d48 add r3, pc, r3 */
/* @0x1b5d4c mov r4, r0 */
/* @0x1b5d50 ldr r12, [r3, #0x10] */
/* @0x1b5d54 cmp r12, #1 */
/* @0x1b5d58 ble 0x1b5d98 <_Z13Room_Previousi+0x58> */
/* @0x1b5d5c ldr r2, [r3, #0x14] */
/* @0x1b5d60 ldm r2, {r0, r3} */
/* @0x1b5d64 cmp r3, r4 */
/* @0x1b5d68 beq 0x1b5d90 <_Z13Room_Previousi+0x50> */
/* @0x1b5d6c mov r3, #1 */
/* @0x1b5d70 b 0x1b5d84 <_Z13Room_Previousi+0x44> */
/* @0x1b5d74 ldr r0, [r2, #0x4]! */
/* @0x1b5d78 ldr r1, [r2, #0x4] */
/* @0x1b5d7c cmp r1, r4 */
/* @0x1b5d80 beq 0x1b5d90 <_Z13Room_Previousi+0x50> */
/* @0x1b5d84 add r3, r3, #1 */
/* @0x1b5d88 cmp r3, r12 */
/* @0x1b5d8c bne 0x1b5d74 <_Z13Room_Previousi+0x34> */
/* @0x1b5d90 ldr r4, [sp], #4 */
/* @0x1b5d94 bx lr */
/* @0x1b5d98 mvn r0, #0 */
/* @0x1b5d9c b 0x1b5d90 <_Z13Room_Previousi+0x50> */
/* @0x1b5da0 eorseq r12, r8, r0, lsl #17 */

/* ── FUNC 0x1b5da4 · Room_Next(int) · size=96 · insn=24 */
/* @0x1b5da4 ldr r1, [pc, #0x54] */
/* @0x1b5da8 mov r12, r0 */
/* @0x1b5dac add r1, pc, r1 */
/* @0x1b5db0 ldr r2, [r1, #0x10] */
/* @0x1b5db4 subs r3, r2, #2 */
/* @0x1b5db8 bmi 0x1b5df8 <_Z9Room_Nexti+0x54> */
/* @0x1b5dbc ldr r1, [r1, #0x14] */
/* @0x1b5dc0 sub r0, r2, #1 */
/* @0x1b5dc4 add r2, r1, r0, lsl #2 */
/* @0x1b5dc8 ldr r0, [r1, r0, lsl #2] */
/* @0x1b5dcc ldr r1, [r2, #-0x4] */
/* @0x1b5dd0 cmp r1, r12 */
/* @0x1b5dd4 bne 0x1b5dec <_Z9Room_Nexti+0x48> */
/* @0x1b5dd8 bx lr */
/* @0x1b5ddc ldr r0, [r2, #-0x4]! */
/* @0x1b5de0 ldr r1, [r2, #-0x4] */
/* @0x1b5de4 cmp r1, r12 */
/* @0x1b5de8 bxeq lr */
/* @0x1b5dec subs r3, r3, #1 */
/* @0x1b5df0 bhs 0x1b5ddc <_Z9Room_Nexti+0x38> */
/* @0x1b5df4 bx lr */
/* @0x1b5df8 mvn r0, #0 */
/* @0x1b5dfc bx lr */
/* @0x1b5e00 eorseq r12, r8, r12, lsl r8 */

/* ── FUNC 0x1b5e04 · Room_Get_maxid() · size=20 · insn=5 */
/* @0x1b5e04 ldr r3, [pc, #0x8] */
/* @0x1b5e08 ldr r3, [pc, r3] */
/* @0x1b5e0c ldr r0, [r3] */
/* @0x1b5e10 bx lr */
/* @0x1b5e14 eoreq r10, r3, r4, lsl #20 */

/* ── FUNC 0x1b5e18 · Room_Set_maxid(int) · size=20 · insn=5 */
/* @0x1b5e18 ldr r3, [pc, #0x8] */
/* @0x1b5e1c ldr r3, [pc, r3] */
/* @0x1b5e20 str r0, [r3] */
/* @0x1b5e24 bx lr */
/* @0x1b5e28 .word 0x0023a9f0 */

/* ── FUNC 0x1b5e2c · Room_Get_maxtileid() · size=20 · insn=5 */
/* @0x1b5e2c ldr r3, [pc, #0x8] */
/* @0x1b5e30 ldr r3, [pc, r3] */
/* @0x1b5e34 ldr r0, [r3] */
/* @0x1b5e38 bx lr */
/* @0x1b5e3c eoreq r10, r3, r0, ror #19 */

/* ── FUNC 0x1b5e40 · Room_Set_maxtileid(int) · size=20 · insn=5 */
/* @0x1b5e40 ldr r3, [pc, #0x8] */
/* @0x1b5e44 ldr r3, [pc, r3] */
/* @0x1b5e48 str r0, [r3] */
/* @0x1b5e4c bx lr */
/* @0x1b5e50 eoreq r10, r3, r12, asr #19 */

/* ── FUNC 0x1b5e54 · FINALIZE_Room_Main() · size=32 · insn=8 */
/* @0x1b5e54 push {r3, lr} */
/* @0x1b5e58 bl 0x1b5044 <_Z9Room_Freev> */
/* @0x1b5e5c mov r2, #0 */
/* @0x1b5e60 ldr r3, [pc, #0x8] */
/* @0x1b5e64 ldr r3, [pc, r3] */
/* @0x1b5e68 str r2, [r3] */
/* @0x1b5e6c pop {r3, pc} */
/* @0x1b5e70 .word 0x0023a9dc */

/* ── FUNC 0x1b5e74 · F_TilemapGetGlobalMask(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x1b5e74 ldr r3, [pc, #0x20] */
/* @0x1b5e78 mov r2, #0 */
/* @0x1b5e7c str r2, [r0, #0xc] */
/* @0x1b5e80 ldr r3, [pc, r3] */
/* @0x1b5e84 ldr r2, [r3] */
/* @0x1b5e88 vmov s15, r2 */
/* @0x1b5e8c vcvt.f64.u32 d7, s15 */
/* @0x1b5e90 vmov r2, r3, d7 */
/* @0x1b5e94 stm r0, {r2, r3} */
/* @0x1b5e98 bx lr */
/* @0x1b5e9c mlaeq r3, r8, r9, r10 */

/* ── FUNC 0x1b5ea0 · F_LayerGetTargetRoom(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x1b5ea0 ldr r3, [pc, #0x20] */
/* @0x1b5ea4 mov r2, #0 */
/* @0x1b5ea8 str r2, [r0, #0xc] */
/* @0x1b5eac ldr r3, [pc, r3] */
/* @0x1b5eb0 ldr r2, [r3] */
/* @0x1b5eb4 vmov s15, r2 */
/* @0x1b5eb8 vcvt.f64.s32 d7, s15 */
/* @0x1b5ebc vmov r2, r3, d7 */
/* @0x1b5ec0 stm r0, {r2, r3} */
/* @0x1b5ec4 bx lr */
/* @0x1b5ec8 eoreq r10, r3, r8, lsr #19 */

/* ── FUNC 0x1b5ecc · F_LayerResetTargetRoom(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x1b5ecc ldr r3, [pc, #0xc] */
/* @0x1b5ed0 mvn r2, #0 */
/* @0x1b5ed4 ldr r3, [pc, r3] */
/* @0x1b5ed8 str r2, [r3] */
/* @0x1b5edc bx lr */
/* @0x1b5ee0 eoreq r10, r3, r0, lsl #19 */

/* ── FUNC 0x1b5ee4 · F_LayerIsDrawDepthForced(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1b5ee4 ldr r3, [pc, #0x28] */
/* @0x1b5ee8 mov r2, #0 */
/* @0x1b5eec str r2, [r0, #0xc] */
/* @0x1b5ef0 ldr r3, [pc, r3] */
/* @0x1b5ef4 ldrb r3, [r3] */
/* @0x1b5ef8 cmp r3, r2 */
/* @0x1b5efc movne r3, r2 */
/* @0x1b5f00 moveq r2, r3 */
/* @0x1b5f04 movtne r2, #0x3ff0 */
/* @0x1b5f08 str r3, [r0] */
/* @0x1b5f0c str r2, [r0, #0x4] */
/* @0x1b5f10 bx lr */
/* @0x1b5f14 eoreq r10, r3, r0, asr #18 */

/* ── FUNC 0x1b5f18 · F_LayerGetForcedDepth(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x1b5f18 ldr r3, [pc, #0x20] */
/* @0x1b5f1c mov r2, #0 */
/* @0x1b5f20 str r2, [r0, #0xc] */
/* @0x1b5f24 ldr r3, [pc, r3] */
/* @0x1b5f28 ldr r2, [r3] */
/* @0x1b5f2c vmov s15, r2 */
/* @0x1b5f30 vcvt.f64.s32 d7, s15 */
/* @0x1b5f34 vmov r2, r3, d7 */
/* @0x1b5f38 stm r0, {r2, r3} */
/* @0x1b5f3c bx lr */
/* @0x1b5f40 eoreq r10, r3, r0, lsl r9 */

/* ── FUNC 0x1b5f44 · ObjectPool<CLayerBackgroundElement>::~ObjectPool() · size=168 · insn=42 */
/* @0x1b5f44 push {r3, r4, r5, lr} */
/* @0x1b5f48 mov r5, r0 */
/* @0x1b5f4c ldr r3, [r0, #0xc] */
/* @0x1b5f50 cmp r3, #0 */
/* @0x1b5f54 beq 0x1b5f8c <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x48> */
/* @0x1b5f58 ldr r0, [r0] */
/* @0x1b5f5c cmp r0, #0 */
/* @0x1b5f60 beq 0x1b5f8c <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x48> */
/* @0x1b5f64 cmp r3, #2 */
/* @0x1b5f68 beq 0x1b5fa4 <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x60> */
/* @0x1b5f6c cmp r3, #3 */
/* @0x1b5f70 beq 0x1b5fbc <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x78> */
/* @0x1b5f74 cmp r3, #1 */
/* @0x1b5f78 beq 0x1b5fd4 <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x90> */
/* @0x1b5f7c ldr r4, [r0, #0x14] */
/* @0x1b5f80 cmp r4, #0 */
/* @0x1b5f84 mov r0, r4 */
/* @0x1b5f88 bne 0x1b5f7c <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x38> */
/* @0x1b5f8c mov r3, #0 */
/* @0x1b5f90 mov r0, r5 */
/* @0x1b5f94 str r3, [r5, #0x8] */
/* @0x1b5f98 str r3, [r5, #0x4] */
/* @0x1b5f9c str r3, [r5] */
/* @0x1b5fa0 pop {r3, r4, r5, pc} */
/* @0x1b5fa4 ldr r4, [r0, #0x14] */
/* @0x1b5fa8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5fac cmp r4, #0 */
/* @0x1b5fb0 mov r0, r4 */
/* @0x1b5fb4 bne 0x1b5fa4 <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x60> */
/* @0x1b5fb8 b 0x1b5f8c <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x48> */
/* @0x1b5fbc ldr r4, [r0, #0x14] */
/* @0x1b5fc0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5fc4 cmp r4, #0 */
/* @0x1b5fc8 mov r0, r4 */
/* @0x1b5fcc bne 0x1b5fbc <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x78> */
/* @0x1b5fd0 b 0x1b5f8c <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x48> */
/* @0x1b5fd4 ldr r4, [r0, #0x14] */
/* @0x1b5fd8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b5fdc cmp r4, #0 */
/* @0x1b5fe0 mov r0, r4 */
/* @0x1b5fe4 bne 0x1b5fd4 <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x90> */
/* @0x1b5fe8 b 0x1b5f8c <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x48> */
