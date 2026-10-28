/* libyoyo.so 覆盖卡组 0297
 * 函数 0x31b134..0x31ba7c，共 13 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x31b134 · __eqsf2 · alias of the symbol above · insn=0 */

/* ── FUNC 0x31b134 · __nesf2 · alias of the symbol above · insn=0 */

/* ── FUNC 0x31b198 · __aeabi_cfrcmple · size=36 · insn=4 */
/* @0x31b198 mov r12, r0 */
/* @0x31b19c mov r0, r1 */
/* @0x31b1a0 mov r1, r12 */
/* @0x31b1a4 b 0x31b1a8 <__aeabi_cfcmple> */

/* ── FUNC 0x31b1a8 · __aeabi_cfcmpeq · size=20 · insn=5 */
/* @0x31b1a8 push {r0, r1, r2, r3, lr} */
/* @0x31b1ac bl 0x31b134 <__nesf2> */
/* @0x31b1b0 cmp r0, #0 */
/* @0x31b1b4 cmnmi r0, #0 */
/* @0x31b1b8 pop {r0, r1, r2, r3, pc} */

/* ── FUNC 0x31b1a8 · __aeabi_cfcmple · alias of the symbol above · insn=0 */

/* ── FUNC 0x31b1bc · __aeabi_fcmpeq · size=20 · insn=5 */
/* @0x31b1bc str lr, [sp, #-0x8]! */
/* @0x31b1c0 bl 0x31b1a8 <__aeabi_cfcmple> */
/* @0x31b1c4 moveq r0, #1 */
/* @0x31b1c8 movne r0, #0 */
/* @0x31b1cc ldr pc, [sp], #8 */

/* ── FUNC 0x31b1d0 · __aeabi_fcmplt · size=20 · insn=5 */
/* @0x31b1d0 str lr, [sp, #-0x8]! */
/* @0x31b1d4 bl 0x31b1a8 <__aeabi_cfcmple> */
/* @0x31b1d8 movlo r0, #1 */
/* @0x31b1dc movhs r0, #0 */
/* @0x31b1e0 ldr pc, [sp], #8 */

/* ── FUNC 0x31b1e4 · __aeabi_fcmple · size=20 · insn=5 */
/* @0x31b1e4 str lr, [sp, #-0x8]! */
/* @0x31b1e8 bl 0x31b1a8 <__aeabi_cfcmple> */
/* @0x31b1ec movls r0, #1 */
/* @0x31b1f0 movhi r0, #0 */
/* @0x31b1f4 ldr pc, [sp], #8 */

/* ── FUNC 0x31b1f8 · __aeabi_fcmpge · size=20 · insn=5 */
/* @0x31b1f8 str lr, [sp, #-0x8]! */
/* @0x31b1fc bl 0x31b198 <__aeabi_cfrcmple> */
/* @0x31b200 movls r0, #1 */
/* @0x31b204 movhi r0, #0 */
/* @0x31b208 ldr pc, [sp], #8 */

/* ── FUNC 0x31b20c · __aeabi_fcmpgt · size=20 · insn=5 */
/* @0x31b20c str lr, [sp, #-0x8]! */
/* @0x31b210 bl 0x31b198 <__aeabi_cfrcmple> */
/* @0x31b214 movlo r0, #1 */
/* @0x31b218 movhs r0, #0 */
/* @0x31b21c ldr pc, [sp], #8 */

/* ── FUNC 0x31b220 · __divdi3 · size=1144 · insn=286 */
/* @0x31b220 cmp r1, #0 */
/* @0x31b224 mov r12, r2 */
/* @0x31b228 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x31b22c mov r5, r0 */
/* @0x31b230 sub sp, sp, #20 */
/* @0x31b234 mov r7, r1 */
/* @0x31b238 mov r8, r3 */
/* @0x31b23c movge r4, #0 */
/* @0x31b240 bge 0x31b258 <__divdi3+0x38> */
/* @0x31b244 rsbs r0, r0, #0 */
/* @0x31b248 rsc r1, r1, #0 */
/* @0x31b24c mvn r4, #0 */
/* @0x31b250 mov r5, r0 */
/* @0x31b254 mov r7, r1 */
/* @0x31b258 cmp r3, #0 */
/* @0x31b25c bge 0x31b274 <__divdi3+0x54> */
/* @0x31b260 rsbs r2, r2, #0 */
/* @0x31b264 rsc r3, r3, #0 */
/* @0x31b268 mvn r4, r4 */
/* @0x31b26c mov r12, r2 */
/* @0x31b270 mov r8, r3 */
/* @0x31b274 cmp r8, #0 */
/* @0x31b278 mov r6, r12 */
/* @0x31b27c mov r9, r5 */
/* @0x31b280 mov r10, r7 */
/* @0x31b284 bne 0x31b514 <__divdi3+0x2f4> */
/* @0x31b288 cmp r12, r7 */
/* @0x31b28c bls 0x31b354 <__divdi3+0x134> */
/* @0x31b290 clz r3, r12 */
/* @0x31b294 cmp r3, #0 */
/* @0x31b298 lslne r6, r12, r3 */
/* @0x31b29c rsbne r2, r3, #32 */
/* @0x31b2a0 lsrne r2, r5, r2 */
/* @0x31b2a4 lslne r9, r5, r3 */
/* @0x31b2a8 orrne r10, r2, r7, lsl r3 */
/* @0x31b2ac lsr r5, r6, #16 */
/* @0x31b2b0 uxth r8, r6 */
/* @0x31b2b4 mov r0, r10 */
/* @0x31b2b8 mov r1, r5 */
/* @0x31b2bc bl 0x318c48 <__udivsi3> */
/* @0x31b2c0 mov r1, r5 */
/* @0x31b2c4 mov r7, r0 */
/* @0x31b2c8 mul r11, r8, r0 */
/* @0x31b2cc mov r0, r10 */
/* @0x31b2d0 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b2d4 lsr r3, r9, #16 */
/* @0x31b2d8 orr r1, r3, r1, lsl #16 */
/* @0x31b2dc cmp r1, r11 */
/* @0x31b2e0 movhs r10, r7 */
/* @0x31b2e4 bhs 0x31b300 <__divdi3+0xe0> */
/* @0x31b2e8 adds r1, r1, r6 */
/* @0x31b2ec sub r10, r7, #1 */
/* @0x31b2f0 bhs 0x31b300 <__divdi3+0xe0> */
/* @0x31b2f4 cmp r1, r11 */
/* @0x31b2f8 sublo r10, r7, #2 */
/* @0x31b2fc addlo r1, r1, r6 */
/* @0x31b300 rsb r11, r11, r1 */
/* @0x31b304 mov r1, r5 */
/* @0x31b308 uxth r9, r9 */
/* @0x31b30c mov r0, r11 */
/* @0x31b310 bl 0x318c48 <__udivsi3> */
/* @0x31b314 mov r1, r5 */
/* @0x31b318 mov r7, r0 */
/* @0x31b31c mul r8, r8, r0 */
/* @0x31b320 mov r0, r11 */
/* @0x31b324 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b328 orr r1, r9, r1, lsl #16 */
/* @0x31b32c cmp r1, r8 */
/* @0x31b330 movhs r12, r7 */
/* @0x31b334 bhs 0x31b34c <__divdi3+0x12c> */
/* @0x31b338 adds r6, r1, r6 */
/* @0x31b33c sub r12, r7, #1 */
/* @0x31b340 bhs 0x31b34c <__divdi3+0x12c> */
/* @0x31b344 cmp r6, r8 */
/* @0x31b348 sublo r12, r7, #2 */
/* @0x31b34c orr r12, r12, r10, lsl #16 */
/* @0x31b350 b 0x31b668 <__divdi3+0x448> */
/* @0x31b354 cmp r12, #0 */
/* @0x31b358 bne 0x31b36c <__divdi3+0x14c> */
/* @0x31b35c mov r0, #1 */
/* @0x31b360 mov r1, r8 */
/* @0x31b364 bl 0x318c48 <__udivsi3> */
/* @0x31b368 mov r6, r0 */
/* @0x31b36c clz r3, r6 */
/* @0x31b370 cmp r3, #0 */
/* @0x31b374 rsbeq r3, r6, r7 */
/* @0x31b378 moveq r5, #1 */
/* @0x31b37c beq 0x31b45c <__divdi3+0x23c> */
/* @0x31b380 lsl r6, r6, r3 */
/* @0x31b384 rsb r1, r3, #32 */
/* @0x31b388 lsr r2, r7, r1 */
/* @0x31b38c lsr r1, r5, r1 */
/* @0x31b390 lsr r8, r6, #16 */
/* @0x31b394 orr r7, r1, r7, lsl r3 */
/* @0x31b398 mov r0, r2 */
/* @0x31b39c lsl r9, r5, r3 */
/* @0x31b3a0 mov r1, r8 */
/* @0x31b3a4 str r2, [sp, #0x4] */
/* @0x31b3a8 bl 0x318c48 <__udivsi3> */
/* @0x31b3ac uxth r11, r6 */
/* @0x31b3b0 ldr r2, [sp, #0x4] */
/* @0x31b3b4 mov r1, r8 */
/* @0x31b3b8 mul r12, r11, r0 */
/* @0x31b3bc mov r10, r0 */
/* @0x31b3c0 mov r0, r2 */
/* @0x31b3c4 str r12, [sp, #0xc] */
/* @0x31b3c8 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b3cc lsr r3, r7, #16 */
/* @0x31b3d0 ldr r12, [sp, #0xc] */
/* @0x31b3d4 orr r1, r3, r1, lsl #16 */
/* @0x31b3d8 cmp r1, r12 */
/* @0x31b3dc movhs r5, r10 */
/* @0x31b3e0 bhs 0x31b3fc <__divdi3+0x1dc> */
/* @0x31b3e4 adds r1, r1, r6 */
/* @0x31b3e8 sub r5, r10, #1 */
/* @0x31b3ec bhs 0x31b3fc <__divdi3+0x1dc> */
/* @0x31b3f0 cmp r1, r12 */
/* @0x31b3f4 sublo r5, r10, #2 */
/* @0x31b3f8 addlo r1, r1, r6 */
/* @0x31b3fc rsb r3, r12, r1 */
/* @0x31b400 mov r1, r8 */
/* @0x31b404 str r3, [sp, #0x8] */
/* @0x31b408 uxth r7, r7 */
/* @0x31b40c mov r0, r3 */
/* @0x31b410 bl 0x318c48 <__udivsi3> */
/* @0x31b414 ldr r3, [sp, #0x8] */
/* @0x31b418 mov r1, r8 */
/* @0x31b41c mov r10, r0 */
/* @0x31b420 mul r11, r11, r0 */
/* @0x31b424 mov r0, r3 */
/* @0x31b428 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b42c orr r1, r7, r1, lsl #16 */
/* @0x31b430 cmp r1, r11 */
/* @0x31b434 movhs r2, r10 */
/* @0x31b438 bhs 0x31b454 <__divdi3+0x234> */
/* @0x31b43c adds r1, r1, r6 */
/* @0x31b440 sub r2, r10, #1 */
/* @0x31b444 bhs 0x31b454 <__divdi3+0x234> */
/* @0x31b448 cmp r1, r11 */
/* @0x31b44c sublo r2, r10, #2 */
/* @0x31b450 addlo r1, r1, r6 */
/* @0x31b454 rsb r3, r11, r1 */
/* @0x31b458 orr r5, r2, r5, lsl #16 */
/* @0x31b45c lsr r8, r6, #16 */
/* @0x31b460 mov r0, r3 */
/* @0x31b464 str r3, [sp, #0x8] */
/* @0x31b468 uxth r10, r6 */
/* @0x31b46c mov r1, r8 */
/* @0x31b470 bl 0x318c48 <__udivsi3> */
/* @0x31b474 ldr r3, [sp, #0x8] */
/* @0x31b478 mov r1, r8 */
/* @0x31b47c mov r11, r0 */
/* @0x31b480 mul r7, r10, r0 */
/* @0x31b484 mov r0, r3 */
/* @0x31b488 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b48c lsr r3, r9, #16 */
/* @0x31b490 orr r1, r3, r1, lsl #16 */
/* @0x31b494 cmp r1, r7 */
/* @0x31b498 movhs r2, r11 */
/* @0x31b49c bhs 0x31b4b8 <__divdi3+0x298> */
/* @0x31b4a0 adds r1, r1, r6 */
/* @0x31b4a4 sub r2, r11, #1 */
/* @0x31b4a8 bhs 0x31b4b8 <__divdi3+0x298> */
/* @0x31b4ac cmp r1, r7 */
/* @0x31b4b0 sublo r2, r11, #2 */
/* @0x31b4b4 addlo r1, r1, r6 */
/* @0x31b4b8 rsb r11, r7, r1 */
/* @0x31b4bc mov r1, r8 */
/* @0x31b4c0 str r2, [sp, #0x4] */
/* @0x31b4c4 uxth r9, r9 */
/* @0x31b4c8 mov r0, r11 */
/* @0x31b4cc bl 0x318c48 <__udivsi3> */
/* @0x31b4d0 mov r1, r8 */
/* @0x31b4d4 mov r7, r0 */
/* @0x31b4d8 mul r10, r10, r0 */
/* @0x31b4dc mov r0, r11 */
/* @0x31b4e0 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b4e4 ldr r2, [sp, #0x4] */
/* @0x31b4e8 orr r1, r9, r1, lsl #16 */
/* @0x31b4ec cmp r1, r10 */
/* @0x31b4f0 movhs r12, r7 */
/* @0x31b4f4 bhs 0x31b50c <__divdi3+0x2ec> */
/* @0x31b4f8 adds r6, r1, r6 */
/* @0x31b4fc sub r12, r7, #1 */
/* @0x31b500 bhs 0x31b50c <__divdi3+0x2ec> */
/* @0x31b504 cmp r6, r10 */
/* @0x31b508 sublo r12, r7, #2 */
/* @0x31b50c orr r12, r12, r2, lsl #16 */
/* @0x31b510 b 0x31b678 <__divdi3+0x458> */
/* @0x31b514 cmp r8, r7 */
/* @0x31b518 bhi 0x31b670 <__divdi3+0x450> */
/* @0x31b51c clz r9, r8 */
/* @0x31b520 cmp r9, #0 */
/* @0x31b524 bne 0x31b548 <__divdi3+0x328> */
/* @0x31b528 cmp r7, r8 */
/* @0x31b52c cmpls r5, r12 */
/* @0x31b530 movlo r5, #0 */
/* @0x31b534 movhs r5, #1 */
/* @0x31b538 movhs r12, #1 */
/* @0x31b53c movhs r5, r9 */
/* @0x31b540 bhs 0x31b678 <__divdi3+0x458> */
/* @0x31b544 b 0x31b674 <__divdi3+0x454> */
/* @0x31b548 rsb r3, r9, #32 */
/* @0x31b54c lsl r10, r12, r9 */
/* @0x31b550 lsr r6, r12, r3 */
/* @0x31b554 lsr r2, r7, r3 */
/* @0x31b558 orr r6, r6, r8, lsl r9 */
/* @0x31b55c lsr r3, r5, r3 */
/* @0x31b560 mov r0, r2 */
/* @0x31b564 orr r7, r3, r7, lsl r9 */
/* @0x31b568 lsr r8, r6, #16 */
/* @0x31b56c str r2, [sp, #0x4] */
/* @0x31b570 uxth r11, r6 */
/* @0x31b574 mov r1, r8 */
/* @0x31b578 bl 0x318c48 <__udivsi3> */
/* @0x31b57c ldr r2, [sp, #0x4] */
/* @0x31b580 mov r1, r8 */
/* @0x31b584 mul r12, r11, r0 */
/* @0x31b588 mov r3, r0 */
/* @0x31b58c mov r0, r2 */
/* @0x31b590 str r3, [sp, #0x8] */
/* @0x31b594 str r12, [sp, #0xc] */
/* @0x31b598 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b59c lsr r2, r7, #16 */
/* @0x31b5a0 ldr r12, [sp, #0xc] */
/* @0x31b5a4 ldr r3, [sp, #0x8] */
/* @0x31b5a8 orr r1, r2, r1, lsl #16 */
/* @0x31b5ac cmp r1, r12 */
/* @0x31b5b0 movhs r2, r3 */
/* @0x31b5b4 bhs 0x31b5d0 <__divdi3+0x3b0> */
/* @0x31b5b8 adds r1, r1, r6 */
/* @0x31b5bc sub r2, r3, #1 */
/* @0x31b5c0 bhs 0x31b5d0 <__divdi3+0x3b0> */
/* @0x31b5c4 cmp r1, r12 */
/* @0x31b5c8 sublo r2, r3, #2 */
/* @0x31b5cc addlo r1, r1, r6 */
/* @0x31b5d0 rsb r12, r12, r1 */
/* @0x31b5d4 mov r1, r8 */
/* @0x31b5d8 str r2, [sp, #0x4] */
/* @0x31b5dc uxth r7, r7 */
/* @0x31b5e0 mov r0, r12 */
/* @0x31b5e4 str r12, [sp, #0xc] */
/* @0x31b5e8 bl 0x318c48 <__udivsi3> */
/* @0x31b5ec ldr r12, [sp, #0xc] */
/* @0x31b5f0 mov r1, r8 */
/* @0x31b5f4 mov r3, r0 */
/* @0x31b5f8 str r3, [sp, #0x8] */
/* @0x31b5fc mul r11, r11, r0 */
/* @0x31b600 mov r0, r12 */
/* @0x31b604 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b608 ldmib sp, {r2, r3} */
/* @0x31b60c orr r1, r7, r1, lsl #16 */
/* @0x31b610 cmp r1, r11 */
/* @0x31b614 movhs r12, r3 */
/* @0x31b618 bhs 0x31b634 <__divdi3+0x414> */
/* @0x31b61c adds r1, r1, r6 */
/* @0x31b620 sub r12, r3, #1 */
/* @0x31b624 bhs 0x31b634 <__divdi3+0x414> */
/* @0x31b628 cmp r1, r11 */
/* @0x31b62c sublo r12, r3, #2 */
/* @0x31b630 addlo r1, r1, r6 */
/* @0x31b634 orr r12, r12, r2, lsl #16 */
/* @0x31b638 rsb r11, r11, r1 */
/* @0x31b63c umull r2, r3, r12, r10 */
/* @0x31b640 cmp r3, r11 */
/* @0x31b644 bhi 0x31b664 <__divdi3+0x444> */
/* @0x31b648 movne r3, #0 */
/* @0x31b64c moveq r3, #1 */
/* @0x31b650 cmp r2, r5, lsl r9 */
/* @0x31b654 movls r5, #0 */
/* @0x31b658 andhi r5, r3, #1 */
/* @0x31b65c cmp r5, #0 */
/* @0x31b660 beq 0x31b678 <__divdi3+0x458> */
/* @0x31b664 sub r12, r12, #1 */
/* @0x31b668 mov r5, #0 */
/* @0x31b66c b 0x31b678 <__divdi3+0x458> */
/* @0x31b670 mov r5, #0 */
/* @0x31b674 mov r12, r5 */
/* @0x31b678 cmp r4, #0 */
/* @0x31b67c mov r0, r12 */
/* @0x31b680 mov r1, r5 */
/* @0x31b684 beq 0x31b690 <__divdi3+0x470> */
/* @0x31b688 rsbs r0, r0, #0 */
/* @0x31b68c rsc r1, r1, #0 */
/* @0x31b690 add sp, sp, #20 */
/* @0x31b694 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x31b698 · __udivdi3 · size=996 · insn=249 */
/* @0x31b698 cmp r3, #0 */
/* @0x31b69c push {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x31b6a0 mov r6, r0 */
/* @0x31b6a4 mov r5, r1 */
/* @0x31b6a8 mov r4, r2 */
/* @0x31b6ac mov r7, r0 */
/* @0x31b6b0 mov r8, r1 */
/* @0x31b6b4 bne 0x31b91c <__udivdi3+0x284> */
/* @0x31b6b8 cmp r2, r1 */
/* @0x31b6bc bls 0x31b784 <__udivdi3+0xec> */
/* @0x31b6c0 clz r3, r2 */
/* @0x31b6c4 cmp r3, #0 */
/* @0x31b6c8 rsbne r8, r3, #32 */
/* @0x31b6cc lslne r4, r2, r3 */
/* @0x31b6d0 lsrne r8, r0, r8 */
/* @0x31b6d4 lslne r7, r0, r3 */
/* @0x31b6d8 orrne r8, r8, r1, lsl r3 */
/* @0x31b6dc lsr r5, r4, #16 */
/* @0x31b6e0 uxth r9, r4 */
/* @0x31b6e4 mov r0, r8 */
/* @0x31b6e8 mov r1, r5 */
/* @0x31b6ec bl 0x318c48 <__udivsi3> */
/* @0x31b6f0 mov r1, r5 */
/* @0x31b6f4 mov r6, r0 */
/* @0x31b6f8 mul r10, r9, r0 */
/* @0x31b6fc mov r0, r8 */
/* @0x31b700 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b704 lsr r3, r7, #16 */
/* @0x31b708 orr r1, r3, r1, lsl #16 */
/* @0x31b70c cmp r1, r10 */
/* @0x31b710 movhs r8, r6 */
/* @0x31b714 bhs 0x31b730 <__udivdi3+0x98> */
/* @0x31b718 adds r1, r1, r4 */
/* @0x31b71c sub r8, r6, #1 */
/* @0x31b720 bhs 0x31b730 <__udivdi3+0x98> */
/* @0x31b724 cmp r1, r10 */
/* @0x31b728 sublo r8, r6, #2 */
/* @0x31b72c addlo r1, r1, r4 */
/* @0x31b730 rsb r10, r10, r1 */
/* @0x31b734 mov r1, r5 */
/* @0x31b738 uxth r7, r7 */
/* @0x31b73c mov r0, r10 */
/* @0x31b740 bl 0x318c48 <__udivsi3> */
/* @0x31b744 mov r1, r5 */
/* @0x31b748 mov r6, r0 */
/* @0x31b74c mul r9, r9, r0 */
/* @0x31b750 mov r0, r10 */
/* @0x31b754 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b758 orr r1, r7, r1, lsl #16 */
/* @0x31b75c cmp r1, r9 */
/* @0x31b760 movhs r0, r6 */
/* @0x31b764 bhs 0x31b77c <__udivdi3+0xe4> */
/* @0x31b768 adds r4, r1, r4 */
/* @0x31b76c sub r0, r6, #1 */
/* @0x31b770 bhs 0x31b77c <__udivdi3+0xe4> */
/* @0x31b774 cmp r4, r9 */
/* @0x31b778 sublo r0, r6, #2 */
/* @0x31b77c orr r0, r0, r8, lsl #16 */
/* @0x31b780 b 0x31ba60 <__udivdi3+0x3c8> */
/* @0x31b784 cmp r2, #0 */
/* @0x31b788 bne 0x31b79c <__udivdi3+0x104> */
/* @0x31b78c mov r0, #1 */
/* @0x31b790 mov r1, r2 */
/* @0x31b794 bl 0x318c48 <__udivsi3> */
/* @0x31b798 mov r4, r0 */
/* @0x31b79c clz r3, r4 */
/* @0x31b7a0 cmp r3, #0 */
/* @0x31b7a4 rsbeq r10, r4, r5 */
/* @0x31b7a8 moveq r5, #1 */
/* @0x31b7ac beq 0x31b874 <__udivdi3+0x1dc> */
/* @0x31b7b0 lsl r4, r4, r3 */
/* @0x31b7b4 rsb r9, r3, #32 */
/* @0x31b7b8 lsr r11, r5, r9 */
/* @0x31b7bc lsl r7, r6, r3 */
/* @0x31b7c0 lsr r9, r6, r9 */
/* @0x31b7c4 lsr r6, r4, #16 */
/* @0x31b7c8 mov r0, r11 */
/* @0x31b7cc orr r9, r9, r5, lsl r3 */
/* @0x31b7d0 mov r1, r6 */
/* @0x31b7d4 uxth r10, r4 */
/* @0x31b7d8 bl 0x318c48 <__udivsi3> */
/* @0x31b7dc mov r1, r6 */
/* @0x31b7e0 mov r8, r0 */
/* @0x31b7e4 mul r5, r10, r0 */
/* @0x31b7e8 mov r0, r11 */
/* @0x31b7ec bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b7f0 lsr r3, r9, #16 */
/* @0x31b7f4 orr r1, r3, r1, lsl #16 */
/* @0x31b7f8 cmp r1, r5 */
/* @0x31b7fc movhs r11, r8 */
/* @0x31b800 bhs 0x31b81c <__udivdi3+0x184> */
/* @0x31b804 adds r1, r1, r4 */
/* @0x31b808 sub r11, r8, #1 */
/* @0x31b80c bhs 0x31b81c <__udivdi3+0x184> */
/* @0x31b810 cmp r1, r5 */
/* @0x31b814 sublo r11, r8, #2 */
/* @0x31b818 addlo r1, r1, r4 */
/* @0x31b81c rsb r5, r5, r1 */
/* @0x31b820 mov r1, r6 */
/* @0x31b824 uxth r9, r9 */
/* @0x31b828 mov r0, r5 */
/* @0x31b82c bl 0x318c48 <__udivsi3> */
/* @0x31b830 mov r1, r6 */
/* @0x31b834 mov r8, r0 */
/* @0x31b838 mul r10, r10, r0 */
/* @0x31b83c mov r0, r5 */
/* @0x31b840 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b844 orr r1, r9, r1, lsl #16 */
/* @0x31b848 cmp r1, r10 */
/* @0x31b84c movhs r5, r8 */
/* @0x31b850 bhs 0x31b86c <__udivdi3+0x1d4> */
/* @0x31b854 adds r1, r1, r4 */
/* @0x31b858 sub r5, r8, #1 */
/* @0x31b85c bhs 0x31b86c <__udivdi3+0x1d4> */
/* @0x31b860 cmp r1, r10 */
/* @0x31b864 sublo r5, r8, #2 */
/* @0x31b868 addlo r1, r1, r4 */
/* @0x31b86c rsb r10, r10, r1 */
/* @0x31b870 orr r5, r5, r11, lsl #16 */
/* @0x31b874 lsr r6, r4, #16 */
/* @0x31b878 mov r0, r10 */
/* @0x31b87c uxth r9, r4 */
/* @0x31b880 mov r1, r6 */
/* @0x31b884 bl 0x318c48 <__udivsi3> */
/* @0x31b888 mov r1, r6 */
/* @0x31b88c mov r8, r0 */
/* @0x31b890 mul r11, r9, r0 */
/* @0x31b894 mov r0, r10 */
/* @0x31b898 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b89c lsr r3, r7, #16 */
/* @0x31b8a0 orr r1, r3, r1, lsl #16 */
/* @0x31b8a4 cmp r1, r11 */
/* @0x31b8a8 movhs r10, r8 */
/* @0x31b8ac bhs 0x31b8c8 <__udivdi3+0x230> */
/* @0x31b8b0 adds r1, r1, r4 */
/* @0x31b8b4 sub r10, r8, #1 */
/* @0x31b8b8 bhs 0x31b8c8 <__udivdi3+0x230> */
/* @0x31b8bc cmp r1, r11 */
/* @0x31b8c0 sublo r10, r8, #2 */
/* @0x31b8c4 addlo r1, r1, r4 */
/* @0x31b8c8 rsb r11, r11, r1 */
/* @0x31b8cc mov r1, r6 */
/* @0x31b8d0 uxth r7, r7 */
/* @0x31b8d4 mov r0, r11 */
/* @0x31b8d8 bl 0x318c48 <__udivsi3> */
/* @0x31b8dc mov r1, r6 */
/* @0x31b8e0 mov r8, r0 */
/* @0x31b8e4 mul r9, r9, r0 */
/* @0x31b8e8 mov r0, r11 */
/* @0x31b8ec bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b8f0 orr r1, r7, r1, lsl #16 */
/* @0x31b8f4 cmp r1, r9 */
/* @0x31b8f8 movhs r0, r8 */
/* @0x31b8fc bhs 0x31b914 <__udivdi3+0x27c> */
/* @0x31b900 adds r4, r1, r4 */
/* @0x31b904 sub r0, r8, #1 */
/* @0x31b908 bhs 0x31b914 <__udivdi3+0x27c> */
/* @0x31b90c cmp r4, r9 */
/* @0x31b910 sublo r0, r8, #2 */
/* @0x31b914 orr r0, r0, r10, lsl #16 */
/* @0x31b918 b 0x31ba70 <__udivdi3+0x3d8> */
/* @0x31b91c cmp r3, r1 */
/* @0x31b920 bhi 0x31ba68 <__udivdi3+0x3d0> */
/* @0x31b924 clz r7, r3 */
/* @0x31b928 cmp r7, #0 */
/* @0x31b92c bne 0x31b950 <__udivdi3+0x2b8> */
/* @0x31b930 cmp r1, r3 */
/* @0x31b934 cmpls r0, r2 */
/* @0x31b938 movlo r5, #0 */
/* @0x31b93c movhs r5, #1 */
/* @0x31b940 movhs r0, #1 */
/* @0x31b944 movhs r5, r7 */
/* @0x31b948 bhs 0x31ba70 <__udivdi3+0x3d8> */
/* @0x31b94c b 0x31ba6c <__udivdi3+0x3d4> */
/* @0x31b950 rsb r1, r7, #32 */
/* @0x31b954 lsl r8, r2, r7 */
/* @0x31b958 lsr r4, r2, r1 */
/* @0x31b95c orr r4, r4, r3, lsl r7 */
/* @0x31b960 lsr r3, r5, r1 */
/* @0x31b964 lsr r1, r0, r1 */
/* @0x31b968 str r3, [sp] */
/* @0x31b96c lsr r9, r4, #16 */
/* @0x31b970 orr r5, r1, r5, lsl r7 */
/* @0x31b974 mov r0, r3 */
/* @0x31b978 uxth r10, r4 */
/* @0x31b97c mov r1, r9 */
/* @0x31b980 bl 0x318c48 <__udivsi3> */
/* @0x31b984 ldr r3, [sp] */
/* @0x31b988 mov r1, r9 */
/* @0x31b98c mul r2, r10, r0 */
/* @0x31b990 mov r11, r0 */
/* @0x31b994 mov r0, r3 */
/* @0x31b998 str r2, [sp, #0x4] */
/* @0x31b99c bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b9a0 lsr r12, r5, #16 */
/* @0x31b9a4 ldr r2, [sp, #0x4] */
/* @0x31b9a8 orr r1, r12, r1, lsl #16 */
/* @0x31b9ac cmp r1, r2 */
/* @0x31b9b0 movhs r3, r11 */
/* @0x31b9b4 bhs 0x31b9d0 <__udivdi3+0x338> */
/* @0x31b9b8 adds r1, r1, r4 */
/* @0x31b9bc sub r3, r11, #1 */
/* @0x31b9c0 bhs 0x31b9d0 <__udivdi3+0x338> */
/* @0x31b9c4 cmp r1, r2 */
/* @0x31b9c8 sublo r3, r11, #2 */
/* @0x31b9cc addlo r1, r1, r4 */
/* @0x31b9d0 rsb r12, r2, r1 */
/* @0x31b9d4 mov r1, r9 */
/* @0x31b9d8 stm sp, {r3, r12} */
/* @0x31b9dc uxth r5, r5 */
/* @0x31b9e0 mov r0, r12 */
/* @0x31b9e4 bl 0x318c48 <__udivsi3> */
/* @0x31b9e8 ldr r12, [sp, #0x4] */
/* @0x31b9ec mov r1, r9 */
/* @0x31b9f0 mov r11, r0 */
/* @0x31b9f4 mul r10, r10, r0 */
/* @0x31b9f8 mov r0, r12 */
/* @0x31b9fc bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31ba00 ldr r3, [sp] */
/* @0x31ba04 orr r1, r5, r1, lsl #16 */
/* @0x31ba08 cmp r1, r10 */
/* @0x31ba0c movhs r0, r11 */
/* @0x31ba10 bhs 0x31ba2c <__udivdi3+0x394> */
/* @0x31ba14 adds r1, r1, r4 */
/* @0x31ba18 sub r0, r11, #1 */
/* @0x31ba1c bhs 0x31ba2c <__udivdi3+0x394> */
/* @0x31ba20 cmp r1, r10 */
/* @0x31ba24 sublo r0, r11, #2 */
/* @0x31ba28 addlo r1, r1, r4 */
/* @0x31ba2c orr r0, r0, r3, lsl #16 */
/* @0x31ba30 rsb r10, r10, r1 */
/* @0x31ba34 umull r2, r3, r0, r8 */
/* @0x31ba38 cmp r3, r10 */
/* @0x31ba3c bhi 0x31ba5c <__udivdi3+0x3c4> */
/* @0x31ba40 movne r5, #0 */
/* @0x31ba44 moveq r5, #1 */
/* @0x31ba48 cmp r2, r6, lsl r7 */
/* @0x31ba4c movls r5, #0 */
/* @0x31ba50 andhi r5, r5, #1 */
/* @0x31ba54 cmp r5, #0 */
/* @0x31ba58 beq 0x31ba70 <__udivdi3+0x3d8> */
/* @0x31ba5c sub r0, r0, #1 */
/* @0x31ba60 mov r5, #0 */
/* @0x31ba64 b 0x31ba70 <__udivdi3+0x3d8> */
/* @0x31ba68 mov r5, #0 */
/* @0x31ba6c mov r0, r5 */
/* @0x31ba70 mov r1, r5 */
/* @0x31ba74 add sp, sp, #12 */
/* @0x31ba78 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x31ba7c · anon_31ba7c · size=252 · insn=64 */
/* @0x31ba7c ldr r12, [pc, #0x4] */
/* @0x31ba80 add r12, pc, r12 */
/* @0x31ba84 bx r12 */
/* @0x31ba88 .word 0xfff88ce5 */
/* @0x31ba8c ldr r12, [pc, #0x4] */
/* @0x31ba90 add r12, pc, r12 */
/* @0x31ba94 bx r12 */
/* @0x31ba98 .word 0xfff888f1 */
/* @0x31ba9c uxtab16mi r4, r0, r8, ror #8 */
/* @0x31baa0 ldr r12, [pc] */
/* @0x31baa4 add pc, r12, pc */
/* @0x31baa8 .word 0xffd9ac24 */
/* @0x31baac uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bab0 ldr r12, [pc] */
/* @0x31bab4 add pc, r12, pc */
/* @0x31bab8 .word 0xffd9b430 */
/* @0x31babc uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bac0 ldr r12, [pc] */
/* @0x31bac4 add pc, r12, pc */
/* @0x31bac8 .word 0xffd9aa90 */
/* @0x31bacc uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bad0 ldr r12, [pc] */
/* @0x31bad4 add pc, r12, pc */
/* @0x31bad8 .word 0xffd9aad4 */
/* @0x31badc uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bae0 ldr r12, [pc] */
/* @0x31bae4 add pc, r12, pc */
/* @0x31bae8 .word 0xffd9b454 */
/* @0x31baec uxtab16mi r4, r0, r8, ror #8 */
/* @0x31baf0 ldr r12, [pc] */
/* @0x31baf4 add pc, r12, pc */
/* @0x31baf8 .word 0xffd9adb4 */
/* @0x31bafc uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bb00 ldr r12, [pc] */
/* @0x31bb04 add pc, r12, pc */
/* @0x31bb08 .word 0xffd9aa38 */
/* @0x31bb0c uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bb10 ldr r12, [pc] */
/* @0x31bb14 add pc, r12, pc */
/* @0x31bb18 .word 0xffd9aaa0 */
/* @0x31bb1c uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bb20 ldr r12, [pc] */
/* @0x31bb24 add pc, r12, pc */
/* @0x31bb28 .word 0xffd9adf0 */
/* @0x31bb2c uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bb30 ldr r12, [pc] */
/* @0x31bb34 add pc, r12, pc */
/* @0x31bb38 .word 0xffd9ad8c */
/* @0x31bb3c uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bb40 ldr r12, [pc] */
/* @0x31bb44 add pc, r12, pc */
/* @0x31bb48 .word 0xffd9b0dc */
/* @0x31bb4c uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bb50 ldr r12, [pc] */
/* @0x31bb54 add pc, r12, pc */
/* @0x31bb58 .word 0xffd9ab14 */
/* @0x31bb5c uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bb60 ldr r12, [pc] */
/* @0x31bb64 add pc, r12, pc */
/* @0x31bb68 .word 0xffd9b164 */
/* @0x31bb6c uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bb70 ldr r12, [pc] */
/* @0x31bb74 add pc, r12, pc */
/* @0x31bb78 .word 0xffd9aa7c */
