/* libyoyo.so 覆盖卡组 0134
 * 函数 0x19e908..0x1a1a18，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x19e908 · Object_Init() · size=112 · insn=28 */
/* @0x19e908 push {r3, r4, r5, lr} */
/* @0x19e90c mov r0, #12 */
/* @0x19e910 ldr r3, [pc, #0x54] */
/* @0x19e914 mov r5, #0 */
/* @0x19e918 ldr r3, [pc, r3] */
/* @0x19e91c str r5, [r3] */
/* @0x19e920 bl 0x27c524 <_Znwj> */
/* @0x19e924 ldr r1, [pc, #0x44] */
/* @0x19e928 movw r3, #0x1ff */
/* @0x19e92c mov r2, #187 */
/* @0x19e930 add r1, pc, r1 */
/* @0x19e934 mov r4, r0 */
/* @0x19e938 mov r0, #4096 */
/* @0x19e93c str r3, [r4, #0x4] */
/* @0x19e940 mov r3, #1 */
/* @0x19e944 str r5, [r4, #0x8] */
/* @0x19e948 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19e94c mov r1, r5 */
/* @0x19e950 mov r2, #4096 */
/* @0x19e954 str r0, [r4] */
/* @0x19e958 bl 0xb65b0 <memset@plt> */
/* @0x19e95c ldr r3, [pc, #0x10] */
/* @0x19e960 ldr r3, [pc, r3] */
/* @0x19e964 str r4, [r3] */
/* @0x19e968 pop {r3, r4, r5, pc} */
/* @0x19e96c eoreq r1, r5, r12, asr #27 */
/* @0x19e970 andseq lr, r10, r12, ror r3 */
/* @0x19e974 .word 0x0024f2dc */

/* ── FUNC 0x19e978 · PatchParents() · size=260 · insn=65 */
/* @0x19e978 ldr r3, [pc, #0xf8] */
/* @0x19e97c mov r12, #0 */
/* @0x19e980 push {r4, r5, r6} */
/* @0x19e984 ldr r3, [pc, r3] */
/* @0x19e988 ldr r5, [r3] */
/* @0x19e98c ldr r1, [r5] */
/* @0x19e990 b 0x19e9a4 <_Z12PatchParentsv+0x2c> */
/* @0x19e994 ldr r3, [r5, #0x4] */
/* @0x19e998 add r12, r12, #1 */
/* @0x19e99c cmp r12, r3 */
/* @0x19e9a0 bgt 0x19ea30 <_Z12PatchParentsv+0xb8> */
/* @0x19e9a4 ldr r2, [r1, r12, lsl #3] */
/* @0x19e9a8 cmp r2, #0 */
/* @0x19e9ac beq 0x19e994 <_Z12PatchParentsv+0x1c> */
/* @0x19e9b0 ldr r4, [r2, #0xc] */
/* @0x19e9b4 cmp r4, #0 */
/* @0x19e9b8 beq 0x19ea30 <_Z12PatchParentsv+0xb8> */
/* @0x19e9bc movw r6, #0x869f */
/* @0x19e9c0 movt r6, #0x1 */
/* @0x19e9c4 ldr r0, [r4, #0xc] */
/* @0x19e9c8 cmp r0, r6 */
/* @0x19e9cc bhi 0x19ea10 <_Z12PatchParentsv+0x98> */
/* @0x19e9d0 ldr r1, [r5, #0x4] */
/* @0x19e9d4 ldr r3, [r5] */
/* @0x19e9d8 and r1, r0, r1 */
/* @0x19e9dc ldr r3, [r3, r1, lsl #3] */
/* @0x19e9e0 cmp r3, #0 */
/* @0x19e9e4 bne 0x19e9f8 <_Z12PatchParentsv+0x80> */
/* @0x19e9e8 b 0x19ea10 <_Z12PatchParentsv+0x98> */
/* @0x19e9ec ldr r3, [r3, #0x4] */
/* @0x19e9f0 cmp r3, #0 */
/* @0x19e9f4 beq 0x19ea10 <_Z12PatchParentsv+0x98> */
/* @0x19e9f8 ldr r1, [r3, #0x8] */
/* @0x19e9fc cmp r0, r1 */
/* @0x19ea00 bne 0x19e9ec <_Z12PatchParentsv+0x74> */
/* @0x19ea04 ldr r3, [r3, #0xc] */
/* @0x19ea08 cmp r3, #0 */
/* @0x19ea0c strne r3, [r4, #0x48] */
/* @0x19ea10 cmp r2, #0 */
/* @0x19ea14 beq 0x19ea30 <_Z12PatchParentsv+0xb8> */
/* @0x19ea18 ldr r2, [r2, #0x4] */
/* @0x19ea1c cmp r2, #0 */
/* @0x19ea20 beq 0x19ea38 <_Z12PatchParentsv+0xc0> */
/* @0x19ea24 ldr r4, [r2, #0xc] */
/* @0x19ea28 cmp r4, #0 */
/* @0x19ea2c bne 0x19e9c4 <_Z12PatchParentsv+0x4c> */
/* @0x19ea30 pop {r4, r5, r6} */
/* @0x19ea34 bx lr */
/* @0x19ea38 ldr r0, [r5, #0x4] */
/* @0x19ea3c add r3, r12, #1 */
/* @0x19ea40 cmp r3, r0 */
/* @0x19ea44 bgt 0x19ea30 <_Z12PatchParentsv+0xb8> */
/* @0x19ea48 ldr r1, [r5] */
/* @0x19ea4c add r1, r1, r12, lsl #3 */
/* @0x19ea50 ldr r2, [r1, #0x8] */
/* @0x19ea54 mov r12, r3 */
/* @0x19ea58 add r1, r1, #8 */
/* @0x19ea5c add r3, r3, #1 */
/* @0x19ea60 cmp r2, #0 */
/* @0x19ea64 bne 0x19ea24 <_Z12PatchParentsv+0xac> */
/* @0x19ea68 cmp r3, r0 */
/* @0x19ea6c ble 0x19ea50 <_Z12PatchParentsv+0xd8> */
/* @0x19ea70 pop {r4, r5, r6} */
/* @0x19ea74 bx lr */
/* @0x19ea78 .word 0x0024f2b8 */

/* ── FUNC 0x19ea7c · Object_Load(unsigned char*, unsigned int, unsigned char*) · size=312 · insn=78 */
/* @0x19ea7c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x19ea80 sub sp, sp, #12 */
/* @0x19ea84 ldr r3, [r0] */
/* @0x19ea88 ldr r8, [pc, #0x114] */
/* @0x19ea8c cmp r3, #0 */
/* @0x19ea90 str r2, [sp] */
/* @0x19ea94 ldr r8, [pc, r8] */
/* @0x19ea98 str r3, [r8] */
/* @0x19ea9c ble 0x19eb94 <_Z11Object_LoadPhjS_+0x118> */
/* @0x19eaa0 ldr r3, [pc, #0x100] */
/* @0x19eaa4 mov r4, #0 */
/* @0x19eaa8 mov r7, r0 */
/* @0x19eaac add r3, pc, r3 */
/* @0x19eab0 str r3, [sp, #0x4] */
/* @0x19eab4 ldr r5, [r7, #0x4]! */
/* @0x19eab8 mov r0, #220 */
/* @0x19eabc ldr r10, [pc, #0xe8] */
/* @0x19eac0 cmp r5, #0 */
/* @0x19eac4 beq 0x19eb84 <_Z11Object_LoadPhjS_+0x108> */
/* @0x19eac8 ldr r10, [pc, r10] */
/* @0x19eacc ldr r11, [r10] */
/* @0x19ead0 adds r9, r11, r5 */
/* @0x19ead4 beq 0x19eb84 <_Z11Object_LoadPhjS_+0x108> */
/* @0x19ead8 bl 0x27c524 <_Znwj> */
/* @0x19eadc mov r1, r4 */
/* @0x19eae0 mov r6, r0 */
/* @0x19eae4 bl 0x19d4f4 <_ZN9CObjectGMC2Ei> */
/* @0x19eae8 mov r1, r9 */
/* @0x19eaec ldr r2, [sp] */
/* @0x19eaf0 mov r0, r6 */
/* @0x19eaf4 bl 0x19d688 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh> */
/* @0x19eaf8 ldr r2, [r11, r5] */
/* @0x19eafc mov r0, r6 */
/* @0x19eb00 cmp r2, #0 */
/* @0x19eb04 mov r1, r2 */
/* @0x19eb08 ldrne r1, [r10] */
/* @0x19eb0c addne r1, r1, r2 */
/* @0x19eb10 bl 0x19d2d4 <_ZN9CObjectGM7SetNameEPc> */
/* @0x19eb14 ldr r12, [pc, #0x94] */
/* @0x19eb18 movw r2, #0x132 */
/* @0x19eb1c mov r3, #1 */
/* @0x19eb20 ldr r12, [pc, r12] */
/* @0x19eb24 mov r0, #16 */
/* @0x19eb28 ldr r1, [sp, #0x4] */
/* @0x19eb2c ldr r5, [r12] */
/* @0x19eb30 ldm r5, {r9, r12} */
/* @0x19eb34 and r10, r4, r12 */
/* @0x19eb38 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19eb3c ldr r2, [r9, r10, lsl #3] */
/* @0x19eb40 add r3, r9, r10, lsl #3 */
/* @0x19eb44 cmp r2, #0 */
/* @0x19eb48 ldrne r2, [r3, #0x4] */
/* @0x19eb4c str r4, [r0, #0x8] */
/* @0x19eb50 str r6, [r0, #0xc] */
/* @0x19eb54 strne r2, [r0] */
/* @0x19eb58 streq r0, [r3, #0x4] */
/* @0x19eb5c strne r0, [r2, #0x4] */
/* @0x19eb60 strne r0, [r3, #0x4] */
/* @0x19eb64 movne r3, #0 */
/* @0x19eb68 strne r3, [r0, #0x4] */
/* @0x19eb6c ldr r3, [r5, #0x8] */
/* @0x19eb70 streq r0, [r9, r10, lsl #3] */
/* @0x19eb74 add r3, r3, #1 */
/* @0x19eb78 streq r2, [r0, #0x4] */
/* @0x19eb7c streq r2, [r0] */
/* @0x19eb80 str r3, [r5, #0x8] */
/* @0x19eb84 ldr r3, [r8] */
/* @0x19eb88 add r4, r4, #1 */
/* @0x19eb8c cmp r3, r4 */
/* @0x19eb90 bgt 0x19eab4 <_Z11Object_LoadPhjS_+0x38> */
/* @0x19eb94 bl 0x19e978 <_Z12PatchParentsv> */
/* @0x19eb98 mov r0, #1 */
/* @0x19eb9c add sp, sp, #12 */
/* @0x19eba0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19eba4 eoreq r1, r5, r0, asr r12 */
/* @0x19eba8 andseq lr, r10, r0, lsl #4 */
/* @0x19ebac eoreq lr, r4, r12, ror lr */
/* @0x19ebb0 eoreq pc, r4, r12, lsl r1 */

/* ── FUNC 0x19ebb4 · Object_Prepare() · size=324 · insn=81 */
/* @0x19ebb4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x19ebb8 mov r5, #0 */
/* @0x19ebbc ldr r8, [pc, #0x118] */
/* @0x19ebc0 ldr r2, [pc, #0x118] */
/* @0x19ebc4 add r8, pc, r8 */
/* @0x19ebc8 ldr r3, [pc, #0x114] */
/* @0x19ebcc ldr r1, [pc, #0x114] */
/* @0x19ebd0 ldr r2, [r8, r2] */
/* @0x19ebd4 ldr r3, [r8, r3] */
/* @0x19ebd8 add r1, pc, r1 */
/* @0x19ebdc ldr r7, [r2] */
/* @0x19ebe0 ldr r2, [r3] */
/* @0x19ebe4 ldr r3, [r7] */
/* @0x19ebe8 mov r0, r7 */
/* @0x19ebec ldr r3, [r3, #0xc] */
/* @0x19ebf0 blx r3 */
/* @0x19ebf4 ldr r3, [pc, #0xf0] */
/* @0x19ebf8 ldr r3, [r8, r3] */
/* @0x19ebfc ldr r10, [r3] */
/* @0x19ec00 ldr r2, [r10] */
/* @0x19ec04 b 0x19ec18 <_Z14Object_Preparev+0x64> */
/* @0x19ec08 ldr r3, [r10, #0x4] */
/* @0x19ec0c add r5, r5, #1 */
/* @0x19ec10 cmp r5, r3 */
/* @0x19ec14 bgt 0x19ecd0 <_Z14Object_Preparev+0x11c> */
/* @0x19ec18 ldr r4, [r2, r5, lsl #3] */
/* @0x19ec1c cmp r4, #0 */
/* @0x19ec20 beq 0x19ec08 <_Z14Object_Preparev+0x54> */
/* @0x19ec24 ldr r6, [r4, #0xc] */
/* @0x19ec28 cmp r6, #0 */
/* @0x19ec2c beq 0x19ecd0 <_Z14Object_Preparev+0x11c> */
/* @0x19ec30 ldr r3, [pc, #0xb8] */
/* @0x19ec34 ldr r9, [pc, #0xb8] */
/* @0x19ec38 ldr r8, [r8, r3] */
/* @0x19ec3c add r9, pc, r9 */
/* @0x19ec40 b 0x19ec50 <_Z14Object_Preparev+0x9c> */
/* @0x19ec44 ldr r6, [r4, #0xc] */
/* @0x19ec48 cmp r6, #0 */
/* @0x19ec4c beq 0x19ecd0 <_Z14Object_Preparev+0x11c> */
/* @0x19ec50 ldr r12, [r7] */
/* @0x19ec54 mov r0, r7 */
/* @0x19ec58 mov r1, r9 */
/* @0x19ec5c ldr r2, [r6, #0x18] */
/* @0x19ec60 ldr r3, [r6, #0x14] */
/* @0x19ec64 ldr r12, [r12, #0xc] */
/* @0x19ec68 blx r12 */
/* @0x19ec6c ldr r3, [r6, #0x18] */
/* @0x19ec70 mov r0, r6 */
/* @0x19ec74 str r3, [r8] */
/* @0x19ec78 bl 0x19d9f4 <_ZN9CObjectGM7CompileEv> */
/* @0x19ec7c cmp r0, #0 */
/* @0x19ec80 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x19ec84 cmp r4, #0 */
/* @0x19ec88 beq 0x19ecd0 <_Z14Object_Preparev+0x11c> */
/* @0x19ec8c ldr r4, [r4, #0x4] */
/* @0x19ec90 cmp r4, #0 */
/* @0x19ec94 bne 0x19ec44 <_Z14Object_Preparev+0x90> */
/* @0x19ec98 ldr r1, [r10, #0x4] */
/* @0x19ec9c add r3, r5, #1 */
/* @0x19eca0 cmp r3, r1 */
/* @0x19eca4 bgt 0x19ecd0 <_Z14Object_Preparev+0x11c> */
/* @0x19eca8 ldr r2, [r10] */
/* @0x19ecac add r2, r2, r5, lsl #3 */
/* @0x19ecb0 ldr r4, [r2, #0x8] */
/* @0x19ecb4 mov r5, r3 */
/* @0x19ecb8 add r2, r2, #8 */
/* @0x19ecbc add r3, r3, #1 */
/* @0x19ecc0 cmp r4, #0 */
/* @0x19ecc4 bne 0x19ec44 <_Z14Object_Preparev+0x90> */
/* @0x19ecc8 cmp r3, r1 */
/* @0x19eccc ble 0x19ecb0 <_Z14Object_Preparev+0xfc> */
/* @0x19ecd0 bl 0x19e978 <_Z12PatchParentsv> */
/* @0x19ecd4 mov r0, #1 */
/* @0x19ecd8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x19ecdc eoreq r3, r5, r12, lsl #1 */
/* @0x19ece0 .word 0xffffdecc */
/* @0x19ece4 .word 0xffffea94 */
/* @0x19ece8 andseq lr, r10, r0, asr #5 */
/* @0x19ecec .word 0xffffbfec */
/* @0x19ecf0 .word 0xffffc168 */
/* @0x19ecf4 andseq lr, r10, r4, ror r2 */

/* ── FUNC 0x19ecf8 · Object_Exists(int) · size=92 · insn=23 */
/* @0x19ecf8 ldr r3, [pc, #0x50] */
/* @0x19ecfc ldr r3, [pc, r3] */
/* @0x19ed00 ldr r3, [r3] */
/* @0x19ed04 ldr r2, [r3, #0x4] */
/* @0x19ed08 ldr r3, [r3] */
/* @0x19ed0c and r2, r0, r2 */
/* @0x19ed10 ldr r3, [r3, r2, lsl #3] */
/* @0x19ed14 cmp r3, #0 */
/* @0x19ed18 bne 0x19ed2c <_Z13Object_Existsi+0x34> */
/* @0x19ed1c b 0x19ed48 <_Z13Object_Existsi+0x50> */
/* @0x19ed20 ldr r3, [r3, #0x4] */
/* @0x19ed24 cmp r3, #0 */
/* @0x19ed28 beq 0x19ed48 <_Z13Object_Existsi+0x50> */
/* @0x19ed2c ldr r2, [r3, #0x8] */
/* @0x19ed30 cmp r0, r2 */
/* @0x19ed34 bne 0x19ed20 <_Z13Object_Existsi+0x28> */
/* @0x19ed38 ldr r0, [r3, #0xc] */
/* @0x19ed3c adds r0, r0, #0 */
/* @0x19ed40 movne r0, #1 */
/* @0x19ed44 bx lr */
/* @0x19ed48 mov r0, r3 */
/* @0x19ed4c bx lr */
/* @0x19ed50 eoreq lr, r4, r0, asr #30 */

/* ── FUNC 0x19ed54 · Object_Name(int) · size=160 · insn=40 */
/* @0x19ed54 ldr r3, [pc, #0x84] */
/* @0x19ed58 ldr r3, [pc, r3] */
/* @0x19ed5c ldr r3, [r3] */
/* @0x19ed60 cmp r3, #0 */
/* @0x19ed64 beq 0x19edbc <_Z11Object_Namei+0x68> */
/* @0x19ed68 ldr r2, [r3, #0x4] */
/* @0x19ed6c ldr r3, [r3] */
/* @0x19ed70 and r2, r0, r2 */
/* @0x19ed74 ldr r3, [r3, r2, lsl #3] */
/* @0x19ed78 cmp r3, #0 */
/* @0x19ed7c bne 0x19ed90 <_Z11Object_Namei+0x3c> */
/* @0x19ed80 b 0x19edc8 <_Z11Object_Namei+0x74> */
/* @0x19ed84 ldr r3, [r3, #0x4] */
/* @0x19ed88 cmp r3, #0 */
/* @0x19ed8c beq 0x19edb0 <_Z11Object_Namei+0x5c> */
/* @0x19ed90 ldr r2, [r3, #0x8] */
/* @0x19ed94 cmp r0, r2 */
/* @0x19ed98 bne 0x19ed84 <_Z11Object_Namei+0x30> */
/* @0x19ed9c ldr r3, [r3, #0xc] */
/* @0x19eda0 cmp r3, #0 */
/* @0x19eda4 beq 0x19edd4 <_Z11Object_Namei+0x80> */
/* @0x19eda8 ldr r0, [r3, #0x14] */
/* @0x19edac bx lr */
/* @0x19edb0 ldr r0, [pc, #0x2c] */
/* @0x19edb4 add r0, pc, r0 */
/* @0x19edb8 bx lr */
/* @0x19edbc ldr r0, [pc, #0x24] */
/* @0x19edc0 add r0, pc, r0 */
/* @0x19edc4 bx lr */
/* @0x19edc8 ldr r0, [pc, #0x1c] */
/* @0x19edcc add r0, pc, r0 */
/* @0x19edd0 bx lr */
/* @0x19edd4 ldr r0, [pc, #0x14] */
/* @0x19edd8 add r0, pc, r0 */
/* @0x19eddc bx lr */
/* @0x19ede0 eoreq lr, r4, r4, ror #29 */
/* @0x19ede4 andseq r1, r9, r12, lsl #26 */
/* @0x19ede8 andseq r1, r9, r0, lsl #26 */
/* @0x19edec ldrsheq r1, [r9], -r4 */
/* @0x19edf0 andseq r1, r9, r8, ror #25 */

/* ── FUNC 0x19edf4 · Object_Find(char const*) · size=200 · insn=50 */
/* @0x19edf4 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x19edf8 mov r8, r0 */
/* @0x19edfc ldr r3, [pc, #0xb4] */
/* @0x19ee00 mov r5, #0 */
/* @0x19ee04 ldr r3, [pc, r3] */
/* @0x19ee08 ldr r9, [r3] */
/* @0x19ee0c ldr r7, [r9] */
/* @0x19ee10 b 0x19ee24 <_Z11Object_FindPKc+0x30> */
/* @0x19ee14 ldr r3, [r9, #0x4] */
/* @0x19ee18 add r5, r5, #1 */
/* @0x19ee1c cmp r5, r3 */
/* @0x19ee20 bgt 0x19eea8 <_Z11Object_FindPKc+0xb4> */
/* @0x19ee24 ldr r4, [r7, r5, lsl #3] */
/* @0x19ee28 cmp r4, #0 */
/* @0x19ee2c beq 0x19ee14 <_Z11Object_FindPKc+0x20> */
/* @0x19ee30 ldr r6, [r4, #0xc] */
/* @0x19ee34 cmp r6, #0 */
/* @0x19ee38 beq 0x19eea8 <_Z11Object_FindPKc+0xb4> */
/* @0x19ee3c ldr r0, [r6, #0x14] */
/* @0x19ee40 cmp r0, #0 */
/* @0x19ee44 beq 0x19ee58 <_Z11Object_FindPKc+0x64> */
/* @0x19ee48 mov r1, r8 */
/* @0x19ee4c bl 0xb6574 <strcmp@plt> */
/* @0x19ee50 cmp r0, #0 */
/* @0x19ee54 beq 0x19eeb0 <_Z11Object_FindPKc+0xbc> */
/* @0x19ee58 cmp r4, #0 */
/* @0x19ee5c beq 0x19eea8 <_Z11Object_FindPKc+0xb4> */
/* @0x19ee60 ldr r4, [r4, #0x4] */
/* @0x19ee64 cmp r4, #0 */
/* @0x19ee68 bne 0x19ee30 <_Z11Object_FindPKc+0x3c> */
/* @0x19ee6c ldr r1, [r9, #0x4] */
/* @0x19ee70 add r3, r5, #1 */
/* @0x19ee74 cmp r3, r1 */
/* @0x19ee78 bgt 0x19eea8 <_Z11Object_FindPKc+0xb4> */
/* @0x19ee7c add r2, r7, r5, lsl #3 */
/* @0x19ee80 b 0x19ee8c <_Z11Object_FindPKc+0x98> */
/* @0x19ee84 cmp r1, r3 */
/* @0x19ee88 blt 0x19eea8 <_Z11Object_FindPKc+0xb4> */
/* @0x19ee8c ldr r4, [r2, #0x8] */
/* @0x19ee90 mov r5, r3 */
/* @0x19ee94 add r2, r2, #8 */
/* @0x19ee98 add r3, r3, #1 */
/* @0x19ee9c cmp r4, #0 */
/* @0x19eea0 beq 0x19ee84 <_Z11Object_FindPKc+0x90> */
/* @0x19eea4 b 0x19ee30 <_Z11Object_FindPKc+0x3c> */
/* @0x19eea8 mvn r0, #0 */
/* @0x19eeac pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x19eeb0 ldr r0, [r6, #0x18] */
/* @0x19eeb4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x19eeb8 eoreq lr, r4, r8, lsr lr */

/* ── FUNC 0x19eebc · Object_Add() · size=344 · insn=86 */
/* @0x19eebc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x19eec0 sub sp, sp, #264 */
/* @0x19eec4 ldr r6, [pc, #0x130] */
/* @0x19eec8 add r7, sp, #4 */
/* @0x19eecc ldr r4, [pc, #0x12c] */
/* @0x19eed0 mov r2, #10 */
/* @0x19eed4 ldr r6, [pc, r6] */
/* @0x19eed8 mov r1, r7 */
/* @0x19eedc ldr r4, [pc, r4] */
/* @0x19eee0 ldr r3, [r6] */
/* @0x19eee4 ldr r0, [r4] */
/* @0x19eee8 str r3, [sp, #0x104] */
/* @0x19eeec bl 0xc4964 <_Z5_itoaiPci> */
/* @0x19eef0 mov r0, #220 */
/* @0x19eef4 bl 0x27c524 <_Znwj> */
/* @0x19eef8 ldr r1, [r4] */
/* @0x19eefc mov r8, r0 */
/* @0x19ef00 bl 0x19d4f4 <_ZN9CObjectGMC2Ei> */
/* @0x19ef04 mov r0, r7 */
/* @0x19ef08 bl 0xb6538 <strlen@plt> */
/* @0x19ef0c ldr r1, [pc, #0xf0] */
/* @0x19ef10 mov r2, #226 */
/* @0x19ef14 mov r3, #1 */
/* @0x19ef18 add r1, pc, r1 */
/* @0x19ef1c add r0, r0, #12 */
/* @0x19ef20 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19ef24 ldr r3, [pc, #0xdc] */
/* @0x19ef28 add r3, pc, r3 */
/* @0x19ef2c mov r5, r0 */
/* @0x19ef30 ldm r3!, {r0, r1, r2} */
/* @0x19ef34 str r2, [r5, #0x8] */
/* @0x19ef38 str r0, [r5] */
/* @0x19ef3c add r0, r5, #11 */
/* @0x19ef40 str r1, [r5, #0x4] */
/* @0x19ef44 mov r1, r7 */
/* @0x19ef48 bl 0xb65a4 <strcpy@plt> */
/* @0x19ef4c mov r1, r5 */
/* @0x19ef50 mov r0, r8 */
/* @0x19ef54 bl 0x19d348 <_ZN9CObjectGM10SetNameRefEPc> */
/* @0x19ef58 ldr r12, [pc, #0xac] */
/* @0x19ef5c ldr r1, [pc, #0xac] */
/* @0x19ef60 movw r2, #0x132 */
/* @0x19ef64 ldr r12, [pc, r12] */
/* @0x19ef68 mov r3, #1 */
/* @0x19ef6c add r1, pc, r1 */
/* @0x19ef70 mov r0, #16 */
/* @0x19ef74 ldr r5, [r12] */
/* @0x19ef78 ldr r10, [r4] */
/* @0x19ef7c ldm r5, {r7, r9} */
/* @0x19ef80 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19ef84 and r9, r10, r9 */
/* @0x19ef88 ldr r1, [r7, r9, lsl #3] */
/* @0x19ef8c add r2, r7, r9, lsl #3 */
/* @0x19ef90 cmp r1, #0 */
/* @0x19ef94 ldrne r1, [r2, #0x4] */
/* @0x19ef98 mov r3, r0 */
/* @0x19ef9c str r8, [r0, #0xc] */
/* @0x19efa0 str r10, [r0, #0x8] */
/* @0x19efa4 movne r0, #0 */
/* @0x19efa8 streq r0, [r2, #0x4] */
/* @0x19efac strne r1, [r3] */
/* @0x19efb0 strne r3, [r1, #0x4] */
/* @0x19efb4 strne r3, [r2, #0x4] */
/* @0x19efb8 strne r0, [r3, #0x4] */
/* @0x19efbc ldr r2, [sp, #0x104] */
/* @0x19efc0 ldr r3, [r6] */
/* @0x19efc4 streq r0, [r7, r9, lsl #3] */
/* @0x19efc8 streq r1, [r0] */
/* @0x19efcc streq r1, [r0, #0x4] */
/* @0x19efd0 cmp r2, r3 */
/* @0x19efd4 ldr r0, [r4] */
/* @0x19efd8 ldr r3, [r5, #0x8] */
/* @0x19efdc add r2, r0, #1 */
/* @0x19efe0 str r2, [r4] */
/* @0x19efe4 add r3, r3, #1 */
/* @0x19efe8 str r3, [r5, #0x8] */
/* @0x19efec bne 0x19eff8 <_Z10Object_Addv+0x13c> */
/* @0x19eff0 add sp, sp, #264 */
/* @0x19eff4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x19eff8 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x19effc eoreq lr, r4, r12, ror r10 */
/* @0x19f000 eoreq r1, r5, r8, lsl #16 */
/* @0x19f004 andseq sp, r10, r12, lsr #31 */
/* @0x19f008 ldrsbeq sp, [r10], -r4 */
/* @0x19f00c .word 0x0024ecd8 */
/* @0x19f010 andseq sp, r10, r0, asr #26 */

/* ── FUNC 0x19f014 · Object_Delete(int) · size=172 · insn=43 */
/* @0x19f014 ldr r3, [pc, #0xa0] */
/* @0x19f018 push {r4, r5, r6, lr} */
/* @0x19f01c ldr r3, [pc, r3] */
/* @0x19f020 ldr r5, [r3] */
/* @0x19f024 ldr r1, [r5, #0x4] */
/* @0x19f028 ldr r2, [r5] */
/* @0x19f02c and r1, r0, r1 */
/* @0x19f030 ldr r4, [r2, r1, lsl #3] */
/* @0x19f034 add r12, r2, r1, lsl #3 */
/* @0x19f038 cmp r4, #0 */
/* @0x19f03c bne 0x19f050 <_Z13Object_Deletei+0x3c> */
/* @0x19f040 b 0x19f0b4 <_Z13Object_Deletei+0xa0> */
/* @0x19f044 ldr r4, [r4, #0x4] */
/* @0x19f048 cmp r4, #0 */
/* @0x19f04c beq 0x19f0b4 <_Z13Object_Deletei+0xa0> */
/* @0x19f050 ldr r3, [r4, #0x8] */
/* @0x19f054 cmp r0, r3 */
/* @0x19f058 bne 0x19f044 <_Z13Object_Deletei+0x30> */
/* @0x19f05c ldr r3, [r4] */
/* @0x19f060 ldr r6, [r4, #0xc] */
/* @0x19f064 cmp r3, #0 */
/* @0x19f068 ldrne r2, [r4, #0x4] */
/* @0x19f06c ldreq r0, [r4, #0x4] */
/* @0x19f070 strne r2, [r3, #0x4] */
/* @0x19f074 ldrne r0, [r4, #0x4] */
/* @0x19f078 streq r0, [r2, r1, lsl #3] */
/* @0x19f07c cmp r0, #0 */
/* @0x19f080 streq r3, [r12, #0x4] */
/* @0x19f084 strne r3, [r0] */
/* @0x19f088 cmp r6, #0 */
/* @0x19f08c beq 0x19f0a0 <_Z13Object_Deletei+0x8c> */
/* @0x19f090 mov r0, r6 */
/* @0x19f094 bl 0x19d558 <_ZN9CObjectGMD2Ev> */
/* @0x19f098 mov r0, r6 */
/* @0x19f09c bl 0x27d1d0 <_ZdlPv> */
/* @0x19f0a0 mov r0, r4 */
/* @0x19f0a4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19f0a8 ldr r3, [r5, #0x8] */
/* @0x19f0ac sub r3, r3, #1 */
/* @0x19f0b0 str r3, [r5, #0x8] */
/* @0x19f0b4 mov r0, #1 */
/* @0x19f0b8 pop {r4, r5, r6, pc} */
/* @0x19f0bc eoreq lr, r4, r0, lsr #24 */

/* ── FUNC 0x19f0c0 · FINALIZE_Object_Main() · size=348 · insn=87 */
/* @0x19f0c0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x19f0c4 mov r11, #0 */
/* @0x19f0c8 ldr r8, [pc, #0x144] */
/* @0x19f0cc ldr r3, [pc, #0x144] */
/* @0x19f0d0 ldr r8, [pc, r8] */
/* @0x19f0d4 ldr r3, [pc, r3] */
/* @0x19f0d8 ldr r7, [r8] */
/* @0x19f0dc str r11, [r3] */
/* @0x19f0e0 cmp r7, r11 */
/* @0x19f0e4 beq 0x19f200 <_Z20FINALIZE_Object_Mainv+0x140> */
/* @0x19f0e8 ldr r10, [r7, #0x4] */
/* @0x19f0ec cmp r10, r11 */
/* @0x19f0f0 blt 0x19f20c <_Z20FINALIZE_Object_Mainv+0x14c> */
/* @0x19f0f4 lsl r9, r10, #3 */
/* @0x19f0f8 ldr r3, [r7] */
/* @0x19f0fc add r2, r3, r9 */
/* @0x19f100 ldr r4, [r3, r9] */
/* @0x19f104 str r11, [r3, r9] */
/* @0x19f108 cmp r4, #0 */
/* @0x19f10c str r11, [r2, #0x4] */
/* @0x19f110 beq 0x19f154 <_Z20FINALIZE_Object_Mainv+0x94> */
/* @0x19f114 ldr r5, [r4, #0xc] */
/* @0x19f118 ldr r6, [r4, #0x4] */
/* @0x19f11c cmp r5, #0 */
/* @0x19f120 mov r0, r5 */
/* @0x19f124 beq 0x19f134 <_Z20FINALIZE_Object_Mainv+0x74> */
/* @0x19f128 bl 0x19d558 <_ZN9CObjectGMD2Ev> */
/* @0x19f12c mov r0, r5 */
/* @0x19f130 bl 0x27d1d0 <_ZdlPv> */
/* @0x19f134 mov r0, r4 */
/* @0x19f138 mov r4, r6 */
/* @0x19f13c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19f140 ldr r3, [r7, #0x8] */
/* @0x19f144 cmp r6, #0 */
/* @0x19f148 sub r3, r3, #1 */
/* @0x19f14c str r3, [r7, #0x8] */
/* @0x19f150 bne 0x19f114 <_Z20FINALIZE_Object_Mainv+0x54> */
/* @0x19f154 sub r10, r10, #1 */
/* @0x19f158 sub r9, r9, #8 */
/* @0x19f15c cmn r10, #1 */
/* @0x19f160 bne 0x19f0f8 <_Z20FINALIZE_Object_Mainv+0x38> */
/* @0x19f164 ldr r7, [r8] */
/* @0x19f168 cmp r7, #0 */
/* @0x19f16c beq 0x19f200 <_Z20FINALIZE_Object_Mainv+0x140> */
/* @0x19f170 ldr r10, [r7, #0x4] */
/* @0x19f174 cmp r10, #0 */
/* @0x19f178 blt 0x19f20c <_Z20FINALIZE_Object_Mainv+0x14c> */
/* @0x19f17c ldr r0, [r7] */
/* @0x19f180 lsl r9, r10, #3 */
/* @0x19f184 mov r11, #0 */
/* @0x19f188 ldr r4, [r0, r9] */
/* @0x19f18c add r3, r0, r9 */
/* @0x19f190 str r11, [r0, r9] */
/* @0x19f194 cmp r4, #0 */
/* @0x19f198 str r11, [r3, #0x4] */
/* @0x19f19c beq 0x19f1e4 <_Z20FINALIZE_Object_Mainv+0x124> */
/* @0x19f1a0 ldr r5, [r4, #0xc] */
/* @0x19f1a4 ldr r6, [r4, #0x4] */
/* @0x19f1a8 cmp r5, #0 */
/* @0x19f1ac mov r0, r5 */
/* @0x19f1b0 beq 0x19f1c0 <_Z20FINALIZE_Object_Mainv+0x100> */
/* @0x19f1b4 bl 0x19d558 <_ZN9CObjectGMD2Ev> */
/* @0x19f1b8 mov r0, r5 */
/* @0x19f1bc bl 0x27d1d0 <_ZdlPv> */
/* @0x19f1c0 mov r0, r4 */
/* @0x19f1c4 mov r4, r6 */
/* @0x19f1c8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19f1cc ldr r3, [r7, #0x8] */
/* @0x19f1d0 cmp r6, #0 */
/* @0x19f1d4 sub r3, r3, #1 */
/* @0x19f1d8 str r3, [r7, #0x8] */
/* @0x19f1dc bne 0x19f1a0 <_Z20FINALIZE_Object_Mainv+0xe0> */
/* @0x19f1e0 ldr r0, [r7] */
/* @0x19f1e4 sub r10, r10, #1 */
/* @0x19f1e8 sub r9, r9, #8 */
/* @0x19f1ec cmn r10, #1 */
/* @0x19f1f0 bne 0x19f188 <_Z20FINALIZE_Object_Mainv+0xc8> */
/* @0x19f1f4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19f1f8 mov r0, r7 */
/* @0x19f1fc bl 0x27d1d0 <_ZdlPv> */
/* @0x19f200 mov r3, #0 */
/* @0x19f204 str r3, [r8] */
/* @0x19f208 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19f20c ldr r0, [r7] */
/* @0x19f210 b 0x19f1f4 <_Z20FINALIZE_Object_Mainv+0x134> */
/* @0x19f214 eoreq lr, r4, r12, ror #22 */
/* @0x19f218 eoreq r1, r5, r0, lsl r6 */

/* ── FUNC 0x19f21c · Object_ClearAllInstanceInfo() · size=180 · insn=45 */
/* @0x19f21c ldr r3, [pc, #0xa8] */
/* @0x19f220 push {r4, r5, r6, lr} */
/* @0x19f224 ldr r3, [pc, r3] */
/* @0x19f228 mov r5, #0 */
/* @0x19f22c ldr r6, [r3] */
/* @0x19f230 ldr r2, [r6] */
/* @0x19f234 b 0x19f248 <_Z27Object_ClearAllInstanceInfov+0x2c> */
/* @0x19f238 ldr r3, [r6, #0x4] */
/* @0x19f23c add r5, r5, #1 */
/* @0x19f240 cmp r5, r3 */
/* @0x19f244 bgt 0x19f2c8 <_Z27Object_ClearAllInstanceInfov+0xac> */
/* @0x19f248 ldr r4, [r2, r5, lsl #3] */
/* @0x19f24c cmp r4, #0 */
/* @0x19f250 beq 0x19f238 <_Z27Object_ClearAllInstanceInfov+0x1c> */
/* @0x19f254 ldr r0, [r4, #0xc] */
/* @0x19f258 cmp r0, #0 */
/* @0x19f25c bne 0x19f270 <_Z27Object_ClearAllInstanceInfov+0x54> */
/* @0x19f260 pop {r4, r5, r6, pc} */
/* @0x19f264 ldr r0, [r4, #0xc] */
/* @0x19f268 cmp r0, #0 */
/* @0x19f26c beq 0x19f2c4 <_Z27Object_ClearAllInstanceInfov+0xa8> */
/* @0x19f270 bl 0x19d36c <_ZN9CObjectGM17ClearInstanceInfoEv> */
/* @0x19f274 cmp r4, #0 */
/* @0x19f278 popeq {r4, r5, r6, pc} */
/* @0x19f27c ldr r4, [r4, #0x4] */
/* @0x19f280 cmp r4, #0 */
/* @0x19f284 bne 0x19f264 <_Z27Object_ClearAllInstanceInfov+0x48> */
/* @0x19f288 ldr r1, [r6, #0x4] */
/* @0x19f28c add r3, r5, #1 */
/* @0x19f290 cmp r3, r1 */
/* @0x19f294 popgt {r4, r5, r6, pc} */
/* @0x19f298 ldr r2, [r6] */
/* @0x19f29c add r2, r2, r5, lsl #3 */
/* @0x19f2a0 ldr r4, [r2, #0x8] */
/* @0x19f2a4 mov r5, r3 */
/* @0x19f2a8 add r2, r2, #8 */
/* @0x19f2ac add r3, r3, #1 */
/* @0x19f2b0 cmp r4, #0 */
/* @0x19f2b4 bne 0x19f264 <_Z27Object_ClearAllInstanceInfov+0x48> */
/* @0x19f2b8 cmp r1, r3 */
/* @0x19f2bc bge 0x19f2a0 <_Z27Object_ClearAllInstanceInfov+0x84> */
/* @0x19f2c0 pop {r4, r5, r6, pc} */
/* @0x19f2c4 pop {r4, r5, r6, pc} */
/* @0x19f2c8 pop {r4, r5, r6, pc} */
/* @0x19f2cc eoreq lr, r4, r8, lsl r10 */

/* ── FUNC 0x19f2d0 · Option_Init() · size=572 · insn=143 */
/* @0x19f2d0 ldr r3, [pc, #0x1ac] */
/* @0x19f2d4 mov r2, #0 */
/* @0x19f2d8 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x19f2dc add r3, pc, r3 */
/* @0x19f2e0 ldr r4, [pc, #0x1a0] */
/* @0x19f2e4 mov r1, #1 */
/* @0x19f2e8 ldr r12, [pc, #0x19c] */
/* @0x19f2ec mov r7, #100 */
/* @0x19f2f0 ldr r0, [pc, #0x198] */
/* @0x19f2f4 mvn r10, #-16777216 */
/* @0x19f2f8 ldr r4, [r3, r4] */
/* @0x19f2fc mov r11, #255 */
/* @0x19f300 ldr r8, [pc, #0x18c] */
/* @0x19f304 ldr r6, [pc, #0x18c] */
/* @0x19f308 strb r2, [r4] */
/* @0x19f30c ldr r12, [r3, r12] */
/* @0x19f310 ldr r5, [pc, #0x184] */
/* @0x19f314 ldr r4, [pc, #0x184] */
/* @0x19f318 strb r2, [r12] */
/* @0x19f31c ldr r9, [r3, r0] */
/* @0x19f320 ldr r12, [pc, #0x17c] */
/* @0x19f324 ldr r0, [pc, #0x17c] */
/* @0x19f328 strb r2, [r9] */
/* @0x19f32c ldr r8, [r3, r8] */
/* @0x19f330 ldr r9, [pc, #0x174] */
/* @0x19f334 strb r1, [r8] */
/* @0x19f338 ldr r6, [r3, r6] */
/* @0x19f33c ldr r8, [pc, #0x16c] */
/* @0x19f340 str r7, [r6] */
/* @0x19f344 ldr r5, [r3, r5] */
/* @0x19f348 ldr r7, [pc, #0x164] */
/* @0x19f34c ldr r6, [pc, #0x164] */
/* @0x19f350 strb r2, [r5] */
/* @0x19f354 ldr r4, [r3, r4] */
/* @0x19f358 ldr r5, [pc, #0x15c] */
/* @0x19f35c strb r2, [r4] */
/* @0x19f360 ldr r12, [r3, r12] */
/* @0x19f364 ldr r4, [pc, #0x154] */
/* @0x19f368 str r10, [r12] */
/* @0x19f36c ldr r10, [r3, r0] */
/* @0x19f370 ldr r12, [pc, #0x14c] */
/* @0x19f374 ldr r0, [pc, #0x14c] */
/* @0x19f378 strb r2, [r10] */
/* @0x19f37c ldr r10, [r3, r9] */
/* @0x19f380 ldr r9, [pc, #0x144] */
/* @0x19f384 str r2, [r10] */
/* @0x19f388 ldr r10, [r3, r8] */
/* @0x19f38c ldr r8, [pc, #0x13c] */
/* @0x19f390 str r2, [r10] */
/* @0x19f394 ldr r10, [r3, r7] */
/* @0x19f398 ldr r7, [pc, #0x134] */
/* @0x19f39c str r2, [r10] */
/* @0x19f3a0 ldr r10, [r3, r6] */
/* @0x19f3a4 ldr r6, [pc, #0x12c] */
/* @0x19f3a8 strb r2, [r10] */
/* @0x19f3ac ldr r10, [r3, r5] */
/* @0x19f3b0 ldr r5, [pc, #0x124] */
/* @0x19f3b4 strb r2, [r10] */
/* @0x19f3b8 ldr r10, [r3, r4] */
/* @0x19f3bc ldr r4, [pc, #0x11c] */
/* @0x19f3c0 str r2, [r10] */
/* @0x19f3c4 ldr r10, [r3, r12] */
/* @0x19f3c8 ldr r12, [pc, #0x114] */
/* @0x19f3cc strb r1, [r10] */
/* @0x19f3d0 ldr r10, [r3, r0] */
/* @0x19f3d4 ldr r0, [pc, #0x10c] */
/* @0x19f3d8 strb r1, [r10] */
/* @0x19f3dc ldr r10, [r3, r9] */
/* @0x19f3e0 ldr r9, [pc, #0x104] */
/* @0x19f3e4 strb r1, [r10] */
/* @0x19f3e8 ldr r10, [r3, r8] */
/* @0x19f3ec ldr r8, [pc, #0xfc] */
/* @0x19f3f0 strb r1, [r10] */
/* @0x19f3f4 ldr r10, [r3, r7] */
/* @0x19f3f8 ldr r7, [pc, #0xf4] */
/* @0x19f3fc strb r1, [r10] */
/* @0x19f400 ldr r10, [r3, r6] */
/* @0x19f404 ldr r6, [pc, #0xec] */
/* @0x19f408 strb r1, [r10] */
/* @0x19f40c ldr r10, [r3, r5] */
/* @0x19f410 ldr r5, [pc, #0xe4] */
/* @0x19f414 str r2, [r10] */
/* @0x19f418 ldr r10, [r3, r4] */
/* @0x19f41c ldr r4, [pc, #0xdc] */
/* @0x19f420 strb r1, [r10] */
/* @0x19f424 ldr r10, [r3, r12] */
/* @0x19f428 ldr r12, [pc, #0xd4] */
/* @0x19f42c strb r2, [r10] */
/* @0x19f430 ldr r10, [r3, r0] */
/* @0x19f434 ldr r0, [pc, #0xcc] */
/* @0x19f438 str r11, [r10] */
/* @0x19f43c ldr r9, [r3, r9] */
/* @0x19f440 strb r1, [r9] */
/* @0x19f444 ldr r8, [r3, r8] */
/* @0x19f448 strb r1, [r8] */
/* @0x19f44c ldr r1, [r3, r7] */
/* @0x19f450 strb r2, [r1] */
/* @0x19f454 ldr r1, [r3, r6] */
/* @0x19f458 strb r2, [r1] */
/* @0x19f45c ldr r1, [r3, r5] */
/* @0x19f460 strb r2, [r1] */
/* @0x19f464 ldr r1, [r3, r4] */
/* @0x19f468 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x19f46c str r2, [r1] */
/* @0x19f470 ldr r1, [r3, r12] */
/* @0x19f474 str r2, [r1] */
/* @0x19f478 ldr r3, [r3, r0] */
/* @0x19f47c str r2, [r3] */
/* @0x19f480 bx lr */
/* @0x19f484 eoreq r2, r5, r4, ror r9 */
/* @0x19f488 .word 0xffffea98 */
/* @0x19f48c .word 0xffffea9c */
/* @0x19f490 .word 0xffffeaa0 */
/* @0x19f494 .word 0xffffd79c */
/* @0x19f498 .word 0xffffeaa4 */
/* @0x19f49c .word 0xffffeaa8 */
/* @0x19f4a0 .word 0xffffeaac */
/* @0x19f4a4 .word 0xffffeab0 */
/* @0x19f4a8 .word 0xffffeab4 */
/* @0x19f4ac .word 0xffffeab8 */
/* @0x19f4b0 .word 0xffffeabc */
/* @0x19f4b4 .word 0xffffeac0 */
/* @0x19f4b8 .word 0xffffeac4 */
/* @0x19f4bc .word 0xffffeac8 */
/* @0x19f4c0 .word 0xffffeacc */
/* @0x19f4c4 .word 0xffffead0 */
/* @0x19f4c8 .word 0xffffead4 */
/* @0x19f4cc .word 0xffffead8 */
/* @0x19f4d0 .word 0xffffeadc */
/* @0x19f4d4 .word 0xffffeae0 */
/* @0x19f4d8 .word 0xffffeae4 */
/* @0x19f4dc .word 0xffffeae8 */
/* @0x19f4e0 .word 0xffffeaec */
/* @0x19f4e4 .word 0xffffeaf0 */
/* @0x19f4e8 .word 0xffffeaf4 */
/* @0x19f4ec .word 0xffffeaf8 */
/* @0x19f4f0 .word 0xffffc158 */
/* @0x19f4f4 .word 0xffffeafc */
/* @0x19f4f8 .word 0xffffc144 */
/* @0x19f4fc .word 0xffffeb00 */
/* @0x19f500 .word 0xffffc184 */
/* @0x19f504 .word 0xffffc188 */
/* @0x19f508 .word 0xffffc18c */

/* ── FUNC 0x19f50c · Option_Quit() · size=40 · insn=10 */
/* @0x19f50c ldr r2, [pc, #0x18] */
/* @0x19f510 mov r1, #0 */
/* @0x19f514 ldr r3, [pc, #0x14] */
/* @0x19f518 ldr r2, [pc, r2] */
/* @0x19f51c ldr r3, [pc, r3] */
/* @0x19f520 str r1, [r2] */
/* @0x19f524 str r1, [r3] */
/* @0x19f528 bx lr */
/* @0x19f52c eoreq lr, r4, r0, asr #17 */
/* @0x19f530 eoreq lr, r4, r0, asr #17 */

/* ── FUNC 0x19f534 · Option_Load(unsigned char*, unsigned int, unsigned char*) · size=2616 · insn=654 */
/* @0x19f534 ldr r3, [r0] */
/* @0x19f538 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x19f53c cmp r3, #0 */
/* @0x19f540 ldr r10, [pc, #0x940] */
/* @0x19f544 sub sp, sp, #36 */
/* @0x19f548 mov r4, r0 */
/* @0x19f54c add r10, pc, r10 */
/* @0x19f550 blt 0x19fb50 <_Z11Option_LoadPhjS_+0x61c> */
/* @0x19f554 ldr r3, [pc, #0x930] */
/* @0x19f558 moveq r1, #0 */
/* @0x19f55c movne r1, #1 */
/* @0x19f560 ldr r2, [pc, #0x928] */
/* @0x19f564 ldr r0, [r0, #0x4] */
/* @0x19f568 ldr r3, [r10, r3] */
/* @0x19f56c ldr lr, [r4, #0x8] */
/* @0x19f570 strb r1, [r3] */
/* @0x19f574 ldr r2, [r10, r2] */
/* @0x19f578 ldrb r2, [r2] */
/* @0x19f57c cmp r2, #0 */
/* @0x19f580 movne r2, #0 */
/* @0x19f584 strbne r2, [r3] */
/* @0x19f588 ldr r3, [pc, #0x904] */
/* @0x19f58c adds r0, r0, #0 */
/* @0x19f590 ldr r2, [pc, #0x900] */
/* @0x19f594 movne r0, #1 */
/* @0x19f598 adds lr, lr, #0 */
/* @0x19f59c ldr r1, [r10, r3] */
/* @0x19f5a0 ldr r3, [pc, #0x8f4] */
/* @0x19f5a4 movne lr, #1 */
/* @0x19f5a8 strb r0, [r1] */
/* @0x19f5ac ldr r1, [r10, r2] */
/* @0x19f5b0 ldr r0, [r4, #0xc] */
/* @0x19f5b4 ldr r2, [pc, #0x8e4] */
/* @0x19f5b8 strb lr, [r1] */
/* @0x19f5bc adds r0, r0, #0 */
/* @0x19f5c0 ldr r1, [r10, r3] */
/* @0x19f5c4 ldr lr, [r4, #0x10] */
/* @0x19f5c8 movne r0, #1 */
/* @0x19f5cc ldr r3, [pc, #0x8d0] */
/* @0x19f5d0 strb r0, [r1] */
/* @0x19f5d4 adds lr, lr, #0 */
/* @0x19f5d8 ldr r1, [r10, r2] */
/* @0x19f5dc movne lr, #1 */
/* @0x19f5e0 ldr r0, [r4, #0x14] */
/* @0x19f5e4 ldr r2, [pc, #0x8bc] */
/* @0x19f5e8 strb lr, [r1] */
/* @0x19f5ec ldr r1, [r10, r3] */
/* @0x19f5f0 ldr lr, [r4, #0x18] */
/* @0x19f5f4 ldr r3, [pc, #0x8b0] */
/* @0x19f5f8 str r0, [r1] */
/* @0x19f5fc adds lr, lr, #0 */
/* @0x19f600 ldr r1, [r10, r2] */
/* @0x19f604 ldr r0, [r4, #0x1c] */
/* @0x19f608 movne lr, #1 */
/* @0x19f60c ldr r2, [pc, #0x89c] */
/* @0x19f610 strb lr, [r1] */
/* @0x19f614 adds r0, r0, #0 */
/* @0x19f618 ldr r1, [r10, r3] */
/* @0x19f61c ldr r3, [r4, #0x20] */
/* @0x19f620 movne r0, #1 */
/* @0x19f624 strb r0, [r1] */
/* @0x19f628 ldr r2, [r10, r2] */
/* @0x19f62c mov r0, r3 */
/* @0x19f630 str r3, [r2] */
/* @0x19f634 bl 0x17ae08 <_Z19GR_Window_Set_Colorj> */
/* @0x19f638 ldr r1, [pc, #0x874] */
/* @0x19f63c mov r3, #0 */
/* @0x19f640 ldr lr, [r4, #0x24] */
/* @0x19f644 ldr r2, [pc, #0x86c] */
/* @0x19f648 ldr r0, [r10, r1] */
/* @0x19f64c subs lr, lr, r3 */
/* @0x19f650 ldr r5, [r4, #0x28] */
/* @0x19f654 movne lr, #1 */
/* @0x19f658 ldr r1, [pc, #0x85c] */
/* @0x19f65c strb lr, [r0] */
/* @0x19f660 ldr r0, [r10, r2] */
/* @0x19f664 ldr lr, [r4, #0x2c] */
/* @0x19f668 ldr r2, [pc, #0x850] */
/* @0x19f66c str r5, [r0] */
/* @0x19f670 ldr r0, [r10, r1] */
/* @0x19f674 ldr r5, [r4, #0x30] */
/* @0x19f678 ldr r1, [pc, #0x844] */
/* @0x19f67c str lr, [r0] */
/* @0x19f680 ldr r0, [r10, r2] */
/* @0x19f684 ldr lr, [r4, #0x34] */
/* @0x19f688 ldr r2, [pc, #0x838] */
/* @0x19f68c str r5, [r0] */
/* @0x19f690 subs lr, lr, r3 */
/* @0x19f694 ldr r0, [r10, r1] */
/* @0x19f698 movne lr, #1 */
/* @0x19f69c ldr r5, [r4, #0x38] */
/* @0x19f6a0 ldr r1, [pc, #0x824] */
/* @0x19f6a4 strb lr, [r0] */
/* @0x19f6a8 ldr r0, [r10, r2] */
/* @0x19f6ac ldr lr, [r4, #0x3c] */
/* @0x19f6b0 ldr r2, [pc, #0x818] */
/* @0x19f6b4 str r5, [r0] */
/* @0x19f6b8 subs lr, lr, r3 */
/* @0x19f6bc ldr r0, [r10, r1] */
/* @0x19f6c0 ldr r5, [r4, #0x40] */
/* @0x19f6c4 movne lr, #1 */
/* @0x19f6c8 ldr r1, [pc, #0x804] */
/* @0x19f6cc strb lr, [r0] */
/* @0x19f6d0 subs r5, r5, r3 */
/* @0x19f6d4 ldr r0, [r10, r2] */
/* @0x19f6d8 ldr lr, [r4, #0x44] */
/* @0x19f6dc movne r5, #1 */
/* @0x19f6e0 ldr r2, [pc, #0x7f0] */
/* @0x19f6e4 strb r5, [r0] */
/* @0x19f6e8 subs lr, lr, r3 */
/* @0x19f6ec ldr r0, [r10, r1] */
/* @0x19f6f0 ldr r5, [r4, #0x48] */
/* @0x19f6f4 movne lr, #1 */
/* @0x19f6f8 ldr r1, [pc, #0x7dc] */
/* @0x19f6fc strb lr, [r0] */
/* @0x19f700 subs r5, r5, r3 */
/* @0x19f704 ldr r0, [r10, r2] */
/* @0x19f708 ldr lr, [r4, #0x4c] */
/* @0x19f70c movne r5, #1 */
/* @0x19f710 ldr r2, [pc, #0x7c8] */
/* @0x19f714 strb r5, [r0] */
/* @0x19f718 subs lr, lr, r3 */
/* @0x19f71c ldr r1, [r10, r1] */
/* @0x19f720 ldr r5, [r4, #0x50] */
/* @0x19f724 movne lr, #1 */
/* @0x19f728 ldr r0, [pc, #0x7b4] */
/* @0x19f72c strb lr, [r1] */
/* @0x19f730 subs r5, r5, r3 */
/* @0x19f734 ldr lr, [r10, r2] */
/* @0x19f738 movne r5, #1 */
/* @0x19f73c ldr r1, [pc, #0x7a4] */
/* @0x19f740 ldr r6, [r4, #0x58] */
/* @0x19f744 strb r5, [lr] */
/* @0x19f748 ldr r5, [r4, #0x54] */
/* @0x19f74c subs r6, r6, r3 */
/* @0x19f750 ldr lr, [r10, r0] */
/* @0x19f754 ldr r2, [pc, #0x790] */
/* @0x19f758 movne r6, #1 */
/* @0x19f75c ldr r0, [pc, #0x78c] */
/* @0x19f760 str r5, [lr] */
/* @0x19f764 ldr r5, [r10, r1] */
/* @0x19f768 ldr r1, [pc, #0x784] */
/* @0x19f76c ldr lr, [pc, #0x784] */
/* @0x19f770 strb r6, [r5] */
/* @0x19f774 ldr r5, [r10, r2] */
/* @0x19f778 ldr r6, [r4, #0x5c] */
/* @0x19f77c ldr r2, [pc, #0x778] */
/* @0x19f780 strb r3, [r5] */
/* @0x19f784 subs r6, r6, r3 */
/* @0x19f788 ldr r7, [r10, r0] */
/* @0x19f78c movne r6, #1 */
/* @0x19f790 ldr r0, [pc, #0x768] */
/* @0x19f794 ldr r5, [r4, #0x68] */
/* @0x19f798 strb r3, [r7] */
/* @0x19f79c ldr r3, [r10, r1] */
/* @0x19f7a0 ldr r7, [r4, #0x6c] */
/* @0x19f7a4 ldr r1, [pc, #0x758] */
/* @0x19f7a8 strb r6, [r3] */
/* @0x19f7ac adds r7, r7, #0 */
/* @0x19f7b0 ldr r6, [r10, lr] */
/* @0x19f7b4 ldr r3, [r10, r2] */
/* @0x19f7b8 movne r7, #1 */
/* @0x19f7bc ldr lr, [r4, #0x70] */
/* @0x19f7c0 ldr r8, [r6] */
/* @0x19f7c4 ldr r2, [pc, #0x73c] */
/* @0x19f7c8 adds lr, lr, #0 */
/* @0x19f7cc add r5, r8, r5 */
/* @0x19f7d0 str r5, [r3] */
/* @0x19f7d4 ldr r0, [r10, r0] */
/* @0x19f7d8 movne lr, #1 */
/* @0x19f7dc ldr r5, [r4, #0x74] */
/* @0x19f7e0 ldr r3, [pc, #0x724] */
/* @0x19f7e4 strb r7, [r0] */
/* @0x19f7e8 adds r5, r5, #0 */
/* @0x19f7ec ldr r1, [r10, r1] */
/* @0x19f7f0 ldr r7, [r4, #0x7c] */
/* @0x19f7f4 movne r5, #1 */
/* @0x19f7f8 ldr r0, [pc, #0x710] */
/* @0x19f7fc str lr, [r1] */
/* @0x19f800 adds r7, r7, #0 */
/* @0x19f804 ldr r1, [r10, r2] */
/* @0x19f808 ldr lr, [r4, #0x80] */
/* @0x19f80c movne r7, #1 */
/* @0x19f810 ldr r2, [pc, #0x6fc] */
/* @0x19f814 strb r5, [r1] */
/* @0x19f818 adds lr, lr, #0 */
/* @0x19f81c ldr r5, [r10, r3] */
/* @0x19f820 ldr r1, [r4, #0x84] */
/* @0x19f824 movne lr, #1 */
/* @0x19f828 ldr r3, [pc, #0x6e8] */
/* @0x19f82c strb r7, [r5] */
/* @0x19f830 adds r1, r1, #0 */
/* @0x19f834 ldr r0, [r10, r0] */
/* @0x19f838 movne r1, #1 */
/* @0x19f83c strb lr, [r0] */
/* @0x19f840 ldr r2, [r10, r2] */
/* @0x19f844 strb r1, [r2] */
/* @0x19f848 ldr r3, [r10, r3] */
/* @0x19f84c ldr r3, [r3] */
/* @0x19f850 cmp r3, #4 */
/* @0x19f854 bgt 0x19fadc <_Z11Option_LoadPhjS_+0x5a8> */
/* @0x19f858 ldr r3, [pc, #0x6bc] */
/* @0x19f85c adds r11, r4, #144 */
/* @0x19f860 ldr r9, [r4, #0x8c] */
/* @0x19f864 ldr r8, [r10, r3] */
/* @0x19f868 str r9, [r8] */
/* @0x19f86c beq 0x19fe28 <_Z11Option_LoadPhjS_+0x8f4> */
/* @0x19f870 cmp r9, #0 */
/* @0x19f874 ble 0x19fe68 <_Z11Option_LoadPhjS_+0x934> */
/* @0x19f878 add r11, r11, #8 */
/* @0x19f87c ldr r12, [pc, #0x69c] */
/* @0x19f880 str r11, [sp, #0xc] */
/* @0x19f884 mov r5, #0 */
/* @0x19f888 ldr r11, [pc, #0x694] */
/* @0x19f88c add r12, pc, r12 */
/* @0x19f890 ldr r4, [sp, #0xc] */
/* @0x19f894 add r11, pc, r11 */
/* @0x19f898 str r12, [sp, #0x8] */
/* @0x19f89c str r11, [sp, #0x4] */
/* @0x19f8a0 b 0x19f8c8 <_Z11Option_LoadPhjS_+0x394> */
/* @0x19f8a4 ldr r1, [sp, #0x8] */
/* @0x19f8a8 mov r0, r11 */
/* @0x19f8ac bl 0xb6574 <strcmp@plt> */
/* @0x19f8b0 subs r1, r0, #0 */
/* @0x19f8b4 beq 0x19faa8 <_Z11Option_LoadPhjS_+0x574> */
/* @0x19f8b8 add r5, r5, #1 */
/* @0x19f8bc add r4, r4, #8 */
/* @0x19f8c0 cmp r5, r9 */
/* @0x19f8c4 beq 0x19f930 <_Z11Option_LoadPhjS_+0x3fc> */
/* @0x19f8c8 ldr r0, [r4, #-0x8] */
/* @0x19f8cc ldr r7, [r4, #-0x4] */
/* @0x19f8d0 cmp r0, #0 */
/* @0x19f8d4 ldr r1, [sp, #0x4] */
/* @0x19f8d8 ldrne r3, [r6] */
/* @0x19f8dc moveq r11, r0 */
/* @0x19f8e0 addne r11, r3, r0 */
/* @0x19f8e4 cmp r7, #0 */
/* @0x19f8e8 ldrne r2, [r6] */
/* @0x19f8ec mov r0, r11 */
/* @0x19f8f0 addne r7, r2, r7 */
/* @0x19f8f4 bl 0xb6574 <strcmp@plt> */
/* @0x19f8f8 cmp r0, #0 */
/* @0x19f8fc bne 0x19f8a4 <_Z11Option_LoadPhjS_+0x370> */
/* @0x19f900 mov r0, r7 */
/* @0x19f904 add r5, r5, #1 */
/* @0x19f908 bl 0xb66b8 <atoi@plt> */
/* @0x19f90c ldr r3, [pc, #0x614] */
/* @0x19f910 ldr r2, [r8] */
/* @0x19f914 cmp r5, r9 */
/* @0x19f918 add r4, r4, #8 */
/* @0x19f91c ldr r3, [r10, r3] */
/* @0x19f920 sub r2, r2, #1 */
/* @0x19f924 str r2, [r8] */
/* @0x19f928 str r0, [r3] */
/* @0x19f92c bne 0x19f8c8 <_Z11Option_LoadPhjS_+0x394> */
/* @0x19f930 ldr r2, [pc, #0x5f4] */
/* @0x19f934 mov r3, #352 */
/* @0x19f938 ldr r7, [pc, #0x5f0] */
/* @0x19f93c mov r5, #0 */
/* @0x19f940 ldr r1, [r8] */
/* @0x19f944 mov r4, r5 */
/* @0x19f948 ldr r2, [r10, r2] */
/* @0x19f94c add r7, pc, r7 */
/* @0x19f950 ldr r12, [pc, #0x5dc] */
/* @0x19f954 lsl r1, r1, #2 */
/* @0x19f958 ldr r11, [sp, #0xc] */
/* @0x19f95c str r2, [sp, #0x8] */
/* @0x19f960 mov r2, r7 */
/* @0x19f964 ldr r0, [sp, #0x8] */
/* @0x19f968 add r12, pc, r12 */
/* @0x19f96c str r12, [sp] */
/* @0x19f970 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x19f974 ldr r0, [pc, #0x5bc] */
/* @0x19f978 movw r3, #0x161 */
/* @0x19f97c ldr lr, [pc, #0x5b8] */
/* @0x19f980 mov r2, r7 */
/* @0x19f984 ldr r1, [r8] */
/* @0x19f988 add lr, pc, lr */
/* @0x19f98c str lr, [sp, #0x4] */
/* @0x19f990 ldr r0, [r10, r0] */
/* @0x19f994 lsl r1, r1, #2 */
/* @0x19f998 str r0, [sp, #0xc] */
/* @0x19f99c ldr r0, [pc, #0x59c] */
/* @0x19f9a0 add r0, pc, r0 */
/* @0x19f9a4 str r0, [sp, #0x10] */
/* @0x19f9a8 ldr r0, [sp, #0xc] */
/* @0x19f9ac bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x19f9b0 ldr r12, [sp] */
/* @0x19f9b4 ldr r3, [pc, #0x588] */
/* @0x19f9b8 str r10, [sp, #0x1c] */
/* @0x19f9bc add r3, pc, r3 */
/* @0x19f9c0 mov r10, r12 */
/* @0x19f9c4 str r3, [sp, #0x14] */
/* @0x19f9c8 b 0x19f9dc <_Z11Option_LoadPhjS_+0x4a8> */
/* @0x19f9cc add r4, r4, #1 */
/* @0x19f9d0 add r11, r11, #8 */
/* @0x19f9d4 cmp r4, r9 */
/* @0x19f9d8 beq 0x19fa9c <_Z11Option_LoadPhjS_+0x568> */
/* @0x19f9dc ldr r7, [r11, #-0x8] */
/* @0x19f9e0 mov r1, r10 */
/* @0x19f9e4 ldr r8, [r11, #-0x4] */
/* @0x19f9e8 cmp r7, #0 */
/* @0x19f9ec ldrne r2, [r6] */
/* @0x19f9f0 addne r7, r2, r7 */
/* @0x19f9f4 cmp r8, #0 */
/* @0x19f9f8 ldrne r2, [r6] */
/* @0x19f9fc mov r0, r7 */
/* @0x19fa00 addne r8, r2, r8 */
/* @0x19fa04 bl 0xb6574 <strcmp@plt> */
/* @0x19fa08 cmp r0, #0 */
/* @0x19fa0c beq 0x19f9cc <_Z11Option_LoadPhjS_+0x498> */
/* @0x19fa10 mov r0, r7 */
/* @0x19fa14 ldr r1, [sp, #0x4] */
/* @0x19fa18 bl 0xb6574 <strcmp@plt> */
/* @0x19fa1c cmp r0, #0 */
/* @0x19fa20 beq 0x19f9cc <_Z11Option_LoadPhjS_+0x498> */
/* @0x19fa24 ldr r12, [sp, #0x8] */
/* @0x19fa28 mov r0, r7 */
/* @0x19fa2c ldr r7, [r12] */
/* @0x19fa30 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x19fa34 ldr r12, [sp, #0xc] */
/* @0x19fa38 lsl r3, r5, #2 */
/* @0x19fa3c str r3, [sp, #0x18] */
/* @0x19fa40 str r0, [r7, r5, lsl #2] */
/* @0x19fa44 mov r0, r8 */
/* @0x19fa48 ldr r8, [r12] */
/* @0x19fa4c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x19fa50 ldr r12, [sp, #0x8] */
/* @0x19fa54 ldr r1, [sp, #0x10] */
/* @0x19fa58 str r0, [r8, r5, lsl #2] */
/* @0x19fa5c ldr r2, [r12] */
/* @0x19fa60 ldr r8, [r2, r5, lsl #2] */
/* @0x19fa64 mov r0, r8 */
/* @0x19fa68 bl 0xb6574 <strcmp@plt> */
/* @0x19fa6c cmp r0, #0 */
/* @0x19fa70 beq 0x19fb20 <_Z11Option_LoadPhjS_+0x5ec> */
/* @0x19fa74 mov r0, r8 */
/* @0x19fa78 ldr r1, [sp, #0x14] */
/* @0x19fa7c bl 0xb6574 <strcmp@plt> */
/* @0x19fa80 cmp r0, #0 */
/* @0x19fa84 beq 0x19faf8 <_Z11Option_LoadPhjS_+0x5c4> */
/* @0x19fa88 add r4, r4, #1 */
/* @0x19fa8c add r5, r5, #1 */
/* @0x19fa90 cmp r4, r9 */
/* @0x19fa94 add r11, r11, #8 */
/* @0x19fa98 bne 0x19f9dc <_Z11Option_LoadPhjS_+0x4a8> */
/* @0x19fa9c mov r0, #1 */
/* @0x19faa0 add sp, sp, #36 */
/* @0x19faa4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19faa8 mov r2, r1 */
/* @0x19faac mov r0, r7 */
/* @0x19fab0 bl 0xb697c <strtoul@plt> */
/* @0x19fab4 ldr r1, [pc, #0x48c] */
/* @0x19fab8 ldr r3, [pc, #0x48c] */
/* @0x19fabc ldr r2, [r8] */
/* @0x19fac0 ldr r1, [r10, r1] */
/* @0x19fac4 sub r2, r2, #1 */
/* @0x19fac8 str r0, [r1] */
/* @0x19facc ldr r3, [r10, r3] */
/* @0x19fad0 str r2, [r8] */
/* @0x19fad4 str r0, [r3] */
/* @0x19fad8 b 0x19f8b8 <_Z11Option_LoadPhjS_+0x384> */
/* @0x19fadc ldr r3, [pc, #0x46c] */
/* @0x19fae0 ldr r2, [r4, #0x88] */
/* @0x19fae4 ldr r3, [r10, r3] */
/* @0x19fae8 adds r2, r2, #0 */
/* @0x19faec movne r2, #1 */
/* @0x19faf0 strb r2, [r3] */
/* @0x19faf4 b 0x19f858 <_Z11Option_LoadPhjS_+0x324> */
/* @0x19faf8 ldr r12, [sp, #0xc] */
/* @0x19fafc ldr r3, [sp, #0x18] */
/* @0x19fb00 ldr r2, [r12] */
/* @0x19fb04 ldr r0, [r2, r3] */
/* @0x19fb08 bl 0xb66b8 <atoi@plt> */
/* @0x19fb0c ldr r2, [pc, #0x440] */
/* @0x19fb10 ldr r12, [sp, #0x1c] */
/* @0x19fb14 ldr r2, [r12, r2] */
/* @0x19fb18 str r0, [r2] */
/* @0x19fb1c b 0x19fa88 <_Z11Option_LoadPhjS_+0x554> */
/* @0x19fb20 ldr r12, [sp, #0xc] */
/* @0x19fb24 ldr r2, [r12] */
/* @0x19fb28 ldr r0, [r2, r5, lsl #2] */
/* @0x19fb2c bl 0xb66b8 <atoi@plt> */
/* @0x19fb30 ldr r2, [pc, #0x420] */
/* @0x19fb34 ldr r12, [sp, #0x8] */
/* @0x19fb38 ldr r3, [sp, #0x1c] */
/* @0x19fb3c ldr r1, [r12] */
/* @0x19fb40 ldr r2, [r3, r2] */
/* @0x19fb44 ldr r8, [r1, r5, lsl #2] */
/* @0x19fb48 str r0, [r2] */
/* @0x19fb4c b 0x19fa74 <_Z11Option_LoadPhjS_+0x540> */
/* @0x19fb50 ldr r3, [r0, #0x4] */
/* @0x19fb54 cmp r3, #2 */
/* @0x19fb58 movne r0, #0 */
/* @0x19fb5c bne 0x19faa0 <_Z11Option_LoadPhjS_+0x56c> */
/* @0x19fb60 ldr r1, [pc, #0x324] */
/* @0x19fb64 ldr r0, [pc, #0x324] */
/* @0x19fb68 ldrd r2, r3, [r4, #8] */
/* @0x19fb6c ldr r1, [r10, r1] */
/* @0x19fb70 and lr, r2, #1 */
/* @0x19fb74 ldr r5, [pc, #0x31c] */
/* @0x19fb78 ubfx r12, r2, #0x3, #0x1 */
/* @0x19fb7c ubfx r7, r2, #0x2, #0x1 */
/* @0x19fb80 strb lr, [r1] */
/* @0x19fb84 ubfx r9, r2, #0x4, #0x1 */
/* @0x19fb88 ldr r0, [r10, r0] */
/* @0x19fb8c ubfx r6, r2, #0x5, #0x1 */
/* @0x19fb90 ldr lr, [pc, #0x2fc] */
/* @0x19fb94 ldrb r0, [r0] */
/* @0x19fb98 cmp r0, #0 */
/* @0x19fb9c movne r0, #0 */
/* @0x19fba0 strbne r0, [r1] */
/* @0x19fba4 ldr lr, [r10, lr] */
/* @0x19fba8 lsrs r1, r3, #1 */
/* @0x19fbac rrx r0, r2 */
/* @0x19fbb0 ldr r1, [pc, #0x2e4] */
/* @0x19fbb4 and r8, r0, #1 */
/* @0x19fbb8 ldr r3, [pc, #0x2e0] */
/* @0x19fbbc strb r8, [lr] */
/* @0x19fbc0 ubfx lr, r2, #0x6, #0x1 */
/* @0x19fbc4 ldr r2, [r10, r5] */
/* @0x19fbc8 ldr r0, [pc, #0x2d4] */
/* @0x19fbcc ldr r8, [r4, #0x10] */
/* @0x19fbd0 strb r7, [r2] */
/* @0x19fbd4 ldr r7, [r10, r1] */
/* @0x19fbd8 ldr r5, [pc, #0x2c8] */
/* @0x19fbdc ldr r1, [pc, #0x2c8] */
/* @0x19fbe0 strb r12, [r7] */
/* @0x19fbe4 ldr r7, [r10, r3] */
/* @0x19fbe8 ldr r2, [pc, #0x2c0] */
/* @0x19fbec ldr r3, [r4, #0x14] */
/* @0x19fbf0 strb r9, [r7] */
/* @0x19fbf4 ldr r7, [r10, r0] */
/* @0x19fbf8 mov r0, r3 */
/* @0x19fbfc str r8, [r7] */
/* @0x19fc00 ldr r5, [r10, r5] */
/* @0x19fc04 strb r6, [r5] */
/* @0x19fc08 ldr r1, [r10, r1] */
/* @0x19fc0c strb lr, [r1] */
/* @0x19fc10 ldr r2, [r10, r2] */
/* @0x19fc14 str r3, [r2] */
/* @0x19fc18 bl 0x17ae08 <_Z19GR_Window_Set_Colorj> */
/* @0x19fc1c ldr r1, [pc, #0x290] */
/* @0x19fc20 ldr r2, [pc, #0x290] */
/* @0x19fc24 ldr r3, [r4, #0x8] */
/* @0x19fc28 ldr r0, [r10, r1] */
/* @0x19fc2c ldr r12, [r4, #0x18] */
/* @0x19fc30 ubfx lr, r3, #0x7, #0x1 */
/* @0x19fc34 ldr r1, [pc, #0x280] */
/* @0x19fc38 ubfx r8, r3, #0x8, #0x1 */
/* @0x19fc3c strb lr, [r0] */
/* @0x19fc40 ubfx r7, r3, #0x9, #0x1 */
/* @0x19fc44 ldr r0, [r10, r2] */
/* @0x19fc48 ubfx r6, r3, #0xa, #0x1 */
/* @0x19fc4c ldr r9, [r4, #0x1c] */
/* @0x19fc50 ubfx r5, r3, #0xb, #0x1 */
/* @0x19fc54 ldr r2, [pc, #0x264] */
/* @0x19fc58 ubfx lr, r3, #0xc, #0x1 */
/* @0x19fc5c str r12, [r0] */
/* @0x19fc60 ubfx r0, r3, #0xd, #0x1 */
/* @0x19fc64 ldr r12, [r10, r1] */
/* @0x19fc68 ubfx r1, r3, #0xe, #0x1 */
/* @0x19fc6c ubfx r11, r3, #0xf, #0x1 */
/* @0x19fc70 str r9, [r12] */
/* @0x19fc74 ubfx r9, r3, #0x18, #0x1 */
/* @0x19fc78 str r9, [sp, #0x8] */
/* @0x19fc7c ldr r9, [r4, #0x20] */
/* @0x19fc80 ldr r12, [r10, r2] */
/* @0x19fc84 ldr r2, [pc, #0x238] */
/* @0x19fc88 str r9, [r12] */
/* @0x19fc8c ubfx r12, r3, #0x19, #0x1 */
/* @0x19fc90 str r12, [sp, #0xc] */
/* @0x19fc94 ldr r12, [r10, r2] */
/* @0x19fc98 ldr r2, [pc, #0x228] */
/* @0x19fc9c strb r8, [r12] */
/* @0x19fca0 ldr r8, [r4, #0x24] */
/* @0x19fca4 ldr r12, [r10, r2] */
/* @0x19fca8 ldr r2, [pc, #0x21c] */
/* @0x19fcac str r8, [r12] */
/* @0x19fcb0 ubfx r8, r3, #0x1a, #0x1 */
/* @0x19fcb4 ldr r12, [r10, r2] */
/* @0x19fcb8 ldr r2, [pc, #0x210] */
/* @0x19fcbc strb r7, [r12] */
/* @0x19fcc0 ubfx r7, r3, #0x1b, #0x1 */
/* @0x19fcc4 ldr r12, [r10, r2] */
/* @0x19fcc8 ldr r2, [pc, #0x204] */
/* @0x19fccc strb r6, [r12] */
/* @0x19fcd0 ubfx r6, r3, #0x10, #0x1 */
/* @0x19fcd4 ldr r12, [r10, r2] */
/* @0x19fcd8 ldr r2, [pc, #0x1f8] */
/* @0x19fcdc strb r5, [r12] */
/* @0x19fce0 ubfx r5, r3, #0x11, #0x1 */
/* @0x19fce4 ldr r12, [r10, r2] */
/* @0x19fce8 ldr r2, [pc, #0x1ec] */
/* @0x19fcec strb lr, [r12] */
/* @0x19fcf0 ubfx lr, r3, #0x12, #0x1 */
/* @0x19fcf4 ldr r12, [r10, r2] */
/* @0x19fcf8 ldr r2, [pc, #0x1e0] */
/* @0x19fcfc strb r0, [r12] */
/* @0x19fd00 ubfx r0, r3, #0x14, #0x1 */
/* @0x19fd04 ldr r12, [r10, r2] */
/* @0x19fd08 ldr r2, [pc, #0x1d4] */
/* @0x19fd0c strb r1, [r12] */
/* @0x19fd10 ldr r12, [r4, #0x28] */
/* @0x19fd14 ldr r1, [r10, r2] */
/* @0x19fd18 ldr r2, [pc, #0x1c8] */
/* @0x19fd1c str r12, [r1] */
/* @0x19fd20 ubfx r1, r3, #0x15, #0x1 */
/* @0x19fd24 ldr r2, [r10, r2] */
/* @0x19fd28 ldr r12, [pc, #0x1bc] */
/* @0x19fd2c ldr r9, [sp, #0x8] */
/* @0x19fd30 strb r11, [r2] */
/* @0x19fd34 ubfx r2, r3, #0x16, #0x1 */
/* @0x19fd38 ldr r12, [r10, r12] */
/* @0x19fd3c str r12, [sp, #0x4] */
/* @0x19fd40 ldr r11, [sp, #0x4] */
/* @0x19fd44 ldr r12, [pc, #0x1a4] */
/* @0x19fd48 strb r9, [r11] */
/* @0x19fd4c ldr r9, [sp, #0xc] */
/* @0x19fd50 ldr r11, [r10, r12] */
/* @0x19fd54 ldr r12, [pc, #0x200] */
/* @0x19fd58 strb r9, [r11] */
/* @0x19fd5c ldr r9, [pc, #0x1fc] */
/* @0x19fd60 ldr r11, [r10, r12] */
/* @0x19fd64 ldr r12, [pc, #0x188] */
/* @0x19fd68 strb r8, [r11] */
/* @0x19fd6c ldr r11, [r10, r9] */
/* @0x19fd70 ldr r9, [pc, #0x180] */
/* @0x19fd74 ldr r8, [pc, #0x180] */
/* @0x19fd78 strb r7, [r11] */
/* @0x19fd7c ldr r11, [r10, r12] */
/* @0x19fd80 ldr r7, [pc, #0x178] */
/* @0x19fd84 ldr r12, [r4, #0x34] */
/* @0x19fd88 strb r6, [r11] */
/* @0x19fd8c ldr r6, [r10, r9] */
/* @0x19fd90 ldr r9, [r10, r8] */
/* @0x19fd94 ldr r8, [pc, #0x168] */
/* @0x19fd98 ldr r11, [r6] */
/* @0x19fd9c add r12, r11, r12 */
/* @0x19fda0 str r12, [r9] */
/* @0x19fda4 ldr r9, [r10, r7] */
/* @0x19fda8 ldr r12, [r4, #0x38] */
/* @0x19fdac ldr r7, [pc, #0x154] */
/* @0x19fdb0 strb r5, [r9] */
/* @0x19fdb4 adds r12, r12, #0 */
/* @0x19fdb8 ldr r5, [r10, r8] */
/* @0x19fdbc movne r12, #1 */
/* @0x19fdc0 ldr r9, [pc, #0x144] */
/* @0x19fdc4 ldr r8, [pc, #0x144] */
/* @0x19fdc8 str r12, [r5] */
/* @0x19fdcc ldr r12, [r10, r7] */
/* @0x19fdd0 ldr r7, [pc, #0x13c] */
/* @0x19fdd4 ldr r5, [pc, #0x13c] */
/* @0x19fdd8 strb lr, [r12] */
/* @0x19fddc ldr lr, [r10, r9] */
/* @0x19fde0 strb r0, [lr] */
/* @0x19fde4 ldr r0, [r10, r8] */
/* @0x19fde8 strb r1, [r0] */
/* @0x19fdec ldr r1, [r10, r7] */
/* @0x19fdf0 strb r2, [r1] */
/* @0x19fdf4 ldr r2, [r10, r5] */
/* @0x19fdf8 ldr r2, [r2] */
/* @0x19fdfc cmp r2, #4 */
/* @0x19fe00 ldrgt r2, [pc, #0x148] */
/* @0x19fe04 ubfxgt r3, r3, #0x17, #0x1 */
/* @0x19fe08 ldrgt r2, [r10, r2] */
/* @0x19fe0c strbgt r3, [r2] */
/* @0x19fe10 ldr r3, [pc, #0x104] */
/* @0x19fe14 add r11, r4, #64 */
/* @0x19fe18 ldr r9, [r4, #0x3c] */
/* @0x19fe1c ldr r8, [r10, r3] */
/* @0x19fe20 str r9, [r8] */
/* @0x19fe24 b 0x19f870 <_Z11Option_LoadPhjS_+0x33c> */
/* @0x19fe28 ldr r2, [pc, #0xfc] */
/* @0x19fe2c lsl r1, r9, #2 */
/* @0x19fe30 ldr r4, [pc, #0x12c] */
/* @0x19fe34 mov r3, #352 */
/* @0x19fe38 ldr r0, [r10, r2] */
/* @0x19fe3c add r4, pc, r4 */
/* @0x19fe40 mov r2, r4 */
/* @0x19fe44 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x19fe48 ldr r1, [r8] */
/* @0x19fe4c ldr r0, [pc, #0xe4] */
/* @0x19fe50 mov r2, r4 */
/* @0x19fe54 movw r3, #0x161 */
/* @0x19fe58 lsl r1, r1, #2 */
/* @0x19fe5c ldr r0, [r10, r0] */
/* @0x19fe60 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x19fe64 b 0x19fa9c <_Z11Option_LoadPhjS_+0x568> */
/* @0x19fe68 ldr r2, [pc, #0xbc] */
/* @0x19fe6c mov r3, #352 */
/* @0x19fe70 ldr r1, [r8] */
/* @0x19fe74 ldr r4, [pc, #0xec] */
/* @0x19fe78 ldr r0, [r10, r2] */
/* @0x19fe7c add r4, pc, r4 */
/* @0x19fe80 lsl r1, r1, #2 */
/* @0x19fe84 b 0x19fe40 <_Z11Option_LoadPhjS_+0x90c> */
/* @0x19fe88 eoreq r2, r5, r4, lsl #14 */
/* @0x19fe8c .word 0xffffea98 */
/* @0x19fe90 .word 0xffffeb04 */
/* @0x19fe94 .word 0xffffea9c */
/* @0x19fe98 .word 0xffffd0e0 */
/* @0x19fe9c .word 0xffffeaa0 */
/* @0x19fea0 .word 0xffffd79c */
/* @0x19fea4 .word 0xffffeaa4 */
/* @0x19fea8 .word 0xffffeaa8 */
/* @0x19feac .word 0xffffeaac */
/* @0x19feb0 .word 0xffffeab0 */
/* @0x19feb4 .word 0xffffeab4 */
/* @0x19feb8 .word 0xffffeab8 */
/* @0x19febc .word 0xffffeabc */
/* @0x19fec0 .word 0xffffeac0 */
/* @0x19fec4 .word 0xffffeac4 */
/* @0x19fec8 .word 0xffffeacc */
/* @0x19fecc .word 0xffffead0 */
/* @0x19fed0 .word 0xffffead4 */
/* @0x19fed4 .word 0xffffead8 */
/* @0x19fed8 .word 0xffffeadc */
/* @0x19fedc .word 0xffffeae0 */
/* @0x19fee0 .word 0xffffeae4 */
/* @0x19fee4 .word 0xffffeae8 */
/* @0x19fee8 .word 0xffffeac8 */
/* @0x19feec .word 0xffffeb08 */
/* @0x19fef0 .word 0xffffeb0c */
/* @0x19fef4 .word 0xffffeaec */
/* @0x19fef8 .word 0xffffbcf4 */
/* @0x19fefc .word 0xffffeb10 */
/* @0x19ff00 .word 0xffffeaf0 */
/* @0x19ff04 .word 0xffffeaf4 */
/* @0x19ff08 .word 0xffffeaf8 */
/* @0x19ff0c .word 0xffffeafc */
/* @0x19ff10 .word 0xffffc144 */
/* @0x19ff14 .word 0xffffeb00 */
/* @0x19ff18 .word 0xffffea88 */
/* @0x19ff1c .word 0xffffc184 */
/* @0x19ff20 andseq sp, r10, r12, lsl #13 */
/* @0x19ff24 andseq sp, r10, r4, ror r6 */
/* @0x19ff28 .word 0xffffc964 */
/* @0x19ff2c .word 0xffffc188 */
/* @0x19ff30 ldrsheq sp, [r10], -r12 */
/* @0x19ff34 andseq sp, r10, r0, lsr #11 */
/* @0x19ff38 .word 0xffffc18c */
/* @0x19ff3c mulseq r10, r0, r5 */
/* @0x19ff40 andseq sp, r10, r8, lsl #11 */
/* @0x19ff44 andseq sp, r10, r12, ror r5 */
/* @0x19ff48 .word 0xffffc0ac */
/* @0x19ff4c .word 0xffffeb14 */
/* @0x19ff50 .word 0xffffeb18 */
/* @0x19ff54 .word 0xffffe7a4 */
/* @0x19ff58 .word 0xffffe7a0 */
/* @0x19ff5c .word 0xffffea30 */
/* @0x19ff60 .word 0xffffea34 */
/* @0x19ff64 andseq sp, r10, r12, lsl #2 */
/* @0x19ff68 andseq sp, r10, r12, asr #1 */

/* ── FUNC 0x19ff6c · Speed_Factor() · size=196 · insn=49 */
/* @0x19ff6c push {r4, lr} */
/* @0x19ff70 ldr r4, [pc, #0xa4] */
/* @0x19ff74 ldr r3, [pc, #0xa4] */
/* @0x19ff78 add r4, pc, r4 */
/* @0x19ff7c ldr r3, [r4, r3] */
/* @0x19ff80 ldrb r3, [r3] */
/* @0x19ff84 cmp r3, #0 */
/* @0x19ff88 bne 0x19fffc <_Z12Speed_Factorv+0x90> */
/* @0x19ff8c ldr r3, [pc, #0x90] */
/* @0x19ff90 ldr r3, [r4, r3] */
/* @0x19ff94 ldr r3, [r3] */
/* @0x19ff98 ldr r0, [r3, #0xc] */
/* @0x19ff9c cmp r0, #30 */
/* @0x19ffa0 ble 0x19fff0 <_Z12Speed_Factorv+0x84> */
/* @0x19ffa4 ldr r3, [pc, #0x7c] */
/* @0x19ffa8 ldr r3, [r4, r3] */
/* @0x19ffac ldr r3, [r3] */
/* @0x19ffb0 cmp r3, #30 */
/* @0x19ffb4 ble 0x19fff0 <_Z12Speed_Factorv+0x84> */
/* @0x19ffb8 vmov s12, r0 */
/* @0x19ffbc vldr s13, [pc, #84] */
/* @0x19ffc0 vcvt.f32.s32 s15, s12 */
/* @0x19ffc4 vmov s12, r3 */
/* @0x19ffc8 vcvt.f32.s32 s14, s12 */
/* @0x19ffcc vdiv.f32 s12, s15, s14 */
/* @0x19ffd0 vcmpe.f32 s12, s13 */
/* @0x19ffd4 vmrs APSR_nzcv, fpscr */
/* @0x19ffd8 vmovpl.f32 s15, #3.000000e+01 */
/* @0x19ffdc vmovmi.f32 s14, #3.000000e+01 */
/* @0x19ffe0 vdivpl.f32 s15, s15, s14 */
/* @0x19ffe4 vdivmi.f32 s15, s14, s15 */
/* @0x19ffe8 vmov r0, s15 */
/* @0x19ffec pop {r4, pc} */
/* @0x19fff0 vmov.f32 s15, #1.000000e+00 */
/* @0x19fff4 vmov r0, s15 */
/* @0x19fff8 pop {r4, pc} */
/* @0x19fffc ldr r3, [pc, #0x28] */
/* @0x1a0000 ldr r0, [r4, r3] */
/* @0x1a0004 bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0x1a0008 vmov d7, r0, r1 */
/* @0x1a000c vcvt.s32.f64 s15, d7 */
/* @0x1a0010 vmov r0, s15 */
/* @0x1a0014 b 0x19ff9c <_Z12Speed_Factorv+0x30> */
/* @0x1a0018 svclo #0x99999a */
/* @0x1a001c .word 0x00251cd8 */
/* @0x1a0020 .word 0xffffbcd4 */
/* @0x1a0024 .word 0xffffbcd8 */
/* @0x1a0028 .word 0xffffeb1c */
/* @0x1a002c .word 0xffffbcdc */

/* ── FUNC 0x1a0030 · Eff_Create00() · size=44 · insn=11 */
/* @0x1a0030 push {r3, r4, r5, lr} */
/* @0x1a0034 ldr r5, [pc, #0x1c] */
/* @0x1a0038 ldr r5, [pc, r5] */
/* @0x1a003c sub r4, r5, #4 */
/* @0x1a0040 add r5, r5, #20 */
/* @0x1a0044 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a0048 str r0, [r4, #0x4]! */
/* @0x1a004c cmp r4, r5 */
/* @0x1a0050 bne 0x1a0044 <_Z12Eff_Create00v+0x14> */
/* @0x1a0054 pop {r3, r4, r5, pc} */
/* @0x1a0058 eoreq r0, r5, r8, lsr r7 */

/* ── FUNC 0x1a005c · Eff_Effect00(int, float, float, int, unsigned int) · size=1420 · insn=355 */
/* @0x1a005c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1a0060 vpush {d8, d9} */
/* @0x1a0064 sub sp, sp, #20 */
/* @0x1a0068 mov r4, r3 */
/* @0x1a006c mov r8, r1 */
/* @0x1a0070 mov r9, r0 */
/* @0x1a0074 mov r7, r2 */
/* @0x1a0078 bl 0x19ff6c <_Z12Speed_Factorv> */
/* @0x1a007c cmp r4, #0 */
/* @0x1a0080 ldr r3, [pc, #0x3a0] */
/* @0x1a0084 mov r1, #10 */
/* @0x1a0088 vmov s18, r0 */
/* @0x1a008c ldr r0, [pc, #0x398] */
/* @0x1a0090 add r0, pc, r0 */
/* @0x1a0094 beq 0x1a026c <_Z12Eff_Effect00iffij+0x210> */
/* @0x1a0098 cmp r4, #2 */
/* @0x1a009c beq 0x1a0438 <_Z12Eff_Effect00iffij+0x3dc> */
/* @0x1a00a0 ldr r4, [r0, r3] */
/* @0x1a00a4 mov r5, #0 */
/* @0x1a00a8 mov r6, #0 */
/* @0x1a00ac vmov.f32 s16, #1.700000e+01 */
/* @0x1a00b0 ldr r0, [r4, #0x8] */
/* @0x1a00b4 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a00b8 vldr s15, [pc, #856] */
/* @0x1a00bc movw r1, #0x999a */
/* @0x1a00c0 movt r1, #0x3e99 */
/* @0x1a00c4 ldr r0, [r4, #0x8] */
/* @0x1a00c8 mov r2, r1 */
/* @0x1a00cc str r5, [sp] */
/* @0x1a00d0 vmul.f32 s15, s18, s15 */
/* @0x1a00d4 vmov r3, s15 */
/* @0x1a00d8 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a00dc ldr r0, [r4, #0x8] */
/* @0x1a00e0 mov r1, r5 */
/* @0x1a00e4 mov r3, r5 */
/* @0x1a00e8 str r5, [sp] */
/* @0x1a00ec mov r2, #0 */
/* @0x1a00f0 str r6, [sp, #0x4] */
/* @0x1a00f4 movt r2, #0x43b4 */
/* @0x1a00f8 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb> */
/* @0x1a00fc ldr r0, [r4, #0x8] */
/* @0x1a0100 mov r1, r5 */
/* @0x1a0104 mov r3, r5 */
/* @0x1a0108 str r5, [sp] */
/* @0x1a010c mov r2, #0 */
/* @0x1a0110 movt r2, #0x43b4 */
/* @0x1a0114 bl 0x1a33b4 <_Z22ParticleType_Directioniffff> */
/* @0x1a0118 vmov.f32 s14, #4.000000e+00 */
/* @0x1a011c vldr s15, [pc, #760] */
/* @0x1a0120 ldr r0, [r4, #0x8] */
/* @0x1a0124 str r5, [sp] */
/* @0x1a0128 vmul.f32 s14, s18, s14 */
/* @0x1a012c vmul.f32 s15, s18, s15 */
/* @0x1a0130 vmov r1, s14 */
/* @0x1a0134 vmov r2, s14 */
/* @0x1a0138 vmov r3, s15 */
/* @0x1a013c bl 0x1a3368 <_Z18ParticleType_Speediffff> */
/* @0x1a0140 mov r2, r5 */
/* @0x1a0144 ldr r0, [r4, #0x8] */
/* @0x1a0148 movw r1, #0x999a */
/* @0x1a014c movt r1, #0x3f19 */
/* @0x1a0150 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a0154 vmov.f32 s15, #1.200000e+01 */
/* @0x1a0158 ldr r11, [r4, #0x8] */
/* @0x1a015c vdiv.f32 s15, s15, s18 */
/* @0x1a0160 vcvt.f64.f32 d6, s15 */
/* @0x1a0164 vmov r0, r1, d6 */
/* @0x1a0168 bl 0xb66e8 <lrint@plt> */
/* @0x1a016c vdiv.f32 s16, s16, s18 */
/* @0x1a0170 mov r10, r0 */
/* @0x1a0174 vcvt.f64.f32 d8, s16 */
/* @0x1a0178 vmov r0, r1, d8 */
/* @0x1a017c bl 0xb66e8 <lrint@plt> */
/* @0x1a0180 mov r1, r10 */
/* @0x1a0184 mov r2, r0 */
/* @0x1a0188 mov r0, r11 */
/* @0x1a018c bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a0190 ldr r2, [sp, #0x48] */
/* @0x1a0194 ldr r3, [r4, #0x8] */
/* @0x1a0198 mov r0, r9 */
/* @0x1a019c mov r1, r8 */
/* @0x1a01a0 str r2, [sp] */
/* @0x1a01a4 mov r2, #20 */
/* @0x1a01a8 str r2, [sp, #0x4] */
/* @0x1a01ac mov r2, r7 */
/* @0x1a01b0 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a01b4 ldr r0, [r4, #0xc] */
/* @0x1a01b8 mov r1, #10 */
/* @0x1a01bc bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a01c0 vldr s15, [pc, #616] */
/* @0x1a01c4 vmul.f32 s15, s18, s15 */
/* @0x1a01c8 movw r1, #0x999a */
/* @0x1a01cc movt r1, #0x3e99 */
/* @0x1a01d0 ldr r0, [r4, #0xc] */
/* @0x1a01d4 str r5, [sp] */
/* @0x1a01d8 mov r2, r1 */
/* @0x1a01dc vmov r3, s15 */
/* @0x1a01e0 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a01e4 mov r3, r5 */
/* @0x1a01e8 ldr r0, [r4, #0xc] */
/* @0x1a01ec mov r1, r5 */
/* @0x1a01f0 str r5, [sp] */
/* @0x1a01f4 mov r2, #0 */
/* @0x1a01f8 str r6, [sp, #0x4] */
/* @0x1a01fc movt r2, #0x43b4 */
/* @0x1a0200 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb> */
/* @0x1a0204 mov r2, r5 */
/* @0x1a0208 ldr r0, [r4, #0xc] */
/* @0x1a020c movw r1, #0xcccd */
/* @0x1a0210 movt r1, #0x3f4c */
/* @0x1a0214 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a0218 vmov r0, r1, d8 */
/* @0x1a021c ldr r10, [r4, #0xc] */
/* @0x1a0220 bl 0xb66e8 <lrint@plt> */
/* @0x1a0224 mov r5, r0 */
/* @0x1a0228 vmov r0, r1, d8 */
/* @0x1a022c bl 0xb66e8 <lrint@plt> */
/* @0x1a0230 mov r1, r5 */
/* @0x1a0234 mov r2, r0 */
/* @0x1a0238 mov r0, r10 */
/* @0x1a023c bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a0240 ldr r3, [r4, #0xc] */
/* @0x1a0244 str r6, [sp] */
/* @0x1a0248 mov r12, #1 */
/* @0x1a024c mov r0, r9 */
/* @0x1a0250 mov r1, r8 */
/* @0x1a0254 mov r2, r7 */
/* @0x1a0258 str r12, [sp, #0x4] */
/* @0x1a025c bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a0260 add sp, sp, #20 */
/* @0x1a0264 vpop {d8, d9} */
/* @0x1a0268 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1a026c ldr r5, [r0, r3] */
/* @0x1a0270 movw r10, #0xcccd */
/* @0x1a0274 movt r10, #0x3dcc */
/* @0x1a0278 mov r6, #0 */
/* @0x1a027c vmov.f32 s16, #1.500000e+01 */
/* @0x1a0280 ldr r0, [r5] */
/* @0x1a0284 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a0288 vldr s15, [pc, #400] */
/* @0x1a028c ldr r0, [r5] */
/* @0x1a0290 mov r1, r10 */
/* @0x1a0294 mov r2, r10 */
/* @0x1a0298 str r6, [sp] */
/* @0x1a029c vmul.f32 s15, s18, s15 */
/* @0x1a02a0 vmov r3, s15 */
/* @0x1a02a4 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a02a8 ldr r0, [r5] */
/* @0x1a02ac mov r1, r6 */
/* @0x1a02b0 mov r3, r6 */
/* @0x1a02b4 str r6, [sp] */
/* @0x1a02b8 mov r2, #0 */
/* @0x1a02bc str r4, [sp, #0x4] */
/* @0x1a02c0 movt r2, #0x43b4 */
/* @0x1a02c4 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb> */
/* @0x1a02c8 ldr r0, [r5] */
/* @0x1a02cc mov r1, r6 */
/* @0x1a02d0 mov r3, r6 */
/* @0x1a02d4 str r6, [sp] */
/* @0x1a02d8 mov r2, #0 */
/* @0x1a02dc movt r2, #0x43b4 */
/* @0x1a02e0 bl 0x1a33b4 <_Z22ParticleType_Directioniffff> */
/* @0x1a02e4 vldr s15, [pc, #312] */
/* @0x1a02e8 vmul.f32 s15, s18, s15 */
/* @0x1a02ec ldr r0, [r5] */
/* @0x1a02f0 str r6, [sp] */
/* @0x1a02f4 vadd.f32 s14, s18, s18 */
/* @0x1a02f8 vmov r3, s15 */
/* @0x1a02fc vmov r1, s14 */
/* @0x1a0300 vmov r2, s14 */
/* @0x1a0304 bl 0x1a3368 <_Z18ParticleType_Speediffff> */
/* @0x1a0308 mov r2, r6 */
/* @0x1a030c ldr r0, [r5] */
/* @0x1a0310 movw r1, #0x999a */
/* @0x1a0314 movt r1, #0x3f19 */
/* @0x1a0318 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a031c vmov.f32 s15, #1.000000e+01 */
/* @0x1a0320 ldr r3, [r5] */
/* @0x1a0324 str r3, [sp, #0xc] */
/* @0x1a0328 vdiv.f32 s15, s15, s18 */
/* @0x1a032c vcvt.f64.f32 d6, s15 */
/* @0x1a0330 vmov r0, r1, d6 */
/* @0x1a0334 bl 0xb66e8 <lrint@plt> */
/* @0x1a0338 vdiv.f32 s16, s16, s18 */
/* @0x1a033c mov r11, r0 */
/* @0x1a0340 vcvt.f64.f32 d8, s16 */
/* @0x1a0344 vmov r0, r1, d8 */
/* @0x1a0348 bl 0xb66e8 <lrint@plt> */
/* @0x1a034c ldr r3, [sp, #0xc] */
/* @0x1a0350 mov r1, r11 */
/* @0x1a0354 mov r2, r0 */
/* @0x1a0358 mov r0, r3 */
/* @0x1a035c bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a0360 ldr r2, [sp, #0x48] */
/* @0x1a0364 ldr r3, [r5] */
/* @0x1a0368 mov r0, r9 */
/* @0x1a036c mov r1, r8 */
/* @0x1a0370 str r2, [sp] */
/* @0x1a0374 mov r2, #20 */
/* @0x1a0378 str r2, [sp, #0x4] */
/* @0x1a037c mov r2, r7 */
/* @0x1a0380 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a0384 ldr r0, [r5, #0x4] */
/* @0x1a0388 mov r1, #10 */
/* @0x1a038c bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a0390 vmov s12, r10 */
/* @0x1a0394 mov r1, r10 */
/* @0x1a0398 ldr r0, [r5, #0x4] */
/* @0x1a039c vmul.f32 s12, s18, s12 */
/* @0x1a03a0 mov r2, r10 */
/* @0x1a03a4 str r6, [sp] */
/* @0x1a03a8 vmov r3, s12 */
/* @0x1a03ac bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a03b0 mov r3, r6 */
/* @0x1a03b4 ldr r0, [r5, #0x4] */
/* @0x1a03b8 mov r1, r6 */
/* @0x1a03bc str r6, [sp] */
/* @0x1a03c0 mov r2, #0 */
/* @0x1a03c4 str r4, [sp, #0x4] */
/* @0x1a03c8 movt r2, #0x43b4 */
/* @0x1a03cc bl 0x1a3400 <_Z24ParticleType_Orientationiffffb> */
/* @0x1a03d0 mov r2, r6 */
/* @0x1a03d4 ldr r0, [r5, #0x4] */
/* @0x1a03d8 movw r1, #0xcccd */
/* @0x1a03dc movt r1, #0x3f4c */
/* @0x1a03e0 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a03e4 vmov r0, r1, d8 */
/* @0x1a03e8 ldr r10, [r5, #0x4] */
/* @0x1a03ec bl 0xb66e8 <lrint@plt> */
/* @0x1a03f0 mov r6, r0 */
/* @0x1a03f4 vmov r0, r1, d8 */
/* @0x1a03f8 bl 0xb66e8 <lrint@plt> */
/* @0x1a03fc mov r1, r6 */
/* @0x1a0400 mov r2, r0 */
/* @0x1a0404 mov r0, r10 */
/* @0x1a0408 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a040c ldr r3, [r5, #0x4] */
/* @0x1a0410 str r4, [sp] */
/* @0x1a0414 b 0x1a0248 <_Z12Eff_Effect00iffij+0x1ec> */
/* @0x1a0418 stcllo p12, c12, [r12, #820] */
/* @0x1a041c cdplt p1, #0x3, c5, c8, c12, #0x7 */
/* @0x1a0420 stcllo p12, c12, [r12, #-820] */
/* @0x1a0424 stcllt p12, c12, [r12, #820] */
/* @0x1a0428 .word 0xffffeb20 */
/* @0x1a042c eoreq r1, r5, r0, asr #23 */
/* @0x1a0430 cdplo p12, #0x4, c12, c12, c13, #0x6 */
/* @0x1a0434 cdplt p12, #0x4, c12, c12, c13, #0x6 */
/* @0x1a0438 ldr r4, [r0, r3] */
/* @0x1a043c movw r10, #0xcccd */
/* @0x1a0440 movt r10, #0x3ecc */
/* @0x1a0444 mov r5, #0 */
/* @0x1a0448 mov r6, #0 */
/* @0x1a044c vmov.f32 s16, #2.000000e+01 */
/* @0x1a0450 ldr r0, [r4, #0x10] */
/* @0x1a0454 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a0458 vldr s15, [pc, #-48] */
/* @0x1a045c ldr r0, [r4, #0x10] */
/* @0x1a0460 mov r1, r10 */
/* @0x1a0464 mov r2, r10 */
/* @0x1a0468 str r5, [sp] */
/* @0x1a046c vmul.f32 s15, s18, s15 */
/* @0x1a0470 vmov r3, s15 */
/* @0x1a0474 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a0478 ldr r0, [r4, #0x10] */
/* @0x1a047c mov r1, r5 */
/* @0x1a0480 mov r3, r5 */
/* @0x1a0484 str r5, [sp] */
/* @0x1a0488 mov r2, #0 */
/* @0x1a048c str r6, [sp, #0x4] */
/* @0x1a0490 movt r2, #0x43b4 */
/* @0x1a0494 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb> */
/* @0x1a0498 ldr r0, [r4, #0x10] */
/* @0x1a049c mov r1, r5 */
/* @0x1a04a0 mov r3, r5 */
/* @0x1a04a4 str r5, [sp] */
/* @0x1a04a8 mov r2, #0 */
/* @0x1a04ac movt r2, #0x43b4 */
/* @0x1a04b0 bl 0x1a33b4 <_Z22ParticleType_Directioniffff> */
/* @0x1a04b4 vmov.f32 s14, #7.000000e+00 */
/* @0x1a04b8 vldr s15, [pc, #-140] */
/* @0x1a04bc ldr r0, [r4, #0x10] */
/* @0x1a04c0 str r5, [sp] */
/* @0x1a04c4 vmul.f32 s14, s18, s14 */
/* @0x1a04c8 vmul.f32 s15, s18, s15 */
/* @0x1a04cc vmov r1, s14 */
/* @0x1a04d0 vmov r2, s14 */
/* @0x1a04d4 vmov r3, s15 */
/* @0x1a04d8 bl 0x1a3368 <_Z18ParticleType_Speediffff> */
/* @0x1a04dc mov r2, r5 */
/* @0x1a04e0 ldr r0, [r4, #0x10] */
/* @0x1a04e4 movw r1, #0x999a */
/* @0x1a04e8 movt r1, #0x3f19 */
/* @0x1a04ec bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a04f0 vmov.f32 s15, #1.500000e+01 */
/* @0x1a04f4 ldr r3, [r4, #0x10] */
/* @0x1a04f8 str r3, [sp, #0xc] */
/* @0x1a04fc vdiv.f32 s15, s15, s18 */
/* @0x1a0500 vcvt.f64.f32 d6, s15 */
/* @0x1a0504 vmov r0, r1, d6 */
/* @0x1a0508 bl 0xb66e8 <lrint@plt> */
/* @0x1a050c vdiv.f32 s16, s16, s18 */
/* @0x1a0510 mov r11, r0 */
/* @0x1a0514 vcvt.f64.f32 d8, s16 */
/* @0x1a0518 vmov r0, r1, d8 */
/* @0x1a051c bl 0xb66e8 <lrint@plt> */
/* @0x1a0520 ldr r3, [sp, #0xc] */
/* @0x1a0524 mov r1, r11 */
/* @0x1a0528 mov r2, r0 */
/* @0x1a052c mov r0, r3 */
/* @0x1a0530 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a0534 ldr r2, [sp, #0x48] */
/* @0x1a0538 ldr r3, [r4, #0x10] */
/* @0x1a053c mov r0, r9 */
/* @0x1a0540 mov r1, r8 */
/* @0x1a0544 str r2, [sp] */
/* @0x1a0548 mov r2, #20 */
/* @0x1a054c str r2, [sp, #0x4] */
/* @0x1a0550 mov r2, r7 */
/* @0x1a0554 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a0558 ldr r0, [r4, #0x14] */
/* @0x1a055c mov r1, #10 */
/* @0x1a0560 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a0564 vmov s12, r10 */
/* @0x1a0568 mov r1, r10 */
/* @0x1a056c ldr r0, [r4, #0x14] */
/* @0x1a0570 vmul.f32 s12, s18, s12 */
/* @0x1a0574 mov r2, r10 */
/* @0x1a0578 str r5, [sp] */
/* @0x1a057c vmov r3, s12 */
/* @0x1a0580 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a0584 mov r3, r5 */
/* @0x1a0588 ldr r0, [r4, #0x14] */
/* @0x1a058c mov r1, r5 */
/* @0x1a0590 str r5, [sp] */
/* @0x1a0594 mov r2, #0 */
/* @0x1a0598 str r6, [sp, #0x4] */
/* @0x1a059c movt r2, #0x43b4 */
/* @0x1a05a0 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb> */
/* @0x1a05a4 mov r2, r5 */
/* @0x1a05a8 ldr r0, [r4, #0x14] */
/* @0x1a05ac movw r1, #0xcccd */
/* @0x1a05b0 movt r1, #0x3f4c */
/* @0x1a05b4 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a05b8 vmov r0, r1, d8 */
/* @0x1a05bc ldr r10, [r4, #0x14] */
/* @0x1a05c0 bl 0xb66e8 <lrint@plt> */
/* @0x1a05c4 mov r5, r0 */
/* @0x1a05c8 vmov r0, r1, d8 */
/* @0x1a05cc bl 0xb66e8 <lrint@plt> */
/* @0x1a05d0 mov r1, r5 */
/* @0x1a05d4 mov r2, r0 */
/* @0x1a05d8 mov r0, r10 */
/* @0x1a05dc bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a05e0 ldr r3, [r4, #0x14] */
/* @0x1a05e4 b 0x1a0244 <_Z12Eff_Effect00iffij+0x1e8> */

/* ── FUNC 0x1a05e8 · Eff_Create01() · size=44 · insn=11 */
/* @0x1a05e8 push {r4, lr} */
/* @0x1a05ec bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a05f0 ldr r4, [pc, #0x18] */
/* @0x1a05f4 ldr r4, [pc, r4] */
/* @0x1a05f8 str r0, [r4] */
/* @0x1a05fc bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a0600 str r0, [r4, #0x4] */
/* @0x1a0604 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a0608 str r0, [r4, #0x8] */
/* @0x1a060c pop {r4, pc} */
/* @0x1a0610 eoreq r0, r5, r0, lsl #3 */

/* ── FUNC 0x1a0614 · Eff_Effect01(int, float, float, int, unsigned int) · size=520 · insn=130 */
/* @0x1a0614 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1a0618 vpush {d8} */
/* @0x1a061c sub sp, sp, #12 */
/* @0x1a0620 mov r4, r3 */
/* @0x1a0624 mov r7, r1 */
/* @0x1a0628 mov r8, r0 */
/* @0x1a062c mov r6, r2 */
/* @0x1a0630 bl 0x19ff6c <_Z12Speed_Factorv> */
/* @0x1a0634 cmp r4, #0 */
/* @0x1a0638 ldr r12, [pc, #0x1d4] */
/* @0x1a063c mov r1, #6 */
/* @0x1a0640 ldr r3, [pc, #0x1d0] */
/* @0x1a0644 mov r5, #0 */
/* @0x1a0648 add r12, pc, r12 */
/* @0x1a064c vmov s16, r0 */
/* @0x1a0650 beq 0x1a0708 <_Z12Eff_Effect01iffij+0xf4> */
/* @0x1a0654 cmp r4, #2 */
/* @0x1a0658 ldr r4, [r12, r3] */
/* @0x1a065c beq 0x1a078c <_Z12Eff_Effect01iffij+0x178> */
/* @0x1a0660 ldr r0, [r4, #0x4] */
/* @0x1a0664 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a0668 mov r2, r5 */
/* @0x1a066c ldr r0, [r4, #0x4] */
/* @0x1a0670 mov r1, #1065353216 */
/* @0x1a0674 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a0678 vmov.f32 s15, #2.500000e-01 */
/* @0x1a067c mov r2, r5 */
/* @0x1a0680 mov r1, r5 */
/* @0x1a0684 ldr r0, [r4, #0x4] */
/* @0x1a0688 str r5, [sp] */
/* @0x1a068c vmul.f32 s15, s16, s15 */
/* @0x1a0690 vmov r3, s15 */
/* @0x1a0694 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a0698 vmov.f32 s15, #1.300000e+01 */
/* @0x1a069c ldr r9, [r4, #0x4] */
/* @0x1a06a0 vdiv.f32 s15, s15, s16 */
/* @0x1a06a4 vcvt.f64.f32 d6, s15 */
/* @0x1a06a8 vmov r0, r1, d6 */
/* @0x1a06ac bl 0xb66e8 <lrint@plt> */
/* @0x1a06b0 vmov.f32 s15, #1.500000e+01 */
/* @0x1a06b4 vdiv.f32 s16, s15, s16 */
/* @0x1a06b8 mov r5, r0 */
/* @0x1a06bc vcvt.f64.f32 d7, s16 */
/* @0x1a06c0 vmov r0, r1, d7 */
/* @0x1a06c4 bl 0xb66e8 <lrint@plt> */
/* @0x1a06c8 mov r1, r5 */
/* @0x1a06cc mov r2, r0 */
/* @0x1a06d0 mov r0, r9 */
/* @0x1a06d4 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a06d8 ldr r3, [r4, #0x4] */
/* @0x1a06dc ldr r2, [sp, #0x30] */
/* @0x1a06e0 mov r12, #1 */
/* @0x1a06e4 mov r0, r8 */
/* @0x1a06e8 mov r1, r7 */
/* @0x1a06ec str r12, [sp, #0x4] */
/* @0x1a06f0 str r2, [sp] */
/* @0x1a06f4 mov r2, r6 */
/* @0x1a06f8 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a06fc add sp, sp, #12 */
/* @0x1a0700 vpop {d8} */
/* @0x1a0704 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1a0708 ldr r4, [r12, r3] */
/* @0x1a070c ldr r0, [r4] */
/* @0x1a0710 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a0714 mov r2, r5 */
/* @0x1a0718 ldr r0, [r4] */
/* @0x1a071c mov r1, #1065353216 */
/* @0x1a0720 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a0724 vldr s15, [pc, #224] */
/* @0x1a0728 vmul.f32 s15, s16, s15 */
/* @0x1a072c mov r2, r5 */
/* @0x1a0730 mov r1, r5 */
/* @0x1a0734 ldr r0, [r4] */
/* @0x1a0738 str r5, [sp] */
/* @0x1a073c vmov r3, s15 */
/* @0x1a0740 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a0744 vmov.f32 s15, #1.000000e+01 */
/* @0x1a0748 ldr r9, [r4] */
/* @0x1a074c vdiv.f32 s15, s15, s16 */
/* @0x1a0750 vcvt.f64.f32 d6, s15 */
/* @0x1a0754 vmov r0, r1, d6 */
/* @0x1a0758 bl 0xb66e8 <lrint@plt> */
/* @0x1a075c vmov.f32 s15, #1.200000e+01 */
/* @0x1a0760 vdiv.f32 s16, s15, s16 */
/* @0x1a0764 mov r5, r0 */
/* @0x1a0768 vcvt.f64.f32 d7, s16 */
/* @0x1a076c vmov r0, r1, d7 */
/* @0x1a0770 bl 0xb66e8 <lrint@plt> */
/* @0x1a0774 mov r1, r5 */
/* @0x1a0778 mov r2, r0 */
/* @0x1a077c mov r0, r9 */
/* @0x1a0780 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a0784 ldr r3, [r4] */
/* @0x1a0788 b 0x1a06dc <_Z12Eff_Effect01iffij+0xc8> */
/* @0x1a078c ldr r0, [r4, #0x8] */
/* @0x1a0790 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a0794 mov r2, r5 */
/* @0x1a0798 ldr r0, [r4, #0x8] */
/* @0x1a079c mov r1, #1065353216 */
/* @0x1a07a0 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a07a4 vldr s15, [pc, #100] */
/* @0x1a07a8 vmul.f32 s15, s16, s15 */
/* @0x1a07ac mov r2, r5 */
/* @0x1a07b0 mov r1, r5 */
/* @0x1a07b4 ldr r0, [r4, #0x8] */
/* @0x1a07b8 str r5, [sp] */
/* @0x1a07bc vmov r3, s15 */
/* @0x1a07c0 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a07c4 vmov.f32 s15, #1.800000e+01 */
/* @0x1a07c8 ldr r9, [r4, #0x8] */
/* @0x1a07cc vdiv.f32 s15, s15, s16 */
/* @0x1a07d0 vcvt.f64.f32 d6, s15 */
/* @0x1a07d4 vmov r0, r1, d6 */
/* @0x1a07d8 bl 0xb66e8 <lrint@plt> */
/* @0x1a07dc vmov.f32 s15, #2.000000e+01 */
/* @0x1a07e0 vdiv.f32 s16, s15, s16 */
/* @0x1a07e4 mov r5, r0 */
/* @0x1a07e8 vcvt.f64.f32 d7, s16 */
/* @0x1a07ec vmov r0, r1, d7 */
/* @0x1a07f0 bl 0xb66e8 <lrint@plt> */
/* @0x1a07f4 mov r1, r5 */
/* @0x1a07f8 mov r2, r0 */
/* @0x1a07fc mov r0, r9 */
/* @0x1a0800 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a0804 ldr r3, [r4, #0x8] */
/* @0x1a0808 b 0x1a06dc <_Z12Eff_Effect01iffij+0xc8> */
/* @0x1a080c mrclo p9, #0x0, r9, c9, c10, #0x4 */
/* @0x1a0810 cdplo p12, #0xc, c12, c12, c13, #0x6 */
/* @0x1a0814 eoreq r1, r5, r8, lsl #12 */
/* @0x1a0818 .word 0xffffeb24 */

/* ── FUNC 0x1a081c · Eff_Create02() · size=44 · insn=11 */
/* @0x1a081c push {r4, lr} */
/* @0x1a0820 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a0824 ldr r4, [pc, #0x18] */
/* @0x1a0828 ldr r4, [pc, r4] */
/* @0x1a082c str r0, [r4] */
/* @0x1a0830 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a0834 str r0, [r4, #0x4] */
/* @0x1a0838 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a083c str r0, [r4, #0x8] */
/* @0x1a0840 pop {r4, pc} */
/* @0x1a0844 eoreq pc, r4, r0, asr pc */

/* ── FUNC 0x1a0848 · Eff_Effect02(int, float, float, int, unsigned int) · size=572 · insn=143 */
/* @0x1a0848 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1a084c vpush {d8} */
/* @0x1a0850 sub sp, sp, #12 */
/* @0x1a0854 mov r4, r3 */
/* @0x1a0858 mov r7, r1 */
/* @0x1a085c mov r8, r0 */
/* @0x1a0860 mov r6, r2 */
/* @0x1a0864 bl 0x19ff6c <_Z12Speed_Factorv> */
/* @0x1a0868 cmp r4, #0 */
/* @0x1a086c ldr r12, [pc, #0x208] */
/* @0x1a0870 mov r1, #6 */
/* @0x1a0874 ldr r3, [pc, #0x204] */
/* @0x1a0878 mov r5, #0 */
/* @0x1a087c add r12, pc, r12 */
/* @0x1a0880 vmov s16, r0 */
/* @0x1a0884 beq 0x1a094c <_Z12Eff_Effect02iffij+0x104> */
/* @0x1a0888 cmp r4, #2 */
/* @0x1a088c ldr r4, [r12, r3] */
/* @0x1a0890 beq 0x1a09e0 <_Z12Eff_Effect02iffij+0x198> */
/* @0x1a0894 ldr r0, [r4, #0x4] */
/* @0x1a0898 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a089c mov r2, r5 */
/* @0x1a08a0 ldr r0, [r4, #0x4] */
/* @0x1a08a4 mov r1, #1065353216 */
/* @0x1a08a8 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a08ac vldr s15, [pc, #444] */
/* @0x1a08b0 vmul.f32 s15, s16, s15 */
/* @0x1a08b4 mov r1, r5 */
/* @0x1a08b8 ldr r0, [r4, #0x4] */
/* @0x1a08bc mov r2, r5 */
/* @0x1a08c0 str r5, [sp] */
/* @0x1a08c4 vmov r3, s15 */
/* @0x1a08c8 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a08cc mov r2, #1056964608 */
/* @0x1a08d0 ldr r0, [r4, #0x4] */
/* @0x1a08d4 mov r1, #1065353216 */
/* @0x1a08d8 bl 0x1a3278 <_Z18ParticleType_Scaleiff> */
/* @0x1a08dc vmov.f32 s15, #1.300000e+01 */
/* @0x1a08e0 ldr r9, [r4, #0x4] */
/* @0x1a08e4 vdiv.f32 s15, s15, s16 */
/* @0x1a08e8 vcvt.f64.f32 d6, s15 */
/* @0x1a08ec vmov r0, r1, d6 */
/* @0x1a08f0 bl 0xb66e8 <lrint@plt> */
/* @0x1a08f4 vmov.f32 s15, #1.500000e+01 */
/* @0x1a08f8 vdiv.f32 s16, s15, s16 */
/* @0x1a08fc mov r5, r0 */
/* @0x1a0900 vcvt.f64.f32 d7, s16 */
/* @0x1a0904 vmov r0, r1, d7 */
/* @0x1a0908 bl 0xb66e8 <lrint@plt> */
/* @0x1a090c mov r1, r5 */
/* @0x1a0910 mov r2, r0 */
/* @0x1a0914 mov r0, r9 */
/* @0x1a0918 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a091c ldr r3, [r4, #0x4] */
/* @0x1a0920 ldr r2, [sp, #0x30] */
/* @0x1a0924 mov r12, #1 */
/* @0x1a0928 mov r0, r8 */
/* @0x1a092c mov r1, r7 */
/* @0x1a0930 str r12, [sp, #0x4] */
/* @0x1a0934 str r2, [sp] */
/* @0x1a0938 mov r2, r6 */
/* @0x1a093c bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a0940 add sp, sp, #12 */
/* @0x1a0944 vpop {d8} */
/* @0x1a0948 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1a094c ldr r4, [r12, r3] */
/* @0x1a0950 ldr r0, [r4] */
/* @0x1a0954 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a0958 mov r2, r5 */
/* @0x1a095c ldr r0, [r4] */
/* @0x1a0960 mov r1, #1065353216 */
/* @0x1a0964 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a0968 vldr s15, [pc, #260] */
/* @0x1a096c vmul.f32 s15, s16, s15 */
/* @0x1a0970 mov r1, r5 */
/* @0x1a0974 ldr r0, [r4] */
/* @0x1a0978 mov r2, r5 */
/* @0x1a097c str r5, [sp] */
/* @0x1a0980 vmov r3, s15 */
/* @0x1a0984 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a0988 mov r2, #1056964608 */
/* @0x1a098c ldr r0, [r4] */
/* @0x1a0990 mov r1, #1065353216 */
/* @0x1a0994 bl 0x1a3278 <_Z18ParticleType_Scaleiff> */
/* @0x1a0998 vmov.f32 s15, #1.000000e+01 */
/* @0x1a099c ldr r9, [r4] */
/* @0x1a09a0 vdiv.f32 s15, s15, s16 */
/* @0x1a09a4 vcvt.f64.f32 d6, s15 */
/* @0x1a09a8 vmov r0, r1, d6 */
/* @0x1a09ac bl 0xb66e8 <lrint@plt> */
/* @0x1a09b0 vmov.f32 s15, #1.200000e+01 */
/* @0x1a09b4 vdiv.f32 s16, s15, s16 */
/* @0x1a09b8 mov r5, r0 */
/* @0x1a09bc vcvt.f64.f32 d7, s16 */
/* @0x1a09c0 vmov r0, r1, d7 */
/* @0x1a09c4 bl 0xb66e8 <lrint@plt> */
/* @0x1a09c8 mov r1, r5 */
/* @0x1a09cc mov r2, r0 */
/* @0x1a09d0 mov r0, r9 */
/* @0x1a09d4 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a09d8 ldr r3, [r4] */
/* @0x1a09dc b 0x1a0920 <_Z12Eff_Effect02iffij+0xd8> */
/* @0x1a09e0 ldr r0, [r4, #0x8] */
/* @0x1a09e4 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a09e8 mov r2, r5 */
/* @0x1a09ec ldr r0, [r4, #0x8] */
/* @0x1a09f0 mov r1, #1065353216 */
/* @0x1a09f4 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a09f8 vldr s15, [pc, #120] */
/* @0x1a09fc vmul.f32 s15, s16, s15 */
/* @0x1a0a00 mov r1, r5 */
/* @0x1a0a04 ldr r0, [r4, #0x8] */
/* @0x1a0a08 mov r2, r5 */
/* @0x1a0a0c str r5, [sp] */
/* @0x1a0a10 vmov r3, s15 */
/* @0x1a0a14 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a0a18 mov r2, #1056964608 */
/* @0x1a0a1c ldr r0, [r4, #0x8] */
/* @0x1a0a20 mov r1, #1065353216 */
/* @0x1a0a24 bl 0x1a3278 <_Z18ParticleType_Scaleiff> */
/* @0x1a0a28 vmov.f32 s15, #1.800000e+01 */
/* @0x1a0a2c ldr r9, [r4, #0x8] */
/* @0x1a0a30 vdiv.f32 s15, s15, s16 */
/* @0x1a0a34 vcvt.f64.f32 d6, s15 */
/* @0x1a0a38 vmov r0, r1, d6 */
/* @0x1a0a3c bl 0xb66e8 <lrint@plt> */
/* @0x1a0a40 vmov.f32 s15, #2.000000e+01 */
/* @0x1a0a44 vdiv.f32 s16, s15, s16 */
/* @0x1a0a48 mov r5, r0 */
/* @0x1a0a4c vcvt.f64.f32 d7, s16 */
/* @0x1a0a50 vmov r0, r1, d7 */
/* @0x1a0a54 bl 0xb66e8 <lrint@plt> */
/* @0x1a0a58 mov r1, r5 */
/* @0x1a0a5c mov r2, r0 */
/* @0x1a0a60 mov r0, r9 */
/* @0x1a0a64 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a0a68 ldr r3, [r4, #0x8] */
/* @0x1a0a6c b 0x1a0920 <_Z12Eff_Effect02iffij+0xd8> */
/* @0x1a0a70 mrclo p3, #0x5, r3, c3, c3, #0x1 */
/* @0x1a0a74 cdplo p12, #0x4, c12, c12, c13, #0x6 */
/* @0x1a0a78 svclo #0x19999a */
/* @0x1a0a7c .word 0x002513d4 */
/* @0x1a0a80 .word 0xffffeb28 */

/* ── FUNC 0x1a0a84 · Eff_Create03() · size=44 · insn=11 */
/* @0x1a0a84 push {r4, lr} */
/* @0x1a0a88 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a0a8c ldr r4, [pc, #0x18] */
/* @0x1a0a90 ldr r4, [pc, r4] */
/* @0x1a0a94 str r0, [r4] */
/* @0x1a0a98 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a0a9c str r0, [r4, #0x4] */
/* @0x1a0aa0 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a0aa4 str r0, [r4, #0x8] */
/* @0x1a0aa8 pop {r4, pc} */
/* @0x1a0aac eoreq pc, r4, r12, ror #25 */

/* ── FUNC 0x1a0ab0 · Eff_Effect03(int, float, float, int, unsigned int) · size=904 · insn=226 */
/* @0x1a0ab0 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1a0ab4 vpush {d8} */
/* @0x1a0ab8 sub sp, sp, #12 */
/* @0x1a0abc mov r4, r3 */
/* @0x1a0ac0 mov r7, r1 */
/* @0x1a0ac4 mov r8, r0 */
/* @0x1a0ac8 mov r6, r2 */
/* @0x1a0acc bl 0x19ff6c <_Z12Speed_Factorv> */
/* @0x1a0ad0 cmp r4, #0 */
/* @0x1a0ad4 ldr r12, [pc, #0x354] */
/* @0x1a0ad8 mov r1, #8 */
/* @0x1a0adc ldr r3, [pc, #0x350] */
/* @0x1a0ae0 add r12, pc, r12 */
/* @0x1a0ae4 vmov s16, r0 */
/* @0x1a0ae8 beq 0x1a0c08 <_Z12Eff_Effect03iffij+0x158> */
/* @0x1a0aec cmp r4, #2 */
/* @0x1a0af0 ldr r4, [r12, r3] */
/* @0x1a0af4 mov r5, #0 */
/* @0x1a0af8 ldr r0, [r4, #0x4] */
/* @0x1a0afc beq 0x1a0d18 <_Z12Eff_Effect03iffij+0x268> */
/* @0x1a0b00 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a0b04 ldr r0, [r4, #0x4] */
/* @0x1a0b08 mov r3, r5 */
/* @0x1a0b0c str r5, [sp] */
/* @0x1a0b10 movw r1, #0xcccd */
/* @0x1a0b14 movw r2, #0xcccd */
/* @0x1a0b18 movt r1, #0x3dcc */
/* @0x1a0b1c movt r2, #0x3e4c */
/* @0x1a0b20 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a0b24 vmov.f32 s14, #5.000000e-01 */
/* @0x1a0b28 ldr r0, [r4, #0x4] */
/* @0x1a0b2c mov r3, r5 */
/* @0x1a0b30 str r5, [sp] */
/* @0x1a0b34 vmov.f32 s15, #6.000000e+00 */
/* @0x1a0b38 vmul.f32 s14, s16, s14 */
/* @0x1a0b3c vmul.f32 s15, s16, s15 */
/* @0x1a0b40 vmov r1, s14 */
/* @0x1a0b44 vmov r2, s15 */
/* @0x1a0b48 bl 0x1a3368 <_Z18ParticleType_Speediffff> */
/* @0x1a0b4c mov r3, r5 */
/* @0x1a0b50 ldr r0, [r4, #0x4] */
/* @0x1a0b54 mov r1, r5 */
/* @0x1a0b58 str r5, [sp] */
/* @0x1a0b5c mov r2, #0 */
/* @0x1a0b60 movt r2, #0x43b4 */
/* @0x1a0b64 bl 0x1a33b4 <_Z22ParticleType_Directioniffff> */
/* @0x1a0b68 ldr r0, [r4, #0x4] */
/* @0x1a0b6c mov r1, #1065353216 */
/* @0x1a0b70 movw r2, #0xcccd */
/* @0x1a0b74 movt r2, #0x3ecc */
/* @0x1a0b78 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a0b7c vmov.f32 s15, #2.000000e+01 */
/* @0x1a0b80 ldr r9, [r4, #0x4] */
/* @0x1a0b84 vdiv.f32 s15, s15, s16 */
/* @0x1a0b88 vcvt.f64.f32 d6, s15 */
/* @0x1a0b8c vmov r0, r1, d6 */
/* @0x1a0b90 bl 0xb66e8 <lrint@plt> */
/* @0x1a0b94 vmov.f32 s15, #3.000000e+01 */
/* @0x1a0b98 vdiv.f32 s15, s15, s16 */
/* @0x1a0b9c mov r5, r0 */
/* @0x1a0ba0 vcvt.f64.f32 d6, s15 */
/* @0x1a0ba4 vmov r0, r1, d6 */
/* @0x1a0ba8 bl 0xb66e8 <lrint@plt> */
/* @0x1a0bac mov r1, r5 */
/* @0x1a0bb0 mov r2, r0 */
/* @0x1a0bb4 mov r0, r9 */
/* @0x1a0bb8 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a0bbc vldr s15, [pc, #604] */
/* @0x1a0bc0 vmul.f32 s15, s16, s15 */
/* @0x1a0bc4 ldr r0, [r4, #0x4] */
/* @0x1a0bc8 mov r2, #0 */
/* @0x1a0bcc movt r2, #0x4387 */
/* @0x1a0bd0 vmov r1, s15 */
/* @0x1a0bd4 bl 0x1a3454 <_Z20ParticleType_Gravityiff> */
/* @0x1a0bd8 ldr r2, [sp, #0x30] */
/* @0x1a0bdc ldr r3, [r4, #0x4] */
/* @0x1a0be0 mov r12, #150 */
/* @0x1a0be4 mov r0, r8 */
/* @0x1a0be8 mov r1, r7 */
/* @0x1a0bec str r2, [sp] */
/* @0x1a0bf0 mov r2, r6 */
/* @0x1a0bf4 str r12, [sp, #0x4] */
/* @0x1a0bf8 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a0bfc add sp, sp, #12 */
/* @0x1a0c00 vpop {d8} */
/* @0x1a0c04 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1a0c08 ldr r4, [r12, r3] */
/* @0x1a0c0c mov r5, #0 */
/* @0x1a0c10 vldr s17, [pc, #524] */
/* @0x1a0c14 ldr r0, [r4, #0x4] */
/* @0x1a0c18 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a0c1c ldr r0, [r4, #0x4] */
/* @0x1a0c20 vmov r1, s17 */
/* @0x1a0c24 mov r3, r5 */
/* @0x1a0c28 str r5, [sp] */
/* @0x1a0c2c movw r2, #0xcccd */
/* @0x1a0c30 movt r2, #0x3e4c */
/* @0x1a0c34 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a0c38 vmov.f32 s14, #5.000000e-01 */
/* @0x1a0c3c ldr r0, [r4, #0x4] */
/* @0x1a0c40 mov r3, r5 */
/* @0x1a0c44 str r5, [sp] */
/* @0x1a0c48 vmov.f32 s15, #3.000000e+00 */
/* @0x1a0c4c vmul.f32 s14, s16, s14 */
/* @0x1a0c50 vmul.f32 s15, s16, s15 */
/* @0x1a0c54 vmov r1, s14 */
/* @0x1a0c58 vmov r2, s15 */
/* @0x1a0c5c bl 0x1a3368 <_Z18ParticleType_Speediffff> */
/* @0x1a0c60 mov r3, r5 */
/* @0x1a0c64 ldr r0, [r4, #0x4] */
/* @0x1a0c68 mov r1, r5 */
/* @0x1a0c6c str r5, [sp] */
/* @0x1a0c70 mov r2, #0 */
/* @0x1a0c74 movt r2, #0x43b4 */
/* @0x1a0c78 bl 0x1a33b4 <_Z22ParticleType_Directioniffff> */
/* @0x1a0c7c ldr r0, [r4, #0x4] */
/* @0x1a0c80 mov r1, #1065353216 */
/* @0x1a0c84 movw r2, #0xcccd */
/* @0x1a0c88 movt r2, #0x3ecc */
/* @0x1a0c8c bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a0c90 vmov.f32 s15, #1.500000e+01 */
/* @0x1a0c94 ldr r9, [r4, #0x4] */
/* @0x1a0c98 vdiv.f32 s15, s15, s16 */
/* @0x1a0c9c vcvt.f64.f32 d6, s15 */
/* @0x1a0ca0 vmov r0, r1, d6 */
/* @0x1a0ca4 bl 0xb66e8 <lrint@plt> */
/* @0x1a0ca8 vmov.f32 s15, #2.500000e+01 */
/* @0x1a0cac vdiv.f32 s15, s15, s16 */
/* @0x1a0cb0 mov r5, r0 */
/* @0x1a0cb4 vcvt.f64.f32 d6, s15 */
/* @0x1a0cb8 vmov r0, r1, d6 */
/* @0x1a0cbc bl 0xb66e8 <lrint@plt> */
/* @0x1a0cc0 mov r1, r5 */
/* @0x1a0cc4 mov r2, r0 */
/* @0x1a0cc8 mov r0, r9 */
/* @0x1a0ccc bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a0cd0 vmul.f32 s17, s16, s17 */
/* @0x1a0cd4 ldr r0, [r4, #0x4] */
/* @0x1a0cd8 mov r2, #0 */
/* @0x1a0cdc movt r2, #0x4387 */
/* @0x1a0ce0 vmov r1, s17 */
/* @0x1a0ce4 bl 0x1a3454 <_Z20ParticleType_Gravityiff> */
/* @0x1a0ce8 ldr r2, [sp, #0x30] */
/* @0x1a0cec ldr r3, [r4, #0x4] */
/* @0x1a0cf0 mov r12, #75 */
/* @0x1a0cf4 mov r0, r8 */
/* @0x1a0cf8 mov r1, r7 */
/* @0x1a0cfc str r2, [sp] */
/* @0x1a0d00 mov r2, r6 */
/* @0x1a0d04 str r12, [sp, #0x4] */
/* @0x1a0d08 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a0d0c add sp, sp, #12 */
/* @0x1a0d10 vpop {d8} */
/* @0x1a0d14 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1a0d18 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a0d1c ldr r0, [r4, #0x4] */
/* @0x1a0d20 mov r3, r5 */
/* @0x1a0d24 str r5, [sp] */
/* @0x1a0d28 movw r1, #0xcccd */
/* @0x1a0d2c movw r2, #0xcccd */
/* @0x1a0d30 movt r1, #0x3dcc */
/* @0x1a0d34 movt r2, #0x3e4c */
/* @0x1a0d38 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a0d3c vmov.f32 s14, #5.000000e-01 */
/* @0x1a0d40 ldr r0, [r4, #0x4] */
/* @0x1a0d44 mov r3, r5 */
/* @0x1a0d48 str r5, [sp] */
/* @0x1a0d4c vmov.f32 s15, #8.000000e+00 */
/* @0x1a0d50 vmul.f32 s14, s16, s14 */
/* @0x1a0d54 vmul.f32 s15, s16, s15 */
/* @0x1a0d58 vmov r1, s14 */
/* @0x1a0d5c vmov r2, s15 */
/* @0x1a0d60 bl 0x1a3368 <_Z18ParticleType_Speediffff> */
/* @0x1a0d64 mov r3, r5 */
/* @0x1a0d68 ldr r0, [r4, #0x4] */
/* @0x1a0d6c mov r1, r5 */
/* @0x1a0d70 str r5, [sp] */
/* @0x1a0d74 mov r2, #0 */
/* @0x1a0d78 movt r2, #0x43b4 */
/* @0x1a0d7c bl 0x1a33b4 <_Z22ParticleType_Directioniffff> */
/* @0x1a0d80 ldr r0, [r4, #0x4] */
/* @0x1a0d84 mov r1, #1065353216 */
/* @0x1a0d88 movw r2, #0xcccd */
/* @0x1a0d8c movt r2, #0x3ecc */
/* @0x1a0d90 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a0d94 vmov.f32 s15, #3.000000e+01 */
/* @0x1a0d98 ldr r9, [r4, #0x4] */
/* @0x1a0d9c vdiv.f32 s15, s15, s16 */
/* @0x1a0da0 vcvt.f64.f32 d6, s15 */
/* @0x1a0da4 vmov r0, r1, d6 */
/* @0x1a0da8 bl 0xb66e8 <lrint@plt> */
/* @0x1a0dac vldr s15, [pc, #116] */
/* @0x1a0db0 vdiv.f32 s15, s15, s16 */
/* @0x1a0db4 mov r5, r0 */
/* @0x1a0db8 vcvt.f64.f32 d6, s15 */
/* @0x1a0dbc vmov r0, r1, d6 */
/* @0x1a0dc0 bl 0xb66e8 <lrint@plt> */
/* @0x1a0dc4 mov r1, r5 */
/* @0x1a0dc8 mov r2, r0 */
/* @0x1a0dcc mov r0, r9 */
/* @0x1a0dd0 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a0dd4 vldr s15, [pc, #80] */
/* @0x1a0dd8 vmul.f32 s15, s16, s15 */
/* @0x1a0ddc ldr r0, [r4, #0x4] */
/* @0x1a0de0 mov r2, #0 */
/* @0x1a0de4 movt r2, #0x4387 */
/* @0x1a0de8 vmov r1, s15 */
/* @0x1a0dec bl 0x1a3454 <_Z20ParticleType_Gravityiff> */
/* @0x1a0df0 ldr r2, [sp, #0x30] */
/* @0x1a0df4 ldr r3, [r4, #0x4] */
/* @0x1a0df8 mov r12, #250 */
/* @0x1a0dfc mov r0, r8 */
/* @0x1a0e00 mov r1, r7 */
/* @0x1a0e04 str r2, [sp] */
/* @0x1a0e08 mov r2, r6 */
/* @0x1a0e0c str r12, [sp, #0x4] */
/* @0x1a0e10 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a0e14 add sp, sp, #12 */
/* @0x1a0e18 vpop {d8} */
/* @0x1a0e1c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1a0e20 mrclo p9, #0x0, r9, c9, c10, #0x4 */
/* @0x1a0e24 stcllo p12, c12, [r12, #820] */
/* @0x1a0e28 eormi r0, r0, #0 */
/* @0x1a0e2c mcrlo p4, #0x1, r1, c14, c11, #0x3 */
/* @0x1a0e30 eoreq r1, r5, r0, ror r1 */
/* @0x1a0e34 .word 0xffffeb2c */

/* ── FUNC 0x1a0e38 · Eff_Create04() · size=44 · insn=11 */
/* @0x1a0e38 push {r4, lr} */
/* @0x1a0e3c bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a0e40 ldr r4, [pc, #0x18] */
/* @0x1a0e44 ldr r4, [pc, r4] */
/* @0x1a0e48 str r0, [r4] */
/* @0x1a0e4c bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a0e50 str r0, [r4, #0x4] */
/* @0x1a0e54 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a0e58 str r0, [r4, #0x8] */
/* @0x1a0e5c pop {r4, pc} */
/* @0x1a0e60 eoreq pc, r4, r12, lsr r9 */

/* ── FUNC 0x1a0e64 · Eff_Effect04(int, float, float, int, unsigned int) · size=772 · insn=193 */
/* @0x1a0e64 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1a0e68 vpush {d8, d9} */
/* @0x1a0e6c sub sp, sp, #8 */
/* @0x1a0e70 mov r4, r3 */
/* @0x1a0e74 vmov s19, r1 */
/* @0x1a0e78 mov r6, r0 */
/* @0x1a0e7c ldr r7, [sp, #0x38] */
/* @0x1a0e80 vmov s18, r2 */
/* @0x1a0e84 bl 0x19ff6c <_Z12Speed_Factorv> */
/* @0x1a0e88 cmp r4, #0 */
/* @0x1a0e8c ldr r3, [pc, #0x2cc] */
/* @0x1a0e90 mov r1, #10 */
/* @0x1a0e94 mov r9, #0 */
/* @0x1a0e98 vmov s16, r0 */
/* @0x1a0e9c ldr r0, [pc, #0x2c0] */
/* @0x1a0ea0 add r0, pc, r0 */
/* @0x1a0ea4 beq 0x1a0f94 <_Z12Eff_Effect04iffij+0x130> */
/* @0x1a0ea8 cmp r4, #2 */
/* @0x1a0eac beq 0x1a1078 <_Z12Eff_Effect04iffij+0x214> */
/* @0x1a0eb0 ldr r5, [r0, r3] */
/* @0x1a0eb4 mov r4, #11 */
/* @0x1a0eb8 mov r8, #1 */
/* @0x1a0ebc ldr r0, [r5, #0x4] */
/* @0x1a0ec0 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a0ec4 vldr s15, [pc, #652] */
/* @0x1a0ec8 vmul.f32 s15, s16, s15 */
/* @0x1a0ecc ldr r0, [r5, #0x4] */
/* @0x1a0ed0 movw r1, #0xcccd */
/* @0x1a0ed4 str r9, [sp] */
/* @0x1a0ed8 movt r1, #0x3ecc */
/* @0x1a0edc movw r2, #0x3333 */
/* @0x1a0ee0 movt r2, #0x3f33 */
/* @0x1a0ee4 vmov r3, s15 */
/* @0x1a0ee8 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a0eec mov r2, r9 */
/* @0x1a0ef0 ldr r0, [r5, #0x4] */
/* @0x1a0ef4 movw r1, #0xcccd */
/* @0x1a0ef8 movt r1, #0x3ecc */
/* @0x1a0efc bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a0f00 vmov.f32 s15, #3.000000e+01 */
/* @0x1a0f04 ldr r10, [r5, #0x4] */
/* @0x1a0f08 vdiv.f32 s16, s15, s16 */
/* @0x1a0f0c vcvt.f64.f32 d8, s16 */
/* @0x1a0f10 vmov r0, r1, d8 */
/* @0x1a0f14 bl 0xb66e8 <lrint@plt> */
/* @0x1a0f18 mov r9, r0 */
/* @0x1a0f1c vmov r0, r1, d8 */
/* @0x1a0f20 bl 0xb66e8 <lrint@plt> */
/* @0x1a0f24 mov r1, r9 */
/* @0x1a0f28 vmov.f32 s17, #1.500000e+01 */
/* @0x1a0f2c mov r2, r0 */
/* @0x1a0f30 mov r0, r10 */
/* @0x1a0f34 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a0f38 vsub.f32 s19, s19, s17 */
/* @0x1a0f3c mov r0, #30 */
/* @0x1a0f40 bl 0xc4600 <_Z8YYRandomi> */
/* @0x1a0f44 vmov s15, r0 */
/* @0x1a0f48 mov r0, #30 */
/* @0x1a0f4c vcvt.f32.u32 s16, s15 */
/* @0x1a0f50 bl 0xc4600 <_Z8YYRandomi> */
/* @0x1a0f54 ldr r3, [r5, #0x4] */
/* @0x1a0f58 stm sp, {r7, r8} */
/* @0x1a0f5c vsub.f32 s14, s18, s17 */
/* @0x1a0f60 vadd.f32 s16, s19, s16 */
/* @0x1a0f64 vmov r1, s16 */
/* @0x1a0f68 vmov s13, r0 */
/* @0x1a0f6c mov r0, r6 */
/* @0x1a0f70 vcvt.f32.u32 s15, s13 */
/* @0x1a0f74 vadd.f32 s15, s14, s15 */
/* @0x1a0f78 vmov r2, s15 */
/* @0x1a0f7c bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a0f80 subs r4, r4, #1 */
/* @0x1a0f84 bne 0x1a0f3c <_Z12Eff_Effect04iffij+0xd8> */
/* @0x1a0f88 add sp, sp, #8 */
/* @0x1a0f8c vpop {d8, d9} */
/* @0x1a0f90 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1a0f94 ldr r5, [r0, r3] */
/* @0x1a0f98 mov r4, #6 */
/* @0x1a0f9c mov r8, #1 */
/* @0x1a0fa0 ldr r0, [r5] */
/* @0x1a0fa4 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a0fa8 vldr s15, [pc, #424] */
/* @0x1a0fac vmul.f32 s15, s16, s15 */
/* @0x1a0fb0 ldr r0, [r5] */
/* @0x1a0fb4 movw r1, #0xcccd */
/* @0x1a0fb8 str r9, [sp] */
/* @0x1a0fbc movt r1, #0x3e4c */
/* @0x1a0fc0 movw r2, #0xcccd */
/* @0x1a0fc4 movt r2, #0x3ecc */
/* @0x1a0fc8 vmov r3, s15 */
/* @0x1a0fcc bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a0fd0 mov r2, r9 */
/* @0x1a0fd4 ldr r0, [r5] */
/* @0x1a0fd8 movw r1, #0xcccd */
/* @0x1a0fdc movt r1, #0x3ecc */
/* @0x1a0fe0 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a0fe4 vmov.f32 s15, #2.500000e+01 */
/* @0x1a0fe8 ldr r10, [r5] */
/* @0x1a0fec vdiv.f32 s16, s15, s16 */
/* @0x1a0ff0 vcvt.f64.f32 d8, s16 */
/* @0x1a0ff4 vmov r0, r1, d8 */
/* @0x1a0ff8 bl 0xb66e8 <lrint@plt> */
/* @0x1a0ffc mov r9, r0 */
/* @0x1a1000 vmov r0, r1, d8 */
/* @0x1a1004 bl 0xb66e8 <lrint@plt> */
/* @0x1a1008 mov r1, r9 */
/* @0x1a100c vmov.f32 s17, #5.000000e+00 */
/* @0x1a1010 mov r2, r0 */
/* @0x1a1014 mov r0, r10 */
/* @0x1a1018 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a101c vsub.f32 s19, s19, s17 */
/* @0x1a1020 mov r0, #10 */
/* @0x1a1024 bl 0xc4600 <_Z8YYRandomi> */
/* @0x1a1028 vmov s13, r0 */
/* @0x1a102c mov r0, #10 */
/* @0x1a1030 vcvt.f32.u32 s16, s13 */
/* @0x1a1034 bl 0xc4600 <_Z8YYRandomi> */
/* @0x1a1038 ldr r3, [r5] */
/* @0x1a103c stm sp, {r7, r8} */
/* @0x1a1040 vsub.f32 s14, s18, s17 */
/* @0x1a1044 vadd.f32 s16, s19, s16 */
/* @0x1a1048 vmov r1, s16 */
/* @0x1a104c vmov s13, r0 */
/* @0x1a1050 mov r0, r6 */
/* @0x1a1054 vcvt.f32.u32 s15, s13 */
/* @0x1a1058 vadd.f32 s15, s14, s15 */
/* @0x1a105c vmov r2, s15 */
/* @0x1a1060 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a1064 subs r4, r4, #1 */
/* @0x1a1068 bne 0x1a1020 <_Z12Eff_Effect04iffij+0x1bc> */
/* @0x1a106c add sp, sp, #8 */
/* @0x1a1070 vpop {d8, d9} */
/* @0x1a1074 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1a1078 ldr r5, [r0, r3] */
/* @0x1a107c mov r4, #16 */
/* @0x1a1080 mov r8, #1 */
/* @0x1a1084 ldr r0, [r5, #0x8] */
/* @0x1a1088 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a108c vldr s15, [pc, #196] */
/* @0x1a1090 vmul.f32 s15, s16, s15 */
/* @0x1a1094 ldr r0, [r5, #0x8] */
/* @0x1a1098 mov r2, #1065353216 */
/* @0x1a109c str r9, [sp] */
/* @0x1a10a0 movw r1, #0xcccd */
/* @0x1a10a4 movt r1, #0x3ecc */
/* @0x1a10a8 vmov r3, s15 */
/* @0x1a10ac bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a10b0 mov r2, r9 */
/* @0x1a10b4 ldr r0, [r5, #0x8] */
/* @0x1a10b8 movw r1, #0xcccd */
/* @0x1a10bc movt r1, #0x3ecc */
/* @0x1a10c0 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a10c4 vldr s15, [pc, #144] */
/* @0x1a10c8 vdiv.f32 s16, s15, s16 */
/* @0x1a10cc ldr r10, [r5, #0x8] */
/* @0x1a10d0 vcvt.f64.f32 d8, s16 */
/* @0x1a10d4 vmov r0, r1, d8 */
/* @0x1a10d8 bl 0xb66e8 <lrint@plt> */
/* @0x1a10dc mov r9, r0 */
/* @0x1a10e0 vmov r0, r1, d8 */
/* @0x1a10e4 bl 0xb66e8 <lrint@plt> */
/* @0x1a10e8 mov r1, r9 */
/* @0x1a10ec vmov.f32 s17, #3.000000e+01 */
/* @0x1a10f0 mov r2, r0 */
/* @0x1a10f4 mov r0, r10 */
/* @0x1a10f8 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a10fc vsub.f32 s19, s19, s17 */
/* @0x1a1100 mov r0, #60 */
/* @0x1a1104 bl 0xc4600 <_Z8YYRandomi> */
/* @0x1a1108 vmov s15, r0 */
/* @0x1a110c mov r0, #60 */
/* @0x1a1110 vcvt.f32.u32 s16, s15 */
/* @0x1a1114 bl 0xc4600 <_Z8YYRandomi> */
/* @0x1a1118 ldr r3, [r5, #0x8] */
/* @0x1a111c stm sp, {r7, r8} */
/* @0x1a1120 vsub.f32 s14, s18, s17 */
/* @0x1a1124 vadd.f32 s16, s19, s16 */
/* @0x1a1128 vmov r1, s16 */
/* @0x1a112c vmov s13, r0 */
/* @0x1a1130 mov r0, r6 */
/* @0x1a1134 vcvt.f32.u32 s15, s13 */
/* @0x1a1138 vadd.f32 s15, s14, s15 */
/* @0x1a113c vmov r2, s15 */
/* @0x1a1140 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a1144 subs r4, r4, #1 */
/* @0x1a1148 bne 0x1a1100 <_Z12Eff_Effect04iffij+0x29c> */
/* @0x1a114c add sp, sp, #8 */
/* @0x1a1150 vpop {d8, d9} */
/* @0x1a1154 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1a1158 stclt p7, c13, [r3], #-40 */
/* @0x1a115c submi r0, r8, #0 */
/* @0x1a1160 .word 0xffffeb30 */
/* @0x1a1164 .word 0x00250db0 */

/* ── FUNC 0x1a1168 · Eff_Create05() · size=44 · insn=11 */
/* @0x1a1168 push {r4, lr} */
/* @0x1a116c bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a1170 ldr r4, [pc, #0x18] */
/* @0x1a1174 ldr r4, [pc, r4] */
/* @0x1a1178 str r0, [r4] */
/* @0x1a117c bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a1180 str r0, [r4, #0x4] */
/* @0x1a1184 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a1188 str r0, [r4, #0x8] */
/* @0x1a118c pop {r4, pc} */
/* @0x1a1190 eoreq pc, r4, r0, lsl r6 */

/* ── FUNC 0x1a1194 · Eff_Effect05(int, float, float, int, unsigned int) · size=976 · insn=244 */
/* @0x1a1194 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1a1198 vpush {d8, d9} */
/* @0x1a119c sub sp, sp, #8 */
/* @0x1a11a0 mov r4, r3 */
/* @0x1a11a4 vmov s19, r1 */
/* @0x1a11a8 mov r6, r0 */
/* @0x1a11ac ldr r7, [sp, #0x38] */
/* @0x1a11b0 vmov s18, r2 */
/* @0x1a11b4 bl 0x19ff6c <_Z12Speed_Factorv> */
/* @0x1a11b8 cmp r4, #0 */
/* @0x1a11bc ldr r3, [pc, #0x398] */
/* @0x1a11c0 mov r1, #10 */
/* @0x1a11c4 mov r9, #0 */
/* @0x1a11c8 vmov s16, r0 */
/* @0x1a11cc ldr r0, [pc, #0x38c] */
/* @0x1a11d0 add r0, pc, r0 */
/* @0x1a11d4 beq 0x1a1308 <_Z12Eff_Effect05iffij+0x174> */
/* @0x1a11d8 cmp r4, #2 */
/* @0x1a11dc beq 0x1a1430 <_Z12Eff_Effect05iffij+0x29c> */
/* @0x1a11e0 ldr r4, [r0, r3] */
/* @0x1a11e4 mov r5, #11 */
/* @0x1a11e8 mov r8, #1 */
/* @0x1a11ec ldr r0, [r4, #0x4] */
/* @0x1a11f0 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a11f4 vldr s15, [pc, #856] */
/* @0x1a11f8 vmul.f32 s15, s16, s15 */
/* @0x1a11fc ldr r0, [r4, #0x4] */
/* @0x1a1200 movw r1, #0xcccd */
/* @0x1a1204 str r9, [sp] */
/* @0x1a1208 movt r1, #0x3ecc */
/* @0x1a120c movw r2, #0x3333 */
/* @0x1a1210 movt r2, #0x3f33 */
/* @0x1a1214 vmov r3, s15 */
/* @0x1a1218 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a121c mov r2, r9 */
/* @0x1a1220 ldr r0, [r4, #0x4] */
/* @0x1a1224 movw r1, #0xcccd */
/* @0x1a1228 movt r1, #0x3ecc */
/* @0x1a122c bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a1230 vmov.f32 s14, #5.000000e+00 */
/* @0x1a1234 ldr r0, [r4, #0x4] */
/* @0x1a1238 mov r3, r9 */
/* @0x1a123c str r9, [sp] */
/* @0x1a1240 vmov.f32 s15, #6.000000e+00 */
/* @0x1a1244 vmul.f32 s14, s16, s14 */
/* @0x1a1248 vmul.f32 s15, s16, s15 */
/* @0x1a124c vmov r1, s14 */
/* @0x1a1250 vmov r2, s15 */
/* @0x1a1254 bl 0x1a3368 <_Z18ParticleType_Speediffff> */
/* @0x1a1258 mov r1, #0 */
/* @0x1a125c movt r1, #0x42b4 */
/* @0x1a1260 mov r3, r9 */
/* @0x1a1264 ldr r0, [r4, #0x4] */
/* @0x1a1268 mov r2, r1 */
/* @0x1a126c str r9, [sp] */
/* @0x1a1270 bl 0x1a33b4 <_Z22ParticleType_Directioniffff> */
/* @0x1a1274 vmov.f32 s15, #3.000000e+01 */
/* @0x1a1278 ldr r10, [r4, #0x4] */
/* @0x1a127c vdiv.f32 s16, s15, s16 */
/* @0x1a1280 vcvt.f64.f32 d8, s16 */
/* @0x1a1284 vmov r0, r1, d8 */
/* @0x1a1288 bl 0xb66e8 <lrint@plt> */
/* @0x1a128c mov r9, r0 */
/* @0x1a1290 vmov r0, r1, d8 */
/* @0x1a1294 bl 0xb66e8 <lrint@plt> */
/* @0x1a1298 mov r1, r9 */
/* @0x1a129c vmov.f32 s17, #1.500000e+01 */
/* @0x1a12a0 mov r2, r0 */
/* @0x1a12a4 mov r0, r10 */
/* @0x1a12a8 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a12ac vsub.f32 s19, s19, s17 */
/* @0x1a12b0 mov r0, #30 */
/* @0x1a12b4 bl 0xc4600 <_Z8YYRandomi> */
/* @0x1a12b8 vmov s15, r0 */
/* @0x1a12bc mov r0, #30 */
/* @0x1a12c0 vcvt.f32.u32 s16, s15 */
/* @0x1a12c4 bl 0xc4600 <_Z8YYRandomi> */
/* @0x1a12c8 ldr r3, [r4, #0x4] */
/* @0x1a12cc stm sp, {r7, r8} */
/* @0x1a12d0 vsub.f32 s14, s18, s17 */
/* @0x1a12d4 vadd.f32 s16, s19, s16 */
/* @0x1a12d8 vmov r1, s16 */
/* @0x1a12dc vmov s13, r0 */
/* @0x1a12e0 mov r0, r6 */
/* @0x1a12e4 vcvt.f32.u32 s15, s13 */
/* @0x1a12e8 vadd.f32 s15, s14, s15 */
/* @0x1a12ec vmov r2, s15 */
/* @0x1a12f0 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a12f4 subs r5, r5, #1 */
/* @0x1a12f8 bne 0x1a12b0 <_Z12Eff_Effect05iffij+0x11c> */
/* @0x1a12fc add sp, sp, #8 */
/* @0x1a1300 vpop {d8, d9} */
/* @0x1a1304 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1a1308 ldr r4, [r0, r3] */
/* @0x1a130c mov r5, #6 */
/* @0x1a1310 mov r8, #1 */
/* @0x1a1314 ldr r0, [r4] */
/* @0x1a1318 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a131c vldr s15, [pc, #560] */
/* @0x1a1320 vmul.f32 s15, s16, s15 */
/* @0x1a1324 ldr r0, [r4] */
/* @0x1a1328 movw r1, #0xcccd */
/* @0x1a132c str r9, [sp] */
/* @0x1a1330 movt r1, #0x3e4c */
/* @0x1a1334 movw r2, #0xcccd */
/* @0x1a1338 movt r2, #0x3ecc */
/* @0x1a133c vmov r3, s15 */
/* @0x1a1340 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a1344 mov r2, r9 */
/* @0x1a1348 ldr r0, [r4] */
/* @0x1a134c movw r1, #0xcccd */
/* @0x1a1350 movt r1, #0x3ecc */
/* @0x1a1354 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a1358 vmov.f32 s14, #3.000000e+00 */
/* @0x1a135c ldr r0, [r4] */
/* @0x1a1360 mov r3, r9 */
/* @0x1a1364 str r9, [sp] */
/* @0x1a1368 vmov.f32 s15, #4.000000e+00 */
/* @0x1a136c vmul.f32 s14, s16, s14 */
/* @0x1a1370 vmul.f32 s15, s16, s15 */
/* @0x1a1374 vmov r1, s14 */
/* @0x1a1378 vmov r2, s15 */
/* @0x1a137c bl 0x1a3368 <_Z18ParticleType_Speediffff> */
/* @0x1a1380 mov r1, #0 */
/* @0x1a1384 movt r1, #0x42b4 */
/* @0x1a1388 mov r3, r9 */
/* @0x1a138c ldr r0, [r4] */
/* @0x1a1390 mov r2, r1 */
/* @0x1a1394 str r9, [sp] */
/* @0x1a1398 bl 0x1a33b4 <_Z22ParticleType_Directioniffff> */
/* @0x1a139c vmov.f32 s15, #2.500000e+01 */
/* @0x1a13a0 ldr r10, [r4] */
/* @0x1a13a4 vdiv.f32 s16, s15, s16 */
/* @0x1a13a8 vcvt.f64.f32 d8, s16 */
/* @0x1a13ac vmov r0, r1, d8 */
/* @0x1a13b0 bl 0xb66e8 <lrint@plt> */
/* @0x1a13b4 mov r9, r0 */
/* @0x1a13b8 vmov r0, r1, d8 */
/* @0x1a13bc bl 0xb66e8 <lrint@plt> */
/* @0x1a13c0 mov r1, r9 */
/* @0x1a13c4 vmov.f32 s17, #5.000000e+00 */
/* @0x1a13c8 mov r2, r0 */
/* @0x1a13cc mov r0, r10 */
/* @0x1a13d0 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a13d4 vsub.f32 s19, s19, s17 */
/* @0x1a13d8 mov r0, #10 */
/* @0x1a13dc bl 0xc4600 <_Z8YYRandomi> */
/* @0x1a13e0 vmov s13, r0 */
/* @0x1a13e4 mov r0, #10 */
/* @0x1a13e8 vcvt.f32.u32 s16, s13 */
/* @0x1a13ec bl 0xc4600 <_Z8YYRandomi> */
/* @0x1a13f0 ldr r3, [r4] */
/* @0x1a13f4 stm sp, {r7, r8} */
/* @0x1a13f8 vsub.f32 s14, s18, s17 */
/* @0x1a13fc vadd.f32 s16, s19, s16 */
/* @0x1a1400 vmov r1, s16 */
/* @0x1a1404 vmov s13, r0 */
/* @0x1a1408 mov r0, r6 */
/* @0x1a140c vcvt.f32.u32 s15, s13 */
/* @0x1a1410 vadd.f32 s15, s14, s15 */
/* @0x1a1414 vmov r2, s15 */
/* @0x1a1418 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a141c subs r5, r5, #1 */
/* @0x1a1420 bne 0x1a13d8 <_Z12Eff_Effect05iffij+0x244> */
/* @0x1a1424 add sp, sp, #8 */
/* @0x1a1428 vpop {d8, d9} */
/* @0x1a142c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1a1430 ldr r4, [r0, r3] */
/* @0x1a1434 mov r5, #16 */
/* @0x1a1438 mov r8, #1 */
/* @0x1a143c ldr r0, [r4, #0x8] */
/* @0x1a1440 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a1444 vldr s15, [pc, #264] */
/* @0x1a1448 vmul.f32 s15, s16, s15 */
/* @0x1a144c ldr r0, [r4, #0x8] */
/* @0x1a1450 mov r2, #1065353216 */
/* @0x1a1454 str r9, [sp] */
/* @0x1a1458 movw r1, #0xcccd */
/* @0x1a145c movt r1, #0x3ecc */
/* @0x1a1460 vmov r3, s15 */
/* @0x1a1464 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a1468 mov r2, r9 */
/* @0x1a146c ldr r0, [r4, #0x8] */
/* @0x1a1470 movw r1, #0xcccd */
/* @0x1a1474 movt r1, #0x3ecc */
/* @0x1a1478 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x1a147c vmov.f32 s14, #6.000000e+00 */
/* @0x1a1480 ldr r0, [r4, #0x8] */
/* @0x1a1484 mov r3, r9 */
/* @0x1a1488 str r9, [sp] */
/* @0x1a148c vmov.f32 s15, #7.000000e+00 */
/* @0x1a1490 vmul.f32 s14, s16, s14 */
/* @0x1a1494 vmul.f32 s15, s16, s15 */
/* @0x1a1498 vmov r1, s14 */
/* @0x1a149c vmov r2, s15 */
/* @0x1a14a0 bl 0x1a3368 <_Z18ParticleType_Speediffff> */
/* @0x1a14a4 mov r1, #0 */
/* @0x1a14a8 movt r1, #0x42b4 */
/* @0x1a14ac mov r3, r9 */
/* @0x1a14b0 ldr r0, [r4, #0x8] */
/* @0x1a14b4 mov r2, r1 */
/* @0x1a14b8 str r9, [sp] */
/* @0x1a14bc bl 0x1a33b4 <_Z22ParticleType_Directioniffff> */
/* @0x1a14c0 vldr s15, [pc, #144] */
/* @0x1a14c4 vdiv.f32 s16, s15, s16 */
/* @0x1a14c8 ldr r10, [r4, #0x8] */
/* @0x1a14cc vcvt.f64.f32 d8, s16 */
/* @0x1a14d0 vmov r0, r1, d8 */
/* @0x1a14d4 bl 0xb66e8 <lrint@plt> */
/* @0x1a14d8 mov r9, r0 */
/* @0x1a14dc vmov r0, r1, d8 */
/* @0x1a14e0 bl 0xb66e8 <lrint@plt> */
/* @0x1a14e4 mov r1, r9 */
/* @0x1a14e8 vmov.f32 s17, #3.000000e+01 */
/* @0x1a14ec mov r2, r0 */
/* @0x1a14f0 mov r0, r10 */
/* @0x1a14f4 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a14f8 vsub.f32 s19, s19, s17 */
/* @0x1a14fc mov r0, #60 */
/* @0x1a1500 bl 0xc4600 <_Z8YYRandomi> */
/* @0x1a1504 vmov s15, r0 */
/* @0x1a1508 mov r0, #60 */
/* @0x1a150c vcvt.f32.u32 s16, s15 */
/* @0x1a1510 bl 0xc4600 <_Z8YYRandomi> */
/* @0x1a1514 ldr r3, [r4, #0x8] */
/* @0x1a1518 stm sp, {r7, r8} */
/* @0x1a151c vsub.f32 s14, s18, s17 */
/* @0x1a1520 vadd.f32 s16, s19, s16 */
/* @0x1a1524 vmov r1, s16 */
/* @0x1a1528 vmov s13, r0 */
/* @0x1a152c mov r0, r6 */
/* @0x1a1530 vcvt.f32.u32 s15, s13 */
/* @0x1a1534 vadd.f32 s15, s14, s15 */
/* @0x1a1538 vmov r2, s15 */
/* @0x1a153c bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a1540 subs r5, r5, #1 */
/* @0x1a1544 bne 0x1a14fc <_Z12Eff_Effect05iffij+0x368> */
/* @0x1a1548 add sp, sp, #8 */
/* @0x1a154c vpop {d8, d9} */
/* @0x1a1550 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1a1554 stclt p7, c13, [r3], #-40 */
/* @0x1a1558 submi r0, r8, #0 */
/* @0x1a155c .word 0xffffeb34 */
/* @0x1a1560 eoreq r0, r5, r0, lsl #21 */

/* ── FUNC 0x1a1564 · Eff_Create06() · size=44 · insn=11 */
/* @0x1a1564 push {r4, lr} */
/* @0x1a1568 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a156c ldr r4, [pc, #0x18] */
/* @0x1a1570 ldr r4, [pc, r4] */
/* @0x1a1574 str r0, [r4] */
/* @0x1a1578 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a157c str r0, [r4, #0x4] */
/* @0x1a1580 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a1584 str r0, [r4, #0x8] */
/* @0x1a1588 pop {r4, pc} */
/* @0x1a158c eoreq pc, r4, r8, lsl r2 */

/* ── FUNC 0x1a1590 · Eff_Effect06(int, float, float, int, unsigned int) · size=560 · insn=140 */
/* @0x1a1590 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1a1594 vpush {d8} */
/* @0x1a1598 sub sp, sp, #12 */
/* @0x1a159c mov r4, r3 */
/* @0x1a15a0 mov r7, r1 */
/* @0x1a15a4 mov r6, r2 */
/* @0x1a15a8 mov r8, r0 */
/* @0x1a15ac bl 0x19ff6c <_Z12Speed_Factorv> */
/* @0x1a15b0 cmp r4, #0 */
/* @0x1a15b4 ldr r3, [pc, #0x1fc] */
/* @0x1a15b8 mov r1, #4 */
/* @0x1a15bc ldr r2, [pc, #0x1f8] */
/* @0x1a15c0 add r3, pc, r3 */
/* @0x1a15c4 vmov s16, r0 */
/* @0x1a15c8 beq 0x1a168c <_Z12Eff_Effect06iffij+0xfc> */
/* @0x1a15cc cmp r4, #2 */
/* @0x1a15d0 mov r5, #0 */
/* @0x1a15d4 ldr r4, [r3, r2] */
/* @0x1a15d8 beq 0x1a1720 <_Z12Eff_Effect06iffij+0x190> */
/* @0x1a15dc ldr r0, [r4, #0x4] */
/* @0x1a15e0 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a15e4 vldr s15, [pc, #448] */
/* @0x1a15e8 vmul.f32 s15, s16, s15 */
/* @0x1a15ec mov r1, #1061158912 */
/* @0x1a15f0 ldr r0, [r4, #0x4] */
/* @0x1a15f4 mov r2, r1 */
/* @0x1a15f8 str r5, [sp] */
/* @0x1a15fc vmov r3, s15 */
/* @0x1a1600 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a1604 ldr r0, [r4, #0x4] */
/* @0x1a1608 mov r1, r5 */
/* @0x1a160c str r5, [sp] */
/* @0x1a1610 mov r3, #0 */
/* @0x1a1614 mov r2, #0 */
/* @0x1a1618 str r3, [sp, #0x4] */
/* @0x1a161c movt r2, #0x43b4 */
/* @0x1a1620 mov r3, r5 */
/* @0x1a1624 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb> */
/* @0x1a1628 vmov.f32 s15, #2.500000e+01 */
/* @0x1a162c ldr r9, [r4, #0x4] */
/* @0x1a1630 vdiv.f32 s16, s15, s16 */
/* @0x1a1634 vcvt.f64.f32 d8, s16 */
/* @0x1a1638 vmov r0, r1, d8 */
/* @0x1a163c bl 0xb66e8 <lrint@plt> */
/* @0x1a1640 mov r5, r0 */
/* @0x1a1644 vmov r0, r1, d8 */
/* @0x1a1648 bl 0xb66e8 <lrint@plt> */
/* @0x1a164c mov r1, r5 */
/* @0x1a1650 mov r2, r0 */
/* @0x1a1654 mov r0, r9 */
/* @0x1a1658 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a165c ldr r3, [r4, #0x4] */
/* @0x1a1660 ldr r2, [sp, #0x30] */
/* @0x1a1664 mov r12, #1 */
/* @0x1a1668 mov r0, r8 */
/* @0x1a166c mov r1, r7 */
/* @0x1a1670 str r12, [sp, #0x4] */
/* @0x1a1674 str r2, [sp] */
/* @0x1a1678 mov r2, r6 */
/* @0x1a167c bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a1680 add sp, sp, #12 */
/* @0x1a1684 vpop {d8} */
/* @0x1a1688 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1a168c ldr r5, [r3, r2] */
/* @0x1a1690 mov r9, #0 */
/* @0x1a1694 ldr r0, [r5] */
/* @0x1a1698 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a169c vldr s15, [pc, #268] */
/* @0x1a16a0 vmul.f32 s15, s16, s15 */
/* @0x1a16a4 ldr r0, [r5] */
/* @0x1a16a8 movw r1, #0xcccd */
/* @0x1a16ac str r9, [sp] */
/* @0x1a16b0 movt r1, #0x3ecc */
/* @0x1a16b4 movw r2, #0x999a */
/* @0x1a16b8 movt r2, #0x3e99 */
/* @0x1a16bc vmov r3, s15 */
/* @0x1a16c0 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a16c4 mov r3, r9 */
/* @0x1a16c8 ldr r0, [r5] */
/* @0x1a16cc mov r1, r9 */
/* @0x1a16d0 str r9, [sp] */
/* @0x1a16d4 mov r2, #0 */
/* @0x1a16d8 str r4, [sp, #0x4] */
/* @0x1a16dc movt r2, #0x43b4 */
/* @0x1a16e0 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb> */
/* @0x1a16e4 vmov.f32 s15, #2.000000e+01 */
/* @0x1a16e8 ldr r9, [r5] */
/* @0x1a16ec vdiv.f32 s16, s15, s16 */
/* @0x1a16f0 vcvt.f64.f32 d8, s16 */
/* @0x1a16f4 vmov r0, r1, d8 */
/* @0x1a16f8 bl 0xb66e8 <lrint@plt> */
/* @0x1a16fc mov r4, r0 */
/* @0x1a1700 vmov r0, r1, d8 */
/* @0x1a1704 bl 0xb66e8 <lrint@plt> */
/* @0x1a1708 mov r1, r4 */
/* @0x1a170c mov r2, r0 */
/* @0x1a1710 mov r0, r9 */
/* @0x1a1714 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a1718 ldr r3, [r5] */
/* @0x1a171c b 0x1a1660 <_Z12Eff_Effect06iffij+0xd0> */
/* @0x1a1720 ldr r0, [r4, #0x8] */
/* @0x1a1724 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a1728 vldr s15, [pc, #132] */
/* @0x1a172c vmul.f32 s15, s16, s15 */
/* @0x1a1730 movw r1, #0x999a */
/* @0x1a1734 movt r1, #0x3f99 */
/* @0x1a1738 ldr r0, [r4, #0x8] */
/* @0x1a173c str r5, [sp] */
/* @0x1a1740 mov r2, r1 */
/* @0x1a1744 vmov r3, s15 */
/* @0x1a1748 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a174c ldr r0, [r4, #0x8] */
/* @0x1a1750 mov r1, r5 */
/* @0x1a1754 str r5, [sp] */
/* @0x1a1758 mov r3, #0 */
/* @0x1a175c mov r2, #0 */
/* @0x1a1760 str r3, [sp, #0x4] */
/* @0x1a1764 movt r2, #0x43b4 */
/* @0x1a1768 mov r3, r5 */
/* @0x1a176c bl 0x1a3400 <_Z24ParticleType_Orientationiffffb> */
/* @0x1a1770 vmov.f32 s15, #3.000000e+01 */
/* @0x1a1774 ldr r9, [r4, #0x8] */
/* @0x1a1778 vdiv.f32 s16, s15, s16 */
/* @0x1a177c vcvt.f64.f32 d8, s16 */
/* @0x1a1780 vmov r0, r1, d8 */
/* @0x1a1784 bl 0xb66e8 <lrint@plt> */
/* @0x1a1788 mov r5, r0 */
/* @0x1a178c vmov r0, r1, d8 */
/* @0x1a1790 bl 0xb66e8 <lrint@plt> */
/* @0x1a1794 mov r1, r5 */
/* @0x1a1798 mov r2, r0 */
/* @0x1a179c mov r0, r9 */
/* @0x1a17a0 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a17a4 ldr r3, [r4, #0x8] */
/* @0x1a17a8 b 0x1a1660 <_Z12Eff_Effect06iffij+0xd0> */
/* @0x1a17ac ldcllt p2, c12, [r5], #572 */
/* @0x1a17b0 stclt p7, c13, [r3], #40 */
/* @0x1a17b4 stclt p7, c13, [r3, #-40]! */
/* @0x1a17b8 mlaeq r5, r0, r6, r0 */
/* @0x1a17bc .word 0xffffeb38 */

/* ── FUNC 0x1a17c0 · Eff_Create07() · size=44 · insn=11 */
/* @0x1a17c0 push {r4, lr} */
/* @0x1a17c4 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a17c8 ldr r4, [pc, #0x18] */
/* @0x1a17cc ldr r4, [pc, r4] */
/* @0x1a17d0 str r0, [r4] */
/* @0x1a17d4 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a17d8 str r0, [r4, #0x4] */
/* @0x1a17dc bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a17e0 str r0, [r4, #0x8] */
/* @0x1a17e4 pop {r4, pc} */
/* @0x1a17e8 eoreq lr, r4, r0, asr #31 */

/* ── FUNC 0x1a17ec · Eff_Effect07(int, float, float, int, unsigned int) · size=556 · insn=139 */
/* @0x1a17ec push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1a17f0 vpush {d8} */
/* @0x1a17f4 sub sp, sp, #12 */
/* @0x1a17f8 mov r4, r3 */
/* @0x1a17fc mov r7, r1 */
/* @0x1a1800 mov r6, r2 */
/* @0x1a1804 mov r8, r0 */
/* @0x1a1808 bl 0x19ff6c <_Z12Speed_Factorv> */
/* @0x1a180c cmp r4, #0 */
/* @0x1a1810 ldr r3, [pc, #0x1f8] */
/* @0x1a1814 mov r1, #9 */
/* @0x1a1818 ldr r2, [pc, #0x1f4] */
/* @0x1a181c add r3, pc, r3 */
/* @0x1a1820 vmov s16, r0 */
/* @0x1a1824 beq 0x1a18e8 <_Z12Eff_Effect07iffij+0xfc> */
/* @0x1a1828 cmp r4, #2 */
/* @0x1a182c mov r5, #0 */
/* @0x1a1830 ldr r4, [r3, r2] */
/* @0x1a1834 beq 0x1a1978 <_Z12Eff_Effect07iffij+0x18c> */
/* @0x1a1838 ldr r0, [r4, #0x4] */
/* @0x1a183c bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a1840 vldr s15, [pc, #444] */
/* @0x1a1844 vmul.f32 s15, s16, s15 */
/* @0x1a1848 mov r1, #1061158912 */
/* @0x1a184c ldr r0, [r4, #0x4] */
/* @0x1a1850 mov r2, r1 */
/* @0x1a1854 str r5, [sp] */
/* @0x1a1858 vmov r3, s15 */
/* @0x1a185c bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a1860 ldr r0, [r4, #0x4] */
/* @0x1a1864 mov r1, r5 */
/* @0x1a1868 str r5, [sp] */
/* @0x1a186c mov r3, #0 */
/* @0x1a1870 mov r2, #0 */
/* @0x1a1874 str r3, [sp, #0x4] */
/* @0x1a1878 movt r2, #0x43b4 */
/* @0x1a187c mov r3, r5 */
/* @0x1a1880 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb> */
/* @0x1a1884 vmov.f32 s15, #2.500000e+01 */
/* @0x1a1888 ldr r9, [r4, #0x4] */
/* @0x1a188c vdiv.f32 s16, s15, s16 */
/* @0x1a1890 vcvt.f64.f32 d8, s16 */
/* @0x1a1894 vmov r0, r1, d8 */
/* @0x1a1898 bl 0xb66e8 <lrint@plt> */
/* @0x1a189c mov r5, r0 */
/* @0x1a18a0 vmov r0, r1, d8 */
/* @0x1a18a4 bl 0xb66e8 <lrint@plt> */
/* @0x1a18a8 mov r1, r5 */
/* @0x1a18ac mov r2, r0 */
/* @0x1a18b0 mov r0, r9 */
/* @0x1a18b4 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a18b8 ldr r3, [r4, #0x4] */
/* @0x1a18bc ldr r2, [sp, #0x30] */
/* @0x1a18c0 mov r12, #1 */
/* @0x1a18c4 mov r0, r8 */
/* @0x1a18c8 mov r1, r7 */
/* @0x1a18cc str r12, [sp, #0x4] */
/* @0x1a18d0 str r2, [sp] */
/* @0x1a18d4 mov r2, r6 */
/* @0x1a18d8 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a18dc add sp, sp, #12 */
/* @0x1a18e0 vpop {d8} */
/* @0x1a18e4 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1a18e8 ldr r5, [r3, r2] */
/* @0x1a18ec mov r9, #0 */
/* @0x1a18f0 ldr r0, [r5] */
/* @0x1a18f4 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a18f8 vldr s15, [pc, #264] */
/* @0x1a18fc vmul.f32 s15, s16, s15 */
/* @0x1a1900 movw r1, #0xcccd */
/* @0x1a1904 movt r1, #0x3ecc */
/* @0x1a1908 ldr r0, [r5] */
/* @0x1a190c str r9, [sp] */
/* @0x1a1910 mov r2, r1 */
/* @0x1a1914 vmov r3, s15 */
/* @0x1a1918 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a191c mov r3, r9 */
/* @0x1a1920 ldr r0, [r5] */
/* @0x1a1924 mov r1, r9 */
/* @0x1a1928 str r9, [sp] */
/* @0x1a192c mov r2, #0 */
/* @0x1a1930 str r4, [sp, #0x4] */
/* @0x1a1934 movt r2, #0x43b4 */
/* @0x1a1938 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb> */
/* @0x1a193c vmov.f32 s15, #2.000000e+01 */
/* @0x1a1940 ldr r9, [r5] */
/* @0x1a1944 vdiv.f32 s16, s15, s16 */
/* @0x1a1948 vcvt.f64.f32 d8, s16 */
/* @0x1a194c vmov r0, r1, d8 */
/* @0x1a1950 bl 0xb66e8 <lrint@plt> */
/* @0x1a1954 mov r4, r0 */
/* @0x1a1958 vmov r0, r1, d8 */
/* @0x1a195c bl 0xb66e8 <lrint@plt> */
/* @0x1a1960 mov r1, r4 */
/* @0x1a1964 mov r2, r0 */
/* @0x1a1968 mov r0, r9 */
/* @0x1a196c bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a1970 ldr r3, [r5] */
/* @0x1a1974 b 0x1a18bc <_Z12Eff_Effect07iffij+0xd0> */
/* @0x1a1978 ldr r0, [r4, #0x8] */
/* @0x1a197c bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a1980 vldr s15, [pc, #132] */
/* @0x1a1984 vmul.f32 s15, s16, s15 */
/* @0x1a1988 movw r1, #0x999a */
/* @0x1a198c movt r1, #0x3f99 */
/* @0x1a1990 ldr r0, [r4, #0x8] */
/* @0x1a1994 str r5, [sp] */
/* @0x1a1998 mov r2, r1 */
/* @0x1a199c vmov r3, s15 */
/* @0x1a19a0 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a19a4 ldr r0, [r4, #0x8] */
/* @0x1a19a8 mov r1, r5 */
/* @0x1a19ac str r5, [sp] */
/* @0x1a19b0 mov r3, #0 */
/* @0x1a19b4 mov r2, #0 */
/* @0x1a19b8 str r3, [sp, #0x4] */
/* @0x1a19bc movt r2, #0x43b4 */
/* @0x1a19c0 mov r3, r5 */
/* @0x1a19c4 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb> */
/* @0x1a19c8 vmov.f32 s15, #3.000000e+01 */
/* @0x1a19cc ldr r9, [r4, #0x8] */
/* @0x1a19d0 vdiv.f32 s16, s15, s16 */
/* @0x1a19d4 vcvt.f64.f32 d8, s16 */
/* @0x1a19d8 vmov r0, r1, d8 */
/* @0x1a19dc bl 0xb66e8 <lrint@plt> */
/* @0x1a19e0 mov r5, r0 */
/* @0x1a19e4 vmov r0, r1, d8 */
/* @0x1a19e8 bl 0xb66e8 <lrint@plt> */
/* @0x1a19ec mov r1, r5 */
/* @0x1a19f0 mov r2, r0 */
/* @0x1a19f4 mov r0, r9 */
/* @0x1a19f8 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a19fc ldr r3, [r4, #0x8] */
/* @0x1a1a00 b 0x1a18bc <_Z12Eff_Effect07iffij+0xd0> */
/* @0x1a1a04 ldcllt p2, c12, [r5], #572 */
/* @0x1a1a08 stclt p7, c13, [r3], #40 */
/* @0x1a1a0c stclt p7, c13, [r3, #-40]! */
/* @0x1a1a10 eoreq r0, r5, r4, lsr r4 */
/* @0x1a1a14 .word 0xffffeb3c */

/* ── FUNC 0x1a1a18 · Eff_Create08() · size=44 · insn=11 */
/* @0x1a1a18 push {r4, lr} */
/* @0x1a1a1c bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a1a20 ldr r4, [pc, #0x18] */
/* @0x1a1a24 ldr r4, [pc, r4] */
/* @0x1a1a28 str r0, [r4] */
/* @0x1a1a2c bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a1a30 str r0, [r4, #0x4] */
/* @0x1a1a34 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a1a38 str r0, [r4, #0x8] */
/* @0x1a1a3c pop {r4, pc} */
/* @0x1a1a40 eoreq lr, r4, r12, ror #26 */
