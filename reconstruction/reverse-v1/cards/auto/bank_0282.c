/* libyoyo.so 覆盖卡组 0282
 * 函数 0x2db370..0x2de9a4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2db370 · b2ParticleSystem::Solve(b2TimeStep const&) · size=816 · insn=204 */
/* @0x2db370 push {r3, r4, r5, r6, r7, lr} */
/* @0x2db374 vpush {d8, d9} */
/* @0x2db378 mov r5, r0 */
/* @0x2db37c ldr r0, [r0, #0x24] */
/* @0x2db380 mov r7, r1 */
/* @0x2db384 ldr r3, [r5] */
/* @0x2db388 cmp r0, #0 */
/* @0x2db38c add r3, r3, #1 */
/* @0x2db390 str r3, [r5] */
/* @0x2db394 beq 0x2db598 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x228> */
/* @0x2db398 mov r1, #0 */
/* @0x2db39c str r1, [r5, #0x4] */
/* @0x2db3a0 ble 0x2db3cc <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x5c> */
/* @0x2db3a4 ldr r3, [r5, #0x30] */
/* @0x2db3a8 add r0, r3, r0, lsl #2 */
/* @0x2db3ac ldr r2, [r3], #4 */
/* @0x2db3b0 orr r2, r2, r1 */
/* @0x2db3b4 cmp r3, r0 */
/* @0x2db3b8 str r2, [r5, #0x4] */
/* @0x2db3bc mov r1, r2 */
/* @0x2db3c0 bne 0x2db3ac <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x3c> */
/* @0x2db3c4 tst r2, #2 */
/* @0x2db3c8 bne 0x2db5b0 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x240> */
/* @0x2db3cc ldr r3, [r5, #0xa8] */
/* @0x2db3d0 mov r1, #0 */
/* @0x2db3d4 str r1, [r5, #0x8] */
/* @0x2db3d8 cmp r3, r1 */
/* @0x2db3dc beq 0x2db3fc <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x8c> */
/* @0x2db3e0 ldr r2, [r3, #0xc] */
/* @0x2db3e4 ldr r3, [r3, #0x18] */
/* @0x2db3e8 orr r2, r1, r2 */
/* @0x2db3ec cmp r3, #0 */
/* @0x2db3f0 mov r1, r2 */
/* @0x2db3f4 bne 0x2db3e0 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x70> */
/* @0x2db3f8 str r2, [r5, #0x8] */
/* @0x2db3fc vldr s15, [r5, #20] */
/* @0x2db400 vldr s18, [r7] */
/* @0x2db404 vmul.f32 s18, s18, s15 */
/* @0x2db408 ldr r3, [r5, #0xd4] */
/* @0x2db40c mov r0, r5 */
/* @0x2db410 mov r1, r7 */
/* @0x2db414 add r2, r3, #102400 */
/* @0x2db418 vldr s17, [r2, #568] */
/* @0x2db41c mov r3, r2 */
/* @0x2db420 vldr s15, [r3, #572] */
/* @0x2db424 vmul.f32 s17, s18, s17 */
/* @0x2db428 vmul.f32 s18, s18, s15 */
/* @0x2db42c bl 0x2d856c <_ZNK16b2ParticleSystem26GetCriticalVelocitySquaredERK10b2TimeStep> */
/* @0x2db430 ldr r3, [r5, #0x24] */
/* @0x2db434 cmp r3, #0 */
/* @0x2db438 movgt r6, #0 */
/* @0x2db43c vmov s16, r0 */
/* @0x2db440 bgt 0x2db55c <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x1ec> */
/* @0x2db444 mov r0, r5 */
/* @0x2db448 mov r1, r7 */
/* @0x2db44c bl 0x2d5cc0 <_ZN16b2ParticleSystem14SolveCollisionERK10b2TimeStep> */
/* @0x2db450 ldr r3, [r5, #0x8] */
/* @0x2db454 tst r3, #2 */
/* @0x2db458 bne 0x2db650 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x2e0> */
/* @0x2db45c ldr r3, [r5, #0x4] */
/* @0x2db460 tst r3, #4 */
/* @0x2db464 bne 0x2db668 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x2f8> */
/* @0x2db468 ldr r1, [r5, #0x24] */
/* @0x2db46c cmp r1, #0 */
/* @0x2db470 ble 0x2db4b8 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x148> */
/* @0x2db474 ldr r2, [r5, #0x40] */
/* @0x2db478 vldr s13, [r7] */
/* @0x2db47c ldr r3, [r5, #0x38] */
/* @0x2db480 add r1, r2, r1, lsl #3 */
/* @0x2db484 vldr s11, [r2, #4] */
/* @0x2db488 vldr s14, [r3, #4] */
/* @0x2db48c vldr s15, [r3] */
/* @0x2db490 mov r0, r2 */
/* @0x2db494 vmla.f32 s14, s13, s11 */
/* @0x2db498 vldr s12, [r0] */
/* @0x2db49c add r2, r2, #8 */
/* @0x2db4a0 add r3, r3, #8 */
/* @0x2db4a4 cmp r2, r1 */
/* @0x2db4a8 vmla.f32 s15, s13, s12 */
/* @0x2db4ac vstr s14, [r3, #-4] */
/* @0x2db4b0 vstr s15, [r3, #-8] */
/* @0x2db4b4 bne 0x2db484 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x114> */
/* @0x2db4b8 mov r0, r5 */
/* @0x2db4bc bl 0x2d5b9c <_ZN16b2ParticleSystem18UpdateBodyContactsEv> */
/* @0x2db4c0 mov r0, r5 */
/* @0x2db4c4 mov r1, #0 */
/* @0x2db4c8 bl 0x2da664 <_ZN16b2ParticleSystem14UpdateContactsEb> */
/* @0x2db4cc ldr r3, [r5, #0x4] */
/* @0x2db4d0 tst r3, #32 */
/* @0x2db4d4 bne 0x2db5bc <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x24c> */
/* @0x2db4d8 tst r3, #64 */
/* @0x2db4dc bne 0x2db5d4 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x264> */
/* @0x2db4e0 tst r3, #128 */
/* @0x2db4e4 bne 0x2db5ec <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x27c> */
/* @0x2db4e8 tst r3, #16 */
/* @0x2db4ec bne 0x2db604 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x294> */
/* @0x2db4f0 tst r3, #8 */
/* @0x2db4f4 bne 0x2db61c <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x2ac> */
/* @0x2db4f8 ldr r3, [r5, #0x8] */
/* @0x2db4fc tst r3, #1 */
/* @0x2db500 bne 0x2db634 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x2c4> */
/* @0x2db504 ldr r3, [r5, #0x4] */
/* @0x2db508 tst r3, #256 */
/* @0x2db50c bne 0x2db5a0 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x230> */
/* @0x2db510 mov r0, r5 */
/* @0x2db514 mov r1, r7 */
/* @0x2db518 bl 0x2d90a4 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep> */
/* @0x2db51c vpop {d8, d9} */
/* @0x2db520 mov r0, r5 */
/* @0x2db524 mov r1, r7 */
/* @0x2db528 pop {r3, r4, r5, r6, r7, lr} */
/* @0x2db52c b 0x2d8a44 <_ZN16b2ParticleSystem12SolveDampingERK10b2TimeStep> */
/* @0x2db530 vdiv.f32 s13, s16, s13 */
/* @0x2db534 vsqrt.f32 s12, s13 */
/* @0x2db538 vcmp.f32 s12, s12 */
/* @0x2db53c vmrs APSR_nzcv, fpscr */
/* @0x2db540 bne 0x2db684 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x314> */
/* @0x2db544 vmul.f32 s14, s14, s12 */
/* @0x2db548 vmul.f32 s15, s15, s12 */
/* @0x2db54c vstr s14, [r4] */
/* @0x2db550 vstr s15, [r4, #4] */
/* @0x2db554 cmp r3, r6 */
/* @0x2db558 ble 0x2db444 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0xd4> */
/* @0x2db55c ldr r4, [r5, #0x40] */
/* @0x2db560 add r4, r4, r6, lsl #3 */
/* @0x2db564 vldr s15, [r4, #4] */
/* @0x2db568 vadd.f32 s15, s18, s15 */
/* @0x2db56c vldr s14, [r4] */
/* @0x2db570 add r6, r6, #1 */
/* @0x2db574 vmul.f32 s13, s15, s15 */
/* @0x2db578 vstr s15, [r4, #4] */
/* @0x2db57c vadd.f32 s14, s17, s14 */
/* @0x2db580 vmla.f32 s13, s14, s14 */
/* @0x2db584 vstr s14, [r4] */
/* @0x2db588 vcmpe.f32 s16, s13 */
/* @0x2db58c vmrs APSR_nzcv, fpscr */
/* @0x2db590 bpl 0x2db554 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x1e4> */
/* @0x2db594 b 0x2db530 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x1c0> */
/* @0x2db598 vpop {d8, d9} */
/* @0x2db59c pop {r3, r4, r5, r6, r7, pc} */
/* @0x2db5a0 mov r0, r5 */
/* @0x2db5a4 mov r1, r7 */
/* @0x2db5a8 bl 0x2d6440 <_ZN16b2ParticleSystem16SolveColorMixingERK10b2TimeStep> */
/* @0x2db5ac b 0x2db510 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x1a0> */
/* @0x2db5b0 mov r0, r5 */
/* @0x2db5b4 bl 0x2d660c <_ZN16b2ParticleSystem11SolveZombieEv> */
/* @0x2db5b8 b 0x2db3cc <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x5c> */
/* @0x2db5bc mov r0, r5 */
/* @0x2db5c0 mov r1, r7 */
/* @0x2db5c4 bl 0x2d8c88 <_ZN16b2ParticleSystem12SolveViscousERK10b2TimeStep> */
/* @0x2db5c8 ldr r3, [r5, #0x4] */
/* @0x2db5cc tst r3, #64 */
/* @0x2db5d0 beq 0x2db4e0 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x170> */
/* @0x2db5d4 mov r0, r5 */
/* @0x2db5d8 mov r1, r7 */
/* @0x2db5dc bl 0x2d8e98 <_ZN16b2ParticleSystem11SolvePowderERK10b2TimeStep> */
/* @0x2db5e0 ldr r3, [r5, #0x4] */
/* @0x2db5e4 tst r3, #128 */
/* @0x2db5e8 beq 0x2db4e8 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x178> */
/* @0x2db5ec mov r0, r5 */
/* @0x2db5f0 mov r1, r7 */
/* @0x2db5f4 bl 0x2d82fc <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep> */
/* @0x2db5f8 ldr r3, [r5, #0x4] */
/* @0x2db5fc tst r3, #16 */
/* @0x2db600 beq 0x2db4f0 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x180> */
/* @0x2db604 mov r0, r5 */
/* @0x2db608 mov r1, r7 */
/* @0x2db60c bl 0x2d5fc0 <_ZN16b2ParticleSystem12SolveElasticERK10b2TimeStep> */
/* @0x2db610 ldr r3, [r5, #0x4] */
/* @0x2db614 tst r3, #8 */
/* @0x2db618 beq 0x2db4f8 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x188> */
/* @0x2db61c mov r0, r5 */
/* @0x2db620 mov r1, r7 */
/* @0x2db624 bl 0x2d620c <_ZN16b2ParticleSystem11SolveSpringERK10b2TimeStep> */
/* @0x2db628 ldr r3, [r5, #0x8] */
/* @0x2db62c tst r3, #1 */
/* @0x2db630 beq 0x2db504 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x194> */
/* @0x2db634 mov r0, r5 */
/* @0x2db638 mov r1, r7 */
/* @0x2db63c bl 0x2d6330 <_ZN16b2ParticleSystem10SolveSolidERK10b2TimeStep> */
/* @0x2db640 ldr r3, [r5, #0x4] */
/* @0x2db644 tst r3, #256 */
/* @0x2db648 beq 0x2db510 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x1a0> */
/* @0x2db64c b 0x2db5a0 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x230> */
/* @0x2db650 mov r0, r5 */
/* @0x2db654 mov r1, r7 */
/* @0x2db658 bl 0x2d5e54 <_ZN16b2ParticleSystem10SolveRigidERK10b2TimeStep> */
/* @0x2db65c ldr r3, [r5, #0x4] */
/* @0x2db660 tst r3, #4 */
/* @0x2db664 beq 0x2db468 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0xf8> */
/* @0x2db668 mov r1, r7 */
/* @0x2db66c mov r0, r5 */
/* @0x2db670 bl 0x2d5e08 <_ZN16b2ParticleSystem9SolveWallERK10b2TimeStep> */
/* @0x2db674 ldr r1, [r5, #0x24] */
/* @0x2db678 cmp r1, #0 */
/* @0x2db67c bgt 0x2db474 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x104> */
/* @0x2db680 b 0x2db4b8 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x148> */
/* @0x2db684 vmov r0, s13 */
/* @0x2db688 bl 0xb6700 <sqrtf@plt> */
/* @0x2db68c ldr r3, [r5, #0x24] */
/* @0x2db690 vldr s14, [r4] */
/* @0x2db694 vldr s15, [r4, #4] */
/* @0x2db698 vmov s12, r0 */
/* @0x2db69c b 0x2db544 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x1d4> */

/* ── FUNC 0x2db6a0 · b2ParticleSystem::JoinParticleGroups(b2ParticleGroup*, b2ParticleGroup*) · size=1164 · insn=291 */
/* @0x2db6a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2db6a4 sub sp, sp, #68 */
/* @0x2db6a8 mov r9, r1 */
/* @0x2db6ac ldr r3, [r0, #0x24] */
/* @0x2db6b0 str r2, [sp, #0x8] */
/* @0x2db6b4 mov r11, r0 */
/* @0x2db6b8 ldr r12, [sp, #0x8] */
/* @0x2db6bc ldr r2, [r2, #0x8] */
/* @0x2db6c0 ldr r1, [r12, #0x4] */
/* @0x2db6c4 bl 0x2d7500 <_ZN16b2ParticleSystem12RotateBufferEiii> */
/* @0x2db6c8 ldr r12, [sp, #0x8] */
/* @0x2db6cc ldmib r9, {r1, r2} */
/* @0x2db6d0 mov r0, r11 */
/* @0x2db6d4 ldr r3, [r12, #0x4] */
/* @0x2db6d8 bl 0x2d7500 <_ZN16b2ParticleSystem12RotateBufferEiii> */
/* @0x2db6dc ldr r12, [sp, #0x8] */
/* @0x2db6e0 ldr r3, [r9, #0x4] */
/* @0x2db6e4 ldr r2, [r12, #0x8] */
/* @0x2db6e8 cmp r3, r2 */
/* @0x2db6ec bge 0x2dbaf8 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x458> */
/* @0x2db6f0 ldr r1, [r11, #0x30] */
/* @0x2db6f4 mov r5, #0 */
/* @0x2db6f8 add r3, r1, r3, lsl #2 */
/* @0x2db6fc add r1, r1, r2, lsl #2 */
/* @0x2db700 ldr r2, [r3], #4 */
/* @0x2db704 cmp r3, r1 */
/* @0x2db708 orr r5, r5, r2 */
/* @0x2db70c bne 0x2db700 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x60> */
/* @0x2db710 mov r0, r11 */
/* @0x2db714 mov r1, #1 */
/* @0x2db718 bl 0x2da664 <_ZN16b2ParticleSystem14UpdateContactsEb> */
/* @0x2db71c tst r5, #8 */
/* @0x2db720 beq 0x2db9c0 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x320> */
/* @0x2db724 ldr r1, [r11, #0x74] */
/* @0x2db728 cmp r1, #0 */
/* @0x2db72c ble 0x2db9c0 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x320> */
/* @0x2db730 ldr r12, [sp, #0x8] */
/* @0x2db734 mov r6, #0 */
/* @0x2db738 mov r8, r6 */
/* @0x2db73c ldr r2, [r12, #0x8] */
/* @0x2db740 mov r12, r5 */
/* @0x2db744 ldr r5, [sp, #0x8] */
/* @0x2db748 ldr r3, [r11, #0x7c] */
/* @0x2db74c add r10, r3, r6 */
/* @0x2db750 ldr r7, [r3, r6] */
/* @0x2db754 ldr r4, [r10, #0x4] */
/* @0x2db758 cmp r7, r4 */
/* @0x2db75c movle r3, r4 */
/* @0x2db760 movle r4, r7 */
/* @0x2db764 movle r7, r3 */
/* @0x2db768 ldr r3, [r9, #0x4] */
/* @0x2db76c cmp r3, r4 */
/* @0x2db770 bgt 0x2db828 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x188> */
/* @0x2db774 ldr r3, [r9, #0x8] */
/* @0x2db778 cmp r3, r4 */
/* @0x2db77c ble 0x2db828 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x188> */
/* @0x2db780 ldr r3, [r5, #0x4] */
/* @0x2db784 cmp r3, r7 */
/* @0x2db788 bgt 0x2db828 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x188> */
/* @0x2db78c cmp r7, r2 */
/* @0x2db790 bge 0x2db828 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x188> */
/* @0x2db794 ldr r0, [r11, #0x8c] */
/* @0x2db798 ldr r3, [r11, #0x90] */
/* @0x2db79c cmp r0, r3 */
/* @0x2db7a0 bge 0x2dba70 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x3d0> */
/* @0x2db7a4 ldr r2, [r11, #0x94] */
/* @0x2db7a8 ldr r3, [r11, #0x38] */
/* @0x2db7ac vldr s12, [r9, #16] */
/* @0x2db7b0 vldr s13, [r5, #16] */
/* @0x2db7b4 vcmpe.f32 s12, s13 */
/* @0x2db7b8 add r1, r3, r4, lsl #3 */
/* @0x2db7bc add r3, r3, r7, lsl #3 */
/* @0x2db7c0 vldr s10, [r1, #4] */
/* @0x2db7c4 vldr s14, [r3, #4] */
/* @0x2db7c8 vldr s11, [r1] */
/* @0x2db7cc vldr s15, [r3] */
/* @0x2db7d0 vsub.f32 s14, s10, s14 */
/* @0x2db7d4 vmrs APSR_nzcv, fpscr */
/* @0x2db7d8 add r3, r0, r0, lsl #2 */
/* @0x2db7dc ldr r1, [r10, #0x8] */
/* @0x2db7e0 add r10, r2, r3, lsl #2 */
/* @0x2db7e4 str r4, [r2, r3, lsl #2] */
/* @0x2db7e8 str r1, [r10, #0x8] */
/* @0x2db7ec str r7, [r10, #0x4] */
/* @0x2db7f0 vmul.f32 s14, s14, s14 */
/* @0x2db7f4 vsub.f32 s15, s11, s15 */
/* @0x2db7f8 vmla.f32 s14, s15, s15 */
/* @0x2db7fc vsqrt.f32 s15, s14 */
/* @0x2db800 vcmp.f32 s15, s15 */
/* @0x2db804 vmovmi.f32 s13, s12 */
/* @0x2db808 vmrs APSR_nzcv, fpscr */
/* @0x2db80c vstr s13, [r10, #12] */
/* @0x2db810 bne 0x2dbb10 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x470> */
/* @0x2db814 ldr r1, [r11, #0x74] */
/* @0x2db818 add r0, r0, #1 */
/* @0x2db81c ldr r2, [r5, #0x8] */
/* @0x2db820 vstr s15, [r10, #16] */
/* @0x2db824 str r0, [r11, #0x8c] */
/* @0x2db828 add r8, r8, #1 */
/* @0x2db82c add r6, r6, #24 */
/* @0x2db830 cmp r1, r8 */
/* @0x2db834 bgt 0x2db748 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0xa8> */
/* @0x2db838 and r5, r12, #16 */
/* @0x2db83c cmp r5, #0 */
/* @0x2db840 beq 0x2db9d4 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x334> */
/* @0x2db844 add r12, sp, #40 */
/* @0x2db848 ldr r1, [r11, #0xd4] */
/* @0x2db84c ldr r3, [r9, #0x4] */
/* @0x2db850 mov r0, r12 */
/* @0x2db854 add r1, r1, #68 */
/* @0x2db858 rsb r2, r3, r2 */
/* @0x2db85c str r12, [sp, #0xc] */
/* @0x2db860 bl 0x2dbb2c <_ZN16b2VoronoiDiagramC2EP16b2StackAllocatori> */
/* @0x2db864 ldr r12, [sp, #0x8] */
/* @0x2db868 ldr r4, [r9, #0x4] */
/* @0x2db86c ldr r2, [r12, #0x8] */
/* @0x2db870 cmp r4, r2 */
/* @0x2db874 bge 0x2db8d8 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x238> */
/* @0x2db878 lsl r5, r4, #2 */
/* @0x2db87c lsl r6, r4, #3 */
/* @0x2db880 ldr r7, [sp, #0x8] */
/* @0x2db884 add r8, sp, #40 */
/* @0x2db888 b 0x2db89c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x1fc> */
/* @0x2db88c add r4, r4, #1 */
/* @0x2db890 add r6, r6, #8 */
/* @0x2db894 cmp r2, r4 */
/* @0x2db898 ble 0x2db8d8 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x238> */
/* @0x2db89c ldr r3, [r11, #0x30] */
/* @0x2db8a0 ldr r3, [r3, r5] */
/* @0x2db8a4 add r5, r5, #4 */
/* @0x2db8a8 tst r3, #2 */
/* @0x2db8ac bne 0x2db88c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x1ec> */
/* @0x2db8b0 ldr r1, [r11, #0x38] */
/* @0x2db8b4 mov r2, r4 */
/* @0x2db8b8 mov r0, r8 */
/* @0x2db8bc add r4, r4, #1 */
/* @0x2db8c0 add r1, r1, r6 */
/* @0x2db8c4 add r6, r6, #8 */
/* @0x2db8c8 bl 0x2dbb94 <_ZN16b2VoronoiDiagram12AddGeneratorERK6b2Vec2i> */
/* @0x2db8cc ldr r2, [r7, #0x8] */
/* @0x2db8d0 cmp r2, r4 */
/* @0x2db8d4 bgt 0x2db89c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x1fc> */
/* @0x2db8d8 mov r0, r11 */
/* @0x2db8dc bl 0x2d85a8 <_ZNK16b2ParticleSystem17GetParticleStrideEv> */
/* @0x2db8e0 vmov.f32 s15, #5.000000e-01 */
/* @0x2db8e4 vmov s14, r0 */
/* @0x2db8e8 add r0, sp, #40 */
/* @0x2db8ec vmul.f32 s15, s14, s15 */
/* @0x2db8f0 vmov r1, s15 */
/* @0x2db8f4 bl 0x2dbbc4 <_ZN16b2VoronoiDiagram8GenerateEf> */
/* @0x2db8f8 ldr r3, [sp, #0x38] */
/* @0x2db8fc ldr r12, [sp, #0x8] */
/* @0x2db900 cmp r3, #1 */
/* @0x2db904 str r11, [sp, #0x1c] */
/* @0x2db908 str r9, [sp, #0x20] */
/* @0x2db90c str r12, [sp, #0x24] */
/* @0x2db910 ble 0x2dba5c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x3bc> */
/* @0x2db914 ldr r1, [sp, #0x34] */
/* @0x2db918 add r10, sp, #28 */
/* @0x2db91c mov r8, #0 */
/* @0x2db920 cmp r1, #1 */
/* @0x2db924 ble 0x2dba4c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x3ac> */
/* @0x2db928 mov r6, #0 */
/* @0x2db92c b 0x2db950 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x2b0> */
/* @0x2db930 cmp r4, r7 */
/* @0x2db934 cmpne r5, r7 */
/* @0x2db938 bne 0x2db9a8 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x308> */
/* @0x2db93c ldr r1, [sp, #0x34] */
/* @0x2db940 add r6, r6, #1 */
/* @0x2db944 sub r3, r1, #1 */
/* @0x2db948 cmp r6, r3 */
/* @0x2db94c bge 0x2dba48 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x3a8> */
/* @0x2db950 mla r2, r1, r8, r6 */
/* @0x2db954 ldr r3, [sp, #0x3c] */
/* @0x2db958 add r0, r1, r2 */
/* @0x2db95c add r12, r0, #1 */
/* @0x2db960 add lr, r3, r2, lsl #2 */
/* @0x2db964 ldr r4, [r3, r0, lsl #2] */
/* @0x2db968 ldr r2, [r3, r2, lsl #2] */
/* @0x2db96c ldr r5, [lr, #0x4] */
/* @0x2db970 ldr r7, [r3, r12, lsl #2] */
/* @0x2db974 cmp r5, r4 */
/* @0x2db978 beq 0x2db940 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x2a0> */
/* @0x2db97c cmp r2, r4 */
/* @0x2db980 cmpne r2, r5 */
/* @0x2db984 beq 0x2db930 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x290> */
/* @0x2db988 ldr r1, [r2, #0x8] */
/* @0x2db98c mov r0, r10 */
/* @0x2db990 ldr r2, [r5, #0x8] */
/* @0x2db994 ldr r3, [r4, #0x8] */
/* @0x2db998 bl 0x2d5580 <_ZNK16b2ParticleSystem26JoinParticleGroupsCallbackclEiii> */
/* @0x2db99c cmp r4, r7 */
/* @0x2db9a0 cmpne r5, r7 */
/* @0x2db9a4 beq 0x2db93c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x29c> */
/* @0x2db9a8 ldr r1, [r5, #0x8] */
/* @0x2db9ac mov r0, r10 */
/* @0x2db9b0 ldr r2, [r7, #0x8] */
/* @0x2db9b4 ldr r3, [r4, #0x8] */
/* @0x2db9b8 bl 0x2d5580 <_ZNK16b2ParticleSystem26JoinParticleGroupsCallbackclEiii> */
/* @0x2db9bc b 0x2db93c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x29c> */
/* @0x2db9c0 and r5, r5, #16 */
/* @0x2db9c4 ldr r12, [sp, #0x8] */
/* @0x2db9c8 cmp r5, #0 */
/* @0x2db9cc ldr r2, [r12, #0x8] */
/* @0x2db9d0 bne 0x2db844 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x1a4> */
/* @0x2db9d4 ldr r12, [sp, #0x8] */
/* @0x2db9d8 ldr r3, [r12, #0x4] */
/* @0x2db9dc cmp r3, r2 */
/* @0x2db9e0 lsllt r1, r3, #2 */
/* @0x2db9e4 bge 0x2dba00 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x360> */
/* @0x2db9e8 add r3, r3, #1 */
/* @0x2db9ec ldr r0, [r11, #0x5c] */
/* @0x2db9f0 cmp r3, r2 */
/* @0x2db9f4 str r9, [r0, r1] */
/* @0x2db9f8 add r1, r1, #4 */
/* @0x2db9fc bne 0x2db9e8 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x348> */
/* @0x2dba00 ldr r12, [sp, #0x8] */
/* @0x2dba04 mov r0, r11 */
/* @0x2dba08 ldr r4, [r12, #0xc] */
/* @0x2dba0c mov r1, r12 */
/* @0x2dba10 str r2, [r9, #0x8] */
/* @0x2dba14 ldr r3, [r12, #0x8] */
/* @0x2dba18 ldr r2, [r9, #0xc] */
/* @0x2dba1c orr r4, r4, r2 */
/* @0x2dba20 str r4, [r9, #0xc] */
/* @0x2dba24 str r3, [r12, #0x4] */
/* @0x2dba28 bl 0x2d5874 <_ZN16b2ParticleSystem20DestroyParticleGroupEP15b2ParticleGroup> */
/* @0x2dba2c tst r4, #1 */
/* @0x2dba30 beq 0x2dba40 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x3a0> */
/* @0x2dba34 mov r0, r11 */
/* @0x2dba38 mov r1, r9 */
/* @0x2dba3c bl 0x2d5920 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup> */
/* @0x2dba40 add sp, sp, #68 */
/* @0x2dba44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2dba48 ldr r3, [sp, #0x38] */
/* @0x2dba4c add r8, r8, #1 */
/* @0x2dba50 sub r2, r3, #1 */
/* @0x2dba54 cmp r8, r2 */
/* @0x2dba58 blt 0x2db920 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x280> */
/* @0x2dba5c add r0, sp, #40 */
/* @0x2dba60 bl 0x2dbb68 <_ZN16b2VoronoiDiagramD2Ev> */
/* @0x2dba64 ldr r12, [sp, #0x8] */
/* @0x2dba68 ldr r2, [r12, #0x8] */
/* @0x2dba6c b 0x2db9d4 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x334> */
/* @0x2dba70 cmp r0, #0 */
/* @0x2dba74 lslne r1, r0, #1 */
/* @0x2dba78 strne r1, [sp, #0x14] */
/* @0x2dba7c moveq r2, #256 */
/* @0x2dba80 addne r1, r1, r0, lsl #3 */
/* @0x2dba84 streq r2, [sp, #0x14] */
/* @0x2dba88 moveq r1, #5120 */
/* @0x2dba8c ldr r2, [r11, #0x94] */
/* @0x2dba90 lslne r1, r1, #2 */
/* @0x2dba94 ldr r0, [r11, #0xd4] */
/* @0x2dba98 str r12, [sp] */
/* @0x2dba9c str r2, [sp, #0xc] */
/* @0x2dbaa0 str r3, [sp, #0x4] */
/* @0x2dbaa4 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2dbaa8 ldr r3, [sp, #0x4] */
/* @0x2dbaac ldr r1, [sp, #0xc] */
/* @0x2dbab0 add r3, r3, r3, lsl #2 */
/* @0x2dbab4 lsl r3, r3, #2 */
/* @0x2dbab8 str r3, [sp, #0x4] */
/* @0x2dbabc mov r2, r3 */
/* @0x2dbac0 str r0, [sp, #0x10] */
/* @0x2dbac4 bl 0xb65bc <memcpy@plt> */
/* @0x2dbac8 ldr r3, [sp, #0x4] */
/* @0x2dbacc ldr r0, [r11, #0xd4] */
/* @0x2dbad0 ldr r1, [sp, #0xc] */
/* @0x2dbad4 mov r2, r3 */
/* @0x2dbad8 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2dbadc ldr r2, [sp, #0x10] */
/* @0x2dbae0 ldr r3, [sp, #0x14] */
/* @0x2dbae4 ldr r0, [r11, #0x8c] */
/* @0x2dbae8 str r2, [r11, #0x94] */
/* @0x2dbaec str r3, [r11, #0x90] */
/* @0x2dbaf0 ldr r12, [sp] */
/* @0x2dbaf4 b 0x2db7a8 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x108> */
/* @0x2dbaf8 mov r0, r11 */
/* @0x2dbafc mov r1, #1 */
/* @0x2dbb00 bl 0x2da664 <_ZN16b2ParticleSystem14UpdateContactsEb> */
/* @0x2dbb04 ldr r12, [sp, #0x8] */
/* @0x2dbb08 ldr r2, [r12, #0x8] */
/* @0x2dbb0c b 0x2db9d4 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x334> */
/* @0x2dbb10 vmov r0, s14 */
/* @0x2dbb14 str r12, [sp] */
/* @0x2dbb18 bl 0xb6700 <sqrtf@plt> */
/* @0x2dbb1c ldr r12, [sp] */
/* @0x2dbb20 vmov s15, r0 */
/* @0x2dbb24 ldr r0, [r11, #0x8c] */
/* @0x2dbb28 b 0x2db814 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x174> */

/* ── FUNC 0x2dbb2c · b2VoronoiDiagram::b2VoronoiDiagram(b2StackAllocator*, int) · size=60 · insn=15 */
/* @0x2dbb2c add r2, r2, r2, lsl #1 */
/* @0x2dbb30 push {r4, lr} */
/* @0x2dbb34 mov r4, r0 */
/* @0x2dbb38 str r1, [r4] */
/* @0x2dbb3c mov r0, r1 */
/* @0x2dbb40 lsl r1, r2, #2 */
/* @0x2dbb44 bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi> */
/* @0x2dbb48 mov r3, #0 */
/* @0x2dbb4c str r3, [r4, #0x8] */
/* @0x2dbb50 str r3, [r4, #0xc] */
/* @0x2dbb54 str r3, [r4, #0x10] */
/* @0x2dbb58 str r3, [r4, #0x14] */
/* @0x2dbb5c str r0, [r4, #0x4] */
/* @0x2dbb60 mov r0, r4 */
/* @0x2dbb64 pop {r4, pc} */

/* ── FUNC 0x2dbb2c · b2VoronoiDiagram::b2VoronoiDiagram(b2StackAllocator*, int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2dbb68 · b2VoronoiDiagram::~b2VoronoiDiagram() · size=44 · insn=11 */
/* @0x2dbb68 ldr r1, [r0, #0x14] */
/* @0x2dbb6c push {r4, lr} */
/* @0x2dbb70 cmp r1, #0 */
/* @0x2dbb74 mov r4, r0 */
/* @0x2dbb78 beq 0x2dbb84 <_ZN16b2VoronoiDiagramD2Ev+0x1c> */
/* @0x2dbb7c ldr r0, [r0] */
/* @0x2dbb80 bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv> */
/* @0x2dbb84 ldm r4, {r0, r1} */
/* @0x2dbb88 bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv> */
/* @0x2dbb8c mov r0, r4 */
/* @0x2dbb90 pop {r4, pc} */

/* ── FUNC 0x2dbb68 · b2VoronoiDiagram::~b2VoronoiDiagram() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2dbb94 · b2VoronoiDiagram::AddGenerator(b2Vec2 const&, int) · size=48 · insn=12 */
/* @0x2dbb94 push {r4, r5} */
/* @0x2dbb98 mov r4, r0 */
/* @0x2dbb9c ldmib r4, {r5, r12} */
/* @0x2dbba0 ldm r1, {r0, r1} */
/* @0x2dbba4 add r3, r12, #1 */
/* @0x2dbba8 add r12, r12, r12, lsl #1 */
/* @0x2dbbac str r3, [r4, #0x8] */
/* @0x2dbbb0 add r3, r5, r12, lsl #2 */
/* @0x2dbbb4 pop {r4, r5} */
/* @0x2dbbb8 stm r3, {r0, r1} */
/* @0x2dbbbc str r2, [r3, #0x8] */
/* @0x2dbbc0 bx lr */

/* ── FUNC 0x2dbbc4 · b2VoronoiDiagram::Generate(float) · size=3048 · insn=762 */
/* @0x2dbbc4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2dbbc8 vpush {d8, d9} */
/* @0x2dbbcc vmov.f32 s18, #1.000000e+00 */
/* @0x2dbbd0 ldr r3, [r0, #0x8] */
/* @0x2dbbd4 sub sp, sp, #76 */
/* @0x2dbbd8 vmov s10, r1 */
/* @0x2dbbdc cmp r3, #0 */
/* @0x2dbbe0 str r0, [sp, #0x2c] */
/* @0x2dbbe4 vdiv.f32 s18, s18, s10 */
/* @0x2dbbe8 ble 0x2dc770 <_ZN16b2VoronoiDiagram8GenerateEf+0xbac> */
/* @0x2dbbec add r2, r3, r3, lsl #1 */
/* @0x2dbbf0 vldr s15, [pc, #968] */
/* @0x2dbbf4 ldr r3, [r0, #0x4] */
/* @0x2dbbf8 vldr s16, [pc, #964] */
/* @0x2dbbfc add r2, r3, r2, lsl #2 */
/* @0x2dbc00 vmov.f32 s12, s15 */
/* @0x2dbc04 vmov.f32 s17, s16 */
/* @0x2dbc08 vldr s13, [r3] */
/* @0x2dbc0c vldr s14, [r3, #4] */
/* @0x2dbc10 add r3, r3, #12 */
/* @0x2dbc14 vcmpe.f32 s13, s16 */
/* @0x2dbc18 vmrs APSR_nzcv, fpscr */
/* @0x2dbc1c vcmpe.f32 s14, s17 */
/* @0x2dbc20 vmovle.f32 s16, s13 */
/* @0x2dbc24 vmrs APSR_nzcv, fpscr */
/* @0x2dbc28 vcmpe.f32 s13, s15 */
/* @0x2dbc2c vmovle.f32 s17, s14 */
/* @0x2dbc30 vmrs APSR_nzcv, fpscr */
/* @0x2dbc34 vcmpe.f32 s14, s12 */
/* @0x2dbc38 vmovpl.f32 s15, s13 */
/* @0x2dbc3c vmrs APSR_nzcv, fpscr */
/* @0x2dbc40 vmovpl.f32 s12, s14 */
/* @0x2dbc44 cmp r3, r2 */
/* @0x2dbc48 bne 0x2dbc08 <_ZN16b2VoronoiDiagram8GenerateEf+0x44> */
/* @0x2dbc4c vsub.f32 s15, s15, s16 */
/* @0x2dbc50 ldr r5, [sp, #0x2c] */
/* @0x2dbc54 ldr r0, [r5] */
/* @0x2dbc58 vsub.f32 s12, s12, s17 */
/* @0x2dbc5c vmul.f32 s14, s15, s18 */
/* @0x2dbc60 vmul.f32 s15, s12, s18 */
/* @0x2dbc64 vcvt.s32.f32 s14, s14 */
/* @0x2dbc68 vcvt.s32.f32 s15, s15 */
/* @0x2dbc6c vmov r3, s14 */
/* @0x2dbc70 vmov r2, s15 */
/* @0x2dbc74 add r3, r3, #1 */
/* @0x2dbc78 str r3, [r5, #0xc] */
/* @0x2dbc7c add r2, r2, #1 */
/* @0x2dbc80 str r2, [r5, #0x10] */
/* @0x2dbc84 mul r1, r2, r3 */
/* @0x2dbc88 lsl r1, r1, #2 */
/* @0x2dbc8c bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi> */
/* @0x2dbc90 ldr r12, [r5, #0xc] */
/* @0x2dbc94 ldr r1, [r5, #0x10] */
/* @0x2dbc98 mul r1, r1, r12 */
/* @0x2dbc9c cmp r1, #0 */
/* @0x2dbca0 str r0, [r5, #0x14] */
/* @0x2dbca4 ble 0x2dbcd0 <_ZN16b2VoronoiDiagram8GenerateEf+0x10c> */
/* @0x2dbca8 mov r3, #0 */
/* @0x2dbcac mov r2, r0 */
/* @0x2dbcb0 ldr lr, [sp, #0x2c] */
/* @0x2dbcb4 mov r0, r3 */
/* @0x2dbcb8 b 0x2dbcc0 <_ZN16b2VoronoiDiagram8GenerateEf+0xfc> */
/* @0x2dbcbc ldr r2, [lr, #0x14] */
/* @0x2dbcc0 str r0, [r2, r3, lsl #2] */
/* @0x2dbcc4 add r3, r3, #1 */
/* @0x2dbcc8 cmp r3, r1 */
/* @0x2dbccc bne 0x2dbcbc <_ZN16b2VoronoiDiagram8GenerateEf+0xf8> */
/* @0x2dbcd0 mul r12, r12, r12 */
/* @0x2dbcd4 ldr r5, [sp, #0x2c] */
/* @0x2dbcd8 ldr r5, [r5] */
/* @0x2dbcdc str r5, [sp, #0x44] */
/* @0x2dbce0 mov r0, r5 */
/* @0x2dbce4 lsl r5, r12, #6 */
/* @0x2dbce8 mov r1, r5 */
/* @0x2dbcec bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi> */
/* @0x2dbcf0 ldr r1, [sp, #0x2c] */
/* @0x2dbcf4 ldr r4, [r1, #0x8] */
/* @0x2dbcf8 cmp r4, #0 */
/* @0x2dbcfc add r5, r0, r5 */
/* @0x2dbd00 str r0, [sp, #0x1c] */
/* @0x2dbd04 str r5, [sp, #0x4] */
/* @0x2dbd08 ble 0x2dc784 <_ZN16b2VoronoiDiagram8GenerateEf+0xbc0> */
/* @0x2dbd0c ldr r5, [sp, #0x2c] */
/* @0x2dbd10 mov r0, #0 */
/* @0x2dbd14 mov r12, r0 */
/* @0x2dbd18 ldr r5, [r5, #0xc] */
/* @0x2dbd1c str r5, [sp, #0x18] */
/* @0x2dbd20 ldr r5, [sp, #0x1c] */
/* @0x2dbd24 add r6, r5, #16 */
/* @0x2dbd28 ldr r5, [sp, #0x2c] */
/* @0x2dbd2c rsb r1, r6, #15 */
/* @0x2dbd30 str r1, [sp] */
/* @0x2dbd34 ldr r5, [r5, #0x10] */
/* @0x2dbd38 str r5, [sp, #0x38] */
/* @0x2dbd3c ldr r5, [sp, #0x2c] */
/* @0x2dbd40 ldr r7, [r5, #0x4] */
/* @0x2dbd44 ldr r5, [sp, #0x18] */
/* @0x2dbd48 sub r8, r5, #1 */
/* @0x2dbd4c ldr r5, [sp, #0x38] */
/* @0x2dbd50 sub r10, r5, #1 */
/* @0x2dbd54 ldr r5, [sp, #0x1c] */
/* @0x2dbd58 add r11, r5, #32 */
/* @0x2dbd5c mov r9, r5 */
/* @0x2dbd60 add r3, r7, r0 */
/* @0x2dbd64 vldr s14, [r3] */
/* @0x2dbd68 vldr s15, [r3, #4] */
/* @0x2dbd6c vsub.f32 s14, s14, s16 */
/* @0x2dbd70 ldr r5, [sp, #0x4] */
/* @0x2dbd74 vsub.f32 s15, s15, s17 */
/* @0x2dbd78 vmul.f32 s14, s18, s14 */
/* @0x2dbd7c vmul.f32 s15, s18, s15 */
/* @0x2dbd80 vstr s14, [r3] */
/* @0x2dbd84 vstr s15, [r3, #4] */
/* @0x2dbd88 vcvt.s32.f32 s14, s14 */
/* @0x2dbd8c vcvt.s32.f32 s15, s15 */
/* @0x2dbd90 vmov r1, s14 */
/* @0x2dbd94 vmov r2, s15 */
/* @0x2dbd98 cmp r1, r8 */
/* @0x2dbd9c movge r1, r8 */
/* @0x2dbda0 bic r1, r1, r1, asr #31 */
/* @0x2dbda4 cmp r2, r10 */
/* @0x2dbda8 movge r2, r10 */
/* @0x2dbdac cmp r5, r9 */
/* @0x2dbdb0 ldr r5, [sp, #0x18] */
/* @0x2dbdb4 bic r2, r2, r2, asr #31 */
/* @0x2dbdb8 mla r5, r5, r2, r1 */
/* @0x2dbdbc str r5, [sp, #0x8] */
/* @0x2dbdc0 bhi 0x2dc51c <_ZN16b2VoronoiDiagram8GenerateEf+0x958> */
/* @0x2dbdc4 ldr r5, [sp, #0x1c] */
/* @0x2dbdc8 cmp r5, r9 */
/* @0x2dbdcc bhs 0x2dbdf0 <_ZN16b2VoronoiDiagram8GenerateEf+0x22c> */
/* @0x2dbdd0 ldr r1, [sp] */
/* @0x2dbdd4 mov r3, r6 */
/* @0x2dbdd8 add r2, r9, r1 */
/* @0x2dbddc bic r2, r2, #15 */
/* @0x2dbde0 add r2, r11, r2 */
/* @0x2dbde4 add r3, r3, #16 */
/* @0x2dbde8 cmp r3, r2 */
/* @0x2dbdec bne 0x2dbde4 <_ZN16b2VoronoiDiagram8GenerateEf+0x220> */
/* @0x2dbdf0 add r12, r12, #1 */
/* @0x2dbdf4 add r0, r0, #12 */
/* @0x2dbdf8 cmp r12, r4 */
/* @0x2dbdfc bne 0x2dbd60 <_ZN16b2VoronoiDiagram8GenerateEf+0x19c> */
/* @0x2dbe00 ldr r5, [sp, #0x18] */
/* @0x2dbe04 ldr r11, [sp, #0x1c] */
/* @0x2dbe08 sub r5, r5, #1 */
/* @0x2dbe0c str r5, [sp, #0xc] */
/* @0x2dbe10 ldr r5, [sp, #0x38] */
/* @0x2dbe14 sub r5, r5, #1 */
/* @0x2dbe18 str r5, [sp, #0x10] */
/* @0x2dbe1c add r3, r11, #16 */
/* @0x2dbe20 ldr r0, [sp, #0x2c] */
/* @0x2dbe24 b 0x2dbe54 <_ZN16b2VoronoiDiagram8GenerateEf+0x290> */
/* @0x2dbe28 ldr r12, [r11, #0x8] */
/* @0x2dbe2c add r3, r3, #16 */
/* @0x2dbe30 ldr r2, [r0, #0x14] */
/* @0x2dbe34 add r11, r11, #16 */
/* @0x2dbe38 ldr r4, [r3, #-0x20] */
/* @0x2dbe3c add r1, r2, r12, lsl #2 */
/* @0x2dbe40 ldr r5, [r3, #-0x1c] */
/* @0x2dbe44 ldr r2, [r2, r12, lsl #2] */
/* @0x2dbe48 ldr r6, [r11, #-0x4] */
/* @0x2dbe4c cmp r2, #0 */
/* @0x2dbe50 beq 0x2dc53c <_ZN16b2VoronoiDiagram8GenerateEf+0x978> */
/* @0x2dbe54 cmp r11, r9 */
/* @0x2dbe58 blo 0x2dbe28 <_ZN16b2VoronoiDiagram8GenerateEf+0x264> */
/* @0x2dbe5c ldr r5, [sp, #0x38] */
/* @0x2dbe60 ldr r1, [sp, #0x18] */
/* @0x2dbe64 add r5, r5, r1 */
/* @0x2dbe68 str r5, [sp, #0x40] */
/* @0x2dbe6c cmp r5, #0 */
/* @0x2dbe70 ble 0x2dc3a4 <_ZN16b2VoronoiDiagram8GenerateEf+0x7e0> */
/* @0x2dbe74 mov r5, #0 */
/* @0x2dbe78 str r5, [sp, #0x3c] */
/* @0x2dbe7c sub r5, r1, #1 */
/* @0x2dbe80 str r5, [sp, #0x24] */
/* @0x2dbe84 ldr r5, [sp, #0x38] */
/* @0x2dbe88 sub r5, r5, #1 */
/* @0x2dbe8c str r5, [sp, #0x34] */
/* @0x2dbe90 ldr r5, [sp, #0x38] */
/* @0x2dbe94 cmp r5, #0 */
/* @0x2dbe98 ble 0x2dc1b4 <_ZN16b2VoronoiDiagram8GenerateEf+0x5f0> */
/* @0x2dbe9c mov r5, #0 */
/* @0x2dbea0 str r5, [sp, #0x14] */
/* @0x2dbea4 ldr r5, [sp, #0x18] */
/* @0x2dbea8 cmp r5, #1 */
/* @0x2dbeac ble 0x2dc028 <_ZN16b2VoronoiDiagram8GenerateEf+0x464> */
/* @0x2dbeb0 ldr r1, [sp, #0x14] */
/* @0x2dbeb4 mov r7, #1 */
/* @0x2dbeb8 mul r3, r1, r5 */
/* @0x2dbebc ldr r5, [sp, #0x2c] */
/* @0x2dbec0 ldr r5, [r5, #0x14] */
/* @0x2dbec4 add r10, r3, r7 */
/* @0x2dbec8 lsl r3, r3, #2 */
/* @0x2dbecc str r5, [sp, #0x8] */
/* @0x2dbed0 ldr r5, [sp, #0x8] */
/* @0x2dbed4 add r8, r3, #4 */
/* @0x2dbed8 ldr r3, [r5, r3] */
/* @0x2dbedc sub r5, r7, #1 */
/* @0x2dbee0 str r5, [sp, #0x10] */
/* @0x2dbee4 sub r5, r10, #1 */
/* @0x2dbee8 str r5, [sp, #0xc] */
/* @0x2dbeec ldr r5, [sp, #0x8] */
/* @0x2dbef0 str r3, [sp] */
/* @0x2dbef4 ldr r6, [r5, r8] */
/* @0x2dbef8 cmp r3, r6 */
/* @0x2dbefc beq 0x2dc020 <_ZN16b2VoronoiDiagram8GenerateEf+0x45c> */
/* @0x2dbf00 ldr r5, [sp, #0x4] */
/* @0x2dbf04 cmp r5, r9 */
/* @0x2dbf08 bhi 0x2dbf5c <_ZN16b2VoronoiDiagram8GenerateEf+0x398> */
/* @0x2dbf0c ldr r1, [sp, #0x1c] */
/* @0x2dbf10 cmp r11, r9 */
/* @0x2dbf14 rsb r5, r1, r11 */
/* @0x2dbf18 asr r5, r5, #4 */
/* @0x2dbf1c lsl r5, r5, #4 */
/* @0x2dbf20 rsbhs r5, r5, #0 */
/* @0x2dbf24 bhs 0x2dbf48 <_ZN16b2VoronoiDiagram8GenerateEf+0x384> */
/* @0x2dbf28 rsb r5, r5, #0 */
/* @0x2dbf2c mov r12, r11 */
/* @0x2dbf30 ldm r12, {r0, r1, r2, r3} */
/* @0x2dbf34 add r4, r12, r5 */
/* @0x2dbf38 add r12, r12, #16 */
/* @0x2dbf3c cmp r12, r9 */
/* @0x2dbf40 stm r4, {r0, r1, r2, r3} */
/* @0x2dbf44 blo 0x2dbf30 <_ZN16b2VoronoiDiagram8GenerateEf+0x36c> */
/* @0x2dbf48 add r9, r9, r5 */
/* @0x2dbf4c add r11, r11, r5 */
/* @0x2dbf50 ldr r5, [sp, #0x4] */
/* @0x2dbf54 cmp r5, r9 */
/* @0x2dbf58 bls 0x2dbfc8 <_ZN16b2VoronoiDiagram8GenerateEf+0x404> */
/* @0x2dbf5c ldr r5, [sp, #0x10] */
/* @0x2dbf60 add r12, r9, #16 */
/* @0x2dbf64 str r6, [r9, #0xc] */
/* @0x2dbf68 str r5, [r9] */
/* @0x2dbf6c ldr r5, [sp, #0x4] */
/* @0x2dbf70 cmp r5, r12 */
/* @0x2dbf74 ldr r5, [sp, #0x14] */
/* @0x2dbf78 str r5, [r9, #0x4] */
/* @0x2dbf7c ldr r5, [sp, #0xc] */
/* @0x2dbf80 str r5, [r9, #0x8] */
/* @0x2dbf84 bls 0x2dbfcc <_ZN16b2VoronoiDiagram8GenerateEf+0x408> */
/* @0x2dbf88 ldr r5, [sp, #0x14] */
/* @0x2dbf8c add r9, r12, #16 */
/* @0x2dbf90 mov r3, r7 */
/* @0x2dbf94 str r7, [r12] */
/* @0x2dbf98 stmib r12, {r5, r10} */
/* @0x2dbf9c ldr r5, [sp] */
/* @0x2dbfa0 str r5, [r12, #0xc] */
/* @0x2dbfa4 ldr r5, [sp, #0x24] */
/* @0x2dbfa8 add r7, r7, #1 */
/* @0x2dbfac add r10, r10, #1 */
/* @0x2dbfb0 cmp r5, r3 */
/* @0x2dbfb4 ble 0x2dc028 <_ZN16b2VoronoiDiagram8GenerateEf+0x464> */
/* @0x2dbfb8 mov r3, r8 */
/* @0x2dbfbc b 0x2dbed0 <_ZN16b2VoronoiDiagram8GenerateEf+0x30c> */
/* @0x2dbfc0 .word 0xff7fffff */
/* @0x2dbfc4 svcvc #0x7fffff */
/* @0x2dbfc8 mov r12, r9 */
/* @0x2dbfcc ldr r5, [sp, #0x1c] */
/* @0x2dbfd0 cmp r12, r11 */
/* @0x2dbfd4 rsb r6, r5, r11 */
/* @0x2dbfd8 asr r6, r6, #4 */
/* @0x2dbfdc lsl r6, r6, #4 */
/* @0x2dbfe0 rsbls r6, r6, #0 */
/* @0x2dbfe4 bls 0x2dc008 <_ZN16b2VoronoiDiagram8GenerateEf+0x444> */
/* @0x2dbfe8 rsb r6, r6, #0 */
/* @0x2dbfec mov r4, r11 */
/* @0x2dbff0 ldm r4, {r0, r1, r2, r3} */
/* @0x2dbff4 add r5, r4, r6 */
/* @0x2dbff8 add r4, r4, #16 */
/* @0x2dbffc cmp r4, r12 */
/* @0x2dc000 stm r5, {r0, r1, r2, r3} */
/* @0x2dc004 blo 0x2dbff0 <_ZN16b2VoronoiDiagram8GenerateEf+0x42c> */
/* @0x2dc008 ldr r5, [sp, #0x4] */
/* @0x2dc00c add r12, r12, r6 */
/* @0x2dc010 add r11, r11, r6 */
/* @0x2dc014 cmp r5, r12 */
/* @0x2dc018 bhi 0x2dbf88 <_ZN16b2VoronoiDiagram8GenerateEf+0x3c4> */
/* @0x2dc01c mov r9, r12 */
/* @0x2dc020 mov r3, r7 */
/* @0x2dc024 b 0x2dbfa4 <_ZN16b2VoronoiDiagram8GenerateEf+0x3e0> */
/* @0x2dc028 ldr r5, [sp, #0x14] */
/* @0x2dc02c ldr r1, [sp, #0x38] */
/* @0x2dc030 add r5, r5, #1 */
/* @0x2dc034 str r5, [sp, #0x14] */
/* @0x2dc038 cmp r5, r1 */
/* @0x2dc03c blt 0x2dbea4 <_ZN16b2VoronoiDiagram8GenerateEf+0x2e0> */
/* @0x2dc040 ldr r5, [sp, #0x38] */
/* @0x2dc044 cmp r5, #1 */
/* @0x2dc048 ble 0x2dc1b4 <_ZN16b2VoronoiDiagram8GenerateEf+0x5f0> */
/* @0x2dc04c mov r5, #1 */
/* @0x2dc050 str r5, [sp, #0xc] */
/* @0x2dc054 ldr r5, [sp, #0x18] */
/* @0x2dc058 cmp r5, #0 */
/* @0x2dc05c ldr r5, [sp, #0xc] */
/* @0x2dc060 sub r5, r5, #1 */
/* @0x2dc064 str r5, [sp, #0x28] */
/* @0x2dc068 ldrle r5, [sp, #0xc] */
/* @0x2dc06c strle r5, [sp, #0x30] */
/* @0x2dc070 ble 0x2dc198 <_ZN16b2VoronoiDiagram8GenerateEf+0x5d4> */
/* @0x2dc074 ldr r1, [sp, #0x18] */
/* @0x2dc078 mov r6, #0 */
/* @0x2dc07c ldr r5, [sp, #0x28] */
/* @0x2dc080 mul r10, r5, r1 */
/* @0x2dc084 ldr r5, [sp, #0xc] */
/* @0x2dc088 rsb r3, r5, #0 */
/* @0x2dc08c mul r7, r5, r1 */
/* @0x2dc090 str r5, [sp, #0x30] */
/* @0x2dc094 mla r3, r1, r3, r10 */
/* @0x2dc098 ldr r5, [sp, #0x2c] */
/* @0x2dc09c ldr r5, [r5, #0x14] */
/* @0x2dc0a0 str r3, [sp, #0x14] */
/* @0x2dc0a4 rsb r3, r10, r7 */
/* @0x2dc0a8 lsl r10, r10, #2 */
/* @0x2dc0ac str r5, [sp, #0x20] */
/* @0x2dc0b0 lsl r3, r3, #2 */
/* @0x2dc0b4 str r3, [sp, #0x10] */
/* @0x2dc0b8 ldr r3, [sp, #0x20] */
/* @0x2dc0bc ldr r5, [sp, #0x14] */
/* @0x2dc0c0 add r5, r7, r5 */
/* @0x2dc0c4 str r5, [sp, #0x8] */
/* @0x2dc0c8 ldr r5, [r3, r10]! */
/* @0x2dc0cc str r5, [sp] */
/* @0x2dc0d0 ldr r5, [sp, #0x10] */
/* @0x2dc0d4 ldr r8, [r3, r5] */
/* @0x2dc0d8 ldr r5, [sp] */
/* @0x2dc0dc cmp r5, r8 */
/* @0x2dc0e0 beq 0x2dc180 <_ZN16b2VoronoiDiagram8GenerateEf+0x5bc> */
/* @0x2dc0e4 ldr r5, [sp, #0x4] */
/* @0x2dc0e8 cmp r5, r9 */
/* @0x2dc0ec bhi 0x2dc140 <_ZN16b2VoronoiDiagram8GenerateEf+0x57c> */
/* @0x2dc0f0 ldr r1, [sp, #0x1c] */
/* @0x2dc0f4 cmp r11, r9 */
/* @0x2dc0f8 rsb r5, r1, r11 */
/* @0x2dc0fc asr r5, r5, #4 */
/* @0x2dc100 lsl r5, r5, #4 */
/* @0x2dc104 rsbhs r5, r5, #0 */
/* @0x2dc108 bhs 0x2dc12c <_ZN16b2VoronoiDiagram8GenerateEf+0x568> */
/* @0x2dc10c rsb r5, r5, #0 */
/* @0x2dc110 mov r12, r11 */
/* @0x2dc114 ldm r12, {r0, r1, r2, r3} */
/* @0x2dc118 add r4, r12, r5 */
/* @0x2dc11c add r12, r12, #16 */
/* @0x2dc120 cmp r12, r9 */
/* @0x2dc124 stm r4, {r0, r1, r2, r3} */
/* @0x2dc128 blo 0x2dc114 <_ZN16b2VoronoiDiagram8GenerateEf+0x550> */
/* @0x2dc12c add r9, r9, r5 */
/* @0x2dc130 add r11, r11, r5 */
/* @0x2dc134 ldr r5, [sp, #0x4] */
/* @0x2dc138 cmp r5, r9 */
/* @0x2dc13c bls 0x2dc3bc <_ZN16b2VoronoiDiagram8GenerateEf+0x7f8> */
/* @0x2dc140 ldr r5, [sp, #0x4] */
/* @0x2dc144 add r12, r9, #16 */
/* @0x2dc148 str r6, [r9] */
/* @0x2dc14c cmp r5, r12 */
/* @0x2dc150 ldr r5, [sp, #0x28] */
/* @0x2dc154 str r8, [r9, #0xc] */
/* @0x2dc158 str r5, [r9, #0x4] */
/* @0x2dc15c ldr r5, [sp, #0x8] */
/* @0x2dc160 str r5, [r9, #0x8] */
/* @0x2dc164 bls 0x2dc3c0 <_ZN16b2VoronoiDiagram8GenerateEf+0x7fc> */
/* @0x2dc168 ldr r5, [sp, #0xc] */
/* @0x2dc16c add r9, r12, #16 */
/* @0x2dc170 str r6, [r12] */
/* @0x2dc174 stmib r12, {r5, r7} */
/* @0x2dc178 ldr r5, [sp] */
/* @0x2dc17c str r5, [r12, #0xc] */
/* @0x2dc180 ldr r5, [sp, #0x18] */
/* @0x2dc184 add r6, r6, #1 */
/* @0x2dc188 add r10, r10, #4 */
/* @0x2dc18c add r7, r7, #1 */
/* @0x2dc190 cmp r6, r5 */
/* @0x2dc194 bne 0x2dc0b8 <_ZN16b2VoronoiDiagram8GenerateEf+0x4f4> */
/* @0x2dc198 ldr r5, [sp, #0x34] */
/* @0x2dc19c ldr r1, [sp, #0x30] */
/* @0x2dc1a0 cmp r5, r1 */
/* @0x2dc1a4 ldr r5, [sp, #0xc] */
/* @0x2dc1a8 add r5, r5, #1 */
/* @0x2dc1ac str r5, [sp, #0xc] */
/* @0x2dc1b0 bgt 0x2dc054 <_ZN16b2VoronoiDiagram8GenerateEf+0x490> */
/* @0x2dc1b4 mov r1, #0 */
/* @0x2dc1b8 cmp r9, r11 */
/* @0x2dc1bc bls 0x2dc384 <_ZN16b2VoronoiDiagram8GenerateEf+0x7c0> */
/* @0x2dc1c0 ldr r5, [sp, #0x2c] */
/* @0x2dc1c4 add r11, r11, #16 */
/* @0x2dc1c8 ldr r6, [r11, #-0x8] */
/* @0x2dc1cc ldr r7, [r11, #-0x10] */
/* @0x2dc1d0 ldr r3, [r5, #0x14] */
/* @0x2dc1d4 ldr r5, [r11, #-0x4] */
/* @0x2dc1d8 add r2, r3, r6, lsl #2 */
/* @0x2dc1dc ldr r8, [r11, #-0xc] */
/* @0x2dc1e0 ldr r3, [r3, r6, lsl #2] */
/* @0x2dc1e4 cmp r5, r3 */
/* @0x2dc1e8 beq 0x2dc1b8 <_ZN16b2VoronoiDiagram8GenerateEf+0x5f4> */
/* @0x2dc1ec vmov s10, r8 */
/* @0x2dc1f0 vldr s13, [r5, #4] */
/* @0x2dc1f4 vldr s14, [r3, #4] */
/* @0x2dc1f8 vldr s12, [r3] */
/* @0x2dc1fc vcvt.f32.s32 s15, s10 */
/* @0x2dc200 vldr s11, [r5] */
/* @0x2dc204 vmov s10, r7 */
/* @0x2dc208 vsub.f32 s14, s14, s15 */
/* @0x2dc20c vsub.f32 s15, s13, s15 */
/* @0x2dc210 vcvt.f32.s32 s13, s10 */
/* @0x2dc214 vmul.f32 s14, s14, s14 */
/* @0x2dc218 vmul.f32 s15, s15, s15 */
/* @0x2dc21c vsub.f32 s12, s12, s13 */
/* @0x2dc220 vsub.f32 s13, s11, s13 */
/* @0x2dc224 vmla.f32 s14, s12, s12 */
/* @0x2dc228 vmla.f32 s15, s13, s13 */
/* @0x2dc22c vcmpe.f32 s14, s15 */
/* @0x2dc230 vmrs APSR_nzcv, fpscr */
/* @0x2dc234 ble 0x2dc1b8 <_ZN16b2VoronoiDiagram8GenerateEf+0x5f4> */
/* @0x2dc238 cmp r7, #0 */
/* @0x2dc23c str r5, [r2] */
/* @0x2dc240 ble 0x2dc2c8 <_ZN16b2VoronoiDiagram8GenerateEf+0x704> */
/* @0x2dc244 ldr r1, [sp, #0x4] */
/* @0x2dc248 sub r2, r7, #1 */
/* @0x2dc24c sub r3, r6, #1 */
/* @0x2dc250 str r2, [sp] */
/* @0x2dc254 cmp r1, r9 */
/* @0x2dc258 str r3, [sp, #0x8] */
/* @0x2dc25c bhi 0x2dc2b0 <_ZN16b2VoronoiDiagram8GenerateEf+0x6ec> */
/* @0x2dc260 ldr r1, [sp, #0x1c] */
/* @0x2dc264 cmp r11, r9 */
/* @0x2dc268 rsb r3, r1, r11 */
/* @0x2dc26c asr r3, r3, #4 */
/* @0x2dc270 lsl r3, r3, #4 */
/* @0x2dc274 rsbhs r10, r3, #0 */
/* @0x2dc278 bhs 0x2dc29c <_ZN16b2VoronoiDiagram8GenerateEf+0x6d8> */
/* @0x2dc27c rsb r10, r3, #0 */
/* @0x2dc280 mov r12, r11 */
/* @0x2dc284 ldm r12, {r0, r1, r2, r3} */
/* @0x2dc288 add r4, r12, r10 */
/* @0x2dc28c add r12, r12, #16 */
/* @0x2dc290 cmp r9, r12 */
/* @0x2dc294 stm r4, {r0, r1, r2, r3} */
/* @0x2dc298 bhi 0x2dc284 <_ZN16b2VoronoiDiagram8GenerateEf+0x6c0> */
/* @0x2dc29c ldr r2, [sp, #0x4] */
/* @0x2dc2a0 add r9, r9, r10 */
/* @0x2dc2a4 add r11, r11, r10 */
/* @0x2dc2a8 cmp r2, r9 */
/* @0x2dc2ac bls 0x2dc2c8 <_ZN16b2VoronoiDiagram8GenerateEf+0x704> */
/* @0x2dc2b0 ldr r3, [sp] */
/* @0x2dc2b4 ldr r1, [sp, #0x8] */
/* @0x2dc2b8 str r5, [r9, #0xc] */
/* @0x2dc2bc stm r9, {r3, r8} */
/* @0x2dc2c0 add r9, r9, #16 */
/* @0x2dc2c4 str r1, [r9, #-0x8] */
/* @0x2dc2c8 cmp r8, #0 */
/* @0x2dc2cc ble 0x2dc35c <_ZN16b2VoronoiDiagram8GenerateEf+0x798> */
/* @0x2dc2d0 ldr r2, [sp, #0x4] */
/* @0x2dc2d4 sub r3, r8, #1 */
/* @0x2dc2d8 ldr r1, [sp, #0x18] */
/* @0x2dc2dc cmp r2, r9 */
/* @0x2dc2e0 str r3, [sp] */
/* @0x2dc2e4 rsb r1, r1, r6 */
/* @0x2dc2e8 str r1, [sp, #0x8] */
/* @0x2dc2ec bhi 0x2dc340 <_ZN16b2VoronoiDiagram8GenerateEf+0x77c> */
/* @0x2dc2f0 ldr r2, [sp, #0x1c] */
/* @0x2dc2f4 cmp r9, r11 */
/* @0x2dc2f8 rsb r3, r2, r11 */
/* @0x2dc2fc asr r3, r3, #4 */
/* @0x2dc300 lsl r3, r3, #4 */
/* @0x2dc304 rsbls r10, r3, #0 */
/* @0x2dc308 bls 0x2dc32c <_ZN16b2VoronoiDiagram8GenerateEf+0x768> */
/* @0x2dc30c rsb r10, r3, #0 */
/* @0x2dc310 mov r12, r11 */
/* @0x2dc314 ldm r12, {r0, r1, r2, r3} */
/* @0x2dc318 add r4, r12, r10 */
/* @0x2dc31c add r12, r12, #16 */
/* @0x2dc320 cmp r9, r12 */
/* @0x2dc324 stm r4, {r0, r1, r2, r3} */
/* @0x2dc328 bhi 0x2dc314 <_ZN16b2VoronoiDiagram8GenerateEf+0x750> */
/* @0x2dc32c ldr r3, [sp, #0x4] */
/* @0x2dc330 add r9, r9, r10 */
/* @0x2dc334 add r11, r11, r10 */
/* @0x2dc338 cmp r3, r9 */
/* @0x2dc33c bls 0x2dc35c <_ZN16b2VoronoiDiagram8GenerateEf+0x798> */
/* @0x2dc340 ldr r1, [sp] */
/* @0x2dc344 add r9, r9, #16 */
/* @0x2dc348 ldr r2, [sp, #0x8] */
/* @0x2dc34c str r7, [r9, #-0x10] */
/* @0x2dc350 str r1, [r9, #-0xc] */
/* @0x2dc354 str r2, [r9, #-0x8] */
/* @0x2dc358 str r5, [r9, #-0x4] */
/* @0x2dc35c ldr r1, [sp, #0x18] */
/* @0x2dc360 sub r3, r1, #1 */
/* @0x2dc364 cmp r7, r3 */
/* @0x2dc368 blt 0x2dc494 <_ZN16b2VoronoiDiagram8GenerateEf+0x8d0> */
/* @0x2dc36c ldr r3, [sp, #0x34] */
/* @0x2dc370 cmp r8, r3 */
/* @0x2dc374 blt 0x2dc418 <_ZN16b2VoronoiDiagram8GenerateEf+0x854> */
/* @0x2dc378 cmp r9, r11 */
/* @0x2dc37c mov r1, #1 */
/* @0x2dc380 bhi 0x2dc1c0 <_ZN16b2VoronoiDiagram8GenerateEf+0x5fc> */
/* @0x2dc384 cmp r1, #0 */
/* @0x2dc388 beq 0x2dc3a4 <_ZN16b2VoronoiDiagram8GenerateEf+0x7e0> */
/* @0x2dc38c ldr r5, [sp, #0x3c] */
/* @0x2dc390 ldr r1, [sp, #0x40] */
/* @0x2dc394 add r5, r5, #1 */
/* @0x2dc398 str r5, [sp, #0x3c] */
/* @0x2dc39c cmp r5, r1 */
/* @0x2dc3a0 bne 0x2dbe90 <_ZN16b2VoronoiDiagram8GenerateEf+0x2cc> */
/* @0x2dc3a4 ldr r0, [sp, #0x44] */
/* @0x2dc3a8 ldr r1, [sp, #0x1c] */
/* @0x2dc3ac add sp, sp, #76 */
/* @0x2dc3b0 vpop {d8, d9} */
/* @0x2dc3b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2dc3b8 b 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv> */
/* @0x2dc3bc mov r12, r9 */
/* @0x2dc3c0 ldr r5, [sp, #0x1c] */
/* @0x2dc3c4 cmp r12, r11 */
/* @0x2dc3c8 rsb r8, r5, r11 */
/* @0x2dc3cc asr r8, r8, #4 */
/* @0x2dc3d0 lsl r8, r8, #4 */
/* @0x2dc3d4 rsbls r8, r8, #0 */
/* @0x2dc3d8 bls 0x2dc3fc <_ZN16b2VoronoiDiagram8GenerateEf+0x838> */
/* @0x2dc3dc rsb r8, r8, #0 */
/* @0x2dc3e0 mov r4, r11 */
/* @0x2dc3e4 ldm r4, {r0, r1, r2, r3} */
/* @0x2dc3e8 add r5, r4, r8 */
/* @0x2dc3ec add r4, r4, #16 */
/* @0x2dc3f0 cmp r4, r12 */
/* @0x2dc3f4 stm r5, {r0, r1, r2, r3} */
/* @0x2dc3f8 blo 0x2dc3e4 <_ZN16b2VoronoiDiagram8GenerateEf+0x820> */
/* @0x2dc3fc ldr r5, [sp, #0x4] */
/* @0x2dc400 add r12, r12, r8 */
/* @0x2dc404 add r11, r11, r8 */
/* @0x2dc408 cmp r5, r12 */
/* @0x2dc40c movls r9, r12 */
/* @0x2dc410 bhi 0x2dc168 <_ZN16b2VoronoiDiagram8GenerateEf+0x5a4> */
/* @0x2dc414 b 0x2dc180 <_ZN16b2VoronoiDiagram8GenerateEf+0x5bc> */
/* @0x2dc418 ldr r1, [sp, #0x4] */
/* @0x2dc41c add r8, r8, #1 */
/* @0x2dc420 ldr r2, [sp, #0x18] */
/* @0x2dc424 cmp r1, r9 */
/* @0x2dc428 add r6, r6, r2 */
/* @0x2dc42c bhi 0x2dc480 <_ZN16b2VoronoiDiagram8GenerateEf+0x8bc> */
/* @0x2dc430 ldr r1, [sp, #0x1c] */
/* @0x2dc434 cmp r11, r9 */
/* @0x2dc438 rsb r3, r1, r11 */
/* @0x2dc43c asr r3, r3, #4 */
/* @0x2dc440 lsl r3, r3, #4 */
/* @0x2dc444 rsbhs r10, r3, #0 */
/* @0x2dc448 bhs 0x2dc46c <_ZN16b2VoronoiDiagram8GenerateEf+0x8a8> */
/* @0x2dc44c rsb r10, r3, #0 */
/* @0x2dc450 mov r12, r11 */
/* @0x2dc454 ldm r12, {r0, r1, r2, r3} */
/* @0x2dc458 add r4, r12, r10 */
/* @0x2dc45c add r12, r12, #16 */
/* @0x2dc460 cmp r12, r9 */
/* @0x2dc464 stm r4, {r0, r1, r2, r3} */
/* @0x2dc468 blo 0x2dc454 <_ZN16b2VoronoiDiagram8GenerateEf+0x890> */
/* @0x2dc46c ldr r2, [sp, #0x4] */
/* @0x2dc470 add r9, r9, r10 */
/* @0x2dc474 add r11, r11, r10 */
/* @0x2dc478 cmp r2, r9 */
/* @0x2dc47c bls 0x2dc378 <_ZN16b2VoronoiDiagram8GenerateEf+0x7b4> */
/* @0x2dc480 stm r9, {r7, r8} */
/* @0x2dc484 add r9, r9, #16 */
/* @0x2dc488 str r6, [r9, #-0x8] */
/* @0x2dc48c str r5, [r9, #-0x4] */
/* @0x2dc490 b 0x2dc378 <_ZN16b2VoronoiDiagram8GenerateEf+0x7b4> */
/* @0x2dc494 ldr r2, [sp, #0x4] */
/* @0x2dc498 add r3, r7, #1 */
/* @0x2dc49c add r1, r6, #1 */
/* @0x2dc4a0 str r3, [sp] */
/* @0x2dc4a4 cmp r2, r9 */
/* @0x2dc4a8 str r1, [sp, #0x8] */
/* @0x2dc4ac bhi 0x2dc500 <_ZN16b2VoronoiDiagram8GenerateEf+0x93c> */
/* @0x2dc4b0 ldr r2, [sp, #0x1c] */
/* @0x2dc4b4 cmp r9, r11 */
/* @0x2dc4b8 rsb r3, r2, r11 */
/* @0x2dc4bc asr r3, r3, #4 */
/* @0x2dc4c0 lsl r3, r3, #4 */
/* @0x2dc4c4 rsbls r10, r3, #0 */
/* @0x2dc4c8 bls 0x2dc4ec <_ZN16b2VoronoiDiagram8GenerateEf+0x928> */
/* @0x2dc4cc rsb r10, r3, #0 */
/* @0x2dc4d0 mov r12, r11 */
/* @0x2dc4d4 ldm r12, {r0, r1, r2, r3} */
/* @0x2dc4d8 add r4, r12, r10 */
/* @0x2dc4dc add r12, r12, #16 */
/* @0x2dc4e0 cmp r9, r12 */
/* @0x2dc4e4 stm r4, {r0, r1, r2, r3} */
/* @0x2dc4e8 bhi 0x2dc4d4 <_ZN16b2VoronoiDiagram8GenerateEf+0x910> */
/* @0x2dc4ec ldr r3, [sp, #0x4] */
/* @0x2dc4f0 add r9, r9, r10 */
/* @0x2dc4f4 add r11, r11, r10 */
/* @0x2dc4f8 cmp r3, r9 */
/* @0x2dc4fc bls 0x2dc36c <_ZN16b2VoronoiDiagram8GenerateEf+0x7a8> */
/* @0x2dc500 ldr r1, [sp] */
/* @0x2dc504 ldr r2, [sp, #0x8] */
/* @0x2dc508 str r5, [r9, #0xc] */
/* @0x2dc50c stm r9, {r1, r8} */
/* @0x2dc510 add r9, r9, #16 */
/* @0x2dc514 str r2, [r9, #-0x8] */
/* @0x2dc518 b 0x2dc36c <_ZN16b2VoronoiDiagram8GenerateEf+0x7a8> */
/* @0x2dc51c add r12, r12, #1 */
/* @0x2dc520 str r3, [r9, #0xc] */
/* @0x2dc524 cmp r12, r4 */
/* @0x2dc528 add r0, r0, #12 */
/* @0x2dc52c stm r9, {r1, r2, r5} */
/* @0x2dc530 add r9, r9, #16 */
/* @0x2dc534 bne 0x2dbd60 <_ZN16b2VoronoiDiagram8GenerateEf+0x19c> */
/* @0x2dc538 b 0x2dbe00 <_ZN16b2VoronoiDiagram8GenerateEf+0x23c> */
/* @0x2dc53c cmp r4, #0 */
/* @0x2dc540 str r6, [r1] */
/* @0x2dc544 mov r10, r11 */
/* @0x2dc548 ble 0x2dc5c8 <_ZN16b2VoronoiDiagram8GenerateEf+0xa04> */
/* @0x2dc54c ldr r1, [sp, #0x4] */
/* @0x2dc550 sub r2, r4, #1 */
/* @0x2dc554 sub r3, r12, #1 */
/* @0x2dc558 str r2, [sp] */
/* @0x2dc55c cmp r1, r9 */
/* @0x2dc560 str r3, [sp, #0x8] */
/* @0x2dc564 bhi 0x2dc5b0 <_ZN16b2VoronoiDiagram8GenerateEf+0x9ec> */
/* @0x2dc568 ldr r1, [sp, #0x1c] */
/* @0x2dc56c cmp r9, r11 */
/* @0x2dc570 rsb r3, r1, r11 */
/* @0x2dc574 asr r3, r3, #4 */
/* @0x2dc578 lsl r3, r3, #4 */
/* @0x2dc57c rsb r7, r3, #0 */
/* @0x2dc580 bls 0x2dc59c <_ZN16b2VoronoiDiagram8GenerateEf+0x9d8> */
/* @0x2dc584 ldm r11, {r0, r1, r2, r3} */
/* @0x2dc588 add r8, r11, r7 */
/* @0x2dc58c add r11, r11, #16 */
/* @0x2dc590 cmp r11, r9 */
/* @0x2dc594 stm r8, {r0, r1, r2, r3} */
/* @0x2dc598 blo 0x2dc584 <_ZN16b2VoronoiDiagram8GenerateEf+0x9c0> */
/* @0x2dc59c ldr r2, [sp, #0x4] */
/* @0x2dc5a0 add r9, r9, r7 */
/* @0x2dc5a4 add r11, r10, r7 */
/* @0x2dc5a8 cmp r2, r9 */
/* @0x2dc5ac bls 0x2dc5c8 <_ZN16b2VoronoiDiagram8GenerateEf+0xa04> */
/* @0x2dc5b0 ldr r3, [sp] */
/* @0x2dc5b4 ldr r1, [sp, #0x8] */
/* @0x2dc5b8 str r6, [r9, #0xc] */
/* @0x2dc5bc stm r9, {r3, r5} */
/* @0x2dc5c0 add r9, r9, #16 */
/* @0x2dc5c4 str r1, [r9, #-0x8] */
/* @0x2dc5c8 cmp r5, #0 */
/* @0x2dc5cc ble 0x2dc65c <_ZN16b2VoronoiDiagram8GenerateEf+0xa98> */
/* @0x2dc5d0 ldr r2, [sp, #0x4] */
/* @0x2dc5d4 sub r3, r5, #1 */
/* @0x2dc5d8 ldr r1, [sp, #0x18] */
/* @0x2dc5dc cmp r2, r9 */
/* @0x2dc5e0 str r3, [sp] */
/* @0x2dc5e4 rsb r1, r1, r12 */
/* @0x2dc5e8 str r1, [sp, #0x8] */
/* @0x2dc5ec bhi 0x2dc640 <_ZN16b2VoronoiDiagram8GenerateEf+0xa7c> */
/* @0x2dc5f0 ldr r2, [sp, #0x1c] */
/* @0x2dc5f4 cmp r11, r9 */
/* @0x2dc5f8 rsb r3, r2, r11 */
/* @0x2dc5fc asr r3, r3, #4 */
/* @0x2dc600 lsl r3, r3, #4 */
/* @0x2dc604 rsbhs r8, r3, #0 */
/* @0x2dc608 bhs 0x2dc62c <_ZN16b2VoronoiDiagram8GenerateEf+0xa68> */
/* @0x2dc60c rsb r8, r3, #0 */
/* @0x2dc610 mov r7, r11 */
/* @0x2dc614 ldm r7, {r0, r1, r2, r3} */
/* @0x2dc618 add r10, r7, r8 */
/* @0x2dc61c add r7, r7, #16 */
/* @0x2dc620 cmp r7, r9 */
/* @0x2dc624 stm r10, {r0, r1, r2, r3} */
/* @0x2dc628 blo 0x2dc614 <_ZN16b2VoronoiDiagram8GenerateEf+0xa50> */
/* @0x2dc62c ldr r3, [sp, #0x4] */
/* @0x2dc630 add r9, r9, r8 */
/* @0x2dc634 add r11, r11, r8 */
/* @0x2dc638 cmp r3, r9 */
/* @0x2dc63c bls 0x2dc65c <_ZN16b2VoronoiDiagram8GenerateEf+0xa98> */
/* @0x2dc640 ldr r1, [sp] */
/* @0x2dc644 add r9, r9, #16 */
/* @0x2dc648 ldr r2, [sp, #0x8] */
/* @0x2dc64c str r4, [r9, #-0x10] */
/* @0x2dc650 str r1, [r9, #-0xc] */
/* @0x2dc654 str r2, [r9, #-0x8] */
/* @0x2dc658 str r6, [r9, #-0x4] */
/* @0x2dc65c ldr r3, [sp, #0xc] */
/* @0x2dc660 cmp r3, r4 */
/* @0x2dc664 bgt 0x2dc6e8 <_ZN16b2VoronoiDiagram8GenerateEf+0xb24> */
/* @0x2dc668 ldr r2, [sp, #0x10] */
/* @0x2dc66c cmp r2, r5 */
/* @0x2dc670 ble 0x2dbe1c <_ZN16b2VoronoiDiagram8GenerateEf+0x258> */
/* @0x2dc674 ldr r3, [sp, #0x4] */
/* @0x2dc678 add r5, r5, #1 */
/* @0x2dc67c ldr r1, [sp, #0x18] */
/* @0x2dc680 mov r8, r11 */
/* @0x2dc684 cmp r3, r9 */
/* @0x2dc688 add r10, r12, r1 */
/* @0x2dc68c bhi 0x2dc6d8 <_ZN16b2VoronoiDiagram8GenerateEf+0xb14> */
/* @0x2dc690 ldr r2, [sp, #0x1c] */
/* @0x2dc694 cmp r11, r9 */
/* @0x2dc698 rsb r3, r2, r11 */
/* @0x2dc69c asr r3, r3, #4 */
/* @0x2dc6a0 lsl r3, r3, #4 */
/* @0x2dc6a4 rsb r12, r3, #0 */
/* @0x2dc6a8 bhs 0x2dc6c4 <_ZN16b2VoronoiDiagram8GenerateEf+0xb00> */
/* @0x2dc6ac ldm r11, {r0, r1, r2, r3} */
/* @0x2dc6b0 add r7, r11, r12 */
/* @0x2dc6b4 add r11, r11, #16 */
/* @0x2dc6b8 cmp r11, r9 */
/* @0x2dc6bc stm r7, {r0, r1, r2, r3} */
/* @0x2dc6c0 blo 0x2dc6ac <_ZN16b2VoronoiDiagram8GenerateEf+0xae8> */
/* @0x2dc6c4 ldr r3, [sp, #0x4] */
/* @0x2dc6c8 add r9, r9, r12 */
/* @0x2dc6cc add r11, r8, r12 */
/* @0x2dc6d0 cmp r3, r9 */
/* @0x2dc6d4 bls 0x2dbe1c <_ZN16b2VoronoiDiagram8GenerateEf+0x258> */
/* @0x2dc6d8 stm r9, {r4, r5, r10} */
/* @0x2dc6dc add r9, r9, #16 */
/* @0x2dc6e0 str r6, [r9, #-0x4] */
/* @0x2dc6e4 b 0x2dbe1c <_ZN16b2VoronoiDiagram8GenerateEf+0x258> */
/* @0x2dc6e8 ldr r1, [sp, #0x4] */
/* @0x2dc6ec add r2, r4, #1 */
/* @0x2dc6f0 add r3, r12, #1 */
/* @0x2dc6f4 str r2, [sp] */
/* @0x2dc6f8 cmp r1, r9 */
/* @0x2dc6fc str r3, [sp, #0x8] */
/* @0x2dc700 bhi 0x2dc754 <_ZN16b2VoronoiDiagram8GenerateEf+0xb90> */
/* @0x2dc704 ldr r1, [sp, #0x1c] */
/* @0x2dc708 cmp r11, r9 */
/* @0x2dc70c rsb r3, r1, r11 */
/* @0x2dc710 asr r3, r3, #4 */
/* @0x2dc714 lsl r3, r3, #4 */
/* @0x2dc718 rsbhs r8, r3, #0 */
/* @0x2dc71c bhs 0x2dc740 <_ZN16b2VoronoiDiagram8GenerateEf+0xb7c> */
/* @0x2dc720 rsb r8, r3, #0 */
/* @0x2dc724 mov r7, r11 */
/* @0x2dc728 ldm r7, {r0, r1, r2, r3} */
/* @0x2dc72c add r10, r7, r8 */
/* @0x2dc730 add r7, r7, #16 */
/* @0x2dc734 cmp r7, r9 */
/* @0x2dc738 stm r10, {r0, r1, r2, r3} */
/* @0x2dc73c blo 0x2dc728 <_ZN16b2VoronoiDiagram8GenerateEf+0xb64> */
/* @0x2dc740 ldr r2, [sp, #0x4] */
/* @0x2dc744 add r9, r9, r8 */
/* @0x2dc748 add r11, r11, r8 */
/* @0x2dc74c cmp r2, r9 */
/* @0x2dc750 bls 0x2dc668 <_ZN16b2VoronoiDiagram8GenerateEf+0xaa4> */
/* @0x2dc754 ldr r3, [sp] */
/* @0x2dc758 ldr r1, [sp, #0x8] */
/* @0x2dc75c str r6, [r9, #0xc] */
/* @0x2dc760 stm r9, {r3, r5} */
/* @0x2dc764 add r9, r9, #16 */
/* @0x2dc768 str r1, [r9, #-0x8] */
/* @0x2dc76c b 0x2dc668 <_ZN16b2VoronoiDiagram8GenerateEf+0xaa4> */
/* @0x2dc770 vldr s15, [pc, #44] */
/* @0x2dc774 vldr s16, [pc, #44] */
/* @0x2dc778 vmov.f32 s12, s15 */
/* @0x2dc77c vmov.f32 s17, s16 */
/* @0x2dc780 b 0x2dbc4c <_ZN16b2VoronoiDiagram8GenerateEf+0x88> */
/* @0x2dc784 ldr r5, [sp, #0x2c] */
/* @0x2dc788 ldr r9, [sp, #0x1c] */
/* @0x2dc78c ldr r5, [r5, #0xc] */
/* @0x2dc790 str r5, [sp, #0x18] */
/* @0x2dc794 ldr r5, [sp, #0x2c] */
/* @0x2dc798 ldr r5, [r5, #0x10] */
/* @0x2dc79c str r5, [sp, #0x38] */
/* @0x2dc7a0 b 0x2dbe00 <_ZN16b2VoronoiDiagram8GenerateEf+0x23c> */
/* @0x2dc7a4 .word 0xff7fffff */
/* @0x2dc7a8 svcvc #0x7fffff */

/* ── FUNC 0x2dc7ac · b2BroadPhase::b2BroadPhase() · size=72 · insn=18 */
/* @0x2dc7ac push {r4, r5, r6, lr} */
/* @0x2dc7b0 mov r4, r0 */
/* @0x2dc7b4 bl 0x2de900 <_ZN13b2DynamicTreeC2Ev> */
/* @0x2dc7b8 mov r5, #0 */
/* @0x2dc7bc mov r6, #16 */
/* @0x2dc7c0 str r5, [r4, #0x1c] */
/* @0x2dc7c4 mov r0, #128 */
/* @0x2dc7c8 str r5, [r4, #0x34] */
/* @0x2dc7cc str r6, [r4, #0x30] */
/* @0x2dc7d0 bl 0x2c6a6c <_Z7b2Alloci> */
/* @0x2dc7d4 str r6, [r4, #0x24] */
/* @0x2dc7d8 str r5, [r4, #0x28] */
/* @0x2dc7dc str r0, [r4, #0x2c] */
/* @0x2dc7e0 mov r0, #64 */
/* @0x2dc7e4 bl 0x2c6a6c <_Z7b2Alloci> */
/* @0x2dc7e8 str r0, [r4, #0x20] */
/* @0x2dc7ec mov r0, r4 */
/* @0x2dc7f0 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2dc7ac · b2BroadPhase::b2BroadPhase() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2dc7f4 · b2BroadPhase::~b2BroadPhase() · size=40 · insn=10 */
/* @0x2dc7f4 push {r4, lr} */
/* @0x2dc7f8 mov r4, r0 */
/* @0x2dc7fc ldr r0, [r0, #0x20] */
/* @0x2dc800 bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2dc804 ldr r0, [r4, #0x2c] */
/* @0x2dc808 bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2dc80c mov r0, r4 */
/* @0x2dc810 bl 0x2de9a4 <_ZN13b2DynamicTreeD2Ev> */
/* @0x2dc814 mov r0, r4 */
/* @0x2dc818 pop {r4, pc} */

/* ── FUNC 0x2dc7f4 · b2BroadPhase::~b2BroadPhase() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2dc81c · b2BroadPhase::BufferMove(int) · size=108 · insn=27 */
/* @0x2dc81c push {r4, r5, r6, lr} */
/* @0x2dc820 mov r4, r0 */
/* @0x2dc824 ldr r3, [r4, #0x24] */
/* @0x2dc828 mov r5, r1 */
/* @0x2dc82c ldr r0, [r0, #0x28] */
/* @0x2dc830 cmp r0, r3 */
/* @0x2dc834 beq 0x2dc850 <_ZN12b2BroadPhase10BufferMoveEi+0x34> */
/* @0x2dc838 ldr r3, [r4, #0x20] */
/* @0x2dc83c str r5, [r3, r0, lsl #2] */
/* @0x2dc840 ldr r3, [r4, #0x28] */
/* @0x2dc844 add r3, r3, #1 */
/* @0x2dc848 str r3, [r4, #0x28] */
/* @0x2dc84c pop {r4, r5, r6, pc} */
/* @0x2dc850 lsl r3, r0, #1 */
/* @0x2dc854 lsl r0, r0, #3 */
/* @0x2dc858 str r3, [r4, #0x24] */
/* @0x2dc85c ldr r6, [r4, #0x20] */
/* @0x2dc860 bl 0x2c6a6c <_Z7b2Alloci> */
/* @0x2dc864 ldr r2, [r4, #0x28] */
/* @0x2dc868 mov r1, r6 */
/* @0x2dc86c lsl r2, r2, #2 */
/* @0x2dc870 str r0, [r4, #0x20] */
/* @0x2dc874 bl 0xb65bc <memcpy@plt> */
/* @0x2dc878 mov r0, r6 */
/* @0x2dc87c bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2dc880 ldr r0, [r4, #0x28] */
/* @0x2dc884 b 0x2dc838 <_ZN12b2BroadPhase10BufferMoveEi+0x1c> */

/* ── FUNC 0x2dc888 · b2BroadPhase::CreateProxy(b2AABB const&, void*) · size=48 · insn=12 */
/* @0x2dc888 push {r3, r4, r5, lr} */
/* @0x2dc88c mov r4, r0 */
/* @0x2dc890 bl 0x2df46c <_ZN13b2DynamicTree11CreateProxyERK6b2AABBPv> */
/* @0x2dc894 ldr r3, [r4, #0x1c] */
/* @0x2dc898 add r3, r3, #1 */
/* @0x2dc89c str r3, [r4, #0x1c] */
/* @0x2dc8a0 mov r5, r0 */
/* @0x2dc8a4 mov r0, r4 */
/* @0x2dc8a8 mov r1, r5 */
/* @0x2dc8ac bl 0x2dc81c <_ZN12b2BroadPhase10BufferMoveEi> */
/* @0x2dc8b0 mov r0, r5 */
/* @0x2dc8b4 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2dc8b8 · b2BroadPhase::MoveProxy(int, b2AABB const&, b2Vec2 const&) · size=40 · insn=10 */
/* @0x2dc8b8 push {r3, r4, r5, lr} */
/* @0x2dc8bc mov r5, r0 */
/* @0x2dc8c0 mov r4, r1 */
/* @0x2dc8c4 bl 0x2df660 <_ZN13b2DynamicTree9MoveProxyEiRK6b2AABBRK6b2Vec2> */
/* @0x2dc8c8 cmp r0, #0 */
/* @0x2dc8cc popeq {r3, r4, r5, pc} */
/* @0x2dc8d0 mov r0, r5 */
/* @0x2dc8d4 mov r1, r4 */
/* @0x2dc8d8 pop {r3, r4, r5, lr} */
/* @0x2dc8dc b 0x2dc81c <_ZN12b2BroadPhase10BufferMoveEi> */

/* ── FUNC 0x2dc8e0 · b2BroadPhase::TouchProxy(int) · size=4 · insn=1 */
/* @0x2dc8e0 b 0x2dc81c <_ZN12b2BroadPhase10BufferMoveEi> */

/* ── FUNC 0x2dc8e4 · b2BroadPhase::UnBufferMove(int) · size=64 · insn=16 */
/* @0x2dc8e4 push {r4, r5} */
/* @0x2dc8e8 ldr r4, [r0, #0x28] */
/* @0x2dc8ec cmp r4, #0 */
/* @0x2dc8f0 ble 0x2dc91c <_ZN12b2BroadPhase12UnBufferMoveEi+0x38> */
/* @0x2dc8f4 ldr r2, [r0, #0x20] */
/* @0x2dc8f8 mov r3, #0 */
/* @0x2dc8fc mvn r5, #0 */
/* @0x2dc900 ldr r12, [r2], #4 */
/* @0x2dc904 add r3, r3, #1 */
/* @0x2dc908 cmp r12, r1 */
/* @0x2dc90c streq r5, [r2, #-0x4] */
/* @0x2dc910 ldreq r4, [r0, #0x28] */
/* @0x2dc914 cmp r4, r3 */
/* @0x2dc918 bgt 0x2dc900 <_ZN12b2BroadPhase12UnBufferMoveEi+0x1c> */
/* @0x2dc91c pop {r4, r5} */
/* @0x2dc920 bx lr */

/* ── FUNC 0x2dc924 · b2BroadPhase::DestroyProxy(int) · size=44 · insn=11 */
/* @0x2dc924 push {r3, r4, r5, lr} */
/* @0x2dc928 mov r4, r0 */
/* @0x2dc92c mov r5, r1 */
/* @0x2dc930 bl 0x2dc8e4 <_ZN12b2BroadPhase12UnBufferMoveEi> */
/* @0x2dc934 ldr r3, [r4, #0x1c] */
/* @0x2dc938 mov r1, r5 */
/* @0x2dc93c mov r0, r4 */
/* @0x2dc940 sub r3, r3, #1 */
/* @0x2dc944 str r3, [r4, #0x1c] */
/* @0x2dc948 pop {r3, r4, r5, lr} */
/* @0x2dc94c b 0x2df640 <_ZN13b2DynamicTree12DestroyProxyEi> */

/* ── FUNC 0x2dc950 · b2BroadPhase::QueryCallback(int) · size=160 · insn=40 */
/* @0x2dc950 ldr r3, [r0, #0x38] */
/* @0x2dc954 push {r4, r5, r6, lr} */
/* @0x2dc958 cmp r3, r1 */
/* @0x2dc95c mov r4, r0 */
/* @0x2dc960 mov r5, r1 */
/* @0x2dc964 beq 0x2dc99c <_ZN12b2BroadPhase13QueryCallbackEi+0x4c> */
/* @0x2dc968 ldr r0, [r0, #0x34] */
/* @0x2dc96c ldr r2, [r4, #0x30] */
/* @0x2dc970 cmp r0, r2 */
/* @0x2dc974 beq 0x2dc9b4 <_ZN12b2BroadPhase13QueryCallbackEi+0x64> */
/* @0x2dc978 ldr r2, [r4, #0x2c] */
/* @0x2dc97c cmp r5, r3 */
/* @0x2dc980 add r1, r2, r0, lsl #3 */
/* @0x2dc984 strlt r5, [r2, r0, lsl #3] */
/* @0x2dc988 movlt r5, r3 */
/* @0x2dc98c bge 0x2dc9a4 <_ZN12b2BroadPhase13QueryCallbackEi+0x54> */
/* @0x2dc990 str r5, [r1, #0x4] */
/* @0x2dc994 add r0, r0, #1 */
/* @0x2dc998 str r0, [r4, #0x34] */
/* @0x2dc99c mov r0, #1 */
/* @0x2dc9a0 pop {r4, r5, r6, pc} */
/* @0x2dc9a4 cmp r5, r3 */
/* @0x2dc9a8 movlt r5, r3 */
/* @0x2dc9ac str r3, [r2, r0, lsl #3] */
/* @0x2dc9b0 b 0x2dc990 <_ZN12b2BroadPhase13QueryCallbackEi+0x40> */
/* @0x2dc9b4 lsl r3, r0, #1 */
/* @0x2dc9b8 lsl r0, r0, #4 */
/* @0x2dc9bc str r3, [r4, #0x30] */
/* @0x2dc9c0 ldr r6, [r4, #0x2c] */
/* @0x2dc9c4 bl 0x2c6a6c <_Z7b2Alloci> */
/* @0x2dc9c8 ldr r2, [r4, #0x34] */
/* @0x2dc9cc mov r1, r6 */
/* @0x2dc9d0 lsl r2, r2, #3 */
/* @0x2dc9d4 str r0, [r4, #0x2c] */
/* @0x2dc9d8 bl 0xb65bc <memcpy@plt> */
/* @0x2dc9dc mov r0, r6 */
/* @0x2dc9e0 bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2dc9e4 ldr r0, [r4, #0x34] */
/* @0x2dc9e8 ldr r3, [r4, #0x38] */
/* @0x2dc9ec b 0x2dc978 <_ZN12b2BroadPhase13QueryCallbackEi+0x28> */

/* ── FUNC 0x2dc9f0 · b2CollideCircles(b2Manifold*, b2CircleShape const*, b2Transform const&, b2CircleShape const*, b2Transform const&) · size=224 · insn=56 */
/* @0x2dc9f0 push {r4, r5, r6} */
/* @0x2dc9f4 vldr s7, [r2, #12] */
/* @0x2dc9f8 vldr s14, [r1, #16] */
/* @0x2dc9fc vldr s6, [r3, #16] */
/* @0x2dca00 ldr r12, [sp, #0xc] */
/* @0x2dca04 vmul.f32 s11, s7, s14 */
/* @0x2dca08 vldr s9, [r12, #12] */
/* @0x2dca0c vldr s5, [r2, #8] */
/* @0x2dca10 vldr s13, [r12, #8] */
/* @0x2dca14 vldr s8, [r1, #12] */
/* @0x2dca18 vldr s10, [r3, #12] */
/* @0x2dca1c vldr s0, [r2, #4] */
/* @0x2dca20 vldr s15, [r12, #4] */
/* @0x2dca24 vldr s1, [r12] */
/* @0x2dca28 vldr s2, [r2] */
/* @0x2dca2c vldr s3, [r1, #8] */
/* @0x2dca30 vldr s4, [r3, #8] */
/* @0x2dca34 mov r12, #0 */
/* @0x2dca38 mov r2, r0 */
/* @0x2dca3c str r12, [r0, #0x3c] */
/* @0x2dca40 vmul.f32 s12, s9, s6 */
/* @0x2dca44 vmul.f32 s14, s5, s14 */
/* @0x2dca48 vmla.f32 s12, s10, s13 */
/* @0x2dca4c vmla.f32 s11, s8, s5 */
/* @0x2dca50 vmul.f32 s13, s13, s6 */
/* @0x2dca54 vnmls.f32 s14, s7, s8 */
/* @0x2dca58 vnmls.f32 s13, s9, s10 */
/* @0x2dca5c vadd.f32 s15, s12, s15 */
/* @0x2dca60 vadd.f32 s11, s11, s0 */
/* @0x2dca64 vsub.f32 s15, s15, s11 */
/* @0x2dca68 vadd.f32 s13, s13, s1 */
/* @0x2dca6c vadd.f32 s14, s14, s2 */
/* @0x2dca70 vmul.f32 s15, s15, s15 */
/* @0x2dca74 vsub.f32 s14, s13, s14 */
/* @0x2dca78 vadd.f32 s12, s3, s4 */
/* @0x2dca7c vmla.f32 s15, s14, s14 */
/* @0x2dca80 vmul.f32 s12, s12, s12 */
/* @0x2dca84 vcmpe.f32 s12, s15 */
/* @0x2dca88 vmrs APSR_nzcv, fpscr */
/* @0x2dca8c bmi 0x2dcac8 <_Z16b2CollideCirclesP10b2ManifoldPK13b2CircleShapeRK11b2TransformS3_S6_+0xd8> */
/* @0x2dca90 add r1, r1, #12 */
/* @0x2dca94 str r12, [r0, #0x38] */
/* @0x2dca98 add r4, r0, #48 */
/* @0x2dca9c add r3, r3, #12 */
/* @0x2dcaa0 ldm r1, {r0, r1} */
/* @0x2dcaa4 mov r5, #0 */
/* @0x2dcaa8 mov r6, #1 */
/* @0x2dcaac stm r4, {r0, r1} */
/* @0x2dcab0 str r5, [r2, #0x28] */
/* @0x2dcab4 str r5, [r2, #0x2c] */
/* @0x2dcab8 ldm r3, {r0, r1} */
/* @0x2dcabc str r6, [r2, #0x3c] */
/* @0x2dcac0 str r12, [r2, #0x10] */
/* @0x2dcac4 stm r2, {r0, r1} */
/* @0x2dcac8 pop {r4, r5, r6} */
/* @0x2dcacc bx lr */

/* ── FUNC 0x2dcad0 · b2CollidePolygonAndCircle(b2Manifold*, b2PolygonShape const*, b2Transform const&, b2CircleShape const*, b2Transform const&) · size=992 · insn=248 */
/* @0x2dcad0 push {r4, r5, r6, r7, r8, lr} */
/* @0x2dcad4 vpush {d8, d9} */
/* @0x2dcad8 sub sp, sp, #8 */
/* @0x2dcadc vldr s6, [r3, #16] */
/* @0x2dcae0 vldr s11, [r3, #12] */
/* @0x2dcae4 vldr s2, [r2, #4] */
/* @0x2dcae8 ldr r12, [sp, #0x30] */
/* @0x2dcaec vldr s10, [r12, #12] */
/* @0x2dcaf0 vmul.f32 s14, s10, s6 */
/* @0x2dcaf4 vldr s7, [r12, #8] */
/* @0x2dcaf8 vldr s9, [r12, #4] */
/* @0x2dcafc vldr s3, [r12] */
/* @0x2dcb00 vldr s12, [r2, #8] */
/* @0x2dcb04 vldr s13, [r2, #12] */
/* @0x2dcb08 vldr s4, [r2] */
/* @0x2dcb0c ldr r5, [r1, #0x94] */
/* @0x2dcb10 mov r4, #0 */
/* @0x2dcb14 vldr s5, [r1, #8] */
/* @0x2dcb18 cmp r5, r4 */
/* @0x2dcb1c vldr s8, [r3, #8] */
/* @0x2dcb20 mov r7, r0 */
/* @0x2dcb24 str r4, [r0, #0x3c] */
/* @0x2dcb28 add r8, r1, #84 */
/* @0x2dcb2c add r0, r1, #20 */
/* @0x2dcb30 vmul.f32 s15, s7, s6 */
/* @0x2dcb34 vmla.f32 s14, s11, s7 */
/* @0x2dcb38 vnmls.f32 s15, s10, s11 */
/* @0x2dcb3c vadd.f32 s9, s14, s9 */
/* @0x2dcb40 vsub.f32 s9, s9, s2 */
/* @0x2dcb44 vadd.f32 s15, s15, s3 */
/* @0x2dcb48 vmul.f32 s10, s9, s12 */
/* @0x2dcb4c vmul.f32 s9, s9, s13 */
/* @0x2dcb50 vsub.f32 s15, s15, s4 */
/* @0x2dcb54 vadd.f32 s8, s5, s8 */
/* @0x2dcb58 vmls.f32 s9, s12, s15 */
/* @0x2dcb5c vmla.f32 s10, s15, s13 */
/* @0x2dcb60 ble 0x2dccf4 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x224> */
/* @0x2dcb64 vldr s15, [r1, #24] */
/* @0x2dcb68 vldr s12, [r1, #88] */
/* @0x2dcb6c vldr s13, [r1, #20] */
/* @0x2dcb70 vldr s14, [r1, #84] */
/* @0x2dcb74 vsub.f32 s15, s9, s15 */
/* @0x2dcb78 vmul.f32 s15, s15, s12 */
/* @0x2dcb7c vsub.f32 s13, s10, s13 */
/* @0x2dcb80 vmla.f32 s15, s13, s14 */
/* @0x2dcb84 vcmpe.f32 s8, s15 */
/* @0x2dcb88 vmrs APSR_nzcv, fpscr */
/* @0x2dcb8c bmi 0x2dcce8 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x218> */
/* @0x2dcb90 add r12, r1, #28 */
/* @0x2dcb94 mov r6, r4 */
/* @0x2dcb98 add r2, r1, #92 */
/* @0x2dcb9c vldr s11, [pc, #772] */
/* @0x2dcba0 b 0x2dcbd8 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x108> */
/* @0x2dcba4 vldr s15, [r12, #4] */
/* @0x2dcba8 vsub.f32 s15, s9, s15 */
/* @0x2dcbac vldr s12, [r2, #4] */
/* @0x2dcbb0 vldr s13, [r12] */
/* @0x2dcbb4 vldr s14, [r2] */
/* @0x2dcbb8 add r12, r12, #8 */
/* @0x2dcbbc add r2, r2, #8 */
/* @0x2dcbc0 vmul.f32 s15, s15, s12 */
/* @0x2dcbc4 vsub.f32 s13, s10, s13 */
/* @0x2dcbc8 vmla.f32 s15, s13, s14 */
/* @0x2dcbcc vcmpe.f32 s8, s15 */
/* @0x2dcbd0 vmrs APSR_nzcv, fpscr */
/* @0x2dcbd4 bmi 0x2dcce8 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x218> */
/* @0x2dcbd8 vcmpe.f32 s11, s15 */
/* @0x2dcbdc vmrs APSR_nzcv, fpscr */
/* @0x2dcbe0 movmi r6, r4 */
/* @0x2dcbe4 add r4, r4, #1 */
/* @0x2dcbe8 vmovmi.f32 s11, s15 */
/* @0x2dcbec cmp r4, r5 */
/* @0x2dcbf0 bne 0x2dcba4 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0xd4> */
/* @0x2dcbf4 vldr s15, [pc, #688] */
/* @0x2dcbf8 vcmpe.f32 s11, s15 */
/* @0x2dcbfc add r2, r6, #1 */
/* @0x2dcc00 lsl r6, r6, #3 */
/* @0x2dcc04 cmp r4, r2 */
/* @0x2dcc08 lslgt r2, r2, #3 */
/* @0x2dcc0c movle r2, #0 */
/* @0x2dcc10 vmrs APSR_nzcv, fpscr */
/* @0x2dcc14 add r2, r0, r2 */
/* @0x2dcc18 add r0, r0, r6 */
/* @0x2dcc1c vldr s19, [r2] */
/* @0x2dcc20 vldr s17, [r0] */
/* @0x2dcc24 vldr s16, [r0, #4] */
/* @0x2dcc28 vldr s18, [r2, #4] */
/* @0x2dcc2c bmi 0x2dcd08 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x238> */
/* @0x2dcc30 vsub.f32 s14, s9, s16 */
/* @0x2dcc34 vsub.f32 s15, s18, s16 */
/* @0x2dcc38 vmul.f32 s15, s14, s15 */
/* @0x2dcc3c vsub.f32 s13, s10, s17 */
/* @0x2dcc40 vsub.f32 s12, s19, s17 */
/* @0x2dcc44 vmla.f32 s15, s13, s12 */
/* @0x2dcc48 vcmpe.f32 s15, #0 */
/* @0x2dcc4c vmrs APSR_nzcv, fpscr */
/* @0x2dcc50 bls 0x2dcd60 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x290> */
/* @0x2dcc54 vsub.f32 s14, s9, s18 */
/* @0x2dcc58 vsub.f32 s15, s16, s18 */
/* @0x2dcc5c vmul.f32 s15, s14, s15 */
/* @0x2dcc60 vsub.f32 s13, s10, s19 */
/* @0x2dcc64 vsub.f32 s12, s17, s19 */
/* @0x2dcc68 vmla.f32 s15, s13, s12 */
/* @0x2dcc6c vcmpe.f32 s15, #0 */
/* @0x2dcc70 vmrs APSR_nzcv, fpscr */
/* @0x2dcc74 bls 0x2dcdec <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x31c> */
/* @0x2dcc78 vmov.f32 s14, #5.000000e-01 */
/* @0x2dcc7c add r6, r8, r6 */
/* @0x2dcc80 vldr s15, [r6, #4] */
/* @0x2dcc84 vldr s12, [r6] */
/* @0x2dcc88 vadd.f32 s13, s18, s16 */
/* @0x2dcc8c vmul.f32 s13, s13, s14 */
/* @0x2dcc90 vadd.f32 s17, s17, s19 */
/* @0x2dcc94 vsub.f32 s9, s9, s13 */
/* @0x2dcc98 vmul.f32 s14, s17, s14 */
/* @0x2dcc9c vmul.f32 s15, s9, s15 */
/* @0x2dcca0 vsub.f32 s10, s10, s14 */
/* @0x2dcca4 vmla.f32 s15, s10, s12 */
/* @0x2dcca8 vcmpe.f32 s8, s15 */
/* @0x2dccac vmrs APSR_nzcv, fpscr */
/* @0x2dccb0 bmi 0x2dcce8 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x218> */
/* @0x2dccb4 ldm r6, {r0, r1} */
/* @0x2dccb8 add r3, r3, #12 */
/* @0x2dccbc add r2, r7, #40 */
/* @0x2dccc0 mov r12, #1 */
/* @0x2dccc4 str r12, [r7, #0x3c] */
/* @0x2dccc8 mov r4, #0 */
/* @0x2dcccc str r12, [r7, #0x38] */
/* @0x2dccd0 stm r2, {r0, r1} */
/* @0x2dccd4 vstr s14, [r7, #48] */
/* @0x2dccd8 vstr s13, [r7, #52] */
/* @0x2dccdc ldm r3, {r0, r1} */
/* @0x2dcce0 str r4, [r7, #0x10] */
/* @0x2dcce4 stm r7, {r0, r1} */
/* @0x2dcce8 add sp, sp, #8 */
/* @0x2dccec vpop {d8, d9} */
/* @0x2dccf0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2dccf4 vldr s17, [r1, #20] */
/* @0x2dccf8 vldr s16, [r1, #24] */
/* @0x2dccfc vmov.f32 s19, s17 */
/* @0x2dcd00 mov r6, r4 */
/* @0x2dcd04 vmov.f32 s18, s16 */
/* @0x2dcd08 add r6, r8, r6 */
/* @0x2dcd0c add r3, r3, #12 */
/* @0x2dcd10 add r2, r7, #40 */
/* @0x2dcd14 mov r12, #1 */
/* @0x2dcd18 vadd.f32 s17, s17, s19 */
/* @0x2dcd1c ldm r6, {r0, r1} */
/* @0x2dcd20 str r12, [r7, #0x3c] */
/* @0x2dcd24 mov r4, #0 */
/* @0x2dcd28 str r12, [r7, #0x38] */
/* @0x2dcd2c stm r2, {r0, r1} */
/* @0x2dcd30 vadd.f32 s16, s18, s16 */
/* @0x2dcd34 vmov.f32 s15, #5.000000e-01 */
/* @0x2dcd38 vmul.f32 s17, s17, s15 */
/* @0x2dcd3c vmul.f32 s15, s16, s15 */
/* @0x2dcd40 vstr s17, [r7, #48] */
/* @0x2dcd44 vstr s15, [r7, #52] */
/* @0x2dcd48 ldm r3, {r0, r1} */
/* @0x2dcd4c str r4, [r7, #0x10] */
/* @0x2dcd50 stm r7, {r0, r1} */
/* @0x2dcd54 add sp, sp, #8 */
/* @0x2dcd58 vpop {d8, d9} */
/* @0x2dcd5c pop {r4, r5, r6, r7, r8, pc} */
/* @0x2dcd60 vmul.f32 s15, s14, s14 */
/* @0x2dcd64 vmla.f32 s15, s13, s13 */
/* @0x2dcd68 vmul.f32 s8, s8, s8 */
/* @0x2dcd6c vcmpe.f32 s8, s15 */
/* @0x2dcd70 vmrs APSR_nzcv, fpscr */
/* @0x2dcd74 bmi 0x2dcce8 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x218> */
/* @0x2dcd78 vsqrt.f32 s12, s15 */
/* @0x2dcd7c mov r2, #1 */
/* @0x2dcd80 vstr s13, [r7, #40] */
/* @0x2dcd84 vstr s14, [r7, #44] */
/* @0x2dcd88 str r2, [r7, #0x3c] */
/* @0x2dcd8c str r2, [r7, #0x38] */
/* @0x2dcd90 vcmp.f32 s12, s12 */
/* @0x2dcd94 vmrs APSR_nzcv, fpscr */
/* @0x2dcd98 bne 0x2dce90 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x3c0> */
/* @0x2dcd9c vldr s15, [pc, #264] */
/* @0x2dcda0 vcmpe.f32 s12, s15 */
/* @0x2dcda4 vmrs APSR_nzcv, fpscr */
/* @0x2dcda8 bmi 0x2dcdcc <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x2fc> */
/* @0x2dcdac vmov.f32 s13, #1.000000e+00 */
/* @0x2dcdb0 vldr s15, [r7, #40] */
/* @0x2dcdb4 vldr s14, [r7, #44] */
/* @0x2dcdb8 vdiv.f32 s12, s13, s12 */
/* @0x2dcdbc vmul.f32 s15, s15, s12 */
/* @0x2dcdc0 vmul.f32 s12, s14, s12 */
/* @0x2dcdc4 vstr s15, [r7, #40] */
/* @0x2dcdc8 vstr s12, [r7, #44] */
/* @0x2dcdcc add r3, r3, #12 */
/* @0x2dcdd0 vstr s17, [r7, #48] */
/* @0x2dcdd4 vstr s16, [r7, #52] */
/* @0x2dcdd8 mov r2, #0 */
/* @0x2dcddc ldm r3, {r0, r1} */
/* @0x2dcde0 str r2, [r7, #0x10] */
/* @0x2dcde4 stm r7, {r0, r1} */
/* @0x2dcde8 b 0x2dcce8 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x218> */
/* @0x2dcdec vmul.f32 s15, s14, s14 */
/* @0x2dcdf0 vmla.f32 s15, s13, s13 */
/* @0x2dcdf4 vmul.f32 s8, s8, s8 */
/* @0x2dcdf8 vcmpe.f32 s8, s15 */
/* @0x2dcdfc vmrs APSR_nzcv, fpscr */
/* @0x2dce00 bmi 0x2dcce8 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x218> */
/* @0x2dce04 vsqrt.f32 s12, s15 */
/* @0x2dce08 mov r2, #1 */
/* @0x2dce0c vstr s13, [r7, #40] */
/* @0x2dce10 vstr s14, [r7, #44] */
/* @0x2dce14 str r2, [r7, #0x3c] */
/* @0x2dce18 str r2, [r7, #0x38] */
/* @0x2dce1c vcmp.f32 s12, s12 */
/* @0x2dce20 vmrs APSR_nzcv, fpscr */
/* @0x2dce24 bne 0x2dce78 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x3a8> */
/* @0x2dce28 vldr s15, [pc, #124] */
/* @0x2dce2c vcmpe.f32 s12, s15 */
/* @0x2dce30 vmrs APSR_nzcv, fpscr */
/* @0x2dce34 bmi 0x2dce58 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x388> */
/* @0x2dce38 vmov.f32 s13, #1.000000e+00 */
/* @0x2dce3c vldr s15, [r7, #40] */
/* @0x2dce40 vldr s14, [r7, #44] */
/* @0x2dce44 vdiv.f32 s12, s13, s12 */
/* @0x2dce48 vmul.f32 s15, s15, s12 */
/* @0x2dce4c vmul.f32 s12, s14, s12 */
/* @0x2dce50 vstr s15, [r7, #40] */
/* @0x2dce54 vstr s12, [r7, #44] */
/* @0x2dce58 add r3, r3, #12 */
/* @0x2dce5c vstr s19, [r7, #48] */
/* @0x2dce60 vstr s18, [r7, #52] */
/* @0x2dce64 mov r2, #0 */
/* @0x2dce68 ldm r3, {r0, r1} */
/* @0x2dce6c str r2, [r7, #0x10] */
/* @0x2dce70 stm r7, {r0, r1} */
/* @0x2dce74 b 0x2dcce8 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x218> */
/* @0x2dce78 vmov r0, s15 */
/* @0x2dce7c str r3, [sp, #0x4] */
/* @0x2dce80 bl 0xb6700 <sqrtf@plt> */
/* @0x2dce84 ldr r3, [sp, #0x4] */
/* @0x2dce88 vmov s12, r0 */
/* @0x2dce8c b 0x2dce28 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x358> */
/* @0x2dce90 vmov r0, s15 */
/* @0x2dce94 str r3, [sp, #0x4] */
/* @0x2dce98 bl 0xb6700 <sqrtf@plt> */
/* @0x2dce9c ldr r3, [sp, #0x4] */
/* @0x2dcea0 vmov s12, r0 */
/* @0x2dcea4 b 0x2dcd9c <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x2cc> */
/* @0x2dcea8 .word 0xff7fffff */
/* @0x2dceac strlo r0, [r0], #-0 */

/* ── FUNC 0x2dceb0 · b2CollideEdgeAndCircle(b2Manifold*, b2EdgeShape const*, b2Transform const&, b2CircleShape const*, b2Transform const&) · size=756 · insn=189 */
/* @0x2dceb0 push {r4, lr} */
/* @0x2dceb4 vpush {d8, d9} */
/* @0x2dceb8 sub sp, sp, #8 */
/* @0x2dcebc vldr s14, [r3, #16] */
/* @0x2dcec0 vldr s7, [r3, #12] */
/* @0x2dcec4 vldr s1, [r2, #4] */
/* @0x2dcec8 ldr r12, [sp, #0x20] */
/* @0x2dcecc vldr s6, [r12, #12] */
/* @0x2dced0 vmul.f32 s12, s6, s14 */
/* @0x2dced4 vldr s5, [r12, #8] */
/* @0x2dced8 vldr s15, [r12, #4] */
/* @0x2dcedc vldr s11, [r12] */
/* @0x2dcee0 vldr s13, [r2, #12] */
/* @0x2dcee4 vldr s2, [r2] */
/* @0x2dcee8 vldr s8, [r2, #8] */
/* @0x2dceec vldr s17, [r1, #16] */
/* @0x2dcef0 vldr s9, [r1, #24] */
/* @0x2dcef4 vldr s18, [r1, #12] */
/* @0x2dcef8 vldr s10, [r1, #20] */
/* @0x2dcefc vldr s3, [r1, #8] */
/* @0x2dcf00 mov r2, #0 */
/* @0x2dcf04 vldr s4, [r3, #8] */
/* @0x2dcf08 mov r4, r0 */
/* @0x2dcf0c str r2, [r0, #0x3c] */
/* @0x2dcf10 vmla.f32 s12, s7, s5 */
/* @0x2dcf14 vmul.f32 s14, s5, s14 */
/* @0x2dcf18 vnmls.f32 s14, s6, s7 */
/* @0x2dcf1c vadd.f32 s15, s12, s15 */
/* @0x2dcf20 vsub.f32 s15, s15, s1 */
/* @0x2dcf24 vadd.f32 s11, s14, s11 */
/* @0x2dcf28 vmul.f32 s14, s15, s13 */
/* @0x2dcf2c vsub.f32 s11, s11, s2 */
/* @0x2dcf30 vmul.f32 s15, s15, s8 */
/* @0x2dcf34 vmls.f32 s14, s8, s11 */
/* @0x2dcf38 vmla.f32 s15, s11, s13 */
/* @0x2dcf3c vsub.f32 s6, s14, s17 */
/* @0x2dcf40 vsub.f32 s12, s9, s17 */
/* @0x2dcf44 vmul.f32 s13, s12, s6 */
/* @0x2dcf48 vsub.f32 s7, s15, s18 */
/* @0x2dcf4c vsub.f32 s16, s10, s18 */
/* @0x2dcf50 vmla.f32 s13, s16, s7 */
/* @0x2dcf54 vcmpe.f32 s13, #0 */
/* @0x2dcf58 vadd.f32 s8, s3, s4 */
/* @0x2dcf5c vmrs APSR_nzcv, fpscr */
/* @0x2dcf60 bls 0x2dd060 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x1b0> */
/* @0x2dcf64 vsub.f32 s11, s9, s14 */
/* @0x2dcf68 vmul.f32 s11, s12, s11 */
/* @0x2dcf6c vsub.f32 s5, s10, s15 */
/* @0x2dcf70 vmla.f32 s11, s16, s5 */
/* @0x2dcf74 vcmpe.f32 s11, #0 */
/* @0x2dcf78 vmrs APSR_nzcv, fpscr */
/* @0x2dcf7c bls 0x2dd0f4 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x244> */
/* @0x2dcf80 vmul.f32 s3, s16, s16 */
/* @0x2dcf84 vmul.f32 s4, s12, s12 */
/* @0x2dcf88 vmov.f32 s2, #1.000000e+00 */
/* @0x2dcf8c vadd.f32 s5, s3, s4 */
/* @0x2dcf90 vdiv.f32 s5, s2, s5 */
/* @0x2dcf94 vmul.f32 s9, s9, s13 */
/* @0x2dcf98 vmul.f32 s13, s10, s13 */
/* @0x2dcf9c vmla.f32 s9, s17, s11 */
/* @0x2dcfa0 vmla.f32 s13, s18, s11 */
/* @0x2dcfa4 vmls.f32 s14, s5, s9 */
/* @0x2dcfa8 vmls.f32 s15, s5, s13 */
/* @0x2dcfac vmul.f32 s14, s14, s14 */
/* @0x2dcfb0 vmla.f32 s14, s15, s15 */
/* @0x2dcfb4 vmul.f32 s8, s8, s8 */
/* @0x2dcfb8 vcmpe.f32 s8, s14 */
/* @0x2dcfbc vmrs APSR_nzcv, fpscr */
/* @0x2dcfc0 bmi 0x2dd054 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x1a4> */
/* @0x2dcfc4 vmul.f32 s6, s16, s6 */
/* @0x2dcfc8 vneg.f32 s19, s12 */
/* @0x2dcfcc vmla.f32 s6, s19, s7 */
/* @0x2dcfd0 vcmpe.f32 s6, #0 */
/* @0x2dcfd4 vmrs APSR_nzcv, fpscr */
/* @0x2dcfd8 vnegmi.f32 s16, s16 */
/* @0x2dcfdc vmulpl.f32 s4, s19, s19 */
/* @0x2dcfe0 vmulmi.f32 s3, s16, s16 */
/* @0x2dcfe4 vadd.f32 s4, s3, s4 */
/* @0x2dcfe8 vsqrt.f32 s15, s4 */
/* @0x2dcfec vcmp.f32 s15, s15 */
/* @0x2dcff0 vmovmi.f32 s19, s12 */
/* @0x2dcff4 vmrs APSR_nzcv, fpscr */
/* @0x2dcff8 bne 0x2dd188 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x2d8> */
/* @0x2dcffc vldr s14, [pc, #412] */
/* @0x2dd000 add r3, r3, #12 */
/* @0x2dd004 vcmpe.f32 s15, s14 */
/* @0x2dd008 mov r1, #0 */
/* @0x2dd00c mov r2, #1 */
/* @0x2dd010 vstr s18, [r4, #48] */
/* @0x2dd014 vstr s17, [r4, #52] */
/* @0x2dd018 strb r2, [r4, #0x12] */
/* @0x2dd01c strb r1, [r4, #0x10] */
/* @0x2dd020 vmrs APSR_nzcv, fpscr */
/* @0x2dd024 vmovpl.f32 s14, #1.000000e+00 */
/* @0x2dd028 strb r1, [r4, #0x11] */
/* @0x2dd02c strb r1, [r4, #0x13] */
/* @0x2dd030 vdivpl.f32 s15, s14, s15 */
/* @0x2dd034 vmulpl.f32 s19, s19, s15 */
/* @0x2dd038 vmulpl.f32 s16, s16, s15 */
/* @0x2dd03c vstr s19, [r4, #40] */
/* @0x2dd040 vstr s16, [r4, #44] */
/* @0x2dd044 ldm r3, {r0, r1} */
/* @0x2dd048 str r2, [r4, #0x3c] */
/* @0x2dd04c str r2, [r4, #0x38] */
/* @0x2dd050 stm r4, {r0, r1} */
/* @0x2dd054 add sp, sp, #8 */
/* @0x2dd058 vpop {d8, d9} */
/* @0x2dd05c pop {r4, pc} */
/* @0x2dd060 vmul.f32 s6, s6, s6 */
/* @0x2dd064 vmla.f32 s6, s7, s7 */
/* @0x2dd068 vmul.f32 s8, s8, s8 */
/* @0x2dd06c vcmpe.f32 s8, s6 */
/* @0x2dd070 vmrs APSR_nzcv, fpscr */
/* @0x2dd074 bmi 0x2dd054 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x1a4> */
/* @0x2dd078 ldrb r2, [r1, #0x2c] */
/* @0x2dd07c cmp r2, #0 */
/* @0x2dd080 beq 0x2dd0b0 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x200> */
/* @0x2dd084 vsub.f32 s14, s17, s14 */
/* @0x2dd088 vldr s12, [r1, #32] */
/* @0x2dd08c vldr s13, [r1, #28] */
/* @0x2dd090 vsub.f32 s12, s17, s12 */
/* @0x2dd094 vmul.f32 s14, s12, s14 */
/* @0x2dd098 vsub.f32 s15, s18, s15 */
/* @0x2dd09c vsub.f32 s13, s18, s13 */
/* @0x2dd0a0 vmla.f32 s14, s13, s15 */
/* @0x2dd0a4 vcmpe.f32 s14, #0 */
/* @0x2dd0a8 vmrs APSR_nzcv, fpscr */
/* @0x2dd0ac bgt 0x2dd054 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x1a4> */
/* @0x2dd0b0 add r3, r3, #12 */
/* @0x2dd0b4 mov r2, #0 */
/* @0x2dd0b8 mov r1, #0 */
/* @0x2dd0bc vstr s18, [r4, #48] */
/* @0x2dd0c0 vstr s17, [r4, #52] */
/* @0x2dd0c4 strb r2, [r4, #0x10] */
/* @0x2dd0c8 strb r2, [r4, #0x11] */
/* @0x2dd0cc mov r12, #1 */
/* @0x2dd0d0 str r1, [r4, #0x28] */
/* @0x2dd0d4 strb r2, [r4, #0x12] */
/* @0x2dd0d8 str r1, [r4, #0x2c] */
/* @0x2dd0dc strb r2, [r4, #0x13] */
/* @0x2dd0e0 ldm r3, {r0, r1} */
/* @0x2dd0e4 str r2, [r4, #0x38] */
/* @0x2dd0e8 str r12, [r4, #0x3c] */
/* @0x2dd0ec stm r4, {r0, r1} */
/* @0x2dd0f0 b 0x2dd054 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x1a4> */
/* @0x2dd0f4 vsub.f32 s14, s14, s9 */
/* @0x2dd0f8 vmul.f32 s13, s14, s14 */
/* @0x2dd0fc vsub.f32 s15, s15, s10 */
/* @0x2dd100 vmla.f32 s13, s15, s15 */
/* @0x2dd104 vmul.f32 s8, s8, s8 */
/* @0x2dd108 vcmpe.f32 s8, s13 */
/* @0x2dd10c vmrs APSR_nzcv, fpscr */
/* @0x2dd110 bmi 0x2dd054 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x1a4> */
/* @0x2dd114 ldrb r2, [r1, #0x2d] */
/* @0x2dd118 cmp r2, #0 */
/* @0x2dd11c beq 0x2dd144 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x294> */
/* @0x2dd120 vldr s12, [r1, #40] */
/* @0x2dd124 vsub.f32 s12, s12, s9 */
/* @0x2dd128 vldr s13, [r1, #36] */
/* @0x2dd12c vmul.f32 s14, s14, s12 */
/* @0x2dd130 vsub.f32 s13, s13, s10 */
/* @0x2dd134 vmla.f32 s14, s15, s13 */
/* @0x2dd138 vcmpe.f32 s14, #0 */
/* @0x2dd13c vmrs APSR_nzcv, fpscr */
/* @0x2dd140 bgt 0x2dd054 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x1a4> */
/* @0x2dd144 add r3, r3, #12 */
/* @0x2dd148 mov r2, #0 */
/* @0x2dd14c mov r1, #0 */
/* @0x2dd150 mov r12, #1 */
/* @0x2dd154 vstr s10, [r4, #48] */
/* @0x2dd158 vstr s9, [r4, #52] */
/* @0x2dd15c strb r12, [r4, #0x10] */
/* @0x2dd160 strb r2, [r4, #0x11] */
/* @0x2dd164 strb r2, [r4, #0x12] */
/* @0x2dd168 str r1, [r4, #0x28] */
/* @0x2dd16c strb r2, [r4, #0x13] */
/* @0x2dd170 str r1, [r4, #0x2c] */
/* @0x2dd174 ldm r3, {r0, r1} */
/* @0x2dd178 str r12, [r4, #0x3c] */
/* @0x2dd17c str r2, [r4, #0x38] */
/* @0x2dd180 stm r4, {r0, r1} */
/* @0x2dd184 b 0x2dd054 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x1a4> */
/* @0x2dd188 vmov r0, s4 */
/* @0x2dd18c str r3, [sp, #0x4] */
/* @0x2dd190 bl 0xb6700 <sqrtf@plt> */
/* @0x2dd194 ldr r3, [sp, #0x4] */
/* @0x2dd198 vmov s15, r0 */
/* @0x2dd19c b 0x2dcffc <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x14c> */
/* @0x2dd1a0 strlo r0, [r0], #-0 */

/* ── FUNC 0x2dd1a4 · b2EPCollider::ComputeEdgeSeparation() · size=128 · insn=32 */
/* @0x2dd1a4 ldr r12, [r1, #0x80] */
/* @0x2dd1a8 mov r2, #1 */
/* @0x2dd1ac ldrb r3, [r1, #0xf8] */
/* @0x2dd1b0 vldr s14, [pc, #104] */
/* @0x2dd1b4 cmp r12, #0 */
/* @0x2dd1b8 str r2, [r0] */
/* @0x2dd1bc eor r3, r3, r2 */
/* @0x2dd1c0 vstr s14, [r0, #8] */
/* @0x2dd1c4 str r3, [r0, #0x4] */
/* @0x2dd1c8 bxle lr */
/* @0x2dd1cc mov r3, r1 */
/* @0x2dd1d0 mov r2, #0 */
/* @0x2dd1d4 vldr s9, [r1, #164] */
/* @0x2dd1d8 vldr s10, [r1, #168] */
/* @0x2dd1dc vldr s11, [r1, #212] */
/* @0x2dd1e0 vldr s12, [r1, #216] */
/* @0x2dd1e4 vldr s15, [r3, #4] */
/* @0x2dd1e8 vsub.f32 s15, s15, s10 */
/* @0x2dd1ec vldr s13, [r3] */
/* @0x2dd1f0 add r2, r2, #1 */
/* @0x2dd1f4 add r3, r3, #8 */
/* @0x2dd1f8 vmul.f32 s15, s15, s12 */
/* @0x2dd1fc vsub.f32 s13, s13, s9 */
/* @0x2dd200 vmla.f32 s15, s13, s11 */
/* @0x2dd204 vcmpe.f32 s15, s14 */
/* @0x2dd208 vmrs APSR_nzcv, fpscr */
/* @0x2dd20c vmovmi.f32 s14, s15 */
/* @0x2dd210 cmp r2, r12 */
/* @0x2dd214 bne 0x2dd1e4 <_ZN12b2EPCollider21ComputeEdgeSeparationEv+0x40> */
/* @0x2dd218 vstr s14, [r0, #8] */
/* @0x2dd21c bx lr */
/* @0x2dd220 svcvc #0x7fffff */

/* ── FUNC 0x2dd224 · b2EPCollider::ComputePolygonSeparation() · size=316 · insn=79 */
/* @0x2dd224 ldr r12, [r1, #0x80] */
/* @0x2dd228 vldr s8, [r1, #216] */
/* @0x2dd22c push {r4, r5} */
/* @0x2dd230 vldr s0, [pc, #288] */
/* @0x2dd234 mov r4, #0 */
/* @0x2dd238 vstr s0, [r0, #8] */
/* @0x2dd23c cmp r12, r4 */
/* @0x2dd240 mvn r5, #0 */
/* @0x2dd244 vneg.f32 s2, s8 */
/* @0x2dd248 str r4, [r0] */
/* @0x2dd24c str r5, [r0, #0x4] */
/* @0x2dd250 vldr s10, [r1, #212] */
/* @0x2dd254 ble 0x2dd340 <_ZN12b2EPCollider24ComputePolygonSeparationEv+0x11c> */
/* @0x2dd258 add r3, r1, #64 */
/* @0x2dd25c mov r2, r4 */
/* @0x2dd260 vldr s3, [r1, #244] */
/* @0x2dd264 vldr s4, [r1, #164] */
/* @0x2dd268 vldr s5, [r1, #168] */
/* @0x2dd26c vldr s6, [r1, #172] */
/* @0x2dd270 vldr s7, [r1, #176] */
/* @0x2dd274 vldr s1, [pc, #224] */
/* @0x2dd278 b 0x2dd2e0 <_ZN12b2EPCollider24ComputePolygonSeparationEv+0xbc> */
/* @0x2dd27c vmul.f32 s11, s10, s12 */
/* @0x2dd280 vmla.f32 s11, s2, s13 */
/* @0x2dd284 vcmpe.f32 s11, #0 */
/* @0x2dd288 vmrs APSR_nzcv, fpscr */
/* @0x2dd28c vldrge s14, [r1, #240] */
/* @0x2dd290 vldrlt s14, [r1, #232] */
/* @0x2dd294 vsubge.f32 s12, s12, s14 */
/* @0x2dd298 vldrge s14, [r1, #236] */
/* @0x2dd29c vsublt.f32 s12, s12, s14 */
/* @0x2dd2a0 vldrlt s14, [r1, #228] */
/* @0x2dd2a4 vmul.f32 s12, s8, s12 */
/* @0x2dd2a8 vsub.f32 s13, s13, s14 */
/* @0x2dd2ac vmla.f32 s12, s10, s13 */
/* @0x2dd2b0 vcmpe.f32 s12, s1 */
/* @0x2dd2b4 vmrs APSR_nzcv, fpscr */
/* @0x2dd2b8 bmi 0x2dd2d0 <_ZN12b2EPCollider24ComputePolygonSeparationEv+0xac> */
/* @0x2dd2bc vcmpe.f32 s0, s15 */
/* @0x2dd2c0 vmrs APSR_nzcv, fpscr */
/* @0x2dd2c4 vmovmi.f32 s0, s15 */
/* @0x2dd2c8 movmi r4, #2 */
/* @0x2dd2cc movmi r5, r2 */
/* @0x2dd2d0 add r2, r2, #1 */
/* @0x2dd2d4 add r3, r3, #8 */
/* @0x2dd2d8 cmp r2, r12 */
/* @0x2dd2dc beq 0x2dd348 <_ZN12b2EPCollider24ComputePolygonSeparationEv+0x124> */
/* @0x2dd2e0 vldr s15, [r3, #-60] */
/* @0x2dd2e4 vsub.f32 s14, s15, s5 */
/* @0x2dd2e8 vldr s12, [r3, #4] */
/* @0x2dd2ec vldr s11, [r3, #-64] */
/* @0x2dd2f0 vldr s13, [r3] */
/* @0x2dd2f4 vsub.f32 s15, s15, s7 */
/* @0x2dd2f8 vneg.f32 s12, s12 */
/* @0x2dd2fc vmul.f32 s14, s12, s14 */
/* @0x2dd300 vmul.f32 s15, s12, s15 */
/* @0x2dd304 vsub.f32 s9, s11, s4 */
/* @0x2dd308 vsub.f32 s11, s11, s6 */
/* @0x2dd30c vneg.f32 s13, s13 */
/* @0x2dd310 vmla.f32 s14, s13, s9 */
/* @0x2dd314 vmla.f32 s15, s13, s11 */
/* @0x2dd318 vcmpe.f32 s14, s15 */
/* @0x2dd31c vmrs APSR_nzcv, fpscr */
/* @0x2dd320 vmovmi.f32 s15, s14 */
/* @0x2dd324 vcmpe.f32 s15, s3 */
/* @0x2dd328 vmrs APSR_nzcv, fpscr */
/* @0x2dd32c ble 0x2dd27c <_ZN12b2EPCollider24ComputePolygonSeparationEv+0x58> */
/* @0x2dd330 mov r3, #2 */
/* @0x2dd334 str r2, [r0, #0x4] */
/* @0x2dd338 vstr s15, [r0, #8] */
/* @0x2dd33c str r3, [r0] */
/* @0x2dd340 pop {r4, r5} */
/* @0x2dd344 bx lr */
/* @0x2dd348 stm r0, {r4, r5} */
/* @0x2dd34c vstr s0, [r0, #8] */
/* @0x2dd350 pop {r4, r5} */
/* @0x2dd354 bx lr */
/* @0x2dd358 .word 0xff7fffff */
/* @0x2dd35c vstrlt s30, [lr, #-216] */

/* ── FUNC 0x2dd360 · b2EPCollider::Collide(b2Manifold*, b2EdgeShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&) · size=3420 · insn=855 */
/* @0x2dd360 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2dd364 vpush {d8, d9, d10} */
/* @0x2dd368 sub sp, sp, #164 */
/* @0x2dd36c vldr s15, [r3, #4] */
/* @0x2dd370 vldr s10, [r3, #8] */
/* @0x2dd374 vldr s11, [r3, #12] */
/* @0x2dd378 ldr r12, [sp, #0xe4] */
/* @0x2dd37c vldr s13, [r12, #4] */
/* @0x2dd380 vsub.f32 s13, s13, s15 */
/* @0x2dd384 vldr s9, [r12, #12] */
/* @0x2dd388 vldr s7, [r12, #8] */
/* @0x2dd38c vldr s6, [r12] */
/* @0x2dd390 vldr s8, [r3] */
/* @0x2dd394 add r3, r2, #28 */
/* @0x2dd398 mov r4, r0 */
/* @0x2dd39c ldr r8, [sp, #0xe0] */
/* @0x2dd3a0 add r10, r0, #156 */
/* @0x2dd3a4 mov r7, r1 */
/* @0x2dd3a8 ldm r3, {r0, r1} */
/* @0x2dd3ac add r9, r2, #12 */
/* @0x2dd3b0 add r5, r4, #164 */
/* @0x2dd3b4 add lr, r2, #20 */
/* @0x2dd3b8 add r6, r4, #172 */
/* @0x2dd3bc add r12, r2, #36 */
/* @0x2dd3c0 add r3, r4, #180 */
/* @0x2dd3c4 vmul.f32 s12, s10, s13 */
/* @0x2dd3c8 vmul.f32 s15, s10, s9 */
/* @0x2dd3cc vmul.f32 s13, s11, s13 */
/* @0x2dd3d0 vmul.f32 s14, s7, s10 */
/* @0x2dd3d4 vsub.f32 s8, s6, s8 */
/* @0x2dd3d8 vmla.f32 s14, s11, s9 */
/* @0x2dd3dc vnmls.f32 s15, s11, s7 */
/* @0x2dd3e0 vstr s14, [r4, #144] */
/* @0x2dd3e4 vmla.f32 s12, s11, s8 */
/* @0x2dd3e8 vstr s15, [r4, #140] */
/* @0x2dd3ec vmls.f32 s13, s10, s8 */
/* @0x2dd3f0 vstr s12, [r4, #132] */
/* @0x2dd3f4 vstr s13, [r4, #136] */
/* @0x2dd3f8 vldr s11, [r8, #16] */
/* @0x2dd3fc vmul.f32 s10, s11, s15 */
/* @0x2dd400 vldr s9, [r8, #12] */
/* @0x2dd404 vmul.f32 s11, s11, s14 */
/* @0x2dd408 vnmls.f32 s10, s9, s14 */
/* @0x2dd40c vmla.f32 s11, s9, s15 */
/* @0x2dd410 vadd.f32 s12, s10, s12 */
/* @0x2dd414 vadd.f32 s13, s11, s13 */
/* @0x2dd418 vstr s12, [r4, #148] */
/* @0x2dd41c vstr s13, [r4, #152] */
/* @0x2dd420 stm r10, {r0, r1} */
/* @0x2dd424 ldm r9, {r0, r1} */
/* @0x2dd428 stm r5, {r0, r1} */
/* @0x2dd42c ldm lr, {r0, r1} */
/* @0x2dd430 stm r6, {r0, r1} */
/* @0x2dd434 ldm r12, {r0, r1} */
/* @0x2dd438 stm r3, {r0, r1} */
/* @0x2dd43c vldr s16, [r4, #176] */
/* @0x2dd440 vldr s12, [r4, #168] */
/* @0x2dd444 vsub.f32 s16, s16, s12 */
/* @0x2dd448 vldr s17, [r4, #172] */
/* @0x2dd44c vldr s13, [r4, #164] */
/* @0x2dd450 ldrb r9, [r2, #0x2c] */
/* @0x2dd454 ldrb r10, [r2, #0x2d] */
/* @0x2dd458 vmul.f32 s14, s16, s16 */
/* @0x2dd45c vsub.f32 s17, s17, s13 */
/* @0x2dd460 vmla.f32 s14, s17, s17 */
/* @0x2dd464 vsqrt.f32 s15, s14 */
/* @0x2dd468 vcmp.f32 s15, s15 */
/* @0x2dd46c vmrs APSR_nzcv, fpscr */
/* @0x2dd470 bne 0x2de0a4 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xd44> */
/* @0x2dd474 vldr s14, [pc, #976] */
/* @0x2dd478 vcmpe.f32 s15, s14 */
/* @0x2dd47c vldr s11, [r4, #152] */
/* @0x2dd480 vmrs APSR_nzcv, fpscr */
/* @0x2dd484 vmovpl.f32 s14, #1.000000e+00 */
/* @0x2dd488 vdivpl.f32 s15, s14, s15 */
/* @0x2dd48c vldr s14, [r4, #148] */
/* @0x2dd490 vmulpl.f32 s17, s17, s15 */
/* @0x2dd494 vsub.f32 s18, s11, s12 */
/* @0x2dd498 vmulpl.f32 s16, s16, s15 */
/* @0x2dd49c cmp r9, #0 */
/* @0x2dd4a0 vneg.f32 s15, s17 */
/* @0x2dd4a4 vstr s16, [r4, #196] */
/* @0x2dd4a8 vmul.f32 s18, s15, s18 */
/* @0x2dd4ac vstr s15, [r4, #200] */
/* @0x2dd4b0 vsub.f32 s15, s14, s13 */
/* @0x2dd4b4 vmla.f32 s18, s15, s16 */
/* @0x2dd4b8 bne 0x2dd524 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x1c4> */
/* @0x2dd4bc cmp r10, #0 */
/* @0x2dd4c0 mov r11, r9 */
/* @0x2dd4c4 vldr s19, [pc, #900] */
/* @0x2dd4c8 bne 0x2dd5a4 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x244> */
/* @0x2dd4cc cmp r9, #0 */
/* @0x2dd4d0 bne 0x2dd7b4 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x454> */
/* @0x2dd4d4 vcmpe.f32 s18, #0 */
/* @0x2dd4d8 vmrs APSR_nzcv, fpscr */
/* @0x2dd4dc movlt r3, #0 */
/* @0x2dd4e0 movge r3, #1 */
/* @0x2dd4e4 cmp r3, #0 */
/* @0x2dd4e8 strb r3, [r4, #0xf8] */
/* @0x2dd4ec beq 0x2ddba0 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x840> */
/* @0x2dd4f0 add r2, r4, #196 */
/* @0x2dd4f4 add r3, r4, #212 */
/* @0x2dd4f8 ldm r2, {r0, r1} */
/* @0x2dd4fc stm r3, {r0, r1} */
/* @0x2dd500 vldr s14, [r4, #196] */
/* @0x2dd504 vldr s15, [r4, #200] */
/* @0x2dd508 vneg.f32 s14, s14 */
/* @0x2dd50c vneg.f32 s15, s15 */
/* @0x2dd510 vstr s14, [r4, #228] */
/* @0x2dd514 vstr s14, [r4, #236] */
/* @0x2dd518 vstr s15, [r4, #232] */
/* @0x2dd51c vstr s15, [r4, #240] */
/* @0x2dd520 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c> */
/* @0x2dd524 vldr s19, [r4, #160] */
/* @0x2dd528 vsub.f32 s20, s12, s19 */
/* @0x2dd52c vldr s10, [r4, #156] */
/* @0x2dd530 vmul.f32 s12, s20, s20 */
/* @0x2dd534 vsub.f32 s21, s13, s10 */
/* @0x2dd538 vmla.f32 s12, s21, s21 */
/* @0x2dd53c vsqrt.f32 s15, s12 */
/* @0x2dd540 vcmp.f32 s15, s15 */
/* @0x2dd544 vmrs APSR_nzcv, fpscr */
/* @0x2dd548 bne 0x2ddf1c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xbbc> */
/* @0x2dd54c vldr s13, [pc, #760] */
/* @0x2dd550 vcmpe.f32 s15, s13 */
/* @0x2dd554 vmrs APSR_nzcv, fpscr */
/* @0x2dd558 vmovpl.f32 s13, #1.000000e+00 */
/* @0x2dd55c vdivpl.f32 s15, s13, s15 */
/* @0x2dd560 vmulpl.f32 s20, s20, s15 */
/* @0x2dd564 vmulpl.f32 s21, s21, s15 */
/* @0x2dd568 vstr s20, [r4, #188] */
/* @0x2dd56c vmul.f32 s15, s20, s17 */
/* @0x2dd570 vnmls.f32 s15, s21, s16 */
/* @0x2dd574 vsub.f32 s19, s11, s19 */
/* @0x2dd578 vneg.f32 s21, s21 */
/* @0x2dd57c vmul.f32 s19, s21, s19 */
/* @0x2dd580 vstr s21, [r4, #192] */
/* @0x2dd584 vsub.f32 s10, s14, s10 */
/* @0x2dd588 vcmpe.f32 s15, #0 */
/* @0x2dd58c vmrs APSR_nzcv, fpscr */
/* @0x2dd590 movlt r11, #0 */
/* @0x2dd594 movge r11, #1 */
/* @0x2dd598 cmp r10, #0 */
/* @0x2dd59c vmla.f32 s19, s10, s20 */
/* @0x2dd5a0 beq 0x2dd4cc <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x16c> */
/* @0x2dd5a4 vldr s20, [r4, #184] */
/* @0x2dd5a8 vldr s10, [r4, #176] */
/* @0x2dd5ac vldr s21, [r4, #180] */
/* @0x2dd5b0 vldr s12, [r4, #172] */
/* @0x2dd5b4 vsub.f32 s20, s20, s10 */
/* @0x2dd5b8 vmul.f32 s13, s20, s20 */
/* @0x2dd5bc vsub.f32 s21, s21, s12 */
/* @0x2dd5c0 vmla.f32 s13, s21, s21 */
/* @0x2dd5c4 vsqrt.f32 s15, s13 */
/* @0x2dd5c8 vcmp.f32 s15, s15 */
/* @0x2dd5cc vmrs APSR_nzcv, fpscr */
/* @0x2dd5d0 bne 0x2de084 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xd24> */
/* @0x2dd5d4 vldr s13, [pc, #624] */
/* @0x2dd5d8 vcmpe.f32 s15, s13 */
/* @0x2dd5dc vmrs APSR_nzcv, fpscr */
/* @0x2dd5e0 vmovpl.f32 s13, #1.000000e+00 */
/* @0x2dd5e4 vdivpl.f32 s15, s13, s15 */
/* @0x2dd5e8 vmulpl.f32 s21, s21, s15 */
/* @0x2dd5ec vmulpl.f32 s20, s20, s15 */
/* @0x2dd5f0 vmul.f32 s16, s21, s16 */
/* @0x2dd5f4 vstr s20, [r4, #204] */
/* @0x2dd5f8 vnmls.f32 s16, s20, s17 */
/* @0x2dd5fc vsub.f32 s11, s11, s10 */
/* @0x2dd600 vneg.f32 s15, s21 */
/* @0x2dd604 vmul.f32 s11, s15, s11 */
/* @0x2dd608 vstr s15, [r4, #208] */
/* @0x2dd60c vsub.f32 s14, s14, s12 */
/* @0x2dd610 vcmpe.f32 s16, #0 */
/* @0x2dd614 vmrs APSR_nzcv, fpscr */
/* @0x2dd618 movle r3, #0 */
/* @0x2dd61c movgt r3, #1 */
/* @0x2dd620 cmp r9, #0 */
/* @0x2dd624 vmla.f32 s11, s14, s20 */
/* @0x2dd628 beq 0x2ddf3c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xbdc> */
/* @0x2dd62c tst r3, r11 */
/* @0x2dd630 beq 0x2dd764 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x404> */
/* @0x2dd634 vcmpe.f32 s19, #0 */
/* @0x2dd638 vmrs APSR_nzcv, fpscr */
/* @0x2dd63c blt 0x2dd8b0 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x550> */
/* @0x2dd640 add r3, r4, #196 */
/* @0x2dd644 add r12, r4, #212 */
/* @0x2dd648 add r9, r4, #188 */
/* @0x2dd64c mov lr, #1 */
/* @0x2dd650 ldm r3, {r0, r1} */
/* @0x2dd654 add r2, r4, #228 */
/* @0x2dd658 strb lr, [r4, #0xf8] */
/* @0x2dd65c add lr, r4, #204 */
/* @0x2dd660 add r3, r4, #236 */
/* @0x2dd664 stm r12, {r0, r1} */
/* @0x2dd668 ldm r9, {r0, r1} */
/* @0x2dd66c stm r2, {r0, r1} */
/* @0x2dd670 mov r2, lr */
/* @0x2dd674 ldm lr, {r0, r1} */
/* @0x2dd678 stm r3, {r0, r1} */
/* @0x2dd67c ldr r1, [r8, #0x94] */
/* @0x2dd680 cmp r1, #0 */
/* @0x2dd684 str r1, [r4, #0x80] */
/* @0x2dd688 addgt r3, r8, #84 */
/* @0x2dd68c addgt r12, r4, #64 */
/* @0x2dd690 addgt r0, r4, #68 */
/* @0x2dd694 movgt r2, #0 */
/* @0x2dd698 ble 0x2dd714 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x3b4> */
/* @0x2dd69c vldr s13, [r4, #140] */
/* @0x2dd6a0 vldr s15, [r3, #-60] */
/* @0x2dd6a4 vldr s11, [r4, #144] */
/* @0x2dd6a8 vmul.f32 s14, s13, s15 */
/* @0x2dd6ac vldr s12, [r3, #-64] */
/* @0x2dd6b0 vldr s9, [r4, #132] */
/* @0x2dd6b4 vldr s10, [r4, #136] */
/* @0x2dd6b8 add r2, r2, #1 */
/* @0x2dd6bc cmp r2, r1 */
/* @0x2dd6c0 add r3, r3, #8 */
/* @0x2dd6c4 vmul.f32 s15, s11, s15 */
/* @0x2dd6c8 vnmls.f32 s14, s11, s12 */
/* @0x2dd6cc vmla.f32 s15, s12, s13 */
/* @0x2dd6d0 vadd.f32 s14, s14, s9 */
/* @0x2dd6d4 vadd.f32 s15, s15, s10 */
/* @0x2dd6d8 vstr s14, [r12, #-64] */
/* @0x2dd6dc vstr s15, [r0, #-64] */
/* @0x2dd6e0 vldr s15, [r3, #-4] */
/* @0x2dd6e4 vldr s13, [r4, #140] */
/* @0x2dd6e8 vmul.f32 s14, s13, s15 */
/* @0x2dd6ec vldr s12, [r3, #-8] */
/* @0x2dd6f0 vldr s11, [r4, #144] */
/* @0x2dd6f4 vnmls.f32 s14, s11, s12 */
/* @0x2dd6f8 vmul.f32 s15, s11, s15 */
/* @0x2dd6fc vmov lr, s14 */
/* @0x2dd700 vmla.f32 s15, s12, s13 */
/* @0x2dd704 str lr, [r12], #8 */
/* @0x2dd708 vmov lr, s15 */
/* @0x2dd70c str lr, [r0], #8 */
/* @0x2dd710 bne 0x2dd69c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x33c> */
/* @0x2dd714 mov r3, #0 */
/* @0x2dd718 movw r2, #0xd70a */
/* @0x2dd71c add r0, sp, #8 */
/* @0x2dd720 movt r2, #0x3ca3 */
/* @0x2dd724 mov r1, r4 */
/* @0x2dd728 str r2, [r4, #0xf4] */
/* @0x2dd72c str r3, [r7, #0x3c] */
/* @0x2dd730 bl 0x2dd1a4 <_ZN12b2EPCollider21ComputeEdgeSeparationEv> */
/* @0x2dd734 ldr r9, [sp, #0x8] */
/* @0x2dd738 ldr r10, [sp, #0xc] */
/* @0x2dd73c vldr s16, [sp, #16] */
/* @0x2dd740 cmp r9, #0 */
/* @0x2dd744 beq 0x2dd758 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x3f8> */
/* @0x2dd748 vldr s15, [r4, #244] */
/* @0x2dd74c vcmpe.f32 s16, s15 */
/* @0x2dd750 vmrs APSR_nzcv, fpscr */
/* @0x2dd754 ble 0x2dd8fc <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x59c> */
/* @0x2dd758 add sp, sp, #164 */
/* @0x2dd75c vpop {d8, d9, d10} */
/* @0x2dd760 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2dd764 cmp r11, #0 */
/* @0x2dd768 beq 0x2dd85c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x4fc> */
/* @0x2dd76c vcmpe.f32 s19, #0 */
/* @0x2dd770 vmrs APSR_nzcv, fpscr */
/* @0x2dd774 blt 0x2ddccc <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x96c> */
/* @0x2dd778 add r3, r4, #196 */
/* @0x2dd77c add r12, r4, #212 */
/* @0x2dd780 add r9, r4, #188 */
/* @0x2dd784 mov lr, #1 */
/* @0x2dd788 ldm r3, {r0, r1} */
/* @0x2dd78c add r2, r4, #228 */
/* @0x2dd790 strb lr, [r4, #0xf8] */
/* @0x2dd794 add lr, r4, #236 */
/* @0x2dd798 stm r12, {r0, r1} */
/* @0x2dd79c ldm r9, {r0, r1} */
/* @0x2dd7a0 stm r2, {r0, r1} */
/* @0x2dd7a4 ldm r3, {r0, r1} */
/* @0x2dd7a8 mov r3, lr */
/* @0x2dd7ac stm lr, {r0, r1} */
/* @0x2dd7b0 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c> */
/* @0x2dd7b4 cmp r11, #0 */
/* @0x2dd7b8 vcmpe.f32 s19, #0 */
/* @0x2dd7bc bne 0x2dd818 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x4b8> */
/* @0x2dd7c0 vmrs APSR_nzcv, fpscr */
/* @0x2dd7c4 blt 0x2ddbdc <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x87c> */
/* @0x2dd7c8 vcmpe.f32 s18, #0 */
/* @0x2dd7cc vmrs APSR_nzcv, fpscr */
/* @0x2dd7d0 blt 0x2ddbdc <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x87c> */
/* @0x2dd7d4 add r3, r4, #196 */
/* @0x2dd7d8 mov r1, #1 */
/* @0x2dd7dc strb r1, [r4, #0xf8] */
/* @0x2dd7e0 add r2, r4, #212 */
/* @0x2dd7e4 ldm r3, {r0, r1} */
/* @0x2dd7e8 add r12, r4, #228 */
/* @0x2dd7ec stm r2, {r0, r1} */
/* @0x2dd7f0 ldm r3, {r0, r1} */
/* @0x2dd7f4 mov r3, r12 */
/* @0x2dd7f8 stm r3, {r0, r1} */
/* @0x2dd7fc vldr s14, [r4, #200] */
/* @0x2dd800 vldr s15, [r4, #196] */
/* @0x2dd804 vneg.f32 s14, s14 */
/* @0x2dd808 vneg.f32 s15, s15 */
/* @0x2dd80c vstr s14, [r4, #240] */
/* @0x2dd810 vstr s15, [r4, #236] */
/* @0x2dd814 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c> */
/* @0x2dd818 vmrs APSR_nzcv, fpscr */
/* @0x2dd81c blt 0x2ddd1c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x9bc> */
/* @0x2dd820 add r3, r4, #196 */
/* @0x2dd824 add r2, r4, #212 */
/* @0x2dd828 add r12, r4, #188 */
/* @0x2dd82c mov lr, #1 */
/* @0x2dd830 ldm r3, {r0, r1} */
/* @0x2dd834 add r3, r4, #228 */
/* @0x2dd838 strb lr, [r4, #0xf8] */
/* @0x2dd83c stm r2, {r0, r1} */
/* @0x2dd840 mov r2, r12 */
/* @0x2dd844 ldm r12, {r0, r1} */
/* @0x2dd848 b 0x2dd7f8 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x498> */
/* @0x2dd84c strlo r0, [r0], #-0 */
/* @0x2dd850 andeq r0, r0, r0 */
/* @0x2dd854 svclo #0x7ae148 */
/* @0x2dd858 blo 0xfe3a221c <b2_toiTime+0xfffffffffdc48d78> */
/* @0x2dd85c cmp r3, #0 */
/* @0x2dd860 beq 0x2ddb44 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x7e4> */
/* @0x2dd864 vcmpe.f32 s11, #0 */
/* @0x2dd868 vmrs APSR_nzcv, fpscr */
/* @0x2dd86c blt 0x2ddc70 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x910> */
/* @0x2dd870 add r3, r4, #196 */
/* @0x2dd874 add r12, r4, #212 */
/* @0x2dd878 mov r2, #1 */
/* @0x2dd87c strb r2, [r4, #0xf8] */
/* @0x2dd880 ldm r3, {r0, r1} */
/* @0x2dd884 add r2, r4, #228 */
/* @0x2dd888 add r9, r4, #204 */
/* @0x2dd88c add lr, r4, #236 */
/* @0x2dd890 stm r12, {r0, r1} */
/* @0x2dd894 ldm r3, {r0, r1} */
/* @0x2dd898 mov r3, lr */
/* @0x2dd89c stm r2, {r0, r1} */
/* @0x2dd8a0 mov r2, r9 */
/* @0x2dd8a4 ldm r9, {r0, r1} */
/* @0x2dd8a8 stm lr, {r0, r1} */
/* @0x2dd8ac b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c> */
/* @0x2dd8b0 vcmpe.f32 s18, #0 */
/* @0x2dd8b4 vmrs APSR_nzcv, fpscr */
/* @0x2dd8b8 bge 0x2dd640 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x2e0> */
/* @0x2dd8bc vcmpe.f32 s11, #0 */
/* @0x2dd8c0 vmrs APSR_nzcv, fpscr */
/* @0x2dd8c4 bge 0x2dd640 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x2e0> */
/* @0x2dd8c8 vldr s14, [r4, #196] */
/* @0x2dd8cc vldr s15, [r4, #200] */
/* @0x2dd8d0 vneg.f32 s14, s14 */
/* @0x2dd8d4 mov r3, #0 */
/* @0x2dd8d8 strb r3, [r4, #0xf8] */
/* @0x2dd8dc vneg.f32 s15, s15 */
/* @0x2dd8e0 vstr s14, [r4, #212] */
/* @0x2dd8e4 vstr s14, [r4, #228] */
/* @0x2dd8e8 vstr s14, [r4, #236] */
/* @0x2dd8ec vstr s15, [r4, #216] */
/* @0x2dd8f0 vstr s15, [r4, #232] */
/* @0x2dd8f4 vstr s15, [r4, #240] */
/* @0x2dd8f8 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c> */
/* @0x2dd8fc add r0, sp, #20 */
/* @0x2dd900 mov r1, r4 */
/* @0x2dd904 bl 0x2dd224 <_ZN12b2EPCollider24ComputePolygonSeparationEv> */
/* @0x2dd908 ldr r3, [sp, #0x14] */
/* @0x2dd90c vldr s15, [sp, #28] */
/* @0x2dd910 cmp r3, #0 */
/* @0x2dd914 beq 0x2dd944 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x5e4> */
/* @0x2dd918 vldr s14, [r4, #244] */
/* @0x2dd91c vcmpe.f32 s15, s14 */
/* @0x2dd920 vmrs APSR_nzcv, fpscr */
/* @0x2dd924 bgt 0x2dd758 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x3f8> */
/* @0x2dd928 vldr s13, [pc, #-220] */
/* @0x2dd92c vldr s14, [pc, #-220] */
/* @0x2dd930 vmla.f32 s14, s16, s13 */
/* @0x2dd934 vcmpe.f32 s15, s14 */
/* @0x2dd938 vmrs APSR_nzcv, fpscr */
/* @0x2dd93c ldrgt r10, [sp, #0x18] */
/* @0x2dd940 movgt r9, r3 */
/* @0x2dd944 cmp r9, #1 */
/* @0x2dd948 beq 0x2ddd60 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xa00> */
/* @0x2dd94c ldr r2, [r4, #0x80] */
/* @0x2dd950 add lr, r10, #1 */
/* @0x2dd954 ldm r5, {r0, r1} */
/* @0x2dd958 add r3, sp, #32 */
/* @0x2dd95c cmp lr, r2 */
/* @0x2dd960 add r12, r4, r10, lsl #3 */
/* @0x2dd964 add r11, sp, #112 */
/* @0x2dd968 add r5, r10, #8 */
/* @0x2dd96c stm r3, {r0, r1} */
/* @0x2dd970 movge lr, #0 */
/* @0x2dd974 ldm r6, {r0, r1} */
/* @0x2dd978 add r2, r4, lr, lsl #3 */
/* @0x2dd97c str lr, [sp, #0x6c] */
/* @0x2dd980 add lr, sp, #44 */
/* @0x2dd984 add r5, r4, r5, lsl #3 */
/* @0x2dd988 add r6, sp, #120 */
/* @0x2dd98c stm lr, {r0, r1} */
/* @0x2dd990 mov lr, #2 */
/* @0x2dd994 ldm r12, {r0, r1} */
/* @0x2dd998 mov r12, r10 */
/* @0x2dd99c str r10, [sp, #0x68] */
/* @0x2dd9a0 uxtb r10, r10 */
/* @0x2dd9a4 strb r10, [sp, #0x29] */
/* @0x2dd9a8 stm r11, {r0, r1} */
/* @0x2dd9ac ldm r2, {r0, r1} */
/* @0x2dd9b0 mov r2, #0 */
/* @0x2dd9b4 str lr, [r7, #0x38] */
/* @0x2dd9b8 mov lr, #1 */
/* @0x2dd9bc strb r10, [sp, #0x35] */
/* @0x2dd9c0 stm r6, {r0, r1} */
/* @0x2dd9c4 ldm r5, {r0, r1} */
/* @0x2dd9c8 add r5, sp, #128 */
/* @0x2dd9cc strb r2, [sp, #0x28] */
/* @0x2dd9d0 strb r2, [sp, #0x2a] */
/* @0x2dd9d4 stm r5, {r0, r1} */
/* @0x2dd9d8 vldr s13, [sp, #132] */
/* @0x2dd9dc vldr s14, [sp, #128] */
/* @0x2dd9e0 strb r2, [sp, #0x34] */
/* @0x2dd9e4 strb r2, [sp, #0x36] */
/* @0x2dd9e8 strb lr, [sp, #0x2b] */
/* @0x2dd9ec strb lr, [sp, #0x37] */
/* @0x2dd9f0 vneg.f32 s12, s14 */
/* @0x2dd9f4 vldr s15, [sp, #116] */
/* @0x2dd9f8 vldr s9, [sp, #124] */
/* @0x2dd9fc vstr s14, [sp, #152] */
/* @0x2dda00 vldr s10, [sp, #112] */
/* @0x2dda04 vldr s11, [sp, #120] */
/* @0x2dda08 add r5, sp, #56 */
/* @0x2dda0c mov r1, r3 */
/* @0x2dda10 vmul.f32 s15, s12, s15 */
/* @0x2dda14 vstr s12, [sp, #140] */
/* @0x2dda18 mov r0, r5 */
/* @0x2dda1c str r12, [sp] */
/* @0x2dda20 add r2, sp, #136 */
/* @0x2dda24 vstr s13, [sp, #136] */
/* @0x2dda28 vmul.f32 s14, s14, s9 */
/* @0x2dda2c vneg.f32 s12, s13 */
/* @0x2dda30 vmla.f32 s15, s13, s10 */
/* @0x2dda34 vstr s12, [sp, #148] */
/* @0x2dda38 vmla.f32 s14, s12, s11 */
/* @0x2dda3c vstr s15, [sp, #144] */
/* @0x2dda40 vmov r3, s15 */
/* @0x2dda44 vstr s14, [sp, #156] */
/* @0x2dda48 bl 0x2c39c4 <_Z19b2ClipSegmentToLineP12b2ClipVertexPKS_RK6b2Vec2fi> */
/* @0x2dda4c cmp r0, #1 */
/* @0x2dda50 ble 0x2dd758 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x3f8> */
/* @0x2dda54 ldr r12, [sp, #0x6c] */
/* @0x2dda58 add r6, sp, #80 */
/* @0x2dda5c ldr r3, [sp, #0x9c] */
/* @0x2dda60 mov r1, r5 */
/* @0x2dda64 mov r0, r6 */
/* @0x2dda68 add r2, sp, #148 */
/* @0x2dda6c str r12, [sp] */
/* @0x2dda70 bl 0x2c39c4 <_Z19b2ClipSegmentToLineP12b2ClipVertexPKS_RK6b2Vec2fi> */
/* @0x2dda74 cmp r0, #1 */
/* @0x2dda78 ble 0x2dd758 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x3f8> */
/* @0x2dda7c cmp r9, #1 */
/* @0x2dda80 beq 0x2ddefc <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xb9c> */
/* @0x2dda84 ldr r2, [sp, #0x68] */
/* @0x2dda88 add r12, r7, #40 */
/* @0x2dda8c add r3, r7, #48 */
/* @0x2dda90 add r1, r8, r2, lsl #3 */
/* @0x2dda94 mov r2, r1 */
/* @0x2dda98 add r1, r1, #84 */
/* @0x2dda9c add r2, r2, #20 */
/* @0x2ddaa0 ldm r1, {r0, r1} */
/* @0x2ddaa4 stm r12, {r0, r1} */
/* @0x2ddaa8 ldm r2, {r0, r1} */
/* @0x2ddaac stm r3, {r0, r1} */
/* @0x2ddab0 add r5, sp, #104 */
/* @0x2ddab4 mov r3, r6 */
/* @0x2ddab8 mov r2, #0 */
/* @0x2ddabc vldr s7, [sp, #112] */
/* @0x2ddac0 vldr s8, [sp, #116] */
/* @0x2ddac4 vldr s9, [sp, #128] */
/* @0x2ddac8 vldr s10, [sp, #132] */
/* @0x2ddacc vldr s13, [r3, #4] */
/* @0x2ddad0 vsub.f32 s15, s13, s8 */
/* @0x2ddad4 vldr s14, [r3] */
/* @0x2ddad8 vldr s12, [r4, #244] */
/* @0x2ddadc add r12, r2, r2, lsl #2 */
/* @0x2ddae0 add r12, r7, r12, lsl #2 */
/* @0x2ddae4 vmul.f32 s15, s15, s10 */
/* @0x2ddae8 vsub.f32 s11, s14, s7 */
/* @0x2ddaec vmla.f32 s15, s11, s9 */
/* @0x2ddaf0 vcmpe.f32 s12, s15 */
/* @0x2ddaf4 vmrs APSR_nzcv, fpscr */
/* @0x2ddaf8 blt 0x2ddb30 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x7d0> */
/* @0x2ddafc cmp r9, #1 */
/* @0x2ddb00 beq 0x2ddec0 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xb60> */
/* @0x2ddb04 ldm r3, {r0, r1} */
/* @0x2ddb08 ldrb r11, [r3, #0xb] */
/* @0x2ddb0c ldrb r10, [r3, #0xa] */
/* @0x2ddb10 ldrb r8, [r3, #0x9] */
/* @0x2ddb14 ldrb r6, [r3, #0x8] */
/* @0x2ddb18 stm r12, {r0, r1} */
/* @0x2ddb1c strb r11, [r12, #0x12] */
/* @0x2ddb20 strb r10, [r12, #0x13] */
/* @0x2ddb24 strb r8, [r12, #0x10] */
/* @0x2ddb28 strb r6, [r12, #0x11] */
/* @0x2ddb2c add r2, r2, #1 */
/* @0x2ddb30 add r3, r3, #12 */
/* @0x2ddb34 cmp r3, r5 */
/* @0x2ddb38 bne 0x2ddacc <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x76c> */
/* @0x2ddb3c str r2, [r7, #0x3c] */
/* @0x2ddb40 b 0x2dd758 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x3f8> */
/* @0x2ddb44 vcmpe.f32 s19, #0 */
/* @0x2ddb48 vmrs APSR_nzcv, fpscr */
/* @0x2ddb4c blt 0x2ddc28 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x8c8> */
/* @0x2ddb50 vcmpe.f32 s18, #0 */
/* @0x2ddb54 vmrs APSR_nzcv, fpscr */
/* @0x2ddb58 blt 0x2ddc28 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x8c8> */
/* @0x2ddb5c vcmpe.f32 s11, #0 */
/* @0x2ddb60 vmrs APSR_nzcv, fpscr */
/* @0x2ddb64 blt 0x2ddc28 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x8c8> */
/* @0x2ddb68 add r3, r4, #196 */
/* @0x2ddb6c add r12, r4, #212 */
/* @0x2ddb70 mov r2, #1 */
/* @0x2ddb74 strb r2, [r4, #0xf8] */
/* @0x2ddb78 ldm r3, {r0, r1} */
/* @0x2ddb7c add r2, r4, #228 */
/* @0x2ddb80 add lr, r4, #236 */
/* @0x2ddb84 stm r12, {r0, r1} */
/* @0x2ddb88 ldm r3, {r0, r1} */
/* @0x2ddb8c stm r2, {r0, r1} */
/* @0x2ddb90 ldm r3, {r0, r1} */
/* @0x2ddb94 mov r3, lr */
/* @0x2ddb98 stm lr, {r0, r1} */
/* @0x2ddb9c b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c> */
/* @0x2ddba0 vldr s14, [r4, #200] */
/* @0x2ddba4 vldr s15, [r4, #196] */
/* @0x2ddba8 vneg.f32 s14, s14 */
/* @0x2ddbac add r3, r4, #196 */
/* @0x2ddbb0 add r2, r4, #228 */
/* @0x2ddbb4 add r12, r4, #236 */
/* @0x2ddbb8 vneg.f32 s15, s15 */
/* @0x2ddbbc vstr s14, [r4, #216] */
/* @0x2ddbc0 vstr s15, [r4, #212] */
/* @0x2ddbc4 ldm r3, {r0, r1} */
/* @0x2ddbc8 stm r2, {r0, r1} */
/* @0x2ddbcc ldm r3, {r0, r1} */
/* @0x2ddbd0 mov r3, r12 */
/* @0x2ddbd4 stm r12, {r0, r1} */
/* @0x2ddbd8 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c> */
/* @0x2ddbdc vldr s14, [r4, #200] */
/* @0x2ddbe0 vldr s15, [r4, #196] */
/* @0x2ddbe4 vneg.f32 s14, s14 */
/* @0x2ddbe8 add r2, r4, #196 */
/* @0x2ddbec mov r1, #0 */
/* @0x2ddbf0 strb r1, [r4, #0xf8] */
/* @0x2ddbf4 add r3, r4, #228 */
/* @0x2ddbf8 vneg.f32 s15, s15 */
/* @0x2ddbfc vstr s14, [r4, #216] */
/* @0x2ddc00 vstr s15, [r4, #212] */
/* @0x2ddc04 ldm r2, {r0, r1} */
/* @0x2ddc08 stm r3, {r0, r1} */
/* @0x2ddc0c vldr s14, [r4, #192] */
/* @0x2ddc10 vldr s15, [r4, #188] */
/* @0x2ddc14 vneg.f32 s14, s14 */
/* @0x2ddc18 vneg.f32 s15, s15 */
/* @0x2ddc1c vstr s14, [r4, #240] */
/* @0x2ddc20 vstr s15, [r4, #236] */
/* @0x2ddc24 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c> */
/* @0x2ddc28 vneg.f32 s20, s20 */
/* @0x2ddc2c vldr s12, [r4, #200] */
/* @0x2ddc30 vldr s13, [r4, #196] */
/* @0x2ddc34 vldr s14, [r4, #192] */
/* @0x2ddc38 vldr s15, [r4, #188] */
/* @0x2ddc3c mov r3, #0 */
/* @0x2ddc40 vstr s21, [r4, #232] */
/* @0x2ddc44 strb r3, [r4, #0xf8] */
/* @0x2ddc48 vneg.f32 s12, s12 */
/* @0x2ddc4c vstr s20, [r4, #228] */
/* @0x2ddc50 vneg.f32 s13, s13 */
/* @0x2ddc54 vstr s12, [r4, #216] */
/* @0x2ddc58 vneg.f32 s14, s14 */
/* @0x2ddc5c vstr s13, [r4, #212] */
/* @0x2ddc60 vneg.f32 s15, s15 */
/* @0x2ddc64 vstr s14, [r4, #240] */
/* @0x2ddc68 vstr s15, [r4, #236] */
/* @0x2ddc6c b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c> */
/* @0x2ddc70 vcmpe.f32 s19, #0 */
/* @0x2ddc74 vmrs APSR_nzcv, fpscr */
/* @0x2ddc78 blt 0x2ddc88 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x928> */
/* @0x2ddc7c vcmpe.f32 s18, #0 */
/* @0x2ddc80 vmrs APSR_nzcv, fpscr */
/* @0x2ddc84 bge 0x2dd870 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x510> */
/* @0x2ddc88 vldr s14, [r4, #196] */
/* @0x2ddc8c vldr s15, [r4, #200] */
/* @0x2ddc90 vneg.f32 s14, s14 */
/* @0x2ddc94 vldr s12, [r4, #192] */
/* @0x2ddc98 vldr s13, [r4, #188] */
/* @0x2ddc9c mov r3, #0 */
/* @0x2ddca0 strb r3, [r4, #0xf8] */
/* @0x2ddca4 vneg.f32 s15, s15 */
/* @0x2ddca8 vstr s14, [r4, #212] */
/* @0x2ddcac vstr s14, [r4, #228] */
/* @0x2ddcb0 vstr s15, [r4, #216] */
/* @0x2ddcb4 vneg.f32 s14, s12 */
/* @0x2ddcb8 vstr s15, [r4, #232] */
/* @0x2ddcbc vneg.f32 s15, s13 */
/* @0x2ddcc0 vstr s14, [r4, #240] */
/* @0x2ddcc4 vstr s15, [r4, #236] */
/* @0x2ddcc8 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c> */
/* @0x2ddccc vcmpe.f32 s18, #0 */
/* @0x2ddcd0 vmrs APSR_nzcv, fpscr */
/* @0x2ddcd4 blt 0x2ddce4 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x984> */
/* @0x2ddcd8 vcmpe.f32 s11, #0 */
/* @0x2ddcdc vmrs APSR_nzcv, fpscr */
/* @0x2ddce0 bge 0x2dd778 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x418> */
/* @0x2ddce4 vneg.f32 s20, s20 */
/* @0x2ddce8 vldr s14, [r4, #196] */
/* @0x2ddcec vldr s15, [r4, #200] */
/* @0x2ddcf0 mov r3, #0 */
/* @0x2ddcf4 vstr s21, [r4, #232] */
/* @0x2ddcf8 strb r3, [r4, #0xf8] */
/* @0x2ddcfc vneg.f32 s14, s14 */
/* @0x2ddd00 vstr s20, [r4, #228] */
/* @0x2ddd04 vneg.f32 s15, s15 */
/* @0x2ddd08 vstr s14, [r4, #212] */
/* @0x2ddd0c vstr s14, [r4, #236] */
/* @0x2ddd10 vstr s15, [r4, #216] */
/* @0x2ddd14 vstr s15, [r4, #240] */
/* @0x2ddd18 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c> */
/* @0x2ddd1c vcmpe.f32 s18, #0 */
/* @0x2ddd20 vmrs APSR_nzcv, fpscr */
/* @0x2ddd24 bge 0x2dd820 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x4c0> */
/* @0x2ddd28 vldr s14, [r4, #196] */
/* @0x2ddd2c vldr s15, [r4, #200] */
/* @0x2ddd30 vneg.f32 s14, s14 */
/* @0x2ddd34 add r2, r4, #196 */
/* @0x2ddd38 add r3, r4, #228 */
/* @0x2ddd3c strb r10, [r4, #0xf8] */
/* @0x2ddd40 vneg.f32 s15, s15 */
/* @0x2ddd44 vstr s14, [r4, #212] */
/* @0x2ddd48 vstr s15, [r4, #216] */
/* @0x2ddd4c ldm r2, {r0, r1} */
/* @0x2ddd50 stm r3, {r0, r1} */
/* @0x2ddd54 vstr s14, [r4, #236] */
/* @0x2ddd58 vstr s15, [r4, #240] */
/* @0x2ddd5c b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c> */
/* @0x2ddd60 vldr s11, [r4, #216] */
/* @0x2ddd64 vldr s13, [r4, #68] */
/* @0x2ddd68 vmul.f32 s13, s11, s13 */
/* @0x2ddd6c ldr r1, [r4, #0x80] */
/* @0x2ddd70 vldr s12, [r4, #212] */
/* @0x2ddd74 vldr s15, [r4, #64] */
/* @0x2ddd78 cmp r1, #1 */
/* @0x2ddd7c str r9, [r7, #0x38] */
/* @0x2ddd80 vmla.f32 s13, s12, s15 */
/* @0x2ddd84 ble 0x2dde6c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xb0c> */
/* @0x2ddd88 add r3, r4, #72 */
/* @0x2ddd8c mov r2, r9 */
/* @0x2ddd90 mov r0, #0 */
/* @0x2ddd94 vldr s15, [r3, #4] */
/* @0x2ddd98 vldr s14, [r3] */
/* @0x2ddd9c add r3, r3, #8 */
/* @0x2ddda0 vmul.f32 s15, s11, s15 */
/* @0x2ddda4 vmla.f32 s15, s12, s14 */
/* @0x2ddda8 vcmpe.f32 s15, s13 */
/* @0x2dddac vmrs APSR_nzcv, fpscr */
/* @0x2dddb0 movmi r0, r2 */
/* @0x2dddb4 add r2, r2, #1 */
/* @0x2dddb8 vmovmi.f32 s13, s15 */
/* @0x2dddbc cmp r2, r1 */
/* @0x2dddc0 bne 0x2ddd94 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xa34> */
/* @0x2dddc4 add r11, r0, #1 */
/* @0x2dddc8 cmp r11, r2 */
/* @0x2dddcc uxtblt r2, r11 */
/* @0x2dddd0 uxtblt r10, r0 */
/* @0x2dddd4 uxtbge r10, r0 */
/* @0x2dddd8 bge 0x2dde74 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xb14> */
/* @0x2ddddc add r0, r4, r0, lsl #3 */
/* @0x2ddde0 add r11, r4, r11, lsl #3 */
/* @0x2ddde4 add r3, sp, #32 */
/* @0x2ddde8 ldrb lr, [r4, #0xf8] */
/* @0x2dddec ldm r0, {r0, r1} */
/* @0x2dddf0 mov r12, #0 */
/* @0x2dddf4 cmp lr, #0 */
/* @0x2dddf8 strb r2, [sp, #0x35] */
/* @0x2dddfc strb r12, [sp, #0x34] */
/* @0x2dde00 mov r2, #1 */
/* @0x2dde04 stm r3, {r0, r1} */
/* @0x2dde08 ldm r11, {r0, r1} */
/* @0x2dde0c strb r10, [sp, #0x29] */
/* @0x2dde10 add r10, sp, #44 */
/* @0x2dde14 strb r12, [sp, #0x28] */
/* @0x2dde18 stm r10, {r0, r1} */
/* @0x2dde1c strb r12, [sp, #0x2b] */
/* @0x2dde20 strb r12, [sp, #0x37] */
/* @0x2dde24 strb r2, [sp, #0x2a] */
/* @0x2dde28 strb r2, [sp, #0x36] */
/* @0x2dde2c beq 0x2dde80 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xb20> */
/* @0x2dde30 ldm r5, {r0, r1} */
/* @0x2dde34 add r11, sp, #112 */
/* @0x2dde38 add lr, r4, #196 */
/* @0x2dde3c str r2, [sp, #0x6c] */
/* @0x2dde40 add r2, sp, #120 */
/* @0x2dde44 str r12, [sp, #0x68] */
/* @0x2dde48 stm r11, {r0, r1} */
/* @0x2dde4c ldm r6, {r0, r1} */
/* @0x2dde50 stm r2, {r0, r1} */
/* @0x2dde54 add r2, sp, #128 */
/* @0x2dde58 ldm lr, {r0, r1} */
/* @0x2dde5c stm r2, {r0, r1} */
/* @0x2dde60 vldr s13, [sp, #132] */
/* @0x2dde64 vldr s14, [sp, #128] */
/* @0x2dde68 b 0x2dd9f0 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x690> */
/* @0x2dde6c mov r10, #0 */
/* @0x2dde70 mov r0, r10 */
/* @0x2dde74 mov r2, #0 */
/* @0x2dde78 mov r11, r2 */
/* @0x2dde7c b 0x2ddddc <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xa7c> */
/* @0x2dde80 ldm r6, {r0, r1} */
/* @0x2dde84 add r11, sp, #112 */
/* @0x2dde88 vldr s14, [r4, #196] */
/* @0x2dde8c vldr s13, [r4, #200] */
/* @0x2dde90 vneg.f32 s14, s14 */
/* @0x2dde94 mov r12, r2 */
/* @0x2dde98 stm r11, {r0, r1} */
/* @0x2dde9c ldm r5, {r0, r1} */
/* @0x2ddea0 str r2, [sp, #0x68] */
/* @0x2ddea4 add r2, sp, #120 */
/* @0x2ddea8 vneg.f32 s13, s13 */
/* @0x2ddeac vstr s14, [sp, #128] */
/* @0x2ddeb0 str lr, [sp, #0x6c] */
/* @0x2ddeb4 stm r2, {r0, r1} */
/* @0x2ddeb8 vstr s13, [sp, #132] */
/* @0x2ddebc b 0x2dd9f0 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x690> */
/* @0x2ddec0 vldr s15, [r4, #136] */
/* @0x2ddec4 vsub.f32 s13, s13, s15 */
/* @0x2ddec8 vldr s11, [r4, #140] */
/* @0x2ddecc vldr s12, [r4, #144] */
/* @0x2dded0 vldr s6, [r4, #132] */
/* @0x2dded4 ldr r1, [r3, #0x8] */
/* @0x2dded8 str r1, [r12, #0x10] */
/* @0x2ddedc vmul.f32 s15, s13, s11 */
/* @0x2ddee0 vmul.f32 s13, s13, s12 */
/* @0x2ddee4 vsub.f32 s14, s14, s6 */
/* @0x2ddee8 vmls.f32 s13, s11, s14 */
/* @0x2ddeec vmla.f32 s15, s14, s12 */
/* @0x2ddef0 vstr s13, [r12, #4] */
/* @0x2ddef4 vstr s15, [r12] */
/* @0x2ddef8 b 0x2ddb2c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x7cc> */
/* @0x2ddefc add r1, sp, #128 */
/* @0x2ddf00 add r2, r7, #40 */
/* @0x2ddf04 add r3, r7, #48 */
/* @0x2ddf08 ldm r1, {r0, r1} */
/* @0x2ddf0c stm r2, {r0, r1} */
/* @0x2ddf10 ldm r11, {r0, r1} */
/* @0x2ddf14 stm r3, {r0, r1} */
/* @0x2ddf18 b 0x2ddab0 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x750> */
/* @0x2ddf1c vmov r0, s12 */
/* @0x2ddf20 bl 0xb6700 <sqrtf@plt> */
/* @0x2ddf24 vldr s14, [r4, #148] */
/* @0x2ddf28 vldr s11, [r4, #152] */
/* @0x2ddf2c vldr s10, [r4, #156] */
/* @0x2ddf30 vldr s19, [r4, #160] */
/* @0x2ddf34 vmov s15, r0 */
/* @0x2ddf38 b 0x2dd54c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x1ec> */
/* @0x2ddf3c cmp r3, #0 */
/* @0x2ddf40 beq 0x2ddf98 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xc38> */
/* @0x2ddf44 vcmpe.f32 s18, #0 */
/* @0x2ddf48 vmrs APSR_nzcv, fpscr */
/* @0x2ddf4c blt 0x2de040 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xce0> */
/* @0x2ddf50 add r3, r4, #196 */
/* @0x2ddf54 mov r1, #1 */
/* @0x2ddf58 strb r1, [r4, #0xf8] */
/* @0x2ddf5c add r2, r4, #212 */
/* @0x2ddf60 ldm r3, {r0, r1} */
/* @0x2ddf64 add r12, r4, #204 */
/* @0x2ddf68 add r3, r4, #236 */
/* @0x2ddf6c stm r2, {r0, r1} */
/* @0x2ddf70 vldr s14, [r4, #200] */
/* @0x2ddf74 vldr s15, [r4, #196] */
/* @0x2ddf78 vneg.f32 s14, s14 */
/* @0x2ddf7c mov r2, r12 */
/* @0x2ddf80 vneg.f32 s15, s15 */
/* @0x2ddf84 vstr s14, [r4, #232] */
/* @0x2ddf88 vstr s15, [r4, #228] */
/* @0x2ddf8c ldm r12, {r0, r1} */
/* @0x2ddf90 stm r3, {r0, r1} */
/* @0x2ddf94 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c> */
/* @0x2ddf98 vcmpe.f32 s18, #0 */
/* @0x2ddf9c vmrs APSR_nzcv, fpscr */
/* @0x2ddfa0 blt 0x2ddff4 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xc94> */
/* @0x2ddfa4 vcmpe.f32 s11, #0 */
/* @0x2ddfa8 vmrs APSR_nzcv, fpscr */
/* @0x2ddfac blt 0x2ddff4 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xc94> */
/* @0x2ddfb0 add r3, r4, #196 */
/* @0x2ddfb4 mov r1, #1 */
/* @0x2ddfb8 strb r1, [r4, #0xf8] */
/* @0x2ddfbc add r2, r4, #212 */
/* @0x2ddfc0 ldm r3, {r0, r1} */
/* @0x2ddfc4 add r12, r4, #236 */
/* @0x2ddfc8 stm r2, {r0, r1} */
/* @0x2ddfcc vldr s14, [r4, #200] */
/* @0x2ddfd0 vldr s15, [r4, #196] */
/* @0x2ddfd4 vneg.f32 s14, s14 */
/* @0x2ddfd8 vneg.f32 s15, s15 */
/* @0x2ddfdc vstr s14, [r4, #232] */
/* @0x2ddfe0 vstr s15, [r4, #228] */
/* @0x2ddfe4 ldm r3, {r0, r1} */
/* @0x2ddfe8 mov r3, r12 */
/* @0x2ddfec stm r12, {r0, r1} */
/* @0x2ddff0 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c> */
/* @0x2ddff4 vldr s12, [r4, #200] */
/* @0x2ddff8 vldr s13, [r4, #196] */
/* @0x2ddffc vldr s14, [r4, #208] */
/* @0x2de000 vldr s15, [r4, #204] */
/* @0x2de004 vneg.f32 s12, s12 */
/* @0x2de008 add r2, r4, #196 */
/* @0x2de00c mov r1, #0 */
/* @0x2de010 strb r1, [r4, #0xf8] */
/* @0x2de014 add r3, r4, #236 */
/* @0x2de018 vneg.f32 s13, s13 */
/* @0x2de01c vstr s12, [r4, #216] */
/* @0x2de020 vneg.f32 s14, s14 */
/* @0x2de024 vstr s13, [r4, #212] */
/* @0x2de028 vneg.f32 s15, s15 */
/* @0x2de02c vstr s14, [r4, #232] */
/* @0x2de030 vstr s15, [r4, #228] */
/* @0x2de034 ldm r2, {r0, r1} */
/* @0x2de038 stm r3, {r0, r1} */
/* @0x2de03c b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c> */
/* @0x2de040 vcmpe.f32 s11, #0 */
/* @0x2de044 vmrs APSR_nzcv, fpscr */
/* @0x2de048 bge 0x2ddf50 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xbf0> */
/* @0x2de04c vldr s14, [r4, #196] */
/* @0x2de050 vldr s15, [r4, #200] */
/* @0x2de054 vneg.f32 s14, s14 */
/* @0x2de058 add r2, r4, #196 */
/* @0x2de05c add r3, r4, #236 */
/* @0x2de060 strb r9, [r4, #0xf8] */
/* @0x2de064 vneg.f32 s15, s15 */
/* @0x2de068 vstr s14, [r4, #212] */
/* @0x2de06c vstr s14, [r4, #228] */
/* @0x2de070 vstr s15, [r4, #216] */
/* @0x2de074 vstr s15, [r4, #232] */
/* @0x2de078 ldm r2, {r0, r1} */
/* @0x2de07c stm r3, {r0, r1} */
/* @0x2de080 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c> */
/* @0x2de084 vmov r0, s13 */
/* @0x2de088 bl 0xb6700 <sqrtf@plt> */
/* @0x2de08c vldr s12, [r4, #172] */
/* @0x2de090 vldr s10, [r4, #176] */
/* @0x2de094 vldr s14, [r4, #148] */
/* @0x2de098 vldr s11, [r4, #152] */
/* @0x2de09c vmov s15, r0 */
/* @0x2de0a0 b 0x2dd5d4 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x274> */
/* @0x2de0a4 vmov r0, s14 */
/* @0x2de0a8 bl 0xb6700 <sqrtf@plt> */
/* @0x2de0ac vldr s13, [r4, #164] */
/* @0x2de0b0 vldr s12, [r4, #168] */
/* @0x2de0b4 vmov s15, r0 */
/* @0x2de0b8 b 0x2dd474 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x114> */

/* ── FUNC 0x2de0bc · b2CollideEdgeAndPolygon(b2Manifold*, b2EdgeShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&) · size=56 · insn=14 */
/* @0x2de0bc push {r4, lr} */
/* @0x2de0c0 sub sp, sp, #264 */
/* @0x2de0c4 mov lr, r2 */
/* @0x2de0c8 mov r4, r1 */
/* @0x2de0cc ldr r12, [sp, #0x110] */
/* @0x2de0d0 mov r1, r0 */
/* @0x2de0d4 str r3, [sp] */
/* @0x2de0d8 mov r2, r4 */
/* @0x2de0dc add r0, sp, #12 */
/* @0x2de0e0 mov r3, lr */
/* @0x2de0e4 str r12, [sp, #0x4] */
/* @0x2de0e8 bl 0x2dd360 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_> */
/* @0x2de0ec add sp, sp, #264 */
/* @0x2de0f0 pop {r4, pc} */

/* ── FUNC 0x2de0f4 · anon_2de0f4 · size=876 · insn=220 */
/* @0x2de0f4 add r12, r0, #84 */
/* @0x2de0f8 lsl r2, r2, #3 */
/* @0x2de0fc add r12, r12, r2 */
/* @0x2de100 vldr s7, [r1, #12] */
/* @0x2de104 vldr s10, [r12, #4] */
/* @0x2de108 vmul.f32 s9, s7, s10 */
/* @0x2de10c vldr s15, [r12] */
/* @0x2de110 vldr s5, [r1, #8] */
/* @0x2de114 push {r4, r5, r6, r7} */
/* @0x2de118 add r0, r0, #20 */
/* @0x2de11c ldr r7, [sp, #0x10] */
/* @0x2de120 vldr s6, [r7, #8] */
/* @0x2de124 vldr s8, [r7, #12] */
/* @0x2de128 ldr r5, [r3, #0x94] */
/* @0x2de12c add r3, r3, #20 */
/* @0x2de130 cmp r5, #0 */
/* @0x2de134 vmla.f32 s9, s15, s5 */
/* @0x2de138 vmul.f32 s10, s5, s10 */
/* @0x2de13c vnmls.f32 s10, s7, s15 */
/* @0x2de140 vmul.f32 s12, s9, s6 */
/* @0x2de144 vmul.f32 s11, s9, s8 */
/* @0x2de148 vmla.f32 s12, s10, s8 */
/* @0x2de14c vmls.f32 s11, s6, s10 */
/* @0x2de150 ble 0x2de208 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x14c> */
/* @0x2de154 mov r4, #0 */
/* @0x2de158 mov r12, r3 */
/* @0x2de15c mov r6, r4 */
/* @0x2de160 vldr s13, [pc, #168] */
/* @0x2de164 vldr s15, [r12, #4] */
/* @0x2de168 vldr s14, [r12] */
/* @0x2de16c add r12, r12, #8 */
/* @0x2de170 vmul.f32 s15, s11, s15 */
/* @0x2de174 vmla.f32 s15, s12, s14 */
/* @0x2de178 vcmpe.f32 s15, s13 */
/* @0x2de17c vmrs APSR_nzcv, fpscr */
/* @0x2de180 movmi r6, r4 */
/* @0x2de184 add r4, r4, #1 */
/* @0x2de188 vmovmi.f32 s13, s15 */
/* @0x2de18c cmp r4, r5 */
/* @0x2de190 bne 0x2de164 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0xa8> */
/* @0x2de194 lsl r6, r6, #3 */
/* @0x2de198 add r6, r3, r6 */
/* @0x2de19c add r2, r0, r2 */
/* @0x2de1a0 vldr s14, [r6, #4] */
/* @0x2de1a4 vldr s15, [r2, #4] */
/* @0x2de1a8 vmul.f32 s13, s8, s14 */
/* @0x2de1ac vldr s11, [r6] */
/* @0x2de1b0 vldr s4, [r2] */
/* @0x2de1b4 vldr s0, [r7, #4] */
/* @0x2de1b8 vldr s1, [r1, #4] */
/* @0x2de1bc vldr s2, [r7] */
/* @0x2de1c0 vldr s3, [r1] */
/* @0x2de1c4 pop {r4, r5, r6, r7} */
/* @0x2de1c8 vmul.f32 s12, s7, s15 */
/* @0x2de1cc vmul.f32 s14, s6, s14 */
/* @0x2de1d0 vmul.f32 s15, s5, s15 */
/* @0x2de1d4 vmla.f32 s12, s5, s4 */
/* @0x2de1d8 vmla.f32 s13, s6, s11 */
/* @0x2de1dc vnmls.f32 s15, s7, s4 */
/* @0x2de1e0 vnmls.f32 s14, s8, s11 */
/* @0x2de1e4 vadd.f32 s12, s12, s1 */
/* @0x2de1e8 vadd.f32 s0, s13, s0 */
/* @0x2de1ec vsub.f32 s0, s0, s12 */
/* @0x2de1f0 vadd.f32 s14, s14, s2 */
/* @0x2de1f4 vadd.f32 s15, s15, s3 */
/* @0x2de1f8 vmul.f32 s0, s9, s0 */
/* @0x2de1fc vsub.f32 s15, s14, s15 */
/* @0x2de200 vmla.f32 s0, s10, s15 */
/* @0x2de204 bx lr */
/* @0x2de208 mov r6, #0 */
/* @0x2de20c b 0x2de198 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0xdc> */
/* @0x2de210 svcvc #0x7fffff */
/* @0x2de214 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2de218 vpush {d8, d9} */
/* @0x2de21c sub sp, sp, #20 */
/* @0x2de220 vldr s14, [r2, #12] */
/* @0x2de224 vldr s13, [r1, #16] */
/* @0x2de228 vldr s5, [r3, #16] */
/* @0x2de22c ldr r7, [sp, #0x48] */
/* @0x2de230 vmul.f32 s9, s14, s13 */
/* @0x2de234 vldr s7, [r7, #12] */
/* @0x2de238 vldr s15, [r2, #8] */
/* @0x2de23c vldr s6, [r1, #12] */
/* @0x2de240 vldr s8, [r3, #12] */
/* @0x2de244 vldr s12, [r7, #8] */
/* @0x2de248 vldr s2, [r2, #4] */
/* @0x2de24c vldr s11, [r7, #4] */
/* @0x2de250 vldr s3, [r7] */
/* @0x2de254 vldr s4, [r2] */
/* @0x2de258 ldr r4, [r1, #0x94] */
/* @0x2de25c mov r5, r1 */
/* @0x2de260 mov r6, r2 */
/* @0x2de264 cmp r4, #0 */
/* @0x2de268 mov r8, r3 */
/* @0x2de26c str r0, [sp, #0xc] */
/* @0x2de270 add r12, r1, #84 */
/* @0x2de274 vmul.f32 s10, s7, s5 */
/* @0x2de278 vmla.f32 s9, s6, s15 */
/* @0x2de27c vmla.f32 s10, s8, s12 */
/* @0x2de280 vmul.f32 s13, s15, s13 */
/* @0x2de284 vmul.f32 s12, s12, s5 */
/* @0x2de288 vnmls.f32 s13, s14, s6 */
/* @0x2de28c vnmls.f32 s12, s7, s8 */
/* @0x2de290 vadd.f32 s11, s10, s11 */
/* @0x2de294 vadd.f32 s9, s9, s2 */
/* @0x2de298 vsub.f32 s11, s11, s9 */
/* @0x2de29c vadd.f32 s10, s12, s3 */
/* @0x2de2a0 vadd.f32 s13, s13, s4 */
/* @0x2de2a4 vmul.f32 s12, s15, s11 */
/* @0x2de2a8 vmul.f32 s11, s14, s11 */
/* @0x2de2ac vsub.f32 s13, s10, s13 */
/* @0x2de2b0 vmla.f32 s12, s14, s13 */
/* @0x2de2b4 vmls.f32 s11, s15, s13 */
/* @0x2de2b8 ble 0x2de438 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x37c> */
/* @0x2de2bc mov r10, #0 */
/* @0x2de2c0 vldr s13, [pc, #408] */
/* @0x2de2c4 mov lr, r10 */
/* @0x2de2c8 vldr s15, [r12, #4] */
/* @0x2de2cc vldr s14, [r12] */
/* @0x2de2d0 add r12, r12, #8 */
/* @0x2de2d4 vmul.f32 s15, s11, s15 */
/* @0x2de2d8 vmla.f32 s15, s12, s14 */
/* @0x2de2dc vcmpe.f32 s15, s13 */
/* @0x2de2e0 vmrs APSR_nzcv, fpscr */
/* @0x2de2e4 movgt r10, lr */
/* @0x2de2e8 add lr, lr, #1 */
/* @0x2de2ec vmovgt.f32 s13, s15 */
/* @0x2de2f0 cmp lr, r4 */
/* @0x2de2f4 bne 0x2de2c8 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x20c> */
/* @0x2de2f8 str r7, [sp] */
/* @0x2de2fc mov r0, r5 */
/* @0x2de300 mov r1, r6 */
/* @0x2de304 mov r2, r10 */
/* @0x2de308 mov r3, r8 */
/* @0x2de30c bl 0x2de0f4 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x38> */
/* @0x2de310 cmp r10, #0 */
/* @0x2de314 vmov.f32 s17, s0 */
/* @0x2de318 beq 0x2de450 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x394> */
/* @0x2de31c sub r9, r10, #1 */
/* @0x2de320 add r11, r10, #1 */
/* @0x2de324 cmp r4, r11 */
/* @0x2de328 mov r0, r5 */
/* @0x2de32c mov r1, r6 */
/* @0x2de330 mov r2, r9 */
/* @0x2de334 mov r3, r8 */
/* @0x2de338 str r7, [sp] */
/* @0x2de33c movle r11, #0 */
/* @0x2de340 bl 0x2de0f4 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x38> */
/* @0x2de344 str r7, [sp] */
/* @0x2de348 mov r2, r11 */
/* @0x2de34c mov r0, r5 */
/* @0x2de350 mov r1, r6 */
/* @0x2de354 mov r3, r8 */
/* @0x2de358 vmov.f32 s18, s0 */
/* @0x2de35c bl 0x2de0f4 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x38> */
/* @0x2de360 vcmpe.f32 s18, s17 */
/* @0x2de364 vmrs APSR_nzcv, fpscr */
/* @0x2de368 vmov.f32 s16, s0 */
/* @0x2de36c ble 0x2de3d8 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x31c> */
/* @0x2de370 vcmpe.f32 s18, s0 */
/* @0x2de374 vmrs APSR_nzcv, fpscr */
/* @0x2de378 ble 0x2de3d8 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x31c> */
/* @0x2de37c vmov.f32 s16, s18 */
/* @0x2de380 mov r11, r9 */
/* @0x2de384 b 0x2de390 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x2d4> */
/* @0x2de388 vmov.f32 s16, s0 */
/* @0x2de38c mov r11, r10 */
/* @0x2de390 cmp r11, #0 */
/* @0x2de394 sub r10, r11, #1 */
/* @0x2de398 suble r10, r4, #1 */
/* @0x2de39c str r7, [sp] */
/* @0x2de3a0 mov r0, r5 */
/* @0x2de3a4 mov r1, r6 */
/* @0x2de3a8 mov r2, r10 */
/* @0x2de3ac mov r3, r8 */
/* @0x2de3b0 bl 0x2de0f4 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x38> */
/* @0x2de3b4 vcmpe.f32 s0, s16 */
/* @0x2de3b8 vmrs APSR_nzcv, fpscr */
/* @0x2de3bc bgt 0x2de388 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x2cc> */
/* @0x2de3c0 ldr r3, [sp, #0xc] */
/* @0x2de3c4 vmov.f32 s0, s16 */
/* @0x2de3c8 str r11, [r3] */
/* @0x2de3cc add sp, sp, #20 */
/* @0x2de3d0 vpop {d8, d9} */
/* @0x2de3d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2de3d8 vcmpe.f32 s16, s17 */
/* @0x2de3dc vmrs APSR_nzcv, fpscr */
/* @0x2de3e0 bgt 0x2de404 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x348> */
/* @0x2de3e4 ldr r3, [sp, #0xc] */
/* @0x2de3e8 vmov.f32 s0, s17 */
/* @0x2de3ec str r10, [r3] */
/* @0x2de3f0 add sp, sp, #20 */
/* @0x2de3f4 vpop {d8, d9} */
/* @0x2de3f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2de3fc vmov.f32 s16, s0 */
/* @0x2de400 mov r11, r10 */
/* @0x2de404 add r10, r11, #1 */
/* @0x2de408 str r7, [sp] */
/* @0x2de40c cmp r4, r10 */
/* @0x2de410 mov r0, r5 */
/* @0x2de414 mov r1, r6 */
/* @0x2de418 mov r3, r8 */
/* @0x2de41c movle r10, #0 */
/* @0x2de420 mov r2, r10 */
/* @0x2de424 bl 0x2de0f4 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x38> */
/* @0x2de428 vcmpe.f32 s0, s16 */
/* @0x2de42c vmrs APSR_nzcv, fpscr */
/* @0x2de430 bgt 0x2de3fc <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x340> */
/* @0x2de434 b 0x2de3c0 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x304> */
/* @0x2de438 mov r0, r1 */
/* @0x2de43c str r7, [sp] */
/* @0x2de440 mov r1, r2 */
/* @0x2de444 mov r2, #0 */
/* @0x2de448 bl 0x2de0f4 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x38> */
/* @0x2de44c vmov.f32 s17, s0 */
/* @0x2de450 sub r9, r4, #1 */
/* @0x2de454 mov r11, #1 */
/* @0x2de458 mov r10, #0 */
/* @0x2de45c b 0x2de324 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x268> */
/* @0x2de460 .word 0xff7fffff */

/* ── FUNC 0x2de464 · b2CollidePolygons(b2Manifold*, b2PolygonShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&) · size=1180 · insn=295 */
/* @0x2de464 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2de468 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2de46c sub sp, sp, #120 */
/* @0x2de470 vldr s16, [r1, #8] */
/* @0x2de474 mov r8, r0 */
/* @0x2de478 add r0, sp, #120 */
/* @0x2de47c ldr r5, [sp, #0xd8] */
/* @0x2de480 vldr s15, [r3, #8] */
/* @0x2de484 mov r4, #0 */
/* @0x2de488 str r4, [r0, #-0x58]! */
/* @0x2de48c str r4, [r8, #0x3c] */
/* @0x2de490 vadd.f32 s16, s16, s15 */
/* @0x2de494 str r5, [sp] */
/* @0x2de498 mov r7, r1 */
/* @0x2de49c mov r6, r3 */
/* @0x2de4a0 mov r9, r2 */
/* @0x2de4a4 bl 0x2de214 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x158> */
/* @0x2de4a8 vcmpe.f32 s16, s0 */
/* @0x2de4ac vmov.f32 s17, s0 */
/* @0x2de4b0 vmrs APSR_nzcv, fpscr */
/* @0x2de4b4 bpl 0x2de4c4 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x60> */
/* @0x2de4b8 add sp, sp, #120 */
/* @0x2de4bc vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2de4c0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2de4c4 add r0, sp, #120 */
/* @0x2de4c8 str r9, [sp] */
/* @0x2de4cc mov r1, r6 */
/* @0x2de4d0 mov r2, r5 */
/* @0x2de4d4 str r4, [r0, #-0x54]! */
/* @0x2de4d8 mov r3, r7 */
/* @0x2de4dc bl 0x2de214 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x158> */
/* @0x2de4e0 vcmpe.f32 s16, s0 */
/* @0x2de4e4 vmrs APSR_nzcv, fpscr */
/* @0x2de4e8 bmi 0x2de4b8 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x54> */
/* @0x2de4ec vldr s14, [pc, #1004] */
/* @0x2de4f0 vldr s15, [pc, #1004] */
/* @0x2de4f4 vmla.f32 s15, s17, s14 */
/* @0x2de4f8 vcmpe.f32 s0, s15 */
/* @0x2de4fc vmrs APSR_nzcv, fpscr */
/* @0x2de500 ble 0x2de85c <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x3f8> */
/* @0x2de504 ldr r10, [sp, #0x24] */
/* @0x2de508 mov r4, #1 */
/* @0x2de50c vldr s11, [r5] */
/* @0x2de510 vldr s13, [r5, #4] */
/* @0x2de514 vldr s18, [r5, #8] */
/* @0x2de518 vldr s17, [r5, #12] */
/* @0x2de51c vldr s30, [r9] */
/* @0x2de520 vldr s29, [r9, #4] */
/* @0x2de524 vldr s21, [r9, #8] */
/* @0x2de528 vldr s19, [r9, #12] */
/* @0x2de52c mov r3, #2 */
/* @0x2de530 vstr s11, [sp, #16] */
/* @0x2de534 vstr s13, [sp, #12] */
/* @0x2de538 str r3, [r8, #0x38] */
/* @0x2de53c lsl r0, r10, #3 */
/* @0x2de540 add r3, r6, #84 */
/* @0x2de544 add r3, r3, r0 */
/* @0x2de548 vldr s15, [r3, #4] */
/* @0x2de54c vmul.f32 s11, s17, s15 */
/* @0x2de550 vldr s14, [r3] */
/* @0x2de554 ldr r3, [r7, #0x94] */
/* @0x2de558 add lr, r7, #20 */
/* @0x2de55c add r2, r7, #84 */
/* @0x2de560 mov r1, #0 */
/* @0x2de564 cmp r3, #0 */
/* @0x2de568 vmla.f32 s11, s18, s14 */
/* @0x2de56c vmul.f32 s15, s18, s15 */
/* @0x2de570 vnmls.f32 s15, s17, s14 */
/* @0x2de574 vmul.f32 s12, s21, s11 */
/* @0x2de578 vmul.f32 s11, s19, s11 */
/* @0x2de57c vneg.f32 s13, s21 */
/* @0x2de580 vmla.f32 s12, s19, s15 */
/* @0x2de584 vstr s13, [sp, #28] */
/* @0x2de588 vmla.f32 s11, s15, s13 */
/* @0x2de58c ble 0x2de8d0 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x46c> */
/* @0x2de590 mov r12, r1 */
/* @0x2de594 vldr s13, [pc, #844] */
/* @0x2de598 vldr s15, [r2, #4] */
/* @0x2de59c vldr s14, [r2] */
/* @0x2de5a0 add r2, r2, #8 */
/* @0x2de5a4 vmul.f32 s15, s11, s15 */
/* @0x2de5a8 vmla.f32 s15, s12, s14 */
/* @0x2de5ac vcmpe.f32 s13, s15 */
/* @0x2de5b0 vmrs APSR_nzcv, fpscr */
/* @0x2de5b4 movgt r1, r12 */
/* @0x2de5b8 add r12, r12, #1 */
/* @0x2de5bc vmovgt.f32 s13, s15 */
/* @0x2de5c0 cmp r12, r3 */
/* @0x2de5c4 bne 0x2de598 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x134> */
/* @0x2de5c8 add r5, r1, #1 */
/* @0x2de5cc lsl r2, r1, #3 */
/* @0x2de5d0 cmp r12, r5 */
/* @0x2de5d4 uxtb r1, r1 */
/* @0x2de5d8 ble 0x2de8c4 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x460> */
/* @0x2de5dc lsl r3, r5, #3 */
/* @0x2de5e0 uxtb r12, r5 */
/* @0x2de5e4 add r3, lr, r3 */
/* @0x2de5e8 vldr s15, [r3, #4] */
/* @0x2de5ec vmul.f32 s14, s21, s15 */
/* @0x2de5f0 vldr s11, [r3] */
/* @0x2de5f4 ldr r3, [r6, #0x94] */
/* @0x2de5f8 add r5, r10, #1 */
/* @0x2de5fc add r6, r6, #20 */
/* @0x2de600 add r2, lr, r2 */
/* @0x2de604 cmp r3, r5 */
/* @0x2de608 uxtb r3, r10 */
/* @0x2de60c strb r3, [sp, #0x38] */
/* @0x2de610 vldr s13, [r2, #4] */
/* @0x2de614 strb r3, [sp, #0x44] */
/* @0x2de618 mov r3, #0 */
/* @0x2de61c strb r3, [sp, #0x3b] */
/* @0x2de620 movle r5, r3 */
/* @0x2de624 strb r3, [sp, #0x47] */
/* @0x2de628 addgt r3, r0, #8 */
/* @0x2de62c add r3, r6, r3 */
/* @0x2de630 add r0, r6, r0 */
/* @0x2de634 vldr s27, [r3, #4] */
/* @0x2de638 vldr s25, [r0, #4] */
/* @0x2de63c vldr s26, [r0] */
/* @0x2de640 vldr s28, [r3] */
/* @0x2de644 vldr s10, [r2] */
/* @0x2de648 strb r1, [sp, #0x39] */
/* @0x2de64c vnmls.f32 s14, s19, s11 */
/* @0x2de650 mov r2, #1 */
/* @0x2de654 strb r12, [sp, #0x45] */
/* @0x2de658 strb r2, [sp, #0x3a] */
/* @0x2de65c strb r2, [sp, #0x46] */
/* @0x2de660 vadd.f32 s14, s14, s30 */
/* @0x2de664 vmul.f32 s15, s19, s15 */
/* @0x2de668 vstr s14, [sp, #60] */
/* @0x2de66c vsub.f32 s23, s27, s25 */
/* @0x2de670 vmul.f32 s14, s23, s23 */
/* @0x2de674 vmla.f32 s15, s21, s11 */
/* @0x2de678 vsub.f32 s22, s28, s26 */
/* @0x2de67c vmla.f32 s14, s22, s22 */
/* @0x2de680 vadd.f32 s15, s15, s29 */
/* @0x2de684 vmul.f32 s12, s21, s13 */
/* @0x2de688 vstr s15, [sp, #64] */
/* @0x2de68c vmul.f32 s13, s19, s13 */
/* @0x2de690 vsqrt.f32 s15, s14 */
/* @0x2de694 vnmls.f32 s12, s19, s10 */
/* @0x2de698 vmla.f32 s13, s21, s10 */
/* @0x2de69c vadd.f32 s12, s12, s30 */
/* @0x2de6a0 vadd.f32 s13, s13, s29 */
/* @0x2de6a4 vstr s12, [sp, #48] */
/* @0x2de6a8 vcmp.f32 s15, s15 */
/* @0x2de6ac vstr s13, [sp, #52] */
/* @0x2de6b0 vmrs APSR_nzcv, fpscr */
/* @0x2de6b4 bne 0x2de8f0 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x48c> */
/* @0x2de6b8 vldr s14, [pc, #556] */
/* @0x2de6bc vcmpe.f32 s15, s14 */
/* @0x2de6c0 vldr s11, [sp, #12] */
/* @0x2de6c4 vldr s13, [sp, #16] */
/* @0x2de6c8 add r6, sp, #72 */
/* @0x2de6cc add r7, sp, #96 */
/* @0x2de6d0 str r10, [sp] */
/* @0x2de6d4 add r1, sp, #48 */
/* @0x2de6d8 vmrs APSR_nzcv, fpscr */
/* @0x2de6dc vmovpl.f32 s14, #1.000000e+00 */
/* @0x2de6e0 mov r0, r6 */
/* @0x2de6e4 mov r2, r7 */
/* @0x2de6e8 vdivpl.f32 s15, s14, s15 */
/* @0x2de6ec vmulpl.f32 s23, s23, s15 */
/* @0x2de6f0 vmulpl.f32 s22, s22, s15 */
/* @0x2de6f4 vmul.f32 s15, s17, s25 */
/* @0x2de6f8 vmul.f32 s20, s17, s23 */
/* @0x2de6fc vmla.f32 s15, s18, s26 */
/* @0x2de700 vmul.f32 s14, s18, s25 */
/* @0x2de704 vmla.f32 s20, s18, s22 */
/* @0x2de708 vmul.f32 s24, s18, s23 */
/* @0x2de70c vstr s20, [sp, #44] */
/* @0x2de710 vnmls.f32 s14, s17, s26 */
/* @0x2de714 vadd.f32 s15, s11, s15 */
/* @0x2de718 vnmls.f32 s24, s17, s22 */
/* @0x2de71c vstr s15, [sp, #24] */
/* @0x2de720 vmul.f32 s15, s20, s15 */
/* @0x2de724 vstr s24, [sp, #40] */
/* @0x2de728 vadd.f32 s14, s13, s14 */
/* @0x2de72c vmla.f32 s15, s24, s14 */
/* @0x2de730 vstr s14, [sp, #20] */
/* @0x2de734 vsub.f32 s15, s16, s15 */
/* @0x2de738 vneg.f32 s14, s20 */
/* @0x2de73c vmov r3, s15 */
/* @0x2de740 vneg.f32 s31, s24 */
/* @0x2de744 vstr s14, [sp, #100] */
/* @0x2de748 vstr s31, [sp, #96] */
/* @0x2de74c bl 0x2c39c4 <_Z19b2ClipSegmentToLineP12b2ClipVertexPKS_RK6b2Vec2fi> */
/* @0x2de750 cmp r0, #1 */
/* @0x2de754 ble 0x2de4b8 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x54> */
/* @0x2de758 vmul.f32 s15, s17, s27 */
/* @0x2de75c vldr s14, [sp, #12] */
/* @0x2de760 vldr s11, [sp, #16] */
/* @0x2de764 str r5, [sp] */
/* @0x2de768 mov r0, r7 */
/* @0x2de76c mov r1, r6 */
/* @0x2de770 add r2, sp, #40 */
/* @0x2de774 vmla.f32 s15, s18, s28 */
/* @0x2de778 vmul.f32 s18, s18, s27 */
/* @0x2de77c vnmls.f32 s18, s17, s28 */
/* @0x2de780 vadd.f32 s15, s14, s15 */
/* @0x2de784 vmul.f32 s15, s20, s15 */
/* @0x2de788 vadd.f32 s18, s11, s18 */
/* @0x2de78c vmla.f32 s15, s24, s18 */
/* @0x2de790 vadd.f32 s15, s16, s15 */
/* @0x2de794 vmov r3, s15 */
/* @0x2de798 bl 0x2c39c4 <_Z19b2ClipSegmentToLineP12b2ClipVertexPKS_RK6b2Vec2fi> */
/* @0x2de79c cmp r0, #1 */
/* @0x2de7a0 ble 0x2de4b8 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x54> */
/* @0x2de7a4 vldr s13, [sp, #24] */
/* @0x2de7a8 vmul.f32 s12, s31, s13 */
/* @0x2de7ac vldr s14, [sp, #20] */
/* @0x2de7b0 add r3, sp, #104 */
/* @0x2de7b4 add r0, sp, #128 */
/* @0x2de7b8 mov r1, #0 */
/* @0x2de7bc vstr s23, [r8, #40] */
/* @0x2de7c0 vmov.f32 s15, #5.000000e-01 */
/* @0x2de7c4 vadd.f32 s26, s28, s26 */
/* @0x2de7c8 vadd.f32 s25, s27, s25 */
/* @0x2de7cc vmla.f32 s12, s20, s14 */
/* @0x2de7d0 vmul.f32 s26, s26, s15 */
/* @0x2de7d4 vmul.f32 s15, s25, s15 */
/* @0x2de7d8 vstr s26, [r8, #48] */
/* @0x2de7dc vneg.f32 s22, s22 */
/* @0x2de7e0 vstr s15, [r8, #52] */
/* @0x2de7e4 vstr s22, [r8, #44] */
/* @0x2de7e8 vldr s13, [r3, #-4] */
/* @0x2de7ec vmul.f32 s15, s31, s13 */
/* @0x2de7f0 vldr s14, [r3, #-8] */
/* @0x2de7f4 add r2, r1, r1, lsl #2 */
/* @0x2de7f8 add r2, r8, r2, lsl #2 */
/* @0x2de7fc vmla.f32 s15, s20, s14 */
/* @0x2de800 vsub.f32 s15, s15, s12 */
/* @0x2de804 vcmpe.f32 s16, s15 */
/* @0x2de808 vmrs APSR_nzcv, fpscr */
/* @0x2de80c blt 0x2de848 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x3e4> */
/* @0x2de810 vsub.f32 s13, s13, s29 */
/* @0x2de814 vldr s11, [sp, #28] */
/* @0x2de818 ldr r12, [r3] */
/* @0x2de81c cmp r4, #0 */
/* @0x2de820 add r1, r1, #1 */
/* @0x2de824 str r12, [r2, #0x10] */
/* @0x2de828 vmul.f32 s15, s13, s21 */
/* @0x2de82c vmul.f32 s13, s13, s19 */
/* @0x2de830 vsub.f32 s14, s14, s30 */
/* @0x2de834 vmla.f32 s15, s14, s19 */
/* @0x2de838 vmla.f32 s13, s14, s11 */
/* @0x2de83c vstr s15, [r2] */
/* @0x2de840 vstr s13, [r2, #4] */
/* @0x2de844 bne 0x2de8a0 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x43c> */
/* @0x2de848 add r3, r3, #12 */
/* @0x2de84c cmp r3, r0 */
/* @0x2de850 bne 0x2de7e8 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x384> */
/* @0x2de854 str r1, [r8, #0x3c] */
/* @0x2de858 b 0x2de4b8 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x54> */
/* @0x2de85c mov r3, r6 */
/* @0x2de860 vldr s14, [r9] */
/* @0x2de864 vldr s15, [r9, #4] */
/* @0x2de868 mov r6, r7 */
/* @0x2de86c vldr s18, [r9, #8] */
/* @0x2de870 mov r7, r3 */
/* @0x2de874 vldr s17, [r9, #12] */
/* @0x2de878 vldr s30, [r5] */
/* @0x2de87c vldr s29, [r5, #4] */
/* @0x2de880 vldr s21, [r5, #8] */
/* @0x2de884 vldr s19, [r5, #12] */
/* @0x2de888 mov r3, #1 */
/* @0x2de88c ldr r10, [sp, #0x20] */
/* @0x2de890 vstr s14, [sp, #16] */
/* @0x2de894 vstr s15, [sp, #12] */
/* @0x2de898 str r3, [r8, #0x38] */
/* @0x2de89c b 0x2de53c <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0xd8> */
/* @0x2de8a0 ldrb r7, [r2, #0x10] */
/* @0x2de8a4 ldrb r6, [r2, #0x11] */
/* @0x2de8a8 ldrb r5, [r2, #0x12] */
/* @0x2de8ac ldrb r12, [r2, #0x13] */
/* @0x2de8b0 strb r7, [r2, #0x11] */
/* @0x2de8b4 strb r6, [r2, #0x10] */
/* @0x2de8b8 strb r5, [r2, #0x13] */
/* @0x2de8bc strb r12, [r2, #0x12] */
/* @0x2de8c0 b 0x2de848 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x3e4> */
/* @0x2de8c4 mov r12, #0 */
/* @0x2de8c8 mov r3, r12 */
/* @0x2de8cc b 0x2de5e4 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x180> */
/* @0x2de8d0 mov r2, r1 */
/* @0x2de8d4 mov r12, r1 */
/* @0x2de8d8 mov r3, r1 */
/* @0x2de8dc b 0x2de5e4 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x180> */
/* @0x2de8e0 svclo #0x7ae148 */
/* @0x2de8e4 blo 0xfe3a32a8 <b2_toiTime+0xfffffffffdc49e04> */
/* @0x2de8e8 svcvc #0x7fffff */
/* @0x2de8ec strlo r0, [r0], #-0 */
/* @0x2de8f0 vmov r0, s14 */
/* @0x2de8f4 bl 0xb6700 <sqrtf@plt> */
/* @0x2de8f8 vmov s15, r0 */
/* @0x2de8fc b 0x2de6b8 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x254> */

/* ── FUNC 0x2de900 · b2DynamicTree::b2DynamicTree() · size=164 · insn=41 */
/* @0x2de900 push {r3, r4, r5, r6, r7, lr} */
/* @0x2de904 mov r4, r0 */
/* @0x2de908 mov r3, #16 */
/* @0x2de90c mov r5, #0 */
/* @0x2de910 str r3, [r0, #0xc] */
/* @0x2de914 mvn r6, #0 */
/* @0x2de918 str r6, [r0] */
/* @0x2de91c mov r0, #576 */
/* @0x2de920 str r5, [r4, #0x8] */
/* @0x2de924 bl 0x2c6a6c <_Z7b2Alloci> */
/* @0x2de928 ldr r3, [r4, #0xc] */
/* @0x2de92c mov r1, r5 */
/* @0x2de930 add r2, r3, r3, lsl #3 */
/* @0x2de934 lsl r2, r2, #2 */
/* @0x2de938 str r0, [r4, #0x4] */
/* @0x2de93c bl 0xb65b0 <memset@plt> */
/* @0x2de940 ldr r12, [r4, #0xc] */
/* @0x2de944 ldr r7, [r4, #0x4] */
/* @0x2de948 cmp r12, #1 */
/* @0x2de94c subgt r0, r12, #1 */
/* @0x2de950 movgt r1, r5 */
/* @0x2de954 movgt r2, r6 */
/* @0x2de958 movgt r3, r7 */
/* @0x2de95c ble 0x2de978 <_ZN13b2DynamicTreeC2Ev+0x78> */
/* @0x2de960 add r1, r1, #1 */
/* @0x2de964 str r2, [r3, #0x20] */
/* @0x2de968 cmp r1, r0 */
/* @0x2de96c str r1, [r3, #0x14] */
/* @0x2de970 add r3, r3, #36 */
/* @0x2de974 bne 0x2de960 <_ZN13b2DynamicTreeC2Ev+0x60> */
/* @0x2de978 add r12, r12, r12, lsl #3 */
/* @0x2de97c mov r3, #0 */
/* @0x2de980 mvn r2, #0 */
/* @0x2de984 mov r0, r4 */
/* @0x2de988 add r12, r7, r12, lsl #2 */
/* @0x2de98c str r2, [r12, #-0x10] */
/* @0x2de990 str r2, [r12, #-0x4] */
/* @0x2de994 str r3, [r4, #0x10] */
/* @0x2de998 str r3, [r4, #0x14] */
/* @0x2de99c str r3, [r4, #0x18] */
/* @0x2de9a0 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2de900 · b2DynamicTree::b2DynamicTree() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2de9a4 · b2DynamicTree::~b2DynamicTree() · size=24 · insn=6 */
/* @0x2de9a4 push {r4, lr} */
/* @0x2de9a8 mov r4, r0 */
/* @0x2de9ac ldr r0, [r0, #0x4] */
/* @0x2de9b0 bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2de9b4 mov r0, r4 */
/* @0x2de9b8 pop {r4, pc} */

/* ── FUNC 0x2de9a4 · b2DynamicTree::~b2DynamicTree() · alias of the symbol above · insn=0 */
