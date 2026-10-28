/* libyoyo.so 覆盖卡组 0268
 * 函数 0x2c5144..0x2c674c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2c5144 · b2EdgeShape::GetChildCount() const · size=8 · insn=2 */
/* @0x2c5144 mov r0, #1 */
/* @0x2c5148 bx lr */

/* ── FUNC 0x2c514c · b2EdgeShape::TestPoint(b2Transform const&, b2Vec2 const&) const · size=8 · insn=2 */
/* @0x2c514c mov r0, #0 */
/* @0x2c5150 bx lr */

/* ── FUNC 0x2c5154 · b2EdgeShape::ComputeAABB(b2AABB*, b2Transform const&, int) const · size=176 · insn=44 */
/* @0x2c5154 vldr s10, [r2, #8] */
/* @0x2c5158 vldr s13, [r0, #16] */
/* @0x2c515c vldr s14, [r0, #24] */
/* @0x2c5160 vmul.f32 s11, s10, s13 */
/* @0x2c5164 vldr s9, [r2, #12] */
/* @0x2c5168 vldr s5, [r0, #12] */
/* @0x2c516c vldr s6, [r0, #20] */
/* @0x2c5170 vldr s12, [r2] */
/* @0x2c5174 vldr s7, [r2, #4] */
/* @0x2c5178 vldr s15, [r0, #8] */
/* @0x2c517c vmul.f32 s8, s10, s14 */
/* @0x2c5180 vmul.f32 s13, s9, s13 */
/* @0x2c5184 vmul.f32 s14, s9, s14 */
/* @0x2c5188 vnmls.f32 s11, s9, s5 */
/* @0x2c518c vnmls.f32 s8, s9, s6 */
/* @0x2c5190 vmla.f32 s13, s5, s10 */
/* @0x2c5194 vmla.f32 s14, s10, s6 */
/* @0x2c5198 vadd.f32 s11, s11, s12 */
/* @0x2c519c vadd.f32 s12, s12, s8 */
/* @0x2c51a0 vadd.f32 s13, s13, s7 */
/* @0x2c51a4 vadd.f32 s14, s7, s14 */
/* @0x2c51a8 vcmpe.f32 s11, s12 */
/* @0x2c51ac vmrs APSR_nzcv, fpscr */
/* @0x2c51b0 vcmpe.f32 s13, s14 */
/* @0x2c51b4 vmovpl.f32 s9, s12 */
/* @0x2c51b8 vmovmi.f32 s9, s11 */
/* @0x2c51bc vmrs APSR_nzcv, fpscr */
/* @0x2c51c0 vcmpe.f32 s11, s12 */
/* @0x2c51c4 vmovpl.f32 s10, s14 */
/* @0x2c51c8 vmovmi.f32 s10, s13 */
/* @0x2c51cc vmrs APSR_nzcv, fpscr */
/* @0x2c51d0 vcmpe.f32 s13, s14 */
/* @0x2c51d4 vmovgt.f32 s12, s11 */
/* @0x2c51d8 vmrs APSR_nzcv, fpscr */
/* @0x2c51dc vmovgt.f32 s14, s13 */
/* @0x2c51e0 vsub.f32 s11, s9, s15 */
/* @0x2c51e4 vsub.f32 s13, s10, s15 */
/* @0x2c51e8 vstr s11, [r1] */
/* @0x2c51ec vadd.f32 s12, s15, s12 */
/* @0x2c51f0 vstr s13, [r1, #4] */
/* @0x2c51f4 vadd.f32 s15, s15, s14 */
/* @0x2c51f8 vstr s12, [r1, #8] */
/* @0x2c51fc vstr s15, [r1, #12] */
/* @0x2c5200 bx lr */

/* ── FUNC 0x2c5204 · b2EdgeShape::ComputeMass(b2MassData*, float) const · size=60 · insn=15 */
/* @0x2c5204 vldr s11, [r0, #16] */
/* @0x2c5208 vldr s14, [r0, #24] */
/* @0x2c520c vldr s12, [r0, #12] */
/* @0x2c5210 vldr s13, [r0, #20] */
/* @0x2c5214 vmov.f32 s15, #5.000000e-01 */
/* @0x2c5218 mov r3, #0 */
/* @0x2c521c str r3, [r1] */
/* @0x2c5220 str r3, [r1, #0xc] */
/* @0x2c5224 vadd.f32 s14, s11, s14 */
/* @0x2c5228 vadd.f32 s13, s12, s13 */
/* @0x2c522c vmul.f32 s14, s14, s15 */
/* @0x2c5230 vmul.f32 s15, s13, s15 */
/* @0x2c5234 vstr s14, [r1, #8] */
/* @0x2c5238 vstr s15, [r1, #4] */
/* @0x2c523c bx lr */

/* ── FUNC 0x2c5240 · b2EdgeShape::~b2EdgeShape() · size=24 · insn=6 */
/* @0x2c5240 ldr r3, [pc, #0xc] */
/* @0x2c5244 ldr r3, [pc, r3] */
/* @0x2c5248 add r3, r3, #8 */
/* @0x2c524c str r3, [r0] */
/* @0x2c5250 bx lr */
/* @0x2c5254 andseq r12, r2, r12, asr r2 */

/* ── FUNC 0x2c5240 · b2EdgeShape::~b2EdgeShape() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2c5258 · b2EdgeShape::~b2EdgeShape() · size=40 · insn=10 */
/* @0x2c5258 ldr r3, [pc, #0x1c] */
/* @0x2c525c push {r4, lr} */
/* @0x2c5260 ldr r3, [pc, r3] */
/* @0x2c5264 mov r4, r0 */
/* @0x2c5268 add r3, r3, #8 */
/* @0x2c526c str r3, [r0] */
/* @0x2c5270 bl 0x27d1d0 <_ZdlPv> */
/* @0x2c5274 mov r0, r4 */
/* @0x2c5278 pop {r4, pc} */
/* @0x2c527c andseq r12, r2, r0, asr #4 */

/* ── FUNC 0x2c5280 · b2EdgeShape::Clone(b2BlockAllocator*) const · size=204 · insn=51 */
/* @0x2c5280 push {r4, r5, r6, r7, r8, lr} */
/* @0x2c5284 mov r4, r0 */
/* @0x2c5288 mov r0, r1 */
/* @0x2c528c mov r1, #48 */
/* @0x2c5290 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2c5294 subs r3, r0, #0 */
/* @0x2c5298 beq 0x2c52e0 <_ZNK11b2EdgeShape5CloneEP16b2BlockAllocator+0x60> */
/* @0x2c529c ldr r2, [pc, #0xa4] */
/* @0x2c52a0 mov r1, #1 */
/* @0x2c52a4 movw r0, #0xd70a */
/* @0x2c52a8 str r1, [r3, #0x4] */
/* @0x2c52ac ldr r2, [pc, r2] */
/* @0x2c52b0 movt r0, #0x3c23 */
/* @0x2c52b4 add r1, r2, #8 */
/* @0x2c52b8 str r0, [r3, #0x8] */
/* @0x2c52bc mov r2, #0 */
/* @0x2c52c0 str r1, [r3] */
/* @0x2c52c4 str r2, [r3, #0x1c] */
/* @0x2c52c8 str r2, [r3, #0x20] */
/* @0x2c52cc str r2, [r3, #0x24] */
/* @0x2c52d0 str r2, [r3, #0x28] */
/* @0x2c52d4 mov r2, #0 */
/* @0x2c52d8 strb r2, [r3, #0x2c] */
/* @0x2c52dc strb r2, [r3, #0x2d] */
/* @0x2c52e0 add r1, r4, #12 */
/* @0x2c52e4 ldr r5, [r4, #0x4] */
/* @0x2c52e8 ldr r6, [r4, #0x8] */
/* @0x2c52ec add r12, r3, #12 */
/* @0x2c52f0 ldm r1, {r0, r1} */
/* @0x2c52f4 add r2, r4, #20 */
/* @0x2c52f8 str r5, [r3, #0x4] */
/* @0x2c52fc add r7, r3, #20 */
/* @0x2c5300 str r6, [r3, #0x8] */
/* @0x2c5304 add r6, r4, #28 */
/* @0x2c5308 stm r12, {r0, r1} */
/* @0x2c530c add r12, r4, #36 */
/* @0x2c5310 ldm r2, {r0, r1} */
/* @0x2c5314 add r5, r3, #28 */
/* @0x2c5318 ldrb r8, [r4, #0x2c] */
/* @0x2c531c add r2, r3, #36 */
/* @0x2c5320 ldrb r4, [r4, #0x2d] */
/* @0x2c5324 stm r7, {r0, r1} */
/* @0x2c5328 ldm r6, {r0, r1} */
/* @0x2c532c stm r5, {r0, r1} */
/* @0x2c5330 ldm r12, {r0, r1} */
/* @0x2c5334 stm r2, {r0, r1} */
/* @0x2c5338 mov r0, r3 */
/* @0x2c533c strb r8, [r3, #0x2c] */
/* @0x2c5340 strb r4, [r3, #0x2d] */
/* @0x2c5344 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2c5348 andseq r12, r2, r8, lsl #4 */

/* ── FUNC 0x2c534c · b2EdgeShape::RayCast(b2RayCastOutput*, b2RayCastInput const&, b2Transform const&, int) const · size=432 · insn=108 */
/* @0x2c534c str lr, [sp, #-0x4]! */
/* @0x2c5350 vpush {d8, d9, d10, d11, d12} */
/* @0x2c5354 vldr s21, [r0, #16] */
/* @0x2c5358 vldr s19, [r0, #24] */
/* @0x2c535c vsub.f32 s19, s19, s21 */
/* @0x2c5360 vldr s20, [r0, #12] */
/* @0x2c5364 vldr s22, [r0, #20] */
/* @0x2c5368 vldr s14, [r3, #4] */
/* @0x2c536c vldr s18, [r2, #4] */
/* @0x2c5370 vldr s13, [r2, #12] */
/* @0x2c5374 vldr s15, [r3, #12] */
/* @0x2c5378 vldr s11, [r3, #8] */
/* @0x2c537c vldr s10, [r3] */
/* @0x2c5380 vldr s9, [r2] */
/* @0x2c5384 vldr s7, [r2, #8] */
/* @0x2c5388 sub sp, sp, #12 */
/* @0x2c538c vmul.f32 s23, s19, s19 */
/* @0x2c5390 vsub.f32 s22, s22, s20 */
/* @0x2c5394 vmov.f32 s8, s23 */
/* @0x2c5398 vneg.f32 s16, s22 */
/* @0x2c539c vmla.f32 s8, s16, s16 */
/* @0x2c53a0 vsub.f32 s18, s18, s14 */
/* @0x2c53a4 vsub.f32 s13, s13, s14 */
/* @0x2c53a8 vsqrt.f32 s14, s8 */
/* @0x2c53ac vmul.f32 s17, s18, s11 */
/* @0x2c53b0 vmul.f32 s12, s11, s13 */
/* @0x2c53b4 vmul.f32 s18, s18, s15 */
/* @0x2c53b8 vmul.f32 s13, s15, s13 */
/* @0x2c53bc vsub.f32 s9, s9, s10 */
/* @0x2c53c0 vsub.f32 s10, s7, s10 */
/* @0x2c53c4 vneg.f32 s11, s11 */
/* @0x2c53c8 vmla.f32 s17, s9, s15 */
/* @0x2c53cc vmla.f32 s18, s9, s11 */
/* @0x2c53d0 vmla.f32 s12, s15, s10 */
/* @0x2c53d4 vmla.f32 s13, s11, s10 */
/* @0x2c53d8 vcmp.f32 s14, s14 */
/* @0x2c53dc vsub.f32 s24, s12, s17 */
/* @0x2c53e0 vmrs APSR_nzcv, fpscr */
/* @0x2c53e4 vsub.f32 s25, s13, s18 */
/* @0x2c53e8 bne 0x2c54d8 <_ZNK11b2EdgeShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x18c> */
/* @0x2c53ec vldr s15, [pc, #260] */
/* @0x2c53f0 vcmpe.f32 s14, s15 */
/* @0x2c53f4 vmrs APSR_nzcv, fpscr */
/* @0x2c53f8 vmovpl.f32 s15, #1.000000e+00 */
/* @0x2c53fc vdivpl.f32 s14, s15, s14 */
/* @0x2c5400 vmulpl.f32 s16, s16, s14 */
/* @0x2c5404 vmulpl.f32 s14, s19, s14 */
/* @0x2c5408 vmul.f32 s15, s16, s25 */
/* @0x2c540c vmovmi.f32 s14, s19 */
/* @0x2c5410 vmla.f32 s15, s14, s24 */
/* @0x2c5414 vcmp.f32 s15, #0 */
/* @0x2c5418 vmrs APSR_nzcv, fpscr */
/* @0x2c541c beq 0x2c54c8 <_ZNK11b2EdgeShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x17c> */
/* @0x2c5420 vsub.f32 s11, s21, s18 */
/* @0x2c5424 vmul.f32 s11, s16, s11 */
/* @0x2c5428 vsub.f32 s13, s20, s17 */
/* @0x2c542c vmla.f32 s11, s14, s13 */
/* @0x2c5430 vdiv.f32 s15, s11, s15 */
/* @0x2c5434 vcmpe.f32 s15, #0 */
/* @0x2c5438 vmrs APSR_nzcv, fpscr */
/* @0x2c543c bmi 0x2c54c8 <_ZNK11b2EdgeShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x17c> */
/* @0x2c5440 vldr s13, [r2, #16] */
/* @0x2c5444 vcmpe.f32 s15, s13 */
/* @0x2c5448 vmrs APSR_nzcv, fpscr */
/* @0x2c544c bgt 0x2c54c8 <_ZNK11b2EdgeShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x17c> */
/* @0x2c5450 vmla.f32 s23, s22, s22 */
/* @0x2c5454 vcmp.f32 s23, #0 */
/* @0x2c5458 vmrs APSR_nzcv, fpscr */
/* @0x2c545c beq 0x2c54c8 <_ZNK11b2EdgeShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x17c> */
/* @0x2c5460 vmla.f32 s18, s15, s25 */
/* @0x2c5464 vmla.f32 s17, s15, s24 */
/* @0x2c5468 vsub.f32 s21, s18, s21 */
/* @0x2c546c vmul.f32 s19, s19, s21 */
/* @0x2c5470 vsub.f32 s20, s17, s20 */
/* @0x2c5474 vmla.f32 s19, s22, s20 */
/* @0x2c5478 vdiv.f32 s23, s19, s23 */
/* @0x2c547c vcmpe.f32 s23, #0 */
/* @0x2c5480 vmrs APSR_nzcv, fpscr */
/* @0x2c5484 bmi 0x2c54c8 <_ZNK11b2EdgeShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x17c> */
/* @0x2c5488 vmov.f32 s13, #1.000000e+00 */
/* @0x2c548c vcmpe.f32 s23, s13 */
/* @0x2c5490 vmrs APSR_nzcv, fpscr */
/* @0x2c5494 bgt 0x2c54c8 <_ZNK11b2EdgeShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x17c> */
/* @0x2c5498 vcmpe.f32 s11, #0 */
/* @0x2c549c vstr s15, [r1, #8] */
/* @0x2c54a0 vmrs APSR_nzcv, fpscr */
/* @0x2c54a4 vneggt.f32 s14, s14 */
/* @0x2c54a8 movgt r0, #1 */
/* @0x2c54ac vstrle s14, [r1] */
/* @0x2c54b0 vstrle s16, [r1, #4] */
/* @0x2c54b4 movle r0, #1 */
/* @0x2c54b8 vneggt.f32 s16, s16 */
/* @0x2c54bc vstrgt s14, [r1] */
/* @0x2c54c0 vstrgt s16, [r1, #4] */
/* @0x2c54c4 b 0x2c54cc <_ZNK11b2EdgeShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x180> */
/* @0x2c54c8 mov r0, #0 */
/* @0x2c54cc add sp, sp, #12 */
/* @0x2c54d0 vpop {d8, d9, d10, d11, d12} */
/* @0x2c54d4 ldr pc, [sp], #4 */
/* @0x2c54d8 vmov r0, s8 */
/* @0x2c54dc str r1, [sp, #0x4] */
/* @0x2c54e0 str r2, [sp] */
/* @0x2c54e4 bl 0xb6700 <sqrtf@plt> */
/* @0x2c54e8 ldr r2, [sp] */
/* @0x2c54ec ldr r1, [sp, #0x4] */
/* @0x2c54f0 vmov s14, r0 */
/* @0x2c54f4 b 0x2c53ec <_ZNK11b2EdgeShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0xa0> */
/* @0x2c54f8 strlo r0, [r0], #-0 */

/* ── FUNC 0x2c54fc · b2EdgeShape::ComputeDistance(b2Transform const&, b2Vec2 const&, float*, b2Vec2*, int) const · size=308 · insn=77 */
/* @0x2c54fc vldr s15, [r1, #12] */
/* @0x2c5500 vldr s12, [r0, #16] */
/* @0x2c5504 vldr s13, [r0, #24] */
/* @0x2c5508 vmul.f32 s10, s15, s12 */
/* @0x2c550c vldr s14, [r1, #8] */
/* @0x2c5510 vldr s6, [r0, #12] */
/* @0x2c5514 vldr s7, [r0, #20] */
/* @0x2c5518 vldr s8, [r1, #4] */
/* @0x2c551c push {r4, lr} */
/* @0x2c5520 vldr s5, [r2, #4] */
/* @0x2c5524 vpush {d8} */
/* @0x2c5528 vldr s9, [r1] */
/* @0x2c552c vldr s4, [r2] */
/* @0x2c5530 sub sp, sp, #8 */
/* @0x2c5534 ldr r4, [sp, #0x18] */
/* @0x2c5538 vmul.f32 s11, s15, s13 */
/* @0x2c553c vmla.f32 s10, s6, s14 */
/* @0x2c5540 vmul.f32 s12, s14, s12 */
/* @0x2c5544 vmul.f32 s13, s14, s13 */
/* @0x2c5548 vmla.f32 s11, s14, s7 */
/* @0x2c554c vnmls.f32 s12, s15, s6 */
/* @0x2c5550 vnmls.f32 s13, s15, s7 */
/* @0x2c5554 vadd.f32 s10, s10, s8 */
/* @0x2c5558 vadd.f32 s11, s8, s11 */
/* @0x2c555c vsub.f32 s16, s5, s10 */
/* @0x2c5560 vsub.f32 s10, s11, s10 */
/* @0x2c5564 vadd.f32 s12, s12, s9 */
/* @0x2c5568 vadd.f32 s13, s9, s13 */
/* @0x2c556c vmul.f32 s15, s16, s10 */
/* @0x2c5570 vsub.f32 s17, s4, s12 */
/* @0x2c5574 vsub.f32 s12, s13, s12 */
/* @0x2c5578 vmla.f32 s15, s17, s12 */
/* @0x2c557c vcmpe.f32 s15, #0 */
/* @0x2c5580 vmrs APSR_nzcv, fpscr */
/* @0x2c5584 ble 0x2c55ac <_ZNK11b2EdgeShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0xb0> */
/* @0x2c5588 vmul.f32 s14, s10, s10 */
/* @0x2c558c vmla.f32 s14, s12, s12 */
/* @0x2c5590 vcmpe.f32 s15, s14 */
/* @0x2c5594 vmrs APSR_nzcv, fpscr */
/* @0x2c5598 vdivle.f32 s15, s15, s14 */
/* @0x2c559c vmlsle.f32 s17, s15, s12 */
/* @0x2c55a0 vmlsle.f32 s16, s15, s10 */
/* @0x2c55a4 vsubgt.f32 s17, s4, s13 */
/* @0x2c55a8 vsubgt.f32 s16, s5, s11 */
/* @0x2c55ac vmul.f32 s14, s16, s16 */
/* @0x2c55b0 vmla.f32 s14, s17, s17 */
/* @0x2c55b4 vsqrt.f32 s15, s14 */
/* @0x2c55b8 vcmp.f32 s15, s15 */
/* @0x2c55bc vmrs APSR_nzcv, fpscr */
/* @0x2c55c0 bne 0x2c5614 <_ZNK11b2EdgeShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0x118> */
/* @0x2c55c4 vcmpe.f32 s15, #0 */
/* @0x2c55c8 vstr s15, [r3] */
/* @0x2c55cc vmrs APSR_nzcv, fpscr */
/* @0x2c55d0 ble 0x2c55f8 <_ZNK11b2EdgeShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0xfc> */
/* @0x2c55d4 vmov.f32 s14, #1.000000e+00 */
/* @0x2c55d8 vdiv.f32 s15, s14, s15 */
/* @0x2c55dc vmul.f32 s17, s15, s17 */
/* @0x2c55e0 vmul.f32 s15, s15, s16 */
/* @0x2c55e4 vstr s17, [r4] */
/* @0x2c55e8 vstr s15, [r4, #4] */
/* @0x2c55ec add sp, sp, #8 */
/* @0x2c55f0 vpop {d8} */
/* @0x2c55f4 pop {r4, pc} */
/* @0x2c55f8 ldr r3, [pc, #0x2c] */
/* @0x2c55fc ldr r3, [pc, r3] */
/* @0x2c5600 ldm r3, {r0, r1} */
/* @0x2c5604 stm r4, {r0, r1} */
/* @0x2c5608 add sp, sp, #8 */
/* @0x2c560c vpop {d8} */
/* @0x2c5610 pop {r4, pc} */
/* @0x2c5614 vmov r0, s14 */
/* @0x2c5618 str r3, [sp, #0x4] */
/* @0x2c561c bl 0xb6700 <sqrtf@plt> */
/* @0x2c5620 ldr r3, [sp, #0x4] */
/* @0x2c5624 vmov s15, r0 */
/* @0x2c5628 b 0x2c55c4 <_ZNK11b2EdgeShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0xc8> */
/* @0x2c562c ldrsbeq r11, [r2], -r12 */

/* ── FUNC 0x2c5630 · b2EdgeShape::Set(b2Vec2 const&, b2Vec2 const&) · size=52 · insn=13 */
/* @0x2c5630 mov r3, r0 */
/* @0x2c5634 ldm r1, {r0, r1} */
/* @0x2c5638 push {r4, r5} */
/* @0x2c563c add r5, r3, #12 */
/* @0x2c5640 add r4, r3, #20 */
/* @0x2c5644 mov r12, #0 */
/* @0x2c5648 stm r5, {r0, r1} */
/* @0x2c564c ldm r2, {r0, r1} */
/* @0x2c5650 stm r4, {r0, r1} */
/* @0x2c5654 strb r12, [r3, #0x2c] */
/* @0x2c5658 strb r12, [r3, #0x2d] */
/* @0x2c565c pop {r4, r5} */
/* @0x2c5660 bx lr */

/* ── FUNC 0x2c5664 · b2PolygonShape::GetChildCount() const · size=8 · insn=2 */
/* @0x2c5664 mov r0, #1 */
/* @0x2c5668 bx lr */

/* ── FUNC 0x2c566c · b2PolygonShape::TestPoint(b2Transform const&, b2Vec2 const&) const · size=196 · insn=49 */
/* @0x2c566c vldr s15, [r1, #4] */
/* @0x2c5670 vldr s10, [r2, #4] */
/* @0x2c5674 vsub.f32 s10, s10, s15 */
/* @0x2c5678 vldr s13, [r1, #8] */
/* @0x2c567c vldr s15, [r1, #12] */
/* @0x2c5680 vldr s14, [r1] */
/* @0x2c5684 vldr s12, [r2] */
/* @0x2c5688 ldr r1, [r0, #0x94] */
/* @0x2c568c cmp r1, #0 */
/* @0x2c5690 vmul.f32 s11, s10, s13 */
/* @0x2c5694 vmul.f32 s10, s10, s15 */
/* @0x2c5698 vsub.f32 s14, s12, s14 */
/* @0x2c569c vmls.f32 s10, s13, s14 */
/* @0x2c56a0 vmla.f32 s11, s14, s15 */
/* @0x2c56a4 ble 0x2c5720 <_ZNK14b2PolygonShape9TestPointERK11b2TransformRK6b2Vec2+0xb4> */
/* @0x2c56a8 vldr s15, [r0, #24] */
/* @0x2c56ac vldr s12, [r0, #88] */
/* @0x2c56b0 vldr s13, [r0, #20] */
/* @0x2c56b4 vldr s14, [r0, #84] */
/* @0x2c56b8 vsub.f32 s15, s10, s15 */
/* @0x2c56bc vmul.f32 s15, s15, s12 */
/* @0x2c56c0 vsub.f32 s13, s11, s13 */
/* @0x2c56c4 vmla.f32 s15, s13, s14 */
/* @0x2c56c8 vcmpe.f32 s15, #0 */
/* @0x2c56cc vmrs APSR_nzcv, fpscr */
/* @0x2c56d0 bgt 0x2c5728 <_ZNK14b2PolygonShape9TestPointERK11b2TransformRK6b2Vec2+0xbc> */
/* @0x2c56d4 add r0, r0, #92 */
/* @0x2c56d8 mov r2, #0 */
/* @0x2c56dc b 0x2c570c <_ZNK14b2PolygonShape9TestPointERK11b2TransformRK6b2Vec2+0xa0> */
/* @0x2c56e0 vldr s15, [r3, #-60] */
/* @0x2c56e4 vsub.f32 s15, s10, s15 */
/* @0x2c56e8 vldr s12, [r3, #4] */
/* @0x2c56ec vldr s13, [r3, #-64] */
/* @0x2c56f0 vldr s14, [r3] */
/* @0x2c56f4 vmul.f32 s15, s15, s12 */
/* @0x2c56f8 vsub.f32 s13, s11, s13 */
/* @0x2c56fc vmla.f32 s15, s13, s14 */
/* @0x2c5700 vcmpe.f32 s15, #0 */
/* @0x2c5704 vmrs APSR_nzcv, fpscr */
/* @0x2c5708 bgt 0x2c5728 <_ZNK14b2PolygonShape9TestPointERK11b2TransformRK6b2Vec2+0xbc> */
/* @0x2c570c add r2, r2, #1 */
/* @0x2c5710 mov r3, r0 */
/* @0x2c5714 cmp r2, r1 */
/* @0x2c5718 add r0, r0, #8 */
/* @0x2c571c bne 0x2c56e0 <_ZNK14b2PolygonShape9TestPointERK11b2TransformRK6b2Vec2+0x74> */
/* @0x2c5720 mov r0, #1 */
/* @0x2c5724 bx lr */
/* @0x2c5728 mov r0, #0 */
/* @0x2c572c bx lr */

/* ── FUNC 0x2c5730 · b2PolygonShape::RayCast(b2RayCastOutput*, b2RayCastInput const&, b2Transform const&, int) const · size=384 · insn=96 */
/* @0x2c5730 vldr s14, [r3, #4] */
/* @0x2c5734 vldr s8, [r2, #4] */
/* @0x2c5738 vldr s6, [r2, #12] */
/* @0x2c573c vsub.f32 s8, s8, s14 */
/* @0x2c5740 vldr s4, [r3, #12] */
/* @0x2c5744 vldr s3, [r3, #8] */
/* @0x2c5748 vldr s15, [r3] */
/* @0x2c574c vldr s13, [r2] */
/* @0x2c5750 vldr s12, [r2, #8] */
/* @0x2c5754 ldr r12, [r0, #0x94] */
/* @0x2c5758 str r4, [sp, #-0x4]! */
/* @0x2c575c vldr s10, [r2, #16] */
/* @0x2c5760 cmp r12, #0 */
/* @0x2c5764 vsub.f32 s6, s6, s14 */
/* @0x2c5768 vmul.f32 s9, s8, s3 */
/* @0x2c576c vmul.f32 s5, s4, s6 */
/* @0x2c5770 vmul.f32 s8, s8, s4 */
/* @0x2c5774 vmul.f32 s6, s3, s6 */
/* @0x2c5778 vsub.f32 s13, s13, s15 */
/* @0x2c577c vsub.f32 s15, s12, s15 */
/* @0x2c5780 vneg.f32 s14, s3 */
/* @0x2c5784 vmla.f32 s9, s13, s4 */
/* @0x2c5788 vmla.f32 s8, s13, s14 */
/* @0x2c578c vmla.f32 s5, s14, s15 */
/* @0x2c5790 vmla.f32 s6, s4, s15 */
/* @0x2c5794 vsub.f32 s5, s5, s8 */
/* @0x2c5798 vsub.f32 s6, s6, s9 */
/* @0x2c579c ble 0x2c5858 <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x128> */
/* @0x2c57a0 add r3, r0, #84 */
/* @0x2c57a4 mov r2, #0 */
/* @0x2c57a8 mvn r4, #0 */
/* @0x2c57ac vldr s7, [pc, #248] */
/* @0x2c57b0 b 0x2c57dc <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0xac> */
/* @0x2c57b4 vcmpe.f32 s14, #0 */
/* @0x2c57b8 vmrs APSR_nzcv, fpscr */
/* @0x2c57bc bmi 0x2c5858 <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x128> */
/* @0x2c57c0 vcmpe.f32 s7, s10 */
/* @0x2c57c4 add r2, r2, #1 */
/* @0x2c57c8 add r3, r3, #8 */
/* @0x2c57cc vmrs APSR_nzcv, fpscr */
/* @0x2c57d0 bgt 0x2c5858 <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x128> */
/* @0x2c57d4 cmp r2, r12 */
/* @0x2c57d8 beq 0x2c5868 <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x138> */
/* @0x2c57dc vldr s12, [r3, #4] */
/* @0x2c57e0 vmul.f32 s15, s5, s12 */
/* @0x2c57e4 vldr s13, [r3] */
/* @0x2c57e8 vldr s14, [r3, #-60] */
/* @0x2c57ec vldr s11, [r3, #-64] */
/* @0x2c57f0 vmla.f32 s15, s6, s13 */
/* @0x2c57f4 vsub.f32 s14, s14, s8 */
/* @0x2c57f8 vmul.f32 s14, s14, s12 */
/* @0x2c57fc vsub.f32 s12, s11, s9 */
/* @0x2c5800 vcmp.f32 s15, #0 */
/* @0x2c5804 vmla.f32 s14, s12, s13 */
/* @0x2c5808 vmrs APSR_nzcv, fpscr */
/* @0x2c580c beq 0x2c57b4 <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x84> */
/* @0x2c5810 vcmpe.f32 s15, #0 */
/* @0x2c5814 vmrs APSR_nzcv, fpscr */
/* @0x2c5818 bmi 0x2c583c <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x10c> */
/* @0x2c581c vcmpe.f32 s15, #0 */
/* @0x2c5820 vmrs APSR_nzcv, fpscr */
/* @0x2c5824 ble 0x2c57c0 <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x90> */
/* @0x2c5828 vmul.f32 s13, s10, s15 */
/* @0x2c582c vcmpe.f32 s13, s14 */
/* @0x2c5830 vmrs APSR_nzcv, fpscr */
/* @0x2c5834 vdivgt.f32 s10, s14, s15 */
/* @0x2c5838 b 0x2c57c0 <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x90> */
/* @0x2c583c vmul.f32 s13, s7, s15 */
/* @0x2c5840 vcmpe.f32 s13, s14 */
/* @0x2c5844 vmrs APSR_nzcv, fpscr */
/* @0x2c5848 ble 0x2c581c <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0xec> */
/* @0x2c584c mov r4, r2 */
/* @0x2c5850 vdiv.f32 s7, s14, s15 */
/* @0x2c5854 b 0x2c57c0 <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x90> */
/* @0x2c5858 mov r3, #0 */
/* @0x2c585c ldr r4, [sp], #4 */
/* @0x2c5860 mov r0, r3 */
/* @0x2c5864 bx lr */
/* @0x2c5868 cmn r4, #1 */
/* @0x2c586c beq 0x2c5858 <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x128> */
/* @0x2c5870 add r4, r4, #10 */
/* @0x2c5874 mov r3, #1 */
/* @0x2c5878 vstr s7, [r1, #8] */
/* @0x2c587c add r0, r0, r4, lsl #3 */
/* @0x2c5880 vldr s15, [r0, #8] */
/* @0x2c5884 vmul.f32 s14, s3, s15 */
/* @0x2c5888 vldr s13, [r0, #4] */
/* @0x2c588c ldr r4, [sp], #4 */
/* @0x2c5890 mov r0, r3 */
/* @0x2c5894 vmul.f32 s15, s4, s15 */
/* @0x2c5898 vnmls.f32 s14, s4, s13 */
/* @0x2c589c vmla.f32 s15, s3, s13 */
/* @0x2c58a0 vstr s14, [r1] */
/* @0x2c58a4 vstr s15, [r1, #4] */
/* @0x2c58a8 bx lr */
/* @0x2c58ac andeq r0, r0, r0 */

/* ── FUNC 0x2c58b0 · b2PolygonShape::ComputeAABB(b2AABB*, b2Transform const&, int) const · size=224 · insn=56 */
/* @0x2c58b0 vldr s12, [r0, #24] */
/* @0x2c58b4 vldr s8, [r2, #12] */
/* @0x2c58b8 vldr s7, [r2, #8] */
/* @0x2c58bc vmul.f32 s13, s8, s12 */
/* @0x2c58c0 vldr s15, [r0, #20] */
/* @0x2c58c4 ldr r12, [r0, #0x94] */
/* @0x2c58c8 vldr s6, [r2] */
/* @0x2c58cc vldr s5, [r2, #4] */
/* @0x2c58d0 cmp r12, #1 */
/* @0x2c58d4 vmul.f32 s12, s7, s12 */
/* @0x2c58d8 vmla.f32 s13, s15, s7 */
/* @0x2c58dc vnmls.f32 s12, s8, s15 */
/* @0x2c58e0 vadd.f32 s13, s13, s5 */
/* @0x2c58e4 vadd.f32 s12, s12, s6 */
/* @0x2c58e8 ble 0x2c5984 <_ZNK14b2PolygonShape11ComputeAABBEP6b2AABBRK11b2Transformi+0xd4> */
/* @0x2c58ec add r3, r0, #28 */
/* @0x2c58f0 mov r2, #1 */
/* @0x2c58f4 vmov.f32 s10, s12 */
/* @0x2c58f8 vmov.f32 s11, s13 */
/* @0x2c58fc vldr s15, [r3, #4] */
/* @0x2c5900 vldr s9, [r3] */
/* @0x2c5904 add r2, r2, #1 */
/* @0x2c5908 add r3, r3, #8 */
/* @0x2c590c vmul.f32 s14, s7, s15 */
/* @0x2c5910 vmul.f32 s15, s8, s15 */
/* @0x2c5914 vnmls.f32 s14, s8, s9 */
/* @0x2c5918 vmla.f32 s15, s7, s9 */
/* @0x2c591c vadd.f32 s14, s6, s14 */
/* @0x2c5920 vadd.f32 s15, s5, s15 */
/* @0x2c5924 vcmpe.f32 s14, s12 */
/* @0x2c5928 vmrs APSR_nzcv, fpscr */
/* @0x2c592c vcmpe.f32 s15, s13 */
/* @0x2c5930 vmovle.f32 s12, s14 */
/* @0x2c5934 vmrs APSR_nzcv, fpscr */
/* @0x2c5938 vcmpe.f32 s14, s10 */
/* @0x2c593c vmovle.f32 s13, s15 */
/* @0x2c5940 vmrs APSR_nzcv, fpscr */
/* @0x2c5944 vcmpe.f32 s15, s11 */
/* @0x2c5948 vmovpl.f32 s10, s14 */
/* @0x2c594c vmrs APSR_nzcv, fpscr */
/* @0x2c5950 vmovpl.f32 s11, s15 */
/* @0x2c5954 cmp r2, r12 */
/* @0x2c5958 bne 0x2c58fc <_ZNK14b2PolygonShape11ComputeAABBEP6b2AABBRK11b2Transformi+0x4c> */
/* @0x2c595c vldr s15, [r0, #8] */
/* @0x2c5960 vsub.f32 s12, s12, s15 */
/* @0x2c5964 vsub.f32 s13, s13, s15 */
/* @0x2c5968 vstr s12, [r1] */
/* @0x2c596c vadd.f32 s10, s15, s10 */
/* @0x2c5970 vstr s13, [r1, #4] */
/* @0x2c5974 vadd.f32 s11, s15, s11 */
/* @0x2c5978 vstr s10, [r1, #8] */
/* @0x2c597c vstr s11, [r1, #12] */
/* @0x2c5980 bx lr */
/* @0x2c5984 vmov.f32 s10, s12 */
/* @0x2c5988 vmov.f32 s11, s13 */
/* @0x2c598c b 0x2c595c <_ZNK14b2PolygonShape11ComputeAABBEP6b2AABBRK11b2Transformi+0xac> */

/* ── FUNC 0x2c5990 · b2PolygonShape::ComputeMass(b2MassData*, float) const · size=512 · insn=128 */
/* @0x2c5990 push {r4, r5, r6, lr} */
/* @0x2c5994 vpush {d8, d9, d10, d11} */
/* @0x2c5998 mov r6, r0 */
/* @0x2c599c ldr r5, [pc, #0x1e0] */
/* @0x2c59a0 mov r4, r1 */
/* @0x2c59a4 ldr r0, [r0, #0x94] */
/* @0x2c59a8 vmov s21, r2 */
/* @0x2c59ac ldr r5, [pc, r5] */
/* @0x2c59b0 ldr r1, [pc, #0x1d0] */
/* @0x2c59b4 cmp r0, #2 */
/* @0x2c59b8 add r1, pc, r1 */
/* @0x2c59bc ldr r3, [r5] */
/* @0x2c59c0 movle r0, #0 */
/* @0x2c59c4 movgt r0, #1 */
/* @0x2c59c8 blx r3 */
/* @0x2c59cc ldr r12, [r6, #0x94] */
/* @0x2c59d0 cmp r12, #0 */
/* @0x2c59d4 ble 0x2c5b40 <_ZNK14b2PolygonShape11ComputeMassEP10b2MassDataf+0x1b0> */
/* @0x2c59d8 vldr s15, [pc, #404] */
/* @0x2c59dc vmov.f32 s14, s15 */
/* @0x2c59e0 add r3, r6, #20 */
/* @0x2c59e4 mov r2, #0 */
/* @0x2c59e8 add r2, r2, #1 */
/* @0x2c59ec vldr s13, [r3] */
/* @0x2c59f0 cmp r2, r12 */
/* @0x2c59f4 vadd.f32 s15, s15, s13 */
/* @0x2c59f8 add r3, r3, #8 */
/* @0x2c59fc vldr s13, [r3, #-4] */
/* @0x2c5a00 vadd.f32 s14, s14, s13 */
/* @0x2c5a04 bne 0x2c59e8 <_ZNK14b2PolygonShape11ComputeMassEP10b2MassDataf+0x58> */
/* @0x2c5a08 vmov.f32 s22, #1.000000e+00 */
/* @0x2c5a0c vldr s16, [pc, #352] */
/* @0x2c5a10 vmov s12, r12 */
/* @0x2c5a14 add r3, r6, #28 */
/* @0x2c5a18 mov r2, #0 */
/* @0x2c5a1c vldr s4, [pc, #340] */
/* @0x2c5a20 vldr s5, [pc, #340] */
/* @0x2c5a24 vcvt.f32.s32 s13, s12 */
/* @0x2c5a28 vdiv.f32 s22, s22, s13 */
/* @0x2c5a2c vmul.f32 s18, s22, s15 */
/* @0x2c5a30 vmul.f32 s22, s22, s14 */
/* @0x2c5a34 vmov.f32 s6, #5.000000e-01 */
/* @0x2c5a38 vmov.f32 s20, s16 */
/* @0x2c5a3c vmov.f32 s19, s16 */
/* @0x2c5a40 vmov.f32 s17, s16 */
/* @0x2c5a44 add r2, r2, #1 */
/* @0x2c5a48 vldr s12, [r3, #-8] */
/* @0x2c5a4c cmp r2, r12 */
/* @0x2c5a50 vldr s14, [r3, #-4] */
/* @0x2c5a54 vsub.f32 s12, s12, s18 */
/* @0x2c5a58 vldrlt s13, [r3] */
/* @0x2c5a5c vldrlt s15, [r3, #4] */
/* @0x2c5a60 vldrge s13, [r6, #20] */
/* @0x2c5a64 vldrge s15, [r6, #24] */
/* @0x2c5a68 cmp r2, r12 */
/* @0x2c5a6c add r3, r3, #8 */
/* @0x2c5a70 vsub.f32 s14, s14, s22 */
/* @0x2c5a74 vsub.f32 s13, s13, s18 */
/* @0x2c5a78 vsub.f32 s15, s15, s22 */
/* @0x2c5a7c vmul.f32 s10, s12, s13 */
/* @0x2c5a80 vmul.f32 s11, s14, s15 */
/* @0x2c5a84 vmul.f32 s9, s14, s13 */
/* @0x2c5a88 vmla.f32 s10, s12, s12 */
/* @0x2c5a8c vmla.f32 s11, s14, s14 */
/* @0x2c5a90 vnmls.f32 s9, s12, s15 */
/* @0x2c5a94 vmla.f32 s10, s13, s13 */
/* @0x2c5a98 vmla.f32 s11, s15, s15 */
/* @0x2c5a9c vmul.f32 s7, s9, s6 */
/* @0x2c5aa0 vmul.f32 s9, s9, s5 */
/* @0x2c5aa4 vmul.f32 s8, s7, s4 */
/* @0x2c5aa8 vadd.f32 s11, s10, s11 */
/* @0x2c5aac vadd.f32 s13, s12, s13 */
/* @0x2c5ab0 vadd.f32 s15, s14, s15 */
/* @0x2c5ab4 vmla.f32 s19, s9, s11 */
/* @0x2c5ab8 vadd.f32 s17, s17, s7 */
/* @0x2c5abc vmla.f32 s16, s8, s13 */
/* @0x2c5ac0 vmla.f32 s20, s8, s15 */
/* @0x2c5ac4 bne 0x2c5a44 <_ZNK14b2PolygonShape11ComputeMassEP10b2MassDataf+0xb4> */
/* @0x2c5ac8 vldr s15, [pc, #176] */
/* @0x2c5acc vcmpe.f32 s17, s15 */
/* @0x2c5ad0 vmrs APSR_nzcv, fpscr */
/* @0x2c5ad4 movle r0, #0 */
/* @0x2c5ad8 movgt r0, #1 */
/* @0x2c5adc vmul.f32 s15, s21, s17 */
/* @0x2c5ae0 ldr r1, [pc, #0xa4] */
/* @0x2c5ae4 ldr r3, [r5] */
/* @0x2c5ae8 add r1, pc, r1 */
/* @0x2c5aec vstr s15, [r4] */
/* @0x2c5af0 blx r3 */
/* @0x2c5af4 vmov.f32 s15, #1.000000e+00 */
/* @0x2c5af8 vldr s14, [r4] */
/* @0x2c5afc vdiv.f32 s17, s15, s17 */
/* @0x2c5b00 vmul.f32 s20, s17, s20 */
/* @0x2c5b04 vmul.f32 s16, s17, s16 */
/* @0x2c5b08 vadd.f32 s22, s22, s20 */
/* @0x2c5b0c vmul.f32 s20, s20, s20 */
/* @0x2c5b10 vstr s22, [r4, #8] */
/* @0x2c5b14 vmul.f32 s22, s22, s22 */
/* @0x2c5b18 vadd.f32 s18, s18, s16 */
/* @0x2c5b1c vmla.f32 s20, s16, s16 */
/* @0x2c5b20 vstr s18, [r4, #4] */
/* @0x2c5b24 vmla.f32 s22, s18, s18 */
/* @0x2c5b28 vsub.f32 s15, s22, s20 */
/* @0x2c5b2c vmul.f32 s15, s15, s14 */
/* @0x2c5b30 vmla.f32 s15, s21, s19 */
/* @0x2c5b34 vpop {d8, d9, d10, d11} */
/* @0x2c5b38 vstr s15, [r4, #12] */
/* @0x2c5b3c pop {r4, r5, r6, pc} */
/* @0x2c5b40 vmov.f32 s18, #1.000000e+00 */
/* @0x2c5b44 vldr s15, [pc, #40] */
/* @0x2c5b48 vmov s13, r12 */
/* @0x2c5b4c mov r0, #0 */
/* @0x2c5b50 vcvt.f32.s32 s14, s13 */
/* @0x2c5b54 vdiv.f32 s18, s18, s14 */
/* @0x2c5b58 vmul.f32 s18, s18, s15 */
/* @0x2c5b5c vmov.f32 s16, s15 */
/* @0x2c5b60 vmov.f32 s20, s15 */
/* @0x2c5b64 vmov.f32 s19, s15 */
/* @0x2c5b68 vmov.f32 s17, s15 */
/* @0x2c5b6c vmov.f32 s22, s18 */
/* @0x2c5b70 b 0x2c5adc <_ZNK14b2PolygonShape11ComputeMassEP10b2MassDataf+0x14c> */
/* @0x2c5b74 andeq r0, r0, r0 */
/* @0x2c5b78 .word 0x3eaaaaab */
/* @0x2c5b7c .word 0x3daaaaab */
/* @0x2c5b80 strlo r0, [r0], #-0 */
/* @0x2c5b84 andseq r11, r2, r12, lsl r11 */
/* @0x2c5b88 andeq r7, r9, r4, lsl #14 */
/* @0x2c5b8c andeq r7, r9, r8, lsl #12 */

/* ── FUNC 0x2c5b90 · b2PolygonShape::~b2PolygonShape() · size=24 · insn=6 */
/* @0x2c5b90 ldr r3, [pc, #0xc] */
/* @0x2c5b94 ldr r3, [pc, r3] */
/* @0x2c5b98 add r3, r3, #8 */
/* @0x2c5b9c str r3, [r0] */
/* @0x2c5ba0 bx lr */
/* @0x2c5ba4 andseq r11, r2, r12, lsl #18 */

/* ── FUNC 0x2c5b90 · b2PolygonShape::~b2PolygonShape() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2c5ba8 · b2PolygonShape::~b2PolygonShape() · size=40 · insn=10 */
/* @0x2c5ba8 ldr r3, [pc, #0x1c] */
/* @0x2c5bac push {r4, lr} */
/* @0x2c5bb0 ldr r3, [pc, r3] */
/* @0x2c5bb4 mov r4, r0 */
/* @0x2c5bb8 add r3, r3, #8 */
/* @0x2c5bbc str r3, [r0] */
/* @0x2c5bc0 bl 0x27d1d0 <_ZdlPv> */
/* @0x2c5bc4 mov r0, r4 */
/* @0x2c5bc8 pop {r4, pc} */
/* @0x2c5bcc ldrsheq r11, [r2], -r0 */

/* ── FUNC 0x2c5bd0 · b2PolygonShape::Clone(b2BlockAllocator*) const · size=216 · insn=54 */
/* @0x2c5bd0 push {r4, r5, r6, r7, r8, lr} */
/* @0x2c5bd4 mov r8, r0 */
/* @0x2c5bd8 mov r0, r1 */
/* @0x2c5bdc mov r1, #152 */
/* @0x2c5be0 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2c5be4 subs r7, r0, #0 */
/* @0x2c5be8 beq 0x2c5c24 <_ZNK14b2PolygonShape5CloneEP16b2BlockAllocator+0x54> */
/* @0x2c5bec ldr r3, [pc, #0xb0] */
/* @0x2c5bf0 mov r2, #2 */
/* @0x2c5bf4 movw r1, #0xd70a */
/* @0x2c5bf8 str r2, [r7, #0x4] */
/* @0x2c5bfc ldr r3, [pc, r3] */
/* @0x2c5c00 movt r1, #0x3c23 */
/* @0x2c5c04 add r3, r3, #8 */
/* @0x2c5c08 mov r2, #0 */
/* @0x2c5c0c str r3, [r7] */
/* @0x2c5c10 mov r3, #0 */
/* @0x2c5c14 str r1, [r7, #0x8] */
/* @0x2c5c18 str r2, [r7, #0x94] */
/* @0x2c5c1c str r3, [r7, #0xc] */
/* @0x2c5c20 str r3, [r7, #0x10] */
/* @0x2c5c24 add r2, r8, #12 */
/* @0x2c5c28 ldr r12, [r8, #0x4] */
/* @0x2c5c2c add r3, r7, #12 */
/* @0x2c5c30 add r6, r8, #20 */
/* @0x2c5c34 ldm r2, {r0, r1} */
/* @0x2c5c38 add r5, r7, #20 */
/* @0x2c5c3c ldr r2, [r8, #0x8] */
/* @0x2c5c40 add r4, r8, #84 */
/* @0x2c5c44 str r12, [r7, #0x4] */
/* @0x2c5c48 add r12, r7, #84 */
/* @0x2c5c4c str r2, [r7, #0x8] */
/* @0x2c5c50 stm r3, {r0, r1} */
/* @0x2c5c54 ldm r6!, {r0, r1, r2, r3} */
/* @0x2c5c58 stm r5!, {r0, r1, r2, r3} */
/* @0x2c5c5c ldm r6!, {r0, r1, r2, r3} */
/* @0x2c5c60 stm r5!, {r0, r1, r2, r3} */
/* @0x2c5c64 ldm r6!, {r0, r1, r2, r3} */
/* @0x2c5c68 stm r5!, {r0, r1, r2, r3} */
/* @0x2c5c6c ldm r6, {r0, r1, r2, r3} */
/* @0x2c5c70 stm r5, {r0, r1, r2, r3} */
/* @0x2c5c74 ldm r4!, {r0, r1, r2, r3} */
/* @0x2c5c78 stm r12!, {r0, r1, r2, r3} */
/* @0x2c5c7c ldm r4!, {r0, r1, r2, r3} */
/* @0x2c5c80 stm r12!, {r0, r1, r2, r3} */
/* @0x2c5c84 ldm r4!, {r0, r1, r2, r3} */
/* @0x2c5c88 stm r12!, {r0, r1, r2, r3} */
/* @0x2c5c8c ldm r4, {r0, r1, r2, r3} */
/* @0x2c5c90 stm r12, {r0, r1, r2, r3} */
/* @0x2c5c94 mov r0, r7 */
/* @0x2c5c98 ldr r3, [r8, #0x94] */
/* @0x2c5c9c str r3, [r7, #0x94] */
/* @0x2c5ca0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2c5ca4 ldrheq r11, [r2], -r4 */

/* ── FUNC 0x2c5ca8 · b2PolygonShape::ComputeDistance(b2Transform const&, b2Vec2 const&, float*, b2Vec2*, int) const · size=500 · insn=125 */
/* @0x2c5ca8 vldr s15, [r1, #4] */
/* @0x2c5cac vldr s11, [r2, #4] */
/* @0x2c5cb0 vsub.f32 s11, s11, s15 */
/* @0x2c5cb4 vldr s13, [r1, #8] */
/* @0x2c5cb8 vldr s15, [r1, #12] */
/* @0x2c5cbc vldr s10, [r2] */
/* @0x2c5cc0 vldr s14, [r1] */
/* @0x2c5cc4 push {r4, r5, lr} */
/* @0x2c5cc8 vpush {d8} */
/* @0x2c5ccc sub sp, sp, #12 */
/* @0x2c5cd0 ldr r4, [r0, #0x94] */
/* @0x2c5cd4 ldr r5, [sp, #0x20] */
/* @0x2c5cd8 cmp r4, #0 */
/* @0x2c5cdc vmul.f32 s12, s11, s13 */
/* @0x2c5ce0 vmul.f32 s11, s11, s15 */
/* @0x2c5ce4 vsub.f32 s14, s10, s14 */
/* @0x2c5ce8 vmls.f32 s11, s13, s14 */
/* @0x2c5cec vmla.f32 s12, s14, s15 */
/* @0x2c5cf0 ble 0x2c5e28 <_ZNK14b2PolygonShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0x180> */
/* @0x2c5cf4 add r2, r0, #84 */
/* @0x2c5cf8 mov r12, #0 */
/* @0x2c5cfc vldr s9, [pc, #400] */
/* @0x2c5d00 vmov.f32 s17, s11 */
/* @0x2c5d04 vmov.f32 s16, s12 */
/* @0x2c5d08 vldr s15, [r2, #-60] */
/* @0x2c5d0c vldr s13, [r2, #4] */
/* @0x2c5d10 vldr s10, [r2, #-64] */
/* @0x2c5d14 vldr s14, [r2] */
/* @0x2c5d18 vsub.f32 s15, s11, s15 */
/* @0x2c5d1c add r12, r12, #1 */
/* @0x2c5d20 add r2, r2, #8 */
/* @0x2c5d24 vmul.f32 s15, s15, s13 */
/* @0x2c5d28 vsub.f32 s10, s12, s10 */
/* @0x2c5d2c vmla.f32 s15, s10, s14 */
/* @0x2c5d30 vcmpe.f32 s15, s9 */
/* @0x2c5d34 vmrs APSR_nzcv, fpscr */
/* @0x2c5d38 vmovgt.f32 s17, s13 */
/* @0x2c5d3c vmovgt.f32 s16, s14 */
/* @0x2c5d40 vmovgt.f32 s9, s15 */
/* @0x2c5d44 cmp r12, r4 */
/* @0x2c5d48 bne 0x2c5d08 <_ZNK14b2PolygonShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0x60> */
/* @0x2c5d4c vcmpe.f32 s9, #0 */
/* @0x2c5d50 vmrs APSR_nzcv, fpscr */
/* @0x2c5d54 ble 0x2c5e34 <_ZNK14b2PolygonShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0x18c> */
/* @0x2c5d58 vmul.f32 s9, s9, s9 */
/* @0x2c5d5c add r0, r0, #20 */
/* @0x2c5d60 mov r2, #0 */
/* @0x2c5d64 vldr s13, [r0, #4] */
/* @0x2c5d68 vldr s14, [r0] */
/* @0x2c5d6c add r2, r2, #1 */
/* @0x2c5d70 add r0, r0, #8 */
/* @0x2c5d74 vsub.f32 s13, s11, s13 */
/* @0x2c5d78 vmul.f32 s15, s13, s13 */
/* @0x2c5d7c vsub.f32 s14, s12, s14 */
/* @0x2c5d80 vmla.f32 s15, s14, s14 */
/* @0x2c5d84 vcmpe.f32 s15, s9 */
/* @0x2c5d88 vmrs APSR_nzcv, fpscr */
/* @0x2c5d8c vmovmi.f32 s17, s13 */
/* @0x2c5d90 vmovmi.f32 s16, s14 */
/* @0x2c5d94 vmovmi.f32 s9, s15 */
/* @0x2c5d98 cmp r2, r4 */
/* @0x2c5d9c bne 0x2c5d64 <_ZNK14b2PolygonShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0xbc> */
/* @0x2c5da0 vsqrt.f32 s15, s9 */
/* @0x2c5da4 vcmp.f32 s15, s15 */
/* @0x2c5da8 vmrs APSR_nzcv, fpscr */
/* @0x2c5dac bne 0x2c5e64 <_ZNK14b2PolygonShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0x1bc> */
/* @0x2c5db0 vstr s15, [r3] */
/* @0x2c5db4 vldr s14, [r1, #12] */
/* @0x2c5db8 vmul.f32 s15, s14, s17 */
/* @0x2c5dbc vldr s13, [r1, #8] */
/* @0x2c5dc0 vmla.f32 s15, s13, s16 */
/* @0x2c5dc4 vmul.f32 s17, s13, s17 */
/* @0x2c5dc8 vstr s15, [r5, #4] */
/* @0x2c5dcc vnmls.f32 s17, s14, s16 */
/* @0x2c5dd0 vmul.f32 s15, s15, s15 */
/* @0x2c5dd4 vstr s17, [r5] */
/* @0x2c5dd8 vmla.f32 s15, s17, s17 */
/* @0x2c5ddc vsqrt.f32 s14, s15 */
/* @0x2c5de0 vcmp.f32 s14, s14 */
/* @0x2c5de4 vmrs APSR_nzcv, fpscr */
/* @0x2c5de8 bne 0x2c5e84 <_ZNK14b2PolygonShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0x1dc> */
/* @0x2c5dec vldr s15, [pc, #164] */
/* @0x2c5df0 vcmpe.f32 s14, s15 */
/* @0x2c5df4 vmrs APSR_nzcv, fpscr */
/* @0x2c5df8 bmi 0x2c5e1c <_ZNK14b2PolygonShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0x174> */
/* @0x2c5dfc vmov.f32 s12, #1.000000e+00 */
/* @0x2c5e00 vldr s15, [r5] */
/* @0x2c5e04 vldr s13, [r5, #4] */
/* @0x2c5e08 vdiv.f32 s14, s12, s14 */
/* @0x2c5e0c vmul.f32 s15, s15, s14 */
/* @0x2c5e10 vmul.f32 s14, s13, s14 */
/* @0x2c5e14 vstr s15, [r5] */
/* @0x2c5e18 vstr s14, [r5, #4] */
/* @0x2c5e1c add sp, sp, #12 */
/* @0x2c5e20 vpop {d8} */
/* @0x2c5e24 pop {r4, r5, pc} */
/* @0x2c5e28 vmov.f32 s17, s11 */
/* @0x2c5e2c vldr s9, [pc, #96] */
/* @0x2c5e30 vmov.f32 s16, s12 */
/* @0x2c5e34 vstr s9, [r3] */
/* @0x2c5e38 vldr s14, [r1, #12] */
/* @0x2c5e3c vldr s13, [r1, #8] */
/* @0x2c5e40 vmul.f32 s15, s14, s17 */
/* @0x2c5e44 vmul.f32 s17, s13, s17 */
/* @0x2c5e48 vmla.f32 s15, s16, s13 */
/* @0x2c5e4c vnmls.f32 s17, s16, s14 */
/* @0x2c5e50 vstr s15, [r5, #4] */
/* @0x2c5e54 vstr s17, [r5] */
/* @0x2c5e58 add sp, sp, #12 */
/* @0x2c5e5c vpop {d8} */
/* @0x2c5e60 pop {r4, r5, pc} */
/* @0x2c5e64 vmov r0, s9 */
/* @0x2c5e68 str r1, [sp, #0x4] */
/* @0x2c5e6c str r3, [sp] */
/* @0x2c5e70 bl 0xb6700 <sqrtf@plt> */
/* @0x2c5e74 ldr r3, [sp] */
/* @0x2c5e78 ldr r1, [sp, #0x4] */
/* @0x2c5e7c vmov s15, r0 */
/* @0x2c5e80 b 0x2c5db0 <_ZNK14b2PolygonShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0x108> */
/* @0x2c5e84 vmov r0, s15 */
/* @0x2c5e88 bl 0xb6700 <sqrtf@plt> */
/* @0x2c5e8c vmov s14, r0 */
/* @0x2c5e90 b 0x2c5dec <_ZNK14b2PolygonShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0x144> */
/* @0x2c5e94 .word 0xff7fffff */
/* @0x2c5e98 strlo r0, [r0], #-0 */

/* ── FUNC 0x2c5e9c · b2PolygonShape::SetAsBox(float, float) · size=116 · insn=29 */
/* @0x2c5e9c vmov s14, r1 */
/* @0x2c5ea0 mov r3, #4 */
/* @0x2c5ea4 vmov s15, r2 */
/* @0x2c5ea8 mov r12, #0 */
/* @0x2c5eac vneg.f32 s14, s14 */
/* @0x2c5eb0 movt r12, #0xbf80 */
/* @0x2c5eb4 str r3, [r0, #0x94] */
/* @0x2c5eb8 mov r3, #0 */
/* @0x2c5ebc str r1, [r0, #0x1c] */
/* @0x2c5ec0 str r3, [r0, #0x54] */
/* @0x2c5ec4 vneg.f32 s15, s15 */
/* @0x2c5ec8 str r3, [r0, #0x60] */
/* @0x2c5ecc str r3, [r0, #0x64] */
/* @0x2c5ed0 vstr s14, [r0, #20] */
/* @0x2c5ed4 str r3, [r0, #0x70] */
/* @0x2c5ed8 vstr s14, [r0, #44] */
/* @0x2c5edc str r3, [r0, #0xc] */
/* @0x2c5ee0 str r3, [r0, #0x10] */
/* @0x2c5ee4 vstr s15, [r0, #24] */
/* @0x2c5ee8 mov r3, #1065353216 */
/* @0x2c5eec str r1, [r0, #0x24] */
/* @0x2c5ef0 str r2, [r0, #0x28] */
/* @0x2c5ef4 vstr s15, [r0, #32] */
/* @0x2c5ef8 str r2, [r0, #0x30] */
/* @0x2c5efc str r12, [r0, #0x58] */
/* @0x2c5f00 str r12, [r0, #0x6c] */
/* @0x2c5f04 str r3, [r0, #0x5c] */
/* @0x2c5f08 str r3, [r0, #0x68] */
/* @0x2c5f0c bx lr */

/* ── FUNC 0x2c5f10 · b2PolygonShape::SetAsBox(float, float, b2Vec2 const&, float) · size=280 · insn=70 */
/* @0x2c5f10 vmov s14, r1 */
/* @0x2c5f14 mov r12, #0 */
/* @0x2c5f18 vmov s15, r2 */
/* @0x2c5f1c movt r12, #0xbf80 */
/* @0x2c5f20 vneg.f32 s14, s14 */
/* @0x2c5f24 push {r3, r4, r5, lr} */
/* @0x2c5f28 vpush {d8, d9} */
/* @0x2c5f2c mov r4, r0 */
/* @0x2c5f30 str r1, [r4, #0x1c] */
/* @0x2c5f34 vneg.f32 s15, s15 */
/* @0x2c5f38 str r1, [r4, #0x24] */
/* @0x2c5f3c str r2, [r4, #0x28] */
/* @0x2c5f40 mov r1, #4 */
/* @0x2c5f44 str r2, [r4, #0x30] */
/* @0x2c5f48 vstr s14, [r0, #20] */
/* @0x2c5f4c str r12, [r0, #0x58] */
/* @0x2c5f50 vstr s14, [r0, #44] */
/* @0x2c5f54 vstr s15, [r0, #24] */
/* @0x2c5f58 vstr s15, [r0, #32] */
/* @0x2c5f5c str r12, [r0, #0x6c] */
/* @0x2c5f60 mov r2, #0 */
/* @0x2c5f64 str r1, [r0, #0x94] */
/* @0x2c5f68 mov r1, #1065353216 */
/* @0x2c5f6c str r2, [r0, #0x54] */
/* @0x2c5f70 str r2, [r0, #0x60] */
/* @0x2c5f74 str r2, [r0, #0x64] */
/* @0x2c5f78 str r2, [r0, #0x70] */
/* @0x2c5f7c add r2, r0, #12 */
/* @0x2c5f80 str r1, [r0, #0x5c] */
/* @0x2c5f84 str r1, [r0, #0x68] */
/* @0x2c5f88 ldr r5, [sp, #0x20] */
/* @0x2c5f8c ldm r3, {r0, r1} */
/* @0x2c5f90 stm r2, {r0, r1} */
/* @0x2c5f94 mov r0, r5 */
/* @0x2c5f98 vldr s18, [r3] */
/* @0x2c5f9c vldr s17, [r3, #4] */
/* @0x2c5fa0 bl 0xb6580 <sinf@plt> */
/* @0x2c5fa4 vmov s16, r0 */
/* @0x2c5fa8 mov r0, r5 */
/* @0x2c5fac bl 0xb658c <cosf@plt> */
/* @0x2c5fb0 add r3, r4, #84 */
/* @0x2c5fb4 add r1, r4, #88 */
/* @0x2c5fb8 mov r2, #0 */
/* @0x2c5fbc vmov s15, r0 */
/* @0x2c5fc0 vldr s14, [r3, #-60] */
/* @0x2c5fc4 vmul.f32 s13, s14, s16 */
/* @0x2c5fc8 vldr s12, [r3, #-64] */
/* @0x2c5fcc add r2, r2, #1 */
/* @0x2c5fd0 vmul.f32 s14, s14, s15 */
/* @0x2c5fd4 vnmls.f32 s13, s12, s15 */
/* @0x2c5fd8 vmla.f32 s14, s12, s16 */
/* @0x2c5fdc vadd.f32 s13, s18, s13 */
/* @0x2c5fe0 vadd.f32 s14, s17, s14 */
/* @0x2c5fe4 vstr s13, [r3, #-64] */
/* @0x2c5fe8 vstr s14, [r1, #-64] */
/* @0x2c5fec vldr s14, [r3, #4] */
/* @0x2c5ff0 vmul.f32 s13, s14, s16 */
/* @0x2c5ff4 vldr s12, [r3] */
/* @0x2c5ff8 vnmls.f32 s13, s12, s15 */
/* @0x2c5ffc vmul.f32 s14, s14, s15 */
/* @0x2c6000 vmov r0, s13 */
/* @0x2c6004 vmla.f32 s14, s12, s16 */
/* @0x2c6008 str r0, [r3], #8 */
/* @0x2c600c vmov r0, s14 */
/* @0x2c6010 str r0, [r1], #8 */
/* @0x2c6014 ldr r0, [r4, #0x94] */
/* @0x2c6018 cmp r0, r2 */
/* @0x2c601c bgt 0x2c5fc0 <_ZN14b2PolygonShape8SetAsBoxEffRK6b2Vec2f+0xb0> */
/* @0x2c6020 vpop {d8, d9} */
/* @0x2c6024 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2c6028 · b2PolygonShape::Set(b2Vec2 const*, int) · size=1004 · insn=251 */
/* @0x2c6028 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2c602c vpush {d8, d9, d10} */
/* @0x2c6030 sub r3, r2, #3 */
/* @0x2c6034 ldr r8, [pc, #0x3c4] */
/* @0x2c6038 cmp r3, #5 */
/* @0x2c603c mov r4, r1 */
/* @0x2c6040 ldr r1, [pc, #0x3bc] */
/* @0x2c6044 ldr r8, [pc, r8] */
/* @0x2c6048 mov r6, r0 */
/* @0x2c604c sub sp, sp, #108 */
/* @0x2c6050 movhi r0, #0 */
/* @0x2c6054 movls r0, #1 */
/* @0x2c6058 add r1, pc, r1 */
/* @0x2c605c ldr r3, [r8] */
/* @0x2c6060 mov r9, r2 */
/* @0x2c6064 blx r3 */
/* @0x2c6068 cmp r9, #2 */
/* @0x2c606c ble 0x2c63c4 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x39c> */
/* @0x2c6070 cmp r9, #7 */
/* @0x2c6074 mov r3, #0 */
/* @0x2c6078 add r5, sp, #40 */
/* @0x2c607c mov r12, r3 */
/* @0x2c6080 movle r7, r9 */
/* @0x2c6084 movgt r7, #8 */
/* @0x2c6088 add r1, r4, r3 */
/* @0x2c608c add r12, r12, #1 */
/* @0x2c6090 add r2, r5, r3 */
/* @0x2c6094 cmp r12, r7 */
/* @0x2c6098 ldm r1, {r0, r1} */
/* @0x2c609c add r3, r3, #8 */
/* @0x2c60a0 stm r2, {r0, r1} */
/* @0x2c60a4 blt 0x2c6088 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x60> */
/* @0x2c60a8 add r10, sp, #48 */
/* @0x2c60ac mov r3, #1 */
/* @0x2c60b0 mov r4, #0 */
/* @0x2c60b4 vldr s14, [sp, #40] */
/* @0x2c60b8 mov r2, r10 */
/* @0x2c60bc vldr s15, [r2] */
/* @0x2c60c0 vcmpe.f32 s15, s14 */
/* @0x2c60c4 vmrs APSR_nzcv, fpscr */
/* @0x2c60c8 vmovgt.f32 s14, s15 */
/* @0x2c60cc movgt r4, r3 */
/* @0x2c60d0 bgt 0x2c6100 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0xd8> */
/* @0x2c60d4 add r0, sp, #104 */
/* @0x2c60d8 vcmp.f32 s15, s14 */
/* @0x2c60dc add r1, r0, r4, lsl #3 */
/* @0x2c60e0 vmrs APSR_nzcv, fpscr */
/* @0x2c60e4 bne 0x2c6100 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0xd8> */
/* @0x2c60e8 vldr s12, [r2, #4] */
/* @0x2c60ec vldr s13, [r1, #-60] */
/* @0x2c60f0 vcmp.f32 s12, s13 */
/* @0x2c60f4 vmrs APSR_nzcv, fpscr */
/* @0x2c60f8 vmovmi.f32 s14, s15 */
/* @0x2c60fc movmi r4, r3 */
/* @0x2c6100 add r3, r3, #1 */
/* @0x2c6104 add r2, r2, #8 */
/* @0x2c6108 cmp r3, r9 */
/* @0x2c610c bne 0x2c60bc <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x94> */
/* @0x2c6110 add r1, sp, #4 */
/* @0x2c6114 mov r11, r4 */
/* @0x2c6118 mov r9, #0 */
/* @0x2c611c str r1, [sp, #0x4] */
/* @0x2c6120 mov r0, r1 */
/* @0x2c6124 add lr, r5, r4, lsl #3 */
/* @0x2c6128 mov r1, r10 */
/* @0x2c612c mov r2, #1 */
/* @0x2c6130 mov r3, #0 */
/* @0x2c6134 str r4, [r0, #0x4]! */
/* @0x2c6138 cmp r3, r4 */
/* @0x2c613c add r12, r5, r3, lsl #3 */
/* @0x2c6140 moveq r3, r2 */
/* @0x2c6144 beq 0x2c61a4 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x17c> */
/* @0x2c6148 vldr s13, [lr] */
/* @0x2c614c vldr s14, [lr, #4] */
/* @0x2c6150 vldr s12, [r1] */
/* @0x2c6154 vldr s11, [r12, #4] */
/* @0x2c6158 vsub.f32 s12, s12, s13 */
/* @0x2c615c vldr s9, [r12] */
/* @0x2c6160 vldr s10, [r1, #4] */
/* @0x2c6164 vsub.f32 s11, s11, s14 */
/* @0x2c6168 vmul.f32 s15, s11, s12 */
/* @0x2c616c vsub.f32 s13, s9, s13 */
/* @0x2c6170 vsub.f32 s14, s10, s14 */
/* @0x2c6174 vnmls.f32 s15, s13, s14 */
/* @0x2c6178 vcmp.f32 s15, #0 */
/* @0x2c617c vmrs APSR_nzcv, fpscr */
/* @0x2c6180 movmi r3, r2 */
/* @0x2c6184 bne 0x2c61a4 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x17c> */
/* @0x2c6188 vmul.f32 s14, s14, s14 */
/* @0x2c618c vmul.f32 s11, s11, s11 */
/* @0x2c6190 vmla.f32 s14, s12, s12 */
/* @0x2c6194 vmla.f32 s11, s13, s13 */
/* @0x2c6198 vcmp.f32 s14, s11 */
/* @0x2c619c vmrs APSR_nzcv, fpscr */
/* @0x2c61a0 movgt r3, r2 */
/* @0x2c61a4 add r2, r2, #1 */
/* @0x2c61a8 add r1, r1, #8 */
/* @0x2c61ac cmp r2, r7 */
/* @0x2c61b0 blt 0x2c6138 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x110> */
/* @0x2c61b4 cmp r11, r3 */
/* @0x2c61b8 add r9, r9, #1 */
/* @0x2c61bc movne r4, r3 */
/* @0x2c61c0 bne 0x2c6124 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0xfc> */
/* @0x2c61c4 add lr, sp, #4 */
/* @0x2c61c8 mov r2, r6 */
/* @0x2c61cc mov r3, #0 */
/* @0x2c61d0 str r9, [r6, #0x94] */
/* @0x2c61d4 ldr r1, [lr, #0x4]! */
/* @0x2c61d8 add r0, sp, #104 */
/* @0x2c61dc add r3, r3, #1 */
/* @0x2c61e0 add r12, r2, #20 */
/* @0x2c61e4 cmp r3, r9 */
/* @0x2c61e8 add r2, r2, #8 */
/* @0x2c61ec add r1, r0, r1, lsl #3 */
/* @0x2c61f0 sub r1, r1, #64 */
/* @0x2c61f4 ldm r1, {r0, r1} */
/* @0x2c61f8 stm r12, {r0, r1} */
/* @0x2c61fc blt 0x2c61d4 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x1ac> */
/* @0x2c6200 vmov.f32 s21, #1.000000e+00 */
/* @0x2c6204 ldr r7, [pc, #0x1fc] */
/* @0x2c6208 add r4, r6, #84 */
/* @0x2c620c mov r5, #0 */
/* @0x2c6210 add r7, pc, r7 */
/* @0x2c6214 vldr s20, [pc, #468] */
/* @0x2c6218 vldr s19, [pc, #468] */
/* @0x2c621c add r5, r5, #1 */
/* @0x2c6220 vldr s14, [r4, #-60] */
/* @0x2c6224 cmp r5, r9 */
/* @0x2c6228 vldr s15, [r4, #-64] */
/* @0x2c622c ldr r2, [r8] */
/* @0x2c6230 mov r1, r7 */
/* @0x2c6234 movlt r3, r5 */
/* @0x2c6238 movge r3, #0 */
/* @0x2c623c add r3, r3, #2 */
/* @0x2c6240 add r3, r6, r3, lsl #3 */
/* @0x2c6244 vldr s16, [r3, #8] */
/* @0x2c6248 vsub.f32 s16, s16, s14 */
/* @0x2c624c vldr s17, [r3, #4] */
/* @0x2c6250 vmul.f32 s18, s16, s16 */
/* @0x2c6254 vsub.f32 s17, s17, s15 */
/* @0x2c6258 vmov.f32 s15, s18 */
/* @0x2c625c vmla.f32 s15, s17, s17 */
/* @0x2c6260 vcmpe.f32 s15, s20 */
/* @0x2c6264 vneg.f32 s17, s17 */
/* @0x2c6268 vmrs APSR_nzcv, fpscr */
/* @0x2c626c movle r0, #0 */
/* @0x2c6270 movgt r0, #1 */
/* @0x2c6274 blx r2 */
/* @0x2c6278 vstr s16, [r4] */
/* @0x2c627c vmla.f32 s18, s17, s17 */
/* @0x2c6280 vstr s17, [r4, #4] */
/* @0x2c6284 vsqrt.f32 s15, s18 */
/* @0x2c6288 vcmp.f32 s15, s15 */
/* @0x2c628c vmrs APSR_nzcv, fpscr */
/* @0x2c6290 bne 0x2c63e0 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x3b8> */
/* @0x2c6294 vcmpe.f32 s15, s19 */
/* @0x2c6298 vmrs APSR_nzcv, fpscr */
/* @0x2c629c bmi 0x2c62bc <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x294> */
/* @0x2c62a0 vdiv.f32 s15, s21, s15 */
/* @0x2c62a4 vldr s14, [r4] */
/* @0x2c62a8 vldr s13, [r4, #4] */
/* @0x2c62ac vmul.f32 s14, s14, s15 */
/* @0x2c62b0 vmul.f32 s15, s13, s15 */
/* @0x2c62b4 vstr s14, [r4] */
/* @0x2c62b8 vstr s15, [r4, #4] */
/* @0x2c62bc cmp r5, r9 */
/* @0x2c62c0 add r4, r4, #8 */
/* @0x2c62c4 blt 0x2c621c <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x1f4> */
/* @0x2c62c8 cmp r9, #2 */
/* @0x2c62cc ldr r1, [pc, #0x138] */
/* @0x2c62d0 ldr r3, [r8] */
/* @0x2c62d4 add r4, r6, #20 */
/* @0x2c62d8 movle r0, #0 */
/* @0x2c62dc movgt r0, #1 */
/* @0x2c62e0 add r1, pc, r1 */
/* @0x2c62e4 blx r3 */
/* @0x2c62e8 vldr s10, [pc, #264] */
/* @0x2c62ec vmov.f32 s5, #5.000000e-01 */
/* @0x2c62f0 add r0, r6, #24 */
/* @0x2c62f4 add r3, r6, #28 */
/* @0x2c62f8 mov r2, #0 */
/* @0x2c62fc vldr s6, [pc, #248] */
/* @0x2c6300 vmov.f32 s8, s10 */
/* @0x2c6304 vmov.f32 s16, s10 */
/* @0x2c6308 vmov.f32 s9, s10 */
/* @0x2c630c b 0x2c6314 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x2ec> */
/* @0x2c6310 vmov.f32 s10, s18 */
/* @0x2c6314 add r2, r2, #1 */
/* @0x2c6318 mov r1, r0 */
/* @0x2c631c cmp r2, r9 */
/* @0x2c6320 vldr s14, [r1] */
/* @0x2c6324 vldr s11, [r3, #-8] */
/* @0x2c6328 vadd.f32 s7, s11, s9 */
/* @0x2c632c movge r1, r4 */
/* @0x2c6330 movlt r1, r3 */
/* @0x2c6334 vldr s12, [r1] */
/* @0x2c6338 vldr s13, [r1, #4] */
/* @0x2c633c add r0, r0, #8 */
/* @0x2c6340 add r3, r3, #8 */
/* @0x2c6344 vmul.f32 s15, s14, s12 */
/* @0x2c6348 vnmls.f32 s15, s11, s13 */
/* @0x2c634c vmul.f32 s15, s15, s5 */
/* @0x2c6350 vadd.f32 s11, s14, s9 */
/* @0x2c6354 vmul.f32 s14, s15, s6 */
/* @0x2c6358 vadd.f32 s12, s12, s7 */
/* @0x2c635c vmov.f32 s17, s8 */
/* @0x2c6360 vmla.f32 s17, s14, s12 */
/* @0x2c6364 vadd.f32 s13, s13, s11 */
/* @0x2c6368 vmov.f32 s18, s10 */
/* @0x2c636c vadd.f32 s16, s16, s15 */
/* @0x2c6370 vmov.f32 s8, s17 */
/* @0x2c6374 vmla.f32 s18, s14, s13 */
/* @0x2c6378 blt 0x2c6310 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x2e8> */
/* @0x2c637c vldr s15, [pc, #112] */
/* @0x2c6380 vcmpe.f32 s16, s15 */
/* @0x2c6384 ldr r1, [pc, #0x84] */
/* @0x2c6388 ldr r3, [r8] */
/* @0x2c638c add r1, pc, r1 */
/* @0x2c6390 vmrs APSR_nzcv, fpscr */
/* @0x2c6394 movle r0, #0 */
/* @0x2c6398 movgt r0, #1 */
/* @0x2c639c blx r3 */
/* @0x2c63a0 vmov.f32 s15, #1.000000e+00 */
/* @0x2c63a4 vdiv.f32 s16, s15, s16 */
/* @0x2c63a8 vmul.f32 s17, s17, s16 */
/* @0x2c63ac vmul.f32 s16, s18, s16 */
/* @0x2c63b0 vstr s17, [r6, #12] */
/* @0x2c63b4 vstr s16, [r6, #16] */
/* @0x2c63b8 add sp, sp, #108 */
/* @0x2c63bc vpop {d8, d9, d10} */
/* @0x2c63c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2c63c4 mov r1, #1065353216 */
/* @0x2c63c8 mov r0, r6 */
/* @0x2c63cc mov r2, r1 */
/* @0x2c63d0 add sp, sp, #108 */
/* @0x2c63d4 vpop {d8, d9, d10} */
/* @0x2c63d8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2c63dc b 0x2c5e9c <_ZN14b2PolygonShape8SetAsBoxEff> */
/* @0x2c63e0 vmov r0, s18 */
/* @0x2c63e4 bl 0xb6700 <sqrtf@plt> */
/* @0x2c63e8 vmov s15, r0 */
/* @0x2c63ec b 0x2c6294 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x26c> */
/* @0x2c63f0 .word 0x28800000 */
/* @0x2c63f4 strlo r0, [r0], #-0 */
/* @0x2c63f8 andeq r0, r0, r0 */
/* @0x2c63fc .word 0x3eaaaaab */
/* @0x2c6400 andseq r11, r2, r4, lsl #9 */
/* @0x2c6404 andeq r7, r9, r0, ror #1 */
/* @0x2c6408 ldrdeq r6, r7, [r9], -r12 */
/* @0x2c640c andeq r6, r9, r8, asr #31 */
/* @0x2c6410 andeq r6, r9, r4, ror #26 */

/* ── FUNC 0x2c6414 · b2PolygonShape::Validate() const · size=188 · insn=47 */
/* @0x2c6414 push {r4, r5, r6, r7, r8} */
/* @0x2c6418 mov r6, r0 */
/* @0x2c641c ldr r4, [r0, #0x94] */
/* @0x2c6420 cmp r4, #0 */
/* @0x2c6424 ble 0x2c64c4 <_ZNK14b2PolygonShape8ValidateEv+0xb0> */
/* @0x2c6428 add r7, r0, #20 */
/* @0x2c642c sub r8, r4, #1 */
/* @0x2c6430 mov r1, #0 */
/* @0x2c6434 mov r5, r7 */
/* @0x2c6438 cmp r1, r8 */
/* @0x2c643c vldr s12, [r5] */
/* @0x2c6440 addlt r12, r1, #1 */
/* @0x2c6444 vldr s13, [r5, #4] */
/* @0x2c6448 movge r12, #0 */
/* @0x2c644c add r3, r12, #2 */
/* @0x2c6450 mov r2, r7 */
/* @0x2c6454 add r3, r6, r3, lsl #3 */
/* @0x2c6458 vldr s10, [r3, #4] */
/* @0x2c645c vldr s11, [r3, #8] */
/* @0x2c6460 vsub.f32 s10, s10, s12 */
/* @0x2c6464 mov r3, #0 */
/* @0x2c6468 vsub.f32 s11, s11, s13 */
/* @0x2c646c cmp r1, r3 */
/* @0x2c6470 cmpne r3, r12 */
/* @0x2c6474 add r3, r3, #1 */
/* @0x2c6478 movne r0, #0 */
/* @0x2c647c moveq r0, #1 */
/* @0x2c6480 beq 0x2c64a8 <_ZNK14b2PolygonShape8ValidateEv+0x94> */
/* @0x2c6484 vldr s15, [r2] */
/* @0x2c6488 vldr s14, [r2, #4] */
/* @0x2c648c vsub.f32 s15, s15, s12 */
/* @0x2c6490 vmul.f32 s15, s11, s15 */
/* @0x2c6494 vsub.f32 s14, s14, s13 */
/* @0x2c6498 vnmls.f32 s15, s10, s14 */
/* @0x2c649c vcmpe.f32 s15, #0 */
/* @0x2c64a0 vmrs APSR_nzcv, fpscr */
/* @0x2c64a4 bmi 0x2c64c8 <_ZNK14b2PolygonShape8ValidateEv+0xb4> */
/* @0x2c64a8 cmp r3, r4 */
/* @0x2c64ac add r2, r2, #8 */
/* @0x2c64b0 bne 0x2c646c <_ZNK14b2PolygonShape8ValidateEv+0x58> */
/* @0x2c64b4 add r1, r1, #1 */
/* @0x2c64b8 add r5, r5, #8 */
/* @0x2c64bc cmp r1, r3 */
/* @0x2c64c0 bne 0x2c6438 <_ZNK14b2PolygonShape8ValidateEv+0x24> */
/* @0x2c64c4 mov r0, #1 */
/* @0x2c64c8 pop {r4, r5, r6, r7, r8} */
/* @0x2c64cc bx lr */

/* ── FUNC 0x2c64d0 · b2BlockAllocator::b2BlockAllocator() · size=168 · insn=42 */
/* @0x2c64d0 push {r4, r5, r6, lr} */
/* @0x2c64d4 mov r3, #128 */
/* @0x2c64d8 mov r6, r0 */
/* @0x2c64dc mov r4, #0 */
/* @0x2c64e0 str r3, [r0, #0x8] */
/* @0x2c64e4 str r4, [r0, #0x4] */
/* @0x2c64e8 mov r0, #1024 */
/* @0x2c64ec bl 0x2c6a6c <_Z7b2Alloci> */
/* @0x2c64f0 ldr r2, [r6, #0x8] */
/* @0x2c64f4 mov r1, r4 */
/* @0x2c64f8 lsl r2, r2, #3 */
/* @0x2c64fc str r0, [r6] */
/* @0x2c6500 bl 0xb65b0 <memset@plt> */
/* @0x2c6504 mov r2, #56 */
/* @0x2c6508 mov r1, r4 */
/* @0x2c650c add r0, r6, #12 */
/* @0x2c6510 bl 0xb65b0 <memset@plt> */
/* @0x2c6514 ldr r0, [pc, #0x50] */
/* @0x2c6518 ldr r0, [pc, r0] */
/* @0x2c651c ldrb r2, [r0] */
/* @0x2c6520 cmp r2, r4 */
/* @0x2c6524 bne 0x2c6564 <_ZN16b2BlockAllocatorC2Ev+0x94> */
/* @0x2c6528 ldr r4, [pc, #0x40] */
/* @0x2c652c mov r3, #1 */
/* @0x2c6530 ldr r12, [pc, #0x3c] */
/* @0x2c6534 movw r5, #0x281 */
/* @0x2c6538 ldr r4, [pc, r4] */
/* @0x2c653c ldr r12, [pc, r12] */
/* @0x2c6540 ldr r1, [r4, r2, lsl #2] */
/* @0x2c6544 cmp r1, r3 */
/* @0x2c6548 addlt r2, r2, #1 */
/* @0x2c654c strb r2, [r12, r3] */
/* @0x2c6550 add r3, r3, #1 */
/* @0x2c6554 cmp r3, r5 */
/* @0x2c6558 bne 0x2c6540 <_ZN16b2BlockAllocatorC2Ev+0x70> */
/* @0x2c655c mov r3, #1 */
/* @0x2c6560 strb r3, [r0] */
/* @0x2c6564 mov r0, r6 */
/* @0x2c6568 pop {r4, r5, r6, pc} */
/* @0x2c656c ldrheq r11, [r2], -r12 */
/* @0x2c6570 andseq r11, r2, r0, lsr #11 */
/* @0x2c6574 andseq r11, r2, r0, lsr #11 */

/* ── FUNC 0x2c64d0 · b2BlockAllocator::b2BlockAllocator() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2c6578 · b2BlockAllocator::~b2BlockAllocator() · size=72 · insn=18 */
/* @0x2c6578 push {r3, r4, r5, lr} */
/* @0x2c657c mov r5, r0 */
/* @0x2c6580 ldr r3, [r0, #0x4] */
/* @0x2c6584 cmp r3, #0 */
/* @0x2c6588 ble 0x2c65b0 <_ZN16b2BlockAllocatorD2Ev+0x38> */
/* @0x2c658c mov r4, #0 */
/* @0x2c6590 ldr r3, [r5] */
/* @0x2c6594 add r3, r3, r4, lsl #3 */
/* @0x2c6598 add r4, r4, #1 */
/* @0x2c659c ldr r0, [r3, #0x4] */
/* @0x2c65a0 bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2c65a4 ldr r3, [r5, #0x4] */
/* @0x2c65a8 cmp r3, r4 */
/* @0x2c65ac bgt 0x2c6590 <_ZN16b2BlockAllocatorD2Ev+0x18> */
/* @0x2c65b0 ldr r0, [r5] */
/* @0x2c65b4 bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2c65b8 mov r0, r5 */
/* @0x2c65bc pop {r3, r4, r5, pc} */

/* ── FUNC 0x2c6578 · b2BlockAllocator::~b2BlockAllocator() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2c65c0 · b2BlockAllocator::Allocate(int) · size=336 · insn=84 */
/* @0x2c65c0 cmp r1, #0 */
/* @0x2c65c4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2c65c8 mov r5, r0 */
/* @0x2c65cc beq 0x2c66ac <_ZN16b2BlockAllocator8AllocateEi+0xec> */
/* @0x2c65d0 cmp r1, #640 */
/* @0x2c65d4 bgt 0x2c6608 <_ZN16b2BlockAllocator8AllocateEi+0x48> */
/* @0x2c65d8 ldr r3, [pc, #0x128] */
/* @0x2c65dc ldr r3, [pc, r3] */
/* @0x2c65e0 ldrb r8, [r3, r1] */
/* @0x2c65e4 add r7, r0, r8, lsl #2 */
/* @0x2c65e8 ldr r4, [r7, #0xc] */
/* @0x2c65ec cmp r4, #0 */
/* @0x2c65f0 beq 0x2c6614 <_ZN16b2BlockAllocator8AllocateEi+0x54> */
/* @0x2c65f4 ldr r3, [r4] */
/* @0x2c65f8 mov r6, r4 */
/* @0x2c65fc mov r0, r6 */
/* @0x2c6600 str r3, [r7, #0xc] */
/* @0x2c6604 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2c6608 mov r0, r1 */
/* @0x2c660c pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2c6610 b 0x2c6a6c <_Z7b2Alloci> */
/* @0x2c6614 ldr r10, [r0, #0x4] */
/* @0x2c6618 ldr r3, [r0, #0x8] */
/* @0x2c661c cmp r10, r3 */
/* @0x2c6620 beq 0x2c66b8 <_ZN16b2BlockAllocator8AllocateEi+0xf8> */
/* @0x2c6624 mov r0, #16384 */
/* @0x2c6628 ldr r9, [r5] */
/* @0x2c662c bl 0x2c6a6c <_Z7b2Alloci> */
/* @0x2c6630 ldr r3, [pc, #0xd4] */
/* @0x2c6634 add r2, r9, r10, lsl #3 */
/* @0x2c6638 ldr r3, [pc, r3] */
/* @0x2c663c ldr r4, [r3, r8, lsl #2] */
/* @0x2c6640 mov r1, r4 */
/* @0x2c6644 mov r6, r0 */
/* @0x2c6648 mov r0, #16384 */
/* @0x2c664c str r6, [r2, #0x4] */
/* @0x2c6650 str r4, [r9, r10, lsl #3] */
/* @0x2c6654 bl 0x318d10 <__divsi3> */
/* @0x2c6658 sub r0, r0, #1 */
/* @0x2c665c cmp r0, #0 */
/* @0x2c6660 addgt r3, r6, r4 */
/* @0x2c6664 movgt r2, #0 */
/* @0x2c6668 ble 0x2c6684 <_ZN16b2BlockAllocator8AllocateEi+0xc4> */
/* @0x2c666c add r2, r2, #1 */
/* @0x2c6670 rsb r12, r4, r3 */
/* @0x2c6674 cmp r2, r0 */
/* @0x2c6678 str r3, [r12] */
/* @0x2c667c add r3, r3, r4 */
/* @0x2c6680 bne 0x2c666c <_ZN16b2BlockAllocator8AllocateEi+0xac> */
/* @0x2c6684 mul r4, r0, r4 */
/* @0x2c6688 mov r3, #0 */
/* @0x2c668c mov r0, r6 */
/* @0x2c6690 str r3, [r6, r4] */
/* @0x2c6694 ldr r3, [r6] */
/* @0x2c6698 str r3, [r7, #0xc] */
/* @0x2c669c ldr r3, [r5, #0x4] */
/* @0x2c66a0 add r3, r3, #1 */
/* @0x2c66a4 str r3, [r5, #0x4] */
/* @0x2c66a8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2c66ac mov r6, r1 */
/* @0x2c66b0 mov r0, r6 */
/* @0x2c66b4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2c66b8 add r0, r10, #128 */
/* @0x2c66bc str r0, [r5, #0x8] */
/* @0x2c66c0 ldr r6, [r5] */
/* @0x2c66c4 lsl r0, r0, #3 */
/* @0x2c66c8 bl 0x2c6a6c <_Z7b2Alloci> */
/* @0x2c66cc ldr r2, [r5, #0x4] */
/* @0x2c66d0 mov r1, r6 */
/* @0x2c66d4 lsl r2, r2, #3 */
/* @0x2c66d8 str r0, [r5] */
/* @0x2c66dc bl 0xb65bc <memcpy@plt> */
/* @0x2c66e0 ldr r0, [r5, #0x4] */
/* @0x2c66e4 ldr r3, [r5] */
/* @0x2c66e8 mov r1, r4 */
/* @0x2c66ec mov r2, #1024 */
/* @0x2c66f0 add r0, r3, r0, lsl #3 */
/* @0x2c66f4 bl 0xb65b0 <memset@plt> */
/* @0x2c66f8 mov r0, r6 */
/* @0x2c66fc bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2c6700 ldr r10, [r5, #0x4] */
/* @0x2c6704 b 0x2c6624 <_ZN16b2BlockAllocator8AllocateEi+0x64> */
/* @0x2c6708 andseq r11, r2, r0, lsl #10 */
/* @0x2c670c andseq r11, r2, r0, lsr #9 */

/* ── FUNC 0x2c6710 · b2BlockAllocator::Free(void*, int) · size=60 · insn=15 */
/* @0x2c6710 cmp r2, #0 */
/* @0x2c6714 bxeq lr */
/* @0x2c6718 cmp r2, #640 */
/* @0x2c671c bgt 0x2c6740 <_ZN16b2BlockAllocator4FreeEPvi+0x30> */
/* @0x2c6720 ldr r3, [pc, #0x20] */
/* @0x2c6724 ldr r3, [pc, r3] */
/* @0x2c6728 ldrb r3, [r3, r2] */
/* @0x2c672c add r0, r0, r3, lsl #2 */
/* @0x2c6730 ldr r3, [r0, #0xc] */
/* @0x2c6734 str r3, [r1] */
/* @0x2c6738 str r1, [r0, #0xc] */
/* @0x2c673c bx lr */
/* @0x2c6740 mov r0, r1 */
/* @0x2c6744 b 0x2c6a70 <_Z6b2FreePv> */
/* @0x2c6748 ldrheq r11, [r2], -r8 */

/* ── FUNC 0x2c674c · b2BlockAllocator::Clear() · size=108 · insn=27 */
/* @0x2c674c ldr r3, [r0, #0x4] */
/* @0x2c6750 push {r4, r5, r6, lr} */
/* @0x2c6754 cmp r3, #0 */
/* @0x2c6758 mov r5, r0 */
/* @0x2c675c movgt r4, #0 */
/* @0x2c6760 ble 0x2c6784 <_ZN16b2BlockAllocator5ClearEv+0x38> */
/* @0x2c6764 ldr r3, [r5] */
/* @0x2c6768 add r3, r3, r4, lsl #3 */
/* @0x2c676c add r4, r4, #1 */
/* @0x2c6770 ldr r0, [r3, #0x4] */
/* @0x2c6774 bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2c6778 ldr r3, [r5, #0x4] */
/* @0x2c677c cmp r3, r4 */
/* @0x2c6780 bgt 0x2c6764 <_ZN16b2BlockAllocator5ClearEv+0x18> */
/* @0x2c6784 ldr r2, [r5, #0x8] */
/* @0x2c6788 mov r6, r5 */
/* @0x2c678c ldr r0, [r6], #12 */
/* @0x2c6790 mov r4, #0 */
/* @0x2c6794 mov r1, r4 */
/* @0x2c6798 str r4, [r5, #0x4] */
/* @0x2c679c lsl r2, r2, #3 */
/* @0x2c67a0 bl 0xb65b0 <memset@plt> */
/* @0x2c67a4 mov r0, r6 */
/* @0x2c67a8 mov r1, r4 */
/* @0x2c67ac mov r2, #56 */
/* @0x2c67b0 pop {r4, r5, r6, lr} */
/* @0x2c67b4 b 0xb65b0 <memset@plt> */
