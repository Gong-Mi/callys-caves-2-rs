/* libyoyo.so 覆盖卡组 0277
 * 函数 0x2d2104..0x2d2e80，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2d2104 · b2RevoluteJoint::GetJointAngle() const · size=36 · insn=9 */
/* @0x2d2104 ldr r3, [r0, #0x34] */
/* @0x2d2108 vldr s13, [r3, #72] */
/* @0x2d210c ldr r3, [r0, #0x30] */
/* @0x2d2110 vldr s14, [r3, #72] */
/* @0x2d2114 vsub.f32 s14, s13, s14 */
/* @0x2d2118 vldr s15, [r0, #116] */
/* @0x2d211c vsub.f32 s15, s14, s15 */
/* @0x2d2120 vmov r0, s15 */
/* @0x2d2124 bx lr */

/* ── FUNC 0x2d2128 · b2RevoluteJoint::GetJointSpeed() const · size=28 · insn=7 */
/* @0x2d2128 ldr r3, [r0, #0x34] */
/* @0x2d212c vldr s14, [r3, #88] */
/* @0x2d2130 ldr r3, [r0, #0x30] */
/* @0x2d2134 vldr s15, [r3, #88] */
/* @0x2d2138 vsub.f32 s15, s14, s15 */
/* @0x2d213c vmov r0, s15 */
/* @0x2d2140 bx lr */

/* ── FUNC 0x2d2144 · b2RevoluteJoint::IsMotorEnabled() const · size=8 · insn=2 */
/* @0x2d2144 ldrb r0, [r0, #0x64] */
/* @0x2d2148 bx lr */

/* ── FUNC 0x2d214c · b2RevoluteJoint::EnableMotor(bool) · size=64 · insn=16 */
/* @0x2d214c ldr r3, [r0, #0x30] */
/* @0x2d2150 ldrh r2, [r3, #4] */
/* @0x2d2154 tst r2, #2 */
/* @0x2d2158 orreq r2, r2, #2 */
/* @0x2d215c strheq r2, [r3, #4] */
/* @0x2d2160 moveq r12, #0 */
/* @0x2d2164 streq r12, [r3, #0xa0] */
/* @0x2d2168 ldr r3, [r0, #0x34] */
/* @0x2d216c ldrh r2, [r3, #4] */
/* @0x2d2170 tst r2, #2 */
/* @0x2d2174 orreq r2, r2, #2 */
/* @0x2d2178 strheq r2, [r3, #4] */
/* @0x2d217c moveq r12, #0 */
/* @0x2d2180 streq r12, [r3, #0xa0] */
/* @0x2d2184 strb r1, [r0, #0x64] */
/* @0x2d2188 bx lr */

/* ── FUNC 0x2d218c · b2RevoluteJoint::GetMotorTorque(float) const · size=20 · insn=5 */
/* @0x2d218c vmov s14, r1 */
/* @0x2d2190 vldr s15, [r0, #96] */
/* @0x2d2194 vmul.f32 s14, s14, s15 */
/* @0x2d2198 vmov r0, s14 */
/* @0x2d219c bx lr */

/* ── FUNC 0x2d21a0 · b2RevoluteJoint::SetMotorSpeed(float) · size=64 · insn=16 */
/* @0x2d21a0 ldr r3, [r0, #0x30] */
/* @0x2d21a4 ldrh r2, [r3, #4] */
/* @0x2d21a8 tst r2, #2 */
/* @0x2d21ac orreq r2, r2, #2 */
/* @0x2d21b0 strheq r2, [r3, #4] */
/* @0x2d21b4 moveq r12, #0 */
/* @0x2d21b8 streq r12, [r3, #0xa0] */
/* @0x2d21bc ldr r3, [r0, #0x34] */
/* @0x2d21c0 ldrh r2, [r3, #4] */
/* @0x2d21c4 tst r2, #2 */
/* @0x2d21c8 orreq r2, r2, #2 */
/* @0x2d21cc strheq r2, [r3, #4] */
/* @0x2d21d0 moveq r12, #0 */
/* @0x2d21d4 streq r12, [r3, #0xa0] */
/* @0x2d21d8 str r1, [r0, #0x6c] */
/* @0x2d21dc bx lr */

/* ── FUNC 0x2d21e0 · b2RevoluteJoint::SetMaxMotorTorque(float) · size=64 · insn=16 */
/* @0x2d21e0 ldr r3, [r0, #0x30] */
/* @0x2d21e4 ldrh r2, [r3, #4] */
/* @0x2d21e8 tst r2, #2 */
/* @0x2d21ec orreq r2, r2, #2 */
/* @0x2d21f0 strheq r2, [r3, #4] */
/* @0x2d21f4 moveq r12, #0 */
/* @0x2d21f8 streq r12, [r3, #0xa0] */
/* @0x2d21fc ldr r3, [r0, #0x34] */
/* @0x2d2200 ldrh r2, [r3, #4] */
/* @0x2d2204 tst r2, #2 */
/* @0x2d2208 orreq r2, r2, #2 */
/* @0x2d220c strheq r2, [r3, #4] */
/* @0x2d2210 moveq r12, #0 */
/* @0x2d2214 streq r12, [r3, #0xa0] */
/* @0x2d2218 str r1, [r0, #0x68] */
/* @0x2d221c bx lr */

/* ── FUNC 0x2d2220 · b2RevoluteJoint::IsLimitEnabled() const · size=8 · insn=2 */
/* @0x2d2220 ldrb r0, [r0, #0x70] */
/* @0x2d2224 bx lr */

/* ── FUNC 0x2d2228 · b2RevoluteJoint::EnableLimit(bool) · size=84 · insn=21 */
/* @0x2d2228 ldrb r3, [r0, #0x70] */
/* @0x2d222c cmp r3, r1 */
/* @0x2d2230 bxeq lr */
/* @0x2d2234 ldr r3, [r0, #0x30] */
/* @0x2d2238 ldrh r2, [r3, #4] */
/* @0x2d223c tst r2, #2 */
/* @0x2d2240 orreq r2, r2, #2 */
/* @0x2d2244 strheq r2, [r3, #4] */
/* @0x2d2248 moveq r12, #0 */
/* @0x2d224c streq r12, [r3, #0xa0] */
/* @0x2d2250 ldr r3, [r0, #0x34] */
/* @0x2d2254 ldrh r2, [r3, #4] */
/* @0x2d2258 tst r2, #2 */
/* @0x2d225c orreq r2, r2, #2 */
/* @0x2d2260 strheq r2, [r3, #4] */
/* @0x2d2264 moveq r12, #0 */
/* @0x2d2268 streq r12, [r3, #0xa0] */
/* @0x2d226c mov r3, #0 */
/* @0x2d2270 strb r1, [r0, #0x70] */
/* @0x2d2274 str r3, [r0, #0x5c] */
/* @0x2d2278 bx lr */

/* ── FUNC 0x2d227c · b2RevoluteJoint::GetLowerLimit() const · size=8 · insn=2 */
/* @0x2d227c ldr r0, [r0, #0x78] */
/* @0x2d2280 bx lr */

/* ── FUNC 0x2d2284 · b2RevoluteJoint::GetUpperLimit() const · size=8 · insn=2 */
/* @0x2d2284 ldr r0, [r0, #0x7c] */
/* @0x2d2288 bx lr */

/* ── FUNC 0x2d228c · b2RevoluteJoint::SetLimits(float, float) · size=180 · insn=45 */
/* @0x2d228c push {r4, lr} */
/* @0x2d2290 vpush {d8} */
/* @0x2d2294 vmov s16, r1 */
/* @0x2d2298 vmov s17, r2 */
/* @0x2d229c ldr r3, [pc, #0x94] */
/* @0x2d22a0 ldr r1, [pc, #0x94] */
/* @0x2d22a4 mov r4, r0 */
/* @0x2d22a8 vcmpe.f32 s16, s17 */
/* @0x2d22ac ldr r3, [pc, r3] */
/* @0x2d22b0 add r1, pc, r1 */
/* @0x2d22b4 ldr r3, [r3] */
/* @0x2d22b8 vmrs APSR_nzcv, fpscr */
/* @0x2d22bc movhi r0, #0 */
/* @0x2d22c0 movls r0, #1 */
/* @0x2d22c4 blx r3 */
/* @0x2d22c8 vldr s15, [r4, #120] */
/* @0x2d22cc vcmp.f32 s15, s16 */
/* @0x2d22d0 vmrs APSR_nzcv, fpscr */
/* @0x2d22d4 bne 0x2d22e8 <_ZN15b2RevoluteJoint9SetLimitsEff+0x5c> */
/* @0x2d22d8 vldr s15, [r4, #124] */
/* @0x2d22dc vcmp.f32 s15, s17 */
/* @0x2d22e0 vmrs APSR_nzcv, fpscr */
/* @0x2d22e4 beq 0x2d2330 <_ZN15b2RevoluteJoint9SetLimitsEff+0xa4> */
/* @0x2d22e8 ldr r3, [r4, #0x30] */
/* @0x2d22ec ldrh r2, [r3, #4] */
/* @0x2d22f0 tst r2, #2 */
/* @0x2d22f4 orreq r2, r2, #2 */
/* @0x2d22f8 strheq r2, [r3, #4] */
/* @0x2d22fc moveq r1, #0 */
/* @0x2d2300 streq r1, [r3, #0xa0] */
/* @0x2d2304 ldr r3, [r4, #0x34] */
/* @0x2d2308 ldrh r2, [r3, #4] */
/* @0x2d230c tst r2, #2 */
/* @0x2d2310 orreq r2, r2, #2 */
/* @0x2d2314 strheq r2, [r3, #4] */
/* @0x2d2318 moveq r1, #0 */
/* @0x2d231c streq r1, [r3, #0xa0] */
/* @0x2d2320 mov r3, #0 */
/* @0x2d2324 vstr s16, [r4, #120] */
/* @0x2d2328 vstr s17, [r4, #124] */
/* @0x2d232c str r3, [r4, #0x5c] */
/* @0x2d2330 vpop {d8} */
/* @0x2d2334 pop {r4, pc} */
/* @0x2d2338 andseq pc, r1, r12, lsl r2 */
/* @0x2d233c andeq r11, r8, r4, ror r5 */

/* ── FUNC 0x2d2340 · b2RopeJoint::SolveVelocityConstraints(b2SolverData const&) · size=300 · insn=75 */
/* @0x2d2340 ldr r2, [r0, #0x60] */
/* @0x2d2344 vpush {d8, d9, d10} */
/* @0x2d2348 ldr r3, [r0, #0x64] */
/* @0x2d234c vldr s2, [r0, #112] */
/* @0x2d2350 ldr r12, [r1, #0x1c] */
/* @0x2d2354 vldr s3, [r0, #120] */
/* @0x2d2358 add r2, r2, r2, lsl #1 */
/* @0x2d235c vldr s1, [r0, #124] */
/* @0x2d2360 add r3, r3, r3, lsl #1 */
/* @0x2d2364 vldr s11, [r0, #116] */
/* @0x2d2368 add r2, r12, r2, lsl #2 */
/* @0x2d236c vldr s5, [r2, #4] */
/* @0x2d2370 add r3, r12, r3, lsl #2 */
/* @0x2d2374 vmov.f32 s13, s5 */
/* @0x2d2378 vldr s9, [r3, #4] */
/* @0x2d237c vldr s10, [r2, #8] */
/* @0x2d2380 vldr s12, [r3, #8] */
/* @0x2d2384 vldr s7, [r3] */
/* @0x2d2388 vldr s4, [r2] */
/* @0x2d238c vldr s0, [r0, #108] */
/* @0x2d2390 vmov.f32 s17, s9 */
/* @0x2d2394 vldr s14, [r0, #104] */
/* @0x2d2398 vldr s16, [r0, #88] */
/* @0x2d239c vldr s15, [r0, #84] */
/* @0x2d23a0 vldr s19, [pc, #192] */
/* @0x2d23a4 vldr s18, [r0, #152] */
/* @0x2d23a8 vmla.f32 s17, s12, s3 */
/* @0x2d23ac vmla.f32 s13, s10, s2 */
/* @0x2d23b0 vmov.f32 s6, s7 */
/* @0x2d23b4 vmov.f32 s8, s4 */
/* @0x2d23b8 vmls.f32 s6, s12, s1 */
/* @0x2d23bc vmls.f32 s8, s10, s11 */
/* @0x2d23c0 vsub.f32 s13, s17, s13 */
/* @0x2d23c4 vldr s17, [r0, #156] */
/* @0x2d23c8 vmul.f32 s13, s13, s0 */
/* @0x2d23cc vsub.f32 s8, s6, s8 */
/* @0x2d23d0 vldr s6, [r0, #144] */
/* @0x2d23d4 vmla.f32 s13, s8, s14 */
/* @0x2d23d8 vsub.f32 s15, s16, s15 */
/* @0x2d23dc vldr s16, [r0, #92] */
/* @0x2d23e0 vcmpe.f32 s15, #0 */
/* @0x2d23e4 vmrs APSR_nzcv, fpscr */
/* @0x2d23e8 vldrmi s8, [r1, #4] */
/* @0x2d23ec vmlami.f32 s13, s15, s8 */
/* @0x2d23f0 vldr s15, [r0, #160] */
/* @0x2d23f4 vldr s8, [r0, #148] */
/* @0x2d23f8 vmov.f32 s20, s16 */
/* @0x2d23fc vmls.f32 s20, s15, s13 */
/* @0x2d2400 vmov.f32 s15, s20 */
/* @0x2d2404 vcmpe.f32 s20, s19 */
/* @0x2d2408 vmrs APSR_nzcv, fpscr */
/* @0x2d240c vmovgt.f32 s15, s19 */
/* @0x2d2410 vstr s15, [r0, #92] */
/* @0x2d2414 vsub.f32 s15, s15, s16 */
/* @0x2d2418 vmul.f32 s14, s15, s14 */
/* @0x2d241c vmul.f32 s15, s15, s0 */
/* @0x2d2420 vmul.f32 s11, s11, s14 */
/* @0x2d2424 vmul.f32 s13, s1, s14 */
/* @0x2d2428 vnmls.f32 s11, s2, s15 */
/* @0x2d242c vnmls.f32 s13, s3, s15 */
/* @0x2d2430 vmls.f32 s10, s11, s18 */
/* @0x2d2434 vmla.f32 s12, s13, s17 */
/* @0x2d2438 vstr s10, [r2, #8] */
/* @0x2d243c vpop {d8, d9, d10} */
/* @0x2d2440 vmls.f32 s4, s6, s14 */
/* @0x2d2444 vmls.f32 s5, s6, s15 */
/* @0x2d2448 vstr s4, [r2] */
/* @0x2d244c vmla.f32 s7, s8, s14 */
/* @0x2d2450 vstr s5, [r2, #4] */
/* @0x2d2454 vstr s12, [r3, #8] */
/* @0x2d2458 vmla.f32 s9, s8, s15 */
/* @0x2d245c vstr s7, [r3] */
/* @0x2d2460 vstr s9, [r3, #4] */
/* @0x2d2464 bx lr */
/* @0x2d2468 andeq r0, r0, r0 */

/* ── FUNC 0x2d246c · b2RopeJoint::GetAnchorA() const · size=64 · insn=16 */
/* @0x2d246c ldr r3, [r1, #0x30] */
/* @0x2d2470 vldr s15, [r1, #72] */
/* @0x2d2474 vldr s12, [r3, #24] */
/* @0x2d2478 vldr s11, [r3, #20] */
/* @0x2d247c vmul.f32 s14, s12, s15 */
/* @0x2d2480 vldr s13, [r1, #68] */
/* @0x2d2484 vldr s9, [r3, #16] */
/* @0x2d2488 vldr s10, [r3, #12] */
/* @0x2d248c vmul.f32 s15, s11, s15 */
/* @0x2d2490 vmla.f32 s14, s13, s11 */
/* @0x2d2494 vnmls.f32 s15, s12, s13 */
/* @0x2d2498 vadd.f32 s14, s14, s9 */
/* @0x2d249c vadd.f32 s15, s15, s10 */
/* @0x2d24a0 vstr s14, [r0, #4] */
/* @0x2d24a4 vstr s15, [r0] */
/* @0x2d24a8 bx lr */

/* ── FUNC 0x2d24ac · b2RopeJoint::GetAnchorB() const · size=64 · insn=16 */
/* @0x2d24ac ldr r3, [r1, #0x34] */
/* @0x2d24b0 vldr s15, [r1, #80] */
/* @0x2d24b4 vldr s12, [r3, #24] */
/* @0x2d24b8 vldr s11, [r3, #20] */
/* @0x2d24bc vmul.f32 s14, s12, s15 */
/* @0x2d24c0 vldr s13, [r1, #76] */
/* @0x2d24c4 vldr s9, [r3, #16] */
/* @0x2d24c8 vldr s10, [r3, #12] */
/* @0x2d24cc vmul.f32 s15, s11, s15 */
/* @0x2d24d0 vmla.f32 s14, s13, s11 */
/* @0x2d24d4 vnmls.f32 s15, s12, s13 */
/* @0x2d24d8 vadd.f32 s14, s14, s9 */
/* @0x2d24dc vadd.f32 s15, s15, s10 */
/* @0x2d24e0 vstr s14, [r0, #4] */
/* @0x2d24e4 vstr s15, [r0] */
/* @0x2d24e8 bx lr */

/* ── FUNC 0x2d24ec · b2RopeJoint::GetReactionForce(float) const · size=40 · insn=10 */
/* @0x2d24ec vmov s14, r2 */
/* @0x2d24f0 vldr s15, [r1, #92] */
/* @0x2d24f4 vldr s13, [r1, #104] */
/* @0x2d24f8 vmul.f32 s15, s14, s15 */
/* @0x2d24fc vldr s14, [r1, #108] */
/* @0x2d2500 vmul.f32 s14, s15, s14 */
/* @0x2d2504 vmul.f32 s15, s15, s13 */
/* @0x2d2508 vstr s14, [r0, #4] */
/* @0x2d250c vstr s15, [r0] */
/* @0x2d2510 bx lr */

/* ── FUNC 0x2d2514 · b2RopeJoint::GetReactionTorque(float) const · size=8 · insn=2 */
/* @0x2d2514 mov r0, #0 */
/* @0x2d2518 bx lr */

/* ── FUNC 0x2d251c · b2RopeJoint::~b2RopeJoint() · size=24 · insn=6 */
/* @0x2d251c ldr r3, [pc, #0xc] */
/* @0x2d2520 ldr r3, [pc, r3] */
/* @0x2d2524 add r3, r3, #8 */
/* @0x2d2528 str r3, [r0] */
/* @0x2d252c bx lr */
/* @0x2d2530 andseq pc, r1, r4, lsr r6 */

/* ── FUNC 0x2d251c · b2RopeJoint::~b2RopeJoint() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2d2534 · b2RopeJoint::Dump() · size=240 · insn=60 */
/* @0x2d2534 push {r4, r5, r6, lr} */
/* @0x2d2538 mov r4, r0 */
/* @0x2d253c ldr r2, [r4, #0x30] */
/* @0x2d2540 sub sp, sp, #8 */
/* @0x2d2544 ldr r3, [r4, #0x34] */
/* @0x2d2548 ldr r0, [pc, #0xb4] */
/* @0x2d254c ldr r6, [r2, #0x8] */
/* @0x2d2550 add r0, pc, r0 */
/* @0x2d2554 ldr r5, [r3, #0x8] */
/* @0x2d2558 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d255c ldr r0, [pc, #0xa4] */
/* @0x2d2560 mov r1, r6 */
/* @0x2d2564 add r0, pc, r0 */
/* @0x2d2568 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d256c ldr r0, [pc, #0x98] */
/* @0x2d2570 mov r1, r5 */
/* @0x2d2574 add r0, pc, r0 */
/* @0x2d2578 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d257c ldr r0, [pc, #0x8c] */
/* @0x2d2580 ldrb r1, [r4, #0x3d] */
/* @0x2d2584 add r0, pc, r0 */
/* @0x2d2588 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d258c vldr s13, [r4, #68] */
/* @0x2d2590 vldr s14, [r4, #72] */
/* @0x2d2594 vcvt.f64.f32 d5, s13 */
/* @0x2d2598 ldr r0, [pc, #0x74] */
/* @0x2d259c add r0, pc, r0 */
/* @0x2d25a0 vcvt.f64.f32 d7, s14 */
/* @0x2d25a4 vmov r2, r3, d5 */
/* @0x2d25a8 vstr d7, [sp] */
/* @0x2d25ac bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d25b0 vldr s13, [r4, #76] */
/* @0x2d25b4 vldr s14, [r4, #80] */
/* @0x2d25b8 vcvt.f64.f32 d5, s13 */
/* @0x2d25bc ldr r0, [pc, #0x54] */
/* @0x2d25c0 add r0, pc, r0 */
/* @0x2d25c4 vcvt.f64.f32 d7, s14 */
/* @0x2d25c8 vmov r2, r3, d5 */
/* @0x2d25cc vstr d7, [sp] */
/* @0x2d25d0 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d25d4 vldr s15, [r4, #84] */
/* @0x2d25d8 vcvt.f64.f32 d6, s15 */
/* @0x2d25dc ldr r0, [pc, #0x38] */
/* @0x2d25e0 add r0, pc, r0 */
/* @0x2d25e4 vmov r2, r3, d6 */
/* @0x2d25e8 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d25ec ldr r0, [pc, #0x2c] */
/* @0x2d25f0 ldr r1, [r4, #0x38] */
/* @0x2d25f4 add r0, pc, r0 */
/* @0x2d25f8 add sp, sp, #8 */
/* @0x2d25fc pop {r4, r5, r6, lr} */
/* @0x2d2600 b 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d2604 strdeq r9, r10, [r8], -r4 */
/* @0x2d2608 andeq r9, r8, r8, asr #18 */
/* @0x2d260c andeq r9, r8, r4, asr r9 */
/* @0x2d2610 andeq r9, r8, r0, ror #18 */
/* @0x2d2614 andeq r9, r8, r12, ror #18 */
/* @0x2d2618 andeq r9, r8, r4, ror r9 */
/* @0x2d261c andeq r9, r8, r12, ror sp */
/* @0x2d2620 andeq r9, r8, r4, asr #19 */

/* ── FUNC 0x2d2624 · b2RopeJoint::~b2RopeJoint() · size=40 · insn=10 */
/* @0x2d2624 ldr r3, [pc, #0x1c] */
/* @0x2d2628 push {r4, lr} */
/* @0x2d262c ldr r3, [pc, r3] */
/* @0x2d2630 mov r4, r0 */
/* @0x2d2634 add r3, r3, #8 */
/* @0x2d2638 str r3, [r0] */
/* @0x2d263c bl 0x27d1d0 <_ZdlPv> */
/* @0x2d2640 mov r0, r4 */
/* @0x2d2644 pop {r4, pc} */
/* @0x2d2648 andseq pc, r1, r8, lsr #10 */

/* ── FUNC 0x2d264c · b2RopeJoint::SolvePositionConstraints(b2SolverData const&) · size=504 · insn=126 */
/* @0x2d264c push {r4, r5, r6, r7, r8, lr} */
/* @0x2d2650 vpush {d8, d9, d10, d11, d12, d13} */
/* @0x2d2654 mov r4, r0 */
/* @0x2d2658 ldr r7, [r0, #0x60] */
/* @0x2d265c mov r8, r1 */
/* @0x2d2660 ldr r6, [r0, #0x64] */
/* @0x2d2664 ldr r5, [r1, #0x18] */
/* @0x2d2668 add r2, r7, r7, lsl #1 */
/* @0x2d266c add r3, r6, r6, lsl #1 */
/* @0x2d2670 add r2, r5, r2, lsl #2 */
/* @0x2d2674 vldr s23, [r2, #8] */
/* @0x2d2678 vmov r0, s23 */
/* @0x2d267c add r3, r5, r3, lsl #2 */
/* @0x2d2680 vldr s27, [r2] */
/* @0x2d2684 vldr s22, [r3, #8] */
/* @0x2d2688 vldr s26, [r2, #4] */
/* @0x2d268c vldr s25, [r3] */
/* @0x2d2690 vldr s24, [r3, #4] */
/* @0x2d2694 bl 0xb6580 <sinf@plt> */
/* @0x2d2698 vmov s16, r0 */
/* @0x2d269c vmov r0, s23 */
/* @0x2d26a0 bl 0xb658c <cosf@plt> */
/* @0x2d26a4 vmov s17, r0 */
/* @0x2d26a8 vmov r0, s22 */
/* @0x2d26ac bl 0xb6580 <sinf@plt> */
/* @0x2d26b0 vmov s21, r0 */
/* @0x2d26b4 vmov r0, s22 */
/* @0x2d26b8 bl 0xb658c <cosf@plt> */
/* @0x2d26bc vldr s15, [r4, #140] */
/* @0x2d26c0 vldr s18, [r4, #80] */
/* @0x2d26c4 vsub.f32 s18, s18, s15 */
/* @0x2d26c8 vldr s10, [r4, #76] */
/* @0x2d26cc vldr s13, [r4, #136] */
/* @0x2d26d0 vldr s19, [r4, #72] */
/* @0x2d26d4 vldr s11, [r4, #132] */
/* @0x2d26d8 vldr s12, [r4, #68] */
/* @0x2d26dc vldr s15, [r4, #128] */
/* @0x2d26e0 vsub.f32 s13, s10, s13 */
/* @0x2d26e4 vsub.f32 s19, s19, s11 */
/* @0x2d26e8 vsub.f32 s15, s12, s15 */
/* @0x2d26ec vmov s14, r0 */
/* @0x2d26f0 vmul.f32 s20, s18, s14 */
/* @0x2d26f4 vmul.f32 s18, s18, s21 */
/* @0x2d26f8 vmla.f32 s20, s13, s21 */
/* @0x2d26fc vmul.f32 s21, s19, s17 */
/* @0x2d2700 vnmls.f32 s18, s13, s14 */
/* @0x2d2704 vmla.f32 s21, s15, s16 */
/* @0x2d2708 vmul.f32 s19, s19, s16 */
/* @0x2d270c vadd.f32 s16, s24, s20 */
/* @0x2d2710 vsub.f32 s16, s16, s26 */
/* @0x2d2714 vnmls.f32 s19, s15, s17 */
/* @0x2d2718 vadd.f32 s17, s25, s18 */
/* @0x2d271c vsub.f32 s16, s16, s21 */
/* @0x2d2720 vsub.f32 s17, s17, s27 */
/* @0x2d2724 vmul.f32 s14, s16, s16 */
/* @0x2d2728 vsub.f32 s17, s17, s19 */
/* @0x2d272c vmla.f32 s14, s17, s17 */
/* @0x2d2730 vsqrt.f32 s15, s14 */
/* @0x2d2734 vcmp.f32 s15, s15 */
/* @0x2d2738 vmrs APSR_nzcv, fpscr */
/* @0x2d273c bne 0x2d2818 <_ZN11b2RopeJoint24SolvePositionConstraintsERK12b2SolverData+0x1cc> */
/* @0x2d2740 vldr s14, [pc, #236] */
/* @0x2d2744 vcmpe.f32 s15, s14 */
/* @0x2d2748 vldr s12, [pc, #232] */
/* @0x2d274c vmrs APSR_nzcv, fpscr */
/* @0x2d2750 vmovpl.f32 s13, #1.000000e+00 */
/* @0x2d2754 vldrmi s14, [pc, #224] */
/* @0x2d2758 vmovpl.f32 s14, s15 */
/* @0x2d275c vdivpl.f32 s15, s13, s15 */
/* @0x2d2760 vmulpl.f32 s17, s17, s15 */
/* @0x2d2764 vmulpl.f32 s16, s16, s15 */
/* @0x2d2768 vldr s15, [r4, #84] */
/* @0x2d276c vsub.f32 s15, s14, s15 */
/* @0x2d2770 vcmpe.f32 s15, s12 */
/* @0x2d2774 vmrs APSR_nzcv, fpscr */
/* @0x2d2778 bpl 0x2d278c <_ZN11b2RopeJoint24SolvePositionConstraintsERK12b2SolverData+0x140> */
/* @0x2d277c vcmpe.f32 s15, #0 */
/* @0x2d2780 vmrs APSR_nzcv, fpscr */
/* @0x2d2784 vmovpl.f32 s12, s15 */
/* @0x2d2788 vldrmi s12, [pc, #172] */
/* @0x2d278c vldr s14, [r4, #160] */
/* @0x2d2790 vldr s13, [r4, #144] */
/* @0x2d2794 vnmul.f32 s12, s14, s12 */
/* @0x2d2798 vldr s9, [r4, #152] */
/* @0x2d279c vldr s14, [r4, #148] */
/* @0x2d27a0 vldr s10, [r4, #156] */
/* @0x2d27a4 add r7, r7, r7, lsl #1 */
/* @0x2d27a8 add r6, r6, r6, lsl #1 */
/* @0x2d27ac vldr s11, [pc, #140] */
/* @0x2d27b0 add r7, r5, r7, lsl #2 */
/* @0x2d27b4 add r5, r5, r6, lsl #2 */
/* @0x2d27b8 vmul.f32 s17, s12, s17 */
/* @0x2d27bc vmul.f32 s16, s12, s16 */
/* @0x2d27c0 vmul.f32 s21, s21, s17 */
/* @0x2d27c4 vmul.f32 s20, s20, s17 */
/* @0x2d27c8 vnmls.f32 s21, s19, s16 */
/* @0x2d27cc vnmls.f32 s20, s18, s16 */
/* @0x2d27d0 vmls.f32 s27, s13, s17 */
/* @0x2d27d4 vmls.f32 s26, s13, s16 */
/* @0x2d27d8 vstr s27, [r7] */
/* @0x2d27dc vmls.f32 s23, s21, s9 */
/* @0x2d27e0 vstr s26, [r7, #4] */
/* @0x2d27e4 vmla.f32 s25, s14, s17 */
/* @0x2d27e8 vstr s23, [r7, #8] */
/* @0x2d27ec vmla.f32 s24, s14, s16 */
/* @0x2d27f0 vstr s25, [r5] */
/* @0x2d27f4 vmla.f32 s22, s20, s10 */
/* @0x2d27f8 vstr s24, [r5, #4] */
/* @0x2d27fc vstr s22, [r5, #8] */
/* @0x2d2800 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x2d2804 vcmpe.f32 s15, s11 */
/* @0x2d2808 vmrs APSR_nzcv, fpscr */
/* @0x2d280c movpl r0, #0 */
/* @0x2d2810 movmi r0, #1 */
/* @0x2d2814 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2d2818 vmov r0, s14 */
/* @0x2d281c bl 0xb6700 <sqrtf@plt> */
/* @0x2d2820 ldr r5, [r8, #0x18] */
/* @0x2d2824 ldr r7, [r4, #0x60] */
/* @0x2d2828 ldr r6, [r4, #0x64] */
/* @0x2d282c vmov s15, r0 */
/* @0x2d2830 b 0x2d2740 <_ZN11b2RopeJoint24SolvePositionConstraintsERK12b2SolverData+0xf4> */
/* @0x2d2834 strlo r0, [r0], #-0 */
/* @0x2d2838 cdplo p12, #0x4, c12, c12, c13, #0x6 */
/* @0x2d283c andeq r0, r0, r0 */
/* @0x2d2840 bllo 0xfebc8470 <b2_toiTime+0xfffffffffe46efcc> */

/* ── FUNC 0x2d2844 · b2RopeJoint::InitVelocityConstraints(b2SolverData const&) · size=772 · insn=193 */
/* @0x2d2844 ldr r2, [r0, #0x30] */
/* @0x2d2848 vldr s15, [r2, #136] */
/* @0x2d284c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2d2850 vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2d2854 mov r5, r1 */
/* @0x2d2858 ldr r3, [r0, #0x34] */
/* @0x2d285c add r1, r2, #44 */
/* @0x2d2860 ldr lr, [r2, #0x8] */
/* @0x2d2864 mov r4, r0 */
/* @0x2d2868 ldr r7, [r5, #0x18] */
/* @0x2d286c add r10, r0, #128 */
/* @0x2d2870 ldr r12, [r3, #0x8] */
/* @0x2d2874 add r6, r0, #136 */
/* @0x2d2878 ldr r11, [r2, #0x90] */
/* @0x2d287c add r9, r3, #44 */
/* @0x2d2880 ldm r1, {r0, r1} */
/* @0x2d2884 str lr, [r4, #0x60] */
/* @0x2d2888 add lr, lr, lr, lsl #1 */
/* @0x2d288c ldr r8, [r5, #0x1c] */
/* @0x2d2890 lsl lr, lr, #2 */
/* @0x2d2894 str r12, [r4, #0x64] */
/* @0x2d2898 add r12, r12, r12, lsl #1 */
/* @0x2d289c add r2, r7, lr */
/* @0x2d28a0 stm r10, {r0, r1} */
/* @0x2d28a4 add lr, r8, lr */
/* @0x2d28a8 lsl r12, r12, #2 */
/* @0x2d28ac ldm r9, {r0, r1} */
/* @0x2d28b0 ldr r10, [r3, #0x88] */
/* @0x2d28b4 vldr s24, [r2] */
/* @0x2d28b8 ldr r9, [r3, #0x90] */
/* @0x2d28bc add r3, r7, r12 */
/* @0x2d28c0 ldr r7, [r2, #0x8] */
/* @0x2d28c4 add r12, r8, r12 */
/* @0x2d28c8 stm r6, {r0, r1} */
/* @0x2d28cc vstr s15, [r4, #144] */
/* @0x2d28d0 str r11, [r4, #0x98] */
/* @0x2d28d4 vldr s26, [r2, #4] */
/* @0x2d28d8 str r10, [r4, #0x94] */
/* @0x2d28dc mov r0, r7 */
/* @0x2d28e0 str r9, [r4, #0x9c] */
/* @0x2d28e4 vldr s25, [r3] */
/* @0x2d28e8 ldr r6, [r3, #0x8] */
/* @0x2d28ec vldr s27, [r3, #4] */
/* @0x2d28f0 vldr s21, [lr] */
/* @0x2d28f4 vldr s20, [lr, #4] */
/* @0x2d28f8 vldr s19, [lr, #8] */
/* @0x2d28fc vldr s18, [r12] */
/* @0x2d2900 vldr s17, [r12, #4] */
/* @0x2d2904 vldr s16, [r12, #8] */
/* @0x2d2908 bl 0xb6580 <sinf@plt> */
/* @0x2d290c vmov s22, r0 */
/* @0x2d2910 mov r0, r7 */
/* @0x2d2914 bl 0xb658c <cosf@plt> */
/* @0x2d2918 vmov s23, r0 */
/* @0x2d291c mov r0, r6 */
/* @0x2d2920 bl 0xb6580 <sinf@plt> */
/* @0x2d2924 vmov s28, r0 */
/* @0x2d2928 mov r0, r6 */
/* @0x2d292c bl 0xb658c <cosf@plt> */
/* @0x2d2930 vldr s15, [r4, #132] */
/* @0x2d2934 vldr s14, [r4, #72] */
/* @0x2d2938 vsub.f32 s14, s14, s15 */
/* @0x2d293c vldr s13, [r4, #128] */
/* @0x2d2940 vldr s11, [r4, #68] */
/* @0x2d2944 vmul.f32 s15, s14, s22 */
/* @0x2d2948 vsub.f32 s11, s11, s13 */
/* @0x2d294c vmov s10, r0 */
/* @0x2d2950 vnmls.f32 s15, s11, s23 */
/* @0x2d2954 vstr s15, [r4, #112] */
/* @0x2d2958 vldr s12, [r4, #80] */
/* @0x2d295c vldr s13, [r4, #140] */
/* @0x2d2960 vsub.f32 s13, s12, s13 */
/* @0x2d2964 vldr s8, [r4, #76] */
/* @0x2d2968 vldr s9, [r4, #136] */
/* @0x2d296c vmul.f32 s12, s13, s10 */
/* @0x2d2970 vsub.f32 s9, s8, s9 */
/* @0x2d2974 vmul.f32 s13, s13, s28 */
/* @0x2d2978 vmla.f32 s12, s9, s28 */
/* @0x2d297c vmul.f32 s14, s14, s23 */
/* @0x2d2980 vstr s12, [r4, #124] */
/* @0x2d2984 vnmls.f32 s13, s9, s10 */
/* @0x2d2988 vmla.f32 s14, s11, s22 */
/* @0x2d298c vstr s13, [r4, #120] */
/* @0x2d2990 vadd.f32 s12, s12, s27 */
/* @0x2d2994 vstr s14, [r4, #116] */
/* @0x2d2998 vsub.f32 s26, s12, s26 */
/* @0x2d299c vadd.f32 s13, s13, s25 */
/* @0x2d29a0 vsub.f32 s14, s26, s14 */
/* @0x2d29a4 vsub.f32 s24, s13, s24 */
/* @0x2d29a8 vstr s14, [r4, #108] */
/* @0x2d29ac vmul.f32 s14, s14, s14 */
/* @0x2d29b0 vsub.f32 s15, s24, s15 */
/* @0x2d29b4 vmla.f32 s14, s15, s15 */
/* @0x2d29b8 vstr s15, [r4, #104] */
/* @0x2d29bc vsqrt.f32 s15, s14 */
/* @0x2d29c0 vcmp.f32 s15, s15 */
/* @0x2d29c4 vmrs APSR_nzcv, fpscr */
/* @0x2d29c8 bne 0x2d2b30 <_ZN11b2RopeJoint23InitVelocityConstraintsERK12b2SolverData+0x2ec> */
/* @0x2d29cc vldr s14, [r4, #84] */
/* @0x2d29d0 vsub.f32 s14, s15, s14 */
/* @0x2d29d4 vstr s15, [r4, #88] */
/* @0x2d29d8 vcmpe.f32 s14, #0 */
/* @0x2d29dc vldr s14, [pc, #348] */
/* @0x2d29e0 vmrs APSR_nzcv, fpscr */
/* @0x2d29e4 vcmpe.f32 s15, s14 */
/* @0x2d29e8 movgt r3, #2 */
/* @0x2d29ec movle r3, #0 */
/* @0x2d29f0 str r3, [r4, #0xa4] */
/* @0x2d29f4 vmrs APSR_nzcv, fpscr */
/* @0x2d29f8 ble 0x2d2b14 <_ZN11b2RopeJoint23InitVelocityConstraintsERK12b2SolverData+0x2d0> */
/* @0x2d29fc vmov.f32 s3, #1.000000e+00 */
/* @0x2d2a00 vldr s12, [r4, #104] */
/* @0x2d2a04 vldr s14, [r4, #108] */
/* @0x2d2a08 vldr s4, [r4, #116] */
/* @0x2d2a0c vldr s6, [r4, #112] */
/* @0x2d2a10 vldr s5, [r4, #124] */
/* @0x2d2a14 vldr s8, [r4, #152] */
/* @0x2d2a18 vldr s10, [r4, #144] */
/* @0x2d2a1c vldr s7, [r4, #120] */
/* @0x2d2a20 vldr s9, [r4, #156] */
/* @0x2d2a24 vldr s11, [r4, #148] */
/* @0x2d2a28 vdiv.f32 s15, s3, s15 */
/* @0x2d2a2c vmul.f32 s12, s15, s12 */
/* @0x2d2a30 vmul.f32 s15, s15, s14 */
/* @0x2d2a34 vstr s12, [r4, #104] */
/* @0x2d2a38 vmul.f32 s13, s12, s4 */
/* @0x2d2a3c vstr s15, [r4, #108] */
/* @0x2d2a40 vnmls.f32 s13, s15, s6 */
/* @0x2d2a44 vmul.f32 s14, s12, s5 */
/* @0x2d2a48 vmul.f32 s2, s8, s13 */
/* @0x2d2a4c vmov.f32 s1, s10 */
/* @0x2d2a50 vnmls.f32 s14, s15, s7 */
/* @0x2d2a54 vmla.f32 s1, s2, s13 */
/* @0x2d2a58 vmul.f32 s2, s9, s14 */
/* @0x2d2a5c vadd.f32 s13, s1, s11 */
/* @0x2d2a60 vmla.f32 s13, s2, s14 */
/* @0x2d2a64 vcmp.f32 s13, #0 */
/* @0x2d2a68 vmrs APSR_nzcv, fpscr */
/* @0x2d2a6c vdivne.f32 s13, s3, s13 */
/* @0x2d2a70 beq 0x2d2b0c <_ZN11b2RopeJoint23InitVelocityConstraintsERK12b2SolverData+0x2c8> */
/* @0x2d2a74 ldrb r3, [r5, #0x14] */
/* @0x2d2a78 vstr s13, [r4, #160] */
/* @0x2d2a7c cmp r3, #0 */
/* @0x2d2a80 moveq r3, #0 */
/* @0x2d2a84 streq r3, [r4, #0x5c] */
/* @0x2d2a88 bne 0x2d2ac8 <_ZN11b2RopeJoint23InitVelocityConstraintsERK12b2SolverData+0x284> */
/* @0x2d2a8c ldr r2, [r4, #0x60] */
/* @0x2d2a90 ldr r3, [r4, #0x64] */
/* @0x2d2a94 ldr r1, [r5, #0x1c] */
/* @0x2d2a98 add r2, r2, r2, lsl #1 */
/* @0x2d2a9c add r3, r3, r3, lsl #1 */
/* @0x2d2aa0 add r2, r1, r2, lsl #2 */
/* @0x2d2aa4 vstr s21, [r2] */
/* @0x2d2aa8 vstr s20, [r2, #4] */
/* @0x2d2aac vstr s19, [r2, #8] */
/* @0x2d2ab0 add r3, r1, r3, lsl #2 */
/* @0x2d2ab4 vstr s18, [r3] */
/* @0x2d2ab8 vstr s17, [r3, #4] */
/* @0x2d2abc vstr s16, [r3, #8] */
/* @0x2d2ac0 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2d2ac4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2d2ac8 vldr s13, [r4, #92] */
/* @0x2d2acc vldr s14, [r5, #8] */
/* @0x2d2ad0 vmul.f32 s14, s13, s14 */
/* @0x2d2ad4 vmul.f32 s12, s14, s12 */
/* @0x2d2ad8 vstr s14, [r4, #92] */
/* @0x2d2adc vmul.f32 s15, s14, s15 */
/* @0x2d2ae0 vmul.f32 s4, s4, s12 */
/* @0x2d2ae4 vmul.f32 s5, s5, s12 */
/* @0x2d2ae8 vnmls.f32 s4, s6, s15 */
/* @0x2d2aec vnmls.f32 s5, s7, s15 */
/* @0x2d2af0 vmls.f32 s19, s8, s4 */
/* @0x2d2af4 vmla.f32 s16, s9, s5 */
/* @0x2d2af8 vmls.f32 s21, s10, s12 */
/* @0x2d2afc vmls.f32 s20, s10, s15 */
/* @0x2d2b00 vmla.f32 s18, s11, s12 */
/* @0x2d2b04 vmla.f32 s17, s11, s15 */
/* @0x2d2b08 b 0x2d2a8c <_ZN11b2RopeJoint23InitVelocityConstraintsERK12b2SolverData+0x248> */
/* @0x2d2b0c vldr s13, [pc, #48] */
/* @0x2d2b10 b 0x2d2a74 <_ZN11b2RopeJoint23InitVelocityConstraintsERK12b2SolverData+0x230> */
/* @0x2d2b14 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2d2b18 mov r3, #0 */
/* @0x2d2b1c str r3, [r4, #0x68] */
/* @0x2d2b20 str r3, [r4, #0x6c] */
/* @0x2d2b24 str r3, [r4, #0xa0] */
/* @0x2d2b28 str r3, [r4, #0x5c] */
/* @0x2d2b2c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2d2b30 vmov r0, s14 */
/* @0x2d2b34 bl 0xb6700 <sqrtf@plt> */
/* @0x2d2b38 vmov s15, r0 */
/* @0x2d2b3c b 0x2d29cc <_ZN11b2RopeJoint23InitVelocityConstraintsERK12b2SolverData+0x188> */
/* @0x2d2b40 bllo 0xfebc8770 <b2_toiTime+0xfffffffffe46f2cc> */
/* @0x2d2b44 andeq r0, r0, r0 */

/* ── FUNC 0x2d2b48 · b2RopeJoint::b2RopeJoint(b2RopeJointDef const*) · size=108 · insn=27 */
/* @0x2d2b48 push {r4, r5, r6, lr} */
/* @0x2d2b4c mov r4, r0 */
/* @0x2d2b50 mov r5, r1 */
/* @0x2d2b54 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef> */
/* @0x2d2b58 add r3, r5, #20 */
/* @0x2d2b5c ldr r2, [pc, #0x4c] */
/* @0x2d2b60 add r6, r5, #28 */
/* @0x2d2b64 ldr r5, [r5, #0x24] */
/* @0x2d2b68 ldm r3, {r0, r1} */
/* @0x2d2b6c ldr r2, [pc, r2] */
/* @0x2d2b70 mov r3, r4 */
/* @0x2d2b74 add r2, r2, #8 */
/* @0x2d2b78 str r2, [r3], #68 */
/* @0x2d2b7c add r12, r4, #76 */
/* @0x2d2b80 stm r3, {r0, r1} */
/* @0x2d2b84 mov r2, #0 */
/* @0x2d2b88 ldm r6, {r0, r1} */
/* @0x2d2b8c mov r3, #0 */
/* @0x2d2b90 stm r12, {r0, r1} */
/* @0x2d2b94 mov r0, r4 */
/* @0x2d2b98 str r5, [r4, #0x54] */
/* @0x2d2b9c str r2, [r4, #0xa4] */
/* @0x2d2ba0 str r3, [r4, #0xa0] */
/* @0x2d2ba4 str r3, [r4, #0x5c] */
/* @0x2d2ba8 str r3, [r4, #0x58] */
/* @0x2d2bac pop {r4, r5, r6, pc} */
/* @0x2d2bb0 andseq pc, r1, r8 */

/* ── FUNC 0x2d2b48 · b2RopeJoint::b2RopeJoint(b2RopeJointDef const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2d2bb4 · b2RopeJoint::GetMaxLength() const · size=8 · insn=2 */
/* @0x2d2bb4 ldr r0, [r0, #0x54] */
/* @0x2d2bb8 bx lr */

/* ── FUNC 0x2d2bbc · b2RopeJoint::GetLimitState() const · size=8 · insn=2 */
/* @0x2d2bbc ldr r0, [r0, #0xa4] */
/* @0x2d2bc0 bx lr */

/* ── FUNC 0x2d2bc4 · b2WeldJoint::SolveVelocityConstraints(b2SolverData const&) · size=540 · insn=135 */
/* @0x2d2bc4 ldr r2, [r0, #0x74] */
/* @0x2d2bc8 vldr s15, [r0, #68] */
/* @0x2d2bcc ldr r12, [r0, #0x78] */
/* @0x2d2bd0 vcmpe.f32 s15, #0 */
/* @0x2d2bd4 ldr r1, [r1, #0x1c] */
/* @0x2d2bd8 vpush {d8, d9, d10, d11, d12, d13} */
/* @0x2d2bdc add r2, r2, r2, lsl #1 */
/* @0x2d2be0 vldr s7, [r0, #156] */
/* @0x2d2be4 add r12, r12, r12, lsl #1 */
/* @0x2d2be8 vldr s8, [r0, #160] */
/* @0x2d2bec add r2, r1, r2, lsl #2 */
/* @0x2d2bf0 vldr s2, [r0, #164] */
/* @0x2d2bf4 add r3, r1, r12, lsl #2 */
/* @0x2d2bf8 vmrs APSR_nzcv, fpscr */
/* @0x2d2bfc vldr s3, [r0, #168] */
/* @0x2d2c00 vldr s4, [r2] */
/* @0x2d2c04 vldr s6, [r2, #4] */
/* @0x2d2c08 vldr s14, [r2, #8] */
/* @0x2d2c0c vldr s5, [r3] */
/* @0x2d2c10 vldr s9, [r3, #4] */
/* @0x2d2c14 vldr s15, [r3, #8] */
/* @0x2d2c18 ble 0x2d2d04 <_ZN11b2WeldJoint24SolveVelocityConstraintsERK12b2SolverData+0x140> */
/* @0x2d2c1c vsub.f32 s24, s15, s14 */
/* @0x2d2c20 vldr s13, [r0, #76] */
/* @0x2d2c24 vldr s17, [r0, #112] */
/* @0x2d2c28 vldr s12, [r0, #100] */
/* @0x2d2c2c vldr s16, [r0, #204] */
/* @0x2d2c30 vldr s18, [r0, #132] */
/* @0x2d2c34 vldr s1, [r0, #136] */
/* @0x2d2c38 vldr s19, [r0, #124] */
/* @0x2d2c3c vldr s0, [r0, #128] */
/* @0x2d2c40 vldr s10, [r0, #184] */
/* @0x2d2c44 vldr s23, [r0, #172] */
/* @0x2d2c48 vldr s11, [r0, #188] */
/* @0x2d2c4c vldr s22, [r0, #176] */
/* @0x2d2c50 vldr s21, [r0, #104] */
/* @0x2d2c54 vldr s20, [r0, #108] */
/* @0x2d2c58 vadd.f32 s13, s24, s13 */
/* @0x2d2c5c vmla.f32 s13, s17, s12 */
/* @0x2d2c60 vnmul.f32 s16, s16, s13 */
/* @0x2d2c64 vmla.f32 s15, s3, s16 */
/* @0x2d2c68 vmov.f32 s12, s9 */
/* @0x2d2c6c vmla.f32 s12, s15, s18 */
/* @0x2d2c70 vmov.f32 s13, s5 */
/* @0x2d2c74 vmls.f32 s14, s2, s16 */
/* @0x2d2c78 vmls.f32 s13, s15, s1 */
/* @0x2d2c7c vsub.f32 s12, s12, s6 */
/* @0x2d2c80 vmls.f32 s12, s14, s19 */
/* @0x2d2c84 vsub.f32 s13, s13, s4 */
/* @0x2d2c88 vmla.f32 s13, s14, s0 */
/* @0x2d2c8c vmul.f32 s10, s12, s10 */
/* @0x2d2c90 vmul.f32 s11, s12, s11 */
/* @0x2d2c94 vmla.f32 s10, s13, s23 */
/* @0x2d2c98 vmla.f32 s11, s13, s22 */
/* @0x2d2c9c vneg.f32 s12, s10 */
/* @0x2d2ca0 vmul.f32 s0, s0, s12 */
/* @0x2d2ca4 vmul.f32 s1, s1, s12 */
/* @0x2d2ca8 vneg.f32 s13, s11 */
/* @0x2d2cac vnmls.f32 s0, s19, s13 */
/* @0x2d2cb0 vnmls.f32 s1, s18, s13 */
/* @0x2d2cb4 vmls.f32 s4, s7, s12 */
/* @0x2d2cb8 vmla.f32 s5, s8, s12 */
/* @0x2d2cbc vmls.f32 s14, s2, s0 */
/* @0x2d2cc0 vmla.f32 s15, s3, s1 */
/* @0x2d2cc4 vmls.f32 s6, s7, s13 */
/* @0x2d2cc8 vmla.f32 s9, s8, s13 */
/* @0x2d2ccc vadd.f32 s16, s17, s16 */
/* @0x2d2cd0 vsub.f32 s10, s21, s10 */
/* @0x2d2cd4 vstr s16, [r0, #112] */
/* @0x2d2cd8 vsub.f32 s11, s20, s11 */
/* @0x2d2cdc vstr s10, [r0, #104] */
/* @0x2d2ce0 vstr s11, [r0, #108] */
/* @0x2d2ce4 vstr s4, [r2] */
/* @0x2d2ce8 vstr s6, [r2, #4] */
/* @0x2d2cec vstr s14, [r2, #8] */
/* @0x2d2cf0 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x2d2cf4 vstr s5, [r3] */
/* @0x2d2cf8 vstr s9, [r3, #4] */
/* @0x2d2cfc vstr s15, [r3, #8] */
/* @0x2d2d00 bx lr */
/* @0x2d2d04 vmov.f32 s1, s9 */
/* @0x2d2d08 vldr s19, [r0, #132] */
/* @0x2d2d0c vldr s16, [r0, #136] */
/* @0x2d2d10 vldr s18, [r0, #124] */
/* @0x2d2d14 vldr s0, [r0, #128] */
/* @0x2d2d18 vldr s11, [r0, #184] */
/* @0x2d2d1c vldr s17, [r0, #172] */
/* @0x2d2d20 vldr s12, [r0, #188] */
/* @0x2d2d24 vmla.f32 s1, s15, s19 */
/* @0x2d2d28 vldr s27, [r0, #176] */
/* @0x2d2d2c vldr s26, [r0, #196] */
/* @0x2d2d30 vldr s13, [r0, #192] */
/* @0x2d2d34 vldr s25, [r0, #200] */
/* @0x2d2d38 vldr s24, [r0, #180] */
/* @0x2d2d3c vldr s23, [r0, #204] */
/* @0x2d2d40 vldr s22, [r0, #104] */
/* @0x2d2d44 vldr s21, [r0, #108] */
/* @0x2d2d48 vldr s20, [r0, #112] */
/* @0x2d2d4c vmov.f32 s10, s5 */
/* @0x2d2d50 vmls.f32 s10, s15, s16 */
/* @0x2d2d54 vsub.f32 s1, s1, s6 */
/* @0x2d2d58 vmls.f32 s1, s14, s18 */
/* @0x2d2d5c vsub.f32 s10, s10, s4 */
/* @0x2d2d60 vmla.f32 s10, s14, s0 */
/* @0x2d2d64 vmul.f32 s11, s1, s11 */
/* @0x2d2d68 vmul.f32 s12, s1, s12 */
/* @0x2d2d6c vmla.f32 s11, s10, s17 */
/* @0x2d2d70 vsub.f32 s17, s15, s14 */
/* @0x2d2d74 vmla.f32 s12, s10, s27 */
/* @0x2d2d78 vmla.f32 s11, s17, s26 */
/* @0x2d2d7c vmul.f32 s13, s1, s13 */
/* @0x2d2d80 vmla.f32 s12, s17, s25 */
/* @0x2d2d84 vmla.f32 s13, s10, s24 */
/* @0x2d2d88 vneg.f32 s1, s11 */
/* @0x2d2d8c vmul.f32 s16, s16, s1 */
/* @0x2d2d90 vmul.f32 s0, s0, s1 */
/* @0x2d2d94 vneg.f32 s10, s12 */
/* @0x2d2d98 vmla.f32 s13, s17, s23 */
/* @0x2d2d9c vnmls.f32 s16, s19, s10 */
/* @0x2d2da0 vnmls.f32 s0, s18, s10 */
/* @0x2d2da4 vsub.f32 s16, s16, s13 */
/* @0x2d2da8 vsub.f32 s0, s0, s13 */
/* @0x2d2dac vsub.f32 s11, s22, s11 */
/* @0x2d2db0 vsub.f32 s12, s21, s12 */
/* @0x2d2db4 vstr s11, [r0, #104] */
/* @0x2d2db8 vsub.f32 s13, s20, s13 */
/* @0x2d2dbc vstr s12, [r0, #108] */
/* @0x2d2dc0 vmls.f32 s4, s7, s1 */
/* @0x2d2dc4 vstr s13, [r0, #112] */
/* @0x2d2dc8 vmla.f32 s5, s8, s1 */
/* @0x2d2dcc vmls.f32 s6, s7, s10 */
/* @0x2d2dd0 vmla.f32 s9, s8, s10 */
/* @0x2d2dd4 vmls.f32 s14, s0, s2 */
/* @0x2d2dd8 vmla.f32 s15, s16, s3 */
/* @0x2d2ddc b 0x2d2ce4 <_ZN11b2WeldJoint24SolveVelocityConstraintsERK12b2SolverData+0x120> */

/* ── FUNC 0x2d2de0 · b2WeldJoint::GetAnchorA() const · size=64 · insn=16 */
/* @0x2d2de0 ldr r3, [r1, #0x30] */
/* @0x2d2de4 vldr s15, [r1, #84] */
/* @0x2d2de8 vldr s12, [r3, #24] */
/* @0x2d2dec vldr s11, [r3, #20] */
/* @0x2d2df0 vmul.f32 s14, s12, s15 */
/* @0x2d2df4 vldr s13, [r1, #80] */
/* @0x2d2df8 vldr s9, [r3, #16] */
/* @0x2d2dfc vldr s10, [r3, #12] */
/* @0x2d2e00 vmul.f32 s15, s11, s15 */
/* @0x2d2e04 vmla.f32 s14, s13, s11 */
/* @0x2d2e08 vnmls.f32 s15, s12, s13 */
/* @0x2d2e0c vadd.f32 s14, s14, s9 */
/* @0x2d2e10 vadd.f32 s15, s15, s10 */
/* @0x2d2e14 vstr s14, [r0, #4] */
/* @0x2d2e18 vstr s15, [r0] */
/* @0x2d2e1c bx lr */

/* ── FUNC 0x2d2e20 · b2WeldJoint::GetAnchorB() const · size=64 · insn=16 */
/* @0x2d2e20 ldr r3, [r1, #0x34] */
/* @0x2d2e24 vldr s15, [r1, #92] */
/* @0x2d2e28 vldr s12, [r3, #24] */
/* @0x2d2e2c vldr s11, [r3, #20] */
/* @0x2d2e30 vmul.f32 s14, s12, s15 */
/* @0x2d2e34 vldr s13, [r1, #88] */
/* @0x2d2e38 vldr s9, [r3, #16] */
/* @0x2d2e3c vldr s10, [r3, #12] */
/* @0x2d2e40 vmul.f32 s15, s11, s15 */
/* @0x2d2e44 vmla.f32 s14, s13, s11 */
/* @0x2d2e48 vnmls.f32 s15, s12, s13 */
/* @0x2d2e4c vadd.f32 s14, s14, s9 */
/* @0x2d2e50 vadd.f32 s15, s15, s10 */
/* @0x2d2e54 vstr s14, [r0, #4] */
/* @0x2d2e58 vstr s15, [r0] */
/* @0x2d2e5c bx lr */

/* ── FUNC 0x2d2e60 · b2WeldJoint::GetReactionForce(float) const · size=32 · insn=8 */
/* @0x2d2e60 vmov s15, r2 */
/* @0x2d2e64 vldr s14, [r1, #108] */
/* @0x2d2e68 vldr s13, [r1, #104] */
/* @0x2d2e6c vmul.f32 s14, s15, s14 */
/* @0x2d2e70 vmul.f32 s15, s13, s15 */
/* @0x2d2e74 vstr s14, [r0, #4] */
/* @0x2d2e78 vstr s15, [r0] */
/* @0x2d2e7c bx lr */

/* ── FUNC 0x2d2e80 · b2WeldJoint::GetReactionTorque(float) const · size=20 · insn=5 */
/* @0x2d2e80 vmov s14, r1 */
/* @0x2d2e84 vldr s15, [r0, #112] */
/* @0x2d2e88 vmul.f32 s14, s14, s15 */
/* @0x2d2e8c vmov r0, s14 */
/* @0x2d2e90 bx lr */
