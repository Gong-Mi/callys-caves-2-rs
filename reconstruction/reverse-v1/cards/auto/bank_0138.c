/* libyoyo.so 覆盖卡组 0138
 * 函数 0x1a6e9c..0x1a7be0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1a6e9c · CPath::CPath() · size=52 · insn=13 */
/* @0x1a6e9c mov r1, #1 */
/* @0x1a6ea0 mov r2, #4 */
/* @0x1a6ea4 strb r1, [r0, #0x18] */
/* @0x1a6ea8 str r2, [r0, #0x1c] */
/* @0x1a6eac mov r2, #0 */
/* @0x1a6eb0 str r2, [r0, #0x10] */
/* @0x1a6eb4 str r2, [r0, #0x4] */
/* @0x1a6eb8 str r2, [r0] */
/* @0x1a6ebc str r2, [r0, #0x20] */
/* @0x1a6ec0 str r2, [r0, #0xc] */
/* @0x1a6ec4 str r2, [r0, #0x8] */
/* @0x1a6ec8 str r2, [r0, #0x14] */
/* @0x1a6ecc bx lr */

/* ── FUNC 0x1a6e9c · CPath::CPath() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1a6ed0 · CPath::Assign(CPath*) · size=200 · insn=50 */
/* @0x1a6ed0 push {r3, r4, r5, r6, r7, lr} */
/* @0x1a6ed4 mov r4, r0 */
/* @0x1a6ed8 mov r6, r1 */
/* @0x1a6edc ldr r0, [r0, #0x4] */
/* @0x1a6ee0 ldr r1, [r1, #0x14] */
/* @0x1a6ee4 ldrb r2, [r6, #0x18] */
/* @0x1a6ee8 cmp r0, #0 */
/* @0x1a6eec ldr r3, [r6, #0x1c] */
/* @0x1a6ef0 str r1, [r4, #0x14] */
/* @0x1a6ef4 strb r2, [r4, #0x18] */
/* @0x1a6ef8 str r3, [r4, #0x1c] */
/* @0x1a6efc beq 0x1a6f10 <_ZN5CPath6AssignEPS_+0x40> */
/* @0x1a6f00 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a6f04 mov r3, #0 */
/* @0x1a6f08 str r3, [r4, #0x4] */
/* @0x1a6f0c str r3, [r4] */
/* @0x1a6f10 ldr r1, [r6, #0x10] */
/* @0x1a6f14 movw r3, #0x15e */
/* @0x1a6f18 ldr r2, [pc, #0x74] */
/* @0x1a6f1c add r0, r4, #4 */
/* @0x1a6f20 add r1, r1, r1, lsl #1 */
/* @0x1a6f24 add r2, pc, r2 */
/* @0x1a6f28 lsl r1, r1, #2 */
/* @0x1a6f2c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1a6f30 ldr r3, [r6, #0x10] */
/* @0x1a6f34 cmp r3, #0 */
/* @0x1a6f38 str r3, [r4] */
/* @0x1a6f3c str r3, [r4, #0x10] */
/* @0x1a6f40 movgt r3, #0 */
/* @0x1a6f44 movgt r12, r3 */
/* @0x1a6f48 ble 0x1a6f88 <_ZN5CPath6AssignEPS_+0xb8> */
/* @0x1a6f4c ldr r2, [r6, #0x4] */
/* @0x1a6f50 add r12, r12, #1 */
/* @0x1a6f54 ldr r5, [r4, #0x4] */
/* @0x1a6f58 add r2, r2, r3 */
/* @0x1a6f5c add r0, r5, r3 */
/* @0x1a6f60 ldr r7, [r2] */
/* @0x1a6f64 ldr r1, [r2, #0x4] */
/* @0x1a6f68 ldr r2, [r2, #0x8] */
/* @0x1a6f6c str r7, [r5, r3] */
/* @0x1a6f70 add r3, r3, #12 */
/* @0x1a6f74 str r1, [r0, #0x4] */
/* @0x1a6f78 str r2, [r0, #0x8] */
/* @0x1a6f7c ldr r2, [r4, #0x10] */
/* @0x1a6f80 cmp r2, r12 */
/* @0x1a6f84 bgt 0x1a6f4c <_ZN5CPath6AssignEPS_+0x7c> */
/* @0x1a6f88 mov r0, r4 */
/* @0x1a6f8c pop {r3, r4, r5, r6, r7, lr} */
/* @0x1a6f90 b 0x1a6e30 <_ZN5CPath15ComputeInternalEv> */
/* @0x1a6f94 ldrheq r6, [r10], -r4 */

/* ── FUNC 0x1a6f98 · CPath::Clear() · size=80 · insn=20 */
/* @0x1a6f98 push {r4, lr} */
/* @0x1a6f9c mov r4, r0 */
/* @0x1a6fa0 ldr r0, [r0, #0x4] */
/* @0x1a6fa4 cmp r0, #0 */
/* @0x1a6fa8 beq 0x1a6fb0 <_ZN5CPath5ClearEv+0x18> */
/* @0x1a6fac bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a6fb0 ldr r0, [r4, #0xc] */
/* @0x1a6fb4 cmp r0, #0 */
/* @0x1a6fb8 beq 0x1a6fc0 <_ZN5CPath5ClearEv+0x28> */
/* @0x1a6fbc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a6fc0 mov r3, #0 */
/* @0x1a6fc4 mov r0, r4 */
/* @0x1a6fc8 str r3, [r4, #0x4] */
/* @0x1a6fcc str r3, [r4, #0xc] */
/* @0x1a6fd0 str r3, [r4, #0x10] */
/* @0x1a6fd4 str r3, [r4] */
/* @0x1a6fd8 str r3, [r4, #0x20] */
/* @0x1a6fdc str r3, [r4, #0x8] */
/* @0x1a6fe0 pop {r4, lr} */
/* @0x1a6fe4 b 0x1a6e30 <_ZN5CPath15ComputeInternalEv> */

/* ── FUNC 0x1a6fe8 · CPath::~CPath() · size=20 · insn=5 */
/* @0x1a6fe8 push {r4, lr} */
/* @0x1a6fec mov r4, r0 */
/* @0x1a6ff0 bl 0x1a6f98 <_ZN5CPath5ClearEv> */
/* @0x1a6ff4 mov r0, r4 */
/* @0x1a6ff8 pop {r4, pc} */

/* ── FUNC 0x1a6fe8 · CPath::~CPath() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1a6ffc · CPath::Free() · size=28 · insn=7 */
/* @0x1a6ffc push {r4, lr} */
/* @0x1a7000 subs r4, r0, #0 */
/* @0x1a7004 popeq {r4, pc} */
/* @0x1a7008 bl 0x1a6fe8 <_ZN5CPathD2Ev> */
/* @0x1a700c mov r0, r4 */
/* @0x1a7010 pop {r4, lr} */
/* @0x1a7014 b 0x27d1d0 <_ZdlPv> */

/* ── FUNC 0x1a7018 · CPath::LoadFromStream(CStream*) · size=264 · insn=66 */
/* @0x1a7018 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1a701c mov r4, r0 */
/* @0x1a7020 mov r0, r1 */
/* @0x1a7024 mov r6, r1 */
/* @0x1a7028 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1a702c movw r3, #0x212 */
/* @0x1a7030 cmp r0, r3 */
/* @0x1a7034 beq 0x1a7040 <_ZN5CPath14LoadFromStreamEP7CStream+0x28> */
/* @0x1a7038 mov r0, #0 */
/* @0x1a703c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1a7040 mov r0, r6 */
/* @0x1a7044 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1a7048 str r0, [r4, #0x14] */
/* @0x1a704c mov r0, r6 */
/* @0x1a7050 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1a7054 strb r0, [r4, #0x18] */
/* @0x1a7058 mov r0, r6 */
/* @0x1a705c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1a7060 str r0, [r4, #0x1c] */
/* @0x1a7064 mov r0, r6 */
/* @0x1a7068 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1a706c ldr r2, [pc, #0xa8] */
/* @0x1a7070 movw r3, #0x1ab */
/* @0x1a7074 add r2, pc, r2 */
/* @0x1a7078 add r1, r0, r0, lsl #1 */
/* @0x1a707c str r0, [r4, #0x10] */
/* @0x1a7080 add r0, r4, #4 */
/* @0x1a7084 lsl r1, r1, #2 */
/* @0x1a7088 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1a708c ldr r3, [r4, #0x10] */
/* @0x1a7090 cmp r3, #0 */
/* @0x1a7094 str r3, [r4] */
/* @0x1a7098 movgt r5, #0 */
/* @0x1a709c movgt r7, r5 */
/* @0x1a70a0 ble 0x1a710c <_ZN5CPath14LoadFromStreamEP7CStream+0xf4> */
/* @0x1a70a4 mov r0, r6 */
/* @0x1a70a8 ldr r8, [r4, #0x4] */
/* @0x1a70ac bl 0x20187c <_ZN7CStream8ReadRealEv> */
/* @0x1a70b0 ldr r9, [r4, #0x4] */
/* @0x1a70b4 add r8, r8, r5 */
/* @0x1a70b8 add r7, r7, #1 */
/* @0x1a70bc add r9, r9, r5 */
/* @0x1a70c0 vmov d6, r0, r1 */
/* @0x1a70c4 mov r0, r6 */
/* @0x1a70c8 vcvt.f32.f64 s15, d6 */
/* @0x1a70cc vstr s15, [r8] */
/* @0x1a70d0 bl 0x20187c <_ZN7CStream8ReadRealEv> */
/* @0x1a70d4 ldr r8, [r4, #0x4] */
/* @0x1a70d8 add r8, r8, r5 */
/* @0x1a70dc add r5, r5, #12 */
/* @0x1a70e0 vmov d6, r0, r1 */
/* @0x1a70e4 mov r0, r6 */
/* @0x1a70e8 vcvt.f32.f64 s15, d6 */
/* @0x1a70ec vstr s15, [r9, #4] */
/* @0x1a70f0 bl 0x20187c <_ZN7CStream8ReadRealEv> */
/* @0x1a70f4 ldr r3, [r4, #0x10] */
/* @0x1a70f8 cmp r3, r7 */
/* @0x1a70fc vmov d6, r0, r1 */
/* @0x1a7100 vcvt.f32.f64 s15, d6 */
/* @0x1a7104 vstr s15, [r8, #8] */
/* @0x1a7108 bgt 0x1a70a4 <_ZN5CPath14LoadFromStreamEP7CStream+0x8c> */
/* @0x1a710c mov r0, r4 */
/* @0x1a7110 bl 0x1a6e30 <_ZN5CPath15ComputeInternalEv> */
/* @0x1a7114 mov r0, #1 */
/* @0x1a7118 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1a711c andseq r6, r10, r4, rrx */

/* ── FUNC 0x1a7120 · CPath::LoadFromChunk(YYPath*, unsigned char*) · size=176 · insn=44 */
/* @0x1a7120 ldr r2, [r1, #0x10] */
/* @0x1a7124 mov r3, #460 */
/* @0x1a7128 ldr r12, [r1, #0x8] */
/* @0x1a712c push {r4, r5, r6, lr} */
/* @0x1a7130 mov r5, r0 */
/* @0x1a7134 ldr r4, [r1, #0x4] */
/* @0x1a7138 adds r12, r12, #0 */
/* @0x1a713c ldr lr, [r1, #0xc] */
/* @0x1a7140 mov r6, r1 */
/* @0x1a7144 str r2, [r5, #0x10] */
/* @0x1a7148 add r1, r2, r2, lsl #1 */
/* @0x1a714c ldr r2, [pc, #0x78] */
/* @0x1a7150 movne r12, #1 */
/* @0x1a7154 str r4, [r5, #0x14] */
/* @0x1a7158 add r0, r0, #4 */
/* @0x1a715c str lr, [r5, #0x1c] */
/* @0x1a7160 lsl r1, r1, #2 */
/* @0x1a7164 strb r12, [r5, #0x18] */
/* @0x1a7168 add r2, pc, r2 */
/* @0x1a716c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1a7170 ldr r4, [r5, #0x10] */
/* @0x1a7174 cmp r4, #0 */
/* @0x1a7178 str r4, [r5] */
/* @0x1a717c ble 0x1a71bc <_ZN5CPath13LoadFromChunkEP6YYPathPh+0x9c> */
/* @0x1a7180 add r4, r4, r4, lsl #1 */
/* @0x1a7184 ldr r2, [r5, #0x4] */
/* @0x1a7188 add r3, r6, #32 */
/* @0x1a718c add r4, r6, r4, lsl #2 */
/* @0x1a7190 add r2, r2, #8 */
/* @0x1a7194 add r4, r4, #32 */
/* @0x1a7198 ldr lr, [r3, #-0xc] */
/* @0x1a719c add r3, r3, #12 */
/* @0x1a71a0 ldr r12, [r3, #-0x14] */
/* @0x1a71a4 ldr r1, [r3, #-0x10] */
/* @0x1a71a8 cmp r3, r4 */
/* @0x1a71ac str lr, [r2, #-0x8] */
/* @0x1a71b0 str r12, [r2, #-0x4] */
/* @0x1a71b4 str r1, [r2], #12 */
/* @0x1a71b8 bne 0x1a7198 <_ZN5CPath13LoadFromChunkEP6YYPathPh+0x78> */
/* @0x1a71bc mov r0, r5 */
/* @0x1a71c0 bl 0x1a6e30 <_ZN5CPath15ComputeInternalEv> */
/* @0x1a71c4 mov r0, #1 */
/* @0x1a71c8 pop {r4, r5, r6, pc} */
/* @0x1a71cc andseq r5, r10, r0, ror pc */

/* ── FUNC 0x1a71d0 · CPath::InsertPoint(int, float, float, float) · size=240 · insn=60 */
/* @0x1a71d0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1a71d4 vpush {d8} */
/* @0x1a71d8 subs r9, r1, #0 */
/* @0x1a71dc vldr s16, [sp, #48] */
/* @0x1a71e0 mov r8, r0 */
/* @0x1a71e4 mov r10, r2 */
/* @0x1a71e8 mov r11, r3 */
/* @0x1a71ec blt 0x1a7284 <_ZN5CPath11InsertPointEifff+0xb4> */
/* @0x1a71f0 ldr r3, [r0, #0x10] */
/* @0x1a71f4 cmp r9, r3 */
/* @0x1a71f8 bgt 0x1a7284 <_ZN5CPath11InsertPointEifff+0xb4> */
/* @0x1a71fc ldr r2, [r0] */
/* @0x1a7200 add r6, r3, #1 */
/* @0x1a7204 str r6, [r0, #0x10] */
/* @0x1a7208 cmp r6, r2 */
/* @0x1a720c bgt 0x1a728c <_ZN5CPath11InsertPointEifff+0xbc> */
/* @0x1a7210 sub r6, r6, #1 */
/* @0x1a7214 cmp r9, r6 */
/* @0x1a7218 addlt r12, r6, r6, lsl #1 */
/* @0x1a721c lsllt r12, r12, #2 */
/* @0x1a7220 bge 0x1a725c <_ZN5CPath11InsertPointEifff+0x8c> */
/* @0x1a7224 ldr r4, [r8, #0x4] */
/* @0x1a7228 sub r3, r12, #12 */
/* @0x1a722c sub r6, r6, #1 */
/* @0x1a7230 add r5, r4, r3 */
/* @0x1a7234 add r7, r4, r12 */
/* @0x1a7238 cmp r6, r9 */
/* @0x1a723c ldr r0, [r5] */
/* @0x1a7240 ldr r1, [r5, #0x4] */
/* @0x1a7244 ldr r2, [r5, #0x8] */
/* @0x1a7248 str r0, [r4, r12] */
/* @0x1a724c mov r12, r3 */
/* @0x1a7250 str r1, [r7, #0x4] */
/* @0x1a7254 str r2, [r7, #0x8] */
/* @0x1a7258 bne 0x1a7224 <_ZN5CPath11InsertPointEifff+0x54> */
/* @0x1a725c ldr r3, [r8, #0x4] */
/* @0x1a7260 add r9, r9, r9, lsl #1 */
/* @0x1a7264 mov r0, r8 */
/* @0x1a7268 add r9, r3, r9, lsl #2 */
/* @0x1a726c vstr s16, [r9, #8] */
/* @0x1a7270 vpop {d8} */
/* @0x1a7274 str r10, [r9] */
/* @0x1a7278 str r11, [r9, #0x4] */
/* @0x1a727c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1a7280 b 0x1a6e30 <_ZN5CPath15ComputeInternalEv> */
/* @0x1a7284 vpop {d8} */
/* @0x1a7288 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1a728c add r1, r3, #6 */
/* @0x1a7290 ldr r2, [pc, #0x24] */
/* @0x1a7294 movw r3, #0x201 */
/* @0x1a7298 add r0, r0, #4 */
/* @0x1a729c add r1, r1, r1, lsl #1 */
/* @0x1a72a0 add r2, pc, r2 */
/* @0x1a72a4 lsl r1, r1, #2 */
/* @0x1a72a8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1a72ac ldr r6, [r8, #0x10] */
/* @0x1a72b0 add r3, r6, #5 */
/* @0x1a72b4 str r3, [r8] */
/* @0x1a72b8 b 0x1a7210 <_ZN5CPath11InsertPointEifff+0x40> */
/* @0x1a72bc andseq r5, r10, r8, lsr lr */

/* ── FUNC 0x1a72c0 · CPath::AddPoint(float, float, float) · size=56 · insn=14 */
/* @0x1a72c0 push {r4, lr} */
/* @0x1a72c4 sub sp, sp, #8 */
/* @0x1a72c8 mov lr, r1 */
/* @0x1a72cc mov r12, r2 */
/* @0x1a72d0 ldr r1, [r0, #0x10] */
/* @0x1a72d4 mov r2, lr */
/* @0x1a72d8 str r3, [sp] */
/* @0x1a72dc mov r3, r12 */
/* @0x1a72e0 mov r4, r0 */
/* @0x1a72e4 bl 0x1a71d0 <_ZN5CPath11InsertPointEifff> */
/* @0x1a72e8 ldr r0, [r4, #0x10] */
/* @0x1a72ec sub r0, r0, #1 */
/* @0x1a72f0 add sp, sp, #8 */
/* @0x1a72f4 pop {r4, pc} */

/* ── FUNC 0x1a72f8 · CPath::ChangePoint(int, float, float, float) · size=68 · insn=17 */
/* @0x1a72f8 cmp r1, #0 */
/* @0x1a72fc push {r4, r5} */
/* @0x1a7300 ldr r5, [sp, #0x8] */
/* @0x1a7304 blt 0x1a7314 <_ZN5CPath11ChangePointEifff+0x1c> */
/* @0x1a7308 ldr r4, [r0, #0x10] */
/* @0x1a730c cmp r1, r4 */
/* @0x1a7310 blt 0x1a731c <_ZN5CPath11ChangePointEifff+0x24> */
/* @0x1a7314 pop {r4, r5} */
/* @0x1a7318 bx lr */
/* @0x1a731c ldr r12, [r0, #0x4] */
/* @0x1a7320 add r1, r1, r1, lsl #1 */
/* @0x1a7324 add r1, r12, r1, lsl #2 */
/* @0x1a7328 str r5, [r1, #0x8] */
/* @0x1a732c str r2, [r1] */
/* @0x1a7330 str r3, [r1, #0x4] */
/* @0x1a7334 pop {r4, r5} */
/* @0x1a7338 b 0x1a6e30 <_ZN5CPath15ComputeInternalEv> */

/* ── FUNC 0x1a733c · CPath::DeletePoint(int) · size=128 · insn=32 */
/* @0x1a733c cmp r1, #0 */
/* @0x1a7340 push {r4, r5, r6, r7} */
/* @0x1a7344 blt 0x1a73b4 <_ZN5CPath11DeletePointEi+0x78> */
/* @0x1a7348 ldr r2, [r0, #0x10] */
/* @0x1a734c cmp r1, r2 */
/* @0x1a7350 bge 0x1a73b4 <_ZN5CPath11DeletePointEi+0x78> */
/* @0x1a7354 sub r2, r2, #1 */
/* @0x1a7358 cmp r1, r2 */
/* @0x1a735c bge 0x1a73a8 <_ZN5CPath11DeletePointEi+0x6c> */
/* @0x1a7360 add r3, r1, r1, lsl #1 */
/* @0x1a7364 lsl r3, r3, #2 */
/* @0x1a7368 ldr r2, [r0, #0x4] */
/* @0x1a736c add r5, r3, #12 */
/* @0x1a7370 add r1, r1, #1 */
/* @0x1a7374 add r12, r2, r5 */
/* @0x1a7378 add r4, r2, r3 */
/* @0x1a737c ldr r7, [r12] */
/* @0x1a7380 ldr r6, [r12, #0x4] */
/* @0x1a7384 ldr r12, [r12, #0x8] */
/* @0x1a7388 str r7, [r2, r3] */
/* @0x1a738c mov r3, r5 */
/* @0x1a7390 str r6, [r4, #0x4] */
/* @0x1a7394 str r12, [r4, #0x8] */
/* @0x1a7398 ldr r2, [r0, #0x10] */
/* @0x1a739c sub r2, r2, #1 */
/* @0x1a73a0 cmp r2, r1 */
/* @0x1a73a4 bgt 0x1a7368 <_ZN5CPath11DeletePointEi+0x2c> */
/* @0x1a73a8 str r2, [r0, #0x10] */
/* @0x1a73ac pop {r4, r5, r6, r7} */
/* @0x1a73b0 b 0x1a6e30 <_ZN5CPath15ComputeInternalEv> */
/* @0x1a73b4 pop {r4, r5, r6, r7} */
/* @0x1a73b8 bx lr */

/* ── FUNC 0x1a73bc · CPath::GetPosition(float, float&, float&, float&) · size=476 · insn=119 */
/* @0x1a73bc push {r4, r5, r6} */
/* @0x1a73c0 vmov s15, r1 */
/* @0x1a73c4 ldr r12, [r0, #0x20] */
/* @0x1a73c8 mov r4, #0 */
/* @0x1a73cc ldr r5, [sp, #0xc] */
/* @0x1a73d0 mov r6, #0 */
/* @0x1a73d4 cmp r12, #0 */
/* @0x1a73d8 str r4, [r2] */
/* @0x1a73dc movt r6, #0x42c8 */
/* @0x1a73e0 str r4, [r3] */
/* @0x1a73e4 str r6, [r5] */
/* @0x1a73e8 ble 0x1a7464 <_ZN5CPath11GetPositionEfRfS0_S0_+0xa8> */
/* @0x1a73ec cmp r12, #1 */
/* @0x1a73f0 beq 0x1a7448 <_ZN5CPath11GetPositionEfRfS0_S0_+0x8c> */
/* @0x1a73f4 vldr s14, [r0, #36] */
/* @0x1a73f8 vcmp.f32 s14, #0 */
/* @0x1a73fc vmrs APSR_nzcv, fpscr */
/* @0x1a7400 beq 0x1a7448 <_ZN5CPath11GetPositionEfRfS0_S0_+0x8c> */
/* @0x1a7404 vcmpe.f32 s15, #0 */
/* @0x1a7408 vmrs APSR_nzcv, fpscr */
/* @0x1a740c bmi 0x1a7448 <_ZN5CPath11GetPositionEfRfS0_S0_+0x8c> */
/* @0x1a7410 vmov.f32 s13, #1.000000e+00 */
/* @0x1a7414 vcmpe.f32 s15, s13 */
/* @0x1a7418 vmrs APSR_nzcv, fpscr */
/* @0x1a741c ble 0x1a746c <_ZN5CPath11GetPositionEfRfS0_S0_+0xb0> */
/* @0x1a7420 ldr r1, [r0, #0xc] */
/* @0x1a7424 sub r12, r12, #-268435455 */
/* @0x1a7428 add r12, r1, r12, lsl #4 */
/* @0x1a742c ldr r1, [r12] */
/* @0x1a7430 str r1, [r2] */
/* @0x1a7434 ldr r2, [r12, #0x4] */
/* @0x1a7438 str r2, [r3] */
/* @0x1a743c ldr r3, [r12, #0x8] */
/* @0x1a7440 str r3, [r5] */
/* @0x1a7444 b 0x1a7464 <_ZN5CPath11GetPositionEfRfS0_S0_+0xa8> */
/* @0x1a7448 ldr r1, [r0, #0xc] */
/* @0x1a744c ldr r0, [r1] */
/* @0x1a7450 str r0, [r2] */
/* @0x1a7454 ldr r2, [r1, #0x4] */
/* @0x1a7458 str r2, [r3] */
/* @0x1a745c ldr r3, [r1, #0x8] */
/* @0x1a7460 str r3, [r5] */
/* @0x1a7464 pop {r4, r5, r6} */
/* @0x1a7468 bx lr */
/* @0x1a746c vcmp.f32 s15, #0 */
/* @0x1a7470 vmrs APSR_nzcv, fpscr */
/* @0x1a7474 beq 0x1a7448 <_ZN5CPath11GetPositionEfRfS0_S0_+0x8c> */
/* @0x1a7478 vcmp.f32 s15, s13 */
/* @0x1a747c vmrs APSR_nzcv, fpscr */
/* @0x1a7480 beq 0x1a7420 <_ZN5CPath11GetPositionEfRfS0_S0_+0x64> */
/* @0x1a7484 cmp r12, #2 */
/* @0x1a7488 ldr r6, [r0, #0xc] */
/* @0x1a748c vmul.f32 s14, s14, s15 */
/* @0x1a7490 moveq r1, #0 */
/* @0x1a7494 addeq r12, r6, #16 */
/* @0x1a7498 beq 0x1a74f4 <_ZN5CPath11GetPositionEfRfS0_S0_+0x138> */
/* @0x1a749c vldr s15, [r6, #28] */
/* @0x1a74a0 vcmpe.f32 s14, s15 */
/* @0x1a74a4 vmrs APSR_nzcv, fpscr */
/* @0x1a74a8 addlt r12, r6, #16 */
/* @0x1a74ac movlt r1, #0 */
/* @0x1a74b0 blt 0x1a74f4 <_ZN5CPath11GetPositionEfRfS0_S0_+0x138> */
/* @0x1a74b4 sub r4, r12, #2 */
/* @0x1a74b8 add r0, r6, #32 */
/* @0x1a74bc mov r1, #0 */
/* @0x1a74c0 b 0x1a74d4 <_ZN5CPath11GetPositionEfRfS0_S0_+0x118> */
/* @0x1a74c4 vldr s15, [r0, #-4] */
/* @0x1a74c8 vcmpe.f32 s14, s15 */
/* @0x1a74cc vmrs APSR_nzcv, fpscr */
/* @0x1a74d0 blt 0x1a7590 <_ZN5CPath11GetPositionEfRfS0_S0_+0x1d4> */
/* @0x1a74d4 add r1, r1, #1 */
/* @0x1a74d8 mov r12, r0 */
/* @0x1a74dc cmp r1, r4 */
/* @0x1a74e0 add r0, r0, #16 */
/* @0x1a74e4 bne 0x1a74c4 <_ZN5CPath11GetPositionEfRfS0_S0_+0x108> */
/* @0x1a74e8 lsl r1, r1, #4 */
/* @0x1a74ec add r12, r1, #16 */
/* @0x1a74f0 add r12, r6, r12 */
/* @0x1a74f4 add r1, r6, r1 */
/* @0x1a74f8 ldr r0, [r1] */
/* @0x1a74fc str r0, [r2] */
/* @0x1a7500 ldr r0, [r1, #0x4] */
/* @0x1a7504 str r0, [r3] */
/* @0x1a7508 ldr r0, [r1, #0x8] */
/* @0x1a750c str r0, [r5] */
/* @0x1a7510 vldr s15, [r1, #12] */
/* @0x1a7514 vldr s13, [r12, #12] */
/* @0x1a7518 vsub.f32 s13, s13, s15 */
/* @0x1a751c vcmp.f32 s13, #0 */
/* @0x1a7520 vmrs APSR_nzcv, fpscr */
/* @0x1a7524 beq 0x1a7464 <_ZN5CPath11GetPositionEfRfS0_S0_+0xa8> */
/* @0x1a7528 vsub.f32 s15, s14, s15 */
/* @0x1a752c vldr s11, [r12] */
/* @0x1a7530 vldr s14, [r1] */
/* @0x1a7534 vldr s12, [r2] */
/* @0x1a7538 vsub.f32 s14, s11, s14 */
/* @0x1a753c vmul.f32 s14, s14, s15 */
/* @0x1a7540 vdiv.f32 s14, s14, s13 */
/* @0x1a7544 vadd.f32 s14, s12, s14 */
/* @0x1a7548 vstr s14, [r2] */
/* @0x1a754c vldr s12, [r12, #4] */
/* @0x1a7550 vldr s14, [r1, #4] */
/* @0x1a7554 vsub.f32 s14, s12, s14 */
/* @0x1a7558 vldr s12, [r3] */
/* @0x1a755c vmul.f32 s14, s14, s15 */
/* @0x1a7560 vdiv.f32 s14, s14, s13 */
/* @0x1a7564 vadd.f32 s14, s12, s14 */
/* @0x1a7568 vstr s14, [r3] */
/* @0x1a756c vldr s12, [r12, #8] */
/* @0x1a7570 vldr s14, [r1, #8] */
/* @0x1a7574 vsub.f32 s14, s12, s14 */
/* @0x1a7578 vldr s12, [r5] */
/* @0x1a757c vmul.f32 s15, s14, s15 */
/* @0x1a7580 vdiv.f32 s13, s15, s13 */
/* @0x1a7584 vadd.f32 s13, s12, s13 */
/* @0x1a7588 vstr s13, [r5] */
/* @0x1a758c b 0x1a7464 <_ZN5CPath11GetPositionEfRfS0_S0_+0xa8> */
/* @0x1a7590 lsl r1, r1, #4 */
/* @0x1a7594 b 0x1a74f4 <_ZN5CPath11GetPositionEfRfS0_S0_+0x138> */

/* ── FUNC 0x1a7598 · CPath::XPosition(float) · size=40 · insn=10 */
/* @0x1a7598 str lr, [sp, #-0x4]! */
/* @0x1a759c sub sp, sp, #28 */
/* @0x1a75a0 add r3, sp, #20 */
/* @0x1a75a4 add r2, sp, #12 */
/* @0x1a75a8 str r3, [sp] */
/* @0x1a75ac add r3, sp, #16 */
/* @0x1a75b0 bl 0x1a73bc <_ZN5CPath11GetPositionEfRfS0_S0_> */
/* @0x1a75b4 ldr r0, [sp, #0xc] */
/* @0x1a75b8 add sp, sp, #28 */
/* @0x1a75bc ldr pc, [sp], #4 */

/* ── FUNC 0x1a75c0 · CPath::YPosition(float) · size=40 · insn=10 */
/* @0x1a75c0 str lr, [sp, #-0x4]! */
/* @0x1a75c4 sub sp, sp, #28 */
/* @0x1a75c8 add r3, sp, #20 */
/* @0x1a75cc add r2, sp, #12 */
/* @0x1a75d0 str r3, [sp] */
/* @0x1a75d4 add r3, sp, #16 */
/* @0x1a75d8 bl 0x1a73bc <_ZN5CPath11GetPositionEfRfS0_S0_> */
/* @0x1a75dc ldr r0, [sp, #0x10] */
/* @0x1a75e0 add sp, sp, #28 */
/* @0x1a75e4 ldr pc, [sp], #4 */

/* ── FUNC 0x1a75e8 · CPath::Speed(float) · size=40 · insn=10 */
/* @0x1a75e8 str lr, [sp, #-0x4]! */
/* @0x1a75ec sub sp, sp, #28 */
/* @0x1a75f0 add r3, sp, #20 */
/* @0x1a75f4 add r2, sp, #12 */
/* @0x1a75f8 str r3, [sp] */
/* @0x1a75fc add r3, sp, #16 */
/* @0x1a7600 bl 0x1a73bc <_ZN5CPath11GetPositionEfRfS0_S0_> */
/* @0x1a7604 ldr r0, [sp, #0x14] */
/* @0x1a7608 add sp, sp, #28 */
/* @0x1a760c ldr pc, [sp], #4 */

/* ── FUNC 0x1a7610 · CPath::Center(float&, float&) · size=164 · insn=41 */
/* @0x1a7610 ldr r12, [r0, #0x10] */
/* @0x1a7614 cmp r12, #0 */
/* @0x1a7618 ble 0x1a769c <_ZN5CPath6CenterERfS0_+0x8c> */
/* @0x1a761c ldr r3, [r0, #0x4] */
/* @0x1a7620 add r12, r12, r12, lsl #1 */
/* @0x1a7624 vldr s13, [pc, #124] */
/* @0x1a7628 vldr s12, [pc, #124] */
/* @0x1a762c vmov.f32 s11, s13 */
/* @0x1a7630 add r0, r3, r12, lsl #2 */
/* @0x1a7634 vmov.f32 s10, s12 */
/* @0x1a7638 vldr s14, [r3] */
/* @0x1a763c vldr s15, [r3, #4] */
/* @0x1a7640 add r3, r3, #12 */
/* @0x1a7644 vcmp.f32 s14, s10 */
/* @0x1a7648 vmrs APSR_nzcv, fpscr */
/* @0x1a764c vcmp.f32 s14, s11 */
/* @0x1a7650 vmovmi.f32 s10, s14 */
/* @0x1a7654 vmrs APSR_nzcv, fpscr */
/* @0x1a7658 vcmp.f32 s15, s12 */
/* @0x1a765c vmovgt.f32 s11, s14 */
/* @0x1a7660 vmrs APSR_nzcv, fpscr */
/* @0x1a7664 vcmp.f32 s15, s13 */
/* @0x1a7668 vmovmi.f32 s12, s15 */
/* @0x1a766c vmrs APSR_nzcv, fpscr */
/* @0x1a7670 vmovgt.f32 s13, s15 */
/* @0x1a7674 cmp r3, r0 */
/* @0x1a7678 bne 0x1a7638 <_ZN5CPath6CenterERfS0_+0x28> */
/* @0x1a767c vmov.f32 s15, #5.000000e-01 */
/* @0x1a7680 vadd.f32 s11, s10, s11 */
/* @0x1a7684 vadd.f32 s13, s12, s13 */
/* @0x1a7688 vmul.f32 s11, s11, s15 */
/* @0x1a768c vmul.f32 s15, s13, s15 */
/* @0x1a7690 vstr s11, [r1] */
/* @0x1a7694 vstr s15, [r2] */
/* @0x1a7698 bx lr */
/* @0x1a769c vldr s15, [pc, #12] */
/* @0x1a76a0 vmov.f32 s11, s15 */
/* @0x1a76a4 b 0x1a7690 <_ZN5CPath6CenterERfS0_+0x80> */
/* @0x1a76a8 ldcgt p12, c11, [lr], #128 */
/* @0x1a76ac ldcmi p12, c11, [lr], #128 */
/* @0x1a76b0 andeq r0, r0, r0 */

/* ── FUNC 0x1a76b4 · CPath::Reverse() · size=128 · insn=32 */
/* @0x1a76b4 ldr r2, [r0, #0x10] */
/* @0x1a76b8 push {r4, r5, r6} */
/* @0x1a76bc cmp r2, #1 */
/* @0x1a76c0 ble 0x1a772c <_ZN5CPath7ReverseEv+0x78> */
/* @0x1a76c4 sub r1, r2, #1 */
/* @0x1a76c8 ldr r3, [r0, #0x4] */
/* @0x1a76cc add r2, r2, r2, lsl #1 */
/* @0x1a76d0 asr r1, r1, #1 */
/* @0x1a76d4 add r12, r3, #20 */
/* @0x1a76d8 add r2, r3, r2, lsl #2 */
/* @0x1a76dc add r3, r3, #8 */
/* @0x1a76e0 add r1, r1, r1, lsl #1 */
/* @0x1a76e4 add r6, r12, r1, lsl #2 */
/* @0x1a76e8 ldr r1, [r2, #-0xc] */
/* @0x1a76ec sub r2, r2, #12 */
/* @0x1a76f0 ldr r4, [r3, #-0x8] */
/* @0x1a76f4 ldr r12, [r3, #-0x4] */
/* @0x1a76f8 str r1, [r3, #-0x8] */
/* @0x1a76fc ldr r5, [r2, #0x4] */
/* @0x1a7700 ldr r1, [r3] */
/* @0x1a7704 str r5, [r3, #-0x4] */
/* @0x1a7708 ldr r5, [r2, #0x8] */
/* @0x1a770c str r5, [r3], #12 */
/* @0x1a7710 cmp r3, r6 */
/* @0x1a7714 str r4, [r2] */
/* @0x1a7718 str r12, [r2, #0x4] */
/* @0x1a771c str r1, [r2, #0x8] */
/* @0x1a7720 bne 0x1a76e8 <_ZN5CPath7ReverseEv+0x34> */
/* @0x1a7724 pop {r4, r5, r6} */
/* @0x1a7728 b 0x1a6e30 <_ZN5CPath15ComputeInternalEv> */
/* @0x1a772c pop {r4, r5, r6} */
/* @0x1a7730 bx lr */

/* ── FUNC 0x1a7734 · CPath::Shift(float, float) · size=72 · insn=18 */
/* @0x1a7734 ldr r3, [r0, #0x10] */
/* @0x1a7738 vmov s13, r1 */
/* @0x1a773c vmov s12, r2 */
/* @0x1a7740 cmp r3, #0 */
/* @0x1a7744 ble 0x1a7778 <_ZN5CPath5ShiftEff+0x44> */
/* @0x1a7748 add r2, r3, r3, lsl #1 */
/* @0x1a774c ldr r3, [r0, #0x4] */
/* @0x1a7750 add r2, r3, r2, lsl #2 */
/* @0x1a7754 vldr s14, [r3] */
/* @0x1a7758 vldr s15, [r3, #4] */
/* @0x1a775c vadd.f32 s14, s14, s13 */
/* @0x1a7760 add r3, r3, #12 */
/* @0x1a7764 vadd.f32 s15, s15, s12 */
/* @0x1a7768 vstr s14, [r3, #-12] */
/* @0x1a776c vstr s15, [r3, #-8] */
/* @0x1a7770 cmp r3, r2 */
/* @0x1a7774 bne 0x1a7754 <_ZN5CPath5ShiftEff+0x20> */
/* @0x1a7778 b 0x1a6e30 <_ZN5CPath15ComputeInternalEv> */

/* ── FUNC 0x1a777c · CPath::Mirror() · size=128 · insn=32 */
/* @0x1a777c push {r4, lr} */
/* @0x1a7780 sub sp, sp, #8 */
/* @0x1a7784 add r2, sp, #4 */
/* @0x1a7788 mov r4, r0 */
/* @0x1a778c mov r1, sp */
/* @0x1a7790 bl 0x1a7610 <_ZN5CPath6CenterERfS0_> */
/* @0x1a7794 ldr r1, [sp] */
/* @0x1a7798 ldr r2, [sp, #0x4] */
/* @0x1a779c mov r0, r4 */
/* @0x1a77a0 eor r1, r1, #-2147483648 */
/* @0x1a77a4 eor r2, r2, #-2147483648 */
/* @0x1a77a8 bl 0x1a7734 <_ZN5CPath5ShiftEff> */
/* @0x1a77ac ldr r2, [r4, #0x10] */
/* @0x1a77b0 cmp r2, #0 */
/* @0x1a77b4 ble 0x1a77dc <_ZN5CPath6MirrorEv+0x60> */
/* @0x1a77b8 add r2, r2, r2, lsl #1 */
/* @0x1a77bc ldr r3, [r4, #0x4] */
/* @0x1a77c0 add r2, r3, r2, lsl #2 */
/* @0x1a77c4 vldr s15, [r3] */
/* @0x1a77c8 vneg.f32 s15, s15 */
/* @0x1a77cc vmov r1, s15 */
/* @0x1a77d0 str r1, [r3], #12 */
/* @0x1a77d4 cmp r3, r2 */
/* @0x1a77d8 bne 0x1a77c4 <_ZN5CPath6MirrorEv+0x48> */
/* @0x1a77dc mov r0, r4 */
/* @0x1a77e0 ldr r1, [sp] */
/* @0x1a77e4 ldr r2, [sp, #0x4] */
/* @0x1a77e8 bl 0x1a7734 <_ZN5CPath5ShiftEff> */
/* @0x1a77ec mov r0, r4 */
/* @0x1a77f0 bl 0x1a6e30 <_ZN5CPath15ComputeInternalEv> */
/* @0x1a77f4 add sp, sp, #8 */
/* @0x1a77f8 pop {r4, pc} */

/* ── FUNC 0x1a77fc · CPath::Flip() · size=128 · insn=32 */
/* @0x1a77fc push {r4, lr} */
/* @0x1a7800 sub sp, sp, #8 */
/* @0x1a7804 add r2, sp, #4 */
/* @0x1a7808 mov r4, r0 */
/* @0x1a780c mov r1, sp */
/* @0x1a7810 bl 0x1a7610 <_ZN5CPath6CenterERfS0_> */
/* @0x1a7814 ldr r1, [sp] */
/* @0x1a7818 ldr r2, [sp, #0x4] */
/* @0x1a781c mov r0, r4 */
/* @0x1a7820 eor r1, r1, #-2147483648 */
/* @0x1a7824 eor r2, r2, #-2147483648 */
/* @0x1a7828 bl 0x1a7734 <_ZN5CPath5ShiftEff> */
/* @0x1a782c ldr r2, [r4, #0x10] */
/* @0x1a7830 cmp r2, #0 */
/* @0x1a7834 ble 0x1a785c <_ZN5CPath4FlipEv+0x60> */
/* @0x1a7838 add r2, r2, r2, lsl #1 */
/* @0x1a783c ldr r3, [r4, #0x4] */
/* @0x1a7840 add r2, r3, r2, lsl #2 */
/* @0x1a7844 vldr s15, [r3, #4] */
/* @0x1a7848 vneg.f32 s15, s15 */
/* @0x1a784c add r3, r3, #12 */
/* @0x1a7850 vstr s15, [r3, #-8] */
/* @0x1a7854 cmp r3, r2 */
/* @0x1a7858 bne 0x1a7844 <_ZN5CPath4FlipEv+0x48> */
/* @0x1a785c mov r0, r4 */
/* @0x1a7860 ldr r1, [sp] */
/* @0x1a7864 ldr r2, [sp, #0x4] */
/* @0x1a7868 bl 0x1a7734 <_ZN5CPath5ShiftEff> */
/* @0x1a786c mov r0, r4 */
/* @0x1a7870 bl 0x1a6e30 <_ZN5CPath15ComputeInternalEv> */
/* @0x1a7874 add sp, sp, #8 */
/* @0x1a7878 pop {r4, pc} */

/* ── FUNC 0x1a787c · CPath::Rotate(float) · size=208 · insn=52 */
/* @0x1a787c push {r4, r5, lr} */
/* @0x1a7880 vpush {d8} */
/* @0x1a7884 sub sp, sp, #12 */
/* @0x1a7888 add r2, sp, #4 */
/* @0x1a788c vmov s16, r1 */
/* @0x1a7890 mov r1, sp */
/* @0x1a7894 mov r4, r0 */
/* @0x1a7898 bl 0x1a7610 <_ZN5CPath6CenterERfS0_> */
/* @0x1a789c ldr r1, [sp] */
/* @0x1a78a0 ldr r2, [sp, #0x4] */
/* @0x1a78a4 mov r0, r4 */
/* @0x1a78a8 eor r1, r1, #-2147483648 */
/* @0x1a78ac eor r2, r2, #-2147483648 */
/* @0x1a78b0 bl 0x1a7734 <_ZN5CPath5ShiftEff> */
/* @0x1a78b4 ldr r5, [r4, #0x10] */
/* @0x1a78b8 cmp r5, #0 */
/* @0x1a78bc ble 0x1a7920 <_ZN5CPath6RotateEf+0xa4> */
/* @0x1a78c0 vldr s17, [pc, #124] */
/* @0x1a78c4 vmul.f32 s17, s16, s17 */
/* @0x1a78c8 vldr s15, [pc, #120] */
/* @0x1a78cc add r5, r5, r5, lsl #1 */
/* @0x1a78d0 vdiv.f32 s17, s17, s15 */
/* @0x1a78d4 vmov r0, s17 */
/* @0x1a78d8 bl 0xb658c <cosf@plt> */
/* @0x1a78dc vmov s16, r0 */
/* @0x1a78e0 vmov r0, s17 */
/* @0x1a78e4 bl 0xb6580 <sinf@plt> */
/* @0x1a78e8 ldr r3, [r4, #0x4] */
/* @0x1a78ec add r2, r3, r5, lsl #2 */
/* @0x1a78f0 vmov s11, r0 */
/* @0x1a78f4 vldr s13, [r3] */
/* @0x1a78f8 vldr s12, [r3, #4] */
/* @0x1a78fc vmul.f32 s14, s13, s11 */
/* @0x1a7900 add r3, r3, #12 */
/* @0x1a7904 vmul.f32 s15, s12, s11 */
/* @0x1a7908 vnmls.f32 s14, s12, s16 */
/* @0x1a790c vmla.f32 s15, s13, s16 */
/* @0x1a7910 vstr s14, [r3, #-8] */
/* @0x1a7914 vstr s15, [r3, #-12] */
/* @0x1a7918 cmp r3, r2 */
/* @0x1a791c bne 0x1a78f4 <_ZN5CPath6RotateEf+0x78> */
/* @0x1a7920 mov r0, r4 */
/* @0x1a7924 ldr r1, [sp] */
/* @0x1a7928 ldr r2, [sp, #0x4] */
/* @0x1a792c bl 0x1a7734 <_ZN5CPath5ShiftEff> */
/* @0x1a7930 mov r0, r4 */
/* @0x1a7934 bl 0x1a6e30 <_ZN5CPath15ComputeInternalEv> */
/* @0x1a7938 add sp, sp, #12 */
/* @0x1a793c vpop {d8} */
/* @0x1a7940 pop {r4, r5, pc} */
/* @0x1a7944 ldrdmi r0, r1, [r9], #-251 */
/* @0x1a7948 teqmi r4, #0 */

/* ── FUNC 0x1a794c · CPath::Scale(float, float) · size=156 · insn=39 */
/* @0x1a794c push {r4, lr} */
/* @0x1a7950 vpush {d8} */
/* @0x1a7954 sub sp, sp, #8 */
/* @0x1a7958 vmov s16, r1 */
/* @0x1a795c mov r4, r0 */
/* @0x1a7960 mov r1, sp */
/* @0x1a7964 vmov s17, r2 */
/* @0x1a7968 add r2, sp, #4 */
/* @0x1a796c bl 0x1a7610 <_ZN5CPath6CenterERfS0_> */
/* @0x1a7970 ldr r1, [sp] */
/* @0x1a7974 ldr r2, [sp, #0x4] */
/* @0x1a7978 mov r0, r4 */
/* @0x1a797c eor r1, r1, #-2147483648 */
/* @0x1a7980 eor r2, r2, #-2147483648 */
/* @0x1a7984 bl 0x1a7734 <_ZN5CPath5ShiftEff> */
/* @0x1a7988 ldr r2, [r4, #0x10] */
/* @0x1a798c cmp r2, #0 */
/* @0x1a7990 ble 0x1a79c4 <_ZN5CPath5ScaleEff+0x78> */
/* @0x1a7994 add r2, r2, r2, lsl #1 */
/* @0x1a7998 ldr r3, [r4, #0x4] */
/* @0x1a799c add r2, r3, r2, lsl #2 */
/* @0x1a79a0 vldr s14, [r3] */
/* @0x1a79a4 vldr s15, [r3, #4] */
/* @0x1a79a8 vmul.f32 s14, s14, s16 */
/* @0x1a79ac add r3, r3, #12 */
/* @0x1a79b0 vmul.f32 s15, s15, s17 */
/* @0x1a79b4 vstr s14, [r3, #-12] */
/* @0x1a79b8 vstr s15, [r3, #-8] */
/* @0x1a79bc cmp r3, r2 */
/* @0x1a79c0 bne 0x1a79a0 <_ZN5CPath5ScaleEff+0x54> */
/* @0x1a79c4 mov r0, r4 */
/* @0x1a79c8 ldr r1, [sp] */
/* @0x1a79cc ldr r2, [sp, #0x4] */
/* @0x1a79d0 bl 0x1a7734 <_ZN5CPath5ShiftEff> */
/* @0x1a79d4 mov r0, r4 */
/* @0x1a79d8 bl 0x1a6e30 <_ZN5CPath15ComputeInternalEv> */
/* @0x1a79dc add sp, sp, #8 */
/* @0x1a79e0 vpop {d8} */
/* @0x1a79e4 pop {r4, pc} */

/* ── FUNC 0x1a79e8 · CPath::Append(CPath*) · size=208 · insn=52 */
/* @0x1a79e8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1a79ec subs r8, r1, #0 */
/* @0x1a79f0 mov r7, r0 */
/* @0x1a79f4 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1a79f8 ldr r2, [r8, #0x10] */
/* @0x1a79fc cmp r2, #0 */
/* @0x1a7a00 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1a7a04 ldr r6, [r0, #0x10] */
/* @0x1a7a08 ldr r1, [r0] */
/* @0x1a7a0c add r3, r2, r6 */
/* @0x1a7a10 cmp r3, r1 */
/* @0x1a7a14 bgt 0x1a7a84 <_ZN5CPath6AppendEPS_+0x9c> */
/* @0x1a7a18 cmp r2, #0 */
/* @0x1a7a1c ble 0x1a7a70 <_ZN5CPath6AppendEPS_+0x88> */
/* @0x1a7a20 mov r12, #0 */
/* @0x1a7a24 mov r3, r12 */
/* @0x1a7a28 ldr r2, [r8, #0x4] */
/* @0x1a7a2c add r6, r3, r6 */
/* @0x1a7a30 ldr r5, [r7, #0x4] */
/* @0x1a7a34 add r3, r3, #1 */
/* @0x1a7a38 add r2, r2, r12 */
/* @0x1a7a3c add r6, r6, r6, lsl #1 */
/* @0x1a7a40 add r12, r12, #12 */
/* @0x1a7a44 ldr r0, [r2] */
/* @0x1a7a48 add r4, r5, r6, lsl #2 */
/* @0x1a7a4c ldr r1, [r2, #0x4] */
/* @0x1a7a50 ldr r2, [r2, #0x8] */
/* @0x1a7a54 str r0, [r5, r6, lsl #2] */
/* @0x1a7a58 str r1, [r4, #0x4] */
/* @0x1a7a5c str r2, [r4, #0x8] */
/* @0x1a7a60 ldr r2, [r8, #0x10] */
/* @0x1a7a64 ldr r6, [r7, #0x10] */
/* @0x1a7a68 cmp r2, r3 */
/* @0x1a7a6c bgt 0x1a7a28 <_ZN5CPath6AppendEPS_+0x40> */
/* @0x1a7a70 add r6, r2, r6 */
/* @0x1a7a74 mov r0, r7 */
/* @0x1a7a78 str r6, [r7, #0x10] */
/* @0x1a7a7c pop {r4, r5, r6, r7, r8, lr} */
/* @0x1a7a80 b 0x1a6e30 <_ZN5CPath15ComputeInternalEv> */
/* @0x1a7a84 add r1, r3, r3, lsl #1 */
/* @0x1a7a88 ldr r2, [pc, #0x24] */
/* @0x1a7a8c add r0, r0, #4 */
/* @0x1a7a90 movw r3, #0x381 */
/* @0x1a7a94 add r2, pc, r2 */
/* @0x1a7a98 lsl r1, r1, #2 */
/* @0x1a7a9c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1a7aa0 ldr r2, [r8, #0x10] */
/* @0x1a7aa4 ldr r6, [r7, #0x10] */
/* @0x1a7aa8 cmp r2, #0 */
/* @0x1a7aac bgt 0x1a7a20 <_ZN5CPath6AppendEPS_+0x38> */
/* @0x1a7ab0 b 0x1a7a70 <_ZN5CPath6AppendEPS_+0x88> */
/* @0x1a7ab4 andseq r5, r10, r4, asr #12 */

/* ── FUNC 0x1a7ab8 · CPath::GetPathLength() · size=8 · insn=2 */
/* @0x1a7ab8 ldr r0, [r0, #0x24] */
/* @0x1a7abc bx lr */

/* ── FUNC 0x1a7ac0 · CPath::Draw(float, float, bool) · size=256 · insn=64 */
/* @0x1a7ac0 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1a7ac4 vpush {d8, d9} */
/* @0x1a7ac8 sub sp, sp, #28 */
/* @0x1a7acc add r6, sp, #12 */
/* @0x1a7ad0 add r7, sp, #16 */
/* @0x1a7ad4 mov r4, r3 */
/* @0x1a7ad8 vmov s17, r2 */
/* @0x1a7adc mov r3, r7 */
/* @0x1a7ae0 mov r2, r6 */
/* @0x1a7ae4 vmov s16, r1 */
/* @0x1a7ae8 add r8, sp, #20 */
/* @0x1a7aec mov r1, #0 */
/* @0x1a7af0 str r8, [sp] */
/* @0x1a7af4 mov r5, r0 */
/* @0x1a7af8 bl 0x1a73bc <_ZN5CPath11GetPositionEfRfS0_S0_> */
/* @0x1a7afc cmp r4, #0 */
/* @0x1a7b00 mov r0, r5 */
/* @0x1a7b04 vldreq s15, [sp, #16] */
/* @0x1a7b08 vldreq s14, [sp, #12] */
/* @0x1a7b0c vsubeq.f32 s17, s17, s15 */
/* @0x1a7b10 vsubeq.f32 s16, s16, s14 */
/* @0x1a7b14 bl 0x1a7ab8 <_ZN5CPath13GetPathLengthEv> */
/* @0x1a7b18 vmov.f32 s15, #2.500000e-01 */
/* @0x1a7b1c vmov s12, r0 */
/* @0x1a7b20 vmul.f32 s15, s12, s15 */
/* @0x1a7b24 vcvt.f64.f32 d6, s15 */
/* @0x1a7b28 vmov r0, r1, d6 */
/* @0x1a7b2c bl 0xb66e8 <lrint@plt> */
/* @0x1a7b30 subs r9, r0, #0 */
/* @0x1a7b34 bne 0x1a7b44 <_ZN5CPath4DrawEffb+0x84> */
/* @0x1a7b38 add sp, sp, #28 */
/* @0x1a7b3c vpop {d8, d9} */
/* @0x1a7b40 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1a7b44 mov r0, #3 */
/* @0x1a7b48 mvn r1, #0 */
/* @0x1a7b4c bl 0x16b964 <_Z23GR_Draw_Primitive_Beginii> */
/* @0x1a7b50 cmp r9, #0 */
/* @0x1a7b54 blt 0x1a7bb0 <_ZN5CPath4DrawEffb+0xf0> */
/* @0x1a7b58 vmov s13, r9 */
/* @0x1a7b5c mov r4, #0 */
/* @0x1a7b60 vcvt.f32.s32 s18, s13 */
/* @0x1a7b64 vmov s14, r4 */
/* @0x1a7b68 mov r0, r5 */
/* @0x1a7b6c mov r2, r6 */
/* @0x1a7b70 mov r3, r7 */
/* @0x1a7b74 str r8, [sp] */
/* @0x1a7b78 add r4, r4, #1 */
/* @0x1a7b7c vcvt.f32.s32 s15, s14 */
/* @0x1a7b80 vdiv.f32 s15, s15, s18 */
/* @0x1a7b84 vmov r1, s15 */
/* @0x1a7b88 bl 0x1a73bc <_ZN5CPath11GetPositionEfRfS0_S0_> */
/* @0x1a7b8c vldr s14, [sp, #12] */
/* @0x1a7b90 vldr s15, [sp, #16] */
/* @0x1a7b94 vadd.f32 s14, s16, s14 */
/* @0x1a7b98 vadd.f32 s15, s17, s15 */
/* @0x1a7b9c vmov r0, s14 */
/* @0x1a7ba0 vmov r1, s15 */
/* @0x1a7ba4 bl 0x16ba58 <_Z14GR_Draw_Vertexff> */
/* @0x1a7ba8 cmp r9, r4 */
/* @0x1a7bac bge 0x1a7b64 <_ZN5CPath4DrawEffb+0xa4> */
/* @0x1a7bb0 bl 0x16bdb0 <_Z21GR_Draw_Primitive_Endv> */
/* @0x1a7bb4 add sp, sp, #28 */
/* @0x1a7bb8 vpop {d8, d9} */
/* @0x1a7bbc pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x1a7bc0 · CPath::GetPathTime() · size=8 · insn=2 */
/* @0x1a7bc0 ldr r0, [r0, #0x28] */
/* @0x1a7bc4 bx lr */

/* ── FUNC 0x1a7bc8 · CPath::GetCount() · size=8 · insn=2 */
/* @0x1a7bc8 ldr r0, [r0, #0x10] */
/* @0x1a7bcc bx lr */

/* ── FUNC 0x1a7bd0 · CPath::GetKind() · size=8 · insn=2 */
/* @0x1a7bd0 ldr r0, [r0, #0x14] */
/* @0x1a7bd4 bx lr */

/* ── FUNC 0x1a7bd8 · CPath::GetClosed() · size=8 · insn=2 */
/* @0x1a7bd8 ldrb r0, [r0, #0x18] */
/* @0x1a7bdc bx lr */

/* ── FUNC 0x1a7be0 · CPath::GetPrecision() · size=8 · insn=2 */
/* @0x1a7be0 ldr r0, [r0, #0x1c] */
/* @0x1a7be4 bx lr */
