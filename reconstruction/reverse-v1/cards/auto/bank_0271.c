/* libyoyo.so 覆盖卡组 0271
 * 函数 0x2cbd48..0x2cc6e0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2cbd48 · b2World::RayCast(b2RayCastCallback*, b2Vec2 const&, b2Vec2 const&) const · size=112 · insn=28 */
/* @0x2cbd48 push {r4, r5, r6, r7, lr} */
/* @0x2cbd4c mov r6, r1 */
/* @0x2cbd50 sub sp, sp, #36 */
/* @0x2cbd54 add r7, r0, #102400 */
/* @0x2cbd58 ldm r2, {r0, r1} */
/* @0x2cbd5c mov r5, r3 */
/* @0x2cbd60 add r3, sp, #12 */
/* @0x2cbd64 add r12, r7, #472 */
/* @0x2cbd68 mov r4, r2 */
/* @0x2cbd6c mov lr, #1065353216 */
/* @0x2cbd70 stm r3, {r0, r1} */
/* @0x2cbd74 mov r2, r3 */
/* @0x2cbd78 ldm r5, {r0, r1} */
/* @0x2cbd7c add r3, sp, #20 */
/* @0x2cbd80 str r12, [sp, #0x4] */
/* @0x2cbd84 str lr, [sp, #0x1c] */
/* @0x2cbd88 stm r3, {r0, r1} */
/* @0x2cbd8c mov r0, r12 */
/* @0x2cbd90 add r1, sp, #4 */
/* @0x2cbd94 str r6, [sp, #0x8] */
/* @0x2cbd98 bl 0x2cb8e0 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput> */
/* @0x2cbd9c add r0, r7, #628 */
/* @0x2cbda0 mov r1, r6 */
/* @0x2cbda4 mov r2, r4 */
/* @0x2cbda8 mov r3, r5 */
/* @0x2cbdac bl 0x2d9c4c <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_> */
/* @0x2cbdb0 add sp, sp, #36 */
/* @0x2cbdb4 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2cbdb8 · b2ContactFilter::ShouldCollide(b2Fixture*, b2Fixture*) · size=84 · insn=21 */
/* @0x2cbdb8 ldrh r12, [r1, #40] */
/* @0x2cbdbc ldrsh r0, [r2, #40] */
/* @0x2cbdc0 sxth r3, r12 */
/* @0x2cbdc4 cmp r0, r3 */
/* @0x2cbdc8 beq 0x2cbdf4 <_ZN15b2ContactFilter13ShouldCollideEP9b2FixtureS1_+0x3c> */
/* @0x2cbdcc ldr r0, [r2, #0x20] */
/* @0x2cbdd0 ldr r3, [r1, #0x24] */
/* @0x2cbdd4 ands r0, r0, r3 */
/* @0x2cbdd8 bxeq lr */
/* @0x2cbddc ldr r2, [r2, #0x24] */
/* @0x2cbde0 ldr r3, [r1, #0x20] */
/* @0x2cbde4 tst r2, r3 */
/* @0x2cbde8 moveq r0, #0 */
/* @0x2cbdec movne r0, #1 */
/* @0x2cbdf0 bx lr */
/* @0x2cbdf4 cmp r12, #0 */
/* @0x2cbdf8 beq 0x2cbdcc <_ZN15b2ContactFilter13ShouldCollideEP9b2FixtureS1_+0x14> */
/* @0x2cbdfc cmp r0, #0 */
/* @0x2cbe00 movle r0, #0 */
/* @0x2cbe04 movgt r0, #1 */
/* @0x2cbe08 bx lr */

/* ── FUNC 0x2cbe0c · b2Contact::~b2Contact() · size=24 · insn=6 */
/* @0x2cbe0c ldr r3, [pc, #0xc] */
/* @0x2cbe10 ldr r3, [pc, r3] */
/* @0x2cbe14 add r3, r3, #8 */
/* @0x2cbe18 str r3, [r0] */
/* @0x2cbe1c bx lr */
/* @0x2cbe20 ldrsheq r5, [r2], -r0 */

/* ── FUNC 0x2cbe0c · b2Contact::~b2Contact() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2cbe24 · b2Contact::~b2Contact() · size=40 · insn=10 */
/* @0x2cbe24 ldr r3, [pc, #0x1c] */
/* @0x2cbe28 push {r4, lr} */
/* @0x2cbe2c ldr r3, [pc, r3] */
/* @0x2cbe30 mov r4, r0 */
/* @0x2cbe34 add r3, r3, #8 */
/* @0x2cbe38 str r3, [r0] */
/* @0x2cbe3c bl 0x27d1d0 <_ZdlPv> */
/* @0x2cbe40 mov r0, r4 */
/* @0x2cbe44 pop {r4, pc} */
/* @0x2cbe48 ldrsbeq r5, [r2], -r4 */

/* ── FUNC 0x2cbe4c · b2Contact::AddType(b2Contact* (*)(b2Fixture*, int, b2Fixture*, int, b2BlockAllocator*), void (*)(b2Contact*, b2BlockAllocator*), b2Shape::Type, b2Shape::Type) · size=96 · insn=24 */
/* @0x2cbe4c push {r4, r5} */
/* @0x2cbe50 add r4, r2, r2, lsl #1 */
/* @0x2cbe54 add r5, r3, r3, lsl #1 */
/* @0x2cbe58 ldr r12, [pc, #0x48] */
/* @0x2cbe5c cmp r2, r3 */
/* @0x2cbe60 lsl r2, r4, #4 */
/* @0x2cbe64 add r2, r2, r5, lsl #2 */
/* @0x2cbe68 ldr r12, [pc, r12] */
/* @0x2cbe6c add r3, r12, r2 */
/* @0x2cbe70 str r0, [r12, r2] */
/* @0x2cbe74 mov r2, #1 */
/* @0x2cbe78 str r1, [r3, #0x4] */
/* @0x2cbe7c strb r2, [r3, #0x8] */
/* @0x2cbe80 beq 0x2cbea0 <_ZN9b2Contact7AddTypeEPFPS_P9b2FixtureiS2_iP16b2BlockAllocatorEPFvS0_S4_EN7b2Shape4TypeESA_+0x54> */
/* @0x2cbe84 lsl r5, r5, #4 */
/* @0x2cbe88 mov r2, #0 */
/* @0x2cbe8c add r4, r5, r4, lsl #2 */
/* @0x2cbe90 add r3, r12, r4 */
/* @0x2cbe94 str r0, [r12, r4] */
/* @0x2cbe98 str r1, [r3, #0x4] */
/* @0x2cbe9c strb r2, [r3, #0x8] */
/* @0x2cbea0 pop {r4, r5} */
/* @0x2cbea4 bx lr */
/* @0x2cbea8 mulseq r2, r12, r12 */

/* ── FUNC 0x2cbeac · b2Contact::InitializeRegisters() · size=272 · insn=68 */
/* @0x2cbeac push {r4, lr} */
/* @0x2cbeb0 mov r2, #0 */
/* @0x2cbeb4 ldr r4, [pc, #0xc4] */
/* @0x2cbeb8 mov r3, r2 */
/* @0x2cbebc ldr r0, [pc, #0xc0] */
/* @0x2cbec0 ldr r1, [pc, #0xc0] */
/* @0x2cbec4 add r4, pc, r4 */
/* @0x2cbec8 ldr r0, [r4, r0] */
/* @0x2cbecc ldr r1, [r4, r1] */
/* @0x2cbed0 bl 0x2cbe4c <_ZN9b2Contact7AddTypeEPFPS_P9b2FixtureiS2_iP16b2BlockAllocatorEPFvS0_S4_EN7b2Shape4TypeESA_> */
/* @0x2cbed4 ldr r0, [pc, #0xb0] */
/* @0x2cbed8 ldr r1, [pc, #0xb0] */
/* @0x2cbedc mov r2, #2 */
/* @0x2cbee0 mov r3, #0 */
/* @0x2cbee4 ldr r0, [r4, r0] */
/* @0x2cbee8 ldr r1, [r4, r1] */
/* @0x2cbeec bl 0x2cbe4c <_ZN9b2Contact7AddTypeEPFPS_P9b2FixtureiS2_iP16b2BlockAllocatorEPFvS0_S4_EN7b2Shape4TypeESA_> */
/* @0x2cbef0 ldr r0, [pc, #0x9c] */
/* @0x2cbef4 ldr r1, [pc, #0x9c] */
/* @0x2cbef8 mov r2, #2 */
/* @0x2cbefc mov r3, r2 */
/* @0x2cbf00 ldr r0, [r4, r0] */
/* @0x2cbf04 ldr r1, [r4, r1] */
/* @0x2cbf08 bl 0x2cbe4c <_ZN9b2Contact7AddTypeEPFPS_P9b2FixtureiS2_iP16b2BlockAllocatorEPFvS0_S4_EN7b2Shape4TypeESA_> */
/* @0x2cbf0c ldr r0, [pc, #0x88] */
/* @0x2cbf10 ldr r1, [pc, #0x88] */
/* @0x2cbf14 mov r2, #1 */
/* @0x2cbf18 mov r3, #0 */
/* @0x2cbf1c ldr r0, [r4, r0] */
/* @0x2cbf20 ldr r1, [r4, r1] */
/* @0x2cbf24 bl 0x2cbe4c <_ZN9b2Contact7AddTypeEPFPS_P9b2FixtureiS2_iP16b2BlockAllocatorEPFvS0_S4_EN7b2Shape4TypeESA_> */
/* @0x2cbf28 ldr r0, [pc, #0x74] */
/* @0x2cbf2c ldr r1, [pc, #0x74] */
/* @0x2cbf30 mov r2, #1 */
/* @0x2cbf34 mov r3, #2 */
/* @0x2cbf38 ldr r0, [r4, r0] */
/* @0x2cbf3c ldr r1, [r4, r1] */
/* @0x2cbf40 bl 0x2cbe4c <_ZN9b2Contact7AddTypeEPFPS_P9b2FixtureiS2_iP16b2BlockAllocatorEPFvS0_S4_EN7b2Shape4TypeESA_> */
/* @0x2cbf44 ldr r0, [pc, #0x60] */
/* @0x2cbf48 ldr r1, [pc, #0x60] */
/* @0x2cbf4c mov r2, #3 */
/* @0x2cbf50 mov r3, #0 */
/* @0x2cbf54 ldr r0, [r4, r0] */
/* @0x2cbf58 ldr r1, [r4, r1] */
/* @0x2cbf5c bl 0x2cbe4c <_ZN9b2Contact7AddTypeEPFPS_P9b2FixtureiS2_iP16b2BlockAllocatorEPFvS0_S4_EN7b2Shape4TypeESA_> */
/* @0x2cbf60 ldr r0, [pc, #0x4c] */
/* @0x2cbf64 ldr r1, [pc, #0x4c] */
/* @0x2cbf68 mov r2, #3 */
/* @0x2cbf6c mov r3, #2 */
/* @0x2cbf70 ldr r0, [r4, r0] */
/* @0x2cbf74 ldr r1, [r4, r1] */
/* @0x2cbf78 pop {r4, lr} */
/* @0x2cbf7c b 0x2cbe4c <_ZN9b2Contact7AddTypeEPFPS_P9b2FixtureiS2_iP16b2BlockAllocatorEPFvS0_S4_EN7b2Shape4TypeESA_> */
/* @0x2cbf80 andseq r5, r2, r12, lsl #27 */
/* @0x2cbf84 .word 0xfffffeb8 */
/* @0x2cbf88 .word 0xfffffebc */
/* @0x2cbf8c .word 0xfffffec0 */
/* @0x2cbf90 .word 0xfffffec4 */
/* @0x2cbf94 .word 0xfffffec8 */
/* @0x2cbf98 .word 0xfffffecc */
/* @0x2cbf9c .word 0xfffffed0 */
/* @0x2cbfa0 .word 0xfffffed4 */
/* @0x2cbfa4 .word 0xfffffed8 */
/* @0x2cbfa8 .word 0xfffffedc */
/* @0x2cbfac .word 0xfffffee0 */
/* @0x2cbfb0 .word 0xfffffee4 */
/* @0x2cbfb4 .word 0xfffffee8 */
/* @0x2cbfb8 .word 0xfffffeec */

/* ── FUNC 0x2cbfbc · b2Contact::Create(b2Fixture*, int, b2Fixture*, int, b2BlockAllocator*) · size=192 · insn=48 */
/* @0x2cbfbc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2cbfc0 mov r10, r3 */
/* @0x2cbfc4 ldr r4, [pc, #0xa8] */
/* @0x2cbfc8 sub sp, sp, #8 */
/* @0x2cbfcc mov r7, r0 */
/* @0x2cbfd0 mov r9, r1 */
/* @0x2cbfd4 ldr r4, [pc, r4] */
/* @0x2cbfd8 mov r8, r2 */
/* @0x2cbfdc ldrb r3, [r4] */
/* @0x2cbfe0 cmp r3, #0 */
/* @0x2cbfe4 beq 0x2cc05c <_ZN9b2Contact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0xa0> */
/* @0x2cbfe8 ldr r2, [r7, #0xc] */
/* @0x2cbfec ldr r3, [r8, #0xc] */
/* @0x2cbff0 ldr r12, [pc, #0x80] */
/* @0x2cbff4 ldr r5, [r2, #0x4] */
/* @0x2cbff8 ldr r4, [r3, #0x4] */
/* @0x2cbffc ldr r12, [pc, r12] */
/* @0x2cc000 add r5, r5, r5, lsl #1 */
/* @0x2cc004 add r4, r4, r4, lsl #1 */
/* @0x2cc008 lsl r5, r5, #4 */
/* @0x2cc00c add r4, r5, r4, lsl #2 */
/* @0x2cc010 ldr r6, [r12, r4] */
/* @0x2cc014 cmp r6, #0 */
/* @0x2cc018 beq 0x2cc06c <_ZN9b2Contact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0xb0> */
/* @0x2cc01c add r12, r12, r4 */
/* @0x2cc020 ldrb r3, [r12, #0x8] */
/* @0x2cc024 cmp r3, #0 */
/* @0x2cc028 ldr r3, [sp, #0x28] */
/* @0x2cc02c movne r0, r7 */
/* @0x2cc030 movne r1, r9 */
/* @0x2cc034 str r3, [sp] */
/* @0x2cc038 movne r2, r8 */
/* @0x2cc03c movne r3, r10 */
/* @0x2cc040 moveq r0, r8 */
/* @0x2cc044 moveq r1, r10 */
/* @0x2cc048 moveq r2, r7 */
/* @0x2cc04c moveq r3, r9 */
/* @0x2cc050 blx r6 */
/* @0x2cc054 add sp, sp, #8 */
/* @0x2cc058 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2cc05c bl 0x2cbeac <_ZN9b2Contact19InitializeRegistersEv> */
/* @0x2cc060 mov r3, #1 */
/* @0x2cc064 strb r3, [r4] */
/* @0x2cc068 b 0x2cbfe8 <_ZN9b2Contact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0x2c> */
/* @0x2cc06c mov r0, r6 */
/* @0x2cc070 b 0x2cc054 <_ZN9b2Contact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0x98> */
/* @0x2cc074 andseq r5, r2, r12, ror #22 */
/* @0x2cc078 andseq r5, r2, r8, lsl #22 */

/* ── FUNC 0x2cc07c · b2Contact::Destroy(b2Contact*, b2BlockAllocator*) · size=164 · insn=41 */
/* @0x2cc07c ldr r2, [r0, #0x7c] */
/* @0x2cc080 push {r4, lr} */
/* @0x2cc084 cmp r2, #0 */
/* @0x2cc088 ldr r3, [r0, #0x30] */
/* @0x2cc08c ldr r2, [r0, #0x34] */
/* @0x2cc090 ble 0x2cc0e4 <_ZN9b2Contact7DestroyEPS_P16b2BlockAllocator+0x68> */
/* @0x2cc094 ldrb r12, [r3, #0x2c] */
/* @0x2cc098 cmp r12, #0 */
/* @0x2cc09c bne 0x2cc0e4 <_ZN9b2Contact7DestroyEPS_P16b2BlockAllocator+0x68> */
/* @0x2cc0a0 ldrb r12, [r2, #0x2c] */
/* @0x2cc0a4 cmp r12, #0 */
/* @0x2cc0a8 bne 0x2cc0e4 <_ZN9b2Contact7DestroyEPS_P16b2BlockAllocator+0x68> */
/* @0x2cc0ac ldr r12, [r3, #0x8] */
/* @0x2cc0b0 ldrh lr, [r12, #4] */
/* @0x2cc0b4 tst lr, #2 */
/* @0x2cc0b8 orreq lr, lr, #2 */
/* @0x2cc0bc moveq r4, #0 */
/* @0x2cc0c0 strheq lr, [r12, #4] */
/* @0x2cc0c4 streq r4, [r12, #0xa0] */
/* @0x2cc0c8 ldr r12, [r2, #0x8] */
/* @0x2cc0cc ldrh lr, [r12, #4] */
/* @0x2cc0d0 tst lr, #2 */
/* @0x2cc0d4 orreq lr, lr, #2 */
/* @0x2cc0d8 strheq lr, [r12, #4] */
/* @0x2cc0dc moveq r4, #0 */
/* @0x2cc0e0 streq r4, [r12, #0xa0] */
/* @0x2cc0e4 ldr r12, [r3, #0xc] */
/* @0x2cc0e8 ldr r2, [r2, #0xc] */
/* @0x2cc0ec ldr r3, [pc, #0x28] */
/* @0x2cc0f0 ldr r12, [r12, #0x4] */
/* @0x2cc0f4 ldr r2, [r2, #0x4] */
/* @0x2cc0f8 ldr r3, [pc, r3] */
/* @0x2cc0fc add r12, r12, r12, lsl #1 */
/* @0x2cc100 add r2, r2, r2, lsl #1 */
/* @0x2cc104 lsl r12, r12, #4 */
/* @0x2cc108 add r2, r12, r2, lsl #2 */
/* @0x2cc10c add r3, r3, r2 */
/* @0x2cc110 ldr r3, [r3, #0x4] */
/* @0x2cc114 blx r3 */
/* @0x2cc118 pop {r4, pc} */
/* @0x2cc11c andseq r5, r2, r12, lsl #20 */

/* ── FUNC 0x2cc120 · b2Contact::b2Contact(b2Fixture*, int, b2Fixture*, int) · size=204 · insn=51 */
/* @0x2cc120 vldr s15, [r3, #16] */
/* @0x2cc124 vldr s14, [r1, #16] */
/* @0x2cc128 vmul.f32 s14, s14, s15 */
/* @0x2cc12c ldr r12, [pc, #0xb4] */
/* @0x2cc130 push {r3, r4, r5, lr} */
/* @0x2cc134 ldr r12, [pc, r12] */
/* @0x2cc138 ldr r5, [sp, #0x10] */
/* @0x2cc13c add r12, r12, #8 */
/* @0x2cc140 str r3, [r0, #0x34] */
/* @0x2cc144 mov r4, r0 */
/* @0x2cc148 mov r3, #0 */
/* @0x2cc14c str r2, [r0, #0x38] */
/* @0x2cc150 str r1, [r0, #0x30] */
/* @0x2cc154 mov r2, #4 */
/* @0x2cc158 str r12, [r0] */
/* @0x2cc15c str r2, [r0, #0x4] */
/* @0x2cc160 str r5, [r0, #0x3c] */
/* @0x2cc164 str r3, [r0, #0x7c] */
/* @0x2cc168 str r3, [r0, #0x8] */
/* @0x2cc16c vsqrt.f32 s15, s14 */
/* @0x2cc170 str r3, [r0, #0xc] */
/* @0x2cc174 str r3, [r0, #0x14] */
/* @0x2cc178 str r3, [r0, #0x18] */
/* @0x2cc17c str r3, [r0, #0x1c] */
/* @0x2cc180 str r3, [r0, #0x10] */
/* @0x2cc184 str r3, [r0, #0x24] */
/* @0x2cc188 str r3, [r0, #0x28] */
/* @0x2cc18c str r3, [r0, #0x2c] */
/* @0x2cc190 str r3, [r0, #0x20] */
/* @0x2cc194 str r3, [r0, #0x80] */
/* @0x2cc198 vcmp.f32 s15, s15 */
/* @0x2cc19c vmrs APSR_nzcv, fpscr */
/* @0x2cc1a0 bne 0x2cc1d8 <_ZN9b2ContactC2EP9b2FixtureiS1_i+0xb8> */
/* @0x2cc1a4 ldr r3, [r4, #0x30] */
/* @0x2cc1a8 vldr s13, [r3, #20] */
/* @0x2cc1ac ldr r3, [r4, #0x34] */
/* @0x2cc1b0 vldr s14, [r3, #20] */
/* @0x2cc1b4 vcmpe.f32 s13, s14 */
/* @0x2cc1b8 mov r3, #0 */
/* @0x2cc1bc vstr s15, [r4, #136] */
/* @0x2cc1c0 mov r0, r4 */
/* @0x2cc1c4 str r3, [r4, #0x90] */
/* @0x2cc1c8 vmrs APSR_nzcv, fpscr */
/* @0x2cc1cc vmovgt.f32 s14, s13 */
/* @0x2cc1d0 vstr s14, [r4, #140] */
/* @0x2cc1d4 pop {r3, r4, r5, pc} */
/* @0x2cc1d8 vmov r0, s14 */
/* @0x2cc1dc bl 0xb6700 <sqrtf@plt> */
/* @0x2cc1e0 vmov s15, r0 */
/* @0x2cc1e4 b 0x2cc1a4 <_ZN9b2ContactC2EP9b2FixtureiS1_i+0x84> */
/* @0x2cc1e8 andseq r5, r2, r12, asr #19 */

/* ── FUNC 0x2cc120 · b2Contact::b2Contact(b2Fixture*, int, b2Fixture*, int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2cc1ec · b2Contact::Update(b2ContactListener*) · size=660 · insn=165 */
/* @0x2cc1ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2cc1f0 add r7, r0, #64 */
/* @0x2cc1f4 mov r8, r0 */
/* @0x2cc1f8 ldr r4, [r0, #0x4] */
/* @0x2cc1fc mov lr, r7 */
/* @0x2cc200 mov r9, r1 */
/* @0x2cc204 ldm lr!, {r0, r1, r2, r3} */
/* @0x2cc208 sub sp, sp, #108 */
/* @0x2cc20c add r12, sp, #40 */
/* @0x2cc210 orr r5, r4, #4 */
/* @0x2cc214 str r12, [sp, #0x14] */
/* @0x2cc218 ubfx r4, r4, #0x1, #0x1 */
/* @0x2cc21c str r4, [sp, #0x24] */
/* @0x2cc220 stm r12!, {r0, r1, r2, r3} */
/* @0x2cc224 ldm lr!, {r0, r1, r2, r3} */
/* @0x2cc228 stm r12!, {r0, r1, r2, r3} */
/* @0x2cc22c ldm lr!, {r0, r1, r2, r3} */
/* @0x2cc230 stm r12!, {r0, r1, r2, r3} */
/* @0x2cc234 ldm lr, {r0, r1, r2, r3} */
/* @0x2cc238 stm r12, {r0, r1, r2, r3} */
/* @0x2cc23c ldr r2, [r8, #0x30] */
/* @0x2cc240 str r5, [r8, #0x4] */
/* @0x2cc244 ldr r1, [r8, #0x34] */
/* @0x2cc248 ldr r12, [r2, #0x8] */
/* @0x2cc24c ldrb r3, [r2, #0x2c] */
/* @0x2cc250 ldrb r0, [r1, #0x2c] */
/* @0x2cc254 str r12, [sp, #0x1c] */
/* @0x2cc258 ldr r12, [r1, #0x8] */
/* @0x2cc25c orrs r3, r0, r3 */
/* @0x2cc260 str r3, [sp, #0x18] */
/* @0x2cc264 str r12, [sp, #0x20] */
/* @0x2cc268 ldr r12, [sp, #0x1c] */
/* @0x2cc26c add lr, r12, #12 */
/* @0x2cc270 ldr r12, [sp, #0x20] */
/* @0x2cc274 add r3, r12, #12 */
/* @0x2cc278 beq 0x2cc370 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x184> */
/* @0x2cc27c ldr r12, [r8, #0x3c] */
/* @0x2cc280 ldr r0, [r2, #0xc] */
/* @0x2cc284 ldr r2, [r1, #0xc] */
/* @0x2cc288 ldr r1, [r8, #0x38] */
/* @0x2cc28c str r3, [sp, #0x4] */
/* @0x2cc290 mov r3, r12 */
/* @0x2cc294 str lr, [sp] */
/* @0x2cc298 bl 0x2c3abc <_Z13b2TestOverlapPK7b2ShapeiS1_iRK11b2TransformS4_> */
/* @0x2cc29c mov r3, #0 */
/* @0x2cc2a0 str r3, [r8, #0x7c] */
/* @0x2cc2a4 mov r12, r0 */
/* @0x2cc2a8 cmp r12, #0 */
/* @0x2cc2ac ldr r7, [sp, #0x24] */
/* @0x2cc2b0 beq 0x2cc31c <_ZN9b2Contact6UpdateEP17b2ContactListener+0x130> */
/* @0x2cc2b4 ldr r3, [r8, #0x4] */
/* @0x2cc2b8 cmp r7, #0 */
/* @0x2cc2bc orr r3, r3, #2 */
/* @0x2cc2c0 str r3, [r8, #0x4] */
/* @0x2cc2c4 bne 0x2cc330 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x144> */
/* @0x2cc2c8 cmp r9, #0 */
/* @0x2cc2cc beq 0x2cc314 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x128> */
/* @0x2cc2d0 ldr r3, [r9] */
/* @0x2cc2d4 mov r0, r9 */
/* @0x2cc2d8 mov r1, r8 */
/* @0x2cc2dc ldr r3, [r3, #0x8] */
/* @0x2cc2e0 str r12, [sp, #0x10] */
/* @0x2cc2e4 blx r3 */
/* @0x2cc2e8 ldr r7, [sp, #0x18] */
/* @0x2cc2ec ldr r12, [sp, #0x10] */
/* @0x2cc2f0 eor r3, r7, #1 */
/* @0x2cc2f4 tst r12, r3 */
/* @0x2cc2f8 beq 0x2cc314 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x128> */
/* @0x2cc2fc ldr r3, [r9] */
/* @0x2cc300 mov r1, r8 */
/* @0x2cc304 add r2, sp, #40 */
/* @0x2cc308 mov r0, r9 */
/* @0x2cc30c ldr r3, [r3, #0x10] */
/* @0x2cc310 blx r3 */
/* @0x2cc314 add sp, sp, #108 */
/* @0x2cc318 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2cc31c ldr r3, [r8, #0x4] */
/* @0x2cc320 cmp r7, #0 */
/* @0x2cc324 bic r3, r3, #2 */
/* @0x2cc328 str r3, [r8, #0x4] */
/* @0x2cc32c bne 0x2cc34c <_ZN9b2Contact6UpdateEP17b2ContactListener+0x160> */
/* @0x2cc330 ldr r7, [sp, #0x18] */
/* @0x2cc334 eor r3, r7, #1 */
/* @0x2cc338 tst r12, r3 */
/* @0x2cc33c beq 0x2cc314 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x128> */
/* @0x2cc340 cmp r9, #0 */
/* @0x2cc344 bne 0x2cc2fc <_ZN9b2Contact6UpdateEP17b2ContactListener+0x110> */
/* @0x2cc348 b 0x2cc314 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x128> */
/* @0x2cc34c cmp r9, #0 */
/* @0x2cc350 beq 0x2cc314 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x128> */
/* @0x2cc354 ldr r3, [r9] */
/* @0x2cc358 mov r1, r8 */
/* @0x2cc35c mov r0, r9 */
/* @0x2cc360 ldr r3, [r3, #0xc] */
/* @0x2cc364 blx r3 */
/* @0x2cc368 add sp, sp, #108 */
/* @0x2cc36c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2cc370 ldr r12, [r8] */
/* @0x2cc374 mov r2, lr */
/* @0x2cc378 mov r0, r8 */
/* @0x2cc37c mov r1, r7 */
/* @0x2cc380 ldr r12, [r12] */
/* @0x2cc384 blx r12 */
/* @0x2cc388 ldr r10, [r8, #0x7c] */
/* @0x2cc38c cmp r10, #0 */
/* @0x2cc390 movle r12, #0 */
/* @0x2cc394 movgt r12, #1 */
/* @0x2cc398 cmp r12, #0 */
/* @0x2cc39c beq 0x2cc414 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x228> */
/* @0x2cc3a0 ldr r5, [sp, #0x64] */
/* @0x2cc3a4 add r0, r8, #84 */
/* @0x2cc3a8 ldr r11, [sp, #0x38] */
/* @0x2cc3ac vldr s15, [pc, #200] */
/* @0x2cc3b0 ldr r1, [sp, #0x18] */
/* @0x2cc3b4 cmp r5, #0 */
/* @0x2cc3b8 vstr s15, [r7, #8] */
/* @0x2cc3bc vstr s15, [r7, #12] */
/* @0x2cc3c0 ldr r4, [r7, #0x10] */
/* @0x2cc3c4 ble 0x2cc400 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x214> */
/* @0x2cc3c8 cmp r11, r4 */
/* @0x2cc3cc strne r7, [sp, #0xc] */
/* @0x2cc3d0 addne r3, sp, #60 */
/* @0x2cc3d4 movne r2, #0 */
/* @0x2cc3d8 bne 0x2cc3ec <_ZN9b2Contact6UpdateEP17b2ContactListener+0x200> */
/* @0x2cc3dc b 0x2cc474 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x288> */
/* @0x2cc3e0 ldr r7, [r3, #-0x4] */
/* @0x2cc3e4 cmp r7, r4 */
/* @0x2cc3e8 beq 0x2cc45c <_ZN9b2Contact6UpdateEP17b2ContactListener+0x270> */
/* @0x2cc3ec add r2, r2, #1 */
/* @0x2cc3f0 mov r6, r3 */
/* @0x2cc3f4 cmp r2, r5 */
/* @0x2cc3f8 add r3, r3, #20 */
/* @0x2cc3fc bne 0x2cc3e0 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x1f4> */
/* @0x2cc400 add r1, r1, #1 */
/* @0x2cc404 cmp r10, r1 */
/* @0x2cc408 movgt r7, r0 */
/* @0x2cc40c addgt r0, r0, #20 */
/* @0x2cc410 bgt 0x2cc3b4 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x1c8> */
/* @0x2cc414 ldr r7, [sp, #0x24] */
/* @0x2cc418 cmp r12, r7 */
/* @0x2cc41c beq 0x2cc2a8 <_ZN9b2Contact6UpdateEP17b2ContactListener+0xbc> */
/* @0x2cc420 ldr r7, [sp, #0x1c] */
/* @0x2cc424 ldrh r3, [r7, #4] */
/* @0x2cc428 tst r3, #2 */
/* @0x2cc42c orreq r3, r3, #2 */
/* @0x2cc430 strheq r3, [r7, #4] */
/* @0x2cc434 moveq r2, #0 */
/* @0x2cc438 streq r2, [r7, #0xa0] */
/* @0x2cc43c ldr r7, [sp, #0x20] */
/* @0x2cc440 ldrh r3, [r7, #4] */
/* @0x2cc444 tst r3, #2 */
/* @0x2cc448 orreq r3, r3, #2 */
/* @0x2cc44c strheq r3, [r7, #4] */
/* @0x2cc450 moveq r2, #0 */
/* @0x2cc454 streq r2, [r7, #0xa0] */
/* @0x2cc458 b 0x2cc2a8 <_ZN9b2Contact6UpdateEP17b2ContactListener+0xbc> */
/* @0x2cc45c ldr r7, [sp, #0xc] */
/* @0x2cc460 ldr r2, [r6, #0x8] */
/* @0x2cc464 ldr r3, [r6, #0xc] */
/* @0x2cc468 str r2, [r7, #0x8] */
/* @0x2cc46c str r3, [r7, #0xc] */
/* @0x2cc470 b 0x2cc400 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x214> */
/* @0x2cc474 add r6, sp, #40 */
/* @0x2cc478 b 0x2cc460 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x274> */
/* @0x2cc47c andeq r0, r0, r0 */

/* ── FUNC 0x2cc480 · b2EdgeAndCircleContact::~b2EdgeAndCircleContact() · size=24 · insn=6 */
/* @0x2cc480 ldr r3, [pc, #0xc] */
/* @0x2cc484 ldr r3, [pc, r3] */
/* @0x2cc488 add r3, r3, #8 */
/* @0x2cc48c str r3, [r0] */
/* @0x2cc490 bx lr */
/* @0x2cc494 andseq r5, r2, r12, ror r6 */

/* ── FUNC 0x2cc480 · b2EdgeAndCircleContact::~b2EdgeAndCircleContact() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2cc498 · b2EdgeAndCircleContact::~b2EdgeAndCircleContact() · size=40 · insn=10 */
/* @0x2cc498 ldr r3, [pc, #0x1c] */
/* @0x2cc49c push {r4, lr} */
/* @0x2cc4a0 ldr r3, [pc, r3] */
/* @0x2cc4a4 mov r4, r0 */
/* @0x2cc4a8 add r3, r3, #8 */
/* @0x2cc4ac str r3, [r0] */
/* @0x2cc4b0 bl 0x27d1d0 <_ZdlPv> */
/* @0x2cc4b4 mov r0, r4 */
/* @0x2cc4b8 pop {r4, pc} */
/* @0x2cc4bc andseq r5, r2, r0, ror #12 */

/* ── FUNC 0x2cc4c0 · b2EdgeAndCircleContact::Evaluate(b2Manifold*, b2Transform const&, b2Transform const&) · size=52 · insn=13 */
/* @0x2cc4c0 mov r12, r0 */
/* @0x2cc4c4 mov r0, r1 */
/* @0x2cc4c8 ldr r1, [r12, #0x30] */
/* @0x2cc4cc ldr r12, [r12, #0x34] */
/* @0x2cc4d0 str lr, [sp, #-0x4]! */
/* @0x2cc4d4 sub sp, sp, #12 */
/* @0x2cc4d8 ldr r12, [r12, #0xc] */
/* @0x2cc4dc ldr r1, [r1, #0xc] */
/* @0x2cc4e0 str r3, [sp] */
/* @0x2cc4e4 mov r3, r12 */
/* @0x2cc4e8 bl 0x2dceb0 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_> */
/* @0x2cc4ec add sp, sp, #12 */
/* @0x2cc4f0 ldr pc, [sp], #4 */

/* ── FUNC 0x2cc4f4 · b2EdgeAndCircleContact::Destroy(b2Contact*, b2BlockAllocator*) · size=44 · insn=11 */
/* @0x2cc4f4 push {r3, r4, r5, lr} */
/* @0x2cc4f8 mov r5, r1 */
/* @0x2cc4fc ldr r3, [r0] */
/* @0x2cc500 mov r4, r0 */
/* @0x2cc504 ldr r3, [r3, #0x4] */
/* @0x2cc508 blx r3 */
/* @0x2cc50c mov r0, r5 */
/* @0x2cc510 mov r1, r4 */
/* @0x2cc514 mov r2, #148 */
/* @0x2cc518 pop {r3, r4, r5, lr} */
/* @0x2cc51c b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */

/* ── FUNC 0x2cc520 · b2EdgeAndCircleContact::b2EdgeAndCircleContact(b2Fixture*, b2Fixture*) · size=60 · insn=15 */
/* @0x2cc520 push {r4, lr} */
/* @0x2cc524 sub sp, sp, #8 */
/* @0x2cc528 mov r3, r2 */
/* @0x2cc52c mov r2, #0 */
/* @0x2cc530 str r2, [sp] */
/* @0x2cc534 mov r4, r0 */
/* @0x2cc538 bl 0x2cc120 <_ZN9b2ContactC2EP9b2FixtureiS1_i> */
/* @0x2cc53c ldr r3, [pc, #0x14] */
/* @0x2cc540 mov r0, r4 */
/* @0x2cc544 ldr r3, [pc, r3] */
/* @0x2cc548 add r3, r3, #8 */
/* @0x2cc54c str r3, [r4] */
/* @0x2cc550 add sp, sp, #8 */
/* @0x2cc554 pop {r4, pc} */
/* @0x2cc558 andseq r5, r2, r0, lsl #12 */

/* ── FUNC 0x2cc520 · b2EdgeAndCircleContact::b2EdgeAndCircleContact(b2Fixture*, b2Fixture*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2cc55c · b2EdgeAndCircleContact::Create(b2Fixture*, int, b2Fixture*, int, b2BlockAllocator*) · size=52 · insn=13 */
/* @0x2cc55c push {r4, r5, r6, lr} */
/* @0x2cc560 mov r1, #148 */
/* @0x2cc564 mov r5, r0 */
/* @0x2cc568 ldr r0, [sp, #0x10] */
/* @0x2cc56c mov r6, r2 */
/* @0x2cc570 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2cc574 subs r4, r0, #0 */
/* @0x2cc578 beq 0x2cc588 <_ZN22b2EdgeAndCircleContact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0x2c> */
/* @0x2cc57c mov r1, r5 */
/* @0x2cc580 mov r2, r6 */
/* @0x2cc584 bl 0x2cc520 <_ZN22b2EdgeAndCircleContactC2EP9b2FixtureS1_> */
/* @0x2cc588 mov r0, r4 */
/* @0x2cc58c pop {r4, r5, r6, pc} */

/* ── FUNC 0x2cc590 · b2EdgeAndPolygonContact::~b2EdgeAndPolygonContact() · size=24 · insn=6 */
/* @0x2cc590 ldr r3, [pc, #0xc] */
/* @0x2cc594 ldr r3, [pc, r3] */
/* @0x2cc598 add r3, r3, #8 */
/* @0x2cc59c str r3, [r0] */
/* @0x2cc5a0 bx lr */
/* @0x2cc5a4 andseq r5, r2, r12, ror #10 */

/* ── FUNC 0x2cc590 · b2EdgeAndPolygonContact::~b2EdgeAndPolygonContact() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2cc5a8 · b2EdgeAndPolygonContact::~b2EdgeAndPolygonContact() · size=40 · insn=10 */
/* @0x2cc5a8 ldr r3, [pc, #0x1c] */
/* @0x2cc5ac push {r4, lr} */
/* @0x2cc5b0 ldr r3, [pc, r3] */
/* @0x2cc5b4 mov r4, r0 */
/* @0x2cc5b8 add r3, r3, #8 */
/* @0x2cc5bc str r3, [r0] */
/* @0x2cc5c0 bl 0x27d1d0 <_ZdlPv> */
/* @0x2cc5c4 mov r0, r4 */
/* @0x2cc5c8 pop {r4, pc} */
/* @0x2cc5cc andseq r5, r2, r0, asr r5 */

/* ── FUNC 0x2cc5d0 · b2EdgeAndPolygonContact::Evaluate(b2Manifold*, b2Transform const&, b2Transform const&) · size=52 · insn=13 */
/* @0x2cc5d0 mov r12, r0 */
/* @0x2cc5d4 mov r0, r1 */
/* @0x2cc5d8 ldr r1, [r12, #0x30] */
/* @0x2cc5dc ldr r12, [r12, #0x34] */
/* @0x2cc5e0 str lr, [sp, #-0x4]! */
/* @0x2cc5e4 sub sp, sp, #12 */
/* @0x2cc5e8 ldr r12, [r12, #0xc] */
/* @0x2cc5ec ldr r1, [r1, #0xc] */
/* @0x2cc5f0 str r3, [sp] */
/* @0x2cc5f4 mov r3, r12 */
/* @0x2cc5f8 bl 0x2de0bc <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_> */
/* @0x2cc5fc add sp, sp, #12 */
/* @0x2cc600 ldr pc, [sp], #4 */

/* ── FUNC 0x2cc604 · b2EdgeAndPolygonContact::Destroy(b2Contact*, b2BlockAllocator*) · size=44 · insn=11 */
/* @0x2cc604 push {r3, r4, r5, lr} */
/* @0x2cc608 mov r5, r1 */
/* @0x2cc60c ldr r3, [r0] */
/* @0x2cc610 mov r4, r0 */
/* @0x2cc614 ldr r3, [r3, #0x4] */
/* @0x2cc618 blx r3 */
/* @0x2cc61c mov r0, r5 */
/* @0x2cc620 mov r1, r4 */
/* @0x2cc624 mov r2, #148 */
/* @0x2cc628 pop {r3, r4, r5, lr} */
/* @0x2cc62c b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */

/* ── FUNC 0x2cc630 · b2EdgeAndPolygonContact::b2EdgeAndPolygonContact(b2Fixture*, b2Fixture*) · size=60 · insn=15 */
/* @0x2cc630 push {r4, lr} */
/* @0x2cc634 sub sp, sp, #8 */
/* @0x2cc638 mov r3, r2 */
/* @0x2cc63c mov r2, #0 */
/* @0x2cc640 str r2, [sp] */
/* @0x2cc644 mov r4, r0 */
/* @0x2cc648 bl 0x2cc120 <_ZN9b2ContactC2EP9b2FixtureiS1_i> */
/* @0x2cc64c ldr r3, [pc, #0x14] */
/* @0x2cc650 mov r0, r4 */
/* @0x2cc654 ldr r3, [pc, r3] */
/* @0x2cc658 add r3, r3, #8 */
/* @0x2cc65c str r3, [r4] */
/* @0x2cc660 add sp, sp, #8 */
/* @0x2cc664 pop {r4, pc} */
/* @0x2cc668 ldrsheq r5, [r2], -r4 */

/* ── FUNC 0x2cc630 · b2EdgeAndPolygonContact::b2EdgeAndPolygonContact(b2Fixture*, b2Fixture*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2cc66c · b2EdgeAndPolygonContact::Create(b2Fixture*, int, b2Fixture*, int, b2BlockAllocator*) · size=52 · insn=13 */
/* @0x2cc66c push {r4, r5, r6, lr} */
/* @0x2cc670 mov r1, #148 */
/* @0x2cc674 mov r5, r0 */
/* @0x2cc678 ldr r0, [sp, #0x10] */
/* @0x2cc67c mov r6, r2 */
/* @0x2cc680 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2cc684 subs r4, r0, #0 */
/* @0x2cc688 beq 0x2cc698 <_ZN23b2EdgeAndPolygonContact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0x2c> */
/* @0x2cc68c mov r1, r5 */
/* @0x2cc690 mov r2, r6 */
/* @0x2cc694 bl 0x2cc630 <_ZN23b2EdgeAndPolygonContactC2EP9b2FixtureS1_> */
/* @0x2cc698 mov r0, r4 */
/* @0x2cc69c pop {r4, r5, r6, pc} */

/* ── FUNC 0x2cc6a0 · b2PolygonAndCircleContact::~b2PolygonAndCircleContact() · size=24 · insn=6 */
/* @0x2cc6a0 ldr r3, [pc, #0xc] */
/* @0x2cc6a4 ldr r3, [pc, r3] */
/* @0x2cc6a8 add r3, r3, #8 */
/* @0x2cc6ac str r3, [r0] */
/* @0x2cc6b0 bx lr */
/* @0x2cc6b4 andseq r5, r2, r12, asr r4 */

/* ── FUNC 0x2cc6a0 · b2PolygonAndCircleContact::~b2PolygonAndCircleContact() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2cc6b8 · b2PolygonAndCircleContact::~b2PolygonAndCircleContact() · size=40 · insn=10 */
/* @0x2cc6b8 ldr r3, [pc, #0x1c] */
/* @0x2cc6bc push {r4, lr} */
/* @0x2cc6c0 ldr r3, [pc, r3] */
/* @0x2cc6c4 mov r4, r0 */
/* @0x2cc6c8 add r3, r3, #8 */
/* @0x2cc6cc str r3, [r0] */
/* @0x2cc6d0 bl 0x27d1d0 <_ZdlPv> */
/* @0x2cc6d4 mov r0, r4 */
/* @0x2cc6d8 pop {r4, pc} */
/* @0x2cc6dc andseq r5, r2, r0, asr #8 */

/* ── FUNC 0x2cc6e0 · b2PolygonAndCircleContact::Evaluate(b2Manifold*, b2Transform const&, b2Transform const&) · size=52 · insn=13 */
/* @0x2cc6e0 mov r12, r0 */
/* @0x2cc6e4 mov r0, r1 */
/* @0x2cc6e8 ldr r1, [r12, #0x30] */
/* @0x2cc6ec ldr r12, [r12, #0x34] */
/* @0x2cc6f0 str lr, [sp, #-0x4]! */
/* @0x2cc6f4 sub sp, sp, #12 */
/* @0x2cc6f8 ldr r12, [r12, #0xc] */
/* @0x2cc6fc ldr r1, [r1, #0xc] */
/* @0x2cc700 str r3, [sp] */
/* @0x2cc704 mov r3, r12 */
/* @0x2cc708 bl 0x2dcad0 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_> */
/* @0x2cc70c add sp, sp, #12 */
/* @0x2cc710 ldr pc, [sp], #4 */
