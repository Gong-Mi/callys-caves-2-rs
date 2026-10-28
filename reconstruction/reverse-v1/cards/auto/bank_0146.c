/* libyoyo.so 覆盖卡组 0146
 * 函数 0x1b6e4c..0x1b8d9c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1b6e4c · ElementsHaveLoop(LinkedList<CLayerElementBase>*) · size=116 · insn=29 */
/* @0x1b6e4c cmp r0, #0 */
/* @0x1b6e50 bxeq lr */
/* @0x1b6e54 ldr r3, [r0] */
/* @0x1b6e58 cmp r3, #0 */
/* @0x1b6e5c beq 0x1b6ea8 <_Z16ElementsHaveLoopP10LinkedListI17CLayerElementBaseE+0x5c> */
/* @0x1b6e60 ldr r0, [r3, #0x14] */
/* @0x1b6e64 cmp r0, #0 */
/* @0x1b6e68 bxeq lr */
/* @0x1b6e6c cmp r3, r0 */
/* @0x1b6e70 beq 0x1b6eb0 <_Z16ElementsHaveLoopP10LinkedListI17CLayerElementBaseE+0x64> */
/* @0x1b6e74 cmp r3, #0 */
/* @0x1b6e78 ldrne r3, [r3, #0x14] */
/* @0x1b6e7c cmp r0, #0 */
/* @0x1b6e80 bxeq lr */
/* @0x1b6e84 ldr r2, [r0, #0x14] */
/* @0x1b6e88 cmp r2, #0 */
/* @0x1b6e8c beq 0x1b6eb8 <_Z16ElementsHaveLoopP10LinkedListI17CLayerElementBaseE+0x6c> */
/* @0x1b6e90 cmp r3, #0 */
/* @0x1b6e94 ldr r0, [r2, #0x14] */
/* @0x1b6e98 beq 0x1b6ea8 <_Z16ElementsHaveLoopP10LinkedListI17CLayerElementBaseE+0x5c> */
/* @0x1b6e9c cmp r0, #0 */
/* @0x1b6ea0 bne 0x1b6e6c <_Z16ElementsHaveLoopP10LinkedListI17CLayerElementBaseE+0x20> */
/* @0x1b6ea4 bx lr */
/* @0x1b6ea8 mov r0, r3 */
/* @0x1b6eac bx lr */
/* @0x1b6eb0 mov r0, #1 */
/* @0x1b6eb4 bx lr */
/* @0x1b6eb8 mov r0, r2 */
/* @0x1b6ebc bx lr */

/* ── FUNC 0x1b6ec0 · IsLayerListInOrder(CRoom*) · size=60 · insn=15 */
/* @0x1b6ec0 ldr r3, [r0, #0xd4] */
/* @0x1b6ec4 cmp r3, #0 */
/* @0x1b6ec8 beq 0x1b6ef4 <_Z18IsLayerListInOrderP5CRoom+0x34> */
/* @0x1b6ecc ldr r1, [r3, #0x4] */
/* @0x1b6ed0 ldr r3, [r3, #0x68] */
/* @0x1b6ed4 cmp r3, #0 */
/* @0x1b6ed8 beq 0x1b6ef4 <_Z18IsLayerListInOrderP5CRoom+0x34> */
/* @0x1b6edc ldr r2, [r3, #0x4] */
/* @0x1b6ee0 cmp r2, r1 */
/* @0x1b6ee4 mov r1, r2 */
/* @0x1b6ee8 bge 0x1b6ed0 <_Z18IsLayerListInOrderP5CRoom+0x10> */
/* @0x1b6eec mov r0, #0 */
/* @0x1b6ef0 bx lr */
/* @0x1b6ef4 mov r0, #1 */
/* @0x1b6ef8 bx lr */

/* ── FUNC 0x1b6efc · anon_1b6efc · size=0 · insn=1 */
/* @0x1b6efc andeq r0, r0, r0 */

/* ── FUNC 0x1b6f00 · CLayerManager::Init() · size=2048 · insn=510 */
/* @0x1b6f00 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b6f04 vpush {d8, d9} */
/* @0x1b6f08 sub sp, sp, #12 */
/* @0x1b6f0c ldr r7, [pc, #0x34] */
/* @0x1b6f10 ldr r3, [pc, #0x34] */
/* @0x1b6f14 add r7, pc, r7 */
/* @0x1b6f18 ldr r3, [r7, r3] */
/* @0x1b6f1c str r3, [sp, #0x4] */
/* @0x1b6f20 ldrb r3, [r3] */
/* @0x1b6f24 cmp r3, #0 */
/* @0x1b6f28 beq 0x1b6f60 <_ZN13CLayerManager4InitEv+0x60> */
/* @0x1b6f2c ldr r3, [pc, #0x1c] */
/* @0x1b6f30 mvn r2, #-2147483648 */
/* @0x1b6f34 ldr r3, [r7, r3] */
/* @0x1b6f38 str r2, [r3] */
/* @0x1b6f3c add sp, sp, #12 */
/* @0x1b6f40 vpop {d8, d9} */
/* @0x1b6f44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b6f48 eoreq r10, r3, r12, lsr sp */
/* @0x1b6f4c .word 0xffffec08 */
/* @0x1b6f50 .word 0xffffebc8 */
/* @0x1b6f54 .word 0xffffec0c */
/* @0x1b6f58 andseq r6, r9, r8, lsl r7 */
/* @0x1b6f5c andeq r0, r0, r0 */
/* @0x1b6f60 ldr r1, [pc, #-0x14] */
/* @0x1b6f64 mov r9, #32 */
/* @0x1b6f68 ldr r11, [pc, #-0x18] */
/* @0x1b6f6c mov r10, #1 */
/* @0x1b6f70 mov r2, #3 */
/* @0x1b6f74 vldr s16, [pc, #-32] */
/* @0x1b6f78 ldr r8, [r7, r1] */
/* @0x1b6f7c add r11, pc, r11 */
/* @0x1b6f80 vldr d9, [pc, #1008] */
/* @0x1b6f84 str r3, [r8, #0x4] */
/* @0x1b6f88 str r3, [r8] */
/* @0x1b6f8c str r3, [r8, #0x8] */
/* @0x1b6f90 str r2, [r8, #0xc] */
/* @0x1b6f94 mov r2, #45 */
/* @0x1b6f98 mov r0, #112 */
/* @0x1b6f9c mov r1, r11 */
/* @0x1b6fa0 mov r3, #1 */
/* @0x1b6fa4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1b6fa8 mov r4, #0 */
/* @0x1b6fac mvn r2, #0 */
/* @0x1b6fb0 subs r6, r0, #0 */
/* @0x1b6fb4 add r0, r6, #48 */
/* @0x1b6fb8 beq 0x1b700c <_ZN13CLayerManager4InitEv+0x10c> */
/* @0x1b6fbc str r2, [r6] */
/* @0x1b6fc0 vstr s16, [r6, #8] */
/* @0x1b6fc4 str r4, [r6, #0x4] */
/* @0x1b6fc8 vstr s16, [r6, #12] */
/* @0x1b6fcc vstr s16, [r6, #16] */
/* @0x1b6fd0 vstr s16, [r6, #20] */
/* @0x1b6fd4 strb r10, [r6, #0x18] */
/* @0x1b6fd8 vstr d9, [r6, #72] */
/* @0x1b6fdc strb r4, [r6, #0x19] */
/* @0x1b6fe0 str r4, [r6, #0x1c] */
/* @0x1b6fe4 str r2, [r6, #0x20] */
/* @0x1b6fe8 str r2, [r6, #0x24] */
/* @0x1b6fec str r2, [r6, #0x28] */
/* @0x1b6ff0 bl 0x214728 <_ZN13CTimingSource5ResetEv> */
/* @0x1b6ff4 str r4, [r6, #0x5c] */
/* @0x1b6ff8 str r4, [r6, #0x58] */
/* @0x1b6ffc str r4, [r6, #0x60] */
/* @0x1b7000 str r10, [r6, #0x64] */
/* @0x1b7004 str r4, [r6, #0x68] */
/* @0x1b7008 str r4, [r6, #0x6c] */
/* @0x1b700c ldr r3, [r8] */
/* @0x1b7010 mov r1, #0 */
/* @0x1b7014 ldr r2, [r8, #0x8] */
/* @0x1b7018 cmp r3, r1 */
/* @0x1b701c streq r6, [r8, #0x4] */
/* @0x1b7020 strne r6, [r3, #0x6c] */
/* @0x1b7024 add r2, r2, #1 */
/* @0x1b7028 streq r6, [r8] */
/* @0x1b702c streq r3, [r6, #0x6c] */
/* @0x1b7030 streq r3, [r6, #0x68] */
/* @0x1b7034 strne r6, [r8] */
/* @0x1b7038 strne r3, [r6, #0x68] */
/* @0x1b703c strne r1, [r6, #0x6c] */
/* @0x1b7040 subs r9, r9, #1 */
/* @0x1b7044 str r2, [r8, #0x8] */
/* @0x1b7048 bne 0x1b6f94 <_ZN13CLayerManager4InitEv+0x94> */
/* @0x1b704c ldr r2, [pc, #0x32c] */
/* @0x1b7050 mov r3, #32 */
/* @0x1b7054 ldr r6, [pc, #0x328] */
/* @0x1b7058 mov r11, #1 */
/* @0x1b705c str r3, [r8, #0x10] */
/* @0x1b7060 mvn r10, #0 */
/* @0x1b7064 ldr r5, [r7, r2] */
/* @0x1b7068 add r6, pc, r6 */
/* @0x1b706c mov r8, r9 */
/* @0x1b7070 mov r4, r3 */
/* @0x1b7074 mov r3, #3 */
/* @0x1b7078 str r9, [r5, #0x4] */
/* @0x1b707c str r9, [r5] */
/* @0x1b7080 str r9, [r5, #0x8] */
/* @0x1b7084 str r3, [r5, #0xc] */
/* @0x1b7088 mov r3, #1 */
/* @0x1b708c mov r0, #32 */
/* @0x1b7090 mov r1, r6 */
/* @0x1b7094 mov r2, #45 */
/* @0x1b7098 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1b709c ldr r3, [r5] */
/* @0x1b70a0 cmp r0, #0 */
/* @0x1b70a4 beq 0x1b70c8 <_ZN13CLayerManager4InitEv+0x1c8> */
/* @0x1b70a8 strb r8, [r0, #0x8] */
/* @0x1b70ac str r8, [r0, #0xc] */
/* @0x1b70b0 str r8, [r0, #0x10] */
/* @0x1b70b4 str r8, [r0, #0x14] */
/* @0x1b70b8 str r8, [r0, #0x18] */
/* @0x1b70bc str r10, [r0, #0x4] */
/* @0x1b70c0 str r8, [r0, #0x1c] */
/* @0x1b70c4 str r11, [r0] */
/* @0x1b70c8 cmp r3, #0 */
/* @0x1b70cc ldr r2, [r5, #0x8] */
/* @0x1b70d0 strne r0, [r3, #0x18] */
/* @0x1b70d4 streq r0, [r5, #0x4] */
/* @0x1b70d8 add r2, r2, #1 */
/* @0x1b70dc streq r0, [r5] */
/* @0x1b70e0 streq r3, [r0, #0x18] */
/* @0x1b70e4 streq r3, [r0, #0x14] */
/* @0x1b70e8 strne r0, [r5] */
/* @0x1b70ec strne r3, [r0, #0x14] */
/* @0x1b70f0 strne r8, [r0, #0x18] */
/* @0x1b70f4 subs r4, r4, #1 */
/* @0x1b70f8 str r2, [r5, #0x8] */
/* @0x1b70fc bne 0x1b7088 <_ZN13CLayerManager4InitEv+0x188> */
/* @0x1b7100 ldr r3, [pc, #0x280] */
/* @0x1b7104 mov r2, #32 */
/* @0x1b7108 ldr r9, [pc, #0x27c] */
/* @0x1b710c mov r10, r4 */
/* @0x1b7110 str r2, [r5, #0x10] */
/* @0x1b7114 mov r8, #256 */
/* @0x1b7118 ldr r5, [r7, r3] */
/* @0x1b711c add r9, pc, r9 */
/* @0x1b7120 mvn r6, #0 */
/* @0x1b7124 mov r3, #3 */
/* @0x1b7128 str r4, [r5, #0x4] */
/* @0x1b712c str r4, [r5] */
/* @0x1b7130 str r4, [r5, #0x8] */
/* @0x1b7134 str r3, [r5, #0xc] */
/* @0x1b7138 mov r2, #45 */
/* @0x1b713c mov r3, #1 */
/* @0x1b7140 mov r0, #36 */
/* @0x1b7144 mov r1, r9 */
/* @0x1b7148 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1b714c ldr r3, [r5] */
/* @0x1b7150 mov r2, #2 */
/* @0x1b7154 cmp r0, #0 */
/* @0x1b7158 beq 0x1b7180 <_ZN13CLayerManager4InitEv+0x280> */
/* @0x1b715c strb r10, [r0, #0x8] */
/* @0x1b7160 str r10, [r0, #0xc] */
/* @0x1b7164 str r10, [r0, #0x10] */
/* @0x1b7168 str r10, [r0, #0x14] */
/* @0x1b716c str r10, [r0, #0x18] */
/* @0x1b7170 str r6, [r0, #0x4] */
/* @0x1b7174 str r6, [r0, #0x1c] */
/* @0x1b7178 str r10, [r0, #0x20] */
/* @0x1b717c str r2, [r0] */
/* @0x1b7180 cmp r3, #0 */
/* @0x1b7184 ldr r2, [r5, #0x8] */
/* @0x1b7188 strne r0, [r3, #0x18] */
/* @0x1b718c streq r0, [r5, #0x4] */
/* @0x1b7190 add r2, r2, #1 */
/* @0x1b7194 streq r0, [r5] */
/* @0x1b7198 streq r3, [r0, #0x18] */
/* @0x1b719c streq r3, [r0, #0x14] */
/* @0x1b71a0 strne r0, [r5] */
/* @0x1b71a4 strne r3, [r0, #0x14] */
/* @0x1b71a8 strne r10, [r0, #0x18] */
/* @0x1b71ac subs r8, r8, #1 */
/* @0x1b71b0 str r2, [r5, #0x8] */
/* @0x1b71b4 bne 0x1b7138 <_ZN13CLayerManager4InitEv+0x238> */
/* @0x1b71b8 ldr r3, [pc, #0x1d0] */
/* @0x1b71bc mov r2, #256 */
/* @0x1b71c0 ldr r6, [pc, #0x1cc] */
/* @0x1b71c4 mov r4, r8 */
/* @0x1b71c8 str r2, [r5, #0x10] */
/* @0x1b71cc mov r11, #32 */
/* @0x1b71d0 ldr r5, [r7, r3] */
/* @0x1b71d4 add r6, pc, r6 */
/* @0x1b71d8 mov r10, #1 */
/* @0x1b71dc mvn r9, #0 */
/* @0x1b71e0 mov r3, #3 */
/* @0x1b71e4 str r8, [r5, #0x4] */
/* @0x1b71e8 str r8, [r5] */
/* @0x1b71ec str r8, [r5, #0x8] */
/* @0x1b71f0 str r3, [r5, #0xc] */
/* @0x1b71f4 mov r2, #45 */
/* @0x1b71f8 mov r3, #1 */
/* @0x1b71fc mov r0, #52 */
/* @0x1b7200 mov r1, r6 */
/* @0x1b7204 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1b7208 ldr r3, [r5] */
/* @0x1b720c mov r2, #3 */
/* @0x1b7210 cmp r0, #0 */
/* @0x1b7214 beq 0x1b724c <_ZN13CLayerManager4InitEv+0x34c> */
/* @0x1b7218 strb r4, [r0, #0x8] */
/* @0x1b721c str r4, [r0, #0xc] */
/* @0x1b7220 str r4, [r0, #0x10] */
/* @0x1b7224 str r4, [r0, #0x14] */
/* @0x1b7228 str r4, [r0, #0x18] */
/* @0x1b722c str r9, [r0, #0x4] */
/* @0x1b7230 str r4, [r0, #0x1c] */
/* @0x1b7234 str r4, [r0, #0x20] */
/* @0x1b7238 str r4, [r0, #0x28] */
/* @0x1b723c str r4, [r0, #0x24] */
/* @0x1b7240 str r4, [r0, #0x2c] */
/* @0x1b7244 str r10, [r0, #0x30] */
/* @0x1b7248 str r2, [r0] */
/* @0x1b724c cmp r3, #0 */
/* @0x1b7250 ldr r2, [r5, #0x8] */
/* @0x1b7254 strne r0, [r3, #0x18] */
/* @0x1b7258 streq r0, [r5, #0x4] */
/* @0x1b725c add r2, r2, #1 */
/* @0x1b7260 streq r0, [r5] */
/* @0x1b7264 streq r3, [r0, #0x18] */
/* @0x1b7268 streq r3, [r0, #0x14] */
/* @0x1b726c strne r0, [r5] */
/* @0x1b7270 strne r3, [r0, #0x14] */
/* @0x1b7274 strne r4, [r0, #0x18] */
/* @0x1b7278 subs r11, r11, #1 */
/* @0x1b727c str r2, [r5, #0x8] */
/* @0x1b7280 bne 0x1b71f4 <_ZN13CLayerManager4InitEv+0x2f4> */
/* @0x1b7284 ldr r3, [pc, #0x10c] */
/* @0x1b7288 mov r2, #32 */
/* @0x1b728c ldr r9, [pc, #0x108] */
/* @0x1b7290 mov r4, r11 */
/* @0x1b7294 str r2, [r5, #0x10] */
/* @0x1b7298 mov r6, #64 */
/* @0x1b729c ldr r5, [r7, r3] */
/* @0x1b72a0 add r9, pc, r9 */
/* @0x1b72a4 mov r10, #0 */
/* @0x1b72a8 mov r3, #3 */
/* @0x1b72ac str r11, [r5, #0x4] */
/* @0x1b72b0 str r11, [r5] */
/* @0x1b72b4 str r11, [r5, #0x8] */
/* @0x1b72b8 str r3, [r5, #0xc] */
/* @0x1b72bc mov r1, r9 */
/* @0x1b72c0 mov r2, #45 */
/* @0x1b72c4 mov r0, #72 */
/* @0x1b72c8 mov r3, #1 */
/* @0x1b72cc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1b72d0 ldr r2, [r5] */
/* @0x1b72d4 mvn r1, #0 */
/* @0x1b72d8 mov r12, #4 */
/* @0x1b72dc cmp r0, #0 */
/* @0x1b72e0 beq 0x1b7330 <_ZN13CLayerManager4InitEv+0x430> */
/* @0x1b72e4 mov r3, #1065353216 */
/* @0x1b72e8 strb r4, [r0, #0x8] */
/* @0x1b72ec str r4, [r0, #0xc] */
/* @0x1b72f0 str r10, [r0, #0x20] */
/* @0x1b72f4 str r4, [r0, #0x10] */
/* @0x1b72f8 str r10, [r0, #0x34] */
/* @0x1b72fc str r4, [r0, #0x14] */
/* @0x1b7300 str r10, [r0, #0x40] */
/* @0x1b7304 str r4, [r0, #0x18] */
/* @0x1b7308 str r10, [r0, #0x44] */
/* @0x1b730c str r1, [r0, #0x4] */
/* @0x1b7310 str r1, [r0, #0x1c] */
/* @0x1b7314 str r4, [r0, #0x28] */
/* @0x1b7318 str r1, [r0, #0x38] */
/* @0x1b731c str r12, [r0] */
/* @0x1b7320 str r3, [r0, #0x24] */
/* @0x1b7324 str r3, [r0, #0x2c] */
/* @0x1b7328 str r3, [r0, #0x30] */
/* @0x1b732c str r3, [r0, #0x3c] */
/* @0x1b7330 cmp r2, #0 */
/* @0x1b7334 ldr r3, [r5, #0x8] */
/* @0x1b7338 strne r0, [r2, #0x18] */
/* @0x1b733c streq r0, [r5, #0x4] */
/* @0x1b7340 add r3, r3, #1 */
/* @0x1b7344 streq r0, [r5] */
/* @0x1b7348 streq r2, [r0, #0x18] */
/* @0x1b734c streq r2, [r0, #0x14] */
/* @0x1b7350 strne r0, [r5] */
/* @0x1b7354 strne r2, [r0, #0x14] */
/* @0x1b7358 strne r4, [r0, #0x18] */
/* @0x1b735c subs r6, r6, #1 */
/* @0x1b7360 str r3, [r5, #0x8] */
/* @0x1b7364 bne 0x1b72bc <_ZN13CLayerManager4InitEv+0x3bc> */
/* @0x1b7368 ldr r3, [pc, #0x30] */
/* @0x1b736c mov r2, #64 */
/* @0x1b7370 b 0x1b73c4 <_ZN13CLayerManager4InitEv+0x4c4> */
/* @0x1b7374 nop */
/* @0x1b7380 .word 0xffffec10 */
/* @0x1b7384 andseq r6, r9, r12, lsr #12 */
/* @0x1b7388 .word 0xffffec14 */
/* @0x1b738c andseq r6, r9, r8, ror r5 */
/* @0x1b7390 .word 0xffffec18 */
/* @0x1b7394 andseq r6, r9, r0, asr #9 */
/* @0x1b7398 .word 0xffffec1c */
/* @0x1b739c ldrsheq r6, [r9], -r4 */
/* @0x1b73a0 .word 0xffffec20 */
/* @0x1b73a4 ldrheq r6, [r9], -r12 */
/* @0x1b73a8 .word 0xffffec24 */
/* @0x1b73ac andseq r6, r9, r4, ror #3 */
/* @0x1b73b0 .word 0xffffec28 */
/* @0x1b73b4 andseq r6, r9, r0, lsr r1 */
/* @0x1b73b8 .word 0xffffec2c */
/* @0x1b73bc andseq r6, r9, r8, asr #32 */
/* @0x1b73c0 .word 0xffffc020 */
/* @0x1b73c4 ldr r9, [pc, #-0x28] */
/* @0x1b73c8 mov r4, r6 */
/* @0x1b73cc str r2, [r5, #0x10] */
/* @0x1b73d0 mov r10, #32 */
/* @0x1b73d4 ldr r5, [r7, r3] */
/* @0x1b73d8 add r9, pc, r9 */
/* @0x1b73dc mov r11, #0 */
/* @0x1b73e0 mov r3, #3 */
/* @0x1b73e4 str r6, [r5, #0x4] */
/* @0x1b73e8 str r6, [r5] */
/* @0x1b73ec str r6, [r5, #0x8] */
/* @0x1b73f0 str r3, [r5, #0xc] */
/* @0x1b73f4 mov r1, r9 */
/* @0x1b73f8 mov r2, #45 */
/* @0x1b73fc mov r3, #1 */
/* @0x1b7400 mov r0, #60 */
/* @0x1b7404 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1b7408 ldr r3, [r5] */
/* @0x1b740c mvn r2, #0 */
/* @0x1b7410 mvn r12, #-2147483648 */
/* @0x1b7414 mov r1, #5 */
/* @0x1b7418 cmp r0, #0 */
/* @0x1b741c beq 0x1b745c <_ZN13CLayerManager4InitEv+0x55c> */
/* @0x1b7420 strb r4, [r0, #0x8] */
/* @0x1b7424 str r11, [r0, #0x20] */
/* @0x1b7428 str r4, [r0, #0xc] */
/* @0x1b742c str r11, [r0, #0x24] */
/* @0x1b7430 str r4, [r0, #0x10] */
/* @0x1b7434 str r11, [r0, #0x30] */
/* @0x1b7438 str r4, [r0, #0x14] */
/* @0x1b743c str r4, [r0, #0x18] */
/* @0x1b7440 str r2, [r0, #0x4] */
/* @0x1b7444 str r2, [r0, #0x1c] */
/* @0x1b7448 str r4, [r0, #0x28] */
/* @0x1b744c str r4, [r0, #0x2c] */
/* @0x1b7450 str r4, [r0, #0x34] */
/* @0x1b7454 str r12, [r0, #0x38] */
/* @0x1b7458 str r1, [r0] */
/* @0x1b745c cmp r3, #0 */
/* @0x1b7460 ldr r2, [r5, #0x8] */
/* @0x1b7464 strne r0, [r3, #0x18] */
/* @0x1b7468 streq r0, [r5, #0x4] */
/* @0x1b746c add r2, r2, #1 */
/* @0x1b7470 streq r0, [r5] */
/* @0x1b7474 streq r3, [r0, #0x18] */
/* @0x1b7478 streq r3, [r0, #0x14] */
/* @0x1b747c strne r0, [r5] */
/* @0x1b7480 strne r3, [r0, #0x14] */
/* @0x1b7484 strne r4, [r0, #0x18] */
/* @0x1b7488 subs r10, r10, #1 */
/* @0x1b748c str r2, [r5, #0x8] */
/* @0x1b7490 bne 0x1b73f4 <_ZN13CLayerManager4InitEv+0x4f4> */
/* @0x1b7494 ldr r2, [pc, #-0xf4] */
/* @0x1b7498 mov r3, #32 */
/* @0x1b749c ldr r4, [pc, #-0xf8] */
/* @0x1b74a0 mov r11, r10 */
/* @0x1b74a4 str r3, [r5, #0x10] */
/* @0x1b74a8 mvn r9, #0 */
/* @0x1b74ac ldr r5, [r7, r2] */
/* @0x1b74b0 add r4, pc, r4 */
/* @0x1b74b4 mov r6, r3 */
/* @0x1b74b8 mov r3, #3 */
/* @0x1b74bc str r10, [r5, #0x4] */
/* @0x1b74c0 str r10, [r5] */
/* @0x1b74c4 str r10, [r5, #0x8] */
/* @0x1b74c8 str r3, [r5, #0xc] */
/* @0x1b74cc mov r2, #45 */
/* @0x1b74d0 mov r3, #1 */
/* @0x1b74d4 mov r0, #32 */
/* @0x1b74d8 mov r1, r4 */
/* @0x1b74dc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1b74e0 ldr r3, [r5] */
/* @0x1b74e4 mov r2, #6 */
/* @0x1b74e8 cmp r0, #0 */
/* @0x1b74ec beq 0x1b7510 <_ZN13CLayerManager4InitEv+0x610> */
/* @0x1b74f0 strb r11, [r0, #0x8] */
/* @0x1b74f4 str r11, [r0, #0xc] */
/* @0x1b74f8 str r11, [r0, #0x10] */
/* @0x1b74fc str r11, [r0, #0x14] */
/* @0x1b7500 str r11, [r0, #0x18] */
/* @0x1b7504 str r9, [r0, #0x4] */
/* @0x1b7508 str r9, [r0, #0x1c] */
/* @0x1b750c str r2, [r0] */
/* @0x1b7510 cmp r3, #0 */
/* @0x1b7514 ldr r2, [r5, #0x8] */
/* @0x1b7518 strne r0, [r3, #0x18] */
/* @0x1b751c streq r0, [r5, #0x4] */
/* @0x1b7520 add r2, r2, #1 */
/* @0x1b7524 streq r0, [r5] */
/* @0x1b7528 streq r3, [r0, #0x18] */
/* @0x1b752c streq r3, [r0, #0x14] */
/* @0x1b7530 strne r0, [r5] */
/* @0x1b7534 strne r3, [r0, #0x14] */
/* @0x1b7538 strne r11, [r0, #0x18] */
/* @0x1b753c subs r6, r6, #1 */
/* @0x1b7540 str r2, [r5, #0x8] */
/* @0x1b7544 bne 0x1b74cc <_ZN13CLayerManager4InitEv+0x5cc> */
/* @0x1b7548 ldr r3, [pc, #-0x1a0] */
/* @0x1b754c mov r2, #32 */
/* @0x1b7550 ldr r9, [pc, #-0x1a4] */
/* @0x1b7554 mov r4, r6 */
/* @0x1b7558 str r2, [r5, #0x10] */
/* @0x1b755c mov r10, #1024 */
/* @0x1b7560 ldr r5, [r7, r3] */
/* @0x1b7564 add r9, pc, r9 */
/* @0x1b7568 mov r11, #0 */
/* @0x1b756c mov r3, #3 */
/* @0x1b7570 str r6, [r5, #0x4] */
/* @0x1b7574 str r6, [r5] */
/* @0x1b7578 str r6, [r5, #0x8] */
/* @0x1b757c str r3, [r5, #0xc] */
/* @0x1b7580 mov r2, #45 */
/* @0x1b7584 mov r3, #1 */
/* @0x1b7588 mov r0, #80 */
/* @0x1b758c mov r1, r9 */
/* @0x1b7590 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1b7594 ldr r3, [r5] */
/* @0x1b7598 mvn r2, #0 */
/* @0x1b759c mov r12, #7 */
/* @0x1b75a0 cmp r0, #0 */
/* @0x1b75a4 beq 0x1b75f8 <_ZN13CLayerManager4InitEv+0x6f8> */
/* @0x1b75a8 mov r1, #1065353216 */
/* @0x1b75ac strb r4, [r0, #0x8] */
/* @0x1b75b0 str r4, [r0, #0xc] */
/* @0x1b75b4 str r11, [r0, #0x24] */
/* @0x1b75b8 str r4, [r0, #0x10] */
/* @0x1b75bc str r11, [r0, #0x28] */
/* @0x1b75c0 str r4, [r0, #0x14] */
/* @0x1b75c4 str r11, [r0, #0x3c] */
/* @0x1b75c8 str r4, [r0, #0x18] */
/* @0x1b75cc str r2, [r0, #0x4] */
/* @0x1b75d0 str r2, [r0, #0x20] */
/* @0x1b75d4 str r4, [r0, #0x2c] */
/* @0x1b75d8 str r4, [r0, #0x30] */
/* @0x1b75dc str r2, [r0, #0x40] */
/* @0x1b75e0 str r4, [r0, #0x48] */
/* @0x1b75e4 str r1, [r0, #0x34] */
/* @0x1b75e8 str r4, [r0, #0x4c] */
/* @0x1b75ec str r1, [r0, #0x38] */
/* @0x1b75f0 str r12, [r0] */
/* @0x1b75f4 str r1, [r0, #0x44] */
/* @0x1b75f8 cmp r3, #0 */
/* @0x1b75fc ldr r2, [r5, #0x8] */
/* @0x1b7600 strne r0, [r3, #0x18] */
/* @0x1b7604 streq r0, [r5, #0x4] */
/* @0x1b7608 add r2, r2, #1 */
/* @0x1b760c streq r0, [r5] */
/* @0x1b7610 streq r3, [r0, #0x18] */
/* @0x1b7614 streq r3, [r0, #0x14] */
/* @0x1b7618 strne r0, [r5] */
/* @0x1b761c strne r3, [r0, #0x14] */
/* @0x1b7620 strne r4, [r0, #0x18] */
/* @0x1b7624 subs r10, r10, #1 */
/* @0x1b7628 str r2, [r5, #0x8] */
/* @0x1b762c bne 0x1b7580 <_ZN13CLayerManager4InitEv+0x680> */
/* @0x1b7630 ldr r3, [pc, #-0x280] */
/* @0x1b7634 mov r2, #1024 */
/* @0x1b7638 ldr r6, [pc, #-0x284] */
/* @0x1b763c mov r9, r10 */
/* @0x1b7640 str r2, [r5, #0x10] */
/* @0x1b7644 mov r5, #32 */
/* @0x1b7648 ldr r4, [r7, r3] */
/* @0x1b764c add r6, pc, r6 */
/* @0x1b7650 mov r3, #3 */
/* @0x1b7654 str r10, [r4, #0x4] */
/* @0x1b7658 str r10, [r4] */
/* @0x1b765c str r10, [r4, #0x8] */
/* @0x1b7660 str r3, [r4, #0xc] */
/* @0x1b7664 mov r2, #45 */
/* @0x1b7668 mov r3, #1 */
/* @0x1b766c movw r0, #0x70c */
/* @0x1b7670 mov r1, r6 */
/* @0x1b7674 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1b7678 ldr r3, [r4] */
/* @0x1b767c ldr r2, [r4, #0x8] */
/* @0x1b7680 add r2, r2, #1 */
/* @0x1b7684 str r2, [r4, #0x8] */
/* @0x1b7688 cmp r0, #0 */
/* @0x1b768c strne r9, [r0, #0x704] */
/* @0x1b7690 strne r9, [r0, #0x708] */
/* @0x1b7694 strne r9, [r0, #0x700] */
/* @0x1b7698 cmp r3, #0 */
/* @0x1b769c strne r0, [r3, #0x708] */
/* @0x1b76a0 streq r0, [r4, #0x4] */
/* @0x1b76a4 streq r0, [r4] */
/* @0x1b76a8 streq r3, [r0, #0x708] */
/* @0x1b76ac streq r3, [r0, #0x704] */
/* @0x1b76b0 strne r0, [r4] */
/* @0x1b76b4 strne r3, [r0, #0x704] */
/* @0x1b76b8 strne r9, [r0, #0x708] */
/* @0x1b76bc subs r5, r5, #1 */
/* @0x1b76c0 bne 0x1b7664 <_ZN13CLayerManager4InitEv+0x764> */
/* @0x1b76c4 ldr r3, [pc, #-0x30c] */
/* @0x1b76c8 mov r2, #32 */
/* @0x1b76cc str r2, [r4, #0x10] */
/* @0x1b76d0 ldr r4, [r7, r3] */
/* @0x1b76d4 ldr r0, [r4] */
/* @0x1b76d8 cmp r0, #0 */
/* @0x1b76dc beq 0x1b76f0 <_ZN13CLayerManager4InitEv+0x7f0> */
/* @0x1b76e0 ldr r3, [r0] */
/* @0x1b76e4 ldr r3, [r3, #0x4] */
/* @0x1b76e8 blx r3 */
/* @0x1b76ec str r5, [r4] */
/* @0x1b76f0 ldr r2, [sp, #0x4] */
/* @0x1b76f4 mov r3, #1 */
/* @0x1b76f8 strb r3, [r2] */
/* @0x1b76fc b 0x1b6f2c <_ZN13CLayerManager4InitEv+0x2c> */

/* ── FUNC 0x1b7700 · CLayerManager::Close() · size=752 · insn=188 */
/* @0x1b7700 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1b7704 ldr r6, [pc, #0x2bc] */
/* @0x1b7708 ldr r3, [pc, #0x2bc] */
/* @0x1b770c add r6, pc, r6 */
/* @0x1b7710 ldr r7, [r6, r3] */
/* @0x1b7714 ldrb r3, [r7] */
/* @0x1b7718 cmp r3, #0 */
/* @0x1b771c popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1b7720 ldr r3, [pc, #0x2a8] */
/* @0x1b7724 ldr r3, [r6, r3] */
/* @0x1b7728 ldr r5, [r3] */
/* @0x1b772c cmp r5, #0 */
/* @0x1b7730 movne r8, #0 */
/* @0x1b7734 beq 0x1b7804 <_ZN13CLayerManager5CloseEv+0x104> */
/* @0x1b7738 ldr r0, [r5, #0x1c] */
/* @0x1b773c ldr r9, [r5, #0x68] */
/* @0x1b7740 bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0x1b7744 cmp r0, #0 */
/* @0x1b7748 bne 0x1b7754 <_ZN13CLayerManager5CloseEv+0x54> */
/* @0x1b774c ldr r0, [r5, #0x1c] */
/* @0x1b7750 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b7754 ldr r3, [r5, #0x64] */
/* @0x1b7758 str r8, [r5, #0x1c] */
/* @0x1b775c cmp r3, #0 */
/* @0x1b7760 beq 0x1b7798 <_ZN13CLayerManager5CloseEv+0x98> */
/* @0x1b7764 ldr r0, [r5, #0x58] */
/* @0x1b7768 cmp r0, #0 */
/* @0x1b776c beq 0x1b7798 <_ZN13CLayerManager5CloseEv+0x98> */
/* @0x1b7770 cmp r3, #2 */
/* @0x1b7774 beq 0x1b77bc <_ZN13CLayerManager5CloseEv+0xbc> */
/* @0x1b7778 cmp r3, #3 */
/* @0x1b777c beq 0x1b77d4 <_ZN13CLayerManager5CloseEv+0xd4> */
/* @0x1b7780 cmp r3, #1 */
/* @0x1b7784 beq 0x1b77ec <_ZN13CLayerManager5CloseEv+0xec> */
/* @0x1b7788 ldr r4, [r0, #0x14] */
/* @0x1b778c cmp r4, #0 */
/* @0x1b7790 mov r0, r4 */
/* @0x1b7794 bne 0x1b7788 <_ZN13CLayerManager5CloseEv+0x88> */
/* @0x1b7798 str r8, [r5, #0x60] */
/* @0x1b779c mov r0, r5 */
/* @0x1b77a0 str r8, [r5, #0x5c] */
/* @0x1b77a4 str r8, [r5, #0x58] */
/* @0x1b77a8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b77ac cmp r9, #0 */
/* @0x1b77b0 beq 0x1b7804 <_ZN13CLayerManager5CloseEv+0x104> */
/* @0x1b77b4 mov r5, r9 */
/* @0x1b77b8 b 0x1b7738 <_ZN13CLayerManager5CloseEv+0x38> */
/* @0x1b77bc ldr r4, [r0, #0x14] */
/* @0x1b77c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b77c4 cmp r4, #0 */
/* @0x1b77c8 mov r0, r4 */
/* @0x1b77cc bne 0x1b77bc <_ZN13CLayerManager5CloseEv+0xbc> */
/* @0x1b77d0 b 0x1b7798 <_ZN13CLayerManager5CloseEv+0x98> */
/* @0x1b77d4 ldr r4, [r0, #0x14] */
/* @0x1b77d8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b77dc cmp r4, #0 */
/* @0x1b77e0 mov r0, r4 */
/* @0x1b77e4 bne 0x1b77d4 <_ZN13CLayerManager5CloseEv+0xd4> */
/* @0x1b77e8 b 0x1b7798 <_ZN13CLayerManager5CloseEv+0x98> */
/* @0x1b77ec ldr r4, [r0, #0x14] */
/* @0x1b77f0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b77f4 cmp r4, #0 */
/* @0x1b77f8 mov r0, r4 */
/* @0x1b77fc bne 0x1b77ec <_ZN13CLayerManager5CloseEv+0xec> */
/* @0x1b7800 b 0x1b7798 <_ZN13CLayerManager5CloseEv+0x98> */
/* @0x1b7804 ldr r3, [pc, #0x1c8] */
/* @0x1b7808 ldr r3, [r6, r3] */
/* @0x1b780c ldr r0, [r3] */
/* @0x1b7810 cmp r0, #0 */
/* @0x1b7814 beq 0x1b782c <_ZN13CLayerManager5CloseEv+0x12c> */
/* @0x1b7818 ldr r4, [r0, #0x14] */
/* @0x1b781c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b7820 cmp r4, #0 */
/* @0x1b7824 mov r0, r4 */
/* @0x1b7828 bne 0x1b7818 <_ZN13CLayerManager5CloseEv+0x118> */
/* @0x1b782c ldr r3, [pc, #0x1a4] */
/* @0x1b7830 ldr r3, [r6, r3] */
/* @0x1b7834 ldr r0, [r3] */
/* @0x1b7838 cmp r0, #0 */
/* @0x1b783c beq 0x1b7854 <_ZN13CLayerManager5CloseEv+0x154> */
/* @0x1b7840 ldr r4, [r0, #0x14] */
/* @0x1b7844 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b7848 cmp r4, #0 */
/* @0x1b784c mov r0, r4 */
/* @0x1b7850 bne 0x1b7840 <_ZN13CLayerManager5CloseEv+0x140> */
/* @0x1b7854 ldr r3, [pc, #0x180] */
/* @0x1b7858 ldr r3, [r6, r3] */
/* @0x1b785c ldr r5, [r3] */
/* @0x1b7860 cmp r5, #0 */
/* @0x1b7864 movne r8, #0 */
/* @0x1b7868 beq 0x1b791c <_ZN13CLayerManager5CloseEv+0x21c> */
/* @0x1b786c ldr r3, [r5, #0x30] */
/* @0x1b7870 ldr r9, [r5, #0x14] */
/* @0x1b7874 cmp r3, #0 */
/* @0x1b7878 beq 0x1b78b0 <_ZN13CLayerManager5CloseEv+0x1b0> */
/* @0x1b787c ldr r0, [r5, #0x24] */
/* @0x1b7880 cmp r0, #0 */
/* @0x1b7884 beq 0x1b78b0 <_ZN13CLayerManager5CloseEv+0x1b0> */
/* @0x1b7888 cmp r3, #2 */
/* @0x1b788c beq 0x1b78d4 <_ZN13CLayerManager5CloseEv+0x1d4> */
/* @0x1b7890 cmp r3, #3 */
/* @0x1b7894 beq 0x1b78ec <_ZN13CLayerManager5CloseEv+0x1ec> */
/* @0x1b7898 cmp r3, #1 */
/* @0x1b789c beq 0x1b7904 <_ZN13CLayerManager5CloseEv+0x204> */
/* @0x1b78a0 ldr r4, [r0, #0x704] */
/* @0x1b78a4 cmp r4, #0 */
/* @0x1b78a8 mov r0, r4 */
/* @0x1b78ac bne 0x1b78a0 <_ZN13CLayerManager5CloseEv+0x1a0> */
/* @0x1b78b0 str r8, [r5, #0x2c] */
/* @0x1b78b4 mov r0, r5 */
/* @0x1b78b8 str r8, [r5, #0x28] */
/* @0x1b78bc str r8, [r5, #0x24] */
/* @0x1b78c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b78c4 cmp r9, #0 */
/* @0x1b78c8 beq 0x1b791c <_ZN13CLayerManager5CloseEv+0x21c> */
/* @0x1b78cc mov r5, r9 */
/* @0x1b78d0 b 0x1b786c <_ZN13CLayerManager5CloseEv+0x16c> */
/* @0x1b78d4 ldr r4, [r0, #0x704] */
/* @0x1b78d8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b78dc cmp r4, #0 */
/* @0x1b78e0 mov r0, r4 */
/* @0x1b78e4 bne 0x1b78d4 <_ZN13CLayerManager5CloseEv+0x1d4> */
/* @0x1b78e8 b 0x1b78b0 <_ZN13CLayerManager5CloseEv+0x1b0> */
/* @0x1b78ec ldr r4, [r0, #0x704] */
/* @0x1b78f0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b78f4 cmp r4, #0 */
/* @0x1b78f8 mov r0, r4 */
/* @0x1b78fc bne 0x1b78ec <_ZN13CLayerManager5CloseEv+0x1ec> */
/* @0x1b7900 b 0x1b78b0 <_ZN13CLayerManager5CloseEv+0x1b0> */
/* @0x1b7904 ldr r4, [r0, #0x704] */
/* @0x1b7908 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b790c cmp r4, #0 */
/* @0x1b7910 mov r0, r4 */
/* @0x1b7914 bne 0x1b7904 <_ZN13CLayerManager5CloseEv+0x204> */
/* @0x1b7918 b 0x1b78b0 <_ZN13CLayerManager5CloseEv+0x1b0> */
/* @0x1b791c ldr r3, [pc, #0xbc] */
/* @0x1b7920 ldr r3, [r6, r3] */
/* @0x1b7924 ldr r0, [r3] */
/* @0x1b7928 cmp r0, #0 */
/* @0x1b792c beq 0x1b7944 <_ZN13CLayerManager5CloseEv+0x244> */
/* @0x1b7930 ldr r4, [r0, #0x14] */
/* @0x1b7934 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b7938 cmp r4, #0 */
/* @0x1b793c mov r0, r4 */
/* @0x1b7940 bne 0x1b7930 <_ZN13CLayerManager5CloseEv+0x230> */
/* @0x1b7944 ldr r3, [pc, #0x98] */
/* @0x1b7948 ldr r3, [r6, r3] */
/* @0x1b794c ldr r0, [r3] */
/* @0x1b7950 cmp r0, #0 */
/* @0x1b7954 beq 0x1b796c <_ZN13CLayerManager5CloseEv+0x26c> */
/* @0x1b7958 ldr r4, [r0, #0x14] */
/* @0x1b795c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b7960 cmp r4, #0 */
/* @0x1b7964 mov r0, r4 */
/* @0x1b7968 bne 0x1b7958 <_ZN13CLayerManager5CloseEv+0x258> */
/* @0x1b796c ldr r3, [pc, #0x74] */
/* @0x1b7970 ldr r3, [r6, r3] */
/* @0x1b7974 ldr r0, [r3] */
/* @0x1b7978 cmp r0, #0 */
/* @0x1b797c beq 0x1b7994 <_ZN13CLayerManager5CloseEv+0x294> */
/* @0x1b7980 ldr r4, [r0, #0x704] */
/* @0x1b7984 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b7988 cmp r4, #0 */
/* @0x1b798c mov r0, r4 */
/* @0x1b7990 bne 0x1b7980 <_ZN13CLayerManager5CloseEv+0x280> */
/* @0x1b7994 ldr r3, [pc, #0x50] */
/* @0x1b7998 ldr r4, [r6, r3] */
/* @0x1b799c ldr r0, [r4] */
/* @0x1b79a0 cmp r0, #0 */
/* @0x1b79a4 beq 0x1b79bc <_ZN13CLayerManager5CloseEv+0x2bc> */
/* @0x1b79a8 ldr r3, [r0] */
/* @0x1b79ac ldr r3, [r3, #0x4] */
/* @0x1b79b0 blx r3 */
/* @0x1b79b4 mov r3, #0 */
/* @0x1b79b8 str r3, [r4] */
/* @0x1b79bc mov r3, #0 */
/* @0x1b79c0 strb r3, [r7] */
/* @0x1b79c4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1b79c8 eoreq r10, r3, r4, asr #10 */
/* @0x1b79cc .word 0xffffec08 */
/* @0x1b79d0 .word 0xffffec0c */
/* @0x1b79d4 .word 0xffffec10 */
/* @0x1b79d8 .word 0xffffec14 */
/* @0x1b79dc .word 0xffffec18 */
/* @0x1b79e0 .word 0xffffec1c */
/* @0x1b79e4 .word 0xffffec20 */
/* @0x1b79e8 .word 0xffffec2c */
/* @0x1b79ec .word 0xffffc020 */

/* ── FUNC 0x1b79f0 · CLayerManager::SetLayerIndexWatermark(int) · size=20 · insn=5 */
/* @0x1b79f0 ldr r3, [pc, #0x8] */
/* @0x1b79f4 ldr r3, [pc, r3] */
/* @0x1b79f8 str r0, [r3] */
/* @0x1b79fc bx lr */
/* @0x1b7a00 eoreq r8, r3, r12, lsl #29 */

/* ── FUNC 0x1b7a04 · CLayerManager::RemoveBackgroundElement(CLayer*, CLayerBackgroundElement*) · size=192 · insn=48 */
/* @0x1b7a04 push {r4, r5, r6, lr} */
/* @0x1b7a08 mov r5, r0 */
/* @0x1b7a0c ldr r0, [r1, #0x1c] */
/* @0x1b7a10 mov r4, r1 */
/* @0x1b7a14 cmp r0, #0 */
/* @0x1b7a18 beq 0x1b7a28 <_ZN13CLayerManager23RemoveBackgroundElementEP6CLayerP23CLayerBackgroundElement+0x24> */
/* @0x1b7a1c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b7a20 mov r3, #0 */
/* @0x1b7a24 str r3, [r4, #0x1c] */
/* @0x1b7a28 ldr r3, [r4, #0x18] */
/* @0x1b7a2c mvn r6, #0 */
/* @0x1b7a30 ldr r2, [r4, #0x14] */
/* @0x1b7a34 mov r12, #1 */
/* @0x1b7a38 cmp r3, #0 */
/* @0x1b7a3c ldr r1, [r5, #0x60] */
/* @0x1b7a40 strne r2, [r3, #0x14] */
/* @0x1b7a44 add r1, r1, r6 */
/* @0x1b7a48 ldrne r2, [r4, #0x14] */
/* @0x1b7a4c ldrne r3, [r4, #0x18] */
/* @0x1b7a50 streq r2, [r5, #0x58] */
/* @0x1b7a54 cmp r2, #0 */
/* @0x1b7a58 streq r3, [r5, #0x5c] */
/* @0x1b7a5c strne r3, [r2, #0x18] */
/* @0x1b7a60 mov r3, #0 */
/* @0x1b7a64 ldr r2, [pc, #0x54] */
/* @0x1b7a68 str r1, [r5, #0x60] */
/* @0x1b7a6c ldr r2, [pc, r2] */
/* @0x1b7a70 str r3, [r4, #0x14] */
/* @0x1b7a74 str r3, [r4, #0x18] */
/* @0x1b7a78 ldr r1, [r2] */
/* @0x1b7a7c ldr r0, [r2, #0x8] */
/* @0x1b7a80 cmp r1, r3 */
/* @0x1b7a84 str r12, [r4] */
/* @0x1b7a88 str r6, [r4, #0x4] */
/* @0x1b7a8c add r0, r0, r12 */
/* @0x1b7a90 strb r3, [r4, #0x8] */
/* @0x1b7a94 str r3, [r4, #0xc] */
/* @0x1b7a98 str r3, [r4, #0x10] */
/* @0x1b7a9c str r3, [r4, #0x1c] */
/* @0x1b7aa0 str r0, [r2, #0x8] */
/* @0x1b7aa4 strne r4, [r1, #0x18] */
/* @0x1b7aa8 streq r4, [r2, #0x4] */
/* @0x1b7aac streq r4, [r2] */
/* @0x1b7ab0 strne r4, [r2] */
/* @0x1b7ab4 strne r1, [r4, #0x14] */
/* @0x1b7ab8 strne r3, [r4, #0x18] */
/* @0x1b7abc pop {r4, r5, r6, pc} */
/* @0x1b7ac0 .word 0x00238df4 */

/* ── FUNC 0x1b7ac4 · CLayerManager::RemoveInstanceElement(CLayer*, CLayerInstanceElement*, bool) · size=232 · insn=58 */
/* @0x1b7ac4 ldr r3, [r1, #0x20] */
/* @0x1b7ac8 push {r4, r5, r6, lr} */
/* @0x1b7acc cmp r3, #0 */
/* @0x1b7ad0 mov r4, r1 */
/* @0x1b7ad4 mov r5, r0 */
/* @0x1b7ad8 mvnne r1, #0 */
/* @0x1b7adc movne r0, #0 */
/* @0x1b7ae0 strne r1, [r3, #0x170] */
/* @0x1b7ae4 strbne r0, [r3, #0x174] */
/* @0x1b7ae8 cmp r2, #0 */
/* @0x1b7aec beq 0x1b7b0c <_ZN13CLayerManager21RemoveInstanceElementEP6CLayerP21CLayerInstanceElementb+0x48> */
/* @0x1b7af0 ldr r2, [r4, #0x1c] */
/* @0x1b7af4 cmn r2, #14 */
/* @0x1b7af8 beq 0x1b7b0c <_ZN13CLayerManager21RemoveInstanceElementEP6CLayerP21CLayerInstanceElementb+0x48> */
/* @0x1b7afc mov r0, #0 */
/* @0x1b7b00 mov r3, #1 */
/* @0x1b7b04 mov r1, r0 */
/* @0x1b7b08 bl 0x10b12c <_Z17DoInstanceDestroyP9CInstanceS0_ib> */
/* @0x1b7b0c ldr r3, [r4, #0x18] */
/* @0x1b7b10 mvn r0, #0 */
/* @0x1b7b14 ldr r2, [r4, #0x14] */
/* @0x1b7b18 mov r6, #2 */
/* @0x1b7b1c cmp r3, #0 */
/* @0x1b7b20 ldr r1, [r5, #0x60] */
/* @0x1b7b24 strne r2, [r3, #0x14] */
/* @0x1b7b28 add r1, r1, r0 */
/* @0x1b7b2c ldrne r2, [r4, #0x14] */
/* @0x1b7b30 ldrne r3, [r4, #0x18] */
/* @0x1b7b34 streq r2, [r5, #0x58] */
/* @0x1b7b38 cmp r2, #0 */
/* @0x1b7b3c streq r3, [r5, #0x5c] */
/* @0x1b7b40 strne r3, [r2, #0x18] */
/* @0x1b7b44 mov r3, #0 */
/* @0x1b7b48 ldr r2, [pc, #0x58] */
/* @0x1b7b4c str r1, [r5, #0x60] */
/* @0x1b7b50 ldr r2, [pc, r2] */
/* @0x1b7b54 str r3, [r4, #0x14] */
/* @0x1b7b58 str r3, [r4, #0x18] */
/* @0x1b7b5c ldr r1, [r2] */
/* @0x1b7b60 ldr r12, [r2, #0x8] */
/* @0x1b7b64 cmp r1, r3 */
/* @0x1b7b68 str r6, [r4] */
/* @0x1b7b6c str r0, [r4, #0x4] */
/* @0x1b7b70 add r12, r12, #1 */
/* @0x1b7b74 strb r3, [r4, #0x8] */
/* @0x1b7b78 str r3, [r4, #0xc] */
/* @0x1b7b7c str r3, [r4, #0x10] */
/* @0x1b7b80 str r3, [r4, #0x20] */
/* @0x1b7b84 str r0, [r4, #0x1c] */
/* @0x1b7b88 str r12, [r2, #0x8] */
/* @0x1b7b8c strne r4, [r1, #0x18] */
/* @0x1b7b90 streq r4, [r2, #0x4] */
/* @0x1b7b94 streq r4, [r2] */
/* @0x1b7b98 strne r4, [r2] */
/* @0x1b7b9c strne r1, [r4, #0x14] */
/* @0x1b7ba0 strne r3, [r4, #0x18] */
/* @0x1b7ba4 pop {r4, r5, r6, pc} */
/* @0x1b7ba8 eoreq r8, r3, r4, lsl sp */

/* ── FUNC 0x1b7bac · CLayerManager::RemoveOldTilemapElement(CLayer*, CLayerOldTilemapElement*) · size=332 · insn=83 */
/* @0x1b7bac push {r4, r5, r6, lr} */
/* @0x1b7bb0 mov r4, r1 */
/* @0x1b7bb4 mov r5, r0 */
/* @0x1b7bb8 ldr r0, [r1, #0x1c] */
/* @0x1b7bbc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b7bc0 ldr r3, [r4, #0x18] */
/* @0x1b7bc4 ldr r2, [r4, #0x14] */
/* @0x1b7bc8 cmp r3, #0 */
/* @0x1b7bcc strne r2, [r3, #0x14] */
/* @0x1b7bd0 ldrne r2, [r4, #0x14] */
/* @0x1b7bd4 ldrne r3, [r4, #0x18] */
/* @0x1b7bd8 streq r2, [r5, #0x58] */
/* @0x1b7bdc cmp r2, #0 */
/* @0x1b7be0 streq r3, [r5, #0x5c] */
/* @0x1b7be4 strne r3, [r2, #0x18] */
/* @0x1b7be8 ldr r3, [r4, #0x30] */
/* @0x1b7bec ldr r2, [r5, #0x60] */
/* @0x1b7bf0 cmp r3, #0 */
/* @0x1b7bf4 sub r2, r2, #1 */
/* @0x1b7bf8 str r2, [r5, #0x60] */
/* @0x1b7bfc beq 0x1b7c34 <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x88> */
/* @0x1b7c00 ldr r0, [r4, #0x24] */
/* @0x1b7c04 cmp r0, #0 */
/* @0x1b7c08 beq 0x1b7c34 <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x88> */
/* @0x1b7c0c cmp r3, #2 */
/* @0x1b7c10 beq 0x1b7cac <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x100> */
/* @0x1b7c14 cmp r3, #3 */
/* @0x1b7c18 beq 0x1b7cc4 <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x118> */
/* @0x1b7c1c cmp r3, #1 */
/* @0x1b7c20 beq 0x1b7cdc <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x130> */
/* @0x1b7c24 ldr r5, [r0, #0x704] */
/* @0x1b7c28 cmp r5, #0 */
/* @0x1b7c2c mov r0, r5 */
/* @0x1b7c30 bne 0x1b7c24 <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x78> */
/* @0x1b7c34 ldr r2, [pc, #0xb8] */
/* @0x1b7c38 mov r3, #0 */
/* @0x1b7c3c mov r12, #1 */
/* @0x1b7c40 strb r3, [r4, #0x8] */
/* @0x1b7c44 ldr r2, [pc, r2] */
/* @0x1b7c48 str r3, [r4, #0x14] */
/* @0x1b7c4c str r3, [r4, #0x18] */
/* @0x1b7c50 mvn r6, #0 */
/* @0x1b7c54 ldr r1, [r2] */
/* @0x1b7c58 mov r5, #3 */
/* @0x1b7c5c ldr r0, [r2, #0x8] */
/* @0x1b7c60 cmp r1, r3 */
/* @0x1b7c64 stm r4, {r5, r6} */
/* @0x1b7c68 str r3, [r4, #0x2c] */
/* @0x1b7c6c add r0, r0, r12 */
/* @0x1b7c70 str r3, [r4, #0x28] */
/* @0x1b7c74 str r3, [r4, #0x24] */
/* @0x1b7c78 str r3, [r4, #0xc] */
/* @0x1b7c7c str r3, [r4, #0x10] */
/* @0x1b7c80 str r3, [r4, #0x1c] */
/* @0x1b7c84 str r3, [r4, #0x20] */
/* @0x1b7c88 str r12, [r4, #0x30] */
/* @0x1b7c8c str r0, [r2, #0x8] */
/* @0x1b7c90 strne r4, [r1, #0x18] */
/* @0x1b7c94 strne r4, [r2] */
/* @0x1b7c98 strne r1, [r4, #0x14] */
/* @0x1b7c9c strne r3, [r4, #0x18] */
/* @0x1b7ca0 streq r4, [r2, #0x4] */
/* @0x1b7ca4 streq r4, [r2] */
/* @0x1b7ca8 pop {r4, r5, r6, pc} */
/* @0x1b7cac ldr r5, [r0, #0x704] */
/* @0x1b7cb0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b7cb4 cmp r5, #0 */
/* @0x1b7cb8 mov r0, r5 */
/* @0x1b7cbc bne 0x1b7cac <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x100> */
/* @0x1b7cc0 b 0x1b7c34 <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x88> */
/* @0x1b7cc4 ldr r5, [r0, #0x704] */
/* @0x1b7cc8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b7ccc cmp r5, #0 */
/* @0x1b7cd0 mov r0, r5 */
/* @0x1b7cd4 bne 0x1b7cc4 <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x118> */
/* @0x1b7cd8 b 0x1b7c34 <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x88> */
/* @0x1b7cdc ldr r5, [r0, #0x704] */
/* @0x1b7ce0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b7ce4 cmp r5, #0 */
/* @0x1b7ce8 mov r0, r5 */
/* @0x1b7cec bne 0x1b7cdc <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x130> */
/* @0x1b7cf0 b 0x1b7c34 <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x88> */
/* @0x1b7cf4 eoreq r8, r3, r4, lsr #24 */

/* ── FUNC 0x1b7cf8 · CLayerManager::RemoveSpriteElement(CLayer*, CLayerSpriteElement*) · size=212 · insn=53 */
/* @0x1b7cf8 ldr r3, [r1, #0x18] */
/* @0x1b7cfc mov r12, #0 */
/* @0x1b7d00 ldr r2, [r1, #0x14] */
/* @0x1b7d04 cmp r3, #0 */
/* @0x1b7d08 push {r4, r5, r6, r7, r8, r9} */
/* @0x1b7d0c mov r4, #1065353216 */
/* @0x1b7d10 strne r2, [r3, #0x14] */
/* @0x1b7d14 mvn r5, #0 */
/* @0x1b7d18 ldrne r2, [r1, #0x14] */
/* @0x1b7d1c mov r7, #4 */
/* @0x1b7d20 ldrne r3, [r1, #0x18] */
/* @0x1b7d24 streq r2, [r0, #0x58] */
/* @0x1b7d28 cmp r2, #0 */
/* @0x1b7d2c ldr r9, [r0, #0x60] */
/* @0x1b7d30 strne r3, [r2, #0x18] */
/* @0x1b7d34 ldr r2, [pc, #0x8c] */
/* @0x1b7d38 add r9, r9, r5 */
/* @0x1b7d3c streq r3, [r0, #0x5c] */
/* @0x1b7d40 mov r3, #0 */
/* @0x1b7d44 ldr r2, [pc, r2] */
/* @0x1b7d48 str r9, [r0, #0x60] */
/* @0x1b7d4c str r4, [r1, #0x24] */
/* @0x1b7d50 ldr r6, [r2] */
/* @0x1b7d54 ldr r8, [r2, #0x8] */
/* @0x1b7d58 cmp r6, r3 */
/* @0x1b7d5c str r5, [r1, #0x4] */
/* @0x1b7d60 str r7, [r1] */
/* @0x1b7d64 add r0, r8, #1 */
/* @0x1b7d68 strb r3, [r1, #0x8] */
/* @0x1b7d6c str r4, [r1, #0x2c] */
/* @0x1b7d70 str r4, [r1, #0x30] */
/* @0x1b7d74 str r4, [r1, #0x3c] */
/* @0x1b7d78 str r5, [r1, #0x1c] */
/* @0x1b7d7c str r5, [r1, #0x38] */
/* @0x1b7d80 str r3, [r1, #0xc] */
/* @0x1b7d84 str r12, [r1, #0x20] */
/* @0x1b7d88 str r3, [r1, #0x10] */
/* @0x1b7d8c str r12, [r1, #0x34] */
/* @0x1b7d90 str r3, [r1, #0x14] */
/* @0x1b7d94 str r3, [r1, #0x18] */
/* @0x1b7d98 str r3, [r1, #0x28] */
/* @0x1b7d9c str r12, [r1, #0x40] */
/* @0x1b7da0 str r12, [r1, #0x44] */
/* @0x1b7da4 str r0, [r2, #0x8] */
/* @0x1b7da8 streq r1, [r2, #0x4] */
/* @0x1b7dac strne r1, [r6, #0x18] */
/* @0x1b7db0 streq r1, [r2] */
/* @0x1b7db4 strne r6, [r1, #0x14] */
/* @0x1b7db8 strne r1, [r2] */
/* @0x1b7dbc strne r3, [r1, #0x18] */
/* @0x1b7dc0 pop {r4, r5, r6, r7, r8, r9} */
/* @0x1b7dc4 bx lr */
/* @0x1b7dc8 eoreq r8, r3, r8, lsr #22 */

/* ── FUNC 0x1b7dcc · CLayerManager::RemoveTilemapElement(CLayer*, CLayerTilemapElement*) · size=244 · insn=61 */
/* @0x1b7dcc push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1b7dd0 mov r5, r0 */
/* @0x1b7dd4 ldr r0, [r1, #0x34] */
/* @0x1b7dd8 mov r4, r1 */
/* @0x1b7ddc bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0x1b7de0 cmp r0, #0 */
/* @0x1b7de4 bne 0x1b7df8 <_ZN13CLayerManager20RemoveTilemapElementEP6CLayerP20CLayerTilemapElement+0x2c> */
/* @0x1b7de8 ldr r0, [r4, #0x34] */
/* @0x1b7dec cmp r0, #0 */
/* @0x1b7df0 beq 0x1b7df8 <_ZN13CLayerManager20RemoveTilemapElementEP6CLayerP20CLayerTilemapElement+0x2c> */
/* @0x1b7df4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b7df8 ldr r3, [r4, #0x18] */
/* @0x1b7dfc mov r2, #0 */
/* @0x1b7e00 str r2, [r4, #0x34] */
/* @0x1b7e04 mvn r0, #0 */
/* @0x1b7e08 cmp r3, r2 */
/* @0x1b7e0c ldr r2, [r4, #0x14] */
/* @0x1b7e10 ldr r9, [r5, #0x60] */
/* @0x1b7e14 mov r1, #0 */
/* @0x1b7e18 mov r7, #5 */
/* @0x1b7e1c mvn r6, #-2147483648 */
/* @0x1b7e20 strne r2, [r3, #0x14] */
/* @0x1b7e24 add r9, r9, r0 */
/* @0x1b7e28 ldrne r2, [r4, #0x14] */
/* @0x1b7e2c ldrne r3, [r4, #0x18] */
/* @0x1b7e30 streq r2, [r5, #0x58] */
/* @0x1b7e34 cmp r2, #0 */
/* @0x1b7e38 streq r3, [r5, #0x5c] */
/* @0x1b7e3c strne r3, [r2, #0x18] */
/* @0x1b7e40 mov r3, #0 */
/* @0x1b7e44 ldr r2, [pc, #0x70] */
/* @0x1b7e48 str r9, [r5, #0x60] */
/* @0x1b7e4c ldr r2, [pc, r2] */
/* @0x1b7e50 str r3, [r4, #0xc] */
/* @0x1b7e54 str r1, [r4, #0x20] */
/* @0x1b7e58 ldr r12, [r2] */
/* @0x1b7e5c ldr r8, [r2, #0x8] */
/* @0x1b7e60 cmp r12, r3 */
/* @0x1b7e64 str r7, [r4] */
/* @0x1b7e68 str r0, [r4, #0x4] */
/* @0x1b7e6c add r5, r8, #1 */
/* @0x1b7e70 strb r3, [r4, #0x8] */
/* @0x1b7e74 str r3, [r4, #0x10] */
/* @0x1b7e78 str r1, [r4, #0x24] */
/* @0x1b7e7c str r3, [r4, #0x14] */
/* @0x1b7e80 str r1, [r4, #0x30] */
/* @0x1b7e84 str r3, [r4, #0x18] */
/* @0x1b7e88 str r3, [r4, #0x28] */
/* @0x1b7e8c str r3, [r4, #0x2c] */
/* @0x1b7e90 str r3, [r4, #0x34] */
/* @0x1b7e94 str r0, [r4, #0x1c] */
/* @0x1b7e98 str r6, [r4, #0x38] */
/* @0x1b7e9c str r5, [r2, #0x8] */
/* @0x1b7ea0 streq r4, [r2, #0x4] */
/* @0x1b7ea4 streq r4, [r2] */
/* @0x1b7ea8 strne r4, [r12, #0x18] */
/* @0x1b7eac strne r4, [r2] */
/* @0x1b7eb0 strne r12, [r4, #0x14] */
/* @0x1b7eb4 strne r3, [r4, #0x18] */
/* @0x1b7eb8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1b7ebc eoreq r8, r3, r4, lsr #20 */

/* ── FUNC 0x1b7ec0 · CLayerManager::RemoveParticleElement(CLayer*, CLayerParticleElement*) · size=164 · insn=41 */
/* @0x1b7ec0 ldr r3, [r1, #0x18] */
/* @0x1b7ec4 mvn r12, #0 */
/* @0x1b7ec8 ldr r2, [r1, #0x14] */
/* @0x1b7ecc cmp r3, #0 */
/* @0x1b7ed0 push {r4, r5} */
/* @0x1b7ed4 mov r5, #6 */
/* @0x1b7ed8 strne r2, [r3, #0x14] */
/* @0x1b7edc ldrne r2, [r1, #0x14] */
/* @0x1b7ee0 ldrne r3, [r1, #0x18] */
/* @0x1b7ee4 streq r2, [r0, #0x58] */
/* @0x1b7ee8 cmp r2, #0 */
/* @0x1b7eec streq r3, [r0, #0x5c] */
/* @0x1b7ef0 strne r3, [r2, #0x18] */
/* @0x1b7ef4 mov r2, #0 */
/* @0x1b7ef8 ldr r3, [pc, #0x60] */
/* @0x1b7efc ldr r4, [r0, #0x60] */
/* @0x1b7f00 ldr r3, [pc, r3] */
/* @0x1b7f04 add r4, r4, r12 */
/* @0x1b7f08 str r4, [r0, #0x60] */
/* @0x1b7f0c ldr r0, [r3] */
/* @0x1b7f10 ldr r4, [r3, #0x8] */
/* @0x1b7f14 cmp r0, r2 */
/* @0x1b7f18 str r5, [r1] */
/* @0x1b7f1c str r12, [r1, #0x4] */
/* @0x1b7f20 add r4, r4, #1 */
/* @0x1b7f24 strb r2, [r1, #0x8] */
/* @0x1b7f28 str r2, [r1, #0x14] */
/* @0x1b7f2c str r2, [r1, #0x18] */
/* @0x1b7f30 str r2, [r1, #0xc] */
/* @0x1b7f34 str r2, [r1, #0x10] */
/* @0x1b7f38 str r12, [r1, #0x1c] */
/* @0x1b7f3c str r4, [r3, #0x8] */
/* @0x1b7f40 strne r1, [r0, #0x18] */
/* @0x1b7f44 streq r1, [r3, #0x4] */
/* @0x1b7f48 streq r1, [r3] */
/* @0x1b7f4c strne r1, [r3] */
/* @0x1b7f50 strne r0, [r1, #0x14] */
/* @0x1b7f54 strne r2, [r1, #0x18] */
/* @0x1b7f58 pop {r4, r5} */
/* @0x1b7f5c bx lr */
/* @0x1b7f60 eoreq r8, r3, r4, ror r9 */

/* ── FUNC 0x1b7f64 · CLayerManager::RemoveTileElement(CLayer*, CLayerTileElement*) · size=216 · insn=54 */
/* @0x1b7f64 ldr r3, [r1, #0x18] */
/* @0x1b7f68 mvn r12, #0 */
/* @0x1b7f6c ldr r2, [r1, #0x14] */
/* @0x1b7f70 cmp r3, #0 */
/* @0x1b7f74 push {r4, r5, r6, r7, r8, r9} */
/* @0x1b7f78 mov r5, #1065353216 */
/* @0x1b7f7c strne r2, [r3, #0x14] */
/* @0x1b7f80 mov r4, #0 */
/* @0x1b7f84 ldrne r2, [r1, #0x14] */
/* @0x1b7f88 mov r7, #7 */
/* @0x1b7f8c ldrne r3, [r1, #0x18] */
/* @0x1b7f90 streq r2, [r0, #0x58] */
/* @0x1b7f94 cmp r2, #0 */
/* @0x1b7f98 ldr r9, [r0, #0x60] */
/* @0x1b7f9c strne r3, [r2, #0x18] */
/* @0x1b7fa0 ldr r2, [pc, #0x90] */
/* @0x1b7fa4 add r9, r9, r12 */
/* @0x1b7fa8 streq r3, [r0, #0x5c] */
/* @0x1b7fac mov r3, #0 */
/* @0x1b7fb0 ldr r2, [pc, r2] */
/* @0x1b7fb4 str r9, [r0, #0x60] */
/* @0x1b7fb8 str r4, [r1, #0x24] */
/* @0x1b7fbc ldr r6, [r2] */
/* @0x1b7fc0 ldr r8, [r2, #0x8] */
/* @0x1b7fc4 cmp r6, r3 */
/* @0x1b7fc8 str r4, [r1, #0x28] */
/* @0x1b7fcc add r0, r8, #1 */
/* @0x1b7fd0 str r5, [r1, #0x34] */
/* @0x1b7fd4 str r5, [r1, #0x38] */
/* @0x1b7fd8 str r5, [r1, #0x44] */
/* @0x1b7fdc str r4, [r1, #0x3c] */
/* @0x1b7fe0 str r7, [r1] */
/* @0x1b7fe4 strb r3, [r1, #0x8] */
/* @0x1b7fe8 str r3, [r1, #0xc] */
/* @0x1b7fec str r3, [r1, #0x10] */
/* @0x1b7ff0 str r3, [r1, #0x14] */
/* @0x1b7ff4 str r3, [r1, #0x18] */
/* @0x1b7ff8 str r3, [r1, #0x2c] */
/* @0x1b7ffc str r3, [r1, #0x30] */
/* @0x1b8000 str r3, [r1, #0x48] */
/* @0x1b8004 str r3, [r1, #0x4c] */
/* @0x1b8008 str r12, [r1, #0x4] */
/* @0x1b800c str r12, [r1, #0x20] */
/* @0x1b8010 str r12, [r1, #0x40] */
/* @0x1b8014 str r0, [r2, #0x8] */
/* @0x1b8018 strne r1, [r6, #0x18] */
/* @0x1b801c streq r1, [r2, #0x4] */
/* @0x1b8020 strne r6, [r1, #0x14] */
/* @0x1b8024 streq r1, [r2] */
/* @0x1b8028 strne r1, [r2] */
/* @0x1b802c strne r3, [r1, #0x18] */
/* @0x1b8030 pop {r4, r5, r6, r7, r8, r9} */
/* @0x1b8034 bx lr */
/* @0x1b8038 eoreq r8, r3, r8, asr #17 */

/* ── FUNC 0x1b803c · CLayerManager::BuildBackgroundElementRuntimeData(CRoom*, CLayer*, CLayerBackgroundElement*) · size=12 · insn=3 */
/* @0x1b803c mov r3, #1 */
/* @0x1b8040 strb r3, [r2, #0x8] */
/* @0x1b8044 bx lr */

/* ── FUNC 0x1b8048 · CLayerManager::BuildInstanceElementRuntimeData(CRoom*, CLayer*, CLayerInstanceElement*) · size=392 · insn=98 */
/* @0x1b8048 push {r4, r5, r6, r7, r8} */
/* @0x1b804c ldr r4, [r2, #0x1c] */
/* @0x1b8050 cmp r4, #0 */
/* @0x1b8054 blt 0x1b81c0 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x178> */
/* @0x1b8058 ldr r3, [pc, #0x168] */
/* @0x1b805c ldr r3, [pc, r3] */
/* @0x1b8060 ldm r3, {r3, r12} */
/* @0x1b8064 and r12, r4, r12 */
/* @0x1b8068 ldr r3, [r3, r12, lsl #3] */
/* @0x1b806c cmp r3, #0 */
/* @0x1b8070 bne 0x1b8084 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x3c> */
/* @0x1b8074 b 0x1b81c0 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x178> */
/* @0x1b8078 ldr r3, [r3, #0x4] */
/* @0x1b807c cmp r3, #0 */
/* @0x1b8080 beq 0x1b81c0 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x178> */
/* @0x1b8084 ldr r12, [r3, #0x8] */
/* @0x1b8088 cmp r4, r12 */
/* @0x1b808c bne 0x1b8078 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x30> */
/* @0x1b8090 ldr r4, [r3, #0xc] */
/* @0x1b8094 cmp r4, #0 */
/* @0x1b8098 beq 0x1b81c0 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x178> */
/* @0x1b809c ldr r5, [r4, #0x170] */
/* @0x1b80a0 cmn r5, #1 */
/* @0x1b80a4 beq 0x1b81a8 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x160> */
/* @0x1b80a8 ldrb r3, [r4, #0x174] */
/* @0x1b80ac cmp r3, #0 */
/* @0x1b80b0 beq 0x1b81a8 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x160> */
/* @0x1b80b4 ldr r12, [r0, #0xd4] */
/* @0x1b80b8 cmp r12, #0 */
/* @0x1b80bc bne 0x1b80d0 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x88> */
/* @0x1b80c0 b 0x1b81a8 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x160> */
/* @0x1b80c4 ldr r12, [r12, #0x68] */
/* @0x1b80c8 cmp r12, #0 */
/* @0x1b80cc beq 0x1b81a8 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x160> */
/* @0x1b80d0 ldr r3, [r12] */
/* @0x1b80d4 cmp r5, r3 */
/* @0x1b80d8 bne 0x1b80c4 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x7c> */
/* @0x1b80dc ldr r3, [r12, #0x58] */
/* @0x1b80e0 cmp r3, #0 */
/* @0x1b80e4 bne 0x1b80f8 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0xb0> */
/* @0x1b80e8 b 0x1b80c4 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x7c> */
/* @0x1b80ec ldr r3, [r3, #0x14] */
/* @0x1b80f0 cmp r3, #0 */
/* @0x1b80f4 beq 0x1b80c4 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x7c> */
/* @0x1b80f8 ldr r0, [r3] */
/* @0x1b80fc cmp r0, #2 */
/* @0x1b8100 bne 0x1b80ec <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0xa4> */
/* @0x1b8104 ldr r0, [r3, #0x20] */
/* @0x1b8108 cmp r0, r4 */
/* @0x1b810c bne 0x1b80ec <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0xa4> */
/* @0x1b8110 ldr r0, [r3, #0x18] */
/* @0x1b8114 mvn r6, #0 */
/* @0x1b8118 ldr r5, [r3, #0x14] */
/* @0x1b811c mov r8, #2 */
/* @0x1b8120 cmp r0, #0 */
/* @0x1b8124 ldr r7, [r12, #0x60] */
/* @0x1b8128 strne r5, [r0, #0x14] */
/* @0x1b812c add r7, r7, r6 */
/* @0x1b8130 ldrne r5, [r3, #0x14] */
/* @0x1b8134 ldrne r0, [r3, #0x18] */
/* @0x1b8138 streq r5, [r12, #0x58] */
/* @0x1b813c cmp r5, #0 */
/* @0x1b8140 streq r0, [r12, #0x5c] */
/* @0x1b8144 strne r0, [r5, #0x18] */
/* @0x1b8148 mov r0, #0 */
/* @0x1b814c ldr r5, [pc, #0x78] */
/* @0x1b8150 str r7, [r12, #0x60] */
/* @0x1b8154 ldr r5, [pc, r5] */
/* @0x1b8158 str r0, [r3, #0x14] */
/* @0x1b815c str r0, [r3, #0x18] */
/* @0x1b8160 ldr r12, [r5] */
/* @0x1b8164 ldr r7, [r5, #0x8] */
/* @0x1b8168 cmp r12, r0 */
/* @0x1b816c str r8, [r3] */
/* @0x1b8170 str r6, [r3, #0x4] */
/* @0x1b8174 add r7, r7, #1 */
/* @0x1b8178 strb r0, [r3, #0x8] */
/* @0x1b817c str r0, [r3, #0xc] */
/* @0x1b8180 str r0, [r3, #0x10] */
/* @0x1b8184 str r0, [r3, #0x20] */
/* @0x1b8188 str r6, [r3, #0x1c] */
/* @0x1b818c str r7, [r5, #0x8] */
/* @0x1b8190 strne r3, [r12, #0x18] */
/* @0x1b8194 streq r3, [r5, #0x4] */
/* @0x1b8198 streq r3, [r5] */
/* @0x1b819c strne r3, [r5] */
/* @0x1b81a0 strne r12, [r3, #0x14] */
/* @0x1b81a4 strne r0, [r3, #0x18] */
/* @0x1b81a8 ldr r1, [r1] */
/* @0x1b81ac mov r3, #1 */
/* @0x1b81b0 str r4, [r2, #0x20] */
/* @0x1b81b4 strb r3, [r4, #0x174] */
/* @0x1b81b8 str r1, [r4, #0x170] */
/* @0x1b81bc strb r3, [r2, #0x8] */
/* @0x1b81c0 pop {r4, r5, r6, r7, r8} */
/* @0x1b81c4 bx lr */
/* @0x1b81c8 eoreq r5, r3, r8, ror #23 */
/* @0x1b81cc eoreq r8, r3, r0, lsl r7 */

/* ── FUNC 0x1b81d0 · CLayerManager::BuildSpriteElementRuntimeData(CRoom*, CLayer*, CLayerSpriteElement*) · size=12 · insn=3 */
/* @0x1b81d0 mov r3, #1 */
/* @0x1b81d4 strb r3, [r2, #0x8] */
/* @0x1b81d8 bx lr */

/* ── FUNC 0x1b81dc · CLayerManager::BuildTilemapElementRuntimeData(CRoom*, CLayer*, CLayerTilemapElement*) · size=12 · insn=3 */
/* @0x1b81dc mov r3, #1 */
/* @0x1b81e0 strb r3, [r2, #0x8] */
/* @0x1b81e4 bx lr */

/* ── FUNC 0x1b81e8 · CLayerManager::BuildParticleElementRuntimeData(CRoom*, CLayer*, CLayerParticleElement*) · size=12 · insn=3 */
/* @0x1b81e8 mov r3, #1 */
/* @0x1b81ec strb r3, [r2, #0x8] */
/* @0x1b81f0 bx lr */

/* ── FUNC 0x1b81f4 · CLayerManager::BuildTileElementRuntimeData(CRoom*, CLayer*, CLayerTileElement*) · size=12 · insn=3 */
/* @0x1b81f4 mov r3, #1 */
/* @0x1b81f8 strb r3, [r2, #0x8] */
/* @0x1b81fc bx lr */

/* ── FUNC 0x1b8200 · CLayerManager::ChangeLayerDepth(CRoom*, CLayer*, int, bool) · size=1524 · insn=381 */
/* @0x1b8200 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b8204 subs r4, r0, #0 */
/* @0x1b8208 sub sp, sp, #20 */
/* @0x1b820c beq 0x1b82a4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xa4> */
/* @0x1b8210 cmp r1, #0 */
/* @0x1b8214 beq 0x1b82a4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xa4> */
/* @0x1b8218 ldr r0, [r1, #0x4] */
/* @0x1b821c cmp r0, r2 */
/* @0x1b8220 beq 0x1b82a4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xa4> */
/* @0x1b8224 str r2, [r1, #0x4] */
/* @0x1b8228 ble 0x1b82ac <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xac> */
/* @0x1b822c ldr r12, [r1, #0x6c] */
/* @0x1b8230 cmp r12, #0 */
/* @0x1b8234 beq 0x1b843c <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x23c> */
/* @0x1b8238 ldr r3, [r12, #0x4] */
/* @0x1b823c cmp r2, r3 */
/* @0x1b8240 movle r3, r12 */
/* @0x1b8244 ble 0x1b8258 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x58> */
/* @0x1b8248 b 0x1b8448 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x248> */
/* @0x1b824c ldr r0, [r3, #0x4] */
/* @0x1b8250 cmp r2, r0 */
/* @0x1b8254 bgt 0x1b844c <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x24c> */
/* @0x1b8258 ldr r3, [r3, #0x6c] */
/* @0x1b825c cmp r3, #0 */
/* @0x1b8260 bne 0x1b824c <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x4c> */
/* @0x1b8264 ldr r3, [r1, #0x68] */
/* @0x1b8268 str r3, [r12, #0x68] */
/* @0x1b826c ldr r3, [r1, #0x68] */
/* @0x1b8270 ldr r12, [r1, #0x6c] */
/* @0x1b8274 cmp r3, #0 */
/* @0x1b8278 strne r12, [r3, #0x6c] */
/* @0x1b827c ldr r3, [r4, #0xd4] */
/* @0x1b8280 streq r12, [r4, #0xd8] */
/* @0x1b8284 cmp r3, #0 */
/* @0x1b8288 beq 0x1b8428 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x228> */
/* @0x1b828c str r1, [r3, #0x6c] */
/* @0x1b8290 mov r3, #0 */
/* @0x1b8294 ldr r2, [r4, #0xd4] */
/* @0x1b8298 str r2, [r1, #0x68] */
/* @0x1b829c str r1, [r4, #0xd4] */
/* @0x1b82a0 str r3, [r1, #0x6c] */
/* @0x1b82a4 add sp, sp, #20 */
/* @0x1b82a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b82ac ldr r12, [r1, #0x68] */
/* @0x1b82b0 cmp r12, #0 */
/* @0x1b82b4 beq 0x1b82f4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xf4> */
/* @0x1b82b8 ldr r0, [r12, #0x4] */
/* @0x1b82bc cmp r2, r0 */
/* @0x1b82c0 blt 0x1b8380 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x180> */
/* @0x1b82c4 cmp r3, #0 */
/* @0x1b82c8 mov r3, r12 */
/* @0x1b82cc bne 0x1b8374 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x174> */
/* @0x1b82d0 ldr r3, [r3, #0x68] */
/* @0x1b82d4 cmp r3, #0 */
/* @0x1b82d8 beq 0x1b82f4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xf4> */
/* @0x1b82dc ldr r0, [r3, #0x4] */
/* @0x1b82e0 cmp r2, r0 */
/* @0x1b82e4 blt 0x1b8384 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x184> */
/* @0x1b82e8 ldr r3, [r3, #0x68] */
/* @0x1b82ec cmp r3, #0 */
/* @0x1b82f0 bne 0x1b82dc <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xdc> */
/* @0x1b82f4 ldr r3, [r1, #0x6c] */
/* @0x1b82f8 cmp r3, #0 */
/* @0x1b82fc streq r12, [r4, #0xd4] */
/* @0x1b8300 strne r12, [r3, #0x68] */
/* @0x1b8304 ldrne r12, [r1, #0x68] */
/* @0x1b8308 ldrne r3, [r1, #0x6c] */
/* @0x1b830c cmp r12, #0 */
/* @0x1b8310 streq r3, [r4, #0xd8] */
/* @0x1b8314 strne r3, [r12, #0x6c] */
/* @0x1b8318 ldrne r3, [r4, #0xd8] */
/* @0x1b831c cmp r3, #0 */
/* @0x1b8320 beq 0x1b8428 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x228> */
/* @0x1b8324 str r1, [r3, #0x68] */
/* @0x1b8328 mov r3, #0 */
/* @0x1b832c ldr r2, [r4, #0xd8] */
/* @0x1b8330 str r2, [r1, #0x6c] */
/* @0x1b8334 str r1, [r4, #0xd8] */
/* @0x1b8338 str r3, [r1, #0x68] */
/* @0x1b833c add sp, sp, #20 */
/* @0x1b8340 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b8344 ldrb r0, [r3, #0x19] */
/* @0x1b8348 cmp r0, #0 */
/* @0x1b834c beq 0x1b835c <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x15c> */
/* @0x1b8350 ldrb r0, [r1, #0x19] */
/* @0x1b8354 cmp r0, #0 */
/* @0x1b8358 bne 0x1b83e8 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x1e8> */
/* @0x1b835c ldr r3, [r3, #0x68] */
/* @0x1b8360 cmp r3, #0 */
/* @0x1b8364 beq 0x1b82f4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xf4> */
/* @0x1b8368 ldr r0, [r3, #0x4] */
/* @0x1b836c cmp r2, r0 */
/* @0x1b8370 blt 0x1b8384 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x184> */
/* @0x1b8374 cmp r2, r0 */
/* @0x1b8378 bne 0x1b835c <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x15c> */
/* @0x1b837c b 0x1b8344 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x144> */
/* @0x1b8380 mov r3, r12 */
/* @0x1b8384 ldr r2, [r3, #0x6c] */
/* @0x1b8388 cmp r1, r2 */
/* @0x1b838c beq 0x1b82a4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xa4> */
/* @0x1b8390 ldr r2, [r1, #0x6c] */
/* @0x1b8394 cmp r2, #0 */
/* @0x1b8398 streq r12, [r4, #0xd4] */
/* @0x1b839c beq 0x1b83b8 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x1b8> */
/* @0x1b83a0 str r12, [r2, #0x68] */
/* @0x1b83a4 ldr r12, [r1, #0x68] */
/* @0x1b83a8 ldr r2, [r1, #0x6c] */
/* @0x1b83ac cmp r12, #0 */
/* @0x1b83b0 streq r2, [r4, #0xd8] */
/* @0x1b83b4 beq 0x1b83bc <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x1bc> */
/* @0x1b83b8 str r2, [r12, #0x6c] */
/* @0x1b83bc ldr r3, [r3, #0x6c] */
/* @0x1b83c0 str r3, [r1, #0x6c] */
/* @0x1b83c4 ldr r2, [r3, #0x68] */
/* @0x1b83c8 str r2, [r1, #0x68] */
/* @0x1b83cc ldr r2, [r3, #0x68] */
/* @0x1b83d0 cmp r2, #0 */
/* @0x1b83d4 streq r1, [r4, #0xd8] */
/* @0x1b83d8 strne r1, [r2, #0x6c] */
/* @0x1b83dc str r1, [r3, #0x68] */
/* @0x1b83e0 add sp, sp, #20 */
/* @0x1b83e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b83e8 ldr r2, [r1, #0x58] */
/* @0x1b83ec cmp r2, #0 */
/* @0x1b83f0 bne 0x1b8408 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x208> */
/* @0x1b83f4 b 0x1b8480 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x280> */
/* @0x1b83f8 str r3, [r2, #0x10] */
/* @0x1b83fc ldr r2, [r2, #0x14] */
/* @0x1b8400 cmp r2, #0 */
/* @0x1b8404 beq 0x1b847c <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x27c> */
/* @0x1b8408 ldr r0, [r2] */
/* @0x1b840c cmp r0, #2 */
/* @0x1b8410 bne 0x1b83f8 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x1f8> */
/* @0x1b8414 ldr r0, [r2, #0x20] */
/* @0x1b8418 cmp r0, #0 */
/* @0x1b841c ldrne r12, [r3] */
/* @0x1b8420 strne r12, [r0, #0x170] */
/* @0x1b8424 b 0x1b83f8 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x1f8> */
/* @0x1b8428 str r1, [r4, #0xd8] */
/* @0x1b842c str r1, [r4, #0xd4] */
/* @0x1b8430 str r3, [r1, #0x6c] */
/* @0x1b8434 str r3, [r1, #0x68] */
/* @0x1b8438 b 0x1b82a4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xa4> */
/* @0x1b843c ldr r3, [r1, #0x68] */
/* @0x1b8440 str r3, [r4, #0xd4] */
/* @0x1b8444 b 0x1b8274 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x74> */
/* @0x1b8448 mov r3, r12 */
/* @0x1b844c ldr r2, [r3, #0x68] */
/* @0x1b8450 cmp r1, r2 */
/* @0x1b8454 beq 0x1b82a4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xa4> */
/* @0x1b8458 ldr r2, [r1, #0x68] */
/* @0x1b845c str r2, [r12, #0x68] */
/* @0x1b8460 ldr r2, [r1, #0x68] */
/* @0x1b8464 cmp r2, #0 */
/* @0x1b8468 ldreq r2, [r1, #0x6c] */
/* @0x1b846c ldrne r0, [r1, #0x6c] */
/* @0x1b8470 streq r2, [r4, #0xd8] */
/* @0x1b8474 strne r0, [r2, #0x6c] */
/* @0x1b8478 b 0x1b83c0 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x1c0> */
/* @0x1b847c ldr r2, [r1, #0x58] */
/* @0x1b8480 ldr r0, [r3, #0x5c] */
/* @0x1b8484 ldr r12, [r3, #0x60] */
/* @0x1b8488 cmp r0, #0 */
/* @0x1b848c streq r2, [r3, #0x5c] */
/* @0x1b8490 strne r2, [r0, #0x14] */
/* @0x1b8494 mov r0, #0 */
/* @0x1b8498 streq r2, [r3, #0x58] */
/* @0x1b849c ldrne r2, [r3, #0x5c] */
/* @0x1b84a0 ldr lr, [r1, #0x58] */
/* @0x1b84a4 str r2, [lr, #0x18] */
/* @0x1b84a8 ldr r2, [r1, #0x5c] */
/* @0x1b84ac str r2, [r3, #0x5c] */
/* @0x1b84b0 ldr r2, [r1, #0x60] */
/* @0x1b84b4 add r2, r12, r2 */
/* @0x1b84b8 str r2, [r3, #0x60] */
/* @0x1b84bc ldr r2, [r1, #0x6c] */
/* @0x1b84c0 ldr r3, [r1, #0x68] */
/* @0x1b84c4 cmp r2, r0 */
/* @0x1b84c8 str r0, [r1, #0x60] */
/* @0x1b84cc str r0, [r1, #0x5c] */
/* @0x1b84d0 str r0, [r1, #0x58] */
/* @0x1b84d4 strne r3, [r2, #0x68] */
/* @0x1b84d8 ldrne r3, [r1, #0x68] */
/* @0x1b84dc ldrne r2, [r1, #0x6c] */
/* @0x1b84e0 streq r3, [r4, #0xd4] */
/* @0x1b84e4 cmp r3, #0 */
/* @0x1b84e8 ldr r0, [r1] */
/* @0x1b84ec strne r2, [r3, #0x6c] */
/* @0x1b84f0 ldr r3, [r4, #0xdc] */
/* @0x1b84f4 streq r2, [r4, #0xd8] */
/* @0x1b84f8 sub r3, r3, #1 */
/* @0x1b84fc str r3, [r4, #0xdc] */
/* @0x1b8500 str r1, [sp, #0x4] */
/* @0x1b8504 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b8508 ldr r2, [r4, #0xec] */
/* @0x1b850c ldr lr, [r4, #0xf4] */
/* @0x1b8510 ldr r1, [sp, #0x4] */
/* @0x1b8514 bic r0, r0, #-2147483648 */
/* @0x1b8518 and r3, r0, r2 */
/* @0x1b851c lsl r12, r3, #1 */
/* @0x1b8520 add r5, r12, r3 */
/* @0x1b8524 add r5, lr, r5, lsl #2 */
/* @0x1b8528 ldr r5, [r5, #0x8] */
/* @0x1b852c cmp r5, #0 */
/* @0x1b8530 beq 0x1b85a0 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x3a0> */
/* @0x1b8534 cmp r0, r5 */
/* @0x1b8538 beq 0x1b8724 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x524> */
/* @0x1b853c ldr r9, [r4, #0xe4] */
/* @0x1b8540 and r5, r2, r5 */
/* @0x1b8544 add r12, r3, r9 */
/* @0x1b8548 rsb r12, r5, r12 */
/* @0x1b854c tst r12, r2 */
/* @0x1b8550 bmi 0x1b85a0 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x3a0> */
/* @0x1b8554 mov r6, #0 */
/* @0x1b8558 b 0x1b856c <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x36c> */
/* @0x1b855c cmp r0, r5 */
/* @0x1b8560 beq 0x1b871c <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x51c> */
/* @0x1b8564 cmp r7, r6 */
/* @0x1b8568 blt 0x1b85a0 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x3a0> */
/* @0x1b856c add r3, r3, #1 */
/* @0x1b8570 add r6, r6, #1 */
/* @0x1b8574 and r3, r2, r3 */
/* @0x1b8578 add r8, r3, r9 */
/* @0x1b857c lsl r12, r3, #1 */
/* @0x1b8580 add r5, r12, r3 */
/* @0x1b8584 add r5, lr, r5, lsl #2 */
/* @0x1b8588 ldr r5, [r5, #0x8] */
/* @0x1b858c and r7, r2, r5 */
/* @0x1b8590 cmp r5, #0 */
/* @0x1b8594 rsb r7, r7, r8 */
/* @0x1b8598 and r7, r7, r2 */
/* @0x1b859c bne 0x1b855c <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x35c> */
/* @0x1b85a0 ldr r0, [r1, #0x1c] */
/* @0x1b85a4 str r1, [sp, #0x4] */
/* @0x1b85a8 bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0x1b85ac ldr r1, [sp, #0x4] */
/* @0x1b85b0 cmp r0, #0 */
/* @0x1b85b4 bne 0x1b85c4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x3c4> */
/* @0x1b85b8 ldr r0, [r1, #0x1c] */
/* @0x1b85bc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b85c0 ldr r1, [sp, #0x4] */
/* @0x1b85c4 ldr r3, [r1, #0x64] */
/* @0x1b85c8 mov r2, #0 */
/* @0x1b85cc str r2, [r1, #0x1c] */
/* @0x1b85d0 cmp r3, r2 */
/* @0x1b85d4 beq 0x1b8618 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x418> */
/* @0x1b85d8 ldr r0, [r1, #0x58] */
/* @0x1b85dc cmp r0, #0 */
/* @0x1b85e0 beq 0x1b8618 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x418> */
/* @0x1b85e4 cmp r3, #2 */
/* @0x1b85e8 moveq r5, r1 */
/* @0x1b85ec beq 0x1b86d0 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x4d0> */
/* @0x1b85f0 cmp r3, #3 */
/* @0x1b85f4 moveq r5, r1 */
/* @0x1b85f8 beq 0x1b86ec <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x4ec> */
/* @0x1b85fc cmp r3, #1 */
/* @0x1b8600 moveq r5, r1 */
/* @0x1b8604 beq 0x1b8704 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x504> */
/* @0x1b8608 mov r3, r0 */
/* @0x1b860c ldr r3, [r3, #0x14] */
/* @0x1b8610 cmp r3, #0 */
/* @0x1b8614 bne 0x1b860c <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x40c> */
/* @0x1b8618 mov r4, #0 */
/* @0x1b861c mvn r12, #0 */
/* @0x1b8620 mov r3, #0 */
/* @0x1b8624 str r4, [r1, #0x60] */
/* @0x1b8628 str r3, [r1, #0x8] */
/* @0x1b862c mov r5, #1 */
/* @0x1b8630 str r3, [r1, #0xc] */
/* @0x1b8634 mov r2, #0 */
/* @0x1b8638 str r3, [r1, #0x10] */
/* @0x1b863c add r0, r1, #48 */
/* @0x1b8640 str r3, [r1, #0x14] */
/* @0x1b8644 mov r3, #0 */
/* @0x1b8648 str r4, [r1, #0x5c] */
/* @0x1b864c strd r2, r3, [r1, #72] */
/* @0x1b8650 str r4, [r1, #0x58] */
/* @0x1b8654 str r4, [r1, #0x4] */
/* @0x1b8658 strb r4, [r1, #0x19] */
/* @0x1b865c str r4, [r1, #0x1c] */
/* @0x1b8660 str r12, [r1] */
/* @0x1b8664 str r12, [r1, #0x20] */
/* @0x1b8668 str r12, [r1, #0x24] */
/* @0x1b866c str r12, [r1, #0x28] */
/* @0x1b8670 strb r5, [r1, #0x18] */
/* @0x1b8674 str r1, [sp, #0x4] */
/* @0x1b8678 bl 0x214728 <_ZN13CTimingSource5ResetEv> */
/* @0x1b867c ldr r3, [pc, #0x16c] */
/* @0x1b8680 ldr r1, [sp, #0x4] */
/* @0x1b8684 ldr r3, [pc, r3] */
/* @0x1b8688 ldr r2, [r3] */
/* @0x1b868c ldr r0, [r3, #0x8] */
/* @0x1b8690 cmp r2, r4 */
/* @0x1b8694 str r4, [r1, #0x68] */
/* @0x1b8698 str r4, [r1, #0x6c] */
/* @0x1b869c add r0, r0, r5 */
/* @0x1b86a0 str r4, [r1, #0x5c] */
/* @0x1b86a4 str r4, [r1, #0x58] */
/* @0x1b86a8 str r4, [r1, #0x60] */
/* @0x1b86ac str r5, [r1, #0x64] */
/* @0x1b86b0 str r0, [r3, #0x8] */
/* @0x1b86b4 strne r1, [r2, #0x6c] */
/* @0x1b86b8 strne r1, [r3] */
/* @0x1b86bc strne r2, [r1, #0x68] */
/* @0x1b86c0 strne r4, [r1, #0x6c] */
/* @0x1b86c4 streq r1, [r3, #0x4] */
/* @0x1b86c8 streq r1, [r3] */
/* @0x1b86cc b 0x1b82a4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xa4> */
/* @0x1b86d0 ldr r4, [r0, #0x14] */
/* @0x1b86d4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b86d8 cmp r4, #0 */
/* @0x1b86dc mov r0, r4 */
/* @0x1b86e0 bne 0x1b86d0 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x4d0> */
/* @0x1b86e4 mov r1, r5 */
/* @0x1b86e8 b 0x1b8618 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x418> */
/* @0x1b86ec ldr r4, [r0, #0x14] */
/* @0x1b86f0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b86f4 cmp r4, #0 */
/* @0x1b86f8 mov r0, r4 */
/* @0x1b86fc bne 0x1b86ec <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x4ec> */
/* @0x1b8700 b 0x1b86e4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x4e4> */
/* @0x1b8704 ldr r4, [r0, #0x14] */
/* @0x1b8708 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b870c cmp r4, #0 */
/* @0x1b8710 mov r0, r4 */
/* @0x1b8714 bne 0x1b8704 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x504> */
/* @0x1b8718 b 0x1b86e4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x4e4> */
/* @0x1b871c cmn r3, #1 */
/* @0x1b8720 beq 0x1b85a0 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x3a0> */
/* @0x1b8724 add r0, r3, #1 */
/* @0x1b8728 and r9, r0, r2 */
/* @0x1b872c add r6, r9, r9, lsl #1 */
/* @0x1b8730 add r6, lr, r6, lsl #2 */
/* @0x1b8734 ldr r5, [r6, #0x8] */
/* @0x1b8738 cmp r5, #0 */
/* @0x1b873c beq 0x1b87e8 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x5e8> */
/* @0x1b8740 ldr r8, [r4, #0xe4] */
/* @0x1b8744 and r0, r2, r5 */
/* @0x1b8748 add r7, r9, r8 */
/* @0x1b874c rsb r0, r0, r7 */
/* @0x1b8750 tst r0, r2 */
/* @0x1b8754 strne r4, [sp, #0x8] */
/* @0x1b8758 strne r1, [sp, #0xc] */
/* @0x1b875c movne r11, r8 */
/* @0x1b8760 bne 0x1b8774 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x574> */
/* @0x1b8764 b 0x1b87e8 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x5e8> */
/* @0x1b8768 tst r4, r2 */
/* @0x1b876c beq 0x1b87c0 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x5c0> */
/* @0x1b8770 mov r9, r1 */
/* @0x1b8774 add r4, r12, r3 */
/* @0x1b8778 add r1, r9, #1 */
/* @0x1b877c and r1, r1, r2 */
/* @0x1b8780 ldr r7, [r6, #0x4] */
/* @0x1b8784 add r0, lr, r4, lsl #2 */
/* @0x1b8788 add r8, r1, r11 */
/* @0x1b878c add r10, r1, r1, lsl #1 */
/* @0x1b8790 mov r3, r9 */
/* @0x1b8794 str r5, [r0, #0x8] */
/* @0x1b8798 lsl r12, r9, #1 */
/* @0x1b879c ldr r6, [r6] */
/* @0x1b87a0 str r6, [lr, r4, lsl #2] */
/* @0x1b87a4 add r6, lr, r10, lsl #2 */
/* @0x1b87a8 ldr r5, [r6, #0x8] */
/* @0x1b87ac str r7, [r0, #0x4] */
/* @0x1b87b0 cmp r5, #0 */
/* @0x1b87b4 and r4, r2, r5 */
/* @0x1b87b8 rsb r4, r4, r8 */
/* @0x1b87bc bne 0x1b8768 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x568> */
/* @0x1b87c0 ldr r4, [sp, #0x8] */
/* @0x1b87c4 ldr r1, [sp, #0xc] */
/* @0x1b87c8 add r0, r9, r9, lsl #1 */
/* @0x1b87cc ldr r3, [r4, #0xe8] */
/* @0x1b87d0 mov r2, #0 */
/* @0x1b87d4 add lr, lr, r0, lsl #2 */
/* @0x1b87d8 sub r3, r3, #1 */
/* @0x1b87dc str r2, [lr, #0x8] */
/* @0x1b87e0 str r3, [r4, #0xe8] */
/* @0x1b87e4 b 0x1b85a0 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x3a0> */
/* @0x1b87e8 mov r9, r3 */
/* @0x1b87ec b 0x1b87c8 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x5c8> */
/* @0x1b87f0 .word 0x002381d8 */

/* ── FUNC 0x1b87f4 · CLayerManager::GetLayerWithDepth(CRoom*, int, bool) · size=116 · insn=29 */
/* @0x1b87f4 cmp r0, #0 */
/* @0x1b87f8 bxeq lr */
/* @0x1b87fc ldr r0, [r0, #0xd4] */
/* @0x1b8800 cmp r0, #0 */
/* @0x1b8804 bxeq lr */
/* @0x1b8808 cmp r2, #0 */
/* @0x1b880c beq 0x1b8844 <_ZN13CLayerManager17GetLayerWithDepthEP5CRoomib+0x50> */
/* @0x1b8810 ldr r3, [r0, #0x4] */
/* @0x1b8814 cmp r3, r1 */
/* @0x1b8818 beq 0x1b8828 <_ZN13CLayerManager17GetLayerWithDepthEP5CRoomib+0x34> */
/* @0x1b881c ble 0x1b8834 <_ZN13CLayerManager17GetLayerWithDepthEP5CRoomib+0x40> */
/* @0x1b8820 mov r0, #0 */
/* @0x1b8824 bx lr */
/* @0x1b8828 ldrb r3, [r0, #0x19] */
/* @0x1b882c cmp r3, #0 */
/* @0x1b8830 bxne lr */
/* @0x1b8834 ldr r0, [r0, #0x68] */
/* @0x1b8838 cmp r0, #0 */
/* @0x1b883c bne 0x1b8810 <_ZN13CLayerManager17GetLayerWithDepthEP5CRoomib+0x1c> */
/* @0x1b8840 bx lr */
/* @0x1b8844 ldr r3, [r0, #0x4] */
/* @0x1b8848 cmp r3, r1 */
/* @0x1b884c bxeq lr */
/* @0x1b8850 cmp r1, r3 */
/* @0x1b8854 blt 0x1b8820 <_ZN13CLayerManager17GetLayerWithDepthEP5CRoomib+0x2c> */
/* @0x1b8858 ldr r0, [r0, #0x68] */
/* @0x1b885c cmp r0, #0 */
/* @0x1b8860 bne 0x1b8844 <_ZN13CLayerManager17GetLayerWithDepthEP5CRoomib+0x50> */
/* @0x1b8864 bx lr */

/* ── FUNC 0x1b8868 · CLayerManager::GetLayerFromID(CRoom*, int) · size=200 · insn=50 */
/* @0x1b8868 push {r4, r5, r6, r7, r8, lr} */
/* @0x1b886c mov r5, r0 */
/* @0x1b8870 mov r0, r1 */
/* @0x1b8874 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b8878 ldr r1, [r5, #0xec] */
/* @0x1b887c ldr r7, [r5, #0xf4] */
/* @0x1b8880 bic r8, r0, #-2147483648 */
/* @0x1b8884 and r3, r8, r1 */
/* @0x1b8888 lsl r4, r3, #1 */
/* @0x1b888c add r2, r4, r3 */
/* @0x1b8890 add r2, r7, r2, lsl #2 */
/* @0x1b8894 ldr r2, [r2, #0x8] */
/* @0x1b8898 cmp r2, #0 */
/* @0x1b889c beq 0x1b890c <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi+0xa4> */
/* @0x1b88a0 cmp r8, r2 */
/* @0x1b88a4 beq 0x1b891c <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi+0xb4> */
/* @0x1b88a8 ldr r0, [r5, #0xe4] */
/* @0x1b88ac and r2, r1, r2 */
/* @0x1b88b0 add r12, r3, r0 */
/* @0x1b88b4 rsb r2, r2, r12 */
/* @0x1b88b8 tst r2, r1 */
/* @0x1b88bc bmi 0x1b890c <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi+0xa4> */
/* @0x1b88c0 mov r12, #0 */
/* @0x1b88c4 b 0x1b88d8 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi+0x70> */
/* @0x1b88c8 cmp r8, r2 */
/* @0x1b88cc beq 0x1b8914 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi+0xac> */
/* @0x1b88d0 cmp r5, r12 */
/* @0x1b88d4 blt 0x1b890c <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi+0xa4> */
/* @0x1b88d8 add r3, r3, #1 */
/* @0x1b88dc add r12, r12, #1 */
/* @0x1b88e0 and r3, r1, r3 */
/* @0x1b88e4 add r6, r3, r0 */
/* @0x1b88e8 lsl r4, r3, #1 */
/* @0x1b88ec add r2, r4, r3 */
/* @0x1b88f0 add r2, r7, r2, lsl #2 */
/* @0x1b88f4 ldr r2, [r2, #0x8] */
/* @0x1b88f8 and r5, r1, r2 */
/* @0x1b88fc cmp r2, #0 */
/* @0x1b8900 rsb r5, r5, r6 */
/* @0x1b8904 and r5, r5, r1 */
/* @0x1b8908 bne 0x1b88c8 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi+0x60> */
/* @0x1b890c mov r0, #0 */
/* @0x1b8910 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1b8914 cmn r3, #1 */
/* @0x1b8918 beq 0x1b890c <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi+0xa4> */
/* @0x1b891c add r3, r4, r3 */
/* @0x1b8920 add r7, r7, r3, lsl #2 */
/* @0x1b8924 adds r0, r7, #4 */
/* @0x1b8928 ldrne r0, [r7, #0x4] */
/* @0x1b892c pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x1b8930 · CLayerManager::GetLayerDepth(CRoom*, int) · size=24 · insn=6 */
/* @0x1b8930 push {r3, lr} */
/* @0x1b8934 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1b8938 cmp r0, #0 */
/* @0x1b893c ldrne r0, [r0, #0x4] */
/* @0x1b8940 mvneq r0, #0 */
/* @0x1b8944 pop {r3, pc} */

/* ── FUNC 0x1b8948 · CLayerManager::ChangeLayerDepth(CRoom*, int, int, bool) · size=52 · insn=13 */
/* @0x1b8948 push {r4, r5, r6, lr} */
/* @0x1b894c subs r4, r0, #0 */
/* @0x1b8950 mov r6, r2 */
/* @0x1b8954 mov r5, r3 */
/* @0x1b8958 popeq {r4, r5, r6, pc} */
/* @0x1b895c bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1b8960 subs r1, r0, #0 */
/* @0x1b8964 popeq {r4, r5, r6, pc} */
/* @0x1b8968 mov r0, r4 */
/* @0x1b896c mov r2, r6 */
/* @0x1b8970 mov r3, r5 */
/* @0x1b8974 pop {r4, r5, r6, lr} */
/* @0x1b8978 b 0x1b8200 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib> */

/* ── FUNC 0x1b897c · CLayerManager::GetLayerFromName(CRoom*, char const*) · size=80 · insn=20 */
/* @0x1b897c push {r3, r4, r5, lr} */
/* @0x1b8980 subs r5, r1, #0 */
/* @0x1b8984 beq 0x1b89c4 <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc+0x48> */
/* @0x1b8988 ldr r4, [r0, #0xd4] */
/* @0x1b898c cmp r4, #0 */
/* @0x1b8990 beq 0x1b89bc <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc+0x40> */
/* @0x1b8994 ldr r1, [r4, #0x1c] */
/* @0x1b8998 mov r0, r5 */
/* @0x1b899c cmp r1, #0 */
/* @0x1b89a0 beq 0x1b89b0 <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc+0x34> */
/* @0x1b89a4 bl 0xb66d0 <strcasecmp@plt> */
/* @0x1b89a8 cmp r0, #0 */
/* @0x1b89ac beq 0x1b89bc <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc+0x40> */
/* @0x1b89b0 ldr r4, [r4, #0x68] */
/* @0x1b89b4 cmp r4, #0 */
/* @0x1b89b8 bne 0x1b8994 <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc+0x18> */
/* @0x1b89bc mov r0, r4 */
/* @0x1b89c0 pop {r3, r4, r5, pc} */
/* @0x1b89c4 mov r0, r5 */
/* @0x1b89c8 pop {r3, r4, r5, pc} */

/* ── FUNC 0x1b89cc · CLayerManager::GetNumLayersInRoom(CRoom*) · size=12 · insn=3 */
/* @0x1b89cc cmp r0, #0 */
/* @0x1b89d0 ldrne r0, [r0, #0xdc] */
/* @0x1b89d4 bx lr */

/* ── FUNC 0x1b89d8 · CLayerManager::GetNthLayerInRoom(CRoom*, int) · size=80 · insn=20 */
/* @0x1b89d8 cmp r0, #0 */
/* @0x1b89dc bxeq lr */
/* @0x1b89e0 ldr r0, [r0, #0xd4] */
/* @0x1b89e4 cmp r0, #0 */
/* @0x1b89e8 bxeq lr */
/* @0x1b89ec cmp r1, #0 */
/* @0x1b89f0 blt 0x1b8a20 <_ZN13CLayerManager17GetNthLayerInRoomEP5CRoomi+0x48> */
/* @0x1b89f4 bxeq lr */
/* @0x1b89f8 mov r3, #1 */
/* @0x1b89fc ldr r0, [r0, #0x68] */
/* @0x1b8a00 cmp r0, #0 */
/* @0x1b8a04 bxeq lr */
/* @0x1b8a08 cmp r1, r3 */
/* @0x1b8a0c blt 0x1b8a20 <_ZN13CLayerManager17GetNthLayerInRoomEP5CRoomi+0x48> */
/* @0x1b8a10 cmp r3, r1 */
/* @0x1b8a14 add r3, r3, #1 */
/* @0x1b8a18 bne 0x1b89fc <_ZN13CLayerManager17GetNthLayerInRoomEP5CRoomi+0x24> */
/* @0x1b8a1c bx lr */
/* @0x1b8a20 mov r0, #0 */
/* @0x1b8a24 bx lr */

/* ── FUNC 0x1b8a28 · CLayerManager::UpdateInstanceActivation(CRoom*, CInstance*) · size=468 · insn=117 */
/* @0x1b8a28 ldr r3, [pc, #0x1c8] */
/* @0x1b8a2c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1b8a30 ldr r3, [pc, r3] */
/* @0x1b8a34 mov r8, r1 */
/* @0x1b8a38 mov r4, r0 */
/* @0x1b8a3c ldrb r3, [r3] */
/* @0x1b8a40 cmp r3, #0 */
/* @0x1b8a44 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b8a48 cmp r0, #0 */
/* @0x1b8a4c popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b8a50 cmp r1, #0 */
/* @0x1b8a54 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b8a58 ldrb r3, [r1, #0x174] */
/* @0x1b8a5c cmp r3, #0 */
/* @0x1b8a60 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b8a64 ldr r1, [r1, #0x170] */
/* @0x1b8a68 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1b8a6c subs r10, r0, #0 */
/* @0x1b8a70 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b8a74 ldr r0, [r8, #0x78] */
/* @0x1b8a78 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b8a7c ldr r12, [r4, #0x118] */
/* @0x1b8a80 ldr r1, [r4, #0x120] */
/* @0x1b8a84 bic r9, r0, #-2147483648 */
/* @0x1b8a88 and r3, r9, r12 */
/* @0x1b8a8c lsl r5, r3, #1 */
/* @0x1b8a90 add r2, r5, r3 */
/* @0x1b8a94 add r2, r1, r2, lsl #2 */
/* @0x1b8a98 ldr r2, [r2, #0x8] */
/* @0x1b8a9c cmp r2, #0 */
/* @0x1b8aa0 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b8aa4 cmp r9, r2 */
/* @0x1b8aa8 beq 0x1b8b1c <_ZN13CLayerManager24UpdateInstanceActivationEP5CRoomP9CInstance+0xf4> */
/* @0x1b8aac ldr r0, [r4, #0x110] */
/* @0x1b8ab0 and r2, r12, r2 */
/* @0x1b8ab4 add r4, r3, r0 */
/* @0x1b8ab8 rsb r2, r2, r4 */
/* @0x1b8abc tst r2, r12 */
/* @0x1b8ac0 popmi {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b8ac4 mov r4, #0 */
/* @0x1b8ac8 b 0x1b8adc <_ZN13CLayerManager24UpdateInstanceActivationEP5CRoomP9CInstance+0xb4> */
/* @0x1b8acc cmp r9, r2 */
/* @0x1b8ad0 beq 0x1b8b14 <_ZN13CLayerManager24UpdateInstanceActivationEP5CRoomP9CInstance+0xec> */
/* @0x1b8ad4 cmp r6, r4 */
/* @0x1b8ad8 poplt {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b8adc add r3, r3, #1 */
/* @0x1b8ae0 add r4, r4, #1 */
/* @0x1b8ae4 and r3, r12, r3 */
/* @0x1b8ae8 add r7, r3, r0 */
/* @0x1b8aec lsl r5, r3, #1 */
/* @0x1b8af0 add r2, r5, r3 */
/* @0x1b8af4 add r2, r1, r2, lsl #2 */
/* @0x1b8af8 ldr r2, [r2, #0x8] */
/* @0x1b8afc and r6, r12, r2 */
/* @0x1b8b00 cmp r2, #0 */
/* @0x1b8b04 rsb r6, r6, r7 */
/* @0x1b8b08 and r6, r6, r12 */
/* @0x1b8b0c bne 0x1b8acc <_ZN13CLayerManager24UpdateInstanceActivationEP5CRoomP9CInstance+0xa4> */
/* @0x1b8b10 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b8b14 cmn r3, #1 */
/* @0x1b8b18 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b8b1c add r3, r5, r3 */
/* @0x1b8b20 add r1, r1, r3, lsl #2 */
/* @0x1b8b24 cmn r1, #4 */
/* @0x1b8b28 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b8b2c ldr r2, [r1, #0x4] */
/* @0x1b8b30 cmp r2, #0 */
/* @0x1b8b34 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b8b38 ldr r3, [r2, #0x10] */
/* @0x1b8b3c cmp r3, #0 */
/* @0x1b8b40 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b8b44 ldr r0, [r2, #0x18] */
/* @0x1b8b48 ldr r3, [r2, #0x14] */
/* @0x1b8b4c cmp r0, #0 */
/* @0x1b8b50 strne r3, [r0, #0x14] */
/* @0x1b8b54 ldrne r3, [r2, #0x14] */
/* @0x1b8b58 ldrne r0, [r2, #0x18] */
/* @0x1b8b5c streq r3, [r10, #0x58] */
/* @0x1b8b60 cmp r3, #0 */
/* @0x1b8b64 streq r0, [r10, #0x5c] */
/* @0x1b8b68 strne r0, [r3, #0x18] */
/* @0x1b8b6c ldrb r2, [r8, #0x69] */
/* @0x1b8b70 ldr r3, [r10, #0x60] */
/* @0x1b8b74 cmp r2, #0 */
/* @0x1b8b78 sub r0, r3, #1 */
/* @0x1b8b7c str r0, [r10, #0x60] */
/* @0x1b8b80 beq 0x1b8bc0 <_ZN13CLayerManager24UpdateInstanceActivationEP5CRoomP9CInstance+0x198> */
/* @0x1b8b84 ldr r0, [r10, #0x5c] */
/* @0x1b8b88 ldr r2, [r1, #0x4] */
/* @0x1b8b8c cmp r0, #0 */
/* @0x1b8b90 str r3, [r10, #0x60] */
/* @0x1b8b94 strne r2, [r0, #0x14] */
/* @0x1b8b98 movne r3, #0 */
/* @0x1b8b9c ldrne r1, [r10, #0x5c] */
/* @0x1b8ba0 streq r2, [r10, #0x5c] */
/* @0x1b8ba4 streq r2, [r10, #0x58] */
/* @0x1b8ba8 strne r1, [r2, #0x18] */
/* @0x1b8bac streq r0, [r2, #0x18] */
/* @0x1b8bb0 strne r2, [r10, #0x5c] */
/* @0x1b8bb4 streq r0, [r2, #0x14] */
/* @0x1b8bb8 strne r3, [r2, #0x14] */
/* @0x1b8bbc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b8bc0 ldr r0, [r10, #0x58] */
/* @0x1b8bc4 ldr r1, [r1, #0x4] */
/* @0x1b8bc8 cmp r0, #0 */
/* @0x1b8bcc str r3, [r10, #0x60] */
/* @0x1b8bd0 strne r1, [r0, #0x18] */
/* @0x1b8bd4 ldrne r3, [r10, #0x58] */
/* @0x1b8bd8 streq r1, [r10, #0x5c] */
/* @0x1b8bdc streq r1, [r10, #0x58] */
/* @0x1b8be0 strne r3, [r1, #0x14] */
/* @0x1b8be4 streq r0, [r1, #0x18] */
/* @0x1b8be8 strne r1, [r10, #0x58] */
/* @0x1b8bec streq r0, [r1, #0x14] */
/* @0x1b8bf0 strne r2, [r1, #0x18] */
/* @0x1b8bf4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b8bf8 .word 0x00234ef4 */

/* ── FUNC 0x1b8bfc · CLayerManager::SortDeactivatedInstances(CLayer*) · size=188 · insn=47 */
/* @0x1b8bfc cmp r0, #0 */
/* @0x1b8c00 str r4, [sp, #-0x4]! */
/* @0x1b8c04 beq 0x1b8cb0 <_ZN13CLayerManager24SortDeactivatedInstancesEP6CLayer+0xb4> */
/* @0x1b8c08 ldr r3, [r0, #0x5c] */
/* @0x1b8c0c cmp r3, #0 */
/* @0x1b8c10 beq 0x1b8cb0 <_ZN13CLayerManager24SortDeactivatedInstancesEP6CLayer+0xb4> */
/* @0x1b8c14 mov r4, #0 */
/* @0x1b8c18 b 0x1b8c28 <_ZN13CLayerManager24SortDeactivatedInstancesEP6CLayer+0x2c> */
/* @0x1b8c1c cmp r2, #0 */
/* @0x1b8c20 beq 0x1b8cb0 <_ZN13CLayerManager24SortDeactivatedInstancesEP6CLayer+0xb4> */
/* @0x1b8c24 mov r3, r2 */
/* @0x1b8c28 ldr r1, [r3] */
/* @0x1b8c2c ldr r2, [r3, #0x18] */
/* @0x1b8c30 cmp r1, #2 */
/* @0x1b8c34 bne 0x1b8c1c <_ZN13CLayerManager24SortDeactivatedInstancesEP6CLayer+0x20> */
/* @0x1b8c38 ldr r1, [r3, #0x20] */
/* @0x1b8c3c cmp r1, #0 */
/* @0x1b8c40 beq 0x1b8c1c <_ZN13CLayerManager24SortDeactivatedInstancesEP6CLayer+0x20> */
/* @0x1b8c44 ldrb r1, [r1, #0x69] */
/* @0x1b8c48 cmp r1, #0 */
/* @0x1b8c4c beq 0x1b8c1c <_ZN13CLayerManager24SortDeactivatedInstancesEP6CLayer+0x20> */
/* @0x1b8c50 cmp r2, #0 */
/* @0x1b8c54 ldrne r1, [r3, #0x14] */
/* @0x1b8c58 moveq r1, r2 */
/* @0x1b8c5c ldreq r12, [r3, #0x14] */
/* @0x1b8c60 strne r1, [r2, #0x14] */
/* @0x1b8c64 ldrne r12, [r3, #0x14] */
/* @0x1b8c68 ldrne r1, [r3, #0x18] */
/* @0x1b8c6c streq r12, [r0, #0x58] */
/* @0x1b8c70 cmp r12, #0 */
/* @0x1b8c74 streq r1, [r0, #0x5c] */
/* @0x1b8c78 strne r1, [r12, #0x18] */
/* @0x1b8c7c ldrne r1, [r0, #0x5c] */
/* @0x1b8c80 cmp r1, #0 */
/* @0x1b8c84 streq r3, [r0, #0x5c] */
/* @0x1b8c88 strne r3, [r1, #0x14] */
/* @0x1b8c8c ldrne r1, [r0, #0x5c] */
/* @0x1b8c90 streq r3, [r0, #0x58] */
/* @0x1b8c94 streq r1, [r3, #0x18] */
/* @0x1b8c98 strne r1, [r3, #0x18] */
/* @0x1b8c9c streq r1, [r3, #0x14] */
/* @0x1b8ca0 strne r3, [r0, #0x5c] */
/* @0x1b8ca4 strne r4, [r3, #0x14] */
/* @0x1b8ca8 cmp r2, #0 */
/* @0x1b8cac bne 0x1b8c24 <_ZN13CLayerManager24SortDeactivatedInstancesEP6CLayer+0x28> */
/* @0x1b8cb0 ldr r4, [sp], #4 */
/* @0x1b8cb4 bx lr */

/* ── FUNC 0x1b8cb8 · CLayerManager::GetLayerIDForInstance(CRoom*, int) · size=224 · insn=56 */
/* @0x1b8cb8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1b8cbc subs r5, r0, #0 */
/* @0x1b8cc0 beq 0x1b8d60 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0xa8> */
/* @0x1b8cc4 mov r0, r1 */
/* @0x1b8cc8 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b8ccc ldr r1, [r5, #0x118] */
/* @0x1b8cd0 ldr r7, [r5, #0x120] */
/* @0x1b8cd4 bic r8, r0, #-2147483648 */
/* @0x1b8cd8 and r3, r8, r1 */
/* @0x1b8cdc lsl r4, r3, #1 */
/* @0x1b8ce0 add r2, r4, r3 */
/* @0x1b8ce4 add r2, r7, r2, lsl #2 */
/* @0x1b8ce8 ldr r2, [r2, #0x8] */
/* @0x1b8cec cmp r2, #0 */
/* @0x1b8cf0 beq 0x1b8d60 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0xa8> */
/* @0x1b8cf4 cmp r8, r2 */
/* @0x1b8cf8 beq 0x1b8d70 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0xb8> */
/* @0x1b8cfc ldr r0, [r5, #0x110] */
/* @0x1b8d00 and r2, r1, r2 */
/* @0x1b8d04 add r12, r3, r0 */
/* @0x1b8d08 rsb r2, r2, r12 */
/* @0x1b8d0c tst r2, r1 */
/* @0x1b8d10 bmi 0x1b8d60 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0xa8> */
/* @0x1b8d14 mov r12, #0 */
/* @0x1b8d18 b 0x1b8d2c <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0x74> */
/* @0x1b8d1c cmp r8, r2 */
/* @0x1b8d20 beq 0x1b8d68 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0xb0> */
/* @0x1b8d24 cmp r5, r12 */
/* @0x1b8d28 blt 0x1b8d60 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0xa8> */
/* @0x1b8d2c add r3, r3, #1 */
/* @0x1b8d30 add r12, r12, #1 */
/* @0x1b8d34 and r3, r1, r3 */
/* @0x1b8d38 add r6, r3, r0 */
/* @0x1b8d3c lsl r4, r3, #1 */
/* @0x1b8d40 add r2, r4, r3 */
/* @0x1b8d44 add r2, r7, r2, lsl #2 */
/* @0x1b8d48 ldr r2, [r2, #0x8] */
/* @0x1b8d4c and r5, r1, r2 */
/* @0x1b8d50 cmp r2, #0 */
/* @0x1b8d54 rsb r5, r5, r6 */
/* @0x1b8d58 and r5, r5, r1 */
/* @0x1b8d5c bne 0x1b8d1c <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0x64> */
/* @0x1b8d60 mvn r0, #0 */
/* @0x1b8d64 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1b8d68 cmn r3, #1 */
/* @0x1b8d6c beq 0x1b8d60 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0xa8> */
/* @0x1b8d70 add r3, r4, r3 */
/* @0x1b8d74 add r7, r7, r3, lsl #2 */
/* @0x1b8d78 cmn r7, #4 */
/* @0x1b8d7c beq 0x1b8d60 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0xa8> */
/* @0x1b8d80 ldr r3, [r7, #0x4] */
/* @0x1b8d84 ldr r3, [r3, #0x10] */
/* @0x1b8d88 cmp r3, #0 */
/* @0x1b8d8c beq 0x1b8d60 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0xa8> */
/* @0x1b8d90 ldr r0, [r3] */
/* @0x1b8d94 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x1b8d98 · CLayerManager::CleanBackgroundElementRuntimeData(CLayerBackgroundElement*) · size=4 · insn=1 */
/* @0x1b8d98 bx lr */

/* ── FUNC 0x1b8d9c · CLayerManager::CleanInstanceElementRuntimeData(CLayerInstanceElement*) · size=112 · insn=28 */
/* @0x1b8d9c ldr r1, [r0, #0x1c] */
/* @0x1b8da0 cmp r1, #0 */
/* @0x1b8da4 blt 0x1b8dfc <_ZN13CLayerManager31CleanInstanceElementRuntimeDataEP21CLayerInstanceElement+0x60> */
/* @0x1b8da8 ldr r3, [pc, #0x58] */
/* @0x1b8dac ldr r3, [pc, r3] */
/* @0x1b8db0 ldr r2, [r3, #0x4] */
/* @0x1b8db4 ldr r3, [r3] */
/* @0x1b8db8 and r2, r1, r2 */
/* @0x1b8dbc ldr r3, [r3, r2, lsl #3] */
/* @0x1b8dc0 cmp r3, #0 */
/* @0x1b8dc4 bne 0x1b8dd8 <_ZN13CLayerManager31CleanInstanceElementRuntimeDataEP21CLayerInstanceElement+0x3c> */
/* @0x1b8dc8 b 0x1b8dfc <_ZN13CLayerManager31CleanInstanceElementRuntimeDataEP21CLayerInstanceElement+0x60> */
/* @0x1b8dcc ldr r3, [r3, #0x4] */
/* @0x1b8dd0 cmp r3, #0 */
/* @0x1b8dd4 beq 0x1b8dfc <_ZN13CLayerManager31CleanInstanceElementRuntimeDataEP21CLayerInstanceElement+0x60> */
/* @0x1b8dd8 ldr r2, [r3, #0x8] */
/* @0x1b8ddc cmp r1, r2 */
/* @0x1b8de0 bne 0x1b8dcc <_ZN13CLayerManager31CleanInstanceElementRuntimeDataEP21CLayerInstanceElement+0x30> */
/* @0x1b8de4 ldr r3, [r3, #0xc] */
/* @0x1b8de8 cmp r3, #0 */
/* @0x1b8dec movne r1, #0 */
/* @0x1b8df0 mvnne r2, #0 */
/* @0x1b8df4 strbne r1, [r3, #0x174] */
/* @0x1b8df8 strne r2, [r3, #0x170] */
/* @0x1b8dfc mov r3, #0 */
/* @0x1b8e00 str r3, [r0, #0x20] */
/* @0x1b8e04 bx lr */
/* @0x1b8e08 mlaeq r3, r8, lr, r4 */
