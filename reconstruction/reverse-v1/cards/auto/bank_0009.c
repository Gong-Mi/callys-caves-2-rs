/* libyoyo.so 覆盖卡组 0009
 * 函数 0xcacec..0xcd128，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xcacec · Buffer_Network::~Buffer_Network() · alias of the symbol above · insn=0 */

/* ── FUNC 0xcad14 · Buffer_Network::~Buffer_Network() · size=48 · insn=12 */
/* @0xcad14 ldr r3, [pc, #0x24] */
/* @0xcad18 push {r4, lr} */
/* @0xcad1c ldr r3, [pc, r3] */
/* @0xcad20 mov r4, r0 */
/* @0xcad24 add r3, r3, #8 */
/* @0xcad28 str r3, [r0] */
/* @0xcad2c bl 0xcb818 <_ZN7IBufferD2Ev> */
/* @0xcad30 mov r0, r4 */
/* @0xcad34 bl 0x27d1d0 <_ZdlPv> */
/* @0xcad38 mov r0, r4 */
/* @0xcad3c pop {r4, pc} */
/* @0xcad40 eorseq r2, r2, r12, ror #27 */

/* ── FUNC 0xcad44 · Buffer_Network::Write(eBuffer_Type, RValue*) · size=772 · insn=193 */
/* @0xcad44 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xcad48 mov r6, r0 */
/* @0xcad4c ldr r3, [r0, #0x24] */
/* @0xcad50 sub r1, r1, #1 */
/* @0xcad54 ldr r7, [r0, #0x1c] */
/* @0xcad58 sub sp, sp, #20 */
/* @0xcad5c ldr r0, [r0, #0x14] */
/* @0xcad60 add r7, r3, r7 */
/* @0xcad64 sub r12, r0, #1 */
/* @0xcad68 rsb r0, r0, #0 */
/* @0xcad6c add r7, r7, r12 */
/* @0xcad70 and r7, r7, r0 */
/* @0xcad74 rsb r7, r3, r7 */
/* @0xcad78 str r7, [r6, #0x1c] */
/* @0xcad7c cmp r1, #12 */
/* @0xcad80 addls pc, pc, r1, lsl #2 */
/* @0xcad84 b 0xcb020 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x2dc> */
/* @0xcad88 b 0xcae44 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x100> */
/* @0xcad8c b 0xcae68 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x124> */
/* @0xcad90 b 0xcae8c <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x148> */
/* @0xcad94 b 0xcaeb0 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x16c> */
/* @0xcad98 b 0xcaed4 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x190> */
/* @0xcad9c b 0xcaef8 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x1b4> */
/* @0xcada0 b 0xcb020 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x2dc> */
/* @0xcada4 b 0xcaf1c <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x1d8> */
/* @0xcada8 b 0xcaf40 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x1fc> */
/* @0xcadac b 0xcaf78 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x234> */
/* @0xcadb0 b 0xcafac <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x268> */
/* @0xcadb4 b 0xcafd0 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x28c> */
/* @0xcadb8 b 0xcadbc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x78> */
/* @0xcadbc ldr r3, [r2, #0xc] */
/* @0xcadc0 bic r3, r3, #-16777216 */
/* @0xcadc4 cmp r3, #1 */
/* @0xcadc8 movne r8, #0 */
/* @0xcadcc beq 0xcb038 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x2f4> */
/* @0xcadd0 mov r0, r8 */
/* @0xcadd4 bl 0xb6538 <strlen@plt> */
/* @0xcadd8 mov r9, r0 */
/* @0xcaddc ldr r1, [r6, #0x10] */
/* @0xcade0 add r3, r9, r7 */
/* @0xcade4 cmp r3, r1 */
/* @0xcade8 bge 0xcb000 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x2bc> */
/* @0xcadec ldr r3, [r6, #0xc] */
/* @0xcadf0 cmp r9, #0 */
/* @0xcadf4 add r3, r3, r7 */
/* @0xcadf8 ble 0xcae14 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0xd0> */
/* @0xcadfc add r1, r3, r9 */
/* @0xcae00 ldrb r2, [r8], #1 */
/* @0xcae04 strb r2, [r3], #1 */
/* @0xcae08 cmp r3, r1 */
/* @0xcae0c bne 0xcae00 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0xbc> */
/* @0xcae10 ldr r7, [r6, #0x1c] */
/* @0xcae14 ldr r3, [r6, #0x10] */
/* @0xcae18 add r7, r9, r7 */
/* @0xcae1c ldr r9, [r6, #0x20] */
/* @0xcae20 mov r0, #0 */
/* @0xcae24 str r7, [r6, #0x1c] */
/* @0xcae28 cmp r7, r9 */
/* @0xcae2c movlt r7, r9 */
/* @0xcae30 cmp r7, r3 */
/* @0xcae34 strle r7, [r6, #0x20] */
/* @0xcae38 strgt r3, [r6, #0x20] */
/* @0xcae3c add sp, sp, #20 */
/* @0xcae40 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xcae44 ldr r4, [r2] */
/* @0xcae48 add r8, sp, #16 */
/* @0xcae4c ldr r5, [r2, #0x4] */
/* @0xcae50 mov r9, #1 */
/* @0xcae54 vmov d6, r4, r5 */
/* @0xcae58 vcvt.u32.f64 s13, d6 */
/* @0xcae5c vmov r4, s13 */
/* @0xcae60 strb r4, [r8, #-0x10]! */
/* @0xcae64 b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98> */
/* @0xcae68 ldr r4, [r2] */
/* @0xcae6c add r8, sp, #16 */
/* @0xcae70 ldr r5, [r2, #0x4] */
/* @0xcae74 mov r9, #1 */
/* @0xcae78 vmov d7, r4, r5 */
/* @0xcae7c vcvt.s32.f64 s15, d7 */
/* @0xcae80 vmov r4, s15 */
/* @0xcae84 strb r4, [r8, #-0x10]! */
/* @0xcae88 b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98> */
/* @0xcae8c ldm r2, {r0, r1} */
/* @0xcae90 vmov d7, r0, r1 */
/* @0xcae94 vcvt.u32.f64 s15, d7 */
/* @0xcae98 vmov r0, s15 */
/* @0xcae9c rev16 r0, r0 */
/* @0xcaea0 add r8, sp, #16 */
/* @0xcaea4 mov r9, #2 */
/* @0xcaea8 strh r0, [r8, #-16]! */
/* @0xcaeac b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98> */
/* @0xcaeb0 ldm r2, {r0, r1} */
/* @0xcaeb4 vmov d6, r0, r1 */
/* @0xcaeb8 vcvt.s32.f64 s13, d6 */
/* @0xcaebc vmov r0, s13 */
/* @0xcaec0 rev16 r0, r0 */
/* @0xcaec4 add r8, sp, #16 */
/* @0xcaec8 mov r9, #2 */
/* @0xcaecc strh r0, [r8, #-16]! */
/* @0xcaed0 b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98> */
/* @0xcaed4 ldm r2, {r0, r1} */
/* @0xcaed8 vmov d7, r0, r1 */
/* @0xcaedc vcvt.u32.f64 s15, d7 */
/* @0xcaee0 vmov r0, s15 */
/* @0xcaee4 rev r0, r0 */
/* @0xcaee8 add r8, sp, #16 */
/* @0xcaeec mov r9, #4 */
/* @0xcaef0 str r0, [r8, #-0x10]! */
/* @0xcaef4 b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98> */
/* @0xcaef8 ldm r2, {r4, r5} */
/* @0xcaefc vmov d6, r4, r5 */
/* @0xcaf00 vcvt.s32.f64 s13, d6 */
/* @0xcaf04 vmov r4, s13 */
/* @0xcaf08 rev r4, r4 */
/* @0xcaf0c add r8, sp, #16 */
/* @0xcaf10 mov r9, #4 */
/* @0xcaf14 str r4, [r8, #-0x10]! */
/* @0xcaf18 b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98> */
/* @0xcaf1c ldm r2, {r4, r5} */
/* @0xcaf20 vmov d7, r4, r5 */
/* @0xcaf24 vcvt.f32.f64 s15, d7 */
/* @0xcaf28 vmov r4, s15 */
/* @0xcaf2c rev r4, r4 */
/* @0xcaf30 add r8, sp, #16 */
/* @0xcaf34 mov r9, #4 */
/* @0xcaf38 str r4, [r8, #-0x10]! */
/* @0xcaf3c b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98> */
/* @0xcaf40 ldm r2, {r4, r5} */
/* @0xcaf44 vmov d6, r4, r5 */
/* @0xcaf48 vcvt.f32.f64 s14, d6 */
/* @0xcaf4c vcvt.f64.f32 d7, s14 */
/* @0xcaf50 vstr d7, [sp, #8] */
/* @0xcaf54 ldr r3, [sp, #0x8] */
/* @0xcaf58 rev r3, r3 */
/* @0xcaf5c str r3, [sp] */
/* @0xcaf60 ldr r3, [sp, #0xc] */
/* @0xcaf64 rev r3, r3 */
/* @0xcaf68 mov r9, #8 */
/* @0xcaf6c str r3, [sp, #0x4] */
/* @0xcaf70 mov r8, sp */
/* @0xcaf74 b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98> */
/* @0xcaf78 vmov.f64 d7, #5.000000e-01 */
/* @0xcaf7c ldm r2, {r0, r1} */
/* @0xcaf80 vmov d6, r0, r1 */
/* @0xcaf84 vcmpe.f64 d6, d7 */
/* @0xcaf88 vmrs APSR_nzcv, fpscr */
/* @0xcaf8c addgt r8, sp, #16 */
/* @0xcaf90 addle r8, sp, #16 */
/* @0xcaf94 movgt r9, #1 */
/* @0xcaf98 movle r3, #0 */
/* @0xcaf9c strbgt r9, [r8, #-0x10]! */
/* @0xcafa0 movle r9, #1 */
/* @0xcafa4 strble r3, [r8, #-0x10]! */
/* @0xcafa8 b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98> */
/* @0xcafac ldr r3, [r2, #0xc] */
/* @0xcafb0 bic r3, r3, #-16777216 */
/* @0xcafb4 cmp r3, #1 */
/* @0xcafb8 movne r8, #0 */
/* @0xcafbc beq 0xcb028 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x2e4> */
/* @0xcafc0 mov r0, r8 */
/* @0xcafc4 bl 0xb6538 <strlen@plt> */
/* @0xcafc8 add r9, r0, #1 */
/* @0xcafcc b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98> */
/* @0xcafd0 ldm r2, {r0, r1} */
/* @0xcafd4 bl 0x319550 <__fixunsdfdi> */
/* @0xcafd8 str r1, [sp, #0xc] */
/* @0xcafdc str r0, [sp, #0x8] */
/* @0xcafe0 rev r0, r0 */
/* @0xcafe4 str r0, [sp] */
/* @0xcafe8 mov r3, r1 */
/* @0xcafec rev r3, r3 */
/* @0xcaff0 mov r9, #8 */
/* @0xcaff4 str r3, [sp, #0x4] */
/* @0xcaff8 mov r8, sp */
/* @0xcaffc b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98> */
/* @0xcb000 ldr r3, [r6] */
/* @0xcb004 lsl r1, r1, #1 */
/* @0xcb008 str r7, [r6, #0x10] */
/* @0xcb00c mov r0, r6 */
/* @0xcb010 ldr r3, [r3, #0x34] */
/* @0xcb014 blx r3 */
/* @0xcb018 ldr r7, [r6, #0x1c] */
/* @0xcb01c b 0xcadec <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0xa8> */
/* @0xcb020 mvn r0, #0 */
/* @0xcb024 b 0xcae3c <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0xf8> */
/* @0xcb028 ldr r8, [r2] */
/* @0xcb02c cmp r8, #0 */
/* @0xcb030 ldrne r8, [r8] */
/* @0xcb034 b 0xcafc0 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x27c> */
/* @0xcb038 ldr r8, [r2] */
/* @0xcb03c cmp r8, #0 */
/* @0xcb040 ldrne r8, [r8] */
/* @0xcb044 b 0xcadd0 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x8c> */

/* ── FUNC 0xcb048 · Buffer_Network::Poke(int, eBuffer_Type, RValue*) · size=732 · insn=183 */
/* @0xcb048 push {r4, r5, r6, r7, lr} */
/* @0xcb04c subs r5, r1, #0 */
/* @0xcb050 sub sp, sp, #20 */
/* @0xcb054 mov r4, r0 */
/* @0xcb058 mov r1, r3 */
/* @0xcb05c blt 0xcb06c <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x24> */
/* @0xcb060 ldr r6, [r0, #0x10] */
/* @0xcb064 cmp r5, r6 */
/* @0xcb068 blt 0xcb074 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x2c> */
/* @0xcb06c add sp, sp, #20 */
/* @0xcb070 pop {r4, r5, r6, r7, pc} */
/* @0xcb074 sub r2, r2, #1 */
/* @0xcb078 cmp r2, #12 */
/* @0xcb07c addls pc, pc, r2, lsl #2 */
/* @0xcb080 b 0xcb06c <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x24> */
/* @0xcb084 b 0xcb124 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0xdc> */
/* @0xcb088 b 0xcb124 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0xdc> */
/* @0xcb08c b 0xcb16c <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x124> */
/* @0xcb090 b 0xcb190 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x148> */
/* @0xcb094 b 0xcb1b4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x16c> */
/* @0xcb098 b 0xcb1d8 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x190> */
/* @0xcb09c b 0xcb06c <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x24> */
/* @0xcb0a0 b 0xcb1fc <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x1b4> */
/* @0xcb0a4 b 0xcb220 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x1d8> */
/* @0xcb0a8 b 0xcb258 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x210> */
/* @0xcb0ac b 0xcb284 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x23c> */
/* @0xcb0b0 b 0xcb2a8 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x260> */
/* @0xcb0b4 b 0xcb0b8 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x70> */
/* @0xcb0b8 ldr r3, [r3, #0xc] */
/* @0xcb0bc bic r3, r3, #-16777216 */
/* @0xcb0c0 cmp r3, #1 */
/* @0xcb0c4 movne r7, #0 */
/* @0xcb0c8 beq 0xcb314 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x2cc> */
/* @0xcb0cc mov r0, r7 */
/* @0xcb0d0 bl 0xb6538 <strlen@plt> */
/* @0xcb0d4 add r3, r5, r0 */
/* @0xcb0d8 cmn r3, #1 */
/* @0xcb0dc beq 0xcb2e0 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x298> */
/* @0xcb0e0 ldr r1, [r4, #0x20] */
/* @0xcb0e4 ldr r2, [r4, #0xc] */
/* @0xcb0e8 cmp r3, r1 */
/* @0xcb0ec movlt r3, r1 */
/* @0xcb0f0 cmp r3, r6 */
/* @0xcb0f4 strle r3, [r4, #0x20] */
/* @0xcb0f8 strgt r6, [r4, #0x20] */
/* @0xcb0fc cmp r0, #0 */
/* @0xcb100 add r5, r2, r5 */
/* @0xcb104 ble 0xcb06c <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x24> */
/* @0xcb108 add r2, r5, r0 */
/* @0xcb10c ldrb r3, [r7], #1 */
/* @0xcb110 strb r3, [r5], #1 */
/* @0xcb114 cmp r5, r2 */
/* @0xcb118 bne 0xcb10c <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0xc4> */
/* @0xcb11c add sp, sp, #20 */
/* @0xcb120 pop {r4, r5, r6, r7, pc} */
/* @0xcb124 ldr r2, [r3] */
/* @0xcb128 add r0, r5, #1 */
/* @0xcb12c ldr r3, [r3, #0x4] */
/* @0xcb130 cmn r0, #1 */
/* @0xcb134 ldr r12, [r4, #0xc] */
/* @0xcb138 vmov d7, r2, r3 */
/* @0xcb13c vcvt.s32.f64 s15, d7 */
/* @0xcb140 vmov r2, s15 */
/* @0xcb144 strb r2, [r12, r5] */
/* @0xcb148 beq 0xcb30c <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x2c4> */
/* @0xcb14c ldr r3, [r4, #0x10] */
/* @0xcb150 ldr r2, [r4, #0x20] */
/* @0xcb154 cmp r0, r2 */
/* @0xcb158 movlt r0, r2 */
/* @0xcb15c cmp r0, r3 */
/* @0xcb160 strle r0, [r4, #0x20] */
/* @0xcb164 strgt r3, [r4, #0x20] */
/* @0xcb168 b 0xcb06c <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x24> */
/* @0xcb16c ldm r3, {r2, r3} */
/* @0xcb170 vmov d7, r2, r3 */
/* @0xcb174 vcvt.u32.f64 s15, d7 */
/* @0xcb178 vmov r2, s15 */
/* @0xcb17c rev16 r2, r2 */
/* @0xcb180 add r7, sp, #16 */
/* @0xcb184 mov r0, #2 */
/* @0xcb188 strh r2, [r7, #-16]! */
/* @0xcb18c b 0xcb0d4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x8c> */
/* @0xcb190 ldm r3, {r2, r3} */
/* @0xcb194 vmov d6, r2, r3 */
/* @0xcb198 vcvt.s32.f64 s13, d6 */
/* @0xcb19c vmov r2, s13 */
/* @0xcb1a0 rev16 r2, r2 */
/* @0xcb1a4 add r7, sp, #16 */
/* @0xcb1a8 mov r0, #2 */
/* @0xcb1ac strh r2, [r7, #-16]! */
/* @0xcb1b0 b 0xcb0d4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x8c> */
/* @0xcb1b4 ldm r3, {r2, r3} */
/* @0xcb1b8 vmov d7, r2, r3 */
/* @0xcb1bc vcvt.u32.f64 s15, d7 */
/* @0xcb1c0 vmov r2, s15 */
/* @0xcb1c4 rev r2, r2 */
/* @0xcb1c8 add r7, sp, #16 */
/* @0xcb1cc mov r0, #4 */
/* @0xcb1d0 str r2, [r7, #-0x10]! */
/* @0xcb1d4 b 0xcb0d4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x8c> */
/* @0xcb1d8 ldm r3, {r2, r3} */
/* @0xcb1dc vmov d6, r2, r3 */
/* @0xcb1e0 vcvt.s32.f64 s13, d6 */
/* @0xcb1e4 vmov r2, s13 */
/* @0xcb1e8 rev r2, r2 */
/* @0xcb1ec add r7, sp, #16 */
/* @0xcb1f0 mov r0, #4 */
/* @0xcb1f4 str r2, [r7, #-0x10]! */
/* @0xcb1f8 b 0xcb0d4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x8c> */
/* @0xcb1fc ldm r3, {r2, r3} */
/* @0xcb200 vmov d7, r2, r3 */
/* @0xcb204 vcvt.f32.f64 s15, d7 */
/* @0xcb208 vmov r2, s15 */
/* @0xcb20c rev r2, r2 */
/* @0xcb210 add r7, sp, #16 */
/* @0xcb214 mov r0, #4 */
/* @0xcb218 str r2, [r7, #-0x10]! */
/* @0xcb21c b 0xcb0d4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x8c> */
/* @0xcb220 ldm r3, {r2, r3} */
/* @0xcb224 vmov d6, r2, r3 */
/* @0xcb228 vcvt.f32.f64 s14, d6 */
/* @0xcb22c vcvt.f64.f32 d7, s14 */
/* @0xcb230 vstr d7, [sp, #8] */
/* @0xcb234 ldr r3, [sp, #0x8] */
/* @0xcb238 rev r3, r3 */
/* @0xcb23c str r3, [sp] */
/* @0xcb240 ldr r3, [sp, #0xc] */
/* @0xcb244 rev r3, r3 */
/* @0xcb248 mov r0, #8 */
/* @0xcb24c str r3, [sp, #0x4] */
/* @0xcb250 mov r7, sp */
/* @0xcb254 b 0xcb0d4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x8c> */
/* @0xcb258 vmov.f64 d7, #5.000000e-01 */
/* @0xcb25c ldm r3, {r2, r3} */
/* @0xcb260 vmov d6, r2, r3 */
/* @0xcb264 vcmpe.f64 d6, d7 */
/* @0xcb268 vmrs APSR_nzcv, fpscr */
/* @0xcb26c ble 0xcb2e8 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x2a0> */
/* @0xcb270 add r7, sp, #16 */
/* @0xcb274 mov r3, #1 */
/* @0xcb278 mov r0, r3 */
/* @0xcb27c strb r3, [r7, #-0x10]! */
/* @0xcb280 b 0xcb0d4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x8c> */
/* @0xcb284 ldr r3, [r3, #0xc] */
/* @0xcb288 bic r3, r3, #-16777216 */
/* @0xcb28c cmp r3, #1 */
/* @0xcb290 movne r7, #0 */
/* @0xcb294 beq 0xcb2fc <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x2b4> */
/* @0xcb298 mov r0, r7 */
/* @0xcb29c bl 0xb6538 <strlen@plt> */
/* @0xcb2a0 add r0, r0, #1 */
/* @0xcb2a4 b 0xcb0d4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x8c> */
/* @0xcb2a8 ldm r3, {r2, r3} */
/* @0xcb2ac mov r0, r2 */
/* @0xcb2b0 mov r1, r3 */
/* @0xcb2b4 bl 0x319550 <__fixunsdfdi> */
/* @0xcb2b8 str r1, [sp, #0xc] */
/* @0xcb2bc str r0, [sp, #0x8] */
/* @0xcb2c0 rev r0, r0 */
/* @0xcb2c4 str r0, [sp] */
/* @0xcb2c8 mov r3, r1 */
/* @0xcb2cc rev r3, r3 */
/* @0xcb2d0 mov r0, #8 */
/* @0xcb2d4 str r3, [sp, #0x4] */
/* @0xcb2d8 mov r7, sp */
/* @0xcb2dc b 0xcb0d4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x8c> */
/* @0xcb2e0 ldr r3, [r4, #0x1c] */
/* @0xcb2e4 b 0xcb0e0 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x98> */
/* @0xcb2e8 add r7, sp, #16 */
/* @0xcb2ec mov r3, #0 */
/* @0xcb2f0 mov r0, #1 */
/* @0xcb2f4 strb r3, [r7, #-0x10]! */
/* @0xcb2f8 b 0xcb0d4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x8c> */
/* @0xcb2fc ldr r7, [r1] */
/* @0xcb300 cmp r7, #0 */
/* @0xcb304 ldrne r7, [r7] */
/* @0xcb308 b 0xcb298 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x250> */
/* @0xcb30c ldr r0, [r4, #0x1c] */
/* @0xcb310 b 0xcb14c <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x104> */
/* @0xcb314 ldr r7, [r1] */
/* @0xcb318 cmp r7, #0 */
/* @0xcb31c ldrne r7, [r7] */
/* @0xcb320 b 0xcb0cc <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x84> */

/* ── FUNC 0xcb324 · Buffer_Network::Read(eBuffer_Type, RValue*) · size=628 · insn=157 */
/* @0xcb324 push {r4, r5, r6, r7, r8, lr} */
/* @0xcb328 mov r4, #0 */
/* @0xcb32c mov r7, r2 */
/* @0xcb330 str r4, [r2] */
/* @0xcb334 str r4, [r2, #0x4] */
/* @0xcb338 sub sp, sp, #8 */
/* @0xcb33c ldr r3, [r0, #0x1c] */
/* @0xcb340 mov r6, r0 */
/* @0xcb344 ldr r2, [r0, #0x10] */
/* @0xcb348 str r4, [r7, #0xc] */
/* @0xcb34c cmp r3, r2 */
/* @0xcb350 bge 0xcb58c <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x268> */
/* @0xcb354 ldr r2, [r0, #0x24] */
/* @0xcb358 cmp r1, #11 */
/* @0xcb35c cmpne r1, #13 */
/* @0xcb360 ldr r0, [r0, #0x14] */
/* @0xcb364 add r3, r3, r2 */
/* @0xcb368 sub r12, r0, #1 */
/* @0xcb36c rsb r0, r0, #0 */
/* @0xcb370 add r3, r3, r12 */
/* @0xcb374 and r3, r3, r0 */
/* @0xcb378 rsb r3, r2, r3 */
/* @0xcb37c str r3, [r6, #0x1c] */
/* @0xcb380 beq 0xcb518 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x1f4> */
/* @0xcb384 sub r1, r1, #1 */
/* @0xcb388 cmp r1, #11 */
/* @0xcb38c addls pc, pc, r1, lsl #2 */
/* @0xcb390 b 0xcb584 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x260> */
/* @0xcb394 b 0xcb3c4 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xa0> */
/* @0xcb398 b 0xcb3c4 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xa0> */
/* @0xcb39c b 0xcb41c <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xf8> */
/* @0xcb3a0 b 0xcb434 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x110> */
/* @0xcb3a4 b 0xcb45c <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x138> */
/* @0xcb3a8 b 0xcb488 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x164> */
/* @0xcb3ac b 0xcb584 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x260> */
/* @0xcb3b0 b 0xcb4a0 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x17c> */
/* @0xcb3b4 b 0xcb4b8 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x194> */
/* @0xcb3b8 b 0xcb3c4 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xa0> */
/* @0xcb3bc b 0xcb584 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x260> */
/* @0xcb3c0 b 0xcb4e4 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x1c0> */
/* @0xcb3c4 ldr r2, [r6, #0xc] */
/* @0xcb3c8 mov r12, #1 */
/* @0xcb3cc ldrb r2, [r2, r3] */
/* @0xcb3d0 vmov s15, r2 */
/* @0xcb3d4 vcvt.f64.u32 d7, s15 */
/* @0xcb3d8 vmov r2, r3, d7 */
/* @0xcb3dc stm r7, {r2, r3} */
/* @0xcb3e0 ldr r3, [r6, #0x1c] */
/* @0xcb3e4 ldr r2, [r6, #0x10] */
/* @0xcb3e8 add r3, r12, r3 */
/* @0xcb3ec cmp r3, r2 */
/* @0xcb3f0 ble 0xcb40c <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xe8> */
/* @0xcb3f4 mov r3, #0 */
/* @0xcb3f8 mov r2, r3 */
/* @0xcb3fc movt r3, #0xc008 */
/* @0xcb400 stm r7, {r2, r3} */
/* @0xcb404 ldr r3, [r6, #0x1c] */
/* @0xcb408 add r3, r12, r3 */
/* @0xcb40c mov r0, #0 */
/* @0xcb410 str r3, [r6, #0x1c] */
/* @0xcb414 add sp, sp, #8 */
/* @0xcb418 pop {r4, r5, r6, r7, r8, pc} */
/* @0xcb41c ldr r2, [r6, #0xc] */
/* @0xcb420 ldrh r2, [r2, r3] */
/* @0xcb424 rev16 r2, r2 */
/* @0xcb428 mov r12, #2 */
/* @0xcb42c uxth r2, r2 */
/* @0xcb430 b 0xcb3d0 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xac> */
/* @0xcb434 ldr r2, [r6, #0xc] */
/* @0xcb438 ldrh r2, [r2, r3] */
/* @0xcb43c rev16 r2, r2 */
/* @0xcb440 sxth r2, r2 */
/* @0xcb444 mov r12, #2 */
/* @0xcb448 vmov s15, r2 */
/* @0xcb44c vcvt.f64.s32 d7, s15 */
/* @0xcb450 vmov r2, r3, d7 */
/* @0xcb454 stm r7, {r2, r3} */
/* @0xcb458 b 0xcb3e0 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xbc> */
/* @0xcb45c ldr r2, [r6, #0xc] */
/* @0xcb460 ldr r4, [r2, r3] */
/* @0xcb464 rev r4, r4 */
/* @0xcb468 vmov s15, r4 */
/* @0xcb46c vcvt.f64.u32 d7, s15 */
/* @0xcb470 vmov r4, r5, d7 */
/* @0xcb474 mov r12, #4 */
/* @0xcb478 vmov r2, s14 */
/* @0xcb47c mov r3, r5 */
/* @0xcb480 stm r7, {r2, r3} */
/* @0xcb484 b 0xcb3e0 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xbc> */
/* @0xcb488 ldr r2, [r6, #0xc] */
/* @0xcb48c ldr r4, [r2, r3] */
/* @0xcb490 rev r4, r4 */
/* @0xcb494 vmov s15, r4 */
/* @0xcb498 vcvt.f64.s32 d7, s15 */
/* @0xcb49c b 0xcb470 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x14c> */
/* @0xcb4a0 ldr r2, [r6, #0xc] */
/* @0xcb4a4 ldr r4, [r2, r3] */
/* @0xcb4a8 rev r4, r4 */
/* @0xcb4ac vmov s15, r4 */
/* @0xcb4b0 vcvt.f64.f32 d7, s15 */
/* @0xcb4b4 b 0xcb470 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x14c> */
/* @0xcb4b8 ldr r2, [r6, #0xc] */
/* @0xcb4bc add r1, r2, r3 */
/* @0xcb4c0 ldr r3, [r2, r3] */
/* @0xcb4c4 rev r3, r3 */
/* @0xcb4c8 str r3, [sp] */
/* @0xcb4cc ldr r2, [r1, #0x4] */
/* @0xcb4d0 rev r2, r2 */
/* @0xcb4d4 mov r12, #8 */
/* @0xcb4d8 str r3, [r7] */
/* @0xcb4dc str r2, [r7, #0x4] */
/* @0xcb4e0 b 0xcb3e0 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xbc> */
/* @0xcb4e4 ldr r2, [r6, #0xc] */
/* @0xcb4e8 add r1, r2, r3 */
/* @0xcb4ec ldr r3, [r2, r3] */
/* @0xcb4f0 rev r3, r3 */
/* @0xcb4f4 str r3, [sp] */
/* @0xcb4f8 ldr r3, [r1, #0x4] */
/* @0xcb4fc rev r3, r3 */
/* @0xcb500 str r3, [sp, #0x4] */
/* @0xcb504 ldrd r0, r1, [sp] */
/* @0xcb508 bl 0x319150 <__floatundidf> */
/* @0xcb50c mov r12, #8 */
/* @0xcb510 stm r7, {r0, r1} */
/* @0xcb514 b 0xcb3e0 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xbc> */
/* @0xcb518 ldr r0, [r6, #0xc] */
/* @0xcb51c add r0, r0, r3 */
/* @0xcb520 bl 0xb6538 <strlen@plt> */
/* @0xcb524 mov r3, #1 */
/* @0xcb528 ldr r1, [pc, #0x64] */
/* @0xcb52c mov r2, #158 */
/* @0xcb530 add r1, pc, r1 */
/* @0xcb534 add r5, r0, r3 */
/* @0xcb538 mov r0, r5 */
/* @0xcb53c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xcb540 ldr r3, [r6, #0x1c] */
/* @0xcb544 ldr r1, [r6, #0xc] */
/* @0xcb548 mov r2, r5 */
/* @0xcb54c add r1, r1, r3 */
/* @0xcb550 mov r8, r0 */
/* @0xcb554 bl 0xb65bc <memcpy@plt> */
/* @0xcb558 mov r0, r7 */
/* @0xcb55c mov r1, r8 */
/* @0xcb560 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0xcb564 mov r0, r8 */
/* @0xcb568 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xcb56c ldr r3, [r6, #0x1c] */
/* @0xcb570 mov r0, r4 */
/* @0xcb574 add r5, r3, r5 */
/* @0xcb578 str r5, [r6, #0x1c] */
/* @0xcb57c add sp, sp, #8 */
/* @0xcb580 pop {r4, r5, r6, r7, r8, pc} */
/* @0xcb584 mvn r0, #0 */
/* @0xcb588 b 0xcb414 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xf0> */
/* @0xcb58c mvn r0, #1 */
/* @0xcb590 b 0xcb414 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xf0> */
/* @0xcb594 eoreq r6, r6, r4, lsl #24 */

/* ── FUNC 0xcb598 · Buffer_Network::Peek(int, eBuffer_Type, RValue*) · size=408 · insn=102 */
/* @0xcb598 push {r4, r5, r6, r7, lr} */
/* @0xcb59c subs r6, r1, #0 */
/* @0xcb5a0 mov r4, r3 */
/* @0xcb5a4 sub sp, sp, #12 */
/* @0xcb5a8 mov r3, #0 */
/* @0xcb5ac mov r5, r0 */
/* @0xcb5b0 mov r7, r2 */
/* @0xcb5b4 str r3, [r4, #0xc] */
/* @0xcb5b8 str r3, [r4] */
/* @0xcb5bc str r3, [r4, #0x4] */
/* @0xcb5c0 blt 0xcb5d0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x38> */
/* @0xcb5c4 ldr r3, [r0, #0x10] */
/* @0xcb5c8 cmp r6, r3 */
/* @0xcb5cc blt 0xcb5d8 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x40> */
/* @0xcb5d0 add sp, sp, #12 */
/* @0xcb5d4 pop {r4, r5, r6, r7, pc} */
/* @0xcb5d8 mov r0, r2 */
/* @0xcb5dc bl 0xcd100 <_ZN7IBuffer6SizeOfE12eBuffer_Type> */
/* @0xcb5e0 ldr r3, [r5, #0x18] */
/* @0xcb5e4 cmp r3, #2 */
/* @0xcb5e8 beq 0xcb5fc <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x64> */
/* @0xcb5ec ldr r3, [r5, #0x10] */
/* @0xcb5f0 rsb r0, r0, r3 */
/* @0xcb5f4 cmp r6, r0 */
/* @0xcb5f8 bgt 0xcb5d0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x38> */
/* @0xcb5fc sub r7, r7, #1 */
/* @0xcb600 cmp r7, #11 */
/* @0xcb604 addls pc, pc, r7, lsl #2 */
/* @0xcb608 b 0xcb5d0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x38> */
/* @0xcb60c b 0xcb63c <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0xa4> */
/* @0xcb610 b 0xcb63c <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0xa4> */
/* @0xcb614 b 0xcb658 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0xc0> */
/* @0xcb618 b 0xcb66c <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0xd4> */
/* @0xcb61c b 0xcb690 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0xf8> */
/* @0xcb620 b 0xcb6a0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x108> */
/* @0xcb624 b 0xcb5d0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x38> */
/* @0xcb628 b 0xcb6b4 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x11c> */
/* @0xcb62c b 0xcb6d8 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x140> */
/* @0xcb630 b 0xcb63c <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0xa4> */
/* @0xcb634 b 0xcb5d0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x38> */
/* @0xcb638 b 0xcb700 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x168> */
/* @0xcb63c ldr r3, [r5, #0xc] */
/* @0xcb640 ldrb r2, [r3, r6] */
/* @0xcb644 vmov s15, r2 */
/* @0xcb648 vcvt.f64.u32 d7, s15 */
/* @0xcb64c vmov r2, r3, d7 */
/* @0xcb650 stm r4, {r2, r3} */
/* @0xcb654 b 0xcb5d0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x38> */
/* @0xcb658 ldr r3, [r5, #0xc] */
/* @0xcb65c ldrh r2, [r3, r6] */
/* @0xcb660 rev16 r2, r2 */
/* @0xcb664 uxth r2, r2 */
/* @0xcb668 b 0xcb644 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0xac> */
/* @0xcb66c ldr r3, [r5, #0xc] */
/* @0xcb670 ldrh r2, [r3, r6] */
/* @0xcb674 rev16 r2, r2 */
/* @0xcb678 sxth r2, r2 */
/* @0xcb67c vmov s15, r2 */
/* @0xcb680 vcvt.f64.s32 d7, s15 */
/* @0xcb684 vmov r2, r3, d7 */
/* @0xcb688 stm r4, {r2, r3} */
/* @0xcb68c b 0xcb5d0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x38> */
/* @0xcb690 ldr r3, [r5, #0xc] */
/* @0xcb694 ldr r2, [r3, r6] */
/* @0xcb698 rev r2, r2 */
/* @0xcb69c b 0xcb644 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0xac> */
/* @0xcb6a0 ldr r3, [r5, #0xc] */
/* @0xcb6a4 ldrh r2, [r3, r6] */
/* @0xcb6a8 rev16 r2, r2 */
/* @0xcb6ac uxth r2, r2 */
/* @0xcb6b0 b 0xcb67c <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0xe4> */
/* @0xcb6b4 ldr r3, [r5, #0xc] */
/* @0xcb6b8 ldrh r2, [r3, r6] */
/* @0xcb6bc rev16 r2, r2 */
/* @0xcb6c0 uxth r2, r2 */
/* @0xcb6c4 vmov s15, r2 */
/* @0xcb6c8 vcvt.f64.f32 d7, s15 */
/* @0xcb6cc vmov r2, r3, d7 */
/* @0xcb6d0 stm r4, {r2, r3} */
/* @0xcb6d4 b 0xcb5d0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x38> */
/* @0xcb6d8 ldr r3, [r5, #0xc] */
/* @0xcb6dc add r2, r3, r6 */
/* @0xcb6e0 ldr r3, [r3, r6] */
/* @0xcb6e4 rev r3, r3 */
/* @0xcb6e8 str r3, [sp] */
/* @0xcb6ec ldr r2, [r2, #0x4] */
/* @0xcb6f0 rev r2, r2 */
/* @0xcb6f4 str r3, [r4] */
/* @0xcb6f8 str r2, [r4, #0x4] */
/* @0xcb6fc b 0xcb5d0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x38> */
/* @0xcb700 ldr r3, [r5, #0xc] */
/* @0xcb704 add r2, r3, r6 */
/* @0xcb708 ldr r3, [r3, r6] */
/* @0xcb70c rev r3, r3 */
/* @0xcb710 str r3, [sp] */
/* @0xcb714 ldr r3, [r2, #0x4] */
/* @0xcb718 rev r3, r3 */
/* @0xcb71c str r3, [sp, #0x4] */
/* @0xcb720 ldrd r0, r1, [sp] */
/* @0xcb724 bl 0x319150 <__floatundidf> */
/* @0xcb728 stm r4, {r0, r1} */
/* @0xcb72c b 0xcb5d0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x38> */

/* ── FUNC 0xcb730 · IBuffer::Seek(eBuffer_Seek, int) · size=232 · insn=58 */
/* @0xcb730 cmp r1, #1 */
/* @0xcb734 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xcb738 mov r5, r0 */
/* @0xcb73c beq 0xcb760 <_ZN7IBuffer4SeekE12eBuffer_Seeki+0x30> */
/* @0xcb740 cmp r1, #2 */
/* @0xcb744 beq 0xcb784 <_ZN7IBuffer4SeekE12eBuffer_Seeki+0x54> */
/* @0xcb748 cmp r1, #0 */
/* @0xcb74c streq r1, [r5, #0x24] */
/* @0xcb750 ldrne r0, [r0, #0x1c] */
/* @0xcb754 biceq r0, r2, r2, asr #31 */
/* @0xcb758 streq r0, [r5, #0x1c] */
/* @0xcb75c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xcb760 ldr r3, [r0, #0x18] */
/* @0xcb764 ldr r4, [r0, #0x1c] */
/* @0xcb768 cmp r3, #2 */
/* @0xcb76c addne r4, r2, r4 */
/* @0xcb770 bicne r4, r4, r4, asr #31 */
/* @0xcb774 beq 0xcb7a8 <_ZN7IBuffer4SeekE12eBuffer_Seeki+0x78> */
/* @0xcb778 str r4, [r5, #0x1c] */
/* @0xcb77c mov r0, r4 */
/* @0xcb780 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xcb784 ldr r3, [r0, #0x10] */
/* @0xcb788 bic r0, r2, r2, asr #31 */
/* @0xcb78c mov r2, #0 */
/* @0xcb790 str r2, [r5, #0x24] */
/* @0xcb794 cmp r0, r3 */
/* @0xcb798 movge r0, r3 */
/* @0xcb79c rsb r0, r0, r3 */
/* @0xcb7a0 str r0, [r5, #0x1c] */
/* @0xcb7a4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xcb7a8 adds r4, r2, r4 */
/* @0xcb7ac ldr r6, [r0, #0x10] */
/* @0xcb7b0 bpl 0xcb7e8 <_ZN7IBuffer4SeekE12eBuffer_Seeki+0xb8> */
/* @0xcb7b4 ldr r8, [r0, #0x14] */
/* @0xcb7b8 ldr r7, [r0, #0x24] */
/* @0xcb7bc mov r0, r6 */
/* @0xcb7c0 mov r1, r8 */
/* @0xcb7c4 bl 0x318dec <__aeabi_idivmod> */
/* @0xcb7c8 rsb r9, r1, r8 */
/* @0xcb7cc add r0, r7, r9 */
/* @0xcb7d0 mov r1, r8 */
/* @0xcb7d4 bl 0x318dec <__aeabi_idivmod> */
/* @0xcb7d8 adds r4, r4, r6 */
/* @0xcb7dc mov r7, r1 */
/* @0xcb7e0 bmi 0xcb7cc <_ZN7IBuffer4SeekE12eBuffer_Seeki+0x9c> */
/* @0xcb7e4 str r1, [r5, #0x24] */
/* @0xcb7e8 cmp r4, r6 */
/* @0xcb7ec blt 0xcb778 <_ZN7IBuffer4SeekE12eBuffer_Seeki+0x48> */
/* @0xcb7f0 ldr r7, [r5, #0x14] */
/* @0xcb7f4 ldr r1, [r5, #0x24] */
/* @0xcb7f8 add r0, r1, r6 */
/* @0xcb7fc rsb r4, r6, r4 */
/* @0xcb800 mov r1, r7 */
/* @0xcb804 bl 0x318dec <__aeabi_idivmod> */
/* @0xcb808 cmp r4, r6 */
/* @0xcb80c bge 0xcb7f8 <_ZN7IBuffer4SeekE12eBuffer_Seeki+0xc8> */
/* @0xcb810 str r1, [r5, #0x24] */
/* @0xcb814 b 0xcb778 <_ZN7IBuffer4SeekE12eBuffer_Seeki+0x48> */

/* ── FUNC 0xcb818 · IBuffer::~IBuffer() · size=68 · insn=17 */
/* @0xcb818 ldrb r2, [r0, #0x3c] */
/* @0xcb81c ldr r3, [pc, #0x34] */
/* @0xcb820 cmp r2, #0 */
/* @0xcb824 ldr r3, [pc, r3] */
/* @0xcb828 push {r4, lr} */
/* @0xcb82c add r3, r3, #8 */
/* @0xcb830 mov r4, r0 */
/* @0xcb834 str r3, [r0] */
/* @0xcb838 beq 0xcb844 <_ZN7IBufferD2Ev+0x2c> */
/* @0xcb83c ldr r0, [r0, #0x4] */
/* @0xcb840 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xcb844 mov r3, #0 */
/* @0xcb848 mov r0, r4 */
/* @0xcb84c str r3, [r4, #0x4] */
/* @0xcb850 str r3, [r4, #0xc] */
/* @0xcb854 pop {r4, pc} */
/* @0xcb858 eorseq r2, r2, r8, ror #5 */

/* ── FUNC 0xcb818 · IBuffer::~IBuffer() · alias of the symbol above · insn=0 */

/* ── FUNC 0xcb85c · IBuffer::~IBuffer() · size=28 · insn=7 */
/* @0xcb85c push {r4, lr} */
/* @0xcb860 mov r4, r0 */
/* @0xcb864 bl 0xcb818 <_ZN7IBufferD2Ev> */
/* @0xcb868 mov r0, r4 */
/* @0xcb86c bl 0x27d1d0 <_ZdlPv> */
/* @0xcb870 mov r0, r4 */
/* @0xcb874 pop {r4, pc} */

/* ── FUNC 0xcb878 · IBuffer::Write(eBuffer_Type, RValue*) · size=984 · insn=246 */
/* @0xcb878 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xcb87c mov r4, r0 */
/* @0xcb880 ldr r5, [r4, #0x1c] */
/* @0xcb884 mov r9, r1 */
/* @0xcb888 ldr r0, [r0, #0x24] */
/* @0xcb88c mov r8, r2 */
/* @0xcb890 ldr r7, [r4, #0x14] */
/* @0xcb894 sub sp, sp, #12 */
/* @0xcb898 add r5, r0, r5 */
/* @0xcb89c ldr r6, [r4, #0x10] */
/* @0xcb8a0 sub r1, r7, #1 */
/* @0xcb8a4 rsb r2, r7, #0 */
/* @0xcb8a8 add r5, r5, r1 */
/* @0xcb8ac and r5, r5, r2 */
/* @0xcb8b0 rsb r5, r0, r5 */
/* @0xcb8b4 str r5, [r4, #0x1c] */
/* @0xcb8b8 cmp r5, r6 */
/* @0xcb8bc blt 0xcb8d4 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x5c> */
/* @0xcb8c0 ldr r2, [r4, #0x18] */
/* @0xcb8c4 cmp r2, #2 */
/* @0xcb8c8 beq 0xcb918 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xa0> */
/* @0xcb8cc cmp r2, #1 */
/* @0xcb8d0 bne 0xcbc10 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x398> */
/* @0xcb8d4 sub r1, r9, #1 */
/* @0xcb8d8 cmp r1, #12 */
/* @0xcb8dc addls pc, pc, r1, lsl #2 */
/* @0xcb8e0 b 0xcbc18 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x3a0> */
/* @0xcb8e4 b 0xcbad4 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x25c> */
/* @0xcb8e8 b 0xcbad4 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x25c> */
/* @0xcb8ec b 0xcbb50 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x2d8> */
/* @0xcb8f0 b 0xcb940 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xc8> */
/* @0xcb8f4 b 0xcba80 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x208> */
/* @0xcb8f8 b 0xcba9c <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x224> */
/* @0xcb8fc b 0xcbc18 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x3a0> */
/* @0xcb900 b 0xcbab8 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x240> */
/* @0xcb904 b 0xcbb6c <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x2f4> */
/* @0xcb908 b 0xcbb88 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x310> */
/* @0xcb90c b 0xcbbb4 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x33c> */
/* @0xcb910 b 0xcbbd4 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x35c> */
/* @0xcb914 b 0xcbbf0 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x378> */
/* @0xcb918 add r0, r6, r0 */
/* @0xcb91c mov r1, r7 */
/* @0xcb920 bl 0x318dec <__aeabi_idivmod> */
/* @0xcb924 rsb r5, r6, r5 */
/* @0xcb928 cmp r6, r5 */
/* @0xcb92c mov r0, r1 */
/* @0xcb930 ble 0xcb918 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xa0> */
/* @0xcb934 str r1, [r4, #0x24] */
/* @0xcb938 str r5, [r4, #0x1c] */
/* @0xcb93c b 0xcb8d4 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x5c> */
/* @0xcb940 mov r0, r8 */
/* @0xcb944 mov r1, #0 */
/* @0xcb948 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xcb94c add r5, sp, #8 */
/* @0xcb950 mov r7, #2 */
/* @0xcb954 strh r0, [r5, #-8]! */
/* @0xcb958 ldr r2, [r4, #0x1c] */
/* @0xcb95c ldr r1, [r4, #0x10] */
/* @0xcb960 add r3, r2, r7 */
/* @0xcb964 cmp r3, r1 */
/* @0xcb968 mov r0, r2 */
/* @0xcb96c ble 0xcba3c <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x1c4> */
/* @0xcb970 ldr r0, [r4, #0x18] */
/* @0xcb974 cmp r0, #1 */
/* @0xcb978 beq 0xcba18 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x1a0> */
/* @0xcb97c cmp r0, #2 */
/* @0xcb980 ldreq r3, [r4, #0xc] */
/* @0xcb984 addeq r3, r3, r2 */
/* @0xcb988 bne 0xcbc10 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x398> */
/* @0xcb98c cmp r7, #0 */
/* @0xcb990 movle r7, r2 */
/* @0xcb994 ldrle r6, [r4, #0x10] */
/* @0xcb998 ble 0xcb9f0 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x178> */
/* @0xcb99c add r7, r5, r7 */
/* @0xcb9a0 mov r8, #0 */
/* @0xcb9a4 ldrb r2, [r5], #1 */
/* @0xcb9a8 add r3, r3, #1 */
/* @0xcb9ac strb r2, [r3, #-0x1] */
/* @0xcb9b0 ldr r2, [r4, #0x1c] */
/* @0xcb9b4 ldr r6, [r4, #0x10] */
/* @0xcb9b8 add r2, r2, #1 */
/* @0xcb9bc str r2, [r4, #0x1c] */
/* @0xcb9c0 cmp r2, r6 */
/* @0xcb9c4 blt 0xcb9e4 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x16c> */
/* @0xcb9c8 ldr r0, [r4, #0x24] */
/* @0xcb9cc ldr r1, [r4, #0x14] */
/* @0xcb9d0 add r0, r6, r0 */
/* @0xcb9d4 bl 0x318dec <__aeabi_idivmod> */
/* @0xcb9d8 ldr r3, [r4, #0xc] */
/* @0xcb9dc str r8, [r4, #0x1c] */
/* @0xcb9e0 str r1, [r4, #0x24] */
/* @0xcb9e4 cmp r5, r7 */
/* @0xcb9e8 bne 0xcb9a4 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x12c> */
/* @0xcb9ec ldr r7, [r4, #0x1c] */
/* @0xcb9f0 ldr r2, [r4, #0x20] */
/* @0xcb9f4 mov r3, #0 */
/* @0xcb9f8 cmp r7, r2 */
/* @0xcb9fc movlt r7, r2 */
/* @0xcba00 cmp r7, r6 */
/* @0xcba04 strle r7, [r4, #0x20] */
/* @0xcba08 strgt r6, [r4, #0x20] */
/* @0xcba0c mov r0, r3 */
/* @0xcba10 add sp, sp, #12 */
/* @0xcba14 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xcba18 lsl r1, r1, #1 */
/* @0xcba1c cmp r3, r1 */
/* @0xcba20 bgt 0xcba18 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x1a0> */
/* @0xcba24 ldr r3, [r4] */
/* @0xcba28 mov r0, r4 */
/* @0xcba2c ldr r3, [r3, #0x34] */
/* @0xcba30 blx r3 */
/* @0xcba34 ldr r2, [r4, #0x1c] */
/* @0xcba38 mov r0, r2 */
/* @0xcba3c ldr r1, [r4, #0x18] */
/* @0xcba40 ldr r3, [r4, #0xc] */
/* @0xcba44 cmp r1, #2 */
/* @0xcba48 add r3, r3, r2 */
/* @0xcba4c beq 0xcb98c <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x114> */
/* @0xcba50 cmp r7, #0 */
/* @0xcba54 addgt r1, r3, r7 */
/* @0xcba58 ble 0xcba70 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x1f8> */
/* @0xcba5c ldrb r2, [r5], #1 */
/* @0xcba60 strb r2, [r3], #1 */
/* @0xcba64 cmp r3, r1 */
/* @0xcba68 bne 0xcba5c <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x1e4> */
/* @0xcba6c ldr r0, [r4, #0x1c] */
/* @0xcba70 add r7, r7, r0 */
/* @0xcba74 ldr r6, [r4, #0x10] */
/* @0xcba78 str r7, [r4, #0x1c] */
/* @0xcba7c b 0xcb9f0 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x178> */
/* @0xcba80 mov r0, r8 */
/* @0xcba84 mov r1, #0 */
/* @0xcba88 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0xcba8c add r5, sp, #8 */
/* @0xcba90 mov r7, #4 */
/* @0xcba94 str r0, [r5, #-0x8]! */
/* @0xcba98 b 0xcb958 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xe0> */
/* @0xcba9c mov r0, r8 */
/* @0xcbaa0 mov r1, #0 */
/* @0xcbaa4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xcbaa8 add r5, sp, #8 */
/* @0xcbaac mov r7, #4 */
/* @0xcbab0 str r0, [r5, #-0x8]! */
/* @0xcbab4 b 0xcb958 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xe0> */
/* @0xcbab8 mov r0, r8 */
/* @0xcbabc mov r1, #0 */
/* @0xcbac0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xcbac4 add r5, sp, #8 */
/* @0xcbac8 mov r7, #4 */
/* @0xcbacc str r0, [r5, #-0x8]! */
/* @0xcbad0 b 0xcb958 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xe0> */
/* @0xcbad4 cmp r5, r6 */
/* @0xcbad8 blt 0xcbb08 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x290> */
/* @0xcbadc ldr r3, [r4, #0x18] */
/* @0xcbae0 cmp r3, #2 */
/* @0xcbae4 beq 0xcbc20 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x3a8> */
/* @0xcbae8 cmp r3, #1 */
/* @0xcbaec bne 0xcbc10 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x398> */
/* @0xcbaf0 ldr r3, [r4] */
/* @0xcbaf4 lsl r1, r6, #1 */
/* @0xcbaf8 str r5, [r4, #0x10] */
/* @0xcbafc mov r0, r4 */
/* @0xcbb00 ldr r3, [r3, #0x34] */
/* @0xcbb04 blx r3 */
/* @0xcbb08 ldr r5, [r4, #0x1c] */
/* @0xcbb0c add r3, r5, #1 */
/* @0xcbb10 mov r1, #0 */
/* @0xcbb14 str r3, [r4, #0x1c] */
/* @0xcbb18 mov r0, r8 */
/* @0xcbb1c ldr r6, [r4, #0xc] */
/* @0xcbb20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xcbb24 mov r3, #0 */
/* @0xcbb28 strb r0, [r6, r5] */
/* @0xcbb2c ldr r2, [r4, #0x10] */
/* @0xcbb30 ldr r0, [r4, #0x20] */
/* @0xcbb34 ldr r1, [r4, #0x1c] */
/* @0xcbb38 cmp r1, r0 */
/* @0xcbb3c movlt r1, r0 */
/* @0xcbb40 cmp r1, r2 */
/* @0xcbb44 strle r1, [r4, #0x20] */
/* @0xcbb48 strgt r2, [r4, #0x20] */
/* @0xcbb4c b 0xcba0c <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x194> */
/* @0xcbb50 mov r0, r8 */
/* @0xcbb54 mov r1, #0 */
/* @0xcbb58 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0xcbb5c add r5, sp, #8 */
/* @0xcbb60 mov r7, #2 */
/* @0xcbb64 strh r0, [r5, #-8]! */
/* @0xcbb68 b 0xcb958 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xe0> */
/* @0xcbb6c mov r0, r8 */
/* @0xcbb70 mov r1, #0 */
/* @0xcbb74 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xcbb78 add r5, sp, #8 */
/* @0xcbb7c mov r7, #8 */
/* @0xcbb80 strd r0, r1, [r5, #-8]! */
/* @0xcbb84 b 0xcb958 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xe0> */
/* @0xcbb88 mov r0, r8 */
/* @0xcbb8c mov r1, #0 */
/* @0xcbb90 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0xcbb94 cmp r0, #0 */
/* @0xcbb98 addne r5, sp, #8 */
/* @0xcbb9c addeq r5, sp, #8 */
/* @0xcbba0 movne r7, #1 */
/* @0xcbba4 moveq r7, #1 */
/* @0xcbba8 strbne r7, [r5, #-0x8]! */
/* @0xcbbac strbeq r0, [r5, #-0x8]! */
/* @0xcbbb0 b 0xcb958 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xe0> */
/* @0xcbbb4 mov r0, r8 */
/* @0xcbbb8 mov r1, #0 */
/* @0xcbbbc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xcbbc0 subs r5, r0, #0 */
/* @0xcbbc4 beq 0xcbc18 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x3a0> */
/* @0xcbbc8 bl 0xb6538 <strlen@plt> */
/* @0xcbbcc add r7, r0, #1 */
/* @0xcbbd0 b 0xcb958 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xe0> */
/* @0xcbbd4 mov r0, r8 */
/* @0xcbbd8 mov r1, #0 */
/* @0xcbbdc bl 0xcea30 <_Z10YYGetInt64PK6RValuei> */
/* @0xcbbe0 add r5, sp, #8 */
/* @0xcbbe4 mov r7, #8 */
/* @0xcbbe8 strd r0, r1, [r5, #-8]! */
/* @0xcbbec b 0xcb958 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xe0> */
/* @0xcbbf0 mov r0, r8 */
/* @0xcbbf4 mov r1, #0 */
/* @0xcbbf8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xcbbfc subs r5, r0, #0 */
/* @0xcbc00 beq 0xcbc18 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x3a0> */
/* @0xcbc04 bl 0xb6538 <strlen@plt> */
/* @0xcbc08 mov r7, r0 */
/* @0xcbc0c b 0xcb958 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xe0> */
/* @0xcbc10 mvn r3, #1 */
/* @0xcbc14 b 0xcba0c <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x194> */
/* @0xcbc18 mvn r3, #0 */
/* @0xcbc1c b 0xcba0c <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x194> */
/* @0xcbc20 ldr r5, [r4, #0x1c] */
/* @0xcbc24 cmp r6, r5 */
/* @0xcbc28 bgt 0xcbb0c <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x294> */
/* @0xcbc2c ldr r1, [r4, #0x24] */
/* @0xcbc30 add r0, r6, r1 */
/* @0xcbc34 rsb r5, r6, r5 */
/* @0xcbc38 mov r1, r7 */
/* @0xcbc3c bl 0x318dec <__aeabi_idivmod> */
/* @0xcbc40 cmp r6, r5 */
/* @0xcbc44 ble 0xcbc30 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x3b8> */
/* @0xcbc48 str r1, [r4, #0x24] */
/* @0xcbc4c b 0xcbb0c <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x294> */

/* ── FUNC 0xcbc50 · IBuffer::MD5(RValue*, int, int) · size=356 · insn=89 */
/* @0xcbc50 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xcbc54 mov r5, r3 */
/* @0xcbc58 ldr r7, [pc, #0x148] */
/* @0xcbc5c sub sp, sp, #112 */
/* @0xcbc60 subs r8, r1, #0 */
/* @0xcbc64 mov r6, r0 */
/* @0xcbc68 ldr r7, [pc, r7] */
/* @0xcbc6c mov r4, r2 */
/* @0xcbc70 ldr r3, [r7] */
/* @0xcbc74 str r3, [sp, #0x6c] */
/* @0xcbc78 beq 0xcbd64 <_ZN7IBuffer3MD5EP6RValueii+0x114> */
/* @0xcbc7c ldr r3, [r0, #0x10] */
/* @0xcbc80 cmp r3, #0 */
/* @0xcbc84 beq 0xcbd64 <_ZN7IBuffer3MD5EP6RValueii+0x114> */
/* @0xcbc88 cmp r5, #0 */
/* @0xcbc8c ldr r2, [r0, #0x18] */
/* @0xcbc90 movlt r5, r3 */
/* @0xcbc94 cmp r2, #2 */
/* @0xcbc98 beq 0xcbd7c <_ZN7IBuffer3MD5EP6RValueii+0x12c> */
/* @0xcbc9c bic r4, r4, r4, asr #31 */
/* @0xcbca0 cmp r4, r3 */
/* @0xcbca4 subge r4, r3, #1 */
/* @0xcbca8 add r2, r4, r5 */
/* @0xcbcac cmp r3, r2 */
/* @0xcbcb0 rsblt r5, r4, r3 */
/* @0xcbcb4 add r9, sp, #4 */
/* @0xcbcb8 mov r0, r9 */
/* @0xcbcbc bl 0x2140d8 <_Z7MD5InitP7MD5_CTX> */
/* @0xcbcc0 cmp r5, #0 */
/* @0xcbcc4 bgt 0xcbcd0 <_ZN7IBuffer3MD5EP6RValueii+0x80> */
/* @0xcbcc8 b 0xcbcfc <_ZN7IBuffer3MD5EP6RValueii+0xac> */
/* @0xcbccc mov r4, #0 */
/* @0xcbcd0 ldr r2, [r6, #0x10] */
/* @0xcbcd4 mov r0, r9 */
/* @0xcbcd8 ldr r1, [r6, #0xc] */
/* @0xcbcdc rsb r2, r4, r2 */
/* @0xcbce0 cmp r2, r5 */
/* @0xcbce4 movge r2, r5 */
/* @0xcbce8 add r1, r1, r4 */
/* @0xcbcec rsb r5, r2, r5 */
/* @0xcbcf0 bl 0x214118 <_Z9MD5UpdateP7MD5_CTXPhj> */
/* @0xcbcf4 cmp r5, #0 */
/* @0xcbcf8 bgt 0xcbccc <_ZN7IBuffer3MD5EP6RValueii+0x7c> */
/* @0xcbcfc mov r0, r9 */
/* @0xcbd00 ldr r6, [pc, #0xa4] */
/* @0xcbd04 bl 0x2141d0 <_Z8MD5FinalP7MD5_CTX> */
/* @0xcbd08 ldr r1, [pc, #0xa0] */
/* @0xcbd0c mov r0, #33 */
/* @0xcbd10 movw r2, #0x4f5 */
/* @0xcbd14 add r1, pc, r1 */
/* @0xcbd18 mov r3, #1 */
/* @0xcbd1c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xcbd20 add r4, sp, #91 */
/* @0xcbd24 add r9, sp, #107 */
/* @0xcbd28 add r6, pc, r6 */
/* @0xcbd2c mov r10, r0 */
/* @0xcbd30 mov r5, r0 */
/* @0xcbd34 ldrb r2, [r4, #0x1]! */
/* @0xcbd38 mov r0, r5 */
/* @0xcbd3c mov r1, r6 */
/* @0xcbd40 add r5, r5, #2 */
/* @0xcbd44 bl 0xb6550 <sprintf@plt> */
/* @0xcbd48 cmp r4, r9 */
/* @0xcbd4c bne 0xcbd34 <_ZN7IBuffer3MD5EP6RValueii+0xe4> */
/* @0xcbd50 mov r0, r8 */
/* @0xcbd54 mov r1, r10 */
/* @0xcbd58 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0xcbd5c mov r0, r10 */
/* @0xcbd60 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xcbd64 ldr r2, [sp, #0x6c] */
/* @0xcbd68 ldr r3, [r7] */
/* @0xcbd6c cmp r2, r3 */
/* @0xcbd70 bne 0xcbda4 <_ZN7IBuffer3MD5EP6RValueii+0x154> */
/* @0xcbd74 add sp, sp, #112 */
/* @0xcbd78 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xcbd7c cmp r4, #0 */
/* @0xcbd80 bge 0xcbd8c <_ZN7IBuffer3MD5EP6RValueii+0x13c> */
/* @0xcbd84 adds r4, r4, r3 */
/* @0xcbd88 bmi 0xcbd84 <_ZN7IBuffer3MD5EP6RValueii+0x134> */
/* @0xcbd8c cmp r3, r4 */
/* @0xcbd90 bgt 0xcbcb4 <_ZN7IBuffer3MD5EP6RValueii+0x64> */
/* @0xcbd94 rsb r4, r3, r4 */
/* @0xcbd98 cmp r3, r4 */
/* @0xcbd9c ble 0xcbd94 <_ZN7IBuffer3MD5EP6RValueii+0x144> */
/* @0xcbda0 b 0xcbcb4 <_ZN7IBuffer3MD5EP6RValueii+0x64> */
/* @0xcbda4 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xcbda8 eorseq r1, r2, r8, ror #25 */
/* @0xcbdac eoreq r6, r6, r12, ror r4 */
/* @0xcbdb0 eoreq r6, r6, r12, asr r4 */

/* ── FUNC 0xcbdb4 · IBuffer::SHA1(RValue*, int, int) · size=360 · insn=90 */
/* @0xcbdb4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xcbdb8 mov r5, r3 */
/* @0xcbdbc ldr r8, [pc, #0x14c] */
/* @0xcbdc0 sub sp, sp, #112 */
/* @0xcbdc4 subs r9, r1, #0 */
/* @0xcbdc8 mov r6, r0 */
/* @0xcbdcc ldr r8, [pc, r8] */
/* @0xcbdd0 mov r4, r2 */
/* @0xcbdd4 ldr r3, [r8] */
/* @0xcbdd8 str r3, [sp, #0x6c] */
/* @0xcbddc beq 0xcbecc <_ZN7IBuffer4SHA1EP6RValueii+0x118> */
/* @0xcbde0 cmp r5, #0 */
/* @0xcbde4 ldr r2, [r0, #0x18] */
/* @0xcbde8 ldrlt r5, [r0, #0x10] */
/* @0xcbdec ldrge r3, [r0, #0x10] */
/* @0xcbdf0 movlt r3, r5 */
/* @0xcbdf4 cmp r2, #2 */
/* @0xcbdf8 beq 0xcbee4 <_ZN7IBuffer4SHA1EP6RValueii+0x130> */
/* @0xcbdfc bic r4, r4, r4, asr #31 */
/* @0xcbe00 cmp r4, r3 */
/* @0xcbe04 subge r4, r3, #1 */
/* @0xcbe08 add r2, r4, r5 */
/* @0xcbe0c cmp r2, r3 */
/* @0xcbe10 rsbgt r5, r4, r3 */
/* @0xcbe14 add r7, sp, #4 */
/* @0xcbe18 mov r3, #1 */
/* @0xcbe1c str r3, [r9, #0xc] */
/* @0xcbe20 mov r0, r7 */
/* @0xcbe24 bl 0x214294 <_Z9SHA1ResetP11SHA1Context> */
/* @0xcbe28 cmp r5, #0 */
/* @0xcbe2c bgt 0xcbe38 <_ZN7IBuffer4SHA1EP6RValueii+0x84> */
/* @0xcbe30 b 0xcbe64 <_ZN7IBuffer4SHA1EP6RValueii+0xb0> */
/* @0xcbe34 mov r4, #0 */
/* @0xcbe38 ldr r2, [r6, #0x10] */
/* @0xcbe3c mov r0, r7 */
/* @0xcbe40 ldr r1, [r6, #0xc] */
/* @0xcbe44 rsb r2, r4, r2 */
/* @0xcbe48 cmp r2, r5 */
/* @0xcbe4c movge r2, r5 */
/* @0xcbe50 add r1, r1, r4 */
/* @0xcbe54 rsb r5, r2, r5 */
/* @0xcbe58 bl 0x214538 <_Z9SHA1InputP11SHA1ContextPKhj> */
/* @0xcbe5c cmp r5, #0 */
/* @0xcbe60 bgt 0xcbe34 <_ZN7IBuffer4SHA1EP6RValueii+0x80> */
/* @0xcbe64 mov r0, r7 */
/* @0xcbe68 ldr r6, [pc, #0xa4] */
/* @0xcbe6c bl 0x2146e4 <_Z10SHA1ResultP11SHA1Context> */
/* @0xcbe70 ldr r1, [pc, #0xa0] */
/* @0xcbe74 mov r0, #45 */
/* @0xcbe78 movw r2, #0x52a */
/* @0xcbe7c add r1, pc, r1 */
/* @0xcbe80 mov r3, #1 */
/* @0xcbe84 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xcbe88 add r7, sp, #20 */
/* @0xcbe8c add r6, pc, r6 */
/* @0xcbe90 mov r4, sp */
/* @0xcbe94 mov r10, r0 */
/* @0xcbe98 mov r5, r0 */
/* @0xcbe9c ldr r2, [r4, #0x4]! */
/* @0xcbea0 mov r0, r5 */
/* @0xcbea4 mov r1, r6 */
/* @0xcbea8 add r5, r5, #8 */
/* @0xcbeac bl 0xb6550 <sprintf@plt> */
/* @0xcbeb0 cmp r4, r7 */
/* @0xcbeb4 bne 0xcbe9c <_ZN7IBuffer4SHA1EP6RValueii+0xe8> */
/* @0xcbeb8 mov r0, r9 */
/* @0xcbebc mov r1, r10 */
/* @0xcbec0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0xcbec4 mov r0, r10 */
/* @0xcbec8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xcbecc ldr r2, [sp, #0x6c] */
/* @0xcbed0 ldr r3, [r8] */
/* @0xcbed4 cmp r2, r3 */
/* @0xcbed8 bne 0xcbf0c <_ZN7IBuffer4SHA1EP6RValueii+0x158> */
/* @0xcbedc add sp, sp, #112 */
/* @0xcbee0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xcbee4 cmp r4, #0 */
/* @0xcbee8 bge 0xcbef4 <_ZN7IBuffer4SHA1EP6RValueii+0x140> */
/* @0xcbeec adds r4, r4, r3 */
/* @0xcbef0 bmi 0xcbeec <_ZN7IBuffer4SHA1EP6RValueii+0x138> */
/* @0xcbef4 cmp r4, r3 */
/* @0xcbef8 blt 0xcbe14 <_ZN7IBuffer4SHA1EP6RValueii+0x60> */
/* @0xcbefc rsb r4, r3, r4 */
/* @0xcbf00 cmp r4, r3 */
/* @0xcbf04 bge 0xcbefc <_ZN7IBuffer4SHA1EP6RValueii+0x148> */
/* @0xcbf08 b 0xcbe14 <_ZN7IBuffer4SHA1EP6RValueii+0x60> */
/* @0xcbf0c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xcbf10 eorseq r1, r2, r4, lsl #23 */
/* @0xcbf14 eoreq r6, r6, r0, lsr #6 */
/* @0xcbf18 .word 0x002662f4 */

/* ── FUNC 0xcbf1c · IBuffer::Resize(int) · size=216 · insn=54 */
/* @0xcbf1c push {r3, r4, r5, r6, r7, lr} */
/* @0xcbf20 mov r4, r0 */
/* @0xcbf24 ldr r0, [r0, #0x14] */
/* @0xcbf28 movw r2, #0x53a */
/* @0xcbf2c ldr r5, [r4, #0x10] */
/* @0xcbf30 mov r3, #0 */
/* @0xcbf34 add r0, r1, r0 */
/* @0xcbf38 str r1, [r4, #0x10] */
/* @0xcbf3c ldr r1, [pc, #0xac] */
/* @0xcbf40 str r0, [r4, #0x8] */
/* @0xcbf44 add r1, pc, r1 */
/* @0xcbf48 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xcbf4c ldr r3, [r4, #0x14] */
/* @0xcbf50 ldr r2, [r4, #0x10] */
/* @0xcbf54 sub r6, r3, #1 */
/* @0xcbf58 rsb r3, r3, #0 */
/* @0xcbf5c cmp r5, r2 */
/* @0xcbf60 movge r5, r2 */
/* @0xcbf64 cmp r5, #0 */
/* @0xcbf68 add r6, r0, r6 */
/* @0xcbf6c mov r7, r0 */
/* @0xcbf70 and r6, r6, r3 */
/* @0xcbf74 mov r0, r6 */
/* @0xcbf78 ble 0xcbfe4 <_ZN7IBuffer6ResizeEi+0xc8> */
/* @0xcbf7c ldr r1, [r4, #0xc] */
/* @0xcbf80 mov r2, r5 */
/* @0xcbf84 bl 0xb65bc <memcpy@plt> */
/* @0xcbf88 ldr r2, [r4, #0x10] */
/* @0xcbf8c add r0, r6, r5 */
/* @0xcbf90 mov r1, #0 */
/* @0xcbf94 rsb r2, r5, r2 */
/* @0xcbf98 bl 0xb65b0 <memset@plt> */
/* @0xcbf9c ldr r0, [r4, #0x4] */
/* @0xcbfa0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xcbfa4 ldr r3, [r4, #0x1c] */
/* @0xcbfa8 ldr r2, [r4, #0x10] */
/* @0xcbfac str r7, [r4, #0x4] */
/* @0xcbfb0 cmp r3, r2 */
/* @0xcbfb4 str r6, [r4, #0xc] */
/* @0xcbfb8 movge r1, #0 */
/* @0xcbfbc movge r3, r1 */
/* @0xcbfc0 strge r1, [r4, #0x1c] */
/* @0xcbfc4 strge r1, [r4, #0x24] */
/* @0xcbfc8 ldr r1, [r4, #0x20] */
/* @0xcbfcc cmp r3, r1 */
/* @0xcbfd0 movlt r3, r1 */
/* @0xcbfd4 cmp r3, r2 */
/* @0xcbfd8 strle r3, [r4, #0x20] */
/* @0xcbfdc strgt r2, [r4, #0x20] */
/* @0xcbfe0 pop {r3, r4, r5, r6, r7, pc} */
/* @0xcbfe4 mov r1, #0 */
/* @0xcbfe8 bl 0xb65b0 <memset@plt> */
/* @0xcbfec b 0xcbf9c <_ZN7IBuffer6ResizeEi+0x80> */
/* @0xcbff0 eoreq r6, r6, r12, lsr #4 */

/* ── FUNC 0xcbff4 · IBuffer::Poke(int, eBuffer_Type, RValue*) · size=652 · insn=163 */
/* @0xcbff4 push {r4, r5, r6, r7, lr} */
/* @0xcbff8 subs r4, r1, #0 */
/* @0xcbffc sub sp, sp, #12 */
/* @0xcc000 mov r6, r0 */
/* @0xcc004 blt 0xcc0a0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xac> */
/* @0xcc008 sub r2, r2, #1 */
/* @0xcc00c cmp r2, #12 */
/* @0xcc010 addls pc, pc, r2, lsl #2 */
/* @0xcc014 b 0xcc0a0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xac> */
/* @0xcc018 b 0xcc04c <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x58> */
/* @0xcc01c b 0xcc04c <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x58> */
/* @0xcc020 b 0xcc154 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x160> */
/* @0xcc024 b 0xcc170 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x17c> */
/* @0xcc028 b 0xcc18c <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x198> */
/* @0xcc02c b 0xcc1a8 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x1b4> */
/* @0xcc030 b 0xcc0a0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xac> */
/* @0xcc034 b 0xcc1c4 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x1d0> */
/* @0xcc038 b 0xcc1e0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x1ec> */
/* @0xcc03c b 0xcc1fc <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x208> */
/* @0xcc040 b 0xcc228 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x234> */
/* @0xcc044 b 0xcc0a0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xac> */
/* @0xcc048 b 0xcc0a8 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xb4> */
/* @0xcc04c ldr r2, [r0, #0x18] */
/* @0xcc050 cmp r2, #2 */
/* @0xcc054 ldr r2, [r0, #0x10] */
/* @0xcc058 beq 0xcc148 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x154> */
/* @0xcc05c cmp r4, r2 */
/* @0xcc060 bge 0xcc0a0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xac> */
/* @0xcc064 mov r0, r3 */
/* @0xcc068 mov r1, #0 */
/* @0xcc06c ldr r5, [r6, #0xc] */
/* @0xcc070 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xcc074 add r3, r4, #1 */
/* @0xcc078 cmn r3, #1 */
/* @0xcc07c strb r0, [r5, r4] */
/* @0xcc080 ldr r2, [r6, #0x10] */
/* @0xcc084 ldreq r3, [r6, #0x1c] */
/* @0xcc088 ldr r1, [r6, #0x20] */
/* @0xcc08c cmp r3, r1 */
/* @0xcc090 movlt r3, r1 */
/* @0xcc094 cmp r3, r2 */
/* @0xcc098 strle r3, [r6, #0x20] */
/* @0xcc09c strgt r2, [r6, #0x20] */
/* @0xcc0a0 add sp, sp, #12 */
/* @0xcc0a4 pop {r4, r5, r6, r7, pc} */
/* @0xcc0a8 mov r0, r3 */
/* @0xcc0ac mov r1, #0 */
/* @0xcc0b0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xcc0b4 mov r5, r0 */
/* @0xcc0b8 bl 0xb6538 <strlen@plt> */
/* @0xcc0bc mov r12, r0 */
/* @0xcc0c0 ldr r1, [r6, #0x18] */
/* @0xcc0c4 ldr r2, [r6, #0x10] */
/* @0xcc0c8 cmp r1, #2 */
/* @0xcc0cc beq 0xcc138 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x144> */
/* @0xcc0d0 rsb r3, r12, r2 */
/* @0xcc0d4 cmp r4, r3 */
/* @0xcc0d8 bgt 0xcc0a0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xac> */
/* @0xcc0dc add r0, r4, r12 */
/* @0xcc0e0 ldr r7, [r6, #0x20] */
/* @0xcc0e4 cmn r0, #1 */
/* @0xcc0e8 ldr r3, [r6, #0xc] */
/* @0xcc0ec ldreq r0, [r6, #0x1c] */
/* @0xcc0f0 add r3, r3, r4 */
/* @0xcc0f4 cmp r0, r7 */
/* @0xcc0f8 movlt r0, r7 */
/* @0xcc0fc cmp r0, r2 */
/* @0xcc100 strle r0, [r6, #0x20] */
/* @0xcc104 strgt r2, [r6, #0x20] */
/* @0xcc108 cmp r1, #2 */
/* @0xcc10c beq 0xcc244 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x250> */
/* @0xcc110 cmp r12, #0 */
/* @0xcc114 addgt r1, r3, r12 */
/* @0xcc118 ble 0xcc0a0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xac> */
/* @0xcc11c ldrb r2, [r5], #1 */
/* @0xcc120 strb r2, [r3], #1 */
/* @0xcc124 cmp r3, r1 */
/* @0xcc128 bne 0xcc11c <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x128> */
/* @0xcc12c add sp, sp, #12 */
/* @0xcc130 pop {r4, r5, r6, r7, pc} */
/* @0xcc134 rsb r4, r2, r4 */
/* @0xcc138 cmp r4, r2 */
/* @0xcc13c bge 0xcc134 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x140> */
/* @0xcc140 b 0xcc0dc <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xe8> */
/* @0xcc144 rsb r4, r2, r4 */
/* @0xcc148 cmp r4, r2 */
/* @0xcc14c bge 0xcc144 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x150> */
/* @0xcc150 b 0xcc064 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x70> */
/* @0xcc154 mov r0, r3 */
/* @0xcc158 mov r1, #0 */
/* @0xcc15c bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0xcc160 add r5, sp, #8 */
/* @0xcc164 mov r12, #2 */
/* @0xcc168 strh r0, [r5, #-8]! */
/* @0xcc16c b 0xcc0c0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xcc> */
/* @0xcc170 mov r0, r3 */
/* @0xcc174 mov r1, #0 */
/* @0xcc178 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xcc17c add r5, sp, #8 */
/* @0xcc180 mov r12, #2 */
/* @0xcc184 strh r0, [r5, #-8]! */
/* @0xcc188 b 0xcc0c0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xcc> */
/* @0xcc18c mov r0, r3 */
/* @0xcc190 mov r1, #0 */
/* @0xcc194 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0xcc198 add r5, sp, #8 */
/* @0xcc19c mov r12, #4 */
/* @0xcc1a0 str r0, [r5, #-0x8]! */
/* @0xcc1a4 b 0xcc0c0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xcc> */
/* @0xcc1a8 mov r0, r3 */
/* @0xcc1ac mov r1, #0 */
/* @0xcc1b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xcc1b4 add r5, sp, #8 */
/* @0xcc1b8 mov r12, #4 */
/* @0xcc1bc str r0, [r5, #-0x8]! */
/* @0xcc1c0 b 0xcc0c0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xcc> */
/* @0xcc1c4 mov r0, r3 */
/* @0xcc1c8 mov r1, #0 */
/* @0xcc1cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xcc1d0 add r5, sp, #8 */
/* @0xcc1d4 mov r12, #4 */
/* @0xcc1d8 str r0, [r5, #-0x8]! */
/* @0xcc1dc b 0xcc0c0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xcc> */
/* @0xcc1e0 mov r0, r3 */
/* @0xcc1e4 mov r1, #0 */
/* @0xcc1e8 bl 0xcea30 <_Z10YYGetInt64PK6RValuei> */
/* @0xcc1ec add r5, sp, #8 */
/* @0xcc1f0 mov r12, #8 */
/* @0xcc1f4 strd r0, r1, [r5, #-8]! */
/* @0xcc1f8 b 0xcc0c0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xcc> */
/* @0xcc1fc mov r0, r3 */
/* @0xcc200 mov r1, #0 */
/* @0xcc204 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0xcc208 cmp r0, #0 */
/* @0xcc20c addne r5, sp, #8 */
/* @0xcc210 addeq r5, sp, #8 */
/* @0xcc214 movne r12, #1 */
/* @0xcc218 moveq r12, #1 */
/* @0xcc21c strbne r12, [r5, #-0x8]! */
/* @0xcc220 strbeq r0, [r5, #-0x8]! */
/* @0xcc224 b 0xcc0c0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xcc> */
/* @0xcc228 mov r0, r3 */
/* @0xcc22c mov r1, #0 */
/* @0xcc230 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xcc234 mov r5, r0 */
/* @0xcc238 bl 0xb6538 <strlen@plt> */
/* @0xcc23c add r12, r0, #1 */
/* @0xcc240 b 0xcc0c0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xcc> */
/* @0xcc244 cmp r12, #0 */
/* @0xcc248 ble 0xcc0a0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xac> */
/* @0xcc24c add r12, r5, r12 */
/* @0xcc250 ldrb r2, [r5], #1 */
/* @0xcc254 add r4, r4, #1 */
/* @0xcc258 add r3, r3, #1 */
/* @0xcc25c strb r2, [r3, #-0x1] */
/* @0xcc260 ldr r2, [r6, #0x10] */
/* @0xcc264 cmp r4, r2 */
/* @0xcc268 ldrge r3, [r6, #0xc] */
/* @0xcc26c movge r4, #0 */
/* @0xcc270 cmp r5, r12 */
/* @0xcc274 bne 0xcc250 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x25c> */
/* @0xcc278 add sp, sp, #12 */
/* @0xcc27c pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0xcc280 · IBuffer::Fill(int, int, eBuffer_Type, RValue*, int, bool) · size=1192 · insn=298 */
/* @0xcc280 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xcc284 sub sp, sp, #36 */
/* @0xcc288 mov r6, r1 */
/* @0xcc28c ldr r1, [r0, #0x10] */
/* @0xcc290 str r2, [sp, #0x4] */
/* @0xcc294 mov r10, r0 */
/* @0xcc298 ldrb r2, [sp, #0x50] */
/* @0xcc29c cmp r1, #0 */
/* @0xcc2a0 str r2, [sp, #0xc] */
/* @0xcc2a4 beq 0xcc444 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1c4> */
/* @0xcc2a8 sub r3, r3, #1 */
/* @0xcc2ac cmp r3, #12 */
/* @0xcc2b0 addls pc, pc, r3, lsl #2 */
/* @0xcc2b4 b 0xcc444 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1c4> */
/* @0xcc2b8 b 0xcc44c <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1cc> */
/* @0xcc2bc b 0xcc44c <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1cc> */
/* @0xcc2c0 b 0xcc46c <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1ec> */
/* @0xcc2c4 b 0xcc46c <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1ec> */
/* @0xcc2c8 b 0xcc2ec <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x6c> */
/* @0xcc2cc b 0xcc2ec <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x6c> */
/* @0xcc2d0 b 0xcc444 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1c4> */
/* @0xcc2d4 b 0xcc4d8 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x258> */
/* @0xcc2d8 b 0xcc4f8 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x278> */
/* @0xcc2dc b 0xcc48c <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x20c> */
/* @0xcc2e0 b 0xcc518 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x298> */
/* @0xcc2e4 b 0xcc444 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1c4> */
/* @0xcc2e8 b 0xcc4bc <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x23c> */
/* @0xcc2ec ldr r0, [sp, #0x48] */
/* @0xcc2f0 mov r1, #0 */
/* @0xcc2f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xcc2f8 add r3, sp, #32 */
/* @0xcc2fc mov r9, #4 */
/* @0xcc300 str r0, [r3, #-0x8]! */
/* @0xcc304 str r3, [sp, #0x8] */
/* @0xcc308 ldr r2, [sp, #0x4] */
/* @0xcc30c cmp r2, #0 */
/* @0xcc310 ldrlt r3, [r10, #0x10] */
/* @0xcc314 strlt r3, [sp, #0x4] */
/* @0xcc318 ldr r3, [r10, #0x18] */
/* @0xcc31c cmp r3, #2 */
/* @0xcc320 beq 0xcc6cc <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x44c> */
/* @0xcc324 cmp r6, #0 */
/* @0xcc328 blt 0xcc444 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1c4> */
/* @0xcc32c ldr r4, [r10, #0x10] */
/* @0xcc330 cmp r6, r4 */
/* @0xcc334 bge 0xcc444 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1c4> */
/* @0xcc338 ldr r3, [sp, #0x4] */
/* @0xcc33c add r3, r6, r3 */
/* @0xcc340 str r3, [sp, #0x10] */
/* @0xcc344 cmp r4, r3 */
/* @0xcc348 strlt r4, [sp, #0x10] */
/* @0xcc34c rsblt r2, r6, r4 */
/* @0xcc350 strlt r2, [sp, #0x4] */
/* @0xcc354 ldr r3, [sp, #0x4c] */
/* @0xcc358 cmp r3, #0 */
/* @0xcc35c ble 0xcc704 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x484> */
/* @0xcc360 cmp r9, r3 */
/* @0xcc364 movge r9, r3 */
/* @0xcc368 mov r3, #0 */
/* @0xcc36c str r3, [sp, #0x14] */
/* @0xcc370 ldr r2, [sp, #0x4] */
/* @0xcc374 cmp r2, r9 */
/* @0xcc378 movlt r3, #0 */
/* @0xcc37c movge r3, #1 */
/* @0xcc380 ldr r2, [sp, #0x4] */
/* @0xcc384 cmp r2, #0 */
/* @0xcc388 ble 0xcc444 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1c4> */
/* @0xcc38c ldr r2, [sp, #0x8] */
/* @0xcc390 mov r11, r6 */
/* @0xcc394 str r6, [sp] */
/* @0xcc398 mov r8, #0 */
/* @0xcc39c add r7, r2, r9 */
/* @0xcc3a0 mov r6, r3 */
/* @0xcc3a4 mov r0, r11 */
/* @0xcc3a8 mov r1, r4 */
/* @0xcc3ac bl 0x318dec <__aeabi_idivmod> */
/* @0xcc3b0 cmp r6, #0 */
/* @0xcc3b4 mov r5, r1 */
/* @0xcc3b8 beq 0xcc534 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x2b4> */
/* @0xcc3bc add r2, r9, r1 */
/* @0xcc3c0 ldr r3, [r10, #0xc] */
/* @0xcc3c4 cmp r4, r2 */
/* @0xcc3c8 add r3, r3, r1 */
/* @0xcc3cc bge 0xcc644 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x3c4> */
/* @0xcc3d0 cmp r9, #0 */
/* @0xcc3d4 ldrgt r2, [sp, #0x8] */
/* @0xcc3d8 ble 0xcc42c <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1ac> */
/* @0xcc3dc ldrb r1, [r2], #1 */
/* @0xcc3e0 add r5, r5, #1 */
/* @0xcc3e4 add r3, r3, #1 */
/* @0xcc3e8 strb r1, [r3, #-0x1] */
/* @0xcc3ec ldr r4, [r10, #0x10] */
/* @0xcc3f0 cmp r5, r4 */
/* @0xcc3f4 blt 0xcc424 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1a4> */
/* @0xcc3f8 cmn r4, #1 */
/* @0xcc3fc ldr r3, [r10, #0xc] */
/* @0xcc400 mov r1, r4 */
/* @0xcc404 ldr r0, [r10, #0x20] */
/* @0xcc408 ldreq r1, [r10, #0x1c] */
/* @0xcc40c mov r5, #0 */
/* @0xcc410 cmp r1, r0 */
/* @0xcc414 movlt r1, r0 */
/* @0xcc418 cmp r1, r4 */
/* @0xcc41c strle r1, [r10, #0x20] */
/* @0xcc420 strgt r4, [r10, #0x20] */
/* @0xcc424 cmp r2, r7 */
/* @0xcc428 bne 0xcc3dc <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x15c> */
/* @0xcc42c add r11, r11, r9 */
/* @0xcc430 add r8, r8, r9 */
/* @0xcc434 mov r6, #0 */
/* @0xcc438 ldr r3, [sp, #0x4] */
/* @0xcc43c cmp r3, r8 */
/* @0xcc440 bgt 0xcc3a4 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x124> */
/* @0xcc444 add sp, sp, #36 */
/* @0xcc448 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xcc44c ldr r0, [sp, #0x48] */
/* @0xcc450 mov r1, #0 */
/* @0xcc454 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xcc458 add r3, sp, #32 */
/* @0xcc45c mov r9, #1 */
/* @0xcc460 strb r0, [r3, #-0x8]! */
/* @0xcc464 str r3, [sp, #0x8] */
/* @0xcc468 b 0xcc308 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x88> */
/* @0xcc46c ldr r0, [sp, #0x48] */
/* @0xcc470 mov r1, #0 */
/* @0xcc474 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xcc478 add r3, sp, #32 */
/* @0xcc47c mov r9, #2 */
/* @0xcc480 strh r0, [r3, #-8]! */
/* @0xcc484 str r3, [sp, #0x8] */
/* @0xcc488 b 0xcc308 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x88> */
/* @0xcc48c ldr r0, [sp, #0x48] */
/* @0xcc490 mov r1, #0 */
/* @0xcc494 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0xcc498 cmp r0, #0 */
/* @0xcc49c addne r3, sp, #32 */
/* @0xcc4a0 addeq r3, sp, #32 */
/* @0xcc4a4 movne r9, #1 */
/* @0xcc4a8 moveq r9, #1 */
/* @0xcc4ac strbne r9, [r3, #-0x8]! */
/* @0xcc4b0 strbeq r0, [r3, #-0x8]! */
/* @0xcc4b4 str r3, [sp, #0x8] */
/* @0xcc4b8 b 0xcc308 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x88> */
/* @0xcc4bc mov r1, #0 */
/* @0xcc4c0 ldr r0, [sp, #0x48] */
/* @0xcc4c4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xcc4c8 str r0, [sp, #0x8] */
/* @0xcc4cc bl 0xb6538 <strlen@plt> */
/* @0xcc4d0 mov r9, r0 */
/* @0xcc4d4 b 0xcc308 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x88> */
/* @0xcc4d8 ldr r0, [sp, #0x48] */
/* @0xcc4dc mov r1, #0 */
/* @0xcc4e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xcc4e4 add r3, sp, #32 */
/* @0xcc4e8 mov r9, #4 */
/* @0xcc4ec str r0, [r3, #-0x8]! */
/* @0xcc4f0 str r3, [sp, #0x8] */
/* @0xcc4f4 b 0xcc308 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x88> */
/* @0xcc4f8 ldr r0, [sp, #0x48] */
/* @0xcc4fc mov r1, #0 */
/* @0xcc500 bl 0xcea30 <_Z10YYGetInt64PK6RValuei> */
/* @0xcc504 add r3, sp, #32 */
/* @0xcc508 mov r9, #8 */
/* @0xcc50c strd r0, r1, [r3, #-8]! */
/* @0xcc510 str r3, [sp, #0x8] */
/* @0xcc514 b 0xcc308 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x88> */
/* @0xcc518 mov r1, #0 */
/* @0xcc51c ldr r0, [sp, #0x48] */
/* @0xcc520 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xcc524 str r0, [sp, #0x8] */
/* @0xcc528 bl 0xb6538 <strlen@plt> */
/* @0xcc52c add r9, r0, #1 */
/* @0xcc530 b 0xcc308 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x88> */
/* @0xcc534 ldr r3, [sp, #0x14] */
/* @0xcc538 cmp r3, #0 */
/* @0xcc53c ldrne r3, [r10, #0x14] */
/* @0xcc540 ldreq r3, [sp, #0x4c] */
/* @0xcc544 subne r2, r3, #1 */
/* @0xcc548 ldreq r2, [sp] */
/* @0xcc54c rsbne r3, r3, #0 */
/* @0xcc550 addne r6, r11, r2 */
/* @0xcc554 andne r6, r6, r3 */
/* @0xcc558 addeq r6, r3, r2 */
/* @0xcc55c ldr r3, [sp, #0x10] */
/* @0xcc560 cmp r3, r6 */
/* @0xcc564 movge r3, r6 */
/* @0xcc568 str r3, [sp] */
/* @0xcc56c ldr r3, [sp, #0xc] */
/* @0xcc570 cmp r3, #0 */
/* @0xcc574 ldr r3, [sp] */
/* @0xcc578 rsb r11, r11, r3 */
/* @0xcc57c beq 0xcc61c <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x39c> */
/* @0xcc580 add r6, r1, r11 */
/* @0xcc584 cmp r4, r6 */
/* @0xcc588 bge 0xcc68c <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x40c> */
/* @0xcc58c cmp r11, #0 */
/* @0xcc590 movgt r6, r11 */
/* @0xcc594 ble 0xcc5fc <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x37c> */
/* @0xcc598 rsb r4, r5, r4 */
/* @0xcc59c ldr r0, [r10, #0xc] */
/* @0xcc5a0 cmp r4, r6 */
/* @0xcc5a4 movge r4, r6 */
/* @0xcc5a8 mov r1, #0 */
/* @0xcc5ac add r0, r0, r5 */
/* @0xcc5b0 rsb r6, r4, r6 */
/* @0xcc5b4 mov r2, r4 */
/* @0xcc5b8 bl 0xb65b0 <memset@plt> */
/* @0xcc5bc add r0, r5, r4 */
/* @0xcc5c0 cmn r0, #1 */
/* @0xcc5c4 ldr r4, [r10, #0x10] */
/* @0xcc5c8 mov r3, r0 */
/* @0xcc5cc ldr r2, [r10, #0x20] */
/* @0xcc5d0 ldreq r3, [r10, #0x1c] */
/* @0xcc5d4 mov r1, r4 */
/* @0xcc5d8 cmp r3, r2 */
/* @0xcc5dc movlt r3, r2 */
/* @0xcc5e0 cmp r3, r4 */
/* @0xcc5e4 strle r3, [r10, #0x20] */
/* @0xcc5e8 strgt r4, [r10, #0x20] */
/* @0xcc5ec bl 0x318dec <__aeabi_idivmod> */
/* @0xcc5f0 cmp r6, #0 */
/* @0xcc5f4 mov r5, r1 */
/* @0xcc5f8 bgt 0xcc598 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x318> */
/* @0xcc5fc add r8, r8, r11 */
/* @0xcc600 ldr r2, [sp, #0x4] */
/* @0xcc604 add r3, r9, r8 */
/* @0xcc608 ldr r11, [sp] */
/* @0xcc60c cmp r2, r3 */
/* @0xcc610 movlt r6, #0 */
/* @0xcc614 movge r6, #1 */
/* @0xcc618 b 0xcc438 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1b8> */
/* @0xcc61c add r5, r1, r11 */
/* @0xcc620 ldr r3, [r10, #0x20] */
/* @0xcc624 cmn r5, #1 */
/* @0xcc628 ldreq r5, [r10, #0x1c] */
/* @0xcc62c cmp r5, r3 */
/* @0xcc630 movlt r5, r3 */
/* @0xcc634 cmp r5, r4 */
/* @0xcc638 strle r5, [r10, #0x20] */
/* @0xcc63c strgt r4, [r10, #0x20] */
/* @0xcc640 b 0xcc5fc <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x37c> */
/* @0xcc644 cmp r9, #0 */
/* @0xcc648 ble 0xcc664 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x3e4> */
/* @0xcc64c ldr r1, [sp, #0x8] */
/* @0xcc650 ldrb r0, [r1], #1 */
/* @0xcc654 cmp r1, r7 */
/* @0xcc658 strb r0, [r3], #1 */
/* @0xcc65c bne 0xcc650 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x3d0> */
/* @0xcc660 ldr r4, [r10, #0x10] */
/* @0xcc664 cmn r2, #1 */
/* @0xcc668 ldr r3, [r10, #0x20] */
/* @0xcc66c add r11, r11, r9 */
/* @0xcc670 ldreq r2, [r10, #0x1c] */
/* @0xcc674 cmp r2, r3 */
/* @0xcc678 movlt r2, r3 */
/* @0xcc67c cmp r2, r4 */
/* @0xcc680 strle r2, [r10, #0x20] */
/* @0xcc684 strgt r4, [r10, #0x20] */
/* @0xcc688 b 0xcc430 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1b0> */
/* @0xcc68c ldr r0, [r10, #0xc] */
/* @0xcc690 mov r2, r11 */
/* @0xcc694 mov r1, #0 */
/* @0xcc698 add r0, r0, r5 */
/* @0xcc69c bl 0xb65b0 <memset@plt> */
/* @0xcc6a0 cmn r6, #1 */
/* @0xcc6a4 ldr r4, [r10, #0x10] */
/* @0xcc6a8 ldreq r6, [r10, #0x1c] */
/* @0xcc6ac ldr r2, [r10, #0x20] */
/* @0xcc6b0 cmp r6, r2 */
/* @0xcc6b4 movge r3, r6 */
/* @0xcc6b8 movlt r3, r2 */
/* @0xcc6bc cmp r3, r4 */
/* @0xcc6c0 strle r3, [r10, #0x20] */
/* @0xcc6c4 strgt r4, [r10, #0x20] */
/* @0xcc6c8 b 0xcc5fc <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x37c> */
/* @0xcc6cc cmp r6, #0 */
/* @0xcc6d0 ldr r4, [r10, #0x10] */
/* @0xcc6d4 bge 0xcc6ec <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x46c> */
/* @0xcc6d8 adds r6, r6, r4 */
/* @0xcc6dc bmi 0xcc6d8 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x458> */
/* @0xcc6e0 cmp r6, r4 */
/* @0xcc6e4 blt 0xcc6f4 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x474> */
/* @0xcc6e8 rsb r6, r4, r6 */
/* @0xcc6ec cmp r6, r4 */
/* @0xcc6f0 bge 0xcc6e8 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x468> */
/* @0xcc6f4 ldr r3, [sp, #0x4] */
/* @0xcc6f8 add r3, r6, r3 */
/* @0xcc6fc str r3, [sp, #0x10] */
/* @0xcc700 b 0xcc354 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0xd4> */
/* @0xcc704 mov r0, r6 */
/* @0xcc708 ldr r1, [r10, #0x14] */
/* @0xcc70c bl 0x318dec <__aeabi_idivmod> */
/* @0xcc710 mov r3, #1 */
/* @0xcc714 str r3, [sp, #0x14] */
/* @0xcc718 cmp r1, #0 */
/* @0xcc71c movne r3, #0 */
/* @0xcc720 bne 0xcc380 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x100> */
/* @0xcc724 b 0xcc370 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0xf0> */

/* ── FUNC 0xcc728 · IBuffer::GetSurface(int, int, int, int) · size=276 · insn=69 */
/* @0xcc728 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xcc72c sub sp, sp, #16 */
/* @0xcc730 mov r10, r0 */
/* @0xcc734 mov r0, r1 */
/* @0xcc738 mov r4, r1 */
/* @0xcc73c mov r5, r3 */
/* @0xcc740 ldr r8, [sp, #0x30] */
/* @0xcc744 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0xcc748 cmp r0, #0 */
/* @0xcc74c bne 0xcc758 <_ZN7IBuffer10GetSurfaceEiiii+0x30> */
/* @0xcc750 add sp, sp, #16 */
/* @0xcc754 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xcc758 mov r0, r4 */
/* @0xcc75c bl 0x1714d4 <_Z20GR_Surface_Get_Widthi> */
/* @0xcc760 mov r6, r0 */
/* @0xcc764 mov r0, r4 */
/* @0xcc768 bl 0x171518 <_Z21GR_Surface_Get_Heighti> */
/* @0xcc76c ldr r2, [r10, #0x10] */
/* @0xcc770 mul r3, r0, r6 */
/* @0xcc774 mov r7, r0 */
/* @0xcc778 add r3, r5, r3, lsl #2 */
/* @0xcc77c cmp r2, r3 */
/* @0xcc780 blt 0xcc750 <_ZN7IBuffer10GetSurfaceEiiii+0x28> */
/* @0xcc784 ldr r3, [pc, #0xac] */
/* @0xcc788 ldr r3, [pc, r3] */
/* @0xcc78c ldr r2, [r3, #0x4] */
/* @0xcc790 ldr r3, [r3] */
/* @0xcc794 and r2, r4, r2 */
/* @0xcc798 ldr r12, [r3, r2, lsl #3] */
/* @0xcc79c cmp r12, #0 */
/* @0xcc7a0 bne 0xcc7b4 <_ZN7IBuffer10GetSurfaceEiiii+0x8c> */
/* @0xcc7a4 b 0xcc7c4 <_ZN7IBuffer10GetSurfaceEiiii+0x9c> */
/* @0xcc7a8 ldr r12, [r12, #0x4] */
/* @0xcc7ac cmp r12, #0 */
/* @0xcc7b0 beq 0xcc7c4 <_ZN7IBuffer10GetSurfaceEiiii+0x9c> */
/* @0xcc7b4 ldr r3, [r12, #0x8] */
/* @0xcc7b8 cmp r4, r3 */
/* @0xcc7bc bne 0xcc7a8 <_ZN7IBuffer10GetSurfaceEiiii+0x80> */
/* @0xcc7c0 ldr r12, [r12, #0xc] */
/* @0xcc7c4 ldr r0, [r12, #0x4] */
/* @0xcc7c8 bl 0x17435c <_Z22GR_Texture_Get_Surfacei> */
/* @0xcc7cc mov r1, #0 */
/* @0xcc7d0 mov r3, r6 */
/* @0xcc7d4 str r7, [sp] */
/* @0xcc7d8 mov r2, r1 */
/* @0xcc7dc bl 0x17e594 <_ZN8Graphics16Surface_GrabRectEPviiii> */
/* @0xcc7e0 cmp r7, #0 */
/* @0xcc7e4 ldr r12, [r10, #0xc] */
/* @0xcc7e8 lslgt r6, r6, #2 */
/* @0xcc7ec addgt r8, r8, r6 */
/* @0xcc7f0 movgt r4, #0 */
/* @0xcc7f4 add r12, r12, r5 */
/* @0xcc7f8 mov r9, r0 */
/* @0xcc7fc movgt r5, r0 */
/* @0xcc800 ble 0xcc828 <_ZN7IBuffer10GetSurfaceEiiii+0x100> */
/* @0xcc804 mov r0, r12 */
/* @0xcc808 mov r1, r5 */
/* @0xcc80c mov r2, r6 */
/* @0xcc810 add r4, r4, #1 */
/* @0xcc814 bl 0xb65bc <memcpy@plt> */
/* @0xcc818 cmp r4, r7 */
/* @0xcc81c add r5, r5, r6 */
/* @0xcc820 add r12, r0, r8 */
/* @0xcc824 bne 0xcc804 <_ZN7IBuffer10GetSurfaceEiiii+0xdc> */
/* @0xcc828 mov r0, r9 */
/* @0xcc82c add sp, sp, #16 */
/* @0xcc830 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xcc834 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xcc838 eorseq r1, r2, r8, lsl #7 */

/* ── FUNC 0xcc83c · IBuffer::SetSurface(int, int, int) · size=196 · insn=49 */
/* @0xcc83c push {r4, r5, r6, r7, r8, lr} */
/* @0xcc840 mov r5, r0 */
/* @0xcc844 sub sp, sp, #8 */
/* @0xcc848 mov r0, r1 */
/* @0xcc84c mov r4, r1 */
/* @0xcc850 mov r6, r2 */
/* @0xcc854 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0xcc858 cmp r0, #0 */
/* @0xcc85c bne 0xcc868 <_ZN7IBuffer10SetSurfaceEiii+0x2c> */
/* @0xcc860 add sp, sp, #8 */
/* @0xcc864 pop {r4, r5, r6, r7, r8, pc} */
/* @0xcc868 mov r0, r4 */
/* @0xcc86c bl 0x1714d4 <_Z20GR_Surface_Get_Widthi> */
/* @0xcc870 mov r7, r0 */
/* @0xcc874 mov r0, r4 */
/* @0xcc878 bl 0x171518 <_Z21GR_Surface_Get_Heighti> */
/* @0xcc87c ldr r3, [r5, #0x10] */
/* @0xcc880 mul r2, r0, r7 */
/* @0xcc884 mov r8, r0 */
/* @0xcc888 add r6, r6, r2, lsl #2 */
/* @0xcc88c cmp r3, r6 */
/* @0xcc890 blt 0xcc860 <_ZN7IBuffer10SetSurfaceEiii+0x24> */
/* @0xcc894 ldr r3, [pc, #0x60] */
/* @0xcc898 ldr r3, [pc, r3] */
/* @0xcc89c ldr r2, [r3, #0x4] */
/* @0xcc8a0 ldr r3, [r3] */
/* @0xcc8a4 and r2, r4, r2 */
/* @0xcc8a8 ldr r3, [r3, r2, lsl #3] */
/* @0xcc8ac cmp r3, #0 */
/* @0xcc8b0 bne 0xcc8c4 <_ZN7IBuffer10SetSurfaceEiii+0x88> */
/* @0xcc8b4 b 0xcc8d4 <_ZN7IBuffer10SetSurfaceEiii+0x98> */
/* @0xcc8b8 ldr r3, [r3, #0x4] */
/* @0xcc8bc cmp r3, #0 */
/* @0xcc8c0 beq 0xcc8d4 <_ZN7IBuffer10SetSurfaceEiii+0x98> */
/* @0xcc8c4 ldr r2, [r3, #0x8] */
/* @0xcc8c8 cmp r4, r2 */
/* @0xcc8cc bne 0xcc8b8 <_ZN7IBuffer10SetSurfaceEiii+0x7c> */
/* @0xcc8d0 ldr r3, [r3, #0xc] */
/* @0xcc8d4 ldr r0, [r3, #0x4] */
/* @0xcc8d8 bl 0x17435c <_Z22GR_Texture_Get_Surfacei> */
/* @0xcc8dc mov r2, #0 */
/* @0xcc8e0 mov r3, r2 */
/* @0xcc8e4 mov r1, r0 */
/* @0xcc8e8 ldr r0, [r5, #0xc] */
/* @0xcc8ec stm sp, {r7, r8} */
/* @0xcc8f0 bl 0x17e6ac <_ZN8Graphics15Surface_SetRectEPvS0_iiii> */
/* @0xcc8f4 add sp, sp, #8 */
/* @0xcc8f8 pop {r4, r5, r6, r7, r8, pc} */
/* @0xcc8fc eorseq r1, r2, r8, ror r2 */

/* ── FUNC 0xcc900 · IBuffer::IBuffer() · size=88 · insn=22 */
/* @0xcc900 ldr r12, [pc, #0x4c] */
/* @0xcc904 mov r2, #0 */
/* @0xcc908 mov r1, #1 */
/* @0xcc90c str r2, [r0, #0x4] */
/* @0xcc910 ldr r12, [pc, r12] */
/* @0xcc914 str r2, [r0, #0xc] */
/* @0xcc918 add r12, r12, #8 */
/* @0xcc91c str r2, [r0, #0x10] */
/* @0xcc920 str r12, [r0] */
/* @0xcc924 str r2, [r0, #0x8] */
/* @0xcc928 str r2, [r0, #0x1c] */
/* @0xcc92c str r2, [r0, #0x20] */
/* @0xcc930 str r2, [r0, #0x24] */
/* @0xcc934 str r2, [r0, #0x38] */
/* @0xcc938 str r2, [r0, #0x2c] */
/* @0xcc93c str r2, [r0, #0x30] */
/* @0xcc940 str r2, [r0, #0x28] */
/* @0xcc944 str r1, [r0, #0x14] */
/* @0xcc948 str r1, [r0, #0x18] */
/* @0xcc94c strb r1, [r0, #0x3c] */
/* @0xcc950 bx lr */
/* @0xcc954 ldrshteq r1, [r2], -r12 */

/* ── FUNC 0xcc900 · IBuffer::IBuffer() · alias of the symbol above · insn=0 */

/* ── FUNC 0xcc958 · IBuffer::GetPOW2Alignment(int) · size=60 · insn=15 */
/* @0xcc958 cmp r0, #1 */
/* @0xcc95c ble 0xcc98c <_ZN7IBuffer16GetPOW2AlignmentEi+0x34> */
/* @0xcc960 mov r2, #10 */
/* @0xcc964 mov r3, #2 */
/* @0xcc968 cmp r0, r3 */
/* @0xcc96c ble 0xcc984 <_ZN7IBuffer16GetPOW2AlignmentEi+0x2c> */
/* @0xcc970 subs r2, r2, #1 */
/* @0xcc974 lsl r3, r3, #1 */
/* @0xcc978 bne 0xcc968 <_ZN7IBuffer16GetPOW2AlignmentEi+0x10> */
/* @0xcc97c mov r0, #1024 */
/* @0xcc980 bx lr */
/* @0xcc984 mov r0, r3 */
/* @0xcc988 bx lr */
/* @0xcc98c mov r0, #1 */
/* @0xcc990 bx lr */

/* ── FUNC 0xcc994 · IBuffer::IBuffer(int, eBuffer_Format, int) · size=164 · insn=41 */
/* @0xcc994 ldr r12, [pc, #0x94] */
/* @0xcc998 push {r3, r4, r5, r6, r7, lr} */
/* @0xcc99c ldr r12, [pc, r12] */
/* @0xcc9a0 mov r4, r0 */
/* @0xcc9a4 add r12, r12, #8 */
/* @0xcc9a8 ubfx r0, r3, #0x0, #0x9 */
/* @0xcc9ac str r12, [r4] */
/* @0xcc9b0 mov r6, r1 */
/* @0xcc9b4 mov r7, r2 */
/* @0xcc9b8 bl 0xcc958 <_ZN7IBuffer16GetPOW2AlignmentEi> */
/* @0xcc9bc ldr r1, [pc, #0x70] */
/* @0xcc9c0 mov r2, #114 */
/* @0xcc9c4 mov r3, #1 */
/* @0xcc9c8 add r1, pc, r1 */
/* @0xcc9cc mov r5, r0 */
/* @0xcc9d0 add r0, r6, r0 */
/* @0xcc9d4 str r0, [r4, #0x8] */
/* @0xcc9d8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xcc9dc rsb r3, r5, #0 */
/* @0xcc9e0 mov r2, #1 */
/* @0xcc9e4 str r7, [r4, #0x18] */
/* @0xcc9e8 str r6, [r4, #0x10] */
/* @0xcc9ec str r5, [r4, #0x14] */
/* @0xcc9f0 str r6, [r4, #0x20] */
/* @0xcc9f4 strb r2, [r4, #0x3c] */
/* @0xcc9f8 add r1, r0, r5 */
/* @0xcc9fc str r0, [r4, #0x4] */
/* @0xcca00 sub r1, r1, #1 */
/* @0xcca04 mov r0, r4 */
/* @0xcca08 and r1, r1, r3 */
/* @0xcca0c mov r3, #0 */
/* @0xcca10 str r1, [r4, #0xc] */
/* @0xcca14 str r3, [r4, #0x1c] */
/* @0xcca18 str r3, [r4, #0x24] */
/* @0xcca1c str r3, [r4, #0x38] */
/* @0xcca20 str r3, [r4, #0x2c] */
/* @0xcca24 str r3, [r4, #0x30] */
/* @0xcca28 str r3, [r4, #0x28] */
/* @0xcca2c pop {r3, r4, r5, r6, r7, pc} */
/* @0xcca30 eorseq r1, r2, r0, ror r1 */
/* @0xcca34 eoreq r5, r6, r8, lsr #15 */

/* ── FUNC 0xcc994 · IBuffer::IBuffer(int, eBuffer_Format, int) · alias of the symbol above · insn=0 */

/* ── FUNC 0xcca38 · IBuffer::IBuffer(void*, int, eBuffer_Format, int, bool) · size=132 · insn=33 */
/* @0xcca38 push {r4, r5, r6, r7, r8, lr} */
/* @0xcca3c mov r4, r0 */
/* @0xcca40 ldr r12, [pc, #0x70] */
/* @0xcca44 mov r5, r2 */
/* @0xcca48 ldr r0, [sp, #0x18] */
/* @0xcca4c mov r6, r1 */
/* @0xcca50 ldr r12, [pc, r12] */
/* @0xcca54 ldrb r7, [sp, #0x1c] */
/* @0xcca58 add r12, r12, #8 */
/* @0xcca5c ubfx r0, r0, #0x0, #0x9 */
/* @0xcca60 str r12, [r4] */
/* @0xcca64 mov r8, r3 */
/* @0xcca68 bl 0xcc958 <_ZN7IBuffer16GetPOW2AlignmentEi> */
/* @0xcca6c mov r1, #0 */
/* @0xcca70 str r6, [r4, #0x4] */
/* @0xcca74 str r6, [r4, #0xc] */
/* @0xcca78 str r8, [r4, #0x18] */
/* @0xcca7c str r5, [r4, #0x10] */
/* @0xcca80 str r5, [r4, #0x20] */
/* @0xcca84 strb r7, [r4, #0x3c] */
/* @0xcca88 str r1, [r4, #0x1c] */
/* @0xcca8c str r1, [r4, #0x24] */
/* @0xcca90 str r1, [r4, #0x38] */
/* @0xcca94 str r1, [r4, #0x2c] */
/* @0xcca98 str r1, [r4, #0x30] */
/* @0xcca9c str r1, [r4, #0x28] */
/* @0xccaa0 mov r2, r0 */
/* @0xccaa4 mov r0, r4 */
/* @0xccaa8 add r12, r5, r2 */
/* @0xccaac str r2, [r4, #0x14] */
/* @0xccab0 str r12, [r4, #0x8] */
/* @0xccab4 pop {r4, r5, r6, r7, r8, pc} */
/* @0xccab8 ldrhteq r1, [r2], -r12 */

/* ── FUNC 0xcca38 · IBuffer::IBuffer(void*, int, eBuffer_Format, int, bool) · alias of the symbol above · insn=0 */

/* ── FUNC 0xccabc · IBuffer::CopyMemoryToBuffer(IBuffer*, unsigned char*, int, int, int, int, bool, bool, bool) · size=584 · insn=146 */
/* @0xccabc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xccac0 subs r8, r0, #0 */
/* @0xccac4 sub sp, sp, #8 */
/* @0xccac8 mov r5, r2 */
/* @0xccacc mov r9, r1 */
/* @0xccad0 ldr r6, [sp, #0x28] */
/* @0xccad4 ldr r4, [sp, #0x2c] */
/* @0xccad8 ldrb r2, [sp, #0x30] */
/* @0xccadc ldrb r10, [sp, #0x34] */
/* @0xccae0 ldrb r7, [sp, #0x38] */
/* @0xccae4 beq 0xcccfc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x240> */
/* @0xccae8 cmp r1, #0 */
/* @0xccaec beq 0xcccfc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x240> */
/* @0xccaf0 cmp r5, #0 */
/* @0xccaf4 ble 0xcccfc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x240> */
/* @0xccaf8 cmp r6, #0 */
/* @0xccafc movlt r6, r5 */
/* @0xccb00 cmp r7, #0 */
/* @0xccb04 bne 0xccc10 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x154> */
/* @0xccb08 cmp r3, #0 */
/* @0xccb0c movlt r3, r7 */
/* @0xccb10 blt 0xccb1c <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x60> */
/* @0xccb14 cmp r5, r3 */
/* @0xccb18 suble r3, r5, #1 */
/* @0xccb1c add r1, r3, r6 */
/* @0xccb20 cmp r5, r1 */
/* @0xccb24 rsblt r6, r3, r5 */
/* @0xccb28 cmp r2, #0 */
/* @0xccb2c bne 0xccc4c <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x190> */
/* @0xccb30 ldr r2, [r8, #0x10] */
/* @0xccb34 cmp r2, #0 */
/* @0xccb38 ble 0xcccfc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x240> */
/* @0xccb3c cmp r10, #0 */
/* @0xccb40 beq 0xcccb0 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x1f4> */
/* @0xccb44 cmp r4, #0 */
/* @0xccb48 bge 0xccb60 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0xa4> */
/* @0xccb4c adds r4, r4, r2 */
/* @0xccb50 bmi 0xccb4c <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x90> */
/* @0xccb54 cmp r2, r4 */
/* @0xccb58 bgt 0xccb68 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0xac> */
/* @0xccb5c rsb r4, r2, r4 */
/* @0xccb60 cmp r2, r4 */
/* @0xccb64 ble 0xccb5c <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0xa0> */
/* @0xccb68 add r1, r6, r4 */
/* @0xccb6c cmp r2, r1 */
/* @0xccb70 bge 0xcccd0 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x214> */
/* @0xccb74 cmp r6, #0 */
/* @0xccb78 ble 0xccc04 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x148> */
/* @0xccb7c ldr r7, [r8, #0x10] */
/* @0xccb80 rsb r2, r3, r5 */
/* @0xccb84 rsb r7, r4, r7 */
/* @0xccb88 cmp r7, r2 */
/* @0xccb8c movge r7, r2 */
/* @0xccb90 ldr r0, [r8, #0xc] */
/* @0xccb94 cmp r7, r6 */
/* @0xccb98 movge r7, r6 */
/* @0xccb9c add r1, r9, r3 */
/* @0xccba0 add r0, r0, r4 */
/* @0xccba4 add r10, r3, r7 */
/* @0xccba8 mov r2, r7 */
/* @0xccbac rsb r6, r7, r6 */
/* @0xccbb0 bl 0xb65bc <memcpy@plt> */
/* @0xccbb4 add r0, r4, r7 */
/* @0xccbb8 cmn r0, #1 */
/* @0xccbbc ldr r7, [r8, #0x10] */
/* @0xccbc0 ldr r2, [r8, #0x20] */
/* @0xccbc4 mov r3, r0 */
/* @0xccbc8 ldreq r3, [r8, #0x1c] */
/* @0xccbcc mov r1, r7 */
/* @0xccbd0 cmp r3, r2 */
/* @0xccbd4 movlt r3, r2 */
/* @0xccbd8 cmp r3, r7 */
/* @0xccbdc strle r3, [r8, #0x20] */
/* @0xccbe0 strgt r7, [r8, #0x20] */
/* @0xccbe4 bl 0x318dec <__aeabi_idivmod> */
/* @0xccbe8 mov r0, r10 */
/* @0xccbec mov r4, r1 */
/* @0xccbf0 mov r1, r5 */
/* @0xccbf4 bl 0x318dec <__aeabi_idivmod> */
/* @0xccbf8 cmp r6, #0 */
/* @0xccbfc mov r3, r1 */
/* @0xccc00 bgt 0xccb80 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0xc4> */
/* @0xccc04 mov r0, r4 */
/* @0xccc08 add sp, sp, #8 */
/* @0xccc0c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xccc10 cmp r3, #0 */
/* @0xccc14 bge 0xccc20 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x164> */
/* @0xccc18 adds r3, r3, r5 */
/* @0xccc1c bmi 0xccc18 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x15c> */
/* @0xccc20 cmp r3, r5 */
/* @0xccc24 blt 0xccc34 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x178> */
/* @0xccc28 rsb r3, r5, r3 */
/* @0xccc2c cmp r5, r3 */
/* @0xccc30 ble 0xccc28 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x16c> */
/* @0xccc34 add r7, r3, r6 */
/* @0xccc38 cmp r5, r7 */
/* @0xccc3c movge r7, #0 */
/* @0xccc40 movlt r7, #1 */
/* @0xccc44 cmp r2, #0 */
/* @0xccc48 beq 0xccb30 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x74> */
/* @0xccc4c bic r4, r4, r4, asr #31 */
/* @0xccc50 ldr r2, [r8, #0x10] */
/* @0xccc54 add r1, r6, r4 */
/* @0xccc58 cmp r1, r2 */
/* @0xccc5c bgt 0xccce0 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x224> */
/* @0xccc60 orrs r7, r10, r7 */
/* @0xccc64 bne 0xccb74 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0xb8> */
/* @0xccc68 ldr r0, [r8, #0xc] */
/* @0xccc6c add r1, r9, r3 */
/* @0xccc70 mov r2, r6 */
/* @0xccc74 add r0, r0, r4 */
/* @0xccc78 bl 0xb65bc <memcpy@plt> */
/* @0xccc7c add r0, r4, r6 */
/* @0xccc80 cmn r0, #1 */
/* @0xccc84 ldr r3, [r8, #0x10] */
/* @0xccc88 ldr r2, [r8, #0x20] */
/* @0xccc8c ldreq r1, [r8, #0x1c] */
/* @0xccc90 movne r1, r0 */
/* @0xccc94 cmp r2, r1 */
/* @0xccc98 movlt r2, r1 */
/* @0xccc9c cmp r2, r3 */
/* @0xccca0 strle r2, [r8, #0x20] */
/* @0xccca4 strgt r3, [r8, #0x20] */
/* @0xccca8 add sp, sp, #8 */
/* @0xcccac pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xcccb0 cmp r4, #0 */
/* @0xcccb4 blt 0xcccd8 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x21c> */
/* @0xcccb8 cmp r2, r4 */
/* @0xcccbc ble 0xcccfc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x240> */
/* @0xcccc0 add r1, r6, r4 */
/* @0xcccc4 cmp r2, r1 */
/* @0xcccc8 rsblt r6, r4, r2 */
/* @0xccccc b 0xccc60 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x1a4> */
/* @0xcccd0 mov r10, #0 */
/* @0xcccd4 b 0xccc60 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x1a4> */
/* @0xcccd8 mov r4, r10 */
/* @0xcccdc b 0xcccc0 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x204> */
/* @0xccce0 ldr r2, [r8] */
/* @0xccce4 mov r0, r8 */
/* @0xccce8 ldr r2, [r2, #0x34] */
/* @0xcccec str r3, [sp, #0x4] */
/* @0xcccf0 blx r2 */
/* @0xcccf4 ldr r3, [sp, #0x4] */
/* @0xcccf8 b 0xccc60 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x1a4> */
/* @0xcccfc mvn r0, #0 */
/* @0xccd00 b 0xccc08 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x14c> */

/* ── FUNC 0xccd04 · IBuffer::Copy(int, int, IBuffer*, int) · size=144 · insn=36 */
/* @0xccd04 push {r4, r5, lr} */
/* @0xccd08 subs r4, r3, #0 */
/* @0xccd0c sub sp, sp, #28 */
/* @0xccd10 mov r12, r0 */
/* @0xccd14 mov r3, r1 */
/* @0xccd18 beq 0xccd7c <_ZN7IBuffer4CopyEiiPS_i+0x78> */
/* @0xccd1c ldr r0, [r4, #0x18] */
/* @0xccd20 cmp r0, #1 */
/* @0xccd24 beq 0xccd8c <_ZN7IBuffer4CopyEiiPS_i+0x88> */
/* @0xccd28 ldr r5, [r4, #0x10] */
/* @0xccd2c rsbs r5, r5, #1 */
/* @0xccd30 movlo r5, #0 */
/* @0xccd34 cmp r0, #2 */
/* @0xccd38 beq 0xccd84 <_ZN7IBuffer4CopyEiiPS_i+0x80> */
/* @0xccd3c mov lr, #0 */
/* @0xccd40 ldr r1, [r12, #0xc] */
/* @0xccd44 mov r0, r4 */
/* @0xccd48 ldr r4, [r12, #0x10] */
/* @0xccd4c ldr r12, [r12, #0x18] */
/* @0xccd50 str r2, [sp] */
/* @0xccd54 ldr r2, [sp, #0x28] */
/* @0xccd58 str r5, [sp, #0x8] */
/* @0xccd5c str lr, [sp, #0xc] */
/* @0xccd60 str r2, [sp, #0x4] */
/* @0xccd64 subs r2, r12, #2 */
/* @0xccd68 rsbs r12, r2, #0 */
/* @0xccd6c adcs r12, r12, r2 */
/* @0xccd70 mov r2, r4 */
/* @0xccd74 str r12, [sp, #0x10] */
/* @0xccd78 bl 0xccabc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb> */
/* @0xccd7c add sp, sp, #28 */
/* @0xccd80 pop {r4, r5, pc} */
/* @0xccd84 mov lr, #1 */
/* @0xccd88 b 0xccd40 <_ZN7IBuffer4CopyEiiPS_i+0x3c> */
/* @0xccd8c mov r5, r0 */
/* @0xccd90 b 0xccd3c <_ZN7IBuffer4CopyEiiPS_i+0x38> */

/* ── FUNC 0xccd94 · IBuffer::CopyMemoryToMemory(unsigned char*, int, unsigned char*, int, int, int, int, bool, bool) · size=420 · insn=105 */
/* @0xccd94 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xccd98 subs r10, r0, #0 */
/* @0xccd9c mov r9, r2 */
/* @0xccda0 mov r5, r3 */
/* @0xccda4 mov r6, r1 */
/* @0xccda8 ldr r12, [sp, #0x28] */
/* @0xccdac ldr r7, [sp, #0x2c] */
/* @0xccdb0 ldr r4, [sp, #0x30] */
/* @0xccdb4 ldrb r2, [sp, #0x34] */
/* @0xccdb8 ldrb r3, [sp, #0x38] */
/* @0xccdbc beq 0xccf30 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x19c> */
/* @0xccdc0 cmp r1, #0 */
/* @0xccdc4 ble 0xccf30 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x19c> */
/* @0xccdc8 cmp r9, #0 */
/* @0xccdcc beq 0xccf30 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x19c> */
/* @0xccdd0 cmp r5, #0 */
/* @0xccdd4 ble 0xccf30 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x19c> */
/* @0xccdd8 cmp r7, #0 */
/* @0xccddc movlt r7, r5 */
/* @0xccde0 cmp r3, #0 */
/* @0xccde4 bne 0xcceb0 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x11c> */
/* @0xccde8 cmp r12, #0 */
/* @0xccdec movlt r12, r3 */
/* @0xccdf0 blt 0xccdfc <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x68> */
/* @0xccdf4 cmp r5, r12 */
/* @0xccdf8 suble r12, r5, #1 */
/* @0xccdfc add r1, r12, r7 */
/* @0xcce00 cmp r5, r1 */
/* @0xcce04 rsblt r7, r12, r5 */
/* @0xcce08 cmp r2, #0 */
/* @0xcce0c beq 0xcceec <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x158> */
/* @0xcce10 cmp r4, #0 */
/* @0xcce14 bge 0xcce2c <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x98> */
/* @0xcce18 adds r4, r4, r6 */
/* @0xcce1c bmi 0xcce18 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x84> */
/* @0xcce20 cmp r6, r4 */
/* @0xcce24 bgt 0xcce34 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0xa0> */
/* @0xcce28 rsb r4, r6, r4 */
/* @0xcce2c cmp r6, r4 */
/* @0xcce30 ble 0xcce28 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x94> */
/* @0xcce34 add r2, r7, r4 */
/* @0xcce38 cmp r6, r2 */
/* @0xcce3c blt 0xcce48 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0xb4> */
/* @0xcce40 cmp r3, #0 */
/* @0xcce44 beq 0xccf10 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x17c> */
/* @0xcce48 cmp r7, #0 */
/* @0xcce4c ble 0xccea8 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x114> */
/* @0xcce50 rsb r3, r12, r5 */
/* @0xcce54 rsb r8, r4, r6 */
/* @0xcce58 cmp r8, r3 */
/* @0xcce5c movge r8, r3 */
/* @0xcce60 add r1, r9, r12 */
/* @0xcce64 cmp r8, r7 */
/* @0xcce68 movge r8, r7 */
/* @0xcce6c add r0, r10, r4 */
/* @0xcce70 add r11, r12, r8 */
/* @0xcce74 rsb r7, r8, r7 */
/* @0xcce78 mov r2, r8 */
/* @0xcce7c bl 0xb65bc <memcpy@plt> */
/* @0xcce80 add r0, r4, r8 */
/* @0xcce84 mov r1, r6 */
/* @0xcce88 bl 0x318dec <__aeabi_idivmod> */
/* @0xcce8c mov r0, r11 */
/* @0xcce90 mov r4, r1 */
/* @0xcce94 mov r1, r5 */
/* @0xcce98 bl 0x318dec <__aeabi_idivmod> */
/* @0xcce9c cmp r7, #0 */
/* @0xccea0 mov r12, r1 */
/* @0xccea4 bgt 0xcce50 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0xbc> */
/* @0xccea8 mov r0, r4 */
/* @0xcceac pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xcceb0 cmp r12, #0 */
/* @0xcceb4 bge 0xccec0 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x12c> */
/* @0xcceb8 adds r12, r12, r5 */
/* @0xccebc bmi 0xcceb8 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x124> */
/* @0xccec0 cmp r12, r5 */
/* @0xccec4 blt 0xcced4 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x140> */
/* @0xccec8 rsb r12, r5, r12 */
/* @0xccecc cmp r5, r12 */
/* @0xcced0 ble 0xccec8 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x134> */
/* @0xcced4 add r3, r12, r7 */
/* @0xcced8 cmp r5, r3 */
/* @0xccedc movge r3, #0 */
/* @0xccee0 movlt r3, #1 */
/* @0xccee4 cmp r2, #0 */
/* @0xccee8 bne 0xcce10 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x7c> */
/* @0xcceec cmp r4, #0 */
/* @0xccef0 blt 0xccf28 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x194> */
/* @0xccef4 cmp r6, r4 */
/* @0xccef8 ble 0xccf30 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x19c> */
/* @0xccefc add r2, r7, r4 */
/* @0xccf00 cmp r6, r2 */
/* @0xccf04 rsblt r7, r4, r6 */
/* @0xccf08 cmp r3, #0 */
/* @0xccf0c bne 0xcce48 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0xb4> */
/* @0xccf10 add r0, r10, r4 */
/* @0xccf14 add r1, r9, r12 */
/* @0xccf18 mov r2, r7 */
/* @0xccf1c bl 0xb65bc <memcpy@plt> */
/* @0xccf20 add r0, r4, r7 */
/* @0xccf24 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xccf28 mov r4, r2 */
/* @0xccf2c b 0xccefc <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x168> */
/* @0xccf30 mvn r0, #0 */
/* @0xccf34 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0xccf38 · IBuffer::GetBufferFileHeader(char const*, BufferFileHeader&) · size=264 · insn=66 */
/* @0xccf38 push {r4, r5, lr} */
/* @0xccf3c mov r4, r0 */
/* @0xccf40 ldr r0, [pc, #0xf0] */
/* @0xccf44 sub sp, sp, #12 */
/* @0xccf48 mov r5, r1 */
/* @0xccf4c mov r2, #7 */
/* @0xccf50 add r0, pc, r0 */
/* @0xccf54 mov r1, r4 */
/* @0xccf58 bl 0xb65e0 <strncmp@plt> */
/* @0xccf5c cmp r0, #0 */
/* @0xccf60 beq 0xccf80 <_ZN7IBuffer19GetBufferFileHeaderEPKcR16BufferFileHeader+0x48> */
/* @0xccf64 ldr r0, [pc, #0xd0] */
/* @0xccf68 mov r1, r4 */
/* @0xccf6c mov r2, #8 */
/* @0xccf70 add r0, pc, r0 */
/* @0xccf74 bl 0xb65e0 <strncmp@plt> */
/* @0xccf78 cmp r0, #0 */
/* @0xccf7c bne 0xccf88 <_ZN7IBuffer19GetBufferFileHeaderEPKcR16BufferFileHeader+0x50> */
/* @0xccf80 add sp, sp, #12 */
/* @0xccf84 pop {r4, r5, pc} */
/* @0xccf88 mov r0, r4 */
/* @0xccf8c mov r3, #0 */
/* @0xccf90 str r3, [sp, #0x4] */
/* @0xccf94 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0xccf98 cmp r0, #0 */
/* @0xccf9c mov r0, r4 */
/* @0xccfa0 beq 0xccfec <_ZN7IBuffer19GetBufferFileHeaderEPKcR16BufferFileHeader+0xb4> */
/* @0xccfa4 add r1, sp, #4 */
/* @0xccfa8 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi> */
/* @0xccfac mov r12, r0 */
/* @0xccfb0 cmp r12, #0 */
/* @0xccfb4 beq 0xccff8 <_ZN7IBuffer19GetBufferFileHeaderEPKcR16BufferFileHeader+0xc0> */
/* @0xccfb8 ldr r2, [r12] */
/* @0xccfbc movw r3, #0x5542 */
/* @0xccfc0 movt r3, #0x4646 */
/* @0xccfc4 cmp r2, r3 */
/* @0xccfc8 bne 0xccfd8 <_ZN7IBuffer19GetBufferFileHeaderEPKcR16BufferFileHeader+0xa0> */
/* @0xccfcc ldr r4, [r12, #0x4] */
/* @0xccfd0 cmp r4, #1 */
/* @0xccfd4 beq 0xcd014 <_ZN7IBuffer19GetBufferFileHeaderEPKcR16BufferFileHeader+0xdc> */
/* @0xccfd8 mov r0, r12 */
/* @0xccfdc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xccfe0 mov r0, #0 */
/* @0xccfe4 add sp, sp, #12 */
/* @0xccfe8 pop {r4, r5, pc} */
/* @0xccfec bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0xccff0 cmp r0, #0 */
/* @0xccff4 bne 0xcd000 <_ZN7IBuffer19GetBufferFileHeaderEPKcR16BufferFileHeader+0xc8> */
/* @0xccff8 mov r0, #0 */
/* @0xccffc b 0xccf80 <_ZN7IBuffer19GetBufferFileHeaderEPKcR16BufferFileHeader+0x48> */
/* @0xcd000 mov r0, r4 */
/* @0xcd004 add r1, sp, #4 */
/* @0xcd008 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0xcd00c mov r12, r0 */
/* @0xcd010 b 0xccfb0 <_ZN7IBuffer19GetBufferFileHeaderEPKcR16BufferFileHeader+0x78> */
/* @0xcd014 mov lr, r12 */
/* @0xcd018 ldm lr!, {r0, r1, r2, r3} */
/* @0xcd01c stm r5!, {r0, r1, r2, r3} */
/* @0xcd020 mov r0, r12 */
/* @0xcd024 ldr r3, [lr] */
/* @0xcd028 str r3, [r5] */
/* @0xcd02c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xcd030 mov r0, r4 */
/* @0xcd034 b 0xccf80 <_ZN7IBuffer19GetBufferFileHeaderEPKcR16BufferFileHeader+0x48> */
/* @0xcd038 mlaeq r6, r0, r11, r3 */
/* @0xcd03c eoreq r3, r6, r8, ror r11 */

/* ── FUNC 0xcd040 · IBuffer::GetBufferFileHeaderFromBase64(char const*, BufferFileHeader&) · size=192 · insn=48 */
/* @0xcd040 push {r3, r4, r5, r6, r7, lr} */
/* @0xcd044 subs r6, r0, #0 */
/* @0xcd048 mov r7, r1 */
/* @0xcd04c beq 0xcd0d0 <_ZN7IBuffer29GetBufferFileHeaderFromBase64EPKcR16BufferFileHeader+0x90> */
/* @0xcd050 bl 0xb6538 <strlen@plt> */
/* @0xcd054 ldr r1, [pc, #0xa0] */
/* @0xcd058 movw r2, #0x1fe */
/* @0xcd05c mov r3, #1 */
/* @0xcd060 add r1, pc, r1 */
/* @0xcd064 add r0, r0, r0, lsl #1 */
/* @0xcd068 cmp r0, #0 */
/* @0xcd06c add r5, r0, #3 */
/* @0xcd070 movge r12, r0 */
/* @0xcd074 movlt r12, r5 */
/* @0xcd078 asr r5, r12, #2 */
/* @0xcd07c add r5, r5, #4 */
/* @0xcd080 mov r0, r5 */
/* @0xcd084 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xcd088 mov r1, r5 */
/* @0xcd08c mov r3, #0 */
/* @0xcd090 mov r4, r0 */
/* @0xcd094 mov r0, r6 */
/* @0xcd098 mov r2, r4 */
/* @0xcd09c bl 0x1d1ff0 <_Z13base64_decodePKcjPcb> */
/* @0xcd0a0 cmp r4, #0 */
/* @0xcd0a4 beq 0xcd0d0 <_ZN7IBuffer29GetBufferFileHeaderFromBase64EPKcR16BufferFileHeader+0x90> */
/* @0xcd0a8 ldr r2, [r4] */
/* @0xcd0ac movw r3, #0x5542 */
/* @0xcd0b0 movt r3, #0x4646 */
/* @0xcd0b4 cmp r2, r3 */
/* @0xcd0b8 bne 0xcd0c8 <_ZN7IBuffer29GetBufferFileHeaderFromBase64EPKcR16BufferFileHeader+0x88> */
/* @0xcd0bc ldr r5, [r4, #0x4] */
/* @0xcd0c0 cmp r5, #1 */
/* @0xcd0c4 beq 0xcd0d8 <_ZN7IBuffer29GetBufferFileHeaderFromBase64EPKcR16BufferFileHeader+0x98> */
/* @0xcd0c8 mov r0, r4 */
/* @0xcd0cc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xcd0d0 mov r0, #0 */
/* @0xcd0d4 pop {r3, r4, r5, r6, r7, pc} */
/* @0xcd0d8 mov r12, r4 */
/* @0xcd0dc ldm r12!, {r0, r1, r2, r3} */
/* @0xcd0e0 stm r7!, {r0, r1, r2, r3} */
/* @0xcd0e4 mov r0, r4 */
/* @0xcd0e8 ldr r3, [r12] */
/* @0xcd0ec str r3, [r7] */
/* @0xcd0f0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xcd0f4 mov r0, r5 */
/* @0xcd0f8 pop {r3, r4, r5, r6, r7, pc} */
/* @0xcd0fc eoreq r5, r6, r0, lsl r1 */

/* ── FUNC 0xcd100 · IBuffer::SizeOf(eBuffer_Type) · size=40 · insn=10 */
/* @0xcd100 sub r0, r0, #1 */
/* @0xcd104 cmp r0, #11 */
/* @0xcd108 bhi 0xcd11c <_ZN7IBuffer6SizeOfE12eBuffer_Type+0x1c> */
/* @0xcd10c ldr r3, [pc, #0x10] */
/* @0xcd110 add r3, pc, r3 */
/* @0xcd114 ldr r0, [r3, r0, lsl #2] */
/* @0xcd118 bx lr */
/* @0xcd11c mov r0, #0 */
/* @0xcd120 bx lr */
/* @0xcd124 eoreq pc, r8, r12, asr #13 */

/* ── FUNC 0xcd128 · IBuffer::Peek(int, eBuffer_Type, RValue*) · size=476 · insn=119 */
/* @0xcd128 push {r4, r5, r6, r7, r8, lr} */
/* @0xcd12c mov r6, r3 */
/* @0xcd130 sub sp, sp, #8 */
/* @0xcd134 mov r3, #0 */
/* @0xcd138 mov r8, r0 */
/* @0xcd13c str r3, [r6, #0xc] */
/* @0xcd140 mov r0, r2 */
/* @0xcd144 mov r4, r1 */
/* @0xcd148 mov r7, r2 */
/* @0xcd14c bl 0xcd100 <_ZN7IBuffer6SizeOfE12eBuffer_Type> */
/* @0xcd150 cmp r4, #0 */
/* @0xcd154 blt 0xcd1f0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xc8> */
/* @0xcd158 ldr r3, [r8, #0x18] */
/* @0xcd15c cmp r3, #2 */
/* @0xcd160 beq 0xcd1f8 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xd0> */
/* @0xcd164 ldr r3, [r8, #0x10] */
/* @0xcd168 rsb r3, r0, r3 */
/* @0xcd16c cmp r4, r3 */
/* @0xcd170 bgt 0xcd1f0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xc8> */
/* @0xcd174 ldr r3, [r8, #0xc] */
/* @0xcd178 cmp r0, #0 */
/* @0xcd17c add r4, r3, r4 */
/* @0xcd180 ble 0xcd19c <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x74> */
/* @0xcd184 add r5, r4, r0 */
/* @0xcd188 sub r1, sp, #1 */
/* @0xcd18c ldrb r12, [r4], #1 */
/* @0xcd190 cmp r4, r5 */
/* @0xcd194 strb r12, [r1, #0x1]! */
/* @0xcd198 bne 0xcd18c <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x64> */
/* @0xcd19c sub r7, r7, #1 */
/* @0xcd1a0 cmp r7, #11 */
/* @0xcd1a4 addls pc, pc, r7, lsl #2 */
/* @0xcd1a8 b 0xcd2f4 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x1cc> */
/* @0xcd1ac b 0xcd250 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x128> */
/* @0xcd1b0 b 0xcd2e0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x1b8> */
/* @0xcd1b4 b 0xcd2cc <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x1a4> */
/* @0xcd1b8 b 0xcd2b8 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x190> */
/* @0xcd1bc b 0xcd29c <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x174> */
/* @0xcd1c0 b 0xcd288 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x160> */
/* @0xcd1c4 b 0xcd2f4 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x1cc> */
/* @0xcd1c8 b 0xcd274 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x14c> */
/* @0xcd1cc b 0xcd268 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x140> */
/* @0xcd1d0 b 0xcd250 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x128> */
/* @0xcd1d4 b 0xcd2f4 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x1cc> */
/* @0xcd1d8 b 0xcd1dc <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xb4> */
/* @0xcd1dc ldr r2, [sp] */
/* @0xcd1e0 mov r1, #10 */
/* @0xcd1e4 ldr r3, [sp, #0x4] */
/* @0xcd1e8 str r1, [r6, #0xc] */
/* @0xcd1ec stm r6, {r2, r3} */
/* @0xcd1f0 add sp, sp, #8 */
/* @0xcd1f4 pop {r4, r5, r6, r7, r8, pc} */
/* @0xcd1f8 ldr r1, [r8, #0x10] */
/* @0xcd1fc cmp r4, r1 */
/* @0xcd200 blt 0xcd210 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xe8> */
/* @0xcd204 rsb r4, r1, r4 */
/* @0xcd208 cmp r1, r4 */
/* @0xcd20c ble 0xcd204 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xdc> */
/* @0xcd210 ldr r2, [r8, #0xc] */
/* @0xcd214 cmp r0, #0 */
/* @0xcd218 add r12, r2, r4 */
/* @0xcd21c ble 0xcd19c <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x74> */
/* @0xcd220 sub r5, sp, #1 */
/* @0xcd224 add r0, r5, r0 */
/* @0xcd228 ldrb r3, [r12] */
/* @0xcd22c add r4, r4, #1 */
/* @0xcd230 cmp r4, r1 */
/* @0xcd234 add r12, r12, #1 */
/* @0xcd238 strb r3, [r5, #0x1]! */
/* @0xcd23c movge r12, r2 */
/* @0xcd240 movge r4, #0 */
/* @0xcd244 cmp r5, r0 */
/* @0xcd248 bne 0xcd228 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x100> */
/* @0xcd24c b 0xcd19c <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x74> */
/* @0xcd250 ldrb r3, [sp] */
/* @0xcd254 mov r2, #7 */
/* @0xcd258 str r2, [r6, #0xc] */
/* @0xcd25c str r3, [r6] */
/* @0xcd260 add sp, sp, #8 */
/* @0xcd264 pop {r4, r5, r6, r7, r8, pc} */
/* @0xcd268 ldm sp, {r2, r3} */
/* @0xcd26c stm r6, {r2, r3} */
/* @0xcd270 b 0xcd1f0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xc8> */
/* @0xcd274 vldr s15, [sp] */
/* @0xcd278 vcvt.f64.f32 d6, s15 */
/* @0xcd27c vmov r2, r3, d6 */
/* @0xcd280 stm r6, {r2, r3} */
/* @0xcd284 b 0xcd1f0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xc8> */
/* @0xcd288 ldr r3, [sp] */
/* @0xcd28c mov r2, #7 */
/* @0xcd290 str r2, [r6, #0xc] */
/* @0xcd294 str r3, [r6] */
/* @0xcd298 b 0xcd1f0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xc8> */
/* @0xcd29c ldr r3, [sp] */
/* @0xcd2a0 mov r1, #10 */
/* @0xcd2a4 mov r2, #0 */
/* @0xcd2a8 str r1, [r6, #0xc] */
/* @0xcd2ac str r2, [r6, #0x4] */
/* @0xcd2b0 str r3, [r6] */
/* @0xcd2b4 b 0xcd1f0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xc8> */
/* @0xcd2b8 ldrsh r3, [sp] */
/* @0xcd2bc mov r2, #7 */
/* @0xcd2c0 str r2, [r6, #0xc] */
/* @0xcd2c4 str r3, [r6] */
/* @0xcd2c8 b 0xcd1f0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xc8> */
/* @0xcd2cc ldrh r3, [sp] */
/* @0xcd2d0 mov r2, #7 */
/* @0xcd2d4 str r2, [r6, #0xc] */
/* @0xcd2d8 str r3, [r6] */
/* @0xcd2dc b 0xcd1f0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xc8> */
/* @0xcd2e0 ldrsb r3, [sp] */
/* @0xcd2e4 mov r2, #7 */
/* @0xcd2e8 str r2, [r6, #0xc] */
/* @0xcd2ec str r3, [r6] */
/* @0xcd2f0 b 0xcd1f0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xc8> */
/* @0xcd2f4 mov r3, #0 */
/* @0xcd2f8 str r3, [r6] */
/* @0xcd2fc str r3, [r6, #0x4] */
/* @0xcd300 b 0xcd1f0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xc8> */
