/* libyoyo.so 覆盖卡组 0219
 * 函数 0x242edc..0x244c68，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x242edc · myswap(RValue*, int, int) · size=120 · insn=30 */
/* @0x242edc push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x242ee0 add r4, r0, r1, lsl #4 */
/* @0x242ee4 add r12, r0, r2, lsl #4 */
/* @0x242ee8 mov r7, r0 */
/* @0x242eec ldr r3, [r4, #0xc] */
/* @0x242ef0 sub sp, sp, #16 */
/* @0x242ef4 ldr r0, [r4] */
/* @0x242ef8 mov r9, r1 */
/* @0x242efc mov r8, r2 */
/* @0x242f00 ldr r1, [r4, #0x4] */
/* @0x242f04 ldr r2, [r4, #0x8] */
/* @0x242f08 mov r5, sp */
/* @0x242f0c mov r6, sp */
/* @0x242f10 ldr r10, [r12, #0x4] */
/* @0x242f14 ldr r11, [r12] */
/* @0x242f18 stm r6!, {r0, r1, r2, r3} */
/* @0x242f1c ldm r5!, {r0, r1, r2, r3} */
/* @0x242f20 ldr r6, [r12, #0x8] */
/* @0x242f24 ldr r5, [r12, #0xc] */
/* @0x242f28 str r11, [r7, r9, lsl #4] */
/* @0x242f2c str r10, [r4, #0x4] */
/* @0x242f30 str r6, [r4, #0x8] */
/* @0x242f34 str r5, [r4, #0xc] */
/* @0x242f38 str r0, [r7, r8, lsl #4] */
/* @0x242f3c str r1, [r12, #0x4] */
/* @0x242f40 str r2, [r12, #0x8] */
/* @0x242f44 str r3, [r12, #0xc] */
/* @0x242f48 add sp, sp, #16 */
/* @0x242f4c pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x242f50 bx lr */

/* ── FUNC 0x242f54 · mysort(RValue*, int, int, RValue*, E_MYSORTVAL (*)(RValue*, RValue*, RValue*)) · size=288 · insn=72 */
/* @0x242f54 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x242f58 cmp r1, r2 */
/* @0x242f5c sub sp, sp, #20 */
/* @0x242f60 mov r10, r0 */
/* @0x242f64 mov r5, r2 */
/* @0x242f68 mov r9, r1 */
/* @0x242f6c mov r6, r3 */
/* @0x242f70 ldr r7, [sp, #0x38] */
/* @0x242f74 movge r0, #0 */
/* @0x242f78 blt 0x242f84 <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E+0x30> */
/* @0x242f7c add sp, sp, #20 */
/* @0x242f80 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x242f84 add r3, r1, r2 */
/* @0x242f88 add r4, r1, #1 */
/* @0x242f8c add r2, r3, r3, lsr #31 */
/* @0x242f90 asr r2, r2, #1 */
/* @0x242f94 bl 0x242edc <_Z6myswapP6RValueii> */
/* @0x242f98 cmp r5, r4 */
/* @0x242f9c blt 0x24306c <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E+0x118> */
/* @0x242fa0 lsl r8, r9, #4 */
/* @0x242fa4 str r9, [sp, #0xc] */
/* @0x242fa8 add r3, r8, #16 */
/* @0x242fac add r8, r10, r8 */
/* @0x242fb0 add r11, r10, r3 */
/* @0x242fb4 b 0x242fc4 <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E+0x70> */
/* @0x242fb8 add r4, r4, #1 */
/* @0x242fbc cmp r5, r4 */
/* @0x242fc0 blt 0x243014 <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E+0xc0> */
/* @0x242fc4 mov r1, r11 */
/* @0x242fc8 mov r2, r8 */
/* @0x242fcc mov r0, r6 */
/* @0x242fd0 add r11, r11, #16 */
/* @0x242fd4 blx r7 */
/* @0x242fd8 add r2, r0, #5 */
/* @0x242fdc cmp r2, #1 */
/* @0x242fe0 bls 0x242f7c <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E+0x28> */
/* @0x242fe4 cmp r0, #0 */
/* @0x242fe8 bge 0x242fb8 <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E+0x64> */
/* @0x242fec ldr r3, [sp, #0xc] */
/* @0x242ff0 mov r2, r4 */
/* @0x242ff4 mov r0, r10 */
/* @0x242ff8 add r4, r4, #1 */
/* @0x242ffc add r3, r3, #1 */
/* @0x243000 str r3, [sp, #0xc] */
/* @0x243004 mov r1, r3 */
/* @0x243008 bl 0x242edc <_Z6myswapP6RValueii> */
/* @0x24300c cmp r5, r4 */
/* @0x243010 bge 0x242fc4 <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E+0x70> */
/* @0x243014 ldr r3, [sp, #0xc] */
/* @0x243018 add r4, r3, #1 */
/* @0x24301c mov r0, r10 */
/* @0x243020 mov r1, r9 */
/* @0x243024 ldr r2, [sp, #0xc] */
/* @0x243028 bl 0x242edc <_Z6myswapP6RValueii> */
/* @0x24302c ldr r3, [sp, #0xc] */
/* @0x243030 mov r1, r9 */
/* @0x243034 str r7, [sp] */
/* @0x243038 sub r2, r3, #1 */
/* @0x24303c mov r0, r10 */
/* @0x243040 mov r3, r6 */
/* @0x243044 bl 0x242f54 <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E> */
/* @0x243048 str r7, [sp] */
/* @0x24304c mov r0, r10 */
/* @0x243050 mov r1, r4 */
/* @0x243054 mov r2, r5 */
/* @0x243058 mov r3, r6 */
/* @0x24305c bl 0x242f54 <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E> */
/* @0x243060 mov r0, #0 */
/* @0x243064 add sp, sp, #20 */
/* @0x243068 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24306c str r9, [sp, #0xc] */
/* @0x243070 b 0x24301c <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E+0xc8> */

/* ── FUNC 0x243074 · JS_ArrayObjectSetup() · size=1496 · insn=374 */
/* @0x243074 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x243078 sub sp, sp, #28 */
/* @0x24307c mov r4, #0 */
/* @0x243080 add r0, sp, #8 */
/* @0x243084 mov r1, r4 */
/* @0x243088 mov r2, r4 */
/* @0x24308c mov r3, r4 */
/* @0x243090 str r4, [sp] */
/* @0x243094 ldr r6, [pc, #0x4e0] */
/* @0x243098 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x24309c ldr r3, [pc, #0x4dc] */
/* @0x2430a0 add r6, pc, r6 */
/* @0x2430a4 ldr r5, [sp, #0x8] */
/* @0x2430a8 ldr r2, [pc, #0x4d4] */
/* @0x2430ac ldr r8, [r6, r3] */
/* @0x2430b0 ldr r3, [pc, #0x4d0] */
/* @0x2430b4 add r2, pc, r2 */
/* @0x2430b8 str r2, [r5, #0x40] */
/* @0x2430bc mov r0, r5 */
/* @0x2430c0 str r5, [r8] */
/* @0x2430c4 ldr r3, [r6, r3] */
/* @0x2430c8 ldr r1, [r3] */
/* @0x2430cc str r1, [r5, #0x18] */
/* @0x2430d0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x2430d4 ldr r3, [pc, #0x4b0] */
/* @0x2430d8 ldr r0, [r5, #0x28] */
/* @0x2430dc mov r1, r4 */
/* @0x2430e0 mov r2, r4 */
/* @0x2430e4 orr r0, r0, #1 */
/* @0x2430e8 str r0, [r5, #0x28] */
/* @0x2430ec ldr r0, [r6, r3] */
/* @0x2430f0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2430f4 ldr r1, [pc, #0x494] */
/* @0x2430f8 mov r3, #6 */
/* @0x2430fc add r1, pc, r1 */
/* @0x243100 mov r2, r0 */
/* @0x243104 mov r0, r5 */
/* @0x243108 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x24310c ldr r3, [pc, #0x480] */
/* @0x243110 mov r1, r4 */
/* @0x243114 mov r2, r4 */
/* @0x243118 ldr r0, [r6, r3] */
/* @0x24311c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243120 ldr r1, [pc, #0x470] */
/* @0x243124 mov r3, #6 */
/* @0x243128 add r1, pc, r1 */
/* @0x24312c mov r2, r0 */
/* @0x243130 mov r0, r5 */
/* @0x243134 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243138 ldr r3, [pc, #0x45c] */
/* @0x24313c mov r2, r4 */
/* @0x243140 mov r1, #1 */
/* @0x243144 ldr r0, [r6, r3] */
/* @0x243148 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x24314c ldr r1, [pc, #0x44c] */
/* @0x243150 mov r3, #6 */
/* @0x243154 add r1, pc, r1 */
/* @0x243158 mov r2, r0 */
/* @0x24315c mov r0, r5 */
/* @0x243160 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243164 ldr r3, [pc, #0x438] */
/* @0x243168 mov r1, r4 */
/* @0x24316c mov r2, r4 */
/* @0x243170 ldr r0, [r6, r3] */
/* @0x243174 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243178 ldr r1, [pc, #0x428] */
/* @0x24317c mov r3, #6 */
/* @0x243180 add r1, pc, r1 */
/* @0x243184 mov r2, r0 */
/* @0x243188 mov r0, r5 */
/* @0x24318c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243190 ldr r3, [pc, #0x414] */
/* @0x243194 mov r1, r4 */
/* @0x243198 mov r2, r4 */
/* @0x24319c ldr r0, [r6, r3] */
/* @0x2431a0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2431a4 ldr r1, [pc, #0x404] */
/* @0x2431a8 mov r3, #6 */
/* @0x2431ac add r1, pc, r1 */
/* @0x2431b0 mov r2, r0 */
/* @0x2431b4 mov r0, r5 */
/* @0x2431b8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2431bc ldr r3, [pc, #0x3f0] */
/* @0x2431c0 mov r2, r4 */
/* @0x2431c4 mov r1, #1 */
/* @0x2431c8 ldr r0, [r6, r3] */
/* @0x2431cc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2431d0 ldr r1, [pc, #0x3e0] */
/* @0x2431d4 mov r3, #6 */
/* @0x2431d8 add r1, pc, r1 */
/* @0x2431dc mov r2, r0 */
/* @0x2431e0 mov r0, r5 */
/* @0x2431e4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2431e8 ldr r3, [pc, #0x3cc] */
/* @0x2431ec mov r1, r4 */
/* @0x2431f0 mov r2, r4 */
/* @0x2431f4 ldr r0, [r6, r3] */
/* @0x2431f8 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2431fc ldr r1, [pc, #0x3bc] */
/* @0x243200 mov r3, #6 */
/* @0x243204 add r1, pc, r1 */
/* @0x243208 mov r2, r0 */
/* @0x24320c mov r0, r5 */
/* @0x243210 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243214 ldr r3, [pc, #0x3a8] */
/* @0x243218 mov r1, r4 */
/* @0x24321c mov r2, r4 */
/* @0x243220 ldr r0, [r6, r3] */
/* @0x243224 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243228 ldr r1, [pc, #0x398] */
/* @0x24322c mov r3, #6 */
/* @0x243230 add r1, pc, r1 */
/* @0x243234 mov r2, r0 */
/* @0x243238 mov r0, r5 */
/* @0x24323c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243240 ldr r3, [pc, #0x384] */
/* @0x243244 mov r2, r4 */
/* @0x243248 mov r1, #2 */
/* @0x24324c ldr r0, [r6, r3] */
/* @0x243250 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243254 ldr r1, [pc, #0x374] */
/* @0x243258 mov r3, #6 */
/* @0x24325c add r1, pc, r1 */
/* @0x243260 mov r2, r0 */
/* @0x243264 mov r0, r5 */
/* @0x243268 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x24326c ldr r3, [pc, #0x360] */
/* @0x243270 mov r2, r4 */
/* @0x243274 mov r1, #1 */
/* @0x243278 ldr r0, [r6, r3] */
/* @0x24327c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243280 ldr r1, [pc, #0x350] */
/* @0x243284 mov r3, #6 */
/* @0x243288 add r1, pc, r1 */
/* @0x24328c mov r2, r0 */
/* @0x243290 mov r0, r5 */
/* @0x243294 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243298 ldr r3, [pc, #0x33c] */
/* @0x24329c mov r2, r4 */
/* @0x2432a0 mov r1, #2 */
/* @0x2432a4 ldr r0, [r6, r3] */
/* @0x2432a8 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2432ac ldr r1, [pc, #0x32c] */
/* @0x2432b0 mov r3, #6 */
/* @0x2432b4 add r1, pc, r1 */
/* @0x2432b8 mov r2, r0 */
/* @0x2432bc mov r0, r5 */
/* @0x2432c0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2432c4 ldr r3, [pc, #0x318] */
/* @0x2432c8 mov r2, r4 */
/* @0x2432cc mov r1, #1 */
/* @0x2432d0 ldr r0, [r6, r3] */
/* @0x2432d4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2432d8 ldr r1, [pc, #0x308] */
/* @0x2432dc mov r3, #6 */
/* @0x2432e0 add r1, pc, r1 */
/* @0x2432e4 mov r2, r0 */
/* @0x2432e8 mov r0, r5 */
/* @0x2432ec bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2432f0 ldr r3, [pc, #0x2f4] */
/* @0x2432f4 mov r2, r4 */
/* @0x2432f8 mov r1, #1 */
/* @0x2432fc ldr r0, [r6, r3] */
/* @0x243300 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243304 ldr r1, [pc, #0x2e4] */
/* @0x243308 mov r3, #6 */
/* @0x24330c add r1, pc, r1 */
/* @0x243310 mov r2, r0 */
/* @0x243314 mov r0, r5 */
/* @0x243318 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x24331c ldr r3, [pc, #0x2d0] */
/* @0x243320 mov r2, r4 */
/* @0x243324 mov r1, #1 */
/* @0x243328 ldr r0, [r6, r3] */
/* @0x24332c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243330 ldr r1, [pc, #0x2c0] */
/* @0x243334 mov r3, #6 */
/* @0x243338 add r1, pc, r1 */
/* @0x24333c mov r2, r0 */
/* @0x243340 mov r0, r5 */
/* @0x243344 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243348 ldr r3, [pc, #0x2ac] */
/* @0x24334c mov r2, r4 */
/* @0x243350 mov r1, #1 */
/* @0x243354 ldr r0, [r6, r3] */
/* @0x243358 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x24335c ldr r1, [pc, #0x29c] */
/* @0x243360 mov r3, #6 */
/* @0x243364 add r1, pc, r1 */
/* @0x243368 mov r2, r0 */
/* @0x24336c mov r0, r5 */
/* @0x243370 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243374 ldr r3, [pc, #0x288] */
/* @0x243378 mov r2, r4 */
/* @0x24337c mov r1, #1 */
/* @0x243380 ldr r0, [r6, r3] */
/* @0x243384 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243388 ldr r1, [pc, #0x278] */
/* @0x24338c mov r3, #6 */
/* @0x243390 add r1, pc, r1 */
/* @0x243394 mov r2, r0 */
/* @0x243398 mov r0, r5 */
/* @0x24339c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2433a0 ldr r3, [pc, #0x264] */
/* @0x2433a4 mov r2, r4 */
/* @0x2433a8 mov r1, #1 */
/* @0x2433ac ldr r0, [r6, r3] */
/* @0x2433b0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2433b4 ldr r1, [pc, #0x254] */
/* @0x2433b8 mov r3, #6 */
/* @0x2433bc add r1, pc, r1 */
/* @0x2433c0 mov r2, r0 */
/* @0x2433c4 mov r0, r5 */
/* @0x2433c8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2433cc ldr r3, [pc, #0x240] */
/* @0x2433d0 mov r2, r4 */
/* @0x2433d4 mov r1, #1 */
/* @0x2433d8 ldr r0, [r6, r3] */
/* @0x2433dc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2433e0 ldr r1, [pc, #0x230] */
/* @0x2433e4 mov r3, #6 */
/* @0x2433e8 add r1, pc, r1 */
/* @0x2433ec mov r2, r0 */
/* @0x2433f0 mov r0, r5 */
/* @0x2433f4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2433f8 ldr r3, [pc, #0x21c] */
/* @0x2433fc mov r2, r4 */
/* @0x243400 mov r1, #1 */
/* @0x243404 ldr r0, [r6, r3] */
/* @0x243408 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x24340c ldr r1, [pc, #0x20c] */
/* @0x243410 mov r3, #6 */
/* @0x243414 add r1, pc, r1 */
/* @0x243418 mov r2, r0 */
/* @0x24341c mov r0, r5 */
/* @0x243420 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243424 ldr r3, [pc, #0x1f8] */
/* @0x243428 mov r2, r4 */
/* @0x24342c mov r1, #1 */
/* @0x243430 ldr r0, [r6, r3] */
/* @0x243434 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243438 ldr r1, [pc, #0x1e8] */
/* @0x24343c mov r3, #6 */
/* @0x243440 add r1, pc, r1 */
/* @0x243444 mov r2, r0 */
/* @0x243448 mov r0, r5 */
/* @0x24344c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243450 ldr r3, [pc, #0x1d4] */
/* @0x243454 mov r2, r4 */
/* @0x243458 mov r1, #1 */
/* @0x24345c ldr r0, [r6, r3] */
/* @0x243460 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243464 ldr r1, [pc, #0x1c4] */
/* @0x243468 mov r3, #6 */
/* @0x24346c add r1, pc, r1 */
/* @0x243470 mov r2, r0 */
/* @0x243474 mov r0, r5 */
/* @0x243478 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x24347c ldr r3, [pc, #0x1b0] */
/* @0x243480 mov r1, r4 */
/* @0x243484 mov r2, r4 */
/* @0x243488 ldr r9, [r6, r3] */
/* @0x24348c mov r0, r9 */
/* @0x243490 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243494 ldr r3, [pc, #0x19c] */
/* @0x243498 mov r1, r4 */
/* @0x24349c mov r2, r4 */
/* @0x2434a0 mov r7, r0 */
/* @0x2434a4 ldr r0, [r6, r3] */
/* @0x2434a8 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2434ac ldr r1, [pc, #0x188] */
/* @0x2434b0 mov r3, r4 */
/* @0x2434b4 add r1, pc, r1 */
/* @0x2434b8 mov r2, r0 */
/* @0x2434bc mov r0, r7 */
/* @0x2434c0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2434c4 ldr r1, [pc, #0x174] */
/* @0x2434c8 mov r3, r4 */
/* @0x2434cc str r9, [r7, #0x94] */
/* @0x2434d0 mov r0, r5 */
/* @0x2434d4 mov r2, r7 */
/* @0x2434d8 add r1, pc, r1 */
/* @0x2434dc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2434e0 ldr r3, [r7, #0x4] */
/* @0x2434e4 cmp r3, r4 */
/* @0x2434e8 beq 0x24353c <_Z19JS_ArrayObjectSetupv+0x4c8> */
/* @0x2434ec ldr r1, [r8] */
/* @0x2434f0 mov r0, r7 */
/* @0x2434f4 str r1, [r3] */
/* @0x2434f8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x2434fc ldr r1, [r7, #0x4] */
/* @0x243500 cmp r1, #0 */
/* @0x243504 movne r3, #6 */
/* @0x243508 strne r3, [r1, #0xc] */
/* @0x24350c beq 0x243550 <_Z19JS_ArrayObjectSetupv+0x4dc> */
/* @0x243510 ldr r0, [pc, #0x12c] */
/* @0x243514 mov r3, #0 */
/* @0x243518 str r3, [r1, #0x8] */
/* @0x24351c mov r2, r7 */
/* @0x243520 ldr r1, [pc, #0x120] */
/* @0x243524 ldr r0, [r6, r0] */
/* @0x243528 add r1, pc, r1 */
/* @0x24352c ldr r0, [r0] */
/* @0x243530 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243534 add sp, sp, #28 */
/* @0x243538 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x24353c mov r1, r3 */
/* @0x243540 mov r0, r7 */
/* @0x243544 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x243548 mov r3, r0 */
/* @0x24354c b 0x2434ec <_Z19JS_ArrayObjectSetupv+0x478> */
/* @0x243550 mov r0, r7 */
/* @0x243554 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x243558 ldr r1, [r7, #0x4] */
/* @0x24355c mov r3, #6 */
/* @0x243560 cmp r1, #0 */
/* @0x243564 str r3, [r0, #0xc] */
/* @0x243568 bne 0x243510 <_Z19JS_ArrayObjectSetupv+0x49c> */
/* @0x24356c mov r0, r7 */
/* @0x243570 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x243574 mov r1, r0 */
/* @0x243578 b 0x243510 <_Z19JS_ArrayObjectSetupv+0x49c> */
/* @0x24357c ldrheq lr, [r10], -r0 */
/* @0x243580 .word 0xfffff9b0 */
/* @0x243584 andseq r2, r1, r4, lsl #15 */
/* @0x243588 .word 0xffffc050 */
/* @0x24358c .word 0xfffff9c4 */
/* @0x243590 andeq pc, lr, r4, lsl r4 */
/* @0x243594 .word 0xfffff9c8 */
/* @0x243598 andseq r2, r1, r0, lsr #10 */
/* @0x24359c .word 0xfffff9cc */
/* @0x2435a0 andseq r2, r1, r4, lsr #12 */
/* @0x2435a4 .word 0xfffff9d0 */
/* @0x2435a8 andseq r2, r1, r4, asr #13 */
/* @0x2435ac .word 0xfffff9d4 */
/* @0x2435b0 andseq r2, r1, r0, lsr #13 */
/* @0x2435b4 .word 0xfffff9d8 */
/* @0x2435b8 andseq r2, r1, r8, ror r6 */
/* @0x2435bc .word 0xfffff9dc */
/* @0x2435c0 andseq r2, r1, r4, asr r6 */
/* @0x2435c4 .word 0xfffff9e0 */
/* @0x2435c8 andseq r2, r1, r0, lsr r6 */
/* @0x2435cc .word 0xfffff9e4 */
/* @0x2435d0 andseq r2, r1, r0, ror #10 */
/* @0x2435d4 .word 0xfffff9e8 */
/* @0x2435d8 andseq r2, r1, r0, ror #11 */
/* @0x2435dc .word 0xfffff9ec */
/* @0x2435e0 ldrheq r2, [r1], -r12 */
/* @0x2435e4 .word 0xfffff9f0 */
/* @0x2435e8 mulseq r1, r8, r5 */
/* @0x2435ec .word 0xfffff9f4 */
/* @0x2435f0 andseq r2, r1, r4, ror r4 */
/* @0x2435f4 .word 0xfffff9f8 */
/* @0x2435f8 andseq r2, r1, r0, asr r4 */
/* @0x2435fc .word 0xfffff9fc */
/* @0x243600 andseq r2, r1, r12, lsl r5 */
/* @0x243604 .word 0xfffffa00 */
/* @0x243608 ldrsheq r2, [r1], -r8 */
/* @0x24360c .word 0xfffffa04 */
/* @0x243610 ldrsbeq r2, [r1], -r4 */
/* @0x243614 .word 0xfffffa08 */
/* @0x243618 ldrheq r2, [r1], -r0 */
/* @0x24361c .word 0xfffffa0c */
/* @0x243620 andseq r2, r1, r8, lsl #9 */
/* @0x243624 .word 0xfffffa10 */
/* @0x243628 andseq r2, r1, r4, ror #8 */
/* @0x24362c .word 0xfffffa14 */
/* @0x243630 andseq r2, r1, r0, asr #8 */
/* @0x243634 .word 0xfffffa18 */
/* @0x243638 .word 0xfffffa1c */
/* @0x24363c andseq r2, r1, r4, lsl #8 */
/* @0x243640 andseq r2, r1, r12, asr #32 */
/* @0x243644 .word 0xffffbf64 */
/* @0x243648 strdeq r1, r2, [pc], -r0 */

/* ── FUNC 0x24364c · myisinf(double) · size=40 · insn=10 */
/* @0x24364c mov r3, #0 */
/* @0x243650 movt r3, #0x7ff0 */
/* @0x243654 mov r2, #0 */
/* @0x243658 and r1, r1, r3 */
/* @0x24365c and r0, r0, r2 */
/* @0x243660 cmp r1, r3 */
/* @0x243664 cmpeq r0, r2 */
/* @0x243668 movne r0, #0 */
/* @0x24366c moveq r0, #1 */
/* @0x243670 bx lr */

/* ── FUNC 0x243674 · myispos(double) · size=12 · insn=3 */
/* @0x243674 mvn r0, r1 */
/* @0x243678 lsr r0, r0, #31 */
/* @0x24367c bx lr */

/* ── FUNC 0x243680 · JS_MathObjectSetup() · size=1392 · insn=348 */
/* @0x243680 push {r4, r5, r6, r7, lr} */
/* @0x243684 sub sp, sp, #28 */
/* @0x243688 mov r4, #0 */
/* @0x24368c add r0, sp, #8 */
/* @0x243690 mov r2, r4 */
/* @0x243694 mov r1, r4 */
/* @0x243698 mov r3, r4 */
/* @0x24369c str r4, [sp] */
/* @0x2436a0 ldr r6, [pc, #0x488] */
/* @0x2436a4 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x2436a8 ldr r5, [sp, #0x8] */
/* @0x2436ac ldr r3, [pc, #0x480] */
/* @0x2436b0 add r6, pc, r6 */
/* @0x2436b4 ldr r7, [pc, #0x47c] */
/* @0x2436b8 mov r0, r5 */
/* @0x2436bc add r7, pc, r7 */
/* @0x2436c0 str r7, [r5, #0x40] */
/* @0x2436c4 ldr r3, [r6, r3] */
/* @0x2436c8 ldr r1, [r3] */
/* @0x2436cc str r1, [r5, #0x18] */
/* @0x2436d0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x2436d4 ldr r1, [pc, #0x460] */
/* @0x2436d8 mov r0, r5 */
/* @0x2436dc str r4, [sp] */
/* @0x2436e0 add r1, pc, r1 */
/* @0x2436e4 movw r2, #0x5769 */
/* @0x2436e8 movw r3, #0xbf0a */
/* @0x2436ec movt r2, #0x8b14 */
/* @0x2436f0 movt r3, #0x4005 */
/* @0x2436f4 bl 0x1999d0 <_ZN12YYObjectBase3AddEPKcdi> */
/* @0x2436f8 ldr r1, [pc, #0x440] */
/* @0x2436fc mov r0, r5 */
/* @0x243700 str r4, [sp] */
/* @0x243704 add r1, pc, r1 */
/* @0x243708 movw r2, #0x5516 */
/* @0x24370c movw r3, #0x6bb1 */
/* @0x243710 movt r2, #0xbbb5 */
/* @0x243714 movt r3, #0x4002 */
/* @0x243718 bl 0x1999d0 <_ZN12YYObjectBase3AddEPKcdi> */
/* @0x24371c ldr r1, [pc, #0x420] */
/* @0x243720 mov r0, r5 */
/* @0x243724 str r4, [sp] */
/* @0x243728 add r1, pc, r1 */
/* @0x24372c movw r2, #0x39ef */
/* @0x243730 movw r3, #0x2e42 */
/* @0x243734 movt r2, #0xfefa */
/* @0x243738 movt r3, #0x3fe6 */
/* @0x24373c bl 0x1999d0 <_ZN12YYObjectBase3AddEPKcdi> */
/* @0x243740 ldr r1, [pc, #0x400] */
/* @0x243744 mov r0, r5 */
/* @0x243748 str r4, [sp] */
/* @0x24374c add r1, pc, r1 */
/* @0x243750 movw r2, #0x82fe */
/* @0x243754 movw r3, #0x1547 */
/* @0x243758 movt r2, #0x652b */
/* @0x24375c movt r3, #0x3ff7 */
/* @0x243760 bl 0x1999d0 <_ZN12YYObjectBase3AddEPKcdi> */
/* @0x243764 ldr r1, [pc, #0x3e0] */
/* @0x243768 mov r0, r5 */
/* @0x24376c str r4, [sp] */
/* @0x243770 add r1, pc, r1 */
/* @0x243774 movw r2, #0xe50e */
/* @0x243778 movw r3, #0xcb7b */
/* @0x24377c movt r2, #0x1526 */
/* @0x243780 movt r3, #0x3fdb */
/* @0x243784 bl 0x1999d0 <_ZN12YYObjectBase3AddEPKcdi> */
/* @0x243788 ldr r1, [pc, #0x3c0] */
/* @0x24378c mov r0, r5 */
/* @0x243790 str r4, [sp] */
/* @0x243794 add r1, pc, r1 */
/* @0x243798 movw r2, #0x2d18 */
/* @0x24379c movw r3, #0x21fb */
/* @0x2437a0 movt r2, #0x5444 */
/* @0x2437a4 movt r3, #0x4009 */
/* @0x2437a8 bl 0x1999d0 <_ZN12YYObjectBase3AddEPKcdi> */
/* @0x2437ac ldr r1, [pc, #0x3a0] */
/* @0x2437b0 mov r0, r5 */
/* @0x2437b4 str r4, [sp] */
/* @0x2437b8 add r1, pc, r1 */
/* @0x2437bc movw r2, #0x3bcd */
/* @0x2437c0 movw r3, #0xa09e */
/* @0x2437c4 movt r2, #0x667f */
/* @0x2437c8 movt r3, #0x3fe6 */
/* @0x2437cc bl 0x1999d0 <_ZN12YYObjectBase3AddEPKcdi> */
/* @0x2437d0 ldr r1, [pc, #0x380] */
/* @0x2437d4 mov r0, r5 */
/* @0x2437d8 str r4, [sp] */
/* @0x2437dc add r1, pc, r1 */
/* @0x2437e0 movw r2, #0x3bcd */
/* @0x2437e4 movw r3, #0xa09e */
/* @0x2437e8 movt r2, #0x667f */
/* @0x2437ec movt r3, #0x3ff6 */
/* @0x2437f0 bl 0x1999d0 <_ZN12YYObjectBase3AddEPKcdi> */
/* @0x2437f4 ldr r3, [pc, #0x360] */
/* @0x2437f8 mov r1, r4 */
/* @0x2437fc mov r2, r4 */
/* @0x243800 ldr r0, [r6, r3] */
/* @0x243804 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243808 ldr r1, [pc, #0x350] */
/* @0x24380c mov r3, r4 */
/* @0x243810 add r1, pc, r1 */
/* @0x243814 mov r2, r0 */
/* @0x243818 mov r0, r5 */
/* @0x24381c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243820 ldr r3, [pc, #0x33c] */
/* @0x243824 mov r1, r4 */
/* @0x243828 mov r2, r4 */
/* @0x24382c ldr r0, [r6, r3] */
/* @0x243830 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243834 ldr r1, [pc, #0x32c] */
/* @0x243838 mov r3, r4 */
/* @0x24383c add r1, pc, r1 */
/* @0x243840 mov r2, r0 */
/* @0x243844 mov r0, r5 */
/* @0x243848 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x24384c ldr r3, [pc, #0x318] */
/* @0x243850 mov r1, r4 */
/* @0x243854 mov r2, r4 */
/* @0x243858 ldr r0, [r6, r3] */
/* @0x24385c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243860 ldr r1, [pc, #0x308] */
/* @0x243864 mov r3, r4 */
/* @0x243868 add r1, pc, r1 */
/* @0x24386c mov r2, r0 */
/* @0x243870 mov r0, r5 */
/* @0x243874 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243878 ldr r3, [pc, #0x2f4] */
/* @0x24387c mov r1, r4 */
/* @0x243880 mov r2, r4 */
/* @0x243884 ldr r0, [r6, r3] */
/* @0x243888 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x24388c ldr r1, [pc, #0x2e4] */
/* @0x243890 mov r3, r4 */
/* @0x243894 add r1, pc, r1 */
/* @0x243898 mov r2, r0 */
/* @0x24389c mov r0, r5 */
/* @0x2438a0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2438a4 ldr r3, [pc, #0x2d0] */
/* @0x2438a8 mov r1, r4 */
/* @0x2438ac mov r2, r4 */
/* @0x2438b0 ldr r0, [r6, r3] */
/* @0x2438b4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2438b8 ldr r1, [pc, #0x2c0] */
/* @0x2438bc mov r3, r4 */
/* @0x2438c0 add r1, pc, r1 */
/* @0x2438c4 mov r2, r0 */
/* @0x2438c8 mov r0, r5 */
/* @0x2438cc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2438d0 ldr r3, [pc, #0x2ac] */
/* @0x2438d4 mov r1, r4 */
/* @0x2438d8 mov r2, r4 */
/* @0x2438dc ldr r0, [r6, r3] */
/* @0x2438e0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2438e4 ldr r1, [pc, #0x29c] */
/* @0x2438e8 mov r3, r4 */
/* @0x2438ec add r1, pc, r1 */
/* @0x2438f0 mov r2, r0 */
/* @0x2438f4 mov r0, r5 */
/* @0x2438f8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2438fc ldr r3, [pc, #0x288] */
/* @0x243900 mov r1, r4 */
/* @0x243904 mov r2, r4 */
/* @0x243908 ldr r0, [r6, r3] */
/* @0x24390c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243910 ldr r1, [pc, #0x278] */
/* @0x243914 mov r3, r4 */
/* @0x243918 add r1, pc, r1 */
/* @0x24391c mov r2, r0 */
/* @0x243920 mov r0, r5 */
/* @0x243924 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243928 ldr r3, [pc, #0x264] */
/* @0x24392c mov r1, r4 */
/* @0x243930 mov r2, r4 */
/* @0x243934 ldr r0, [r6, r3] */
/* @0x243938 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x24393c ldr r1, [pc, #0x254] */
/* @0x243940 mov r3, r4 */
/* @0x243944 add r1, pc, r1 */
/* @0x243948 mov r2, r0 */
/* @0x24394c mov r0, r5 */
/* @0x243950 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243954 ldr r3, [pc, #0x240] */
/* @0x243958 mov r1, r4 */
/* @0x24395c mov r2, r4 */
/* @0x243960 ldr r0, [r6, r3] */
/* @0x243964 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243968 ldr r1, [pc, #0x230] */
/* @0x24396c mov r3, r4 */
/* @0x243970 add r1, pc, r1 */
/* @0x243974 mov r2, r0 */
/* @0x243978 mov r0, r5 */
/* @0x24397c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243980 ldr r3, [pc, #0x21c] */
/* @0x243984 mov r1, r4 */
/* @0x243988 mov r2, r4 */
/* @0x24398c ldr r0, [r6, r3] */
/* @0x243990 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243994 ldr r1, [pc, #0x20c] */
/* @0x243998 mov r3, r4 */
/* @0x24399c add r1, pc, r1 */
/* @0x2439a0 mov r2, r0 */
/* @0x2439a4 mov r0, r5 */
/* @0x2439a8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2439ac ldr r3, [pc, #0x1f8] */
/* @0x2439b0 mov r1, r4 */
/* @0x2439b4 mov r2, r4 */
/* @0x2439b8 ldr r0, [r6, r3] */
/* @0x2439bc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2439c0 ldr r1, [pc, #0x1e8] */
/* @0x2439c4 mov r3, r4 */
/* @0x2439c8 add r1, pc, r1 */
/* @0x2439cc mov r2, r0 */
/* @0x2439d0 mov r0, r5 */
/* @0x2439d4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2439d8 ldr r3, [pc, #0x1d4] */
/* @0x2439dc mov r1, r4 */
/* @0x2439e0 mov r2, r4 */
/* @0x2439e4 ldr r0, [r6, r3] */
/* @0x2439e8 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2439ec ldr r1, [pc, #0x1c4] */
/* @0x2439f0 mov r3, r4 */
/* @0x2439f4 add r1, pc, r1 */
/* @0x2439f8 mov r2, r0 */
/* @0x2439fc mov r0, r5 */
/* @0x243a00 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243a04 ldr r3, [pc, #0x1b0] */
/* @0x243a08 mov r1, r4 */
/* @0x243a0c mov r2, r4 */
/* @0x243a10 ldr r0, [r6, r3] */
/* @0x243a14 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243a18 ldr r1, [pc, #0x1a0] */
/* @0x243a1c mov r3, r4 */
/* @0x243a20 add r1, pc, r1 */
/* @0x243a24 mov r2, r0 */
/* @0x243a28 mov r0, r5 */
/* @0x243a2c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243a30 ldr r3, [pc, #0x18c] */
/* @0x243a34 mov r1, r4 */
/* @0x243a38 mov r2, r4 */
/* @0x243a3c ldr r0, [r6, r3] */
/* @0x243a40 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243a44 ldr r1, [pc, #0x17c] */
/* @0x243a48 mov r3, r4 */
/* @0x243a4c add r1, pc, r1 */
/* @0x243a50 mov r2, r0 */
/* @0x243a54 mov r0, r5 */
/* @0x243a58 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243a5c ldr r3, [pc, #0x168] */
/* @0x243a60 mov r1, r4 */
/* @0x243a64 mov r2, r4 */
/* @0x243a68 ldr r0, [r6, r3] */
/* @0x243a6c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243a70 ldr r1, [pc, #0x158] */
/* @0x243a74 mov r3, r4 */
/* @0x243a78 add r1, pc, r1 */
/* @0x243a7c mov r2, r0 */
/* @0x243a80 mov r0, r5 */
/* @0x243a84 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243a88 ldr r3, [pc, #0x144] */
/* @0x243a8c mov r1, r4 */
/* @0x243a90 mov r2, r4 */
/* @0x243a94 ldr r0, [r6, r3] */
/* @0x243a98 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243a9c ldr r1, [pc, #0x134] */
/* @0x243aa0 mov r3, r4 */
/* @0x243aa4 add r1, pc, r1 */
/* @0x243aa8 mov r2, r0 */
/* @0x243aac mov r0, r5 */
/* @0x243ab0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243ab4 ldr r3, [pc, #0x120] */
/* @0x243ab8 mov r1, r4 */
/* @0x243abc mov r2, r4 */
/* @0x243ac0 ldr r0, [r6, r3] */
/* @0x243ac4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243ac8 ldr r1, [pc, #0x110] */
/* @0x243acc mov r3, r4 */
/* @0x243ad0 add r1, pc, r1 */
/* @0x243ad4 mov r2, r0 */
/* @0x243ad8 mov r0, r5 */
/* @0x243adc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243ae0 ldr r3, [pc, #0xfc] */
/* @0x243ae4 mov r1, r4 */
/* @0x243ae8 mov r2, r4 */
/* @0x243aec ldr r0, [r6, r3] */
/* @0x243af0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243af4 ldr r1, [pc, #0xec] */
/* @0x243af8 mov r3, r4 */
/* @0x243afc add r1, pc, r1 */
/* @0x243b00 mov r2, r0 */
/* @0x243b04 mov r0, r5 */
/* @0x243b08 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243b0c ldr r0, [pc, #0xd8] */
/* @0x243b10 mov r1, r7 */
/* @0x243b14 mov r2, r5 */
/* @0x243b18 mov r3, r4 */
/* @0x243b1c ldr r0, [r6, r0] */
/* @0x243b20 ldr r0, [r0] */
/* @0x243b24 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243b28 add sp, sp, #28 */
/* @0x243b2c pop {r4, r5, r6, r7, pc} */
/* @0x243b30 andseq lr, r10, r0, lsr #11 */
/* @0x243b34 .word 0xffffc050 */
/* @0x243b38 andseq r2, r1, r4, lsl #4 */
/* @0x243b3c andseq r2, r1, r8, ror #3 */
/* @0x243b40 andseq r2, r1, r8, asr #3 */
/* @0x243b44 andseq r2, r1, r12, lsr #3 */
/* @0x243b48 andseq r2, r1, r12, lsl #3 */
/* @0x243b4c andseq r2, r1, r0, ror r1 */
/* @0x243b50 andseq r2, r1, r4, asr r1 */
/* @0x243b54 andseq r2, r1, r4, lsr r1 */
/* @0x243b58 andseq r2, r1, r8, lsl r1 */
/* @0x243b5c .word 0xfffffa20 */
/* @0x243b60 andeq r5, pc, r12, ror #20 */
/* @0x243b64 .word 0xfffffa24 */
/* @0x243b68 andseq r2, r1, r0, asr #1 */
/* @0x243b6c .word 0xfffffa28 */
/* @0x243b70 mulseq r1, r12, r0 */
/* @0x243b74 .word 0xfffffa2c */
/* @0x243b78 andseq r2, r1, r8, ror r0 */
/* @0x243b7c .word 0xfffffa30 */
/* @0x243b80 andseq r2, r1, r4, asr r0 */
/* @0x243b84 .word 0xfffffa34 */
/* @0x243b88 andeq r5, pc, r4, lsr #19 */
/* @0x243b8c .word 0xfffffa38 */
/* @0x243b90 strheq r5, [pc], -r8 */
/* @0x243b94 .word 0xfffffa3c */
/* @0x243b98 andeq r5, pc, r0, ror r9 */
/* @0x243b9c .word 0xfffffa40 */
/* @0x243ba0 andeq r5, pc, r8, lsl r9 */
/* @0x243ba4 .word 0xfffffa44 */
/* @0x243ba8 andseq r1, r1, r0, lsl #31 */
/* @0x243bac .word 0xfffffa48 */
/* @0x243bb0 muleq pc, r8, r9 */
/* @0x243bb4 .word 0xfffffa4c */
/* @0x243bb8 andeq r5, pc, r8, ror #18 */
/* @0x243bbc .word 0xfffffa50 */
/* @0x243bc0 andseq r1, r1, r0, lsl #30 */
/* @0x243bc4 .word 0xfffffa54 */
/* @0x243bc8 strheq r5, [pc], -r0 */
/* @0x243bcc .word 0xfffffa58 */
/* @0x243bd0 andeq r5, pc, r8, lsl #16 */
/* @0x243bd4 .word 0xfffffa5c */
/* @0x243bd8 andeq r5, pc, r8, lsr #16 */
/* @0x243bdc .word 0xfffffa60 */
/* @0x243be0 ldrdeq r5, r6, [pc], -r8 */
/* @0x243be4 .word 0xfffffa64 */
/* @0x243be8 ldrdeq r5, r6, [pc], -r8 */
/* @0x243bec .word 0xffffbf64 */

/* ── FUNC 0x243bf0 · JS_BooleanObjectSetup() · size=496 · insn=124 */
/* @0x243bf0 push {r4, r5, r6, r7, r8, lr} */
/* @0x243bf4 sub sp, sp, #24 */
/* @0x243bf8 mov r4, #0 */
/* @0x243bfc add r0, sp, #8 */
/* @0x243c00 mov r1, r4 */
/* @0x243c04 mov r2, r4 */
/* @0x243c08 mov r3, r4 */
/* @0x243c0c str r4, [sp] */
/* @0x243c10 ldr r6, [pc, #0x190] */
/* @0x243c14 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x243c18 ldr r3, [pc, #0x18c] */
/* @0x243c1c add r6, pc, r6 */
/* @0x243c20 ldr r5, [sp, #0x8] */
/* @0x243c24 ldr r2, [pc, #0x184] */
/* @0x243c28 ldr r8, [r6, r3] */
/* @0x243c2c ldr r3, [pc, #0x180] */
/* @0x243c30 add r2, pc, r2 */
/* @0x243c34 str r2, [r5, #0x40] */
/* @0x243c38 mov r0, r5 */
/* @0x243c3c str r5, [r8] */
/* @0x243c40 ldr r3, [r6, r3] */
/* @0x243c44 ldr r1, [r3] */
/* @0x243c48 str r1, [r5, #0x18] */
/* @0x243c4c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x243c50 ldr r1, [r5, #0x28] */
/* @0x243c54 mov r0, r5 */
/* @0x243c58 mov r2, r4 */
/* @0x243c5c orr r1, r1, #1 */
/* @0x243c60 str r1, [r5, #0x28] */
/* @0x243c64 ldr r1, [pc, #0x14c] */
/* @0x243c68 mov r3, r4 */
/* @0x243c6c add r1, pc, r1 */
/* @0x243c70 bl 0x1998e0 <_ZN12YYObjectBase3AddEPKcbi> */
/* @0x243c74 ldr r3, [pc, #0x140] */
/* @0x243c78 mov r1, r4 */
/* @0x243c7c mov r2, r4 */
/* @0x243c80 ldr r0, [r6, r3] */
/* @0x243c84 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243c88 ldr r1, [pc, #0x130] */
/* @0x243c8c mov r3, r4 */
/* @0x243c90 add r1, pc, r1 */
/* @0x243c94 mov r2, r0 */
/* @0x243c98 mov r0, r5 */
/* @0x243c9c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243ca0 ldr r3, [pc, #0x11c] */
/* @0x243ca4 mov r1, r4 */
/* @0x243ca8 mov r2, r4 */
/* @0x243cac ldr r0, [r6, r3] */
/* @0x243cb0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243cb4 ldr r1, [pc, #0x10c] */
/* @0x243cb8 mov r3, r4 */
/* @0x243cbc add r1, pc, r1 */
/* @0x243cc0 mov r2, r0 */
/* @0x243cc4 mov r0, r5 */
/* @0x243cc8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243ccc ldr r3, [pc, #0xf8] */
/* @0x243cd0 mov r1, r4 */
/* @0x243cd4 mov r2, r4 */
/* @0x243cd8 ldr r0, [r6, r3] */
/* @0x243cdc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x243ce0 ldr r12, [pc, #0xe8] */
/* @0x243ce4 ldr r1, [pc, #0xe8] */
/* @0x243ce8 mov r3, r4 */
/* @0x243cec ldr r12, [r6, r12] */
/* @0x243cf0 add r1, pc, r1 */
/* @0x243cf4 mov r7, r0 */
/* @0x243cf8 mov r0, r5 */
/* @0x243cfc mov r2, r7 */
/* @0x243d00 str r12, [r7, #0x94] */
/* @0x243d04 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243d08 ldr r3, [r7, #0x4] */
/* @0x243d0c cmp r3, r4 */
/* @0x243d10 beq 0x243d68 <_Z21JS_BooleanObjectSetupv+0x178> */
/* @0x243d14 ldr r1, [r8] */
/* @0x243d18 mov r0, r7 */
/* @0x243d1c str r1, [r3] */
/* @0x243d20 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x243d24 ldr r1, [r7, #0x4] */
/* @0x243d28 cmp r1, #0 */
/* @0x243d2c movne r3, #6 */
/* @0x243d30 strne r3, [r1, #0xc] */
/* @0x243d34 beq 0x243d7c <_Z21JS_BooleanObjectSetupv+0x18c> */
/* @0x243d38 ldr r0, [pc, #0x98] */
/* @0x243d3c mov r3, #6 */
/* @0x243d40 str r3, [r1, #0x8] */
/* @0x243d44 mov r2, r7 */
/* @0x243d48 ldr r1, [pc, #0x8c] */
/* @0x243d4c mov r3, #0 */
/* @0x243d50 ldr r0, [r6, r0] */
/* @0x243d54 add r1, pc, r1 */
/* @0x243d58 ldr r0, [r0] */
/* @0x243d5c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243d60 add sp, sp, #24 */
/* @0x243d64 pop {r4, r5, r6, r7, r8, pc} */
/* @0x243d68 mov r1, r3 */
/* @0x243d6c mov r0, r7 */
/* @0x243d70 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x243d74 mov r3, r0 */
/* @0x243d78 b 0x243d14 <_Z21JS_BooleanObjectSetupv+0x124> */
/* @0x243d7c mov r0, r7 */
/* @0x243d80 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x243d84 ldr r1, [r7, #0x4] */
/* @0x243d88 mov r3, #6 */
/* @0x243d8c cmp r1, #0 */
/* @0x243d90 str r3, [r0, #0xc] */
/* @0x243d94 bne 0x243d38 <_Z21JS_BooleanObjectSetupv+0x148> */
/* @0x243d98 mov r0, r7 */
/* @0x243d9c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x243da0 mov r1, r0 */
/* @0x243da4 b 0x243d38 <_Z21JS_BooleanObjectSetupv+0x148> */
/* @0x243da8 andseq lr, r10, r4, lsr r0 */
/* @0x243dac .word 0xfffff8d4 */
/* @0x243db0 ldrsbeq r1, [r1], -r8 */
/* @0x243db4 .word 0xffffc050 */
/* @0x243db8 andseq r1, r1, r4, lsr #17 */
/* @0x243dbc .word 0xfffffa68 */
/* @0x243dc0 andeq lr, lr, r0, lsl #17 */
/* @0x243dc4 .word 0xfffffa6c */
/* @0x243dc8 mulseq r1, r12, r9 */
/* @0x243dcc .word 0xfffffa70 */
/* @0x243dd0 .word 0xfffffa74 */
/* @0x243dd4 andseq r1, r1, r4, lsr r8 */
/* @0x243dd8 .word 0xffffbf64 */
/* @0x243ddc ldrheq r1, [r1], -r4 */

/* ── FUNC 0x243de0 · NativeErrorCall(char const*, YYObjectBase*, RValue&, CInstance*, CInstance*, int, RValue*) · size=452 · insn=113 */
/* @0x243de0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x243de4 sub sp, sp, #12 */
/* @0x243de8 ldr r10, [pc, #0x194] */
/* @0x243dec mov r8, r0 */
/* @0x243df0 ldr r4, [sp, #0x34] */
/* @0x243df4 mov r5, r1 */
/* @0x243df8 mov r6, r2 */
/* @0x243dfc add r10, pc, r10 */
/* @0x243e00 cmp r4, #0 */
/* @0x243e04 mov r11, r3 */
/* @0x243e08 ldr r9, [sp, #0x30] */
/* @0x243e0c ldr r7, [sp, #0x38] */
/* @0x243e10 ble 0x243e24 <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_+0x44> */
/* @0x243e14 mov r0, r7 */
/* @0x243e18 mov r1, #0 */
/* @0x243e1c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x243e20 mov r10, r0 */
/* @0x243e24 mov r3, r4 */
/* @0x243e28 mov r2, r9 */
/* @0x243e2c mov r1, r11 */
/* @0x243e30 mov r0, r6 */
/* @0x243e34 str r7, [sp] */
/* @0x243e38 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x243e3c ldr r4, [r6] */
/* @0x243e40 mov r1, r5 */
/* @0x243e44 str r5, [r4, #0x18] */
/* @0x243e48 mov r0, r4 */
/* @0x243e4c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x243e50 ldr r12, [r4, #0x28] */
/* @0x243e54 ldr r3, [pc, #0x12c] */
/* @0x243e58 mov r2, r10 */
/* @0x243e5c ldr r1, [pc, #0x128] */
/* @0x243e60 orr r12, r12, #1 */
/* @0x243e64 add r3, pc, r3 */
/* @0x243e68 str r12, [r4, #0x28] */
/* @0x243e6c mov r0, r4 */
/* @0x243e70 add r1, pc, r1 */
/* @0x243e74 str r3, [r4, #0x40] */
/* @0x243e78 mov r3, #0 */
/* @0x243e7c bl 0x199aa8 <_ZN12YYObjectBase3AddEPKcS1_i> */
/* @0x243e80 ldr r1, [pc, #0x108] */
/* @0x243e84 mov r2, r8 */
/* @0x243e88 mov r3, #0 */
/* @0x243e8c add r1, pc, r1 */
/* @0x243e90 mov r0, r4 */
/* @0x243e94 bl 0x199aa8 <_ZN12YYObjectBase3AddEPKcS1_i> */
/* @0x243e98 bl 0xdb934 <_Z14vmGetCallStackv> */
/* @0x243e9c ldr r1, [pc, #0xf0] */
/* @0x243ea0 mov r3, #0 */
/* @0x243ea4 add r1, pc, r1 */
/* @0x243ea8 mov r2, r0 */
/* @0x243eac mov r0, r4 */
/* @0x243eb0 bl 0x199aa8 <_ZN12YYObjectBase3AddEPKcS1_i> */
/* @0x243eb4 ldr r3, [pc, #0xdc] */
/* @0x243eb8 mvn r1, #-16777216 */
/* @0x243ebc mov r2, #0 */
/* @0x243ec0 ldr r3, [pc, r3] */
/* @0x243ec4 ldr r0, [r3] */
/* @0x243ec8 bl 0x19198c <_ZN12YYObjectBase5AllocEjib> */
/* @0x243ecc ldr r1, [pc, #0xc8] */
/* @0x243ed0 ldr r2, [r6] */
/* @0x243ed4 mov r3, #6 */
/* @0x243ed8 add r1, pc, r1 */
/* @0x243edc mov r5, r0 */
/* @0x243ee0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x243ee4 ldr r3, [pc, #0xb4] */
/* @0x243ee8 mov r0, r5 */
/* @0x243eec ldr r3, [pc, r3] */
/* @0x243ef0 ldr r1, [r3] */
/* @0x243ef4 str r1, [r5, #0x18] */
/* @0x243ef8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x243efc ldr r1, [r4, #0x4] */
/* @0x243f00 cmp r1, #0 */
/* @0x243f04 beq 0x243f3c <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_+0x15c> */
/* @0x243f08 str r5, [r1] */
/* @0x243f0c mov r0, r4 */
/* @0x243f10 mov r1, r5 */
/* @0x243f14 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x243f18 ldr r1, [r4, #0x4] */
/* @0x243f1c cmp r1, #0 */
/* @0x243f20 movne r3, #6 */
/* @0x243f24 strne r3, [r1, #0xc] */
/* @0x243f28 beq 0x243f4c <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_+0x16c> */
/* @0x243f2c mov r3, #6 */
/* @0x243f30 str r3, [r1, #0x8] */
/* @0x243f34 add sp, sp, #12 */
/* @0x243f38 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x243f3c mov r0, r4 */
/* @0x243f40 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x243f44 mov r1, r0 */
/* @0x243f48 b 0x243f08 <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_+0x128> */
/* @0x243f4c mov r0, r4 */
/* @0x243f50 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x243f54 ldr r1, [r4, #0x4] */
/* @0x243f58 mov r3, #6 */
/* @0x243f5c cmp r1, #0 */
/* @0x243f60 str r3, [r0, #0xc] */
/* @0x243f64 bne 0x243f2c <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_+0x14c> */
/* @0x243f68 mov r0, r4 */
/* @0x243f6c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x243f70 mov r3, #6 */
/* @0x243f74 mov r1, r0 */
/* @0x243f78 str r3, [r1, #0x8] */
/* @0x243f7c add sp, sp, #12 */
/* @0x243f80 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x243f84 andeq r10, lr, r10, lsr sp */
/* @0x243f88 andseq r1, r1, r0, asr #21 */
/* @0x243f8c andseq r5, r0, r4, lsl r9 */
/* @0x243f90 andeq r12, lr, r12, ror r9 */
/* @0x243f94 andseq r1, r1, r8, lsl #21 */
/* @0x243f98 andseq r9, r10, r4, asr lr */
/* @0x243f9c andseq r1, r1, r12, asr #12 */
/* @0x243fa0 ldrheq r9, [r10], -r4 */

/* ── FUNC 0x243fa4 · F_JSErrorCall(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x243fa4 push {r4, r5, lr} */
/* @0x243fa8 sub sp, sp, #20 */
/* @0x243fac ldr r12, [pc, #0x38] */
/* @0x243fb0 mov r4, r0 */
/* @0x243fb4 ldr lr, [sp, #0x20] */
/* @0x243fb8 mov r5, r1 */
/* @0x243fbc ldr r12, [pc, r12] */
/* @0x243fc0 ldr r0, [pc, #0x28] */
/* @0x243fc4 ldr r1, [r12] */
/* @0x243fc8 add r0, pc, r0 */
/* @0x243fcc str r2, [sp] */
/* @0x243fd0 mov r2, r4 */
/* @0x243fd4 str r3, [sp, #0x4] */
/* @0x243fd8 mov r3, r5 */
/* @0x243fdc str lr, [sp, #0x8] */
/* @0x243fe0 bl 0x243de0 <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_> */
/* @0x243fe4 add sp, sp, #20 */
/* @0x243fe8 pop {r4, r5, pc} */
/* @0x243fec andseq sp, r10, r12, lsl #14 */
/* @0x243ff0 andseq r1, r1, r12, asr r9 */

/* ── FUNC 0x243ff4 · F_JSEvalErrorCall(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x243ff4 push {r4, r5, lr} */
/* @0x243ff8 sub sp, sp, #20 */
/* @0x243ffc ldr r12, [pc, #0x38] */
/* @0x244000 mov r4, r0 */
/* @0x244004 ldr lr, [sp, #0x20] */
/* @0x244008 mov r5, r1 */
/* @0x24400c ldr r12, [pc, r12] */
/* @0x244010 ldr r0, [pc, #0x28] */
/* @0x244014 ldr r1, [r12] */
/* @0x244018 add r0, pc, r0 */
/* @0x24401c str r2, [sp] */
/* @0x244020 mov r2, r4 */
/* @0x244024 str r3, [sp, #0x4] */
/* @0x244028 mov r3, r5 */
/* @0x24402c str lr, [sp, #0x8] */
/* @0x244030 bl 0x243de0 <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_> */
/* @0x244034 add sp, sp, #20 */
/* @0x244038 pop {r4, r5, pc} */
/* @0x24403c andseq sp, r10, r0, asr #13 */
/* @0x244040 andseq r1, r1, r0, lsr #18 */

/* ── FUNC 0x244044 · F_JSRangeErrorCall(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x244044 push {r4, r5, lr} */
/* @0x244048 sub sp, sp, #20 */
/* @0x24404c ldr r12, [pc, #0x38] */
/* @0x244050 mov r4, r0 */
/* @0x244054 ldr lr, [sp, #0x20] */
/* @0x244058 mov r5, r1 */
/* @0x24405c ldr r12, [pc, r12] */
/* @0x244060 ldr r0, [pc, #0x28] */
/* @0x244064 ldr r1, [r12] */
/* @0x244068 add r0, pc, r0 */
/* @0x24406c str r2, [sp] */
/* @0x244070 mov r2, r4 */
/* @0x244074 str r3, [sp, #0x4] */
/* @0x244078 mov r3, r5 */
/* @0x24407c str lr, [sp, #0x8] */
/* @0x244080 bl 0x243de0 <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_> */
/* @0x244084 add sp, sp, #20 */
/* @0x244088 pop {r4, r5, pc} */
/* @0x24408c andseq sp, r10, r4, ror r6 */
/* @0x244090 ldrsbeq r1, [r1], -r12 */

/* ── FUNC 0x244094 · F_JSReferenceErrorCall(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x244094 push {r4, r5, lr} */
/* @0x244098 sub sp, sp, #20 */
/* @0x24409c ldr r12, [pc, #0x38] */
/* @0x2440a0 mov r4, r0 */
/* @0x2440a4 ldr lr, [sp, #0x20] */
/* @0x2440a8 mov r5, r1 */
/* @0x2440ac ldr r12, [pc, r12] */
/* @0x2440b0 ldr r0, [pc, #0x28] */
/* @0x2440b4 ldr r1, [r12] */
/* @0x2440b8 add r0, pc, r0 */
/* @0x2440bc str r2, [sp] */
/* @0x2440c0 mov r2, r4 */
/* @0x2440c4 str r3, [sp, #0x4] */
/* @0x2440c8 mov r3, r5 */
/* @0x2440cc str lr, [sp, #0x8] */
/* @0x2440d0 bl 0x243de0 <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_> */
/* @0x2440d4 add sp, sp, #20 */
/* @0x2440d8 pop {r4, r5, pc} */
/* @0x2440dc andseq sp, r10, r8, lsr #12 */
/* @0x2440e0 mulseq r1, r8, r8 */

/* ── FUNC 0x2440e4 · F_JSSyntaxErrorCall(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x2440e4 push {r4, r5, lr} */
/* @0x2440e8 sub sp, sp, #20 */
/* @0x2440ec ldr r12, [pc, #0x38] */
/* @0x2440f0 mov r4, r0 */
/* @0x2440f4 ldr lr, [sp, #0x20] */
/* @0x2440f8 mov r5, r1 */
/* @0x2440fc ldr r12, [pc, r12] */
/* @0x244100 ldr r0, [pc, #0x28] */
/* @0x244104 ldr r1, [r12] */
/* @0x244108 add r0, pc, r0 */
/* @0x24410c str r2, [sp] */
/* @0x244110 mov r2, r4 */
/* @0x244114 str r3, [sp, #0x4] */
/* @0x244118 mov r3, r5 */
/* @0x24411c str lr, [sp, #0x8] */
/* @0x244120 bl 0x243de0 <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_> */
/* @0x244124 add sp, sp, #20 */
/* @0x244128 pop {r4, r5, pc} */
/* @0x24412c ldrsbeq sp, [r10], -r12 */
/* @0x244130 andseq r1, r1, r8, asr r8 */

/* ── FUNC 0x244134 · F_JSTypeErrorCall(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x244134 push {r4, r5, lr} */
/* @0x244138 sub sp, sp, #20 */
/* @0x24413c ldr r12, [pc, #0x38] */
/* @0x244140 mov r4, r0 */
/* @0x244144 ldr lr, [sp, #0x20] */
/* @0x244148 mov r5, r1 */
/* @0x24414c ldr r12, [pc, r12] */
/* @0x244150 ldr r0, [pc, #0x28] */
/* @0x244154 ldr r1, [r12] */
/* @0x244158 add r0, pc, r0 */
/* @0x24415c str r2, [sp] */
/* @0x244160 mov r2, r4 */
/* @0x244164 str r3, [sp, #0x4] */
/* @0x244168 mov r3, r5 */
/* @0x24416c str lr, [sp, #0x8] */
/* @0x244170 bl 0x243de0 <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_> */
/* @0x244174 add sp, sp, #20 */
/* @0x244178 pop {r4, r5, pc} */
/* @0x24417c mulseq r10, r0, r5 */
/* @0x244180 andseq r1, r1, r4, lsl r8 */

/* ── FUNC 0x244184 · F_JSURIErrorCall(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x244184 push {r4, r5, lr} */
/* @0x244188 sub sp, sp, #20 */
/* @0x24418c ldr r12, [pc, #0x38] */
/* @0x244190 mov r4, r0 */
/* @0x244194 ldr lr, [sp, #0x20] */
/* @0x244198 mov r5, r1 */
/* @0x24419c ldr r12, [pc, r12] */
/* @0x2441a0 ldr r0, [pc, #0x28] */
/* @0x2441a4 ldr r1, [r12] */
/* @0x2441a8 add r0, pc, r0 */
/* @0x2441ac str r2, [sp] */
/* @0x2441b0 mov r2, r4 */
/* @0x2441b4 str r3, [sp, #0x4] */
/* @0x2441b8 mov r3, r5 */
/* @0x2441bc str lr, [sp, #0x8] */
/* @0x2441c0 bl 0x243de0 <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_> */
/* @0x2441c4 add sp, sp, #20 */
/* @0x2441c8 pop {r4, r5, pc} */
/* @0x2441cc andseq sp, r10, r4, asr #10 */
/* @0x2441d0 ldrsbeq r1, [r1], -r0 */

/* ── FUNC 0x2441d4 · JS_CreateNativeErrorSetup(char const*, void (*)(RValue&, CInstance*, CInstance*, int, RValue*), YYObjectBase**, YYObjectBase*) · size=404 · insn=101 */
/* @0x2441d4 push {r4, r5, r6, r7, r8, lr} */
/* @0x2441d8 sub sp, sp, #24 */
/* @0x2441dc mov r12, #0 */
/* @0x2441e0 mov r5, r3 */
/* @0x2441e4 str r12, [sp] */
/* @0x2441e8 mov r3, r12 */
/* @0x2441ec mov r6, r1 */
/* @0x2441f0 mov r7, r2 */
/* @0x2441f4 mov r1, r12 */
/* @0x2441f8 mov r2, r12 */
/* @0x2441fc mov r8, r0 */
/* @0x244200 add r0, sp, #8 */
/* @0x244204 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x244208 ldr r4, [sp, #0x8] */
/* @0x24420c ldr r3, [pc, #0x138] */
/* @0x244210 cmp r7, #0 */
/* @0x244214 mov r1, r5 */
/* @0x244218 strne r4, [r7] */
/* @0x24421c add r3, pc, r3 */
/* @0x244220 str r5, [r4, #0x18] */
/* @0x244224 mov r0, r4 */
/* @0x244228 str r3, [r4, #0x40] */
/* @0x24422c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x244230 ldr r3, [r4, #0x28] */
/* @0x244234 ldr r1, [pc, #0x114] */
/* @0x244238 mov r2, r8 */
/* @0x24423c mov r0, r4 */
/* @0x244240 orr r3, r3, #1 */
/* @0x244244 add r1, pc, r1 */
/* @0x244248 str r3, [r4, #0x28] */
/* @0x24424c mov r3, #6 */
/* @0x244250 bl 0x199aa8 <_ZN12YYObjectBase3AddEPKcS1_i> */
/* @0x244254 ldr r1, [pc, #0xf8] */
/* @0x244258 ldr r2, [pc, #0xf8] */
/* @0x24425c mov r3, #6 */
/* @0x244260 mov r0, r4 */
/* @0x244264 add r1, pc, r1 */
/* @0x244268 add r2, pc, r2 */
/* @0x24426c bl 0x199aa8 <_ZN12YYObjectBase3AddEPKcS1_i> */
/* @0x244270 ldr r0, [pc, #0xe4] */
/* @0x244274 mov r1, #0 */
/* @0x244278 mov r2, r1 */
/* @0x24427c ldr r0, [pc, r0] */
/* @0x244280 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x244284 ldr r1, [pc, #0xd4] */
/* @0x244288 mov r3, #6 */
/* @0x24428c add r1, pc, r1 */
/* @0x244290 mov r2, r0 */
/* @0x244294 mov r0, r4 */
/* @0x244298 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x24429c mov r1, #0 */
/* @0x2442a0 mov r2, r1 */
/* @0x2442a4 mov r0, r6 */
/* @0x2442a8 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2442ac ldr r1, [pc, #0xb0] */
/* @0x2442b0 mov r3, #0 */
/* @0x2442b4 add r1, pc, r1 */
/* @0x2442b8 mov r5, r0 */
/* @0x2442bc str r6, [r0, #0x94] */
/* @0x2442c0 mov r2, r0 */
/* @0x2442c4 mov r0, r4 */
/* @0x2442c8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2442cc ldr r1, [r5, #0x4] */
/* @0x2442d0 cmp r1, #0 */
/* @0x2442d4 beq 0x244310 <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_+0x13c> */
/* @0x2442d8 str r4, [r1] */
/* @0x2442dc mov r0, r5 */
/* @0x2442e0 mov r1, r4 */
/* @0x2442e4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x2442e8 ldr r1, [r5, #0x4] */
/* @0x2442ec cmp r1, #0 */
/* @0x2442f0 movne r3, #6 */
/* @0x2442f4 strne r3, [r1, #0xc] */
/* @0x2442f8 beq 0x244320 <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_+0x14c> */
/* @0x2442fc mov r3, #6 */
/* @0x244300 mov r0, r5 */
/* @0x244304 str r3, [r1, #0x8] */
/* @0x244308 add sp, sp, #24 */
/* @0x24430c pop {r4, r5, r6, r7, r8, pc} */
/* @0x244310 mov r0, r5 */
/* @0x244314 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x244318 mov r1, r0 */
/* @0x24431c b 0x2442d8 <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_+0x104> */
/* @0x244320 mov r0, r5 */
/* @0x244324 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x244328 ldr r1, [r5, #0x4] */
/* @0x24432c mov r3, #6 */
/* @0x244330 cmp r1, #0 */
/* @0x244334 str r3, [r0, #0xc] */
/* @0x244338 bne 0x2442fc <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_+0x128> */
/* @0x24433c mov r0, r5 */
/* @0x244340 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x244344 mov r1, r0 */
/* @0x244348 b 0x2442fc <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_+0x128> */
/* @0x24434c andseq r1, r1, r8, ror #14 */
/* @0x244350 andeq r12, lr, r4, asr #11 */
/* @0x244354 andseq r5, r0, r0, lsr #10 */
/* @0x244358 andeq r10, lr, lr, asr #17 */
/* @0x24435c andseq sp, r10, r8, ror #8 */
/* @0x244360 andeq lr, lr, r4, lsl #5 */
/* @0x244364 andseq r1, r1, r0, ror r2 */

/* ── FUNC 0x244368 · JS_ErrorObjectSetup() · size=576 · insn=144 */
/* @0x244368 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24436c sub sp, sp, #36 */
/* @0x244370 ldr r4, [pc, #0x1d0] */
/* @0x244374 ldr r2, [pc, #0x1d0] */
/* @0x244378 ldr r3, [pc, #0x1d0] */
/* @0x24437c add r4, pc, r4 */
/* @0x244380 ldr r10, [pc, #0x1cc] */
/* @0x244384 ldr r5, [r4, r2] */
/* @0x244388 ldr r3, [r4, r3] */
/* @0x24438c add r10, pc, r10 */
/* @0x244390 ldr r1, [pc, #0x1c0] */
/* @0x244394 mov r2, r5 */
/* @0x244398 mov r0, r10 */
/* @0x24439c ldr r3, [r3] */
/* @0x2443a0 ldr r1, [r4, r1] */
/* @0x2443a4 bl 0x2441d4 <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_> */
/* @0x2443a8 ldr r7, [pc, #0x1ac] */
/* @0x2443ac ldr r1, [pc, #0x1ac] */
/* @0x2443b0 ldr r2, [pc, #0x1ac] */
/* @0x2443b4 add r7, pc, r7 */
/* @0x2443b8 ldr r3, [r5] */
/* @0x2443bc ldr r6, [pc, #0x1a4] */
/* @0x2443c0 mov r11, r7 */
/* @0x2443c4 ldr r9, [pc, #0x1a0] */
/* @0x2443c8 add r6, pc, r6 */
/* @0x2443cc ldr r8, [pc, #0x19c] */
/* @0x2443d0 add r9, pc, r9 */
/* @0x2443d4 add r8, pc, r8 */
/* @0x2443d8 str r0, [sp, #0x8] */
/* @0x2443dc mov r0, r7 */
/* @0x2443e0 ldr r1, [r4, r1] */
/* @0x2443e4 ldr r2, [r4, r2] */
/* @0x2443e8 bl 0x2441d4 <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_> */
/* @0x2443ec ldr r1, [pc, #0x180] */
/* @0x2443f0 ldr r2, [pc, #0x180] */
/* @0x2443f4 mov r12, r6 */
/* @0x2443f8 ldr r3, [r5] */
/* @0x2443fc ldr r7, [pc, #0x178] */
/* @0x244400 add r7, pc, r7 */
/* @0x244404 str r0, [sp, #0xc] */
/* @0x244408 mov r0, r6 */
/* @0x24440c ldr r1, [r4, r1] */
/* @0x244410 ldr r2, [r4, r2] */
/* @0x244414 str r12, [sp, #0x4] */
/* @0x244418 bl 0x2441d4 <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_> */
/* @0x24441c ldr r1, [pc, #0x15c] */
/* @0x244420 ldr r2, [pc, #0x15c] */
/* @0x244424 ldr r3, [r5] */
/* @0x244428 ldr r6, [pc, #0x158] */
/* @0x24442c add r6, pc, r6 */
/* @0x244430 str r0, [sp, #0x10] */
/* @0x244434 mov r0, r9 */
/* @0x244438 ldr r1, [r4, r1] */
/* @0x24443c ldr r2, [r4, r2] */
/* @0x244440 bl 0x2441d4 <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_> */
/* @0x244444 ldr r1, [pc, #0x140] */
/* @0x244448 ldr r2, [pc, #0x140] */
/* @0x24444c ldr r3, [r5] */
/* @0x244450 str r0, [sp, #0x14] */
/* @0x244454 mov r0, r8 */
/* @0x244458 ldr r1, [r4, r1] */
/* @0x24445c ldr r2, [r4, r2] */
/* @0x244460 bl 0x2441d4 <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_> */
/* @0x244464 ldr r1, [pc, #0x128] */
/* @0x244468 ldr r2, [pc, #0x128] */
/* @0x24446c ldr r3, [r5] */
/* @0x244470 str r0, [sp, #0x18] */
/* @0x244474 mov r0, r7 */
/* @0x244478 ldr r1, [r4, r1] */
/* @0x24447c ldr r2, [r4, r2] */
/* @0x244480 bl 0x2441d4 <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_> */
/* @0x244484 ldr r1, [pc, #0x110] */
/* @0x244488 ldr r2, [pc, #0x110] */
/* @0x24448c ldr r3, [r5] */
/* @0x244490 str r0, [sp, #0x1c] */
/* @0x244494 mov r0, r6 */
/* @0x244498 ldr r1, [r4, r1] */
/* @0x24449c ldr r2, [r4, r2] */
/* @0x2444a0 bl 0x2441d4 <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_> */
/* @0x2444a4 mov r1, r10 */
/* @0x2444a8 ldr r2, [sp, #0x8] */
/* @0x2444ac mov r3, #0 */
/* @0x2444b0 mov r5, r0 */
/* @0x2444b4 ldr r0, [pc, #0xe8] */
/* @0x2444b8 ldr r4, [r4, r0] */
/* @0x2444bc ldr r0, [r4] */
/* @0x2444c0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2444c4 mov r1, r11 */
/* @0x2444c8 ldr r2, [sp, #0xc] */
/* @0x2444cc mov r3, #0 */
/* @0x2444d0 ldr r0, [r4] */
/* @0x2444d4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2444d8 ldr r12, [sp, #0x4] */
/* @0x2444dc ldr r2, [sp, #0x10] */
/* @0x2444e0 mov r3, #0 */
/* @0x2444e4 ldr r0, [r4] */
/* @0x2444e8 mov r1, r12 */
/* @0x2444ec bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2444f0 mov r1, r9 */
/* @0x2444f4 ldr r2, [sp, #0x14] */
/* @0x2444f8 mov r3, #0 */
/* @0x2444fc ldr r0, [r4] */
/* @0x244500 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x244504 mov r1, r8 */
/* @0x244508 ldr r2, [sp, #0x18] */
/* @0x24450c mov r3, #0 */
/* @0x244510 ldr r0, [r4] */
/* @0x244514 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x244518 mov r1, r7 */
/* @0x24451c ldr r2, [sp, #0x1c] */
/* @0x244520 mov r3, #0 */
/* @0x244524 ldr r0, [r4] */
/* @0x244528 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x24452c ldr r0, [r4] */
/* @0x244530 mov r1, r6 */
/* @0x244534 mov r2, r5 */
/* @0x244538 mov r3, #0 */
/* @0x24453c add sp, sp, #36 */
/* @0x244540 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x244544 b 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x244548 ldrsbeq sp, [r10], -r4 */
/* @0x24454c .word 0xfffffa78 */
/* @0x244550 .word 0xffffc050 */
/* @0x244554 mulseq r1, r8, r5 */
/* @0x244558 .word 0xfffffa98 */
/* @0x24455c andseq r1, r1, r4, lsl #11 */
/* @0x244560 .word 0xfffffa9c */
/* @0x244564 .word 0xfffffa7c */
/* @0x244568 andseq r1, r1, r12, ror r5 */
/* @0x24456c andseq r1, r1, r0, lsl #11 */
/* @0x244570 andseq r1, r1, r12, lsl #11 */
/* @0x244574 .word 0xfffffaa0 */
/* @0x244578 .word 0xfffffa80 */
/* @0x24457c andseq r1, r1, r12, ror #10 */
/* @0x244580 .word 0xfffffaa4 */
/* @0x244584 .word 0xfffffa84 */
/* @0x244588 andseq r1, r1, r12, asr #10 */
/* @0x24458c .word 0xfffffaa8 */
/* @0x244590 .word 0xfffffa88 */
/* @0x244594 .word 0xfffffaac */
/* @0x244598 .word 0xfffffa8c */
/* @0x24459c .word 0xfffffab0 */
/* @0x2445a0 .word 0xfffffa90 */
/* @0x2445a4 .word 0xffffbf64 */

/* ── FUNC 0x2445a8 · JS_NumberObjectSetup() · size=988 · insn=247 */
/* @0x2445a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2445ac sub sp, sp, #124 */
/* @0x2445b0 mov r6, #0 */
/* @0x2445b4 add r0, sp, #8 */
/* @0x2445b8 mov r1, r6 */
/* @0x2445bc mov r2, r6 */
/* @0x2445c0 mov r3, r6 */
/* @0x2445c4 str r6, [sp] */
/* @0x2445c8 ldr r8, [pc, #0x348] */
/* @0x2445cc bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x2445d0 ldr r3, [pc, #0x344] */
/* @0x2445d4 mov r4, #0 */
/* @0x2445d8 add r8, pc, r8 */
/* @0x2445dc ldr r11, [sp, #0x8] */
/* @0x2445e0 ldr r2, [pc, #0x338] */
/* @0x2445e4 mov r5, #0 */
/* @0x2445e8 ldr r10, [r8, r3] */
/* @0x2445ec ldr r3, [pc, #0x330] */
/* @0x2445f0 add r2, pc, r2 */
/* @0x2445f4 str r2, [r11, #0x40] */
/* @0x2445f8 mov r0, r11 */
/* @0x2445fc str r11, [r10] */
/* @0x244600 ldr r9, [r8, r3] */
/* @0x244604 ldr r1, [r9] */
/* @0x244608 str r1, [r11, #0x18] */
/* @0x24460c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x244610 ldr r3, [pc, #0x310] */
/* @0x244614 ldr r0, [r11, #0x28] */
/* @0x244618 mov r1, r6 */
/* @0x24461c mov r2, r6 */
/* @0x244620 orr r0, r0, #1 */
/* @0x244624 str r0, [r11, #0x28] */
/* @0x244628 ldr r0, [r8, r3] */
/* @0x24462c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x244630 ldr r1, [pc, #0x2f4] */
/* @0x244634 mov r3, #6 */
/* @0x244638 add r1, pc, r1 */
/* @0x24463c mov r2, r0 */
/* @0x244640 mov r0, r11 */
/* @0x244644 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x244648 ldr r3, [pc, #0x2e0] */
/* @0x24464c mov r1, r6 */
/* @0x244650 mov r2, r6 */
/* @0x244654 ldr r0, [r8, r3] */
/* @0x244658 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x24465c ldr r1, [pc, #0x2d0] */
/* @0x244660 mov r3, #6 */
/* @0x244664 add r1, pc, r1 */
/* @0x244668 mov r2, r0 */
/* @0x24466c mov r0, r11 */
/* @0x244670 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x244674 ldr r3, [pc, #0x2bc] */
/* @0x244678 mov r1, r6 */
/* @0x24467c mov r2, r6 */
/* @0x244680 ldr r0, [r8, r3] */
/* @0x244684 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x244688 ldr r1, [pc, #0x2ac] */
/* @0x24468c mov r3, #6 */
/* @0x244690 add r1, pc, r1 */
/* @0x244694 mov r2, r0 */
/* @0x244698 mov r0, r11 */
/* @0x24469c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2446a0 ldr r3, [pc, #0x298] */
/* @0x2446a4 mov r2, r6 */
/* @0x2446a8 mov r1, #1 */
/* @0x2446ac ldr r0, [r8, r3] */
/* @0x2446b0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2446b4 ldr r1, [pc, #0x288] */
/* @0x2446b8 mov r3, #6 */
/* @0x2446bc add r1, pc, r1 */
/* @0x2446c0 mov r2, r0 */
/* @0x2446c4 mov r0, r11 */
/* @0x2446c8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2446cc ldr r3, [pc, #0x274] */
/* @0x2446d0 mov r2, r6 */
/* @0x2446d4 mov r1, #1 */
/* @0x2446d8 ldr r0, [r8, r3] */
/* @0x2446dc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2446e0 ldr r1, [pc, #0x264] */
/* @0x2446e4 mov r3, #6 */
/* @0x2446e8 add r1, pc, r1 */
/* @0x2446ec mov r2, r0 */
/* @0x2446f0 mov r0, r11 */
/* @0x2446f4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2446f8 ldr r3, [pc, #0x250] */
/* @0x2446fc mov r2, r6 */
/* @0x244700 mov r1, #1 */
/* @0x244704 ldr r0, [r8, r3] */
/* @0x244708 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x24470c ldr r1, [pc, #0x240] */
/* @0x244710 mov r3, #6 */
/* @0x244714 add r1, pc, r1 */
/* @0x244718 mov r2, r0 */
/* @0x24471c mov r0, r11 */
/* @0x244720 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x244724 add r2, sp, #120 */
/* @0x244728 ldr r1, [pc, #0x228] */
/* @0x24472c mov r0, r11 */
/* @0x244730 strd r4, r5, [r2, #-96]! */
/* @0x244734 mov r3, r6 */
/* @0x244738 add r1, pc, r1 */
/* @0x24473c str r6, [sp, #0x24] */
/* @0x244740 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x244744 ldr r3, [pc, #0x210] */
/* @0x244748 mov r1, r6 */
/* @0x24474c mov r2, r6 */
/* @0x244750 mvn r4, #0 */
/* @0x244754 movw r5, #0xffff */
/* @0x244758 ldr r0, [r8, r3] */
/* @0x24475c movt r5, #0x7fef */
/* @0x244760 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x244764 ldr r12, [pc, #0x1f4] */
/* @0x244768 ldr r1, [pc, #0x1f4] */
/* @0x24476c mov r3, r6 */
/* @0x244770 ldr r12, [r8, r12] */
/* @0x244774 add r1, pc, r1 */
/* @0x244778 mov r7, r0 */
/* @0x24477c mov r0, r11 */
/* @0x244780 str r12, [r7, #0x94] */
/* @0x244784 mov r2, r7 */
/* @0x244788 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x24478c ldr r1, [pc, #0x1d4] */
/* @0x244790 mov r0, r7 */
/* @0x244794 mov r3, r6 */
/* @0x244798 add r1, pc, r1 */
/* @0x24479c add r2, sp, #40 */
/* @0x2447a0 strd r4, r5, [sp, #40] */
/* @0x2447a4 mov r4, #1 */
/* @0x2447a8 str r6, [sp, #0x34] */
/* @0x2447ac mov r5, #0 */
/* @0x2447b0 str r6, [sp, #0x30] */
/* @0x2447b4 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x2447b8 ldr r1, [pc, #0x1ac] */
/* @0x2447bc mov r0, r7 */
/* @0x2447c0 mov r3, r6 */
/* @0x2447c4 add r2, sp, #56 */
/* @0x2447c8 add r1, pc, r1 */
/* @0x2447cc strd r4, r5, [sp, #56] */
/* @0x2447d0 str r6, [sp, #0x44] */
/* @0x2447d4 mvn r4, #0 */
/* @0x2447d8 str r6, [sp, #0x40] */
/* @0x2447dc bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x2447e0 ldr r1, [pc, #0x188] */
/* @0x2447e4 mov r0, r7 */
/* @0x2447e8 mov r3, r6 */
/* @0x2447ec add r2, sp, #72 */
/* @0x2447f0 add r1, pc, r1 */
/* @0x2447f4 mvn r5, #-2147483648 */
/* @0x2447f8 str r6, [sp, #0x54] */
/* @0x2447fc strd r4, r5, [sp, #72] */
/* @0x244800 mov r4, #0 */
/* @0x244804 str r6, [sp, #0x50] */
/* @0x244808 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x24480c ldr r1, [pc, #0x160] */
/* @0x244810 mov r0, r7 */
/* @0x244814 mov r3, r6 */
/* @0x244818 add r2, sp, #88 */
/* @0x24481c add r1, pc, r1 */
/* @0x244820 str r6, [sp, #0x64] */
/* @0x244824 mov r5, #0 */
/* @0x244828 str r6, [sp, #0x60] */
/* @0x24482c movt r5, #0xfff0 */
/* @0x244830 strd r4, r5, [sp, #88] */
/* @0x244834 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x244838 ldr r1, [pc, #0x138] */
/* @0x24483c mov r3, r6 */
/* @0x244840 mov r0, r7 */
/* @0x244844 add r1, pc, r1 */
/* @0x244848 add r2, sp, #104 */
/* @0x24484c str r6, [sp, #0x74] */
/* @0x244850 mov r4, #0 */
/* @0x244854 mov r5, #0 */
/* @0x244858 str r6, [sp, #0x70] */
/* @0x24485c movt r5, #0x7ff0 */
/* @0x244860 strd r4, r5, [sp, #104] */
/* @0x244864 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x244868 ldr r1, [r9] */
/* @0x24486c mov r0, r7 */
/* @0x244870 str r1, [r7, #0x18] */
/* @0x244874 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x244878 ldr r3, [r7, #0x4] */
/* @0x24487c cmp r3, r6 */
/* @0x244880 beq 0x2448d8 <_Z20JS_NumberObjectSetupv+0x330> */
/* @0x244884 ldr r1, [r10] */
/* @0x244888 mov r0, r7 */
/* @0x24488c str r1, [r3] */
/* @0x244890 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x244894 ldr r1, [r7, #0x4] */
/* @0x244898 cmp r1, #0 */
/* @0x24489c movne r3, #6 */
/* @0x2448a0 strne r3, [r1, #0xc] */
/* @0x2448a4 beq 0x2448ec <_Z20JS_NumberObjectSetupv+0x344> */
/* @0x2448a8 ldr r0, [pc, #0xcc] */
/* @0x2448ac mov r3, #6 */
/* @0x2448b0 str r3, [r1, #0x8] */
/* @0x2448b4 mov r2, r7 */
/* @0x2448b8 ldr r1, [pc, #0xc0] */
/* @0x2448bc mov r3, #0 */
/* @0x2448c0 ldr r0, [r8, r0] */
/* @0x2448c4 add r1, pc, r1 */
/* @0x2448c8 ldr r0, [r0] */
/* @0x2448cc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2448d0 add sp, sp, #124 */
/* @0x2448d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2448d8 mov r1, r3 */
/* @0x2448dc mov r0, r7 */
/* @0x2448e0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2448e4 mov r3, r0 */
/* @0x2448e8 b 0x244884 <_Z20JS_NumberObjectSetupv+0x2dc> */
/* @0x2448ec mov r0, r7 */
/* @0x2448f0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2448f4 ldr r1, [r7, #0x4] */
/* @0x2448f8 mov r3, #6 */
/* @0x2448fc cmp r1, #0 */
/* @0x244900 str r3, [r0, #0xc] */
/* @0x244904 bne 0x2448a8 <_Z20JS_NumberObjectSetupv+0x300> */
/* @0x244908 mov r0, r7 */
/* @0x24490c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x244910 mov r1, r0 */
/* @0x244914 b 0x2448a8 <_Z20JS_NumberObjectSetupv+0x300> */
/* @0x244918 andseq sp, r10, r8, ror r6 */
/* @0x24491c .word 0xfffffab4 */
/* @0x244920 andseq r1, r1, r0, lsr #7 */
/* @0x244924 .word 0xffffc050 */
/* @0x244928 .word 0xfffffab8 */
/* @0x24492c ldrdeq sp, lr, [lr], -r8 */
/* @0x244930 .word 0xfffffabc */
/* @0x244934 andseq r0, r1, r4, ror #31 */
/* @0x244938 .word 0xfffffac0 */
/* @0x24493c andseq r0, r1, r8, asr #31 */
/* @0x244940 .word 0xfffffac4 */
/* @0x244944 ldrsbeq r1, [r1], -r12 */
/* @0x244948 .word 0xfffffac8 */
/* @0x24494c ldrheq r1, [r1], -r8 */
/* @0x244950 .word 0xfffffacc */
/* @0x244954 mulseq r1, r12, r2 */
/* @0x244958 ldrsbeq r0, [r1], -r8 */
/* @0x24495c .word 0xfffffad0 */
/* @0x244960 .word 0xfffffad4 */
/* @0x244964 ldrheq r0, [r1], -r0 */
/* @0x244968 andseq r1, r1, r4, lsr #4 */
/* @0x24496c andseq r1, r1, r0, lsl #4 */
/* @0x244970 andeq sp, lr, r4, lsl #26 */
/* @0x244974 ldrheq r1, [r1], -r8 */
/* @0x244978 andseq r1, r1, r4, lsr #3 */
/* @0x24497c .word 0xffffbf64 */
/* @0x244980 andseq r1, r1, r12, asr #1 */

/* ── FUNC 0x244984 · anon_244984 · size=0 · insn=1 */
/* @0x244984 andeq r0, r0, r0 */

/* ── FUNC 0x244988 · DateGetNow() · size=48 · insn=12 */
/* @0x244988 push {r3, lr} */
/* @0x24498c mov r0, #0 */
/* @0x244990 bl 0xb67fc <time@plt> */
/* @0x244994 vldr d7, [pc, #20] */
/* @0x244998 vmov s10, r0 */
/* @0x24499c vcvt.f64.s32 d6, s10 */
/* @0x2449a0 vmul.f64 d5, d6, d7 */
/* @0x2449a4 vmov r0, r1, d5 */
/* @0x2449a8 pop {r3, pc} */
/* @0x2449ac nop */
/* @0x2449b0 andeq r0, r0, r0 */
/* @0x2449b4 addmi r4, pc, r0 */

/* ── FUNC 0x2449b8 · JS_Date_now(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x2449b8 push {r4, lr} */
/* @0x2449bc mov r3, #0 */
/* @0x2449c0 str r3, [r0, #0xc] */
/* @0x2449c4 mov r4, r0 */
/* @0x2449c8 bl 0x244988 <_Z10DateGetNowv> */
/* @0x2449cc stm r4, {r0, r1} */
/* @0x2449d0 pop {r4, pc} */

/* ── FUNC 0x2449d4 · anon_2449d4 · size=0 · insn=1 */
/* @0x2449d4 andeq r0, r0, r0 */

/* ── FUNC 0x2449d8 · Day(double) · size=32 · insn=8 */
/* @0x2449d8 vmov d6, r0, r1 */
/* @0x2449dc vldr d7, [pc, #12] */
/* @0x2449e0 vdiv.f64 d6, d6, d7 */
/* @0x2449e4 vmov r0, r1, d6 */
/* @0x2449e8 b 0xb6598 <floor@plt> */
/* @0x2449ec nop */
/* @0x2449f0 andeq r0, r0, r0 */
/* @0x2449f4 orrsmi r9, r4, r0, ror r9 */

/* ── FUNC 0x2449f8 · TimeWithinDay(double) · size=16 · insn=4 */
/* @0x2449f8 movw r3, #0x9970 */
/* @0x2449fc mov r2, #0 */
/* @0x244a00 movt r3, #0x4194 */
/* @0x244a04 b 0xb66ac <fmod@plt> */

/* ── FUNC 0x244a08 · DaysInYear(double) · size=160 · insn=40 */
/* @0x244a08 push {r3, r4, r5, lr} */
/* @0x244a0c mov r2, #0 */
/* @0x244a10 mov r3, #0 */
/* @0x244a14 movt r3, #0x4010 */
/* @0x244a18 mov r4, r0 */
/* @0x244a1c mov r5, r1 */
/* @0x244a20 bl 0xb66ac <fmod@plt> */
/* @0x244a24 vmov d7, r0, r1 */
/* @0x244a28 vcmp.f64 d7, #0 */
/* @0x244a2c vmrs APSR_nzcv, fpscr */
/* @0x244a30 beq 0x244a44 <_Z10DaysInYeard+0x3c> */
/* @0x244a34 mov r0, #0 */
/* @0x244a38 mov r1, #53248 */
/* @0x244a3c movt r1, #0x4076 */
/* @0x244a40 pop {r3, r4, r5, pc} */
/* @0x244a44 mov r0, r4 */
/* @0x244a48 mov r1, r5 */
/* @0x244a4c mov r2, #0 */
/* @0x244a50 mov r3, #0 */
/* @0x244a54 movt r3, #0x4059 */
/* @0x244a58 bl 0xb66ac <fmod@plt> */
/* @0x244a5c vmov d7, r0, r1 */
/* @0x244a60 vcmp.f64 d7, #0 */
/* @0x244a64 vmrs APSR_nzcv, fpscr */
/* @0x244a68 beq 0x244a7c <_Z10DaysInYeard+0x74> */
/* @0x244a6c mov r0, #0 */
/* @0x244a70 mov r1, #57344 */
/* @0x244a74 movt r1, #0x4076 */
/* @0x244a78 pop {r3, r4, r5, pc} */
/* @0x244a7c mov r0, r4 */
/* @0x244a80 mov r1, r5 */
/* @0x244a84 mov r2, #0 */
/* @0x244a88 mov r3, #0 */
/* @0x244a8c movt r3, #0x4079 */
/* @0x244a90 bl 0xb66ac <fmod@plt> */
/* @0x244a94 vmov d7, r0, r1 */
/* @0x244a98 vcmp.f64 d7, #0 */
/* @0x244a9c vmrs APSR_nzcv, fpscr */
/* @0x244aa0 beq 0x244a6c <_Z10DaysInYeard+0x64> */
/* @0x244aa4 b 0x244a34 <_Z10DaysInYeard+0x2c> */

/* ── FUNC 0x244aa8 · DayFromYear(double) · size=192 · insn=48 */
/* @0x244aa8 push {r3, lr} */
/* @0x244aac vpush {d8, d9, d10} */
/* @0x244ab0 vmov d8, r0, r1 */
/* @0x244ab4 vldr d6, [pc, #116] */
/* @0x244ab8 vmov.f64 d7, #2.500000e-01 */
/* @0x244abc vsub.f64 d6, d8, d6 */
/* @0x244ac0 vmul.f64 d5, d6, d7 */
/* @0x244ac4 vmov r0, r1, d5 */
/* @0x244ac8 bl 0xb6598 <floor@plt> */
/* @0x244acc vldr d6, [pc, #100] */
/* @0x244ad0 vsub.f64 d6, d8, d6 */
/* @0x244ad4 vldr d7, [pc, #100] */
/* @0x244ad8 vdiv.f64 d5, d6, d7 */
/* @0x244adc vmov d10, r0, r1 */
/* @0x244ae0 vmov r0, r1, d5 */
/* @0x244ae4 bl 0xb6598 <floor@plt> */
/* @0x244ae8 vldr d6, [pc, #88] */
/* @0x244aec vsub.f64 d6, d8, d6 */
/* @0x244af0 vldr d7, [pc, #88] */
/* @0x244af4 vdiv.f64 d5, d6, d7 */
/* @0x244af8 vmov d9, r0, r1 */
/* @0x244afc vmov r0, r1, d5 */
/* @0x244b00 bl 0xb6598 <floor@plt> */
/* @0x244b04 vldr d6, [pc, #76] */
/* @0x244b08 vsub.f64 d8, d8, d6 */
/* @0x244b0c vldr d7, [pc, #76] */
/* @0x244b10 vmla.f64 d10, d8, d7 */
/* @0x244b14 vmov d7, r0, r1 */
/* @0x244b18 vsub.f64 d9, d10, d9 */
/* @0x244b1c vadd.f64 d7, d9, d7 */
/* @0x244b20 vpop {d8, d9, d10} */
/* @0x244b24 vmov r0, r1, d7 */
/* @0x244b28 pop {r3, pc} */
/* @0x244b2c nop */
/* @0x244b30 andeq r0, r0, r0 */
/* @0x244b34 addsmi r12, lr, r0, lsl #8 */
/* @0x244b38 andeq r0, r0, r0 */
/* @0x244b3c addsmi r11, sp, r0, lsl #8 */
/* @0x244b40 andeq r0, r0, r0 */
/* @0x244b44 subsmi r0, r9, r0 */
/* @0x244b48 andeq r0, r0, r0 */
/* @0x244b4c addsmi r0, r9, r0, lsl #8 */
/* @0x244b50 andeq r0, r0, r0 */
/* @0x244b54 rsbsmi r0, r9, r0 */
/* @0x244b58 andeq r0, r0, r0 */
/* @0x244b5c addsmi r12, lr, r0, lsl #16 */
/* @0x244b60 andeq r0, r0, r0 */
/* @0x244b64 rsbsmi sp, r6, r0 */

/* ── FUNC 0x244b68 · TimeFromYear(double) · size=40 · insn=10 */
/* @0x244b68 push {r3, lr} */
/* @0x244b6c bl 0x244aa8 <_Z11DayFromYeard> */
/* @0x244b70 vldr d7, [pc, #16] */
/* @0x244b74 vmov d6, r0, r1 */
/* @0x244b78 vmul.f64 d6, d6, d7 */
/* @0x244b7c vmov r0, r1, d6 */
/* @0x244b80 pop {r3, pc} */
/* @0x244b84 nop */
/* @0x244b88 andeq r0, r0, r0 */
/* @0x244b8c orrsmi r9, r4, r0, ror r9 */

/* ── FUNC 0x244b90 · YearFromTime(double) · size=88 · insn=22 */
/* @0x244b90 push {r3, r4, r5, lr} */
/* @0x244b94 vpush {d8, d9, d10} */
/* @0x244b98 vldr d8, [pc, #64] */
/* @0x244b9c vmov d9, r0, r1 */
/* @0x244ba0 vmov r4, r5, d8 */
/* @0x244ba4 vmov.f64 d10, #1.000000e+00 */
/* @0x244ba8 b 0x244bb4 <_Z12YearFromTimed+0x24> */
/* @0x244bac vmov r4, r5, d8 */
/* @0x244bb0 vadd.f64 d8, d8, d10 */
/* @0x244bb4 vmov r0, r1, d8 */
/* @0x244bb8 bl 0x244b68 <_Z12TimeFromYeard> */
/* @0x244bbc vmov d7, r0, r1 */
/* @0x244bc0 vcmpe.f64 d7, d9 */
/* @0x244bc4 vmrs APSR_nzcv, fpscr */
/* @0x244bc8 bgt 0x244bac <_Z12YearFromTimed+0x1c> */
/* @0x244bcc vpop {d8, d9, d10} */
/* @0x244bd0 mov r0, r4 */
/* @0x244bd4 mov r1, r5 */
/* @0x244bd8 pop {r3, r4, r5, pc} */
/* @0x244bdc nop */
/* @0x244be0 andeq r0, r0, r0 */
/* @0x244be4 addsmi r12, lr, r0, lsl #16 */

/* ── FUNC 0x244be8 · InLeapYear(double) · size=64 · insn=16 */
/* @0x244be8 push {r3, lr} */
/* @0x244bec bl 0x244b90 <_Z12YearFromTimed> */
/* @0x244bf0 bl 0x244a08 <_Z10DaysInYeard> */
/* @0x244bf4 vldr d7, [pc, #36] */
/* @0x244bf8 vmov d6, r0, r1 */
/* @0x244bfc vcmp.f64 d6, d7 */
/* @0x244c00 vmrs APSR_nzcv, fpscr */
/* @0x244c04 moveq r0, #0 */
/* @0x244c08 movne r0, #1 */
/* @0x244c0c vmov s15, r0 */
/* @0x244c10 vcvt.f64.s32 d7, s15 */
/* @0x244c14 vmov r0, r1, d7 */
/* @0x244c18 pop {r3, pc} */
/* @0x244c1c nop */
/* @0x244c20 andeq r0, r0, r0 */
/* @0x244c24 rsbsmi sp, r6, r0 */

/* ── FUNC 0x244c28 · DayWithinYear(double) · size=60 · insn=15 */
/* @0x244c28 push {r3, r4, r5, lr} */
/* @0x244c2c vpush {d8} */
/* @0x244c30 mov r4, r0 */
/* @0x244c34 mov r5, r1 */
/* @0x244c38 bl 0x244b90 <_Z12YearFromTimed> */
/* @0x244c3c bl 0x244aa8 <_Z11DayFromYeard> */
/* @0x244c40 vmov d8, r0, r1 */
/* @0x244c44 mov r0, r4 */
/* @0x244c48 mov r1, r5 */
/* @0x244c4c bl 0x2449d8 <_Z3Dayd> */
/* @0x244c50 vmov d7, r0, r1 */
/* @0x244c54 vsub.f64 d7, d7, d8 */
/* @0x244c58 vpop {d8} */
/* @0x244c5c vmov r0, r1, d7 */
/* @0x244c60 pop {r3, r4, r5, pc} */

/* ── FUNC 0x244c64 · anon_244c64 · size=0 · insn=1 */
/* @0x244c64 andeq r0, r0, r0 */

/* ── FUNC 0x244c68 · MonthFromTime(double) · size=760 · insn=190 */
/* @0x244c68 push {r3, r4, r5, lr} */
/* @0x244c6c vpush {d8} */
/* @0x244c70 mov r4, r0 */
/* @0x244c74 mov r5, r1 */
/* @0x244c78 bl 0x244c28 <_Z13DayWithinYeard> */
/* @0x244c7c vmov d8, r0, r1 */
/* @0x244c80 mov r0, r4 */
/* @0x244c84 mov r1, r5 */
/* @0x244c88 bl 0x244be8 <_Z10InLeapYeard> */
/* @0x244c8c vcmpe.f64 d8, #0 */
/* @0x244c90 vmrs APSR_nzcv, fpscr */
/* @0x244c94 vmov d7, r0, r1 */
/* @0x244c98 blt 0x244cb4 <_Z13MonthFromTimed+0x4c> */
/* @0x244c9c vmov.f64 d6, #3.100000e+01 */
/* @0x244ca0 vcmpe.f64 d8, d6 */
/* @0x244ca4 vmrs APSR_nzcv, fpscr */
/* @0x244ca8 movmi r0, #0 */
/* @0x244cac movmi r1, #0 */
/* @0x244cb0 bmi 0x244d3c <_Z13MonthFromTimed+0xd4> */
/* @0x244cb4 vmov.f64 d6, #3.100000e+01 */
/* @0x244cb8 vcmpe.f64 d8, d6 */
/* @0x244cbc vmrs APSR_nzcv, fpscr */
/* @0x244cc0 blt 0x244cd8 <_Z13MonthFromTimed+0x70> */
/* @0x244cc4 vldr d6, [pc, #572] */
/* @0x244cc8 vadd.f64 d6, d7, d6 */
/* @0x244ccc vcmpe.f64 d8, d6 */
/* @0x244cd0 vmrs APSR_nzcv, fpscr */
/* @0x244cd4 bmi 0x244e6c <_Z13MonthFromTimed+0x204> */
/* @0x244cd8 vldr d6, [pc, #552] */
/* @0x244cdc vcmpe.f64 d8, d6 */
/* @0x244ce0 vmrs APSR_nzcv, fpscr */
/* @0x244ce4 bge 0x244d44 <_Z13MonthFromTimed+0xdc> */
/* @0x244ce8 vldr d6, [pc, #544] */
/* @0x244cec vcmpe.f64 d8, d6 */
/* @0x244cf0 vmrs APSR_nzcv, fpscr */
/* @0x244cf4 blt 0x244d0c <_Z13MonthFromTimed+0xa4> */
/* @0x244cf8 vldr d6, [pc, #536] */
/* @0x244cfc vadd.f64 d6, d7, d6 */
/* @0x244d00 vcmpe.f64 d8, d6 */
/* @0x244d04 vmrs APSR_nzcv, fpscr */
/* @0x244d08 bmi 0x244ea4 <_Z13MonthFromTimed+0x23c> */
/* @0x244d0c vldr d6, [pc, #516] */
/* @0x244d10 vcmpe.f64 d8, d6 */
/* @0x244d14 vmrs APSR_nzcv, fpscr */
/* @0x244d18 blt 0x244d68 <_Z13MonthFromTimed+0x100> */
/* @0x244d1c vldr d6, [pc, #508] */
/* @0x244d20 vadd.f64 d6, d7, d6 */
/* @0x244d24 vcmpe.f64 d8, d6 */
/* @0x244d28 vmrs APSR_nzcv, fpscr */
/* @0x244d2c bpl 0x244d68 <_Z13MonthFromTimed+0x100> */
/* @0x244d30 mov r1, #0 */
/* @0x244d34 movt r1, #0x4010 */
/* @0x244d38 mov r0, #0 */
/* @0x244d3c vpop {d8} */
/* @0x244d40 pop {r3, r4, r5, pc} */
/* @0x244d44 vldr d6, [pc, #452] */
/* @0x244d48 vadd.f64 d6, d7, d6 */
/* @0x244d4c vcmpe.f64 d8, d6 */
/* @0x244d50 vmrs APSR_nzcv, fpscr */
/* @0x244d54 movmi r0, #0 */
/* @0x244d58 movmi r1, #1073741824 */
/* @0x244d5c bpl 0x244ce8 <_Z13MonthFromTimed+0x80> */
/* @0x244d60 vpop {d8} */
/* @0x244d64 pop {r3, r4, r5, pc} */
/* @0x244d68 vldr d6, [pc, #432] */
/* @0x244d6c vcmpe.f64 d8, d6 */
/* @0x244d70 vmrs APSR_nzcv, fpscr */
/* @0x244d74 blt 0x244d98 <_Z13MonthFromTimed+0x130> */
/* @0x244d78 vldr d6, [pc, #424] */
/* @0x244d7c vadd.f64 d6, d7, d6 */
/* @0x244d80 vcmpe.f64 d8, d6 */
/* @0x244d84 vmrs APSR_nzcv, fpscr */
/* @0x244d88 movmi r1, #0 */
/* @0x244d8c movmi r0, #0 */
/* @0x244d90 movtmi r1, #0x4014 */
/* @0x244d94 bmi 0x244d3c <_Z13MonthFromTimed+0xd4> */
/* @0x244d98 vldr d6, [pc, #392] */
/* @0x244d9c vcmpe.f64 d8, d6 */
/* @0x244da0 vmrs APSR_nzcv, fpscr */
/* @0x244da4 bge 0x244e80 <_Z13MonthFromTimed+0x218> */
/* @0x244da8 vldr d6, [pc, #384] */
/* @0x244dac vcmpe.f64 d8, d6 */
/* @0x244db0 vmrs APSR_nzcv, fpscr */
/* @0x244db4 blt 0x244dcc <_Z13MonthFromTimed+0x164> */
/* @0x244db8 vldr d6, [pc, #376] */
/* @0x244dbc vadd.f64 d6, d7, d6 */
/* @0x244dc0 vcmpe.f64 d8, d6 */
/* @0x244dc4 vmrs APSR_nzcv, fpscr */
/* @0x244dc8 bmi 0x244ef4 <_Z13MonthFromTimed+0x28c> */
/* @0x244dcc vldr d6, [pc, #356] */
/* @0x244dd0 vcmpe.f64 d8, d6 */
/* @0x244dd4 vmrs APSR_nzcv, fpscr */
/* @0x244dd8 blt 0x244df0 <_Z13MonthFromTimed+0x188> */
/* @0x244ddc vldr d6, [pc, #348] */
/* @0x244de0 vadd.f64 d6, d7, d6 */
/* @0x244de4 vcmpe.f64 d8, d6 */
/* @0x244de8 vmrs APSR_nzcv, fpscr */
/* @0x244dec bmi 0x244ec4 <_Z13MonthFromTimed+0x25c> */
/* @0x244df0 vldr d6, [pc, #328] */
/* @0x244df4 vcmpe.f64 d8, d6 */
/* @0x244df8 vmrs APSR_nzcv, fpscr */
/* @0x244dfc blt 0x244e14 <_Z13MonthFromTimed+0x1ac> */
/* @0x244e00 vldr d6, [pc, #320] */
/* @0x244e04 vadd.f64 d6, d7, d6 */
/* @0x244e08 vcmpe.f64 d8, d6 */
/* @0x244e0c vmrs APSR_nzcv, fpscr */
/* @0x244e10 bmi 0x244ed4 <_Z13MonthFromTimed+0x26c> */
/* @0x244e14 vldr d6, [pc, #300] */
/* @0x244e18 vcmpe.f64 d8, d6 */
/* @0x244e1c vmrs APSR_nzcv, fpscr */
/* @0x244e20 blt 0x244e38 <_Z13MonthFromTimed+0x1d0> */
/* @0x244e24 vldr d6, [pc, #292] */
/* @0x244e28 vadd.f64 d6, d7, d6 */
/* @0x244e2c vcmpe.f64 d8, d6 */
/* @0x244e30 vmrs APSR_nzcv, fpscr */
/* @0x244e34 bmi 0x244ee4 <_Z13MonthFromTimed+0x27c> */
/* @0x244e38 vldr d6, [pc, #272] */
/* @0x244e3c vcmpe.f64 d8, d6 */
/* @0x244e40 vmrs APSR_nzcv, fpscr */
/* @0x244e44 blt 0x244eb4 <_Z13MonthFromTimed+0x24c> */
/* @0x244e48 vldr d6, [pc, #264] */
/* @0x244e4c vadd.f64 d7, d7, d6 */
/* @0x244e50 vmov.f64 d5, #1.100000e+01 */
/* @0x244e54 vmov.f64 d6, #-1.000000e+00 */
/* @0x244e58 vcmpe.f64 d8, d7 */
/* @0x244e5c vmrs APSR_nzcv, fpscr */
/* @0x244e60 vmovpl r0, r1, d6 */
/* @0x244e64 vmovmi r0, r1, d5 */
/* @0x244e68 b 0x244d3c <_Z13MonthFromTimed+0xd4> */
/* @0x244e6c vpop {d8} */
/* @0x244e70 mov r0, #0 */
/* @0x244e74 mov r1, #0 */
/* @0x244e78 movt r1, #0x3ff0 */
/* @0x244e7c pop {r3, r4, r5, pc} */
/* @0x244e80 vldr d6, [pc, #168] */
/* @0x244e84 vadd.f64 d6, d7, d6 */
/* @0x244e88 vcmpe.f64 d8, d6 */
/* @0x244e8c vmrs APSR_nzcv, fpscr */
/* @0x244e90 bpl 0x244da8 <_Z13MonthFromTimed+0x140> */
/* @0x244e94 mov r1, #0 */
/* @0x244e98 mov r0, #0 */
/* @0x244e9c movt r1, #0x4018 */
/* @0x244ea0 b 0x244d3c <_Z13MonthFromTimed+0xd4> */
/* @0x244ea4 mov r1, #0 */
/* @0x244ea8 mov r0, #0 */
/* @0x244eac movt r1, #0x4008 */
/* @0x244eb0 b 0x244d3c <_Z13MonthFromTimed+0xd4> */
/* @0x244eb4 mov r1, #0 */
/* @0x244eb8 mov r0, #0 */
/* @0x244ebc movt r1, #0xbff0 */
/* @0x244ec0 b 0x244d3c <_Z13MonthFromTimed+0xd4> */
/* @0x244ec4 mov r1, #0 */
/* @0x244ec8 mov r0, #0 */
/* @0x244ecc movt r1, #0x4020 */
/* @0x244ed0 b 0x244d3c <_Z13MonthFromTimed+0xd4> */
/* @0x244ed4 mov r1, #0 */
/* @0x244ed8 mov r0, #0 */
/* @0x244edc movt r1, #0x4022 */
/* @0x244ee0 b 0x244d3c <_Z13MonthFromTimed+0xd4> */
/* @0x244ee4 mov r1, #0 */
/* @0x244ee8 mov r0, #0 */
/* @0x244eec movt r1, #0x4024 */
/* @0x244ef0 b 0x244d3c <_Z13MonthFromTimed+0xd4> */
/* @0x244ef4 mov r1, #0 */
/* @0x244ef8 mov r0, #0 */
/* @0x244efc movt r1, #0x401c */
/* @0x244f00 b 0x244d3c <_Z13MonthFromTimed+0xd4> */
/* @0x244f04 nop */
/* @0x244f08 andeq r0, r0, r0 */
/* @0x244f0c submi r8, sp, r0 */
/* @0x244f10 andeq r0, r0, r0 */
/* @0x244f14 subsmi r8, r6, r0 */
/* @0x244f18 andeq r0, r0, r0 */
/* @0x244f1c subsmi r0, lr, r0 */
/* @0x244f20 andeq r0, r0, r0 */
/* @0x244f24 rsbmi lr, r2, r0 */
/* @0x244f28 andeq r0, r0, r0 */
/* @0x244f2c rsbmi r10, r6, r0 */
/* @0x244f30 andeq r0, r0, r0 */
/* @0x244f34 rsbmi r8, r10, r0 */
/* @0x244f38 andeq r0, r0, r0 */
/* @0x244f3c rsbmi r6, lr, r0 */
/* @0x244f40 andeq r0, r0, r0 */
/* @0x244f44 rsbsmi r1, r1, r0 */
/* @0x244f48 andeq r0, r0, r0 */
/* @0x244f4c rsbsmi r0, r3, r0 */
/* @0x244f50 andeq r0, r0, r0 */
/* @0x244f54 rsbsmi lr, r4, r0 */
/* @0x244f58 andeq r0, r0, r0 */
/* @0x244f5c rsbsmi sp, r6, r0 */
