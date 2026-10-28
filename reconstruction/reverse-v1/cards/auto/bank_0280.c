/* libyoyo.so 覆盖卡组 0280
 * 函数 0x2d523c..0x2d8a20，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

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

/* ── FUNC 0x2d5580 · b2ParticleSystem::JoinParticleGroupsCallback::operator()(int, int, int) const · size=756 · insn=189 */
/* @0x2d5580 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2d5584 vpush {d8, d9, d10} */
/* @0x2d5588 mov r6, r0 */
/* @0x2d558c ldr r0, [r0, #0x8] */
/* @0x2d5590 mov r5, r2 */
/* @0x2d5594 mov r4, r1 */
/* @0x2d5598 sub sp, sp, #36 */
/* @0x2d559c ldr r2, [r0, #0x4] */
/* @0x2d55a0 cmp r2, r5 */
/* @0x2d55a4 movle r1, #0 */
/* @0x2d55a8 movgt r1, #1 */
/* @0x2d55ac cmp r2, r4 */
/* @0x2d55b0 addgt r1, r1, #1 */
/* @0x2d55b4 cmp r2, r3 */
/* @0x2d55b8 movgt r2, r1 */
/* @0x2d55bc suble r2, r1, #1 */
/* @0x2d55c0 cmp r2, #1 */
/* @0x2d55c4 bls 0x2d55d4 <_ZNK16b2ParticleSystem26JoinParticleGroupsCallbackclEiii+0x54> */
/* @0x2d55c8 add sp, sp, #36 */
/* @0x2d55cc vpop {d8, d9, d10} */
/* @0x2d55d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2d55d4 ldr r7, [r6] */
/* @0x2d55d8 ldr r2, [r7, #0x30] */
/* @0x2d55dc ldr r11, [r2, r3, lsl #2] */
/* @0x2d55e0 ldr r8, [r2, r5, lsl #2] */
/* @0x2d55e4 ldr r12, [r2, r4, lsl #2] */
/* @0x2d55e8 and r1, r11, #16 */
/* @0x2d55ec and r2, r1, r8 */
/* @0x2d55f0 tst r2, r12 */
/* @0x2d55f4 str r8, [sp, #0xc] */
/* @0x2d55f8 beq 0x2d55c8 <_ZNK16b2ParticleSystem26JoinParticleGroupsCallbackclEiii+0x48> */
/* @0x2d55fc ldr r9, [r7, #0x38] */
/* @0x2d5600 vmov.f32 s14, #4.000000e+00 */
/* @0x2d5604 vldr s9, [r7, #32] */
/* @0x2d5608 add r10, r9, r4, lsl #3 */
/* @0x2d560c add r8, r9, r5, lsl #3 */
/* @0x2d5610 vldr s10, [r10, #4] */
/* @0x2d5614 vldr s12, [r8, #4] */
/* @0x2d5618 vldr s11, [r10] */
/* @0x2d561c vldr s13, [r8] */
/* @0x2d5620 add r9, r9, r3, lsl #3 */
/* @0x2d5624 vldr s8, [r9] */
/* @0x2d5628 vldr s7, [r9, #4] */
/* @0x2d562c vsub.f32 s17, s10, s12 */
/* @0x2d5630 vmul.f32 s15, s17, s17 */
/* @0x2d5634 vsub.f32 s16, s11, s13 */
/* @0x2d5638 vmla.f32 s15, s16, s16 */
/* @0x2d563c vmul.f32 s14, s9, s14 */
/* @0x2d5640 vcmpe.f32 s14, s15 */
/* @0x2d5644 vmrs APSR_nzcv, fpscr */
/* @0x2d5648 ble 0x2d55c8 <_ZNK16b2ParticleSystem26JoinParticleGroupsCallbackclEiii+0x48> */
/* @0x2d564c vsub.f32 s19, s12, s7 */
/* @0x2d5650 vmul.f32 s9, s19, s19 */
/* @0x2d5654 vsub.f32 s18, s13, s8 */
/* @0x2d5658 vmla.f32 s9, s18, s18 */
/* @0x2d565c vcmpe.f32 s14, s9 */
/* @0x2d5660 vmrs APSR_nzcv, fpscr */
/* @0x2d5664 ble 0x2d55c8 <_ZNK16b2ParticleSystem26JoinParticleGroupsCallbackclEiii+0x48> */
/* @0x2d5668 vsub.f32 s21, s7, s10 */
/* @0x2d566c vmul.f32 s15, s21, s21 */
/* @0x2d5670 vsub.f32 s20, s8, s11 */
/* @0x2d5674 vmla.f32 s15, s20, s20 */
/* @0x2d5678 vcmpe.f32 s14, s15 */
/* @0x2d567c vmrs APSR_nzcv, fpscr */
/* @0x2d5680 ble 0x2d55c8 <_ZNK16b2ParticleSystem26JoinParticleGroupsCallbackclEiii+0x48> */
/* @0x2d5684 ldr r1, [r7, #0x9c] */
/* @0x2d5688 ldr r2, [r7, #0x98] */
/* @0x2d568c cmp r2, r1 */
/* @0x2d5690 str r1, [sp, #0x10] */
/* @0x2d5694 bge 0x2d57cc <_ZNK16b2ParticleSystem26JoinParticleGroupsCallbackclEiii+0x24c> */
/* @0x2d5698 vmov.f32 s14, s7 */
/* @0x2d569c str r0, [sp, #0x10] */
/* @0x2d56a0 vmov.f32 s15, s8 */
/* @0x2d56a4 vldr s5, [pc, #452] */
/* @0x2d56a8 rsb r0, r2, r2, lsl #4 */
/* @0x2d56ac ldr r1, [r6, #0x4] */
/* @0x2d56b0 vldr s6, [r1, #16] */
/* @0x2d56b4 vadd.f32 s13, s11, s13 */
/* @0x2d56b8 ldr r1, [r7, #0xa0] */
/* @0x2d56bc ldr r6, [sp, #0x10] */
/* @0x2d56c0 vldr s9, [r6, #16] */
/* @0x2d56c4 ldr r6, [sp, #0xc] */
/* @0x2d56c8 lsl r0, r0, #2 */
/* @0x2d56cc add r2, r2, #1 */
/* @0x2d56d0 orr r11, r6, r11 */
/* @0x2d56d4 str r4, [r1, r0] */
/* @0x2d56d8 orr r11, r11, r12 */
/* @0x2d56dc add r12, r1, r0 */
/* @0x2d56e0 str r11, [r12, #0xc] */
/* @0x2d56e4 str r5, [r12, #0x4] */
/* @0x2d56e8 str r3, [r12, #0x8] */
/* @0x2d56ec vadd.f32 s12, s10, s12 */
/* @0x2d56f0 vadd.f32 s15, s13, s15 */
/* @0x2d56f4 vadd.f32 s14, s12, s14 */
/* @0x2d56f8 vmul.f32 s15, s15, s5 */
/* @0x2d56fc vmul.f32 s14, s14, s5 */
/* @0x2d5700 vsub.f32 s11, s11, s15 */
/* @0x2d5704 vsub.f32 s10, s10, s14 */
/* @0x2d5708 vstr s11, [r12, #20] */
/* @0x2d570c vstr s10, [r12, #24] */
/* @0x2d5710 vldr s12, [r8, #4] */
/* @0x2d5714 vldr s13, [r8] */
/* @0x2d5718 vsub.f32 s12, s12, s14 */
/* @0x2d571c vsub.f32 s13, s13, s15 */
/* @0x2d5720 vstr s12, [r12, #32] */
/* @0x2d5724 vstr s13, [r12, #28] */
/* @0x2d5728 vldr s12, [r9, #4] */
/* @0x2d572c vldr s13, [r9] */
/* @0x2d5730 vsub.f32 s14, s12, s14 */
/* @0x2d5734 vsub.f32 s15, s13, s15 */
/* @0x2d5738 vstr s14, [r12, #40] */
/* @0x2d573c vstr s15, [r12, #36] */
/* @0x2d5740 vldr s7, [r8, #4] */
/* @0x2d5744 vldr s11, [r9] */
/* @0x2d5748 vldr s10, [r10, #4] */
/* @0x2d574c vldr s8, [r8] */
/* @0x2d5750 vmul.f32 s13, s7, s11 */
/* @0x2d5754 vldr s15, [r9, #4] */
/* @0x2d5758 vldr s5, [r10] */
/* @0x2d575c vmul.f32 s12, s10, s8 */
/* @0x2d5760 vmul.f32 s14, s5, s15 */
/* @0x2d5764 vnmls.f32 s13, s8, s15 */
/* @0x2d5768 vnmls.f32 s12, s5, s7 */
/* @0x2d576c vmul.f32 s15, s17, s21 */
/* @0x2d5770 vmul.f32 s17, s17, s19 */
/* @0x2d5774 vmul.f32 s19, s19, s21 */
/* @0x2d5778 vnmls.f32 s14, s10, s11 */
/* @0x2d577c vmla.f32 s15, s16, s20 */
/* @0x2d5780 vmla.f32 s17, s16, s18 */
/* @0x2d5784 vmla.f32 s19, s18, s20 */
/* @0x2d5788 vadd.f32 s13, s12, s13 */
/* @0x2d578c vadd.f32 s14, s13, s14 */
/* @0x2d5790 vcmpe.f32 s6, s9 */
/* @0x2d5794 vstr s14, [r12, #56] */
/* @0x2d5798 vneg.f32 s15, s15 */
/* @0x2d579c vmrs APSR_nzcv, fpscr */
/* @0x2d57a0 vneg.f32 s17, s17 */
/* @0x2d57a4 vstr s15, [r12, #44] */
/* @0x2d57a8 vneg.f32 s19, s19 */
/* @0x2d57ac vstr s17, [r12, #48] */
/* @0x2d57b0 vmovmi.f32 s9, s6 */
/* @0x2d57b4 vstr s19, [r12, #52] */
/* @0x2d57b8 vstr s9, [r12, #16] */
/* @0x2d57bc str r2, [r7, #0x98] */
/* @0x2d57c0 add sp, sp, #36 */
/* @0x2d57c4 vpop {d8, d9, d10} */
/* @0x2d57c8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2d57cc cmp r2, #0 */
/* @0x2d57d0 lslne lr, r2, #1 */
/* @0x2d57d4 strne lr, [sp, #0x18] */
/* @0x2d57d8 rsbne r2, lr, r2, lsl #5 */
/* @0x2d57dc moveq r0, #256 */
/* @0x2d57e0 moveq r1, #15360 */
/* @0x2d57e4 streq r0, [sp, #0x18] */
/* @0x2d57e8 lslne r1, r2, #2 */
/* @0x2d57ec ldr r2, [r7, #0xa0] */
/* @0x2d57f0 ldr r0, [r7, #0xd4] */
/* @0x2d57f4 stmib sp, {r3, r12} */
/* @0x2d57f8 str r2, [sp, #0x14] */
/* @0x2d57fc bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2d5800 ldr lr, [sp, #0x10] */
/* @0x2d5804 ldr r1, [sp, #0x14] */
/* @0x2d5808 rsb r2, lr, lr, lsl #4 */
/* @0x2d580c lsl r2, r2, #2 */
/* @0x2d5810 str r2, [sp, #0x10] */
/* @0x2d5814 str r0, [sp, #0x1c] */
/* @0x2d5818 bl 0xb65bc <memcpy@plt> */
/* @0x2d581c ldr r0, [r7, #0xd4] */
/* @0x2d5820 ldr r2, [sp, #0x10] */
/* @0x2d5824 ldr r1, [sp, #0x14] */
/* @0x2d5828 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2d582c ldr r0, [r6, #0x8] */
/* @0x2d5830 ldr r1, [r6] */
/* @0x2d5834 vldr s11, [r10] */
/* @0x2d5838 ldr r2, [sp, #0x1c] */
/* @0x2d583c vldr s13, [r8] */
/* @0x2d5840 str r0, [sp, #0x10] */
/* @0x2d5844 vldr s10, [r10, #4] */
/* @0x2d5848 ldr r0, [sp, #0x18] */
/* @0x2d584c vldr s12, [r8, #4] */
/* @0x2d5850 str r2, [r7, #0xa0] */
/* @0x2d5854 vldr s15, [r9] */
/* @0x2d5858 ldr r2, [r1, #0x98] */
/* @0x2d585c mov r7, r1 */
/* @0x2d5860 str r0, [r1, #0x9c] */
/* @0x2d5864 vldr s14, [r9, #4] */
/* @0x2d5868 ldmib sp, {r3, r12} */
/* @0x2d586c b 0x2d56a4 <_ZNK16b2ParticleSystem26JoinParticleGroupsCallbackclEiii+0x124> */
/* @0x2d5870 .word 0x3eaaaaab */

/* ── FUNC 0x2d5874 · b2ParticleSystem::DestroyParticleGroup(b2ParticleGroup*) · size=172 · insn=43 */
/* @0x2d5874 ldr r2, [r0, #0xd4] */
/* @0x2d5878 movw r3, #0x9244 */
/* @0x2d587c movt r3, #0x1 */
/* @0x2d5880 push {r4, r5, r6, lr} */
/* @0x2d5884 mov r4, r0 */
/* @0x2d5888 ldr r0, [r2, r3] */
/* @0x2d588c mov r6, r1 */
/* @0x2d5890 cmp r0, #0 */
/* @0x2d5894 beq 0x2d58a4 <_ZN16b2ParticleSystem20DestroyParticleGroupEP15b2ParticleGroup+0x30> */
/* @0x2d5898 ldr r3, [r0] */
/* @0x2d589c ldr r3, [r3, #0x10] */
/* @0x2d58a0 blx r3 */
/* @0x2d58a4 ldmib r6, {r3, lr} */
/* @0x2d58a8 cmp r3, lr */
/* @0x2d58ac lsllt r2, r3, #2 */
/* @0x2d58b0 movlt r5, #0 */
/* @0x2d58b4 bge 0x2d58d0 <_ZN16b2ParticleSystem20DestroyParticleGroupEP15b2ParticleGroup+0x5c> */
/* @0x2d58b8 add r3, r3, #1 */
/* @0x2d58bc ldr r12, [r4, #0x5c] */
/* @0x2d58c0 cmp r3, lr */
/* @0x2d58c4 str r5, [r12, r2] */
/* @0x2d58c8 add r2, r2, #4 */
/* @0x2d58cc bne 0x2d58b8 <_ZN16b2ParticleSystem20DestroyParticleGroupEP15b2ParticleGroup+0x44> */
/* @0x2d58d0 ldr r3, [r6, #0x14] */
/* @0x2d58d4 cmp r3, #0 */
/* @0x2d58d8 ldrne r2, [r6, #0x18] */
/* @0x2d58dc strne r2, [r3, #0x18] */
/* @0x2d58e0 ldr r2, [r6, #0x18] */
/* @0x2d58e4 mov r0, r6 */
/* @0x2d58e8 cmp r2, #0 */
/* @0x2d58ec strne r3, [r2, #0x14] */
/* @0x2d58f0 ldr r3, [r4, #0xa8] */
/* @0x2d58f4 cmp r3, r6 */
/* @0x2d58f8 ldr r3, [r4, #0xa4] */
/* @0x2d58fc streq r2, [r4, #0xa8] */
/* @0x2d5900 sub r3, r3, #1 */
/* @0x2d5904 str r3, [r4, #0xa4] */
/* @0x2d5908 bl 0x2d45f8 <_ZN15b2ParticleGroupD2Ev> */
/* @0x2d590c ldr r0, [r4, #0xd4] */
/* @0x2d5910 mov r1, r6 */
/* @0x2d5914 mov r2, #84 */
/* @0x2d5918 pop {r4, r5, r6, lr} */
/* @0x2d591c b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */

/* ── FUNC 0x2d5920 · b2ParticleSystem::ComputeDepthForGroup(b2ParticleGroup*) · size=636 · insn=159 */
/* @0x2d5920 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2d5924 mov r4, r1 */
/* @0x2d5928 ldmib r1, {r1, r5} */
/* @0x2d592c sub sp, sp, #12 */
/* @0x2d5930 mov r9, r0 */
/* @0x2d5934 cmp r1, r5 */
/* @0x2d5938 bge 0x2d5958 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x38> */
/* @0x2d593c ldr r2, [r0, #0x48] */
/* @0x2d5940 mov r0, #0 */
/* @0x2d5944 add r3, r2, r1, lsl #2 */
/* @0x2d5948 add r2, r2, r5, lsl #2 */
/* @0x2d594c str r0, [r3], #4 */
/* @0x2d5950 cmp r3, r2 */
/* @0x2d5954 bne 0x2d594c <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x2c> */
/* @0x2d5958 ldr r12, [r9, #0x74] */
/* @0x2d595c cmp r12, #0 */
/* @0x2d5960 ble 0x2d59d0 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0xb0> */
/* @0x2d5964 ldr r3, [r9, #0x7c] */
/* @0x2d5968 add r12, r12, r12, lsl #1 */
/* @0x2d596c add r3, r3, #12 */
/* @0x2d5970 add r12, r3, r12, lsl #3 */
/* @0x2d5974 ldr r2, [r3, #-0xc] */
/* @0x2d5978 ldr r0, [r3, #-0x8] */
/* @0x2d597c cmp r1, r2 */
/* @0x2d5980 bgt 0x2d59c4 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0xa4> */
/* @0x2d5984 cmp r2, r5 */
/* @0x2d5988 bge 0x2d59c4 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0xa4> */
/* @0x2d598c cmp r1, r0 */
/* @0x2d5990 bgt 0x2d59c4 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0xa4> */
/* @0x2d5994 cmp r0, r5 */
/* @0x2d5998 bge 0x2d59c4 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0xa4> */
/* @0x2d599c ldr r6, [r9, #0x48] */
/* @0x2d59a0 vldr s15, [r3] */
/* @0x2d59a4 add r2, r6, r2, lsl #2 */
/* @0x2d59a8 vldr s14, [r2] */
/* @0x2d59ac vadd.f32 s14, s14, s15 */
/* @0x2d59b0 add r0, r6, r0, lsl #2 */
/* @0x2d59b4 vstr s14, [r2] */
/* @0x2d59b8 vldr s14, [r0] */
/* @0x2d59bc vadd.f32 s15, s14, s15 */
/* @0x2d59c0 vstr s15, [r0] */
/* @0x2d59c4 add r3, r3, #24 */
/* @0x2d59c8 cmp r3, r12 */
/* @0x2d59cc bne 0x2d5974 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x54> */
/* @0x2d59d0 ldr r6, [r9, #0x50] */
/* @0x2d59d4 cmp r6, #0 */
/* @0x2d59d8 beq 0x2d5aac <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x18c> */
/* @0x2d59dc str r1, [sp, #0x4] */
/* @0x2d59e0 ldr r3, [sp, #0x4] */
/* @0x2d59e4 str r6, [r9, #0x50] */
/* @0x2d59e8 cmp r5, r3 */
/* @0x2d59ec ble 0x2d5aa4 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x184> */
/* @0x2d59f0 ldr r0, [r9, #0x48] */
/* @0x2d59f4 lsl r3, r3, #2 */
/* @0x2d59f8 add r2, r6, r3 */
/* @0x2d59fc vldr s12, [pc, #396] */
/* @0x2d5a00 add r1, r0, r5, lsl #2 */
/* @0x2d5a04 add r3, r0, r3 */
/* @0x2d5a08 vldr s13, [pc, #388] */
/* @0x2d5a0c vldr s14, [pc, #388] */
/* @0x2d5a10 vldmia r3!, {s15} */
/* @0x2d5a14 vcmpe.f32 s15, s12 */
/* @0x2d5a18 vmrs APSR_nzcv, fpscr */
/* @0x2d5a1c vmovpl.f32 s15, s14 */
/* @0x2d5a20 vmovmi.f32 s15, s13 */
/* @0x2d5a24 cmp r3, r1 */
/* @0x2d5a28 vstmia r2!, {s15} */
/* @0x2d5a2c bne 0x2d5a10 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0xf0> */
/* @0x2d5a30 ldr r12, [r4, #0x4] */
/* @0x2d5a34 ldr r5, [r4, #0x8] */
/* @0x2d5a38 rsb r10, r12, r5 */
/* @0x2d5a3c cmp r10, #0 */
/* @0x2d5a40 ble 0x2d5a58 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x138> */
/* @0x2d5a44 ldr r3, [r9, #0x74] */
/* @0x2d5a48 cmp r3, #0 */
/* @0x2d5a4c add r3, r3, r3, lsl #1 */
/* @0x2d5a50 lsl r4, r3, #3 */
/* @0x2d5a54 bgt 0x2d5ae0 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x1c0> */
/* @0x2d5a58 ldr r3, [sp, #0x4] */
/* @0x2d5a5c cmp r5, r3 */
/* @0x2d5a60 ble 0x2d5a9c <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x17c> */
/* @0x2d5a64 ldr r2, [sp, #0x4] */
/* @0x2d5a68 add r5, r6, r5, lsl #2 */
/* @0x2d5a6c vldr s14, [pc, #292] */
/* @0x2d5a70 add r3, r6, r2, lsl #2 */
/* @0x2d5a74 mov r2, #0 */
/* @0x2d5a78 vldmia r3!, {s15} */
/* @0x2d5a7c vcmpe.f32 s15, s14 */
/* @0x2d5a80 vmrs APSR_nzcv, fpscr */
/* @0x2d5a84 vldrmi s13, [r9, #24] */
/* @0x2d5a88 vmulmi.f32 s15, s15, s13 */
/* @0x2d5a8c strpl r2, [r3, #-0x4] */
/* @0x2d5a90 vstrmi s15, [r3, #-4] */
/* @0x2d5a94 cmp r3, r5 */
/* @0x2d5a98 bne 0x2d5a78 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x158> */
/* @0x2d5a9c add sp, sp, #12 */
/* @0x2d5aa0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2d5aa4 ldr r12, [sp, #0x4] */
/* @0x2d5aa8 b 0x2d5a38 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x118> */
/* @0x2d5aac ldr r1, [r9, #0x28] */
/* @0x2d5ab0 ldr r0, [r9, #0xd4] */
/* @0x2d5ab4 lsl r1, r1, #2 */
/* @0x2d5ab8 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2d5abc ldr r2, [r9, #0x28] */
/* @0x2d5ac0 mov r1, #0 */
/* @0x2d5ac4 lsl r2, r2, #2 */
/* @0x2d5ac8 mov r6, r0 */
/* @0x2d5acc bl 0xb65b0 <memset@plt> */
/* @0x2d5ad0 ldr r2, [r4, #0x4] */
/* @0x2d5ad4 ldr r5, [r4, #0x8] */
/* @0x2d5ad8 str r2, [sp, #0x4] */
/* @0x2d5adc b 0x2d59e0 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0xc0> */
/* @0x2d5ae0 vmov.f32 s11, #1.000000e+00 */
/* @0x2d5ae4 ldr r3, [r9, #0x7c] */
/* @0x2d5ae8 mov r7, #0 */
/* @0x2d5aec add r11, r3, #12 */
/* @0x2d5af0 add r4, r11, r4 */
/* @0x2d5af4 mov r3, r11 */
/* @0x2d5af8 mov r8, #0 */
/* @0x2d5afc ldr r2, [r3, #-0xc] */
/* @0x2d5b00 ldr r1, [r3, #-0x8] */
/* @0x2d5b04 cmp r2, r12 */
/* @0x2d5b08 blt 0x2d5b6c <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x24c> */
/* @0x2d5b0c cmp r2, r5 */
/* @0x2d5b10 bge 0x2d5b6c <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x24c> */
/* @0x2d5b14 cmp r1, r12 */
/* @0x2d5b18 blt 0x2d5b6c <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x24c> */
/* @0x2d5b1c cmp r1, r5 */
/* @0x2d5b20 add r0, r6, r1, lsl #2 */
/* @0x2d5b24 add r2, r6, r2, lsl #2 */
/* @0x2d5b28 bge 0x2d5b6c <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x24c> */
/* @0x2d5b2c vldr s15, [r3] */
/* @0x2d5b30 vsub.f32 s15, s11, s15 */
/* @0x2d5b34 vldr s13, [r0] */
/* @0x2d5b38 vldr s14, [r2] */
/* @0x2d5b3c vmov.f32 s12, s13 */
/* @0x2d5b40 vadd.f32 s13, s13, s15 */
/* @0x2d5b44 vadd.f32 s15, s14, s15 */
/* @0x2d5b48 vcmpe.f32 s13, s14 */
/* @0x2d5b4c vmrs APSR_nzcv, fpscr */
/* @0x2d5b50 vstrmi s13, [r2] */
/* @0x2d5b54 vldrmi s12, [r0] */
/* @0x2d5b58 vcmpe.f32 s15, s12 */
/* @0x2d5b5c movmi r8, #1 */
/* @0x2d5b60 vmrs APSR_nzcv, fpscr */
/* @0x2d5b64 movmi r8, #1 */
/* @0x2d5b68 vstrmi s15, [r0] */
/* @0x2d5b6c add r3, r3, #24 */
/* @0x2d5b70 cmp r3, r4 */
/* @0x2d5b74 bne 0x2d5afc <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x1dc> */
/* @0x2d5b78 cmp r8, #0 */
/* @0x2d5b7c beq 0x2d5a58 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x138> */
/* @0x2d5b80 add r7, r7, #1 */
/* @0x2d5b84 cmp r7, r10 */
/* @0x2d5b88 bne 0x2d5af4 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x1d4> */
/* @0x2d5b8c b 0x2d5a58 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x138> */
/* @0x2d5b90 svclo #0x4ccccd */
/* @0x2d5b94 andeq r0, r0, r0 */
/* @0x2d5b98 svcvc #0x7fffff */

/* ── FUNC 0x2d5b9c · b2ParticleSystem::UpdateBodyContacts() · size=292 · insn=73 */
/* @0x2d5b9c ldr r2, [r0, #0x24] */
/* @0x2d5ba0 vldr s13, [pc, #268] */
/* @0x2d5ba4 str lr, [sp, #-0x4]! */
/* @0x2d5ba8 vldr s12, [pc, #264] */
/* @0x2d5bac cmp r2, #0 */
/* @0x2d5bb0 sub sp, sp, #28 */
/* @0x2d5bb4 mov r12, r0 */
/* @0x2d5bb8 vstr s13, [sp, #8] */
/* @0x2d5bbc vstr s13, [sp, #12] */
/* @0x2d5bc0 vstr s12, [sp, #16] */
/* @0x2d5bc4 vstr s12, [sp, #20] */
/* @0x2d5bc8 ble 0x2d5ca0 <_ZN16b2ParticleSystem18UpdateBodyContactsEv+0x104> */
/* @0x2d5bcc ldr r3, [r0, #0x38] */
/* @0x2d5bd0 vmov.f32 s8, s12 */
/* @0x2d5bd4 add r2, r3, r2, lsl #3 */
/* @0x2d5bd8 vmov.f32 s9, s13 */
/* @0x2d5bdc vldr s14, [r3] */
/* @0x2d5be0 vldr s15, [r3, #4] */
/* @0x2d5be4 add r3, r3, #8 */
/* @0x2d5be8 vcmpe.f32 s14, s9 */
/* @0x2d5bec vmrs APSR_nzcv, fpscr */
/* @0x2d5bf0 vcmpe.f32 s15, s13 */
/* @0x2d5bf4 vmovle.f32 s11, s14 */
/* @0x2d5bf8 vmovgt.f32 s11, s9 */
/* @0x2d5bfc vmrs APSR_nzcv, fpscr */
/* @0x2d5c00 vstr s11, [sp, #8] */
/* @0x2d5c04 vcmpe.f32 s14, s8 */
/* @0x2d5c08 vmovle.f32 s10, s15 */
/* @0x2d5c0c vmovgt.f32 s10, s13 */
/* @0x2d5c10 vmrs APSR_nzcv, fpscr */
/* @0x2d5c14 vstr s10, [sp, #12] */
/* @0x2d5c18 vcmpe.f32 s15, s12 */
/* @0x2d5c1c vmovmi.f32 s14, s8 */
/* @0x2d5c20 vmrs APSR_nzcv, fpscr */
/* @0x2d5c24 vstr s14, [sp, #16] */
/* @0x2d5c28 vmovmi.f32 s15, s12 */
/* @0x2d5c2c cmp r3, r2 */
/* @0x2d5c30 vstr s15, [sp, #20] */
/* @0x2d5c34 vmov.f32 s9, s11 */
/* @0x2d5c38 vmov.f32 s13, s10 */
/* @0x2d5c3c vmov.f32 s8, s14 */
/* @0x2d5c40 vmov.f32 s12, s15 */
/* @0x2d5c44 bne 0x2d5bdc <_ZN16b2ParticleSystem18UpdateBodyContactsEv+0x40> */
/* @0x2d5c48 vldr s9, [r12, #24] */
/* @0x2d5c4c vsub.f32 s11, s11, s9 */
/* @0x2d5c50 ldr r3, [pc, #0x64] */
/* @0x2d5c54 mov r2, #0 */
/* @0x2d5c58 ldr r0, [r12, #0xd4] */
/* @0x2d5c5c mov r1, sp */
/* @0x2d5c60 str r2, [r12, #0x80] */
/* @0x2d5c64 add r3, pc, r3 */
/* @0x2d5c68 add r2, sp, #8 */
/* @0x2d5c6c add r3, r3, #32 */
/* @0x2d5c70 str r12, [sp, #0x4] */
/* @0x2d5c74 str r3, [sp] */
/* @0x2d5c78 vsub.f32 s10, s10, s9 */
/* @0x2d5c7c vstr s11, [sp, #8] */
/* @0x2d5c80 vadd.f32 s14, s9, s14 */
/* @0x2d5c84 vstr s10, [sp, #12] */
/* @0x2d5c88 vadd.f32 s15, s9, s15 */
/* @0x2d5c8c vstr s14, [sp, #16] */
/* @0x2d5c90 vstr s15, [sp, #20] */
/* @0x2d5c94 bl 0x2cb89c <_ZNK7b2World9QueryAABBEP15b2QueryCallbackRK6b2AABB> */
/* @0x2d5c98 add sp, sp, #28 */
/* @0x2d5c9c ldr pc, [sp], #4 */
/* @0x2d5ca0 vmov.f32 s15, s12 */
/* @0x2d5ca4 vmov.f32 s10, s13 */
/* @0x2d5ca8 vmov.f32 s14, s12 */
/* @0x2d5cac vmov.f32 s11, s13 */
/* @0x2d5cb0 b 0x2d5c48 <_ZN16b2ParticleSystem18UpdateBodyContactsEv+0xac> */
/* @0x2d5cb4 svcvc #0x7fffff */
/* @0x2d5cb8 .word 0xff7fffff */
/* @0x2d5cbc andseq r6, r1, r4, asr #20 */

/* ── FUNC 0x2d5cc0 · b2ParticleSystem::SolveCollision(b2TimeStep const&) · size=328 · insn=82 */
/* @0x2d5cc0 ldr r12, [r0, #0x24] */
/* @0x2d5cc4 vldr s11, [pc, #304] */
/* @0x2d5cc8 push {r4, r5, lr} */
/* @0x2d5ccc vldr s10, [pc, #300] */
/* @0x2d5cd0 cmp r12, #0 */
/* @0x2d5cd4 sub sp, sp, #52 */
/* @0x2d5cd8 mov r4, r0 */
/* @0x2d5cdc vstr s11, [sp] */
/* @0x2d5ce0 vstr s11, [sp, #4] */
/* @0x2d5ce4 vstr s10, [sp, #8] */
/* @0x2d5ce8 vstr s10, [sp, #12] */
/* @0x2d5cec ble 0x2d5db8 <_ZN16b2ParticleSystem14SolveCollisionERK10b2TimeStep+0xf8> */
/* @0x2d5cf0 ldr r3, [r0, #0x40] */
/* @0x2d5cf4 vmov.f32 s8, s10 */
/* @0x2d5cf8 ldr r2, [r0, #0x38] */
/* @0x2d5cfc vldr s5, [r1] */
/* @0x2d5d00 add r12, r3, r12, lsl #3 */
/* @0x2d5d04 vmov.f32 s9, s11 */
/* @0x2d5d08 vldr s14, [r2] */
/* @0x2d5d0c vldr s15, [r3] */
/* @0x2d5d10 vldr s13, [r3, #4] */
/* @0x2d5d14 add r3, r3, #8 */
/* @0x2d5d18 vmov.f32 s12, s14 */
/* @0x2d5d1c add r2, r2, #8 */
/* @0x2d5d20 vmla.f32 s12, s5, s15 */
/* @0x2d5d24 vldr s15, [r2, #-4] */
/* @0x2d5d28 vmov.f32 s7, s15 */
/* @0x2d5d2c vmla.f32 s7, s5, s13 */
/* @0x2d5d30 vcmpe.f32 s12, s14 */
/* @0x2d5d34 vmrs APSR_nzcv, fpscr */
/* @0x2d5d38 vcmpe.f32 s7, s15 */
/* @0x2d5d3c vmovle.f32 s6, s12 */
/* @0x2d5d40 vmovgt.f32 s6, s14 */
/* @0x2d5d44 vmrs APSR_nzcv, fpscr */
/* @0x2d5d48 vmov.f32 s13, s7 */
/* @0x2d5d4c vcmpe.f32 s6, s9 */
/* @0x2d5d50 vmovgt.f32 s7, s15 */
/* @0x2d5d54 vmrs APSR_nzcv, fpscr */
/* @0x2d5d58 vcmpe.f32 s7, s11 */
/* @0x2d5d5c vmovle.f32 s9, s6 */
/* @0x2d5d60 vmrs APSR_nzcv, fpscr */
/* @0x2d5d64 vstr s9, [sp] */
/* @0x2d5d68 vcmpe.f32 s12, s14 */
/* @0x2d5d6c vmovle.f32 s11, s7 */
/* @0x2d5d70 vmrs APSR_nzcv, fpscr */
/* @0x2d5d74 vstr s11, [sp, #4] */
/* @0x2d5d78 vcmpe.f32 s13, s15 */
/* @0x2d5d7c vmovpl.f32 s14, s12 */
/* @0x2d5d80 vmrs APSR_nzcv, fpscr */
/* @0x2d5d84 vcmpe.f32 s14, s8 */
/* @0x2d5d88 vmovpl.f32 s15, s13 */
/* @0x2d5d8c vmrs APSR_nzcv, fpscr */
/* @0x2d5d90 vcmpe.f32 s15, s10 */
/* @0x2d5d94 vmovmi.f32 s14, s8 */
/* @0x2d5d98 vmrs APSR_nzcv, fpscr */
/* @0x2d5d9c vstr s14, [sp, #8] */
/* @0x2d5da0 vmovmi.f32 s15, s10 */
/* @0x2d5da4 cmp r3, r12 */
/* @0x2d5da8 vstr s15, [sp, #12] */
/* @0x2d5dac vmov.f32 s8, s14 */
/* @0x2d5db0 vmov.f32 s10, s15 */
/* @0x2d5db4 bne 0x2d5d08 <_ZN16b2ParticleSystem14SolveCollisionERK10b2TimeStep+0x48> */
/* @0x2d5db8 mov lr, r1 */
/* @0x2d5dbc add r12, sp, #24 */
/* @0x2d5dc0 ldm lr!, {r0, r1, r2, r3} */
/* @0x2d5dc4 ldr r5, [pc, #0x38] */
/* @0x2d5dc8 str r4, [sp, #0x14] */
/* @0x2d5dcc add r5, pc, r5 */
/* @0x2d5dd0 stm r12!, {r0, r1, r2, r3} */
/* @0x2d5dd4 mov r2, sp */
/* @0x2d5dd8 ldm lr, {r0, r1} */
/* @0x2d5ddc add r5, r5, #8 */
/* @0x2d5de0 str r5, [sp, #0x10] */
/* @0x2d5de4 stm r12, {r0, r1} */
/* @0x2d5de8 add r1, sp, #16 */
/* @0x2d5dec ldr r0, [r4, #0xd4] */
/* @0x2d5df0 bl 0x2cb89c <_ZNK7b2World9QueryAABBEP15b2QueryCallbackRK6b2AABB> */
/* @0x2d5df4 add sp, sp, #52 */
/* @0x2d5df8 pop {r4, r5, pc} */
/* @0x2d5dfc svcvc #0x7fffff */
/* @0x2d5e00 .word 0xff7fffff */
/* @0x2d5e04 ldrsbeq r6, [r1], -r12 */

/* ── FUNC 0x2d5e08 · b2ParticleSystem::SolveWall(b2TimeStep const&) · size=76 · insn=19 */
/* @0x2d5e08 ldr r1, [r0, #0x24] */
/* @0x2d5e0c str r4, [sp, #-0x4]! */
/* @0x2d5e10 cmp r1, #0 */
/* @0x2d5e14 ble 0x2d5e4c <_ZN16b2ParticleSystem9SolveWallERK10b2TimeStep+0x44> */
/* @0x2d5e18 ldr r12, [r0, #0x30] */
/* @0x2d5e1c lsl r1, r1, #2 */
/* @0x2d5e20 mov r3, #0 */
/* @0x2d5e24 mov r4, #0 */
/* @0x2d5e28 ldr r2, [r12, r3] */
/* @0x2d5e2c tst r2, #4 */
/* @0x2d5e30 ldrne r2, [r0, #0x40] */
/* @0x2d5e34 addne r2, r2, r3, lsl #1 */
/* @0x2d5e38 add r3, r3, #4 */
/* @0x2d5e3c strne r4, [r2] */
/* @0x2d5e40 strne r4, [r2, #0x4] */
/* @0x2d5e44 cmp r3, r1 */
/* @0x2d5e48 bne 0x2d5e28 <_ZN16b2ParticleSystem9SolveWallERK10b2TimeStep+0x20> */
/* @0x2d5e4c ldr r4, [sp], #4 */
/* @0x2d5e50 bx lr */

/* ── FUNC 0x2d5e54 · b2ParticleSystem::SolveRigid(b2TimeStep const&) · size=364 · insn=91 */
/* @0x2d5e54 push {r4, r5, r6, lr} */
/* @0x2d5e58 vpush {d8, d9} */
/* @0x2d5e5c mov r6, r0 */
/* @0x2d5e60 ldr r4, [r0, #0xa8] */
/* @0x2d5e64 mov r5, r1 */
/* @0x2d5e68 cmp r4, #0 */
/* @0x2d5e6c beq 0x2d5fb8 <_ZN16b2ParticleSystem10SolveRigidERK10b2TimeStep+0x164> */
/* @0x2d5e70 vmov.f32 s18, #1.000000e+00 */
/* @0x2d5e74 b 0x2d5e84 <_ZN16b2ParticleSystem10SolveRigidERK10b2TimeStep+0x30> */
/* @0x2d5e78 ldr r4, [r4, #0x18] */
/* @0x2d5e7c cmp r4, #0 */
/* @0x2d5e80 beq 0x2d5fb8 <_ZN16b2ParticleSystem10SolveRigidERK10b2TimeStep+0x164> */
/* @0x2d5e84 ldr r3, [r4, #0xc] */
/* @0x2d5e88 tst r3, #2 */
/* @0x2d5e8c beq 0x2d5e78 <_ZN16b2ParticleSystem10SolveRigidERK10b2TimeStep+0x24> */
/* @0x2d5e90 mov r0, r4 */
/* @0x2d5e94 bl 0x2d4644 <_ZNK15b2ParticleGroup16UpdateStatisticsEv> */
/* @0x2d5e98 vldr s17, [r5] */
/* @0x2d5e9c vldr s19, [r4, #56] */
/* @0x2d5ea0 vmul.f32 s19, s17, s19 */
/* @0x2d5ea4 vmov r0, s19 */
/* @0x2d5ea8 bl 0xb6580 <sinf@plt> */
/* @0x2d5eac vmov s16, r0 */
/* @0x2d5eb0 vmov r0, s19 */
/* @0x2d5eb4 bl 0xb658c <cosf@plt> */
/* @0x2d5eb8 vldr s9, [r4, #44] */
/* @0x2d5ebc vmul.f32 s10, s9, s16 */
/* @0x2d5ec0 vldr s7, [r4, #40] */
/* @0x2d5ec4 vldr s15, [r4, #64] */
/* @0x2d5ec8 vldr s4, [r4, #48] */
/* @0x2d5ecc vldr s3, [r4, #52] */
/* @0x2d5ed0 vldr s8, [r4, #68] */
/* @0x2d5ed4 vldr s5, [r4, #60] */
/* @0x2d5ed8 vldr s6, [r4, #72] */
/* @0x2d5edc ldmib r4, {r2, r12} */
/* @0x2d5ee0 vldr s12, [r5, #4] */
/* @0x2d5ee4 cmp r2, r12 */
/* @0x2d5ee8 vmov.f32 s2, s7 */
/* @0x2d5eec vmul.f32 s14, s16, s15 */
/* @0x2d5ef0 vmla.f32 s2, s17, s4 */
/* @0x2d5ef4 vmov s11, r0 */
/* @0x2d5ef8 vmul.f32 s13, s9, s11 */
/* @0x2d5efc vmul.f32 s15, s11, s15 */
/* @0x2d5f00 vnmls.f32 s10, s7, s11 */
/* @0x2d5f04 vmla.f32 s13, s7, s16 */
/* @0x2d5f08 vmla.f32 s9, s17, s3 */
/* @0x2d5f0c vmul.f32 s7, s11, s8 */
/* @0x2d5f10 vmul.f32 s8, s16, s8 */
/* @0x2d5f14 vnmls.f32 s14, s11, s5 */
/* @0x2d5f18 vmla.f32 s15, s16, s5 */
/* @0x2d5f1c vnmls.f32 s8, s11, s6 */
/* @0x2d5f20 vmla.f32 s7, s16, s6 */
/* @0x2d5f24 vstr s8, [r4, #72] */
/* @0x2d5f28 vsub.f32 s10, s2, s10 */
/* @0x2d5f2c vstr s7, [r4, #68] */
/* @0x2d5f30 vsub.f32 s9, s9, s13 */
/* @0x2d5f34 vadd.f32 s14, s10, s14 */
/* @0x2d5f38 vadd.f32 s15, s9, s15 */
/* @0x2d5f3c vstr s14, [r4, #60] */
/* @0x2d5f40 vsub.f32 s11, s11, s18 */
/* @0x2d5f44 vstr s15, [r4, #64] */
/* @0x2d5f48 vmul.f32 s10, s12, s10 */
/* @0x2d5f4c vmul.f32 s9, s12, s9 */
/* @0x2d5f50 vmul.f32 s11, s12, s11 */
/* @0x2d5f54 vmul.f32 s12, s12, s16 */
/* @0x2d5f58 bge 0x2d5e78 <_ZN16b2ParticleSystem10SolveRigidERK10b2TimeStep+0x24> */
/* @0x2d5f5c ldr r3, [r6, #0x38] */
/* @0x2d5f60 lsl r2, r2, #3 */
/* @0x2d5f64 ldr r1, [r6, #0x40] */
/* @0x2d5f68 add r12, r3, r12, lsl #3 */
/* @0x2d5f6c add r3, r3, r2 */
/* @0x2d5f70 add r2, r1, r2 */
/* @0x2d5f74 vldr s15, [r3, #4] */
/* @0x2d5f78 vldr s13, [r3] */
/* @0x2d5f7c add r3, r3, #8 */
/* @0x2d5f80 add r2, r2, #8 */
/* @0x2d5f84 cmp r3, r12 */
/* @0x2d5f88 vmul.f32 s14, s12, s15 */
/* @0x2d5f8c vmul.f32 s15, s11, s15 */
/* @0x2d5f90 vnmls.f32 s14, s11, s13 */
/* @0x2d5f94 vmla.f32 s15, s12, s13 */
/* @0x2d5f98 vadd.f32 s14, s10, s14 */
/* @0x2d5f9c vadd.f32 s15, s9, s15 */
/* @0x2d5fa0 vstr s14, [r2, #-8] */
/* @0x2d5fa4 vstr s15, [r2, #-4] */
/* @0x2d5fa8 bne 0x2d5f74 <_ZN16b2ParticleSystem10SolveRigidERK10b2TimeStep+0x120> */
/* @0x2d5fac ldr r4, [r4, #0x18] */
/* @0x2d5fb0 cmp r4, #0 */
/* @0x2d5fb4 bne 0x2d5e84 <_ZN16b2ParticleSystem10SolveRigidERK10b2TimeStep+0x30> */
/* @0x2d5fb8 vpop {d8, d9} */
/* @0x2d5fbc pop {r4, r5, r6, pc} */

/* ── FUNC 0x2d5fc0 · b2ParticleSystem::SolveElastic(b2TimeStep const&) · size=588 · insn=147 */
/* @0x2d5fc0 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2d5fc4 vldr s15, [r0, #180] */
/* @0x2d5fc8 vpush {d8, d9, d10, d11} */
/* @0x2d5fcc vldr s16, [r1, #4] */
/* @0x2d5fd0 ldr r10, [r0, #0x98] */
/* @0x2d5fd4 vmul.f32 s16, s16, s15 */
/* @0x2d5fd8 cmp r10, #0 */
/* @0x2d5fdc ble 0x2d61fc <_ZN16b2ParticleSystem12SolveElasticERK10b2TimeStep+0x23c> */
/* @0x2d5fe0 ldr r1, [r0, #0xa0] */
/* @0x2d5fe4 rsb r10, r10, r10, lsl #4 */
/* @0x2d5fe8 vldr s0, [pc, #536] */
/* @0x2d5fec add r3, r1, #16 */
/* @0x2d5ff0 add r4, r1, #20 */
/* @0x2d5ff4 add r12, r1, #28 */
/* @0x2d5ff8 add r10, r3, r10, lsl #2 */
/* @0x2d5ffc add r1, r1, #36 */
/* @0x2d6000 vmov.f32 s18, #5.000000e-01 */
/* @0x2d6004 vmov.f32 s17, #1.500000e+00 */
/* @0x2d6008 ldr r2, [r3, #-0x4] */
/* @0x2d600c tst r2, #16 */
/* @0x2d6010 beq 0x2d61e4 <_ZN16b2ParticleSystem12SolveElasticERK10b2TimeStep+0x224> */
/* @0x2d6014 ldr r9, [r3, #-0x10] */
/* @0x2d6018 vldr s9, [r4, #4] */
/* @0x2d601c ldr r7, [r3, #-0xc] */
/* @0x2d6020 vldr s8, [r12, #4] */
/* @0x2d6024 ldr r6, [r0, #0x38] */
/* @0x2d6028 vldr s19, [r1, #4] */
/* @0x2d602c lsl r9, r9, #3 */
/* @0x2d6030 ldr r5, [r3, #-0x8] */
/* @0x2d6034 lsl r7, r7, #3 */
/* @0x2d6038 add r2, r6, r9 */
/* @0x2d603c add r8, r6, r7 */
/* @0x2d6040 vldr s12, [r2, #4] */
/* @0x2d6044 vldr s4, [r8, #4] */
/* @0x2d6048 vmul.f32 s21, s12, s9 */
/* @0x2d604c lsl r5, r5, #3 */
/* @0x2d6050 vldr s11, [r2] */
/* @0x2d6054 add r6, r6, r5 */
/* @0x2d6058 vldr s2, [r6, #4] */
/* @0x2d605c vldr s10, [r4] */
/* @0x2d6060 vldr s7, [r8] */
/* @0x2d6064 vldr s23, [r12] */
/* @0x2d6068 vldr s3, [r6] */
/* @0x2d606c vldr s22, [r1] */
/* @0x2d6070 ldr r2, [r0, #0x40] */
/* @0x2d6074 vldr s15, [r3] */
/* @0x2d6078 add r9, r2, r9 */
/* @0x2d607c add r7, r2, r7 */
/* @0x2d6080 add r5, r2, r5 */
/* @0x2d6084 vldr s5, [r9] */
/* @0x2d6088 vldr s6, [r9, #4] */
/* @0x2d608c vmul.f32 s13, s4, s8 */
/* @0x2d6090 vmul.f32 s20, s2, s19 */
/* @0x2d6094 vmla.f32 s21, s11, s10 */
/* @0x2d6098 vmul.f32 s1, s11, s9 */
/* @0x2d609c vmul.f32 s8, s7, s8 */
/* @0x2d60a0 vmla.f32 s13, s7, s23 */
/* @0x2d60a4 vmul.f32 s19, s3, s19 */
/* @0x2d60a8 vmla.f32 s20, s3, s22 */
/* @0x2d60ac vnmls.f32 s8, s4, s23 */
/* @0x2d60b0 vnmls.f32 s1, s12, s10 */
/* @0x2d60b4 vadd.f32 s13, s21, s13 */
/* @0x2d60b8 vnmls.f32 s19, s2, s22 */
/* @0x2d60bc vadd.f32 s13, s13, s20 */
/* @0x2d60c0 vadd.f32 s1, s1, s8 */
/* @0x2d60c4 vmul.f32 s8, s13, s13 */
/* @0x2d60c8 vadd.f32 s1, s1, s19 */
/* @0x2d60cc vmla.f32 s8, s1, s1 */
/* @0x2d60d0 vmov r11, s8 */
/* @0x2d60d4 vmul.f32 s14, s8, s18 */
/* @0x2d60d8 vmov.f32 s19, s17 */
/* @0x2d60dc vadd.f32 s7, s11, s7 */
/* @0x2d60e0 asr r2, r11, #1 */
/* @0x2d60e4 rsb r2, r2, #1593835520 */
/* @0x2d60e8 add r2, r2, #3620864 */
/* @0x2d60ec add r2, r2, #6592 */
/* @0x2d60f0 add r2, r2, #31 */
/* @0x2d60f4 vmov s8, r2 */
/* @0x2d60f8 vadd.f32 s7, s7, s3 */
/* @0x2d60fc vmul.f32 s14, s14, s8 */
/* @0x2d6100 vmls.f32 s19, s8, s14 */
/* @0x2d6104 vmul.f32 s14, s8, s19 */
/* @0x2d6108 vmul.f32 s13, s13, s14 */
/* @0x2d610c vmul.f32 s14, s1, s14 */
/* @0x2d6110 vadd.f32 s8, s12, s4 */
/* @0x2d6114 vmul.f32 s4, s14, s9 */
/* @0x2d6118 vmul.f32 s9, s13, s9 */
/* @0x2d611c vadd.f32 s8, s8, s2 */
/* @0x2d6120 vmul.f32 s7, s7, s0 */
/* @0x2d6124 vmul.f32 s8, s8, s0 */
/* @0x2d6128 vnmls.f32 s4, s13, s10 */
/* @0x2d612c vmla.f32 s9, s14, s10 */
/* @0x2d6130 vsub.f32 s11, s11, s7 */
/* @0x2d6134 vsub.f32 s12, s12, s8 */
/* @0x2d6138 vmul.f32 s15, s16, s15 */
/* @0x2d613c vsub.f32 s4, s4, s11 */
/* @0x2d6140 vsub.f32 s9, s9, s12 */
/* @0x2d6144 vmla.f32 s5, s15, s4 */
/* @0x2d6148 vmla.f32 s6, s15, s9 */
/* @0x2d614c vstr s5, [r9] */
/* @0x2d6150 vldr s5, [r8] */
/* @0x2d6154 vldr s12, [r7] */
/* @0x2d6158 vstr s6, [r9, #4] */
/* @0x2d615c vldr s11, [r12, #4] */
/* @0x2d6160 vmul.f32 s9, s14, s11 */
/* @0x2d6164 vldr s6, [r12] */
/* @0x2d6168 vldr s4, [r8, #4] */
/* @0x2d616c vldr s10, [r7, #4] */
/* @0x2d6170 vmul.f32 s11, s13, s11 */
/* @0x2d6174 vnmls.f32 s9, s13, s6 */
/* @0x2d6178 vmla.f32 s11, s14, s6 */
/* @0x2d617c vsub.f32 s5, s5, s7 */
/* @0x2d6180 vsub.f32 s6, s4, s8 */
/* @0x2d6184 vsub.f32 s9, s9, s5 */
/* @0x2d6188 vsub.f32 s11, s11, s6 */
/* @0x2d618c vmla.f32 s12, s15, s9 */
/* @0x2d6190 vmla.f32 s10, s15, s11 */
/* @0x2d6194 vstr s12, [r7] */
/* @0x2d6198 vldr s5, [r6] */
/* @0x2d619c vldr s12, [r5] */
/* @0x2d61a0 vstr s10, [r7, #4] */
/* @0x2d61a4 vldr s9, [r1, #4] */
/* @0x2d61a8 vmul.f32 s11, s14, s9 */
/* @0x2d61ac vldr s10, [r1] */
/* @0x2d61b0 vldr s6, [r6, #4] */
/* @0x2d61b4 vnmls.f32 s11, s13, s10 */
/* @0x2d61b8 vmul.f32 s13, s13, s9 */
/* @0x2d61bc vsub.f32 s7, s5, s7 */
/* @0x2d61c0 vmla.f32 s13, s14, s10 */
/* @0x2d61c4 vsub.f32 s11, s11, s7 */
/* @0x2d61c8 vmla.f32 s12, s15, s11 */
/* @0x2d61cc vsub.f32 s8, s6, s8 */
/* @0x2d61d0 vstr s12, [r5] */
/* @0x2d61d4 vldr s14, [r5, #4] */
/* @0x2d61d8 vsub.f32 s13, s13, s8 */
/* @0x2d61dc vmla.f32 s14, s15, s13 */
/* @0x2d61e0 vstr s14, [r5, #4] */
/* @0x2d61e4 add r3, r3, #60 */
/* @0x2d61e8 add r4, r4, #60 */
/* @0x2d61ec cmp r3, r10 */
/* @0x2d61f0 add r12, r12, #60 */
/* @0x2d61f4 add r1, r1, #60 */
/* @0x2d61f8 bne 0x2d6008 <_ZN16b2ParticleSystem12SolveElasticERK10b2TimeStep+0x48> */
/* @0x2d61fc vpop {d8, d9, d10, d11} */
/* @0x2d6200 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2d6204 bx lr */
/* @0x2d6208 .word 0x3eaaaaab */

/* ── FUNC 0x2d620c · b2ParticleSystem::SolveSpring(b2TimeStep const&) · size=292 · insn=73 */
/* @0x2d620c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2d6210 vpush {d8, d9} */
/* @0x2d6214 vldr s19, [r1, #4] */
/* @0x2d6218 vldr s15, [r0, #184] */
/* @0x2d621c ldr r1, [r0, #0x8c] */
/* @0x2d6220 mov r7, r0 */
/* @0x2d6224 vmul.f32 s19, s19, s15 */
/* @0x2d6228 cmp r1, #0 */
/* @0x2d622c ble 0x2d6314 <_ZN16b2ParticleSystem11SolveSpringERK10b2TimeStep+0x108> */
/* @0x2d6230 mov r4, #0 */
/* @0x2d6234 mov r5, r4 */
/* @0x2d6238 b 0x2d6248 <_ZN16b2ParticleSystem11SolveSpringERK10b2TimeStep+0x3c> */
/* @0x2d623c cmp r1, r5 */
/* @0x2d6240 add r4, r4, #20 */
/* @0x2d6244 ble 0x2d6314 <_ZN16b2ParticleSystem11SolveSpringERK10b2TimeStep+0x108> */
/* @0x2d6248 ldr r3, [r7, #0x94] */
/* @0x2d624c add r5, r5, #1 */
/* @0x2d6250 add r6, r3, r4 */
/* @0x2d6254 ldr r2, [r6, #0x8] */
/* @0x2d6258 tst r2, #8 */
/* @0x2d625c beq 0x2d623c <_ZN16b2ParticleSystem11SolveSpringERK10b2TimeStep+0x30> */
/* @0x2d6260 ldr r2, [r3, r4] */
/* @0x2d6264 vldr s18, [r6, #16] */
/* @0x2d6268 ldr r8, [r6, #0x4] */
/* @0x2d626c ldr r0, [r7, #0x38] */
/* @0x2d6270 lsl r9, r2, #3 */
/* @0x2d6274 lsl r8, r8, #3 */
/* @0x2d6278 add r3, r0, r9 */
/* @0x2d627c add r0, r0, r8 */
/* @0x2d6280 vldr s15, [r3, #4] */
/* @0x2d6284 vldr s16, [r0, #4] */
/* @0x2d6288 vsub.f32 s16, s16, s15 */
/* @0x2d628c vldr s17, [r0] */
/* @0x2d6290 vldr s15, [r3] */
/* @0x2d6294 vmul.f32 s14, s16, s16 */
/* @0x2d6298 vsub.f32 s17, s17, s15 */
/* @0x2d629c vmla.f32 s14, s17, s17 */
/* @0x2d62a0 vsqrt.f32 s15, s14 */
/* @0x2d62a4 vcmp.f32 s15, s15 */
/* @0x2d62a8 vmrs APSR_nzcv, fpscr */
/* @0x2d62ac bne 0x2d631c <_ZN16b2ParticleSystem11SolveSpringERK10b2TimeStep+0x110> */
/* @0x2d62b0 vldr s12, [r6, #12] */
/* @0x2d62b4 vmul.f32 s12, s19, s12 */
/* @0x2d62b8 ldr r3, [r7, #0x40] */
/* @0x2d62bc cmp r1, r5 */
/* @0x2d62c0 add r4, r4, #20 */
/* @0x2d62c4 add r2, r3, r9 */
/* @0x2d62c8 vldr s13, [r2] */
/* @0x2d62cc vldr s14, [r2, #4] */
/* @0x2d62d0 add r3, r3, r8 */
/* @0x2d62d4 vsub.f32 s18, s18, s15 */
/* @0x2d62d8 vmul.f32 s18, s18, s12 */
/* @0x2d62dc vdiv.f32 s15, s18, s15 */
/* @0x2d62e0 vmul.f32 s16, s15, s16 */
/* @0x2d62e4 vmul.f32 s17, s15, s17 */
/* @0x2d62e8 vsub.f32 s14, s14, s16 */
/* @0x2d62ec vsub.f32 s15, s13, s17 */
/* @0x2d62f0 vstr s15, [r2] */
/* @0x2d62f4 vldr s15, [r3] */
/* @0x2d62f8 vstr s14, [r2, #4] */
/* @0x2d62fc vadd.f32 s17, s15, s17 */
/* @0x2d6300 vldr s15, [r3, #4] */
/* @0x2d6304 vadd.f32 s16, s15, s16 */
/* @0x2d6308 vstr s17, [r3] */
/* @0x2d630c vstr s16, [r3, #4] */
/* @0x2d6310 bgt 0x2d6248 <_ZN16b2ParticleSystem11SolveSpringERK10b2TimeStep+0x3c> */
/* @0x2d6314 vpop {d8, d9} */
/* @0x2d6318 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2d631c vmov r0, s14 */
/* @0x2d6320 bl 0xb6700 <sqrtf@plt> */
/* @0x2d6324 ldr r1, [r7, #0x8c] */
/* @0x2d6328 vmov s15, r0 */
/* @0x2d632c b 0x2d62b0 <_ZN16b2ParticleSystem11SolveSpringERK10b2TimeStep+0xa4> */

/* ── FUNC 0x2d6330 · b2ParticleSystem::SolveSolid(b2TimeStep const&) · size=272 · insn=68 */
/* @0x2d6330 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2d6334 mov r7, r0 */
/* @0x2d6338 ldr r5, [r0, #0x50] */
/* @0x2d633c mov r4, r1 */
/* @0x2d6340 cmp r5, #0 */
/* @0x2d6344 beq 0x2d6418 <_ZN16b2ParticleSystem10SolveSolidERK10b2TimeStep+0xe8> */
/* @0x2d6348 ldr r8, [r7, #0x74] */
/* @0x2d634c vldr s9, [r4, #4] */
/* @0x2d6350 vldr s15, [r7, #204] */
/* @0x2d6354 str r5, [r7, #0x50] */
/* @0x2d6358 cmp r8, #0 */
/* @0x2d635c vmul.f32 s9, s9, s15 */
/* @0x2d6360 pople {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2d6364 ldr r3, [r7, #0x7c] */
/* @0x2d6368 add r8, r8, r8, lsl #1 */
/* @0x2d636c ldr r6, [r7, #0x5c] */
/* @0x2d6370 add r8, r3, r8, lsl #3 */
/* @0x2d6374 add r2, r3, #12 */
/* @0x2d6378 ldr r12, [r2, #-0xc] */
/* @0x2d637c ldr r1, [r2, #-0x8] */
/* @0x2d6380 lsl r0, r12, #2 */
/* @0x2d6384 ldr r4, [r6, r12, lsl #2] */
/* @0x2d6388 add r10, r5, r0 */
/* @0x2d638c ldr r0, [r6, r1, lsl #2] */
/* @0x2d6390 lsl r9, r1, #2 */
/* @0x2d6394 cmp r4, r0 */
/* @0x2d6398 add r9, r5, r9 */
/* @0x2d639c beq 0x2d6404 <_ZN16b2ParticleSystem10SolveSolidERK10b2TimeStep+0xd4> */
/* @0x2d63a0 vldr s14, [r10] */
/* @0x2d63a4 vldr s15, [r9] */
/* @0x2d63a8 vadd.f32 s15, s14, s15 */
/* @0x2d63ac vldr s10, [r2] */
/* @0x2d63b0 vldr s14, [r3, #16] */
/* @0x2d63b4 vldr s11, [r3, #20] */
/* @0x2d63b8 ldr r4, [r7, #0x40] */
/* @0x2d63bc add r12, r4, r12, lsl #3 */
/* @0x2d63c0 vldr s13, [r12] */
/* @0x2d63c4 vldr s12, [r12, #4] */
/* @0x2d63c8 add r1, r4, r1, lsl #3 */
/* @0x2d63cc vmul.f32 s15, s9, s15 */
/* @0x2d63d0 vmul.f32 s15, s15, s10 */
/* @0x2d63d4 vmul.f32 s14, s15, s14 */
/* @0x2d63d8 vmul.f32 s15, s15, s11 */
/* @0x2d63dc vsub.f32 s13, s13, s14 */
/* @0x2d63e0 vsub.f32 s12, s12, s15 */
/* @0x2d63e4 vstr s13, [r12] */
/* @0x2d63e8 vldr s13, [r1] */
/* @0x2d63ec vstr s12, [r12, #4] */
/* @0x2d63f0 vadd.f32 s14, s13, s14 */
/* @0x2d63f4 vldr s13, [r1, #4] */
/* @0x2d63f8 vadd.f32 s15, s13, s15 */
/* @0x2d63fc vstr s14, [r1] */
/* @0x2d6400 vstr s15, [r1, #4] */
/* @0x2d6404 add r3, r3, #24 */
/* @0x2d6408 add r2, r2, #24 */
/* @0x2d640c cmp r3, r8 */
/* @0x2d6410 bne 0x2d6378 <_ZN16b2ParticleSystem10SolveSolidERK10b2TimeStep+0x48> */
/* @0x2d6414 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2d6418 ldr r1, [r0, #0x28] */
/* @0x2d641c ldr r0, [r0, #0xd4] */
/* @0x2d6420 lsl r1, r1, #2 */
/* @0x2d6424 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2d6428 ldr r2, [r7, #0x28] */
/* @0x2d642c mov r1, #0 */
/* @0x2d6430 lsl r2, r2, #2 */
/* @0x2d6434 mov r5, r0 */
/* @0x2d6438 bl 0xb65b0 <memset@plt> */
/* @0x2d643c b 0x2d6348 <_ZN16b2ParticleSystem10SolveSolidERK10b2TimeStep+0x18> */

/* ── FUNC 0x2d6440 · b2ParticleSystem::SolveColorMixing(b2TimeStep const&) · size=460 · insn=115 */
/* @0x2d6440 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2d6444 mov r11, r0 */
/* @0x2d6448 ldr r0, [r0, #0x54] */
/* @0x2d644c sub sp, sp, #36 */
/* @0x2d6450 cmp r0, #0 */
/* @0x2d6454 beq 0x2d65f8 <_ZN16b2ParticleSystem16SolveColorMixingERK10b2TimeStep+0x1b8> */
/* @0x2d6458 vldr s14, [r11, #208] */
/* @0x2d645c vldr s15, [pc, #420] */
/* @0x2d6460 vmul.f32 s15, s14, s15 */
/* @0x2d6464 ldr r4, [r11, #0x74] */
/* @0x2d6468 str r0, [r11, #0x54] */
/* @0x2d646c cmp r4, #0 */
/* @0x2d6470 vcvt.s32.f32 s15, s15 */
/* @0x2d6474 vstr s15, [sp, #20] */
/* @0x2d6478 ble 0x2d65f0 <_ZN16b2ParticleSystem16SolveColorMixingERK10b2TimeStep+0x1b0> */
/* @0x2d647c mov r10, #0 */
/* @0x2d6480 mov r8, r10 */
/* @0x2d6484 ldr r2, [r11, #0x7c] */
/* @0x2d6488 add r8, r8, #1 */
/* @0x2d648c ldr r3, [r11, #0x30] */
/* @0x2d6490 add r1, r2, r10 */
/* @0x2d6494 ldr r0, [r2, r10] */
/* @0x2d6498 add r10, r10, #24 */
/* @0x2d649c ldr r2, [r1, #0x4] */
/* @0x2d64a0 ldr r5, [r3, r0, lsl #2] */
/* @0x2d64a4 lsl r12, r0, #2 */
/* @0x2d64a8 ldr r1, [r3, r2, lsl #2] */
/* @0x2d64ac lsl r3, r2, #2 */
/* @0x2d64b0 and r1, r5, r1 */
/* @0x2d64b4 tst r1, #256 */
/* @0x2d64b8 beq 0x2d65e8 <_ZN16b2ParticleSystem16SolveColorMixingERK10b2TimeStep+0x1a8> */
/* @0x2d64bc ldr r1, [r11, #0x54] */
/* @0x2d64c0 add r12, r1, r12 */
/* @0x2d64c4 add r3, r1, r3 */
/* @0x2d64c8 ldrb r4, [r1, r0, lsl #2] */
/* @0x2d64cc ldrb r6, [r12, #0x2] */
/* @0x2d64d0 ldrb r5, [r12, #0x1] */
/* @0x2d64d4 ldrb r7, [r3, #0x1] */
/* @0x2d64d8 str r6, [sp, #0x10] */
/* @0x2d64dc ldrb r9, [r12, #0x3] */
/* @0x2d64e0 rsb r7, r5, r7 */
/* @0x2d64e4 str r4, [sp, #0x18] */
/* @0x2d64e8 ldrb r4, [r3, #0x3] */
/* @0x2d64ec str r7, [sp, #0x1c] */
/* @0x2d64f0 ldrb r6, [r3, #0x2] */
/* @0x2d64f4 rsb r4, r9, r4 */
/* @0x2d64f8 ldr r7, [sp, #0x10] */
/* @0x2d64fc str r5, [sp, #0xc] */
/* @0x2d6500 str r4, [sp] */
/* @0x2d6504 rsb r6, r7, r6 */
/* @0x2d6508 ldr r4, [sp, #0x18] */
/* @0x2d650c ldrb r5, [r1, r2, lsl #2] */
/* @0x2d6510 str r6, [sp, #0x4] */
/* @0x2d6514 rsb r5, r4, r5 */
/* @0x2d6518 ldr r6, [sp, #0x1c] */
/* @0x2d651c str r5, [sp, #0x8] */
/* @0x2d6520 ldr r4, [sp, #0x4] */
/* @0x2d6524 ldr r5, [sp, #0x14] */
/* @0x2d6528 mul r7, r5, r6 */
/* @0x2d652c mul r6, r5, r4 */
/* @0x2d6530 ldr r4, [sp] */
/* @0x2d6534 ubfx r7, r7, #0x8, #0x8 */
/* @0x2d6538 mul r5, r5, r4 */
/* @0x2d653c ldr r4, [sp, #0x8] */
/* @0x2d6540 ubfx r6, r6, #0x8, #0x8 */
/* @0x2d6544 str r6, [sp, #0x1c] */
/* @0x2d6548 ldr r6, [sp, #0xc] */
/* @0x2d654c add r6, r7, r6 */
/* @0x2d6550 str r6, [sp, #0xc] */
/* @0x2d6554 str r5, [sp, #0x4] */
/* @0x2d6558 ldr r5, [sp, #0x14] */
/* @0x2d655c ldr r6, [sp, #0x10] */
/* @0x2d6560 mul r5, r5, r4 */
/* @0x2d6564 str r5, [sp, #0x8] */
/* @0x2d6568 ldr r5, [sp, #0x4] */
/* @0x2d656c ubfx r4, r5, #0x8, #0x8 */
/* @0x2d6570 ldr r5, [sp, #0x1c] */
/* @0x2d6574 add r9, r4, r9 */
/* @0x2d6578 add r5, r5, r6 */
/* @0x2d657c str r5, [sp, #0x10] */
/* @0x2d6580 str r9, [sp, #0x4] */
/* @0x2d6584 ldr r6, [sp, #0x8] */
/* @0x2d6588 ubfx r5, r6, #0x8, #0x8 */
/* @0x2d658c ldr r6, [sp, #0x18] */
/* @0x2d6590 add r9, r5, r6 */
/* @0x2d6594 strb r9, [r1, r0, lsl #2] */
/* @0x2d6598 ldr r0, [sp, #0xc] */
/* @0x2d659c ldr r6, [sp, #0x10] */
/* @0x2d65a0 strb r0, [r12, #0x1] */
/* @0x2d65a4 ldr r0, [sp, #0x4] */
/* @0x2d65a8 strb r6, [r12, #0x2] */
/* @0x2d65ac ldrb r6, [r1, r2, lsl #2] */
/* @0x2d65b0 strb r0, [r12, #0x3] */
/* @0x2d65b4 ldrb r0, [r3, #0x1] */
/* @0x2d65b8 rsb r5, r5, r6 */
/* @0x2d65bc ldrb r12, [r3, #0x2] */
/* @0x2d65c0 rsb r0, r7, r0 */
/* @0x2d65c4 ldr r6, [sp, #0x1c] */
/* @0x2d65c8 ldrb r7, [r3, #0x3] */
/* @0x2d65cc rsb r12, r6, r12 */
/* @0x2d65d0 strb r5, [r1, r2, lsl #2] */
/* @0x2d65d4 rsb r4, r4, r7 */
/* @0x2d65d8 strb r0, [r3, #0x1] */
/* @0x2d65dc strb r12, [r3, #0x2] */
/* @0x2d65e0 strb r4, [r3, #0x3] */
/* @0x2d65e4 ldr r4, [r11, #0x74] */
/* @0x2d65e8 cmp r4, r8 */
/* @0x2d65ec bgt 0x2d6484 <_ZN16b2ParticleSystem16SolveColorMixingERK10b2TimeStep+0x44> */
/* @0x2d65f0 add sp, sp, #36 */
/* @0x2d65f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2d65f8 add r0, r11, #40 */
/* @0x2d65fc add r1, r11, #212 */
/* @0x2d6600 bl 0x2d4a30 <_ZN15b2QueryCallbackD0Ev+0xa0> */
/* @0x2d6604 b 0x2d6458 <_ZN16b2ParticleSystem16SolveColorMixingERK10b2TimeStep+0x18> */
/* @0x2d6608 orrmi r0, r0, #0 */

/* ── FUNC 0x2d660c · b2ParticleSystem::SolveZombie() · size=3828 · insn=957 */
/* @0x2d660c ldr r1, [r0, #0x24] */
/* @0x2d6610 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2d6614 mov r5, r0 */
/* @0x2d6618 ldr r0, [r0, #0xd4] */
/* @0x2d661c sub sp, sp, #28 */
/* @0x2d6620 lsl r1, r1, #2 */
/* @0x2d6624 add r0, r0, #68 */
/* @0x2d6628 bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi> */
/* @0x2d662c ldr r3, [r5, #0x24] */
/* @0x2d6630 cmp r3, #0 */
/* @0x2d6634 mov r4, r0 */
/* @0x2d6638 ble 0x2d74cc <_ZN16b2ParticleSystem11SolveZombieEv+0xec0> */
/* @0x2d663c mov r6, #0 */
/* @0x2d6640 movw r8, #0x9244 */
/* @0x2d6644 mov r7, r6 */
/* @0x2d6648 movt r8, #0x1 */
/* @0x2d664c str r6, [sp, #0x14] */
/* @0x2d6650 mvn r9, #0 */
/* @0x2d6654 mov r10, r6 */
/* @0x2d6658 str r8, [sp] */
/* @0x2d665c b 0x2d66a4 <_ZN16b2ParticleSystem11SolveZombieEv+0x98> */
/* @0x2d6660 ldr r3, [r5, #0xd4] */
/* @0x2d6664 tst r2, #512 */
/* @0x2d6668 ldr r2, [sp] */
/* @0x2d666c ldr r0, [r3, r2] */
/* @0x2d6670 beq 0x2d668c <_ZN16b2ParticleSystem11SolveZombieEv+0x80> */
/* @0x2d6674 cmp r0, #0 */
/* @0x2d6678 beq 0x2d668c <_ZN16b2ParticleSystem11SolveZombieEv+0x80> */
/* @0x2d667c ldr r3, [r0] */
/* @0x2d6680 mov r1, r7 */
/* @0x2d6684 ldr r3, [r3, #0x14] */
/* @0x2d6688 blx r3 */
/* @0x2d668c str r9, [r4, r6] */
/* @0x2d6690 ldr r3, [r5, #0x24] */
/* @0x2d6694 add r7, r7, #1 */
/* @0x2d6698 add r6, r6, #4 */
/* @0x2d669c cmp r3, r7 */
/* @0x2d66a0 ble 0x2d674c <_ZN16b2ParticleSystem11SolveZombieEv+0x140> */
/* @0x2d66a4 ldr r3, [r5, #0x30] */
/* @0x2d66a8 add r0, r3, r6 */
/* @0x2d66ac ldr r2, [r3, r6] */
/* @0x2d66b0 tst r2, #2 */
/* @0x2d66b4 bne 0x2d6660 <_ZN16b2ParticleSystem11SolveZombieEv+0x54> */
/* @0x2d66b8 cmp r7, r10 */
/* @0x2d66bc str r10, [r4, r6] */
/* @0x2d66c0 beq 0x2d6744 <_ZN16b2ParticleSystem11SolveZombieEv+0x138> */
/* @0x2d66c4 ldr r11, [r5, #0x38] */
/* @0x2d66c8 lsl lr, r7, #3 */
/* @0x2d66cc ldr r0, [r0] */
/* @0x2d66d0 lsl r12, r10, #3 */
/* @0x2d66d4 ldr r2, [r5, #0x40] */
/* @0x2d66d8 add r1, r11, lr */
/* @0x2d66dc add r11, r11, r12 */
/* @0x2d66e0 str r0, [r3, r10, lsl #2] */
/* @0x2d66e4 add lr, r2, lr */
/* @0x2d66e8 ldm r1, {r0, r1} */
/* @0x2d66ec add r12, r2, r12 */
/* @0x2d66f0 ldr r2, [r5, #0x5c] */
/* @0x2d66f4 lsl r3, r10, #2 */
/* @0x2d66f8 stm r11, {r0, r1} */
/* @0x2d66fc ldr r11, [r2, r6] */
/* @0x2d6700 ldm lr, {r0, r1} */
/* @0x2d6704 stm r12, {r0, r1} */
/* @0x2d6708 str r11, [r2, r10, lsl #2] */
/* @0x2d670c ldr r2, [r5, #0x50] */
/* @0x2d6710 cmp r2, #0 */
/* @0x2d6714 addne r1, r2, r6 */
/* @0x2d6718 addne r2, r2, r3 */
/* @0x2d671c ldrne r1, [r1] */
/* @0x2d6720 strne r1, [r2] */
/* @0x2d6724 ldr r2, [r5, #0x54] */
/* @0x2d6728 cmp r2, #0 */
/* @0x2d672c ldrne r1, [r2, r6] */
/* @0x2d6730 strne r1, [r2, r3] */
/* @0x2d6734 ldr r2, [r5, #0x60] */
/* @0x2d6738 cmp r2, #0 */
/* @0x2d673c ldrne r1, [r2, r6] */
/* @0x2d6740 strne r1, [r2, r3] */
/* @0x2d6744 add r10, r10, #1 */
/* @0x2d6748 b 0x2d6690 <_ZN16b2ParticleSystem11SolveZombieEv+0x84> */
/* @0x2d674c str r10, [sp, #0x14] */
/* @0x2d6750 ldr r10, [r5, #0x68] */
/* @0x2d6754 cmp r10, #0 */
/* @0x2d6758 lslle r10, r10, #3 */
/* @0x2d675c ldrle r2, [r5, #0x70] */
/* @0x2d6760 ble 0x2d6788 <_ZN16b2ParticleSystem11SolveZombieEv+0x17c> */
/* @0x2d6764 ldr r2, [r5, #0x70] */
/* @0x2d6768 lsl r10, r10, #3 */
/* @0x2d676c mov r3, #0 */
/* @0x2d6770 ldr r1, [r2, r3] */
/* @0x2d6774 ldr r1, [r4, r1, lsl #2] */
/* @0x2d6778 str r1, [r2, r3] */
/* @0x2d677c add r3, r3, #8 */
/* @0x2d6780 cmp r3, r10 */
/* @0x2d6784 bne 0x2d6770 <_ZN16b2ParticleSystem11SolveZombieEv+0x164> */
/* @0x2d6788 add r10, r2, r10 */
/* @0x2d678c rsb r11, r2, r10 */
/* @0x2d6790 asr r0, r11, #5 */
/* @0x2d6794 asr r11, r11, #3 */
/* @0x2d6798 cmp r0, #0 */
/* @0x2d679c ble 0x2d74f4 <_ZN16b2ParticleSystem11SolveZombieEv+0xee8> */
/* @0x2d67a0 ldr r3, [r2] */
/* @0x2d67a4 cmp r3, #0 */
/* @0x2d67a8 blt 0x2d74ec <_ZN16b2ParticleSystem11SolveZombieEv+0xee0> */
/* @0x2d67ac ldr r3, [r2, #0x8] */
/* @0x2d67b0 cmp r3, #0 */
/* @0x2d67b4 addlt r3, r2, #8 */
/* @0x2d67b8 blt 0x2d6860 <_ZN16b2ParticleSystem11SolveZombieEv+0x254> */
/* @0x2d67bc ldr r3, [r2, #0x10] */
/* @0x2d67c0 cmp r3, #0 */
/* @0x2d67c4 addlt r3, r2, #16 */
/* @0x2d67c8 blt 0x2d6860 <_ZN16b2ParticleSystem11SolveZombieEv+0x254> */
/* @0x2d67cc ldr r3, [r2, #0x18] */
/* @0x2d67d0 cmp r3, #0 */
/* @0x2d67d4 blt 0x2d685c <_ZN16b2ParticleSystem11SolveZombieEv+0x250> */
/* @0x2d67d8 mov r1, r2 */
/* @0x2d67dc add r9, r2, #56 */
/* @0x2d67e0 b 0x2d6818 <_ZN16b2ParticleSystem11SolveZombieEv+0x20c> */
/* @0x2d67e4 ldr r6, [r1, #0x20] */
/* @0x2d67e8 cmp r6, #0 */
/* @0x2d67ec blt 0x2d6860 <_ZN16b2ParticleSystem11SolveZombieEv+0x254> */
/* @0x2d67f0 ldr r6, [r12, r7] */
/* @0x2d67f4 cmp r6, #0 */
/* @0x2d67f8 blt 0x2d749c <_ZN16b2ParticleSystem11SolveZombieEv+0xe90> */
/* @0x2d67fc ldr r12, [r12, r8] */
/* @0x2d6800 cmp r12, #0 */
/* @0x2d6804 blt 0x2d74a4 <_ZN16b2ParticleSystem11SolveZombieEv+0xe98> */
/* @0x2d6808 ldr r12, [lr, #-0x20] */
/* @0x2d680c cmp r12, #0 */
/* @0x2d6810 blt 0x2d74c4 <_ZN16b2ParticleSystem11SolveZombieEv+0xeb8> */
/* @0x2d6814 mov r1, r3 */
/* @0x2d6818 add r3, r1, #32 */
/* @0x2d681c subs r0, r0, #1 */
/* @0x2d6820 rsb lr, r2, r3 */
/* @0x2d6824 add r7, r2, #40 */
/* @0x2d6828 add r8, r2, #48 */
/* @0x2d682c rsb r12, r2, r1 */
/* @0x2d6830 add lr, lr, r9 */
/* @0x2d6834 bne 0x2d67e4 <_ZN16b2ParticleSystem11SolveZombieEv+0x1d8> */
/* @0x2d6838 rsb r1, r3, r10 */
/* @0x2d683c asr r1, r1, #3 */
/* @0x2d6840 cmp r1, #2 */
/* @0x2d6844 beq 0x2d7404 <_ZN16b2ParticleSystem11SolveZombieEv+0xdf8> */
/* @0x2d6848 cmp r1, #3 */
/* @0x2d684c beq 0x2d73f4 <_ZN16b2ParticleSystem11SolveZombieEv+0xde8> */
/* @0x2d6850 cmp r1, #1 */
/* @0x2d6854 bne 0x2d68b0 <_ZN16b2ParticleSystem11SolveZombieEv+0x2a4> */
/* @0x2d6858 b 0x2d7414 <_ZN16b2ParticleSystem11SolveZombieEv+0xe08> */
/* @0x2d685c add r3, r2, #24 */
/* @0x2d6860 cmp r10, r3 */
/* @0x2d6864 beq 0x2d68b0 <_ZN16b2ParticleSystem11SolveZombieEv+0x2a4> */
/* @0x2d6868 add r1, r3, #8 */
/* @0x2d686c cmp r10, r1 */
/* @0x2d6870 beq 0x2d68a8 <_ZN16b2ParticleSystem11SolveZombieEv+0x29c> */
/* @0x2d6874 add r12, r3, #16 */
/* @0x2d6878 add lr, r3, #24 */
/* @0x2d687c rsb r1, r12, r10 */
/* @0x2d6880 bic r1, r1, #7 */
/* @0x2d6884 add lr, lr, r1 */
/* @0x2d6888 ldr r1, [r12, #-0x8] */
/* @0x2d688c cmp r1, #0 */
/* @0x2d6890 ldmdbge r12, {r0, r1} */
/* @0x2d6894 add r12, r12, #8 */
/* @0x2d6898 stmge r3, {r0, r1} */
/* @0x2d689c addge r3, r3, #8 */
/* @0x2d68a0 cmp r12, lr */
/* @0x2d68a4 bne 0x2d6888 <_ZN16b2ParticleSystem11SolveZombieEv+0x27c> */
/* @0x2d68a8 rsb r3, r2, r3 */
/* @0x2d68ac asr r11, r3, #3 */
/* @0x2d68b0 ldr r12, [r5, #0x74] */
/* @0x2d68b4 str r11, [r5, #0x68] */
/* @0x2d68b8 cmp r12, #0 */
/* @0x2d68bc lslle r6, r12, #1 */
/* @0x2d68c0 ldrle lr, [r5, #0x7c] */
/* @0x2d68c4 ble 0x2d6904 <_ZN16b2ParticleSystem11SolveZombieEv+0x2f8> */
/* @0x2d68c8 lsl r6, r12, #1 */
/* @0x2d68cc ldr lr, [r5, #0x7c] */
/* @0x2d68d0 add r0, r6, r12 */
/* @0x2d68d4 mov r2, #0 */
/* @0x2d68d8 lsl r0, r0, #3 */
/* @0x2d68dc ldr r1, [lr, r2] */
/* @0x2d68e0 mov r3, lr */
/* @0x2d68e4 ldr r1, [r4, r1, lsl #2] */
/* @0x2d68e8 str r1, [r3, r2]! */
/* @0x2d68ec add r2, r2, #24 */
/* @0x2d68f0 ldr r1, [r3, #0x4] */
/* @0x2d68f4 cmp r2, r0 */
/* @0x2d68f8 ldr r1, [r4, r1, lsl #2] */
/* @0x2d68fc str r1, [r3, #0x4] */
/* @0x2d6900 bne 0x2d68dc <_ZN16b2ParticleSystem11SolveZombieEv+0x2d0> */
/* @0x2d6904 add r12, r6, r12 */
/* @0x2d6908 sbfx r3, r12, #0x0, #0x1d */
/* @0x2d690c add r12, lr, r12, lsl #3 */
/* @0x2d6910 str r12, [sp, #0x10] */
/* @0x2d6914 add r2, r3, r3, lsl #2 */
/* @0x2d6918 add r2, r2, r2, lsl #4 */
/* @0x2d691c add r2, r2, r2, lsl #8 */
/* @0x2d6920 add r2, r2, r2, lsl #16 */
/* @0x2d6924 add r2, r3, r2, lsl #1 */
/* @0x2d6928 str r2, [sp, #0xc] */
/* @0x2d692c asr r1, r2, #2 */
/* @0x2d6930 str r1, [sp] */
/* @0x2d6934 cmp r1, #0 */
/* @0x2d6938 movle r3, r2 */
/* @0x2d693c movle r12, lr */
/* @0x2d6940 ble 0x2d72c4 <_ZN16b2ParticleSystem11SolveZombieEv+0xcb8> */
/* @0x2d6944 ldr r3, [lr] */
/* @0x2d6948 cmp r3, #0 */
/* @0x2d694c blt 0x2d725c <_ZN16b2ParticleSystem11SolveZombieEv+0xc50> */
/* @0x2d6950 ldr r3, [lr, #0x4] */
/* @0x2d6954 cmp r3, #0 */
/* @0x2d6958 blt 0x2d725c <_ZN16b2ParticleSystem11SolveZombieEv+0xc50> */
/* @0x2d695c ldr r3, [lr, #0x18] */
/* @0x2d6960 add r12, lr, #24 */
/* @0x2d6964 cmp r3, #0 */
/* @0x2d6968 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448> */
/* @0x2d696c ldr r3, [lr, #0x1c] */
/* @0x2d6970 cmp r3, #0 */
/* @0x2d6974 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448> */
/* @0x2d6978 ldr r3, [lr, #0x30] */
/* @0x2d697c add r1, lr, #48 */
/* @0x2d6980 str r1, [sp, #0x4] */
/* @0x2d6984 cmp r3, #0 */
/* @0x2d6988 mov r12, r1 */
/* @0x2d698c blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448> */
/* @0x2d6990 add r9, lr, #72 */
/* @0x2d6994 add r6, lr, #96 */
/* @0x2d6998 add r10, lr, #120 */
/* @0x2d699c add r2, lr, #144 */
/* @0x2d69a0 str r2, [sp, #0x8] */
/* @0x2d69a4 mov r2, lr */
/* @0x2d69a8 ldr r8, [sp, #0x4] */
/* @0x2d69ac rsb r3, lr, r2 */
/* @0x2d69b0 add r1, r3, r9 */
/* @0x2d69b4 add r7, r3, r6 */
/* @0x2d69b8 add r0, r3, r8 */
/* @0x2d69bc ldr r0, [r0, #0x4] */
/* @0x2d69c0 cmp r0, #0 */
/* @0x2d69c4 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448> */
/* @0x2d69c8 ldr r0, [r3, r9] */
/* @0x2d69cc add r12, r2, #72 */
/* @0x2d69d0 cmp r0, #0 */
/* @0x2d69d4 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448> */
/* @0x2d69d8 ldr r1, [r1, #0x4] */
/* @0x2d69dc add r8, r3, r10 */
/* @0x2d69e0 cmp r1, #0 */
/* @0x2d69e4 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448> */
/* @0x2d69e8 ldr r1, [sp] */
/* @0x2d69ec add r12, r2, #96 */
/* @0x2d69f0 rsb r11, lr, r12 */
/* @0x2d69f4 subs r1, r1, #1 */
/* @0x2d69f8 str r1, [sp] */
/* @0x2d69fc ldr r1, [sp, #0x8] */
/* @0x2d6a00 mov r0, r12 */
/* @0x2d6a04 add r11, r11, r1 */
/* @0x2d6a08 beq 0x2d72a4 <_ZN16b2ParticleSystem11SolveZombieEv+0xc98> */
/* @0x2d6a0c ldr r1, [r3, r6] */
/* @0x2d6a10 cmp r1, #0 */
/* @0x2d6a14 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448> */
/* @0x2d6a18 ldr r1, [r7, #0x4] */
/* @0x2d6a1c cmp r1, #0 */
/* @0x2d6a20 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448> */
/* @0x2d6a24 ldr r3, [r3, r10] */
/* @0x2d6a28 add r12, r2, #120 */
/* @0x2d6a2c cmp r3, #0 */
/* @0x2d6a30 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448> */
/* @0x2d6a34 ldr r3, [r8, #0x4] */
/* @0x2d6a38 cmp r3, #0 */
/* @0x2d6a3c blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448> */
/* @0x2d6a40 ldr r3, [r11, #-0x60] */
/* @0x2d6a44 add r12, r2, #144 */
/* @0x2d6a48 mov r2, r0 */
/* @0x2d6a4c cmp r3, #0 */
/* @0x2d6a50 bge 0x2d69a8 <_ZN16b2ParticleSystem11SolveZombieEv+0x39c> */
/* @0x2d6a54 ldr r2, [sp, #0x10] */
/* @0x2d6a58 cmp r2, r12 */
/* @0x2d6a5c beq 0x2d6ae0 <_ZN16b2ParticleSystem11SolveZombieEv+0x4d4> */
/* @0x2d6a60 add r3, r12, #24 */
/* @0x2d6a64 cmp r2, r3 */
/* @0x2d6a68 beq 0x2d6ac0 <_ZN16b2ParticleSystem11SolveZombieEv+0x4b4> */
/* @0x2d6a6c add r8, r12, #48 */
/* @0x2d6a70 add r9, r12, #72 */
/* @0x2d6a74 rsb r3, r8, r2 */
/* @0x2d6a78 bic r3, r3, #7 */
/* @0x2d6a7c add r9, r9, r3 */
/* @0x2d6a80 ldr r3, [r8, #-0x18] */
/* @0x2d6a84 sub r7, r8, #24 */
/* @0x2d6a88 mov r6, r12 */
/* @0x2d6a8c cmp r3, #0 */
/* @0x2d6a90 blt 0x2d6ab4 <_ZN16b2ParticleSystem11SolveZombieEv+0x4a8> */
/* @0x2d6a94 ldr r3, [r8, #-0x14] */
/* @0x2d6a98 cmp r3, #0 */
/* @0x2d6a9c blt 0x2d6ab4 <_ZN16b2ParticleSystem11SolveZombieEv+0x4a8> */
/* @0x2d6aa0 ldm r7!, {r0, r1, r2, r3} */
/* @0x2d6aa4 add r12, r12, #24 */
/* @0x2d6aa8 stm r6!, {r0, r1, r2, r3} */
/* @0x2d6aac ldm r7, {r0, r1} */
/* @0x2d6ab0 stm r6, {r0, r1} */
/* @0x2d6ab4 add r8, r8, #24 */
/* @0x2d6ab8 cmp r8, r9 */
/* @0x2d6abc bne 0x2d6a80 <_ZN16b2ParticleSystem11SolveZombieEv+0x474> */
/* @0x2d6ac0 rsb r3, lr, r12 */
/* @0x2d6ac4 asr r3, r3, #3 */
/* @0x2d6ac8 add r2, r3, r3, lsl #2 */
/* @0x2d6acc add r2, r2, r2, lsl #4 */
/* @0x2d6ad0 add r2, r2, r2, lsl #8 */
/* @0x2d6ad4 add r2, r2, r2, lsl #16 */
/* @0x2d6ad8 add r2, r3, r2, lsl #1 */
/* @0x2d6adc str r2, [sp, #0xc] */
/* @0x2d6ae0 ldr r0, [r5, #0x80] */
/* @0x2d6ae4 ldr r3, [sp, #0xc] */
/* @0x2d6ae8 cmp r0, #0 */
/* @0x2d6aec lslle r12, r0, #1 */
/* @0x2d6af0 str r3, [r5, #0x74] */
/* @0x2d6af4 ldrle lr, [r5, #0x88] */
/* @0x2d6af8 ble 0x2d6b28 <_ZN16b2ParticleSystem11SolveZombieEv+0x51c> */
/* @0x2d6afc lsl r12, r0, #1 */
/* @0x2d6b00 ldr lr, [r5, #0x88] */
/* @0x2d6b04 add r1, r12, r0 */
/* @0x2d6b08 mov r3, #0 */
/* @0x2d6b0c lsl r1, r1, #3 */
/* @0x2d6b10 ldr r2, [lr, r3] */
/* @0x2d6b14 ldr r2, [r4, r2, lsl #2] */
/* @0x2d6b18 str r2, [lr, r3] */
/* @0x2d6b1c add r3, r3, #24 */
/* @0x2d6b20 cmp r3, r1 */
/* @0x2d6b24 bne 0x2d6b10 <_ZN16b2ParticleSystem11SolveZombieEv+0x504> */
/* @0x2d6b28 add r0, r12, r0 */
/* @0x2d6b2c sbfx r3, r0, #0x0, #0x1d */
/* @0x2d6b30 add r11, lr, r0, lsl #3 */
/* @0x2d6b34 add r10, r3, r3, lsl #2 */
/* @0x2d6b38 add r10, r10, r10, lsl #4 */
/* @0x2d6b3c add r10, r10, r10, lsl #8 */
/* @0x2d6b40 add r10, r10, r10, lsl #16 */
/* @0x2d6b44 add r10, r3, r10, lsl #1 */
/* @0x2d6b48 asr r2, r10, #2 */
/* @0x2d6b4c cmp r2, #0 */
/* @0x2d6b50 ble 0x2d74e0 <_ZN16b2ParticleSystem11SolveZombieEv+0xed4> */
/* @0x2d6b54 ldr r3, [lr] */
/* @0x2d6b58 cmp r3, #0 */
/* @0x2d6b5c blt 0x2d74d8 <_ZN16b2ParticleSystem11SolveZombieEv+0xecc> */
/* @0x2d6b60 ldr r3, [lr, #0x18] */
/* @0x2d6b64 cmp r3, #0 */
/* @0x2d6b68 addlt r12, lr, #24 */
/* @0x2d6b6c blt 0x2d6c28 <_ZN16b2ParticleSystem11SolveZombieEv+0x61c> */
/* @0x2d6b70 ldr r3, [lr, #0x30] */
/* @0x2d6b74 cmp r3, #0 */
/* @0x2d6b78 addlt r12, lr, #48 */
/* @0x2d6b7c blt 0x2d6c28 <_ZN16b2ParticleSystem11SolveZombieEv+0x61c> */
/* @0x2d6b80 ldr r3, [lr, #0x48] */
/* @0x2d6b84 cmp r3, #0 */
/* @0x2d6b88 blt 0x2d6c24 <_ZN16b2ParticleSystem11SolveZombieEv+0x618> */
/* @0x2d6b8c mov r3, lr */
/* @0x2d6b90 add r9, lr, #168 */
/* @0x2d6b94 b 0x2d6bcc <_ZN16b2ParticleSystem11SolveZombieEv+0x5c0> */
/* @0x2d6b98 ldr r6, [r3, #0x60] */
/* @0x2d6b9c cmp r6, #0 */
/* @0x2d6ba0 blt 0x2d6c28 <_ZN16b2ParticleSystem11SolveZombieEv+0x61c> */
/* @0x2d6ba4 ldr r6, [r1, r7] */
/* @0x2d6ba8 cmp r6, #0 */
/* @0x2d6bac blt 0x2d74ac <_ZN16b2ParticleSystem11SolveZombieEv+0xea0> */
/* @0x2d6bb0 ldr r1, [r1, r8] */
/* @0x2d6bb4 cmp r1, #0 */
/* @0x2d6bb8 blt 0x2d74b4 <_ZN16b2ParticleSystem11SolveZombieEv+0xea8> */
/* @0x2d6bbc ldr r1, [r0, #-0x60] */
/* @0x2d6bc0 cmp r1, #0 */
/* @0x2d6bc4 blt 0x2d74bc <_ZN16b2ParticleSystem11SolveZombieEv+0xeb0> */
/* @0x2d6bc8 mov r3, r12 */
/* @0x2d6bcc add r12, r3, #96 */
/* @0x2d6bd0 subs r2, r2, #1 */
/* @0x2d6bd4 rsb r0, lr, r12 */
/* @0x2d6bd8 add r7, lr, #120 */
/* @0x2d6bdc add r8, lr, #144 */
/* @0x2d6be0 rsb r1, lr, r3 */
/* @0x2d6be4 add r0, r0, r9 */
/* @0x2d6be8 bne 0x2d6b98 <_ZN16b2ParticleSystem11SolveZombieEv+0x58c> */
/* @0x2d6bec rsb r2, r12, r11 */
/* @0x2d6bf0 asr r2, r2, #3 */
/* @0x2d6bf4 add r3, r2, r2, lsl #2 */
/* @0x2d6bf8 add r3, r3, r3, lsl #4 */
/* @0x2d6bfc add r3, r3, r3, lsl #8 */
/* @0x2d6c00 add r3, r3, r3, lsl #16 */
/* @0x2d6c04 add r3, r2, r3, lsl #1 */
/* @0x2d6c08 cmp r3, #2 */
/* @0x2d6c0c beq 0x2d732c <_ZN16b2ParticleSystem11SolveZombieEv+0xd20> */
/* @0x2d6c10 cmp r3, #3 */
/* @0x2d6c14 beq 0x2d731c <_ZN16b2ParticleSystem11SolveZombieEv+0xd10> */
/* @0x2d6c18 cmp r3, #1 */
/* @0x2d6c1c bne 0x2d6c9c <_ZN16b2ParticleSystem11SolveZombieEv+0x690> */
/* @0x2d6c20 b 0x2d733c <_ZN16b2ParticleSystem11SolveZombieEv+0xd30> */
/* @0x2d6c24 add r12, lr, #72 */
/* @0x2d6c28 cmp r11, r12 */
/* @0x2d6c2c beq 0x2d6c9c <_ZN16b2ParticleSystem11SolveZombieEv+0x690> */
/* @0x2d6c30 add r3, r12, #24 */
/* @0x2d6c34 cmp r11, r3 */
/* @0x2d6c38 beq 0x2d6c80 <_ZN16b2ParticleSystem11SolveZombieEv+0x674> */
/* @0x2d6c3c add r6, r12, #48 */
/* @0x2d6c40 add r9, r12, #72 */
/* @0x2d6c44 rsb r3, r6, r11 */
/* @0x2d6c48 bic r3, r3, #7 */
/* @0x2d6c4c add r9, r9, r3 */
/* @0x2d6c50 ldr r3, [r6, #-0x18] */
/* @0x2d6c54 sub r8, r6, #24 */
/* @0x2d6c58 mov r7, r12 */
/* @0x2d6c5c add r6, r6, #24 */
/* @0x2d6c60 cmp r3, #0 */
/* @0x2d6c64 addge r12, r12, #24 */
/* @0x2d6c68 ldmge r8!, {r0, r1, r2, r3} */
/* @0x2d6c6c stmge r7!, {r0, r1, r2, r3} */
/* @0x2d6c70 ldmge r8, {r0, r1} */
/* @0x2d6c74 stmge r7, {r0, r1} */
/* @0x2d6c78 cmp r6, r9 */
/* @0x2d6c7c bne 0x2d6c50 <_ZN16b2ParticleSystem11SolveZombieEv+0x644> */
/* @0x2d6c80 rsb r3, lr, r12 */
/* @0x2d6c84 asr r3, r3, #3 */
/* @0x2d6c88 add r10, r3, r3, lsl #2 */
/* @0x2d6c8c add r10, r10, r10, lsl #4 */
/* @0x2d6c90 add r10, r10, r10, lsl #8 */
/* @0x2d6c94 add r10, r10, r10, lsl #16 */
/* @0x2d6c98 add r10, r3, r10, lsl #1 */
/* @0x2d6c9c ldr r12, [r5, #0x8c] */
/* @0x2d6ca0 str r10, [r5, #0x80] */
/* @0x2d6ca4 cmp r12, #0 */
/* @0x2d6ca8 lslle r6, r12, #2 */
/* @0x2d6cac ldrle lr, [r5, #0x94] */
/* @0x2d6cb0 ble 0x2d6cf0 <_ZN16b2ParticleSystem11SolveZombieEv+0x6e4> */
/* @0x2d6cb4 lsl r6, r12, #2 */
/* @0x2d6cb8 ldr lr, [r5, #0x94] */
/* @0x2d6cbc add r0, r6, r12 */
/* @0x2d6cc0 mov r2, #0 */
/* @0x2d6cc4 lsl r0, r0, #2 */
/* @0x2d6cc8 ldr r1, [lr, r2] */
/* @0x2d6ccc mov r3, lr */
/* @0x2d6cd0 ldr r1, [r4, r1, lsl #2] */
/* @0x2d6cd4 str r1, [r3, r2]! */
/* @0x2d6cd8 add r2, r2, #20 */
/* @0x2d6cdc ldr r1, [r3, #0x4] */
/* @0x2d6ce0 cmp r2, r0 */
/* @0x2d6ce4 ldr r1, [r4, r1, lsl #2] */
/* @0x2d6ce8 str r1, [r3, #0x4] */
/* @0x2d6cec bne 0x2d6cc8 <_ZN16b2ParticleSystem11SolveZombieEv+0x6bc> */
/* @0x2d6cf0 add r12, r6, r12 */
/* @0x2d6cf4 sbfx r3, r12, #0x0, #0x1e */
/* @0x2d6cf8 add r12, lr, r12, lsl #2 */
/* @0x2d6cfc str r12, [sp, #0x10] */
/* @0x2d6d00 add r2, r3, r3, lsl #1 */
/* @0x2d6d04 add r2, r2, r2, lsl #4 */
/* @0x2d6d08 add r2, r2, r2, lsl #8 */
/* @0x2d6d0c add r2, r2, r2, lsl #16 */
/* @0x2d6d10 add r2, r3, r2, lsl #2 */
/* @0x2d6d14 str r2, [sp, #0xc] */
/* @0x2d6d18 asr r8, r2, #2 */
/* @0x2d6d1c str r8, [sp] */
/* @0x2d6d20 cmp r8, #0 */
/* @0x2d6d24 movle r3, r2 */
/* @0x2d6d28 movle r12, lr */
/* @0x2d6d2c ble 0x2d7300 <_ZN16b2ParticleSystem11SolveZombieEv+0xcf4> */
/* @0x2d6d30 ldr r3, [lr] */
/* @0x2d6d34 cmp r3, #0 */
/* @0x2d6d38 blt 0x2d7264 <_ZN16b2ParticleSystem11SolveZombieEv+0xc58> */
/* @0x2d6d3c ldr r3, [lr, #0x4] */
/* @0x2d6d40 cmp r3, #0 */
/* @0x2d6d44 blt 0x2d7264 <_ZN16b2ParticleSystem11SolveZombieEv+0xc58> */
/* @0x2d6d48 ldr r3, [lr, #0x14] */
/* @0x2d6d4c add r12, lr, #20 */
/* @0x2d6d50 cmp r3, #0 */
/* @0x2d6d54 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834> */
/* @0x2d6d58 ldr r3, [lr, #0x18] */
/* @0x2d6d5c cmp r3, #0 */
/* @0x2d6d60 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834> */
/* @0x2d6d64 ldr r3, [lr, #0x28] */
/* @0x2d6d68 add r1, lr, #40 */
/* @0x2d6d6c str r1, [sp, #0x4] */
/* @0x2d6d70 cmp r3, #0 */
/* @0x2d6d74 mov r12, r1 */
/* @0x2d6d78 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834> */
/* @0x2d6d7c add r9, lr, #60 */
/* @0x2d6d80 add r6, lr, #80 */
/* @0x2d6d84 add r10, lr, #100 */
/* @0x2d6d88 mov r2, lr */
/* @0x2d6d8c add r1, lr, #120 */
/* @0x2d6d90 str r1, [sp, #0x8] */
/* @0x2d6d94 ldr r8, [sp, #0x4] */
/* @0x2d6d98 rsb r3, lr, r2 */
/* @0x2d6d9c add r1, r3, r9 */
/* @0x2d6da0 add r7, r3, r6 */
/* @0x2d6da4 add r0, r3, r8 */
/* @0x2d6da8 ldr r0, [r0, #0x4] */
/* @0x2d6dac cmp r0, #0 */
/* @0x2d6db0 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834> */
/* @0x2d6db4 ldr r0, [r3, r9] */
/* @0x2d6db8 add r12, r2, #60 */
/* @0x2d6dbc cmp r0, #0 */
/* @0x2d6dc0 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834> */
/* @0x2d6dc4 ldr r1, [r1, #0x4] */
/* @0x2d6dc8 add r8, r3, r10 */
/* @0x2d6dcc cmp r1, #0 */
/* @0x2d6dd0 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834> */
/* @0x2d6dd4 ldr r1, [sp] */
/* @0x2d6dd8 add r12, r2, #80 */
/* @0x2d6ddc rsb r11, lr, r12 */
/* @0x2d6de0 subs r1, r1, #1 */
/* @0x2d6de4 str r1, [sp] */
/* @0x2d6de8 ldr r1, [sp, #0x8] */
/* @0x2d6dec mov r0, r12 */
/* @0x2d6df0 add r11, r11, r1 */
/* @0x2d6df4 beq 0x2d72e0 <_ZN16b2ParticleSystem11SolveZombieEv+0xcd4> */
/* @0x2d6df8 ldr r1, [r3, r6] */
/* @0x2d6dfc cmp r1, #0 */
/* @0x2d6e00 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834> */
/* @0x2d6e04 ldr r1, [r7, #0x4] */
/* @0x2d6e08 cmp r1, #0 */
/* @0x2d6e0c blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834> */
/* @0x2d6e10 ldr r3, [r3, r10] */
/* @0x2d6e14 add r12, r2, #100 */
/* @0x2d6e18 cmp r3, #0 */
/* @0x2d6e1c blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834> */
/* @0x2d6e20 ldr r3, [r8, #0x4] */
/* @0x2d6e24 cmp r3, #0 */
/* @0x2d6e28 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834> */
/* @0x2d6e2c ldr r3, [r11, #-0x50] */
/* @0x2d6e30 add r12, r2, #120 */
/* @0x2d6e34 mov r2, r0 */
/* @0x2d6e38 cmp r3, #0 */
/* @0x2d6e3c bge 0x2d6d94 <_ZN16b2ParticleSystem11SolveZombieEv+0x788> */
/* @0x2d6e40 ldr r2, [sp, #0x10] */
/* @0x2d6e44 cmp r2, r12 */
/* @0x2d6e48 beq 0x2d6ecc <_ZN16b2ParticleSystem11SolveZombieEv+0x8c0> */
/* @0x2d6e4c add r3, r12, #20 */
/* @0x2d6e50 cmp r2, r3 */
/* @0x2d6e54 beq 0x2d6eac <_ZN16b2ParticleSystem11SolveZombieEv+0x8a0> */
/* @0x2d6e58 add r6, r12, #40 */
/* @0x2d6e5c add r9, r12, #60 */
/* @0x2d6e60 rsb r3, r6, r2 */
/* @0x2d6e64 bic r3, r3, #3 */
/* @0x2d6e68 add r9, r9, r3 */
/* @0x2d6e6c ldr r3, [r6, #-0x14] */
/* @0x2d6e70 sub r8, r6, #20 */
/* @0x2d6e74 mov r7, r12 */
/* @0x2d6e78 cmp r3, #0 */
/* @0x2d6e7c blt 0x2d6ea0 <_ZN16b2ParticleSystem11SolveZombieEv+0x894> */
/* @0x2d6e80 ldr r3, [r6, #-0x10] */
/* @0x2d6e84 cmp r3, #0 */
/* @0x2d6e88 blt 0x2d6ea0 <_ZN16b2ParticleSystem11SolveZombieEv+0x894> */
/* @0x2d6e8c ldm r8!, {r0, r1, r2, r3} */
/* @0x2d6e90 add r12, r12, #20 */
/* @0x2d6e94 stm r7!, {r0, r1, r2, r3} */
/* @0x2d6e98 ldr r3, [r8] */
/* @0x2d6e9c str r3, [r7] */
/* @0x2d6ea0 add r6, r6, #20 */
/* @0x2d6ea4 cmp r6, r9 */
/* @0x2d6ea8 bne 0x2d6e6c <_ZN16b2ParticleSystem11SolveZombieEv+0x860> */
/* @0x2d6eac rsb r3, lr, r12 */
/* @0x2d6eb0 asr r3, r3, #2 */
/* @0x2d6eb4 add r2, r3, r3, lsl #1 */
/* @0x2d6eb8 add r2, r2, r2, lsl #4 */
/* @0x2d6ebc add r2, r2, r2, lsl #8 */
/* @0x2d6ec0 add r2, r2, r2, lsl #16 */
/* @0x2d6ec4 add r2, r3, r2, lsl #2 */
/* @0x2d6ec8 str r2, [sp, #0xc] */
/* @0x2d6ecc ldr lr, [r5, #0x98] */
/* @0x2d6ed0 ldr r3, [sp, #0xc] */
/* @0x2d6ed4 cmp lr, #0 */
/* @0x2d6ed8 lslle r7, lr, #4 */
/* @0x2d6edc str r3, [r5, #0x8c] */
/* @0x2d6ee0 ldrle r6, [r5, #0xa0] */
/* @0x2d6ee4 ble 0x2d6f30 <_ZN16b2ParticleSystem11SolveZombieEv+0x924> */
/* @0x2d6ee8 lsl r7, lr, #4 */
/* @0x2d6eec ldr r6, [r5, #0xa0] */
/* @0x2d6ef0 rsb r12, lr, r7 */
/* @0x2d6ef4 add r3, r6, #8 */
/* @0x2d6ef8 add r12, r6, r12, lsl #2 */
/* @0x2d6efc mov r2, r6 */
/* @0x2d6f00 ldmdb r3, {r0, r1} */
/* @0x2d6f04 add r2, r2, #60 */
/* @0x2d6f08 add r3, r3, #60 */
/* @0x2d6f0c ldr r0, [r4, r0, lsl #2] */
/* @0x2d6f10 str r0, [r3, #-0x44] */
/* @0x2d6f14 ldr r1, [r4, r1, lsl #2] */
/* @0x2d6f18 str r1, [r3, #-0x40] */
/* @0x2d6f1c ldr r1, [r2, #-0x34] */
/* @0x2d6f20 ldr r1, [r4, r1, lsl #2] */
/* @0x2d6f24 str r1, [r2, #-0x34] */
/* @0x2d6f28 cmp r2, r12 */
/* @0x2d6f2c bne 0x2d6f00 <_ZN16b2ParticleSystem11SolveZombieEv+0x8f4> */
/* @0x2d6f30 rsb lr, lr, r7 */
/* @0x2d6f34 sbfx r3, lr, #0x0, #0x1e */
/* @0x2d6f38 add lr, r6, lr, lsl #2 */
/* @0x2d6f3c str lr, [sp, #0x8] */
/* @0x2d6f40 add r3, r3, r3, lsl #4 */
/* @0x2d6f44 add r3, r3, r3, lsl #8 */
/* @0x2d6f48 add r3, r3, r3, lsl #16 */
/* @0x2d6f4c rsb r3, r3, #0 */
/* @0x2d6f50 str r3, [sp, #0x4] */
/* @0x2d6f54 asr r11, r3, #2 */
/* @0x2d6f58 cmp r11, #0 */
/* @0x2d6f5c movle r12, r6 */
/* @0x2d6f60 ble 0x2d7288 <_ZN16b2ParticleSystem11SolveZombieEv+0xc7c> */
/* @0x2d6f64 ldr r3, [r6] */
/* @0x2d6f68 cmp r3, #0 */
/* @0x2d6f6c blt 0x2d7254 <_ZN16b2ParticleSystem11SolveZombieEv+0xc48> */
/* @0x2d6f70 ldr r3, [r6, #0x4] */
/* @0x2d6f74 cmp r3, #0 */
/* @0x2d6f78 blt 0x2d7254 <_ZN16b2ParticleSystem11SolveZombieEv+0xc48> */
/* @0x2d6f7c ldr r3, [r6, #0x8] */
/* @0x2d6f80 cmp r3, #0 */
/* @0x2d6f84 blt 0x2d7254 <_ZN16b2ParticleSystem11SolveZombieEv+0xc48> */
/* @0x2d6f88 ldr r3, [r6, #0x3c] */
/* @0x2d6f8c add r9, r6, #60 */
/* @0x2d6f90 cmp r3, #0 */
/* @0x2d6f94 mov r12, r9 */
/* @0x2d6f98 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d6f9c ldr r3, [r6, #0x40] */
/* @0x2d6fa0 cmp r3, #0 */
/* @0x2d6fa4 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d6fa8 add r8, r6, #240 */
/* @0x2d6fac add r3, r6, #248 */
/* @0x2d6fb0 str r8, [sp] */
/* @0x2d6fb4 mov r1, r6 */
/* @0x2d6fb8 add lr, r6, #120 */
/* @0x2d6fbc add r7, r6, #180 */
/* @0x2d6fc0 add r8, r6, #300 */
/* @0x2d6fc4 b 0x2d7008 <_ZN16b2ParticleSystem11SolveZombieEv+0x9fc> */
/* @0x2d6fc8 ldr r0, [r3, #-0x4] */
/* @0x2d6fcc cmp r0, #0 */
/* @0x2d6fd0 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d6fd4 ldr r0, [r3] */
/* @0x2d6fd8 cmp r0, #0 */
/* @0x2d6fdc blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d6fe0 ldr r0, [r2, r8] */
/* @0x2d6fe4 add r12, r1, #300 */
/* @0x2d6fe8 cmp r0, #0 */
/* @0x2d6fec blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d6ff0 add r2, r2, r8 */
/* @0x2d6ff4 add r3, r3, #240 */
/* @0x2d6ff8 ldr r2, [r2, #0x4] */
/* @0x2d6ffc cmp r2, #0 */
/* @0x2d7000 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d7004 mov r1, r10 */
/* @0x2d7008 ldr r2, [sp] */
/* @0x2d700c rsb r0, r2, r3 */
/* @0x2d7010 ldr r2, [r0, r9] */
/* @0x2d7014 cmp r2, #0 */
/* @0x2d7018 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d701c rsb r2, r6, r1 */
/* @0x2d7020 add r12, r1, #120 */
/* @0x2d7024 ldr r10, [r2, lr] */
/* @0x2d7028 cmp r10, #0 */
/* @0x2d702c blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d7030 add r10, r2, lr */
/* @0x2d7034 ldr r10, [r10, #0x4] */
/* @0x2d7038 cmp r10, #0 */
/* @0x2d703c blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d7040 ldr r10, [r0, lr] */
/* @0x2d7044 cmp r10, #0 */
/* @0x2d7048 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d704c ldr r10, [r2, r7] */
/* @0x2d7050 add r12, r1, #180 */
/* @0x2d7054 cmp r10, #0 */
/* @0x2d7058 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d705c add r10, r2, r7 */
/* @0x2d7060 ldr r10, [r10, #0x4] */
/* @0x2d7064 cmp r10, #0 */
/* @0x2d7068 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d706c ldr r0, [r0, r7] */
/* @0x2d7070 cmp r0, #0 */
/* @0x2d7074 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d7078 add r12, r1, #240 */
/* @0x2d707c subs r11, r11, #1 */
/* @0x2d7080 mov r10, r12 */
/* @0x2d7084 beq 0x2d726c <_ZN16b2ParticleSystem11SolveZombieEv+0xc60> */
/* @0x2d7088 ldr r0, [r3, #-0x8] */
/* @0x2d708c cmp r0, #0 */
/* @0x2d7090 bge 0x2d6fc8 <_ZN16b2ParticleSystem11SolveZombieEv+0x9bc> */
/* @0x2d7094 ldr r1, [sp, #0x8] */
/* @0x2d7098 cmp r1, r12 */
/* @0x2d709c beq 0x2d7138 <_ZN16b2ParticleSystem11SolveZombieEv+0xb2c> */
/* @0x2d70a0 add r3, r12, #60 */
/* @0x2d70a4 cmp r1, r3 */
/* @0x2d70a8 beq 0x2d711c <_ZN16b2ParticleSystem11SolveZombieEv+0xb10> */
/* @0x2d70ac add r8, r12, #120 */
/* @0x2d70b0 add r9, r12, #180 */
/* @0x2d70b4 rsb r3, r8, r1 */
/* @0x2d70b8 bic r3, r3, #3 */
/* @0x2d70bc add r9, r9, r3 */
/* @0x2d70c0 ldr r3, [r8, #-0x3c] */
/* @0x2d70c4 sub r7, r8, #60 */
/* @0x2d70c8 mov lr, r12 */
/* @0x2d70cc cmp r3, #0 */
/* @0x2d70d0 blt 0x2d7110 <_ZN16b2ParticleSystem11SolveZombieEv+0xb04> */
/* @0x2d70d4 ldr r3, [r8, #-0x38] */
/* @0x2d70d8 cmp r3, #0 */
/* @0x2d70dc blt 0x2d7110 <_ZN16b2ParticleSystem11SolveZombieEv+0xb04> */
/* @0x2d70e0 ldr r3, [r8, #-0x34] */
/* @0x2d70e4 cmp r3, #0 */
/* @0x2d70e8 blt 0x2d7110 <_ZN16b2ParticleSystem11SolveZombieEv+0xb04> */
/* @0x2d70ec ldm r7!, {r0, r1, r2, r3} */
/* @0x2d70f0 add r12, r12, #60 */
/* @0x2d70f4 stm lr!, {r0, r1, r2, r3} */
/* @0x2d70f8 ldm r7!, {r0, r1, r2, r3} */
/* @0x2d70fc stm lr!, {r0, r1, r2, r3} */
/* @0x2d7100 ldm r7!, {r0, r1, r2, r3} */
/* @0x2d7104 stm lr!, {r0, r1, r2, r3} */
/* @0x2d7108 ldm r7, {r0, r1, r2} */
/* @0x2d710c stm lr, {r0, r1, r2} */
/* @0x2d7110 add r8, r8, #60 */
/* @0x2d7114 cmp r8, r9 */
/* @0x2d7118 bne 0x2d70c0 <_ZN16b2ParticleSystem11SolveZombieEv+0xab4> */
/* @0x2d711c rsb r3, r6, r12 */
/* @0x2d7120 asr r3, r3, #2 */
/* @0x2d7124 add r3, r3, r3, lsl #4 */
/* @0x2d7128 add r3, r3, r3, lsl #8 */
/* @0x2d712c add r3, r3, r3, lsl #16 */
/* @0x2d7130 rsb r3, r3, #0 */
/* @0x2d7134 str r3, [sp, #0x4] */
/* @0x2d7138 ldr r6, [r5, #0xa8] */
/* @0x2d713c ldr r2, [sp, #0x4] */
/* @0x2d7140 cmp r6, #0 */
/* @0x2d7144 str r2, [r5, #0x98] */
/* @0x2d7148 movne r8, #0 */
/* @0x2d714c ldrne r9, [sp, #0x14] */
/* @0x2d7150 beq 0x2d71d8 <_ZN16b2ParticleSystem11SolveZombieEv+0xbcc> */
/* @0x2d7154 ldmib r6, {r2, lr} */
/* @0x2d7158 cmp r2, lr */
/* @0x2d715c bge 0x2d7238 <_ZN16b2ParticleSystem11SolveZombieEv+0xc2c> */
/* @0x2d7160 mov r7, #0 */
/* @0x2d7164 add r2, r4, r2, lsl #2 */
/* @0x2d7168 add lr, r4, lr, lsl #2 */
/* @0x2d716c mov r12, r9 */
/* @0x2d7170 mov r0, r7 */
/* @0x2d7174 ldr r3, [r2], #4 */
/* @0x2d7178 cmp r3, #0 */
/* @0x2d717c add r1, r3, #1 */
/* @0x2d7180 movlt r7, #1 */
/* @0x2d7184 blt 0x2d7198 <_ZN16b2ParticleSystem11SolveZombieEv+0xb8c> */
/* @0x2d7188 cmp r12, r3 */
/* @0x2d718c movge r12, r3 */
/* @0x2d7190 cmp r0, r1 */
/* @0x2d7194 movlt r0, r1 */
/* @0x2d7198 cmp r2, lr */
/* @0x2d719c bne 0x2d7174 <_ZN16b2ParticleSystem11SolveZombieEv+0xb68> */
/* @0x2d71a0 cmp r12, r0 */
/* @0x2d71a4 bge 0x2d7238 <_ZN16b2ParticleSystem11SolveZombieEv+0xc2c> */
/* @0x2d71a8 cmp r7, #0 */
/* @0x2d71ac str r12, [r6, #0x4] */
/* @0x2d71b0 str r0, [r6, #0x8] */
/* @0x2d71b4 beq 0x2d71cc <_ZN16b2ParticleSystem11SolveZombieEv+0xbc0> */
/* @0x2d71b8 ldr r3, [r6, #0xc] */
/* @0x2d71bc tst r3, #2 */
/* @0x2d71c0 ldrbne r3, [r6, #0x4c] */
/* @0x2d71c4 orrne r3, r3, #4 */
/* @0x2d71c8 strbne r3, [r6, #0x4c] */
/* @0x2d71cc ldr r6, [r6, #0x18] */
/* @0x2d71d0 cmp r6, #0 */
/* @0x2d71d4 bne 0x2d7154 <_ZN16b2ParticleSystem11SolveZombieEv+0xb48> */
/* @0x2d71d8 ldr r8, [sp, #0x14] */
/* @0x2d71dc mov r1, r4 */
/* @0x2d71e0 ldr r0, [r5, #0xd4] */
/* @0x2d71e4 str r8, [r5, #0x24] */
/* @0x2d71e8 add r0, r0, #68 */
/* @0x2d71ec bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv> */
/* @0x2d71f0 ldr r1, [r5, #0xa8] */
/* @0x2d71f4 cmp r1, #0 */
/* @0x2d71f8 bne 0x2d720c <_ZN16b2ParticleSystem11SolveZombieEv+0xc00> */
/* @0x2d71fc b 0x2d7230 <_ZN16b2ParticleSystem11SolveZombieEv+0xc24> */
/* @0x2d7200 cmp r4, #0 */
/* @0x2d7204 mov r1, r4 */
/* @0x2d7208 beq 0x2d7230 <_ZN16b2ParticleSystem11SolveZombieEv+0xc24> */
/* @0x2d720c ldrb r3, [r1, #0x4c] */
/* @0x2d7210 ldr r4, [r1, #0x18] */
/* @0x2d7214 tst r3, #2 */
/* @0x2d7218 beq 0x2d7200 <_ZN16b2ParticleSystem11SolveZombieEv+0xbf4> */
/* @0x2d721c mov r0, r5 */
/* @0x2d7220 bl 0x2d5874 <_ZN16b2ParticleSystem20DestroyParticleGroupEP15b2ParticleGroup> */
/* @0x2d7224 cmp r4, #0 */
/* @0x2d7228 mov r1, r4 */
/* @0x2d722c bne 0x2d720c <_ZN16b2ParticleSystem11SolveZombieEv+0xc00> */
/* @0x2d7230 add sp, sp, #28 */
/* @0x2d7234 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2d7238 ldrb r3, [r6, #0x4c] */
/* @0x2d723c str r8, [r6, #0x4] */
/* @0x2d7240 tst r3, #1 */
/* @0x2d7244 str r8, [r6, #0x8] */
/* @0x2d7248 orrne r3, r3, #2 */
/* @0x2d724c strbne r3, [r6, #0x4c] */
/* @0x2d7250 b 0x2d71cc <_ZN16b2ParticleSystem11SolveZombieEv+0xbc0> */
/* @0x2d7254 mov r12, r6 */
/* @0x2d7258 b 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d725c mov r12, lr */
/* @0x2d7260 b 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448> */
/* @0x2d7264 mov r12, lr */
/* @0x2d7268 b 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834> */
/* @0x2d726c ldr r8, [sp, #0x8] */
/* @0x2d7270 rsb r3, r12, r8 */
/* @0x2d7274 asr r3, r3, #2 */
/* @0x2d7278 add r3, r3, r3, lsl #4 */
/* @0x2d727c add r3, r3, r3, lsl #8 */
/* @0x2d7280 add r3, r3, r3, lsl #16 */
/* @0x2d7284 rsb r3, r3, #0 */
/* @0x2d7288 cmp r3, #2 */
/* @0x2d728c beq 0x2d744c <_ZN16b2ParticleSystem11SolveZombieEv+0xe40> */
/* @0x2d7290 cmp r3, #3 */
/* @0x2d7294 beq 0x2d7424 <_ZN16b2ParticleSystem11SolveZombieEv+0xe18> */
/* @0x2d7298 cmp r3, #1 */
/* @0x2d729c bne 0x2d7138 <_ZN16b2ParticleSystem11SolveZombieEv+0xb2c> */
/* @0x2d72a0 b 0x2d7474 <_ZN16b2ParticleSystem11SolveZombieEv+0xe68> */
/* @0x2d72a4 ldr r3, [sp, #0x10] */
/* @0x2d72a8 rsb r2, r12, r3 */
/* @0x2d72ac asr r2, r2, #3 */
/* @0x2d72b0 add r3, r2, r2, lsl #2 */
/* @0x2d72b4 add r3, r3, r3, lsl #4 */
/* @0x2d72b8 add r3, r3, r3, lsl #8 */
/* @0x2d72bc add r3, r3, r3, lsl #16 */
/* @0x2d72c0 add r3, r2, r3, lsl #1 */
/* @0x2d72c4 cmp r3, #2 */
/* @0x2d72c8 beq 0x2d73bc <_ZN16b2ParticleSystem11SolveZombieEv+0xdb0> */
/* @0x2d72cc cmp r3, #3 */
/* @0x2d72d0 beq 0x2d73a0 <_ZN16b2ParticleSystem11SolveZombieEv+0xd94> */
/* @0x2d72d4 cmp r3, #1 */
/* @0x2d72d8 bne 0x2d6ae0 <_ZN16b2ParticleSystem11SolveZombieEv+0x4d4> */
/* @0x2d72dc b 0x2d73d8 <_ZN16b2ParticleSystem11SolveZombieEv+0xdcc> */
/* @0x2d72e0 ldr r3, [sp, #0x10] */
/* @0x2d72e4 rsb r2, r12, r3 */
/* @0x2d72e8 asr r2, r2, #2 */
/* @0x2d72ec add r3, r2, r2, lsl #1 */
/* @0x2d72f0 add r3, r3, r3, lsl #4 */
/* @0x2d72f4 add r3, r3, r3, lsl #8 */
/* @0x2d72f8 add r3, r3, r3, lsl #16 */
/* @0x2d72fc add r3, r2, r3, lsl #2 */
/* @0x2d7300 cmp r3, #2 */
/* @0x2d7304 beq 0x2d7368 <_ZN16b2ParticleSystem11SolveZombieEv+0xd5c> */
/* @0x2d7308 cmp r3, #3 */
/* @0x2d730c beq 0x2d734c <_ZN16b2ParticleSystem11SolveZombieEv+0xd40> */
/* @0x2d7310 cmp r3, #1 */
/* @0x2d7314 bne 0x2d6ecc <_ZN16b2ParticleSystem11SolveZombieEv+0x8c0> */
/* @0x2d7318 b 0x2d7384 <_ZN16b2ParticleSystem11SolveZombieEv+0xd78> */
/* @0x2d731c ldr r3, [r12] */
/* @0x2d7320 cmp r3, #0 */
/* @0x2d7324 blt 0x2d6c28 <_ZN16b2ParticleSystem11SolveZombieEv+0x61c> */
/* @0x2d7328 add r12, r12, #24 */
/* @0x2d732c ldr r3, [r12] */
/* @0x2d7330 cmp r3, #0 */
/* @0x2d7334 blt 0x2d6c28 <_ZN16b2ParticleSystem11SolveZombieEv+0x61c> */
/* @0x2d7338 add r12, r12, #24 */
/* @0x2d733c ldr r3, [r12] */
/* @0x2d7340 cmp r3, #0 */
/* @0x2d7344 bge 0x2d6c9c <_ZN16b2ParticleSystem11SolveZombieEv+0x690> */
/* @0x2d7348 b 0x2d6c28 <_ZN16b2ParticleSystem11SolveZombieEv+0x61c> */
/* @0x2d734c ldr r3, [r12] */
/* @0x2d7350 cmp r3, #0 */
/* @0x2d7354 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834> */
/* @0x2d7358 ldr r3, [r12, #0x4] */
/* @0x2d735c cmp r3, #0 */
/* @0x2d7360 addge r12, r12, #20 */
/* @0x2d7364 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834> */
/* @0x2d7368 ldr r3, [r12] */
/* @0x2d736c cmp r3, #0 */
/* @0x2d7370 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834> */
/* @0x2d7374 ldr r3, [r12, #0x4] */
/* @0x2d7378 cmp r3, #0 */
/* @0x2d737c addge r12, r12, #20 */
/* @0x2d7380 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834> */
/* @0x2d7384 ldr r3, [r12] */
/* @0x2d7388 cmp r3, #0 */
/* @0x2d738c blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834> */
/* @0x2d7390 ldr r3, [r12, #0x4] */
/* @0x2d7394 cmp r3, #0 */
/* @0x2d7398 bge 0x2d6ecc <_ZN16b2ParticleSystem11SolveZombieEv+0x8c0> */
/* @0x2d739c b 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834> */
/* @0x2d73a0 ldr r3, [r12] */
/* @0x2d73a4 cmp r3, #0 */
/* @0x2d73a8 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448> */
/* @0x2d73ac ldr r3, [r12, #0x4] */
/* @0x2d73b0 cmp r3, #0 */
/* @0x2d73b4 addge r12, r12, #24 */
/* @0x2d73b8 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448> */
/* @0x2d73bc ldr r3, [r12] */
/* @0x2d73c0 cmp r3, #0 */
/* @0x2d73c4 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448> */
/* @0x2d73c8 ldr r3, [r12, #0x4] */
/* @0x2d73cc cmp r3, #0 */
/* @0x2d73d0 addge r12, r12, #24 */
/* @0x2d73d4 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448> */
/* @0x2d73d8 ldr r3, [r12] */
/* @0x2d73dc cmp r3, #0 */
/* @0x2d73e0 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448> */
/* @0x2d73e4 ldr r3, [r12, #0x4] */
/* @0x2d73e8 cmp r3, #0 */
/* @0x2d73ec bge 0x2d6ae0 <_ZN16b2ParticleSystem11SolveZombieEv+0x4d4> */
/* @0x2d73f0 b 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448> */
/* @0x2d73f4 ldr r1, [r3] */
/* @0x2d73f8 cmp r1, #0 */
/* @0x2d73fc blt 0x2d6860 <_ZN16b2ParticleSystem11SolveZombieEv+0x254> */
/* @0x2d7400 add r3, r3, #8 */
/* @0x2d7404 ldr r1, [r3] */
/* @0x2d7408 cmp r1, #0 */
/* @0x2d740c blt 0x2d6860 <_ZN16b2ParticleSystem11SolveZombieEv+0x254> */
/* @0x2d7410 add r3, r3, #8 */
/* @0x2d7414 ldr r1, [r3] */
/* @0x2d7418 cmp r1, #0 */
/* @0x2d741c bge 0x2d68b0 <_ZN16b2ParticleSystem11SolveZombieEv+0x2a4> */
/* @0x2d7420 b 0x2d6860 <_ZN16b2ParticleSystem11SolveZombieEv+0x254> */
/* @0x2d7424 ldr r3, [r12] */
/* @0x2d7428 cmp r3, #0 */
/* @0x2d742c blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d7430 ldr r3, [r12, #0x4] */
/* @0x2d7434 cmp r3, #0 */
/* @0x2d7438 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d743c ldr r3, [r12, #0x8] */
/* @0x2d7440 cmp r3, #0 */
/* @0x2d7444 addge r12, r12, #60 */
/* @0x2d7448 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d744c ldr r3, [r12] */
/* @0x2d7450 cmp r3, #0 */
/* @0x2d7454 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d7458 ldr r3, [r12, #0x4] */
/* @0x2d745c cmp r3, #0 */
/* @0x2d7460 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d7464 ldr r3, [r12, #0x8] */
/* @0x2d7468 cmp r3, #0 */
/* @0x2d746c addge r12, r12, #60 */
/* @0x2d7470 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d7474 ldr r3, [r12] */
/* @0x2d7478 cmp r3, #0 */
/* @0x2d747c blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d7480 ldr r3, [r12, #0x4] */
/* @0x2d7484 cmp r3, #0 */
/* @0x2d7488 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d748c ldr r3, [r12, #0x8] */
/* @0x2d7490 cmp r3, #0 */
/* @0x2d7494 bge 0x2d7138 <_ZN16b2ParticleSystem11SolveZombieEv+0xb2c> */
/* @0x2d7498 b 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88> */
/* @0x2d749c add r3, r1, #40 */
/* @0x2d74a0 b 0x2d6860 <_ZN16b2ParticleSystem11SolveZombieEv+0x254> */
/* @0x2d74a4 add r3, r1, #48 */
/* @0x2d74a8 b 0x2d6860 <_ZN16b2ParticleSystem11SolveZombieEv+0x254> */
/* @0x2d74ac add r12, r3, #120 */
/* @0x2d74b0 b 0x2d6c28 <_ZN16b2ParticleSystem11SolveZombieEv+0x61c> */
/* @0x2d74b4 add r12, r3, #144 */
/* @0x2d74b8 b 0x2d6c28 <_ZN16b2ParticleSystem11SolveZombieEv+0x61c> */
/* @0x2d74bc add r12, r3, #168 */
/* @0x2d74c0 b 0x2d6c28 <_ZN16b2ParticleSystem11SolveZombieEv+0x61c> */
/* @0x2d74c4 add r3, r1, #56 */
/* @0x2d74c8 b 0x2d6860 <_ZN16b2ParticleSystem11SolveZombieEv+0x254> */
/* @0x2d74cc mov r8, #0 */
/* @0x2d74d0 str r8, [sp, #0x14] */
/* @0x2d74d4 b 0x2d6750 <_ZN16b2ParticleSystem11SolveZombieEv+0x144> */
/* @0x2d74d8 mov r12, lr */
/* @0x2d74dc b 0x2d6c28 <_ZN16b2ParticleSystem11SolveZombieEv+0x61c> */
/* @0x2d74e0 mov r3, r10 */
/* @0x2d74e4 mov r12, lr */
/* @0x2d74e8 b 0x2d6c08 <_ZN16b2ParticleSystem11SolveZombieEv+0x5fc> */
/* @0x2d74ec mov r3, r2 */
/* @0x2d74f0 b 0x2d6860 <_ZN16b2ParticleSystem11SolveZombieEv+0x254> */
/* @0x2d74f4 mov r1, r11 */
/* @0x2d74f8 mov r3, r2 */
/* @0x2d74fc b 0x2d6840 <_ZN16b2ParticleSystem11SolveZombieEv+0x234> */

/* ── FUNC 0x2d7500 · b2ParticleSystem::RotateBuffer(int, int, int) · size=3440 · insn=860 */
/* @0x2d7500 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2d7504 vpush {d8} */
/* @0x2d7508 cmp r2, r3 */
/* @0x2d750c cmpne r1, r2 */
/* @0x2d7510 sub sp, sp, #60 */
/* @0x2d7514 mov r4, r1 */
/* @0x2d7518 mov r11, r2 */
/* @0x2d751c str r3, [sp, #0x10] */
/* @0x2d7520 str r0, [sp, #0xc] */
/* @0x2d7524 bne 0x2d7534 <_ZN16b2ParticleSystem12RotateBufferEiii+0x34> */
/* @0x2d7528 add sp, sp, #60 */
/* @0x2d752c vpop {d8} */
/* @0x2d7530 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2d7534 lsl r3, r1, #2 */
/* @0x2d7538 str r3, [sp, #0x20] */
/* @0x2d753c lsl r3, r2, #2 */
/* @0x2d7540 str r3, [sp, #0x24] */
/* @0x2d7544 ldr r3, [sp, #0x10] */
/* @0x2d7548 ldr r8, [r0, #0x30] */
/* @0x2d754c ldr r1, [sp, #0x24] */
/* @0x2d7550 lsl r3, r3, #2 */
/* @0x2d7554 str r3, [sp, #0x28] */
/* @0x2d7558 ldr r3, [sp, #0x20] */
/* @0x2d755c add r10, r8, r3 */
/* @0x2d7560 add r3, r8, r1 */
/* @0x2d7564 rsb r2, r10, r3 */
/* @0x2d7568 asrs r2, r2, #2 */
/* @0x2d756c str r2, [sp, #0x4] */
/* @0x2d7570 beq 0x2d766c <_ZN16b2ParticleSystem12RotateBufferEiii+0x16c> */
/* @0x2d7574 ldr r2, [sp, #0x28] */
/* @0x2d7578 ldr r1, [sp, #0x4] */
/* @0x2d757c add r8, r8, r2 */
/* @0x2d7580 ldr r2, [sp, #0x4] */
/* @0x2d7584 rsb r0, r10, r8 */
/* @0x2d7588 asr r0, r0, #2 */
/* @0x2d758c rsb r2, r2, r0 */
/* @0x2d7590 str r2, [sp, #0x8] */
/* @0x2d7594 cmp r1, r2 */
/* @0x2d7598 ldrne r9, [sp, #0x4] */
/* @0x2d759c bne 0x2d75a8 <_ZN16b2ParticleSystem12RotateBufferEiii+0xa8> */
/* @0x2d75a0 b 0x2d8168 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc68> */
/* @0x2d75a4 mov r9, r1 */
/* @0x2d75a8 mov r1, r9 */
/* @0x2d75ac bl 0x318dec <__aeabi_idivmod> */
/* @0x2d75b0 mov r0, r9 */
/* @0x2d75b4 cmp r1, #0 */
/* @0x2d75b8 bne 0x2d75a4 <_ZN16b2ParticleSystem12RotateBufferEiii+0xa4> */
/* @0x2d75bc cmp r9, #0 */
/* @0x2d75c0 ble 0x2d766c <_ZN16b2ParticleSystem12RotateBufferEiii+0x16c> */
/* @0x2d75c4 ldr r2, [sp, #0x8] */
/* @0x2d75c8 mov r5, r9 */
/* @0x2d75cc mov r9, r1 */
/* @0x2d75d0 str r4, [sp, #0x18] */
/* @0x2d75d4 str r11, [sp, #0x1c] */
/* @0x2d75d8 lsl r3, r2, #2 */
/* @0x2d75dc ldr r2, [sp, #0x4] */
/* @0x2d75e0 rsb r7, r3, #0 */
/* @0x2d75e4 sub r3, r3, #4 */
/* @0x2d75e8 str r3, [sp, #0x14] */
/* @0x2d75ec lsl r6, r2, #2 */
/* @0x2d75f0 rsb r8, r6, r8 */
/* @0x2d75f4 ldr r3, [sp, #0x4] */
/* @0x2d75f8 mov r4, r10 */
/* @0x2d75fc ldr r2, [sp, #0x8] */
/* @0x2d7600 ldr r11, [r10], #4 */
/* @0x2d7604 cmp r3, r2 */
/* @0x2d7608 blt 0x2d7f0c <_ZN16b2ParticleSystem12RotateBufferEiii+0xa0c> */
/* @0x2d760c mov r1, r5 */
/* @0x2d7610 mov r0, r3 */
/* @0x2d7614 bl 0x318d10 <__divsi3> */
/* @0x2d7618 cmp r0, #1 */
/* @0x2d761c subgt r0, r0, #1 */
/* @0x2d7620 movgt r1, #0 */
/* @0x2d7624 ble 0x2d80e8 <_ZN16b2ParticleSystem12RotateBufferEiii+0xbe8> */
/* @0x2d7628 cmp r4, r8 */
/* @0x2d762c add r1, r1, #1 */
/* @0x2d7630 ldrlo r3, [r4, r6] */
/* @0x2d7634 strlo r3, [r4] */
/* @0x2d7638 addlo r4, r4, r6 */
/* @0x2d763c add r3, r4, r7 */
/* @0x2d7640 cmp r1, r0 */
/* @0x2d7644 ldr r2, [r4, r7] */
/* @0x2d7648 str r2, [r4] */
/* @0x2d764c mov r4, r3 */
/* @0x2d7650 bne 0x2d7628 <_ZN16b2ParticleSystem12RotateBufferEiii+0x128> */
/* @0x2d7654 add r9, r9, #1 */
/* @0x2d7658 str r11, [r3] */
/* @0x2d765c cmp r9, r5 */
/* @0x2d7660 bne 0x2d75f4 <_ZN16b2ParticleSystem12RotateBufferEiii+0xf4> */
/* @0x2d7664 ldr r4, [sp, #0x18] */
/* @0x2d7668 ldr r11, [sp, #0x1c] */
/* @0x2d766c ldr r3, [sp, #0xc] */
/* @0x2d7670 lsl r7, r4, #3 */
/* @0x2d7674 lsl r6, r11, #3 */
/* @0x2d7678 ldr r2, [r3, #0x38] */
/* @0x2d767c ldr r3, [sp, #0x10] */
/* @0x2d7680 add r1, r2, r6 */
/* @0x2d7684 add r0, r2, r7 */
/* @0x2d7688 lsl r5, r3, #3 */
/* @0x2d768c add r2, r2, r5 */
/* @0x2d7690 bl 0x2d4de4 <_ZN15b2QueryCallbackD0Ev+0x454> */
/* @0x2d7694 ldr r3, [sp, #0xc] */
/* @0x2d7698 ldr r2, [r3, #0x40] */
/* @0x2d769c add r1, r2, r6 */
/* @0x2d76a0 add r0, r2, r7 */
/* @0x2d76a4 add r2, r2, r5 */
/* @0x2d76a8 bl 0x2d4de4 <_ZN15b2QueryCallbackD0Ev+0x454> */
/* @0x2d76ac ldr r3, [sp, #0xc] */
/* @0x2d76b0 ldr r1, [sp, #0x24] */
/* @0x2d76b4 ldr r8, [r3, #0x5c] */
/* @0x2d76b8 ldr r3, [sp, #0x20] */
/* @0x2d76bc add r10, r8, r3 */
/* @0x2d76c0 add r3, r8, r1 */
/* @0x2d76c4 rsb r2, r10, r3 */
/* @0x2d76c8 asrs r2, r2, #2 */
/* @0x2d76cc str r2, [sp, #0x4] */
/* @0x2d76d0 beq 0x2d77c8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x2c8> */
/* @0x2d76d4 ldr r1, [sp, #0x28] */
/* @0x2d76d8 ldr r2, [sp, #0x4] */
/* @0x2d76dc add r8, r8, r1 */
/* @0x2d76e0 ldr r1, [sp, #0x4] */
/* @0x2d76e4 rsb r0, r10, r8 */
/* @0x2d76e8 asr r0, r0, #2 */
/* @0x2d76ec rsb r2, r2, r0 */
/* @0x2d76f0 str r2, [sp, #0x8] */
/* @0x2d76f4 cmp r1, r2 */
/* @0x2d76f8 ldrne r9, [sp, #0x4] */
/* @0x2d76fc bne 0x2d7708 <_ZN16b2ParticleSystem12RotateBufferEiii+0x208> */
/* @0x2d7700 b 0x2d8130 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc30> */
/* @0x2d7704 mov r9, r1 */
/* @0x2d7708 mov r1, r9 */
/* @0x2d770c bl 0x318dec <__aeabi_idivmod> */
/* @0x2d7710 mov r0, r9 */
/* @0x2d7714 cmp r1, #0 */
/* @0x2d7718 bne 0x2d7704 <_ZN16b2ParticleSystem12RotateBufferEiii+0x204> */
/* @0x2d771c cmp r9, #0 */
/* @0x2d7720 ble 0x2d77c8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x2c8> */
/* @0x2d7724 ldr r2, [sp, #0x8] */
/* @0x2d7728 str r11, [sp, #0x1c] */
/* @0x2d772c mov r11, r1 */
/* @0x2d7730 str r4, [sp, #0x18] */
/* @0x2d7734 lsl r3, r2, #2 */
/* @0x2d7738 ldr r2, [sp, #0x4] */
/* @0x2d773c rsb r7, r3, #0 */
/* @0x2d7740 sub r3, r3, #4 */
/* @0x2d7744 str r3, [sp, #0x14] */
/* @0x2d7748 lsl r6, r2, #2 */
/* @0x2d774c rsb r8, r6, r8 */
/* @0x2d7750 ldr r3, [sp, #0x4] */
/* @0x2d7754 mov r4, r10 */
/* @0x2d7758 ldr r2, [sp, #0x8] */
/* @0x2d775c ldr r5, [r10], #4 */
/* @0x2d7760 cmp r3, r2 */
/* @0x2d7764 blt 0x2d7f6c <_ZN16b2ParticleSystem12RotateBufferEiii+0xa6c> */
/* @0x2d7768 mov r0, r3 */
/* @0x2d776c mov r1, r9 */
/* @0x2d7770 bl 0x318d10 <__divsi3> */
/* @0x2d7774 cmp r0, #1 */
/* @0x2d7778 subgt r0, r0, #1 */
/* @0x2d777c movgt r2, #0 */
/* @0x2d7780 ble 0x2d8100 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc00> */
/* @0x2d7784 cmp r8, r4 */
/* @0x2d7788 add r2, r2, #1 */
/* @0x2d778c ldrhi r3, [r4, r6] */
/* @0x2d7790 strhi r3, [r4] */
/* @0x2d7794 addhi r4, r4, r6 */
/* @0x2d7798 add r3, r4, r7 */
/* @0x2d779c cmp r2, r0 */
/* @0x2d77a0 ldr r1, [r4, r7] */
/* @0x2d77a4 str r1, [r4] */
/* @0x2d77a8 mov r4, r3 */
/* @0x2d77ac bne 0x2d7784 <_ZN16b2ParticleSystem12RotateBufferEiii+0x284> */
/* @0x2d77b0 add r11, r11, #1 */
/* @0x2d77b4 str r5, [r3] */
/* @0x2d77b8 cmp r11, r9 */
/* @0x2d77bc bne 0x2d7750 <_ZN16b2ParticleSystem12RotateBufferEiii+0x250> */
/* @0x2d77c0 ldr r4, [sp, #0x18] */
/* @0x2d77c4 ldr r11, [sp, #0x1c] */
/* @0x2d77c8 ldr r3, [sp, #0xc] */
/* @0x2d77cc ldr r8, [r3, #0x50] */
/* @0x2d77d0 cmp r8, #0 */
/* @0x2d77d4 beq 0x2d78f4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x3f4> */
/* @0x2d77d8 ldr r3, [sp, #0x20] */
/* @0x2d77dc ldr r1, [sp, #0x24] */
/* @0x2d77e0 add r10, r8, r3 */
/* @0x2d77e4 add r3, r8, r1 */
/* @0x2d77e8 rsb r2, r10, r3 */
/* @0x2d77ec asrs r2, r2, #2 */
/* @0x2d77f0 str r2, [sp, #0x4] */
/* @0x2d77f4 beq 0x2d78f4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x3f4> */
/* @0x2d77f8 ldr r2, [sp, #0x28] */
/* @0x2d77fc ldr r1, [sp, #0x4] */
/* @0x2d7800 add r8, r8, r2 */
/* @0x2d7804 ldr r2, [sp, #0x4] */
/* @0x2d7808 rsb r0, r10, r8 */
/* @0x2d780c asr r0, r0, #2 */
/* @0x2d7810 rsb r2, r2, r0 */
/* @0x2d7814 str r2, [sp, #0x14] */
/* @0x2d7818 cmp r1, r2 */
/* @0x2d781c ldrne r9, [sp, #0x4] */
/* @0x2d7820 bne 0x2d782c <_ZN16b2ParticleSystem12RotateBufferEiii+0x32c> */
/* @0x2d7824 b 0x2d81a0 <_ZN16b2ParticleSystem12RotateBufferEiii+0xca0> */
/* @0x2d7828 mov r9, r1 */
/* @0x2d782c mov r1, r9 */
/* @0x2d7830 bl 0x318dec <__aeabi_idivmod> */
/* @0x2d7834 mov r0, r9 */
/* @0x2d7838 cmp r1, #0 */
/* @0x2d783c bne 0x2d7828 <_ZN16b2ParticleSystem12RotateBufferEiii+0x328> */
/* @0x2d7840 cmp r9, #0 */
/* @0x2d7844 ble 0x2d78f4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x3f4> */
/* @0x2d7848 ldr r2, [sp, #0x14] */
/* @0x2d784c mov r5, r9 */
/* @0x2d7850 str r11, [sp, #0x1c] */
/* @0x2d7854 mov r9, r1 */
/* @0x2d7858 ldr r11, [sp, #0x14] */
/* @0x2d785c lsl r3, r2, #2 */
/* @0x2d7860 ldr r2, [sp, #0x4] */
/* @0x2d7864 rsb r7, r3, #0 */
/* @0x2d7868 str r4, [sp, #0x18] */
/* @0x2d786c sub r3, r3, #4 */
/* @0x2d7870 str r3, [sp, #0x8] */
/* @0x2d7874 lsl r6, r2, #2 */
/* @0x2d7878 rsb r8, r6, r8 */
/* @0x2d787c ldr r3, [sp, #0x4] */
/* @0x2d7880 mov r4, r10 */
/* @0x2d7884 vldmia r10!, {s16} */
/* @0x2d7888 cmp r3, r11 */
/* @0x2d788c blt 0x2d7fcc <_ZN16b2ParticleSystem12RotateBufferEiii+0xacc> */
/* @0x2d7890 mov r0, r3 */
/* @0x2d7894 mov r1, r5 */
/* @0x2d7898 bl 0x318d10 <__divsi3> */
/* @0x2d789c cmp r0, #1 */
/* @0x2d78a0 subgt r0, r0, #1 */
/* @0x2d78a4 movgt r2, #0 */
/* @0x2d78a8 ble 0x2d8120 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc20> */
/* @0x2d78ac cmp r8, r4 */
/* @0x2d78b0 add r3, r4, r6 */
/* @0x2d78b4 add r2, r2, #1 */
/* @0x2d78b8 ldrhi r1, [r3] */
/* @0x2d78bc strhi r1, [r4] */
/* @0x2d78c0 movhi r4, r3 */
/* @0x2d78c4 add r3, r4, r7 */
/* @0x2d78c8 cmp r2, r0 */
/* @0x2d78cc ldr r1, [r3] */
/* @0x2d78d0 str r1, [r4] */
/* @0x2d78d4 mov r4, r3 */
/* @0x2d78d8 bne 0x2d78ac <_ZN16b2ParticleSystem12RotateBufferEiii+0x3ac> */
/* @0x2d78dc add r9, r9, #1 */
/* @0x2d78e0 vstr s16, [r3] */
/* @0x2d78e4 cmp r9, r5 */
/* @0x2d78e8 bne 0x2d787c <_ZN16b2ParticleSystem12RotateBufferEiii+0x37c> */
/* @0x2d78ec ldr r4, [sp, #0x18] */
/* @0x2d78f0 ldr r11, [sp, #0x1c] */
/* @0x2d78f4 ldr r3, [sp, #0xc] */
/* @0x2d78f8 ldr r7, [r3, #0x54] */
/* @0x2d78fc cmp r7, #0 */
/* @0x2d7900 beq 0x2d7a4c <_ZN16b2ParticleSystem12RotateBufferEiii+0x54c> */
/* @0x2d7904 ldr r3, [sp, #0x20] */
/* @0x2d7908 add r9, r7, r3 */
/* @0x2d790c ldr r3, [sp, #0x24] */
/* @0x2d7910 add r12, r7, r3 */
/* @0x2d7914 rsb r3, r9, r12 */
/* @0x2d7918 asrs r3, r3, #2 */
/* @0x2d791c str r3, [sp, #0x4] */
/* @0x2d7920 beq 0x2d7a4c <_ZN16b2ParticleSystem12RotateBufferEiii+0x54c> */
/* @0x2d7924 ldr r3, [sp, #0x28] */
/* @0x2d7928 ldr r2, [sp, #0x4] */
/* @0x2d792c add r7, r7, r3 */
/* @0x2d7930 ldr r3, [sp, #0x4] */
/* @0x2d7934 rsb r0, r9, r7 */
/* @0x2d7938 asr r0, r0, #2 */
/* @0x2d793c rsb r2, r2, r0 */
/* @0x2d7940 str r2, [sp, #0x1c] */
/* @0x2d7944 cmp r3, r2 */
/* @0x2d7948 ldrne r10, [sp, #0x4] */
/* @0x2d794c bne 0x2d7958 <_ZN16b2ParticleSystem12RotateBufferEiii+0x458> */
/* @0x2d7950 b 0x2d81d8 <_ZN16b2ParticleSystem12RotateBufferEiii+0xcd8> */
/* @0x2d7954 mov r10, r1 */
/* @0x2d7958 mov r1, r10 */
/* @0x2d795c bl 0x318dec <__aeabi_idivmod> */
/* @0x2d7960 mov r0, r10 */
/* @0x2d7964 cmp r1, #0 */
/* @0x2d7968 bne 0x2d7954 <_ZN16b2ParticleSystem12RotateBufferEiii+0x454> */
/* @0x2d796c cmp r10, #0 */
/* @0x2d7970 ble 0x2d7a4c <_ZN16b2ParticleSystem12RotateBufferEiii+0x54c> */
/* @0x2d7974 ldr r2, [sp, #0x1c] */
/* @0x2d7978 ldr r3, [sp, #0x4] */
/* @0x2d797c str r4, [sp, #0x30] */
/* @0x2d7980 lsl r2, r2, #2 */
/* @0x2d7984 str r11, [sp, #0x34] */
/* @0x2d7988 lsl r5, r3, #2 */
/* @0x2d798c rsb r6, r2, #0 */
/* @0x2d7990 rsb r8, r5, r7 */
/* @0x2d7994 mov r7, r1 */
/* @0x2d7998 str r2, [sp, #0x2c] */
/* @0x2d799c ldr r2, [sp, #0x4] */
/* @0x2d79a0 ldr r3, [sp, #0x1c] */
/* @0x2d79a4 ldrb r11, [r9] */
/* @0x2d79a8 cmp r2, r3 */
/* @0x2d79ac ldrb r2, [r9, #0x1] */
/* @0x2d79b0 ldrb r3, [r9, #0x2] */
/* @0x2d79b4 str r2, [sp, #0x8] */
/* @0x2d79b8 ldrb r2, [r9, #0x3] */
/* @0x2d79bc str r3, [sp, #0x14] */
/* @0x2d79c0 str r2, [sp, #0x18] */
/* @0x2d79c4 blt 0x2d8030 <_ZN16b2ParticleSystem12RotateBufferEiii+0xb30> */
/* @0x2d79c8 mov r1, r10 */
/* @0x2d79cc ldr r0, [sp, #0x4] */
/* @0x2d79d0 bl 0x318d10 <__divsi3> */
/* @0x2d79d4 cmp r0, #1 */
/* @0x2d79d8 subgt r0, r0, #1 */
/* @0x2d79dc movgt r2, r9 */
/* @0x2d79e0 movgt r1, #0 */
/* @0x2d79e4 ble 0x2d8128 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc28> */
/* @0x2d79e8 cmp r8, r2 */
/* @0x2d79ec add r3, r2, r5 */
/* @0x2d79f0 add r1, r1, #1 */
/* @0x2d79f4 ldrhi r12, [r3] */
/* @0x2d79f8 strhi r12, [r2] */
/* @0x2d79fc movhi r2, r3 */
/* @0x2d7a00 add r3, r2, r6 */
/* @0x2d7a04 cmp r1, r0 */
/* @0x2d7a08 ldr r12, [r3] */
/* @0x2d7a0c str r12, [r2] */
/* @0x2d7a10 mov r2, r3 */
/* @0x2d7a14 bne 0x2d79e8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x4e8> */
/* @0x2d7a18 ldr r2, [sp, #0x8] */
/* @0x2d7a1c add r7, r7, #1 */
/* @0x2d7a20 cmp r7, r10 */
/* @0x2d7a24 strb r11, [r3] */
/* @0x2d7a28 add r9, r9, #4 */
/* @0x2d7a2c strb r2, [r3, #0x1] */
/* @0x2d7a30 ldr r2, [sp, #0x14] */
/* @0x2d7a34 strb r2, [r3, #0x2] */
/* @0x2d7a38 ldr r2, [sp, #0x18] */
/* @0x2d7a3c strb r2, [r3, #0x3] */
/* @0x2d7a40 bne 0x2d799c <_ZN16b2ParticleSystem12RotateBufferEiii+0x49c> */
/* @0x2d7a44 ldr r4, [sp, #0x30] */
/* @0x2d7a48 ldr r11, [sp, #0x34] */
/* @0x2d7a4c ldr r3, [sp, #0xc] */
/* @0x2d7a50 ldr r8, [r3, #0x60] */
/* @0x2d7a54 cmp r8, #0 */
/* @0x2d7a58 beq 0x2d7b74 <_ZN16b2ParticleSystem12RotateBufferEiii+0x674> */
/* @0x2d7a5c ldr r3, [sp, #0x20] */
/* @0x2d7a60 ldr r1, [sp, #0x24] */
/* @0x2d7a64 add r10, r8, r3 */
/* @0x2d7a68 add r3, r8, r1 */
/* @0x2d7a6c rsb r2, r10, r3 */
/* @0x2d7a70 asrs r2, r2, #2 */
/* @0x2d7a74 str r2, [sp, #0x4] */
/* @0x2d7a78 beq 0x2d7b74 <_ZN16b2ParticleSystem12RotateBufferEiii+0x674> */
/* @0x2d7a7c ldr r2, [sp, #0x28] */
/* @0x2d7a80 ldr r1, [sp, #0x4] */
/* @0x2d7a84 add r8, r8, r2 */
/* @0x2d7a88 ldr r2, [sp, #0x4] */
/* @0x2d7a8c rsb r0, r10, r8 */
/* @0x2d7a90 asr r0, r0, #2 */
/* @0x2d7a94 rsb r2, r2, r0 */
/* @0x2d7a98 str r2, [sp, #0x8] */
/* @0x2d7a9c cmp r1, r2 */
/* @0x2d7aa0 ldrne r9, [sp, #0x4] */
/* @0x2d7aa4 bne 0x2d7ab0 <_ZN16b2ParticleSystem12RotateBufferEiii+0x5b0> */
/* @0x2d7aa8 b 0x2d8238 <_ZN16b2ParticleSystem12RotateBufferEiii+0xd38> */
/* @0x2d7aac mov r9, r1 */
/* @0x2d7ab0 mov r1, r9 */
/* @0x2d7ab4 bl 0x318dec <__aeabi_idivmod> */
/* @0x2d7ab8 mov r0, r9 */
/* @0x2d7abc cmp r1, #0 */
/* @0x2d7ac0 bne 0x2d7aac <_ZN16b2ParticleSystem12RotateBufferEiii+0x5ac> */
/* @0x2d7ac4 cmp r9, #0 */
/* @0x2d7ac8 ble 0x2d7b74 <_ZN16b2ParticleSystem12RotateBufferEiii+0x674> */
/* @0x2d7acc ldr r2, [sp, #0x8] */
/* @0x2d7ad0 mov r5, r9 */
/* @0x2d7ad4 str r11, [sp, #0x1c] */
/* @0x2d7ad8 mov r11, r1 */
/* @0x2d7adc str r4, [sp, #0x18] */
/* @0x2d7ae0 lsl r3, r2, #2 */
/* @0x2d7ae4 ldr r2, [sp, #0x4] */
/* @0x2d7ae8 rsb r7, r3, #0 */
/* @0x2d7aec sub r3, r3, #4 */
/* @0x2d7af0 str r3, [sp, #0x14] */
/* @0x2d7af4 lsl r6, r2, #2 */
/* @0x2d7af8 rsb r8, r6, r8 */
/* @0x2d7afc ldr r3, [sp, #0x4] */
/* @0x2d7b00 mov r4, r10 */
/* @0x2d7b04 ldr r2, [sp, #0x8] */
/* @0x2d7b08 ldr r9, [r10], #4 */
/* @0x2d7b0c cmp r3, r2 */
/* @0x2d7b10 blt 0x2d8088 <_ZN16b2ParticleSystem12RotateBufferEiii+0xb88> */
/* @0x2d7b14 mov r0, r3 */
/* @0x2d7b18 mov r1, r5 */
/* @0x2d7b1c bl 0x318d10 <__divsi3> */
/* @0x2d7b20 cmp r0, #1 */
/* @0x2d7b24 subgt r0, r0, #1 */
/* @0x2d7b28 movgt r2, #0 */
/* @0x2d7b2c ble 0x2d8118 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc18> */
/* @0x2d7b30 cmp r8, r4 */
/* @0x2d7b34 add r2, r2, #1 */
/* @0x2d7b38 ldrhi r3, [r4, r6] */
/* @0x2d7b3c strhi r3, [r4] */
/* @0x2d7b40 addhi r4, r4, r6 */
/* @0x2d7b44 add r3, r4, r7 */
/* @0x2d7b48 cmp r2, r0 */
/* @0x2d7b4c ldr r1, [r4, r7] */
/* @0x2d7b50 str r1, [r4] */
/* @0x2d7b54 mov r4, r3 */
/* @0x2d7b58 bne 0x2d7b30 <_ZN16b2ParticleSystem12RotateBufferEiii+0x630> */
/* @0x2d7b5c add r11, r11, #1 */
/* @0x2d7b60 str r9, [r3] */
/* @0x2d7b64 cmp r11, r5 */
/* @0x2d7b68 bne 0x2d7afc <_ZN16b2ParticleSystem12RotateBufferEiii+0x5fc> */
/* @0x2d7b6c ldr r4, [sp, #0x18] */
/* @0x2d7b70 ldr r11, [sp, #0x1c] */
/* @0x2d7b74 ldr r3, [sp, #0xc] */
/* @0x2d7b78 ldr r12, [r3, #0x68] */
/* @0x2d7b7c cmp r12, #0 */
/* @0x2d7b80 ble 0x2d7bd8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x6d8> */
/* @0x2d7b84 ldr r3, [sp, #0xc] */
/* @0x2d7b88 lsl r12, r12, #3 */
/* @0x2d7b8c ldr r5, [sp, #0x10] */
/* @0x2d7b90 ldr r0, [r3, #0x70] */
/* @0x2d7b94 mov r3, #0 */
/* @0x2d7b98 ldr r2, [r0, r3] */
/* @0x2d7b9c cmp r4, r2 */
/* @0x2d7ba0 mov r1, r2 */
/* @0x2d7ba4 bgt 0x2d7bc8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x6c8> */
/* @0x2d7ba8 cmp r11, r2 */
/* @0x2d7bac add r1, r5, r2 */
/* @0x2d7bb0 rsb r1, r11, r1 */
/* @0x2d7bb4 bgt 0x2d7bc8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x6c8> */
/* @0x2d7bb8 cmp r5, r2 */
/* @0x2d7bbc add r1, r4, r2 */
/* @0x2d7bc0 rsb r1, r11, r1 */
/* @0x2d7bc4 movle r1, r2 */
/* @0x2d7bc8 str r1, [r0, r3] */
/* @0x2d7bcc add r3, r3, #8 */
/* @0x2d7bd0 cmp r3, r12 */
/* @0x2d7bd4 bne 0x2d7b98 <_ZN16b2ParticleSystem12RotateBufferEiii+0x698> */
/* @0x2d7bd8 ldr r3, [sp, #0xc] */
/* @0x2d7bdc ldr r12, [r3, #0x74] */
/* @0x2d7be0 cmp r12, #0 */
/* @0x2d7be4 ble 0x2d7c8c <_ZN16b2ParticleSystem12RotateBufferEiii+0x78c> */
/* @0x2d7be8 ldr r3, [sp, #0xc] */
/* @0x2d7bec add r12, r12, r12, lsl #1 */
/* @0x2d7bf0 mov r2, #0 */
/* @0x2d7bf4 ldr r5, [sp, #0x10] */
/* @0x2d7bf8 lsl r12, r12, #3 */
/* @0x2d7bfc ldr r0, [r3, #0x7c] */
/* @0x2d7c00 b 0x2d7c48 <_ZN16b2ParticleSystem12RotateBufferEiii+0x748> */
/* @0x2d7c04 cmp r11, r3 */
/* @0x2d7c08 ble 0x2d7c5c <_ZN16b2ParticleSystem12RotateBufferEiii+0x75c> */
/* @0x2d7c0c add r3, r5, r3 */
/* @0x2d7c10 rsb r1, r11, r3 */
/* @0x2d7c14 mov r3, r0 */
/* @0x2d7c18 str r1, [r3, r2]! */
/* @0x2d7c1c ldr r1, [r3, #0x4] */
/* @0x2d7c20 cmp r4, r1 */
/* @0x2d7c24 bgt 0x2d7c38 <_ZN16b2ParticleSystem12RotateBufferEiii+0x738> */
/* @0x2d7c28 cmp r11, r1 */
/* @0x2d7c2c ble 0x2d7c70 <_ZN16b2ParticleSystem12RotateBufferEiii+0x770> */
/* @0x2d7c30 add r1, r5, r1 */
/* @0x2d7c34 rsb r1, r11, r1 */
/* @0x2d7c38 add r2, r2, #24 */
/* @0x2d7c3c str r1, [r3, #0x4] */
/* @0x2d7c40 cmp r2, r12 */
/* @0x2d7c44 beq 0x2d7c8c <_ZN16b2ParticleSystem12RotateBufferEiii+0x78c> */
/* @0x2d7c48 ldr r3, [r0, r2] */
/* @0x2d7c4c cmp r4, r3 */
/* @0x2d7c50 ble 0x2d7c04 <_ZN16b2ParticleSystem12RotateBufferEiii+0x704> */
/* @0x2d7c54 mov r1, r3 */
/* @0x2d7c58 b 0x2d7c14 <_ZN16b2ParticleSystem12RotateBufferEiii+0x714> */
/* @0x2d7c5c cmp r5, r3 */
/* @0x2d7c60 ble 0x2d7c54 <_ZN16b2ParticleSystem12RotateBufferEiii+0x754> */
/* @0x2d7c64 add r3, r4, r3 */
/* @0x2d7c68 rsb r1, r11, r3 */
/* @0x2d7c6c b 0x2d7c14 <_ZN16b2ParticleSystem12RotateBufferEiii+0x714> */
/* @0x2d7c70 cmp r5, r1 */
/* @0x2d7c74 add r2, r2, #24 */
/* @0x2d7c78 addgt r1, r4, r1 */
/* @0x2d7c7c rsbgt r1, r11, r1 */
/* @0x2d7c80 cmp r2, r12 */
/* @0x2d7c84 str r1, [r3, #0x4] */
/* @0x2d7c88 bne 0x2d7c48 <_ZN16b2ParticleSystem12RotateBufferEiii+0x748> */
/* @0x2d7c8c ldr r3, [sp, #0xc] */
/* @0x2d7c90 ldr r12, [r3, #0x80] */
/* @0x2d7c94 cmp r12, #0 */
/* @0x2d7c98 ble 0x2d7cf4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x7f4> */
/* @0x2d7c9c ldr r3, [sp, #0xc] */
/* @0x2d7ca0 add r12, r12, r12, lsl #1 */
/* @0x2d7ca4 ldr r5, [sp, #0x10] */
/* @0x2d7ca8 lsl r12, r12, #3 */
/* @0x2d7cac ldr r0, [r3, #0x88] */
/* @0x2d7cb0 mov r3, #0 */
/* @0x2d7cb4 ldr r2, [r0, r3] */
/* @0x2d7cb8 cmp r4, r2 */
/* @0x2d7cbc mov r1, r2 */
/* @0x2d7cc0 bgt 0x2d7ce4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x7e4> */
/* @0x2d7cc4 cmp r11, r2 */
/* @0x2d7cc8 add r1, r5, r2 */
/* @0x2d7ccc rsb r1, r11, r1 */
/* @0x2d7cd0 bgt 0x2d7ce4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x7e4> */
/* @0x2d7cd4 cmp r5, r2 */
/* @0x2d7cd8 add r1, r4, r2 */
/* @0x2d7cdc rsb r1, r11, r1 */
/* @0x2d7ce0 movle r1, r2 */
/* @0x2d7ce4 str r1, [r0, r3] */
/* @0x2d7ce8 add r3, r3, #24 */
/* @0x2d7cec cmp r3, r12 */
/* @0x2d7cf0 bne 0x2d7cb4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x7b4> */
/* @0x2d7cf4 ldr r3, [sp, #0xc] */
/* @0x2d7cf8 ldr r12, [r3, #0x8c] */
/* @0x2d7cfc cmp r12, #0 */
/* @0x2d7d00 ble 0x2d7da8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x8a8> */
/* @0x2d7d04 ldr r3, [sp, #0xc] */
/* @0x2d7d08 add r12, r12, r12, lsl #2 */
/* @0x2d7d0c mov r2, #0 */
/* @0x2d7d10 ldr r5, [sp, #0x10] */
/* @0x2d7d14 lsl r12, r12, #2 */
/* @0x2d7d18 ldr r0, [r3, #0x94] */
/* @0x2d7d1c b 0x2d7d64 <_ZN16b2ParticleSystem12RotateBufferEiii+0x864> */
/* @0x2d7d20 cmp r11, r3 */
/* @0x2d7d24 ble 0x2d7d78 <_ZN16b2ParticleSystem12RotateBufferEiii+0x878> */
/* @0x2d7d28 add r3, r5, r3 */
/* @0x2d7d2c rsb r1, r11, r3 */
/* @0x2d7d30 mov r3, r0 */
/* @0x2d7d34 str r1, [r3, r2]! */
/* @0x2d7d38 ldr r1, [r3, #0x4] */
/* @0x2d7d3c cmp r4, r1 */
/* @0x2d7d40 bgt 0x2d7d54 <_ZN16b2ParticleSystem12RotateBufferEiii+0x854> */
/* @0x2d7d44 cmp r11, r1 */
/* @0x2d7d48 ble 0x2d7d8c <_ZN16b2ParticleSystem12RotateBufferEiii+0x88c> */
/* @0x2d7d4c add r1, r5, r1 */
/* @0x2d7d50 rsb r1, r11, r1 */
/* @0x2d7d54 add r2, r2, #20 */
/* @0x2d7d58 str r1, [r3, #0x4] */
/* @0x2d7d5c cmp r2, r12 */
/* @0x2d7d60 beq 0x2d7da8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x8a8> */
/* @0x2d7d64 ldr r3, [r0, r2] */
/* @0x2d7d68 cmp r4, r3 */
/* @0x2d7d6c ble 0x2d7d20 <_ZN16b2ParticleSystem12RotateBufferEiii+0x820> */
/* @0x2d7d70 mov r1, r3 */
/* @0x2d7d74 b 0x2d7d30 <_ZN16b2ParticleSystem12RotateBufferEiii+0x830> */
/* @0x2d7d78 cmp r5, r3 */
/* @0x2d7d7c ble 0x2d7d70 <_ZN16b2ParticleSystem12RotateBufferEiii+0x870> */
/* @0x2d7d80 add r3, r4, r3 */
/* @0x2d7d84 rsb r1, r11, r3 */
/* @0x2d7d88 b 0x2d7d30 <_ZN16b2ParticleSystem12RotateBufferEiii+0x830> */
/* @0x2d7d8c cmp r5, r1 */
/* @0x2d7d90 add r2, r2, #20 */
/* @0x2d7d94 addgt r1, r4, r1 */
/* @0x2d7d98 rsbgt r1, r11, r1 */
/* @0x2d7d9c cmp r2, r12 */
/* @0x2d7da0 str r1, [r3, #0x4] */
/* @0x2d7da4 bne 0x2d7d64 <_ZN16b2ParticleSystem12RotateBufferEiii+0x864> */
/* @0x2d7da8 ldr r3, [sp, #0xc] */
/* @0x2d7dac ldr r12, [r3, #0x98] */
/* @0x2d7db0 cmp r12, #0 */
/* @0x2d7db4 ble 0x2d7e80 <_ZN16b2ParticleSystem12RotateBufferEiii+0x980> */
/* @0x2d7db8 ldr r3, [sp, #0xc] */
/* @0x2d7dbc rsb r12, r12, r12, lsl #4 */
/* @0x2d7dc0 ldr r5, [sp, #0x10] */
/* @0x2d7dc4 ldr r2, [r3, #0xa0] */
/* @0x2d7dc8 add r12, r2, r12, lsl #2 */
/* @0x2d7dcc add r3, r2, #8 */
/* @0x2d7dd0 b 0x2d7e38 <_ZN16b2ParticleSystem12RotateBufferEiii+0x938> */
/* @0x2d7dd4 cmp r11, r1 */
/* @0x2d7dd8 ble 0x2d7e5c <_ZN16b2ParticleSystem12RotateBufferEiii+0x95c> */
/* @0x2d7ddc add r1, r5, r1 */
/* @0x2d7de0 rsb r0, r11, r1 */
/* @0x2d7de4 ldr r1, [r3, #-0x4] */
/* @0x2d7de8 str r0, [r3, #-0x8] */
/* @0x2d7dec cmp r4, r1 */
/* @0x2d7df0 bgt 0x2d7e04 <_ZN16b2ParticleSystem12RotateBufferEiii+0x904> */
/* @0x2d7df4 cmp r11, r1 */
/* @0x2d7df8 ble 0x2d7e70 <_ZN16b2ParticleSystem12RotateBufferEiii+0x970> */
/* @0x2d7dfc add r1, r5, r1 */
/* @0x2d7e00 rsb r1, r11, r1 */
/* @0x2d7e04 str r1, [r3, #-0x4] */
/* @0x2d7e08 ldr r1, [r2, #0x8] */
/* @0x2d7e0c cmp r4, r1 */
/* @0x2d7e10 bgt 0x2d7e24 <_ZN16b2ParticleSystem12RotateBufferEiii+0x924> */
/* @0x2d7e14 cmp r11, r1 */
/* @0x2d7e18 ble 0x2d7e4c <_ZN16b2ParticleSystem12RotateBufferEiii+0x94c> */
/* @0x2d7e1c add r1, r5, r1 */
/* @0x2d7e20 rsb r1, r11, r1 */
/* @0x2d7e24 str r1, [r2, #0x8] */
/* @0x2d7e28 add r2, r2, #60 */
/* @0x2d7e2c cmp r2, r12 */
/* @0x2d7e30 add r3, r3, #60 */
/* @0x2d7e34 beq 0x2d7e80 <_ZN16b2ParticleSystem12RotateBufferEiii+0x980> */
/* @0x2d7e38 ldr r1, [r3, #-0x8] */
/* @0x2d7e3c cmp r4, r1 */
/* @0x2d7e40 ble 0x2d7dd4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x8d4> */
/* @0x2d7e44 mov r0, r1 */
/* @0x2d7e48 b 0x2d7de4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x8e4> */
/* @0x2d7e4c cmp r5, r1 */
/* @0x2d7e50 addgt r1, r4, r1 */
/* @0x2d7e54 rsbgt r1, r11, r1 */
/* @0x2d7e58 b 0x2d7e24 <_ZN16b2ParticleSystem12RotateBufferEiii+0x924> */
/* @0x2d7e5c cmp r5, r1 */
/* @0x2d7e60 ble 0x2d7e44 <_ZN16b2ParticleSystem12RotateBufferEiii+0x944> */
/* @0x2d7e64 add r1, r4, r1 */
/* @0x2d7e68 rsb r0, r11, r1 */
/* @0x2d7e6c b 0x2d7de4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x8e4> */
/* @0x2d7e70 cmp r5, r1 */
/* @0x2d7e74 addgt r1, r4, r1 */
/* @0x2d7e78 rsbgt r1, r11, r1 */
/* @0x2d7e7c b 0x2d7e04 <_ZN16b2ParticleSystem12RotateBufferEiii+0x904> */
/* @0x2d7e80 ldr r1, [sp, #0xc] */
/* @0x2d7e84 ldr r3, [r1, #0xa8] */
/* @0x2d7e88 cmp r3, #0 */
/* @0x2d7e8c ldrne r0, [sp, #0x10] */
/* @0x2d7e90 bne 0x2d7ed8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x9d8> */
/* @0x2d7e94 b 0x2d7528 <_ZN16b2ParticleSystem12RotateBufferEiii+0x28> */
/* @0x2d7e98 add r2, r0, r2 */
/* @0x2d7e9c rsb r2, r11, r2 */
/* @0x2d7ea0 ldr r1, [r3, #0x8] */
/* @0x2d7ea4 str r2, [r3, #0x4] */
/* @0x2d7ea8 sub r2, r1, #1 */
/* @0x2d7eac cmp r4, r2 */
/* @0x2d7eb0 bgt 0x2d7ec4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x9c4> */
/* @0x2d7eb4 cmp r11, r2 */
/* @0x2d7eb8 ble 0x2d7efc <_ZN16b2ParticleSystem12RotateBufferEiii+0x9fc> */
/* @0x2d7ebc add r2, r0, r2 */
/* @0x2d7ec0 rsb r2, r11, r2 */
/* @0x2d7ec4 add r2, r2, #1 */
/* @0x2d7ec8 str r2, [r3, #0x8] */
/* @0x2d7ecc ldr r3, [r3, #0x18] */
/* @0x2d7ed0 cmp r3, #0 */
/* @0x2d7ed4 beq 0x2d7528 <_ZN16b2ParticleSystem12RotateBufferEiii+0x28> */
/* @0x2d7ed8 ldr r2, [r3, #0x4] */
/* @0x2d7edc cmp r4, r2 */
/* @0x2d7ee0 bgt 0x2d7ea0 <_ZN16b2ParticleSystem12RotateBufferEiii+0x9a0> */
/* @0x2d7ee4 cmp r11, r2 */
/* @0x2d7ee8 bgt 0x2d7e98 <_ZN16b2ParticleSystem12RotateBufferEiii+0x998> */
/* @0x2d7eec cmp r0, r2 */
/* @0x2d7ef0 addgt r2, r4, r2 */
/* @0x2d7ef4 rsbgt r2, r11, r2 */
/* @0x2d7ef8 b 0x2d7ea0 <_ZN16b2ParticleSystem12RotateBufferEiii+0x9a0> */
/* @0x2d7efc cmp r0, r2 */
/* @0x2d7f00 addgt r2, r4, r2 */
/* @0x2d7f04 rsbgt r2, r11, r2 */
/* @0x2d7f08 b 0x2d7ec4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x9c4> */
/* @0x2d7f0c ldr r0, [sp, #0x8] */
/* @0x2d7f10 mov r1, r5 */
/* @0x2d7f14 bl 0x318d10 <__divsi3> */
/* @0x2d7f18 cmp r0, #0 */
/* @0x2d7f1c ble 0x2d80e8 <_ZN16b2ParticleSystem12RotateBufferEiii+0xbe8> */
/* @0x2d7f20 ldr r3, [sp, #0x14] */
/* @0x2d7f24 mov r1, #0 */
/* @0x2d7f28 add lr, r3, r10 */
/* @0x2d7f2c cmp lr, r4 */
/* @0x2d7f30 add r1, r1, #1 */
/* @0x2d7f34 ldrlo r3, [r4, r7] */
/* @0x2d7f38 strlo r3, [r4] */
/* @0x2d7f3c addlo r4, r4, r7 */
/* @0x2d7f40 add r3, r4, r6 */
/* @0x2d7f44 cmp r1, r0 */
/* @0x2d7f48 ldr r2, [r4, r6] */
/* @0x2d7f4c str r2, [r4] */
/* @0x2d7f50 mov r4, r3 */
/* @0x2d7f54 bne 0x2d7f2c <_ZN16b2ParticleSystem12RotateBufferEiii+0xa2c> */
/* @0x2d7f58 add r9, r9, #1 */
/* @0x2d7f5c str r11, [r3] */
/* @0x2d7f60 cmp r9, r5 */
/* @0x2d7f64 bne 0x2d75f4 <_ZN16b2ParticleSystem12RotateBufferEiii+0xf4> */
/* @0x2d7f68 b 0x2d7664 <_ZN16b2ParticleSystem12RotateBufferEiii+0x164> */
/* @0x2d7f6c ldr r0, [sp, #0x8] */
/* @0x2d7f70 mov r1, r9 */
/* @0x2d7f74 bl 0x318d10 <__divsi3> */
/* @0x2d7f78 cmp r0, #0 */
/* @0x2d7f7c ble 0x2d8100 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc00> */
/* @0x2d7f80 ldr r3, [sp, #0x14] */
/* @0x2d7f84 mov r2, #0 */
/* @0x2d7f88 add r1, r3, r10 */
/* @0x2d7f8c cmp r1, r4 */
/* @0x2d7f90 add r2, r2, #1 */
/* @0x2d7f94 ldrlo r3, [r4, r7] */
/* @0x2d7f98 strlo r3, [r4] */
/* @0x2d7f9c addlo r4, r4, r7 */
/* @0x2d7fa0 add r3, r4, r6 */
/* @0x2d7fa4 cmp r2, r0 */
/* @0x2d7fa8 ldr r12, [r4, r6] */
/* @0x2d7fac str r12, [r4] */
/* @0x2d7fb0 mov r4, r3 */
/* @0x2d7fb4 bne 0x2d7f8c <_ZN16b2ParticleSystem12RotateBufferEiii+0xa8c> */
/* @0x2d7fb8 add r11, r11, #1 */
/* @0x2d7fbc str r5, [r3] */
/* @0x2d7fc0 cmp r11, r9 */
/* @0x2d7fc4 bne 0x2d7750 <_ZN16b2ParticleSystem12RotateBufferEiii+0x250> */
/* @0x2d7fc8 b 0x2d77c0 <_ZN16b2ParticleSystem12RotateBufferEiii+0x2c0> */
/* @0x2d7fcc mov r0, r11 */
/* @0x2d7fd0 mov r1, r5 */
/* @0x2d7fd4 bl 0x318d10 <__divsi3> */
/* @0x2d7fd8 cmp r0, #0 */
/* @0x2d7fdc ble 0x2d8120 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc20> */
/* @0x2d7fe0 ldr r2, [sp, #0x8] */
/* @0x2d7fe4 add r1, r2, r10 */
/* @0x2d7fe8 mov r2, #0 */
/* @0x2d7fec cmp r1, r4 */
/* @0x2d7ff0 add r3, r4, r7 */
/* @0x2d7ff4 add r2, r2, #1 */
/* @0x2d7ff8 ldrlo r12, [r3] */
/* @0x2d7ffc strlo r12, [r4] */
/* @0x2d8000 movlo r4, r3 */
/* @0x2d8004 add r3, r4, r6 */
/* @0x2d8008 cmp r2, r0 */
/* @0x2d800c ldr r12, [r3] */
/* @0x2d8010 str r12, [r4] */
/* @0x2d8014 mov r4, r3 */
/* @0x2d8018 bne 0x2d7fec <_ZN16b2ParticleSystem12RotateBufferEiii+0xaec> */
/* @0x2d801c add r9, r9, #1 */
/* @0x2d8020 vstr s16, [r3] */
/* @0x2d8024 cmp r9, r5 */
/* @0x2d8028 bne 0x2d787c <_ZN16b2ParticleSystem12RotateBufferEiii+0x37c> */
/* @0x2d802c b 0x2d78ec <_ZN16b2ParticleSystem12RotateBufferEiii+0x3ec> */
/* @0x2d8030 ldr r0, [sp, #0x1c] */
/* @0x2d8034 mov r1, r10 */
/* @0x2d8038 bl 0x318d10 <__divsi3> */
/* @0x2d803c cmp r0, #0 */
/* @0x2d8040 ble 0x2d8128 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc28> */
/* @0x2d8044 ldr r3, [sp, #0x2c] */
/* @0x2d8048 mov r2, r9 */
/* @0x2d804c mov r12, #0 */
/* @0x2d8050 add r1, r9, r3 */
/* @0x2d8054 cmp r1, r2 */
/* @0x2d8058 add r3, r2, r6 */
/* @0x2d805c add r12, r12, #1 */
/* @0x2d8060 ldrlo r4, [r3] */
/* @0x2d8064 strlo r4, [r2] */
/* @0x2d8068 movlo r2, r3 */
/* @0x2d806c add r3, r2, r5 */
/* @0x2d8070 cmp r12, r0 */
/* @0x2d8074 ldr r4, [r3] */
/* @0x2d8078 str r4, [r2] */
/* @0x2d807c mov r2, r3 */
/* @0x2d8080 bne 0x2d8054 <_ZN16b2ParticleSystem12RotateBufferEiii+0xb54> */
/* @0x2d8084 b 0x2d7a18 <_ZN16b2ParticleSystem12RotateBufferEiii+0x518> */
/* @0x2d8088 ldr r0, [sp, #0x8] */
/* @0x2d808c mov r1, r5 */
/* @0x2d8090 bl 0x318d10 <__divsi3> */
/* @0x2d8094 cmp r0, #0 */
/* @0x2d8098 ble 0x2d8118 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc18> */
/* @0x2d809c ldr r3, [sp, #0x14] */
/* @0x2d80a0 mov r2, #0 */
/* @0x2d80a4 add r1, r3, r10 */
/* @0x2d80a8 cmp r1, r4 */
/* @0x2d80ac add r2, r2, #1 */
/* @0x2d80b0 ldrlo r3, [r4, r7] */
/* @0x2d80b4 strlo r3, [r4] */
/* @0x2d80b8 addlo r4, r4, r7 */
/* @0x2d80bc add r3, r4, r6 */
/* @0x2d80c0 cmp r2, r0 */
/* @0x2d80c4 ldr r12, [r4, r6] */
/* @0x2d80c8 str r12, [r4] */
/* @0x2d80cc mov r4, r3 */
/* @0x2d80d0 bne 0x2d80a8 <_ZN16b2ParticleSystem12RotateBufferEiii+0xba8> */
/* @0x2d80d4 add r11, r11, #1 */
/* @0x2d80d8 str r9, [r3] */
/* @0x2d80dc cmp r11, r5 */
/* @0x2d80e0 bne 0x2d7afc <_ZN16b2ParticleSystem12RotateBufferEiii+0x5fc> */
/* @0x2d80e4 b 0x2d7b6c <_ZN16b2ParticleSystem12RotateBufferEiii+0x66c> */
/* @0x2d80e8 add r9, r9, #1 */
/* @0x2d80ec mov r3, r4 */
/* @0x2d80f0 cmp r9, r5 */
/* @0x2d80f4 str r11, [r3] */
/* @0x2d80f8 bne 0x2d75f4 <_ZN16b2ParticleSystem12RotateBufferEiii+0xf4> */
/* @0x2d80fc b 0x2d7664 <_ZN16b2ParticleSystem12RotateBufferEiii+0x164> */
/* @0x2d8100 add r11, r11, #1 */
/* @0x2d8104 mov r3, r4 */
/* @0x2d8108 cmp r11, r9 */
/* @0x2d810c str r5, [r3] */
/* @0x2d8110 bne 0x2d7750 <_ZN16b2ParticleSystem12RotateBufferEiii+0x250> */
/* @0x2d8114 b 0x2d77c0 <_ZN16b2ParticleSystem12RotateBufferEiii+0x2c0> */
/* @0x2d8118 mov r3, r4 */
/* @0x2d811c b 0x2d7b5c <_ZN16b2ParticleSystem12RotateBufferEiii+0x65c> */
/* @0x2d8120 mov r3, r4 */
/* @0x2d8124 b 0x2d78dc <_ZN16b2ParticleSystem12RotateBufferEiii+0x3dc> */
/* @0x2d8128 mov r3, r9 */
/* @0x2d812c b 0x2d7a18 <_ZN16b2ParticleSystem12RotateBufferEiii+0x518> */
/* @0x2d8130 cmp r10, r3 */
/* @0x2d8134 beq 0x2d77c8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x2c8> */
/* @0x2d8138 add r2, r10, #4 */
/* @0x2d813c add r0, r3, #4 */
/* @0x2d8140 rsb r2, r2, r3 */
/* @0x2d8144 bic r2, r2, #3 */
/* @0x2d8148 add r0, r0, r2 */
/* @0x2d814c ldr r2, [r10] */
/* @0x2d8150 ldr r1, [r3] */
/* @0x2d8154 str r1, [r10], #4 */
/* @0x2d8158 str r2, [r3], #4 */
/* @0x2d815c cmp r3, r0 */
/* @0x2d8160 bne 0x2d814c <_ZN16b2ParticleSystem12RotateBufferEiii+0xc4c> */
/* @0x2d8164 b 0x2d77c8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x2c8> */
/* @0x2d8168 cmp r10, r3 */
/* @0x2d816c beq 0x2d766c <_ZN16b2ParticleSystem12RotateBufferEiii+0x16c> */
/* @0x2d8170 add r2, r10, #4 */
/* @0x2d8174 add r0, r3, #4 */
/* @0x2d8178 rsb r2, r2, r3 */
/* @0x2d817c bic r2, r2, #3 */
/* @0x2d8180 add r0, r0, r2 */
/* @0x2d8184 ldr r2, [r10] */
/* @0x2d8188 ldr r1, [r3] */
/* @0x2d818c str r1, [r10], #4 */
/* @0x2d8190 str r2, [r3], #4 */
/* @0x2d8194 cmp r3, r0 */
/* @0x2d8198 bne 0x2d8184 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc84> */
/* @0x2d819c b 0x2d766c <_ZN16b2ParticleSystem12RotateBufferEiii+0x16c> */
/* @0x2d81a0 cmp r10, r3 */
/* @0x2d81a4 beq 0x2d78f4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x3f4> */
/* @0x2d81a8 add r2, r10, #4 */
/* @0x2d81ac add r0, r3, #4 */
/* @0x2d81b0 rsb r2, r2, r3 */
/* @0x2d81b4 bic r2, r2, #3 */
/* @0x2d81b8 add r0, r0, r2 */
/* @0x2d81bc ldr r2, [r10] */
/* @0x2d81c0 ldr r1, [r3] */
/* @0x2d81c4 str r1, [r10], #4 */
/* @0x2d81c8 str r2, [r3], #4 */
/* @0x2d81cc cmp r3, r0 */
/* @0x2d81d0 bne 0x2d81bc <_ZN16b2ParticleSystem12RotateBufferEiii+0xcbc> */
/* @0x2d81d4 b 0x2d78f4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x3f4> */
/* @0x2d81d8 cmp r9, r12 */
/* @0x2d81dc beq 0x2d7a4c <_ZN16b2ParticleSystem12RotateBufferEiii+0x54c> */
/* @0x2d81e0 add r2, r9, #4 */
/* @0x2d81e4 add r0, r12, #4 */
/* @0x2d81e8 mov r3, r12 */
/* @0x2d81ec mov r1, r2 */
/* @0x2d81f0 ldrb r8, [r1, #-0x4] */
/* @0x2d81f4 cmp r12, r2 */
/* @0x2d81f8 ldrb r7, [r9, #0x1] */
/* @0x2d81fc add r1, r1, #4 */
/* @0x2d8200 ldrb r6, [r9, #0x2] */
/* @0x2d8204 add r0, r0, #4 */
/* @0x2d8208 ldrb r5, [r9, #0x3] */
/* @0x2d820c add r3, r3, #4 */
/* @0x2d8210 ldr r10, [r0, #-0x8] */
/* @0x2d8214 mov r9, r2 */
/* @0x2d8218 add r2, r2, #4 */
/* @0x2d821c str r10, [r1, #-0x8] */
/* @0x2d8220 strb r8, [r0, #-0x8] */
/* @0x2d8224 strb r7, [r3, #-0x3] */
/* @0x2d8228 strb r6, [r3, #-0x2] */
/* @0x2d822c strb r5, [r3, #-0x1] */
/* @0x2d8230 bne 0x2d81f0 <_ZN16b2ParticleSystem12RotateBufferEiii+0xcf0> */
/* @0x2d8234 b 0x2d7a4c <_ZN16b2ParticleSystem12RotateBufferEiii+0x54c> */
/* @0x2d8238 cmp r10, r3 */
/* @0x2d823c beq 0x2d7b74 <_ZN16b2ParticleSystem12RotateBufferEiii+0x674> */
/* @0x2d8240 add r2, r10, #4 */
/* @0x2d8244 add r0, r3, #4 */
/* @0x2d8248 rsb r2, r2, r3 */
/* @0x2d824c bic r2, r2, #3 */
/* @0x2d8250 add r0, r0, r2 */
/* @0x2d8254 ldr r2, [r10] */
/* @0x2d8258 ldr r1, [r3] */
/* @0x2d825c str r1, [r10], #4 */
/* @0x2d8260 str r2, [r3], #4 */
/* @0x2d8264 cmp r3, r0 */
/* @0x2d8268 bne 0x2d8254 <_ZN16b2ParticleSystem12RotateBufferEiii+0xd54> */
/* @0x2d826c b 0x2d7b74 <_ZN16b2ParticleSystem12RotateBufferEiii+0x674> */

/* ── FUNC 0x2d8270 · b2ParticleSystem::SetParticleRadius(float) · size=36 · insn=9 */
/* @0x2d8270 vmov s13, r1 */
/* @0x2d8274 vmov.f32 s14, #1.000000e+00 */
/* @0x2d8278 vadd.f32 s15, s13, s13 */
/* @0x2d827c vdiv.f32 s14, s14, s15 */
/* @0x2d8280 vstr s15, [r0, #24] */
/* @0x2d8284 vmul.f32 s15, s15, s15 */
/* @0x2d8288 vstr s14, [r0, #28] */
/* @0x2d828c vstr s15, [r0, #32] */
/* @0x2d8290 bx lr */

/* ── FUNC 0x2d8294 · b2ParticleSystem::SetParticleDensity(float) · size=24 · insn=6 */
/* @0x2d8294 vmov.f32 s14, #1.000000e+00 */
/* @0x2d8298 str r1, [r0, #0xc] */
/* @0x2d829c vmov s15, r1 */
/* @0x2d82a0 vdiv.f32 s15, s14, s15 */
/* @0x2d82a4 vstr s15, [r0, #16] */
/* @0x2d82a8 bx lr */

/* ── FUNC 0x2d82ac · b2ParticleSystem::GetParticleDensity() const · size=8 · insn=2 */
/* @0x2d82ac ldr r0, [r0, #0xc] */
/* @0x2d82b0 bx lr */

/* ── FUNC 0x2d82b4 · b2ParticleSystem::SetParticleGravityScale(float) · size=8 · insn=2 */
/* @0x2d82b4 str r1, [r0, #0x14] */
/* @0x2d82b8 bx lr */

/* ── FUNC 0x2d82bc · b2ParticleSystem::GetParticleGravityScale() const · size=8 · insn=2 */
/* @0x2d82bc ldr r0, [r0, #0x14] */
/* @0x2d82c0 bx lr */

/* ── FUNC 0x2d82c4 · b2ParticleSystem::SetParticleDamping(float) · size=8 · insn=2 */
/* @0x2d82c4 str r1, [r0, #0xb0] */
/* @0x2d82c8 bx lr */

/* ── FUNC 0x2d82cc · b2ParticleSystem::GetParticleDamping() const · size=8 · insn=2 */
/* @0x2d82cc ldr r0, [r0, #0xb0] */
/* @0x2d82d0 bx lr */

/* ── FUNC 0x2d82d4 · b2ParticleSystem::GetParticleRadius() const · size=20 · insn=5 */
/* @0x2d82d4 vmov.f32 s15, #5.000000e-01 */
/* @0x2d82d8 vldr s14, [r0, #24] */
/* @0x2d82dc vmul.f32 s15, s14, s15 */
/* @0x2d82e0 vmov r0, s15 */
/* @0x2d82e4 bx lr */

/* ── FUNC 0x2d82e8 · b2ParticleSystem::GetCriticalVelocity(b2TimeStep const&) const · size=20 · insn=5 */
/* @0x2d82e8 vldr s14, [r0, #24] */
/* @0x2d82ec vldr s15, [r1, #4] */
/* @0x2d82f0 vmul.f32 s15, s14, s15 */
/* @0x2d82f4 vmov r0, s15 */
/* @0x2d82f8 bx lr */

/* ── FUNC 0x2d82fc · b2ParticleSystem::SolveTensile(b2TimeStep const&) · size=624 · insn=156 */
/* @0x2d82fc push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2d8300 vpush {d8} */
/* @0x2d8304 mov r4, r0 */
/* @0x2d8308 ldr r5, [r0, #0x4c] */
/* @0x2d830c mov r6, r1 */
/* @0x2d8310 cmp r5, #0 */
/* @0x2d8314 beq 0x2d8540 <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep+0x244> */
/* @0x2d8318 ldr r7, [r4, #0x24] */
/* @0x2d831c str r5, [r4, #0x4c] */
/* @0x2d8320 cmp r7, #0 */
/* @0x2d8324 ble 0x2d835c <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep+0x60> */
/* @0x2d8328 ldr r3, [r4, #0x48] */
/* @0x2d832c mov r2, #0 */
/* @0x2d8330 ldr lr, [pc, #0x230] */
/* @0x2d8334 mov r8, #0 */
/* @0x2d8338 add r7, r3, r7, lsl #2 */
/* @0x2d833c ldr lr, [pc, lr] */
/* @0x2d8340 ldm lr, {r0, r1} */
/* @0x2d8344 add r12, r5, r2 */
/* @0x2d8348 str r8, [r3], #4 */
/* @0x2d834c cmp r3, r7 */
/* @0x2d8350 add r2, r2, #8 */
/* @0x2d8354 stm r12, {r0, r1} */
/* @0x2d8358 bne 0x2d8340 <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep+0x44> */
/* @0x2d835c ldr r7, [r4, #0x74] */
/* @0x2d8360 cmp r7, #0 */
/* @0x2d8364 ble 0x2d8418 <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep+0x11c> */
/* @0x2d8368 vmov.f32 s10, #1.000000e+00 */
/* @0x2d836c ldr r3, [r4, #0x7c] */
/* @0x2d8370 add r7, r7, r7, lsl #1 */
/* @0x2d8374 add r2, r3, #8 */
/* @0x2d8378 add r7, r3, r7, lsl #3 */
/* @0x2d837c ldr r1, [r3, #0x8] */
/* @0x2d8380 tst r1, #128 */
/* @0x2d8384 beq 0x2d8408 <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep+0x10c> */
/* @0x2d8388 vldr s15, [r2, #4] */
/* @0x2d838c vsub.f32 s14, s10, s15 */
/* @0x2d8390 ldr lr, [r2, #-0x8] */
/* @0x2d8394 vldr s13, [r3, #16] */
/* @0x2d8398 ldr r1, [r4, #0x48] */
/* @0x2d839c vldr s11, [r3, #20] */
/* @0x2d83a0 ldr r12, [r2, #-0x4] */
/* @0x2d83a4 add r0, r1, lr, lsl #2 */
/* @0x2d83a8 vldr s12, [r0] */
/* @0x2d83ac add lr, r5, lr, lsl #3 */
/* @0x2d83b0 add r1, r1, r12, lsl #2 */
/* @0x2d83b4 add r12, r5, r12, lsl #3 */
/* @0x2d83b8 vmul.f32 s14, s14, s15 */
/* @0x2d83bc vadd.f32 s12, s12, s15 */
/* @0x2d83c0 vmul.f32 s13, s14, s13 */
/* @0x2d83c4 vstr s12, [r0] */
/* @0x2d83c8 vldr s12, [r1] */
/* @0x2d83cc vmul.f32 s14, s14, s11 */
/* @0x2d83d0 vadd.f32 s15, s12, s15 */
/* @0x2d83d4 vstr s15, [r1] */
/* @0x2d83d8 vldr s15, [lr] */
/* @0x2d83dc vldr s12, [lr, #4] */
/* @0x2d83e0 vsub.f32 s15, s15, s13 */
/* @0x2d83e4 vsub.f32 s12, s12, s14 */
/* @0x2d83e8 vstr s15, [lr] */
/* @0x2d83ec vldr s15, [r12] */
/* @0x2d83f0 vstr s12, [lr, #4] */
/* @0x2d83f4 vadd.f32 s13, s15, s13 */
/* @0x2d83f8 vldr s15, [r12, #4] */
/* @0x2d83fc vadd.f32 s14, s15, s14 */
/* @0x2d8400 vstr s13, [r12] */
/* @0x2d8404 vstr s14, [r12, #4] */
/* @0x2d8408 add r3, r3, #24 */
/* @0x2d840c add r2, r2, #24 */
/* @0x2d8410 cmp r3, r7 */
/* @0x2d8414 bne 0x2d837c <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep+0x80> */
/* @0x2d8418 mov r1, r6 */
/* @0x2d841c mov r0, r4 */
/* @0x2d8420 vldr s16, [r4, #192] */
/* @0x2d8424 bl 0x2d82e8 <_ZNK16b2ParticleSystem19GetCriticalVelocityERK10b2TimeStep> */
/* @0x2d8428 mov r1, r6 */
/* @0x2d842c vldr s17, [r4, #196] */
/* @0x2d8430 vmov s15, r0 */
/* @0x2d8434 mov r0, r4 */
/* @0x2d8438 vmul.f32 s16, s16, s15 */
/* @0x2d843c bl 0x2d82e8 <_ZNK16b2ParticleSystem19GetCriticalVelocityERK10b2TimeStep> */
/* @0x2d8440 ldr r7, [r4, #0x74] */
/* @0x2d8444 cmp r7, #0 */
/* @0x2d8448 vmov s15, r0 */
/* @0x2d844c vmul.f32 s5, s17, s15 */
/* @0x2d8450 ble 0x2d8538 <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep+0x23c> */
/* @0x2d8454 ldr r3, [r4, #0x7c] */
/* @0x2d8458 add r7, r7, r7, lsl #1 */
/* @0x2d845c add r2, r3, #8 */
/* @0x2d8460 add r7, r3, r7, lsl #3 */
/* @0x2d8464 vmov.f32 s4, #2.000000e+00 */
/* @0x2d8468 ldr r1, [r3, #0x8] */
/* @0x2d846c tst r1, #128 */
/* @0x2d8470 beq 0x2d8528 <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep+0x22c> */
/* @0x2d8474 ldr r6, [r2, #-0x8] */
/* @0x2d8478 vldr s13, [r3, #20] */
/* @0x2d847c ldr r5, [r2, #-0x4] */
/* @0x2d8480 vldr s14, [r3, #16] */
/* @0x2d8484 ldr r9, [r4, #0x4c] */
/* @0x2d8488 vldr s10, [r2, #4] */
/* @0x2d848c lsl r0, r6, #3 */
/* @0x2d8490 ldr r12, [r4, #0x48] */
/* @0x2d8494 lsl r1, r5, #3 */
/* @0x2d8498 add r8, r9, r0 */
/* @0x2d849c add r9, r9, r1 */
/* @0x2d84a0 vldr s15, [r8, #4] */
/* @0x2d84a4 vldr s12, [r9, #4] */
/* @0x2d84a8 vsub.f32 s15, s12, s15 */
/* @0x2d84ac vldr s6, [r9] */
/* @0x2d84b0 vldr s7, [r8] */
/* @0x2d84b4 add r6, r12, r6, lsl #2 */
/* @0x2d84b8 add r12, r12, r5, lsl #2 */
/* @0x2d84bc vldr s8, [r6] */
/* @0x2d84c0 vldr s9, [r12] */
/* @0x2d84c4 ldr r12, [r4, #0x40] */
/* @0x2d84c8 add r0, r12, r0 */
/* @0x2d84cc vldr s11, [r0] */
/* @0x2d84d0 vldr s12, [r0, #4] */
/* @0x2d84d4 add r1, r12, r1 */
/* @0x2d84d8 vmul.f32 s15, s15, s13 */
/* @0x2d84dc vsub.f32 s7, s6, s7 */
/* @0x2d84e0 vmla.f32 s15, s7, s14 */
/* @0x2d84e4 vadd.f32 s9, s8, s9 */
/* @0x2d84e8 vmul.f32 s15, s5, s15 */
/* @0x2d84ec vsub.f32 s9, s9, s4 */
/* @0x2d84f0 vmla.f32 s15, s9, s16 */
/* @0x2d84f4 vmul.f32 s15, s15, s10 */
/* @0x2d84f8 vmul.f32 s14, s15, s14 */
/* @0x2d84fc vmul.f32 s15, s15, s13 */
/* @0x2d8500 vsub.f32 s13, s11, s14 */
/* @0x2d8504 vsub.f32 s12, s12, s15 */
/* @0x2d8508 vstr s13, [r0] */
/* @0x2d850c vldr s13, [r1] */
/* @0x2d8510 vstr s12, [r0, #4] */
/* @0x2d8514 vadd.f32 s14, s13, s14 */
/* @0x2d8518 vldr s13, [r1, #4] */
/* @0x2d851c vadd.f32 s15, s13, s15 */
/* @0x2d8520 vstr s14, [r1] */
/* @0x2d8524 vstr s15, [r1, #4] */
/* @0x2d8528 add r3, r3, #24 */
/* @0x2d852c add r2, r2, #24 */
/* @0x2d8530 cmp r3, r7 */
/* @0x2d8534 bne 0x2d8468 <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep+0x16c> */
/* @0x2d8538 vpop {d8} */
/* @0x2d853c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2d8540 ldr r1, [r0, #0x28] */
/* @0x2d8544 ldr r0, [r0, #0xd4] */
/* @0x2d8548 lsl r1, r1, #3 */
/* @0x2d854c bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2d8550 ldr r2, [r4, #0x28] */
/* @0x2d8554 mov r1, #0 */
/* @0x2d8558 lsl r2, r2, #3 */
/* @0x2d855c mov r5, r0 */
/* @0x2d8560 bl 0xb65b0 <memset@plt> */
/* @0x2d8564 b 0x2d8318 <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep+0x1c> */
/* @0x2d8568 mulseq r1, r12, r1 */

/* ── FUNC 0x2d856c · b2ParticleSystem::GetCriticalVelocitySquared(b2TimeStep const&) const · size=24 · insn=6 */
/* @0x2d856c push {r3, lr} */
/* @0x2d8570 bl 0x2d82e8 <_ZNK16b2ParticleSystem19GetCriticalVelocityERK10b2TimeStep> */
/* @0x2d8574 vmov s14, r0 */
/* @0x2d8578 vmul.f32 s14, s14, s14 */
/* @0x2d857c vmov r0, s14 */
/* @0x2d8580 pop {r3, pc} */

/* ── FUNC 0x2d8584 · b2ParticleSystem::GetCriticalPressure(b2TimeStep const&) const · size=36 · insn=9 */
/* @0x2d8584 push {r3, lr} */
/* @0x2d8588 vpush {d8} */
/* @0x2d858c vldr s16, [r0, #12] */
/* @0x2d8590 bl 0x2d856c <_ZNK16b2ParticleSystem26GetCriticalVelocitySquaredERK10b2TimeStep> */
/* @0x2d8594 vmov s15, r0 */
/* @0x2d8598 vmul.f32 s15, s16, s15 */
/* @0x2d859c vpop {d8} */
/* @0x2d85a0 vmov r0, s15 */
/* @0x2d85a4 pop {r3, pc} */

/* ── FUNC 0x2d85a8 · b2ParticleSystem::GetParticleStride() const · size=20 · insn=5 */
/* @0x2d85a8 vmov.f32 s15, #7.500000e-01 */
/* @0x2d85ac vldr s14, [r0, #24] */
/* @0x2d85b0 vmul.f32 s15, s14, s15 */
/* @0x2d85b4 vmov r0, s15 */
/* @0x2d85b8 bx lr */

/* ── FUNC 0x2d85bc · b2ParticleSystem::GetParticleMass() const · size=36 · insn=9 */
/* @0x2d85bc push {r4, lr} */
/* @0x2d85c0 mov r4, r0 */
/* @0x2d85c4 bl 0x2d85a8 <_ZNK16b2ParticleSystem17GetParticleStrideEv> */
/* @0x2d85c8 vldr s15, [r4, #12] */
/* @0x2d85cc vmov s14, r0 */
/* @0x2d85d0 vmul.f32 s15, s14, s15 */
/* @0x2d85d4 vmul.f32 s14, s15, s14 */
/* @0x2d85d8 vmov r0, s14 */
/* @0x2d85dc pop {r4, pc} */

/* ── FUNC 0x2d85e0 · anon_2d85e0 · size=1084 · insn=272 */
/* @0x2d85e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2d85e4 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2d85e8 mov r10, r1 */
/* @0x2d85ec ldrb r8, [r1, #0x2c] */
/* @0x2d85f0 sub sp, sp, #68 */
/* @0x2d85f4 mov r7, r0 */
/* @0x2d85f8 cmp r8, #0 */
/* @0x2d85fc beq 0x2d8610 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x54> */
/* @0x2d8600 mov r0, #1 */
/* @0x2d8604 add sp, sp, #68 */
/* @0x2d8608 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2d860c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2d8610 ldr r3, [r7, #0x4] */
/* @0x2d8614 ldr r0, [r1, #0xc] */
/* @0x2d8618 ldr r9, [r1, #0x8] */
/* @0x2d861c ldr r2, [r3, #0x68] */
/* @0x2d8620 ldr r3, [r3, #0x70] */
/* @0x2d8624 ldr r1, [r0] */
/* @0x2d8628 str r3, [sp, #0xc] */
/* @0x2d862c ldr r3, [r1, #0xc] */
/* @0x2d8630 ldr r1, [sp, #0xc] */
/* @0x2d8634 add r2, r1, r2, lsl #3 */
/* @0x2d8638 str r2, [sp, #0x14] */
/* @0x2d863c blx r3 */
/* @0x2d8640 cmp r0, #0 */
/* @0x2d8644 str r0, [sp, #0x18] */
/* @0x2d8648 ble 0x2d8600 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x44> */
/* @0x2d864c vmov.f32 s25, #1.000000e+00 */
/* @0x2d8650 ldr r2, [sp, #0x14] */
/* @0x2d8654 ldr r1, [sp, #0xc] */
/* @0x2d8658 vldr s24, [pc, #940] */
/* @0x2d865c vldr s23, [pc, #940] */
/* @0x2d8660 vldr s22, [pc, #940] */
/* @0x2d8664 rsb r3, r1, r2 */
/* @0x2d8668 vldr s26, [pc, #936] */
/* @0x2d866c vldr s27, [pc, #936] */
/* @0x2d8670 asr r3, r3, #3 */
/* @0x2d8674 str r3, [sp, #0x1c] */
/* @0x2d8678 ldr r2, [r10, #0x18] */
/* @0x2d867c rsb r3, r8, r8, lsl #3 */
/* @0x2d8680 ldr r0, [r7, #0x4] */
/* @0x2d8684 vldr s14, [r0, #24] */
/* @0x2d8688 add r3, r2, r3, lsl #2 */
/* @0x2d868c vldr s18, [r3] */
/* @0x2d8690 vsub.f32 s18, s18, s14 */
/* @0x2d8694 vldr s15, [r0, #28] */
/* @0x2d8698 vldr s20, [r3, #4] */
/* @0x2d869c vldr s19, [r3, #8] */
/* @0x2d86a0 vldr s21, [r3, #12] */
/* @0x2d86a4 ldr r12, [sp, #0x1c] */
/* @0x2d86a8 ldr r4, [sp, #0xc] */
/* @0x2d86ac vmul.f32 s13, s18, s15 */
/* @0x2d86b0 vsub.f32 s20, s20, s14 */
/* @0x2d86b4 vmov.f32 s12, s23 */
/* @0x2d86b8 vmla.f32 s12, s13, s24 */
/* @0x2d86bc vmov.f32 s13, s22 */
/* @0x2d86c0 vmla.f32 s13, s20, s15 */
/* @0x2d86c4 vcvt.u32.f32 s12, s12 */
/* @0x2d86c8 vcvt.u32.f32 s13, s13 */
/* @0x2d86cc vmov r2, s12 */
/* @0x2d86d0 vmov r5, s13 */
/* @0x2d86d4 vadd.f32 s19, s14, s19 */
/* @0x2d86d8 vadd.f32 s21, s14, s21 */
/* @0x2d86dc add r5, r2, r5, lsl #20 */
/* @0x2d86e0 cmp r12, #0 */
/* @0x2d86e4 ble 0x2d8720 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x164> */
/* @0x2d86e8 asr r3, r12, #1 */
/* @0x2d86ec add r1, r4, r3, lsl #3 */
/* @0x2d86f0 ldr r2, [r1, #0x4] */
/* @0x2d86f4 cmp r5, r2 */
/* @0x2d86f8 bls 0x2d8710 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x154> */
/* @0x2d86fc b 0x2d8838 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x27c> */
/* @0x2d8700 ldr r12, [r1, #0x4] */
/* @0x2d8704 cmp r5, r12 */
/* @0x2d8708 bhi 0x2d8840 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x284> */
/* @0x2d870c mov r3, r2 */
/* @0x2d8710 asr r2, r3, #1 */
/* @0x2d8714 cmp r3, #0 */
/* @0x2d8718 add r1, r4, r2, lsl #3 */
/* @0x2d871c bne 0x2d8700 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x144> */
/* @0x2d8720 vmul.f32 s14, s19, s15 */
/* @0x2d8724 ldr r3, [sp, #0x14] */
/* @0x2d8728 mov r5, r4 */
/* @0x2d872c rsb r12, r4, r3 */
/* @0x2d8730 asr r12, r12, #3 */
/* @0x2d8734 vmov.f32 s13, s23 */
/* @0x2d8738 vmla.f32 s13, s14, s24 */
/* @0x2d873c vmov.f32 s14, s13 */
/* @0x2d8740 vmov.f32 s13, s22 */
/* @0x2d8744 vmla.f32 s13, s21, s15 */
/* @0x2d8748 vcvt.u32.f32 s14, s14 */
/* @0x2d874c vcvt.u32.f32 s15, s13 */
/* @0x2d8750 vmov r1, s14 */
/* @0x2d8754 vmov r6, s15 */
/* @0x2d8758 add r6, r1, r6, lsl #20 */
/* @0x2d875c cmp r12, #0 */
/* @0x2d8760 ble 0x2d87a4 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x1e8> */
/* @0x2d8764 asr r3, r12, #1 */
/* @0x2d8768 add r1, r4, r3, lsl #3 */
/* @0x2d876c ldr r2, [r1, #0x4] */
/* @0x2d8770 cmp r6, r2 */
/* @0x2d8774 movhs r2, r3 */
/* @0x2d8778 movhs r3, r12 */
/* @0x2d877c blo 0x2d8794 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x1d8> */
/* @0x2d8780 b 0x2d8850 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x294> */
/* @0x2d8784 ldr r12, [r1, #0x4] */
/* @0x2d8788 cmp r6, r12 */
/* @0x2d878c bhs 0x2d8850 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x294> */
/* @0x2d8790 mov r3, r2 */
/* @0x2d8794 asr r2, r3, #1 */
/* @0x2d8798 cmp r3, #0 */
/* @0x2d879c add r1, r4, r2, lsl #3 */
/* @0x2d87a0 bne 0x2d8784 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x1c8> */
/* @0x2d87a4 cmp r4, r5 */
/* @0x2d87a8 beq 0x2d8818 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x25c> */
/* @0x2d87ac add r2, sp, #44 */
/* @0x2d87b0 add r5, r5, #8 */
/* @0x2d87b4 add r11, sp, #32 */
/* @0x2d87b8 str r2, [sp, #0x10] */
/* @0x2d87bc b 0x2d87c8 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x20c> */
/* @0x2d87c0 ldr r0, [r7, #0x4] */
/* @0x2d87c4 add r5, r5, #8 */
/* @0x2d87c8 ldr r6, [r5, #-0x8] */
/* @0x2d87cc ldr r3, [r0, #0x38] */
/* @0x2d87d0 lsl r6, r6, #3 */
/* @0x2d87d4 add r3, r3, r6 */
/* @0x2d87d8 vldr s16, [r3] */
/* @0x2d87dc vcmpe.f32 s18, s16 */
/* @0x2d87e0 vldr s17, [r3, #4] */
/* @0x2d87e4 vmrs APSR_nzcv, fpscr */
/* @0x2d87e8 bhi 0x2d8810 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x254> */
/* @0x2d87ec vcmpe.f32 s19, s16 */
/* @0x2d87f0 vmrs APSR_nzcv, fpscr */
/* @0x2d87f4 blt 0x2d8810 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x254> */
/* @0x2d87f8 vcmpe.f32 s20, s17 */
/* @0x2d87fc vmrs APSR_nzcv, fpscr */
/* @0x2d8800 bhi 0x2d8810 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x254> */
/* @0x2d8804 vcmpe.f32 s21, s17 */
/* @0x2d8808 vmrs APSR_nzcv, fpscr */
/* @0x2d880c bge 0x2d8860 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x2a4> */
/* @0x2d8810 cmp r5, r4 */
/* @0x2d8814 bne 0x2d87c0 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x204> */
/* @0x2d8818 ldr r3, [sp, #0x18] */
/* @0x2d881c add r8, r8, #1 */
/* @0x2d8820 cmp r8, r3 */
/* @0x2d8824 bne 0x2d8678 <_ZNK16b2ParticleSystem15GetParticleMassEv+0xbc> */
/* @0x2d8828 mov r0, #1 */
/* @0x2d882c add sp, sp, #68 */
/* @0x2d8830 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2d8834 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2d8838 mov r2, r3 */
/* @0x2d883c mov r3, r12 */
/* @0x2d8840 rsb r3, r2, r3 */
/* @0x2d8844 add r4, r1, #8 */
/* @0x2d8848 sub r12, r3, #1 */
/* @0x2d884c b 0x2d86e0 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x124> */
/* @0x2d8850 rsb r3, r2, r3 */
/* @0x2d8854 add r4, r1, #8 */
/* @0x2d8858 sub r12, r3, #1 */
/* @0x2d885c b 0x2d875c <_ZNK16b2ParticleSystem15GetParticleMassEv+0x1a0> */
/* @0x2d8860 vldr s15, [r9, #32] */
/* @0x2d8864 vsub.f32 s15, s17, s15 */
/* @0x2d8868 vldr s9, [r9, #40] */
/* @0x2d886c vldr s8, [r9, #28] */
/* @0x2d8870 vldr s7, [r9, #36] */
/* @0x2d8874 vldr s11, [r9, #24] */
/* @0x2d8878 vldr s10, [r9, #20] */
/* @0x2d887c ldr r3, [r0, #0x40] */
/* @0x2d8880 vldr s12, [r7, #8] */
/* @0x2d8884 vldr s6, [r9, #12] */
/* @0x2d8888 add r3, r3, r6 */
/* @0x2d888c vldr s28, [r3] */
/* @0x2d8890 vldr s29, [r3, #4] */
/* @0x2d8894 vldr s5, [r9, #16] */
/* @0x2d8898 ldr r0, [r10, #0xc] */
/* @0x2d889c mov r1, r11 */
/* @0x2d88a0 ldr r3, [r10, #0x8] */
/* @0x2d88a4 add r2, sp, #44 */
/* @0x2d88a8 vstr s25, [sp, #60] */
/* @0x2d88ac vmul.f32 s14, s15, s9 */
/* @0x2d88b0 ldr r12, [r0] */
/* @0x2d88b4 add r3, r3, #12 */
/* @0x2d88b8 str r8, [sp] */
/* @0x2d88bc ldr r12, [r12, #0x18] */
/* @0x2d88c0 vsub.f32 s8, s16, s8 */
/* @0x2d88c4 vmul.f32 s15, s15, s7 */
/* @0x2d88c8 vmls.f32 s14, s7, s8 */
/* @0x2d88cc vmla.f32 s15, s8, s9 */
/* @0x2d88d0 vmul.f32 s13, s14, s11 */
/* @0x2d88d4 vmul.f32 s14, s14, s10 */
/* @0x2d88d8 vmla.f32 s13, s15, s10 */
/* @0x2d88dc vnmls.f32 s14, s15, s11 */
/* @0x2d88e0 vmov.f32 s11, s16 */
/* @0x2d88e4 vmov.f32 s15, s17 */
/* @0x2d88e8 vmla.f32 s11, s28, s12 */
/* @0x2d88ec vmla.f32 s15, s29, s12 */
/* @0x2d88f0 vstr s11, [sp, #52] */
/* @0x2d88f4 vadd.f32 s13, s13, s5 */
/* @0x2d88f8 vstr s15, [sp, #56] */
/* @0x2d88fc vadd.f32 s14, s14, s6 */
/* @0x2d8900 vstr s13, [sp, #48] */
/* @0x2d8904 vstr s14, [sp, #44] */
/* @0x2d8908 blx r12 */
/* @0x2d890c cmp r0, #0 */
/* @0x2d8910 beq 0x2d8810 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x254> */
/* @0x2d8914 vldr s15, [sp, #40] */
/* @0x2d8918 vldr s30, [sp, #52] */
/* @0x2d891c vldr s31, [sp, #56] */
/* @0x2d8920 vmul.f32 s30, s15, s30 */
/* @0x2d8924 vldr s10, [sp, #48] */
/* @0x2d8928 vldr s9, [sp, #44] */
/* @0x2d892c vldr s12, [sp, #36] */
/* @0x2d8930 vldr s11, [sp, #32] */
/* @0x2d8934 vldr s14, [r7, #12] */
/* @0x2d8938 ldr r0, [r7, #0x4] */
/* @0x2d893c ldr r3, [r0, #0x40] */
/* @0x2d8940 add r6, r3, r6 */
/* @0x2d8944 vmul.f32 s31, s15, s31 */
/* @0x2d8948 vsub.f32 s13, s25, s15 */
/* @0x2d894c vmla.f32 s30, s13, s9 */
/* @0x2d8950 vmla.f32 s31, s13, s10 */
/* @0x2d8954 vmla.f32 s30, s11, s26 */
/* @0x2d8958 vmla.f32 s31, s12, s26 */
/* @0x2d895c vsub.f32 s16, s30, s16 */
/* @0x2d8960 vsub.f32 s17, s31, s17 */
/* @0x2d8964 vmul.f32 s16, s14, s16 */
/* @0x2d8968 vmul.f32 s17, s14, s17 */
/* @0x2d896c vstr s16, [r6] */
/* @0x2d8970 vstr s17, [r6, #4] */
/* @0x2d8974 bl 0x2d85bc <_ZNK16b2ParticleSystem15GetParticleMassEv> */
/* @0x2d8978 ldr r3, [r9] */
/* @0x2d897c vldr s14, [sp, #32] */
/* @0x2d8980 vldr s13, [sp, #36] */
/* @0x2d8984 cmp r3, #2 */
/* @0x2d8988 vmov s15, r0 */
/* @0x2d898c bne 0x2d8810 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x254> */
/* @0x2d8990 ldrh r3, [r9, #4] */
/* @0x2d8994 tst r3, #2 */
/* @0x2d8998 orreq r3, r3, #2 */
/* @0x2d899c vstreq s27, [r9, #160] */
/* @0x2d89a0 strheq r3, [r9, #4] */
/* @0x2d89a4 vsub.f32 s12, s29, s17 */
/* @0x2d89a8 vldr s5, [r9, #64] */
/* @0x2d89ac vldr s6, [r9, #60] */
/* @0x2d89b0 vldr s10, [r9, #88] */
/* @0x2d89b4 vldr s8, [r9, #136] */
/* @0x2d89b8 vldr s9, [r9, #80] */
/* @0x2d89bc vldr s11, [r9, #84] */
/* @0x2d89c0 vldr s7, [r9, #144] */
/* @0x2d89c4 vmul.f32 s12, s15, s12 */
/* @0x2d89c8 vsub.f32 s16, s28, s16 */
/* @0x2d89cc vmul.f32 s12, s12, s13 */
/* @0x2d89d0 vmul.f32 s15, s15, s16 */
/* @0x2d89d4 vmla.f32 s12, s15, s14 */
/* @0x2d89d8 vmul.f32 s14, s14, s12 */
/* @0x2d89dc vsub.f32 s15, s31, s5 */
/* @0x2d89e0 vmul.f32 s13, s13, s12 */
/* @0x2d89e4 vmul.f32 s15, s14, s15 */
/* @0x2d89e8 vsub.f32 s30, s30, s6 */
/* @0x2d89ec vnmls.f32 s15, s13, s30 */
/* @0x2d89f0 vmla.f32 s9, s14, s8 */
/* @0x2d89f4 vmla.f32 s10, s15, s7 */
/* @0x2d89f8 vstr s9, [r9, #80] */
/* @0x2d89fc vmla.f32 s11, s13, s8 */
/* @0x2d8a00 vstr s10, [r9, #88] */
/* @0x2d8a04 vstr s11, [r9, #84] */
/* @0x2d8a08 b 0x2d8810 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x254> */
/* @0x2d8a0c orrmi r0, r0, #0 */
/* @0x2d8a10 .word 0x49000000 */
/* @0x2d8a14 strmi r0, [r0, #-0x0] */
/* @0x2d8a18 bllo 0xfebce648 <b2_toiTime+0xfffffffffe4751a4> */
/* @0x2d8a1c andeq r0, r0, r0 */

/* ── FUNC 0x2d8a20 · b2ParticleSystem::GetParticleInvMass() const · size=36 · insn=9 */
/* @0x2d8a20 vldr s14, [r0, #16] */
/* @0x2d8a24 vldr s15, [pc, #20] */
/* @0x2d8a28 vmul.f32 s14, s14, s15 */
/* @0x2d8a2c vldr s15, [r0, #28] */
/* @0x2d8a30 vmul.f32 s14, s14, s15 */
/* @0x2d8a34 vmul.f32 s14, s15, s14 */
/* @0x2d8a38 vmov r0, s14 */
/* @0x2d8a3c bx lr */
/* @0x2d8a40 svclo #0xe38e32 */
