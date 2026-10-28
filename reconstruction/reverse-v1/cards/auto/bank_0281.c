/* libyoyo.so 覆盖卡组 0281
 * 函数 0x2d4560..0x2d5308，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2d4560 · b2ParticleGroup::b2ParticleGroup() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2d45f8 · b2ParticleGroup::~b2ParticleGroup() · size=4 · insn=1 */
/* @0x2d45f8 bx lr */

/* ── FUNC 0x2d45f8 · b2ParticleGroup::~b2ParticleGroup() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2d45fc · b2ParticleGroup::GetBufferIndex() const · size=8 · insn=2 */
/* @0x2d45fc ldr r0, [r0, #0x4] */
/* @0x2d4600 bx lr */

/* ── FUNC 0x2d4604 · b2ParticleGroup::GetGroupFlags() const · size=8 · insn=2 */
/* @0x2d4604 ldr r0, [r0, #0xc] */
/* @0x2d4608 bx lr */

/* ── FUNC 0x2d460c · b2ParticleGroup::SetGroupFlags(int) · size=8 · insn=2 */
/* @0x2d460c str r1, [r0, #0xc] */
/* @0x2d4610 bx lr */

/* ── FUNC 0x2d4614 · b2ParticleGroup::GetTransform() const · size=8 · insn=2 */
/* @0x2d4614 add r0, r0, #60 */
/* @0x2d4618 bx lr */

/* ── FUNC 0x2d461c · b2ParticleGroup::GetPosition() const · size=8 · insn=2 */
/* @0x2d461c add r0, r0, #60 */
/* @0x2d4620 bx lr */

/* ── FUNC 0x2d4624 · b2ParticleGroup::GetAngle() const · size=16 · insn=4 */
/* @0x2d4624 mov r3, r0 */
/* @0x2d4628 ldr r0, [r0, #0x44] */
/* @0x2d462c ldr r1, [r3, #0x48] */
/* @0x2d4630 b 0xb6778 <atan2f@plt> */

/* ── FUNC 0x2d4634 · b2ParticleGroup::GetUserData() const · size=8 · insn=2 */
/* @0x2d4634 ldr r0, [r0, #0x50] */
/* @0x2d4638 bx lr */

/* ── FUNC 0x2d463c · b2ParticleGroup::SetUserData(void*) · size=8 · insn=2 */
/* @0x2d463c str r1, [r0, #0x50] */
/* @0x2d4640 bx lr */

/* ── FUNC 0x2d4644 · b2ParticleGroup::UpdateStatistics() const · size=464 · insn=116 */
/* @0x2d4644 push {r4, r5, r6, lr} */
/* @0x2d4648 mov r4, r0 */
/* @0x2d464c ldr r0, [r0] */
/* @0x2d4650 ldr r2, [r4, #0x1c] */
/* @0x2d4654 ldr r3, [r0] */
/* @0x2d4658 cmp r2, r3 */
/* @0x2d465c popeq {r4, r5, r6, pc} */
/* @0x2d4660 bl 0x2d85bc <_ZNK16b2ParticleSystem15GetParticleMassEv> */
/* @0x2d4664 ldr r6, [r4, #0x4] */
/* @0x2d4668 ldr r5, [r4, #0x8] */
/* @0x2d466c vldr s10, [pc, #412] */
/* @0x2d4670 ldr r12, [r4] */
/* @0x2d4674 vstr s10, [r4, #32] */
/* @0x2d4678 cmp r6, r5 */
/* @0x2d467c vstr s10, [r4, #40] */
/* @0x2d4680 vstr s10, [r4, #44] */
/* @0x2d4684 vstr s10, [r4, #48] */
/* @0x2d4688 vstr s10, [r4, #52] */
/* @0x2d468c vmov s15, r0 */
/* @0x2d4690 bge 0x2d4750 <_ZNK15b2ParticleGroup16UpdateStatisticsEv+0x10c> */
/* @0x2d4694 ldr r0, [r12, #0x38] */
/* @0x2d4698 vmov.f32 s6, s10 */
/* @0x2d469c ldr r2, [r12, #0x40] */
/* @0x2d46a0 lsl r1, r6, #3 */
/* @0x2d46a4 add r3, r0, r1 */
/* @0x2d46a8 add r0, r0, r5, lsl #3 */
/* @0x2d46ac add r1, r2, r1 */
/* @0x2d46b0 vmov.f32 s7, s10 */
/* @0x2d46b4 vmov.f32 s8, s10 */
/* @0x2d46b8 vmov.f32 s9, s10 */
/* @0x2d46bc vldr s12, [r3, #4] */
/* @0x2d46c0 mov r2, r3 */
/* @0x2d46c4 vldr s13, [r2] */
/* @0x2d46c8 mov r2, r1 */
/* @0x2d46cc vmov.f32 s11, s8 */
/* @0x2d46d0 add r3, r3, #8 */
/* @0x2d46d4 cmp r3, r0 */
/* @0x2d46d8 add r1, r1, #8 */
/* @0x2d46dc vmla.f32 s11, s15, s13 */
/* @0x2d46e0 vmla.f32 s7, s15, s12 */
/* @0x2d46e4 vstr s11, [r4, #40] */
/* @0x2d46e8 vmov.f32 s14, s10 */
/* @0x2d46ec vstr s7, [r4, #44] */
/* @0x2d46f0 vldr s8, [r1, #-4] */
/* @0x2d46f4 vldr s13, [r2] */
/* @0x2d46f8 vmla.f32 s14, s15, s8 */
/* @0x2d46fc vmla.f32 s6, s15, s13 */
/* @0x2d4700 vstr s14, [r4, #52] */
/* @0x2d4704 vmov.f32 s8, s11 */
/* @0x2d4708 vstr s6, [r4, #48] */
/* @0x2d470c vmov.f32 s10, s14 */
/* @0x2d4710 vadd.f32 s9, s15, s9 */
/* @0x2d4714 bne 0x2d46bc <_ZNK15b2ParticleGroup16UpdateStatisticsEv+0x78> */
/* @0x2d4718 vcmpe.f32 s9, #0 */
/* @0x2d471c vstr s9, [r4, #32] */
/* @0x2d4720 vmrs APSR_nzcv, fpscr */
/* @0x2d4724 ble 0x2d4750 <_ZNK15b2ParticleGroup16UpdateStatisticsEv+0x10c> */
/* @0x2d4728 vmov.f32 s10, #1.000000e+00 */
/* @0x2d472c vdiv.f32 s9, s10, s9 */
/* @0x2d4730 vmul.f32 s11, s11, s9 */
/* @0x2d4734 vmul.f32 s12, s7, s9 */
/* @0x2d4738 vstr s11, [r4, #40] */
/* @0x2d473c vmul.f32 s13, s6, s9 */
/* @0x2d4740 vstr s12, [r4, #44] */
/* @0x2d4744 vmul.f32 s9, s14, s9 */
/* @0x2d4748 vstr s13, [r4, #48] */
/* @0x2d474c vstr s9, [r4, #52] */
/* @0x2d4750 cmp r6, r5 */
/* @0x2d4754 vldr s10, [pc, #180] */
/* @0x2d4758 vstr s10, [r4, #36] */
/* @0x2d475c vstr s10, [r4, #56] */
/* @0x2d4760 bge 0x2d4804 <_ZNK15b2ParticleGroup16UpdateStatisticsEv+0x1c0> */
/* @0x2d4764 ldr r3, [r12, #0x38] */
/* @0x2d4768 vmov.f32 s8, s10 */
/* @0x2d476c ldr r2, [r12, #0x40] */
/* @0x2d4770 lsl r6, r6, #3 */
/* @0x2d4774 add r1, r3, r5, lsl #3 */
/* @0x2d4778 add r3, r3, r6 */
/* @0x2d477c add r2, r2, r6 */
/* @0x2d4780 vldr s4, [r4, #40] */
/* @0x2d4784 vldr s5, [r4, #44] */
/* @0x2d4788 vldr s6, [r4, #48] */
/* @0x2d478c vldr s7, [r4, #52] */
/* @0x2d4790 vldr s11, [r3, #4] */
/* @0x2d4794 mov r0, r2 */
/* @0x2d4798 vsub.f32 s11, s11, s5 */
/* @0x2d479c vldr s13, [r0] */
/* @0x2d47a0 vldr s12, [r3] */
/* @0x2d47a4 vldr s9, [r2, #4] */
/* @0x2d47a8 add r3, r3, #8 */
/* @0x2d47ac add r2, r2, #8 */
/* @0x2d47b0 cmp r3, r1 */
/* @0x2d47b4 vsub.f32 s13, s13, s6 */
/* @0x2d47b8 vmul.f32 s14, s11, s11 */
/* @0x2d47bc vmul.f32 s13, s11, s13 */
/* @0x2d47c0 vsub.f32 s12, s12, s4 */
/* @0x2d47c4 vsub.f32 s11, s9, s7 */
/* @0x2d47c8 vmla.f32 s14, s12, s12 */
/* @0x2d47cc vnmls.f32 s13, s12, s11 */
/* @0x2d47d0 vmla.f32 s8, s15, s14 */
/* @0x2d47d4 vmla.f32 s10, s15, s13 */
/* @0x2d47d8 vmov.f32 s14, s8 */
/* @0x2d47dc vmov.f32 s13, s10 */
/* @0x2d47e0 bne 0x2d4790 <_ZNK15b2ParticleGroup16UpdateStatisticsEv+0x14c> */
/* @0x2d47e4 vcmpe.f32 s8, #0 */
/* @0x2d47e8 vstr s10, [r4, #56] */
/* @0x2d47ec vstr s8, [r4, #36] */
/* @0x2d47f0 vmrs APSR_nzcv, fpscr */
/* @0x2d47f4 vmovgt.f32 s15, #1.000000e+00 */
/* @0x2d47f8 vdivgt.f32 s14, s15, s8 */
/* @0x2d47fc vmulgt.f32 s13, s10, s14 */
/* @0x2d4800 vstrgt s13, [r4, #56] */
/* @0x2d4804 ldr r3, [r12] */
/* @0x2d4808 str r3, [r4, #0x1c] */
/* @0x2d480c pop {r4, r5, r6, pc} */
/* @0x2d4810 andeq r0, r0, r0 */

/* ── FUNC 0x2d4814 · b2ParticleGroup::GetMass() const · size=20 · insn=5 */
/* @0x2d4814 push {r4, lr} */
/* @0x2d4818 mov r4, r0 */
/* @0x2d481c bl 0x2d4644 <_ZNK15b2ParticleGroup16UpdateStatisticsEv> */
/* @0x2d4820 ldr r0, [r4, #0x20] */
/* @0x2d4824 pop {r4, pc} */

/* ── FUNC 0x2d4828 · b2ParticleGroup::GetInertia() const · size=20 · insn=5 */
/* @0x2d4828 push {r4, lr} */
/* @0x2d482c mov r4, r0 */
/* @0x2d4830 bl 0x2d4644 <_ZNK15b2ParticleGroup16UpdateStatisticsEv> */
/* @0x2d4834 ldr r0, [r4, #0x24] */
/* @0x2d4838 pop {r4, pc} */

/* ── FUNC 0x2d483c · b2ParticleGroup::GetCenter() const · size=40 · insn=10 */
/* @0x2d483c push {r3, r4, r5, lr} */
/* @0x2d4840 mov r5, r1 */
/* @0x2d4844 add r5, r5, #40 */
/* @0x2d4848 mov r4, r0 */
/* @0x2d484c mov r0, r1 */
/* @0x2d4850 bl 0x2d4644 <_ZNK15b2ParticleGroup16UpdateStatisticsEv> */
/* @0x2d4854 ldm r5, {r0, r1} */
/* @0x2d4858 stm r4, {r0, r1} */
/* @0x2d485c mov r0, r4 */
/* @0x2d4860 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2d4864 · b2ParticleGroup::GetLinearVelocity() const · size=40 · insn=10 */
/* @0x2d4864 push {r3, r4, r5, lr} */
/* @0x2d4868 mov r5, r1 */
/* @0x2d486c add r5, r5, #48 */
/* @0x2d4870 mov r4, r0 */
/* @0x2d4874 mov r0, r1 */
/* @0x2d4878 bl 0x2d4644 <_ZNK15b2ParticleGroup16UpdateStatisticsEv> */
/* @0x2d487c ldm r5, {r0, r1} */
/* @0x2d4880 stm r4, {r0, r1} */
/* @0x2d4884 mov r0, r4 */
/* @0x2d4888 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2d488c · b2ParticleGroup::GetAngularVelocity() const · size=20 · insn=5 */
/* @0x2d488c push {r4, lr} */
/* @0x2d4890 mov r4, r0 */
/* @0x2d4894 bl 0x2d4644 <_ZNK15b2ParticleGroup16UpdateStatisticsEv> */
/* @0x2d4898 ldr r0, [r4, #0x38] */
/* @0x2d489c pop {r4, pc} */

/* ── FUNC 0x2d48a0 · b2QueryCallback::~b2QueryCallback() · size=24 · insn=6 */
/* @0x2d48a0 ldr r3, [pc, #0xc] */
/* @0x2d48a4 ldr r3, [pc, r3] */
/* @0x2d48a8 add r3, r3, #8 */
/* @0x2d48ac str r3, [r0] */
/* @0x2d48b0 bx lr */
/* @0x2d48b4 ldrsbeq sp, [r1], -r12 */

/* ── FUNC 0x2d48a0 · b2QueryCallback::~b2QueryCallback() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2d48b8 · b2QueryCallback::ReportParticle(int) · size=8 · insn=2 */
/* @0x2d48b8 mov r0, #0 */
/* @0x2d48bc bx lr */

/* ── FUNC 0x2d48c0 · anon_2d48c0 · size=208 · insn=52 */
/* @0x2d48c0 mov r0, #0 */
/* @0x2d48c4 bx lr */
/* @0x2d48c8 ldr r0, [r0, #0x8] */
/* @0x2d48cc ubfx r0, r0, #0x1, #0x1 */
/* @0x2d48d0 bx lr */
/* @0x2d48d4 ldr r0, [r0] */
/* @0x2d48d8 lsr r0, r0, #31 */
/* @0x2d48dc bx lr */
/* @0x2d48e0 ldr r3, [r0] */
/* @0x2d48e4 cmp r3, #0 */
/* @0x2d48e8 ldrge r0, [r0, #0x4] */
/* @0x2d48ec lsrge r0, r0, #31 */
/* @0x2d48f0 movlt r0, #1 */
/* @0x2d48f4 bx lr */
/* @0x2d48f8 ldr r0, [r0] */
/* @0x2d48fc lsr r0, r0, #31 */
/* @0x2d4900 bx lr */
/* @0x2d4904 ldr r3, [r0] */
/* @0x2d4908 cmp r3, #0 */
/* @0x2d490c ldrge r0, [r0, #0x4] */
/* @0x2d4910 lsrge r0, r0, #31 */
/* @0x2d4914 movlt r0, #1 */
/* @0x2d4918 bx lr */
/* @0x2d491c ldr r3, [r0] */
/* @0x2d4920 cmp r3, #0 */
/* @0x2d4924 blt 0x2d4940 <_ZN15b2QueryCallback14ReportParticleEi+0x88> */
/* @0x2d4928 ldr r3, [r0, #0x4] */
/* @0x2d492c cmp r3, #0 */
/* @0x2d4930 blt 0x2d4940 <_ZN15b2QueryCallback14ReportParticleEi+0x88> */
/* @0x2d4934 ldr r0, [r0, #0x8] */
/* @0x2d4938 lsr r0, r0, #31 */
/* @0x2d493c bx lr */
/* @0x2d4940 mov r0, #1 */
/* @0x2d4944 bx lr */
/* @0x2d4948 ldr r3, [pc, #0xc] */
/* @0x2d494c ldr r3, [pc, r3] */
/* @0x2d4950 add r3, r3, #8 */
/* @0x2d4954 str r3, [r0] */
/* @0x2d4958 bx lr */
/* @0x2d495c andseq sp, r1, r4, lsr r2 */
/* @0x2d4960 ldr r3, [pc, #0xc] */
/* @0x2d4964 ldr r3, [pc, r3] */
/* @0x2d4968 add r3, r3, #8 */
/* @0x2d496c str r3, [r0] */
/* @0x2d4970 bx lr */
/* @0x2d4974 andseq sp, r1, r12, lsl r2 */
/* @0x2d4978 ldr r3, [pc, #0xc] */
/* @0x2d497c ldr r3, [pc, r3] */
/* @0x2d4980 add r3, r3, #8 */
/* @0x2d4984 str r3, [r0] */
/* @0x2d4988 bx lr */
/* @0x2d498c andseq sp, r1, r4, lsl #4 */

/* ── FUNC 0x2d4990 · b2QueryCallback::~b2QueryCallback() · size=40 · insn=10 */
/* @0x2d4990 ldr r3, [pc, #0x1c] */
/* @0x2d4994 push {r4, lr} */
/* @0x2d4998 ldr r3, [pc, r3] */
/* @0x2d499c mov r4, r0 */
/* @0x2d49a0 add r3, r3, #8 */
/* @0x2d49a4 str r3, [r0] */
/* @0x2d49a8 bl 0x27d1d0 <_ZdlPv> */
/* @0x2d49ac mov r0, r4 */
/* @0x2d49b0 pop {r4, pc} */
/* @0x2d49b4 andseq sp, r1, r8, ror #3 */

/* ── FUNC 0x2d49b8 · anon_2d49b8 · size=1540 · insn=385 */
/* @0x2d49b8 ldr r3, [pc, #0x1c] */
/* @0x2d49bc push {r4, lr} */
/* @0x2d49c0 ldr r3, [pc, r3] */
/* @0x2d49c4 mov r4, r0 */
/* @0x2d49c8 add r3, r3, #8 */
/* @0x2d49cc str r3, [r0] */
/* @0x2d49d0 bl 0x27d1d0 <_ZdlPv> */
/* @0x2d49d4 mov r0, r4 */
/* @0x2d49d8 pop {r4, pc} */
/* @0x2d49dc andseq sp, r1, r0, asr #3 */
/* @0x2d49e0 ldr r3, [pc, #0x1c] */
/* @0x2d49e4 push {r4, lr} */
/* @0x2d49e8 ldr r3, [pc, r3] */
/* @0x2d49ec mov r4, r0 */
/* @0x2d49f0 add r3, r3, #8 */
/* @0x2d49f4 str r3, [r0] */
/* @0x2d49f8 bl 0x27d1d0 <_ZdlPv> */
/* @0x2d49fc mov r0, r4 */
/* @0x2d4a00 pop {r4, pc} */
/* @0x2d4a04 mulseq r1, r8, r1 */
/* @0x2d4a08 ldr r3, [pc, #0x1c] */
/* @0x2d4a0c push {r4, lr} */
/* @0x2d4a10 ldr r3, [pc, r3] */
/* @0x2d4a14 mov r4, r0 */
/* @0x2d4a18 add r3, r3, #8 */
/* @0x2d4a1c str r3, [r0] */
/* @0x2d4a20 bl 0x27d1d0 <_ZdlPv> */
/* @0x2d4a24 mov r0, r4 */
/* @0x2d4a28 pop {r4, pc} */
/* @0x2d4a2c andseq sp, r1, r0, ror r1 */
/* @0x2d4a30 push {r3, r4, r5, lr} */
/* @0x2d4a34 mov r4, r0 */
/* @0x2d4a38 ldr r0, [r1] */
/* @0x2d4a3c ldr r1, [r4] */
/* @0x2d4a40 lsl r1, r1, #2 */
/* @0x2d4a44 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2d4a48 ldr r2, [r4] */
/* @0x2d4a4c mov r1, #0 */
/* @0x2d4a50 lsl r2, r2, #2 */
/* @0x2d4a54 mov r5, r0 */
/* @0x2d4a58 bl 0xb65b0 <memset@plt> */
/* @0x2d4a5c mov r0, r5 */
/* @0x2d4a60 pop {r3, r4, r5, pc} */
/* @0x2d4a64 add r12, r1, #1 */
/* @0x2d4a68 sub sp, sp, #8 */
/* @0x2d4a6c lsl r12, r12, #1 */
/* @0x2d4a70 cmp r12, r2 */
/* @0x2d4a74 push {r4, r5, r6, r7, r8} */
/* @0x2d4a78 movge r5, r12 */
/* @0x2d4a7c str r3, [sp, #0x18] */
/* @0x2d4a80 mov r8, r1 */
/* @0x2d4a84 mov r4, r0 */
/* @0x2d4a88 addge r3, r0, r1, lsl #3 */
/* @0x2d4a8c movge r12, r1 */
/* @0x2d4a90 bge 0x2d4ae4 <_ZN15b2QueryCallbackD0Ev+0x154> */
/* @0x2d4a94 mov r7, r1 */
/* @0x2d4a98 b 0x2d4aa0 <_ZN15b2QueryCallbackD0Ev+0x110> */
/* @0x2d4a9c mov r12, r5 */
/* @0x2d4aa0 lsl r3, r12, #3 */
/* @0x2d4aa4 add r6, r4, r7, lsl #3 */
/* @0x2d4aa8 add r0, r4, r3 */
/* @0x2d4aac sub r3, r3, #8 */
/* @0x2d4ab0 add r3, r4, r3 */
/* @0x2d4ab4 ldr r5, [r0, #0x4] */
/* @0x2d4ab8 ldr r1, [r0, #-0x4] */
/* @0x2d4abc cmp r5, r1 */
/* @0x2d4ac0 sublo r12, r12, #1 */
/* @0x2d4ac4 add r5, r12, #1 */
/* @0x2d4ac8 movhs r3, r0 */
/* @0x2d4acc ldm r3, {r0, r1} */
/* @0x2d4ad0 mov r7, r12 */
/* @0x2d4ad4 lsl r5, r5, #1 */
/* @0x2d4ad8 cmp r5, r2 */
/* @0x2d4adc stm r6, {r0, r1} */
/* @0x2d4ae0 blt 0x2d4a9c <_ZN15b2QueryCallbackD0Ev+0x10c> */
/* @0x2d4ae4 cmp r5, r2 */
/* @0x2d4ae8 bne 0x2d4b04 <_ZN15b2QueryCallbackD0Ev+0x174> */
/* @0x2d4aec sub r2, r5, #-536870911 */
/* @0x2d4af0 sub r12, r5, #1 */
/* @0x2d4af4 add r2, r4, r2, lsl #3 */
/* @0x2d4af8 ldm r2, {r0, r1} */
/* @0x2d4afc stm r3, {r0, r1} */
/* @0x2d4b00 mov r3, r2 */
/* @0x2d4b04 cmp r8, r12 */
/* @0x2d4b08 ldr r7, [sp, #0x18] */
/* @0x2d4b0c ldr r5, [sp, #0x1c] */
/* @0x2d4b10 bge 0x2d4b74 <_ZN15b2QueryCallbackD0Ev+0x1e4> */
/* @0x2d4b14 sub r2, r12, #1 */
/* @0x2d4b18 add r2, r2, r2, lsr #31 */
/* @0x2d4b1c asr r2, r2, #1 */
/* @0x2d4b20 lsl r1, r2, #3 */
/* @0x2d4b24 add r0, r4, r1 */
/* @0x2d4b28 ldr r0, [r0, #0x4] */
/* @0x2d4b2c cmp r5, r0 */
/* @0x2d4b30 bls 0x2d4b74 <_ZN15b2QueryCallbackD0Ev+0x1e4> */
/* @0x2d4b34 add r3, r4, r1 */
/* @0x2d4b38 sub r6, r2, #1 */
/* @0x2d4b3c add r12, r4, r12, lsl #3 */
/* @0x2d4b40 cmp r8, r2 */
/* @0x2d4b44 ldm r3, {r0, r1} */
/* @0x2d4b48 add r6, r6, r6, lsr #31 */
/* @0x2d4b4c asr r6, r6, #1 */
/* @0x2d4b50 stm r12, {r0, r1} */
/* @0x2d4b54 bge 0x2d4b74 <_ZN15b2QueryCallbackD0Ev+0x1e4> */
/* @0x2d4b58 lsl r1, r6, #3 */
/* @0x2d4b5c mov r12, r2 */
/* @0x2d4b60 add r0, r4, r1 */
/* @0x2d4b64 mov r2, r6 */
/* @0x2d4b68 ldr r0, [r0, #0x4] */
/* @0x2d4b6c cmp r0, r5 */
/* @0x2d4b70 blo 0x2d4b34 <_ZN15b2QueryCallbackD0Ev+0x1a4> */
/* @0x2d4b74 str r7, [r3] */
/* @0x2d4b78 str r5, [r3, #0x4] */
/* @0x2d4b7c pop {r4, r5, r6, r7, r8} */
/* @0x2d4b80 add sp, sp, #8 */
/* @0x2d4b84 bx lr */
/* @0x2d4b88 rsb r3, r0, r1 */
/* @0x2d4b8c cmp r3, #135 */
/* @0x2d4b90 push {r4, r5, r6, r7, r8, lr} */
/* @0x2d4b94 mov r6, r0 */
/* @0x2d4b98 sub sp, sp, #16 */
/* @0x2d4b9c mov r7, r1 */
/* @0x2d4ba0 mov r8, r2 */
/* @0x2d4ba4 ble 0x2d4d08 <_ZN15b2QueryCallbackD0Ev+0x378> */
/* @0x2d4ba8 cmp r2, #0 */
/* @0x2d4bac beq 0x2d4c8c <_ZN15b2QueryCallbackD0Ev+0x2fc> */
/* @0x2d4bb0 asr r3, r3, #4 */
/* @0x2d4bb4 ldr lr, [r6, #0x4] */
/* @0x2d4bb8 sub r8, r8, #1 */
/* @0x2d4bbc ldr r5, [r7, #-0x4] */
/* @0x2d4bc0 add r3, r6, r3, lsl #3 */
/* @0x2d4bc4 ldr r12, [r3, #0x4] */
/* @0x2d4bc8 cmp lr, r12 */
/* @0x2d4bcc bhs 0x2d4c78 <_ZN15b2QueryCallbackD0Ev+0x2e8> */
/* @0x2d4bd0 cmp r12, r5 */
/* @0x2d4bd4 blo 0x2d4be4 <_ZN15b2QueryCallbackD0Ev+0x254> */
/* @0x2d4bd8 cmp lr, r5 */
/* @0x2d4bdc movhs r12, lr */
/* @0x2d4be0 movlo r12, r5 */
/* @0x2d4be4 mov r3, r7 */
/* @0x2d4be8 mov r2, r6 */
/* @0x2d4bec cmp r12, lr */
/* @0x2d4bf0 mov r4, r2 */
/* @0x2d4bf4 bls 0x2d4c08 <_ZN15b2QueryCallbackD0Ev+0x278> */
/* @0x2d4bf8 add r4, r4, #8 */
/* @0x2d4bfc ldr lr, [r4, #0x4] */
/* @0x2d4c00 cmp lr, r12 */
/* @0x2d4c04 blo 0x2d4bf8 <_ZN15b2QueryCallbackD0Ev+0x268> */
/* @0x2d4c08 cmp r12, r5 */
/* @0x2d4c0c sub r3, r3, #8 */
/* @0x2d4c10 bhs 0x2d4c24 <_ZN15b2QueryCallbackD0Ev+0x294> */
/* @0x2d4c14 sub r3, r3, #8 */
/* @0x2d4c18 ldr r5, [r3, #0x4] */
/* @0x2d4c1c cmp r5, r12 */
/* @0x2d4c20 bhi 0x2d4c14 <_ZN15b2QueryCallbackD0Ev+0x284> */
/* @0x2d4c24 cmp r4, r3 */
/* @0x2d4c28 bhs 0x2d4c4c <_ZN15b2QueryCallbackD0Ev+0x2bc> */
/* @0x2d4c2c ldr r5, [r4] */
/* @0x2d4c30 add r2, r4, #8 */
/* @0x2d4c34 ldm r3, {r0, r1} */
/* @0x2d4c38 stm r4, {r0, r1} */
/* @0x2d4c3c stm r3, {r5, lr} */
/* @0x2d4c40 ldr r5, [r3, #-0x4] */
/* @0x2d4c44 ldr lr, [r4, #0xc] */
/* @0x2d4c48 b 0x2d4bec <_ZN15b2QueryCallbackD0Ev+0x25c> */
/* @0x2d4c4c mov r1, r7 */
/* @0x2d4c50 mov r0, r4 */
/* @0x2d4c54 mov r2, r8 */
/* @0x2d4c58 bl 0x2d4b88 <_ZN15b2QueryCallbackD0Ev+0x1f8> */
/* @0x2d4c5c rsb r3, r6, r4 */
/* @0x2d4c60 cmp r3, #135 */
/* @0x2d4c64 ble 0x2d4d08 <_ZN15b2QueryCallbackD0Ev+0x378> */
/* @0x2d4c68 cmp r8, #0 */
/* @0x2d4c6c beq 0x2d4c90 <_ZN15b2QueryCallbackD0Ev+0x300> */
/* @0x2d4c70 mov r7, r4 */
/* @0x2d4c74 b 0x2d4bb0 <_ZN15b2QueryCallbackD0Ev+0x220> */
/* @0x2d4c78 cmp r12, r5 */
/* @0x2d4c7c movlo r12, r5 */
/* @0x2d4c80 cmp lr, r5 */
/* @0x2d4c84 movlo r12, lr */
/* @0x2d4c88 b 0x2d4be4 <_ZN15b2QueryCallbackD0Ev+0x254> */
/* @0x2d4c8c mov r4, r7 */
/* @0x2d4c90 asr r8, r3, #3 */
/* @0x2d4c94 sub r5, r8, #2 */
/* @0x2d4c98 asr r5, r5, #1 */
/* @0x2d4c9c add r7, r6, r5, lsl #3 */
/* @0x2d4ca0 ldr r12, [r7, #0x4] */
/* @0x2d4ca4 mov r1, r5 */
/* @0x2d4ca8 ldr r3, [r7], #-8 */
/* @0x2d4cac mov r0, r6 */
/* @0x2d4cb0 mov r2, r8 */
/* @0x2d4cb4 str r12, [sp] */
/* @0x2d4cb8 bl 0x2d4a64 <_ZN15b2QueryCallbackD0Ev+0xd4> */
/* @0x2d4cbc cmp r5, #0 */
/* @0x2d4cc0 sub r5, r5, #1 */
/* @0x2d4cc4 bne 0x2d4ca0 <_ZN15b2QueryCallbackD0Ev+0x310> */
/* @0x2d4cc8 add r7, sp, #8 */
/* @0x2d4ccc sub r4, r4, #8 */
/* @0x2d4cd0 rsb r5, r6, r4 */
/* @0x2d4cd4 ldm r4, {r0, r1} */
/* @0x2d4cd8 asr r2, r5, #3 */
/* @0x2d4cdc stm r7, {r0, r1} */
/* @0x2d4ce0 ldm r6, {r0, r1} */
/* @0x2d4ce4 ldr r12, [sp, #0xc] */
/* @0x2d4ce8 ldr r3, [sp, #0x8] */
/* @0x2d4cec stm r4, {r0, r1} */
/* @0x2d4cf0 mov r0, r6 */
/* @0x2d4cf4 str r12, [sp] */
/* @0x2d4cf8 mov r1, #0 */
/* @0x2d4cfc bl 0x2d4a64 <_ZN15b2QueryCallbackD0Ev+0xd4> */
/* @0x2d4d00 cmp r5, #15 */
/* @0x2d4d04 bgt 0x2d4ccc <_ZN15b2QueryCallbackD0Ev+0x33c> */
/* @0x2d4d08 add sp, sp, #16 */
/* @0x2d4d0c pop {r4, r5, r6, r7, r8, pc} */
/* @0x2d4d10 cmp r0, r1 */
/* @0x2d4d14 push {r4, r5, r6, r7, r8, r9, r10} */
/* @0x2d4d18 mov r6, r0 */
/* @0x2d4d1c mov r9, r1 */
/* @0x2d4d20 beq 0x2d4d94 <_ZN15b2QueryCallbackD0Ev+0x404> */
/* @0x2d4d24 add r4, r0, #8 */
/* @0x2d4d28 cmp r1, r4 */
/* @0x2d4d2c beq 0x2d4d94 <_ZN15b2QueryCallbackD0Ev+0x404> */
/* @0x2d4d30 add r5, r0, #16 */
/* @0x2d4d34 ldr r12, [r4, #0x4] */
/* @0x2d4d38 mov r2, r4 */
/* @0x2d4d3c ldr r3, [r6, #0x4] */
/* @0x2d4d40 mov r7, r5 */
/* @0x2d4d44 ldr r8, [r5, #-0x8] */
/* @0x2d4d48 cmp r12, r3 */
/* @0x2d4d4c bhs 0x2d4d9c <_ZN15b2QueryCallbackD0Ev+0x40c> */
/* @0x2d4d50 rsb r2, r6, r4 */
/* @0x2d4d54 asr r2, r2, #3 */
/* @0x2d4d58 cmp r2, #0 */
/* @0x2d4d5c movgt r10, r5 */
/* @0x2d4d60 ble 0x2d4d80 <_ZN15b2QueryCallbackD0Ev+0x3f0> */
/* @0x2d4d64 sub r1, r10, #16 */
/* @0x2d4d68 sub r3, r10, #8 */
/* @0x2d4d6c subs r2, r2, #1 */
/* @0x2d4d70 ldm r1, {r0, r1} */
/* @0x2d4d74 mov r10, r3 */
/* @0x2d4d78 stm r3, {r0, r1} */
/* @0x2d4d7c bne 0x2d4d64 <_ZN15b2QueryCallbackD0Ev+0x3d4> */
/* @0x2d4d80 stm r6, {r8, r12} */
/* @0x2d4d84 cmp r9, r7 */
/* @0x2d4d88 add r4, r4, #8 */
/* @0x2d4d8c add r5, r5, #8 */
/* @0x2d4d90 bne 0x2d4d34 <_ZN15b2QueryCallbackD0Ev+0x3a4> */
/* @0x2d4d94 pop {r4, r5, r6, r7, r8, r9, r10} */
/* @0x2d4d98 bx lr */
/* @0x2d4d9c ldr r1, [r4, #-0x4] */
/* @0x2d4da0 sub r3, r4, #8 */
/* @0x2d4da4 cmp r12, r1 */
/* @0x2d4da8 blo 0x2d4db4 <_ZN15b2QueryCallbackD0Ev+0x424> */
/* @0x2d4dac b 0x2d4dd8 <_ZN15b2QueryCallbackD0Ev+0x448> */
/* @0x2d4db0 mov r3, r10 */
/* @0x2d4db4 ldm r3, {r0, r1} */
/* @0x2d4db8 sub r10, r3, #8 */
/* @0x2d4dbc stm r2, {r0, r1} */
/* @0x2d4dc0 mov r2, r3 */
/* @0x2d4dc4 ldr r1, [r3, #-0x4] */
/* @0x2d4dc8 cmp r12, r1 */
/* @0x2d4dcc blo 0x2d4db0 <_ZN15b2QueryCallbackD0Ev+0x420> */
/* @0x2d4dd0 stm r3, {r8, r12} */
/* @0x2d4dd4 b 0x2d4d84 <_ZN15b2QueryCallbackD0Ev+0x3f4> */
/* @0x2d4dd8 mov r3, r4 */
/* @0x2d4ddc stm r3, {r8, r12} */
/* @0x2d4de0 b 0x2d4d84 <_ZN15b2QueryCallbackD0Ev+0x3f4> */
/* @0x2d4de4 rsb r3, r0, r1 */
/* @0x2d4de8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2d4dec vpush {d8} */
/* @0x2d4df0 asrs r3, r3, #3 */
/* @0x2d4df4 sub sp, sp, #20 */
/* @0x2d4df8 mov r9, r2 */
/* @0x2d4dfc rsb r2, r1, r2 */
/* @0x2d4e00 mov r6, r0 */
/* @0x2d4e04 add r2, r0, r2 */
/* @0x2d4e08 mov r4, r1 */
/* @0x2d4e0c str r3, [sp] */
/* @0x2d4e10 moveq r0, r9 */
/* @0x2d4e14 str r2, [sp, #0xc] */
/* @0x2d4e18 beq 0x2d4e8c <_ZN15b2QueryCallbackD0Ev+0x4fc> */
/* @0x2d4e1c rsb r0, r6, r9 */
/* @0x2d4e20 asr r0, r0, #3 */
/* @0x2d4e24 rsb r2, r3, r0 */
/* @0x2d4e28 str r2, [sp, #0x4] */
/* @0x2d4e2c cmp r3, r2 */
/* @0x2d4e30 ldrne r10, [sp] */
/* @0x2d4e34 bne 0x2d4e9c <_ZN15b2QueryCallbackD0Ev+0x50c> */
/* @0x2d4e38 cmp r6, r1 */
/* @0x2d4e3c beq 0x2d4e88 <_ZN15b2QueryCallbackD0Ev+0x4f8> */
/* @0x2d4e40 add r12, r6, #8 */
/* @0x2d4e44 add r3, r1, #8 */
/* @0x2d4e48 mov r7, r1 */
/* @0x2d4e4c mov r5, r12 */
/* @0x2d4e50 mov r2, r5 */
/* @0x2d4e54 ldmdb r3, {r0, r1} */
/* @0x2d4e58 ldr r8, [r6, #0x4] */
/* @0x2d4e5c cmp r4, r12 */
/* @0x2d4e60 ldr r9, [r2, #-0x8]! */
/* @0x2d4e64 mov r6, r12 */
/* @0x2d4e68 add r5, r5, #8 */
/* @0x2d4e6c add r12, r12, #8 */
/* @0x2d4e70 add r3, r3, #8 */
/* @0x2d4e74 add r7, r7, #8 */
/* @0x2d4e78 stm r2, {r0, r1} */
/* @0x2d4e7c str r9, [r3, #-0x10] */
/* @0x2d4e80 str r8, [r7, #-0x4] */
/* @0x2d4e84 bne 0x2d4e50 <_ZN15b2QueryCallbackD0Ev+0x4c0> */
/* @0x2d4e88 ldr r0, [sp, #0xc] */
/* @0x2d4e8c add sp, sp, #20 */
/* @0x2d4e90 vpop {d8} */
/* @0x2d4e94 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2d4e98 mov r10, r1 */
/* @0x2d4e9c mov r1, r10 */
/* @0x2d4ea0 bl 0x318dec <__aeabi_idivmod> */
/* @0x2d4ea4 mov r0, r10 */
/* @0x2d4ea8 cmp r1, #0 */
/* @0x2d4eac bne 0x2d4e98 <_ZN15b2QueryCallbackD0Ev+0x508> */
/* @0x2d4eb0 cmp r10, #0 */
/* @0x2d4eb4 ble 0x2d4e88 <_ZN15b2QueryCallbackD0Ev+0x4f8> */
/* @0x2d4eb8 ldr r3, [sp, #0x4] */
/* @0x2d4ebc mov r11, r1 */
/* @0x2d4ec0 ldr r2, [sp] */
/* @0x2d4ec4 lsl r3, r3, #3 */
/* @0x2d4ec8 str r3, [sp, #0x8] */
/* @0x2d4ecc lsl r4, r2, #3 */
/* @0x2d4ed0 rsb r5, r3, #0 */
/* @0x2d4ed4 rsb r9, r4, r9 */
/* @0x2d4ed8 ldr r3, [sp] */
/* @0x2d4edc vldr s17, [r6] */
/* @0x2d4ee0 ldr r2, [sp, #0x4] */
/* @0x2d4ee4 vldr s16, [r6, #4] */
/* @0x2d4ee8 cmp r3, r2 */
/* @0x2d4eec blt 0x2d4f5c <_ZN15b2QueryCallbackD0Ev+0x5cc> */
/* @0x2d4ef0 mov r0, r3 */
/* @0x2d4ef4 mov r1, r10 */
/* @0x2d4ef8 bl 0x318d10 <__divsi3> */
/* @0x2d4efc cmp r0, #1 */
/* @0x2d4f00 subgt r7, r0, #1 */
/* @0x2d4f04 movgt r2, r6 */
/* @0x2d4f08 movgt r12, #0 */
/* @0x2d4f0c ble 0x2d4fb4 <_ZN15b2QueryCallbackD0Ev+0x624> */
/* @0x2d4f10 cmp r9, r2 */
/* @0x2d4f14 add r3, r2, r4 */
/* @0x2d4f18 add r12, r12, #1 */
/* @0x2d4f1c ldmhi r3, {r0, r1} */
/* @0x2d4f20 stmhi r2, {r0, r1} */
/* @0x2d4f24 movhi r2, r3 */
/* @0x2d4f28 add r3, r2, r5 */
/* @0x2d4f2c cmp r12, r7 */
/* @0x2d4f30 ldm r3, {r0, r1} */
/* @0x2d4f34 stm r2, {r0, r1} */
/* @0x2d4f38 mov r2, r3 */
/* @0x2d4f3c bne 0x2d4f10 <_ZN15b2QueryCallbackD0Ev+0x580> */
/* @0x2d4f40 add r11, r11, #1 */
/* @0x2d4f44 vstr s17, [r3] */
/* @0x2d4f48 cmp r11, r10 */
/* @0x2d4f4c vstr s16, [r3, #4] */
/* @0x2d4f50 add r6, r6, #8 */
/* @0x2d4f54 bne 0x2d4ed8 <_ZN15b2QueryCallbackD0Ev+0x548> */
/* @0x2d4f58 b 0x2d4e88 <_ZN15b2QueryCallbackD0Ev+0x4f8> */
/* @0x2d4f5c ldr r0, [sp, #0x4] */
/* @0x2d4f60 mov r1, r10 */
/* @0x2d4f64 bl 0x318d10 <__divsi3> */
/* @0x2d4f68 subs r7, r0, #0 */
/* @0x2d4f6c ble 0x2d4fb4 <_ZN15b2QueryCallbackD0Ev+0x624> */
/* @0x2d4f70 ldr r3, [sp, #0x8] */
/* @0x2d4f74 mov r2, r6 */
/* @0x2d4f78 mov r12, #0 */
/* @0x2d4f7c add r8, r6, r3 */
/* @0x2d4f80 cmp r8, r2 */
/* @0x2d4f84 add r3, r2, r5 */
/* @0x2d4f88 add r12, r12, #1 */
/* @0x2d4f8c ldmlo r3, {r0, r1} */
/* @0x2d4f90 stmlo r2, {r0, r1} */
/* @0x2d4f94 movlo r2, r3 */
/* @0x2d4f98 add r3, r2, r4 */
/* @0x2d4f9c cmp r12, r7 */
/* @0x2d4fa0 ldm r3, {r0, r1} */
/* @0x2d4fa4 stm r2, {r0, r1} */
/* @0x2d4fa8 mov r2, r3 */
/* @0x2d4fac bne 0x2d4f80 <_ZN15b2QueryCallbackD0Ev+0x5f0> */
/* @0x2d4fb0 b 0x2d4f40 <_ZN15b2QueryCallbackD0Ev+0x5b0> */
/* @0x2d4fb4 mov r3, r6 */
/* @0x2d4fb8 b 0x2d4f40 <_ZN15b2QueryCallbackD0Ev+0x5b0> */

/* ── FUNC 0x2d4fbc · b2ParticleSystem::b2ParticleSystem() · size=268 · insn=67 */
/* @0x2d4fbc mov r2, #0 */
/* @0x2d4fc0 mov r1, #1065353216 */
/* @0x2d4fc4 push {r4, r5, r6, r7} */
/* @0x2d4fc8 mov r4, #1048576000 */
/* @0x2d4fcc mov r12, #1056964608 */
/* @0x2d4fd0 movw r7, #0xcccd */
/* @0x2d4fd4 str r2, [r0, #0x30] */
/* @0x2d4fd8 movt r7, #0x3d4c */
/* @0x2d4fdc movw r6, #0xcccd */
/* @0x2d4fe0 str r2, [r0, #0x34] */
/* @0x2d4fe4 movt r6, #0x3dcc */
/* @0x2d4fe8 movw r5, #0xcccd */
/* @0x2d4fec str r2, [r0, #0x38] */
/* @0x2d4ff0 movt r5, #0x3e4c */
/* @0x2d4ff4 str r2, [r0, #0x3c] */
/* @0x2d4ff8 str r2, [r0, #0x40] */
/* @0x2d4ffc str r2, [r0, #0x44] */
/* @0x2d5000 str r2, [r0, #0x54] */
/* @0x2d5004 str r2, [r0, #0x58] */
/* @0x2d5008 str r1, [r0, #0xc] */
/* @0x2d500c str r1, [r0, #0x10] */
/* @0x2d5010 str r1, [r0, #0x14] */
/* @0x2d5014 str r1, [r0, #0x18] */
/* @0x2d5018 str r1, [r0, #0x1c] */
/* @0x2d501c str r1, [r0, #0x20] */
/* @0x2d5020 str r2, [r0, #0x60] */
/* @0x2d5024 str r2, [r0, #0x64] */
/* @0x2d5028 str r2, [r0] */
/* @0x2d502c str r2, [r0, #0x4] */
/* @0x2d5030 str r2, [r0, #0x8] */
/* @0x2d5034 str r2, [r0, #0x24] */
/* @0x2d5038 str r2, [r0, #0x28] */
/* @0x2d503c str r2, [r0, #0x2c] */
/* @0x2d5040 str r2, [r0, #0x48] */
/* @0x2d5044 str r2, [r0, #0x4c] */
/* @0x2d5048 str r2, [r0, #0x50] */
/* @0x2d504c str r2, [r0, #0x5c] */
/* @0x2d5050 str r2, [r0, #0x68] */
/* @0x2d5054 str r2, [r0, #0x6c] */
/* @0x2d5058 str r2, [r0, #0x70] */
/* @0x2d505c str r2, [r0, #0x74] */
/* @0x2d5060 str r2, [r0, #0x78] */
/* @0x2d5064 str r2, [r0, #0x7c] */
/* @0x2d5068 str r2, [r0, #0x80] */
/* @0x2d506c str r7, [r0, #0xac] */
/* @0x2d5070 str r6, [r0, #0xc0] */
/* @0x2d5074 str r5, [r0, #0xc4] */
/* @0x2d5078 str r4, [r0, #0xb4] */
/* @0x2d507c str r4, [r0, #0xb8] */
/* @0x2d5080 str r4, [r0, #0xbc] */
/* @0x2d5084 str r2, [r0, #0x84] */
/* @0x2d5088 str r1, [r0, #0xb0] */
/* @0x2d508c str r2, [r0, #0x88] */
/* @0x2d5090 str r2, [r0, #0x8c] */
/* @0x2d5094 str r2, [r0, #0x90] */
/* @0x2d5098 str r2, [r0, #0x94] */
/* @0x2d509c str r2, [r0, #0x98] */
/* @0x2d50a0 str r2, [r0, #0x9c] */
/* @0x2d50a4 str r2, [r0, #0xa0] */
/* @0x2d50a8 str r12, [r0, #0xc8] */
/* @0x2d50ac str r2, [r0, #0xa4] */
/* @0x2d50b0 str r12, [r0, #0xcc] */
/* @0x2d50b4 str r2, [r0, #0xa8] */
/* @0x2d50b8 str r12, [r0, #0xd0] */
/* @0x2d50bc str r2, [r0, #0xd4] */
/* @0x2d50c0 pop {r4, r5, r6, r7} */
/* @0x2d50c4 bx lr */

/* ── FUNC 0x2d4fbc · b2ParticleSystem::b2ParticleSystem() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2d50c8 · b2ParticleSystem::~b2ParticleSystem() · size=248 · insn=62 */
/* @0x2d50c8 push {r4, lr} */
/* @0x2d50cc mov r4, r0 */
/* @0x2d50d0 ldr r0, [r0, #0xd4] */
/* @0x2d50d4 cmp r0, #0 */
/* @0x2d50d8 beq 0x2d51b8 <_ZN16b2ParticleSystemD2Ev+0xf0> */
/* @0x2d50dc ldr r2, [r4, #0x28] */
/* @0x2d50e0 ldr r1, [r4, #0x30] */
/* @0x2d50e4 lsl r2, r2, #2 */
/* @0x2d50e8 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2d50ec ldr r2, [r4, #0x28] */
/* @0x2d50f0 ldr r0, [r4, #0xd4] */
/* @0x2d50f4 ldr r1, [r4, #0x38] */
/* @0x2d50f8 lsl r2, r2, #3 */
/* @0x2d50fc bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2d5100 ldr r2, [r4, #0x28] */
/* @0x2d5104 ldr r0, [r4, #0xd4] */
/* @0x2d5108 ldr r1, [r4, #0x40] */
/* @0x2d510c lsl r2, r2, #3 */
/* @0x2d5110 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2d5114 ldr r2, [r4, #0x28] */
/* @0x2d5118 ldr r0, [r4, #0xd4] */
/* @0x2d511c ldr r1, [r4, #0x54] */
/* @0x2d5120 lsl r2, r2, #2 */
/* @0x2d5124 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2d5128 ldr r2, [r4, #0x28] */
/* @0x2d512c ldr r0, [r4, #0xd4] */
/* @0x2d5130 ldr r1, [r4, #0x60] */
/* @0x2d5134 lsl r2, r2, #2 */
/* @0x2d5138 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2d513c ldr r2, [r4, #0x28] */
/* @0x2d5140 ldr r0, [r4, #0xd4] */
/* @0x2d5144 ldr r1, [r4, #0x50] */
/* @0x2d5148 lsl r2, r2, #2 */
/* @0x2d514c bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2d5150 ldr r2, [r4, #0x28] */
/* @0x2d5154 ldr r0, [r4, #0xd4] */
/* @0x2d5158 ldr r1, [r4, #0x5c] */
/* @0x2d515c lsl r2, r2, #2 */
/* @0x2d5160 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2d5164 ldr r2, [r4, #0x28] */
/* @0x2d5168 ldr r0, [r4, #0xd4] */
/* @0x2d516c ldr r1, [r4, #0x48] */
/* @0x2d5170 lsl r2, r2, #2 */
/* @0x2d5174 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2d5178 ldr r2, [r4, #0x28] */
/* @0x2d517c ldr r0, [r4, #0xd4] */
/* @0x2d5180 ldr r1, [r4, #0x4c] */
/* @0x2d5184 lsl r2, r2, #3 */
/* @0x2d5188 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2d518c ldr r2, [r4, #0x78] */
/* @0x2d5190 ldr r0, [r4, #0xd4] */
/* @0x2d5194 ldr r1, [r4, #0x7c] */
/* @0x2d5198 add r2, r2, r2, lsl #1 */
/* @0x2d519c lsl r2, r2, #3 */
/* @0x2d51a0 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2d51a4 ldr r2, [r4, #0x6c] */
/* @0x2d51a8 ldr r0, [r4, #0xd4] */
/* @0x2d51ac ldr r1, [r4, #0x70] */
/* @0x2d51b0 lsl r2, r2, #3 */
/* @0x2d51b4 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2d51b8 mov r0, r4 */
/* @0x2d51bc pop {r4, pc} */

/* ── FUNC 0x2d50c8 · b2ParticleSystem::~b2ParticleSystem() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2d51c0 · b2ParticleSystem::DestroyParticle(int, bool) · size=36 · insn=9 */
/* @0x2d51c0 ldr r3, [r0, #0x30] */
/* @0x2d51c4 cmp r2, #0 */
/* @0x2d51c8 movw r0, #0x202 */
/* @0x2d51cc movne r2, r0 */
/* @0x2d51d0 moveq r2, #2 */
/* @0x2d51d4 ldr r0, [r3, r1, lsl #2] */
/* @0x2d51d8 orr r0, r0, r2 */
/* @0x2d51dc str r0, [r3, r1, lsl #2] */
/* @0x2d51e0 bx lr */

/* ── FUNC 0x2d51e4 · anon_2d51e4 · size=88 · insn=22 */
/* @0x2d51e4 push {r3, r4, r5, lr} */
/* @0x2d51e8 mov r4, r0 */
/* @0x2d51ec ldr r0, [r0, #0x8] */
/* @0x2d51f0 mov r5, r1 */
/* @0x2d51f4 ldr r2, [r4, #0x4] */
/* @0x2d51f8 add r1, r4, #12 */
/* @0x2d51fc ldr r3, [r0] */
/* @0x2d5200 ldr r2, [r2, #0x38] */
/* @0x2d5204 ldr r3, [r3, #0x10] */
/* @0x2d5208 add r2, r2, r5, lsl #3 */
/* @0x2d520c blx r3 */
/* @0x2d5210 cmp r0, #0 */
/* @0x2d5214 beq 0x2d5234 <_ZN16b2ParticleSystem15DestroyParticleEib+0x74> */
/* @0x2d5218 mov r1, r5 */
/* @0x2d521c ldr r0, [r4, #0x4] */
/* @0x2d5220 ldrb r2, [r4, #0x1c] */
/* @0x2d5224 bl 0x2d51c0 <_ZN16b2ParticleSystem15DestroyParticleEib> */
/* @0x2d5228 ldr r3, [r4, #0x20] */
/* @0x2d522c add r3, r3, #1 */
/* @0x2d5230 str r3, [r4, #0x20] */
/* @0x2d5234 mov r0, #1 */
/* @0x2d5238 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2d523c · b2ParticleSystem::DestroyParticlesInShape(b2Shape const&, b2Transform const&, bool) · size=136 · insn=34 */
/* @0x2d523c push {r4, r5, r6, r7, r8, lr} */
/* @0x2d5240 mov r12, r2 */
/* @0x2d5244 mov r4, r1 */
/* @0x2d5248 mov r5, r0 */
/* @0x2d524c mov lr, r3 */
/* @0x2d5250 sub sp, sp, #56 */
/* @0x2d5254 ldm r2, {r0, r1, r2, r3} */
/* @0x2d5258 mov r6, #0 */
/* @0x2d525c strb lr, [sp, #0x30] */
/* @0x2d5260 add lr, sp, #32 */
/* @0x2d5264 ldr r8, [r4] */
/* @0x2d5268 ldr r7, [pc, #0x50] */
/* @0x2d526c stm lr, {r0, r1, r2, r3} */
/* @0x2d5270 mov r0, r4 */
/* @0x2d5274 str r4, [sp, #0x1c] */
/* @0x2d5278 add r4, sp, #4 */
/* @0x2d527c add r7, pc, r7 */
/* @0x2d5280 mov r2, r12 */
/* @0x2d5284 mov r1, r4 */
/* @0x2d5288 ldr r12, [r8, #0x1c] */
/* @0x2d528c mov r3, r6 */
/* @0x2d5290 str r5, [sp, #0x18] */
/* @0x2d5294 add r7, r7, #8 */
/* @0x2d5298 str r6, [sp, #0x34] */
/* @0x2d529c str r7, [sp, #0x14] */
/* @0x2d52a0 blx r12 */
/* @0x2d52a4 ldr r0, [r5, #0xd4] */
/* @0x2d52a8 mov r2, r4 */
/* @0x2d52ac add r1, sp, #20 */
/* @0x2d52b0 bl 0x2cb89c <_ZNK7b2World9QueryAABBEP15b2QueryCallbackRK6b2AABB> */
/* @0x2d52b4 ldr r0, [sp, #0x34] */
/* @0x2d52b8 add sp, sp, #56 */
/* @0x2d52bc pop {r4, r5, r6, r7, r8, pc} */
/* @0x2d52c0 andseq r3, r1, r12, asr #13 */

/* ── FUNC 0x2d52c4 · b2ParticleSystem::DestroyParticlesInGroup(b2ParticleGroup*, bool) · size=68 · insn=17 */
/* @0x2d52c4 push {r3, r4, r5, r6, r7, lr} */
/* @0x2d52c8 mov r5, r1 */
/* @0x2d52cc ldr r4, [r1, #0x4] */
/* @0x2d52d0 mov r7, r0 */
/* @0x2d52d4 ldr r3, [r1, #0x8] */
/* @0x2d52d8 mov r6, r2 */
/* @0x2d52dc cmp r4, r3 */
/* @0x2d52e0 popge {r3, r4, r5, r6, r7, pc} */
/* @0x2d52e4 mov r1, r4 */
/* @0x2d52e8 mov r0, r7 */
/* @0x2d52ec mov r2, r6 */
/* @0x2d52f0 add r4, r4, #1 */
/* @0x2d52f4 bl 0x2d51c0 <_ZN16b2ParticleSystem15DestroyParticleEib> */
/* @0x2d52f8 ldr r3, [r5, #0x8] */
/* @0x2d52fc cmp r3, r4 */
/* @0x2d5300 bgt 0x2d52e4 <_ZN16b2ParticleSystem23DestroyParticlesInGroupEP15b2ParticleGroupb+0x20> */
/* @0x2d5304 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2d5308 · b2ParticleSystem::CreateParticleGroupCallback::operator()(int, int, int) const · size=632 · insn=158 */
/* @0x2d5308 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2d530c vpush {d8, d9, d10} */
/* @0x2d5310 vmov.f32 s14, #4.000000e+00 */
/* @0x2d5314 ldr r7, [r0] */
/* @0x2d5318 vldr s9, [r7, #32] */
/* @0x2d531c sub sp, sp, #20 */
/* @0x2d5320 mov r12, r0 */
/* @0x2d5324 mov r8, r1 */
/* @0x2d5328 mov r9, r2 */
/* @0x2d532c ldr r5, [r7, #0x38] */
/* @0x2d5330 mov r10, r3 */
/* @0x2d5334 add r6, r5, r1, lsl #3 */
/* @0x2d5338 add r4, r5, r2, lsl #3 */
/* @0x2d533c vldr s10, [r6, #4] */
/* @0x2d5340 vldr s12, [r4, #4] */
/* @0x2d5344 vldr s11, [r6] */
/* @0x2d5348 vldr s13, [r4] */
/* @0x2d534c add r5, r5, r3, lsl #3 */
/* @0x2d5350 vldr s8, [r5] */
/* @0x2d5354 vsub.f32 s17, s10, s12 */
/* @0x2d5358 vldr s7, [r5, #4] */
/* @0x2d535c vmul.f32 s15, s17, s17 */
/* @0x2d5360 vsub.f32 s16, s11, s13 */
/* @0x2d5364 vmla.f32 s15, s16, s16 */
/* @0x2d5368 vmul.f32 s14, s9, s14 */
/* @0x2d536c vcmpe.f32 s14, s15 */
/* @0x2d5370 vmrs APSR_nzcv, fpscr */
/* @0x2d5374 ble 0x2d5570 <_ZNK16b2ParticleSystem27CreateParticleGroupCallbackclEiii+0x268> */
/* @0x2d5378 vsub.f32 s19, s12, s7 */
/* @0x2d537c vmul.f32 s15, s19, s19 */
/* @0x2d5380 vsub.f32 s18, s13, s8 */
/* @0x2d5384 vmla.f32 s15, s18, s18 */
/* @0x2d5388 vcmpe.f32 s14, s15 */
/* @0x2d538c vmrs APSR_nzcv, fpscr */
/* @0x2d5390 ble 0x2d5570 <_ZNK16b2ParticleSystem27CreateParticleGroupCallbackclEiii+0x268> */
/* @0x2d5394 vsub.f32 s21, s7, s10 */
/* @0x2d5398 vmul.f32 s15, s21, s21 */
/* @0x2d539c vsub.f32 s20, s8, s11 */
/* @0x2d53a0 vmla.f32 s15, s20, s20 */
/* @0x2d53a4 vcmpe.f32 s14, s15 */
/* @0x2d53a8 vmrs APSR_nzcv, fpscr */
/* @0x2d53ac ble 0x2d5570 <_ZNK16b2ParticleSystem27CreateParticleGroupCallbackclEiii+0x268> */
/* @0x2d53b0 ldr r3, [r7, #0x98] */
/* @0x2d53b4 ldr r2, [r7, #0x9c] */
/* @0x2d53b8 cmp r3, r2 */
/* @0x2d53bc blt 0x2d5460 <_ZNK16b2ParticleSystem27CreateParticleGroupCallbackclEiii+0x158> */
/* @0x2d53c0 cmp r3, #0 */
/* @0x2d53c4 ldr r0, [r7, #0xd4] */
/* @0x2d53c8 lslne r1, r3, #1 */
/* @0x2d53cc strne r1, [sp, #0x8] */
/* @0x2d53d0 rsbne r3, r1, r3, lsl #5 */
/* @0x2d53d4 moveq r1, #15360 */
/* @0x2d53d8 ldr r11, [r7, #0xa0] */
/* @0x2d53dc moveq r3, #256 */
/* @0x2d53e0 lslne r1, r3, #2 */
/* @0x2d53e4 streq r3, [sp, #0x8] */
/* @0x2d53e8 str r12, [sp] */
/* @0x2d53ec str r2, [sp, #0x4] */
/* @0x2d53f0 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2d53f4 ldr r2, [sp, #0x4] */
/* @0x2d53f8 mov r1, r11 */
/* @0x2d53fc rsb r2, r2, r2, lsl #4 */
/* @0x2d5400 lsl r3, r2, #2 */
/* @0x2d5404 str r3, [sp, #0x4] */
/* @0x2d5408 mov r2, r3 */
/* @0x2d540c str r0, [sp, #0xc] */
/* @0x2d5410 bl 0xb65bc <memcpy@plt> */
/* @0x2d5414 ldr r3, [sp, #0x4] */
/* @0x2d5418 mov r1, r11 */
/* @0x2d541c ldr r0, [r7, #0xd4] */
/* @0x2d5420 mov r2, r3 */
/* @0x2d5424 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2d5428 ldr r12, [sp] */
/* @0x2d542c ldr r3, [sp, #0xc] */
/* @0x2d5430 vldr s11, [r6] */
/* @0x2d5434 ldr r1, [sp, #0x8] */
/* @0x2d5438 vldr s13, [r4] */
/* @0x2d543c ldr r2, [r12] */
/* @0x2d5440 vldr s10, [r6, #4] */
/* @0x2d5444 str r3, [r7, #0xa0] */
/* @0x2d5448 vldr s12, [r4, #4] */
/* @0x2d544c vldr s8, [r5] */
/* @0x2d5450 vldr s7, [r5, #4] */
/* @0x2d5454 ldr r3, [r2, #0x98] */
/* @0x2d5458 mov r7, r2 */
/* @0x2d545c str r1, [r2, #0x9c] */
/* @0x2d5460 vadd.f32 s13, s11, s13 */
/* @0x2d5464 vldr s15, [pc, #272] */
/* @0x2d5468 rsb r1, r3, r3, lsl #4 */
/* @0x2d546c ldr r0, [r7, #0xa0] */
/* @0x2d5470 ldr r2, [r7, #0x30] */
/* @0x2d5474 add r11, r3, #1 */
/* @0x2d5478 lsl r1, r1, #2 */
/* @0x2d547c ldr r3, [r12, #0x4] */
/* @0x2d5480 vldr s14, [r3, #36] */
/* @0x2d5484 add r3, r0, r1 */
/* @0x2d5488 str r8, [r0, r1] */
/* @0x2d548c stmib r3, {r9, r10} */
/* @0x2d5490 ldr r1, [r2, r8, lsl #2] */
/* @0x2d5494 ldr r12, [r2, r9, lsl #2] */
/* @0x2d5498 ldr r0, [r2, r10, lsl #2] */
/* @0x2d549c vstr s14, [r3, #16] */
/* @0x2d54a0 vadd.f32 s12, s10, s12 */
/* @0x2d54a4 orr r2, r12, r0 */
/* @0x2d54a8 orr r2, r2, r1 */
/* @0x2d54ac str r2, [r3, #0xc] */
/* @0x2d54b0 vadd.f32 s13, s13, s8 */
/* @0x2d54b4 vadd.f32 s12, s12, s7 */
/* @0x2d54b8 vmul.f32 s13, s13, s15 */
/* @0x2d54bc vmul.f32 s12, s12, s15 */
/* @0x2d54c0 vsub.f32 s11, s11, s13 */
/* @0x2d54c4 vsub.f32 s10, s10, s12 */
/* @0x2d54c8 vstr s11, [r3, #20] */
/* @0x2d54cc vstr s10, [r3, #24] */
/* @0x2d54d0 vldr s14, [r4, #4] */
/* @0x2d54d4 vldr s15, [r4] */
/* @0x2d54d8 vsub.f32 s14, s14, s12 */
/* @0x2d54dc vsub.f32 s15, s15, s13 */
/* @0x2d54e0 vstr s14, [r3, #32] */
/* @0x2d54e4 vstr s15, [r3, #28] */
/* @0x2d54e8 vldr s14, [r5, #4] */
/* @0x2d54ec vldr s15, [r5] */
/* @0x2d54f0 vsub.f32 s12, s14, s12 */
/* @0x2d54f4 vsub.f32 s13, s15, s13 */
/* @0x2d54f8 vstr s12, [r3, #40] */
/* @0x2d54fc vstr s13, [r3, #36] */
/* @0x2d5500 vldr s8, [r4, #4] */
/* @0x2d5504 vldr s11, [r5] */
/* @0x2d5508 vldr s10, [r6, #4] */
/* @0x2d550c vldr s9, [r4] */
/* @0x2d5510 vmul.f32 s13, s8, s11 */
/* @0x2d5514 vldr s15, [r5, #4] */
/* @0x2d5518 vldr s7, [r6] */
/* @0x2d551c vmul.f32 s12, s10, s9 */
/* @0x2d5520 vmul.f32 s14, s7, s15 */
/* @0x2d5524 vnmls.f32 s13, s9, s15 */
/* @0x2d5528 vnmls.f32 s12, s7, s8 */
/* @0x2d552c vmul.f32 s15, s17, s21 */
/* @0x2d5530 vmul.f32 s17, s17, s19 */
/* @0x2d5534 vmul.f32 s19, s19, s21 */
/* @0x2d5538 vnmls.f32 s14, s10, s11 */
/* @0x2d553c vmla.f32 s15, s16, s20 */
/* @0x2d5540 vmla.f32 s17, s16, s18 */
/* @0x2d5544 vmla.f32 s19, s18, s20 */
/* @0x2d5548 vadd.f32 s13, s12, s13 */
/* @0x2d554c vadd.f32 s14, s13, s14 */
/* @0x2d5550 vneg.f32 s15, s15 */
/* @0x2d5554 vstr s14, [r3, #56] */
/* @0x2d5558 vneg.f32 s17, s17 */
/* @0x2d555c vstr s15, [r3, #44] */
/* @0x2d5560 vneg.f32 s19, s19 */
/* @0x2d5564 vstr s17, [r3, #48] */
/* @0x2d5568 vstr s19, [r3, #52] */
/* @0x2d556c str r11, [r7, #0x98] */
/* @0x2d5570 add sp, sp, #20 */
/* @0x2d5574 vpop {d8, d9, d10} */
/* @0x2d5578 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2d557c .word 0x3eaaaaab */
