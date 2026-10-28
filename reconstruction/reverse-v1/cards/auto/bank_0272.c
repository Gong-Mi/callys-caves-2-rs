/* libyoyo.so 覆盖卡组 0272
 * 函数 0x2cb4d8..0x2cbe0c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2cb4d8 · b2World::DestroyParticlesInShape(b2Shape const&, b2Transform const&, bool) · size=40 · insn=10 */
/* @0x2cb4d8 movw r12, #0x91d4 */
/* @0x2cb4dc movt r12, #0x1 */
/* @0x2cb4e0 ldr r12, [r0, r12] */
/* @0x2cb4e4 tst r12, #2 */
/* @0x2cb4e8 beq 0x2cb4f4 <_ZN7b2World23DestroyParticlesInShapeERK7b2ShapeRK11b2Transformb+0x1c> */
/* @0x2cb4ec mov r0, #0 */
/* @0x2cb4f0 bx lr */
/* @0x2cb4f4 add r0, r0, #102400 */
/* @0x2cb4f8 add r0, r0, #628 */
/* @0x2cb4fc b 0x2d523c <_ZN16b2ParticleSystem23DestroyParticlesInShapeERK7b2ShapeRK11b2Transformb> */

/* ── FUNC 0x2cb500 · b2World::CreateParticleGroup(b2ParticleGroupDef const&) · size=40 · insn=10 */
/* @0x2cb500 movw r3, #0x91d4 */
/* @0x2cb504 movt r3, #0x1 */
/* @0x2cb508 ldr r3, [r0, r3] */
/* @0x2cb50c tst r3, #2 */
/* @0x2cb510 bne 0x2cb520 <_ZN7b2World19CreateParticleGroupERK18b2ParticleGroupDef+0x20> */
/* @0x2cb514 add r0, r0, #102400 */
/* @0x2cb518 add r0, r0, #628 */
/* @0x2cb51c b 0x2dacd0 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef> */
/* @0x2cb520 mov r0, #0 */
/* @0x2cb524 bx lr */

/* ── FUNC 0x2cb528 · b2World::JoinParticleGroups(b2ParticleGroup*, b2ParticleGroup*) · size=32 · insn=8 */
/* @0x2cb528 movw r3, #0x91d4 */
/* @0x2cb52c movt r3, #0x1 */
/* @0x2cb530 ldr r3, [r0, r3] */
/* @0x2cb534 tst r3, #2 */
/* @0x2cb538 bxne lr */
/* @0x2cb53c add r0, r0, #102400 */
/* @0x2cb540 add r0, r0, #628 */
/* @0x2cb544 b 0x2db6a0 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_> */

/* ── FUNC 0x2cb548 · b2World::DestroyParticlesInGroup(b2ParticleGroup*, bool) · size=32 · insn=8 */
/* @0x2cb548 movw r3, #0x91d4 */
/* @0x2cb54c movt r3, #0x1 */
/* @0x2cb550 ldr r3, [r0, r3] */
/* @0x2cb554 tst r3, #2 */
/* @0x2cb558 bxne lr */
/* @0x2cb55c add r0, r0, #102400 */
/* @0x2cb560 add r0, r0, #628 */
/* @0x2cb564 b 0x2d52c4 <_ZN16b2ParticleSystem23DestroyParticlesInGroupEP15b2ParticleGroupb> */

/* ── FUNC 0x2cb568 · b2World::GetParticleFlagsBuffer() · size=12 · insn=3 */
/* @0x2cb568 add r0, r0, #102400 */
/* @0x2cb56c add r0, r0, #628 */
/* @0x2cb570 b 0x2d9864 <_ZN16b2ParticleSystem22GetParticleFlagsBufferEv> */

/* ── FUNC 0x2cb574 · b2World::GetParticlePositionBuffer() · size=12 · insn=3 */
/* @0x2cb574 add r0, r0, #102400 */
/* @0x2cb578 add r0, r0, #628 */
/* @0x2cb57c b 0x2d986c <_ZN16b2ParticleSystem25GetParticlePositionBufferEv> */

/* ── FUNC 0x2cb580 · b2World::GetParticleVelocityBuffer() · size=12 · insn=3 */
/* @0x2cb580 add r0, r0, #102400 */
/* @0x2cb584 add r0, r0, #628 */
/* @0x2cb588 b 0x2d9874 <_ZN16b2ParticleSystem25GetParticleVelocityBufferEv> */

/* ── FUNC 0x2cb58c · b2World::GetParticleColorBuffer() · size=12 · insn=3 */
/* @0x2cb58c add r0, r0, #102400 */
/* @0x2cb590 add r0, r0, #628 */
/* @0x2cb594 b 0x2d987c <_ZN16b2ParticleSystem22GetParticleColorBufferEv> */

/* ── FUNC 0x2cb598 · b2World::GetParticleUserDataBuffer() · size=12 · insn=3 */
/* @0x2cb598 add r0, r0, #102400 */
/* @0x2cb59c add r0, r0, #628 */
/* @0x2cb5a0 b 0x2d98ac <_ZN16b2ParticleSystem25GetParticleUserDataBufferEv> */

/* ── FUNC 0x2cb5a4 · b2World::GetParticleFlagsBuffer() const · size=12 · insn=3 */
/* @0x2cb5a4 add r0, r0, #102400 */
/* @0x2cb5a8 add r0, r0, #628 */
/* @0x2cb5ac b 0x2d9904 <_ZNK16b2ParticleSystem22GetParticleFlagsBufferEv> */

/* ── FUNC 0x2cb5b0 · b2World::GetParticlePositionBuffer() const · size=12 · insn=3 */
/* @0x2cb5b0 add r0, r0, #102400 */
/* @0x2cb5b4 add r0, r0, #628 */
/* @0x2cb5b8 b 0x2d990c <_ZNK16b2ParticleSystem25GetParticlePositionBufferEv> */

/* ── FUNC 0x2cb5bc · b2World::GetParticleVelocityBuffer() const · size=12 · insn=3 */
/* @0x2cb5bc add r0, r0, #102400 */
/* @0x2cb5c0 add r0, r0, #628 */
/* @0x2cb5c4 b 0x2d9914 <_ZNK16b2ParticleSystem25GetParticleVelocityBufferEv> */

/* ── FUNC 0x2cb5c8 · b2World::GetParticleColorBuffer() const · size=12 · insn=3 */
/* @0x2cb5c8 add r0, r0, #102400 */
/* @0x2cb5cc add r0, r0, #628 */
/* @0x2cb5d0 b 0x2d991c <_ZNK16b2ParticleSystem22GetParticleColorBufferEv> */

/* ── FUNC 0x2cb5d4 · b2World::GetParticleGroupBuffer() const · size=12 · insn=3 */
/* @0x2cb5d4 add r0, r0, #102400 */
/* @0x2cb5d8 add r0, r0, #628 */
/* @0x2cb5dc b 0x2d9920 <_ZNK16b2ParticleSystem22GetParticleGroupBufferEv> */

/* ── FUNC 0x2cb5e0 · b2World::GetParticleUserDataBuffer() const · size=12 · insn=3 */
/* @0x2cb5e0 add r0, r0, #102400 */
/* @0x2cb5e4 add r0, r0, #628 */
/* @0x2cb5e8 b 0x2d9928 <_ZNK16b2ParticleSystem25GetParticleUserDataBufferEv> */

/* ── FUNC 0x2cb5ec · b2World::SetParticleFlagsBuffer(unsigned int*, int) · size=12 · insn=3 */
/* @0x2cb5ec add r0, r0, #102400 */
/* @0x2cb5f0 add r0, r0, #628 */
/* @0x2cb5f4 b 0x2d992c <_ZN16b2ParticleSystem22SetParticleFlagsBufferEPji> */

/* ── FUNC 0x2cb5f8 · b2World::SetParticlePositionBuffer(b2Vec2*, int) · size=12 · insn=3 */
/* @0x2cb5f8 add r0, r0, #102400 */
/* @0x2cb5fc add r0, r0, #628 */
/* @0x2cb600 b 0x2d9968 <_ZN16b2ParticleSystem25SetParticlePositionBufferEP6b2Vec2i> */

/* ── FUNC 0x2cb604 · b2World::SetParticleVelocityBuffer(b2Vec2*, int) · size=12 · insn=3 */
/* @0x2cb604 add r0, r0, #102400 */
/* @0x2cb608 add r0, r0, #628 */
/* @0x2cb60c b 0x2d99a4 <_ZN16b2ParticleSystem25SetParticleVelocityBufferEP6b2Vec2i> */

/* ── FUNC 0x2cb610 · b2World::SetParticleColorBuffer(b2ParticleColor*, int) · size=12 · insn=3 */
/* @0x2cb610 add r0, r0, #102400 */
/* @0x2cb614 add r0, r0, #628 */
/* @0x2cb618 b 0x2d99e0 <_ZN16b2ParticleSystem22SetParticleColorBufferEP15b2ParticleColori> */

/* ── FUNC 0x2cb61c · b2World::GetParticleGroupBuffer() · size=12 · insn=3 */
/* @0x2cb61c add r0, r0, #102400 */
/* @0x2cb620 add r0, r0, #628 */
/* @0x2cb624 b 0x2d9a1c <_ZN16b2ParticleSystem22GetParticleGroupBufferEv> */

/* ── FUNC 0x2cb628 · b2World::SetParticleUserDataBuffer(void**, int) · size=12 · insn=3 */
/* @0x2cb628 add r0, r0, #102400 */
/* @0x2cb62c add r0, r0, #628 */
/* @0x2cb630 b 0x2d9a24 <_ZN16b2ParticleSystem25SetParticleUserDataBufferEPPvi> */

/* ── FUNC 0x2cb634 · b2World::GetParticleContacts() · size=16 · insn=4 */
/* @0x2cb634 movw r3, #0x92f0 */
/* @0x2cb638 movt r3, #0x1 */
/* @0x2cb63c ldr r0, [r0, r3] */
/* @0x2cb640 bx lr */

/* ── FUNC 0x2cb644 · b2World::GetParticleContactCount() · size=16 · insn=4 */
/* @0x2cb644 movw r3, #0x92e8 */
/* @0x2cb648 movt r3, #0x1 */
/* @0x2cb64c ldr r0, [r0, r3] */
/* @0x2cb650 bx lr */

/* ── FUNC 0x2cb654 · b2World::GetParticleBodyContacts() · size=16 · insn=4 */
/* @0x2cb654 movw r3, #0x92fc */
/* @0x2cb658 movt r3, #0x1 */
/* @0x2cb65c ldr r0, [r0, r3] */
/* @0x2cb660 bx lr */

/* ── FUNC 0x2cb664 · b2World::GetParticleBodyContactCount() · size=16 · insn=4 */
/* @0x2cb664 movw r3, #0x92f4 */
/* @0x2cb668 movt r3, #0x1 */
/* @0x2cb66c ldr r0, [r0, r3] */
/* @0x2cb670 bx lr */

/* ── FUNC 0x2cb674 · b2World::ComputeParticleCollisionEnergy() const · size=12 · insn=3 */
/* @0x2cb674 add r0, r0, #102400 */
/* @0x2cb678 add r0, r0, #628 */
/* @0x2cb67c b 0x2d9fe8 <_ZNK16b2ParticleSystem30ComputeParticleCollisionEnergyEv> */

/* ── FUNC 0x2cb680 · void b2DynamicTree::Query<b2WorldQueryWrapper>(b2WorldQueryWrapper*, b2AABB const&) const · size=540 · insn=135 */
/* @0x2cb680 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2cb684 mov r10, r0 */
/* @0x2cb688 sub sp, sp, #1040 */
/* @0x2cb68c ldr r12, [r10] */
/* @0x2cb690 add r7, sp, #16 */
/* @0x2cb694 mov r9, r2 */
/* @0x2cb698 sub r0, r7, #8 */
/* @0x2cb69c mov r2, #256 */
/* @0x2cb6a0 mov r6, r1 */
/* @0x2cb6a4 mov r3, #1 */
/* @0x2cb6a8 mov r5, r0 */
/* @0x2cb6ac mov r8, r0 */
/* @0x2cb6b0 stmib sp, {r0, r12} */
/* @0x2cb6b4 str r2, [sp, #0x40c] */
/* @0x2cb6b8 b 0x2cb6c4 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x44> */
/* @0x2cb6bc cmp r3, #0 */
/* @0x2cb6c0 ble 0x2cb7a4 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x124> */
/* @0x2cb6c4 sub r3, r3, #1 */
/* @0x2cb6c8 str r3, [sp, #0x408] */
/* @0x2cb6cc ldr r12, [r5, r3, lsl #2] */
/* @0x2cb6d0 add r2, r5, r3, lsl #2 */
/* @0x2cb6d4 cmn r12, #1 */
/* @0x2cb6d8 beq 0x2cb6bc <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x3c> */
/* @0x2cb6dc add r12, r12, r12, lsl #3 */
/* @0x2cb6e0 ldr r4, [r10, #0x4] */
/* @0x2cb6e4 vldr s14, [r9] */
/* @0x2cb6e8 vldr s13, [r9, #4] */
/* @0x2cb6ec lsl r12, r12, #2 */
/* @0x2cb6f0 vldr s12, [r9, #8] */
/* @0x2cb6f4 add r4, r4, r12 */
/* @0x2cb6f8 vldr s15, [r4, #8] */
/* @0x2cb6fc vsub.f32 s15, s14, s15 */
/* @0x2cb700 vldr s11, [r4] */
/* @0x2cb704 vldr s14, [r4, #12] */
/* @0x2cb708 vldr s9, [r4, #4] */
/* @0x2cb70c vldr s10, [r9, #12] */
/* @0x2cb710 vcmpe.f32 s15, #0 */
/* @0x2cb714 vmrs APSR_nzcv, fpscr */
/* @0x2cb718 bgt 0x2cb6bc <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x3c> */
/* @0x2cb71c vsub.f32 s14, s13, s14 */
/* @0x2cb720 vcmpe.f32 s14, #0 */
/* @0x2cb724 vmrs APSR_nzcv, fpscr */
/* @0x2cb728 bgt 0x2cb6bc <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x3c> */
/* @0x2cb72c vsub.f32 s12, s11, s12 */
/* @0x2cb730 vcmpe.f32 s12, #0 */
/* @0x2cb734 vmrs APSR_nzcv, fpscr */
/* @0x2cb738 bgt 0x2cb6bc <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x3c> */
/* @0x2cb73c vsub.f32 s10, s9, s10 */
/* @0x2cb740 vcmpe.f32 s10, #0 */
/* @0x2cb744 vmrs APSR_nzcv, fpscr */
/* @0x2cb748 bgt 0x2cb6bc <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x3c> */
/* @0x2cb74c ldr r0, [r4, #0x18] */
/* @0x2cb750 cmn r0, #1 */
/* @0x2cb754 beq 0x2cb7c0 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x140> */
/* @0x2cb758 ldr r1, [sp, #0x40c] */
/* @0x2cb75c cmp r3, r1 */
/* @0x2cb760 movne r3, r0 */
/* @0x2cb764 beq 0x2cb838 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x1b8> */
/* @0x2cb768 str r3, [r2] */
/* @0x2cb76c ldr r3, [sp, #0x408] */
/* @0x2cb770 ldr r2, [sp, #0x40c] */
/* @0x2cb774 add r3, r3, #1 */
/* @0x2cb778 str r3, [sp, #0x408] */
/* @0x2cb77c cmp r3, r2 */
/* @0x2cb780 beq 0x2cb7f8 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x178> */
/* @0x2cb784 ldr r2, [r4, #0x1c] */
/* @0x2cb788 str r2, [r5, r3, lsl #2] */
/* @0x2cb78c ldr r3, [sp, #0x408] */
/* @0x2cb790 ldr r5, [sp, #0x4] */
/* @0x2cb794 add r3, r3, #1 */
/* @0x2cb798 str r3, [sp, #0x408] */
/* @0x2cb79c cmp r3, #0 */
/* @0x2cb7a0 bgt 0x2cb6c4 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x44> */
/* @0x2cb7a4 sub r7, r7, #8 */
/* @0x2cb7a8 cmp r5, r7 */
/* @0x2cb7ac beq 0x2cb7b8 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x138> */
/* @0x2cb7b0 mov r0, r5 */
/* @0x2cb7b4 bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2cb7b8 add sp, sp, #1040 */
/* @0x2cb7bc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2cb7c0 ldr r3, [r6] */
/* @0x2cb7c4 ldr r0, [r6, #0x4] */
/* @0x2cb7c8 ldr r2, [r3, #0x4] */
/* @0x2cb7cc ldr r3, [r0] */
/* @0x2cb7d0 add r12, r2, r12 */
/* @0x2cb7d4 ldr r2, [r12, #0x10] */
/* @0x2cb7d8 ldr r3, [r3, #0x8] */
/* @0x2cb7dc ldr r1, [r2, #0x10] */
/* @0x2cb7e0 blx r3 */
/* @0x2cb7e4 cmp r0, #0 */
/* @0x2cb7e8 beq 0x2cb884 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x204> */
/* @0x2cb7ec ldr r3, [sp, #0x408] */
/* @0x2cb7f0 ldr r5, [sp, #0x4] */
/* @0x2cb7f4 b 0x2cb6bc <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x3c> */
/* @0x2cb7f8 lsl r0, r3, #3 */
/* @0x2cb7fc lsl r3, r3, #1 */
/* @0x2cb800 str r3, [sp, #0x40c] */
/* @0x2cb804 bl 0x2c6a6c <_Z7b2Alloci> */
/* @0x2cb808 ldr r2, [sp, #0x408] */
/* @0x2cb80c mov r1, r5 */
/* @0x2cb810 lsl r2, r2, #2 */
/* @0x2cb814 str r0, [sp, #0x4] */
/* @0x2cb818 bl 0xb65bc <memcpy@plt> */
/* @0x2cb81c cmp r5, r8 */
/* @0x2cb820 beq 0x2cb82c <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x1ac> */
/* @0x2cb824 mov r0, r5 */
/* @0x2cb828 bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2cb82c ldr r5, [sp, #0x4] */
/* @0x2cb830 ldr r3, [sp, #0x408] */
/* @0x2cb834 b 0x2cb784 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x104> */
/* @0x2cb838 lsl r0, r3, #3 */
/* @0x2cb83c ldr r5, [sp, #0x4] */
/* @0x2cb840 lsl r3, r3, #1 */
/* @0x2cb844 str r3, [sp, #0x40c] */
/* @0x2cb848 bl 0x2c6a6c <_Z7b2Alloci> */
/* @0x2cb84c ldr r2, [sp, #0x408] */
/* @0x2cb850 mov r1, r5 */
/* @0x2cb854 lsl r2, r2, #2 */
/* @0x2cb858 str r0, [sp, #0x4] */
/* @0x2cb85c bl 0xb65bc <memcpy@plt> */
/* @0x2cb860 cmp r5, r8 */
/* @0x2cb864 beq 0x2cb870 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x1f0> */
/* @0x2cb868 mov r0, r5 */
/* @0x2cb86c bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2cb870 ldr r2, [sp, #0x408] */
/* @0x2cb874 ldr r5, [sp, #0x4] */
/* @0x2cb878 ldr r3, [r4, #0x18] */
/* @0x2cb87c add r2, r5, r2, lsl #2 */
/* @0x2cb880 b 0x2cb768 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0xe8> */
/* @0x2cb884 ldr r0, [sp, #0x4] */
/* @0x2cb888 sub r7, r7, #8 */
/* @0x2cb88c cmp r0, r7 */
/* @0x2cb890 beq 0x2cb7b8 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x138> */
/* @0x2cb894 bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2cb898 b 0x2cb7b8 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x138> */

/* ── FUNC 0x2cb89c · b2World::QueryAABB(b2QueryCallback*, b2AABB const&) const · size=68 · insn=17 */
/* @0x2cb89c push {r4, r5, r6, lr} */
/* @0x2cb8a0 add r5, r0, #102400 */
/* @0x2cb8a4 sub sp, sp, #8 */
/* @0x2cb8a8 add r3, r5, #472 */
/* @0x2cb8ac mov r4, r1 */
/* @0x2cb8b0 mov r6, r2 */
/* @0x2cb8b4 mov r0, r3 */
/* @0x2cb8b8 mov r1, sp */
/* @0x2cb8bc str r3, [sp] */
/* @0x2cb8c0 str r4, [sp, #0x4] */
/* @0x2cb8c4 bl 0x2cb680 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB> */
/* @0x2cb8c8 add r0, r5, #628 */
/* @0x2cb8cc mov r1, r4 */
/* @0x2cb8d0 mov r2, r6 */
/* @0x2cb8d4 bl 0x2d9a60 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB> */
/* @0x2cb8d8 add sp, sp, #8 */
/* @0x2cb8dc pop {r4, r5, r6, pc} */

/* ── FUNC 0x2cb8e0 · void b2DynamicTree::RayCast<b2WorldRayCastWrapper>(b2WorldRayCastWrapper*, b2RayCastInput const&) const · size=1128 · insn=282 */
/* @0x2cb8e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2cb8e4 vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2cb8e8 vldr s18, [r2, #4] */
/* @0x2cb8ec vldr s24, [r2, #12] */
/* @0x2cb8f0 vsub.f32 s24, s24, s18 */
/* @0x2cb8f4 vldr s19, [r2] */
/* @0x2cb8f8 vldr s25, [r2, #8] */
/* @0x2cb8fc sub sp, sp, #1104 */
/* @0x2cb900 sub sp, sp, #4 */
/* @0x2cb904 mov r6, r2 */
/* @0x2cb908 mov r5, r0 */
/* @0x2cb90c mov r10, r1 */
/* @0x2cb910 vmul.f32 s14, s24, s24 */
/* @0x2cb914 vsub.f32 s25, s25, s19 */
/* @0x2cb918 vmla.f32 s14, s25, s25 */
/* @0x2cb91c vsqrt.f32 s15, s14 */
/* @0x2cb920 vcmp.f32 s15, s15 */
/* @0x2cb924 vmrs APSR_nzcv, fpscr */
/* @0x2cb928 bne 0x2cbd38 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x458> */
/* @0x2cb92c vldr s14, [pc, #1004] */
/* @0x2cb930 vcmpe.f32 s15, s14 */
/* @0x2cb934 vldr s26, [r6, #16] */
/* @0x2cb938 add r8, sp, #80 */
/* @0x2cb93c ldr r1, [r5] */
/* @0x2cb940 sub r3, r8, #8 */
/* @0x2cb944 add r9, sp, #48 */
/* @0x2cb948 str r3, [sp, #0x10] */
/* @0x2cb94c vmrs APSR_nzcv, fpscr */
/* @0x2cb950 vmovpl.f32 s21, #1.000000e+00 */
/* @0x2cb954 sub r2, r9, #12 */
/* @0x2cb958 str r2, [sp, #0xc] */
/* @0x2cb95c add r2, sp, #28 */
/* @0x2cb960 str r2, [sp, #0x14] */
/* @0x2cb964 mov r2, #1 */
/* @0x2cb968 mov r11, r3 */
/* @0x2cb96c str r3, [sp, #0x44] */
/* @0x2cb970 add r7, sp, #64 */
/* @0x2cb974 mov r3, #256 */
/* @0x2cb978 str r1, [sp, #0x48] */
/* @0x2cb97c str r3, [sp, #0x44c] */
/* @0x2cb980 mov r3, r2 */
/* @0x2cb984 vdivpl.f32 s21, s21, s15 */
/* @0x2cb988 vmov.f32 s17, s19 */
/* @0x2cb98c vmulpl.f32 s28, s25, s21 */
/* @0x2cb990 vmulpl.f32 s21, s24, s21 */
/* @0x2cb994 vmla.f32 s17, s26, s25 */
/* @0x2cb998 vmov.f32 s20, s18 */
/* @0x2cb99c vmla.f32 s20, s26, s24 */
/* @0x2cb9a0 vmovmi.f32 s21, s24 */
/* @0x2cb9a4 vneg.f32 s27, s21 */
/* @0x2cb9a8 vmovmi.f32 s28, s25 */
/* @0x2cb9ac vcmpe.f32 s27, #0 */
/* @0x2cb9b0 vmrs APSR_nzcv, fpscr */
/* @0x2cb9b4 vcmpe.f32 s28, #0 */
/* @0x2cb9b8 vmovgt.f32 s21, s27 */
/* @0x2cb9bc vmrs APSR_nzcv, fpscr */
/* @0x2cb9c0 vcmpe.f32 s19, s17 */
/* @0x2cb9c4 vnegle.f32 s22, s28 */
/* @0x2cb9c8 vmovgt.f32 s22, s28 */
/* @0x2cb9cc vmrs APSR_nzcv, fpscr */
/* @0x2cb9d0 vcmpe.f32 s18, s20 */
/* @0x2cb9d4 vmovpl.f32 s16, s17 */
/* @0x2cb9d8 vmovmi.f32 s16, s19 */
/* @0x2cb9dc vmrs APSR_nzcv, fpscr */
/* @0x2cb9e0 vcmp.f32 s19, s17 */
/* @0x2cb9e4 vmovpl.f32 s23, s20 */
/* @0x2cb9e8 vmovmi.f32 s23, s18 */
/* @0x2cb9ec vmrs APSR_nzcv, fpscr */
/* @0x2cb9f0 vcmp.f32 s18, s20 */
/* @0x2cb9f4 vmovgt.f32 s17, s19 */
/* @0x2cb9f8 vmrs APSR_nzcv, fpscr */
/* @0x2cb9fc vmov.f32 s29, #5.000000e-01 */
/* @0x2cba00 vmovgt.f32 s20, s18 */
/* @0x2cba04 b 0x2cba10 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x130> */
/* @0x2cba08 cmp r3, #0 */
/* @0x2cba0c ble 0x2cbb34 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x254> */
/* @0x2cba10 sub r3, r3, #1 */
/* @0x2cba14 str r3, [sp, #0x448] */
/* @0x2cba18 ldr r12, [r11, r3, lsl #2] */
/* @0x2cba1c add r2, r11, r3, lsl #2 */
/* @0x2cba20 cmn r12, #1 */
/* @0x2cba24 beq 0x2cba08 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x128> */
/* @0x2cba28 add r12, r12, r12, lsl #3 */
/* @0x2cba2c ldr r4, [r5, #0x4] */
/* @0x2cba30 lsl r12, r12, #2 */
/* @0x2cba34 add r4, r4, r12 */
/* @0x2cba38 vldr s15, [r4, #8] */
/* @0x2cba3c vsub.f32 s14, s16, s15 */
/* @0x2cba40 vldr s13, [r4, #12] */
/* @0x2cba44 vldr s12, [r4] */
/* @0x2cba48 vldr s11, [r4, #4] */
/* @0x2cba4c vcmpe.f32 s14, #0 */
/* @0x2cba50 vmrs APSR_nzcv, fpscr */
/* @0x2cba54 bgt 0x2cba08 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x128> */
/* @0x2cba58 vsub.f32 s14, s23, s13 */
/* @0x2cba5c vcmpe.f32 s14, #0 */
/* @0x2cba60 vmrs APSR_nzcv, fpscr */
/* @0x2cba64 bgt 0x2cba08 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x128> */
/* @0x2cba68 vsub.f32 s14, s12, s17 */
/* @0x2cba6c vcmpe.f32 s14, #0 */
/* @0x2cba70 vmrs APSR_nzcv, fpscr */
/* @0x2cba74 bgt 0x2cba08 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x128> */
/* @0x2cba78 vsub.f32 s14, s11, s20 */
/* @0x2cba7c vcmpe.f32 s14, #0 */
/* @0x2cba80 vmrs APSR_nzcv, fpscr */
/* @0x2cba84 bgt 0x2cba08 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x128> */
/* @0x2cba88 vadd.f32 s14, s13, s11 */
/* @0x2cba8c vmov.f32 s9, s18 */
/* @0x2cba90 vmls.f32 s9, s14, s29 */
/* @0x2cba94 vadd.f32 s10, s15, s12 */
/* @0x2cba98 vmov.f32 s14, s9 */
/* @0x2cba9c vmov.f32 s9, s19 */
/* @0x2cbaa0 vmls.f32 s9, s10, s29 */
/* @0x2cbaa4 vmul.f32 s14, s28, s14 */
/* @0x2cbaa8 vmla.f32 s14, s27, s9 */
/* @0x2cbaac vsub.f32 s13, s13, s11 */
/* @0x2cbab0 vsub.f32 s12, s15, s12 */
/* @0x2cbab4 vcmpe.f32 s14, #0 */
/* @0x2cbab8 vmul.f32 s15, s13, s29 */
/* @0x2cbabc vmrs APSR_nzcv, fpscr */
/* @0x2cbac0 vmul.f32 s13, s12, s29 */
/* @0x2cbac4 ble 0x2cbb58 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x278> */
/* @0x2cbac8 vmul.f32 s15, s22, s15 */
/* @0x2cbacc vmla.f32 s15, s21, s13 */
/* @0x2cbad0 vsub.f32 s15, s14, s15 */
/* @0x2cbad4 vcmpe.f32 s15, #0 */
/* @0x2cbad8 vmrs APSR_nzcv, fpscr */
/* @0x2cbadc bgt 0x2cba08 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x128> */
/* @0x2cbae0 ldr r1, [r4, #0x18] */
/* @0x2cbae4 cmn r1, #1 */
/* @0x2cbae8 beq 0x2cbb60 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x280> */
/* @0x2cbaec ldr r0, [sp, #0x44c] */
/* @0x2cbaf0 cmp r3, r0 */
/* @0x2cbaf4 beq 0x2cbc30 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x350> */
/* @0x2cbaf8 str r1, [r2] */
/* @0x2cbafc ldr r3, [sp, #0x448] */
/* @0x2cbb00 ldr r2, [sp, #0x44c] */
/* @0x2cbb04 add r3, r3, #1 */
/* @0x2cbb08 str r3, [sp, #0x448] */
/* @0x2cbb0c cmp r3, r2 */
/* @0x2cbb10 beq 0x2cbc80 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x3a0> */
/* @0x2cbb14 ldr r2, [r4, #0x1c] */
/* @0x2cbb18 str r2, [r11, r3, lsl #2] */
/* @0x2cbb1c ldr r3, [sp, #0x448] */
/* @0x2cbb20 ldr r11, [sp, #0x44] */
/* @0x2cbb24 add r3, r3, #1 */
/* @0x2cbb28 str r3, [sp, #0x448] */
/* @0x2cbb2c cmp r3, #0 */
/* @0x2cbb30 bgt 0x2cba10 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x130> */
/* @0x2cbb34 sub r8, r8, #8 */
/* @0x2cbb38 cmp r11, r8 */
/* @0x2cbb3c beq 0x2cbb48 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x268> */
/* @0x2cbb40 mov r0, r11 */
/* @0x2cbb44 bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2cbb48 add sp, sp, #1104 */
/* @0x2cbb4c add sp, sp, #4 */
/* @0x2cbb50 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2cbb54 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2cbb58 vneg.f32 s14, s14 */
/* @0x2cbb5c b 0x2cbac8 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x1e8> */
/* @0x2cbb60 ldr r2, [r10] */
/* @0x2cbb64 add r3, r6, #8 */
/* @0x2cbb68 ldm r6, {r0, r1} */
/* @0x2cbb6c vstr s26, [r7] */
/* @0x2cbb70 ldr lr, [r2, #0x4] */
/* @0x2cbb74 mov r2, r9 */
/* @0x2cbb78 stm r9, {r0, r1} */
/* @0x2cbb7c add r12, lr, r12 */
/* @0x2cbb80 ldm r3, {r0, r1} */
/* @0x2cbb84 ldr r3, [r12, #0x10] */
/* @0x2cbb88 stmdb r7, {r0, r1} */
/* @0x2cbb8c ldr r1, [sp, #0xc] */
/* @0x2cbb90 ldr r4, [r3, #0x10] */
/* @0x2cbb94 ldr lr, [r3, #0x14] */
/* @0x2cbb98 ldr r0, [r4, #0xc] */
/* @0x2cbb9c ldr r3, [r4, #0x8] */
/* @0x2cbba0 ldr r12, [r0] */
/* @0x2cbba4 add r3, r3, #12 */
/* @0x2cbba8 str lr, [sp] */
/* @0x2cbbac ldr r12, [r12, #0x18] */
/* @0x2cbbb0 blx r12 */
/* @0x2cbbb4 cmp r0, #0 */
/* @0x2cbbb8 vldreq s15, [r7] */
/* @0x2cbbbc bne 0x2cbcc4 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x3e4> */
/* @0x2cbbc0 vcmp.f32 s15, #0 */
/* @0x2cbbc4 vmrs APSR_nzcv, fpscr */
/* @0x2cbbc8 beq 0x2cbd24 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x444> */
/* @0x2cbbcc vcmpe.f32 s15, #0 */
/* @0x2cbbd0 vmrs APSR_nzcv, fpscr */
/* @0x2cbbd4 ble 0x2cbc24 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x344> */
/* @0x2cbbd8 vmov.f32 s17, s19 */
/* @0x2cbbdc vmov.f32 s20, s18 */
/* @0x2cbbe0 vmla.f32 s17, s25, s15 */
/* @0x2cbbe4 vmla.f32 s20, s24, s15 */
/* @0x2cbbe8 vcmpe.f32 s19, s17 */
/* @0x2cbbec vmrs APSR_nzcv, fpscr */
/* @0x2cbbf0 vcmpe.f32 s18, s20 */
/* @0x2cbbf4 vmovpl.f32 s16, s17 */
/* @0x2cbbf8 vmovmi.f32 s16, s19 */
/* @0x2cbbfc vmrs APSR_nzcv, fpscr */
/* @0x2cbc00 vcmp.f32 s19, s17 */
/* @0x2cbc04 vmovpl.f32 s23, s20 */
/* @0x2cbc08 vmovmi.f32 s23, s18 */
/* @0x2cbc0c vmrs APSR_nzcv, fpscr */
/* @0x2cbc10 vcmp.f32 s18, s20 */
/* @0x2cbc14 vmovgt.f32 s17, s19 */
/* @0x2cbc18 vmrs APSR_nzcv, fpscr */
/* @0x2cbc1c vmov.f32 s26, s15 */
/* @0x2cbc20 vmovgt.f32 s20, s18 */
/* @0x2cbc24 ldr r3, [sp, #0x448] */
/* @0x2cbc28 ldr r11, [sp, #0x44] */
/* @0x2cbc2c b 0x2cba08 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x128> */
/* @0x2cbc30 lsl r0, r3, #3 */
/* @0x2cbc34 ldr r11, [sp, #0x44] */
/* @0x2cbc38 lsl r3, r3, #1 */
/* @0x2cbc3c str r3, [sp, #0x44c] */
/* @0x2cbc40 bl 0x2c6a6c <_Z7b2Alloci> */
/* @0x2cbc44 ldr r2, [sp, #0x448] */
/* @0x2cbc48 mov r1, r11 */
/* @0x2cbc4c lsl r2, r2, #2 */
/* @0x2cbc50 str r0, [sp, #0x44] */
/* @0x2cbc54 bl 0xb65bc <memcpy@plt> */
/* @0x2cbc58 ldr r3, [sp, #0x10] */
/* @0x2cbc5c cmp r11, r3 */
/* @0x2cbc60 beq 0x2cbc6c <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x38c> */
/* @0x2cbc64 mov r0, r11 */
/* @0x2cbc68 bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2cbc6c ldr r2, [sp, #0x448] */
/* @0x2cbc70 ldr r11, [sp, #0x44] */
/* @0x2cbc74 ldr r1, [r4, #0x18] */
/* @0x2cbc78 add r2, r11, r2, lsl #2 */
/* @0x2cbc7c b 0x2cbaf8 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x218> */
/* @0x2cbc80 lsl r0, r3, #3 */
/* @0x2cbc84 lsl r3, r3, #1 */
/* @0x2cbc88 str r3, [sp, #0x44c] */
/* @0x2cbc8c bl 0x2c6a6c <_Z7b2Alloci> */
/* @0x2cbc90 ldr r2, [sp, #0x448] */
/* @0x2cbc94 mov r1, r11 */
/* @0x2cbc98 lsl r2, r2, #2 */
/* @0x2cbc9c str r0, [sp, #0x44] */
/* @0x2cbca0 bl 0xb65bc <memcpy@plt> */
/* @0x2cbca4 ldr r2, [sp, #0x10] */
/* @0x2cbca8 cmp r11, r2 */
/* @0x2cbcac beq 0x2cbcb8 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x3d8> */
/* @0x2cbcb0 mov r0, r11 */
/* @0x2cbcb4 bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2cbcb8 ldr r11, [sp, #0x44] */
/* @0x2cbcbc ldr r3, [sp, #0x448] */
/* @0x2cbcc0 b 0x2cbb14 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x234> */
/* @0x2cbcc4 vmov.f32 s10, #1.000000e+00 */
/* @0x2cbcc8 ldr r0, [r10, #0x4] */
/* @0x2cbccc vldr s15, [sp, #44] */
/* @0x2cbcd0 vldr s14, [r7, #-8] */
/* @0x2cbcd4 vldr s13, [sp, #60] */
/* @0x2cbcd8 vldr s12, [r9] */
/* @0x2cbcdc ldr r12, [r0] */
/* @0x2cbce0 vstr s15, [sp] */
/* @0x2cbce4 vldr s11, [sp, #52] */
/* @0x2cbce8 mov r1, r4 */
/* @0x2cbcec add r2, sp, #28 */
/* @0x2cbcf0 ldr r3, [sp, #0xc] */
/* @0x2cbcf4 ldr r12, [r12, #0x8] */
/* @0x2cbcf8 vmul.f32 s13, s15, s13 */
/* @0x2cbcfc vmul.f32 s14, s15, s14 */
/* @0x2cbd00 vsub.f32 s15, s10, s15 */
/* @0x2cbd04 vmla.f32 s13, s15, s11 */
/* @0x2cbd08 vmla.f32 s14, s15, s12 */
/* @0x2cbd0c vstr s13, [sp, #32] */
/* @0x2cbd10 vstr s14, [sp, #28] */
/* @0x2cbd14 blx r12 */
/* @0x2cbd18 vmov s15, r0 */
/* @0x2cbd1c b 0x2cbbc0 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x2e0> */
/* @0x2cbd20 strlo r0, [r0], #-0 */
/* @0x2cbd24 ldr r0, [sp, #0x44] */
/* @0x2cbd28 sub r8, r8, #8 */
/* @0x2cbd2c cmp r0, r8 */
/* @0x2cbd30 bne 0x2cbb44 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x264> */
/* @0x2cbd34 b 0x2cbb48 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x268> */
/* @0x2cbd38 vmov r0, s14 */
/* @0x2cbd3c bl 0xb6700 <sqrtf@plt> */
/* @0x2cbd40 vmov s15, r0 */
/* @0x2cbd44 b 0x2cb92c <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x4c> */

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
