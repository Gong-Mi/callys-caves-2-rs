/* libyoyo.so 覆盖卡组 0084
 * 函数 0x14d43c..0x14e718，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x14d43c · F_PhysicsDestroyParticleRegionBox(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x14d43c ldr r3, [pc, #0x8c] */
/* @0x14d440 push {r4, r5, r6, r7, r8, lr} */
/* @0x14d444 ldr r3, [pc, r3] */
/* @0x14d448 ldr r4, [sp, #0x18] */
/* @0x14d44c ldr r3, [r3] */
/* @0x14d450 cmp r3, #0 */
/* @0x14d454 beq 0x14d4bc <_Z33F_PhysicsDestroyParticleRegionBoxR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x14d458 ldr r5, [r3, #0xb4] */
/* @0x14d45c cmp r5, #0 */
/* @0x14d460 beq 0x14d4bc <_Z33F_PhysicsDestroyParticleRegionBoxR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x14d464 mov r0, r4 */
/* @0x14d468 mov r1, #0 */
/* @0x14d46c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d470 mov r1, #1 */
/* @0x14d474 mov r8, r0 */
/* @0x14d478 mov r0, r4 */
/* @0x14d47c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d480 mov r1, #2 */
/* @0x14d484 mov r7, r0 */
/* @0x14d488 mov r0, r4 */
/* @0x14d48c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d490 mov r1, #3 */
/* @0x14d494 mov r6, r0 */
/* @0x14d498 mov r0, r4 */
/* @0x14d49c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d4a0 mov r1, r8 */
/* @0x14d4a4 mov r2, r7 */
/* @0x14d4a8 mov r3, r6 */
/* @0x14d4ac str r0, [sp, #0x18] */
/* @0x14d4b0 mov r0, r5 */
/* @0x14d4b4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x14d4b8 b 0x239fd0 <_ZN13CPhysicsWorld23DeleteParticleBoxRegionEffff> */
/* @0x14d4bc ldr r0, [pc, #0x10] */
/* @0x14d4c0 mov r1, #0 */
/* @0x14d4c4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x14d4c8 add r0, pc, r0 */
/* @0x14d4cc b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14d4d0 eoreq r0, r10, r4, ror #9 */
/* @0x14d4d4 andseq r6, pc, r8, ror #23 */

/* ── FUNC 0x14d4d8 · F_PhysicsDestroyParticleRegionPoly(RValue&, CInstance*, CInstance*, int, RValue*) · size=380 · insn=95 */
/* @0x14d4d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x14d4dc sub sp, sp, #12 */
/* @0x14d4e0 ldr r7, [pc, #0x154] */
/* @0x14d4e4 ldr r0, [sp, #0x30] */
/* @0x14d4e8 ldr r7, [pc, r7] */
/* @0x14d4ec ldr r3, [r7] */
/* @0x14d4f0 cmp r3, #0 */
/* @0x14d4f4 beq 0x14d624 <_Z34F_PhysicsDestroyParticleRegionPolyR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x14d4f8 ldr r3, [r3, #0xb4] */
/* @0x14d4fc cmp r3, #0 */
/* @0x14d500 beq 0x14d624 <_Z34F_PhysicsDestroyParticleRegionPolyR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x14d504 mov r1, #0 */
/* @0x14d508 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14d50c cmp r0, #0 */
/* @0x14d510 blt 0x14d604 <_Z34F_PhysicsDestroyParticleRegionPolyR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x14d514 ldr r3, [pc, #0x124] */
/* @0x14d518 ldr r3, [pc, r3] */
/* @0x14d51c ldr r3, [r3] */
/* @0x14d520 cmp r0, r3 */
/* @0x14d524 bge 0x14d604 <_Z34F_PhysicsDestroyParticleRegionPolyR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x14d528 ldr r10, [pc, #0x114] */
/* @0x14d52c lsl r8, r0, #2 */
/* @0x14d530 ldr r10, [pc, r10] */
/* @0x14d534 ldr r3, [r10, #0x4] */
/* @0x14d538 ldr r0, [r3, r0, lsl #2] */
/* @0x14d53c cmp r0, #0 */
/* @0x14d540 beq 0x14d604 <_Z34F_PhysicsDestroyParticleRegionPolyR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x14d544 bl 0x2052b8 <_ZN8CDS_List4SizeEv> */
/* @0x14d548 subs r11, r0, #0 */
/* @0x14d54c ble 0x14d61c <_Z34F_PhysicsDestroyParticleRegionPolyR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x14d550 ldr r1, [pc, #0xf0] */
/* @0x14d554 lsl r0, r11, #2 */
/* @0x14d558 movw r2, #0x6ad */
/* @0x14d55c mov r3, #1 */
/* @0x14d560 add r1, pc, r1 */
/* @0x14d564 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x14d568 asrs r11, r11, #1 */
/* @0x14d56c str r11, [sp, #0x4] */
/* @0x14d570 str r0, [sp] */
/* @0x14d574 beq 0x14d5e4 <_Z34F_PhysicsDestroyParticleRegionPolyR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x14d578 ldr r3, [sp] */
/* @0x14d57c mov r11, #0 */
/* @0x14d580 add r6, r3, #4 */
/* @0x14d584 ldr r3, [sp, #0x4] */
/* @0x14d588 lsl r9, r3, #1 */
/* @0x14d58c ldr r2, [r10, #0x4] */
/* @0x14d590 mov r1, r11 */
/* @0x14d594 ldr r0, [r2, r8] */
/* @0x14d598 bl 0x2031f4 <_ZN8CDS_List8GetValueEi> */
/* @0x14d59c ldr r2, [r10, #0x4] */
/* @0x14d5a0 add r1, r11, #1 */
/* @0x14d5a4 add r11, r11, #2 */
/* @0x14d5a8 ldr r4, [r0] */
/* @0x14d5ac ldr r5, [r0, #0x4] */
/* @0x14d5b0 ldr r0, [r2, r8] */
/* @0x14d5b4 vmov d6, r4, r5 */
/* @0x14d5b8 vcvt.f32.f64 s15, d6 */
/* @0x14d5bc vstr s15, [r6, #-4] */
/* @0x14d5c0 bl 0x2031f4 <_ZN8CDS_List8GetValueEi> */
/* @0x14d5c4 cmp r11, r9 */
/* @0x14d5c8 ldr r4, [r0] */
/* @0x14d5cc ldr r5, [r0, #0x4] */
/* @0x14d5d0 vmov d6, r4, r5 */
/* @0x14d5d4 vcvt.f32.f64 s15, d6 */
/* @0x14d5d8 vmov r3, s15 */
/* @0x14d5dc str r3, [r6], #8 */
/* @0x14d5e0 bne 0x14d58c <_Z34F_PhysicsDestroyParticleRegionPolyR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x14d5e4 ldr r3, [r7] */
/* @0x14d5e8 ldm sp, {r1, r2} */
/* @0x14d5ec ldr r0, [r3, #0xb4] */
/* @0x14d5f0 bl 0x23a08c <_ZN13CPhysicsWorld24DeleteParticlePolyRegionEPfi> */
/* @0x14d5f4 ldr r0, [sp] */
/* @0x14d5f8 add sp, sp, #12 */
/* @0x14d5fc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x14d600 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x14d604 ldr r0, [pc, #0x40] */
/* @0x14d608 mov r1, #0 */
/* @0x14d60c add r0, pc, r0 */
/* @0x14d610 add sp, sp, #12 */
/* @0x14d614 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x14d618 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14d61c add sp, sp, #12 */
/* @0x14d620 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x14d624 ldr r0, [pc, #0x24] */
/* @0x14d628 mov r1, #0 */
/* @0x14d62c add r0, pc, r0 */
/* @0x14d630 add sp, sp, #12 */
/* @0x14d634 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x14d638 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14d63c eoreq r0, r10, r0, asr #8 */
/* @0x14d640 eoreq r0, r10, r4, ror #14 */
/* @0x14d644 eoreq r0, r10, r0, asr r7 */
/* @0x14d648 ldrheq r6, [pc], -r4 */
/* @0x14d64c ldrsheq r10, [lr], -r0 */
/* @0x14d650 andseq r6, pc, r8, lsr #22 */

/* ── FUNC 0x14d654 · F_PhysicsSetParticleFlags(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x14d654 ldr r3, [pc, #0x64] */
/* @0x14d658 push {r4, r5, r6, lr} */
/* @0x14d65c ldr r3, [pc, r3] */
/* @0x14d660 ldr r4, [sp, #0x10] */
/* @0x14d664 ldr r3, [r3] */
/* @0x14d668 cmp r3, #0 */
/* @0x14d66c beq 0x14d6ac <_Z25F_PhysicsSetParticleFlagsR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x14d670 ldr r5, [r3, #0xb4] */
/* @0x14d674 cmp r5, #0 */
/* @0x14d678 beq 0x14d6ac <_Z25F_PhysicsSetParticleFlagsR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x14d67c mov r0, r4 */
/* @0x14d680 mov r1, #0 */
/* @0x14d684 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14d688 mov r1, #1 */
/* @0x14d68c mov r6, r0 */
/* @0x14d690 mov r0, r4 */
/* @0x14d694 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x14d698 mov r1, r6 */
/* @0x14d69c mov r2, r0 */
/* @0x14d6a0 mov r0, r5 */
/* @0x14d6a4 pop {r4, r5, r6, lr} */
/* @0x14d6a8 b 0x23a160 <_ZN13CPhysicsWorld16SetParticleFlagsEij> */
/* @0x14d6ac ldr r0, [pc, #0x10] */
/* @0x14d6b0 mov r1, #0 */
/* @0x14d6b4 pop {r4, r5, r6, lr} */
/* @0x14d6b8 add r0, pc, r0 */
/* @0x14d6bc b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14d6c0 eoreq r0, r10, r12, asr #5 */
/* @0x14d6c4 andseq r6, pc, r0, lsl #22 */

/* ── FUNC 0x14d6c8 · F_PhysicsSetParticleCategoryFlags(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x14d6c8 ldr r3, [pc, #0x64] */
/* @0x14d6cc push {r4, r5, r6, lr} */
/* @0x14d6d0 ldr r3, [pc, r3] */
/* @0x14d6d4 ldr r4, [sp, #0x10] */
/* @0x14d6d8 ldr r3, [r3] */
/* @0x14d6dc cmp r3, #0 */
/* @0x14d6e0 beq 0x14d720 <_Z33F_PhysicsSetParticleCategoryFlagsR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x14d6e4 ldr r5, [r3, #0xb4] */
/* @0x14d6e8 cmp r5, #0 */
/* @0x14d6ec beq 0x14d720 <_Z33F_PhysicsSetParticleCategoryFlagsR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x14d6f0 mov r0, r4 */
/* @0x14d6f4 mov r1, #0 */
/* @0x14d6f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14d6fc mov r1, #1 */
/* @0x14d700 mov r6, r0 */
/* @0x14d704 mov r0, r4 */
/* @0x14d708 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x14d70c mov r1, r6 */
/* @0x14d710 mov r2, r0 */
/* @0x14d714 mov r0, r5 */
/* @0x14d718 pop {r4, r5, r6, lr} */
/* @0x14d71c b 0x23a194 <_ZN13CPhysicsWorld24SetParticleCategoryFlagsEij> */
/* @0x14d720 ldr r0, [pc, #0x10] */
/* @0x14d724 mov r1, #0 */
/* @0x14d728 pop {r4, r5, r6, lr} */
/* @0x14d72c add r0, pc, r0 */
/* @0x14d730 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14d734 eoreq r0, r10, r8, asr r2 */
/* @0x14d738 andseq r6, pc, r12, lsl #21 */

/* ── FUNC 0x14d73c · F_PhysicsSetParticleGroupFlags(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x14d73c ldr r3, [pc, #0x64] */
/* @0x14d740 push {r4, r5, r6, lr} */
/* @0x14d744 ldr r3, [pc, r3] */
/* @0x14d748 ldr r4, [sp, #0x10] */
/* @0x14d74c ldr r3, [r3] */
/* @0x14d750 cmp r3, #0 */
/* @0x14d754 beq 0x14d794 <_Z30F_PhysicsSetParticleGroupFlagsR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x14d758 ldr r5, [r3, #0xb4] */
/* @0x14d75c cmp r5, #0 */
/* @0x14d760 beq 0x14d794 <_Z30F_PhysicsSetParticleGroupFlagsR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x14d764 mov r0, r4 */
/* @0x14d768 mov r1, #0 */
/* @0x14d76c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14d770 mov r1, #1 */
/* @0x14d774 mov r6, r0 */
/* @0x14d778 mov r0, r4 */
/* @0x14d77c bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x14d780 mov r1, r6 */
/* @0x14d784 mov r2, r0 */
/* @0x14d788 mov r0, r5 */
/* @0x14d78c pop {r4, r5, r6, lr} */
/* @0x14d790 b 0x23a210 <_ZN13CPhysicsWorld21SetParticleGroupFlagsEij> */
/* @0x14d794 ldr r0, [pc, #0x10] */
/* @0x14d798 mov r1, #0 */
/* @0x14d79c pop {r4, r5, r6, lr} */
/* @0x14d7a0 add r0, pc, r0 */
/* @0x14d7a4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14d7a8 eoreq r0, r10, r4, ror #3 */
/* @0x14d7ac andseq r6, pc, r8, lsl r10 */

/* ── FUNC 0x14d7b0 · F_PhysicsGetParticleGroupFlags(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x14d7b0 push {r3, r4, r5, lr} */
/* @0x14d7b4 mov r1, #0 */
/* @0x14d7b8 ldr r3, [pc, #0x74] */
/* @0x14d7bc mov r4, r0 */
/* @0x14d7c0 str r1, [r0] */
/* @0x14d7c4 mov r2, r1 */
/* @0x14d7c8 ldr r3, [pc, r3] */
/* @0x14d7cc str r1, [r0, #0xc] */
/* @0x14d7d0 movt r2, #0xbff0 */
/* @0x14d7d4 str r2, [r0, #0x4] */
/* @0x14d7d8 ldr r3, [r3] */
/* @0x14d7dc ldr r0, [sp, #0x10] */
/* @0x14d7e0 cmp r3, r1 */
/* @0x14d7e4 beq 0x14d820 <_Z30F_PhysicsGetParticleGroupFlagsR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14d7e8 ldr r5, [r3, #0xb4] */
/* @0x14d7ec cmp r5, r1 */
/* @0x14d7f0 beq 0x14d820 <_Z30F_PhysicsGetParticleGroupFlagsR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14d7f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14d7f8 mov r1, r0 */
/* @0x14d7fc mov r0, r5 */
/* @0x14d800 bl 0x23a230 <_ZN13CPhysicsWorld21GetParticleGroupFlagsEi> */
/* @0x14d804 vmov s15, r0 */
/* @0x14d808 vcvt.f64.s32 d7, s15 */
/* @0x14d80c vmov r0, r1, d7 */
/* @0x14d810 vmov r2, s14 */
/* @0x14d814 mov r3, r1 */
/* @0x14d818 stm r4, {r2, r3} */
/* @0x14d81c pop {r3, r4, r5, pc} */
/* @0x14d820 ldr r0, [pc, #0x10] */
/* @0x14d824 mov r1, #0 */
/* @0x14d828 pop {r3, r4, r5, lr} */
/* @0x14d82c add r0, pc, r0 */
/* @0x14d830 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14d834 eoreq r0, r10, r0, ror #2 */
/* @0x14d838 andseq r6, pc, r12, ror #14 */

/* ── FUNC 0x14d83c · F_PhysicsBeginParticleGroup(RValue&, CInstance*, CInstance*, int, RValue*) · size=352 · insn=88 */
/* @0x14d83c ldr r3, [pc, #0x150] */
/* @0x14d840 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x14d844 ldr r3, [pc, r3] */
/* @0x14d848 sub sp, sp, #68 */
/* @0x14d84c ldr r3, [r3] */
/* @0x14d850 ldr r4, [sp, #0x68] */
/* @0x14d854 cmp r3, #0 */
/* @0x14d858 beq 0x14d97c <_Z27F_PhysicsBeginParticleGroupR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x14d85c ldr r5, [r3, #0xb4] */
/* @0x14d860 cmp r5, #0 */
/* @0x14d864 beq 0x14d97c <_Z27F_PhysicsBeginParticleGroupR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x14d868 mov r0, r4 */
/* @0x14d86c mov r1, #0 */
/* @0x14d870 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x14d874 mov r1, #1 */
/* @0x14d878 mov r6, r0 */
/* @0x14d87c mov r0, r4 */
/* @0x14d880 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x14d884 mov r1, #2 */
/* @0x14d888 mov r2, r0 */
/* @0x14d88c mov r0, r4 */
/* @0x14d890 str r2, [sp, #0x2c] */
/* @0x14d894 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d898 mov r1, #3 */
/* @0x14d89c mov r3, r0 */
/* @0x14d8a0 mov r0, r4 */
/* @0x14d8a4 str r3, [sp, #0x30] */
/* @0x14d8a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d8ac mov r1, #4 */
/* @0x14d8b0 mov r12, r0 */
/* @0x14d8b4 mov r0, r4 */
/* @0x14d8b8 str r12, [sp, #0x34] */
/* @0x14d8bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d8c0 mov r1, #5 */
/* @0x14d8c4 str r0, [sp, #0x38] */
/* @0x14d8c8 mov r0, r4 */
/* @0x14d8cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d8d0 mov r1, #6 */
/* @0x14d8d4 str r0, [sp, #0x3c] */
/* @0x14d8d8 mov r0, r4 */
/* @0x14d8dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d8e0 mov r1, #7 */
/* @0x14d8e4 mov r11, r0 */
/* @0x14d8e8 mov r0, r4 */
/* @0x14d8ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d8f0 mov r1, #8 */
/* @0x14d8f4 mov r10, r0 */
/* @0x14d8f8 mov r0, r4 */
/* @0x14d8fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14d900 mov r1, #9 */
/* @0x14d904 mov r9, r0 */
/* @0x14d908 mov r0, r4 */
/* @0x14d90c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d910 mov r1, #10 */
/* @0x14d914 mov r8, r0 */
/* @0x14d918 mov r0, r4 */
/* @0x14d91c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d920 mov r1, #11 */
/* @0x14d924 mov r7, r0 */
/* @0x14d928 mov r0, r4 */
/* @0x14d92c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14d930 ldr r1, [sp, #0x38] */
/* @0x14d934 ldr r12, [sp, #0x34] */
/* @0x14d938 str r11, [sp, #0xc] */
/* @0x14d93c str r1, [sp, #0x4] */
/* @0x14d940 ldr r1, [sp, #0x3c] */
/* @0x14d944 str r12, [sp] */
/* @0x14d948 str r10, [sp, #0x10] */
/* @0x14d94c str r1, [sp, #0x8] */
/* @0x14d950 mov r1, r6 */
/* @0x14d954 str r9, [sp, #0x14] */
/* @0x14d958 str r8, [sp, #0x18] */
/* @0x14d95c str r7, [sp, #0x1c] */
/* @0x14d960 ldr r2, [sp, #0x2c] */
/* @0x14d964 ldr r3, [sp, #0x30] */
/* @0x14d968 str r0, [sp, #0x20] */
/* @0x14d96c mov r0, r5 */
/* @0x14d970 bl 0x2399a8 <_ZN13CPhysicsWorld18BeginParticleGroupEjjffffffjffi> */
/* @0x14d974 add sp, sp, #68 */
/* @0x14d978 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x14d97c ldr r0, [pc, #0x14] */
/* @0x14d980 mov r1, #0 */
/* @0x14d984 add r0, pc, r0 */
/* @0x14d988 add sp, sp, #68 */
/* @0x14d98c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x14d990 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14d994 eoreq r0, r10, r4, ror #1 */
/* @0x14d998 mulseq pc, r4, r8 */

/* ── FUNC 0x14d99c · F_PhysicsParticleGroupSetCircle(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x14d99c ldr r3, [pc, #0x4c] */
/* @0x14d9a0 push {r4, lr} */
/* @0x14d9a4 ldr r3, [pc, r3] */
/* @0x14d9a8 ldr r0, [sp, #0x8] */
/* @0x14d9ac ldr r3, [r3] */
/* @0x14d9b0 cmp r3, #0 */
/* @0x14d9b4 beq 0x14d9dc <_Z31F_PhysicsParticleGroupSetCircleR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x14d9b8 ldr r4, [r3, #0xb4] */
/* @0x14d9bc cmp r4, #0 */
/* @0x14d9c0 beq 0x14d9dc <_Z31F_PhysicsParticleGroupSetCircleR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x14d9c4 mov r1, #0 */
/* @0x14d9c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d9cc mov r1, r0 */
/* @0x14d9d0 mov r0, r4 */
/* @0x14d9d4 pop {r4, lr} */
/* @0x14d9d8 b 0x239a6c <_ZN13CPhysicsWorld19ParticleGroupCircleEf> */
/* @0x14d9dc ldr r0, [pc, #0x10] */
/* @0x14d9e0 mov r1, #0 */
/* @0x14d9e4 pop {r4, lr} */
/* @0x14d9e8 add r0, pc, r0 */
/* @0x14d9ec b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14d9f0 eoreq pc, r9, r4, lsl #31 */
/* @0x14d9f4 mulseq pc, r0, r8 */

/* ── FUNC 0x14d9f8 · F_PhysicsParticleGroupSetBox(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x14d9f8 ldr r3, [pc, #0x64] */
/* @0x14d9fc push {r4, r5, r6, lr} */
/* @0x14da00 ldr r3, [pc, r3] */
/* @0x14da04 ldr r4, [sp, #0x10] */
/* @0x14da08 ldr r3, [r3] */
/* @0x14da0c cmp r3, #0 */
/* @0x14da10 beq 0x14da50 <_Z28F_PhysicsParticleGroupSetBoxR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x14da14 ldr r5, [r3, #0xb4] */
/* @0x14da18 cmp r5, #0 */
/* @0x14da1c beq 0x14da50 <_Z28F_PhysicsParticleGroupSetBoxR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x14da20 mov r0, r4 */
/* @0x14da24 mov r1, #0 */
/* @0x14da28 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14da2c mov r1, #1 */
/* @0x14da30 mov r6, r0 */
/* @0x14da34 mov r0, r4 */
/* @0x14da38 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14da3c mov r1, r6 */
/* @0x14da40 mov r2, r0 */
/* @0x14da44 mov r0, r5 */
/* @0x14da48 pop {r4, r5, r6, lr} */
/* @0x14da4c b 0x239ae4 <_ZN13CPhysicsWorld16ParticleGroupBoxEff> */
/* @0x14da50 ldr r0, [pc, #0x10] */
/* @0x14da54 mov r1, #0 */
/* @0x14da58 pop {r4, r5, r6, lr} */
/* @0x14da5c add r0, pc, r0 */
/* @0x14da60 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14da64 eoreq pc, r9, r8, lsr #30 */
/* @0x14da68 andseq r6, pc, r12, ror r8 */

/* ── FUNC 0x14da6c · F_PhysicsParticleGroupSetPoly(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x14da6c ldr r3, [pc, #0x2c] */
/* @0x14da70 ldr r3, [pc, r3] */
/* @0x14da74 ldr r3, [r3] */
/* @0x14da78 cmp r3, #0 */
/* @0x14da7c beq 0x14da90 <_Z29F_PhysicsParticleGroupSetPolyR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x14da80 ldr r0, [r3, #0xb4] */
/* @0x14da84 cmp r0, #0 */
/* @0x14da88 beq 0x14da90 <_Z29F_PhysicsParticleGroupSetPolyR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x14da8c b 0x239b98 <_ZN13CPhysicsWorld17ParticleGroupPolyEv> */
/* @0x14da90 ldr r0, [pc, #0xc] */
/* @0x14da94 mov r1, #0 */
/* @0x14da98 add r0, pc, r0 */
/* @0x14da9c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14daa0 .word 0x0029feb8 */
/* @0x14daa4 mulseq pc, r12, r8 */

/* ── FUNC 0x14daa8 · F_PhysicsParticleGroupAddPoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x14daa8 ldr r3, [pc, #0x64] */
/* @0x14daac push {r4, r5, r6, lr} */
/* @0x14dab0 ldr r3, [pc, r3] */
/* @0x14dab4 ldr r4, [sp, #0x10] */
/* @0x14dab8 ldr r3, [r3] */
/* @0x14dabc cmp r3, #0 */
/* @0x14dac0 beq 0x14db00 <_Z30F_PhysicsParticleGroupAddPointR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x14dac4 ldr r5, [r3, #0xb4] */
/* @0x14dac8 cmp r5, #0 */
/* @0x14dacc beq 0x14db00 <_Z30F_PhysicsParticleGroupAddPointR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x14dad0 mov r0, r4 */
/* @0x14dad4 mov r1, #0 */
/* @0x14dad8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14dadc mov r1, #1 */
/* @0x14dae0 mov r6, r0 */
/* @0x14dae4 mov r0, r4 */
/* @0x14dae8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14daec mov r1, r6 */
/* @0x14daf0 mov r2, r0 */
/* @0x14daf4 mov r0, r5 */
/* @0x14daf8 pop {r4, r5, r6, lr} */
/* @0x14dafc b 0x239c08 <_ZN13CPhysicsWorld21ParticleGroupAddPointEff> */
/* @0x14db00 ldr r0, [pc, #0x10] */
/* @0x14db04 mov r1, #0 */
/* @0x14db08 pop {r4, r5, r6, lr} */
/* @0x14db0c add r0, pc, r0 */
/* @0x14db10 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14db14 eoreq pc, r9, r8, ror lr */
/* @0x14db18 andseq r6, pc, r8, lsl #17 */

/* ── FUNC 0x14db1c · F_PhysicsEndParticleGroup(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x14db1c ldr r3, [pc, #0x6c] */
/* @0x14db20 mov r1, #0 */
/* @0x14db24 push {r4, lr} */
/* @0x14db28 ldr r3, [pc, r3] */
/* @0x14db2c str r1, [r0] */
/* @0x14db30 mov r2, r1 */
/* @0x14db34 ldr r3, [r3] */
/* @0x14db38 movt r2, #0xbff0 */
/* @0x14db3c mov r4, r0 */
/* @0x14db40 str r1, [r0, #0xc] */
/* @0x14db44 cmp r3, r1 */
/* @0x14db48 str r2, [r0, #0x4] */
/* @0x14db4c beq 0x14db7c <_Z25F_PhysicsEndParticleGroupR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x14db50 ldr r0, [r3, #0xb4] */
/* @0x14db54 cmp r0, r1 */
/* @0x14db58 beq 0x14db7c <_Z25F_PhysicsEndParticleGroupR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x14db5c bl 0x239d30 <_ZN13CPhysicsWorld16EndParticleGroupEv> */
/* @0x14db60 vmov s15, r0 */
/* @0x14db64 vcvt.f64.s32 d7, s15 */
/* @0x14db68 vmov r0, r1, d7 */
/* @0x14db6c vmov r2, s14 */
/* @0x14db70 mov r3, r1 */
/* @0x14db74 stm r4, {r2, r3} */
/* @0x14db78 pop {r4, pc} */
/* @0x14db7c ldr r0, [pc, #0x10] */
/* @0x14db80 mov r1, #0 */
/* @0x14db84 pop {r4, lr} */
/* @0x14db88 add r0, pc, r0 */
/* @0x14db8c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14db90 eoreq pc, r9, r0, lsl #28 */
/* @0x14db94 andseq r6, pc, r0, ror r8 */

/* ── FUNC 0x14db98 · F_PhysicsJoinParticleGroups(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x14db98 ldr r3, [pc, #0x64] */
/* @0x14db9c push {r4, r5, r6, lr} */
/* @0x14dba0 ldr r3, [pc, r3] */
/* @0x14dba4 ldr r4, [sp, #0x10] */
/* @0x14dba8 ldr r3, [r3] */
/* @0x14dbac cmp r3, #0 */
/* @0x14dbb0 beq 0x14dbf0 <_Z27F_PhysicsJoinParticleGroupsR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x14dbb4 ldr r5, [r3, #0xb4] */
/* @0x14dbb8 cmp r5, #0 */
/* @0x14dbbc beq 0x14dbf0 <_Z27F_PhysicsJoinParticleGroupsR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x14dbc0 mov r0, r4 */
/* @0x14dbc4 mov r1, #0 */
/* @0x14dbc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14dbcc mov r1, #1 */
/* @0x14dbd0 mov r6, r0 */
/* @0x14dbd4 mov r0, r4 */
/* @0x14dbd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14dbdc mov r1, r6 */
/* @0x14dbe0 mov r2, r0 */
/* @0x14dbe4 mov r0, r5 */
/* @0x14dbe8 pop {r4, r5, r6, lr} */
/* @0x14dbec b 0x239de8 <_ZN13CPhysicsWorld18JoinParticleGroupsEii> */
/* @0x14dbf0 ldr r0, [pc, #0x10] */
/* @0x14dbf4 mov r1, #0 */
/* @0x14dbf8 pop {r4, r5, r6, lr} */
/* @0x14dbfc add r0, pc, r0 */
/* @0x14dc00 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14dc04 eoreq pc, r9, r8, lsl #27 */
/* @0x14dc08 andseq r6, pc, r8, asr r8 */

/* ── FUNC 0x14dc0c · F_PhysicsDeleteParticleGroup(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x14dc0c ldr r3, [pc, #0x4c] */
/* @0x14dc10 push {r4, lr} */
/* @0x14dc14 ldr r3, [pc, r3] */
/* @0x14dc18 ldr r0, [sp, #0x8] */
/* @0x14dc1c ldr r3, [r3] */
/* @0x14dc20 cmp r3, #0 */
/* @0x14dc24 beq 0x14dc4c <_Z28F_PhysicsDeleteParticleGroupR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x14dc28 ldr r4, [r3, #0xb4] */
/* @0x14dc2c cmp r4, #0 */
/* @0x14dc30 beq 0x14dc4c <_Z28F_PhysicsDeleteParticleGroupR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x14dc34 mov r1, #0 */
/* @0x14dc38 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14dc3c mov r1, r0 */
/* @0x14dc40 mov r0, r4 */
/* @0x14dc44 pop {r4, lr} */
/* @0x14dc48 b 0x239e34 <_ZN13CPhysicsWorld19DeleteParticleGroupEi> */
/* @0x14dc4c ldr r0, [pc, #0x10] */
/* @0x14dc50 mov r1, #0 */
/* @0x14dc54 pop {r4, lr} */
/* @0x14dc58 add r0, pc, r0 */
/* @0x14dc5c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14dc60 eoreq pc, r9, r4, lsl sp */
/* @0x14dc64 andseq r6, pc, r0, ror #10 */

/* ── FUNC 0x14dc68 · F_PhysicsDrawParticles(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x14dc68 push {r4, r5, r6, r7, r8, lr} */
/* @0x14dc6c ldr r4, [pc, #0x9c] */
/* @0x14dc70 ldr r5, [sp, #0x18] */
/* @0x14dc74 ldr r4, [pc, r4] */
/* @0x14dc78 ldr r3, [r4] */
/* @0x14dc7c cmp r3, #0 */
/* @0x14dc80 beq 0x14dcf8 <_Z22F_PhysicsDrawParticlesR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x14dc84 ldr r3, [r3, #0xb4] */
/* @0x14dc88 cmp r3, #0 */
/* @0x14dc8c beq 0x14dcf8 <_Z22F_PhysicsDrawParticlesR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x14dc90 mov r1, #2 */
/* @0x14dc94 mov r0, r5 */
/* @0x14dc98 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14dc9c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x14dca0 subs r6, r0, #0 */
/* @0x14dca4 beq 0x14dd0c <_Z22F_PhysicsDrawParticlesR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x14dca8 ldr r3, [r4] */
/* @0x14dcac mov r0, r5 */
/* @0x14dcb0 mov r1, #0 */
/* @0x14dcb4 ldr r4, [r3, #0xb4] */
/* @0x14dcb8 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x14dcbc mov r1, #1 */
/* @0x14dcc0 mov r8, r0 */
/* @0x14dcc4 mov r0, r5 */
/* @0x14dcc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14dccc mov r1, #3 */
/* @0x14dcd0 mov r7, r0 */
/* @0x14dcd4 mov r0, r5 */
/* @0x14dcd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14dcdc mov r1, r8 */
/* @0x14dce0 mov r2, r7 */
/* @0x14dce4 mov r3, r6 */
/* @0x14dce8 str r0, [sp, #0x18] */
/* @0x14dcec mov r0, r4 */
/* @0x14dcf0 pop {r4, r5, r6, r7, r8, lr} */
/* @0x14dcf4 b 0x23a8c0 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei> */
/* @0x14dcf8 ldr r0, [pc, #0x14] */
/* @0x14dcfc mov r1, #0 */
/* @0x14dd00 pop {r4, r5, r6, r7, r8, lr} */
/* @0x14dd04 add r0, pc, r0 */
/* @0x14dd08 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14dd0c pop {r4, r5, r6, r7, r8, pc} */
/* @0x14dd10 .word 0x0029fcb4 */
/* @0x14dd14 andseq r6, pc, r12, lsr #15 */

/* ── FUNC 0x14dd18 · F_PhysicsDrawParticlesExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=328 · insn=82 */
/* @0x14dd18 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x14dd1c vpush {d8} */
/* @0x14dd20 sub sp, sp, #36 */
/* @0x14dd24 ldr r5, [pc, #0x12c] */
/* @0x14dd28 ldr r4, [sp, #0x50] */
/* @0x14dd2c ldr r5, [pc, r5] */
/* @0x14dd30 ldr r3, [r5] */
/* @0x14dd34 cmp r3, #0 */
/* @0x14dd38 beq 0x14de34 <_Z25F_PhysicsDrawParticlesExtR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x14dd3c ldr r3, [r3, #0xb4] */
/* @0x14dd40 cmp r3, #0 */
/* @0x14dd44 beq 0x14de34 <_Z25F_PhysicsDrawParticlesExtR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x14dd48 mov r1, #2 */
/* @0x14dd4c mov r0, r4 */
/* @0x14dd50 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14dd54 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x14dd58 subs r6, r0, #0 */
/* @0x14dd5c beq 0x14de28 <_Z25F_PhysicsDrawParticlesExtR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x14dd60 ldr r3, [r5] */
/* @0x14dd64 mov r1, #0 */
/* @0x14dd68 mov r0, r4 */
/* @0x14dd6c ldr r5, [r3, #0xb4] */
/* @0x14dd70 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x14dd74 mov r1, #1 */
/* @0x14dd78 mov r8, r0 */
/* @0x14dd7c mov r0, r4 */
/* @0x14dd80 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14dd84 mov r1, #3 */
/* @0x14dd88 mov r7, r0 */
/* @0x14dd8c mov r0, r4 */
/* @0x14dd90 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14dd94 mov r1, #4 */
/* @0x14dd98 mov r3, r0 */
/* @0x14dd9c mov r0, r4 */
/* @0x14dda0 str r3, [sp, #0x1c] */
/* @0x14dda4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14dda8 mov r1, #5 */
/* @0x14ddac mov r11, r0 */
/* @0x14ddb0 mov r0, r4 */
/* @0x14ddb4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14ddb8 mov r1, #6 */
/* @0x14ddbc mov r10, r0 */
/* @0x14ddc0 mov r0, r4 */
/* @0x14ddc4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14ddc8 mov r1, #7 */
/* @0x14ddcc vmov s16, r0 */
/* @0x14ddd0 mov r0, r4 */
/* @0x14ddd4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14ddd8 mov r1, #8 */
/* @0x14dddc mov r9, r0 */
/* @0x14dde0 mov r0, r4 */
/* @0x14dde4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14dde8 vldr s15, [pc, #96] */
/* @0x14ddec vmul.f32 s16, s16, s15 */
/* @0x14ddf0 vldr s15, [pc, #92] */
/* @0x14ddf4 ldr r3, [sp, #0x1c] */
/* @0x14ddf8 mov r1, r8 */
/* @0x14ddfc str r11, [sp, #0x4] */
/* @0x14de00 mov r2, r7 */
/* @0x14de04 str r10, [sp, #0x8] */
/* @0x14de08 str r3, [sp] */
/* @0x14de0c mov r3, r6 */
/* @0x14de10 str r9, [sp, #0x10] */
/* @0x14de14 vdiv.f32 s16, s16, s15 */
/* @0x14de18 str r0, [sp, #0x14] */
/* @0x14de1c mov r0, r5 */
/* @0x14de20 vstr s16, [sp, #12] */
/* @0x14de24 bl 0x23acf4 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf> */
/* @0x14de28 add sp, sp, #36 */
/* @0x14de2c vpop {d8} */
/* @0x14de30 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x14de34 ldr r0, [pc, #0x20] */
/* @0x14de38 mov r1, #0 */
/* @0x14de3c add r0, pc, r0 */
/* @0x14de40 add sp, sp, #36 */
/* @0x14de44 vpop {d8} */
/* @0x14de48 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x14de4c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14de50 ldrdmi r0, r1, [r9], #-251 */
/* @0x14de54 teqmi r4, #0 */
/* @0x14de58 .word 0x0029fbfc */
/* @0x14de5c andseq r6, pc, r4, ror r6 */

/* ── FUNC 0x14de60 · F_PhysicsParticleCount(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x14de60 ldr r3, [pc, #0x64] */
/* @0x14de64 mov r1, #0 */
/* @0x14de68 str r1, [r0] */
/* @0x14de6c mov r2, r1 */
/* @0x14de70 ldr r3, [pc, r3] */
/* @0x14de74 movt r2, #0xbff0 */
/* @0x14de78 str r1, [r0, #0xc] */
/* @0x14de7c ldr r3, [r3] */
/* @0x14de80 str r2, [r0, #0x4] */
/* @0x14de84 cmp r3, r1 */
/* @0x14de88 beq 0x14debc <_Z22F_PhysicsParticleCountR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x14de8c ldr r3, [r3, #0xb4] */
/* @0x14de90 cmp r3, r1 */
/* @0x14de94 beq 0x14debc <_Z22F_PhysicsParticleCountR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x14de98 ldr r2, [r3, #0x10] */
/* @0x14de9c movw r3, #0x9298 */
/* @0x14dea0 movt r3, #0x1 */
/* @0x14dea4 ldr r2, [r2, r3] */
/* @0x14dea8 vmov s15, r2 */
/* @0x14deac vcvt.f64.s32 d7, s15 */
/* @0x14deb0 vmov r2, r3, d7 */
/* @0x14deb4 stm r0, {r2, r3} */
/* @0x14deb8 bx lr */
/* @0x14debc ldr r0, [pc, #0xc] */
/* @0x14dec0 mov r1, #0 */
/* @0x14dec4 add r0, pc, r0 */
/* @0x14dec8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14decc .word 0x0029fab8 */
/* @0x14ded0 andseq r6, pc, r4, asr #12 */

/* ── FUNC 0x14ded4 · F_PhysicsParticleData(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x14ded4 push {r4, r5, r6, lr} */
/* @0x14ded8 mov r1, #0 */
/* @0x14dedc ldr r4, [pc, #0x94] */
/* @0x14dee0 mov r3, r1 */
/* @0x14dee4 str r1, [r0] */
/* @0x14dee8 movt r3, #0xbff0 */
/* @0x14deec ldr r4, [pc, r4] */
/* @0x14def0 str r1, [r0, #0xc] */
/* @0x14def4 str r3, [r0, #0x4] */
/* @0x14def8 ldr r2, [r4] */
/* @0x14defc ldr r5, [sp, #0x10] */
/* @0x14df00 cmp r2, r1 */
/* @0x14df04 beq 0x14df50 <_Z21F_PhysicsParticleDataR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x14df08 ldr r3, [r2, #0xb4] */
/* @0x14df0c cmp r3, r1 */
/* @0x14df10 beq 0x14df50 <_Z21F_PhysicsParticleDataR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x14df14 mov r0, r5 */
/* @0x14df18 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14df1c bl 0xc6720 <_Z10GetIBufferi> */
/* @0x14df20 subs r6, r0, #0 */
/* @0x14df24 beq 0x14df64 <_Z21F_PhysicsParticleDataR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x14df28 ldr r3, [r4] */
/* @0x14df2c mov r0, r5 */
/* @0x14df30 mov r1, #1 */
/* @0x14df34 ldr r4, [r3, #0xb4] */
/* @0x14df38 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x14df3c mov r1, r6 */
/* @0x14df40 mov r2, r0 */
/* @0x14df44 mov r0, r4 */
/* @0x14df48 pop {r4, r5, r6, lr} */
/* @0x14df4c b 0x23a57c <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferj> */
/* @0x14df50 ldr r0, [pc, #0x24] */
/* @0x14df54 mov r1, #0 */
/* @0x14df58 pop {r4, r5, r6, lr} */
/* @0x14df5c add r0, pc, r0 */
/* @0x14df60 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14df64 ldr r0, [pc, #0x14] */
/* @0x14df68 mov r1, r6 */
/* @0x14df6c pop {r4, r5, r6, lr} */
/* @0x14df70 add r0, pc, r0 */
/* @0x14df74 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14df78 eoreq pc, r9, r12, lsr r10 */
/* @0x14df7c andseq r6, pc, r4, lsl #12 */
/* @0x14df80 andseq r2, lr, r4, asr #24 */

/* ── FUNC 0x14df84 · F_PhysicsParticleDataParticle(RValue&, CInstance*, CInstance*, int, RValue*) · size=200 · insn=50 */
/* @0x14df84 push {r4, r5, r6, r7, r8, lr} */
/* @0x14df88 mov r5, #0 */
/* @0x14df8c ldr r4, [pc, #0xac] */
/* @0x14df90 mov r3, r5 */
/* @0x14df94 str r5, [r0] */
/* @0x14df98 movt r3, #0xbff0 */
/* @0x14df9c ldr r4, [pc, r4] */
/* @0x14dfa0 str r5, [r0, #0xc] */
/* @0x14dfa4 str r3, [r0, #0x4] */
/* @0x14dfa8 ldr r2, [r4] */
/* @0x14dfac ldr r6, [sp, #0x18] */
/* @0x14dfb0 cmp r2, r5 */
/* @0x14dfb4 beq 0x14e018 <_Z29F_PhysicsParticleDataParticleR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x14dfb8 ldr r3, [r2, #0xb4] */
/* @0x14dfbc cmp r3, r5 */
/* @0x14dfc0 beq 0x14e018 <_Z29F_PhysicsParticleDataParticleR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x14dfc4 mov r1, #1 */
/* @0x14dfc8 mov r0, r6 */
/* @0x14dfcc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14dfd0 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x14dfd4 subs r7, r0, #0 */
/* @0x14dfd8 beq 0x14e02c <_Z29F_PhysicsParticleDataParticleR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x14dfdc ldr r3, [r4] */
/* @0x14dfe0 mov r1, r5 */
/* @0x14dfe4 mov r0, r6 */
/* @0x14dfe8 ldr r5, [r3, #0xb4] */
/* @0x14dfec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14dff0 mov r1, #2 */
/* @0x14dff4 mov r4, r0 */
/* @0x14dff8 mov r0, r6 */
/* @0x14dffc bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x14e000 mov r1, r4 */
/* @0x14e004 mov r2, r7 */
/* @0x14e008 mov r3, r0 */
/* @0x14e00c mov r0, r5 */
/* @0x14e010 pop {r4, r5, r6, r7, r8, lr} */
/* @0x14e014 b 0x23a5a8 <_ZN13CPhysicsWorld23GetParticleDataParticleEiP7IBufferj> */
/* @0x14e018 ldr r0, [pc, #0x24] */
/* @0x14e01c mov r1, #0 */
/* @0x14e020 pop {r4, r5, r6, r7, r8, lr} */
/* @0x14e024 add r0, pc, r0 */
/* @0x14e028 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e02c ldr r0, [pc, #0x14] */
/* @0x14e030 mov r1, r7 */
/* @0x14e034 pop {r4, r5, r6, r7, r8, lr} */
/* @0x14e038 add r0, pc, r0 */
/* @0x14e03c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e040 eoreq pc, r9, r12, lsl #19 */
/* @0x14e044 mulseq pc, r4, r5 */
/* @0x14e048 andseq r2, lr, r12, ror r11 */

/* ── FUNC 0x14e04c · F_PhysicsParticleGroupCount(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x14e04c push {r3, r4, r5, lr} */
/* @0x14e050 mov r1, #0 */
/* @0x14e054 ldr r3, [pc, #0x74] */
/* @0x14e058 mov r4, r0 */
/* @0x14e05c str r1, [r0] */
/* @0x14e060 mov r2, r1 */
/* @0x14e064 ldr r3, [pc, r3] */
/* @0x14e068 str r1, [r0, #0xc] */
/* @0x14e06c movt r2, #0xbff0 */
/* @0x14e070 str r2, [r0, #0x4] */
/* @0x14e074 ldr r3, [r3] */
/* @0x14e078 ldr r0, [sp, #0x10] */
/* @0x14e07c cmp r3, r1 */
/* @0x14e080 beq 0x14e0bc <_Z27F_PhysicsParticleGroupCountR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e084 ldr r5, [r3, #0xb4] */
/* @0x14e088 cmp r5, r1 */
/* @0x14e08c beq 0x14e0bc <_Z27F_PhysicsParticleGroupCountR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e090 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14e094 mov r1, r0 */
/* @0x14e098 mov r0, r5 */
/* @0x14e09c bl 0x23a5d4 <_ZN13CPhysicsWorld21GetParticleGroupCountEi> */
/* @0x14e0a0 vmov s15, r0 */
/* @0x14e0a4 vcvt.f64.s32 d7, s15 */
/* @0x14e0a8 vmov r0, r1, d7 */
/* @0x14e0ac vmov r2, s14 */
/* @0x14e0b0 mov r3, r1 */
/* @0x14e0b4 stm r4, {r2, r3} */
/* @0x14e0b8 pop {r3, r4, r5, pc} */
/* @0x14e0bc ldr r0, [pc, #0x10] */
/* @0x14e0c0 mov r1, #0 */
/* @0x14e0c4 pop {r3, r4, r5, lr} */
/* @0x14e0c8 add r0, pc, r0 */
/* @0x14e0cc b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e0d0 eoreq pc, r9, r4, asr #17 */
/* @0x14e0d4 andseq r6, pc, r4, asr r5 */

/* ── FUNC 0x14e0d8 · F_PhysicsParticleDataGroup(RValue&, CInstance*, CInstance*, int, RValue*) · size=200 · insn=50 */
/* @0x14e0d8 push {r4, r5, r6, r7, r8, lr} */
/* @0x14e0dc mov r5, #0 */
/* @0x14e0e0 ldr r4, [pc, #0xac] */
/* @0x14e0e4 mov r3, r5 */
/* @0x14e0e8 str r5, [r0] */
/* @0x14e0ec movt r3, #0xbff0 */
/* @0x14e0f0 ldr r4, [pc, r4] */
/* @0x14e0f4 str r5, [r0, #0xc] */
/* @0x14e0f8 str r3, [r0, #0x4] */
/* @0x14e0fc ldr r2, [r4] */
/* @0x14e100 ldr r6, [sp, #0x18] */
/* @0x14e104 cmp r2, r5 */
/* @0x14e108 beq 0x14e16c <_Z26F_PhysicsParticleDataGroupR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x14e10c ldr r3, [r2, #0xb4] */
/* @0x14e110 cmp r3, r5 */
/* @0x14e114 beq 0x14e16c <_Z26F_PhysicsParticleDataGroupR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x14e118 mov r1, #1 */
/* @0x14e11c mov r0, r6 */
/* @0x14e120 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14e124 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x14e128 subs r7, r0, #0 */
/* @0x14e12c beq 0x14e180 <_Z26F_PhysicsParticleDataGroupR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x14e130 ldr r3, [r4] */
/* @0x14e134 mov r1, r5 */
/* @0x14e138 mov r0, r6 */
/* @0x14e13c ldr r5, [r3, #0xb4] */
/* @0x14e140 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14e144 mov r1, #2 */
/* @0x14e148 mov r4, r0 */
/* @0x14e14c mov r0, r6 */
/* @0x14e150 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x14e154 mov r1, r4 */
/* @0x14e158 mov r2, r7 */
/* @0x14e15c mov r3, r0 */
/* @0x14e160 mov r0, r5 */
/* @0x14e164 pop {r4, r5, r6, r7, r8, lr} */
/* @0x14e168 b 0x23a5f0 <_ZN13CPhysicsWorld20GetParticleDataGroupEiP7IBufferj> */
/* @0x14e16c ldr r0, [pc, #0x24] */
/* @0x14e170 mov r1, #0 */
/* @0x14e174 pop {r4, r5, r6, r7, r8, lr} */
/* @0x14e178 add r0, pc, r0 */
/* @0x14e17c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e180 ldr r0, [pc, #0x14] */
/* @0x14e184 mov r1, r7 */
/* @0x14e188 pop {r4, r5, r6, r7, r8, lr} */
/* @0x14e18c add r0, pc, r0 */
/* @0x14e190 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e194 eoreq pc, r9, r8, lsr r8 */
/* @0x14e198 andseq r6, pc, r4, lsl #10 */
/* @0x14e19c andseq r2, lr, r8, lsr #20 */

/* ── FUNC 0x14e1a0 · F_PhysicsParticleGroupMass(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x14e1a0 push {r3, r4, r5, lr} */
/* @0x14e1a4 mov r1, #0 */
/* @0x14e1a8 ldr r3, [pc, #0x74] */
/* @0x14e1ac mov r4, r0 */
/* @0x14e1b0 str r1, [r0] */
/* @0x14e1b4 mov r2, r1 */
/* @0x14e1b8 ldr r3, [pc, r3] */
/* @0x14e1bc str r1, [r0, #0xc] */
/* @0x14e1c0 movt r2, #0xbff0 */
/* @0x14e1c4 str r2, [r0, #0x4] */
/* @0x14e1c8 ldr r3, [r3] */
/* @0x14e1cc ldr r0, [sp, #0x10] */
/* @0x14e1d0 cmp r3, r1 */
/* @0x14e1d4 beq 0x14e210 <_Z26F_PhysicsParticleGroupMassR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e1d8 ldr r5, [r3, #0xb4] */
/* @0x14e1dc cmp r5, r1 */
/* @0x14e1e0 beq 0x14e210 <_Z26F_PhysicsParticleGroupMassR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e1e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14e1e8 mov r1, r0 */
/* @0x14e1ec mov r0, r5 */
/* @0x14e1f0 bl 0x23a648 <_ZN13CPhysicsWorld20GetParticleGroupMassEi> */
/* @0x14e1f4 vmov s15, r0 */
/* @0x14e1f8 vcvt.f64.f32 d7, s15 */
/* @0x14e1fc vmov r0, r1, d7 */
/* @0x14e200 vmov r2, s14 */
/* @0x14e204 mov r3, r1 */
/* @0x14e208 stm r4, {r2, r3} */
/* @0x14e20c pop {r3, r4, r5, pc} */
/* @0x14e210 ldr r0, [pc, #0x10] */
/* @0x14e214 mov r1, #0 */
/* @0x14e218 pop {r3, r4, r5, lr} */
/* @0x14e21c add r0, pc, r0 */
/* @0x14e220 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e224 eoreq pc, r9, r0, ror r7 */
/* @0x14e228 andseq r6, pc, r0, asr #9 */

/* ── FUNC 0x14e22c · F_PhysicsParticleGroupInertia(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x14e22c push {r3, r4, r5, lr} */
/* @0x14e230 mov r1, #0 */
/* @0x14e234 ldr r3, [pc, #0x74] */
/* @0x14e238 mov r4, r0 */
/* @0x14e23c str r1, [r0] */
/* @0x14e240 mov r2, r1 */
/* @0x14e244 ldr r3, [pc, r3] */
/* @0x14e248 str r1, [r0, #0xc] */
/* @0x14e24c movt r2, #0xbff0 */
/* @0x14e250 str r2, [r0, #0x4] */
/* @0x14e254 ldr r3, [r3] */
/* @0x14e258 ldr r0, [sp, #0x10] */
/* @0x14e25c cmp r3, r1 */
/* @0x14e260 beq 0x14e29c <_Z29F_PhysicsParticleGroupInertiaR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e264 ldr r5, [r3, #0xb4] */
/* @0x14e268 cmp r5, r1 */
/* @0x14e26c beq 0x14e29c <_Z29F_PhysicsParticleGroupInertiaR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e270 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14e274 mov r1, r0 */
/* @0x14e278 mov r0, r5 */
/* @0x14e27c bl 0x23a668 <_ZN13CPhysicsWorld23GetParticleGroupInertiaEi> */
/* @0x14e280 vmov s15, r0 */
/* @0x14e284 vcvt.f64.f32 d7, s15 */
/* @0x14e288 vmov r0, r1, d7 */
/* @0x14e28c vmov r2, s14 */
/* @0x14e290 mov r3, r1 */
/* @0x14e294 stm r4, {r2, r3} */
/* @0x14e298 pop {r3, r4, r5, pc} */
/* @0x14e29c ldr r0, [pc, #0x10] */
/* @0x14e2a0 mov r1, #0 */
/* @0x14e2a4 pop {r3, r4, r5, lr} */
/* @0x14e2a8 add r0, pc, r0 */
/* @0x14e2ac b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e2b0 eoreq pc, r9, r4, ror #13 */
/* @0x14e2b4 mulseq pc, r4, r4 */

/* ── FUNC 0x14e2b8 · F_PhysicsParticleGroupCentreX(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x14e2b8 push {r3, r4, r5, lr} */
/* @0x14e2bc mov r1, #0 */
/* @0x14e2c0 ldr r3, [pc, #0x74] */
/* @0x14e2c4 mov r4, r0 */
/* @0x14e2c8 str r1, [r0] */
/* @0x14e2cc mov r2, r1 */
/* @0x14e2d0 ldr r3, [pc, r3] */
/* @0x14e2d4 str r1, [r0, #0xc] */
/* @0x14e2d8 movt r2, #0xbff0 */
/* @0x14e2dc str r2, [r0, #0x4] */
/* @0x14e2e0 ldr r3, [r3] */
/* @0x14e2e4 ldr r0, [sp, #0x10] */
/* @0x14e2e8 cmp r3, r1 */
/* @0x14e2ec beq 0x14e328 <_Z29F_PhysicsParticleGroupCentreXR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e2f0 ldr r5, [r3, #0xb4] */
/* @0x14e2f4 cmp r5, r1 */
/* @0x14e2f8 beq 0x14e328 <_Z29F_PhysicsParticleGroupCentreXR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e2fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14e300 mov r1, r0 */
/* @0x14e304 mov r0, r5 */
/* @0x14e308 bl 0x23a688 <_ZN13CPhysicsWorld23GetParticleGroupCentreXEi> */
/* @0x14e30c vmov s15, r0 */
/* @0x14e310 vcvt.f64.f32 d7, s15 */
/* @0x14e314 vmov r0, r1, d7 */
/* @0x14e318 vmov r2, s14 */
/* @0x14e31c mov r3, r1 */
/* @0x14e320 stm r4, {r2, r3} */
/* @0x14e324 pop {r3, r4, r5, pc} */
/* @0x14e328 ldr r0, [pc, #0x10] */
/* @0x14e32c mov r1, #0 */
/* @0x14e330 pop {r3, r4, r5, lr} */
/* @0x14e334 add r0, pc, r0 */
/* @0x14e338 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e33c eoreq pc, r9, r8, asr r6 */
/* @0x14e340 andseq r6, pc, r12, ror #8 */

/* ── FUNC 0x14e344 · F_PhysicsParticleGroupCentreY(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x14e344 push {r3, r4, r5, lr} */
/* @0x14e348 mov r1, #0 */
/* @0x14e34c ldr r3, [pc, #0x74] */
/* @0x14e350 mov r4, r0 */
/* @0x14e354 str r1, [r0] */
/* @0x14e358 mov r2, r1 */
/* @0x14e35c ldr r3, [pc, r3] */
/* @0x14e360 str r1, [r0, #0xc] */
/* @0x14e364 movt r2, #0xbff0 */
/* @0x14e368 str r2, [r0, #0x4] */
/* @0x14e36c ldr r3, [r3] */
/* @0x14e370 ldr r0, [sp, #0x10] */
/* @0x14e374 cmp r3, r1 */
/* @0x14e378 beq 0x14e3b4 <_Z29F_PhysicsParticleGroupCentreYR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e37c ldr r5, [r3, #0xb4] */
/* @0x14e380 cmp r5, r1 */
/* @0x14e384 beq 0x14e3b4 <_Z29F_PhysicsParticleGroupCentreYR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e388 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14e38c mov r1, r0 */
/* @0x14e390 mov r0, r5 */
/* @0x14e394 bl 0x23a6d4 <_ZN13CPhysicsWorld23GetParticleGroupCentreYEi> */
/* @0x14e398 vmov s15, r0 */
/* @0x14e39c vcvt.f64.f32 d7, s15 */
/* @0x14e3a0 vmov r0, r1, d7 */
/* @0x14e3a4 vmov r2, s14 */
/* @0x14e3a8 mov r3, r1 */
/* @0x14e3ac stm r4, {r2, r3} */
/* @0x14e3b0 pop {r3, r4, r5, pc} */
/* @0x14e3b4 ldr r0, [pc, #0x10] */
/* @0x14e3b8 mov r1, #0 */
/* @0x14e3bc pop {r3, r4, r5, lr} */
/* @0x14e3c0 add r0, pc, r0 */
/* @0x14e3c4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e3c8 eoreq pc, r9, r12, asr #11 */
/* @0x14e3cc andseq r6, pc, r4, asr #8 */

/* ── FUNC 0x14e3d0 · F_PhysicsParticleGroupVelX(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x14e3d0 push {r3, r4, r5, lr} */
/* @0x14e3d4 mov r1, #0 */
/* @0x14e3d8 ldr r3, [pc, #0x74] */
/* @0x14e3dc mov r4, r0 */
/* @0x14e3e0 str r1, [r0] */
/* @0x14e3e4 mov r2, r1 */
/* @0x14e3e8 ldr r3, [pc, r3] */
/* @0x14e3ec str r1, [r0, #0xc] */
/* @0x14e3f0 movt r2, #0xbff0 */
/* @0x14e3f4 str r2, [r0, #0x4] */
/* @0x14e3f8 ldr r3, [r3] */
/* @0x14e3fc ldr r0, [sp, #0x10] */
/* @0x14e400 cmp r3, r1 */
/* @0x14e404 beq 0x14e440 <_Z26F_PhysicsParticleGroupVelXR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e408 ldr r5, [r3, #0xb4] */
/* @0x14e40c cmp r5, r1 */
/* @0x14e410 beq 0x14e440 <_Z26F_PhysicsParticleGroupVelXR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e414 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14e418 mov r1, r0 */
/* @0x14e41c mov r0, r5 */
/* @0x14e420 bl 0x23a720 <_ZN13CPhysicsWorld25GetParticleGroupVelocityXEi> */
/* @0x14e424 vmov s15, r0 */
/* @0x14e428 vcvt.f64.f32 d7, s15 */
/* @0x14e42c vmov r0, r1, d7 */
/* @0x14e430 vmov r2, s14 */
/* @0x14e434 mov r3, r1 */
/* @0x14e438 stm r4, {r2, r3} */
/* @0x14e43c pop {r3, r4, r5, pc} */
/* @0x14e440 ldr r0, [pc, #0x10] */
/* @0x14e444 mov r1, #0 */
/* @0x14e448 pop {r3, r4, r5, lr} */
/* @0x14e44c add r0, pc, r0 */
/* @0x14e450 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e454 eoreq pc, r9, r0, asr #10 */
/* @0x14e458 andseq r6, pc, r12, lsl r4 */

/* ── FUNC 0x14e45c · F_PhysicsParticleGroupVelY(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x14e45c push {r3, r4, r5, lr} */
/* @0x14e460 mov r1, #0 */
/* @0x14e464 ldr r3, [pc, #0x74] */
/* @0x14e468 mov r4, r0 */
/* @0x14e46c str r1, [r0] */
/* @0x14e470 mov r2, r1 */
/* @0x14e474 ldr r3, [pc, r3] */
/* @0x14e478 str r1, [r0, #0xc] */
/* @0x14e47c movt r2, #0xbff0 */
/* @0x14e480 str r2, [r0, #0x4] */
/* @0x14e484 ldr r3, [r3] */
/* @0x14e488 ldr r0, [sp, #0x10] */
/* @0x14e48c cmp r3, r1 */
/* @0x14e490 beq 0x14e4cc <_Z26F_PhysicsParticleGroupVelYR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e494 ldr r5, [r3, #0xb4] */
/* @0x14e498 cmp r5, r1 */
/* @0x14e49c beq 0x14e4cc <_Z26F_PhysicsParticleGroupVelYR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e4a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14e4a4 mov r1, r0 */
/* @0x14e4a8 mov r0, r5 */
/* @0x14e4ac bl 0x23a76c <_ZN13CPhysicsWorld25GetParticleGroupVelocityYEi> */
/* @0x14e4b0 vmov s15, r0 */
/* @0x14e4b4 vcvt.f64.f32 d7, s15 */
/* @0x14e4b8 vmov r0, r1, d7 */
/* @0x14e4bc vmov r2, s14 */
/* @0x14e4c0 mov r3, r1 */
/* @0x14e4c4 stm r4, {r2, r3} */
/* @0x14e4c8 pop {r3, r4, r5, pc} */
/* @0x14e4cc ldr r0, [pc, #0x10] */
/* @0x14e4d0 mov r1, #0 */
/* @0x14e4d4 pop {r3, r4, r5, lr} */
/* @0x14e4d8 add r0, pc, r0 */
/* @0x14e4dc b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e4e0 .word 0x0029f4b4 */
/* @0x14e4e4 ldrsheq r6, [pc], -r4 */

/* ── FUNC 0x14e4e8 · F_PhysicsParticleGroupAngVel(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x14e4e8 push {r3, r4, r5, lr} */
/* @0x14e4ec mov r1, #0 */
/* @0x14e4f0 ldr r3, [pc, #0x74] */
/* @0x14e4f4 mov r4, r0 */
/* @0x14e4f8 str r1, [r0] */
/* @0x14e4fc mov r2, r1 */
/* @0x14e500 ldr r3, [pc, r3] */
/* @0x14e504 str r1, [r0, #0xc] */
/* @0x14e508 movt r2, #0xbff0 */
/* @0x14e50c str r2, [r0, #0x4] */
/* @0x14e510 ldr r3, [r3] */
/* @0x14e514 ldr r0, [sp, #0x10] */
/* @0x14e518 cmp r3, r1 */
/* @0x14e51c beq 0x14e558 <_Z28F_PhysicsParticleGroupAngVelR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e520 ldr r5, [r3, #0xb4] */
/* @0x14e524 cmp r5, r1 */
/* @0x14e528 beq 0x14e558 <_Z28F_PhysicsParticleGroupAngVelR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e52c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14e530 mov r1, r0 */
/* @0x14e534 mov r0, r5 */
/* @0x14e538 bl 0x23a7b8 <_ZN13CPhysicsWorld21GetParticleGroupOmegaEi> */
/* @0x14e53c vmov s15, r0 */
/* @0x14e540 vcvt.f64.f32 d7, s15 */
/* @0x14e544 vmov r0, r1, d7 */
/* @0x14e548 vmov r2, s14 */
/* @0x14e54c mov r3, r1 */
/* @0x14e550 stm r4, {r2, r3} */
/* @0x14e554 pop {r3, r4, r5, pc} */
/* @0x14e558 ldr r0, [pc, #0x10] */
/* @0x14e55c mov r1, #0 */
/* @0x14e560 pop {r3, r4, r5, lr} */
/* @0x14e564 add r0, pc, r0 */
/* @0x14e568 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e56c eoreq pc, r9, r8, lsr #8 */
/* @0x14e570 andseq r6, pc, r12, asr #7 */

/* ── FUNC 0x14e574 · F_PhysicsParticleGroupX(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x14e574 push {r3, r4, r5, lr} */
/* @0x14e578 mov r1, #0 */
/* @0x14e57c ldr r3, [pc, #0x74] */
/* @0x14e580 mov r4, r0 */
/* @0x14e584 str r1, [r0] */
/* @0x14e588 mov r2, r1 */
/* @0x14e58c ldr r3, [pc, r3] */
/* @0x14e590 str r1, [r0, #0xc] */
/* @0x14e594 movt r2, #0xbff0 */
/* @0x14e598 str r2, [r0, #0x4] */
/* @0x14e59c ldr r3, [r3] */
/* @0x14e5a0 ldr r0, [sp, #0x10] */
/* @0x14e5a4 cmp r3, r1 */
/* @0x14e5a8 beq 0x14e5e4 <_Z23F_PhysicsParticleGroupXR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e5ac ldr r5, [r3, #0xb4] */
/* @0x14e5b0 cmp r5, r1 */
/* @0x14e5b4 beq 0x14e5e4 <_Z23F_PhysicsParticleGroupXR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e5b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14e5bc mov r1, r0 */
/* @0x14e5c0 mov r0, r5 */
/* @0x14e5c4 bl 0x23a800 <_ZN13CPhysicsWorld17GetParticleGroupXEi> */
/* @0x14e5c8 vmov s15, r0 */
/* @0x14e5cc vcvt.f64.f32 d7, s15 */
/* @0x14e5d0 vmov r0, r1, d7 */
/* @0x14e5d4 vmov r2, s14 */
/* @0x14e5d8 mov r3, r1 */
/* @0x14e5dc stm r4, {r2, r3} */
/* @0x14e5e0 pop {r3, r4, r5, pc} */
/* @0x14e5e4 ldr r0, [pc, #0x10] */
/* @0x14e5e8 mov r1, #0 */
/* @0x14e5ec pop {r3, r4, r5, lr} */
/* @0x14e5f0 add r0, pc, r0 */
/* @0x14e5f4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e5f8 mlaeq r9, r12, r3, pc */
/* @0x14e5fc andseq r6, pc, r0, asr #6 */

/* ── FUNC 0x14e600 · F_PhysicsParticleGroupY(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x14e600 push {r3, r4, r5, lr} */
/* @0x14e604 mov r1, #0 */
/* @0x14e608 ldr r3, [pc, #0x74] */
/* @0x14e60c mov r4, r0 */
/* @0x14e610 str r1, [r0] */
/* @0x14e614 mov r2, r1 */
/* @0x14e618 ldr r3, [pc, r3] */
/* @0x14e61c str r1, [r0, #0xc] */
/* @0x14e620 movt r2, #0xbff0 */
/* @0x14e624 str r2, [r0, #0x4] */
/* @0x14e628 ldr r3, [r3] */
/* @0x14e62c ldr r0, [sp, #0x10] */
/* @0x14e630 cmp r3, r1 */
/* @0x14e634 beq 0x14e670 <_Z23F_PhysicsParticleGroupYR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e638 ldr r5, [r3, #0xb4] */
/* @0x14e63c cmp r5, r1 */
/* @0x14e640 beq 0x14e670 <_Z23F_PhysicsParticleGroupYR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e644 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14e648 mov r1, r0 */
/* @0x14e64c mov r0, r5 */
/* @0x14e650 bl 0x23a83c <_ZN13CPhysicsWorld17GetParticleGroupYEi> */
/* @0x14e654 vmov s15, r0 */
/* @0x14e658 vcvt.f64.f32 d7, s15 */
/* @0x14e65c vmov r0, r1, d7 */
/* @0x14e660 vmov r2, s14 */
/* @0x14e664 mov r3, r1 */
/* @0x14e668 stm r4, {r2, r3} */
/* @0x14e66c pop {r3, r4, r5, pc} */
/* @0x14e670 ldr r0, [pc, #0x10] */
/* @0x14e674 mov r1, #0 */
/* @0x14e678 pop {r3, r4, r5, lr} */
/* @0x14e67c add r0, pc, r0 */
/* @0x14e680 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e684 eoreq pc, r9, r0, lsl r3 */
/* @0x14e688 andseq r6, pc, r4, lsl r3 */

/* ── FUNC 0x14e68c · F_PhysicsParticleGroupAngle(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x14e68c push {r3, r4, r5, lr} */
/* @0x14e690 mov r1, #0 */
/* @0x14e694 ldr r3, [pc, #0x74] */
/* @0x14e698 mov r4, r0 */
/* @0x14e69c str r1, [r0] */
/* @0x14e6a0 mov r2, r1 */
/* @0x14e6a4 ldr r3, [pc, r3] */
/* @0x14e6a8 str r1, [r0, #0xc] */
/* @0x14e6ac movt r2, #0xbff0 */
/* @0x14e6b0 str r2, [r0, #0x4] */
/* @0x14e6b4 ldr r3, [r3] */
/* @0x14e6b8 ldr r0, [sp, #0x10] */
/* @0x14e6bc cmp r3, r1 */
/* @0x14e6c0 beq 0x14e6fc <_Z27F_PhysicsParticleGroupAngleR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e6c4 ldr r5, [r3, #0xb4] */
/* @0x14e6c8 cmp r5, r1 */
/* @0x14e6cc beq 0x14e6fc <_Z27F_PhysicsParticleGroupAngleR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x14e6d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14e6d4 mov r1, r0 */
/* @0x14e6d8 mov r0, r5 */
/* @0x14e6dc bl 0x23a878 <_ZN13CPhysicsWorld21GetParticleGroupAngleEi> */
/* @0x14e6e0 vmov s15, r0 */
/* @0x14e6e4 vcvt.f64.f32 d7, s15 */
/* @0x14e6e8 vmov r0, r1, d7 */
/* @0x14e6ec vmov r2, s14 */
/* @0x14e6f0 mov r3, r1 */
/* @0x14e6f4 stm r4, {r2, r3} */
/* @0x14e6f8 pop {r3, r4, r5, pc} */
/* @0x14e6fc ldr r0, [pc, #0x10] */
/* @0x14e700 mov r1, #0 */
/* @0x14e704 pop {r3, r4, r5, lr} */
/* @0x14e708 add r0, pc, r0 */
/* @0x14e70c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e710 eoreq pc, r9, r4, lsl #5 */
/* @0x14e714 andseq r6, pc, r8, ror #5 */

/* ── FUNC 0x14e718 · F_PhysicsParticleMaxCount(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x14e718 ldr r3, [pc, #0x70] */
/* @0x14e71c mov r1, #0 */
/* @0x14e720 push {r4, lr} */
/* @0x14e724 ldr r3, [pc, r3] */
/* @0x14e728 str r1, [r0] */
/* @0x14e72c mov r2, r1 */
/* @0x14e730 ldr r3, [r3] */
/* @0x14e734 movt r2, #0xbff0 */
/* @0x14e738 mov r4, r0 */
/* @0x14e73c str r1, [r0, #0xc] */
/* @0x14e740 cmp r3, r1 */
/* @0x14e744 str r2, [r0, #0x4] */
/* @0x14e748 beq 0x14e77c <_Z25F_PhysicsParticleMaxCountR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x14e74c ldr r3, [r3, #0xb4] */
/* @0x14e750 cmp r3, r1 */
/* @0x14e754 beq 0x14e77c <_Z25F_PhysicsParticleMaxCountR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x14e758 ldr r0, [r3, #0x10] */
/* @0x14e75c bl 0x2cb42c <_ZNK7b2World19GetParticleMaxCountEv> */
/* @0x14e760 vmov s15, r0 */
/* @0x14e764 vcvt.f64.s32 d7, s15 */
/* @0x14e768 vmov r0, r1, d7 */
/* @0x14e76c vmov r2, s14 */
/* @0x14e770 mov r3, r1 */
/* @0x14e774 stm r4, {r2, r3} */
/* @0x14e778 pop {r4, pc} */
/* @0x14e77c ldr r0, [pc, #0x10] */
/* @0x14e780 mov r1, #0 */
/* @0x14e784 pop {r4, lr} */
/* @0x14e788 add r0, pc, r0 */
/* @0x14e78c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e790 eoreq pc, r9, r4, lsl #4 */
/* @0x14e794 andseq r6, pc, r12, asr #5 */
