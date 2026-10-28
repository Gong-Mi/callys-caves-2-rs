/* libyoyo.so 覆盖卡组 0142
 * 函数 0x1ab2e4..0x1afa00，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1ab2e4 · CRoom::AddInstance(float, float, int, int) · size=432 · insn=108 */
/* @0x1ab2e4 ldr r12, [pc, #0x19c] */
/* @0x1ab2e8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1ab2ec ldr r12, [pc, r12] */
/* @0x1ab2f0 sub sp, sp, #8 */
/* @0x1ab2f4 mov r5, r0 */
/* @0x1ab2f8 ldr r6, [r12] */
/* @0x1ab2fc mov r0, #432 */
/* @0x1ab300 mov r10, r3 */
/* @0x1ab304 mov r9, r1 */
/* @0x1ab308 ldr r7, [sp, #0x28] */
/* @0x1ab30c mov r8, r2 */
/* @0x1ab310 add r6, r6, #1 */
/* @0x1ab314 str r6, [r12] */
/* @0x1ab318 bl 0x27c524 <_Znwj> */
/* @0x1ab31c mov r12, #1 */
/* @0x1ab320 mov r3, r6 */
/* @0x1ab324 mov r2, r8 */
/* @0x1ab328 mov r1, r9 */
/* @0x1ab32c str r12, [sp, #0x4] */
/* @0x1ab330 str r7, [sp] */
/* @0x1ab334 mov r4, r0 */
/* @0x1ab338 bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1ab33c vmov s14, r10 */
/* @0x1ab340 mov r0, r4 */
/* @0x1ab344 mov r1, r5 */
/* @0x1ab348 vcvt.f32.s32 s15, s14 */
/* @0x1ab34c vstr s15, [r4, #384] */
/* @0x1ab350 bl 0x192cd4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom> */
/* @0x1ab354 ldr r3, [r5, #0x84] */
/* @0x1ab358 ldr r2, [r5, #0x88] */
/* @0x1ab35c cmp r3, #0 */
/* @0x1ab360 vldrne s14, [r4, #384] */
/* @0x1ab364 add r2, r2, #1 */
/* @0x1ab368 str r2, [r5, #0x88] */
/* @0x1ab36c beq 0x1ab46c <_ZN5CRoom11AddInstanceEffii+0x188> */
/* @0x1ab370 vldr s15, [r3, #388] */
/* @0x1ab374 vcmpe.f32 s15, s14 */
/* @0x1ab378 vmrs APSR_nzcv, fpscr */
/* @0x1ab37c bls 0x1ab438 <_ZN5CRoom11AddInstanceEffii+0x154> */
/* @0x1ab380 ldr r3, [r3, #0x17c] */
/* @0x1ab384 cmp r3, #0 */
/* @0x1ab388 bne 0x1ab370 <_ZN5CRoom11AddInstanceEffii+0x8c> */
/* @0x1ab38c ldr r2, [r5, #0x80] */
/* @0x1ab390 vstr s14, [r4, #388] */
/* @0x1ab394 str r4, [r2, #0x17c] */
/* @0x1ab398 str r2, [r4, #0x178] */
/* @0x1ab39c str r4, [r5, #0x80] */
/* @0x1ab3a0 str r3, [r4, #0x17c] */
/* @0x1ab3a4 ldr r6, [pc, #0xe0] */
/* @0x1ab3a8 movw r2, #0x132 */
/* @0x1ab3ac ldr r1, [pc, #0xdc] */
/* @0x1ab3b0 mov r3, #1 */
/* @0x1ab3b4 ldr r6, [pc, r6] */
/* @0x1ab3b8 mov r0, #16 */
/* @0x1ab3bc add r1, pc, r1 */
/* @0x1ab3c0 ldr r9, [r4, #0x78] */
/* @0x1ab3c4 ldm r6, {r7, r8} */
/* @0x1ab3c8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ab3cc and r8, r9, r8 */
/* @0x1ab3d0 ldr r2, [r7, r8, lsl #3] */
/* @0x1ab3d4 add r3, r7, r8, lsl #3 */
/* @0x1ab3d8 cmp r2, #0 */
/* @0x1ab3dc ldrne r2, [r3, #0x4] */
/* @0x1ab3e0 movne r1, #0 */
/* @0x1ab3e4 str r9, [r0, #0x8] */
/* @0x1ab3e8 str r4, [r0, #0xc] */
/* @0x1ab3ec strne r2, [r0] */
/* @0x1ab3f0 streq r0, [r3, #0x4] */
/* @0x1ab3f4 strne r0, [r2, #0x4] */
/* @0x1ab3f8 strne r0, [r3, #0x4] */
/* @0x1ab3fc ldr r3, [r6, #0x8] */
/* @0x1ab400 streq r0, [r7, r8, lsl #3] */
/* @0x1ab404 strne r1, [r0, #0x4] */
/* @0x1ab408 mov r1, r4 */
/* @0x1ab40c streq r2, [r0, #0x4] */
/* @0x1ab410 add r3, r3, #1 */
/* @0x1ab414 streq r2, [r0] */
/* @0x1ab418 mov r0, r5 */
/* @0x1ab41c str r3, [r6, #0x8] */
/* @0x1ab420 bl 0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance> */
/* @0x1ab424 mov r0, r4 */
/* @0x1ab428 bl 0x1cc494 <_Z15CollisionInsertP9CInstance> */
/* @0x1ab42c mov r0, r4 */
/* @0x1ab430 add sp, sp, #8 */
/* @0x1ab434 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1ab438 ldr r2, [r3, #0x178] */
/* @0x1ab43c cmp r2, #0 */
/* @0x1ab440 streq r3, [r4, #0x17c] */
/* @0x1ab444 strne r2, [r4, #0x178] */
/* @0x1ab448 ldrne r2, [r3, #0x178] */
/* @0x1ab44c streq r4, [r3, #0x178] */
/* @0x1ab450 strne r3, [r4, #0x17c] */
/* @0x1ab454 streq r4, [r5, #0x84] */
/* @0x1ab458 strne r4, [r2, #0x17c] */
/* @0x1ab45c streq r2, [r4, #0x178] */
/* @0x1ab460 strne r4, [r3, #0x178] */
/* @0x1ab464 vstr s14, [r4, #388] */
/* @0x1ab468 b 0x1ab3a4 <_ZN5CRoom11AddInstanceEffii+0xc0> */
/* @0x1ab46c ldr r2, [r4, #0x180] */
/* @0x1ab470 str r4, [r5, #0x84] */
/* @0x1ab474 str r4, [r5, #0x80] */
/* @0x1ab478 str r2, [r4, #0x184] */
/* @0x1ab47c str r3, [r4, #0x17c] */
/* @0x1ab480 str r3, [r4, #0x178] */
/* @0x1ab484 b 0x1ab3a4 <_ZN5CRoom11AddInstanceEffii+0xc0> */
/* @0x1ab488 eoreq r5, r4, r0, lsr #10 */
/* @0x1ab48c mlaeq r4, r0, r8, r2 */
/* @0x1ab490 ldrsheq r1, [r10], -r0 */

/* ── FUNC 0x1ab494 · CRoom::AddInstance(float, float, CLayer*, int) · size=448 · insn=112 */
/* @0x1ab494 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1ab498 subs r7, r3, #0 */
/* @0x1ab49c sub sp, sp, #8 */
/* @0x1ab4a0 mov r5, r0 */
/* @0x1ab4a4 mov r9, r1 */
/* @0x1ab4a8 mov r8, r2 */
/* @0x1ab4ac beq 0x1ab640 <_ZN5CRoom11AddInstanceEffP6CLayeri+0x1ac> */
/* @0x1ab4b0 ldr r12, [pc, #0x190] */
/* @0x1ab4b4 mov r0, #432 */
/* @0x1ab4b8 ldr r12, [pc, r12] */
/* @0x1ab4bc ldr r6, [r12] */
/* @0x1ab4c0 add r6, r6, #1 */
/* @0x1ab4c4 str r6, [r12] */
/* @0x1ab4c8 bl 0x27c524 <_Znwj> */
/* @0x1ab4cc ldr r2, [sp, #0x28] */
/* @0x1ab4d0 mov r12, #1 */
/* @0x1ab4d4 mov r3, r6 */
/* @0x1ab4d8 str r12, [sp, #0x4] */
/* @0x1ab4dc mov r1, r9 */
/* @0x1ab4e0 str r2, [sp] */
/* @0x1ab4e4 mov r2, r8 */
/* @0x1ab4e8 mov r4, r0 */
/* @0x1ab4ec bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1ab4f0 vldr s14, [r7, #4] */
/* @0x1ab4f4 vcvt.f32.s32 s15, s14 */
/* @0x1ab4f8 mov r0, r4 */
/* @0x1ab4fc mov r1, r5 */
/* @0x1ab500 vstr s15, [r4, #384] */
/* @0x1ab504 bl 0x192cd4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom> */
/* @0x1ab508 ldr r12, [r5, #0x84] */
/* @0x1ab50c ldr r3, [r5, #0x88] */
/* @0x1ab510 cmp r12, #0 */
/* @0x1ab514 vldrne s14, [r4, #384] */
/* @0x1ab518 add r3, r3, #1 */
/* @0x1ab51c str r3, [r5, #0x88] */
/* @0x1ab520 beq 0x1ab624 <_ZN5CRoom11AddInstanceEffP6CLayeri+0x190> */
/* @0x1ab524 vldr s15, [r12, #388] */
/* @0x1ab528 vcmpe.f32 s15, s14 */
/* @0x1ab52c vmrs APSR_nzcv, fpscr */
/* @0x1ab530 bls 0x1ab5f0 <_ZN5CRoom11AddInstanceEffP6CLayeri+0x15c> */
/* @0x1ab534 ldr r12, [r12, #0x17c] */
/* @0x1ab538 cmp r12, #0 */
/* @0x1ab53c bne 0x1ab524 <_ZN5CRoom11AddInstanceEffP6CLayeri+0x90> */
/* @0x1ab540 ldr r3, [r5, #0x80] */
/* @0x1ab544 vstr s14, [r4, #388] */
/* @0x1ab548 str r4, [r3, #0x17c] */
/* @0x1ab54c str r3, [r4, #0x178] */
/* @0x1ab550 str r4, [r5, #0x80] */
/* @0x1ab554 str r12, [r4, #0x17c] */
/* @0x1ab558 ldr r6, [pc, #0xec] */
/* @0x1ab55c movw r2, #0x132 */
/* @0x1ab560 ldr r1, [pc, #0xe8] */
/* @0x1ab564 mov r3, #1 */
/* @0x1ab568 ldr r6, [pc, r6] */
/* @0x1ab56c mov r0, #16 */
/* @0x1ab570 add r1, pc, r1 */
/* @0x1ab574 ldr r10, [r4, #0x78] */
/* @0x1ab578 ldm r6, {r8, r9} */
/* @0x1ab57c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ab580 and r9, r10, r9 */
/* @0x1ab584 ldr r2, [r8, r9, lsl #3] */
/* @0x1ab588 add r3, r8, r9, lsl #3 */
/* @0x1ab58c cmp r2, #0 */
/* @0x1ab590 ldrne r2, [r3, #0x4] */
/* @0x1ab594 movne r1, #0 */
/* @0x1ab598 str r10, [r0, #0x8] */
/* @0x1ab59c strne r2, [r0] */
/* @0x1ab5a0 str r4, [r0, #0xc] */
/* @0x1ab5a4 streq r0, [r3, #0x4] */
/* @0x1ab5a8 strne r0, [r2, #0x4] */
/* @0x1ab5ac strne r0, [r3, #0x4] */
/* @0x1ab5b0 ldr r3, [r6, #0x8] */
/* @0x1ab5b4 streq r0, [r8, r9, lsl #3] */
/* @0x1ab5b8 strne r1, [r0, #0x4] */
/* @0x1ab5bc mov r1, r7 */
/* @0x1ab5c0 streq r2, [r0, #0x4] */
/* @0x1ab5c4 add r3, r3, #1 */
/* @0x1ab5c8 streq r2, [r0] */
/* @0x1ab5cc mov r0, r5 */
/* @0x1ab5d0 mov r2, r4 */
/* @0x1ab5d4 str r3, [r6, #0x8] */
/* @0x1ab5d8 bl 0x1c5a38 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance> */
/* @0x1ab5dc mov r0, r4 */
/* @0x1ab5e0 bl 0x1cc494 <_Z15CollisionInsertP9CInstance> */
/* @0x1ab5e4 mov r0, r4 */
/* @0x1ab5e8 add sp, sp, #8 */
/* @0x1ab5ec pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1ab5f0 ldr r3, [r12, #0x178] */
/* @0x1ab5f4 cmp r3, #0 */
/* @0x1ab5f8 streq r12, [r4, #0x17c] */
/* @0x1ab5fc strne r3, [r4, #0x178] */
/* @0x1ab600 ldrne r3, [r12, #0x178] */
/* @0x1ab604 streq r4, [r12, #0x178] */
/* @0x1ab608 strne r12, [r4, #0x17c] */
/* @0x1ab60c streq r4, [r5, #0x84] */
/* @0x1ab610 strne r4, [r3, #0x17c] */
/* @0x1ab614 streq r3, [r4, #0x178] */
/* @0x1ab618 strne r4, [r12, #0x178] */
/* @0x1ab61c vstr s14, [r4, #388] */
/* @0x1ab620 b 0x1ab558 <_ZN5CRoom11AddInstanceEffP6CLayeri+0xc4> */
/* @0x1ab624 ldr r3, [r4, #0x180] */
/* @0x1ab628 str r4, [r5, #0x84] */
/* @0x1ab62c str r4, [r5, #0x80] */
/* @0x1ab630 str r3, [r4, #0x184] */
/* @0x1ab634 str r12, [r4, #0x17c] */
/* @0x1ab638 str r12, [r4, #0x178] */
/* @0x1ab63c b 0x1ab558 <_ZN5CRoom11AddInstanceEffP6CLayeri+0xc4> */
/* @0x1ab640 mov r0, r7 */
/* @0x1ab644 b 0x1ab5e8 <_ZN5CRoom11AddInstanceEffP6CLayeri+0x154> */
/* @0x1ab648 eoreq r5, r4, r4, asr r3 */
/* @0x1ab64c .word 0x002426dc */
/* @0x1ab650 andseq r1, r10, r12, lsr r7 */

/* ── FUNC 0x1ab654 · CRoom::AddInstance(CInstance*) · size=324 · insn=81 */
/* @0x1ab654 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1ab658 mov r6, r0 */
/* @0x1ab65c ldr r3, [r0, #0x84] */
/* @0x1ab660 mov r4, r1 */
/* @0x1ab664 ldr r2, [r0, #0x88] */
/* @0x1ab668 cmp r3, #0 */
/* @0x1ab66c vldrne s14, [r1, #384] */
/* @0x1ab670 add r2, r2, #1 */
/* @0x1ab674 str r2, [r0, #0x88] */
/* @0x1ab678 beq 0x1ab774 <_ZN5CRoom11AddInstanceEP9CInstance+0x120> */
/* @0x1ab67c vldr s15, [r3, #388] */
/* @0x1ab680 vcmpe.f32 s15, s14 */
/* @0x1ab684 vmrs APSR_nzcv, fpscr */
/* @0x1ab688 bls 0x1ab740 <_ZN5CRoom11AddInstanceEP9CInstance+0xec> */
/* @0x1ab68c ldr r3, [r3, #0x17c] */
/* @0x1ab690 cmp r3, #0 */
/* @0x1ab694 bne 0x1ab67c <_ZN5CRoom11AddInstanceEP9CInstance+0x28> */
/* @0x1ab698 ldr r2, [r6, #0x80] */
/* @0x1ab69c vstr s14, [r4, #388] */
/* @0x1ab6a0 str r4, [r2, #0x17c] */
/* @0x1ab6a4 str r2, [r4, #0x178] */
/* @0x1ab6a8 str r4, [r6, #0x80] */
/* @0x1ab6ac str r3, [r4, #0x17c] */
/* @0x1ab6b0 ldr r5, [pc, #0xd8] */
/* @0x1ab6b4 movw r2, #0x132 */
/* @0x1ab6b8 ldr r1, [pc, #0xd4] */
/* @0x1ab6bc mov r3, #1 */
/* @0x1ab6c0 ldr r5, [pc, r5] */
/* @0x1ab6c4 mov r0, #16 */
/* @0x1ab6c8 add r1, pc, r1 */
/* @0x1ab6cc ldr r9, [r4, #0x78] */
/* @0x1ab6d0 ldm r5, {r7, r8} */
/* @0x1ab6d4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ab6d8 and r8, r9, r8 */
/* @0x1ab6dc ldr r1, [r7, r8, lsl #3] */
/* @0x1ab6e0 add r2, r7, r8, lsl #3 */
/* @0x1ab6e4 cmp r1, #0 */
/* @0x1ab6e8 ldrne r1, [r2, #0x4] */
/* @0x1ab6ec mov r3, r0 */
/* @0x1ab6f0 str r9, [r0, #0x8] */
/* @0x1ab6f4 str r4, [r0, #0xc] */
/* @0x1ab6f8 movne r0, #0 */
/* @0x1ab6fc strne r1, [r3] */
/* @0x1ab700 strne r3, [r1, #0x4] */
/* @0x1ab704 strne r3, [r2, #0x4] */
/* @0x1ab708 strne r0, [r3, #0x4] */
/* @0x1ab70c ldr r3, [r5, #0x8] */
/* @0x1ab710 streq r0, [r2, #0x4] */
/* @0x1ab714 streq r0, [r7, r8, lsl #3] */
/* @0x1ab718 add r3, r3, #1 */
/* @0x1ab71c streq r1, [r0, #0x4] */
/* @0x1ab720 streq r1, [r0] */
/* @0x1ab724 mov r0, r6 */
/* @0x1ab728 mov r1, r4 */
/* @0x1ab72c str r3, [r5, #0x8] */
/* @0x1ab730 bl 0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance> */
/* @0x1ab734 mov r0, r4 */
/* @0x1ab738 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1ab73c b 0x1cc494 <_Z15CollisionInsertP9CInstance> */
/* @0x1ab740 ldr r2, [r3, #0x178] */
/* @0x1ab744 cmp r2, #0 */
/* @0x1ab748 streq r3, [r4, #0x17c] */
/* @0x1ab74c strne r2, [r4, #0x178] */
/* @0x1ab750 ldrne r2, [r3, #0x178] */
/* @0x1ab754 streq r4, [r3, #0x178] */
/* @0x1ab758 strne r3, [r4, #0x17c] */
/* @0x1ab75c streq r4, [r6, #0x84] */
/* @0x1ab760 strne r4, [r2, #0x17c] */
/* @0x1ab764 streq r2, [r4, #0x178] */
/* @0x1ab768 strne r4, [r3, #0x178] */
/* @0x1ab76c vstr s14, [r4, #388] */
/* @0x1ab770 b 0x1ab6b0 <_ZN5CRoom11AddInstanceEP9CInstance+0x5c> */
/* @0x1ab774 ldr r2, [r1, #0x180] */
/* @0x1ab778 str r1, [r6, #0x84] */
/* @0x1ab77c str r1, [r6, #0x80] */
/* @0x1ab780 str r2, [r1, #0x184] */
/* @0x1ab784 str r3, [r1, #0x17c] */
/* @0x1ab788 str r3, [r1, #0x178] */
/* @0x1ab78c b 0x1ab6b0 <_ZN5CRoom11AddInstanceEP9CInstance+0x5c> */
/* @0x1ab790 eoreq r2, r4, r4, lsl #11 */
/* @0x1ab794 andseq r1, r10, r4, ror #11 */

/* ── FUNC 0x1ab798 · CRoom::ClearInstances() · size=560 · insn=140 */
/* @0x1ab798 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ab79c mov r5, r0 */
/* @0x1ab7a0 ldr r4, [r0, #0x80] */
/* @0x1ab7a4 ldr r3, [pc, #0x208] */
/* @0x1ab7a8 cmp r4, #0 */
/* @0x1ab7ac add r3, pc, r3 */
/* @0x1ab7b0 beq 0x1ab9a0 <_ZN5CRoom14ClearInstancesEv+0x208> */
/* @0x1ab7b4 ldr r12, [pc, #0x1fc] */
/* @0x1ab7b8 ldr r0, [pc, #0x1fc] */
/* @0x1ab7bc ldr r1, [pc, #0x1fc] */
/* @0x1ab7c0 ldr r2, [pc, #0x1fc] */
/* @0x1ab7c4 ldr r7, [r3, r12] */
/* @0x1ab7c8 ldr r10, [r3, r0] */
/* @0x1ab7cc ldr r9, [r3, r1] */
/* @0x1ab7d0 ldr r8, [r3, r2] */
/* @0x1ab7d4 mov r0, r5 */
/* @0x1ab7d8 mov r1, r4 */
/* @0x1ab7dc ldr r6, [r4, #0x178] */
/* @0x1ab7e0 bl 0x1b9e5c <_ZN13CLayerManager14RemoveInstanceEP5CRoomP9CInstance> */
/* @0x1ab7e4 ldm r7, {r0, r12} */
/* @0x1ab7e8 ldr r1, [r4, #0x78] */
/* @0x1ab7ec and r12, r1, r12 */
/* @0x1ab7f0 ldr r3, [r0, r12, lsl #3] */
/* @0x1ab7f4 add lr, r0, r12, lsl #3 */
/* @0x1ab7f8 cmp r3, #0 */
/* @0x1ab7fc bne 0x1ab810 <_ZN5CRoom14ClearInstancesEv+0x78> */
/* @0x1ab800 b 0x1ab854 <_ZN5CRoom14ClearInstancesEv+0xbc> */
/* @0x1ab804 ldr r3, [r3, #0x4] */
/* @0x1ab808 cmp r3, #0 */
/* @0x1ab80c beq 0x1ab854 <_ZN5CRoom14ClearInstancesEv+0xbc> */
/* @0x1ab810 ldr r2, [r3, #0x8] */
/* @0x1ab814 cmp r1, r2 */
/* @0x1ab818 bne 0x1ab804 <_ZN5CRoom14ClearInstancesEv+0x6c> */
/* @0x1ab81c ldr r2, [r3] */
/* @0x1ab820 ldr r1, [r3, #0x4] */
/* @0x1ab824 cmp r2, #0 */
/* @0x1ab828 strne r1, [r2, #0x4] */
/* @0x1ab82c ldrne r1, [r3, #0x4] */
/* @0x1ab830 streq r1, [r0, r12, lsl #3] */
/* @0x1ab834 mov r0, r3 */
/* @0x1ab838 cmp r1, #0 */
/* @0x1ab83c streq r2, [lr, #0x4] */
/* @0x1ab840 strne r2, [r1] */
/* @0x1ab844 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ab848 ldr r3, [r7, #0x8] */
/* @0x1ab84c sub r3, r3, #1 */
/* @0x1ab850 str r3, [r7, #0x8] */
/* @0x1ab854 ldr r3, [r4, #0x17c] */
/* @0x1ab858 mov r0, r4 */
/* @0x1ab85c ldr r2, [r4, #0x178] */
/* @0x1ab860 cmp r3, #0 */
/* @0x1ab864 strne r2, [r3, #0x178] */
/* @0x1ab868 ldrne r2, [r4, #0x178] */
/* @0x1ab86c ldrne r3, [r4, #0x17c] */
/* @0x1ab870 streq r2, [r5, #0x80] */
/* @0x1ab874 cmp r2, #0 */
/* @0x1ab878 streq r3, [r5, #0x84] */
/* @0x1ab87c strne r3, [r2, #0x17c] */
/* @0x1ab880 mov r2, #0 */
/* @0x1ab884 ldr r3, [r4] */
/* @0x1ab888 str r2, [r4, #0x178] */
/* @0x1ab88c str r2, [r4, #0x17c] */
/* @0x1ab890 ldr r3, [r3, #0x4] */
/* @0x1ab894 blx r3 */
/* @0x1ab898 ldr r12, [r10, #0x8] */
/* @0x1ab89c ldr r3, [r5, #0x88] */
/* @0x1ab8a0 cmp r12, #0 */
/* @0x1ab8a4 sub r3, r3, #1 */
/* @0x1ab8a8 str r3, [r5, #0x88] */
/* @0x1ab8ac ble 0x1ab8f4 <_ZN5CRoom14ClearInstancesEv+0x15c> */
/* @0x1ab8b0 ldr r2, [r10] */
/* @0x1ab8b4 mov r11, #0 */
/* @0x1ab8b8 mov r3, r11 */
/* @0x1ab8bc mov r1, r11 */
/* @0x1ab8c0 ldr r0, [r2, r3, lsl #2] */
/* @0x1ab8c4 str r0, [r2, r1, lsl #2] */
/* @0x1ab8c8 ldr r2, [r10] */
/* @0x1ab8cc ldr r0, [r2, r3, lsl #2] */
/* @0x1ab8d0 add r3, r3, #1 */
/* @0x1ab8d4 cmp r4, r0 */
/* @0x1ab8d8 addne r1, r1, #1 */
/* @0x1ab8dc moveq r11, #1 */
/* @0x1ab8e0 cmp r3, r12 */
/* @0x1ab8e4 bne 0x1ab8c0 <_ZN5CRoom14ClearInstancesEv+0x128> */
/* @0x1ab8e8 cmp r11, #0 */
/* @0x1ab8ec subne r3, r3, #1 */
/* @0x1ab8f0 strne r3, [r10, #0x8] */
/* @0x1ab8f4 ldr r12, [r9, #0x8] */
/* @0x1ab8f8 cmp r12, #0 */
/* @0x1ab8fc ble 0x1ab944 <_ZN5CRoom14ClearInstancesEv+0x1ac> */
/* @0x1ab900 ldr r2, [r9] */
/* @0x1ab904 mov r11, #0 */
/* @0x1ab908 mov r3, r11 */
/* @0x1ab90c mov r1, r11 */
/* @0x1ab910 ldr r0, [r2, r3, lsl #2] */
/* @0x1ab914 str r0, [r2, r1, lsl #2] */
/* @0x1ab918 ldr r2, [r9] */
/* @0x1ab91c ldr r0, [r2, r3, lsl #2] */
/* @0x1ab920 add r3, r3, #1 */
/* @0x1ab924 cmp r4, r0 */
/* @0x1ab928 addne r1, r1, #1 */
/* @0x1ab92c moveq r11, #1 */
/* @0x1ab930 cmp r3, r12 */
/* @0x1ab934 bne 0x1ab910 <_ZN5CRoom14ClearInstancesEv+0x178> */
/* @0x1ab938 cmp r11, #0 */
/* @0x1ab93c subne r3, r3, #1 */
/* @0x1ab940 strne r3, [r9, #0x8] */
/* @0x1ab944 ldr r12, [r8, #0x8] */
/* @0x1ab948 cmp r12, #0 */
/* @0x1ab94c ble 0x1ab994 <_ZN5CRoom14ClearInstancesEv+0x1fc> */
/* @0x1ab950 ldr r2, [r8] */
/* @0x1ab954 mov r11, #0 */
/* @0x1ab958 mov r3, r11 */
/* @0x1ab95c mov r1, r11 */
/* @0x1ab960 ldr r0, [r2, r3, lsl #2] */
/* @0x1ab964 str r0, [r2, r1, lsl #2] */
/* @0x1ab968 ldr r2, [r8] */
/* @0x1ab96c ldr r0, [r2, r3, lsl #2] */
/* @0x1ab970 add r3, r3, #1 */
/* @0x1ab974 cmp r4, r0 */
/* @0x1ab978 addne r1, r1, #1 */
/* @0x1ab97c moveq r11, #1 */
/* @0x1ab980 cmp r3, r12 */
/* @0x1ab984 bne 0x1ab960 <_ZN5CRoom14ClearInstancesEv+0x1c8> */
/* @0x1ab988 cmp r11, #0 */
/* @0x1ab98c subne r3, r3, #1 */
/* @0x1ab990 strne r3, [r8, #0x8] */
/* @0x1ab994 cmp r6, #0 */
/* @0x1ab998 movne r4, r6 */
/* @0x1ab99c bne 0x1ab7d4 <_ZN5CRoom14ClearInstancesEv+0x3c> */
/* @0x1ab9a0 mov r3, #0 */
/* @0x1ab9a4 str r3, [r5, #0x88] */
/* @0x1ab9a8 str r3, [r5, #0x84] */
/* @0x1ab9ac str r3, [r5, #0x80] */
/* @0x1ab9b0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ab9b4 eoreq r6, r4, r4, lsr #9 */
/* @0x1ab9b8 .word 0xffffbff4 */
/* @0x1ab9bc .word 0xffffc454 */
/* @0x1ab9c0 .word 0xffffbff0 */
/* @0x1ab9c4 .word 0xffffbff8 */

/* ── FUNC 0x1ab9c8 · CRoom::ClearDeactiveInstances() · size=268 · insn=67 */
/* @0x1ab9c8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1ab9cc mov r5, r0 */
/* @0x1ab9d0 ldr r4, [r0, #0x8c] */
/* @0x1ab9d4 cmp r4, #0 */
/* @0x1ab9d8 beq 0x1ababc <_ZN5CRoom22ClearDeactiveInstancesEv+0xf4> */
/* @0x1ab9dc ldr r6, [pc, #0xec] */
/* @0x1ab9e0 ldr r6, [pc, r6] */
/* @0x1ab9e4 mov r0, r5 */
/* @0x1ab9e8 mov r1, r4 */
/* @0x1ab9ec ldr r7, [r4, #0x178] */
/* @0x1ab9f0 bl 0x1b9e5c <_ZN13CLayerManager14RemoveInstanceEP5CRoomP9CInstance> */
/* @0x1ab9f4 ldr r12, [r4, #0x78] */
/* @0x1ab9f8 ldr r0, [r6, #0x4] */
/* @0x1ab9fc ldr r1, [r6] */
/* @0x1aba00 and r0, r12, r0 */
/* @0x1aba04 ldr r3, [r1, r0, lsl #3] */
/* @0x1aba08 add lr, r1, r0, lsl #3 */
/* @0x1aba0c cmp r3, #0 */
/* @0x1aba10 bne 0x1aba24 <_ZN5CRoom22ClearDeactiveInstancesEv+0x5c> */
/* @0x1aba14 b 0x1aba6c <_ZN5CRoom22ClearDeactiveInstancesEv+0xa4> */
/* @0x1aba18 ldr r3, [r3, #0x4] */
/* @0x1aba1c cmp r3, #0 */
/* @0x1aba20 beq 0x1aba6c <_ZN5CRoom22ClearDeactiveInstancesEv+0xa4> */
/* @0x1aba24 ldr r2, [r3, #0x8] */
/* @0x1aba28 cmp r12, r2 */
/* @0x1aba2c bne 0x1aba18 <_ZN5CRoom22ClearDeactiveInstancesEv+0x50> */
/* @0x1aba30 ldr r2, [r3] */
/* @0x1aba34 cmp r2, #0 */
/* @0x1aba38 ldrne r1, [r3, #0x4] */
/* @0x1aba3c ldreq r12, [r3, #0x4] */
/* @0x1aba40 strne r1, [r2, #0x4] */
/* @0x1aba44 ldrne r12, [r3, #0x4] */
/* @0x1aba48 streq r12, [r1, r0, lsl #3] */
/* @0x1aba4c mov r0, r3 */
/* @0x1aba50 cmp r12, #0 */
/* @0x1aba54 streq r2, [lr, #0x4] */
/* @0x1aba58 strne r2, [r12] */
/* @0x1aba5c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1aba60 ldr r3, [r6, #0x8] */
/* @0x1aba64 sub r3, r3, #1 */
/* @0x1aba68 str r3, [r6, #0x8] */
/* @0x1aba6c ldr r3, [r4, #0x17c] */
/* @0x1aba70 mov r0, r4 */
/* @0x1aba74 ldr r2, [r4, #0x178] */
/* @0x1aba78 cmp r3, #0 */
/* @0x1aba7c strne r2, [r3, #0x178] */
/* @0x1aba80 ldrne r3, [r4, #0x17c] */
/* @0x1aba84 ldrne r2, [r4, #0x178] */
/* @0x1aba88 streq r2, [r5, #0x8c] */
/* @0x1aba8c cmp r2, #0 */
/* @0x1aba90 streq r3, [r5, #0x90] */
/* @0x1aba94 strne r3, [r2, #0x17c] */
/* @0x1aba98 ldr r3, [r4] */
/* @0x1aba9c ldr r3, [r3, #0x4] */
/* @0x1abaa0 blx r3 */
/* @0x1abaa4 ldr r3, [r5, #0x94] */
/* @0x1abaa8 cmp r7, #0 */
/* @0x1abaac sub r3, r3, #1 */
/* @0x1abab0 str r3, [r5, #0x94] */
/* @0x1abab4 movne r4, r7 */
/* @0x1abab8 bne 0x1ab9e4 <_ZN5CRoom22ClearDeactiveInstancesEv+0x1c> */
/* @0x1ababc mov r3, #0 */
/* @0x1abac0 str r3, [r5, #0x94] */
/* @0x1abac4 str r3, [r5, #0x90] */
/* @0x1abac8 str r3, [r5, #0x8c] */
/* @0x1abacc pop {r3, r4, r5, r6, r7, pc} */
/* @0x1abad0 eoreq r2, r4, r4, ror #4 */

/* ── FUNC 0x1abad4 · CRoom::CleanPersistent() · size=80 · insn=20 */
/* @0x1abad4 ldr r0, [r0, #0x80] */
/* @0x1abad8 push {r4, lr} */
/* @0x1abadc cmp r0, #0 */
/* @0x1abae0 bne 0x1abaf4 <_ZN5CRoom15CleanPersistentEv+0x20> */
/* @0x1abae4 pop {r4, pc} */
/* @0x1abae8 cmp r4, #0 */
/* @0x1abaec mov r0, r4 */
/* @0x1abaf0 beq 0x1abb20 <_ZN5CRoom15CleanPersistentEv+0x4c> */
/* @0x1abaf4 ldrb r3, [r0, #0x67] */
/* @0x1abaf8 ldr r4, [r0, #0x178] */
/* @0x1abafc cmp r3, #0 */
/* @0x1abb00 beq 0x1abae8 <_ZN5CRoom15CleanPersistentEv+0x14> */
/* @0x1abb04 mov r1, r0 */
/* @0x1abb08 mov r2, #12 */
/* @0x1abb0c mov r3, #0 */
/* @0x1abb10 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1abb14 cmp r4, #0 */
/* @0x1abb18 mov r0, r4 */
/* @0x1abb1c bne 0x1abaf4 <_ZN5CRoom15CleanPersistentEv+0x20> */
/* @0x1abb20 pop {r4, pc} */

/* ── FUNC 0x1abb24 · CRoom::RemoveMarked() · size=632 · insn=158 */
/* @0x1abb24 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1abb28 sub sp, sp, #12 */
/* @0x1abb2c ldr r10, [pc, #0x250] */
/* @0x1abb30 mov r5, r0 */
/* @0x1abb34 ldr r2, [pc, #0x24c] */
/* @0x1abb38 add r10, pc, r10 */
/* @0x1abb3c ldr r3, [pc, #0x248] */
/* @0x1abb40 ldr r7, [r10, r2] */
/* @0x1abb44 ldr r3, [r10, r3] */
/* @0x1abb48 ldr r8, [r7] */
/* @0x1abb4c str r3, [sp, #0x4] */
/* @0x1abb50 cmp r8, #250 */
/* @0x1abb54 ldrb r3, [r3] */
/* @0x1abb58 movle r8, #0 */
/* @0x1abb5c movgt r8, #1 */
/* @0x1abb60 cmp r3, #0 */
/* @0x1abb64 beq 0x1abb70 <_ZN5CRoom12RemoveMarkedEv+0x4c> */
/* @0x1abb68 cmp r8, #0 */
/* @0x1abb6c bne 0x1abd44 <_ZN5CRoom12RemoveMarkedEv+0x220> */
/* @0x1abb70 ldr r4, [r5, #0x80] */
/* @0x1abb74 cmp r4, #0 */
/* @0x1abb78 movne r6, #0 */
/* @0x1abb7c bne 0x1abb90 <_ZN5CRoom12RemoveMarkedEv+0x6c> */
/* @0x1abb80 b 0x1abcdc <_ZN5CRoom12RemoveMarkedEv+0x1b8> */
/* @0x1abb84 cmp r9, #0 */
/* @0x1abb88 beq 0x1abcdc <_ZN5CRoom12RemoveMarkedEv+0x1b8> */
/* @0x1abb8c mov r4, r9 */
/* @0x1abb90 ldrb r3, [r4, #0x68] */
/* @0x1abb94 ldr r9, [r4, #0x178] */
/* @0x1abb98 cmp r3, #0 */
/* @0x1abb9c beq 0x1abb84 <_ZN5CRoom12RemoveMarkedEv+0x60> */
/* @0x1abba0 ldr r3, [pc, #0x1e8] */
/* @0x1abba4 ldr r12, [r10, r3] */
/* @0x1abba8 ldr lr, [r12, #0x8] */
/* @0x1abbac cmp lr, #0 */
/* @0x1abbb0 ble 0x1abbf8 <_ZN5CRoom12RemoveMarkedEv+0xd4> */
/* @0x1abbb4 ldr r2, [r12] */
/* @0x1abbb8 mov r11, #0 */
/* @0x1abbbc mov r3, r11 */
/* @0x1abbc0 mov r1, r11 */
/* @0x1abbc4 ldr r0, [r2, r3, lsl #2] */
/* @0x1abbc8 str r0, [r2, r1, lsl #2] */
/* @0x1abbcc ldr r2, [r12] */
/* @0x1abbd0 ldr r0, [r2, r3, lsl #2] */
/* @0x1abbd4 add r3, r3, #1 */
/* @0x1abbd8 cmp r4, r0 */
/* @0x1abbdc addne r1, r1, #1 */
/* @0x1abbe0 moveq r11, #1 */
/* @0x1abbe4 cmp r3, lr */
/* @0x1abbe8 bne 0x1abbc4 <_ZN5CRoom12RemoveMarkedEv+0xa0> */
/* @0x1abbec cmp r11, #0 */
/* @0x1abbf0 subne r3, r3, #1 */
/* @0x1abbf4 strne r3, [r12, #0x8] */
/* @0x1abbf8 mov r0, r5 */
/* @0x1abbfc mov r1, r4 */
/* @0x1abc00 bl 0x1b9e5c <_ZN13CLayerManager14RemoveInstanceEP5CRoomP9CInstance> */
/* @0x1abc04 ldr r3, [pc, #0x188] */
/* @0x1abc08 ldr r1, [r4, #0x78] */
/* @0x1abc0c ldr r11, [r10, r3] */
/* @0x1abc10 ldm r11, {r0, r12} */
/* @0x1abc14 and r12, r1, r12 */
/* @0x1abc18 ldr r3, [r0, r12, lsl #3] */
/* @0x1abc1c add lr, r0, r12, lsl #3 */
/* @0x1abc20 cmp r3, #0 */
/* @0x1abc24 bne 0x1abc38 <_ZN5CRoom12RemoveMarkedEv+0x114> */
/* @0x1abc28 b 0x1abc7c <_ZN5CRoom12RemoveMarkedEv+0x158> */
/* @0x1abc2c ldr r3, [r3, #0x4] */
/* @0x1abc30 cmp r3, #0 */
/* @0x1abc34 beq 0x1abc7c <_ZN5CRoom12RemoveMarkedEv+0x158> */
/* @0x1abc38 ldr r2, [r3, #0x8] */
/* @0x1abc3c cmp r1, r2 */
/* @0x1abc40 bne 0x1abc2c <_ZN5CRoom12RemoveMarkedEv+0x108> */
/* @0x1abc44 ldr r2, [r3] */
/* @0x1abc48 ldr r1, [r3, #0x4] */
/* @0x1abc4c cmp r2, #0 */
/* @0x1abc50 strne r1, [r2, #0x4] */
/* @0x1abc54 ldrne r1, [r3, #0x4] */
/* @0x1abc58 streq r1, [r0, r12, lsl #3] */
/* @0x1abc5c mov r0, r3 */
/* @0x1abc60 cmp r1, #0 */
/* @0x1abc64 streq r2, [lr, #0x4] */
/* @0x1abc68 strne r2, [r1] */
/* @0x1abc6c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1abc70 ldr r3, [r11, #0x8] */
/* @0x1abc74 sub r3, r3, #1 */
/* @0x1abc78 str r3, [r11, #0x8] */
/* @0x1abc7c ldrb r3, [r4, #0x69] */
/* @0x1abc80 ldr r2, [r4, #0x178] */
/* @0x1abc84 cmp r3, #0 */
/* @0x1abc88 ldr r3, [r4, #0x17c] */
/* @0x1abc8c bne 0x1abd04 <_ZN5CRoom12RemoveMarkedEv+0x1e0> */
/* @0x1abc90 cmp r3, #0 */
/* @0x1abc94 strne r2, [r3, #0x178] */
/* @0x1abc98 streq r2, [r5, #0x80] */
/* @0x1abc9c mov r0, r4 */
/* @0x1abca0 ldrne r3, [r4, #0x17c] */
/* @0x1abca4 ldrne r2, [r4, #0x178] */
/* @0x1abca8 cmp r2, #0 */
/* @0x1abcac streq r3, [r5, #0x84] */
/* @0x1abcb0 strne r3, [r2, #0x17c] */
/* @0x1abcb4 ldr r3, [r4] */
/* @0x1abcb8 str r6, [r4, #0x178] */
/* @0x1abcbc str r6, [r4, #0x17c] */
/* @0x1abcc0 ldr r3, [r3, #0x4] */
/* @0x1abcc4 blx r3 */
/* @0x1abcc8 ldr r3, [r5, #0x88] */
/* @0x1abccc cmp r9, #0 */
/* @0x1abcd0 sub r3, r3, #1 */
/* @0x1abcd4 str r3, [r5, #0x88] */
/* @0x1abcd8 bne 0x1abb8c <_ZN5CRoom12RemoveMarkedEv+0x68> */
/* @0x1abcdc ldr r2, [sp, #0x4] */
/* @0x1abce0 ldrb r3, [r2] */
/* @0x1abce4 cmp r3, #0 */
/* @0x1abce8 beq 0x1abcf4 <_ZN5CRoom12RemoveMarkedEv+0x1d0> */
/* @0x1abcec cmp r8, #0 */
/* @0x1abcf0 bne 0x1abd70 <_ZN5CRoom12RemoveMarkedEv+0x24c> */
/* @0x1abcf4 mov r3, #0 */
/* @0x1abcf8 str r3, [r7] */
/* @0x1abcfc add sp, sp, #12 */
/* @0x1abd00 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1abd04 cmp r3, #0 */
/* @0x1abd08 strne r2, [r3, #0x178] */
/* @0x1abd0c streq r2, [r5, #0x8c] */
/* @0x1abd10 mov r0, r4 */
/* @0x1abd14 ldrne r3, [r4, #0x17c] */
/* @0x1abd18 ldrne r2, [r4, #0x178] */
/* @0x1abd1c cmp r2, #0 */
/* @0x1abd20 streq r3, [r5, #0x90] */
/* @0x1abd24 strne r3, [r2, #0x17c] */
/* @0x1abd28 ldr r3, [r4] */
/* @0x1abd2c ldr r3, [r3, #0x4] */
/* @0x1abd30 blx r3 */
/* @0x1abd34 ldr r3, [r5, #0x94] */
/* @0x1abd38 sub r3, r3, #1 */
/* @0x1abd3c str r3, [r5, #0x94] */
/* @0x1abd40 b 0x1abb84 <_ZN5CRoom12RemoveMarkedEv+0x60> */
/* @0x1abd44 ldr r3, [pc, #0x4c] */
/* @0x1abd48 ldr r4, [r10, r3] */
/* @0x1abd4c ldr r0, [r4] */
/* @0x1abd50 cmp r0, #0 */
/* @0x1abd54 beq 0x1abd64 <_ZN5CRoom12RemoveMarkedEv+0x240> */
/* @0x1abd58 ldr r3, [r0] */
/* @0x1abd5c ldr r3, [r3, #0x4] */
/* @0x1abd60 blx r3 */
/* @0x1abd64 mov r3, #0 */
/* @0x1abd68 str r3, [r4] */
/* @0x1abd6c b 0x1abb70 <_ZN5CRoom12RemoveMarkedEv+0x4c> */
/* @0x1abd70 bl 0x1cdb1c <_Z11RebuildTreev> */
/* @0x1abd74 mov r3, #0 */
/* @0x1abd78 str r3, [r7] */
/* @0x1abd7c add sp, sp, #12 */
/* @0x1abd80 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1abd84 eoreq r6, r4, r8, lsl r1 */
/* @0x1abd88 .word 0xffffc464 */
/* @0x1abd8c .word 0xffffea30 */
/* @0x1abd90 .word 0xffffc454 */
/* @0x1abd94 .word 0xffffbff4 */
/* @0x1abd98 .word 0xffffc5f4 */

/* ── FUNC 0x1abd9c · CRoom::UpdateActive() · size=464 · insn=116 */
/* @0x1abd9c ldr r1, [r0, #0x8c] */
/* @0x1abda0 push {r4, r5, r6, lr} */
/* @0x1abda4 cmp r1, #0 */
/* @0x1abda8 mov r4, r0 */
/* @0x1abdac bne 0x1abdc0 <_ZN5CRoom12UpdateActiveEv+0x24> */
/* @0x1abdb0 b 0x1abe64 <_ZN5CRoom12UpdateActiveEv+0xc8> */
/* @0x1abdb4 cmp r5, #0 */
/* @0x1abdb8 beq 0x1abe64 <_ZN5CRoom12UpdateActiveEv+0xc8> */
/* @0x1abdbc mov r1, r5 */
/* @0x1abdc0 ldrb r3, [r1, #0x69] */
/* @0x1abdc4 ldr r5, [r1, #0x178] */
/* @0x1abdc8 cmp r3, #0 */
/* @0x1abdcc bne 0x1abdb4 <_ZN5CRoom12UpdateActiveEv+0x18> */
/* @0x1abdd0 ldr r3, [r1, #0x17c] */
/* @0x1abdd4 ldr r0, [r4, #0x94] */
/* @0x1abdd8 cmp r3, #0 */
/* @0x1abddc streq r5, [r4, #0x8c] */
/* @0x1abde0 strne r5, [r3, #0x178] */
/* @0x1abde4 sub r0, r0, #1 */
/* @0x1abde8 ldrne r2, [r1, #0x178] */
/* @0x1abdec moveq r2, r5 */
/* @0x1abdf0 ldrne r3, [r1, #0x17c] */
/* @0x1abdf4 cmp r2, #0 */
/* @0x1abdf8 streq r3, [r4, #0x90] */
/* @0x1abdfc strne r3, [r2, #0x17c] */
/* @0x1abe00 ldr r3, [r4, #0x84] */
/* @0x1abe04 ldr r2, [r4, #0x88] */
/* @0x1abe08 cmp r3, #0 */
/* @0x1abe0c str r0, [r4, #0x94] */
/* @0x1abe10 add r2, r2, #1 */
/* @0x1abe14 vldrne s14, [r1, #384] */
/* @0x1abe18 str r2, [r4, #0x88] */
/* @0x1abe1c beq 0x1abf50 <_ZN5CRoom12UpdateActiveEv+0x1b4> */
/* @0x1abe20 vldr s15, [r3, #388] */
/* @0x1abe24 vcmpe.f32 s15, s14 */
/* @0x1abe28 vmrs APSR_nzcv, fpscr */
/* @0x1abe2c bls 0x1abf1c <_ZN5CRoom12UpdateActiveEv+0x180> */
/* @0x1abe30 ldr r3, [r3, #0x17c] */
/* @0x1abe34 cmp r3, #0 */
/* @0x1abe38 bne 0x1abe20 <_ZN5CRoom12UpdateActiveEv+0x84> */
/* @0x1abe3c ldr r2, [r4, #0x80] */
/* @0x1abe40 vstr s14, [r1, #388] */
/* @0x1abe44 str r1, [r2, #0x17c] */
/* @0x1abe48 str r2, [r1, #0x178] */
/* @0x1abe4c str r1, [r4, #0x80] */
/* @0x1abe50 str r3, [r1, #0x17c] */
/* @0x1abe54 ldr r0, [r1, #0x80] */
/* @0x1abe58 bl 0x19e02c <_ZN9CObjectGM11AddInstanceEP9CInstance> */
/* @0x1abe5c cmp r5, #0 */
/* @0x1abe60 bne 0x1abdbc <_ZN5CRoom12UpdateActiveEv+0x20> */
/* @0x1abe64 ldr r1, [r4, #0x80] */
/* @0x1abe68 cmp r1, #0 */
/* @0x1abe6c popeq {r4, r5, r6, pc} */
/* @0x1abe70 mov r6, #0 */
/* @0x1abe74 b 0x1abe84 <_ZN5CRoom12UpdateActiveEv+0xe8> */
/* @0x1abe78 cmp r5, #0 */
/* @0x1abe7c popeq {r4, r5, r6, pc} */
/* @0x1abe80 mov r1, r5 */
/* @0x1abe84 ldrb r3, [r1, #0x69] */
/* @0x1abe88 ldr r5, [r1, #0x178] */
/* @0x1abe8c cmp r3, #0 */
/* @0x1abe90 beq 0x1abe78 <_ZN5CRoom12UpdateActiveEv+0xdc> */
/* @0x1abe94 ldr r3, [r1, #0x17c] */
/* @0x1abe98 ldr r0, [r4, #0x88] */
/* @0x1abe9c cmp r3, #0 */
/* @0x1abea0 streq r5, [r4, #0x80] */
/* @0x1abea4 strne r5, [r3, #0x178] */
/* @0x1abea8 sub r0, r0, #1 */
/* @0x1abeac ldrne r2, [r1, #0x178] */
/* @0x1abeb0 moveq r2, r5 */
/* @0x1abeb4 ldrne r3, [r1, #0x17c] */
/* @0x1abeb8 cmp r2, #0 */
/* @0x1abebc streq r3, [r4, #0x84] */
/* @0x1abec0 strne r3, [r2, #0x17c] */
/* @0x1abec4 ldr r3, [r4, #0x90] */
/* @0x1abec8 ldr r2, [r4, #0x94] */
/* @0x1abecc cmp r3, #0 */
/* @0x1abed0 str r6, [r1, #0x178] */
/* @0x1abed4 str r6, [r1, #0x17c] */
/* @0x1abed8 add r2, r2, #1 */
/* @0x1abedc str r0, [r4, #0x88] */
/* @0x1abee0 str r2, [r4, #0x94] */
/* @0x1abee4 strne r1, [r3, #0x178] */
/* @0x1abee8 ldrne r3, [r4, #0x90] */
/* @0x1abeec streq r1, [r4, #0x90] */
/* @0x1abef0 streq r1, [r4, #0x8c] */
/* @0x1abef4 strne r3, [r1, #0x17c] */
/* @0x1abef8 streq r3, [r1, #0x17c] */
/* @0x1abefc strne r1, [r4, #0x90] */
/* @0x1abf00 streq r3, [r1, #0x178] */
/* @0x1abf04 strne r6, [r1, #0x178] */
/* @0x1abf08 ldr r0, [r1, #0x80] */
/* @0x1abf0c bl 0x19e0fc <_ZN9CObjectGM14RemoveInstanceEP9CInstance> */
/* @0x1abf10 cmp r5, #0 */
/* @0x1abf14 bne 0x1abe80 <_ZN5CRoom12UpdateActiveEv+0xe4> */
/* @0x1abf18 pop {r4, r5, r6, pc} */
/* @0x1abf1c ldr r2, [r3, #0x178] */
/* @0x1abf20 cmp r2, #0 */
/* @0x1abf24 streq r3, [r1, #0x17c] */
/* @0x1abf28 strne r2, [r1, #0x178] */
/* @0x1abf2c ldrne r2, [r3, #0x178] */
/* @0x1abf30 streq r1, [r3, #0x178] */
/* @0x1abf34 strne r3, [r1, #0x17c] */
/* @0x1abf38 streq r1, [r4, #0x84] */
/* @0x1abf3c strne r1, [r2, #0x17c] */
/* @0x1abf40 streq r2, [r1, #0x178] */
/* @0x1abf44 strne r1, [r3, #0x178] */
/* @0x1abf48 vstr s14, [r1, #388] */
/* @0x1abf4c b 0x1abe54 <_ZN5CRoom12UpdateActiveEv+0xb8> */
/* @0x1abf50 ldr r2, [r1, #0x180] */
/* @0x1abf54 str r1, [r4, #0x84] */
/* @0x1abf58 str r1, [r4, #0x80] */
/* @0x1abf5c str r2, [r1, #0x184] */
/* @0x1abf60 str r3, [r1, #0x17c] */
/* @0x1abf64 str r3, [r1, #0x178] */
/* @0x1abf68 b 0x1abe54 <_ZN5CRoom12UpdateActiveEv+0xb8> */

/* ── FUNC 0x1abf6c · _GetSpriteFrames(int) · size=48 · insn=12 */
/* @0x1abf6c push {r4, lr} */
/* @0x1abf70 mov r4, r0 */
/* @0x1abf74 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1abf78 cmp r0, #0 */
/* @0x1abf7c popeq {r4, pc} */
/* @0x1abf80 mov r0, r4 */
/* @0x1abf84 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1abf88 ldr r3, [r0, #0x74] */
/* @0x1abf8c cmp r3, #2 */
/* @0x1abf90 ldrne r0, [r0, #0x18] */
/* @0x1abf94 moveq r0, #1 */
/* @0x1abf98 pop {r4, pc} */

/* ── FUNC 0x1abf9c · anon_1abf9c · size=4 · insn=1 */
/* @0x1abf9c andeq r0, r0, r0 */

/* ── FUNC 0x1abfa0 · CRoom::UpdateLayers() · size=608 · insn=152 */
/* @0x1abfa0 push {r3, r4, r5, r6, r7, lr} */
/* @0x1abfa4 vpush {d8, d9, d10} */
/* @0x1abfa8 ldr r3, [pc, #0x248] */
/* @0x1abfac ldr r3, [pc, r3] */
/* @0x1abfb0 ldrb r3, [r3] */
/* @0x1abfb4 cmp r3, #0 */
/* @0x1abfb8 beq 0x1ac0d0 <_ZN5CRoom12UpdateLayersEv+0x130> */
/* @0x1abfbc ldr r5, [r0, #0xd4] */
/* @0x1abfc0 cmp r5, #0 */
/* @0x1abfc4 beq 0x1ac0d0 <_ZN5CRoom12UpdateLayersEv+0x130> */
/* @0x1abfc8 ldr r6, [pc, #0x22c] */
/* @0x1abfcc vldr d10, [pc, #540] */
/* @0x1abfd0 ldr r6, [pc, r6] */
/* @0x1abfd4 mov r0, r6 */
/* @0x1abfd8 bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0x1abfdc vldr s14, [r5, #8] */
/* @0x1abfe0 vldr s15, [r5, #16] */
/* @0x1abfe4 vldr s13, [r5, #12] */
/* @0x1abfe8 vadd.f32 s14, s14, s15 */
/* @0x1abfec vldr s15, [r5, #20] */
/* @0x1abff0 ldr r4, [r5, #0x58] */
/* @0x1abff4 cmp r4, #0 */
/* @0x1abff8 vadd.f32 s15, s13, s15 */
/* @0x1abffc vstr s14, [r5, #8] */
/* @0x1ac000 vstr s15, [r5, #12] */
/* @0x1ac004 vmov d8, r0, r1 */
/* @0x1ac008 bne 0x1ac034 <_ZN5CRoom12UpdateLayersEv+0x94> */
/* @0x1ac00c b 0x1ac0c4 <_ZN5CRoom12UpdateLayersEv+0x124> */
/* @0x1ac010 cmp r3, #4 */
/* @0x1ac014 beq 0x1ac0d8 <_ZN5CRoom12UpdateLayersEv+0x138> */
/* @0x1ac018 cmp r3, #5 */
/* @0x1ac01c beq 0x1ac16c <_ZN5CRoom12UpdateLayersEv+0x1cc> */
/* @0x1ac020 cmp r3, #2 */
/* @0x1ac024 beq 0x1ac144 <_ZN5CRoom12UpdateLayersEv+0x1a4> */
/* @0x1ac028 ldr r4, [r4, #0x14] */
/* @0x1ac02c cmp r4, #0 */
/* @0x1ac030 beq 0x1ac0c4 <_ZN5CRoom12UpdateLayersEv+0x124> */
/* @0x1ac034 ldr r3, [r4] */
/* @0x1ac038 cmp r3, #1 */
/* @0x1ac03c bne 0x1ac010 <_ZN5CRoom12UpdateLayersEv+0x70> */
/* @0x1ac040 ldr r3, [r4, #0x1c] */
/* @0x1ac044 cmp r3, #0 */
/* @0x1ac048 beq 0x1ac028 <_ZN5CRoom12UpdateLayersEv+0x88> */
/* @0x1ac04c ldr r2, [r3, #0x28] */
/* @0x1ac050 cmp r2, #1 */
/* @0x1ac054 beq 0x1ac1c4 <_ZN5CRoom12UpdateLayersEv+0x224> */
/* @0x1ac058 vcmp.f64 d8, #0 */
/* @0x1ac05c vmrs APSR_nzcv, fpscr */
/* @0x1ac060 beq 0x1ac07c <_ZN5CRoom12UpdateLayersEv+0xdc> */
/* @0x1ac064 vcvt.f32.f64 s15, d8 */
/* @0x1ac068 vldr s13, [r3, #36] */
/* @0x1ac06c vldr s14, [r3, #32] */
/* @0x1ac070 vdiv.f32 s15, s13, s15 */
/* @0x1ac074 vadd.f32 s15, s14, s15 */
/* @0x1ac078 vstr s15, [r3, #32] */
/* @0x1ac07c ldr r0, [r3, #0x4] */
/* @0x1ac080 bl 0x1abf6c <_Z16_GetSpriteFramesi> */
/* @0x1ac084 ldr r3, [r4, #0x1c] */
/* @0x1ac088 vldr s15, [r3, #32] */
/* @0x1ac08c vmov s12, r0 */
/* @0x1ac090 vcvt.f32.s32 s14, s12 */
/* @0x1ac094 vcmpe.f32 s15, s14 */
/* @0x1ac098 vmrs APSR_nzcv, fpscr */
/* @0x1ac09c vsubge.f32 s15, s15, s14 */
/* @0x1ac0a0 vstrge s15, [r3, #32] */
/* @0x1ac0a4 bge 0x1ac028 <_ZN5CRoom12UpdateLayersEv+0x88> */
/* @0x1ac0a8 vcmpe.f32 s15, #0 */
/* @0x1ac0ac ldr r4, [r4, #0x14] */
/* @0x1ac0b0 vmrs APSR_nzcv, fpscr */
/* @0x1ac0b4 vaddmi.f32 s15, s15, s14 */
/* @0x1ac0b8 vstrmi s15, [r3, #32] */
/* @0x1ac0bc cmp r4, #0 */
/* @0x1ac0c0 bne 0x1ac034 <_ZN5CRoom12UpdateLayersEv+0x94> */
/* @0x1ac0c4 ldr r5, [r5, #0x68] */
/* @0x1ac0c8 cmp r5, #0 */
/* @0x1ac0cc bne 0x1abfd4 <_ZN5CRoom12UpdateLayersEv+0x34> */
/* @0x1ac0d0 vpop {d8, d9, d10} */
/* @0x1ac0d4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1ac0d8 ldr r3, [r4, #0x28] */
/* @0x1ac0dc cmp r3, #1 */
/* @0x1ac0e0 beq 0x1ac1d8 <_ZN5CRoom12UpdateLayersEv+0x238> */
/* @0x1ac0e4 vcmp.f64 d8, #0 */
/* @0x1ac0e8 vmrs APSR_nzcv, fpscr */
/* @0x1ac0ec beq 0x1ac108 <_ZN5CRoom12UpdateLayersEv+0x168> */
/* @0x1ac0f0 vcvt.f32.f64 s15, d8 */
/* @0x1ac0f4 vldr s13, [r4, #36] */
/* @0x1ac0f8 vldr s14, [r4, #32] */
/* @0x1ac0fc vdiv.f32 s15, s13, s15 */
/* @0x1ac100 vadd.f32 s15, s14, s15 */
/* @0x1ac104 vstr s15, [r4, #32] */
/* @0x1ac108 ldr r0, [r4, #0x1c] */
/* @0x1ac10c bl 0x1abf6c <_Z16_GetSpriteFramesi> */
/* @0x1ac110 vldr s15, [r4, #32] */
/* @0x1ac114 vmov s13, r0 */
/* @0x1ac118 vcvt.f32.s32 s14, s13 */
/* @0x1ac11c vcmpe.f32 s15, s14 */
/* @0x1ac120 vmrs APSR_nzcv, fpscr */
/* @0x1ac124 vsubge.f32 s15, s15, s14 */
/* @0x1ac128 vstrge s15, [r4, #32] */
/* @0x1ac12c bge 0x1ac028 <_ZN5CRoom12UpdateLayersEv+0x88> */
/* @0x1ac130 vcmpe.f32 s15, #0 */
/* @0x1ac134 vmrs APSR_nzcv, fpscr */
/* @0x1ac138 vaddmi.f32 s15, s15, s14 */
/* @0x1ac13c vstrmi s15, [r4, #32] */
/* @0x1ac140 b 0x1ac028 <_ZN5CRoom12UpdateLayersEv+0x88> */
/* @0x1ac144 ldr r3, [r4, #0x20] */
/* @0x1ac148 cmp r3, #0 */
/* @0x1ac14c beq 0x1ac028 <_ZN5CRoom12UpdateLayersEv+0x88> */
/* @0x1ac150 ldrb r3, [r3, #0x69] */
/* @0x1ac154 cmp r3, #0 */
/* @0x1ac158 beq 0x1ac028 <_ZN5CRoom12UpdateLayersEv+0x88> */
/* @0x1ac15c ldr r5, [r5, #0x68] */
/* @0x1ac160 cmp r5, #0 */
/* @0x1ac164 bne 0x1abfd4 <_ZN5CRoom12UpdateLayersEv+0x34> */
/* @0x1ac168 b 0x1ac0d0 <_ZN5CRoom12UpdateLayersEv+0x130> */
/* @0x1ac16c ldr r0, [r4, #0x1c] */
/* @0x1ac170 bl 0xc3794 <_Z15Background_Datai> */
/* @0x1ac174 subs r7, r0, #0 */
/* @0x1ac178 beq 0x1ac028 <_ZN5CRoom12UpdateLayersEv+0x88> */
/* @0x1ac17c ldrd r0, r1, [r7, #56] */
/* @0x1ac180 vldr s18, [r4, #48] */
/* @0x1ac184 bl 0x319164 <__floatdidf> */
/* @0x1ac188 vcvt.f64.f32 d9, s18 */
/* @0x1ac18c ldr r3, [r7, #0x30] */
/* @0x1ac190 vmov d6, r0, r1 */
/* @0x1ac194 vdiv.f64 d7, d10, d6 */
/* @0x1ac198 vmov s13, r3 */
/* @0x1ac19c vdiv.f64 d7, d7, d8 */
/* @0x1ac1a0 vadd.f64 d9, d9, d7 */
/* @0x1ac1a4 vcvt.f32.s32 s13, s13 */
/* @0x1ac1a8 vcvt.f32.f64 s18, d9 */
/* @0x1ac1ac vmov r1, s13 */
/* @0x1ac1b0 vstr s18, [r4, #48] */
/* @0x1ac1b4 vmov r0, s18 */
/* @0x1ac1b8 bl 0xb6790 <fmodf@plt> */
/* @0x1ac1bc str r0, [r4, #0x30] */
/* @0x1ac1c0 b 0x1ac028 <_ZN5CRoom12UpdateLayersEv+0x88> */
/* @0x1ac1c4 vldr s14, [r3, #32] */
/* @0x1ac1c8 vldr s15, [r3, #36] */
/* @0x1ac1cc vadd.f32 s15, s14, s15 */
/* @0x1ac1d0 vstr s15, [r3, #32] */
/* @0x1ac1d4 b 0x1ac07c <_ZN5CRoom12UpdateLayersEv+0xdc> */
/* @0x1ac1d8 vldr s14, [r4, #32] */
/* @0x1ac1dc vldr s15, [r4, #36] */
/* @0x1ac1e0 vadd.f32 s15, s14, s15 */
/* @0x1ac1e4 vstr s15, [r4, #32] */
/* @0x1ac1e8 b 0x1ac108 <_ZN5CRoom12UpdateLayersEv+0x168> */
/* @0x1ac1ec nop */
/* @0x1ac1f0 andeq r0, r0, r0 */
/* @0x1ac1f4 smlawbmi lr, r0, r4, r8 */
/* @0x1ac1f8 eoreq r1, r4, r8, ror r9 */
/* @0x1ac1fc eoreq r1, r4, r12, asr r9 */

/* ── FUNC 0x1ac200 · CRoom::ScrollBackground() · size=64 · insn=16 */
/* @0x1ac200 mov r2, #8 */
/* @0x1ac204 ldr r3, [r0, #0x24] */
/* @0x1ac208 add r0, r0, #4 */
/* @0x1ac20c cmp r3, #0 */
/* @0x1ac210 beq 0x1ac234 <_ZN5CRoom16ScrollBackgroundEv+0x34> */
/* @0x1ac214 vldr s14, [r3, #8] */
/* @0x1ac218 vldr s15, [r3, #20] */
/* @0x1ac21c vldr s13, [r3, #12] */
/* @0x1ac220 vadd.f32 s14, s14, s15 */
/* @0x1ac224 vldr s15, [r3, #24] */
/* @0x1ac228 vadd.f32 s15, s13, s15 */
/* @0x1ac22c vstr s14, [r3, #8] */
/* @0x1ac230 vstr s15, [r3, #12] */
/* @0x1ac234 subs r2, r2, #1 */
/* @0x1ac238 bne 0x1ac204 <_ZN5CRoom16ScrollBackgroundEv+0x4> */
/* @0x1ac23c bx lr */

/* ── FUNC 0x1ac240 · CRoom::AddTile(RTile*) · size=252 · insn=63 */
/* @0x1ac240 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1ac244 mov r6, r0 */
/* @0x1ac248 ldr r5, [r0, #0xb8] */
/* @0x1ac24c sub sp, sp, #12 */
/* @0x1ac250 ldr r3, [r0, #0xbc] */
/* @0x1ac254 mov r4, r1 */
/* @0x1ac258 cmp r5, r3 */
/* @0x1ac25c bge 0x1ac2c0 <_ZN5CRoom7AddTileEP5RTile+0x80> */
/* @0x1ac260 ldr r8, [r0, #0xc0] */
/* @0x1ac264 ldm r4!, {r0, r1, r2, r3} */
/* @0x1ac268 rsb r12, r5, r5, lsl #3 */
/* @0x1ac26c ldr r7, [pc, #0xc0] */
/* @0x1ac270 add r8, r8, r12, lsl #3 */
/* @0x1ac274 add r12, r5, #1 */
/* @0x1ac278 str r12, [r6, #0xb8] */
/* @0x1ac27c ldr r7, [pc, r7] */
/* @0x1ac280 mov r12, r8 */
/* @0x1ac284 stm r12!, {r0, r1, r2, r3} */
/* @0x1ac288 ldm r4!, {r0, r1, r2, r3} */
/* @0x1ac28c ldr r9, [r7] */
/* @0x1ac290 add r9, r9, #1 */
/* @0x1ac294 str r9, [r7] */
/* @0x1ac298 stm r12!, {r0, r1, r2, r3} */
/* @0x1ac29c ldm r4!, {r0, r1, r2, r3} */
/* @0x1ac2a0 stm r12!, {r0, r1, r2, r3} */
/* @0x1ac2a4 ldm r4, {r0, r1} */
/* @0x1ac2a8 stm r12, {r0, r1} */
/* @0x1ac2ac mov r0, r5 */
/* @0x1ac2b0 str r9, [r8, #0x20] */
/* @0x1ac2b4 str r5, [r6] */
/* @0x1ac2b8 add sp, sp, #12 */
/* @0x1ac2bc pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1ac2c0 adds r7, r5, #10 */
/* @0x1ac2c4 beq 0x1ac304 <_ZN5CRoom7AddTileEP5RTile+0xc4> */
/* @0x1ac2c8 rsb r1, r7, r7, lsl #3 */
/* @0x1ac2cc ldr r0, [r0, #0xc0] */
/* @0x1ac2d0 lsls r1, r1, #3 */
/* @0x1ac2d4 beq 0x1ac320 <_ZN5CRoom7AddTileEP5RTile+0xe0> */
/* @0x1ac2d8 ldr r2, [pc, #0x58] */
/* @0x1ac2dc mov r3, #0 */
/* @0x1ac2e0 str r3, [sp] */
/* @0x1ac2e4 mov r3, #106 */
/* @0x1ac2e8 add r2, pc, r2 */
/* @0x1ac2ec bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1ac2f0 mov r8, r0 */
/* @0x1ac2f4 str r0, [r6, #0xc0] */
/* @0x1ac2f8 ldr r5, [r6, #0xb8] */
/* @0x1ac2fc str r7, [r6, #0xbc] */
/* @0x1ac300 b 0x1ac264 <_ZN5CRoom7AddTileEP5RTile+0x24> */
/* @0x1ac304 ldr r0, [r0, #0xc0] */
/* @0x1ac308 cmp r0, #0 */
/* @0x1ac30c beq 0x1ac320 <_ZN5CRoom7AddTileEP5RTile+0xe0> */
/* @0x1ac310 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ac314 mov r8, r7 */
/* @0x1ac318 str r7, [r6, #0xc0] */
/* @0x1ac31c b 0x1ac2f8 <_ZN5CRoom7AddTileEP5RTile+0xb8> */
/* @0x1ac320 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ac324 mov r3, #0 */
/* @0x1ac328 mov r8, r3 */
/* @0x1ac32c str r3, [r6, #0xc0] */
/* @0x1ac330 b 0x1ac2f8 <_ZN5CRoom7AddTileEP5RTile+0xb8> */
/* @0x1ac334 mlaeq r4, r4, r5, r4 */
/* @0x1ac338 andseq r0, r10, r12, asr #30 */

/* ── FUNC 0x1ac33c · CRoom::DeSerialise(IBuffer*, bool) · size=3364 · insn=841 */
/* @0x1ac33c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ac340 mov r6, r0 */
/* @0x1ac344 sub sp, sp, #100 */
/* @0x1ac348 mov r0, r1 */
/* @0x1ac34c mov r4, r1 */
/* @0x1ac350 mov r11, r2 */
/* @0x1ac354 bl 0xcde74 <_ZN7IBuffer10ReadStringEv> */
/* @0x1ac358 ldr r3, [r4] */
/* @0x1ac35c add r5, r4, #44 */
/* @0x1ac360 ldr r12, [pc, #0xce0] */
/* @0x1ac364 mov r1, #6 */
/* @0x1ac368 mov r9, r6 */
/* @0x1ac36c add r12, pc, r12 */
/* @0x1ac370 mov r2, r5 */
/* @0x1ac374 str r12, [sp, #0x1c] */
/* @0x1ac378 mov r8, #8 */
/* @0x1ac37c str r0, [r6, #0x8] */
/* @0x1ac380 mov r0, r4 */
/* @0x1ac384 ldr r3, [r3, #0xc] */
/* @0x1ac388 blx r3 */
/* @0x1ac38c mov r1, #0 */
/* @0x1ac390 mov r0, r5 */
/* @0x1ac394 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac398 ldr r3, [r4] */
/* @0x1ac39c mov r2, r5 */
/* @0x1ac3a0 mov r1, #6 */
/* @0x1ac3a4 ldr r3, [r3, #0xc] */
/* @0x1ac3a8 str r0, [r6, #0x10] */
/* @0x1ac3ac mov r0, r4 */
/* @0x1ac3b0 blx r3 */
/* @0x1ac3b4 mov r1, #0 */
/* @0x1ac3b8 mov r0, r5 */
/* @0x1ac3bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac3c0 ldr r3, [r4] */
/* @0x1ac3c4 mov r2, r5 */
/* @0x1ac3c8 mov r1, #6 */
/* @0x1ac3cc ldr r3, [r3, #0xc] */
/* @0x1ac3d0 str r0, [r6, #0x14] */
/* @0x1ac3d4 mov r0, r4 */
/* @0x1ac3d8 blx r3 */
/* @0x1ac3dc mov r1, #0 */
/* @0x1ac3e0 mov r0, r5 */
/* @0x1ac3e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac3e8 ldr r3, [r4] */
/* @0x1ac3ec mov r2, r5 */
/* @0x1ac3f0 mov r1, #6 */
/* @0x1ac3f4 ldr r3, [r3, #0xc] */
/* @0x1ac3f8 str r0, [r6, #0xc] */
/* @0x1ac3fc mov r0, r4 */
/* @0x1ac400 blx r3 */
/* @0x1ac404 mov r1, #0 */
/* @0x1ac408 mov r0, r5 */
/* @0x1ac40c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1ac410 ldr r3, [r4] */
/* @0x1ac414 mov r2, r5 */
/* @0x1ac418 mov r1, #5 */
/* @0x1ac41c ldr r3, [r3, #0xc] */
/* @0x1ac420 strb r0, [r6, #0x18] */
/* @0x1ac424 mov r0, r4 */
/* @0x1ac428 blx r3 */
/* @0x1ac42c mov r1, #0 */
/* @0x1ac430 mov r0, r5 */
/* @0x1ac434 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x1ac438 ldr r3, [r4] */
/* @0x1ac43c mov r2, r5 */
/* @0x1ac440 mov r1, #6 */
/* @0x1ac444 ldr r3, [r3, #0xc] */
/* @0x1ac448 str r0, [r6, #0x1c] */
/* @0x1ac44c mov r0, r4 */
/* @0x1ac450 blx r3 */
/* @0x1ac454 mov r1, #0 */
/* @0x1ac458 mov r0, r5 */
/* @0x1ac45c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1ac460 strb r0, [r6, #0x20] */
/* @0x1ac464 mov r0, r4 */
/* @0x1ac468 bl 0xcde74 <_ZN7IBuffer10ReadStringEv> */
/* @0x1ac46c str r0, [r6, #0x68] */
/* @0x1ac470 ldr r3, [r4] */
/* @0x1ac474 mov r2, r5 */
/* @0x1ac478 mov r1, #6 */
/* @0x1ac47c mov r0, r4 */
/* @0x1ac480 ldr r7, [r9, #0x24] */
/* @0x1ac484 add r9, r9, #4 */
/* @0x1ac488 ldr r3, [r3, #0xc] */
/* @0x1ac48c blx r3 */
/* @0x1ac490 mov r1, #0 */
/* @0x1ac494 mov r0, r5 */
/* @0x1ac498 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1ac49c ldr r3, [r4] */
/* @0x1ac4a0 mov r2, r5 */
/* @0x1ac4a4 mov r1, #6 */
/* @0x1ac4a8 ldr r3, [r3, #0xc] */
/* @0x1ac4ac strb r0, [r7] */
/* @0x1ac4b0 mov r0, r4 */
/* @0x1ac4b4 blx r3 */
/* @0x1ac4b8 mov r1, #0 */
/* @0x1ac4bc mov r0, r5 */
/* @0x1ac4c0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1ac4c4 ldr r3, [r4] */
/* @0x1ac4c8 mov r2, r5 */
/* @0x1ac4cc mov r1, #6 */
/* @0x1ac4d0 ldr r3, [r3, #0xc] */
/* @0x1ac4d4 strb r0, [r7, #0x1] */
/* @0x1ac4d8 mov r0, r4 */
/* @0x1ac4dc blx r3 */
/* @0x1ac4e0 mov r1, #0 */
/* @0x1ac4e4 mov r0, r5 */
/* @0x1ac4e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac4ec ldr r3, [r4] */
/* @0x1ac4f0 mov r2, r5 */
/* @0x1ac4f4 mov r1, #8 */
/* @0x1ac4f8 ldr r3, [r3, #0xc] */
/* @0x1ac4fc str r0, [r7, #0x4] */
/* @0x1ac500 mov r0, r4 */
/* @0x1ac504 blx r3 */
/* @0x1ac508 mov r1, #0 */
/* @0x1ac50c mov r0, r5 */
/* @0x1ac510 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1ac514 ldr r3, [r4] */
/* @0x1ac518 mov r2, r5 */
/* @0x1ac51c mov r1, #8 */
/* @0x1ac520 ldr r3, [r3, #0xc] */
/* @0x1ac524 str r0, [r7, #0x8] */
/* @0x1ac528 mov r0, r4 */
/* @0x1ac52c blx r3 */
/* @0x1ac530 mov r1, #0 */
/* @0x1ac534 mov r0, r5 */
/* @0x1ac538 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1ac53c ldr r3, [r4] */
/* @0x1ac540 mov r2, r5 */
/* @0x1ac544 mov r1, #6 */
/* @0x1ac548 ldr r3, [r3, #0xc] */
/* @0x1ac54c str r0, [r7, #0xc] */
/* @0x1ac550 mov r0, r4 */
/* @0x1ac554 blx r3 */
/* @0x1ac558 mov r1, #0 */
/* @0x1ac55c mov r0, r5 */
/* @0x1ac560 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1ac564 ldr r3, [r4] */
/* @0x1ac568 mov r2, r5 */
/* @0x1ac56c mov r1, #6 */
/* @0x1ac570 ldr r3, [r3, #0xc] */
/* @0x1ac574 strb r0, [r7, #0x10] */
/* @0x1ac578 mov r0, r4 */
/* @0x1ac57c blx r3 */
/* @0x1ac580 mov r1, #0 */
/* @0x1ac584 mov r0, r5 */
/* @0x1ac588 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1ac58c ldr r3, [r4] */
/* @0x1ac590 mov r2, r5 */
/* @0x1ac594 mov r1, #8 */
/* @0x1ac598 ldr r3, [r3, #0xc] */
/* @0x1ac59c strb r0, [r7, #0x11] */
/* @0x1ac5a0 mov r0, r4 */
/* @0x1ac5a4 blx r3 */
/* @0x1ac5a8 mov r1, #0 */
/* @0x1ac5ac mov r0, r5 */
/* @0x1ac5b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1ac5b4 ldr r3, [r4] */
/* @0x1ac5b8 mov r2, r5 */
/* @0x1ac5bc mov r1, #8 */
/* @0x1ac5c0 ldr r3, [r3, #0xc] */
/* @0x1ac5c4 str r0, [r7, #0x14] */
/* @0x1ac5c8 mov r0, r4 */
/* @0x1ac5cc blx r3 */
/* @0x1ac5d0 mov r1, #0 */
/* @0x1ac5d4 mov r0, r5 */
/* @0x1ac5d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1ac5dc ldr r3, [r4] */
/* @0x1ac5e0 mov r2, r5 */
/* @0x1ac5e4 mov r1, #8 */
/* @0x1ac5e8 ldr r3, [r3, #0xc] */
/* @0x1ac5ec str r0, [r7, #0x18] */
/* @0x1ac5f0 mov r0, r4 */
/* @0x1ac5f4 blx r3 */
/* @0x1ac5f8 mov r1, #0 */
/* @0x1ac5fc mov r0, r5 */
/* @0x1ac600 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1ac604 ldr r3, [r4] */
/* @0x1ac608 mov r2, r5 */
/* @0x1ac60c mov r1, #8 */
/* @0x1ac610 ldr r3, [r3, #0xc] */
/* @0x1ac614 str r0, [r7, #0x1c] */
/* @0x1ac618 mov r0, r4 */
/* @0x1ac61c blx r3 */
/* @0x1ac620 mov r1, #0 */
/* @0x1ac624 mov r0, r5 */
/* @0x1ac628 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1ac62c ldr r3, [r4] */
/* @0x1ac630 mov r2, r5 */
/* @0x1ac634 mov r1, #6 */
/* @0x1ac638 ldr r3, [r3, #0xc] */
/* @0x1ac63c str r0, [r7, #0x20] */
/* @0x1ac640 mov r0, r4 */
/* @0x1ac644 blx r3 */
/* @0x1ac648 mov r1, #0 */
/* @0x1ac64c mov r0, r5 */
/* @0x1ac650 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac654 ldr r3, [r4] */
/* @0x1ac658 mov r1, #8 */
/* @0x1ac65c mov r2, r5 */
/* @0x1ac660 ldr r3, [r3, #0xc] */
/* @0x1ac664 str r0, [r7, #0x24] */
/* @0x1ac668 mov r0, r4 */
/* @0x1ac66c blx r3 */
/* @0x1ac670 mov r0, r5 */
/* @0x1ac674 mov r1, #0 */
/* @0x1ac678 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1ac67c subs r8, r8, #1 */
/* @0x1ac680 str r0, [r7, #0x28] */
/* @0x1ac684 bne 0x1ac470 <_ZN5CRoom11DeSerialiseEP7IBufferb+0x134> */
/* @0x1ac688 ldr r3, [r4] */
/* @0x1ac68c mov r1, #6 */
/* @0x1ac690 mov r2, r5 */
/* @0x1ac694 mov r0, r4 */
/* @0x1ac698 mov r10, r8 */
/* @0x1ac69c mov r9, r6 */
/* @0x1ac6a0 ldr r3, [r3, #0xc] */
/* @0x1ac6a4 blx r3 */
/* @0x1ac6a8 mov r0, r5 */
/* @0x1ac6ac mov r1, r8 */
/* @0x1ac6b0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1ac6b4 strb r0, [r6, #0x44] */
/* @0x1ac6b8 ldr r3, [r4] */
/* @0x1ac6bc mov r2, r5 */
/* @0x1ac6c0 mov r1, #6 */
/* @0x1ac6c4 mov r0, r4 */
/* @0x1ac6c8 ldr r7, [r9, #0x48] */
/* @0x1ac6cc add r10, r10, #1 */
/* @0x1ac6d0 ldr r3, [r3, #0xc] */
/* @0x1ac6d4 add r9, r9, #4 */
/* @0x1ac6d8 blx r3 */
/* @0x1ac6dc mov r1, #0 */
/* @0x1ac6e0 mov r0, r5 */
/* @0x1ac6e4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1ac6e8 ldr r3, [r4] */
/* @0x1ac6ec mov r2, r5 */
/* @0x1ac6f0 mov r1, #6 */
/* @0x1ac6f4 ldr r3, [r3, #0xc] */
/* @0x1ac6f8 strb r0, [r7] */
/* @0x1ac6fc mov r0, r4 */
/* @0x1ac700 blx r3 */
/* @0x1ac704 mov r1, #0 */
/* @0x1ac708 mov r0, r5 */
/* @0x1ac70c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac710 ldr r3, [r4] */
/* @0x1ac714 mov r2, r5 */
/* @0x1ac718 mov r1, #6 */
/* @0x1ac71c ldr r3, [r3, #0xc] */
/* @0x1ac720 vmov s14, r0 */
/* @0x1ac724 mov r0, r4 */
/* @0x1ac728 vcvt.f32.s32 s15, s14 */
/* @0x1ac72c vstr s15, [r7, #4] */
/* @0x1ac730 blx r3 */
/* @0x1ac734 mov r1, #0 */
/* @0x1ac738 mov r0, r5 */
/* @0x1ac73c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac740 ldr r3, [r4] */
/* @0x1ac744 mov r2, r5 */
/* @0x1ac748 mov r1, #6 */
/* @0x1ac74c ldr r3, [r3, #0xc] */
/* @0x1ac750 vmov s14, r0 */
/* @0x1ac754 mov r0, r4 */
/* @0x1ac758 vcvt.f32.s32 s15, s14 */
/* @0x1ac75c vstr s15, [r7, #8] */
/* @0x1ac760 blx r3 */
/* @0x1ac764 mov r1, #0 */
/* @0x1ac768 mov r0, r5 */
/* @0x1ac76c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac770 ldr r3, [r4] */
/* @0x1ac774 mov r2, r5 */
/* @0x1ac778 mov r1, #6 */
/* @0x1ac77c ldr r3, [r3, #0xc] */
/* @0x1ac780 vmov s14, r0 */
/* @0x1ac784 mov r0, r4 */
/* @0x1ac788 vcvt.f32.s32 s15, s14 */
/* @0x1ac78c vstr s15, [r7, #12] */
/* @0x1ac790 blx r3 */
/* @0x1ac794 mov r1, #0 */
/* @0x1ac798 mov r0, r5 */
/* @0x1ac79c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac7a0 ldr r3, [r4] */
/* @0x1ac7a4 mov r2, r5 */
/* @0x1ac7a8 mov r1, #6 */
/* @0x1ac7ac ldr r3, [r3, #0xc] */
/* @0x1ac7b0 vmov s14, r0 */
/* @0x1ac7b4 mov r0, r4 */
/* @0x1ac7b8 vcvt.f32.s32 s15, s14 */
/* @0x1ac7bc vstr s15, [r7, #16] */
/* @0x1ac7c0 blx r3 */
/* @0x1ac7c4 mov r1, #0 */
/* @0x1ac7c8 mov r0, r5 */
/* @0x1ac7cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac7d0 ldr r3, [r4] */
/* @0x1ac7d4 mov r2, r5 */
/* @0x1ac7d8 mov r1, #6 */
/* @0x1ac7dc ldr r3, [r3, #0xc] */
/* @0x1ac7e0 str r0, [r7, #0x14] */
/* @0x1ac7e4 mov r0, r4 */
/* @0x1ac7e8 blx r3 */
/* @0x1ac7ec mov r1, #0 */
/* @0x1ac7f0 mov r0, r5 */
/* @0x1ac7f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac7f8 ldr r3, [r4] */
/* @0x1ac7fc mov r2, r5 */
/* @0x1ac800 mov r1, #6 */
/* @0x1ac804 ldr r3, [r3, #0xc] */
/* @0x1ac808 str r0, [r7, #0x18] */
/* @0x1ac80c mov r0, r4 */
/* @0x1ac810 blx r3 */
/* @0x1ac814 mov r1, #0 */
/* @0x1ac818 mov r0, r5 */
/* @0x1ac81c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac820 ldr r3, [r4] */
/* @0x1ac824 mov r2, r5 */
/* @0x1ac828 mov r1, #6 */
/* @0x1ac82c ldr r3, [r3, #0xc] */
/* @0x1ac830 str r0, [r7, #0x1c] */
/* @0x1ac834 mov r0, r4 */
/* @0x1ac838 blx r3 */
/* @0x1ac83c mov r1, #0 */
/* @0x1ac840 mov r0, r5 */
/* @0x1ac844 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac848 ldr r3, [r4] */
/* @0x1ac84c mov r2, r5 */
/* @0x1ac850 mov r1, #8 */
/* @0x1ac854 ldr r3, [r3, #0xc] */
/* @0x1ac858 str r0, [r7, #0x20] */
/* @0x1ac85c mov r0, r4 */
/* @0x1ac860 blx r3 */
/* @0x1ac864 mov r1, #0 */
/* @0x1ac868 mov r0, r5 */
/* @0x1ac86c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1ac870 ldr r3, [r4] */
/* @0x1ac874 mov r2, r5 */
/* @0x1ac878 mov r1, #6 */
/* @0x1ac87c ldr r3, [r3, #0xc] */
/* @0x1ac880 str r0, [r7, #0x24] */
/* @0x1ac884 mov r0, r4 */
/* @0x1ac888 blx r3 */
/* @0x1ac88c mov r1, #0 */
/* @0x1ac890 mov r0, r5 */
/* @0x1ac894 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac898 ldr r3, [r4] */
/* @0x1ac89c mov r2, r5 */
/* @0x1ac8a0 mov r1, #6 */
/* @0x1ac8a4 ldr r3, [r3, #0xc] */
/* @0x1ac8a8 str r0, [r7, #0x28] */
/* @0x1ac8ac mov r0, r4 */
/* @0x1ac8b0 blx r3 */
/* @0x1ac8b4 mov r1, #0 */
/* @0x1ac8b8 mov r0, r5 */
/* @0x1ac8bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac8c0 ldr r3, [r4] */
/* @0x1ac8c4 mov r2, r5 */
/* @0x1ac8c8 mov r1, #6 */
/* @0x1ac8cc ldr r3, [r3, #0xc] */
/* @0x1ac8d0 str r0, [r7, #0x2c] */
/* @0x1ac8d4 mov r0, r4 */
/* @0x1ac8d8 blx r3 */
/* @0x1ac8dc mov r1, #0 */
/* @0x1ac8e0 mov r0, r5 */
/* @0x1ac8e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac8e8 ldr r3, [r4] */
/* @0x1ac8ec mov r2, r5 */
/* @0x1ac8f0 mov r1, #6 */
/* @0x1ac8f4 ldr r3, [r3, #0xc] */
/* @0x1ac8f8 str r0, [r7, #0x30] */
/* @0x1ac8fc mov r0, r4 */
/* @0x1ac900 blx r3 */
/* @0x1ac904 mov r1, #0 */
/* @0x1ac908 mov r0, r5 */
/* @0x1ac90c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac910 ldr r3, [r4] */
/* @0x1ac914 mov r2, r5 */
/* @0x1ac918 mov r1, #6 */
/* @0x1ac91c ldr r3, [r3, #0xc] */
/* @0x1ac920 str r0, [r7, #0x34] */
/* @0x1ac924 mov r0, r4 */
/* @0x1ac928 blx r3 */
/* @0x1ac92c mov r1, #0 */
/* @0x1ac930 mov r0, r5 */
/* @0x1ac934 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac938 ldr r3, [r4] */
/* @0x1ac93c mov r2, r5 */
/* @0x1ac940 mov r1, #6 */
/* @0x1ac944 ldr r3, [r3, #0xc] */
/* @0x1ac948 str r0, [r7, #0x38] */
/* @0x1ac94c mov r0, r4 */
/* @0x1ac950 blx r3 */
/* @0x1ac954 mov r1, #0 */
/* @0x1ac958 mov r0, r5 */
/* @0x1ac95c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac960 ldr r3, [r4] */
/* @0x1ac964 mov r1, #6 */
/* @0x1ac968 mov r2, r5 */
/* @0x1ac96c ldr r3, [r3, #0xc] */
/* @0x1ac970 str r0, [r7, #0x3c] */
/* @0x1ac974 mov r0, r4 */
/* @0x1ac978 blx r3 */
/* @0x1ac97c mov r0, r5 */
/* @0x1ac980 mov r1, #0 */
/* @0x1ac984 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac988 cmp r10, #8 */
/* @0x1ac98c str r0, [r7, #0x40] */
/* @0x1ac990 bne 0x1ac6b8 <_ZN5CRoom11DeSerialiseEP7IBufferb+0x37c> */
/* @0x1ac994 ldr r3, [r4] */
/* @0x1ac998 mov r1, #6 */
/* @0x1ac99c mov r2, r5 */
/* @0x1ac9a0 mov r0, r4 */
/* @0x1ac9a4 ldr r3, [r3, #0xc] */
/* @0x1ac9a8 blx r3 */
/* @0x1ac9ac mov r0, r5 */
/* @0x1ac9b0 mov r1, #0 */
/* @0x1ac9b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac9b8 subs r8, r0, #0 */
/* @0x1ac9bc bne 0x1ac9dc <_ZN5CRoom11DeSerialiseEP7IBufferb+0x6a0> */
/* @0x1ac9c0 ldr r0, [r6, #0xc0] */
/* @0x1ac9c4 cmp r0, #0 */
/* @0x1ac9c8 beq 0x1acf40 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xc04> */
/* @0x1ac9cc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ac9d0 str r8, [r6, #0xc0] */
/* @0x1ac9d4 str r8, [r6, #0xbc] */
/* @0x1ac9d8 b 0x1acc98 <_ZN5CRoom11DeSerialiseEP7IBufferb+0x95c> */
/* @0x1ac9dc rsb r3, r8, r8, lsl #3 */
/* @0x1ac9e0 ldr r0, [r6, #0xc0] */
/* @0x1ac9e4 lsls r1, r3, #3 */
/* @0x1ac9e8 beq 0x1acf40 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xc04> */
/* @0x1ac9ec ldr r2, [pc, #0x658] */
/* @0x1ac9f0 mov r3, #0 */
/* @0x1ac9f4 str r3, [sp] */
/* @0x1ac9f8 mov r3, #106 */
/* @0x1ac9fc add r2, pc, r2 */
/* @0x1aca00 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1aca04 str r0, [r6, #0xc0] */
/* @0x1aca08 cmp r8, #0 */
/* @0x1aca0c str r8, [r6, #0xbc] */
/* @0x1aca10 ble 0x1acc98 <_ZN5CRoom11DeSerialiseEP7IBufferb+0x95c> */
/* @0x1aca14 ldr r3, [pc, #0x634] */
/* @0x1aca18 add r9, sp, #40 */
/* @0x1aca1c ldr r12, [sp, #0x1c] */
/* @0x1aca20 mov r7, #0 */
/* @0x1aca24 ldr r10, [r12, r3] */
/* @0x1aca28 str r11, [sp, #0x14] */
/* @0x1aca2c ldr r3, [r4] */
/* @0x1aca30 mov r2, r5 */
/* @0x1aca34 mov r1, #8 */
/* @0x1aca38 mov r0, r4 */
/* @0x1aca3c add r7, r7, #1 */
/* @0x1aca40 ldr r3, [r3, #0xc] */
/* @0x1aca44 blx r3 */
/* @0x1aca48 mov r1, #0 */
/* @0x1aca4c mov r0, r5 */
/* @0x1aca50 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1aca54 ldr r3, [r4] */
/* @0x1aca58 mov r2, r5 */
/* @0x1aca5c mov r1, #8 */
/* @0x1aca60 ldr r3, [r3, #0xc] */
/* @0x1aca64 str r0, [sp, #0x28] */
/* @0x1aca68 mov r0, r4 */
/* @0x1aca6c blx r3 */
/* @0x1aca70 mov r1, #0 */
/* @0x1aca74 mov r0, r5 */
/* @0x1aca78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1aca7c ldr r3, [r4] */
/* @0x1aca80 mov r2, r5 */
/* @0x1aca84 mov r1, #6 */
/* @0x1aca88 ldr r3, [r3, #0xc] */
/* @0x1aca8c str r0, [sp, #0x2c] */
/* @0x1aca90 mov r0, r4 */
/* @0x1aca94 blx r3 */
/* @0x1aca98 mov r1, #0 */
/* @0x1aca9c mov r0, r5 */
/* @0x1acaa0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1acaa4 ldr r3, [r4] */
/* @0x1acaa8 mov r2, r5 */
/* @0x1acaac mov r1, #6 */
/* @0x1acab0 ldr r3, [r3, #0xc] */
/* @0x1acab4 str r0, [sp, #0x30] */
/* @0x1acab8 mov r0, r4 */
/* @0x1acabc blx r3 */
/* @0x1acac0 mov r1, #0 */
/* @0x1acac4 mov r0, r5 */
/* @0x1acac8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1acacc ldr r3, [r4] */
/* @0x1acad0 mov r2, r5 */
/* @0x1acad4 mov r1, #6 */
/* @0x1acad8 ldr r3, [r3, #0xc] */
/* @0x1acadc str r0, [sp, #0x34] */
/* @0x1acae0 mov r0, r4 */
/* @0x1acae4 blx r3 */
/* @0x1acae8 mov r1, #0 */
/* @0x1acaec mov r0, r5 */
/* @0x1acaf0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1acaf4 ldr r3, [r4] */
/* @0x1acaf8 mov r2, r5 */
/* @0x1acafc mov r1, #6 */
/* @0x1acb00 ldr r3, [r3, #0xc] */
/* @0x1acb04 str r0, [sp, #0x38] */
/* @0x1acb08 mov r0, r4 */
/* @0x1acb0c blx r3 */
/* @0x1acb10 mov r1, #0 */
/* @0x1acb14 mov r0, r5 */
/* @0x1acb18 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1acb1c ldr r3, [r4] */
/* @0x1acb20 mov r2, r5 */
/* @0x1acb24 mov r1, #6 */
/* @0x1acb28 ldr r3, [r3, #0xc] */
/* @0x1acb2c str r0, [sp, #0x3c] */
/* @0x1acb30 mov r0, r4 */
/* @0x1acb34 blx r3 */
/* @0x1acb38 mov r1, #0 */
/* @0x1acb3c mov r0, r5 */
/* @0x1acb40 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1acb44 ldr r3, [r4] */
/* @0x1acb48 mov r2, r5 */
/* @0x1acb4c mov r1, #8 */
/* @0x1acb50 ldr r3, [r3, #0xc] */
/* @0x1acb54 str r0, [sp, #0x40] */
/* @0x1acb58 mov r0, r4 */
/* @0x1acb5c blx r3 */
/* @0x1acb60 mov r1, #0 */
/* @0x1acb64 mov r0, r5 */
/* @0x1acb68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1acb6c ldr r3, [r4] */
/* @0x1acb70 mov r2, r5 */
/* @0x1acb74 mov r1, #6 */
/* @0x1acb78 ldr r3, [r3, #0xc] */
/* @0x1acb7c str r0, [sp, #0x44] */
/* @0x1acb80 mov r0, r4 */
/* @0x1acb84 blx r3 */
/* @0x1acb88 mov r1, #0 */
/* @0x1acb8c mov r0, r5 */
/* @0x1acb90 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1acb94 ldr r3, [r4] */
/* @0x1acb98 mov r2, r5 */
/* @0x1acb9c mov r1, #8 */
/* @0x1acba0 ldr r3, [r3, #0xc] */
/* @0x1acba4 str r0, [sp, #0x48] */
/* @0x1acba8 mov r0, r4 */
/* @0x1acbac blx r3 */
/* @0x1acbb0 mov r1, #0 */
/* @0x1acbb4 mov r0, r5 */
/* @0x1acbb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1acbbc ldr r3, [r4] */
/* @0x1acbc0 mov r2, r5 */
/* @0x1acbc4 mov r1, #8 */
/* @0x1acbc8 ldr r3, [r3, #0xc] */
/* @0x1acbcc str r0, [sp, #0x4c] */
/* @0x1acbd0 mov r0, r4 */
/* @0x1acbd4 blx r3 */
/* @0x1acbd8 mov r1, #0 */
/* @0x1acbdc mov r0, r5 */
/* @0x1acbe0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1acbe4 ldr r3, [r4] */
/* @0x1acbe8 mov r2, r5 */
/* @0x1acbec mov r1, #6 */
/* @0x1acbf0 ldr r3, [r3, #0xc] */
/* @0x1acbf4 str r0, [sp, #0x50] */
/* @0x1acbf8 mov r0, r4 */
/* @0x1acbfc blx r3 */
/* @0x1acc00 mov r1, #0 */
/* @0x1acc04 mov r0, r5 */
/* @0x1acc08 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1acc0c ldr r3, [r4] */
/* @0x1acc10 mov r2, r5 */
/* @0x1acc14 mov r1, #8 */
/* @0x1acc18 ldr r3, [r3, #0xc] */
/* @0x1acc1c str r0, [sp, #0x54] */
/* @0x1acc20 mov r0, r4 */
/* @0x1acc24 blx r3 */
/* @0x1acc28 mov r1, #0 */
/* @0x1acc2c mov r0, r5 */
/* @0x1acc30 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1acc34 ldr r3, [r4] */
/* @0x1acc38 mov r2, r5 */
/* @0x1acc3c mov r1, #6 */
/* @0x1acc40 ldr r3, [r3, #0xc] */
/* @0x1acc44 str r0, [sp, #0x58] */
/* @0x1acc48 mov r0, r4 */
/* @0x1acc4c blx r3 */
/* @0x1acc50 mov r1, #0 */
/* @0x1acc54 mov r0, r5 */
/* @0x1acc58 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1acc5c mov r1, r9 */
/* @0x1acc60 ldr r11, [sp, #0x48] */
/* @0x1acc64 strb r0, [sp, #0x5c] */
/* @0x1acc68 mov r0, r6 */
/* @0x1acc6c bl 0x1ac240 <_ZN5CRoom7AddTileEP5RTile> */
/* @0x1acc70 ldr r2, [r6, #0xc0] */
/* @0x1acc74 ldr r1, [r10] */
/* @0x1acc78 cmp r7, r8 */
/* @0x1acc7c sub r1, r1, #1 */
/* @0x1acc80 str r1, [r10] */
/* @0x1acc84 rsb r0, r0, r0, lsl #3 */
/* @0x1acc88 add r2, r2, r0, lsl #3 */
/* @0x1acc8c str r11, [r2, #0x20] */
/* @0x1acc90 bne 0x1aca2c <_ZN5CRoom11DeSerialiseEP7IBufferb+0x6f0> */
/* @0x1acc94 ldr r11, [sp, #0x14] */
/* @0x1acc98 ldr r3, [r4] */
/* @0x1acc9c mov r1, #6 */
/* @0x1acca0 mov r2, r5 */
/* @0x1acca4 mov r0, r4 */
/* @0x1acca8 ldr r3, [r3, #0xc] */
/* @0x1accac blx r3 */
/* @0x1accb0 mov r0, r5 */
/* @0x1accb4 mov r1, #0 */
/* @0x1accb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1accbc subs r8, r0, #0 */
/* @0x1accc0 movgt r7, #0 */
/* @0x1accc4 ble 0x1acce0 <_ZN5CRoom11DeSerialiseEP7IBufferb+0x9a4> */
/* @0x1accc8 add r7, r7, #1 */
/* @0x1acccc mov r0, r6 */
/* @0x1accd0 mov r1, r4 */
/* @0x1accd4 bl 0x1c74d0 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer> */
/* @0x1accd8 cmp r7, r8 */
/* @0x1accdc bne 0x1accc8 <_ZN5CRoom11DeSerialiseEP7IBufferb+0x98c> */
/* @0x1acce0 ldr r3, [r4] */
/* @0x1acce4 mov r1, #6 */
/* @0x1acce8 mov r2, r5 */
/* @0x1accec mov r0, r4 */
/* @0x1accf0 ldr r3, [r3, #0xc] */
/* @0x1accf4 blx r3 */
/* @0x1accf8 mov r0, r5 */
/* @0x1accfc mov r1, #0 */
/* @0x1acd00 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1acd04 subs r9, r0, #0 */
/* @0x1acd08 ble 0x1acdc0 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xa84> */
/* @0x1acd0c ldr r12, [pc, #0x340] */
/* @0x1acd10 mov r8, #0 */
/* @0x1acd14 mov r10, r8 */
/* @0x1acd18 str r5, [sp, #0x24] */
/* @0x1acd1c add r12, pc, r12 */
/* @0x1acd20 str r12, [sp, #0x20] */
/* @0x1acd24 mov r0, #432 */
/* @0x1acd28 bl 0x27c524 <_Znwj> */
/* @0x1acd2c mov r1, #0 */
/* @0x1acd30 mov r3, #0 */
/* @0x1acd34 mov r2, r1 */
/* @0x1acd38 str r10, [sp] */
/* @0x1acd3c str r10, [sp, #0x4] */
/* @0x1acd40 mov r5, r0 */
/* @0x1acd44 bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1acd48 mov r2, r11 */
/* @0x1acd4c mov r0, r5 */
/* @0x1acd50 mov r1, r4 */
/* @0x1acd54 bl 0x19766c <_ZN9CInstance11DeSerialiseEP7IBufferb> */
/* @0x1acd58 ldr r3, [r6, #0x84] */
/* @0x1acd5c ldr r2, [r6, #0x88] */
/* @0x1acd60 cmp r3, #0 */
/* @0x1acd64 vldrne s14, [r5, #384] */
/* @0x1acd68 add r2, r2, #1 */
/* @0x1acd6c str r2, [r6, #0x88] */
/* @0x1acd70 beq 0x1ad02c <_ZN5CRoom11DeSerialiseEP7IBufferb+0xcf0> */
/* @0x1acd74 vldr s15, [r3, #388] */
/* @0x1acd78 vcmpe.f32 s14, s15 */
/* @0x1acd7c vmrs APSR_nzcv, fpscr */
/* @0x1acd80 bge 0x1acf50 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xc14> */
/* @0x1acd84 ldr r3, [r3, #0x17c] */
/* @0x1acd88 cmp r3, #0 */
/* @0x1acd8c bne 0x1acd74 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xa38> */
/* @0x1acd90 ldr r2, [r6, #0x80] */
/* @0x1acd94 vstr s14, [r5, #388] */
/* @0x1acd98 str r5, [r2, #0x17c] */
/* @0x1acd9c str r2, [r5, #0x178] */
/* @0x1acda0 str r5, [r6, #0x80] */
/* @0x1acda4 str r3, [r5, #0x17c] */
/* @0x1acda8 cmp r11, #0 */
/* @0x1acdac bne 0x1acf88 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xc4c> */
/* @0x1acdb0 add r8, r8, #1 */
/* @0x1acdb4 cmp r8, r9 */
/* @0x1acdb8 bne 0x1acd24 <_ZN5CRoom11DeSerialiseEP7IBufferb+0x9e8> */
/* @0x1acdbc ldr r5, [sp, #0x24] */
/* @0x1acdc0 ldr r3, [r4] */
/* @0x1acdc4 mov r1, #6 */
/* @0x1acdc8 mov r2, r5 */
/* @0x1acdcc mov r0, r4 */
/* @0x1acdd0 ldr r3, [r3, #0xc] */
/* @0x1acdd4 blx r3 */
/* @0x1acdd8 mov r0, r5 */
/* @0x1acddc mov r1, #0 */
/* @0x1acde0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1acde4 subs r10, r0, #0 */
/* @0x1acde8 ble 0x1acf38 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xbfc> */
/* @0x1acdec ldr r12, [pc, #0x264] */
/* @0x1acdf0 mov r8, #0 */
/* @0x1acdf4 mov r9, r10 */
/* @0x1acdf8 mov r7, r8 */
/* @0x1acdfc add r12, pc, r12 */
/* @0x1ace00 mov r10, r4 */
/* @0x1ace04 str r12, [sp, #0x20] */
/* @0x1ace08 b 0x1ace18 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xadc> */
/* @0x1ace0c add r8, r8, #1 */
/* @0x1ace10 cmp r8, r9 */
/* @0x1ace14 beq 0x1acf38 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xbfc> */
/* @0x1ace18 mov r0, #432 */
/* @0x1ace1c bl 0x27c524 <_Znwj> */
/* @0x1ace20 mov r1, #0 */
/* @0x1ace24 mov r3, #0 */
/* @0x1ace28 mov r2, r1 */
/* @0x1ace2c str r7, [sp] */
/* @0x1ace30 str r7, [sp, #0x4] */
/* @0x1ace34 mov r4, r0 */
/* @0x1ace38 bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1ace3c mov r2, r11 */
/* @0x1ace40 mov r0, r4 */
/* @0x1ace44 mov r1, r10 */
/* @0x1ace48 bl 0x19766c <_ZN9CInstance11DeSerialiseEP7IBufferb> */
/* @0x1ace4c ldr r3, [r6, #0x90] */
/* @0x1ace50 ldr r2, [r6, #0x94] */
/* @0x1ace54 cmp r3, #0 */
/* @0x1ace58 streq r4, [r6, #0x90] */
/* @0x1ace5c add r2, r2, #1 */
/* @0x1ace60 str r2, [r6, #0x94] */
/* @0x1ace64 strne r4, [r3, #0x178] */
/* @0x1ace68 ldrne r3, [r6, #0x90] */
/* @0x1ace6c streq r4, [r6, #0x8c] */
/* @0x1ace70 streq r3, [r4, #0x17c] */
/* @0x1ace74 strne r3, [r4, #0x17c] */
/* @0x1ace78 streq r3, [r4, #0x178] */
/* @0x1ace7c strne r4, [r6, #0x90] */
/* @0x1ace80 strne r7, [r4, #0x178] */
/* @0x1ace84 cmp r11, #0 */
/* @0x1ace88 beq 0x1ace0c <_ZN5CRoom11DeSerialiseEP7IBufferb+0xad0> */
/* @0x1ace8c ldr r12, [r4, #0x78] */
/* @0x1ace90 movw r2, #0x132 */
/* @0x1ace94 ldr lr, [pc, #0x1c0] */
/* @0x1ace98 mov r3, #1 */
/* @0x1ace9c ldr r1, [sp, #0x20] */
/* @0x1acea0 mov r0, #16 */
/* @0x1acea4 str r12, [sp, #0x18] */
/* @0x1acea8 add r8, r8, #1 */
/* @0x1aceac ldr r12, [sp, #0x1c] */
/* @0x1aceb0 ldr r5, [r12, lr] */
/* @0x1aceb4 ldr r12, [r5] */
/* @0x1aceb8 ldr lr, [r5, #0x4] */
/* @0x1acebc str r12, [sp, #0x24] */
/* @0x1acec0 ldr r12, [sp, #0x18] */
/* @0x1acec4 and r12, r12, lr */
/* @0x1acec8 str r12, [sp, #0x14] */
/* @0x1acecc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1aced0 ldr r12, [sp, #0x14] */
/* @0x1aced4 ldr lr, [sp, #0x24] */
/* @0x1aced8 mov r1, r4 */
/* @0x1acedc add r3, lr, r12, lsl #3 */
/* @0x1acee0 ldr r2, [lr, r12, lsl #3] */
/* @0x1acee4 ldr r12, [sp, #0x18] */
/* @0x1acee8 cmp r2, #0 */
/* @0x1aceec ldrne r2, [r3, #0x4] */
/* @0x1acef0 str r12, [r0, #0x8] */
/* @0x1acef4 ldreq r12, [sp, #0x14] */
/* @0x1acef8 str r4, [r0, #0xc] */
/* @0x1acefc strne r2, [r0] */
/* @0x1acf00 streq r0, [r3, #0x4] */
/* @0x1acf04 strne r0, [r2, #0x4] */
/* @0x1acf08 strne r0, [r3, #0x4] */
/* @0x1acf0c ldr r3, [r5, #0x8] */
/* @0x1acf10 streq r0, [lr, r12, lsl #3] */
/* @0x1acf14 strne r7, [r0, #0x4] */
/* @0x1acf18 add r3, r3, #1 */
/* @0x1acf1c streq r2, [r0, #0x4] */
/* @0x1acf20 streq r2, [r0] */
/* @0x1acf24 mov r0, r6 */
/* @0x1acf28 str r3, [r5, #0x8] */
/* @0x1acf2c bl 0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance> */
/* @0x1acf30 cmp r8, r9 */
/* @0x1acf34 bne 0x1ace18 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xadc> */
/* @0x1acf38 add sp, sp, #100 */
/* @0x1acf3c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1acf40 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1acf44 mov r3, #0 */
/* @0x1acf48 str r3, [r6, #0xc0] */
/* @0x1acf4c b 0x1aca08 <_ZN5CRoom11DeSerialiseEP7IBufferb+0x6cc> */
/* @0x1acf50 ldr r2, [r3, #0x178] */
/* @0x1acf54 cmp r2, #0 */
/* @0x1acf58 streq r3, [r5, #0x17c] */
/* @0x1acf5c strne r2, [r5, #0x178] */
/* @0x1acf60 ldrne r2, [r3, #0x178] */
/* @0x1acf64 streq r5, [r3, #0x178] */
/* @0x1acf68 strne r3, [r5, #0x17c] */
/* @0x1acf6c streq r5, [r6, #0x84] */
/* @0x1acf70 strne r5, [r2, #0x17c] */
/* @0x1acf74 streq r2, [r5, #0x178] */
/* @0x1acf78 strne r5, [r3, #0x178] */
/* @0x1acf7c cmp r11, #0 */
/* @0x1acf80 vstr s14, [r5, #388] */
/* @0x1acf84 beq 0x1acdb0 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xa74> */
/* @0x1acf88 ldr r12, [r5, #0x78] */
/* @0x1acf8c movw r2, #0x132 */
/* @0x1acf90 ldr lr, [pc, #0xc4] */
/* @0x1acf94 mov r3, #1 */
/* @0x1acf98 ldr r1, [sp, #0x20] */
/* @0x1acf9c mov r0, #16 */
/* @0x1acfa0 str r12, [sp, #0x18] */
/* @0x1acfa4 ldr r12, [sp, #0x1c] */
/* @0x1acfa8 ldr r7, [r12, lr] */
/* @0x1acfac ldr r12, [r7] */
/* @0x1acfb0 ldr lr, [r7, #0x4] */
/* @0x1acfb4 str r12, [sp, #0xc] */
/* @0x1acfb8 ldr r12, [sp, #0x18] */
/* @0x1acfbc and r12, r12, lr */
/* @0x1acfc0 str r12, [sp, #0x14] */
/* @0x1acfc4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1acfc8 ldr r12, [sp, #0x14] */
/* @0x1acfcc ldr lr, [sp, #0xc] */
/* @0x1acfd0 mov r1, r5 */
/* @0x1acfd4 add r3, lr, r12, lsl #3 */
/* @0x1acfd8 ldr r2, [lr, r12, lsl #3] */
/* @0x1acfdc ldr r12, [sp, #0x18] */
/* @0x1acfe0 cmp r2, #0 */
/* @0x1acfe4 ldrne r2, [r3, #0x4] */
/* @0x1acfe8 str r12, [r0, #0x8] */
/* @0x1acfec ldreq r12, [sp, #0x14] */
/* @0x1acff0 str r5, [r0, #0xc] */
/* @0x1acff4 strne r2, [r0] */
/* @0x1acff8 streq r0, [r3, #0x4] */
/* @0x1acffc strne r0, [r2, #0x4] */
/* @0x1ad000 strne r0, [r3, #0x4] */
/* @0x1ad004 ldr r3, [r7, #0x8] */
/* @0x1ad008 streq r0, [lr, r12, lsl #3] */
/* @0x1ad00c strne r10, [r0, #0x4] */
/* @0x1ad010 add r3, r3, #1 */
/* @0x1ad014 streq r2, [r0, #0x4] */
/* @0x1ad018 streq r2, [r0] */
/* @0x1ad01c mov r0, r6 */
/* @0x1ad020 str r3, [r7, #0x8] */
/* @0x1ad024 bl 0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance> */
/* @0x1ad028 b 0x1acdb0 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xa74> */
/* @0x1ad02c ldr r2, [r5, #0x180] */
/* @0x1ad030 str r5, [r6, #0x84] */
/* @0x1ad034 str r5, [r6, #0x80] */
/* @0x1ad038 str r2, [r5, #0x184] */
/* @0x1ad03c str r3, [r5, #0x17c] */
/* @0x1ad040 str r3, [r5, #0x178] */
/* @0x1ad044 b 0x1acda8 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xa6c> */
/* @0x1ad048 eoreq r5, r4, r4, ror #17 */
/* @0x1ad04c andseq r0, r10, r8, lsr r8 */
/* @0x1ad050 .word 0xffffebc0 */
/* @0x1ad054 mulseq r9, r0, pc */
/* @0x1ad058 ldrheq pc, [r9], -r0 */
/* @0x1ad05c .word 0xffffbff4 */

/* ── FUNC 0x1ad060 · CRoom::ClearTiles() · size=68 · insn=17 */
/* @0x1ad060 push {r3, r4, r5, lr} */
/* @0x1ad064 mov r4, r0 */
/* @0x1ad068 ldr r5, [r0, #0xc0] */
/* @0x1ad06c subs r0, r5, #0 */
/* @0x1ad070 beq 0x1ad098 <_ZN5CRoom10ClearTilesEv+0x38> */
/* @0x1ad074 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ad078 mov r3, #0 */
/* @0x1ad07c str r3, [r4, #0xc0] */
/* @0x1ad080 mov r3, #0 */
/* @0x1ad084 mvn r2, #0 */
/* @0x1ad088 str r3, [r4, #0xbc] */
/* @0x1ad08c str r3, [r4, #0xb8] */
/* @0x1ad090 str r2, [r4] */
/* @0x1ad094 pop {r3, r4, r5, pc} */
/* @0x1ad098 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ad09c str r5, [r4, #0xc0] */
/* @0x1ad0a0 b 0x1ad080 <_ZN5CRoom10ClearTilesEv+0x20> */

/* ── FUNC 0x1ad0a4 · CRoom::Clear() · size=552 · insn=138 */
/* @0x1ad0a4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ad0a8 vpush {d8} */
/* @0x1ad0ac mov r6, r0 */
/* @0x1ad0b0 mov r3, #0 */
/* @0x1ad0b4 mov r8, #1 */
/* @0x1ad0b8 sub sp, sp, #12 */
/* @0x1ad0bc mov r2, #640 */
/* @0x1ad0c0 mov r12, #1065353216 */
/* @0x1ad0c4 str r2, [r6, #0x10] */
/* @0x1ad0c8 mov r4, r3 */
/* @0x1ad0cc mov r2, #30 */
/* @0x1ad0d0 mov lr, r8 */
/* @0x1ad0d4 str r2, [r6, #0xc] */
/* @0x1ad0d8 mov r1, #8 */
/* @0x1ad0dc mvn r7, #0 */
/* @0x1ad0e0 mvn r5, #-16777216 */
/* @0x1ad0e4 mov r2, #0 */
/* @0x1ad0e8 mov r9, #480 */
/* @0x1ad0ec str r3, [r6, #0xc4] */
/* @0x1ad0f0 str r9, [r6, #0x14] */
/* @0x1ad0f4 movw r9, #0xc0c0 */
/* @0x1ad0f8 str r3, [r6, #0xc8] */
/* @0x1ad0fc movt r9, #0xc0 */
/* @0x1ad100 str r3, [r6, #0xac] */
/* @0x1ad104 str r9, [r6, #0x1c] */
/* @0x1ad108 str r3, [r6, #0x8] */
/* @0x1ad10c strb r3, [r6, #0x18] */
/* @0x1ad110 str r3, [r6, #0x68] */
/* @0x1ad114 strb r3, [r6, #0x70] */
/* @0x1ad118 strb r8, [r6, #0x20] */
/* @0x1ad11c ldr r3, [r0, #0x24] */
/* @0x1ad120 subs r1, r1, #1 */
/* @0x1ad124 add r0, r0, #4 */
/* @0x1ad128 str r2, [r3, #0x8] */
/* @0x1ad12c str r2, [r3, #0xc] */
/* @0x1ad130 str r12, [r3, #0x1c] */
/* @0x1ad134 str r12, [r3, #0x20] */
/* @0x1ad138 strb r4, [r3] */
/* @0x1ad13c str r2, [r3, #0x14] */
/* @0x1ad140 strb r4, [r3, #0x1] */
/* @0x1ad144 str r2, [r3, #0x18] */
/* @0x1ad148 str r7, [r3, #0x4] */
/* @0x1ad14c str r12, [r3, #0x28] */
/* @0x1ad150 strb lr, [r3, #0x10] */
/* @0x1ad154 strb lr, [r3, #0x11] */
/* @0x1ad158 str r5, [r3, #0x24] */
/* @0x1ad15c bne 0x1ad11c <_ZN5CRoom5ClearEv+0x78> */
/* @0x1ad160 ldr r10, [pc, #0x15c] */
/* @0x1ad164 mov r7, r1 */
/* @0x1ad168 mov r8, r1 */
/* @0x1ad16c mov r4, r6 */
/* @0x1ad170 ldr r10, [pc, r10] */
/* @0x1ad174 mov r2, #640 */
/* @0x1ad178 mov r11, #480 */
/* @0x1ad17c strb r1, [r6, #0x44] */
/* @0x1ad180 strb r1, [r6, #0x45] */
/* @0x1ad184 mov r9, #0 */
/* @0x1ad188 strb r1, [r6, #0x46] */
/* @0x1ad18c vldr s17, [pc, #296] */
/* @0x1ad190 vldr s16, [pc, #296] */
/* @0x1ad194 b 0x1ad1a4 <_ZN5CRoom5ClearEv+0x100> */
/* @0x1ad198 cmp r7, #8 */
/* @0x1ad19c add r4, r4, #4 */
/* @0x1ad1a0 beq 0x1ad228 <_ZN5CRoom5ClearEv+0x184> */
/* @0x1ad1a4 ldrb r0, [r10] */
/* @0x1ad1a8 mvn r5, #0 */
/* @0x1ad1ac ldr r3, [r4, #0x48] */
/* @0x1ad1b0 mov r1, #32 */
/* @0x1ad1b4 cmp r0, #0 */
/* @0x1ad1b8 add r7, r7, #1 */
/* @0x1ad1bc vstr s17, [r3, #12] */
/* @0x1ad1c0 vstr s16, [r3, #16] */
/* @0x1ad1c4 strb r8, [r3] */
/* @0x1ad1c8 str r9, [r3, #0x4] */
/* @0x1ad1cc str r9, [r3, #0x8] */
/* @0x1ad1d0 str r8, [r3, #0x14] */
/* @0x1ad1d4 str r8, [r3, #0x18] */
/* @0x1ad1d8 str r9, [r3, #0x24] */
/* @0x1ad1dc str r2, [r3, #0x1c] */
/* @0x1ad1e0 str r11, [r3, #0x20] */
/* @0x1ad1e4 str r1, [r3, #0x28] */
/* @0x1ad1e8 str r1, [r3, #0x2c] */
/* @0x1ad1ec str r5, [r3, #0x30] */
/* @0x1ad1f0 str r5, [r3, #0x34] */
/* @0x1ad1f4 str r5, [r3, #0x38] */
/* @0x1ad1f8 beq 0x1ad198 <_ZN5CRoom5ClearEv+0xf4> */
/* @0x1ad1fc ldr r0, [pc, #0xc4] */
/* @0x1ad200 add r4, r4, #4 */
/* @0x1ad204 ldr r1, [r3, #0x40] */
/* @0x1ad208 ldr r0, [pc, r0] */
/* @0x1ad20c str r2, [sp, #0x4] */
/* @0x1ad210 bl 0x16f2cc <_ZN14CCameraManager13DestroyCameraEi> */
/* @0x1ad214 ldr r3, [r4, #0x44] */
/* @0x1ad218 cmp r7, #8 */
/* @0x1ad21c ldr r2, [sp, #0x4] */
/* @0x1ad220 str r5, [r3, #0x40] */
/* @0x1ad224 bne 0x1ad1a4 <_ZN5CRoom5ClearEv+0x100> */
/* @0x1ad228 mov r0, r6 */
/* @0x1ad22c mov r4, #0 */
/* @0x1ad230 bl 0x1ab798 <_ZN5CRoom14ClearInstancesEv> */
/* @0x1ad234 mov r0, r6 */
/* @0x1ad238 bl 0x1ab9c8 <_ZN5CRoom22ClearDeactiveInstancesEv> */
/* @0x1ad23c ldr r0, [r6, #0xa4] */
/* @0x1ad240 str r4, [r6, #0xa8] */
/* @0x1ad244 cmp r0, r4 */
/* @0x1ad248 beq 0x1ad254 <_ZN5CRoom5ClearEv+0x1b0> */
/* @0x1ad24c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ad250 str r4, [r6, #0xa4] */
/* @0x1ad254 mov r0, r6 */
/* @0x1ad258 bl 0x1ad060 <_ZN5CRoom10ClearTilesEv> */
/* @0x1ad25c mov r0, r6 */
/* @0x1ad260 bl 0x1b93c8 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom> */
/* @0x1ad264 ldr r0, [r6, #0xf4] */
/* @0x1ad268 cmp r0, #0 */
/* @0x1ad26c beq 0x1ad274 <_ZN5CRoom5ClearEv+0x1d0> */
/* @0x1ad270 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ad274 ldr r0, [r6, #0x108] */
/* @0x1ad278 mov r3, #0 */
/* @0x1ad27c str r3, [r6, #0xf4] */
/* @0x1ad280 cmp r0, r3 */
/* @0x1ad284 beq 0x1ad28c <_ZN5CRoom5ClearEv+0x1e8> */
/* @0x1ad288 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ad28c ldr r0, [r6, #0x120] */
/* @0x1ad290 mov r3, #0 */
/* @0x1ad294 str r3, [r6, #0x108] */
/* @0x1ad298 cmp r0, r3 */
/* @0x1ad29c str r3, [r6, #0x10c] */
/* @0x1ad2a0 beq 0x1ad2a8 <_ZN5CRoom5ClearEv+0x204> */
/* @0x1ad2a4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ad2a8 mov r3, #0 */
/* @0x1ad2ac str r3, [r6, #0x120] */
/* @0x1ad2b0 add sp, sp, #12 */
/* @0x1ad2b4 vpop {d8} */
/* @0x1ad2b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ad2bc strtmi r0, [r0], #-0 */
/* @0x1ad2c0 mvnsmi r0, #0 */
/* @0x1ad2c4 .word 0x002407b4 */
/* @0x1ad2c8 eoreq r0, r4, r12, ror #20 */

/* ── FUNC 0x1ad2cc · CRoom::CRoom() · size=1088 · insn=272 */
/* @0x1ad2cc push {r3, r4, r5, r6, r7, lr} */
/* @0x1ad2d0 mov r1, #1 */
/* @0x1ad2d4 mov r4, r0 */
/* @0x1ad2d8 mov r5, #0 */
/* @0x1ad2dc mov r2, #128 */
/* @0x1ad2e0 str r5, [r0, #0x84] */
/* @0x1ad2e4 str r2, [r0, #0xe4] */
/* @0x1ad2e8 mov r3, #127 */
/* @0x1ad2ec str r3, [r0, #0xec] */
/* @0x1ad2f0 mov r3, r1 */
/* @0x1ad2f4 str r1, [r4, #0x98] */
/* @0x1ad2f8 mov r2, #70 */
/* @0x1ad2fc str r1, [r4, #0xe0] */
/* @0x1ad300 mov r0, #1536 */
/* @0x1ad304 ldr r1, [pc, #0x3e8] */
/* @0x1ad308 str r5, [r4, #0x80] */
/* @0x1ad30c add r1, pc, r1 */
/* @0x1ad310 str r5, [r4, #0x88] */
/* @0x1ad314 str r5, [r4, #0x90] */
/* @0x1ad318 str r5, [r4, #0x8c] */
/* @0x1ad31c str r5, [r4, #0x94] */
/* @0x1ad320 str r5, [r4, #0xbc] */
/* @0x1ad324 str r5, [r4, #0xc0] */
/* @0x1ad328 str r5, [r4, #0xd8] */
/* @0x1ad32c str r5, [r4, #0xd4] */
/* @0x1ad330 str r5, [r4, #0xdc] */
/* @0x1ad334 str r5, [r4, #0xf4] */
/* @0x1ad338 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ad33c mov r2, #1536 */
/* @0x1ad340 mov r1, r5 */
/* @0x1ad344 str r0, [r4, #0xf4] */
/* @0x1ad348 bl 0xb65b0 <memset@plt> */
/* @0x1ad34c ldr r2, [r4, #0xe4] */
/* @0x1ad350 vldr s15, [pc, #920] */
/* @0x1ad354 str r5, [r4, #0xe8] */
/* @0x1ad358 cmp r2, r5 */
/* @0x1ad35c vmov s13, r2 */
/* @0x1ad360 vcvt.f32.s32 s14, s13 */
/* @0x1ad364 vmul.f32 s15, s14, s15 */
/* @0x1ad368 vcvt.s32.f32 s15, s15 */
/* @0x1ad36c vstr s15, [r4, #240] */
/* @0x1ad370 ble 0x1ad390 <_ZN5CRoomC2Ev+0xc4> */
/* @0x1ad374 add r2, r2, r2, lsl #1 */
/* @0x1ad378 ldr r3, [r4, #0xf4] */
/* @0x1ad37c add r2, r3, r2, lsl #2 */
/* @0x1ad380 str r5, [r3, #0x8] */
/* @0x1ad384 add r3, r3, #12 */
/* @0x1ad388 cmp r3, r2 */
/* @0x1ad38c bne 0x1ad380 <_ZN5CRoomC2Ev+0xb4> */
/* @0x1ad390 ldr r1, [pc, #0x360] */
/* @0x1ad394 mov r5, #0 */
/* @0x1ad398 mov r2, #128 */
/* @0x1ad39c mov r3, #127 */
/* @0x1ad3a0 str r2, [r4, #0xf8] */
/* @0x1ad3a4 add r1, pc, r1 */
/* @0x1ad3a8 str r3, [r4, #0x100] */
/* @0x1ad3ac mov r2, #70 */
/* @0x1ad3b0 mov r3, #1 */
/* @0x1ad3b4 str r5, [r4, #0x108] */
/* @0x1ad3b8 mov r0, #1536 */
/* @0x1ad3bc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ad3c0 mov r2, #1536 */
/* @0x1ad3c4 mov r1, r5 */
/* @0x1ad3c8 str r0, [r4, #0x108] */
/* @0x1ad3cc bl 0xb65b0 <memset@plt> */
/* @0x1ad3d0 ldr r2, [r4, #0xf8] */
/* @0x1ad3d4 vldr s15, [pc, #788] */
/* @0x1ad3d8 str r5, [r4, #0xfc] */
/* @0x1ad3dc cmp r2, r5 */
/* @0x1ad3e0 vmov s13, r2 */
/* @0x1ad3e4 vcvt.f32.s32 s14, s13 */
/* @0x1ad3e8 vmul.f32 s15, s14, s15 */
/* @0x1ad3ec vcvt.s32.f32 s15, s15 */
/* @0x1ad3f0 vstr s15, [r4, #260] */
/* @0x1ad3f4 ble 0x1ad418 <_ZN5CRoomC2Ev+0x14c> */
/* @0x1ad3f8 add r2, r2, r2, lsl #1 */
/* @0x1ad3fc ldr r3, [r4, #0x108] */
/* @0x1ad400 mov r1, r5 */
/* @0x1ad404 add r2, r3, r2, lsl #2 */
/* @0x1ad408 str r1, [r3, #0x8] */
/* @0x1ad40c add r3, r3, #12 */
/* @0x1ad410 cmp r3, r2 */
/* @0x1ad414 bne 0x1ad408 <_ZN5CRoomC2Ev+0x13c> */
/* @0x1ad418 ldr r1, [pc, #0x2dc] */
/* @0x1ad41c mov r5, #0 */
/* @0x1ad420 mov r2, #128 */
/* @0x1ad424 mov r3, #127 */
/* @0x1ad428 str r2, [r4, #0x110] */
/* @0x1ad42c add r1, pc, r1 */
/* @0x1ad430 str r3, [r4, #0x118] */
/* @0x1ad434 mov r2, #70 */
/* @0x1ad438 mov r3, #1 */
/* @0x1ad43c str r5, [r4, #0x120] */
/* @0x1ad440 mov r0, #1536 */
/* @0x1ad444 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ad448 mov r2, #1536 */
/* @0x1ad44c mov r1, r5 */
/* @0x1ad450 str r0, [r4, #0x120] */
/* @0x1ad454 bl 0xb65b0 <memset@plt> */
/* @0x1ad458 ldr r2, [r4, #0x110] */
/* @0x1ad45c vldr s15, [pc, #652] */
/* @0x1ad460 str r5, [r4, #0x114] */
/* @0x1ad464 cmp r2, r5 */
/* @0x1ad468 vmov s13, r2 */
/* @0x1ad46c vcvt.f32.s32 s14, s13 */
/* @0x1ad470 vmul.f32 s15, s14, s15 */
/* @0x1ad474 vcvt.s32.f32 s15, s15 */
/* @0x1ad478 vstr s15, [r4, #284] */
/* @0x1ad47c ble 0x1ad4a0 <_ZN5CRoomC2Ev+0x1d4> */
/* @0x1ad480 add r2, r2, r2, lsl #1 */
/* @0x1ad484 ldr r3, [r4, #0x120] */
/* @0x1ad488 mov r1, r5 */
/* @0x1ad48c add r2, r3, r2, lsl #2 */
/* @0x1ad490 str r1, [r3, #0x8] */
/* @0x1ad494 add r3, r3, #12 */
/* @0x1ad498 cmp r3, r2 */
/* @0x1ad49c bne 0x1ad490 <_ZN5CRoomC2Ev+0x1c4> */
/* @0x1ad4a0 mov r3, #0 */
/* @0x1ad4a4 mov r5, r4 */
/* @0x1ad4a8 mov r6, r3 */
/* @0x1ad4ac mov r2, #1 */
/* @0x1ad4b0 stm r4, {r3, r4} */
/* @0x1ad4b4 str r3, [r4, #0x8] */
/* @0x1ad4b8 str r3, [r4, #0xc] */
/* @0x1ad4bc str r3, [r4, #0x10] */
/* @0x1ad4c0 str r3, [r4, #0x14] */
/* @0x1ad4c4 strb r3, [r4, #0x18] */
/* @0x1ad4c8 str r3, [r4, #0x1c] */
/* @0x1ad4cc strb r3, [r4, #0x20] */
/* @0x1ad4d0 strb r3, [r4, #0x44] */
/* @0x1ad4d4 str r3, [r4, #0x68] */
/* @0x1ad4d8 str r3, [r4, #0x6c] */
/* @0x1ad4dc str r3, [r4, #0xa4] */
/* @0x1ad4e0 str r3, [r4, #0xa8] */
/* @0x1ad4e4 strb r3, [r4, #0xd0] */
/* @0x1ad4e8 str r3, [r4, #0xcc] */
/* @0x1ad4ec str r3, [r4, #0xb4] */
/* @0x1ad4f0 strb r2, [r4, #0x45] */
/* @0x1ad4f4 strb r2, [r4, #0x46] */
/* @0x1ad4f8 mov r0, #44 */
/* @0x1ad4fc add r6, r6, #1 */
/* @0x1ad500 bl 0x27c524 <_Znwj> */
/* @0x1ad504 cmp r6, #8 */
/* @0x1ad508 add r5, r5, #4 */
/* @0x1ad50c str r0, [r5, #0x20] */
/* @0x1ad510 bne 0x1ad4f8 <_ZN5CRoomC2Ev+0x22c> */
/* @0x1ad514 mov r6, r4 */
/* @0x1ad518 mov r5, #0 */
/* @0x1ad51c mvn r7, #0 */
/* @0x1ad520 mov r0, #68 */
/* @0x1ad524 add r5, r5, #1 */
/* @0x1ad528 bl 0x27c524 <_Znwj> */
/* @0x1ad52c cmp r5, #8 */
/* @0x1ad530 add r6, r6, #4 */
/* @0x1ad534 str r7, [r0, #0x3c] */
/* @0x1ad538 str r7, [r0, #0x40] */
/* @0x1ad53c str r0, [r6, #0x44] */
/* @0x1ad540 bne 0x1ad520 <_ZN5CRoomC2Ev+0x254> */
/* @0x1ad544 mov r5, #0 */
/* @0x1ad548 mov r0, r4 */
/* @0x1ad54c str r5, [r4, #0xbc] */
/* @0x1ad550 str r5, [r4, #0xc0] */
/* @0x1ad554 str r5, [r4, #0xb8] */
/* @0x1ad558 bl 0x1ad0a4 <_ZN5CRoom5ClearEv> */
/* @0x1ad55c ldr r0, [r4, #0xe4] */
/* @0x1ad560 ldr r1, [pc, #0x198] */
/* @0x1ad564 mov r2, #70 */
/* @0x1ad568 sub r12, r0, #1 */
/* @0x1ad56c mov r3, #1 */
/* @0x1ad570 add r0, r0, r0, lsl #1 */
/* @0x1ad574 add r1, pc, r1 */
/* @0x1ad578 str r12, [r4, #0xec] */
/* @0x1ad57c lsl r6, r0, #2 */
/* @0x1ad580 mov r0, r6 */
/* @0x1ad584 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ad588 mov r2, r6 */
/* @0x1ad58c mov r1, r5 */
/* @0x1ad590 str r0, [r4, #0xf4] */
/* @0x1ad594 bl 0xb65b0 <memset@plt> */
/* @0x1ad598 ldr r2, [r4, #0xe4] */
/* @0x1ad59c vldr s15, [pc, #332] */
/* @0x1ad5a0 str r5, [r4, #0xe8] */
/* @0x1ad5a4 cmp r2, r5 */
/* @0x1ad5a8 vmov s13, r2 */
/* @0x1ad5ac vcvt.f32.s32 s14, s13 */
/* @0x1ad5b0 vmul.f32 s15, s14, s15 */
/* @0x1ad5b4 vcvt.s32.f32 s15, s15 */
/* @0x1ad5b8 vstr s15, [r4, #240] */
/* @0x1ad5bc ble 0x1ad5e0 <_ZN5CRoomC2Ev+0x314> */
/* @0x1ad5c0 add r2, r2, r2, lsl #1 */
/* @0x1ad5c4 ldr r3, [r4, #0xf4] */
/* @0x1ad5c8 mov r1, r5 */
/* @0x1ad5cc add r2, r3, r2, lsl #2 */
/* @0x1ad5d0 str r1, [r3, #0x8] */
/* @0x1ad5d4 add r3, r3, #12 */
/* @0x1ad5d8 cmp r3, r2 */
/* @0x1ad5dc bne 0x1ad5d0 <_ZN5CRoomC2Ev+0x304> */
/* @0x1ad5e0 ldr r0, [r4, #0xf8] */
/* @0x1ad5e4 mov r2, #70 */
/* @0x1ad5e8 ldr r1, [pc, #0x114] */
/* @0x1ad5ec mov r3, #1 */
/* @0x1ad5f0 sub r12, r0, #1 */
/* @0x1ad5f4 str r12, [r4, #0x100] */
/* @0x1ad5f8 add r0, r0, r0, lsl #1 */
/* @0x1ad5fc add r1, pc, r1 */
/* @0x1ad600 lsl r5, r0, #2 */
/* @0x1ad604 mov r0, r5 */
/* @0x1ad608 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ad60c mov r2, r5 */
/* @0x1ad610 mov r1, #0 */
/* @0x1ad614 str r0, [r4, #0x108] */
/* @0x1ad618 bl 0xb65b0 <memset@plt> */
/* @0x1ad61c ldr r2, [r4, #0xf8] */
/* @0x1ad620 vldr s15, [pc, #200] */
/* @0x1ad624 mov r1, #0 */
/* @0x1ad628 cmp r2, r1 */
/* @0x1ad62c str r1, [r4, #0xfc] */
/* @0x1ad630 vmov s13, r2 */
/* @0x1ad634 vcvt.f32.s32 s14, s13 */
/* @0x1ad638 vmul.f32 s15, s14, s15 */
/* @0x1ad63c vcvt.s32.f32 s15, s15 */
/* @0x1ad640 vstr s15, [r4, #260] */
/* @0x1ad644 ble 0x1ad664 <_ZN5CRoomC2Ev+0x398> */
/* @0x1ad648 add r2, r2, r2, lsl #1 */
/* @0x1ad64c ldr r3, [r4, #0x108] */
/* @0x1ad650 add r2, r3, r2, lsl #2 */
/* @0x1ad654 str r1, [r3, #0x8] */
/* @0x1ad658 add r3, r3, #12 */
/* @0x1ad65c cmp r3, r2 */
/* @0x1ad660 bne 0x1ad654 <_ZN5CRoomC2Ev+0x388> */
/* @0x1ad664 ldr r0, [r4, #0x110] */
/* @0x1ad668 mov r2, #70 */
/* @0x1ad66c ldr r1, [pc, #0x94] */
/* @0x1ad670 mov r3, #1 */
/* @0x1ad674 sub r12, r0, #1 */
/* @0x1ad678 str r12, [r4, #0x118] */
/* @0x1ad67c add r0, r0, r0, lsl #1 */
/* @0x1ad680 add r1, pc, r1 */
/* @0x1ad684 lsl r5, r0, #2 */
/* @0x1ad688 mov r0, r5 */
/* @0x1ad68c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ad690 mov r2, r5 */
/* @0x1ad694 mov r1, #0 */
/* @0x1ad698 str r0, [r4, #0x120] */
/* @0x1ad69c bl 0xb65b0 <memset@plt> */
/* @0x1ad6a0 ldr r2, [r4, #0x110] */
/* @0x1ad6a4 vldr s15, [pc, #68] */
/* @0x1ad6a8 mov r1, #0 */
/* @0x1ad6ac cmp r2, r1 */
/* @0x1ad6b0 str r1, [r4, #0x114] */
/* @0x1ad6b4 vmov s13, r2 */
/* @0x1ad6b8 vcvt.f32.s32 s14, s13 */
/* @0x1ad6bc vmul.f32 s15, s14, s15 */
/* @0x1ad6c0 vcvt.s32.f32 s15, s15 */
/* @0x1ad6c4 vstr s15, [r4, #284] */
/* @0x1ad6c8 ble 0x1ad6e8 <_ZN5CRoomC2Ev+0x41c> */
/* @0x1ad6cc add r2, r2, r2, lsl #1 */
/* @0x1ad6d0 ldr r3, [r4, #0x120] */
/* @0x1ad6d4 add r2, r3, r2, lsl #2 */
/* @0x1ad6d8 str r1, [r3, #0x8] */
/* @0x1ad6dc add r3, r3, #12 */
/* @0x1ad6e0 cmp r3, r2 */
/* @0x1ad6e4 bne 0x1ad6d8 <_ZN5CRoomC2Ev+0x40c> */
/* @0x1ad6e8 mov r0, r4 */
/* @0x1ad6ec pop {r3, r4, r5, r6, r7, pc} */
/* @0x1ad6f0 svclo #0x19999a */
/* @0x1ad6f4 andseq r3, r8, r4, lsr #26 */
/* @0x1ad6f8 andseq r3, r8, r12, lsl #25 */
/* @0x1ad6fc andseq r3, r8, r4, lsl #24 */
/* @0x1ad700 ldrheq r3, [r8], -r12 */
/* @0x1ad704 andseq r3, r8, r4, lsr r10 */
/* @0x1ad708 ldrheq r3, [r8], -r0 */

/* ── FUNC 0x1ad2cc · CRoom::CRoom() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1ad70c · CRoom::Assign(CRoom*, bool) · size=3308 · insn=827 */
/* @0x1ad70c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ad710 vpush {d8} */
/* @0x1ad714 sub sp, sp, #52 */
/* @0x1ad718 mov r4, r0 */
/* @0x1ad71c ldr r7, [pc, #0xbc4] */
/* @0x1ad720 str r1, [sp, #0x10] */
/* @0x1ad724 str r2, [sp, #0x1c] */
/* @0x1ad728 bl 0x1ad0a4 <_ZN5CRoom5ClearEv> */
/* @0x1ad72c ldr r6, [sp, #0x10] */
/* @0x1ad730 add r7, pc, r7 */
/* @0x1ad734 str r7, [sp, #0x18] */
/* @0x1ad738 cmp r6, #0 */
/* @0x1ad73c beq 0x1ada5c <_ZN5CRoom6AssignEPS_b+0x350> */
/* @0x1ad740 ldr r0, [r6, #0x8] */
/* @0x1ad744 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1ad748 ldr r5, [r6, #0x10] */
/* @0x1ad74c ldr lr, [r6, #0x14] */
/* @0x1ad750 ldr r12, [r6, #0xc] */
/* @0x1ad754 ldrb r1, [r6, #0x18] */
/* @0x1ad758 ldr r2, [r6, #0x1c] */
/* @0x1ad75c ldrb r3, [r6, #0x20] */
/* @0x1ad760 str r5, [r4, #0x10] */
/* @0x1ad764 str lr, [r4, #0x14] */
/* @0x1ad768 str r12, [r4, #0xc] */
/* @0x1ad76c strb r1, [r4, #0x18] */
/* @0x1ad770 str r2, [r4, #0x1c] */
/* @0x1ad774 strb r3, [r4, #0x20] */
/* @0x1ad778 str r0, [r4, #0x8] */
/* @0x1ad77c ldr r0, [r6, #0x68] */
/* @0x1ad780 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1ad784 ldr r9, [sp, #0x10] */
/* @0x1ad788 mov r12, r4 */
/* @0x1ad78c mov r1, #8 */
/* @0x1ad790 ldr r6, [r9, #0x6c] */
/* @0x1ad794 mov lr, r9 */
/* @0x1ad798 ldrb r5, [r9, #0x70] */
/* @0x1ad79c ldr r2, [r9, #0x74] */
/* @0x1ad7a0 ldr r3, [r9, #0x78] */
/* @0x1ad7a4 str r6, [r4, #0x6c] */
/* @0x1ad7a8 ldr r6, [r9, #0x7c] */
/* @0x1ad7ac strb r5, [r4, #0x70] */
/* @0x1ad7b0 str r2, [r4, #0x74] */
/* @0x1ad7b4 str r6, [r4, #0x7c] */
/* @0x1ad7b8 str r3, [r4, #0x78] */
/* @0x1ad7bc str r0, [r4, #0x68] */
/* @0x1ad7c0 ldr r2, [lr, #0x24] */
/* @0x1ad7c4 subs r1, r1, #1 */
/* @0x1ad7c8 ldr r3, [r12, #0x24] */
/* @0x1ad7cc add lr, lr, #4 */
/* @0x1ad7d0 add r12, r12, #4 */
/* @0x1ad7d4 ldr r6, [r2, #0x8] */
/* @0x1ad7d8 ldr r5, [r2, #0xc] */
/* @0x1ad7dc ldrb r8, [r2, #0x1] */
/* @0x1ad7e0 ldr r0, [r2, #0x1c] */
/* @0x1ad7e4 ldrb r9, [r2] */
/* @0x1ad7e8 ldr r7, [r2, #0x4] */
/* @0x1ad7ec str r6, [r3, #0x8] */
/* @0x1ad7f0 ldrb r6, [r2, #0x10] */
/* @0x1ad7f4 str r5, [r3, #0xc] */
/* @0x1ad7f8 ldrb r5, [r2, #0x11] */
/* @0x1ad7fc str r0, [r3, #0x1c] */
/* @0x1ad800 ldr r0, [r2, #0x24] */
/* @0x1ad804 strb r8, [r3, #0x1] */
/* @0x1ad808 ldr r8, [r2, #0x20] */
/* @0x1ad80c strb r6, [r3, #0x10] */
/* @0x1ad810 ldr r6, [r2, #0x14] */
/* @0x1ad814 strb r5, [r3, #0x11] */
/* @0x1ad818 ldr r5, [r2, #0x18] */
/* @0x1ad81c ldr r2, [r2, #0x28] */
/* @0x1ad820 strb r9, [r3] */
/* @0x1ad824 str r7, [r3, #0x4] */
/* @0x1ad828 str r8, [r3, #0x20] */
/* @0x1ad82c str r6, [r3, #0x14] */
/* @0x1ad830 str r5, [r3, #0x18] */
/* @0x1ad834 str r0, [r3, #0x24] */
/* @0x1ad838 str r2, [r3, #0x28] */
/* @0x1ad83c bne 0x1ad7c0 <_ZN5CRoom6AssignEPS_b+0xb4> */
/* @0x1ad840 ldr r12, [sp, #0x10] */
/* @0x1ad844 mov r8, r1 */
/* @0x1ad848 ldr r3, [pc, #0xa9c] */
/* @0x1ad84c mov r5, r4 */
/* @0x1ad850 mvn r6, #0 */
/* @0x1ad854 ldrb r0, [r12, #0x44] */
/* @0x1ad858 mov r7, r12 */
/* @0x1ad85c ldrb r1, [r12, #0x45] */
/* @0x1ad860 ldrb r2, [r12, #0x46] */
/* @0x1ad864 ldr r12, [sp, #0x18] */
/* @0x1ad868 strb r0, [r4, #0x44] */
/* @0x1ad86c strb r1, [r4, #0x45] */
/* @0x1ad870 strb r2, [r4, #0x46] */
/* @0x1ad874 mov r10, r12 */
/* @0x1ad878 ldr r9, [r12, r3] */
/* @0x1ad87c b 0x1ad894 <_ZN5CRoom6AssignEPS_b+0x188> */
/* @0x1ad880 add r8, r8, #1 */
/* @0x1ad884 add r5, r5, #4 */
/* @0x1ad888 cmp r8, #8 */
/* @0x1ad88c add r7, r7, #4 */
/* @0x1ad890 beq 0x1ada68 <_ZN5CRoom6AssignEPS_b+0x35c> */
/* @0x1ad894 ldr r3, [r7, #0x48] */
/* @0x1ad898 vldr s15, [r3, #4] */
/* @0x1ad89c ldr r2, [r5, #0x48] */
/* @0x1ad8a0 ldr r12, [r3, #0x8] */
/* @0x1ad8a4 ldrb r0, [r3] */
/* @0x1ad8a8 ldr r11, [r3, #0xc] */
/* @0x1ad8ac ldr r1, [r3, #0x14] */
/* @0x1ad8b0 ldr lr, [r3, #0x18] */
/* @0x1ad8b4 strb r0, [r2] */
/* @0x1ad8b8 ldr r0, [r5, #0x48] */
/* @0x1ad8bc vstr s15, [r0, #4] */
/* @0x1ad8c0 ldr r0, [r3, #0x20] */
/* @0x1ad8c4 str r12, [r2, #0x8] */
/* @0x1ad8c8 ldr r12, [r3, #0x1c] */
/* @0x1ad8cc str r11, [r2, #0xc] */
/* @0x1ad8d0 ldr r11, [r3, #0x10] */
/* @0x1ad8d4 str r1, [r2, #0x14] */
/* @0x1ad8d8 ldr r1, [r3, #0x28] */
/* @0x1ad8dc str lr, [r2, #0x18] */
/* @0x1ad8e0 ldr lr, [r3, #0x2c] */
/* @0x1ad8e4 str r12, [r2, #0x1c] */
/* @0x1ad8e8 ldr r12, [r3, #0x30] */
/* @0x1ad8ec str r0, [r2, #0x20] */
/* @0x1ad8f0 ldr r0, [r3, #0x24] */
/* @0x1ad8f4 str r1, [r2, #0x28] */
/* @0x1ad8f8 ldr r1, [r3, #0x38] */
/* @0x1ad8fc str r0, [r2, #0x24] */
/* @0x1ad900 ldr r0, [r3, #0x34] */
/* @0x1ad904 str r11, [r2, #0x10] */
/* @0x1ad908 str lr, [r2, #0x2c] */
/* @0x1ad90c str r12, [r2, #0x30] */
/* @0x1ad910 str r0, [r2, #0x34] */
/* @0x1ad914 str r1, [r2, #0x38] */
/* @0x1ad918 ldrb r2, [r9] */
/* @0x1ad91c cmp r2, #0 */
/* @0x1ad920 beq 0x1ad880 <_ZN5CRoom6AssignEPS_b+0x174> */
/* @0x1ad924 ldr r2, [pc, #0x9c4] */
/* @0x1ad928 ldr r1, [r3, #0x40] */
/* @0x1ad92c ldr r0, [r10, r2] */
/* @0x1ad930 bl 0x170658 <_ZN14CCameraManager11CloneCameraEi> */
/* @0x1ad934 cmp r0, #0 */
/* @0x1ad938 beq 0x1ade3c <_ZN5CRoom6AssignEPS_b+0x730> */
/* @0x1ad93c ldr r11, [r5, #0x48] */
/* @0x1ad940 bl 0x16d12c <_ZN7CCamera5GetIDEv> */
/* @0x1ad944 str r0, [r11, #0x40] */
/* @0x1ad948 b 0x1ad880 <_ZN5CRoom6AssignEPS_b+0x174> */
/* @0x1ad94c ldr r6, [sp, #0x10] */
/* @0x1ad950 ldr r8, [r6, #0x8c] */
/* @0x1ad954 cmp r8, #0 */
/* @0x1ad958 beq 0x1ada5c <_ZN5CRoom6AssignEPS_b+0x350> */
/* @0x1ad95c ldr r3, [pc, #0x990] */
/* @0x1ad960 mov r7, #0 */
/* @0x1ad964 ldr r9, [sp, #0x18] */
/* @0x1ad968 ldr r6, [pc, #0x988] */
/* @0x1ad96c add r6, pc, r6 */
/* @0x1ad970 str r6, [sp, #0x10] */
/* @0x1ad974 ldr r6, [r9, r3] */
/* @0x1ad978 mov r0, #432 */
/* @0x1ad97c ldr r10, [r8, #0x178] */
/* @0x1ad980 bl 0x27c524 <_Znwj> */
/* @0x1ad984 mov r1, #0 */
/* @0x1ad988 mov r3, #0 */
/* @0x1ad98c mov r2, r1 */
/* @0x1ad990 str r7, [sp] */
/* @0x1ad994 str r7, [sp, #0x4] */
/* @0x1ad998 mov r5, r0 */
/* @0x1ad99c bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1ad9a0 mov r1, r8 */
/* @0x1ad9a4 mov r0, r5 */
/* @0x1ad9a8 mov r2, #0 */
/* @0x1ad9ac bl 0x1986ec <_ZN9CInstance6AssignEPS_b> */
/* @0x1ad9b0 ldr r3, [r4, #0x90] */
/* @0x1ad9b4 ldr r2, [r4, #0x94] */
/* @0x1ad9b8 mov r0, #16 */
/* @0x1ad9bc cmp r3, #0 */
/* @0x1ad9c0 ldr r1, [sp, #0x10] */
/* @0x1ad9c4 add r2, r2, #1 */
/* @0x1ad9c8 str r2, [r4, #0x94] */
/* @0x1ad9cc strne r5, [r3, #0x178] */
/* @0x1ad9d0 movw r2, #0x132 */
/* @0x1ad9d4 ldrne r3, [r4, #0x90] */
/* @0x1ad9d8 streq r5, [r4, #0x90] */
/* @0x1ad9dc streq r5, [r4, #0x8c] */
/* @0x1ad9e0 strne r3, [r5, #0x17c] */
/* @0x1ad9e4 streq r3, [r5, #0x17c] */
/* @0x1ad9e8 streq r3, [r5, #0x178] */
/* @0x1ad9ec mov r3, #1 */
/* @0x1ad9f0 strne r5, [r4, #0x90] */
/* @0x1ad9f4 strne r7, [r5, #0x178] */
/* @0x1ad9f8 ldr r8, [r6] */
/* @0x1ad9fc ldr r11, [r5, #0x78] */
/* @0x1ada00 ldr r9, [r6, #0x4] */
/* @0x1ada04 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ada08 and r9, r11, r9 */
/* @0x1ada0c ldr r2, [r8, r9, lsl #3] */
/* @0x1ada10 add r3, r8, r9, lsl #3 */
/* @0x1ada14 cmp r2, #0 */
/* @0x1ada18 ldrne r2, [r3, #0x4] */
/* @0x1ada1c str r11, [r0, #0x8] */
/* @0x1ada20 str r5, [r0, #0xc] */
/* @0x1ada24 strne r2, [r0] */
/* @0x1ada28 streq r0, [r3, #0x4] */
/* @0x1ada2c strne r0, [r2, #0x4] */
/* @0x1ada30 streq r0, [r8, r9, lsl #3] */
/* @0x1ada34 mov r8, r10 */
/* @0x1ada38 strne r0, [r3, #0x4] */
/* @0x1ada3c streq r2, [r0, #0x4] */
/* @0x1ada40 streq r2, [r0] */
/* @0x1ada44 strne r7, [r0, #0x4] */
/* @0x1ada48 cmp r10, #0 */
/* @0x1ada4c ldr r3, [r6, #0x8] */
/* @0x1ada50 add r3, r3, #1 */
/* @0x1ada54 str r3, [r6, #0x8] */
/* @0x1ada58 bne 0x1ad978 <_ZN5CRoom6AssignEPS_b+0x26c> */
/* @0x1ada5c add sp, sp, #52 */
/* @0x1ada60 vpop {d8} */
/* @0x1ada64 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ada68 ldr r6, [sp, #0x10] */
/* @0x1ada6c ldr r3, [r6, #0xb4] */
/* @0x1ada70 cmp r3, #0 */
/* @0x1ada74 beq 0x1ada90 <_ZN5CRoom6AssignEPS_b+0x384> */
/* @0x1ada78 mov r0, #488 */
/* @0x1ada7c bl 0x27c524 <_Znwj> */
/* @0x1ada80 ldr r1, [r6, #0xb4] */
/* @0x1ada84 mov r5, r0 */
/* @0x1ada88 bl 0x237d90 <_ZN13CPhysicsWorldC2EPS_> */
/* @0x1ada8c str r5, [r4, #0xb4] */
/* @0x1ada90 mov r0, r4 */
/* @0x1ada94 ldr r1, [sp, #0x10] */
/* @0x1ada98 bl 0x1c47e0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_> */
/* @0x1ada9c ldrb r3, [r4, #0xd0] */
/* @0x1adaa0 cmp r3, #0 */
/* @0x1adaa4 beq 0x1ade48 <_ZN5CRoom6AssignEPS_b+0x73c> */
/* @0x1adaa8 ldr r9, [sp, #0x10] */
/* @0x1adaac ldr r3, [r9, #0xac] */
/* @0x1adab0 ldr r12, [r3, #0x34] */
/* @0x1adab4 cmp r12, #0 */
/* @0x1adab8 str r12, [sp, #0x20] */
/* @0x1adabc beq 0x1ae27c <_ZN5CRoom6AssignEPS_b+0xb70> */
/* @0x1adac0 ldr r6, [r9, #0xc4] */
/* @0x1adac4 mov r2, #52 */
/* @0x1adac8 ldr r7, [r6], #4 */
/* @0x1adacc mul r2, r2, r7 */
/* @0x1adad0 lsl r9, r7, #2 */
/* @0x1adad4 str r6, [sp, #0x28] */
/* @0x1adad8 str r7, [sp, #0x14] */
/* @0x1adadc add r2, r2, #4 */
/* @0x1adae0 str r9, [sp, #0x20] */
/* @0x1adae4 str r2, [sp, #0x2c] */
/* @0x1adae8 ldr r8, [r3, #0x30] */
/* @0x1adaec movw r2, #0x14e */
/* @0x1adaf0 ldr r6, [pc, #0x804] */
/* @0x1adaf4 mov r3, #1 */
/* @0x1adaf8 cmp r8, #0 */
/* @0x1adafc mov r0, #96 */
/* @0x1adb00 add r6, pc, r6 */
/* @0x1adb04 mov r5, #88 */
/* @0x1adb08 ldrne r7, [sp, #0x10] */
/* @0x1adb0c moveq r9, #4 */
/* @0x1adb10 mov r1, r6 */
/* @0x1adb14 moveq r10, r8 */
/* @0x1adb18 moveq r7, r9 */
/* @0x1adb1c ldrne r9, [r7, #0xc8] */
/* @0x1adb20 movne r7, #44 */
/* @0x1adb24 ldrne r10, [r9], #4 */
/* @0x1adb28 mulne r7, r7, r10 */
/* @0x1adb2c lslne r8, r10, #2 */
/* @0x1adb30 addne r7, r7, #4 */
/* @0x1adb34 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1adb38 mov r2, r5 */
/* @0x1adb3c mov r1, #0 */
/* @0x1adb40 str r0, [r4, #0xac] */
/* @0x1adb44 bl 0xb65b0 <memset@plt> */
/* @0x1adb48 ldr r12, [sp, #0x10] */
/* @0x1adb4c ldr r11, [r4, #0xac] */
/* @0x1adb50 mov lr, #92 */
/* @0x1adb54 mov r1, r6 */
/* @0x1adb58 mov r2, #344 */
/* @0x1adb5c ldr r3, [r12, #0xac] */
/* @0x1adb60 mov r0, r7 */
/* @0x1adb64 ldr r12, [r3, #0x10] */
/* @0x1adb68 mov r3, #1 */
/* @0x1adb6c str r11, [r4, #0xb0] */
/* @0x1adb70 str lr, [r11, #0x34] */
/* @0x1adb74 str r5, [r11, #0x30] */
/* @0x1adb78 str r12, [r11, #0x10] */
/* @0x1adb7c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1adb80 mov r2, #0 */
/* @0x1adb84 cmp r10, r2 */
/* @0x1adb88 mov r3, r0 */
/* @0x1adb8c str r0, [r11, #0x58] */
/* @0x1adb90 strb r2, [r3], #1 */
/* @0x1adb94 add r3, r3, #1 */
/* @0x1adb98 strb r2, [r0, #0x1] */
/* @0x1adb9c strb r2, [r3], #1 */
/* @0x1adba0 strb r2, [r3] */
/* @0x1adba4 ldr lr, [r11, #0x58] */
/* @0x1adba8 mov r1, lr */
/* @0x1adbac str lr, [sp, #0x24] */
/* @0x1adbb0 str r10, [r1], #4 */
/* @0x1adbb4 add r1, r1, r8 */
/* @0x1adbb8 ble 0x1adc28 <_ZN5CRoom6AssignEPS_b+0x51c> */
/* @0x1adbbc ldr r0, [sp, #0x24] */
/* @0x1adbc0 sub r12, r9, #4 */
/* @0x1adbc4 mov r9, r2 */
/* @0x1adbc8 str r1, [r0, #0x4]! */
/* @0x1adbcc mov r2, r1 */
/* @0x1adbd0 ldr r3, [r12, #0x4]! */
/* @0x1adbd4 add lr, r3, #32 */
/* @0x1adbd8 ldr r8, [r3] */
/* @0x1adbdc add r3, r3, #16 */
/* @0x1adbe0 ldr r7, [r3, #-0xc] */
/* @0x1adbe4 add r2, r2, #16 */
/* @0x1adbe8 ldr r6, [r3, #-0x8] */
/* @0x1adbec ldr r5, [r3, #-0x4] */
/* @0x1adbf0 cmp r3, lr */
/* @0x1adbf4 str r8, [r2, #-0x10] */
/* @0x1adbf8 str r7, [r2, #-0xc] */
/* @0x1adbfc str r6, [r2, #-0x8] */
/* @0x1adc00 str r5, [r2, #-0x4] */
/* @0x1adc04 bne 0x1adbd8 <_ZN5CRoom6AssignEPS_b+0x4cc> */
/* @0x1adc08 ldr lr, [r3] */
/* @0x1adc0c add r9, r9, #1 */
/* @0x1adc10 ldr r3, [r3, #0x4] */
/* @0x1adc14 cmp r9, r10 */
/* @0x1adc18 add r1, r1, #40 */
/* @0x1adc1c str lr, [r2] */
/* @0x1adc20 str r3, [r2, #0x4] */
/* @0x1adc24 bne 0x1adbc8 <_ZN5CRoom6AssignEPS_b+0x4bc> */
/* @0x1adc28 ldr r0, [sp, #0x24] */
/* @0x1adc2c mov r3, #1 */
/* @0x1adc30 ldr r1, [pc, #0x6c8] */
/* @0x1adc34 movw r2, #0x165 */
/* @0x1adc38 mov r10, #0 */
/* @0x1adc3c str r0, [r4, #0xc8] */
/* @0x1adc40 add r1, pc, r1 */
/* @0x1adc44 ldr r0, [sp, #0x2c] */
/* @0x1adc48 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1adc4c ldr r6, [sp, #0x14] */
/* @0x1adc50 ldr r7, [sp, #0x20] */
/* @0x1adc54 cmp r6, r10 */
/* @0x1adc58 mov r3, r0 */
/* @0x1adc5c str r0, [r11, #0x5c] */
/* @0x1adc60 strb r10, [r3], #1 */
/* @0x1adc64 add r3, r3, #1 */
/* @0x1adc68 strb r10, [r0, #0x1] */
/* @0x1adc6c strb r10, [r3], #1 */
/* @0x1adc70 strb r10, [r3] */
/* @0x1adc74 ldr r11, [r11, #0x5c] */
/* @0x1adc78 mov r1, r11 */
/* @0x1adc7c str r6, [r1], #4 */
/* @0x1adc80 add r1, r1, r7 */
/* @0x1adc84 str r6, [r4, #0xb8] */
/* @0x1adc88 ble 0x1adcf4 <_ZN5CRoom6AssignEPS_b+0x5e8> */
/* @0x1adc8c ldr r9, [sp, #0x28] */
/* @0x1adc90 mov r0, r11 */
/* @0x1adc94 str r4, [sp, #0x20] */
/* @0x1adc98 ldr r4, [sp, #0x14] */
/* @0x1adc9c sub r12, r9, #4 */
/* @0x1adca0 str r1, [r0, #0x4]! */
/* @0x1adca4 mov r2, r1 */
/* @0x1adca8 ldr r3, [r12, #0x4]! */
/* @0x1adcac add r5, r3, #48 */
/* @0x1adcb0 ldr r9, [r3] */
/* @0x1adcb4 add r3, r3, #16 */
/* @0x1adcb8 ldr r8, [r3, #-0xc] */
/* @0x1adcbc add r2, r2, #16 */
/* @0x1adcc0 ldr r7, [r3, #-0x8] */
/* @0x1adcc4 ldr r6, [r3, #-0x4] */
/* @0x1adcc8 cmp r3, r5 */
/* @0x1adccc str r9, [r2, #-0x10] */
/* @0x1adcd0 str r8, [r2, #-0xc] */
/* @0x1adcd4 str r7, [r2, #-0x8] */
/* @0x1adcd8 str r6, [r2, #-0x4] */
/* @0x1adcdc bne 0x1adcb0 <_ZN5CRoom6AssignEPS_b+0x5a4> */
/* @0x1adce0 add r10, r10, #1 */
/* @0x1adce4 add r1, r1, #48 */
/* @0x1adce8 cmp r10, r4 */
/* @0x1adcec bne 0x1adca0 <_ZN5CRoom6AssignEPS_b+0x594> */
/* @0x1adcf0 ldr r4, [sp, #0x20] */
/* @0x1adcf4 ldr r12, [sp, #0x1c] */
/* @0x1adcf8 str r11, [r4, #0xc4] */
/* @0x1adcfc cmp r12, #0 */
/* @0x1add00 bne 0x1ade68 <_ZN5CRoom6AssignEPS_b+0x75c> */
/* @0x1add04 ldrb r3, [r4, #0xd0] */
/* @0x1add08 cmp r3, #0 */
/* @0x1add0c beq 0x1ae2b8 <_ZN5CRoom6AssignEPS_b+0xbac> */
/* @0x1add10 ldr r6, [sp, #0x10] */
/* @0x1add14 ldr r7, [r6, #0x80] */
/* @0x1add18 cmp r7, #0 */
/* @0x1add1c beq 0x1ad94c <_ZN5CRoom6AssignEPS_b+0x240> */
/* @0x1add20 ldr r3, [pc, #0x5cc] */
/* @0x1add24 mov r10, #0 */
/* @0x1add28 ldr r12, [sp, #0x18] */
/* @0x1add2c ldr r9, [pc, #0x5d0] */
/* @0x1add30 add r9, pc, r9 */
/* @0x1add34 str r9, [sp, #0x14] */
/* @0x1add38 ldr r6, [r12, r3] */
/* @0x1add3c mov r0, #432 */
/* @0x1add40 ldr r8, [r7, #0x178] */
/* @0x1add44 bl 0x27c524 <_Znwj> */
/* @0x1add48 mov r1, #0 */
/* @0x1add4c mov r3, #0 */
/* @0x1add50 mov r2, r1 */
/* @0x1add54 str r10, [sp] */
/* @0x1add58 str r10, [sp, #0x4] */
/* @0x1add5c mov r5, r0 */
/* @0x1add60 bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1add64 mov r2, #1 */
/* @0x1add68 mov r0, r5 */
/* @0x1add6c mov r1, r7 */
/* @0x1add70 bl 0x1986ec <_ZN9CInstance6AssignEPS_b> */
/* @0x1add74 ldr r3, [r4, #0x84] */
/* @0x1add78 ldr r2, [r4, #0x88] */
/* @0x1add7c cmp r3, #0 */
/* @0x1add80 vldrne s14, [r5, #384] */
/* @0x1add84 add r2, r2, #1 */
/* @0x1add88 str r2, [r4, #0x88] */
/* @0x1add8c beq 0x1ae22c <_ZN5CRoom6AssignEPS_b+0xb20> */
/* @0x1add90 vldr s15, [r3, #388] */
/* @0x1add94 vcmpe.f32 s15, s14 */
/* @0x1add98 vmrs APSR_nzcv, fpscr */
/* @0x1add9c bls 0x1ae1f8 <_ZN5CRoom6AssignEPS_b+0xaec> */
/* @0x1adda0 ldr r3, [r3, #0x17c] */
/* @0x1adda4 cmp r3, #0 */
/* @0x1adda8 bne 0x1add90 <_ZN5CRoom6AssignEPS_b+0x684> */
/* @0x1addac ldr r2, [r4, #0x80] */
/* @0x1addb0 vstr s14, [r5, #388] */
/* @0x1addb4 str r5, [r2, #0x17c] */
/* @0x1addb8 str r2, [r5, #0x178] */
/* @0x1addbc str r5, [r4, #0x80] */
/* @0x1addc0 str r3, [r5, #0x17c] */
/* @0x1addc4 movw r2, #0x132 */
/* @0x1addc8 mov r3, #1 */
/* @0x1addcc mov r0, #16 */
/* @0x1addd0 ldr r1, [sp, #0x14] */
/* @0x1addd4 ldr r7, [r6] */
/* @0x1addd8 ldr r9, [r5, #0x78] */
/* @0x1adddc ldr r11, [r6, #0x4] */
/* @0x1adde0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1adde4 and r11, r9, r11 */
/* @0x1adde8 ldr r2, [r7, r11, lsl #3] */
/* @0x1addec add r3, r7, r11, lsl #3 */
/* @0x1addf0 cmp r2, #0 */
/* @0x1addf4 ldrne r2, [r3, #0x4] */
/* @0x1addf8 str r9, [r0, #0x8] */
/* @0x1addfc str r5, [r0, #0xc] */
/* @0x1ade00 strne r2, [r0] */
/* @0x1ade04 streq r0, [r3, #0x4] */
/* @0x1ade08 strne r0, [r2, #0x4] */
/* @0x1ade0c streq r0, [r7, r11, lsl #3] */
/* @0x1ade10 strne r0, [r3, #0x4] */
/* @0x1ade14 streq r2, [r0, #0x4] */
/* @0x1ade18 streq r2, [r0] */
/* @0x1ade1c strne r10, [r0, #0x4] */
/* @0x1ade20 cmp r8, #0 */
/* @0x1ade24 ldr r3, [r6, #0x8] */
/* @0x1ade28 add r3, r3, #1 */
/* @0x1ade2c str r3, [r6, #0x8] */
/* @0x1ade30 beq 0x1ad94c <_ZN5CRoom6AssignEPS_b+0x240> */
/* @0x1ade34 mov r7, r8 */
/* @0x1ade38 b 0x1add3c <_ZN5CRoom6AssignEPS_b+0x630> */
/* @0x1ade3c ldr r3, [r5, #0x48] */
/* @0x1ade40 str r6, [r3, #0x40] */
/* @0x1ade44 b 0x1ad880 <_ZN5CRoom6AssignEPS_b+0x174> */
/* @0x1ade48 ldr r7, [sp, #0x10] */
/* @0x1ade4c ldr r12, [sp, #0x1c] */
/* @0x1ade50 ldr r2, [r7, #0xac] */
/* @0x1ade54 cmp r12, #0 */
/* @0x1ade58 ldr r3, [r7, #0xb0] */
/* @0x1ade5c str r2, [r4, #0xac] */
/* @0x1ade60 str r3, [r4, #0xb0] */
/* @0x1ade64 beq 0x1add04 <_ZN5CRoom6AssignEPS_b+0x5f8> */
/* @0x1ade68 ldr r6, [sp, #0x10] */
/* @0x1ade6c ldr r3, [r6, #0xac] */
/* @0x1ade70 cmp r3, #0 */
/* @0x1ade74 beq 0x1add04 <_ZN5CRoom6AssignEPS_b+0x5f8> */
/* @0x1ade78 ldr r3, [r3, #0x34] */
/* @0x1ade7c cmp r3, #0 */
/* @0x1ade80 streq r3, [r4, #0xb8] */
/* @0x1ade84 streq r3, [sp, #0x24] */
/* @0x1ade88 bne 0x1ae294 <_ZN5CRoom6AssignEPS_b+0xb88> */
/* @0x1ade8c ldr r9, [sp, #0x10] */
/* @0x1ade90 ldr r9, [r9, #0xc8] */
/* @0x1ade94 cmp r9, #0 */
/* @0x1ade98 str r9, [sp, #0x14] */
/* @0x1ade9c beq 0x1ae0f0 <_ZN5CRoom6AssignEPS_b+0x9e4> */
/* @0x1adea0 ldr r6, [sp, #0x14] */
/* @0x1adea4 movw r2, #0x18e */
/* @0x1adea8 ldr r1, [pc, #0x458] */
/* @0x1adeac mov r3, #1 */
/* @0x1adeb0 mov r7, #0 */
/* @0x1adeb4 ldr r0, [r6] */
/* @0x1adeb8 add r1, pc, r1 */
/* @0x1adebc lsl r0, r0, #2 */
/* @0x1adec0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1adec4 ldr r2, [r6] */
/* @0x1adec8 mov r1, r7 */
/* @0x1adecc str r7, [r4, #0xa8] */
/* @0x1aded0 lsl r2, r2, #2 */
/* @0x1aded4 str r0, [r4, #0xa4] */
/* @0x1aded8 bl 0xb65b0 <memset@plt> */
/* @0x1adedc ldr r2, [r6] */
/* @0x1adee0 cmp r2, r7 */
/* @0x1adee4 ble 0x1ae0f0 <_ZN5CRoom6AssignEPS_b+0x9e4> */
/* @0x1adee8 ldr r11, [sp, #0x14] */
/* @0x1adeec vldr s16, [pc, #1008] */
/* @0x1adef0 ldr r9, [pc, #0x414] */
/* @0x1adef4 add r9, pc, r9 */
/* @0x1adef8 str r9, [sp, #0x20] */
/* @0x1adefc ldr r6, [r11, #0x4]! */
/* @0x1adf00 ldr r3, [r6, #0x8] */
/* @0x1adf04 cmp r3, #0 */
/* @0x1adf08 blt 0x1ae0e4 <_ZN5CRoom6AssignEPS_b+0x9d8> */
/* @0x1adf0c mov r0, #432 */
/* @0x1adf10 mov r9, #1 */
/* @0x1adf14 bl 0x27c524 <_Znwj> */
/* @0x1adf18 vldr s10, [r6] */
/* @0x1adf1c vcvt.f32.s32 s10, s10 */
/* @0x1adf20 ldr r2, [r6, #0x4] */
/* @0x1adf24 ldr r12, [r6, #0x8] */
/* @0x1adf28 ldr r3, [r6, #0xc] */
/* @0x1adf2c str r9, [sp, #0x4] */
/* @0x1adf30 str r12, [sp] */
/* @0x1adf34 vmov r1, s10 */
/* @0x1adf38 vmov s10, r2 */
/* @0x1adf3c vcvt.f32.s32 s10, s10 */
/* @0x1adf40 vmov r2, s10 */
/* @0x1adf44 mov r5, r0 */
/* @0x1adf48 bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1adf4c ldr r0, [r6, #0x10] */
/* @0x1adf50 bl 0xced64 <_Z13Code_GetEntryi> */
/* @0x1adf54 str r0, [r5, #0x160] */
/* @0x1adf58 ldr r0, [r6, #0x24] */
/* @0x1adf5c bl 0xced64 <_Z13Code_GetEntryi> */
/* @0x1adf60 ldr r1, [r6, #0x14] */
/* @0x1adf64 str r0, [r5, #0x164] */
/* @0x1adf68 mov r0, r5 */
/* @0x1adf6c bl 0x192fec <_ZN9CInstance14SetImageScaleXEf> */
/* @0x1adf70 mov r0, r5 */
/* @0x1adf74 ldr r1, [r6, #0x18] */
/* @0x1adf78 bl 0x193014 <_ZN9CInstance14SetImageScaleYEf> */
/* @0x1adf7c ldr r3, [r6, #0x1c] */
/* @0x1adf80 mov r0, r5 */
/* @0x1adf84 bic r3, r3, #-16777216 */
/* @0x1adf88 str r3, [r5, #0xa8] */
/* @0x1adf8c ldrb r1, [r6, #0x1f] */
/* @0x1adf90 vmov s15, r1 */
/* @0x1adf94 vcvt.f32.s32 s15, s15 */
/* @0x1adf98 vdiv.f32 s15, s15, s16 */
/* @0x1adf9c vstr s15, [r5, #164] */
/* @0x1adfa0 ldr r1, [r6, #0x20] */
/* @0x1adfa4 bl 0x19303c <_ZN9CInstance13SetImageAngleEf> */
/* @0x1adfa8 ldr r9, [sp, #0x18] */
/* @0x1adfac ldr r3, [pc, #0x35c] */
/* @0x1adfb0 mov r0, r5 */
/* @0x1adfb4 ldr r2, [r5, #0x7c] */
/* @0x1adfb8 mov r1, r4 */
/* @0x1adfbc ldr r3, [r9, r3] */
/* @0x1adfc0 str r2, [r3] */
/* @0x1adfc4 bl 0x192cd4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom> */
/* @0x1adfc8 ldr r1, [r5, #0x78] */
/* @0x1adfcc mov r0, r4 */
/* @0x1adfd0 bl 0x1b8cb8 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi> */
/* @0x1adfd4 mov r1, r0 */
/* @0x1adfd8 mov r0, r4 */
/* @0x1adfdc bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1adfe0 mov r2, r5 */
/* @0x1adfe4 mov r1, r0 */
/* @0x1adfe8 mov r0, r4 */
/* @0x1adfec bl 0x1c5a38 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance> */
/* @0x1adff0 ldr r3, [r4, #0x84] */
/* @0x1adff4 ldr r2, [r4, #0x88] */
/* @0x1adff8 cmp r3, #0 */
/* @0x1adffc vldrne s14, [r5, #384] */
/* @0x1ae000 add r2, r2, #1 */
/* @0x1ae004 str r2, [r4, #0x88] */
/* @0x1ae008 beq 0x1ae334 <_ZN5CRoom6AssignEPS_b+0xc28> */
/* @0x1ae00c vldr s15, [r3, #388] */
/* @0x1ae010 vcmpe.f32 s15, s14 */
/* @0x1ae014 vmrs APSR_nzcv, fpscr */
/* @0x1ae018 bls 0x1ae248 <_ZN5CRoom6AssignEPS_b+0xb3c> */
/* @0x1ae01c ldr r3, [r3, #0x17c] */
/* @0x1ae020 cmp r3, #0 */
/* @0x1ae024 bne 0x1ae00c <_ZN5CRoom6AssignEPS_b+0x900> */
/* @0x1ae028 ldr r2, [r4, #0x80] */
/* @0x1ae02c vstr s14, [r5, #388] */
/* @0x1ae030 str r5, [r2, #0x17c] */
/* @0x1ae034 str r2, [r5, #0x178] */
/* @0x1ae038 str r5, [r4, #0x80] */
/* @0x1ae03c str r3, [r5, #0x17c] */
/* @0x1ae040 ldr lr, [pc, #0x2ac] */
/* @0x1ae044 movw r2, #0x132 */
/* @0x1ae048 ldr r9, [sp, #0x18] */
/* @0x1ae04c mov r3, #1 */
/* @0x1ae050 ldr r12, [r5, #0x78] */
/* @0x1ae054 mov r0, #16 */
/* @0x1ae058 ldr r1, [sp, #0x20] */
/* @0x1ae05c ldr r8, [r9, lr] */
/* @0x1ae060 ldm r8, {r9, r10} */
/* @0x1ae064 str r12, [sp, #0xc] */
/* @0x1ae068 and r10, r12, r10 */
/* @0x1ae06c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ae070 ldr r12, [sp, #0xc] */
/* @0x1ae074 ldr r2, [r9, r10, lsl #3] */
/* @0x1ae078 add r3, r9, r10, lsl #3 */
/* @0x1ae07c cmp r2, #0 */
/* @0x1ae080 ldrne r2, [r3, #0x4] */
/* @0x1ae084 movne r1, #0 */
/* @0x1ae088 str r12, [r0, #0x8] */
/* @0x1ae08c str r5, [r0, #0xc] */
/* @0x1ae090 strne r2, [r0] */
/* @0x1ae094 streq r0, [r3, #0x4] */
/* @0x1ae098 strne r0, [r2, #0x4] */
/* @0x1ae09c strne r0, [r3, #0x4] */
/* @0x1ae0a0 ldr r3, [r8, #0x8] */
/* @0x1ae0a4 streq r0, [r9, r10, lsl #3] */
/* @0x1ae0a8 strne r1, [r0, #0x4] */
/* @0x1ae0ac add r3, r3, #1 */
/* @0x1ae0b0 streq r2, [r0, #0x4] */
/* @0x1ae0b4 streq r2, [r0] */
/* @0x1ae0b8 mov r0, r5 */
/* @0x1ae0bc str r3, [r8, #0x8] */
/* @0x1ae0c0 bl 0x1cc494 <_Z15CollisionInsertP9CInstance> */
/* @0x1ae0c4 ldr r3, [r4, #0xa8] */
/* @0x1ae0c8 ldr r1, [r6, #0xc] */
/* @0x1ae0cc ldr r2, [r4, #0xa4] */
/* @0x1ae0d0 add r0, r3, #1 */
/* @0x1ae0d4 ldr r12, [sp, #0x14] */
/* @0x1ae0d8 str r0, [r4, #0xa8] */
/* @0x1ae0dc str r1, [r2, r3, lsl #2] */
/* @0x1ae0e0 ldr r2, [r12] */
/* @0x1ae0e4 add r7, r7, #1 */
/* @0x1ae0e8 cmp r2, r7 */
/* @0x1ae0ec bgt 0x1adefc <_ZN5CRoom6AssignEPS_b+0x7f0> */
/* @0x1ae0f0 ldr r12, [sp, #0x24] */
/* @0x1ae0f4 cmp r12, #0 */
/* @0x1ae0f8 beq 0x1add10 <_ZN5CRoom6AssignEPS_b+0x604> */
/* @0x1ae0fc ldr r5, [r4, #0xb8] */
/* @0x1ae100 cmp r5, #0 */
/* @0x1ae104 beq 0x1ae31c <_ZN5CRoom6AssignEPS_b+0xc10> */
/* @0x1ae108 rsb r3, r5, r5, lsl #3 */
/* @0x1ae10c ldr r0, [r4, #0xc0] */
/* @0x1ae110 lsls r1, r3, #3 */
/* @0x1ae114 beq 0x1ae3d8 <_ZN5CRoom6AssignEPS_b+0xccc> */
/* @0x1ae118 ldr r2, [pc, #0x1f4] */
/* @0x1ae11c mov r3, #0 */
/* @0x1ae120 str r3, [sp] */
/* @0x1ae124 mov r3, #106 */
/* @0x1ae128 add r2, pc, r2 */
/* @0x1ae12c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1ae130 str r0, [r4, #0xc0] */
/* @0x1ae134 ldr r7, [r4, #0xb8] */
/* @0x1ae138 str r5, [r4, #0xbc] */
/* @0x1ae13c cmp r7, #0 */
/* @0x1ae140 ble 0x1add10 <_ZN5CRoom6AssignEPS_b+0x604> */
/* @0x1ae144 ldr r3, [r4, #0xc0] */
/* @0x1ae148 mov r6, #1 */
/* @0x1ae14c ldr r1, [sp, #0x24] */
/* @0x1ae150 vldr s11, [pc, #396] */
/* @0x1ae154 add r3, r3, #48 */
/* @0x1ae158 add r7, r1, r7, lsl #2 */
/* @0x1ae15c ldr r2, [r1, #0x4]! */
/* @0x1ae160 vldr s14, [r2, #4] */
/* @0x1ae164 vldr s15, [r2, #28] */
/* @0x1ae168 vldr s10, [r2] */
/* @0x1ae16c vcvt.f32.s32 s14, s14 */
/* @0x1ae170 cmp r1, r7 */
/* @0x1ae174 ldr r0, [r2, #0x2c] */
/* @0x1ae178 add r3, r3, #56 */
/* @0x1ae17c ldr r8, [r2, #0x8] */
/* @0x1ae180 bic r12, r0, #-16777216 */
/* @0x1ae184 ldr r5, [r2, #0xc] */
/* @0x1ae188 lsr r0, r0, #24 */
/* @0x1ae18c ldr r9, [r2, #0x24] */
/* @0x1ae190 str r8, [r3, #-0x60] */
/* @0x1ae194 vmov s13, r0 */
/* @0x1ae198 ldr r8, [r2, #0x28] */
/* @0x1ae19c vcvt.f32.s32 s12, s10 */
/* @0x1ae1a0 str r5, [r3, #-0x5c] */
/* @0x1ae1a4 ldr r5, [r2, #0x10] */
/* @0x1ae1a8 ldr r0, [r2, #0x18] */
/* @0x1ae1ac str r5, [r3, #-0x58] */
/* @0x1ae1b0 ldr r5, [r2, #0x14] */
/* @0x1ae1b4 ldr r2, [r2, #0x20] */
/* @0x1ae1b8 vstr s14, [r3, #-100] */
/* @0x1ae1bc vcvt.f32.s32 s13, s13 */
/* @0x1ae1c0 vstr s12, [r3, #-104] */
/* @0x1ae1c4 str r9, [r3, #-0x44] */
/* @0x1ae1c8 str r5, [r3, #-0x54] */
/* @0x1ae1cc str r8, [r3, #-0x40] */
/* @0x1ae1d0 str r0, [r3, #-0x50] */
/* @0x1ae1d4 str r2, [r3, #-0x48] */
/* @0x1ae1d8 str r12, [r3, #-0x3c] */
/* @0x1ae1dc vdiv.f32 s13, s13, s11 */
/* @0x1ae1e0 strb r6, [r3, #-0x34] */
/* @0x1ae1e4 vcvt.f32.s32 s15, s15 */
/* @0x1ae1e8 vstr s13, [r3, #-56] */
/* @0x1ae1ec vstr s15, [r3, #-76] */
/* @0x1ae1f0 bne 0x1ae15c <_ZN5CRoom6AssignEPS_b+0xa50> */
/* @0x1ae1f4 b 0x1add10 <_ZN5CRoom6AssignEPS_b+0x604> */
/* @0x1ae1f8 ldr r2, [r3, #0x178] */
/* @0x1ae1fc cmp r2, #0 */
/* @0x1ae200 streq r3, [r5, #0x17c] */
/* @0x1ae204 strne r2, [r5, #0x178] */
/* @0x1ae208 ldrne r2, [r3, #0x178] */
/* @0x1ae20c streq r5, [r3, #0x178] */
/* @0x1ae210 strne r3, [r5, #0x17c] */
/* @0x1ae214 streq r5, [r4, #0x84] */
/* @0x1ae218 strne r5, [r2, #0x17c] */
/* @0x1ae21c streq r2, [r5, #0x178] */
/* @0x1ae220 strne r5, [r3, #0x178] */
/* @0x1ae224 vstr s14, [r5, #388] */
/* @0x1ae228 b 0x1addc4 <_ZN5CRoom6AssignEPS_b+0x6b8> */
/* @0x1ae22c ldr r2, [r5, #0x180] */
/* @0x1ae230 str r5, [r4, #0x84] */
/* @0x1ae234 str r5, [r4, #0x80] */
/* @0x1ae238 str r2, [r5, #0x184] */
/* @0x1ae23c str r3, [r5, #0x17c] */
/* @0x1ae240 str r3, [r5, #0x178] */
/* @0x1ae244 b 0x1addc4 <_ZN5CRoom6AssignEPS_b+0x6b8> */
/* @0x1ae248 ldr r2, [r3, #0x178] */
/* @0x1ae24c cmp r2, #0 */
/* @0x1ae250 streq r3, [r5, #0x17c] */
/* @0x1ae254 strne r2, [r5, #0x178] */
/* @0x1ae258 ldrne r2, [r3, #0x178] */
/* @0x1ae25c streq r5, [r3, #0x178] */
/* @0x1ae260 strne r3, [r5, #0x17c] */
/* @0x1ae264 streq r5, [r4, #0x84] */
/* @0x1ae268 strne r5, [r2, #0x17c] */
/* @0x1ae26c streq r2, [r5, #0x178] */
/* @0x1ae270 strne r5, [r3, #0x178] */
/* @0x1ae274 vstr s14, [r5, #388] */
/* @0x1ae278 b 0x1ae040 <_ZN5CRoom6AssignEPS_b+0x934> */
/* @0x1ae27c ldr r6, [sp, #0x20] */
/* @0x1ae280 mov r12, #4 */
/* @0x1ae284 str r12, [sp, #0x28] */
/* @0x1ae288 str r12, [sp, #0x2c] */
/* @0x1ae28c str r6, [sp, #0x14] */
/* @0x1ae290 b 0x1adae8 <_ZN5CRoom6AssignEPS_b+0x3dc> */
/* @0x1ae294 ldr r7, [sp, #0x10] */
/* @0x1ae298 mov r3, #0 */
/* @0x1ae29c ldr r7, [r7, #0xc4] */
/* @0x1ae2a0 str r3, [r4, #0xb8] */
/* @0x1ae2a4 cmp r7, r3 */
/* @0x1ae2a8 str r7, [sp, #0x24] */
/* @0x1ae2ac ldrne r3, [r7] */
/* @0x1ae2b0 strne r3, [r4, #0xb8] */
/* @0x1ae2b4 b 0x1ade8c <_ZN5CRoom6AssignEPS_b+0x780> */
/* @0x1ae2b8 ldr r6, [sp, #0x10] */
/* @0x1ae2bc ldr r5, [r6, #0xb8] */
/* @0x1ae2c0 cmp r5, #0 */
/* @0x1ae2c4 str r5, [r4, #0xb8] */
/* @0x1ae2c8 bne 0x1ae350 <_ZN5CRoom6AssignEPS_b+0xc44> */
/* @0x1ae2cc ldr r0, [r4, #0xc0] */
/* @0x1ae2d0 cmp r0, #0 */
/* @0x1ae2d4 beq 0x1ae3e8 <_ZN5CRoom6AssignEPS_b+0xcdc> */
/* @0x1ae2d8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ae2dc str r5, [r4, #0xc0] */
/* @0x1ae2e0 b 0x1ae378 <_ZN5CRoom6AssignEPS_b+0xc6c> */
/* @0x1ae2e4 cmnmi pc, #0 */
/* @0x1ae2e8 eoreq r4, r4, r0, lsr #10 */
/* @0x1ae2ec .word 0xffffbcd4 */
/* @0x1ae2f0 .word 0xffffc024 */
/* @0x1ae2f4 .word 0xffffbff4 */
/* @0x1ae2f8 andseq pc, r9, r0, asr #6 */
/* @0x1ae2fc andseq pc, r9, r8, lsr #13 */
/* @0x1ae300 andseq pc, r9, r8, ror #10 */
/* @0x1ae304 andseq lr, r9, r12, ror pc */
/* @0x1ae308 ldrsheq pc, [r9], -r0 */
/* @0x1ae30c ldrheq lr, [r9], -r8 */
/* @0x1ae310 .word 0xffffc168 */
/* @0x1ae314 andseq pc, r9, r12, lsl #2 */
/* @0x1ae318 andseq lr, r9, r8, asr #29 */
/* @0x1ae31c ldr r0, [r4, #0xc0] */
/* @0x1ae320 cmp r0, #0 */
/* @0x1ae324 beq 0x1ae3d8 <_ZN5CRoom6AssignEPS_b+0xccc> */
/* @0x1ae328 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ae32c str r5, [r4, #0xc0] */
/* @0x1ae330 b 0x1ae134 <_ZN5CRoom6AssignEPS_b+0xa28> */
/* @0x1ae334 ldr r2, [r5, #0x180] */
/* @0x1ae338 str r5, [r4, #0x84] */
/* @0x1ae33c str r5, [r4, #0x80] */
/* @0x1ae340 str r2, [r5, #0x184] */
/* @0x1ae344 str r3, [r5, #0x17c] */
/* @0x1ae348 str r3, [r5, #0x178] */
/* @0x1ae34c b 0x1ae040 <_ZN5CRoom6AssignEPS_b+0x934> */
/* @0x1ae350 rsb r2, r5, r5, lsl #3 */
/* @0x1ae354 ldr r0, [r4, #0xc0] */
/* @0x1ae358 lsls r1, r2, #3 */
/* @0x1ae35c beq 0x1ae3e8 <_ZN5CRoom6AssignEPS_b+0xcdc> */
/* @0x1ae360 ldr r2, [pc, #-0x50] */
/* @0x1ae364 str r3, [sp] */
/* @0x1ae368 mov r3, #106 */
/* @0x1ae36c add r2, pc, r2 */
/* @0x1ae370 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1ae374 str r0, [r4, #0xc0] */
/* @0x1ae378 ldr r7, [r4, #0xb8] */
/* @0x1ae37c str r5, [r4, #0xbc] */
/* @0x1ae380 cmp r7, #0 */
/* @0x1ae384 ble 0x1add10 <_ZN5CRoom6AssignEPS_b+0x604> */
/* @0x1ae388 ldr r12, [sp, #0x10] */
/* @0x1ae38c rsb r7, r7, r7, lsl #3 */
/* @0x1ae390 ldr r8, [r4, #0xc0] */
/* @0x1ae394 mov r6, #0 */
/* @0x1ae398 lsl r7, r7, #3 */
/* @0x1ae39c ldr r9, [r12, #0xc0] */
/* @0x1ae3a0 add r5, r9, r6 */
/* @0x1ae3a4 add r12, r8, r6 */
/* @0x1ae3a8 add r6, r6, #56 */
/* @0x1ae3ac ldm r5!, {r0, r1, r2, r3} */
/* @0x1ae3b0 cmp r6, r7 */
/* @0x1ae3b4 stm r12!, {r0, r1, r2, r3} */
/* @0x1ae3b8 ldm r5!, {r0, r1, r2, r3} */
/* @0x1ae3bc stm r12!, {r0, r1, r2, r3} */
/* @0x1ae3c0 ldm r5!, {r0, r1, r2, r3} */
/* @0x1ae3c4 stm r12!, {r0, r1, r2, r3} */
/* @0x1ae3c8 ldm r5, {r0, r1} */
/* @0x1ae3cc stm r12, {r0, r1} */
/* @0x1ae3d0 bne 0x1ae3a0 <_ZN5CRoom6AssignEPS_b+0xc94> */
/* @0x1ae3d4 b 0x1add10 <_ZN5CRoom6AssignEPS_b+0x604> */
/* @0x1ae3d8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ae3dc mov r3, #0 */
/* @0x1ae3e0 str r3, [r4, #0xc0] */
/* @0x1ae3e4 b 0x1ae134 <_ZN5CRoom6AssignEPS_b+0xa28> */
/* @0x1ae3e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ae3ec mov r3, #0 */
/* @0x1ae3f0 str r3, [r4, #0xc0] */
/* @0x1ae3f4 b 0x1ae378 <_ZN5CRoom6AssignEPS_b+0xc6c> */

/* ── FUNC 0x1ae3f8 · CRoom::LoadFromStream(CStream*) · size=1604 · insn=401 */
/* @0x1ae3f8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ae3fc vpush {d8} */
/* @0x1ae400 mov r4, r1 */
/* @0x1ae404 sub sp, sp, #28 */
/* @0x1ae408 mov r6, r0 */
/* @0x1ae40c bl 0x1ad0a4 <_ZN5CRoom5ClearEv> */
/* @0x1ae410 mov r0, r4 */
/* @0x1ae414 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae418 movw r3, #0x21d */
/* @0x1ae41c cmp r0, r3 */
/* @0x1ae420 movne r0, #0 */
/* @0x1ae424 beq 0x1ae434 <_ZN5CRoom14LoadFromStreamEP7CStream+0x3c> */
/* @0x1ae428 add sp, sp, #28 */
/* @0x1ae42c vpop {d8} */
/* @0x1ae430 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ae434 ldr r0, [r6, #0x8] */
/* @0x1ae438 cmp r0, #0 */
/* @0x1ae43c beq 0x1ae44c <_ZN5CRoom14LoadFromStreamEP7CStream+0x54> */
/* @0x1ae440 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ae444 mov r3, #0 */
/* @0x1ae448 str r3, [r6, #0x8] */
/* @0x1ae44c add r1, r6, #8 */
/* @0x1ae450 mov r0, r4 */
/* @0x1ae454 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* @0x1ae458 mov r0, r4 */
/* @0x1ae45c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae460 str r0, [r6, #0x10] */
/* @0x1ae464 mov r0, r4 */
/* @0x1ae468 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae46c str r0, [r6, #0x14] */
/* @0x1ae470 mov r0, r4 */
/* @0x1ae474 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae478 str r0, [r6, #0xc] */
/* @0x1ae47c mov r0, r4 */
/* @0x1ae480 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1ae484 strb r0, [r6, #0x18] */
/* @0x1ae488 mov r0, r4 */
/* @0x1ae48c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae490 str r0, [r6, #0x1c] */
/* @0x1ae494 mov r0, r4 */
/* @0x1ae498 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1ae49c ldr r3, [r6, #0x68] */
/* @0x1ae4a0 cmp r3, #0 */
/* @0x1ae4a4 strb r0, [r6, #0x20] */
/* @0x1ae4a8 beq 0x1ae4bc <_ZN5CRoom14LoadFromStreamEP7CStream+0xc4> */
/* @0x1ae4ac mov r0, r3 */
/* @0x1ae4b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ae4b4 mov r3, #0 */
/* @0x1ae4b8 str r3, [r6, #0x68] */
/* @0x1ae4bc mov r0, r4 */
/* @0x1ae4c0 add r1, r6, #104 */
/* @0x1ae4c4 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* @0x1ae4c8 mov r0, r4 */
/* @0x1ae4cc bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae4d0 mov r7, #0 */
/* @0x1ae4d4 strb r7, [r6, #0x70] */
/* @0x1ae4d8 subs r9, r0, #0 */
/* @0x1ae4dc vmovgt.f32 s16, #1.000000e+00 */
/* @0x1ae4e0 movgt r5, r6 */
/* @0x1ae4e4 mvngt r10, #-16777216 */
/* @0x1ae4e8 bgt 0x1ae500 <_ZN5CRoom14LoadFromStreamEP7CStream+0x108> */
/* @0x1ae4ec b 0x1ae654 <_ZN5CRoom14LoadFromStreamEP7CStream+0x25c> */
/* @0x1ae4f0 add r7, r7, #1 */
/* @0x1ae4f4 add r5, r5, #4 */
/* @0x1ae4f8 cmp r7, r9 */
/* @0x1ae4fc beq 0x1ae654 <_ZN5CRoom14LoadFromStreamEP7CStream+0x25c> */
/* @0x1ae500 mov r0, r4 */
/* @0x1ae504 ldr r8, [r5, #0x24] */
/* @0x1ae508 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1ae50c ldr r11, [r5, #0x24] */
/* @0x1ae510 strb r0, [r8] */
/* @0x1ae514 mov r0, r4 */
/* @0x1ae518 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1ae51c ldr r8, [r5, #0x24] */
/* @0x1ae520 strb r0, [r11, #0x1] */
/* @0x1ae524 mov r0, r4 */
/* @0x1ae528 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae52c ldr r11, [r5, #0x24] */
/* @0x1ae530 str r0, [r8, #0x4] */
/* @0x1ae534 mov r0, r4 */
/* @0x1ae538 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae53c ldr r8, [r5, #0x24] */
/* @0x1ae540 vmov s13, r0 */
/* @0x1ae544 mov r0, r4 */
/* @0x1ae548 vcvt.f32.s32 s15, s13 */
/* @0x1ae54c vstr s15, [r11, #8] */
/* @0x1ae550 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae554 ldr r11, [r5, #0x24] */
/* @0x1ae558 vmov s14, r0 */
/* @0x1ae55c mov r0, r4 */
/* @0x1ae560 vcvt.f32.s32 s15, s14 */
/* @0x1ae564 vstr s15, [r8, #12] */
/* @0x1ae568 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1ae56c ldr r8, [r5, #0x24] */
/* @0x1ae570 strb r0, [r11, #0x10] */
/* @0x1ae574 mov r0, r4 */
/* @0x1ae578 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1ae57c ldr r11, [r5, #0x24] */
/* @0x1ae580 strb r0, [r8, #0x11] */
/* @0x1ae584 mov r0, r4 */
/* @0x1ae588 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae58c ldr r8, [r5, #0x24] */
/* @0x1ae590 vmov s13, r0 */
/* @0x1ae594 mov r0, r4 */
/* @0x1ae598 vcvt.f32.s32 s15, s13 */
/* @0x1ae59c vstr s15, [r11, #20] */
/* @0x1ae5a0 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae5a4 ldr r3, [r5, #0x24] */
/* @0x1ae5a8 vmov s14, r0 */
/* @0x1ae5ac mov r0, r4 */
/* @0x1ae5b0 vcvt.f32.s32 s15, s14 */
/* @0x1ae5b4 vstr s15, [r8, #24] */
/* @0x1ae5b8 str r10, [r3, #0x24] */
/* @0x1ae5bc vstr s16, [r3, #40] */
/* @0x1ae5c0 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1ae5c4 cmp r0, #0 */
/* @0x1ae5c8 beq 0x1ae4f0 <_ZN5CRoom14LoadFromStreamEP7CStream+0xf8> */
/* @0x1ae5cc ldr r3, [r5, #0x24] */
/* @0x1ae5d0 ldr r0, [r3, #0x4] */
/* @0x1ae5d4 bl 0xc3640 <_Z17Background_Existsi> */
/* @0x1ae5d8 cmp r0, #0 */
/* @0x1ae5dc beq 0x1ae4f0 <_ZN5CRoom14LoadFromStreamEP7CStream+0xf8> */
/* @0x1ae5e0 ldr r3, [r5, #0x24] */
/* @0x1ae5e4 add r7, r7, #1 */
/* @0x1ae5e8 add r5, r5, #4 */
/* @0x1ae5ec ldr r0, [r3, #0x4] */
/* @0x1ae5f0 bl 0xc3794 <_Z15Background_Datai> */
/* @0x1ae5f4 bl 0xc2d78 <_ZN11CBackground8GetWidthEv> */
/* @0x1ae5f8 ldr r3, [r5, #0x20] */
/* @0x1ae5fc vmov s13, r0 */
/* @0x1ae600 ldr r0, [r3, #0x4] */
/* @0x1ae604 vcvt.f32.s32 s15, s13 */
/* @0x1ae608 vcmpe.f32 s15, #0 */
/* @0x1ae60c vmrs APSR_nzcv, fpscr */
/* @0x1ae610 vldrgt s13, [r6, #16] */
/* @0x1ae614 vcvtgt.f32.s32 s14, s13 */
/* @0x1ae618 vdivgt.f32 s15, s14, s15 */
/* @0x1ae61c vstrgt s15, [r3, #28] */
/* @0x1ae620 bl 0xc3794 <_Z15Background_Datai> */
/* @0x1ae624 bl 0xc2d80 <_ZN11CBackground9GetHeightEv> */
/* @0x1ae628 vmov s14, r0 */
/* @0x1ae62c vcvt.f32.s32 s15, s14 */
/* @0x1ae630 vcmpe.f32 s15, #0 */
/* @0x1ae634 vmrs APSR_nzcv, fpscr */
/* @0x1ae638 vldrgt s13, [r6, #20] */
/* @0x1ae63c vcvtgt.f32.s32 s14, s13 */
/* @0x1ae640 ldrgt r3, [r5, #0x20] */
/* @0x1ae644 vdivgt.f32 s15, s14, s15 */
/* @0x1ae648 vstrgt s15, [r3, #32] */
/* @0x1ae64c cmp r7, r9 */
/* @0x1ae650 bne 0x1ae500 <_ZN5CRoom14LoadFromStreamEP7CStream+0x108> */
/* @0x1ae654 mov r0, r4 */
/* @0x1ae658 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1ae65c strb r0, [r6, #0x44] */
/* @0x1ae660 mov r0, r4 */
/* @0x1ae664 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae668 subs r10, r0, #0 */
/* @0x1ae66c movgt r5, r6 */
/* @0x1ae670 movgt r7, #0 */
/* @0x1ae674 movgt r11, #0 */
/* @0x1ae678 ble 0x1ae790 <_ZN5CRoom14LoadFromStreamEP7CStream+0x398> */
/* @0x1ae67c mov r0, r4 */
/* @0x1ae680 ldr r9, [r5, #0x48] */
/* @0x1ae684 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1ae688 ldr r8, [r5, #0x48] */
/* @0x1ae68c add r7, r7, #1 */
/* @0x1ae690 add r5, r5, #4 */
/* @0x1ae694 strb r0, [r9] */
/* @0x1ae698 mov r0, r4 */
/* @0x1ae69c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae6a0 ldr r9, [r5, #0x44] */
/* @0x1ae6a4 vmov s14, r0 */
/* @0x1ae6a8 mov r0, r4 */
/* @0x1ae6ac vcvt.f32.s32 s15, s14 */
/* @0x1ae6b0 vstr s15, [r8, #4] */
/* @0x1ae6b4 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae6b8 ldr r8, [r5, #0x44] */
/* @0x1ae6bc vmov s13, r0 */
/* @0x1ae6c0 mov r0, r4 */
/* @0x1ae6c4 vcvt.f32.s32 s15, s13 */
/* @0x1ae6c8 vstr s15, [r9, #8] */
/* @0x1ae6cc bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae6d0 ldr r9, [r5, #0x44] */
/* @0x1ae6d4 vmov s14, r0 */
/* @0x1ae6d8 mov r0, r4 */
/* @0x1ae6dc vcvt.f32.s32 s15, s14 */
/* @0x1ae6e0 vstr s15, [r8, #12] */
/* @0x1ae6e4 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae6e8 ldr r8, [r5, #0x44] */
/* @0x1ae6ec vmov s13, r0 */
/* @0x1ae6f0 mov r0, r4 */
/* @0x1ae6f4 vcvt.f32.s32 s15, s13 */
/* @0x1ae6f8 vstr s15, [r9, #16] */
/* @0x1ae6fc bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae700 ldr r9, [r5, #0x44] */
/* @0x1ae704 str r0, [r8, #0x14] */
/* @0x1ae708 mov r0, r4 */
/* @0x1ae70c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae710 ldr r8, [r5, #0x44] */
/* @0x1ae714 str r0, [r9, #0x18] */
/* @0x1ae718 mov r0, r4 */
/* @0x1ae71c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae720 ldr r9, [r5, #0x44] */
/* @0x1ae724 str r0, [r8, #0x1c] */
/* @0x1ae728 mov r0, r4 */
/* @0x1ae72c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae730 ldr r8, [r5, #0x44] */
/* @0x1ae734 str r0, [r9, #0x20] */
/* @0x1ae738 mov r0, r4 */
/* @0x1ae73c str r11, [r8, #0x24] */
/* @0x1ae740 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae744 ldr r9, [r5, #0x44] */
/* @0x1ae748 str r0, [r8, #0x28] */
/* @0x1ae74c mov r0, r4 */
/* @0x1ae750 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae754 ldr r8, [r5, #0x44] */
/* @0x1ae758 str r0, [r9, #0x2c] */
/* @0x1ae75c mov r0, r4 */
/* @0x1ae760 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae764 ldr r9, [r5, #0x44] */
/* @0x1ae768 str r0, [r8, #0x30] */
/* @0x1ae76c mov r0, r4 */
/* @0x1ae770 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae774 ldr r8, [r5, #0x44] */
/* @0x1ae778 str r0, [r9, #0x34] */
/* @0x1ae77c mov r0, r4 */
/* @0x1ae780 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae784 cmp r7, r10 */
/* @0x1ae788 str r0, [r8, #0x38] */
/* @0x1ae78c bne 0x1ae67c <_ZN5CRoom14LoadFromStreamEP7CStream+0x284> */
/* @0x1ae790 mov r0, r4 */
/* @0x1ae794 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae798 cmp r0, #0 */
/* @0x1ae79c str r0, [sp, #0xc] */
/* @0x1ae7a0 addgt r10, sp, #20 */
/* @0x1ae7a4 movgt r8, #0 */
/* @0x1ae7a8 movgt r7, r8 */
/* @0x1ae7ac ble 0x1ae894 <_ZN5CRoom14LoadFromStreamEP7CStream+0x49c> */
/* @0x1ae7b0 mov r0, r4 */
/* @0x1ae7b4 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae7b8 vmov s17, r0 */
/* @0x1ae7bc mov r0, r4 */
/* @0x1ae7c0 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae7c4 vmov s16, r0 */
/* @0x1ae7c8 mov r0, r4 */
/* @0x1ae7cc bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae7d0 mov r9, r0 */
/* @0x1ae7d4 mov r0, r4 */
/* @0x1ae7d8 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae7dc mov r11, r0 */
/* @0x1ae7e0 mov r0, #432 */
/* @0x1ae7e4 bl 0x27c524 <_Znwj> */
/* @0x1ae7e8 vcvt.f32.s32 s17, s17 */
/* @0x1ae7ec mov r3, r11 */
/* @0x1ae7f0 str r9, [sp] */
/* @0x1ae7f4 str r7, [sp, #0x4] */
/* @0x1ae7f8 vcvt.f32.s32 s16, s16 */
/* @0x1ae7fc vmov r1, s17 */
/* @0x1ae800 vmov r2, s16 */
/* @0x1ae804 mov r5, r0 */
/* @0x1ae808 bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1ae80c mov r0, r4 */
/* @0x1ae810 mov r1, r10 */
/* @0x1ae814 str r7, [sp, #0x14] */
/* @0x1ae818 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* @0x1ae81c str r7, [r5, #0x160] */
/* @0x1ae820 str r7, [r5, #0x164] */
/* @0x1ae824 ldr r3, [r6, #0x84] */
/* @0x1ae828 ldr r2, [r6, #0x88] */
/* @0x1ae82c cmp r3, #0 */
/* @0x1ae830 vldrne s14, [r5, #384] */
/* @0x1ae834 add r2, r2, #1 */
/* @0x1ae838 str r2, [r6, #0x88] */
/* @0x1ae83c beq 0x1ae9f4 <_ZN5CRoom14LoadFromStreamEP7CStream+0x5fc> */
/* @0x1ae840 vldr s15, [r3, #388] */
/* @0x1ae844 vcmpe.f32 s15, s14 */
/* @0x1ae848 vmrs APSR_nzcv, fpscr */
/* @0x1ae84c bls 0x1ae9c0 <_ZN5CRoom14LoadFromStreamEP7CStream+0x5c8> */
/* @0x1ae850 ldr r3, [r3, #0x17c] */
/* @0x1ae854 cmp r3, #0 */
/* @0x1ae858 bne 0x1ae840 <_ZN5CRoom14LoadFromStreamEP7CStream+0x448> */
/* @0x1ae85c ldr r2, [r6, #0x80] */
/* @0x1ae860 vstr s14, [r5, #388] */
/* @0x1ae864 str r5, [r2, #0x17c] */
/* @0x1ae868 str r2, [r5, #0x178] */
/* @0x1ae86c str r5, [r6, #0x80] */
/* @0x1ae870 str r3, [r5, #0x17c] */
/* @0x1ae874 ldr r0, [sp, #0x14] */
/* @0x1ae878 cmp r0, #0 */
/* @0x1ae87c beq 0x1ae884 <_ZN5CRoom14LoadFromStreamEP7CStream+0x48c> */
/* @0x1ae880 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ae884 ldr r3, [sp, #0xc] */
/* @0x1ae888 add r8, r8, #1 */
/* @0x1ae88c cmp r8, r3 */
/* @0x1ae890 bne 0x1ae7b0 <_ZN5CRoom14LoadFromStreamEP7CStream+0x3b8> */
/* @0x1ae894 mov r0, r4 */
/* @0x1ae898 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae89c cmp r0, #0 */
/* @0x1ae8a0 mov r5, r0 */
/* @0x1ae8a4 str r0, [r6, #0xb8] */
/* @0x1ae8a8 beq 0x1aea10 <_ZN5CRoom14LoadFromStreamEP7CStream+0x618> */
/* @0x1ae8ac rsb r3, r0, r0, lsl #3 */
/* @0x1ae8b0 ldr r0, [r6, #0xc0] */
/* @0x1ae8b4 lsls r1, r3, #3 */
/* @0x1ae8b8 beq 0x1aea28 <_ZN5CRoom14LoadFromStreamEP7CStream+0x630> */
/* @0x1ae8bc ldr r2, [pc, #0x174] */
/* @0x1ae8c0 mov r3, #0 */
/* @0x1ae8c4 str r3, [sp] */
/* @0x1ae8c8 mov r3, #106 */
/* @0x1ae8cc add r2, pc, r2 */
/* @0x1ae8d0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1ae8d4 str r0, [r6, #0xc0] */
/* @0x1ae8d8 ldr r3, [r6, #0xb8] */
/* @0x1ae8dc str r5, [r6, #0xbc] */
/* @0x1ae8e0 cmp r3, #0 */
/* @0x1ae8e4 ble 0x1ae9b0 <_ZN5CRoom14LoadFromStreamEP7CStream+0x5b8> */
/* @0x1ae8e8 mov r7, #0 */
/* @0x1ae8ec mov r9, #1065353216 */
/* @0x1ae8f0 mov r8, r7 */
/* @0x1ae8f4 mvn r11, #-16777216 */
/* @0x1ae8f8 mov r10, #1 */
/* @0x1ae8fc mov r0, r4 */
/* @0x1ae900 ldr r5, [r6, #0xc0] */
/* @0x1ae904 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae908 add r8, r8, #1 */
/* @0x1ae90c add r5, r5, r7 */
/* @0x1ae910 add r7, r7, #56 */
/* @0x1ae914 vmov s13, r0 */
/* @0x1ae918 mov r0, r4 */
/* @0x1ae91c vcvt.f32.s32 s15, s13 */
/* @0x1ae920 vstr s15, [r5] */
/* @0x1ae924 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae928 vmov s14, r0 */
/* @0x1ae92c mov r0, r4 */
/* @0x1ae930 vcvt.f32.s32 s15, s14 */
/* @0x1ae934 vstr s15, [r5, #4] */
/* @0x1ae938 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae93c str r0, [r5, #0x8] */
/* @0x1ae940 mov r0, r4 */
/* @0x1ae944 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae948 str r0, [r5, #0xc] */
/* @0x1ae94c mov r0, r4 */
/* @0x1ae950 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae954 str r0, [r5, #0x10] */
/* @0x1ae958 mov r0, r4 */
/* @0x1ae95c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae960 str r0, [r5, #0x14] */
/* @0x1ae964 mov r0, r4 */
/* @0x1ae968 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae96c str r0, [r5, #0x18] */
/* @0x1ae970 mov r0, r4 */
/* @0x1ae974 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae978 vmov s13, r0 */
/* @0x1ae97c mov r0, r4 */
/* @0x1ae980 vcvt.f32.s32 s15, s13 */
/* @0x1ae984 vstr s15, [r5, #28] */
/* @0x1ae988 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae98c ldr r3, [r6, #0xb8] */
/* @0x1ae990 str r9, [r5, #0x24] */
/* @0x1ae994 cmp r3, r8 */
/* @0x1ae998 str r9, [r5, #0x28] */
/* @0x1ae99c str r11, [r5, #0x2c] */
/* @0x1ae9a0 str r9, [r5, #0x30] */
/* @0x1ae9a4 strb r10, [r5, #0x34] */
/* @0x1ae9a8 str r0, [r5, #0x20] */
/* @0x1ae9ac bgt 0x1ae8fc <_ZN5CRoom14LoadFromStreamEP7CStream+0x504> */
/* @0x1ae9b0 mov r0, #1 */
/* @0x1ae9b4 add sp, sp, #28 */
/* @0x1ae9b8 vpop {d8} */
/* @0x1ae9bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ae9c0 ldr r2, [r3, #0x178] */
/* @0x1ae9c4 cmp r2, #0 */
/* @0x1ae9c8 streq r3, [r5, #0x17c] */
/* @0x1ae9cc strne r2, [r5, #0x178] */
/* @0x1ae9d0 ldrne r2, [r3, #0x178] */
/* @0x1ae9d4 streq r5, [r3, #0x178] */
/* @0x1ae9d8 strne r3, [r5, #0x17c] */
/* @0x1ae9dc streq r5, [r6, #0x84] */
/* @0x1ae9e0 strne r5, [r2, #0x17c] */
/* @0x1ae9e4 streq r2, [r5, #0x178] */
/* @0x1ae9e8 strne r5, [r3, #0x178] */
/* @0x1ae9ec vstr s14, [r5, #388] */
/* @0x1ae9f0 b 0x1ae874 <_ZN5CRoom14LoadFromStreamEP7CStream+0x47c> */
/* @0x1ae9f4 ldr r2, [r5, #0x180] */
/* @0x1ae9f8 str r5, [r6, #0x84] */
/* @0x1ae9fc str r5, [r6, #0x80] */
/* @0x1aea00 str r2, [r5, #0x184] */
/* @0x1aea04 str r3, [r5, #0x17c] */
/* @0x1aea08 str r3, [r5, #0x178] */
/* @0x1aea0c b 0x1ae874 <_ZN5CRoom14LoadFromStreamEP7CStream+0x47c> */
/* @0x1aea10 ldr r0, [r6, #0xc0] */
/* @0x1aea14 cmp r0, #0 */
/* @0x1aea18 beq 0x1aea28 <_ZN5CRoom14LoadFromStreamEP7CStream+0x630> */
/* @0x1aea1c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1aea20 str r5, [r6, #0xc0] */
/* @0x1aea24 b 0x1ae8d8 <_ZN5CRoom14LoadFromStreamEP7CStream+0x4e0> */
/* @0x1aea28 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1aea2c mov r3, #0 */
/* @0x1aea30 str r3, [r6, #0xc0] */
/* @0x1aea34 b 0x1ae8d8 <_ZN5CRoom14LoadFromStreamEP7CStream+0x4e0> */
/* @0x1aea38 andseq lr, r9, r8, ror #18 */

/* ── FUNC 0x1aea3c · CRoom::LoadFromChunk(YYRoom*, unsigned char*) · size=2176 · insn=544 */
/* @0x1aea3c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1aea40 vpush {d8} */
/* @0x1aea44 mov r4, r0 */
/* @0x1aea48 sub sp, sp, #20 */
/* @0x1aea4c mov r8, r1 */
/* @0x1aea50 mov r5, r2 */
/* @0x1aea54 bl 0x1ad0a4 <_ZN5CRoom5ClearEv> */
/* @0x1aea58 ldr r0, [r4, #0xe4] */
/* @0x1aea5c mov r2, #70 */
/* @0x1aea60 ldr r1, [pc, #0x334] */
/* @0x1aea64 mov r3, #1 */
/* @0x1aea68 sub r12, r0, #1 */
/* @0x1aea6c str r12, [r4, #0xec] */
/* @0x1aea70 add r0, r0, r0, lsl #1 */
/* @0x1aea74 add r1, pc, r1 */
/* @0x1aea78 ldr r7, [pc, #0x320] */
/* @0x1aea7c lsl r6, r0, #2 */
/* @0x1aea80 add r7, pc, r7 */
/* @0x1aea84 mov r0, r6 */
/* @0x1aea88 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1aea8c mov r2, r6 */
/* @0x1aea90 mov r1, #0 */
/* @0x1aea94 str r0, [r4, #0xf4] */
/* @0x1aea98 bl 0xb65b0 <memset@plt> */
/* @0x1aea9c ldr r2, [r4, #0xe4] */
/* @0x1aeaa0 vldr s15, [pc, #752] */
/* @0x1aeaa4 mov r1, #0 */
/* @0x1aeaa8 cmp r2, r1 */
/* @0x1aeaac str r1, [r4, #0xe8] */
/* @0x1aeab0 vmov s11, r2 */
/* @0x1aeab4 vcvt.f32.s32 s14, s11 */
/* @0x1aeab8 vmul.f32 s15, s14, s15 */
/* @0x1aeabc vcvt.s32.f32 s15, s15 */
/* @0x1aeac0 vstr s15, [r4, #240] */
/* @0x1aeac4 ble 0x1aeae4 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0xa8> */
/* @0x1aeac8 add r2, r2, r2, lsl #1 */
/* @0x1aeacc ldr r3, [r4, #0xf4] */
/* @0x1aead0 add r2, r3, r2, lsl #2 */
/* @0x1aead4 str r1, [r3, #0x8] */
/* @0x1aead8 add r3, r3, #12 */
/* @0x1aeadc cmp r3, r2 */
/* @0x1aeae0 bne 0x1aead4 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x98> */
/* @0x1aeae4 ldr r0, [r4, #0xf8] */
/* @0x1aeae8 mov r2, #70 */
/* @0x1aeaec ldr r1, [pc, #0x2b0] */
/* @0x1aeaf0 mov r3, #1 */
/* @0x1aeaf4 sub r12, r0, #1 */
/* @0x1aeaf8 str r12, [r4, #0x100] */
/* @0x1aeafc add r0, r0, r0, lsl #1 */
/* @0x1aeb00 add r1, pc, r1 */
/* @0x1aeb04 lsl r6, r0, #2 */
/* @0x1aeb08 mov r0, r6 */
/* @0x1aeb0c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1aeb10 mov r2, r6 */
/* @0x1aeb14 mov r1, #0 */
/* @0x1aeb18 str r0, [r4, #0x108] */
/* @0x1aeb1c bl 0xb65b0 <memset@plt> */
/* @0x1aeb20 ldr r2, [r4, #0xf8] */
/* @0x1aeb24 vldr s15, [pc, #620] */
/* @0x1aeb28 mov r1, #0 */
/* @0x1aeb2c cmp r2, r1 */
/* @0x1aeb30 str r1, [r4, #0xfc] */
/* @0x1aeb34 vmov s13, r2 */
/* @0x1aeb38 vcvt.f32.s32 s14, s13 */
/* @0x1aeb3c vmul.f32 s15, s14, s15 */
/* @0x1aeb40 vcvt.s32.f32 s15, s15 */
/* @0x1aeb44 vstr s15, [r4, #260] */
/* @0x1aeb48 ble 0x1aeb68 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x12c> */
/* @0x1aeb4c add r2, r2, r2, lsl #1 */
/* @0x1aeb50 ldr r3, [r4, #0x108] */
/* @0x1aeb54 add r2, r3, r2, lsl #2 */
/* @0x1aeb58 str r1, [r3, #0x8] */
/* @0x1aeb5c add r3, r3, #12 */
/* @0x1aeb60 cmp r3, r2 */
/* @0x1aeb64 bne 0x1aeb58 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x11c> */
/* @0x1aeb68 ldr r0, [r4, #0x110] */
/* @0x1aeb6c mov r2, #70 */
/* @0x1aeb70 ldr r1, [pc, #0x230] */
/* @0x1aeb74 mov r3, #1 */
/* @0x1aeb78 sub r12, r0, #1 */
/* @0x1aeb7c str r12, [r4, #0x118] */
/* @0x1aeb80 add r0, r0, r0, lsl #1 */
/* @0x1aeb84 add r1, pc, r1 */
/* @0x1aeb88 lsl r6, r0, #2 */
/* @0x1aeb8c mov r0, r6 */
/* @0x1aeb90 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1aeb94 mov r2, r6 */
/* @0x1aeb98 mov r1, #0 */
/* @0x1aeb9c str r0, [r4, #0x120] */
/* @0x1aeba0 bl 0xb65b0 <memset@plt> */
/* @0x1aeba4 ldr r1, [r4, #0x110] */
/* @0x1aeba8 vldr s15, [pc, #488] */
/* @0x1aebac mov r2, #0 */
/* @0x1aebb0 cmp r1, r2 */
/* @0x1aebb4 str r2, [r4, #0x114] */
/* @0x1aebb8 vmov s11, r1 */
/* @0x1aebbc vcvt.f32.s32 s14, s11 */
/* @0x1aebc0 vmul.f32 s15, s14, s15 */
/* @0x1aebc4 vcvt.s32.f32 s15, s15 */
/* @0x1aebc8 vstr s15, [r4, #284] */
/* @0x1aebcc ble 0x1aebec <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x1b0> */
/* @0x1aebd0 add r1, r1, r1, lsl #1 */
/* @0x1aebd4 ldr r3, [r4, #0x120] */
/* @0x1aebd8 add r1, r3, r1, lsl #2 */
/* @0x1aebdc str r2, [r3, #0x8] */
/* @0x1aebe0 add r3, r3, #12 */
/* @0x1aebe4 cmp r3, r1 */
/* @0x1aebe8 bne 0x1aebdc <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x1a0> */
/* @0x1aebec ldr r3, [r8] */
/* @0x1aebf0 str r5, [r4, #0xb0] */
/* @0x1aebf4 cmp r3, #0 */
/* @0x1aebf8 str r8, [r4, #0xac] */
/* @0x1aebfc moveq r5, r3 */
/* @0x1aec00 ldrne r2, [pc, #0x1c8] */
/* @0x1aec04 ldrne r2, [r7, r2] */
/* @0x1aec08 ldrne r5, [r2] */
/* @0x1aec0c addne r5, r5, r3 */
/* @0x1aec10 ldr r0, [r4, #0xcc] */
/* @0x1aec14 cmp r0, #0 */
/* @0x1aec18 beq 0x1aec20 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x1e4> */
/* @0x1aec1c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1aec20 mov r0, r5 */
/* @0x1aec24 bl 0xb6538 <strlen@plt> */
/* @0x1aec28 ldr r1, [pc, #0x17c] */
/* @0x1aec2c mov r3, #1 */
/* @0x1aec30 movw r2, #0x25b */
/* @0x1aec34 add r1, pc, r1 */
/* @0x1aec38 add r0, r0, r3 */
/* @0x1aec3c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1aec40 mov r1, r5 */
/* @0x1aec44 str r0, [r4, #0xcc] */
/* @0x1aec48 bl 0xb65a4 <strcpy@plt> */
/* @0x1aec4c ldr r0, [r8, #0x4] */
/* @0x1aec50 cmp r0, #0 */
/* @0x1aec54 ldrne r3, [pc, #0x174] */
/* @0x1aec58 ldrne r3, [r7, r3] */
/* @0x1aec5c ldrne r3, [r3] */
/* @0x1aec60 addne r0, r3, r0 */
/* @0x1aec64 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1aec68 ldr lr, [r8, #0x14] */
/* @0x1aec6c ldr r1, [r8, #0x1c] */
/* @0x1aec70 adds lr, lr, #0 */
/* @0x1aec74 ldr r6, [r8, #0x8] */
/* @0x1aec78 ldr r5, [r8, #0xc] */
/* @0x1aec7c ldr r12, [r8, #0x10] */
/* @0x1aec80 movne lr, #1 */
/* @0x1aec84 ldr r2, [r8, #0x18] */
/* @0x1aec88 adds r1, r1, #0 */
/* @0x1aec8c ldr r3, [pc, #0x11c] */
/* @0x1aec90 movne r1, #1 */
/* @0x1aec94 str r6, [r4, #0x10] */
/* @0x1aec98 str r5, [r4, #0x14] */
/* @0x1aec9c strb lr, [r4, #0x18] */
/* @0x1aeca0 str r12, [r4, #0xc] */
/* @0x1aeca4 strb r1, [r4, #0x20] */
/* @0x1aeca8 str r2, [r4, #0x1c] */
/* @0x1aecac str r0, [r4, #0x8] */
/* @0x1aecb0 ldr r3, [r7, r3] */
/* @0x1aecb4 ldrb r3, [r3] */
/* @0x1aecb8 cmp r3, #0 */
/* @0x1aecbc bne 0x1af0e0 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x6a4> */
/* @0x1aecc0 ldr r3, [pc, #0xec] */
/* @0x1aecc4 ldr r3, [r7, r3] */
/* @0x1aecc8 ldrb r3, [r3] */
/* @0x1aeccc cmp r3, #0 */
/* @0x1aecd0 bne 0x1af0e0 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x6a4> */
/* @0x1aecd4 ldr r9, [r8, #0x24] */
/* @0x1aecd8 mov r1, #0 */
/* @0x1aecdc ldr r3, [pc, #0xd4] */
/* @0x1aece0 eor r2, r9, #4 */
/* @0x1aece4 and r0, r9, #1 */
/* @0x1aece8 ubfx r2, r2, #0x2, #0x1 */
/* @0x1aecec strb r0, [r4, #0x44] */
/* @0x1aecf0 strb r2, [r4, #0x46] */
/* @0x1aecf4 ubfx r2, r9, #0x1, #0x1 */
/* @0x1aecf8 strb r1, [r4, #0x70] */
/* @0x1aecfc asr r9, r9, #16 */
/* @0x1aed00 strb r2, [r4, #0x45] */
/* @0x1aed04 str r9, [sp, #0xc] */
/* @0x1aed08 ldr r3, [r7, r3] */
/* @0x1aed0c ldr r3, [r3] */
/* @0x1aed10 cmp r3, #5 */
/* @0x1aed14 ble 0x1aed50 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x314> */
/* @0x1aed18 vldr s14, [r8, #76] */
/* @0x1aed1c vldr s15, [r8, #80] */
/* @0x1aed20 vcvt.s32.f32 s14, s14 */
/* @0x1aed24 ldr r3, [r8, #0x38] */
/* @0x1aed28 ldr r2, [r8, #0x54] */
/* @0x1aed2c subs r3, r3, r1 */
/* @0x1aed30 movne r3, #1 */
/* @0x1aed34 cmp r3, r1 */
/* @0x1aed38 str r2, [r4, #0x7c] */
/* @0x1aed3c strb r3, [r4, #0x70] */
/* @0x1aed40 vcvt.s32.f32 s15, s15 */
/* @0x1aed44 vstr s14, [r4, #116] */
/* @0x1aed48 vstr s15, [r4, #120] */
/* @0x1aed4c bne 0x1af1a4 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x768> */
/* @0x1aed50 ldr r6, [r8, #0x28] */
/* @0x1aed54 cmp r6, #0 */
/* @0x1aed58 moveq r1, #4 */
/* @0x1aed5c beq 0x1aed74 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x338> */
/* @0x1aed60 ldr r3, [pc, #0x68] */
/* @0x1aed64 ldr r3, [r7, r3] */
/* @0x1aed68 ldr r3, [r3] */
/* @0x1aed6c add r6, r3, r6 */
/* @0x1aed70 add r1, r6, #4 */
/* @0x1aed74 ldr r12, [r6] */
/* @0x1aed78 cmp r12, #0 */
/* @0x1aed7c ble 0x1aeeb4 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x478> */
/* @0x1aed80 vmov.f32 s16, #1.000000e+00 */
/* @0x1aed84 sub r9, r1, #4 */
/* @0x1aed88 mov r10, r4 */
/* @0x1aed8c mov r11, #0 */
/* @0x1aed90 mvn r5, #-16777216 */
/* @0x1aed94 b 0x1aedec <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x3b0> */
/* @0x1aed98 svclo #0x19999a */
/* @0x1aed9c ldrheq r2, [r8], -r12 */
/* @0x1aeda0 .word 0x002431d0 */
/* @0x1aeda4 andseq r2, r8, r0, lsr r5 */
/* @0x1aeda8 andseq r2, r8, r12, lsr #9 */
/* @0x1aedac andseq lr, r9, r12, lsr r6 */
/* @0x1aedb0 .word 0xffffbf10 */
/* @0x1aedb4 .word 0xffffbecc */
/* @0x1aedb8 .word 0xffffea88 */
/* @0x1aedbc .word 0xffffc024 */
/* @0x1aedc0 andseq lr, r9, r0, asr r1 */
/* @0x1aedc4 andseq pc, r7, r2, asr r10 */
/* @0x1aedc8 .word 0xffffbcd4 */
/* @0x1aedcc andseq sp, r9, r0, lsr #31 */
/* @0x1aedd0 .word 0xffffbcf4 */
/* @0x1aedd4 .word 0xffffebc4 */
/* @0x1aedd8 andeq r0, r0, r0 */
/* @0x1aeddc add r11, r11, #1 */
/* @0x1aede0 add r10, r10, #4 */
/* @0x1aede4 cmp r12, r11 */
/* @0x1aede8 ble 0x1aeeb4 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x478> */
/* @0x1aedec ldr r2, [r9, #0x4]! */
/* @0x1aedf0 cmp r2, #0 */
/* @0x1aedf4 ldrne r3, [pc, #-0x2c] */
/* @0x1aedf8 ldrne r3, [r7, r3] */
/* @0x1aedfc ldrne r3, [r3] */
/* @0x1aee00 addne r2, r3, r2 */
/* @0x1aee04 ldr r1, [r2] */
/* @0x1aee08 vldr s13, [r2, #16] */
/* @0x1aee0c ldr r3, [r10, #0x24] */
/* @0x1aee10 vldr s14, [r2, #28] */
/* @0x1aee14 ldr r0, [r2, #0x4] */
/* @0x1aee18 adds r1, r1, #0 */
/* @0x1aee1c vldr s15, [r2, #32] */
/* @0x1aee20 vldr s11, [r2, #12] */
/* @0x1aee24 movne r1, #1 */
/* @0x1aee28 adds r0, r0, #0 */
/* @0x1aee2c strb r1, [r3] */
/* @0x1aee30 vcvt.f32.s32 s12, s11 */
/* @0x1aee34 ldr r1, [r2, #0x14] */
/* @0x1aee38 movne r0, #1 */
/* @0x1aee3c ldr lr, [r2, #0x18] */
/* @0x1aee40 adds r1, r1, #0 */
/* @0x1aee44 strb r0, [r3, #0x1] */
/* @0x1aee48 ldr r0, [r2, #0x8] */
/* @0x1aee4c vstr s16, [r3, #40] */
/* @0x1aee50 movne r1, #1 */
/* @0x1aee54 strb r1, [r3, #0x10] */
/* @0x1aee58 ldr r1, [r2, #0x24] */
/* @0x1aee5c adds r2, lr, #0 */
/* @0x1aee60 vcvt.f32.s32 s13, s13 */
/* @0x1aee64 vstr s12, [r3, #8] */
/* @0x1aee68 movne r2, #1 */
/* @0x1aee6c cmp r1, #0 */
/* @0x1aee70 str r0, [r3, #0x4] */
/* @0x1aee74 strb r2, [r3, #0x11] */
/* @0x1aee78 str r5, [r3, #0x24] */
/* @0x1aee7c vcvt.f32.s32 s14, s14 */
/* @0x1aee80 vstr s13, [r3, #12] */
/* @0x1aee84 vcvt.f32.s32 s15, s15 */
/* @0x1aee88 vstr s14, [r3, #20] */
/* @0x1aee8c vstr s15, [r3, #24] */
/* @0x1aee90 beq 0x1aeddc <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x3a0> */
/* @0x1aee94 bl 0xc3640 <_Z17Background_Existsi> */
/* @0x1aee98 cmp r0, #0 */
/* @0x1aee9c bne 0x1af124 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x6e8> */
/* @0x1aeea0 ldr r12, [r6] */
/* @0x1aeea4 add r11, r11, #1 */
/* @0x1aeea8 add r10, r10, #4 */
/* @0x1aeeac cmp r12, r11 */
/* @0x1aeeb0 bgt 0x1aedec <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x3b0> */
/* @0x1aeeb4 ldr r2, [r8, #0x2c] */
/* @0x1aeeb8 cmp r2, #0 */
/* @0x1aeebc moveq r9, r2 */
/* @0x1aeec0 moveq r10, #4 */
/* @0x1aeec4 beq 0x1aeedc <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x4a0> */
/* @0x1aeec8 ldr r3, [pc, #-0x100] */
/* @0x1aeecc ldr r3, [r7, r3] */
/* @0x1aeed0 ldr r3, [r3] */
/* @0x1aeed4 add r9, r3, r2 */
/* @0x1aeed8 add r10, r9, #4 */
/* @0x1aeedc ldr r12, [r9] */
/* @0x1aeee0 cmp r12, #0 */
/* @0x1aeee4 ble 0x1aeffc <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x5c0> */
/* @0x1aeee8 ldr r3, [pc, #-0x128] */
/* @0x1aeeec sub r10, r10, #4 */
/* @0x1aeef0 mov r5, r4 */
/* @0x1aeef4 mov r6, #0 */
/* @0x1aeef8 vldr s16, [pc, #-296] */
/* @0x1aeefc ldr r11, [r7, r3] */
/* @0x1aef00 str r4, [sp, #0x8] */
/* @0x1aef04 b 0x1aef14 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x4d8> */
/* @0x1aef08 cmp r12, r6 */
/* @0x1aef0c add r5, r5, #4 */
/* @0x1aef10 ble 0x1aeff8 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x5bc> */
/* @0x1aef14 ldr r3, [r10, #0x4]! */
/* @0x1aef18 add r6, r6, #1 */
/* @0x1aef1c ldr r2, [pc, #-0x154] */
/* @0x1aef20 cmp r3, #0 */
/* @0x1aef24 mov r1, r3 */
/* @0x1aef28 ldrne r2, [r7, r2] */
/* @0x1aef2c ldrne r1, [r2] */
/* @0x1aef30 addne r1, r1, r3 */
/* @0x1aef34 ldr r3, [r5, #0x48] */
/* @0x1aef38 vldr s13, [r1, #8] */
/* @0x1aef3c vldr s14, [r1, #12] */
/* @0x1aef40 ldr r2, [r1] */
/* @0x1aef44 vldr s15, [r1, #16] */
/* @0x1aef48 vldr s11, [r1, #4] */
/* @0x1aef4c ldr r0, [r1, #0x18] */
/* @0x1aef50 adds r2, r2, #0 */
/* @0x1aef54 vcvt.f32.s32 s12, s11 */
/* @0x1aef58 ldr lr, [r1, #0x20] */
/* @0x1aef5c movne r2, #1 */
/* @0x1aef60 strb r2, [r3] */
/* @0x1aef64 ldrb r2, [r11] */
/* @0x1aef68 cmp r2, #0 */
/* @0x1aef6c ldr r2, [r1, #0x14] */
/* @0x1aef70 vcvt.f32.s32 s13, s13 */
/* @0x1aef74 vstr s12, [r3, #4] */
/* @0x1aef78 str r2, [r3, #0x14] */
/* @0x1aef7c ldr r2, [r1, #0x1c] */
/* @0x1aef80 vstr s16, [r3, #36] */
/* @0x1aef84 str r0, [r3, #0x18] */
/* @0x1aef88 ldr r0, [r1, #0x24] */
/* @0x1aef8c str r2, [r3, #0x1c] */
/* @0x1aef90 ldr r2, [r1, #0x28] */
/* @0x1aef94 vcvt.f32.s32 s14, s14 */
/* @0x1aef98 str lr, [r3, #0x20] */
/* @0x1aef9c ldr lr, [r1, #0x2c] */
/* @0x1aefa0 vstr s13, [r3, #8] */
/* @0x1aefa4 str r0, [r3, #0x28] */
/* @0x1aefa8 ldr r0, [r1, #0x30] */
/* @0x1aefac str r2, [r3, #0x2c] */
/* @0x1aefb0 ldr r2, [r1, #0x34] */
/* @0x1aefb4 str lr, [r3, #0x30] */
/* @0x1aefb8 vcvt.f32.s32 s15, s15 */
/* @0x1aefbc vstr s14, [r3, #12] */
/* @0x1aefc0 str r0, [r3, #0x34] */
/* @0x1aefc4 vstr s15, [r3, #16] */
/* @0x1aefc8 str r2, [r3, #0x38] */
/* @0x1aefcc beq 0x1aef08 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x4cc> */
/* @0x1aefd0 ldr r3, [pc, #-0x21c] */
/* @0x1aefd4 add r5, r5, #4 */
/* @0x1aefd8 ldr r0, [r7, r3] */
/* @0x1aefdc bl 0x16f108 <_ZN14CCameraManager20CreateCameraFromViewEP10YYRoomView> */
/* @0x1aefe0 ldr r4, [r5, #0x44] */
/* @0x1aefe4 bl 0x16d12c <_ZN7CCamera5GetIDEv> */
/* @0x1aefe8 ldr r12, [r9] */
/* @0x1aefec cmp r12, r6 */
/* @0x1aeff0 str r0, [r4, #0x40] */
/* @0x1aeff4 bgt 0x1aef14 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x4d8> */
/* @0x1aeff8 ldr r4, [sp, #0x8] */
/* @0x1aeffc ldr r11, [r8, #0x30] */
/* @0x1af000 cmp r11, #0 */
/* @0x1af004 ldrne r3, [pc, #-0x23c] */
/* @0x1af008 ldrne r3, [r7, r3] */
/* @0x1af00c ldrne r3, [r3] */
/* @0x1af010 addne r11, r3, r11 */
/* @0x1af014 ldr r3, [r11] */
/* @0x1af018 cmp r3, #0 */
/* @0x1af01c bne 0x1af1f8 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x7bc> */
/* @0x1af020 str r3, [r8, #0x30] */
/* @0x1af024 str r3, [r4, #0xc8] */
/* @0x1af028 ldr r5, [r8, #0x34] */
/* @0x1af02c cmp r5, #0 */
/* @0x1af030 ldrne r3, [pc, #-0x268] */
/* @0x1af034 ldrne r3, [r7, r3] */
/* @0x1af038 ldrne r12, [r3] */
/* @0x1af03c addne r5, r12, r5 */
/* @0x1af040 ldr r12, [r5] */
/* @0x1af044 movw r2, #0x337 */
/* @0x1af048 ldr r1, [pc, #-0x290] */
/* @0x1af04c mov r3, #1 */
/* @0x1af050 lsl r0, r12, #2 */
/* @0x1af054 str r12, [r4, #0xb8] */
/* @0x1af058 add r1, pc, r1 */
/* @0x1af05c add r0, r0, #4 */
/* @0x1af060 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1af064 ldr r3, [r5] */
/* @0x1af068 str r3, [r0] */
/* @0x1af06c ldr r6, [r5] */
/* @0x1af070 cmp r6, #0 */
/* @0x1af074 addgt r6, r0, r6, lsl #2 */
/* @0x1af078 movgt r12, r5 */
/* @0x1af07c movgt r2, r0 */
/* @0x1af080 ble 0x1af0ac <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x670> */
/* @0x1af084 ldr r3, [r12, #0x4]! */
/* @0x1af088 ldr r5, [pc, #-0x2c0] */
/* @0x1af08c cmp r3, #0 */
/* @0x1af090 mov r1, r3 */
/* @0x1af094 ldrne r1, [r7, r5] */
/* @0x1af098 ldrne r1, [r1] */
/* @0x1af09c addne r1, r1, r3 */
/* @0x1af0a0 str r1, [r2, #0x4]! */
/* @0x1af0a4 cmp r2, r6 */
/* @0x1af0a8 bne 0x1af084 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x648> */
/* @0x1af0ac ldr r3, [sp, #0xc] */
/* @0x1af0b0 str r0, [r4, #0xc4] */
/* @0x1af0b4 cmp r3, #1 */
/* @0x1af0b8 ble 0x1af0d0 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x694> */
/* @0x1af0bc ldr r1, [r8, #0x58] */
/* @0x1af0c0 cmp r1, #0 */
/* @0x1af0c4 bne 0x1af190 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x754> */
/* @0x1af0c8 mov r0, r4 */
/* @0x1af0cc bl 0x1c6070 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers> */
/* @0x1af0d0 mov r0, #1 */
/* @0x1af0d4 add sp, sp, #20 */
/* @0x1af0d8 vpop {d8} */
/* @0x1af0dc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1af0e0 ldr r0, [pc, #-0x324] */
/* @0x1af0e4 add r0, pc, r0 */
/* @0x1af0e8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1af0ec ldr r3, [r8, #0x20] */
/* @0x1af0f0 cmn r3, #1 */
/* @0x1af0f4 moveq r3, #0 */
/* @0x1af0f8 streq r3, [r4, #0x6c] */
/* @0x1af0fc str r0, [r4, #0x68] */
/* @0x1af100 beq 0x1aecd4 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x298> */
/* @0x1af104 mov r0, #124 */
/* @0x1af108 bl 0x27c524 <_Znwj> */
/* @0x1af10c ldr r1, [r8, #0x20] */
/* @0x1af110 mov r2, #0 */
/* @0x1af114 mov r5, r0 */
/* @0x1af118 bl 0xcefc8 <_ZN5CCodeC2Eib> */
/* @0x1af11c str r5, [r4, #0x6c] */
/* @0x1af120 b 0x1aecd4 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x298> */
/* @0x1af124 ldr r3, [r10, #0x24] */
/* @0x1af128 ldr r0, [r3, #0x4] */
/* @0x1af12c bl 0xc3794 <_Z15Background_Datai> */
/* @0x1af130 bl 0xc2d78 <_ZN11CBackground8GetWidthEv> */
/* @0x1af134 ldr r3, [r10, #0x24] */
/* @0x1af138 vmov s11, r0 */
/* @0x1af13c vcvt.f32.s32 s15, s11 */
/* @0x1af140 vcmpe.f32 s15, #0 */
/* @0x1af144 vmrs APSR_nzcv, fpscr */
/* @0x1af148 vldrgt s13, [r4, #16] */
/* @0x1af14c vcvtgt.f32.s32 s14, s13 */
/* @0x1af150 vdivgt.f32 s15, s14, s15 */
/* @0x1af154 vstrgt s15, [r3, #28] */
/* @0x1af158 ldr r0, [r3, #0x4] */
/* @0x1af15c bl 0xc3794 <_Z15Background_Datai> */
/* @0x1af160 bl 0xc2d80 <_ZN11CBackground9GetHeightEv> */
/* @0x1af164 ldr r12, [r6] */
/* @0x1af168 vmov s14, r0 */
/* @0x1af16c vcvt.f32.s32 s15, s14 */
/* @0x1af170 vcmpe.f32 s15, #0 */
/* @0x1af174 vmrs APSR_nzcv, fpscr */
/* @0x1af178 vldrgt s11, [r4, #20] */
/* @0x1af17c vcvtgt.f32.s32 s14, s11 */
/* @0x1af180 ldrgt r3, [r10, #0x24] */
/* @0x1af184 vdivgt.f32 s15, s14, s15 */
/* @0x1af188 vstrgt s15, [r3, #32] */
/* @0x1af18c b 0x1aeddc <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x3a0> */
/* @0x1af190 ldr r3, [pc, #-0x3c8] */
/* @0x1af194 ldr r3, [r7, r3] */
/* @0x1af198 ldr r3, [r3] */
/* @0x1af19c add r1, r3, r1 */
/* @0x1af1a0 b 0x1af0c8 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x68c> */
/* @0x1af1a4 ldr r3, [pc, #-0x3e4] */
/* @0x1af1a8 mov r0, #488 */
/* @0x1af1ac ldr r11, [r7, r3] */
/* @0x1af1b0 ldrb r3, [r11] */
/* @0x1af1b4 cmp r3, r1 */
/* @0x1af1b8 bne 0x1af294 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x858> */
/* @0x1af1bc bl 0x27c524 <_Znwj> */
/* @0x1af1c0 ldr r1, [r4, #0x7c] */
/* @0x1af1c4 ldr r2, [r4, #0xc] */
/* @0x1af1c8 mov r5, r0 */
/* @0x1af1cc bl 0x237ca0 <_ZN13CPhysicsWorldC2Efi> */
/* @0x1af1d0 vldr s14, [r4, #116] */
/* @0x1af1d4 vldr s15, [r4, #120] */
/* @0x1af1d8 vcvt.f32.s32 s14, s14 */
/* @0x1af1dc mov r0, r5 */
/* @0x1af1e0 vcvt.f32.s32 s15, s15 */
/* @0x1af1e4 vmov r1, s14 */
/* @0x1af1e8 vmov r2, s15 */
/* @0x1af1ec bl 0x238c14 <_ZN13CPhysicsWorld10SetGravityEff> */
/* @0x1af1f0 str r5, [r4, #0xb4] */
/* @0x1af1f4 b 0x1aed50 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x314> */
/* @0x1af1f8 ldr r1, [pc, #-0x434] */
/* @0x1af1fc lsl r0, r3, #2 */
/* @0x1af200 add r0, r0, #4 */
/* @0x1af204 mov r3, #1 */
/* @0x1af208 add r1, pc, r1 */
/* @0x1af20c movw r2, #0x325 */
/* @0x1af210 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1af214 ldr r3, [r11] */
/* @0x1af218 str r3, [r0] */
/* @0x1af21c ldr r3, [r11] */
/* @0x1af220 str r0, [sp, #0x4] */
/* @0x1af224 cmp r3, #0 */
/* @0x1af228 ble 0x1af288 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x84c> */
/* @0x1af22c ldr r10, [sp, #0x4] */
/* @0x1af230 mov r9, r11 */
/* @0x1af234 mov r6, #0 */
/* @0x1af238 ldr r3, [r9, #0x4]! */
/* @0x1af23c mov r1, #0 */
/* @0x1af240 ldr r2, [pc, #-0x478] */
/* @0x1af244 add r6, r6, #1 */
/* @0x1af248 cmp r3, #0 */
/* @0x1af24c mov r5, r3 */
/* @0x1af250 ldrne r2, [r7, r2] */
/* @0x1af254 ldrne r5, [r2] */
/* @0x1af258 addne r5, r5, r3 */
/* @0x1af25c str r5, [r10, #0x4]! */
/* @0x1af260 ldr r0, [r5, #0x10] */
/* @0x1af264 bl 0xcf324 <_Z16Code_CreateEntryjb> */
/* @0x1af268 mov r1, #0 */
/* @0x1af26c str r0, [r5, #0x10] */
/* @0x1af270 ldr r0, [r5, #0x24] */
/* @0x1af274 bl 0xcf324 <_Z16Code_CreateEntryjb> */
/* @0x1af278 ldr r3, [r11] */
/* @0x1af27c cmp r3, r6 */
/* @0x1af280 str r0, [r5, #0x24] */
/* @0x1af284 bgt 0x1af238 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x7fc> */
/* @0x1af288 ldr r2, [sp, #0x4] */
/* @0x1af28c str r2, [r4, #0xc8] */
/* @0x1af290 b 0x1af028 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x5ec> */
/* @0x1af294 bl 0x27c524 <_Znwj> */
/* @0x1af298 ldr r3, [pc, #-0x4cc] */
/* @0x1af29c ldr r1, [r4, #0x7c] */
/* @0x1af2a0 ldr r3, [r7, r3] */
/* @0x1af2a4 vldr d7, [r3] */
/* @0x1af2a8 vcvt.s32.f64 s13, d7 */
/* @0x1af2ac vmov r2, s13 */
/* @0x1af2b0 mov r5, r0 */
/* @0x1af2b4 bl 0x237ca0 <_ZN13CPhysicsWorldC2Efi> */
/* @0x1af2b8 b 0x1af1d0 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x794> */

/* ── FUNC 0x1af2bc · CRoom::FindTile(int) · size=160 · insn=40 */
/* @0x1af2bc ldr r3, [r0] */
/* @0x1af2c0 str r4, [sp, #-0x4]! */
/* @0x1af2c4 cmp r3, #0 */
/* @0x1af2c8 ldr r4, [r0, #0xb8] */
/* @0x1af2cc blt 0x1af2d8 <_ZN5CRoom8FindTileEi+0x1c> */
/* @0x1af2d0 cmp r3, r4 */
/* @0x1af2d4 blt 0x1af324 <_ZN5CRoom8FindTileEi+0x68> */
/* @0x1af2d8 cmp r4, #0 */
/* @0x1af2dc ble 0x1af314 <_ZN5CRoom8FindTileEi+0x58> */
/* @0x1af2e0 ldr r2, [r0, #0xc0] */
/* @0x1af2e4 ldr r3, [r2, #0x20] */
/* @0x1af2e8 cmp r1, r3 */
/* @0x1af2ec movne r3, #0 */
/* @0x1af2f0 bne 0x1af304 <_ZN5CRoom8FindTileEi+0x48> */
/* @0x1af2f4 b 0x1af348 <_ZN5CRoom8FindTileEi+0x8c> */
/* @0x1af2f8 ldr r12, [r2, #0x20] */
/* @0x1af2fc cmp r1, r12 */
/* @0x1af300 beq 0x1af34c <_ZN5CRoom8FindTileEi+0x90> */
/* @0x1af304 add r3, r3, #1 */
/* @0x1af308 add r2, r2, #56 */
/* @0x1af30c cmp r3, r4 */
/* @0x1af310 bne 0x1af2f8 <_ZN5CRoom8FindTileEi+0x3c> */
/* @0x1af314 mvn r3, #0 */
/* @0x1af318 ldr r4, [sp], #4 */
/* @0x1af31c mov r0, r3 */
/* @0x1af320 bx lr */
/* @0x1af324 ldr r2, [r0, #0xc0] */
/* @0x1af328 rsb r12, r3, r3, lsl #3 */
/* @0x1af32c add r2, r2, r12, lsl #3 */
/* @0x1af330 ldr r2, [r2, #0x20] */
/* @0x1af334 cmp r2, r1 */
/* @0x1af338 bne 0x1af2d8 <_ZN5CRoom8FindTileEi+0x1c> */
/* @0x1af33c mov r0, r3 */
/* @0x1af340 ldr r4, [sp], #4 */
/* @0x1af344 bx lr */
/* @0x1af348 mov r3, #0 */
/* @0x1af34c str r3, [r0] */
/* @0x1af350 mov r0, r3 */
/* @0x1af354 ldr r4, [sp], #4 */
/* @0x1af358 bx lr */

/* ── FUNC 0x1af35c · CRoom::DeleteTile(int) · size=152 · insn=38 */
/* @0x1af35c push {r4, r5, r6, r7, r8, lr} */
/* @0x1af360 subs r6, r1, #0 */
/* @0x1af364 mov r8, r0 */
/* @0x1af368 poplt {r4, r5, r6, r7, r8, pc} */
/* @0x1af36c ldr r7, [r0, #0xb8] */
/* @0x1af370 cmp r6, r7 */
/* @0x1af374 popge {r4, r5, r6, r7, r8, pc} */
/* @0x1af378 sub r7, r7, #1 */
/* @0x1af37c cmp r6, r7 */
/* @0x1af380 bge 0x1af3c8 <_ZN5CRoom10DeleteTileEi+0x6c> */
/* @0x1af384 rsb r5, r6, r6, lsl #3 */
/* @0x1af388 ldr r3, [r0, #0xc0] */
/* @0x1af38c add r5, r3, r5, lsl #3 */
/* @0x1af390 add r4, r5, #56 */
/* @0x1af394 mov r12, r5 */
/* @0x1af398 add r6, r6, #1 */
/* @0x1af39c mov r5, r4 */
/* @0x1af3a0 cmp r6, r7 */
/* @0x1af3a4 ldm r4!, {r0, r1, r2, r3} */
/* @0x1af3a8 stm r12!, {r0, r1, r2, r3} */
/* @0x1af3ac ldm r4!, {r0, r1, r2, r3} */
/* @0x1af3b0 stm r12!, {r0, r1, r2, r3} */
/* @0x1af3b4 ldm r4!, {r0, r1, r2, r3} */
/* @0x1af3b8 stm r12!, {r0, r1, r2, r3} */
/* @0x1af3bc ldm r4, {r0, r1} */
/* @0x1af3c0 stm r12, {r0, r1} */
/* @0x1af3c4 bne 0x1af390 <_ZN5CRoom10DeleteTileEi+0x34> */
/* @0x1af3c8 cmp r7, #0 */
/* @0x1af3cc str r7, [r8, #0xb8] */
/* @0x1af3d0 popne {r4, r5, r6, r7, r8, pc} */
/* @0x1af3d4 ldr r0, [r8, #0xc0] */
/* @0x1af3d8 cmp r0, #0 */
/* @0x1af3dc moveq r0, r7 */
/* @0x1af3e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1af3e4 mov r3, #0 */
/* @0x1af3e8 str r7, [r8, #0xc0] */
/* @0x1af3ec str r3, [r8, #0xbc] */
/* @0x1af3f0 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x1af3f4 · CRoom::SortTiles() · size=400 · insn=100 */
/* @0x1af3f4 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x1af3f8 sub sp, sp, #80 */
/* @0x1af3fc ldr r7, [r0, #0xb8] */
/* @0x1af400 mov r2, #56 */
/* @0x1af404 mov r3, #0 */
/* @0x1af408 sub r4, r7, #1 */
/* @0x1af40c str r7, [sp, #0x14] */
/* @0x1af410 b 0x1af434 <_ZN5CRoom9SortTilesEv+0x40> */
/* @0x1af414 ldr r12, [r0, #0xc0] */
/* @0x1af418 add r1, r12, r2 */
/* @0x1af41c vldr s14, [r1, #28] */
/* @0x1af420 vldr s15, [r1, #-28] */
/* @0x1af424 vcmpe.f32 s14, s15 */
/* @0x1af428 add r2, r2, #56 */
/* @0x1af42c vmrs APSR_nzcv, fpscr */
/* @0x1af430 bgt 0x1af44c <_ZN5CRoom9SortTilesEv+0x58> */
/* @0x1af434 cmp r3, r4 */
/* @0x1af438 add r3, r3, #1 */
/* @0x1af43c blt 0x1af414 <_ZN5CRoom9SortTilesEv+0x20> */
/* @0x1af440 add sp, sp, #80 */
/* @0x1af444 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x1af448 bx lr */
/* @0x1af44c ldr r7, [sp, #0x14] */
/* @0x1af450 cmp r7, #1 */
/* @0x1af454 ble 0x1af440 <_ZN5CRoom9SortTilesEv+0x4c> */
/* @0x1af458 mov r7, #1 */
/* @0x1af45c add r12, r12, #56 */
/* @0x1af460 str r7, [sp, #0x10] */
/* @0x1af464 add r7, sp, #24 */
/* @0x1af468 str r12, [sp, #0xc] */
/* @0x1af46c str r7, [sp, #0x8] */
/* @0x1af470 ldr r7, [sp, #0xc] */
/* @0x1af474 vldr s14, [r7, #28] */
/* @0x1af478 vldr s15, [r7, #-28] */
/* @0x1af47c vcmpe.f32 s14, s15 */
/* @0x1af480 mov r9, r7 */
/* @0x1af484 ldr r7, [sp, #0x10] */
/* @0x1af488 sub r11, r9, #56 */
/* @0x1af48c sub r7, r7, #1 */
/* @0x1af490 vmrs APSR_nzcv, fpscr */
/* @0x1af494 str r7, [sp, #0x4] */
/* @0x1af498 ble 0x1af550 <_ZN5CRoom9SortTilesEv+0x15c> */
/* @0x1af49c mov r10, r9 */
/* @0x1af4a0 b 0x1af4bc <_ZN5CRoom9SortTilesEv+0xc8> */
/* @0x1af4a4 vldr s14, [r10, #-28] */
/* @0x1af4a8 vldr s15, [r9, #-28] */
/* @0x1af4ac vcmpe.f32 s14, s15 */
/* @0x1af4b0 mov r10, r9 */
/* @0x1af4b4 vmrs APSR_nzcv, fpscr */
/* @0x1af4b8 ble 0x1af550 <_ZN5CRoom9SortTilesEv+0x15c> */
/* @0x1af4bc mov r5, r9 */
/* @0x1af4c0 add r4, sp, #24 */
/* @0x1af4c4 ldm r5!, {r0, r1, r2, r3} */
/* @0x1af4c8 mov r12, r11 */
/* @0x1af4cc ldr r7, [sp, #0x4] */
/* @0x1af4d0 mov r8, r9 */
/* @0x1af4d4 mov r6, r11 */
/* @0x1af4d8 sub r9, r10, #56 */
/* @0x1af4dc cmp r7, #0 */
/* @0x1af4e0 sub r7, r7, #1 */
/* @0x1af4e4 stm r4!, {r0, r1, r2, r3} */
/* @0x1af4e8 sub r11, r10, #112 */
/* @0x1af4ec ldm r5!, {r0, r1, r2, r3} */
/* @0x1af4f0 str r7, [sp, #0x4] */
/* @0x1af4f4 add r7, sp, #24 */
/* @0x1af4f8 stm r4!, {r0, r1, r2, r3} */
/* @0x1af4fc ldm r5!, {r0, r1, r2, r3} */
/* @0x1af500 stm r4!, {r0, r1, r2, r3} */
/* @0x1af504 ldm r5, {r0, r1} */
/* @0x1af508 stm r4, {r0, r1} */
/* @0x1af50c ldm r12!, {r0, r1, r2, r3} */
/* @0x1af510 stm r8!, {r0, r1, r2, r3} */
/* @0x1af514 ldm r12!, {r0, r1, r2, r3} */
/* @0x1af518 stm r8!, {r0, r1, r2, r3} */
/* @0x1af51c ldm r12!, {r0, r1, r2, r3} */
/* @0x1af520 stm r8!, {r0, r1, r2, r3} */
/* @0x1af524 ldm r12, {r0, r1} */
/* @0x1af528 stm r5, {r0, r1} */
/* @0x1af52c ldm r7!, {r0, r1, r2, r3} */
/* @0x1af530 stm r6!, {r0, r1, r2, r3} */
/* @0x1af534 ldm r7!, {r0, r1, r2, r3} */
/* @0x1af538 stm r6!, {r0, r1, r2, r3} */
/* @0x1af53c ldm r7!, {r0, r1, r2, r3} */
/* @0x1af540 stm r6!, {r0, r1, r2, r3} */
/* @0x1af544 ldm r4, {r0, r1} */
/* @0x1af548 stm r12, {r0, r1} */
/* @0x1af54c bne 0x1af4a4 <_ZN5CRoom9SortTilesEv+0xb0> */
/* @0x1af550 ldr r7, [sp, #0x10] */
/* @0x1af554 ldr r1, [sp, #0x14] */
/* @0x1af558 add r7, r7, #1 */
/* @0x1af55c str r7, [sp, #0x10] */
/* @0x1af560 ldr r7, [sp, #0xc] */
/* @0x1af564 add r7, r7, #56 */
/* @0x1af568 str r7, [sp, #0xc] */
/* @0x1af56c ldr r7, [sp, #0x10] */
/* @0x1af570 cmp r7, r1 */
/* @0x1af574 bne 0x1af470 <_ZN5CRoom9SortTilesEv+0x7c> */
/* @0x1af578 add sp, sp, #80 */
/* @0x1af57c pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x1af580 bx lr */

/* ── FUNC 0x1af584 · CRoom::HideTilesDepth(float) · size=64 · insn=16 */
/* @0x1af584 ldr r2, [r0, #0xb8] */
/* @0x1af588 vmov s14, r1 */
/* @0x1af58c cmp r2, #0 */
/* @0x1af590 bxle lr */
/* @0x1af594 ldr r3, [r0, #0xc0] */
/* @0x1af598 rsb r2, r2, r2, lsl #3 */
/* @0x1af59c mov r1, #0 */
/* @0x1af5a0 add r2, r3, r2, lsl #3 */
/* @0x1af5a4 vldr s15, [r3, #28] */
/* @0x1af5a8 vcmp.f32 s15, s14 */
/* @0x1af5ac add r3, r3, #56 */
/* @0x1af5b0 vmrs APSR_nzcv, fpscr */
/* @0x1af5b4 strbeq r1, [r3, #-0x4] */
/* @0x1af5b8 cmp r3, r2 */
/* @0x1af5bc bne 0x1af5a4 <_ZN5CRoom14HideTilesDepthEf+0x20> */
/* @0x1af5c0 bx lr */

/* ── FUNC 0x1af5c4 · CRoom::ShowTilesDepth(float) · size=64 · insn=16 */
/* @0x1af5c4 ldr r2, [r0, #0xb8] */
/* @0x1af5c8 vmov s14, r1 */
/* @0x1af5cc cmp r2, #0 */
/* @0x1af5d0 bxle lr */
/* @0x1af5d4 ldr r3, [r0, #0xc0] */
/* @0x1af5d8 rsb r2, r2, r2, lsl #3 */
/* @0x1af5dc mov r1, #1 */
/* @0x1af5e0 add r2, r3, r2, lsl #3 */
/* @0x1af5e4 vldr s15, [r3, #28] */
/* @0x1af5e8 vcmp.f32 s15, s14 */
/* @0x1af5ec add r3, r3, #56 */
/* @0x1af5f0 vmrs APSR_nzcv, fpscr */
/* @0x1af5f4 strbeq r1, [r3, #-0x4] */
/* @0x1af5f8 cmp r3, r2 */
/* @0x1af5fc bne 0x1af5e4 <_ZN5CRoom14ShowTilesDepthEf+0x20> */
/* @0x1af600 bx lr */

/* ── FUNC 0x1af604 · CRoom::DeleteTilesDepth(float) · size=196 · insn=49 */
/* @0x1af604 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1af608 vmov s14, r1 */
/* @0x1af60c ldr r8, [r0, #0xb8] */
/* @0x1af610 mov r9, r0 */
/* @0x1af614 cmp r8, #0 */
/* @0x1af618 ble 0x1af6b8 <_ZN5CRoom16DeleteTilesDepthEf+0xb4> */
/* @0x1af61c ldr r7, [r0, #0xc0] */
/* @0x1af620 rsb r8, r8, r8, lsl #3 */
/* @0x1af624 mov r6, #0 */
/* @0x1af628 add r8, r7, r8, lsl #3 */
/* @0x1af62c add r5, r7, #28 */
/* @0x1af630 add r8, r8, #28 */
/* @0x1af634 vldr s15, [r5] */
/* @0x1af638 vcmp.f32 s15, s14 */
/* @0x1af63c rsb r12, r6, r6, lsl #3 */
/* @0x1af640 sub r4, r5, #28 */
/* @0x1af644 add r5, r5, #56 */
/* @0x1af648 add r12, r7, r12, lsl #3 */
/* @0x1af64c vmrs APSR_nzcv, fpscr */
/* @0x1af650 beq 0x1af678 <_ZN5CRoom16DeleteTilesDepthEf+0x74> */
/* @0x1af654 ldm r4!, {r0, r1, r2, r3} */
/* @0x1af658 add r6, r6, #1 */
/* @0x1af65c stm r12!, {r0, r1, r2, r3} */
/* @0x1af660 ldm r4!, {r0, r1, r2, r3} */
/* @0x1af664 stm r12!, {r0, r1, r2, r3} */
/* @0x1af668 ldm r4!, {r0, r1, r2, r3} */
/* @0x1af66c stm r12!, {r0, r1, r2, r3} */
/* @0x1af670 ldm r4, {r0, r1} */
/* @0x1af674 stm r12, {r0, r1} */
/* @0x1af678 cmp r5, r8 */
/* @0x1af67c bne 0x1af634 <_ZN5CRoom16DeleteTilesDepthEf+0x30> */
/* @0x1af680 cmp r6, #0 */
/* @0x1af684 str r6, [r9, #0xb8] */
/* @0x1af688 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1af68c subs r0, r7, #0 */
/* @0x1af690 beq 0x1af6ac <_ZN5CRoom16DeleteTilesDepthEf+0xa8> */
/* @0x1af694 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1af698 mov r3, #0 */
/* @0x1af69c str r3, [r9, #0xc0] */
/* @0x1af6a0 mov r3, #0 */
/* @0x1af6a4 str r3, [r9, #0xbc] */
/* @0x1af6a8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1af6ac bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1af6b0 str r7, [r9, #0xc0] */
/* @0x1af6b4 b 0x1af6a0 <_ZN5CRoom16DeleteTilesDepthEf+0x9c> */
/* @0x1af6b8 mov r3, #0 */
/* @0x1af6bc ldr r7, [r0, #0xc0] */
/* @0x1af6c0 str r3, [r0, #0xb8] */
/* @0x1af6c4 b 0x1af68c <_ZN5CRoom16DeleteTilesDepthEf+0x88> */

/* ── FUNC 0x1af6c8 · CRoom::ShiftTilesDepth(float, float, float) · size=100 · insn=25 */
/* @0x1af6c8 vmov s14, r1 */
/* @0x1af6cc ldr r1, [r0, #0xb8] */
/* @0x1af6d0 vmov s12, r2 */
/* @0x1af6d4 cmp r1, #0 */
/* @0x1af6d8 vmov s11, r3 */
/* @0x1af6dc bxle lr */
/* @0x1af6e0 ldr r3, [r0, #0xc0] */
/* @0x1af6e4 rsb r1, r1, r1, lsl #3 */
/* @0x1af6e8 add r2, r3, r1, lsl #3 */
/* @0x1af6ec add r3, r3, #28 */
/* @0x1af6f0 add r2, r2, #28 */
/* @0x1af6f4 vldr s15, [r3] */
/* @0x1af6f8 vcmp.f32 s15, s14 */
/* @0x1af6fc vmrs APSR_nzcv, fpscr */
/* @0x1af700 bne 0x1af71c <_ZN5CRoom15ShiftTilesDepthEfff+0x54> */
/* @0x1af704 vldr s13, [r3, #-28] */
/* @0x1af708 vldr s15, [r3, #-24] */
/* @0x1af70c vadd.f32 s13, s13, s12 */
/* @0x1af710 vadd.f32 s15, s15, s11 */
/* @0x1af714 vstr s13, [r3, #-28] */
/* @0x1af718 vstr s15, [r3, #-24] */
/* @0x1af71c add r3, r3, #56 */
/* @0x1af720 cmp r3, r2 */
/* @0x1af724 bne 0x1af6f4 <_ZN5CRoom15ShiftTilesDepthEfff+0x2c> */
/* @0x1af728 bx lr */

/* ── FUNC 0x1af72c · CRoom::FindTileAtDepth(float, float, float) · size=308 · insn=77 */
/* @0x1af72c vmov s11, r1 */
/* @0x1af730 ldr r1, [r0, #0xb8] */
/* @0x1af734 str r4, [sp, #-0x4]! */
/* @0x1af738 cmp r1, #0 */
/* @0x1af73c vmov s9, r2 */
/* @0x1af740 vmov s8, r3 */
/* @0x1af744 ble 0x1af854 <_ZN5CRoom15FindTileAtDepthEfff+0x128> */
/* @0x1af748 vmov.f32 s7, #5.000000e-01 */
/* @0x1af74c ldr r3, [r0, #0xc0] */
/* @0x1af750 mvn r12, #0 */
/* @0x1af754 mov r2, #0 */
/* @0x1af758 add r3, r3, #40 */
/* @0x1af75c vldr s6, [pc, #248] */
/* @0x1af760 vldr s15, [r3, #-12] */
/* @0x1af764 vcmp.f32 s15, s11 */
/* @0x1af768 vmrs APSR_nzcv, fpscr */
/* @0x1af76c bne 0x1af830 <_ZN5CRoom15FindTileAtDepthEfff+0x104> */
/* @0x1af770 vldr s5, [r3, #-20] */
/* @0x1af774 vcvt.f32.s32 s10, s5 */
/* @0x1af778 vldr s15, [r3, #-40] */
/* @0x1af77c vldr s13, [r3, #-4] */
/* @0x1af780 vldr s14, [r3, #-36] */
/* @0x1af784 vldr s12, [r3] */
/* @0x1af788 vmov.f32 s5, s15 */
/* @0x1af78c vmla.f32 s5, s10, s13 */
/* @0x1af790 vmov.f32 s13, s5 */
/* @0x1af794 vldr s5, [r3, #-16] */
/* @0x1af798 vcvt.f32.s32 s10, s5 */
/* @0x1af79c vmov.f32 s5, s14 */
/* @0x1af7a0 vmla.f32 s5, s10, s12 */
/* @0x1af7a4 vcmpe.f32 s15, s13 */
/* @0x1af7a8 vmrs APSR_nzcv, fpscr */
/* @0x1af7ac vcmpe.f32 s14, s5 */
/* @0x1af7b0 vmovle.f32 s10, s13 */
/* @0x1af7b4 vmovle.f32 s13, s15 */
/* @0x1af7b8 vmovle.f32 s15, s10 */
/* @0x1af7bc vmrs APSR_nzcv, fpscr */
/* @0x1af7c0 vcmpe.f32 s13, s9 */
/* @0x1af7c4 vmovle.f32 s10, s5 */
/* @0x1af7c8 vmov.f32 s12, s5 */
/* @0x1af7cc vmovle.f32 s12, s14 */
/* @0x1af7d0 vmovle.f32 s14, s10 */
/* @0x1af7d4 vmrs APSR_nzcv, fpscr */
/* @0x1af7d8 bhi 0x1af830 <_ZN5CRoom15FindTileAtDepthEfff+0x104> */
/* @0x1af7dc vcmpe.f32 s15, s9 */
/* @0x1af7e0 vmrs APSR_nzcv, fpscr */
/* @0x1af7e4 ble 0x1af830 <_ZN5CRoom15FindTileAtDepthEfff+0x104> */
/* @0x1af7e8 vcmpe.f32 s12, s8 */
/* @0x1af7ec vmrs APSR_nzcv, fpscr */
/* @0x1af7f0 bhi 0x1af830 <_ZN5CRoom15FindTileAtDepthEfff+0x104> */
/* @0x1af7f4 vcmpe.f32 s14, s8 */
/* @0x1af7f8 vmrs APSR_nzcv, fpscr */
/* @0x1af7fc ble 0x1af830 <_ZN5CRoom15FindTileAtDepthEfff+0x104> */
/* @0x1af800 vadd.f32 s14, s12, s14 */
/* @0x1af804 vmov.f32 s12, s8 */
/* @0x1af808 vnmls.f32 s12, s14, s7 */
/* @0x1af80c vadd.f32 s15, s13, s15 */
/* @0x1af810 vmov.f32 s14, s9 */
/* @0x1af814 vnmls.f32 s14, s15, s7 */
/* @0x1af818 vmul.f32 s15, s12, s12 */
/* @0x1af81c vmla.f32 s15, s14, s14 */
/* @0x1af820 vcmpe.f32 s15, s6 */
/* @0x1af824 vmrs APSR_nzcv, fpscr */
/* @0x1af828 vmovmi.f32 s6, s15 */
/* @0x1af82c movmi r12, r2 */
/* @0x1af830 add r2, r2, #1 */
/* @0x1af834 add r3, r3, #56 */
/* @0x1af838 cmp r2, r1 */
/* @0x1af83c bne 0x1af760 <_ZN5CRoom15FindTileAtDepthEfff+0x34> */
/* @0x1af840 cmn r12, #1 */
/* @0x1af844 strne r2, [r0] */
/* @0x1af848 mov r0, r12 */
/* @0x1af84c ldr r4, [sp], #4 */
/* @0x1af850 bx lr */
/* @0x1af854 mvn r12, #0 */
/* @0x1af858 b 0x1af848 <_ZN5CRoom15FindTileAtDepthEfff+0x11c> */
/* @0x1af85c svcvc #0x7fffff */

/* ── FUNC 0x1af860 · CRoom::DeleteTilesAtDepth(float, float, float) · size=348 · insn=87 */
/* @0x1af860 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1af864 vmov s11, r1 */
/* @0x1af868 ldr r8, [r0, #0xb8] */
/* @0x1af86c mov r9, r0 */
/* @0x1af870 vmov s9, r2 */
/* @0x1af874 cmp r8, #0 */
/* @0x1af878 vmov s8, r3 */
/* @0x1af87c ble 0x1af9ac <_ZN5CRoom18DeleteTilesAtDepthEfff+0x14c> */
/* @0x1af880 ldr r7, [r0, #0xc0] */
/* @0x1af884 rsb r8, r8, r8, lsl #3 */
/* @0x1af888 mov r6, #0 */
/* @0x1af88c add r8, r7, r8, lsl #3 */
/* @0x1af890 add r5, r7, #40 */
/* @0x1af894 add r8, r8, #40 */
/* @0x1af898 vldr s15, [r5, #-12] */
/* @0x1af89c vcmp.f32 s15, s11 */
/* @0x1af8a0 vmrs APSR_nzcv, fpscr */
/* @0x1af8a4 bne 0x1af938 <_ZN5CRoom18DeleteTilesAtDepthEfff+0xd8> */
/* @0x1af8a8 vldr s7, [r5, #-20] */
/* @0x1af8ac vcvt.f32.s32 s10, s7 */
/* @0x1af8b0 vldr s15, [r5, #-40] */
/* @0x1af8b4 vldr s13, [r5, #-4] */
/* @0x1af8b8 vldr s14, [r5, #-36] */
/* @0x1af8bc vldr s12, [r5] */
/* @0x1af8c0 vmov.f32 s7, s15 */
/* @0x1af8c4 vmla.f32 s7, s10, s13 */
/* @0x1af8c8 vmov.f32 s13, s7 */
/* @0x1af8cc vldr s7, [r5, #-16] */
/* @0x1af8d0 vcvt.f32.s32 s10, s7 */
/* @0x1af8d4 vmov.f32 s7, s14 */
/* @0x1af8d8 vmla.f32 s7, s10, s12 */
/* @0x1af8dc vcmpe.f32 s15, s13 */
/* @0x1af8e0 vmrs APSR_nzcv, fpscr */
/* @0x1af8e4 vcmpe.f32 s14, s7 */
/* @0x1af8e8 vmovle.f32 s10, s13 */
/* @0x1af8ec vmovle.f32 s13, s15 */
/* @0x1af8f0 vmovle.f32 s15, s10 */
/* @0x1af8f4 vmrs APSR_nzcv, fpscr */
/* @0x1af8f8 vcmpe.f32 s13, s9 */
/* @0x1af8fc vmovle.f32 s10, s7 */
/* @0x1af900 vmov.f32 s12, s7 */
/* @0x1af904 vmovle.f32 s12, s14 */
/* @0x1af908 vmovle.f32 s14, s10 */
/* @0x1af90c vmrs APSR_nzcv, fpscr */
/* @0x1af910 bgt 0x1af938 <_ZN5CRoom18DeleteTilesAtDepthEfff+0xd8> */
/* @0x1af914 vcmpe.f32 s15, s9 */
/* @0x1af918 vmrs APSR_nzcv, fpscr */
/* @0x1af91c bls 0x1af938 <_ZN5CRoom18DeleteTilesAtDepthEfff+0xd8> */
/* @0x1af920 vcmpe.f32 s12, s8 */
/* @0x1af924 vmrs APSR_nzcv, fpscr */
/* @0x1af928 bgt 0x1af938 <_ZN5CRoom18DeleteTilesAtDepthEfff+0xd8> */
/* @0x1af92c vcmpe.f32 s14, s8 */
/* @0x1af930 vmrs APSR_nzcv, fpscr */
/* @0x1af934 bhi 0x1af968 <_ZN5CRoom18DeleteTilesAtDepthEfff+0x108> */
/* @0x1af938 sub r4, r5, #40 */
/* @0x1af93c rsb r12, r6, r6, lsl #3 */
/* @0x1af940 add r6, r6, #1 */
/* @0x1af944 ldm r4!, {r0, r1, r2, r3} */
/* @0x1af948 add r12, r7, r12, lsl #3 */
/* @0x1af94c stm r12!, {r0, r1, r2, r3} */
/* @0x1af950 ldm r4!, {r0, r1, r2, r3} */
/* @0x1af954 stm r12!, {r0, r1, r2, r3} */
/* @0x1af958 ldm r4!, {r0, r1, r2, r3} */
/* @0x1af95c stm r12!, {r0, r1, r2, r3} */
/* @0x1af960 ldm r4, {r0, r1} */
/* @0x1af964 stm r12, {r0, r1} */
/* @0x1af968 add r5, r5, #56 */
/* @0x1af96c cmp r5, r8 */
/* @0x1af970 bne 0x1af898 <_ZN5CRoom18DeleteTilesAtDepthEfff+0x38> */
/* @0x1af974 cmp r6, #0 */
/* @0x1af978 str r6, [r9, #0xb8] */
/* @0x1af97c popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1af980 subs r0, r7, #0 */
/* @0x1af984 beq 0x1af9a0 <_ZN5CRoom18DeleteTilesAtDepthEfff+0x140> */
/* @0x1af988 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1af98c mov r3, #0 */
/* @0x1af990 str r3, [r9, #0xc0] */
/* @0x1af994 mov r3, #0 */
/* @0x1af998 str r3, [r9, #0xbc] */
/* @0x1af99c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1af9a0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1af9a4 str r7, [r9, #0xc0] */
/* @0x1af9a8 b 0x1af994 <_ZN5CRoom18DeleteTilesAtDepthEfff+0x134> */
/* @0x1af9ac mov r3, #0 */
/* @0x1af9b0 ldr r7, [r0, #0xc0] */
/* @0x1af9b4 str r3, [r0, #0xb8] */
/* @0x1af9b8 b 0x1af980 <_ZN5CRoom18DeleteTilesAtDepthEfff+0x120> */

/* ── FUNC 0x1af9bc · CRoom::ChangeTilesDepth(float, float) · size=68 · insn=17 */
/* @0x1af9bc ldr r12, [r0, #0xb8] */
/* @0x1af9c0 vmov s14, r1 */
/* @0x1af9c4 cmp r12, #0 */
/* @0x1af9c8 bxle lr */
/* @0x1af9cc ldr r3, [r0, #0xc0] */
/* @0x1af9d0 rsb r12, r12, r12, lsl #3 */
/* @0x1af9d4 add r1, r3, r12, lsl #3 */
/* @0x1af9d8 add r3, r3, #28 */
/* @0x1af9dc add r1, r1, #28 */
/* @0x1af9e0 vldr s15, [r3] */
/* @0x1af9e4 vcmp.f32 s15, s14 */
/* @0x1af9e8 add r3, r3, #56 */
/* @0x1af9ec vmrs APSR_nzcv, fpscr */
/* @0x1af9f0 streq r2, [r3, #-0x38] */
/* @0x1af9f4 cmp r3, r1 */
/* @0x1af9f8 bne 0x1af9e0 <_ZN5CRoom16ChangeTilesDepthEff+0x24> */
/* @0x1af9fc bx lr */

/* ── FUNC 0x1afa00 · CRoom::~CRoom() · size=1264 · insn=316 */
/* @0x1afa00 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1afa04 mov r4, r0 */
/* @0x1afa08 ldr r3, [pc, #0x4d8] */
/* @0x1afa0c ldr r7, [pc, #0x4d8] */
/* @0x1afa10 ldr r3, [pc, r3] */
/* @0x1afa14 ldr r7, [pc, r7] */
/* @0x1afa18 ldrb r3, [r3] */
/* @0x1afa1c ldr r8, [r7] */
/* @0x1afa20 cmp r3, #0 */
/* @0x1afa24 str r0, [r7] */
/* @0x1afa28 beq 0x1afa78 <_ZN5CRoomD2Ev+0x78> */
/* @0x1afa2c ldr r0, [r0, #0x80] */
/* @0x1afa30 cmp r0, #0 */
/* @0x1afa34 beq 0x1afa78 <_ZN5CRoomD2Ev+0x78> */
/* @0x1afa38 ldrb r3, [r0, #0x68] */
/* @0x1afa3c ldr r5, [r0, #0x178] */
/* @0x1afa40 cmp r3, #0 */
/* @0x1afa44 bne 0x1afa6c <_ZN5CRoomD2Ev+0x6c> */
/* @0x1afa48 ldrb r3, [r0, #0x69] */
/* @0x1afa4c cmp r3, #0 */
/* @0x1afa50 bne 0x1afa6c <_ZN5CRoomD2Ev+0x6c> */
/* @0x1afa54 ldrb r3, [r0, #0x67] */
/* @0x1afa58 mov r1, r0 */
/* @0x1afa5c mov r2, #12 */
/* @0x1afa60 cmp r3, #0 */
/* @0x1afa64 bne 0x1afa6c <_ZN5CRoomD2Ev+0x6c> */
/* @0x1afa68 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1afa6c cmp r5, #0 */
/* @0x1afa70 mov r0, r5 */
/* @0x1afa74 bne 0x1afa38 <_ZN5CRoomD2Ev+0x38> */
/* @0x1afa78 ldrb r3, [r4, #0xd0] */
/* @0x1afa7c cmp r3, #0 */
/* @0x1afa80 beq 0x1afac8 <_ZN5CRoomD2Ev+0xc8> */
/* @0x1afa84 ldr r3, [r4, #0xac] */
/* @0x1afa88 cmp r3, #0 */
/* @0x1afa8c beq 0x1afac8 <_ZN5CRoomD2Ev+0xc8> */
/* @0x1afa90 ldr r0, [r4, #0xc8] */
/* @0x1afa94 cmp r0, #0 */
/* @0x1afa98 beq 0x1afaa8 <_ZN5CRoomD2Ev+0xa8> */
/* @0x1afa9c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afaa0 mov r3, #0 */
/* @0x1afaa4 str r3, [r4, #0xc8] */
/* @0x1afaa8 ldr r0, [r4, #0xc4] */
/* @0x1afaac cmp r0, #0 */
/* @0x1afab0 beq 0x1afac0 <_ZN5CRoomD2Ev+0xc0> */
/* @0x1afab4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afab8 mov r3, #0 */
/* @0x1afabc str r3, [r4, #0xc4] */
/* @0x1afac0 mov r3, #0 */
/* @0x1afac4 str r3, [r4, #0xac] */
/* @0x1afac8 ldr r0, [r4, #0x8] */
/* @0x1afacc cmp r0, #0 */
/* @0x1afad0 beq 0x1afae0 <_ZN5CRoomD2Ev+0xe0> */
/* @0x1afad4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afad8 mov r3, #0 */
/* @0x1afadc str r3, [r4, #0x8] */
/* @0x1afae0 ldr r0, [r4, #0x68] */
/* @0x1afae4 cmp r0, #0 */
/* @0x1afae8 beq 0x1afaf8 <_ZN5CRoomD2Ev+0xf8> */
/* @0x1afaec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afaf0 mov r3, #0 */
/* @0x1afaf4 str r3, [r4, #0x68] */
/* @0x1afaf8 mov r0, r4 */
/* @0x1afafc mov r5, r4 */
/* @0x1afb00 bl 0x1ad0a4 <_ZN5CRoom5ClearEv> */
/* @0x1afb04 mov r6, #8 */
/* @0x1afb08 mov r9, #0 */
/* @0x1afb0c ldr r0, [r5, #0x24] */
/* @0x1afb10 cmp r0, #0 */
/* @0x1afb14 beq 0x1afb20 <_ZN5CRoomD2Ev+0x120> */
/* @0x1afb18 bl 0x27d1d0 <_ZdlPv> */
/* @0x1afb1c str r9, [r5, #0x24] */
/* @0x1afb20 subs r6, r6, #1 */
/* @0x1afb24 add r5, r5, #4 */
/* @0x1afb28 bne 0x1afb0c <_ZN5CRoomD2Ev+0x10c> */
/* @0x1afb2c mov r5, r4 */
/* @0x1afb30 mov r9, r6 */
/* @0x1afb34 ldr r0, [r5, #0x48] */
/* @0x1afb38 add r6, r6, #1 */
/* @0x1afb3c cmp r0, #0 */
/* @0x1afb40 beq 0x1afb4c <_ZN5CRoomD2Ev+0x14c> */
/* @0x1afb44 bl 0x27d1d0 <_ZdlPv> */
/* @0x1afb48 str r9, [r5, #0x48] */
/* @0x1afb4c cmp r6, #8 */
/* @0x1afb50 add r5, r5, #4 */
/* @0x1afb54 bne 0x1afb34 <_ZN5CRoomD2Ev+0x134> */
/* @0x1afb58 ldr r5, [r4, #0xb4] */
/* @0x1afb5c cmp r5, #0 */
/* @0x1afb60 beq 0x1afb7c <_ZN5CRoomD2Ev+0x17c> */
/* @0x1afb64 mov r0, r5 */
/* @0x1afb68 bl 0x239e68 <_ZN13CPhysicsWorldD2Ev> */
/* @0x1afb6c mov r0, r5 */
/* @0x1afb70 bl 0x27d1d0 <_ZdlPv> */
/* @0x1afb74 mov r3, #0 */
/* @0x1afb78 str r3, [r4, #0xb4] */
/* @0x1afb7c mov r0, r4 */
/* @0x1afb80 mov r1, #0 */
/* @0x1afb84 mov r2, #292 */
/* @0x1afb88 bl 0xb65b0 <memset@plt> */
/* @0x1afb8c ldr r0, [r4, #0x120] */
/* @0x1afb90 str r8, [r7] */
/* @0x1afb94 cmp r0, #0 */
/* @0x1afb98 beq 0x1afba8 <_ZN5CRoomD2Ev+0x1a8> */
/* @0x1afb9c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afba0 mov r3, #0 */
/* @0x1afba4 str r3, [r4, #0x120] */
/* @0x1afba8 ldr r0, [r4, #0x108] */
/* @0x1afbac cmp r0, #0 */
/* @0x1afbb0 beq 0x1afbc0 <_ZN5CRoomD2Ev+0x1c0> */
/* @0x1afbb4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afbb8 mov r3, #0 */
/* @0x1afbbc str r3, [r4, #0x108] */
/* @0x1afbc0 ldr r0, [r4, #0xf4] */
/* @0x1afbc4 cmp r0, #0 */
/* @0x1afbc8 beq 0x1afbd8 <_ZN5CRoomD2Ev+0x1d8> */
/* @0x1afbcc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afbd0 mov r3, #0 */
/* @0x1afbd4 str r3, [r4, #0xf4] */
/* @0x1afbd8 ldr r8, [r4, #0xe0] */
/* @0x1afbdc cmp r8, #0 */
/* @0x1afbe0 beq 0x1afc30 <_ZN5CRoomD2Ev+0x230> */
/* @0x1afbe4 ldr r5, [r4, #0xd4] */
/* @0x1afbe8 cmp r5, #0 */
/* @0x1afbec beq 0x1afc30 <_ZN5CRoomD2Ev+0x230> */
/* @0x1afbf0 mov r9, #0 */
/* @0x1afbf4 b 0x1afc14 <_ZN5CRoomD2Ev+0x214> */
/* @0x1afbf8 cmp r8, #3 */
/* @0x1afbfc beq 0x1afcf4 <_ZN5CRoomD2Ev+0x2f4> */
/* @0x1afc00 cmp r8, #1 */
/* @0x1afc04 beq 0x1afd98 <_ZN5CRoomD2Ev+0x398> */
/* @0x1afc08 cmp r7, #0 */
/* @0x1afc0c beq 0x1afc30 <_ZN5CRoomD2Ev+0x230> */
/* @0x1afc10 mov r5, r7 */
/* @0x1afc14 cmp r8, #2 */
/* @0x1afc18 ldr r7, [r5, #0x68] */
/* @0x1afc1c bne 0x1afbf8 <_ZN5CRoomD2Ev+0x1f8> */
/* @0x1afc20 mov r0, r5 */
/* @0x1afc24 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afc28 cmp r7, #0 */
/* @0x1afc2c bne 0x1afc10 <_ZN5CRoomD2Ev+0x210> */
/* @0x1afc30 ldr r6, [r4, #0xc0] */
/* @0x1afc34 mov r5, #0 */
/* @0x1afc38 str r5, [r4, #0xdc] */
/* @0x1afc3c cmp r6, r5 */
/* @0x1afc40 str r5, [r4, #0xd8] */
/* @0x1afc44 str r5, [r4, #0xd4] */
/* @0x1afc48 beq 0x1afed8 <_ZN5CRoomD2Ev+0x4d8> */
/* @0x1afc4c mov r0, r6 */
/* @0x1afc50 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afc54 str r5, [r4, #0xc0] */
/* @0x1afc58 ldr r3, [r4, #0x98] */
/* @0x1afc5c mov r2, #0 */
/* @0x1afc60 str r2, [r4, #0xbc] */
/* @0x1afc64 cmp r3, r2 */
/* @0x1afc68 beq 0x1afca0 <_ZN5CRoomD2Ev+0x2a0> */
/* @0x1afc6c ldr r5, [r4, #0x8c] */
/* @0x1afc70 cmp r5, #0 */
/* @0x1afc74 beq 0x1afca0 <_ZN5CRoomD2Ev+0x2a0> */
/* @0x1afc78 cmp r3, #2 */
/* @0x1afc7c beq 0x1afe24 <_ZN5CRoomD2Ev+0x424> */
/* @0x1afc80 cmp r3, #3 */
/* @0x1afc84 beq 0x1afe88 <_ZN5CRoomD2Ev+0x488> */
/* @0x1afc88 cmp r3, #1 */
/* @0x1afc8c beq 0x1afeb4 <_ZN5CRoomD2Ev+0x4b4> */
/* @0x1afc90 ldr r6, [r5, #0x178] */
/* @0x1afc94 cmp r6, #0 */
/* @0x1afc98 mov r5, r6 */
/* @0x1afc9c bne 0x1afc90 <_ZN5CRoomD2Ev+0x290> */
/* @0x1afca0 ldr r3, [r4, #0x80] */
/* @0x1afca4 mov r2, #0 */
/* @0x1afca8 str r2, [r4, #0x94] */
/* @0x1afcac cmp r3, r2 */
/* @0x1afcb0 str r2, [r4, #0x90] */
/* @0x1afcb4 str r2, [r4, #0x8c] */
/* @0x1afcb8 beq 0x1afcdc <_ZN5CRoomD2Ev+0x2dc> */
/* @0x1afcbc ldr r2, [r3] */
/* @0x1afcc0 mov r0, r3 */
/* @0x1afcc4 ldr r5, [r3, #0x178] */
/* @0x1afcc8 ldr r3, [r2, #0x4] */
/* @0x1afccc blx r3 */
/* @0x1afcd0 cmp r5, #0 */
/* @0x1afcd4 mov r3, r5 */
/* @0x1afcd8 bne 0x1afcbc <_ZN5CRoomD2Ev+0x2bc> */
/* @0x1afcdc mov r3, #0 */
/* @0x1afce0 mov r0, r4 */
/* @0x1afce4 str r3, [r4, #0x88] */
/* @0x1afce8 str r3, [r4, #0x84] */
/* @0x1afcec str r3, [r4, #0x80] */
/* @0x1afcf0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1afcf4 ldr r0, [r5, #0x1c] */
/* @0x1afcf8 bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0x1afcfc cmp r0, #0 */
/* @0x1afd00 bne 0x1afd0c <_ZN5CRoomD2Ev+0x30c> */
/* @0x1afd04 ldr r0, [r5, #0x1c] */
/* @0x1afd08 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afd0c ldr r3, [r5, #0x64] */
/* @0x1afd10 str r9, [r5, #0x1c] */
/* @0x1afd14 cmp r3, #0 */
/* @0x1afd18 beq 0x1afd50 <_ZN5CRoomD2Ev+0x350> */
/* @0x1afd1c ldr r0, [r5, #0x58] */
/* @0x1afd20 cmp r0, #0 */
/* @0x1afd24 beq 0x1afd50 <_ZN5CRoomD2Ev+0x350> */
/* @0x1afd28 cmp r3, #2 */
/* @0x1afd2c beq 0x1afd68 <_ZN5CRoomD2Ev+0x368> */
/* @0x1afd30 cmp r3, #3 */
/* @0x1afd34 beq 0x1afd80 <_ZN5CRoomD2Ev+0x380> */
/* @0x1afd38 cmp r3, #1 */
/* @0x1afd3c beq 0x1afe70 <_ZN5CRoomD2Ev+0x470> */
/* @0x1afd40 ldr r6, [r0, #0x14] */
/* @0x1afd44 cmp r6, #0 */
/* @0x1afd48 mov r0, r6 */
/* @0x1afd4c bne 0x1afd40 <_ZN5CRoomD2Ev+0x340> */
/* @0x1afd50 str r9, [r5, #0x60] */
/* @0x1afd54 mov r0, r5 */
/* @0x1afd58 str r9, [r5, #0x5c] */
/* @0x1afd5c str r9, [r5, #0x58] */
/* @0x1afd60 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afd64 b 0x1afc08 <_ZN5CRoomD2Ev+0x208> */
/* @0x1afd68 ldr r6, [r0, #0x14] */
/* @0x1afd6c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afd70 cmp r6, #0 */
/* @0x1afd74 mov r0, r6 */
/* @0x1afd78 bne 0x1afd68 <_ZN5CRoomD2Ev+0x368> */
/* @0x1afd7c b 0x1afd50 <_ZN5CRoomD2Ev+0x350> */
/* @0x1afd80 ldr r6, [r0, #0x14] */
/* @0x1afd84 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afd88 cmp r6, #0 */
/* @0x1afd8c mov r0, r6 */
/* @0x1afd90 bne 0x1afd80 <_ZN5CRoomD2Ev+0x380> */
/* @0x1afd94 b 0x1afd50 <_ZN5CRoomD2Ev+0x350> */
/* @0x1afd98 ldr r0, [r5, #0x1c] */
/* @0x1afd9c bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0x1afda0 cmp r0, #0 */
/* @0x1afda4 bne 0x1afdb0 <_ZN5CRoomD2Ev+0x3b0> */
/* @0x1afda8 ldr r0, [r5, #0x1c] */
/* @0x1afdac bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afdb0 ldr r3, [r5, #0x64] */
/* @0x1afdb4 str r9, [r5, #0x1c] */
/* @0x1afdb8 cmp r3, #0 */
/* @0x1afdbc beq 0x1afdf4 <_ZN5CRoomD2Ev+0x3f4> */
/* @0x1afdc0 ldr r0, [r5, #0x58] */
/* @0x1afdc4 cmp r0, #0 */
/* @0x1afdc8 beq 0x1afdf4 <_ZN5CRoomD2Ev+0x3f4> */
/* @0x1afdcc cmp r3, #2 */
/* @0x1afdd0 beq 0x1afe0c <_ZN5CRoomD2Ev+0x40c> */
/* @0x1afdd4 cmp r3, #3 */
/* @0x1afdd8 beq 0x1afe40 <_ZN5CRoomD2Ev+0x440> */
/* @0x1afddc cmp r3, #1 */
/* @0x1afde0 beq 0x1afe58 <_ZN5CRoomD2Ev+0x458> */
/* @0x1afde4 ldr r6, [r0, #0x14] */
/* @0x1afde8 cmp r6, #0 */
/* @0x1afdec mov r0, r6 */
/* @0x1afdf0 bne 0x1afde4 <_ZN5CRoomD2Ev+0x3e4> */
/* @0x1afdf4 str r9, [r5, #0x60] */
/* @0x1afdf8 mov r0, r5 */
/* @0x1afdfc str r9, [r5, #0x5c] */
/* @0x1afe00 str r9, [r5, #0x58] */
/* @0x1afe04 bl 0x27d1d0 <_ZdlPv> */
/* @0x1afe08 b 0x1afc08 <_ZN5CRoomD2Ev+0x208> */
/* @0x1afe0c ldr r6, [r0, #0x14] */
/* @0x1afe10 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afe14 cmp r6, #0 */
/* @0x1afe18 mov r0, r6 */
/* @0x1afe1c bne 0x1afe0c <_ZN5CRoomD2Ev+0x40c> */
/* @0x1afe20 b 0x1afdf4 <_ZN5CRoomD2Ev+0x3f4> */
/* @0x1afe24 ldr r6, [r5, #0x178] */
/* @0x1afe28 mov r0, r5 */
/* @0x1afe2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afe30 cmp r6, #0 */
/* @0x1afe34 mov r5, r6 */
/* @0x1afe38 bne 0x1afe24 <_ZN5CRoomD2Ev+0x424> */
/* @0x1afe3c b 0x1afca0 <_ZN5CRoomD2Ev+0x2a0> */
/* @0x1afe40 ldr r6, [r0, #0x14] */
/* @0x1afe44 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afe48 cmp r6, #0 */
/* @0x1afe4c mov r0, r6 */
/* @0x1afe50 bne 0x1afe40 <_ZN5CRoomD2Ev+0x440> */
/* @0x1afe54 b 0x1afdf4 <_ZN5CRoomD2Ev+0x3f4> */
/* @0x1afe58 ldr r6, [r0, #0x14] */
/* @0x1afe5c bl 0x27d1d0 <_ZdlPv> */
/* @0x1afe60 cmp r6, #0 */
/* @0x1afe64 mov r0, r6 */
/* @0x1afe68 bne 0x1afe58 <_ZN5CRoomD2Ev+0x458> */
/* @0x1afe6c b 0x1afdf4 <_ZN5CRoomD2Ev+0x3f4> */
/* @0x1afe70 ldr r6, [r0, #0x14] */
/* @0x1afe74 bl 0x27d1d0 <_ZdlPv> */
/* @0x1afe78 cmp r6, #0 */
/* @0x1afe7c mov r0, r6 */
/* @0x1afe80 bne 0x1afe70 <_ZN5CRoomD2Ev+0x470> */
/* @0x1afe84 b 0x1afd50 <_ZN5CRoomD2Ev+0x350> */
/* @0x1afe88 ldr r3, [r5] */
/* @0x1afe8c mov r0, r5 */
/* @0x1afe90 ldr r6, [r5, #0x178] */
/* @0x1afe94 ldr r3, [r3] */
/* @0x1afe98 blx r3 */
/* @0x1afe9c mov r0, r5 */
/* @0x1afea0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afea4 cmp r6, #0 */
/* @0x1afea8 mov r5, r6 */
/* @0x1afeac bne 0x1afe88 <_ZN5CRoomD2Ev+0x488> */
/* @0x1afeb0 b 0x1afca0 <_ZN5CRoomD2Ev+0x2a0> */
/* @0x1afeb4 ldr r3, [r5] */
/* @0x1afeb8 mov r0, r5 */
/* @0x1afebc ldr r6, [r5, #0x178] */
/* @0x1afec0 ldr r3, [r3, #0x4] */
/* @0x1afec4 blx r3 */
/* @0x1afec8 cmp r6, #0 */
/* @0x1afecc mov r5, r6 */
/* @0x1afed0 bne 0x1afeb4 <_ZN5CRoomD2Ev+0x4b4> */
/* @0x1afed4 b 0x1afca0 <_ZN5CRoomD2Ev+0x2a0> */
/* @0x1afed8 mov r0, r6 */
/* @0x1afedc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afee0 str r6, [r4, #0xc0] */
/* @0x1afee4 b 0x1afc58 <_ZN5CRoomD2Ev+0x258> */
/* @0x1afee8 eoreq sp, r3, r4, lsl pc */
/* @0x1afeec eoreq sp, r3, r4, lsl pc */
