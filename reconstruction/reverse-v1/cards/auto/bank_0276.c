/* libyoyo.so 覆盖卡组 0276
 * 函数 0x2ce6c4..0x2cf0b8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2ce6c4 · b2MotorJoint::b2MotorJoint(b2MotorJointDef const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2ce730 · b2MotorJoint::SetMaxForce(float) · size=152 · insn=38 */
/* @0x2ce730 push {r4, lr} */
/* @0x2ce734 vpush {d8} */
/* @0x2ce738 vmov s16, r1 */
/* @0x2ce73c ldr r3, [pc, #0x7c] */
/* @0x2ce740 sub sp, sp, #16 */
/* @0x2ce744 vcmp.f32 s16, s16 */
/* @0x2ce748 mov r4, r0 */
/* @0x2ce74c ldr r3, [pc, r3] */
/* @0x2ce750 ldr r3, [r3] */
/* @0x2ce754 vmrs APSR_nzcv, fpscr */
/* @0x2ce758 bne 0x2ce780 <_ZN12b2MotorJoint11SetMaxForceEf+0x50> */
/* @0x2ce75c mov r1, #0 */
/* @0x2ce760 movw r2, #0x7f80 */
/* @0x2ce764 strh r1, [sp] */
/* @0x2ce768 strh r2, [sp, #2] */
/* @0x2ce76c vldr s15, [sp] */
/* @0x2ce770 vneg.f32 s14, s15 */
/* @0x2ce774 vcmpe.f32 s16, s14 */
/* @0x2ce778 vmrs APSR_nzcv, fpscr */
/* @0x2ce77c bgt 0x2ce7a0 <_ZN12b2MotorJoint11SetMaxForceEf+0x70> */
/* @0x2ce780 mov r0, #0 */
/* @0x2ce784 ldr r1, [pc, #0x38] */
/* @0x2ce788 add r1, pc, r1 */
/* @0x2ce78c blx r3 */
/* @0x2ce790 vstr s16, [r4, #92] */
/* @0x2ce794 add sp, sp, #16 */
/* @0x2ce798 vpop {d8} */
/* @0x2ce79c pop {r4, pc} */
/* @0x2ce7a0 vcmpe.f32 s16, s15 */
/* @0x2ce7a4 vmrs APSR_nzcv, fpscr */
/* @0x2ce7a8 bpl 0x2ce780 <_ZN12b2MotorJoint11SetMaxForceEf+0x50> */
/* @0x2ce7ac vcmpe.f32 s16, #0 */
/* @0x2ce7b0 vmrs APSR_nzcv, fpscr */
/* @0x2ce7b4 movge r0, #1 */
/* @0x2ce7b8 bge 0x2ce784 <_ZN12b2MotorJoint11SetMaxForceEf+0x54> */
/* @0x2ce7bc b 0x2ce780 <_ZN12b2MotorJoint11SetMaxForceEf+0x50> */
/* @0x2ce7c0 andseq r2, r2, r12, ror sp */
/* @0x2ce7c4 andeq lr, r8, r0, lsr #24 */

/* ── FUNC 0x2ce7c8 · b2MotorJoint::GetMaxForce() const · size=8 · insn=2 */
/* @0x2ce7c8 ldr r0, [r0, #0x5c] */
/* @0x2ce7cc bx lr */

/* ── FUNC 0x2ce7d0 · b2MotorJoint::SetMaxTorque(float) · size=152 · insn=38 */
/* @0x2ce7d0 push {r4, lr} */
/* @0x2ce7d4 vpush {d8} */
/* @0x2ce7d8 vmov s16, r1 */
/* @0x2ce7dc ldr r3, [pc, #0x7c] */
/* @0x2ce7e0 sub sp, sp, #16 */
/* @0x2ce7e4 vcmp.f32 s16, s16 */
/* @0x2ce7e8 mov r4, r0 */
/* @0x2ce7ec ldr r3, [pc, r3] */
/* @0x2ce7f0 ldr r3, [r3] */
/* @0x2ce7f4 vmrs APSR_nzcv, fpscr */
/* @0x2ce7f8 bne 0x2ce820 <_ZN12b2MotorJoint12SetMaxTorqueEf+0x50> */
/* @0x2ce7fc mov r1, #0 */
/* @0x2ce800 movw r2, #0x7f80 */
/* @0x2ce804 strh r1, [sp] */
/* @0x2ce808 strh r2, [sp, #2] */
/* @0x2ce80c vldr s15, [sp] */
/* @0x2ce810 vneg.f32 s14, s15 */
/* @0x2ce814 vcmpe.f32 s16, s14 */
/* @0x2ce818 vmrs APSR_nzcv, fpscr */
/* @0x2ce81c bgt 0x2ce840 <_ZN12b2MotorJoint12SetMaxTorqueEf+0x70> */
/* @0x2ce820 mov r0, #0 */
/* @0x2ce824 ldr r1, [pc, #0x38] */
/* @0x2ce828 add r1, pc, r1 */
/* @0x2ce82c blx r3 */
/* @0x2ce830 vstr s16, [r4, #96] */
/* @0x2ce834 add sp, sp, #16 */
/* @0x2ce838 vpop {d8} */
/* @0x2ce83c pop {r4, pc} */
/* @0x2ce840 vcmpe.f32 s16, s15 */
/* @0x2ce844 vmrs APSR_nzcv, fpscr */
/* @0x2ce848 bpl 0x2ce820 <_ZN12b2MotorJoint12SetMaxTorqueEf+0x50> */
/* @0x2ce84c vcmpe.f32 s16, #0 */
/* @0x2ce850 vmrs APSR_nzcv, fpscr */
/* @0x2ce854 movge r0, #1 */
/* @0x2ce858 bge 0x2ce824 <_ZN12b2MotorJoint12SetMaxTorqueEf+0x54> */
/* @0x2ce85c b 0x2ce820 <_ZN12b2MotorJoint12SetMaxTorqueEf+0x50> */
/* @0x2ce860 ldrsbeq r2, [r2], -r12 */
/* @0x2ce864 andeq lr, r8, r8, lsl #24 */

/* ── FUNC 0x2ce868 · b2MotorJoint::GetMaxTorque() const · size=8 · insn=2 */
/* @0x2ce868 ldr r0, [r0, #0x60] */
/* @0x2ce86c bx lr */

/* ── FUNC 0x2ce870 · b2MotorJoint::SetLinearOffset(b2Vec2 const&) · size=116 · insn=29 */
/* @0x2ce870 vldr s15, [r0, #68] */
/* @0x2ce874 vldr s14, [r1] */
/* @0x2ce878 vcmp.f32 s14, s15 */
/* @0x2ce87c mov r3, r0 */
/* @0x2ce880 vmrs APSR_nzcv, fpscr */
/* @0x2ce884 bne 0x2ce89c <_ZN12b2MotorJoint15SetLinearOffsetERK6b2Vec2+0x2c> */
/* @0x2ce888 vldr s14, [r1, #4] */
/* @0x2ce88c vldr s15, [r0, #72] */
/* @0x2ce890 vcmp.f32 s14, s15 */
/* @0x2ce894 vmrs APSR_nzcv, fpscr */
/* @0x2ce898 bxeq lr */
/* @0x2ce89c ldr r2, [r3, #0x30] */
/* @0x2ce8a0 add r3, r3, #68 */
/* @0x2ce8a4 ldrh r0, [r2, #4] */
/* @0x2ce8a8 tst r0, #2 */
/* @0x2ce8ac orreq r0, r0, #2 */
/* @0x2ce8b0 strheq r0, [r2, #4] */
/* @0x2ce8b4 moveq r12, #0 */
/* @0x2ce8b8 streq r12, [r2, #0xa0] */
/* @0x2ce8bc ldr r2, [r3, #-0x10] */
/* @0x2ce8c0 ldrh r0, [r2, #4] */
/* @0x2ce8c4 tst r0, #2 */
/* @0x2ce8c8 orreq r0, r0, #2 */
/* @0x2ce8cc strheq r0, [r2, #4] */
/* @0x2ce8d0 ldm r1, {r0, r1} */
/* @0x2ce8d4 moveq r12, #0 */
/* @0x2ce8d8 streq r12, [r2, #0xa0] */
/* @0x2ce8dc stm r3, {r0, r1} */
/* @0x2ce8e0 bx lr */

/* ── FUNC 0x2ce8e4 · b2MotorJoint::GetLinearOffset() const · size=8 · insn=2 */
/* @0x2ce8e4 add r0, r0, #68 */
/* @0x2ce8e8 bx lr */

/* ── FUNC 0x2ce8ec · b2MotorJoint::SetAngularOffset(float) · size=84 · insn=21 */
/* @0x2ce8ec vmov s15, r1 */
/* @0x2ce8f0 vldr s14, [r0, #76] */
/* @0x2ce8f4 vcmp.f32 s14, s15 */
/* @0x2ce8f8 vmrs APSR_nzcv, fpscr */
/* @0x2ce8fc bxeq lr */
/* @0x2ce900 ldr r3, [r0, #0x30] */
/* @0x2ce904 ldrh r2, [r3, #4] */
/* @0x2ce908 tst r2, #2 */
/* @0x2ce90c orreq r2, r2, #2 */
/* @0x2ce910 strheq r2, [r3, #4] */
/* @0x2ce914 moveq r1, #0 */
/* @0x2ce918 streq r1, [r3, #0xa0] */
/* @0x2ce91c ldr r3, [r0, #0x34] */
/* @0x2ce920 ldrh r2, [r3, #4] */
/* @0x2ce924 tst r2, #2 */
/* @0x2ce928 orreq r2, r2, #2 */
/* @0x2ce92c strheq r2, [r3, #4] */
/* @0x2ce930 moveq r1, #0 */
/* @0x2ce934 streq r1, [r3, #0xa0] */
/* @0x2ce938 vstr s15, [r0, #76] */
/* @0x2ce93c bx lr */

/* ── FUNC 0x2ce940 · b2MotorJoint::GetAngularOffset() const · size=8 · insn=2 */
/* @0x2ce940 ldr r0, [r0, #0x4c] */
/* @0x2ce944 bx lr */

/* ── FUNC 0x2ce948 · b2MouseJoint::SolvePositionConstraints(b2SolverData const&) · size=8 · insn=2 */
/* @0x2ce948 mov r0, #1 */
/* @0x2ce94c bx lr */

/* ── FUNC 0x2ce950 · b2MouseJoint::GetAnchorA() const · size=24 · insn=6 */
/* @0x2ce950 add r1, r1, #76 */
/* @0x2ce954 mov r3, r0 */
/* @0x2ce958 ldm r1, {r0, r1} */
/* @0x2ce95c stm r3, {r0, r1} */
/* @0x2ce960 mov r0, r3 */
/* @0x2ce964 bx lr */

/* ── FUNC 0x2ce968 · b2MouseJoint::GetAnchorB() const · size=64 · insn=16 */
/* @0x2ce968 ldr r3, [r1, #0x34] */
/* @0x2ce96c vldr s15, [r1, #72] */
/* @0x2ce970 vldr s12, [r3, #24] */
/* @0x2ce974 vldr s11, [r3, #20] */
/* @0x2ce978 vmul.f32 s14, s12, s15 */
/* @0x2ce97c vldr s13, [r1, #68] */
/* @0x2ce980 vldr s9, [r3, #16] */
/* @0x2ce984 vldr s10, [r3, #12] */
/* @0x2ce988 vmul.f32 s15, s11, s15 */
/* @0x2ce98c vmla.f32 s14, s13, s11 */
/* @0x2ce990 vnmls.f32 s15, s12, s13 */
/* @0x2ce994 vadd.f32 s14, s14, s9 */
/* @0x2ce998 vadd.f32 s15, s15, s10 */
/* @0x2ce99c vstr s14, [r0, #4] */
/* @0x2ce9a0 vstr s15, [r0] */
/* @0x2ce9a4 bx lr */

/* ── FUNC 0x2ce9a8 · b2MouseJoint::GetReactionForce(float) const · size=32 · insn=8 */
/* @0x2ce9a8 vmov s15, r2 */
/* @0x2ce9ac vldr s14, [r1, #100] */
/* @0x2ce9b0 vldr s13, [r1, #96] */
/* @0x2ce9b4 vmul.f32 s14, s15, s14 */
/* @0x2ce9b8 vmul.f32 s15, s15, s13 */
/* @0x2ce9bc vstr s14, [r0, #4] */
/* @0x2ce9c0 vstr s15, [r0] */
/* @0x2ce9c4 bx lr */

/* ── FUNC 0x2ce9c8 · b2MouseJoint::GetReactionTorque(float) const · size=24 · insn=6 */
/* @0x2ce9c8 vmov s14, r1 */
/* @0x2ce9cc vldr s15, [pc, #8] */
/* @0x2ce9d0 vmul.f32 s14, s14, s15 */
/* @0x2ce9d4 vmov r0, s14 */
/* @0x2ce9d8 bx lr */
/* @0x2ce9dc andeq r0, r0, r0 */

/* ── FUNC 0x2ce9e0 · b2MouseJoint::ShiftOrigin(b2Vec2 const&) · size=36 · insn=9 */
/* @0x2ce9e0 vldr s15, [r1] */
/* @0x2ce9e4 vldr s14, [r0, #76] */
/* @0x2ce9e8 vldr s13, [r0, #80] */
/* @0x2ce9ec vsub.f32 s14, s14, s15 */
/* @0x2ce9f0 vldr s15, [r1, #4] */
/* @0x2ce9f4 vsub.f32 s15, s13, s15 */
/* @0x2ce9f8 vstr s14, [r0, #76] */
/* @0x2ce9fc vstr s15, [r0, #80] */
/* @0x2cea00 bx lr */

/* ── FUNC 0x2cea04 · b2MouseJoint::~b2MouseJoint() · size=24 · insn=6 */
/* @0x2cea04 ldr r3, [pc, #0xc] */
/* @0x2cea08 ldr r3, [pc, r3] */
/* @0x2cea0c add r3, r3, #8 */
/* @0x2cea10 str r3, [r0] */
/* @0x2cea14 bx lr */
/* @0x2cea18 andseq r3, r2, r12, asr #2 */

/* ── FUNC 0x2cea04 · b2MouseJoint::~b2MouseJoint() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2cea1c · b2MouseJoint::Dump() · size=16 · insn=4 */
/* @0x2cea1c ldr r0, [pc, #0x4] */
/* @0x2cea20 add r0, pc, r0 */
/* @0x2cea24 b 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cea28 andeq sp, r8, r0, lsr #13 */

/* ── FUNC 0x2cea2c · b2MouseJoint::~b2MouseJoint() · size=40 · insn=10 */
/* @0x2cea2c ldr r3, [pc, #0x1c] */
/* @0x2cea30 push {r4, lr} */
/* @0x2cea34 ldr r3, [pc, r3] */
/* @0x2cea38 mov r4, r0 */
/* @0x2cea3c add r3, r3, #8 */
/* @0x2cea40 str r3, [r0] */
/* @0x2cea44 bl 0x27d1d0 <_ZdlPv> */
/* @0x2cea48 mov r0, r4 */
/* @0x2cea4c pop {r4, pc} */
/* @0x2cea50 andseq r3, r2, r0, lsr #2 */

/* ── FUNC 0x2cea54 · b2MouseJoint::SolveVelocityConstraints(b2SolverData const&) · size=352 · insn=88 */
/* @0x2cea54 ldr r2, [r0, #0x74] */
/* @0x2cea58 vldr s10, [r0, #120] */
/* @0x2cea5c push {r4, lr} */
/* @0x2cea60 vpush {d8, d9, d10} */
/* @0x2cea64 mov r4, r0 */
/* @0x2cea68 vldr s9, [r4, #124] */
/* @0x2cea6c ldr r0, [r1, #0x1c] */
/* @0x2cea70 add r3, r2, r2, lsl #1 */
/* @0x2cea74 vldr s11, [r4, #164] */
/* @0x2cea78 vldr s13, [r4, #108] */
/* @0x2cea7c add r3, r0, r3, lsl #2 */
/* @0x2cea80 vldr s20, [r3, #4] */
/* @0x2cea84 vmov.f32 s4, s20 */
/* @0x2cea88 vldr s16, [r3, #8] */
/* @0x2cea8c vldr s21, [r3] */
/* @0x2cea90 vldr s17, [r4, #100] */
/* @0x2cea94 vldr s12, [r4, #160] */
/* @0x2cea98 vldr s18, [r4, #96] */
/* @0x2cea9c vldr s14, [r4, #156] */
/* @0x2ceaa0 vldr s6, [r4, #148] */
/* @0x2ceaa4 vmla.f32 s4, s16, s10 */
/* @0x2ceaa8 vldr s15, [r4, #152] */
/* @0x2ceaac vldr s7, [r4, #144] */
/* @0x2ceab0 vldr s19, [r1] */
/* @0x2ceab4 vldr s8, [r4, #104] */
/* @0x2ceab8 sub sp, sp, #8 */
/* @0x2ceabc vmov.f32 s5, s21 */
/* @0x2ceac0 vmls.f32 s5, s16, s9 */
/* @0x2ceac4 vadd.f32 s11, s4, s11 */
/* @0x2ceac8 vmla.f32 s11, s13, s17 */
/* @0x2ceacc vadd.f32 s12, s5, s12 */
/* @0x2cead0 vmla.f32 s12, s13, s18 */
/* @0x2cead4 vneg.f32 s11, s11 */
/* @0x2cead8 vmul.f32 s14, s11, s14 */
/* @0x2ceadc vneg.f32 s12, s12 */
/* @0x2ceae0 vmul.f32 s15, s11, s15 */
/* @0x2ceae4 vmla.f32 s14, s12, s6 */
/* @0x2ceae8 vmla.f32 s15, s12, s7 */
/* @0x2ceaec vadd.f32 s14, s17, s14 */
/* @0x2ceaf0 vmul.f32 s13, s14, s14 */
/* @0x2ceaf4 vstr s14, [r4, #100] */
/* @0x2ceaf8 vadd.f32 s15, s18, s15 */
/* @0x2ceafc vmul.f32 s19, s19, s8 */
/* @0x2ceb00 vstr s15, [r4, #96] */
/* @0x2ceb04 vmla.f32 s13, s15, s15 */
/* @0x2ceb08 vmul.f32 s12, s19, s19 */
/* @0x2ceb0c vcmpe.f32 s12, s13 */
/* @0x2ceb10 vmrs APSR_nzcv, fpscr */
/* @0x2ceb14 bmi 0x2ceb54 <_ZN12b2MouseJoint24SolveVelocityConstraintsERK12b2SolverData+0x100> */
/* @0x2ceb18 vsub.f32 s18, s15, s18 */
/* @0x2ceb1c vldr s12, [r4, #136] */
/* @0x2ceb20 vldr s15, [r4, #140] */
/* @0x2ceb24 vmul.f32 s13, s18, s9 */
/* @0x2ceb28 vsub.f32 s17, s14, s17 */
/* @0x2ceb2c vnmls.f32 s13, s17, s10 */
/* @0x2ceb30 vmla.f32 s21, s12, s18 */
/* @0x2ceb34 vmla.f32 s16, s13, s15 */
/* @0x2ceb38 vstr s21, [r3] */
/* @0x2ceb3c vmla.f32 s20, s12, s17 */
/* @0x2ceb40 vstr s16, [r3, #8] */
/* @0x2ceb44 vstr s20, [r3, #4] */
/* @0x2ceb48 add sp, sp, #8 */
/* @0x2ceb4c vpop {d8, d9, d10} */
/* @0x2ceb50 pop {r4, pc} */
/* @0x2ceb54 vsqrt.f32 s14, s13 */
/* @0x2ceb58 vcmp.f32 s14, s14 */
/* @0x2ceb5c vmrs APSR_nzcv, fpscr */
/* @0x2ceb60 bne 0x2ceb8c <_ZN12b2MouseJoint24SolveVelocityConstraintsERK12b2SolverData+0x138> */
/* @0x2ceb64 vdiv.f32 s19, s19, s14 */
/* @0x2ceb68 vldr s15, [r4, #96] */
/* @0x2ceb6c vldr s14, [r4, #100] */
/* @0x2ceb70 add r2, r2, r2, lsl #1 */
/* @0x2ceb74 add r3, r0, r2, lsl #2 */
/* @0x2ceb78 vmul.f32 s15, s19, s15 */
/* @0x2ceb7c vmul.f32 s14, s19, s14 */
/* @0x2ceb80 vstr s15, [r4, #96] */
/* @0x2ceb84 vstr s14, [r4, #100] */
/* @0x2ceb88 b 0x2ceb18 <_ZN12b2MouseJoint24SolveVelocityConstraintsERK12b2SolverData+0xc4> */
/* @0x2ceb8c vmov r0, s13 */
/* @0x2ceb90 str r1, [sp, #0x4] */
/* @0x2ceb94 bl 0xb6700 <sqrtf@plt> */
/* @0x2ceb98 ldr r1, [sp, #0x4] */
/* @0x2ceb9c vldr s9, [r4, #124] */
/* @0x2ceba0 ldr r2, [r4, #0x74] */
/* @0x2ceba4 vldr s10, [r4, #120] */
/* @0x2ceba8 vmov s14, r0 */
/* @0x2cebac ldr r0, [r1, #0x1c] */
/* @0x2cebb0 b 0x2ceb64 <_ZN12b2MouseJoint24SolveVelocityConstraintsERK12b2SolverData+0x110> */

/* ── FUNC 0x2cebb4 · b2MouseJoint::InitVelocityConstraints(b2SolverData const&) · size=520 · insn=130 */
/* @0x2cebb4 push {r4, r5, r6, r7, r8, lr} */
/* @0x2cebb8 vpush {d8, d9, d10} */
/* @0x2cebbc mov r7, r1 */
/* @0x2cebc0 ldr r6, [r0, #0x34] */
/* @0x2cebc4 mov r4, r0 */
/* @0x2cebc8 ldr lr, [r1, #0x18] */
/* @0x2cebcc vldr s16, [r6, #144] */
/* @0x2cebd0 add r1, r6, #44 */
/* @0x2cebd4 ldr r12, [r7, #0x1c] */
/* @0x2cebd8 ldr r3, [r6, #0x8] */
/* @0x2cebdc vldr s17, [r6, #136] */
/* @0x2cebe0 add r2, r0, #128 */
/* @0x2cebe4 ldm r1, {r0, r1} */
/* @0x2cebe8 add r5, r3, r3, lsl #1 */
/* @0x2cebec str r3, [r4, #0x74] */
/* @0x2cebf0 stm r2, {r0, r1} */
/* @0x2cebf4 vstr s17, [r4, #136] */
/* @0x2cebf8 lsl r5, r5, #2 */
/* @0x2cebfc vstr s16, [r4, #140] */
/* @0x2cec00 add r3, lr, r5 */
/* @0x2cec04 add r5, r12, r5 */
/* @0x2cec08 vldr s20, [r3] */
/* @0x2cec0c vldr s19, [r3, #4] */
/* @0x2cec10 ldr r8, [r3, #0x8] */
/* @0x2cec14 mov r0, r8 */
/* @0x2cec18 bl 0xb6580 <sinf@plt> */
/* @0x2cec1c vmov s18, r0 */
/* @0x2cec20 mov r0, r8 */
/* @0x2cec24 bl 0xb658c <cosf@plt> */
/* @0x2cec28 vldr s14, [r4, #84] */
/* @0x2cec2c vldr s15, [pc, #384] */
/* @0x2cec30 vmul.f32 s15, s14, s15 */
/* @0x2cec34 vldr s14, [r6, #132] */
/* @0x2cec38 vldr s13, [r7] */
/* @0x2cec3c vldr s10, [r4, #88] */
/* @0x2cec40 vldr s5, [r5, #8] */
/* @0x2cec44 vldr s6, [r5] */
/* @0x2cec48 vldr s7, [r5, #4] */
/* @0x2cec4c vldr s3, [r4, #76] */
/* @0x2cec50 vldr s4, [r4, #80] */
/* @0x2cec54 ldrb r3, [r7, #0x14] */
/* @0x2cec58 vmul.f32 s8, s15, s15 */
/* @0x2cec5c vmul.f32 s8, s14, s8 */
/* @0x2cec60 vmov s11, r0 */
/* @0x2cec64 vadd.f32 s14, s14, s14 */
/* @0x2cec68 vmul.f32 s8, s13, s8 */
/* @0x2cec6c vmul.f32 s14, s14, s10 */
/* @0x2cec70 vldr s10, [r4, #68] */
/* @0x2cec74 vmov.f32 s12, s8 */
/* @0x2cec78 vmla.f32 s12, s14, s15 */
/* @0x2cec7c vldr s14, [r4, #72] */
/* @0x2cec80 vmul.f32 s12, s12, s13 */
/* @0x2cec84 vldr s13, [r4, #128] */
/* @0x2cec88 vcmp.f32 s12, #0 */
/* @0x2cec8c vmrs APSR_nzcv, fpscr */
/* @0x2cec90 vmovne.f32 s15, #1.000000e+00 */
/* @0x2cec94 vstreq s12, [r4, #108] */
/* @0x2cec98 vdivne.f32 s15, s15, s12 */
/* @0x2cec9c vmovne.f32 s12, s15 */
/* @0x2ceca0 vstrne s15, [r4, #108] */
/* @0x2ceca4 vldr s15, [r4, #132] */
/* @0x2ceca8 vsub.f32 s14, s14, s15 */
/* @0x2cecac vmul.f32 s15, s14, s18 */
/* @0x2cecb0 vmul.f32 s14, s14, s11 */
/* @0x2cecb4 vsub.f32 s13, s10, s13 */
/* @0x2cecb8 vmla.f32 s14, s13, s18 */
/* @0x2cecbc vmul.f32 s10, s16, s14 */
/* @0x2cecc0 vstr s14, [r4, #124] */
/* @0x2cecc4 vnmls.f32 s15, s13, s11 */
/* @0x2cecc8 vmov.f32 s9, s17 */
/* @0x2ceccc vstr s15, [r4, #120] */
/* @0x2cecd0 vmla.f32 s9, s10, s14 */
/* @0x2cecd4 vmul.f32 s13, s16, s15 */
/* @0x2cecd8 vnmul.f32 s11, s16, s15 */
/* @0x2cecdc vmov.f32 s10, s9 */
/* @0x2cece0 vmov.f32 s9, s17 */
/* @0x2cece4 vmla.f32 s9, s13, s15 */
/* @0x2cece8 vmul.f32 s11, s11, s14 */
/* @0x2cecec vmul.f32 s13, s11, s11 */
/* @0x2cecf0 vadd.f32 s10, s10, s12 */
/* @0x2cecf4 vadd.f32 s9, s9, s12 */
/* @0x2cecf8 vnmls.f32 s13, s10, s9 */
/* @0x2cecfc vcmp.f32 s13, #0 */
/* @0x2ced00 vmul.f32 s12, s8, s12 */
/* @0x2ced04 vmrs APSR_nzcv, fpscr */
/* @0x2ced08 vmovne.f32 s8, #1.000000e+00 */
/* @0x2ced0c vstr s12, [r4, #92] */
/* @0x2ced10 vdivne.f32 s13, s8, s13 */
/* @0x2ced14 cmp r3, #0 */
/* @0x2ced18 vldr s8, [pc, #152] */
/* @0x2ced1c vadd.f32 s20, s20, s15 */
/* @0x2ced20 vadd.f32 s19, s14, s19 */
/* @0x2ced24 vsub.f32 s20, s20, s3 */
/* @0x2ced28 vsub.f32 s19, s19, s4 */
/* @0x2ced2c vnmul.f32 s11, s13, s11 */
/* @0x2ced30 vmul.f32 s9, s9, s13 */
/* @0x2ced34 vstr s11, [r4, #148] */
/* @0x2ced38 vstr s11, [r4, #152] */
/* @0x2ced3c vmul.f32 s13, s10, s13 */
/* @0x2ced40 vstr s9, [r4, #144] */
/* @0x2ced44 vmul.f32 s20, s12, s20 */
/* @0x2ced48 vstr s13, [r4, #156] */
/* @0x2ced4c vmul.f32 s12, s12, s19 */
/* @0x2ced50 vstr s20, [r4, #160] */
/* @0x2ced54 vstr s12, [r4, #164] */
/* @0x2ced58 vmul.f32 s13, s5, s8 */
/* @0x2ced5c bne 0x2ced80 <_ZN12b2MouseJoint23InitVelocityConstraintsERK12b2SolverData+0x1cc> */
/* @0x2ced60 mov r3, #0 */
/* @0x2ced64 str r3, [r4, #0x60] */
/* @0x2ced68 str r3, [r4, #0x64] */
/* @0x2ced6c vpop {d8, d9, d10} */
/* @0x2ced70 vstr s6, [r5] */
/* @0x2ced74 vstr s7, [r5, #4] */
/* @0x2ced78 vstr s13, [r5, #8] */
/* @0x2ced7c pop {r4, r5, r6, r7, r8, pc} */
/* @0x2ced80 vldr s12, [r7, #8] */
/* @0x2ced84 vldr s11, [r4, #96] */
/* @0x2ced88 vmul.f32 s11, s12, s11 */
/* @0x2ced8c vldr s10, [r4, #100] */
/* @0x2ced90 vmul.f32 s14, s14, s11 */
/* @0x2ced94 vstr s11, [r4, #96] */
/* @0x2ced98 vmul.f32 s12, s12, s10 */
/* @0x2ced9c vnmls.f32 s14, s15, s12 */
/* @0x2ceda0 vstr s12, [r4, #100] */
/* @0x2ceda4 vmla.f32 s6, s17, s11 */
/* @0x2ceda8 vmla.f32 s13, s16, s14 */
/* @0x2cedac vmla.f32 s7, s17, s12 */
/* @0x2cedb0 b 0x2ced6c <_ZN12b2MouseJoint23InitVelocityConstraintsERK12b2SolverData+0x1b8> */
/* @0x2cedb4 ldrdmi r0, r1, [r9], #251 */
/* @0x2cedb8 svclo #0x7ae148 */

/* ── FUNC 0x2cedbc · b2MouseJoint::b2MouseJoint(b2MouseJointDef const*) · size=660 · insn=165 */
/* @0x2cedbc push {r4, r5, r6, lr} */
/* @0x2cedc0 sub sp, sp, #16 */
/* @0x2cedc4 mov r4, r0 */
/* @0x2cedc8 mov r5, r1 */
/* @0x2cedcc ldr r6, [pc, #0x264] */
/* @0x2cedd0 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef> */
/* @0x2cedd4 vldr s15, [r5, #20] */
/* @0x2cedd8 vcmp.f32 s15, s15 */
/* @0x2ceddc ldr r3, [pc, #0x258] */
/* @0x2cede0 ldr r6, [pc, r6] */
/* @0x2cede4 ldr r3, [pc, r3] */
/* @0x2cede8 ldr r2, [r6] */
/* @0x2cedec add r3, r3, #8 */
/* @0x2cedf0 vmrs APSR_nzcv, fpscr */
/* @0x2cedf4 str r3, [r4] */
/* @0x2cedf8 bne 0x2cee20 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x64> */
/* @0x2cedfc mov r3, #0 */
/* @0x2cee00 movw r1, #0x7f80 */
/* @0x2cee04 strh r3, [sp] */
/* @0x2cee08 strh r1, [sp, #2] */
/* @0x2cee0c vldr s14, [sp] */
/* @0x2cee10 vneg.f32 s13, s14 */
/* @0x2cee14 vcmpe.f32 s15, s13 */
/* @0x2cee18 vmrs APSR_nzcv, fpscr */
/* @0x2cee1c bgt 0x2cefec <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x230> */
/* @0x2cee20 mov r0, #0 */
/* @0x2cee24 ldr r1, [pc, #0x214] */
/* @0x2cee28 add r1, pc, r1 */
/* @0x2cee2c blx r2 */
/* @0x2cee30 vldr s15, [r5, #28] */
/* @0x2cee34 vcmp.f32 s15, s15 */
/* @0x2cee38 ldr r3, [r6] */
/* @0x2cee3c vmrs APSR_nzcv, fpscr */
/* @0x2cee40 bne 0x2cee68 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0xac> */
/* @0x2cee44 mov r1, #0 */
/* @0x2cee48 movw r2, #0x7f80 */
/* @0x2cee4c strh r1, [sp] */
/* @0x2cee50 strh r2, [sp, #2] */
/* @0x2cee54 vldr s14, [sp] */
/* @0x2cee58 vneg.f32 s13, s14 */
/* @0x2cee5c vcmpe.f32 s15, s13 */
/* @0x2cee60 vmrs APSR_nzcv, fpscr */
/* @0x2cee64 bgt 0x2cefcc <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x210> */
/* @0x2cee68 mov r0, #0 */
/* @0x2cee6c ldr r1, [pc, #0x1d0] */
/* @0x2cee70 add r1, pc, r1 */
/* @0x2cee74 blx r3 */
/* @0x2cee78 vldr s15, [r5, #32] */
/* @0x2cee7c vcmp.f32 s15, s15 */
/* @0x2cee80 ldr r3, [r6] */
/* @0x2cee84 vmrs APSR_nzcv, fpscr */
/* @0x2cee88 bne 0x2ceeb0 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0xf4> */
/* @0x2cee8c mov r1, #0 */
/* @0x2cee90 movw r2, #0x7f80 */
/* @0x2cee94 strh r1, [sp] */
/* @0x2cee98 strh r2, [sp, #2] */
/* @0x2cee9c vldr s14, [sp] */
/* @0x2ceea0 vneg.f32 s13, s14 */
/* @0x2ceea4 vcmpe.f32 s15, s13 */
/* @0x2ceea8 vmrs APSR_nzcv, fpscr */
/* @0x2ceeac bgt 0x2cefac <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x1f0> */
/* @0x2ceeb0 mov r0, #0 */
/* @0x2ceeb4 ldr r1, [pc, #0x18c] */
/* @0x2ceeb8 add r1, pc, r1 */
/* @0x2ceebc blx r3 */
/* @0x2ceec0 vldr s15, [r5, #36] */
/* @0x2ceec4 vcmp.f32 s15, s15 */
/* @0x2ceec8 ldr r3, [r6] */
/* @0x2ceecc vmrs APSR_nzcv, fpscr */
/* @0x2ceed0 bne 0x2ceef8 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x13c> */
/* @0x2ceed4 mov r1, #0 */
/* @0x2ceed8 movw r2, #0x7f80 */
/* @0x2ceedc strh r1, [sp] */
/* @0x2ceee0 strh r2, [sp, #2] */
/* @0x2ceee4 vldr s14, [sp] */
/* @0x2ceee8 vneg.f32 s13, s14 */
/* @0x2ceeec vcmpe.f32 s15, s13 */
/* @0x2ceef0 vmrs APSR_nzcv, fpscr */
/* @0x2ceef4 bgt 0x2cef8c <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x1d0> */
/* @0x2ceef8 mov r0, #0 */
/* @0x2ceefc ldr r1, [pc, #0x148] */
/* @0x2cef00 add r1, pc, r1 */
/* @0x2cef04 blx r3 */
/* @0x2cef08 add r2, r5, #20 */
/* @0x2cef0c add r12, r4, #76 */
/* @0x2cef10 ldr r3, [r4, #0x34] */
/* @0x2cef14 ldm r2, {r0, r1} */
/* @0x2cef18 vldr s15, [r3, #16] */
/* @0x2cef1c vldr s11, [r3, #20] */
/* @0x2cef20 vldr s13, [r3, #24] */
/* @0x2cef24 vldr s12, [r3, #12] */
/* @0x2cef28 ldr r2, [r5, #0x1c] */
/* @0x2cef2c stm r12, {r0, r1} */
/* @0x2cef30 vldr s14, [r4, #80] */
/* @0x2cef34 vsub.f32 s14, s14, s15 */
/* @0x2cef38 vldr s10, [r4, #76] */
/* @0x2cef3c ldr r1, [r5, #0x20] */
/* @0x2cef40 mov r3, #0 */
/* @0x2cef44 str r2, [r4, #0x68] */
/* @0x2cef48 mov r0, r4 */
/* @0x2cef4c ldr r2, [r5, #0x24] */
/* @0x2cef50 str r3, [r4, #0x60] */
/* @0x2cef54 str r3, [r4, #0x64] */
/* @0x2cef58 str r1, [r4, #0x54] */
/* @0x2cef5c str r3, [r4, #0x5c] */
/* @0x2cef60 str r2, [r4, #0x58] */
/* @0x2cef64 str r3, [r4, #0x6c] */
/* @0x2cef68 vmul.f32 s15, s14, s11 */
/* @0x2cef6c vmul.f32 s14, s14, s13 */
/* @0x2cef70 vsub.f32 s12, s10, s12 */
/* @0x2cef74 vmls.f32 s14, s11, s12 */
/* @0x2cef78 vmla.f32 s15, s12, s13 */
/* @0x2cef7c vstr s14, [r4, #72] */
/* @0x2cef80 vstr s15, [r4, #68] */
/* @0x2cef84 add sp, sp, #16 */
/* @0x2cef88 pop {r4, r5, r6, pc} */
/* @0x2cef8c vcmpe.f32 s15, s14 */
/* @0x2cef90 vmrs APSR_nzcv, fpscr */
/* @0x2cef94 bpl 0x2ceef8 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x13c> */
/* @0x2cef98 vcmpe.f32 s15, #0 */
/* @0x2cef9c vmrs APSR_nzcv, fpscr */
/* @0x2cefa0 movge r0, #1 */
/* @0x2cefa4 bge 0x2ceefc <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x140> */
/* @0x2cefa8 b 0x2ceef8 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x13c> */
/* @0x2cefac vcmpe.f32 s15, s14 */
/* @0x2cefb0 vmrs APSR_nzcv, fpscr */
/* @0x2cefb4 bpl 0x2ceeb0 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0xf4> */
/* @0x2cefb8 vcmpe.f32 s15, #0 */
/* @0x2cefbc vmrs APSR_nzcv, fpscr */
/* @0x2cefc0 movge r0, #1 */
/* @0x2cefc4 bge 0x2ceeb4 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0xf8> */
/* @0x2cefc8 b 0x2ceeb0 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0xf4> */
/* @0x2cefcc vcmpe.f32 s15, s14 */
/* @0x2cefd0 vmrs APSR_nzcv, fpscr */
/* @0x2cefd4 bpl 0x2cee68 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0xac> */
/* @0x2cefd8 vcmpe.f32 s15, #0 */
/* @0x2cefdc vmrs APSR_nzcv, fpscr */
/* @0x2cefe0 movge r0, #1 */
/* @0x2cefe4 bge 0x2cee6c <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0xb0> */
/* @0x2cefe8 b 0x2cee68 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0xac> */
/* @0x2cefec vcmpe.f32 s15, s14 */
/* @0x2ceff0 vmrs APSR_nzcv, fpscr */
/* @0x2ceff4 bpl 0x2cee20 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x64> */
/* @0x2ceff8 vldr s15, [r5, #24] */
/* @0x2ceffc vcmp.f32 s15, s15 */
/* @0x2cf000 vmrs APSR_nzcv, fpscr */
/* @0x2cf004 bne 0x2cee20 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x64> */
/* @0x2cf008 strh r3, [sp] */
/* @0x2cf00c strh r1, [sp, #2] */
/* @0x2cf010 vldr s14, [sp] */
/* @0x2cf014 vneg.f32 s13, s14 */
/* @0x2cf018 vcmpe.f32 s15, s13 */
/* @0x2cf01c vmrs APSR_nzcv, fpscr */
/* @0x2cf020 ble 0x2cee20 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x64> */
/* @0x2cf024 vcmpe.f32 s15, s14 */
/* @0x2cf028 vmrs APSR_nzcv, fpscr */
/* @0x2cf02c bpl 0x2cee20 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x64> */
/* @0x2cf030 mov r0, #1 */
/* @0x2cf034 b 0x2cee24 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x68> */
/* @0x2cf038 andseq r2, r2, r8, ror #13 */
/* @0x2cf03c andseq r2, r2, r0, lsl #27 */
/* @0x2cf040 andeq lr, r8, r4, lsl r7 */
/* @0x2cf044 andeq lr, r8, r4, lsr #14 */
/* @0x2cf048 andeq lr, r8, r4, lsr #15 */
/* @0x2cf04c andeq lr, r8, r12, lsr r8 */

/* ── FUNC 0x2cedbc · b2MouseJoint::b2MouseJoint(b2MouseJointDef const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2cf050 · b2MouseJoint::SetTarget(b2Vec2 const&) · size=48 · insn=12 */
/* @0x2cf050 ldr r2, [r0, #0x34] */
/* @0x2cf054 mov r3, r0 */
/* @0x2cf058 add r3, r3, #76 */
/* @0x2cf05c ldrh r0, [r2, #4] */
/* @0x2cf060 tst r0, #2 */
/* @0x2cf064 orreq r0, r0, #2 */
/* @0x2cf068 strheq r0, [r2, #4] */
/* @0x2cf06c ldm r1, {r0, r1} */
/* @0x2cf070 moveq r12, #0 */
/* @0x2cf074 streq r12, [r2, #0xa0] */
/* @0x2cf078 stm r3, {r0, r1} */
/* @0x2cf07c bx lr */

/* ── FUNC 0x2cf080 · b2MouseJoint::GetTarget() const · size=8 · insn=2 */
/* @0x2cf080 add r0, r0, #76 */
/* @0x2cf084 bx lr */

/* ── FUNC 0x2cf088 · b2MouseJoint::SetMaxForce(float) · size=8 · insn=2 */
/* @0x2cf088 str r1, [r0, #0x68] */
/* @0x2cf08c bx lr */

/* ── FUNC 0x2cf090 · b2MouseJoint::GetMaxForce() const · size=8 · insn=2 */
/* @0x2cf090 ldr r0, [r0, #0x68] */
/* @0x2cf094 bx lr */

/* ── FUNC 0x2cf098 · b2MouseJoint::SetFrequency(float) · size=8 · insn=2 */
/* @0x2cf098 str r1, [r0, #0x54] */
/* @0x2cf09c bx lr */

/* ── FUNC 0x2cf0a0 · b2MouseJoint::GetFrequency() const · size=8 · insn=2 */
/* @0x2cf0a0 ldr r0, [r0, #0x54] */
/* @0x2cf0a4 bx lr */

/* ── FUNC 0x2cf0a8 · b2MouseJoint::SetDampingRatio(float) · size=8 · insn=2 */
/* @0x2cf0a8 str r1, [r0, #0x58] */
/* @0x2cf0ac bx lr */

/* ── FUNC 0x2cf0b0 · b2MouseJoint::GetDampingRatio() const · size=8 · insn=2 */
/* @0x2cf0b0 ldr r0, [r0, #0x58] */
/* @0x2cf0b4 bx lr */

/* ── FUNC 0x2cf0b8 · b2PrismaticJoint::GetAnchorA() const · size=64 · insn=16 */
/* @0x2cf0b8 ldr r3, [r1, #0x30] */
/* @0x2cf0bc vldr s15, [r1, #72] */
/* @0x2cf0c0 vldr s12, [r3, #24] */
/* @0x2cf0c4 vldr s11, [r3, #20] */
/* @0x2cf0c8 vmul.f32 s14, s12, s15 */
/* @0x2cf0cc vldr s13, [r1, #68] */
/* @0x2cf0d0 vldr s9, [r3, #16] */
/* @0x2cf0d4 vldr s10, [r3, #12] */
/* @0x2cf0d8 vmul.f32 s15, s11, s15 */
/* @0x2cf0dc vmla.f32 s14, s13, s11 */
/* @0x2cf0e0 vnmls.f32 s15, s12, s13 */
/* @0x2cf0e4 vadd.f32 s14, s14, s9 */
/* @0x2cf0e8 vadd.f32 s15, s15, s10 */
/* @0x2cf0ec vstr s14, [r0, #4] */
/* @0x2cf0f0 vstr s15, [r0] */
/* @0x2cf0f4 bx lr */
