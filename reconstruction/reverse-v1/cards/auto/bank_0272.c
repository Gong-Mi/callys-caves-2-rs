/* libyoyo.so 覆盖卡组 0272
 * 函数 0x2cc714..0x2cd320，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2cc714 · b2PolygonAndCircleContact::Destroy(b2Contact*, b2BlockAllocator*) · size=44 · insn=11 */
/* @0x2cc714 push {r3, r4, r5, lr} */
/* @0x2cc718 mov r5, r1 */
/* @0x2cc71c ldr r3, [r0] */
/* @0x2cc720 mov r4, r0 */
/* @0x2cc724 ldr r3, [r3, #0x4] */
/* @0x2cc728 blx r3 */
/* @0x2cc72c mov r0, r5 */
/* @0x2cc730 mov r1, r4 */
/* @0x2cc734 mov r2, #148 */
/* @0x2cc738 pop {r3, r4, r5, lr} */
/* @0x2cc73c b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */

/* ── FUNC 0x2cc740 · b2PolygonAndCircleContact::b2PolygonAndCircleContact(b2Fixture*, b2Fixture*) · size=60 · insn=15 */
/* @0x2cc740 push {r4, lr} */
/* @0x2cc744 sub sp, sp, #8 */
/* @0x2cc748 mov r3, r2 */
/* @0x2cc74c mov r2, #0 */
/* @0x2cc750 str r2, [sp] */
/* @0x2cc754 mov r4, r0 */
/* @0x2cc758 bl 0x2cc120 <_ZN9b2ContactC2EP9b2FixtureiS1_i> */
/* @0x2cc75c ldr r3, [pc, #0x14] */
/* @0x2cc760 mov r0, r4 */
/* @0x2cc764 ldr r3, [pc, r3] */
/* @0x2cc768 add r3, r3, #8 */
/* @0x2cc76c str r3, [r4] */
/* @0x2cc770 add sp, sp, #8 */
/* @0x2cc774 pop {r4, pc} */
/* @0x2cc778 andseq r5, r2, r8, ror #7 */

/* ── FUNC 0x2cc740 · b2PolygonAndCircleContact::b2PolygonAndCircleContact(b2Fixture*, b2Fixture*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2cc77c · b2PolygonAndCircleContact::Create(b2Fixture*, int, b2Fixture*, int, b2BlockAllocator*) · size=52 · insn=13 */
/* @0x2cc77c push {r4, r5, r6, lr} */
/* @0x2cc780 mov r1, #148 */
/* @0x2cc784 mov r5, r0 */
/* @0x2cc788 ldr r0, [sp, #0x10] */
/* @0x2cc78c mov r6, r2 */
/* @0x2cc790 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2cc794 subs r4, r0, #0 */
/* @0x2cc798 beq 0x2cc7a8 <_ZN25b2PolygonAndCircleContact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0x2c> */
/* @0x2cc79c mov r1, r5 */
/* @0x2cc7a0 mov r2, r6 */
/* @0x2cc7a4 bl 0x2cc740 <_ZN25b2PolygonAndCircleContactC2EP9b2FixtureS1_> */
/* @0x2cc7a8 mov r0, r4 */
/* @0x2cc7ac pop {r4, r5, r6, pc} */

/* ── FUNC 0x2cc7b0 · b2PolygonContact::~b2PolygonContact() · size=24 · insn=6 */
/* @0x2cc7b0 ldr r3, [pc, #0xc] */
/* @0x2cc7b4 ldr r3, [pc, r3] */
/* @0x2cc7b8 add r3, r3, #8 */
/* @0x2cc7bc str r3, [r0] */
/* @0x2cc7c0 bx lr */
/* @0x2cc7c4 andseq r5, r2, r12, asr #6 */

/* ── FUNC 0x2cc7b0 · b2PolygonContact::~b2PolygonContact() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2cc7c8 · b2PolygonContact::~b2PolygonContact() · size=40 · insn=10 */
/* @0x2cc7c8 ldr r3, [pc, #0x1c] */
/* @0x2cc7cc push {r4, lr} */
/* @0x2cc7d0 ldr r3, [pc, r3] */
/* @0x2cc7d4 mov r4, r0 */
/* @0x2cc7d8 add r3, r3, #8 */
/* @0x2cc7dc str r3, [r0] */
/* @0x2cc7e0 bl 0x27d1d0 <_ZdlPv> */
/* @0x2cc7e4 mov r0, r4 */
/* @0x2cc7e8 pop {r4, pc} */
/* @0x2cc7ec andseq r5, r2, r0, lsr r3 */

/* ── FUNC 0x2cc7f0 · b2PolygonContact::Evaluate(b2Manifold*, b2Transform const&, b2Transform const&) · size=52 · insn=13 */
/* @0x2cc7f0 mov r12, r0 */
/* @0x2cc7f4 mov r0, r1 */
/* @0x2cc7f8 ldr r1, [r12, #0x30] */
/* @0x2cc7fc ldr r12, [r12, #0x34] */
/* @0x2cc800 str lr, [sp, #-0x4]! */
/* @0x2cc804 sub sp, sp, #12 */
/* @0x2cc808 ldr r12, [r12, #0xc] */
/* @0x2cc80c ldr r1, [r1, #0xc] */
/* @0x2cc810 str r3, [sp] */
/* @0x2cc814 mov r3, r12 */
/* @0x2cc818 bl 0x2de464 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_> */
/* @0x2cc81c add sp, sp, #12 */
/* @0x2cc820 ldr pc, [sp], #4 */

/* ── FUNC 0x2cc824 · b2PolygonContact::Destroy(b2Contact*, b2BlockAllocator*) · size=44 · insn=11 */
/* @0x2cc824 push {r3, r4, r5, lr} */
/* @0x2cc828 mov r5, r1 */
/* @0x2cc82c ldr r3, [r0] */
/* @0x2cc830 mov r4, r0 */
/* @0x2cc834 ldr r3, [r3, #0x4] */
/* @0x2cc838 blx r3 */
/* @0x2cc83c mov r0, r5 */
/* @0x2cc840 mov r1, r4 */
/* @0x2cc844 mov r2, #148 */
/* @0x2cc848 pop {r3, r4, r5, lr} */
/* @0x2cc84c b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */

/* ── FUNC 0x2cc850 · b2PolygonContact::b2PolygonContact(b2Fixture*, b2Fixture*) · size=60 · insn=15 */
/* @0x2cc850 push {r4, lr} */
/* @0x2cc854 sub sp, sp, #8 */
/* @0x2cc858 mov r3, r2 */
/* @0x2cc85c mov r2, #0 */
/* @0x2cc860 str r2, [sp] */
/* @0x2cc864 mov r4, r0 */
/* @0x2cc868 bl 0x2cc120 <_ZN9b2ContactC2EP9b2FixtureiS1_i> */
/* @0x2cc86c ldr r3, [pc, #0x14] */
/* @0x2cc870 mov r0, r4 */
/* @0x2cc874 ldr r3, [pc, r3] */
/* @0x2cc878 add r3, r3, #8 */
/* @0x2cc87c str r3, [r4] */
/* @0x2cc880 add sp, sp, #8 */
/* @0x2cc884 pop {r4, pc} */
/* @0x2cc888 ldrsbeq r5, [r2], -r12 */

/* ── FUNC 0x2cc850 · b2PolygonContact::b2PolygonContact(b2Fixture*, b2Fixture*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2cc88c · b2PolygonContact::Create(b2Fixture*, int, b2Fixture*, int, b2BlockAllocator*) · size=52 · insn=13 */
/* @0x2cc88c push {r4, r5, r6, lr} */
/* @0x2cc890 mov r1, #148 */
/* @0x2cc894 mov r5, r0 */
/* @0x2cc898 ldr r0, [sp, #0x10] */
/* @0x2cc89c mov r6, r2 */
/* @0x2cc8a0 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2cc8a4 subs r4, r0, #0 */
/* @0x2cc8a8 beq 0x2cc8b8 <_ZN16b2PolygonContact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0x2c> */
/* @0x2cc8ac mov r1, r5 */
/* @0x2cc8b0 mov r2, r6 */
/* @0x2cc8b4 bl 0x2cc850 <_ZN16b2PolygonContactC2EP9b2FixtureS1_> */
/* @0x2cc8b8 mov r0, r4 */
/* @0x2cc8bc pop {r4, r5, r6, pc} */

/* ── FUNC 0x2cc8c0 · b2Joint::ShiftOrigin(b2Vec2 const&) · size=4 · insn=1 */
/* @0x2cc8c0 bx lr */

/* ── FUNC 0x2cc8c4 · b2Joint::~b2Joint() · size=24 · insn=6 */
/* @0x2cc8c4 ldr r3, [pc, #0xc] */
/* @0x2cc8c8 ldr r3, [pc, r3] */
/* @0x2cc8cc add r3, r3, #8 */
/* @0x2cc8d0 str r3, [r0] */
/* @0x2cc8d4 bx lr */
/* @0x2cc8d8 andseq r5, r2, r12, lsl #5 */

/* ── FUNC 0x2cc8c4 · b2Joint::~b2Joint() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2cc8dc · b2DistanceJoint::SolveVelocityConstraints(b2SolverData const&) · size=260 · insn=65 */
/* @0x2cc8dc ldr r2, [r0, #0x6c] */
/* @0x2cc8e0 vpush {d8, d9, d10, d11} */
/* @0x2cc8e4 ldr r3, [r0, #0x70] */
/* @0x2cc8e8 vldr s16, [r0, #124] */
/* @0x2cc8ec ldr r1, [r1, #0x1c] */
/* @0x2cc8f0 vldr s0, [r0, #132] */
/* @0x2cc8f4 add r2, r2, r2, lsl #1 */
/* @0x2cc8f8 vldr s11, [r0, #136] */
/* @0x2cc8fc add r3, r3, r3, lsl #1 */
/* @0x2cc900 vldr s10, [r0, #128] */
/* @0x2cc904 add r2, r1, r2, lsl #2 */
/* @0x2cc908 vldr s2, [r2, #4] */
/* @0x2cc90c add r3, r1, r3, lsl #2 */
/* @0x2cc910 vmov.f32 s8, s2 */
/* @0x2cc914 vldr s6, [r3, #4] */
/* @0x2cc918 vldr s9, [r2, #8] */
/* @0x2cc91c vldr s12, [r3, #8] */
/* @0x2cc920 vldr s4, [r3] */
/* @0x2cc924 vldr s1, [r2] */
/* @0x2cc928 vldr s15, [r0, #120] */
/* @0x2cc92c vmov.f32 s23, s6 */
/* @0x2cc930 vldr s14, [r0, #116] */
/* @0x2cc934 vldr s20, [r0, #76] */
/* @0x2cc938 vldr s7, [r0, #100] */
/* @0x2cc93c vldr s19, [r0, #96] */
/* @0x2cc940 vldr s13, [r0, #172] */
/* @0x2cc944 vldr s18, [r0, #164] */
/* @0x2cc948 vldr s3, [r0, #156] */
/* @0x2cc94c vmla.f32 s8, s9, s16 */
/* @0x2cc950 vldr s5, [r0, #160] */
/* @0x2cc954 vldr s17, [r0, #168] */
/* @0x2cc958 vmla.f32 s23, s12, s0 */
/* @0x2cc95c vmov.f32 s22, s4 */
/* @0x2cc960 vmov.f32 s21, s1 */
/* @0x2cc964 vmls.f32 s22, s12, s11 */
/* @0x2cc968 vmls.f32 s21, s9, s10 */
/* @0x2cc96c vsub.f32 s8, s23, s8 */
/* @0x2cc970 vmul.f32 s8, s8, s15 */
/* @0x2cc974 vsub.f32 s21, s22, s21 */
/* @0x2cc978 vmla.f32 s8, s21, s14 */
/* @0x2cc97c vadd.f32 s8, s8, s20 */
/* @0x2cc980 vmla.f32 s8, s7, s19 */
/* @0x2cc984 vnmul.f32 s13, s13, s8 */
/* @0x2cc988 vmul.f32 s14, s13, s14 */
/* @0x2cc98c vmul.f32 s15, s13, s15 */
/* @0x2cc990 vmul.f32 s10, s10, s14 */
/* @0x2cc994 vmul.f32 s11, s11, s14 */
/* @0x2cc998 vnmls.f32 s10, s16, s15 */
/* @0x2cc99c vnmls.f32 s11, s0, s15 */
/* @0x2cc9a0 vmls.f32 s9, s10, s18 */
/* @0x2cc9a4 vmla.f32 s12, s11, s17 */
/* @0x2cc9a8 vpop {d8, d9, d10, d11} */
/* @0x2cc9ac vmls.f32 s1, s3, s14 */
/* @0x2cc9b0 vmls.f32 s2, s3, s15 */
/* @0x2cc9b4 vmla.f32 s4, s5, s14 */
/* @0x2cc9b8 vmla.f32 s6, s5, s15 */
/* @0x2cc9bc vadd.f32 s13, s7, s13 */
/* @0x2cc9c0 vstr s13, [r0, #100] */
/* @0x2cc9c4 vstr s9, [r2, #8] */
/* @0x2cc9c8 vstr s1, [r2] */
/* @0x2cc9cc vstr s2, [r2, #4] */
/* @0x2cc9d0 vstr s12, [r3, #8] */
/* @0x2cc9d4 vstr s4, [r3] */
/* @0x2cc9d8 vstr s6, [r3, #4] */
/* @0x2cc9dc bx lr */

/* ── FUNC 0x2cc9e0 · b2DistanceJoint::GetAnchorA() const · size=64 · insn=16 */
/* @0x2cc9e0 ldr r3, [r1, #0x30] */
/* @0x2cc9e4 vldr s15, [r1, #84] */
/* @0x2cc9e8 vldr s12, [r3, #24] */
/* @0x2cc9ec vldr s11, [r3, #20] */
/* @0x2cc9f0 vmul.f32 s14, s12, s15 */
/* @0x2cc9f4 vldr s13, [r1, #80] */
/* @0x2cc9f8 vldr s9, [r3, #16] */
/* @0x2cc9fc vldr s10, [r3, #12] */
/* @0x2cca00 vmul.f32 s15, s11, s15 */
/* @0x2cca04 vmla.f32 s14, s13, s11 */
/* @0x2cca08 vnmls.f32 s15, s12, s13 */
/* @0x2cca0c vadd.f32 s14, s14, s9 */
/* @0x2cca10 vadd.f32 s15, s15, s10 */
/* @0x2cca14 vstr s14, [r0, #4] */
/* @0x2cca18 vstr s15, [r0] */
/* @0x2cca1c bx lr */

/* ── FUNC 0x2cca20 · b2DistanceJoint::GetAnchorB() const · size=64 · insn=16 */
/* @0x2cca20 ldr r3, [r1, #0x34] */
/* @0x2cca24 vldr s15, [r1, #92] */
/* @0x2cca28 vldr s12, [r3, #24] */
/* @0x2cca2c vldr s11, [r3, #20] */
/* @0x2cca30 vmul.f32 s14, s12, s15 */
/* @0x2cca34 vldr s13, [r1, #88] */
/* @0x2cca38 vldr s9, [r3, #16] */
/* @0x2cca3c vldr s10, [r3, #12] */
/* @0x2cca40 vmul.f32 s15, s11, s15 */
/* @0x2cca44 vmla.f32 s14, s13, s11 */
/* @0x2cca48 vnmls.f32 s15, s12, s13 */
/* @0x2cca4c vadd.f32 s14, s14, s9 */
/* @0x2cca50 vadd.f32 s15, s15, s10 */
/* @0x2cca54 vstr s14, [r0, #4] */
/* @0x2cca58 vstr s15, [r0] */
/* @0x2cca5c bx lr */

/* ── FUNC 0x2cca60 · b2DistanceJoint::GetReactionForce(float) const · size=40 · insn=10 */
/* @0x2cca60 vmov s14, r2 */
/* @0x2cca64 vldr s15, [r1, #100] */
/* @0x2cca68 vldr s13, [r1, #116] */
/* @0x2cca6c vmul.f32 s15, s14, s15 */
/* @0x2cca70 vldr s14, [r1, #120] */
/* @0x2cca74 vmul.f32 s14, s15, s14 */
/* @0x2cca78 vmul.f32 s15, s15, s13 */
/* @0x2cca7c vstr s14, [r0, #4] */
/* @0x2cca80 vstr s15, [r0] */
/* @0x2cca84 bx lr */

/* ── FUNC 0x2cca88 · b2DistanceJoint::GetReactionTorque(float) const · size=8 · insn=2 */
/* @0x2cca88 mov r0, #0 */
/* @0x2cca8c bx lr */

/* ── FUNC 0x2cca90 · b2DistanceJoint::~b2DistanceJoint() · size=24 · insn=6 */
/* @0x2cca90 ldr r3, [pc, #0xc] */
/* @0x2cca94 ldr r3, [pc, r3] */
/* @0x2cca98 add r3, r3, #8 */
/* @0x2cca9c str r3, [r0] */
/* @0x2ccaa0 bx lr */
/* @0x2ccaa4 andseq r5, r2, r0, asr #1 */

/* ── FUNC 0x2cca90 · b2DistanceJoint::~b2DistanceJoint() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2ccaa8 · b2Joint::Dump() · size=16 · insn=4 */
/* @0x2ccaa8 ldr r0, [pc, #0x4] */
/* @0x2ccaac add r0, pc, r0 */
/* @0x2ccab0 b 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ccab4 strheq pc, [r8], -r4 */

/* ── FUNC 0x2ccab8 · b2DistanceJoint::Dump() · size=296 · insn=74 */
/* @0x2ccab8 push {r4, r5, r6, lr} */
/* @0x2ccabc mov r4, r0 */
/* @0x2ccac0 ldr r2, [r4, #0x30] */
/* @0x2ccac4 sub sp, sp, #8 */
/* @0x2ccac8 ldr r3, [r4, #0x34] */
/* @0x2ccacc ldr r0, [pc, #0xe4] */
/* @0x2ccad0 ldr r6, [r2, #0x8] */
/* @0x2ccad4 add r0, pc, r0 */
/* @0x2ccad8 ldr r5, [r3, #0x8] */
/* @0x2ccadc bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ccae0 ldr r0, [pc, #0xd4] */
/* @0x2ccae4 mov r1, r6 */
/* @0x2ccae8 add r0, pc, r0 */
/* @0x2ccaec bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ccaf0 ldr r0, [pc, #0xc8] */
/* @0x2ccaf4 mov r1, r5 */
/* @0x2ccaf8 add r0, pc, r0 */
/* @0x2ccafc bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ccb00 ldr r0, [pc, #0xbc] */
/* @0x2ccb04 ldrb r1, [r4, #0x3d] */
/* @0x2ccb08 add r0, pc, r0 */
/* @0x2ccb0c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ccb10 vldr s13, [r4, #80] */
/* @0x2ccb14 vldr s14, [r4, #84] */
/* @0x2ccb18 vcvt.f64.f32 d5, s13 */
/* @0x2ccb1c ldr r0, [pc, #0xa4] */
/* @0x2ccb20 add r0, pc, r0 */
/* @0x2ccb24 vcvt.f64.f32 d7, s14 */
/* @0x2ccb28 vmov r2, r3, d5 */
/* @0x2ccb2c vstr d7, [sp] */
/* @0x2ccb30 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ccb34 vldr s13, [r4, #88] */
/* @0x2ccb38 vldr s14, [r4, #92] */
/* @0x2ccb3c vcvt.f64.f32 d5, s13 */
/* @0x2ccb40 ldr r0, [pc, #0x84] */
/* @0x2ccb44 add r0, pc, r0 */
/* @0x2ccb48 vcvt.f64.f32 d7, s14 */
/* @0x2ccb4c vmov r2, r3, d5 */
/* @0x2ccb50 vstr d7, [sp] */
/* @0x2ccb54 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ccb58 vldr s15, [r4, #104] */
/* @0x2ccb5c vcvt.f64.f32 d6, s15 */
/* @0x2ccb60 ldr r0, [pc, #0x68] */
/* @0x2ccb64 add r0, pc, r0 */
/* @0x2ccb68 vmov r2, r3, d6 */
/* @0x2ccb6c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ccb70 vldr s15, [r4, #68] */
/* @0x2ccb74 vcvt.f64.f32 d5, s15 */
/* @0x2ccb78 ldr r0, [pc, #0x54] */
/* @0x2ccb7c add r0, pc, r0 */
/* @0x2ccb80 vmov r2, r3, d5 */
/* @0x2ccb84 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ccb88 vldr s15, [r4, #72] */
/* @0x2ccb8c vcvt.f64.f32 d6, s15 */
/* @0x2ccb90 ldr r0, [pc, #0x40] */
/* @0x2ccb94 add r0, pc, r0 */
/* @0x2ccb98 vmov r2, r3, d6 */
/* @0x2ccb9c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ccba0 ldr r0, [pc, #0x34] */
/* @0x2ccba4 ldr r1, [r4, #0x38] */
/* @0x2ccba8 add r0, pc, r0 */
/* @0x2ccbac add sp, sp, #8 */
/* @0x2ccbb0 pop {r4, r5, r6, lr} */
/* @0x2ccbb4 b 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ccbb8 strheq pc, [r8], -r12 */
/* @0x2ccbbc andeq pc, r8, r4, asr #7 */
/* @0x2ccbc0 .word 0x0008f3d0 */
/* @0x2ccbc4 .word 0x0008f3dc */
/* @0x2ccbc8 andeq pc, r8, r8, ror #7 */
/* @0x2ccbcc .word 0x0008f3f0 */
/* @0x2ccbd0 .word 0x0008f3fc */
/* @0x2ccbd4 .word 0x0008f3fc */
/* @0x2ccbd8 andeq pc, r8, r4, lsl #8 */
/* @0x2ccbdc andeq pc, r8, r0, lsl r4 */

/* ── FUNC 0x2ccbe0 · b2Joint::~b2Joint() · size=40 · insn=10 */
/* @0x2ccbe0 ldr r3, [pc, #0x1c] */
/* @0x2ccbe4 push {r4, lr} */
/* @0x2ccbe8 ldr r3, [pc, r3] */
/* @0x2ccbec mov r4, r0 */
/* @0x2ccbf0 add r3, r3, #8 */
/* @0x2ccbf4 str r3, [r0] */
/* @0x2ccbf8 bl 0x27d1d0 <_ZdlPv> */
/* @0x2ccbfc mov r0, r4 */
/* @0x2ccc00 pop {r4, pc} */
/* @0x2ccc04 andseq r4, r2, r12, ror #30 */

/* ── FUNC 0x2ccc08 · b2DistanceJoint::~b2DistanceJoint() · size=40 · insn=10 */
/* @0x2ccc08 ldr r3, [pc, #0x1c] */
/* @0x2ccc0c push {r4, lr} */
/* @0x2ccc10 ldr r3, [pc, r3] */
/* @0x2ccc14 mov r4, r0 */
/* @0x2ccc18 add r3, r3, #8 */
/* @0x2ccc1c str r3, [r0] */
/* @0x2ccc20 bl 0x27d1d0 <_ZdlPv> */
/* @0x2ccc24 mov r0, r4 */
/* @0x2ccc28 pop {r4, pc} */
/* @0x2ccc2c andseq r4, r2, r4, asr #30 */

/* ── FUNC 0x2ccc30 · b2DistanceJoint::SolvePositionConstraints(b2SolverData const&) · size=564 · insn=141 */
/* @0x2ccc30 vldr s15, [r0, #68] */
/* @0x2ccc34 vcmpe.f32 s15, #0 */
/* @0x2ccc38 push {r4, r5, r6, r7, lr} */
/* @0x2ccc3c vpush {d8, d9, d10, d11, d12, d13} */
/* @0x2ccc40 mov r4, r0 */
/* @0x2ccc44 sub sp, sp, #12 */
/* @0x2ccc48 vmrs APSR_nzcv, fpscr */
/* @0x2ccc4c movgt r0, #1 */
/* @0x2ccc50 ble 0x2ccc60 <_ZN15b2DistanceJoint24SolvePositionConstraintsERK12b2SolverData+0x30> */
/* @0x2ccc54 add sp, sp, #12 */
/* @0x2ccc58 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x2ccc5c pop {r4, r5, r6, r7, pc} */
/* @0x2ccc60 ldr r7, [r4, #0x6c] */
/* @0x2ccc64 ldr r6, [r4, #0x70] */
/* @0x2ccc68 ldr r5, [r1, #0x18] */
/* @0x2ccc6c add r2, r7, r7, lsl #1 */
/* @0x2ccc70 add r3, r6, r6, lsl #1 */
/* @0x2ccc74 add r2, r5, r2, lsl #2 */
/* @0x2ccc78 vldr s23, [r2, #8] */
/* @0x2ccc7c vmov r0, s23 */
/* @0x2ccc80 add r3, r5, r3, lsl #2 */
/* @0x2ccc84 vldr s27, [r2] */
/* @0x2ccc88 vldr s22, [r3, #8] */
/* @0x2ccc8c vldr s26, [r2, #4] */
/* @0x2ccc90 vldr s25, [r3] */
/* @0x2ccc94 vldr s24, [r3, #4] */
/* @0x2ccc98 str r1, [sp, #0x4] */
/* @0x2ccc9c bl 0xb6580 <sinf@plt> */
/* @0x2ccca0 vmov s16, r0 */
/* @0x2ccca4 vmov r0, s23 */
/* @0x2ccca8 bl 0xb658c <cosf@plt> */
/* @0x2cccac vmov s17, r0 */
/* @0x2cccb0 vmov r0, s22 */
/* @0x2cccb4 bl 0xb6580 <sinf@plt> */
/* @0x2cccb8 vmov s21, r0 */
/* @0x2cccbc vmov r0, s22 */
/* @0x2cccc0 bl 0xb658c <cosf@plt> */
/* @0x2cccc4 vldr s15, [r4, #152] */
/* @0x2cccc8 vldr s18, [r4, #92] */
/* @0x2ccccc vsub.f32 s18, s18, s15 */
/* @0x2cccd0 vldr s10, [r4, #88] */
/* @0x2cccd4 vldr s13, [r4, #148] */
/* @0x2cccd8 vldr s19, [r4, #84] */
/* @0x2cccdc vldr s11, [r4, #144] */
/* @0x2ccce0 vldr s12, [r4, #80] */
/* @0x2ccce4 vldr s15, [r4, #140] */
/* @0x2ccce8 vsub.f32 s13, s10, s13 */
/* @0x2cccec vsub.f32 s19, s19, s11 */
/* @0x2cccf0 vsub.f32 s15, s12, s15 */
/* @0x2cccf4 vmov s14, r0 */
/* @0x2cccf8 vmul.f32 s20, s18, s14 */
/* @0x2cccfc vmul.f32 s18, s18, s21 */
/* @0x2ccd00 vmla.f32 s20, s13, s21 */
/* @0x2ccd04 vmul.f32 s21, s19, s17 */
/* @0x2ccd08 vnmls.f32 s18, s13, s14 */
/* @0x2ccd0c vmla.f32 s21, s15, s16 */
/* @0x2ccd10 vmul.f32 s19, s19, s16 */
/* @0x2ccd14 vadd.f32 s16, s24, s20 */
/* @0x2ccd18 vsub.f32 s16, s16, s26 */
/* @0x2ccd1c vnmls.f32 s19, s15, s17 */
/* @0x2ccd20 vadd.f32 s17, s25, s18 */
/* @0x2ccd24 vsub.f32 s16, s16, s21 */
/* @0x2ccd28 vsub.f32 s17, s17, s27 */
/* @0x2ccd2c vmul.f32 s14, s16, s16 */
/* @0x2ccd30 vsub.f32 s17, s17, s19 */
/* @0x2ccd34 vmla.f32 s14, s17, s17 */
/* @0x2ccd38 vsqrt.f32 s15, s14 */
/* @0x2ccd3c vcmp.f32 s15, s15 */
/* @0x2ccd40 vmrs APSR_nzcv, fpscr */
/* @0x2ccd44 bne 0x2cce30 <_ZN15b2DistanceJoint24SolvePositionConstraintsERK12b2SolverData+0x200> */
/* @0x2ccd48 vldr s14, [pc, #256] */
/* @0x2ccd4c vcmpe.f32 s15, s14 */
/* @0x2ccd50 vmrs APSR_nzcv, fpscr */
/* @0x2ccd54 vmovpl.f32 s13, #1.000000e+00 */
/* @0x2ccd58 vldrmi s14, [pc, #244] */
/* @0x2ccd5c vmovpl.f32 s14, s15 */
/* @0x2ccd60 vdivpl.f32 s15, s13, s15 */
/* @0x2ccd64 vmulpl.f32 s17, s17, s15 */
/* @0x2ccd68 vmulpl.f32 s16, s16, s15 */
/* @0x2ccd6c vldr s15, [r4, #104] */
/* @0x2ccd70 vsub.f32 s14, s14, s15 */
/* @0x2ccd74 vldr s15, [pc, #220] */
/* @0x2ccd78 vcmpe.f32 s14, s15 */
/* @0x2ccd7c vmrs APSR_nzcv, fpscr */
/* @0x2ccd80 bpl 0x2ccd94 <_ZN15b2DistanceJoint24SolvePositionConstraintsERK12b2SolverData+0x164> */
/* @0x2ccd84 vldr s15, [pc, #208] */
/* @0x2ccd88 vcmpe.f32 s14, s15 */
/* @0x2ccd8c vmrs APSR_nzcv, fpscr */
/* @0x2ccd90 vmovpl.f32 s15, s14 */
/* @0x2ccd94 vldr s12, [r4, #172] */
/* @0x2ccd98 vldr s14, [r4, #160] */
/* @0x2ccd9c vldr s13, [r4, #156] */
/* @0x2ccda0 vldr s10, [r4, #164] */
/* @0x2ccda4 vnmul.f32 s12, s12, s15 */
/* @0x2ccda8 vldr s11, [r4, #168] */
/* @0x2ccdac add r6, r6, r6, lsl #1 */
/* @0x2ccdb0 add r7, r7, r7, lsl #1 */
/* @0x2ccdb4 add r7, r5, r7, lsl #2 */
/* @0x2ccdb8 add r5, r5, r6, lsl #2 */
/* @0x2ccdbc vmul.f32 s17, s12, s17 */
/* @0x2ccdc0 vmul.f32 s16, s12, s16 */
/* @0x2ccdc4 vmul.f32 s21, s21, s17 */
/* @0x2ccdc8 vmul.f32 s20, s20, s17 */
/* @0x2ccdcc vnmls.f32 s21, s19, s16 */
/* @0x2ccdd0 vnmls.f32 s20, s18, s16 */
/* @0x2ccdd4 vmla.f32 s25, s17, s14 */
/* @0x2ccdd8 vmla.f32 s24, s16, s14 */
/* @0x2ccddc vldr s14, [pc, #124] */
/* @0x2ccde0 vmls.f32 s27, s17, s13 */
/* @0x2ccde4 vmls.f32 s26, s16, s13 */
/* @0x2ccde8 vstr s27, [r7] */
/* @0x2ccdec vmls.f32 s23, s21, s10 */
/* @0x2ccdf0 vstr s26, [r7, #4] */
/* @0x2ccdf4 vmla.f32 s22, s20, s11 */
/* @0x2ccdf8 vstr s23, [r7, #8] */
/* @0x2ccdfc vstr s25, [r5] */
/* @0x2cce00 vstr s24, [r5, #4] */
/* @0x2cce04 vcmpe.f32 s15, #0 */
/* @0x2cce08 vstr s22, [r5, #8] */
/* @0x2cce0c vmrs APSR_nzcv, fpscr */
/* @0x2cce10 vnegle.f32 s15, s15 */
/* @0x2cce14 vcmpe.f32 s15, s14 */
/* @0x2cce18 vmrs APSR_nzcv, fpscr */
/* @0x2cce1c movpl r0, #0 */
/* @0x2cce20 movmi r0, #1 */
/* @0x2cce24 add sp, sp, #12 */
/* @0x2cce28 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x2cce2c pop {r4, r5, r6, r7, pc} */
/* @0x2cce30 vmov r0, s14 */
/* @0x2cce34 bl 0xb6700 <sqrtf@plt> */
/* @0x2cce38 ldr r1, [sp, #0x4] */
/* @0x2cce3c ldr r7, [r4, #0x6c] */
/* @0x2cce40 ldr r6, [r4, #0x70] */
/* @0x2cce44 ldr r5, [r1, #0x18] */
/* @0x2cce48 vmov s15, r0 */
/* @0x2cce4c b 0x2ccd48 <_ZN15b2DistanceJoint24SolvePositionConstraintsERK12b2SolverData+0x118> */
/* @0x2cce50 strlo r0, [r0], #-0 */
/* @0x2cce54 andeq r0, r0, r0 */
/* @0x2cce58 cdplo p12, #0x4, c12, c12, c13, #0x6 */
/* @0x2cce5c cdplt p12, #0x4, c12, c12, c13, #0x6 */
/* @0x2cce60 bllo 0xfebc2a90 <b2_toiTime+0xfffffffffe4695ec> */

/* ── FUNC 0x2cce64 · b2DistanceJoint::InitVelocityConstraints(b2SolverData const&) · size=892 · insn=223 */
/* @0x2cce64 ldr r2, [r0, #0x30] */
/* @0x2cce68 vldr s15, [r2, #136] */
/* @0x2cce6c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2cce70 vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2cce74 mov r5, r1 */
/* @0x2cce78 ldr r3, [r0, #0x34] */
/* @0x2cce7c add r1, r2, #44 */
/* @0x2cce80 ldr lr, [r2, #0x8] */
/* @0x2cce84 mov r4, r0 */
/* @0x2cce88 ldr r8, [r5, #0x18] */
/* @0x2cce8c add r10, r0, #140 */
/* @0x2cce90 ldr r12, [r3, #0x8] */
/* @0x2cce94 add r7, r0, #148 */
/* @0x2cce98 ldr r11, [r2, #0x90] */
/* @0x2cce9c add r9, r3, #44 */
/* @0x2ccea0 ldm r1, {r0, r1} */
/* @0x2ccea4 str lr, [r4, #0x6c] */
/* @0x2ccea8 add lr, lr, lr, lsl #1 */
/* @0x2cceac ldr r6, [r5, #0x1c] */
/* @0x2cceb0 lsl lr, lr, #2 */
/* @0x2cceb4 str r12, [r4, #0x70] */
/* @0x2cceb8 add r12, r12, r12, lsl #1 */
/* @0x2ccebc add r2, r8, lr */
/* @0x2ccec0 stm r10, {r0, r1} */
/* @0x2ccec4 add lr, r6, lr */
/* @0x2ccec8 lsl r12, r12, #2 */
/* @0x2ccecc ldm r9, {r0, r1} */
/* @0x2cced0 ldr r10, [r3, #0x88] */
/* @0x2cced4 vldr s24, [r2] */
/* @0x2cced8 ldr r9, [r3, #0x90] */
/* @0x2ccedc add r3, r8, r12 */
/* @0x2ccee0 ldr r8, [r2, #0x8] */
/* @0x2ccee4 add r12, r6, r12 */
/* @0x2ccee8 stm r7, {r0, r1} */
/* @0x2cceec vstr s15, [r4, #156] */
/* @0x2ccef0 str r11, [r4, #0xa4] */
/* @0x2ccef4 vldr s26, [r2, #4] */
/* @0x2ccef8 str r10, [r4, #0xa0] */
/* @0x2ccefc mov r0, r8 */
/* @0x2ccf00 str r9, [r4, #0xa8] */
/* @0x2ccf04 vldr s25, [r3] */
/* @0x2ccf08 ldr r7, [r3, #0x8] */
/* @0x2ccf0c vldr s27, [r3, #4] */
/* @0x2ccf10 vldr s21, [lr] */
/* @0x2ccf14 vldr s20, [lr, #4] */
/* @0x2ccf18 vldr s19, [lr, #8] */
/* @0x2ccf1c vldr s18, [r12] */
/* @0x2ccf20 vldr s17, [r12, #4] */
/* @0x2ccf24 vldr s16, [r12, #8] */
/* @0x2ccf28 bl 0xb6580 <sinf@plt> */
/* @0x2ccf2c vmov s22, r0 */
/* @0x2ccf30 mov r0, r8 */
/* @0x2ccf34 bl 0xb658c <cosf@plt> */
/* @0x2ccf38 vmov s23, r0 */
/* @0x2ccf3c mov r0, r7 */
/* @0x2ccf40 bl 0xb6580 <sinf@plt> */
/* @0x2ccf44 vmov s28, r0 */
/* @0x2ccf48 mov r0, r7 */
/* @0x2ccf4c bl 0xb658c <cosf@plt> */
/* @0x2ccf50 vldr s15, [r4, #144] */
/* @0x2ccf54 vldr s14, [r4, #84] */
/* @0x2ccf58 vsub.f32 s14, s14, s15 */
/* @0x2ccf5c vldr s13, [r4, #140] */
/* @0x2ccf60 vldr s11, [r4, #80] */
/* @0x2ccf64 vmul.f32 s15, s14, s22 */
/* @0x2ccf68 vsub.f32 s11, s11, s13 */
/* @0x2ccf6c vmov s10, r0 */
/* @0x2ccf70 vnmls.f32 s15, s11, s23 */
/* @0x2ccf74 vstr s15, [r4, #124] */
/* @0x2ccf78 vldr s12, [r4, #92] */
/* @0x2ccf7c vldr s13, [r4, #152] */
/* @0x2ccf80 vsub.f32 s13, s12, s13 */
/* @0x2ccf84 vldr s8, [r4, #88] */
/* @0x2ccf88 vldr s9, [r4, #148] */
/* @0x2ccf8c vmul.f32 s12, s13, s10 */
/* @0x2ccf90 vsub.f32 s9, s8, s9 */
/* @0x2ccf94 vmul.f32 s13, s13, s28 */
/* @0x2ccf98 vmla.f32 s12, s9, s28 */
/* @0x2ccf9c vmul.f32 s14, s14, s23 */
/* @0x2ccfa0 vstr s12, [r4, #136] */
/* @0x2ccfa4 vnmls.f32 s13, s9, s10 */
/* @0x2ccfa8 vmla.f32 s14, s11, s22 */
/* @0x2ccfac vstr s13, [r4, #132] */
/* @0x2ccfb0 vadd.f32 s12, s12, s27 */
/* @0x2ccfb4 vstr s14, [r4, #128] */
/* @0x2ccfb8 vsub.f32 s26, s12, s26 */
/* @0x2ccfbc vadd.f32 s13, s13, s25 */
/* @0x2ccfc0 vsub.f32 s14, s26, s14 */
/* @0x2ccfc4 vsub.f32 s24, s13, s24 */
/* @0x2ccfc8 vstr s14, [r4, #120] */
/* @0x2ccfcc vmul.f32 s14, s14, s14 */
/* @0x2ccfd0 vsub.f32 s15, s24, s15 */
/* @0x2ccfd4 vmla.f32 s14, s15, s15 */
/* @0x2ccfd8 vstr s15, [r4, #116] */
/* @0x2ccfdc vsqrt.f32 s15, s14 */
/* @0x2ccfe0 vcmp.f32 s15, s15 */
/* @0x2ccfe4 vmrs APSR_nzcv, fpscr */
/* @0x2ccfe8 bne 0x2cd1c0 <_ZN15b2DistanceJoint23InitVelocityConstraintsERK12b2SolverData+0x35c> */
/* @0x2ccfec vldr s14, [pc, #480] */
/* @0x2ccff0 vcmpe.f32 s15, s14 */
/* @0x2ccff4 vmrs APSR_nzcv, fpscr */
/* @0x2ccff8 ble 0x2cd19c <_ZN15b2DistanceJoint23InitVelocityConstraintsERK12b2SolverData+0x338> */
/* @0x2ccffc vmov.f32 s12, #1.000000e+00 */
/* @0x2cd000 vldr s13, [r4, #116] */
/* @0x2cd004 vldr s14, [r4, #120] */
/* @0x2cd008 vdiv.f32 s12, s12, s15 */
/* @0x2cd00c vmul.f32 s13, s12, s13 */
/* @0x2cd010 vmul.f32 s12, s12, s14 */
/* @0x2cd014 vstr s13, [r4, #116] */
/* @0x2cd018 vstr s12, [r4, #120] */
/* @0x2cd01c vldr s1, [r4, #128] */
/* @0x2cd020 vmul.f32 s14, s13, s1 */
/* @0x2cd024 vldr s3, [r4, #124] */
/* @0x2cd028 vldr s2, [r4, #136] */
/* @0x2cd02c vldr s5, [r4, #164] */
/* @0x2cd030 vldr s4, [r4, #132] */
/* @0x2cd034 vldr s7, [r4, #156] */
/* @0x2cd038 vldr s6, [r4, #168] */
/* @0x2cd03c vldr s8, [r4, #160] */
/* @0x2cd040 vnmls.f32 s14, s12, s3 */
/* @0x2cd044 vmul.f32 s13, s13, s2 */
/* @0x2cd048 vmul.f32 s11, s14, s5 */
/* @0x2cd04c vnmls.f32 s13, s12, s4 */
/* @0x2cd050 vmov.f32 s12, s7 */
/* @0x2cd054 vmla.f32 s12, s11, s14 */
/* @0x2cd058 vldr s11, [r4, #68] */
/* @0x2cd05c vmov.f32 s14, s12 */
/* @0x2cd060 vmul.f32 s12, s13, s6 */
/* @0x2cd064 vadd.f32 s14, s14, s8 */
/* @0x2cd068 vmla.f32 s14, s12, s13 */
/* @0x2cd06c vldr s12, [pc, #356] */
/* @0x2cd070 vcmp.f32 s14, #0 */
/* @0x2cd074 vmrs APSR_nzcv, fpscr */
/* @0x2cd078 vmovne.f32 s13, #1.000000e+00 */
/* @0x2cd07c vldreq s13, [pc, #340] */
/* @0x2cd080 vdivne.f32 s13, s13, s14 */
/* @0x2cd084 vcmpe.f32 s11, #0 */
/* @0x2cd088 vstr s13, [r4, #172] */
/* @0x2cd08c vmrs APSR_nzcv, fpscr */
/* @0x2cd090 ble 0x2cd1b4 <_ZN15b2DistanceJoint23InitVelocityConstraintsERK12b2SolverData+0x350> */
/* @0x2cd094 vldr s9, [pc, #320] */
/* @0x2cd098 vmul.f32 s9, s11, s9 */
/* @0x2cd09c vldr s10, [r4, #72] */
/* @0x2cd0a0 vldr s11, [r5] */
/* @0x2cd0a4 vldr s0, [r4, #104] */
/* @0x2cd0a8 vadd.f32 s22, s13, s13 */
/* @0x2cd0ac vmul.f32 s13, s13, s9 */
/* @0x2cd0b0 vmul.f32 s10, s22, s10 */
/* @0x2cd0b4 vmul.f32 s13, s13, s9 */
/* @0x2cd0b8 vmul.f32 s10, s10, s9 */
/* @0x2cd0bc vmla.f32 s10, s11, s13 */
/* @0x2cd0c0 vmul.f32 s10, s10, s11 */
/* @0x2cd0c4 vcmp.f32 s10, s12 */
/* @0x2cd0c8 vmrs APSR_nzcv, fpscr */
/* @0x2cd0cc vmovne.f32 s12, #1.000000e+00 */
/* @0x2cd0d0 vdivne.f32 s12, s12, s10 */
/* @0x2cd0d4 vadd.f32 s14, s12, s14 */
/* @0x2cd0d8 vstr s12, [r4, #96] */
/* @0x2cd0dc vsub.f32 s15, s15, s0 */
/* @0x2cd0e0 vcmp.f32 s14, #0 */
/* @0x2cd0e4 vmul.f32 s11, s15, s11 */
/* @0x2cd0e8 vmrs APSR_nzcv, fpscr */
/* @0x2cd0ec vldreq s14, [pc, #228] */
/* @0x2cd0f0 vmovne.f32 s15, #1.000000e+00 */
/* @0x2cd0f4 vdivne.f32 s14, s15, s14 */
/* @0x2cd0f8 vmul.f32 s13, s11, s13 */
/* @0x2cd0fc vstr s14, [r4, #172] */
/* @0x2cd100 vmul.f32 s12, s12, s13 */
/* @0x2cd104 vstr s12, [r4, #76] */
/* @0x2cd108 ldrb r3, [r5, #0x14] */
/* @0x2cd10c cmp r3, #0 */
/* @0x2cd110 moveq r3, #0 */
/* @0x2cd114 streq r3, [r4, #0x64] */
/* @0x2cd118 beq 0x2cd164 <_ZN15b2DistanceJoint23InitVelocityConstraintsERK12b2SolverData+0x300> */
/* @0x2cd11c vldr s14, [r4, #100] */
/* @0x2cd120 vldr s15, [r5, #8] */
/* @0x2cd124 vmul.f32 s15, s14, s15 */
/* @0x2cd128 vldr s14, [r4, #116] */
/* @0x2cd12c vldr s13, [r4, #120] */
/* @0x2cd130 vmul.f32 s14, s15, s14 */
/* @0x2cd134 vstr s15, [r4, #100] */
/* @0x2cd138 vmul.f32 s1, s14, s1 */
/* @0x2cd13c vmul.f32 s15, s15, s13 */
/* @0x2cd140 vmul.f32 s2, s14, s2 */
/* @0x2cd144 vnmls.f32 s1, s15, s3 */
/* @0x2cd148 vnmls.f32 s2, s15, s4 */
/* @0x2cd14c vmls.f32 s21, s7, s14 */
/* @0x2cd150 vmla.f32 s18, s8, s14 */
/* @0x2cd154 vmls.f32 s19, s1, s5 */
/* @0x2cd158 vmla.f32 s16, s2, s6 */
/* @0x2cd15c vmls.f32 s20, s7, s15 */
/* @0x2cd160 vmla.f32 s17, s8, s15 */
/* @0x2cd164 ldr r3, [r4, #0x6c] */
/* @0x2cd168 ldr r2, [r4, #0x70] */
/* @0x2cd16c add r3, r3, r3, lsl #1 */
/* @0x2cd170 add r2, r2, r2, lsl #1 */
/* @0x2cd174 add r3, r6, r3, lsl #2 */
/* @0x2cd178 vstr s21, [r3] */
/* @0x2cd17c vstr s20, [r3, #4] */
/* @0x2cd180 vstr s19, [r3, #8] */
/* @0x2cd184 add r6, r6, r2, lsl #2 */
/* @0x2cd188 vstr s18, [r6] */
/* @0x2cd18c vstr s17, [r6, #4] */
/* @0x2cd190 vstr s16, [r6, #8] */
/* @0x2cd194 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2cd198 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2cd19c vldr s14, [pc, #52] */
/* @0x2cd1a0 vmov.f32 s13, s14 */
/* @0x2cd1a4 vstr s14, [r4, #116] */
/* @0x2cd1a8 vstr s14, [r4, #120] */
/* @0x2cd1ac vmov.f32 s12, s14 */
/* @0x2cd1b0 b 0x2cd01c <_ZN15b2DistanceJoint23InitVelocityConstraintsERK12b2SolverData+0x1b8> */
/* @0x2cd1b4 vstr s12, [r4, #96] */
/* @0x2cd1b8 vstr s12, [r4, #76] */
/* @0x2cd1bc b 0x2cd108 <_ZN15b2DistanceJoint23InitVelocityConstraintsERK12b2SolverData+0x2a4> */
/* @0x2cd1c0 vmov r0, s14 */
/* @0x2cd1c4 bl 0xb6700 <sqrtf@plt> */
/* @0x2cd1c8 ldr r6, [r5, #0x1c] */
/* @0x2cd1cc vmov s15, r0 */
/* @0x2cd1d0 b 0x2ccfec <_ZN15b2DistanceJoint23InitVelocityConstraintsERK12b2SolverData+0x188> */
/* @0x2cd1d4 bllo 0xfebc2e04 <b2_toiTime+0xfffffffffe469960> */
/* @0x2cd1d8 andeq r0, r0, r0 */
/* @0x2cd1dc ldrdmi r0, r1, [r9], #251 */

/* ── FUNC 0x2cd1e0 · b2DistanceJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&, b2Vec2 const&) · size=204 · insn=51 */
/* @0x2cd1e0 vldr s15, [r1, #16] */
/* @0x2cd1e4 vldr s14, [r3, #4] */
/* @0x2cd1e8 vsub.f32 s14, s14, s15 */
/* @0x2cd1ec vldr s9, [r1, #20] */
/* @0x2cd1f0 vldr s8, [r1, #24] */
/* @0x2cd1f4 vldr s6, [r3] */
/* @0x2cd1f8 vldr s10, [r1, #12] */
/* @0x2cd1fc push {r4, lr} */
/* @0x2cd200 vldr s12, [r2, #20] */
/* @0x2cd204 vldr s11, [r2, #24] */
/* @0x2cd208 mov r4, r0 */
/* @0x2cd20c vldr s15, [r2, #16] */
/* @0x2cd210 vldr s7, [r2, #12] */
/* @0x2cd214 ldr r0, [sp, #0x8] */
/* @0x2cd218 str r1, [r4, #0x8] */
/* @0x2cd21c str r2, [r4, #0xc] */
/* @0x2cd220 vmul.f32 s13, s14, s9 */
/* @0x2cd224 vmul.f32 s14, s14, s8 */
/* @0x2cd228 vsub.f32 s10, s6, s10 */
/* @0x2cd22c vmla.f32 s13, s10, s8 */
/* @0x2cd230 vmls.f32 s14, s9, s10 */
/* @0x2cd234 vstr s13, [r4, #20] */
/* @0x2cd238 vstr s14, [r4, #24] */
/* @0x2cd23c vldr s14, [r0, #4] */
/* @0x2cd240 vsub.f32 s15, s14, s15 */
/* @0x2cd244 vldr s13, [r0] */
/* @0x2cd248 vmul.f32 s14, s15, s12 */
/* @0x2cd24c vmul.f32 s15, s15, s11 */
/* @0x2cd250 vsub.f32 s13, s13, s7 */
/* @0x2cd254 vmla.f32 s14, s13, s11 */
/* @0x2cd258 vmls.f32 s15, s12, s13 */
/* @0x2cd25c vstr s14, [r4, #28] */
/* @0x2cd260 vstr s15, [r4, #32] */
/* @0x2cd264 vldr s15, [r3, #4] */
/* @0x2cd268 vldr s14, [r0, #4] */
/* @0x2cd26c vsub.f32 s14, s14, s15 */
/* @0x2cd270 vldr s13, [r0] */
/* @0x2cd274 vldr s15, [r3] */
/* @0x2cd278 vmul.f32 s14, s14, s14 */
/* @0x2cd27c vsub.f32 s15, s13, s15 */
/* @0x2cd280 vmla.f32 s14, s15, s15 */
/* @0x2cd284 vsqrt.f32 s15, s14 */
/* @0x2cd288 vcmp.f32 s15, s15 */
/* @0x2cd28c vmrs APSR_nzcv, fpscr */
/* @0x2cd290 bne 0x2cd29c <_ZN18b2DistanceJointDef10InitializeEP6b2BodyS1_RK6b2Vec2S4_+0xbc> */
/* @0x2cd294 vstr s15, [r4, #36] */
/* @0x2cd298 pop {r4, pc} */
/* @0x2cd29c vmov r0, s14 */
/* @0x2cd2a0 bl 0xb6700 <sqrtf@plt> */
/* @0x2cd2a4 vmov s15, r0 */
/* @0x2cd2a8 b 0x2cd294 <_ZN18b2DistanceJointDef10InitializeEP6b2BodyS1_RK6b2Vec2S4_+0xb4> */

/* ── FUNC 0x2cd2ac · b2DistanceJoint::b2DistanceJoint(b2DistanceJointDef const*) · size=116 · insn=29 */
/* @0x2cd2ac push {r3, r4, r5, r6, r7, lr} */
/* @0x2cd2b0 mov r4, r0 */
/* @0x2cd2b4 mov r5, r1 */
/* @0x2cd2b8 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef> */
/* @0x2cd2bc add r3, r5, #20 */
/* @0x2cd2c0 ldr r2, [pc, #0x54] */
/* @0x2cd2c4 add r6, r5, #28 */
/* @0x2cd2c8 ldr r7, [r5, #0x24] */
/* @0x2cd2cc ldm r3, {r0, r1} */
/* @0x2cd2d0 ldr r2, [pc, r2] */
/* @0x2cd2d4 mov r3, r4 */
/* @0x2cd2d8 add r2, r2, #8 */
/* @0x2cd2dc str r2, [r3], #80 */
/* @0x2cd2e0 add r12, r4, #88 */
/* @0x2cd2e4 stm r3, {r0, r1} */
/* @0x2cd2e8 mov r3, #0 */
/* @0x2cd2ec ldm r6, {r0, r1} */
/* @0x2cd2f0 ldr r2, [r5, #0x2c] */
/* @0x2cd2f4 ldr r6, [r5, #0x28] */
/* @0x2cd2f8 stm r12, {r0, r1} */
/* @0x2cd2fc mov r0, r4 */
/* @0x2cd300 str r7, [r4, #0x68] */
/* @0x2cd304 str r6, [r4, #0x44] */
/* @0x2cd308 str r2, [r4, #0x48] */
/* @0x2cd30c str r3, [r4, #0x64] */
/* @0x2cd310 str r3, [r4, #0x60] */
/* @0x2cd314 str r3, [r4, #0x4c] */
/* @0x2cd318 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2cd31c andseq r4, r2, r8, lsl #17 */

/* ── FUNC 0x2cd2ac · b2DistanceJoint::b2DistanceJoint(b2DistanceJointDef const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2cd320 · b2FrictionJoint::SolvePositionConstraints(b2SolverData const&) · size=8 · insn=2 */
/* @0x2cd320 mov r0, #1 */
/* @0x2cd324 bx lr */
