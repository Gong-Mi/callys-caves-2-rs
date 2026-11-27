/* libyoyo.so 覆盖卡组 0183
 * 函数 0x202e20..0x203b94，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x202e20 · CDS_Queue::GetSize() · size=16 · insn=4 */
/* @0x202e20 ldr r2, [r0, #0x4] */
/* @0x202e24 ldr r0, [r0, #0x8] */
/* @0x202e28 rsb r0, r0, r2 */
/* @0x202e2c bx lr */

/* ── FUNC 0x202e30 · CDS_Queue::WriteToString(char const*&) · size=168 · insn=42 */
/* @0x202e30 push {r3, r4, r5, r6, r7, lr} */
/* @0x202e34 mov r5, r0 */
/* @0x202e38 mov r0, #32 */
/* @0x202e3c mov r7, r1 */
/* @0x202e40 bl 0x27c524 <_Znwj> */
/* @0x202e44 mov r1, #0 */
/* @0x202e48 mov r6, r0 */
/* @0x202e4c bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x202e50 mov r0, r6 */
/* @0x202e54 mov r1, #202 */
/* @0x202e58 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x202e5c mov r0, r6 */
/* @0x202e60 ldr r1, [r5, #0x4] */
/* @0x202e64 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x202e68 mov r0, r6 */
/* @0x202e6c ldr r1, [r5, #0x8] */
/* @0x202e70 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x202e74 mov r0, r6 */
/* @0x202e78 ldr r1, [r5, #0xc] */
/* @0x202e7c bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x202e80 ldr r3, [r5, #0xc] */
/* @0x202e84 cmp r3, #0 */
/* @0x202e88 movgt r4, #0 */
/* @0x202e8c ble 0x202eb0 <_ZN9CDS_Queue13WriteToStringERPKc+0x80> */
/* @0x202e90 ldr r1, [r5, #0x10] */
/* @0x202e94 mov r0, r6 */
/* @0x202e98 add r1, r1, r4, lsl #4 */
/* @0x202e9c add r4, r4, #1 */
/* @0x202ea0 bl 0x202af8 <_Z10WriteValueR7CStreamR6RValue> */
/* @0x202ea4 ldr r3, [r5, #0xc] */
/* @0x202ea8 cmp r3, r4 */
/* @0x202eac bgt 0x202e90 <_ZN9CDS_Queue13WriteToStringERPKc+0x60> */
/* @0x202eb0 mov r1, r7 */
/* @0x202eb4 mov r0, r6 */
/* @0x202eb8 bl 0x2024b0 <_ZN7CStream15ConvertToStringERPKc> */
/* @0x202ebc cmp r6, #0 */
/* @0x202ec0 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x202ec4 mov r0, r6 */
/* @0x202ec8 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x202ecc mov r0, r6 */
/* @0x202ed0 pop {r3, r4, r5, r6, r7, lr} */
/* @0x202ed4 b 0x27d1d0 <_ZdlPv> */

/* ── FUNC 0x202ed8 · CDS_Queue::Mark4GC(unsigned int*, int) · size=72 · insn=18 */
/* @0x202ed8 push {r3, r4, r5, r6, r7, lr} */
/* @0x202edc mov r5, r0 */
/* @0x202ee0 ldr r3, [r0, #0xc] */
/* @0x202ee4 mov r6, r1 */
/* @0x202ee8 mov r7, r2 */
/* @0x202eec cmp r3, #0 */
/* @0x202ef0 pople {r3, r4, r5, r6, r7, pc} */
/* @0x202ef4 mov r4, #0 */
/* @0x202ef8 ldr r0, [r5, #0x10] */
/* @0x202efc mov r1, r6 */
/* @0x202f00 mov r2, r7 */
/* @0x202f04 add r0, r0, r4, lsl #4 */
/* @0x202f08 add r4, r4, #1 */
/* @0x202f0c bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji> */
/* @0x202f10 ldr r3, [r5, #0xc] */
/* @0x202f14 cmp r3, r4 */
/* @0x202f18 bgt 0x202ef8 <_ZN9CDS_Queue7Mark4GCEPji+0x20> */
/* @0x202f1c pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x202f20 · CDS_Queue::Add4GC(CGCGeneration*) · size=64 · insn=16 */
/* @0x202f20 ldr r3, [r0, #0xc] */
/* @0x202f24 push {r4, r5, r6, lr} */
/* @0x202f28 cmp r3, #0 */
/* @0x202f2c mov r5, r0 */
/* @0x202f30 mov r6, r1 */
/* @0x202f34 pople {r4, r5, r6, pc} */
/* @0x202f38 mov r4, #0 */
/* @0x202f3c ldr r0, [r5, #0x10] */
/* @0x202f40 mov r1, r6 */
/* @0x202f44 add r0, r0, r4, lsl #4 */
/* @0x202f48 add r4, r4, #1 */
/* @0x202f4c bl 0x191bac <_Z17RVALUE_GC_ADDROOTPK6RValueP13CGCGeneration> */
/* @0x202f50 ldr r3, [r5, #0xc] */
/* @0x202f54 cmp r3, r4 */
/* @0x202f58 bgt 0x202f3c <_ZN9CDS_Queue6Add4GCEP13CGCGeneration+0x1c> */
/* @0x202f5c pop {r4, r5, r6, pc} */

/* ── FUNC 0x202f60 · CDS_Queue::MarkOnlyChildren4GC(unsigned int*, int) · size=72 · insn=18 */
/* @0x202f60 push {r3, r4, r5, r6, r7, lr} */
/* @0x202f64 mov r5, r0 */
/* @0x202f68 ldr r3, [r0, #0xc] */
/* @0x202f6c mov r6, r1 */
/* @0x202f70 mov r7, r2 */
/* @0x202f74 cmp r3, #0 */
/* @0x202f78 pople {r3, r4, r5, r6, r7, pc} */
/* @0x202f7c mov r4, #0 */
/* @0x202f80 ldr r0, [r5, #0x10] */
/* @0x202f84 mov r1, r6 */
/* @0x202f88 mov r2, r7 */
/* @0x202f8c add r0, r0, r4, lsl #4 */
/* @0x202f90 add r4, r4, #1 */
/* @0x202f94 bl 0x191f5c <_Z18RVALUE_GC_THISONLYPK6RValuePji> */
/* @0x202f98 ldr r3, [r5, #0xc] */
/* @0x202f9c cmp r3, r4 */
/* @0x202fa0 bgt 0x202f80 <_ZN9CDS_Queue19MarkOnlyChildren4GCEPji+0x20> */
/* @0x202fa4 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x202fa8 · CDS_Queue::Head() · size=24 · insn=6 */
/* @0x202fa8 ldmib r0, {r2, r3} */
/* @0x202fac cmp r3, r2 */
/* @0x202fb0 ldrne r0, [r0, #0x10] */
/* @0x202fb4 addne r0, r0, r3, lsl #4 */
/* @0x202fb8 moveq r0, #0 */
/* @0x202fbc bx lr */

/* ── FUNC 0x202fc0 · CDS_Queue::Tail() · size=32 · insn=8 */
/* @0x202fc0 ldr r3, [r0, #0x4] */
/* @0x202fc4 ldr r2, [r0, #0x8] */
/* @0x202fc8 cmp r2, r3 */
/* @0x202fcc subne r3, r3, #-268435455 */
/* @0x202fd0 ldrne r2, [r0, #0x10] */
/* @0x202fd4 addne r0, r2, r3, lsl #4 */
/* @0x202fd8 moveq r0, #0 */
/* @0x202fdc bx lr */

/* ── FUNC 0x202fe0 · CDS_Queue::Empty() · size=24 · insn=6 */
/* @0x202fe0 ldr r2, [r0, #0x4] */
/* @0x202fe4 ldr r0, [r0, #0x8] */
/* @0x202fe8 subs r3, r2, r0 */
/* @0x202fec rsbs r0, r3, #0 */
/* @0x202ff0 adcs r0, r0, r3 */
/* @0x202ff4 bx lr */

/* ── FUNC 0x202ff8 · CDS_List::CDS_List() · size=36 · insn=9 */
/* @0x202ff8 ldr r1, [pc, #0x18] */
/* @0x202ffc mov r2, #0 */
/* @0x203000 str r2, [r0, #0x8] */
/* @0x203004 ldr r1, [pc, r1] */
/* @0x203008 str r2, [r0, #0xc] */
/* @0x20300c add r1, r1, #8 */
/* @0x203010 stm r0, {r1, r2} */
/* @0x203014 bx lr */
/* @0x203018 mulseq lr, r0, r3 */

/* ── FUNC 0x202ff8 · CDS_List::CDS_List() · alias of the symbol above · insn=0 */

/* ── FUNC 0x20301c · CDS_List::WriteToString(char const*&) · size=144 · insn=36 */
/* @0x20301c push {r3, r4, r5, r6, r7, lr} */
/* @0x203020 mov r5, r0 */
/* @0x203024 mov r0, #32 */
/* @0x203028 mov r7, r1 */
/* @0x20302c bl 0x27c524 <_Znwj> */
/* @0x203030 mov r1, #0 */
/* @0x203034 mov r6, r0 */
/* @0x203038 bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x20303c mov r0, r6 */
/* @0x203040 movw r1, #0x12e */
/* @0x203044 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x203048 mov r0, r6 */
/* @0x20304c ldr r1, [r5, #0x4] */
/* @0x203050 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x203054 ldr r3, [r5, #0x4] */
/* @0x203058 cmp r3, #0 */
/* @0x20305c movgt r4, #0 */
/* @0x203060 ble 0x203084 <_ZN8CDS_List13WriteToStringERPKc+0x68> */
/* @0x203064 ldr r1, [r5, #0xc] */
/* @0x203068 mov r0, r6 */
/* @0x20306c add r1, r1, r4, lsl #4 */
/* @0x203070 add r4, r4, #1 */
/* @0x203074 bl 0x202af8 <_Z10WriteValueR7CStreamR6RValue> */
/* @0x203078 ldr r3, [r5, #0x4] */
/* @0x20307c cmp r3, r4 */
/* @0x203080 bgt 0x203064 <_ZN8CDS_List13WriteToStringERPKc+0x48> */
/* @0x203084 mov r1, r7 */
/* @0x203088 mov r0, r6 */
/* @0x20308c bl 0x2024b0 <_ZN7CStream15ConvertToStringERPKc> */
/* @0x203090 cmp r6, #0 */
/* @0x203094 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x203098 mov r0, r6 */
/* @0x20309c bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x2030a0 mov r0, r6 */
/* @0x2030a4 pop {r3, r4, r5, r6, r7, lr} */
/* @0x2030a8 b 0x27d1d0 <_ZdlPv> */

/* ── FUNC 0x2030ac · CDS_List::Mark4GC(unsigned int*, int) · size=72 · insn=18 */
/* @0x2030ac push {r3, r4, r5, r6, r7, lr} */
/* @0x2030b0 mov r5, r0 */
/* @0x2030b4 ldr r3, [r0, #0x4] */
/* @0x2030b8 mov r6, r1 */
/* @0x2030bc mov r7, r2 */
/* @0x2030c0 cmp r3, #0 */
/* @0x2030c4 pople {r3, r4, r5, r6, r7, pc} */
/* @0x2030c8 mov r4, #0 */
/* @0x2030cc ldr r0, [r5, #0xc] */
/* @0x2030d0 mov r1, r6 */
/* @0x2030d4 mov r2, r7 */
/* @0x2030d8 add r0, r0, r4, lsl #4 */
/* @0x2030dc add r4, r4, #1 */
/* @0x2030e0 bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji> */
/* @0x2030e4 ldr r3, [r5, #0x4] */
/* @0x2030e8 cmp r3, r4 */
/* @0x2030ec bgt 0x2030cc <_ZN8CDS_List7Mark4GCEPji+0x20> */
/* @0x2030f0 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2030f4 · CDS_List::Add4GC(CGCGeneration*) · size=64 · insn=16 */
/* @0x2030f4 ldr r3, [r0, #0x4] */
/* @0x2030f8 push {r4, r5, r6, lr} */
/* @0x2030fc cmp r3, #0 */
/* @0x203100 mov r5, r0 */
/* @0x203104 mov r6, r1 */
/* @0x203108 pople {r4, r5, r6, pc} */
/* @0x20310c mov r4, #0 */
/* @0x203110 ldr r0, [r5, #0xc] */
/* @0x203114 mov r1, r6 */
/* @0x203118 add r0, r0, r4, lsl #4 */
/* @0x20311c add r4, r4, #1 */
/* @0x203120 bl 0x191bac <_Z17RVALUE_GC_ADDROOTPK6RValueP13CGCGeneration> */
/* @0x203124 ldr r3, [r5, #0x4] */
/* @0x203128 cmp r3, r4 */
/* @0x20312c bgt 0x203110 <_ZN8CDS_List6Add4GCEP13CGCGeneration+0x1c> */
/* @0x203130 pop {r4, r5, r6, pc} */

/* ── FUNC 0x203134 · CDS_List::MarkOnlyChildren4GC(unsigned int*, int) · size=72 · insn=18 */
/* @0x203134 push {r3, r4, r5, r6, r7, lr} */
/* @0x203138 mov r5, r0 */
/* @0x20313c ldr r3, [r0, #0x4] */
/* @0x203140 mov r6, r1 */
/* @0x203144 mov r7, r2 */
/* @0x203148 cmp r3, #0 */
/* @0x20314c pople {r3, r4, r5, r6, r7, pc} */
/* @0x203150 mov r4, #0 */
/* @0x203154 ldr r0, [r5, #0xc] */
/* @0x203158 mov r1, r6 */
/* @0x20315c mov r2, r7 */
/* @0x203160 add r0, r0, r4, lsl #4 */
/* @0x203164 add r4, r4, #1 */
/* @0x203168 bl 0x191f5c <_Z18RVALUE_GC_THISONLYPK6RValuePji> */
/* @0x20316c ldr r3, [r5, #0x4] */
/* @0x203170 cmp r3, r4 */
/* @0x203174 bgt 0x203154 <_ZN8CDS_List19MarkOnlyChildren4GCEPji+0x20> */
/* @0x203178 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x20317c · CDS_List::Empty() · size=16 · insn=4 */
/* @0x20317c ldr r0, [r0, #0x4] */
/* @0x203180 rsbs r0, r0, #1 */
/* @0x203184 movlo r0, #0 */
/* @0x203188 bx lr */

/* ── FUNC 0x20318c · CDS_List::Find(RValue*) · size=104 · insn=26 */
/* @0x20318c push {r3, r4, r5, r6, r7, lr} */
/* @0x203190 mov r5, r0 */
/* @0x203194 ldr r3, [r0, #0x4] */
/* @0x203198 mov r7, r1 */
/* @0x20319c cmp r3, #0 */
/* @0x2031a0 ble 0x2031e8 <_ZN8CDS_List4FindEP6RValue+0x5c> */
/* @0x2031a4 ldr r6, [pc, #0x44] */
/* @0x2031a8 mov r4, #0 */
/* @0x2031ac ldr r6, [pc, r6] */
/* @0x2031b0 b 0x2031c4 <_ZN8CDS_List4FindEP6RValue+0x38> */
/* @0x2031b4 ldr r3, [r5, #0x4] */
/* @0x2031b8 add r4, r4, #1 */
/* @0x2031bc cmp r3, r4 */
/* @0x2031c0 ble 0x2031e8 <_ZN8CDS_List4FindEP6RValue+0x5c> */
/* @0x2031c4 ldr r0, [r5, #0xc] */
/* @0x2031c8 mov r1, r7 */
/* @0x2031cc ldrd r2, r3, [r6] */
/* @0x2031d0 add r0, r0, r4, lsl #4 */
/* @0x2031d4 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x2031d8 cmp r0, #0 */
/* @0x2031dc bne 0x2031b4 <_ZN8CDS_List4FindEP6RValue+0x28> */
/* @0x2031e0 mov r0, r4 */
/* @0x2031e4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2031e8 mvn r0, #0 */
/* @0x2031ec pop {r3, r4, r5, r6, r7, pc} */
/* @0x2031f0 ldrsbeq lr, [lr], -r8 */

/* ── FUNC 0x2031f4 · CDS_List::GetValue(int) · size=40 · insn=10 */
/* @0x2031f4 cmp r1, #0 */
/* @0x2031f8 blt 0x203214 <_ZN8CDS_List8GetValueEi+0x20> */
/* @0x2031fc ldr r3, [r0, #0x4] */
/* @0x203200 cmp r1, r3 */
/* @0x203204 bge 0x203214 <_ZN8CDS_List8GetValueEi+0x20> */
/* @0x203208 ldr r0, [r0, #0xc] */
/* @0x20320c add r0, r0, r1, lsl #4 */
/* @0x203210 bx lr */
/* @0x203214 mov r0, #0 */
/* @0x203218 bx lr */

/* ── FUNC 0x20321c · CDS_List::Sort(bool) · size=324 · insn=81 */
/* @0x20321c ldr r2, [r0, #0x4] */
/* @0x203220 mov r3, #0 */
/* @0x203224 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x203228 cmp r2, #1 */
/* @0x20322c sub sp, sp, #44 */
/* @0x203230 mov r11, r0 */
/* @0x203234 str r1, [sp, #0x10] */
/* @0x203238 str r3, [sp, #0x18] */
/* @0x20323c str r3, [sp, #0x1c] */
/* @0x203240 str r3, [sp, #0x20] */
/* @0x203244 str r3, [sp, #0x24] */
/* @0x203248 ble 0x20334c <_ZN8CDS_List4SortEb+0x130> */
/* @0x20324c mov r8, #1 */
/* @0x203250 str r8, [sp, #0x14] */
/* @0x203254 add r8, sp, #24 */
/* @0x203258 ldr r4, [pc, #0xfc] */
/* @0x20325c mov r7, r8 */
/* @0x203260 ldr r4, [pc, r4] */
/* @0x203264 str r4, [sp, #0xc] */
/* @0x203268 ldr r4, [sp, #0x14] */
/* @0x20326c mov r9, r7 */
/* @0x203270 lsl r10, r4, #4 */
/* @0x203274 str r4, [sp] */
/* @0x203278 b 0x2032f8 <_ZN8CDS_List4SortEb+0xdc> */
/* @0x20327c ldr r8, [sp] */
/* @0x203280 subs r8, r8, #1 */
/* @0x203284 str r8, [sp] */
/* @0x203288 ldr r8, [r11, #0xc] */
/* @0x20328c add r6, r8, r10 */
/* @0x203290 add r12, r8, r5 */
/* @0x203294 ldr r8, [r6] */
/* @0x203298 ldr r1, [r12, #0x4] */
/* @0x20329c ldr r2, [r12, #0x8] */
/* @0x2032a0 ldr r3, [r12, #0xc] */
/* @0x2032a4 ldr r0, [r12] */
/* @0x2032a8 str r8, [sp, #0x4] */
/* @0x2032ac ldr r8, [r6, #0x4] */
/* @0x2032b0 stm r7!, {r0, r1, r2, r3} */
/* @0x2032b4 ldr r7, [r6, #0x8] */
/* @0x2032b8 ldr r2, [r11, #0xc] */
/* @0x2032bc ldr r6, [r6, #0xc] */
/* @0x2032c0 ldr r0, [sp, #0x4] */
/* @0x2032c4 str r0, [r2, r5] */
/* @0x2032c8 ldm r4!, {r0, r1, r2, r3} */
/* @0x2032cc str r8, [r12, #0x4] */
/* @0x2032d0 str r7, [r12, #0x8] */
/* @0x2032d4 str r6, [r12, #0xc] */
/* @0x2032d8 ldr r4, [r11, #0xc] */
/* @0x2032dc add r12, r4, r10 */
/* @0x2032e0 str r0, [r4, r10] */
/* @0x2032e4 mov r10, r5 */
/* @0x2032e8 str r1, [r12, #0x4] */
/* @0x2032ec str r2, [r12, #0x8] */
/* @0x2032f0 str r3, [r12, #0xc] */
/* @0x2032f4 beq 0x203354 <_ZN8CDS_List4SortEb+0x138> */
/* @0x2032f8 ldr r4, [sp, #0xc] */
/* @0x2032fc sub r5, r10, #16 */
/* @0x203300 ldr r1, [r11, #0xc] */
/* @0x203304 mov r7, r9 */
/* @0x203308 ldrd r2, r3, [r4] */
/* @0x20330c add r0, r1, r5 */
/* @0x203310 add r1, r1, r10 */
/* @0x203314 mov r4, r9 */
/* @0x203318 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x20331c ldr r8, [sp, #0x10] */
/* @0x203320 cmp r0, #0 */
/* @0x203324 movle r0, #0 */
/* @0x203328 movgt r0, #1 */
/* @0x20332c cmp r0, r8 */
/* @0x203330 beq 0x20327c <_ZN8CDS_List4SortEb+0x60> */
/* @0x203334 ldr r4, [sp, #0x14] */
/* @0x203338 ldr r3, [r11, #0x4] */
/* @0x20333c add r4, r4, #1 */
/* @0x203340 str r4, [sp, #0x14] */
/* @0x203344 cmp r3, r4 */
/* @0x203348 bgt 0x203268 <_ZN8CDS_List4SortEb+0x4c> */
/* @0x20334c add sp, sp, #44 */
/* @0x203350 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x203354 mov r7, r9 */
/* @0x203358 b 0x203334 <_ZN8CDS_List4SortEb+0x118> */
/* @0x20335c andseq lr, lr, r4, lsr #2 */

/* ── FUNC 0x203360 · CDS_List::Shuffle() · size=388 · insn=97 */
/* @0x203360 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x203364 mov r11, r0 */
/* @0x203368 ldr r0, [r0, #0x4] */
/* @0x20336c mov r3, #0 */
/* @0x203370 sub sp, sp, #52 */
/* @0x203374 cmp r0, r3 */
/* @0x203378 str r3, [sp, #0x20] */
/* @0x20337c str r3, [sp, #0x24] */
/* @0x203380 str r3, [sp, #0x28] */
/* @0x203384 str r3, [sp, #0x2c] */
/* @0x203388 ble 0x2034cc <_ZN8CDS_List7ShuffleEv+0x16c> */
/* @0x20338c ldr r4, [pc, #0x140] */
/* @0x203390 add r10, sp, #32 */
/* @0x203394 ldr r5, [pc, #0x13c] */
/* @0x203398 mov r8, #1 */
/* @0x20339c add r4, pc, r4 */
/* @0x2033a0 str r10, [sp, #0x4] */
/* @0x2033a4 add r5, pc, r5 */
/* @0x2033a8 str r4, [sp, #0x18] */
/* @0x2033ac str r5, [sp, #0x1c] */
/* @0x2033b0 b 0x203468 <_ZN8CDS_List7ShuffleEv+0x108> */
/* @0x2033b4 cmp r7, #0 */
/* @0x2033b8 blt 0x203498 <_ZN8CDS_List7ShuffleEv+0x138> */
/* @0x2033bc cmp r6, r3 */
/* @0x2033c0 ldr r0, [pc, #0x114] */
/* @0x2033c4 ldr r1, [sp, #0x1c] */
/* @0x2033c8 mov r2, r6 */
/* @0x2033cc bge 0x2034b4 <_ZN8CDS_List7ShuffleEv+0x154> */
/* @0x2033d0 cmp r6, #0 */
/* @0x2033d4 blt 0x2034b4 <_ZN8CDS_List7ShuffleEv+0x154> */
/* @0x2033d8 ldr r9, [r11, #0xc] */
/* @0x2033dc lsl r10, r6, #4 */
/* @0x2033e0 ldr r5, [sp, #0x4] */
/* @0x2033e4 add r4, r9, r10 */
/* @0x2033e8 add r12, r9, r7, lsl #4 */
/* @0x2033ec ldr r9, [r4] */
/* @0x2033f0 ldr r1, [r12, #0x4] */
/* @0x2033f4 ldr r2, [r12, #0x8] */
/* @0x2033f8 str r9, [sp, #0x8] */
/* @0x2033fc ldr r9, [r4, #0x4] */
/* @0x203400 ldr r3, [r12, #0xc] */
/* @0x203404 ldr r0, [r12] */
/* @0x203408 str r9, [sp, #0xc] */
/* @0x20340c ldr r9, [r4, #0x8] */
/* @0x203410 str r9, [sp, #0x10] */
/* @0x203414 ldr r9, [r4, #0xc] */
/* @0x203418 mov r4, r5 */
/* @0x20341c stm r5!, {r0, r1, r2, r3} */
/* @0x203420 ldr r5, [r11, #0xc] */
/* @0x203424 ldm r4!, {r0, r1, r2, r3} */
/* @0x203428 ldr r4, [sp, #0x8] */
/* @0x20342c str r4, [r5, r7, lsl #4] */
/* @0x203430 ldr r4, [sp, #0xc] */
/* @0x203434 ldr r5, [sp, #0x10] */
/* @0x203438 str r9, [r12, #0xc] */
/* @0x20343c str r4, [r12, #0x4] */
/* @0x203440 str r5, [r12, #0x8] */
/* @0x203444 ldr r4, [r11, #0xc] */
/* @0x203448 add r12, r4, r10 */
/* @0x20344c str r0, [r4, r6, lsl #4] */
/* @0x203450 str r1, [r12, #0x4] */
/* @0x203454 str r2, [r12, #0x8] */
/* @0x203458 str r3, [r12, #0xc] */
/* @0x20345c ldr r0, [r11, #0x4] */
/* @0x203460 cmp r8, r0, lsl #3 */
/* @0x203464 bgt 0x2034cc <_ZN8CDS_List7ShuffleEv+0x16c> */
/* @0x203468 bl 0xc4600 <_Z8YYRandomi> */
/* @0x20346c add r8, r8, #1 */
/* @0x203470 mov r7, r0 */
/* @0x203474 ldr r0, [r11, #0x4] */
/* @0x203478 bl 0xc4600 <_Z8YYRandomi> */
/* @0x20347c ldr r3, [r11, #0x4] */
/* @0x203480 ldr r1, [sp, #0x18] */
/* @0x203484 mov r2, r7 */
/* @0x203488 cmp r7, r3 */
/* @0x20348c mov r6, r0 */
/* @0x203490 ldr r0, [pc, #0x48] */
/* @0x203494 blt 0x2033b4 <_ZN8CDS_List7ShuffleEv+0x54> */
/* @0x203498 ldr r0, [pc, r0] */
/* @0x20349c ldr r0, [r0] */
/* @0x2034a0 ldr r3, [r0] */
/* @0x2034a4 ldr r3, [r3, #0xc] */
/* @0x2034a8 blx r3 */
/* @0x2034ac ldr r3, [r11, #0x4] */
/* @0x2034b0 b 0x2033bc <_ZN8CDS_List7ShuffleEv+0x5c> */
/* @0x2034b4 ldr r0, [pc, r0] */
/* @0x2034b8 ldr r0, [r0] */
/* @0x2034bc ldr r3, [r0] */
/* @0x2034c0 ldr r3, [r3, #0xc] */
/* @0x2034c4 blx r3 */
/* @0x2034c8 b 0x2033d8 <_ZN8CDS_List7ShuffleEv+0x78> */
/* @0x2034cc add sp, sp, #52 */
/* @0x2034d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2034d4 andseq r0, r5, r0, asr #8 */
/* @0x2034d8 andseq r0, r5, r0, asr #8 */
/* @0x2034dc andseq r10, lr, r0, ror #4 */
/* @0x2034e0 andseq r10, lr, r12, ror r2 */

/* ── FUNC 0x2034e4 · CDS_Map::Find(RValue*) · size=320 · insn=80 */
/* @0x2034e4 ldr r3, [r1, #0xc] */
/* @0x2034e8 push {r4, r5, r6, lr} */
/* @0x2034ec bic r3, r3, #-16777216 */
/* @0x2034f0 cmp r3, #6 */
/* @0x2034f4 sub sp, sp, #8 */
/* @0x2034f8 mov r6, r1 */
/* @0x2034fc mov r4, r0 */
/* @0x203500 beq 0x203600 <_ZN7CDS_Map4FindEP6RValue+0x11c> */
/* @0x203504 bgt 0x203538 <_ZN7CDS_Map4FindEP6RValue+0x54> */
/* @0x203508 cmp r3, #4 */
/* @0x20350c bgt 0x203550 <_ZN7CDS_Map4FindEP6RValue+0x6c> */
/* @0x203510 cmp r3, #2 */
/* @0x203514 bge 0x203600 <_ZN7CDS_Map4FindEP6RValue+0x11c> */
/* @0x203518 cmp r3, #1 */
/* @0x20351c bne 0x2035d0 <_ZN7CDS_Map4FindEP6RValue+0xec> */
/* @0x203520 ldr r0, [r1] */
/* @0x203524 cmp r0, #0 */
/* @0x203528 ldrne r0, [r0] */
/* @0x20352c bl 0x27dfa8 <_Z14CalcCRC_stringPKc> */
/* @0x203530 mov r5, r0 */
/* @0x203534 b 0x203554 <_ZN7CDS_Map4FindEP6RValue+0x70> */
/* @0x203538 cmp r3, #11 */
/* @0x20353c beq 0x203600 <_ZN7CDS_Map4FindEP6RValue+0x11c> */
/* @0x203540 ble 0x2035c4 <_ZN7CDS_Map4FindEP6RValue+0xe0> */
/* @0x203544 mvn r2, #-16777216 */
/* @0x203548 cmp r3, r2 */
/* @0x20354c bne 0x2035d0 <_ZN7CDS_Map4FindEP6RValue+0xec> */
/* @0x203550 mov r5, #0 */
/* @0x203554 ldr r3, [r4] */
/* @0x203558 ldr r2, [r3, #0x4] */
/* @0x20355c ldr r3, [r3] */
/* @0x203560 and r2, r5, r2 */
/* @0x203564 ldr r4, [r3, r2, lsl #3] */
/* @0x203568 cmp r4, #0 */
/* @0x20356c bne 0x203580 <_ZN7CDS_Map4FindEP6RValue+0x9c> */
/* @0x203570 b 0x2035b8 <_ZN7CDS_Map4FindEP6RValue+0xd4> */
/* @0x203574 ldr r4, [r4, #0x4] */
/* @0x203578 cmp r4, #0 */
/* @0x20357c beq 0x2035b8 <_ZN7CDS_Map4FindEP6RValue+0xd4> */
/* @0x203580 ldr r3, [r4, #0x8] */
/* @0x203584 cmp r3, r5 */
/* @0x203588 bne 0x203574 <_ZN7CDS_Map4FindEP6RValue+0x90> */
/* @0x20358c ldr r3, [pc, #0x8c] */
/* @0x203590 mov r1, r6 */
/* @0x203594 ldr r0, [r4, #0xc] */
/* @0x203598 ldr r3, [pc, r3] */
/* @0x20359c ldrd r2, r3, [r3] */
/* @0x2035a0 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x2035a4 cmp r0, #0 */
/* @0x2035a8 bne 0x203574 <_ZN7CDS_Map4FindEP6RValue+0x90> */
/* @0x2035ac ldr r0, [r4, #0xc] */
/* @0x2035b0 add sp, sp, #8 */
/* @0x2035b4 pop {r4, r5, r6, pc} */
/* @0x2035b8 mov r0, #0 */
/* @0x2035bc add sp, sp, #8 */
/* @0x2035c0 pop {r4, r5, r6, pc} */
/* @0x2035c4 sub r2, r3, #8 */
/* @0x2035c8 cmp r2, #1 */
/* @0x2035cc bls 0x203600 <_ZN7CDS_Map4FindEP6RValue+0x11c> */
/* @0x2035d0 cmp r3, #0 */
/* @0x2035d4 bne 0x203614 <_ZN7CDS_Map4FindEP6RValue+0x130> */
/* @0x2035d8 ldm r6, {r0, r1} */
/* @0x2035dc mov r2, r0 */
/* @0x2035e0 add r0, sp, #8 */
/* @0x2035e4 mov r3, r1 */
/* @0x2035e8 mov r1, #8 */
/* @0x2035ec strd r2, r3, [r0, #-8]! */
/* @0x2035f0 mov r0, sp */
/* @0x2035f4 bl 0x27dfa0 <_Z7CalcCRCPKci> */
/* @0x2035f8 mov r5, r0 */
/* @0x2035fc b 0x203554 <_ZN7CDS_Map4FindEP6RValue+0x70> */
/* @0x203600 mov r0, r6 */
/* @0x203604 mov r1, #8 */
/* @0x203608 bl 0x27dfa0 <_Z7CalcCRCPKci> */
/* @0x20360c mov r5, r0 */
/* @0x203610 b 0x203554 <_ZN7CDS_Map4FindEP6RValue+0x70> */
/* @0x203614 mov r0, r6 */
/* @0x203618 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x20361c b 0x2035dc <_ZN7CDS_Map4FindEP6RValue+0xf8> */
/* @0x203620 andseq sp, lr, r12, ror #27 */

/* ── FUNC 0x203624 · CDS_Map::CDS_Map() · size=92 · insn=23 */
/* @0x203624 push {r4, r5, r6, lr} */
/* @0x203628 mov r5, r0 */
/* @0x20362c mov r0, #12 */
/* @0x203630 mov r6, #0 */
/* @0x203634 bl 0x27c524 <_Znwj> */
/* @0x203638 ldr r1, [pc, #0x3c] */
/* @0x20363c mov r3, #255 */
/* @0x203640 mov r2, #187 */
/* @0x203644 add r1, pc, r1 */
/* @0x203648 mov r4, r0 */
/* @0x20364c str r3, [r0, #0x4] */
/* @0x203650 mov r3, #1 */
/* @0x203654 str r6, [r4, #0x8] */
/* @0x203658 mov r0, #2048 */
/* @0x20365c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x203660 mov r1, r6 */
/* @0x203664 mov r2, #2048 */
/* @0x203668 str r0, [r4] */
/* @0x20366c bl 0xb65b0 <memset@plt> */
/* @0x203670 str r4, [r5] */
/* @0x203674 mov r0, r5 */
/* @0x203678 pop {r4, r5, r6, pc} */
/* @0x20367c andseq r9, r4, r8, ror #12 */

/* ── FUNC 0x203624 · CDS_Map::CDS_Map() · alias of the symbol above · insn=0 */

/* ── FUNC 0x203680 · CDS_Map::CDS_Map(int) · size=100 · insn=25 */
/* @0x203680 push {r3, r4, r5, r6, r7, lr} */
/* @0x203684 mov r6, r0 */
/* @0x203688 mov r0, #12 */
/* @0x20368c lsl r5, r1, #3 */
/* @0x203690 mov r7, r1 */
/* @0x203694 bl 0x27c524 <_Znwj> */
/* @0x203698 ldr r1, [pc, #0x40] */
/* @0x20369c mov r3, #1 */
/* @0x2036a0 sub r7, r7, #1 */
/* @0x2036a4 mov r2, #187 */
/* @0x2036a8 add r1, pc, r1 */
/* @0x2036ac mov r4, r0 */
/* @0x2036b0 mov r0, r5 */
/* @0x2036b4 str r7, [r4, #0x4] */
/* @0x2036b8 mov r7, #0 */
/* @0x2036bc str r7, [r4, #0x8] */
/* @0x2036c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2036c4 mov r2, r5 */
/* @0x2036c8 mov r1, r7 */
/* @0x2036cc str r0, [r4] */
/* @0x2036d0 bl 0xb65b0 <memset@plt> */
/* @0x2036d4 str r4, [r6] */
/* @0x2036d8 mov r0, r6 */
/* @0x2036dc pop {r3, r4, r5, r6, r7, pc} */
/* @0x2036e0 andseq r9, r4, r4, lsl #12 */

/* ── FUNC 0x203680 · CDS_Map::CDS_Map(int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2036e4 · CDS_Map::Mark4GC(unsigned int*, int) · size=208 · insn=52 */
/* @0x2036e4 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2036e8 mov r8, r2 */
/* @0x2036ec ldr r9, [r0] */
/* @0x2036f0 mov r7, r1 */
/* @0x2036f4 mov r5, #0 */
/* @0x2036f8 ldr r2, [r9] */
/* @0x2036fc b 0x203710 <_ZN7CDS_Map7Mark4GCEPji+0x2c> */
/* @0x203700 ldr r3, [r9, #0x4] */
/* @0x203704 add r5, r5, #1 */
/* @0x203708 cmp r5, r3 */
/* @0x20370c bgt 0x2037a4 <_ZN7CDS_Map7Mark4GCEPji+0xc0> */
/* @0x203710 ldr r4, [r2, r5, lsl #3] */
/* @0x203714 cmp r4, #0 */
/* @0x203718 beq 0x203700 <_ZN7CDS_Map7Mark4GCEPji+0x1c> */
/* @0x20371c cmp r4, #0 */
/* @0x203720 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x203724 ldr r6, [r4, #0xc] */
/* @0x203728 cmp r6, #0 */
/* @0x20372c beq 0x20379c <_ZN7CDS_Map7Mark4GCEPji+0xb8> */
/* @0x203730 mov r0, r6 */
/* @0x203734 mov r1, r7 */
/* @0x203738 mov r2, r8 */
/* @0x20373c bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji> */
/* @0x203740 add r0, r6, #16 */
/* @0x203744 mov r1, r7 */
/* @0x203748 mov r2, r8 */
/* @0x20374c bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji> */
/* @0x203750 ldr r4, [r4, #0x4] */
/* @0x203754 cmp r4, #0 */
/* @0x203758 bne 0x20371c <_ZN7CDS_Map7Mark4GCEPji+0x38> */
/* @0x20375c ldr r12, [r9, #0x4] */
/* @0x203760 add r3, r5, #1 */
/* @0x203764 cmp r3, r12 */
/* @0x203768 popgt {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x20376c ldr r0, [r9] */
/* @0x203770 add r0, r0, r5, lsl #3 */
/* @0x203774 b 0x203780 <_ZN7CDS_Map7Mark4GCEPji+0x9c> */
/* @0x203778 cmp r3, r12 */
/* @0x20377c bgt 0x2037a0 <_ZN7CDS_Map7Mark4GCEPji+0xbc> */
/* @0x203780 ldr r4, [r0, #0x8] */
/* @0x203784 mov r5, r3 */
/* @0x203788 add r0, r0, #8 */
/* @0x20378c add r3, r3, #1 */
/* @0x203790 cmp r4, #0 */
/* @0x203794 beq 0x203778 <_ZN7CDS_Map7Mark4GCEPji+0x94> */
/* @0x203798 b 0x20371c <_ZN7CDS_Map7Mark4GCEPji+0x38> */
/* @0x20379c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2037a0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2037a4 cmp r4, #0 */
/* @0x2037a8 mvn r5, #0 */
/* @0x2037ac bne 0x203724 <_ZN7CDS_Map7Mark4GCEPji+0x40> */
/* @0x2037b0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x2037b4 · CDS_Map::Add4GC(CGCGeneration*) · size=196 · insn=49 */
/* @0x2037b4 push {r4, r5, r6, r7, r8, lr} */
/* @0x2037b8 mov r7, r1 */
/* @0x2037bc ldr r8, [r0] */
/* @0x2037c0 mov r5, #0 */
/* @0x2037c4 ldr r2, [r8] */
/* @0x2037c8 b 0x2037dc <_ZN7CDS_Map6Add4GCEP13CGCGeneration+0x28> */
/* @0x2037cc ldr r3, [r8, #0x4] */
/* @0x2037d0 add r5, r5, #1 */
/* @0x2037d4 cmp r5, r3 */
/* @0x2037d8 bgt 0x203868 <_ZN7CDS_Map6Add4GCEP13CGCGeneration+0xb4> */
/* @0x2037dc ldr r4, [r2, r5, lsl #3] */
/* @0x2037e0 cmp r4, #0 */
/* @0x2037e4 beq 0x2037cc <_ZN7CDS_Map6Add4GCEP13CGCGeneration+0x18> */
/* @0x2037e8 cmp r4, #0 */
/* @0x2037ec popeq {r4, r5, r6, r7, r8, pc} */
/* @0x2037f0 ldr r6, [r4, #0xc] */
/* @0x2037f4 cmp r6, #0 */
/* @0x2037f8 beq 0x203860 <_ZN7CDS_Map6Add4GCEP13CGCGeneration+0xac> */
/* @0x2037fc mov r0, r6 */
/* @0x203800 mov r1, r7 */
/* @0x203804 bl 0x191bac <_Z17RVALUE_GC_ADDROOTPK6RValueP13CGCGeneration> */
/* @0x203808 add r0, r6, #16 */
/* @0x20380c mov r1, r7 */
/* @0x203810 bl 0x191bac <_Z17RVALUE_GC_ADDROOTPK6RValueP13CGCGeneration> */
/* @0x203814 ldr r4, [r4, #0x4] */
/* @0x203818 cmp r4, #0 */
/* @0x20381c bne 0x2037e8 <_ZN7CDS_Map6Add4GCEP13CGCGeneration+0x34> */
/* @0x203820 ldr r0, [r8, #0x4] */
/* @0x203824 add r3, r5, #1 */
/* @0x203828 cmp r3, r0 */
/* @0x20382c popgt {r4, r5, r6, r7, r8, pc} */
/* @0x203830 ldr r2, [r8] */
/* @0x203834 add r2, r2, r5, lsl #3 */
/* @0x203838 b 0x203844 <_ZN7CDS_Map6Add4GCEP13CGCGeneration+0x90> */
/* @0x20383c cmp r3, r0 */
/* @0x203840 bgt 0x203864 <_ZN7CDS_Map6Add4GCEP13CGCGeneration+0xb0> */
/* @0x203844 ldr r4, [r2, #0x8] */
/* @0x203848 mov r5, r3 */
/* @0x20384c add r2, r2, #8 */
/* @0x203850 add r3, r3, #1 */
/* @0x203854 cmp r4, #0 */
/* @0x203858 beq 0x20383c <_ZN7CDS_Map6Add4GCEP13CGCGeneration+0x88> */
/* @0x20385c b 0x2037e8 <_ZN7CDS_Map6Add4GCEP13CGCGeneration+0x34> */
/* @0x203860 pop {r4, r5, r6, r7, r8, pc} */
/* @0x203864 pop {r4, r5, r6, r7, r8, pc} */
/* @0x203868 cmp r4, #0 */
/* @0x20386c mvn r5, #0 */
/* @0x203870 bne 0x2037f0 <_ZN7CDS_Map6Add4GCEP13CGCGeneration+0x3c> */
/* @0x203874 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x203878 · CDS_Map::MarkOnlyChildren4GC(unsigned int*, int) · size=208 · insn=52 */
/* @0x203878 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x20387c mov r8, r2 */
/* @0x203880 ldr r9, [r0] */
/* @0x203884 mov r7, r1 */
/* @0x203888 mov r5, #0 */
/* @0x20388c ldr r2, [r9] */
/* @0x203890 b 0x2038a4 <_ZN7CDS_Map19MarkOnlyChildren4GCEPji+0x2c> */
/* @0x203894 ldr r3, [r9, #0x4] */
/* @0x203898 add r5, r5, #1 */
/* @0x20389c cmp r5, r3 */
/* @0x2038a0 bgt 0x203938 <_ZN7CDS_Map19MarkOnlyChildren4GCEPji+0xc0> */
/* @0x2038a4 ldr r4, [r2, r5, lsl #3] */
/* @0x2038a8 cmp r4, #0 */
/* @0x2038ac beq 0x203894 <_ZN7CDS_Map19MarkOnlyChildren4GCEPji+0x1c> */
/* @0x2038b0 cmp r4, #0 */
/* @0x2038b4 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2038b8 ldr r6, [r4, #0xc] */
/* @0x2038bc cmp r6, #0 */
/* @0x2038c0 beq 0x203930 <_ZN7CDS_Map19MarkOnlyChildren4GCEPji+0xb8> */
/* @0x2038c4 mov r0, r6 */
/* @0x2038c8 mov r1, r7 */
/* @0x2038cc mov r2, r8 */
/* @0x2038d0 bl 0x191f5c <_Z18RVALUE_GC_THISONLYPK6RValuePji> */
/* @0x2038d4 add r0, r6, #16 */
/* @0x2038d8 mov r1, r7 */
/* @0x2038dc mov r2, r8 */
/* @0x2038e0 bl 0x191f5c <_Z18RVALUE_GC_THISONLYPK6RValuePji> */
/* @0x2038e4 ldr r4, [r4, #0x4] */
/* @0x2038e8 cmp r4, #0 */
/* @0x2038ec bne 0x2038b0 <_ZN7CDS_Map19MarkOnlyChildren4GCEPji+0x38> */
/* @0x2038f0 ldr r12, [r9, #0x4] */
/* @0x2038f4 add r3, r5, #1 */
/* @0x2038f8 cmp r3, r12 */
/* @0x2038fc popgt {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x203900 ldr r0, [r9] */
/* @0x203904 add r0, r0, r5, lsl #3 */
/* @0x203908 b 0x203914 <_ZN7CDS_Map19MarkOnlyChildren4GCEPji+0x9c> */
/* @0x20390c cmp r3, r12 */
/* @0x203910 bgt 0x203934 <_ZN7CDS_Map19MarkOnlyChildren4GCEPji+0xbc> */
/* @0x203914 ldr r4, [r0, #0x8] */
/* @0x203918 mov r5, r3 */
/* @0x20391c add r0, r0, #8 */
/* @0x203920 add r3, r3, #1 */
/* @0x203924 cmp r4, #0 */
/* @0x203928 beq 0x20390c <_ZN7CDS_Map19MarkOnlyChildren4GCEPji+0x94> */
/* @0x20392c b 0x2038b0 <_ZN7CDS_Map19MarkOnlyChildren4GCEPji+0x38> */
/* @0x203930 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x203934 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x203938 cmp r4, #0 */
/* @0x20393c mvn r5, #0 */
/* @0x203940 bne 0x2038b8 <_ZN7CDS_Map19MarkOnlyChildren4GCEPji+0x40> */
/* @0x203944 pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x203948 · CDS_Map::WriteToString(char const*&) · size=272 · insn=68 */
/* @0x203948 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x20394c mov r4, r0 */
/* @0x203950 mov r0, #32 */
/* @0x203954 mov r8, r1 */
/* @0x203958 bl 0x27c524 <_Znwj> */
/* @0x20395c mov r1, #0 */
/* @0x203960 mov r5, r1 */
/* @0x203964 mov r7, r0 */
/* @0x203968 bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x20396c mov r0, r7 */
/* @0x203970 movw r1, #0x192 */
/* @0x203974 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x203978 ldr r3, [r4] */
/* @0x20397c mov r0, r7 */
/* @0x203980 ldr r1, [r3, #0x8] */
/* @0x203984 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x203988 ldr r9, [r4] */
/* @0x20398c ldr r2, [r9] */
/* @0x203990 b 0x2039a4 <_ZN7CDS_Map13WriteToStringERPKc+0x5c> */
/* @0x203994 ldr r3, [r9, #0x4] */
/* @0x203998 add r5, r5, #1 */
/* @0x20399c cmp r5, r3 */
/* @0x2039a0 bgt 0x203a50 <_ZN7CDS_Map13WriteToStringERPKc+0x108> */
/* @0x2039a4 ldr r4, [r2, r5, lsl #3] */
/* @0x2039a8 cmp r4, #0 */
/* @0x2039ac beq 0x203994 <_ZN7CDS_Map13WriteToStringERPKc+0x4c> */
/* @0x2039b0 cmp r4, #0 */
/* @0x2039b4 beq 0x203a28 <_ZN7CDS_Map13WriteToStringERPKc+0xe0> */
/* @0x2039b8 ldr r6, [r4, #0xc] */
/* @0x2039bc cmp r6, #0 */
/* @0x2039c0 beq 0x203a28 <_ZN7CDS_Map13WriteToStringERPKc+0xe0> */
/* @0x2039c4 mov r0, r7 */
/* @0x2039c8 mov r1, r6 */
/* @0x2039cc bl 0x202af8 <_Z10WriteValueR7CStreamR6RValue> */
/* @0x2039d0 mov r0, r7 */
/* @0x2039d4 add r1, r6, #16 */
/* @0x2039d8 bl 0x202af8 <_Z10WriteValueR7CStreamR6RValue> */
/* @0x2039dc ldr r4, [r4, #0x4] */
/* @0x2039e0 cmp r4, #0 */
/* @0x2039e4 bne 0x2039b0 <_ZN7CDS_Map13WriteToStringERPKc+0x68> */
/* @0x2039e8 ldr r12, [r9, #0x4] */
/* @0x2039ec add r3, r5, #1 */
/* @0x2039f0 cmp r3, r12 */
/* @0x2039f4 bgt 0x203a28 <_ZN7CDS_Map13WriteToStringERPKc+0xe0> */
/* @0x2039f8 ldr r2, [r9] */
/* @0x2039fc add r2, r2, r5, lsl #3 */
/* @0x203a00 b 0x203a0c <_ZN7CDS_Map13WriteToStringERPKc+0xc4> */
/* @0x203a04 cmp r3, r12 */
/* @0x203a08 bgt 0x203a28 <_ZN7CDS_Map13WriteToStringERPKc+0xe0> */
/* @0x203a0c ldr r4, [r2, #0x8] */
/* @0x203a10 mov r5, r3 */
/* @0x203a14 add r2, r2, #8 */
/* @0x203a18 add r3, r3, #1 */
/* @0x203a1c cmp r4, #0 */
/* @0x203a20 beq 0x203a04 <_ZN7CDS_Map13WriteToStringERPKc+0xbc> */
/* @0x203a24 b 0x2039b0 <_ZN7CDS_Map13WriteToStringERPKc+0x68> */
/* @0x203a28 mov r1, r8 */
/* @0x203a2c mov r0, r7 */
/* @0x203a30 bl 0x2024b0 <_ZN7CStream15ConvertToStringERPKc> */
/* @0x203a34 cmp r7, #0 */
/* @0x203a38 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x203a3c mov r0, r7 */
/* @0x203a40 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x203a44 mov r0, r7 */
/* @0x203a48 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x203a4c b 0x27d1d0 <_ZdlPv> */
/* @0x203a50 mvn r5, #0 */
/* @0x203a54 b 0x2039b0 <_ZN7CDS_Map13WriteToStringERPKc+0x68> */

/* ── FUNC 0x203a58 · CDS_Map::Empty() · size=20 · insn=5 */
/* @0x203a58 ldr r3, [r0] */
/* @0x203a5c ldr r0, [r3, #0x8] */
/* @0x203a60 rsbs r0, r0, #1 */
/* @0x203a64 movlo r0, #0 */
/* @0x203a68 bx lr */

/* ── FUNC 0x203a6c · CDS_Map::Exists(RValue*) · size=20 · insn=5 */
/* @0x203a6c push {r3, lr} */
/* @0x203a70 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x203a74 adds r0, r0, #0 */
/* @0x203a78 movne r0, #1 */
/* @0x203a7c pop {r3, pc} */

/* ── FUNC 0x203a80 · CDS_Map::FindPrevious(RValue*) · size=276 · insn=69 */
/* @0x203a80 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x203a84 mov r8, r1 */
/* @0x203a88 ldr r9, [r0] */
/* @0x203a8c sub sp, sp, #16 */
/* @0x203a90 mov r5, #0 */
/* @0x203a94 ldr r2, [r9] */
/* @0x203a98 b 0x203aac <_ZN7CDS_Map12FindPreviousEP6RValue+0x2c> */
/* @0x203a9c ldr r3, [r9, #0x4] */
/* @0x203aa0 add r5, r5, #1 */
/* @0x203aa4 cmp r5, r3 */
/* @0x203aa8 bgt 0x203b74 <_ZN7CDS_Map12FindPreviousEP6RValue+0xf4> */
/* @0x203aac ldr r4, [r2, r5, lsl #3] */
/* @0x203ab0 cmp r4, #0 */
/* @0x203ab4 beq 0x203a9c <_ZN7CDS_Map12FindPreviousEP6RValue+0x1c> */
/* @0x203ab8 mov r10, #0 */
/* @0x203abc b 0x203ac4 <_ZN7CDS_Map12FindPreviousEP6RValue+0x44> */
/* @0x203ac0 mov r10, r6 */
/* @0x203ac4 cmp r4, #0 */
/* @0x203ac8 beq 0x203b68 <_ZN7CDS_Map12FindPreviousEP6RValue+0xe8> */
/* @0x203acc ldr r6, [r4, #0xc] */
/* @0x203ad0 cmp r6, #0 */
/* @0x203ad4 beq 0x203b88 <_ZN7CDS_Map12FindPreviousEP6RValue+0x108> */
/* @0x203ad8 ldr lr, [pc, #0xb0] */
/* @0x203adc mov r12, sp */
/* @0x203ae0 ldr r3, [r6, #0xc] */
/* @0x203ae4 ldr r0, [r6] */
/* @0x203ae8 ldr lr, [pc, lr] */
/* @0x203aec ldr r1, [r6, #0x4] */
/* @0x203af0 ldr r2, [r6, #0x8] */
/* @0x203af4 stm r12!, {r0, r1, r2, r3} */
/* @0x203af8 mov r12, r3 */
/* @0x203afc mov r0, r8 */
/* @0x203b00 mov r1, sp */
/* @0x203b04 ldrd r2, r3, [lr] */
/* @0x203b08 bic r12, r12, #-16777216 */
/* @0x203b0c str r12, [sp, #0xc] */
/* @0x203b10 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x203b14 cmp r0, #0 */
/* @0x203b18 beq 0x203b7c <_ZN7CDS_Map12FindPreviousEP6RValue+0xfc> */
/* @0x203b1c ldr r4, [r4, #0x4] */
/* @0x203b20 cmp r4, #0 */
/* @0x203b24 bne 0x203ac0 <_ZN7CDS_Map12FindPreviousEP6RValue+0x40> */
/* @0x203b28 ldr r1, [r9, #0x4] */
/* @0x203b2c add r2, r5, #1 */
/* @0x203b30 cmp r2, r1 */
/* @0x203b34 bgt 0x203b60 <_ZN7CDS_Map12FindPreviousEP6RValue+0xe0> */
/* @0x203b38 ldr r3, [r9] */
/* @0x203b3c add r3, r3, r5, lsl #3 */
/* @0x203b40 ldr r4, [r3, #0x8] */
/* @0x203b44 mov r5, r2 */
/* @0x203b48 add r3, r3, #8 */
/* @0x203b4c add r2, r2, #1 */
/* @0x203b50 cmp r4, #0 */
/* @0x203b54 bne 0x203ac0 <_ZN7CDS_Map12FindPreviousEP6RValue+0x40> */
/* @0x203b58 cmp r2, r1 */
/* @0x203b5c ble 0x203b40 <_ZN7CDS_Map12FindPreviousEP6RValue+0xc0> */
/* @0x203b60 mvn r5, #0 */
/* @0x203b64 b 0x203ac0 <_ZN7CDS_Map12FindPreviousEP6RValue+0x40> */
/* @0x203b68 mov r0, r4 */
/* @0x203b6c add sp, sp, #16 */
/* @0x203b70 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x203b74 mvn r5, #0 */
/* @0x203b78 b 0x203ab8 <_ZN7CDS_Map12FindPreviousEP6RValue+0x38> */
/* @0x203b7c mov r0, r10 */
/* @0x203b80 add sp, sp, #16 */
/* @0x203b84 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x203b88 mov r0, r6 */
/* @0x203b8c b 0x203b6c <_ZN7CDS_Map12FindPreviousEP6RValue+0xec> */
/* @0x203b90 mulseq lr, r12, r8 */

/* ── FUNC 0x203b94 · CDS_Map::FindNext(RValue*) · size=248 · insn=62 */
/* @0x203b94 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x203b98 mov r8, r1 */
/* @0x203b9c ldr r9, [r0] */
/* @0x203ba0 sub sp, sp, #16 */
/* @0x203ba4 mov r5, #0 */
/* @0x203ba8 ldr r2, [r9] */
/* @0x203bac b 0x203bc0 <_ZN7CDS_Map8FindNextEP6RValue+0x2c> */
/* @0x203bb0 ldr r3, [r9, #0x4] */
/* @0x203bb4 add r5, r5, #1 */
/* @0x203bb8 cmp r5, r3 */
/* @0x203bbc bgt 0x203c80 <_ZN7CDS_Map8FindNextEP6RValue+0xec> */
/* @0x203bc0 ldr r4, [r2, r5, lsl #3] */
/* @0x203bc4 cmp r4, #0 */
/* @0x203bc8 beq 0x203bb0 <_ZN7CDS_Map8FindNextEP6RValue+0x1c> */
/* @0x203bcc mov r10, #0 */
/* @0x203bd0 cmp r4, #0 */
/* @0x203bd4 beq 0x203c70 <_ZN7CDS_Map8FindNextEP6RValue+0xdc> */
/* @0x203bd8 ldr r6, [r4, #0xc] */
/* @0x203bdc cmp r6, #0 */
/* @0x203be0 beq 0x203c74 <_ZN7CDS_Map8FindNextEP6RValue+0xe0> */
/* @0x203be4 ldr r3, [r6, #0xc] */
/* @0x203be8 cmp r10, #0 */
/* @0x203bec ldr r0, [r6] */
/* @0x203bf0 mov r12, sp */
/* @0x203bf4 ldr r1, [r6, #0x4] */
/* @0x203bf8 ldr r2, [r6, #0x8] */
/* @0x203bfc stm r12!, {r0, r1, r2, r3} */
/* @0x203c00 bic r3, r3, #-16777216 */
/* @0x203c04 str r3, [sp, #0xc] */
/* @0x203c08 bne 0x203c74 <_ZN7CDS_Map8FindNextEP6RValue+0xe0> */
/* @0x203c0c ldr r3, [pc, #0x74] */
/* @0x203c10 mov r0, r8 */
/* @0x203c14 mov r1, sp */
/* @0x203c18 ldr r3, [pc, r3] */
/* @0x203c1c ldrd r2, r3, [r3] */
/* @0x203c20 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x203c24 ldr r4, [r4, #0x4] */
/* @0x203c28 rsbs r10, r0, #1 */
/* @0x203c2c movlo r10, #0 */
/* @0x203c30 cmp r4, #0 */
/* @0x203c34 bne 0x203bd0 <_ZN7CDS_Map8FindNextEP6RValue+0x3c> */
/* @0x203c38 ldr r1, [r9, #0x4] */
/* @0x203c3c add r3, r5, #1 */
/* @0x203c40 cmp r3, r1 */
/* @0x203c44 bgt 0x203c70 <_ZN7CDS_Map8FindNextEP6RValue+0xdc> */
/* @0x203c48 ldr r2, [r9] */
/* @0x203c4c add r2, r2, r5, lsl #3 */
/* @0x203c50 ldr r4, [r2, #0x8] */
/* @0x203c54 mov r5, r3 */
/* @0x203c58 add r2, r2, #8 */
/* @0x203c5c add r3, r3, #1 */
/* @0x203c60 cmp r4, #0 */
/* @0x203c64 bne 0x203bd0 <_ZN7CDS_Map8FindNextEP6RValue+0x3c> */
/* @0x203c68 cmp r3, r1 */
/* @0x203c6c ble 0x203c50 <_ZN7CDS_Map8FindNextEP6RValue+0xbc> */
/* @0x203c70 mov r6, #0 */
/* @0x203c74 mov r0, r6 */
/* @0x203c78 add sp, sp, #16 */
/* @0x203c7c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x203c80 mvn r5, #0 */
/* @0x203c84 b 0x203bcc <_ZN7CDS_Map8FindNextEP6RValue+0x38> */
/* @0x203c88 andseq sp, lr, r12, ror #14 */
