/* libyoyo.so 覆盖卡组 0285
 * 函数 0x2e2090..0x2e4dec，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2e2090 · b2ContactSolver::b2ContactSolver(b2ContactSolverDef*) · size=736 · insn=184 */
/* @0x2e2090 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e2094 mov lr, r1 */
/* @0x2e2098 mov r4, r0 */
/* @0x2e209c mov r5, r1 */
/* @0x2e20a0 mov r12, r0 */
/* @0x2e20a4 ldr r7, [r5, #0x28] */
/* @0x2e20a8 ldm lr!, {r0, r1, r2, r3} */
/* @0x2e20ac mov r8, #88 */
/* @0x2e20b0 ldr r6, [r5, #0x1c] */
/* @0x2e20b4 sub sp, sp, #20 */
/* @0x2e20b8 stm r12!, {r0, r1, r2, r3} */
/* @0x2e20bc ldm lr, {r0, r1} */
/* @0x2e20c0 stm r12, {r0, r1} */
/* @0x2e20c4 mov r0, r7 */
/* @0x2e20c8 mul r1, r8, r6 */
/* @0x2e20cc str r7, [r4, #0x20] */
/* @0x2e20d0 str r6, [r4, #0x30] */
/* @0x2e20d4 bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi> */
/* @0x2e20d8 ldr r3, [r4, #0x30] */
/* @0x2e20dc mov r1, #156 */
/* @0x2e20e0 mul r1, r1, r3 */
/* @0x2e20e4 str r0, [r4, #0x24] */
/* @0x2e20e8 ldr r0, [r4, #0x20] */
/* @0x2e20ec bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi> */
/* @0x2e20f0 ldr r2, [r4, #0x30] */
/* @0x2e20f4 ldr r1, [r5, #0x20] */
/* @0x2e20f8 ldr r3, [r5, #0x24] */
/* @0x2e20fc cmp r2, #0 */
/* @0x2e2100 str r2, [sp, #0x8] */
/* @0x2e2104 ldr r2, [r5, #0x18] */
/* @0x2e2108 str r1, [r4, #0x18] */
/* @0x2e210c str r3, [r4, #0x1c] */
/* @0x2e2110 str r2, [r4, #0x2c] */
/* @0x2e2114 str r0, [r4, #0x28] */
/* @0x2e2118 ble 0x2e2360 <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x2d0> */
/* @0x2e211c ldr r3, [r4, #0x24] */
/* @0x2e2120 vldr s15, [pc, #580] */
/* @0x2e2124 str r3, [sp, #0xc] */
/* @0x2e2128 mov r3, #0 */
/* @0x2e212c str r3, [sp] */
/* @0x2e2130 mov r3, r0 */
/* @0x2e2134 mov r0, #0 */
/* @0x2e2138 str r0, [sp, #0x4] */
/* @0x2e213c mov r5, r0 */
/* @0x2e2140 ldr r12, [r2, r5, lsl #2] */
/* @0x2e2144 vldr s14, [r12, #140] */
/* @0x2e2148 ldr r2, [sp, #0x4] */
/* @0x2e214c vldr s9, [r12, #136] */
/* @0x2e2150 ldr r0, [sp, #0xc] */
/* @0x2e2154 ldr r8, [r12, #0x30] */
/* @0x2e2158 add r3, r3, r2 */
/* @0x2e215c ldr r10, [r12, #0x34] */
/* @0x2e2160 ldr r1, [sp] */
/* @0x2e2164 ldr r9, [r8, #0x8] */
/* @0x2e2168 vldr s12, [r9, #136] */
/* @0x2e216c add r2, r0, r1 */
/* @0x2e2170 ldr r11, [r12, #0x90] */
/* @0x2e2174 ldr r1, [r10, #0x8] */
/* @0x2e2178 vldr s13, [r9, #144] */
/* @0x2e217c ldr r6, [r12, #0x7c] */
/* @0x2e2180 add r0, r9, #44 */
/* @0x2e2184 ldr r8, [r8, #0xc] */
/* @0x2e2188 vldr s10, [r8, #8] */
/* @0x2e218c ldr r9, [r9, #0x8] */
/* @0x2e2190 add r7, r2, #48 */
/* @0x2e2194 ldr r8, [r1, #0x8] */
/* @0x2e2198 cmp r6, #0 */
/* @0x2e219c ldr r10, [r10, #0xc] */
/* @0x2e21a0 vldr s11, [r10, #8] */
/* @0x2e21a4 str r11, [r3, #0x90] */
/* @0x2e21a8 add r10, r1, #44 */
/* @0x2e21ac ldr r11, [r1, #0x88] */
/* @0x2e21b0 vstr s14, [r3, #140] */
/* @0x2e21b4 str r9, [r3, #0x70] */
/* @0x2e21b8 vldr s14, [r1, #144] */
/* @0x2e21bc str r8, [r3, #0x74] */
/* @0x2e21c0 vstr s9, [r3, #136] */
/* @0x2e21c4 str r11, [r3, #0x7c] */
/* @0x2e21c8 vstr s12, [r3, #120] */
/* @0x2e21cc vstr s13, [r3, #128] */
/* @0x2e21d0 vstr s14, [r3, #132] */
/* @0x2e21d4 str r6, [r3, #0x94] */
/* @0x2e21d8 str r5, [r3, #0x98] */
/* @0x2e21dc vstr s15, [r3, #96] */
/* @0x2e21e0 ldm r0, {r0, r1} */
/* @0x2e21e4 vstr s15, [r3, #104] */
/* @0x2e21e8 vstr s15, [r3, #100] */
/* @0x2e21ec vstr s15, [r3, #108] */
/* @0x2e21f0 vstr s15, [r3, #80] */
/* @0x2e21f4 vstr s15, [r3, #88] */
/* @0x2e21f8 vstr s15, [r3, #84] */
/* @0x2e21fc vstr s15, [r3, #92] */
/* @0x2e2200 str r9, [r2, #0x20] */
/* @0x2e2204 vstr s12, [r2, #40] */
/* @0x2e2208 str r8, [r2, #0x24] */
/* @0x2e220c add r9, r12, #104 */
/* @0x2e2210 str r11, [r2, #0x2c] */
/* @0x2e2214 add r8, r2, #16 */
/* @0x2e2218 stm r7, {r0, r1} */
/* @0x2e221c add r7, r12, #112 */
/* @0x2e2220 ldm r10, {r0, r1} */
/* @0x2e2224 add r10, r2, #56 */
/* @0x2e2228 ldr r11, [r12, #0x78] */
/* @0x2e222c stm r10, {r0, r1} */
/* @0x2e2230 vstr s13, [r2, #64] */
/* @0x2e2234 ldm r9, {r0, r1} */
/* @0x2e2238 vstr s14, [r2, #68] */
/* @0x2e223c add r9, r2, #24 */
/* @0x2e2240 stm r8, {r0, r1} */
/* @0x2e2244 ldm r7, {r0, r1} */
/* @0x2e2248 stm r9, {r0, r1} */
/* @0x2e224c vstr s10, [r2, #76] */
/* @0x2e2250 vstr s11, [r2, #80] */
/* @0x2e2254 str r6, [r2, #0x54] */
/* @0x2e2258 str r11, [r2, #0x48] */
/* @0x2e225c ble 0x2e22c8 <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x238> */
/* @0x2e2260 ldrb r1, [r4, #0x14] */
/* @0x2e2264 add r8, r3, #8 */
/* @0x2e2268 lsl r6, r6, #3 */
/* @0x2e226c add r3, r3, #32 */
/* @0x2e2270 cmp r1, #0 */
/* @0x2e2274 mov r7, #0 */
/* @0x2e2278 bne 0x2e22fc <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x26c> */
/* @0x2e227c vmov r0, s15 */
/* @0x2e2280 add r1, r12, #64 */
/* @0x2e2284 vstr s15, [r3, #-16] */
/* @0x2e2288 vstr s15, [r3, #-12] */
/* @0x2e228c vstr s15, [r3, #-32] */
/* @0x2e2290 vstr s15, [r3, #-28] */
/* @0x2e2294 add r9, r2, r7 */
/* @0x2e2298 vstr s15, [r8] */
/* @0x2e229c vstr s15, [r8, #4] */
/* @0x2e22a0 add r7, r7, #8 */
/* @0x2e22a4 vstr s15, [r3, #-8] */
/* @0x2e22a8 vstr s15, [r3, #-4] */
/* @0x2e22ac cmp r7, r6 */
/* @0x2e22b0 add r8, r8, #36 */
/* @0x2e22b4 add r12, r12, #20 */
/* @0x2e22b8 str r0, [r3], #36 */
/* @0x2e22bc ldm r1, {r0, r1} */
/* @0x2e22c0 stm r9, {r0, r1} */
/* @0x2e22c4 bne 0x2e227c <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x1ec> */
/* @0x2e22c8 ldr r2, [sp, #0x4] */
/* @0x2e22cc add r5, r5, #1 */
/* @0x2e22d0 ldr r3, [sp, #0x8] */
/* @0x2e22d4 add r2, r2, #156 */
/* @0x2e22d8 str r2, [sp, #0x4] */
/* @0x2e22dc cmp r3, r5 */
/* @0x2e22e0 ldr r2, [sp] */
/* @0x2e22e4 add r2, r2, #88 */
/* @0x2e22e8 str r2, [sp] */
/* @0x2e22ec ble 0x2e2360 <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x2d0> */
/* @0x2e22f0 ldr r2, [r4, #0x2c] */
/* @0x2e22f4 ldr r3, [r4, #0x28] */
/* @0x2e22f8 b 0x2e2140 <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0xb0> */
/* @0x2e22fc vldr s13, [r4, #8] */
/* @0x2e2300 vldr s14, [r12, #72] */
/* @0x2e2304 vmul.f32 s14, s13, s14 */
/* @0x2e2308 add r1, r12, #64 */
/* @0x2e230c vmov r0, s15 */
/* @0x2e2310 add r9, r2, r7 */
/* @0x2e2314 add r7, r7, #8 */
/* @0x2e2318 add r12, r12, #20 */
/* @0x2e231c cmp r7, r6 */
/* @0x2e2320 add r8, r8, #36 */
/* @0x2e2324 vstr s14, [r3, #-16] */
/* @0x2e2328 vldr s14, [r12, #56] */
/* @0x2e232c vmul.f32 s14, s13, s14 */
/* @0x2e2330 vstr s15, [r3, #-32] */
/* @0x2e2334 vstr s15, [r3, #-28] */
/* @0x2e2338 vstr s14, [r3, #-12] */
/* @0x2e233c vstr s15, [r8, #-36] */
/* @0x2e2340 vstr s15, [r8, #-32] */
/* @0x2e2344 vstr s15, [r3, #-8] */
/* @0x2e2348 vstr s15, [r3, #-4] */
/* @0x2e234c str r0, [r3], #36 */
/* @0x2e2350 ldm r1, {r0, r1} */
/* @0x2e2354 stm r9, {r0, r1} */
/* @0x2e2358 bne 0x2e22fc <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x26c> */
/* @0x2e235c b 0x2e22c8 <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x238> */
/* @0x2e2360 mov r0, r4 */
/* @0x2e2364 add sp, sp, #20 */
/* @0x2e2368 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e236c andeq r0, r0, r0 */

/* ── FUNC 0x2e2090 · b2ContactSolver::b2ContactSolver(b2ContactSolverDef*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2e2370 · b2ContactSolver::~b2ContactSolver() · size=40 · insn=10 */
/* @0x2e2370 push {r4, lr} */
/* @0x2e2374 mov r4, r0 */
/* @0x2e2378 ldr r1, [r4, #0x28] */
/* @0x2e237c ldr r0, [r0, #0x20] */
/* @0x2e2380 bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv> */
/* @0x2e2384 ldr r0, [r4, #0x20] */
/* @0x2e2388 ldr r1, [r4, #0x24] */
/* @0x2e238c bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv> */
/* @0x2e2390 mov r0, r4 */
/* @0x2e2394 pop {r4, pc} */

/* ── FUNC 0x2e2370 · b2ContactSolver::~b2ContactSolver() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2e2398 · b2ContactSolver::InitializeVelocityConstraints() · size=1080 · insn=270 */
/* @0x2e2398 ldr r3, [r0, #0x30] */
/* @0x2e239c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e23a0 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2e23a4 cmp r3, #0 */
/* @0x2e23a8 sub sp, sp, #124 */
/* @0x2e23ac mov r6, r0 */
/* @0x2e23b0 ble 0x2e26d8 <_ZN15b2ContactSolver29InitializeVelocityConstraintsEv+0x340> */
/* @0x2e23b4 vmov.f32 s18, #1.000000e+00 */
/* @0x2e23b8 mov r7, #0 */
/* @0x2e23bc mov r9, r7 */
/* @0x2e23c0 mov r8, r7 */
/* @0x2e23c4 mov r5, #0 */
/* @0x2e23c8 add r12, sp, #96 */
/* @0x2e23cc str r12, [sp, #0x1c] */
/* @0x2e23d0 add r12, sp, #64 */
/* @0x2e23d4 str r12, [sp, #0x38] */
/* @0x2e23d8 add r12, sp, #80 */
/* @0x2e23dc str r12, [sp, #0x3c] */
/* @0x2e23e0 vmov.f32 s29, #-1.000000e+00 */
/* @0x2e23e4 ldr r4, [r6, #0x28] */
/* @0x2e23e8 ldr r1, [r6, #0x2c] */
/* @0x2e23ec add r4, r4, r9 */
/* @0x2e23f0 ldr lr, [r6, #0x18] */
/* @0x2e23f4 vldr s3, [r4, #120] */
/* @0x2e23f8 vldr s4, [r4, #124] */
/* @0x2e23fc ldr r10, [r4, #0x70] */
/* @0x2e2400 vstr s3, [sp, #48] */
/* @0x2e2404 ldr r3, [r4, #0x98] */
/* @0x2e2408 vstr s4, [sp, #52] */
/* @0x2e240c ldr r2, [r4, #0x74] */
/* @0x2e2410 vldr s17, [r4, #128] */
/* @0x2e2414 add r10, r10, r10, lsl #1 */
/* @0x2e2418 vldr s16, [r4, #132] */
/* @0x2e241c ldr r1, [r1, r3, lsl #2] */
/* @0x2e2420 lsl r10, r10, #2 */
/* @0x2e2424 add r2, r2, r2, lsl #1 */
/* @0x2e2428 add r3, lr, r10 */
/* @0x2e242c vldr s20, [r3] */
/* @0x2e2430 vldr s19, [r3, #4] */
/* @0x2e2434 lsl r2, r2, #2 */
/* @0x2e2438 ldr r11, [r3, #0x8] */
/* @0x2e243c add lr, lr, r2 */
/* @0x2e2440 ldr r3, [r6, #0x1c] */
/* @0x2e2444 vldr s22, [lr] */
/* @0x2e2448 vldr s21, [lr, #4] */
/* @0x2e244c add r1, r1, #64 */
/* @0x2e2450 add r2, r3, r2 */
/* @0x2e2454 vldr s26, [r2] */
/* @0x2e2458 vldr s25, [r2, #4] */
/* @0x2e245c vldr s24, [r2, #8] */
/* @0x2e2460 ldr r2, [r6, #0x24] */
/* @0x2e2464 add r10, r3, r10 */
/* @0x2e2468 mov r0, r11 */
/* @0x2e246c vldr s28, [r10] */
/* @0x2e2470 add r12, r2, r7 */
/* @0x2e2474 vldr s27, [r10, #4] */
/* @0x2e2478 vldr s3, [r12, #48] */
/* @0x2e247c vldr s4, [r12, #52] */
/* @0x2e2480 ldr r3, [r12, #0x4c] */
/* @0x2e2484 vldr s8, [r12, #56] */
/* @0x2e2488 ldr r2, [r12, #0x50] */
/* @0x2e248c vstr s3, [sp, #44] */
/* @0x2e2490 vstr s4, [sp, #40] */
/* @0x2e2494 vldr s23, [r10, #8] */
/* @0x2e2498 ldr r10, [lr, #0x8] */
/* @0x2e249c vstr s8, [sp, #36] */
/* @0x2e24a0 vldr s10, [r12, #60] */
/* @0x2e24a4 str r1, [sp, #0xc] */
/* @0x2e24a8 vstr s10, [sp, #32] */
/* @0x2e24ac str r2, [sp, #0x10] */
/* @0x2e24b0 str r3, [sp, #0x14] */
/* @0x2e24b4 bl 0xb6580 <sinf@plt> */
/* @0x2e24b8 vmov s30, r0 */
/* @0x2e24bc mov r0, r11 */
/* @0x2e24c0 vstr s30, [sp, #72] */
/* @0x2e24c4 bl 0xb658c <cosf@plt> */
/* @0x2e24c8 vmov s31, r0 */
/* @0x2e24cc mov r0, r10 */
/* @0x2e24d0 vstr s31, [sp, #76] */
/* @0x2e24d4 bl 0xb6580 <sinf@plt> */
/* @0x2e24d8 str r0, [sp, #0x18] */
/* @0x2e24dc mov r0, r10 */
/* @0x2e24e0 vldr s11, [sp, #24] */
/* @0x2e24e4 vstr s11, [sp, #88] */
/* @0x2e24e8 bl 0xb658c <cosf@plt> */
/* @0x2e24ec vldr s14, [sp, #40] */
/* @0x2e24f0 vldr s3, [sp, #32] */
/* @0x2e24f4 vldr s4, [sp, #24] */
/* @0x2e24f8 vmul.f32 s12, s14, s30 */
/* @0x2e24fc vldr s8, [sp, #44] */
/* @0x2e2500 vldr s10, [sp, #36] */
/* @0x2e2504 ldr r2, [sp, #0x10] */
/* @0x2e2508 ldr r1, [sp, #0xc] */
/* @0x2e250c ldr r3, [sp, #0x14] */
/* @0x2e2510 str r2, [sp, #0x4] */
/* @0x2e2514 add r2, sp, #80 */
/* @0x2e2518 str r2, [sp] */
/* @0x2e251c add r2, sp, #64 */
/* @0x2e2520 vmul.f32 s13, s14, s31 */
/* @0x2e2524 vmul.f32 s14, s3, s4 */
/* @0x2e2528 vmov s11, r0 */
/* @0x2e252c add r0, sp, #96 */
/* @0x2e2530 vstr s11, [sp, #92] */
/* @0x2e2534 vmul.f32 s15, s3, s11 */
/* @0x2e2538 vnmls.f32 s12, s8, s31 */
/* @0x2e253c vmla.f32 s13, s8, s30 */
/* @0x2e2540 vnmls.f32 s14, s10, s11 */
/* @0x2e2544 vmla.f32 s15, s10, s4 */
/* @0x2e2548 vsub.f32 s12, s20, s12 */
/* @0x2e254c vsub.f32 s13, s19, s13 */
/* @0x2e2550 vstr s12, [sp, #64] */
/* @0x2e2554 vsub.f32 s14, s22, s14 */
/* @0x2e2558 vstr s13, [sp, #68] */
/* @0x2e255c vsub.f32 s15, s21, s15 */
/* @0x2e2560 vstr s14, [sp, #80] */
/* @0x2e2564 vstr s15, [sp, #84] */
/* @0x2e2568 bl 0x2c32c8 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f> */
/* @0x2e256c ldr r2, [sp, #0x1c] */
/* @0x2e2570 add r3, r4, #72 */
/* @0x2e2574 ldr r12, [r4, #0x94] */
/* @0x2e2578 ldm r2, {r0, r1} */
/* @0x2e257c cmp r12, #0 */
/* @0x2e2580 stm r3, {r0, r1} */
/* @0x2e2584 ble 0x2e26c0 <_ZN15b2ContactSolver29InitializeVelocityConstraintsEv+0x328> */
/* @0x2e2588 vldr s3, [sp, #48] */
/* @0x2e258c vldr s4, [sp, #52] */
/* @0x2e2590 vadd.f32 s7, s3, s4 */
/* @0x2e2594 add r2, sp, #104 */
/* @0x2e2598 add r1, r4, #4 */
/* @0x2e259c add r3, r4, #32 */
/* @0x2e25a0 mov r0, #0 */
/* @0x2e25a4 vneg.f32 s5, s24 */
/* @0x2e25a8 vneg.f32 s6, s23 */
/* @0x2e25ac vldr s12, [r2] */
/* @0x2e25b0 vldr s13, [r2, #4] */
/* @0x2e25b4 add r0, r0, #1 */
/* @0x2e25b8 add r2, r2, #8 */
/* @0x2e25bc vsub.f32 s12, s12, s20 */
/* @0x2e25c0 add r1, r1, #36 */
/* @0x2e25c4 add r3, r3, #36 */
/* @0x2e25c8 vsub.f32 s13, s13, s19 */
/* @0x2e25cc vstr s12, [r3, #-68] */
/* @0x2e25d0 vstr s13, [r1, #-36] */
/* @0x2e25d4 vldr s10, [r2, #-8] */
/* @0x2e25d8 vldr s11, [r2, #-4] */
/* @0x2e25dc vsub.f32 s10, s10, s22 */
/* @0x2e25e0 vsub.f32 s11, s11, s21 */
/* @0x2e25e4 vstr s10, [r1, #-32] */
/* @0x2e25e8 vstr s11, [r1, #-28] */
/* @0x2e25ec vldr s14, [r4, #72] */
/* @0x2e25f0 vmul.f32 s8, s13, s14 */
/* @0x2e25f4 vldr s15, [r4, #76] */
/* @0x2e25f8 str r5, [r3, #-0x24] */
/* @0x2e25fc vnmls.f32 s8, s12, s15 */
/* @0x2e2600 vmul.f32 s9, s11, s14 */
/* @0x2e2604 vmul.f32 s4, s17, s8 */
/* @0x2e2608 vnmls.f32 s9, s10, s15 */
/* @0x2e260c vmov.f32 s3, s7 */
/* @0x2e2610 vmla.f32 s3, s4, s8 */
/* @0x2e2614 vmul.f32 s4, s16, s9 */
/* @0x2e2618 vmov.f32 s8, s3 */
/* @0x2e261c vmla.f32 s8, s4, s9 */
/* @0x2e2620 vcmpe.f32 s8, #0 */
/* @0x2e2624 vmrs APSR_nzcv, fpscr */
/* @0x2e2628 vdivgt.f32 s8, s18, s8 */
/* @0x2e262c vldrle s8, [pc, #408] */
/* @0x2e2630 vstr s8, [r3, #-44] */
/* @0x2e2634 vmul.f32 s8, s13, s15 */
/* @0x2e2638 vneg.f32 s4, s14 */
/* @0x2e263c vnmls.f32 s8, s12, s4 */
/* @0x2e2640 vmul.f32 s9, s11, s15 */
/* @0x2e2644 vmul.f32 s3, s17, s8 */
/* @0x2e2648 vnmls.f32 s9, s10, s4 */
/* @0x2e264c vmov.f32 s4, s7 */
/* @0x2e2650 vmla.f32 s4, s3, s8 */
/* @0x2e2654 vmov.f32 s8, s4 */
/* @0x2e2658 vmul.f32 s4, s16, s9 */
/* @0x2e265c vmla.f32 s8, s4, s9 */
/* @0x2e2660 vmov.f32 s9, s25 */
/* @0x2e2664 vmla.f32 s9, s24, s10 */
/* @0x2e2668 vmov.f32 s10, s26 */
/* @0x2e266c vmla.f32 s10, s11, s5 */
/* @0x2e2670 vsub.f32 s11, s9, s27 */
/* @0x2e2674 vmls.f32 s11, s23, s12 */
/* @0x2e2678 vsub.f32 s12, s10, s28 */
/* @0x2e267c vmls.f32 s12, s13, s6 */
/* @0x2e2680 vcmpe.f32 s8, #0 */
/* @0x2e2684 vmul.f32 s15, s15, s11 */
/* @0x2e2688 vmrs APSR_nzcv, fpscr */
/* @0x2e268c vldrle s8, [pc, #312] */
/* @0x2e2690 vdivgt.f32 s8, s18, s8 */
/* @0x2e2694 vmla.f32 s15, s14, s12 */
/* @0x2e2698 vstr s8, [r3, #-40] */
/* @0x2e269c vcmpe.f32 s15, s29 */
/* @0x2e26a0 vmrs APSR_nzcv, fpscr */
/* @0x2e26a4 vldrmi s14, [r4, #140] */
/* @0x2e26a8 vnmulmi.f32 s15, s14, s15 */
/* @0x2e26ac vstrmi s15, [r3, #-36] */
/* @0x2e26b0 cmp r0, r12 */
/* @0x2e26b4 bne 0x2e25ac <_ZN15b2ContactSolver29InitializeVelocityConstraintsEv+0x214> */
/* @0x2e26b8 cmp r0, #2 */
/* @0x2e26bc beq 0x2e26e4 <_ZN15b2ContactSolver29InitializeVelocityConstraintsEv+0x34c> */
/* @0x2e26c0 ldr r3, [r6, #0x30] */
/* @0x2e26c4 add r8, r8, #1 */
/* @0x2e26c8 add r9, r9, #156 */
/* @0x2e26cc add r7, r7, #88 */
/* @0x2e26d0 cmp r3, r8 */
/* @0x2e26d4 bgt 0x2e23e4 <_ZN15b2ContactSolver29InitializeVelocityConstraintsEv+0x4c> */
/* @0x2e26d8 add sp, sp, #124 */
/* @0x2e26dc vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2e26e0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e26e4 vldr s14, [r4, #72] */
/* @0x2e26e8 vldr s11, [r4, #4] */
/* @0x2e26ec vmul.f32 s11, s14, s11 */
/* @0x2e26f0 vldr s13, [r4, #40] */
/* @0x2e26f4 vldr s15, [r4, #76] */
/* @0x2e26f8 vldr s5, [r4] */
/* @0x2e26fc vldr s6, [r4, #36] */
/* @0x2e2700 vldr s12, [r4, #12] */
/* @0x2e2704 vldr s9, [r4, #48] */
/* @0x2e2708 vldr s8, [r4, #8] */
/* @0x2e270c vldr s10, [r4, #44] */
/* @0x2e2710 mov r2, #0 */
/* @0x2e2714 movt r2, #0x447a */
/* @0x2e2718 vmov s3, r2 */
/* @0x2e271c vmul.f32 s13, s14, s13 */
/* @0x2e2720 vnmls.f32 s11, s15, s5 */
/* @0x2e2724 vnmls.f32 s13, s15, s6 */
/* @0x2e2728 vmul.f32 s12, s14, s12 */
/* @0x2e272c vmul.f32 s14, s14, s9 */
/* @0x2e2730 vnmls.f32 s12, s15, s8 */
/* @0x2e2734 vmul.f32 s9, s17, s11 */
/* @0x2e2738 vnmls.f32 s14, s15, s10 */
/* @0x2e273c vmul.f32 s17, s17, s13 */
/* @0x2e2740 vmov.f32 s15, s7 */
/* @0x2e2744 vmla.f32 s15, s9, s13 */
/* @0x2e2748 vmov.f32 s8, s7 */
/* @0x2e274c vmla.f32 s8, s17, s13 */
/* @0x2e2750 vmul.f32 s10, s16, s12 */
/* @0x2e2754 vmla.f32 s7, s9, s11 */
/* @0x2e2758 vmul.f32 s16, s16, s14 */
/* @0x2e275c vmla.f32 s15, s10, s14 */
/* @0x2e2760 vmov.f32 s13, s8 */
/* @0x2e2764 vmla.f32 s7, s10, s12 */
/* @0x2e2768 vmla.f32 s13, s16, s14 */
/* @0x2e276c vmul.f32 s14, s15, s15 */
/* @0x2e2770 vnmls.f32 s14, s7, s13 */
/* @0x2e2774 vmul.f32 s11, s7, s7 */
/* @0x2e2778 vmul.f32 s12, s14, s3 */
/* @0x2e277c vcmpe.f32 s11, s12 */
/* @0x2e2780 vmrs APSR_nzcv, fpscr */
/* @0x2e2784 movpl r2, #1 */
/* @0x2e2788 strpl r2, [r4, #0x94] */
/* @0x2e278c bpl 0x2e26c0 <_ZN15b2ContactSolver29InitializeVelocityConstraintsEv+0x328> */
/* @0x2e2790 vcmp.f32 s14, #0 */
/* @0x2e2794 vstr s15, [r4, #100] */
/* @0x2e2798 vstr s15, [r4, #104] */
/* @0x2e279c vstr s13, [r4, #108] */
/* @0x2e27a0 vstr s7, [r4, #96] */
/* @0x2e27a4 vmrs APSR_nzcv, fpscr */
/* @0x2e27a8 vdivne.f32 s14, s18, s14 */
/* @0x2e27ac vnmul.f32 s15, s14, s15 */
/* @0x2e27b0 vmul.f32 s13, s13, s14 */
/* @0x2e27b4 vstr s15, [r4, #84] */
/* @0x2e27b8 vstr s15, [r4, #88] */
/* @0x2e27bc vmul.f32 s14, s7, s14 */
/* @0x2e27c0 vstr s13, [r4, #80] */
/* @0x2e27c4 vstr s14, [r4, #92] */
/* @0x2e27c8 b 0x2e26c0 <_ZN15b2ContactSolver29InitializeVelocityConstraintsEv+0x328> */
/* @0x2e27cc andeq r0, r0, r0 */

/* ── FUNC 0x2e27d0 · b2ContactSolver::WarmStart() · size=292 · insn=73 */
/* @0x2e27d0 ldr r3, [r0, #0x30] */
/* @0x2e27d4 push {r4, r5, r6, r7, r8} */
/* @0x2e27d8 vpush {d8, d9} */
/* @0x2e27dc cmp r3, #0 */
/* @0x2e27e0 ble 0x2e28e8 <_ZN15b2ContactSolver9WarmStartEv+0x118> */
/* @0x2e27e4 ldr r12, [r0, #0x28] */
/* @0x2e27e8 mov r8, #156 */
/* @0x2e27ec ldr r7, [r0, #0x1c] */
/* @0x2e27f0 add r6, r12, #148 */
/* @0x2e27f4 mla r8, r8, r3, r12 */
/* @0x2e27f8 ldr r5, [r12, #0x70] */
/* @0x2e27fc vldr s16, [r12, #72] */
/* @0x2e2800 ldr r4, [r12, #0x74] */
/* @0x2e2804 vneg.f32 s19, s16 */
/* @0x2e2808 ldr r0, [r12, #0x94] */
/* @0x2e280c vldr s4, [r6, #-28] */
/* @0x2e2810 add r5, r5, r5, lsl #1 */
/* @0x2e2814 vldr s17, [r6, #-20] */
/* @0x2e2818 add r4, r4, r4, lsl #1 */
/* @0x2e281c cmp r0, #0 */
/* @0x2e2820 add r5, r7, r5, lsl #2 */
/* @0x2e2824 vldr s3, [r6, #-24] */
/* @0x2e2828 add r4, r7, r4, lsl #2 */
/* @0x2e282c vldr s5, [r5] */
/* @0x2e2830 vldr s6, [r5, #4] */
/* @0x2e2834 vldr s7, [r5, #8] */
/* @0x2e2838 vldr s18, [r6, #-16] */
/* @0x2e283c vldr s8, [r4] */
/* @0x2e2840 vldr s9, [r4, #4] */
/* @0x2e2844 vldr s10, [r4, #8] */
/* @0x2e2848 vldr s2, [r12, #76] */
/* @0x2e284c ble 0x2e28c0 <_ZN15b2ContactSolver9WarmStartEv+0xf0> */
/* @0x2e2850 add r2, r12, #8 */
/* @0x2e2854 add r3, r12, #16 */
/* @0x2e2858 mov r1, #0 */
/* @0x2e285c vldr s15, [r3, #4] */
/* @0x2e2860 vmul.f32 s14, s15, s2 */
/* @0x2e2864 vldr s11, [r3] */
/* @0x2e2868 vldr s12, [r3, #-12] */
/* @0x2e286c vldr s13, [r2, #4] */
/* @0x2e2870 vldr s0, [r3, #-16] */
/* @0x2e2874 vldr s1, [r2] */
/* @0x2e2878 add r1, r1, #1 */
/* @0x2e287c cmp r1, r0 */
/* @0x2e2880 add r3, r3, #36 */
/* @0x2e2884 add r2, r2, #36 */
/* @0x2e2888 vmla.f32 s14, s11, s16 */
/* @0x2e288c vmul.f32 s15, s15, s19 */
/* @0x2e2890 vmla.f32 s15, s11, s2 */
/* @0x2e2894 vmul.f32 s12, s14, s12 */
/* @0x2e2898 vmul.f32 s13, s14, s13 */
/* @0x2e289c vnmls.f32 s12, s15, s0 */
/* @0x2e28a0 vnmls.f32 s13, s15, s1 */
/* @0x2e28a4 vmls.f32 s5, s4, s14 */
/* @0x2e28a8 vmls.f32 s6, s4, s15 */
/* @0x2e28ac vmla.f32 s8, s3, s14 */
/* @0x2e28b0 vmla.f32 s9, s3, s15 */
/* @0x2e28b4 vmls.f32 s7, s17, s12 */
/* @0x2e28b8 vmla.f32 s10, s18, s13 */
/* @0x2e28bc bne 0x2e285c <_ZN15b2ContactSolver9WarmStartEv+0x8c> */
/* @0x2e28c0 add r12, r12, #156 */
/* @0x2e28c4 vstr s5, [r5] */
/* @0x2e28c8 cmp r12, r8 */
/* @0x2e28cc vstr s6, [r5, #4] */
/* @0x2e28d0 vstr s7, [r5, #8] */
/* @0x2e28d4 add r6, r6, #156 */
/* @0x2e28d8 vstr s8, [r4] */
/* @0x2e28dc vstr s9, [r4, #4] */
/* @0x2e28e0 vstr s10, [r4, #8] */
/* @0x2e28e4 bne 0x2e27f8 <_ZN15b2ContactSolver9WarmStartEv+0x28> */
/* @0x2e28e8 vpop {d8, d9} */
/* @0x2e28ec pop {r4, r5, r6, r7, r8} */
/* @0x2e28f0 bx lr */

/* ── FUNC 0x2e28f4 · b2ContactSolver::SolveVelocityConstraints() · size=1524 · insn=381 */
/* @0x2e28f4 ldr r3, [r0, #0x30] */
/* @0x2e28f8 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2e28fc vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2e2900 cmp r3, #0 */
/* @0x2e2904 sub sp, sp, #48 */
/* @0x2e2908 ble 0x2e2cc8 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x3d4> */
/* @0x2e290c mov r2, #156 */
/* @0x2e2910 ldr r7, [r0, #0x28] */
/* @0x2e2914 mul r2, r2, r3 */
/* @0x2e2918 ldr r0, [r0, #0x1c] */
/* @0x2e291c add r1, r7, #8 */
/* @0x2e2920 add r3, r7, #80 */
/* @0x2e2924 str r1, [sp, #0x10] */
/* @0x2e2928 add r1, r7, #60 */
/* @0x2e292c str r3, [sp, #0x20] */
/* @0x2e2930 add r3, r7, #36 */
/* @0x2e2934 str r1, [sp, #0x8] */
/* @0x2e2938 add r1, r7, #12 */
/* @0x2e293c str r2, [sp, #0x14] */
/* @0x2e2940 add r2, r7, #96 */
/* @0x2e2944 str r2, [sp, #0x24] */
/* @0x2e2948 add r8, r7, #16 */
/* @0x2e294c str r3, [sp, #0x2c] */
/* @0x2e2950 add r9, r7, #52 */
/* @0x2e2954 str r1, [sp, #0x18] */
/* @0x2e2958 add r11, r7, #68 */
/* @0x2e295c ldr r3, [sp, #0x24] */
/* @0x2e2960 mov r4, #0 */
/* @0x2e2964 ldr r1, [sp, #0x20] */
/* @0x2e2968 add r2, r7, #44 */
/* @0x2e296c ldr r10, [sp, #0x10] */
/* @0x2e2970 str r0, [sp, #0xc] */
/* @0x2e2974 mov r0, r7 */
/* @0x2e2978 str r2, [sp, #0x28] */
/* @0x2e297c add r2, r7, #28 */
/* @0x2e2980 str r3, [sp, #0x4] */
/* @0x2e2984 str r2, [sp, #0x1c] */
/* @0x2e2988 str r1, [sp] */
/* @0x2e298c ldr r6, [r0, #0x70] */
/* @0x2e2990 add r3, r7, r4 */
/* @0x2e2994 ldr r5, [r0, #0x74] */
/* @0x2e2998 vldr s4, [r3, #72] */
/* @0x2e299c ldr r12, [r0, #0x94] */
/* @0x2e29a0 vneg.f32 s21, s4 */
/* @0x2e29a4 ldr r2, [sp, #0xc] */
/* @0x2e29a8 add r6, r6, r6, lsl #1 */
/* @0x2e29ac add r5, r5, r5, lsl #1 */
/* @0x2e29b0 cmp r12, #0 */
/* @0x2e29b4 add r6, r2, r6, lsl #2 */
/* @0x2e29b8 vldr s9, [r3, #76] */
/* @0x2e29bc add r5, r2, r5, lsl #2 */
/* @0x2e29c0 vldr s7, [r0, #120] */
/* @0x2e29c4 vldr s10, [r6] */
/* @0x2e29c8 vldr s11, [r6, #4] */
/* @0x2e29cc vldr s14, [r6, #8] */
/* @0x2e29d0 vldr s5, [r0, #128] */
/* @0x2e29d4 vldr s12, [r5] */
/* @0x2e29d8 vldr s13, [r5, #4] */
/* @0x2e29dc vldr s15, [r5, #8] */
/* @0x2e29e0 vldr s8, [r0, #124] */
/* @0x2e29e4 vldr s6, [r0, #132] */
/* @0x2e29e8 vldr s22, [r0, #136] */
/* @0x2e29ec ble 0x2e2acc <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x1d8> */
/* @0x2e29f0 ldr r1, [sp, #0x1c] */
/* @0x2e29f4 vldr s23, [r0, #144] */
/* @0x2e29f8 add r3, r1, r4 */
/* @0x2e29fc ldr r1, [sp, #0x18] */
/* @0x2e2a00 add r2, r1, r4 */
/* @0x2e2a04 mov r1, #0 */
/* @0x2e2a08 vmov.f32 s16, s13 */
/* @0x2e2a0c vldr s19, [r2, #-4] */
/* @0x2e2a10 vldr s0, [r2] */
/* @0x2e2a14 vldr s18, [r3, #-28] */
/* @0x2e2a18 vldr s1, [r3, #-24] */
/* @0x2e2a1c vldr s20, [r3, #-8] */
/* @0x2e2a20 vldr s3, [r3] */
/* @0x2e2a24 vldr s2, [r3, #-12] */
/* @0x2e2a28 vmla.f32 s16, s15, s19 */
/* @0x2e2a2c add r1, r1, #1 */
/* @0x2e2a30 add r2, r2, #36 */
/* @0x2e2a34 add r3, r3, #36 */
/* @0x2e2a38 vmov.f32 s17, s12 */
/* @0x2e2a3c vmls.f32 s17, s15, s0 */
/* @0x2e2a40 vsub.f32 s16, s16, s11 */
/* @0x2e2a44 vmls.f32 s16, s14, s18 */
/* @0x2e2a48 vsub.f32 s17, s17, s10 */
/* @0x2e2a4c vmla.f32 s17, s14, s1 */
/* @0x2e2a50 vmul.f32 s16, s21, s16 */
/* @0x2e2a54 vmla.f32 s16, s17, s9 */
/* @0x2e2a58 vsub.f32 s16, s16, s23 */
/* @0x2e2a5c vmov.f32 s17, s20 */
/* @0x2e2a60 vmls.f32 s17, s16, s3 */
/* @0x2e2a64 vmul.f32 s2, s22, s2 */
/* @0x2e2a68 vcmpe.f32 s2, s17 */
/* @0x2e2a6c vneg.f32 s3, s2 */
/* @0x2e2a70 vmrs APSR_nzcv, fpscr */
/* @0x2e2a74 vmovgt.f32 s2, s17 */
/* @0x2e2a78 vcmpe.f32 s3, s2 */
/* @0x2e2a7c vmrs APSR_nzcv, fpscr */
/* @0x2e2a80 vmovle.f32 s3, s2 */
/* @0x2e2a84 vstr s3, [r3, #-44] */
/* @0x2e2a88 cmp r1, r12 */
/* @0x2e2a8c vsub.f32 s3, s3, s20 */
/* @0x2e2a90 vmul.f32 s2, s3, s9 */
/* @0x2e2a94 vmul.f32 s3, s3, s21 */
/* @0x2e2a98 vmul.f32 s0, s0, s2 */
/* @0x2e2a9c vmul.f32 s1, s1, s2 */
/* @0x2e2aa0 vnmls.f32 s0, s19, s3 */
/* @0x2e2aa4 vnmls.f32 s1, s18, s3 */
/* @0x2e2aa8 vmla.f32 s15, s6, s0 */
/* @0x2e2aac vmls.f32 s14, s5, s1 */
/* @0x2e2ab0 vmls.f32 s10, s7, s2 */
/* @0x2e2ab4 vmls.f32 s11, s7, s3 */
/* @0x2e2ab8 vmla.f32 s12, s8, s2 */
/* @0x2e2abc vmla.f32 s13, s8, s3 */
/* @0x2e2ac0 bne 0x2e2a08 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x114> */
/* @0x2e2ac4 cmp r1, #1 */
/* @0x2e2ac8 beq 0x2e2d3c <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x448> */
/* @0x2e2acc vmov.f32 s0, s13 */
/* @0x2e2ad0 ldr r1, [sp, #0x28] */
/* @0x2e2ad4 vldr s21, [r0] */
/* @0x2e2ad8 vldr s25, [r0, #4] */
/* @0x2e2adc add r3, r1, r4 */
/* @0x2e2ae0 vldr s18, [r3] */
/* @0x2e2ae4 ldr r1, [sp, #0x2c] */
/* @0x2e2ae8 vldr s22, [r3, #4] */
/* @0x2e2aec vmla.f32 s0, s15, s18 */
/* @0x2e2af0 rsb r3, r7, r10 */
/* @0x2e2af4 add r2, r1, r4 */
/* @0x2e2af8 ldr r1, [sp, #0x10] */
/* @0x2e2afc vldr s19, [r2] */
/* @0x2e2b00 vldr s23, [r2, #4] */
/* @0x2e2b04 add r3, r3, r1 */
/* @0x2e2b08 vldr s20, [r3, #-8] */
/* @0x2e2b0c vldr s24, [r3, #-4] */
/* @0x2e2b10 ldr r2, [sp, #0x4] */
/* @0x2e2b14 ldr r1, [sp, #0x24] */
/* @0x2e2b18 vldr s16, [r9] */
/* @0x2e2b1c rsb r3, r7, r2 */
/* @0x2e2b20 vldr s17, [r8] */
/* @0x2e2b24 add r3, r3, r1 */
/* @0x2e2b28 vldr s1, [r3, #-84] */
/* @0x2e2b2c vldr s26, [r3, #-92] */
/* @0x2e2b30 vldr s27, [r3, #-88] */
/* @0x2e2b34 vldr s29, [r3, #-96] */
/* @0x2e2b38 ldr r2, [sp] */
/* @0x2e2b3c ldr r1, [sp, #0x20] */
/* @0x2e2b40 rsb r3, r7, r2 */
/* @0x2e2b44 add r3, r3, r1 */
/* @0x2e2b48 vmov.f32 s2, s13 */
/* @0x2e2b4c vneg.f32 s3, s15 */
/* @0x2e2b50 vmov.f32 s28, s12 */
/* @0x2e2b54 vmla.f32 s2, s15, s20 */
/* @0x2e2b58 vmla.f32 s28, s3, s22 */
/* @0x2e2b5c vmov.f32 s30, s12 */
/* @0x2e2b60 vsub.f32 s0, s0, s11 */
/* @0x2e2b64 vmla.f32 s30, s3, s24 */
/* @0x2e2b68 vmls.f32 s0, s14, s19 */
/* @0x2e2b6c vsub.f32 s2, s2, s11 */
/* @0x2e2b70 vsub.f32 s28, s28, s10 */
/* @0x2e2b74 vneg.f32 s31, s14 */
/* @0x2e2b78 vmls.f32 s2, s14, s21 */
/* @0x2e2b7c vmls.f32 s28, s31, s23 */
/* @0x2e2b80 vsub.f32 s3, s30, s10 */
/* @0x2e2b84 vldr s30, [r11] */
/* @0x2e2b88 vmul.f32 s0, s0, s9 */
/* @0x2e2b8c vmls.f32 s3, s31, s25 */
/* @0x2e2b90 vldr s31, [r3, #-80] */
/* @0x2e2b94 vmul.f32 s1, s16, s1 */
/* @0x2e2b98 vmul.f32 s2, s2, s9 */
/* @0x2e2b9c vmla.f32 s0, s28, s4 */
/* @0x2e2ba0 vldr s28, [r3, #-72] */
/* @0x2e2ba4 vmla.f32 s1, s17, s26 */
/* @0x2e2ba8 vmla.f32 s2, s3, s4 */
/* @0x2e2bac vmul.f32 s3, s16, s27 */
/* @0x2e2bb0 vsub.f32 s0, s0, s30 */
/* @0x2e2bb4 vldr s30, [r0, #32] */
/* @0x2e2bb8 vmla.f32 s3, s17, s29 */
/* @0x2e2bbc vldr s29, [r3, #-76] */
/* @0x2e2bc0 vsub.f32 s0, s0, s1 */
/* @0x2e2bc4 vldr s1, [r3, #-68] */
/* @0x2e2bc8 vsub.f32 s2, s2, s30 */
/* @0x2e2bcc vmul.f32 s28, s0, s28 */
/* @0x2e2bd0 vsub.f32 s2, s2, s3 */
/* @0x2e2bd4 vmla.f32 s28, s2, s31 */
/* @0x2e2bd8 vneg.f32 s28, s28 */
/* @0x2e2bdc vcmpe.f32 s28, #0 */
/* @0x2e2be0 vmrs APSR_nzcv, fpscr */
/* @0x2e2be4 blt 0x2e2cd8 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x3e4> */
/* @0x2e2be8 vmul.f32 s1, s0, s1 */
/* @0x2e2bec vmla.f32 s1, s2, s29 */
/* @0x2e2bf0 vneg.f32 s1, s1 */
/* @0x2e2bf4 vcmpe.f32 s1, #0 */
/* @0x2e2bf8 vmrs APSR_nzcv, fpscr */
/* @0x2e2bfc blt 0x2e2cd8 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x3e4> */
/* @0x2e2c00 vsub.f32 s17, s28, s17 */
/* @0x2e2c04 vstr s28, [r8] */
/* @0x2e2c08 vstr s1, [r9] */
/* @0x2e2c0c vsub.f32 s1, s1, s16 */
/* @0x2e2c10 vmul.f32 s3, s17, s4 */
/* @0x2e2c14 vmul.f32 s4, s1, s4 */
/* @0x2e2c18 vmul.f32 s17, s17, s9 */
/* @0x2e2c1c vmul.f32 s25, s25, s3 */
/* @0x2e2c20 vmul.f32 s24, s24, s3 */
/* @0x2e2c24 vmul.f32 s23, s23, s4 */
/* @0x2e2c28 vmul.f32 s22, s22, s4 */
/* @0x2e2c2c vmul.f32 s9, s1, s9 */
/* @0x2e2c30 vnmls.f32 s23, s19, s9 */
/* @0x2e2c34 vnmls.f32 s22, s18, s9 */
/* @0x2e2c38 vnmls.f32 s25, s21, s17 */
/* @0x2e2c3c vnmls.f32 s24, s20, s17 */
/* @0x2e2c40 vadd.f32 s23, s25, s23 */
/* @0x2e2c44 vadd.f32 s22, s24, s22 */
/* @0x2e2c48 vadd.f32 s4, s3, s4 */
/* @0x2e2c4c vadd.f32 s9, s17, s9 */
/* @0x2e2c50 vmls.f32 s14, s23, s5 */
/* @0x2e2c54 vmla.f32 s15, s22, s6 */
/* @0x2e2c58 vmls.f32 s10, s7, s4 */
/* @0x2e2c5c vmla.f32 s12, s8, s4 */
/* @0x2e2c60 vmls.f32 s11, s7, s9 */
/* @0x2e2c64 vmla.f32 s13, s8, s9 */
/* @0x2e2c68 ldr r1, [sp, #0x14] */
/* @0x2e2c6c add r4, r4, #156 */
/* @0x2e2c70 ldr r2, [sp, #0x8] */
/* @0x2e2c74 vstr s10, [r6] */
/* @0x2e2c78 ldr r3, [sp, #0x4] */
/* @0x2e2c7c cmp r4, r1 */
/* @0x2e2c80 ldr r1, [sp] */
/* @0x2e2c84 vstr s11, [r6, #4] */
/* @0x2e2c88 vstr s14, [r6, #8] */
/* @0x2e2c8c add r2, r2, #156 */
/* @0x2e2c90 add r3, r3, #156 */
/* @0x2e2c94 add r1, r1, #156 */
/* @0x2e2c98 add r0, r0, #156 */
/* @0x2e2c9c vstr s12, [r5] */
/* @0x2e2ca0 vstr s13, [r5, #4] */
/* @0x2e2ca4 vstr s15, [r5, #8] */
/* @0x2e2ca8 add r8, r8, #156 */
/* @0x2e2cac add r9, r9, #156 */
/* @0x2e2cb0 str r2, [sp, #0x8] */
/* @0x2e2cb4 add r10, r10, #156 */
/* @0x2e2cb8 add r11, r11, #156 */
/* @0x2e2cbc str r3, [sp, #0x4] */
/* @0x2e2cc0 str r1, [sp] */
/* @0x2e2cc4 bne 0x2e298c <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x98> */
/* @0x2e2cc8 add sp, sp, #48 */
/* @0x2e2ccc vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2e2cd0 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2e2cd4 bx lr */
/* @0x2e2cd8 vldr s3, [r0, #24] */
/* @0x2e2cdc vnmul.f32 s3, s3, s2 */
/* @0x2e2ce0 vcmpe.f32 s3, #0 */
/* @0x2e2ce4 vmrs APSR_nzcv, fpscr */
/* @0x2e2ce8 blt 0x2e2dec <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x4f8> */
/* @0x2e2cec vmov.f32 s1, s0 */
/* @0x2e2cf0 vmla.f32 s1, s3, s26 */
/* @0x2e2cf4 vcmpe.f32 s1, #0 */
/* @0x2e2cf8 vmrs APSR_nzcv, fpscr */
/* @0x2e2cfc blt 0x2e2dec <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x4f8> */
/* @0x2e2d00 mov r1, #0 */
/* @0x2e2d04 vsub.f32 s17, s3, s17 */
/* @0x2e2d08 vmov s0, r1 */
/* @0x2e2d0c vstr s3, [r8] */
/* @0x2e2d10 str r1, [r9] */
/* @0x2e2d14 vsub.f32 s16, s0, s16 */
/* @0x2e2d18 vmul.f32 s3, s17, s4 */
/* @0x2e2d1c vmul.f32 s4, s16, s4 */
/* @0x2e2d20 vmul.f32 s17, s17, s9 */
/* @0x2e2d24 vmul.f32 s25, s25, s3 */
/* @0x2e2d28 vmul.f32 s24, s24, s3 */
/* @0x2e2d2c vmul.f32 s23, s23, s4 */
/* @0x2e2d30 vmul.f32 s22, s22, s4 */
/* @0x2e2d34 vmul.f32 s9, s16, s9 */
/* @0x2e2d38 b 0x2e2c30 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x33c> */
/* @0x2e2d3c vmov.f32 s1, s13 */
/* @0x2e2d40 ldr r1, [sp, #0x10] */
/* @0x2e2d44 rsb r3, r7, r10 */
/* @0x2e2d48 vldr s16, [r0] */
/* @0x2e2d4c add r3, r3, r1 */
/* @0x2e2d50 vldr s17, [r3, #-8] */
/* @0x2e2d54 vldr s2, [r3, #-4] */
/* @0x2e2d58 vldr s3, [r0, #4] */
/* @0x2e2d5c vmla.f32 s1, s15, s17 */
/* @0x2e2d60 vldr s20, [r0, #32] */
/* @0x2e2d64 vldr s18, [r8] */
/* @0x2e2d68 vldr s19, [r0, #24] */
/* @0x2e2d6c mov r1, #0 */
/* @0x2e2d70 vmov.f32 s0, s12 */
/* @0x2e2d74 vmls.f32 s0, s15, s2 */
/* @0x2e2d78 vsub.f32 s1, s1, s11 */
/* @0x2e2d7c vmls.f32 s1, s14, s16 */
/* @0x2e2d80 vsub.f32 s0, s0, s10 */
/* @0x2e2d84 vmla.f32 s0, s14, s3 */
/* @0x2e2d88 vmul.f32 s1, s1, s9 */
/* @0x2e2d8c vmla.f32 s1, s0, s4 */
/* @0x2e2d90 vsub.f32 s1, s1, s20 */
/* @0x2e2d94 vmov.f32 s0, s18 */
/* @0x2e2d98 vmls.f32 s0, s19, s1 */
/* @0x2e2d9c vmov.f32 s1, s0 */
/* @0x2e2da0 vcmpe.f32 s0, #0 */
/* @0x2e2da4 vmov s0, r1 */
/* @0x2e2da8 vmrs APSR_nzcv, fpscr */
/* @0x2e2dac vmovle.f32 s1, s0 */
/* @0x2e2db0 vstr s1, [r8] */
/* @0x2e2db4 vsub.f32 s1, s1, s18 */
/* @0x2e2db8 vmul.f32 s4, s1, s4 */
/* @0x2e2dbc vmul.f32 s9, s1, s9 */
/* @0x2e2dc0 vmul.f32 s2, s2, s4 */
/* @0x2e2dc4 vmul.f32 s3, s3, s4 */
/* @0x2e2dc8 vnmls.f32 s2, s17, s9 */
/* @0x2e2dcc vnmls.f32 s3, s16, s9 */
/* @0x2e2dd0 vmla.f32 s15, s6, s2 */
/* @0x2e2dd4 vmls.f32 s14, s5, s3 */
/* @0x2e2dd8 vmls.f32 s10, s7, s4 */
/* @0x2e2ddc vmls.f32 s11, s7, s9 */
/* @0x2e2de0 vmla.f32 s12, s8, s4 */
/* @0x2e2de4 vmla.f32 s13, s8, s9 */
/* @0x2e2de8 b 0x2e2c68 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x374> */
/* @0x2e2dec ldr r2, [sp, #0x8] */
/* @0x2e2df0 vldr s3, [r2] */
/* @0x2e2df4 vnmul.f32 s3, s3, s0 */
/* @0x2e2df8 vcmpe.f32 s3, #0 */
/* @0x2e2dfc vmrs APSR_nzcv, fpscr */
/* @0x2e2e00 blt 0x2e2e74 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x580> */
/* @0x2e2e04 vmov.f32 s1, s2 */
/* @0x2e2e08 vmla.f32 s1, s3, s27 */
/* @0x2e2e0c vcmpe.f32 s1, #0 */
/* @0x2e2e10 vmrs APSR_nzcv, fpscr */
/* @0x2e2e14 blt 0x2e2e74 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x580> */
/* @0x2e2e18 mov r3, #0 */
/* @0x2e2e1c str r3, [r8] */
/* @0x2e2e20 vmov s0, r3 */
/* @0x2e2e24 vstr s3, [r9] */
/* @0x2e2e28 vsub.f32 s3, s3, s16 */
/* @0x2e2e2c vsub.f32 s2, s0, s17 */
/* @0x2e2e30 vmul.f32 s1, s2, s4 */
/* @0x2e2e34 vmul.f32 s4, s3, s4 */
/* @0x2e2e38 vmul.f32 s2, s2, s9 */
/* @0x2e2e3c vmul.f32 s23, s23, s4 */
/* @0x2e2e40 vmul.f32 s9, s3, s9 */
/* @0x2e2e44 vmul.f32 s22, s22, s4 */
/* @0x2e2e48 vmul.f32 s25, s25, s1 */
/* @0x2e2e4c vmul.f32 s24, s24, s1 */
/* @0x2e2e50 vnmls.f32 s23, s19, s9 */
/* @0x2e2e54 vnmls.f32 s22, s18, s9 */
/* @0x2e2e58 vnmls.f32 s25, s21, s2 */
/* @0x2e2e5c vnmls.f32 s24, s20, s2 */
/* @0x2e2e60 vadd.f32 s23, s25, s23 */
/* @0x2e2e64 vadd.f32 s22, s24, s22 */
/* @0x2e2e68 vadd.f32 s4, s1, s4 */
/* @0x2e2e6c vadd.f32 s9, s2, s9 */
/* @0x2e2e70 b 0x2e2c50 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x35c> */
/* @0x2e2e74 vcmpe.f32 s2, #0 */
/* @0x2e2e78 vmrs APSR_nzcv, fpscr */
/* @0x2e2e7c blt 0x2e2c68 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x374> */
/* @0x2e2e80 vcmpe.f32 s0, #0 */
/* @0x2e2e84 vmrs APSR_nzcv, fpscr */
/* @0x2e2e88 blt 0x2e2c68 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x374> */
/* @0x2e2e8c mov r2, #0 */
/* @0x2e2e90 str r2, [r8] */
/* @0x2e2e94 vmov s0, r2 */
/* @0x2e2e98 str r2, [r9] */
/* @0x2e2e9c vsub.f32 s3, s0, s17 */
/* @0x2e2ea0 vsub.f32 s16, s0, s16 */
/* @0x2e2ea4 vmul.f32 s2, s3, s4 */
/* @0x2e2ea8 vmul.f32 s4, s16, s4 */
/* @0x2e2eac vmul.f32 s3, s3, s9 */
/* @0x2e2eb0 vmul.f32 s23, s23, s4 */
/* @0x2e2eb4 vmul.f32 s9, s16, s9 */
/* @0x2e2eb8 vmul.f32 s22, s22, s4 */
/* @0x2e2ebc vmul.f32 s25, s25, s2 */
/* @0x2e2ec0 vmul.f32 s24, s24, s2 */
/* @0x2e2ec4 vnmls.f32 s23, s19, s9 */
/* @0x2e2ec8 vnmls.f32 s22, s18, s9 */
/* @0x2e2ecc vnmls.f32 s25, s21, s3 */
/* @0x2e2ed0 vnmls.f32 s24, s20, s3 */
/* @0x2e2ed4 vadd.f32 s23, s25, s23 */
/* @0x2e2ed8 vadd.f32 s22, s24, s22 */
/* @0x2e2edc vadd.f32 s4, s2, s4 */
/* @0x2e2ee0 vadd.f32 s9, s3, s9 */
/* @0x2e2ee4 b 0x2e2c50 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x35c> */

/* ── FUNC 0x2e2ee8 · b2ContactSolver::StoreImpulses() · size=100 · insn=25 */
/* @0x2e2ee8 ldr r2, [r0, #0x30] */
/* @0x2e2eec cmp r2, #0 */
/* @0x2e2ef0 bxle lr */
/* @0x2e2ef4 ldr r3, [r0, #0x28] */
/* @0x2e2ef8 mov r1, #156 */
/* @0x2e2efc ldr r12, [r0, #0x2c] */
/* @0x2e2f00 add r3, r3, #152 */
/* @0x2e2f04 mla r0, r1, r2, r3 */
/* @0x2e2f08 ldmda r3, {r1, r2} */
/* @0x2e2f0c cmp r1, #0 */
/* @0x2e2f10 ldr r2, [r12, r2, lsl #2] */
/* @0x2e2f14 ble 0x2e2f3c <_ZN15b2ContactSolver13StoreImpulsesEv+0x54> */
/* @0x2e2f18 cmp r1, #1 */
/* @0x2e2f1c ldr r1, [r3, #-0x88] */
/* @0x2e2f20 str r1, [r2, #0x48] */
/* @0x2e2f24 ldr r1, [r3, #-0x84] */
/* @0x2e2f28 str r1, [r2, #0x4c] */
/* @0x2e2f2c ldrne r1, [r3, #-0x64] */
/* @0x2e2f30 strne r1, [r2, #0x5c] */
/* @0x2e2f34 ldrne r1, [r3, #-0x60] */
/* @0x2e2f38 strne r1, [r2, #0x60] */
/* @0x2e2f3c add r3, r3, #156 */
/* @0x2e2f40 cmp r3, r0 */
/* @0x2e2f44 bne 0x2e2f08 <_ZN15b2ContactSolver13StoreImpulsesEv+0x20> */
/* @0x2e2f48 bx lr */

/* ── FUNC 0x2e2f4c · b2ContactSolver::SolvePositionConstraints() · size=1164 · insn=291 */
/* @0x2e2f4c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e2f50 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2e2f54 mov r7, r0 */
/* @0x2e2f58 ldr r0, [r0, #0x30] */
/* @0x2e2f5c sub sp, sp, #36 */
/* @0x2e2f60 cmp r0, #0 */
/* @0x2e2f64 ble 0x2e33b8 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x46c> */
/* @0x2e2f68 ldr r1, [r7, #0x18] */
/* @0x2e2f6c mov r6, #0 */
/* @0x2e2f70 vldr s27, [pc, #992] */
/* @0x2e2f74 ldr r4, [r7, #0x24] */
/* @0x2e2f78 mov r3, #88 */
/* @0x2e2f7c mla r4, r3, r6, r4 */
/* @0x2e2f80 vldr s7, [r4, #48] */
/* @0x2e2f84 vldr s10, [r4, #52] */
/* @0x2e2f88 vstr s7, [sp, #24] */
/* @0x2e2f8c vstr s10, [sp, #20] */
/* @0x2e2f90 vldr s13, [r4, #64] */
/* @0x2e2f94 vldr s14, [r4, #56] */
/* @0x2e2f98 vldr s15, [r4, #60] */
/* @0x2e2f9c vldr s7, [r4, #44] */
/* @0x2e2fa0 vldr s10, [r4, #68] */
/* @0x2e2fa4 vldr s26, [r4, #40] */
/* @0x2e2fa8 vstr s13, [sp, #4] */
/* @0x2e2fac ldr r9, [r4, #0x20] */
/* @0x2e2fb0 vstr s14, [sp, #16] */
/* @0x2e2fb4 ldr r8, [r4, #0x24] */
/* @0x2e2fb8 vstr s15, [sp, #12] */
/* @0x2e2fbc ldr r5, [r4, #0x54] */
/* @0x2e2fc0 vstr s7, [sp] */
/* @0x2e2fc4 add r9, r9, r9, lsl #1 */
/* @0x2e2fc8 vstr s10, [sp, #8] */
/* @0x2e2fcc add r8, r8, r8, lsl #1 */
/* @0x2e2fd0 cmp r5, #0 */
/* @0x2e2fd4 lsl r9, r9, #2 */
/* @0x2e2fd8 lsl r8, r8, #2 */
/* @0x2e2fdc add r2, r1, r9 */
/* @0x2e2fe0 add r3, r1, r8 */
/* @0x2e2fe4 vldr s24, [r2] */
/* @0x2e2fe8 vldr s23, [r2, #4] */
/* @0x2e2fec vldr s22, [r2, #8] */
/* @0x2e2ff0 vldr s21, [r3] */
/* @0x2e2ff4 vldr s20, [r3, #4] */
/* @0x2e2ff8 vldr s19, [r3, #8] */
/* @0x2e2ffc ble 0x2e3374 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x428> */
/* @0x2e3000 vadd.f32 s13, s26, s7 */
/* @0x2e3004 mov r10, r4 */
/* @0x2e3008 mov r11, #0 */
/* @0x2e300c vstr s13, [sp, #28] */
/* @0x2e3010 b 0x2e30a8 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x15c> */
/* @0x2e3014 vldr s15, [pc, #828] */
/* @0x2e3018 vmul.f32 s13, s11, s30 */
/* @0x2e301c vldr s7, [sp, #4] */
/* @0x2e3020 add r11, r11, #1 */
/* @0x2e3024 add r10, r10, #8 */
/* @0x2e3028 vnmls.f32 s13, s9, s29 */
/* @0x2e302c vmul.f32 s14, s12, s30 */
/* @0x2e3030 vmul.f32 s8, s7, s13 */
/* @0x2e3034 vldr s7, [sp, #28] */
/* @0x2e3038 vnmls.f32 s14, s10, s29 */
/* @0x2e303c vmla.f32 s7, s8, s13 */
/* @0x2e3040 vmov.f32 s13, s7 */
/* @0x2e3044 vldr s7, [sp, #8] */
/* @0x2e3048 vmul.f32 s8, s7, s14 */
/* @0x2e304c vldr s7, [sp] */
/* @0x2e3050 vmla.f32 s13, s8, s14 */
/* @0x2e3054 vcmpe.f32 s13, #0 */
/* @0x2e3058 vmrs APSR_nzcv, fpscr */
/* @0x2e305c vneggt.f32 s15, s15 */
/* @0x2e3060 vldrle s15, [pc, #752] */
/* @0x2e3064 vdivgt.f32 s15, s15, s13 */
/* @0x2e3068 cmp r11, r5 */
/* @0x2e306c vldr s13, [sp, #8] */
/* @0x2e3070 vmul.f32 s14, s15, s30 */
/* @0x2e3074 vmul.f32 s15, s15, s29 */
/* @0x2e3078 vmul.f32 s11, s11, s14 */
/* @0x2e307c vmul.f32 s12, s12, s14 */
/* @0x2e3080 vnmls.f32 s11, s9, s15 */
/* @0x2e3084 vnmls.f32 s12, s10, s15 */
/* @0x2e3088 vldr s10, [sp, #4] */
/* @0x2e308c vmla.f32 s19, s13, s12 */
/* @0x2e3090 vmls.f32 s22, s10, s11 */
/* @0x2e3094 vmls.f32 s24, s26, s14 */
/* @0x2e3098 vmls.f32 s23, s26, s15 */
/* @0x2e309c vmla.f32 s21, s7, s14 */
/* @0x2e30a0 vmla.f32 s20, s7, s15 */
/* @0x2e30a4 beq 0x2e3364 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x418> */
/* @0x2e30a8 vmov r0, s22 */
/* @0x2e30ac bl 0xb6580 <sinf@plt> */
/* @0x2e30b0 vmov s18, r0 */
/* @0x2e30b4 vmov r0, s22 */
/* @0x2e30b8 bl 0xb658c <cosf@plt> */
/* @0x2e30bc vmov s17, r0 */
/* @0x2e30c0 vmov r0, s19 */
/* @0x2e30c4 bl 0xb6580 <sinf@plt> */
/* @0x2e30c8 vmov s16, r0 */
/* @0x2e30cc vmov r0, s19 */
/* @0x2e30d0 bl 0xb658c <cosf@plt> */
/* @0x2e30d4 vldr s14, [sp, #20] */
/* @0x2e30d8 vldr s7, [sp, #12] */
/* @0x2e30dc vmul.f32 s11, s14, s18 */
/* @0x2e30e0 vldr s10, [sp, #24] */
/* @0x2e30e4 ldr r3, [r4, #0x48] */
/* @0x2e30e8 cmp r3, #1 */
/* @0x2e30ec vmul.f32 s12, s14, s17 */
/* @0x2e30f0 vmul.f32 s13, s7, s16 */
/* @0x2e30f4 vmov s15, r0 */
/* @0x2e30f8 vmul.f32 s14, s7, s15 */
/* @0x2e30fc vldr s7, [sp, #16] */
/* @0x2e3100 vnmls.f32 s11, s10, s17 */
/* @0x2e3104 vmla.f32 s12, s10, s18 */
/* @0x2e3108 vnmls.f32 s13, s7, s15 */
/* @0x2e310c vmla.f32 s14, s7, s16 */
/* @0x2e3110 vsub.f32 s11, s24, s11 */
/* @0x2e3114 vsub.f32 s12, s23, s12 */
/* @0x2e3118 vsub.f32 s13, s21, s13 */
/* @0x2e311c vsub.f32 s14, s20, s14 */
/* @0x2e3120 beq 0x2e32dc <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x390> */
/* @0x2e3124 cmp r3, #2 */
/* @0x2e3128 beq 0x2e3258 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x30c> */
/* @0x2e312c cmp r3, #0 */
/* @0x2e3130 beq 0x2e3198 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x24c> */
/* @0x2e3134 movw r3, #0xd70a */
/* @0x2e3138 movt r3, #0x3ba3 */
/* @0x2e313c vcmpe.f32 s28, s27 */
/* @0x2e3140 vmov s7, r3 */
/* @0x2e3144 movw r3, #0xcccd */
/* @0x2e3148 movt r3, #0x3e4c */
/* @0x2e314c vadd.f32 s15, s28, s7 */
/* @0x2e3150 vmrs APSR_nzcv, fpscr */
/* @0x2e3154 vmov s7, r3 */
/* @0x2e3158 vmul.f32 s15, s15, s7 */
/* @0x2e315c vcmpe.f32 s15, #0 */
/* @0x2e3160 vmovle.f32 s27, s28 */
/* @0x2e3164 vmrs APSR_nzcv, fpscr */
/* @0x2e3168 vsub.f32 s9, s25, s24 */
/* @0x2e316c vsub.f32 s11, s31, s23 */
/* @0x2e3170 vsub.f32 s10, s25, s21 */
/* @0x2e3174 vsub.f32 s12, s31, s20 */
/* @0x2e3178 bpl 0x2e3014 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0xc8> */
/* @0x2e317c movw r3, #0xcccd */
/* @0x2e3180 movt r3, #0xbe4c */
/* @0x2e3184 vmov s7, r3 */
/* @0x2e3188 vcmpe.f32 s15, s7 */
/* @0x2e318c vmrs APSR_nzcv, fpscr */
/* @0x2e3190 vldrmi s15, [pc, #452] */
/* @0x2e3194 b 0x2e3018 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0xcc> */
/* @0x2e3198 vldr s25, [r4, #28] */
/* @0x2e319c vldr s10, [r4, #4] */
/* @0x2e31a0 vmul.f32 s31, s17, s25 */
/* @0x2e31a4 vldr s7, [r4, #24] */
/* @0x2e31a8 vldr s8, [r4] */
/* @0x2e31ac vmul.f32 s9, s15, s10 */
/* @0x2e31b0 vmul.f32 s25, s18, s25 */
/* @0x2e31b4 vmul.f32 s10, s16, s10 */
/* @0x2e31b8 vmla.f32 s31, s18, s7 */
/* @0x2e31bc vmla.f32 s9, s16, s8 */
/* @0x2e31c0 vnmls.f32 s25, s17, s7 */
/* @0x2e31c4 vnmls.f32 s10, s15, s8 */
/* @0x2e31c8 vadd.f32 s31, s12, s31 */
/* @0x2e31cc vadd.f32 s16, s14, s9 */
/* @0x2e31d0 vsub.f32 s29, s16, s31 */
/* @0x2e31d4 vadd.f32 s25, s11, s25 */
/* @0x2e31d8 vadd.f32 s17, s13, s10 */
/* @0x2e31dc vmul.f32 s28, s29, s29 */
/* @0x2e31e0 vsub.f32 s30, s17, s25 */
/* @0x2e31e4 vmla.f32 s28, s30, s30 */
/* @0x2e31e8 vsqrt.f32 s15, s28 */
/* @0x2e31ec vcmp.f32 s15, s15 */
/* @0x2e31f0 vmrs APSR_nzcv, fpscr */
/* @0x2e31f4 bne 0x2e33c8 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x47c> */
/* @0x2e31f8 mov r3, #872415232 */
/* @0x2e31fc vmov s7, r3 */
/* @0x2e3200 vcmpe.f32 s15, s7 */
/* @0x2e3204 vmrs APSR_nzcv, fpscr */
/* @0x2e3208 bmi 0x2e322c <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x2e0> */
/* @0x2e320c vmov.f32 s14, #1.000000e+00 */
/* @0x2e3210 vdiv.f32 s15, s14, s15 */
/* @0x2e3214 vmul.f32 s14, s29, s15 */
/* @0x2e3218 vmul.f32 s15, s30, s15 */
/* @0x2e321c vmul.f32 s28, s29, s14 */
/* @0x2e3220 vmov.f32 s29, s14 */
/* @0x2e3224 vmla.f32 s28, s30, s15 */
/* @0x2e3228 vmov.f32 s30, s15 */
/* @0x2e322c vldr s14, [r4, #76] */
/* @0x2e3230 mov r3, #1056964608 */
/* @0x2e3234 vmov s7, r3 */
/* @0x2e3238 vldr s15, [r4, #80] */
/* @0x2e323c vadd.f32 s25, s25, s17 */
/* @0x2e3240 vadd.f32 s31, s31, s16 */
/* @0x2e3244 vsub.f32 s28, s28, s14 */
/* @0x2e3248 vmul.f32 s25, s25, s7 */
/* @0x2e324c vmul.f32 s31, s31, s7 */
/* @0x2e3250 vsub.f32 s28, s28, s15 */
/* @0x2e3254 b 0x2e3134 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x1e8> */
/* @0x2e3258 vldr s10, [r4, #28] */
/* @0x2e325c vldr s25, [r10, #4] */
/* @0x2e3260 vmul.f32 s9, s15, s10 */
/* @0x2e3264 vldr s8, [r10] */
/* @0x2e3268 vldr s7, [r4, #24] */
/* @0x2e326c vldr s30, [r4, #20] */
/* @0x2e3270 vldr s28, [r4, #76] */
/* @0x2e3274 vmul.f32 s31, s17, s25 */
/* @0x2e3278 vmul.f32 s10, s16, s10 */
/* @0x2e327c vmla.f32 s31, s18, s8 */
/* @0x2e3280 vmla.f32 s9, s16, s7 */
/* @0x2e3284 vmul.f32 s25, s18, s25 */
/* @0x2e3288 vmul.f32 s29, s15, s30 */
/* @0x2e328c vnmls.f32 s25, s17, s8 */
/* @0x2e3290 vldr s8, [r4, #16] */
/* @0x2e3294 vnmls.f32 s10, s15, s7 */
/* @0x2e3298 vmla.f32 s29, s16, s8 */
/* @0x2e329c vmul.f32 s30, s16, s30 */
/* @0x2e32a0 vadd.f32 s31, s12, s31 */
/* @0x2e32a4 vldr s12, [r4, #80] */
/* @0x2e32a8 vadd.f32 s14, s14, s9 */
/* @0x2e32ac vsub.f32 s14, s31, s14 */
/* @0x2e32b0 vnmls.f32 s30, s15, s8 */
/* @0x2e32b4 vadd.f32 s13, s13, s10 */
/* @0x2e32b8 vadd.f32 s25, s11, s25 */
/* @0x2e32bc vmul.f32 s14, s29, s14 */
/* @0x2e32c0 vsub.f32 s13, s25, s13 */
/* @0x2e32c4 vmla.f32 s14, s30, s13 */
/* @0x2e32c8 vsub.f32 s28, s14, s28 */
/* @0x2e32cc vneg.f32 s30, s30 */
/* @0x2e32d0 vsub.f32 s28, s28, s12 */
/* @0x2e32d4 vneg.f32 s29, s29 */
/* @0x2e32d8 b 0x2e3134 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x1e8> */
/* @0x2e32dc vldr s10, [r4, #28] */
/* @0x2e32e0 vldr s25, [r10, #4] */
/* @0x2e32e4 vmul.f32 s9, s17, s10 */
/* @0x2e32e8 vldr s7, [r4, #24] */
/* @0x2e32ec vldr s8, [r10] */
/* @0x2e32f0 vldr s30, [r4, #20] */
/* @0x2e32f4 vldr s28, [r4, #76] */
/* @0x2e32f8 vmul.f32 s31, s15, s25 */
/* @0x2e32fc vmul.f32 s10, s18, s10 */
/* @0x2e3300 vmla.f32 s9, s18, s7 */
/* @0x2e3304 vmul.f32 s25, s16, s25 */
/* @0x2e3308 vmla.f32 s31, s16, s8 */
/* @0x2e330c vmul.f32 s29, s17, s30 */
/* @0x2e3310 vnmls.f32 s25, s15, s8 */
/* @0x2e3314 vldr s15, [r4, #16] */
/* @0x2e3318 vnmls.f32 s10, s17, s7 */
/* @0x2e331c vmul.f32 s30, s18, s30 */
/* @0x2e3320 vmla.f32 s29, s18, s15 */
/* @0x2e3324 vadd.f32 s31, s14, s31 */
/* @0x2e3328 vldr s14, [r4, #80] */
/* @0x2e332c vadd.f32 s12, s12, s9 */
/* @0x2e3330 vsub.f32 s12, s31, s12 */
/* @0x2e3334 vnmls.f32 s30, s17, s15 */
/* @0x2e3338 vadd.f32 s11, s11, s10 */
/* @0x2e333c vadd.f32 s25, s13, s25 */
/* @0x2e3340 vmul.f32 s12, s29, s12 */
/* @0x2e3344 vsub.f32 s11, s25, s11 */
/* @0x2e3348 vmla.f32 s12, s30, s11 */
/* @0x2e334c vsub.f32 s28, s12, s28 */
/* @0x2e3350 vsub.f32 s28, s28, s14 */
/* @0x2e3354 b 0x2e3134 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x1e8> */
/* @0x2e3358 andeq r0, r0, r0 */
/* @0x2e335c cdplt p12, #0x4, c12, c12, c13, #0x6 */
/* @0x2e3360 ldcllt p2, c12, [r5], #-572 */
/* @0x2e3364 ldr r1, [r7, #0x18] */
/* @0x2e3368 ldr r0, [r7, #0x30] */
/* @0x2e336c add r2, r1, r9 */
/* @0x2e3370 add r3, r1, r8 */
/* @0x2e3374 add r6, r6, #1 */
/* @0x2e3378 vstr s24, [r2] */
/* @0x2e337c cmp r0, r6 */
/* @0x2e3380 vstr s23, [r2, #4] */
/* @0x2e3384 vstr s22, [r2, #8] */
/* @0x2e3388 vstr s21, [r3] */
/* @0x2e338c vstr s20, [r3, #4] */
/* @0x2e3390 vstr s19, [r3, #8] */
/* @0x2e3394 bgt 0x2e2f74 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x28> */
/* @0x2e3398 vldr s15, [pc, #-64] */
/* @0x2e339c vcmpe.f32 s27, s15 */
/* @0x2e33a0 vmrs APSR_nzcv, fpscr */
/* @0x2e33a4 movlt r0, #0 */
/* @0x2e33a8 movge r0, #1 */
/* @0x2e33ac add sp, sp, #36 */
/* @0x2e33b0 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2e33b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e33b8 mov r0, #1 */
/* @0x2e33bc add sp, sp, #36 */
/* @0x2e33c0 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2e33c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e33c8 vmov r0, s28 */
/* @0x2e33cc bl 0xb6700 <sqrtf@plt> */
/* @0x2e33d0 vmov s15, r0 */
/* @0x2e33d4 b 0x2e31f8 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x2ac> */

/* ── FUNC 0x2e33d8 · b2ContactSolver::SolveTOIPositionConstraints(int, int) · size=1228 · insn=307 */
/* @0x2e33d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e33dc vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2e33e0 mov r6, r0 */
/* @0x2e33e4 ldr r0, [r0, #0x30] */
/* @0x2e33e8 sub sp, sp, #44 */
/* @0x2e33ec cmp r0, #0 */
/* @0x2e33f0 str r1, [sp, #0x20] */
/* @0x2e33f4 str r2, [sp, #0x24] */
/* @0x2e33f8 ble 0x2e3884 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x4ac> */
/* @0x2e33fc ldr r12, [r6, #0x18] */
/* @0x2e3400 mov r5, #0 */
/* @0x2e3404 vldr s29, [pc, #924] */
/* @0x2e3408 ldr r3, [r6, #0x24] */
/* @0x2e340c mov r2, #88 */
/* @0x2e3410 mla r10, r2, r5, r3 */
/* @0x2e3414 vldr s10, [r10, #52] */
/* @0x2e3418 ldr r3, [sp, #0x20] */
/* @0x2e341c vldr s7, [r10, #48] */
/* @0x2e3420 ldr r2, [sp, #0x24] */
/* @0x2e3424 vstr s7, [sp, #24] */
/* @0x2e3428 vstr s10, [sp, #20] */
/* @0x2e342c vldr s13, [r10, #56] */
/* @0x2e3430 vstr s13, [sp, #16] */
/* @0x2e3434 vldr s14, [r10, #60] */
/* @0x2e3438 vstr s14, [sp, #12] */
/* @0x2e343c ldr r8, [r10, #0x20] */
/* @0x2e3440 ldr r7, [r10, #0x24] */
/* @0x2e3444 cmp r8, r2 */
/* @0x2e3448 cmpne r8, r3 */
/* @0x2e344c ldr r2, [sp, #0x24] */
/* @0x2e3450 ldr r3, [sp, #0x20] */
/* @0x2e3454 vldreq s7, [r10, #64] */
/* @0x2e3458 ldr r4, [r10, #0x54] */
/* @0x2e345c vldrne s10, [pc, #836] */
/* @0x2e3460 vstreq s7, [sp, #4] */
/* @0x2e3464 vldreq s26, [r10, #40] */
/* @0x2e3468 vstrne s10, [sp, #4] */
/* @0x2e346c vmovne.f32 s26, s10 */
/* @0x2e3470 add r8, r8, r8, lsl #1 */
/* @0x2e3474 cmp r7, r2 */
/* @0x2e3478 cmpne r7, r3 */
/* @0x2e347c add r7, r7, r7, lsl #1 */
/* @0x2e3480 vldrne s13, [pc, #800] */
/* @0x2e3484 vldreq s7, [r10, #44] */
/* @0x2e3488 vldreq s10, [r10, #68] */
/* @0x2e348c vstreq s7, [sp] */
/* @0x2e3490 vstreq s10, [sp, #8] */
/* @0x2e3494 vstrne s13, [sp, #8] */
/* @0x2e3498 vstrne s13, [sp] */
/* @0x2e349c cmp r4, #0 */
/* @0x2e34a0 lsl r8, r8, #2 */
/* @0x2e34a4 lsl r7, r7, #2 */
/* @0x2e34a8 add r1, r12, r8 */
/* @0x2e34ac add r2, r12, r7 */
/* @0x2e34b0 vldr s24, [r1] */
/* @0x2e34b4 vldr s23, [r1, #4] */
/* @0x2e34b8 vldr s22, [r1, #8] */
/* @0x2e34bc vldr s21, [r2] */
/* @0x2e34c0 vldr s20, [r2, #4] */
/* @0x2e34c4 vldr s19, [r2, #8] */
/* @0x2e34c8 ble 0x2e3840 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x468> */
/* @0x2e34cc vldr s14, [sp] */
/* @0x2e34d0 vadd.f32 s14, s26, s14 */
/* @0x2e34d4 mov r9, r10 */
/* @0x2e34d8 mov r11, #0 */
/* @0x2e34dc vstr s14, [sp, #28] */
/* @0x2e34e0 b 0x2e3578 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x1a0> */
/* @0x2e34e4 vldr s15, [pc, #700] */
/* @0x2e34e8 vmul.f32 s13, s11, s27 */
/* @0x2e34ec vldr s7, [sp, #4] */
/* @0x2e34f0 add r11, r11, #1 */
/* @0x2e34f4 add r9, r9, #8 */
/* @0x2e34f8 vnmls.f32 s13, s9, s31 */
/* @0x2e34fc vmul.f32 s14, s12, s27 */
/* @0x2e3500 vmul.f32 s8, s7, s13 */
/* @0x2e3504 vldr s7, [sp, #28] */
/* @0x2e3508 vnmls.f32 s14, s10, s31 */
/* @0x2e350c vmla.f32 s7, s8, s13 */
/* @0x2e3510 vmov.f32 s13, s7 */
/* @0x2e3514 vldr s7, [sp, #8] */
/* @0x2e3518 vmul.f32 s8, s7, s14 */
/* @0x2e351c vldr s7, [sp] */
/* @0x2e3520 vmla.f32 s13, s8, s14 */
/* @0x2e3524 vcmpe.f32 s13, #0 */
/* @0x2e3528 vmrs APSR_nzcv, fpscr */
/* @0x2e352c vneggt.f32 s15, s15 */
/* @0x2e3530 vldrle s15, [pc, #624] */
/* @0x2e3534 vdivgt.f32 s15, s15, s13 */
/* @0x2e3538 cmp r11, r4 */
/* @0x2e353c vldr s13, [sp, #8] */
/* @0x2e3540 vmul.f32 s14, s15, s27 */
/* @0x2e3544 vmul.f32 s15, s15, s31 */
/* @0x2e3548 vmul.f32 s11, s11, s14 */
/* @0x2e354c vmul.f32 s12, s12, s14 */
/* @0x2e3550 vnmls.f32 s11, s9, s15 */
/* @0x2e3554 vnmls.f32 s12, s10, s15 */
/* @0x2e3558 vldr s10, [sp, #4] */
/* @0x2e355c vmla.f32 s19, s13, s12 */
/* @0x2e3560 vmls.f32 s22, s10, s11 */
/* @0x2e3564 vmls.f32 s24, s26, s14 */
/* @0x2e3568 vmls.f32 s23, s26, s15 */
/* @0x2e356c vmla.f32 s21, s7, s14 */
/* @0x2e3570 vmla.f32 s20, s7, s15 */
/* @0x2e3574 beq 0x2e3830 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x458> */
/* @0x2e3578 vmov r0, s22 */
/* @0x2e357c bl 0xb6580 <sinf@plt> */
/* @0x2e3580 vmov s18, r0 */
/* @0x2e3584 vmov r0, s22 */
/* @0x2e3588 bl 0xb658c <cosf@plt> */
/* @0x2e358c vmov s17, r0 */
/* @0x2e3590 vmov r0, s19 */
/* @0x2e3594 bl 0xb6580 <sinf@plt> */
/* @0x2e3598 vmov s16, r0 */
/* @0x2e359c vmov r0, s19 */
/* @0x2e35a0 bl 0xb658c <cosf@plt> */
/* @0x2e35a4 vldr s7, [sp, #20] */
/* @0x2e35a8 vldr s10, [sp, #12] */
/* @0x2e35ac vmul.f32 s11, s7, s18 */
/* @0x2e35b0 ldr r2, [r10, #0x48] */
/* @0x2e35b4 cmp r2, #1 */
/* @0x2e35b8 vmul.f32 s12, s7, s17 */
/* @0x2e35bc vldr s7, [sp, #24] */
/* @0x2e35c0 vmul.f32 s13, s10, s16 */
/* @0x2e35c4 vmov s15, r0 */
/* @0x2e35c8 vmul.f32 s14, s10, s15 */
/* @0x2e35cc vldr s10, [sp, #16] */
/* @0x2e35d0 vnmls.f32 s11, s7, s17 */
/* @0x2e35d4 vmla.f32 s12, s7, s18 */
/* @0x2e35d8 vnmls.f32 s13, s10, s15 */
/* @0x2e35dc vmla.f32 s14, s10, s16 */
/* @0x2e35e0 vsub.f32 s11, s24, s11 */
/* @0x2e35e4 vsub.f32 s12, s23, s12 */
/* @0x2e35e8 vsub.f32 s13, s21, s13 */
/* @0x2e35ec vsub.f32 s14, s20, s14 */
/* @0x2e35f0 beq 0x2e37b4 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x3dc> */
/* @0x2e35f4 cmp r2, #2 */
/* @0x2e35f8 beq 0x2e3724 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x34c> */
/* @0x2e35fc cmp r2, #0 */
/* @0x2e3600 beq 0x2e3660 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x288> */
/* @0x2e3604 movw r3, #0xd70a */
/* @0x2e3608 movt r3, #0x3ba3 */
/* @0x2e360c vmov.f32 s15, #7.500000e-01 */
/* @0x2e3610 vmov s7, r3 */
/* @0x2e3614 vadd.f32 s14, s30, s7 */
/* @0x2e3618 vmul.f32 s15, s14, s15 */
/* @0x2e361c vcmpe.f32 s30, s29 */
/* @0x2e3620 vmrs APSR_nzcv, fpscr */
/* @0x2e3624 vcmpe.f32 s15, #0 */
/* @0x2e3628 vmovle.f32 s29, s30 */
/* @0x2e362c vmrs APSR_nzcv, fpscr */
/* @0x2e3630 vsub.f32 s9, s25, s24 */
/* @0x2e3634 vsub.f32 s11, s28, s23 */
/* @0x2e3638 vsub.f32 s10, s25, s21 */
/* @0x2e363c vsub.f32 s12, s28, s20 */
/* @0x2e3640 bpl 0x2e34e4 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x10c> */
/* @0x2e3644 movw r2, #0xcccd */
/* @0x2e3648 movt r2, #0xbe4c */
/* @0x2e364c vmov s7, r2 */
/* @0x2e3650 vcmpe.f32 s15, s7 */
/* @0x2e3654 vmrs APSR_nzcv, fpscr */
/* @0x2e3658 vldrmi s15, [pc, #332] */
/* @0x2e365c b 0x2e34e8 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x110> */
/* @0x2e3660 vldr s25, [r10, #28] */
/* @0x2e3664 vldr s10, [r10, #4] */
/* @0x2e3668 vmul.f32 s28, s17, s25 */
/* @0x2e366c vldr s7, [r10, #24] */
/* @0x2e3670 vldr s8, [r10] */
/* @0x2e3674 vmul.f32 s9, s15, s10 */
/* @0x2e3678 vmul.f32 s25, s18, s25 */
/* @0x2e367c vmul.f32 s10, s16, s10 */
/* @0x2e3680 vmla.f32 s28, s18, s7 */
/* @0x2e3684 vmla.f32 s9, s16, s8 */
/* @0x2e3688 vnmls.f32 s25, s17, s7 */
/* @0x2e368c vnmls.f32 s10, s15, s8 */
/* @0x2e3690 vadd.f32 s28, s12, s28 */
/* @0x2e3694 vadd.f32 s16, s14, s9 */
/* @0x2e3698 vsub.f32 s31, s16, s28 */
/* @0x2e369c vadd.f32 s25, s11, s25 */
/* @0x2e36a0 vadd.f32 s17, s13, s10 */
/* @0x2e36a4 vmul.f32 s30, s31, s31 */
/* @0x2e36a8 vsub.f32 s27, s17, s25 */
/* @0x2e36ac vmla.f32 s30, s27, s27 */
/* @0x2e36b0 vsqrt.f32 s15, s30 */
/* @0x2e36b4 vcmp.f32 s15, s15 */
/* @0x2e36b8 vmrs APSR_nzcv, fpscr */
/* @0x2e36bc bne 0x2e3894 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x4bc> */
/* @0x2e36c0 mov r2, #872415232 */
/* @0x2e36c4 vmov s7, r2 */
/* @0x2e36c8 vcmpe.f32 s15, s7 */
/* @0x2e36cc vmrs APSR_nzcv, fpscr */
/* @0x2e36d0 bmi 0x2e36f8 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x320> */
/* @0x2e36d4 mov r2, #1065353216 */
/* @0x2e36d8 vmov s7, r2 */
/* @0x2e36dc vdiv.f32 s15, s7, s15 */
/* @0x2e36e0 vmul.f32 s14, s31, s15 */
/* @0x2e36e4 vmul.f32 s15, s27, s15 */
/* @0x2e36e8 vmul.f32 s30, s31, s14 */
/* @0x2e36ec vmov.f32 s31, s14 */
/* @0x2e36f0 vmla.f32 s30, s27, s15 */
/* @0x2e36f4 vmov.f32 s27, s15 */
/* @0x2e36f8 vldr s14, [r10, #76] */
/* @0x2e36fc mov r2, #1056964608 */
/* @0x2e3700 vmov s7, r2 */
/* @0x2e3704 vldr s15, [r10, #80] */
/* @0x2e3708 vadd.f32 s25, s25, s17 */
/* @0x2e370c vadd.f32 s28, s28, s16 */
/* @0x2e3710 vsub.f32 s30, s30, s14 */
/* @0x2e3714 vmul.f32 s25, s25, s7 */
/* @0x2e3718 vmul.f32 s28, s28, s7 */
/* @0x2e371c vsub.f32 s30, s30, s15 */
/* @0x2e3720 b 0x2e3604 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x22c> */
/* @0x2e3724 vldr s10, [r10, #28] */
/* @0x2e3728 vldr s25, [r9, #4] */
/* @0x2e372c vmul.f32 s9, s15, s10 */
/* @0x2e3730 vldr s8, [r9] */
/* @0x2e3734 vldr s7, [r10, #24] */
/* @0x2e3738 vldr s27, [r10, #20] */
/* @0x2e373c vldr s30, [r10, #76] */
/* @0x2e3740 vmul.f32 s28, s17, s25 */
/* @0x2e3744 vmul.f32 s10, s16, s10 */
/* @0x2e3748 vmla.f32 s28, s18, s8 */
/* @0x2e374c vmla.f32 s9, s16, s7 */
/* @0x2e3750 vmul.f32 s25, s18, s25 */
/* @0x2e3754 vmul.f32 s31, s15, s27 */
/* @0x2e3758 vnmls.f32 s25, s17, s8 */
/* @0x2e375c vldr s8, [r10, #16] */
/* @0x2e3760 vnmls.f32 s10, s15, s7 */
/* @0x2e3764 vmla.f32 s31, s16, s8 */
/* @0x2e3768 vmul.f32 s27, s16, s27 */
/* @0x2e376c vadd.f32 s28, s12, s28 */
/* @0x2e3770 vldr s12, [r10, #80] */
/* @0x2e3774 vadd.f32 s14, s14, s9 */
/* @0x2e3778 vsub.f32 s14, s28, s14 */
/* @0x2e377c vnmls.f32 s27, s15, s8 */
/* @0x2e3780 vadd.f32 s13, s13, s10 */
/* @0x2e3784 vadd.f32 s25, s11, s25 */
/* @0x2e3788 vmul.f32 s14, s31, s14 */
/* @0x2e378c vsub.f32 s13, s25, s13 */
/* @0x2e3790 vmla.f32 s14, s27, s13 */
/* @0x2e3794 vsub.f32 s30, s14, s30 */
/* @0x2e3798 vneg.f32 s27, s27 */
/* @0x2e379c vsub.f32 s30, s30, s12 */
/* @0x2e37a0 vneg.f32 s31, s31 */
/* @0x2e37a4 b 0x2e3604 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x22c> */
/* @0x2e37a8 andeq r0, r0, r0 */
/* @0x2e37ac cdplt p12, #0x4, c12, c12, c13, #0x6 */
/* @0x2e37b0 bllt 0x541f4 */
/* @0x2e37b4 vldr s10, [r10, #28] */
/* @0x2e37b8 vldr s25, [r9, #4] */
/* @0x2e37bc vmul.f32 s9, s17, s10 */
/* @0x2e37c0 vldr s7, [r10, #24] */
/* @0x2e37c4 vldr s8, [r9] */
/* @0x2e37c8 vldr s27, [r10, #20] */
/* @0x2e37cc vldr s30, [r10, #76] */
/* @0x2e37d0 vmul.f32 s28, s15, s25 */
/* @0x2e37d4 vmul.f32 s10, s18, s10 */
/* @0x2e37d8 vmla.f32 s9, s18, s7 */
/* @0x2e37dc vmul.f32 s25, s16, s25 */
/* @0x2e37e0 vmla.f32 s28, s16, s8 */
/* @0x2e37e4 vmul.f32 s31, s17, s27 */
/* @0x2e37e8 vnmls.f32 s25, s15, s8 */
/* @0x2e37ec vldr s15, [r10, #16] */
/* @0x2e37f0 vnmls.f32 s10, s17, s7 */
/* @0x2e37f4 vmul.f32 s27, s18, s27 */
/* @0x2e37f8 vmla.f32 s31, s18, s15 */
/* @0x2e37fc vadd.f32 s28, s14, s28 */
/* @0x2e3800 vldr s14, [r10, #80] */
/* @0x2e3804 vadd.f32 s12, s12, s9 */
/* @0x2e3808 vsub.f32 s12, s28, s12 */
/* @0x2e380c vnmls.f32 s27, s17, s15 */
/* @0x2e3810 vadd.f32 s11, s11, s10 */
/* @0x2e3814 vadd.f32 s25, s13, s25 */
/* @0x2e3818 vmul.f32 s12, s31, s12 */
/* @0x2e381c vsub.f32 s11, s25, s11 */
/* @0x2e3820 vmla.f32 s12, s27, s11 */
/* @0x2e3824 vsub.f32 s30, s12, s30 */
/* @0x2e3828 vsub.f32 s30, s30, s14 */
/* @0x2e382c b 0x2e3604 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x22c> */
/* @0x2e3830 ldr r12, [r6, #0x18] */
/* @0x2e3834 ldr r0, [r6, #0x30] */
/* @0x2e3838 add r1, r12, r8 */
/* @0x2e383c add r2, r12, r7 */
/* @0x2e3840 add r5, r5, #1 */
/* @0x2e3844 vstr s24, [r1] */
/* @0x2e3848 cmp r0, r5 */
/* @0x2e384c vstr s23, [r1, #4] */
/* @0x2e3850 vstr s22, [r1, #8] */
/* @0x2e3854 vstr s21, [r2] */
/* @0x2e3858 vstr s20, [r2, #4] */
/* @0x2e385c vstr s19, [r2, #8] */
/* @0x2e3860 bgt 0x2e3408 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x30> */
/* @0x2e3864 vldr s15, [pc, #-188] */
/* @0x2e3868 vcmpe.f32 s29, s15 */
/* @0x2e386c vmrs APSR_nzcv, fpscr */
/* @0x2e3870 movlt r0, #0 */
/* @0x2e3874 movge r0, #1 */
/* @0x2e3878 add sp, sp, #44 */
/* @0x2e387c vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2e3880 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e3884 mov r0, #1 */
/* @0x2e3888 add sp, sp, #44 */
/* @0x2e388c vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2e3890 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e3894 vmov r0, s30 */
/* @0x2e3898 bl 0xb6700 <sqrtf@plt> */
/* @0x2e389c vmov s15, r0 */
/* @0x2e38a0 b 0x2e36c0 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x2e8> */

/* ── FUNC 0x2e38a4 · b2GearJoint::SolveVelocityConstraints(b2SolverData const&) · size=392 · insn=98 */
/* @0x2e38a4 str r4, [sp, #-0x4]! */
/* @0x2e38a8 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2e38ac vldr s13, [r0, #244] */
/* @0x2e38b0 vldr s15, [r0, #252] */
/* @0x2e38b4 ldr r4, [r1, #0x1c] */
/* @0x2e38b8 vldr s3, [r0, #264] */
/* @0x2e38bc ldr r12, [r0, #0xa0] */
/* @0x2e38c0 vldr s7, [r0, #268] */
/* @0x2e38c4 ldr r2, [r0, #0xa8] */
/* @0x2e38c8 vldr s12, [r0, #240] */
/* @0x2e38cc ldr r1, [r0, #0xa4] */
/* @0x2e38d0 vldr s14, [r0, #248] */
/* @0x2e38d4 ldr r3, [r0, #0xac] */
/* @0x2e38d8 add r12, r12, r12, lsl #1 */
/* @0x2e38dc add r2, r2, r2, lsl #1 */
/* @0x2e38e0 vldr s23, [r0, #256] */
/* @0x2e38e4 add r1, r1, r1, lsl #1 */
/* @0x2e38e8 add r12, r4, r12, lsl #2 */
/* @0x2e38ec add r3, r3, r3, lsl #1 */
/* @0x2e38f0 add r2, r4, r2, lsl #2 */
/* @0x2e38f4 add r1, r4, r1, lsl #2 */
/* @0x2e38f8 vldr s20, [r12, #4] */
/* @0x2e38fc add r3, r4, r3, lsl #2 */
/* @0x2e3900 vldr s1, [r2, #4] */
/* @0x2e3904 vldr s18, [r1, #4] */
/* @0x2e3908 vsub.f32 s8, s20, s1 */
/* @0x2e390c vldr s5, [r3, #4] */
/* @0x2e3910 vldr s2, [r2, #8] */
/* @0x2e3914 vldr s6, [r3, #8] */
/* @0x2e3918 vldr s21, [r12] */
/* @0x2e391c vldr s0, [r2] */
/* @0x2e3920 vldr s19, [r1] */
/* @0x2e3924 vldr s4, [r3] */
/* @0x2e3928 vldr s17, [r0, #260] */
/* @0x2e392c vldr s22, [r12, #8] */
/* @0x2e3930 vldr s16, [r1, #8] */
/* @0x2e3934 vldr s29, [r0, #272] */
/* @0x2e3938 vldr s28, [r0, #224] */
/* @0x2e393c vldr s27, [r0, #208] */
/* @0x2e3940 vldr s26, [r0, #212] */
/* @0x2e3944 vldr s25, [r0, #228] */
/* @0x2e3948 vldr s24, [r0, #216] */
/* @0x2e394c vsub.f32 s9, s18, s5 */
/* @0x2e3950 vmul.f32 s10, s3, s2 */
/* @0x2e3954 vmul.f32 s11, s7, s6 */
/* @0x2e3958 vmul.f32 s8, s8, s13 */
/* @0x2e395c vmul.f32 s9, s9, s15 */
/* @0x2e3960 vsub.f32 s31, s21, s0 */
/* @0x2e3964 vsub.f32 s30, s19, s4 */
/* @0x2e3968 vnmls.f32 s10, s23, s22 */
/* @0x2e396c vmla.f32 s8, s31, s12 */
/* @0x2e3970 vnmls.f32 s11, s17, s16 */
/* @0x2e3974 vmla.f32 s9, s30, s14 */
/* @0x2e3978 vadd.f32 s11, s10, s11 */
/* @0x2e397c vldr s10, [r0, #220] */
/* @0x2e3980 vadd.f32 s9, s8, s9 */
/* @0x2e3984 vldr s8, [r0, #232] */
/* @0x2e3988 vadd.f32 s9, s11, s9 */
/* @0x2e398c vnmul.f32 s29, s29, s9 */
/* @0x2e3990 vmul.f32 s27, s29, s27 */
/* @0x2e3994 vmul.f32 s26, s29, s26 */
/* @0x2e3998 vmul.f32 s28, s29, s28 */
/* @0x2e399c vmul.f32 s25, s29, s25 */
/* @0x2e39a0 vmul.f32 s24, s29, s24 */
/* @0x2e39a4 vmul.f32 s11, s29, s10 */
/* @0x2e39a8 vmul.f32 s9, s29, s8 */
/* @0x2e39ac vldr s8, [r0, #236] */
/* @0x2e39b0 vmul.f32 s10, s29, s8 */
/* @0x2e39b4 vmla.f32 s22, s23, s28 */
/* @0x2e39b8 vmla.f32 s21, s27, s12 */
/* @0x2e39bc vmla.f32 s20, s27, s13 */
/* @0x2e39c0 vmla.f32 s19, s26, s14 */
/* @0x2e39c4 vmla.f32 s18, s26, s15 */
/* @0x2e39c8 vmla.f32 s16, s17, s25 */
/* @0x2e39cc vmls.f32 s0, s24, s12 */
/* @0x2e39d0 vmls.f32 s1, s24, s13 */
/* @0x2e39d4 vmls.f32 s6, s7, s10 */
/* @0x2e39d8 vldr s10, [r0, #156] */
/* @0x2e39dc vmls.f32 s2, s3, s9 */
/* @0x2e39e0 vmls.f32 s4, s11, s14 */
/* @0x2e39e4 vmls.f32 s5, s11, s15 */
/* @0x2e39e8 vadd.f32 s29, s10, s29 */
/* @0x2e39ec vstr s29, [r0, #156] */
/* @0x2e39f0 vstr s21, [r12] */
/* @0x2e39f4 vstr s22, [r12, #8] */
/* @0x2e39f8 vstr s20, [r12, #4] */
/* @0x2e39fc vstr s19, [r1] */
/* @0x2e3a00 vstr s18, [r1, #4] */
/* @0x2e3a04 vstr s16, [r1, #8] */
/* @0x2e3a08 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2e3a0c vstr s0, [r2] */
/* @0x2e3a10 vstr s1, [r2, #4] */
/* @0x2e3a14 vstr s2, [r2, #8] */
/* @0x2e3a18 vstr s4, [r3] */
/* @0x2e3a1c vstr s5, [r3, #4] */
/* @0x2e3a20 vstr s6, [r3, #8] */
/* @0x2e3a24 ldr r4, [sp], #4 */
/* @0x2e3a28 bx lr */

/* ── FUNC 0x2e3a2c · b2GearJoint::GetAnchorA() const · size=64 · insn=16 */
/* @0x2e3a2c ldr r3, [r1, #0x30] */
/* @0x2e3a30 vldr s15, [r1, #96] */
/* @0x2e3a34 vldr s12, [r3, #24] */
/* @0x2e3a38 vldr s11, [r3, #20] */
/* @0x2e3a3c vmul.f32 s14, s12, s15 */
/* @0x2e3a40 vldr s13, [r1, #92] */
/* @0x2e3a44 vldr s9, [r3, #16] */
/* @0x2e3a48 vldr s10, [r3, #12] */
/* @0x2e3a4c vmul.f32 s15, s11, s15 */
/* @0x2e3a50 vmla.f32 s14, s13, s11 */
/* @0x2e3a54 vnmls.f32 s15, s12, s13 */
/* @0x2e3a58 vadd.f32 s14, s14, s9 */
/* @0x2e3a5c vadd.f32 s15, s15, s10 */
/* @0x2e3a60 vstr s14, [r0, #4] */
/* @0x2e3a64 vstr s15, [r0] */
/* @0x2e3a68 bx lr */

/* ── FUNC 0x2e3a6c · b2GearJoint::GetAnchorB() const · size=64 · insn=16 */
/* @0x2e3a6c ldr r3, [r1, #0x34] */
/* @0x2e3a70 vldr s15, [r1, #104] */
/* @0x2e3a74 vldr s12, [r3, #24] */
/* @0x2e3a78 vldr s11, [r3, #20] */
/* @0x2e3a7c vmul.f32 s14, s12, s15 */
/* @0x2e3a80 vldr s13, [r1, #100] */
/* @0x2e3a84 vldr s9, [r3, #16] */
/* @0x2e3a88 vldr s10, [r3, #12] */
/* @0x2e3a8c vmul.f32 s15, s11, s15 */
/* @0x2e3a90 vmla.f32 s14, s13, s11 */
/* @0x2e3a94 vnmls.f32 s15, s12, s13 */
/* @0x2e3a98 vadd.f32 s14, s14, s9 */
/* @0x2e3a9c vadd.f32 s15, s15, s10 */
/* @0x2e3aa0 vstr s14, [r0, #4] */
/* @0x2e3aa4 vstr s15, [r0] */
/* @0x2e3aa8 bx lr */

/* ── FUNC 0x2e3aac · b2GearJoint::GetReactionForce(float) const · size=44 · insn=11 */
/* @0x2e3aac vldr s14, [r1, #156] */
/* @0x2e3ab0 vldr s13, [r1, #244] */
/* @0x2e3ab4 vldr s12, [r1, #240] */
/* @0x2e3ab8 vmul.f32 s13, s14, s13 */
/* @0x2e3abc vmov s15, r2 */
/* @0x2e3ac0 vmul.f32 s14, s14, s12 */
/* @0x2e3ac4 vmul.f32 s13, s15, s13 */
/* @0x2e3ac8 vmul.f32 s15, s15, s14 */
/* @0x2e3acc vstr s13, [r0, #4] */
/* @0x2e3ad0 vstr s15, [r0] */
/* @0x2e3ad4 bx lr */

/* ── FUNC 0x2e3ad8 · b2GearJoint::GetReactionTorque(float) const · size=28 · insn=7 */
/* @0x2e3ad8 vldr s14, [r0, #156] */
/* @0x2e3adc vldr s15, [r0, #256] */
/* @0x2e3ae0 vmul.f32 s15, s14, s15 */
/* @0x2e3ae4 vmov s14, r1 */
/* @0x2e3ae8 vmul.f32 s14, s14, s15 */
/* @0x2e3aec vmov r0, s14 */
/* @0x2e3af0 bx lr */

/* ── FUNC 0x2e3af4 · b2GearJoint::~b2GearJoint() · size=24 · insn=6 */
/* @0x2e3af4 ldr r3, [pc, #0xc] */
/* @0x2e3af8 ldr r3, [pc, r3] */
/* @0x2e3afc add r3, r3, #8 */
/* @0x2e3b00 str r3, [r0] */
/* @0x2e3b04 bx lr */
/* @0x2e3b08 andseq lr, r0, r12, asr r0 */

/* ── FUNC 0x2e3af4 · b2GearJoint::~b2GearJoint() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2e3b0c · b2GearJoint::Dump() · size=208 · insn=52 */
/* @0x2e3b0c push {r4, r5, r6, r7, r8, lr} */
/* @0x2e3b10 mov r4, r0 */
/* @0x2e3b14 ldr r3, [r4, #0x30] */
/* @0x2e3b18 ldr r2, [r4, #0x44] */
/* @0x2e3b1c ldr r1, [r4, #0x34] */
/* @0x2e3b20 ldr r8, [r3, #0x8] */
/* @0x2e3b24 ldr r0, [pc, #0x90] */
/* @0x2e3b28 ldr r3, [r4, #0x48] */
/* @0x2e3b2c add r0, pc, r0 */
/* @0x2e3b30 ldr r6, [r2, #0x38] */
/* @0x2e3b34 ldr r7, [r1, #0x8] */
/* @0x2e3b38 ldr r5, [r3, #0x38] */
/* @0x2e3b3c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2e3b40 ldr r0, [pc, #0x78] */
/* @0x2e3b44 mov r1, r8 */
/* @0x2e3b48 add r0, pc, r0 */
/* @0x2e3b4c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2e3b50 ldr r0, [pc, #0x6c] */
/* @0x2e3b54 mov r1, r7 */
/* @0x2e3b58 add r0, pc, r0 */
/* @0x2e3b5c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2e3b60 ldr r0, [pc, #0x60] */
/* @0x2e3b64 ldrb r1, [r4, #0x3d] */
/* @0x2e3b68 add r0, pc, r0 */
/* @0x2e3b6c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2e3b70 ldr r0, [pc, #0x54] */
/* @0x2e3b74 mov r1, r6 */
/* @0x2e3b78 add r0, pc, r0 */
/* @0x2e3b7c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2e3b80 ldr r0, [pc, #0x48] */
/* @0x2e3b84 mov r1, r5 */
/* @0x2e3b88 add r0, pc, r0 */
/* @0x2e3b8c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2e3b90 vldr s15, [r4, #152] */
/* @0x2e3b94 vcvt.f64.f32 d6, s15 */
/* @0x2e3b98 ldr r0, [pc, #0x34] */
/* @0x2e3b9c add r0, pc, r0 */
/* @0x2e3ba0 vmov r2, r3, d6 */
/* @0x2e3ba4 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2e3ba8 ldr r0, [pc, #0x28] */
/* @0x2e3bac ldr r1, [r4, #0x38] */
/* @0x2e3bb0 add r0, pc, r0 */
/* @0x2e3bb4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x2e3bb8 b 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2e3bbc andeq r8, r7, r12, ror r8 */
/* @0x2e3bc0 andeq r8, r7, r4, ror #6 */
/* @0x2e3bc4 andeq r8, r7, r0, ror r3 */
/* @0x2e3bc8 andeq r8, r7, r12, ror r3 */
/* @0x2e3bcc andeq r8, r7, r8, asr #16 */
/* @0x2e3bd0 andeq r8, r7, r4, asr r8 */
/* @0x2e3bd4 andeq r8, r7, r12, lsl r7 */
/* @0x2e3bd8 andeq r8, r7, r8, lsl #8 */

/* ── FUNC 0x2e3bdc · b2GearJoint::~b2GearJoint() · size=40 · insn=10 */
/* @0x2e3bdc ldr r3, [pc, #0x1c] */
/* @0x2e3be0 push {r4, lr} */
/* @0x2e3be4 ldr r3, [pc, r3] */
/* @0x2e3be8 mov r4, r0 */
/* @0x2e3bec add r3, r3, #8 */
/* @0x2e3bf0 str r3, [r0] */
/* @0x2e3bf4 bl 0x27d1d0 <_ZdlPv> */
/* @0x2e3bf8 mov r0, r4 */
/* @0x2e3bfc pop {r4, pc} */
/* @0x2e3c00 andseq sp, r0, r0, ror pc */

/* ── FUNC 0x2e3c04 · b2GearJoint::SolvePositionConstraints(b2SolverData const&) · size=1120 · insn=280 */
/* @0x2e3c04 push {r4, r5, r6, r7, r8, lr} */
/* @0x2e3c08 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2e3c0c mov r4, r0 */
/* @0x2e3c10 ldr r8, [r0, #0xa0] */
/* @0x2e3c14 sub sp, sp, #32 */
/* @0x2e3c18 ldr r7, [r0, #0xa4] */
/* @0x2e3c1c ldr r6, [r0, #0xa8] */
/* @0x2e3c20 ldr r5, [r0, #0xac] */
/* @0x2e3c24 add r8, r8, r8, lsl #1 */
/* @0x2e3c28 ldr r3, [r1, #0x18] */
/* @0x2e3c2c add r7, r7, r7, lsl #1 */
/* @0x2e3c30 add r6, r6, r6, lsl #1 */
/* @0x2e3c34 add r5, r5, r5, lsl #1 */
/* @0x2e3c38 add r8, r3, r8, lsl #2 */
/* @0x2e3c3c vldr s22, [r8, #8] */
/* @0x2e3c40 vmov r0, s22 */
/* @0x2e3c44 add r7, r3, r7, lsl #2 */
/* @0x2e3c48 add r6, r3, r6, lsl #2 */
/* @0x2e3c4c add r5, r3, r5, lsl #2 */
/* @0x2e3c50 bl 0xb6580 <sinf@plt> */
/* @0x2e3c54 vldr s21, [r7, #8] */
/* @0x2e3c58 vmov s28, r0 */
/* @0x2e3c5c vmov r0, s22 */
/* @0x2e3c60 bl 0xb658c <cosf@plt> */
/* @0x2e3c64 vmov s27, r0 */
/* @0x2e3c68 vmov r0, s21 */
/* @0x2e3c6c bl 0xb6580 <sinf@plt> */
/* @0x2e3c70 vldr s20, [r6, #8] */
/* @0x2e3c74 vldr s19, [r5, #8] */
/* @0x2e3c78 vmov s24, r0 */
/* @0x2e3c7c vmov r0, s21 */
/* @0x2e3c80 bl 0xb658c <cosf@plt> */
/* @0x2e3c84 vmov s23, r0 */
/* @0x2e3c88 vmov r0, s20 */
/* @0x2e3c8c bl 0xb6580 <sinf@plt> */
/* @0x2e3c90 vmov s18, r0 */
/* @0x2e3c94 vmov r0, s20 */
/* @0x2e3c98 bl 0xb658c <cosf@plt> */
/* @0x2e3c9c vmov s17, r0 */
/* @0x2e3ca0 vmov r0, s19 */
/* @0x2e3ca4 bl 0xb6580 <sinf@plt> */
/* @0x2e3ca8 vmov s16, r0 */
/* @0x2e3cac vmov r0, s19 */
/* @0x2e3cb0 bl 0xb658c <cosf@plt> */
/* @0x2e3cb4 ldr r3, [r4, #0x4c] */
/* @0x2e3cb8 vldr s0, [r7, #4] */
/* @0x2e3cbc vldr s1, [r6] */
/* @0x2e3cc0 cmp r3, #1 */
/* @0x2e3cc4 vldr s3, [r6, #4] */
/* @0x2e3cc8 vldr s4, [r5] */
/* @0x2e3ccc vldr s29, [r8] */
/* @0x2e3cd0 vldr s26, [r8, #4] */
/* @0x2e3cd4 vldr s25, [r7] */
/* @0x2e3cd8 vstr s0, [sp, #8] */
/* @0x2e3cdc vstr s1, [sp, #4] */
/* @0x2e3ce0 vstr s3, [sp] */
/* @0x2e3ce4 vstr s4, [sp, #12] */
/* @0x2e3ce8 vldr s31, [r5, #4] */
/* @0x2e3cec vmov s12, r0 */
/* @0x2e3cf0 beq 0x2e3fc4 <_ZN11b2GearJoint24SolvePositionConstraintsERK12b2SolverData+0x3c0> */
/* @0x2e3cf4 vldr s15, [r4, #196] */
/* @0x2e3cf8 vldr s5, [r4, #112] */
/* @0x2e3cfc vsub.f32 s5, s5, s15 */
/* @0x2e3d00 vldr s6, [r4, #128] */
/* @0x2e3d04 vldr s10, [r4, #192] */
/* @0x2e3d08 vldr s7, [r4, #108] */
/* @0x2e3d0c vldr s15, [r4, #180] */
/* @0x2e3d10 vldr s13, [r4, #96] */
/* @0x2e3d14 vldr s8, [r4, #124] */
/* @0x2e3d18 vldr s9, [r4, #176] */
/* @0x2e3d1c vldr s3, [r4, #92] */
/* @0x2e3d20 vldr s2, [r4, #232] */
/* @0x2e3d24 vstr s2, [sp, #16] */
/* @0x2e3d28 vldr s0, [r4, #216] */
/* @0x2e3d2c vldr s30, [r4, #208] */
/* @0x2e3d30 ldr r3, [r4, #0x50] */
/* @0x2e3d34 vstr s30, [sp, #24] */
/* @0x2e3d38 vstr s0, [sp, #20] */
/* @0x2e3d3c cmp r3, #1 */
/* @0x2e3d40 vmul.f32 s11, s5, s17 */
/* @0x2e3d44 vmul.f32 s14, s6, s18 */
/* @0x2e3d48 vsub.f32 s7, s7, s10 */
/* @0x2e3d4c vsub.f32 s13, s13, s15 */
/* @0x2e3d50 vmul.f32 s4, s5, s18 */
/* @0x2e3d54 vnmls.f32 s14, s8, s17 */
/* @0x2e3d58 vmla.f32 s11, s7, s18 */
/* @0x2e3d5c vmul.f32 s15, s6, s17 */
/* @0x2e3d60 vmul.f32 s10, s13, s27 */
/* @0x2e3d64 vsub.f32 s3, s3, s9 */
/* @0x2e3d68 vldr s9, [pc, #752] */
/* @0x2e3d6c vmla.f32 s15, s8, s18 */
/* @0x2e3d70 vnmls.f32 s4, s7, s17 */
/* @0x2e3d74 vmul.f32 s13, s13, s28 */
/* @0x2e3d78 vmla.f32 s10, s3, s28 */
/* @0x2e3d7c vmul.f32 s11, s14, s11 */
/* @0x2e3d80 vnmls.f32 s13, s3, s27 */
/* @0x2e3d84 vldr s3, [sp] */
/* @0x2e3d88 vldr s27, [r4, #224] */
/* @0x2e3d8c vsub.f32 s1, s26, s3 */
/* @0x2e3d90 vnmls.f32 s11, s15, s4 */
/* @0x2e3d94 vldr s4, [sp, #4] */
/* @0x2e3d98 vadd.f32 s1, s10, s1 */
/* @0x2e3d9c vmul.f32 s10, s14, s10 */
/* @0x2e3da0 vsub.f32 s3, s29, s4 */
/* @0x2e3da4 vmul.f32 s4, s1, s17 */
/* @0x2e3da8 vnmls.f32 s10, s15, s13 */
/* @0x2e3dac vmul.f32 s2, s2, s11 */
/* @0x2e3db0 vadd.f32 s3, s13, s3 */
/* @0x2e3db4 vadd.f32 s28, s0, s30 */
/* @0x2e3db8 vmls.f32 s4, s18, s3 */
/* @0x2e3dbc vmul.f32 s18, s1, s18 */
/* @0x2e3dc0 vmla.f32 s28, s2, s11 */
/* @0x2e3dc4 vmul.f32 s13, s27, s10 */
/* @0x2e3dc8 vmla.f32 s18, s3, s17 */
/* @0x2e3dcc vsub.f32 s5, s4, s5 */
/* @0x2e3dd0 vmla.f32 s28, s13, s10 */
/* @0x2e3dd4 vmul.f32 s5, s6, s5 */
/* @0x2e3dd8 vsub.f32 s18, s18, s7 */
/* @0x2e3ddc vadd.f32 s28, s28, s9 */
/* @0x2e3de0 vmla.f32 s5, s8, s18 */
/* @0x2e3de4 beq 0x2e4018 <_ZN11b2GearJoint24SolvePositionConstraintsERK12b2SolverData+0x414> */
/* @0x2e3de8 vldr s13, [r4, #204] */
/* @0x2e3dec vldr s2, [r4, #120] */
/* @0x2e3df0 vldr s3, [r4, #136] */
/* @0x2e3df4 vldr s4, [r4, #116] */
/* @0x2e3df8 vldr s17, [r4, #188] */
/* @0x2e3dfc vldr s9, [r4, #104] */
/* @0x2e3e00 vldr s1, [r4, #184] */
/* @0x2e3e04 vldr s0, [r4, #100] */
/* @0x2e3e08 vldr s30, [r4, #236] */
/* @0x2e3e0c vsub.f32 s2, s2, s13 */
/* @0x2e3e10 vldr s13, [r4, #200] */
/* @0x2e3e14 vmul.f32 s6, s2, s12 */
/* @0x2e3e18 vmul.f32 s7, s3, s16 */
/* @0x2e3e1c vsub.f32 s4, s4, s13 */
/* @0x2e3e20 vldr s13, [r4, #132] */
/* @0x2e3e24 vmul.f32 s18, s2, s16 */
/* @0x2e3e28 vnmls.f32 s7, s13, s12 */
/* @0x2e3e2c vldr s13, [r4, #152] */
/* @0x2e3e30 vmla.f32 s6, s4, s16 */
/* @0x2e3e34 vmul.f32 s8, s3, s12 */
/* @0x2e3e38 vsub.f32 s9, s9, s17 */
/* @0x2e3e3c vldr s17, [r4, #132] */
/* @0x2e3e40 vnmls.f32 s18, s4, s12 */
/* @0x2e3e44 vmla.f32 s8, s17, s16 */
/* @0x2e3e48 vsub.f32 s0, s0, s1 */
/* @0x2e3e4c vmul.f32 s6, s7, s6 */
/* @0x2e3e50 vmul.f32 s1, s9, s23 */
/* @0x2e3e54 vnmls.f32 s6, s8, s18 */
/* @0x2e3e58 vldr s18, [r4, #220] */
/* @0x2e3e5c vmla.f32 s1, s0, s24 */
/* @0x2e3e60 vmul.f32 s9, s9, s24 */
/* @0x2e3e64 vnmls.f32 s9, s0, s23 */
/* @0x2e3e68 vldr s0, [sp, #8] */
/* @0x2e3e6c vsub.f32 s24, s0, s31 */
/* @0x2e3e70 vmul.f32 s6, s13, s6 */
/* @0x2e3e74 vmul.f32 s0, s7, s1 */
/* @0x2e3e78 vadd.f32 s24, s1, s24 */
/* @0x2e3e7c vldr s1, [sp, #12] */
/* @0x2e3e80 vsub.f32 s17, s25, s1 */
/* @0x2e3e84 vnmls.f32 s0, s8, s9 */
/* @0x2e3e88 vadd.f32 s17, s9, s17 */
/* @0x2e3e8c vmul.f32 s1, s24, s12 */
/* @0x2e3e90 vmul.f32 s9, s30, s6 */
/* @0x2e3e94 vmov.f32 s23, s30 */
/* @0x2e3e98 vmul.f32 s30, s13, s13 */
/* @0x2e3e9c vmls.f32 s1, s16, s17 */
/* @0x2e3ea0 vstr s30, [sp, #28] */
/* @0x2e3ea4 vmul.f32 s16, s24, s16 */
/* @0x2e3ea8 vldr s24, [r4, #212] */
/* @0x2e3eac vmul.f32 s9, s9, s6 */
/* @0x2e3eb0 vadd.f32 s30, s18, s24 */
/* @0x2e3eb4 vmul.f32 s0, s13, s0 */
/* @0x2e3eb8 vmla.f32 s16, s17, s12 */
/* @0x2e3ebc vldr s12, [sp, #28] */
/* @0x2e3ec0 vmla.f32 s9, s12, s30 */
/* @0x2e3ec4 vldr s12, [r4, #228] */
/* @0x2e3ec8 vsub.f32 s2, s1, s2 */
/* @0x2e3ecc vmul.f32 s30, s12, s0 */
/* @0x2e3ed0 vmul.f32 s2, s3, s2 */
/* @0x2e3ed4 vmla.f32 s9, s30, s0 */
/* @0x2e3ed8 vldr s30, [r4, #132] */
/* @0x2e3edc vsub.f32 s16, s16, s4 */
/* @0x2e3ee0 vmla.f32 s2, s30, s16 */
/* @0x2e3ee4 vmov.f32 s17, s13 */
/* @0x2e3ee8 vmul.f32 s7, s13, s7 */
/* @0x2e3eec vmul.f32 s13, s13, s8 */
/* @0x2e3ef0 vadd.f32 s28, s9, s28 */
/* @0x2e3ef4 vldr s9, [r4, #148] */
/* @0x2e3ef8 vldr s1, [sp, #24] */
/* @0x2e3efc vldr s3, [sp, #20] */
/* @0x2e3f00 vldr s4, [sp, #16] */
/* @0x2e3f04 mov r0, #1 */
/* @0x2e3f08 vmla.f32 s5, s2, s17 */
/* @0x2e3f0c vldr s17, [sp] */
/* @0x2e3f10 vsub.f32 s5, s5, s9 */
/* @0x2e3f14 vcmpe.f32 s28, #0 */
/* @0x2e3f18 vmrs APSR_nzcv, fpscr */
/* @0x2e3f1c vneggt.f32 s5, s5 */
/* @0x2e3f20 vldrle s28, [pc, #312] */
/* @0x2e3f24 vdivgt.f32 s28, s5, s28 */
/* @0x2e3f28 vmul.f32 s5, s28, s1 */
/* @0x2e3f2c vmul.f32 s8, s28, s3 */
/* @0x2e3f30 vmul.f32 s24, s28, s24 */
/* @0x2e3f34 vmul.f32 s18, s28, s18 */
/* @0x2e3f38 vmul.f32 s27, s28, s27 */
/* @0x2e3f3c vmul.f32 s12, s28, s12 */
/* @0x2e3f40 vmul.f32 s9, s28, s4 */
/* @0x2e3f44 vmul.f32 s28, s28, s23 */
/* @0x2e3f48 vmla.f32 s26, s5, s15 */
/* @0x2e3f4c vmls.f32 s17, s8, s15 */
/* @0x2e3f50 vstr s26, [r8, #4] */
/* @0x2e3f54 vmov.f32 s15, s31 */
/* @0x2e3f58 vmla.f32 s29, s5, s14 */
/* @0x2e3f5c vmla.f32 s22, s27, s10 */
/* @0x2e3f60 vldr s10, [sp, #8] */
/* @0x2e3f64 vstr s29, [r8] */
/* @0x2e3f68 vmla.f32 s21, s12, s0 */
/* @0x2e3f6c vldr s12, [sp, #4] */
/* @0x2e3f70 vstr s22, [r8, #8] */
/* @0x2e3f74 vmls.f32 s12, s8, s14 */
/* @0x2e3f78 vldr s14, [sp, #12] */
/* @0x2e3f7c vstr s21, [r7, #8] */
/* @0x2e3f80 vmla.f32 s25, s24, s7 */
/* @0x2e3f84 vmla.f32 s10, s24, s13 */
/* @0x2e3f88 vstr s25, [r7] */
/* @0x2e3f8c vmls.f32 s20, s9, s11 */
/* @0x2e3f90 vstr s10, [r7, #4] */
/* @0x2e3f94 vstr s12, [r6] */
/* @0x2e3f98 vstr s17, [r6, #4] */
/* @0x2e3f9c vmls.f32 s14, s18, s7 */
/* @0x2e3fa0 vstr s20, [r6, #8] */
/* @0x2e3fa4 vmls.f32 s15, s18, s13 */
/* @0x2e3fa8 vstr s14, [r5] */
/* @0x2e3fac vmls.f32 s19, s28, s6 */
/* @0x2e3fb0 vstr s15, [r5, #4] */
/* @0x2e3fb4 vstr s19, [r5, #8] */
/* @0x2e3fb8 add sp, sp, #32 */
/* @0x2e3fbc vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2e3fc0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2e3fc4 vldr s11, [r4, #232] */
/* @0x2e3fc8 vldr s28, [r4, #224] */
/* @0x2e3fcc vsub.f32 s5, s22, s20 */
/* @0x2e3fd0 vstr s11, [sp, #16] */
/* @0x2e3fd4 ldr r3, [r4, #0x50] */
/* @0x2e3fd8 vldr s13, [pc, #128] */
/* @0x2e3fdc vldr s14, [r4, #208] */
/* @0x2e3fe0 vldr s8, [r4, #140] */
/* @0x2e3fe4 cmp r3, #1 */
/* @0x2e3fe8 vldr s9, [r4, #216] */
/* @0x2e3fec vstr s14, [sp, #24] */
/* @0x2e3ff0 vstr s9, [sp, #20] */
/* @0x2e3ff4 vmov.f32 s27, s28 */
/* @0x2e3ff8 vadd.f32 s28, s28, s11 */
/* @0x2e3ffc vmov.f32 s11, #1.000000e+00 */
/* @0x2e4000 vmov.f32 s15, s13 */
/* @0x2e4004 vmov.f32 s14, s13 */
/* @0x2e4008 vadd.f32 s28, s28, s13 */
/* @0x2e400c vmov.f32 s10, s11 */
/* @0x2e4010 vsub.f32 s5, s5, s8 */
/* @0x2e4014 bne 0x2e3de8 <_ZN11b2GearJoint24SolvePositionConstraintsERK12b2SolverData+0x1e4> */
/* @0x2e4018 vldr s0, [r4, #152] */
/* @0x2e401c vldr s7, [r4, #228] */
/* @0x2e4020 vldr s9, [r4, #236] */
/* @0x2e4024 vldr s3, [r4, #144] */
/* @0x2e4028 vldr s13, [pc, #48] */
/* @0x2e402c vldr s18, [r4, #220] */
/* @0x2e4030 vldr s24, [r4, #212] */
/* @0x2e4034 vmul.f32 s8, s0, s0 */
/* @0x2e4038 vmov.f32 s23, s9 */
/* @0x2e403c vsub.f32 s2, s21, s19 */
/* @0x2e4040 vadd.f32 s9, s7, s9 */
/* @0x2e4044 vmov.f32 s12, s7 */
/* @0x2e4048 vmov.f32 s17, s0 */
/* @0x2e404c vmov.f32 s6, s0 */
/* @0x2e4050 vmov.f32 s7, s13 */
/* @0x2e4054 vmla.f32 s28, s8, s9 */
/* @0x2e4058 vsub.f32 s2, s2, s3 */
/* @0x2e405c b 0x2e3ef4 <_ZN11b2GearJoint24SolvePositionConstraintsERK12b2SolverData+0x2f0> */
/* @0x2e4060 andeq r0, r0, r0 */

/* ── FUNC 0x2e4064 · b2GearJoint::InitVelocityConstraints(b2SolverData const&) · size=1316 · insn=329 */
/* @0x2e4064 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e4068 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2e406c sub sp, sp, #44 */
/* @0x2e4070 ldr r9, [r0, #0x30] */
/* @0x2e4074 add r3, r0, #184 */
/* @0x2e4078 ldr r12, [r0, #0x34] */
/* @0x2e407c mov r6, r1 */
/* @0x2e4080 ldr r2, [r0, #0x54] */
/* @0x2e4084 add r1, r9, #44 */
/* @0x2e4088 str r3, [sp, #0x4] */
/* @0x2e408c mov r4, r0 */
/* @0x2e4090 ldr r3, [r0, #0x58] */
/* @0x2e4094 add lr, r0, #176 */
/* @0x2e4098 ldr r7, [r12, #0x8] */
/* @0x2e409c add r5, r12, #44 */
/* @0x2e40a0 ldr r11, [r2, #0x8] */
/* @0x2e40a4 vldr s30, [r2, #136] */
/* @0x2e40a8 ldr r8, [r9, #0x8] */
/* @0x2e40ac vldr s5, [r9, #136] */
/* @0x2e40b0 ldr r10, [r3, #0x8] */
/* @0x2e40b4 vldr s15, [r12, #136] */
/* @0x2e40b8 ldm r1, {r0, r1} */
/* @0x2e40bc vstr s5, [sp, #20] */
/* @0x2e40c0 str r8, [r4, #0xa0] */
/* @0x2e40c4 add r8, r8, r8, lsl #1 */
/* @0x2e40c8 str r7, [r4, #0xa4] */
/* @0x2e40cc add r7, r7, r7, lsl #1 */
/* @0x2e40d0 str r11, [r4, #0xa8] */
/* @0x2e40d4 lsl r8, r8, #2 */
/* @0x2e40d8 str r10, [r4, #0xac] */
/* @0x2e40dc lsl r7, r7, #2 */
/* @0x2e40e0 stm lr, {r0, r1} */
/* @0x2e40e4 add lr, r2, #44 */
/* @0x2e40e8 ldm r5, {r0, r1} */
/* @0x2e40ec add r5, r4, #192 */
/* @0x2e40f0 str r5, [sp, #0x8] */
/* @0x2e40f4 add r11, r11, r11, lsl #1 */
/* @0x2e40f8 ldr r5, [sp, #0x4] */
/* @0x2e40fc add r10, r10, r10, lsl #1 */
/* @0x2e4100 lsl r11, r11, #2 */
/* @0x2e4104 lsl r10, r10, #2 */
/* @0x2e4108 stm r5, {r0, r1} */
/* @0x2e410c add r5, r3, #44 */
/* @0x2e4110 ldm lr, {r0, r1} */
/* @0x2e4114 add lr, r4, #200 */
/* @0x2e4118 str lr, [sp, #0x4] */
/* @0x2e411c ldr lr, [sp, #0x8] */
/* @0x2e4120 stm lr, {r0, r1} */
/* @0x2e4124 vldr s21, [r9, #144] */
/* @0x2e4128 ldm r5, {r0, r1} */
/* @0x2e412c vldr s20, [r3, #144] */
/* @0x2e4130 ldr r5, [sp, #0x4] */
/* @0x2e4134 vldr s19, [r12, #144] */
/* @0x2e4138 ldr lr, [r6, #0x18] */
/* @0x2e413c vldr s22, [r2, #144] */
/* @0x2e4140 stm r5, {r0, r1} */
/* @0x2e4144 vstr s15, [r4, #212] */
/* @0x2e4148 ldr r1, [r3, #0x88] */
/* @0x2e414c add r3, lr, r7 */
/* @0x2e4150 ldr r5, [r6, #0x1c] */
/* @0x2e4154 vstr s5, [r4, #208] */
/* @0x2e4158 vstr s30, [r4, #216] */
/* @0x2e415c str r1, [r4, #0xdc] */
/* @0x2e4160 add r1, lr, r8 */
/* @0x2e4164 add r8, r5, r8 */
/* @0x2e4168 vldr s29, [r8] */
/* @0x2e416c ldr r9, [r1, #0x8] */
/* @0x2e4170 vldr s28, [r8, #4] */
/* @0x2e4174 vldr s27, [r8, #8] */
/* @0x2e4178 ldr r8, [r3, #0x8] */
/* @0x2e417c add r3, lr, r11 */
/* @0x2e4180 add lr, lr, r10 */
/* @0x2e4184 mov r0, r9 */
/* @0x2e4188 add r7, r5, r7 */
/* @0x2e418c add r10, r5, r10 */
/* @0x2e4190 vldr s26, [r7] */
/* @0x2e4194 vldr s25, [r7, #4] */
/* @0x2e4198 vldr s24, [r7, #8] */
/* @0x2e419c vstr s21, [r4, #224] */
/* @0x2e41a0 ldr r7, [r3, #0x8] */
/* @0x2e41a4 vstr s19, [r4, #228] */
/* @0x2e41a8 add r3, r5, r11 */
/* @0x2e41ac vstr s22, [r4, #232] */
/* @0x2e41b0 ldr r11, [lr, #0x8] */
/* @0x2e41b4 vldr s23, [r3] */
/* @0x2e41b8 vldr s5, [r3, #4] */
/* @0x2e41bc vstr s20, [r4, #236] */
/* @0x2e41c0 vstr s5, [sp, #16] */
/* @0x2e41c4 vldr s6, [r3, #8] */
/* @0x2e41c8 vldr s11, [r10, #4] */
/* @0x2e41cc vldr s8, [r10] */
/* @0x2e41d0 vstr s11, [sp, #8] */
/* @0x2e41d4 vstr s6, [sp, #4] */
/* @0x2e41d8 vstr s8, [sp, #12] */
/* @0x2e41dc bl 0xb6580 <sinf@plt> */
/* @0x2e41e0 vldr s31, [r10, #8] */
/* @0x2e41e4 str r0, [sp, #0x18] */
/* @0x2e41e8 mov r0, r9 */
/* @0x2e41ec bl 0xb658c <cosf@plt> */
/* @0x2e41f0 str r0, [sp, #0x1c] */
/* @0x2e41f4 mov r0, r8 */
/* @0x2e41f8 bl 0xb6580 <sinf@plt> */
/* @0x2e41fc str r0, [sp, #0x20] */
/* @0x2e4200 mov r0, r8 */
/* @0x2e4204 bl 0xb658c <cosf@plt> */
/* @0x2e4208 str r0, [sp, #0x24] */
/* @0x2e420c mov r0, r7 */
/* @0x2e4210 bl 0xb6580 <sinf@plt> */
/* @0x2e4214 vmov s17, r0 */
/* @0x2e4218 mov r0, r7 */
/* @0x2e421c bl 0xb658c <cosf@plt> */
/* @0x2e4220 vmov s18, r0 */
/* @0x2e4224 mov r0, r11 */
/* @0x2e4228 bl 0xb6580 <sinf@plt> */
/* @0x2e422c vmov s16, r0 */
/* @0x2e4230 mov r0, r11 */
/* @0x2e4234 bl 0xb658c <cosf@plt> */
/* @0x2e4238 ldr r3, [r4, #0x4c] */
/* @0x2e423c vldr s11, [pc, #832] */
/* @0x2e4240 vstr s11, [r4, #272] */
/* @0x2e4244 cmp r3, #1 */
/* @0x2e4248 vmov s12, r0 */
/* @0x2e424c beq 0x2e4560 <_ZN11b2GearJoint23InitVelocityConstraintsERK12b2SolverData+0x4fc> */
/* @0x2e4250 vldr s15, [r4, #196] */
/* @0x2e4254 vldr s8, [r4, #112] */
/* @0x2e4258 vsub.f32 s8, s8, s15 */
/* @0x2e425c vldr s13, [r4, #128] */
/* @0x2e4260 vldr s15, [r4, #192] */
/* @0x2e4264 vldr s9, [r4, #108] */
/* @0x2e4268 vldr s7, [r4, #96] */
/* @0x2e426c vldr s10, [r4, #180] */
/* @0x2e4270 vldr s6, [r4, #124] */
/* @0x2e4274 vldr s5, [sp, #28] */
/* @0x2e4278 vsub.f32 s9, s9, s15 */
/* @0x2e427c vmul.f32 s14, s8, s18 */
/* @0x2e4280 vmul.f32 s15, s13, s17 */
/* @0x2e4284 vmul.f32 s8, s8, s17 */
/* @0x2e4288 vsub.f32 s10, s7, s10 */
/* @0x2e428c vldr s7, [r4, #92] */
/* @0x2e4290 vnmls.f32 s15, s6, s18 */
/* @0x2e4294 vmla.f32 s14, s9, s17 */
/* @0x2e4298 vstr s15, [r4, #240] */
/* @0x2e429c vmul.f32 s13, s13, s18 */
/* @0x2e42a0 vnmls.f32 s8, s9, s18 */
/* @0x2e42a4 vldr s9, [r4, #176] */
/* @0x2e42a8 vsub.f32 s7, s7, s9 */
/* @0x2e42ac vmul.f32 s9, s10, s5 */
/* @0x2e42b0 vmla.f32 s13, s6, s17 */
/* @0x2e42b4 vldr s6, [sp, #24] */
/* @0x2e42b8 vmul.f32 s14, s15, s14 */
/* @0x2e42bc vstr s13, [r4, #244] */
/* @0x2e42c0 vmul.f32 s10, s10, s6 */
/* @0x2e42c4 vmla.f32 s9, s7, s6 */
/* @0x2e42c8 vnmls.f32 s14, s13, s8 */
/* @0x2e42cc vldr s8, [sp, #20] */
/* @0x2e42d0 vnmls.f32 s10, s7, s5 */
/* @0x2e42d4 vstr s14, [r4, #264] */
/* @0x2e42d8 vmul.f32 s15, s15, s9 */
/* @0x2e42dc vmul.f32 s22, s22, s14 */
/* @0x2e42e0 vnmls.f32 s15, s13, s10 */
/* @0x2e42e4 vadd.f32 s30, s8, s30 */
/* @0x2e42e8 vstr s15, [r4, #256] */
/* @0x2e42ec vmla.f32 s30, s22, s14 */
/* @0x2e42f0 vmul.f32 s21, s21, s15 */
/* @0x2e42f4 vmla.f32 s30, s21, s15 */
/* @0x2e42f8 vadd.f32 s30, s30, s11 */
/* @0x2e42fc vmov.f32 s21, s30 */
/* @0x2e4300 vstr s30, [r4, #272] */
/* @0x2e4304 ldr r3, [r4, #0x50] */
/* @0x2e4308 cmp r3, #1 */
/* @0x2e430c beq 0x2e4534 <_ZN11b2GearJoint23InitVelocityConstraintsERK12b2SolverData+0x4d0> */
/* @0x2e4310 vldr s15, [r4, #204] */
/* @0x2e4314 vldr s8, [r4, #120] */
/* @0x2e4318 vsub.f32 s8, s8, s15 */
/* @0x2e431c vldr s14, [r4, #136] */
/* @0x2e4320 vldr s1, [r4, #116] */
/* @0x2e4324 vldr s4, [r4, #200] */
/* @0x2e4328 vldr s5, [r4, #132] */
/* @0x2e432c vldr s2, [r4, #104] */
/* @0x2e4330 vldr s9, [r4, #188] */
/* @0x2e4334 vldr s3, [r4, #100] */
/* @0x2e4338 vldr s7, [r4, #184] */
/* @0x2e433c vldr s15, [r4, #152] */
/* @0x2e4340 vldr s6, [r4, #220] */
/* @0x2e4344 vldr s11, [r4, #212] */
/* @0x2e4348 vmul.f32 s10, s8, s12 */
/* @0x2e434c vmul.f32 s13, s14, s16 */
/* @0x2e4350 vsub.f32 s4, s1, s4 */
/* @0x2e4354 vnmls.f32 s13, s5, s12 */
/* @0x2e4358 vmul.f32 s14, s14, s12 */
/* @0x2e435c vmul.f32 s8, s8, s16 */
/* @0x2e4360 vmla.f32 s10, s4, s16 */
/* @0x2e4364 vsub.f32 s9, s2, s9 */
/* @0x2e4368 vmla.f32 s14, s5, s16 */
/* @0x2e436c vldr s5, [sp, #36] */
/* @0x2e4370 vnmls.f32 s8, s4, s12 */
/* @0x2e4374 vmul.f32 s10, s13, s10 */
/* @0x2e4378 vmul.f32 s12, s9, s5 */
/* @0x2e437c vsub.f32 s7, s3, s7 */
/* @0x2e4380 vnmls.f32 s10, s14, s8 */
/* @0x2e4384 vldr s8, [sp, #32] */
/* @0x2e4388 vmul.f32 s9, s9, s8 */
/* @0x2e438c vmla.f32 s12, s7, s8 */
/* @0x2e4390 vnmls.f32 s9, s7, s5 */
/* @0x2e4394 vmul.f32 s10, s15, s10 */
/* @0x2e4398 vmul.f32 s12, s13, s12 */
/* @0x2e439c vstr s10, [r4, #268] */
/* @0x2e43a0 vnmls.f32 s12, s14, s9 */
/* @0x2e43a4 vmul.f32 s20, s20, s10 */
/* @0x2e43a8 vmul.f32 s9, s15, s15 */
/* @0x2e43ac vmul.f32 s20, s10, s20 */
/* @0x2e43b0 vadd.f32 s11, s6, s11 */
/* @0x2e43b4 vmul.f32 s12, s15, s12 */
/* @0x2e43b8 vmla.f32 s20, s9, s11 */
/* @0x2e43bc vstr s12, [r4, #260] */
/* @0x2e43c0 vmul.f32 s19, s19, s12 */
/* @0x2e43c4 vmla.f32 s20, s12, s19 */
/* @0x2e43c8 vmul.f32 s13, s15, s13 */
/* @0x2e43cc vmul.f32 s15, s15, s14 */
/* @0x2e43d0 vstr s13, [r4, #248] */
/* @0x2e43d4 vadd.f32 s20, s21, s20 */
/* @0x2e43d8 vstr s15, [r4, #252] */
/* @0x2e43dc ldrb r3, [r6, #0x14] */
/* @0x2e43e0 vcmpe.f32 s20, #0 */
/* @0x2e43e4 vmrs APSR_nzcv, fpscr */
/* @0x2e43e8 vmovgt.f32 s15, #1.000000e+00 */
/* @0x2e43ec vldrle s20, [pc, #400] */
/* @0x2e43f0 vdivgt.f32 s20, s15, s20 */
/* @0x2e43f4 cmp r3, #0 */
/* @0x2e43f8 moveq r3, #0 */
/* @0x2e43fc streq r3, [r4, #0x9c] */
/* @0x2e4400 vstr s20, [r4, #272] */
/* @0x2e4404 beq 0x2e44bc <_ZN11b2GearJoint23InitVelocityConstraintsERK12b2SolverData+0x458> */
/* @0x2e4408 vldr s15, [r4, #156] */
/* @0x2e440c vldr s7, [r4, #208] */
/* @0x2e4410 vldr s9, [r4, #216] */
/* @0x2e4414 vmul.f32 s7, s15, s7 */
/* @0x2e4418 vldr s0, [r4, #224] */
/* @0x2e441c vldr s11, [r4, #212] */
/* @0x2e4420 vldr s13, [r4, #220] */
/* @0x2e4424 vldr s2, [r4, #228] */
/* @0x2e4428 vldr s4, [r4, #232] */
/* @0x2e442c vldr s16, [r4, #236] */
/* @0x2e4430 vldr s8, [r4, #240] */
/* @0x2e4434 vldr s12, [r4, #248] */
/* @0x2e4438 vldr s10, [r4, #244] */
/* @0x2e443c vldr s14, [r4, #252] */
/* @0x2e4440 vldr s1, [r4, #256] */
/* @0x2e4444 vldr s3, [r4, #260] */
/* @0x2e4448 vldr s5, [r4, #264] */
/* @0x2e444c vldr s6, [r4, #268] */
/* @0x2e4450 vmul.f32 s11, s15, s11 */
/* @0x2e4454 vmul.f32 s13, s15, s13 */
/* @0x2e4458 vmul.f32 s9, s15, s9 */
/* @0x2e445c vmul.f32 s0, s15, s0 */
/* @0x2e4460 vmul.f32 s2, s15, s2 */
/* @0x2e4464 vmul.f32 s4, s15, s4 */
/* @0x2e4468 vmul.f32 s15, s15, s16 */
/* @0x2e446c vmla.f32 s26, s11, s12 */
/* @0x2e4470 vmla.f32 s29, s7, s8 */
/* @0x2e4474 vmls.f32 s23, s9, s8 */
/* @0x2e4478 vldr s8, [sp, #16] */
/* @0x2e447c vmla.f32 s25, s11, s14 */
/* @0x2e4480 vldr s11, [sp, #12] */
/* @0x2e4484 vmls.f32 s8, s9, s10 */
/* @0x2e4488 vmls.f32 s11, s13, s12 */
/* @0x2e448c vldr s12, [sp, #8] */
/* @0x2e4490 vstr s8, [sp, #16] */
/* @0x2e4494 vmls.f32 s12, s13, s14 */
/* @0x2e4498 vldr s13, [sp, #4] */
/* @0x2e449c vstr s11, [sp, #12] */
/* @0x2e44a0 vmls.f32 s13, s4, s5 */
/* @0x2e44a4 vstr s12, [sp, #8] */
/* @0x2e44a8 vmla.f32 s28, s7, s10 */
/* @0x2e44ac vstr s13, [sp, #4] */
/* @0x2e44b0 vmla.f32 s27, s0, s1 */
/* @0x2e44b4 vmla.f32 s24, s2, s3 */
/* @0x2e44b8 vmls.f32 s31, s15, s6 */
/* @0x2e44bc add r1, r4, #160 */
/* @0x2e44c0 ldr r0, [r4, #0xac] */
/* @0x2e44c4 vldr s14, [sp, #16] */
/* @0x2e44c8 vldr s15, [sp, #4] */
/* @0x2e44cc ldm r1, {r1, r2, r3} */
/* @0x2e44d0 vldr s5, [sp, #12] */
/* @0x2e44d4 add r0, r0, r0, lsl #1 */
/* @0x2e44d8 vldr s6, [sp, #8] */
/* @0x2e44dc add r2, r2, r2, lsl #1 */
/* @0x2e44e0 add r3, r3, r3, lsl #1 */
/* @0x2e44e4 add r1, r1, r1, lsl #1 */
/* @0x2e44e8 add r2, r5, r2, lsl #2 */
/* @0x2e44ec add r3, r5, r3, lsl #2 */
/* @0x2e44f0 add r1, r5, r1, lsl #2 */
/* @0x2e44f4 add r5, r5, r0, lsl #2 */
/* @0x2e44f8 vstr s29, [r1] */
/* @0x2e44fc vstr s28, [r1, #4] */
/* @0x2e4500 vstr s27, [r1, #8] */
/* @0x2e4504 vstr s26, [r2] */
/* @0x2e4508 vstr s25, [r2, #4] */
/* @0x2e450c vstr s24, [r2, #8] */
/* @0x2e4510 vstr s23, [r3] */
/* @0x2e4514 vstr s14, [r3, #4] */
/* @0x2e4518 vstr s15, [r3, #8] */
/* @0x2e451c vstr s5, [r5] */
/* @0x2e4520 vstr s6, [r5, #4] */
/* @0x2e4524 vstr s31, [r5, #8] */
/* @0x2e4528 add sp, sp, #44 */
/* @0x2e452c vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2e4530 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e4534 vldr s15, [r4, #152] */
/* @0x2e4538 vmul.f32 s14, s15, s15 */
/* @0x2e453c mov r3, #0 */
/* @0x2e4540 vstr s15, [r4, #260] */
/* @0x2e4544 vstr s15, [r4, #268] */
/* @0x2e4548 str r3, [r4, #0xf8] */
/* @0x2e454c str r3, [r4, #0xfc] */
/* @0x2e4550 vadd.f32 s19, s19, s20 */
/* @0x2e4554 vmov.f32 s20, s21 */
/* @0x2e4558 vmla.f32 s20, s14, s19 */
/* @0x2e455c b 0x2e43dc <_ZN11b2GearJoint23InitVelocityConstraintsERK12b2SolverData+0x378> */
/* @0x2e4560 vadd.f32 s21, s21, s22 */
/* @0x2e4564 mov r3, #1065353216 */
/* @0x2e4568 vstr s11, [r4, #240] */
/* @0x2e456c vstr s11, [r4, #244] */
/* @0x2e4570 str r3, [r4, #0x100] */
/* @0x2e4574 str r3, [r4, #0x108] */
/* @0x2e4578 vadd.f32 s21, s21, s11 */
/* @0x2e457c vstr s21, [r4, #272] */
/* @0x2e4580 b 0x2e4304 <_ZN11b2GearJoint23InitVelocityConstraintsERK12b2SolverData+0x2a0> */
/* @0x2e4584 andeq r0, r0, r0 */

/* ── FUNC 0x2e4588 · b2GearJoint::b2GearJoint(b2GearJointDef const*) · size=760 · insn=190 */
/* @0x2e4588 push {r4, r5, r6, r7, r8, lr} */
/* @0x2e458c mov r5, r1 */
/* @0x2e4590 mov r4, r0 */
/* @0x2e4594 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef> */
/* @0x2e4598 ldr r1, [r5, #0x14] */
/* @0x2e459c ldr r2, [r5, #0x18] */
/* @0x2e45a0 ldr r3, [pc, #0x2c8] */
/* @0x2e45a4 str r1, [r4, #0x44] */
/* @0x2e45a8 ldr r3, [pc, r3] */
/* @0x2e45ac str r2, [r4, #0x48] */
/* @0x2e45b0 add r3, r3, #8 */
/* @0x2e45b4 str r3, [r4] */
/* @0x2e45b8 ldr r3, [r1, #0x4] */
/* @0x2e45bc ldr r6, [pc, #0x2b0] */
/* @0x2e45c0 sub r0, r3, #1 */
/* @0x2e45c4 ldr r1, [pc, #0x2ac] */
/* @0x2e45c8 str r3, [r4, #0x4c] */
/* @0x2e45cc cmp r0, #1 */
/* @0x2e45d0 ldr r2, [r2, #0x4] */
/* @0x2e45d4 ldr r6, [pc, r6] */
/* @0x2e45d8 movhi r0, #0 */
/* @0x2e45dc movls r0, #1 */
/* @0x2e45e0 add r1, pc, r1 */
/* @0x2e45e4 ldr r3, [r6] */
/* @0x2e45e8 str r2, [r4, #0x50] */
/* @0x2e45ec blx r3 */
/* @0x2e45f0 ldr r0, [r4, #0x50] */
/* @0x2e45f4 ldr r1, [pc, #0x280] */
/* @0x2e45f8 sub r0, r0, #1 */
/* @0x2e45fc ldr r3, [r6] */
/* @0x2e4600 cmp r0, #1 */
/* @0x2e4604 add r1, pc, r1 */
/* @0x2e4608 movhi r0, #0 */
/* @0x2e460c movls r0, #1 */
/* @0x2e4610 blx r3 */
/* @0x2e4614 ldr r2, [r4, #0x44] */
/* @0x2e4618 ldr r1, [r4, #0x4c] */
/* @0x2e461c ldr r3, [r2, #0x30] */
/* @0x2e4620 vldr s13, [r3, #12] */
/* @0x2e4624 vldr s15, [r3, #16] */
/* @0x2e4628 vldr s9, [r3, #20] */
/* @0x2e462c vldr s10, [r3, #24] */
/* @0x2e4630 vldr s14, [r3, #72] */
/* @0x2e4634 str r3, [r4, #0x54] */
/* @0x2e4638 cmp r1, #1 */
/* @0x2e463c ldr r3, [r2, #0x34] */
/* @0x2e4640 vldr s12, [r3, #12] */
/* @0x2e4644 vldr s11, [r3, #16] */
/* @0x2e4648 vldr s7, [r3, #20] */
/* @0x2e464c vldr s8, [r3, #24] */
/* @0x2e4650 vldr s6, [r3, #72] */
/* @0x2e4654 str r3, [r4, #0x30] */
/* @0x2e4658 beq 0x2e47ec <_ZN11b2GearJointC2EPK14b2GearJointDef+0x264> */
/* @0x2e465c ldr r3, [r5, #0x14] */
/* @0x2e4660 add r7, r4, #108 */
/* @0x2e4664 add r12, r4, #92 */
/* @0x2e4668 add r8, r4, #124 */
/* @0x2e466c add r1, r3, #68 */
/* @0x2e4670 add r6, r3, #76 */
/* @0x2e4674 add r2, r3, #84 */
/* @0x2e4678 ldr r3, [r3, #0x64] */
/* @0x2e467c ldm r1, {r0, r1} */
/* @0x2e4680 vsub.f32 s15, s11, s15 */
/* @0x2e4684 stm r7, {r0, r1} */
/* @0x2e4688 ldm r6, {r0, r1} */
/* @0x2e468c stm r12, {r0, r1} */
/* @0x2e4690 ldm r2, {r0, r1} */
/* @0x2e4694 str r3, [r4, #0x8c] */
/* @0x2e4698 vsub.f32 s1, s12, s13 */
/* @0x2e469c stm r8, {r0, r1} */
/* @0x2e46a0 vldr s5, [r4, #96] */
/* @0x2e46a4 vldr s6, [r4, #92] */
/* @0x2e46a8 vldr s14, [r4, #112] */
/* @0x2e46ac vldr s2, [r4, #128] */
/* @0x2e46b0 vldr s3, [r4, #108] */
/* @0x2e46b4 vldr s4, [r4, #124] */
/* @0x2e46b8 vmul.f32 s11, s8, s5 */
/* @0x2e46bc vmul.f32 s12, s7, s5 */
/* @0x2e46c0 vmla.f32 s11, s7, s6 */
/* @0x2e46c4 vnmls.f32 s12, s8, s6 */
/* @0x2e46c8 vadd.f32 s11, s11, s15 */
/* @0x2e46cc vmul.f32 s13, s11, s10 */
/* @0x2e46d0 vadd.f32 s12, s12, s1 */
/* @0x2e46d4 vmul.f32 s15, s11, s9 */
/* @0x2e46d8 vmls.f32 s13, s9, s12 */
/* @0x2e46dc vmla.f32 s15, s12, s10 */
/* @0x2e46e0 vsub.f32 s14, s13, s14 */
/* @0x2e46e4 vmul.f32 s14, s14, s2 */
/* @0x2e46e8 vsub.f32 s15, s15, s3 */
/* @0x2e46ec vmla.f32 s14, s15, s4 */
/* @0x2e46f0 ldr r2, [r4, #0x48] */
/* @0x2e46f4 ldr r1, [r4, #0x50] */
/* @0x2e46f8 ldr r3, [r2, #0x30] */
/* @0x2e46fc vldr s12, [r3, #12] */
/* @0x2e4700 vldr s13, [r3, #16] */
/* @0x2e4704 vldr s8, [r3, #20] */
/* @0x2e4708 vldr s9, [r3, #24] */
/* @0x2e470c vldr s5, [r3, #72] */
/* @0x2e4710 str r3, [r4, #0x58] */
/* @0x2e4714 cmp r1, #1 */
/* @0x2e4718 ldr r3, [r2, #0x34] */
/* @0x2e471c vldr s11, [r3, #12] */
/* @0x2e4720 vldr s10, [r3, #16] */
/* @0x2e4724 vldr s6, [r3, #20] */
/* @0x2e4728 vldr s7, [r3, #24] */
/* @0x2e472c vldr s4, [r3, #72] */
/* @0x2e4730 str r3, [r4, #0x34] */
/* @0x2e4734 ldr r3, [r5, #0x18] */
/* @0x2e4738 beq 0x2e4830 <_ZN11b2GearJointC2EPK14b2GearJointDef+0x2a8> */
/* @0x2e473c add r1, r3, #68 */
/* @0x2e4740 add r6, r3, #76 */
/* @0x2e4744 add r7, r4, #116 */
/* @0x2e4748 add r2, r3, #84 */
/* @0x2e474c ldm r1, {r0, r1} */
/* @0x2e4750 add r12, r4, #100 */
/* @0x2e4754 ldr r3, [r3, #0x64] */
/* @0x2e4758 add r8, r4, #132 */
/* @0x2e475c stm r7, {r0, r1} */
/* @0x2e4760 ldm r6, {r0, r1} */
/* @0x2e4764 vsub.f32 s13, s10, s13 */
/* @0x2e4768 stm r12, {r0, r1} */
/* @0x2e476c ldm r2, {r0, r1} */
/* @0x2e4770 str r3, [r4, #0x90] */
/* @0x2e4774 stm r8, {r0, r1} */
/* @0x2e4778 vldr s4, [r4, #104] */
/* @0x2e477c vldr s5, [r4, #100] */
/* @0x2e4780 vldr s15, [r4, #120] */
/* @0x2e4784 vldr s1, [r4, #136] */
/* @0x2e4788 vldr s2, [r4, #116] */
/* @0x2e478c vmul.f32 s10, s4, s7 */
/* @0x2e4790 vldr s3, [r4, #132] */
/* @0x2e4794 vsub.f32 s0, s11, s12 */
/* @0x2e4798 vmla.f32 s10, s5, s6 */
/* @0x2e479c vmul.f32 s11, s4, s6 */
/* @0x2e47a0 vnmls.f32 s11, s5, s7 */
/* @0x2e47a4 vadd.f32 s10, s10, s13 */
/* @0x2e47a8 vmul.f32 s12, s9, s10 */
/* @0x2e47ac vadd.f32 s11, s11, s0 */
/* @0x2e47b0 vmul.f32 s13, s8, s10 */
/* @0x2e47b4 vmls.f32 s12, s8, s11 */
/* @0x2e47b8 vmla.f32 s13, s9, s11 */
/* @0x2e47bc vsub.f32 s15, s12, s15 */
/* @0x2e47c0 vmul.f32 s15, s15, s1 */
/* @0x2e47c4 vsub.f32 s13, s13, s2 */
/* @0x2e47c8 vmla.f32 s15, s13, s3 */
/* @0x2e47cc vldr s13, [r5, #28] */
/* @0x2e47d0 mov r3, #0 */
/* @0x2e47d4 vstr s13, [r4, #152] */
/* @0x2e47d8 str r3, [r4, #0x9c] */
/* @0x2e47dc mov r0, r4 */
/* @0x2e47e0 vmla.f32 s14, s15, s13 */
/* @0x2e47e4 vstr s14, [r4, #148] */
/* @0x2e47e8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2e47ec ldr r3, [r5, #0x14] */
/* @0x2e47f0 vsub.f32 s14, s6, s14 */
/* @0x2e47f4 add r12, r4, #108 */
/* @0x2e47f8 vldr s15, [r3, #116] */
/* @0x2e47fc add r1, r3, #68 */
/* @0x2e4800 add r2, r3, #76 */
/* @0x2e4804 add r7, r4, #92 */
/* @0x2e4808 mov r6, #0 */
/* @0x2e480c ldm r1, {r0, r1} */
/* @0x2e4810 stm r12, {r0, r1} */
/* @0x2e4814 ldm r2, {r0, r1} */
/* @0x2e4818 vsub.f32 s14, s14, s15 */
/* @0x2e481c stm r7, {r0, r1} */
/* @0x2e4820 vstr s15, [r4, #140] */
/* @0x2e4824 str r6, [r4, #0x7c] */
/* @0x2e4828 str r6, [r4, #0x80] */
/* @0x2e482c b 0x2e46f0 <_ZN11b2GearJointC2EPK14b2GearJointDef+0x168> */
/* @0x2e4830 vsub.f32 s15, s4, s5 */
/* @0x2e4834 add r1, r3, #68 */
/* @0x2e4838 add r12, r4, #116 */
/* @0x2e483c add r2, r3, #76 */
/* @0x2e4840 ldm r1, {r0, r1} */
/* @0x2e4844 vldr s13, [r3, #116] */
/* @0x2e4848 add r7, r4, #100 */
/* @0x2e484c mov r6, #0 */
/* @0x2e4850 stm r12, {r0, r1} */
/* @0x2e4854 ldm r2, {r0, r1} */
/* @0x2e4858 stm r7, {r0, r1} */
/* @0x2e485c vstr s13, [r4, #144] */
/* @0x2e4860 str r6, [r4, #0x84] */
/* @0x2e4864 vsub.f32 s15, s15, s13 */
/* @0x2e4868 str r6, [r4, #0x88] */
/* @0x2e486c b 0x2e47cc <_ZN11b2GearJointC2EPK14b2GearJointDef+0x244> */
/* @0x2e4870 andseq sp, r0, r4, lsl #12 */
/* @0x2e4874 ldrsheq r12, [r0], -r4 */
/* @0x2e4878 andeq r9, r7, r8, lsl r3 */
/* @0x2e487c ldrdeq r9, r10, [r7], -r12 */

/* ── FUNC 0x2e4588 · b2GearJoint::b2GearJoint(b2GearJointDef const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2e4880 · b2GearJoint::SetRatio(float) · size=132 · insn=33 */
/* @0x2e4880 push {r4, lr} */
/* @0x2e4884 vpush {d8} */
/* @0x2e4888 vmov s16, r1 */
/* @0x2e488c ldr r3, [pc, #0x68] */
/* @0x2e4890 mov r4, r0 */
/* @0x2e4894 vcmp.f32 s16, s16 */
/* @0x2e4898 sub sp, sp, #16 */
/* @0x2e489c ldr r3, [pc, r3] */
/* @0x2e48a0 mov r0, #0 */
/* @0x2e48a4 ldr r3, [r3] */
/* @0x2e48a8 vmrs APSR_nzcv, fpscr */
/* @0x2e48ac bne 0x2e48e0 <_ZN11b2GearJoint8SetRatioEf+0x60> */
/* @0x2e48b0 movw r2, #0x7f80 */
/* @0x2e48b4 strh r0, [sp] */
/* @0x2e48b8 strh r2, [sp, #2] */
/* @0x2e48bc vldr s15, [sp] */
/* @0x2e48c0 vneg.f32 s14, s15 */
/* @0x2e48c4 vcmpe.f32 s16, s14 */
/* @0x2e48c8 vmrs APSR_nzcv, fpscr */
/* @0x2e48cc ble 0x2e48e0 <_ZN11b2GearJoint8SetRatioEf+0x60> */
/* @0x2e48d0 vcmpe.f32 s16, s15 */
/* @0x2e48d4 vmrs APSR_nzcv, fpscr */
/* @0x2e48d8 movpl r0, #0 */
/* @0x2e48dc movmi r0, #1 */
/* @0x2e48e0 ldr r1, [pc, #0x18] */
/* @0x2e48e4 add r1, pc, r1 */
/* @0x2e48e8 blx r3 */
/* @0x2e48ec vstr s16, [r4, #152] */
/* @0x2e48f0 add sp, sp, #16 */
/* @0x2e48f4 vpop {d8} */
/* @0x2e48f8 pop {r4, pc} */
/* @0x2e48fc andseq r12, r0, r12, lsr #24 */
/* @0x2e4900 andeq r9, r7, r4, ror #3 */

/* ── FUNC 0x2e4904 · b2GearJoint::GetRatio() const · size=8 · insn=2 */
/* @0x2e4904 ldr r0, [r0, #0x98] */
/* @0x2e4908 bx lr */

/* ── FUNC 0x2e490c · anon_2e490c · size=1036 · insn=260 */
/* @0x2e490c addlt r11, r4, #240, #10 */
/* @0x2e4910 .word 0x0c00b28e */
/* @0x2e4914 blx 0x467942 <g_RomDisk+0x70122> */
/* @0x2e4918 blx 0x361d22 <_ZTS12CDS_Priority+0x3d7a> */
/* @0x2e491c adcmi r5, r11, #4, #6 */
/* @0x2e4920 .word 0xf44fbf34 */
/* @0x2e4924 strhs r3, [r0, -r0, lsl #15] */
/* @0x2e4928 .word 0x0c1b041d */
/* @0x2e492c strpl pc, [r4], #-2822 */
/* @0x2e4930 andlo pc, r0, r1, lsl #22 */
/* @0x2e4934 svclt #0x2c42ac */
/* @0x2e4938 mcrrne p6, #0x0, r4, r5, c5 */
/* @0x2e493c ldrtmi r6, [sp], #-20 */
/* @0x2e4940 ldcllt p0, c6, [r0, #340]! */
/* @0x2e4944 ldrhhs pc, [r6], -r0 */
/* @0x2e4948 sbcseq r6, r3, r1, lsl #19 */
/* @0x2e494c bicvs r4, r1, #419430400 */
/* @0x2e4950 strmi r6, [r10], #-2497 */
/* @0x2e4954 ldrhne pc, [r4], -r0 */
/* @0x2e4958 bvs 0x37d968 <_ZTS13C_UTF16String+0x14a14> */
/* @0x2e495c subeq lr, r1, #2048 */
/* @0x2e4960 .word 0x7c026442 */
/* @0x2e4964 bvs 0xfe390e14 <b2_toiTime+0xfffffffffdc37970> */
/* @0x2e4968 strbvs r4, [r2], #1050 */
/* @0x2e496c ldrmi r6, [r3], #-2754 */
/* @0x2e4970 ldrbmi r6, [r0, -r3, lsl #10]! */
/* @0x2e4974 andhs r6, r0, r2, lsl #16 */
/* @0x2e4978 .word 0xf8123a01 */
/* @0x2e497c tstlt r11, r1, lsl #30 */
/* @0x2e4980 bne 0x4e4e8c <SrcVerts+0x41ed0> */
/* @0x2e4984 .word 0xe7f84418 */
/* @0x2e4988 stmdavs r3, {r4, r5, r6, r8, r9, r10, lr} */
/* @0x2e498c andhs pc, r7, #201326595 */
/* @0x2e4990 bl 0x3914fc <ft_adobe_glyph_list+0xbd8> */
/* @0x2e4994 bne 0x17692a0 <b2_toiTime+0x100fdfc> */
/* @0x2e4998 bne 0xfe564ee4 <b2_toiTime+0xfffffffffde0ba40> */
/* @0x2e499c smlabtmi r7, r3, r3, pc */
/* @0x2e49a0 cmpeq r1, r10, lsl #8 */
/* @0x2e49a4 bl 0x2eb3cc <FT_Done_Memory+0x1758> */
/* @0x2e49a8 .word 0x47706013 */
/* @0x2e49ac stmdavs r8, {r0, r1, r11, sp, lr} */
/* @0x2e49b0 subsmi r1, r8, #110592 */
/* @0x2e49b4 .word 0x47704158 */
/* @0x2e49b8 mcrge p5, #0x0, r11, c2, c7, #0x7 */
/* @0x2e49bc strmi r6, [sp], -r11, asr #17 */
/* @0x2e49c0 stceq p8, c15, [r4, #-280] */
/* @0x2e49c4 stmdbvs pc, {r4, r5, r9, r10, lr} ^ */
/* @0x2e49c8 stmdavs r9!, {r3, r4, r7, r8, r9, r10, lr} ^ */
/* @0x2e49cc ldmib r0, {r2, r4, r5, r12, sp, lr, pc} */
/* @0x2e49d0 streq lr, [r1], #2823 */
/* @0x2e49d4 .word 0xb1686820 */
/* @0x2e49d8 ldrtmi r6, [r1], -r11, lsr #18 */
/* @0x2e49dc stmdblt r8, {r3, r4, r7, r8, r9, r10, lr} ^ */
/* @0x2e49e0 adcsmi r3, r12, #4, #24 */
/* @0x2e49e4 stmdavs r12!, {r1, r2, r4, r5, r6, r7, r9, r12, lr, pc} ^ */
/* @0x2e49e8 strmi pc, [r0], #260 */
/* @0x2e49ec bl 0x4b39f8 <SrcVerts+0x10a3c> */
/* @0x2e49f0 strb r0, [pc, r4, lsl #9]! */
/* @0x2e49f4 andlt r4, r3, r0, lsr #12 */
/* @0x2e49f8 strdeq r11, r12, [r0], -r0 */
/* @0x2e49fc bvs 0xfe3d21c4 <b2_toiTime+0xfffffffffdc78d20> */
/* @0x2e4a00 bvs 0x14111f4 <b2_toiTime+0xcb7d50> */
/* @0x2e4a04 svcmi #0x114e10 */
/* @0x2e4a08 streq lr, [r4], #2819 */
/* @0x2e4a0c blo 0x3f629c <g_MP3UpdateVolume+0xfc0> */
/* @0x2e4a10 movwle r4, #0xa29a */
/* @0x2e4a14 stmdavs sp, {r0, r4, r11, sp, lr} ^ */
/* @0x2e4a18 ldrhle r4, [r8, #37]! */
/* @0x2e4a1c adcsmi r6, sp, #9240576 */
/* @0x2e4a20 .word 0xf5b5d00c */
/* @0x2e4a24 mvnsle r2, r0, lsl #31 */
/* @0x2e4a28 stcmi p0, c14, [r7, #-32] */
/* @0x2e4a2c addsmi r1, r10, #34, #30 */
/* @0x2e4a30 .word 0xf852d307 */
/* @0x2e4a34 stmdavs r12, {r2, r8, r11, r12} ^ */
/* @0x2e4a38 mvnsle r4, r12, lsr #5 */
/* @0x2e4a3c andhs r6, r0, r1, asr #11 */
/* @0x2e4a40 .word 0x2026bdf0 */
/* @0x2e4a44 svclt #0xbdf0 */
/* @0x2e4a48 strbvc r6, [lr, #-0x963]! */
/* @0x2e4a4c andeq r0, r10, r3 */
/* @0x2e4a50 strhlo pc, [r0], -r0 */
/* @0x2e4a54 strhhs pc, [r0], -r1 */
/* @0x2e4a58 blle 0x3b54ac <error_g0017+0xe150> */
/* @0x2e4a5c ldrdhs r11, r12, [r0], -r4 */
/* @0x2e4a60 ldrbmi r2, [r0, -r1]! */
/* @0x2e4a64 rscslo pc, pc, pc, asr #32 */
/* @0x2e4a68 stmdahs r0, {r4, r5, r6, r8, r9, r10, lr} */
/* @0x2e4a6c submi r11, r0, #184, #30 */
/* @0x2e4a70 b 0x16d2238 <b2_toiTime+0xf78d94> */
/* @0x2e4a74 addlt r4, r1, #16, #10 */
/* @0x2e4a78 ldrlo pc, [r6, -r5, asr #12] */
/* @0x2e4a7c .word 0xf005fb07 */
/* @0x2e4a80 ldrblo pc, [r9], sp, asr #12 */
/* @0x2e4a84 movweq pc, #0x1b06 */
/* @0x2e4a88 .word 0xf04fbfb4 */
/* @0x2e4a8c andhs r3, r1, #-268435441 */
/* @0x2e4a90 svclt #0x344283 */
/* @0x2e4a94 addlo pc, r0, pc, asr #8 */
/* @0x2e4a98 ldreq r2, [r12], #-0 */
/* @0x2e4a9c blx 0x4a7b12 <SrcVerts+0x4b56> */
/* @0x2e4aa0 blx 0x474eae <g_RomDisk+0x7d68e> */
/* @0x2e4aa4 adcmi r3, r1, #20971520 */
/* @0x2e4aa8 strtmi r11, [r12], -r12, lsr #30 */
/* @0x2e4aac .word 0xf1b11c6c */
/* @0x2e4ab0 svclt #0x344f40 */
/* @0x2e4ab4 stclne p6, c4, [r1], #-132 */
/* @0x2e4ab8 strmi r3, [r8], #-513 */
/* @0x2e4abc submi r11, r0, #8, #30 */
/* @0x2e4ac0 strdeq r11, r12, [r0], -r0 */
/* @0x2e4ac4 muleq r12, r0, r8 */
/* @0x2e4ac8 mvnsmi lr, sp, lsr #18 */
/* @0x2e4acc svcne #0x34f511 */
/* @0x2e4ad0 subsmi sp, r4, #20480 */
/* @0x2e4ad4 .word 0x01b4f501 */
/* @0x2e4ad8 qadd16mi r4, r3, r10 */
/* @0x2e4adc .word 0xf5b1e7f6 */
/* @0x2e4ae0 stcle p15, c1, [r5, #-208] */
/* @0x2e4ae4 .word 0xf5a1425c */
/* @0x2e4ae8 .word 0x461301b4 */
/* @0x2e4aec ldrb r4, [r6, r2, lsr #12]! */
/* @0x2e4af0 strhs r4, [r1, #-0xe10] */
/* @0x2e4af4 ldrbtmi r4, [lr], #-1580 */
/* @0x2e4af8 .word 0x0c05eb03 */
/* @0x2e4afc stmdbhs r0, {r0, r1, r2, r4, r6, r8, r11, r12} */
/* @0x2e4b00 stmdaeq r4, {r1, r2, r8, r12, sp, lr, pc} */
/* @0x2e4b04 .word 0xfc04fa4c */
/* @0x2e4b08 blx 0x14bebe8 <b2_toiTime+0xd65744> */
/* @0x2e4b0c ble 0x3e2724 <error_g0017+0x3b3c8> */
/* @0x2e4b10 ldrtmi r1, [r1], #-3035 */
/* @0x2e4b14 and r4, r3, r2, ror #8 */
/* @0x2e4b18 blne 0xfe535c0c <b2_toiTime+0xfffffffffdddc768> */
/* @0x2e4b1c andeq lr, r2, #204, #22 */
/* @0x2e4b20 rsbeq r3, sp, r1, lsl #8 */
/* @0x2e4b24 andle r2, r1, r7, lsl r12 */
/* @0x2e4b28 strb r4, [r5, r6, asr #12]! */
/* @0x2e4b2c andeq lr, r12, r0, lsl #17 */
/* @0x2e4b30 ldrhhi lr, [r0, #141]! */
/* @0x2e4b34 strheq r11, [r10], -r6 */
/* @0x2e4b38 muleq r12, r0, r8 */
/* @0x2e4b3c mvnsmi lr, sp, lsr #18 */
/* @0x2e4b40 .word 0xf1c24293 */
/* @0x2e4b44 stcle p1, c0, [lr, #-0] */
/* @0x2e4b48 strmi r4, [r10], -r11, lsl #5 */
/* @0x2e4b4c stmdbmi r0!, {r1, r2, r10, r11, r12, lr, pc} */
/* @0x2e4b50 svclt #0xc82b00 */
/* @0x2e4b54 teqeq r4, pc, asr #8 */
/* @0x2e4b58 and r4, r7, r11, asr r2 */
/* @0x2e4b5c .word 0x460b461a */
/* @0x2e4b60 .word 0x01b4f44f */
/* @0x2e4b64 addmi lr, r11, #2 */
/* @0x2e4b68 .word 0x2100db05 */
/* @0x2e4b6c strhs r4, [r1, #-0xe1a] */
/* @0x2e4b70 ldrbtmi r4, [lr], #-1580 */
/* @0x2e4b74 subsmi lr, r9, #13 */
/* @0x2e4b78 .word 0x460a4613 */
/* @0x2e4b7c .word 0xe7f54915 */
/* @0x2e4b80 blne 0xfe535c74 <b2_toiTime+0xfffffffffdddc7d0> */
/* @0x2e4b84 andeq lr, r2, #204, #22 */
/* @0x2e4b88 rsbeq r3, sp, r1, lsl #8 */
/* @0x2e4b8c andsle r2, r0, r7, lsl r12 */
/* @0x2e4b90 bl 0x3b64b0 <error_g0017+0xf154> */
/* @0x2e4b94 ldmdbne r7, {r0, r2, r10, r11} ^ */
/* @0x2e4b98 .word 0xf1062b00 */
/* @0x2e4b9c blx 0x15e6bb4 <b2_toiTime+0xe8d710> */
/* @0x2e4ba0 ldmdavs r6!, {r2, r10, r11, r12, sp, lr, pc} */
/* @0x2e4ba4 .word 0xf704fa47 */
/* @0x2e4ba8 blne 0xff9dc358 <b2_toiTime+0xffffffffff282eb4> */
/* @0x2e4bac strbtmi r4, [r2], #-1073 */
/* @0x2e4bb0 stmdbhs r0, {r1, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2e4bb4 .word 0x3108db03 */
/* @0x2e4bb8 .word 0x010ff021 */
/* @0x2e4bbc .word 0xf1c1e004 */
/* @0x2e4bc0 .word 0xf0210108 */
/* @0x2e4bc4 submi r0, r9, #-1073741821 */
/* @0x2e4bc8 subvs r6, r1, r2 */
/* @0x2e4bcc ldrhhi lr, [r0, #141]! */
/* @0x2e4bd0 .word 0xff4c0000 */
/* @0x2e4bd4 .word 0xffa60000 */
/* @0x2e4bd8 andeq r11, r10, r10, lsr r10 */
/* @0x2e4bdc .word 0x4603b510 */
/* @0x2e4be0 muleq r6, r0, r8 */
/* @0x2e4be4 strbtvc lr, [r2], #2690 */
/* @0x2e4be8 strbtvc lr, [r2], #2980 */
/* @0x2e4bec rscvc lr, r1, r1, lsl #21 */
/* @0x2e4bf0 rscvc lr, r1, r0, lsr #23 */
/* @0x2e4bf4 blx 0xfeef587c <b2_toiTime+0xfffffffffe79c3d8> */
/* @0x2e4bf8 .word 0xf1c0f080 */
/* @0x2e4bfc .word 0x2c1d041f */
/* @0x2e4c00 stmdalo r2, {r0, r2, r10, r11, r12, lr, pc} */
/* @0x2e4c04 addmi r4, r2, r1, lsl #1 */
/* @0x2e4c08 subsvs r6, r10, r9, lsl r0 */
/* @0x2e4c0c .word 0xf1c0bd10 */
/* @0x2e4c10 mrsmi r0, apsr */
/* @0x2e4c14 andsvs r4, r9, r2, lsl #2 */
/* @0x2e4c18 subsvs r4, r10, r0, asr #4 */
/* @0x2e4c1c strlt r11, [r8, #-0xd10] */
/* @0x2e4c20 stmdavs r9, {r11, sp, lr} */
/* @0x2e4c24 stmdavc r11, {r1, r11, r12, sp, lr} */
/* @0x2e4c28 swple r4, r10, [r6] */
/* @0x2e4c2c stc p5, c15, [r2], #836 */
/* @0x2e4c30 .word 0x0001f1d0 */
/* @0x2e4c34 andhs r11, r0, r8, lsr pc */
/* @0x2e4c38 andhs r11, r0, r8, lsl #26 */
/* @0x2e4c3c ldrblt r11, [r8, #0xd08]! */
/* @0x2e4c40 blx 0xfeef649c <b2_toiTime+0xfffffffffe79cff8> */
/* @0x2e4c44 .word 0xf1c2f280 */
/* @0x2e4c48 addsmi r0, r0, r0, lsr #8 */
/* @0x2e4c4c .word 0xf704fa21 */
/* @0x2e4c50 .word 0xf602fa01 */
/* @0x2e4c54 strtmi r4, [r9], -r7, lsl #6 */
/* @0x2e4c58 .word 0xf0334638 */
/* @0x2e4c5c blx 0x460c3e <g_RomDisk+0x6941e> */
/* @0x2e4c60 svceq #0xf27310 */
/* @0x2e4c64 b 0x1364d6c <b2_toiTime+0xc0b8c8> */
/* @0x2e4c68 rsbseq r0, r6, r3, asr #6 */
/* @0x2e4c6c svclt #0x2442ab */
/* @0x2e4c70 movweq lr, #0x3bc5 */
/* @0x2e4c74 andeq pc, r1, r0, asr #32 */
/* @0x2e4c78 mvnsle r3, r1, lsl #24 */
/* @0x2e4c7c strdeq r11, r12, [r0], -r8 */
/* @0x2e4c80 .word 0x43f8e92d */
/* @0x2e4c84 ldrmi r4, [r6], -r8, lsl #13 */
/* @0x2e4c88 stmdahs r0, {r0, r1, r2, r3, r4, r9, r10, lr} */
/* @0x2e4c8c stmdbhs r0, {r1, r2, r3, r4, r5, r12, lr, pc} */
/* @0x2e4c90 bhs 0x318d94 <__divsi3+0x84> */
/* @0x2e4c94 blhs 0x318d90 <__divsi3+0x80> */
/* @0x2e4c98 stmdbvs r3, {r0, r1, r3, r4, r5, r12, lr, pc} */
/* @0x2e4c9c ldreq pc, [r4, #-0x100] */
/* @0x2e4ca0 stmibeq r3, {r0, r2, r8, r9, r11, sp, lr, pc} */
/* @0x2e4ca4 strtmi r4, [r12], -sp, asr #10 */
/* @0x2e4ca8 stmdavs r3!, {r3, r9, r12, lr, pc} */
/* @0x2e4cac strlo r4, [r4, #-0x641] */
/* @0x2e4cb0 ldmvs r8, {r0, r1, r3, r4, r11, sp, lr} */
/* @0x2e4cb4 mrrc p5, #0xd, pc, lr, c1 */
/* @0x2e4cb8 mvnsle r2, r0, lsl #16 */
/* @0x2e4cbc eorle r4, r2, r12, asr #10 */
/* @0x2e4cc0 stmdavs r3, {r5, r11, sp, lr} */
/* @0x2e4cc4 ldmdblt r3, {r0, r1, r3, r4, r9, r11, sp, lr} */
/* @0x2e4cc8 pop {r0, r1, r2, sp} */
/* @0x2e4ccc ldmdbmi r2, {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2e4cd0 .word 0x47984479 */
/* @0x2e4cd4 rscsle r2, r7, r0, lsl #16 */
/* @0x2e4cd8 mlalo r0, sp, r8, pc */
/* @0x2e4cdc stmdavs r5, {r0, r1, r4, r6, r8, r12, sp, pc} */
/* @0x2e4ce0 rscsle r2, r1, r0, lsl #26 */
/* @0x2e4ce4 ldrtmi r6, [r1], -r0, lsr #16 */
/* @0x2e4ce8 .word 0xf89d463a */
/* @0x2e4cec strmi r3, [r8, r4, lsr #32]! */
/* @0x2e4cf0 .word 0x83f8e8bd */
/* @0x2e4cf4 blhs 0x2fee08 <TT_RunIns+0x2014> */
/* @0x2e4cf8 stmdavs r0!, {r1, r2, r5, r6, r7, r12, lr, pc} */
/* @0x2e4cfc shasxmi r4, r10, r1 */
/* @0x2e4d00 pop {r3, r4, r7, r8, r9, r10, lr} */
/* @0x2e4d04 strdhs r8, r9, [r11], -r8 */
/* @0x2e4d08 .word 0x83f8e8bd */
/* @0x2e4d0c pop {r0, r5, sp} */
/* @0x2e4d10 strdhs r8, r9, [r6], -r8 */
/* @0x2e4d14 .word 0x83f8e8bd */
/* @0x2e4d18 andeq r9, r10, r9, lsl #20 */

/* ── FUNC 0x2e4d1c · FT_RoundFix · size=14 · insn=5 */
/* @0x2e4d1c add.w r3, r0, #0x8000 */
/* @0x2e4d20 sub.w r0, r3, r0, lsr #31 */
/* @0x2e4d24 lsrs r0, r0, #0x10 */
/* @0x2e4d26 lsls r0, r0, #0x10 */
/* @0x2e4d28 bx lr */

/* ── FUNC 0x2e4d2a · FT_CeilFix · size=12 · insn=5 */
/* @0x2e4d2a add.w r0, r0, #0xff00 */
/* @0x2e4d2e adds r0, #0xff */
/* @0x2e4d30 lsrs r0, r0, #0x10 */
/* @0x2e4d32 lsls r0, r0, #0x10 */
/* @0x2e4d34 bx lr */

/* ── FUNC 0x2e4d36 · FT_FloorFix · size=6 · insn=3 */
/* @0x2e4d36 lsrs r0, r0, #0x10 */
/* @0x2e4d38 lsls r0, r0, #0x10 */
/* @0x2e4d3a bx lr */

/* ── FUNC 0x2e4d3c · FT_MulDiv · size=118 · insn=56 */
/* @0x2e4d3c push {r0, r1, r4, r5, r6, lr} */
/* @0x2e4d3e cmp r0, #0x0 */
/* @0x2e4d40 it lt */
/* @0x2e4d42 rsblt r0, r0, #0 */
/* @0x2e4d44 mov r4, r2 */
/* @0x2e4d46 ite lt */
/* @0x2e4d48 movlt.w r5, #0xffffffff */
/* @0x2e4d4c movge r5, #0x1 */
/* @0x2e4d4e cmp r1, #0x0 */
/* @0x2e4d50 itt lt */
/* @0x2e4d52 rsblt r5, r5, #0 */
/* @0x2e4d54 rsblt r1, r1, #0 */
/* @0x2e4d56 cmp r2, #0x0 */
/* @0x2e4d58 itt lt */
/* @0x2e4d5a rsblt r4, r2, #0 */
/* @0x2e4d5c rsblt r5, r5, #0 */
/* @0x2e4d5e cbz r4, 0x2e4da4 <FT_MulDiv+0x68> */
/* @0x2e4d60 lsrs r3, r4, #0x11 */
/* @0x2e4d62 adds r2, r1, r0 */
/* @0x2e4d64 rsb.w r3, r3, #0x1fa00 */
/* @0x2e4d68 lsrs r6, r4, #0x1 */
/* @0x2e4d6a add.w r3, r3, #0x166 */
/* @0x2e4d6c addsmi r7, r3, #-872415230 */
/* @0x2e4d6e cmp r3, r2 */
/* @0x2e4d70 blo 0x2e4d78 <FT_MulDiv+0x3c> */
/* @0x2e4d72 mla r0, r0, r1, r6 */
/* @0x2e4d74 and r6, r11, r1 */
/* @0x2e4d76 b 0x2e4d90 <FT_MulDiv+0x54> */
/* @0x2e4d78 mov r2, sp */
/* @0x2e4d7a bl 0x2e490c <_ZNK11b2GearJoint8GetRatioEv+0x8> */
/* @0x2e4d7c stmdbls r0, {r0, r1, r2, r6, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2e4d7e ldr r1, [sp] */
/* @0x2e4d80 ldr r3, [sp, #0x4] */
/* @0x2e4d82 adds r1, r6, r1 */
/* @0x2e4d84 ite lo */
/* @0x2e4d86 movlo r0, #0x0 */
/* @0x2e4d88 movhs r0, #0x1 */
/* @0x2e4d8a adds r0, r0, r3 */
/* @0x2e4d8c bne 0x2e4d98 <FT_MulDiv+0x5c> */
/* @0x2e4d8e mov r0, r1 */
/* @0x2e4d90 mov r1, r4 */
/* @0x2e4d92 blx 0x318c48 <__udivsi3> */
/* @0x2e4d94 and lr, r7, r10, asr pc */
/* @0x2e4d96 b 0x2e4da8 <FT_MulDiv+0x6c> */
/* @0x2e4d98 cmp r0, r4 */
/* @0x2e4d9a bhs 0x2e4da4 <FT_MulDiv+0x68> */
/* @0x2e4d9c mov r2, r4 */
/* @0x2e4d9e bl 0x2e4c3e <_ZNK11b2GearJoint8GetRatioEv+0x33a> */
/* @0x2e4da0 and pc, r1, lr, asr #30 */
/* @0x2e4da2 b 0x2e4da8 <FT_MulDiv+0x6c> */
/* @0x2e4da4 mvn r0, #0x80000000 */
/* @0x2e4da8 adds r5, #0x1 */
/* @0x2e4daa it eq */
/* @0x2e4dac rsbeq r0, r0, #0 */
/* @0x2e4dae add sp, #0x8 */
/* @0x2e4db0 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2e4db4 · anon_2e4db4 · size=52 · insn=14 */
/* @0x2e4db4 streq pc, [r1], #-19 */
/* @0x2e4db8 tstle r5, r7, lsl r6 */
/* @0x2e4dbc orrlt r6, r8, r0, lsl #16 */
/* @0x2e4dc0 .word 0xf0136905 */
/* @0x2e4dc4 stmdbvs r2, {r4, r8, r9, r10, r11} ^ */
/* @0x2e4dc8 svclt #0x18460e */
/* @0x2e4dcc adcsmi r4, r12, #22020096 */
/* @0x2e4dd0 ldmdavs r0!, {r1, r3, r12, lr, pc} */
/* @0x2e4dd4 subhs r4, r0, #42991616 */
/* @0x2e4dd8 .word 0xf7ff3401 */
/* @0x2e4ddc .word 0xf846ffaf */
/* @0x2e4de0 ldrb r0, [r4, r4, lsl #22]! */
/* @0x2e4de4 ldcllt p0, c2, [r8, #144]! */
/* @0x2e4de8 ldcllt p0, c2, [r8, #0]! */

/* ── FUNC 0x2e4dec · FT_MulDiv_No_Round · size=96 · insn=46 */
/* @0x2e4dec push {r0, r1, r2, r4, r5, lr} */
/* @0x2e4dee cmp r0, #0x0 */
/* @0x2e4df0 it lt */
/* @0x2e4df2 rsblt r0, r0, #0 */
/* @0x2e4df4 mov r4, r2 */
/* @0x2e4df6 ite lt */
/* @0x2e4df8 movlt.w r5, #0xffffffff */
/* @0x2e4dfc movge r5, #0x1 */
/* @0x2e4dfe cmp r1, #0x0 */
/* @0x2e4e00 itt lt */
/* @0x2e4e02 rsblt r5, r5, #0 */
/* @0x2e4e04 rsblt r1, r1, #0 */
/* @0x2e4e06 cmp r2, #0x0 */
/* @0x2e4e08 itt lt */
/* @0x2e4e0a rsblt r4, r2, #0 */
/* @0x2e4e0c rsblt r5, r5, #0 */
/* @0x2e4e0e cbz r4, 0x2e4e3e <FT_MulDiv_No_Round+0x52> */
/* @0x2e4e10 adds r3, r1, r0 */
/* @0x2e4e12 cmp.w r3, #0x20000 */
/* @0x2e4e14 andle r3, r1, #0, #30 */
/* @0x2e4e16 bhs 0x2e4e1c <FT_MulDiv_No_Round+0x30> */
/* @0x2e4e18 muls r0, r1, r0 */
/* @0x2e4e1a b 0x2e4e28 <FT_MulDiv_No_Round+0x3c> */
/* @0x2e4e1c mov r2, sp */
/* @0x2e4e1e bl 0x2e490c <_ZNK11b2GearJoint8GetRatioEv+0x8> */
/* @0x2e4e20 stmdals r1, {r0, r2, r4, r5, r6, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2e4e22 ldr r0, [sp, #0x4] */
/* @0x2e4e24 cbnz r0, 0x2e4e30 <FT_MulDiv_No_Round+0x44> */
/* @0x2e4e26 ldr r0, [sp] */
/* @0x2e4e28 mov r1, r4 */
/* @0x2e4e2a blx 0x318c48 <__udivsi3> */
/* @0x2e4e2c and lr, r8, lr, lsl #30 */
/* @0x2e4e2e b 0x2e4e42 <FT_MulDiv_No_Round+0x56> */
/* @0x2e4e30 cmp r0, r4 */
/* @0x2e4e32 ldr r1, [sp] */
/* @0x2e4e34 bhs 0x2e4e3e <FT_MulDiv_No_Round+0x52> */
/* @0x2e4e36 mov r2, r4 */
/* @0x2e4e38 bl 0x2e4c3e <_ZNK11b2GearJoint8GetRatioEv+0x33a> */
/* @0x2e4e3c b 0x2e4e42 <FT_MulDiv_No_Round+0x56> */
/* @0x2e4e3e mvn r0, #0x80000000 */
/* @0x2e4e40 strlo r4, [r1, #-0x0] */
/* @0x2e4e42 adds r5, #0x1 */
/* @0x2e4e44 it eq */
/* @0x2e4e46 rsbeq r0, r0, #0 */
/* @0x2e4e48 add sp, #0xc */
/* @0x2e4e4a pop {r4, r5, pc} */
