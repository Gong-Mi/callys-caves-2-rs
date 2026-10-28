/* libyoyo.so 覆盖卡组 0118
 * 函数 0x17e2a8..0x17fcf8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x17e2a8 · Graphics::Texture_GrabRect(void*, int, int, int, int) · size=748 · insn=187 */
/* @0x17e2a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17e2ac mov r11, r1 */
/* @0x17e2b0 ldr r1, [r0, #0x18] */
/* @0x17e2b4 sub sp, sp, #36 */
/* @0x17e2b8 ldr r4, [pc, #0x28c] */
/* @0x17e2bc mov r6, r0 */
/* @0x17e2c0 cmn r1, #1 */
/* @0x17e2c4 str r2, [sp, #0x14] */
/* @0x17e2c8 add r4, pc, r4 */
/* @0x17e2cc mov r9, r3 */
/* @0x17e2d0 ldr r5, [sp, #0x48] */
/* @0x17e2d4 beq 0x17e44c <_ZN8Graphics16Texture_GrabRectEPviiii+0x1a4> */
/* @0x17e2d8 ldr r3, [r6, #0x14] */
/* @0x17e2dc cmn r3, #1 */
/* @0x17e2e0 beq 0x17e544 <_ZN8Graphics16Texture_GrabRectEPviiii+0x29c> */
/* @0x17e2e4 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x17e2e8 ldr r3, [pc, #0x260] */
/* @0x17e2ec movw r0, #0xd05 */
/* @0x17e2f0 mov r1, #4 */
/* @0x17e2f4 ldr r3, [r4, r3] */
/* @0x17e2f8 ldr r3, [r3] */
/* @0x17e2fc blx r3 */
/* @0x17e300 ldr r3, [pc, #0x24c] */
/* @0x17e304 ldr r3, [r4, r3] */
/* @0x17e308 str r3, [sp, #0x10] */
/* @0x17e30c ldr r3, [r3] */
/* @0x17e310 blx r3 */
/* @0x17e314 ldr r3, [pc, #0x23c] */
/* @0x17e318 ldr r8, [r4, r3] */
/* @0x17e31c ldr r0, [r8] */
/* @0x17e320 cmp r0, #1 */
/* @0x17e324 beq 0x17e518 <_ZN8Graphics16Texture_GrabRectEPviiii+0x270> */
/* @0x17e328 ldr r3, [pc, #0x22c] */
/* @0x17e32c add r10, sp, #28 */
/* @0x17e330 mov r0, #1 */
/* @0x17e334 mov r1, r10 */
/* @0x17e338 ldr r3, [r4, r3] */
/* @0x17e33c ldr r3, [r3] */
/* @0x17e340 blx r3 */
/* @0x17e344 ldr r1, [pc, #0x214] */
/* @0x17e348 mov r3, #247 */
/* @0x17e34c ldr r2, [pc, #0x210] */
/* @0x17e350 ldr r0, [sp, #0x1c] */
/* @0x17e354 ldr r7, [r4, r1] */
/* @0x17e358 add r2, pc, r2 */
/* @0x17e35c stm r7, {r2, r3} */
/* @0x17e360 bl 0x1805b4 <_Z20DBG_BIND_FRAMEBUFFERi> */
/* @0x17e364 ldr r3, [r8] */
/* @0x17e368 ldr r12, [pc, #0x1f8] */
/* @0x17e36c cmp r3, #1 */
/* @0x17e370 ldrne r12, [pc, #0x1f4] */
/* @0x17e374 ldr r12, [r4, r12] */
/* @0x17e378 mov lr, #0 */
/* @0x17e37c ldr r3, [r6, #0x14] */
/* @0x17e380 movw r0, #0x8d40 */
/* @0x17e384 str lr, [sp] */
/* @0x17e388 movw r1, #0x8ce0 */
/* @0x17e38c ldr r12, [r12] */
/* @0x17e390 movw r2, #0xde1 */
/* @0x17e394 blx r12 */
/* @0x17e398 mul r0, r5, r9 */
/* @0x17e39c ldr r1, [pc, #0x1cc] */
/* @0x17e3a0 mov r2, #70 */
/* @0x17e3a4 mov r3, #1 */
/* @0x17e3a8 add r1, pc, r1 */
/* @0x17e3ac lsl r0, r0, #2 */
/* @0x17e3b0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x17e3b4 ldr r2, [sp, #0x10] */
/* @0x17e3b8 ldr r3, [r2] */
/* @0x17e3bc mov r6, r0 */
/* @0x17e3c0 blx r3 */
/* @0x17e3c4 ldr r12, [pc, #0x1a8] */
/* @0x17e3c8 mov r0, r11 */
/* @0x17e3cc mov r3, r5 */
/* @0x17e3d0 movw lr, #0x1401 */
/* @0x17e3d4 ldr r1, [sp, #0x14] */
/* @0x17e3d8 mov r2, r9 */
/* @0x17e3dc ldr r12, [r4, r12] */
/* @0x17e3e0 movw r5, #0x1908 */
/* @0x17e3e4 str r6, [sp, #0x8] */
/* @0x17e3e8 str r5, [sp] */
/* @0x17e3ec ldr r12, [r12] */
/* @0x17e3f0 str lr, [sp, #0x4] */
/* @0x17e3f4 blx r12 */
/* @0x17e3f8 ldr r0, [r8] */
/* @0x17e3fc cmp r0, #1 */
/* @0x17e400 beq 0x17e500 <_ZN8Graphics16Texture_GrabRectEPviiii+0x258> */
/* @0x17e404 ldr r3, [pc, #0x16c] */
/* @0x17e408 mov r1, r10 */
/* @0x17e40c mov r0, #1 */
/* @0x17e410 ldr r3, [r4, r3] */
/* @0x17e414 ldr r3, [r3] */
/* @0x17e418 blx r3 */
/* @0x17e41c ldr r3, [pc, #0x158] */
/* @0x17e420 movw r1, #0x10e */
/* @0x17e424 ldr r2, [pc, #0x154] */
/* @0x17e428 str r1, [r7, #0x4] */
/* @0x17e42c add r2, pc, r2 */
/* @0x17e430 str r2, [r7] */
/* @0x17e434 ldr r3, [r4, r3] */
/* @0x17e438 ldr r0, [r3] */
/* @0x17e43c bl 0x1805b4 <_Z20DBG_BIND_FRAMEBUFFERi> */
/* @0x17e440 mov r0, r6 */
/* @0x17e444 add sp, sp, #36 */
/* @0x17e448 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17e44c ldr r3, [pc, #0x130] */
/* @0x17e450 ldr r3, [r4, r3] */
/* @0x17e454 ldr r3, [r3] */
/* @0x17e458 cmp r3, #1 */
/* @0x17e45c beq 0x17e534 <_ZN8Graphics16Texture_GrabRectEPviiii+0x28c> */
/* @0x17e460 add r1, sp, #32 */
/* @0x17e464 mov r7, #0 */
/* @0x17e468 mov r0, r6 */
/* @0x17e46c strb r7, [r1, #-0x4]! */
/* @0x17e470 bl 0x182da0 <_Z22_GetCPUSideTextureDataP7TextureRb> */
/* @0x17e474 subs r8, r0, #0 */
/* @0x17e478 beq 0x17e2d8 <_ZN8Graphics16Texture_GrabRectEPviiii+0x30> */
/* @0x17e47c mul r0, r5, r9 */
/* @0x17e480 ldr r1, [pc, #0x100] */
/* @0x17e484 mov r2, #70 */
/* @0x17e488 mov r3, #1 */
/* @0x17e48c add r1, pc, r1 */
/* @0x17e490 lsl r0, r0, #2 */
/* @0x17e494 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x17e498 ldr r6, [r6, #0x4] */
/* @0x17e49c ldr r2, [sp, #0x14] */
/* @0x17e4a0 cmp r5, r7 */
/* @0x17e4a4 lslgt r9, r9, #2 */
/* @0x17e4a8 mla r11, r2, r6, r11 */
/* @0x17e4ac lslgt r6, r6, #2 */
/* @0x17e4b0 add r11, r8, r11, lsl #2 */
/* @0x17e4b4 mov r4, r0 */
/* @0x17e4b8 movgt r3, r0 */
/* @0x17e4bc ble 0x17e4e4 <_ZN8Graphics16Texture_GrabRectEPviiii+0x23c> */
/* @0x17e4c0 mov r0, r3 */
/* @0x17e4c4 mov r1, r11 */
/* @0x17e4c8 mov r2, r9 */
/* @0x17e4cc add r7, r7, #1 */
/* @0x17e4d0 bl 0xb65bc <memcpy@plt> */
/* @0x17e4d4 cmp r7, r5 */
/* @0x17e4d8 add r11, r11, r6 */
/* @0x17e4dc add r3, r0, r9 */
/* @0x17e4e0 bne 0x17e4c0 <_ZN8Graphics16Texture_GrabRectEPviiii+0x218> */
/* @0x17e4e4 ldrb r3, [sp, #0x1c] */
/* @0x17e4e8 cmp r3, #0 */
/* @0x17e4ec beq 0x17e4f4 <_ZN8Graphics16Texture_GrabRectEPviiii+0x24c> */
/* @0x17e4f0 bl 0x18a518 <_Z11FreePNGFilev> */
/* @0x17e4f4 mov r0, r4 */
/* @0x17e4f8 add sp, sp, #36 */
/* @0x17e4fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17e500 ldr r3, [pc, #0x84] */
/* @0x17e504 mov r1, r10 */
/* @0x17e508 ldr r3, [r4, r3] */
/* @0x17e50c ldr r3, [r3] */
/* @0x17e510 blx r3 */
/* @0x17e514 b 0x17e41c <_ZN8Graphics16Texture_GrabRectEPviiii+0x174> */
/* @0x17e518 ldr r3, [pc, #0x70] */
/* @0x17e51c add r10, sp, #28 */
/* @0x17e520 mov r1, r10 */
/* @0x17e524 ldr r3, [r4, r3] */
/* @0x17e528 ldr r3, [r3] */
/* @0x17e52c blx r3 */
/* @0x17e530 b 0x17e344 <_ZN8Graphics16Texture_GrabRectEPviiii+0x9c> */
/* @0x17e534 ldr r3, [r0, #0x14] */
/* @0x17e538 cmn r3, #1 */
/* @0x17e53c bne 0x17e2e4 <_ZN8Graphics16Texture_GrabRectEPviiii+0x3c> */
/* @0x17e540 b 0x17e460 <_ZN8Graphics16Texture_GrabRectEPviiii+0x1b8> */
/* @0x17e544 mov r0, #0 */
/* @0x17e548 b 0x17e444 <_ZN8Graphics16Texture_GrabRectEPviiii+0x19c> */
/* @0x17e54c eoreq r3, r7, r8, lsl #19 */
/* @0x17e550 .word 0xffffbaf8 */
/* @0x17e554 .word 0xffffbafc */
/* @0x17e558 .word 0xffffe7b8 */
/* @0x17e55c .word 0xffffbc74 */
/* @0x17e560 .word 0xffffe81c */
/* @0x17e564 ldrsheq sp, [r12], -r0 */
/* @0x17e568 .word 0xffffbb6c */
/* @0x17e56c .word 0xffffbc7c */
/* @0x17e570 andseq r2, r11, r8, lsl #25 */
/* @0x17e574 .word 0xffffbaf4 */
/* @0x17e578 .word 0xffffbc80 */
/* @0x17e57c .word 0xffffe820 */
/* @0x17e580 andseq sp, r12, r12, lsl r5 */
/* @0x17e584 .word 0xffffc984 */
/* @0x17e588 andseq r2, r11, r4, lsr #23 */
/* @0x17e58c .word 0xffffbb70 */
/* @0x17e590 .word 0xffffbb68 */

/* ── FUNC 0x17e594 · Graphics::Surface_GrabRect(void*, int, int, int, int) · size=280 · insn=70 */
/* @0x17e594 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17e598 sub sp, sp, #20 */
/* @0x17e59c ldr r4, [pc, #0xe8] */
/* @0x17e5a0 mov r11, r2 */
/* @0x17e5a4 mov r8, r3 */
/* @0x17e5a8 mov r5, r0 */
/* @0x17e5ac mov r7, r1 */
/* @0x17e5b0 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x17e5b4 ldr r3, [pc, #0xd4] */
/* @0x17e5b8 add r4, pc, r4 */
/* @0x17e5bc movw r0, #0xd05 */
/* @0x17e5c0 mov r1, #4 */
/* @0x17e5c4 ldr r9, [pc, #0xc8] */
/* @0x17e5c8 ldr r3, [r4, r3] */
/* @0x17e5cc add r9, pc, r9 */
/* @0x17e5d0 ldr r3, [r3] */
/* @0x17e5d4 blx r3 */
/* @0x17e5d8 ldr r3, [pc, #0xb8] */
/* @0x17e5dc ldr r10, [r4, r3] */
/* @0x17e5e0 ldr r3, [r10] */
/* @0x17e5e4 blx r3 */
/* @0x17e5e8 ldr r3, [sp, #0x38] */
/* @0x17e5ec ldr r1, [pc, #0xa8] */
/* @0x17e5f0 mov r2, #70 */
/* @0x17e5f4 mul r0, r3, r8 */
/* @0x17e5f8 add r1, pc, r1 */
/* @0x17e5fc mov r3, #1 */
/* @0x17e600 lsl r0, r0, #2 */
/* @0x17e604 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x17e608 ldr r2, [pc, #0x90] */
/* @0x17e60c movw r3, #0x133 */
/* @0x17e610 mov r6, r0 */
/* @0x17e614 ldr r0, [r5, #0x18] */
/* @0x17e618 ldr r5, [r4, r2] */
/* @0x17e61c str r3, [r5, #0x4] */
/* @0x17e620 str r9, [r5] */
/* @0x17e624 bl 0x1805b4 <_Z20DBG_BIND_FRAMEBUFFERi> */
/* @0x17e628 ldr r3, [r10] */
/* @0x17e62c blx r3 */
/* @0x17e630 ldr lr, [pc, #0x6c] */
/* @0x17e634 mov r0, r7 */
/* @0x17e638 mov r1, r11 */
/* @0x17e63c mov r2, r8 */
/* @0x17e640 ldr r3, [sp, #0x38] */
/* @0x17e644 ldr r12, [r4, lr] */
/* @0x17e648 movw r7, #0x1908 */
/* @0x17e64c movw lr, #0x1401 */
/* @0x17e650 str r6, [sp, #0x8] */
/* @0x17e654 str r7, [sp] */
/* @0x17e658 ldr r12, [r12] */
/* @0x17e65c str lr, [sp, #0x4] */
/* @0x17e660 blx r12 */
/* @0x17e664 ldr r3, [pc, #0x3c] */
/* @0x17e668 str r9, [r5] */
/* @0x17e66c mov r2, #316 */
/* @0x17e670 str r2, [r5, #0x4] */
/* @0x17e674 ldr r3, [r4, r3] */
/* @0x17e678 ldr r0, [r3] */
/* @0x17e67c bl 0x1805b4 <_Z20DBG_BIND_FRAMEBUFFERi> */
/* @0x17e680 mov r0, r6 */
/* @0x17e684 add sp, sp, #20 */
/* @0x17e688 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17e68c mlaeq r7, r8, r6, r3 */
/* @0x17e690 .word 0xffffbaf8 */
/* @0x17e694 andseq sp, r12, r12, ror r3 */
/* @0x17e698 .word 0xffffbafc */
/* @0x17e69c andseq r2, r11, r8, lsr r10 */
/* @0x17e6a0 .word 0xffffe81c */
/* @0x17e6a4 .word 0xffffbaf4 */
/* @0x17e6a8 .word 0xffffe820 */

/* ── FUNC 0x17e6ac · Graphics::Surface_SetRect(void*, void*, int, int, int, int) · size=420 · insn=105 */
/* @0x17e6ac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17e6b0 sub sp, sp, #44 */
/* @0x17e6b4 mov r9, r2 */
/* @0x17e6b8 mov r8, r3 */
/* @0x17e6bc mov r5, r0 */
/* @0x17e6c0 ldr r10, [sp, #0x50] */
/* @0x17e6c4 mov r4, r1 */
/* @0x17e6c8 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x17e6cc cmp r9, #0 */
/* @0x17e6d0 ldmib r4, {r1, r3} */
/* @0x17e6d4 addlt r7, r10, r9 */
/* @0x17e6d8 rsblt r2, r9, #0 */
/* @0x17e6dc movge r7, r10 */
/* @0x17e6e0 movlt r9, #0 */
/* @0x17e6e4 movge r2, #0 */
/* @0x17e6e8 cmp r8, #0 */
/* @0x17e6ec rsblt r12, r8, #0 */
/* @0x17e6f0 ldr r11, [pc, #0x148] */
/* @0x17e6f4 ldrlt r0, [sp, #0x54] */
/* @0x17e6f8 movge r12, #0 */
/* @0x17e6fc ldrge r6, [sp, #0x54] */
/* @0x17e700 add r11, pc, r11 */
/* @0x17e704 addlt r6, r0, r8 */
/* @0x17e708 add r0, r9, r7 */
/* @0x17e70c movlt r8, #0 */
/* @0x17e710 cmp r1, r0 */
/* @0x17e714 rsblt r7, r9, r1 */
/* @0x17e718 add r1, r8, r6 */
/* @0x17e71c cmp r3, r1 */
/* @0x17e720 rsblt r6, r8, r3 */
/* @0x17e724 cmp r7, #0 */
/* @0x17e728 cmpgt r6, #0 */
/* @0x17e72c movgt r3, #0 */
/* @0x17e730 movle r3, #1 */
/* @0x17e734 bgt 0x17e740 <_ZN8Graphics15Surface_SetRectEPvS0_iiii+0x94> */
/* @0x17e738 add sp, sp, #44 */
/* @0x17e73c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17e740 ldr lr, [pc, #0xfc] */
/* @0x17e744 add r1, sp, #40 */
/* @0x17e748 movw r0, #0x8069 */
/* @0x17e74c str r3, [r1, #-0x4]! */
/* @0x17e750 ldr r3, [r11, lr] */
/* @0x17e754 ldr r3, [r3] */
/* @0x17e758 str r2, [sp, #0x1c] */
/* @0x17e75c str r12, [sp, #0x18] */
/* @0x17e760 blx r3 */
/* @0x17e764 ldr r3, [pc, #0xdc] */
/* @0x17e768 ldr r1, [r4, #0x14] */
/* @0x17e76c movw r0, #0xde1 */
/* @0x17e770 ldr r3, [r11, r3] */
/* @0x17e774 ldr r3, [r3] */
/* @0x17e778 blx r3 */
/* @0x17e77c ldr r2, [sp, #0x1c] */
/* @0x17e780 ldr r12, [sp, #0x18] */
/* @0x17e784 orrs r1, r12, r2 */
/* @0x17e788 beq 0x17e7f4 <_ZN8Graphics15Surface_SetRectEPvS0_iiii+0x148> */
/* @0x17e78c mla r2, r10, r12, r2 */
/* @0x17e790 ldr r3, [pc, #0xb4] */
/* @0x17e794 lsl r10, r10, #2 */
/* @0x17e798 mov r4, #0 */
/* @0x17e79c ldr r11, [r11, r3] */
/* @0x17e7a0 add r5, r5, r2, lsl #2 */
/* @0x17e7a4 str r5, [sp, #0x10] */
/* @0x17e7a8 mov r3, #1 */
/* @0x17e7ac str r7, [sp] */
/* @0x17e7b0 movw r0, #0xde1 */
/* @0x17e7b4 str r3, [sp, #0x4] */
/* @0x17e7b8 movw r3, #0x1908 */
/* @0x17e7bc str r3, [sp, #0x8] */
/* @0x17e7c0 movw r3, #0x1401 */
/* @0x17e7c4 str r3, [sp, #0xc] */
/* @0x17e7c8 mov r1, #0 */
/* @0x17e7cc add r3, r4, r8 */
/* @0x17e7d0 mov r2, r9 */
/* @0x17e7d4 add r4, r4, #1 */
/* @0x17e7d8 ldr r12, [r11] */
/* @0x17e7dc blx r12 */
/* @0x17e7e0 cmp r6, r4 */
/* @0x17e7e4 add r5, r5, r10 */
/* @0x17e7e8 bgt 0x17e7a4 <_ZN8Graphics15Surface_SetRectEPvS0_iiii+0xf8> */
/* @0x17e7ec add sp, sp, #44 */
/* @0x17e7f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17e7f4 ldr r3, [sp, #0x54] */
/* @0x17e7f8 cmp r7, r10 */
/* @0x17e7fc cmpeq r6, r3 */
/* @0x17e800 bne 0x17e78c <_ZN8Graphics15Surface_SetRectEPvS0_iiii+0xe0> */
/* @0x17e804 ldr r0, [pc, #0x40] */
/* @0x17e808 movw r4, #0x1908 */
/* @0x17e80c movw lr, #0x1401 */
/* @0x17e810 mov r2, r9 */
/* @0x17e814 mov r3, r8 */
/* @0x17e818 ldr r12, [r11, r0] */
/* @0x17e81c movw r0, #0xde1 */
/* @0x17e820 str r7, [sp] */
/* @0x17e824 str r6, [sp, #0x4] */
/* @0x17e828 ldr r12, [r12] */
/* @0x17e82c str r5, [sp, #0x10] */
/* @0x17e830 str r4, [sp, #0x8] */
/* @0x17e834 str lr, [sp, #0xc] */
/* @0x17e838 blx r12 */
/* @0x17e83c b 0x17e738 <_ZN8Graphics15Surface_SetRectEPvS0_iiii+0x8c> */
/* @0x17e840 eoreq r3, r7, r0, asr r5 */
/* @0x17e844 .word 0xffffbb48 */
/* @0x17e848 .word 0xffffbb20 */
/* @0x17e84c .word 0xffffbb30 */

/* ── FUNC 0x17e850 · Graphics::SurfaceCopy(void*, int, int, void*, int, int, int, int) · size=640 · insn=160 */
/* @0x17e850 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17e854 vpush {d8} */
/* @0x17e858 sub sp, sp, #268 */
/* @0x17e85c ldr r4, [pc, #0x23c] */
/* @0x17e860 mov r5, r0 */
/* @0x17e864 mov r9, r3 */
/* @0x17e868 vmov s17, r1 */
/* @0x17e86c vmov s16, r2 */
/* @0x17e870 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x17e874 ldr r3, [pc, #0x228] */
/* @0x17e878 add r4, pc, r4 */
/* @0x17e87c add r8, sp, #72 */
/* @0x17e880 mov r10, #192 */
/* @0x17e884 mov r2, r10 */
/* @0x17e888 ldr r11, [pc, #0x218] */
/* @0x17e88c ldr r3, [r4, r3] */
/* @0x17e890 mov r0, r8 */
/* @0x17e894 add r11, pc, r11 */
/* @0x17e898 mvn r6, #0 */
/* @0x17e89c mov r1, r3 */
/* @0x17e8a0 str r3, [sp, #0x40] */
/* @0x17e8a4 bl 0xb65bc <memcpy@plt> */
/* @0x17e8a8 ldr r2, [pc, #0x1fc] */
/* @0x17e8ac ldr r0, [r5, #0x18] */
/* @0x17e8b0 movw r3, #0x1b9 */
/* @0x17e8b4 ldr r7, [r4, r2] */
/* @0x17e8b8 str r3, [r7, #0x4] */
/* @0x17e8bc str r11, [r7] */
/* @0x17e8c0 bl 0x1805b4 <_Z20DBG_BIND_FRAMEBUFFERi> */
/* @0x17e8c4 ldmib r5, {r2, r3} */
/* @0x17e8c8 mov r12, #0 */
/* @0x17e8cc ldr lr, [pc, #0x1dc] */
/* @0x17e8d0 mov r0, r12 */
/* @0x17e8d4 vmov s6, r2 */
/* @0x17e8d8 ldr lr, [r4, lr] */
/* @0x17e8dc vcvt.f32.s32 s6, s6 */
/* @0x17e8e0 str r12, [sp] */
/* @0x17e8e4 ldr r1, [lr] */
/* @0x17e8e8 str r6, [lr] */
/* @0x17e8ec str lr, [sp, #0x3c] */
/* @0x17e8f0 str r1, [sp, #0x44] */
/* @0x17e8f4 mov r1, r12 */
/* @0x17e8f8 vmov r2, s6 */
/* @0x17e8fc vmov s6, r3 */
/* @0x17e900 vcvt.f32.s32 s6, s6 */
/* @0x17e904 vmov r3, s6 */
/* @0x17e908 bl 0x1633e8 <_Z22GR_3D_Projection_Orthofffff> */
/* @0x17e90c ldr r12, [pc, #0x1a0] */
/* @0x17e910 mov r0, #0 */
/* @0x17e914 ldmib r5, {r2, r3} */
/* @0x17e918 mov r1, r0 */
/* @0x17e91c ldr r12, [r4, r12] */
/* @0x17e920 ldr r12, [r12] */
/* @0x17e924 blx r12 */
/* @0x17e928 ldr r12, [pc, #0x188] */
/* @0x17e92c mov r0, #0 */
/* @0x17e930 ldmib r5, {r2, r3} */
/* @0x17e934 mov r1, r0 */
/* @0x17e938 ldr r12, [r4, r12] */
/* @0x17e93c ldr r12, [r12] */
/* @0x17e940 blx r12 */
/* @0x17e944 vmov.f32 s11, #1.000000e+00 */
/* @0x17e948 vldr s10, [r9, #4] */
/* @0x17e94c vldr s15, [r9, #8] */
/* @0x17e950 ldr r2, [sp, #0x140] */
/* @0x17e954 vldr s6, [sp, #312] */
/* @0x17e958 ldr r1, [sp, #0x138] */
/* @0x17e95c mov r0, r9 */
/* @0x17e960 ldr r3, [sp, #0x13c] */
/* @0x17e964 add r1, r1, r2 */
/* @0x17e968 vmov r2, s16 */
/* @0x17e96c str r6, [sp, #0x24] */
/* @0x17e970 vmov s7, r1 */
/* @0x17e974 ldr r1, [sp, #0x144] */
/* @0x17e978 str r6, [sp, #0x28] */
/* @0x17e97c add r3, r3, r1 */
/* @0x17e980 str r6, [sp, #0x2c] */
/* @0x17e984 vcvt.f32.s32 s10, s10 */
/* @0x17e988 str r6, [sp, #0x30] */
/* @0x17e98c vmov s9, r3 */
/* @0x17e990 ldr r3, [sp, #0x44] */
/* @0x17e994 vcvt.f32.s32 s15, s15 */
/* @0x17e998 vdiv.f32 s12, s11, s10 */
/* @0x17e99c add r2, r2, r1 */
/* @0x17e9a0 ldr r1, [sp, #0x3c] */
/* @0x17e9a4 vmov s14, r2 */
/* @0x17e9a8 str r3, [r1] */
/* @0x17e9ac vdiv.f32 s13, s11, s15 */
/* @0x17e9b0 vldr s15, [sp, #316] */
/* @0x17e9b4 vcvt.f32.s32 s7, s7 */
/* @0x17e9b8 vcvt.f32.s32 s9, s9 */
/* @0x17e9bc vcvt.f32.s32 s8, s6 */
/* @0x17e9c0 vldr s6, [sp, #320] */
/* @0x17e9c4 vcvt.f32.s32 s10, s15 */
/* @0x17e9c8 vcvt.f32.s32 s11, s6 */
/* @0x17e9cc vcvt.f32.s32 s15, s17 */
/* @0x17e9d0 vmul.f32 s8, s8, s12 */
/* @0x17e9d4 vstr s15, [sp, #12] */
/* @0x17e9d8 vmov r1, s15 */
/* @0x17e9dc vmul.f32 s10, s13, s10 */
/* @0x17e9e0 vstr s8, [sp, #20] */
/* @0x17e9e4 vmul.f32 s12, s7, s12 */
/* @0x17e9e8 vstr s10, [sp, #24] */
/* @0x17e9ec vmul.f32 s13, s13, s9 */
/* @0x17e9f0 vstr s12, [sp, #28] */
/* @0x17e9f4 vadd.f32 s15, s15, s11 */
/* @0x17e9f8 vstr s13, [sp, #32] */
/* @0x17e9fc vcvt.f32.s32 s14, s14 */
/* @0x17ea00 vstr s15, [sp, #4] */
/* @0x17ea04 vmov r3, s15 */
/* @0x17ea08 vcvt.f32.s32 s16, s16 */
/* @0x17ea0c vstr s14, [sp, #8] */
/* @0x17ea10 vstr s14, [sp, #16] */
/* @0x17ea14 vmov r2, s16 */
/* @0x17ea18 vstr s16, [sp] */
/* @0x17ea1c bl 0x17438c <_Z12DrawIt_ColorPvffffffffffffjjjj> */
/* @0x17ea20 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x17ea24 mov r1, r8 */
/* @0x17ea28 mov r2, r10 */
/* @0x17ea2c ldr r0, [sp, #0x40] */
/* @0x17ea30 bl 0xb65bc <memcpy@plt> */
/* @0x17ea34 mov r1, r8 */
/* @0x17ea38 add r0, sp, #200 */
/* @0x17ea3c add r2, sp, #136 */
/* @0x17ea40 bl 0x17ec90 <_ZN8Graphics11SetMatricesEPfS0_S0_> */
/* @0x17ea44 ldr r0, [pc, #0x70] */
/* @0x17ea48 ldr r1, [pc, #0x70] */
/* @0x17ea4c ldr r2, [pc, #0x70] */
/* @0x17ea50 ldr r3, [pc, #0x70] */
/* @0x17ea54 ldr r0, [r4, r0] */
/* @0x17ea58 ldr r1, [r4, r1] */
/* @0x17ea5c ldr r2, [r4, r2] */
/* @0x17ea60 ldr r3, [r4, r3] */
/* @0x17ea64 ldr r1, [r1] */
/* @0x17ea68 ldr r0, [r0] */
/* @0x17ea6c ldr r2, [r2] */
/* @0x17ea70 ldr r3, [r3] */
/* @0x17ea74 bl 0x17dfb0 <_ZN8Graphics11SetViewPortEiiii> */
/* @0x17ea78 ldr r3, [pc, #0x4c] */
/* @0x17ea7c str r11, [r7] */
/* @0x17ea80 movw r2, #0x1e3 */
/* @0x17ea84 str r2, [r7, #0x4] */
/* @0x17ea88 ldr r3, [r4, r3] */
/* @0x17ea8c ldr r0, [r3] */
/* @0x17ea90 bl 0x1805b4 <_Z20DBG_BIND_FRAMEBUFFERi> */
/* @0x17ea94 add sp, sp, #268 */
/* @0x17ea98 vpop {d8} */
/* @0x17ea9c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17eaa0 .word 0x002733d8 */
/* @0x17eaa4 .word 0xffffe824 */
/* @0x17eaa8 ldrheq sp, [r12], -r4 */
/* @0x17eaac .word 0xffffe81c */
/* @0x17eab0 .word 0xffffe48c */
/* @0x17eab4 .word 0xffffbae4 */
/* @0x17eab8 .word 0xffffbaf0 */
/* @0x17eabc .word 0xffffe80c */
/* @0x17eac0 .word 0xffffe810 */
/* @0x17eac4 .word 0xffffe814 */
/* @0x17eac8 .word 0xffffe818 */
/* @0x17eacc .word 0xffffe820 */

/* ── FUNC 0x17ead0 · Graphics::GetMatrix(eMatrix, float*) · size=76 · insn=19 */
/* @0x17ead0 push {r4, r5, r6} */
/* @0x17ead4 mov r4, r1 */
/* @0x17ead8 ldr r5, [pc, #0x38] */
/* @0x17eadc ldr r5, [pc, r5] */
/* @0x17eae0 add r5, r5, r0, lsl #6 */
/* @0x17eae4 add r6, r5, #64 */
/* @0x17eae8 mov r12, r5 */
/* @0x17eaec add r4, r4, #16 */
/* @0x17eaf0 ldm r12!, {r0, r1, r2, r3} */
/* @0x17eaf4 add r5, r5, #16 */
/* @0x17eaf8 cmp r12, r6 */
/* @0x17eafc str r0, [r4, #-0x10] */
/* @0x17eb00 str r1, [r4, #-0xc] */
/* @0x17eb04 str r2, [r4, #-0x8] */
/* @0x17eb08 str r3, [r4, #-0x4] */
/* @0x17eb0c bne 0x17eae8 <_ZN8Graphics9GetMatrixE7eMatrixPf+0x18> */
/* @0x17eb10 pop {r4, r5, r6} */
/* @0x17eb14 bx lr */
/* @0x17eb18 mlaeq r7, r8, r9, r1 */

/* ── FUNC 0x17eb1c · Graphics::SetMatrix(eMatrix, float*) · size=372 · insn=93 */
/* @0x17eb1c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x17eb20 mov r5, r0 */
/* @0x17eb24 ldr r4, [pc, #0x144] */
/* @0x17eb28 mov r6, r1 */
/* @0x17eb2c ldr r3, [pc, #0x140] */
/* @0x17eb30 add r4, pc, r4 */
/* @0x17eb34 ldr r3, [r4, r3] */
/* @0x17eb38 ldrb r3, [r3] */
/* @0x17eb3c cmp r3, #0 */
/* @0x17eb40 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x17eb44 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x17eb48 ldr r3, [pc, #0x128] */
/* @0x17eb4c mov r12, r6 */
/* @0x17eb50 add r9, r6, #64 */
/* @0x17eb54 ldr r6, [r4, r3] */
/* @0x17eb58 add r8, r6, r5, lsl #6 */
/* @0x17eb5c mov r7, r8 */
/* @0x17eb60 ldr r0, [r12] */
/* @0x17eb64 add r12, r12, #16 */
/* @0x17eb68 ldr r1, [r12, #-0xc] */
/* @0x17eb6c mov lr, r7 */
/* @0x17eb70 ldr r2, [r12, #-0x8] */
/* @0x17eb74 add r7, r7, #16 */
/* @0x17eb78 ldr r3, [r12, #-0x4] */
/* @0x17eb7c cmp r12, r9 */
/* @0x17eb80 stm lr!, {r0, r1, r2, r3} */
/* @0x17eb84 bne 0x17eb60 <_ZN8Graphics9SetMatrixE7eMatrixPf+0x44> */
/* @0x17eb88 cmp r5, #0 */
/* @0x17eb8c beq 0x17ec48 <_ZN8Graphics9SetMatrixE7eMatrixPf+0x12c> */
/* @0x17eb90 cmp r5, #2 */
/* @0x17eb94 beq 0x17ec48 <_ZN8Graphics9SetMatrixE7eMatrixPf+0x12c> */
/* @0x17eb98 cmp r5, #1 */
/* @0x17eb9c beq 0x17ebb0 <_ZN8Graphics9SetMatrixE7eMatrixPf+0x94> */
/* @0x17eba0 add r0, r6, #192 */
/* @0x17eba4 add r1, r6, #128 */
/* @0x17eba8 mov r2, r6 */
/* @0x17ebac bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x17ebb0 add r0, r6, #256 */
/* @0x17ebb4 add r1, r6, #192 */
/* @0x17ebb8 add r2, r6, #64 */
/* @0x17ebbc bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x17ebc0 ldr r3, [pc, #0xb4] */
/* @0x17ebc4 ldr r7, [r4, r3] */
/* @0x17ebc8 ldr r3, [r7] */
/* @0x17ebcc cmp r3, #0 */
/* @0x17ebd0 bne 0x17ec04 <_ZN8Graphics9SetMatrixE7eMatrixPf+0xe8> */
/* @0x17ebd4 ldr r3, [pc, #0xa4] */
/* @0x17ebd8 cmp r5, #1 */
/* @0x17ebdc movw r0, #0x1701 */
/* @0x17ebe0 movne r0, #5888 */
/* @0x17ebe4 ldr r3, [r4, r3] */
/* @0x17ebe8 ldr r3, [r3] */
/* @0x17ebec blx r3 */
/* @0x17ebf0 ldr r3, [pc, #0x8c] */
/* @0x17ebf4 mov r0, r8 */
/* @0x17ebf8 ldr r3, [r4, r3] */
/* @0x17ebfc ldr r3, [r3] */
/* @0x17ec00 blx r3 */
/* @0x17ec04 bics r3, r5, #2 */
/* @0x17ec08 beq 0x17ec50 <_ZN8Graphics9SetMatrixE7eMatrixPf+0x134> */
/* @0x17ec0c cmp r5, #1 */
/* @0x17ec10 beq 0x17ec58 <_ZN8Graphics9SetMatrixE7eMatrixPf+0x13c> */
/* @0x17ec14 ldr r3, [r7] */
/* @0x17ec18 cmp r3, #1 */
/* @0x17ec1c popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x17ec20 ldr r3, [pc, #0x60] */
/* @0x17ec24 ldr r3, [r4, r3] */
/* @0x17ec28 ldr r3, [r3] */
/* @0x17ec2c cmp r3, #0 */
/* @0x17ec30 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x17ec34 ldr r0, [r3, #0x6c] */
/* @0x17ec38 mov r2, r6 */
/* @0x17ec3c mov r1, #5 */
/* @0x17ec40 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x17ec44 b 0x1889fc <_Z27Shader_Set_Uniform_Matrix_NiiPf> */
/* @0x17ec48 add r8, r6, #192 */
/* @0x17ec4c b 0x17eb98 <_ZN8Graphics9SetMatrixE7eMatrixPf+0x7c> */
/* @0x17ec50 bl 0x17fa9c <_Z19GR_3D_Light_Processv> */
/* @0x17ec54 b 0x17ec0c <_ZN8Graphics9SetMatrixE7eMatrixPf+0xf0> */
/* @0x17ec58 ldr r3, [pc, #0x2c] */
/* @0x17ec5c mov r0, #8 */
/* @0x17ec60 ldr r3, [r4, r3] */
/* @0x17ec64 ldr r1, [r3] */
/* @0x17ec68 bl 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej> */
/* @0x17ec6c b 0x17ec14 <_ZN8Graphics9SetMatrixE7eMatrixPf+0xf8> */
/* @0x17ec70 eoreq r3, r7, r0, lsr #2 */
/* @0x17ec74 .word 0xffffe4d0 */
/* @0x17ec78 .word 0xffffe824 */
/* @0x17ec7c .word 0xffffe7b8 */
/* @0x17ec80 .word 0xffffbc48 */
/* @0x17ec84 .word 0xffffbc88 */
/* @0x17ec88 .word 0xffffe828 */
/* @0x17ec8c .word 0xffffe82c */

/* ── FUNC 0x17ec90 · Graphics::SetMatrices(float*, float*, float*) · size=564 · insn=141 */
/* @0x17ec90 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17ec94 mov r9, r0 */
/* @0x17ec98 ldr r4, [pc, #0x204] */
/* @0x17ec9c mov r7, r1 */
/* @0x17eca0 ldr r3, [pc, #0x200] */
/* @0x17eca4 mov r5, r2 */
/* @0x17eca8 add r4, pc, r4 */
/* @0x17ecac ldr r3, [r4, r3] */
/* @0x17ecb0 ldrb r6, [r3] */
/* @0x17ecb4 cmp r6, #0 */
/* @0x17ecb8 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17ecbc bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x17ecc0 ldr r3, [pc, #0x1e4] */
/* @0x17ecc4 cmp r7, #0 */
/* @0x17ecc8 ldreq r8, [r4, r3] */
/* @0x17eccc beq 0x17ed08 <_ZN8Graphics11SetMatricesEPfS0_S0_+0x78> */
/* @0x17ecd0 ldr r8, [r4, r3] */
/* @0x17ecd4 add r11, r7, #64 */
/* @0x17ecd8 mov lr, r7 */
/* @0x17ecdc mov r10, r8 */
/* @0x17ece0 ldr r0, [lr] */
/* @0x17ece4 add lr, lr, #16 */
/* @0x17ece8 ldr r1, [lr, #-0xc] */
/* @0x17ecec mov r12, r10 */
/* @0x17ecf0 ldr r2, [lr, #-0x8] */
/* @0x17ecf4 add r10, r10, #16 */
/* @0x17ecf8 ldr r3, [lr, #-0x4] */
/* @0x17ecfc cmp lr, r11 */
/* @0x17ed00 stm r12!, {r0, r1, r2, r3} */
/* @0x17ed04 bne 0x17ece0 <_ZN8Graphics11SetMatricesEPfS0_S0_+0x50> */
/* @0x17ed08 cmp r5, #0 */
/* @0x17ed0c beq 0x17ed44 <_ZN8Graphics11SetMatricesEPfS0_S0_+0xb4> */
/* @0x17ed10 add r10, r8, #64 */
/* @0x17ed14 add r11, r5, #64 */
/* @0x17ed18 mov lr, r5 */
/* @0x17ed1c ldr r0, [lr] */
/* @0x17ed20 add lr, lr, #16 */
/* @0x17ed24 ldr r1, [lr, #-0xc] */
/* @0x17ed28 mov r12, r10 */
/* @0x17ed2c ldr r2, [lr, #-0x8] */
/* @0x17ed30 add r10, r10, #16 */
/* @0x17ed34 ldr r3, [lr, #-0x4] */
/* @0x17ed38 cmp lr, r11 */
/* @0x17ed3c stm r12!, {r0, r1, r2, r3} */
/* @0x17ed40 bne 0x17ed1c <_ZN8Graphics11SetMatricesEPfS0_S0_+0x8c> */
/* @0x17ed44 cmp r9, #0 */
/* @0x17ed48 beq 0x17ee68 <_ZN8Graphics11SetMatricesEPfS0_S0_+0x1d8> */
/* @0x17ed4c mov r12, r9 */
/* @0x17ed50 add r7, r8, #128 */
/* @0x17ed54 add r9, r9, #64 */
/* @0x17ed58 ldr r0, [r12] */
/* @0x17ed5c add r12, r12, #16 */
/* @0x17ed60 ldr r1, [r12, #-0xc] */
/* @0x17ed64 mov lr, r7 */
/* @0x17ed68 ldr r2, [r12, #-0x8] */
/* @0x17ed6c add r7, r7, #16 */
/* @0x17ed70 ldr r3, [r12, #-0x4] */
/* @0x17ed74 cmp r12, r9 */
/* @0x17ed78 stm lr!, {r0, r1, r2, r3} */
/* @0x17ed7c bne 0x17ed58 <_ZN8Graphics11SetMatricesEPfS0_S0_+0xc8> */
/* @0x17ed80 add r7, r8, #192 */
/* @0x17ed84 add r1, r8, #128 */
/* @0x17ed88 mov r2, r8 */
/* @0x17ed8c mov r0, r7 */
/* @0x17ed90 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x17ed94 mov r1, r7 */
/* @0x17ed98 add r0, r8, #256 */
/* @0x17ed9c add r2, r8, #64 */
/* @0x17eda0 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x17eda4 ldr r3, [pc, #0x104] */
/* @0x17eda8 ldr r9, [r4, r3] */
/* @0x17edac ldr r3, [r9] */
/* @0x17edb0 cmp r3, #0 */
/* @0x17edb4 bne 0x17ee9c <_ZN8Graphics11SetMatricesEPfS0_S0_+0x20c> */
/* @0x17edb8 ldr r3, [pc, #0xf4] */
/* @0x17edbc mov r0, #5888 */
/* @0x17edc0 ldr r3, [r4, r3] */
/* @0x17edc4 ldr r3, [r3] */
/* @0x17edc8 blx r3 */
/* @0x17edcc ldr r3, [pc, #0xe4] */
/* @0x17edd0 mov r0, r7 */
/* @0x17edd4 ldr r3, [r4, r3] */
/* @0x17edd8 ldr r3, [r3] */
/* @0x17eddc blx r3 */
/* @0x17ede0 cmp r5, #0 */
/* @0x17ede4 beq 0x17ee10 <_ZN8Graphics11SetMatricesEPfS0_S0_+0x180> */
/* @0x17ede8 ldr r3, [pc, #0xc4] */
/* @0x17edec movw r0, #0x1701 */
/* @0x17edf0 ldr r3, [r4, r3] */
/* @0x17edf4 ldr r3, [r3] */
/* @0x17edf8 blx r3 */
/* @0x17edfc ldr r3, [pc, #0xb4] */
/* @0x17ee00 add r0, r8, #64 */
/* @0x17ee04 ldr r3, [r4, r3] */
/* @0x17ee08 ldr r3, [r3] */
/* @0x17ee0c blx r3 */
/* @0x17ee10 cmp r6, #0 */
/* @0x17ee14 bne 0x17ee9c <_ZN8Graphics11SetMatricesEPfS0_S0_+0x20c> */
/* @0x17ee18 cmp r5, #0 */
/* @0x17ee1c beq 0x17ee34 <_ZN8Graphics11SetMatricesEPfS0_S0_+0x1a4> */
/* @0x17ee20 ldr r3, [pc, #0x94] */
/* @0x17ee24 mov r0, #8 */
/* @0x17ee28 ldr r3, [r4, r3] */
/* @0x17ee2c ldr r1, [r3] */
/* @0x17ee30 bl 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej> */
/* @0x17ee34 ldr r3, [r9] */
/* @0x17ee38 cmp r3, #1 */
/* @0x17ee3c popne {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17ee40 ldr r3, [pc, #0x78] */
/* @0x17ee44 ldr r3, [r4, r3] */
/* @0x17ee48 ldr r3, [r3] */
/* @0x17ee4c cmp r3, #0 */
/* @0x17ee50 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17ee54 ldr r0, [r3, #0x6c] */
/* @0x17ee58 mov r2, r8 */
/* @0x17ee5c mov r1, #5 */
/* @0x17ee60 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17ee64 b 0x1889fc <_Z27Shader_Set_Uniform_Matrix_NiiPf> */
/* @0x17ee68 cmp r7, #0 */
/* @0x17ee6c bne 0x17ed80 <_ZN8Graphics11SetMatricesEPfS0_S0_+0xf0> */
/* @0x17ee70 add r0, r8, #256 */
/* @0x17ee74 add r1, r8, #192 */
/* @0x17ee78 add r2, r8, #64 */
/* @0x17ee7c bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x17ee80 ldr r3, [pc, #0x28] */
/* @0x17ee84 ldr r9, [r4, r3] */
/* @0x17ee88 ldr r3, [r9] */
/* @0x17ee8c cmp r3, #0 */
/* @0x17ee90 bne 0x17ee18 <_ZN8Graphics11SetMatricesEPfS0_S0_+0x188> */
/* @0x17ee94 mov r6, r7 */
/* @0x17ee98 b 0x17ede0 <_ZN8Graphics11SetMatricesEPfS0_S0_+0x150> */
/* @0x17ee9c bl 0x17fa9c <_Z19GR_3D_Light_Processv> */
/* @0x17eea0 b 0x17ee18 <_ZN8Graphics11SetMatricesEPfS0_S0_+0x188> */
/* @0x17eea4 eoreq r2, r7, r8, lsr #31 */
/* @0x17eea8 .word 0xffffe4d0 */
/* @0x17eeac .word 0xffffe824 */
/* @0x17eeb0 .word 0xffffe7b8 */
/* @0x17eeb4 .word 0xffffbc48 */
/* @0x17eeb8 .word 0xffffbc88 */
/* @0x17eebc .word 0xffffe82c */
/* @0x17eec0 .word 0xffffe828 */

/* ── FUNC 0x17eec4 · Graphics::Clear(unsigned int, float, int, eClearFlags) · size=1180 · insn=295 */
/* @0x17eec4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17eec8 mov r5, r3 */
/* @0x17eecc ldr r4, [pc, #0x43c] */
/* @0x17eed0 sub sp, sp, #268 */
/* @0x17eed4 ldr r6, [pc, #0x438] */
/* @0x17eed8 mov r7, r0 */
/* @0x17eedc add r4, pc, r4 */
/* @0x17eee0 mov r11, r1 */
/* @0x17eee4 mov r8, r2 */
/* @0x17eee8 ldr r3, [r4, r6] */
/* @0x17eeec ldrb r3, [r3] */
/* @0x17eef0 cmp r3, #0 */
/* @0x17eef4 beq 0x17ef00 <_ZN8Graphics5ClearEjfi11eClearFlags+0x3c> */
/* @0x17eef8 cmp r5, #0 */
/* @0x17eefc bne 0x17ef08 <_ZN8Graphics5ClearEjfi11eClearFlags+0x44> */
/* @0x17ef00 add sp, sp, #268 */
/* @0x17ef04 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17ef08 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x17ef0c ldr r3, [pc, #0x404] */
/* @0x17ef10 ldr r3, [r4, r3] */
/* @0x17ef14 ldrb r9, [r3] */
/* @0x17ef18 cmp r9, #0 */
/* @0x17ef1c bne 0x17f064 <_ZN8Graphics5ClearEjfi11eClearFlags+0x1a0> */
/* @0x17ef20 ldr r3, [pc, #0x3f4] */
/* @0x17ef24 ldr r6, [r4, r3] */
/* @0x17ef28 mov r0, r6 */
/* @0x17ef2c bl 0x167fcc <_ZN18RenderStateManager10SaveStatesEv> */
/* @0x17ef30 mov r0, r6 */
/* @0x17ef34 mov r1, #24 */
/* @0x17ef38 mov r2, #15 */
/* @0x17ef3c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17ef40 mov r2, r9 */
/* @0x17ef44 mov r0, r6 */
/* @0x17ef48 mov r1, #12 */
/* @0x17ef4c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17ef50 mov r0, r6 */
/* @0x17ef54 mov r1, #32 */
/* @0x17ef58 mvn r2, #0 */
/* @0x17ef5c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17ef60 mov r0, r6 */
/* @0x17ef64 mov r1, #4 */
/* @0x17ef68 mov r2, #1 */
/* @0x17ef6c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17ef70 mov r0, r6 */
/* @0x17ef74 mov r1, #25 */
/* @0x17ef78 mov r2, #1 */
/* @0x17ef7c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17ef80 ands r9, r5, #1 */
/* @0x17ef84 bne 0x17f284 <_ZN8Graphics5ClearEjfi11eClearFlags+0x3c0> */
/* @0x17ef88 tst r5, #2 */
/* @0x17ef8c bne 0x17f254 <_ZN8Graphics5ClearEjfi11eClearFlags+0x390> */
/* @0x17ef90 mov r0, r6 */
/* @0x17ef94 bl 0x168134 <_ZN18RenderStateManager5FlushEv> */
/* @0x17ef98 ldr r1, [pc, #0x380] */
/* @0x17ef9c movw r0, #0x8080 */
/* @0x17efa0 movt r0, #0xff80 */
/* @0x17efa4 add r1, pc, r1 */
/* @0x17efa8 bl 0x17b8f0 <_ZN12GraphicsPerf4PushEjPKc> */
/* @0x17efac ldr r3, [pc, #0x370] */
/* @0x17efb0 ldr r3, [r4, r3] */
/* @0x17efb4 ldr r3, [r3] */
/* @0x17efb8 cmp r3, #0 */
/* @0x17efbc bne 0x17f230 <_ZN8Graphics5ClearEjfi11eClearFlags+0x36c> */
/* @0x17efc0 ldr r3, [pc, #0x360] */
/* @0x17efc4 ldr r3, [r4, r3] */
/* @0x17efc8 ldr r3, [r3] */
/* @0x17efcc cmp r3, #0 */
/* @0x17efd0 bne 0x17f230 <_ZN8Graphics5ClearEjfi11eClearFlags+0x36c> */
/* @0x17efd4 ldr r2, [pc, #0x350] */
/* @0x17efd8 ldr r3, [pc, #0x350] */
/* @0x17efdc ldr r2, [r4, r2] */
/* @0x17efe0 ldr r3, [r4, r3] */
/* @0x17efe4 ldr r2, [r2] */
/* @0x17efe8 ldr r3, [r3] */
/* @0x17efec cmp r2, r3 */
/* @0x17eff0 beq 0x17f2fc <_ZN8Graphics5ClearEjfi11eClearFlags+0x438> */
/* @0x17eff4 ldr r1, [pc, #0x338] */
/* @0x17eff8 ldr r1, [r4, r1] */
/* @0x17effc ldr r1, [r1] */
/* @0x17f000 cmp r3, r1 */
/* @0x17f004 bne 0x17f230 <_ZN8Graphics5ClearEjfi11eClearFlags+0x36c> */
/* @0x17f008 ldr r1, [pc, #0x328] */
/* @0x17f00c ldr r1, [r4, r1] */
/* @0x17f010 ldr r1, [r1] */
/* @0x17f014 cmp r1, r3 */
/* @0x17f018 beq 0x17f024 <_ZN8Graphics5ClearEjfi11eClearFlags+0x160> */
/* @0x17f01c cmp r2, r1 */
/* @0x17f020 bne 0x17f230 <_ZN8Graphics5ClearEjfi11eClearFlags+0x36c> */
/* @0x17f024 ldr r3, [pc, #0x310] */
/* @0x17f028 movw r0, #0xc11 */
/* @0x17f02c ldr r3, [r4, r3] */
/* @0x17f030 ldr r3, [r3] */
/* @0x17f034 blx r3 */
/* @0x17f038 ldr r3, [pc, #0x300] */
/* @0x17f03c mov r0, r9 */
/* @0x17f040 ldr r3, [r4, r3] */
/* @0x17f044 ldr r3, [r3] */
/* @0x17f048 blx r3 */
/* @0x17f04c ldr r3, [pc, #0x2f0] */
/* @0x17f050 movw r0, #0xc11 */
/* @0x17f054 ldr r3, [r4, r3] */
/* @0x17f058 ldr r3, [r3] */
/* @0x17f05c blx r3 */
/* @0x17f060 b 0x17f244 <_ZN8Graphics5ClearEjfi11eClearFlags+0x380> */
/* @0x17f064 add r10, sp, #8 */
/* @0x17f068 add r9, sp, #72 */
/* @0x17f06c mov r0, #2 */
/* @0x17f070 add r8, sp, #136 */
/* @0x17f074 mov r1, r10 */
/* @0x17f078 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x17f07c mov r1, r9 */
/* @0x17f080 mov r0, #0 */
/* @0x17f084 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x17f088 mov r1, r8 */
/* @0x17f08c mov r0, #1 */
/* @0x17f090 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x17f094 ldr r3, [pc, #0x280] */
/* @0x17f098 ldr r6, [r4, r3] */
/* @0x17f09c mov r0, r6 */
/* @0x17f0a0 bl 0x167fcc <_ZN18RenderStateManager10SaveStatesEv> */
/* @0x17f0a4 ldr r3, [pc, #0x29c] */
/* @0x17f0a8 mov r0, #0 */
/* @0x17f0ac ldr r3, [r4, r3] */
/* @0x17f0b0 ldr r3, [r3] */
/* @0x17f0b4 str r3, [sp, #0x4] */
/* @0x17f0b8 bl 0x1e2024 <_Z10Shader_SetP6Shader> */
/* @0x17f0bc bl 0x1e1520 <_Z11FlushShaderv> */
/* @0x17f0c0 mov r0, r6 */
/* @0x17f0c4 mov r1, #1 */
/* @0x17f0c8 mov r2, #0 */
/* @0x17f0cc bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17f0d0 mov r0, r6 */
/* @0x17f0d4 mov r1, #12 */
/* @0x17f0d8 mov r2, #0 */
/* @0x17f0dc bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17f0e0 mov r0, r6 */
/* @0x17f0e4 mov r1, #5 */
/* @0x17f0e8 mov r2, #0 */
/* @0x17f0ec bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17f0f0 mov r0, r6 */
/* @0x17f0f4 mov r1, #21 */
/* @0x17f0f8 mov r2, #0 */
/* @0x17f0fc bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17f100 mov r0, r6 */
/* @0x17f104 mov r1, #8 */
/* @0x17f108 mov r2, #0 */
/* @0x17f10c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17f110 ands r2, r5, #1 */
/* @0x17f114 mov r0, r6 */
/* @0x17f118 mov r1, #24 */
/* @0x17f11c movne r2, #15 */
/* @0x17f120 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17f124 ands r2, r5, #2 */
/* @0x17f128 mov r0, r6 */
/* @0x17f12c mov r1, #4 */
/* @0x17f130 movne r2, #1 */
/* @0x17f134 mov r5, #1065353216 */
/* @0x17f138 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17f13c add r0, sp, #200 */
/* @0x17f140 mov r3, #0 */
/* @0x17f144 str r5, [sp, #0x104] */
/* @0x17f148 mov r1, r0 */
/* @0x17f14c mov r2, r0 */
/* @0x17f150 str r3, [sp, #0x100] */
/* @0x17f154 str r3, [sp, #0xfc] */
/* @0x17f158 str r3, [sp, #0xf8] */
/* @0x17f15c str r3, [sp, #0xf4] */
/* @0x17f160 str r3, [sp, #0xec] */
/* @0x17f164 str r3, [sp, #0xe8] */
/* @0x17f168 str r3, [sp, #0xe4] */
/* @0x17f16c str r3, [sp, #0xe0] */
/* @0x17f170 str r3, [sp, #0xd8] */
/* @0x17f174 str r3, [sp, #0xd4] */
/* @0x17f178 str r3, [sp, #0xd0] */
/* @0x17f17c str r3, [sp, #0xcc] */
/* @0x17f180 str r5, [sp, #0xf0] */
/* @0x17f184 str r5, [sp, #0xdc] */
/* @0x17f188 str r5, [sp, #0xc8] */
/* @0x17f18c bl 0x17ec90 <_ZN8Graphics11SetMatricesEPfS0_S0_> */
/* @0x17f190 mov r1, #0 */
/* @0x17f194 mov r2, #16 */
/* @0x17f198 mov r3, #4 */
/* @0x17f19c mov r0, #5 */
/* @0x17f1a0 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x17f1a4 mov r3, #0 */
/* @0x17f1a8 movt r3, #0xbf80 */
/* @0x17f1ac str r5, [r0, #0x14] */
/* @0x17f1b0 str r3, [r0] */
/* @0x17f1b4 str r3, [r0, #0x4] */
/* @0x17f1b8 str r3, [r0, #0x10] */
/* @0x17f1bc str r3, [r0, #0x24] */
/* @0x17f1c0 str r5, [r0, #0x20] */
/* @0x17f1c4 str r5, [r0, #0x30] */
/* @0x17f1c8 str r5, [r0, #0x34] */
/* @0x17f1cc str r11, [r0, #0x38] */
/* @0x17f1d0 str r11, [r0, #0x28] */
/* @0x17f1d4 str r11, [r0, #0x18] */
/* @0x17f1d8 str r11, [r0, #0x8] */
/* @0x17f1dc str r7, [r0, #0x3c] */
/* @0x17f1e0 str r7, [r0, #0x2c] */
/* @0x17f1e4 str r7, [r0, #0x1c] */
/* @0x17f1e8 str r7, [r0, #0xc] */
/* @0x17f1ec bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x17f1f0 mov r0, r6 */
/* @0x17f1f4 bl 0x168050 <_ZN18RenderStateManager13RestoreStatesEv> */
/* @0x17f1f8 mov r0, r10 */
/* @0x17f1fc mov r1, r9 */
/* @0x17f200 mov r2, r8 */
/* @0x17f204 bl 0x17ec90 <_ZN8Graphics11SetMatricesEPfS0_S0_> */
/* @0x17f208 ldr r0, [sp, #0x4] */
/* @0x17f20c bl 0x1e2024 <_Z10Shader_SetP6Shader> */
/* @0x17f210 bl 0x1e1520 <_Z11FlushShaderv> */
/* @0x17f214 ldr r3, [pc, #0x130] */
/* @0x17f218 ldr r3, [r4, r3] */
/* @0x17f21c ldr r2, [r3] */
/* @0x17f220 add r2, r2, #1 */
/* @0x17f224 str r2, [r3] */
/* @0x17f228 add sp, sp, #268 */
/* @0x17f22c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17f230 ldr r3, [pc, #0x108] */
/* @0x17f234 mov r0, r9 */
/* @0x17f238 ldr r3, [r4, r3] */
/* @0x17f23c ldr r3, [r3] */
/* @0x17f240 blx r3 */
/* @0x17f244 bl 0x17bb10 <_ZN12GraphicsPerf3PopEv> */
/* @0x17f248 mov r0, r6 */
/* @0x17f24c bl 0x168050 <_ZN18RenderStateManager13RestoreStatesEv> */
/* @0x17f250 b 0x17f214 <_ZN8Graphics5ClearEjfi11eClearFlags+0x350> */
/* @0x17f254 ldr r3, [pc, #0xf4] */
/* @0x17f258 mov r0, #1065353216 */
/* @0x17f25c orr r9, r9, #1280 */
/* @0x17f260 ldr r3, [r4, r3] */
/* @0x17f264 ldr r3, [r3] */
/* @0x17f268 blx r3 */
/* @0x17f26c ldr r3, [pc, #0xe0] */
/* @0x17f270 mov r0, r8 */
/* @0x17f274 ldr r3, [r4, r3] */
/* @0x17f278 ldr r3, [r3] */
/* @0x17f27c blx r3 */
/* @0x17f280 b 0x17ef90 <_ZN8Graphics5ClearEjfi11eClearFlags+0xcc> */
/* @0x17f284 uxtb r2, r7 */
/* @0x17f288 vldr s15, [pc, #124] */
/* @0x17f28c ldr r3, [pc, #0xc4] */
/* @0x17f290 mov r9, #16384 */
/* @0x17f294 vmov s11, r2 */
/* @0x17f298 ubfx r2, r7, #0x8, #0x8 */
/* @0x17f29c vmov s12, r2 */
/* @0x17f2a0 ubfx r2, r7, #0x10, #0x8 */
/* @0x17f2a4 vcvt.f32.s32 s11, s11 */
/* @0x17f2a8 vmov s13, r2 */
/* @0x17f2ac lsr r2, r7, #24 */
/* @0x17f2b0 vmov s14, r2 */
/* @0x17f2b4 ldr r2, [r4, r3] */
/* @0x17f2b8 ldr r3, [pc, #0x9c] */
/* @0x17f2bc str r7, [r2] */
/* @0x17f2c0 vcvt.f32.s32 s12, s12 */
/* @0x17f2c4 ldr r3, [r4, r3] */
/* @0x17f2c8 ldr r12, [r3] */
/* @0x17f2cc vcvt.f32.s32 s13, s13 */
/* @0x17f2d0 vcvt.f32.u32 s14, s14 */
/* @0x17f2d4 vdiv.f32 s11, s11, s15 */
/* @0x17f2d8 vdiv.f32 s12, s12, s15 */
/* @0x17f2dc vmov r0, s11 */
/* @0x17f2e0 vdiv.f32 s13, s13, s15 */
/* @0x17f2e4 vmov r1, s12 */
/* @0x17f2e8 vdiv.f32 s14, s14, s15 */
/* @0x17f2ec vmov r2, s13 */
/* @0x17f2f0 vmov r3, s14 */
/* @0x17f2f4 blx r12 */
/* @0x17f2f8 b 0x17ef88 <_ZN8Graphics5ClearEjfi11eClearFlags+0xc4> */
/* @0x17f2fc ldr r3, [pc, #0x30] */
/* @0x17f300 ldr r3, [r4, r3] */
/* @0x17f304 ldr r3, [r3] */
/* @0x17f308 b 0x17f008 <_ZN8Graphics5ClearEjfi11eClearFlags+0x144> */
/* @0x17f30c cmnmi pc, #0 */
/* @0x17f310 eoreq r2, r7, r4, ror sp */
/* @0x17f314 .word 0xffffe4d0 */
/* @0x17f318 .word 0xffffe830 */
/* @0x17f31c .word 0xffffc0a8 */
/* @0x17f320 ldrsheq r12, [r12], -r8 */
/* @0x17f324 .word 0xffffe80c */
/* @0x17f328 .word 0xffffe810 */
/* @0x17f32c .word 0xffffe814 */
/* @0x17f330 .word 0xffffe834 */
/* @0x17f334 .word 0xffffe818 */
/* @0x17f338 .word 0xffffe838 */
/* @0x17f33c .word 0xffffbad0 */
/* @0x17f340 .word 0xffffbacc */
/* @0x17f344 .word 0xffffbad8 */
/* @0x17f348 .word 0xffffe828 */
/* @0x17f34c .word 0xffffe83c */
/* @0x17f350 .word 0xffffbb04 */
/* @0x17f354 .word 0xffffbb08 */
/* @0x17f358 .word 0xffffe840 */
/* @0x17f35c .word 0xffffbb00 */

/* ── FUNC 0x17f360 · Graphics::FogType() · size=8 · insn=2 */
/* @0x17f360 mov r0, #1 */
/* @0x17f364 bx lr */

/* ── FUNC 0x17f368 · Graphics::GetTimerFreq() · size=12 · insn=3 */
/* @0x17f368 mov r0, #0 */
/* @0x17f36c mov r1, #0 */
/* @0x17f370 bx lr */

/* ── FUNC 0x17f374 · Graphics::GetTimer() · size=12 · insn=3 */
/* @0x17f374 mov r0, #0 */
/* @0x17f378 mov r1, #0 */
/* @0x17f37c bx lr */

/* ── FUNC 0x17f380 · Graphics::GetTiming() · size=4 · insn=1 */
/* @0x17f380 bx lr */

/* ── FUNC 0x17f384 · Graphics::DrawNumber(float, float, float, int) · size=4 · insn=1 */
/* @0x17f384 bx lr */

/* ── FUNC 0x17f388 · Graphics::DrawChar(float, float, float, int) · size=4 · insn=1 */
/* @0x17f388 bx lr */

/* ── FUNC 0x17f38c · Graphics::Init() · size=16 · insn=4 */
/* @0x17f38c push {r3, lr} */
/* @0x17f390 bl 0x17f368 <_ZN8Graphics12GetTimerFreqEv> */
/* @0x17f394 pop {r3, lr} */
/* @0x17f398 b 0x17afa0 <_ZN12GraphicsPerf4InitEv> */

/* ── FUNC 0x17f39c · Graphics::DrawQuad(Texture*, float, float, float, float, float, float, float, float, unsigned int) · size=224 · insn=56 */
/* @0x17f39c mov r12, r0 */
/* @0x17f3a0 mov r0, #4 */
/* @0x17f3a4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17f3a8 vpush {d8} */
/* @0x17f3ac mov r6, r1 */
/* @0x17f3b0 vldr s16, [sp, #48] */
/* @0x17f3b4 mov r5, r2 */
/* @0x17f3b8 mov r7, r3 */
/* @0x17f3bc mov r1, r12 */
/* @0x17f3c0 mov r3, #6 */
/* @0x17f3c4 mov r2, #24 */
/* @0x17f3c8 ldr r4, [sp, #0x44] */
/* @0x17f3cc ldr r9, [sp, #0x34] */
/* @0x17f3d0 ldr r8, [sp, #0x38] */
/* @0x17f3d4 ldr r11, [sp, #0x3c] */
/* @0x17f3d8 ldr r10, [sp, #0x40] */
/* @0x17f3dc bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x17f3e0 mov r3, #0 */
/* @0x17f3e4 vstr s16, [r0, #52] */
/* @0x17f3e8 vstr s16, [r0, #76] */
/* @0x17f3ec vstr s16, [r0, #100] */
/* @0x17f3f0 str r6, [r0] */
/* @0x17f3f4 str r4, [r0, #0x84] */
/* @0x17f3f8 str r5, [r0, #0x4] */
/* @0x17f3fc str r4, [r0, #0x6c] */
/* @0x17f400 str r7, [r0, #0x18] */
/* @0x17f404 str r4, [r0, #0x54] */
/* @0x17f408 str r5, [r0, #0x1c] */
/* @0x17f40c str r4, [r0, #0x3c] */
/* @0x17f410 str r7, [r0, #0x30] */
/* @0x17f414 str r4, [r0, #0x24] */
/* @0x17f418 str r4, [r0, #0xc] */
/* @0x17f41c str r7, [r0, #0x48] */
/* @0x17f420 str r6, [r0, #0x60] */
/* @0x17f424 str r6, [r0, #0x78] */
/* @0x17f428 str r5, [r0, #0x7c] */
/* @0x17f42c str r9, [r0, #0x10] */
/* @0x17f430 str r8, [r0, #0x14] */
/* @0x17f434 str r11, [r0, #0x28] */
/* @0x17f438 str r8, [r0, #0x2c] */
/* @0x17f43c str r11, [r0, #0x40] */
/* @0x17f440 str r10, [r0, #0x44] */
/* @0x17f444 str r11, [r0, #0x58] */
/* @0x17f448 str r10, [r0, #0x5c] */
/* @0x17f44c str r9, [r0, #0x70] */
/* @0x17f450 str r3, [r0, #0x80] */
/* @0x17f454 str r3, [r0, #0x68] */
/* @0x17f458 str r3, [r0, #0x50] */
/* @0x17f45c str r3, [r0, #0x38] */
/* @0x17f460 str r3, [r0, #0x20] */
/* @0x17f464 str r3, [r0, #0x8] */
/* @0x17f468 str r10, [r0, #0x74] */
/* @0x17f46c str r9, [r0, #0x88] */
/* @0x17f470 str r8, [r0, #0x8c] */
/* @0x17f474 vpop {d8} */
/* @0x17f478 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x17f47c · GR_3D_Light_Set_Ambient() · size=72 · insn=18 */
/* @0x17f47c push {r3, lr} */
/* @0x17f480 ldr r3, [pc, #0x30] */
/* @0x17f484 ldr r3, [pc, r3] */
/* @0x17f488 ldr r3, [r3] */
/* @0x17f48c cmp r3, #0 */
/* @0x17f490 popne {r3, pc} */
/* @0x17f494 ldr r3, [pc, #0x20] */
/* @0x17f498 movw r0, #0x408 */
/* @0x17f49c ldr r2, [pc, #0x1c] */
/* @0x17f4a0 mov r1, #5632 */
/* @0x17f4a4 ldr r3, [pc, r3] */
/* @0x17f4a8 ldr r2, [pc, r2] */
/* @0x17f4ac ldr r3, [r3] */
/* @0x17f4b0 blx r3 */
/* @0x17f4b4 pop {r3, pc} */
/* @0x17f4b8 eoreq r0, r7, r4, lsl #31 */
/* @0x17f4bc eoreq lr, r6, r8, lsr r4 */
/* @0x17f4c0 eoreq r0, r7, r12, ror #31 */

/* ── FUNC 0x17f4c4 · GR_3D_Light_Update(int) · size=312 · insn=78 */
/* @0x17f4c4 push {r4, r5, r6, r7, lr} */
/* @0x17f4c8 mov r6, r0 */
/* @0x17f4cc ldr r4, [pc, #0xf8] */
/* @0x17f4d0 sub sp, sp, #68 */
/* @0x17f4d4 ldr r3, [pc, #0xf4] */
/* @0x17f4d8 add r4, pc, r4 */
/* @0x17f4dc ldr r3, [r4, r3] */
/* @0x17f4e0 ldr r5, [r3] */
/* @0x17f4e4 cmp r5, #0 */
/* @0x17f4e8 bne 0x17f5c4 <_Z18GR_3D_Light_Updatei+0x100> */
/* @0x17f4ec ldr r3, [pc, #0xe0] */
/* @0x17f4f0 mov r0, #5888 */
/* @0x17f4f4 lsl r7, r6, #4 */
/* @0x17f4f8 ldr r3, [r4, r3] */
/* @0x17f4fc ldr r3, [r3] */
/* @0x17f500 blx r3 */
/* @0x17f504 ldr r3, [pc, #0xcc] */
/* @0x17f508 ldr r3, [r4, r3] */
/* @0x17f50c ldr r3, [r3] */
/* @0x17f510 blx r3 */
/* @0x17f514 mov r0, r5 */
/* @0x17f518 mov r1, sp */
/* @0x17f51c bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x17f520 ldr r3, [pc, #0xb4] */
/* @0x17f524 mov r0, sp */
/* @0x17f528 ldr r3, [r4, r3] */
/* @0x17f52c ldr r3, [r3] */
/* @0x17f530 blx r3 */
/* @0x17f534 vmov.f32 s14, #1.000000e+00 */
/* @0x17f538 ldr r0, [pc, #0xa0] */
/* @0x17f53c movw r1, #0x1208 */
/* @0x17f540 ldr r2, [pc, #0x9c] */
/* @0x17f544 ldr r3, [pc, #0x9c] */
/* @0x17f548 ldr r0, [r4, r0] */
/* @0x17f54c ldr r2, [r4, r2] */
/* @0x17f550 ldr r3, [r4, r3] */
/* @0x17f554 ldr r5, [r0, r6, lsl #2] */
/* @0x17f558 add r6, r2, r6, lsl #2 */
/* @0x17f55c vldr s15, [r6] */
/* @0x17f560 ldr r3, [r3] */
/* @0x17f564 vdiv.f32 s15, s14, s15 */
/* @0x17f568 mov r0, r5 */
/* @0x17f56c vmov r2, s15 */
/* @0x17f570 blx r3 */
/* @0x17f574 ldr r2, [pc, #0x70] */
/* @0x17f578 ldr r3, [pc, #0x70] */
/* @0x17f57c mov r0, r5 */
/* @0x17f580 movw r1, #0x1201 */
/* @0x17f584 ldr r6, [r4, r2] */
/* @0x17f588 ldr r2, [r4, r3] */
/* @0x17f58c ldr r3, [r6] */
/* @0x17f590 add r2, r2, r7 */
/* @0x17f594 blx r3 */
/* @0x17f598 ldr r2, [pc, #0x54] */
/* @0x17f59c ldr r3, [r6] */
/* @0x17f5a0 mov r0, r5 */
/* @0x17f5a4 movw r1, #0x1203 */
/* @0x17f5a8 ldr r2, [r4, r2] */
/* @0x17f5ac add r2, r2, r7 */
/* @0x17f5b0 blx r3 */
/* @0x17f5b4 ldr r3, [pc, #0x3c] */
/* @0x17f5b8 ldr r3, [r4, r3] */
/* @0x17f5bc ldr r3, [r3] */
/* @0x17f5c0 blx r3 */
/* @0x17f5c4 add sp, sp, #68 */
/* @0x17f5c8 pop {r4, r5, r6, r7, pc} */
/* @0x17f5cc eoreq r2, r7, r8, ror r7 */
/* @0x17f5d0 .word 0xffffe7b8 */
/* @0x17f5d4 .word 0xffffbc48 */
/* @0x17f5d8 .word 0xffffbc58 */
/* @0x17f5dc .word 0xffffbc88 */
/* @0x17f5e0 .word 0xffffe848 */
/* @0x17f5e4 .word 0xffffe84c */
/* @0x17f5e8 .word 0xffffbc90 */
/* @0x17f5ec .word 0xffffbc94 */
/* @0x17f5f0 .word 0xffffe850 */
/* @0x17f5f4 .word 0xffffe854 */
/* @0x17f5f8 .word 0xffffbc54 */

/* ── FUNC 0x17f5fc · GR_3D_Set_Ambient(unsigned int) · size=92 · insn=23 */
/* @0x17f5fc ubfx r3, r0, #0x8, #0x8 */
/* @0x17f600 vldr s15, [pc, #72] */
/* @0x17f604 mov r2, #1065353216 */
/* @0x17f608 vmov s14, r3 */
/* @0x17f60c uxtb r3, r0 */
/* @0x17f610 ubfx r0, r0, #0x10, #0x8 */
/* @0x17f614 vmov s12, r3 */
/* @0x17f618 ldr r3, [pc, #0x34] */
/* @0x17f61c vmov s11, r0 */
/* @0x17f620 vcvt.f32.s32 s14, s14 */
/* @0x17f624 ldr r3, [pc, r3] */
/* @0x17f628 str r2, [r3, #0xc] */
/* @0x17f62c vcvt.f32.s32 s12, s12 */
/* @0x17f630 vcvt.f32.s32 s13, s11 */
/* @0x17f634 vdiv.f32 s12, s12, s15 */
/* @0x17f638 vdiv.f32 s14, s14, s15 */
/* @0x17f63c vstr s12, [r3] */
/* @0x17f640 vdiv.f32 s15, s13, s15 */
/* @0x17f644 vstr s14, [r3, #4] */
/* @0x17f648 vstr s15, [r3, #8] */
/* @0x17f64c b 0x17f47c <_Z23GR_3D_Light_Set_Ambientv> */
/* @0x17f650 cmnmi pc, #0 */
/* @0x17f654 eoreq r0, r7, r0, ror lr */

/* ── FUNC 0x17f658 · GR_3D_Light_Define_Direction(int, float, float, float, unsigned int) · size=400 · insn=100 */
/* @0x17f658 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x17f65c vldr s15, [pc, #352] */
/* @0x17f660 and r0, r0, #7 */
/* @0x17f664 ldr r4, [sp, #0x20] */
/* @0x17f668 ldr r12, [pc, #0x160] */
/* @0x17f66c ubfx r5, r4, #0x8, #0x8 */
/* @0x17f670 ldr r6, [pc, #0x15c] */
/* @0x17f674 add r12, pc, r12 */
/* @0x17f678 vmov s14, r5 */
/* @0x17f67c uxtb r5, r4 */
/* @0x17f680 ubfx r4, r4, #0x10, #0x8 */
/* @0x17f684 vmov s12, r5 */
/* @0x17f688 lsl r5, r0, #2 */
/* @0x17f68c vcvt.f32.s32 s14, s14 */
/* @0x17f690 add r7, r5, #1 */
/* @0x17f694 vmov s13, r4 */
/* @0x17f698 ldr r4, [r12, r6] */
/* @0x17f69c lsl r7, r7, #2 */
/* @0x17f6a0 lsl r6, r0, #4 */
/* @0x17f6a4 add r10, r4, r7 */
/* @0x17f6a8 add r11, r4, r6 */
/* @0x17f6ac add r9, r5, #2 */
/* @0x17f6b0 add r8, r5, #3 */
/* @0x17f6b4 lsl r9, r9, #2 */
/* @0x17f6b8 lsl r8, r8, #2 */
/* @0x17f6bc vcvt.f32.s32 s12, s12 */
/* @0x17f6c0 vdiv.f32 s14, s14, s15 */
/* @0x17f6c4 vdiv.f32 s12, s12, s15 */
/* @0x17f6c8 vcvt.f32.s32 s13, s13 */
/* @0x17f6cc vstr s12, [r11] */
/* @0x17f6d0 vstr s14, [r10] */
/* @0x17f6d4 ldr r11, [pc, #0xfc] */
/* @0x17f6d8 add r10, r4, r9 */
/* @0x17f6dc add r4, r4, r8 */
/* @0x17f6e0 vdiv.f32 s15, s13, s15 */
/* @0x17f6e4 vmov.f32 s14, #1.000000e+00 */
/* @0x17f6e8 vstr s15, [r10] */
/* @0x17f6ec vstr s14, [r4] */
/* @0x17f6f0 ldr r4, [r12, r11] */
/* @0x17f6f4 ldr r4, [r4] */
/* @0x17f6f8 cmp r4, #0 */
/* @0x17f6fc bne 0x17f764 <_Z28GR_3D_Light_Define_Directionifffj+0x10c> */
/* @0x17f700 vmov s12, r1 */
/* @0x17f704 ldr r10, [pc, #0xd0] */
/* @0x17f708 ldr r4, [pc, #0xd0] */
/* @0x17f70c vldr s13, [pc, #180] */
/* @0x17f710 vneg.f32 s15, s12 */
/* @0x17f714 mov r11, #9216 */
/* @0x17f718 vmov s12, r2 */
/* @0x17f71c ldr r1, [r12, r10] */
/* @0x17f720 movt r11, #0x4974 */
/* @0x17f724 add r6, r1, r6 */
/* @0x17f728 add r7, r1, r7 */
/* @0x17f72c vneg.f32 s14, s12 */
/* @0x17f730 vstr s15, [r6] */
/* @0x17f734 vmov s12, r3 */
/* @0x17f738 add r9, r1, r9 */
/* @0x17f73c add r8, r1, r8 */
/* @0x17f740 vneg.f32 s15, s12 */
/* @0x17f744 vstr s14, [r7] */
/* @0x17f748 vstr s15, [r9] */
/* @0x17f74c vstr s13, [r8] */
/* @0x17f750 ldr r3, [r12, r4] */
/* @0x17f754 add r5, r3, r5 */
/* @0x17f758 str r11, [r5] */
/* @0x17f75c pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x17f760 b 0x17f4c4 <_Z18GR_3D_Light_Updatei> */
/* @0x17f764 cmp r4, #1 */
/* @0x17f768 bne 0x17f75c <_Z28GR_3D_Light_Define_Directionifffj+0x104> */
/* @0x17f76c ldr r4, [pc, #0x68] */
/* @0x17f770 vldr s14, [pc, #80] */
/* @0x17f774 ldr r11, [pc, #0x64] */
/* @0x17f778 vldr s15, [pc, #76] */
/* @0x17f77c ldr r10, [pc, #0x60] */
/* @0x17f780 ldr r4, [r12, r4] */
/* @0x17f784 add r6, r4, r6 */
/* @0x17f788 add r7, r4, r7 */
/* @0x17f78c add r9, r4, r9 */
/* @0x17f790 add r8, r4, r8 */
/* @0x17f794 str r1, [r6] */
/* @0x17f798 str r2, [r7] */
/* @0x17f79c mov r2, #0 */
/* @0x17f7a0 str r3, [r9] */
/* @0x17f7a4 vstr s14, [r8] */
/* @0x17f7a8 ldr r3, [r12, r11] */
/* @0x17f7ac add r5, r3, r5 */
/* @0x17f7b0 vstr s15, [r5] */
/* @0x17f7b4 ldr r3, [r12, r10] */
/* @0x17f7b8 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x17f7bc str r2, [r3, r0, lsl #2] */
/* @0x17f7c0 b 0x17f4c4 <_Z18GR_3D_Light_Updatei> */
/* @0x17f7c4 cmnmi pc, #0 */
/* @0x17f7c8 andeq r0, r0, r0 */
/* @0x17f7cc ldmdbmi r4!, {r10, sp} ^ */
/* @0x17f7d0 .word 0x002725dc */
/* @0x17f7d4 .word 0xffffe850 */
/* @0x17f7d8 .word 0xffffe7b8 */
/* @0x17f7dc .word 0xffffe854 */
/* @0x17f7e0 .word 0xffffe84c */
/* @0x17f7e4 .word 0xffffe858 */

/* ── FUNC 0x17f7e8 · GR_3D_Light_Define_Point(int, float, float, float, float, unsigned int) · size=312 · insn=78 */
/* @0x17f7e8 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x17f7ec vldr s15, [pc, #272] */
/* @0x17f7f0 and r0, r0, #7 */
/* @0x17f7f4 vldr s13, [sp, #32] */
/* @0x17f7f8 ldr r4, [sp, #0x24] */
/* @0x17f7fc vcmpe.f32 s13, #0 */
/* @0x17f800 ldr r12, [pc, #0x100] */
/* @0x17f804 lsl r10, r0, #4 */
/* @0x17f808 ubfx r5, r4, #0x8, #0x8 */
/* @0x17f80c uxtb r6, r4 */
/* @0x17f810 ubfx r4, r4, #0x10, #0x8 */
/* @0x17f814 vmov s14, r5 */
/* @0x17f818 ldr r5, [pc, #0xec] */
/* @0x17f81c vmov s11, r6 */
/* @0x17f820 add r12, pc, r12 */
/* @0x17f824 vcvt.f32.s32 s14, s14 */
/* @0x17f828 lsl r6, r0, #2 */
/* @0x17f82c vmov s12, r4 */
/* @0x17f830 add r9, r6, #1 */
/* @0x17f834 ldr r5, [r12, r5] */
/* @0x17f838 add r8, r6, #2 */
/* @0x17f83c lsl r9, r9, #2 */
/* @0x17f840 add r7, r6, #3 */
/* @0x17f844 add r11, r5, r9 */
/* @0x17f848 add r4, r5, r10 */
/* @0x17f84c lsl r8, r8, #2 */
/* @0x17f850 lsl r7, r7, #2 */
/* @0x17f854 vmrs APSR_nzcv, fpscr */
/* @0x17f858 vcvt.f32.s32 s11, s11 */
/* @0x17f85c vdiv.f32 s14, s14, s15 */
/* @0x17f860 vdiv.f32 s11, s11, s15 */
/* @0x17f864 vcvt.f32.s32 s12, s12 */
/* @0x17f868 vstr s11, [r4] */
/* @0x17f86c vstr s14, [r11] */
/* @0x17f870 ldr r4, [pc, #0x98] */
/* @0x17f874 add r11, r5, r8 */
/* @0x17f878 add r5, r5, r7 */
/* @0x17f87c vdiv.f32 s15, s12, s15 */
/* @0x17f880 vmov.f32 s14, #1.000000e+00 */
/* @0x17f884 vstr s15, [r11] */
/* @0x17f888 vstr s14, [r5] */
/* @0x17f88c ldr r4, [r12, r4] */
/* @0x17f890 add r10, r4, r10 */
/* @0x17f894 add r9, r4, r9 */
/* @0x17f898 add r8, r4, r8 */
/* @0x17f89c add r4, r4, r7 */
/* @0x17f8a0 str r1, [r10] */
/* @0x17f8a4 str r2, [r9] */
/* @0x17f8a8 movwle r2, #0x126f */
/* @0x17f8ac str r3, [r8] */
/* @0x17f8b0 vstr s14, [r4] */
/* @0x17f8b4 ldr r3, [pc, #0x58] */
/* @0x17f8b8 movtle r2, #0x3a83 */
/* @0x17f8bc ldrgt r3, [r12, r3] */
/* @0x17f8c0 ldrle r3, [r12, r3] */
/* @0x17f8c4 addgt r6, r3, r6 */
/* @0x17f8c8 vstrgt s13, [r6] */
/* @0x17f8cc addle r6, r3, r6 */
/* @0x17f8d0 ldr r3, [pc, #0x40] */
/* @0x17f8d4 strle r2, [r6] */
/* @0x17f8d8 ldr r3, [r12, r3] */
/* @0x17f8dc ldr r3, [r3] */
/* @0x17f8e0 cmp r3, #1 */
/* @0x17f8e4 beq 0x17f8f0 <_Z24GR_3D_Light_Define_Pointiffffj+0x108> */
/* @0x17f8e8 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x17f8ec b 0x17f4c4 <_Z18GR_3D_Light_Updatei> */
/* @0x17f8f0 ldr r2, [pc, #0x24] */
/* @0x17f8f4 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x17f8f8 ldr r2, [r12, r2] */
/* @0x17f8fc str r3, [r2, r0, lsl #2] */
/* @0x17f900 b 0x17f4c4 <_Z18GR_3D_Light_Updatei> */
/* @0x17f904 cmnmi pc, #0 */
/* @0x17f908 eoreq r2, r7, r0, lsr r4 */
/* @0x17f90c .word 0xffffe850 */
/* @0x17f910 .word 0xffffe854 */
/* @0x17f914 .word 0xffffe84c */
/* @0x17f918 .word 0xffffe7b8 */
/* @0x17f91c .word 0xffffe858 */

/* ── FUNC 0x17f920 · GR_3D_Light_Enable(int, bool) · size=380 · insn=95 */
/* @0x17f920 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17f924 mov r5, r0 */
/* @0x17f928 ldr r4, [pc, #0x140] */
/* @0x17f92c mov r7, r1 */
/* @0x17f930 ldr r3, [pc, #0x13c] */
/* @0x17f934 add r4, pc, r4 */
/* @0x17f938 ldr r6, [r4, r3] */
/* @0x17f93c ldr r3, [r6] */
/* @0x17f940 cmp r3, #0 */
/* @0x17f944 bne 0x17f98c <_Z18GR_3D_Light_Enableib+0x6c> */
/* @0x17f948 ldr r3, [pc, #0x128] */
/* @0x17f94c and r5, r0, #7 */
/* @0x17f950 cmp r1, #0 */
/* @0x17f954 mov r12, #1 */
/* @0x17f958 ldr r3, [r4, r3] */
/* @0x17f95c ldr r0, [r3, r5, lsl #2] */
/* @0x17f960 ldr r3, [pc, #0x114] */
/* @0x17f964 bne 0x17fa5c <_Z18GR_3D_Light_Enableib+0x13c> */
/* @0x17f968 ldr r3, [r4, r3] */
/* @0x17f96c ldr r2, [pc, #0x10c] */
/* @0x17f970 ldr r1, [r3] */
/* @0x17f974 bic r1, r1, r12, lsl r5 */
/* @0x17f978 str r1, [r3] */
/* @0x17f97c ldr r3, [r4, r2] */
/* @0x17f980 ldr r3, [r3] */
/* @0x17f984 blx r3 */
/* @0x17f988 ldr r3, [r6] */
/* @0x17f98c cmp r3, #1 */
/* @0x17f990 popne {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17f994 ldr r2, [pc, #0xe0] */
/* @0x17f998 and r5, r5, #7 */
/* @0x17f99c cmp r7, #0 */
/* @0x17f9a0 ldr r9, [pc, #0xdc] */
/* @0x17f9a4 mov r0, #1 */
/* @0x17f9a8 ldr r2, [r4, r2] */
/* @0x17f9ac ldr r1, [r2] */
/* @0x17f9b0 orrne r5, r1, r3, lsl r5 */
/* @0x17f9b4 biceq r5, r1, r3, lsl r5 */
/* @0x17f9b8 ldr r3, [pc, #0xc8] */
/* @0x17f9bc mov r1, #0 */
/* @0x17f9c0 str r5, [r2] */
/* @0x17f9c4 mov r6, r1 */
/* @0x17f9c8 mov r2, r1 */
/* @0x17f9cc mov r8, r1 */
/* @0x17f9d0 ldr r10, [r4, r3] */
/* @0x17f9d4 mov r7, r1 */
/* @0x17f9d8 mov r12, r1 */
/* @0x17f9dc mov r3, r1 */
/* @0x17f9e0 str r1, [r10] */
/* @0x17f9e4 ldr r9, [r4, r9] */
/* @0x17f9e8 str r1, [r9] */
/* @0x17f9ec ands r11, r5, r0, lsl r3 */
/* @0x17f9f0 ldr r1, [pc, #0x94] */
/* @0x17f9f4 beq 0x17fa24 <_Z18GR_3D_Light_Enableib+0x104> */
/* @0x17f9f8 ldr r1, [r4, r1] */
/* @0x17f9fc mov r2, r3 */
/* @0x17fa00 ldr r1, [r1, r3, lsl #2] */
/* @0x17fa04 cmp r1, #0 */
/* @0x17fa08 addeq r6, r12, #1 */
/* @0x17fa0c moveq r12, r6 */
/* @0x17fa10 beq 0x17fa24 <_Z18GR_3D_Light_Enableib+0x104> */
/* @0x17fa14 cmp r1, #1 */
/* @0x17fa18 mov r2, r3 */
/* @0x17fa1c addeq r8, r7, #1 */
/* @0x17fa20 moveq r7, r8 */
/* @0x17fa24 add r3, r3, #1 */
/* @0x17fa28 cmp r3, #8 */
/* @0x17fa2c bne 0x17f9ec <_Z18GR_3D_Light_Enableib+0xcc> */
/* @0x17fa30 ldr r1, [pc, #0x58] */
/* @0x17fa34 str r2, [r10] */
/* @0x17fa38 str r6, [r9] */
/* @0x17fa3c ldr r3, [pc, #0x50] */
/* @0x17fa40 ldr r2, [r4, r1] */
/* @0x17fa44 str r8, [r2] */
/* @0x17fa48 ldr r3, [r4, r3] */
/* @0x17fa4c cmp r7, r12 */
/* @0x17fa50 strhs r7, [r3] */
/* @0x17fa54 strlo r12, [r3] */
/* @0x17fa58 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17fa5c ldr r3, [r4, r3] */
/* @0x17fa60 ldr r2, [pc, #0x30] */
/* @0x17fa64 ldr r1, [r3] */
/* @0x17fa68 orr r1, r1, r12, lsl r5 */
/* @0x17fa6c b 0x17f978 <_Z18GR_3D_Light_Enableib+0x58> */
/* @0x17fa70 eoreq r2, r7, r12, lsl r3 */
/* @0x17fa74 .word 0xffffe7b8 */
/* @0x17fa78 .word 0xffffe848 */
/* @0x17fa7c .word 0xffffe85c */
/* @0x17fa80 .word 0xffffbad0 */
/* @0x17fa84 .word 0xffffe860 */
/* @0x17fa88 .word 0xffffe864 */
/* @0x17fa8c .word 0xffffe858 */
/* @0x17fa90 .word 0xffffe868 */
/* @0x17fa94 .word 0xffffe86c */
/* @0x17fa98 .word 0xffffbad8 */

/* ── FUNC 0x17fa9c · GR_3D_Light_Process() · size=212 · insn=53 */
/* @0x17fa9c push {r4, r5, r6, r7, r8, lr} */
/* @0x17faa0 sub sp, sp, #64 */
/* @0x17faa4 ldr r6, [pc, #0xa4] */
/* @0x17faa8 ldr r3, [pc, #0xa4] */
/* @0x17faac add r6, pc, r6 */
/* @0x17fab0 ldr r3, [r6, r3] */
/* @0x17fab4 ldr r4, [r3] */
/* @0x17fab8 cmp r4, #0 */
/* @0x17fabc beq 0x17fac8 <_Z19GR_3D_Light_Processv+0x2c> */
/* @0x17fac0 add sp, sp, #64 */
/* @0x17fac4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x17fac8 ldr r3, [pc, #0x88] */
/* @0x17facc ldr r3, [r6, r3] */
/* @0x17fad0 ldr r3, [r3] */
/* @0x17fad4 blx r3 */
/* @0x17fad8 mov r0, r4 */
/* @0x17fadc mov r1, sp */
/* @0x17fae0 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x17fae4 ldr r3, [pc, #0x70] */
/* @0x17fae8 mov r0, sp */
/* @0x17faec ldr r3, [r6, r3] */
/* @0x17faf0 ldr r3, [r3] */
/* @0x17faf4 blx r3 */
/* @0x17faf8 ldr r1, [pc, #0x60] */
/* @0x17fafc ldr r2, [pc, #0x60] */
/* @0x17fb00 ldr r3, [pc, #0x60] */
/* @0x17fb04 ldr r7, [r6, r1] */
/* @0x17fb08 ldr r5, [r6, r2] */
/* @0x17fb0c ldr r8, [r6, r3] */
/* @0x17fb10 sub r4, r7, #4 */
/* @0x17fb14 add r7, r7, #28 */
/* @0x17fb18 ldr r0, [r4, #0x4]! */
/* @0x17fb1c mov r2, r5 */
/* @0x17fb20 movw r1, #0x1203 */
/* @0x17fb24 ldr r3, [r8] */
/* @0x17fb28 blx r3 */
/* @0x17fb2c cmp r4, r7 */
/* @0x17fb30 add r5, r5, #16 */
/* @0x17fb34 bne 0x17fb18 <_Z19GR_3D_Light_Processv+0x7c> */
/* @0x17fb38 ldr r3, [pc, #0x2c] */
/* @0x17fb3c ldr r3, [r6, r3] */
/* @0x17fb40 ldr r3, [r3] */
/* @0x17fb44 blx r3 */
/* @0x17fb48 add sp, sp, #64 */
/* @0x17fb4c pop {r4, r5, r6, r7, r8, pc} */
/* @0x17fb50 eoreq r2, r7, r4, lsr #3 */
/* @0x17fb54 .word 0xffffe7b8 */
/* @0x17fb58 .word 0xffffbc58 */
/* @0x17fb5c .word 0xffffbc88 */
/* @0x17fb60 .word 0xffffe848 */
/* @0x17fb64 .word 0xffffe854 */
/* @0x17fb68 .word 0xffffbc94 */
/* @0x17fb6c .word 0xffffbc54 */

/* ── FUNC 0x17fb70 · GR_D3D_Lights_Resume() · size=148 · insn=37 */
/* @0x17fb70 push {r3, r4, r5, r6, r7, lr} */
/* @0x17fb74 ldr r5, [pc, #0x74] */
/* @0x17fb78 ldr r3, [pc, #0x74] */
/* @0x17fb7c add r5, pc, r5 */
/* @0x17fb80 ldr r3, [r5, r3] */
/* @0x17fb84 ldr r4, [r3] */
/* @0x17fb88 cmp r4, #0 */
/* @0x17fb8c popne {r3, r4, r5, r6, r7, pc} */
/* @0x17fb90 ldr r3, [pc, #0x60] */
/* @0x17fb94 mov r7, #1 */
/* @0x17fb98 ldr r6, [r5, r3] */
/* @0x17fb9c b 0x17fbac <_Z20GR_D3D_Lights_Resumev+0x3c> */
/* @0x17fba0 add r4, r4, #1 */
/* @0x17fba4 cmp r4, #8 */
/* @0x17fba8 beq 0x17fbe8 <_Z20GR_D3D_Lights_Resumev+0x78> */
/* @0x17fbac ldr r3, [r6] */
/* @0x17fbb0 ands r3, r3, r7, lsl r4 */
/* @0x17fbb4 beq 0x17fba0 <_Z20GR_D3D_Lights_Resumev+0x30> */
/* @0x17fbb8 ldr r3, [pc, #0x3c] */
/* @0x17fbbc ldr r2, [pc, #0x3c] */
/* @0x17fbc0 ldr r3, [r5, r3] */
/* @0x17fbc4 ldr r2, [r5, r2] */
/* @0x17fbc8 ldr r3, [r3] */
/* @0x17fbcc ldr r0, [r2, r4, lsl #2] */
/* @0x17fbd0 blx r3 */
/* @0x17fbd4 mov r0, r4 */
/* @0x17fbd8 add r4, r4, #1 */
/* @0x17fbdc bl 0x17f4c4 <_Z18GR_3D_Light_Updatei> */
/* @0x17fbe0 cmp r4, #8 */
/* @0x17fbe4 bne 0x17fbac <_Z20GR_D3D_Lights_Resumev+0x3c> */
/* @0x17fbe8 pop {r3, r4, r5, r6, r7, lr} */
/* @0x17fbec b 0x17f47c <_Z23GR_3D_Light_Set_Ambientv> */
/* @0x17fbf0 .word 0x002720d4 */
/* @0x17fbf4 .word 0xffffe7b8 */
/* @0x17fbf8 .word 0xffffe85c */
/* @0x17fbfc .word 0xffffbad8 */
/* @0x17fc00 .word 0xffffe848 */

/* ── FUNC 0x17fc04 · Graphics::PushRenderStates() · size=4 · insn=1 */
/* @0x17fc04 bx lr */

/* ── FUNC 0x17fc08 · Graphics::PopRenderStates() · size=4 · insn=1 */
/* @0x17fc08 bx lr */

/* ── FUNC 0x17fc0c · ConvertBlend(eBlend, int*) · size=48 · insn=12 */
/* @0x17fc0c sub r0, r0, #2 */
/* @0x17fc10 mvn r3, #0 */
/* @0x17fc14 cmp r0, #9 */
/* @0x17fc18 str r3, [r1] */
/* @0x17fc1c bhi 0x17fc30 <_Z12ConvertBlend6eBlendPi+0x24> */
/* @0x17fc20 ldr r3, [pc, #0x10] */
/* @0x17fc24 add r3, pc, r3 */
/* @0x17fc28 ldr r0, [r3, r0, lsl #2] */
/* @0x17fc2c bx lr */
/* @0x17fc30 mov r0, #0 */
/* @0x17fc34 bx lr */
/* @0x17fc38 andseq sp, sp, r8, lsr #30 */

/* ── FUNC 0x17fc3c · ConvertComparison(eCmpFunc) · size=44 · insn=11 */
/* @0x17fc3c sub r0, r0, #1 */
/* @0x17fc40 cmp r0, #6 */
/* @0x17fc44 bhi 0x17fc5c <_Z17ConvertComparison8eCmpFunc+0x20> */
/* @0x17fc48 ldr r3, [pc, #0x14] */
/* @0x17fc4c add r3, pc, r3 */
/* @0x17fc50 add r0, r3, r0, lsl #2 */
/* @0x17fc54 ldr r0, [r0, #0x28] */
/* @0x17fc58 bx lr */
/* @0x17fc5c movw r0, #0x207 */
/* @0x17fc60 bx lr */
/* @0x17fc64 andseq sp, sp, r0, lsl #30 */

/* ── FUNC 0x17fc68 · ConvertCull(eCull) · size=96 · insn=24 */
/* @0x17fc68 cmp r0, #1 */
/* @0x17fc6c beq 0x17fca0 <_Z11ConvertCull5eCull+0x38> */
/* @0x17fc70 cmp r0, #2 */
/* @0x17fc74 bne 0x17fc98 <_Z11ConvertCull5eCull+0x30> */
/* @0x17fc78 ldr r3, [pc, #0x40] */
/* @0x17fc7c movw r2, #0x901 */
/* @0x17fc80 ldr r3, [pc, r3] */
/* @0x17fc84 ldr r0, [r3] */
/* @0x17fc88 cmp r0, #1 */
/* @0x17fc8c movne r0, r2 */
/* @0x17fc90 moveq r0, #2304 */
/* @0x17fc94 bx lr */
/* @0x17fc98 mvn r0, #0 */
/* @0x17fc9c bx lr */
/* @0x17fca0 ldr r3, [pc, #0x1c] */
/* @0x17fca4 movw r2, #0x901 */
/* @0x17fca8 ldr r3, [pc, r3] */
/* @0x17fcac ldr r0, [r3] */
/* @0x17fcb0 cmp r0, #1 */
/* @0x17fcb4 moveq r0, r2 */
/* @0x17fcb8 movne r0, #2304 */
/* @0x17fcbc bx lr */
/* @0x17fcc0 eoreq r0, r7, r12, asr r4 */
/* @0x17fcc4 eoreq r0, r7, r4, lsr r4 */

/* ── FUNC 0x17fcc8 · ConvertFogMode(eFog) · size=44 · insn=11 */
/* @0x17fcc8 cmp r0, #2 */
/* @0x17fccc bhi 0x17fce4 <_Z14ConvertFogMode4eFog+0x1c> */
/* @0x17fcd0 ldr r3, [pc, #0x18] */
/* @0x17fcd4 add r3, pc, r3 */
/* @0x17fcd8 add r0, r3, r0, lsl #2 */
/* @0x17fcdc ldr r0, [r0, #0x44] */
/* @0x17fce0 bx lr */
/* @0x17fce4 mov r0, #1024 */
/* @0x17fce8 movt r0, #0x4618 */
/* @0x17fcec bx lr */
/* @0x17fcf0 andseq sp, sp, r8, ror lr */

/* ── FUNC 0x17fcf4 · Graphics::SetSamplerStateEx(int, int, unsigned int) · size=4 · insn=1 */
/* @0x17fcf4 bx lr */

/* ── FUNC 0x17fcf8 · ConvertStencilOp(eStencilOp) · size=44 · insn=11 */
/* @0x17fcf8 sub r0, r0, #2 */
/* @0x17fcfc cmp r0, #6 */
/* @0x17fd00 bhi 0x17fd18 <_Z16ConvertStencilOp10eStencilOp+0x20> */
/* @0x17fd04 ldr r3, [pc, #0x14] */
/* @0x17fd08 add r3, pc, r3 */
/* @0x17fd0c add r0, r3, r0, lsl #2 */
/* @0x17fd10 ldr r0, [r0, #0x50] */
/* @0x17fd14 bx lr */
/* @0x17fd18 mov r0, #7680 */
/* @0x17fd1c bx lr */
/* @0x17fd20 andseq sp, sp, r4, asr #28 */
