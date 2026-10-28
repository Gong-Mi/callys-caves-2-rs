/* libyoyo.so 覆盖卡组 0011
 * 函数 0xcec84..0xd1294，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xcec84 · YYGetFloat(RValue const*, int) · size=224 · insn=56 */
/* @0xcec84 add r2, r0, r1, lsl #4 */
/* @0xcec88 push {r4, r5, r6, lr} */
/* @0xcec8c mov r6, r1 */
/* @0xcec90 ldr r3, [r2, #0xc] */
/* @0xcec94 bic r3, r3, #-16777216 */
/* @0xcec98 cmp r3, #13 */
/* @0xcec9c addls pc, pc, r3, lsl #2 */
/* @0xceca0 b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c> */
/* @0xceca4 b 0xced08 <_Z10YYGetFloatPK6RValuei+0x84> */
/* @0xceca8 b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c> */
/* @0xcecac b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c> */
/* @0xcecb0 b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c> */
/* @0xcecb4 b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c> */
/* @0xcecb8 b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c> */
/* @0xcecbc b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c> */
/* @0xcecc0 b 0xcecf4 <_Z10YYGetFloatPK6RValuei+0x70> */
/* @0xcecc4 b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c> */
/* @0xcecc8 b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c> */
/* @0xceccc b 0xcecdc <_Z10YYGetFloatPK6RValuei+0x58> */
/* @0xcecd0 b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c> */
/* @0xcecd4 b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c> */
/* @0xcecd8 b 0xced08 <_Z10YYGetFloatPK6RValuei+0x84> */
/* @0xcecdc ldr r0, [r0, r1, lsl #4] */
/* @0xcece0 ldr r1, [r2, #0x4] */
/* @0xcece4 bl 0x319398 <__floatdisf> */
/* @0xcece8 vmov s15, r0 */
/* @0xcecec vmov r0, s15 */
/* @0xcecf0 pop {r4, r5, r6, pc} */
/* @0xcecf4 ldr r6, [r0, r1, lsl #4] */
/* @0xcecf8 vmov s15, r6 */
/* @0xcecfc vcvt.f32.s32 s15, s15 */
/* @0xced00 vmov r0, s15 */
/* @0xced04 pop {r4, r5, r6, pc} */
/* @0xced08 ldr r4, [r0, r1, lsl #4] */
/* @0xced0c ldr r5, [r2, #0x4] */
/* @0xced10 vmov d6, r4, r5 */
/* @0xced14 vcvt.f32.f64 s15, d6 */
/* @0xced18 vmov r0, s15 */
/* @0xced1c pop {r4, r5, r6, pc} */
/* @0xced20 ldr r3, [pc, #0x34] */
/* @0xced24 mov r0, r2 */
/* @0xced28 ldr r3, [pc, r3] */
/* @0xced2c ldr r4, [r3] */
/* @0xced30 bl 0xce54c <_Z8KindNamePK6RValue> */
/* @0xced34 add r2, r6, #1 */
/* @0xced38 mov r1, r4 */
/* @0xced3c mov r3, r0 */
/* @0xced40 ldr r0, [pc, #0x18] */
/* @0xced44 add r0, pc, r0 */
/* @0xced48 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xced4c vldr s15, [pc, #4] */
/* @0xced50 vmov r0, s15 */
/* @0xced54 pop {r4, r5, r6, pc} */
/* @0xced58 andeq r0, r0, r0 */
/* @0xced5c eorseq lr, r1, r8, lsl #28 */
/* @0xced60 eoreq r3, r6, r8, lsr #14 */

/* ── FUNC 0xced64 · Code_GetEntry(int) · size=56 · insn=14 */
/* @0xced64 ldr r3, [pc, #0x28] */
/* @0xced68 ldr r3, [pc, r3] */
/* @0xced6c ldr r3, [r3] */
/* @0xced70 cmp r3, r0 */
/* @0xced74 ble 0xced8c <_Z13Code_GetEntryi+0x28> */
/* @0xced78 ldr r3, [pc, #0x18] */
/* @0xced7c ldr r3, [pc, r3] */
/* @0xced80 ldr r3, [r3] */
/* @0xced84 ldr r0, [r3, r0, lsl #2] */
/* @0xced88 bx lr */
/* @0xced8c mov r0, #0 */
/* @0xced90 bx lr */
/* @0xced94 eorseq lr, r1, r12, asr #27 */
/* @0xced98 ldrhteq lr, [r1], -r12 */

/* ── FUNC 0xced9c · ARRAY_RefAlloc(void*) · size=72 · insn=18 */
/* @0xced9c ldr r1, [pc, #0x3c] */
/* @0xceda0 movw r2, #0x1e7 */
/* @0xceda4 push {r3, r4, r5, lr} */
/* @0xceda8 add r1, pc, r1 */
/* @0xcedac mov r5, r0 */
/* @0xcedb0 mov r3, #1 */
/* @0xcedb4 mov r0, #20 */
/* @0xcedb8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xcedbc mov r1, #0 */
/* @0xcedc0 mov r2, #20 */
/* @0xcedc4 mov r4, r0 */
/* @0xcedc8 bl 0xb65b0 <memset@plt> */
/* @0xcedcc mov r3, #1 */
/* @0xcedd0 str r5, [r4, #0x8] */
/* @0xcedd4 mov r0, r4 */
/* @0xcedd8 str r3, [r4] */
/* @0xceddc pop {r3, r4, r5, pc} */
/* @0xcede0 eoreq r3, r6, r4, asr r4 */

/* ── FUNC 0xcede4 · ARRAY_RVAL_RValue(RValue const*, int) · size=176 · insn=44 */
/* @0xcede4 push {r4, lr} */
/* @0xcede8 sub sp, sp, #8 */
/* @0xcedec mov r4, r0 */
/* @0xcedf0 mov r2, #32000 */
/* @0xcedf4 mov r0, sp */
/* @0xcedf8 bl 0xb664c <ldiv@plt> */
/* @0xcedfc ldr r3, [r4, #0xc] */
/* @0xcee00 ldr r2, [sp] */
/* @0xcee04 bic r3, r3, #-16777216 */
/* @0xcee08 ldr r1, [sp, #0x4] */
/* @0xcee0c cmp r3, #2 */
/* @0xcee10 beq 0xcee2c <_Z17ARRAY_RVAL_RValuePK6RValuei+0x48> */
/* @0xcee14 mvn r2, #-16777216 */
/* @0xcee18 cmp r3, r2 */
/* @0xcee1c beq 0xcee78 <_Z17ARRAY_RVAL_RValuePK6RValuei+0x94> */
/* @0xcee20 mov r0, #0 */
/* @0xcee24 add sp, sp, #8 */
/* @0xcee28 pop {r4, pc} */
/* @0xcee2c ldr r0, [r4] */
/* @0xcee30 cmp r0, #0 */
/* @0xcee34 beq 0xcee24 <_Z17ARRAY_RVAL_RValuePK6RValuei+0x40> */
/* @0xcee38 cmp r2, #0 */
/* @0xcee3c blt 0xcee20 <_Z17ARRAY_RVAL_RValuePK6RValuei+0x3c> */
/* @0xcee40 ldr r3, [r0, #0x10] */
/* @0xcee44 cmp r3, r2 */
/* @0xcee48 ble 0xcee20 <_Z17ARRAY_RVAL_RValuePK6RValuei+0x3c> */
/* @0xcee4c ldr r3, [r0, #0x4] */
/* @0xcee50 cmp r1, #0 */
/* @0xcee54 add r0, r3, r2, lsl #3 */
/* @0xcee58 blt 0xcee20 <_Z17ARRAY_RVAL_RValuePK6RValuei+0x3c> */
/* @0xcee5c ldr r3, [r3, r2, lsl #3] */
/* @0xcee60 cmp r1, r3 */
/* @0xcee64 bge 0xcee20 <_Z17ARRAY_RVAL_RValuePK6RValuei+0x3c> */
/* @0xcee68 ldr r0, [r0, #0x4] */
/* @0xcee6c add r0, r0, r1, lsl #4 */
/* @0xcee70 add sp, sp, #8 */
/* @0xcee74 pop {r4, pc} */
/* @0xcee78 ldr r0, [pc, #0x10] */
/* @0xcee7c add r0, pc, r0 */
/* @0xcee80 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xcee84 mov r0, #0 */
/* @0xcee88 add sp, sp, #8 */
/* @0xcee8c pop {r4, pc} */
/* @0xcee90 eoreq r3, r6, r0, lsr r6 */

/* ── FUNC 0xcee94 · HASH_RValue(RValue const*) · size=184 · insn=46 */
/* @0xcee94 push {r4, lr} */
/* @0xcee98 ldr r3, [r0, #0xc] */
/* @0xcee9c ldr r1, [r0] */
/* @0xceea0 bic r3, r3, #-16777216 */
/* @0xceea4 mov r4, r1 */
/* @0xceea8 cmp r3, #10 */
/* @0xceeac addls pc, pc, r3, lsl #2 */
/* @0xceeb0 b 0xceef8 <_Z11HASH_RValuePK6RValue+0x64> */
/* @0xceeb4 b 0xcef14 <_Z11HASH_RValuePK6RValue+0x80> */
/* @0xceeb8 b 0xcef2c <_Z11HASH_RValuePK6RValue+0x98> */
/* @0xceebc b 0xceeec <_Z11HASH_RValuePK6RValue+0x58> */
/* @0xceec0 b 0xceef8 <_Z11HASH_RValuePK6RValue+0x64> */
/* @0xceec4 b 0xceef8 <_Z11HASH_RValuePK6RValue+0x64> */
/* @0xceec8 b 0xceeec <_Z11HASH_RValuePK6RValue+0x58> */
/* @0xceecc b 0xceef8 <_Z11HASH_RValuePK6RValue+0x64> */
/* @0xceed0 b 0xceee4 <_Z11HASH_RValuePK6RValue+0x50> */
/* @0xceed4 b 0xceef8 <_Z11HASH_RValuePK6RValue+0x64> */
/* @0xceed8 b 0xceef8 <_Z11HASH_RValuePK6RValue+0x64> */
/* @0xceedc b 0xceee0 <_Z11HASH_RValuePK6RValue+0x4c> */
/* @0xceee0 ldr r4, [r0] */
/* @0xceee4 mov r0, r4 */
/* @0xceee8 pop {r4, pc} */
/* @0xceeec cmp r1, #0 */
/* @0xceef0 ldrne r4, [r1, #0x4] */
/* @0xceef4 moveq r4, r1 */
/* @0xceef8 mvn r2, #-16777216 */
/* @0xceefc cmp r3, r2 */
/* @0xcef00 bne 0xceee4 <_Z11HASH_RValuePK6RValue+0x50> */
/* @0xcef04 ldr r0, [pc, #0x3c] */
/* @0xcef08 add r0, pc, r0 */
/* @0xcef0c bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xcef10 b 0xceee4 <_Z11HASH_RValuePK6RValue+0x50> */
/* @0xcef14 ldm r0, {r2, r3} */
/* @0xcef18 vmov d7, r2, r3 */
/* @0xcef1c vcvt.s32.f64 s15, d7 */
/* @0xcef20 vmov r4, s15 */
/* @0xcef24 mov r0, r4 */
/* @0xcef28 pop {r4, pc} */
/* @0xcef2c cmp r1, #0 */
/* @0xcef30 beq 0xcef40 <_Z11HASH_RValuePK6RValue+0xac> */
/* @0xcef34 ldr r0, [r1] */
/* @0xcef38 pop {r4, lr} */
/* @0xcef3c b 0x27dfa8 <_Z14CalcCRC_stringPKc> */
/* @0xcef40 mov r4, r1 */
/* @0xcef44 b 0xceee4 <_Z11HASH_RValuePK6RValue+0x50> */
/* @0xcef48 .word 0x002635bc */

/* ── FUNC 0xcef4c · YYAlloc(int) · size=24 · insn=6 */
/* @0xcef4c ldr r1, [pc, #0xc] */
/* @0xcef50 movw r2, #0x50d */
/* @0xcef54 mov r3, #0 */
/* @0xcef58 add r1, pc, r1 */
/* @0xcef5c b 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xcef60 eoreq r3, r6, r4, lsr #5 */

/* ── FUNC 0xcef64 · YYRealloc(void*, int) · size=44 · insn=11 */
/* @0xcef64 str lr, [sp, #-0x4]! */
/* @0xcef68 sub sp, sp, #12 */
/* @0xcef6c ldr r2, [pc, #0x18] */
/* @0xcef70 mov r3, #0 */
/* @0xcef74 str r3, [sp] */
/* @0xcef78 movw r3, #0x512 */
/* @0xcef7c add r2, pc, r2 */
/* @0xcef80 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xcef84 add sp, sp, #12 */
/* @0xcef88 ldr pc, [sp], #4 */
/* @0xcef8c eoreq r3, r6, r0, lsl #5 */

/* ── FUNC 0xcef90 · YYFree(void const*) · size=4 · insn=1 */
/* @0xcef90 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */

/* ── FUNC 0xcef94 · Code_Main_GET_Argument_Relative() · size=20 · insn=5 */
/* @0xcef94 ldr r3, [pc, #0x8] */
/* @0xcef98 ldr r3, [pc, r3] */
/* @0xcef9c ldrb r0, [r3] */
/* @0xcefa0 bx lr */
/* @0xcefa4 eorseq lr, r1, r4, lsr #23 */

/* ── FUNC 0xcefa8 · Code_Main_SET_Argument_Relative(int) · size=32 · insn=8 */
/* @0xcefa8 ldr r3, [pc, #0x14] */
/* @0xcefac subs r2, r0, #1 */
/* @0xcefb0 rsbs r0, r2, #0 */
/* @0xcefb4 ldr r3, [pc, r3] */
/* @0xcefb8 adcs r0, r0, r2 */
/* @0xcefbc strb r0, [r3] */
/* @0xcefc0 bx lr */
/* @0xcefc4 eorseq lr, r1, r8, lsl #23 */

/* ── FUNC 0xcefc8 · CCode::CCode(int, bool) · size=860 · insn=215 */
/* @0xcefc8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xcefcc mov r4, r0 */
/* @0xcefd0 ldr r5, [pc, #0x30c] */
/* @0xcefd4 mov r3, #0 */
/* @0xcefd8 ldr r0, [pc, #0x308] */
/* @0xcefdc sub sp, sp, #8 */
/* @0xcefe0 add r5, pc, r5 */
/* @0xcefe4 ldr r12, [pc, #0x300] */
/* @0xcefe8 ldr r0, [r5, r0] */
/* @0xcefec str r1, [r4, #0x60] */
/* @0xceff0 add r0, r0, #8 */
/* @0xceff4 strb r3, [r4, #0x68] */
/* @0xceff8 str r0, [r4] */
/* @0xceffc str r3, [r4, #0x50] */
/* @0xcf000 str r3, [r4, #0x54] */
/* @0xcf004 str r3, [r4, #0x64] */
/* @0xcf008 str r3, [r4, #0x6c] */
/* @0xcf00c str r3, [r4, #0x70] */
/* @0xcf010 ldr r3, [r5, r12] */
/* @0xcf014 ldrb r6, [r3] */
/* @0xcf018 cmp r6, #0 */
/* @0xcf01c beq 0xcf0d4 <_ZN5CCodeC2Eib+0x10c> */
/* @0xcf020 ldr r3, [pc, #0x2c8] */
/* @0xcf024 ldr r0, [pc, #0x2c8] */
/* @0xcf028 ldr r12, [r5, r3] */
/* @0xcf02c add r0, pc, r0 */
/* @0xcf030 mov r3, r0 */
/* @0xcf034 ldr r12, [r12] */
/* @0xcf038 ldr r12, [r12, #0x1c] */
/* @0xcf03c add lr, r12, r1, lsl #3 */
/* @0xcf040 ldr r1, [r12, r1, lsl #3] */
/* @0xcf044 str lr, [r4, #0x64] */
/* @0xcf048 str r0, [r4, #0x10] */
/* @0xcf04c str r1, [r4, #0x5c] */
/* @0xcf050 cmp r2, #0 */
/* @0xcf054 str r3, [r4, #0x58] */
/* @0xcf058 mov r1, #0 */
/* @0xcf05c mov r3, #1 */
/* @0xcf060 mov r2, #44 */
/* @0xcf064 strb r3, [r4, #0xc] */
/* @0xcf068 add r0, r4, #20 */
/* @0xcf06c movne r3, #2 */
/* @0xcf070 str r3, [r4, #0x8] */
/* @0xcf074 bl 0xb65b0 <memset@plt> */
/* @0xcf078 add r0, r4, #64 */
/* @0xcf07c mov r1, #0 */
/* @0xcf080 mov r2, #16 */
/* @0xcf084 bl 0xb65b0 <memset@plt> */
/* @0xcf088 ldr r3, [r4, #0x60] */
/* @0xcf08c cmp r3, #0 */
/* @0xcf090 blt 0xcf0c8 <_ZN5CCodeC2Eib+0x100> */
/* @0xcf094 ldr r3, [pc, #0x25c] */
/* @0xcf098 ldr r3, [r5, r3] */
/* @0xcf09c ldr r2, [r3] */
/* @0xcf0a0 cmp r2, #0 */
/* @0xcf0a4 streq r4, [r3] */
/* @0xcf0a8 strne r4, [r3] */
/* @0xcf0ac ldr r3, [pc, #0x248] */
/* @0xcf0b0 streq r2, [r4, #0x4] */
/* @0xcf0b4 strne r2, [r4, #0x4] */
/* @0xcf0b8 ldr r3, [r5, r3] */
/* @0xcf0bc ldr r2, [r3] */
/* @0xcf0c0 add r2, r2, #1 */
/* @0xcf0c4 str r2, [r3] */
/* @0xcf0c8 mov r0, r4 */
/* @0xcf0cc add sp, sp, #8 */
/* @0xcf0d0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xcf0d4 cmp r1, #0 */
/* @0xcf0d8 blt 0xcf0f0 <_ZN5CCodeC2Eib+0x128> */
/* @0xcf0dc ldr r3, [pc, #0x21c] */
/* @0xcf0e0 ldr r3, [r5, r3] */
/* @0xcf0e4 ldr r3, [r3] */
/* @0xcf0e8 cmp r1, r3 */
/* @0xcf0ec blt 0xcf10c <_ZN5CCodeC2Eib+0x144> */
/* @0xcf0f0 ldr r1, [pc, #0x20c] */
/* @0xcf0f4 mov r3, #0 */
/* @0xcf0f8 str r3, [r4, #0x5c] */
/* @0xcf0fc add r1, pc, r1 */
/* @0xcf100 str r1, [r4, #0x10] */
/* @0xcf104 mov r3, r1 */
/* @0xcf108 b 0xcf050 <_ZN5CCodeC2Eib+0x88> */
/* @0xcf10c mov r0, #28 */
/* @0xcf110 str r1, [sp, #0x4] */
/* @0xcf114 str r2, [sp] */
/* @0xcf118 bl 0x27c524 <_Znwj> */
/* @0xcf11c ldr r12, [pc, #0x1e4] */
/* @0xcf120 ldr r3, [pc, #0x1e4] */
/* @0xcf124 ldr r1, [sp, #0x4] */
/* @0xcf128 ldr r7, [r5, r12] */
/* @0xcf12c ldr r2, [sp] */
/* @0xcf130 add r12, r7, #8 */
/* @0xcf134 str r6, [r0, #0x10] */
/* @0xcf138 str r6, [r0, #0x14] */
/* @0xcf13c str r6, [r0, #0x18] */
/* @0xcf140 str r12, [r0] */
/* @0xcf144 str r0, [r4, #0x50] */
/* @0xcf148 ldr r3, [r5, r3] */
/* @0xcf14c ldr r3, [r3] */
/* @0xcf150 ldr r3, [r3, r1, lsl #2] */
/* @0xcf154 cmp r3, #0 */
/* @0xcf158 ldrne r12, [pc, #0x1b0] */
/* @0xcf15c ldrne r12, [r5, r12] */
/* @0xcf160 ldrne r12, [r12] */
/* @0xcf164 addne r3, r12, r3 */
/* @0xcf168 ldr r12, [r3] */
/* @0xcf16c cmp r12, #0 */
/* @0xcf170 moveq r6, r12 */
/* @0xcf174 ldrne lr, [pc, #0x194] */
/* @0xcf178 ldrne lr, [r5, lr] */
/* @0xcf17c ldrne r6, [lr] */
/* @0xcf180 addne r6, r6, r12 */
/* @0xcf184 ldr r12, [pc, #0x188] */
/* @0xcf188 mov lr, #0 */
/* @0xcf18c str r6, [r4, #0x5c] */
/* @0xcf190 str lr, [r4, #0x10] */
/* @0xcf194 ldr r12, [r5, r12] */
/* @0xcf198 ldr r12, [r12] */
/* @0xcf19c cmp r12, lr */
/* @0xcf1a0 beq 0xcf1cc <_ZN5CCodeC2Eib+0x204> */
/* @0xcf1a4 ldr r12, [r12, r1, lsl #2] */
/* @0xcf1a8 cmp r12, lr */
/* @0xcf1ac ldrne lr, [pc, #0x164] */
/* @0xcf1b0 ldrne lr, [r5, lr] */
/* @0xcf1b4 ldrne lr, [lr] */
/* @0xcf1b8 addne r12, lr, r12 */
/* @0xcf1bc ldr r12, [r12] */
/* @0xcf1c0 cmp r12, #0 */
/* @0xcf1c4 bne 0xcf2d0 <_ZN5CCodeC2Eib+0x308> */
/* @0xcf1c8 str r12, [r4, #0x10] */
/* @0xcf1cc ldr r12, [pc, #0x148] */
/* @0xcf1d0 ldr r10, [r3, #0x4] */
/* @0xcf1d4 ldr r12, [r5, r12] */
/* @0xcf1d8 ldrb r12, [r12] */
/* @0xcf1dc cmp r12, #0 */
/* @0xcf1e0 beq 0xcf2a4 <_ZN5CCodeC2Eib+0x2dc> */
/* @0xcf1e4 ldrh lr, [r3, #10] */
/* @0xcf1e8 add r9, r3, #12 */
/* @0xcf1ec ldrh r12, [r3, #8] */
/* @0xcf1f0 ldr r8, [r3, #0x10] */
/* @0xcf1f4 ubfx r6, lr, #0x0, #0xd */
/* @0xcf1f8 ldr r3, [r3, #0xc] */
/* @0xcf1fc str r10, [r0, #0x4] */
/* @0xcf200 str r12, [r0, #0x8] */
/* @0xcf204 add r3, r3, r9 */
/* @0xcf208 str lr, [r0, #0xc] */
/* @0xcf20c str r3, [r0, #0x10] */
/* @0xcf210 str r12, [r4, #0x70] */
/* @0xcf214 str r8, [r4, #0x6c] */
/* @0xcf218 ldr r3, [pc, #0x100] */
/* @0xcf21c lsr lr, lr, #13 */
/* @0xcf220 str r6, [r4, #0x74] */
/* @0xcf224 str lr, [r4, #0x78] */
/* @0xcf228 ldr r3, [r5, r3] */
/* @0xcf22c ldr r3, [r3] */
/* @0xcf230 cmp r3, #0 */
/* @0xcf234 ldreq r3, [r4, #0x10] */
/* @0xcf238 beq 0xcf050 <_ZN5CCodeC2Eib+0x88> */
/* @0xcf23c ldr r3, [r3, r1, lsl #2] */
/* @0xcf240 cmp r3, #0 */
/* @0xcf244 moveq r6, r3 */
/* @0xcf248 moveq r8, #4 */
/* @0xcf24c beq 0xcf264 <_ZN5CCodeC2Eib+0x29c> */
/* @0xcf250 ldr r1, [pc, #0xc0] */
/* @0xcf254 ldr r1, [r5, r1] */
/* @0xcf258 ldr r6, [r1] */
/* @0xcf25c add r6, r6, r3 */
/* @0xcf260 add r8, r6, #4 */
/* @0xcf264 mov r0, #28 */
/* @0xcf268 str r2, [sp] */
/* @0xcf26c bl 0x27c524 <_Znwj> */
/* @0xcf270 ldr r1, [r6] */
/* @0xcf274 mov r3, #0 */
/* @0xcf278 add r7, r7, #8 */
/* @0xcf27c ldr r2, [sp] */
/* @0xcf280 lsl r1, r1, #2 */
/* @0xcf284 str r3, [r0, #0x14] */
/* @0xcf288 str r3, [r0, #0x18] */
/* @0xcf28c str r7, [r0] */
/* @0xcf290 ldr r3, [r4, #0x10] */
/* @0xcf294 str r0, [r4, #0x54] */
/* @0xcf298 str r1, [r0, #0x4] */
/* @0xcf29c str r8, [r0, #0x10] */
/* @0xcf2a0 b 0xcf050 <_ZN5CCodeC2Eib+0x88> */
/* @0xcf2a4 ldrh r9, [r3, #8] */
/* @0xcf2a8 add r8, r3, #8 */
/* @0xcf2ac ldrh lr, [r3, #10] */
/* @0xcf2b0 mov r6, r12 */
/* @0xcf2b4 str r10, [r0, #0x4] */
/* @0xcf2b8 str r9, [r0, #0x8] */
/* @0xcf2bc str lr, [r0, #0xc] */
/* @0xcf2c0 str r8, [r0, #0x10] */
/* @0xcf2c4 str r12, [r4, #0x70] */
/* @0xcf2c8 str r12, [r4, #0x6c] */
/* @0xcf2cc b 0xcf218 <_ZN5CCodeC2Eib+0x250> */
/* @0xcf2d0 ldr lr, [pc, #0x40] */
/* @0xcf2d4 ldr lr, [r5, lr] */
/* @0xcf2d8 ldr lr, [lr] */
/* @0xcf2dc add r12, lr, r12 */
/* @0xcf2e0 b 0xcf1c8 <_ZN5CCodeC2Eib+0x200> */
/* @0xcf2e4 eorseq r2, r2, r0, ror r12 */
/* @0xcf2e8 .word 0xffffbed4 */
/* @0xcf2ec .word 0xffffbecc */
/* @0xcf2f0 .word 0xffffbef0 */
/* @0xcf2f4 eoreq pc, r5, r10, lsl #22 */
/* @0xcf2f8 .word 0xffffbed0 */
/* @0xcf2fc .word 0xffffbed8 */
/* @0xcf300 .word 0xffffbef4 */
/* @0xcf304 eoreq pc, r5, r10, lsr r10 */
/* @0xcf308 .word 0xffffbedc */
/* @0xcf30c .word 0xffffbef8 */
/* @0xcf310 .word 0xffffbcf4 */
/* @0xcf314 .word 0xffffbefc */
/* @0xcf318 .word 0xffffbf00 */
/* @0xcf31c .word 0xffffbf04 */
/* @0xcf320 .word 0xffffbf08 */

/* ── FUNC 0xcefc8 · CCode::CCode(int, bool) · alias of the symbol above · insn=0 */

/* ── FUNC 0xcf324 · Code_CreateEntry(unsigned int, bool) · size=332 · insn=83 */
/* @0xcf324 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xcf328 mov r8, r0 */
/* @0xcf32c ldr r4, [pc, #0x11c] */
/* @0xcf330 sub sp, sp, #8 */
/* @0xcf334 ldr r3, [pc, #0x118] */
/* @0xcf338 mov r9, r1 */
/* @0xcf33c ldr r2, [pc, #0x114] */
/* @0xcf340 add r4, pc, r4 */
/* @0xcf344 ldr r7, [r4, r3] */
/* @0xcf348 ldr r5, [r4, r2] */
/* @0xcf34c ldr r3, [r7] */
/* @0xcf350 ldr r2, [r5] */
/* @0xcf354 cmp r2, r3 */
/* @0xcf358 bge 0xcf3c8 <_Z16Code_CreateEntryjb+0xa4> */
/* @0xcf35c ldr r3, [pc, #0xf8] */
/* @0xcf360 ldr r6, [r4, r3] */
/* @0xcf364 ldr r12, [r6] */
/* @0xcf368 cmp r12, #0 */
/* @0xcf36c beq 0xcf420 <_Z16Code_CreateEntryjb+0xfc> */
/* @0xcf370 ldr r3, [pc, #0xe8] */
/* @0xcf374 ldr r3, [r4, r3] */
/* @0xcf378 ldrb r3, [r3] */
/* @0xcf37c cmp r3, #0 */
/* @0xcf380 beq 0xcf42c <_Z16Code_CreateEntryjb+0x108> */
/* @0xcf384 cmn r8, #1 */
/* @0xcf388 moveq r4, #0 */
/* @0xcf38c beq 0xcf3ac <_Z16Code_CreateEntryjb+0x88> */
/* @0xcf390 mov r0, #124 */
/* @0xcf394 bl 0x27c524 <_Znwj> */
/* @0xcf398 mov r1, r8 */
/* @0xcf39c mov r2, r9 */
/* @0xcf3a0 mov r4, r0 */
/* @0xcf3a4 bl 0xcefc8 <_ZN5CCodeC2Eib> */
/* @0xcf3a8 ldr r12, [r6] */
/* @0xcf3ac ldr r3, [r5] */
/* @0xcf3b0 add r2, r3, #1 */
/* @0xcf3b4 str r4, [r12, r3, lsl #2] */
/* @0xcf3b8 mov r0, r3 */
/* @0xcf3bc str r2, [r5] */
/* @0xcf3c0 add sp, sp, #8 */
/* @0xcf3c4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xcf3c8 add r3, r3, r3, lsl #1 */
/* @0xcf3cc add r10, r3, #1 */
/* @0xcf3d0 add r10, r10, r10, lsr #31 */
/* @0xcf3d4 asrs r10, r10, #1 */
/* @0xcf3d8 ldreq r3, [pc, #0x84] */
/* @0xcf3dc ldreq r3, [r4, r3] */
/* @0xcf3e0 ldreq r10, [r3] */
/* @0xcf3e4 ldr r0, [pc, #0x70] */
/* @0xcf3e8 mov r12, #0 */
/* @0xcf3ec ldr r2, [pc, #0x74] */
/* @0xcf3f0 lsl r1, r10, #2 */
/* @0xcf3f4 mov r3, #74 */
/* @0xcf3f8 ldr r6, [r4, r0] */
/* @0xcf3fc add r2, pc, r2 */
/* @0xcf400 ldr r0, [r6] */
/* @0xcf404 str r12, [sp] */
/* @0xcf408 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xcf40c str r10, [r7] */
/* @0xcf410 mov r12, r0 */
/* @0xcf414 cmp r12, #0 */
/* @0xcf418 str r0, [r6] */
/* @0xcf41c bne 0xcf370 <_Z16Code_CreateEntryjb+0x4c> */
/* @0xcf420 mov r0, r12 */
/* @0xcf424 add sp, sp, #8 */
/* @0xcf428 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xcf42c ldr r3, [pc, #0x38] */
/* @0xcf430 ldr r3, [r4, r3] */
/* @0xcf434 ldrb r4, [r3] */
/* @0xcf438 cmp r4, #0 */
/* @0xcf43c beq 0xcf3ac <_Z16Code_CreateEntryjb+0x88> */
/* @0xcf440 cmn r8, #1 */
/* @0xcf444 moveq r4, #0 */
/* @0xcf448 bne 0xcf390 <_Z16Code_CreateEntryjb+0x6c> */
/* @0xcf44c b 0xcf3ac <_Z16Code_CreateEntryjb+0x88> */
/* @0xcf450 eorseq r2, r2, r0, lsl r9 */
/* @0xcf454 .word 0xffffbf0c */
/* @0xcf458 .word 0xffffbee4 */
/* @0xcf45c .word 0xffffbee8 */
/* @0xcf460 .word 0xffffbf10 */
/* @0xcf464 .word 0xffffbef4 */
/* @0xcf468 eoreq r1, r6, r4, lsr r12 */
/* @0xcf46c .word 0xffffbecc */

/* ── FUNC 0xcf470 · CCode::GetText() · size=8 · insn=2 */
/* @0xcf470 ldr r0, [r0, #0x10] */
/* @0xcf474 bx lr */

/* ── FUNC 0xcf478 · FINALIZE_Code_Main() · size=4 · insn=1 */
/* @0xcf478 bx lr */

/* ── FUNC 0xcf47c · RValue::Serialise(IBuffer*) · size=616 · insn=154 */
/* @0xcf47c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xcf480 add r8, r1, #44 */
/* @0xcf484 ldr r4, [r0, #0xc] */
/* @0xcf488 mov r6, r1 */
/* @0xcf48c ldr r3, [r1] */
/* @0xcf490 mov r7, r0 */
/* @0xcf494 mov r1, #0 */
/* @0xcf498 mov r2, r8 */
/* @0xcf49c vmov s15, r4 */
/* @0xcf4a0 str r1, [r6, #0x38] */
/* @0xcf4a4 mov r0, r6 */
/* @0xcf4a8 mov r1, #6 */
/* @0xcf4ac vcvt.f64.s32 d7, s15 */
/* @0xcf4b0 vmov r4, r5, d7 */
/* @0xcf4b4 vstr s14, [r6, #44] */
/* @0xcf4b8 str r5, [r6, #0x30] */
/* @0xcf4bc ldr r3, [r3, #0x8] */
/* @0xcf4c0 blx r3 */
/* @0xcf4c4 ldr r3, [r7, #0xc] */
/* @0xcf4c8 cmp r3, #13 */
/* @0xcf4cc addls pc, pc, r3, lsl #2 */
/* @0xcf4d0 b 0xcf50c <_ZN6RValue9SerialiseEP7IBuffer+0x90> */
/* @0xcf4d4 b 0xcf544 <_ZN6RValue9SerialiseEP7IBuffer+0xc8> */
/* @0xcf4d8 b 0xcf578 <_ZN6RValue9SerialiseEP7IBuffer+0xfc> */
/* @0xcf4dc b 0xcf594 <_ZN6RValue9SerialiseEP7IBuffer+0x118> */
/* @0xcf4e0 b 0xcf670 <_ZN6RValue9SerialiseEP7IBuffer+0x1f4> */
/* @0xcf4e4 b 0xcf50c <_ZN6RValue9SerialiseEP7IBuffer+0x90> */
/* @0xcf4e8 b 0xcf50c <_ZN6RValue9SerialiseEP7IBuffer+0x90> */
/* @0xcf4ec b 0xcf50c <_ZN6RValue9SerialiseEP7IBuffer+0x90> */
/* @0xcf4f0 b 0xcf6a8 <_ZN6RValue9SerialiseEP7IBuffer+0x22c> */
/* @0xcf4f4 b 0xcf50c <_ZN6RValue9SerialiseEP7IBuffer+0x90> */
/* @0xcf4f8 b 0xcf50c <_ZN6RValue9SerialiseEP7IBuffer+0x90> */
/* @0xcf4fc b 0xcf510 <_ZN6RValue9SerialiseEP7IBuffer+0x94> */
/* @0xcf500 b 0xcf50c <_ZN6RValue9SerialiseEP7IBuffer+0x90> */
/* @0xcf504 b 0xcf50c <_ZN6RValue9SerialiseEP7IBuffer+0x90> */
/* @0xcf508 b 0xcf544 <_ZN6RValue9SerialiseEP7IBuffer+0xc8> */
/* @0xcf50c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xcf510 ldr r1, [r7] */
/* @0xcf514 mov r12, #10 */
/* @0xcf518 ldr lr, [r7, #0x4] */
/* @0xcf51c mov r2, r8 */
/* @0xcf520 ldr r3, [r6] */
/* @0xcf524 mov r0, r6 */
/* @0xcf528 str r1, [r6, #0x2c] */
/* @0xcf52c mov r1, #12 */
/* @0xcf530 str lr, [r6, #0x30] */
/* @0xcf534 str r12, [r6, #0x38] */
/* @0xcf538 ldr r3, [r3, #0x8] */
/* @0xcf53c blx r3 */
/* @0xcf540 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xcf544 ldr r1, [r7] */
/* @0xcf548 mov r12, #0 */
/* @0xcf54c ldr lr, [r7, #0x4] */
/* @0xcf550 mov r2, r8 */
/* @0xcf554 ldr r3, [r6] */
/* @0xcf558 mov r0, r6 */
/* @0xcf55c str r1, [r6, #0x2c] */
/* @0xcf560 mov r1, #9 */
/* @0xcf564 str lr, [r6, #0x30] */
/* @0xcf568 str r12, [r6, #0x38] */
/* @0xcf56c ldr r3, [r3, #0x8] */
/* @0xcf570 blx r3 */
/* @0xcf574 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xcf578 ldr r3, [r7] */
/* @0xcf57c mov r0, r6 */
/* @0xcf580 cmp r3, #0 */
/* @0xcf584 ldrne r1, [r3] */
/* @0xcf588 moveq r1, r3 */
/* @0xcf58c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xcf590 b 0xcddb8 <_ZN7IBuffer5WriteEPKc> */
/* @0xcf594 ldr r3, [r7] */
/* @0xcf598 cmp r3, #0 */
/* @0xcf59c popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xcf5a0 ldr r4, [r3, #0x10] */
/* @0xcf5a4 mov r9, #0 */
/* @0xcf5a8 ldr r3, [r6] */
/* @0xcf5ac mov r2, r8 */
/* @0xcf5b0 mov r0, r6 */
/* @0xcf5b4 str r9, [r6, #0x38] */
/* @0xcf5b8 vmov s15, r4 */
/* @0xcf5bc mov r1, #6 */
/* @0xcf5c0 vcvt.f64.s32 d7, s15 */
/* @0xcf5c4 vmov r4, r5, d7 */
/* @0xcf5c8 vstr s14, [r6, #44] */
/* @0xcf5cc str r5, [r6, #0x30] */
/* @0xcf5d0 ldr r3, [r3, #0x8] */
/* @0xcf5d4 blx r3 */
/* @0xcf5d8 ldr r3, [r7] */
/* @0xcf5dc ldr r2, [r3, #0x10] */
/* @0xcf5e0 cmp r2, r9 */
/* @0xcf5e4 pople {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xcf5e8 ldr r10, [r3, #0x4] */
/* @0xcf5ec mov r0, r6 */
/* @0xcf5f0 ldr r12, [r6] */
/* @0xcf5f4 mov r3, #0 */
/* @0xcf5f8 mov r1, #6 */
/* @0xcf5fc mov r2, r8 */
/* @0xcf600 ldr r4, [r10, r9, lsl #3] */
/* @0xcf604 add r11, r10, r9, lsl #3 */
/* @0xcf608 str r3, [r6, #0x38] */
/* @0xcf60c vmov s15, r4 */
/* @0xcf610 vcvt.f64.s32 d7, s15 */
/* @0xcf614 vmov r4, r5, d7 */
/* @0xcf618 vstr s14, [r6, #44] */
/* @0xcf61c str r5, [r6, #0x30] */
/* @0xcf620 ldr r12, [r12, #0x8] */
/* @0xcf624 blx r12 */
/* @0xcf628 ldr r3, [r10, r9, lsl #3] */
/* @0xcf62c cmp r3, #0 */
/* @0xcf630 movgt r4, #0 */
/* @0xcf634 ble 0xcf658 <_ZN6RValue9SerialiseEP7IBuffer+0x1dc> */
/* @0xcf638 ldr r0, [r11, #0x4] */
/* @0xcf63c mov r1, r6 */
/* @0xcf640 add r0, r0, r4, lsl #4 */
/* @0xcf644 add r4, r4, #1 */
/* @0xcf648 bl 0xcf47c <_ZN6RValue9SerialiseEP7IBuffer> */
/* @0xcf64c ldr r3, [r11] */
/* @0xcf650 cmp r3, r4 */
/* @0xcf654 bgt 0xcf638 <_ZN6RValue9SerialiseEP7IBuffer+0x1bc> */
/* @0xcf658 ldr r3, [r7] */
/* @0xcf65c add r9, r9, #1 */
/* @0xcf660 ldr r2, [r3, #0x10] */
/* @0xcf664 cmp r2, r9 */
/* @0xcf668 bgt 0xcf5e8 <_ZN6RValue9SerialiseEP7IBuffer+0x16c> */
/* @0xcf66c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xcf670 ldr r3, [r7] */
/* @0xcf674 mov r1, #10 */
/* @0xcf678 ldr r12, [r6] */
/* @0xcf67c mov r2, r8 */
/* @0xcf680 str r1, [r6, #0x38] */
/* @0xcf684 mov r0, r6 */
/* @0xcf688 asr r5, r3, #31 */
/* @0xcf68c mov r4, r3 */
/* @0xcf690 str r3, [r6, #0x2c] */
/* @0xcf694 mov r1, #12 */
/* @0xcf698 str r5, [r6, #0x30] */
/* @0xcf69c ldr r3, [r12, #0x8] */
/* @0xcf6a0 blx r3 */
/* @0xcf6a4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xcf6a8 ldr r4, [r7] */
/* @0xcf6ac mov r1, #0 */
/* @0xcf6b0 ldr r3, [r6] */
/* @0xcf6b4 mov r2, r8 */
/* @0xcf6b8 str r1, [r6, #0x38] */
/* @0xcf6bc mov r0, r6 */
/* @0xcf6c0 vmov s15, r4 */
/* @0xcf6c4 mov r1, #6 */
/* @0xcf6c8 vcvt.f64.s32 d7, s15 */
/* @0xcf6cc vmov r4, r5, d7 */
/* @0xcf6d0 vstr s14, [r6, #44] */
/* @0xcf6d4 str r5, [r6, #0x30] */
/* @0xcf6d8 ldr r3, [r3, #0x8] */
/* @0xcf6dc blx r3 */
/* @0xcf6e0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0xcf6e4 · RValue::DeSerialise(IBuffer*) · size=560 · insn=140 */
/* @0xcf6e4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xcf6e8 mov r4, #0 */
/* @0xcf6ec str r4, [r0] */
/* @0xcf6f0 add r9, r1, #44 */
/* @0xcf6f4 str r4, [r0, #0x4] */
/* @0xcf6f8 mov r8, r0 */
/* @0xcf6fc ldr r3, [r1] */
/* @0xcf700 mov r0, r1 */
/* @0xcf704 mov r2, r9 */
/* @0xcf708 mov r6, r1 */
/* @0xcf70c mov r1, #6 */
/* @0xcf710 ldr r3, [r3, #0xc] */
/* @0xcf714 blx r3 */
/* @0xcf718 mov r0, r9 */
/* @0xcf71c mov r1, r4 */
/* @0xcf720 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xcf724 str r0, [r8, #0xc] */
/* @0xcf728 cmp r0, #13 */
/* @0xcf72c addls pc, pc, r0, lsl #2 */
/* @0xcf730 b 0xcf76c <_ZN6RValue11DeSerialiseEP7IBuffer+0x88> */
/* @0xcf734 b 0xcf798 <_ZN6RValue11DeSerialiseEP7IBuffer+0xb4> */
/* @0xcf738 b 0xcf7ac <_ZN6RValue11DeSerialiseEP7IBuffer+0xc8> */
/* @0xcf73c b 0xcf7c4 <_ZN6RValue11DeSerialiseEP7IBuffer+0xe0> */
/* @0xcf740 b 0xcf8c0 <_ZN6RValue11DeSerialiseEP7IBuffer+0x1dc> */
/* @0xcf744 b 0xcf76c <_ZN6RValue11DeSerialiseEP7IBuffer+0x88> */
/* @0xcf748 b 0xcf76c <_ZN6RValue11DeSerialiseEP7IBuffer+0x88> */
/* @0xcf74c b 0xcf76c <_ZN6RValue11DeSerialiseEP7IBuffer+0x88> */
/* @0xcf750 b 0xcf8e4 <_ZN6RValue11DeSerialiseEP7IBuffer+0x200> */
/* @0xcf754 b 0xcf76c <_ZN6RValue11DeSerialiseEP7IBuffer+0x88> */
/* @0xcf758 b 0xcf76c <_ZN6RValue11DeSerialiseEP7IBuffer+0x88> */
/* @0xcf75c b 0xcf770 <_ZN6RValue11DeSerialiseEP7IBuffer+0x8c> */
/* @0xcf760 b 0xcf76c <_ZN6RValue11DeSerialiseEP7IBuffer+0x88> */
/* @0xcf764 b 0xcf76c <_ZN6RValue11DeSerialiseEP7IBuffer+0x88> */
/* @0xcf768 b 0xcf798 <_ZN6RValue11DeSerialiseEP7IBuffer+0xb4> */
/* @0xcf76c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xcf770 ldr r3, [r6] */
/* @0xcf774 mov r2, r9 */
/* @0xcf778 mov r0, r6 */
/* @0xcf77c mov r1, #12 */
/* @0xcf780 ldr r3, [r3, #0xc] */
/* @0xcf784 blx r3 */
/* @0xcf788 ldr r2, [r6, #0x2c] */
/* @0xcf78c ldr r3, [r6, #0x30] */
/* @0xcf790 stm r8, {r2, r3} */
/* @0xcf794 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xcf798 ldr r3, [r6] */
/* @0xcf79c mov r2, r9 */
/* @0xcf7a0 mov r0, r6 */
/* @0xcf7a4 mov r1, #9 */
/* @0xcf7a8 b 0xcf780 <_ZN6RValue11DeSerialiseEP7IBuffer+0x9c> */
/* @0xcf7ac mov r0, r6 */
/* @0xcf7b0 bl 0xcde74 <_ZN7IBuffer10ReadStringEv> */
/* @0xcf7b4 mov r1, r0 */
/* @0xcf7b8 mov r0, r8 */
/* @0xcf7bc pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xcf7c0 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0xcf7c4 mov r0, r8 */
/* @0xcf7c8 ldr r10, [pc, #0x140] */
/* @0xcf7cc bl 0xced9c <_Z14ARRAY_RefAllocPv> */
/* @0xcf7d0 mov r2, r9 */
/* @0xcf7d4 mov r1, #6 */
/* @0xcf7d8 add r10, pc, r10 */
/* @0xcf7dc str r0, [r8] */
/* @0xcf7e0 mov r4, r0 */
/* @0xcf7e4 ldr r3, [r6] */
/* @0xcf7e8 mov r0, r6 */
/* @0xcf7ec ldr r3, [r3, #0xc] */
/* @0xcf7f0 blx r3 */
/* @0xcf7f4 mov r1, #0 */
/* @0xcf7f8 mov r0, r9 */
/* @0xcf7fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xcf800 mov r2, r10 */
/* @0xcf804 movw r3, #0x766 */
/* @0xcf808 str r0, [r4, #0x10] */
/* @0xcf80c ldr r1, [r8] */
/* @0xcf810 add r0, r1, #4 */
/* @0xcf814 ldr r1, [r1, #0x10] */
/* @0xcf818 lsl r1, r1, #3 */
/* @0xcf81c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xcf820 ldr r3, [r8] */
/* @0xcf824 ldr r2, [r3, #0x10] */
/* @0xcf828 cmp r2, #0 */
/* @0xcf82c pople {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xcf830 mov r7, #0 */
/* @0xcf834 ldr r12, [r6] */
/* @0xcf838 mov r2, r9 */
/* @0xcf83c ldr r4, [r3, #0x4] */
/* @0xcf840 mov r1, #6 */
/* @0xcf844 mov r0, r6 */
/* @0xcf848 ldr r3, [r12, #0xc] */
/* @0xcf84c add r5, r4, r7, lsl #3 */
/* @0xcf850 blx r3 */
/* @0xcf854 mov r1, #0 */
/* @0xcf858 mov r0, r9 */
/* @0xcf85c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xcf860 movw r3, #0x76c */
/* @0xcf864 mov r2, r10 */
/* @0xcf868 str r0, [r4, r7, lsl #3] */
/* @0xcf86c lsl r1, r0, #4 */
/* @0xcf870 add r0, r5, #4 */
/* @0xcf874 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xcf878 ldr r3, [r4, r7, lsl #3] */
/* @0xcf87c cmp r3, #0 */
/* @0xcf880 movgt r4, #0 */
/* @0xcf884 ble 0xcf8a8 <_ZN6RValue11DeSerialiseEP7IBuffer+0x1c4> */
/* @0xcf888 ldr r0, [r5, #0x4] */
/* @0xcf88c mov r1, r6 */
/* @0xcf890 add r0, r0, r4, lsl #4 */
/* @0xcf894 add r4, r4, #1 */
/* @0xcf898 bl 0xcf6e4 <_ZN6RValue11DeSerialiseEP7IBuffer> */
/* @0xcf89c ldr r3, [r5] */
/* @0xcf8a0 cmp r3, r4 */
/* @0xcf8a4 bgt 0xcf888 <_ZN6RValue11DeSerialiseEP7IBuffer+0x1a4> */
/* @0xcf8a8 ldr r3, [r8] */
/* @0xcf8ac add r7, r7, #1 */
/* @0xcf8b0 ldr r2, [r3, #0x10] */
/* @0xcf8b4 cmp r2, r7 */
/* @0xcf8b8 bgt 0xcf834 <_ZN6RValue11DeSerialiseEP7IBuffer+0x150> */
/* @0xcf8bc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xcf8c0 ldr r3, [r6] */
/* @0xcf8c4 mov r2, r9 */
/* @0xcf8c8 mov r0, r6 */
/* @0xcf8cc mov r1, #12 */
/* @0xcf8d0 ldr r3, [r3, #0xc] */
/* @0xcf8d4 blx r3 */
/* @0xcf8d8 ldr r3, [r6, #0x2c] */
/* @0xcf8dc str r3, [r8] */
/* @0xcf8e0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xcf8e4 ldr r3, [r6] */
/* @0xcf8e8 mov r1, #6 */
/* @0xcf8ec mov r2, r9 */
/* @0xcf8f0 mov r0, r6 */
/* @0xcf8f4 ldr r3, [r3, #0xc] */
/* @0xcf8f8 blx r3 */
/* @0xcf8fc mov r0, r9 */
/* @0xcf900 mov r1, #0 */
/* @0xcf904 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xcf908 str r0, [r8] */
/* @0xcf90c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xcf910 eoreq r2, r6, r4, lsr #20 */

/* ── FUNC 0xcf914 · ExecuteIt(CInstance*, CInstance*, CCode*, RValue*, int) · size=844 · insn=211 */
/* @0xcf914 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xcf918 mov r4, r2 */
/* @0xcf91c ldr r6, [pc, #0x32c] */
/* @0xcf920 mov r5, r3 */
/* @0xcf924 ldr r2, [pc, #0x328] */
/* @0xcf928 mov r7, #0 */
/* @0xcf92c add r6, pc, r6 */
/* @0xcf930 ldr r12, [r4, #0x8] */
/* @0xcf934 sub sp, sp, #28 */
/* @0xcf938 mov r8, r0 */
/* @0xcf93c ldr r3, [r6, r2] */
/* @0xcf940 cmp r12, #1 */
/* @0xcf944 mov r9, r1 */
/* @0xcf948 strb r7, [r3] */
/* @0xcf94c blt 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> */
/* @0xcf950 cmp r12, #2 */
/* @0xcf954 ble 0xcfa30 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x11c> */
/* @0xcf958 cmp r12, #3 */
/* @0xcf95c bne 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> */
/* @0xcf960 ldr r2, [r5, #0xc] */
/* @0xcf964 bic r3, r2, #-16777216 */
/* @0xcf968 cmp r3, #1 */
/* @0xcf96c beq 0xcfaec <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1d8> */
/* @0xcf970 cmp r3, #2 */
/* @0xcf974 bne 0xcf99c <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x88> */
/* @0xcf978 sub r2, r2, #1 */
/* @0xcf97c bic r2, r2, #-16777216 */
/* @0xcf980 bic r2, r2, #3 */
/* @0xcf984 cmp r2, #0 */
/* @0xcf988 beq 0xcfb9c <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x288> */
/* @0xcf98c mov r2, #0 */
/* @0xcf990 mov r3, #5 */
/* @0xcf994 str r2, [r5, #0x8] */
/* @0xcf998 str r3, [r5, #0xc] */
/* @0xcf99c ldr r3, [r4, #0x4c] */
/* @0xcf9a0 mov r1, #0 */
/* @0xcf9a4 ldr r2, [r4, #0x48] */
/* @0xcf9a8 str r1, [r5] */
/* @0xcf9ac str r3, [r5, #0xc] */
/* @0xcf9b0 ldr r3, [r4, #0x4c] */
/* @0xcf9b4 str r2, [r5, #0x8] */
/* @0xcf9b8 bic r3, r3, #-16777216 */
/* @0xcf9bc cmp r3, #14 */
/* @0xcf9c0 addls pc, pc, r3, lsl #2 */
/* @0xcf9c4 b 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> */
/* @0xcf9c8 b 0xcfadc <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1c8> */
/* @0xcf9cc b 0xcfb20 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x20c> */
/* @0xcf9d0 b 0xcfb38 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x224> */
/* @0xcf9d4 b 0xcfac8 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1b4> */
/* @0xcf9d8 b 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> */
/* @0xcf9dc b 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> */
/* @0xcf9e0 b 0xcfa04 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0xf0> */
/* @0xcf9e4 b 0xcfac8 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1b4> */
/* @0xcf9e8 b 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> */
/* @0xcf9ec b 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> */
/* @0xcf9f0 b 0xcfadc <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1c8> */
/* @0xcf9f4 b 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> */
/* @0xcf9f8 b 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> */
/* @0xcf9fc b 0xcfadc <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1c8> */
/* @0xcfa00 b 0xcfac8 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1b4> */
/* @0xcfa04 ldr r3, [r4, #0x40] */
/* @0xcfa08 str r3, [r5] */
/* @0xcfa0c ldr r3, [r4, #0x40] */
/* @0xcfa10 cmp r3, #0 */
/* @0xcfa14 beq 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> */
/* @0xcfa18 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xcfa1c ldr r1, [r4, #0x40] */
/* @0xcfa20 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xcfa24 mov r0, #1 */
/* @0xcfa28 add sp, sp, #28 */
/* @0xcfa2c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xcfa30 ldr r3, [r4, #0x64] */
/* @0xcfa34 cmp r3, #0 */
/* @0xcfa38 beq 0xcfa50 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x13c> */
/* @0xcfa3c ldr r3, [r3, #0x4] */
/* @0xcfa40 blx r3 */
/* @0xcfa44 mov r0, #1 */
/* @0xcfa48 add sp, sp, #28 */
/* @0xcfa4c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xcfa50 ldr r3, [r4, #0x50] */
/* @0xcfa54 cmp r3, #0 */
/* @0xcfa58 beq 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> */
/* @0xcfa5c ldr r3, [r3, #0x4] */
/* @0xcfa60 cmp r3, #0 */
/* @0xcfa64 ble 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> */
/* @0xcfa68 ldr r3, [pc, #0x1e8] */
/* @0xcfa6c ldr r7, [r6, r3] */
/* @0xcfa70 ldrb r3, [r7] */
/* @0xcfa74 cmp r3, #0 */
/* @0xcfa78 bne 0xcfba8 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x294> */
/* @0xcfa7c ldr r3, [sp, #0x38] */
/* @0xcfa80 mov r12, #0 */
/* @0xcfa84 mov r0, r4 */
/* @0xcfa88 mov r1, r8 */
/* @0xcfa8c mov r2, r9 */
/* @0xcfa90 str r12, [sp] */
/* @0xcfa94 str r3, [sp, #0xc] */
/* @0xcfa98 mov r3, r5 */
/* @0xcfa9c str r12, [sp, #0x4] */
/* @0xcfaa0 str r12, [sp, #0x8] */
/* @0xcfaa4 str r12, [sp, #0x10] */
/* @0xcfaa8 bl 0xe7fd0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_> */
/* @0xcfaac ldrb r3, [r7] */
/* @0xcfab0 cmp r3, #0 */
/* @0xcfab4 beq 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> */
/* @0xcfab8 ldr r3, [pc, #0x19c] */
/* @0xcfabc ldr r0, [r6, r3] */
/* @0xcfac0 bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0xcfac4 b 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> */
/* @0xcfac8 ldr r3, [r4, #0x40] */
/* @0xcfacc mov r0, #1 */
/* @0xcfad0 str r3, [r5] */
/* @0xcfad4 add sp, sp, #28 */
/* @0xcfad8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xcfadc ldr r2, [r4, #0x40] */
/* @0xcfae0 ldr r3, [r4, #0x44] */
/* @0xcfae4 stm r5, {r2, r3} */
/* @0xcfae8 b 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> */
/* @0xcfaec ldr r6, [r5] */
/* @0xcfaf0 cmp r6, #0 */
/* @0xcfaf4 beq 0xcfb14 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x200> */
/* @0xcfaf8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xcfafc ldr r7, [r6, #0x4] */
/* @0xcfb00 sub r7, r7, #1 */
/* @0xcfb04 str r7, [r6, #0x4] */
/* @0xcfb08 cmp r7, #0 */
/* @0xcfb0c beq 0xcfb64 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x250> */
/* @0xcfb10 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xcfb14 mov r3, #0 */
/* @0xcfb18 str r3, [r5] */
/* @0xcfb1c b 0xcf99c <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x88> */
/* @0xcfb20 ldr r3, [r4, #0x40] */
/* @0xcfb24 cmp r3, #0 */
/* @0xcfb28 ldrne r2, [r3, #0x4] */
/* @0xcfb2c addne r2, r2, #1 */
/* @0xcfb30 strne r2, [r3, #0x4] */
/* @0xcfb34 b 0xcfacc <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1b8> */
/* @0xcfb38 ldr r3, [r4, #0x40] */
/* @0xcfb3c cmp r3, #0 */
/* @0xcfb40 str r3, [r5] */
/* @0xcfb44 beq 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> */
/* @0xcfb48 ldr r1, [r3, #0x8] */
/* @0xcfb4c ldr r2, [r3] */
/* @0xcfb50 cmp r1, #0 */
/* @0xcfb54 streq r5, [r3, #0x8] */
/* @0xcfb58 add r2, r2, #1 */
/* @0xcfb5c str r2, [r3] */
/* @0xcfb60 b 0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> */
/* @0xcfb64 ldr r0, [r6] */
/* @0xcfb68 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xcfb6c str r7, [r6] */
/* @0xcfb70 str r7, [r6, #0x8] */
/* @0xcfb74 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xcfb78 ldr r7, [r6, #0x4] */
/* @0xcfb7c sub r7, r7, #1 */
/* @0xcfb80 str r7, [r6, #0x4] */
/* @0xcfb84 cmp r7, #0 */
/* @0xcfb88 beq 0xcfbc0 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x2ac> */
/* @0xcfb8c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xcfb90 mov r0, r6 */
/* @0xcfb94 bl 0x27d1d0 <_ZdlPv> */
/* @0xcfb98 b 0xcfb10 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1fc> */
/* @0xcfb9c mov r0, r5 */
/* @0xcfba0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xcfba4 b 0xcf98c <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x78> */
/* @0xcfba8 ldr r3, [pc, #0xac] */
/* @0xcfbac mov r1, #1 */
/* @0xcfbb0 ldr r2, [r4, #0x60] */
/* @0xcfbb4 ldr r0, [r6, r3] */
/* @0xcfbb8 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0xcfbbc b 0xcfa7c <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x168> */
/* @0xcfbc0 ldr r0, [r6] */
/* @0xcfbc4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xcfbc8 str r7, [r6] */
/* @0xcfbcc str r7, [r6, #0x8] */
/* @0xcfbd0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xcfbd4 ldr r7, [r6, #0x4] */
/* @0xcfbd8 sub r7, r7, #1 */
/* @0xcfbdc str r7, [r6, #0x4] */
/* @0xcfbe0 cmp r7, #0 */
/* @0xcfbe4 beq 0xcfbf8 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x2e4> */
/* @0xcfbe8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xcfbec mov r0, r6 */
/* @0xcfbf0 bl 0x27d1d0 <_ZdlPv> */
/* @0xcfbf4 b 0xcfb8c <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x278> */
/* @0xcfbf8 ldr r0, [r6] */
/* @0xcfbfc bl 0xcef90 <_Z6YYFreePKv> */
/* @0xcfc00 str r7, [r6] */
/* @0xcfc04 str r7, [r6, #0x8] */
/* @0xcfc08 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xcfc0c ldr r7, [r6, #0x4] */
/* @0xcfc10 sub r7, r7, #1 */
/* @0xcfc14 str r7, [r6, #0x4] */
/* @0xcfc18 cmp r7, #0 */
/* @0xcfc1c bne 0xcfc40 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x32c> */
/* @0xcfc20 ldr r0, [r6] */
/* @0xcfc24 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xcfc28 mov r0, r6 */
/* @0xcfc2c str r7, [r6] */
/* @0xcfc30 str r7, [r6, #0x8] */
/* @0xcfc34 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xcfc38 mov r0, r6 */
/* @0xcfc3c bl 0x27d1d0 <_ZdlPv> */
/* @0xcfc40 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xcfc44 mov r0, r6 */
/* @0xcfc48 bl 0x27d1d0 <_ZdlPv> */
/* @0xcfc4c b 0xcfbe8 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x2d4> */
/* @0xcfc50 eorseq r2, r2, r4, lsr #6 */
/* @0xcfc54 .word 0xffffbf14 */
/* @0xcfc58 .word 0xffffbf18 */
/* @0xcfc5c .word 0xffffbf1c */

/* ── FUNC 0xcfc60 · Code_Execute(CInstance*, CInstance*, CCode*, RValue*, int) · size=84 · insn=21 */
/* @0xcfc60 push {r4, lr} */
/* @0xcfc64 sub sp, sp, #8 */
/* @0xcfc68 ldr r12, [sp, #0x10] */
/* @0xcfc6c str r12, [sp] */
/* @0xcfc70 bl 0xcf914 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei> */
/* @0xcfc74 subs r4, r0, #0 */
/* @0xcfc78 bne 0xcfca0 <_Z12Code_ExecuteP9CInstanceS0_P5CCodeP6RValuei+0x40> */
/* @0xcfc7c ldr r3, [pc, #0x28] */
/* @0xcfc80 mov r1, r4 */
/* @0xcfc84 ldr r3, [pc, r3] */
/* @0xcfc88 ldr r3, [r3] */
/* @0xcfc8c ldr r0, [r3] */
/* @0xcfc90 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xcfc94 ldr r3, [pc, #0x14] */
/* @0xcfc98 ldr r3, [pc, r3] */
/* @0xcfc9c strb r4, [r3] */
/* @0xcfca0 mov r0, r4 */
/* @0xcfca4 add sp, sp, #8 */
/* @0xcfca8 pop {r4, pc} */
/* @0xcfcac eorseq sp, r1, r12, ror #29 */
/* @0xcfcb0 eorseq sp, r1, r12, asr #29 */

/* ── FUNC 0xcfcb4 · SET_RValue_Array(RValue*, RValue*, int) · size=708 · insn=177 */
/* @0xcfcb4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xcfcb8 mov r4, r0 */
/* @0xcfcbc ldr r0, [pc, #0x290] */
/* @0xcfcc0 sub sp, sp, #12 */
/* @0xcfcc4 mov r5, r2 */
/* @0xcfcc8 mov r6, r1 */
/* @0xcfccc add r0, pc, r0 */
/* @0xcfcd0 ldr r8, [pc, #0x280] */
/* @0xcfcd4 bl 0x27b948 <_Z17memLogPushContextPKc> */
/* @0xcfcd8 ldr r7, [r4] */
/* @0xcfcdc mov r1, r5 */
/* @0xcfce0 mov r0, sp */
/* @0xcfce4 mov r2, #32000 */
/* @0xcfce8 add r8, pc, r8 */
/* @0xcfcec bl 0xb664c <ldiv@plt> */
/* @0xcfcf0 ldr r3, [r7, #0x10] */
/* @0xcfcf4 ldr r5, [sp] */
/* @0xcfcf8 ldr r4, [sp, #0x4] */
/* @0xcfcfc cmp r3, r5 */
/* @0xcfd00 ble 0xcfe2c <_Z16SET_RValue_ArrayP6RValueS0_i+0x178> */
/* @0xcfd04 cmp r5, #0 */
/* @0xcfd08 blt 0xcfe54 <_Z16SET_RValue_ArrayP6RValueS0_i+0x1a0> */
/* @0xcfd0c ldr r3, [r7, #0x4] */
/* @0xcfd10 cmp r4, #0 */
/* @0xcfd14 add r9, r3, r5, lsl #3 */
/* @0xcfd18 blt 0xcfdbc <_Z16SET_RValue_ArrayP6RValueS0_i+0x108> */
/* @0xcfd1c ldr r3, [r9] */
/* @0xcfd20 cmp r3, r4 */
/* @0xcfd24 ble 0xcfe64 <_Z16SET_RValue_ArrayP6RValueS0_i+0x1b0> */
/* @0xcfd28 ldr r7, [r9, #0x4] */
/* @0xcfd2c add r5, r7, r4, lsl #4 */
/* @0xcfd30 ldr r3, [r5, #0xc] */
/* @0xcfd34 sub r3, r3, #1 */
/* @0xcfd38 bic r3, r3, #-16777216 */
/* @0xcfd3c bic r3, r3, #3 */
/* @0xcfd40 cmp r3, #0 */
/* @0xcfd44 beq 0xcff48 <_Z16SET_RValue_ArrayP6RValueS0_i+0x294> */
/* @0xcfd48 mov r3, #5 */
/* @0xcfd4c str r3, [r5, #0xc] */
/* @0xcfd50 ldr r1, [r6, #0xc] */
/* @0xcfd54 mov r3, #0 */
/* @0xcfd58 str r3, [r5, #0x8] */
/* @0xcfd5c str r3, [r7, r4, lsl #4] */
/* @0xcfd60 ldr r2, [r6, #0x8] */
/* @0xcfd64 str r1, [r5, #0xc] */
/* @0xcfd68 ldr r3, [r6, #0xc] */
/* @0xcfd6c str r2, [r5, #0x8] */
/* @0xcfd70 bic r3, r3, #-16777216 */
/* @0xcfd74 cmp r3, #14 */
/* @0xcfd78 addls pc, pc, r3, lsl #2 */
/* @0xcfd7c b 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158> */
/* @0xcfd80 b 0xcfe88 <_Z16SET_RValue_ArrayP6RValueS0_i+0x1d4> */
/* @0xcfd84 b 0xcff04 <_Z16SET_RValue_ArrayP6RValueS0_i+0x250> */
/* @0xcfd88 b 0xcff1c <_Z16SET_RValue_ArrayP6RValueS0_i+0x268> */
/* @0xcfd8c b 0xcfe18 <_Z16SET_RValue_ArrayP6RValueS0_i+0x164> */
/* @0xcfd90 b 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158> */
/* @0xcfd94 b 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158> */
/* @0xcfd98 b 0xcfee0 <_Z16SET_RValue_ArrayP6RValueS0_i+0x22c> */
/* @0xcfd9c b 0xcfe18 <_Z16SET_RValue_ArrayP6RValueS0_i+0x164> */
/* @0xcfda0 b 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158> */
/* @0xcfda4 b 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158> */
/* @0xcfda8 b 0xcfe88 <_Z16SET_RValue_ArrayP6RValueS0_i+0x1d4> */
/* @0xcfdac b 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158> */
/* @0xcfdb0 b 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158> */
/* @0xcfdb4 b 0xcfe88 <_Z16SET_RValue_ArrayP6RValueS0_i+0x1d4> */
/* @0xcfdb8 b 0xcfe18 <_Z16SET_RValue_ArrayP6RValueS0_i+0x164> */
/* @0xcfdbc cmp r9, #0 */
/* @0xcfdc0 bne 0xcfea0 <_Z16SET_RValue_ArrayP6RValueS0_i+0x1ec> */
/* @0xcfdc4 ldr r3, [pc, #0x190] */
/* @0xcfdc8 mov r9, #1 */
/* @0xcfdcc ldr r12, [pc, #0x18c] */
/* @0xcfdd0 mvn r2, #0 */
/* @0xcfdd4 ldr r0, [pc, #0x188] */
/* @0xcfdd8 ldr r6, [r8, r3] */
/* @0xcfddc ldr r3, [pc, #0x184] */
/* @0xcfde0 ldr r1, [r7, #0x10] */
/* @0xcfde4 strb r9, [r6] */
/* @0xcfde8 ldr r12, [r8, r12] */
/* @0xcfdec str r5, [r12] */
/* @0xcfdf0 ldr r0, [r8, r0] */
/* @0xcfdf4 str r4, [r0] */
/* @0xcfdf8 ldr r3, [r8, r3] */
/* @0xcfdfc str r1, [r3] */
/* @0xcfe00 ldr r3, [pc, #0x164] */
/* @0xcfe04 ldr r3, [r8, r3] */
/* @0xcfe08 str r2, [r3] */
/* @0xcfe0c add sp, sp, #12 */
/* @0xcfe10 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0xcfe14 b 0x27b94c <_Z16memLogPopContextv> */
/* @0xcfe18 ldr r3, [r6] */
/* @0xcfe1c str r3, [r7, r4, lsl #4] */
/* @0xcfe20 add sp, sp, #12 */
/* @0xcfe24 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0xcfe28 b 0x27b94c <_Z16memLogPopContextv> */
/* @0xcfe2c add r1, r5, #1 */
/* @0xcfe30 ldr r2, [pc, #0x138] */
/* @0xcfe34 str r1, [r7, #0x10] */
/* @0xcfe38 add r0, r7, #4 */
/* @0xcfe3c mov r3, #744 */
/* @0xcfe40 lsl r1, r1, #3 */
/* @0xcfe44 add r2, pc, r2 */
/* @0xcfe48 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xcfe4c cmp r5, #0 */
/* @0xcfe50 bge 0xcfd0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x58> */
/* @0xcfe54 cmp r4, #0 */
/* @0xcfe58 movge r9, #0 */
/* @0xcfe5c bge 0xcfd1c <_Z16SET_RValue_ArrayP6RValueS0_i+0x68> */
/* @0xcfe60 b 0xcfdc4 <_Z16SET_RValue_ArrayP6RValueS0_i+0x110> */
/* @0xcfe64 add r1, r4, #1 */
/* @0xcfe68 ldr r2, [pc, #0x104] */
/* @0xcfe6c mov r0, r9 */
/* @0xcfe70 movw r3, #0x2f5 */
/* @0xcfe74 str r1, [r0], #4 */
/* @0xcfe78 add r2, pc, r2 */
/* @0xcfe7c lsl r1, r1, #4 */
/* @0xcfe80 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xcfe84 b 0xcfd28 <_Z16SET_RValue_ArrayP6RValueS0_i+0x74> */
/* @0xcfe88 ldm r6, {r2, r3} */
/* @0xcfe8c str r2, [r7, r4, lsl #4] */
/* @0xcfe90 str r3, [r5, #0x4] */
/* @0xcfe94 add sp, sp, #12 */
/* @0xcfe98 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0xcfe9c b 0x27b94c <_Z16memLogPopContextv> */
/* @0xcfea0 ldr r1, [pc, #0xb4] */
/* @0xcfea4 mov r9, #1 */
/* @0xcfea8 ldr r2, [pc, #0xb0] */
/* @0xcfeac ldr r12, [pc, #0xb0] */
/* @0xcfeb0 ldr r6, [r8, r1] */
/* @0xcfeb4 ldr r0, [pc, #0xac] */
/* @0xcfeb8 ldr r1, [r7, #0x10] */
/* @0xcfebc strb r9, [r6] */
/* @0xcfec0 ldr r6, [r8, r2] */
/* @0xcfec4 ldr r2, [r3, r5, lsl #3] */
/* @0xcfec8 str r5, [r6] */
/* @0xcfecc ldr r3, [r8, r12] */
/* @0xcfed0 str r4, [r3] */
/* @0xcfed4 ldr r3, [r8, r0] */
/* @0xcfed8 str r1, [r3] */
/* @0xcfedc b 0xcfe00 <_Z16SET_RValue_ArrayP6RValueS0_i+0x14c> */
/* @0xcfee0 ldr r3, [r6] */
/* @0xcfee4 str r3, [r7, r4, lsl #4] */
/* @0xcfee8 ldr r3, [r6] */
/* @0xcfeec cmp r3, #0 */
/* @0xcfef0 beq 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158> */
/* @0xcfef4 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xcfef8 ldr r1, [r6] */
/* @0xcfefc bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xcff00 b 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158> */
/* @0xcff04 ldr r3, [r6] */
/* @0xcff08 cmp r3, #0 */
/* @0xcff0c ldrne r2, [r3, #0x4] */
/* @0xcff10 addne r2, r2, #1 */
/* @0xcff14 strne r2, [r3, #0x4] */
/* @0xcff18 b 0xcfe1c <_Z16SET_RValue_ArrayP6RValueS0_i+0x168> */
/* @0xcff1c ldr r3, [r6] */
/* @0xcff20 cmp r3, #0 */
/* @0xcff24 str r3, [r7, r4, lsl #4] */
/* @0xcff28 beq 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158> */
/* @0xcff2c ldr r1, [r3, #0x8] */
/* @0xcff30 ldr r2, [r3] */
/* @0xcff34 cmp r1, #0 */
/* @0xcff38 streq r5, [r3, #0x8] */
/* @0xcff3c add r2, r2, #1 */
/* @0xcff40 str r2, [r3] */
/* @0xcff44 b 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158> */
/* @0xcff48 mov r0, r5 */
/* @0xcff4c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xcff50 b 0xcfd48 <_Z16SET_RValue_ArrayP6RValueS0_i+0x94> */
/* @0xcff54 eoreq r2, r6, r0, lsl r8 */
/* @0xcff58 eorseq r1, r2, r8, ror #30 */
/* @0xcff5c .word 0xffffbf24 */
/* @0xcff60 .word 0xffffbf28 */
/* @0xcff64 .word 0xffffbf2c */
/* @0xcff68 .word 0xffffbf30 */
/* @0xcff6c .word 0xffffbf34 */
/* @0xcff70 .word 0x002623b8 */
/* @0xcff74 eoreq r2, r6, r4, lsl #7 */

/* ── FUNC 0xcff78 · STRING_RValue(char**, char**, int*, RValue const*) · size=1368 · insn=342 */
/* @0xcff78 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xcff7c vpush {d8} */
/* @0xcff80 mov r6, r0 */
/* @0xcff84 ldr r10, [pc, #0x4ec] */
/* @0xcff88 mov r7, r1 */
/* @0xcff8c ldr r0, [pc, #0x4e8] */
/* @0xcff90 mov r4, r3 */
/* @0xcff94 add r10, pc, r10 */
/* @0xcff98 ldr r1, [pc, #0x4e0] */
/* @0xcff9c sub sp, sp, #588 */
/* @0xcffa0 mov r8, r2 */
/* @0xcffa4 ldr r0, [r10, r0] */
/* @0xcffa8 ldr r2, [pc, #0x4d4] */
/* @0xcffac ldr r3, [r0] */
/* @0xcffb0 str r0, [sp, #0x8] */
/* @0xcffb4 str r3, [sp, #0x244] */
/* @0xcffb8 ldr r5, [r10, r1] */
/* @0xcffbc ldr r12, [r5] */
/* @0xcffc0 add r12, r12, #1 */
/* @0xcffc4 str r12, [r5] */
/* @0xcffc8 ldr r9, [r10, r2] */
/* @0xcffcc ldr r2, [r9] */
/* @0xcffd0 cmp r2, #0 */
/* @0xcffd4 ldreq r3, [pc, #0x4ac] */
/* @0xcffd8 ldreq r3, [r10, r3] */
/* @0xcffdc streq r12, [r3] */
/* @0xcffe0 ldr r3, [r4, #0xc] */
/* @0xcffe4 add r2, r2, #1 */
/* @0xcffe8 str r2, [r9] */
/* @0xcffec bic r3, r3, #-16777216 */
/* @0xcfff0 cmp r3, #5 */
/* @0xcfff4 beq 0xd03a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x42c> */
/* @0xcfff8 ble 0xd002c <_Z13STRING_RValuePPcS0_PiPK6RValue+0xb4> */
/* @0xcfffc cmp r3, #10 */
/* @0xd0000 beq 0xd02c4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x34c> */
/* @0xd0004 bgt 0xd0080 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x108> */
/* @0xd0008 cmp r3, #6 */
/* @0xd000c beq 0xd00cc <_Z13STRING_RValuePPcS0_PiPK6RValue+0x154> */
/* @0xd0010 cmp r3, #7 */
/* @0xd0014 bne 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c> */
/* @0xd0018 ldr r2, [pc, #0x46c] */
/* @0xd001c mov r1, #256 */
/* @0xd0020 ldr r3, [r4] */
/* @0xd0024 add r2, pc, r2 */
/* @0xd0028 b 0xd0058 <_Z13STRING_RValuePPcS0_PiPK6RValue+0xe0> */
/* @0xd002c cmp r3, #1 */
/* @0xd0030 beq 0xd03f0 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x478> */
/* @0xd0034 ble 0xd0344 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x3cc> */
/* @0xd0038 cmp r3, #2 */
/* @0xd003c beq 0xd01b8 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x240> */
/* @0xd0040 cmp r3, #3 */
/* @0xd0044 bne 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c> */
/* @0xd0048 ldr r2, [pc, #0x440] */
/* @0xd004c mov r1, #256 */
/* @0xd0050 ldr r3, [r4] */
/* @0xd0054 add r2, pc, r2 */
/* @0xd0058 add r4, sp, #68 */
/* @0xd005c mov r0, r4 */
/* @0xd0060 bl 0xb65c8 <snprintf@plt> */
/* @0xd0064 mov r2, r8 */
/* @0xd0068 mov r0, r6 */
/* @0xd006c mov r1, r7 */
/* @0xd0070 mov r3, r4 */
/* @0xd0074 bl 0xce388 <_ZN5CCodeD0Ev+0x1c> */
/* @0xd0078 ldr r2, [r9] */
/* @0xd007c b 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c> */
/* @0xd0080 cmp r3, #13 */
/* @0xd0084 beq 0xd0184 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x20c> */
/* @0xd0088 mvn r1, #-16777216 */
/* @0xd008c cmp r3, r1 */
/* @0xd0090 bne 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c> */
/* @0xd0094 ldr r0, [pc, #0x3f8] */
/* @0xd0098 add r0, pc, r0 */
/* @0xd009c bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xd00a0 ldr r2, [r9] */
/* @0xd00a4 ldr r0, [sp, #0x8] */
/* @0xd00a8 sub r2, r2, #1 */
/* @0xd00ac ldr r1, [sp, #0x244] */
/* @0xd00b0 str r2, [r9] */
/* @0xd00b4 ldr r3, [r0] */
/* @0xd00b8 cmp r1, r3 */
/* @0xd00bc bne 0xd0474 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x4fc> */
/* @0xd00c0 add sp, sp, #588 */
/* @0xd00c4 vpop {d8} */
/* @0xd00c8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd00cc ldr r4, [r4] */
/* @0xd00d0 cmp r4, #0 */
/* @0xd00d4 beq 0xd0454 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x4dc> */
/* @0xd00d8 ldr r3, [pc, #0x3a8] */
/* @0xd00dc ldr r1, [r4, #0x30] */
/* @0xd00e0 ldr r3, [r10, r3] */
/* @0xd00e4 ldr r3, [r3] */
/* @0xd00e8 cmp r1, r3 */
/* @0xd00ec bhs 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c> */
/* @0xd00f0 add r5, sp, #36 */
/* @0xd00f4 ldr r2, [pc, #0x39c] */
/* @0xd00f8 str r12, [r4, #0x30] */
/* @0xd00fc mov r0, r4 */
/* @0xd0100 add r2, pc, r2 */
/* @0xd0104 mov r1, r5 */
/* @0xd0108 mov r3, #5 */
/* @0xd010c str r3, [sp, #0x30] */
/* @0xd0110 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* @0xd0114 mov r0, r5 */
/* @0xd0118 bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0xd011c cmp r0, #0 */
/* @0xd0120 beq 0xd00a0 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x128> */
/* @0xd0124 add r10, sp, #52 */
/* @0xd0128 mov r12, #0 */
/* @0xd012c mov r3, r12 */
/* @0xd0130 mov r0, r4 */
/* @0xd0134 mov r2, r5 */
/* @0xd0138 mov r1, r10 */
/* @0xd013c str r12, [sp] */
/* @0xd0140 mvn lr, #-16777216 */
/* @0xd0144 str r12, [sp, #0x34] */
/* @0xd0148 str r12, [sp, #0x38] */
/* @0xd014c str r12, [sp, #0x3c] */
/* @0xd0150 str lr, [sp, #0x40] */
/* @0xd0154 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0xd0158 ldr r3, [sp, #0x40] */
/* @0xd015c cmp r3, #1 */
/* @0xd0160 beq 0xd042c <_Z13STRING_RValuePPcS0_PiPK6RValue+0x4b4> */
/* @0xd0164 sub r3, r3, #1 */
/* @0xd0168 bic r3, r3, #-16777216 */
/* @0xd016c bic r3, r3, #3 */
/* @0xd0170 cmp r3, #0 */
/* @0xd0174 bne 0xd00a0 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x128> */
/* @0xd0178 mov r0, r10 */
/* @0xd017c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xd0180 b 0xd00a0 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x128> */
/* @0xd0184 ldm r4, {r2, r3} */
/* @0xd0188 vmov d7, r2, r3 */
/* @0xd018c vcmp.f64 d7, #0 */
/* @0xd0190 vmrs APSR_nzcv, fpscr */
/* @0xd0194 beq 0xd03e4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x46c> */
/* @0xd0198 ldr r3, [pc, #0x2fc] */
/* @0xd019c add r3, pc, r3 */
/* @0xd01a0 mov r2, r8 */
/* @0xd01a4 mov r0, r6 */
/* @0xd01a8 mov r1, r7 */
/* @0xd01ac bl 0xce388 <_ZN5CCodeD0Ev+0x1c> */
/* @0xd01b0 ldr r2, [r9] */
/* @0xd01b4 b 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c> */
/* @0xd01b8 ldr r3, [pc, #0x2e0] */
/* @0xd01bc mov r0, r6 */
/* @0xd01c0 mov r1, r7 */
/* @0xd01c4 mov r2, r8 */
/* @0xd01c8 add r3, pc, r3 */
/* @0xd01cc bl 0xce388 <_ZN5CCodeD0Ev+0x1c> */
/* @0xd01d0 ldr r11, [r4] */
/* @0xd01d4 cmp r11, #0 */
/* @0xd01d8 beq 0xd0324 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x3ac> */
/* @0xd01dc ldr r3, [pc, #0x2a4] */
/* @0xd01e0 ldr r2, [r11, #0xc] */
/* @0xd01e4 ldr r3, [r10, r3] */
/* @0xd01e8 str r3, [sp, #0xc] */
/* @0xd01ec ldr r3, [r3] */
/* @0xd01f0 cmp r2, r3 */
/* @0xd01f4 bhs 0xd0324 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x3ac> */
/* @0xd01f8 ldr r3, [r11, #0x10] */
/* @0xd01fc ldr r2, [r5] */
/* @0xd0200 cmp r3, #0 */
/* @0xd0204 str r2, [r11, #0xc] */
/* @0xd0208 ble 0xd0324 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x3ac> */
/* @0xd020c ldr r0, [pc, #0x290] */
/* @0xd0210 mov r12, #0 */
/* @0xd0214 ldr r1, [pc, #0x28c] */
/* @0xd0218 ldr r2, [pc, #0x28c] */
/* @0xd021c add r0, pc, r0 */
/* @0xd0220 str r9, [sp, #0x1c] */
/* @0xd0224 mov r9, r12 */
/* @0xd0228 add r1, pc, r1 */
/* @0xd022c add r2, pc, r2 */
/* @0xd0230 str r0, [sp, #0x14] */
/* @0xd0234 str r1, [sp, #0x10] */
/* @0xd0238 str r2, [sp, #0x18] */
/* @0xd023c cmp r3, #0 */
/* @0xd0240 ble 0xd0258 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x2e0> */
/* @0xd0244 mov r0, r6 */
/* @0xd0248 mov r1, r7 */
/* @0xd024c mov r2, r8 */
/* @0xd0250 ldr r3, [sp, #0x14] */
/* @0xd0254 bl 0xce388 <_ZN5CCodeD0Ev+0x1c> */
/* @0xd0258 ldr r3, [r11, #0x4] */
/* @0xd025c add r10, r3, r9, lsl #3 */
/* @0xd0260 ldr r3, [r3, r9, lsl #3] */
/* @0xd0264 cmp r3, #0 */
/* @0xd0268 movgt r4, #0 */
/* @0xd026c ble 0xd02f0 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x378> */
/* @0xd0270 ldr r3, [r10, #0x4] */
/* @0xd0274 mov r0, r6 */
/* @0xd0278 mov r1, r7 */
/* @0xd027c mov r2, r8 */
/* @0xd0280 add r3, r3, r4, lsl #4 */
/* @0xd0284 add r4, r4, #1 */
/* @0xd0288 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0xd028c ldr r3, [r10] */
/* @0xd0290 cmp r3, r4 */
/* @0xd0294 ble 0xd02f0 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x378> */
/* @0xd0298 cmp r4, #0 */
/* @0xd029c beq 0xd0270 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x2f8> */
/* @0xd02a0 mov r0, r6 */
/* @0xd02a4 ldr r3, [sp, #0x10] */
/* @0xd02a8 mov r1, r7 */
/* @0xd02ac mov r2, r8 */
/* @0xd02b0 bl 0xce388 <_ZN5CCodeD0Ev+0x1c> */
/* @0xd02b4 ldr r3, [r5] */
/* @0xd02b8 ldr r0, [sp, #0xc] */
/* @0xd02bc str r3, [r0] */
/* @0xd02c0 b 0xd0270 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x2f8> */
/* @0xd02c4 ldr r12, [r4] */
/* @0xd02c8 mov r1, #256 */
/* @0xd02cc ldr r3, [r4, #0x4] */
/* @0xd02d0 add r4, sp, #68 */
/* @0xd02d4 ldr r2, [pc, #0x1d4] */
/* @0xd02d8 mov r0, r4 */
/* @0xd02dc str r12, [sp] */
/* @0xd02e0 add r2, pc, r2 */
/* @0xd02e4 str r3, [sp, #0x4] */
/* @0xd02e8 bl 0xb65c8 <snprintf@plt> */
/* @0xd02ec b 0xd0064 <_Z13STRING_RValuePPcS0_PiPK6RValue+0xec> */
/* @0xd02f0 ldr r3, [r11, #0x10] */
/* @0xd02f4 cmp r3, #0 */
/* @0xd02f8 ble 0xd0320 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x3a8> */
/* @0xd02fc ldr r3, [sp, #0x18] */
/* @0xd0300 mov r0, r6 */
/* @0xd0304 mov r1, r7 */
/* @0xd0308 mov r2, r8 */
/* @0xd030c bl 0xce388 <_ZN5CCodeD0Ev+0x1c> */
/* @0xd0310 ldr r3, [r11, #0x10] */
/* @0xd0314 add r9, r9, #1 */
/* @0xd0318 cmp r9, r3 */
/* @0xd031c blt 0xd023c <_Z13STRING_RValuePPcS0_PiPK6RValue+0x2c4> */
/* @0xd0320 ldr r9, [sp, #0x1c] */
/* @0xd0324 ldr r3, [pc, #0x188] */
/* @0xd0328 mov r2, r8 */
/* @0xd032c mov r0, r6 */
/* @0xd0330 mov r1, r7 */
/* @0xd0334 add r3, pc, r3 */
/* @0xd0338 bl 0xce388 <_ZN5CCodeD0Ev+0x1c> */
/* @0xd033c ldr r2, [r9] */
/* @0xd0340 b 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c> */
/* @0xd0344 cmp r3, #0 */
/* @0xd0348 bne 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c> */
/* @0xd034c vldr s16, [r4] */
/* @0xd0350 vldr s17, [r4, #4] */
/* @0xd0354 vcmp.f64 d8, d8 */
/* @0xd0358 vmrs APSR_nzcv, fpscr */
/* @0xd035c bne 0xd040c <_Z13STRING_RValuePPcS0_PiPK6RValue+0x494> */
/* @0xd0360 vmov r0, r1, d8 */
/* @0xd0364 bl 0x3194a0 <__fixdfdi> */
/* @0xd0368 mov r4, r0 */
/* @0xd036c mov r5, r1 */
/* @0xd0370 bl 0x319164 <__floatdidf> */
/* @0xd0374 vmov d7, r0, r1 */
/* @0xd0378 vcmp.f64 d8, d7 */
/* @0xd037c vmrs APSR_nzcv, fpscr */
/* @0xd0380 bne 0xd03c4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x44c> */
/* @0xd0384 strd r4, r5, [sp] */
/* @0xd0388 add r4, sp, #68 */
/* @0xd038c ldr r2, [pc, #0x124] */
/* @0xd0390 mov r1, #256 */
/* @0xd0394 mov r0, r4 */
/* @0xd0398 add r2, pc, r2 */
/* @0xd039c bl 0xb65c8 <snprintf@plt> */
/* @0xd03a0 b 0xd0064 <_Z13STRING_RValuePPcS0_PiPK6RValue+0xec> */
/* @0xd03a4 ldr r3, [pc, #0x110] */
/* @0xd03a8 mov r2, r8 */
/* @0xd03ac mov r0, r6 */
/* @0xd03b0 mov r1, r7 */
/* @0xd03b4 add r3, pc, r3 */
/* @0xd03b8 bl 0xce388 <_ZN5CCodeD0Ev+0x1c> */
/* @0xd03bc ldr r2, [r9] */
/* @0xd03c0 b 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c> */
/* @0xd03c4 add r4, sp, #68 */
/* @0xd03c8 ldr r2, [pc, #0xf0] */
/* @0xd03cc vstr d8, [sp] */
/* @0xd03d0 mov r1, #512 */
/* @0xd03d4 add r2, pc, r2 */
/* @0xd03d8 mov r0, r4 */
/* @0xd03dc bl 0xb65c8 <snprintf@plt> */
/* @0xd03e0 b 0xd0064 <_Z13STRING_RValuePPcS0_PiPK6RValue+0xec> */
/* @0xd03e4 ldr r3, [pc, #0xd8] */
/* @0xd03e8 add r3, pc, r3 */
/* @0xd03ec b 0xd01a0 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x228> */
/* @0xd03f0 ldr r3, [r4] */
/* @0xd03f4 cmp r3, #0 */
/* @0xd03f8 beq 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c> */
/* @0xd03fc ldr r3, [r3] */
/* @0xd0400 cmp r3, #0 */
/* @0xd0404 bne 0xd01a0 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x228> */
/* @0xd0408 b 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c> */
/* @0xd040c ldr r3, [pc, #0xb4] */
/* @0xd0410 mov r2, r8 */
/* @0xd0414 mov r0, r6 */
/* @0xd0418 mov r1, r7 */
/* @0xd041c add r3, pc, r3 */
/* @0xd0420 bl 0xce388 <_ZN5CCodeD0Ev+0x1c> */
/* @0xd0424 ldr r2, [r9] */
/* @0xd0428 b 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c> */
/* @0xd042c ldr r3, [sp, #0x34] */
/* @0xd0430 ldr r3, [r3] */
/* @0xd0434 cmp r3, #0 */
/* @0xd0438 beq 0xd0178 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x200> */
/* @0xd043c mov r0, r6 */
/* @0xd0440 mov r1, r7 */
/* @0xd0444 mov r2, r8 */
/* @0xd0448 bl 0xce388 <_ZN5CCodeD0Ev+0x1c> */
/* @0xd044c ldr r3, [sp, #0x40] */
/* @0xd0450 b 0xd0164 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x1ec> */
/* @0xd0454 ldr r3, [pc, #0x70] */
/* @0xd0458 mov r2, r8 */
/* @0xd045c mov r0, r6 */
/* @0xd0460 mov r1, r7 */
/* @0xd0464 add r3, pc, r3 */
/* @0xd0468 bl 0xce388 <_ZN5CCodeD0Ev+0x1c> */
/* @0xd046c ldr r2, [r9] */
/* @0xd0470 b 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c> */
/* @0xd0474 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xd0478 ldrhteq r1, [r2], -r12 */
/* @0xd047c .word 0xffffbd00 */
/* @0xd0480 .word 0xffffbf38 */
/* @0xd0484 .word 0xffffbf3c */
/* @0xd0488 .word 0xffffbf40 */
/* @0xd048c eoreq r2, r6, r8, ror #9 */
/* @0xd0490 .word 0x002624b4 */
/* @0xd0494 mlaeq r6, r8, r4, r2 */
/* @0xd0498 eoreq r2, r6, r0, lsl r4 */
/* @0xd049c eoreq r2, r6, r4, asr r3 */
/* @0xd04a0 eoreq r2, r6, r4, asr r3 */
/* @0xd04a4 eoreq r2, r6, r0, lsl #6 */
/* @0xd04a8 .word 0x002622fc */
/* @0xd04ac .word 0x002622fc */
/* @0xd04b0 eoreq r2, r6, r8, lsl r2 */
/* @0xd04b4 eoreq r2, r6, r12, ror #3 */
/* @0xd04b8 eoreq r2, r6, r0, ror #2 */
/* @0xd04bc eoreq r1, r6, r12, lsr #29 */
/* @0xd04c0 eoreq r2, r6, r12, lsr #2 */
/* @0xd04c4 eoreq r2, r6, r4, lsl #2 */
/* @0xd04c8 .word 0x002620d8 */
/* @0xd04cc eoreq r1, r6, r0, asr #28 */

/* ── FUNC 0xd04d0 · YYGetString(RValue const*, int) · size=260 · insn=65 */
/* @0xd04d0 push {r4, r5, r7, lr} */
/* @0xd04d4 add r7, r0, r1, lsl #4 */
/* @0xd04d8 sub sp, sp, #24 */
/* @0xd04dc ldr r4, [r7, #0xc] */
/* @0xd04e0 bic r4, r4, #-16777216 */
/* @0xd04e4 cmp r4, #13 */
/* @0xd04e8 bhi 0xd0588 <_Z11YYGetStringPK6RValuei+0xb8> */
/* @0xd04ec mov r3, #1 */
/* @0xd04f0 movw r12, #0x24c1 */
/* @0xd04f4 lsl r5, r3, r4 */
/* @0xd04f8 and r12, r5, r12 */
/* @0xd04fc cmp r12, #0 */
/* @0xd0500 bne 0xd0538 <_Z11YYGetStringPK6RValuei+0x68> */
/* @0xd0504 tst r5, #2 */
/* @0xd0508 beq 0xd0588 <_Z11YYGetStringPK6RValuei+0xb8> */
/* @0xd050c cmp r4, r3 */
/* @0xd0510 movne r0, r12 */
/* @0xd0514 beq 0xd0520 <_Z11YYGetStringPK6RValuei+0x50> */
/* @0xd0518 add sp, sp, #24 */
/* @0xd051c pop {r4, r5, r7, pc} */
/* @0xd0520 ldr r0, [r0, r1, lsl #4] */
/* @0xd0524 cmp r0, #0 */
/* @0xd0528 beq 0xd0518 <_Z11YYGetStringPK6RValuei+0x48> */
/* @0xd052c ldr r0, [r0] */
/* @0xd0530 add sp, sp, #24 */
/* @0xd0534 pop {r4, r5, r7, pc} */
/* @0xd0538 ldr r1, [pc, #0x88] */
/* @0xd053c mov r12, #16 */
/* @0xd0540 mov r0, r12 */
/* @0xd0544 movw r2, #0x1ad */
/* @0xd0548 add r1, pc, r1 */
/* @0xd054c str r12, [sp, #0xc] */
/* @0xd0550 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd0554 mov r3, r7 */
/* @0xd0558 mov r1, #0 */
/* @0xd055c mov r2, r0 */
/* @0xd0560 add r0, sp, #24 */
/* @0xd0564 str r2, [sp, #0x10] */
/* @0xd0568 str r2, [r0, #-0x4]! */
/* @0xd056c strb r1, [r2] */
/* @0xd0570 add r1, sp, #16 */
/* @0xd0574 add r2, sp, #12 */
/* @0xd0578 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0xd057c ldr r0, [sp, #0x10] */
/* @0xd0580 add sp, sp, #24 */
/* @0xd0584 pop {r4, r5, r7, pc} */
/* @0xd0588 ldr r3, [pc, #0x3c] */
/* @0xd058c mov r0, r7 */
/* @0xd0590 ldr r3, [pc, r3] */
/* @0xd0594 ldr r4, [r3] */
/* @0xd0598 str r1, [sp, #0x4] */
/* @0xd059c bl 0xce54c <_Z8KindNamePK6RValue> */
/* @0xd05a0 ldr r1, [sp, #0x4] */
/* @0xd05a4 add r2, r1, #1 */
/* @0xd05a8 mov r1, r4 */
/* @0xd05ac mov r3, r0 */
/* @0xd05b0 ldr r0, [pc, #0x18] */
/* @0xd05b4 add r0, pc, r0 */
/* @0xd05b8 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xd05bc mov r0, #0 */
/* @0xd05c0 add sp, sp, #24 */
/* @0xd05c4 pop {r4, r5, r7, pc} */
/* @0xd05c8 .word 0x00261cb4 */
/* @0xd05cc eorseq sp, r1, r0, lsr #11 */
/* @0xd05d0 mlaeq r6, r8, pc, r1 */

/* ── FUNC 0xd05d4 · Code_Execute_Special(CInstance*, CInstance*, CCode*, RValue*, int) · size=120 · insn=30 */
/* @0xd05d4 push {r4, r5, lr} */
/* @0xd05d8 sub sp, sp, #12 */
/* @0xd05dc mov r4, r3 */
/* @0xd05e0 ldr r12, [sp, #0x18] */
/* @0xd05e4 str r12, [sp] */
/* @0xd05e8 bl 0xcf914 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei> */
/* @0xd05ec subs r5, r0, #0 */
/* @0xd05f0 bne 0xd0630 <_Z20Code_Execute_SpecialP9CInstanceS0_P5CCodeP6RValuei+0x5c> */
/* @0xd05f4 ldr r3, [r4, #0xc] */
/* @0xd05f8 sub r3, r3, #1 */
/* @0xd05fc bic r3, r3, #-16777216 */
/* @0xd0600 bic r3, r3, #3 */
/* @0xd0604 cmp r3, #0 */
/* @0xd0608 beq 0xd063c <_Z20Code_Execute_SpecialP9CInstanceS0_P5CCodeP6RValuei+0x68> */
/* @0xd060c ldr r1, [pc, #0x34] */
/* @0xd0610 mov r3, #0 */
/* @0xd0614 mov r2, #5 */
/* @0xd0618 str r3, [r4, #0x8] */
/* @0xd061c mov r0, r4 */
/* @0xd0620 str r3, [r4] */
/* @0xd0624 str r2, [r4, #0xc] */
/* @0xd0628 add r1, pc, r1 */
/* @0xd062c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0xd0630 mov r0, r5 */
/* @0xd0634 add sp, sp, #12 */
/* @0xd0638 pop {r4, r5, pc} */
/* @0xd063c mov r0, r4 */
/* @0xd0640 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xd0644 b 0xd060c <_Z20Code_Execute_SpecialP9CInstanceS0_P5CCodeP6RValuei+0x38> */
/* @0xd0648 eoreq r1, r6, r4, ror #30 */

/* ── FUNC 0xd064c · CopyRefArrayAndUnref(RefDynamicArrayOfRValue*, void*) · size=1084 · insn=271 */
/* @0xd064c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd0650 cmp r0, #0 */
/* @0xd0654 sub sp, sp, #28 */
/* @0xd0658 str r0, [sp, #0x10] */
/* @0xd065c beq 0xd0a08 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x3bc> */
/* @0xd0660 mov r0, r1 */
/* @0xd0664 bl 0xced9c <_Z14ARRAY_RefAllocPv> */
/* @0xd0668 str r0, [sp, #0xc] */
/* @0xd066c ldr r0, [sp, #0x10] */
/* @0xd0670 ldr r2, [sp, #0xc] */
/* @0xd0674 ldr r1, [r0, #0x10] */
/* @0xd0678 cmp r1, #0 */
/* @0xd067c str r1, [r2, #0x10] */
/* @0xd0680 ble 0xd09ac <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x360> */
/* @0xd0684 mov r0, r2 */
/* @0xd0688 ldr r2, [pc, #0x3f0] */
/* @0xd068c mov r9, #0 */
/* @0xd0690 movw r3, #0x226 */
/* @0xd0694 add r2, pc, r2 */
/* @0xd0698 lsl r1, r1, #3 */
/* @0xd069c str r9, [r0, #0x4]! */
/* @0xd06a0 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xd06a4 ldr r3, [sp, #0xc] */
/* @0xd06a8 ldr r2, [r3, #0x10] */
/* @0xd06ac cmp r2, r9 */
/* @0xd06b0 ble 0xd0814 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x1c8> */
/* @0xd06b4 ldr r3, [pc, #0x3c8] */
/* @0xd06b8 mov r7, r9 */
/* @0xd06bc str r9, [sp, #0x8] */
/* @0xd06c0 add r3, pc, r3 */
/* @0xd06c4 str r3, [sp, #0x14] */
/* @0xd06c8 ldr r0, [sp, #0x10] */
/* @0xd06cc ldr r1, [sp, #0x8] */
/* @0xd06d0 ldr r4, [r0, #0x4] */
/* @0xd06d4 ldr r0, [sp, #0xc] */
/* @0xd06d8 lsl r6, r1, #3 */
/* @0xd06dc add r10, r4, r6 */
/* @0xd06e0 ldr r1, [r4, r1, lsl #3] */
/* @0xd06e4 ldr r3, [r0, #0x4] */
/* @0xd06e8 cmp r1, #0 */
/* @0xd06ec ldr r5, [r10, #0x4] */
/* @0xd06f0 add r6, r3, r6 */
/* @0xd06f4 ble 0xd091c <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x2d0> */
/* @0xd06f8 ldr r2, [sp, #0x8] */
/* @0xd06fc add r0, r6, #4 */
/* @0xd0700 str r1, [r3, r2, lsl #3] */
/* @0xd0704 movw r3, #0x235 */
/* @0xd0708 lsl r1, r1, #4 */
/* @0xd070c ldr r2, [sp, #0x14] */
/* @0xd0710 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xd0714 ldr r0, [sp, #0x8] */
/* @0xd0718 ldr r3, [r4, r0, lsl #3] */
/* @0xd071c ldr r4, [r6, #0x4] */
/* @0xd0720 cmp r3, #0 */
/* @0xd0724 addgt r4, r4, #16 */
/* @0xd0728 addgt r5, r5, #16 */
/* @0xd072c movgt r11, #0 */
/* @0xd0730 ble 0xd09bc <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x370> */
/* @0xd0734 ldr r2, [r4, #-0x4] */
/* @0xd0738 sub r8, r5, #16 */
/* @0xd073c sub r6, r4, #16 */
/* @0xd0740 bic r3, r2, #-16777216 */
/* @0xd0744 cmp r3, #1 */
/* @0xd0748 beq 0xd08a4 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x258> */
/* @0xd074c cmp r3, #2 */
/* @0xd0750 bne 0xd0774 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x128> */
/* @0xd0754 sub r2, r2, #1 */
/* @0xd0758 bic r2, r2, #-16777216 */
/* @0xd075c bic r2, r2, #3 */
/* @0xd0760 cmp r2, #0 */
/* @0xd0764 beq 0xd0910 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x2c4> */
/* @0xd0768 mov r2, #5 */
/* @0xd076c str r7, [r4, #-0x8] */
/* @0xd0770 str r2, [r4, #-0x4] */
/* @0xd0774 str r7, [r4, #-0x10] */
/* @0xd0778 ldr r3, [r5, #-0x4] */
/* @0xd077c str r3, [r4, #-0x4] */
/* @0xd0780 ldr r3, [r5, #-0x8] */
/* @0xd0784 str r3, [r4, #-0x8] */
/* @0xd0788 ldr r3, [r5, #-0x4] */
/* @0xd078c bic r3, r3, #-16777216 */
/* @0xd0790 cmp r3, #14 */
/* @0xd0794 addls pc, pc, r3, lsl #2 */
/* @0xd0798 b 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194> */
/* @0xd079c b 0xd0830 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x1e4> */
/* @0xd07a0 b 0xd0868 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x21c> */
/* @0xd07a4 b 0xd083c <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x1f0> */
/* @0xd07a8 b 0xd07d8 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x18c> */
/* @0xd07ac b 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194> */
/* @0xd07b0 b 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194> */
/* @0xd07b4 b 0xd0880 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x234> */
/* @0xd07b8 b 0xd07d8 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x18c> */
/* @0xd07bc b 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194> */
/* @0xd07c0 b 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194> */
/* @0xd07c4 b 0xd0830 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x1e4> */
/* @0xd07c8 b 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194> */
/* @0xd07cc b 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194> */
/* @0xd07d0 b 0xd0830 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x1e4> */
/* @0xd07d4 b 0xd07d8 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x18c> */
/* @0xd07d8 ldr r3, [r5, #-0x10] */
/* @0xd07dc str r3, [r4, #-0x10] */
/* @0xd07e0 ldr r3, [r10] */
/* @0xd07e4 add r11, r11, #1 */
/* @0xd07e8 add r4, r4, #16 */
/* @0xd07ec add r5, r5, #16 */
/* @0xd07f0 cmp r3, r11 */
/* @0xd07f4 bgt 0xd0734 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0xe8> */
/* @0xd07f8 ldr r3, [sp, #0xc] */
/* @0xd07fc ldr r2, [r3, #0x10] */
/* @0xd0800 ldr r1, [sp, #0x8] */
/* @0xd0804 add r1, r1, #1 */
/* @0xd0808 str r1, [sp, #0x8] */
/* @0xd080c cmp r2, r1 */
/* @0xd0810 bgt 0xd06c8 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x7c> */
/* @0xd0814 ldr r1, [sp, #0x10] */
/* @0xd0818 ldr r3, [r1] */
/* @0xd081c sub r3, r3, #1 */
/* @0xd0820 str r3, [r1] */
/* @0xd0824 ldr r0, [sp, #0xc] */
/* @0xd0828 add sp, sp, #28 */
/* @0xd082c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd0830 ldm r8, {r2, r3} */
/* @0xd0834 stm r6, {r2, r3} */
/* @0xd0838 b 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194> */
/* @0xd083c ldr r3, [r5, #-0x10] */
/* @0xd0840 cmp r3, #0 */
/* @0xd0844 str r3, [r4, #-0x10] */
/* @0xd0848 beq 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194> */
/* @0xd084c ldr r1, [r3, #0x8] */
/* @0xd0850 ldr r2, [r3] */
/* @0xd0854 cmp r1, #0 */
/* @0xd0858 streq r6, [r3, #0x8] */
/* @0xd085c add r2, r2, #1 */
/* @0xd0860 str r2, [r3] */
/* @0xd0864 b 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194> */
/* @0xd0868 ldr r3, [r5, #-0x10] */
/* @0xd086c cmp r3, #0 */
/* @0xd0870 ldrne r2, [r3, #0x4] */
/* @0xd0874 addne r2, r2, #1 */
/* @0xd0878 strne r2, [r3, #0x4] */
/* @0xd087c b 0xd07dc <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x190> */
/* @0xd0880 ldr r3, [r5, #-0x10] */
/* @0xd0884 str r3, [r4, #-0x10] */
/* @0xd0888 ldr r3, [r5, #-0x10] */
/* @0xd088c cmp r3, #0 */
/* @0xd0890 beq 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194> */
/* @0xd0894 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xd0898 ldr r1, [r5, #-0x10] */
/* @0xd089c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xd08a0 b 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194> */
/* @0xd08a4 ldr r9, [r4, #-0x10] */
/* @0xd08a8 cmp r9, #0 */
/* @0xd08ac beq 0xd0774 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x128> */
/* @0xd08b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xd08b4 ldr r3, [r9, #0x4] */
/* @0xd08b8 sub r3, r3, #1 */
/* @0xd08bc str r3, [r9, #0x4] */
/* @0xd08c0 cmp r3, #0 */
/* @0xd08c4 beq 0xd08d0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x284> */
/* @0xd08c8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xd08cc b 0xd0774 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x128> */
/* @0xd08d0 ldr r0, [r9] */
/* @0xd08d4 str r3, [sp, #0x4] */
/* @0xd08d8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xd08dc ldr r3, [sp, #0x4] */
/* @0xd08e0 str r3, [r9] */
/* @0xd08e4 str r3, [r9, #0x8] */
/* @0xd08e8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xd08ec ldr r3, [r9, #0x4] */
/* @0xd08f0 sub r3, r3, #1 */
/* @0xd08f4 str r3, [r9, #0x4] */
/* @0xd08f8 cmp r3, #0 */
/* @0xd08fc beq 0xd092c <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x2e0> */
/* @0xd0900 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xd0904 mov r0, r9 */
/* @0xd0908 bl 0x27d1d0 <_ZdlPv> */
/* @0xd090c b 0xd08c8 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x27c> */
/* @0xd0910 mov r0, r6 */
/* @0xd0914 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xd0918 b 0xd0768 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x11c> */
/* @0xd091c ldr r0, [sp, #0x8] */
/* @0xd0920 str r7, [r3, r0, lsl #3] */
/* @0xd0924 str r7, [r6, #0x4] */
/* @0xd0928 b 0xd0800 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x1b4> */
/* @0xd092c ldr r0, [r9] */
/* @0xd0930 str r3, [sp, #0x4] */
/* @0xd0934 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xd0938 ldr r3, [sp, #0x4] */
/* @0xd093c str r3, [r9] */
/* @0xd0940 str r3, [r9, #0x8] */
/* @0xd0944 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xd0948 ldr r3, [r9, #0x4] */
/* @0xd094c sub r3, r3, #1 */
/* @0xd0950 str r3, [r9, #0x4] */
/* @0xd0954 cmp r3, #0 */
/* @0xd0958 beq 0xd096c <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x320> */
/* @0xd095c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xd0960 mov r0, r9 */
/* @0xd0964 bl 0x27d1d0 <_ZdlPv> */
/* @0xd0968 b 0xd0900 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x2b4> */
/* @0xd096c ldr r0, [r9] */
/* @0xd0970 str r3, [sp, #0x4] */
/* @0xd0974 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xd0978 ldr r3, [sp, #0x4] */
/* @0xd097c str r3, [r9] */
/* @0xd0980 str r3, [r9, #0x8] */
/* @0xd0984 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xd0988 ldr r3, [r9, #0x4] */
/* @0xd098c sub r3, r3, #1 */
/* @0xd0990 str r3, [r9, #0x4] */
/* @0xd0994 cmp r3, #0 */
/* @0xd0998 beq 0xd09c8 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x37c> */
/* @0xd099c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xd09a0 mov r0, r9 */
/* @0xd09a4 bl 0x27d1d0 <_ZdlPv> */
/* @0xd09a8 b 0xd095c <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x310> */
/* @0xd09ac ldr r0, [sp, #0xc] */
/* @0xd09b0 mov r3, #0 */
/* @0xd09b4 str r3, [r0, #0x4] */
/* @0xd09b8 b 0xd0814 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x1c8> */
/* @0xd09bc ldr r1, [sp, #0xc] */
/* @0xd09c0 ldr r2, [r1, #0x10] */
/* @0xd09c4 b 0xd0800 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x1b4> */
/* @0xd09c8 ldr r0, [r9] */
/* @0xd09cc str r3, [sp, #0x4] */
/* @0xd09d0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xd09d4 ldr r3, [sp, #0x4] */
/* @0xd09d8 str r3, [r9] */
/* @0xd09dc str r3, [r9, #0x8] */
/* @0xd09e0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xd09e4 ldr r3, [r9, #0x4] */
/* @0xd09e8 sub r3, r3, #1 */
/* @0xd09ec str r3, [r9, #0x4] */
/* @0xd09f0 cmp r3, #0 */
/* @0xd09f4 beq 0xd0a14 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x3c8> */
/* @0xd09f8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xd09fc mov r0, r9 */
/* @0xd0a00 bl 0x27d1d0 <_ZdlPv> */
/* @0xd0a04 b 0xd099c <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x350> */
/* @0xd0a08 ldr r2, [sp, #0x10] */
/* @0xd0a0c str r2, [sp, #0xc] */
/* @0xd0a10 b 0xd0824 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x1d8> */
/* @0xd0a14 ldr r0, [r9] */
/* @0xd0a18 str r3, [sp, #0x4] */
/* @0xd0a1c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xd0a20 ldr r3, [sp, #0x4] */
/* @0xd0a24 str r3, [r9] */
/* @0xd0a28 str r3, [r9, #0x8] */
/* @0xd0a2c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xd0a30 ldr r3, [r9, #0x4] */
/* @0xd0a34 sub r3, r3, #1 */
/* @0xd0a38 str r3, [r9, #0x4] */
/* @0xd0a3c cmp r3, #0 */
/* @0xd0a40 beq 0xd0a54 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x408> */
/* @0xd0a44 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xd0a48 mov r0, r9 */
/* @0xd0a4c bl 0x27d1d0 <_ZdlPv> */
/* @0xd0a50 b 0xd09f8 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x3ac> */
/* @0xd0a54 ldr r0, [r9] */
/* @0xd0a58 str r3, [sp, #0x4] */
/* @0xd0a5c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xd0a60 ldr r3, [sp, #0x4] */
/* @0xd0a64 mov r0, r9 */
/* @0xd0a68 str r3, [r9] */
/* @0xd0a6c str r3, [r9, #0x8] */
/* @0xd0a70 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xd0a74 mov r0, r9 */
/* @0xd0a78 bl 0x27d1d0 <_ZdlPv> */
/* @0xd0a7c b 0xd0a44 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x3f8> */
/* @0xd0a80 eoreq r1, r6, r8, ror #22 */
/* @0xd0a84 eoreq r1, r6, r12, lsr r11 */

/* ── FUNC 0xd0a88 · DEEP_COPY_RValue(RValue*, RValue const*) · size=156 · insn=39 */
/* @0xd0a88 ldr r3, [r1, #0xc] */
/* @0xd0a8c push {r4, lr} */
/* @0xd0a90 mov r4, r0 */
/* @0xd0a94 str r3, [r0, #0xc] */
/* @0xd0a98 ldr r3, [r1, #0xc] */
/* @0xd0a9c bic r3, r3, #-16777216 */
/* @0xd0aa0 cmp r3, #10 */
/* @0xd0aa4 addls pc, pc, r3, lsl #2 */
/* @0xd0aa8 b 0xd0af4 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x6c> */
/* @0xd0aac b 0xd0b04 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x7c> */
/* @0xd0ab0 b 0xd0ad8 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x50> */
/* @0xd0ab4 b 0xd0b10 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x88> */
/* @0xd0ab8 b 0xd0af8 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x70> */
/* @0xd0abc b 0xd0af4 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x6c> */
/* @0xd0ac0 b 0xd0af4 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x6c> */
/* @0xd0ac4 b 0xd0af4 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x6c> */
/* @0xd0ac8 b 0xd0af8 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x70> */
/* @0xd0acc b 0xd0af4 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x6c> */
/* @0xd0ad0 b 0xd0af4 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x6c> */
/* @0xd0ad4 b 0xd0b04 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x7c> */
/* @0xd0ad8 ldr r3, [r1] */
/* @0xd0adc cmp r3, #0 */
/* @0xd0ae0 str r3, [r0] */
/* @0xd0ae4 popeq {r4, pc} */
/* @0xd0ae8 ldr r2, [r3, #0x4] */
/* @0xd0aec add r2, r2, #1 */
/* @0xd0af0 str r2, [r3, #0x4] */
/* @0xd0af4 pop {r4, pc} */
/* @0xd0af8 ldr r3, [r1] */
/* @0xd0afc str r3, [r0] */
/* @0xd0b00 pop {r4, pc} */
/* @0xd0b04 ldm r1, {r2, r3} */
/* @0xd0b08 stm r0, {r2, r3} */
/* @0xd0b0c pop {r4, pc} */
/* @0xd0b10 ldr r0, [r1] */
/* @0xd0b14 mov r1, r4 */
/* @0xd0b18 bl 0xd064c <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv> */
/* @0xd0b1c str r0, [r4] */
/* @0xd0b20 pop {r4, pc} */

/* ── FUNC 0xd0b24 · SET_RValue(RValue*, RValue*, int) · size=532 · insn=133 */
/* @0xd0b24 ldr r3, [r0, #0xc] */
/* @0xd0b28 push {r4, r5, lr} */
/* @0xd0b2c mov r5, r1 */
/* @0xd0b30 bic r1, r3, #-16777216 */
/* @0xd0b34 sub sp, sp, #12 */
/* @0xd0b38 cmp r1, #2 */
/* @0xd0b3c mov r4, r0 */
/* @0xd0b40 beq 0xd0cbc <_Z10SET_RValueP6RValueS0_i+0x198> */
/* @0xd0b44 cmp r2, #-2147483648 */
/* @0xd0b48 beq 0xd0b78 <_Z10SET_RValueP6RValueS0_i+0x54> */
/* @0xd0b4c mov r1, #2 */
/* @0xd0b50 mov r3, #0 */
/* @0xd0b54 str r1, [r0, #0xc] */
/* @0xd0b58 str r3, [r0] */
/* @0xd0b5c mov r0, r4 */
/* @0xd0b60 str r2, [sp, #0x4] */
/* @0xd0b64 bl 0xced9c <_Z14ARRAY_RefAllocPv> */
/* @0xd0b68 str r0, [r4] */
/* @0xd0b6c ldr r2, [sp, #0x4] */
/* @0xd0b70 ldr r3, [r0, #0x8] */
/* @0xd0b74 b 0xd0d00 <_Z10SET_RValueP6RValueS0_i+0x1dc> */
/* @0xd0b78 sub r3, r3, #1 */
/* @0xd0b7c bic r3, r3, #-16777216 */
/* @0xd0b80 bic r3, r3, #3 */
/* @0xd0b84 cmp r3, #0 */
/* @0xd0b88 beq 0xd0c38 <_Z10SET_RValueP6RValueS0_i+0x114> */
/* @0xd0b8c mov r3, #5 */
/* @0xd0b90 str r3, [r4, #0xc] */
/* @0xd0b94 ldr r3, [r5, #0xc] */
/* @0xd0b98 mov r2, #0 */
/* @0xd0b9c str r2, [r4, #0x8] */
/* @0xd0ba0 ldr r1, [r5, #0x8] */
/* @0xd0ba4 str r3, [r4, #0xc] */
/* @0xd0ba8 ldr r3, [r5, #0xc] */
/* @0xd0bac str r2, [r4] */
/* @0xd0bb0 bic r3, r3, #-16777216 */
/* @0xd0bb4 str r1, [r4, #0x8] */
/* @0xd0bb8 cmp r3, #14 */
/* @0xd0bbc addls pc, pc, r3, lsl #2 */
/* @0xd0bc0 b 0xd0c08 <_Z10SET_RValueP6RValueS0_i+0xe4> */
/* @0xd0bc4 b 0xd0c40 <_Z10SET_RValueP6RValueS0_i+0x11c> */
/* @0xd0bc8 b 0xd0ca4 <_Z10SET_RValueP6RValueS0_i+0x180> */
/* @0xd0bcc b 0xd0c78 <_Z10SET_RValueP6RValueS0_i+0x154> */
/* @0xd0bd0 b 0xd0c00 <_Z10SET_RValueP6RValueS0_i+0xdc> */
/* @0xd0bd4 b 0xd0c08 <_Z10SET_RValueP6RValueS0_i+0xe4> */
/* @0xd0bd8 b 0xd0c08 <_Z10SET_RValueP6RValueS0_i+0xe4> */
/* @0xd0bdc b 0xd0c50 <_Z10SET_RValueP6RValueS0_i+0x12c> */
/* @0xd0be0 b 0xd0c00 <_Z10SET_RValueP6RValueS0_i+0xdc> */
/* @0xd0be4 b 0xd0c08 <_Z10SET_RValueP6RValueS0_i+0xe4> */
/* @0xd0be8 b 0xd0c08 <_Z10SET_RValueP6RValueS0_i+0xe4> */
/* @0xd0bec b 0xd0c40 <_Z10SET_RValueP6RValueS0_i+0x11c> */
/* @0xd0bf0 b 0xd0c08 <_Z10SET_RValueP6RValueS0_i+0xe4> */
/* @0xd0bf4 b 0xd0c08 <_Z10SET_RValueP6RValueS0_i+0xe4> */
/* @0xd0bf8 b 0xd0c40 <_Z10SET_RValueP6RValueS0_i+0x11c> */
/* @0xd0bfc b 0xd0c00 <_Z10SET_RValueP6RValueS0_i+0xdc> */
/* @0xd0c00 ldr r3, [r5] */
/* @0xd0c04 str r3, [r4] */
/* @0xd0c08 add sp, sp, #12 */
/* @0xd0c0c pop {r4, r5, pc} */
/* @0xd0c10 ldr r2, [r5, #0xc] */
/* @0xd0c14 bic r2, r2, #-16777216 */
/* @0xd0c18 cmp r2, #2 */
/* @0xd0c1c beq 0xd0d1c <_Z10SET_RValueP6RValueS0_i+0x1f8> */
/* @0xd0c20 sub r3, r3, #1 */
/* @0xd0c24 bic r3, r3, #-16777216 */
/* @0xd0c28 bic r3, r3, #3 */
/* @0xd0c2c cmp r3, #0 */
/* @0xd0c30 bne 0xd0b8c <_Z10SET_RValueP6RValueS0_i+0x68> */
/* @0xd0c34 mov r0, r4 */
/* @0xd0c38 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xd0c3c b 0xd0b8c <_Z10SET_RValueP6RValueS0_i+0x68> */
/* @0xd0c40 ldm r5, {r2, r3} */
/* @0xd0c44 stm r4, {r2, r3} */
/* @0xd0c48 add sp, sp, #12 */
/* @0xd0c4c pop {r4, r5, pc} */
/* @0xd0c50 ldr r3, [r5] */
/* @0xd0c54 str r3, [r4] */
/* @0xd0c58 ldr r3, [r5] */
/* @0xd0c5c cmp r3, #0 */
/* @0xd0c60 beq 0xd0c08 <_Z10SET_RValueP6RValueS0_i+0xe4> */
/* @0xd0c64 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xd0c68 ldr r1, [r5] */
/* @0xd0c6c add sp, sp, #12 */
/* @0xd0c70 pop {r4, r5, lr} */
/* @0xd0c74 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xd0c78 ldr r3, [r5] */
/* @0xd0c7c cmp r3, #0 */
/* @0xd0c80 str r3, [r4] */
/* @0xd0c84 beq 0xd0c08 <_Z10SET_RValueP6RValueS0_i+0xe4> */
/* @0xd0c88 ldr r1, [r3, #0x8] */
/* @0xd0c8c ldr r2, [r3] */
/* @0xd0c90 cmp r1, #0 */
/* @0xd0c94 streq r4, [r3, #0x8] */
/* @0xd0c98 add r2, r2, #1 */
/* @0xd0c9c str r2, [r3] */
/* @0xd0ca0 b 0xd0c08 <_Z10SET_RValueP6RValueS0_i+0xe4> */
/* @0xd0ca4 ldr r3, [r5] */
/* @0xd0ca8 cmp r3, #0 */
/* @0xd0cac ldrne r2, [r3, #0x4] */
/* @0xd0cb0 addne r2, r2, #1 */
/* @0xd0cb4 strne r2, [r3, #0x4] */
/* @0xd0cb8 b 0xd0c04 <_Z10SET_RValueP6RValueS0_i+0xe0> */
/* @0xd0cbc cmp r2, #-2147483648 */
/* @0xd0cc0 beq 0xd0c10 <_Z10SET_RValueP6RValueS0_i+0xec> */
/* @0xd0cc4 ldr r0, [r0] */
/* @0xd0cc8 cmp r0, #0 */
/* @0xd0ccc beq 0xd0b5c <_Z10SET_RValueP6RValueS0_i+0x38> */
/* @0xd0cd0 ldr r3, [r0, #0x8] */
/* @0xd0cd4 cmp r3, r4 */
/* @0xd0cd8 beq 0xd0d08 <_Z10SET_RValueP6RValueS0_i+0x1e4> */
/* @0xd0cdc ldr r1, [r0] */
/* @0xd0ce0 cmp r1, #1 */
/* @0xd0ce4 beq 0xd0d00 <_Z10SET_RValueP6RValueS0_i+0x1dc> */
/* @0xd0ce8 mov r1, r4 */
/* @0xd0cec str r2, [sp, #0x4] */
/* @0xd0cf0 bl 0xd064c <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv> */
/* @0xd0cf4 str r0, [r4] */
/* @0xd0cf8 ldr r2, [sp, #0x4] */
/* @0xd0cfc ldr r3, [r0, #0x8] */
/* @0xd0d00 cmp r3, #0 */
/* @0xd0d04 streq r5, [r0, #0x8] */
/* @0xd0d08 mov r0, r4 */
/* @0xd0d0c mov r1, r5 */
/* @0xd0d10 add sp, sp, #12 */
/* @0xd0d14 pop {r4, r5, lr} */
/* @0xd0d18 b 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i> */
/* @0xd0d1c ldr r2, [r5] */
/* @0xd0d20 cmp r2, #0 */
/* @0xd0d24 beq 0xd0c20 <_Z10SET_RValueP6RValueS0_i+0xfc> */
/* @0xd0d28 ldr r1, [r2, #0x8] */
/* @0xd0d2c cmp r1, #0 */
/* @0xd0d30 streq r5, [r2, #0x8] */
/* @0xd0d34 b 0xd0c20 <_Z10SET_RValueP6RValueS0_i+0xfc> */

/* ── FUNC 0xd0d38 · ARRAY_LVAL_RValue(YYRValue*, int) · size=348 · insn=87 */
/* @0xd0d38 push {r4, r5, r6, r7, lr} */
/* @0xd0d3c sub sp, sp, #12 */
/* @0xd0d40 mov r4, r0 */
/* @0xd0d44 mov r2, #32000 */
/* @0xd0d48 mov r0, sp */
/* @0xd0d4c bl 0xb664c <ldiv@plt> */
/* @0xd0d50 ldr r3, [r4, #0xc] */
/* @0xd0d54 ldr r5, [r4] */
/* @0xd0d58 bic r2, r3, #-16777216 */
/* @0xd0d5c ldr r6, [sp] */
/* @0xd0d60 cmp r2, #2 */
/* @0xd0d64 ldr r7, [sp, #0x4] */
/* @0xd0d68 beq 0xd0e24 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0xec> */
/* @0xd0d6c sub r3, r3, #1 */
/* @0xd0d70 bic r3, r3, #-16777216 */
/* @0xd0d74 bic r3, r3, #3 */
/* @0xd0d78 cmp r3, #0 */
/* @0xd0d7c beq 0xd0e5c <_Z17ARRAY_LVAL_RValueP8YYRValuei+0x124> */
/* @0xd0d80 mov r3, #0 */
/* @0xd0d84 mov r2, #2 */
/* @0xd0d88 str r3, [r4, #0x8] */
/* @0xd0d8c mov r0, r4 */
/* @0xd0d90 str r3, [r4] */
/* @0xd0d94 str r2, [r4, #0xc] */
/* @0xd0d98 bl 0xced9c <_Z14ARRAY_RefAllocPv> */
/* @0xd0d9c mov r5, r0 */
/* @0xd0da0 str r0, [r4] */
/* @0xd0da4 ldr r3, [r5, #0x10] */
/* @0xd0da8 cmp r3, r6 */
/* @0xd0dac ble 0xd0de4 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0xac> */
/* @0xd0db0 cmp r6, #0 */
/* @0xd0db4 blt 0xd0e0c <_Z17ARRAY_LVAL_RValueP8YYRValuei+0xd4> */
/* @0xd0db8 cmp r7, #0 */
/* @0xd0dbc ldr r3, [r5, #0x4] */
/* @0xd0dc0 addge r6, r3, r6, lsl #3 */
/* @0xd0dc4 blt 0xd0e18 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0xe0> */
/* @0xd0dc8 ldr r3, [r6] */
/* @0xd0dcc cmp r3, r7 */
/* @0xd0dd0 ble 0xd0e68 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0x130> */
/* @0xd0dd4 ldr r0, [r6, #0x4] */
/* @0xd0dd8 add r0, r0, r7, lsl #4 */
/* @0xd0ddc add sp, sp, #12 */
/* @0xd0de0 pop {r4, r5, r6, r7, pc} */
/* @0xd0de4 add r1, r6, #1 */
/* @0xd0de8 ldr r2, [pc, #0x9c] */
/* @0xd0dec str r1, [r5, #0x10] */
/* @0xd0df0 add r0, r5, #4 */
/* @0xd0df4 mov r3, #876 */
/* @0xd0df8 lsl r1, r1, #3 */
/* @0xd0dfc add r2, pc, r2 */
/* @0xd0e00 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xd0e04 cmp r6, #0 */
/* @0xd0e08 bge 0xd0db8 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0x80> */
/* @0xd0e0c cmp r7, #0 */
/* @0xd0e10 movge r6, #0 */
/* @0xd0e14 bge 0xd0dc8 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0x90> */
/* @0xd0e18 mov r0, #0 */
/* @0xd0e1c add sp, sp, #12 */
/* @0xd0e20 pop {r4, r5, r6, r7, pc} */
/* @0xd0e24 cmp r5, #0 */
/* @0xd0e28 beq 0xd0d6c <_Z17ARRAY_LVAL_RValueP8YYRValuei+0x34> */
/* @0xd0e2c ldr r3, [r5, #0x8] */
/* @0xd0e30 cmp r3, r4 */
/* @0xd0e34 beq 0xd0da4 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0x6c> */
/* @0xd0e38 ldr r3, [r5] */
/* @0xd0e3c cmp r3, #1 */
/* @0xd0e40 beq 0xd0da4 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0x6c> */
/* @0xd0e44 mov r0, r5 */
/* @0xd0e48 mov r1, r4 */
/* @0xd0e4c bl 0xd064c <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv> */
/* @0xd0e50 mov r5, r0 */
/* @0xd0e54 str r0, [r4] */
/* @0xd0e58 b 0xd0da4 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0x6c> */
/* @0xd0e5c mov r0, r4 */
/* @0xd0e60 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xd0e64 b 0xd0d80 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0x48> */
/* @0xd0e68 add r1, r7, #1 */
/* @0xd0e6c ldr r2, [pc, #0x1c] */
/* @0xd0e70 mov r0, r6 */
/* @0xd0e74 movw r3, #0x379 */
/* @0xd0e78 str r1, [r0], #4 */
/* @0xd0e7c add r2, pc, r2 */
/* @0xd0e80 lsl r1, r1, #4 */
/* @0xd0e84 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xd0e88 b 0xd0dd4 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0x9c> */
/* @0xd0e8c eoreq r1, r6, r0, lsl #8 */
/* @0xd0e90 eoreq r1, r6, r0, lsl #7 */

/* ── FUNC 0xd0e94 · REAL_RValue_Ex(RValue const*) · size=300 · insn=75 */
/* @0xd0e94 ldr r1, [r0, #0xc] */
/* @0xd0e98 push {r3, lr} */
/* @0xd0e9c mov r3, r0 */
/* @0xd0ea0 bic r1, r1, #-16777216 */
/* @0xd0ea4 cmp r1, #13 */
/* @0xd0ea8 addls pc, pc, r1, lsl #2 */
/* @0xd0eac b 0xd0f4c <_Z14REAL_RValue_ExPK6RValue+0xb8> */
/* @0xd0eb0 b 0xd0f08 <_Z14REAL_RValue_ExPK6RValue+0x74> */
/* @0xd0eb4 b 0xd0f70 <_Z14REAL_RValue_ExPK6RValue+0xdc> */
/* @0xd0eb8 b 0xd0ee8 <_Z14REAL_RValue_ExPK6RValue+0x54> */
/* @0xd0ebc b 0xd0f4c <_Z14REAL_RValue_ExPK6RValue+0xb8> */
/* @0xd0ec0 b 0xd0f4c <_Z14REAL_RValue_ExPK6RValue+0xb8> */
/* @0xd0ec4 b 0xd0f18 <_Z14REAL_RValue_ExPK6RValue+0x84> */
/* @0xd0ec8 b 0xd0f4c <_Z14REAL_RValue_ExPK6RValue+0xb8> */
/* @0xd0ecc b 0xd0f38 <_Z14REAL_RValue_ExPK6RValue+0xa4> */
/* @0xd0ed0 b 0xd0f4c <_Z14REAL_RValue_ExPK6RValue+0xb8> */
/* @0xd0ed4 b 0xd0f4c <_Z14REAL_RValue_ExPK6RValue+0xb8> */
/* @0xd0ed8 b 0xd0f24 <_Z14REAL_RValue_ExPK6RValue+0x90> */
/* @0xd0edc b 0xd0f4c <_Z14REAL_RValue_ExPK6RValue+0xb8> */
/* @0xd0ee0 b 0xd0f4c <_Z14REAL_RValue_ExPK6RValue+0xb8> */
/* @0xd0ee4 b 0xd0f08 <_Z14REAL_RValue_ExPK6RValue+0x74> */
/* @0xd0ee8 mov r0, r3 */
/* @0xd0eec mov r1, #0 */
/* @0xd0ef0 bl 0xd0d38 <_Z17ARRAY_LVAL_RValueP8YYRValuei> */
/* @0xd0ef4 ldr r1, [r0, #0xc] */
/* @0xd0ef8 mov r3, r0 */
/* @0xd0efc bic r2, r1, #-16777216 */
/* @0xd0f00 cmp r2, #0 */
/* @0xd0f04 bne 0xd0ea0 <_Z14REAL_RValue_ExPK6RValue+0xc> */
/* @0xd0f08 ldm r3, {r2, r3} */
/* @0xd0f0c mov r0, r2 */
/* @0xd0f10 mov r1, r3 */
/* @0xd0f14 pop {r3, pc} */
/* @0xd0f18 mov r2, #0 */
/* @0xd0f1c mov r3, r2 */
/* @0xd0f20 b 0xd0f0c <_Z14REAL_RValue_ExPK6RValue+0x78> */
/* @0xd0f24 ldm r3, {r0, r1} */
/* @0xd0f28 bl 0x319164 <__floatdidf> */
/* @0xd0f2c mov r2, r0 */
/* @0xd0f30 mov r3, r1 */
/* @0xd0f34 b 0xd0f0c <_Z14REAL_RValue_ExPK6RValue+0x78> */
/* @0xd0f38 ldr r2, [r3] */
/* @0xd0f3c vmov s15, r2 */
/* @0xd0f40 vcvt.f64.s32 d7, s15 */
/* @0xd0f44 vmov r2, r3, d7 */
/* @0xd0f48 b 0xd0f0c <_Z14REAL_RValue_ExPK6RValue+0x78> */
/* @0xd0f4c mvn r3, #-16777216 */
/* @0xd0f50 cmp r1, r3 */
/* @0xd0f54 beq 0xd0f94 <_Z14REAL_RValue_ExPK6RValue+0x100> */
/* @0xd0f58 ldr r0, [pc, #0x58] */
/* @0xd0f5c add r0, pc, r0 */
/* @0xd0f60 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xd0f64 mov r2, #0 */
/* @0xd0f68 mov r3, r2 */
/* @0xd0f6c b 0xd0f0c <_Z14REAL_RValue_ExPK6RValue+0x78> */
/* @0xd0f70 ldr r2, [r3] */
/* @0xd0f74 cmp r2, #0 */
/* @0xd0f78 beq 0xd0fb0 <_Z14REAL_RValue_ExPK6RValue+0x11c> */
/* @0xd0f7c ldr r0, [r2] */
/* @0xd0f80 cmp r0, #0 */
/* @0xd0f84 beq 0xd0fac <_Z14REAL_RValue_ExPK6RValue+0x118> */
/* @0xd0f88 mov r1, #0 */
/* @0xd0f8c pop {r3, lr} */
/* @0xd0f90 b 0xb6658 <strtod@plt> */
/* @0xd0f94 ldr r0, [pc, #0x20] */
/* @0xd0f98 add r0, pc, r0 */
/* @0xd0f9c bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xd0fa0 mov r2, #0 */
/* @0xd0fa4 mov r3, r2 */
/* @0xd0fa8 b 0xd0f0c <_Z14REAL_RValue_ExPK6RValue+0x78> */
/* @0xd0fac mov r2, r0 */
/* @0xd0fb0 mov r3, r2 */
/* @0xd0fb4 b 0xd0f0c <_Z14REAL_RValue_ExPK6RValue+0x78> */
/* @0xd0fb8 eoreq r1, r6, r0, asr r6 */
/* @0xd0fbc .word 0x002615fc */

/* ── FUNC 0xd0fc0 · PTR_RValue(RValue const*) · size=228 · insn=57 */
/* @0xd0fc0 push {r3, lr} */
/* @0xd0fc4 ldr r1, [r0, #0xc] */
/* @0xd0fc8 bic r1, r1, #-16777216 */
/* @0xd0fcc cmp r1, #13 */
/* @0xd0fd0 addls pc, pc, r1, lsl #2 */
/* @0xd0fd4 b 0xd1068 <_Z10PTR_RValuePK6RValue+0xa8> */
/* @0xd0fd8 b 0xd1020 <_Z10PTR_RValuePK6RValue+0x60> */
/* @0xd0fdc b 0xd1034 <_Z10PTR_RValuePK6RValue+0x74> */
/* @0xd0fe0 b 0xd105c <_Z10PTR_RValuePK6RValue+0x9c> */
/* @0xd0fe4 b 0xd1010 <_Z10PTR_RValuePK6RValue+0x50> */
/* @0xd0fe8 b 0xd1068 <_Z10PTR_RValuePK6RValue+0xa8> */
/* @0xd0fec b 0xd1018 <_Z10PTR_RValuePK6RValue+0x58> */
/* @0xd0ff0 b 0xd1010 <_Z10PTR_RValuePK6RValue+0x50> */
/* @0xd0ff4 b 0xd1010 <_Z10PTR_RValuePK6RValue+0x50> */
/* @0xd0ff8 b 0xd1068 <_Z10PTR_RValuePK6RValue+0xa8> */
/* @0xd0ffc b 0xd1068 <_Z10PTR_RValuePK6RValue+0xa8> */
/* @0xd1000 b 0xd1010 <_Z10PTR_RValuePK6RValue+0x50> */
/* @0xd1004 b 0xd1068 <_Z10PTR_RValuePK6RValue+0xa8> */
/* @0xd1008 b 0xd1068 <_Z10PTR_RValuePK6RValue+0xa8> */
/* @0xd100c b 0xd1020 <_Z10PTR_RValuePK6RValue+0x60> */
/* @0xd1010 ldr r0, [r0] */
/* @0xd1014 pop {r3, pc} */
/* @0xd1018 mov r0, #0 */
/* @0xd101c pop {r3, pc} */
/* @0xd1020 ldm r0, {r2, r3} */
/* @0xd1024 mov r0, r2 */
/* @0xd1028 mov r1, r3 */
/* @0xd102c bl 0x3194a0 <__fixdfdi> */
/* @0xd1030 pop {r3, pc} */
/* @0xd1034 ldr r0, [r0] */
/* @0xd1038 cmp r0, #0 */
/* @0xd103c popeq {r3, pc} */
/* @0xd1040 ldr r0, [r0] */
/* @0xd1044 cmp r0, #0 */
/* @0xd1048 popeq {r3, pc} */
/* @0xd104c mov r2, #16 */
/* @0xd1050 mov r1, #0 */
/* @0xd1054 bl 0xb6664 <strtoll@plt> */
/* @0xd1058 pop {r3, pc} */
/* @0xd105c mov r1, #0 */
/* @0xd1060 bl 0xd0d38 <_Z17ARRAY_LVAL_RValueP8YYRValuei> */
/* @0xd1064 b 0xd0fc4 <_Z10PTR_RValuePK6RValue+0x4> */
/* @0xd1068 mvn r3, #-16777216 */
/* @0xd106c cmp r1, r3 */
/* @0xd1070 beq 0xd1088 <_Z10PTR_RValuePK6RValue+0xc8> */
/* @0xd1074 ldr r0, [pc, #0x20] */
/* @0xd1078 add r0, pc, r0 */
/* @0xd107c bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xd1080 mov r0, #0 */
/* @0xd1084 pop {r3, pc} */
/* @0xd1088 ldr r0, [pc, #0x10] */
/* @0xd108c add r0, pc, r0 */
/* @0xd1090 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xd1094 mov r0, #0 */
/* @0xd1098 pop {r3, pc} */
/* @0xd109c eoreq r1, r6, r12, ror #10 */
/* @0xd10a0 eoreq r1, r6, r0, asr #10 */

/* ── FUNC 0xd10a4 · INT64_RValue(RValue const*) · size=268 · insn=67 */
/* @0xd10a4 push {r3, lr} */
/* @0xd10a8 ldr r1, [r0, #0xc] */
/* @0xd10ac bic r1, r1, #-16777216 */
/* @0xd10b0 cmp r1, #13 */
/* @0xd10b4 addls pc, pc, r1, lsl #2 */
/* @0xd10b8 b 0xd115c <_Z12INT64_RValuePK6RValue+0xb8> */
/* @0xd10bc b 0xd112c <_Z12INT64_RValuePK6RValue+0x88> */
/* @0xd10c0 b 0xd1108 <_Z12INT64_RValuePK6RValue+0x64> */
/* @0xd10c4 b 0xd1148 <_Z12INT64_RValuePK6RValue+0xa4> */
/* @0xd10c8 b 0xd10f4 <_Z12INT64_RValuePK6RValue+0x50> */
/* @0xd10cc b 0xd115c <_Z12INT64_RValuePK6RValue+0xb8> */
/* @0xd10d0 b 0xd1120 <_Z12INT64_RValuePK6RValue+0x7c> */
/* @0xd10d4 b 0xd115c <_Z12INT64_RValuePK6RValue+0xb8> */
/* @0xd10d8 b 0xd10f4 <_Z12INT64_RValuePK6RValue+0x50> */
/* @0xd10dc b 0xd115c <_Z12INT64_RValuePK6RValue+0xb8> */
/* @0xd10e0 b 0xd115c <_Z12INT64_RValuePK6RValue+0xb8> */
/* @0xd10e4 b 0xd1154 <_Z12INT64_RValuePK6RValue+0xb0> */
/* @0xd10e8 b 0xd115c <_Z12INT64_RValuePK6RValue+0xb8> */
/* @0xd10ec b 0xd115c <_Z12INT64_RValuePK6RValue+0xb8> */
/* @0xd10f0 b 0xd112c <_Z12INT64_RValuePK6RValue+0x88> */
/* @0xd10f4 ldr r2, [r0] */
/* @0xd10f8 asr r3, r2, #31 */
/* @0xd10fc mov r0, r2 */
/* @0xd1100 mov r1, r3 */
/* @0xd1104 pop {r3, pc} */
/* @0xd1108 ldr r3, [r0] */
/* @0xd110c cmp r3, #0 */
/* @0xd1110 beq 0xd1120 <_Z12INT64_RValuePK6RValue+0x7c> */
/* @0xd1114 ldr r0, [r3] */
/* @0xd1118 cmp r0, #0 */
/* @0xd111c bne 0xd1180 <_Z12INT64_RValuePK6RValue+0xdc> */
/* @0xd1120 mov r2, #0 */
/* @0xd1124 mov r3, #0 */
/* @0xd1128 b 0xd10fc <_Z12INT64_RValuePK6RValue+0x58> */
/* @0xd112c ldm r0, {r2, r3} */
/* @0xd1130 mov r0, r2 */
/* @0xd1134 mov r1, r3 */
/* @0xd1138 bl 0x3194a0 <__fixdfdi> */
/* @0xd113c mov r2, r0 */
/* @0xd1140 mov r3, r1 */
/* @0xd1144 b 0xd10fc <_Z12INT64_RValuePK6RValue+0x58> */
/* @0xd1148 mov r1, #0 */
/* @0xd114c bl 0xd0d38 <_Z17ARRAY_LVAL_RValueP8YYRValuei> */
/* @0xd1150 b 0xd10a8 <_Z12INT64_RValuePK6RValue+0x4> */
/* @0xd1154 ldm r0, {r2, r3} */
/* @0xd1158 b 0xd10fc <_Z12INT64_RValuePK6RValue+0x58> */
/* @0xd115c mvn r3, #-16777216 */
/* @0xd1160 cmp r1, r3 */
/* @0xd1164 beq 0xd1190 <_Z12INT64_RValuePK6RValue+0xec> */
/* @0xd1168 ldr r0, [pc, #0x38] */
/* @0xd116c add r0, pc, r0 */
/* @0xd1170 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xd1174 mov r2, #0 */
/* @0xd1178 mov r3, #0 */
/* @0xd117c b 0xd10fc <_Z12INT64_RValuePK6RValue+0x58> */
/* @0xd1180 mov r1, #0 */
/* @0xd1184 mov r2, #10 */
/* @0xd1188 pop {r3, lr} */
/* @0xd118c b 0xb6664 <strtoll@plt> */
/* @0xd1190 ldr r0, [pc, #0x14] */
/* @0xd1194 add r0, pc, r0 */
/* @0xd1198 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xd119c mov r2, #0 */
/* @0xd11a0 mov r3, #0 */
/* @0xd11a4 b 0xd10fc <_Z12INT64_RValuePK6RValue+0x58> */
/* @0xd11a8 .word 0x002614b0 */
/* @0xd11ac eoreq r1, r6, r0, ror r4 */

/* ── FUNC 0xd11b0 · INT32_RValue(RValue const*) · size=228 · insn=57 */
/* @0xd11b0 push {r3, lr} */
/* @0xd11b4 ldr r1, [r0, #0xc] */
/* @0xd11b8 bic r1, r1, #-16777216 */
/* @0xd11bc cmp r1, #13 */
/* @0xd11c0 addls pc, pc, r1, lsl #2 */
/* @0xd11c4 b 0xd1258 <_Z12INT32_RValuePK6RValue+0xa8> */
/* @0xd11c8 b 0xd1210 <_Z12INT32_RValuePK6RValue+0x60> */
/* @0xd11cc b 0xd1224 <_Z12INT32_RValuePK6RValue+0x74> */
/* @0xd11d0 b 0xd124c <_Z12INT32_RValuePK6RValue+0x9c> */
/* @0xd11d4 b 0xd1200 <_Z12INT32_RValuePK6RValue+0x50> */
/* @0xd11d8 b 0xd1258 <_Z12INT32_RValuePK6RValue+0xa8> */
/* @0xd11dc b 0xd1208 <_Z12INT32_RValuePK6RValue+0x58> */
/* @0xd11e0 b 0xd1258 <_Z12INT32_RValuePK6RValue+0xa8> */
/* @0xd11e4 b 0xd1200 <_Z12INT32_RValuePK6RValue+0x50> */
/* @0xd11e8 b 0xd1258 <_Z12INT32_RValuePK6RValue+0xa8> */
/* @0xd11ec b 0xd1258 <_Z12INT32_RValuePK6RValue+0xa8> */
/* @0xd11f0 b 0xd1200 <_Z12INT32_RValuePK6RValue+0x50> */
/* @0xd11f4 b 0xd1258 <_Z12INT32_RValuePK6RValue+0xa8> */
/* @0xd11f8 b 0xd1258 <_Z12INT32_RValuePK6RValue+0xa8> */
/* @0xd11fc b 0xd1210 <_Z12INT32_RValuePK6RValue+0x60> */
/* @0xd1200 ldr r0, [r0] */
/* @0xd1204 pop {r3, pc} */
/* @0xd1208 mov r0, #0 */
/* @0xd120c pop {r3, pc} */
/* @0xd1210 ldm r0, {r2, r3} */
/* @0xd1214 vmov d7, r2, r3 */
/* @0xd1218 vcvt.s32.f64 s15, d7 */
/* @0xd121c vmov r0, s15 */
/* @0xd1220 pop {r3, pc} */
/* @0xd1224 ldr r0, [r0] */
/* @0xd1228 cmp r0, #0 */
/* @0xd122c popeq {r3, pc} */
/* @0xd1230 ldr r0, [r0] */
/* @0xd1234 cmp r0, #0 */
/* @0xd1238 popeq {r3, pc} */
/* @0xd123c mov r1, #0 */
/* @0xd1240 mov r2, #10 */
/* @0xd1244 pop {r3, lr} */
/* @0xd1248 b 0xb6670 <strtol@plt> */
/* @0xd124c mov r1, #0 */
/* @0xd1250 bl 0xd0d38 <_Z17ARRAY_LVAL_RValueP8YYRValuei> */
/* @0xd1254 b 0xd11b4 <_Z12INT32_RValuePK6RValue+0x4> */
/* @0xd1258 mvn r3, #-16777216 */
/* @0xd125c cmp r1, r3 */
/* @0xd1260 beq 0xd1278 <_Z12INT32_RValuePK6RValue+0xc8> */
/* @0xd1264 ldr r0, [pc, #0x20] */
/* @0xd1268 add r0, pc, r0 */
/* @0xd126c bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xd1270 mov r0, #0 */
/* @0xd1274 pop {r3, pc} */
/* @0xd1278 ldr r0, [pc, #0x10] */
/* @0xd127c add r0, pc, r0 */
/* @0xd1280 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xd1284 mov r0, #0 */
/* @0xd1288 pop {r3, pc} */
/* @0xd128c eoreq r1, r6, r12, ror #7 */
/* @0xd1290 eoreq r1, r6, r0, asr #7 */

/* ── FUNC 0xd1294 · BOOL_RValue(RValue const*) · size=296 · insn=74 */
/* @0xd1294 push {r3, lr} */
/* @0xd1298 ldr r1, [r0, #0xc] */
/* @0xd129c bic r1, r1, #-16777216 */
/* @0xd12a0 cmp r1, #13 */
/* @0xd12a4 addls pc, pc, r1, lsl #2 */
/* @0xd12a8 b 0xd1380 <_Z11BOOL_RValuePK6RValue+0xec> */
/* @0xd12ac b 0xd1300 <_Z11BOOL_RValuePK6RValue+0x6c> */
/* @0xd12b0 b 0xd1320 <_Z11BOOL_RValuePK6RValue+0x8c> */
/* @0xd12b4 b 0xd135c <_Z11BOOL_RValuePK6RValue+0xc8> */
/* @0xd12b8 b 0xd12e4 <_Z11BOOL_RValuePK6RValue+0x50> */
/* @0xd12bc b 0xd1380 <_Z11BOOL_RValuePK6RValue+0xec> */
/* @0xd12c0 b 0xd12f8 <_Z11BOOL_RValuePK6RValue+0x64> */
/* @0xd12c4 b 0xd1380 <_Z11BOOL_RValuePK6RValue+0xec> */
/* @0xd12c8 b 0xd12e4 <_Z11BOOL_RValuePK6RValue+0x50> */
/* @0xd12cc b 0xd1380 <_Z11BOOL_RValuePK6RValue+0xec> */
/* @0xd12d0 b 0xd1380 <_Z11BOOL_RValuePK6RValue+0xec> */
/* @0xd12d4 b 0xd1368 <_Z11BOOL_RValuePK6RValue+0xd4> */
/* @0xd12d8 b 0xd1380 <_Z11BOOL_RValuePK6RValue+0xec> */
/* @0xd12dc b 0xd1380 <_Z11BOOL_RValuePK6RValue+0xec> */
/* @0xd12e0 b 0xd1300 <_Z11BOOL_RValuePK6RValue+0x6c> */
/* @0xd12e4 ldr r0, [r0] */
/* @0xd12e8 cmp r0, #0 */
/* @0xd12ec movle r0, #0 */
/* @0xd12f0 movgt r0, #1 */
/* @0xd12f4 pop {r3, pc} */
/* @0xd12f8 mov r0, #0 */
/* @0xd12fc pop {r3, pc} */
/* @0xd1300 vmov.f64 d7, #5.000000e-01 */
/* @0xd1304 ldm r0, {r2, r3} */
/* @0xd1308 vmov d6, r2, r3 */
/* @0xd130c vcmpe.f64 d6, d7 */
/* @0xd1310 vmrs APSR_nzcv, fpscr */
/* @0xd1314 movle r0, #0 */
/* @0xd1318 movgt r0, #1 */
/* @0xd131c pop {r3, pc} */
/* @0xd1320 ldr r0, [r0] */
/* @0xd1324 cmp r0, #0 */
/* @0xd1328 popeq {r3, pc} */
/* @0xd132c ldr r0, [r0] */
/* @0xd1330 cmp r0, #0 */
/* @0xd1334 popeq {r3, pc} */
/* @0xd1338 mov r1, #0 */
/* @0xd133c bl 0xb6658 <strtod@plt> */
/* @0xd1340 vmov.f64 d7, #5.000000e-01 */
/* @0xd1344 vmov d6, r0, r1 */
/* @0xd1348 vcmpe.f64 d6, d7 */
/* @0xd134c vmrs APSR_nzcv, fpscr */
/* @0xd1350 movle r0, #0 */
/* @0xd1354 movgt r0, #1 */
/* @0xd1358 pop {r3, pc} */
/* @0xd135c mov r1, #0 */
/* @0xd1360 bl 0xd0d38 <_Z17ARRAY_LVAL_RValueP8YYRValuei> */
/* @0xd1364 b 0xd1298 <_Z11BOOL_RValuePK6RValue+0x4> */
/* @0xd1368 ldm r0, {r2, r3} */
/* @0xd136c cmp r2, #1 */
/* @0xd1370 sbcs r1, r3, #0 */
/* @0xd1374 movlt r0, #0 */
/* @0xd1378 movge r0, #1 */
/* @0xd137c pop {r3, pc} */
/* @0xd1380 mvn r3, #-16777216 */
/* @0xd1384 cmp r1, r3 */
/* @0xd1388 beq 0xd13a0 <_Z11BOOL_RValuePK6RValue+0x10c> */
/* @0xd138c ldr r0, [pc, #0x20] */
/* @0xd1390 add r0, pc, r0 */
/* @0xd1394 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xd1398 mov r0, #0 */
/* @0xd139c pop {r3, pc} */
/* @0xd13a0 ldr r0, [pc, #0x10] */
/* @0xd13a4 add r0, pc, r0 */
/* @0xd13a8 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xd13ac mov r0, #0 */
/* @0xd13b0 pop {r3, pc} */
/* @0xd13b4 .word 0x002612fc */
/* @0xd13b8 .word 0x002612d0 */
