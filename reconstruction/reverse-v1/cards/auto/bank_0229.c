/* libyoyo.so 覆盖卡组 0229
 * 函数 0x27bcf4..0x27d1dc，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x27bcf4 · logLocation(ELogType, void const*, void const*, unsigned int) · size=4 · insn=1 */
/* @0x27bcf4 bx lr */

/* ── FUNC 0x27bcf8 · addPageToGlobalPageList(void*, void*) · size=316 · insn=79 */
/* @0x27bcf8 ldr r2, [pc, #0x124] */
/* @0x27bcfc ldr r3, [pc, #0x124] */
/* @0x27bd00 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x27bd04 add r2, pc, r2 */
/* @0x27bd08 mov r9, r1 */
/* @0x27bd0c ldr r1, [pc, #0x118] */
/* @0x27bd10 ldr r8, [r2, r3] */
/* @0x27bd14 mov r6, r0 */
/* @0x27bd18 ldr r0, [r2, r1] */
/* @0x27bd1c ldr r4, [r8] */
/* @0x27bd20 ldr r3, [r0] */
/* @0x27bd24 add r1, r4, #1 */
/* @0x27bd28 cmp r1, r3 */
/* @0x27bd2c bge 0x27bdd4 <_Z23addPageToGlobalPageListPvS_+0xdc> */
/* @0x27bd30 ldr r3, [pc, #0xf8] */
/* @0x27bd34 ldr r10, [r2, r3] */
/* @0x27bd38 ldr r1, [r10] */
/* @0x27bd3c cmp r4, #0 */
/* @0x27bd40 ble 0x27be08 <_Z23addPageToGlobalPageListPvS_+0x110> */
/* @0x27bd44 ldr r3, [r1] */
/* @0x27bd48 cmp r6, r3 */
/* @0x27bd4c blo 0x27be10 <_Z23addPageToGlobalPageListPvS_+0x118> */
/* @0x27bd50 cmp r3, #0 */
/* @0x27bd54 beq 0x27be08 <_Z23addPageToGlobalPageListPvS_+0x110> */
/* @0x27bd58 add r2, r1, #8 */
/* @0x27bd5c mov r3, #0 */
/* @0x27bd60 b 0x27bd7c <_Z23addPageToGlobalPageListPvS_+0x84> */
/* @0x27bd64 ldr r12, [r2] */
/* @0x27bd68 add r2, r2, #8 */
/* @0x27bd6c cmp r12, r6 */
/* @0x27bd70 bhi 0x27bda8 <_Z23addPageToGlobalPageListPvS_+0xb0> */
/* @0x27bd74 cmp r12, #0 */
/* @0x27bd78 beq 0x27bd94 <_Z23addPageToGlobalPageListPvS_+0x9c> */
/* @0x27bd7c add r3, r3, #1 */
/* @0x27bd80 mov r5, r2 */
/* @0x27bd84 cmp r3, r4 */
/* @0x27bd88 lsl r7, r3, #3 */
/* @0x27bd8c bne 0x27bd64 <_Z23addPageToGlobalPageListPvS_+0x6c> */
/* @0x27bd90 add r5, r1, r4, lsl #3 */
/* @0x27bd94 str r6, [r5] */
/* @0x27bd98 add r4, r4, #1 */
/* @0x27bd9c str r9, [r5, #0x4] */
/* @0x27bda0 str r4, [r8] */
/* @0x27bda4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x27bda8 add r0, r3, #1 */
/* @0x27bdac lsl r0, r0, #3 */
/* @0x27bdb0 rsb r2, r3, r4 */
/* @0x27bdb4 add r0, r1, r0 */
/* @0x27bdb8 mov r1, r5 */
/* @0x27bdbc lsl r2, r2, #3 */
/* @0x27bdc0 bl 0xb6694 <memmove@plt> */
/* @0x27bdc4 ldr r5, [r10] */
/* @0x27bdc8 ldr r4, [r8] */
/* @0x27bdcc add r5, r5, r7 */
/* @0x27bdd0 b 0x27bd94 <_Z23addPageToGlobalPageListPvS_+0x9c> */
/* @0x27bdd4 add r3, r3, r3, lsl #1 */
/* @0x27bdd8 ldr r12, [pc, #0x50] */
/* @0x27bddc add r3, r3, r3, lsr #31 */
/* @0x27bde0 asr r1, r3, #1 */
/* @0x27bde4 str r1, [r0] */
/* @0x27bde8 ldr r10, [r2, r12] */
/* @0x27bdec lsl r1, r1, #3 */
/* @0x27bdf0 ldr r0, [r10] */
/* @0x27bdf4 bl 0xb6c28 <realloc@plt> */
/* @0x27bdf8 ldr r4, [r8] */
/* @0x27bdfc mov r1, r0 */
/* @0x27be00 str r0, [r10] */
/* @0x27be04 b 0x27bd3c <_Z23addPageToGlobalPageListPvS_+0x44> */
/* @0x27be08 mov r5, r1 */
/* @0x27be0c b 0x27bd94 <_Z23addPageToGlobalPageListPvS_+0x9c> */
/* @0x27be10 mov r7, #0 */
/* @0x27be14 mov r5, r1 */
/* @0x27be18 mov r3, r7 */
/* @0x27be1c mov r0, #8 */
/* @0x27be20 b 0x27bdb0 <_Z23addPageToGlobalPageListPvS_+0xb8> */
/* @0x27be24 andseq r5, r7, r12, asr #30 */
/* @0x27be28 .word 0xfffffbd8 */
/* @0x27be2c .word 0xfffffbdc */
/* @0x27be30 .word 0xfffffbe0 */

/* ── FUNC 0x27be34 · globalPageListFindAddr(void const*) · size=172 · insn=43 */
/* @0x27be34 ldr r3, [pc, #0x9c] */
/* @0x27be38 ldr r2, [pc, #0x9c] */
/* @0x27be3c ldr r3, [pc, r3] */
/* @0x27be40 ldr r2, [pc, r2] */
/* @0x27be44 push {r4, r5} */
/* @0x27be48 ldr r1, [r2] */
/* @0x27be4c ldr r5, [r3] */
/* @0x27be50 lsl r1, r1, #1 */
/* @0x27be54 mov r2, r5 */
/* @0x27be58 b 0x27be68 <_Z22globalPageListFindAddrPKv+0x34> */
/* @0x27be5c mvn r3, r3 */
/* @0x27be60 add r2, r12, #4 */
/* @0x27be64 add r1, r1, r3 */
/* @0x27be68 cmp r1, #0 */
/* @0x27be6c ble 0x27beac <_Z22globalPageListFindAddrPKv+0x78> */
/* @0x27be70 asr r3, r1, #1 */
/* @0x27be74 ldr r4, [r2, r3, lsl #2] */
/* @0x27be78 add r12, r2, r3, lsl #2 */
/* @0x27be7c cmp r0, r4 */
/* @0x27be80 bhi 0x27be5c <_Z22globalPageListFindAddrPKv+0x28> */
/* @0x27be84 subs r1, r3, #0 */
/* @0x27be88 asr r3, r3, #1 */
/* @0x27be8c beq 0x27beac <_Z22globalPageListFindAddrPKv+0x78> */
/* @0x27be90 ldr r4, [r2, r3, lsl #2] */
/* @0x27be94 add r12, r2, r3, lsl #2 */
/* @0x27be98 cmp r4, r0 */
/* @0x27be9c blo 0x27be5c <_Z22globalPageListFindAddrPKv+0x28> */
/* @0x27bea0 subs r1, r3, #0 */
/* @0x27bea4 asr r3, r3, #1 */
/* @0x27bea8 bne 0x27be90 <_Z22globalPageListFindAddrPKv+0x5c> */
/* @0x27beac rsb r1, r5, r2 */
/* @0x27beb0 pop {r4, r5} */
/* @0x27beb4 lsr r3, r1, #31 */
/* @0x27beb8 add r1, r3, r1, asr #2 */
/* @0x27bebc and r1, r1, #1 */
/* @0x27bec0 rsb r3, r3, r1 */
/* @0x27bec4 cmp r3, #1 */
/* @0x27bec8 ldreq r3, [r2, #-0x4] */
/* @0x27becc movne r0, #0 */
/* @0x27bed0 ldreq r0, [r3, #0x4] */
/* @0x27bed4 bx lr */
/* @0x27bed8 ldrsheq r5, [r7], -r4 */
/* @0x27bedc andseq r5, r7, r8, ror #19 */

/* ── FUNC 0x27bee0 · bucketCheck(char*) · size=772 · insn=193 */
/* @0x27bee0 ldr r0, [pc, #0x2d8] */
/* @0x27bee4 mov r2, #8 */
/* @0x27bee8 ldr r1, [pc, #0x2d4] */
/* @0x27beec add r0, pc, r0 */
/* @0x27bef0 ldr r12, [pc, #0x2d0] */
/* @0x27bef4 push {r4, r5, r6, r7, r8} */
/* @0x27bef8 mov r8, #0 */
/* @0x27befc ldr r1, [r0, r1] */
/* @0x27bf00 ldr r3, [pc, #0x2c4] */
/* @0x27bf04 str r8, [r1] */
/* @0x27bf08 ldr r12, [r0, r12] */
/* @0x27bf0c str r2, [r12] */
/* @0x27bf10 ldr r6, [r0, r3] */
/* @0x27bf14 ldr r5, [r6, #0x8] */
/* @0x27bf18 cmp r5, r8 */
/* @0x27bf1c movne r7, #42 */
/* @0x27bf20 beq 0x27bf74 <_Z11bucketCheckPc+0x94> */
/* @0x27bf24 ldr r3, [r6, #0x4] */
/* @0x27bf28 cmp r3, #0 */
/* @0x27bf2c beq 0x27bf58 <_Z11bucketCheckPc+0x78> */
/* @0x27bf30 add r4, r3, #8 */
/* @0x27bf34 add r2, r3, #131072 */
/* @0x27bf38 cmp r5, r4 */
/* @0x27bf3c add r2, r2, #8 */
/* @0x27bf40 blo 0x27bf4c <_Z11bucketCheckPc+0x6c> */
/* @0x27bf44 cmp r2, r5 */
/* @0x27bf48 bhi 0x27bf5c <_Z11bucketCheckPc+0x7c> */
/* @0x27bf4c ldr r3, [r3] */
/* @0x27bf50 cmp r3, #0 */
/* @0x27bf54 bne 0x27bf30 <_Z11bucketCheckPc+0x50> */
/* @0x27bf58 str r7, [r8] */
/* @0x27bf5c ldr r5, [r5] */
/* @0x27bf60 ldr r3, [r1] */
/* @0x27bf64 cmp r5, #0 */
/* @0x27bf68 add r3, r3, #1 */
/* @0x27bf6c str r3, [r1] */
/* @0x27bf70 bne 0x27bf24 <_Z11bucketCheckPc+0x44> */
/* @0x27bf74 ldr r3, [pc, #0x254] */
/* @0x27bf78 mov r2, #16 */
/* @0x27bf7c str r2, [r12] */
/* @0x27bf80 ldr r6, [r0, r3] */
/* @0x27bf84 ldr r5, [r6, #0x8] */
/* @0x27bf88 cmp r5, #0 */
/* @0x27bf8c movne r8, #0 */
/* @0x27bf90 movne r7, #42 */
/* @0x27bf94 beq 0x27bfe8 <_Z11bucketCheckPc+0x108> */
/* @0x27bf98 ldr r3, [r6, #0x4] */
/* @0x27bf9c cmp r3, #0 */
/* @0x27bfa0 beq 0x27bfcc <_Z11bucketCheckPc+0xec> */
/* @0x27bfa4 add r4, r3, #8 */
/* @0x27bfa8 add r2, r3, #262144 */
/* @0x27bfac cmp r5, r4 */
/* @0x27bfb0 add r2, r2, #8 */
/* @0x27bfb4 blo 0x27bfc0 <_Z11bucketCheckPc+0xe0> */
/* @0x27bfb8 cmp r2, r5 */
/* @0x27bfbc bhi 0x27bfd0 <_Z11bucketCheckPc+0xf0> */
/* @0x27bfc0 ldr r3, [r3] */
/* @0x27bfc4 cmp r3, #0 */
/* @0x27bfc8 bne 0x27bfa4 <_Z11bucketCheckPc+0xc4> */
/* @0x27bfcc str r7, [r8] */
/* @0x27bfd0 ldr r5, [r5] */
/* @0x27bfd4 ldr r3, [r1] */
/* @0x27bfd8 cmp r5, #0 */
/* @0x27bfdc add r3, r3, #1 */
/* @0x27bfe0 str r3, [r1] */
/* @0x27bfe4 bne 0x27bf98 <_Z11bucketCheckPc+0xb8> */
/* @0x27bfe8 ldr r3, [pc, #0x1e4] */
/* @0x27bfec mov r2, #32 */
/* @0x27bff0 str r2, [r12] */
/* @0x27bff4 ldr r6, [r0, r3] */
/* @0x27bff8 ldr r5, [r6, #0x8] */
/* @0x27bffc cmp r5, #0 */
/* @0x27c000 movne r8, #0 */
/* @0x27c004 movne r7, #42 */
/* @0x27c008 beq 0x27c05c <_Z11bucketCheckPc+0x17c> */
/* @0x27c00c ldr r3, [r6, #0x4] */
/* @0x27c010 cmp r3, #0 */
/* @0x27c014 beq 0x27c040 <_Z11bucketCheckPc+0x160> */
/* @0x27c018 add r4, r3, #8 */
/* @0x27c01c add r2, r3, #262144 */
/* @0x27c020 cmp r5, r4 */
/* @0x27c024 add r2, r2, #8 */
/* @0x27c028 blo 0x27c034 <_Z11bucketCheckPc+0x154> */
/* @0x27c02c cmp r2, r5 */
/* @0x27c030 bhi 0x27c044 <_Z11bucketCheckPc+0x164> */
/* @0x27c034 ldr r3, [r3] */
/* @0x27c038 cmp r3, #0 */
/* @0x27c03c bne 0x27c018 <_Z11bucketCheckPc+0x138> */
/* @0x27c040 str r7, [r8] */
/* @0x27c044 ldr r5, [r5] */
/* @0x27c048 ldr r3, [r1] */
/* @0x27c04c cmp r5, #0 */
/* @0x27c050 add r3, r3, #1 */
/* @0x27c054 str r3, [r1] */
/* @0x27c058 bne 0x27c00c <_Z11bucketCheckPc+0x12c> */
/* @0x27c05c ldr r3, [pc, #0x174] */
/* @0x27c060 mov r2, #64 */
/* @0x27c064 str r2, [r12] */
/* @0x27c068 ldr r6, [r0, r3] */
/* @0x27c06c ldr r5, [r6, #0x8] */
/* @0x27c070 cmp r5, #0 */
/* @0x27c074 movne r8, #0 */
/* @0x27c078 movne r7, #42 */
/* @0x27c07c beq 0x27c0d0 <_Z11bucketCheckPc+0x1f0> */
/* @0x27c080 ldr r3, [r6, #0x4] */
/* @0x27c084 cmp r3, #0 */
/* @0x27c088 beq 0x27c0b4 <_Z11bucketCheckPc+0x1d4> */
/* @0x27c08c add r4, r3, #8 */
/* @0x27c090 add r2, r3, #524288 */
/* @0x27c094 cmp r5, r4 */
/* @0x27c098 add r2, r2, #8 */
/* @0x27c09c blo 0x27c0a8 <_Z11bucketCheckPc+0x1c8> */
/* @0x27c0a0 cmp r2, r5 */
/* @0x27c0a4 bhi 0x27c0b8 <_Z11bucketCheckPc+0x1d8> */
/* @0x27c0a8 ldr r3, [r3] */
/* @0x27c0ac cmp r3, #0 */
/* @0x27c0b0 bne 0x27c08c <_Z11bucketCheckPc+0x1ac> */
/* @0x27c0b4 str r7, [r8] */
/* @0x27c0b8 ldr r5, [r5] */
/* @0x27c0bc ldr r3, [r1] */
/* @0x27c0c0 cmp r5, #0 */
/* @0x27c0c4 add r3, r3, #1 */
/* @0x27c0c8 str r3, [r1] */
/* @0x27c0cc bne 0x27c080 <_Z11bucketCheckPc+0x1a0> */
/* @0x27c0d0 ldr r3, [pc, #0x104] */
/* @0x27c0d4 mov r2, #128 */
/* @0x27c0d8 str r2, [r12] */
/* @0x27c0dc ldr r6, [r0, r3] */
/* @0x27c0e0 ldr r5, [r6, #0x8] */
/* @0x27c0e4 cmp r5, #0 */
/* @0x27c0e8 movne r8, #0 */
/* @0x27c0ec movne r7, #42 */
/* @0x27c0f0 beq 0x27c144 <_Z11bucketCheckPc+0x264> */
/* @0x27c0f4 ldr r3, [r6, #0x4] */
/* @0x27c0f8 cmp r3, #0 */
/* @0x27c0fc beq 0x27c128 <_Z11bucketCheckPc+0x248> */
/* @0x27c100 add r4, r3, #8 */
/* @0x27c104 add r2, r3, #524288 */
/* @0x27c108 cmp r5, r4 */
/* @0x27c10c add r2, r2, #8 */
/* @0x27c110 blo 0x27c11c <_Z11bucketCheckPc+0x23c> */
/* @0x27c114 cmp r2, r5 */
/* @0x27c118 bhi 0x27c12c <_Z11bucketCheckPc+0x24c> */
/* @0x27c11c ldr r3, [r3] */
/* @0x27c120 cmp r3, #0 */
/* @0x27c124 bne 0x27c100 <_Z11bucketCheckPc+0x220> */
/* @0x27c128 str r7, [r8] */
/* @0x27c12c ldr r5, [r5] */
/* @0x27c130 ldr r3, [r1] */
/* @0x27c134 cmp r5, #0 */
/* @0x27c138 add r3, r3, #1 */
/* @0x27c13c str r3, [r1] */
/* @0x27c140 bne 0x27c0f4 <_Z11bucketCheckPc+0x214> */
/* @0x27c144 ldr r3, [pc, #0x94] */
/* @0x27c148 mov r2, #256 */
/* @0x27c14c str r2, [r12] */
/* @0x27c150 ldr r4, [r0, r3] */
/* @0x27c154 ldr r12, [r4, #0x8] */
/* @0x27c158 cmp r12, #0 */
/* @0x27c15c movne r6, #0 */
/* @0x27c160 movne r5, #42 */
/* @0x27c164 beq 0x27c1b8 <_Z11bucketCheckPc+0x2d8> */
/* @0x27c168 ldr r3, [r4, #0x4] */
/* @0x27c16c cmp r3, #0 */
/* @0x27c170 beq 0x27c19c <_Z11bucketCheckPc+0x2bc> */
/* @0x27c174 add r0, r3, #8 */
/* @0x27c178 add r2, r3, #1048576 */
/* @0x27c17c cmp r12, r0 */
/* @0x27c180 add r2, r2, #8 */
/* @0x27c184 blo 0x27c190 <_Z11bucketCheckPc+0x2b0> */
/* @0x27c188 cmp r2, r12 */
/* @0x27c18c bhi 0x27c1a0 <_Z11bucketCheckPc+0x2c0> */
/* @0x27c190 ldr r3, [r3] */
/* @0x27c194 cmp r3, #0 */
/* @0x27c198 bne 0x27c174 <_Z11bucketCheckPc+0x294> */
/* @0x27c19c str r5, [r6] */
/* @0x27c1a0 ldr r12, [r12] */
/* @0x27c1a4 ldr r3, [r1] */
/* @0x27c1a8 cmp r12, #0 */
/* @0x27c1ac add r3, r3, #1 */
/* @0x27c1b0 str r3, [r1] */
/* @0x27c1b4 bne 0x27c168 <_Z11bucketCheckPc+0x288> */
/* @0x27c1b8 pop {r4, r5, r6, r7, r8} */
/* @0x27c1bc bx lr */
/* @0x27c1c0 andseq r5, r7, r4, ror #26 */
/* @0x27c1c4 .word 0xffffbf74 */
/* @0x27c1c8 .word 0xfffffbe4 */
/* @0x27c1cc .word 0xfffffbe8 */
/* @0x27c1d0 .word 0xfffffbec */
/* @0x27c1d4 .word 0xfffffbf0 */
/* @0x27c1d8 .word 0xfffffbf4 */
/* @0x27c1dc .word 0xfffffbf8 */
/* @0x27c1e0 .word 0xfffffbfc */

/* ── FUNC 0x27c1e4 · bucketSize(void const*) · size=40 · insn=10 */
/* @0x27c1e4 push {r3, lr} */
/* @0x27c1e8 bl 0x27be34 <_Z22globalPageListFindAddrPKv> */
/* @0x27c1ec subs r3, r0, #0 */
/* @0x27c1f0 beq 0x27c204 <_Z10bucketSizePKv+0x20> */
/* @0x27c1f4 ldr r3, [r3] */
/* @0x27c1f8 ldr r3, [r3, #0x8] */
/* @0x27c1fc blx r3 */
/* @0x27c200 pop {r3, pc} */
/* @0x27c204 mov r0, r3 */
/* @0x27c208 pop {r3, pc} */

/* ── FUNC 0x27c20c · bucketFree(void const*) · size=48 · insn=12 */
/* @0x27c20c push {r4, lr} */
/* @0x27c210 mov r4, r0 */
/* @0x27c214 bl 0x27be34 <_Z22globalPageListFindAddrPKv> */
/* @0x27c218 subs r3, r0, #0 */
/* @0x27c21c beq 0x27c234 <_Z10bucketFreePKv+0x28> */
/* @0x27c220 ldr r3, [r3] */
/* @0x27c224 mov r1, r4 */
/* @0x27c228 ldr r3, [r3, #0xc] */
/* @0x27c22c blx r3 */
/* @0x27c230 pop {r4, pc} */
/* @0x27c234 mov r0, r3 */
/* @0x27c238 pop {r4, pc} */

/* ── FUNC 0x27c23c · MemoryManager::Init() · size=76 · insn=19 */
/* @0x27c23c ldr r2, [pc, #0x38] */
/* @0x27c240 mov r1, #1 */
/* @0x27c244 ldr r3, [pc, #0x34] */
/* @0x27c248 add r2, pc, r2 */
/* @0x27c24c ldr r3, [pc, r3] */
/* @0x27c250 ldrb r0, [r2, #0x200] */
/* @0x27c254 strb r1, [r3] */
/* @0x27c258 cmp r0, #0 */
/* @0x27c25c bxne lr */
/* @0x27c260 ldr r3, [pc, #0x1c] */
/* @0x27c264 strb r1, [r2, #0x200] */
/* @0x27c268 ldr r3, [pc, r3] */
/* @0x27c26c ldr r3, [r3] */
/* @0x27c270 cmp r3, #0 */
/* @0x27c274 bxne lr */
/* @0x27c278 b 0x27b918 <_ZN7CBucketILj8ELj131072ELb1EE4FreeEPKv+0x38> */
/* @0x27c27c subeq r10, sp, r8, asr #4 */
/* @0x27c280 andseq r5, r7, r4, lsl #12 */
/* @0x27c284 ldrheq r5, [r7], -r4 */

/* ── FUNC 0x27c288 · MemoryManager::Quit() · size=4 · insn=1 */
/* @0x27c288 bx lr */

/* ── FUNC 0x27c28c · MemoryManager::DumpMemory(__sFILE*) · size=68 · insn=17 */
/* @0x27c28c ldr r2, [pc, #0x30] */
/* @0x27c290 push {r3, lr} */
/* @0x27c294 ldr r2, [pc, r2] */
/* @0x27c298 ldr r3, [pc, #0x28] */
/* @0x27c29c ldr r0, [r2] */
/* @0x27c2a0 ldr r3, [pc, r3] */
/* @0x27c2a4 ldr r1, [pc, #0x20] */
/* @0x27c2a8 ldr r2, [r3] */
/* @0x27c2ac add r1, pc, r1 */
/* @0x27c2b0 ldr r12, [r0] */
/* @0x27c2b4 mov r3, r2 */
/* @0x27c2b8 ldr r12, [r12, #0xc] */
/* @0x27c2bc blx r12 */
/* @0x27c2c0 pop {r3, pc} */
/* @0x27c2c4 andseq r1, r7, r0, lsl #9 */
/* @0x27c2c8 andseq r4, r7, r8, lsr r1 */
/* @0x27c2cc andeq r10, sp, r12, lsl #30 */

/* ── FUNC 0x27c2d0 · MemoryManager::Free(void const*) · size=348 · insn=87 */
/* @0x27c2d0 push {r4, r5, r6, lr} */
/* @0x27c2d4 subs r4, r0, #0 */
/* @0x27c2d8 ldr r5, [pc, #0x134] */
/* @0x27c2dc add r5, pc, r5 */
/* @0x27c2e0 popeq {r4, r5, r6, pc} */
/* @0x27c2e4 ldr r3, [pc, #0x12c] */
/* @0x27c2e8 ldr r6, [r5, r3] */
/* @0x27c2ec ldr r0, [r6] */
/* @0x27c2f0 cmp r0, #0 */
/* @0x27c2f4 beq 0x27c408 <_ZN13MemoryManager4FreeEPKv+0x138> */
/* @0x27c2f8 bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0x27c2fc mov r2, #0 */
/* @0x27c300 mov r3, r2 */
/* @0x27c304 mov r0, #2 */
/* @0x27c308 mov r1, r4 */
/* @0x27c30c bl 0x27bcf4 <_Z11logLocation8ELogTypePKvS1_j> */
/* @0x27c310 mov r0, r4 */
/* @0x27c314 bl 0x27c20c <_Z10bucketFreePKv> */
/* @0x27c318 cmp r0, #0 */
/* @0x27c31c bne 0x27c348 <_ZN13MemoryManager4FreeEPKv+0x78> */
/* @0x27c320 ldr r2, [r4, #-0xc] */
/* @0x27c324 movw r3, #0xc0de */
/* @0x27c328 movt r3, #0xdead */
/* @0x27c32c cmp r2, r3 */
/* @0x27c330 beq 0x27c354 <_ZN13MemoryManager4FreeEPKv+0x84> */
/* @0x27c334 ldr r3, [r4, #-0x4] */
/* @0x27c338 cmp r3, #0 */
/* @0x27c33c blt 0x27c3c8 <_ZN13MemoryManager4FreeEPKv+0xf8> */
/* @0x27c340 mov r0, r4 */
/* @0x27c344 bl 0xb655c <free@plt> */
/* @0x27c348 ldr r0, [r6] */
/* @0x27c34c pop {r4, r5, r6, lr} */
/* @0x27c350 b 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0x27c354 ldr r2, [r4, #-0x8] */
/* @0x27c358 movw r3, #0xb00b */
/* @0x27c35c movt r3, #0xbaad */
/* @0x27c360 cmp r2, r3 */
/* @0x27c364 bne 0x27c334 <_ZN13MemoryManager4FreeEPKv+0x64> */
/* @0x27c368 ldr r2, [pc, #0xac] */
/* @0x27c36c mov r0, r4 */
/* @0x27c370 ldr lr, [pc, #0xa8] */
/* @0x27c374 ldr r3, [r0, #-0x10]! */
/* @0x27c378 ldr r2, [r5, r2] */
/* @0x27c37c ldr r12, [pc, #0xa0] */
/* @0x27c380 ldr r1, [pc, #0xa0] */
/* @0x27c384 ldr r4, [r2] */
/* @0x27c388 rsb r4, r3, r4 */
/* @0x27c38c str r4, [r2] */
/* @0x27c390 ldr r2, [r5, lr] */
/* @0x27c394 ldr lr, [r2] */
/* @0x27c398 rsb lr, r3, lr */
/* @0x27c39c str lr, [r2] */
/* @0x27c3a0 ldr r2, [r5, r12] */
/* @0x27c3a4 ldr r12, [r2] */
/* @0x27c3a8 sub r12, r12, #1 */
/* @0x27c3ac str r12, [r2] */
/* @0x27c3b0 ldr r2, [r5, r1] */
/* @0x27c3b4 ldr r1, [r2] */
/* @0x27c3b8 rsb r3, r3, r1 */
/* @0x27c3bc str r3, [r2] */
/* @0x27c3c0 bl 0xb655c <free@plt> */
/* @0x27c3c4 b 0x27c348 <_ZN13MemoryManager4FreeEPKv+0x78> */
/* @0x27c3c8 bic r3, r3, #-2147483648 */
/* @0x27c3cc cmp r3, #8192 */
/* @0x27c3d0 bhs 0x27c340 <_ZN13MemoryManager4FreeEPKv+0x70> */
/* @0x27c3d4 sub r1, r4, #16 */
/* @0x27c3d8 movw r2, #0xc0de */
/* @0x27c3dc rsb r3, r3, r1 */
/* @0x27c3e0 movt r2, #0xdead */
/* @0x27c3e4 ldr r1, [r3, #0x4] */
/* @0x27c3e8 cmp r1, r2 */
/* @0x27c3ec bne 0x27c340 <_ZN13MemoryManager4FreeEPKv+0x70> */
/* @0x27c3f0 ldr r2, [r3, #0x8] */
/* @0x27c3f4 movw r3, #0xb00b */
/* @0x27c3f8 movt r3, #0xbaad */
/* @0x27c3fc cmp r2, r3 */
/* @0x27c400 bne 0x27c340 <_ZN13MemoryManager4FreeEPKv+0x70> */
/* @0x27c404 b 0x27c348 <_ZN13MemoryManager4FreeEPKv+0x78> */
/* @0x27c408 bl 0x27b918 <_ZN7CBucketILj8ELj131072ELb1EE4FreeEPKv+0x38> */
/* @0x27c40c ldr r0, [r6] */
/* @0x27c410 b 0x27c2f8 <_ZN13MemoryManager4FreeEPKv+0x28> */
/* @0x27c414 andseq r5, r7, r4, ror r9 */
/* @0x27c418 .word 0xfffffbcc */
/* @0x27c41c .word 0xffffe794 */
/* @0x27c420 .word 0xffffe788 */
/* @0x27c424 .word 0xfffffc04 */
/* @0x27c428 .word 0xffffe790 */

/* ── FUNC 0x27c42c · CHashMap<char const*, int, 3>::~CHashMap() · size=40 · insn=10 */
/* @0x27c42c push {r4, lr} */
/* @0x27c430 mov r4, r0 */
/* @0x27c434 ldr r0, [r0, #0x10] */
/* @0x27c438 cmp r0, #0 */
/* @0x27c43c beq 0x27c44c <_ZN8CHashMapIPKciLi3EED2Ev+0x20> */
/* @0x27c440 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x27c444 mov r3, #0 */
/* @0x27c448 str r3, [r4, #0x10] */
/* @0x27c44c mov r0, r4 */
/* @0x27c450 pop {r4, pc} */

/* ── FUNC 0x27c42c · CHashMap<char const*, int, 3>::~CHashMap() · alias of the symbol above · insn=0 */

/* ── FUNC 0x27c454 · MemoryManager::IsAllocated(void const*) · size=208 · insn=52 */
/* @0x27c454 push {r3, r4, r5, lr} */
/* @0x27c458 subs r5, r0, #0 */
/* @0x27c45c beq 0x27c4a4 <_ZN13MemoryManager11IsAllocatedEPKv+0x50> */
/* @0x27c460 ldr r4, [pc, #0xb8] */
/* @0x27c464 ldr r4, [pc, r4] */
/* @0x27c468 ldr r0, [r4] */
/* @0x27c46c cmp r0, #0 */
/* @0x27c470 beq 0x27c514 <_ZN13MemoryManager11IsAllocatedEPKv+0xc0> */
/* @0x27c474 bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0x27c478 ldr r2, [r5, #-0xc] */
/* @0x27c47c movw r3, #0xc0de */
/* @0x27c480 movt r3, #0xdead */
/* @0x27c484 cmp r2, r3 */
/* @0x27c488 beq 0x27c4ac <_ZN13MemoryManager11IsAllocatedEPKv+0x58> */
/* @0x27c48c ldr r3, [r5, #-0x4] */
/* @0x27c490 cmp r3, #0 */
/* @0x27c494 blt 0x27c4d0 <_ZN13MemoryManager11IsAllocatedEPKv+0x7c> */
/* @0x27c498 mov r5, #0 */
/* @0x27c49c ldr r0, [r4] */
/* @0x27c4a0 bl 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0x27c4a4 mov r0, r5 */
/* @0x27c4a8 pop {r3, r4, r5, pc} */
/* @0x27c4ac ldr r2, [r5, #-0x8] */
/* @0x27c4b0 movw r3, #0xb00b */
/* @0x27c4b4 movt r3, #0xbaad */
/* @0x27c4b8 cmp r2, r3 */
/* @0x27c4bc moveq r5, #1 */
/* @0x27c4c0 beq 0x27c49c <_ZN13MemoryManager11IsAllocatedEPKv+0x48> */
/* @0x27c4c4 ldr r3, [r5, #-0x4] */
/* @0x27c4c8 cmp r3, #0 */
/* @0x27c4cc bge 0x27c498 <_ZN13MemoryManager11IsAllocatedEPKv+0x44> */
/* @0x27c4d0 bic r3, r3, #-2147483648 */
/* @0x27c4d4 cmp r3, #8192 */
/* @0x27c4d8 bhs 0x27c498 <_ZN13MemoryManager11IsAllocatedEPKv+0x44> */
/* @0x27c4dc sub r5, r5, #16 */
/* @0x27c4e0 movw r2, #0xc0de */
/* @0x27c4e4 rsb r3, r3, r5 */
/* @0x27c4e8 movt r2, #0xdead */
/* @0x27c4ec ldr r1, [r3, #0x4] */
/* @0x27c4f0 cmp r1, r2 */
/* @0x27c4f4 bne 0x27c498 <_ZN13MemoryManager11IsAllocatedEPKv+0x44> */
/* @0x27c4f8 ldr r5, [r3, #0x8] */
/* @0x27c4fc movw r3, #0xb00b */
/* @0x27c500 movt r3, #0xbaad */
/* @0x27c504 subs r3, r5, r3 */
/* @0x27c508 rsbs r5, r3, #0 */
/* @0x27c50c adcs r5, r5, r3 */
/* @0x27c510 b 0x27c49c <_ZN13MemoryManager11IsAllocatedEPKv+0x48> */
/* @0x27c514 bl 0x27b918 <_ZN7CBucketILj8ELj131072ELb1EE4FreeEPKv+0x38> */
/* @0x27c518 ldr r0, [r4] */
/* @0x27c51c b 0x27c474 <_ZN13MemoryManager11IsAllocatedEPKv+0x20> */
/* @0x27c520 ldrheq r5, [r7], -r8 */

/* ── FUNC 0x27c524 · operator new(unsigned int) · size=24 · insn=6 */
/* @0x27c524 ldr r1, [pc, #0xc] */
/* @0x27c528 movw r2, #0x525 */
/* @0x27c52c mov r3, #1 */
/* @0x27c530 add r1, pc, r1 */
/* @0x27c534 b 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x27c538 strheq r10, [sp], -r0 */

/* ── FUNC 0x27c53c · bucketAlloc(unsigned int, bool) · size=2072 · insn=518 */
/* @0x27c53c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x27c540 mov r5, r0 */
/* @0x27c544 ldr r7, [pc, #0x7d0] */
/* @0x27c548 sub sp, sp, #12 */
/* @0x27c54c ldr r6, [pc, #0x7cc] */
/* @0x27c550 mov r8, r1 */
/* @0x27c554 add r7, pc, r7 */
/* @0x27c558 add r6, pc, r6 */
/* @0x27c55c ldrb r4, [r7, #0x201] */
/* @0x27c560 cmp r4, #0 */
/* @0x27c564 bne 0x27c644 <_Z11bucketAllocjb+0x108> */
/* @0x27c568 ldr r3, [pc, #0x7b4] */
/* @0x27c56c ldr r3, [r6, r3] */
/* @0x27c570 ldrb r3, [r3] */
/* @0x27c574 cmp r3, #0 */
/* @0x27c578 beq 0x27c6e8 <_Z11bucketAllocjb+0x1ac> */
/* @0x27c57c ldr r3, [pc, #0x7a4] */
/* @0x27c580 mov r0, #128 */
/* @0x27c584 mov r2, #16 */
/* @0x27c588 ldr r10, [pc, #0x79c] */
/* @0x27c58c ldr r9, [pc, #0x79c] */
/* @0x27c590 mov r11, #1 */
/* @0x27c594 ldr r3, [r6, r3] */
/* @0x27c598 str r2, [r3] */
/* @0x27c59c bl 0xb6544 <malloc@plt> */
/* @0x27c5a0 ldr r3, [pc, #0x78c] */
/* @0x27c5a4 ldr r2, [pc, #0x78c] */
/* @0x27c5a8 ldr r12, [pc, #0x78c] */
/* @0x27c5ac ldr r3, [r6, r3] */
/* @0x27c5b0 str r2, [sp] */
/* @0x27c5b4 ldr r1, [pc, #0x784] */
/* @0x27c5b8 str r3, [sp, #0x4] */
/* @0x27c5bc ldr r2, [sp, #0x4] */
/* @0x27c5c0 ldr r3, [pc, #0x77c] */
/* @0x27c5c4 str r0, [r2] */
/* @0x27c5c8 ldr r0, [r6, r10] */
/* @0x27c5cc ldr r2, [sp] */
/* @0x27c5d0 str r4, [r0, #0x4] */
/* @0x27c5d4 str r4, [r0, #0x8] */
/* @0x27c5d8 str r4, [r0, #0xc] */
/* @0x27c5dc ldr r0, [r6, r9] */
/* @0x27c5e0 str r4, [r0, #0x4] */
/* @0x27c5e4 str r4, [r0, #0x8] */
/* @0x27c5e8 str r4, [r0, #0xc] */
/* @0x27c5ec ldr r0, [r6, r12] */
/* @0x27c5f0 str r4, [r0, #0x4] */
/* @0x27c5f4 str r4, [r0, #0x8] */
/* @0x27c5f8 str r4, [r0, #0xc] */
/* @0x27c5fc ldr r1, [r6, r1] */
/* @0x27c600 str r4, [r1, #0x4] */
/* @0x27c604 str r4, [r1, #0x8] */
/* @0x27c608 str r4, [r1, #0xc] */
/* @0x27c60c ldr r2, [r6, r2] */
/* @0x27c610 str r4, [r2, #0x4] */
/* @0x27c614 str r4, [r2, #0x8] */
/* @0x27c618 str r4, [r2, #0xc] */
/* @0x27c61c ldr r2, [pc, #0x724] */
/* @0x27c620 ldr r2, [r6, r2] */
/* @0x27c624 str r4, [r2, #0x4] */
/* @0x27c628 str r4, [r2, #0x8] */
/* @0x27c62c str r4, [r2, #0xc] */
/* @0x27c630 ldr r3, [r6, r3] */
/* @0x27c634 strb r11, [r7, #0x201] */
/* @0x27c638 str r4, [r3, #0x4] */
/* @0x27c63c str r4, [r3, #0x8] */
/* @0x27c640 str r4, [r3, #0xc] */
/* @0x27c644 cmp r5, #16384 */
/* @0x27c648 cmpne r5, #256 */
/* @0x27c64c movls r4, #0 */
/* @0x27c650 movhi r4, #1 */
/* @0x27c654 bhi 0x27c6e8 <_Z11bucketAllocjb+0x1ac> */
/* @0x27c658 cmp r5, #8 */
/* @0x27c65c bls 0x27c794 <_Z11bucketAllocjb+0x258> */
/* @0x27c660 cmp r5, #16 */
/* @0x27c664 bls 0x27c800 <_Z11bucketAllocjb+0x2c4> */
/* @0x27c668 cmp r5, #32 */
/* @0x27c66c bls 0x27c6f4 <_Z11bucketAllocjb+0x1b8> */
/* @0x27c670 cmp r5, #64 */
/* @0x27c674 bls 0x27c850 <_Z11bucketAllocjb+0x314> */
/* @0x27c678 cmp r5, #128 */
/* @0x27c67c bls 0x27c8a0 <_Z11bucketAllocjb+0x364> */
/* @0x27c680 cmp r5, #256 */
/* @0x27c684 bls 0x27c744 <_Z11bucketAllocjb+0x208> */
/* @0x27c688 cmp r5, #16384 */
/* @0x27c68c bne 0x27c984 <_Z11bucketAllocjb+0x448> */
/* @0x27c690 ldr r3, [pc, #0x6ac] */
/* @0x27c694 ldr r4, [r6, r3] */
/* @0x27c698 ldr r5, [r4, #0x8] */
/* @0x27c69c cmp r5, #0 */
/* @0x27c6a0 beq 0x27ca4c <_Z11bucketAllocjb+0x510> */
/* @0x27c6a4 ldr r1, [r4, #0x10] */
/* @0x27c6a8 ldr r2, [r5] */
/* @0x27c6ac ldr r3, [r4, #0xc] */
/* @0x27c6b0 cmp r8, #0 */
/* @0x27c6b4 sub r1, r1, #1 */
/* @0x27c6b8 str r2, [r4, #0x8] */
/* @0x27c6bc add r3, r3, #1 */
/* @0x27c6c0 str r1, [r4, #0x10] */
/* @0x27c6c4 str r3, [r4, #0xc] */
/* @0x27c6c8 beq 0x27c6dc <_Z11bucketAllocjb+0x1a0> */
/* @0x27c6cc mov r0, r5 */
/* @0x27c6d0 mov r1, #0 */
/* @0x27c6d4 mov r2, #16384 */
/* @0x27c6d8 bl 0xb65b0 <memset@plt> */
/* @0x27c6dc mov r0, r5 */
/* @0x27c6e0 add sp, sp, #12 */
/* @0x27c6e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x27c6e8 mov r0, #0 */
/* @0x27c6ec add sp, sp, #12 */
/* @0x27c6f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x27c6f4 ldr r3, [pc, #0x640] */
/* @0x27c6f8 ldr r4, [r6, r3] */
/* @0x27c6fc ldr r5, [r4, #0x8] */
/* @0x27c700 cmp r5, #0 */
/* @0x27c704 beq 0x27cb6c <_Z11bucketAllocjb+0x630> */
/* @0x27c708 ldr r3, [r4, #0x10] */
/* @0x27c70c ldr r2, [r5] */
/* @0x27c710 ldr r1, [r4, #0xc] */
/* @0x27c714 cmp r8, #0 */
/* @0x27c718 sub r3, r3, #1 */
/* @0x27c71c str r2, [r4, #0x8] */
/* @0x27c720 str r3, [r4, #0x10] */
/* @0x27c724 add r3, r1, #1 */
/* @0x27c728 str r3, [r4, #0xc] */
/* @0x27c72c beq 0x27c6dc <_Z11bucketAllocjb+0x1a0> */
/* @0x27c730 mov r0, r5 */
/* @0x27c734 mov r1, #0 */
/* @0x27c738 mov r2, #32 */
/* @0x27c73c bl 0xb65b0 <memset@plt> */
/* @0x27c740 b 0x27c6dc <_Z11bucketAllocjb+0x1a0> */
/* @0x27c744 ldr r3, [pc, #0x5fc] */
/* @0x27c748 ldr r4, [r6, r3] */
/* @0x27c74c ldr r5, [r4, #0x8] */
/* @0x27c750 cmp r5, #0 */
/* @0x27c754 beq 0x27c8f0 <_Z11bucketAllocjb+0x3b4> */
/* @0x27c758 ldr r3, [r4, #0x10] */
/* @0x27c75c ldr r2, [r5] */
/* @0x27c760 ldr r1, [r4, #0xc] */
/* @0x27c764 cmp r8, #0 */
/* @0x27c768 sub r3, r3, #1 */
/* @0x27c76c str r2, [r4, #0x8] */
/* @0x27c770 str r3, [r4, #0x10] */
/* @0x27c774 add r3, r1, #1 */
/* @0x27c778 str r3, [r4, #0xc] */
/* @0x27c77c beq 0x27c6dc <_Z11bucketAllocjb+0x1a0> */
/* @0x27c780 mov r0, r5 */
/* @0x27c784 mov r1, #0 */
/* @0x27c788 mov r2, #256 */
/* @0x27c78c bl 0xb65b0 <memset@plt> */
/* @0x27c790 b 0x27c6dc <_Z11bucketAllocjb+0x1a0> */
/* @0x27c794 ldr r3, [pc, #0x590] */
/* @0x27c798 ldr r4, [r6, r3] */
/* @0x27c79c ldr r0, [r4, #0x8] */
/* @0x27c7a0 cmp r0, #0 */
/* @0x27c7a4 beq 0x27c9bc <_Z11bucketAllocjb+0x480> */
/* @0x27c7a8 ldr r3, [r4, #0x10] */
/* @0x27c7ac ldr r2, [r0] */
/* @0x27c7b0 ldr r1, [r4, #0xc] */
/* @0x27c7b4 cmp r8, #0 */
/* @0x27c7b8 sub r3, r3, #1 */
/* @0x27c7bc str r2, [r4, #0x8] */
/* @0x27c7c0 str r3, [r4, #0x10] */
/* @0x27c7c4 add r3, r1, #1 */
/* @0x27c7c8 str r3, [r4, #0xc] */
/* @0x27c7cc beq 0x27c6e0 <_Z11bucketAllocjb+0x1a4> */
/* @0x27c7d0 mov r3, r0 */
/* @0x27c7d4 mov r2, #0 */
/* @0x27c7d8 strb r2, [r3], #1 */
/* @0x27c7dc add r3, r3, #1 */
/* @0x27c7e0 strb r2, [r0, #0x1] */
/* @0x27c7e4 strb r2, [r3], #1 */
/* @0x27c7e8 strb r2, [r3], #1 */
/* @0x27c7ec strb r2, [r3], #1 */
/* @0x27c7f0 strb r2, [r3], #1 */
/* @0x27c7f4 strb r2, [r3], #1 */
/* @0x27c7f8 strb r2, [r3] */
/* @0x27c7fc b 0x27c6e0 <_Z11bucketAllocjb+0x1a4> */
/* @0x27c800 ldr r3, [pc, #0x528] */
/* @0x27c804 ldr r4, [r6, r3] */
/* @0x27c808 ldr r5, [r4, #0x8] */
/* @0x27c80c cmp r5, #0 */
/* @0x27c810 beq 0x27cadc <_Z11bucketAllocjb+0x5a0> */
/* @0x27c814 ldr r3, [r4, #0x10] */
/* @0x27c818 ldr r2, [r5] */
/* @0x27c81c ldr r1, [r4, #0xc] */
/* @0x27c820 cmp r8, #0 */
/* @0x27c824 sub r3, r3, #1 */
/* @0x27c828 str r2, [r4, #0x8] */
/* @0x27c82c str r3, [r4, #0x10] */
/* @0x27c830 add r3, r1, #1 */
/* @0x27c834 str r3, [r4, #0xc] */
/* @0x27c838 beq 0x27c6dc <_Z11bucketAllocjb+0x1a0> */
/* @0x27c83c mov r0, r5 */
/* @0x27c840 mov r1, #0 */
/* @0x27c844 mov r2, #16 */
/* @0x27c848 bl 0xb65b0 <memset@plt> */
/* @0x27c84c b 0x27c6dc <_Z11bucketAllocjb+0x1a0> */
/* @0x27c850 ldr r3, [pc, #0x4e8] */
/* @0x27c854 ldr r4, [r6, r3] */
/* @0x27c858 ldr r5, [r4, #0x8] */
/* @0x27c85c cmp r5, #0 */
/* @0x27c860 beq 0x27cbfc <_Z11bucketAllocjb+0x6c0> */
/* @0x27c864 ldr r3, [r4, #0x10] */
/* @0x27c868 ldr r2, [r5] */
/* @0x27c86c ldr r1, [r4, #0xc] */
/* @0x27c870 cmp r8, #0 */
/* @0x27c874 sub r3, r3, #1 */
/* @0x27c878 str r2, [r4, #0x8] */
/* @0x27c87c str r3, [r4, #0x10] */
/* @0x27c880 add r3, r1, #1 */
/* @0x27c884 str r3, [r4, #0xc] */
/* @0x27c888 beq 0x27c6dc <_Z11bucketAllocjb+0x1a0> */
/* @0x27c88c mov r0, r5 */
/* @0x27c890 mov r1, #0 */
/* @0x27c894 mov r2, #64 */
/* @0x27c898 bl 0xb65b0 <memset@plt> */
/* @0x27c89c b 0x27c6dc <_Z11bucketAllocjb+0x1a0> */
/* @0x27c8a0 ldr r3, [pc, #0x490] */
/* @0x27c8a4 ldr r4, [r6, r3] */
/* @0x27c8a8 ldr r5, [r4, #0x8] */
/* @0x27c8ac cmp r5, #0 */
/* @0x27c8b0 beq 0x27cc8c <_Z11bucketAllocjb+0x750> */
/* @0x27c8b4 ldr r3, [r4, #0x10] */
/* @0x27c8b8 ldr r2, [r5] */
/* @0x27c8bc ldr r1, [r4, #0xc] */
/* @0x27c8c0 cmp r8, #0 */
/* @0x27c8c4 sub r3, r3, #1 */
/* @0x27c8c8 str r2, [r4, #0x8] */
/* @0x27c8cc str r3, [r4, #0x10] */
/* @0x27c8d0 add r3, r1, #1 */
/* @0x27c8d4 str r3, [r4, #0xc] */
/* @0x27c8d8 beq 0x27c6dc <_Z11bucketAllocjb+0x1a0> */
/* @0x27c8dc mov r0, r5 */
/* @0x27c8e0 mov r1, #0 */
/* @0x27c8e4 mov r2, #128 */
/* @0x27c8e8 bl 0xb65b0 <memset@plt> */
/* @0x27c8ec b 0x27c6dc <_Z11bucketAllocjb+0x1a0> */
/* @0x27c8f0 mov r0, #264 */
/* @0x27c8f4 movt r0, #0x10 */
/* @0x27c8f8 bl 0x27c524 <_Znwj> */
/* @0x27c8fc mov r1, #120 */
/* @0x27c900 mov r2, #256 */
/* @0x27c904 movt r2, #0x10 */
/* @0x27c908 mov r6, r0 */
/* @0x27c90c add r0, r0, #8 */
/* @0x27c910 bl 0xb65b0 <memset@plt> */
/* @0x27c914 ldr r3, [r4, #0x4] */
/* @0x27c918 movw r1, #0x107 */
/* @0x27c91c movt r1, #0x10 */
/* @0x27c920 mov r0, r6 */
/* @0x27c924 add r1, r6, r1 */
/* @0x27c928 str r3, [r6] */
/* @0x27c92c add r7, r6, #264 */
/* @0x27c930 bic r7, r7, #255 */
/* @0x27c934 str r6, [r4, #0x4] */
/* @0x27c938 bl 0x27bcf8 <_Z23addPageToGlobalPageListPvS_> */
/* @0x27c93c ldr r1, [r4, #0x8] */
/* @0x27c940 add r5, r7, #1044480 */
/* @0x27c944 mov r3, r7 */
/* @0x27c948 ldr r0, [r4, #0x10] */
/* @0x27c94c add r12, r5, #3840 */
/* @0x27c950 str r4, [r6, #0x4] */
/* @0x27c954 mov r2, r7 */
/* @0x27c958 str r1, [r3], #256 */
/* @0x27c95c b 0x27c964 <_Z11bucketAllocjb+0x428> */
/* @0x27c960 mov r2, r1 */
/* @0x27c964 mov r1, r3 */
/* @0x27c968 str r2, [r3], #256 */
/* @0x27c96c cmp r3, r12 */
/* @0x27c970 bne 0x27c960 <_Z11bucketAllocjb+0x424> */
/* @0x27c974 add r3, r0, #4080 */
/* @0x27c978 add r5, r5, #3584 */
/* @0x27c97c add r3, r3, #15 */
/* @0x27c980 b 0x27c760 <_Z11bucketAllocjb+0x224> */
/* @0x27c984 ldr r0, [pc, #0x3c0] */
/* @0x27c988 mov r3, r5 */
/* @0x27c98c ldr r1, [pc, #0x3bc] */
/* @0x27c990 mov r2, r5 */
/* @0x27c994 ldr r0, [r6, r0] */
/* @0x27c998 add r1, pc, r1 */
/* @0x27c99c ldr r0, [r0] */
/* @0x27c9a0 ldr r12, [r0] */
/* @0x27c9a4 ldr r12, [r12, #0xc] */
/* @0x27c9a8 blx r12 */
/* @0x27c9ac mov r3, #42 */
/* @0x27c9b0 mov r0, r4 */
/* @0x27c9b4 str r3, [r4] */
/* @0x27c9b8 b 0x27c6e0 <_Z11bucketAllocjb+0x1a4> */
/* @0x27c9bc mov r0, #16 */
/* @0x27c9c0 movt r0, #0x2 */
/* @0x27c9c4 bl 0x27c524 <_Znwj> */
/* @0x27c9c8 mov r2, #8 */
/* @0x27c9cc mov r1, #120 */
/* @0x27c9d0 mov r5, r0 */
/* @0x27c9d4 add r0, r0, r2 */
/* @0x27c9d8 movt r2, #0x2 */
/* @0x27c9dc add r6, r5, #16 */
/* @0x27c9e0 bl 0xb65b0 <memset@plt> */
/* @0x27c9e4 ldr r3, [r4, #0x4] */
/* @0x27c9e8 add r1, r5, #131072 */
/* @0x27c9ec mov r0, r5 */
/* @0x27c9f0 add r1, r1, #15 */
/* @0x27c9f4 bic r6, r6, #7 */
/* @0x27c9f8 str r3, [r5] */
/* @0x27c9fc str r5, [r4, #0x4] */
/* @0x27ca00 bl 0x27bcf8 <_Z23addPageToGlobalPageListPvS_> */
/* @0x27ca04 ldr r1, [r4, #0x8] */
/* @0x27ca08 add r0, r6, #130048 */
/* @0x27ca0c mov r3, r6 */
/* @0x27ca10 ldr r7, [r4, #0x10] */
/* @0x27ca14 add r12, r0, #1016 */
/* @0x27ca18 str r4, [r5, #0x4] */
/* @0x27ca1c mov r2, r6 */
/* @0x27ca20 str r1, [r3], #8 */
/* @0x27ca24 b 0x27ca2c <_Z11bucketAllocjb+0x4f0> */
/* @0x27ca28 mov r2, r1 */
/* @0x27ca2c mov r1, r3 */
/* @0x27ca30 str r2, [r3], #8 */
/* @0x27ca34 cmp r3, r12 */
/* @0x27ca38 bne 0x27ca28 <_Z11bucketAllocjb+0x4ec> */
/* @0x27ca3c add r3, r7, #16320 */
/* @0x27ca40 add r0, r0, #1008 */
/* @0x27ca44 add r3, r3, #63 */
/* @0x27ca48 b 0x27c7b0 <_Z11bucketAllocjb+0x274> */
/* @0x27ca4c movw r0, #0x4008 */
/* @0x27ca50 movt r0, #0x4 */
/* @0x27ca54 bl 0x27c524 <_Znwj> */
/* @0x27ca58 mov r1, #120 */
/* @0x27ca5c mov r2, #278528 */
/* @0x27ca60 mov r6, r0 */
/* @0x27ca64 add r0, r0, #8 */
/* @0x27ca68 bl 0xb65b0 <memset@plt> */
/* @0x27ca6c ldr r2, [r4, #0x4] */
/* @0x27ca70 add r3, r6, #16384 */
/* @0x27ca74 add r1, r6, #278528 */
/* @0x27ca78 add r3, r3, #8 */
/* @0x27ca7c add r1, r1, #7 */
/* @0x27ca80 str r2, [r6] */
/* @0x27ca84 bic r3, r3, #16320 */
/* @0x27ca88 mov r0, r6 */
/* @0x27ca8c bic r5, r3, #63 */
/* @0x27ca90 str r6, [r4, #0x4] */
/* @0x27ca94 bl 0x27bcf8 <_Z23addPageToGlobalPageListPvS_> */
/* @0x27ca98 ldr r0, [r4, #0x8] */
/* @0x27ca9c add r3, r5, #16384 */
/* @0x27caa0 ldr r1, [r4, #0x10] */
/* @0x27caa4 add r12, r5, #245760 */
/* @0x27caa8 str r4, [r6, #0x4] */
/* @0x27caac mov r2, r5 */
/* @0x27cab0 str r0, [r5] */
/* @0x27cab4 b 0x27cabc <_Z11bucketAllocjb+0x580> */
/* @0x27cab8 mov r2, r0 */
/* @0x27cabc str r2, [r3] */
/* @0x27cac0 mov r0, r3 */
/* @0x27cac4 add r3, r3, #16384 */
/* @0x27cac8 cmp r3, r12 */
/* @0x27cacc bne 0x27cab8 <_Z11bucketAllocjb+0x57c> */
/* @0x27cad0 add r1, r1, #15 */
/* @0x27cad4 add r5, r5, #229376 */
/* @0x27cad8 b 0x27c6ac <_Z11bucketAllocjb+0x170> */
/* @0x27cadc mov r0, #24 */
/* @0x27cae0 movt r0, #0x4 */
/* @0x27cae4 bl 0x27c524 <_Znwj> */
/* @0x27cae8 mov r1, #120 */
/* @0x27caec mov r2, #16 */
/* @0x27caf0 movt r2, #0x4 */
/* @0x27caf4 mov r6, r0 */
/* @0x27caf8 add r0, r0, #8 */
/* @0x27cafc bl 0xb65b0 <memset@plt> */
/* @0x27cb00 ldr r3, [r4, #0x4] */
/* @0x27cb04 add r1, r6, #262144 */
/* @0x27cb08 mov r0, r6 */
/* @0x27cb0c add r1, r1, #23 */
/* @0x27cb10 add r7, r6, #24 */
/* @0x27cb14 str r3, [r6] */
/* @0x27cb18 bic r7, r7, #15 */
/* @0x27cb1c str r6, [r4, #0x4] */
/* @0x27cb20 bl 0x27bcf8 <_Z23addPageToGlobalPageListPvS_> */
/* @0x27cb24 ldr r1, [r4, #0x8] */
/* @0x27cb28 add r5, r7, #261120 */
/* @0x27cb2c mov r3, r7 */
/* @0x27cb30 ldr r0, [r4, #0x10] */
/* @0x27cb34 add r12, r5, #1008 */
/* @0x27cb38 str r4, [r6, #0x4] */
/* @0x27cb3c mov r2, r7 */
/* @0x27cb40 str r1, [r3], #16 */
/* @0x27cb44 b 0x27cb4c <_Z11bucketAllocjb+0x610> */
/* @0x27cb48 mov r2, r1 */
/* @0x27cb4c mov r1, r3 */
/* @0x27cb50 str r2, [r3], #16 */
/* @0x27cb54 cmp r3, r12 */
/* @0x27cb58 bne 0x27cb48 <_Z11bucketAllocjb+0x60c> */
/* @0x27cb5c add r3, r0, #16320 */
/* @0x27cb60 add r5, r5, #992 */
/* @0x27cb64 add r3, r3, #63 */
/* @0x27cb68 b 0x27c81c <_Z11bucketAllocjb+0x2e0> */
/* @0x27cb6c mov r0, #40 */
/* @0x27cb70 movt r0, #0x4 */
/* @0x27cb74 bl 0x27c524 <_Znwj> */
/* @0x27cb78 mov r1, #120 */
/* @0x27cb7c mov r2, #32 */
/* @0x27cb80 movt r2, #0x4 */
/* @0x27cb84 mov r6, r0 */
/* @0x27cb88 add r0, r0, #8 */
/* @0x27cb8c bl 0xb65b0 <memset@plt> */
/* @0x27cb90 ldr r3, [r4, #0x4] */
/* @0x27cb94 add r1, r6, #262144 */
/* @0x27cb98 mov r0, r6 */
/* @0x27cb9c add r1, r1, #39 */
/* @0x27cba0 add r7, r6, #40 */
/* @0x27cba4 str r3, [r6] */
/* @0x27cba8 bic r7, r7, #31 */
/* @0x27cbac str r6, [r4, #0x4] */
/* @0x27cbb0 bl 0x27bcf8 <_Z23addPageToGlobalPageListPvS_> */
/* @0x27cbb4 ldr r1, [r4, #0x8] */
/* @0x27cbb8 add r5, r7, #261120 */
/* @0x27cbbc mov r3, r7 */
/* @0x27cbc0 ldr r0, [r4, #0x10] */
/* @0x27cbc4 add r12, r5, #992 */
/* @0x27cbc8 str r4, [r6, #0x4] */
/* @0x27cbcc mov r2, r7 */
/* @0x27cbd0 str r1, [r3], #32 */
/* @0x27cbd4 b 0x27cbdc <_Z11bucketAllocjb+0x6a0> */
/* @0x27cbd8 mov r2, r1 */
/* @0x27cbdc mov r1, r3 */
/* @0x27cbe0 str r2, [r3], #32 */
/* @0x27cbe4 cmp r3, r12 */
/* @0x27cbe8 bne 0x27cbd8 <_Z11bucketAllocjb+0x69c> */
/* @0x27cbec add r3, r0, #8128 */
/* @0x27cbf0 add r5, r5, #960 */
/* @0x27cbf4 add r3, r3, #63 */
/* @0x27cbf8 b 0x27c710 <_Z11bucketAllocjb+0x1d4> */
/* @0x27cbfc mov r0, #72 */
/* @0x27cc00 movt r0, #0x8 */
/* @0x27cc04 bl 0x27c524 <_Znwj> */
/* @0x27cc08 mov r1, #120 */
/* @0x27cc0c mov r2, #64 */
/* @0x27cc10 movt r2, #0x8 */
/* @0x27cc14 mov r6, r0 */
/* @0x27cc18 add r0, r0, #8 */
/* @0x27cc1c bl 0xb65b0 <memset@plt> */
/* @0x27cc20 ldr r3, [r4, #0x4] */
/* @0x27cc24 add r1, r6, #524288 */
/* @0x27cc28 mov r0, r6 */
/* @0x27cc2c add r1, r1, #71 */
/* @0x27cc30 add r7, r6, #72 */
/* @0x27cc34 str r3, [r6] */
/* @0x27cc38 bic r7, r7, #63 */
/* @0x27cc3c str r6, [r4, #0x4] */
/* @0x27cc40 bl 0x27bcf8 <_Z23addPageToGlobalPageListPvS_> */
/* @0x27cc44 ldr r1, [r4, #0x8] */
/* @0x27cc48 add r5, r7, #520192 */
/* @0x27cc4c mov r3, r7 */
/* @0x27cc50 ldr r0, [r4, #0x10] */
/* @0x27cc54 add r12, r5, #4032 */
/* @0x27cc58 str r4, [r6, #0x4] */
/* @0x27cc5c mov r2, r7 */
/* @0x27cc60 str r1, [r3], #64 */
/* @0x27cc64 b 0x27cc6c <_Z11bucketAllocjb+0x730> */
/* @0x27cc68 mov r2, r1 */
/* @0x27cc6c mov r1, r3 */
/* @0x27cc70 str r2, [r3], #64 */
/* @0x27cc74 cmp r3, r12 */
/* @0x27cc78 bne 0x27cc68 <_Z11bucketAllocjb+0x72c> */
/* @0x27cc7c add r3, r0, #8128 */
/* @0x27cc80 add r5, r5, #3968 */
/* @0x27cc84 add r3, r3, #63 */
/* @0x27cc88 b 0x27c86c <_Z11bucketAllocjb+0x330> */
/* @0x27cc8c mov r0, #136 */
/* @0x27cc90 movt r0, #0x8 */
/* @0x27cc94 bl 0x27c524 <_Znwj> */
/* @0x27cc98 mov r1, #120 */
/* @0x27cc9c mov r2, #128 */
/* @0x27cca0 movt r2, #0x8 */
/* @0x27cca4 mov r6, r0 */
/* @0x27cca8 add r0, r0, #8 */
/* @0x27ccac bl 0xb65b0 <memset@plt> */
/* @0x27ccb0 ldr r3, [r4, #0x4] */
/* @0x27ccb4 add r1, r6, #524288 */
/* @0x27ccb8 mov r0, r6 */
/* @0x27ccbc add r1, r1, #135 */
/* @0x27ccc0 add r7, r6, #136 */
/* @0x27ccc4 str r3, [r6] */
/* @0x27ccc8 bic r7, r7, #127 */
/* @0x27cccc str r6, [r4, #0x4] */
/* @0x27ccd0 bl 0x27bcf8 <_Z23addPageToGlobalPageListPvS_> */
/* @0x27ccd4 ldr r1, [r4, #0x8] */
/* @0x27ccd8 add r5, r7, #520192 */
/* @0x27ccdc mov r3, r7 */
/* @0x27cce0 ldr r0, [r4, #0x10] */
/* @0x27cce4 add r12, r5, #3968 */
/* @0x27cce8 str r4, [r6, #0x4] */
/* @0x27ccec mov r2, r7 */
/* @0x27ccf0 str r1, [r3], #128 */
/* @0x27ccf4 b 0x27ccfc <_Z11bucketAllocjb+0x7c0> */
/* @0x27ccf8 mov r2, r1 */
/* @0x27ccfc mov r1, r3 */
/* @0x27cd00 str r2, [r3], #128 */
/* @0x27cd04 cmp r3, r12 */
/* @0x27cd08 bne 0x27ccf8 <_Z11bucketAllocjb+0x7bc> */
/* @0x27cd0c add r3, r0, #4080 */
/* @0x27cd10 add r5, r5, #3840 */
/* @0x27cd14 add r3, r3, #15 */
/* @0x27cd18 b 0x27c8bc <_Z11bucketAllocjb+0x380> */
/* @0x27cd1c subeq r9, sp, r12, lsr pc */
/* @0x27cd20 ldrsheq r5, [r7], -r8 */
/* @0x27cd24 .word 0xfffffc00 */
/* @0x27cd28 .word 0xfffffbdc */
/* @0x27cd2c .word 0xfffffbe8 */
/* @0x27cd30 .word 0xfffffbec */
/* @0x27cd34 .word 0xfffffbe0 */
/* @0x27cd38 .word 0xfffffbf8 */
/* @0x27cd3c .word 0xfffffbf0 */
/* @0x27cd40 .word 0xfffffbf4 */
/* @0x27cd44 .word 0xfffffc08 */
/* @0x27cd48 .word 0xfffffbfc */
/* @0x27cd4c .word 0xffffbac4 */
/* @0x27cd50 andeq r10, sp, r12, ror r8 */

/* ── FUNC 0x27cd54 · MemoryManager::_Alloc(unsigned int, char const*, int, bool) · size=292 · insn=73 */
/* @0x27cd54 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x27cd58 mov r7, r0 */
/* @0x27cd5c ldr r8, [pc, #0xfc] */
/* @0x27cd60 mov r4, r3 */
/* @0x27cd64 ldr r2, [pc, #0xf8] */
/* @0x27cd68 add r8, pc, r8 */
/* @0x27cd6c ldr r6, [r8, r2] */
/* @0x27cd70 ldr r0, [r6] */
/* @0x27cd74 cmp r0, #0 */
/* @0x27cd78 beq 0x27ce54 <_ZN13MemoryManager6_AllocEjPKcib+0x100> */
/* @0x27cd7c bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0x27cd80 mov r1, r4 */
/* @0x27cd84 mov r0, r7 */
/* @0x27cd88 bl 0x27c53c <_Z11bucketAllocjb> */
/* @0x27cd8c subs r9, r0, #0 */
/* @0x27cd90 movne r4, r9 */
/* @0x27cd94 beq 0x27cda8 <_ZN13MemoryManager6_AllocEjPKcib+0x54> */
/* @0x27cd98 ldr r0, [r6] */
/* @0x27cd9c bl 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0x27cda0 mov r0, r4 */
/* @0x27cda4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x27cda8 adds r0, r7, #16 */
/* @0x27cdac mov r3, #0 */
/* @0x27cdb0 adc r1, r3, #0 */
/* @0x27cdb4 mvn r4, #1 */
/* @0x27cdb8 mov r5, #0 */
/* @0x27cdbc cmp r4, r0 */
/* @0x27cdc0 sbcs r3, r5, r1 */
/* @0x27cdc4 bge 0x27cdd0 <_ZN13MemoryManager6_AllocEjPKcib+0x7c> */
/* @0x27cdc8 mov r4, #0 */
/* @0x27cdcc b 0x27cd98 <_ZN13MemoryManager6_AllocEjPKcib+0x44> */
/* @0x27cdd0 bl 0xb6544 <malloc@plt> */
/* @0x27cdd4 cmp r0, #0 */
/* @0x27cdd8 beq 0x27cdc8 <_ZN13MemoryManager6_AllocEjPKcib+0x74> */
/* @0x27cddc ldr r1, [pc, #0x84] */
/* @0x27cde0 movw r2, #0xc0de */
/* @0x27cde4 str r7, [r0] */
/* @0x27cde8 movt r2, #0xdead */
/* @0x27cdec str r9, [r0, #0xc] */
/* @0x27cdf0 movw r3, #0xb00b */
/* @0x27cdf4 str r2, [r0, #0x4] */
/* @0x27cdf8 movt r3, #0xbaad */
/* @0x27cdfc str r3, [r0, #0x8] */
/* @0x27ce00 add r4, r0, #16 */
/* @0x27ce04 ldr r3, [r8, r1] */
/* @0x27ce08 ldr r0, [pc, #0x5c] */
/* @0x27ce0c ldr r1, [pc, #0x5c] */
/* @0x27ce10 ldr r12, [r3] */
/* @0x27ce14 ldr r2, [pc, #0x58] */
/* @0x27ce18 add r12, r7, r12 */
/* @0x27ce1c str r12, [r3] */
/* @0x27ce20 ldr r3, [r8, r0] */
/* @0x27ce24 ldr r0, [r3] */
/* @0x27ce28 add r0, r7, r0 */
/* @0x27ce2c str r0, [r3] */
/* @0x27ce30 ldr r3, [r8, r1] */
/* @0x27ce34 ldr r1, [r3] */
/* @0x27ce38 add r1, r1, #1 */
/* @0x27ce3c str r1, [r3] */
/* @0x27ce40 ldr r3, [r8, r2] */
/* @0x27ce44 ldr r2, [r3] */
/* @0x27ce48 add r7, r7, r2 */
/* @0x27ce4c str r7, [r3] */
/* @0x27ce50 b 0x27cd98 <_ZN13MemoryManager6_AllocEjPKcib+0x44> */
/* @0x27ce54 bl 0x27b918 <_ZN7CBucketILj8ELj131072ELb1EE4FreeEPKv+0x38> */
/* @0x27ce58 ldr r0, [r6] */
/* @0x27ce5c b 0x27cd7c <_ZN13MemoryManager6_AllocEjPKcib+0x28> */
/* @0x27ce60 andseq r4, r7, r8, ror #29 */
/* @0x27ce64 .word 0xfffffbcc */
/* @0x27ce68 .word 0xffffe788 */
/* @0x27ce6c .word 0xffffe794 */
/* @0x27ce70 .word 0xfffffc04 */
/* @0x27ce74 .word 0xffffe790 */

/* ── FUNC 0x27ce78 · MemoryManager::Alloc(unsigned int, char const*, int, bool) · size=100 · insn=25 */
/* @0x27ce78 push {r4, r5, r6, lr} */
/* @0x27ce7c subs r6, r0, #0 */
/* @0x27ce80 mov r5, r3 */
/* @0x27ce84 beq 0x27cec4 <_ZN13MemoryManager5AllocEjPKcib+0x4c> */
/* @0x27ce88 bl 0x27cd54 <_ZN13MemoryManager6_AllocEjPKcib> */
/* @0x27ce8c adds r1, r0, #0 */
/* @0x27ce90 mov r4, r0 */
/* @0x27ce94 movne r1, #1 */
/* @0x27ce98 tst r1, r5 */
/* @0x27ce9c bne 0x27cecc <_ZN13MemoryManager5AllocEjPKcib+0x54> */
/* @0x27cea0 cmp r1, #0 */
/* @0x27cea4 beq 0x27cec4 <_ZN13MemoryManager5AllocEjPKcib+0x4c> */
/* @0x27cea8 mov r0, #0 */
/* @0x27ceac mov r3, r6 */
/* @0x27ceb0 mov r1, r0 */
/* @0x27ceb4 mov r2, r4 */
/* @0x27ceb8 bl 0x27bcf4 <_Z11logLocation8ELogTypePKvS1_j> */
/* @0x27cebc mov r0, r4 */
/* @0x27cec0 pop {r4, r5, r6, pc} */
/* @0x27cec4 mov r0, #0 */
/* @0x27cec8 pop {r4, r5, r6, pc} */
/* @0x27cecc mov r1, #0 */
/* @0x27ced0 mov r2, r6 */
/* @0x27ced4 bl 0xb65b0 <memset@plt> */
/* @0x27ced8 b 0x27cea8 <_ZN13MemoryManager5AllocEjPKcib+0x30> */

/* ── FUNC 0x27cedc · MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) · size=396 · insn=99 */
/* @0x27cedc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x27cee0 subs r5, r0, #0 */
/* @0x27cee4 mov r7, r1 */
/* @0x27cee8 mov r9, r2 */
/* @0x27ceec mov r8, r3 */
/* @0x27cef0 beq 0x27d038 <_ZN13MemoryManager7ReAllocEPvjPKcib+0x15c> */
/* @0x27cef4 ldr r4, [pc, #0x160] */
/* @0x27cef8 ldr r4, [pc, r4] */
/* @0x27cefc ldr r0, [r4] */
/* @0x27cf00 cmp r0, #0 */
/* @0x27cf04 beq 0x27d050 <_ZN13MemoryManager7ReAllocEPvjPKcib+0x174> */
/* @0x27cf08 bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0x27cf0c mov r0, r5 */
/* @0x27cf10 bl 0x27c1e4 <_Z10bucketSizePKv> */
/* @0x27cf14 subs r6, r0, #0 */
/* @0x27cf18 bne 0x27cfa0 <_ZN13MemoryManager7ReAllocEPvjPKcib+0xc4> */
/* @0x27cf1c ldr r2, [r5, #-0xc] */
/* @0x27cf20 movw r3, #0xc0de */
/* @0x27cf24 movt r3, #0xdead */
/* @0x27cf28 ldr r6, [r5, #-0x10] */
/* @0x27cf2c cmp r2, r3 */
/* @0x27cf30 beq 0x27d020 <_ZN13MemoryManager7ReAllocEPvjPKcib+0x144> */
/* @0x27cf34 ldr r6, [r5, #-0x4] */
/* @0x27cf38 cmp r6, #0 */
/* @0x27cf3c blt 0x27cf64 <_ZN13MemoryManager7ReAllocEPvjPKcib+0x88> */
/* @0x27cf40 ldr r3, [pc, #0x118] */
/* @0x27cf44 ldr r1, [pc, #0x118] */
/* @0x27cf48 ldr r3, [pc, r3] */
/* @0x27cf4c add r1, pc, r1 */
/* @0x27cf50 ldr r0, [r3] */
/* @0x27cf54 ldr r3, [r0] */
/* @0x27cf58 ldr r3, [r3, #0xc] */
/* @0x27cf5c blx r3 */
/* @0x27cf60 bl 0xb6c88 <abort@plt> */
/* @0x27cf64 bic r3, r6, #-2147483648 */
/* @0x27cf68 cmp r3, #8192 */
/* @0x27cf6c bhs 0x27cf40 <_ZN13MemoryManager7ReAllocEPvjPKcib+0x64> */
/* @0x27cf70 sub r1, r5, #16 */
/* @0x27cf74 movw r2, #0xc0de */
/* @0x27cf78 rsb r3, r3, r1 */
/* @0x27cf7c movt r2, #0xdead */
/* @0x27cf80 ldr r1, [r3, #0x4] */
/* @0x27cf84 cmp r1, r2 */
/* @0x27cf88 bne 0x27cf40 <_ZN13MemoryManager7ReAllocEPvjPKcib+0x64> */
/* @0x27cf8c ldr r2, [r3, #0x8] */
/* @0x27cf90 movw r3, #0xb00b */
/* @0x27cf94 movt r3, #0xbaad */
/* @0x27cf98 cmp r2, r3 */
/* @0x27cf9c bne 0x27cf40 <_ZN13MemoryManager7ReAllocEPvjPKcib+0x64> */
/* @0x27cfa0 cmp r6, r7 */
/* @0x27cfa4 movhs r8, r5 */
/* @0x27cfa8 bhs 0x27cfc0 <_ZN13MemoryManager7ReAllocEPvjPKcib+0xe4> */
/* @0x27cfac cmp r7, #0 */
/* @0x27cfb0 bne 0x27cfd0 <_ZN13MemoryManager7ReAllocEPvjPKcib+0xf4> */
/* @0x27cfb4 mov r0, r5 */
/* @0x27cfb8 mov r8, r7 */
/* @0x27cfbc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x27cfc0 ldr r0, [r4] */
/* @0x27cfc4 bl 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0x27cfc8 mov r0, r8 */
/* @0x27cfcc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x27cfd0 mov r3, #1 */
/* @0x27cfd4 mov r1, r9 */
/* @0x27cfd8 mov r2, r8 */
/* @0x27cfdc mov r0, r7 */
/* @0x27cfe0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x27cfe4 rsb r2, r6, r7 */
/* @0x27cfe8 mov r1, #0 */
/* @0x27cfec mov r9, r0 */
/* @0x27cff0 add r0, r0, r6 */
/* @0x27cff4 bl 0xb65b0 <memset@plt> */
/* @0x27cff8 mov r0, r9 */
/* @0x27cffc mov r1, r5 */
/* @0x27d000 cmp r6, r7 */
/* @0x27d004 movlo r2, r6 */
/* @0x27d008 movhs r2, r7 */
/* @0x27d00c bl 0xb65bc <memcpy@plt> */
/* @0x27d010 mov r0, r5 */
/* @0x27d014 mov r8, r9 */
/* @0x27d018 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x27d01c b 0x27cfc0 <_ZN13MemoryManager7ReAllocEPvjPKcib+0xe4> */
/* @0x27d020 ldr r2, [r5, #-0x8] */
/* @0x27d024 movw r3, #0xb00b */
/* @0x27d028 movt r3, #0xbaad */
/* @0x27d02c cmp r2, r3 */
/* @0x27d030 bne 0x27cf34 <_ZN13MemoryManager7ReAllocEPvjPKcib+0x58> */
/* @0x27d034 b 0x27cfa0 <_ZN13MemoryManager7ReAllocEPvjPKcib+0xc4> */
/* @0x27d038 mov r0, r1 */
/* @0x27d03c mov r1, r2 */
/* @0x27d040 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x27d044 mov r2, r3 */
/* @0x27d048 mov r3, #1 */
/* @0x27d04c b 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x27d050 bl 0x27b918 <_ZN7CBucketILj8ELj131072ELb1EE4FreeEPKv+0x38> */
/* @0x27d054 ldr r0, [r4] */
/* @0x27d058 b 0x27cf08 <_ZN13MemoryManager7ReAllocEPvjPKcib+0x2c> */
/* @0x27d05c andseq r4, r7, r4, lsr #18 */
/* @0x27d060 andseq r0, r7, r12, asr #15 */
/* @0x27d064 strdeq r10, r11, [sp], -r0 */

/* ── FUNC 0x27d068 · MemoryManager::SetLength(void**, unsigned int, char const*, int) · size=40 · insn=10 */
/* @0x27d068 push {r4, lr} */
/* @0x27d06c sub sp, sp, #8 */
/* @0x27d070 mov r4, r0 */
/* @0x27d074 mov r12, #0 */
/* @0x27d078 ldr r0, [r0] */
/* @0x27d07c str r12, [sp] */
/* @0x27d080 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x27d084 str r0, [r4] */
/* @0x27d088 add sp, sp, #8 */
/* @0x27d08c pop {r4, pc} */

/* ── FUNC 0x27d090 · MemoryManager::AllocAligned(unsigned int, int, char const*, int, bool) · size=188 · insn=47 */
/* @0x27d090 push {r4, r5, r6, r7, r8, lr} */
/* @0x27d094 subs r8, r0, #0 */
/* @0x27d098 mov r6, r1 */
/* @0x27d09c ldrb r4, [sp, #0x18] */
/* @0x27d0a0 beq 0x27d134 <_ZN13MemoryManager12AllocAlignedEjiPKcib+0xa4> */
/* @0x27d0a4 sub r0, r1, #1 */
/* @0x27d0a8 mov r1, r2 */
/* @0x27d0ac add r0, r0, r8 */
/* @0x27d0b0 mov r2, r3 */
/* @0x27d0b4 mov r3, #0 */
/* @0x27d0b8 bl 0x27cd54 <_ZN13MemoryManager6_AllocEjPKcib> */
/* @0x27d0bc cmp r4, #0 */
/* @0x27d0c0 mov r7, r0 */
/* @0x27d0c4 bne 0x27d124 <_ZN13MemoryManager12AllocAlignedEjiPKcib+0x94> */
/* @0x27d0c8 ldr r5, [pc, #0x78] */
/* @0x27d0cc ldr r5, [pc, r5] */
/* @0x27d0d0 ldr r0, [r5] */
/* @0x27d0d4 cmp r0, #0 */
/* @0x27d0d8 beq 0x27d13c <_ZN13MemoryManager12AllocAlignedEjiPKcib+0xac> */
/* @0x27d0dc add r4, r7, r6 */
/* @0x27d0e0 rsb r6, r6, #0 */
/* @0x27d0e4 sub r4, r4, #1 */
/* @0x27d0e8 bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0x27d0ec and r4, r4, r6 */
/* @0x27d0f0 mov r0, #0 */
/* @0x27d0f4 cmp r4, r7 */
/* @0x27d0f8 mov r1, r0 */
/* @0x27d0fc rsbne r7, r7, r4 */
/* @0x27d100 mov r3, r8 */
/* @0x27d104 addne r7, r7, #-2147483648 */
/* @0x27d108 mov r2, r4 */
/* @0x27d10c strne r7, [r4, #-0x4] */
/* @0x27d110 bl 0x27bcf4 <_Z11logLocation8ELogTypePKvS1_j> */
/* @0x27d114 ldr r0, [r5] */
/* @0x27d118 bl 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0x27d11c mov r0, r4 */
/* @0x27d120 pop {r4, r5, r6, r7, r8, pc} */
/* @0x27d124 mov r1, #0 */
/* @0x27d128 mov r2, r8 */
/* @0x27d12c bl 0xb65b0 <memset@plt> */
/* @0x27d130 b 0x27d0c8 <_ZN13MemoryManager12AllocAlignedEjiPKcib+0x38> */
/* @0x27d134 mov r0, r8 */
/* @0x27d138 pop {r4, r5, r6, r7, r8, pc} */
/* @0x27d13c bl 0x27b918 <_ZN7CBucketILj8ELj131072ELb1EE4FreeEPKv+0x38> */
/* @0x27d140 ldr r0, [r5] */
/* @0x27d144 b 0x27d0dc <_ZN13MemoryManager12AllocAlignedEjiPKcib+0x4c> */
/* @0x27d148 andseq r4, r7, r0, asr r7 */

/* ── FUNC 0x27d14c · operator new[](unsigned int) · size=24 · insn=6 */
/* @0x27d14c ldr r1, [pc, #0xc] */
/* @0x27d150 movw r2, #0x52b */
/* @0x27d154 mov r3, #1 */
/* @0x27d158 add r1, pc, r1 */
/* @0x27d15c b 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x27d160 andeq r10, sp, r8, lsl #1 */

/* ── FUNC 0x27d164 · operator new[](unsigned int, char const*, int) · size=24 · insn=6 */
/* @0x27d164 ldr r1, [pc, #0xc] */
/* @0x27d168 movw r2, #0x531 */
/* @0x27d16c mov r3, #1 */
/* @0x27d170 add r1, pc, r1 */
/* @0x27d174 b 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x27d178 andeq r10, sp, r0, ror r0 */

/* ── FUNC 0x27d17c · operator new(unsigned int, char const*, int) · size=24 · insn=6 */
/* @0x27d17c ldr r1, [pc, #0xc] */
/* @0x27d180 movw r2, #0x537 */
/* @0x27d184 mov r3, #1 */
/* @0x27d188 add r1, pc, r1 */
/* @0x27d18c b 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x27d190 andeq r10, sp, r8, asr r0 */

/* ── FUNC 0x27d194 · operator new(unsigned int, std::nothrow_t const&) · size=24 · insn=6 */
/* @0x27d194 ldr r1, [pc, #0xc] */
/* @0x27d198 movw r2, #0x53e */
/* @0x27d19c mov r3, #1 */
/* @0x27d1a0 add r1, pc, r1 */
/* @0x27d1a4 b 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x27d1a8 andeq r10, sp, r0, asr #32 */

/* ── FUNC 0x27d1ac · operator new[](unsigned int, std::nothrow_t const&) · size=24 · insn=6 */
/* @0x27d1ac ldr r1, [pc, #0xc] */
/* @0x27d1b0 movw r2, #0x544 */
/* @0x27d1b4 mov r3, #1 */
/* @0x27d1b8 add r1, pc, r1 */
/* @0x27d1bc b 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x27d1c0 andeq r10, sp, r8, lsr #32 */

/* ── FUNC 0x27d1c4 · operator delete(void*, std::nothrow_t const&) · size=4 · insn=1 */
/* @0x27d1c4 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */

/* ── FUNC 0x27d1c8 · operator delete[](void*, std::nothrow_t const&) · size=4 · insn=1 */
/* @0x27d1c8 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */

/* ── FUNC 0x27d1cc · operator delete(void*, unsigned int) · size=4 · insn=1 */
/* @0x27d1cc b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */

/* ── FUNC 0x27d1d0 · operator delete(void*) · size=4 · insn=1 */
/* @0x27d1d0 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */

/* ── FUNC 0x27d1d4 · operator delete[](void*) · size=4 · insn=1 */
/* @0x27d1d4 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */

/* ── FUNC 0x27d1d8 · operator delete[](void*, char const*, int) · size=4 · insn=1 */
/* @0x27d1d8 b 0xb655c <free@plt> */

/* ── FUNC 0x27d1dc · operator delete(void*, char const*, int) · size=4 · insn=1 */
/* @0x27d1dc b 0xb655c <free@plt> */
