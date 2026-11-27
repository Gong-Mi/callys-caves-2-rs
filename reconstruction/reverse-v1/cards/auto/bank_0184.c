/* libyoyo.so 覆盖卡组 0184
 * 函数 0x203c8c..0x205334，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x203c8c · CDS_Map::FindFirst() · size=56 · insn=14 */
/* @0x203c8c ldr r1, [r0] */
/* @0x203c90 mov r3, #0 */
/* @0x203c94 ldr r12, [r1] */
/* @0x203c98 b 0x203ca8 <_ZN7CDS_Map9FindFirstEv+0x1c> */
/* @0x203c9c ldr r2, [r1, #0x4] */
/* @0x203ca0 cmp r3, r2 */
/* @0x203ca4 bgt 0x203cc0 <_ZN7CDS_Map9FindFirstEv+0x34> */
/* @0x203ca8 ldr r0, [r12, r3, lsl #3] */
/* @0x203cac add r3, r3, #1 */
/* @0x203cb0 cmp r0, #0 */
/* @0x203cb4 beq 0x203c9c <_ZN7CDS_Map9FindFirstEv+0x10> */
/* @0x203cb8 ldr r0, [r0, #0xc] */
/* @0x203cbc bx lr */
/* @0x203cc0 bx lr */

/* ── FUNC 0x203cc4 · CDS_Map::FindLast() · size=168 · insn=42 */
/* @0x203cc4 push {r4, r5, r6} */
/* @0x203cc8 mov r2, #0 */
/* @0x203ccc ldr r5, [r0] */
/* @0x203cd0 ldr r6, [r5] */
/* @0x203cd4 b 0x203ce8 <_ZN7CDS_Map8FindLastEv+0x24> */
/* @0x203cd8 ldr r1, [r5, #0x4] */
/* @0x203cdc add r2, r2, #1 */
/* @0x203ce0 cmp r2, r1 */
/* @0x203ce4 bgt 0x203d64 <_ZN7CDS_Map8FindLastEv+0xa0> */
/* @0x203ce8 ldr r3, [r6, r2, lsl #3] */
/* @0x203cec cmp r3, #0 */
/* @0x203cf0 beq 0x203cd8 <_ZN7CDS_Map8FindLastEv+0x14> */
/* @0x203cf4 mov r0, #0 */
/* @0x203cf8 b 0x203d00 <_ZN7CDS_Map8FindLastEv+0x3c> */
/* @0x203cfc mov r0, r12 */
/* @0x203d00 cmp r3, #0 */
/* @0x203d04 beq 0x203d5c <_ZN7CDS_Map8FindLastEv+0x98> */
/* @0x203d08 ldr r12, [r3, #0xc] */
/* @0x203d0c cmp r12, #0 */
/* @0x203d10 beq 0x203d5c <_ZN7CDS_Map8FindLastEv+0x98> */
/* @0x203d14 ldr r3, [r3, #0x4] */
/* @0x203d18 cmp r3, #0 */
/* @0x203d1c bne 0x203cfc <_ZN7CDS_Map8FindLastEv+0x38> */
/* @0x203d20 ldr r4, [r5, #0x4] */
/* @0x203d24 add r0, r2, #1 */
/* @0x203d28 cmp r0, r4 */
/* @0x203d2c bgt 0x203d54 <_ZN7CDS_Map8FindLastEv+0x90> */
/* @0x203d30 add r1, r6, r2, lsl #3 */
/* @0x203d34 ldr r3, [r1, #0x8] */
/* @0x203d38 mov r2, r0 */
/* @0x203d3c add r1, r1, #8 */
/* @0x203d40 add r0, r0, #1 */
/* @0x203d44 cmp r3, #0 */
/* @0x203d48 bne 0x203cfc <_ZN7CDS_Map8FindLastEv+0x38> */
/* @0x203d4c cmp r0, r4 */
/* @0x203d50 ble 0x203d34 <_ZN7CDS_Map8FindLastEv+0x70> */
/* @0x203d54 mvn r2, #0 */
/* @0x203d58 b 0x203cfc <_ZN7CDS_Map8FindLastEv+0x38> */
/* @0x203d5c pop {r4, r5, r6} */
/* @0x203d60 bx lr */
/* @0x203d64 mvn r2, #0 */
/* @0x203d68 b 0x203cf4 <_ZN7CDS_Map8FindLastEv+0x30> */

/* ── FUNC 0x203d6c · CDS_Priority::WriteToString(char const*&) · size=188 · insn=47 */
/* @0x203d6c push {r3, r4, r5, r6, r7, lr} */
/* @0x203d70 mov r4, r0 */
/* @0x203d74 mov r0, #32 */
/* @0x203d78 mov r7, r1 */
/* @0x203d7c bl 0x27c524 <_Znwj> */
/* @0x203d80 mov r1, #0 */
/* @0x203d84 mov r6, r0 */
/* @0x203d88 bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x203d8c mov r0, r6 */
/* @0x203d90 movw r1, #0x1f6 */
/* @0x203d94 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x203d98 mov r0, r6 */
/* @0x203d9c ldr r1, [r4, #0x4] */
/* @0x203da0 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x203da4 ldr r3, [r4, #0x4] */
/* @0x203da8 cmp r3, #0 */
/* @0x203dac movgt r5, #0 */
/* @0x203db0 ble 0x203e00 <_ZN12CDS_Priority13WriteToStringERPKc+0x94> */
/* @0x203db4 ldr r1, [r4, #0x14] */
/* @0x203db8 mov r0, r6 */
/* @0x203dbc add r1, r1, r5, lsl #4 */
/* @0x203dc0 add r5, r5, #1 */
/* @0x203dc4 bl 0x202af8 <_Z10WriteValueR7CStreamR6RValue> */
/* @0x203dc8 ldr r3, [r4, #0x4] */
/* @0x203dcc cmp r3, r5 */
/* @0x203dd0 bgt 0x203db4 <_ZN12CDS_Priority13WriteToStringERPKc+0x48> */
/* @0x203dd4 cmp r3, #0 */
/* @0x203dd8 ble 0x203e00 <_ZN12CDS_Priority13WriteToStringERPKc+0x94> */
/* @0x203ddc mov r5, #0 */
/* @0x203de0 ldr r1, [r4, #0xc] */
/* @0x203de4 mov r0, r6 */
/* @0x203de8 add r1, r1, r5, lsl #4 */
/* @0x203dec add r5, r5, #1 */
/* @0x203df0 bl 0x202af8 <_Z10WriteValueR7CStreamR6RValue> */
/* @0x203df4 ldr r3, [r4, #0x4] */
/* @0x203df8 cmp r3, r5 */
/* @0x203dfc bgt 0x203de0 <_ZN12CDS_Priority13WriteToStringERPKc+0x74> */
/* @0x203e00 mov r1, r7 */
/* @0x203e04 mov r0, r6 */
/* @0x203e08 bl 0x2024b0 <_ZN7CStream15ConvertToStringERPKc> */
/* @0x203e0c cmp r6, #0 */
/* @0x203e10 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x203e14 mov r0, r6 */
/* @0x203e18 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x203e1c mov r0, r6 */
/* @0x203e20 pop {r3, r4, r5, r6, r7, lr} */
/* @0x203e24 b 0x27d1d0 <_ZdlPv> */

/* ── FUNC 0x203e28 · CDS_Priority::Mark4GC(unsigned int*, int) · size=124 · insn=31 */
/* @0x203e28 push {r3, r4, r5, r6, r7, lr} */
/* @0x203e2c mov r4, r0 */
/* @0x203e30 ldr r3, [r0, #0x8] */
/* @0x203e34 mov r6, r1 */
/* @0x203e38 mov r7, r2 */
/* @0x203e3c cmp r3, #0 */
/* @0x203e40 movgt r5, #0 */
/* @0x203e44 ble 0x203e6c <_ZN12CDS_Priority7Mark4GCEPji+0x44> */
/* @0x203e48 ldr r0, [r4, #0xc] */
/* @0x203e4c mov r1, r6 */
/* @0x203e50 mov r2, r7 */
/* @0x203e54 add r0, r0, r5, lsl #4 */
/* @0x203e58 add r5, r5, #1 */
/* @0x203e5c bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji> */
/* @0x203e60 ldr r3, [r4, #0x8] */
/* @0x203e64 cmp r3, r5 */
/* @0x203e68 bgt 0x203e48 <_ZN12CDS_Priority7Mark4GCEPji+0x20> */
/* @0x203e6c ldr r3, [r4, #0x10] */
/* @0x203e70 cmp r3, #0 */
/* @0x203e74 pople {r3, r4, r5, r6, r7, pc} */
/* @0x203e78 mov r5, #0 */
/* @0x203e7c ldr r0, [r4, #0x14] */
/* @0x203e80 mov r1, r6 */
/* @0x203e84 mov r2, r7 */
/* @0x203e88 add r0, r0, r5, lsl #4 */
/* @0x203e8c add r5, r5, #1 */
/* @0x203e90 bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji> */
/* @0x203e94 ldr r3, [r4, #0x10] */
/* @0x203e98 cmp r3, r5 */
/* @0x203e9c bgt 0x203e7c <_ZN12CDS_Priority7Mark4GCEPji+0x54> */
/* @0x203ea0 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x203ea4 · CDS_Priority::Add4GC(CGCGeneration*) · size=112 · insn=28 */
/* @0x203ea4 ldr r3, [r0, #0x8] */
/* @0x203ea8 push {r4, r5, r6, lr} */
/* @0x203eac cmp r3, #0 */
/* @0x203eb0 mov r4, r0 */
/* @0x203eb4 mov r6, r1 */
/* @0x203eb8 movgt r5, #0 */
/* @0x203ebc ble 0x203ee0 <_ZN12CDS_Priority6Add4GCEP13CGCGeneration+0x3c> */
/* @0x203ec0 ldr r0, [r4, #0xc] */
/* @0x203ec4 mov r1, r6 */
/* @0x203ec8 add r0, r0, r5, lsl #4 */
/* @0x203ecc add r5, r5, #1 */
/* @0x203ed0 bl 0x191bac <_Z17RVALUE_GC_ADDROOTPK6RValueP13CGCGeneration> */
/* @0x203ed4 ldr r3, [r4, #0x8] */
/* @0x203ed8 cmp r3, r5 */
/* @0x203edc bgt 0x203ec0 <_ZN12CDS_Priority6Add4GCEP13CGCGeneration+0x1c> */
/* @0x203ee0 ldr r3, [r4, #0x10] */
/* @0x203ee4 cmp r3, #0 */
/* @0x203ee8 pople {r4, r5, r6, pc} */
/* @0x203eec mov r5, #0 */
/* @0x203ef0 ldr r0, [r4, #0x14] */
/* @0x203ef4 mov r1, r6 */
/* @0x203ef8 add r0, r0, r5, lsl #4 */
/* @0x203efc add r5, r5, #1 */
/* @0x203f00 bl 0x191bac <_Z17RVALUE_GC_ADDROOTPK6RValueP13CGCGeneration> */
/* @0x203f04 ldr r3, [r4, #0x10] */
/* @0x203f08 cmp r3, r5 */
/* @0x203f0c bgt 0x203ef0 <_ZN12CDS_Priority6Add4GCEP13CGCGeneration+0x4c> */
/* @0x203f10 pop {r4, r5, r6, pc} */

/* ── FUNC 0x203f14 · CDS_Priority::MarkOnlyChildren4GC(unsigned int*, int) · size=124 · insn=31 */
/* @0x203f14 push {r3, r4, r5, r6, r7, lr} */
/* @0x203f18 mov r4, r0 */
/* @0x203f1c ldr r3, [r0, #0x8] */
/* @0x203f20 mov r6, r1 */
/* @0x203f24 mov r7, r2 */
/* @0x203f28 cmp r3, #0 */
/* @0x203f2c movgt r5, #0 */
/* @0x203f30 ble 0x203f58 <_ZN12CDS_Priority19MarkOnlyChildren4GCEPji+0x44> */
/* @0x203f34 ldr r0, [r4, #0xc] */
/* @0x203f38 mov r1, r6 */
/* @0x203f3c mov r2, r7 */
/* @0x203f40 add r0, r0, r5, lsl #4 */
/* @0x203f44 add r5, r5, #1 */
/* @0x203f48 bl 0x191f5c <_Z18RVALUE_GC_THISONLYPK6RValuePji> */
/* @0x203f4c ldr r3, [r4, #0x8] */
/* @0x203f50 cmp r3, r5 */
/* @0x203f54 bgt 0x203f34 <_ZN12CDS_Priority19MarkOnlyChildren4GCEPji+0x20> */
/* @0x203f58 ldr r3, [r4, #0x10] */
/* @0x203f5c cmp r3, #0 */
/* @0x203f60 pople {r3, r4, r5, r6, r7, pc} */
/* @0x203f64 mov r5, #0 */
/* @0x203f68 ldr r0, [r4, #0x14] */
/* @0x203f6c mov r1, r6 */
/* @0x203f70 mov r2, r7 */
/* @0x203f74 add r0, r0, r5, lsl #4 */
/* @0x203f78 add r5, r5, #1 */
/* @0x203f7c bl 0x191f5c <_Z18RVALUE_GC_THISONLYPK6RValuePji> */
/* @0x203f80 ldr r3, [r4, #0x10] */
/* @0x203f84 cmp r3, r5 */
/* @0x203f88 bgt 0x203f68 <_ZN12CDS_Priority19MarkOnlyChildren4GCEPji+0x54> */
/* @0x203f8c pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x203f90 · CDS_Priority::Find(RValue*) · size=112 · insn=28 */
/* @0x203f90 ldr r3, [r0, #0x4] */
/* @0x203f94 push {r4, r5, r6, r7, r8, lr} */
/* @0x203f98 cmp r3, #0 */
/* @0x203f9c mov r5, r0 */
/* @0x203fa0 mov r8, r1 */
/* @0x203fa4 ble 0x203ff4 <_ZN12CDS_Priority4FindEP6RValue+0x64> */
/* @0x203fa8 ldr r7, [pc, #0x4c] */
/* @0x203fac mov r4, #0 */
/* @0x203fb0 ldr r7, [pc, r7] */
/* @0x203fb4 b 0x203fc4 <_ZN12CDS_Priority4FindEP6RValue+0x34> */
/* @0x203fb8 ldr r3, [r5, #0x4] */
/* @0x203fbc cmp r3, r4 */
/* @0x203fc0 ble 0x203ff4 <_ZN12CDS_Priority4FindEP6RValue+0x64> */
/* @0x203fc4 ldr r0, [r5, #0xc] */
/* @0x203fc8 lsl r6, r4, #4 */
/* @0x203fcc mov r1, r8 */
/* @0x203fd0 ldrd r2, r3, [r7] */
/* @0x203fd4 add r0, r0, r6 */
/* @0x203fd8 add r4, r4, #1 */
/* @0x203fdc bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x203fe0 cmp r0, #0 */
/* @0x203fe4 bne 0x203fb8 <_ZN12CDS_Priority4FindEP6RValue+0x28> */
/* @0x203fe8 ldr r0, [r5, #0x14] */
/* @0x203fec add r0, r0, r6 */
/* @0x203ff0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x203ff4 mov r0, #0 */
/* @0x203ff8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x203ffc ldrsbeq sp, [lr], -r4 */

/* ── FUNC 0x204000 · CDS_Priority::FindMin() · size=124 · insn=31 */
/* @0x204000 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x204004 mov r8, r0 */
/* @0x204008 ldr r0, [r0, #0x4] */
/* @0x20400c cmp r0, #0 */
/* @0x204010 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x204014 cmp r0, #1 */
/* @0x204018 ble 0x204070 <_ZN12CDS_Priority7FindMinEv+0x70> */
/* @0x20401c ldr r9, [pc, #0x54] */
/* @0x204020 mov r4, #1 */
/* @0x204024 mov r6, #0 */
/* @0x204028 ldr r9, [pc, r9] */
/* @0x20402c ldr r1, [r8, #0x14] */
/* @0x204030 lsl r7, r4, #4 */
/* @0x204034 lsl r5, r6, #4 */
/* @0x204038 ldrd r2, r3, [r9] */
/* @0x20403c add r0, r1, r7 */
/* @0x204040 add r1, r1, r5 */
/* @0x204044 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x204048 ldr r3, [r8, #0x4] */
/* @0x20404c cmp r0, #0 */
/* @0x204050 movlt r6, r4 */
/* @0x204054 add r4, r4, #1 */
/* @0x204058 movlt r5, r7 */
/* @0x20405c cmp r3, r4 */
/* @0x204060 bgt 0x20402c <_ZN12CDS_Priority7FindMinEv+0x2c> */
/* @0x204064 ldr r0, [r8, #0xc] */
/* @0x204068 add r0, r0, r5 */
/* @0x20406c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x204070 mov r5, #0 */
/* @0x204074 b 0x204064 <_ZN12CDS_Priority7FindMinEv+0x64> */
/* @0x204078 andseq sp, lr, r12, asr r3 */

/* ── FUNC 0x20407c · CDS_Priority::FindMax() · size=124 · insn=31 */
/* @0x20407c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x204080 mov r8, r0 */
/* @0x204084 ldr r0, [r0, #0x4] */
/* @0x204088 cmp r0, #0 */
/* @0x20408c popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x204090 cmp r0, #1 */
/* @0x204094 ble 0x2040ec <_ZN12CDS_Priority7FindMaxEv+0x70> */
/* @0x204098 ldr r9, [pc, #0x54] */
/* @0x20409c mov r4, #1 */
/* @0x2040a0 mov r6, #0 */
/* @0x2040a4 ldr r9, [pc, r9] */
/* @0x2040a8 ldr r1, [r8, #0x14] */
/* @0x2040ac lsl r5, r4, #4 */
/* @0x2040b0 lsl r7, r6, #4 */
/* @0x2040b4 ldrd r2, r3, [r9] */
/* @0x2040b8 add r0, r1, r5 */
/* @0x2040bc add r1, r1, r7 */
/* @0x2040c0 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x2040c4 ldr r3, [r8, #0x4] */
/* @0x2040c8 cmp r0, #0 */
/* @0x2040cc movgt r6, r4 */
/* @0x2040d0 add r4, r4, #1 */
/* @0x2040d4 movle r5, r7 */
/* @0x2040d8 cmp r3, r4 */
/* @0x2040dc bgt 0x2040a8 <_ZN12CDS_Priority7FindMaxEv+0x2c> */
/* @0x2040e0 ldr r0, [r8, #0xc] */
/* @0x2040e4 add r0, r0, r5 */
/* @0x2040e8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2040ec mov r5, #0 */
/* @0x2040f0 b 0x2040e0 <_ZN12CDS_Priority7FindMaxEv+0x64> */
/* @0x2040f4 andseq sp, lr, r0, ror #5 */

/* ── FUNC 0x2040f8 · CDS_Priority::Empty() · size=16 · insn=4 */
/* @0x2040f8 ldr r0, [r0, #0x4] */
/* @0x2040fc rsbs r0, r0, #1 */
/* @0x204100 movlo r0, #0 */
/* @0x204104 bx lr */

/* ── FUNC 0x204108 · CDS_Grid::WriteToString(char const*&) · size=192 · insn=48 */
/* @0x204108 push {r4, r5, r6, r7, r8, lr} */
/* @0x20410c mov r5, r0 */
/* @0x204110 mov r0, #32 */
/* @0x204114 mov r8, r1 */
/* @0x204118 bl 0x27c524 <_Znwj> */
/* @0x20411c mov r1, #0 */
/* @0x204120 mov r7, r0 */
/* @0x204124 bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x204128 mov r0, r7 */
/* @0x20412c movw r1, #0x25a */
/* @0x204130 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x204134 mov r0, r7 */
/* @0x204138 ldr r1, [r5, #0x4] */
/* @0x20413c bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x204140 mov r0, r7 */
/* @0x204144 ldr r1, [r5, #0x8] */
/* @0x204148 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x20414c ldr r3, [r5, #0x4] */
/* @0x204150 cmp r3, #0 */
/* @0x204154 ble 0x2041a0 <_ZN8CDS_Grid13WriteToStringERPKc+0x98> */
/* @0x204158 ldr r2, [r5, #0x8] */
/* @0x20415c mov r6, #0 */
/* @0x204160 cmp r2, #0 */
/* @0x204164 ble 0x204194 <_ZN8CDS_Grid13WriteToStringERPKc+0x8c> */
/* @0x204168 mov r4, #0 */
/* @0x20416c mla r3, r3, r4, r6 */
/* @0x204170 ldr r1, [r5] */
/* @0x204174 mov r0, r7 */
/* @0x204178 add r4, r4, #1 */
/* @0x20417c add r1, r1, r3, lsl #4 */
/* @0x204180 bl 0x202af8 <_Z10WriteValueR7CStreamR6RValue> */
/* @0x204184 ldr r2, [r5, #0x8] */
/* @0x204188 ldr r3, [r5, #0x4] */
/* @0x20418c cmp r2, r4 */
/* @0x204190 bgt 0x20416c <_ZN8CDS_Grid13WriteToStringERPKc+0x64> */
/* @0x204194 add r6, r6, #1 */
/* @0x204198 cmp r6, r3 */
/* @0x20419c blt 0x204160 <_ZN8CDS_Grid13WriteToStringERPKc+0x58> */
/* @0x2041a0 mov r1, r8 */
/* @0x2041a4 mov r0, r7 */
/* @0x2041a8 bl 0x2024b0 <_ZN7CStream15ConvertToStringERPKc> */
/* @0x2041ac cmp r7, #0 */
/* @0x2041b0 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x2041b4 mov r0, r7 */
/* @0x2041b8 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x2041bc mov r0, r7 */
/* @0x2041c0 pop {r4, r5, r6, r7, r8, lr} */
/* @0x2041c4 b 0x27d1d0 <_ZdlPv> */

/* ── FUNC 0x2041c8 · CDS_Grid::Get_Sum(RValue&, int, int, int, int) · size=256 · insn=64 */
/* @0x2041c8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2041cc mov r8, r1 */
/* @0x2041d0 ldr r12, [sp, #0x20] */
/* @0x2041d4 mov r9, r0 */
/* @0x2041d8 mov r0, #0 */
/* @0x2041dc str r0, [r8] */
/* @0x2041e0 cmp r2, r12 */
/* @0x2041e4 str r0, [r8, #0x4] */
/* @0x2041e8 str r0, [r8, #0xc] */
/* @0x2041ec lsrge r0, r12, #31 */
/* @0x2041f0 lsrlt r0, r2, #31 */
/* @0x2041f4 ldr r1, [sp, #0x24] */
/* @0x2041f8 cmp r2, r12 */
/* @0x2041fc movlt r5, r2 */
/* @0x204200 movge r5, r12 */
/* @0x204204 cmp r0, #0 */
/* @0x204208 movne r5, #0 */
/* @0x20420c cmp r3, r1 */
/* @0x204210 movlt r0, r3 */
/* @0x204214 movge r0, r1 */
/* @0x204218 cmp r3, r1 */
/* @0x20421c lsrlt r7, r3, #31 */
/* @0x204220 lsrge r7, r1, #31 */
/* @0x204224 cmp r2, r12 */
/* @0x204228 movge r6, r2 */
/* @0x20422c movlt r6, r12 */
/* @0x204230 cmp r7, #0 */
/* @0x204234 ldr r12, [r9, #0x4] */
/* @0x204238 moveq r7, r0 */
/* @0x20423c movne r7, #0 */
/* @0x204240 cmp r3, r1 */
/* @0x204244 movge r10, r3 */
/* @0x204248 movlt r10, r1 */
/* @0x20424c cmp r6, r12 */
/* @0x204250 subge r3, r12, #1 */
/* @0x204254 movlt r3, r6 */
/* @0x204258 cmp r5, r3 */
/* @0x20425c bgt 0x2042c4 <_ZN8CDS_Grid7Get_SumER6RValueiiii+0xfc> */
/* @0x204260 mov r4, r7 */
/* @0x204264 b 0x204298 <_ZN8CDS_Grid7Get_SumER6RValueiiii+0xd0> */
/* @0x204268 ldr r0, [r9] */
/* @0x20426c add r0, r0, r3, lsl #4 */
/* @0x204270 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x204274 ldm r8, {r2, r3} */
/* @0x204278 vmov d6, r2, r3 */
/* @0x20427c vmov d7, r0, r1 */
/* @0x204280 vadd.f64 d6, d6, d7 */
/* @0x204284 vmov r0, r1, d6 */
/* @0x204288 vmov r2, s12 */
/* @0x20428c mov r3, r1 */
/* @0x204290 stm r8, {r2, r3} */
/* @0x204294 ldr r12, [r9, #0x4] */
/* @0x204298 ldr r2, [r9, #0x8] */
/* @0x20429c mov r3, r10 */
/* @0x2042a0 mov r1, #0 */
/* @0x2042a4 cmp r10, r2 */
/* @0x2042a8 subge r3, r2, #1 */
/* @0x2042ac cmp r4, r3 */
/* @0x2042b0 mla r3, r12, r4, r5 */
/* @0x2042b4 add r4, r4, #1 */
/* @0x2042b8 ble 0x204268 <_ZN8CDS_Grid7Get_SumER6RValueiiii+0xa0> */
/* @0x2042bc add r5, r5, #1 */
/* @0x2042c0 b 0x20424c <_ZN8CDS_Grid7Get_SumER6RValueiiii+0x84> */
/* @0x2042c4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x2042c8 · CDS_Grid::Get_Mean(RValue&, int, int, int, int) · size=340 · insn=85 */
/* @0x2042c8 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2042cc sub sp, sp, #16 */
/* @0x2042d0 mov r5, #0 */
/* @0x2042d4 str r5, [r1] */
/* @0x2042d8 ldr r4, [sp, #0x30] */
/* @0x2042dc mov r7, #0 */
/* @0x2042e0 str r5, [r1, #0x4] */
/* @0x2042e4 cmp r2, r4 */
/* @0x2042e8 str r5, [r1, #0xc] */
/* @0x2042ec lsrlt r5, r2, #31 */
/* @0x2042f0 lsrge r5, r4, #31 */
/* @0x2042f4 ldr r12, [sp, #0x34] */
/* @0x2042f8 cmp r2, r4 */
/* @0x2042fc movlt r9, r2 */
/* @0x204300 movge r9, r4 */
/* @0x204304 cmp r5, #0 */
/* @0x204308 ldr r8, [r0, #0x4] */
/* @0x20430c movne r9, #0 */
/* @0x204310 cmp r3, r12 */
/* @0x204314 movlt r5, r3 */
/* @0x204318 movge r5, r12 */
/* @0x20431c cmp r3, r12 */
/* @0x204320 lsrlt r6, r3, #31 */
/* @0x204324 lsrge r6, r12, #31 */
/* @0x204328 cmp r6, #0 */
/* @0x20432c movne r5, #0 */
/* @0x204330 cmp r2, r4 */
/* @0x204334 movlt r2, r4 */
/* @0x204338 cmp r3, r12 */
/* @0x20433c movlt r3, r12 */
/* @0x204340 cmp r8, r2 */
/* @0x204344 mla r10, r5, r8, r9 */
/* @0x204348 suble r2, r8, #1 */
/* @0x20434c str r2, [sp, #0xc] */
/* @0x204350 lsl r8, r8, #4 */
/* @0x204354 str r3, [sp, #0x4] */
/* @0x204358 ldr r3, [sp, #0xc] */
/* @0x20435c str r5, [sp, #0x8] */
/* @0x204360 cmp r9, r3 */
/* @0x204364 lsl r11, r10, #4 */
/* @0x204368 bgt 0x2043ec <_ZN8CDS_Grid8Get_MeanER6RValueiiii+0x124> */
/* @0x20436c ldr r6, [r0, #0x8] */
/* @0x204370 mov r3, r11 */
/* @0x204374 ldr r4, [sp, #0x4] */
/* @0x204378 ldr r2, [sp, #0x8] */
/* @0x20437c cmp r6, r4 */
/* @0x204380 suble r4, r6, #1 */
/* @0x204384 mov r6, r4 */
/* @0x204388 b 0x2043cc <_ZN8CDS_Grid8Get_MeanER6RValueiiii+0x104> */
/* @0x20438c ldr r10, [r0] */
/* @0x204390 add r12, r10, r3 */
/* @0x204394 ldr r4, [r12, #0xc] */
/* @0x204398 cmp r4, #0 */
/* @0x20439c bne 0x2043c8 <_ZN8CDS_Grid8Get_MeanER6RValueiiii+0x100> */
/* @0x2043a0 ldr r5, [r12, #0x4] */
/* @0x2043a4 vldr s14, [r1] */
/* @0x2043a8 ldr r4, [r10, r3] */
/* @0x2043ac vldr s15, [r1, #4] */
/* @0x2043b0 add r7, r7, #1 */
/* @0x2043b4 vmov d6, r4, r5 */
/* @0x2043b8 vadd.f64 d6, d7, d6 */
/* @0x2043bc vmov r4, r5, d6 */
/* @0x2043c0 mov r12, r5 */
/* @0x2043c4 stm r1, {r4, r12} */
/* @0x2043c8 add r3, r3, r8 */
/* @0x2043cc cmp r2, r6 */
/* @0x2043d0 add r2, r2, #1 */
/* @0x2043d4 ble 0x20438c <_ZN8CDS_Grid8Get_MeanER6RValueiiii+0xc4> */
/* @0x2043d8 ldr r3, [sp, #0xc] */
/* @0x2043dc add r9, r9, #1 */
/* @0x2043e0 add r11, r11, #16 */
/* @0x2043e4 cmp r9, r3 */
/* @0x2043e8 ble 0x20436c <_ZN8CDS_Grid8Get_MeanER6RValueiiii+0xa4> */
/* @0x2043ec cmp r7, #0 */
/* @0x2043f0 beq 0x204410 <_ZN8CDS_Grid8Get_MeanER6RValueiiii+0x148> */
/* @0x2043f4 vmov s12, r7 */
/* @0x2043f8 ldm r1, {r2, r3} */
/* @0x2043fc vcvt.f64.s32 d7, s12 */
/* @0x204400 vmov d6, r2, r3 */
/* @0x204404 vdiv.f64 d6, d6, d7 */
/* @0x204408 vmov r2, r3, d6 */
/* @0x20440c stm r1, {r2, r3} */
/* @0x204410 add sp, sp, #16 */
/* @0x204414 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x204418 bx lr */

/* ── FUNC 0x20441c · CDS_Grid::Get_Disk_Sum(RValue&, double, double, double) · size=416 · insn=104 */
/* @0x20441c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x204420 vpush {d8, d9, d10} */
/* @0x204424 vmov d10, r2, r3 */
/* @0x204428 sub sp, sp, #12 */
/* @0x20442c vldr d9, [sp, #80] */
/* @0x204430 vsub.f64 d5, d10, d9 */
/* @0x204434 mov r5, r1 */
/* @0x204438 mov r8, #0 */
/* @0x20443c mov r7, r0 */
/* @0x204440 str r8, [r1, #0xc] */
/* @0x204444 str r8, [r1] */
/* @0x204448 str r8, [r5, #0x4] */
/* @0x20444c vmov r0, r1, d5 */
/* @0x204450 bl 0xb6598 <floor@plt> */
/* @0x204454 ldr r6, [r7, #0x4] */
/* @0x204458 vldr d8, [sp, #72] */
/* @0x20445c sub r4, r6, #1 */
/* @0x204460 vmov d7, r0, r1 */
/* @0x204464 vcmpe.f64 d7, #0 */
/* @0x204468 vmrs APSR_nzcv, fpscr */
/* @0x20446c vcvtpl.s32.f64 s11, d7 */
/* @0x204470 vadd.f64 d7, d10, d9 */
/* @0x204474 vmovpl r8, s11 */
/* @0x204478 vmov r0, r1, d7 */
/* @0x20447c bl 0xb670c <ceil@plt> */
/* @0x204480 vmov s10, r4 */
/* @0x204484 vcvt.f64.s32 d6, s10 */
/* @0x204488 vmov d7, r0, r1 */
/* @0x20448c vcmpe.f64 d6, d7 */
/* @0x204490 vmrs APSR_nzcv, fpscr */
/* @0x204494 vcvtpl.s32.f64 s11, d7 */
/* @0x204498 vsub.f64 d7, d8, d9 */
/* @0x20449c vmovpl r4, s11 */
/* @0x2044a0 vmov r0, r1, d7 */
/* @0x2044a4 bl 0xb6598 <floor@plt> */
/* @0x2044a8 ldr r10, [r7, #0x8] */
/* @0x2044ac sub r10, r10, #1 */
/* @0x2044b0 vmov d7, r0, r1 */
/* @0x2044b4 vcmpe.f64 d7, #0 */
/* @0x2044b8 vmrs APSR_nzcv, fpscr */
/* @0x2044bc vcvtpl.s32.f64 s10, d7 */
/* @0x2044c0 movmi r9, #0 */
/* @0x2044c4 vadd.f64 d7, d8, d9 */
/* @0x2044c8 vmovpl r9, s10 */
/* @0x2044cc vmov r0, r1, d7 */
/* @0x2044d0 bl 0xb670c <ceil@plt> */
/* @0x2044d4 vmov s10, r10 */
/* @0x2044d8 vcvt.f64.s32 d6, s10 */
/* @0x2044dc vmov d7, r0, r1 */
/* @0x2044e0 vcmpe.f64 d6, d7 */
/* @0x2044e4 vmrs APSR_nzcv, fpscr */
/* @0x2044e8 vcvtpl.s32.f64 s11, d7 */
/* @0x2044ec vmovpl r10, s11 */
/* @0x2044f0 cmp r8, r4 */
/* @0x2044f4 bgt 0x2045b0 <_ZN8CDS_Grid12Get_Disk_SumER6RValueddd+0x194> */
/* @0x2044f8 mla r11, r6, r9, r8 */
/* @0x2044fc add r4, r4, #1 */
/* @0x204500 lsl r6, r6, #4 */
/* @0x204504 add r1, r10, #1 */
/* @0x204508 lsl r11, r11, #4 */
/* @0x20450c cmp r9, r10 */
/* @0x204510 bgt 0x2045a0 <_ZN8CDS_Grid12Get_Disk_SumER6RValueddd+0x184> */
/* @0x204514 vmov s10, r8 */
/* @0x204518 mov r2, r11 */
/* @0x20451c vmul.f64 d4, d9, d9 */
/* @0x204520 mov r3, r9 */
/* @0x204524 str r4, [sp, #0x4] */
/* @0x204528 vcvt.f64.s32 d6, s10 */
/* @0x20452c vsub.f64 d6, d6, d10 */
/* @0x204530 vmul.f64 d6, d6, d6 */
/* @0x204534 vmov s10, r3 */
/* @0x204538 add r3, r3, #1 */
/* @0x20453c vcvt.f64.s32 d7, s10 */
/* @0x204540 vsub.f64 d7, d7, d8 */
/* @0x204544 vmov.f64 d5, d6 */
/* @0x204548 vmla.f64 d5, d7, d7 */
/* @0x20454c vcmpe.f64 d5, d4 */
/* @0x204550 vmrs APSR_nzcv, fpscr */
/* @0x204554 bhi 0x204590 <_ZN8CDS_Grid12Get_Disk_SumER6RValueddd+0x174> */
/* @0x204558 ldr r12, [r7] */
/* @0x20455c add r0, r12, r2 */
/* @0x204560 ldr r4, [r0, #0xc] */
/* @0x204564 cmp r4, #0 */
/* @0x204568 bne 0x204590 <_ZN8CDS_Grid12Get_Disk_SumER6RValueddd+0x174> */
/* @0x20456c ldr r12, [r12, r2] */
/* @0x204570 vldr s15, [r0, #4] */
/* @0x204574 vldr s10, [r5] */
/* @0x204578 vldr s11, [r5, #4] */
/* @0x20457c vmov s14, r12 */
/* @0x204580 vadd.f64 d7, d5, d7 */
/* @0x204584 vmov r0, s14 */
/* @0x204588 vmov r12, s15 */
/* @0x20458c stm r5, {r0, r12} */
/* @0x204590 cmp r3, r1 */
/* @0x204594 add r2, r2, r6 */
/* @0x204598 bne 0x204534 <_ZN8CDS_Grid12Get_Disk_SumER6RValueddd+0x118> */
/* @0x20459c ldr r4, [sp, #0x4] */
/* @0x2045a0 add r8, r8, #1 */
/* @0x2045a4 add r11, r11, #16 */
/* @0x2045a8 cmp r8, r4 */
/* @0x2045ac bne 0x20450c <_ZN8CDS_Grid12Get_Disk_SumER6RValueddd+0xf0> */
/* @0x2045b0 add sp, sp, #12 */
/* @0x2045b4 vpop {d8, d9, d10} */
/* @0x2045b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x2045bc · CDS_Grid::Get_Disk_Mean(RValue&, double, double, double) · size=464 · insn=116 */
/* @0x2045bc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2045c0 vpush {d8, d9, d10} */
/* @0x2045c4 vmov d10, r2, r3 */
/* @0x2045c8 sub sp, sp, #12 */
/* @0x2045cc vldr d9, [sp, #80] */
/* @0x2045d0 vsub.f64 d5, d10, d9 */
/* @0x2045d4 mov r5, r1 */
/* @0x2045d8 mov r9, #0 */
/* @0x2045dc mov r8, r0 */
/* @0x2045e0 str r9, [r1, #0xc] */
/* @0x2045e4 str r9, [r1] */
/* @0x2045e8 str r9, [r5, #0x4] */
/* @0x2045ec vmov r0, r1, d5 */
/* @0x2045f0 bl 0xb6598 <floor@plt> */
/* @0x2045f4 ldr r6, [r8, #0x4] */
/* @0x2045f8 vadd.f64 d6, d10, d9 */
/* @0x2045fc vldr d8, [sp, #72] */
/* @0x204600 sub r4, r6, #1 */
/* @0x204604 vmov d7, r0, r1 */
/* @0x204608 vcmpe.f64 d7, #0 */
/* @0x20460c vmov r0, r1, d6 */
/* @0x204610 vmrs APSR_nzcv, fpscr */
/* @0x204614 vcvtpl.s32.f64 s11, d7 */
/* @0x204618 vmovpl r9, s11 */
/* @0x20461c bl 0xb670c <ceil@plt> */
/* @0x204620 vmov s10, r4 */
/* @0x204624 vcvt.f64.s32 d6, s10 */
/* @0x204628 vmov d7, r0, r1 */
/* @0x20462c vcmpe.f64 d6, d7 */
/* @0x204630 vsub.f64 d6, d8, d9 */
/* @0x204634 vmrs APSR_nzcv, fpscr */
/* @0x204638 vcvtpl.s32.f64 s11, d7 */
/* @0x20463c vmov r0, r1, d6 */
/* @0x204640 vmovpl r4, s11 */
/* @0x204644 bl 0xb6598 <floor@plt> */
/* @0x204648 ldr r3, [r8, #0x8] */
/* @0x20464c sub r7, r3, #1 */
/* @0x204650 vmov d7, r0, r1 */
/* @0x204654 vcmpe.f64 d7, #0 */
/* @0x204658 vmrs APSR_nzcv, fpscr */
/* @0x20465c vcvtpl.s32.f64 s13, d7 */
/* @0x204660 movmi r10, #0 */
/* @0x204664 vadd.f64 d7, d8, d9 */
/* @0x204668 vmovpl r10, s13 */
/* @0x20466c vmov r0, r1, d7 */
/* @0x204670 bl 0xb670c <ceil@plt> */
/* @0x204674 vmov s10, r7 */
/* @0x204678 vcvt.f64.s32 d6, s10 */
/* @0x20467c vmov d7, r0, r1 */
/* @0x204680 vcmpe.f64 d6, d7 */
/* @0x204684 vmrs APSR_nzcv, fpscr */
/* @0x204688 vcvtpl.s32.f64 s11, d7 */
/* @0x20468c vmovpl r7, s11 */
/* @0x204690 cmp r9, r4 */
/* @0x204694 bgt 0x204780 <_ZN8CDS_Grid13Get_Disk_MeanER6RValueddd+0x1c4> */
/* @0x204698 mla r11, r6, r10, r9 */
/* @0x20469c add r1, r7, #1 */
/* @0x2046a0 lsl r6, r6, #4 */
/* @0x2046a4 mov r0, #0 */
/* @0x2046a8 add r4, r4, #1 */
/* @0x2046ac str r4, [sp, #0x4] */
/* @0x2046b0 lsl r11, r11, #4 */
/* @0x2046b4 cmp r10, r7 */
/* @0x2046b8 bgt 0x204748 <_ZN8CDS_Grid13Get_Disk_MeanER6RValueddd+0x18c> */
/* @0x2046bc vmov s10, r9 */
/* @0x2046c0 mov r2, r11 */
/* @0x2046c4 vmul.f64 d4, d9, d9 */
/* @0x2046c8 mov r3, r10 */
/* @0x2046cc str r7, [sp] */
/* @0x2046d0 vcvt.f64.s32 d6, s10 */
/* @0x2046d4 vsub.f64 d6, d6, d10 */
/* @0x2046d8 vmul.f64 d6, d6, d6 */
/* @0x2046dc vmov s10, r3 */
/* @0x2046e0 add r3, r3, #1 */
/* @0x2046e4 vcvt.f64.s32 d7, s10 */
/* @0x2046e8 vsub.f64 d7, d7, d8 */
/* @0x2046ec vmov.f64 d5, d6 */
/* @0x2046f0 vmla.f64 d5, d7, d7 */
/* @0x2046f4 vcmpe.f64 d4, d5 */
/* @0x2046f8 vmrs APSR_nzcv, fpscr */
/* @0x2046fc blt 0x204738 <_ZN8CDS_Grid13Get_Disk_MeanER6RValueddd+0x17c> */
/* @0x204700 ldr r4, [r8] */
/* @0x204704 add r12, r4, r2 */
/* @0x204708 ldr r7, [r12, #0xc] */
/* @0x20470c cmp r7, #0 */
/* @0x204710 bne 0x204738 <_ZN8CDS_Grid13Get_Disk_MeanER6RValueddd+0x17c> */
/* @0x204714 ldr r4, [r4, r2] */
/* @0x204718 vldr s15, [r12, #4] */
/* @0x20471c vldr s10, [r5] */
/* @0x204720 vldr s11, [r5, #4] */
/* @0x204724 add r0, r0, #1 */
/* @0x204728 vmov s14, r4 */
/* @0x20472c vadd.f64 d7, d5, d7 */
/* @0x204730 vstr s14, [r5] */
/* @0x204734 vstr s15, [r5, #4] */
/* @0x204738 cmp r3, r1 */
/* @0x20473c add r2, r2, r6 */
/* @0x204740 bne 0x2046dc <_ZN8CDS_Grid13Get_Disk_MeanER6RValueddd+0x120> */
/* @0x204744 ldr r7, [sp] */
/* @0x204748 ldr r3, [sp, #0x4] */
/* @0x20474c add r9, r9, #1 */
/* @0x204750 add r11, r11, #16 */
/* @0x204754 cmp r9, r3 */
/* @0x204758 bne 0x2046b4 <_ZN8CDS_Grid13Get_Disk_MeanER6RValueddd+0xf8> */
/* @0x20475c cmp r0, #0 */
/* @0x204760 beq 0x204780 <_ZN8CDS_Grid13Get_Disk_MeanER6RValueddd+0x1c4> */
/* @0x204764 vmov s11, r0 */
/* @0x204768 ldm r5, {r2, r3} */
/* @0x20476c vcvt.f64.s32 d7, s11 */
/* @0x204770 vmov d6, r2, r3 */
/* @0x204774 vdiv.f64 d6, d6, d7 */
/* @0x204778 vmov r2, r3, d6 */
/* @0x20477c stm r5, {r2, r3} */
/* @0x204780 add sp, sp, #12 */
/* @0x204784 vpop {d8, d9, d10} */
/* @0x204788 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x20478c · CDS_Grid::Value_Exists(RValue&, int, int, int, int, RValue*) · size=272 · insn=68 */
/* @0x20478c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x204790 mov r8, r1 */
/* @0x204794 ldr r12, [sp, #0x28] */
/* @0x204798 mov r5, r0 */
/* @0x20479c mov r0, #0 */
/* @0x2047a0 str r0, [r8] */
/* @0x2047a4 cmp r2, r12 */
/* @0x2047a8 str r0, [r8, #0x4] */
/* @0x2047ac str r0, [r8, #0xc] */
/* @0x2047b0 lsrlt r0, r2, #31 */
/* @0x2047b4 lsrge r0, r12, #31 */
/* @0x2047b8 ldr r1, [sp, #0x2c] */
/* @0x2047bc cmp r2, r12 */
/* @0x2047c0 movlt r6, r2 */
/* @0x2047c4 movge r6, r12 */
/* @0x2047c8 cmp r0, #0 */
/* @0x2047cc ldr r7, [sp, #0x30] */
/* @0x2047d0 movne r6, #0 */
/* @0x2047d4 cmp r3, r1 */
/* @0x2047d8 movlt r0, r3 */
/* @0x2047dc movge r0, r1 */
/* @0x2047e0 cmp r3, r1 */
/* @0x2047e4 lsrlt r10, r3, #31 */
/* @0x2047e8 lsrge r10, r1, #31 */
/* @0x2047ec cmp r2, r12 */
/* @0x2047f0 movge r9, r2 */
/* @0x2047f4 movlt r9, r12 */
/* @0x2047f8 cmp r10, #0 */
/* @0x2047fc ldr r2, [r5, #0x4] */
/* @0x204800 moveq r10, r0 */
/* @0x204804 movne r10, #0 */
/* @0x204808 cmp r3, r1 */
/* @0x20480c movge r11, r3 */
/* @0x204810 movlt r11, r1 */
/* @0x204814 cmp r9, r2 */
/* @0x204818 subge r3, r2, #1 */
/* @0x20481c movlt r3, r9 */
/* @0x204820 cmp r6, r3 */
/* @0x204824 bgt 0x204880 <_ZN8CDS_Grid12Value_ExistsER6RValueiiiiPS0_+0xf4> */
/* @0x204828 mov r4, r10 */
/* @0x20482c b 0x204850 <_ZN8CDS_Grid12Value_ExistsER6RValueiiiiPS0_+0xc4> */
/* @0x204830 ldr r12, [pc, r12] */
/* @0x204834 ldr lr, [r5] */
/* @0x204838 ldrd r2, r3, [r12] */
/* @0x20483c add r0, lr, r0, lsl #4 */
/* @0x204840 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x204844 cmp r0, #0 */
/* @0x204848 beq 0x204884 <_ZN8CDS_Grid12Value_ExistsER6RValueiiiiPS0_+0xf8> */
/* @0x20484c ldr r2, [r5, #0x4] */
/* @0x204850 ldr r1, [r5, #0x8] */
/* @0x204854 mov r3, r11 */
/* @0x204858 mla r0, r2, r4, r6 */
/* @0x20485c cmp r1, r11 */
/* @0x204860 suble r3, r1, #1 */
/* @0x204864 ldr r12, [pc, #0x2c] */
/* @0x204868 cmp r4, r3 */
/* @0x20486c mov r1, r7 */
/* @0x204870 add r4, r4, #1 */
/* @0x204874 ble 0x204830 <_ZN8CDS_Grid12Value_ExistsER6RValueiiiiPS0_+0xa4> */
/* @0x204878 add r6, r6, #1 */
/* @0x20487c b 0x204814 <_ZN8CDS_Grid12Value_ExistsER6RValueiiiiPS0_+0x88> */
/* @0x204880 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x204884 mov r3, #0 */
/* @0x204888 str r0, [r8] */
/* @0x20488c movt r3, #0x3ff0 */
/* @0x204890 str r3, [r8, #0x4] */
/* @0x204894 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x204898 andseq r12, lr, r4, asr r11 */

/* ── FUNC 0x20489c · CDS_Grid::Value_X(RValue&, int, int, int, int, RValue*) · size=280 · insn=70 */
/* @0x20489c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2048a0 mov r8, r1 */
/* @0x2048a4 ldr r12, [sp, #0x28] */
/* @0x2048a8 mov r5, r0 */
/* @0x2048ac mov r0, #0 */
/* @0x2048b0 ldr r7, [sp, #0x30] */
/* @0x2048b4 cmp r2, r12 */
/* @0x2048b8 mov r1, r0 */
/* @0x2048bc movt r0, #0xbff0 */
/* @0x2048c0 str r0, [r8, #0x4] */
/* @0x2048c4 lsrlt r0, r2, #31 */
/* @0x2048c8 lsrge r0, r12, #31 */
/* @0x2048cc str r1, [r8] */
/* @0x2048d0 cmp r2, r12 */
/* @0x2048d4 movlt r6, r2 */
/* @0x2048d8 movge r6, r12 */
/* @0x2048dc str r1, [r8, #0xc] */
/* @0x2048e0 cmp r0, #0 */
/* @0x2048e4 ldr r1, [sp, #0x2c] */
/* @0x2048e8 movne r6, #0 */
/* @0x2048ec cmp r3, r1 */
/* @0x2048f0 movlt r0, r3 */
/* @0x2048f4 movge r0, r1 */
/* @0x2048f8 cmp r3, r1 */
/* @0x2048fc lsrlt r10, r3, #31 */
/* @0x204900 lsrge r10, r1, #31 */
/* @0x204904 cmp r2, r12 */
/* @0x204908 movge r9, r2 */
/* @0x20490c movlt r9, r12 */
/* @0x204910 cmp r10, #0 */
/* @0x204914 ldr r2, [r5, #0x4] */
/* @0x204918 moveq r10, r0 */
/* @0x20491c movne r10, #0 */
/* @0x204920 cmp r3, r1 */
/* @0x204924 movge r11, r3 */
/* @0x204928 movlt r11, r1 */
/* @0x20492c cmp r9, r2 */
/* @0x204930 subge r3, r2, #1 */
/* @0x204934 movlt r3, r9 */
/* @0x204938 cmp r6, r3 */
/* @0x20493c bgt 0x204998 <_ZN8CDS_Grid7Value_XER6RValueiiiiPS0_+0xfc> */
/* @0x204940 mov r4, r10 */
/* @0x204944 b 0x204968 <_ZN8CDS_Grid7Value_XER6RValueiiiiPS0_+0xcc> */
/* @0x204948 ldr r12, [pc, r12] */
/* @0x20494c ldr lr, [r5] */
/* @0x204950 ldrd r2, r3, [r12] */
/* @0x204954 add r0, lr, r0, lsl #4 */
/* @0x204958 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x20495c cmp r0, #0 */
/* @0x204960 beq 0x20499c <_ZN8CDS_Grid7Value_XER6RValueiiiiPS0_+0x100> */
/* @0x204964 ldr r2, [r5, #0x4] */
/* @0x204968 ldr r1, [r5, #0x8] */
/* @0x20496c mov r3, r11 */
/* @0x204970 mla r0, r2, r4, r6 */
/* @0x204974 cmp r1, r11 */
/* @0x204978 suble r3, r1, #1 */
/* @0x20497c ldr r12, [pc, #0x2c] */
/* @0x204980 cmp r4, r3 */
/* @0x204984 mov r1, r7 */
/* @0x204988 add r4, r4, #1 */
/* @0x20498c ble 0x204948 <_ZN8CDS_Grid7Value_XER6RValueiiiiPS0_+0xac> */
/* @0x204990 add r6, r6, #1 */
/* @0x204994 b 0x20492c <_ZN8CDS_Grid7Value_XER6RValueiiiiPS0_+0x90> */
/* @0x204998 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20499c vmov s15, r6 */
/* @0x2049a0 vcvt.f64.s32 d7, s15 */
/* @0x2049a4 vmov r2, r3, d7 */
/* @0x2049a8 stm r8, {r2, r3} */
/* @0x2049ac pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2049b0 andseq r12, lr, r12, lsr r10 */

/* ── FUNC 0x2049b4 · CDS_Grid::Value_Y(RValue&, int, int, int, int, RValue*) · size=280 · insn=70 */
/* @0x2049b4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2049b8 mov r8, r1 */
/* @0x2049bc ldr r12, [sp, #0x28] */
/* @0x2049c0 mov r5, r0 */
/* @0x2049c4 mov r0, #0 */
/* @0x2049c8 ldr r7, [sp, #0x30] */
/* @0x2049cc cmp r2, r12 */
/* @0x2049d0 mov r1, r0 */
/* @0x2049d4 movt r0, #0xbff0 */
/* @0x2049d8 str r0, [r8, #0x4] */
/* @0x2049dc lsrlt r0, r2, #31 */
/* @0x2049e0 lsrge r0, r12, #31 */
/* @0x2049e4 str r1, [r8] */
/* @0x2049e8 cmp r2, r12 */
/* @0x2049ec movlt r6, r2 */
/* @0x2049f0 movge r6, r12 */
/* @0x2049f4 str r1, [r8, #0xc] */
/* @0x2049f8 cmp r0, #0 */
/* @0x2049fc ldr r1, [sp, #0x2c] */
/* @0x204a00 movne r6, #0 */
/* @0x204a04 cmp r3, r1 */
/* @0x204a08 movlt r0, r3 */
/* @0x204a0c movge r0, r1 */
/* @0x204a10 cmp r3, r1 */
/* @0x204a14 lsrlt r10, r3, #31 */
/* @0x204a18 lsrge r10, r1, #31 */
/* @0x204a1c cmp r2, r12 */
/* @0x204a20 movge r9, r2 */
/* @0x204a24 movlt r9, r12 */
/* @0x204a28 cmp r10, #0 */
/* @0x204a2c ldr r2, [r5, #0x4] */
/* @0x204a30 moveq r10, r0 */
/* @0x204a34 movne r10, #0 */
/* @0x204a38 cmp r3, r1 */
/* @0x204a3c movge r11, r3 */
/* @0x204a40 movlt r11, r1 */
/* @0x204a44 cmp r9, r2 */
/* @0x204a48 subge r3, r2, #1 */
/* @0x204a4c movlt r3, r9 */
/* @0x204a50 cmp r6, r3 */
/* @0x204a54 bgt 0x204ab0 <_ZN8CDS_Grid7Value_YER6RValueiiiiPS0_+0xfc> */
/* @0x204a58 mov r4, r10 */
/* @0x204a5c b 0x204a84 <_ZN8CDS_Grid7Value_YER6RValueiiiiPS0_+0xd0> */
/* @0x204a60 ldr r12, [pc, r12] */
/* @0x204a64 ldr lr, [r5] */
/* @0x204a68 ldrd r2, r3, [r12] */
/* @0x204a6c add r0, lr, r0, lsl #4 */
/* @0x204a70 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x204a74 cmp r0, #0 */
/* @0x204a78 beq 0x204ab4 <_ZN8CDS_Grid7Value_YER6RValueiiiiPS0_+0x100> */
/* @0x204a7c ldr r2, [r5, #0x4] */
/* @0x204a80 add r4, r4, #1 */
/* @0x204a84 ldr r1, [r5, #0x8] */
/* @0x204a88 mov r3, r11 */
/* @0x204a8c ldr r12, [pc, #0x34] */
/* @0x204a90 cmp r1, r11 */
/* @0x204a94 suble r3, r1, #1 */
/* @0x204a98 mov r1, r7 */
/* @0x204a9c cmp r4, r3 */
/* @0x204aa0 mla r0, r2, r4, r6 */
/* @0x204aa4 ble 0x204a60 <_ZN8CDS_Grid7Value_YER6RValueiiiiPS0_+0xac> */
/* @0x204aa8 add r6, r6, #1 */
/* @0x204aac b 0x204a44 <_ZN8CDS_Grid7Value_YER6RValueiiiiPS0_+0x90> */
/* @0x204ab0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x204ab4 vmov s15, r4 */
/* @0x204ab8 vcvt.f64.s32 d7, s15 */
/* @0x204abc vmov r2, r3, d7 */
/* @0x204ac0 stm r8, {r2, r3} */
/* @0x204ac4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x204ac8 andseq r12, lr, r4, lsr #18 */

/* ── FUNC 0x204acc · CDS_Grid::Value_Disk_Exists(RValue&, double, double, double, RValue*) · size=392 · insn=98 */
/* @0x204acc push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x204ad0 vpush {d8, d9, d10, d11, d12} */
/* @0x204ad4 vmov d12, r2, r3 */
/* @0x204ad8 vldr d11, [sp, #88] */
/* @0x204adc mov r10, r1 */
/* @0x204ae0 mov r6, #0 */
/* @0x204ae4 vsub.f64 d6, d12, d11 */
/* @0x204ae8 str r6, [r1, #0xc] */
/* @0x204aec str r6, [r1] */
/* @0x204af0 mov r11, r0 */
/* @0x204af4 str r6, [r10, #0x4] */
/* @0x204af8 vmov r0, r1, d6 */
/* @0x204afc bl 0xb6598 <floor@plt> */
/* @0x204b00 ldr r9, [r11, #0x4] */
/* @0x204b04 vldr d10, [sp, #80] */
/* @0x204b08 ldr r7, [sp, #0x60] */
/* @0x204b0c sub r9, r9, #1 */
/* @0x204b10 vmov d7, r0, r1 */
/* @0x204b14 vcmpe.f64 d7, #0 */
/* @0x204b18 vmrs APSR_nzcv, fpscr */
/* @0x204b1c vcvtpl.s32.f64 s13, d7 */
/* @0x204b20 vadd.f64 d7, d12, d11 */
/* @0x204b24 vmovpl r6, s13 */
/* @0x204b28 vmov r0, r1, d7 */
/* @0x204b2c bl 0xb670c <ceil@plt> */
/* @0x204b30 vmov s11, r9 */
/* @0x204b34 vcvt.f64.s32 d6, s11 */
/* @0x204b38 vmov d7, r0, r1 */
/* @0x204b3c vcmpe.f64 d6, d7 */
/* @0x204b40 vmrs APSR_nzcv, fpscr */
/* @0x204b44 vcvtpl.s32.f64 s12, d7 */
/* @0x204b48 vsub.f64 d7, d10, d11 */
/* @0x204b4c vmovpl r9, s12 */
/* @0x204b50 vmov r0, r1, d7 */
/* @0x204b54 bl 0xb6598 <floor@plt> */
/* @0x204b58 ldr r5, [r11, #0x8] */
/* @0x204b5c vadd.f64 d6, d10, d11 */
/* @0x204b60 sub r5, r5, #1 */
/* @0x204b64 vmov d7, r0, r1 */
/* @0x204b68 vcmpe.f64 d7, #0 */
/* @0x204b6c vmov r0, r1, d6 */
/* @0x204b70 vmrs APSR_nzcv, fpscr */
/* @0x204b74 vcvtpl.s32.f64 s11, d7 */
/* @0x204b78 movmi r8, #0 */
/* @0x204b7c vmovpl r8, s11 */
/* @0x204b80 bl 0xb670c <ceil@plt> */
/* @0x204b84 vmov s11, r5 */
/* @0x204b88 vcvt.f64.s32 d6, s11 */
/* @0x204b8c vmov d7, r0, r1 */
/* @0x204b90 vcmpe.f64 d6, d7 */
/* @0x204b94 vmrs APSR_nzcv, fpscr */
/* @0x204b98 vcvtpl.s32.f64 s12, d7 */
/* @0x204b9c vmovpl r5, s12 */
/* @0x204ba0 cmp r6, r9 */
/* @0x204ba4 bgt 0x204c34 <_ZN8CDS_Grid17Value_Disk_ExistsER6RValuedddPS0_+0x168> */
/* @0x204ba8 cmp r8, r5 */
/* @0x204bac bgt 0x204c3c <_ZN8CDS_Grid17Value_Disk_ExistsER6RValuedddPS0_+0x170> */
/* @0x204bb0 vmov s13, r6 */
/* @0x204bb4 mov r4, r8 */
/* @0x204bb8 vmul.f64 d9, d11, d11 */
/* @0x204bbc vcvt.f64.s32 d8, s13 */
/* @0x204bc0 vsub.f64 d8, d8, d12 */
/* @0x204bc4 vmul.f64 d8, d8, d8 */
/* @0x204bc8 b 0x204bd8 <_ZN8CDS_Grid17Value_Disk_ExistsER6RValuedddPS0_+0x10c> */
/* @0x204bcc add r4, r4, #1 */
/* @0x204bd0 cmp r5, r4 */
/* @0x204bd4 blt 0x204c3c <_ZN8CDS_Grid17Value_Disk_ExistsER6RValuedddPS0_+0x170> */
/* @0x204bd8 vmov s13, r4 */
/* @0x204bdc vcvt.f64.s32 d7, s13 */
/* @0x204be0 vsub.f64 d7, d7, d10 */
/* @0x204be4 vmov.f64 d6, d8 */
/* @0x204be8 vmla.f64 d6, d7, d7 */
/* @0x204bec vcmpe.f64 d6, d9 */
/* @0x204bf0 vmrs APSR_nzcv, fpscr */
/* @0x204bf4 bhi 0x204bcc <_ZN8CDS_Grid17Value_Disk_ExistsER6RValuedddPS0_+0x100> */
/* @0x204bf8 ldr r0, [r11, #0x4] */
/* @0x204bfc mov r1, r7 */
/* @0x204c00 ldr r3, [pc, #0x48] */
/* @0x204c04 ldr r12, [r11] */
/* @0x204c08 mla r0, r0, r4, r6 */
/* @0x204c0c ldr r3, [pc, r3] */
/* @0x204c10 ldrd r2, r3, [r3] */
/* @0x204c14 add r0, r12, r0, lsl #4 */
/* @0x204c18 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x204c1c cmp r0, #0 */
/* @0x204c20 bne 0x204bcc <_ZN8CDS_Grid17Value_Disk_ExistsER6RValuedddPS0_+0x100> */
/* @0x204c24 mov r3, #0 */
/* @0x204c28 str r0, [r10] */
/* @0x204c2c movt r3, #0x3ff0 */
/* @0x204c30 str r3, [r10, #0x4] */
/* @0x204c34 vpop {d8, d9, d10, d11, d12} */
/* @0x204c38 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x204c3c add r6, r6, #1 */
/* @0x204c40 cmp r9, r6 */
/* @0x204c44 bge 0x204ba8 <_ZN8CDS_Grid17Value_Disk_ExistsER6RValuedddPS0_+0xdc> */
/* @0x204c48 vpop {d8, d9, d10, d11, d12} */
/* @0x204c4c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x204c50 andseq r12, lr, r8, ror r7 */

/* ── FUNC 0x204c54 · CDS_Grid::Value_Disk_X(RValue&, double, double, double, RValue*) · size=396 · insn=99 */
/* @0x204c54 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x204c58 vpush {d8, d9, d10, d11, d12, d13} */
/* @0x204c5c vmov d12, r2, r3 */
/* @0x204c60 vldr d11, [sp, #96] */
/* @0x204c64 mov r10, r1 */
/* @0x204c68 mov r3, #0 */
/* @0x204c6c vsub.f64 d6, d12, d11 */
/* @0x204c70 mov r6, r3 */
/* @0x204c74 mov r11, r0 */
/* @0x204c78 movt r3, #0xbff0 */
/* @0x204c7c str r6, [r1, #0xc] */
/* @0x204c80 str r3, [r1, #0x4] */
/* @0x204c84 str r6, [r10] */
/* @0x204c88 vmov r0, r1, d6 */
/* @0x204c8c bl 0xb6598 <floor@plt> */
/* @0x204c90 ldr r9, [r11, #0x4] */
/* @0x204c94 vldr d10, [sp, #88] */
/* @0x204c98 ldr r7, [sp, #0x68] */
/* @0x204c9c sub r9, r9, #1 */
/* @0x204ca0 vmov d7, r0, r1 */
/* @0x204ca4 vcmpe.f64 d7, #0 */
/* @0x204ca8 vmrs APSR_nzcv, fpscr */
/* @0x204cac vcvtpl.s32.f64 s13, d7 */
/* @0x204cb0 vadd.f64 d7, d12, d11 */
/* @0x204cb4 vmovpl r6, s13 */
/* @0x204cb8 vmov r0, r1, d7 */
/* @0x204cbc bl 0xb670c <ceil@plt> */
/* @0x204cc0 vmov s11, r9 */
/* @0x204cc4 vcvt.f64.s32 d6, s11 */
/* @0x204cc8 vmov d7, r0, r1 */
/* @0x204ccc vcmpe.f64 d6, d7 */
/* @0x204cd0 vmrs APSR_nzcv, fpscr */
/* @0x204cd4 vcvtpl.s32.f64 s12, d7 */
/* @0x204cd8 vsub.f64 d7, d10, d11 */
/* @0x204cdc vmovpl r9, s12 */
/* @0x204ce0 vmov r0, r1, d7 */
/* @0x204ce4 bl 0xb6598 <floor@plt> */
/* @0x204ce8 ldr r5, [r11, #0x8] */
/* @0x204cec vadd.f64 d6, d10, d11 */
/* @0x204cf0 sub r5, r5, #1 */
/* @0x204cf4 vmov d7, r0, r1 */
/* @0x204cf8 vcmpe.f64 d7, #0 */
/* @0x204cfc vmov r0, r1, d6 */
/* @0x204d00 vmrs APSR_nzcv, fpscr */
/* @0x204d04 vcvtpl.s32.f64 s11, d7 */
/* @0x204d08 movmi r8, #0 */
/* @0x204d0c vmovpl r8, s11 */
/* @0x204d10 bl 0xb670c <ceil@plt> */
/* @0x204d14 vmov s11, r5 */
/* @0x204d18 vcvt.f64.s32 d6, s11 */
/* @0x204d1c vmov d7, r0, r1 */
/* @0x204d20 vcmpe.f64 d6, d7 */
/* @0x204d24 vmrs APSR_nzcv, fpscr */
/* @0x204d28 vcvtpl.s32.f64 s12, d7 */
/* @0x204d2c vmovpl r5, s12 */
/* @0x204d30 cmp r6, r9 */
/* @0x204d34 bgt 0x204dc0 <_ZN8CDS_Grid12Value_Disk_XER6RValuedddPS0_+0x16c> */
/* @0x204d38 cmp r8, r5 */
/* @0x204d3c bgt 0x204dc8 <_ZN8CDS_Grid12Value_Disk_XER6RValuedddPS0_+0x174> */
/* @0x204d40 vmov s13, r6 */
/* @0x204d44 mov r4, r8 */
/* @0x204d48 vmul.f64 d9, d11, d11 */
/* @0x204d4c vcvt.f64.s32 d13, s13 */
/* @0x204d50 vsub.f64 d8, d13, d12 */
/* @0x204d54 vmul.f64 d8, d8, d8 */
/* @0x204d58 b 0x204d68 <_ZN8CDS_Grid12Value_Disk_XER6RValuedddPS0_+0x114> */
/* @0x204d5c add r4, r4, #1 */
/* @0x204d60 cmp r5, r4 */
/* @0x204d64 blt 0x204dc8 <_ZN8CDS_Grid12Value_Disk_XER6RValuedddPS0_+0x174> */
/* @0x204d68 vmov s13, r4 */
/* @0x204d6c vcvt.f64.s32 d7, s13 */
/* @0x204d70 vsub.f64 d7, d7, d10 */
/* @0x204d74 vmov.f64 d6, d8 */
/* @0x204d78 vmla.f64 d6, d7, d7 */
/* @0x204d7c vcmpe.f64 d6, d9 */
/* @0x204d80 vmrs APSR_nzcv, fpscr */
/* @0x204d84 bhi 0x204d5c <_ZN8CDS_Grid12Value_Disk_XER6RValuedddPS0_+0x108> */
/* @0x204d88 ldr r0, [r11, #0x4] */
/* @0x204d8c mov r1, r7 */
/* @0x204d90 ldr r3, [pc, #0x44] */
/* @0x204d94 ldr r12, [r11] */
/* @0x204d98 mla r0, r0, r4, r6 */
/* @0x204d9c ldr r3, [pc, r3] */
/* @0x204da0 ldrd r2, r3, [r3] */
/* @0x204da4 add r0, r12, r0, lsl #4 */
/* @0x204da8 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x204dac cmp r0, #0 */
/* @0x204db0 bne 0x204d5c <_ZN8CDS_Grid12Value_Disk_XER6RValuedddPS0_+0x108> */
/* @0x204db4 vmov r2, s26 */
/* @0x204db8 vmov r3, s27 */
/* @0x204dbc stm r10, {r2, r3} */
/* @0x204dc0 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x204dc4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x204dc8 add r6, r6, #1 */
/* @0x204dcc cmp r9, r6 */
/* @0x204dd0 bge 0x204d38 <_ZN8CDS_Grid12Value_Disk_XER6RValuedddPS0_+0xe4> */
/* @0x204dd4 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x204dd8 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x204ddc andseq r12, lr, r8, ror #11 */

/* ── FUNC 0x204de0 · CDS_Grid::Value_Disk_Y(RValue&, double, double, double, RValue*) · size=396 · insn=99 */
/* @0x204de0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x204de4 vpush {d8, d9, d10, d11, d12, d13} */
/* @0x204de8 vmov d13, r2, r3 */
/* @0x204dec vldr d12, [sp, #96] */
/* @0x204df0 mov r10, r1 */
/* @0x204df4 mov r3, #0 */
/* @0x204df8 vsub.f64 d6, d13, d12 */
/* @0x204dfc mov r6, r3 */
/* @0x204e00 mov r11, r0 */
/* @0x204e04 movt r3, #0xbff0 */
/* @0x204e08 str r6, [r1, #0xc] */
/* @0x204e0c str r3, [r1, #0x4] */
/* @0x204e10 str r6, [r10] */
/* @0x204e14 vmov r0, r1, d6 */
/* @0x204e18 bl 0xb6598 <floor@plt> */
/* @0x204e1c ldr r9, [r11, #0x4] */
/* @0x204e20 vldr d11, [sp, #88] */
/* @0x204e24 ldr r7, [sp, #0x68] */
/* @0x204e28 sub r9, r9, #1 */
/* @0x204e2c vmov d7, r0, r1 */
/* @0x204e30 vcmpe.f64 d7, #0 */
/* @0x204e34 vmrs APSR_nzcv, fpscr */
/* @0x204e38 vcvtpl.s32.f64 s13, d7 */
/* @0x204e3c vadd.f64 d7, d13, d12 */
/* @0x204e40 vmovpl r6, s13 */
/* @0x204e44 vmov r0, r1, d7 */
/* @0x204e48 bl 0xb670c <ceil@plt> */
/* @0x204e4c vmov s11, r9 */
/* @0x204e50 vcvt.f64.s32 d6, s11 */
/* @0x204e54 vmov d7, r0, r1 */
/* @0x204e58 vcmpe.f64 d6, d7 */
/* @0x204e5c vmrs APSR_nzcv, fpscr */
/* @0x204e60 vcvtpl.s32.f64 s12, d7 */
/* @0x204e64 vsub.f64 d7, d11, d12 */
/* @0x204e68 vmovpl r9, s12 */
/* @0x204e6c vmov r0, r1, d7 */
/* @0x204e70 bl 0xb6598 <floor@plt> */
/* @0x204e74 ldr r5, [r11, #0x8] */
/* @0x204e78 vadd.f64 d6, d11, d12 */
/* @0x204e7c sub r5, r5, #1 */
/* @0x204e80 vmov d7, r0, r1 */
/* @0x204e84 vcmpe.f64 d7, #0 */
/* @0x204e88 vmov r0, r1, d6 */
/* @0x204e8c vmrs APSR_nzcv, fpscr */
/* @0x204e90 vcvtpl.s32.f64 s11, d7 */
/* @0x204e94 movmi r8, #0 */
/* @0x204e98 vmovpl r8, s11 */
/* @0x204e9c bl 0xb670c <ceil@plt> */
/* @0x204ea0 vmov s11, r5 */
/* @0x204ea4 vcvt.f64.s32 d6, s11 */
/* @0x204ea8 vmov d7, r0, r1 */
/* @0x204eac vcmpe.f64 d6, d7 */
/* @0x204eb0 vmrs APSR_nzcv, fpscr */
/* @0x204eb4 vcvtpl.s32.f64 s12, d7 */
/* @0x204eb8 vmovpl r5, s12 */
/* @0x204ebc cmp r6, r9 */
/* @0x204ec0 bgt 0x204f4c <_ZN8CDS_Grid12Value_Disk_YER6RValuedddPS0_+0x16c> */
/* @0x204ec4 cmp r8, r5 */
/* @0x204ec8 bgt 0x204f54 <_ZN8CDS_Grid12Value_Disk_YER6RValuedddPS0_+0x174> */
/* @0x204ecc vmov s13, r6 */
/* @0x204ed0 mov r4, r8 */
/* @0x204ed4 vmul.f64 d10, d12, d12 */
/* @0x204ed8 vcvt.f64.s32 d9, s13 */
/* @0x204edc vsub.f64 d9, d9, d13 */
/* @0x204ee0 vmul.f64 d9, d9, d9 */
/* @0x204ee4 b 0x204ef4 <_ZN8CDS_Grid12Value_Disk_YER6RValuedddPS0_+0x114> */
/* @0x204ee8 add r4, r4, #1 */
/* @0x204eec cmp r5, r4 */
/* @0x204ef0 blt 0x204f54 <_ZN8CDS_Grid12Value_Disk_YER6RValuedddPS0_+0x174> */
/* @0x204ef4 vmov s13, r4 */
/* @0x204ef8 vcvt.f64.s32 d8, s13 */
/* @0x204efc vsub.f64 d7, d8, d11 */
/* @0x204f00 vmov.f64 d6, d9 */
/* @0x204f04 vmla.f64 d6, d7, d7 */
/* @0x204f08 vcmpe.f64 d6, d10 */
/* @0x204f0c vmrs APSR_nzcv, fpscr */
/* @0x204f10 bhi 0x204ee8 <_ZN8CDS_Grid12Value_Disk_YER6RValuedddPS0_+0x108> */
/* @0x204f14 ldr r0, [r11, #0x4] */
/* @0x204f18 mov r1, r7 */
/* @0x204f1c ldr r3, [pc, #0x44] */
/* @0x204f20 ldr r12, [r11] */
/* @0x204f24 mla r0, r0, r4, r6 */
/* @0x204f28 ldr r3, [pc, r3] */
/* @0x204f2c ldrd r2, r3, [r3] */
/* @0x204f30 add r0, r12, r0, lsl #4 */
/* @0x204f34 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x204f38 cmp r0, #0 */
/* @0x204f3c bne 0x204ee8 <_ZN8CDS_Grid12Value_Disk_YER6RValuedddPS0_+0x108> */
/* @0x204f40 vmov r2, s16 */
/* @0x204f44 vmov r3, s17 */
/* @0x204f48 stm r10, {r2, r3} */
/* @0x204f4c vpop {d8, d9, d10, d11, d12, d13} */
/* @0x204f50 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x204f54 add r6, r6, #1 */
/* @0x204f58 cmp r9, r6 */
/* @0x204f5c bge 0x204ec4 <_ZN8CDS_Grid12Value_Disk_YER6RValuedddPS0_+0xe4> */
/* @0x204f60 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x204f64 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x204f68 andseq r12, lr, r12, asr r4 */

/* ── FUNC 0x204f6c · CDS_Grid::Sort(int, int) · size=516 · insn=129 */
/* @0x204f6c ldr r12, [pc, #0x1e0] */
/* @0x204f70 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x204f74 add r11, sp, #32 */
/* @0x204f78 ldr r3, [pc, #0x1d8] */
/* @0x204f7c sub sp, sp, #12 */
/* @0x204f80 add r12, pc, r12 */
/* @0x204f84 mov r4, r0 */
/* @0x204f88 ldr r5, [r12, r3] */
/* @0x204f8c ldr r0, [r0, #0x4] */
/* @0x204f90 ldr r3, [r5] */
/* @0x204f94 cmp r0, r1 */
/* @0x204f98 str r3, [r11, #-0x28] */
/* @0x204f9c bgt 0x204fb8 <_ZN8CDS_Grid4SortEii+0x4c> */
/* @0x204fa0 ldr r2, [r11, #-0x28] */
/* @0x204fa4 ldr r3, [r5] */
/* @0x204fa8 cmp r2, r3 */
/* @0x204fac bne 0x205150 <_ZN8CDS_Grid4SortEii+0x1e4> */
/* @0x204fb0 sub sp, r11, #32 */
/* @0x204fb4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x204fb8 ldr r0, [pc, #0x19c] */
/* @0x204fbc ldr r6, [pc, #0x19c] */
/* @0x204fc0 ldr r3, [r4, #0x8] */
/* @0x204fc4 ldr r7, [r12, r0] */
/* @0x204fc8 ldr r0, [pc, #0x194] */
/* @0x204fcc cmp r3, #0 */
/* @0x204fd0 lsl lr, r3, #2 */
/* @0x204fd4 str r1, [r7] */
/* @0x204fd8 add lr, lr, #14 */
/* @0x204fdc ldr r1, [r12, r6] */
/* @0x204fe0 bic lr, lr, #7 */
/* @0x204fe4 sub sp, sp, lr */
/* @0x204fe8 str r2, [r1] */
/* @0x204fec mov r6, sp */
/* @0x204ff0 ldr r2, [r12, r0] */
/* @0x204ff4 str r4, [r2] */
/* @0x204ff8 ble 0x20501c <_ZN8CDS_Grid4SortEii+0xb0> */
/* @0x204ffc sub r2, sp, #4 */
/* @0x205000 mov r3, #0 */
/* @0x205004 ldr r1, [r4, #0x8] */
/* @0x205008 str r3, [r2, #0x4]! */
/* @0x20500c add r3, r3, #1 */
/* @0x205010 cmp r1, r3 */
/* @0x205014 bgt 0x205004 <_ZN8CDS_Grid4SortEii+0x98> */
/* @0x205018 mov r3, r1 */
/* @0x20501c ldr lr, [pc, #0x144] */
/* @0x205020 mov r1, r3 */
/* @0x205024 mov r0, r6 */
/* @0x205028 mov r2, #4 */
/* @0x20502c ldr r3, [r12, lr] */
/* @0x205030 bl 0xb66dc <qsort@plt> */
/* @0x205034 ldmib r4, {r0, r12} */
/* @0x205038 ldr r1, [pc, #0x12c] */
/* @0x20503c movw r2, #0x102c */
/* @0x205040 mov r3, #1 */
/* @0x205044 mul r0, r12, r0 */
/* @0x205048 add r1, pc, r1 */
/* @0x20504c lsl r0, r0, #4 */
/* @0x205050 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x205054 ldr r2, [r4, #0x8] */
/* @0x205058 cmp r2, #0 */
/* @0x20505c movgt r7, #0 */
/* @0x205060 ldrgt r3, [r4, #0x4] */
/* @0x205064 ble 0x205148 <_ZN8CDS_Grid4SortEii+0x1dc> */
/* @0x205068 cmp r3, #0 */
/* @0x20506c ble 0x2050bc <_ZN8CDS_Grid4SortEii+0x150> */
/* @0x205070 mov r1, #0 */
/* @0x205074 mla r3, r3, r7, r1 */
/* @0x205078 ldr r2, [r4] */
/* @0x20507c add r1, r1, #1 */
/* @0x205080 lsl r12, r3, #4 */
/* @0x205084 add r2, r2, r12 */
/* @0x205088 add r12, r0, r12 */
/* @0x20508c ldr r9, [r2] */
/* @0x205090 ldr r8, [r2, #0x4] */
/* @0x205094 ldr lr, [r2, #0x8] */
/* @0x205098 ldr r2, [r2, #0xc] */
/* @0x20509c str r9, [r0, r3, lsl #4] */
/* @0x2050a0 str r8, [r12, #0x4] */
/* @0x2050a4 str lr, [r12, #0x8] */
/* @0x2050a8 str r2, [r12, #0xc] */
/* @0x2050ac ldr r3, [r4, #0x4] */
/* @0x2050b0 cmp r3, r1 */
/* @0x2050b4 bgt 0x205074 <_ZN8CDS_Grid4SortEii+0x108> */
/* @0x2050b8 ldr r2, [r4, #0x8] */
/* @0x2050bc add r7, r7, #1 */
/* @0x2050c0 cmp r2, r7 */
/* @0x2050c4 bgt 0x205068 <_ZN8CDS_Grid4SortEii+0xfc> */
/* @0x2050c8 cmp r2, #0 */
/* @0x2050cc ble 0x205148 <_ZN8CDS_Grid4SortEii+0x1dc> */
/* @0x2050d0 mov r8, #0 */
/* @0x2050d4 ldr r1, [r6], #4 */
/* @0x2050d8 cmp r1, r8 */
/* @0x2050dc beq 0x20513c <_ZN8CDS_Grid4SortEii+0x1d0> */
/* @0x2050e0 cmp r3, #0 */
/* @0x2050e4 ble 0x20513c <_ZN8CDS_Grid4SortEii+0x1d0> */
/* @0x2050e8 mov r2, #0 */
/* @0x2050ec b 0x2050f4 <_ZN8CDS_Grid4SortEii+0x188> */
/* @0x2050f0 ldr r1, [r6, #-0x4] */
/* @0x2050f4 mla r1, r1, r3, r2 */
/* @0x2050f8 ldr lr, [r4] */
/* @0x2050fc mla r3, r3, r8, r2 */
/* @0x205100 add r2, r2, #1 */
/* @0x205104 add r1, r0, r1, lsl #4 */
/* @0x205108 ldr r10, [r1] */
/* @0x20510c add r12, lr, r3, lsl #4 */
/* @0x205110 ldr r9, [r1, #0x4] */
/* @0x205114 ldr r7, [r1, #0x8] */
/* @0x205118 ldr r1, [r1, #0xc] */
/* @0x20511c str r10, [lr, r3, lsl #4] */
/* @0x205120 str r9, [r12, #0x4] */
/* @0x205124 str r7, [r12, #0x8] */
/* @0x205128 str r1, [r12, #0xc] */
/* @0x20512c ldr r3, [r4, #0x4] */
/* @0x205130 cmp r3, r2 */
/* @0x205134 bgt 0x2050f0 <_ZN8CDS_Grid4SortEii+0x184> */
/* @0x205138 ldr r2, [r4, #0x8] */
/* @0x20513c add r8, r8, #1 */
/* @0x205140 cmp r2, r8 */
/* @0x205144 bgt 0x2050d4 <_ZN8CDS_Grid4SortEii+0x168> */
/* @0x205148 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x20514c b 0x204fa0 <_ZN8CDS_Grid4SortEii+0x34> */
/* @0x205150 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x205154 ldrsbeq r12, [lr], -r0 */
/* @0x205158 .word 0xffffbd00 */
/* @0x20515c .word 0xfffff73c */
/* @0x205160 .word 0xfffff740 */
/* @0x205164 .word 0xfffff738 */
/* @0x205168 .word 0xfffff748 */
/* @0x20516c andseq lr, r4, r4, lsr #15 */

/* ── FUNC 0x205170 · CDS_Grid::Mark4GC(unsigned int*, int) · size=108 · insn=27 */
/* @0x205170 push {r4, r5, r6, r7, r8, lr} */
/* @0x205174 mov r7, r1 */
/* @0x205178 ldr r1, [r0, #0x8] */
/* @0x20517c mov r5, r0 */
/* @0x205180 mov r8, r2 */
/* @0x205184 cmp r1, #0 */
/* @0x205188 pople {r4, r5, r6, r7, r8, pc} */
/* @0x20518c ldr r3, [r0, #0x4] */
/* @0x205190 mov r6, #0 */
/* @0x205194 cmp r3, #0 */
/* @0x205198 ble 0x2051cc <_ZN8CDS_Grid7Mark4GCEPji+0x5c> */
/* @0x20519c mov r4, #0 */
/* @0x2051a0 mla r3, r3, r6, r4 */
/* @0x2051a4 ldr r0, [r5] */
/* @0x2051a8 mov r1, r7 */
/* @0x2051ac mov r2, r8 */
/* @0x2051b0 add r4, r4, #1 */
/* @0x2051b4 add r0, r0, r3, lsl #4 */
/* @0x2051b8 bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji> */
/* @0x2051bc ldr r3, [r5, #0x4] */
/* @0x2051c0 cmp r3, r4 */
/* @0x2051c4 bgt 0x2051a0 <_ZN8CDS_Grid7Mark4GCEPji+0x30> */
/* @0x2051c8 ldr r1, [r5, #0x8] */
/* @0x2051cc add r6, r6, #1 */
/* @0x2051d0 cmp r1, r6 */
/* @0x2051d4 bgt 0x205194 <_ZN8CDS_Grid7Mark4GCEPji+0x24> */
/* @0x2051d8 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2051dc · CDS_Grid::Add4GC(CGCGeneration*) · size=100 · insn=25 */
/* @0x2051dc ldr r2, [r0, #0x8] */
/* @0x2051e0 push {r3, r4, r5, r6, r7, lr} */
/* @0x2051e4 cmp r2, #0 */
/* @0x2051e8 mov r5, r0 */
/* @0x2051ec mov r7, r1 */
/* @0x2051f0 pople {r3, r4, r5, r6, r7, pc} */
/* @0x2051f4 ldr r3, [r0, #0x4] */
/* @0x2051f8 mov r6, #0 */
/* @0x2051fc cmp r3, #0 */
/* @0x205200 ble 0x205230 <_ZN8CDS_Grid6Add4GCEP13CGCGeneration+0x54> */
/* @0x205204 mov r4, #0 */
/* @0x205208 mla r3, r3, r6, r4 */
/* @0x20520c ldr r0, [r5] */
/* @0x205210 mov r1, r7 */
/* @0x205214 add r4, r4, #1 */
/* @0x205218 add r0, r0, r3, lsl #4 */
/* @0x20521c bl 0x191bac <_Z17RVALUE_GC_ADDROOTPK6RValueP13CGCGeneration> */
/* @0x205220 ldr r3, [r5, #0x4] */
/* @0x205224 cmp r3, r4 */
/* @0x205228 bgt 0x205208 <_ZN8CDS_Grid6Add4GCEP13CGCGeneration+0x2c> */
/* @0x20522c ldr r2, [r5, #0x8] */
/* @0x205230 add r6, r6, #1 */
/* @0x205234 cmp r2, r6 */
/* @0x205238 bgt 0x2051fc <_ZN8CDS_Grid6Add4GCEP13CGCGeneration+0x20> */
/* @0x20523c pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x205240 · CDS_Grid::MarkOnlyChildren4GC(unsigned int*, int) · size=108 · insn=27 */
/* @0x205240 push {r4, r5, r6, r7, r8, lr} */
/* @0x205244 mov r7, r1 */
/* @0x205248 ldr r1, [r0, #0x8] */
/* @0x20524c mov r5, r0 */
/* @0x205250 mov r8, r2 */
/* @0x205254 cmp r1, #0 */
/* @0x205258 pople {r4, r5, r6, r7, r8, pc} */
/* @0x20525c ldr r3, [r0, #0x4] */
/* @0x205260 mov r6, #0 */
/* @0x205264 cmp r3, #0 */
/* @0x205268 ble 0x20529c <_ZN8CDS_Grid19MarkOnlyChildren4GCEPji+0x5c> */
/* @0x20526c mov r4, #0 */
/* @0x205270 mla r3, r3, r6, r4 */
/* @0x205274 ldr r0, [r5] */
/* @0x205278 mov r1, r7 */
/* @0x20527c mov r2, r8 */
/* @0x205280 add r4, r4, #1 */
/* @0x205284 add r0, r0, r3, lsl #4 */
/* @0x205288 bl 0x191f5c <_Z18RVALUE_GC_THISONLYPK6RValuePji> */
/* @0x20528c ldr r3, [r5, #0x4] */
/* @0x205290 cmp r3, r4 */
/* @0x205294 bgt 0x205270 <_ZN8CDS_Grid19MarkOnlyChildren4GCEPji+0x30> */
/* @0x205298 ldr r1, [r5, #0x8] */
/* @0x20529c add r6, r6, #1 */
/* @0x2052a0 cmp r1, r6 */
/* @0x2052a4 bgt 0x205264 <_ZN8CDS_Grid19MarkOnlyChildren4GCEPji+0x24> */
/* @0x2052a8 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2052ac · CDS_Stack::Size() · size=8 · insn=2 */
/* @0x2052ac ldr r0, [r0, #0x4] */
/* @0x2052b0 bx lr */

/* ── FUNC 0x2052b4 · CDS_Queue::Size() · size=4 · insn=1 */
/* @0x2052b4 b 0x202e20 <_ZN9CDS_Queue7GetSizeEv> */

/* ── FUNC 0x2052b8 · CDS_List::Size() · size=8 · insn=2 */
/* @0x2052b8 ldr r0, [r0, #0x4] */
/* @0x2052bc bx lr */

/* ── FUNC 0x2052c0 · CDS_Map::Size() · size=12 · insn=3 */
/* @0x2052c0 ldr r3, [r0] */
/* @0x2052c4 ldr r0, [r3, #0x8] */
/* @0x2052c8 bx lr */

/* ── FUNC 0x2052cc · CDS_Priority::Size() · size=8 · insn=2 */
/* @0x2052cc ldr r0, [r0, #0x4] */
/* @0x2052d0 bx lr */

/* ── FUNC 0x2052d4 · GetDsMap(int) · size=96 · insn=24 */
/* @0x2052d4 push {r4, r5, r6, lr} */
/* @0x2052d8 subs r5, r0, #0 */
/* @0x2052dc sub sp, sp, #8 */
/* @0x2052e0 blt 0x205320 <_Z8GetDsMapi+0x4c> */
/* @0x2052e4 ldr r4, [pc, #0x44] */
/* @0x2052e8 ldr r4, [pc, r4] */
/* @0x2052ec ldr r3, [r4] */
/* @0x2052f0 cmp r5, r3 */
/* @0x2052f4 bge 0x205320 <_Z8GetDsMapi+0x4c> */
/* @0x2052f8 add r6, sp, #4 */
/* @0x2052fc mov r0, r6 */
/* @0x205300 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x205304 ldr r3, [r4, #0x4] */
/* @0x205308 mov r0, r6 */
/* @0x20530c ldr r4, [r3, r5, lsl #2] */
/* @0x205310 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x205314 mov r0, r4 */
/* @0x205318 add sp, sp, #8 */
/* @0x20531c pop {r4, r5, r6, pc} */
/* @0x205320 mov r4, #0 */
/* @0x205324 mov r0, r4 */
/* @0x205328 add sp, sp, #8 */
/* @0x20532c pop {r4, r5, r6, pc} */
/* @0x205330 andseq r8, lr, r4, asr r6 */

/* ── FUNC 0x205334 · DestroyDsMap(int) · size=68 · insn=17 */
/* @0x205334 vmov s13, r0 */
/* @0x205338 mov r12, #0 */
/* @0x20533c str lr, [sp, #-0x4]! */
/* @0x205340 vcvt.f64.s32 d7, s13 */
/* @0x205344 sub sp, sp, #44 */
/* @0x205348 mov r1, r12 */
/* @0x20534c add r3, sp, #24 */
/* @0x205350 mov r2, r12 */
/* @0x205354 str r3, [sp] */
/* @0x205358 add r0, sp, #8 */
/* @0x20535c mov r3, #1 */
/* @0x205360 str r12, [sp, #0x8] */
/* @0x205364 str r12, [sp, #0x24] */
/* @0x205368 vstr d7, [sp, #24] */
/* @0x20536c bl 0xfec90 <_Z14F_DsMapDestroyR6RValueP9CInstanceS2_iPS_> */
/* @0x205370 add sp, sp, #44 */
/* @0x205374 ldr pc, [sp], #4 */
