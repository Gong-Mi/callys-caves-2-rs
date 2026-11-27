/* cally 逆向卡：All_36 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 42 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/42 F_DrawBackgroundGeneral(RValue&, CInstance*, CInstance*, int, RValue*)  0x11e168  size 752  188 条（0x11e168..0x11e458）
 * @func 0x11e168 0x11e458  size 752  188 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×20 / YYGetInt32(RValue const*, int)×10 / Sprite_Data(int) / CSprite::DrawGeneral(int, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float) / Background_Data(int) / CBackground::DrawGeneral(float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)
 * 字段偏移 top8: 0x34×4 / 0x38×4 / 0x3c×4 / 0x40×4 / 0x44×4 / 0x48×4 / 0x4c×4 / 0x14×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11e168 ldr r3, [pc, #0x2e0]
 *   @0x11e16c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11e170 ldr r3, [pc, r3]
 *   @0x11e174 sub sp, sp, #84
 *   @0x11e178 ldrb r1, [r3]
 *   @0x11e17c ldr r4, [sp, #0x78]
 *   @0x11e180 cmp r1, #0
 *   @0x11e184 mov r0, r4
 *   @0x11e188 beq 0x11e2e8 <_Z23F_DrawBackgroundGeneralR6RValueP9CInstanceS2_iPS_+0x180>
 *   @0x11e18c mov r1, #0
 *   @0x11e190 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e194 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11e198 subs r5, r0, #0
 *   @0x11e19c beq 0x11e438 <_Z23F_DrawBackgroundGeneralR6RValueP9CInstanceS2_iPS_+0x2d0>
 *   @0x11e1a0 mov r0, r4
 *   @0x11e1a4 mov r1, #1
 *   @0x11e1a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e1ac mov r1, #2
 *   @0x11e1b0 mov r2, r0
 *   @0x11e1b4 mov r0, r4
 *   @0x11e1b8 str r2, [sp, #0x34]
 *   @0x11e1bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e1c0 mov r1, #3
 *   @0x11e1c4 mov r3, r0
 *   @0x11e1c8 mov r0, r4
 *   @0x11e1cc str r3, [sp, #0x38]
 *   @0x11e1d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e1d4 mov r1, #4
 *   @0x11e1d8 mov r12, r0
 *   @0x11e1dc mov r0, r4
 *   @0x11e1e0 str r12, [sp, #0x3c]
 *   @0x11e1e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e1e8 mov r1, #5
 *   @0x11e1ec str r0, [sp, #0x40]
 *   @0x11e1f0 mov r0, r4
 *   @0x11e1f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e1f8 mov r1, #6
 *   @0x11e1fc str r0, [sp, #0x44]
 *   @0x11e200 mov r0, r4
 *   @0x11e204 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e208 mov r1, #7
 *   @0x11e20c mov r11, r0
 *   @0x11e210 mov r0, r4
 *   @0x11e214 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e218 mov r1, #8
 *   @0x11e21c mov r10, r0
 *   @0x11e220 mov r0, r4
 *   @0x11e224 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e228 mov r1, #9
 *   @0x11e22c mov r9, r0
 *   @0x11e230 mov r0, r4
 *   @0x11e234 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e238 mov r1, #10
 *   @0x11e23c str r0, [sp, #0x48]
 *   @0x11e240 mov r0, r4
 *   @0x11e244 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e248 mov r1, #11
 *   @0x11e24c str r0, [sp, #0x4c]
 *   @0x11e250 mov r0, r4
 *   @0x11e254 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e258 mov r1, #12
 *   @0x11e25c mov r8, r0
 *   @0x11e260 mov r0, r4
 *   @0x11e264 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e268 mov r1, #13
 *   @0x11e26c mov r7, r0
 *   @0x11e270 mov r0, r4
 *   @0x11e274 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e278 mov r1, #14
 *   @0x11e27c mov r6, r0
 *   @0x11e280 mov r0, r4
 *   @0x11e284 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e288 ldr r1, [sp, #0x40]
 *   @0x11e28c ldr r12, [sp, #0x3c]
 *   @0x11e290 str r11, [sp, #0xc]
 *   @0x11e294 str r1, [sp, #0x4]
 *   @0x11e298 ldr r1, [sp, #0x44]
 *   @0x11e29c str r12, [sp]
 *   @0x11e2a0 str r10, [sp, #0x10]
 *   @0x11e2a4 str r1, [sp, #0x8]
 *   @0x11e2a8 ldr r1, [sp, #0x48]
 *   @0x11e2ac str r9, [sp, #0x14]
 *   @0x11e2b0 str r8, [sp, #0x20]
 *   @0x11e2b4 str r1, [sp, #0x18]
 *   @0x11e2b8 ldr r1, [sp, #0x4c]
 *   @0x11e2bc str r7, [sp, #0x24]
 *   @0x11e2c0 str r6, [sp, #0x28]
 *   @0x11e2c4 str r1, [sp, #0x1c]
 *   @0x11e2c8 mov r1, #0
 *   @0x11e2cc ldr r2, [sp, #0x34]
 *   @0x11e2d0 ldr r3, [sp, #0x38]
 *   @0x11e2d4 str r0, [sp, #0x2c]
 *   @0x11e2d8 mov r0, r5
 *   @0x11e2dc bl 0x1e5fa8 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf>
 *   @0x11e2e0 add sp, sp, #84
 *   @0x11e2e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11e2e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e2ec bl 0xc3794 <_Z15Background_Datai>
 *   @0x11e2f0 subs r5, r0, #0
 *   @0x11e2f4 beq 0x11e438 <_Z23F_DrawBackgroundGeneralR6RValueP9CInstanceS2_iPS_+0x2d0>
 *   @0x11e2f8 mov r0, r4
 *   @0x11e2fc mov r1, #1
 *   @0x11e300 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e304 mov r1, #2
 *   @0x11e308 str r0, [sp, #0x40]
 *   @0x11e30c mov r0, r4
 *   @0x11e310 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e314 mov r1, #3
 *   @0x11e318 mov r2, r0
 *   @0x11e31c mov r0, r4
 *   @0x11e320 str r2, [sp, #0x34]
 *   @0x11e324 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e328 mov r1, #4
 *   @0x11e32c mov r3, r0
 *   @0x11e330 mov r0, r4
 *   @0x11e334 str r3, [sp, #0x38]
 *   @0x11e338 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e33c mov r1, #5
 *   @0x11e340 mov r12, r0
 *   @0x11e344 mov r0, r4
 *   @0x11e348 str r12, [sp, #0x3c]
 *   @0x11e34c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e350 mov r1, #6
 *   @0x11e354 str r0, [sp, #0x44]
 *   @0x11e358 mov r0, r4
 *   @0x11e35c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e360 mov r1, #7
 *   @0x11e364 str r0, [sp, #0x48]
 *   @0x11e368 mov r0, r4
 *   @0x11e36c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e370 mov r1, #8
 *   @0x11e374 mov r11, r0
 *   @0x11e378 mov r0, r4
 *   @0x11e37c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e380 mov r1, #9
 *   @0x11e384 mov r10, r0
 *   @0x11e388 mov r0, r4
 *   @0x11e38c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e390 mov r1, #10
 *   @0x11e394 mov r9, r0
 *   @0x11e398 mov r0, r4
 *   @0x11e39c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e3a0 mov r1, #11
 *   @0x11e3a4 str r0, [sp, #0x4c]
 *   @0x11e3a8 mov r0, r4
 *   @0x11e3ac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e3b0 mov r1, #12
 *   @0x11e3b4 mov r8, r0
 *   @0x11e3b8 mov r0, r4
 *   @0x11e3bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e3c0 mov r1, #13
 *   @0x11e3c4 mov r7, r0
 *   @0x11e3c8 mov r0, r4
 *   @0x11e3cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e3d0 mov r1, #14
 *   @0x11e3d4 mov r6, r0
 *   @0x11e3d8 mov r0, r4
 *   @0x11e3dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e3e0 ldr r1, [sp, #0x44]
 *   @0x11e3e4 ldr r12, [sp, #0x3c]
 *   @0x11e3e8 str r11, [sp, #0xc]
 *   @0x11e3ec str r1, [sp, #0x4]
 *   @0x11e3f0 ldr r1, [sp, #0x48]
 *   @0x11e3f4 str r12, [sp]
 *   @0x11e3f8 str r10, [sp, #0x10]
 *   @0x11e3fc str r1, [sp, #0x8]
 *   @0x11e400 ldr r1, [sp, #0x4c]
 *   @0x11e404 str r9, [sp, #0x14]
 *   @0x11e408 str r8, [sp, #0x1c]
 *   @0x11e40c str r1, [sp, #0x18]
 *   @0x11e410 str r7, [sp, #0x20]
 *   @0x11e414 str r6, [sp, #0x24]
 *   @0x11e418 ldr r1, [sp, #0x40]
 *   @0x11e41c ldr r2, [sp, #0x34]
 *   @0x11e420 ldr r3, [sp, #0x38]
 *   @0x11e424 str r0, [sp, #0x28]
 *   @0x11e428 mov r0, r5
 *   @0x11e42c bl 0xc2238 <_ZN11CBackground11DrawGeneralEfffffffffjjjjf>
 *   @0x11e430 add sp, sp, #84
 *   @0x11e434 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11e438 ldr r0, [pc, #0x14]
 *   @0x11e43c mov r1, #0
 *   @0x11e440 add r0, pc, r0
 *   @0x11e444 add sp, sp, #84
 *   @0x11e448 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11e44c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11e450 .word 0x002cf7b4
 *   @0x11e454 mlaeq r1, r4, sp, r11
 *
 * ══ §2/42 Eff_Effect11(int, float, float, int, unsigned int)  0x1a21b8  size 752  188 条（0x1a21b8..0x1a24a8）
 * @func 0x1a21b8 0x1a24a8  size 752  188 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: fYYRandom(double)×6 / ParticleSystem_Particles_Create_Color(int, float, float, int, unsigned int, int)×3 / 0xb66e8×2 / Speed_Factor() / ParticleType_Shape(int, int) / ParticleType_Size(int, float, float, float, float) / ParticleType_Alpha1(int, float) / ParticleType_Orientation(int, float, float, float, float, bool)
 * 字段偏移 top8: 0x4×2 / 0x48×1 / 0x2c4×1 / 0x2bc×1 / 0x14×1
 * VFP 指令 64 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a21b8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1a21bc vpush {d8, d9, d10, d11}
 *   @0x1a21c0 sub sp, sp, #8
 *   @0x1a21c4 mov r9, r3
 *   @0x1a21c8 mov r7, r0
 *   @0x1a21cc ldr r8, [sp, #0x48]
 *   @0x1a21d0 bl 0x19ff6c <_Z12Speed_Factorv>
 *   @0x1a21d4 ldr r4, [pc, #0x2c4]
 *   @0x1a21d8 mov r5, #0
 *   @0x1a21dc mov r1, #13
 *   @0x1a21e0 ldr r6, [pc, #0x2bc]
 *   @0x1a21e4 ldr r4, [pc, r4]
 *   @0x1a21e8 vmov s16, r0
 *   @0x1a21ec ldr r0, [r4]
 *   @0x1a21f0 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a21f4 mov r3, r5
 *   @0x1a21f8 ldr r0, [r4]
 *   @0x1a21fc mov r2, #1048576000
 *   @0x1a2200 str r5, [sp]
 *   @0x1a2204 movw r1, #0xcccd
 *   @0x1a2208 movt r1, #0x3dcc
 *   @0x1a220c bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a2210 ldr r0, [r4]
 *   @0x1a2214 movw r1, #0x999a
 *   @0x1a2218 movt r1, #0x3f19
 *   @0x1a221c bl 0x1a3668 <_Z19ParticleType_Alpha1if>
 *   @0x1a2220 ldr r0, [r4]
 *   @0x1a2224 mov r1, r5
 *   @0x1a2228 mov r3, r5
 *   @0x1a222c str r5, [sp]
 *   @0x1a2230 mov r2, #0
 *   @0x1a2234 str r2, [sp, #0x4]
 *   @0x1a2238 mov r2, #0
 *   @0x1a223c movt r2, #0x43b4
 *   @0x1a2240 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb>
 *   @0x1a2244 vmov.f32 s14, #2.500000e+00
 *   @0x1a2248 ldr r0, [r4]
 *   @0x1a224c mov r3, r5
 *   @0x1a2250 str r5, [sp]
 *   @0x1a2254 vmov.f32 s15, #3.000000e+00
 *   @0x1a2258 vmul.f32 s14, s16, s14
 *   @0x1a225c vmul.f32 s15, s16, s15
 *   @0x1a2260 vmov r1, s14
 *   @0x1a2264 vmov r2, s15
 *   @0x1a2268 bl 0x1a3368 <_Z18ParticleType_Speediffff>
 *   @0x1a226c ldr r0, [r4]
 *   @0x1a2270 mov r3, r5
 *   @0x1a2274 mov r1, #0
 *   @0x1a2278 mov r2, #0
 *   @0x1a227c movt r1, #0x4370
 *   @0x1a2280 movt r2, #0x4396
 *   @0x1a2284 mov r12, #0
 *   @0x1a2288 movt r12, #0x41a0
 *   @0x1a228c str r12, [sp]
 *   @0x1a2290 bl 0x1a33b4 <_Z22ParticleType_Directioniffff>
 *   @0x1a2294 ldr r6, [pc, r6]
 *   @0x1a2298 ldr r10, [r4]
 *   @0x1a229c ldr r3, [r6]
 *   @0x1a22a0 vldr s15, [r3, #20]
 *   @0x1a22a4 vcvt.f32.s32 s15, s15, #1
 *   @0x1a22a8 vdiv.f32 s15, s15, s16
 *   @0x1a22ac vcvt.f64.f32 d4, s15
 *   @0x1a22b0 vmov r0, r1, d4
 *   @0x1a22b4 bl 0xb66e8 <lrint@plt>
 *   @0x1a22b8 ldr r3, [r6]
 *   @0x1a22bc vcvt.f64.f32 d7, s16
 *   @0x1a22c0 ldr r3, [r3, #0x14]
 *   @0x1a22c4 vmov s12, r3
 *   @0x1a22c8 vcvt.f64.s32 d6, d6, #1
 *   @0x1a22cc vdiv.f64 d5, d6, d7
 *   @0x1a22d0 mov r5, r0
 *   @0x1a22d4 vmov r0, r1, d5
 *   @0x1a22d8 bl 0xb66e8 <lrint@plt>
 *   @0x1a22dc mov r1, r5
 *   @0x1a22e0 mov r2, r0
 *   @0x1a22e4 mov r0, r10
 *   @0x1a22e8 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a22ec cmp r9, #0
 *   @0x1a22f0 bne 0x1a2374 <_Z12Eff_Effect11iffij+0x1bc>
 *   @0x1a22f4 mov r0, #0
 *   @0x1a22f8 mov r1, #0
 *   @0x1a22fc movt r1, #0x3ff0
 *   @0x1a2300 bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a2304 vldr d5, [pc, #388]
 *   @0x1a2308 ldr r3, [r6]
 *   @0x1a230c vldr s12, [r3, #16]
 *   @0x1a2310 vcvt.f64.s32 d6, s12
 *   @0x1a2314 vldr d7, [pc, #380]
 *   @0x1a2318 vmov d4, r0, r1
 *   @0x1a231c mov r0, #0
 *   @0x1a2320 mov r1, #0
 *   @0x1a2324 movt r1, #0x4034
 *   @0x1a2328 vmul.f64 d5, d4, d5
 *   @0x1a232c vnmls.f64 d7, d5, d6
 *   @0x1a2330 vcvt.f32.f64 s16, d7
 *   @0x1a2334 bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a2338 ldr r3, [r4]
 *   @0x1a233c mov r2, #1
 *   @0x1a2340 str r8, [sp]
 *   @0x1a2344 str r2, [sp, #0x4]
 *   @0x1a2348 vmov.f64 d6, #3.000000e+01
 *   @0x1a234c vmov d5, r0, r1
 *   @0x1a2350 mov r0, r7
 *   @0x1a2354 vsub.f64 d6, d5, d6
 *   @0x1a2358 vmov r1, s16
 *   @0x1a235c vcvt.f32.f64 s11, d6
 *   @0x1a2360 vmov r2, s11
 *   @0x1a2364 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a2368 add sp, sp, #8
 *   @0x1a236c vpop {d8, d9, d10, d11}
 *   @0x1a2370 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1a2374 cmp r9, #2
 *   @0x1a2378 vmov.f64 d10, #3.000000e+01
 *   @0x1a237c beq 0x1a2408 <_Z12Eff_Effect11iffij+0x250>
 *   @0x1a2380 mov r5, #3
 *   @0x1a2384 mov r9, #1
 *   @0x1a2388 vldr d9, [pc, #256]
 *   @0x1a238c vldr d8, [pc, #260]
 *   @0x1a2390 mov r0, #0
 *   @0x1a2394 mov r1, #0
 *   @0x1a2398 movt r1, #0x3ff0
 *   @0x1a239c bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a23a0 ldr r3, [r6]
 *   @0x1a23a4 vldr s14, [r3, #16]
 *   @0x1a23a8 vcvt.f64.s32 d7, s14
 *   @0x1a23ac vmov.f64 d5, d8
 *   @0x1a23b0 vmov d4, r0, r1
 *   @0x1a23b4 mov r0, #0
 *   @0x1a23b8 mov r1, #0
 *   @0x1a23bc movt r1, #0x4034
 *   @0x1a23c0 vmul.f64 d6, d4, d9
 *   @0x1a23c4 vnmls.f64 d5, d6, d7
 *   @0x1a23c8 vcvt.f32.f64 s22, d5
 *   @0x1a23cc bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a23d0 ldr r3, [r4]
 *   @0x1a23d4 stm sp, {r8, r9}
 *   @0x1a23d8 vmov d6, r0, r1
 *   @0x1a23dc mov r0, r7
 *   @0x1a23e0 vsub.f64 d7, d6, d10
 *   @0x1a23e4 vmov r1, s22
 *   @0x1a23e8 vcvt.f32.f64 s13, d7
 *   @0x1a23ec vmov r2, s13
 *   @0x1a23f0 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a23f4 subs r5, r5, #1
 *   @0x1a23f8 bne 0x1a2390 <_Z12Eff_Effect11iffij+0x1d8>
 *   @0x1a23fc add sp, sp, #8
 *   @0x1a2400 vpop {d8, d9, d10, d11}
 *   @0x1a2404 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1a2408 mov r5, #7
 *   @0x1a240c mov r9, #1
 *   @0x1a2410 vldr d9, [pc, #120]
 *   @0x1a2414 vldr d8, [pc, #124]
 *   @0x1a2418 mov r0, #0
 *   @0x1a241c mov r1, #0
 *   @0x1a2420 movt r1, #0x3ff0
 *   @0x1a2424 bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a2428 ldr r3, [r6]
 *   @0x1a242c vldr s14, [r3, #16]
 *   @0x1a2430 vcvt.f64.s32 d7, s14
 *   @0x1a2434 vmov.f64 d5, d8
 *   @0x1a2438 vmov d4, r0, r1
 *   @0x1a243c mov r0, #0
 *   @0x1a2440 mov r1, #0
 *   @0x1a2444 movt r1, #0x4034
 *   @0x1a2448 vmul.f64 d6, d4, d9
 *   @0x1a244c vnmls.f64 d5, d6, d7
 *   @0x1a2450 vcvt.f32.f64 s22, d5
 *   @0x1a2454 bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a2458 ldr r3, [r4]
 *   @0x1a245c stm sp, {r8, r9}
 *   @0x1a2460 vmov d6, r0, r1
 *   @0x1a2464 mov r0, r7
 *   @0x1a2468 vsub.f64 d7, d6, d10
 *   @0x1a246c vmov r1, s22
 *   @0x1a2470 vcvt.f32.f64 s13, d7
 *   @0x1a2474 vmov r2, s13
 *   @0x1a2478 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a247c subs r5, r5, #1
 *   @0x1a2480 bne 0x1a2418 <_Z12Eff_Effect11iffij+0x260>
 *   @0x1a2484 add sp, sp, #8
 *   @0x1a2488 vpop {d8, d9, d10, d11}
 *   @0x1a248c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1a2490 andmi r0, r0, r0
 *   @0x1a2494 svclo #0xf33333
 *   @0x1a2498 andeq r0, r0, r0
 *   @0x1a249c submi r0, lr, r0
 *   @0x1a24a0 .word 0x0024e5b8
 *   @0x1a24a4 mlaeq r4, r4, r6, r11
 *
 * ══ §3/42 CLayerManager::Close()  0x1b7700  size 752  188 条（0x1b7700..0x1b79f0）
 * @func 0x1b7700 0x1b79f0  size 752  188 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1b7708→0x5425ed, 0x1b7720→0x5426a0, 0x1b7804→0x54268c, 0x1b782c→0x542678, 0x1b7854→0x542664, 0x1b791c→0x542650, 0x1b7944→0x54263c, 0x1b796c→0x5425fc
 * 调用序列: MemoryManager::Free(void const*)×12 / operator delete(void*)×2 / MemoryInWad(void*)
 * 字段偏移 top8: 0x14×9 / 0x704×5 / 0x1c×3 / 0x2bc×2 / 0x58×2 / 0x24×2 / 0x2a8×1 / 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b7700 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1b7704 ldr r6, [pc, #0x2bc]
 *   @0x1b7708 ldr r3, [pc, #0x2bc]
 *   @0x1b770c add r6, pc, r6
 *   @0x1b7710 ldr r7, [r6, r3]
 *   @0x1b7714 ldrb r3, [r7]
 *   @0x1b7718 cmp r3, #0
 *   @0x1b771c popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1b7720 ldr r3, [pc, #0x2a8]
 *   @0x1b7724 ldr r3, [r6, r3]
 *   @0x1b7728 ldr r5, [r3]
 *   @0x1b772c cmp r5, #0
 *   @0x1b7730 movne r8, #0
 *   @0x1b7734 beq 0x1b7804 <_ZN13CLayerManager5CloseEv+0x104>
 *   @0x1b7738 ldr r0, [r5, #0x1c]
 *   @0x1b773c ldr r9, [r5, #0x68]
 *   @0x1b7740 bl 0x1aad50 <_Z11MemoryInWadPv>
 *   @0x1b7744 cmp r0, #0
 *   @0x1b7748 bne 0x1b7754 <_ZN13CLayerManager5CloseEv+0x54>
 *   @0x1b774c ldr r0, [r5, #0x1c]
 *   @0x1b7750 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b7754 ldr r3, [r5, #0x64]
 *   @0x1b7758 str r8, [r5, #0x1c]
 *   @0x1b775c cmp r3, #0
 *   @0x1b7760 beq 0x1b7798 <_ZN13CLayerManager5CloseEv+0x98>
 *   @0x1b7764 ldr r0, [r5, #0x58]
 *   @0x1b7768 cmp r0, #0
 *   @0x1b776c beq 0x1b7798 <_ZN13CLayerManager5CloseEv+0x98>
 *   @0x1b7770 cmp r3, #2
 *   @0x1b7774 beq 0x1b77bc <_ZN13CLayerManager5CloseEv+0xbc>
 *   @0x1b7778 cmp r3, #3
 *   @0x1b777c beq 0x1b77d4 <_ZN13CLayerManager5CloseEv+0xd4>
 *   @0x1b7780 cmp r3, #1
 *   @0x1b7784 beq 0x1b77ec <_ZN13CLayerManager5CloseEv+0xec>
 *   @0x1b7788 ldr r4, [r0, #0x14]
 *   @0x1b778c cmp r4, #0
 *   @0x1b7790 mov r0, r4
 *   @0x1b7794 bne 0x1b7788 <_ZN13CLayerManager5CloseEv+0x88>
 *   @0x1b7798 str r8, [r5, #0x60]
 *   @0x1b779c mov r0, r5
 *   @0x1b77a0 str r8, [r5, #0x5c]
 *   @0x1b77a4 str r8, [r5, #0x58]
 *   @0x1b77a8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b77ac cmp r9, #0
 *   @0x1b77b0 beq 0x1b7804 <_ZN13CLayerManager5CloseEv+0x104>
 *   @0x1b77b4 mov r5, r9
 *   @0x1b77b8 b 0x1b7738 <_ZN13CLayerManager5CloseEv+0x38>
 *   @0x1b77bc ldr r4, [r0, #0x14]
 *   @0x1b77c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b77c4 cmp r4, #0
 *   @0x1b77c8 mov r0, r4
 *   @0x1b77cc bne 0x1b77bc <_ZN13CLayerManager5CloseEv+0xbc>
 *   @0x1b77d0 b 0x1b7798 <_ZN13CLayerManager5CloseEv+0x98>
 *   @0x1b77d4 ldr r4, [r0, #0x14]
 *   @0x1b77d8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b77dc cmp r4, #0
 *   @0x1b77e0 mov r0, r4
 *   @0x1b77e4 bne 0x1b77d4 <_ZN13CLayerManager5CloseEv+0xd4>
 *   @0x1b77e8 b 0x1b7798 <_ZN13CLayerManager5CloseEv+0x98>
 *   @0x1b77ec ldr r4, [r0, #0x14]
 *   @0x1b77f0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1b77f4 cmp r4, #0
 *   @0x1b77f8 mov r0, r4
 *   @0x1b77fc bne 0x1b77ec <_ZN13CLayerManager5CloseEv+0xec>
 *   @0x1b7800 b 0x1b7798 <_ZN13CLayerManager5CloseEv+0x98>
 *   @0x1b7804 ldr r3, [pc, #0x1c8]
 *   @0x1b7808 ldr r3, [r6, r3]
 *   @0x1b780c ldr r0, [r3]
 *   @0x1b7810 cmp r0, #0
 *   @0x1b7814 beq 0x1b782c <_ZN13CLayerManager5CloseEv+0x12c>
 *   @0x1b7818 ldr r4, [r0, #0x14]
 *   @0x1b781c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b7820 cmp r4, #0
 *   @0x1b7824 mov r0, r4
 *   @0x1b7828 bne 0x1b7818 <_ZN13CLayerManager5CloseEv+0x118>
 *   @0x1b782c ldr r3, [pc, #0x1a4]
 *   @0x1b7830 ldr r3, [r6, r3]
 *   @0x1b7834 ldr r0, [r3]
 *   @0x1b7838 cmp r0, #0
 *   @0x1b783c beq 0x1b7854 <_ZN13CLayerManager5CloseEv+0x154>
 *   @0x1b7840 ldr r4, [r0, #0x14]
 *   @0x1b7844 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b7848 cmp r4, #0
 *   @0x1b784c mov r0, r4
 *   @0x1b7850 bne 0x1b7840 <_ZN13CLayerManager5CloseEv+0x140>
 *   @0x1b7854 ldr r3, [pc, #0x180]
 *   @0x1b7858 ldr r3, [r6, r3]
 *   @0x1b785c ldr r5, [r3]
 *   @0x1b7860 cmp r5, #0
 *   @0x1b7864 movne r8, #0
 *   @0x1b7868 beq 0x1b791c <_ZN13CLayerManager5CloseEv+0x21c>
 *   @0x1b786c ldr r3, [r5, #0x30]
 *   @0x1b7870 ldr r9, [r5, #0x14]
 *   @0x1b7874 cmp r3, #0
 *   @0x1b7878 beq 0x1b78b0 <_ZN13CLayerManager5CloseEv+0x1b0>
 *   @0x1b787c ldr r0, [r5, #0x24]
 *   @0x1b7880 cmp r0, #0
 *   @0x1b7884 beq 0x1b78b0 <_ZN13CLayerManager5CloseEv+0x1b0>
 *   @0x1b7888 cmp r3, #2
 *   @0x1b788c beq 0x1b78d4 <_ZN13CLayerManager5CloseEv+0x1d4>
 *   @0x1b7890 cmp r3, #3
 *   @0x1b7894 beq 0x1b78ec <_ZN13CLayerManager5CloseEv+0x1ec>
 *   @0x1b7898 cmp r3, #1
 *   @0x1b789c beq 0x1b7904 <_ZN13CLayerManager5CloseEv+0x204>
 *   @0x1b78a0 ldr r4, [r0, #0x704]
 *   @0x1b78a4 cmp r4, #0
 *   @0x1b78a8 mov r0, r4
 *   @0x1b78ac bne 0x1b78a0 <_ZN13CLayerManager5CloseEv+0x1a0>
 *   @0x1b78b0 str r8, [r5, #0x2c]
 *   @0x1b78b4 mov r0, r5
 *   @0x1b78b8 str r8, [r5, #0x28]
 *   @0x1b78bc str r8, [r5, #0x24]
 *   @0x1b78c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b78c4 cmp r9, #0
 *   @0x1b78c8 beq 0x1b791c <_ZN13CLayerManager5CloseEv+0x21c>
 *   @0x1b78cc mov r5, r9
 *   @0x1b78d0 b 0x1b786c <_ZN13CLayerManager5CloseEv+0x16c>
 *   @0x1b78d4 ldr r4, [r0, #0x704]
 *   @0x1b78d8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b78dc cmp r4, #0
 *   @0x1b78e0 mov r0, r4
 *   @0x1b78e4 bne 0x1b78d4 <_ZN13CLayerManager5CloseEv+0x1d4>
 *   @0x1b78e8 b 0x1b78b0 <_ZN13CLayerManager5CloseEv+0x1b0>
 *   @0x1b78ec ldr r4, [r0, #0x704]
 *   @0x1b78f0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b78f4 cmp r4, #0
 *   @0x1b78f8 mov r0, r4
 *   @0x1b78fc bne 0x1b78ec <_ZN13CLayerManager5CloseEv+0x1ec>
 *   @0x1b7900 b 0x1b78b0 <_ZN13CLayerManager5CloseEv+0x1b0>
 *   @0x1b7904 ldr r4, [r0, #0x704]
 *   @0x1b7908 bl 0x27d1d0 <_ZdlPv>
 *   @0x1b790c cmp r4, #0
 *   @0x1b7910 mov r0, r4
 *   @0x1b7914 bne 0x1b7904 <_ZN13CLayerManager5CloseEv+0x204>
 *   @0x1b7918 b 0x1b78b0 <_ZN13CLayerManager5CloseEv+0x1b0>
 *   @0x1b791c ldr r3, [pc, #0xbc]
 *   @0x1b7920 ldr r3, [r6, r3]
 *   @0x1b7924 ldr r0, [r3]
 *   @0x1b7928 cmp r0, #0
 *   @0x1b792c beq 0x1b7944 <_ZN13CLayerManager5CloseEv+0x244>
 *   @0x1b7930 ldr r4, [r0, #0x14]
 *   @0x1b7934 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b7938 cmp r4, #0
 *   @0x1b793c mov r0, r4
 *   @0x1b7940 bne 0x1b7930 <_ZN13CLayerManager5CloseEv+0x230>
 *   @0x1b7944 ldr r3, [pc, #0x98]
 *   @0x1b7948 ldr r3, [r6, r3]
 *   @0x1b794c ldr r0, [r3]
 *   @0x1b7950 cmp r0, #0
 *   @0x1b7954 beq 0x1b796c <_ZN13CLayerManager5CloseEv+0x26c>
 *   @0x1b7958 ldr r4, [r0, #0x14]
 *   @0x1b795c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b7960 cmp r4, #0
 *   @0x1b7964 mov r0, r4
 *   @0x1b7968 bne 0x1b7958 <_ZN13CLayerManager5CloseEv+0x258>
 *   @0x1b796c ldr r3, [pc, #0x74]
 *   @0x1b7970 ldr r3, [r6, r3]
 *   @0x1b7974 ldr r0, [r3]
 *   @0x1b7978 cmp r0, #0
 *   @0x1b797c beq 0x1b7994 <_ZN13CLayerManager5CloseEv+0x294>
 *   @0x1b7980 ldr r4, [r0, #0x704]
 *   @0x1b7984 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b7988 cmp r4, #0
 *   @0x1b798c mov r0, r4
 *   @0x1b7990 bne 0x1b7980 <_ZN13CLayerManager5CloseEv+0x280>
 *   @0x1b7994 ldr r3, [pc, #0x50]
 *   @0x1b7998 ldr r4, [r6, r3]
 *   @0x1b799c ldr r0, [r4]
 *   @0x1b79a0 cmp r0, #0
 *   @0x1b79a4 beq 0x1b79bc <_ZN13CLayerManager5CloseEv+0x2bc>
 *   @0x1b79a8 ldr r3, [r0]
 *   @0x1b79ac ldr r3, [r3, #0x4]
 *   @0x1b79b0 blx r3
 *   @0x1b79b4 mov r3, #0
 *   @0x1b79b8 str r3, [r4]
 *   @0x1b79bc mov r3, #0
 *   @0x1b79c0 strb r3, [r7]
 *   @0x1b79c4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1b79c8 eoreq r10, r3, r4, asr #10
 *   @0x1b79cc .word 0xffffec08
 *   @0x1b79d0 .word 0xffffec0c
 *   @0x1b79d4 .word 0xffffec10
 *   @0x1b79d8 .word 0xffffec14
 *   @0x1b79dc .word 0xffffec18
 *   @0x1b79e0 .word 0xffffec1c
 *   @0x1b79e4 .word 0xffffec20
 *   @0x1b79e8 .word 0xffffec2c
 *   @0x1b79ec .word 0xffffc020
 *
 * ══ §4/42 CSprite::LoadFromStream(CStream*)  0x1e7854  size 752  188 条（0x1e7854..0x1e7b44）
 * @func 0x1e7854 0x1e7b44  size 752  188 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger()×14 / CStream::ReadBoolean()×5 / MemoryManager::SetLength(void**, unsigned int, char const*, int)×4 / operator new(unsigned int)×2 / CBitmap32::CBitmap32(CStream*)×2 / CSprite::LoadFromStream(CStream*)+0x174×2 / CSprite::LoadMaskFromStream(int, CStream*)×2 / CSprite::Clear()
 * 字段偏移 top8: 0x18×9 / 0x48×6 / 0x4×3 / 0x24×2 / 0x28×2 / 0x2×2 / 0x1c×2 / 0x20×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e7854 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1e7858 mov r6, r1
 *   @0x1e785c mov r4, r0
 *   @0x1e7860 bl 0x1e6b4c <_ZN7CSprite5ClearEv>
 *   @0x1e7864 mov r0, r6
 *   @0x1e7868 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e786c movw r3, #0x21e
 *   @0x1e7870 cmp r0, r3
 *   @0x1e7874 mov r8, r0
 *   @0x1e7878 beq 0x1e79d4 <_ZN7CSprite14LoadFromStreamEP7CStream+0x180>
 *   @0x1e787c cmp r0, #800
 *   @0x1e7880 beq 0x1e789c <_ZN7CSprite14LoadFromStreamEP7CStream+0x48>
 *   @0x1e7884 movw r0, #0x21e
 *   @0x1e7888 cmp r8, r0
 *   @0x1e788c cmpne r8, #800
 *   @0x1e7890 movne r0, #0
 *   @0x1e7894 moveq r0, #1
 *   @0x1e7898 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1e789c mov r0, r6
 *   @0x1e78a0 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e78a4 str r0, [r4, #0x24]
 *   @0x1e78a8 mov r0, r6
 *   @0x1e78ac bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e78b0 str r0, [r4, #0x28]
 *   @0x1e78b4 mov r0, r6
 *   @0x1e78b8 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e78bc ldr r2, [pc, #0x270]
 *   @0x1e78c0 movw r3, #0xb18
 *   @0x1e78c4 add r2, pc, r2
 *   @0x1e78c8 lsl r1, r0, #2
 *   @0x1e78cc str r0, [r4, #0x18]
 *   @0x1e78d0 add r0, r4, #72
 *   @0x1e78d4 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e78d8 ldr r3, [r4, #0x18]
 *   @0x1e78dc cmp r3, #0
 *   @0x1e78e0 movgt r5, #0
 *   @0x1e78e4 ble 0x1e7958 <_ZN7CSprite14LoadFromStreamEP7CStream+0x104>
 *   @0x1e78e8 ldr r3, [r4, #0x48]
 *   @0x1e78ec lsl r7, r5, #2
 *   @0x1e78f0 ldr r3, [r3, r5, lsl #2]
 *   @0x1e78f4 add r5, r5, #1
 *   @0x1e78f8 cmp r3, #0
 *   @0x1e78fc mov r0, r3
 *   @0x1e7900 beq 0x1e7910 <_ZN7CSprite14LoadFromStreamEP7CStream+0xbc>
 *   @0x1e7904 ldr r3, [r3]
 *   @0x1e7908 ldr r3, [r3, #0x4]
 *   @0x1e790c blx r3
 *   @0x1e7910 mov r0, #24
 *   @0x1e7914 bl 0x27c524 <_Znwj>
 *   @0x1e7918 mov r1, r6
 *   @0x1e791c mov r9, r0
 *   @0x1e7920 bl 0x165e2c <_ZN9CBitmap32C2EP7CStream>
 *   @0x1e7924 ldr r3, [r4, #0x48]
 *   @0x1e7928 str r9, [r3, r7]
 *   @0x1e792c ldr r3, [r4, #0x48]
 *   @0x1e7930 ldr r0, [r3, r7]
 *   @0x1e7934 bl 0x167960 <_ZN9CBitmap328GetWidthEv>
 *   @0x1e7938 ldr r3, [r4, #0x48]
 *   @0x1e793c str r0, [r4, #0x1c]
 *   @0x1e7940 ldr r0, [r3, r7]
 *   @0x1e7944 bl 0x167968 <_ZN9CBitmap329GetHeightEv>
 *   @0x1e7948 ldr r3, [r4, #0x18]
 *   @0x1e794c cmp r3, r5
 *   @0x1e7950 str r0, [r4, #0x20]
 *   @0x1e7954 bgt 0x1e78e8 <_ZN7CSprite14LoadFromStreamEP7CStream+0x94>
 *   @0x1e7958 mov r0, r6
 *   @0x1e795c bl 0x2019b0 <_ZN7CStream11ReadBooleanEv>
 *   @0x1e7960 ldr r1, [r4, #0x18]
 *   @0x1e7964 cmp r1, #0
 *   @0x1e7968 mov r5, r0
 *   @0x1e796c strb r0, [r4, #0x35]
 *   @0x1e7970 ble 0x1e79c8 <_ZN7CSprite14LoadFromStreamEP7CStream+0x174>
 *   @0x1e7974 cmp r0, #0
 *   @0x1e7978 beq 0x1e7b00 <_ZN7CSprite14LoadFromStreamEP7CStream+0x2ac>
 *   @0x1e797c ldr r2, [pc, #0x1b4]
 *   @0x1e7980 movw r3, #0xb27
 *   @0x1e7984 lsl r1, r1, #3
 *   @0x1e7988 add r0, r4, #64
 *   @0x1e798c add r2, pc, r2
 *   @0x1e7990 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e7994 ldr r3, [r4, #0x18]
 *   @0x1e7998 cmp r3, #0
 *   @0x1e799c str r3, [r4, #0x3c]
 *   @0x1e79a0 ble 0x1e79c8 <_ZN7CSprite14LoadFromStreamEP7CStream+0x174>
 *   @0x1e79a4 mov r5, #0
 *   @0x1e79a8 mov r1, r5
 *   @0x1e79ac mov r0, r4
 *   @0x1e79b0 mov r2, r6
 *   @0x1e79b4 add r5, r5, #1
 *   @0x1e79b8 bl 0x1e64cc <_ZN7CSprite18LoadMaskFromStreamEiP7CStream>
 *   @0x1e79bc ldr r3, [r4, #0x18]
 *   @0x1e79c0 cmp r3, r5
 *   @0x1e79c4 bgt 0x1e79a8 <_ZN7CSprite14LoadFromStreamEP7CStream+0x154>
 *   @0x1e79c8 mov r0, r4
 *   @0x1e79cc bl 0x1e3320 <_ZN7CSprite18ComputeBoundingBoxEv>
 *   @0x1e79d0 b 0x1e7884 <_ZN7CSprite14LoadFromStreamEP7CStream+0x30>
 *   @0x1e79d4 mov r0, r6
 *   @0x1e79d8 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e79dc str r0, [r4, #0x1c]
 *   @0x1e79e0 mov r0, r6
 *   @0x1e79e4 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e79e8 str r0, [r4, #0x20]
 *   @0x1e79ec mov r0, r6
 *   @0x1e79f0 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e79f4 str r0, [r4, #0x8]
 *   @0x1e79f8 mov r0, r6
 *   @0x1e79fc bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e7a00 str r0, [r4, #0x10]
 *   @0x1e7a04 mov r0, r6
 *   @0x1e7a08 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e7a0c str r0, [r4, #0x14]
 *   @0x1e7a10 mov r0, r6
 *   @0x1e7a14 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e7a18 str r0, [r4, #0xc]
 *   @0x1e7a1c mov r0, r6
 *   @0x1e7a20 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv>
 *   @0x1e7a24 strb r0, [r4, #0x32]
 *   @0x1e7a28 mov r0, r6
 *   @0x1e7a2c bl 0x2019b0 <_ZN7CStream11ReadBooleanEv>
 *   @0x1e7a30 strb r0, [r4, #0x33]
 *   @0x1e7a34 mov r0, r6
 *   @0x1e7a38 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv>
 *   @0x1e7a3c strb r0, [r4, #0x34]
 *   @0x1e7a40 mov r0, r6
 *   @0x1e7a44 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e7a48 str r0, [r4, #0x4]
 *   @0x1e7a4c mov r0, r6
 *   @0x1e7a50 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv>
 *   @0x1e7a54 strb r0, [r4, #0x30]
 *   @0x1e7a58 mov r0, r6
 *   @0x1e7a5c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e7a60 str r0, [r4, #0x24]
 *   @0x1e7a64 mov r0, r6
 *   @0x1e7a68 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e7a6c str r0, [r4, #0x28]
 *   @0x1e7a70 mov r0, r6
 *   @0x1e7a74 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e7a78 ldr r2, [pc, #0xbc]
 *   @0x1e7a7c movw r3, #0xb04
 *   @0x1e7a80 add r2, pc, r2
 *   @0x1e7a84 lsl r1, r0, #2
 *   @0x1e7a88 str r0, [r4, #0x18]
 *   @0x1e7a8c add r0, r4, #72
 *   @0x1e7a90 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e7a94 ldr r3, [r4, #0x18]
 *   @0x1e7a98 cmp r3, #0
 *   @0x1e7a9c movgt r5, #0
 *   @0x1e7aa0 ble 0x1e7af4 <_ZN7CSprite14LoadFromStreamEP7CStream+0x2a0>
 *   @0x1e7aa4 ldr r3, [r4, #0x48]
 *   @0x1e7aa8 lsl r7, r5, #2
 *   @0x1e7aac ldr r3, [r3, r5, lsl #2]
 *   @0x1e7ab0 add r5, r5, #1
 *   @0x1e7ab4 cmp r3, #0
 *   @0x1e7ab8 mov r0, r3
 *   @0x1e7abc beq 0x1e7acc <_ZN7CSprite14LoadFromStreamEP7CStream+0x278>
 *   @0x1e7ac0 ldr r3, [r3]
 *   @0x1e7ac4 ldr r3, [r3, #0x4]
 *   @0x1e7ac8 blx r3
 *   @0x1e7acc mov r0, #24
 *   @0x1e7ad0 bl 0x27c524 <_Znwj>
 *   @0x1e7ad4 mov r1, r6
 *   @0x1e7ad8 mov r9, r0
 *   @0x1e7adc bl 0x165e2c <_ZN9CBitmap32C2EP7CStream>
 *   @0x1e7ae0 ldr r2, [r4, #0x18]
 *   @0x1e7ae4 ldr r3, [r4, #0x48]
 *   @0x1e7ae8 cmp r2, r5
 *   @0x1e7aec str r9, [r3, r7]
 *   @0x1e7af0 bgt 0x1e7aa4 <_ZN7CSprite14LoadFromStreamEP7CStream+0x250>
 *   @0x1e7af4 mov r0, r4
 *   @0x1e7af8 bl 0x1e3bcc <_ZN7CSprite10CreateMaskEv>
 *   @0x1e7afc b 0x1e7884 <_ZN7CSprite14LoadFromStreamEP7CStream+0x30>
 *   @0x1e7b00 ldr r2, [pc, #0x38]
 *   @0x1e7b04 add r0, r4, #64
 *   @0x1e7b08 mov r1, #8
 *   @0x1e7b0c mov r3, #2864
 *   @0x1e7b10 add r2, pc, r2
 *   @0x1e7b14 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e7b18 mov r3, #1
 *   @0x1e7b1c mov r1, r5
 *   @0x1e7b20 mov r2, r6
 *   @0x1e7b24 mov r0, r4
 *   @0x1e7b28 str r3, [r4, #0x3c]
 *   @0x1e7b2c bl 0x1e64cc <_ZN7CSprite18LoadMaskFromStreamEiP7CStream>
 *   @0x1e7b30 b 0x1e79c8 <_ZN7CSprite14LoadFromStreamEP7CStream+0x174>
 *   @0x1e7b34 andseq r10, r6, r0, ror #22
 *   @0x1e7b38 mulseq r6, r8, r10
 *   @0x1e7b3c andseq r10, r6, r4, lsr #19
 *   @0x1e7b40 andseq r10, r6, r4, lsl r9
 *
 * ══ §5/42 pcre_study  0x2665e0  size 752  188 条（0x2665e0..0x2668d0）
 * @func 0x2665e0 0x2668d0  size 752  188 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_25fe2c+0x5de4 / anon_25e350 / 0xb65b0 / pcre_fullinfo / 0xb65d4
 * 字段偏移 top8: 0x24×3 / 0x8×3 / 0x30×3 / 0x20×3 / 0xc×2 / 0xc4×2 / 0x10×2 / 0xa4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2665e0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2665e4 mov r6, r2
 *   @0x2665e8 ldr r5, [pc, #0x2bc]
 *   @0x2665ec sub sp, sp, #200
 *   @0x2665f0 subs r4, r0, #0
 *   @0x2665f4 mov r3, #0
 *   @0x2665f8 ldr r5, [pc, r5]
 *   @0x2665fc mov r7, r1
 *   @0x266600 str r3, [sp, #0xc]
 *   @0x266604 ldr r2, [r5]
 *   @0x266608 str r3, [r6]
 *   @0x26660c str r2, [sp, #0xc4]
 *   @0x266610 beq 0x266744 <pcre_study+0x164>
 *   @0x266614 ldr r2, [r4]
 *   @0x266618 movw r12, #0x5245
 *   @0x26661c movt r12, #0x5043
 *   @0x266620 cmp r2, r12
 *   @0x266624 bne 0x266744 <pcre_study+0x164>
 *   @0x266628 ldr r12, [r4, #0xc]
 *   @0x26662c ands r2, r12, #1
 *   @0x266630 beq 0x26682c <pcre_study+0x24c>
 *   @0x266634 bics r8, r1, #15
 *   @0x266638 bne 0x266840 <pcre_study+0x260>
 *   @0x26663c ldrh r1, [r4, #38]
 *   @0x266640 ldrh r10, [r4, #36]
 *   @0x266644 ldrh r2, [r4, #34]
 *   @0x266648 ldr r3, [r4, #0x8]
 *   @0x26664c mla r10, r10, r1, r2
 *   @0x266650 ands r9, r3, #16
 *   @0x266654 add r10, r4, r10
 *   @0x266658 bne 0x266824 <pcre_study+0x244>
 *   @0x26665c tst r12, #272
 *   @0x266660 bne 0x2666e8 <pcre_study+0x108>
 *   @0x266664 ldr r1, [r4, #0x30]
 *   @0x266668 cmp r1, #0
 *   @0x26666c str r1, [sp, #0x10]
 *   @0x266670 movne r2, r3
 *   @0x266674 movne r12, r1
 *   @0x266678 beq 0x266868 <pcre_study+0x288>
 *   @0x26667c add r3, sp, #20
 *   @0x266680 ubfx r2, r2, #0xb, #0x1
 *   @0x266684 mov r0, r10
 *   @0x266688 add r1, sp, #164
 *   @0x26668c add r8, r12, #256
 *   @0x266690 add lr, r12, #512
 *   @0x266694 str r12, [sp, #0x14]
 *   @0x266698 add r12, r12, #832
 *   @0x26669c str r8, [sp, #0x18]
 *   @0x2666a0 mov r8, #0
 *   @0x2666a4 str lr, [sp, #0x1c]
 *   @0x2666a8 str r12, [sp, #0x20]
 *   @0x2666ac str r8, [sp, #0xa4]
 *   @0x2666b0 str r8, [sp, #0xa8]
 *   @0x2666b4 str r8, [sp, #0xac]
 *   @0x2666b8 str r8, [sp, #0xb0]
 *   @0x2666bc str r8, [sp, #0xb4]
 *   @0x2666c0 str r8, [sp, #0xb8]
 *   @0x2666c4 str r8, [sp, #0xbc]
 *   @0x2666c8 str r8, [sp, #0xc0]
 *   @0x2666cc bl 0x265c10 <_pcre_ord2utf+0x5e78>
 *   @0x2666d0 subs r3, r0, #1
 *   @0x2666d4 rsbs r9, r3, #0
 *   @0x2666d8 adcs r9, r9, r3
 *   @0x2666dc cmp r0, #3
 *   @0x2666e0 beq 0x266880 <pcre_study+0x2a0>
 *   @0x2666e4 ldr r3, [r4, #0x8]
 *   @0x2666e8 mov r0, r4
 *   @0x2666ec add r12, sp, #12
 *   @0x2666f0 mov r1, r10
 *   @0x2666f4 mov r2, r10
 *   @0x2666f8 mov r8, #0
 *   @0x2666fc str r12, [sp, #0x4]
 *   @0x266700 str r8, [sp]
 *   @0x266704 bl 0x25e350 <_pcre_find_bracket+0x254>
 *   @0x266708 cmn r0, #3
 *   @0x26670c mov r4, r0
 *   @0x266710 beq 0x266810 <pcre_study+0x230>
 *   @0x266714 cmn r0, #2
 *   @0x266718 bne 0x266758 <pcre_study+0x178>
 *   @0x26671c ldr r3, [pc, #0x18c]
 *   @0x266720 mov r0, r8
 *   @0x266724 add r3, pc, r3
 *   @0x266728 str r3, [r6]
 *   @0x26672c ldr r2, [sp, #0xc4]
 *   @0x266730 ldr r3, [r5]
 *   @0x266734 cmp r2, r3
 *   @0x266738 bne 0x2668a8 <pcre_study+0x2c8>
 *   @0x26673c add sp, sp, #200
 *   @0x266740 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x266744 ldr r3, [pc, #0x168]
 *   @0x266748 mov r0, #0
 *   @0x26674c add r3, pc, r3
 *   @0x266750 str r3, [r6]
 *   @0x266754 b 0x26672c <pcre_study+0x14c>
 *   @0x266758 cmp r0, #0
 *   @0x26675c and r3, r9, #1
 *   @0x266760 movle r8, #0
 *   @0x266764 movgt r8, #1
 *   @0x266768 orrs r3, r8, r3
 *   @0x26676c bne 0x266778 <pcre_study+0x198>
 *   @0x266770 ands r0, r7, #8
 *   @0x266774 beq 0x26672c <pcre_study+0x14c>
 *   @0x266778 ldr r3, [pc, #0x138]
 *   @0x26677c mov r0, #76
 *   @0x266780 ldr r3, [pc, r3]
 *   @0x266784 ldr r3, [r3]
 *   @0x266788 blx r3
 *   @0x26678c subs r7, r0, #0
 *   @0x266790 beq 0x266894 <pcre_study+0x2b4>
 *   @0x266794 cmp r9, #0
 *   @0x266798 mov r3, r7
 *   @0x26679c mov r2, #1
 *   @0x2667a0 mov r0, #44
 *   @0x2667a4 str r2, [r3], #32
 *   @0x2667a8 mov r1, #0
 *   @0x2667ac str r3, [r7, #0x4]
 *   @0x2667b0 str r0, [r7, #0x20]
 *   @0x2667b4 str r1, [r7, #0x24]
 *   @0x2667b8 beq 0x266854 <pcre_study+0x274>
 *   @0x2667bc add r12, sp, #164
 *   @0x2667c0 str r2, [r7, #0x24]
 *   @0x2667c4 ldm r12!, {r0, r1, r2, r3}
 *   @0x2667c8 str r0, [r7, #0x28]
 *   @0x2667cc str r1, [r7, #0x2c]
 *   @0x2667d0 str r2, [r7, #0x30]
 *   @0x2667d4 str r3, [r7, #0x34]
 *   @0x2667d8 ldm r12!, {r0, r1, r2, r3}
 *   @0x2667dc str r0, [r7, #0x38]
 *   @0x2667e0 str r1, [r7, #0x3c]
 *   @0x2667e4 str r2, [r7, #0x40]
 *   @0x2667e8 str r3, [r7, #0x44]
 *   @0x2667ec cmp r8, #0
 *   @0x2667f0 strne r4, [r7, #0x48]
 *   @0x2667f4 streq r8, [r7, #0x48]
 *   @0x2667f8 ldrne r3, [r7, #0x24]
 *   @0x2667fc movne r0, r7
 *   @0x266800 moveq r0, r7
 *   @0x266804 orrne r3, r3, #2
 *   @0x266808 strne r3, [r7, #0x24]
 *   @0x26680c b 0x26672c <pcre_study+0x14c>
 *   @0x266810 ldr r3, [pc, #0xa4]
 *   @0x266814 mov r0, r8
 *   @0x266818 add r3, pc, r3
 *   @0x26681c str r3, [r6]
 *   @0x266820 b 0x26672c <pcre_study+0x14c>
 *   @0x266824 mov r9, r8
 *   @0x266828 b 0x2666e8 <pcre_study+0x108>
 *   @0x26682c ldr r3, [pc, #0x8c]
 *   @0x266830 mov r0, r2
 *   @0x266834 add r3, pc, r3
 *   @0x266838 str r3, [r6]
 *   @0x26683c b 0x26672c <pcre_study+0x14c>
 *   @0x266840 ldr r2, [pc, #0x7c]
 *   @0x266844 mov r0, r3
 *   @0x266848 add r2, pc, r2
 *   @0x26684c str r2, [r6]
 *   @0x266850 b 0x26672c <pcre_study+0x14c>
 *   @0x266854 mov r1, r9
 *   @0x266858 add r0, r7, #40
 *   @0x26685c mov r2, #32
 *   @0x266860 bl 0xb65b0 <memset@plt>
 *   @0x266864 b 0x2667ec <pcre_study+0x20c>
 *   @0x266868 mov r2, #11
 *   @0x26686c add r3, sp, #16
 *   @0x266870 bl 0x25ee20 <pcre_fullinfo>
 *   @0x266874 ldr r12, [sp, #0x10]
 *   @0x266878 ldr r2, [r4, #0x8]
 *   @0x26687c b 0x26667c <pcre_study+0x9c>
 *   @0x266880 ldr r3, [pc, #0x40]
 *   @0x266884 mov r0, r8
 *   @0x266888 add r3, pc, r3
 *   @0x26688c str r3, [r6]
 *   @0x266890 b 0x26672c <pcre_study+0x14c>
 *   @0x266894 ldr r3, [pc, #0x30]
 *   @0x266898 mov r0, r7
 *   @0x26689c add r3, pc, r3
 *   @0x2668a0 str r3, [r6]
 *   @0x2668a4 b 0x26672c <pcre_study+0x14c>
 *   @0x2668a8 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2668ac andseq r7, r8, r8, asr r3
 *   @0x2668b0 andeq r0, pc, r0, lsl #18
 *   @0x2668b4 andeq r0, pc, r4, lsr r8
 *   @0x2668b8 andseq r11, r8, r4, rrx
 *   @0x2668bc andeq r0, pc, r4, ror #15
 *   @0x2668c0 andeq r0, pc, r12, ror r7
 *   @0x2668c4 andeq r0, pc, r12, lsl #15
 *   @0x2668c8 andeq r0, pc, r4, ror r7
 *   @0x2668cc strheq r0, [pc], -r4
 *
 * ══ §6/42 yyServer::Init(eSocketType, int, int, bool)  0x2971e0  size 752  188 条（0x2971e0..0x2974d0）
 * @func 0x2971e0 0x2974d0  size 752  188 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x29725c→0x7578c4, 0x2972d0→0x3eb70c, 0x2973ec→0x3eb70c, 0x297444→0x3eb70c, 0x29748c→0x3eb788
 * 调用序列: operator new(unsigned int)×4 / 0xb65b0×4 / yyServer::Init(eSocketType, int, int, bool)+0x68 / yySocket::yySocket(eSocketType) / yySocket::Init() / yySocket::Create() / yySocket::Bind(sockaddr const*, int) / yyServer::Init(eSocketType, int, int, bool)+0x26c
 * 字段偏移 top8: 0x4×7 / 0x8×4 / 0x14×3 / 0xc×3 / 0x1e8×2 / 0xcc×2 / 0x2c0×1 / 0x2bc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2971e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2971e4 mov r4, r1
 *   @0x2971e8 ldr r7, [pc, #0x2c0]
 *   @0x2971ec sub r12, r4, #3
 *   @0x2971f0 ldr r1, [pc, #0x2bc]
 *   @0x2971f4 sub sp, sp, #28
 *   @0x2971f8 add r7, pc, r7
 *   @0x2971fc cmp r12, #1
 *   @0x297200 cmphi r4, #1
 *   @0x297204 mov r6, r0
 *   @0x297208 mov r10, r2
 *   @0x29720c ldr r8, [r7, r1]
 *   @0x297210 str r3, [r0, #0x24]
 *   @0x297214 ldrb r11, [sp, #0x40]
 *   @0x297218 ldr r3, [r8]
 *   @0x29721c str r4, [r0, #0x20]
 *   @0x297220 str r3, [sp, #0x14]
 *   @0x297224 bls 0x297248 <_ZN8yyServer4InitE11eSocketTypeiib+0x68>
 *   @0x297228 mvn r9, #0
 *   @0x29722c ldr r2, [sp, #0x14]
 *   @0x297230 mov r0, r9
 *   @0x297234 ldr r3, [r8]
 *   @0x297238 cmp r2, r3
 *   @0x29723c bne 0x2974ac <_ZN8yyServer4InitE11eSocketTypeiib+0x2cc>
 *   @0x297240 add sp, sp, #28
 *   @0x297244 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x297248 mov r0, #200
 *   @0x29724c bl 0x27c524 <_Znwj>
 *   @0x297250 mov r1, r4
 *   @0x297254 mov r9, r0
 *   @0x297258 bl 0x2970ac <_ZN8yySocketC2E11eSocketType>
 *   @0x29725c ldr r3, [pc, #0x254]
 *   @0x297260 mov r0, r9
 *   @0x297264 ldr r5, [r7, r3]
 *   @0x297268 str r9, [r5]
 *   @0x29726c bl 0x294ec8 <_ZN8yySocket4InitEv>
 *   @0x297270 cmp r11, #0
 *   @0x297274 ldrne r3, [r5]
 *   @0x297278 movne r2, #1
 *   @0x29727c ldreq r0, [r5]
 *   @0x297280 movne r0, r3
 *   @0x297284 strbne r2, [r3, #0x2c]
 *   @0x297288 bl 0x294f68 <_ZN8yySocket6CreateEv>
 *   @0x29728c ldr r0, [r5]
 *   @0x297290 ldr r9, [r0]
 *   @0x297294 cmn r9, #1
 *   @0x297298 beq 0x2973ec <_ZN8yyServer4InitE11eSocketTypeiib+0x20c>
 *   @0x29729c mov r2, #0
 *   @0x2972a0 mov r1, #2
 *   @0x2972a4 str r2, [sp, #0x8]
 *   @0x2972a8 mov r3, r10
 *   @0x2972ac str r2, [sp, #0xc]
 *   @0x2972b0 str r2, [sp, #0x10]
 *   @0x2972b4 strh r1, [sp, #4]
 *   @0x2972b8 rev16 r3, r3
 *   @0x2972bc mov r2, #16
 *   @0x2972c0 add r1, sp, #4
 *   @0x2972c4 strh r3, [sp, #6]
 *   @0x2972c8 bl 0x2951c4 <_ZN8yySocket4BindEPK8sockaddri>
 *   @0x2972cc ldr r1, [pc, #0x1e8]
 *   @0x2972d0 ldr r3, [pc, #0x1e8]
 *   @0x2972d4 add r1, pc, r1
 *   @0x2972d8 subs r9, r0, #0
 *   @0x2972dc blt 0x29744c <_ZN8yyServer4InitE11eSocketTypeiib+0x26c>
 *   @0x2972e0 cmp r4, #0
 *   @0x2972e4 cmpne r4, #3
 *   @0x2972e8 beq 0x29742c <_ZN8yyServer4InitE11eSocketTypeiib+0x24c>
 *   @0x2972ec cmp r4, #1
 *   @0x2972f0 cmpne r4, #4
 *   @0x2972f4 beq 0x297470 <_ZN8yyServer4InitE11eSocketTypeiib+0x290>
 *   @0x2972f8 ldr r3, [r5]
 *   @0x2972fc str r3, [r6]
 *   @0x297300 movw r0, #0x1088
 *   @0x297304 str r10, [r3, #0xac]
 *   @0x297308 mov r7, #0
 *   @0x29730c bl 0x27c524 <_Znwj>
 *   @0x297310 mov r3, #1024
 *   @0x297314 mov r1, r7
 *   @0x297318 mov r2, #128
 *   @0x29731c mov r4, r0
 *   @0x297320 add r0, r0, #8
 *   @0x297324 str r3, [r4]
 *   @0x297328 str r4, [r6, #0x4]
 *   @0x29732c str r7, [r4, #0x4]
 *   @0x297330 bl 0xb65b0 <memset@plt>
 *   @0x297334 add r0, r4, #136
 *   @0x297338 mov r1, r7
 *   @0x29733c mov r2, #4096
 *   @0x297340 bl 0xb65b0 <memset@plt>
 *   @0x297344 ldr r0, [r6, #0x4]
 *   @0x297348 ldr r12, [r5]
 *   @0x29734c ldr r3, [r0, #0x4]
 *   @0x297350 cmp r3, #1024
 *   @0x297354 bge 0x2973a4 <_ZN8yyServer4InitE11eSocketTypeiib+0x1c4>
 *   @0x297358 add r3, r0, #132
 *   @0x29735c mov r1, r7
 *   @0x297360 b 0x297370 <_ZN8yyServer4InitE11eSocketTypeiib+0x190>
 *   @0x297364 add r1, r1, #1
 *   @0x297368 cmp r1, #1024
 *   @0x29736c beq 0x297384 <_ZN8yyServer4InitE11eSocketTypeiib+0x1a4>
 *   @0x297370 ldr r2, [r3, #0x4]!
 *   @0x297374 cmp r2, #0
 *   @0x297378 bne 0x297364 <_ZN8yyServer4InitE11eSocketTypeiib+0x184>
 *   @0x29737c add r1, r1, #34
 *   @0x297380 str r12, [r0, r1, lsl #2]
 *   @0x297384 ldr r3, [r12]
 *   @0x297388 mov r12, #1
 *   @0x29738c and r1, r3, #31
 *   @0x297390 asr r3, r3, #5
 *   @0x297394 add r0, r0, r3, lsl #2
 *   @0x297398 ldr r2, [r0, #0x8]
 *   @0x29739c orr r3, r2, r12, lsl r1
 *   @0x2973a0 str r3, [r0, #0x8]
 *   @0x2973a4 movw r0, #0x1088
 *   @0x2973a8 mov r5, #0
 *   @0x2973ac bl 0x27c524 <_Znwj>
 *   @0x2973b0 mov r3, #1024
 *   @0x2973b4 mov r1, r5
 *   @0x2973b8 mov r2, #128
 *   @0x2973bc mov r9, r5
 *   @0x2973c0 mov r4, r0
 *   @0x2973c4 add r0, r0, #8
 *   @0x2973c8 str r3, [r4]
 *   @0x2973cc str r4, [r6, #0x8]
 *   @0x2973d0 str r5, [r4, #0x4]
 *   @0x2973d4 bl 0xb65b0 <memset@plt>
 *   @0x2973d8 add r0, r4, #136
 *   @0x2973dc mov r1, r5
 *   @0x2973e0 mov r2, #4096
 *   @0x2973e4 bl 0xb65b0 <memset@plt>
 *   @0x2973e8 b 0x29722c <_ZN8yyServer4InitE11eSocketTypeiib+0x4c>
 *   @0x2973ec ldr r3, [pc, #0xcc]
 *   @0x2973f0 ldr r1, [pc, #0xcc]
 *   @0x2973f4 ldr r3, [r7, r3]
 *   @0x2973f8 add r1, pc, r1
 *   @0x2973fc ldr r0, [r3]
 *   @0x297400 ldr r3, [r0]
 *   @0x297404 ldr r3, [r3, #0xc]
 *   @0x297408 blx r3
 *   @0x29740c ldr r4, [r5]
 *   @0x297410 cmp r4, #0
 *   @0x297414 beq 0x297228 <_ZN8yyServer4InitE11eSocketTypeiib+0x48>
 *   @0x297418 mov r0, r4
 *   @0x29741c bl 0x294cbc <_ZN8yySocketD2Ev>
 *   @0x297420 mov r0, r4
 *   @0x297424 bl 0x27d1d0 <_ZdlPv>
 *   @0x297428 b 0x29722c <_ZN8yyServer4InitE11eSocketTypeiib+0x4c>
 *   @0x29742c ldr r0, [r5]
 *   @0x297430 mov r1, #5
 *   @0x297434 bl 0x295240 <_ZN8yySocket6ListenEi>
 *   @0x297438 subs r9, r0, #0
 *   @0x29743c bge 0x2972f8 <_ZN8yyServer4InitE11eSocketTypeiib+0x118>
 *   @0x297440 ldr r1, [pc, #0x80]
 *   @0x297444 ldr r3, [pc, #0x74]
 *   @0x297448 add r1, pc, r1
 *   @0x29744c ldr r3, [r7, r3]
 *   @0x297450 ldr r0, [r3]
 *   @0x297454 ldr r3, [r0]
 *   @0x297458 ldr r3, [r3, #0xc]
 *   @0x29745c blx r3
 *   @0x297460 ldr r4, [r5]
 *   @0x297464 cmp r4, #0
 *   @0x297468 bne 0x297418 <_ZN8yyServer4InitE11eSocketTypeiib+0x238>
 *   @0x29746c b 0x29722c <_ZN8yyServer4InitE11eSocketTypeiib+0x4c>
 *   @0x297470 mov r0, #64
 *   @0x297474 bl 0x27c524 <_Znwj>
 *   @0x297478 mov r2, #1
 *   @0x29747c mov r3, r2
 *   @0x297480 ldr r1, [r6, #0x14]
 *   @0x297484 mov r4, r0
 *   @0x297488 bl 0xcc994 <_ZN7IBufferC2Ei14eBuffer_Formati>
 *   @0x29748c ldr r3, [pc, #0x38]
 *   @0x297490 ldr r2, [r5]
 *   @0x297494 ldr r1, [r7, r3]
 *   @0x297498 mov r3, r2
 *   @0x29749c add r1, r1, #8
 *   @0x2974a0 str r1, [r4]
 *   @0x2974a4 str r4, [r2, #0x4c]
 *   @0x2974a8 b 0x2972fc <_ZN8yyServer4InitE11eSocketTypeiib+0x11c>
 *   @0x2974ac bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2974b0 andseq r10, r5, r8, asr r10
 *   @0x2974b4 .word 0xffffbd00
 *   @0x2974b8 .word 0xfffffd50
 *   @0x2974bc strheq r2, [r12], -r0
 *   @0x2974c0 .word 0xffffbac4
 *   @0x2974c4 andeq r2, r12, r4, ror #2
 *   @0x2974c8 andeq r2, r12, r0, asr r1
 *   @0x2974cc .word 0xffffbd60
 *
 * ══ §7/42 jinit_upsampler  0x2b8ad0  size 752  188 条（0x2b8ad0..0x2b8dc0）
 * @func 0x2b8ad0 0x2b8dc0  size 752  188 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×4 / jinit_upsampler+0x230×2 / __aeabi_idivmod×2 / jround_up / jinit_upsampler+0x294
 * 字段偏移 top8: 0x8×7 / 0x14×5 / 0x34×5 / 0x4×4 / 0x24×4 / 0xc×3 / 0x118×2 / 0x10×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b8ad0 ldr r3, [r0, #0x4]
 *   @0x2b8ad4 mov r1, #1
 *   @0x2b8ad8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2b8adc mov r2, #160
 *   @0x2b8ae0 sub sp, sp, #44
 *   @0x2b8ae4 ldr r3, [r3]
 *   @0x2b8ae8 mov r4, r0
 *   @0x2b8aec blx r3
 *   @0x2b8af0 ldr r1, [pc, #0x2a4]
 *   @0x2b8af4 mov r3, #0
 *   @0x2b8af8 ldr r2, [pc, #0x2a0]
 *   @0x2b8afc add r1, pc, r1
 *   @0x2b8b00 add r2, pc, r2
 *   @0x2b8b04 str r0, [r4, #0x1a0]
 *   @0x2b8b08 stm r0, {r1, r2}
 *   @0x2b8b0c strb r3, [r0, #0x8]
 *   @0x2b8b10 ldrb r3, [r4, #0x10a]
 *   @0x2b8b14 str r0, [sp, #0x8]
 *   @0x2b8b18 cmp r3, #0
 *   @0x2b8b1c bne 0x2b8d48 <jinit_upsampler+0x278>
 *   @0x2b8b20 ldrb r3, [r4, #0x48]
 *   @0x2b8b24 cmp r3, #0
 *   @0x2b8b28 streq r3, [sp, #0x14]
 *   @0x2b8b2c beq 0x2b8b44 <jinit_upsampler+0x74>
 *   @0x2b8b30 ldr r3, [r4, #0x118]
 *   @0x2b8b34 cmp r3, #1
 *   @0x2b8b38 movle r3, #0
 *   @0x2b8b3c movgt r3, #1
 *   @0x2b8b40 str r3, [sp, #0x14]
 *   @0x2b8b44 ldr r3, [r4, #0x24]
 *   @0x2b8b48 ldr r5, [r4, #0xc4]
 *   @0x2b8b4c cmp r3, #0
 *   @0x2b8b50 ble 0x2b8d00 <jinit_upsampler+0x230>
 *   @0x2b8b54 ldr r0, [pc, #0x248]
 *   @0x2b8b58 mov r8, #0
 *   @0x2b8b5c ldr r1, [pc, #0x244]
 *   @0x2b8b60 ldr r6, [sp, #0x8]
 *   @0x2b8b64 add r0, pc, r0
 *   @0x2b8b68 add r1, pc, r1
 *   @0x2b8b6c str r0, [sp, #0x10]
 *   @0x2b8b70 str r1, [sp, #0x1c]
 *   @0x2b8b74 ldr r2, [pc, #0x230]
 *   @0x2b8b78 mov r10, r6
 *   @0x2b8b7c ldr r3, [pc, #0x22c]
 *   @0x2b8b80 ldr r0, [pc, #0x22c]
 *   @0x2b8b84 add r2, pc, r2
 *   @0x2b8b88 ldr r1, [pc, #0x228]
 *   @0x2b8b8c add r3, pc, r3
 *   @0x2b8b90 add r0, pc, r0
 *   @0x2b8b94 str r2, [sp, #0x20]
 *   @0x2b8b98 add r1, pc, r1
 *   @0x2b8b9c str r3, [sp, #0x18]
 *   @0x2b8ba0 str r0, [sp, #0x24]
 *   @0x2b8ba4 str r1, [sp, #0xc]
 *   @0x2b8ba8 b 0x2b8bd4 <jinit_upsampler+0x104>
 *   @0x2b8bac ldr r3, [pc, #0x208]
 *   @0x2b8bb0 add r3, pc, r3
 *   @0x2b8bb4 str r3, [r6, #0x34]
 *   @0x2b8bb8 ldr r3, [r4, #0x24]
 *   @0x2b8bbc add r8, r8, #1
 *   @0x2b8bc0 add r5, r5, #84
 *   @0x2b8bc4 add r6, r6, #4
 *   @0x2b8bc8 cmp r3, r8
 *   @0x2b8bcc add r10, r10, #1
 *   @0x2b8bd0 ble 0x2b8d00 <jinit_upsampler+0x230>
 *   @0x2b8bd4 ldr r3, [r5, #0x24]
 *   @0x2b8bd8 ldr r0, [r5, #0xc]
 *   @0x2b8bdc ldr r9, [r4, #0x118]
 *   @0x2b8be0 ldr r2, [r5, #0x8]
 *   @0x2b8be4 mul r0, r0, r3
 *   @0x2b8be8 mov r1, r9
 *   @0x2b8bec str r3, [sp]
 *   @0x2b8bf0 str r2, [sp, #0x4]
 *   @0x2b8bf4 bl 0x318d10 <__divsi3>
 *   @0x2b8bf8 ldr r12, [r4, #0x110]
 *   @0x2b8bfc ldr r11, [r4, #0x114]
 *   @0x2b8c00 str r0, [r6, #0x64]
 *   @0x2b8c04 mov r7, r0
 *   @0x2b8c08 ldrb r1, [r5, #0x30]
 *   @0x2b8c0c ldr r3, [sp]
 *   @0x2b8c10 cmp r1, #0
 *   @0x2b8c14 beq 0x2b8bac <jinit_upsampler+0xdc>
 *   @0x2b8c18 ldr r2, [sp, #0x4]
 *   @0x2b8c1c mov r1, r9
 *   @0x2b8c20 str r12, [sp]
 *   @0x2b8c24 mul r0, r3, r2
 *   @0x2b8c28 bl 0x318d10 <__divsi3>
 *   @0x2b8c2c subs r2, r7, r11
 *   @0x2b8c30 ldr r12, [sp]
 *   @0x2b8c34 rsbs r3, r2, #0
 *   @0x2b8c38 adcs r3, r3, r2
 *   @0x2b8c3c cmp r0, r12
 *   @0x2b8c40 cmpeq r7, r11
 *   @0x2b8c44 mov r9, r0
 *   @0x2b8c48 ldreq r3, [sp, #0xc]
 *   @0x2b8c4c streq r3, [r6, #0x34]
 *   @0x2b8c50 beq 0x2b8bb8 <jinit_upsampler+0xe8>
 *   @0x2b8c54 cmp r12, r0, lsl #1
 *   @0x2b8c58 beq 0x2b8d08 <jinit_upsampler+0x238>
 *   @0x2b8c5c mov r0, r12
 *   @0x2b8c60 mov r1, r9
 *   @0x2b8c64 str r12, [sp]
 *   @0x2b8c68 bl 0x318dec <__aeabi_idivmod>
 *   @0x2b8c6c cmp r1, #0
 *   @0x2b8c70 bne 0x2b8ce4 <jinit_upsampler+0x214>
 *   @0x2b8c74 mov r0, r11
 *   @0x2b8c78 mov r1, r7
 *   @0x2b8c7c bl 0x318dec <__aeabi_idivmod>
 *   @0x2b8c80 ldr r12, [sp]
 *   @0x2b8c84 cmp r1, #0
 *   @0x2b8c88 bne 0x2b8ce4 <jinit_upsampler+0x214>
 *   @0x2b8c8c ldr r3, [sp, #0x10]
 *   @0x2b8c90 mov r0, r12
 *   @0x2b8c94 mov r1, r9
 *   @0x2b8c98 str r3, [r6, #0x34]
 *   @0x2b8c9c bl 0x318d10 <__divsi3>
 *   @0x2b8ca0 mov r1, r7
 *   @0x2b8ca4 strb r0, [r10, #0x8c]
 *   @0x2b8ca8 mov r0, r11
 *   @0x2b8cac bl 0x318d10 <__divsi3>
 *   @0x2b8cb0 strb r0, [r10, #0x96]
 *   @0x2b8cb4 ldr r3, [r4, #0x4]
 *   @0x2b8cb8 ldr r1, [r4, #0x110]
 *   @0x2b8cbc ldr r0, [r4, #0x5c]
 *   @0x2b8cc0 ldr r7, [r3, #0x8]
 *   @0x2b8cc4 bl 0x2bc800 <jround_up>
 *   @0x2b8cc8 mov r1, #1
 *   @0x2b8ccc ldr r3, [r4, #0x114]
 *   @0x2b8cd0 mov r2, r0
 *   @0x2b8cd4 mov r0, r4
 *   @0x2b8cd8 blx r7
 *   @0x2b8cdc str r0, [r6, #0xc]
 *   @0x2b8ce0 b 0x2b8bb8 <jinit_upsampler+0xe8>
 *   @0x2b8ce4 ldr r3, [r4]
 *   @0x2b8ce8 mov r2, #38
 *   @0x2b8cec mov r0, r4
 *   @0x2b8cf0 str r2, [r3, #0x14]
 *   @0x2b8cf4 ldr r3, [r3]
 *   @0x2b8cf8 blx r3
 *   @0x2b8cfc b 0x2b8cb4 <jinit_upsampler+0x1e4>
 *   @0x2b8d00 add sp, sp, #44
 *   @0x2b8d04 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2b8d08 cmp r3, #0
 *   @0x2b8d0c bne 0x2b8d70 <jinit_upsampler+0x2a0>
 *   @0x2b8d10 cmp r11, r7, lsl #1
 *   @0x2b8d14 bne 0x2b8c5c <jinit_upsampler+0x18c>
 *   @0x2b8d18 ldr r3, [sp, #0x14]
 *   @0x2b8d1c cmp r3, #0
 *   @0x2b8d20 beq 0x2b8d64 <jinit_upsampler+0x294>
 *   @0x2b8d24 ldr r3, [r5, #0x28]
 *   @0x2b8d28 cmp r3, #2
 *   @0x2b8d2c bls 0x2b8d64 <jinit_upsampler+0x294>
 *   @0x2b8d30 ldr r0, [sp, #0x20]
 *   @0x2b8d34 mov r3, #1
 *   @0x2b8d38 ldr r1, [sp, #0x8]
 *   @0x2b8d3c str r0, [r6, #0x34]
 *   @0x2b8d40 strb r3, [r1, #0x8]
 *   @0x2b8d44 b 0x2b8cb4 <jinit_upsampler+0x1e4>
 *   @0x2b8d48 ldr r3, [r4]
 *   @0x2b8d4c mov r2, #25
 *   @0x2b8d50 mov r0, r4
 *   @0x2b8d54 str r2, [r3, #0x14]
 *   @0x2b8d58 ldr r3, [r3]
 *   @0x2b8d5c blx r3
 *   @0x2b8d60 b 0x2b8b20 <jinit_upsampler+0x50>
 *   @0x2b8d64 ldr r2, [sp, #0x1c]
 *   @0x2b8d68 str r2, [r6, #0x34]
 *   @0x2b8d6c b 0x2b8cb4 <jinit_upsampler+0x1e4>
 *   @0x2b8d70 ldr r0, [sp, #0x14]
 *   @0x2b8d74 cmp r0, #0
 *   @0x2b8d78 beq 0x2b8d90 <jinit_upsampler+0x2c0>
 *   @0x2b8d7c ldr r3, [r5, #0x28]
 *   @0x2b8d80 cmp r3, #2
 *   @0x2b8d84 ldrhi r1, [sp, #0x24]
 *   @0x2b8d88 strhi r1, [r6, #0x34]
 *   @0x2b8d8c bhi 0x2b8cb4 <jinit_upsampler+0x1e4>
 *   @0x2b8d90 ldr r2, [sp, #0x18]
 *   @0x2b8d94 str r2, [r6, #0x34]
 *   @0x2b8d98 b 0x2b8cb4 <jinit_upsampler+0x1e4>
 *   @0x2b8d9c .word 0xfffff9e4
 *   @0x2b8da0 .word 0xfffff9f8
 *   @0x2b8da4 .word 0xfffffe00
 *   @0x2b8da8 .word 0xfffffed0
 *   @0x2b8dac .word 0xfffffc3c
 *   @0x2b8db0 .word 0xfffffabc
 *   @0x2b8db4 .word 0xfffffb20
 *   @0x2b8db8 .word 0xfffffa9c
 *   @0x2b8dbc .word 0xfffffa8c
 *
 * ══ §8/42 FT_Bitmap_Convert  0x314ad0  size 752  188 条（0x314ad0..0x314dc0）
 * @func 0x314ad0 0x314dc0  size 752  188 条
 * 部分覆盖: 本节 188/334 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x374afc / __aeabi_idivmod / 0x718d76 / 0x3f19e2 / 0x3985c2 / 0x450b0c
 * 字段偏移 top8: 0x4×6 / 0x8×6 / 0x12×2 / 0x1c×2 / 0x10×2 / 0x18×2 / 0x18c×1 / 0x-4×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x314ad0 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x314ad4 sub sp, #0x24
 *   @0x314ad8 mov r5, r2
 *   @0x314adc mov r11, r3
 *   @0x314ae0 cmp r0, #0x0
 *   @0x314ae4 stmdblt r12, {r0, r3, r5, r6, r8, pc}
 *   @0x314ae8 movs r0, #0x6
 *   @0x314aec cmp r2, #0x0
 *   @0x314af0 ldrb r3, [r4, #0x12]
 *   @0x314af4 bllo 0x374afc <_ZTS13C_UTF16String+0xbba8>
 *   @0x314af8 cmp r3, #0x6
 *   @0x314afc movs r3, #0x2
 *   @0x314b00 ldr r7, [r4]
 *   @0x314b04 .word 0xf8d20f00
 *   @0x314b08 .word 0xf8d29000
 *   @0x314b0c andsvs r10, r7, r8
 *   @0x314b10 ldr r3, [r4, #0x4]
 *   @0x314b14 ldr r6, [r4, #0x4]
 *   @0x314b18 mov r0, r6
 *   @0x314b1c blx 0x318dec <__aeabi_idivmod>
 *   @0x314b20 cbz r1, 0x314b26 <FT_Bitmap_Convert+0x56>
 *   @0x314b24 strmi r0, [lr], #-267
 *   @0x314b28 cmp r6, #0x0
 *   @0x314b2c mov.w r0, #0xffffffff
 *   @0x314b30 mov r1, r6
 *   @0x314b34 addmi lr, r7, #9043968
 *   @0x314b38 bhi 0x314ae8 <FT_Bitmap_Convert+0x18>
 *   @0x314b3c svclt #0xb80f00
 *   @0x314b40 rsblt.w r10, r10, #0x0
 *   @0x314b44 mul r3, r7, r6
 *   @0x314b48 mul r2, r9, r10
 *   @0x314b4c cmp r3, r2
 *   @0x314b50 ldr r3, [r5, #0x8]
 *   @0x314b54 bge 0x314b74 <FT_Bitmap_Convert+0xa4>
 *   @0x314b58 b 0x314b74 <FT_Bitmap_Convert+0xa4>
 *   @0x314b5c mov r0, r8
 *   @0x314b60 add r1, sp, #0x1c
 *   @0x314b64 movs r1, #0x1
 *   @0x314b68 rscvs pc, r8, r3, asr r10
 *   @0x314b6c ldr r0, [sp, #0x1c]
 *   @0x314b70 beq 0x314b50 <FT_Bitmap_Convert+0x80>
 *   @0x314b74 str r6, [r5, #0x8]
 *   @0x314b78 movs r3, #0x6
 *   @0x314b7c ldr r3, [r4, #0x8]
 *   @0x314b80 cmp r3, #0x0
 *   @0x314b84 bge 0x314b8e <FT_Bitmap_Convert+0xbe>
 *   @0x314b88 subs r2, #0x1
 *   @0x314b8c stmvs r11!, {r0, r1, r4, r8, r9, r10, r12, sp, lr}
 *   @0x314b90 cmp r3, #0x0
 *   @0x314b94 ldr r2, [r5]
 *   @0x314b98 mls r6, r2, r3, r6
 *   @0x314b9c ldrb r3, [r4, #0x12]
 *   @0x314ba0 cmp r3, #0x6
 *   @0x314ba4 ldm pc, {r0, r1, r2, r8, pc} ^
 *   @0x314ba8 .word 0x4c04f003
 *   @0x314bac ldr r2, [sp, #0x18c]
 *   @0x314bb0 lsls r0, r0, #0x3
 *   @0x314bb4 strh r3, [r5, #0x10]
 *   @0x314bb8 cmp r0, #0x0
 *   @0x314bbc stmdavs r3!, {r0, r1, r3, r4, r5, r6, r7, pc} ^
 *   @0x314bc0 movs r1, #0x0
 *   @0x314bc4 .word 0x46330cd3
 *   @0x314bc8 cmp r1, r12
 *   @0x314bcc ldrb r2, [r7, r1]
 *   @0x314bd0 adds r1, #0x1
 *   @0x314bd4 .word 0xf80318d2
 *   @0x314bd8 vmull.u8 q12, d2, d8
 *   @0x314bdc .word 0xf8031880
 *   @0x314be0 vmull.u8 q12, d2, d7
 *   @0x314be4 .word 0xf8031840
 *   @0x314be8 vmull.u8 q12, d2, d6
 *   @0x314bec .word 0xf8031800
 *   @0x314bf0 vmull.u8 q12, d2, d5
 *   @0x314bf4 .word 0xf80308c0
 *   @0x314bf8 vmull.u8 q12, d2, d4
 *   @0x314bfc .word 0xf8030880
 *   @0x314c00 vmull.u8 q12, d2, d3
 *   @0x314c04 .word 0xf0020840
 *   @0x314c08 .word 0xf8030201
 *   @0x314c0c .word 0xf8038c02
 *   @0x314c10 ldrb r2, [r9, r1, lsl #24]
 *   @0x314c14 ldr r2, [r4, #0x4]
 *   @0x314c18 .word 0xf01203c1
 *   @0x314c1c andle r0, r10, r7, lsl #24
 *   @0x314c20 ldrb r2, [r7, r1]
 *   @0x314c24 vaddw.u8 q8, q1, d12
 *   @0x314c28 .word 0xf8031cc0
 *   @0x314c2c addmi r12, r11, #1024
 *   @0x314c30 lsl.w r2, r2, #0x1
 *   @0x314c34 bne 0x314c26 <FT_Bitmap_Convert+0x156>
 *   @0x314c38 subs r0, #0x1
 *   @0x314c3c ldr r3, [r5, #0x8]
 *   @0x314c40 b 0x314bb8 <FT_Bitmap_Convert+0xe8>
 *   @0x314c44 vst4.8 {d25, d26, d27, d28}, [pc], r4
 *   @0x314c48 eorhi r7, r11, #128, #6
 *   @0x314c4c ldr.w r8, [r4]
 *   @0x314c50 cmp.w r8, #0x0
 *   @0x314c54 beq.w 0x314db4 <FT_Bitmap_Convert+0x2e4>
 *   @0x314c58 mov r0, r6
 *   @0x314c5c mov r2, r9
 *   @0x314c60 .word 0xf5a138ff
 *   @0x314c64 stmvs r3!, {r2, r3, r5, r7, r10, r11, sp, lr, pc}
 *   @0x314c68 add r7, r3
 *   @0x314c6c add r6, r3
 *   @0x314c70 movs r3, #0x4
 *   @0x314c74 ldr r0, [r4]
 *   @0x314c78 beq.w 0x314db4 <FT_Bitmap_Convert+0x2e4>
 *   @0x314c7c ldr r3, [r4, #0x4]
 *   @0x314c80 lsr.w r12, r3, #0x2
 *   @0x314c84 movs r3, #0x0
 *   @0x314c88 beq 0x314cb2 <FT_Bitmap_Convert+0x1e2>
 *   @0x314c8c adds r2, #0x4
 *   @0x314c90 lsr.w r8, r1, #0x6
 *   @0x314c94 strb r8, [r2, #-4]
 *   @0x314c98 ubfx r8, r1, #0x4, #0x2
 *   @0x314c9c strb r8, [r2, #-3]
 *   @0x314ca0 ubfx r8, r1, #0x2, #0x2
 *   @0x314ca4 and r1, r1, #0x3
 *   @0x314ca8 strb r8, [r2, #-2]
 *   @0x314cac strb r1, [r2, #-1]
 *   @0x314cb0 b 0x314c86 <FT_Bitmap_Convert+0x1b6>
 *   @0x314cb4 add.w r2, r6, r3, lsl #2
 *   @0x314cb8 ands r1, r1, #0x3
 *   @0x314cbc beq 0x314cd2 <FT_Bitmap_Convert+0x202>
 *   @0x314cc0 add r1, r2
 *   @0x314cc4 .word 0xf8021c81
 *   @0x314cc8 addmi r12, r10, #1024
 *   @0x314ccc lsl.w r3, r3, #0x2
 *   @0x314cd0 bne 0x314cc2 <FT_Bitmap_Convert+0x1f2>
 *   @0x314cd4 subs r0, #0x1
 *   @0x314cd8 ldr r3, [r5, #0x8]
 *   @0x314cdc b 0x314c76 <FT_Bitmap_Convert+0x1a6>
 *   @0x314ce0 strh r3, [r5, #0x10]
 *   @0x314ce4 cmp r1, #0x0
 *   @0x314ce8 ldr r3, [r4, #0x4]
 *   @0x314cec lsr.w r12, r3, #0x1
 *   @0x314cf0 movs r3, #0x0
 *   @0x314cf4 add.w r2, r2, #0x2
 *   @0x314cf8 beq 0x314d10 <FT_Bitmap_Convert+0x240>
 *   @0x314cfc adds r3, #0x1
 *   @0x314d00 .word 0xf0001810
 *   @0x314d04 .word 0xf802000f
 *   @0x314d08 .word 0xf8028c02
 *   @0x314d0c ldrb r0, [r0, r1, lsl #24]!
 *   @0x314d10 ldr r2, [r4, #0x4]
 *   @0x314d14 bpl 0x314d1e <FT_Bitmap_Convert+0x24e>
 *   @0x314d18 lsrs r2, r2, #0x4
 *   @0x314d1c stmvs r3!, {r0, r1, r4, sp}
 *   @0x314d20 subs r1, #0x1
 *   @0x314d24 ldr r3, [r5, #0x8]
 *   @0x314d28 b 0x314ce4 <FT_Bitmap_Convert+0x214>
 *   @0x314d2c eorhi r7, r11, #128, #6
 *   @0x314d30 ldr.w r10, [r4]
 *   @0x314d34 movw r2, #0x366d
 *   @0x314d38 cmp.w r10, #0x0
 *   @0x314d3c beq 0x314db4 <FT_Bitmap_Convert+0x2e4>
 *   @0x314d40 mov r11, r6
 *   @0x314d44 add.w r12, r6, r1
 *   @0x314d48 cmp r11, r12
 *   @0x314d4c ldrb.w r9, [r8, #0x3]
 *   @0x314d50 cmp.w r9, #0x0
 *   @0x314d54 beq 0x314d9c <FT_Bitmap_Convert+0x2cc>
 *   @0x314d58 vhadd.s8 d16, d1, d0
 *   @0x314d5c .word 0xf898237c
 *   @0x314d60 .word 0xf898e001
 *   @0x314d64 blx 0x718d76 <g_SWFvertbuff+0x45cae>
 *   @0x314d68 andls pc, r4, #0
 *   @0x314d6c smulbb lr, lr, lr
 *   @0x314d70 str.w r12, [sp, #0x14]
 *   @0x314d74 smulbb r1, r1, r1
 *   @0x314d78 muls r0, r3, r0
 *   @0x314d7c blx 0x3f19e2
 *   @0x314d80 blx 0x3985c2 <ft_adobe_glyph_list+0x7c9e>
 *   @0x314d84 strbmi lr, [r9], -r1
 *   @0x314d88 lsrs r0, r0, #0x10
 *   @0x314d8c bls 0x450b0c <g_RomDisk+0x592ec>
 *   @0x314d90 ldr.w r12, [sp, #0x14]
 *   @0x314d94 rsb r0, r0, r9
 *   @0x314d98 uxtb.w r9, r0
 *   @0x314d9c strb r9, [r11], #1
 *   @0x314da0 add.w r8, r8, #0x4
 *   @0x314da4 b 0x314d48 <FT_Bitmap_Convert+0x278>
 *   @0x314da8 add.w r10, r10, #0xffffffff
 *   @0x314dac add r7, r1
 *   @0x314db0 add r6, r1
 *   @0x314db4 ldr r0, [sp, #0x1c]
 *   @0x314db8 movs r0, #0x21
 *   @0x314dbc pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §9/42 GetDeactiveList(void (*)(CInstance*))  0x10baf8  size 748  187 条（0x10baf8..0x10bde4）
 * @func 0x10baf8 0x10bde4  size 748  187 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)×4 / operator new(unsigned int) / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x8×14 / 0x4×8 / 0x68×4 / 0x178×4 / 0x69×4 / 0x2×4 / 0x2c0×1 / 0x2ac×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10baf8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x10bafc mov r8, r0
 *   @0x10bb00 ldr r7, [pc, #0x2c0]
 *   @0x10bb04 sub sp, sp, #12
 *   @0x10bb08 ldr r7, [pc, r7]
 *   @0x10bb0c ldr r4, [r7]
 *   @0x10bb10 cmp r4, #0
 *   @0x10bb14 beq 0x10bd8c <_Z15GetDeactiveListPFvP9CInstanceE+0x294>
 *   @0x10bb18 ldr r9, [pc, #0x2ac]
 *   @0x10bb1c mov r3, #0
 *   @0x10bb20 str r3, [r4, #0x8]
 *   @0x10bb24 ldr r9, [pc, r9]
 *   @0x10bb28 ldr r3, [r9]
 *   @0x10bb2c ldr r4, [r3, #0x80]
 *   @0x10bb30 cmp r4, #0
 *   @0x10bb34 beq 0x10bba0 <_Z15GetDeactiveListPFvP9CInstanceE+0xa8>
 *   @0x10bb38 ldr r10, [pc, #0x290]
 *   @0x10bb3c cmp r8, #0
 *   @0x10bb40 add r10, pc, r10
 *   @0x10bb44 beq 0x10bc7c <_Z15GetDeactiveListPFvP9CInstanceE+0x184>
 *   @0x10bb48 ldrb r11, [r4, #0x68]
 *   @0x10bb4c ldr r5, [r4, #0x178]
 *   @0x10bb50 cmp r11, #0
 *   @0x10bb54 bne 0x10bb90 <_Z15GetDeactiveListPFvP9CInstanceE+0x98>
 *   @0x10bb58 ldrb r3, [r4, #0x69]
 *   @0x10bb5c mov r0, r4
 *   @0x10bb60 cmp r3, #0
 *   @0x10bb64 beq 0x10bb90 <_Z15GetDeactiveListPFvP9CInstanceE+0x98>
 *   @0x10bb68 blx r8
 *   @0x10bb6c ldr r6, [r7]
 *   @0x10bb70 ldr r1, [r6, #0x8]
 *   @0x10bb74 ldr r3, [r6, #0x4]
 *   @0x10bb78 cmp r1, r3
 *   @0x10bb7c beq 0x10bc1c <_Z15GetDeactiveListPFvP9CInstanceE+0x124>
 *   @0x10bb80 ldr r2, [r6]
 *   @0x10bb84 add r3, r1, #1
 *   @0x10bb88 str r4, [r2, r1, lsl #2]
 *   @0x10bb8c str r3, [r6, #0x8]
 *   @0x10bb90 cmp r5, #0
 *   @0x10bb94 mov r4, r5
 *   @0x10bb98 bne 0x10bb48 <_Z15GetDeactiveListPFvP9CInstanceE+0x50>
 *   @0x10bb9c ldr r3, [r9]
 *   @0x10bba0 ldr r4, [r3, #0x8c]
 *   @0x10bba4 cmp r4, #0
 *   @0x10bba8 beq 0x10bc10 <_Z15GetDeactiveListPFvP9CInstanceE+0x118>
 *   @0x10bbac ldr r10, [pc, #0x220]
 *   @0x10bbb0 cmp r8, #0
 *   @0x10bbb4 add r10, pc, r10
 *   @0x10bbb8 beq 0x10bd04 <_Z15GetDeactiveListPFvP9CInstanceE+0x20c>
 *   @0x10bbbc ldrb r9, [r4, #0x68]
 *   @0x10bbc0 ldr r5, [r4, #0x178]
 *   @0x10bbc4 cmp r9, #0
 *   @0x10bbc8 bne 0x10bc04 <_Z15GetDeactiveListPFvP9CInstanceE+0x10c>
 *   @0x10bbcc ldrb r3, [r4, #0x69]
 *   @0x10bbd0 mov r0, r4
 *   @0x10bbd4 cmp r3, #0
 *   @0x10bbd8 beq 0x10bc04 <_Z15GetDeactiveListPFvP9CInstanceE+0x10c>
 *   @0x10bbdc blx r8
 *   @0x10bbe0 ldr r6, [r7]
 *   @0x10bbe4 ldr r1, [r6, #0x8]
 *   @0x10bbe8 ldr r3, [r6, #0x4]
 *   @0x10bbec cmp r1, r3
 *   @0x10bbf0 beq 0x10bc4c <_Z15GetDeactiveListPFvP9CInstanceE+0x154>
 *   @0x10bbf4 ldr r2, [r6]
 *   @0x10bbf8 add r3, r1, #1
 *   @0x10bbfc str r4, [r2, r1, lsl #2]
 *   @0x10bc00 str r3, [r6, #0x8]
 *   @0x10bc04 cmp r5, #0
 *   @0x10bc08 mov r4, r5
 *   @0x10bc0c bne 0x10bbbc <_Z15GetDeactiveListPFvP9CInstanceE+0xc4>
 *   @0x10bc10 ldr r0, [r7]
 *   @0x10bc14 add sp, sp, #12
 *   @0x10bc18 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x10bc1c lsl r3, r1, #1
 *   @0x10bc20 ldr r0, [r6]
 *   @0x10bc24 str r3, [r6, #0x4]
 *   @0x10bc28 lsl r1, r1, #3
 *   @0x10bc2c mov r2, r10
 *   @0x10bc30 str r11, [sp]
 *   @0x10bc34 mov r3, #74
 *   @0x10bc38 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x10bc3c ldr r1, [r6, #0x8]
 *   @0x10bc40 mov r2, r0
 *   @0x10bc44 str r0, [r6]
 *   @0x10bc48 b 0x10bb84 <_Z15GetDeactiveListPFvP9CInstanceE+0x8c>
 *   @0x10bc4c lsl r3, r1, #1
 *   @0x10bc50 ldr r0, [r6]
 *   @0x10bc54 str r3, [r6, #0x4]
 *   @0x10bc58 lsl r1, r1, #3
 *   @0x10bc5c mov r2, r10
 *   @0x10bc60 str r9, [sp]
 *   @0x10bc64 mov r3, #74
 *   @0x10bc68 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x10bc6c ldr r1, [r6, #0x8]
 *   @0x10bc70 mov r2, r0
 *   @0x10bc74 str r0, [r6]
 *   @0x10bc78 b 0x10bbf8 <_Z15GetDeactiveListPFvP9CInstanceE+0x100>
 *   @0x10bc7c ldr r10, [pc, #0x154]
 *   @0x10bc80 add r10, pc, r10
 *   @0x10bc84 b 0x10bca0 <_Z15GetDeactiveListPFvP9CInstanceE+0x1a8>
 *   @0x10bc88 str r4, [r3, r1, lsl #2]
 *   @0x10bc8c add r1, r1, #1
 *   @0x10bc90 str r1, [r6, #0x8]
 *   @0x10bc94 cmp r5, #0
 *   @0x10bc98 mov r4, r5
 *   @0x10bc9c beq 0x10bb9c <_Z15GetDeactiveListPFvP9CInstanceE+0xa4>
 *   @0x10bca0 ldrb r12, [r4, #0x68]
 *   @0x10bca4 ldr r5, [r4, #0x178]
 *   @0x10bca8 cmp r12, #0
 *   @0x10bcac bne 0x10bc94 <_Z15GetDeactiveListPFvP9CInstanceE+0x19c>
 *   @0x10bcb0 ldrb r3, [r4, #0x69]
 *   @0x10bcb4 cmp r3, #0
 *   @0x10bcb8 beq 0x10bc94 <_Z15GetDeactiveListPFvP9CInstanceE+0x19c>
 *   @0x10bcbc ldr r6, [r7]
 *   @0x10bcc0 ldr r3, [r6, #0x4]
 *   @0x10bcc4 ldr r1, [r6, #0x8]
 *   @0x10bcc8 cmp r1, r3
 *   @0x10bccc ldrne r3, [r6]
 *   @0x10bcd0 bne 0x10bc88 <_Z15GetDeactiveListPFvP9CInstanceE+0x190>
 *   @0x10bcd4 lsl r3, r1, #1
 *   @0x10bcd8 ldr r0, [r6]
 *   @0x10bcdc str r3, [r6, #0x4]
 *   @0x10bce0 lsl r1, r1, #3
 *   @0x10bce4 mov r3, #74
 *   @0x10bce8 mov r2, r10
 *   @0x10bcec str r12, [sp]
 *   @0x10bcf0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x10bcf4 ldr r1, [r6, #0x8]
 *   @0x10bcf8 mov r3, r0
 *   @0x10bcfc str r0, [r6]
 *   @0x10bd00 b 0x10bc88 <_Z15GetDeactiveListPFvP9CInstanceE+0x190>
 *   @0x10bd04 ldr r8, [pc, #0xd0]
 *   @0x10bd08 add r8, pc, r8
 *   @0x10bd0c b 0x10bd28 <_Z15GetDeactiveListPFvP9CInstanceE+0x230>
 *   @0x10bd10 str r4, [r3, r1, lsl #2]
 *   @0x10bd14 add r1, r1, #1
 *   @0x10bd18 str r1, [r6, #0x8]
 *   @0x10bd1c cmp r5, #0
 *   @0x10bd20 mov r4, r5
 *   @0x10bd24 beq 0x10bc10 <_Z15GetDeactiveListPFvP9CInstanceE+0x118>
 *   @0x10bd28 ldrb r12, [r4, #0x68]
 *   @0x10bd2c ldr r5, [r4, #0x178]
 *   @0x10bd30 cmp r12, #0
 *   @0x10bd34 bne 0x10bd1c <_Z15GetDeactiveListPFvP9CInstanceE+0x224>
 *   @0x10bd38 ldrb r3, [r4, #0x69]
 *   @0x10bd3c cmp r3, #0
 *   @0x10bd40 beq 0x10bd1c <_Z15GetDeactiveListPFvP9CInstanceE+0x224>
 *   @0x10bd44 ldr r6, [r7]
 *   @0x10bd48 ldr r3, [r6, #0x4]
 *   @0x10bd4c ldr r1, [r6, #0x8]
 *   @0x10bd50 cmp r1, r3
 *   @0x10bd54 ldrne r3, [r6]
 *   @0x10bd58 bne 0x10bd10 <_Z15GetDeactiveListPFvP9CInstanceE+0x218>
 *   @0x10bd5c lsl r3, r1, #1
 *   @0x10bd60 ldr r0, [r6]
 *   @0x10bd64 str r3, [r6, #0x4]
 *   @0x10bd68 lsl r1, r1, #3
 *   @0x10bd6c mov r3, #74
 *   @0x10bd70 mov r2, r8
 *   @0x10bd74 str r12, [sp]
 *   @0x10bd78 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x10bd7c ldr r1, [r6, #0x8]
 *   @0x10bd80 mov r3, r0
 *   @0x10bd84 str r0, [r6]
 *   @0x10bd88 b 0x10bd10 <_Z15GetDeactiveListPFvP9CInstanceE+0x218>
 *   @0x10bd8c mov r0, #12
 *   @0x10bd90 bl 0x27c524 <_Znwj>
 *   @0x10bd94 ldr r1, [pc, #0x44]
 *   @0x10bd98 mov r3, #1
 *   @0x10bd9c mov r2, #50
 *   @0x10bda0 add r1, pc, r1
 *   @0x10bda4 mov r5, r0
 *   @0x10bda8 mov r0, #128
 *   @0x10bdac bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x10bdb0 str r4, [r5, #0x8]
 *   @0x10bdb4 mov r3, #32
 *   @0x10bdb8 mov r4, r5
 *   @0x10bdbc stm r5, {r0, r3}
 *   @0x10bdc0 str r5, [r7]
 *   @0x10bdc4 b 0x10bb18 <_Z15GetDeactiveListPFvP9CInstanceE+0x20>
 *   @0x10bdc8 .word 0x002e25b0
 *   @0x10bdcc eoreq r1, lr, r4, lsl #28
 *   @0x10bdd0 .word 0x002254f0
 *   @0x10bdd4 eoreq r5, r2, r12, ror r4
 *   @0x10bdd8 .word 0x002253b0
 *   @0x10bddc eoreq r5, r2, r8, lsr #6
 *   @0x10bde0 eoreq r12, r2, r8, asr r9
 *
 * ══ §10/42 Graphics::Texture_GrabRect(void*, int, int, int, int)  0x17e2a8  size 748  187 条（0x17e2a8..0x17e594）
 * @func 0x17e2a8 0x17e594  size 748  187 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17e2e8→0x479c10, 0x17e300→0x479c0c, 0x17e314→0x3f26dc, 0x17e328→0x479c08, 0x17e344→0x4a2f4c, 0x17e368→0x479b44, 0x17e370→0x479c00, 0x17e3c4→0x479c14
 * 调用序列: DBG_BIND_FRAMEBUFFER(int)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / Graphics::Flush() / _GetCPUSideTextureData(Texture*, bool&) / Graphics::Texture_GrabRect(void*, int, int, int, int)+0x23c / 0xb65bc / FreePNGFile()
 * 字段偏移 top8: 0x14×6 / 0x4×3 / 0x10×2 / 0x1c×2 / 0x18×1 / 0x28c×1 / 0x48×1 / 0x260×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17e2a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17e2ac mov r11, r1
 *   @0x17e2b0 ldr r1, [r0, #0x18]
 *   @0x17e2b4 sub sp, sp, #36
 *   @0x17e2b8 ldr r4, [pc, #0x28c]
 *   @0x17e2bc mov r6, r0
 *   @0x17e2c0 cmn r1, #1
 *   @0x17e2c4 str r2, [sp, #0x14]
 *   @0x17e2c8 add r4, pc, r4
 *   @0x17e2cc mov r9, r3
 *   @0x17e2d0 ldr r5, [sp, #0x48]
 *   @0x17e2d4 beq 0x17e44c <_ZN8Graphics16Texture_GrabRectEPviiii+0x1a4>
 *   @0x17e2d8 ldr r3, [r6, #0x14]
 *   @0x17e2dc cmn r3, #1
 *   @0x17e2e0 beq 0x17e544 <_ZN8Graphics16Texture_GrabRectEPviiii+0x29c>
 *   @0x17e2e4 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x17e2e8 ldr r3, [pc, #0x260]
 *   @0x17e2ec movw r0, #0xd05
 *   @0x17e2f0 mov r1, #4
 *   @0x17e2f4 ldr r3, [r4, r3]
 *   @0x17e2f8 ldr r3, [r3]
 *   @0x17e2fc blx r3
 *   @0x17e300 ldr r3, [pc, #0x24c]
 *   @0x17e304 ldr r3, [r4, r3]
 *   @0x17e308 str r3, [sp, #0x10]
 *   @0x17e30c ldr r3, [r3]
 *   @0x17e310 blx r3
 *   @0x17e314 ldr r3, [pc, #0x23c]
 *   @0x17e318 ldr r8, [r4, r3]
 *   @0x17e31c ldr r0, [r8]
 *   @0x17e320 cmp r0, #1
 *   @0x17e324 beq 0x17e518 <_ZN8Graphics16Texture_GrabRectEPviiii+0x270>
 *   @0x17e328 ldr r3, [pc, #0x22c]
 *   @0x17e32c add r10, sp, #28
 *   @0x17e330 mov r0, #1
 *   @0x17e334 mov r1, r10
 *   @0x17e338 ldr r3, [r4, r3]
 *   @0x17e33c ldr r3, [r3]
 *   @0x17e340 blx r3
 *   @0x17e344 ldr r1, [pc, #0x214]
 *   @0x17e348 mov r3, #247
 *   @0x17e34c ldr r2, [pc, #0x210]
 *   @0x17e350 ldr r0, [sp, #0x1c]
 *   @0x17e354 ldr r7, [r4, r1]
 *   @0x17e358 add r2, pc, r2
 *   @0x17e35c stm r7, {r2, r3}
 *   @0x17e360 bl 0x1805b4 <_Z20DBG_BIND_FRAMEBUFFERi>
 *   @0x17e364 ldr r3, [r8]
 *   @0x17e368 ldr r12, [pc, #0x1f8]
 *   @0x17e36c cmp r3, #1
 *   @0x17e370 ldrne r12, [pc, #0x1f4]
 *   @0x17e374 ldr r12, [r4, r12]
 *   @0x17e378 mov lr, #0
 *   @0x17e37c ldr r3, [r6, #0x14]
 *   @0x17e380 movw r0, #0x8d40
 *   @0x17e384 str lr, [sp]
 *   @0x17e388 movw r1, #0x8ce0
 *   @0x17e38c ldr r12, [r12]
 *   @0x17e390 movw r2, #0xde1
 *   @0x17e394 blx r12
 *   @0x17e398 mul r0, r5, r9
 *   @0x17e39c ldr r1, [pc, #0x1cc]
 *   @0x17e3a0 mov r2, #70
 *   @0x17e3a4 mov r3, #1
 *   @0x17e3a8 add r1, pc, r1
 *   @0x17e3ac lsl r0, r0, #2
 *   @0x17e3b0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x17e3b4 ldr r2, [sp, #0x10]
 *   @0x17e3b8 ldr r3, [r2]
 *   @0x17e3bc mov r6, r0
 *   @0x17e3c0 blx r3
 *   @0x17e3c4 ldr r12, [pc, #0x1a8]
 *   @0x17e3c8 mov r0, r11
 *   @0x17e3cc mov r3, r5
 *   @0x17e3d0 movw lr, #0x1401
 *   @0x17e3d4 ldr r1, [sp, #0x14]
 *   @0x17e3d8 mov r2, r9
 *   @0x17e3dc ldr r12, [r4, r12]
 *   @0x17e3e0 movw r5, #0x1908
 *   @0x17e3e4 str r6, [sp, #0x8]
 *   @0x17e3e8 str r5, [sp]
 *   @0x17e3ec ldr r12, [r12]
 *   @0x17e3f0 str lr, [sp, #0x4]
 *   @0x17e3f4 blx r12
 *   @0x17e3f8 ldr r0, [r8]
 *   @0x17e3fc cmp r0, #1
 *   @0x17e400 beq 0x17e500 <_ZN8Graphics16Texture_GrabRectEPviiii+0x258>
 *   @0x17e404 ldr r3, [pc, #0x16c]
 *   @0x17e408 mov r1, r10
 *   @0x17e40c mov r0, #1
 *   @0x17e410 ldr r3, [r4, r3]
 *   @0x17e414 ldr r3, [r3]
 *   @0x17e418 blx r3
 *   @0x17e41c ldr r3, [pc, #0x158]
 *   @0x17e420 movw r1, #0x10e
 *   @0x17e424 ldr r2, [pc, #0x154]
 *   @0x17e428 str r1, [r7, #0x4]
 *   @0x17e42c add r2, pc, r2
 *   @0x17e430 str r2, [r7]
 *   @0x17e434 ldr r3, [r4, r3]
 *   @0x17e438 ldr r0, [r3]
 *   @0x17e43c bl 0x1805b4 <_Z20DBG_BIND_FRAMEBUFFERi>
 *   @0x17e440 mov r0, r6
 *   @0x17e444 add sp, sp, #36
 *   @0x17e448 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17e44c ldr r3, [pc, #0x130]
 *   @0x17e450 ldr r3, [r4, r3]
 *   @0x17e454 ldr r3, [r3]
 *   @0x17e458 cmp r3, #1
 *   @0x17e45c beq 0x17e534 <_ZN8Graphics16Texture_GrabRectEPviiii+0x28c>
 *   @0x17e460 add r1, sp, #32
 *   @0x17e464 mov r7, #0
 *   @0x17e468 mov r0, r6
 *   @0x17e46c strb r7, [r1, #-0x4]!
 *   @0x17e470 bl 0x182da0 <_Z22_GetCPUSideTextureDataP7TextureRb>
 *   @0x17e474 subs r8, r0, #0
 *   @0x17e478 beq 0x17e2d8 <_ZN8Graphics16Texture_GrabRectEPviiii+0x30>
 *   @0x17e47c mul r0, r5, r9
 *   @0x17e480 ldr r1, [pc, #0x100]
 *   @0x17e484 mov r2, #70
 *   @0x17e488 mov r3, #1
 *   @0x17e48c add r1, pc, r1
 *   @0x17e490 lsl r0, r0, #2
 *   @0x17e494 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x17e498 ldr r6, [r6, #0x4]
 *   @0x17e49c ldr r2, [sp, #0x14]
 *   @0x17e4a0 cmp r5, r7
 *   @0x17e4a4 lslgt r9, r9, #2
 *   @0x17e4a8 mla r11, r2, r6, r11
 *   @0x17e4ac lslgt r6, r6, #2
 *   @0x17e4b0 add r11, r8, r11, lsl #2
 *   @0x17e4b4 mov r4, r0
 *   @0x17e4b8 movgt r3, r0
 *   @0x17e4bc ble 0x17e4e4 <_ZN8Graphics16Texture_GrabRectEPviiii+0x23c>
 *   @0x17e4c0 mov r0, r3
 *   @0x17e4c4 mov r1, r11
 *   @0x17e4c8 mov r2, r9
 *   @0x17e4cc add r7, r7, #1
 *   @0x17e4d0 bl 0xb65bc <memcpy@plt>
 *   @0x17e4d4 cmp r7, r5
 *   @0x17e4d8 add r11, r11, r6
 *   @0x17e4dc add r3, r0, r9
 *   @0x17e4e0 bne 0x17e4c0 <_ZN8Graphics16Texture_GrabRectEPviiii+0x218>
 *   @0x17e4e4 ldrb r3, [sp, #0x1c]
 *   @0x17e4e8 cmp r3, #0
 *   @0x17e4ec beq 0x17e4f4 <_ZN8Graphics16Texture_GrabRectEPviiii+0x24c>
 *   @0x17e4f0 bl 0x18a518 <_Z11FreePNGFilev>
 *   @0x17e4f4 mov r0, r4
 *   @0x17e4f8 add sp, sp, #36
 *   @0x17e4fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17e500 ldr r3, [pc, #0x84]
 *   @0x17e504 mov r1, r10
 *   @0x17e508 ldr r3, [r4, r3]
 *   @0x17e50c ldr r3, [r3]
 *   @0x17e510 blx r3
 *   @0x17e514 b 0x17e41c <_ZN8Graphics16Texture_GrabRectEPviiii+0x174>
 *   @0x17e518 ldr r3, [pc, #0x70]
 *   @0x17e51c add r10, sp, #28
 *   @0x17e520 mov r1, r10
 *   @0x17e524 ldr r3, [r4, r3]
 *   @0x17e528 ldr r3, [r3]
 *   @0x17e52c blx r3
 *   @0x17e530 b 0x17e344 <_ZN8Graphics16Texture_GrabRectEPviiii+0x9c>
 *   @0x17e534 ldr r3, [r0, #0x14]
 *   @0x17e538 cmn r3, #1
 *   @0x17e53c bne 0x17e2e4 <_ZN8Graphics16Texture_GrabRectEPviiii+0x3c>
 *   @0x17e540 b 0x17e460 <_ZN8Graphics16Texture_GrabRectEPviiii+0x1b8>
 *   @0x17e544 mov r0, #0
 *   @0x17e548 b 0x17e444 <_ZN8Graphics16Texture_GrabRectEPviiii+0x19c>
 *   @0x17e54c eoreq r3, r7, r8, lsl #19
 *   @0x17e550 .word 0xffffbaf8
 *   @0x17e554 .word 0xffffbafc
 *   @0x17e558 .word 0xffffe7b8
 *   @0x17e55c .word 0xffffbc74
 *   @0x17e560 .word 0xffffe81c
 *   @0x17e564 ldrsheq sp, [r12], -r0
 *   @0x17e568 .word 0xffffbb6c
 *   @0x17e56c .word 0xffffbc7c
 *   @0x17e570 andseq r2, r11, r8, lsl #25
 *   @0x17e574 .word 0xffffbaf4
 *   @0x17e578 .word 0xffffbc80
 *   @0x17e57c .word 0xffffe820
 *   @0x17e580 andseq sp, r12, r12, lsl r5
 *   @0x17e584 .word 0xffffc984
 *   @0x17e588 andseq r2, r11, r4, lsr #23
 *   @0x17e58c .word 0xffffbb70
 *   @0x17e590 .word 0xffffbb68
 *
 * ══ §11/42 png_write_IHDR  0x2b12e4  size 748  187 条（0x2b12e4..0x2b15d0）
 * @func 0x2b12e4 0x2b15d0  size 748  187 条
 * 部分覆盖: 本节 187/332 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_error×3 / png_warning×2 / 0x331fe8 / png_write_IHDR+0x118 / 0x1a79bc4 / 0x1aafa24 / 0x1aaf634 / png_write_chunk
 * 字段偏移 top8: 0x14×2 / 0x4×2 / 0x34×1 / 0x8×1 / 0x250×1 / 0x244×1 / 0x208×1 / 0x64×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b12e4 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2b12e8 mov r5, r3
 *   @0x2b12ec mov r11, r2
 *   @0x2b12f0 mov r4, r0
 *   @0x2b12f4 ldr r3, [r3]
 *   @0x2b12f8 ldr.w r8, [sp, #0x60]
 *   @0x2b12fc ldr r2, [r3]
 *   @0x2b1300 ldr.w r10, [sp, #0x6c]
 *   @0x2b1304 str r2, [sp, #0x34]
 *   @0x2b1308 str r3, [sp, #0x14]
 *   @0x2b130c ldr r0, [r2, #8]!
 *   @0x2b1310 ldrb r2, [r2, #0x4]
 *   @0x2b1314 strb.w r2, [sp, #0x20]
 *   @0x2b1318 movs r2, #0x1
 *   @0x2b131c stmdale r2, {r1, r2, r8, r9, r10, r11} ^
 *   @0x2b1320 tbb [pc, r8]
 *   @0x2b1324 asrs r4, r0
 *   @0x2b1328 asrs r1, r5
 *   @0x2b132c subs r3, r5, #0x1
 *   @0x2b1330 bhi 0x2b133c <png_write_IHDR+0x58>
 *   @0x2b1334 movw r3, #0x808b
 *   @0x2b1338 ands r3, r2
 *   @0x2b133c ldr r1, [pc, #0x250]
 *   @0x2b1340 add r1, pc
 *   @0x2b1344 cmp r5, #0x8
 *   @0x2b1348 cmp r5, #0x10
 *   @0x2b134c ldr r1, [pc, #0x244]
 *   @0x2b1350 add r1, pc
 *   @0x2b1354 movwhs pc, #0x386b
 *   @0x2b1358 b 0x2b13a0 <png_write_IHDR+0xbc>
 *   @0x2b135c cmp r3, #0x7
 *   @0x2b1360 lsl.w r3, r2, r3
 *   @0x2b1364 tst.w r3, #0x8b
 *   @0x2b1368 beq 0x2b136e <png_write_IHDR+0x8a>
 *   @0x2b136c b 0x2b13a0 <png_write_IHDR+0xbc>
 *   @0x2b1370 mov r0, r4
 *   @0x2b1374 b 0x2b13ac <png_write_IHDR+0xc8>
 *   @0x2b1378 beq 0x2b1388 <png_write_IHDR+0xa4>
 *   @0x2b137c beq 0x2b1388 <png_write_IHDR+0xa4>
 *   @0x2b1380 mov r0, r4
 *   @0x2b1384 bl 0x2a642c <png_error>
 *   @0x2b1388 movs r3, #0x2
 *   @0x2b138c cmp r5, #0x8
 *   @0x2b1390 cmp r5, #0x10
 *   @0x2b1394 ldr r1, [pc, #0x208]
 *   @0x2b1398 add r1, pc
 *   @0x2b139c movwhs pc, #0x4847
 *   @0x2b13a0 strb.w r3, [r4, #0x1ee]
 *   @0x2b13a4 b 0x2b13b0 <png_write_IHDR+0xcc>
 *   @0x2b13a8 mov r0, r4
 *   @0x2b13ac bl 0x2a642c <png_error>
 *   @0x2b13b0 ldr r3, [sp, #0x64]
 *   @0x2b13b4 ldr r1, [pc, #0x1f0]
 *   @0x2b13b8 add r1, pc
 *   @0x2b13bc .word 0xf8d4f85b
 *   @0x2b13c0 smmlseq r10, r12, r2, r3
 *   @0x2b13c4 bpl 0x2b13da <png_write_IHDR+0xf6>
 *   @0x2b13c8 ldrbeq r3, [r11], #300
 *   @0x2b13cc bmi 0x2b13da <png_write_IHDR+0xf6>
 *   @0x2b13d0 blhs 0x331fe8
 *   @0x2b13d4 bne 0x2b13da <png_write_IHDR+0xf6>
 *   @0x2b13d8 beq 0x2b13e8 <png_write_IHDR+0x104>
 *   @0x2b13dc ldr r1, [pc, #0x1cc]
 *   @0x2b13e0 movs r7, #0x0
 *   @0x2b13e4 bl 0x2a6474 <png_warning>
 *   @0x2b13e8 cmp.w r10, #0x1
 *   @0x2b13ec bls 0x2b13fc <png_write_IHDR+0x118>
 *   @0x2b13f0 mov r0, r4
 *   @0x2b13f4 ldrbtmi r0, [r9], #-2561
 *   @0x2b13f8 bl 0x2a6474 <png_warning>
 *   @0x2b13fc movs r2, #0x0
 *   @0x2b1400 .word 0xf8942304
 *   @0x2b1404 blx 0x1a79bc4 <b2_toiTime+0x1320720>
 *   @0x2b1408 blx 0x1aafa24 <b2_toiTime+0x1356580>
 *   @0x2b140c blx 0x1aaf634 <b2_toiTime+0x1356190>
 *   @0x2b1410 rscslt pc, pc, #565248
 *   @0x2b1414 strb.w r9, [r4, #0x1eb]
 *   @0x2b1418 muls r5, r2, r5
 *   @0x2b141c .word 0xf88481ea
 *   @0x2b1420 .word 0xf884a1e7
 *   @0x2b1424 .word 0xf8c472e4
 *   @0x2b1428 .word 0xf8c4618c
 *   @0x2b142c rsclt r11, sp, #144, #2
 *   @0x2b1430 strb.w r5, [r4, #0x1ed]
 *   @0x2b1434 cmp r5, #0x7
 *   @0x2b1438 lsrs r5, r5, #0x3
 *   @0x2b143c b 0x2b1444 <png_write_IHDR+0x160>
 *   @0x2b1440 adds r5, #0x7
 *   @0x2b1444 str.w r5, [r4, #0x19c]
 *   @0x2b1448 add r5, sp, #0x24
 *   @0x2b144c ldrtmi r2, [r1], -pc, ror #3
 *   @0x2b1450 mov r0, r5
 *   @0x2b1454 .word 0xf8846198
 *   @0x2b1458 .word 0xf7ff91ec
 *   @0x2b145c stcne p14, c15, [r8, #-396]!
 *   @0x2b1460 mov r1, r11
 *   @0x2b1464 movwhs pc, #0xe5f
 *   @0x2b1468 mov r0, r4
 *   @0x2b146c stmdbge r7, {r1, r2, r3, r5, r12, sp}
 *   @0x2b1470 movs r3, #0xd
 *   @0x2b1474 strb.w r9, [sp, #0x2c]
 *   @0x2b1478 strb.w r8, [sp, #0x2d]
 *   @0x2b147c strb.w r7, [sp, #0x2f]
 *   @0x2b1480 strb.w r10, [sp, #0x30]
 *   @0x2b1484 bl 0x2b12bc <png_write_chunk>
 *   @0x2b1488 ldr r3, [pc, #0x128]
 *   @0x2b148c ldrbtmi r4, [r11], #-352
 *   @0x2b1490 ldr r3, [r3]
 *   @0x2b1494 blmi 0x14bd9fc <b2_toiTime+0xd64558>
 *   @0x2b1498 add r3, pc
 *   @0x2b149c str.w r3, [r4, #0x15c]
 *   @0x2b14a0 ldrb.w r3, [r4, #0x1e9]
 *   @0x2b14a4 cbnz r3, 0x2b14c0 <png_write_IHDR+0x1dc>
 *   @0x2b14a8 blhs 0x37dc58 <_ZTS13C_UTF16String+0x14d04>
 *   @0x2b14ac beq 0x2b14b6 <png_write_IHDR+0x1d2>
 *   @0x2b14b0 blhs 0x47dc64 <targetStr+0x2a24>
 *   @0x2b14b4 bhi 0x2b14ba <png_write_IHDR+0x1d6>
 *   @0x2b14b8 b 0x2b14bc <png_write_IHDR+0x1d8>
 *   @0x2b14bc strb.w r3, [r4, #0x1e9]
 *   @0x2b14c0 ldr.w r3, [r4, #0x130]
 *   @0x2b14c4 ands r2, r3, #0x1
 *   @0x2b14c8 bne 0x2b14d8 <png_write_IHDR+0x1f4>
 *   @0x2b14cc stmdbhs r8, {r0, r3, r5, r6, r7, r8, r12}
 *   @0x2b14d0 it ne
 *   @0x2b14d4 str.w r2, [r4, #0x188]
 *   @0x2b14d8 lsls r6, r3, #0x1e
 *   @0x2b14dc movpl.w r2, #0xffffffff
 *   @0x2b14e0 strpl.w r2, [r4, #0x178]
 *   @0x2b14e4 lsls r5, r3, #0x1d
 *   @0x2b14e8 movpl r2, #0x8
 *   @0x2b14ec ldreq r2, [r8, -r4, lsl #3]
 *   @0x2b14f0 add.w r0, r4, #0x138
 *   @0x2b14f4 itt pl
 *   @0x2b14f8 strpl.w r2, [r4, #0x180]
 *   @0x2b14fc lsls r1, r3, #0x1b
 *   @0x2b1500 svclt #0x5c71bc
 *   @0x2b1504 movpl r3, #0x8
 *   @0x2b1508 .word 0xf8d4317c
 *   @0x2b150c movwls r3, #0x184
 *   @0x2b1510 ldr.w r3, [r4, #0x188]
 *   @0x2b1514 str r3, [sp, #0x4]
 *   @0x2b1518 add r3, pc
 *   @0x2b151c movs r3, #0x38
 *   @0x2b1520 ldm r1, {r1, r2, r3}
 *   @0x2b1524 .word 0xb1b8ecc6
 *   @0x2b1528 adds r2, r0, #0x6
 *   @0x2b152c ldr r1, [pc, #0x90]
 *   @0x2b1530 add r1, pc
 *   @0x2b1534 adds r3, r0, #0x2
 *   @0x2b1538 ldr r1, [pc, #0x88]
 *   @0x2b153c add r1, pc
 *   @0x2b1540 adds r0, #0x4
 *   @0x2b1544 ldr r1, [pc, #0x80]
 *   @0x2b1548 add r1, pc
 *   @0x2b154c ldmdbmi pc, {r0, r1, r2, r3, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2b1550 mov r0, r4
 *   @0x2b1554 bl 0x2a642c <png_error>
 *   @0x2b1558 ldr.w r3, [r4, #0x170]
 *   @0x2b155c ldr r1, [sp, #0x14]
 *   @0x2b1560 str.w r3, [r4, #0x144]
 *   @0x2b1564 ldr.w r3, [r4, #0x174]
 *   @0x2b1568 str.w r3, [r4, #0x148]
 *   @0x2b156c movs r3, #0x0
 *   @0x2b1570 movwhs r3, #0x1164
 *   @0x2b1574 str.w r3, [r4, #0x12c]
 *   @0x2b1578 ldr r3, [r1]
 *   @0x2b157c beq 0x2b1582 <png_write_IHDR+0x29e>
 *   @0x2b1580 andlt lr, pc, r10, lsr #16
 *   @0x2b1584 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2b1588 stm r6!, {r1, r5, r6}
 *   @0x2b158c orrs.w r0, r6, sp
 *   @0x2b1590 ldm r5!, {r0, r1, r3, r6, r7}
 *   @0x2b1594 ldm r5, {r0, r5, r6, r7}
 *   @0x2b1598 ldm r5!, {r0, r1, r2, r3, r4, r6, r7}
 *   @0x2b159c ldm r5, {r2, r4, r5, r6, r7}
 *   @0x2b15a0 ldm r6!, {r1, r3}
 *   @0x2b15a4 ldm r6!, {r0, r3, r4}
 *   @0x2b15a8 ldm r6!, {r1, r2, r3, r5}
 *   @0x2b15ac ldm r6!, {r0, r1, r2, r5}
 *   @0x2b15b0 ldm r6!, {r0, r4, r5}
 *   @0x2b15b4 lsls r2, r1, #0x18
 *   @0x2b15b8 lsls r4, r0, #0x18
 *   @0x2b15bc add r2, sp, #0x2c0
 *   @0x2b15c0 ldm r5!, {r3, r4}
 *   @0x2b15c4 ldm r5!, {r1, r6}
 *   @0x2b15c8 ldm r5, {r0, r1, r3, r5, r6}
 *   @0x2b15cc ldm r5!, {r0, r1, r4, r7}
 *
 * ══ §12/42 anon_2b60ec  0x2b60ec  size 748  187 条（0x2b60ec..0x2b63d8）
 * @func 0x2b60ec 0x2b63d8  size 748  187 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×10 / 0xc×5 / 0x1a8×4 / 0x4a×3 / 0x10×3 / 0x180×2 / 0x18c×2 / 0x184×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b60ec push {r3, r4, r5, lr}
 *   @0x2b60f0 mov r4, r0
 *   @0x2b60f4 ldr r5, [r0, #0x180]
 *   @0x2b60f8 ldrb r3, [r5, #0x8]
 *   @0x2b60fc cmp r3, #0
 *   @0x2b6100 bne 0x2b6208 <jpeg_set_marker_processor+0x164>
 *   @0x2b6104 ldrb r3, [r0, #0x4a]
 *   @0x2b6108 cmp r3, #0
 *   @0x2b610c beq 0x2b611c <jpeg_set_marker_processor+0x78>
 *   @0x2b6110 ldr r3, [r0, #0x74]
 *   @0x2b6114 cmp r3, #0
 *   @0x2b6118 beq 0x2b6248 <jpeg_set_marker_processor+0x1a4>
 *   @0x2b611c ldr r3, [r4, #0x19c]
 *   @0x2b6120 mov r0, r4
 *   @0x2b6124 ldr r3, [r3]
 *   @0x2b6128 blx r3
 *   @0x2b612c ldr r3, [r4, #0x188]
 *   @0x2b6130 mov r0, r4
 *   @0x2b6134 ldr r3, [r3, #0x8]
 *   @0x2b6138 blx r3
 *   @0x2b613c ldrb r3, [r4, #0x41]
 *   @0x2b6140 cmp r3, #0
 *   @0x2b6144 bne 0x2b61a4 <jpeg_set_marker_processor+0x100>
 *   @0x2b6148 ldrb r3, [r5, #0x10]
 *   @0x2b614c cmp r3, #0
 *   @0x2b6150 beq 0x2b628c <jpeg_set_marker_processor+0x1e8>
 *   @0x2b6154 ldr r3, [r4, #0x1a0]
 *   @0x2b6158 mov r0, r4
 *   @0x2b615c ldr r3, [r3]
 *   @0x2b6160 blx r3
 *   @0x2b6164 ldrb r3, [r4, #0x4a]
 *   @0x2b6168 cmp r3, #0
 *   @0x2b616c bne 0x2b6274 <jpeg_set_marker_processor+0x1d0>
 *   @0x2b6170 ldrb r1, [r5, #0x8]
 *   @0x2b6174 mov r0, r4
 *   @0x2b6178 ldr r3, [r4, #0x18c]
 *   @0x2b617c cmp r1, #0
 *   @0x2b6180 ldr r3, [r3]
 *   @0x2b6184 movne r1, #3
 *   @0x2b6188 moveq r1, #0
 *   @0x2b618c blx r3
 *   @0x2b6190 ldr r3, [r4, #0x184]
 *   @0x2b6194 mov r0, r4
 *   @0x2b6198 mov r1, #0
 *   @0x2b619c ldr r3, [r3]
 *   @0x2b61a0 blx r3
 *   @0x2b61a4 ldr r3, [r4, #0x8]
 *   @0x2b61a8 cmp r3, #0
 *   @0x2b61ac popeq {r3, r4, r5, pc}
 *   @0x2b61b0 ldr r2, [r5, #0xc]
 *   @0x2b61b4 str r2, [r3, #0xc]
 *   @0x2b61b8 ldrb r1, [r5, #0x8]
 *   @0x2b61bc cmp r1, #0
 *   @0x2b61c0 moveq r1, #1
 *   @0x2b61c4 movne r1, #2
 *   @0x2b61c8 add r2, r1, r2
 *   @0x2b61cc str r2, [r3, #0x10]
 *   @0x2b61d0 ldrb r1, [r4, #0x40]
 *   @0x2b61d4 cmp r1, #0
 *   @0x2b61d8 popeq {r3, r4, r5, pc}
 *   @0x2b61dc ldr r1, [r4, #0x190]
 *   @0x2b61e0 ldrb r1, [r1, #0x11]
 *   @0x2b61e4 cmp r1, #0
 *   @0x2b61e8 popne {r3, r4, r5, pc}
 *   @0x2b61ec ldrb r1, [r4, #0x5a]
 *   @0x2b61f0 cmp r1, #0
 *   @0x2b61f4 moveq r1, #1
 *   @0x2b61f8 movne r1, #2
 *   @0x2b61fc add r2, r1, r2
 *   @0x2b6200 str r2, [r3, #0x10]
 *   @0x2b6204 pop {r3, r4, r5, pc}
 *   @0x2b6208 mov r1, #0
 *   @0x2b620c strb r1, [r5, #0x8]
 *   @0x2b6210 ldr r3, [r0, #0x1a8]
 *   @0x2b6214 ldr r3, [r3]
 *   @0x2b6218 blx r3
 *   @0x2b621c ldr r3, [r4, #0x18c]
 *   @0x2b6220 mov r0, r4
 *   @0x2b6224 mov r1, #2
 *   @0x2b6228 ldr r3, [r3]
 *   @0x2b622c blx r3
 *   @0x2b6230 ldr r3, [r4, #0x184]
 *   @0x2b6234 mov r0, r4
 *   @0x2b6238 mov r1, #2
 *   @0x2b623c ldr r3, [r3]
 *   @0x2b6240 blx r3
 *   @0x2b6244 b 0x2b61a4 <jpeg_set_marker_processor+0x100>
 *   @0x2b6248 ldrb r3, [r0, #0x50]
 *   @0x2b624c cmp r3, #0
 *   @0x2b6250 beq 0x2b62a0 <jpeg_set_marker_processor+0x1fc>
 *   @0x2b6254 ldrb r3, [r0, #0x5a]
 *   @0x2b6258 cmp r3, #0
 *   @0x2b625c beq 0x2b62a0 <jpeg_set_marker_processor+0x1fc>
 *   @0x2b6260 ldr r2, [r5, #0x18]
 *   @0x2b6264 mov r3, #1
 *   @0x2b6268 str r2, [r0, #0x1a8]
 *   @0x2b626c strb r3, [r5, #0x8]
 *   @0x2b6270 b 0x2b611c <jpeg_set_marker_processor+0x78>
 *   @0x2b6274 ldr r3, [r4, #0x1a8]
 *   @0x2b6278 mov r0, r4
 *   @0x2b627c ldrb r1, [r5, #0x8]
 *   @0x2b6280 ldr r3, [r3]
 *   @0x2b6284 blx r3
 *   @0x2b6288 b 0x2b6170 <jpeg_set_marker_processor+0xcc>
 *   @0x2b628c ldr r3, [r4, #0x1a4]
 *   @0x2b6290 mov r0, r4
 *   @0x2b6294 ldr r3, [r3]
 *   @0x2b6298 blx r3
 *   @0x2b629c b 0x2b6154 <jpeg_set_marker_processor+0xb0>
 *   @0x2b62a0 ldrb r3, [r4, #0x58]
 *   @0x2b62a4 cmp r3, #0
 *   @0x2b62a8 ldrne r3, [r5, #0x14]
 *   @0x2b62ac strne r3, [r4, #0x1a8]
 *   @0x2b62b0 bne 0x2b611c <jpeg_set_marker_processor+0x78>
 *   @0x2b62b4 ldr r3, [r4]
 *   @0x2b62b8 mov r2, #46
 *   @0x2b62bc mov r0, r4
 *   @0x2b62c0 str r2, [r3, #0x14]
 *   @0x2b62c4 ldr r3, [r3]
 *   @0x2b62c8 blx r3
 *   @0x2b62cc b 0x2b611c <jpeg_set_marker_processor+0x78>
 *   @0x2b62d0 ldrb r2, [r0, #0x4a]
 *   @0x2b62d4 push {r4, lr}
 *   @0x2b62d8 cmp r2, #0
 *   @0x2b62dc ldr r4, [r0, #0x180]
 *   @0x2b62e0 beq 0x2b62f0 <jpeg_set_marker_processor+0x24c>
 *   @0x2b62e4 ldr r3, [r0, #0x1a8]
 *   @0x2b62e8 ldr r3, [r3, #0x8]
 *   @0x2b62ec blx r3
 *   @0x2b62f0 ldr r3, [r4, #0xc]
 *   @0x2b62f4 add r3, r3, #1
 *   @0x2b62f8 str r3, [r4, #0xc]
 *   @0x2b62fc pop {r4, pc}
 *   @0x2b6300 ldrb r3, [r0, #0x48]
 *   @0x2b6304 cmp r3, #0
 *   @0x2b6308 bne 0x2b6334 <jpeg_set_marker_processor+0x290>
 *   @0x2b630c ldrb r2, [r0, #0x10a]
 *   @0x2b6310 cmp r2, #0
 *   @0x2b6314 bne 0x2b632c <jpeg_set_marker_processor+0x288>
 *   @0x2b6318 ldr r3, [r0, #0x28]
 *   @0x2b631c cmp r3, #3
 *   @0x2b6320 beq 0x2b633c <jpeg_set_marker_processor+0x298>
 *   @0x2b6324 mov r0, r2
 *   @0x2b6328 bx lr
 *   @0x2b632c mov r0, r3
 *   @0x2b6330 bx lr
 *   @0x2b6334 mov r0, #0
 *   @0x2b6338 bx lr
 *   @0x2b633c ldr r3, [r0, #0x24]
 *   @0x2b6340 cmp r3, #3
 *   @0x2b6344 bne 0x2b6324 <jpeg_set_marker_processor+0x280>
 *   @0x2b6348 ldr r3, [r0, #0x2c]
 *   @0x2b634c cmp r3, #2
 *   @0x2b6350 bne 0x2b6324 <jpeg_set_marker_processor+0x280>
 *   @0x2b6354 ldr r3, [r0, #0x64]
 *   @0x2b6358 cmp r3, #3
 *   @0x2b635c bne 0x2b6324 <jpeg_set_marker_processor+0x280>
 *   @0x2b6360 ldr r3, [r0, #0xc4]
 *   @0x2b6364 ldr r1, [r3, #0x8]
 *   @0x2b6368 cmp r1, #2
 *   @0x2b636c bne 0x2b6324 <jpeg_set_marker_processor+0x280>
 *   @0x2b6370 ldr r1, [r3, #0x5c]
 *   @0x2b6374 cmp r1, #1
 *   @0x2b6378 bne 0x2b6324 <jpeg_set_marker_processor+0x280>
 *   @0x2b637c ldr r1, [r3, #0xb0]
 *   @0x2b6380 cmp r1, #1
 *   @0x2b6384 bne 0x2b6324 <jpeg_set_marker_processor+0x280>
 *   @0x2b6388 ldr r2, [r3, #0xc]
 *   @0x2b638c cmp r2, #2
 *   @0x2b6390 bgt 0x2b6334 <jpeg_set_marker_processor+0x290>
 *   @0x2b6394 ldr r2, [r3, #0x60]
 *   @0x2b6398 cmp r2, #1
 *   @0x2b639c bne 0x2b6334 <jpeg_set_marker_processor+0x290>
 *   @0x2b63a0 ldr r2, [r3, #0xb4]
 *   @0x2b63a4 cmp r2, #1
 *   @0x2b63a8 bne 0x2b6334 <jpeg_set_marker_processor+0x290>
 *   @0x2b63ac ldr r1, [r0, #0x118]
 *   @0x2b63b0 ldr r2, [r3, #0x24]
 *   @0x2b63b4 cmp r2, r1
 *   @0x2b63b8 bne 0x2b6334 <jpeg_set_marker_processor+0x290>
 *   @0x2b63bc ldr r1, [r3, #0x78]
 *   @0x2b63c0 cmp r2, r1
 *   @0x2b63c4 bne 0x2b6334 <jpeg_set_marker_processor+0x290>
 *   @0x2b63c8 ldr r0, [r3, #0xcc]
 *   @0x2b63cc subs r3, r2, r0
 *   @0x2b63d0 rsbs r0, r3, #0
 *   @0x2b63d4 adcs r0, r0, r3
 *
 * ══ §13/42 F_PhysicsCreatePrismaticJoint(RValue&, CInstance*, CInstance*, int, RValue*)  0x14f4a8  size 744  186 条（0x14f4a8..0x14f790）
 * @func 0x14f4a8 0x14f790  size 744  186 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x14f548→0x54298c, 0x14f6a0→0x54298c
 * 调用序列: YYGetFloat(RValue const*, int)×8 / YYGetInt32(RValue const*, int)×4 / Error_Show_Action(char const*, bool)×4 / YYGetBool(RValue const*, int)×3 / Object_GetInstance(int, CInstance*, CInstance*)×2 / 0xb65b0×2 / 0xb65c8×2 / CPhysicsWorld::CreatePrismaticJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, float, float, bool, float, float, bool, bool)
 * 字段偏移 top8: 0x3c×3 / 0xc×2 / 0x4×2 / 0x14c×2 / 0x84×2 / 0xb4×2 / 0x28×2 / 0x2c×2
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14f4a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x14f4ac sub sp, sp, #340
 *   @0x14f4b0 ldr r9, [pc, #0x2bc]
 *   @0x14f4b4 mov r7, r2
 *   @0x14f4b8 ldr r12, [pc, #0x2b8]
 *   @0x14f4bc mov r3, #0
 *   @0x14f4c0 add r9, pc, r9
 *   @0x14f4c4 ldr r4, [sp, #0x178]
 *   @0x14f4c8 mov r5, r0
 *   @0x14f4cc mov r8, r1
 *   @0x14f4d0 ldr r6, [r9, r12]
 *   @0x14f4d4 mov r0, r3
 *   @0x14f4d8 mov r1, r3
 *   @0x14f4dc movt r0, #0xbff0
 *   @0x14f4e0 str r3, [r5, #0xc]
 *   @0x14f4e4 ldr r2, [r6]
 *   @0x14f4e8 str r0, [r5, #0x4]
 *   @0x14f4ec mov r0, r4
 *   @0x14f4f0 str r3, [r5]
 *   @0x14f4f4 str r2, [sp, #0x14c]
 *   @0x14f4f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14f4fc mov r1, r8
 *   @0x14f500 mov r2, r7
 *   @0x14f504 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_>
 *   @0x14f508 subs r10, r0, #0
 *   @0x14f50c beq 0x14f6e0 <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x238>
 *   @0x14f510 mov r1, #1
 *   @0x14f514 mov r0, r4
 *   @0x14f518 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14f51c mov r1, r8
 *   @0x14f520 mov r2, r7
 *   @0x14f524 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_>
 *   @0x14f528 subs r8, r0, #0
 *   @0x14f52c beq 0x14f728 <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x280>
 *   @0x14f530 ldr r7, [r10, #0x84]
 *   @0x14f534 cmp r7, #0
 *   @0x14f538 beq 0x14f6a0 <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0x14f53c ldr r8, [r8, #0x84]
 *   @0x14f540 cmp r8, #0
 *   @0x14f544 beq 0x14f6a0 <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0x14f548 ldr r3, [pc, #0x22c]
 *   @0x14f54c ldr r3, [r9, r3]
 *   @0x14f550 ldr r3, [r3]
 *   @0x14f554 ldr r9, [r3, #0xb4]
 *   @0x14f558 cmp r9, #0
 *   @0x14f55c beq 0x14f6cc <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x224>
 *   @0x14f560 mov r1, #2
 *   @0x14f564 mov r0, r4
 *   @0x14f568 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f56c mov r1, #3
 *   @0x14f570 mov r3, r0
 *   @0x14f574 mov r0, r4
 *   @0x14f578 str r3, [sp, #0x28]
 *   @0x14f57c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f580 mov r1, #4
 *   @0x14f584 mov r12, r0
 *   @0x14f588 mov r0, r4
 *   @0x14f58c str r12, [sp, #0x2c]
 *   @0x14f590 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f594 mov r1, #5
 *   @0x14f598 str r0, [sp, #0x34]
 *   @0x14f59c mov r0, r4
 *   @0x14f5a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f5a4 mov r1, #6
 *   @0x14f5a8 str r0, [sp, #0x38]
 *   @0x14f5ac mov r0, r4
 *   @0x14f5b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f5b4 mov r1, #7
 *   @0x14f5b8 str r0, [sp, #0x3c]
 *   @0x14f5bc mov r0, r4
 *   @0x14f5c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f5c4 mov r1, #8
 *   @0x14f5c8 str r0, [sp, #0x40]
 *   @0x14f5cc mov r0, r4
 *   @0x14f5d0 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x14f5d4 mov r1, #9
 *   @0x14f5d8 mov r2, r0
 *   @0x14f5dc mov r0, r4
 *   @0x14f5e0 str r2, [sp, #0x30]
 *   @0x14f5e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f5e8 mov r1, #10
 *   @0x14f5ec str r0, [sp, #0x44]
 *   @0x14f5f0 mov r0, r4
 *   @0x14f5f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f5f8 mov r1, #11
 *   @0x14f5fc mov r11, r0
 *   @0x14f600 mov r0, r4
 *   @0x14f604 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x14f608 mov r1, #12
 *   @0x14f60c mov r10, r0
 *   @0x14f610 mov r0, r4
 *   @0x14f614 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x14f618 ldr r1, [sp, #0x34]
 *   @0x14f61c ldr r2, [sp, #0x30]
 *   @0x14f620 ldr r12, [sp, #0x2c]
 *   @0x14f624 str r1, [sp, #0x4]
 *   @0x14f628 ldr r1, [sp, #0x38]
 *   @0x14f62c str r2, [sp, #0x14]
 *   @0x14f630 ldr r2, [sp, #0x44]
 *   @0x14f634 str r1, [sp, #0x8]
 *   @0x14f638 ldr r1, [sp, #0x3c]
 *   @0x14f63c str r2, [sp, #0x18]
 *   @0x14f640 mov r2, r8
 *   @0x14f644 ldr r3, [sp, #0x28]
 *   @0x14f648 str r1, [sp, #0xc]
 *   @0x14f64c ldr r1, [sp, #0x40]
 *   @0x14f650 str r12, [sp]
 *   @0x14f654 str r11, [sp, #0x1c]
 *   @0x14f658 str r1, [sp, #0x10]
 *   @0x14f65c mov r1, r7
 *   @0x14f660 str r10, [sp, #0x20]
 *   @0x14f664 str r0, [sp, #0x24]
 *   @0x14f668 mov r0, r9
 *   @0x14f66c bl 0x239164 <_ZN13CPhysicsWorld20CreatePrismaticJointEP14CPhysicsObjectS1_ffffffbffbb>
 *   @0x14f670 vmov s15, r0
 *   @0x14f674 vcvt.f64.s32 d7, s15
 *   @0x14f678 vmov r0, r1, d7
 *   @0x14f67c vmov r2, s14
 *   @0x14f680 mov r3, r1
 *   @0x14f684 stm r5, {r2, r3}
 *   @0x14f688 ldr r2, [sp, #0x14c]
 *   @0x14f68c ldr r3, [r6]
 *   @0x14f690 cmp r2, r3
 *   @0x14f694 bne 0x14f770 <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x2c8>
 *   @0x14f698 add sp, sp, #340
 *   @0x14f69c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x14f6a0 ldr r3, [pc, #0xd4]
 *   @0x14f6a4 ldr r3, [r9, r3]
 *   @0x14f6a8 ldr r3, [r3]
 *   @0x14f6ac ldr r3, [r3, #0xb4]
 *   @0x14f6b0 cmp r3, #0
 *   @0x14f6b4 beq 0x14f6cc <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x224>
 *   @0x14f6b8 ldr r0, [pc, #0xc0]
 *   @0x14f6bc mov r1, #0
 *   @0x14f6c0 add r0, pc, r0
 *   @0x14f6c4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14f6c8 b 0x14f688 <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x14f6cc ldr r0, [pc, #0xb0]
 *   @0x14f6d0 mov r1, #0
 *   @0x14f6d4 add r0, pc, r0
 *   @0x14f6d8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14f6dc b 0x14f688 <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x14f6e0 add r5, sp, #76
 *   @0x14f6e4 mov r1, r10
 *   @0x14f6e8 mov r2, #256
 *   @0x14f6ec mov r0, r5
 *   @0x14f6f0 bl 0xb65b0 <memset@plt>
 *   @0x14f6f4 mov r1, r10
 *   @0x14f6f8 mov r0, r4
 *   @0x14f6fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14f700 ldr r2, [pc, #0x80]
 *   @0x14f704 mov r1, #256
 *   @0x14f708 add r2, pc, r2
 *   @0x14f70c mov r3, r0
 *   @0x14f710 mov r0, r5
 *   @0x14f714 bl 0xb65c8 <snprintf@plt>
 *   @0x14f718 mov r0, r5
 *   @0x14f71c mov r1, r10
 *   @0x14f720 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14f724 b 0x14f688 <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x14f728 add r5, sp, #76
 *   @0x14f72c mov r1, r8
 *   @0x14f730 mov r2, #256
 *   @0x14f734 mov r0, r5
 *   @0x14f738 bl 0xb65b0 <memset@plt>
 *   @0x14f73c mov r0, r4
 *   @0x14f740 mov r1, #1
 *   @0x14f744 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14f748 ldr r2, [pc, #0x3c]
 *   @0x14f74c mov r1, #256
 *   @0x14f750 add r2, pc, r2
 *   @0x14f754 mov r3, r0
 *   @0x14f758 mov r0, r5
 *   @0x14f75c bl 0xb65c8 <snprintf@plt>
 *   @0x14f760 mov r0, r5
 *   @0x14f764 mov r1, r8
 *   @0x14f768 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14f76c b 0x14f688 <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x14f770 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x14f774 mlaeq r10, r0, r7, r2
 *   @0x14f778 .word 0xffffbd00
 *   @0x14f77c .word 0xffffbcd8
 *   @0x14f780 andseq r5, pc, r12, lsl r8
 *   @0x14f784 andseq r4, pc, r0, asr r7
 *   @0x14f788 mulseq pc, r8, r6
 *   @0x14f78c andseq r5, pc, r0, asr r6
 *
 * ══ §14/42 GR_Window_Views_Get_ID(int, int)  0x17a3b8  size 744  179 条（0x17a3b8..0x17a6a0）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x17a3b8 0x17a6a0  size 744  179 条
 * 部分覆盖: 本节 179/186 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17a3e0→0x54298c, 0x17a3f8→0x498cd8, 0x17a4ec→0x5428e8, 0x17a57c→0x3f50a8, 0x17a588→0x3f510c, 0x17a5a0→0x3f50d8, 0x17a5a8→0x3f50a4, 0x17a5b8→0x3f5108
 * 调用序列: GR_Window_Views_Get_ID(int, int)+0xd4×4 / Get_FullScreenOffset(int&, int&, int&, int&)×2 / GR_Window_View_Convert(int, int, int, int&, int&)
 * 字段偏移 top8: 0x3c×2 / 0x298×1 / 0x294×1 / 0x280×1 / 0x5d0×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 56 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17a3b8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17a3bc sub sp, sp, #68
 *   @0x17a3c0 add r3, sp, #44
 *   @0x17a3c4 mov r7, r0
 *   @0x17a3c8 mov r8, r1
 *   @0x17a3cc add r0, sp, #32
 *   @0x17a3d0 add r1, sp, #36
 *   @0x17a3d4 add r2, sp, #40
 *   @0x17a3d8 ldr r11, [pc, #0x298]
 *   @0x17a3dc bl 0x179a00 <_Z20Get_FullScreenOffsetRiS_S_S_>
 *   @0x17a3e0 ldr r3, [pc, #0x294]
 *   @0x17a3e4 add r11, pc, r11
 *   @0x17a3e8 ldr r6, [r11, r3]
 *   @0x17a3ec ldr r1, [r6]
 *   @0x17a3f0 cmp r1, #0
 *   @0x17a3f4 beq 0x17a55c <_Z22GR_Window_Views_Get_IDii+0x1a4>
 *   @0x17a3f8 ldr r2, [pc, #0x280]
 *   @0x17a3fc mov r9, #0
 *   @0x17a400 mov r3, #31
 *   @0x17a404 ldr r5, [r11, r2]
 *   @0x17a408 mov r2, r5
 *   @0x17a40c ldrb r0, [r2, #0x5d0]
 *   @0x17a410 cmp r0, #0
 *   @0x17a414 beq 0x17a43c <_Z22GR_Window_Views_Get_IDii+0x84>
 *   @0x17a418 cmp r3, #7
 *   @0x17a41c ldrls r0, [r1, #0xc4]
 *   @0x17a420 movhi r0, #0
 *   @0x17a424 ldrb r12, [r0]
 *   @0x17a428 cmp r12, #0
 *   @0x17a42c beq 0x17a43c <_Z22GR_Window_Views_Get_IDii+0x84>
 *   @0x17a430 ldr r0, [r0, #0x3c]
 *   @0x17a434 cmn r0, #1
 *   @0x17a438 addeq r9, r9, #1
 *   @0x17a43c sub r3, r3, #1
 *   @0x17a440 sub r2, r2, #48
 *   @0x17a444 cmn r3, #1
 *   @0x17a448 sub r1, r1, #4
 *   @0x17a44c bne 0x17a40c <_Z22GR_Window_Views_Get_IDii+0x54>
 *   @0x17a450 cmp r9, #0
 *   @0x17a454 beq 0x17a55c <_Z22GR_Window_Views_Get_IDii+0x1a4>
 *   @0x17a458 add r3, sp, #48
 *   @0x17a45c add r5, r5, #1520
 *   @0x17a460 str r3, [sp, #0x8]
 *   @0x17a464 add r10, sp, #24
 *   @0x17a468 add r3, sp, #52
 *   @0x17a46c add r9, sp, #28
 *   @0x17a470 str r3, [sp, #0xc]
 *   @0x17a474 mov r4, #31
 *   @0x17a478 add r3, sp, #56
 *   @0x17a47c str r3, [sp, #0x10]
 *   @0x17a480 add r3, sp, #60
 *   @0x17a484 str r3, [sp, #0x14]
 *   @0x17a488 b 0x17a49c <_Z22GR_Window_Views_Get_IDii+0xe4>
 *   @0x17a48c sub r4, r4, #1
 *   @0x17a490 sub r5, r5, #48
 *   @0x17a494 cmn r4, #1
 *   @0x17a498 beq 0x17a55c <_Z22GR_Window_Views_Get_IDii+0x1a4>
 *   @0x17a49c ldrb r0, [r5, #-0x20]
 *   @0x17a4a0 cmp r0, #0
 *   @0x17a4a4 beq 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4>
 *   @0x17a4a8 cmp r4, #7
 *   @0x17a4ac ldr r3, [r6]
 *   @0x17a4b0 addls r2, r4, #18
 *   @0x17a4b4 movhi r3, #0
 *   @0x17a4b8 ldrls r3, [r3, r2, lsl #2]
 *   @0x17a4bc ldrb r2, [r3]
 *   @0x17a4c0 cmp r2, #0
 *   @0x17a4c4 beq 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4>
 *   @0x17a4c8 ldr r3, [r3, #0x3c]
 *   @0x17a4cc cmn r3, #1
 *   @0x17a4d0 bne 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4>
 *   @0x17a4d4 mov r3, r10
 *   @0x17a4d8 str r9, [sp]
 *   @0x17a4dc mov r0, r4
 *   @0x17a4e0 mov r1, r7
 *   @0x17a500 vldr s13, [sp, #24]
 *   @0x17a504 vcvt.f32.s32 s15, s13
 *   @0x17a508 vldr s14, [r5, #-28]
 *   @0x17a50c vcmpe.f32 s15, s14
 *   @0x17a510 vmrs APSR_nzcv, fpscr
 *   @0x17a514 blt 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4>
 *   @0x17a518 vldr s13, [r5, #-20]
 *   @0x17a51c vadd.f32 s14, s14, s13
 *   @0x17a520 vcmpe.f32 s15, s14
 *   @0x17a524 vmrs APSR_nzcv, fpscr
 *   @0x17a528 bpl 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4>
 *   @0x17a52c vldr s12, [sp, #28]
 *   @0x17a530 vcvt.f32.s32 s15, s12
 *   @0x17a534 vldr s14, [r5, #-24]
 *   @0x17a538 vcmpe.f32 s15, s14
 *   @0x17a53c vmrs APSR_nzcv, fpscr
 *   @0x17a540 blt 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4>
 *   @0x17a544 vldr s13, [r5, #-16]
 *   @0x17a548 vadd.f32 s14, s14, s13
 *   @0x17a54c vcmpe.f32 s15, s14
 *   @0x17a550 vmrs APSR_nzcv, fpscr
 *   @0x17a554 bpl 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4>
 *   @0x17a558 b 0x17a670 <_Z22GR_Window_Views_Get_IDii+0x2b8>
 *   @0x17a55c mvn r0, #0
 *   @0x17a560 add sp, sp, #68
 *   @0x17a564 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17a568 add r0, sp, #48
 *   @0x17a56c add r1, sp, #52
 *   @0x17a570 add r2, sp, #56
 *   @0x17a574 add r3, sp, #60
 *   @0x17a578 bl 0x179a00 <_Z20Get_FullScreenOffsetRiS_S_S_>
 *   @0x17a57c ldr r2, [pc, #0x104]
 *   @0x17a580 ldr r3, [sp, #0x30]
 *   @0x17a584 vldr s14, [r5, #-12]
 *   @0x17a588 ldr r1, [pc, #0xfc]
 *   @0x17a58c ldr r2, [r11, r2]
 *   @0x17a590 ldr r0, [r11, r1]
 *   @0x17a594 vldr s12, [r0]
 *   @0x17a598 ldr r2, [r2]
 *   @0x17a59c vcvt.f32.s32 s12, s12
 *   @0x17a5a0 ldr r1, [pc, #0xe8]
 *   @0x17a5a4 sub r2, r2, r3, lsl #1
 *   @0x17a5a8 ldr r3, [pc, #0xe4]
 *   @0x17a5ac ldr r1, [r11, r1]
 *   @0x17a5b0 vldr s15, [r1]
 *   @0x17a5b4 vmov s13, r2
 *   @0x17a5b8 ldr r2, [pc, #0xd8]
 *   @0x17a5bc ldr r3, [r11, r3]
 *   @0x17a5c0 vcvt.f32.s32 s13, s13
 *   @0x17a5c4 ldr r1, [pc, #0xd0]
 *   @0x17a5c8 ldr r2, [r11, r2]
 *   @0x17a5cc ldr r1, [r11, r1]
 *   @0x17a5d0 vldr s11, [r1]
 *   @0x17a5d4 ldr r2, [r2]
 *   @0x17a5d8 ldr r1, [r3]
 *   @0x17a5dc ldr r3, [sp, #0x34]
 *   @0x17a5e0 vdiv.f32 s13, s12, s13
 *   @0x17a5e4 vmov s12, r7
 *   @0x17a5e8 vdiv.f32 s15, s13, s15
 *   @0x17a5ec vcvt.f32.s32 s13, s12
 *   @0x17a5f0 vmul.f32 s15, s13, s15
 *   @0x17a5f4 vcvt.s32.f32 s15, s15
 *   @0x17a5f8 vcvt.f32.s32 s15, s15
 *   @0x17a5fc vcmpe.f32 s15, s14
 *   @0x17a600 vmrs APSR_nzcv, fpscr
 *   @0x17a604 blt 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4>
 *   @0x17a608 vldr s13, [r5, #-4]
 *   @0x17a60c vadd.f32 s14, s14, s13
 *   @0x17a610 vcmpe.f32 s15, s14
 *   @0x17a614 vmrs APSR_nzcv, fpscr
 *   @0x17a618 bpl 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4>
 *   @0x17a61c sub r1, r1, r3, lsl #1
 *   @0x17a620 vmov s14, r2
 *   @0x17a624 vmov s12, r8
 *   @0x17a628 vmov s15, r1
 *   @0x17a62c vcvt.f32.s32 s13, s14
 *   @0x17a630 vldr s14, [r5, #-8]
 *   @0x17a634 vcvt.f32.s32 s15, s15
 *   @0x17a638 vdiv.f32 s15, s13, s15
 *   @0x17a63c vdiv.f32 s11, s15, s11
 *   @0x17a640 vcvt.f32.s32 s15, s12
 *   @0x17a644 vmul.f32 s15, s15, s11
 *   @0x17a648 vcvt.s32.f32 s15, s15
 *   @0x17a64c vcvt.f32.s32 s15, s15
 *   @0x17a650 vcmpe.f32 s15, s14
 *   @0x17a654 vmrs APSR_nzcv, fpscr
 *   @0x17a658 blt 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4>
 *   @0x17a65c vldr s13, [r5]
 *   @0x17a660 vadd.f32 s14, s14, s13
 *   @0x17a664 vcmpe.f32 s15, s14
 *   @0x17a668 vmrs APSR_nzcv, fpscr
 *   @0x17a66c bpl 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4>
 *   @0x17a670 mov r0, r4
 *   @0x17a674 b 0x17a560 <_Z22GR_Window_Views_Get_IDii+0x1a8>
 *   @0x17a678 eoreq r7, r7, r12, ror #16
 *   @0x17a67c .word 0xffffbcd8
 *   @0x17a680 .word 0xffffe6b0
 *   @0x17a684 .word 0xffffbcd4
 *   @0x17a688 .word 0xffffe6b8
 *   @0x17a68c .word 0xffffdf38
 *   @0x17a690 .word 0xffffe6bc
 *   @0x17a694 .word 0xffffe6c0
 *   @0x17a698 .word 0xffffdf40
 *   @0x17a69c .word 0xffffe6c4
 *
 * ══ §15/42 CSprite::PreciseCollisionRectangle(int, tagYYRECT*, int, int, float, float, float, tagYYRECT*)  0x1e4c24  size 744  186 条（0x1e4c24..0x1e4f0c）
 * @func 0x1e4c24 0x1e4f0c  size 744  186 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSprite::PreciseCollisionRectangle(int, tagYYRECT*, int, int, float, float, float, tagYYRECT*)+0x214×3 / 0xb6910×2 / CSprite::PreciseCollisionRectangle(int, tagYYRECT*, int, int, float, float, float, tagYYRECT*)+0x1fc×2 / CSprite::PreciseCollisionRectangle(int, tagYYRECT*, int, int, float, float, float, tagYYRECT*)+0x234×2 / CSprite::UnpackWADMask(int) / __aeabi_idivmod / 0xb6580 / 0xb658c
 * 字段偏移 top8: 0x4×9 / 0x8×2 / 0xc×2 / 0x1c×2 / 0x20×2 / 0x40×2 / 0x58×1 / 0x68×1
 * VFP 指令 50 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e4c24 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e4c28 vpush {d8, d9, d10, d11, d12}
 *   @0x1e4c2c sub sp, sp, #12
 *   @0x1e4c30 vldr s23, [sp, #92]
 *   @0x1e4c34 mov r4, r0
 *   @0x1e4c38 mov r8, r2
 *   @0x1e4c3c str r3, [sp]
 *   @0x1e4c40 mov r7, r1
 *   @0x1e4c44 ldr r6, [sp, #0x58]
 *   @0x1e4c48 vldr s24, [sp, #96]
 *   @0x1e4c4c vldr s16, [sp, #100]
 *   @0x1e4c50 ldr r5, [sp, #0x68]
 *   @0x1e4c54 bl 0x1e3994 <_ZN7CSprite13UnpackWADMaskEi>
 *   @0x1e4c58 ldrb r3, [r4, #0x31]
 *   @0x1e4c5c cmp r3, #0
 *   @0x1e4c60 moveq r0, #1
 *   @0x1e4c64 beq 0x1e4e3c <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x218>
 *   @0x1e4c68 ldr r3, [r4, #0x18]
 *   @0x1e4c6c cmp r3, #0
 *   @0x1e4c70 ble 0x1e4e38 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x214>
 *   @0x1e4c74 ldr r11, [r4, #0x3c]
 *   @0x1e4c78 mov r0, r7
 *   @0x1e4c7c mov r1, r11
 *   @0x1e4c80 bl 0x318dec <__aeabi_idivmod>
 *   @0x1e4c84 vmov.f32 s15, #1.000000e+00
 *   @0x1e4c88 ldr r3, [r8]
 *   @0x1e4c8c ldr r7, [r5]
 *   @0x1e4c90 ldr r2, [r8, #0x4]
 *   @0x1e4c94 vcmp.f32 s23, s15
 *   @0x1e4c98 subs r9, r1, #0
 *   @0x1e4c9c ldr r1, [r8, #0x8]
 *   @0x1e4ca0 addlt r9, r9, r11
 *   @0x1e4ca4 ldr r11, [r5, #0x8]
 *   @0x1e4ca8 cmp r7, r3
 *   @0x1e4cac movlt r7, r3
 *   @0x1e4cb0 ldr r3, [r8, #0xc]
 *   @0x1e4cb4 ldr r8, [r5, #0x4]
 *   @0x1e4cb8 cmp r11, r1
 *   @0x1e4cbc movge r11, r1
 *   @0x1e4cc0 ldr r5, [r5, #0xc]
 *   @0x1e4cc4 cmp r8, r2
 *   @0x1e4cc8 movlt r8, r2
 *   @0x1e4ccc str r11, [sp, #0x4]
 *   @0x1e4cd0 cmp r5, r3
 *   @0x1e4cd4 movge r5, r3
 *   @0x1e4cd8 vmrs APSR_nzcv, fpscr
 *   @0x1e4cdc vcmp.f32 s24, s15
 *   @0x1e4ce0 movne r3, #0
 *   @0x1e4ce4 moveq r3, #1
 *   @0x1e4ce8 vmrs APSR_nzcv, fpscr
 *   @0x1e4cec movne r3, #0
 *   @0x1e4cf0 andeq r3, r3, #1
 *   @0x1e4cf4 cmp r3, #0
 *   @0x1e4cf8 beq 0x1e4d10 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0xec>
 *   @0x1e4cfc vabs.f32 s14, s16
 *   @0x1e4d00 vldr s15, [pc, #504]
 *   @0x1e4d04 vcmpe.f32 s14, s15
 *   @0x1e4d08 vmrs APSR_nzcv, fpscr
 *   @0x1e4d0c bmi 0x1e4e48 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x224>
 *   @0x1e4d10 vldr s19, [pc, #492]
 *   @0x1e4d14 vnmul.f32 s15, s16, s19
 *   @0x1e4d18 vldr s18, [pc, #488]
 *   @0x1e4d1c vdiv.f32 s15, s15, s18
 *   @0x1e4d20 vmul.f32 s16, s16, s19
 *   @0x1e4d24 vmov r0, s15
 *   @0x1e4d28 bl 0xb6580 <sinf@plt>
 *   @0x1e4d2c vdiv.f32 s16, s16, s18
 *   @0x1e4d30 vmov s17, r0
 *   @0x1e4d34 vmov r0, s16
 *   @0x1e4d38 bl 0xb658c <cosf@plt>
 *   @0x1e4d3c ldr r3, [sp, #0x4]
 *   @0x1e4d40 cmp r3, r7
 *   @0x1e4d44 vmov s18, r0
 *   @0x1e4d48 blt 0x1e4e38 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x214>
 *   @0x1e4d4c lsl r9, r9, #3
 *   @0x1e4d50 cmp r5, r8
 *   @0x1e4d54 blt 0x1e4e28 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x204>
 *   @0x1e4d58 ldr r3, [sp]
 *   @0x1e4d5c vldr s15, [r4, #36]
 *   @0x1e4d60 vcvt.f32.s32 s22, s15
 *   @0x1e4d64 mov r11, r8
 *   @0x1e4d68 rsb r2, r3, r7
 *   @0x1e4d6c vmov s14, r2
 *   @0x1e4d70 vcvt.f32.s32 s20, s14
 *   @0x1e4d74 vldr s14, [r4, #40]
 *   @0x1e4d78 vmul.f32 s21, s18, s20
 *   @0x1e4d7c vmul.f32 s20, s17, s20
 *   @0x1e4d80 vcvt.f32.s32 s19, s14
 *   @0x1e4d84 rsb r2, r6, r11
 *   @0x1e4d88 add r11, r11, #1
 *   @0x1e4d8c vmov s16, r2
 *   @0x1e4d90 vcvt.f32.s32 s16, s16
 *   @0x1e4d94 vmov.f32 s15, s21
 *   @0x1e4d98 vmla.f32 s15, s16, s17
 *   @0x1e4d9c vdiv.f32 s15, s15, s23
 *   @0x1e4da0 vadd.f32 s15, s15, s22
 *   @0x1e4da4 vmov r0, s15
 *   @0x1e4da8 bl 0xb6910 <floorf@plt>
 *   @0x1e4dac vmov.f32 s15, s20
 *   @0x1e4db0 vnmls.f32 s15, s18, s16
 *   @0x1e4db4 vdiv.f32 s15, s15, s24
 *   @0x1e4db8 vmov s14, r0
 *   @0x1e4dbc vadd.f32 s15, s15, s19
 *   @0x1e4dc0 vcvt.s32.f32 s14, s14
 *   @0x1e4dc4 vmov r0, s15
 *   @0x1e4dc8 vmov r10, s14
 *   @0x1e4dcc bl 0xb6910 <floorf@plt>
 *   @0x1e4dd0 cmp r10, #0
 *   @0x1e4dd4 vmov s15, r0
 *   @0x1e4dd8 blt 0x1e4e20 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x1fc>
 *   @0x1e4ddc ldr r2, [r4, #0x1c]
 *   @0x1e4de0 cmp r10, r2
 *   @0x1e4de4 bge 0x1e4e20 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x1fc>
 *   @0x1e4de8 vcvt.s32.f32 s15, s15
 *   @0x1e4dec vmov r1, s15
 *   @0x1e4df0 cmp r1, #0
 *   @0x1e4df4 blt 0x1e4e20 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x1fc>
 *   @0x1e4df8 ldr r0, [r4, #0x20]
 *   @0x1e4dfc cmp r1, r0
 *   @0x1e4e00 bge 0x1e4e20 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x1fc>
 *   @0x1e4e04 ldr r0, [r4, #0x40]
 *   @0x1e4e08 add r0, r0, r9
 *   @0x1e4e0c ldr r0, [r0, #0x4]
 *   @0x1e4e10 mla r2, r2, r1, r0
 *   @0x1e4e14 ldrb r0, [r2, r10]
 *   @0x1e4e18 cmp r0, #0
 *   @0x1e4e1c bne 0x1e4e3c <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x218>
 *   @0x1e4e20 cmp r5, r11
 *   @0x1e4e24 bge 0x1e4d84 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x160>
 *   @0x1e4e28 ldr r2, [sp, #0x4]
 *   @0x1e4e2c add r7, r7, #1
 *   @0x1e4e30 cmp r7, r2
 *   @0x1e4e34 ble 0x1e4d50 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x12c>
 *   @0x1e4e38 mov r0, #0
 *   @0x1e4e3c add sp, sp, #12
 *   @0x1e4e40 vpop {d8, d9, d10, d11, d12}
 *   @0x1e4e44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e4e48 cmp r11, r7
 *   @0x1e4e4c blt 0x1e4e38 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x214>
 *   @0x1e4e50 lsl r9, r9, #3
 *   @0x1e4e54 rsb r6, r6, r8
 *   @0x1e4e58 cmp r5, r8
 *   @0x1e4e5c blt 0x1e4e98 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x274>
 *   @0x1e4e60 ldr r2, [sp]
 *   @0x1e4e64 ldr r3, [r4, #0x24]
 *   @0x1e4e68 rsb r1, r2, r7
 *   @0x1e4e6c ldr r2, [r4, #0x28]
 *   @0x1e4e70 adds r1, r1, r3
 *   @0x1e4e74 bmi 0x1e4e98 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x274>
 *   @0x1e4e78 ldr r12, [r4, #0x1c]
 *   @0x1e4e7c add r2, r6, r2
 *   @0x1e4e80 mov r3, r8
 *   @0x1e4e84 cmp r12, r1
 *   @0x1e4e88 bgt 0x1e4eac <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x288>
 *   @0x1e4e8c add r3, r3, #1
 *   @0x1e4e90 cmp r5, r3
 *   @0x1e4e94 bge 0x1e4e8c <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x268>
 *   @0x1e4e98 ldr r2, [sp, #0x4]
 *   @0x1e4e9c add r7, r7, #1
 *   @0x1e4ea0 cmp r7, r2
 *   @0x1e4ea4 ble 0x1e4e58 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x234>
 *   @0x1e4ea8 b 0x1e4e38 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x214>
 *   @0x1e4eac cmp r2, #0
 *   @0x1e4eb0 add r3, r3, #1
 *   @0x1e4eb4 blt 0x1e4ee0 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x2bc>
 *   @0x1e4eb8 ldr r0, [r4, #0x20]
 *   @0x1e4ebc cmp r2, r0
 *   @0x1e4ec0 bge 0x1e4ee0 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x2bc>
 *   @0x1e4ec4 ldr r0, [r4, #0x40]
 *   @0x1e4ec8 add r0, r0, r9
 *   @0x1e4ecc ldr r0, [r0, #0x4]
 *   @0x1e4ed0 mla r0, r12, r2, r0
 *   @0x1e4ed4 ldrb r0, [r0, r1]
 *   @0x1e4ed8 cmp r0, #0
 *   @0x1e4edc bne 0x1e4e3c <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x218>
 *   @0x1e4ee0 cmp r5, r3
 *   @0x1e4ee4 add r2, r2, #1
 *   @0x1e4ee8 bge 0x1e4eac <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x288>
 *   @0x1e4eec ldr r2, [sp, #0x4]
 *   @0x1e4ef0 add r7, r7, #1
 *   @0x1e4ef4 cmp r7, r2
 *   @0x1e4ef8 ble 0x1e4e58 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x234>
 *   @0x1e4efc b 0x1e4e38 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x214>
 *   @0x1e4f00 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^
 *   @0x1e4f04 ldrdmi r0, r1, [r9], #-251
 *   @0x1e4f08 teqmi r4, #0
 *
 * ══ §16/42 Sprite_Replace(int, char const*, int, bool, bool, bool, bool, int, int)  0x1ef5a8  size 744  186 条（0x1ef5a8..0x1ef890）
 * @func 0x1ef5a8 0x1ef890  size 744  186 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1ef5f0→0x7530d8, 0x1ef638→0x7530d0, 0x1ef678→0x533c54, 0x1ef750→0x7530d0, 0x1ef7a0→0x7530dc, 0x1ef7c8→0x7530e0
 * 调用序列: operator new(unsigned int)×3 / 0xb65e0×2 / CSprite::CSprite()×2 / Sprite_Replace(int, char const*, int, bool, bool, bool, bool, int, int)+0x140 / LoadSave::HTTP_Get(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*) / LoadSave::SaveFileExists(char const*) / LoadSave::BundleFileExists(char const*) / LoadSave::_GetBundleFileName(char*, int, char const*)
 * 字段偏移 top8: 0x4×8 / 0x2×8 / 0x20×8 / 0x1c×8 / 0x24×2 / 0x42c×2 / 0x464×2 / 0x468×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ef5a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1ef5ac subs r5, r0, #0
 *   @0x1ef5b0 ldr r4, [pc, #0x2ac]
 *   @0x1ef5b4 sub sp, sp, #1072
 *   @0x1ef5b8 ldr r0, [pc, #0x2a8]
 *   @0x1ef5bc mov r8, r3
 *   @0x1ef5c0 add r4, pc, r4
 *   @0x1ef5c4 sub sp, sp, #4
 *   @0x1ef5c8 mov r9, r2
 *   @0x1ef5cc mov r6, r1
 *   @0x1ef5d0 ldr r0, [r4, r0]
 *   @0x1ef5d4 ldrb r7, [sp, #0x458]
 *   @0x1ef5d8 ldrb r11, [sp, #0x45c]
 *   @0x1ef5dc ldr r3, [r0]
 *   @0x1ef5e0 str r0, [sp, #0x24]
 *   @0x1ef5e4 ldrb r10, [sp, #0x460]
 *   @0x1ef5e8 str r3, [sp, #0x42c]
 *   @0x1ef5ec blt 0x1ef6e8 <_Z14Sprite_ReplaceiPKcibbbbii+0x140>
 *   @0x1ef5f0 ldr r3, [pc, #0x274]
 *   @0x1ef5f4 ldr r3, [r4, r3]
 *   @0x1ef5f8 ldr r3, [r3]
 *   @0x1ef5fc cmp r5, r3
 *   @0x1ef600 bge 0x1ef6e8 <_Z14Sprite_ReplaceiPKcibbbbii+0x140>
 *   @0x1ef604 ldr r0, [pc, #0x264]
 *   @0x1ef608 mov r2, #7
 *   @0x1ef60c add r0, pc, r0
 *   @0x1ef610 bl 0xb65e0 <strncmp@plt>
 *   @0x1ef614 cmp r0, #0
 *   @0x1ef618 beq 0x1ef638 <_Z14Sprite_ReplaceiPKcibbbbii+0x90>
 *   @0x1ef61c ldr r0, [pc, #0x250]
 *   @0x1ef620 mov r1, r6
 *   @0x1ef624 mov r2, #8
 *   @0x1ef628 add r0, pc, r0
 *   @0x1ef62c bl 0xb65e0 <strncmp@plt>
 *   @0x1ef630 cmp r0, #0
 *   @0x1ef634 bne 0x1ef710 <_Z14Sprite_ReplaceiPKcibbbbii+0x168>
 *   @0x1ef638 ldr r3, [pc, #0x238]
 *   @0x1ef63c ldr r3, [r4, r3]
 *   @0x1ef640 ldr r2, [r3, #0x4]
 *   @0x1ef644 ldr r2, [r2, r5, lsl #2]
 *   @0x1ef648 cmp r2, #0
 *   @0x1ef64c beq 0x1ef808 <_Z14Sprite_ReplaceiPKcibbbbii+0x260>
 *   @0x1ef650 mov r0, #20
 *   @0x1ef654 mov r12, #0
 *   @0x1ef658 str r12, [sp, #0x20]
 *   @0x1ef65c bl 0x27c524 <_Znwj>
 *   @0x1ef660 cmp r7, #0
 *   @0x1ef664 ldr r1, [sp, #0x464]
 *   @0x1ef668 ldr r2, [sp, #0x468]
 *   @0x1ef66c movne r7, #2
 *   @0x1ef670 moveq r7, #0
 *   @0x1ef674 cmp r11, #0
 *   @0x1ef678 ldr r3, [pc, #0x1fc]
 *   @0x1ef67c orr r8, r7, r8
 *   @0x1ef680 mov r7, #1
 *   @0x1ef684 movne r11, #4
 *   @0x1ef688 moveq r11, #0
 *   @0x1ef68c cmp r10, #0
 *   @0x1ef690 orr r8, r8, r11
 *   @0x1ef694 movne r10, #8
 *   @0x1ef698 moveq r10, #0
 *   @0x1ef69c orr r10, r8, r10
 *   @0x1ef6a0 mov lr, r0
 *   @0x1ef6a4 str r5, [r0]
 *   @0x1ef6a8 str r10, [r0, #0x10]
 *   @0x1ef6ac str r9, [r0, #0x4]
 *   @0x1ef6b0 mov r0, r6
 *   @0x1ef6b4 str r1, [lr, #0x8]
 *   @0x1ef6b8 mov r1, #5
 *   @0x1ef6bc str r2, [lr, #0xc]
 *   @0x1ef6c0 ldr r2, [pc, #0x1b8]
 *   @0x1ef6c4 ldr r5, [r4, r3]
 *   @0x1ef6c8 ldr r3, [pc, #0x1b4]
 *   @0x1ef6cc strb r7, [r5]
 *   @0x1ef6d0 ldr r2, [r4, r2]
 *   @0x1ef6d4 ldr r3, [r4, r3]
 *   @0x1ef6d8 str lr, [sp]
 *   @0x1ef6dc bl 0x18fc68 <_ZN8LoadSave8HTTP_GetEPKciPFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_>
 *   @0x1ef6e0 ldr r12, [sp, #0x20]
 *   @0x1ef6e4 b 0x1ef6ec <_Z14Sprite_ReplaceiPKcibbbbii+0x144>
 *   @0x1ef6e8 mov r12, #0
 *   @0x1ef6ec mov r0, r12
 *   @0x1ef6f0 ldr r12, [sp, #0x24]
 *   @0x1ef6f4 ldr r2, [sp, #0x42c]
 *   @0x1ef6f8 ldr r3, [r12]
 *   @0x1ef6fc cmp r2, r3
 *   @0x1ef700 bne 0x1ef860 <_Z14Sprite_ReplaceiPKcibbbbii+0x2b8>
 *   @0x1ef704 add sp, sp, #1072
 *   @0x1ef708 add sp, sp, #4
 *   @0x1ef70c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1ef710 mov r0, r6
 *   @0x1ef714 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x1ef718 cmp r0, #0
 *   @0x1ef71c bne 0x1ef7e8 <_Z14Sprite_ReplaceiPKcibbbbii+0x240>
 *   @0x1ef720 mov r0, r6
 *   @0x1ef724 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x1ef728 cmp r0, #0
 *   @0x1ef72c moveq r12, r0
 *   @0x1ef730 beq 0x1ef6ec <_Z14Sprite_ReplaceiPKcibbbbii+0x144>
 *   @0x1ef734 add r3, sp, #44
 *   @0x1ef738 mov r2, r6
 *   @0x1ef73c mov r1, #1024
 *   @0x1ef740 str r3, [sp, #0x1c]
 *   @0x1ef744 mov r0, r3
 *   @0x1ef748 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x1ef74c ldr r3, [sp, #0x1c]
 *   @0x1ef750 ldr r2, [pc, #0x120]
 *   @0x1ef754 ldr r6, [r4, r2]
 *   @0x1ef758 ldr r2, [r6, #0x4]
 *   @0x1ef75c ldr r0, [r2, r5, lsl #2]
 *   @0x1ef760 cmp r0, #0
 *   @0x1ef764 beq 0x1ef830 <_Z14Sprite_ReplaceiPKcibbbbii+0x288>
 *   @0x1ef768 mov r1, r3
 *   @0x1ef76c ldr r12, [sp, #0x468]
 *   @0x1ef770 ldr r3, [sp, #0x464]
 *   @0x1ef774 mov r2, r9
 *   @0x1ef778 str r7, [sp]
 *   @0x1ef77c eor r7, r7, #1
 *   @0x1ef780 str r12, [sp, #0x10]
 *   @0x1ef784 str r3, [sp, #0xc]
 *   @0x1ef788 mov r3, r8
 *   @0x1ef78c str r11, [sp, #0x4]
 *   @0x1ef790 str r7, [sp, #0x14]
 *   @0x1ef794 str r10, [sp, #0x8]
 *   @0x1ef798 bl 0x1e7270 <_ZN7CSprite12LoadFromFileEPKcibbbbiib>
 *   @0x1ef79c ldr r1, [r6, #0x4]
 *   @0x1ef7a0 ldr r3, [pc, #0xe0]
 *   @0x1ef7a4 mov r2, r5
 *   @0x1ef7a8 ldr r1, [r1, r5, lsl #2]
 *   @0x1ef7ac str r5, [r1, #0x60]
 *   @0x1ef7b0 ldr r3, [r4, r3]
 *   @0x1ef7b4 ldr r3, [r3]
 *   @0x1ef7b8 ldr lr, [r3, r5, lsl #2]
 *   @0x1ef7bc str lr, [r1, #0x5c]
 *   @0x1ef7c0 ldr r1, [r3, r5, lsl #2]
 *   @0x1ef7c4 mov r12, r0
 *   @0x1ef7c8 ldr r0, [pc, #0xbc]
 *   @0x1ef7cc ldr r0, [r4, r0]
 *   @0x1ef7d0 str r12, [sp, #0x20]
 *   @0x1ef7d4 bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i>
 *   @0x1ef7d8 mov r0, r5
 *   @0x1ef7dc bl 0x130cac <_Z20MarkInstancesAsDirtyi>
 *   @0x1ef7e0 ldr r12, [sp, #0x20]
 *   @0x1ef7e4 b 0x1ef6ec <_Z14Sprite_ReplaceiPKcibbbbii+0x144>
 *   @0x1ef7e8 add r3, sp, #44
 *   @0x1ef7ec mov r2, r6
 *   @0x1ef7f0 mov r1, #1024
 *   @0x1ef7f4 str r3, [sp, #0x1c]
 *   @0x1ef7f8 mov r0, r3
 *   @0x1ef7fc bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x1ef800 ldr r3, [sp, #0x1c]
 *   @0x1ef804 b 0x1ef750 <_Z14Sprite_ReplaceiPKcibbbbii+0x1a8>
 *   @0x1ef808 mov r0, #136
 *   @0x1ef80c str r3, [sp, #0x1c]
 *   @0x1ef810 bl 0x27c524 <_Znwj>
 *   @0x1ef814 str r0, [sp, #0x20]
 *   @0x1ef818 bl 0x1e761c <_ZN7CSpriteC2Ev>
 *   @0x1ef81c ldr r3, [sp, #0x1c]
 *   @0x1ef820 ldr r2, [sp, #0x20]
 *   @0x1ef824 ldr r3, [r3, #0x4]
 *   @0x1ef828 str r2, [r3, r5, lsl #2]
 *   @0x1ef82c b 0x1ef650 <_Z14Sprite_ReplaceiPKcibbbbii+0xa8>
 *   @0x1ef830 mov r0, #136
 *   @0x1ef834 str r3, [sp, #0x1c]
 *   @0x1ef838 bl 0x27c524 <_Znwj>
 *   @0x1ef83c str r0, [sp, #0x20]
 *   @0x1ef840 bl 0x1e761c <_ZN7CSpriteC2Ev>
 *   @0x1ef844 ldr r2, [sp, #0x20]
 *   @0x1ef848 ldr r1, [r6, #0x4]
 *   @0x1ef84c ldr r3, [sp, #0x1c]
 *   @0x1ef850 str r2, [r1, r5, lsl #2]
 *   @0x1ef854 ldr r2, [r6, #0x4]
 *   @0x1ef858 ldr r0, [r2, r5, lsl #2]
 *   @0x1ef85c b 0x1ef768 <_Z14Sprite_ReplaceiPKcibbbbii+0x1c0>
 *   @0x1ef860 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1ef864 mlaeq r0, r0, r6, r2
 *   @0x1ef868 .word 0xffffbd00
 *   @0x1ef86c .word 0xfffff1c0
 *   @0x1ef870 ldrsbeq r1, [r4], -r4
 *   @0x1ef874 andseq r1, r4, r0, asr #9
 *   @0x1ef878 .word 0xfffff1b8
 *   @0x1ef87c .word 0xffffbd04
 *   @0x1ef880 .word 0xfffff1c8
 *   @0x1ef884 .word 0xfffff1cc
 *   @0x1ef888 .word 0xfffff1bc
 *   @0x1ef88c .word 0xfffff1c4
 *
 * ══ §17/42 Audio_CreateEmitter()  0x2169ac  size 744  186 条（0x2169ac..0x216c94）
 * @func 0x2169ac 0x216c94  size 744  186 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)×2 / CEmitter::CEmitter()×2 / MemoryManager::Free(void const*)×2 / CEmitter::Reset()×2 / Audio_CreateEmitter()+0x294 / Audio_CreateEmitter()+0x19c / CEmitter::~CEmitter() / operator delete(void*)
 * 字段偏移 top8: 0x44×12 / 0x40×5 / 0x18×5 / 0x2×2 / 0xc×2 / 0x29c×1 / 0x284×1 / 0x274×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2169ac ldr r3, [pc, #0x29c]
 *   @0x2169b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2169b4 ldr r3, [pc, r3]
 *   @0x2169b8 sub sp, sp, #20
 *   @0x2169bc ldrb r3, [r3]
 *   @0x2169c0 cmp r3, #0
 *   @0x2169c4 beq 0x216c48 <_Z19Audio_CreateEmitterv+0x29c>
 *   @0x2169c8 ldr r3, [pc, #0x284]
 *   @0x2169cc add r3, pc, r3
 *   @0x2169d0 ldr r7, [r3, #0x40]
 *   @0x2169d4 cmp r7, #0
 *   @0x2169d8 ble 0x216c40 <_Z19Audio_CreateEmitterv+0x294>
 *   @0x2169dc ldr r10, [pc, #0x274]
 *   @0x2169e0 mov r5, #0
 *   @0x2169e4 ldr r9, [pc, #0x270]
 *   @0x2169e8 mov r4, r5
 *   @0x2169ec ldr r8, [pc, #0x26c]
 *   @0x2169f0 add r10, pc, r10
 *   @0x2169f4 add r9, pc, r9
 *   @0x2169f8 mov r3, r7
 *   @0x2169fc add r8, pc, r8
 *   @0x216a00 b 0x216a38 <_Z19Audio_CreateEmitterv+0x8c>
 *   @0x216a04 bl 0x27c524 <_Znwj>
 *   @0x216a08 mov r6, r0
 *   @0x216a0c bl 0x2157c8 <_ZN8CEmitterC2Ev>
 *   @0x216a10 ldr r3, [r10, #0x44]
 *   @0x216a14 str r6, [r3, r5]
 *   @0x216a18 add r5, r5, #4
 *   @0x216a1c ldrb r3, [r6, #0x18]
 *   @0x216a20 cmp r3, #0
 *   @0x216a24 beq 0x216a64 <_Z19Audio_CreateEmitterv+0xb8>
 *   @0x216a28 add r4, r4, #1
 *   @0x216a2c cmp r4, r7
 *   @0x216a30 beq 0x216a7c <_Z19Audio_CreateEmitterv+0xd0>
 *   @0x216a34 ldr r3, [r8, #0x40]
 *   @0x216a38 cmp r4, r3
 *   @0x216a3c mov r0, #60
 *   @0x216a40 bge 0x216a04 <_Z19Audio_CreateEmitterv+0x58>
 *   @0x216a44 ldr r3, [r9, #0x44]
 *   @0x216a48 ldr r6, [r3, r5]
 *   @0x216a4c cmp r6, #0
 *   @0x216a50 beq 0x216a04 <_Z19Audio_CreateEmitterv+0x58>
 *   @0x216a54 ldrb r3, [r6, #0x18]
 *   @0x216a58 add r5, r5, #4
 *   @0x216a5c cmp r3, #0
 *   @0x216a60 bne 0x216a28 <_Z19Audio_CreateEmitterv+0x7c>
 *   @0x216a64 mov r7, r4
 *   @0x216a68 mov r3, #1
 *   @0x216a6c strb r3, [r6, #0x18]
 *   @0x216a70 mov r0, r7
 *   @0x216a74 add sp, sp, #20
 *   @0x216a78 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x216a7c ldr r3, [pc, #0x1e0]
 *   @0x216a80 add r3, pc, r3
 *   @0x216a84 ldr r2, [r3, #0x40]
 *   @0x216a88 add r8, r7, #8
 *   @0x216a8c cmp r8, r2
 *   @0x216a90 moveq r8, r2
 *   @0x216a94 beq 0x216ba0 <_Z19Audio_CreateEmitterv+0x1f4>
 *   @0x216a98 cmp r8, #0
 *   @0x216a9c bne 0x216b64 <_Z19Audio_CreateEmitterv+0x1b8>
 *   @0x216aa0 ldr r9, [pc, #0x1c0]
 *   @0x216aa4 add r9, pc, r9
 *   @0x216aa8 ldr r3, [r9, #0x44]
 *   @0x216aac cmp r3, #0
 *   @0x216ab0 beq 0x216c24 <_Z19Audio_CreateEmitterv+0x278>
 *   @0x216ab4 cmp r2, #0
 *   @0x216ab8 ble 0x216b48 <_Z19Audio_CreateEmitterv+0x19c>
 *   @0x216abc ldr r11, [pc, #0x1a8]
 *   @0x216ac0 mov r4, r8
 *   @0x216ac4 ldr r12, [pc, #0x1a4]
 *   @0x216ac8 mov r10, r8
 *   @0x216acc add r11, pc, r11
 *   @0x216ad0 add r12, pc, r12
 *   @0x216ad4 ldr r0, [r3]
 *   @0x216ad8 movw r2, #0xfeee
 *   @0x216adc movt r2, #0xfeee
 *   @0x216ae0 movw r1, #0xfeee
 *   @0x216ae4 cmp r0, r2
 *   @0x216ae8 movt r1, #0xfeee
 *   @0x216aec lsl r6, r4, #2
 *   @0x216af0 beq 0x216b38 <_Z19Audio_CreateEmitterv+0x18c>
 *   @0x216af4 ldr r5, [r3, r4, lsl #2]
 *   @0x216af8 add r2, r3, r6
 *   @0x216afc cmp r5, #0
 *   @0x216b00 mov r0, r5
 *   @0x216b04 beq 0x216b38 <_Z19Audio_CreateEmitterv+0x18c>
 *   @0x216b08 ldr r3, [r5]
 *   @0x216b0c cmp r3, r1
 *   @0x216b10 beq 0x216b30 <_Z19Audio_CreateEmitterv+0x184>
 *   @0x216b14 str r12, [sp, #0xc]
 *   @0x216b18 bl 0x21580c <_ZN8CEmitterD2Ev>
 *   @0x216b1c mov r0, r5
 *   @0x216b20 bl 0x27d1d0 <_ZdlPv>
 *   @0x216b24 ldr r12, [sp, #0xc]
 *   @0x216b28 ldr r2, [r12, #0x44]
 *   @0x216b2c add r2, r2, r6
 *   @0x216b30 str r10, [r2]
 *   @0x216b34 ldr r3, [r11, #0x44]
 *   @0x216b38 ldr r2, [r9, #0x40]
 *   @0x216b3c add r4, r4, #1
 *   @0x216b40 cmp r4, r2
 *   @0x216b44 blt 0x216ad4 <_Z19Audio_CreateEmitterv+0x128>
 *   @0x216b48 mov r0, r3
 *   @0x216b4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x216b50 ldr r3, [pc, #0x11c]
 *   @0x216b54 mov r2, #0
 *   @0x216b58 add r3, pc, r3
 *   @0x216b5c str r2, [r3, #0x44]
 *   @0x216b60 b 0x216b94 <_Z19Audio_CreateEmitterv+0x1e8>
 *   @0x216b64 lsls r1, r8, #2
 *   @0x216b68 beq 0x216c18 <_Z19Audio_CreateEmitterv+0x26c>
 *   @0x216b6c ldr r4, [pc, #0x104]
 *   @0x216b70 mov r3, #0
 *   @0x216b74 ldr r2, [pc, #0x100]
 *   @0x216b78 add r4, pc, r4
 *   @0x216b7c str r3, [sp]
 *   @0x216b80 add r2, pc, r2
 *   @0x216b84 mov r3, #135
 *   @0x216b88 ldr r0, [r4, #0x44]
 *   @0x216b8c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x216b90 str r0, [r4, #0x44]
 *   @0x216b94 ldr r3, [pc, #0xe4]
 *   @0x216b98 add r3, pc, r3
 *   @0x216b9c str r8, [r3, #0x40]
 *   @0x216ba0 cmp r7, r8
 *   @0x216ba4 lslge r5, r7, #2
 *   @0x216ba8 blt 0x216be8 <_Z19Audio_CreateEmitterv+0x23c>
 *   @0x216bac mov r0, #60
 *   @0x216bb0 bl 0x27c524 <_Znwj>
 *   @0x216bb4 mov r4, r0
 *   @0x216bb8 bl 0x2157c8 <_ZN8CEmitterC2Ev>
 *   @0x216bbc ldr r3, [pc, #0xc0]
 *   @0x216bc0 mov r0, r4
 *   @0x216bc4 add r3, pc, r3
 *   @0x216bc8 ldr r3, [r3, #0x44]
 *   @0x216bcc str r4, [r3, r5]
 *   @0x216bd0 bl 0x215774 <_ZN8CEmitter5ResetEv>
 *   @0x216bd4 mov r3, #1
 *   @0x216bd8 strb r3, [r4, #0x18]
 *   @0x216bdc mov r0, r7
 *   @0x216be0 add sp, sp, #20
 *   @0x216be4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x216be8 ldr r3, [pc, #0x98]
 *   @0x216bec lsl r5, r7, #2
 *   @0x216bf0 add r3, pc, r3
 *   @0x216bf4 ldr r3, [r3, #0x44]
 *   @0x216bf8 ldr r4, [r3, r7, lsl #2]
 *   @0x216bfc cmp r4, #0
 *   @0x216c00 beq 0x216bac <_Z19Audio_CreateEmitterv+0x200>
 *   @0x216c04 mov r0, r4
 *   @0x216c08 bl 0x215774 <_ZN8CEmitter5ResetEv>
 *   @0x216c0c mov r3, #1
 *   @0x216c10 strb r3, [r4, #0x18]
 *   @0x216c14 b 0x216bdc <_Z19Audio_CreateEmitterv+0x230>
 *   @0x216c18 ldr r3, [pc, #0x6c]
 *   @0x216c1c add r3, pc, r3
 *   @0x216c20 ldr r3, [r3, #0x44]
 *   @0x216c24 mov r0, r3
 *   @0x216c28 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x216c2c ldr r3, [pc, #0x5c]
 *   @0x216c30 mov r2, #0
 *   @0x216c34 add r3, pc, r3
 *   @0x216c38 str r2, [r3, #0x44]
 *   @0x216c3c b 0x216b94 <_Z19Audio_CreateEmitterv+0x1e8>
 *   @0x216c40 mov r2, r7
 *   @0x216c44 b 0x216a88 <_Z19Audio_CreateEmitterv+0xdc>
 *   @0x216c48 mvn r7, #0
 *   @0x216c4c b 0x216a70 <_Z19Audio_CreateEmitterv+0xc4>
 *   @0x216c50 andseq r8, sp, r12, ror r3
 *   @0x216c54 subseq lr, r3, r8, asr #17
 *   @0x216c58 subseq lr, r3, r4, lsr #17
 *   @0x216c5c subseq lr, r3, r0, lsr #17
 *   @0x216c60 .word 0x0053e898
 *   @0x216c64 subseq lr, r3, r4, lsl r8
 *   @0x216c68 ldrsheq lr, [r3], #-112
 *   @0x216c6c subseq lr, r3, r8, asr #15
 *   @0x216c70 subseq lr, r3, r4, asr #15
 *   @0x216c74 subseq lr, r3, r12, lsr r7
 *   @0x216c78 subseq lr, r3, r12, lsl r7
 *   @0x216c7c andseq r6, r3, r0, ror r7
 *   @0x216c80 ldrsheq lr, [r3], #-108
 *   @0x216c84 ldrsbeq lr, [r3], #-96
 *   @0x216c88 subseq lr, r3, r4, lsr #13
 *   @0x216c8c subseq lr, r3, r8, ror r6
 *   @0x216c90 subseq lr, r3, r0, ror #12
 *
 * ══ §18/42 Audio_PlaySound(int, double, int)  0x21b5d8  size 744  176 条（0x21b5d8..0x21b8c0）｜其中 10 条已由别的卡落锚，本节不再重复
 * @func 0x21b600 0x21b8c0  size 704  176 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21b5ec→0x755363, 0x21b608→0x755314, 0x21b628→0x755324, 0x21b674→0x75531c, 0x21b688→0x755318, 0x21b698→0x3f52d4, 0x21b6ec→0x3f52cc, 0x21b79c→0x75531c
 * 调用序列: 0xb6a78×3 / 0xb6a54×2 / 0xb6b2c×2 / Audio_GetSound(int) / CAudioGroupMan::IsGroupLoaded(int) / Audio_GetSoundSourceToPlay(int, float) / Audio_PlaySound(int, double, int)+0x1c4 / 0xb6a6c
 * 字段偏移 top8: 0x2×7 / 0xc×5 / 0x4c×2 / 0x14×2 / 0x10×2 / 0xc0×2 / 0x2a0×1 / 0x29c×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21b600 cmp r3, #0
 *   @0x21b604 bne 0x21b7d4 <_Z15Audio_PlaySoundidi+0x1fc>
 *   @0x21b608 ldr r3, [pc, #0x284]
 *   @0x21b60c ldr r3, [r5, r3]
 *   @0x21b610 ldrb r3, [r3]
 *   @0x21b614 cmp r3, #0
 *   @0x21b618 beq 0x21b7d4 <_Z15Audio_PlaySoundidi+0x1fc>
 *   @0x21b61c bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x21b620 subs r9, r0, #0
 *   @0x21b624 beq 0x21b82c <_Z15Audio_PlaySoundidi+0x254>
 *   @0x21b628 ldr r3, [pc, #0x268]
 *   @0x21b62c ldr r1, [r9, #0x4c]
 *   @0x21b630 ldr r0, [r5, r3]
 *   @0x21b634 bl 0x21e1e0 <_ZN14CAudioGroupMan13IsGroupLoadedEi>
 *   @0x21b638 cmp r0, #0
 *   @0x21b63c beq 0x21b854 <_Z15Audio_PlaySoundidi+0x27c>
 *   @0x21b640 vcvt.f32.f64 s16, d8
 *   @0x21b644 mov r0, r7
 *   @0x21b648 vmov r1, s16
 *   @0x21b64c bl 0x21addc <_Z26Audio_GetSoundSourceToPlayif>
 *   @0x21b650 sub r2, r7, #199680
 *   @0x21b654 movw r3, #0x869f
 *   @0x21b658 sub r2, r2, #320
 *   @0x21b65c movt r3, #0x1
 *   @0x21b660 cmp r2, r3
 *   @0x21b664 mov r4, r0
 *   @0x21b668 bls 0x21b79c <_Z15Audio_PlaySoundidi+0x1c4>
 *   @0x21b66c cmp r0, #0
 *   @0x21b670 beq 0x21b7d4 <_Z15Audio_PlaySoundidi+0x1fc>
 *   @0x21b674 ldr r3, [pc, #0x220]
 *   @0x21b678 ldr r6, [r5, r3]
 *   @0x21b67c bl 0xb6a54 <alGetError@plt>
 *   @0x21b680 subs r2, r0, #0
 *   @0x21b684 bne 0x21b808 <_Z15Audio_PlaySoundidi+0x230>
 *   @0x21b688 ldr r3, [pc, #0x210]
 *   @0x21b68c mov r1, #0
 *   @0x21b690 ldr r2, [sp, #0x38]
 *   @0x21b694 mov lr, #1065353216
 *   @0x21b698 ldr r0, [pc, #0x204]
 *   @0x21b69c mov r8, #0
 *   @0x21b6a0 cmp r2, r1
 *   @0x21b6a4 ldr r2, [r5, r3]
 *   @0x21b6a8 str lr, [r4, #0x24]
 *   @0x21b6ac str r7, [r4, #0x18]
 *   @0x21b6b0 ldr r3, [r2]
 *   @0x21b6b4 str r1, [r4, #0x2c]
 *   @0x21b6b8 add r12, r3, #1
 *   @0x21b6bc str r12, [r2]
 *   @0x21b6c0 str r3, [r4, #0x14]
 *   @0x21b6c4 ldr r3, [r5, r0]
 *   @0x21b6c8 vstr s16, [r4, #28]
 *   @0x21b6cc strble r1, [r4, #0x4]
 *   @0x21b6d0 movw r1, #0x1023
 *   @0x21b6d4 ldr r7, [r4, #0x10]
 *   @0x21b6d8 ldr r3, [r3]
 *   @0x21b6dc ldr r2, [r6]
 *   @0x21b6e0 str r3, [r4, #0x34]
 *   @0x21b6e4 movgt r3, #1
 *   @0x21b6e8 strbgt r3, [r4, #0x4]
 *   @0x21b6ec ldr r3, [pc, #0x1b4]
 *   @0x21b6f0 ldr r0, [r2, r7, lsl #2]
 *   @0x21b6f4 ldr r3, [r5, r3]
 *   @0x21b6f8 ldr r2, [r3]
 *   @0x21b6fc bl 0xb6a78 <alSourcef@plt>
 *   @0x21b700 ldr r3, [r6]
 *   @0x21b704 movw r1, #0x100a
 *   @0x21b708 ldr r2, [r9, #0x4]
 *   @0x21b70c ldr r0, [r3, r7, lsl #2]
 *   @0x21b710 bl 0xb6a78 <alSourcef@plt>
 *   @0x21b714 ldr r3, [r6]
 *   @0x21b718 movw r1, #0x1003
 *   @0x21b71c ldr r2, [r9, #0x8]
 *   @0x21b720 ldr r0, [r3, r7, lsl #2]
 *   @0x21b724 bl 0xb6a78 <alSourcef@plt>
 *   @0x21b728 ldr r3, [r6]
 *   @0x21b72c movw r1, #0x202
 *   @0x21b730 mov r2, #1
 *   @0x21b734 ldr r0, [r3, r7, lsl #2]
 *   @0x21b738 bl 0xb6a6c <alSourcei@plt>
 *   @0x21b73c ldr r0, [r6]
 *   @0x21b740 mov r2, r8
 *   @0x21b744 movw r1, #0x1004
 *   @0x21b748 mov r3, r8
 *   @0x21b74c ldr r0, [r0, r7, lsl #2]
 *   @0x21b750 str r8, [sp]
 *   @0x21b754 bl 0xb6b2c <alSource3f@plt>
 *   @0x21b758 ldr r3, [r6]
 *   @0x21b75c mov r2, r8
 *   @0x21b760 movw r1, #0x1006
 *   @0x21b764 ldr r0, [r3, r7, lsl #2]
 *   @0x21b768 mov r3, r8
 *   @0x21b76c str r8, [sp]
 *   @0x21b770 bl 0xb6b2c <alSource3f@plt>
 *   @0x21b774 mov r1, r4
 *   @0x21b778 mov r0, r9
 *   @0x21b77c bl 0x2173d8 <_Z21Audio_StartSoundNoiseP12cAudio_SoundP6CNoise>
 *   @0x21b780 bl 0xb6a54 <alGetError@plt>
 *   @0x21b784 subs r2, r0, #0
 *   @0x21b788 bne 0x21b7e4 <_Z15Audio_PlaySoundidi+0x20c>
 *   @0x21b78c ldr r0, [r4, #0x14]
 *   @0x21b790 add sp, sp, #20
 *   @0x21b794 vpop {d8}
 *   @0x21b798 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x21b79c ldr r3, [pc, #0xf8]
 *   @0x21b7a0 add r2, sp, #16
 *   @0x21b7a4 movw r1, #0x1011
 *   @0x21b7a8 ldr r0, [r0, #0x10]
 *   @0x21b7ac str r1, [r2, #-0x4]!
 *   @0x21b7b0 movw r1, #0x1010
 *   @0x21b7b4 ldr r6, [r5, r3]
 *   @0x21b7b8 ldr r3, [r6]
 *   @0x21b7bc ldr r0, [r3, r0, lsl #2]
 *   @0x21b7c0 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x21b7c4 ldr r2, [sp, #0xc]
 *   @0x21b7c8 movw r3, #0x1012
 *   @0x21b7cc cmp r2, r3
 *   @0x21b7d0 bne 0x21b67c <_Z15Audio_PlaySoundidi+0xa4>
 *   @0x21b7d4 mvn r0, #0
 *   @0x21b7d8 add sp, sp, #20
 *   @0x21b7dc vpop {d8}
 *   @0x21b7e0 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x21b7e4 ldr r3, [pc, #0xc0]
 *   @0x21b7e8 ldr r1, [pc, #0xc0]
 *   @0x21b7ec ldr r3, [r5, r3]
 *   @0x21b7f0 add r1, pc, r1
 *   @0x21b7f4 ldr r0, [r3]
 *   @0x21b7f8 ldr r3, [r0]
 *   @0x21b7fc ldr r3, [r3, #0xc]
 *   @0x21b800 blx r3
 *   @0x21b804 b 0x21b78c <_Z15Audio_PlaySoundidi+0x1b4>
 *   @0x21b808 ldr r3, [pc, #0x9c]
 *   @0x21b80c ldr r1, [pc, #0xa0]
 *   @0x21b810 ldr r3, [r5, r3]
 *   @0x21b814 add r1, pc, r1
 *   @0x21b818 ldr r0, [r3]
 *   @0x21b81c ldr r3, [r0]
 *   @0x21b820 ldr r3, [r3, #0xc]
 *   @0x21b824 blx r3
 *   @0x21b828 b 0x21b688 <_Z15Audio_PlaySoundidi+0xb0>
 *   @0x21b82c ldr r3, [pc, #0x78]
 *   @0x21b830 ldr r1, [pc, #0x80]
 *   @0x21b834 ldr r3, [r5, r3]
 *   @0x21b838 add r1, pc, r1
 *   @0x21b83c ldr r0, [r3]
 *   @0x21b840 ldr r3, [r0]
 *   @0x21b844 ldr r3, [r3, #0xc]
 *   @0x21b848 blx r3
 *   @0x21b84c mov r0, r9
 *   @0x21b850 b 0x21b790 <_Z15Audio_PlaySoundidi+0x1b8>
 *   @0x21b854 ldr r3, [pc, #0x50]
 *   @0x21b858 mov r0, r7
 *   @0x21b85c ldr r3, [r5, r3]
 *   @0x21b860 ldr r4, [r3]
 *   @0x21b864 ldr r3, [r4]
 *   @0x21b868 ldr r5, [r3, #0xc]
 *   @0x21b86c bl 0x218348 <_Z13Audio_GetNamei>
 *   @0x21b870 ldr r1, [pc, #0x44]
 *   @0x21b874 ldr r3, [r9, #0x4c]
 *   @0x21b878 add r1, pc, r1
 *   @0x21b87c mov r2, r0
 *   @0x21b880 mov r0, r4
 *   @0x21b884 blx r5
 *   @0x21b888 b 0x21b7d4 <_Z15Audio_PlaySoundidi+0x1fc>
 *   @0x21b88c andseq r6, sp, r12, asr r6
 *   @0x21b890 .word 0xffffd3fc
 *   @0x21b894 .word 0xffffd0e0
 *   @0x21b898 .word 0xffffd400
 *   @0x21b89c .word 0xfffff77c
 *   @0x21b8a0 .word 0xfffff7a0
 *   @0x21b8a4 .word 0xfffff778
 *   @0x21b8a8 .word 0xfffff7a4
 *   @0x21b8ac .word 0xffffbac4
 *   @0x21b8b0 andseq r8, r3, r0, lsl #18
 *   @0x21b8b4 ldrheq r8, [r3], -r12
 *   @0x21b8b8 ldrsheq r8, [r3], -r4
 *   @0x21b8bc ldrsbeq r8, [r3], -r12
 *
 * ══ §19/42 Debug_GetArrays(Buffer_Standard*, Buffer_Standard*)  0x29b3c0  size 744  186 条（0x29b3c0..0x29b6a8）
 * @func 0x29b3c0 0x29b6a8  size 744  186 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetUint32(RValue const*, int) / Debug_GetArrays(Buffer_Standard*, Buffer_Standard*)+0x270 / YYGetInt32(RValue const*, int) / Debug_GetArrays(Buffer_Standard*, Buffer_Standard*)+0x278 / Debug_GetArrays(Buffer_Standard*, Buffer_Standard*)+0x258 / Debug_GetArrays(Buffer_Standard*, Buffer_Standard*)+0x244 / VM::WriteRValueToBuffer(RValue*, Buffer_Standard*)
 * 字段偏移 top8: 0x4×11 / 0x8×10 / 0xc×9 / 0x38×7 / 0x30×6 / 0x10×4 / 0x2c×4 / 0x14×3
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29b3c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29b3c4 sub sp, sp, #28
 *   @0x29b3c8 add r3, r0, #44
 *   @0x29b3cc mov r4, r1
 *   @0x29b3d0 str r3, [sp, #0xc]
 *   @0x29b3d4 mov r5, #0
 *   @0x29b3d8 ldr r3, [r0]
 *   @0x29b3dc mov r1, #5
 *   @0x29b3e0 ldr r2, [sp, #0xc]
 *   @0x29b3e4 add r10, r4, #44
 *   @0x29b3e8 str r0, [sp, #0x8]
 *   @0x29b3ec ldr r3, [r3, #0xc]
 *   @0x29b3f0 blx r3
 *   @0x29b3f4 mov r1, r5
 *   @0x29b3f8 ldr r0, [sp, #0xc]
 *   @0x29b3fc bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29b400 ldr r3, [r4]
 *   @0x29b404 mov r2, r10
 *   @0x29b408 str r5, [r4, #0x38]
 *   @0x29b40c mov r1, #5
 *   @0x29b410 vmov s15, r0
 *   @0x29b414 str r0, [sp, #0x14]
 *   @0x29b418 mov r0, r4
 *   @0x29b41c vcvt.f64.u32 d7, s15
 *   @0x29b420 vmov r6, r7, d7
 *   @0x29b424 vstr s14, [r4, #44]
 *   @0x29b428 str r7, [r4, #0x30]
 *   @0x29b42c ldr r3, [r3, #0x8]
 *   @0x29b430 blx r3
 *   @0x29b434 ldr r3, [sp, #0x14]
 *   @0x29b438 cmp r3, r5
 *   @0x29b43c ble 0x29b630 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x270>
 *   @0x29b440 str r5, [sp, #0x10]
 *   @0x29b444 ldr r12, [sp, #0x8]
 *   @0x29b448 mov r1, #12
 *   @0x29b44c ldr r2, [sp, #0xc]
 *   @0x29b450 ldr r3, [r12]
 *   @0x29b454 mov r0, r12
 *   @0x29b458 ldr r3, [r3, #0xc]
 *   @0x29b45c blx r3
 *   @0x29b460 ldr r12, [sp, #0x8]
 *   @0x29b464 ldr r2, [sp, #0xc]
 *   @0x29b468 mov r1, #6
 *   @0x29b46c ldr r3, [r12]
 *   @0x29b470 mov r0, r12
 *   @0x29b474 ldr r11, [r12, #0x2c]
 *   @0x29b478 ldr r6, [r12, #0x30]
 *   @0x29b47c ldr r3, [r3, #0xc]
 *   @0x29b480 blx r3
 *   @0x29b484 mov r1, #0
 *   @0x29b488 ldr r0, [sp, #0xc]
 *   @0x29b48c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x29b490 ldr r3, [r11, #0x10]
 *   @0x29b494 ldr r5, [r11, #0x4]
 *   @0x29b498 mov r12, #10
 *   @0x29b49c str r11, [r4, #0x2c]
 *   @0x29b4a0 mov r1, #12
 *   @0x29b4a4 str r3, [sp, #0x4]
 *   @0x29b4a8 cmp r5, #0
 *   @0x29b4ac ldr r3, [r4]
 *   @0x29b4b0 mov r2, r10
 *   @0x29b4b4 str r6, [r4, #0x30]
 *   @0x29b4b8 str r12, [r4, #0x38]
 *   @0x29b4bc ldr r3, [r3, #0x8]
 *   @0x29b4c0 mov r7, r0
 *   @0x29b4c4 mov r0, r4
 *   @0x29b4c8 beq 0x29b670 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x2b0>
 *   @0x29b4cc blx r3
 *   @0x29b4d0 vldr s15, [sp, #4]
 *   @0x29b4d4 vcvt.f64.u32 d7, s15
 *   @0x29b4d8 ldr r3, [r4]
 *   @0x29b4dc mov r1, #0
 *   @0x29b4e0 mov r0, r4
 *   @0x29b4e4 str r1, [r4, #0x38]
 *   @0x29b4e8 mov r2, r10
 *   @0x29b4ec mov r1, #5
 *   @0x29b4f0 vmov r8, r9, d7
 *   @0x29b4f4 vstr s14, [r4, #44]
 *   @0x29b4f8 str r9, [r4, #0x30]
 *   @0x29b4fc ldr r3, [r3, #0x8]
 *   @0x29b500 blx r3
 *   @0x29b504 cmp r7, #0
 *   @0x29b508 blt 0x29b638 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x278>
 *   @0x29b50c vmov s15, r7
 *   @0x29b510 ldr r3, [sp, #0x4]
 *   @0x29b514 vcvt.f64.s32 d7, s15
 *   @0x29b518 rsb r9, r7, r3
 *   @0x29b51c cmp r9, #10
 *   @0x29b520 movge r9, #10
 *   @0x29b524 bic r9, r9, r9, asr #31
 *   @0x29b528 str r9, [sp, #0x4]
 *   @0x29b52c mov r5, r9
 *   @0x29b530 vmov r2, r3, d7
 *   @0x29b534 ldr r12, [r4]
 *   @0x29b538 mov r1, #0
 *   @0x29b53c str r2, [r4, #0x2c]
 *   @0x29b540 mov r0, r4
 *   @0x29b544 str r1, [r4, #0x38]
 *   @0x29b548 mov r2, r10
 *   @0x29b54c str r3, [r4, #0x30]
 *   @0x29b550 mov r1, #5
 *   @0x29b554 ldr r3, [r12, #0x8]
 *   @0x29b558 blx r3
 *   @0x29b55c vmov s13, r5
 *   @0x29b560 ldr r3, [r4]
 *   @0x29b564 mov r1, #0
 *   @0x29b568 vcvt.f64.u32 d7, s13
 *   @0x29b56c str r1, [r4, #0x38]
 *   @0x29b570 mov r0, r4
 *   @0x29b574 mov r1, #5
 *   @0x29b578 mov r2, r10
 *   @0x29b57c vstr s14, [r4, #44]
 *   @0x29b580 vstr s15, [r4, #48]
 *   @0x29b584 ldr r3, [r3, #0x8]
 *   @0x29b588 blx r3
 *   @0x29b58c ldr r3, [sp, #0x4]
 *   @0x29b590 cmp r3, #0
 *   @0x29b594 lslgt r7, r7, #3
 *   @0x29b598 movgt r8, #0
 *   @0x29b59c ble 0x29b618 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x258>
 *   @0x29b5a0 ldr r2, [r11, #0x4]
 *   @0x29b5a4 mov r12, #0
 *   @0x29b5a8 ldr r3, [r4]
 *   @0x29b5ac mov r0, r4
 *   @0x29b5b0 add r6, r2, r7
 *   @0x29b5b4 mov r1, #5
 *   @0x29b5b8 ldr r5, [r2, r7]
 *   @0x29b5bc mov r2, r10
 *   @0x29b5c0 str r12, [r4, #0x38]
 *   @0x29b5c4 vmov s13, r5
 *   @0x29b5c8 vcvt.f64.u32 d7, s13
 *   @0x29b5cc vstr s14, [r4, #44]
 *   @0x29b5d0 vstr s15, [r4, #48]
 *   @0x29b5d4 ldr r3, [r3, #0x8]
 *   @0x29b5d8 blx r3
 *   @0x29b5dc cmp r5, #0
 *   @0x29b5e0 movgt r9, #0
 *   @0x29b5e4 ble 0x29b604 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x244>
 *   @0x29b5e8 ldr r0, [r6, #0x4]
 *   @0x29b5ec mov r1, r4
 *   @0x29b5f0 add r0, r0, r9, lsl #4
 *   @0x29b5f4 add r9, r9, #1
 *   @0x29b5f8 bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard>
 *   @0x29b5fc cmp r9, r5
 *   @0x29b600 bne 0x29b5e8 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x228>
 *   @0x29b604 ldr r3, [sp, #0x4]
 *   @0x29b608 add r8, r8, #1
 *   @0x29b60c add r7, r7, #8
 *   @0x29b610 cmp r8, r3
 *   @0x29b614 bne 0x29b5a0 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x1e0>
 *   @0x29b618 ldr r12, [sp, #0x10]
 *   @0x29b61c ldr r3, [sp, #0x14]
 *   @0x29b620 add r12, r12, #1
 *   @0x29b624 str r12, [sp, #0x10]
 *   @0x29b628 cmp r3, r12
 *   @0x29b62c bne 0x29b444 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x84>
 *   @0x29b630 add sp, sp, #28
 *   @0x29b634 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29b638 ldr r3, [sp, #0x4]
 *   @0x29b63c cmp r3, #10
 *   @0x29b640 bgt 0x29b658 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x298>
 *   @0x29b644 mov r5, r3
 *   @0x29b648 mov r2, #0
 *   @0x29b64c mov r3, #0
 *   @0x29b650 mov r7, #0
 *   @0x29b654 b 0x29b534 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x174>
 *   @0x29b658 mov r5, #0
 *   @0x29b65c mov r2, #0
 *   @0x29b660 mov r3, #0
 *   @0x29b664 str r5, [sp, #0x4]
 *   @0x29b668 mov r7, r5
 *   @0x29b66c b 0x29b534 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x174>
 *   @0x29b670 blx r3
 *   @0x29b674 ldr r3, [r4]
 *   @0x29b678 str r5, [r4, #0x2c]
 *   @0x29b67c mov r0, r4
 *   @0x29b680 str r5, [r4, #0x30]
 *   @0x29b684 mov r1, #5
 *   @0x29b688 str r5, [r4, #0x38]
 *   @0x29b68c mov r2, r10
 *   @0x29b690 ldr r3, [r3, #0x8]
 *   @0x29b694 blx r3
 *   @0x29b698 cmp r7, #0
 *   @0x29b69c str r5, [sp, #0x4]
 *   @0x29b6a0 bge 0x29b50c <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x14c>
 *   @0x29b6a4 b 0x29b648 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x288>
 *
 * ══ §20/42 GR_Text_Draw_Transformed_Color(float, float, char const*, int, int, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)  0x1735a0  size 740  185 条（0x1735a0..0x173884）
 * @func 0x1735a0 0x173884  size 740  185 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / CFontGM::TextWidth(unsigned short*)×2 / SetFont() / Split_TextBlock(char const*, int, TStringList*) / 0xb6580 / 0xb658c / GR_Text_Draw_Transformed_Color(float, float, char const*, int, int, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)+0x2a4 / GR_Text_Draw_Transformed_Color(float, float, char const*, int, int, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)+0x140
 * 字段偏移 top8: 0x20×4 / 0x28×4 / 0x2c×2 / 0x30×2 / 0x90×1 / 0x24×1 / 0x25c×1 / 0x230×1
 * VFP 指令 59 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1735a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1735a4 vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x1735a8 sub sp, sp, #52
 *   @0x1735ac vldr s24, [sp, #156]
 *   @0x1735b0 add r5, sp, #160
 *   @0x1735b4 mov r10, r2
 *   @0x1735b8 ldr r9, [sp, #0x90]
 *   @0x1735bc mov r4, r3
 *   @0x1735c0 vmov s16, r0
 *   @0x1735c4 vldr s25, [sp, #148]
 *   @0x1735c8 vmov s17, r1
 *   @0x1735cc vldr s22, [sp, #152]
 *   @0x1735d0 ldm r5, {r5, r6, r7, r8}
 *   @0x1735d4 vldr s26, [sp, #176]
 *   @0x1735d8 bl 0x1724e4 <_Z7SetFontv>
 *   @0x1735dc mov r1, r9
 *   @0x1735e0 add r2, sp, #32
 *   @0x1735e4 mov r0, r10
 *   @0x1735e8 mov r12, #0
 *   @0x1735ec vldr s18, [pc, #624]
 *   @0x1735f0 str r12, [sp, #0x24]
 *   @0x1735f4 str r12, [sp, #0x20]
 *   @0x1735f8 str r12, [sp, #0x2c]
 *   @0x1735fc str r12, [sp, #0x28]
 *   @0x173600 bl 0x172560 <_Z15Split_TextBlockPKciP11TStringList>
 *   @0x173604 vmul.f32 s18, s24, s18
 *   @0x173608 vldr s15, [pc, #600]
 *   @0x17360c ldr r9, [pc, #0x25c]
 *   @0x173610 add r9, pc, r9
 *   @0x173614 vdiv.f32 s18, s18, s15
 *   @0x173618 vmov r0, s18
 *   @0x17361c bl 0xb6580 <sinf@plt>
 *   @0x173620 vmov s20, r0
 *   @0x173624 vmov r0, s18
 *   @0x173628 bl 0xb658c <cosf@plt>
 *   @0x17362c cmp r4, #0
 *   @0x173630 vmov s21, r0
 *   @0x173634 blt 0x173844 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x2a4>
 *   @0x173638 vmul.f32 s18, s20, s22
 *   @0x17363c ldr r3, [pc, #0x230]
 *   @0x173640 vmov s13, r4
 *   @0x173644 ldr r1, [sp, #0x28]
 *   @0x173648 ldr r3, [r9, r3]
 *   @0x17364c ldr r3, [r3]
 *   @0x173650 cmp r3, #1
 *   @0x173654 vmul.f32 s19, s21, s22
 *   @0x173658 vcvt.f32.s32 s15, s13
 *   @0x17365c vmul.f32 s18, s18, s15
 *   @0x173660 vmul.f32 s19, s15, s19
 *   @0x173664 beq 0x173824 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x284>
 *   @0x173668 cmp r3, #2
 *   @0x17366c vmoveq s13, r1
 *   @0x173670 vcvteq.f32.s32 s15, s13
 *   @0x173674 vmlseq.f32 s17, s15, s19
 *   @0x173678 vmlseq.f32 s16, s18, s15
 *   @0x17367c cmp r1, #0
 *   @0x173680 ldrle r0, [sp, #0x20]
 *   @0x173684 ble 0x1736e0 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x140>
 *   @0x173688 ldr r0, [sp, #0x20]
 *   @0x17368c mov r4, #0
 *   @0x173690 vldr s23, [pc, #468]
 *   @0x173694 vmov.f32 s28, #5.000000e-01
 *   @0x173698 vneg.f32 s27, s25
 *   @0x17369c cmp r0, #0
 *   @0x1736a0 beq 0x1736cc <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x12c>
 *   @0x1736a4 cmp r4, #0
 *   @0x1736a8 movne r2, r4
 *   @0x1736ac movne r3, r0
 *   @0x1736b0 bne 0x1736c0 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x120>
 *   @0x1736b4 b 0x173724 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x184>
 *   @0x1736b8 subs r2, r2, #1
 *   @0x1736bc beq 0x173728 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x188>
 *   @0x1736c0 ldr r3, [r3]
 *   @0x1736c4 cmp r3, #0
 *   @0x1736c8 bne 0x1736b8 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x118>
 *   @0x1736cc add r4, r4, #1
 *   @0x1736d0 vadd.f32 s16, s16, s18
 *   @0x1736d4 cmp r1, r4
 *   @0x1736d8 vadd.f32 s17, s17, s19
 *   @0x1736dc bgt 0x17369c <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0xfc>
 *   @0x1736e0 cmp r0, #0
 *   @0x1736e4 beq 0x1736fc <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x15c>
 *   @0x1736e8 ldr r4, [r0]
 *   @0x1736ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1736f0 cmp r4, #0
 *   @0x1736f4 mov r0, r4
 *   @0x1736f8 bne 0x1736e8 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x148>
 *   @0x1736fc ldr r0, [sp, #0x2c]
 *   @0x173700 mov r3, #0
 *   @0x173704 str r3, [sp, #0x28]
 *   @0x173708 cmp r0, r3
 *   @0x17370c str r3, [sp, #0x20]
 *   @0x173710 beq 0x173718 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x178>
 *   @0x173714 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x173718 add sp, sp, #52
 *   @0x17371c vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x173720 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x173724 mov r3, r0
 *   @0x173728 ldr r10, [r3, #0x4]
 *   @0x17372c cmp r10, #0
 *   @0x173730 beq 0x1736cc <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x12c>
 *   @0x173734 ldrh r3, [r10]
 *   @0x173738 cmp r3, #0
 *   @0x17373c beq 0x1736cc <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x12c>
 *   @0x173740 ldr r3, [pc, #0x130]
 *   @0x173744 ldr r11, [r9, r3]
 *   @0x173748 ldr r3, [r11]
 *   @0x17374c cmp r3, #1
 *   @0x173750 beq 0x1737f8 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x258>
 *   @0x173754 vldr s15, [pc, #272]
 *   @0x173758 cmp r3, #2
 *   @0x17375c beq 0x1737d4 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x234>
 *   @0x173760 ldrh r3, [r10]
 *   @0x173764 cmp r3, #0
 *   @0x173768 bne 0x173778 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x1d8>
 *   @0x17376c ldr r0, [sp, #0x20]
 *   @0x173770 ldr r1, [sp, #0x28]
 *   @0x173774 b 0x1736cc <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x12c>
 *   @0x173778 vmov.f32 s13, s17
 *   @0x17377c ldr r2, [pc, #0xf8]
 *   @0x173780 mov r3, r10
 *   @0x173784 ldr r2, [r9, r2]
 *   @0x173788 vstr s25, [sp]
 *   @0x17378c vmov.f32 s14, s16
 *   @0x173790 vstr s22, [sp, #4]
 *   @0x173794 vstr s24, [sp, #8]
 *   @0x173798 str r5, [sp, #0xc]
 *   @0x17379c vstr s26, [sp, #28]
 *   @0x1737a0 ldr r0, [r2]
 *   @0x1737a4 str r6, [sp, #0x10]
 *   @0x1737a8 vmls.f32 s13, s20, s15
 *   @0x1737ac str r7, [sp, #0x14]
 *   @0x1737b0 str r8, [sp, #0x18]
 *   @0x1737b4 vmla.f32 s14, s21, s15
 *   @0x1737b8 vmov.f32 s15, s13
 *   @0x1737bc vmla.f32 s14, s20, s23
 *   @0x1737c0 vmla.f32 s15, s21, s23
 *   @0x1737c4 vmov r1, s14
 *   @0x1737c8 vmov r2, s15
 *   @0x1737cc bl 0xf8f58 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf>
 *   @0x1737d0 b 0x17376c <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x1cc>
 *   @0x1737d4 ldr r3, [pc, #0xa0]
 *   @0x1737d8 mov r1, r10
 *   @0x1737dc ldr r3, [r9, r3]
 *   @0x1737e0 ldr r0, [r3]
 *   @0x1737e4 bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt>
 *   @0x1737e8 vmov s13, r0
 *   @0x1737ec vcvt.f32.s32 s15, s13
 *   @0x1737f0 vmul.f32 s15, s27, s15
 *   @0x1737f4 b 0x173760 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x1c0>
 *   @0x1737f8 ldr r3, [pc, #0x7c]
 *   @0x1737fc mov r1, r10
 *   @0x173800 ldr r3, [r9, r3]
 *   @0x173804 ldr r0, [r3]
 *   @0x173808 bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt>
 *   @0x17380c ldr r3, [r11]
 *   @0x173810 vmov s14, r0
 *   @0x173814 vcvt.f32.s32 s15, s14
 *   @0x173818 vmul.f32 s15, s27, s15
 *   @0x17381c vmul.f32 s15, s15, s28
 *   @0x173820 b 0x173758 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x1b8>
 *   @0x173824 vmov s14, r1
 *   @0x173828 vcvt.f32.s32 s15, s14
 *   @0x17382c vmul.f32 s13, s15, s19
 *   @0x173830 vmul.f32 s14, s18, s15
 *   @0x173834 vmov.f32 s15, #5.000000e-01
 *   @0x173838 vmls.f32 s17, s13, s15
 *   @0x17383c vmls.f32 s16, s14, s15
 *   @0x173840 b 0x17367c <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0xdc>
 *   @0x173844 ldr r3, [pc, #0x30]
 *   @0x173848 ldr r1, [pc, #0x30]
 *   @0x17384c ldr r3, [r9, r3]
 *   @0x173850 add r1, pc, r1
 *   @0x173854 ldr r0, [r3]
 *   @0x173858 bl 0xf93a4 <_ZN7CFontGM10TextHeightEPt>
 *   @0x17385c mov r4, r0
 *   @0x173860 b 0x173638 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x98>
 *   @0x173864 ldrdmi r0, r1, [r9], #-251
 *   @0x173868 teqmi r4, #0
 *   @0x17386c andeq r0, r0, r0
 *   @0x173870 eoreq lr, r7, r0, asr #12
 *   @0x173874 .word 0xffffe65c
 *   @0x173878 .word 0xffffe658
 *   @0x17387c .word 0xffffe654
 *   @0x173880 ldrheq r7, [sp], -r8
 *
 * ══ §21/42 ProcessVirtualKeys()  0x18cfa4  size 740  185 条（0x18cfa4..0x18d288）
 * @func 0x18cfa4 0x18d288  size 740  185 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x18cfb0→0x534658, 0x18cfdc→0x533c58, 0x18cfe0→0x534660, 0x18cff8→0x542564, 0x18d0f0→0x533c50, 0x18d1bc→0x534ba0, 0x18d1c4→0x534af0, 0x18d1c8→0x534da0
 * 调用序列: ProcessVirtualKeys()+0x12c×2 / Get_FullScreenOffset(int&, int&, int&, int&) / ProcessVirtualKeys()+0x13c / ProcessVirtualKeys()+0x2a4
 * 字段偏移 top8: 0xa8×5 / 0x2a4×2 / 0x27c×2 / 0x-14×2 / 0x-2c×2 / 0xc×2 / 0x4×2 / 0x8×2
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18cfa4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x18cfa8 sub sp, sp, #36
 *   @0x18cfac ldr r4, [pc, #0x2a4]
 *   @0x18cfb0 ldr r3, [pc, #0x2a4]
 *   @0x18cfb4 add r4, pc, r4
 *   @0x18cfb8 ldr r5, [r4, r3]
 *   @0x18cfbc ldr r3, [r5]
 *   @0x18cfc0 cmp r3, #0
 *   @0x18cfc4 beq 0x18d250 <_Z18ProcessVirtualKeysv+0x2ac>
 *   @0x18cfc8 add r1, sp, #20
 *   @0x18cfcc add r2, sp, #24
 *   @0x18cfd0 add r3, sp, #28
 *   @0x18cfd4 add r0, sp, #16
 *   @0x18cfd8 bl 0x179a00 <_Z20Get_FullScreenOffsetRiS_S_S_>
 *   @0x18cfdc ldr r2, [pc, #0x27c]
 *   @0x18cfe0 ldr r3, [pc, #0x27c]
 *   @0x18cfe4 mov r10, #0
 *   @0x18cfe8 ldr r1, [r5]
 *   @0x18cfec mov r9, r10
 *   @0x18cff0 ldr r12, [r4, r2]
 *   @0x18cff4 ldr r3, [r4, r3]
 *   @0x18cff8 ldr r2, [pc, #0x268]
 *   @0x18cffc add r8, r12, #2576
 *   @0x18d000 add r8, r8, #4
 *   @0x18d004 add r12, r12, #20
 *   @0x18d008 ldr r3, [r3]
 *   @0x18d00c ldr r2, [r4, r2]
 *   @0x18d010 vldr s10, [r2]
 *   @0x18d014 vldr s11, [r2, #16]
 *   @0x18d018 vldr s12, [r2, #48]
 *   @0x18d01c vldr s7, [r2, #4]
 *   @0x18d020 vldr s8, [r2, #20]
 *   @0x18d024 vldr s9, [r2, #52]
 *   @0x18d028 b 0x18d038 <_Z18ProcessVirtualKeysv+0x94>
 *   @0x18d02c add r12, r12, #20
 *   @0x18d030 cmp r12, r8
 *   @0x18d034 beq 0x18d0f0 <_Z18ProcessVirtualKeysv+0x14c>
 *   @0x18d038 ldr r2, [r12, #-0x14]
 *   @0x18d03c cmp r2, #0
 *   @0x18d040 bge 0x18d02c <_Z18ProcessVirtualKeysv+0x88>
 *   @0x18d044 cmp r3, #0
 *   @0x18d048 ble 0x18d0e0 <_Z18ProcessVirtualKeysv+0x13c>
 *   @0x18d04c add r2, r1, #44
 *   @0x18d050 mov r0, #0
 *   @0x18d054 mov r5, #1
 *   @0x18d058 ldrh r6, [r2, #-44]
 *   @0x18d05c add r0, r0, #1
 *   @0x18d060 tst r6, #1
 *   @0x18d064 beq 0x18d0d0 <_Z18ProcessVirtualKeysv+0x12c>
 *   @0x18d068 vldr s6, [r12, #-12]
 *   @0x18d06c vcvt.f32.s32 s13, s6
 *   @0x18d070 vldr s6, [r12, #-16]
 *   @0x18d074 ldr r7, [r2, #-0x28]
 *   @0x18d078 vmul.f32 s15, s11, s13
 *   @0x18d07c vcvt.f32.s32 s14, s6
 *   @0x18d080 vmla.f32 s15, s10, s14
 *   @0x18d084 vadd.f32 s15, s15, s12
 *   @0x18d088 vcvt.s32.f32 s15, s15
 *   @0x18d08c vmov r6, s15
 *   @0x18d090 cmp r6, r7
 *   @0x18d094 blt 0x18d0d0 <_Z18ProcessVirtualKeysv+0x12c>
 *   @0x18d098 ldr r7, [r2, #-0x20]
 *   @0x18d09c cmp r6, r7
 *   @0x18d0a0 bge 0x18d0d0 <_Z18ProcessVirtualKeysv+0x12c>
 *   @0x18d0a4 vmul.f32 s13, s8, s13
 *   @0x18d0a8 ldr r7, [r2, #-0x24]
 *   @0x18d0ac vmla.f32 s13, s7, s14
 *   @0x18d0b0 vadd.f32 s13, s13, s9
 *   @0x18d0b4 vcvt.s32.f32 s13, s13
 *   @0x18d0b8 vmov r6, s13
 *   @0x18d0bc cmp r6, r7
 *   @0x18d0c0 blt 0x18d0d0 <_Z18ProcessVirtualKeysv+0x12c>
 *   @0x18d0c4 ldr r7, [r2, #-0x1c]
 *   @0x18d0c8 cmp r6, r7
 *   @0x18d0cc orrlt r10, r10, r5
 *   @0x18d0d0 cmp r0, r3
 *   @0x18d0d4 lsl r5, r5, #1
 *   @0x18d0d8 add r2, r2, #44
 *   @0x18d0dc bne 0x18d058 <_Z18ProcessVirtualKeysv+0xb4>
 *   @0x18d0e0 str r9, [r12, #-0x14]
 *   @0x18d0e4 add r12, r12, #20
 *   @0x18d0e8 cmp r12, r8
 *   @0x18d0ec bne 0x18d038 <_Z18ProcessVirtualKeysv+0x94>
 *   @0x18d0f0 ldr r2, [pc, #0x174]
 *   @0x18d0f4 cmp r3, #0
 *   @0x18d0f8 ldr r2, [r4, r2]
 *   @0x18d0fc str r2, [sp, #0xc]
 *   @0x18d100 ldr r2, [r2]
 *   @0x18d104 eor r2, r10, r2
 *   @0x18d108 str r2, [sp, #0x4]
 *   @0x18d10c ble 0x18d248 <_Z18ProcessVirtualKeysv+0x2a4>
 *   @0x18d110 add r1, r1, #44
 *   @0x18d114 mov r11, #0
 *   @0x18d118 mov r2, #1
 *   @0x18d11c str r10, [sp]
 *   @0x18d120 str r3, [sp, #0x8]
 *   @0x18d124 b 0x18d19c <_Z18ProcessVirtualKeysv+0x1f8>
 *   @0x18d128 adds r5, r0, #0
 *   @0x18d12c ldr r10, [r4, r10]
 *   @0x18d130 movne r5, #1
 *   @0x18d134 cmp r12, #0
 *   @0x18d138 ldrb r6, [r10, r3]
 *   @0x18d13c moveq r12, #0
 *   @0x18d140 movne r12, #1
 *   @0x18d144 and r7, r12, r5
 *   @0x18d148 orr r6, r7, r6
 *   @0x18d14c strb r6, [r10, r3]
 *   @0x18d150 ldr r6, [r4, r9]
 *   @0x18d154 movne r5, #0
 *   @0x18d158 andeq r5, r5, #1
 *   @0x18d15c cmp r0, #0
 *   @0x18d160 movne r0, #0
 *   @0x18d164 andeq r0, r12, #1
 *   @0x18d168 ldrb r12, [r6, r3]
 *   @0x18d16c orr r5, r5, r12
 *   @0x18d170 strb r5, [r6, r3]
 *   @0x18d174 ldr r5, [r4, r8]
 *   @0x18d178 ldrb r12, [r5, r3]
 *   @0x18d17c orr r0, r0, r12
 *   @0x18d180 strb r0, [r5, r3]
 *   @0x18d184 ldr r12, [sp, #0x8]
 *   @0x18d188 add r11, r11, #1
 *   @0x18d18c lsl r2, r2, #1
 *   @0x18d190 add r1, r1, #44
 *   @0x18d194 cmp r11, r12
 *   @0x18d198 beq 0x18d244 <_Z18ProcessVirtualKeysv+0x2a0>
 *   @0x18d19c ldrh r3, [r1, #-44]
 *   @0x18d1a0 ldr r5, [sp]
 *   @0x18d1a4 ldr r6, [sp, #0x4]
 *   @0x18d1a8 tst r3, #1
 *   @0x18d1ac and r0, r2, r5
 *   @0x18d1b0 and r12, r2, r6
 *   @0x18d1b4 beq 0x18d184 <_Z18ProcessVirtualKeysv+0x1e0>
 *   @0x18d1b8 ldr r3, [r1, #-0x8]
 *   @0x18d1bc ldr r10, [pc, #0xac]
 *   @0x18d1c0 cmp r3, #0
 *   @0x18d1c4 ldr r7, [pc, #0xa8]
 *   @0x18d1c8 ldr r9, [pc, #0xa8]
 *   @0x18d1cc ldr r6, [pc, #0xa8]
 *   @0x18d1d0 ldr r8, [pc, #0xa8]
 *   @0x18d1d4 ldr r5, [pc, #0xa8]
 *   @0x18d1d8 bne 0x18d128 <_Z18ProcessVirtualKeysv+0x184>
 *   @0x18d1dc ldr r3, [r1, #-0x4]
 *   @0x18d1e0 adds r8, r0, #0
 *   @0x18d1e4 ldr r10, [r4, r7]
 *   @0x18d1e8 sub r3, r3, #1
 *   @0x18d1ec movne r8, #1
 *   @0x18d1f0 cmp r12, #0
 *   @0x18d1f4 ldrb r7, [r10, r3]
 *   @0x18d1f8 moveq r12, #0
 *   @0x18d1fc movne r12, #1
 *   @0x18d200 and r9, r12, r8
 *   @0x18d204 orr r7, r9, r7
 *   @0x18d208 movne r8, #0
 *   @0x18d20c andeq r8, r8, #1
 *   @0x18d210 strb r7, [r10, r3]
 *   @0x18d214 cmp r0, #0
 *   @0x18d218 movne r0, #0
 *   @0x18d21c andeq r0, r12, #1
 *   @0x18d220 ldr r12, [r4, r6]
 *   @0x18d224 ldrb r6, [r12, r3]
 *   @0x18d228 orr r8, r8, r6
 *   @0x18d22c strb r8, [r12, r3]
 *   @0x18d230 ldr r12, [r4, r5]
 *   @0x18d234 ldrb r5, [r12, r3]
 *   @0x18d238 orr r0, r0, r5
 *   @0x18d23c strb r0, [r12, r3]
 *   @0x18d240 b 0x18d184 <_Z18ProcessVirtualKeysv+0x1e0>
 *   @0x18d244 ldr r10, [sp]
 *   @0x18d248 ldr r0, [sp, #0xc]
 *   @0x18d24c str r10, [r0]
 *   @0x18d250 add sp, sp, #36
 *   @0x18d254 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x18d258 mlaeq r6, r12, r12, r4
 *   @0x18d25c .word 0xffffdf04
 *   @0x18d260 .word 0xffffe9c4
 *   @0x18d264 .word 0xffffdf00
 *   @0x18d268 .word 0xffffdf50
 *   @0x18d26c .word 0xffffe9d8
 *   @0x18d270 .word 0xffffe998
 *   @0x18d274 .word 0xffffe9ac
 *   @0x18d278 .word 0xffffe990
 *   @0x18d27c .word 0xffffe9a4
 *   @0x18d280 .word 0xffffe994
 *   @0x18d284 .word 0xffffe9a8
 *
 * ══ §22/42 ASYNCFunc_SpriteAdd(HTTP_REQ_CONTEXT*, void*, int*)  0x1ee7a0  size 740  185 条（0x1ee7a0..0x1eea84）
 * @func 0x1ee7a0 0x1eea84  size 740  185 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CreateDsMap(int, ...) / ASYNCFunc_SpriteAdd(HTTP_REQ_CONTEXT*, void*, int*)+0xac / MarkInstancesAsDirty(int) / CSprite::LoadFromJPEGData(void*, int, int, bool, bool, bool, int, int, bool) / CSprite::LoadFromGIFData(void*, int, int, bool, bool, bool, int, int, bool) / CSprite::LoadFromPNGData(void*, int, int, bool, bool, bool, int, int, bool)
 * 字段偏移 top8: 0x4×10 / 0x2×8 / 0x10×7 / 0xc×7 / 0x8×6 / 0x3c×4 / 0x14×4 / 0x20×3
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ee7a0 vmov.f64 d7, #-1.000000e+00
 *   @0x1ee7a4 vldr s10, [r1]
 *   @0x1ee7a8 vldr s12, [r0, #40]
 *   @0x1ee7ac push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1ee7b0 mov r7, r1
 *   @0x1ee7b4 ldr r1, [r0, #0x3c]
 *   @0x1ee7b8 sub sp, sp, #56
 *   @0x1ee7bc mov r12, #0
 *   @0x1ee7c0 mov r8, r2
 *   @0x1ee7c4 cmp r1, r12
 *   @0x1ee7c8 ldr r1, [pc, #0x294]
 *   @0x1ee7cc ldr r2, [r0, #0x20]
 *   @0x1ee7d0 mov r4, #0
 *   @0x1ee7d4 add r1, pc, r1
 *   @0x1ee7d8 ldr r3, [pc, #0x288]
 *   @0x1ee7dc str r1, [sp, #0x24]
 *   @0x1ee7e0 mov r5, #0
 *   @0x1ee7e4 ldr lr, [pc, #0x280]
 *   @0x1ee7e8 mov r6, r0
 *   @0x1ee7ec vcvt.f64.s32 d5, s10
 *   @0x1ee7f0 ldr r1, [pc, #0x278]
 *   @0x1ee7f4 vmovgt d7, r4, r5
 *   @0x1ee7f8 add r3, pc, r3
 *   @0x1ee7fc add lr, pc, lr
 *   @0x1ee800 stm sp, {r2, r3}
 *   @0x1ee804 str r12, [sp, #0x10]
 *   @0x1ee808 mov r3, r5
 *   @0x1ee80c str r12, [sp, #0x20]
 *   @0x1ee810 mov r0, #4
 *   @0x1ee814 str r12, [sp, #0x30]
 *   @0x1ee818 mov r2, r4
 *   @0x1ee81c str lr, [sp, #0x14]
 *   @0x1ee820 add r1, pc, r1
 *   @0x1ee824 vcvt.f64.s32 d6, s12
 *   @0x1ee828 vstr d5, [sp, #8]
 *   @0x1ee82c vstr d7, [sp, #40]
 *   @0x1ee830 vstr d6, [sp, #24]
 *   @0x1ee834 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x1ee838 str r0, [r8]
 *   @0x1ee83c ldr r3, [r6, #0x28]
 *   @0x1ee840 ldr r12, [r7, #0x10]
 *   @0x1ee844 cmp r3, #200
 *   @0x1ee848 beq 0x1ee858 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0xb8>
 *   @0x1ee84c mov r0, #60
 *   @0x1ee850 add sp, sp, #56
 *   @0x1ee854 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1ee858 ldr r2, [r6, #0x3c]
 *   @0x1ee85c cmp r2, #0
 *   @0x1ee860 ble 0x1ee84c <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0xac>
 *   @0x1ee864 ldr r4, [pc, #0x208]
 *   @0x1ee868 ldr r1, [r7]
 *   @0x1ee86c ldr r4, [pc, r4]
 *   @0x1ee870 ldr r3, [r4, #0x4]
 *   @0x1ee874 ldr r0, [r3, r1, lsl #2]
 *   @0x1ee878 cmp r0, #0
 *   @0x1ee87c beq 0x1ee84c <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0xac>
 *   @0x1ee880 ldr r5, [r6, #0x34]
 *   @0x1ee884 ands r1, r12, #2
 *   @0x1ee888 movne r8, #0
 *   @0x1ee88c moveq r8, #1
 *   @0x1ee890 ldrb r3, [r5]
 *   @0x1ee894 cmp r3, #255
 *   @0x1ee898 beq 0x1ee90c <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x16c>
 *   @0x1ee89c cmp r3, #71
 *   @0x1ee8a0 bne 0x1ee9e0 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x240>
 *   @0x1ee8a4 ldrb r3, [r5, #0x1]
 *   @0x1ee8a8 cmp r3, #73
 *   @0x1ee8ac beq 0x1ee970 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x1d0>
 *   @0x1ee8b0 ldr r3, [pc, #0x1c0]
 *   @0x1ee8b4 ldr r1, [pc, #0x1c0]
 *   @0x1ee8b8 ldr r3, [pc, r3]
 *   @0x1ee8bc ldr r2, [r6, #0x20]
 *   @0x1ee8c0 add r1, pc, r1
 *   @0x1ee8c4 ldr r0, [r3]
 *   @0x1ee8c8 ldr r3, [r0]
 *   @0x1ee8cc ldr r3, [r3, #0xc]
 *   @0x1ee8d0 blx r3
 *   @0x1ee8d4 ldr r2, [pc, #0x1a4]
 *   @0x1ee8d8 ldr r3, [r7]
 *   @0x1ee8dc ldr r2, [pc, r2]
 *   @0x1ee8e0 ldr r12, [r4, #0x4]
 *   @0x1ee8e4 ldr r1, [r2]
 *   @0x1ee8e8 mov r0, r3
 *   @0x1ee8ec ldr r2, [r12, r3, lsl #2]
 *   @0x1ee8f0 ldr r1, [r1, r3, lsl #2]
 *   @0x1ee8f4 str r3, [r2, #0x60]
 *   @0x1ee8f8 str r1, [r2, #0x5c]
 *   @0x1ee8fc bl 0x130cac <_Z20MarkInstancesAsDirtyi>
 *   @0x1ee900 mov r0, #60
 *   @0x1ee904 add sp, sp, #56
 *   @0x1ee908 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1ee90c ldrb r3, [r5, #0x1]
 *   @0x1ee910 cmp r3, #216
 *   @0x1ee914 bne 0x1ee8b0 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x110>
 *   @0x1ee918 ldrb r3, [r5, #0x2]
 *   @0x1ee91c cmp r3, #255
 *   @0x1ee920 bne 0x1ee8b0 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x110>
 *   @0x1ee924 ldr r10, [r7, #0x8]
 *   @0x1ee928 adds r1, r1, #0
 *   @0x1ee92c ldr r9, [r7, #0xc]
 *   @0x1ee930 and lr, r12, #1
 *   @0x1ee934 ldr r3, [r7, #0x4]
 *   @0x1ee938 movne r1, #1
 *   @0x1ee93c ubfx r12, r12, #0x2, #0x1
 *   @0x1ee940 str r1, [sp, #0x4]
 *   @0x1ee944 str r8, [sp, #0x14]
 *   @0x1ee948 mov r1, r5
 *   @0x1ee94c str r10, [sp, #0xc]
 *   @0x1ee950 str r9, [sp, #0x10]
 *   @0x1ee954 str lr, [sp]
 *   @0x1ee958 str r12, [sp, #0x8]
 *   @0x1ee95c bl 0x1e7140 <_ZN7CSprite16LoadFromJPEGDataEPviibbbiib>
 *   @0x1ee960 cmp r0, #0
 *   @0x1ee964 bne 0x1ee8d4 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x134>
 *   @0x1ee968 ldrb r3, [r5]
 *   @0x1ee96c b 0x1ee89c <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0xfc>
 *   @0x1ee970 ldrb r3, [r5, #0x2]
 *   @0x1ee974 cmp r3, #70
 *   @0x1ee978 bne 0x1ee8b0 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x110>
 *   @0x1ee97c ldrb r3, [r5, #0x3]
 *   @0x1ee980 cmp r3, #56
 *   @0x1ee984 bne 0x1ee8b0 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x110>
 *   @0x1ee988 ldr r2, [r4, #0x4]
 *   @0x1ee98c ldr r1, [r7, #0xc]
 *   @0x1ee990 ldr r0, [r7]
 *   @0x1ee994 ldr r12, [r7, #0x8]
 *   @0x1ee998 ldr r3, [r7, #0x10]
 *   @0x1ee99c str r8, [sp, #0x14]
 *   @0x1ee9a0 str r12, [sp, #0xc]
 *   @0x1ee9a4 ubfx lr, r3, #0x1, #0x1
 *   @0x1ee9a8 str r1, [sp, #0x10]
 *   @0x1ee9ac and r9, r3, #1
 *   @0x1ee9b0 str lr, [sp, #0x4]
 *   @0x1ee9b4 ubfx r3, r3, #0x2, #0x1
 *   @0x1ee9b8 str r9, [sp]
 *   @0x1ee9bc str r3, [sp, #0x8]
 *   @0x1ee9c0 ldr r0, [r2, r0, lsl #2]
 *   @0x1ee9c4 ldr r1, [r6, #0x34]
 *   @0x1ee9c8 ldr r2, [r6, #0x3c]
 *   @0x1ee9cc ldr r3, [r7, #0x4]
 *   @0x1ee9d0 bl 0x1e71d8 <_ZN7CSprite15LoadFromGIFDataEPviibbbiib>
 *   @0x1ee9d4 cmp r0, #0
 *   @0x1ee9d8 bne 0x1ee8d4 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x134>
 *   @0x1ee9dc ldrb r3, [r5]
 *   @0x1ee9e0 cmp r3, #137
 *   @0x1ee9e4 bne 0x1ee8b0 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x110>
 *   @0x1ee9e8 ldrb r3, [r5, #0x1]
 *   @0x1ee9ec cmp r3, #80
 *   @0x1ee9f0 bne 0x1ee8b0 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x110>
 *   @0x1ee9f4 ldrb r3, [r5, #0x2]
 *   @0x1ee9f8 cmp r3, #78
 *   @0x1ee9fc bne 0x1ee8b0 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x110>
 *   @0x1eea00 ldrb r3, [r5, #0x3]
 *   @0x1eea04 cmp r3, #71
 *   @0x1eea08 bne 0x1ee8b0 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x110>
 *   @0x1eea0c ldr r2, [r4, #0x4]
 *   @0x1eea10 ldr r1, [r7, #0xc]
 *   @0x1eea14 ldr r0, [r7]
 *   @0x1eea18 ldr r12, [r7, #0x8]
 *   @0x1eea1c ldr r3, [r7, #0x10]
 *   @0x1eea20 str r8, [sp, #0x14]
 *   @0x1eea24 str r12, [sp, #0xc]
 *   @0x1eea28 ubfx lr, r3, #0x1, #0x1
 *   @0x1eea2c str r1, [sp, #0x10]
 *   @0x1eea30 and r5, r3, #1
 *   @0x1eea34 str lr, [sp, #0x4]
 *   @0x1eea38 ubfx r3, r3, #0x2, #0x1
 *   @0x1eea3c str r5, [sp]
 *   @0x1eea40 str r3, [sp, #0x8]
 *   @0x1eea44 ldr r0, [r2, r0, lsl #2]
 *   @0x1eea48 ldr r1, [r6, #0x34]
 *   @0x1eea4c ldr r2, [r6, #0x3c]
 *   @0x1eea50 ldr r3, [r7, #0x4]
 *   @0x1eea54 bl 0x1e70b0 <_ZN7CSprite15LoadFromPNGDataEPviibbbiib>
 *   @0x1eea58 cmp r0, #0
 *   @0x1eea5c bne 0x1ee8d4 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x134>
 *   @0x1eea60 b 0x1ee8b0 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x110>
 *   @0x1eea64 andseq r2, r4, r12, ror r2
 *   @0x1eea68 andseq r2, r4, r8, asr #4
 *   @0x1eea6c andseq r2, r4, r8, asr #4
 *   @0x1eea70 andseq r2, r4, r4, lsl r2
 *   @0x1eea74 mlaeq r0, r12, r5, r2
 *   @0x1eea78 andseq lr, pc, r12, asr lr
 *   @0x1eea7c mulseq r4, r8, r1
 *   @0x1eea80 eoreq r2, r0, r0, lsr r5
 *
 * ══ §23/42 Audio_QueueBufferSound(int, int, int, int)  0x21d0e0  size 740  178 条（0x21d0e0..0x21d3c4）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x21d0e0 0x21d3c4  size 740  178 条
 * 部分覆盖: 本节 178/185 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21d0f0→0x755363, 0x21d110→0x755314, 0x21d1bc→0x3eb70c, 0x21d1e0→0x75531c, 0x21d228→0x3eb70c, 0x21d260→0x755318, 0x21d264→0x3f52d4, 0x21d26c→0x75531c
 * 调用序列: 0xb6a78×3 / 0xb6a54×2 / 0xb6a6c×2 / 0xb6b2c×2 / Audio_CreateBufferSound(int, int, int, int, int, int) / Audio_GetSound(int) / 0xb6b8c / Audio_GetSoundSourceToPlay(int, float)
 * 字段偏移 top8: 0x2×9 / 0xc×4 / 0x4×3 / 0x14×3 / 0x34×2 / 0x58×2 / 0x18×2 / 0x10×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21d0e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x21d0e4 mov r8, r0
 *   @0x21d104 ldrb r7, [r12]
 *   @0x21d108 cmp r7, #0
 *   @0x21d10c bne 0x21d220 <_Z22Audio_QueueBufferSoundiiii+0x140>
 *   @0x21d110 ldr r3, [pc, #0x280]
 *   @0x21d114 ldr r3, [r4, r3]
 *   @0x21d118 ldrb r3, [r3]
 *   @0x21d11c cmp r3, #0
 *   @0x21d120 beq 0x21d220 <_Z22Audio_QueueBufferSoundiiii+0x140>
 *   @0x21d124 sub r12, r8, #199680
 *   @0x21d128 subs r12, r12, #320
 *   @0x21d12c bmi 0x21d350 <_Z22Audio_QueueBufferSoundiiii+0x270>
 *   @0x21d130 ldr r3, [pc, #0x264]
 *   @0x21d134 add r3, pc, r3
 *   @0x21d138 ldr r1, [r3, #0x30]
 *   @0x21d13c cmp r12, r1
 *   @0x21d140 bge 0x21d350 <_Z22Audio_QueueBufferSoundiiii+0x270>
 *   @0x21d144 ldr r3, [r3, #0x34]
 *   @0x21d148 ldr r6, [r3, r12, lsl #2]
 *   @0x21d14c cmp r6, #0
 *   @0x21d150 beq 0x21d350 <_Z22Audio_QueueBufferSoundiiii+0x270>
 *   @0x21d154 ldr lr, [r6, #0x38]
 *   @0x21d158 mov r3, r2
 *   @0x21d15c ldr r1, [r6, #0x50]
 *   @0x21d160 str r5, [sp]
 *   @0x21d164 ldr r12, [r6, #0x54]
 *   @0x21d168 mov r2, lr
 *   @0x21d16c str r12, [sp, #0x4]
 *   @0x21d170 bl 0x2198a0 <_Z23Audio_CreateBufferSoundiiiiii>
 *   @0x21d174 mov r5, r0
 *   @0x21d178 bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x21d17c subs r9, r0, #0
 *   @0x21d180 beq 0x21d37c <_Z22Audio_QueueBufferSoundiiii+0x29c>
 *   @0x21d184 ldr r5, [r6, #0x58]
 *   @0x21d188 cmp r5, #0
 *   @0x21d18c beq 0x21d24c <_Z22Audio_QueueBufferSoundiiii+0x16c>
 *   @0x21d190 ldr r3, [r9, #0x18]
 *   @0x21d194 ldr r6, [r5, #0x10]
 *   @0x21d198 cmp r3, #0
 *   @0x21d19c str r3, [sp, #0xc]
 *   @0x21d1a0 bne 0x21d1e0 <_Z22Audio_QueueBufferSoundiiii+0x100>
 *   @0x21d1a4 bl 0xb6a54 <alGetError@plt>
 *   @0x21d1a8 subs r2, r0, #0
 *   @0x21d1ac bne 0x21d1bc <_Z22Audio_QueueBufferSoundiiii+0xdc>
 *   @0x21d1b0 ldr r0, [r5, #0x14]
 *   @0x21d1b4 add sp, sp, #20
 *   @0x21d1b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x21d1bc ldr r3, [pc, #0x1dc]
 *   @0x21d1c0 ldr r1, [pc, #0x1dc]
 *   @0x21d1c4 ldr r3, [r4, r3]
 *   @0x21d1c8 add r1, pc, r1
 *   @0x21d1cc ldr r0, [r3]
 *   @0x21d1d0 ldr r3, [r0]
 *   @0x21d1d4 ldr r3, [r3, #0xc]
 *   @0x21d1d8 blx r3
 *   @0x21d1dc b 0x21d1b0 <_Z22Audio_QueueBufferSoundiiii+0xd0>
 *   @0x21d1e0 ldr r3, [pc, #0x1c0]
 *   @0x21d1e4 add r2, sp, #12
 *   @0x21d1e8 mov r1, #1
 *   @0x21d1ec ldr r7, [r4, r3]
 *   @0x21d1f0 ldr r3, [r7]
 *   @0x21d1f4 ldr r0, [r3, r6, lsl #2]
 *   @0x21d1f8 bl 0xb6b8c <alSourceQueueBuffers@plt>
 *   @0x21d1fc bl 0xb6a54 <alGetError@plt>
 *   @0x21d200 subs r2, r0, #0
 *   @0x21d204 bne 0x21d228 <_Z22Audio_QueueBufferSoundiiii+0x148>
 *   @0x21d208 ldr r3, [r7]
 *   @0x21d20c movw r1, #0x1007
 *   @0x21d210 mov r2, #0
 *   @0x21d214 ldr r0, [r3, r6, lsl #2]
 *   @0x21d218 bl 0xb6a6c <alSourcei@plt>
 *   @0x21d21c b 0x21d1a4 <_Z22Audio_QueueBufferSoundiiii+0xc4>
 *   @0x21d220 mvn r0, #0
 *   @0x21d224 b 0x21d1b4 <_Z22Audio_QueueBufferSoundiiii+0xd4>
 *   @0x21d228 ldr r3, [pc, #0x170]
 *   @0x21d22c ldr r1, [pc, #0x178]
 *   @0x21d230 ldr r3, [r4, r3]
 *   @0x21d234 add r1, pc, r1
 *   @0x21d238 ldr r0, [r3]
 *   @0x21d23c ldr r3, [r0]
 *   @0x21d240 ldr r3, [r3, #0xc]
 *   @0x21d244 blx r3
 *   @0x21d248 b 0x21d208 <_Z22Audio_QueueBufferSoundiiii+0x128>
 *   @0x21d24c mov r0, r8
 *   @0x21d250 mov r1, #0
 *   @0x21d254 movt r1, #0x4120
 *   @0x21d258 mov r11, #1065353216
 *   @0x21d25c bl 0x21addc <_Z26Audio_GetSoundSourceToPlayif>
 *   @0x21d260 ldr r3, [pc, #0x148]
 *   @0x21d264 ldr lr, [pc, #0x148]
 *   @0x21d268 movw r1, #0x1023
 *   @0x21d26c ldr r12, [pc, #0x134]
 *   @0x21d270 mov r10, #0
 *   @0x21d274 ldr r2, [r4, r3]
 *   @0x21d278 ldr r3, [r2]
 *   @0x21d27c mov r5, r0
 *   @0x21d280 str r8, [r0, #0x18]
 *   @0x21d284 str r7, [r0, #0x2c]
 *   @0x21d288 add r8, r3, #1
 *   @0x21d28c str r3, [r5, #0x14]
 *   @0x21d290 str r8, [r2]
 *   @0x21d294 mov r2, #0
 *   @0x21d298 str r11, [r5, #0x24]
 *   @0x21d29c movt r2, #0x4120
 *   @0x21d2a0 ldr r3, [r4, lr]
 *   @0x21d2a4 ldr r0, [pc, #0x10c]
 *   @0x21d2a8 strb r7, [r5, #0x4]
 *   @0x21d2ac ldr r3, [r3]
 *   @0x21d2b0 str r2, [r5, #0x1c]
 *   @0x21d2b4 ldr r7, [r5, #0x10]
 *   @0x21d2b8 str r3, [r5, #0x34]
 *   @0x21d2bc ldr r8, [r4, r12]
 *   @0x21d2c0 ldr r2, [r4, r0]
 *   @0x21d2c4 ldr r3, [r8]
 *   @0x21d2c8 ldr r2, [r2]
 *   @0x21d2cc ldr r0, [r3, r7, lsl #2]
 *   @0x21d2d0 bl 0xb6a78 <alSourcef@plt>
 *   @0x21d2d4 ldr r3, [r8]
 *   @0x21d2d8 movw r1, #0x100a
 *   @0x21d2dc ldr r2, [r6, #0x4]
 *   @0x21d2e0 ldr r0, [r3, r7, lsl #2]
 *   @0x21d2e4 bl 0xb6a78 <alSourcef@plt>
 *   @0x21d2e8 ldr r3, [r8]
 *   @0x21d2ec movw r1, #0x1003
 *   @0x21d2f0 ldr r2, [r6, #0x8]
 *   @0x21d2f4 ldr r0, [r3, r7, lsl #2]
 *   @0x21d2f8 bl 0xb6a78 <alSourcef@plt>
 *   @0x21d2fc ldr r3, [r8]
 *   @0x21d300 movw r1, #0x202
 *   @0x21d304 mov r2, #1
 *   @0x21d308 ldr r0, [r3, r7, lsl #2]
 *   @0x21d30c bl 0xb6a6c <alSourcei@plt>
 *   @0x21d310 ldr r0, [r8]
 *   @0x21d314 mov r2, r10
 *   @0x21d318 movw r1, #0x1004
 *   @0x21d31c mov r3, r10
 *   @0x21d320 ldr r0, [r0, r7, lsl #2]
 *   @0x21d324 str r10, [sp]
 *   @0x21d328 bl 0xb6b2c <alSource3f@plt>
 *   @0x21d32c ldr r3, [r8]
 *   @0x21d330 mov r2, r10
 *   @0x21d334 movw r1, #0x1006
 *   @0x21d338 ldr r0, [r3, r7, lsl #2]
 *   @0x21d33c mov r3, r10
 *   @0x21d340 str r10, [sp]
 *   @0x21d344 bl 0xb6b2c <alSource3f@plt>
 *   @0x21d348 str r5, [r6, #0x58]
 *   @0x21d34c b 0x21d190 <_Z22Audio_QueueBufferSoundiiii+0xb0>
 *   @0x21d350 ldr r1, [pc, #0x64]
 *   @0x21d354 mov r2, r8
 *   @0x21d358 ldr r3, [pc, #0x40]
 *   @0x21d35c add r1, pc, r1
 *   @0x21d360 ldr r3, [r4, r3]
 *   @0x21d364 ldr r0, [r3]
 *   @0x21d368 ldr r3, [r0]
 *   @0x21d36c ldr r3, [r3, #0xc]
 *   @0x21d370 blx r3
 *   @0x21d374 mvn r0, #0
 *   @0x21d378 b 0x21d1b4 <_Z22Audio_QueueBufferSoundiiii+0xd4>
 *   @0x21d37c ldr r1, [pc, #0x3c]
 *   @0x21d380 mov r2, r5
 *   @0x21d384 ldr r3, [pc, #0x14]
 *   @0x21d388 add r1, pc, r1
 *   @0x21d38c b 0x21d360 <_Z22Audio_QueueBufferSoundiiii+0x280>
 *   @0x21d390 andseq r4, sp, r8, asr r11
 *   @0x21d394 .word 0xffffd3fc
 *   @0x21d398 .word 0xffffd0e0
 *   @0x21d39c subseq r8, r3, r0, ror #2
 *   @0x21d3a0 .word 0xffffbac4
 *   @0x21d3a4 andseq r7, r3, r12, lsl #7
 *   @0x21d3a8 .word 0xfffff77c
 *   @0x21d3ac andseq r7, r3, r4, ror #5
 *   @0x21d3b0 .word 0xfffff7a0
 *   @0x21d3b4 .word 0xfffff778
 *   @0x21d3b8 .word 0xfffff7a4
 *   @0x21d3bc andseq r7, r3, r0, asr r1
 *   @0x21d3c0 andseq r7, r3, r8, asr r1
 *
 * ══ §24/42 anon_2be194  0x2be194  size 740  185 条（0x2be194..0x2be478）
 * @func 0x2be194 0x2be478  size 740  185 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2be194+0x11c / anon_2be194+0x294
 * 字段偏移 top8: 0x4×11 / 0x8×7 / 0x14×5 / 0x24×3 / 0x50×3 / 0xc×2 / 0x10×2 / 0x30×2
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2be194 ldr r3, [r0, #0x24]
 *   @0x2be198 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2be19c cmp r3, #0
 *   @0x2be1a0 sub sp, sp, #28
 *   @0x2be1a4 ldr r1, [pc, #0x2ac]
 *   @0x2be1a8 mov r8, r0
 *   @0x2be1ac ldr r6, [r0, #0x19c]
 *   @0x2be1b0 add r1, pc, r1
 *   @0x2be1b4 ldr r5, [r0, #0xc4]
 *   @0x2be1b8 str r1, [sp, #0x8]
 *   @0x2be1bc ble 0x2be2b0 <jinit_color_deconverter+0x348>
 *   @0x2be1c0 ldr r4, [pc, #0x294]
 *   @0x2be1c4 mov r10, #0
 *   @0x2be1c8 ldr r2, [pc, #0x290]
 *   @0x2be1cc sub r6, r6, #4
 *   @0x2be1d0 add r4, pc, r4
 *   @0x2be1d4 mov r9, r10
 *   @0x2be1d8 add r2, pc, r2
 *   @0x2be1dc mov r7, r10
 *   @0x2be1e0 add r3, r2, #128
 *   @0x2be1e4 str r2, [sp, #0xc]
 *   @0x2be1e8 str r3, [sp, #0x10]
 *   @0x2be1ec str r10, [sp, #0x4]
 *   @0x2be1f0 ldr r2, [r5, #0x24]
 *   @0x2be1f4 sub r3, r2, #1
 *   @0x2be1f8 cmp r3, #7
 *   @0x2be1fc addls pc, pc, r3, lsl #2
 *   @0x2be200 b 0x2be31c <jinit_color_deconverter+0x3b4>
 *   @0x2be204 b 0x2be304 <jinit_color_deconverter+0x39c>
 *   @0x2be208 b 0x2be224 <jinit_color_deconverter+0x2bc>
 *   @0x2be20c b 0x2be31c <jinit_color_deconverter+0x3b4>
 *   @0x2be210 b 0x2be2ec <jinit_color_deconverter+0x384>
 *   @0x2be214 b 0x2be31c <jinit_color_deconverter+0x3b4>
 *   @0x2be218 b 0x2be31c <jinit_color_deconverter+0x3b4>
 *   @0x2be21c b 0x2be31c <jinit_color_deconverter+0x3b4>
 *   @0x2be220 b 0x2be2b8 <jinit_color_deconverter+0x350>
 *   @0x2be224 ldr r3, [pc, #0x238]
 *   @0x2be228 mov r9, #0
 *   @0x2be22c ldr r2, [sp, #0x8]
 *   @0x2be230 ldr r3, [r2, r3]
 *   @0x2be234 str r3, [sp, #0x4]
 *   @0x2be238 ldr r2, [sp, #0x4]
 *   @0x2be23c add r6, r6, #4
 *   @0x2be240 str r2, [r6, #0x4]
 *   @0x2be244 ldrb r3, [r5, #0x30]
 *   @0x2be248 cmp r3, #0
 *   @0x2be24c beq 0x2be29c <jinit_color_deconverter+0x334>
 *   @0x2be250 ldr r3, [r6, #0x2c]
 *   @0x2be254 cmp r3, r9
 *   @0x2be258 beq 0x2be29c <jinit_color_deconverter+0x334>
 *   @0x2be25c ldr r11, [r5, #0x4c]
 *   @0x2be260 cmp r11, #0
 *   @0x2be264 beq 0x2be29c <jinit_color_deconverter+0x334>
 *   @0x2be268 cmp r9, #1
 *   @0x2be26c str r9, [r6, #0x2c]
 *   @0x2be270 beq 0x2be3d8 <jinit_color_deconverter+0x470>
 *   @0x2be274 cmp r9, #2
 *   @0x2be278 beq 0x2be364 <jinit_color_deconverter+0x3fc>
 *   @0x2be27c cmp r9, #0
 *   @0x2be280 beq 0x2be340 <jinit_color_deconverter+0x3d8>
 *   @0x2be284 ldr r3, [r8]
 *   @0x2be288 mov r2, #48
 *   @0x2be28c mov r0, r8
 *   @0x2be290 str r2, [r3, #0x14]
 *   @0x2be294 ldr r3, [r3]
 *   @0x2be298 blx r3
 *   @0x2be29c ldr r3, [r8, #0x24]
 *   @0x2be2a0 add r7, r7, #1
 *   @0x2be2a4 add r5, r5, #84
 *   @0x2be2a8 cmp r3, r7
 *   @0x2be2ac bgt 0x2be1f0 <jinit_color_deconverter+0x288>
 *   @0x2be2b0 add sp, sp, #28
 *   @0x2be2b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2be2b8 ldr r3, [r8, #0x44]
 *   @0x2be2bc cmp r3, #1
 *   @0x2be2c0 beq 0x2be440 <jinit_color_deconverter+0x4d8>
 *   @0x2be2c4 blo 0x2be428 <jinit_color_deconverter+0x4c0>
 *   @0x2be2c8 cmp r3, #2
 *   @0x2be2cc bne 0x2be40c <jinit_color_deconverter+0x4a4>
 *   @0x2be2d0 ldr r2, [pc, #0x190]
 *   @0x2be2d4 mov r9, r3
 *   @0x2be2d8 mov r3, r2
 *   @0x2be2dc ldr r2, [sp, #0x8]
 *   @0x2be2e0 ldr r3, [r2, r3]
 *   @0x2be2e4 str r3, [sp, #0x4]
 *   @0x2be2e8 b 0x2be238 <jinit_color_deconverter+0x2d0>
 *   @0x2be2ec ldr r3, [pc, #0x178]
 *   @0x2be2f0 mov r9, #0
 *   @0x2be2f4 ldr r2, [sp, #0x8]
 *   @0x2be2f8 ldr r3, [r2, r3]
 *   @0x2be2fc str r3, [sp, #0x4]
 *   @0x2be300 b 0x2be238 <jinit_color_deconverter+0x2d0>
 *   @0x2be304 ldr r3, [pc, #0x164]
 *   @0x2be308 mov r9, #0
 *   @0x2be30c ldr r1, [sp, #0x8]
 *   @0x2be310 ldr r3, [r1, r3]
 *   @0x2be314 str r3, [sp, #0x4]
 *   @0x2be318 b 0x2be238 <jinit_color_deconverter+0x2d0>
 *   @0x2be31c ldr r3, [r8]
 *   @0x2be320 mov r1, #7
 *   @0x2be324 mov r0, r8
 *   @0x2be328 str r2, [r3, #0x18]
 *   @0x2be32c ldr r2, [r8]
 *   @0x2be330 str r1, [r3, #0x14]
 *   @0x2be334 ldr r3, [r2]
 *   @0x2be338 blx r3
 *   @0x2be33c b 0x2be238 <jinit_color_deconverter+0x2d0>
 *   @0x2be340 ldr r2, [r5, #0x50]
 *   @0x2be344 mov r3, r9
 *   @0x2be348 sub r2, r2, #4
 *   @0x2be34c ldrh r1, [r11, r3]
 *   @0x2be350 add r3, r3, #2
 *   @0x2be354 cmp r3, #128
 *   @0x2be358 str r1, [r2, #0x4]!
 *   @0x2be35c bne 0x2be34c <jinit_color_deconverter+0x3e4>
 *   @0x2be360 b 0x2be29c <jinit_color_deconverter+0x334>
 *   @0x2be364 ldr r3, [sp, #0xc]
 *   @0x2be368 sub r11, r11, #2
 *   @0x2be36c ldr r0, [sp, #0x10]
 *   @0x2be370 ldr r10, [r5, #0x50]
 *   @0x2be374 add r12, r3, #192
 *   @0x2be378 str r9, [sp, #0x14]
 *   @0x2be37c mov r9, r0
 *   @0x2be380 mov r1, r10
 *   @0x2be384 mov r3, r9
 *   @0x2be388 mov r2, r11
 *   @0x2be38c vldmia r0!, {d5}
 *   @0x2be390 str r0, [sp]
 *   @0x2be394 ldrh r0, [r2, #2]!
 *   @0x2be398 vldmia r3!, {d6}
 *   @0x2be39c cmp r12, r3
 *   @0x2be3a0 vmov s14, r0
 *   @0x2be3a4 vcvt.f64.u32 d7, s14
 *   @0x2be3a8 vmul.f64 d7, d7, d5
 *   @0x2be3ac vmul.f64 d7, d7, d6
 *   @0x2be3b0 vcvt.f32.f64 s14, d7
 *   @0x2be3b4 vstmia r1!, {s14}
 *   @0x2be3b8 bne 0x2be394 <jinit_color_deconverter+0x42c>
 *   @0x2be3bc ldr r0, [sp]
 *   @0x2be3c0 add r11, r11, #16
 *   @0x2be3c4 add r10, r10, #32
 *   @0x2be3c8 cmp r0, r12
 *   @0x2be3cc bne 0x2be380 <jinit_color_deconverter+0x418>
 *   @0x2be3d0 ldr r9, [sp, #0x14]
 *   @0x2be3d4 b 0x2be29c <jinit_color_deconverter+0x334>
 *   @0x2be3d8 ldr r2, [r5, #0x50]
 *   @0x2be3dc mov r3, #0
 *   @0x2be3e0 sub r2, r2, #4
 *   @0x2be3e4 ldrh r1, [r11, r3]
 *   @0x2be3e8 ldrsh r0, [r3, r4]
 *   @0x2be3ec add r3, r3, #2
 *   @0x2be3f0 cmp r3, #128
 *   @0x2be3f4 mul r1, r0, r1
 *   @0x2be3f8 add r1, r1, #2048
 *   @0x2be3fc asr r1, r1, #12
 *   @0x2be400 str r1, [r2, #0x4]!
 *   @0x2be404 bne 0x2be3e4 <jinit_color_deconverter+0x47c>
 *   @0x2be408 b 0x2be29c <jinit_color_deconverter+0x334>
 *   @0x2be40c ldr r3, [r8]
 *   @0x2be410 mov r2, #48
 *   @0x2be414 mov r0, r8
 *   @0x2be418 str r2, [r3, #0x14]
 *   @0x2be41c ldr r3, [r3]
 *   @0x2be420 blx r3
 *   @0x2be424 b 0x2be238 <jinit_color_deconverter+0x2d0>
 *   @0x2be428 ldr r3, [pc, #0x44]
 *   @0x2be42c mov r9, #0
 *   @0x2be430 ldr r1, [sp, #0x8]
 *   @0x2be434 ldr r3, [r1, r3]
 *   @0x2be438 str r3, [sp, #0x4]
 *   @0x2be43c b 0x2be238 <jinit_color_deconverter+0x2d0>
 *   @0x2be440 ldr r2, [pc, #0x30]
 *   @0x2be444 mov r9, r3
 *   @0x2be448 ldr r1, [sp, #0x8]
 *   @0x2be44c ldr r3, [r1, r2]
 *   @0x2be450 str r3, [sp, #0x4]
 *   @0x2be454 b 0x2be238 <jinit_color_deconverter+0x2d0>
 *   @0x2be458 andseq r3, r3, r0, lsr #21
 *   @0x2be45c andeq r1, sp, r0, asr pc
 *   @0x2be460 andeq r1, sp, r8, asr #30
 *   @0x2be464 .word 0xfffffe60
 *   @0x2be468 .word 0xfffffe64
 *   @0x2be46c .word 0xfffffe68
 *   @0x2be470 .word 0xfffffe6c
 *   @0x2be474 .word 0xfffffe70
 *
 * ══ §25/42 F_DsListFindValue(RValue&, CInstance*, CInstance*, int, RValue*)  0x106634  size 736  184 条（0x106634..0x106914）
 * @func 0x106634 0x106914  size 736  184 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYGetInt32(RValue const*, int)×2 / F_DsListFindValue(RValue&, CInstance*, CInstance*, int, RValue*)+0x120 / CDS_List::GetValue(int) / GetContextStackTop()
 * 字段偏移 top8: 0x4×9 / 0x8×8 / 0xc×7 / 0x18×1 / 0x2ac×1 / 0x29c×1 / 0x2×1 / 0x1b4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x106634 push {r3, r4, r5, r6, r7, lr}
 *   @0x106638 mov r1, #0
 *   @0x10663c ldr r5, [sp, #0x18]
 *   @0x106640 mov r4, r0
 *   @0x106644 mov r0, r5
 *   @0x106648 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10664c cmp r0, #0
 *   @0x106650 blt 0x106754 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x106654 ldr r3, [pc, #0x2ac]
 *   @0x106658 ldr r3, [pc, r3]
 *   @0x10665c ldr r3, [r3]
 *   @0x106660 cmp r0, r3
 *   @0x106664 bge 0x106754 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x106668 ldr r3, [pc, #0x29c]
 *   @0x10666c ldr r3, [pc, r3]
 *   @0x106670 ldr r3, [r3, #0x4]
 *   @0x106674 ldr r6, [r3, r0, lsl #2]
 *   @0x106678 cmp r6, #0
 *   @0x10667c beq 0x106754 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x106680 mov r0, r5
 *   @0x106684 mov r1, #1
 *   @0x106688 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10668c mov r1, r0
 *   @0x106690 mov r0, r6
 *   @0x106694 bl 0x2031f4 <_ZN8CDS_List8GetValueEi>
 *   @0x106698 subs r5, r0, #0
 *   @0x10669c streq r5, [r4]
 *   @0x1066a0 streq r5, [r4, #0x4]
 *   @0x1066a4 moveq r3, #5
 *   @0x1066a8 streq r3, [r4, #0xc]
 *   @0x1066ac popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1066b0 ldr r2, [r4, #0xc]
 *   @0x1066b4 bic r3, r2, #-16777216
 *   @0x1066b8 cmp r3, #1
 *   @0x1066bc beq 0x106788 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x1066c0 cmp r3, #2
 *   @0x1066c4 bne 0x1066ec <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x1066c8 sub r2, r2, #1
 *   @0x1066cc bic r2, r2, #-16777216
 *   @0x1066d0 bic r2, r2, #3
 *   @0x1066d4 cmp r2, #0
 *   @0x1066d8 beq 0x106864 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x230>
 *   @0x1066dc mov r2, #0
 *   @0x1066e0 mov r3, #5
 *   @0x1066e4 str r2, [r4, #0x8]
 *   @0x1066e8 str r3, [r4, #0xc]
 *   @0x1066ec ldr r3, [r5, #0xc]
 *   @0x1066f0 mov r2, #0
 *   @0x1066f4 ldr r1, [r5, #0x8]
 *   @0x1066f8 str r2, [r4]
 *   @0x1066fc str r3, [r4, #0xc]
 *   @0x106700 ldr r2, [r5, #0xc]
 *   @0x106704 str r1, [r4, #0x8]
 *   @0x106708 bic r2, r2, #-16777216
 *   @0x10670c cmp r2, #14
 *   @0x106710 addls pc, pc, r2, lsl #2
 *   @0x106714 b 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x106718 b 0x10677c <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x10671c b 0x1067e4 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x1b0>
 *   @0x106720 b 0x106800 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x1cc>
 *   @0x106724 b 0x106768 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x106728 b 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x10672c b 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x106730 b 0x1067bc <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x188>
 *   @0x106734 b 0x106768 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x106738 b 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x10673c b 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x106740 b 0x10677c <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x106744 b 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x106748 b 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x10674c b 0x10677c <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x106750 b 0x106768 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x106754 ldr r0, [pc, #0x1b4]
 *   @0x106758 mov r1, #0
 *   @0x10675c pop {r3, r4, r5, r6, r7, lr}
 *   @0x106760 add r0, pc, r0
 *   @0x106764 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x106768 ldr r2, [r5]
 *   @0x10676c str r2, [r4]
 *   @0x106770 bic r3, r3, #-16777216
 *   @0x106774 str r3, [r4, #0xc]
 *   @0x106778 pop {r3, r4, r5, r6, r7, pc}
 *   @0x10677c ldm r5, {r1, r2}
 *   @0x106780 stm r4, {r1, r2}
 *   @0x106784 b 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x106788 ldr r6, [r4]
 *   @0x10678c cmp r6, #0
 *   @0x106790 beq 0x1067b0 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x106794 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x106798 ldr r7, [r6, #0x4]
 *   @0x10679c sub r7, r7, #1
 *   @0x1067a0 str r7, [r6, #0x4]
 *   @0x1067a4 cmp r7, #0
 *   @0x1067a8 beq 0x10682c <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0x1067ac bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1067b0 mov r3, #0
 *   @0x1067b4 str r3, [r4]
 *   @0x1067b8 b 0x1066ec <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x1067bc ldr r2, [r5]
 *   @0x1067c0 str r2, [r4]
 *   @0x1067c4 ldr r2, [r5]
 *   @0x1067c8 cmp r2, #0
 *   @0x1067cc beq 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x1067d0 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x1067d4 ldr r1, [r5]
 *   @0x1067d8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x1067dc ldr r3, [r4, #0xc]
 *   @0x1067e0 b 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x1067e4 ldr r2, [r5]
 *   @0x1067e8 cmp r2, #0
 *   @0x1067ec ldrne r3, [r2, #0x4]
 *   @0x1067f0 addne r3, r3, #1
 *   @0x1067f4 strne r3, [r2, #0x4]
 *   @0x1067f8 ldrne r3, [r4, #0xc]
 *   @0x1067fc b 0x10676c <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x106800 ldr r2, [r5]
 *   @0x106804 cmp r2, #0
 *   @0x106808 str r2, [r4]
 *   @0x10680c beq 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x106810 ldr r0, [r2, #0x8]
 *   @0x106814 ldr r1, [r2]
 *   @0x106818 cmp r0, #0
 *   @0x10681c streq r4, [r2, #0x8]
 *   @0x106820 add r1, r1, #1
 *   @0x106824 str r1, [r2]
 *   @0x106828 b 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x10682c ldr r0, [r6]
 *   @0x106830 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x106834 str r7, [r6]
 *   @0x106838 str r7, [r6, #0x8]
 *   @0x10683c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x106840 ldr r7, [r6, #0x4]
 *   @0x106844 sub r7, r7, #1
 *   @0x106848 str r7, [r6, #0x4]
 *   @0x10684c cmp r7, #0
 *   @0x106850 beq 0x106870 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x23c>
 *   @0x106854 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x106858 mov r0, r6
 *   @0x10685c bl 0x27d1d0 <_ZdlPv>
 *   @0x106860 b 0x1067ac <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x106864 mov r0, r4
 *   @0x106868 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x10686c b 0x1066dc <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x106870 ldr r0, [r6]
 *   @0x106874 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x106878 str r7, [r6]
 *   @0x10687c str r7, [r6, #0x8]
 *   @0x106880 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x106884 ldr r7, [r6, #0x4]
 *   @0x106888 sub r7, r7, #1
 *   @0x10688c str r7, [r6, #0x4]
 *   @0x106890 cmp r7, #0
 *   @0x106894 beq 0x1068a8 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x274>
 *   @0x106898 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x10689c mov r0, r6
 *   @0x1068a0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1068a4 b 0x106854 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x220>
 *   @0x1068a8 ldr r0, [r6]
 *   @0x1068ac bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1068b0 str r7, [r6]
 *   @0x1068b4 str r7, [r6, #0x8]
 *   @0x1068b8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1068bc ldr r3, [r6, #0x4]
 *   @0x1068c0 sub r3, r3, #1
 *   @0x1068c4 str r3, [r6, #0x4]
 *   @0x1068c8 cmp r3, #0
 *   @0x1068cc beq 0x1068e0 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x2ac>
 *   @0x1068d0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1068d4 mov r0, r6
 *   @0x1068d8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1068dc b 0x106898 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x264>
 *   @0x1068e0 ldr r0, [r6]
 *   @0x1068e4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1068e8 mov r3, #0
 *   @0x1068ec mov r0, r6
 *   @0x1068f0 str r3, [r6]
 *   @0x1068f4 str r3, [r6, #0x8]
 *   @0x1068f8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1068fc mov r0, r6
 *   @0x106900 bl 0x27d1d0 <_ZdlPv>
 *   @0x106904 b 0x1068d0 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x29c>
 *   @0x106908 eoreq r7, lr, r4, lsr #12
 *   @0x10690c eoreq r7, lr, r4, lsl r6
 *   @0x106910 mlaeq r3, r12, r4, r1
 *
 * ══ §26/42 F_ActionExecuteScript(RValue&, CInstance*, CInstance*, int, RValue*)  0x143668  size 736  184 条（0x143668..0x143948）
 * @func 0x143668 0x143948  size 736  184 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: UNLOCK_RVALUE_MUTEX()×3 / operator delete(void*)×3 / LOCK_RVALUE_MUTEX()×2 / FREE_RValue__Pre(RValue*)×2 / YYFree(void const*)×2 / 0xb65b0 / YYGetInt32(RValue const*, int) / Script_Perform(int, CInstance*, CInstance*, int, RValue*, DynamicArrayOfRValue*)
 * 字段偏移 top8: 0x-c×12 / 0x8×11 / 0xc×8 / 0x4×5 / 0x10×3 / 0x14×2 / 0x98×2 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143668 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x14366c sub sp, sp, #116
 *   @0x143670 add r8, sp, #32
 *   @0x143674 add r6, sp, #44
 *   @0x143678 str r0, [sp, #0xc]
 *   @0x14367c add r7, sp, #112
 *   @0x143680 str r1, [sp, #0x10]
 *   @0x143684 mov r0, r8
 *   @0x143688 str r2, [sp, #0x14]
 *   @0x14368c mov r1, #0
 *   @0x143690 mov r2, #80
 *   @0x143694 mov r4, r8
 *   @0x143698 bl 0xb65b0 <memset@plt>
 *   @0x14369c ldr r3, [sp, #0x98]
 *   @0x1436a0 mov r10, #0
 *   @0x1436a4 add r11, r3, #12
 *   @0x1436a8 mov r5, r3
 *   @0x1436ac ldr r2, [r4, #0xc]
 *   @0x1436b0 bic r3, r2, #-16777216
 *   @0x1436b4 cmp r3, #1
 *   @0x1436b8 beq 0x143864 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0x1436bc cmp r3, #2
 *   @0x1436c0 bne 0x1436e4 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x1436c4 sub r2, r2, #1
 *   @0x1436c8 bic r2, r2, #-16777216
 *   @0x1436cc bic r2, r2, #3
 *   @0x1436d0 cmp r2, #0
 *   @0x1436d4 beq 0x1438e0 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x278>
 *   @0x1436d8 mov r2, #5
 *   @0x1436dc str r10, [r4, #0x8]
 *   @0x1436e0 str r2, [r4, #0xc]
 *   @0x1436e4 str r10, [r6, #-0xc]
 *   @0x1436e8 ldr r2, [r5, #0xc]
 *   @0x1436ec bic r3, r2, #-16777216
 *   @0x1436f0 str r2, [r4, #0xc]
 *   @0x1436f4 ldr r2, [r5, #0x8]
 *   @0x1436f8 str r2, [r4, #0x8]
 *   @0x1436fc cmp r3, #14
 *   @0x143700 addls pc, pc, r3, lsl #2
 *   @0x143704 b 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x143708 b 0x1437f0 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x188>
 *   @0x14370c b 0x14384c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x143710 b 0x143820 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x143714 b 0x143744 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x143718 b 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x14371c b 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x143720 b 0x1437fc <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x143724 b 0x143744 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x143728 b 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x14372c b 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x143730 b 0x1437f0 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x188>
 *   @0x143734 b 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x143738 b 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x14373c b 0x1437f0 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x188>
 *   @0x143740 b 0x143744 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x143744 ldr r3, [r11, #-0xc]
 *   @0x143748 str r3, [r6, #-0xc]
 *   @0x14374c add r4, r4, #16
 *   @0x143750 add r6, r6, #16
 *   @0x143754 cmp r4, r7
 *   @0x143758 add r11, r11, #16
 *   @0x14375c add r5, r5, #16
 *   @0x143760 bne 0x1436ac <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x143764 mov r5, #0
 *   @0x143768 ldr r0, [sp, #0x98]
 *   @0x14376c mov r1, r5
 *   @0x143770 mov r4, #5
 *   @0x143774 str r8, [sp, #0x1c]
 *   @0x143778 str r4, [sp, #0x18]
 *   @0x14377c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x143780 ldr r2, [sp, #0xc]
 *   @0x143784 mov r3, r4
 *   @0x143788 add r12, sp, #24
 *   @0x14378c ldr r1, [sp, #0x10]
 *   @0x143790 str r12, [sp, #0x4]
 *   @0x143794 str r2, [sp]
 *   @0x143798 ldr r2, [sp, #0x14]
 *   @0x14379c bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue>
 *   @0x1437a0 ldr r3, [pc, #0x198]
 *   @0x1437a4 ldr r3, [pc, r3]
 *   @0x1437a8 ldrb r3, [r3]
 *   @0x1437ac cmp r3, r5
 *   @0x1437b0 bne 0x1438ec <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x284>
 *   @0x1437b4 mov r4, #0
 *   @0x1437b8 mov r5, #5
 *   @0x1437bc ldr r3, [r8, #0xc]
 *   @0x1437c0 sub r3, r3, #1
 *   @0x1437c4 bic r3, r3, #-16777216
 *   @0x1437c8 bic r3, r3, #3
 *   @0x1437cc cmp r3, #0
 *   @0x1437d0 beq 0x143894 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x22c>
 *   @0x1437d4 str r4, [r8, #0x8]
 *   @0x1437d8 str r5, [r8, #0xc]
 *   @0x1437dc str r4, [r8], #16
 *   @0x1437e0 cmp r8, r7
 *   @0x1437e4 bne 0x1437bc <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x1437e8 add sp, sp, #116
 *   @0x1437ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1437f0 ldm r5, {r2, r3}
 *   @0x1437f4 stm r4, {r2, r3}
 *   @0x1437f8 b 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x1437fc ldr r3, [r11, #-0xc]
 *   @0x143800 str r3, [r6, #-0xc]
 *   @0x143804 ldr r3, [r11, #-0xc]
 *   @0x143808 cmp r3, #0
 *   @0x14380c beq 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x143810 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x143814 ldr r1, [r11, #-0xc]
 *   @0x143818 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x14381c b 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x143820 ldr r3, [r11, #-0xc]
 *   @0x143824 cmp r3, #0
 *   @0x143828 str r3, [r6, #-0xc]
 *   @0x14382c beq 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x143830 ldr r1, [r3, #0x8]
 *   @0x143834 ldr r2, [r3]
 *   @0x143838 cmp r1, #0
 *   @0x14383c streq r4, [r3, #0x8]
 *   @0x143840 add r2, r2, #1
 *   @0x143844 str r2, [r3]
 *   @0x143848 b 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x14384c ldr r3, [r11, #-0xc]
 *   @0x143850 cmp r3, #0
 *   @0x143854 ldrne r2, [r3, #0x4]
 *   @0x143858 addne r2, r2, #1
 *   @0x14385c strne r2, [r3, #0x4]
 *   @0x143860 b 0x143748 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x143864 ldr r9, [r6, #-0xc]
 *   @0x143868 cmp r9, #0
 *   @0x14386c beq 0x14388c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x224>
 *   @0x143870 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x143874 ldr r3, [r9, #0x4]
 *   @0x143878 sub r3, r3, #1
 *   @0x14387c str r3, [r9, #0x4]
 *   @0x143880 cmp r3, #0
 *   @0x143884 beq 0x1438a0 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x238>
 *   @0x143888 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x14388c str r10, [r6, #-0xc]
 *   @0x143890 b 0x1436e4 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x143894 mov r0, r8
 *   @0x143898 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x14389c b 0x1437d4 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x1438a0 ldr r0, [r9]
 *   @0x1438a4 str r3, [sp, #0x8]
 *   @0x1438a8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1438ac ldr r3, [sp, #0x8]
 *   @0x1438b0 str r3, [r9]
 *   @0x1438b4 str r3, [r9, #0x8]
 *   @0x1438b8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1438bc ldr r3, [r9, #0x4]
 *   @0x1438c0 sub r3, r3, #1
 *   @0x1438c4 str r3, [r9, #0x4]
 *   @0x1438c8 cmp r3, #0
 *   @0x1438cc beq 0x143908 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x2a0>
 *   @0x1438d0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1438d4 mov r0, r9
 *   @0x1438d8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1438dc b 0x143888 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x220>
 *   @0x1438e0 mov r0, r4
 *   @0x1438e4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1438e8 b 0x1436d8 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x1438ec ldr r3, [pc, #0x50]
 *   @0x1438f0 mov r1, r5
 *   @0x1438f4 ldr r3, [pc, r3]
 *   @0x1438f8 ldr r3, [r3]
 *   @0x1438fc ldr r0, [r3]
 *   @0x143900 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x143904 b 0x1437b4 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x143908 ldr r0, [r9]
 *   @0x14390c str r3, [sp, #0x8]
 *   @0x143910 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x143914 ldr r3, [sp, #0x8]
 *   @0x143918 mov r0, r9
 *   @0x14391c str r3, [r9]
 *   @0x143920 str r3, [r9, #0x8]
 *   @0x143924 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x143928 mov r0, r9
 *   @0x14392c bl 0x27d1d0 <_ZdlPv>
 *   @0x143930 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x143934 mov r0, r9
 *   @0x143938 bl 0x27d1d0 <_ZdlPv>
 *   @0x14393c b 0x143888 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x220>
 *   @0x143940 eoreq r10, r10, r0, asr #7
 *   @0x143944 eoreq r10, r10, r12, ror r2
 *
 * ══ §27/42 CBitmap32::CBitmap32(int, IBitmap*, bool, bool)  0x166488  size 736  184 条（0x166488..0x166768）
 * @func 0x166488 0x166768  size 736  184 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / CBitmap32::CBitmap32(int, IBitmap*, bool, bool)+0x188×2 / CBitmap32::CBitmap32(int, IBitmap*, bool, bool)+0x170 / CBitmap32::RemoveBackground() / CBitmap32::SmoothEdges() / CBitmap32::CBitmap32(int, IBitmap*, bool, bool)+0x2b8
 * 字段偏移 top8: 0x8×11 / 0xc×9 / 0x4×7 / 0x10×5 / 0x14×5 / 0x2×4 / 0x20×2 / 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x166488 ldr r1, [pc, #0x2cc]
 *   @0x16648c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x166490 subs r10, r2, #0
 *   @0x166494 sub sp, sp, #12
 *   @0x166498 ldr r1, [pc, r1]
 *   @0x16649c mov r5, #0
 *   @0x1664a0 add r1, r1, #8
 *   @0x1664a4 mov r6, r0
 *   @0x1664a8 mov r8, r3
 *   @0x1664ac strb r5, [r0, #0x4]
 *   @0x1664b0 str r1, [r0]
 *   @0x1664b4 str r5, [r0, #0x8]
 *   @0x1664b8 str r5, [r0, #0xc]
 *   @0x1664bc str r5, [r0, #0x10]
 *   @0x1664c0 str r5, [r0, #0x14]
 *   @0x1664c4 ldrb r9, [sp, #0x30]
 *   @0x1664c8 beq 0x1664fc <_ZN9CBitmap32C2EiP7IBitmapbb+0x74>
 *   @0x1664cc ldr r3, [r10]
 *   @0x1664d0 mov r0, r10
 *   @0x1664d4 ldr r3, [r3, #0x20]
 *   @0x1664d8 blx r3
 *   @0x1664dc ldr r3, [r10]
 *   @0x1664e0 cmp r0, #6
 *   @0x1664e4 beq 0x166508 <_ZN9CBitmap32C2EiP7IBitmapbb+0x80>
 *   @0x1664e8 mov r0, r10
 *   @0x1664ec ldr r3, [r3, #0x20]
 *   @0x1664f0 blx r3
 *   @0x1664f4 cmp r0, #7
 *   @0x1664f8 beq 0x166650 <_ZN9CBitmap32C2EiP7IBitmapbb+0x1c8>
 *   @0x1664fc mov r0, r6
 *   @0x166500 add sp, sp, #12
 *   @0x166504 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x166508 mov r4, #1
 *   @0x16650c ldr r3, [r3, #0x10]
 *   @0x166510 strb r4, [r6, #0x4]
 *   @0x166514 mov r0, r10
 *   @0x166518 blx r3
 *   @0x16651c ldr r3, [r10]
 *   @0x166520 ldr r3, [r3, #0x18]
 *   @0x166524 str r0, [r6, #0x8]
 *   @0x166528 mov r0, r10
 *   @0x16652c blx r3
 *   @0x166530 ldr r12, [r6, #0x8]
 *   @0x166534 ldr r1, [pc, #0x224]
 *   @0x166538 mov r3, r4
 *   @0x16653c movw r2, #0x2d9
 *   @0x166540 add r1, pc, r1
 *   @0x166544 str r0, [r6, #0xc]
 *   @0x166548 mul r0, r12, r0
 *   @0x16654c lsl r0, r0, #2
 *   @0x166550 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x166554 ldr lr, [r6, #0x8]
 *   @0x166558 ldr r4, [r6, #0xc]
 *   @0x16655c add r2, sp, #8
 *   @0x166560 ldr r12, [r10]
 *   @0x166564 mov r3, sp
 *   @0x166568 str r5, [r2, #-0x4]!
 *   @0x16656c mov r1, r5
 *   @0x166570 mul lr, r4, lr
 *   @0x166574 str r5, [sp]
 *   @0x166578 lsl lr, lr, #2
 *   @0x16657c str lr, [r6, #0x10]
 *   @0x166580 str r0, [r6, #0x14]
 *   @0x166584 mov r0, r10
 *   @0x166588 ldr r12, [r12, #0x24]
 *   @0x16658c blx r12
 *   @0x166590 ldr r3, [r6, #0xc]
 *   @0x166594 cmp r3, r5
 *   @0x166598 ble 0x166610 <_ZN9CBitmap32C2EiP7IBitmapbb+0x188>
 *   @0x16659c ldr r7, [sp, #0x4]
 *   @0x1665a0 mov r2, r5
 *   @0x1665a4 ldr r12, [r6, #0x8]
 *   @0x1665a8 cmp r12, #0
 *   @0x1665ac ble 0x1665f8 <_ZN9CBitmap32C2EiP7IBitmapbb+0x170>
 *   @0x1665b0 ldr r11, [r6, #0x14]
 *   @0x1665b4 mov lr, #0
 *   @0x1665b8 mov r4, lr
 *   @0x1665bc mla r12, r12, r2, r4
 *   @0x1665c0 add r5, r7, lr
 *   @0x1665c4 ldrb r3, [r7, lr]
 *   @0x1665c8 add r4, r4, #1
 *   @0x1665cc ldrb r1, [r5, #0x2]
 *   @0x1665d0 add lr, lr, #3
 *   @0x1665d4 ldrb r5, [r5, #0x1]
 *   @0x1665d8 add r3, r3, #-16777216
 *   @0x1665dc add r3, r3, r1, lsl #16
 *   @0x1665e0 add r3, r3, r5, lsl #8
 *   @0x1665e4 str r3, [r11, r12, lsl #2]
 *   @0x1665e8 ldr r12, [r6, #0x8]
 *   @0x1665ec cmp r12, r4
 *   @0x1665f0 bgt 0x1665bc <_ZN9CBitmap32C2EiP7IBitmapbb+0x134>
 *   @0x1665f4 ldr r3, [r6, #0xc]
 *   @0x1665f8 add r2, r2, #1
 *   @0x1665fc ldr r1, [sp]
 *   @0x166600 cmp r3, r2
 *   @0x166604 add r7, r7, r1
 *   @0x166608 bgt 0x1665a8 <_ZN9CBitmap32C2EiP7IBitmapbb+0x120>
 *   @0x16660c str r7, [sp, #0x4]
 *   @0x166610 ldr r3, [r10]
 *   @0x166614 mov r1, r0
 *   @0x166618 mov r0, r10
 *   @0x16661c ldr r3, [r3, #0x28]
 *   @0x166620 blx r3
 *   @0x166624 cmp r8, #0
 *   @0x166628 beq 0x1664fc <_ZN9CBitmap32C2EiP7IBitmapbb+0x74>
 *   @0x16662c mov r0, r6
 *   @0x166630 bl 0x166404 <_ZN9CBitmap3216RemoveBackgroundEv>
 *   @0x166634 cmp r9, #0
 *   @0x166638 beq 0x1664fc <_ZN9CBitmap32C2EiP7IBitmapbb+0x74>
 *   @0x16663c mov r0, r6
 *   @0x166640 bl 0x1661fc <_ZN9CBitmap3211SmoothEdgesEv>
 *   @0x166644 mov r0, r6
 *   @0x166648 add sp, sp, #12
 *   @0x16664c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x166650 ldr r3, [r10]
 *   @0x166654 mov r4, #1
 *   @0x166658 mov r0, r10
 *   @0x16665c strb r4, [r6, #0x4]
 *   @0x166660 ldr r3, [r3, #0x10]
 *   @0x166664 blx r3
 *   @0x166668 ldr r3, [r10]
 *   @0x16666c ldr r3, [r3, #0x18]
 *   @0x166670 str r0, [r6, #0x8]
 *   @0x166674 mov r0, r10
 *   @0x166678 blx r3
 *   @0x16667c ldr r12, [r6, #0x8]
 *   @0x166680 ldr r1, [pc, #0xdc]
 *   @0x166684 mov r3, r4
 *   @0x166688 movw r2, #0x2f3
 *   @0x16668c add r1, pc, r1
 *   @0x166690 str r0, [r6, #0xc]
 *   @0x166694 mul r0, r12, r0
 *   @0x166698 lsl r0, r0, #2
 *   @0x16669c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1666a0 ldr lr, [r6, #0x8]
 *   @0x1666a4 ldr r4, [r6, #0xc]
 *   @0x1666a8 add r2, sp, #8
 *   @0x1666ac ldr r12, [r10]
 *   @0x1666b0 mov r3, sp
 *   @0x1666b4 str r5, [r2, #-0x4]!
 *   @0x1666b8 mov r1, r5
 *   @0x1666bc mul lr, r4, lr
 *   @0x1666c0 str r5, [sp]
 *   @0x1666c4 lsl lr, lr, #2
 *   @0x1666c8 str lr, [r6, #0x10]
 *   @0x1666cc str r0, [r6, #0x14]
 *   @0x1666d0 mov r0, r10
 *   @0x1666d4 ldr r12, [r12, #0x24]
 *   @0x1666d8 blx r12
 *   @0x1666dc ldr r3, [r6, #0xc]
 *   @0x1666e0 cmp r3, #0
 *   @0x1666e4 ble 0x166610 <_ZN9CBitmap32C2EiP7IBitmapbb+0x188>
 *   @0x1666e8 ldr r4, [sp, #0x4]
 *   @0x1666ec ldr r12, [r6, #0x8]
 *   @0x1666f0 cmp r12, #0
 *   @0x1666f4 ble 0x166740 <_ZN9CBitmap32C2EiP7IBitmapbb+0x2b8>
 *   @0x1666f8 ldr r7, [r6, #0x14]
 *   @0x1666fc mov r3, #0
 *   @0x166700 mov r2, r3
 *   @0x166704 add lr, r4, r3
 *   @0x166708 ldrb r1, [r4, r3]
 *   @0x16670c mla r12, r12, r5, r2
 *   @0x166710 ldrb r11, [lr, #0x2]
 *   @0x166714 ldrb lr, [lr, #0x1]
 *   @0x166718 add r2, r2, #1
 *   @0x16671c add r3, r3, #4
 *   @0x166720 add lr, lr, r11, lsl #8
 *   @0x166724 add lr, r1, lr, lsl #8
 *   @0x166728 orr lr, lr, #-16777216
 *   @0x16672c str lr, [r7, r12, lsl #2]
 *   @0x166730 ldr r12, [r6, #0x8]
 *   @0x166734 cmp r12, r2
 *   @0x166738 bgt 0x166704 <_ZN9CBitmap32C2EiP7IBitmapbb+0x27c>
 *   @0x16673c ldr r3, [r6, #0xc]
 *   @0x166740 add r5, r5, #1
 *   @0x166744 ldr r2, [sp]
 *   @0x166748 cmp r3, r5
 *   @0x16674c add r4, r4, r2
 *   @0x166750 bgt 0x1666f0 <_ZN9CBitmap32C2EiP7IBitmapbb+0x268>
 *   @0x166754 str r4, [sp, #0x4]
 *   @0x166758 b 0x166610 <_ZN9CBitmap32C2EiP7IBitmapbb+0x188>
 *   @0x16675c eoreq r9, r8, r0, ror #24
 *   @0x166760 andseq r4, lr, r0, lsl #1
 *   @0x166764 andseq r3, lr, r4, lsr pc
 *
 * ══ §28/42 Motion_Grid_AddInstance(int, CInstance*, bool)  0x19a618  size 736  184 条（0x19a618..0x19a8f8）
 * @func 0x19a618 0x19a8f8  size 736  184 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×6 / CInstance::Compute_BoundingBox(bool)×4 / Motion_Grid_AddInstance(int, CInstance*, bool)+0x218×2 / Motion_Grid_AddInstance(int, CInstance*, bool)+0x204 / Motion_Grid_AddInstance(int, CInstance*, bool)+0x1f4 / CInstance::Collision_Rectangle(float, float, float, float, bool)
 * 字段偏移 top8: 0xc×16 / 0x10×7 / 0x14×5 / 0x1c×5 / 0x18×5 / 0x64×4 / 0x4×4 / 0x2×3
 * VFP 指令 25 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19a618 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x19a61c vpush {d8}
 *   @0x19a620 cmp r0, #0
 *   @0x19a624 sub sp, sp, #36
 *   @0x19a628 mov r10, r2
 *   @0x19a62c str r1, [sp, #0xc]
 *   @0x19a630 blt 0x19a830 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x218>
 *   @0x19a634 ldr r3, [pc, #0x2b4]
 *   @0x19a638 ldr r3, [pc, r3]
 *   @0x19a63c ldr r3, [r3]
 *   @0x19a640 cmp r0, r3
 *   @0x19a644 bge 0x19a830 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x218>
 *   @0x19a648 ldr r3, [pc, #0x2a4]
 *   @0x19a64c ldr r3, [pc, r3]
 *   @0x19a650 ldr r3, [r3]
 *   @0x19a654 ldr r5, [r3, r0, lsl #2]
 *   @0x19a658 cmp r5, #0
 *   @0x19a65c beq 0x19a830 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x218>
 *   @0x19a660 cmp r1, #0
 *   @0x19a664 beq 0x19a830 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x218>
 *   @0x19a668 ldrb r4, [r1, #0x64]
 *   @0x19a66c cmp r4, #0
 *   @0x19a670 bne 0x19a83c <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x224>
 *   @0x19a674 ldr r2, [sp, #0xc]
 *   @0x19a678 ldr r8, [r5, #0xc]
 *   @0x19a67c ldr r7, [r5, #0x4]
 *   @0x19a680 ldr r0, [r2, #0xe8]
 *   @0x19a684 mov r1, r8
 *   @0x19a688 rsb r0, r7, r0
 *   @0x19a68c bl 0x318d10 <__divsi3>
 *   @0x19a690 bic r6, r0, r0, asr #31
 *   @0x19a694 ldr r1, [sp, #0xc]
 *   @0x19a698 ldr r0, [r1, #0xf0]
 *   @0x19a69c mov r1, r8
 *   @0x19a6a0 rsb r0, r7, r0
 *   @0x19a6a4 bl 0x318d10 <__divsi3>
 *   @0x19a6a8 ldr r3, [r5, #0x14]
 *   @0x19a6ac cmp r0, r3
 *   @0x19a6b0 str r0, [sp, #0x1c]
 *   @0x19a6b4 subge r3, r3, #1
 *   @0x19a6b8 strge r3, [sp, #0x1c]
 *   @0x19a6bc cmp r4, #0
 *   @0x19a6c0 bne 0x19a898 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x280>
 *   @0x19a6c4 ldr r3, [sp, #0xc]
 *   @0x19a6c8 ldr r7, [r5, #0x10]
 *   @0x19a6cc ldr r4, [r5, #0x8]
 *   @0x19a6d0 ldr r0, [r3, #0xec]
 *   @0x19a6d4 mov r1, r7
 *   @0x19a6d8 rsb r0, r4, r0
 *   @0x19a6dc bl 0x318d10 <__divsi3>
 *   @0x19a6e0 bic r0, r0, r0, asr #31
 *   @0x19a6e4 str r0, [sp, #0x14]
 *   @0x19a6e8 ldr r2, [sp, #0xc]
 *   @0x19a6ec mov r1, r7
 *   @0x19a6f0 ldr r0, [r2, #0xf4]
 *   @0x19a6f4 rsb r0, r4, r0
 *   @0x19a6f8 bl 0x318d10 <__divsi3>
 *   @0x19a6fc ldr r3, [r5, #0x18]
 *   @0x19a700 cmp r0, r3
 *   @0x19a704 mov r9, r0
 *   @0x19a708 subge r9, r3, #1
 *   @0x19a70c ldr r3, [sp, #0x1c]
 *   @0x19a710 cmp r3, r6
 *   @0x19a714 blt 0x19a830 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x218>
 *   @0x19a718 vmov.f32 s16, #1.000000e+00
 *   @0x19a71c add r12, r6, #1
 *   @0x19a720 mvn r11, #0
 *   @0x19a724 ldr r3, [sp, #0x14]
 *   @0x19a728 sub r8, r12, #1
 *   @0x19a72c str r12, [sp, #0x18]
 *   @0x19a730 cmp r9, r3
 *   @0x19a734 blt 0x19a81c <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x204>
 *   @0x19a738 ldr r1, [sp, #0x14]
 *   @0x19a73c str r12, [sp, #0x10]
 *   @0x19a740 add r4, r1, #1
 *   @0x19a744 cmp r10, #0
 *   @0x19a748 mov r6, r4
 *   @0x19a74c sub r7, r4, #1
 *   @0x19a750 beq 0x19a7fc <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x1e4>
 *   @0x19a754 ldr r2, [r5, #0x18]
 *   @0x19a758 mov r6, r4
 *   @0x19a75c ldr r3, [r5, #0x1c]
 *   @0x19a760 ldr r0, [sp, #0xc]
 *   @0x19a764 mla r2, r2, r8, r7
 *   @0x19a768 ldr r3, [r3, r2, lsl #2]
 *   @0x19a76c cmp r3, #0
 *   @0x19a770 blt 0x19a80c <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x1f4>
 *   @0x19a774 ldr r2, [r5, #0x10]
 *   @0x19a778 vldr s13, [r5, #8]
 *   @0x19a77c vcvt.f32.s32 s15, s13
 *   @0x19a780 ldr r3, [r5, #0xc]
 *   @0x19a784 vldr s14, [r5, #4]
 *   @0x19a788 mul r1, r4, r2
 *   @0x19a78c mul r2, r7, r2
 *   @0x19a790 vcvt.f32.s32 s14, s14
 *   @0x19a794 vmov s10, r1
 *   @0x19a798 ldr r1, [sp, #0x10]
 *   @0x19a79c mul r1, r1, r3
 *   @0x19a7a0 mul r3, r8, r3
 *   @0x19a7a4 vcvt.f32.s32 s10, s10
 *   @0x19a7a8 vmov s11, r1
 *   @0x19a7ac mov r1, #1
 *   @0x19a7b0 str r1, [sp, #0x4]
 *   @0x19a7b4 vadd.f32 s10, s15, s10
 *   @0x19a7b8 vsub.f32 s10, s10, s16
 *   @0x19a7bc vcvt.f32.s32 s11, s11
 *   @0x19a7c0 vstr s10, [sp]
 *   @0x19a7c4 vmov s10, r3
 *   @0x19a7c8 vadd.f32 s11, s14, s11
 *   @0x19a7cc vcvt.f32.s32 s12, s10
 *   @0x19a7d0 vmov s10, r2
 *   @0x19a7d4 vcvt.f32.s32 s13, s10
 *   @0x19a7d8 vsub.f32 s11, s11, s16
 *   @0x19a7dc vadd.f32 s12, s14, s12
 *   @0x19a7e0 vmov r3, s11
 *   @0x19a7e4 vadd.f32 s13, s15, s13
 *   @0x19a7e8 vmov r1, s12
 *   @0x19a7ec vmov r2, s13
 *   @0x19a7f0 bl 0x1946f4 <_ZN9CInstance19Collision_RectangleEffffb>
 *   @0x19a7f4 cmp r0, #0
 *   @0x19a7f8 beq 0x19a80c <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x1f4>
 *   @0x19a7fc ldr r2, [r5, #0x18]
 *   @0x19a800 ldr r3, [r5, #0x1c]
 *   @0x19a804 mla r7, r2, r8, r7
 *   @0x19a808 str r11, [r3, r7, lsl #2]
 *   @0x19a80c cmp r9, r6
 *   @0x19a810 add r4, r4, #1
 *   @0x19a814 bge 0x19a744 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x12c>
 *   @0x19a818 ldr r12, [sp, #0x10]
 *   @0x19a81c ldr r1, [sp, #0x1c]
 *   @0x19a820 add r12, r12, #1
 *   @0x19a824 ldr r2, [sp, #0x18]
 *   @0x19a828 cmp r1, r2
 *   @0x19a82c bge 0x19a724 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x10c>
 *   @0x19a830 add sp, sp, #36
 *   @0x19a834 vpop {d8}
 *   @0x19a838 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x19a83c mov r0, r1
 *   @0x19a840 mov r1, #1
 *   @0x19a844 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x19a848 ldr r1, [sp, #0xc]
 *   @0x19a84c ldr r8, [r5, #0xc]
 *   @0x19a850 ldr r7, [r5, #0x4]
 *   @0x19a854 ldr r0, [r1, #0xe8]
 *   @0x19a858 mov r1, r8
 *   @0x19a85c rsb r0, r7, r0
 *   @0x19a860 bl 0x318d10 <__divsi3>
 *   @0x19a864 ldr r2, [sp, #0xc]
 *   @0x19a868 ldrb r4, [r2, #0x64]
 *   @0x19a86c cmp r4, #0
 *   @0x19a870 bic r6, r0, r0, asr #31
 *   @0x19a874 beq 0x19a694 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x7c>
 *   @0x19a878 mov r0, r2
 *   @0x19a87c mov r1, #1
 *   @0x19a880 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x19a884 ldr r3, [sp, #0xc]
 *   @0x19a888 ldr r7, [r5, #0x4]
 *   @0x19a88c ldr r8, [r5, #0xc]
 *   @0x19a890 ldrb r4, [r3, #0x64]
 *   @0x19a894 b 0x19a694 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x7c>
 *   @0x19a898 ldr r0, [sp, #0xc]
 *   @0x19a89c mov r1, #1
 *   @0x19a8a0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x19a8a4 ldr r2, [sp, #0xc]
 *   @0x19a8a8 ldr r7, [r5, #0x10]
 *   @0x19a8ac ldr r4, [r5, #0x8]
 *   @0x19a8b0 ldr r0, [r2, #0xec]
 *   @0x19a8b4 mov r1, r7
 *   @0x19a8b8 rsb r0, r4, r0
 *   @0x19a8bc bl 0x318d10 <__divsi3>
 *   @0x19a8c0 ldr r1, [sp, #0xc]
 *   @0x19a8c4 ldrb r3, [r1, #0x64]
 *   @0x19a8c8 cmp r3, #0
 *   @0x19a8cc bic r0, r0, r0, asr #31
 *   @0x19a8d0 str r0, [sp, #0x14]
 *   @0x19a8d4 beq 0x19a6e8 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0xd0>
 *   @0x19a8d8 mov r0, r1
 *   @0x19a8dc mov r1, #1
 *   @0x19a8e0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x19a8e4 ldr r4, [r5, #0x8]
 *   @0x19a8e8 ldr r7, [r5, #0x10]
 *   @0x19a8ec b 0x19a6e8 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0xd0>
 *   @0x19a8f0 eoreq r6, r5, r4, ror r0
 *   @0x19a8f4 eoreq r6, r5, r4, rrx
 *
 * ══ §29/42 TimeLine_Load(unsigned char*, unsigned int, unsigned char*)  0x1f2770  size 736  184 条（0x1f2770..0x1f2a50）
 * @func 0x1f2770 0x1f2a50  size 736  184 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×6 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)×2 / TimeLine_Load(unsigned char*, unsigned int, unsigned char*)+0xb4 / TimeLine_Load(unsigned char*, unsigned int, unsigned char*)+0x50 / TimeLine_Load(unsigned char*, unsigned int, unsigned char*)+0x138 / MemoryManager::IsAllocated(void const*) / TimeLine_Load(unsigned char*, unsigned int, unsigned char*)+0xfc / operator new(unsigned int)
 * 字段偏移 top8: 0x4×21 / 0x2×4 / 0x14×3 / 0x10×3 / 0x8×3 / 0xc×3 / 0x2bc×1 / 0x1f8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f2770 ldr r3, [pc, #0x2bc]
 *   @0x1f2774 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1f2778 add r3, pc, r3
 *   @0x1f277c ldr r9, [r0]
 *   @0x1f2780 sub sp, sp, #28
 *   @0x1f2784 ldr r5, [r3]
 *   @0x1f2788 mov r8, r0
 *   @0x1f278c str r2, [sp, #0x14]
 *   @0x1f2790 ldr r12, [r5]
 *   @0x1f2794 cmp r9, r12
 *   @0x1f2798 beq 0x1f2838 <_Z13TimeLine_LoadPhjS_+0xc8>
 *   @0x1f279c cmp r9, #0
 *   @0x1f27a0 ldr r3, [r5, #0x4]
 *   @0x1f27a4 bne 0x1f29e8 <_Z13TimeLine_LoadPhjS_+0x278>
 *   @0x1f27a8 cmp r3, #0
 *   @0x1f27ac beq 0x1f29e8 <_Z13TimeLine_LoadPhjS_+0x278>
 *   @0x1f27b0 cmp r12, #0
 *   @0x1f27b4 ble 0x1f2824 <_Z13TimeLine_LoadPhjS_+0xb4>
 *   @0x1f27b8 mov r4, r9
 *   @0x1f27bc mov r7, r9
 *   @0x1f27c0 ldr r0, [r3]
 *   @0x1f27c4 movw r2, #0xfeee
 *   @0x1f27c8 movt r2, #0xfeee
 *   @0x1f27cc movw r1, #0xfeee
 *   @0x1f27d0 cmp r0, r2
 *   @0x1f27d4 movt r1, #0xfeee
 *   @0x1f27d8 lsl r6, r4, #2
 *   @0x1f27dc beq 0x1f2818 <_Z13TimeLine_LoadPhjS_+0xa8>
 *   @0x1f27e0 ldr r2, [r3, r4, lsl #2]
 *   @0x1f27e4 add lr, r3, r6
 *   @0x1f27e8 cmp r2, #0
 *   @0x1f27ec mov r0, r2
 *   @0x1f27f0 beq 0x1f2818 <_Z13TimeLine_LoadPhjS_+0xa8>
 *   @0x1f27f4 ldr r3, [r2]
 *   @0x1f27f8 cmp r3, r1
 *   @0x1f27fc beq 0x1f2810 <_Z13TimeLine_LoadPhjS_+0xa0>
 *   @0x1f2800 ldr r3, [r3, #0x4]
 *   @0x1f2804 blx r3
 *   @0x1f2808 ldm r5, {r12, lr}
 *   @0x1f280c add lr, lr, r6
 *   @0x1f2810 str r7, [lr]
 *   @0x1f2814 ldr r3, [r5, #0x4]
 *   @0x1f2818 add r4, r4, #1
 *   @0x1f281c cmp r4, r12
 *   @0x1f2820 blt 0x1f27c0 <_Z13TimeLine_LoadPhjS_+0x50>
 *   @0x1f2824 mov r0, r3
 *   @0x1f2828 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f282c mov r3, #0
 *   @0x1f2830 str r9, [r5]
 *   @0x1f2834 str r3, [r5, #0x4]
 *   @0x1f2838 ldr r3, [pc, #0x1f8]
 *   @0x1f283c cmp r9, #0
 *   @0x1f2840 add r3, pc, r3
 *   @0x1f2844 ldr r5, [r3, #0x4]
 *   @0x1f2848 ldr r0, [r5, #0x4]
 *   @0x1f284c bne 0x1f29bc <_Z13TimeLine_LoadPhjS_+0x24c>
 *   @0x1f2850 cmp r0, #0
 *   @0x1f2854 beq 0x1f29bc <_Z13TimeLine_LoadPhjS_+0x24c>
 *   @0x1f2858 ldr r3, [r5]
 *   @0x1f285c cmp r3, #0
 *   @0x1f2860 ble 0x1f28a8 <_Z13TimeLine_LoadPhjS_+0x138>
 *   @0x1f2864 mov r4, r9
 *   @0x1f2868 mov r7, r9
 *   @0x1f286c ldr r0, [r0, r4, lsl #2]
 *   @0x1f2870 lsl r6, r4, #2
 *   @0x1f2874 bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv>
 *   @0x1f2878 cmp r0, #0
 *   @0x1f287c beq 0x1f288c <_Z13TimeLine_LoadPhjS_+0x11c>
 *   @0x1f2880 ldr r3, [r5, #0x4]
 *   @0x1f2884 ldr r0, [r3, r4, lsl #2]
 *   @0x1f2888 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f288c ldr r2, [r5]
 *   @0x1f2890 add r4, r4, #1
 *   @0x1f2894 ldr r3, [r5, #0x4]
 *   @0x1f2898 cmp r4, r2
 *   @0x1f289c str r7, [r3, r6]
 *   @0x1f28a0 ldr r0, [r5, #0x4]
 *   @0x1f28a4 blt 0x1f286c <_Z13TimeLine_LoadPhjS_+0xfc>
 *   @0x1f28a8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f28ac mov r3, #0
 *   @0x1f28b0 str r3, [r5, #0x4]
 *   @0x1f28b4 cmp r9, #0
 *   @0x1f28b8 str r9, [r5]
 *   @0x1f28bc beq 0x1f29b0 <_Z13TimeLine_LoadPhjS_+0x240>
 *   @0x1f28c0 ldr r10, [pc, #0x174]
 *   @0x1f28c4 mov r5, #0
 *   @0x1f28c8 mov r7, r5
 *   @0x1f28cc str r9, [sp, #0x10]
 *   @0x1f28d0 add r10, pc, r10
 *   @0x1f28d4 mov r11, r10
 *   @0x1f28d8 ldr r6, [r8, #0x4]!
 *   @0x1f28dc cmp r6, #0
 *   @0x1f28e0 moveq r9, r6
 *   @0x1f28e4 moveq r4, r9
 *   @0x1f28e8 beq 0x1f296c <_Z13TimeLine_LoadPhjS_+0x1fc>
 *   @0x1f28ec ldr r9, [pc, #0x14c]
 *   @0x1f28f0 ldr r9, [pc, r9]
 *   @0x1f28f4 ldr r12, [r9]
 *   @0x1f28f8 adds r1, r12, r6
 *   @0x1f28fc moveq r9, r1
 *   @0x1f2900 moveq r4, r9
 *   @0x1f2904 beq 0x1f296c <_Z13TimeLine_LoadPhjS_+0x1fc>
 *   @0x1f2908 mov r0, #24
 *   @0x1f290c str r12, [sp, #0x8]
 *   @0x1f2910 str r1, [sp, #0xc]
 *   @0x1f2914 bl 0x27c524 <_Znwj>
 *   @0x1f2918 ldr r2, [pc, #0x124]
 *   @0x1f291c ldr r2, [pc, r2]
 *   @0x1f2920 add r2, r2, #8
 *   @0x1f2924 mov r4, r0
 *   @0x1f2928 str r2, [r0]
 *   @0x1f292c str r7, [r0, #0x8]
 *   @0x1f2930 str r7, [r0, #0xc]
 *   @0x1f2934 str r7, [r0, #0x10]
 *   @0x1f2938 str r7, [r0, #0x14]
 *   @0x1f293c bl 0x1f1768 <_ZN9CTimeLine5ClearEv>
 *   @0x1f2940 ldr r1, [sp, #0xc]
 *   @0x1f2944 str r4, [r4, #0x4]
 *   @0x1f2948 mov r0, r4
 *   @0x1f294c ldr r2, [sp, #0x14]
 *   @0x1f2950 bl 0x1f19b4 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh>
 *   @0x1f2954 ldr r12, [sp, #0x8]
 *   @0x1f2958 ldr r1, [r12, r6]
 *   @0x1f295c cmp r1, #0
 *   @0x1f2960 ldrne r6, [r9]
 *   @0x1f2964 moveq r9, r1
 *   @0x1f2968 addne r9, r6, r1
 *   @0x1f296c ldr r3, [r10, #0x4]
 *   @0x1f2970 lsl r6, r5, #2
 *   @0x1f2974 ldr r2, [r3, #0x4]
 *   @0x1f2978 ldr r0, [r2, r5, lsl #2]
 *   @0x1f297c cmp r0, #0
 *   @0x1f2980 beq 0x1f298c <_Z13TimeLine_LoadPhjS_+0x21c>
 *   @0x1f2984 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f2988 ldr r3, [r10, #0x4]
 *   @0x1f298c ldr r2, [r11]
 *   @0x1f2990 add r5, r5, #1
 *   @0x1f2994 ldr r1, [sp, #0x10]
 *   @0x1f2998 ldr r2, [r2, #0x4]
 *   @0x1f299c cmp r5, r1
 *   @0x1f29a0 str r4, [r2, r6]
 *   @0x1f29a4 ldr r3, [r3, #0x4]
 *   @0x1f29a8 str r9, [r3, r6]
 *   @0x1f29ac bne 0x1f28d8 <_Z13TimeLine_LoadPhjS_+0x168>
 *   @0x1f29b0 mov r0, #1
 *   @0x1f29b4 add sp, sp, #28
 *   @0x1f29b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1f29bc lsls r4, r9, #2
 *   @0x1f29c0 beq 0x1f2a04 <_Z13TimeLine_LoadPhjS_+0x294>
 *   @0x1f29c4 ldr r2, [pc, #0x7c]
 *   @0x1f29c8 mov r3, #0
 *   @0x1f29cc mov r1, r4
 *   @0x1f29d0 str r3, [sp]
 *   @0x1f29d4 add r2, pc, r2
 *   @0x1f29d8 mov r3, #92
 *   @0x1f29dc bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1f29e0 str r0, [r5, #0x4]
 *   @0x1f29e4 b 0x1f28b4 <_Z13TimeLine_LoadPhjS_+0x144>
 *   @0x1f29e8 lsls r4, r9, #2
 *   @0x1f29ec mov r0, r3
 *   @0x1f29f0 bne 0x1f2a10 <_Z13TimeLine_LoadPhjS_+0x2a0>
 *   @0x1f29f4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f29f8 str r4, [r5, #0x4]
 *   @0x1f29fc str r9, [r5]
 *   @0x1f2a00 b 0x1f2838 <_Z13TimeLine_LoadPhjS_+0xc8>
 *   @0x1f2a04 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f2a08 str r4, [r5, #0x4]
 *   @0x1f2a0c b 0x1f28b4 <_Z13TimeLine_LoadPhjS_+0x144>
 *   @0x1f2a10 ldr r2, [pc, #0x34]
 *   @0x1f2a14 mov r3, #0
 *   @0x1f2a18 mov r1, r4
 *   @0x1f2a1c str r3, [sp]
 *   @0x1f2a20 add r2, pc, r2
 *   @0x1f2a24 mov r3, #135
 *   @0x1f2a28 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1f2a2c str r0, [r5, #0x4]
 *   @0x1f2a30 b 0x1f29fc <_Z13TimeLine_LoadPhjS_+0x28c>
 *   @0x1f2a34 subseq r0, r6, r4, ror r9
 *   @0x1f2a38 subseq r0, r6, r12, lsr #17
 *   @0x1f2a3c subseq r0, r6, r12, lsl r8
 *   @0x1f2a40 andseq r11, pc, r4, asr r0
 *   @0x1f2a44 andseq lr, pc, r8, lsl #10
 *   @0x1f2a48 andseq pc, r5, r8, asr #26
 *   @0x1f2a4c ldrsbeq r10, [r5], -r0
 *
 * ══ §30/42 Debug_GetData(eNetworkCommand, DbgSocket*, unsigned char*, int)  0x29e22c  size 736  184 条（0x29e22c..0x29e50c）
 * @func 0x29e22c 0x29e50c  size 736  184 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetUint32(RValue const*, int)×4 / Debug_ReadCommand(eNetworkCommand, Buffer_Standard*, Buffer_Standard*)×2 / YYGetInt32(RValue const*, int)×2 / DbgSocket::GetUserData() / AllocateIBuffer(void*, int, bool) / GetIBuffer(int) / DbgSocket::Write(void*, unsigned int) / Debug_GetData(eNetworkCommand, DbgSocket*, unsigned char*, int)+0x174
 * 字段偏移 top8: 0xc×9 / 0x8×8 / 0x38×6 / 0x30×4 / 0x2c×2 / 0x10×2 / 0x1c×1 / 0x4×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29e22c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29e230 sub sp, sp, #20
 *   @0x29e234 mov r8, r0
 *   @0x29e238 mov r0, r1
 *   @0x29e23c mov r6, r3
 *   @0x29e240 mov r5, r2
 *   @0x29e244 str r1, [sp, #0x8]
 *   @0x29e248 bl 0x29d9b0 <_ZN9DbgSocket11GetUserDataEv>
 *   @0x29e24c mov r9, #0
 *   @0x29e250 mov r1, r6
 *   @0x29e254 mov r2, r9
 *   @0x29e258 mov r4, r0
 *   @0x29e25c mov r0, r5
 *   @0x29e260 bl 0xc6a10 <_Z15AllocateIBufferPvib>
 *   @0x29e264 add r7, r4, #44
 *   @0x29e268 str r0, [sp, #0xc]
 *   @0x29e26c bl 0xc6720 <_Z10GetIBufferi>
 *   @0x29e270 ldr r1, [r4]
 *   @0x29e274 mov r2, #465567744
 *   @0x29e278 movw r3, #0xc238
 *   @0x29e27c str r2, [r4, #0x2c]
 *   @0x29e280 movt r3, #0x41e7
 *   @0x29e284 mov r2, r7
 *   @0x29e288 str r3, [r4, #0x30]
 *   @0x29e28c ldr r3, [r1, #0x8]
 *   @0x29e290 mov r1, #5
 *   @0x29e294 str r9, [r4, #0x38]
 *   @0x29e298 mov r5, r0
 *   @0x29e29c mov r0, r4
 *   @0x29e2a0 blx r3
 *   @0x29e2a4 ldr r3, [r4]
 *   @0x29e2a8 str r9, [r4, #0x2c]
 *   @0x29e2ac mov r2, r7
 *   @0x29e2b0 str r9, [r4, #0x30]
 *   @0x29e2b4 mov r1, #5
 *   @0x29e2b8 ldr r3, [r3, #0x8]
 *   @0x29e2bc mov r0, r4
 *   @0x29e2c0 str r9, [r4, #0x38]
 *   @0x29e2c4 add r6, r5, #44
 *   @0x29e2c8 blx r3
 *   @0x29e2cc vmov s13, r8
 *   @0x29e2d0 ldr r3, [r4]
 *   @0x29e2d4 mov r2, r7
 *   @0x29e2d8 vcvt.f64.u32 d7, s13
 *   @0x29e2dc mov r1, #5
 *   @0x29e2e0 str r9, [r4, #0x38]
 *   @0x29e2e4 mov r0, r4
 *   @0x29e2e8 vstr s14, [r4, #44]
 *   @0x29e2ec vstr s15, [r4, #48]
 *   @0x29e2f0 ldr r3, [r3, #0x8]
 *   @0x29e2f4 blx r3
 *   @0x29e2f8 ldr r3, [r5]
 *   @0x29e2fc mov r2, r6
 *   @0x29e300 mov r1, #5
 *   @0x29e304 mov r0, r5
 *   @0x29e308 ldr r3, [r3, #0xc]
 *   @0x29e30c blx r3
 *   @0x29e310 mov r1, r9
 *   @0x29e314 mov r0, r6
 *   @0x29e318 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29e31c ldr r3, [r5]
 *   @0x29e320 mov r2, r6
 *   @0x29e324 mov r1, #5
 *   @0x29e328 mov r0, r5
 *   @0x29e32c ldr r3, [r3, #0xc]
 *   @0x29e330 blx r3
 *   @0x29e334 mov r1, r9
 *   @0x29e338 mov r0, r6
 *   @0x29e33c bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29e340 ldr r3, [r5]
 *   @0x29e344 mov r2, r6
 *   @0x29e348 mov r1, #5
 *   @0x29e34c mov r0, r5
 *   @0x29e350 ldr r3, [r3, #0xc]
 *   @0x29e354 blx r3
 *   @0x29e358 mov r1, r9
 *   @0x29e35c mov r0, r6
 *   @0x29e360 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29e364 ldr r3, [r5]
 *   @0x29e368 mov r2, r6
 *   @0x29e36c mov r1, #5
 *   @0x29e370 mov r0, r5
 *   @0x29e374 ldr r3, [r3, #0xc]
 *   @0x29e378 blx r3
 *   @0x29e37c mov r0, r6
 *   @0x29e380 mov r1, r9
 *   @0x29e384 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29e388 cmp r8, #19
 *   @0x29e38c beq 0x29e428 <_Z13Debug_GetData15eNetworkCommandP9DbgSocketPhi+0x1fc>
 *   @0x29e390 mov r0, r8
 *   @0x29e394 mov r2, r5
 *   @0x29e398 mov r1, r4
 *   @0x29e39c bl 0x29e11c <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_>
 *   @0x29e3a0 ldr r3, [r4]
 *   @0x29e3a4 mov r1, #0
 *   @0x29e3a8 ldr r5, [r4, #0x1c]
 *   @0x29e3ac mov r0, r4
 *   @0x29e3b0 mov r2, #4
 *   @0x29e3b4 mov r6, r1
 *   @0x29e3b8 ldr r3, [r3, #0x10]
 *   @0x29e3bc blx r3
 *   @0x29e3c0 vmov s15, r5
 *   @0x29e3c4 ldr r3, [r4]
 *   @0x29e3c8 mov r2, r7
 *   @0x29e3cc vcvt.f64.u32 d7, s15
 *   @0x29e3d0 str r6, [r4, #0x38]
 *   @0x29e3d4 mov r0, r4
 *   @0x29e3d8 mov r1, #5
 *   @0x29e3dc vmov r8, r9, d7
 *   @0x29e3e0 vstr s14, [r4, #44]
 *   @0x29e3e4 str r9, [r4, #0x30]
 *   @0x29e3e8 ldr r3, [r3, #0x8]
 *   @0x29e3ec blx r3
 *   @0x29e3f0 ldr r3, [r4]
 *   @0x29e3f4 mov r1, r6
 *   @0x29e3f8 mov r2, r5
 *   @0x29e3fc mov r0, r4
 *   @0x29e400 ldr r3, [r3, #0x10]
 *   @0x29e404 blx r3
 *   @0x29e408 ldr r0, [sp, #0x8]
 *   @0x29e40c mov r2, r5
 *   @0x29e410 ldr r1, [r4, #0xc]
 *   @0x29e414 bl 0x29d9a8 <_ZN9DbgSocket5WriteEPvj>
 *   @0x29e418 ldr r0, [sp, #0xc]
 *   @0x29e41c add sp, sp, #20
 *   @0x29e420 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29e424 b 0xc6a88 <_Z11FreeIBufferi>
 *   @0x29e428 ldr r3, [r5]
 *   @0x29e42c mov r2, r6
 *   @0x29e430 mov r1, #6
 *   @0x29e434 mov r0, r5
 *   @0x29e438 ldr r3, [r3, #0xc]
 *   @0x29e43c blx r3
 *   @0x29e440 mov r1, r9
 *   @0x29e444 mov r0, r6
 *   @0x29e448 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x29e44c ldr r3, [r4]
 *   @0x29e450 str r9, [r4, #0x38]
 *   @0x29e454 mov r1, #5
 *   @0x29e458 mov r2, r7
 *   @0x29e45c vmov s13, r0
 *   @0x29e460 mov r8, r0
 *   @0x29e464 mov r0, r4
 *   @0x29e468 vcvt.f64.u32 d7, s13
 *   @0x29e46c vstr s14, [r4, #44]
 *   @0x29e470 vstr s15, [r4, #48]
 *   @0x29e474 ldr r3, [r3, #0x8]
 *   @0x29e478 blx r3
 *   @0x29e47c cmp r8, r9
 *   @0x29e480 ble 0x29e3a0 <_Z13Debug_GetData15eNetworkCommandP9DbgSocketPhi+0x174>
 *   @0x29e484 stm sp, {r7, r8}
 *   @0x29e488 mov r8, r9
 *   @0x29e48c ldr r12, [r5]
 *   @0x29e490 mov r2, r6
 *   @0x29e494 mov r1, #6
 *   @0x29e498 mov r0, r5
 *   @0x29e49c add r8, r8, #1
 *   @0x29e4a0 ldr r12, [r12, #0xc]
 *   @0x29e4a4 blx r12
 *   @0x29e4a8 mov r1, #0
 *   @0x29e4ac mov r0, r6
 *   @0x29e4b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x29e4b4 ldr r12, [r4]
 *   @0x29e4b8 mov r1, #5
 *   @0x29e4bc ldr r2, [sp]
 *   @0x29e4c0 str r9, [r4, #0x38]
 *   @0x29e4c4 vmov s15, r0
 *   @0x29e4c8 mov r7, r0
 *   @0x29e4cc mov r0, r4
 *   @0x29e4d0 vcvt.f64.u32 d7, s15
 *   @0x29e4d4 vmov r10, r11, d7
 *   @0x29e4d8 vstr s14, [r4, #44]
 *   @0x29e4dc str r11, [r4, #0x30]
 *   @0x29e4e0 ldr r12, [r12, #0x8]
 *   @0x29e4e4 blx r12
 *   @0x29e4e8 mov r0, r7
 *   @0x29e4ec mov r1, r4
 *   @0x29e4f0 mov r2, r5
 *   @0x29e4f4 bl 0x29e11c <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_>
 *   @0x29e4f8 ldr r3, [sp, #0x4]
 *   @0x29e4fc cmp r8, r3
 *   @0x29e500 bne 0x29e48c <_Z13Debug_GetData15eNetworkCommandP9DbgSocketPhi+0x260>
 *   @0x29e504 ldr r7, [sp]
 *   @0x29e508 b 0x29e3a0 <_Z13Debug_GetData15eNetworkCommandP9DbgSocketPhi+0x174>
 *
 * ══ §31/42 anon_2be198  0x2be198  size 736  184 条（0x2be198..0x2be478）
 * @func 0x2be198 0x2be478  size 736  184 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2be194+0x11c / anon_2be194+0x294
 * 字段偏移 top8: 0x4×11 / 0x8×7 / 0x14×5 / 0x50×3 / 0xc×2 / 0x10×2 / 0x24×2 / 0x30×2
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2be198 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2be19c cmp r3, #0
 *   @0x2be1a0 sub sp, sp, #28
 *   @0x2be1a4 ldr r1, [pc, #0x2ac]
 *   @0x2be1a8 mov r8, r0
 *   @0x2be1ac ldr r6, [r0, #0x19c]
 *   @0x2be1b0 add r1, pc, r1
 *   @0x2be1b4 ldr r5, [r0, #0xc4]
 *   @0x2be1b8 str r1, [sp, #0x8]
 *   @0x2be1bc ble 0x2be2b0 <jinit_color_deconverter+0x348>
 *   @0x2be1c0 ldr r4, [pc, #0x294]
 *   @0x2be1c4 mov r10, #0
 *   @0x2be1c8 ldr r2, [pc, #0x290]
 *   @0x2be1cc sub r6, r6, #4
 *   @0x2be1d0 add r4, pc, r4
 *   @0x2be1d4 mov r9, r10
 *   @0x2be1d8 add r2, pc, r2
 *   @0x2be1dc mov r7, r10
 *   @0x2be1e0 add r3, r2, #128
 *   @0x2be1e4 str r2, [sp, #0xc]
 *   @0x2be1e8 str r3, [sp, #0x10]
 *   @0x2be1ec str r10, [sp, #0x4]
 *   @0x2be1f0 ldr r2, [r5, #0x24]
 *   @0x2be1f4 sub r3, r2, #1
 *   @0x2be1f8 cmp r3, #7
 *   @0x2be1fc addls pc, pc, r3, lsl #2
 *   @0x2be200 b 0x2be31c <jinit_color_deconverter+0x3b4>
 *   @0x2be204 b 0x2be304 <jinit_color_deconverter+0x39c>
 *   @0x2be208 b 0x2be224 <jinit_color_deconverter+0x2bc>
 *   @0x2be20c b 0x2be31c <jinit_color_deconverter+0x3b4>
 *   @0x2be210 b 0x2be2ec <jinit_color_deconverter+0x384>
 *   @0x2be214 b 0x2be31c <jinit_color_deconverter+0x3b4>
 *   @0x2be218 b 0x2be31c <jinit_color_deconverter+0x3b4>
 *   @0x2be21c b 0x2be31c <jinit_color_deconverter+0x3b4>
 *   @0x2be220 b 0x2be2b8 <jinit_color_deconverter+0x350>
 *   @0x2be224 ldr r3, [pc, #0x238]
 *   @0x2be228 mov r9, #0
 *   @0x2be22c ldr r2, [sp, #0x8]
 *   @0x2be230 ldr r3, [r2, r3]
 *   @0x2be234 str r3, [sp, #0x4]
 *   @0x2be238 ldr r2, [sp, #0x4]
 *   @0x2be23c add r6, r6, #4
 *   @0x2be240 str r2, [r6, #0x4]
 *   @0x2be244 ldrb r3, [r5, #0x30]
 *   @0x2be248 cmp r3, #0
 *   @0x2be24c beq 0x2be29c <jinit_color_deconverter+0x334>
 *   @0x2be250 ldr r3, [r6, #0x2c]
 *   @0x2be254 cmp r3, r9
 *   @0x2be258 beq 0x2be29c <jinit_color_deconverter+0x334>
 *   @0x2be25c ldr r11, [r5, #0x4c]
 *   @0x2be260 cmp r11, #0
 *   @0x2be264 beq 0x2be29c <jinit_color_deconverter+0x334>
 *   @0x2be268 cmp r9, #1
 *   @0x2be26c str r9, [r6, #0x2c]
 *   @0x2be270 beq 0x2be3d8 <jinit_color_deconverter+0x470>
 *   @0x2be274 cmp r9, #2
 *   @0x2be278 beq 0x2be364 <jinit_color_deconverter+0x3fc>
 *   @0x2be27c cmp r9, #0
 *   @0x2be280 beq 0x2be340 <jinit_color_deconverter+0x3d8>
 *   @0x2be284 ldr r3, [r8]
 *   @0x2be288 mov r2, #48
 *   @0x2be28c mov r0, r8
 *   @0x2be290 str r2, [r3, #0x14]
 *   @0x2be294 ldr r3, [r3]
 *   @0x2be298 blx r3
 *   @0x2be29c ldr r3, [r8, #0x24]
 *   @0x2be2a0 add r7, r7, #1
 *   @0x2be2a4 add r5, r5, #84
 *   @0x2be2a8 cmp r3, r7
 *   @0x2be2ac bgt 0x2be1f0 <jinit_color_deconverter+0x288>
 *   @0x2be2b0 add sp, sp, #28
 *   @0x2be2b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2be2b8 ldr r3, [r8, #0x44]
 *   @0x2be2bc cmp r3, #1
 *   @0x2be2c0 beq 0x2be440 <jinit_color_deconverter+0x4d8>
 *   @0x2be2c4 blo 0x2be428 <jinit_color_deconverter+0x4c0>
 *   @0x2be2c8 cmp r3, #2
 *   @0x2be2cc bne 0x2be40c <jinit_color_deconverter+0x4a4>
 *   @0x2be2d0 ldr r2, [pc, #0x190]
 *   @0x2be2d4 mov r9, r3
 *   @0x2be2d8 mov r3, r2
 *   @0x2be2dc ldr r2, [sp, #0x8]
 *   @0x2be2e0 ldr r3, [r2, r3]
 *   @0x2be2e4 str r3, [sp, #0x4]
 *   @0x2be2e8 b 0x2be238 <jinit_color_deconverter+0x2d0>
 *   @0x2be2ec ldr r3, [pc, #0x178]
 *   @0x2be2f0 mov r9, #0
 *   @0x2be2f4 ldr r2, [sp, #0x8]
 *   @0x2be2f8 ldr r3, [r2, r3]
 *   @0x2be2fc str r3, [sp, #0x4]
 *   @0x2be300 b 0x2be238 <jinit_color_deconverter+0x2d0>
 *   @0x2be304 ldr r3, [pc, #0x164]
 *   @0x2be308 mov r9, #0
 *   @0x2be30c ldr r1, [sp, #0x8]
 *   @0x2be310 ldr r3, [r1, r3]
 *   @0x2be314 str r3, [sp, #0x4]
 *   @0x2be318 b 0x2be238 <jinit_color_deconverter+0x2d0>
 *   @0x2be31c ldr r3, [r8]
 *   @0x2be320 mov r1, #7
 *   @0x2be324 mov r0, r8
 *   @0x2be328 str r2, [r3, #0x18]
 *   @0x2be32c ldr r2, [r8]
 *   @0x2be330 str r1, [r3, #0x14]
 *   @0x2be334 ldr r3, [r2]
 *   @0x2be338 blx r3
 *   @0x2be33c b 0x2be238 <jinit_color_deconverter+0x2d0>
 *   @0x2be340 ldr r2, [r5, #0x50]
 *   @0x2be344 mov r3, r9
 *   @0x2be348 sub r2, r2, #4
 *   @0x2be34c ldrh r1, [r11, r3]
 *   @0x2be350 add r3, r3, #2
 *   @0x2be354 cmp r3, #128
 *   @0x2be358 str r1, [r2, #0x4]!
 *   @0x2be35c bne 0x2be34c <jinit_color_deconverter+0x3e4>
 *   @0x2be360 b 0x2be29c <jinit_color_deconverter+0x334>
 *   @0x2be364 ldr r3, [sp, #0xc]
 *   @0x2be368 sub r11, r11, #2
 *   @0x2be36c ldr r0, [sp, #0x10]
 *   @0x2be370 ldr r10, [r5, #0x50]
 *   @0x2be374 add r12, r3, #192
 *   @0x2be378 str r9, [sp, #0x14]
 *   @0x2be37c mov r9, r0
 *   @0x2be380 mov r1, r10
 *   @0x2be384 mov r3, r9
 *   @0x2be388 mov r2, r11
 *   @0x2be38c vldmia r0!, {d5}
 *   @0x2be390 str r0, [sp]
 *   @0x2be394 ldrh r0, [r2, #2]!
 *   @0x2be398 vldmia r3!, {d6}
 *   @0x2be39c cmp r12, r3
 *   @0x2be3a0 vmov s14, r0
 *   @0x2be3a4 vcvt.f64.u32 d7, s14
 *   @0x2be3a8 vmul.f64 d7, d7, d5
 *   @0x2be3ac vmul.f64 d7, d7, d6
 *   @0x2be3b0 vcvt.f32.f64 s14, d7
 *   @0x2be3b4 vstmia r1!, {s14}
 *   @0x2be3b8 bne 0x2be394 <jinit_color_deconverter+0x42c>
 *   @0x2be3bc ldr r0, [sp]
 *   @0x2be3c0 add r11, r11, #16
 *   @0x2be3c4 add r10, r10, #32
 *   @0x2be3c8 cmp r0, r12
 *   @0x2be3cc bne 0x2be380 <jinit_color_deconverter+0x418>
 *   @0x2be3d0 ldr r9, [sp, #0x14]
 *   @0x2be3d4 b 0x2be29c <jinit_color_deconverter+0x334>
 *   @0x2be3d8 ldr r2, [r5, #0x50]
 *   @0x2be3dc mov r3, #0
 *   @0x2be3e0 sub r2, r2, #4
 *   @0x2be3e4 ldrh r1, [r11, r3]
 *   @0x2be3e8 ldrsh r0, [r3, r4]
 *   @0x2be3ec add r3, r3, #2
 *   @0x2be3f0 cmp r3, #128
 *   @0x2be3f4 mul r1, r0, r1
 *   @0x2be3f8 add r1, r1, #2048
 *   @0x2be3fc asr r1, r1, #12
 *   @0x2be400 str r1, [r2, #0x4]!
 *   @0x2be404 bne 0x2be3e4 <jinit_color_deconverter+0x47c>
 *   @0x2be408 b 0x2be29c <jinit_color_deconverter+0x334>
 *   @0x2be40c ldr r3, [r8]
 *   @0x2be410 mov r2, #48
 *   @0x2be414 mov r0, r8
 *   @0x2be418 str r2, [r3, #0x14]
 *   @0x2be41c ldr r3, [r3]
 *   @0x2be420 blx r3
 *   @0x2be424 b 0x2be238 <jinit_color_deconverter+0x2d0>
 *   @0x2be428 ldr r3, [pc, #0x44]
 *   @0x2be42c mov r9, #0
 *   @0x2be430 ldr r1, [sp, #0x8]
 *   @0x2be434 ldr r3, [r1, r3]
 *   @0x2be438 str r3, [sp, #0x4]
 *   @0x2be43c b 0x2be238 <jinit_color_deconverter+0x2d0>
 *   @0x2be440 ldr r2, [pc, #0x30]
 *   @0x2be444 mov r9, r3
 *   @0x2be448 ldr r1, [sp, #0x8]
 *   @0x2be44c ldr r3, [r1, r2]
 *   @0x2be450 str r3, [sp, #0x4]
 *   @0x2be454 b 0x2be238 <jinit_color_deconverter+0x2d0>
 *   @0x2be458 andseq r3, r3, r0, lsr #21
 *   @0x2be45c andeq r1, sp, r0, asr pc
 *   @0x2be460 andeq r1, sp, r8, asr #30
 *   @0x2be464 .word 0xfffffe60
 *   @0x2be468 .word 0xfffffe64
 *   @0x2be46c .word 0xfffffe68
 *   @0x2be470 .word 0xfffffe6c
 *   @0x2be474 .word 0xfffffe70
 *
 * ══ §32/42 Buffer_Network::Poke(int, eBuffer_Type, RValue*)  0xcb048  size 732  183 条（0xcb048..0xcb324）
 * @func 0xcb048 0xcb324  size 732  183 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Buffer_Network::Poke(int, eBuffer_Type, RValue*)+0x24×2 / 0xb6538×2 / Buffer_Network::Poke(int, eBuffer_Type, RValue*)+0x2c / Buffer_Network::Poke(int, eBuffer_Type, RValue*)+0x2a0 / __fixunsdfdi
 * 字段偏移 top8: 0x-10×7 / 0xc×6 / 0x4×3 / 0x10×2 / 0x20×2 / 0x1×2 / 0x8×2 / 0x1c×2
 * VFP 指令 26 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcb048 push {r4, r5, r6, r7, lr}
 *   @0xcb04c subs r5, r1, #0
 *   @0xcb050 sub sp, sp, #20
 *   @0xcb054 mov r4, r0
 *   @0xcb058 mov r1, r3
 *   @0xcb05c blt 0xcb06c <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x24>
 *   @0xcb060 ldr r6, [r0, #0x10]
 *   @0xcb064 cmp r5, r6
 *   @0xcb068 blt 0xcb074 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x2c>
 *   @0xcb06c add sp, sp, #20
 *   @0xcb070 pop {r4, r5, r6, r7, pc}
 *   @0xcb074 sub r2, r2, #1
 *   @0xcb078 cmp r2, #12
 *   @0xcb07c addls pc, pc, r2, lsl #2
 *   @0xcb080 b 0xcb06c <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x24>
 *   @0xcb084 b 0xcb124 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0xdc>
 *   @0xcb088 b 0xcb124 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0xdc>
 *   @0xcb08c b 0xcb16c <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x124>
 *   @0xcb090 b 0xcb190 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x148>
 *   @0xcb094 b 0xcb1b4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x16c>
 *   @0xcb098 b 0xcb1d8 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x190>
 *   @0xcb09c b 0xcb06c <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x24>
 *   @0xcb0a0 b 0xcb1fc <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x1b4>
 *   @0xcb0a4 b 0xcb220 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x1d8>
 *   @0xcb0a8 b 0xcb258 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x210>
 *   @0xcb0ac b 0xcb284 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x23c>
 *   @0xcb0b0 b 0xcb2a8 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x260>
 *   @0xcb0b4 b 0xcb0b8 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x70>
 *   @0xcb0b8 ldr r3, [r3, #0xc]
 *   @0xcb0bc bic r3, r3, #-16777216
 *   @0xcb0c0 cmp r3, #1
 *   @0xcb0c4 movne r7, #0
 *   @0xcb0c8 beq 0xcb314 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x2cc>
 *   @0xcb0cc mov r0, r7
 *   @0xcb0d0 bl 0xb6538 <strlen@plt>
 *   @0xcb0d4 add r3, r5, r0
 *   @0xcb0d8 cmn r3, #1
 *   @0xcb0dc beq 0xcb2e0 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x298>
 *   @0xcb0e0 ldr r1, [r4, #0x20]
 *   @0xcb0e4 ldr r2, [r4, #0xc]
 *   @0xcb0e8 cmp r3, r1
 *   @0xcb0ec movlt r3, r1
 *   @0xcb0f0 cmp r3, r6
 *   @0xcb0f4 strle r3, [r4, #0x20]
 *   @0xcb0f8 strgt r6, [r4, #0x20]
 *   @0xcb0fc cmp r0, #0
 *   @0xcb100 add r5, r2, r5
 *   @0xcb104 ble 0xcb06c <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x24>
 *   @0xcb108 add r2, r5, r0
 *   @0xcb10c ldrb r3, [r7], #1
 *   @0xcb110 strb r3, [r5], #1
 *   @0xcb114 cmp r5, r2
 *   @0xcb118 bne 0xcb10c <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0xc4>
 *   @0xcb11c add sp, sp, #20
 *   @0xcb120 pop {r4, r5, r6, r7, pc}
 *   @0xcb124 ldr r2, [r3]
 *   @0xcb128 add r0, r5, #1
 *   @0xcb12c ldr r3, [r3, #0x4]
 *   @0xcb130 cmn r0, #1
 *   @0xcb134 ldr r12, [r4, #0xc]
 *   @0xcb138 vmov d7, r2, r3
 *   @0xcb13c vcvt.s32.f64 s15, d7
 *   @0xcb140 vmov r2, s15
 *   @0xcb144 strb r2, [r12, r5]
 *   @0xcb148 beq 0xcb30c <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x2c4>
 *   @0xcb14c ldr r3, [r4, #0x10]
 *   @0xcb150 ldr r2, [r4, #0x20]
 *   @0xcb154 cmp r0, r2
 *   @0xcb158 movlt r0, r2
 *   @0xcb15c cmp r0, r3
 *   @0xcb160 strle r0, [r4, #0x20]
 *   @0xcb164 strgt r3, [r4, #0x20]
 *   @0xcb168 b 0xcb06c <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x24>
 *   @0xcb16c ldm r3, {r2, r3}
 *   @0xcb170 vmov d7, r2, r3
 *   @0xcb174 vcvt.u32.f64 s15, d7
 *   @0xcb178 vmov r2, s15
 *   @0xcb17c rev16 r2, r2
 *   @0xcb180 add r7, sp, #16
 *   @0xcb184 mov r0, #2
 *   @0xcb188 strh r2, [r7, #-16]!
 *   @0xcb18c b 0xcb0d4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x8c>
 *   @0xcb190 ldm r3, {r2, r3}
 *   @0xcb194 vmov d6, r2, r3
 *   @0xcb198 vcvt.s32.f64 s13, d6
 *   @0xcb19c vmov r2, s13
 *   @0xcb1a0 rev16 r2, r2
 *   @0xcb1a4 add r7, sp, #16
 *   @0xcb1a8 mov r0, #2
 *   @0xcb1ac strh r2, [r7, #-16]!
 *   @0xcb1b0 b 0xcb0d4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x8c>
 *   @0xcb1b4 ldm r3, {r2, r3}
 *   @0xcb1b8 vmov d7, r2, r3
 *   @0xcb1bc vcvt.u32.f64 s15, d7
 *   @0xcb1c0 vmov r2, s15
 *   @0xcb1c4 rev r2, r2
 *   @0xcb1c8 add r7, sp, #16
 *   @0xcb1cc mov r0, #4
 *   @0xcb1d0 str r2, [r7, #-0x10]!
 *   @0xcb1d4 b 0xcb0d4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x8c>
 *   @0xcb1d8 ldm r3, {r2, r3}
 *   @0xcb1dc vmov d6, r2, r3
 *   @0xcb1e0 vcvt.s32.f64 s13, d6
 *   @0xcb1e4 vmov r2, s13
 *   @0xcb1e8 rev r2, r2
 *   @0xcb1ec add r7, sp, #16
 *   @0xcb1f0 mov r0, #4
 *   @0xcb1f4 str r2, [r7, #-0x10]!
 *   @0xcb1f8 b 0xcb0d4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x8c>
 *   @0xcb1fc ldm r3, {r2, r3}
 *   @0xcb200 vmov d7, r2, r3
 *   @0xcb204 vcvt.f32.f64 s15, d7
 *   @0xcb208 vmov r2, s15
 *   @0xcb20c rev r2, r2
 *   @0xcb210 add r7, sp, #16
 *   @0xcb214 mov r0, #4
 *   @0xcb218 str r2, [r7, #-0x10]!
 *   @0xcb21c b 0xcb0d4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x8c>
 *   @0xcb220 ldm r3, {r2, r3}
 *   @0xcb224 vmov d6, r2, r3
 *   @0xcb228 vcvt.f32.f64 s14, d6
 *   @0xcb22c vcvt.f64.f32 d7, s14
 *   @0xcb230 vstr d7, [sp, #8]
 *   @0xcb234 ldr r3, [sp, #0x8]
 *   @0xcb238 rev r3, r3
 *   @0xcb23c str r3, [sp]
 *   @0xcb240 ldr r3, [sp, #0xc]
 *   @0xcb244 rev r3, r3
 *   @0xcb248 mov r0, #8
 *   @0xcb24c str r3, [sp, #0x4]
 *   @0xcb250 mov r7, sp
 *   @0xcb254 b 0xcb0d4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x8c>
 *   @0xcb258 vmov.f64 d7, #5.000000e-01
 *   @0xcb25c ldm r3, {r2, r3}
 *   @0xcb260 vmov d6, r2, r3
 *   @0xcb264 vcmpe.f64 d6, d7
 *   @0xcb268 vmrs APSR_nzcv, fpscr
 *   @0xcb26c ble 0xcb2e8 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x2a0>
 *   @0xcb270 add r7, sp, #16
 *   @0xcb274 mov r3, #1
 *   @0xcb278 mov r0, r3
 *   @0xcb27c strb r3, [r7, #-0x10]!
 *   @0xcb280 b 0xcb0d4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x8c>
 *   @0xcb284 ldr r3, [r3, #0xc]
 *   @0xcb288 bic r3, r3, #-16777216
 *   @0xcb28c cmp r3, #1
 *   @0xcb290 movne r7, #0
 *   @0xcb294 beq 0xcb2fc <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x2b4>
 *   @0xcb298 mov r0, r7
 *   @0xcb29c bl 0xb6538 <strlen@plt>
 *   @0xcb2a0 add r0, r0, #1
 *   @0xcb2a4 b 0xcb0d4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x8c>
 *   @0xcb2a8 ldm r3, {r2, r3}
 *   @0xcb2ac mov r0, r2
 *   @0xcb2b0 mov r1, r3
 *   @0xcb2b4 bl 0x319550 <__fixunsdfdi>
 *   @0xcb2b8 str r1, [sp, #0xc]
 *   @0xcb2bc str r0, [sp, #0x8]
 *   @0xcb2c0 rev r0, r0
 *   @0xcb2c4 str r0, [sp]
 *   @0xcb2c8 mov r3, r1
 *   @0xcb2cc rev r3, r3
 *   @0xcb2d0 mov r0, #8
 *   @0xcb2d4 str r3, [sp, #0x4]
 *   @0xcb2d8 mov r7, sp
 *   @0xcb2dc b 0xcb0d4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x8c>
 *   @0xcb2e0 ldr r3, [r4, #0x1c]
 *   @0xcb2e4 b 0xcb0e0 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x98>
 *   @0xcb2e8 add r7, sp, #16
 *   @0xcb2ec mov r3, #0
 *   @0xcb2f0 mov r0, #1
 *   @0xcb2f4 strb r3, [r7, #-0x10]!
 *   @0xcb2f8 b 0xcb0d4 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x8c>
 *   @0xcb2fc ldr r7, [r1]
 *   @0xcb300 cmp r7, #0
 *   @0xcb304 ldrne r7, [r7]
 *   @0xcb308 b 0xcb298 <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x250>
 *   @0xcb30c ldr r0, [r4, #0x1c]
 *   @0xcb310 b 0xcb14c <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x104>
 *   @0xcb314 ldr r7, [r1]
 *   @0xcb318 cmp r7, #0
 *   @0xcb31c ldrne r7, [r7]
 *   @0xcb320 b 0xcb0cc <_ZN14Buffer_Network4PokeEi12eBuffer_TypeP6RValue+0x84>
 *
 * ══ §33/42 GCThreadFunc(CThread*)  0xd34ac  size 732  183 条（0xd34ac..0xd3788）
 * @func 0xd34ac 0xd3788  size 732  183 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __floatdidf×3 / Timing_Time×2 / __fixdfdi×2 / GCThreadFunc(CThread*)+0x6c / YYObjectBase::FreeVars(YYObjectBase*, RValue**, RValue**, RVariable**, RVariable**) / Timing_Wait
 * 字段偏移 top8: 0xc×3 / 0x30×3 / 0x278×2 / 0x8×2 / 0x1d4×2 / 0x10×2 / 0x14×2 / 0x34×2
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd34ac push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xd34b0 vpush {d8, d9}
 *   @0xd34b4 sub sp, sp, #60
 *   @0xd34b8 ldr r9, [pc, #0x294]
 *   @0xd34bc mvn r4, #0
 *   @0xd34c0 mvn r5, #0
 *   @0xd34c4 mov r10, r0
 *   @0xd34c8 strd r4, r5, [sp, #24]
 *   @0xd34cc add r9, pc, r9
 *   @0xd34d0 strd r4, r5, [sp, #40]
 *   @0xd34d4 b 0xd34fc <_Z12GCThreadFuncP7CThread+0x50>
 *   @0xd34d8 ldr r2, [pc, #0x278]
 *   @0xd34dc ldr r3, [pc, #0x278]
 *   @0xd34e0 ldr r2, [r9, r2]
 *   @0xd34e4 str r2, [sp, #0xc]
 *   @0xd34e8 ldr r3, [r9, r3]
 *   @0xd34ec ldr r2, [r2]
 *   @0xd34f0 ldr r3, [r3]
 *   @0xd34f4 cmp r2, r3
 *   @0xd34f8 blt 0xd3518 <_Z12GCThreadFuncP7CThread+0x6c>
 *   @0xd34fc ldrb r3, [r10, #0x8]
 *   @0xd3500 cmp r3, #0
 *   @0xd3504 beq 0xd34d8 <_Z12GCThreadFuncP7CThread+0x2c>
 *   @0xd3508 mov r0, #0
 *   @0xd350c add sp, sp, #60
 *   @0xd3510 vpop {d8, d9}
 *   @0xd3514 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xd3518 bl 0x215148 <Timing_Time>
 *   @0xd351c strd r0, r1, [sp, #32]
 *   @0xd3520 mvn r0, #0
 *   @0xd3524 mvn r1, #0
 *   @0xd3528 cmp r5, r1
 *   @0xd352c cmpeq r4, r0
 *   @0xd3530 beq 0xd3568 <_Z12GCThreadFuncP7CThread+0xbc>
 *   @0xd3534 ldrd r2, r3, [sp, #32]
 *   @0xd3538 movw r0, #0x9c40
 *   @0xd353c mov r1, #0
 *   @0xd3540 subs r4, r2, r4
 *   @0xd3544 sbc r5, r3, r5
 *   @0xd3548 ldrd r2, r3, [sp, #32]
 *   @0xd354c cmp r0, r4
 *   @0xd3550 sbcs r1, r1, r5
 *   @0xd3554 movlt r5, #0
 *   @0xd3558 movwlt r4, #0x9c40
 *   @0xd355c adds r2, r2, r4
 *   @0xd3560 adc r3, r3, r5
 *   @0xd3564 strd r2, r3, [sp, #40]
 *   @0xd3568 ldr r3, [pc, #0x1f0]
 *   @0xd356c ldr r11, [r9, r3]
 *   @0xd3570 ldr r3, [r11]
 *   @0xd3574 cmp r3, #0
 *   @0xd3578 beq 0xd365c <_Z12GCThreadFuncP7CThread+0x1b0>
 *   @0xd357c ldr r12, [pc, #0x1e0]
 *   @0xd3580 mov r5, #0
 *   @0xd3584 ldr r3, [pc, #0x1dc]
 *   @0xd3588 mov r4, r5
 *   @0xd358c ldr lr, [pc, #0x1d8]
 *   @0xd3590 ldr r12, [r9, r12]
 *   @0xd3594 ldr r0, [pc, #0x1d4]
 *   @0xd3598 ldr r2, [pc, #0x1d4]
 *   @0xd359c ldr r7, [r9, r3]
 *   @0xd35a0 ldr r8, [r9, lr]
 *   @0xd35a4 ldr r3, [pc, #0x1cc]
 *   @0xd35a8 str r12, [sp, #0x10]
 *   @0xd35ac ldr r12, [r9, r0]
 *   @0xd35b0 ldr r2, [r9, r2]
 *   @0xd35b4 ldr r1, [r7]
 *   @0xd35b8 str r2, [sp, #0x14]
 *   @0xd35bc ldr r6, [r9, r3]
 *   @0xd35c0 str r10, [sp, #0x34]
 *   @0xd35c4 mov r10, r8
 *   @0xd35c8 str r9, [sp, #0x30]
 *   @0xd35cc mov r9, r12
 *   @0xd35d0 b 0xd3604 <_Z12GCThreadFuncP7CThread+0x158>
 *   @0xd35d4 ldr r12, [r2]
 *   @0xd35d8 add r4, r4, #1
 *   @0xd35dc ldr r0, [r11]
 *   @0xd35e0 mov r5, r4
 *   @0xd35e4 str r3, [r12, #0x8]
 *   @0xd35e8 cmp r4, r0
 *   @0xd35ec ldr r3, [r2]
 *   @0xd35f0 mov r0, #0
 *   @0xd35f4 str r0, [r3, #0xc]
 *   @0xd35f8 ldr r3, [r2]
 *   @0xd35fc str r3, [r6]
 *   @0xd3600 bhs 0xd3654 <_Z12GCThreadFuncP7CThread+0x1a8>
 *   @0xd3604 ldr r2, [sp, #0x14]
 *   @0xd3608 mov r3, r9
 *   @0xd360c ldr r0, [r1, r5, lsl #2]
 *   @0xd3610 mov r1, r10
 *   @0xd3614 lsl r8, r5, #2
 *   @0xd3618 str r2, [sp]
 *   @0xd361c ldr r2, [sp, #0x10]
 *   @0xd3620 bl 0x198dac <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_>
 *   @0xd3624 ldr r3, [r6]
 *   @0xd3628 ldr r1, [r7]
 *   @0xd362c cmp r3, #0
 *   @0xd3630 addne r2, r1, r8
 *   @0xd3634 bne 0xd35d4 <_Z12GCThreadFuncP7CThread+0x128>
 *   @0xd3638 ldr r12, [r1, r5, lsl #2]
 *   @0xd363c add r2, r1, r8
 *   @0xd3640 ldr r0, [pc, #0x134]
 *   @0xd3644 ldr r5, [sp, #0x30]
 *   @0xd3648 ldr r0, [r5, r0]
 *   @0xd364c str r12, [r0]
 *   @0xd3650 b 0xd35d4 <_Z12GCThreadFuncP7CThread+0x128>
 *   @0xd3654 ldr r10, [sp, #0x34]
 *   @0xd3658 ldr r9, [sp, #0x30]
 *   @0xd365c ldrd r4, r5, [sp, #40]
 *   @0xd3660 mvn r0, #0
 *   @0xd3664 mvn r1, #0
 *   @0xd3668 cmp r5, r1
 *   @0xd366c cmpeq r4, r0
 *   @0xd3670 ldr r4, [sp, #0xc]
 *   @0xd3674 ldr r3, [r4]
 *   @0xd3678 add r3, r3, #1
 *   @0xd367c str r3, [r4]
 *   @0xd3680 beq 0xd373c <_Z12GCThreadFuncP7CThread+0x290>
 *   @0xd3684 bl 0x215148 <Timing_Time>
 *   @0xd3688 ldrd r4, r5, [sp, #24]
 *   @0xd368c mvn r2, #0
 *   @0xd3690 mvn r3, #0
 *   @0xd3694 cmp r5, r3
 *   @0xd3698 cmpeq r4, r2
 *   @0xd369c beq 0xd3728 <_Z12GCThreadFuncP7CThread+0x27c>
 *   @0xd36a0 ldrd r4, r5, [sp, #40]
 *   @0xd36a4 subs r4, r4, r0
 *   @0xd36a8 sbc r5, r5, r1
 *   @0xd36ac mov r0, r4
 *   @0xd36b0 mov r1, r5
 *   @0xd36b4 bl 0x319164 <__floatdidf>
 *   @0xd36b8 ldr r3, [pc, #0xc0]
 *   @0xd36bc ldr r3, [r9, r3]
 *   @0xd36c0 vldr d9, [r3]
 *   @0xd36c4 vmov d5, r0, r1
 *   @0xd36c8 ldrd r0, r1, [sp, #24]
 *   @0xd36cc vmul.f64 d9, d5, d9
 *   @0xd36d0 bl 0x319164 <__floatdidf>
 *   @0xd36d4 vmov d8, r0, r1
 *   @0xd36d8 vcmpe.f64 d9, d8
 *   @0xd36dc vmrs APSR_nzcv, fpscr
 *   @0xd36e0 bmi 0xd3744 <_Z12GCThreadFuncP7CThread+0x298>
 *   @0xd36e4 ldrd r0, r1, [sp, #24]
 *   @0xd36e8 subs r0, r4, r0
 *   @0xd36ec sbc r1, r5, r1
 *   @0xd36f0 bl 0x319164 <__floatdidf>
 *   @0xd36f4 vmov.f64 d6, d8
 *   @0xd36f8 ldr r3, [pc, #0x84]
 *   @0xd36fc ldr r3, [r9, r3]
 *   @0xd3700 vldr d7, [r3]
 *   @0xd3704 vmov d5, r0, r1
 *   @0xd3708 vmla.f64 d6, d5, d7
 *   @0xd370c vmov r0, r1, d6
 *   @0xd3710 bl 0x3194a0 <__fixdfdi>
 *   @0xd3714 strd r0, r1, [sp, #24]
 *   @0xd3718 ldrd r4, r5, [sp, #24]
 *   @0xd371c cmp r4, #0
 *   @0xd3720 sbcs r5, r5, #0
 *   @0xd3724 bge 0xd3734 <_Z12GCThreadFuncP7CThread+0x288>
 *   @0xd3728 mov r4, #0
 *   @0xd372c mov r5, #0
 *   @0xd3730 strd r4, r5, [sp, #24]
 *   @0xd3734 ldrd r0, r1, [sp, #24]
 *   @0xd3738 bl 0x212da4 <Timing_Wait>
 *   @0xd373c ldrd r4, r5, [sp, #32]
 *   @0xd3740 b 0xd34fc <_Z12GCThreadFuncP7CThread+0x50>
 *   @0xd3744 vmov r0, r1, d9
 *   @0xd3748 bl 0x3194a0 <__fixdfdi>
 *   @0xd374c strd r0, r1, [sp, #24]
 *   @0xd3750 b 0xd3718 <_Z12GCThreadFuncP7CThread+0x26c>
 *   @0xd3754 eorseq lr, r1, r4, lsl #15
 *   @0xd3758 .word 0xffffbf7c
 *   @0xd375c .word 0xffffbf80
 *   @0xd3760 .word 0xffffbf84
 *   @0xd3764 .word 0xffffbf88
 *   @0xd3768 .word 0xffffbf8c
 *   @0xd376c .word 0xffffbf90
 *   @0xd3770 .word 0xffffbf94
 *   @0xd3774 .word 0xffffbf98
 *   @0xd3778 .word 0xffffbf9c
 *   @0xd377c .word 0xffffbfa0
 *   @0xd3780 .word 0xffffbfa4
 *   @0xd3784 .word 0xffffbfa8
 *
 * ══ §34/42 CIAPProduct::SetFromMap(int)  0x18b5c4  size 732  183 条（0x18b5c4..0x18b8a0）
 * @func 0x18b5c4 0x18b8a0  size 732  183 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*)×7 / YYStrDup(char const*)×7 / anon_18b538×6 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb6550 / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0xc×11 / 0x10×4 / 0x4×3 / 0x8×3 / 0x2ac×1 / 0x274×1 / 0x254×1 / 0x234×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18b5c4 push {r4, r5, r6, r7, lr}
 *   @0x18b5c8 sub sp, sp, #20
 *   @0x18b5cc ldr r2, [pc, #0x2ac]
 *   @0x18b5d0 mov r4, r0
 *   @0x18b5d4 mov r0, sp
 *   @0x18b5d8 mov r3, #0
 *   @0x18b5dc add r2, pc, r2
 *   @0x18b5e0 str r3, [sp]
 *   @0x18b5e4 str r3, [sp, #0x4]
 *   @0x18b5e8 mov r6, r1
 *   @0x18b5ec str r3, [sp, #0x8]
 *   @0x18b5f0 str r3, [sp, #0xc]
 *   @0x18b5f4 bl 0x18b538 <_ZN11CIAPProduct11PopulateMapEi+0x1f0>
 *   @0x18b5f8 ldr r3, [sp, #0xc]
 *   @0x18b5fc bic r3, r3, #-16777216
 *   @0x18b600 cmp r3, #1
 *   @0x18b604 beq 0x18b7d4 <_ZN11CIAPProduct10SetFromMapEi+0x210>
 *   @0x18b608 ldr r2, [pc, #0x274]
 *   @0x18b60c mov r0, sp
 *   @0x18b610 mov r1, r6
 *   @0x18b614 add r2, pc, r2
 *   @0x18b618 bl 0x18b538 <_ZN11CIAPProduct11PopulateMapEi+0x1f0>
 *   @0x18b61c ldr r3, [sp, #0xc]
 *   @0x18b620 bic r3, r3, #-16777216
 *   @0x18b624 cmp r3, #1
 *   @0x18b628 beq 0x18b79c <_ZN11CIAPProduct10SetFromMapEi+0x1d8>
 *   @0x18b62c ldr r2, [pc, #0x254]
 *   @0x18b630 mov r0, sp
 *   @0x18b634 mov r1, r6
 *   @0x18b638 add r2, pc, r2
 *   @0x18b63c bl 0x18b538 <_ZN11CIAPProduct11PopulateMapEi+0x1f0>
 *   @0x18b640 ldr r3, [sp, #0xc]
 *   @0x18b644 bic r3, r3, #-16777216
 *   @0x18b648 cmp r3, #1
 *   @0x18b64c beq 0x18b728 <_ZN11CIAPProduct10SetFromMapEi+0x164>
 *   @0x18b650 ldr r2, [pc, #0x234]
 *   @0x18b654 mov r0, sp
 *   @0x18b658 mov r1, r6
 *   @0x18b65c add r2, pc, r2
 *   @0x18b660 bl 0x18b538 <_ZN11CIAPProduct11PopulateMapEi+0x1f0>
 *   @0x18b664 ldr r3, [sp, #0xc]
 *   @0x18b668 cmp r3, #0
 *   @0x18b66c beq 0x18b6cc <_ZN11CIAPProduct10SetFromMapEi+0x108>
 *   @0x18b670 bic r3, r3, #-16777216
 *   @0x18b674 cmp r3, #1
 *   @0x18b678 beq 0x18b848 <_ZN11CIAPProduct10SetFromMapEi+0x284>
 *   @0x18b67c ldr r2, [pc, #0x20c]
 *   @0x18b680 mov r0, sp
 *   @0x18b684 mov r1, r6
 *   @0x18b688 add r2, pc, r2
 *   @0x18b68c bl 0x18b538 <_ZN11CIAPProduct11PopulateMapEi+0x1f0>
 *   @0x18b690 ldr r3, [sp, #0xc]
 *   @0x18b694 bic r3, r3, #-16777216
 *   @0x18b698 cmp r3, #1
 *   @0x18b69c beq 0x18b760 <_ZN11CIAPProduct10SetFromMapEi+0x19c>
 *   @0x18b6a0 ldr r2, [pc, #0x1ec]
 *   @0x18b6a4 mov r0, sp
 *   @0x18b6a8 mov r1, r6
 *   @0x18b6ac add r2, pc, r2
 *   @0x18b6b0 bl 0x18b538 <_ZN11CIAPProduct11PopulateMapEi+0x1f0>
 *   @0x18b6b4 ldr r3, [sp, #0xc]
 *   @0x18b6b8 bic r3, r3, #-16777216
 *   @0x18b6bc cmp r3, #1
 *   @0x18b6c0 beq 0x18b80c <_ZN11CIAPProduct10SetFromMapEi+0x248>
 *   @0x18b6c4 add sp, sp, #20
 *   @0x18b6c8 pop {r4, r5, r6, r7, pc}
 *   @0x18b6cc ldr r1, [pc, #0x1c4]
 *   @0x18b6d0 mov r2, #133
 *   @0x18b6d4 mov r3, #1
 *   @0x18b6d8 mov r0, #512
 *   @0x18b6dc add r1, pc, r1
 *   @0x18b6e0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x18b6e4 ldr r1, [pc, #0x1b0]
 *   @0x18b6e8 ldrd r2, r3, [sp]
 *   @0x18b6ec add r1, pc, r1
 *   @0x18b6f0 mov r7, r0
 *   @0x18b6f4 bl 0xb6550 <sprintf@plt>
 *   @0x18b6f8 ldr r0, [r4, #0xc]
 *   @0x18b6fc cmp r0, #0
 *   @0x18b700 beq 0x18b708 <_ZN11CIAPProduct10SetFromMapEi+0x144>
 *   @0x18b704 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18b708 mov r0, r7
 *   @0x18b70c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18b710 cmp r7, #0
 *   @0x18b714 str r0, [r4, #0xc]
 *   @0x18b718 beq 0x18b67c <_ZN11CIAPProduct10SetFromMapEi+0xb8>
 *   @0x18b71c mov r0, r7
 *   @0x18b720 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x18b724 b 0x18b67c <_ZN11CIAPProduct10SetFromMapEi+0xb8>
 *   @0x18b728 ldr r3, [sp]
 *   @0x18b72c cmp r3, #0
 *   @0x18b730 beq 0x18b650 <_ZN11CIAPProduct10SetFromMapEi+0x8c>
 *   @0x18b734 ldr r7, [r3]
 *   @0x18b738 cmp r7, #0
 *   @0x18b73c beq 0x18b650 <_ZN11CIAPProduct10SetFromMapEi+0x8c>
 *   @0x18b740 ldr r0, [r4, #0x8]
 *   @0x18b744 cmp r0, #0
 *   @0x18b748 beq 0x18b750 <_ZN11CIAPProduct10SetFromMapEi+0x18c>
 *   @0x18b74c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18b750 mov r0, r7
 *   @0x18b754 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18b758 str r0, [r4, #0x8]
 *   @0x18b75c b 0x18b650 <_ZN11CIAPProduct10SetFromMapEi+0x8c>
 *   @0x18b760 ldr r3, [sp]
 *   @0x18b764 cmp r3, #0
 *   @0x18b768 beq 0x18b6a0 <_ZN11CIAPProduct10SetFromMapEi+0xdc>
 *   @0x18b76c ldr r7, [r3]
 *   @0x18b770 cmp r7, #0
 *   @0x18b774 beq 0x18b6a0 <_ZN11CIAPProduct10SetFromMapEi+0xdc>
 *   @0x18b778 ldr r0, [r4, #0x10]
 *   @0x18b77c cmp r0, #0
 *   @0x18b780 beq 0x18b788 <_ZN11CIAPProduct10SetFromMapEi+0x1c4>
 *   @0x18b784 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18b788 mov r0, r7
 *   @0x18b78c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18b790 str r0, [r4, #0x10]
 *   @0x18b794 add sp, sp, #20
 *   @0x18b798 pop {r4, r5, r6, r7, pc}
 *   @0x18b79c ldr r3, [sp]
 *   @0x18b7a0 cmp r3, #0
 *   @0x18b7a4 beq 0x18b62c <_ZN11CIAPProduct10SetFromMapEi+0x68>
 *   @0x18b7a8 ldr r7, [r3]
 *   @0x18b7ac cmp r7, #0
 *   @0x18b7b0 beq 0x18b62c <_ZN11CIAPProduct10SetFromMapEi+0x68>
 *   @0x18b7b4 ldr r0, [r4, #0x4]
 *   @0x18b7b8 cmp r0, #0
 *   @0x18b7bc beq 0x18b7c4 <_ZN11CIAPProduct10SetFromMapEi+0x200>
 *   @0x18b7c0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18b7c4 mov r0, r7
 *   @0x18b7c8 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18b7cc str r0, [r4, #0x4]
 *   @0x18b7d0 b 0x18b62c <_ZN11CIAPProduct10SetFromMapEi+0x68>
 *   @0x18b7d4 ldr r3, [sp]
 *   @0x18b7d8 cmp r3, #0
 *   @0x18b7dc beq 0x18b608 <_ZN11CIAPProduct10SetFromMapEi+0x44>
 *   @0x18b7e0 ldr r7, [r3]
 *   @0x18b7e4 cmp r7, #0
 *   @0x18b7e8 beq 0x18b608 <_ZN11CIAPProduct10SetFromMapEi+0x44>
 *   @0x18b7ec ldr r0, [r4]
 *   @0x18b7f0 cmp r0, #0
 *   @0x18b7f4 beq 0x18b7fc <_ZN11CIAPProduct10SetFromMapEi+0x238>
 *   @0x18b7f8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18b7fc mov r0, r7
 *   @0x18b800 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18b804 str r0, [r4]
 *   @0x18b808 b 0x18b608 <_ZN11CIAPProduct10SetFromMapEi+0x44>
 *   @0x18b80c ldr r3, [sp]
 *   @0x18b810 cmp r3, #0
 *   @0x18b814 beq 0x18b6c4 <_ZN11CIAPProduct10SetFromMapEi+0x100>
 *   @0x18b818 ldr r5, [r3]
 *   @0x18b81c cmp r5, #0
 *   @0x18b820 beq 0x18b6c4 <_ZN11CIAPProduct10SetFromMapEi+0x100>
 *   @0x18b824 ldr r0, [r4, #0x10]
 *   @0x18b828 cmp r0, #0
 *   @0x18b82c beq 0x18b834 <_ZN11CIAPProduct10SetFromMapEi+0x270>
 *   @0x18b830 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18b834 mov r0, r5
 *   @0x18b838 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18b83c str r0, [r4, #0x10]
 *   @0x18b840 add sp, sp, #20
 *   @0x18b844 pop {r4, r5, r6, r7, pc}
 *   @0x18b848 ldr r3, [sp]
 *   @0x18b84c cmp r3, #0
 *   @0x18b850 beq 0x18b67c <_ZN11CIAPProduct10SetFromMapEi+0xb8>
 *   @0x18b854 ldr r7, [r3]
 *   @0x18b858 cmp r7, #0
 *   @0x18b85c beq 0x18b67c <_ZN11CIAPProduct10SetFromMapEi+0xb8>
 *   @0x18b860 ldr r0, [r4, #0xc]
 *   @0x18b864 cmp r0, #0
 *   @0x18b868 beq 0x18b870 <_ZN11CIAPProduct10SetFromMapEi+0x2ac>
 *   @0x18b86c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18b870 mov r0, r7
 *   @0x18b874 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18b878 str r0, [r4, #0xc]
 *   @0x18b87c b 0x18b67c <_ZN11CIAPProduct10SetFromMapEi+0xb8>
 *   @0x18b880 andseq r5, r10, r4, ror #8
 *   @0x18b884 ldrheq lr, [r11], -r8
 *   @0x18b888 andseq r10, r11, r4, lsl #31
 *   @0x18b88c mulseq r12, r4, r11
 *   @0x18b890 andseq r10, r11, r0, lsr #21
 *   @0x18b894 mulseq r12, r0, r11
 *   @0x18b898 andseq r0, r12, r8, lsr #22
 *   @0x18b89c andseq r6, r10, r4, lsl lr
 *
 * ══ §35/42 INITIALIZE_Run_Global()  0x1cb778  size 732  183 条（0x1cb778..0x1cba54）
 * @func 0x1cb778 0x1cba54  size 732  183 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1cb788→0x542944, 0x1cb794→0x542938, 0x1cb798→0x542924, 0x1cb7a8→0x54297a, 0x1cb7b0→0x542979, 0x1cb840→0x542978, 0x1cb84c→0x542950, 0x1cb854→0x54294c
 * 调用序列: operator new(unsigned int)×3 / YYStrDup(char const*)×3
 * 字段偏移 top8: 0x4×10 / 0x8×8 / 0x23c×2 / 0xc×2 / 0x18c×2 / 0x248×1 / 0x244×1 / 0x230×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cb778 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1cb77c sub sp, sp, #20
 *   @0x1cb780 ldr r4, [pc, #0x248]
 *   @0x1cb784 mov r5, #0
 *   @0x1cb788 ldr r1, [pc, #0x244]
 *   @0x1cb78c mov r0, #12
 *   @0x1cb790 add r4, pc, r4
 *   @0x1cb794 ldr r2, [pc, #0x23c]
 *   @0x1cb798 ldr r3, [pc, #0x23c]
 *   @0x1cb79c mov r8, #8
 *   @0x1cb7a0 ldr r1, [r4, r1]
 *   @0x1cb7a4 mov r6, #1
 *   @0x1cb7a8 ldr r10, [pc, #0x230]
 *   @0x1cb7ac movw r11, #0xdead
 *   @0x1cb7b0 ldr r9, [pc, #0x22c]
 *   @0x1cb7b4 movt r11, #0xfeee
 *   @0x1cb7b8 str r1, [sp, #0x4]
 *   @0x1cb7bc str r5, [r1]
 *   @0x1cb7c0 ldr r2, [r4, r2]
 *   @0x1cb7c4 str r2, [sp, #0x8]
 *   @0x1cb7c8 str r5, [r2]
 *   @0x1cb7cc ldr r3, [r4, r3]
 *   @0x1cb7d0 str r3, [sp, #0xc]
 *   @0x1cb7d4 str r5, [r3]
 *   @0x1cb7d8 bl 0x27c524 <_Znwj>
 *   @0x1cb7dc mov r7, r0
 *   @0x1cb7e0 ldr r0, [pc, #0x200]
 *   @0x1cb7e4 str r8, [r7, #0x8]
 *   @0x1cb7e8 add r0, pc, r0
 *   @0x1cb7ec bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1cb7f0 ldr r1, [sp, #0x4]
 *   @0x1cb7f4 stm r7, {r0, r6}
 *   @0x1cb7f8 mov r0, #12
 *   @0x1cb7fc str r7, [r1]
 *   @0x1cb800 bl 0x27c524 <_Znwj>
 *   @0x1cb804 mov r3, #7
 *   @0x1cb808 mov r7, r0
 *   @0x1cb80c ldr r0, [pc, #0x1d8]
 *   @0x1cb810 str r3, [r7, #0x8]
 *   @0x1cb814 add r0, pc, r0
 *   @0x1cb818 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1cb81c ldr r2, [sp, #0x8]
 *   @0x1cb820 stm r7, {r0, r6}
 *   @0x1cb824 mov r0, #12
 *   @0x1cb828 str r7, [r2]
 *   @0x1cb82c bl 0x27c524 <_Znwj>
 *   @0x1cb830 mov r7, r0
 *   @0x1cb834 ldr r0, [pc, #0x1b4]
 *   @0x1cb838 str r8, [r7, #0x8]
 *   @0x1cb83c add r0, pc, r0
 *   @0x1cb840 ldr r8, [pc, #0x1ac]
 *   @0x1cb844 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1cb848 str r6, [r7, #0x4]
 *   @0x1cb84c ldr r12, [pc, #0x1a4]
 *   @0x1cb850 mvn r3, #0
 *   @0x1cb854 ldr r1, [pc, #0x1a0]
 *   @0x1cb858 vldr d7, [pc, #360]
 *   @0x1cb85c ldr r2, [pc, #0x19c]
 *   @0x1cb860 str r0, [r7]
 *   @0x1cb864 ldr r0, [sp, #0xc]
 *   @0x1cb868 str r7, [r0]
 *   @0x1cb86c ldr r0, [r4, r10]
 *   @0x1cb870 ldr r10, [pc, #0x18c]
 *   @0x1cb874 ldr r7, [pc, #0x18c]
 *   @0x1cb878 strb r5, [r0]
 *   @0x1cb87c ldr r0, [r4, r9]
 *   @0x1cb880 ldr r9, [sp, #0x8]
 *   @0x1cb884 strb r5, [r0]
 *   @0x1cb888 ldr r0, [r4, r8]
 *   @0x1cb88c ldr r8, [pc, #0x178]
 *   @0x1cb890 strb r5, [r0]
 *   @0x1cb894 ldr r0, [r4, r12]
 *   @0x1cb898 ldr r12, [pc, #0x170]
 *   @0x1cb89c str r5, [r0]
 *   @0x1cb8a0 ldr r1, [r4, r1]
 *   @0x1cb8a4 str r5, [r1]
 *   @0x1cb8a8 ldr r2, [r4, r2]
 *   @0x1cb8ac ldr r1, [sp, #0x4]
 *   @0x1cb8b0 strb r6, [r2]
 *   @0x1cb8b4 ldr r2, [pc, #0x158]
 *   @0x1cb8b8 ldr r2, [r4, r2]
 *   @0x1cb8bc str r5, [r1]
 *   @0x1cb8c0 ldr r1, [pc, #0x150]
 *   @0x1cb8c4 strb r5, [r2]
 *   @0x1cb8c8 ldr r2, [pc, #0x14c]
 *   @0x1cb8cc ldr r2, [r4, r2]
 *   @0x1cb8d0 str r3, [r2]
 *   @0x1cb8d4 ldr r2, [pc, #0x144]
 *   @0x1cb8d8 ldr r2, [r4, r2]
 *   @0x1cb8dc str r5, [r9]
 *   @0x1cb8e0 strb r5, [r2]
 *   @0x1cb8e4 ldr r2, [pc, #0x138]
 *   @0x1cb8e8 ldr r2, [r4, r2]
 *   @0x1cb8ec vstr d7, [r2]
 *   @0x1cb8f0 ldr r2, [pc, #0x130]
 *   @0x1cb8f4 ldr r0, [r4, r2]
 *   @0x1cb8f8 ldr r2, [pc, #0x12c]
 *   @0x1cb8fc strb r5, [r0]
 *   @0x1cb900 ldr r0, [pc, #0x128]
 *   @0x1cb904 ldr r0, [r4, r0]
 *   @0x1cb908 str r12, [sp, #0x8]
 *   @0x1cb90c ldr r12, [pc, #0x120]
 *   @0x1cb910 str r5, [r0]
 *   @0x1cb914 ldr r0, [pc, #0x11c]
 *   @0x1cb918 ldr r0, [r4, r0]
 *   @0x1cb91c strb r5, [r0]
 *   @0x1cb920 ldr r0, [pc, #0x114]
 *   @0x1cb924 ldr r0, [r4, r0]
 *   @0x1cb928 str r3, [r0]
 *   @0x1cb92c ldr r0, [pc, #0x10c]
 *   @0x1cb930 ldr r0, [r4, r0]
 *   @0x1cb934 str r5, [r0]
 *   @0x1cb938 ldr r0, [pc, #0x104]
 *   @0x1cb93c ldr r0, [r4, r0]
 *   @0x1cb940 str r0, [sp, #0x4]
 *   @0x1cb944 ldr r9, [sp, #0x4]
 *   @0x1cb948 ldr r0, [pc, #0xf8]
 *   @0x1cb94c strb r6, [r9]
 *   @0x1cb950 ldr r1, [r4, r1]
 *   @0x1cb954 str r1, [sp, #0x4]
 *   @0x1cb958 ldr r9, [sp, #0x4]
 *   @0x1cb95c ldr r1, [pc, #0xe8]
 *   @0x1cb960 str r5, [r9]
 *   @0x1cb964 ldr r2, [r4, r2]
 *   @0x1cb968 str r2, [sp, #0x4]
 *   @0x1cb96c ldr r9, [sp, #0x4]
 *   @0x1cb970 ldr r2, [pc, #0xd8]
 *   @0x1cb974 str r11, [r9]
 *   @0x1cb978 ldr r9, [sp, #0x8]
 *   @0x1cb97c ldr r10, [r4, r10]
 *   @0x1cb980 str r3, [r10]
 *   @0x1cb984 ldr r9, [r4, r9]
 *   @0x1cb988 str r3, [r9]
 *   @0x1cb98c ldr r8, [r4, r8]
 *   @0x1cb990 strb r6, [r8]
 *   @0x1cb994 ldr r6, [r4, r7]
 *   @0x1cb998 str r3, [r6]
 *   @0x1cb99c ldr r12, [r4, r12]
 *   @0x1cb9a0 str r3, [r12]
 *   @0x1cb9a4 ldr r0, [r4, r0]
 *   @0x1cb9a8 strb r5, [r0]
 *   @0x1cb9ac ldr r1, [r4, r1]
 *   @0x1cb9b0 str r5, [r1]
 *   @0x1cb9b4 ldr r2, [r4, r2]
 *   @0x1cb9b8 str r3, [r2]
 *   @0x1cb9bc add sp, sp, #20
 *   @0x1cb9c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1cb9c4 nop
 *   @0x1cb9c8 andeq r0, r0, r0
 *   @0x1cb9cc subsmi r0, r9, r0
 *   @0x1cb9d0 eoreq r6, r2, r0, asr #9
 *   @0x1cb9d4 .word 0xffffd9a0
 *   @0x1cb9d8 .word 0xffffd9a8
 *   @0x1cb9dc .word 0xffffd9b0
 *   @0x1cb9e0 .word 0xffffeebc
 *   @0x1cb9e4 .word 0xffffdfa0
 *   @0x1cb9e8 andseq r5, r8, r12, asr #11
 *   @0x1cb9ec andseq r5, r8, r12, lsr #11
 *   @0x1cb9f0 andseq r5, r8, r12, lsl #11
 *   @0x1cb9f4 .word 0xffffeec0
 *   @0x1cb9f8 .word 0xffffc458
 *   @0x1cb9fc .word 0xffffce34
 *   @0x1cba00 .word 0xffffd99c
 *   @0x1cba04 .word 0xffffdf38
 *   @0x1cba08 .word 0xffffc990
 *   @0x1cba0c .word 0xffffdf34
 *   @0x1cba10 .word 0xffffdf40
 *   @0x1cba14 .word 0xffffd998
 *   @0x1cba18 .word 0xffffeec4
 *   @0x1cba1c .word 0xffffd780
 *   @0x1cba20 .word 0xffffd9a4
 *   @0x1cba24 .word 0xffffd788
 *   @0x1cba28 .word 0xffffd9ac
 *   @0x1cba2c .word 0xffffc988
 *   @0x1cba30 .word 0xffffc980
 *   @0x1cba34 .word 0xffffc994
 *   @0x1cba38 .word 0xffffd658
 *   @0x1cba3c .word 0xffffd798
 *   @0x1cba40 .word 0xffffebf0
 *   @0x1cba44 .word 0xffffc974
 *   @0x1cba48 .word 0xffffc98c
 *   @0x1cba4c .word 0xffffebec
 *   @0x1cba50 .word 0xffffeec8
 *
 * ══ §36/42 CDS_Priority::Change(RValue*, RValue*)  0x20a148  size 732  183 条（0x20a148..0x20a424）
 * @func 0x20a148 0x20a424  size 732  183 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / FREE_RValue__Pre(RValue*)×2 / CDS_Priority::Change(RValue*, RValue*)+0x138 / YYCompareVal(RValue const&, RValue const&, double) / GetContextStackTop()
 * 字段偏移 top8: 0x4×10 / 0x8×9 / 0xc×8 / 0x14×2 / 0x2b4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20a148 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x20a14c mov r5, r0
 *   @0x20a150 ldr r3, [r0, #0x4]
 *   @0x20a154 mov r8, r1
 *   @0x20a158 mov r9, r2
 *   @0x20a15c cmp r3, #0
 *   @0x20a160 pople {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x20a164 ldr r7, [pc, #0x2b4]
 *   @0x20a168 mov r4, #0
 *   @0x20a16c ldr r7, [pc, r7]
 *   @0x20a170 b 0x20a180 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x38>
 *   @0x20a174 ldr r3, [r5, #0x4]
 *   @0x20a178 cmp r3, r4
 *   @0x20a17c ble 0x20a280 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x138>
 *   @0x20a180 ldr r0, [r5, #0xc]
 *   @0x20a184 lsl r6, r4, #4
 *   @0x20a188 mov r1, r8
 *   @0x20a18c ldrd r2, r3, [r7]
 *   @0x20a190 add r0, r0, r6
 *   @0x20a194 add r4, r4, #1
 *   @0x20a198 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x20a19c cmp r0, #0
 *   @0x20a1a0 bne 0x20a174 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x2c>
 *   @0x20a1a4 ldr r8, [r5, #0x14]
 *   @0x20a1a8 add r7, r8, r6
 *   @0x20a1ac ldr r3, [r7, #0xc]
 *   @0x20a1b0 sub r3, r3, #1
 *   @0x20a1b4 bic r3, r3, #-16777216
 *   @0x20a1b8 bic r3, r3, #3
 *   @0x20a1bc cmp r3, #0
 *   @0x20a1c0 movne r4, r7
 *   @0x20a1c4 beq 0x20a338 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x1f0>
 *   @0x20a1c8 mov r3, #5
 *   @0x20a1cc str r3, [r7, #0xc]
 *   @0x20a1d0 ldr r1, [r4, #0xc]
 *   @0x20a1d4 mov r3, #0
 *   @0x20a1d8 str r3, [r7, #0x8]
 *   @0x20a1dc bic r2, r1, #-16777216
 *   @0x20a1e0 str r3, [r8, r6]
 *   @0x20a1e4 cmp r2, #1
 *   @0x20a1e8 beq 0x20a304 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x1bc>
 *   @0x20a1ec cmp r2, #2
 *   @0x20a1f0 bne 0x20a218 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0xd0>
 *   @0x20a1f4 sub r3, r1, #1
 *   @0x20a1f8 bic r3, r3, #-16777216
 *   @0x20a1fc bic r3, r3, #3
 *   @0x20a200 cmp r3, #0
 *   @0x20a204 beq 0x20a3bc <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x274>
 *   @0x20a208 mov r2, #0
 *   @0x20a20c mov r3, #5
 *   @0x20a210 str r2, [r4, #0x8]
 *   @0x20a214 str r3, [r4, #0xc]
 *   @0x20a218 ldr r3, [r9, #0xc]
 *   @0x20a21c mov r1, #0
 *   @0x20a220 ldr r2, [r9, #0x8]
 *   @0x20a224 str r1, [r4]
 *   @0x20a228 str r3, [r4, #0xc]
 *   @0x20a22c ldr r3, [r9, #0xc]
 *   @0x20a230 str r2, [r4, #0x8]
 *   @0x20a234 bic r3, r3, #-16777216
 *   @0x20a238 cmp r3, #14
 *   @0x20a23c addls pc, pc, r3, lsl #2
 *   @0x20a240 b 0x20a280 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x138>
 *   @0x20a244 b 0x20a290 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x148>
 *   @0x20a248 b 0x20a2ec <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x1a4>
 *   @0x20a24c b 0x20a2c0 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x178>
 *   @0x20a250 b 0x20a284 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x13c>
 *   @0x20a254 b 0x20a280 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x138>
 *   @0x20a258 b 0x20a280 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x138>
 *   @0x20a25c b 0x20a29c <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x154>
 *   @0x20a260 b 0x20a284 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x13c>
 *   @0x20a264 b 0x20a280 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x138>
 *   @0x20a268 b 0x20a280 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x138>
 *   @0x20a26c b 0x20a290 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x148>
 *   @0x20a270 b 0x20a280 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x138>
 *   @0x20a274 b 0x20a280 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x138>
 *   @0x20a278 b 0x20a290 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x148>
 *   @0x20a27c b 0x20a284 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x13c>
 *   @0x20a280 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x20a284 ldr r3, [r9]
 *   @0x20a288 str r3, [r4]
 *   @0x20a28c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x20a290 ldm r9, {r2, r3}
 *   @0x20a294 stm r4, {r2, r3}
 *   @0x20a298 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x20a29c ldr r3, [r9]
 *   @0x20a2a0 str r3, [r4]
 *   @0x20a2a4 ldr r3, [r9]
 *   @0x20a2a8 cmp r3, #0
 *   @0x20a2ac popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x20a2b0 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20a2b4 ldr r1, [r9]
 *   @0x20a2b8 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x20a2bc b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20a2c0 ldr r3, [r9]
 *   @0x20a2c4 cmp r3, #0
 *   @0x20a2c8 str r3, [r4]
 *   @0x20a2cc popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x20a2d0 ldr r1, [r3, #0x8]
 *   @0x20a2d4 ldr r2, [r3]
 *   @0x20a2d8 cmp r1, #0
 *   @0x20a2dc streq r4, [r3, #0x8]
 *   @0x20a2e0 add r2, r2, #1
 *   @0x20a2e4 str r2, [r3]
 *   @0x20a2e8 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x20a2ec ldr r3, [r9]
 *   @0x20a2f0 cmp r3, #0
 *   @0x20a2f4 ldrne r2, [r3, #0x4]
 *   @0x20a2f8 addne r2, r2, #1
 *   @0x20a2fc strne r2, [r3, #0x4]
 *   @0x20a300 b 0x20a288 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x140>
 *   @0x20a304 ldr r5, [r4]
 *   @0x20a308 cmp r5, #0
 *   @0x20a30c beq 0x20a32c <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x1e4>
 *   @0x20a310 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20a314 ldr r6, [r5, #0x4]
 *   @0x20a318 sub r6, r6, #1
 *   @0x20a31c str r6, [r5, #0x4]
 *   @0x20a320 cmp r6, #0
 *   @0x20a324 beq 0x20a34c <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x204>
 *   @0x20a328 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20a32c mov r3, #0
 *   @0x20a330 str r3, [r4]
 *   @0x20a334 b 0x20a218 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0xd0>
 *   @0x20a338 mov r0, r7
 *   @0x20a33c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20a340 ldr r4, [r5, #0x14]
 *   @0x20a344 add r4, r4, r6
 *   @0x20a348 b 0x20a1c8 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x80>
 *   @0x20a34c ldr r0, [r5]
 *   @0x20a350 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20a354 str r6, [r5]
 *   @0x20a358 str r6, [r5, #0x8]
 *   @0x20a35c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20a360 ldr r6, [r5, #0x4]
 *   @0x20a364 sub r6, r6, #1
 *   @0x20a368 str r6, [r5, #0x4]
 *   @0x20a36c cmp r6, #0
 *   @0x20a370 beq 0x20a384 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x23c>
 *   @0x20a374 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20a378 mov r0, r5
 *   @0x20a37c bl 0x27d1d0 <_ZdlPv>
 *   @0x20a380 b 0x20a328 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x1e0>
 *   @0x20a384 ldr r0, [r5]
 *   @0x20a388 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20a38c str r6, [r5]
 *   @0x20a390 str r6, [r5, #0x8]
 *   @0x20a394 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20a398 ldr r6, [r5, #0x4]
 *   @0x20a39c sub r6, r6, #1
 *   @0x20a3a0 str r6, [r5, #0x4]
 *   @0x20a3a4 cmp r6, #0
 *   @0x20a3a8 beq 0x20a3c8 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x280>
 *   @0x20a3ac bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20a3b0 mov r0, r5
 *   @0x20a3b4 bl 0x27d1d0 <_ZdlPv>
 *   @0x20a3b8 b 0x20a374 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x22c>
 *   @0x20a3bc mov r0, r4
 *   @0x20a3c0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20a3c4 b 0x20a208 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0xc0>
 *   @0x20a3c8 ldr r0, [r5]
 *   @0x20a3cc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20a3d0 str r6, [r5]
 *   @0x20a3d4 str r6, [r5, #0x8]
 *   @0x20a3d8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20a3dc ldr r6, [r5, #0x4]
 *   @0x20a3e0 sub r6, r6, #1
 *   @0x20a3e4 str r6, [r5, #0x4]
 *   @0x20a3e8 cmp r6, #0
 *   @0x20a3ec bne 0x20a410 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x2c8>
 *   @0x20a3f0 ldr r0, [r5]
 *   @0x20a3f4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20a3f8 mov r0, r5
 *   @0x20a3fc str r6, [r5]
 *   @0x20a400 str r6, [r5, #0x8]
 *   @0x20a404 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20a408 mov r0, r5
 *   @0x20a40c bl 0x27d1d0 <_ZdlPv>
 *   @0x20a410 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20a414 mov r0, r5
 *   @0x20a418 bl 0x27d1d0 <_ZdlPv>
 *   @0x20a41c b 0x20a3ac <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x264>
 *   @0x20a420 andseq r7, lr, r8, lsl r2
 *
 * ══ §37/42 F_DsGridSet_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0x10316c  size 728  182 条（0x10316c..0x103444）
 * @func 0x10316c 0x103444  size 728  182 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / LOCK_RVALUE_MUTEX()×2 / UNLOCK_RVALUE_MUTEX()×2 / YYFree(void const*)×2 / operator delete(void*)×2 / F_DsGridSet_debug(RValue&, CInstance*, CInstance*, int, RValue*)+0x148 / F_DsGridSet_debug(RValue&, CInstance*, CInstance*, int, RValue*)+0x160 / F_DsGridSet_debug(RValue&, CInstance*, CInstance*, int, RValue*)+0x164
 * 字段偏移 top8: 0x4×14 / 0x30×8 / 0x8×7 / 0xc×4 / 0x3c×2 / 0x278×1 / 0x268×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10316c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x103170 sub sp, sp, #20
 *   @0x103174 mov r1, #0
 *   @0x103178 ldr r4, [sp, #0x30]
 *   @0x10317c mov r0, r4
 *   @0x103180 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x103184 mov r1, #1
 *   @0x103188 mov r5, r0
 *   @0x10318c mov r0, r4
 *   @0x103190 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x103194 mov r1, #2
 *   @0x103198 mov r6, r0
 *   @0x10319c mov r0, r4
 *   @0x1031a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1031a4 cmp r5, #0
 *   @0x1031a8 mov r12, r0
 *   @0x1031ac blt 0x1032b4 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x1031b0 ldr r2, [pc, #0x278]
 *   @0x1031b4 ldr r2, [pc, r2]
 *   @0x1031b8 ldr r3, [r2]
 *   @0x1031bc cmp r5, r3
 *   @0x1031c0 bge 0x1032b4 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x1031c4 ldr r3, [pc, #0x268]
 *   @0x1031c8 ldr r3, [pc, r3]
 *   @0x1031cc ldr r3, [r3, #0x4]
 *   @0x1031d0 ldr r3, [r3, r5, lsl #2]
 *   @0x1031d4 cmp r3, #0
 *   @0x1031d8 beq 0x1032b4 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x1031dc cmp r6, #0
 *   @0x1031e0 ldr r7, [r3, #0x4]
 *   @0x1031e4 blt 0x1032cc <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x1031e8 cmp r6, r7
 *   @0x1031ec bge 0x1032cc <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x1031f0 cmp r0, #0
 *   @0x1031f4 ldr r8, [r3, #0x8]
 *   @0x1031f8 blt 0x1032d0 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x1031fc cmp r0, r8
 *   @0x103200 bge 0x1032d0 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x103204 mla r6, r7, r0, r6
 *   @0x103208 ldr r8, [r3]
 *   @0x10320c add r5, r8, r6, lsl #4
 *   @0x103210 ldr r2, [r5, #0xc]
 *   @0x103214 bic r3, r2, #-16777216
 *   @0x103218 cmp r3, #1
 *   @0x10321c beq 0x103394 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x228>
 *   @0x103220 cmp r3, #2
 *   @0x103224 bne 0x10324c <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x103228 sub r3, r2, #1
 *   @0x10322c bic r3, r3, #-16777216
 *   @0x103230 bic r3, r3, #3
 *   @0x103234 cmp r3, #0
 *   @0x103238 beq 0x103424 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x2b8>
 *   @0x10323c mov r2, #0
 *   @0x103240 mov r3, #5
 *   @0x103244 str r2, [r5, #0x8]
 *   @0x103248 str r3, [r5, #0xc]
 *   @0x10324c ldr r3, [r4, #0x3c]
 *   @0x103250 mov r1, #0
 *   @0x103254 ldr r2, [r4, #0x38]
 *   @0x103258 str r1, [r8, r6, lsl #4]
 *   @0x10325c str r3, [r5, #0xc]
 *   @0x103260 ldr r3, [r4, #0x3c]
 *   @0x103264 str r2, [r5, #0x8]
 *   @0x103268 bic r3, r3, #-16777216
 *   @0x10326c cmp r3, #14
 *   @0x103270 addls pc, pc, r3, lsl #2
 *   @0x103274 b 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x103278 b 0x103314 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x10327c b 0x103354 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0x103280 b 0x103328 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x1bc>
 *   @0x103284 b 0x103308 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x103288 b 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x10328c b 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x103290 b 0x10336c <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x200>
 *   @0x103294 b 0x103308 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x103298 b 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x10329c b 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x1032a0 b 0x103314 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x1032a4 b 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x1032a8 b 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x1032ac b 0x103314 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x1032b0 b 0x103308 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x1032b4 ldr r0, [pc, #0x17c]
 *   @0x1032b8 mov r1, #0
 *   @0x1032bc add r0, pc, r0
 *   @0x1032c0 add sp, sp, #20
 *   @0x1032c4 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1032c8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1032cc ldr r8, [r3, #0x8]
 *   @0x1032d0 ldr r0, [pc, #0x164]
 *   @0x1032d4 mov r2, r5
 *   @0x1032d8 ldr r1, [pc, #0x160]
 *   @0x1032dc mov r3, r6
 *   @0x1032e0 ldr r0, [pc, r0]
 *   @0x1032e4 add r1, pc, r1
 *   @0x1032e8 ldr r0, [r0]
 *   @0x1032ec ldr lr, [r0]
 *   @0x1032f0 str r12, [sp]
 *   @0x1032f4 stmib sp, {r7, r8}
 *   @0x1032f8 ldr r12, [lr, #0xc]
 *   @0x1032fc blx r12
 *   @0x103300 add sp, sp, #20
 *   @0x103304 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x103308 ldr r3, [r4, #0x30]
 *   @0x10330c str r3, [r8, r6, lsl #4]
 *   @0x103310 b 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x103314 ldr r2, [r4, #0x30]
 *   @0x103318 ldr r3, [r4, #0x34]
 *   @0x10331c str r2, [r8, r6, lsl #4]
 *   @0x103320 str r3, [r5, #0x4]
 *   @0x103324 b 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x103328 ldr r3, [r4, #0x30]
 *   @0x10332c cmp r3, #0
 *   @0x103330 str r3, [r8, r6, lsl #4]
 *   @0x103334 beq 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x103338 ldr r1, [r3, #0x8]
 *   @0x10333c ldr r2, [r3]
 *   @0x103340 cmp r1, #0
 *   @0x103344 streq r5, [r3, #0x8]
 *   @0x103348 add r2, r2, #1
 *   @0x10334c str r2, [r3]
 *   @0x103350 b 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x103354 ldr r3, [r4, #0x30]
 *   @0x103358 cmp r3, #0
 *   @0x10335c ldrne r2, [r3, #0x4]
 *   @0x103360 addne r2, r2, #1
 *   @0x103364 strne r2, [r3, #0x4]
 *   @0x103368 b 0x10330c <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x10336c ldr r3, [r4, #0x30]
 *   @0x103370 str r3, [r8, r6, lsl #4]
 *   @0x103374 ldr r3, [r4, #0x30]
 *   @0x103378 cmp r3, #0
 *   @0x10337c beq 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x103380 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x103384 ldr r1, [r4, #0x30]
 *   @0x103388 add sp, sp, #20
 *   @0x10338c pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0x103390 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x103394 ldr r7, [r8, r6, lsl #4]
 *   @0x103398 cmp r7, #0
 *   @0x10339c beq 0x1033bc <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x250>
 *   @0x1033a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1033a4 ldr r3, [r7, #0x4]
 *   @0x1033a8 sub r3, r3, #1
 *   @0x1033ac str r3, [r7, #0x4]
 *   @0x1033b0 cmp r3, #0
 *   @0x1033b4 beq 0x1033c8 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x25c>
 *   @0x1033b8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1033bc mov r3, #0
 *   @0x1033c0 str r3, [r8, r6, lsl #4]
 *   @0x1033c4 b 0x10324c <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x1033c8 ldr r0, [r7]
 *   @0x1033cc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1033d0 mov r3, #0
 *   @0x1033d4 str r3, [r7]
 *   @0x1033d8 str r3, [r7, #0x8]
 *   @0x1033dc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1033e0 ldr r9, [r7, #0x4]
 *   @0x1033e4 sub r9, r9, #1
 *   @0x1033e8 str r9, [r7, #0x4]
 *   @0x1033ec cmp r9, #0
 *   @0x1033f0 bne 0x103414 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x2a8>
 *   @0x1033f4 ldr r0, [r7]
 *   @0x1033f8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1033fc mov r0, r7
 *   @0x103400 str r9, [r7]
 *   @0x103404 str r9, [r7, #0x8]
 *   @0x103408 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x10340c mov r0, r7
 *   @0x103410 bl 0x27d1d0 <_ZdlPv>
 *   @0x103414 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x103418 mov r0, r7
 *   @0x10341c bl 0x27d1d0 <_ZdlPv>
 *   @0x103420 b 0x1033b8 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x24c>
 *   @0x103424 mov r0, r5
 *   @0x103428 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x10342c b 0x10323c <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x103430 .word 0x002eacd0
 *   @0x103434 eoreq r10, lr, r0, asr #25
 *   @0x103438 eoreq r4, r3, r0, asr #18
 *   @0x10343c eoreq r10, lr, r0, ror #12
 *   @0x103440 eoreq r5, r3, r8, lsr #7
 *
 * ══ §38/42 F_DsMapSetPre(RValue&, CInstance*, CInstance*, int, RValue*)  0x106ee4  size 728  182 条（0x106ee4..0x1071bc）
 * @func 0x106ee4 0x1071bc  size 728  182 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / YYGetInt32(RValue const*, int) / F_DsMapSetPre(RValue&, CInstance*, CInstance*, int, RValue*)+0x12c
 * 字段偏移 top8: 0x4×9 / 0x8×7 / 0x20×7 / 0xc×3 / 0x28×2 / 0x2c×2 / 0x1e4×1 / 0x1d4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x106ee4 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x106ee8 sub sp, sp, #12
 *   @0x106eec add r7, sp, #4
 *   @0x106ef0 mov r4, r0
 *   @0x106ef4 ldr r5, [sp, #0x28]
 *   @0x106ef8 mov r0, r7
 *   @0x106efc bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x106f00 mov r1, #0
 *   @0x106f04 mov r0, r5
 *   @0x106f08 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x106f0c ldr r2, [r4, #0xc]
 *   @0x106f10 bic r3, r2, #-16777216
 *   @0x106f14 cmp r3, #1
 *   @0x106f18 mov r6, r0
 *   @0x106f1c beq 0x107040 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x106f20 cmp r3, #2
 *   @0x106f24 bne 0x106f4c <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x106f28 sub r2, r2, #1
 *   @0x106f2c bic r2, r2, #-16777216
 *   @0x106f30 bic r2, r2, #3
 *   @0x106f34 cmp r2, #0
 *   @0x106f38 beq 0x107114 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x230>
 *   @0x106f3c mov r2, #0
 *   @0x106f40 mov r3, #5
 *   @0x106f44 str r2, [r4, #0x8]
 *   @0x106f48 str r3, [r4, #0xc]
 *   @0x106f4c ldr r3, [r5, #0x2c]
 *   @0x106f50 mov r1, #0
 *   @0x106f54 ldr r2, [r5, #0x28]
 *   @0x106f58 str r1, [r4]
 *   @0x106f5c str r3, [r4, #0xc]
 *   @0x106f60 ldr r3, [r5, #0x2c]
 *   @0x106f64 str r2, [r4, #0x8]
 *   @0x106f68 bic r3, r3, #-16777216
 *   @0x106f6c cmp r3, #14
 *   @0x106f70 addls pc, pc, r3, lsl #2
 *   @0x106f74 b 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x106f78 b 0x107030 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x106f7c b 0x1070a0 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x1bc>
 *   @0x106f80 b 0x107074 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x190>
 *   @0x106f84 b 0x106fb4 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x106f88 b 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x106f8c b 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x106f90 b 0x1070b8 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x1d4>
 *   @0x106f94 b 0x106fb4 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x106f98 b 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x106f9c b 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x106fa0 b 0x107030 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x106fa4 b 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x106fa8 b 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x106fac b 0x107030 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x106fb0 b 0x106fb4 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x106fb4 ldr r3, [r5, #0x20]
 *   @0x106fb8 str r3, [r4]
 *   @0x106fbc cmp r6, #0
 *   @0x106fc0 blt 0x107010 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x106fc4 ldr r3, [pc, #0x1e4]
 *   @0x106fc8 ldr r3, [pc, r3]
 *   @0x106fcc ldr r3, [r3]
 *   @0x106fd0 cmp r6, r3
 *   @0x106fd4 bge 0x107010 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x106fd8 ldr r3, [pc, #0x1d4]
 *   @0x106fdc ldr r3, [pc, r3]
 *   @0x106fe0 ldr r3, [r3, #0x4]
 *   @0x106fe4 ldr r0, [r3, r6, lsl #2]
 *   @0x106fe8 cmp r0, #0
 *   @0x106fec beq 0x107010 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x106ff0 add r1, r5, #16
 *   @0x106ff4 add r2, r5, #32
 *   @0x106ff8 mov r3, #0
 *   @0x106ffc bl 0x208c3c <_ZN7CDS_Map3SetEP6RValueS1_S1_>
 *   @0x107000 mov r0, r7
 *   @0x107004 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x107008 add sp, sp, #12
 *   @0x10700c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x107010 ldr r0, [pc, #0x1a0]
 *   @0x107014 mov r1, #0
 *   @0x107018 add r0, pc, r0
 *   @0x10701c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x107020 mov r0, r7
 *   @0x107024 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x107028 add sp, sp, #12
 *   @0x10702c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x107030 ldr r2, [r5, #0x20]
 *   @0x107034 ldr r3, [r5, #0x24]
 *   @0x107038 stm r4, {r2, r3}
 *   @0x10703c b 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x107040 ldr r8, [r4]
 *   @0x107044 cmp r8, #0
 *   @0x107048 beq 0x107068 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0x10704c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x107050 ldr r9, [r8, #0x4]
 *   @0x107054 sub r9, r9, #1
 *   @0x107058 str r9, [r8, #0x4]
 *   @0x10705c cmp r9, #0
 *   @0x107060 beq 0x1070dc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0x107064 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x107068 mov r3, #0
 *   @0x10706c str r3, [r4]
 *   @0x107070 b 0x106f4c <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x107074 ldr r3, [r5, #0x20]
 *   @0x107078 cmp r3, #0
 *   @0x10707c str r3, [r4]
 *   @0x107080 beq 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x107084 ldr r1, [r3, #0x8]
 *   @0x107088 ldr r2, [r3]
 *   @0x10708c cmp r1, #0
 *   @0x107090 streq r4, [r3, #0x8]
 *   @0x107094 add r2, r2, #1
 *   @0x107098 str r2, [r3]
 *   @0x10709c b 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x1070a0 ldr r3, [r5, #0x20]
 *   @0x1070a4 cmp r3, #0
 *   @0x1070a8 ldrne r2, [r3, #0x4]
 *   @0x1070ac addne r2, r2, #1
 *   @0x1070b0 strne r2, [r3, #0x4]
 *   @0x1070b4 b 0x106fb8 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x1070b8 ldr r3, [r5, #0x20]
 *   @0x1070bc str r3, [r4]
 *   @0x1070c0 ldr r3, [r5, #0x20]
 *   @0x1070c4 cmp r3, #0
 *   @0x1070c8 beq 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x1070cc bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x1070d0 ldr r1, [r5, #0x20]
 *   @0x1070d4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x1070d8 b 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x1070dc ldr r0, [r8]
 *   @0x1070e0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1070e4 str r9, [r8]
 *   @0x1070e8 str r9, [r8, #0x8]
 *   @0x1070ec bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1070f0 ldr r9, [r8, #0x4]
 *   @0x1070f4 sub r9, r9, #1
 *   @0x1070f8 str r9, [r8, #0x4]
 *   @0x1070fc cmp r9, #0
 *   @0x107100 beq 0x107120 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x23c>
 *   @0x107104 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x107108 mov r0, r8
 *   @0x10710c bl 0x27d1d0 <_ZdlPv>
 *   @0x107110 b 0x107064 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x180>
 *   @0x107114 mov r0, r4
 *   @0x107118 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x10711c b 0x106f3c <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x107120 ldr r0, [r8]
 *   @0x107124 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x107128 str r9, [r8]
 *   @0x10712c str r9, [r8, #0x8]
 *   @0x107130 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x107134 ldr r9, [r8, #0x4]
 *   @0x107138 sub r9, r9, #1
 *   @0x10713c str r9, [r8, #0x4]
 *   @0x107140 cmp r9, #0
 *   @0x107144 beq 0x107158 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x274>
 *   @0x107148 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x10714c mov r0, r8
 *   @0x107150 bl 0x27d1d0 <_ZdlPv>
 *   @0x107154 b 0x107104 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x220>
 *   @0x107158 ldr r0, [r8]
 *   @0x10715c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x107160 str r9, [r8]
 *   @0x107164 str r9, [r8, #0x8]
 *   @0x107168 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x10716c ldr r9, [r8, #0x4]
 *   @0x107170 sub r9, r9, #1
 *   @0x107174 str r9, [r8, #0x4]
 *   @0x107178 cmp r9, #0
 *   @0x10717c bne 0x1071a0 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x2bc>
 *   @0x107180 ldr r0, [r8]
 *   @0x107184 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x107188 mov r0, r8
 *   @0x10718c str r9, [r8]
 *   @0x107190 str r9, [r8, #0x8]
 *   @0x107194 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x107198 mov r0, r8
 *   @0x10719c bl 0x27d1d0 <_ZdlPv>
 *   @0x1071a0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1071a4 mov r0, r8
 *   @0x1071a8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1071ac b 0x107148 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x264>
 *   @0x1071b0 .word 0x002e6cb0
 *   @0x1071b4 eoreq r6, lr, r0, ror #18
 *   @0x1071b8 eoreq r0, r3, r4, ror #23
 *
 * ══ §39/42 F_ExternalCall(RValue&, CInstance*, CInstance*, int, RValue*)  0x1194cc  size 728  182 条（0x1194cc..0x1197a4）
 * @func 0x1194cc 0x1197a4  size 728  182 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYGetInt32(RValue const*, int) / F_ExternalCall(RValue&, CInstance*, CInstance*, int, RValue*)+0x170 / 0xb65b0 / F_ExternalCall(RValue&, CInstance*, CInstance*, int, RValue*)+0x74
 * 字段偏移 top8: 0x4×10 / 0x8×8 / 0xc×5 / 0x140×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1194cc push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1194d0 sub sp, sp, #292
 *   @0x1194d4 mov r7, r0
 *   @0x1194d8 mov r1, #0
 *   @0x1194dc ldr r4, [sp, #0x140]
 *   @0x1194e0 mov r6, r3
 *   @0x1194e4 mov r0, r4
 *   @0x1194e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1194ec subs r8, r0, #0
 *   @0x1194f0 blt 0x11963c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x1194f4 add r5, sp, #16
 *   @0x1194f8 sub r9, r6, #1
 *   @0x1194fc mov r1, #0
 *   @0x119500 mov r2, #272
 *   @0x119504 mov r0, r5
 *   @0x119508 bl 0xb65b0 <memset@plt>
 *   @0x11950c cmp r9, #0
 *   @0x119510 subgt r6, r6, #-268435455
 *   @0x119514 movgt r12, r4
 *   @0x119518 movgt r4, #0
 *   @0x11951c lslgt r6, r6, #4
 *   @0x119520 ble 0x119540 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x119524 add r12, r12, #16
 *   @0x119528 add lr, r5, r4
 *   @0x11952c add r4, r4, #16
 *   @0x119530 ldm r12, {r0, r1, r2, r3}
 *   @0x119534 cmp r4, r6
 *   @0x119538 stm lr, {r0, r1, r2, r3}
 *   @0x11953c bne 0x119524 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x119540 mov r2, r5
 *   @0x119544 mov r3, sp
 *   @0x119548 mov r0, r8
 *   @0x11954c mov r1, r9
 *   @0x119550 mov r12, #0
 *   @0x119554 str r12, [sp]
 *   @0x119558 str r12, [sp, #0x4]
 *   @0x11955c str r12, [sp, #0x8]
 *   @0x119560 str r12, [sp, #0xc]
 *   @0x119564 bl 0x212b10 <_Z8DLL_CalliiP6RValueS0_>
 *   @0x119568 ldr r2, [r7, #0xc]
 *   @0x11956c bic r3, r2, #-16777216
 *   @0x119570 cmp r3, #1
 *   @0x119574 beq 0x1195f8 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x119578 cmp r3, #2
 *   @0x11957c bne 0x119594 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x119580 sub r3, r2, #1
 *   @0x119584 bic r3, r3, #-16777216
 *   @0x119588 bic r3, r3, #3
 *   @0x11958c cmp r3, #0
 *   @0x119590 beq 0x1196d0 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x204>
 *   @0x119594 ldr r2, [sp, #0xc]
 *   @0x119598 mov r0, #0
 *   @0x11959c ldr r1, [sp, #0x8]
 *   @0x1195a0 bic r3, r2, #-16777216
 *   @0x1195a4 str r0, [r7]
 *   @0x1195a8 str r2, [r7, #0xc]
 *   @0x1195ac str r1, [r7, #0x8]
 *   @0x1195b0 cmp r3, #14
 *   @0x1195b4 addls pc, pc, r3, lsl #2
 *   @0x1195b8 b 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x1195bc b 0x11965c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x190>
 *   @0x1195c0 b 0x119698 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x1cc>
 *   @0x1195c4 b 0x11966c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x1195c8 b 0x11962c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x1195cc b 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x1195d0 b 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x1195d4 b 0x1196b0 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x1195d8 b 0x11962c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x1195dc b 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x1195e0 b 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x1195e4 b 0x11965c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x190>
 *   @0x1195e8 b 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x1195ec b 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x1195f0 b 0x11965c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x190>
 *   @0x1195f4 b 0x11962c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x1195f8 ldr r4, [r7]
 *   @0x1195fc cmp r4, #0
 *   @0x119600 beq 0x119620 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x119604 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x119608 ldr r5, [r4, #0x4]
 *   @0x11960c sub r5, r5, #1
 *   @0x119610 str r5, [r4, #0x4]
 *   @0x119614 cmp r5, #0
 *   @0x119618 beq 0x1196dc <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x210>
 *   @0x11961c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x119620 mov r3, #0
 *   @0x119624 str r3, [r7]
 *   @0x119628 b 0x119594 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x11962c ldr r3, [sp]
 *   @0x119630 str r3, [r7]
 *   @0x119634 add sp, sp, #292
 *   @0x119638 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x11963c mov r2, #0
 *   @0x119640 mov r3, r2
 *   @0x119644 movt r2, #0xbff0
 *   @0x119648 str r3, [r7]
 *   @0x11964c str r2, [r7, #0x4]
 *   @0x119650 str r3, [r7, #0xc]
 *   @0x119654 add sp, sp, #292
 *   @0x119658 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x11965c ldm sp, {r2, r3}
 *   @0x119660 stm r7, {r2, r3}
 *   @0x119664 add sp, sp, #292
 *   @0x119668 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x11966c ldr r3, [sp]
 *   @0x119670 cmp r3, #0
 *   @0x119674 str r3, [r7]
 *   @0x119678 beq 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x11967c ldr r1, [r3, #0x8]
 *   @0x119680 ldr r2, [r3]
 *   @0x119684 cmp r1, #0
 *   @0x119688 streq r7, [r3, #0x8]
 *   @0x11968c add r2, r2, #1
 *   @0x119690 str r2, [r3]
 *   @0x119694 b 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x119698 ldr r3, [sp]
 *   @0x11969c cmp r3, #0
 *   @0x1196a0 ldrne r2, [r3, #0x4]
 *   @0x1196a4 addne r2, r2, #1
 *   @0x1196a8 strne r2, [r3, #0x4]
 *   @0x1196ac b 0x119630 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x1196b0 ldr r3, [sp]
 *   @0x1196b4 cmp r3, #0
 *   @0x1196b8 str r3, [r7]
 *   @0x1196bc beq 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x1196c0 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x1196c4 ldr r1, [sp]
 *   @0x1196c8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x1196cc b 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x1196d0 mov r0, r7
 *   @0x1196d4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1196d8 b 0x119594 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x1196dc ldr r0, [r4]
 *   @0x1196e0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1196e4 str r5, [r4]
 *   @0x1196e8 str r5, [r4, #0x8]
 *   @0x1196ec bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1196f0 ldr r5, [r4, #0x4]
 *   @0x1196f4 sub r5, r5, #1
 *   @0x1196f8 str r5, [r4, #0x4]
 *   @0x1196fc cmp r5, #0
 *   @0x119700 beq 0x119714 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x248>
 *   @0x119704 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x119708 mov r0, r4
 *   @0x11970c bl 0x27d1d0 <_ZdlPv>
 *   @0x119710 b 0x11961c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x119714 ldr r0, [r4]
 *   @0x119718 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x11971c str r5, [r4]
 *   @0x119720 str r5, [r4, #0x8]
 *   @0x119724 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x119728 ldr r5, [r4, #0x4]
 *   @0x11972c sub r5, r5, #1
 *   @0x119730 str r5, [r4, #0x4]
 *   @0x119734 cmp r5, #0
 *   @0x119738 beq 0x11974c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x280>
 *   @0x11973c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x119740 mov r0, r4
 *   @0x119744 bl 0x27d1d0 <_ZdlPv>
 *   @0x119748 b 0x119704 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x238>
 *   @0x11974c ldr r0, [r4]
 *   @0x119750 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x119754 str r5, [r4]
 *   @0x119758 str r5, [r4, #0x8]
 *   @0x11975c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x119760 ldr r5, [r4, #0x4]
 *   @0x119764 sub r5, r5, #1
 *   @0x119768 str r5, [r4, #0x4]
 *   @0x11976c cmp r5, #0
 *   @0x119770 bne 0x119794 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x2c8>
 *   @0x119774 ldr r0, [r4]
 *   @0x119778 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x11977c mov r0, r4
 *   @0x119780 str r5, [r4]
 *   @0x119784 str r5, [r4, #0x8]
 *   @0x119788 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x11978c mov r0, r4
 *   @0x119790 bl 0x27d1d0 <_ZdlPv>
 *   @0x119794 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x119798 mov r0, r4
 *   @0x11979c bl 0x27d1d0 <_ZdlPv>
 *   @0x1197a0 b 0x11973c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x270>
 *
 * ══ §40/42 F_FileBinOpen(RValue&, CInstance*, CInstance*, int, RValue*)  0x13adac  size 728  182 条（0x13adac..0x13b084）
 * @func 0x13adac 0x13b084  size 728  182 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x13adfc→0x483924, 0x13ae3c→0x483944, 0x13aebc→0x483ac4, 0x13afa8→0x483ac4, 0x13afe8→0x3eb70c, 0x13b010→0x483ac4
 * 调用序列: LoadSave::_GetSaveFileName(char*, int, char const*)×2 / LoadSave::fopen(char const*, char const*)×2 / YYGetString(RValue const*, int) / YYGetInt32(RValue const*, int) / F_FileBinOpen(RValue&, CInstance*, CInstance*, int, RValue*)+0xd0 / LoadSave::fclose(_YYFILE*) / MemoryManager::Free(void const*) / LoadSave::SaveFileExists(char const*)
 * 字段偏移 top8: 0xc×9 / 0x8×8 / 0x4×5 / 0x2×3 / 0x414×2 / 0x88×2 / 0x2a0×1 / 0x29c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13adac push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13adb0 sub sp, sp, #1040
 *   @0x13adb4 ldr r4, [pc, #0x2a0]
 *   @0x13adb8 sub sp, sp, #12
 *   @0x13adbc ldr r3, [pc, #0x29c]
 *   @0x13adc0 mov r5, r0
 *   @0x13adc4 add r4, pc, r4
 *   @0x13adc8 ldr r6, [sp, #0x440]
 *   @0x13adcc mov r1, #0
 *   @0x13add0 mov r11, #1
 *   @0x13add4 ldr r3, [r4, r3]
 *   @0x13add8 mov r0, r6
 *   @0x13addc str r3, [sp, #0x4]
 *   @0x13ade0 ldr r3, [r3]
 *   @0x13ade4 str r3, [sp, #0x414]
 *   @0x13ade8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13adec mov r1, #1
 *   @0x13adf0 str r0, [sp, #0xc]
 *   @0x13adf4 mov r0, r6
 *   @0x13adf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13adfc ldr r1, [pc, #0x260]
 *   @0x13ae00 mov r2, #0
 *   @0x13ae04 mov r3, r2
 *   @0x13ae08 movt r2, #0xbff0
 *   @0x13ae0c str r3, [r5, #0xc]
 *   @0x13ae10 str r2, [r5, #0x4]
 *   @0x13ae14 str r3, [r5]
 *   @0x13ae18 str r0, [sp, #0x8]
 *   @0x13ae1c ldr r10, [r4, r1]
 *   @0x13ae20 ldrb r3, [r10, #0x1]
 *   @0x13ae24 cmp r3, #0
 *   @0x13ae28 beq 0x13ae3c <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x13ae2c add r11, r11, #1
 *   @0x13ae30 ldrb r3, [r10, r11]
 *   @0x13ae34 cmp r3, #0
 *   @0x13ae38 bne 0x13ae2c <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x13ae3c ldr r2, [pc, #0x224]
 *   @0x13ae40 add r6, r11, r11, lsl #1
 *   @0x13ae44 lsl r6, r6, #2
 *   @0x13ae48 ldr r2, [r4, r2]
 *   @0x13ae4c add r7, r6, r2
 *   @0x13ae50 str r2, [sp]
 *   @0x13ae54 ldr r0, [r7, #0x8]
 *   @0x13ae58 cmp r0, #0
 *   @0x13ae5c beq 0x13ae98 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x13ae60 ldr r2, [r7, #0x4]
 *   @0x13ae64 cmp r2, #0
 *   @0x13ae68 beq 0x13ae78 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x13ae6c blt 0x13ae7c <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x13ae70 cmp r2, #2
 *   @0x13ae74 bgt 0x13ae7c <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x13ae78 bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE>
 *   @0x13ae7c ldr r3, [sp]
 *   @0x13ae80 mov r8, #0
 *   @0x13ae84 ldr r0, [r3, r6]
 *   @0x13ae88 str r8, [r7, #0x8]
 *   @0x13ae8c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x13ae90 ldr r3, [sp]
 *   @0x13ae94 str r8, [r6, r3]
 *   @0x13ae98 ldr r0, [sp, #0xc]
 *   @0x13ae9c bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x13aea0 cmp r0, #0
 *   @0x13aea4 beq 0x13af84 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x1d8>
 *   @0x13aea8 add r8, sp, #20
 *   @0x13aeac ldr r2, [sp, #0xc]
 *   @0x13aeb0 mov r1, #1024
 *   @0x13aeb4 mov r0, r8
 *   @0x13aeb8 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x13aebc ldr r2, [pc, #0x1a8]
 *   @0x13aec0 ldr r9, [r4, r2]
 *   @0x13aec4 ldr r3, [sp]
 *   @0x13aec8 ldr r0, [r6, r3]
 *   @0x13aecc cmp r0, #0
 *   @0x13aed0 beq 0x13aed8 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x13aed4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x13aed8 mov r0, r8
 *   @0x13aedc bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x13aee0 ldr r3, [sp, #0x8]
 *   @0x13aee4 cmp r3, #0
 *   @0x13aee8 ldr r3, [sp]
 *   @0x13aeec str r0, [r3, r6]
 *   @0x13aef0 beq 0x13afb4 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x208>
 *   @0x13aef4 ldr r3, [sp, #0x8]
 *   @0x13aef8 cmp r3, #1
 *   @0x13aefc beq 0x13b03c <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x290>
 *   @0x13af00 ldr r2, [pc, #0x168]
 *   @0x13af04 add r2, pc, r2
 *   @0x13af08 ldr r2, [r2]
 *   @0x13af0c strh r2, [r9]
 *   @0x13af10 lsr r2, r2, #16
 *   @0x13af14 strb r2, [r9, #0x2]
 *   @0x13af18 mov r0, r8
 *   @0x13af1c bl 0x13ad20 <_Z24EnsureDirectoryIsCreatedPKc>
 *   @0x13af20 mov r0, r8
 *   @0x13af24 mov r1, r9
 *   @0x13af28 bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_>
 *   @0x13af2c mov r2, r0
 *   @0x13af30 cmp r2, #0
 *   @0x13af34 str r0, [r7, #0x8]
 *   @0x13af38 beq 0x13afe8 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x23c>
 *   @0x13af3c vmov s15, r11
 *   @0x13af40 mov r2, #1
 *   @0x13af44 strb r2, [r10, r11]
 *   @0x13af48 vcvt.f64.s32 d7, s15
 *   @0x13af4c ldr r3, [sp, #0x8]
 *   @0x13af50 str r3, [r7, #0x4]
 *   @0x13af54 vmov r0, r1, d7
 *   @0x13af58 vmov r2, s14
 *   @0x13af5c mov r3, r1
 *   @0x13af60 stm r5, {r2, r3}
 *   @0x13af64 ldr r1, [sp, #0x4]
 *   @0x13af68 ldr r2, [sp, #0x414]
 *   @0x13af6c ldr r3, [r1]
 *   @0x13af70 cmp r2, r3
 *   @0x13af74 bne 0x13b058 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x2ac>
 *   @0x13af78 add sp, sp, #1040
 *   @0x13af7c add sp, sp, #12
 *   @0x13af80 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x13af84 ldr r0, [sp, #0xc]
 *   @0x13af88 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x13af8c cmp r0, #0
 *   @0x13af90 beq 0x13b010 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x264>
 *   @0x13af94 add r8, sp, #20
 *   @0x13af98 ldr r2, [sp, #0xc]
 *   @0x13af9c mov r1, #1024
 *   @0x13afa0 mov r0, r8
 *   @0x13afa4 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x13afa8 ldr r2, [pc, #0xbc]
 *   @0x13afac ldr r9, [r4, r2]
 *   @0x13afb0 b 0x13aec4 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x13afb4 ldr r2, [pc, #0xb8]
 *   @0x13afb8 mov r0, r8
 *   @0x13afbc mov r1, r9
 *   @0x13afc0 add r2, pc, r2
 *   @0x13afc4 ldr r2, [r2]
 *   @0x13afc8 strh r2, [r9]
 *   @0x13afcc lsr r2, r2, #16
 *   @0x13afd0 strb r2, [r9, #0x2]
 *   @0x13afd4 bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_>
 *   @0x13afd8 mov r2, r0
 *   @0x13afdc cmp r2, #0
 *   @0x13afe0 str r0, [r7, #0x8]
 *   @0x13afe4 bne 0x13af3c <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x190>
 *   @0x13afe8 ldr r3, [pc, #0x88]
 *   @0x13afec ldr r1, [pc, #0x88]
 *   @0x13aff0 ldr r2, [sp, #0xc]
 *   @0x13aff4 ldr r3, [r4, r3]
 *   @0x13aff8 add r1, pc, r1
 *   @0x13affc ldr r0, [r3]
 *   @0x13b000 ldr r3, [r0]
 *   @0x13b004 ldr r3, [r3, #0xc]
 *   @0x13b008 blx r3
 *   @0x13b00c b 0x13af64 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x13b010 ldr r2, [pc, #0x54]
 *   @0x13b014 add r8, sp, #20
 *   @0x13b018 movw lr, #0x6261
 *   @0x13b01c mov r1, #1024
 *   @0x13b020 movt lr, #0x2b
 *   @0x13b024 mov r0, r8
 *   @0x13b028 ldr r9, [r4, r2]
 *   @0x13b02c ldr r2, [sp, #0xc]
 *   @0x13b030 str lr, [r9]
 *   @0x13b034 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x13b038 b 0x13aec4 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x13b03c ldr r2, [pc, #0x3c]
 *   @0x13b040 add r2, pc, r2
 *   @0x13b044 ldr r2, [r2]
 *   @0x13b048 strh r2, [r9]
 *   @0x13b04c lsr r2, r2, #16
 *   @0x13b050 strb r2, [r9, #0x2]
 *   @0x13b054 b 0x13af18 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x13b058 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x13b05c eoreq r6, r11, r12, lsl #29
 *   @0x13b060 .word 0xffffbd00
 *   @0x13b064 .word 0xffffd63c
 *   @0x13b068 .word 0xffffd640
 *   @0x13b06c .word 0xffffd630
 *   @0x13b070 eoreq r5, r0, r4, asr #8
 *   @0x13b074 andseq r12, pc, r8, lsr r12
 *   @0x13b078 .word 0xffffbac4
 *   @0x13b07c eoreq r5, r0, r4, asr r3
 *   @0x13b080 eoreq r5, r0, r4, lsl #6
 *
 * ══ §41/42 Audio_PlayInSyncGroup(int, int)  0x21d434  size 464  109 条（0x21d434..0x21d604）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x21d434 0x21d604  size 464  109 条
 * 部分覆盖: 本节 109/116 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21d450→0x755363, 0x21d474→0x755314, 0x21d494→0x3eb70c, 0x21d4b0→0x755324, 0x21d52c→0x3eb70c, 0x21d59c→0x3eb70c
 * 调用序列: Audio_GetSound(int) / CAudioGroupMan::IsGroupLoaded(int) / COggAudio::Play_Sound(int, cAudio_Sound*, bool, float, int, int) / LoadSave::_GetBundleFileName(char*, int, char const*) / LoadSave::BundleFileExists(char const*) / YYFree(void const*) / YYStrDup(char const*) / Audio_GetName(int)
 * 字段偏移 top8: 0x4c×3 / 0x30×3 / 0x414×2 / 0x154×2 / 0xc×2 / 0x198×1 / 0x194×1 / 0x18c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21d434 push {r4, r5, r6, r7, r8, lr}
 *   @0x21d438 sub sp, sp, #1040
 *   @0x21d43c ldr r4, [pc, #0x198]
 *   @0x21d440 sub sp, sp, #8
 *   @0x21d444 ldr r3, [pc, #0x194]
 *   @0x21d464 ldr r3, [r4, r2]
 *   @0x21d468 ldrb r3, [r3]
 *   @0x21d46c cmp r3, #0
 *   @0x21d470 bne 0x21d550 <_Z21Audio_PlayInSyncGroupii+0x11c>
 *   @0x21d474 ldr r3, [pc, #0x16c]
 *   @0x21d478 ldr r3, [r4, r3]
 *   @0x21d47c ldrb r3, [r3]
 *   @0x21d480 cmp r3, #0
 *   @0x21d484 beq 0x21d550 <_Z21Audio_PlayInSyncGroupii+0x11c>
 *   @0x21d488 mov r0, r1
 *   @0x21d48c bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x21d490 ldr r1, [pc, #0x154]
 *   @0x21d494 ldr r3, [pc, #0x154]
 *   @0x21d498 add r1, pc, r1
 *   @0x21d49c subs r5, r0, #0
 *   @0x21d4a0 beq 0x21d534 <_Z21Audio_PlayInSyncGroupii+0x100>
 *   @0x21d4a4 ldrb r3, [r5, #0x24]
 *   @0x21d4a8 cmp r3, #0
 *   @0x21d4ac beq 0x21d51c <_Z21Audio_PlayInSyncGroupii+0xe8>
 *   @0x21d4b0 ldr r3, [pc, #0x13c]
 *   @0x21d4b4 ldr r1, [r5, #0x4c]
 *   @0x21d4b8 ldr r0, [r4, r3]
 *   @0x21d4bc bl 0x21e1e0 <_ZN14CAudioGroupMan13IsGroupLoadedEi>
 *   @0x21d4c0 cmp r0, #0
 *   @0x21d4c4 beq 0x21d59c <_Z21Audio_PlayInSyncGroupii+0x168>
 *   @0x21d4c8 ldr r3, [r5, #0x30]
 *   @0x21d4cc cmp r3, #0
 *   @0x21d4d0 beq 0x21d558 <_Z21Audio_PlayInSyncGroupii+0x124>
 *   @0x21d4d4 ldr r0, [pc, #0x11c]
 *   @0x21d4d8 mov r1, #0
 *   @0x21d4dc mov r3, #1
 *   @0x21d4e0 str r1, [sp]
 *   @0x21d4e4 str r3, [sp, #0x4]
 *   @0x21d4e8 mov r2, r5
 *   @0x21d4ec str r8, [sp, #0x8]
 *   @0x21d4f0 add r0, pc, r0
 *   @0x21d4f4 mvn r1, #0
 *   @0x21d4f8 mov r3, #0
 *   @0x21d4fc bl 0x22630c <_ZN9COggAudio10Play_SoundEiP12cAudio_Soundbfii>
 *   @0x21d500 ldr r2, [sp, #0x414]
 *   @0x21d504 ldr r3, [r6]
 *   @0x21d508 cmp r2, r3
 *   @0x21d50c bne 0x21d5d8 <_Z21Audio_PlayInSyncGroupii+0x1a4>
 *   @0x21d510 add sp, sp, #1040
 *   @0x21d514 add sp, sp, #8
 *   @0x21d518 pop {r4, r5, r6, r7, r8, pc}
 *   @0x21d51c ldrb r3, [r5, #0x25]
 *   @0x21d520 cmp r3, #0
 *   @0x21d524 bne 0x21d4b0 <_Z21Audio_PlayInSyncGroupii+0x7c>
 *   @0x21d528 ldr r1, [pc, #0xcc]
 *   @0x21d52c ldr r3, [pc, #0xbc]
 *   @0x21d530 add r1, pc, r1
 *   @0x21d534 ldr r3, [r4, r3]
 *   @0x21d538 ldr r0, [r3]
 *   @0x21d53c ldr r3, [r0]
 *   @0x21d540 ldr r3, [r3, #0xc]
 *   @0x21d544 blx r3
 *   @0x21d548 mvn r0, #0
 *   @0x21d54c b 0x21d500 <_Z21Audio_PlayInSyncGroupii+0xcc>
 *   @0x21d550 mvn r0, #0
 *   @0x21d554 b 0x21d500 <_Z21Audio_PlayInSyncGroupii+0xcc>
 *   @0x21d558 add r4, sp, #20
 *   @0x21d55c mov r1, #1024
 *   @0x21d560 ldr r2, [r5]
 *   @0x21d564 mov r0, r4
 *   @0x21d568 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x21d56c mov r0, r4
 *   @0x21d570 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x21d574 cmp r0, #0
 *   @0x21d578 beq 0x21d4d4 <_Z21Audio_PlayInSyncGroupii+0xa0>
 *   @0x21d57c ldr r0, [r5, #0x30]
 *   @0x21d580 cmp r0, #0
 *   @0x21d584 beq 0x21d58c <_Z21Audio_PlayInSyncGroupii+0x158>
 *   @0x21d588 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x21d58c mov r0, r4
 *   @0x21d590 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x21d594 str r0, [r5, #0x30]
 *   @0x21d598 b 0x21d4d4 <_Z21Audio_PlayInSyncGroupii+0xa0>
 *   @0x21d59c ldr r3, [pc, #0x4c]
 *   @0x21d5a0 mov r0, r7
 *   @0x21d5a4 ldr r3, [r4, r3]
 *   @0x21d5a8 ldr r4, [r3]
 *   @0x21d5ac ldr r3, [r4]
 *   @0x21d5b0 ldr r7, [r3, #0xc]
 *   @0x21d5b4 bl 0x218348 <_Z13Audio_GetNamei>
 *   @0x21d5b8 ldr r1, [pc, #0x40]
 *   @0x21d5bc ldr r3, [r5, #0x4c]
 *   @0x21d5c0 add r1, pc, r1
 *   @0x21d5c4 mov r2, r0
 *   @0x21d5c8 mov r0, r4
 *   @0x21d5cc blx r7
 *   @0x21d5d0 mvn r0, #0
 *   @0x21d5d4 b 0x21d500 <_Z21Audio_PlayInSyncGroupii+0xcc>
 *   @0x21d5d8 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x21d5dc andseq r4, sp, r4, lsl #16
 *   @0x21d5e0 .word 0xffffbd00
 *   @0x21d5e4 .word 0xffffd3fc
 *   @0x21d5e8 .word 0xffffd0e0
 *   @0x21d5ec mulseq r3, r4, r11
 *   @0x21d5f0 .word 0xffffbac4
 *   @0x21d5f4 .word 0xffffd400
 *   @0x21d5f8 subseq r7, r3, r4, lsr #27
 *   @0x21d5fc andseq r7, r3, r4, rrx
 *   @0x21d600 mulseq r3, r4, r10
 *
 * ══ §42/42 CBackground::~CBackground()  0xc2d48  size 20  5 条（0xc2d48..0xc2d5c）
 * @func 0xc2d48 0xc2d5c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBackground::Clear()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc2d48 push {r4, lr}
 *   @0xc2d4c mov r4, r0
 *   @0xc2d50 bl 0xc23c0 <_ZN11CBackground5ClearEv>
 *   @0xc2d54 mov r0, r4
 *   @0xc2d58 pop {r4, pc}
 */
