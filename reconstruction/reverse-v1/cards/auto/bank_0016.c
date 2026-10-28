/* libyoyo.so 覆盖卡组 0016
 * 函数 0xdc418..0xe6364，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xdc418 · _RefThing<char const*>::assign(_RefThing<char const*>*) · size=20 · insn=5 */
/* @0xdc418 cmp r0, #0 */
/* @0xdc41c ldrne r3, [r0, #0x4] */
/* @0xdc420 addne r3, r3, #1 */
/* @0xdc424 strne r3, [r0, #0x4] */
/* @0xdc428 bx lr */

/* ── FUNC 0xdc42c · _RefThing<char const*>::remove(_RefThing<char const*>*) · size=248 · insn=62 */
/* @0xdc42c push {r3, r4, r5, lr} */
/* @0xdc430 subs r4, r0, #0 */
/* @0xdc434 beq 0xdc454 <_ZN9_RefThingIPKcE6removeEPS2_+0x28> */
/* @0xdc438 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xdc43c ldr r5, [r4, #0x4] */
/* @0xdc440 sub r5, r5, #1 */
/* @0xdc444 str r5, [r4, #0x4] */
/* @0xdc448 cmp r5, #0 */
/* @0xdc44c beq 0xdc45c <_ZN9_RefThingIPKcE6removeEPS2_+0x30> */
/* @0xdc450 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xdc454 mov r0, #0 */
/* @0xdc458 pop {r3, r4, r5, pc} */
/* @0xdc45c ldr r0, [r4] */
/* @0xdc460 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdc464 str r5, [r4] */
/* @0xdc468 str r5, [r4, #0x8] */
/* @0xdc46c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xdc470 ldr r5, [r4, #0x4] */
/* @0xdc474 sub r5, r5, #1 */
/* @0xdc478 str r5, [r4, #0x4] */
/* @0xdc47c cmp r5, #0 */
/* @0xdc480 beq 0xdc494 <_ZN9_RefThingIPKcE6removeEPS2_+0x68> */
/* @0xdc484 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xdc488 mov r0, r4 */
/* @0xdc48c bl 0x27d1d0 <_ZdlPv> */
/* @0xdc490 b 0xdc450 <_ZN9_RefThingIPKcE6removeEPS2_+0x24> */
/* @0xdc494 ldr r0, [r4] */
/* @0xdc498 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdc49c str r5, [r4] */
/* @0xdc4a0 str r5, [r4, #0x8] */
/* @0xdc4a4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xdc4a8 ldr r5, [r4, #0x4] */
/* @0xdc4ac sub r5, r5, #1 */
/* @0xdc4b0 str r5, [r4, #0x4] */
/* @0xdc4b4 cmp r5, #0 */
/* @0xdc4b8 beq 0xdc4cc <_ZN9_RefThingIPKcE6removeEPS2_+0xa0> */
/* @0xdc4bc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xdc4c0 mov r0, r4 */
/* @0xdc4c4 bl 0x27d1d0 <_ZdlPv> */
/* @0xdc4c8 b 0xdc484 <_ZN9_RefThingIPKcE6removeEPS2_+0x58> */
/* @0xdc4cc ldr r0, [r4] */
/* @0xdc4d0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdc4d4 str r5, [r4] */
/* @0xdc4d8 str r5, [r4, #0x8] */
/* @0xdc4dc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xdc4e0 ldr r5, [r4, #0x4] */
/* @0xdc4e4 sub r5, r5, #1 */
/* @0xdc4e8 str r5, [r4, #0x4] */
/* @0xdc4ec cmp r5, #0 */
/* @0xdc4f0 bne 0xdc514 <_ZN9_RefThingIPKcE6removeEPS2_+0xe8> */
/* @0xdc4f4 ldr r0, [r4] */
/* @0xdc4f8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdc4fc mov r0, r4 */
/* @0xdc500 str r5, [r4] */
/* @0xdc504 str r5, [r4, #0x8] */
/* @0xdc508 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xdc50c mov r0, r4 */
/* @0xdc510 bl 0x27d1d0 <_ZdlPv> */
/* @0xdc514 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xdc518 mov r0, r4 */
/* @0xdc51c bl 0x27d1d0 <_ZdlPv> */
/* @0xdc520 b 0xdc4bc <_ZN9_RefThingIPKcE6removeEPS2_+0x90> */

/* ── FUNC 0xdc524 · DoAdd(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=4060 · insn=1015 */
/* @0xdc524 ubfx r2, r0, #0x8, #0x4 */
/* @0xdc528 lsr r0, r0, #16 */
/* @0xdc52c cmp r2, #0 */
/* @0xdc530 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xdc534 mov r10, r1 */
/* @0xdc538 sub sp, sp, #124 */
/* @0xdc53c uxtb r9, r0 */
/* @0xdc540 beq 0xdc554 <_Z5DoAddjPhPKhP6VMExec+0x30> */
/* @0xdc544 cmp r2, #1 */
/* @0xdc548 beq 0xdc9f8 <_Z5DoAddjPhPKhP6VMExec+0x4d4> */
/* @0xdc54c cmp r2, #2 */
/* @0xdc550 beq 0xdcb30 <_Z5DoAddjPhPKhP6VMExec+0x60c> */
/* @0xdc554 and r2, r9, #15 */
/* @0xdc558 cmp r2, #6 */
/* @0xdc55c addls pc, pc, r2, lsl #2 */
/* @0xdc560 b 0xdd4a0 <_Z5DoAddjPhPKhP6VMExec+0xf7c> */
/* @0xdc564 b 0xdc948 <_Z5DoAddjPhPKhP6VMExec+0x424> */
/* @0xdc568 b 0xdc580 <_Z5DoAddjPhPKhP6VMExec+0x5c> */
/* @0xdc56c b 0xdc580 <_Z5DoAddjPhPKhP6VMExec+0x5c> */
/* @0xdc570 b 0xdc948 <_Z5DoAddjPhPKhP6VMExec+0x424> */
/* @0xdc574 b 0xdc580 <_Z5DoAddjPhPKhP6VMExec+0x5c> */
/* @0xdc578 b 0xdc954 <_Z5DoAddjPhPKhP6VMExec+0x430> */
/* @0xdc57c b 0xdc580 <_Z5DoAddjPhPKhP6VMExec+0x5c> */
/* @0xdc580 add r7, r10, #4 */
/* @0xdc584 mov r6, r9 */
/* @0xdc588 asr r2, r6, #4 */
/* @0xdc58c cmp r2, #6 */
/* @0xdc590 addls pc, pc, r2, lsl #2 */
/* @0xdc594 b 0xdd4ac <_Z5DoAddjPhPKhP6VMExec+0xf88> */
/* @0xdc598 b 0xdc940 <_Z5DoAddjPhPKhP6VMExec+0x41c> */
/* @0xdc59c b 0xdc5b4 <_Z5DoAddjPhPKhP6VMExec+0x90> */
/* @0xdc5a0 b 0xdc5b4 <_Z5DoAddjPhPKhP6VMExec+0x90> */
/* @0xdc5a4 b 0xdc940 <_Z5DoAddjPhPKhP6VMExec+0x41c> */
/* @0xdc5a8 b 0xdc5b4 <_Z5DoAddjPhPKhP6VMExec+0x90> */
/* @0xdc5ac b 0xdc8f8 <_Z5DoAddjPhPKhP6VMExec+0x3d4> */
/* @0xdc5b0 b 0xdc5b4 <_Z5DoAddjPhPKhP6VMExec+0x90> */
/* @0xdc5b4 add r8, r7, #4 */
/* @0xdc5b8 cmp r9, #102 */
/* @0xdc5bc addls pc, pc, r9, lsl #2 */
/* @0xdc5c0 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5c4 b 0xdc8a0 <_Z5DoAddjPhPKhP6VMExec+0x37c> */
/* @0xdc5c8 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5cc b 0xdc8a0 <_Z5DoAddjPhPKhP6VMExec+0x37c> */
/* @0xdc5d0 b 0xdc8a0 <_Z5DoAddjPhPKhP6VMExec+0x37c> */
/* @0xdc5d4 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5d8 b 0xdc890 <_Z5DoAddjPhPKhP6VMExec+0x36c> */
/* @0xdc5dc b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5e0 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5e4 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5e8 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5ec b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5f0 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5f4 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5f8 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5fc b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc600 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc604 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc608 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc60c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc610 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc614 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc618 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc61c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc620 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc624 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc628 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc62c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc630 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc634 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc638 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc63c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc640 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc644 b 0xdc8a0 <_Z5DoAddjPhPKhP6VMExec+0x37c> */
/* @0xdc648 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc64c b 0xdc760 <_Z5DoAddjPhPKhP6VMExec+0x23c> */
/* @0xdc650 b 0xdc8a0 <_Z5DoAddjPhPKhP6VMExec+0x37c> */
/* @0xdc654 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc658 b 0xdc890 <_Z5DoAddjPhPKhP6VMExec+0x36c> */
/* @0xdc65c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc660 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc664 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc668 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc66c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc670 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc674 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc678 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc67c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc680 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc684 b 0xdc8a0 <_Z5DoAddjPhPKhP6VMExec+0x37c> */
/* @0xdc688 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc68c b 0xdc8a0 <_Z5DoAddjPhPKhP6VMExec+0x37c> */
/* @0xdc690 b 0xdc8a0 <_Z5DoAddjPhPKhP6VMExec+0x37c> */
/* @0xdc694 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc698 b 0xdc890 <_Z5DoAddjPhPKhP6VMExec+0x36c> */
/* @0xdc69c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6a0 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6a4 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6a8 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6ac b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6b0 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6b4 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6b8 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6bc b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6c0 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6c4 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6c8 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6cc b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6d0 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6d4 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6d8 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6dc b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6e0 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6e4 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6e8 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6ec b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6f0 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6f4 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6f8 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6fc b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc700 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc704 b 0xdc890 <_Z5DoAddjPhPKhP6VMExec+0x36c> */
/* @0xdc708 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc70c b 0xdc890 <_Z5DoAddjPhPKhP6VMExec+0x36c> */
/* @0xdc710 b 0xdc890 <_Z5DoAddjPhPKhP6VMExec+0x36c> */
/* @0xdc714 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc718 b 0xdc890 <_Z5DoAddjPhPKhP6VMExec+0x36c> */
/* @0xdc71c b 0xdc890 <_Z5DoAddjPhPKhP6VMExec+0x36c> */
/* @0xdc720 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc724 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc728 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc72c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc730 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc734 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc738 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc73c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc740 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc744 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc748 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc74c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc750 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc754 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc758 b 0xdc890 <_Z5DoAddjPhPKhP6VMExec+0x36c> */
/* @0xdc75c b 0xdc760 <_Z5DoAddjPhPKhP6VMExec+0x23c> */
/* @0xdc760 sub r8, r8, #4 */
/* @0xdc764 mov r4, #0 */
/* @0xdc768 mov r5, r8 */
/* @0xdc76c cmp r6, #34 */
/* @0xdc770 beq 0xdcd3c <_Z5DoAddjPhPKhP6VMExec+0x818> */
/* @0xdc774 bls 0xdc8b0 <_Z5DoAddjPhPKhP6VMExec+0x38c> */
/* @0xdc778 cmp r6, #50 */
/* @0xdc77c beq 0xdcd20 <_Z5DoAddjPhPKhP6VMExec+0x7fc> */
/* @0xdc780 bls 0xdc99c <_Z5DoAddjPhPKhP6VMExec+0x478> */
/* @0xdc784 cmp r6, #51 */
/* @0xdc788 beq 0xdcd04 <_Z5DoAddjPhPKhP6VMExec+0x7e0> */
/* @0xdc78c cmp r6, #102 */
/* @0xdc790 bne 0xdcd54 <_Z5DoAddjPhPKhP6VMExec+0x830> */
/* @0xdc794 ldr r9, [r10] */
/* @0xdc798 mov r0, #12 */
/* @0xdc79c ldr r6, [r7] */
/* @0xdc7a0 cmp r9, #0 */
/* @0xdc7a4 streq r9, [sp, #0x8] */
/* @0xdc7a8 ldrne r2, [r9] */
/* @0xdc7ac strne r2, [sp, #0x8] */
/* @0xdc7b0 cmp r6, #0 */
/* @0xdc7b4 ldrne r1, [r6] */
/* @0xdc7b8 moveq r1, r6 */
/* @0xdc7bc cmp r9, #0 */
/* @0xdc7c0 ldrne r7, [r9, #0x8] */
/* @0xdc7c4 moveq r7, r9 */
/* @0xdc7c8 cmp r6, #0 */
/* @0xdc7cc streq r6, [sp, #0xc] */
/* @0xdc7d0 ldrne r3, [r6, #0x8] */
/* @0xdc7d4 str r1, [sp, #0x4] */
/* @0xdc7d8 strne r3, [sp, #0xc] */
/* @0xdc7dc ldr r2, [sp, #0xc] */
/* @0xdc7e0 add r7, r2, r7 */
/* @0xdc7e4 bl 0x27c524 <_Znwj> */
/* @0xdc7e8 mov r10, r0 */
/* @0xdc7ec add r0, r7, #1 */
/* @0xdc7f0 bl 0xcef4c <_Z7YYAlloci> */
/* @0xdc7f4 ldr r1, [sp, #0x4] */
/* @0xdc7f8 mov r12, #1 */
/* @0xdc7fc str r7, [r10, #0x8] */
/* @0xdc800 cmp r1, #0 */
/* @0xdc804 mov r11, r0 */
/* @0xdc808 stm r10, {r11, r12} */
/* @0xdc80c beq 0xdc814 <_Z5DoAddjPhPKhP6VMExec+0x2f0> */
/* @0xdc810 bl 0xb65a4 <strcpy@plt> */
/* @0xdc814 ldr r3, [sp, #0x8] */
/* @0xdc818 cmp r3, #0 */
/* @0xdc81c beq 0xdc830 <_Z5DoAddjPhPKhP6VMExec+0x30c> */
/* @0xdc820 ldr r2, [sp, #0xc] */
/* @0xdc824 mov r1, r3 */
/* @0xdc828 add r0, r11, r2 */
/* @0xdc82c bl 0xb65a4 <strcpy@plt> */
/* @0xdc830 cmp r9, #0 */
/* @0xdc834 mov r1, #0 */
/* @0xdc838 strb r1, [r11, r7] */
/* @0xdc83c str r10, [r5] */
/* @0xdc840 beq 0xdc860 <_Z5DoAddjPhPKhP6VMExec+0x33c> */
/* @0xdc844 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xdc848 ldr r5, [r9, #0x4] */
/* @0xdc84c sub r5, r5, #1 */
/* @0xdc850 str r5, [r9, #0x4] */
/* @0xdc854 cmp r5, #0 */
/* @0xdc858 beq 0xdcea0 <_Z5DoAddjPhPKhP6VMExec+0x97c> */
/* @0xdc85c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xdc860 cmp r6, #0 */
/* @0xdc864 moveq r12, #1 */
/* @0xdc868 beq 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdc86c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xdc870 ldr r5, [r6, #0x4] */
/* @0xdc874 sub r5, r5, #1 */
/* @0xdc878 str r5, [r6, #0x4] */
/* @0xdc87c cmp r5, #0 */
/* @0xdc880 beq 0xdcef8 <_Z5DoAddjPhPKhP6VMExec+0x9d4> */
/* @0xdc884 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xdc888 mov r12, #1 */
/* @0xdc88c b 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdc890 sub r4, r8, #16 */
/* @0xdc894 mov r5, r4 */
/* @0xdc898 mov r8, r4 */
/* @0xdc89c b 0xdc76c <_Z5DoAddjPhPKhP6VMExec+0x248> */
/* @0xdc8a0 sub r8, r8, #8 */
/* @0xdc8a4 mov r4, #0 */
/* @0xdc8a8 mov r5, r8 */
/* @0xdc8ac b 0xdc76c <_Z5DoAddjPhPKhP6VMExec+0x248> */
/* @0xdc8b0 cmp r6, #2 */
/* @0xdc8b4 beq 0xdcce8 <_Z5DoAddjPhPKhP6VMExec+0x7c4> */
/* @0xdc8b8 bls 0xdc9d8 <_Z5DoAddjPhPKhP6VMExec+0x4b4> */
/* @0xdc8bc cmp r6, #3 */
/* @0xdc8c0 beq 0xdcd6c <_Z5DoAddjPhPKhP6VMExec+0x848> */
/* @0xdc8c4 cmp r6, #32 */
/* @0xdc8c8 bne 0xdcd54 <_Z5DoAddjPhPKhP6VMExec+0x830> */
/* @0xdc8cc vldr s14, [r7] */
/* @0xdc8d0 vcvt.f64.s32 d7, s14 */
/* @0xdc8d4 vldr d6, [r10] */
/* @0xdc8d8 mov r12, #0 */
/* @0xdc8dc vadd.f64 d7, d7, d6 */
/* @0xdc8e0 vstr d7, [r5] */
/* @0xdc8e4 cmp r4, #0 */
/* @0xdc8e8 strne r12, [r4, #0xc] */
/* @0xdc8ec mov r0, r8 */
/* @0xdc8f0 add sp, sp, #124 */
/* @0xdc8f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xdc8f8 ldr r2, [r7, #0xc] */
/* @0xdc8fc cmp r2, #13 */
/* @0xdc900 addls pc, pc, r2, lsl #2 */
/* @0xdc904 b 0xdcf78 <_Z5DoAddjPhPKhP6VMExec+0xa54> */
/* @0xdc908 b 0xdce98 <_Z5DoAddjPhPKhP6VMExec+0x974> */
/* @0xdc90c b 0xdce8c <_Z5DoAddjPhPKhP6VMExec+0x968> */
/* @0xdc910 b 0xdce70 <_Z5DoAddjPhPKhP6VMExec+0x94c> */
/* @0xdc914 b 0xdce54 <_Z5DoAddjPhPKhP6VMExec+0x930> */
/* @0xdc918 b 0xdcf78 <_Z5DoAddjPhPKhP6VMExec+0xa54> */
/* @0xdc91c b 0xdce38 <_Z5DoAddjPhPKhP6VMExec+0x914> */
/* @0xdc920 b 0xdcf78 <_Z5DoAddjPhPKhP6VMExec+0xa54> */
/* @0xdc924 b 0xdce2c <_Z5DoAddjPhPKhP6VMExec+0x908> */
/* @0xdc928 b 0xdcf78 <_Z5DoAddjPhPKhP6VMExec+0xa54> */
/* @0xdc92c b 0xdcf78 <_Z5DoAddjPhPKhP6VMExec+0xa54> */
/* @0xdc930 b 0xdce1c <_Z5DoAddjPhPKhP6VMExec+0x8f8> */
/* @0xdc934 b 0xdcf78 <_Z5DoAddjPhPKhP6VMExec+0xa54> */
/* @0xdc938 b 0xdcf78 <_Z5DoAddjPhPKhP6VMExec+0xa54> */
/* @0xdc93c b 0xdce98 <_Z5DoAddjPhPKhP6VMExec+0x974> */
/* @0xdc940 add r8, r7, #8 */
/* @0xdc944 b 0xdc5b8 <_Z5DoAddjPhPKhP6VMExec+0x94> */
/* @0xdc948 add r7, r10, #8 */
/* @0xdc94c mov r6, r9 */
/* @0xdc950 b 0xdc588 <_Z5DoAddjPhPKhP6VMExec+0x64> */
/* @0xdc954 ldr r2, [r10, #0xc] */
/* @0xdc958 cmp r2, #13 */
/* @0xdc95c addls pc, pc, r2, lsl #2 */
/* @0xdc960 b 0xdcf94 <_Z5DoAddjPhPKhP6VMExec+0xa70> */
/* @0xdc964 b 0xdce14 <_Z5DoAddjPhPKhP6VMExec+0x8f0> */
/* @0xdc968 b 0xdcdfc <_Z5DoAddjPhPKhP6VMExec+0x8d8> */
/* @0xdc96c b 0xdcddc <_Z5DoAddjPhPKhP6VMExec+0x8b8> */
/* @0xdc970 b 0xdcdbc <_Z5DoAddjPhPKhP6VMExec+0x898> */
/* @0xdc974 b 0xdcf94 <_Z5DoAddjPhPKhP6VMExec+0xa70> */
/* @0xdc978 b 0xdcd9c <_Z5DoAddjPhPKhP6VMExec+0x878> */
/* @0xdc97c b 0xdcf94 <_Z5DoAddjPhPKhP6VMExec+0xa70> */
/* @0xdc980 b 0xdce08 <_Z5DoAddjPhPKhP6VMExec+0x8e4> */
/* @0xdc984 b 0xdcf94 <_Z5DoAddjPhPKhP6VMExec+0xa70> */
/* @0xdc988 b 0xdcf94 <_Z5DoAddjPhPKhP6VMExec+0xa70> */
/* @0xdc98c b 0xdcd8c <_Z5DoAddjPhPKhP6VMExec+0x868> */
/* @0xdc990 b 0xdcf94 <_Z5DoAddjPhPKhP6VMExec+0xa70> */
/* @0xdc994 b 0xdcf94 <_Z5DoAddjPhPKhP6VMExec+0xa70> */
/* @0xdc998 b 0xdce14 <_Z5DoAddjPhPKhP6VMExec+0x8f0> */
/* @0xdc99c cmp r6, #35 */
/* @0xdc9a0 beq 0xdcccc <_Z5DoAddjPhPKhP6VMExec+0x7a8> */
/* @0xdc9a4 cmp r6, #48 */
/* @0xdc9a8 bne 0xdcd54 <_Z5DoAddjPhPKhP6VMExec+0x830> */
/* @0xdc9ac ldrd r0, r1, [r7] */
/* @0xdc9b0 bl 0x319164 <__floatdidf> */
/* @0xdc9b4 vldr d7, [r10] */
/* @0xdc9b8 mov r12, #0 */
/* @0xdc9bc vmov d6, r0, r1 */
/* @0xdc9c0 vadd.f64 d7, d6, d7 */
/* @0xdc9c4 vstr d7, [r5] */
/* @0xdc9c8 b 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdc9cc mov r5, #0 */
/* @0xdc9d0 mov r4, r5 */
/* @0xdc9d4 b 0xdc76c <_Z5DoAddjPhPKhP6VMExec+0x248> */
/* @0xdc9d8 cmp r6, #0 */
/* @0xdc9dc bne 0xdcd54 <_Z5DoAddjPhPKhP6VMExec+0x830> */
/* @0xdc9e0 vldr d6, [r7] */
/* @0xdc9e4 vldr d7, [r10] */
/* @0xdc9e8 vadd.f64 d7, d6, d7 */
/* @0xdc9ec mov r12, r6 */
/* @0xdc9f0 vstr d7, [r5] */
/* @0xdc9f4 b 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdc9f8 add r7, sp, #40 */
/* @0xdc9fc mov r2, r1 */
/* @0xdca00 and r1, r9, #15 */
/* @0xdca04 mov r3, #0 */
/* @0xdca08 mov r0, r7 */
/* @0xdca0c mvn r6, #-16777216 */
/* @0xdca10 str r3, [sp, #0x20] */
/* @0xdca14 mov r10, #0 */
/* @0xdca18 str r3, [sp, #0x30] */
/* @0xdca1c mov r11, #0 */
/* @0xdca20 str r3, [sp, #0x4] */
/* @0xdca24 add r5, sp, #24 */
/* @0xdca28 strd r10, r11, [sp, #24] */
/* @0xdca2c strd r10, r11, [sp, #40] */
/* @0xdca30 str r6, [sp, #0x24] */
/* @0xdca34 str r6, [sp, #0x34] */
/* @0xdca38 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xdca3c lsr r1, r9, #4 */
/* @0xdca40 mov r2, r0 */
/* @0xdca44 mov r0, r5 */
/* @0xdca48 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xdca4c ldr r2, [sp, #0x24] */
/* @0xdca50 ldr r3, [sp, #0x4] */
/* @0xdca54 and r2, r2, r6 */
/* @0xdca58 cmp r2, r6 */
/* @0xdca5c mov r8, r0 */
/* @0xdca60 beq 0xdd064 <_Z5DoAddjPhPKhP6VMExec+0xb40> */
/* @0xdca64 ldr r2, [sp, #0x34] */
/* @0xdca68 bic r2, r2, #-16777216 */
/* @0xdca6c cmp r2, r6 */
/* @0xdca70 beq 0xdcf50 <_Z5DoAddjPhPKhP6VMExec+0xa2c> */
/* @0xdca74 add r4, sp, #56 */
/* @0xdca78 mov r2, r3 */
/* @0xdca7c mov r1, r5 */
/* @0xdca80 strd r10, r11, [sp, #56] */
/* @0xdca84 mov r0, r4 */
/* @0xdca88 str r3, [sp, #0x40] */
/* @0xdca8c str r6, [sp, #0x44] */
/* @0xdca90 strd r10, r11, [sp, #72] */
/* @0xdca94 str r3, [sp, #0x50] */
/* @0xdca98 str r6, [sp, #0x54] */
/* @0xdca9c bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i> */
/* @0xdcaa0 cmp r0, #1 */
/* @0xdcaa4 beq 0xdd15c <_Z5DoAddjPhPKhP6VMExec+0xc38> */
/* @0xdcaa8 cmp r0, #0 */
/* @0xdcaac beq 0xdcfb4 <_Z5DoAddjPhPKhP6VMExec+0xa90> */
/* @0xdcab0 ldr r3, [sp, #0x24] */
/* @0xdcab4 sub r3, r3, #1 */
/* @0xdcab8 bic r3, r3, #-16777216 */
/* @0xdcabc bic r3, r3, #3 */
/* @0xdcac0 cmp r3, #0 */
/* @0xdcac4 beq 0xdd084 <_Z5DoAddjPhPKhP6VMExec+0xb60> */
/* @0xdcac8 ldr r1, [sp, #0x34] */
/* @0xdcacc mov r3, #0 */
/* @0xdcad0 str r3, [sp, #0x20] */
/* @0xdcad4 mov r2, #5 */
/* @0xdcad8 sub r1, r1, #1 */
/* @0xdcadc str r3, [sp, #0x18] */
/* @0xdcae0 bic r3, r1, #-16777216 */
/* @0xdcae4 str r2, [sp, #0x24] */
/* @0xdcae8 bic r3, r3, #3 */
/* @0xdcaec cmp r3, #0 */
/* @0xdcaf0 beq 0xdd078 <_Z5DoAddjPhPKhP6VMExec+0xb54> */
/* @0xdcaf4 ldr r1, [sp, #0x44] */
/* @0xdcaf8 mov r3, #0 */
/* @0xdcafc str r3, [sp, #0x30] */
/* @0xdcb00 mov r2, #5 */
/* @0xdcb04 sub r1, r1, #1 */
/* @0xdcb08 str r3, [sp, #0x28] */
/* @0xdcb0c bic r3, r1, #-16777216 */
/* @0xdcb10 str r2, [sp, #0x34] */
/* @0xdcb14 bic r3, r3, #3 */
/* @0xdcb18 cmp r3, #0 */
/* @0xdcb1c bne 0xdc8ec <_Z5DoAddjPhPKhP6VMExec+0x3c8> */
/* @0xdcb20 mov r0, r4 */
/* @0xdcb24 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdcb28 mov r0, r8 */
/* @0xdcb2c b 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdcb30 add r6, sp, #72 */
/* @0xdcb34 mov r2, r1 */
/* @0xdcb38 and r1, r9, #15 */
/* @0xdcb3c mvn r5, #-16777216 */
/* @0xdcb40 mov r0, r6 */
/* @0xdcb44 mov r10, #0 */
/* @0xdcb48 mov r11, #0 */
/* @0xdcb4c mov r7, #0 */
/* @0xdcb50 strd r10, r11, [sp, #56] */
/* @0xdcb54 add r4, sp, #56 */
/* @0xdcb58 strd r10, r11, [sp, #72] */
/* @0xdcb5c str r7, [sp, #0x40] */
/* @0xdcb60 str r7, [sp, #0x50] */
/* @0xdcb64 str r5, [sp, #0x44] */
/* @0xdcb68 str r5, [sp, #0x54] */
/* @0xdcb6c bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xdcb70 lsr r1, r9, #4 */
/* @0xdcb74 mov r2, r0 */
/* @0xdcb78 mov r0, r4 */
/* @0xdcb7c bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xdcb80 ldr r3, [sp, #0x44] */
/* @0xdcb84 and r3, r3, r5 */
/* @0xdcb88 cmp r3, r5 */
/* @0xdcb8c mov r8, r0 */
/* @0xdcb90 beq 0xdd090 <_Z5DoAddjPhPKhP6VMExec+0xb6c> */
/* @0xdcb94 ldr r3, [sp, #0x54] */
/* @0xdcb98 bic r3, r3, #-16777216 */
/* @0xdcb9c cmp r3, r5 */
/* @0xdcba0 beq 0xdcf64 <_Z5DoAddjPhPKhP6VMExec+0xa40> */
/* @0xdcba4 add r9, sp, #88 */
/* @0xdcba8 mov r1, r4 */
/* @0xdcbac strd r10, r11, [sp, #88] */
/* @0xdcbb0 mov r0, r9 */
/* @0xdcbb4 str r7, [sp, #0x60] */
/* @0xdcbb8 str r5, [sp, #0x64] */
/* @0xdcbbc strd r10, r11, [sp, #104] */
/* @0xdcbc0 str r7, [sp, #0x70] */
/* @0xdcbc4 str r5, [sp, #0x74] */
/* @0xdcbc8 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xdcbcc cmp r0, #1 */
/* @0xdcbd0 beq 0xdd16c <_Z5DoAddjPhPKhP6VMExec+0xc48> */
/* @0xdcbd4 cmp r0, #0 */
/* @0xdcbd8 bne 0xdc8ec <_Z5DoAddjPhPKhP6VMExec+0x3c8> */
/* @0xdcbdc add r10, sp, #104 */
/* @0xdcbe0 mov r1, r6 */
/* @0xdcbe4 mov r0, r10 */
/* @0xdcbe8 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xdcbec cmp r0, #1 */
/* @0xdcbf0 beq 0xdd3b0 <_Z5DoAddjPhPKhP6VMExec+0xe8c> */
/* @0xdcbf4 cmp r0, #0 */
/* @0xdcbf8 bne 0xdc8ec <_Z5DoAddjPhPKhP6VMExec+0x3c8> */
/* @0xdcbfc str r0, [r8, #-0x4] */
/* @0xdcc00 sub r5, r8, #16 */
/* @0xdcc04 vldr d6, [sp, #88] */
/* @0xdcc08 vldr d7, [sp, #104] */
/* @0xdcc0c vadd.f64 d5, d6, d7 */
/* @0xdcc10 ldr r1, [sp, #0x44] */
/* @0xdcc14 sub r1, r1, #1 */
/* @0xdcc18 bic r1, r1, #-16777216 */
/* @0xdcc1c bic r1, r1, #3 */
/* @0xdcc20 cmp r1, #0 */
/* @0xdcc24 vmov r2, r3, d5 */
/* @0xdcc28 vstr s10, [r8, #-16] */
/* @0xdcc2c str r3, [r8, #-0xc] */
/* @0xdcc30 beq 0xdd398 <_Z5DoAddjPhPKhP6VMExec+0xe74> */
/* @0xdcc34 ldr r1, [sp, #0x54] */
/* @0xdcc38 mov r3, #0 */
/* @0xdcc3c str r3, [sp, #0x40] */
/* @0xdcc40 mov r2, #5 */
/* @0xdcc44 sub r1, r1, #1 */
/* @0xdcc48 str r3, [sp, #0x38] */
/* @0xdcc4c bic r3, r1, #-16777216 */
/* @0xdcc50 str r2, [sp, #0x44] */
/* @0xdcc54 bic r3, r3, #3 */
/* @0xdcc58 cmp r3, #0 */
/* @0xdcc5c beq 0xdd38c <_Z5DoAddjPhPKhP6VMExec+0xe68> */
/* @0xdcc60 ldr r1, [sp, #0x64] */
/* @0xdcc64 mov r3, #0 */
/* @0xdcc68 str r3, [sp, #0x50] */
/* @0xdcc6c mov r2, #5 */
/* @0xdcc70 sub r1, r1, #1 */
/* @0xdcc74 str r3, [sp, #0x48] */
/* @0xdcc78 bic r3, r1, #-16777216 */
/* @0xdcc7c str r2, [sp, #0x54] */
/* @0xdcc80 bic r3, r3, #3 */
/* @0xdcc84 cmp r3, #0 */
/* @0xdcc88 beq 0xdd3a4 <_Z5DoAddjPhPKhP6VMExec+0xe80> */
/* @0xdcc8c ldr r1, [sp, #0x74] */
/* @0xdcc90 mov r3, #0 */
/* @0xdcc94 str r3, [sp, #0x60] */
/* @0xdcc98 mov r2, #5 */
/* @0xdcc9c sub r1, r1, #1 */
/* @0xdcca0 str r3, [sp, #0x58] */
/* @0xdcca4 bic r3, r1, #-16777216 */
/* @0xdcca8 str r2, [sp, #0x64] */
/* @0xdccac bic r3, r3, #3 */
/* @0xdccb0 cmp r3, #0 */
/* @0xdccb4 movne r0, r5 */
/* @0xdccb8 bne 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdccbc mov r0, r10 */
/* @0xdccc0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdccc4 mov r0, r5 */
/* @0xdccc8 b 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdcccc ldr r1, [r7] */
/* @0xdccd0 mov r12, #10 */
/* @0xdccd4 ldrd r2, r3, [r10] */
/* @0xdccd8 adds r2, r2, r1 */
/* @0xdccdc adc r3, r3, r1, asr #31 */
/* @0xdcce0 strd r2, r3, [r5] */
/* @0xdcce4 b 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdcce8 vldr s14, [r10] */
/* @0xdccec vcvt.f64.s32 d7, s14 */
/* @0xdccf0 vldr d6, [r7] */
/* @0xdccf4 mov r12, #0 */
/* @0xdccf8 vadd.f64 d7, d6, d7 */
/* @0xdccfc vstr d7, [r5] */
/* @0xdcd00 b 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdcd04 ldrd r0, r1, [r7] */
/* @0xdcd08 mov r12, #10 */
/* @0xdcd0c ldrd r2, r3, [r10] */
/* @0xdcd10 adds r2, r2, r0 */
/* @0xdcd14 adc r3, r3, r1 */
/* @0xdcd18 strd r2, r3, [r5] */
/* @0xdcd1c b 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdcd20 ldr r1, [r10] */
/* @0xdcd24 mov r12, #10 */
/* @0xdcd28 ldrd r2, r3, [r7] */
/* @0xdcd2c adds r2, r2, r1 */
/* @0xdcd30 adc r3, r3, r1, asr #31 */
/* @0xdcd34 strd r2, r3, [r5] */
/* @0xdcd38 b 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdcd3c ldr r2, [r7] */
/* @0xdcd40 mov r12, #7 */
/* @0xdcd44 ldr r3, [r10] */
/* @0xdcd48 add r3, r2, r3 */
/* @0xdcd4c str r3, [r5] */
/* @0xdcd50 b 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdcd54 ldr r1, [pc, #0x758] */
/* @0xdcd58 mov r0, r3 */
/* @0xdcd5c add r1, pc, r1 */
/* @0xdcd60 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdcd64 mov r12, #0 */
/* @0xdcd68 b 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdcd6c ldrd r0, r1, [r10] */
/* @0xdcd70 bl 0x319164 <__floatdidf> */
/* @0xdcd74 vldr d7, [r7] */
/* @0xdcd78 mov r12, #0 */
/* @0xdcd7c vmov d5, r0, r1 */
/* @0xdcd80 vadd.f64 d7, d7, d5 */
/* @0xdcd84 vstr d7, [r5] */
/* @0xdcd88 b 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdcd8c and r0, r0, #240 */
/* @0xdcd90 orr r6, r0, #3 */
/* @0xdcd94 add r7, r10, #16 */
/* @0xdcd98 b 0xdc588 <_Z5DoAddjPhPKhP6VMExec+0x64> */
/* @0xdcd9c ldr r1, [pc, #0x714] */
/* @0xdcda0 mov r0, r3 */
/* @0xdcda4 str r3, [sp, #0x4] */
/* @0xdcda8 mov r6, r9 */
/* @0xdcdac add r1, pc, r1 */
/* @0xdcdb0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdcdb4 ldr r3, [sp, #0x4] */
/* @0xdcdb8 b 0xdcd94 <_Z5DoAddjPhPKhP6VMExec+0x870> */
/* @0xdcdbc ldr r1, [pc, #0x6f8] */
/* @0xdcdc0 mov r0, r3 */
/* @0xdcdc4 str r3, [sp, #0x4] */
/* @0xdcdc8 mov r6, r9 */
/* @0xdcdcc add r1, pc, r1 */
/* @0xdcdd0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdcdd4 ldr r3, [sp, #0x4] */
/* @0xdcdd8 b 0xdcd94 <_Z5DoAddjPhPKhP6VMExec+0x870> */
/* @0xdcddc ldr r1, [pc, #0x6dc] */
/* @0xdcde0 mov r0, r3 */
/* @0xdcde4 str r3, [sp, #0x4] */
/* @0xdcde8 mov r6, r9 */
/* @0xdcdec add r1, pc, r1 */
/* @0xdcdf0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdcdf4 ldr r3, [sp, #0x4] */
/* @0xdcdf8 b 0xdcd94 <_Z5DoAddjPhPKhP6VMExec+0x870> */
/* @0xdcdfc and r0, r0, #240 */
/* @0xdce00 orr r6, r0, #6 */
/* @0xdce04 b 0xdcd94 <_Z5DoAddjPhPKhP6VMExec+0x870> */
/* @0xdce08 and r0, r0, #240 */
/* @0xdce0c orr r6, r0, #2 */
/* @0xdce10 b 0xdcd94 <_Z5DoAddjPhPKhP6VMExec+0x870> */
/* @0xdce14 and r6, r9, #240 */
/* @0xdce18 b 0xdcd94 <_Z5DoAddjPhPKhP6VMExec+0x870> */
/* @0xdce1c and r6, r6, #15 */
/* @0xdce20 orr r6, r6, #48 */
/* @0xdce24 add r8, r7, #16 */
/* @0xdce28 b 0xdc5b8 <_Z5DoAddjPhPKhP6VMExec+0x94> */
/* @0xdce2c and r6, r6, #15 */
/* @0xdce30 orr r6, r6, #32 */
/* @0xdce34 b 0xdce24 <_Z5DoAddjPhPKhP6VMExec+0x900> */
/* @0xdce38 ldr r1, [pc, #0x684] */
/* @0xdce3c mov r0, r3 */
/* @0xdce40 str r3, [sp, #0x4] */
/* @0xdce44 add r1, pc, r1 */
/* @0xdce48 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdce4c ldr r3, [sp, #0x4] */
/* @0xdce50 b 0xdce24 <_Z5DoAddjPhPKhP6VMExec+0x900> */
/* @0xdce54 ldr r1, [pc, #0x66c] */
/* @0xdce58 mov r0, r3 */
/* @0xdce5c str r3, [sp, #0x4] */
/* @0xdce60 add r1, pc, r1 */
/* @0xdce64 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdce68 ldr r3, [sp, #0x4] */
/* @0xdce6c b 0xdce24 <_Z5DoAddjPhPKhP6VMExec+0x900> */
/* @0xdce70 ldr r1, [pc, #0x654] */
/* @0xdce74 mov r0, r3 */
/* @0xdce78 str r3, [sp, #0x4] */
/* @0xdce7c add r1, pc, r1 */
/* @0xdce80 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdce84 ldr r3, [sp, #0x4] */
/* @0xdce88 b 0xdce24 <_Z5DoAddjPhPKhP6VMExec+0x900> */
/* @0xdce8c and r6, r6, #15 */
/* @0xdce90 orr r6, r6, #96 */
/* @0xdce94 b 0xdce24 <_Z5DoAddjPhPKhP6VMExec+0x900> */
/* @0xdce98 and r6, r6, #15 */
/* @0xdce9c b 0xdce24 <_Z5DoAddjPhPKhP6VMExec+0x900> */
/* @0xdcea0 ldr r0, [r9] */
/* @0xdcea4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdcea8 str r5, [r9] */
/* @0xdceac str r5, [r9, #0x8] */
/* @0xdceb0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xdceb4 ldr r5, [r9, #0x4] */
/* @0xdceb8 sub r5, r5, #1 */
/* @0xdcebc str r5, [r9, #0x4] */
/* @0xdcec0 cmp r5, #0 */
/* @0xdcec4 bne 0xdcee8 <_Z5DoAddjPhPKhP6VMExec+0x9c4> */
/* @0xdcec8 ldr r0, [r9] */
/* @0xdcecc bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdced0 mov r0, r9 */
/* @0xdced4 str r5, [r9] */
/* @0xdced8 str r5, [r9, #0x8] */
/* @0xdcedc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xdcee0 mov r0, r9 */
/* @0xdcee4 bl 0x27d1d0 <_ZdlPv> */
/* @0xdcee8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xdceec mov r0, r9 */
/* @0xdcef0 bl 0x27d1d0 <_ZdlPv> */
/* @0xdcef4 b 0xdc85c <_Z5DoAddjPhPKhP6VMExec+0x338> */
/* @0xdcef8 ldr r0, [r6] */
/* @0xdcefc bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdcf00 str r5, [r6] */
/* @0xdcf04 str r5, [r6, #0x8] */
/* @0xdcf08 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xdcf0c ldr r5, [r6, #0x4] */
/* @0xdcf10 sub r5, r5, #1 */
/* @0xdcf14 str r5, [r6, #0x4] */
/* @0xdcf18 cmp r5, #0 */
/* @0xdcf1c bne 0xdcf40 <_Z5DoAddjPhPKhP6VMExec+0xa1c> */
/* @0xdcf20 ldr r0, [r6] */
/* @0xdcf24 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdcf28 mov r0, r6 */
/* @0xdcf2c str r5, [r6] */
/* @0xdcf30 str r5, [r6, #0x8] */
/* @0xdcf34 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xdcf38 mov r0, r6 */
/* @0xdcf3c bl 0x27d1d0 <_ZdlPv> */
/* @0xdcf40 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xdcf44 mov r0, r6 */
/* @0xdcf48 bl 0x27d1d0 <_ZdlPv> */
/* @0xdcf4c b 0xdc884 <_Z5DoAddjPhPKhP6VMExec+0x360> */
/* @0xdcf50 ldr r0, [pc, #0x578] */
/* @0xdcf54 add r0, pc, r0 */
/* @0xdcf58 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xdcf5c mov r0, r8 */
/* @0xdcf60 b 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdcf64 ldr r0, [pc, #0x568] */
/* @0xdcf68 add r0, pc, r0 */
/* @0xdcf6c bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xdcf70 mov r0, r8 */
/* @0xdcf74 b 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdcf78 ldr r1, [pc, #0x558] */
/* @0xdcf7c mov r0, r3 */
/* @0xdcf80 str r3, [sp, #0x4] */
/* @0xdcf84 add r1, pc, r1 */
/* @0xdcf88 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdcf8c ldr r3, [sp, #0x4] */
/* @0xdcf90 b 0xdce24 <_Z5DoAddjPhPKhP6VMExec+0x900> */
/* @0xdcf94 ldr r1, [pc, #0x540] */
/* @0xdcf98 mov r0, r3 */
/* @0xdcf9c str r3, [sp, #0x4] */
/* @0xdcfa0 mov r6, r9 */
/* @0xdcfa4 add r1, pc, r1 */
/* @0xdcfa8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdcfac ldr r3, [sp, #0x4] */
/* @0xdcfb0 b 0xdcd94 <_Z5DoAddjPhPKhP6VMExec+0x870> */
/* @0xdcfb4 add r6, sp, #72 */
/* @0xdcfb8 mov r2, r0 */
/* @0xdcfbc mov r1, r7 */
/* @0xdcfc0 mov r0, r6 */
/* @0xdcfc4 bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i> */
/* @0xdcfc8 cmp r0, #1 */
/* @0xdcfcc beq 0xdd0a4 <_Z5DoAddjPhPKhP6VMExec+0xb80> */
/* @0xdcfd0 cmp r0, #0 */
/* @0xdcfd4 bne 0xdd0b0 <_Z5DoAddjPhPKhP6VMExec+0xb8c> */
/* @0xdcfd8 ldr r3, [sp, #0x44] */
/* @0xdcfdc bic r3, r3, #-16777216 */
/* @0xdcfe0 cmp r3, #1 */
/* @0xdcfe4 beq 0xdd180 <_Z5DoAddjPhPKhP6VMExec+0xc5c> */
/* @0xdcfe8 ldr r3, [sp, #0x54] */
/* @0xdcfec bic r3, r3, #-16777216 */
/* @0xdcff0 cmp r3, #1 */
/* @0xdcff4 beq 0xdd180 <_Z5DoAddjPhPKhP6VMExec+0xc5c> */
/* @0xdcff8 add r9, sp, #88 */
/* @0xdcffc mov r1, r4 */
/* @0xdd000 mov r2, #0 */
/* @0xdd004 mov r3, #0 */
/* @0xdd008 mov r0, r9 */
/* @0xdd00c mov r12, #0 */
/* @0xdd010 strd r2, r3, [sp, #88] */
/* @0xdd014 strd r2, r3, [sp, #104] */
/* @0xdd018 mvn r3, #-16777216 */
/* @0xdd01c str r12, [sp, #0x60] */
/* @0xdd020 str r12, [sp, #0x70] */
/* @0xdd024 str r3, [sp, #0x64] */
/* @0xdd028 str r3, [sp, #0x74] */
/* @0xdd02c bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xdd030 cmp r0, #1 */
/* @0xdd034 beq 0xdd480 <_Z5DoAddjPhPKhP6VMExec+0xf5c> */
/* @0xdd038 cmp r0, #0 */
/* @0xdd03c beq 0xdd418 <_Z5DoAddjPhPKhP6VMExec+0xef4> */
/* @0xdd040 ldr r3, [sp, #0x44] */
/* @0xdd044 sub r3, r3, #1 */
/* @0xdd048 bic r3, r3, #-16777216 */
/* @0xdd04c bic r3, r3, #3 */
/* @0xdd050 cmp r3, #0 */
/* @0xdd054 bne 0xdc8ec <_Z5DoAddjPhPKhP6VMExec+0x3c8> */
/* @0xdd058 mov r0, r4 */
/* @0xdd05c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd060 b 0xdc8ec <_Z5DoAddjPhPKhP6VMExec+0x3c8> */
/* @0xdd064 ldr r0, [pc, #0x474] */
/* @0xdd068 add r0, pc, r0 */
/* @0xdd06c bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xdd070 mov r0, r8 */
/* @0xdd074 b 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdd078 mov r0, r7 */
/* @0xdd07c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd080 b 0xdcaf4 <_Z5DoAddjPhPKhP6VMExec+0x5d0> */
/* @0xdd084 mov r0, r5 */
/* @0xdd088 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd08c b 0xdcac8 <_Z5DoAddjPhPKhP6VMExec+0x5a4> */
/* @0xdd090 ldr r0, [pc, #0x44c] */
/* @0xdd094 add r0, pc, r0 */
/* @0xdd098 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xdd09c mov r0, r8 */
/* @0xdd0a0 b 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdd0a4 ldr r0, [pc, #0x43c] */
/* @0xdd0a8 add r0, pc, r0 */
/* @0xdd0ac bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xdd0b0 ldr r3, [sp, #0x24] */
/* @0xdd0b4 sub r3, r3, #1 */
/* @0xdd0b8 bic r3, r3, #-16777216 */
/* @0xdd0bc bic r3, r3, #3 */
/* @0xdd0c0 cmp r3, #0 */
/* @0xdd0c4 beq 0xdd3dc <_Z5DoAddjPhPKhP6VMExec+0xeb8> */
/* @0xdd0c8 ldr r1, [sp, #0x34] */
/* @0xdd0cc mov r3, #0 */
/* @0xdd0d0 str r3, [sp, #0x20] */
/* @0xdd0d4 mov r2, #5 */
/* @0xdd0d8 sub r1, r1, #1 */
/* @0xdd0dc str r3, [sp, #0x18] */
/* @0xdd0e0 bic r3, r1, #-16777216 */
/* @0xdd0e4 str r2, [sp, #0x24] */
/* @0xdd0e8 bic r3, r3, #3 */
/* @0xdd0ec cmp r3, #0 */
/* @0xdd0f0 beq 0xdd3d0 <_Z5DoAddjPhPKhP6VMExec+0xeac> */
/* @0xdd0f4 ldr r1, [sp, #0x44] */
/* @0xdd0f8 mov r3, #0 */
/* @0xdd0fc str r3, [sp, #0x30] */
/* @0xdd100 mov r2, #5 */
/* @0xdd104 sub r1, r1, #1 */
/* @0xdd108 str r3, [sp, #0x28] */
/* @0xdd10c bic r3, r1, #-16777216 */
/* @0xdd110 str r2, [sp, #0x34] */
/* @0xdd114 bic r3, r3, #3 */
/* @0xdd118 cmp r3, #0 */
/* @0xdd11c beq 0xdd3c4 <_Z5DoAddjPhPKhP6VMExec+0xea0> */
/* @0xdd120 ldr r1, [sp, #0x54] */
/* @0xdd124 mov r3, #0 */
/* @0xdd128 str r3, [sp, #0x40] */
/* @0xdd12c mov r2, #5 */
/* @0xdd130 sub r1, r1, #1 */
/* @0xdd134 str r3, [sp, #0x38] */
/* @0xdd138 bic r3, r1, #-16777216 */
/* @0xdd13c str r2, [sp, #0x44] */
/* @0xdd140 bic r3, r3, #3 */
/* @0xdd144 cmp r3, #0 */
/* @0xdd148 bne 0xdc8ec <_Z5DoAddjPhPKhP6VMExec+0x3c8> */
/* @0xdd14c mov r0, r6 */
/* @0xdd150 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd154 mov r0, r8 */
/* @0xdd158 b 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdd15c ldr r0, [pc, #0x388] */
/* @0xdd160 add r0, pc, r0 */
/* @0xdd164 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xdd168 b 0xdcab0 <_Z5DoAddjPhPKhP6VMExec+0x58c> */
/* @0xdd16c ldr r0, [pc, #0x37c] */
/* @0xdd170 add r0, pc, r0 */
/* @0xdd174 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xdd178 mov r0, r8 */
/* @0xdd17c b 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdd180 add r9, sp, #88 */
/* @0xdd184 add r10, sp, #104 */
/* @0xdd188 mov r1, r4 */
/* @0xdd18c mov r2, #0 */
/* @0xdd190 mov r0, r9 */
/* @0xdd194 mov r3, #0 */
/* @0xdd198 strd r2, r3, [sp, #88] */
/* @0xdd19c strd r2, r3, [sp, #104] */
/* @0xdd1a0 mvn r3, #-16777216 */
/* @0xdd1a4 mov r2, #0 */
/* @0xdd1a8 str r3, [sp, #0x64] */
/* @0xdd1ac str r3, [sp, #0x74] */
/* @0xdd1b0 str r2, [sp, #0x60] */
/* @0xdd1b4 str r2, [sp, #0x70] */
/* @0xdd1b8 sub r2, r8, #16 */
/* @0xdd1bc str r2, [sp, #0x14] */
/* @0xdd1c0 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0xdd1c4 mov r1, r6 */
/* @0xdd1c8 mov r0, r10 */
/* @0xdd1cc bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0xdd1d0 ldr r2, [sp, #0x68] */
/* @0xdd1d4 mov r1, #1 */
/* @0xdd1d8 ldr r3, [sp, #0x58] */
/* @0xdd1dc cmp r2, #0 */
/* @0xdd1e0 str r1, [r8, #-0x4] */
/* @0xdd1e4 streq r2, [sp, #0xc] */
/* @0xdd1e8 ldrne r1, [r2] */
/* @0xdd1ec strne r1, [sp, #0xc] */
/* @0xdd1f0 cmp r3, #0 */
/* @0xdd1f4 mov r0, #12 */
/* @0xdd1f8 ldrne r1, [r3] */
/* @0xdd1fc moveq r1, r3 */
/* @0xdd200 cmp r2, #0 */
/* @0xdd204 ldrne r2, [r2, #0x8] */
/* @0xdd208 cmp r3, #0 */
/* @0xdd20c ldrne r3, [r3, #0x8] */
/* @0xdd210 str r1, [sp, #0x4] */
/* @0xdd214 str r3, [sp, #0x10] */
/* @0xdd218 ldr r3, [sp, #0x10] */
/* @0xdd21c add r2, r3, r2 */
/* @0xdd220 str r2, [sp, #0x8] */
/* @0xdd224 bl 0x27c524 <_Znwj> */
/* @0xdd228 ldr r2, [sp, #0x8] */
/* @0xdd22c mov r11, r0 */
/* @0xdd230 add r0, r2, #1 */
/* @0xdd234 bl 0xcef4c <_Z7YYAlloci> */
/* @0xdd238 ldr r1, [sp, #0x4] */
/* @0xdd23c ldr r3, [sp, #0x8] */
/* @0xdd240 mov r12, #1 */
/* @0xdd244 cmp r1, #0 */
/* @0xdd248 str r3, [r11, #0x8] */
/* @0xdd24c mov r2, r0 */
/* @0xdd250 stm r11, {r2, r12} */
/* @0xdd254 beq 0xdd264 <_Z5DoAddjPhPKhP6VMExec+0xd40> */
/* @0xdd258 str r0, [sp, #0x4] */
/* @0xdd25c bl 0xb65a4 <strcpy@plt> */
/* @0xdd260 ldr r2, [sp, #0x4] */
/* @0xdd264 ldr r3, [sp, #0xc] */
/* @0xdd268 cmp r3, #0 */
/* @0xdd26c beq 0xdd288 <_Z5DoAddjPhPKhP6VMExec+0xd64> */
/* @0xdd270 ldr r3, [sp, #0x10] */
/* @0xdd274 ldr r1, [sp, #0xc] */
/* @0xdd278 add r0, r2, r3 */
/* @0xdd27c str r2, [sp, #0x4] */
/* @0xdd280 bl 0xb65a4 <strcpy@plt> */
/* @0xdd284 ldr r2, [sp, #0x4] */
/* @0xdd288 ldr r3, [sp, #0x8] */
/* @0xdd28c mov r1, #0 */
/* @0xdd290 strb r1, [r2, r3] */
/* @0xdd294 ldr r2, [sp, #0x64] */
/* @0xdd298 str r11, [r8, #-0x10] */
/* @0xdd29c sub r3, r2, #1 */
/* @0xdd2a0 bic r3, r3, #-16777216 */
/* @0xdd2a4 bic r3, r3, #3 */
/* @0xdd2a8 cmp r3, r1 */
/* @0xdd2ac beq 0xdd474 <_Z5DoAddjPhPKhP6VMExec+0xf50> */
/* @0xdd2b0 ldr r1, [sp, #0x74] */
/* @0xdd2b4 mov r3, #0 */
/* @0xdd2b8 str r3, [sp, #0x60] */
/* @0xdd2bc mov r2, #5 */
/* @0xdd2c0 sub r1, r1, #1 */
/* @0xdd2c4 str r3, [sp, #0x58] */
/* @0xdd2c8 bic r3, r1, #-16777216 */
/* @0xdd2cc str r2, [sp, #0x64] */
/* @0xdd2d0 bic r3, r3, #3 */
/* @0xdd2d4 cmp r3, #0 */
/* @0xdd2d8 beq 0xdd40c <_Z5DoAddjPhPKhP6VMExec+0xee8> */
/* @0xdd2dc ldr r3, [sp, #0x24] */
/* @0xdd2e0 sub r3, r3, #1 */
/* @0xdd2e4 bic r3, r3, #-16777216 */
/* @0xdd2e8 bic r3, r3, #3 */
/* @0xdd2ec cmp r3, #0 */
/* @0xdd2f0 beq 0xdd400 <_Z5DoAddjPhPKhP6VMExec+0xedc> */
/* @0xdd2f4 ldr r1, [sp, #0x34] */
/* @0xdd2f8 mov r3, #0 */
/* @0xdd2fc str r3, [sp, #0x20] */
/* @0xdd300 mov r2, #5 */
/* @0xdd304 sub r1, r1, #1 */
/* @0xdd308 str r3, [sp, #0x18] */
/* @0xdd30c bic r3, r1, #-16777216 */
/* @0xdd310 str r2, [sp, #0x24] */
/* @0xdd314 bic r3, r3, #3 */
/* @0xdd318 cmp r3, #0 */
/* @0xdd31c beq 0xdd3f4 <_Z5DoAddjPhPKhP6VMExec+0xed0> */
/* @0xdd320 ldr r1, [sp, #0x44] */
/* @0xdd324 mov r3, #0 */
/* @0xdd328 str r3, [sp, #0x30] */
/* @0xdd32c mov r2, #5 */
/* @0xdd330 sub r1, r1, #1 */
/* @0xdd334 str r3, [sp, #0x28] */
/* @0xdd338 bic r3, r1, #-16777216 */
/* @0xdd33c str r2, [sp, #0x34] */
/* @0xdd340 bic r3, r3, #3 */
/* @0xdd344 cmp r3, #0 */
/* @0xdd348 beq 0xdd3e8 <_Z5DoAddjPhPKhP6VMExec+0xec4> */
/* @0xdd34c ldr r1, [sp, #0x54] */
/* @0xdd350 mov r3, #0 */
/* @0xdd354 str r3, [sp, #0x40] */
/* @0xdd358 mov r2, #5 */
/* @0xdd35c sub r1, r1, #1 */
/* @0xdd360 str r3, [sp, #0x38] */
/* @0xdd364 bic r3, r1, #-16777216 */
/* @0xdd368 str r2, [sp, #0x44] */
/* @0xdd36c bic r3, r3, #3 */
/* @0xdd370 cmp r3, #0 */
/* @0xdd374 ldrne r0, [sp, #0x14] */
/* @0xdd378 bne 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdd37c mov r0, r6 */
/* @0xdd380 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd384 ldr r0, [sp, #0x14] */
/* @0xdd388 b 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdd38c mov r0, r6 */
/* @0xdd390 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd394 b 0xdcc60 <_Z5DoAddjPhPKhP6VMExec+0x73c> */
/* @0xdd398 mov r0, r4 */
/* @0xdd39c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd3a0 b 0xdcc34 <_Z5DoAddjPhPKhP6VMExec+0x710> */
/* @0xdd3a4 mov r0, r9 */
/* @0xdd3a8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd3ac b 0xdcc8c <_Z5DoAddjPhPKhP6VMExec+0x768> */
/* @0xdd3b0 ldr r0, [pc, #0x13c] */
/* @0xdd3b4 add r0, pc, r0 */
/* @0xdd3b8 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xdd3bc mov r0, r8 */
/* @0xdd3c0 b 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdd3c4 mov r0, r4 */
/* @0xdd3c8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd3cc b 0xdd120 <_Z5DoAddjPhPKhP6VMExec+0xbfc> */
/* @0xdd3d0 mov r0, r7 */
/* @0xdd3d4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd3d8 b 0xdd0f4 <_Z5DoAddjPhPKhP6VMExec+0xbd0> */
/* @0xdd3dc mov r0, r5 */
/* @0xdd3e0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd3e4 b 0xdd0c8 <_Z5DoAddjPhPKhP6VMExec+0xba4> */
/* @0xdd3e8 mov r0, r4 */
/* @0xdd3ec bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd3f0 b 0xdd34c <_Z5DoAddjPhPKhP6VMExec+0xe28> */
/* @0xdd3f4 mov r0, r7 */
/* @0xdd3f8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd3fc b 0xdd320 <_Z5DoAddjPhPKhP6VMExec+0xdfc> */
/* @0xdd400 mov r0, r5 */
/* @0xdd404 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd408 b 0xdd2f4 <_Z5DoAddjPhPKhP6VMExec+0xdd0> */
/* @0xdd40c mov r0, r10 */
/* @0xdd410 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd414 b 0xdd2dc <_Z5DoAddjPhPKhP6VMExec+0xdb8> */
/* @0xdd418 add r10, sp, #104 */
/* @0xdd41c mov r1, r6 */
/* @0xdd420 mov r0, r10 */
/* @0xdd424 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xdd428 cmp r0, #1 */
/* @0xdd42c beq 0xdd490 <_Z5DoAddjPhPKhP6VMExec+0xf6c> */
/* @0xdd430 cmp r0, #0 */
/* @0xdd434 bne 0xdd040 <_Z5DoAddjPhPKhP6VMExec+0xb1c> */
/* @0xdd438 str r0, [r8, #-0x4] */
/* @0xdd43c sub r2, r8, #16 */
/* @0xdd440 vldr d6, [sp, #88] */
/* @0xdd444 vldr d7, [sp, #104] */
/* @0xdd448 vadd.f64 d5, d6, d7 */
/* @0xdd44c str r2, [sp, #0x14] */
/* @0xdd450 ldr r1, [sp, #0x64] */
/* @0xdd454 sub r1, r1, #1 */
/* @0xdd458 bic r1, r1, #-16777216 */
/* @0xdd45c bic r1, r1, #3 */
/* @0xdd460 cmp r1, #0 */
/* @0xdd464 vmov r2, r3, d5 */
/* @0xdd468 vstr s10, [r8, #-16] */
/* @0xdd46c str r3, [r8, #-0xc] */
/* @0xdd470 bne 0xdd2b0 <_Z5DoAddjPhPKhP6VMExec+0xd8c> */
/* @0xdd474 mov r0, r9 */
/* @0xdd478 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd47c b 0xdd2b0 <_Z5DoAddjPhPKhP6VMExec+0xd8c> */
/* @0xdd480 ldr r0, [pc, #0x70] */
/* @0xdd484 add r0, pc, r0 */
/* @0xdd488 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xdd48c b 0xdd040 <_Z5DoAddjPhPKhP6VMExec+0xb1c> */
/* @0xdd490 ldr r0, [pc, #0x64] */
/* @0xdd494 add r0, pc, r0 */
/* @0xdd498 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xdd49c b 0xdd040 <_Z5DoAddjPhPKhP6VMExec+0xb1c> */
/* @0xdd4a0 mov r6, r9 */
/* @0xdd4a4 mov r7, r10 */
/* @0xdd4a8 b 0xdc588 <_Z5DoAddjPhPKhP6VMExec+0x64> */
/* @0xdd4ac mov r8, r7 */
/* @0xdd4b0 b 0xdc5b8 <_Z5DoAddjPhPKhP6VMExec+0x94> */
/* @0xdd4b4 eoreq r6, r5, r12, asr r2 */
/* @0xdd4b8 eoreq r6, r5, r12, lsr r1 */
/* @0xdd4bc .word 0x002560fc */
/* @0xdd4c0 eoreq r6, r5, r8, lsl r1 */
/* @0xdd4c4 eoreq r6, r5, r12, lsl r1 */
/* @0xdd4c8 eoreq r6, r5, r0, ror #1 */
/* @0xdd4cc eoreq r6, r5, r0, lsl #2 */
/* @0xdd4d0 eoreq r5, r5, r4, ror sp */
/* @0xdd4d4 .word 0x00255eb4 */
/* @0xdd4d8 eoreq r6, r5, r4, lsl r0 */
/* @0xdd4dc eoreq r5, r5, r12, ror pc */
/* @0xdd4e0 eoreq r5, r5, r4, lsr r12 */
/* @0xdd4e4 eoreq r5, r5, r4, ror #26 */
/* @0xdd4e8 eoreq r5, r5, r12, lsl #25 */
/* @0xdd4ec mlaeq r5, r4, r11, r5 */
/* @0xdd4f0 .word 0x00255cd0 */
/* @0xdd4f4 .word 0x00255ad0 */
/* @0xdd4f8 .word 0x002558f4 */
/* @0xdd4fc eoreq r5, r5, r4, lsr #18 */

/* ── FUNC 0xdd500 · DoSub(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=2152 · insn=538 */
/* @0xdd500 ubfx r2, r0, #0x8, #0x4 */
/* @0xdd504 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xdd508 cmp r2, #1 */
/* @0xdd50c lsr r5, r0, #16 */
/* @0xdd510 sub sp, sp, #68 */
/* @0xdd514 mov r9, r1 */
/* @0xdd518 mov r11, r3 */
/* @0xdd51c uxtb r4, r5 */
/* @0xdd520 beq 0xdda70 <_Z5DoSubjPhPKhP6VMExec+0x570> */
/* @0xdd524 and r2, r4, #15 */
/* @0xdd528 cmp r2, #6 */
/* @0xdd52c addls pc, pc, r2, lsl #2 */
/* @0xdd530 b 0xddd10 <_Z5DoSubjPhPKhP6VMExec+0x810> */
/* @0xdd534 b 0xdd8ac <_Z5DoSubjPhPKhP6VMExec+0x3ac> */
/* @0xdd538 b 0xdd8b8 <_Z5DoSubjPhPKhP6VMExec+0x3b8> */
/* @0xdd53c b 0xdd8b8 <_Z5DoSubjPhPKhP6VMExec+0x3b8> */
/* @0xdd540 b 0xdd8ac <_Z5DoSubjPhPKhP6VMExec+0x3ac> */
/* @0xdd544 b 0xdd8b8 <_Z5DoSubjPhPKhP6VMExec+0x3b8> */
/* @0xdd548 b 0xdd8c4 <_Z5DoSubjPhPKhP6VMExec+0x3c4> */
/* @0xdd54c b 0xdd550 <_Z5DoSubjPhPKhP6VMExec+0x50> */
/* @0xdd550 ldr r1, [pc, #0x7cc] */
/* @0xdd554 mov r0, r3 */
/* @0xdd558 mov r5, r4 */
/* @0xdd55c mov r10, r9 */
/* @0xdd560 add r1, pc, r1 */
/* @0xdd564 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdd568 asr r2, r5, #4 */
/* @0xdd56c cmp r2, #6 */
/* @0xdd570 addls pc, pc, r2, lsl #2 */
/* @0xdd574 b 0xddd1c <_Z5DoSubjPhPKhP6VMExec+0x81c> */
/* @0xdd578 b 0xdd8a4 <_Z5DoSubjPhPKhP6VMExec+0x3a4> */
/* @0xdd57c b 0xdd89c <_Z5DoSubjPhPKhP6VMExec+0x39c> */
/* @0xdd580 b 0xdd89c <_Z5DoSubjPhPKhP6VMExec+0x39c> */
/* @0xdd584 b 0xdd8a4 <_Z5DoSubjPhPKhP6VMExec+0x3a4> */
/* @0xdd588 b 0xdd89c <_Z5DoSubjPhPKhP6VMExec+0x39c> */
/* @0xdd58c b 0xdd854 <_Z5DoSubjPhPKhP6VMExec+0x354> */
/* @0xdd590 b 0xdd594 <_Z5DoSubjPhPKhP6VMExec+0x94> */
/* @0xdd594 ldr r1, [pc, #0x78c] */
/* @0xdd598 mov r0, r11 */
/* @0xdd59c mov r6, r10 */
/* @0xdd5a0 add r1, pc, r1 */
/* @0xdd5a4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdd5a8 cmp r4, #101 */
/* @0xdd5ac addls pc, pc, r4, lsl #2 */
/* @0xdd5b0 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5b4 b 0xdd844 <_Z5DoSubjPhPKhP6VMExec+0x344> */
/* @0xdd5b8 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5bc b 0xdd844 <_Z5DoSubjPhPKhP6VMExec+0x344> */
/* @0xdd5c0 b 0xdd844 <_Z5DoSubjPhPKhP6VMExec+0x344> */
/* @0xdd5c4 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5c8 b 0xdd834 <_Z5DoSubjPhPKhP6VMExec+0x334> */
/* @0xdd5cc b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5d0 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5d4 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5d8 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5dc b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5e0 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5e4 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5e8 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5ec b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5f0 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5f4 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5f8 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5fc b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd600 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd604 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd608 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd60c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd610 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd614 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd618 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd61c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd620 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd624 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd628 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd62c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd630 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd634 b 0xdd844 <_Z5DoSubjPhPKhP6VMExec+0x344> */
/* @0xdd638 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd63c b 0xdd74c <_Z5DoSubjPhPKhP6VMExec+0x24c> */
/* @0xdd640 b 0xdd844 <_Z5DoSubjPhPKhP6VMExec+0x344> */
/* @0xdd644 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd648 b 0xdd834 <_Z5DoSubjPhPKhP6VMExec+0x334> */
/* @0xdd64c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd650 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd654 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd658 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd65c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd660 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd664 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd668 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd66c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd670 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd674 b 0xdd844 <_Z5DoSubjPhPKhP6VMExec+0x344> */
/* @0xdd678 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd67c b 0xdd844 <_Z5DoSubjPhPKhP6VMExec+0x344> */
/* @0xdd680 b 0xdd844 <_Z5DoSubjPhPKhP6VMExec+0x344> */
/* @0xdd684 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd688 b 0xdd834 <_Z5DoSubjPhPKhP6VMExec+0x334> */
/* @0xdd68c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd690 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd694 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd698 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd69c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6a0 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6a4 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6a8 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6ac b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6b0 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6b4 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6b8 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6bc b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6c0 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6c4 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6c8 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6cc b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6d0 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6d4 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6d8 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6dc b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6e0 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6e4 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6e8 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6ec b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6f0 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6f4 b 0xdd834 <_Z5DoSubjPhPKhP6VMExec+0x334> */
/* @0xdd6f8 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6fc b 0xdd834 <_Z5DoSubjPhPKhP6VMExec+0x334> */
/* @0xdd700 b 0xdd834 <_Z5DoSubjPhPKhP6VMExec+0x334> */
/* @0xdd704 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd708 b 0xdd834 <_Z5DoSubjPhPKhP6VMExec+0x334> */
/* @0xdd70c b 0xdd834 <_Z5DoSubjPhPKhP6VMExec+0x334> */
/* @0xdd710 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd714 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd718 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd71c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd720 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd724 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd728 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd72c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd730 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd734 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd738 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd73c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd740 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd744 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd748 b 0xdd834 <_Z5DoSubjPhPKhP6VMExec+0x334> */
/* @0xdd74c sub r6, r6, #4 */
/* @0xdd750 mov r7, #0 */
/* @0xdd754 mov r8, r6 */
/* @0xdd758 cmp r5, #51 */
/* @0xdd75c addls pc, pc, r5, lsl #2 */
/* @0xdd760 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd764 b 0xdd918 <_Z5DoSubjPhPKhP6VMExec+0x418> */
/* @0xdd768 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd76c b 0xdd9b4 <_Z5DoSubjPhPKhP6VMExec+0x4b4> */
/* @0xdd770 b 0xdd994 <_Z5DoSubjPhPKhP6VMExec+0x494> */
/* @0xdd774 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd778 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd77c b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd780 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd784 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd788 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd78c b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd790 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd794 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd798 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd79c b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7a0 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7a4 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7a8 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7ac b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7b0 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7b4 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7b8 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7bc b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7c0 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7c4 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7c8 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7cc b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7d0 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7d4 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7d8 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7dc b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7e0 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7e4 b 0xdd978 <_Z5DoSubjPhPKhP6VMExec+0x478> */
/* @0xdd7e8 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7ec b 0xdd960 <_Z5DoSubjPhPKhP6VMExec+0x460> */
/* @0xdd7f0 b 0xdd9f0 <_Z5DoSubjPhPKhP6VMExec+0x4f0> */
/* @0xdd7f4 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7f8 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7fc b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd800 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd804 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd808 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd80c b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd810 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd814 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd818 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd81c b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd820 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd824 b 0xdd9d0 <_Z5DoSubjPhPKhP6VMExec+0x4d0> */
/* @0xdd828 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd82c b 0xdda0c <_Z5DoSubjPhPKhP6VMExec+0x50c> */
/* @0xdd830 b 0xdd944 <_Z5DoSubjPhPKhP6VMExec+0x444> */
/* @0xdd834 sub r7, r6, #16 */
/* @0xdd838 mov r8, r7 */
/* @0xdd83c mov r6, r7 */
/* @0xdd840 b 0xdd758 <_Z5DoSubjPhPKhP6VMExec+0x258> */
/* @0xdd844 sub r6, r6, #8 */
/* @0xdd848 mov r7, #0 */
/* @0xdd84c mov r8, r6 */
/* @0xdd850 b 0xdd758 <_Z5DoSubjPhPKhP6VMExec+0x258> */
/* @0xdd854 ldr r3, [r10, #0xc] */
/* @0xdd858 cmp r3, #13 */
/* @0xdd85c addls pc, pc, r3, lsl #2 */
/* @0xdd860 b 0xddcb8 <_Z5DoSubjPhPKhP6VMExec+0x7b8> */
/* @0xdd864 b 0xddc88 <_Z5DoSubjPhPKhP6VMExec+0x788> */
/* @0xdd868 b 0xddc74 <_Z5DoSubjPhPKhP6VMExec+0x774> */
/* @0xdd86c b 0xddc60 <_Z5DoSubjPhPKhP6VMExec+0x760> */
/* @0xdd870 b 0xddc4c <_Z5DoSubjPhPKhP6VMExec+0x74c> */
/* @0xdd874 b 0xddcb8 <_Z5DoSubjPhPKhP6VMExec+0x7b8> */
/* @0xdd878 b 0xddc38 <_Z5DoSubjPhPKhP6VMExec+0x738> */
/* @0xdd87c b 0xddcb8 <_Z5DoSubjPhPKhP6VMExec+0x7b8> */
/* @0xdd880 b 0xddc2c <_Z5DoSubjPhPKhP6VMExec+0x72c> */
/* @0xdd884 b 0xddcb8 <_Z5DoSubjPhPKhP6VMExec+0x7b8> */
/* @0xdd888 b 0xddcb8 <_Z5DoSubjPhPKhP6VMExec+0x7b8> */
/* @0xdd88c b 0xddc1c <_Z5DoSubjPhPKhP6VMExec+0x71c> */
/* @0xdd890 b 0xddcb8 <_Z5DoSubjPhPKhP6VMExec+0x7b8> */
/* @0xdd894 b 0xddcb8 <_Z5DoSubjPhPKhP6VMExec+0x7b8> */
/* @0xdd898 b 0xddc88 <_Z5DoSubjPhPKhP6VMExec+0x788> */
/* @0xdd89c add r6, r10, #4 */
/* @0xdd8a0 b 0xdd5a8 <_Z5DoSubjPhPKhP6VMExec+0xa8> */
/* @0xdd8a4 add r6, r10, #8 */
/* @0xdd8a8 b 0xdd5a8 <_Z5DoSubjPhPKhP6VMExec+0xa8> */
/* @0xdd8ac add r10, r1, #8 */
/* @0xdd8b0 mov r5, r4 */
/* @0xdd8b4 b 0xdd568 <_Z5DoSubjPhPKhP6VMExec+0x68> */
/* @0xdd8b8 add r10, r1, #4 */
/* @0xdd8bc mov r5, r4 */
/* @0xdd8c0 b 0xdd568 <_Z5DoSubjPhPKhP6VMExec+0x68> */
/* @0xdd8c4 ldr r3, [r1, #0xc] */
/* @0xdd8c8 cmp r3, #13 */
/* @0xdd8cc addls pc, pc, r3, lsl #2 */
/* @0xdd8d0 b 0xddca0 <_Z5DoSubjPhPKhP6VMExec+0x7a0> */
/* @0xdd8d4 b 0xddc14 <_Z5DoSubjPhPKhP6VMExec+0x714> */
/* @0xdd8d8 b 0xddbfc <_Z5DoSubjPhPKhP6VMExec+0x6fc> */
/* @0xdd8dc b 0xddbe4 <_Z5DoSubjPhPKhP6VMExec+0x6e4> */
/* @0xdd8e0 b 0xddbcc <_Z5DoSubjPhPKhP6VMExec+0x6cc> */
/* @0xdd8e4 b 0xddca0 <_Z5DoSubjPhPKhP6VMExec+0x7a0> */
/* @0xdd8e8 b 0xddbb4 <_Z5DoSubjPhPKhP6VMExec+0x6b4> */
/* @0xdd8ec b 0xddca0 <_Z5DoSubjPhPKhP6VMExec+0x7a0> */
/* @0xdd8f0 b 0xddba8 <_Z5DoSubjPhPKhP6VMExec+0x6a8> */
/* @0xdd8f4 b 0xddca0 <_Z5DoSubjPhPKhP6VMExec+0x7a0> */
/* @0xdd8f8 b 0xddca0 <_Z5DoSubjPhPKhP6VMExec+0x7a0> */
/* @0xdd8fc b 0xddb98 <_Z5DoSubjPhPKhP6VMExec+0x698> */
/* @0xdd900 b 0xddca0 <_Z5DoSubjPhPKhP6VMExec+0x7a0> */
/* @0xdd904 b 0xddca0 <_Z5DoSubjPhPKhP6VMExec+0x7a0> */
/* @0xdd908 b 0xddc14 <_Z5DoSubjPhPKhP6VMExec+0x714> */
/* @0xdd90c mov r8, #0 */
/* @0xdd910 mov r7, r8 */
/* @0xdd914 b 0xdd758 <_Z5DoSubjPhPKhP6VMExec+0x258> */
/* @0xdd918 vldr d6, [r10] */
/* @0xdd91c vldr d7, [r9] */
/* @0xdd920 vsub.f64 d7, d6, d7 */
/* @0xdd924 mov r12, #0 */
/* @0xdd928 vstr d7, [r8] */
/* @0xdd92c cmp r7, #0 */
/* @0xdd930 beq 0xdda64 <_Z5DoSubjPhPKhP6VMExec+0x564> */
/* @0xdd934 mov r0, r6 */
/* @0xdd938 str r12, [r7, #0xc] */
/* @0xdd93c add sp, sp, #68 */
/* @0xdd940 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xdd944 ldrd r4, r5, [r10] */
/* @0xdd948 mov r12, #10 */
/* @0xdd94c ldrd r2, r3, [r9] */
/* @0xdd950 subs r4, r4, r2 */
/* @0xdd954 sbc r5, r5, r3 */
/* @0xdd958 strd r4, r5, [r8] */
/* @0xdd95c b 0xdd92c <_Z5DoSubjPhPKhP6VMExec+0x42c> */
/* @0xdd960 ldr r2, [r10] */
/* @0xdd964 mov r12, #7 */
/* @0xdd968 ldr r3, [r9] */
/* @0xdd96c rsb r3, r3, r2 */
/* @0xdd970 str r3, [r8] */
/* @0xdd974 b 0xdd92c <_Z5DoSubjPhPKhP6VMExec+0x42c> */
/* @0xdd978 vldr s14, [r10] */
/* @0xdd97c vcvt.f64.s32 d7, s14 */
/* @0xdd980 vldr d6, [r9] */
/* @0xdd984 mov r12, #0 */
/* @0xdd988 vsub.f64 d7, d7, d6 */
/* @0xdd98c vstr d7, [r8] */
/* @0xdd990 b 0xdd92c <_Z5DoSubjPhPKhP6VMExec+0x42c> */
/* @0xdd994 ldrd r0, r1, [r9] */
/* @0xdd998 bl 0x319164 <__floatdidf> */
/* @0xdd99c vldr d7, [r10] */
/* @0xdd9a0 mov r12, #0 */
/* @0xdd9a4 vmov d5, r0, r1 */
/* @0xdd9a8 vsub.f64 d7, d7, d5 */
/* @0xdd9ac vstr d7, [r8] */
/* @0xdd9b0 b 0xdd92c <_Z5DoSubjPhPKhP6VMExec+0x42c> */
/* @0xdd9b4 vldr s14, [r9] */
/* @0xdd9b8 vcvt.f64.s32 d7, s14 */
/* @0xdd9bc vldr d6, [r10] */
/* @0xdd9c0 mov r12, #0 */
/* @0xdd9c4 vsub.f64 d7, d6, d7 */
/* @0xdd9c8 vstr d7, [r8] */
/* @0xdd9cc b 0xdd92c <_Z5DoSubjPhPKhP6VMExec+0x42c> */
/* @0xdd9d0 ldrd r0, r1, [r10] */
/* @0xdd9d4 bl 0x319164 <__floatdidf> */
/* @0xdd9d8 vldr d7, [r9] */
/* @0xdd9dc mov r12, #0 */
/* @0xdd9e0 vmov d6, r0, r1 */
/* @0xdd9e4 vsub.f64 d7, d6, d7 */
/* @0xdd9e8 vstr d7, [r8] */
/* @0xdd9ec b 0xdd92c <_Z5DoSubjPhPKhP6VMExec+0x42c> */
/* @0xdd9f0 ldr r1, [r10] */
/* @0xdd9f4 mov r12, #10 */
/* @0xdd9f8 ldrd r2, r3, [r9] */
/* @0xdd9fc rsbs r2, r2, r1 */
/* @0xdda00 rsc r3, r3, r1, asr #31 */
/* @0xdda04 strd r2, r3, [r8] */
/* @0xdda08 b 0xdd92c <_Z5DoSubjPhPKhP6VMExec+0x42c> */
/* @0xdda0c ldr r1, [r9] */
/* @0xdda10 mov r12, #10 */
/* @0xdda14 ldrd r2, r3, [r10] */
/* @0xdda18 subs r2, r2, r1 */
/* @0xdda1c sbc r3, r3, r1, asr #31 */
/* @0xdda20 strd r2, r3, [r8] */
/* @0xdda24 b 0xdd92c <_Z5DoSubjPhPKhP6VMExec+0x42c> */
/* @0xdda28 ldr r1, [pc, #0x2fc] */
/* @0xdda2c mov r0, r11 */
/* @0xdda30 add r1, pc, r1 */
/* @0xdda34 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdda38 mov r12, #0 */
/* @0xdda3c b 0xdd92c <_Z5DoSubjPhPKhP6VMExec+0x42c> */
/* @0xdda40 ldr r0, [pc, #0x2e8] */
/* @0xdda44 add r0, pc, r0 */
/* @0xdda48 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xdda4c ldr r3, [sp, #0x2c] */
/* @0xdda50 sub r3, r3, #1 */
/* @0xdda54 bic r3, r3, #-16777216 */
/* @0xdda58 bic r3, r3, #3 */
/* @0xdda5c cmp r3, #0 */
/* @0xdda60 beq 0xddc90 <_Z5DoSubjPhPKhP6VMExec+0x790> */
/* @0xdda64 mov r0, r6 */
/* @0xdda68 add sp, sp, #68 */
/* @0xdda6c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xdda70 add r5, sp, #16 */
/* @0xdda74 mov r2, r1 */
/* @0xdda78 and r1, r4, #15 */
/* @0xdda7c mov r0, r5 */
/* @0xdda80 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xdda84 lsr r1, r4, #4 */
/* @0xdda88 mov r2, r0 */
/* @0xdda8c mov r0, sp */
/* @0xdda90 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xdda94 ldr r3, [sp, #0xc] */
/* @0xdda98 mvn r12, #-16777216 */
/* @0xdda9c and r3, r3, r12 */
/* @0xddaa0 cmp r3, r12 */
/* @0xddaa4 mov r6, r0 */
/* @0xddaa8 beq 0xddce0 <_Z5DoSubjPhPKhP6VMExec+0x7e0> */
/* @0xddaac ldr r3, [sp, #0x1c] */
/* @0xddab0 bic r3, r3, #-16777216 */
/* @0xddab4 cmp r3, r12 */
/* @0xddab8 beq 0xddccc <_Z5DoSubjPhPKhP6VMExec+0x7cc> */
/* @0xddabc add r4, sp, #32 */
/* @0xddac0 mov r1, sp */
/* @0xddac4 mov r2, #0 */
/* @0xddac8 mov r3, #0 */
/* @0xddacc mov r0, r4 */
/* @0xddad0 str r12, [sp, #0x2c] */
/* @0xddad4 str r12, [sp, #0x3c] */
/* @0xddad8 mov r12, #0 */
/* @0xddadc strd r2, r3, [sp, #32] */
/* @0xddae0 strd r2, r3, [sp, #48] */
/* @0xddae4 str r12, [sp, #0x28] */
/* @0xddae8 str r12, [sp, #0x38] */
/* @0xddaec bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xddaf0 cmp r0, #1 */
/* @0xddaf4 beq 0xddcf4 <_Z5DoSubjPhPKhP6VMExec+0x7f4> */
/* @0xddaf8 cmp r0, #0 */
/* @0xddafc bne 0xdda4c <_Z5DoSubjPhPKhP6VMExec+0x54c> */
/* @0xddb00 add r7, sp, #48 */
/* @0xddb04 mov r1, r5 */
/* @0xddb08 mov r0, r7 */
/* @0xddb0c bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xddb10 cmp r0, #1 */
/* @0xddb14 beq 0xdda40 <_Z5DoSubjPhPKhP6VMExec+0x540> */
/* @0xddb18 cmp r0, #0 */
/* @0xddb1c bne 0xdda4c <_Z5DoSubjPhPKhP6VMExec+0x54c> */
/* @0xddb20 str r0, [r6, #-0x4] */
/* @0xddb24 sub r5, r6, #16 */
/* @0xddb28 vldr d6, [sp, #32] */
/* @0xddb2c vldr d7, [sp, #48] */
/* @0xddb30 vsub.f64 d5, d6, d7 */
/* @0xddb34 ldr r1, [sp, #0x2c] */
/* @0xddb38 sub r1, r1, #1 */
/* @0xddb3c bic r1, r1, #-16777216 */
/* @0xddb40 bic r1, r1, #3 */
/* @0xddb44 cmp r1, #0 */
/* @0xddb48 vmov r2, r3, d5 */
/* @0xddb4c vstr s10, [r6, #-16] */
/* @0xddb50 str r3, [r6, #-0xc] */
/* @0xddb54 beq 0xddd04 <_Z5DoSubjPhPKhP6VMExec+0x804> */
/* @0xddb58 ldr r1, [sp, #0x3c] */
/* @0xddb5c mov r3, #0 */
/* @0xddb60 str r3, [sp, #0x28] */
/* @0xddb64 mov r2, #5 */
/* @0xddb68 sub r1, r1, #1 */
/* @0xddb6c str r3, [sp, #0x20] */
/* @0xddb70 bic r3, r1, #-16777216 */
/* @0xddb74 str r2, [sp, #0x2c] */
/* @0xddb78 bic r3, r3, #3 */
/* @0xddb7c cmp r3, #0 */
/* @0xddb80 movne r0, r5 */
/* @0xddb84 bne 0xdd93c <_Z5DoSubjPhPKhP6VMExec+0x43c> */
/* @0xddb88 mov r0, r7 */
/* @0xddb8c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xddb90 mov r0, r5 */
/* @0xddb94 b 0xdd93c <_Z5DoSubjPhPKhP6VMExec+0x43c> */
/* @0xddb98 and r5, r5, #240 */
/* @0xddb9c orr r5, r5, #3 */
/* @0xddba0 add r10, r9, #16 */
/* @0xddba4 b 0xdd568 <_Z5DoSubjPhPKhP6VMExec+0x68> */
/* @0xddba8 and r5, r5, #240 */
/* @0xddbac orr r5, r5, #2 */
/* @0xddbb0 b 0xddba0 <_Z5DoSubjPhPKhP6VMExec+0x6a0> */
/* @0xddbb4 ldr r1, [pc, #0x178] */
/* @0xddbb8 mov r0, r11 */
/* @0xddbbc mov r5, r4 */
/* @0xddbc0 add r1, pc, r1 */
/* @0xddbc4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddbc8 b 0xddba0 <_Z5DoSubjPhPKhP6VMExec+0x6a0> */
/* @0xddbcc ldr r1, [pc, #0x164] */
/* @0xddbd0 mov r0, r11 */
/* @0xddbd4 mov r5, r4 */
/* @0xddbd8 add r1, pc, r1 */
/* @0xddbdc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddbe0 b 0xddba0 <_Z5DoSubjPhPKhP6VMExec+0x6a0> */
/* @0xddbe4 ldr r1, [pc, #0x150] */
/* @0xddbe8 mov r0, r11 */
/* @0xddbec mov r5, r4 */
/* @0xddbf0 add r1, pc, r1 */
/* @0xddbf4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddbf8 b 0xddba0 <_Z5DoSubjPhPKhP6VMExec+0x6a0> */
/* @0xddbfc ldr r1, [pc, #0x13c] */
/* @0xddc00 mov r0, r11 */
/* @0xddc04 mov r5, r4 */
/* @0xddc08 add r1, pc, r1 */
/* @0xddc0c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddc10 b 0xddba0 <_Z5DoSubjPhPKhP6VMExec+0x6a0> */
/* @0xddc14 and r5, r4, #240 */
/* @0xddc18 b 0xddba0 <_Z5DoSubjPhPKhP6VMExec+0x6a0> */
/* @0xddc1c and r5, r5, #15 */
/* @0xddc20 orr r5, r5, #48 */
/* @0xddc24 add r6, r10, #16 */
/* @0xddc28 b 0xdd5a8 <_Z5DoSubjPhPKhP6VMExec+0xa8> */
/* @0xddc2c and r5, r5, #15 */
/* @0xddc30 orr r5, r5, #32 */
/* @0xddc34 b 0xddc24 <_Z5DoSubjPhPKhP6VMExec+0x724> */
/* @0xddc38 ldr r1, [pc, #0x104] */
/* @0xddc3c mov r0, r11 */
/* @0xddc40 add r1, pc, r1 */
/* @0xddc44 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddc48 b 0xddc24 <_Z5DoSubjPhPKhP6VMExec+0x724> */
/* @0xddc4c ldr r1, [pc, #0xf4] */
/* @0xddc50 mov r0, r11 */
/* @0xddc54 add r1, pc, r1 */
/* @0xddc58 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddc5c b 0xddc24 <_Z5DoSubjPhPKhP6VMExec+0x724> */
/* @0xddc60 ldr r1, [pc, #0xe4] */
/* @0xddc64 mov r0, r11 */
/* @0xddc68 add r1, pc, r1 */
/* @0xddc6c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddc70 b 0xddc24 <_Z5DoSubjPhPKhP6VMExec+0x724> */
/* @0xddc74 ldr r1, [pc, #0xd4] */
/* @0xddc78 mov r0, r11 */
/* @0xddc7c add r1, pc, r1 */
/* @0xddc80 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddc84 b 0xddc24 <_Z5DoSubjPhPKhP6VMExec+0x724> */
/* @0xddc88 and r5, r5, #15 */
/* @0xddc8c b 0xddc24 <_Z5DoSubjPhPKhP6VMExec+0x724> */
/* @0xddc90 mov r0, r4 */
/* @0xddc94 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xddc98 mov r0, r6 */
/* @0xddc9c b 0xdd93c <_Z5DoSubjPhPKhP6VMExec+0x43c> */
/* @0xddca0 ldr r1, [pc, #0xac] */
/* @0xddca4 mov r0, r11 */
/* @0xddca8 mov r5, r4 */
/* @0xddcac add r1, pc, r1 */
/* @0xddcb0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddcb4 b 0xddba0 <_Z5DoSubjPhPKhP6VMExec+0x6a0> */
/* @0xddcb8 ldr r1, [pc, #0x98] */
/* @0xddcbc mov r0, r11 */
/* @0xddcc0 add r1, pc, r1 */
/* @0xddcc4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddcc8 b 0xddc24 <_Z5DoSubjPhPKhP6VMExec+0x724> */
/* @0xddccc ldr r0, [pc, #0x88] */
/* @0xddcd0 add r0, pc, r0 */
/* @0xddcd4 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xddcd8 mov r0, r6 */
/* @0xddcdc b 0xdd93c <_Z5DoSubjPhPKhP6VMExec+0x43c> */
/* @0xddce0 ldr r0, [pc, #0x78] */
/* @0xddce4 add r0, pc, r0 */
/* @0xddce8 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xddcec mov r0, r6 */
/* @0xddcf0 b 0xdd93c <_Z5DoSubjPhPKhP6VMExec+0x43c> */
/* @0xddcf4 ldr r0, [pc, #0x68] */
/* @0xddcf8 add r0, pc, r0 */
/* @0xddcfc bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xddd00 b 0xdda4c <_Z5DoSubjPhPKhP6VMExec+0x54c> */
/* @0xddd04 mov r0, r4 */
/* @0xddd08 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xddd0c b 0xddb58 <_Z5DoSubjPhPKhP6VMExec+0x658> */
/* @0xddd10 mov r5, r4 */
/* @0xddd14 mov r10, r1 */
/* @0xddd18 b 0xdd568 <_Z5DoSubjPhPKhP6VMExec+0x68> */
/* @0xddd1c mov r6, r10 */
/* @0xddd20 b 0xdd5a8 <_Z5DoSubjPhPKhP6VMExec+0xa8> */
/* @0xddd24 eoreq r5, r5, r12, asr #22 */
/* @0xddd28 eoreq r5, r5, r12, lsl #22 */
/* @0xddd2c eoreq r5, r5, r8, lsr #15 */
/* @0xddd30 eoreq r5, r5, r0, lsr #12 */
/* @0xddd34 eoreq r5, r5, r8, asr #10 */
/* @0xddd38 eoreq r5, r5, r0, lsl r5 */
/* @0xddd3c eoreq r5, r5, r4, lsr r5 */
/* @0xddd40 eoreq r5, r5, r4, lsr #9 */
/* @0xddd44 eoreq r5, r5, r0, asr #10 */
/* @0xddd48 eoreq r5, r5, r12, lsl #10 */
/* @0xddd4c eoreq r5, r5, r4, lsr r5 */
/* @0xddd50 eoreq r5, r5, r0, lsr r4 */
/* @0xddd54 mlaeq r5, r4, r4, r5 */
/* @0xddd58 .word 0x002554f8 */
/* @0xddd5c eoreq r5, r5, r8, lsr #6 */
/* @0xddd60 .word 0x002552f0 */
/* @0xddd64 eoreq r5, r5, r4, lsr #6 */

/* ── FUNC 0xddd68 · DoDiv(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=2172 · insn=543 */
/* @0xddd68 ubfx r2, r0, #0x8, #0x4 */
/* @0xddd6c lsr r0, r0, #16 */
/* @0xddd70 cmp r2, #1 */
/* @0xddd74 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xddd78 mov r10, r1 */
/* @0xddd7c sub sp, sp, #64 */
/* @0xddd80 mov r9, r3 */
/* @0xddd84 uxtb r4, r0 */
/* @0xddd88 beq 0xde2b4 <_Z5DoDivjPhPKhP6VMExec+0x54c> */
/* @0xddd8c and r3, r4, #15 */
/* @0xddd90 cmp r3, #6 */
/* @0xddd94 addls pc, pc, r3, lsl #2 */
/* @0xddd98 b 0xde584 <_Z5DoDivjPhPKhP6VMExec+0x81c> */
/* @0xddd9c b 0xde0d4 <_Z5DoDivjPhPKhP6VMExec+0x36c> */
/* @0xddda0 b 0xde0e0 <_Z5DoDivjPhPKhP6VMExec+0x378> */
/* @0xddda4 b 0xde0e0 <_Z5DoDivjPhPKhP6VMExec+0x378> */
/* @0xddda8 b 0xde0d4 <_Z5DoDivjPhPKhP6VMExec+0x36c> */
/* @0xdddac b 0xde0e0 <_Z5DoDivjPhPKhP6VMExec+0x378> */
/* @0xdddb0 b 0xde0ec <_Z5DoDivjPhPKhP6VMExec+0x384> */
/* @0xdddb4 b 0xdddb8 <_Z5DoDivjPhPKhP6VMExec+0x50> */
/* @0xdddb8 ldr r1, [pc, #0x7d8] */
/* @0xdddbc mov r0, r9 */
/* @0xdddc0 mov r5, r4 */
/* @0xdddc4 mov r7, r10 */
/* @0xdddc8 add r1, pc, r1 */
/* @0xdddcc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdddd0 asr r3, r5, #4 */
/* @0xdddd4 cmp r3, #6 */
/* @0xdddd8 addls pc, pc, r3, lsl #2 */
/* @0xddddc b 0xde590 <_Z5DoDivjPhPKhP6VMExec+0x828> */
/* @0xddde0 b 0xde0cc <_Z5DoDivjPhPKhP6VMExec+0x364> */
/* @0xddde4 b 0xde0c4 <_Z5DoDivjPhPKhP6VMExec+0x35c> */
/* @0xddde8 b 0xde0c4 <_Z5DoDivjPhPKhP6VMExec+0x35c> */
/* @0xdddec b 0xde0cc <_Z5DoDivjPhPKhP6VMExec+0x364> */
/* @0xdddf0 b 0xde0c4 <_Z5DoDivjPhPKhP6VMExec+0x35c> */
/* @0xdddf4 b 0xde07c <_Z5DoDivjPhPKhP6VMExec+0x314> */
/* @0xdddf8 b 0xdddfc <_Z5DoDivjPhPKhP6VMExec+0x94> */
/* @0xdddfc ldr r1, [pc, #0x798] */
/* @0xdde00 mov r0, r9 */
/* @0xdde04 mov r6, r7 */
/* @0xdde08 add r1, pc, r1 */
/* @0xdde0c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdde10 cmp r4, #85 */
/* @0xdde14 addls pc, pc, r4, lsl #2 */
/* @0xdde18 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde1c b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xdde20 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde24 b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xdde28 b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xdde2c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde30 b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xdde34 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde38 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde3c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde40 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde44 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde48 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde4c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde50 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde54 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde58 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde5c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde60 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde64 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde68 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde6c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde70 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde74 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde78 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde7c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde80 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde84 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde88 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde8c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde90 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde94 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde98 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde9c b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xddea0 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddea4 b 0xddf74 <_Z5DoDivjPhPKhP6VMExec+0x20c> */
/* @0xddea8 b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xddeac b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddeb0 b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xddeb4 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddeb8 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddebc b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddec0 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddec4 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddec8 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddecc b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdded0 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdded4 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdded8 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddedc b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xddee0 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddee4 b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xddee8 b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xddeec b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddef0 b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xddef4 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddef8 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddefc b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf00 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf04 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf08 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf0c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf10 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf14 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf18 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf1c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf20 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf24 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf28 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf2c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf30 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf34 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf38 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf3c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf40 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf44 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf48 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf4c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf50 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf54 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf58 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf5c b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xddf60 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf64 b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xddf68 b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xddf6c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf70 b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xddf74 sub r6, r6, #4 */
/* @0xddf78 mov r4, #0 */
/* @0xddf7c mov r8, r6 */
/* @0xddf80 cmp r5, #51 */
/* @0xddf84 addls pc, pc, r5, lsl #2 */
/* @0xddf88 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddf8c b 0xde140 <_Z5DoDivjPhPKhP6VMExec+0x3d8> */
/* @0xddf90 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddf94 b 0xde234 <_Z5DoDivjPhPKhP6VMExec+0x4cc> */
/* @0xddf98 b 0xde214 <_Z5DoDivjPhPKhP6VMExec+0x4ac> */
/* @0xddf9c b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfa0 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfa4 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfa8 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfac b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfb0 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfb4 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfb8 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfbc b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfc0 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfc4 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfc8 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfcc b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfd0 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfd4 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfd8 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfdc b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfe0 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfe4 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfe8 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfec b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddff0 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddff4 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddff8 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddffc b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde000 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde004 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde008 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde00c b 0xde250 <_Z5DoDivjPhPKhP6VMExec+0x4e8> */
/* @0xde010 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde014 b 0xde18c <_Z5DoDivjPhPKhP6VMExec+0x424> */
/* @0xde018 b 0xde1cc <_Z5DoDivjPhPKhP6VMExec+0x464> */
/* @0xde01c b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde020 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde024 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde028 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde02c b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde030 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde034 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde038 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde03c b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde040 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde044 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde048 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde04c b 0xde1ac <_Z5DoDivjPhPKhP6VMExec+0x444> */
/* @0xde050 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde054 b 0xde1f0 <_Z5DoDivjPhPKhP6VMExec+0x488> */
/* @0xde058 b 0xde16c <_Z5DoDivjPhPKhP6VMExec+0x404> */
/* @0xde05c sub r4, r6, #16 */
/* @0xde060 mov r8, r4 */
/* @0xde064 mov r6, r4 */
/* @0xde068 b 0xddf80 <_Z5DoDivjPhPKhP6VMExec+0x218> */
/* @0xde06c sub r6, r6, #8 */
/* @0xde070 mov r4, #0 */
/* @0xde074 mov r8, r6 */
/* @0xde078 b 0xddf80 <_Z5DoDivjPhPKhP6VMExec+0x218> */
/* @0xde07c ldr r3, [r7, #0xc] */
/* @0xde080 cmp r3, #13 */
/* @0xde084 addls pc, pc, r3, lsl #2 */
/* @0xde088 b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde08c b 0xde4e4 <_Z5DoDivjPhPKhP6VMExec+0x77c> */
/* @0xde090 b 0xde4d0 <_Z5DoDivjPhPKhP6VMExec+0x768> */
/* @0xde094 b 0xde4bc <_Z5DoDivjPhPKhP6VMExec+0x754> */
/* @0xde098 b 0xde4a8 <_Z5DoDivjPhPKhP6VMExec+0x740> */
/* @0xde09c b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde0a0 b 0xde494 <_Z5DoDivjPhPKhP6VMExec+0x72c> */
/* @0xde0a4 b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde0a8 b 0xde488 <_Z5DoDivjPhPKhP6VMExec+0x720> */
/* @0xde0ac b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde0b0 b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde0b4 b 0xde478 <_Z5DoDivjPhPKhP6VMExec+0x710> */
/* @0xde0b8 b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde0bc b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde0c0 b 0xde4e4 <_Z5DoDivjPhPKhP6VMExec+0x77c> */
/* @0xde0c4 add r6, r7, #4 */
/* @0xde0c8 b 0xdde10 <_Z5DoDivjPhPKhP6VMExec+0xa8> */
/* @0xde0cc add r6, r7, #8 */
/* @0xde0d0 b 0xdde10 <_Z5DoDivjPhPKhP6VMExec+0xa8> */
/* @0xde0d4 add r7, r1, #8 */
/* @0xde0d8 mov r5, r4 */
/* @0xde0dc b 0xdddd0 <_Z5DoDivjPhPKhP6VMExec+0x68> */
/* @0xde0e0 add r7, r1, #4 */
/* @0xde0e4 mov r5, r4 */
/* @0xde0e8 b 0xdddd0 <_Z5DoDivjPhPKhP6VMExec+0x68> */
/* @0xde0ec ldr r3, [r1, #0xc] */
/* @0xde0f0 cmp r3, #13 */
/* @0xde0f4 addls pc, pc, r3, lsl #2 */
/* @0xde0f8 b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde0fc b 0xde470 <_Z5DoDivjPhPKhP6VMExec+0x708> */
/* @0xde100 b 0xde458 <_Z5DoDivjPhPKhP6VMExec+0x6f0> */
/* @0xde104 b 0xde440 <_Z5DoDivjPhPKhP6VMExec+0x6d8> */
/* @0xde108 b 0xde428 <_Z5DoDivjPhPKhP6VMExec+0x6c0> */
/* @0xde10c b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde110 b 0xde410 <_Z5DoDivjPhPKhP6VMExec+0x6a8> */
/* @0xde114 b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde118 b 0xde404 <_Z5DoDivjPhPKhP6VMExec+0x69c> */
/* @0xde11c b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde120 b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde124 b 0xde3f4 <_Z5DoDivjPhPKhP6VMExec+0x68c> */
/* @0xde128 b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde12c b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde130 b 0xde470 <_Z5DoDivjPhPKhP6VMExec+0x708> */
/* @0xde134 mov r8, #0 */
/* @0xde138 mov r4, r8 */
/* @0xde13c b 0xddf80 <_Z5DoDivjPhPKhP6VMExec+0x218> */
/* @0xde140 vldr d6, [r7] */
/* @0xde144 vldr d7, [r10] */
/* @0xde148 vdiv.f64 d7, d6, d7 */
/* @0xde14c mov r3, #0 */
/* @0xde150 vstr d7, [r8] */
/* @0xde154 cmp r4, #0 */
/* @0xde158 beq 0xde2a8 <_Z5DoDivjPhPKhP6VMExec+0x540> */
/* @0xde15c mov r0, r6 */
/* @0xde160 str r3, [r4, #0xc] */
/* @0xde164 add sp, sp, #64 */
/* @0xde168 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xde16c ldrd r2, r3, [r10] */
/* @0xde170 orrs r1, r2, r3 */
/* @0xde174 beq 0xde3dc <_Z5DoDivjPhPKhP6VMExec+0x674> */
/* @0xde178 ldrd r0, r1, [r7] */
/* @0xde17c bl 0x319414 <__aeabi_ldivmod> */
/* @0xde180 mov r3, #10 */
/* @0xde184 strd r0, r1, [r8] */
/* @0xde188 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde18c ldr r1, [r10] */
/* @0xde190 cmp r1, #0 */
/* @0xde194 beq 0xde53c <_Z5DoDivjPhPKhP6VMExec+0x7d4> */
/* @0xde198 ldr r0, [r7] */
/* @0xde19c bl 0x318d10 <__divsi3> */
/* @0xde1a0 mov r3, #7 */
/* @0xde1a4 str r0, [r8] */
/* @0xde1a8 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde1ac ldrd r0, r1, [r7] */
/* @0xde1b0 bl 0x319164 <__floatdidf> */
/* @0xde1b4 vldr d7, [r10] */
/* @0xde1b8 mov r3, #0 */
/* @0xde1bc vmov d6, r0, r1 */
/* @0xde1c0 vdiv.f64 d7, d6, d7 */
/* @0xde1c4 vstr d7, [r8] */
/* @0xde1c8 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde1cc ldrd r2, r3, [r10] */
/* @0xde1d0 orrs r1, r2, r3 */
/* @0xde1d4 beq 0xde3dc <_Z5DoDivjPhPKhP6VMExec+0x674> */
/* @0xde1d8 ldr r0, [r7] */
/* @0xde1dc asr r1, r0, #31 */
/* @0xde1e0 bl 0x319414 <__aeabi_ldivmod> */
/* @0xde1e4 mov r3, #10 */
/* @0xde1e8 strd r0, r1, [r8] */
/* @0xde1ec b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde1f0 ldr r2, [r10] */
/* @0xde1f4 cmp r2, #0 */
/* @0xde1f8 beq 0xde3dc <_Z5DoDivjPhPKhP6VMExec+0x674> */
/* @0xde1fc ldrd r0, r1, [r7] */
/* @0xde200 asr r3, r2, #31 */
/* @0xde204 bl 0x319414 <__aeabi_ldivmod> */
/* @0xde208 mov r3, #10 */
/* @0xde20c strd r0, r1, [r8] */
/* @0xde210 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde214 ldrd r0, r1, [r10] */
/* @0xde218 bl 0x319164 <__floatdidf> */
/* @0xde21c vldr d7, [r7] */
/* @0xde220 mov r3, #0 */
/* @0xde224 vmov d5, r0, r1 */
/* @0xde228 vdiv.f64 d7, d7, d5 */
/* @0xde22c vstr d7, [r8] */
/* @0xde230 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde234 vldr s14, [r10] */
/* @0xde238 vcvt.f64.s32 d7, s14 */
/* @0xde23c vldr d6, [r7] */
/* @0xde240 mov r3, #0 */
/* @0xde244 vdiv.f64 d7, d6, d7 */
/* @0xde248 vstr d7, [r8] */
/* @0xde24c b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde250 vldr s14, [r7] */
/* @0xde254 vcvt.f64.s32 d7, s14 */
/* @0xde258 vldr d6, [r10] */
/* @0xde25c mov r3, #0 */
/* @0xde260 vdiv.f64 d7, d7, d6 */
/* @0xde264 vstr d7, [r8] */
/* @0xde268 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde26c ldr r1, [pc, #0x32c] */
/* @0xde270 mov r0, r9 */
/* @0xde274 add r1, pc, r1 */
/* @0xde278 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde27c mov r3, #0 */
/* @0xde280 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde284 ldr r0, [pc, #0x318] */
/* @0xde288 add r0, pc, r0 */
/* @0xde28c bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xde290 ldr r3, [sp, #0x2c] */
/* @0xde294 sub r3, r3, #1 */
/* @0xde298 bic r3, r3, #-16777216 */
/* @0xde29c bic r3, r3, #3 */
/* @0xde2a0 cmp r3, #0 */
/* @0xde2a4 beq 0xde4ec <_Z5DoDivjPhPKhP6VMExec+0x784> */
/* @0xde2a8 mov r0, r6 */
/* @0xde2ac add sp, sp, #64 */
/* @0xde2b0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xde2b4 add r5, sp, #16 */
/* @0xde2b8 mov r2, r1 */
/* @0xde2bc and r1, r4, #15 */
/* @0xde2c0 mov r0, r5 */
/* @0xde2c4 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xde2c8 lsr r1, r4, #4 */
/* @0xde2cc mov r2, r0 */
/* @0xde2d0 mov r0, sp */
/* @0xde2d4 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xde2d8 ldr r3, [sp, #0xc] */
/* @0xde2dc mvn r12, #-16777216 */
/* @0xde2e0 and r3, r3, r12 */
/* @0xde2e4 cmp r3, r12 */
/* @0xde2e8 mov r6, r0 */
/* @0xde2ec beq 0xde554 <_Z5DoDivjPhPKhP6VMExec+0x7ec> */
/* @0xde2f0 ldr r3, [sp, #0x1c] */
/* @0xde2f4 bic r3, r3, #-16777216 */
/* @0xde2f8 cmp r3, r12 */
/* @0xde2fc beq 0xde528 <_Z5DoDivjPhPKhP6VMExec+0x7c0> */
/* @0xde300 add r4, sp, #32 */
/* @0xde304 mov r1, sp */
/* @0xde308 mov r2, #0 */
/* @0xde30c mov r3, #0 */
/* @0xde310 mov r0, r4 */
/* @0xde314 str r12, [sp, #0x2c] */
/* @0xde318 str r12, [sp, #0x3c] */
/* @0xde31c mov r12, #0 */
/* @0xde320 strd r2, r3, [sp, #32] */
/* @0xde324 strd r2, r3, [sp, #48] */
/* @0xde328 str r12, [sp, #0x28] */
/* @0xde32c str r12, [sp, #0x38] */
/* @0xde330 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xde334 cmp r0, #1 */
/* @0xde338 beq 0xde568 <_Z5DoDivjPhPKhP6VMExec+0x800> */
/* @0xde33c cmp r0, #0 */
/* @0xde340 bne 0xde290 <_Z5DoDivjPhPKhP6VMExec+0x528> */
/* @0xde344 add r7, sp, #48 */
/* @0xde348 mov r1, r5 */
/* @0xde34c mov r0, r7 */
/* @0xde350 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xde354 cmp r0, #1 */
/* @0xde358 beq 0xde284 <_Z5DoDivjPhPKhP6VMExec+0x51c> */
/* @0xde35c cmp r0, #0 */
/* @0xde360 bne 0xde290 <_Z5DoDivjPhPKhP6VMExec+0x528> */
/* @0xde364 str r0, [r6, #-0x4] */
/* @0xde368 sub r5, r6, #16 */
/* @0xde36c vldr d6, [sp, #32] */
/* @0xde370 vldr d7, [sp, #48] */
/* @0xde374 vdiv.f64 d5, d6, d7 */
/* @0xde378 ldr r1, [sp, #0x2c] */
/* @0xde37c sub r1, r1, #1 */
/* @0xde380 bic r1, r1, #-16777216 */
/* @0xde384 bic r1, r1, #3 */
/* @0xde388 cmp r1, #0 */
/* @0xde38c vmov r2, r3, d5 */
/* @0xde390 vstr s10, [r6, #-16] */
/* @0xde394 str r3, [r6, #-0xc] */
/* @0xde398 beq 0xde578 <_Z5DoDivjPhPKhP6VMExec+0x810> */
/* @0xde39c ldr r1, [sp, #0x3c] */
/* @0xde3a0 mov r3, #0 */
/* @0xde3a4 str r3, [sp, #0x28] */
/* @0xde3a8 mov r2, #5 */
/* @0xde3ac sub r1, r1, #1 */
/* @0xde3b0 str r3, [sp, #0x20] */
/* @0xde3b4 bic r3, r1, #-16777216 */
/* @0xde3b8 str r2, [sp, #0x2c] */
/* @0xde3bc bic r3, r3, #3 */
/* @0xde3c0 cmp r3, #0 */
/* @0xde3c4 movne r0, r5 */
/* @0xde3c8 bne 0xde164 <_Z5DoDivjPhPKhP6VMExec+0x3fc> */
/* @0xde3cc mov r0, r7 */
/* @0xde3d0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xde3d4 mov r0, r5 */
/* @0xde3d8 b 0xde164 <_Z5DoDivjPhPKhP6VMExec+0x3fc> */
/* @0xde3dc ldr r1, [pc, #0x1c4] */
/* @0xde3e0 mov r0, r9 */
/* @0xde3e4 add r1, pc, r1 */
/* @0xde3e8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde3ec mov r3, #10 */
/* @0xde3f0 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde3f4 and r0, r0, #240 */
/* @0xde3f8 orr r5, r0, #3 */
/* @0xde3fc add r7, r10, #16 */
/* @0xde400 b 0xdddd0 <_Z5DoDivjPhPKhP6VMExec+0x68> */
/* @0xde404 and r0, r0, #240 */
/* @0xde408 orr r5, r0, #2 */
/* @0xde40c b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde410 ldr r1, [pc, #0x194] */
/* @0xde414 mov r0, r9 */
/* @0xde418 mov r5, r4 */
/* @0xde41c add r1, pc, r1 */
/* @0xde420 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde424 b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde428 ldr r1, [pc, #0x180] */
/* @0xde42c mov r0, r9 */
/* @0xde430 mov r5, r4 */
/* @0xde434 add r1, pc, r1 */
/* @0xde438 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde43c b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde440 ldr r1, [pc, #0x16c] */
/* @0xde444 mov r0, r9 */
/* @0xde448 mov r5, r4 */
/* @0xde44c add r1, pc, r1 */
/* @0xde450 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde454 b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde458 ldr r1, [pc, #0x158] */
/* @0xde45c mov r0, r9 */
/* @0xde460 mov r5, r4 */
/* @0xde464 add r1, pc, r1 */
/* @0xde468 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde46c b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde470 and r5, r4, #240 */
/* @0xde474 b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde478 and r5, r5, #15 */
/* @0xde47c orr r5, r5, #48 */
/* @0xde480 add r6, r7, #16 */
/* @0xde484 b 0xdde10 <_Z5DoDivjPhPKhP6VMExec+0xa8> */
/* @0xde488 and r5, r5, #15 */
/* @0xde48c orr r5, r5, #32 */
/* @0xde490 b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde494 ldr r1, [pc, #0x120] */
/* @0xde498 mov r0, r9 */
/* @0xde49c add r1, pc, r1 */
/* @0xde4a0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde4a4 b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde4a8 ldr r1, [pc, #0x110] */
/* @0xde4ac mov r0, r9 */
/* @0xde4b0 add r1, pc, r1 */
/* @0xde4b4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde4b8 b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde4bc ldr r1, [pc, #0x100] */
/* @0xde4c0 mov r0, r9 */
/* @0xde4c4 add r1, pc, r1 */
/* @0xde4c8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde4cc b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde4d0 ldr r1, [pc, #0xf0] */
/* @0xde4d4 mov r0, r9 */
/* @0xde4d8 add r1, pc, r1 */
/* @0xde4dc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde4e0 b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde4e4 and r5, r5, #15 */
/* @0xde4e8 b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde4ec mov r0, r4 */
/* @0xde4f0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xde4f4 mov r0, r6 */
/* @0xde4f8 b 0xde164 <_Z5DoDivjPhPKhP6VMExec+0x3fc> */
/* @0xde4fc ldr r1, [pc, #0xc8] */
/* @0xde500 mov r0, r9 */
/* @0xde504 mov r5, r4 */
/* @0xde508 add r1, pc, r1 */
/* @0xde50c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde510 b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde514 ldr r1, [pc, #0xb4] */
/* @0xde518 mov r0, r9 */
/* @0xde51c add r1, pc, r1 */
/* @0xde520 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde524 b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde528 ldr r0, [pc, #0xa4] */
/* @0xde52c add r0, pc, r0 */
/* @0xde530 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xde534 mov r0, r6 */
/* @0xde538 b 0xde164 <_Z5DoDivjPhPKhP6VMExec+0x3fc> */
/* @0xde53c ldr r1, [pc, #0x94] */
/* @0xde540 mov r0, r9 */
/* @0xde544 add r1, pc, r1 */
/* @0xde548 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde54c mov r3, #7 */
/* @0xde550 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde554 ldr r0, [pc, #0x80] */
/* @0xde558 add r0, pc, r0 */
/* @0xde55c bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xde560 mov r0, r6 */
/* @0xde564 b 0xde164 <_Z5DoDivjPhPKhP6VMExec+0x3fc> */
/* @0xde568 ldr r0, [pc, #0x70] */
/* @0xde56c add r0, pc, r0 */
/* @0xde570 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xde574 b 0xde290 <_Z5DoDivjPhPKhP6VMExec+0x528> */
/* @0xde578 mov r0, r4 */
/* @0xde57c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xde580 b 0xde39c <_Z5DoDivjPhPKhP6VMExec+0x634> */
/* @0xde584 mov r5, r4 */
/* @0xde588 mov r7, r1 */
/* @0xde58c b 0xdddd0 <_Z5DoDivjPhPKhP6VMExec+0x68> */
/* @0xde590 mov r6, r7 */
/* @0xde594 b 0xdde10 <_Z5DoDivjPhPKhP6VMExec+0xa8> */
/* @0xde598 eoreq r5, r5, r12, asr #9 */
/* @0xde59c eoreq r5, r5, r12, lsl #9 */
/* @0xde5a0 eoreq r5, r5, r0, lsr #3 */
/* @0xde5a4 eoreq r4, r5, r12, asr #31 */
/* @0xde5a8 eoreq r5, r5, r8, lsl r0 */
/* @0xde5ac .word 0x00254ed4 */
/* @0xde5b0 mlaeq r5, r12, lr, r4 */
/* @0xde5b4 .word 0x00254efc */
/* @0xde5b8 eoreq r4, r5, r8, lsr #29 */
/* @0xde5bc eoreq r4, r5, r8, lsl #30 */
/* @0xde5c0 .word 0x00254ed4 */
/* @0xde5c4 .word 0x00254efc */
/* @0xde5c8 .word 0x00254dbc */
/* @0xde5cc eoreq r4, r5, r12, asr lr */
/* @0xde5d0 eoreq r4, r5, r0, asr #29 */
/* @0xde5d4 eoreq r4, r5, r4, asr #25 */
/* @0xde5d8 .word 0x00254eb8 */
/* @0xde5dc mlaeq r5, r8, r12, r4 */
/* @0xde5e0 eoreq r4, r5, r8, lsr #25 */

/* ── FUNC 0xde5e4 · anon_de5e4 · size=4 · insn=1 */
/* @0xde5e4 andeq r0, r0, r0 */

/* ── FUNC 0xde5e8 · DoMod(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=2436 · insn=609 */
/* @0xde5e8 ubfx r2, r0, #0x8, #0x4 */
/* @0xde5ec lsr r0, r0, #16 */
/* @0xde5f0 cmp r2, #1 */
/* @0xde5f4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xde5f8 vpush {d8} */
/* @0xde5fc mov r11, r1 */
/* @0xde600 sub sp, sp, #68 */
/* @0xde604 mov r10, r3 */
/* @0xde608 uxtb r4, r0 */
/* @0xde60c beq 0xdeb68 <_Z5DoModjPhPKhP6VMExec+0x580> */
/* @0xde610 and r3, r4, #15 */
/* @0xde614 cmp r3, #6 */
/* @0xde618 addls pc, pc, r3, lsl #2 */
/* @0xde61c b 0xdef58 <_Z5DoModjPhPKhP6VMExec+0x970> */
/* @0xde620 b 0xde958 <_Z5DoModjPhPKhP6VMExec+0x370> */
/* @0xde624 b 0xde964 <_Z5DoModjPhPKhP6VMExec+0x37c> */
/* @0xde628 b 0xde964 <_Z5DoModjPhPKhP6VMExec+0x37c> */
/* @0xde62c b 0xde958 <_Z5DoModjPhPKhP6VMExec+0x370> */
/* @0xde630 b 0xde964 <_Z5DoModjPhPKhP6VMExec+0x37c> */
/* @0xde634 b 0xde970 <_Z5DoModjPhPKhP6VMExec+0x388> */
/* @0xde638 b 0xde63c <_Z5DoModjPhPKhP6VMExec+0x54> */
/* @0xde63c ldr r1, [pc, #0x74c] */
/* @0xde640 mov r0, r10 */
/* @0xde644 mov r5, r4 */
/* @0xde648 mov r9, r11 */
/* @0xde64c add r1, pc, r1 */
/* @0xde650 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde654 asr r3, r5, #4 */
/* @0xde658 cmp r3, #6 */
/* @0xde65c addls pc, pc, r3, lsl #2 */
/* @0xde660 b 0xdef64 <_Z5DoModjPhPKhP6VMExec+0x97c> */
/* @0xde664 b 0xde950 <_Z5DoModjPhPKhP6VMExec+0x368> */
/* @0xde668 b 0xde948 <_Z5DoModjPhPKhP6VMExec+0x360> */
/* @0xde66c b 0xde948 <_Z5DoModjPhPKhP6VMExec+0x360> */
/* @0xde670 b 0xde950 <_Z5DoModjPhPKhP6VMExec+0x368> */
/* @0xde674 b 0xde948 <_Z5DoModjPhPKhP6VMExec+0x360> */
/* @0xde678 b 0xde900 <_Z5DoModjPhPKhP6VMExec+0x318> */
/* @0xde67c b 0xde680 <_Z5DoModjPhPKhP6VMExec+0x98> */
/* @0xde680 ldr r1, [pc, #0x70c] */
/* @0xde684 mov r0, r10 */
/* @0xde688 mov r6, r9 */
/* @0xde68c add r1, pc, r1 */
/* @0xde690 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde694 cmp r4, #85 */
/* @0xde698 addls pc, pc, r4, lsl #2 */
/* @0xde69c b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde6a0 b 0xde8f0 <_Z5DoModjPhPKhP6VMExec+0x308> */
/* @0xde6a4 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde6a8 b 0xde8f0 <_Z5DoModjPhPKhP6VMExec+0x308> */
/* @0xde6ac b 0xde8f0 <_Z5DoModjPhPKhP6VMExec+0x308> */
/* @0xde6b0 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde6b4 b 0xde8e0 <_Z5DoModjPhPKhP6VMExec+0x2f8> */
/* @0xde6b8 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde6bc b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde6c0 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde6c4 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde6c8 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde6cc b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde6d0 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde6d4 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde6d8 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde6dc b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde6e0 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde6e4 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde6e8 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde6ec b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde6f0 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde6f4 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde6f8 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde6fc b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde700 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde704 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde708 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde70c b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde710 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde714 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde718 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde71c b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde720 b 0xde8f0 <_Z5DoModjPhPKhP6VMExec+0x308> */
/* @0xde724 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde728 b 0xde7f8 <_Z5DoModjPhPKhP6VMExec+0x210> */
/* @0xde72c b 0xde8f0 <_Z5DoModjPhPKhP6VMExec+0x308> */
/* @0xde730 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde734 b 0xde8e0 <_Z5DoModjPhPKhP6VMExec+0x2f8> */
/* @0xde738 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde73c b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde740 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde744 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde748 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde74c b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde750 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde754 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde758 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde75c b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde760 b 0xde8f0 <_Z5DoModjPhPKhP6VMExec+0x308> */
/* @0xde764 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde768 b 0xde8f0 <_Z5DoModjPhPKhP6VMExec+0x308> */
/* @0xde76c b 0xde8f0 <_Z5DoModjPhPKhP6VMExec+0x308> */
/* @0xde770 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde774 b 0xde8e0 <_Z5DoModjPhPKhP6VMExec+0x2f8> */
/* @0xde778 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde77c b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde780 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde784 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde788 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde78c b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde790 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde794 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde798 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde79c b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde7a0 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde7a4 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde7a8 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde7ac b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde7b0 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde7b4 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde7b8 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde7bc b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde7c0 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde7c4 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde7c8 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde7cc b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde7d0 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde7d4 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde7d8 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde7dc b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde7e0 b 0xde8e0 <_Z5DoModjPhPKhP6VMExec+0x2f8> */
/* @0xde7e4 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde7e8 b 0xde8e0 <_Z5DoModjPhPKhP6VMExec+0x2f8> */
/* @0xde7ec b 0xde8e0 <_Z5DoModjPhPKhP6VMExec+0x2f8> */
/* @0xde7f0 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0xde7f4 b 0xde8e0 <_Z5DoModjPhPKhP6VMExec+0x2f8> */
/* @0xde7f8 sub r6, r6, #4 */
/* @0xde7fc mov r7, #0 */
/* @0xde800 mov r8, r6 */
/* @0xde804 cmp r5, #51 */
/* @0xde808 addls pc, pc, r5, lsl #2 */
/* @0xde80c b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde810 b 0xde9c4 <_Z5DoModjPhPKhP6VMExec+0x3dc> */
/* @0xde814 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde818 b 0xdeaa8 <_Z5DoModjPhPKhP6VMExec+0x4c0> */
/* @0xde81c b 0xdea74 <_Z5DoModjPhPKhP6VMExec+0x48c> */
/* @0xde820 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde824 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde828 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde82c b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde830 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde834 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde838 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde83c b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde840 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde844 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde848 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde84c b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde850 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde854 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde858 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde85c b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde860 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde864 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde868 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde86c b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde870 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde874 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde878 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde87c b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde880 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde884 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde888 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde88c b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde890 b 0xdea38 <_Z5DoModjPhPKhP6VMExec+0x450> */
/* @0xde894 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde898 b 0xdea20 <_Z5DoModjPhPKhP6VMExec+0x438> */
/* @0xde89c b 0xdeb08 <_Z5DoModjPhPKhP6VMExec+0x520> */
/* @0xde8a0 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde8a4 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde8a8 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde8ac b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde8b0 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde8b4 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde8b8 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde8bc b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde8c0 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde8c4 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde8c8 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde8cc b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde8d0 b 0xdead4 <_Z5DoModjPhPKhP6VMExec+0x4ec> */
/* @0xde8d4 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0xde8d8 b 0xdeb2c <_Z5DoModjPhPKhP6VMExec+0x544> */
/* @0xde8dc b 0xde9f4 <_Z5DoModjPhPKhP6VMExec+0x40c> */
/* @0xde8e0 sub r7, r6, #16 */
/* @0xde8e4 mov r8, r7 */
/* @0xde8e8 mov r6, r7 */
/* @0xde8ec b 0xde804 <_Z5DoModjPhPKhP6VMExec+0x21c> */
/* @0xde8f0 sub r6, r6, #8 */
/* @0xde8f4 mov r7, #0 */
/* @0xde8f8 mov r8, r6 */
/* @0xde8fc b 0xde804 <_Z5DoModjPhPKhP6VMExec+0x21c> */
/* @0xde900 ldr r3, [r9, #0xc] */
/* @0xde904 cmp r3, #13 */
/* @0xde908 addls pc, pc, r3, lsl #2 */
/* @0xde90c b 0xdeedc <_Z5DoModjPhPKhP6VMExec+0x8f4> */
/* @0xde910 b 0xdeebc <_Z5DoModjPhPKhP6VMExec+0x8d4> */
/* @0xde914 b 0xdeea8 <_Z5DoModjPhPKhP6VMExec+0x8c0> */
/* @0xde918 b 0xdee94 <_Z5DoModjPhPKhP6VMExec+0x8ac> */
/* @0xde91c b 0xdee80 <_Z5DoModjPhPKhP6VMExec+0x898> */
/* @0xde920 b 0xdeedc <_Z5DoModjPhPKhP6VMExec+0x8f4> */
/* @0xde924 b 0xdee6c <_Z5DoModjPhPKhP6VMExec+0x884> */
/* @0xde928 b 0xdeedc <_Z5DoModjPhPKhP6VMExec+0x8f4> */
/* @0xde92c b 0xdee60 <_Z5DoModjPhPKhP6VMExec+0x878> */
/* @0xde930 b 0xdeedc <_Z5DoModjPhPKhP6VMExec+0x8f4> */
/* @0xde934 b 0xdeedc <_Z5DoModjPhPKhP6VMExec+0x8f4> */
/* @0xde938 b 0xdee50 <_Z5DoModjPhPKhP6VMExec+0x868> */
/* @0xde93c b 0xdeedc <_Z5DoModjPhPKhP6VMExec+0x8f4> */
/* @0xde940 b 0xdeedc <_Z5DoModjPhPKhP6VMExec+0x8f4> */
/* @0xde944 b 0xdeebc <_Z5DoModjPhPKhP6VMExec+0x8d4> */
/* @0xde948 add r6, r9, #4 */
/* @0xde94c b 0xde694 <_Z5DoModjPhPKhP6VMExec+0xac> */
/* @0xde950 add r6, r9, #8 */
/* @0xde954 b 0xde694 <_Z5DoModjPhPKhP6VMExec+0xac> */
/* @0xde958 add r9, r1, #8 */
/* @0xde95c mov r5, r4 */
/* @0xde960 b 0xde654 <_Z5DoModjPhPKhP6VMExec+0x6c> */
/* @0xde964 add r9, r1, #4 */
/* @0xde968 mov r5, r4 */
/* @0xde96c b 0xde654 <_Z5DoModjPhPKhP6VMExec+0x6c> */
/* @0xde970 ldr r3, [r1, #0xc] */
/* @0xde974 cmp r3, #13 */
/* @0xde978 addls pc, pc, r3, lsl #2 */
/* @0xde97c b 0xdeec4 <_Z5DoModjPhPKhP6VMExec+0x8dc> */
/* @0xde980 b 0xdee3c <_Z5DoModjPhPKhP6VMExec+0x854> */
/* @0xde984 b 0xdee24 <_Z5DoModjPhPKhP6VMExec+0x83c> */
/* @0xde988 b 0xdee0c <_Z5DoModjPhPKhP6VMExec+0x824> */
/* @0xde98c b 0xdedf4 <_Z5DoModjPhPKhP6VMExec+0x80c> */
/* @0xde990 b 0xdeec4 <_Z5DoModjPhPKhP6VMExec+0x8dc> */
/* @0xde994 b 0xdeddc <_Z5DoModjPhPKhP6VMExec+0x7f4> */
/* @0xde998 b 0xdeec4 <_Z5DoModjPhPKhP6VMExec+0x8dc> */
/* @0xde99c b 0xded78 <_Z5DoModjPhPKhP6VMExec+0x790> */
/* @0xde9a0 b 0xdeec4 <_Z5DoModjPhPKhP6VMExec+0x8dc> */
/* @0xde9a4 b 0xdeec4 <_Z5DoModjPhPKhP6VMExec+0x8dc> */
/* @0xde9a8 b 0xdee44 <_Z5DoModjPhPKhP6VMExec+0x85c> */
/* @0xde9ac b 0xdeec4 <_Z5DoModjPhPKhP6VMExec+0x8dc> */
/* @0xde9b0 b 0xdeec4 <_Z5DoModjPhPKhP6VMExec+0x8dc> */
/* @0xde9b4 b 0xdee3c <_Z5DoModjPhPKhP6VMExec+0x854> */
/* @0xde9b8 mov r8, #0 */
/* @0xde9bc mov r7, r8 */
/* @0xde9c0 b 0xde804 <_Z5DoModjPhPKhP6VMExec+0x21c> */
/* @0xde9c4 vldr d7, [r11] */
/* @0xde9c8 vabs.f64 d5, d7 */
/* @0xde9cc vldr d6, [pc, #948] */
/* @0xde9d0 vcmpe.f64 d5, d6 */
/* @0xde9d4 vmrs APSR_nzcv, fpscr */
/* @0xde9d8 bpl 0xdec38 <_Z5DoModjPhPKhP6VMExec+0x650> */
/* @0xde9dc ldr r1, [pc, #0x3b4] */
/* @0xde9e0 mov r0, r10 */
/* @0xde9e4 add r1, pc, r1 */
/* @0xde9e8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde9ec mov r12, #0 */
/* @0xde9f0 b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* @0xde9f4 ldrd r0, r1, [r9] */
/* @0xde9f8 ldrd r2, r3, [r11] */
/* @0xde9fc bl 0x319414 <__aeabi_ldivmod> */
/* @0xdea00 mov r12, #10 */
/* @0xdea04 strd r2, r3, [r8] */
/* @0xdea08 cmp r7, #0 */
/* @0xdea0c strne r12, [r7, #0xc] */
/* @0xdea10 mov r0, r6 */
/* @0xdea14 add sp, sp, #68 */
/* @0xdea18 vpop {d8} */
/* @0xdea1c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xdea20 ldr r0, [r9] */
/* @0xdea24 ldr r1, [r11] */
/* @0xdea28 bl 0x318dec <__aeabi_idivmod> */
/* @0xdea2c mov r12, #7 */
/* @0xdea30 str r1, [r8] */
/* @0xdea34 b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* @0xdea38 vldr d7, [r11] */
/* @0xdea3c vabs.f64 d5, d7 */
/* @0xdea40 vldr d6, [pc, #832] */
/* @0xdea44 vcmpe.f64 d5, d6 */
/* @0xdea48 vmrs APSR_nzcv, fpscr */
/* @0xdea4c bmi 0xde9dc <_Z5DoModjPhPKhP6VMExec+0x3f4> */
/* @0xdea50 ldr r0, [r9] */
/* @0xdea54 vmov r2, r3, d7 */
/* @0xdea58 vmov s15, r0 */
/* @0xdea5c vcvt.f64.s32 d7, s15 */
/* @0xdea60 vmov r0, r1, d7 */
/* @0xdea64 bl 0xb66ac <fmod@plt> */
/* @0xdea68 mov r12, #0 */
/* @0xdea6c strd r0, r1, [r8] */
/* @0xdea70 b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* @0xdea74 ldrd r0, r1, [r11] */
/* @0xdea78 orrs r3, r0, r1 */
/* @0xdea7c beq 0xde9dc <_Z5DoModjPhPKhP6VMExec+0x3f4> */
/* @0xdea80 bl 0x319164 <__floatdidf> */
/* @0xdea84 ldrd r4, r5, [r9] */
/* @0xdea88 mov r2, r0 */
/* @0xdea8c mov r3, r1 */
/* @0xdea90 mov r0, r4 */
/* @0xdea94 mov r1, r5 */
/* @0xdea98 bl 0xb66ac <fmod@plt> */
/* @0xdea9c mov r12, #0 */
/* @0xdeaa0 strd r0, r1, [r8] */
/* @0xdeaa4 b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* @0xdeaa8 ldr r2, [r11] */
/* @0xdeaac cmp r2, #0 */
/* @0xdeab0 beq 0xde9dc <_Z5DoModjPhPKhP6VMExec+0x3f4> */
/* @0xdeab4 vmov s15, r2 */
/* @0xdeab8 ldrd r0, r1, [r9] */
/* @0xdeabc vcvt.f64.s32 d7, s15 */
/* @0xdeac0 vmov r2, r3, d7 */
/* @0xdeac4 bl 0xb66ac <fmod@plt> */
/* @0xdeac8 mov r12, #0 */
/* @0xdeacc strd r0, r1, [r8] */
/* @0xdead0 b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* @0xdead4 vldr d8, [r11] */
/* @0xdead8 vabs.f64 d6, d8 */
/* @0xdeadc vldr d7, [pc, #676] */
/* @0xdeae0 vcmpe.f64 d6, d7 */
/* @0xdeae4 vmrs APSR_nzcv, fpscr */
/* @0xdeae8 bmi 0xde9dc <_Z5DoModjPhPKhP6VMExec+0x3f4> */
/* @0xdeaec ldrd r0, r1, [r9] */
/* @0xdeaf0 bl 0x319164 <__floatdidf> */
/* @0xdeaf4 vmov r2, r3, d8 */
/* @0xdeaf8 bl 0xb66ac <fmod@plt> */
/* @0xdeafc mov r12, #0 */
/* @0xdeb00 strd r0, r1, [r8] */
/* @0xdeb04 b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* @0xdeb08 ldrd r2, r3, [r11] */
/* @0xdeb0c orrs r1, r2, r3 */
/* @0xdeb10 beq 0xdec20 <_Z5DoModjPhPKhP6VMExec+0x638> */
/* @0xdeb14 ldr r0, [r9] */
/* @0xdeb18 asr r1, r0, #31 */
/* @0xdeb1c bl 0x319414 <__aeabi_ldivmod> */
/* @0xdeb20 mov r12, #10 */
/* @0xdeb24 strd r2, r3, [r8] */
/* @0xdeb28 b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* @0xdeb2c ldr r2, [r11] */
/* @0xdeb30 cmp r2, #0 */
/* @0xdeb34 beq 0xdec20 <_Z5DoModjPhPKhP6VMExec+0x638> */
/* @0xdeb38 ldrd r0, r1, [r9] */
/* @0xdeb3c asr r3, r2, #31 */
/* @0xdeb40 bl 0x319414 <__aeabi_ldivmod> */
/* @0xdeb44 mov r12, #10 */
/* @0xdeb48 strd r2, r3, [r8] */
/* @0xdeb4c b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* @0xdeb50 ldr r1, [pc, #0x244] */
/* @0xdeb54 mov r0, r10 */
/* @0xdeb58 add r1, pc, r1 */
/* @0xdeb5c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdeb60 mov r12, #0 */
/* @0xdeb64 b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* @0xdeb68 add r7, sp, #16 */
/* @0xdeb6c mov r2, r1 */
/* @0xdeb70 and r1, r4, #15 */
/* @0xdeb74 mov r0, r7 */
/* @0xdeb78 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xdeb7c lsr r1, r4, #4 */
/* @0xdeb80 mov r2, r0 */
/* @0xdeb84 mov r0, sp */
/* @0xdeb88 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xdeb8c ldr r3, [sp, #0xc] */
/* @0xdeb90 mvn r12, #-16777216 */
/* @0xdeb94 and r3, r3, r12 */
/* @0xdeb98 cmp r3, r12 */
/* @0xdeb9c mov r6, r0 */
/* @0xdeba0 beq 0xdef04 <_Z5DoModjPhPKhP6VMExec+0x91c> */
/* @0xdeba4 ldr r3, [sp, #0x1c] */
/* @0xdeba8 bic r3, r3, #-16777216 */
/* @0xdebac cmp r3, r12 */
/* @0xdebb0 beq 0xdeef0 <_Z5DoModjPhPKhP6VMExec+0x908> */
/* @0xdebb4 add r4, sp, #32 */
/* @0xdebb8 mov r1, sp */
/* @0xdebbc mov r2, #0 */
/* @0xdebc0 mov r3, #0 */
/* @0xdebc4 mov r0, r4 */
/* @0xdebc8 str r12, [sp, #0x2c] */
/* @0xdebcc str r12, [sp, #0x3c] */
/* @0xdebd0 mov r12, #0 */
/* @0xdebd4 strd r2, r3, [sp, #32] */
/* @0xdebd8 strd r2, r3, [sp, #48] */
/* @0xdebdc str r12, [sp, #0x28] */
/* @0xdebe0 str r12, [sp, #0x38] */
/* @0xdebe4 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xdebe8 cmp r0, #1 */
/* @0xdebec beq 0xdef18 <_Z5DoModjPhPKhP6VMExec+0x930> */
/* @0xdebf0 cmp r0, #0 */
/* @0xdebf4 beq 0xdec50 <_Z5DoModjPhPKhP6VMExec+0x668> */
/* @0xdebf8 ldr r3, [sp, #0x2c] */
/* @0xdebfc sub r3, r3, #1 */
/* @0xdec00 bic r3, r3, #-16777216 */
/* @0xdec04 bic r3, r3, #3 */
/* @0xdec08 cmp r3, #0 */
/* @0xdec0c bne 0xdea10 <_Z5DoModjPhPKhP6VMExec+0x428> */
/* @0xdec10 mov r0, r4 */
/* @0xdec14 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdec18 mov r0, r6 */
/* @0xdec1c b 0xdea14 <_Z5DoModjPhPKhP6VMExec+0x42c> */
/* @0xdec20 ldr r1, [pc, #0x178] */
/* @0xdec24 mov r0, r10 */
/* @0xdec28 add r1, pc, r1 */
/* @0xdec2c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdec30 mov r12, #10 */
/* @0xdec34 b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* @0xdec38 ldrd r0, r1, [r9] */
/* @0xdec3c vmov r2, r3, d7 */
/* @0xdec40 bl 0xb66ac <fmod@plt> */
/* @0xdec44 mov r12, #0 */
/* @0xdec48 strd r0, r1, [r8] */
/* @0xdec4c b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* @0xdec50 add r5, sp, #48 */
/* @0xdec54 mov r1, r7 */
/* @0xdec58 mov r0, r5 */
/* @0xdec5c bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xdec60 cmp r0, #1 */
/* @0xdec64 beq 0xdef28 <_Z5DoModjPhPKhP6VMExec+0x940> */
/* @0xdec68 cmp r0, #0 */
/* @0xdec6c bne 0xdebf8 <_Z5DoModjPhPKhP6VMExec+0x610> */
/* @0xdec70 str r0, [r6, #-0x4] */
/* @0xdec74 sub r7, r6, #16 */
/* @0xdec78 ldrd r0, r1, [sp, #32] */
/* @0xdec7c ldrd r2, r3, [sp, #48] */
/* @0xdec80 bl 0xb66ac <fmod@plt> */
/* @0xdec84 str r0, [r6, #-0x10] */
/* @0xdec88 str r1, [r6, #-0xc] */
/* @0xdec8c vldr d7, [sp, #48] */
/* @0xdec90 vcmp.f64 d7, d7 */
/* @0xdec94 vmrs APSR_nzcv, fpscr */
/* @0xdec98 bvs 0xdef38 <_Z5DoModjPhPKhP6VMExec+0x950> */
/* @0xdec9c vldr d7, [sp, #32] */
/* @0xdeca0 vcmp.f64 d7, d7 */
/* @0xdeca4 vmrs APSR_nzcv, fpscr */
/* @0xdeca8 bvs 0xdef38 <_Z5DoModjPhPKhP6VMExec+0x950> */
/* @0xdecac mov r0, r4 */
/* @0xdecb0 bl 0x240970 <_Z7yyisinfR6RValue> */
/* @0xdecb4 cmp r0, #0 */
/* @0xdecb8 bne 0xdef38 <_Z5DoModjPhPKhP6VMExec+0x950> */
/* @0xdecbc ldrd r2, r3, [sp, #48] */
/* @0xdecc0 mvn r8, #0 */
/* @0xdecc4 mvn r9, #-2147483648 */
/* @0xdecc8 and r2, r2, r8 */
/* @0xdeccc and r3, r3, r9 */
/* @0xdecd0 orrs r1, r2, r3 */
/* @0xdecd4 beq 0xdef38 <_Z5DoModjPhPKhP6VMExec+0x950> */
/* @0xdecd8 mov r0, r5 */
/* @0xdecdc bl 0x240970 <_Z7yyisinfR6RValue> */
/* @0xdece0 cmp r0, #0 */
/* @0xdece4 bne 0xded10 <_Z5DoModjPhPKhP6VMExec+0x728> */
/* @0xdece8 ldrd r2, r3, [sp, #32] */
/* @0xdecec and r2, r2, r8 */
/* @0xdecf0 and r3, r3, r9 */
/* @0xdecf4 orrs r1, r2, r3 */
/* @0xdecf8 bne 0xded20 <_Z5DoModjPhPKhP6VMExec+0x738> */
/* @0xdecfc ldrd r2, r3, [sp, #48] */
/* @0xded00 and r2, r2, r8 */
/* @0xded04 and r3, r3, r9 */
/* @0xded08 orrs r1, r2, r3 */
/* @0xded0c beq 0xded20 <_Z5DoModjPhPKhP6VMExec+0x738> */
/* @0xded10 ldr r2, [sp, #0x20] */
/* @0xded14 ldr r3, [sp, #0x24] */
/* @0xded18 str r2, [r6, #-0x10] */
/* @0xded1c str r3, [r6, #-0xc] */
/* @0xded20 ldr r3, [sp, #0x2c] */
/* @0xded24 sub r3, r3, #1 */
/* @0xded28 bic r3, r3, #-16777216 */
/* @0xded2c bic r3, r3, #3 */
/* @0xded30 cmp r3, #0 */
/* @0xded34 beq 0xdef4c <_Z5DoModjPhPKhP6VMExec+0x964> */
/* @0xded38 ldr r1, [sp, #0x3c] */
/* @0xded3c mov r3, #0 */
/* @0xded40 str r3, [sp, #0x28] */
/* @0xded44 mov r2, #5 */
/* @0xded48 sub r1, r1, #1 */
/* @0xded4c str r3, [sp, #0x20] */
/* @0xded50 bic r3, r1, #-16777216 */
/* @0xded54 str r2, [sp, #0x2c] */
/* @0xded58 bic r3, r3, #3 */
/* @0xded5c cmp r3, #0 */
/* @0xded60 movne r0, r7 */
/* @0xded64 bne 0xdea14 <_Z5DoModjPhPKhP6VMExec+0x42c> */
/* @0xded68 mov r0, r5 */
/* @0xded6c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xded70 mov r0, r7 */
/* @0xded74 b 0xdea14 <_Z5DoModjPhPKhP6VMExec+0x42c> */
/* @0xded78 and r0, r0, #240 */
/* @0xded7c orr r5, r0, #2 */
/* @0xded80 add r9, r11, #16 */
/* @0xded84 b 0xde654 <_Z5DoModjPhPKhP6VMExec+0x6c> */
/* @0xded88 ldmible r7, {r0, r1, r3, r4, r5, r7, r8, r10, r11, r12, sp, pc} ^ */
/* @0xded8c ldcllo p12, c7, [r11, #892] */
/* @0xded90 eoreq r4, r5, r8, lsl #29 */
/* @0xded94 eoreq r4, r5, r8, asr #28 */
/* @0xded98 eoreq r4, r5, r8, asr r12 */
/* @0xded9c .word 0x00254afc */
/* @0xdeda0 eoreq r4, r5, r4, lsl r10 */
/* @0xdeda4 eoreq r4, r5, r8, asr #14 */
/* @0xdeda8 eoreq r4, r5, r0, lsl r7 */
/* @0xdedac eoreq r4, r5, r0, ror r7 */
/* @0xdedb0 eoreq r4, r5, r12, lsl r7 */
/* @0xdedb4 eoreq r4, r5, r0, ror r7 */
/* @0xdedb8 eoreq r4, r5, r12, lsr r7 */
/* @0xdedbc eoreq r4, r5, r4, ror #14 */
/* @0xdedc0 eoreq r4, r5, r4, lsr #12 */
/* @0xdedc4 .word 0x002546d4 */
/* @0xdedc8 eoreq r4, r5, r8, lsr r7 */
/* @0xdedcc eoreq r4, r5, r12, lsr r5 */
/* @0xdedd0 eoreq r4, r5, r8, lsr #10 */
/* @0xdedd4 eoreq r4, r5, r8, lsr r5 */
/* @0xdedd8 eoreq r4, r5, r8, ror #10 */
/* @0xdeddc ldr r1, [pc, #-0x40] */
/* @0xdede0 mov r0, r10 */
/* @0xdede4 mov r5, r4 */
/* @0xdede8 add r1, pc, r1 */
/* @0xdedec bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdedf0 b 0xded80 <_Z5DoModjPhPKhP6VMExec+0x798> */
/* @0xdedf4 ldr r1, [pc, #-0x54] */
/* @0xdedf8 mov r0, r10 */
/* @0xdedfc mov r5, r4 */
/* @0xdee00 add r1, pc, r1 */
/* @0xdee04 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdee08 b 0xded80 <_Z5DoModjPhPKhP6VMExec+0x798> */
/* @0xdee0c ldr r1, [pc, #-0x68] */
/* @0xdee10 mov r0, r10 */
/* @0xdee14 mov r5, r4 */
/* @0xdee18 add r1, pc, r1 */
/* @0xdee1c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdee20 b 0xded80 <_Z5DoModjPhPKhP6VMExec+0x798> */
/* @0xdee24 ldr r1, [pc, #-0x7c] */
/* @0xdee28 mov r0, r10 */
/* @0xdee2c mov r5, r4 */
/* @0xdee30 add r1, pc, r1 */
/* @0xdee34 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdee38 b 0xded80 <_Z5DoModjPhPKhP6VMExec+0x798> */
/* @0xdee3c and r5, r4, #240 */
/* @0xdee40 b 0xded80 <_Z5DoModjPhPKhP6VMExec+0x798> */
/* @0xdee44 and r0, r0, #240 */
/* @0xdee48 orr r5, r0, #3 */
/* @0xdee4c b 0xded80 <_Z5DoModjPhPKhP6VMExec+0x798> */
/* @0xdee50 and r5, r5, #15 */
/* @0xdee54 orr r5, r5, #48 */
/* @0xdee58 add r6, r9, #16 */
/* @0xdee5c b 0xde694 <_Z5DoModjPhPKhP6VMExec+0xac> */
/* @0xdee60 and r5, r5, #15 */
/* @0xdee64 orr r5, r5, #32 */
/* @0xdee68 b 0xdee58 <_Z5DoModjPhPKhP6VMExec+0x870> */
/* @0xdee6c ldr r1, [pc, #-0xc0] */
/* @0xdee70 mov r0, r10 */
/* @0xdee74 add r1, pc, r1 */
/* @0xdee78 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdee7c b 0xdee58 <_Z5DoModjPhPKhP6VMExec+0x870> */
/* @0xdee80 ldr r1, [pc, #-0xd0] */
/* @0xdee84 mov r0, r10 */
/* @0xdee88 add r1, pc, r1 */
/* @0xdee8c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdee90 b 0xdee58 <_Z5DoModjPhPKhP6VMExec+0x870> */
/* @0xdee94 ldr r1, [pc, #-0xe0] */
/* @0xdee98 mov r0, r10 */
/* @0xdee9c add r1, pc, r1 */
/* @0xdeea0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdeea4 b 0xdee58 <_Z5DoModjPhPKhP6VMExec+0x870> */
/* @0xdeea8 ldr r1, [pc, #-0xf0] */
/* @0xdeeac mov r0, r10 */
/* @0xdeeb0 add r1, pc, r1 */
/* @0xdeeb4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdeeb8 b 0xdee58 <_Z5DoModjPhPKhP6VMExec+0x870> */
/* @0xdeebc and r5, r5, #15 */
/* @0xdeec0 b 0xdee58 <_Z5DoModjPhPKhP6VMExec+0x870> */
/* @0xdeec4 ldr r1, [pc, #-0x108] */
/* @0xdeec8 mov r0, r10 */
/* @0xdeecc mov r5, r4 */
/* @0xdeed0 add r1, pc, r1 */
/* @0xdeed4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdeed8 b 0xded80 <_Z5DoModjPhPKhP6VMExec+0x798> */
/* @0xdeedc ldr r1, [pc, #-0x11c] */
/* @0xdeee0 mov r0, r10 */
/* @0xdeee4 add r1, pc, r1 */
/* @0xdeee8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdeeec b 0xdee58 <_Z5DoModjPhPKhP6VMExec+0x870> */
/* @0xdeef0 ldr r0, [pc, #-0x12c] */
/* @0xdeef4 add r0, pc, r0 */
/* @0xdeef8 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xdeefc mov r0, r6 */
/* @0xdef00 b 0xdea14 <_Z5DoModjPhPKhP6VMExec+0x42c> */
/* @0xdef04 ldr r0, [pc, #-0x13c] */
/* @0xdef08 add r0, pc, r0 */
/* @0xdef0c bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xdef10 mov r0, r6 */
/* @0xdef14 b 0xdea14 <_Z5DoModjPhPKhP6VMExec+0x42c> */
/* @0xdef18 ldr r0, [pc, #-0x14c] */
/* @0xdef1c add r0, pc, r0 */
/* @0xdef20 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xdef24 b 0xdebf8 <_Z5DoModjPhPKhP6VMExec+0x610> */
/* @0xdef28 ldr r0, [pc, #-0x158] */
/* @0xdef2c add r0, pc, r0 */
/* @0xdef30 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xdef34 b 0xdebf8 <_Z5DoModjPhPKhP6VMExec+0x610> */
/* @0xdef38 mvn r2, #0 */
/* @0xdef3c mvn r3, #-2147483648 */
/* @0xdef40 str r2, [r6, #-0x10] */
/* @0xdef44 str r3, [r6, #-0xc] */
/* @0xdef48 b 0xded20 <_Z5DoModjPhPKhP6VMExec+0x738> */
/* @0xdef4c mov r0, r4 */
/* @0xdef50 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdef54 b 0xded38 <_Z5DoModjPhPKhP6VMExec+0x750> */
/* @0xdef58 mov r5, r4 */
/* @0xdef5c mov r9, r1 */
/* @0xdef60 b 0xde654 <_Z5DoModjPhPKhP6VMExec+0x6c> */
/* @0xdef64 mov r6, r9 */
/* @0xdef68 b 0xde694 <_Z5DoModjPhPKhP6VMExec+0xac> */

/* ── FUNC 0xdef6c · anon_def6c · size=4 · insn=1 */
/* @0xdef6c nop */

/* ── FUNC 0xdef70 · DoAnd(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=2196 · insn=549 */
/* @0xdef70 tst r0, #3840 */
/* @0xdef74 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xdef78 lsr r5, r0, #16 */
/* @0xdef7c sub sp, sp, #68 */
/* @0xdef80 mov r9, r1 */
/* @0xdef84 mov r11, r3 */
/* @0xdef88 bne 0xdefbc <_Z5DoAndjPhPKhP6VMExec+0x4c> */
/* @0xdef8c uxtb r4, r5 */
/* @0xdef90 and r2, r4, #15 */
/* @0xdef94 cmp r2, #6 */
/* @0xdef98 addls pc, pc, r2, lsl #2 */
/* @0xdef9c b 0xdf7ac <_Z5DoAndjPhPKhP6VMExec+0x83c> */
/* @0xdefa0 b 0xdf05c <_Z5DoAndjPhPKhP6VMExec+0xec> */
/* @0xdefa4 b 0xdf3ac <_Z5DoAndjPhPKhP6VMExec+0x43c> */
/* @0xdefa8 b 0xdf3ac <_Z5DoAndjPhPKhP6VMExec+0x43c> */
/* @0xdefac b 0xdf05c <_Z5DoAndjPhPKhP6VMExec+0xec> */
/* @0xdefb0 b 0xdf3ac <_Z5DoAndjPhPKhP6VMExec+0x43c> */
/* @0xdefb4 b 0xdf3b8 <_Z5DoAndjPhPKhP6VMExec+0x448> */
/* @0xdefb8 b 0xdf400 <_Z5DoAndjPhPKhP6VMExec+0x490> */
/* @0xdefbc add r4, sp, #16 */
/* @0xdefc0 uxtb r5, r5 */
/* @0xdefc4 mov r2, r1 */
/* @0xdefc8 and r1, r5, #15 */
/* @0xdefcc mov r0, r4 */
/* @0xdefd0 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xdefd4 lsr r1, r5, #4 */
/* @0xdefd8 mov r2, r0 */
/* @0xdefdc mov r0, sp */
/* @0xdefe0 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xdefe4 ldr r3, [sp, #0xc] */
/* @0xdefe8 mvn r12, #-16777216 */
/* @0xdefec and r3, r3, r12 */
/* @0xdeff0 cmp r3, r12 */
/* @0xdeff4 mov r6, r0 */
/* @0xdeff8 beq 0xdf764 <_Z5DoAndjPhPKhP6VMExec+0x7f4> */
/* @0xdeffc ldr r3, [sp, #0x1c] */
/* @0xdf000 bic r3, r3, #-16777216 */
/* @0xdf004 cmp r3, r12 */
/* @0xdf008 beq 0xdf488 <_Z5DoAndjPhPKhP6VMExec+0x518> */
/* @0xdf00c add r5, sp, #32 */
/* @0xdf010 mov r1, sp */
/* @0xdf014 mov r2, #0 */
/* @0xdf018 mov r3, #0 */
/* @0xdf01c mov r0, r5 */
/* @0xdf020 str r12, [sp, #0x2c] */
/* @0xdf024 str r12, [sp, #0x3c] */
/* @0xdf028 mov r12, #0 */
/* @0xdf02c strd r2, r3, [sp, #32] */
/* @0xdf030 strd r2, r3, [sp, #48] */
/* @0xdf034 str r12, [sp, #0x28] */
/* @0xdf038 str r12, [sp, #0x38] */
/* @0xdf03c bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0xdf040 cmp r0, #1 */
/* @0xdf044 beq 0xdf778 <_Z5DoAndjPhPKhP6VMExec+0x808> */
/* @0xdf048 cmp r0, #0 */
/* @0xdf04c beq 0xdf590 <_Z5DoAndjPhPKhP6VMExec+0x620> */
/* @0xdf050 mov r0, r6 */
/* @0xdf054 add sp, sp, #68 */
/* @0xdf058 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xdf05c add r10, r1, #8 */
/* @0xdf060 mov r5, r4 */
/* @0xdf064 asr r2, r5, #4 */
/* @0xdf068 cmp r2, #6 */
/* @0xdf06c addls pc, pc, r2, lsl #2 */
/* @0xdf070 b 0xdf7b8 <_Z5DoAndjPhPKhP6VMExec+0x848> */
/* @0xdf074 b 0xdf3a4 <_Z5DoAndjPhPKhP6VMExec+0x434> */
/* @0xdf078 b 0xdf39c <_Z5DoAndjPhPKhP6VMExec+0x42c> */
/* @0xdf07c b 0xdf39c <_Z5DoAndjPhPKhP6VMExec+0x42c> */
/* @0xdf080 b 0xdf3a4 <_Z5DoAndjPhPKhP6VMExec+0x434> */
/* @0xdf084 b 0xdf39c <_Z5DoAndjPhPKhP6VMExec+0x42c> */
/* @0xdf088 b 0xdf354 <_Z5DoAndjPhPKhP6VMExec+0x3e4> */
/* @0xdf08c b 0xdf090 <_Z5DoAndjPhPKhP6VMExec+0x120> */
/* @0xdf090 ldr r1, [pc, #0x728] */
/* @0xdf094 mov r0, r11 */
/* @0xdf098 mov r6, r10 */
/* @0xdf09c add r1, pc, r1 */
/* @0xdf0a0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf0a4 cmp r4, #85 */
/* @0xdf0a8 addls pc, pc, r4, lsl #2 */
/* @0xdf0ac b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0b0 b 0xdf344 <_Z5DoAndjPhPKhP6VMExec+0x3d4> */
/* @0xdf0b4 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0b8 b 0xdf344 <_Z5DoAndjPhPKhP6VMExec+0x3d4> */
/* @0xdf0bc b 0xdf344 <_Z5DoAndjPhPKhP6VMExec+0x3d4> */
/* @0xdf0c0 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0c4 b 0xdf334 <_Z5DoAndjPhPKhP6VMExec+0x3c4> */
/* @0xdf0c8 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0cc b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0d0 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0d4 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0d8 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0dc b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0e0 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0e4 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0e8 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0ec b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0f0 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0f4 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0f8 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0fc b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf100 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf104 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf108 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf10c b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf110 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf114 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf118 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf11c b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf120 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf124 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf128 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf12c b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf130 b 0xdf344 <_Z5DoAndjPhPKhP6VMExec+0x3d4> */
/* @0xdf134 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf138 b 0xdf208 <_Z5DoAndjPhPKhP6VMExec+0x298> */
/* @0xdf13c b 0xdf344 <_Z5DoAndjPhPKhP6VMExec+0x3d4> */
/* @0xdf140 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf144 b 0xdf334 <_Z5DoAndjPhPKhP6VMExec+0x3c4> */
/* @0xdf148 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf14c b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf150 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf154 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf158 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf15c b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf160 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf164 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf168 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf16c b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf170 b 0xdf344 <_Z5DoAndjPhPKhP6VMExec+0x3d4> */
/* @0xdf174 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf178 b 0xdf344 <_Z5DoAndjPhPKhP6VMExec+0x3d4> */
/* @0xdf17c b 0xdf344 <_Z5DoAndjPhPKhP6VMExec+0x3d4> */
/* @0xdf180 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf184 b 0xdf334 <_Z5DoAndjPhPKhP6VMExec+0x3c4> */
/* @0xdf188 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf18c b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf190 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf194 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf198 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf19c b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1a0 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1a4 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1a8 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1ac b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1b0 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1b4 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1b8 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1bc b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1c0 b 0xdf208 <_Z5DoAndjPhPKhP6VMExec+0x298> */
/* @0xdf1c4 b 0xdf334 <_Z5DoAndjPhPKhP6VMExec+0x3c4> */
/* @0xdf1c8 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1cc b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1d0 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1d4 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1d8 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1dc b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1e0 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1e4 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1e8 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1ec b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1f0 b 0xdf334 <_Z5DoAndjPhPKhP6VMExec+0x3c4> */
/* @0xdf1f4 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1f8 b 0xdf334 <_Z5DoAndjPhPKhP6VMExec+0x3c4> */
/* @0xdf1fc b 0xdf334 <_Z5DoAndjPhPKhP6VMExec+0x3c4> */
/* @0xdf200 b 0xdf334 <_Z5DoAndjPhPKhP6VMExec+0x3c4> */
/* @0xdf204 b 0xdf334 <_Z5DoAndjPhPKhP6VMExec+0x3c4> */
/* @0xdf208 sub r6, r6, #4 */
/* @0xdf20c mov r7, #0 */
/* @0xdf210 mov r8, r6 */
/* @0xdf214 cmp r5, #68 */
/* @0xdf218 addls pc, pc, r5, lsl #2 */
/* @0xdf21c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf220 b 0xdf560 <_Z5DoAndjPhPKhP6VMExec+0x5f0> */
/* @0xdf224 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf228 b 0xdf458 <_Z5DoAndjPhPKhP6VMExec+0x4e8> */
/* @0xdf22c b 0xdf550 <_Z5DoAndjPhPKhP6VMExec+0x5e0> */
/* @0xdf230 b 0xdf458 <_Z5DoAndjPhPKhP6VMExec+0x4e8> */
/* @0xdf234 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf238 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf23c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf240 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf244 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf248 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf24c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf250 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf254 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf258 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf25c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf260 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf264 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf268 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf26c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf270 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf274 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf278 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf27c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf280 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf284 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf288 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf28c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf290 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf294 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf298 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf29c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2a0 b 0xdf41c <_Z5DoAndjPhPKhP6VMExec+0x4ac> */
/* @0xdf2a4 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2a8 b 0xdf4d4 <_Z5DoAndjPhPKhP6VMExec+0x564> */
/* @0xdf2ac b 0xdf4b8 <_Z5DoAndjPhPKhP6VMExec+0x548> */
/* @0xdf2b0 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2b4 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2b8 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2bc b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2c0 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2c4 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2c8 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2cc b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2d0 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2d4 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2d8 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2dc b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2e0 b 0xdf508 <_Z5DoAndjPhPKhP6VMExec+0x598> */
/* @0xdf2e4 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2e8 b 0xdf4ec <_Z5DoAndjPhPKhP6VMExec+0x57c> */
/* @0xdf2ec b 0xdf49c <_Z5DoAndjPhPKhP6VMExec+0x52c> */
/* @0xdf2f0 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2f4 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2f8 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2fc b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf300 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf304 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf308 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf30c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf310 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf314 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf318 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf31c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf320 b 0xdf41c <_Z5DoAndjPhPKhP6VMExec+0x4ac> */
/* @0xdf324 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf328 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf32c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf330 b 0xdf52c <_Z5DoAndjPhPKhP6VMExec+0x5bc> */
/* @0xdf334 sub r7, r6, #16 */
/* @0xdf338 mov r8, r7 */
/* @0xdf33c mov r6, r7 */
/* @0xdf340 b 0xdf214 <_Z5DoAndjPhPKhP6VMExec+0x2a4> */
/* @0xdf344 sub r6, r6, #8 */
/* @0xdf348 mov r7, #0 */
/* @0xdf34c mov r8, r6 */
/* @0xdf350 b 0xdf214 <_Z5DoAndjPhPKhP6VMExec+0x2a4> */
/* @0xdf354 ldr r3, [r10, #0xc] */
/* @0xdf358 cmp r3, #13 */
/* @0xdf35c addls pc, pc, r3, lsl #2 */
/* @0xdf360 b 0xdf738 <_Z5DoAndjPhPKhP6VMExec+0x7c8> */
/* @0xdf364 b 0xdf6ac <_Z5DoAndjPhPKhP6VMExec+0x73c> */
/* @0xdf368 b 0xdf698 <_Z5DoAndjPhPKhP6VMExec+0x728> */
/* @0xdf36c b 0xdf684 <_Z5DoAndjPhPKhP6VMExec+0x714> */
/* @0xdf370 b 0xdf670 <_Z5DoAndjPhPKhP6VMExec+0x700> */
/* @0xdf374 b 0xdf738 <_Z5DoAndjPhPKhP6VMExec+0x7c8> */
/* @0xdf378 b 0xdf65c <_Z5DoAndjPhPKhP6VMExec+0x6ec> */
/* @0xdf37c b 0xdf738 <_Z5DoAndjPhPKhP6VMExec+0x7c8> */
/* @0xdf380 b 0xdf650 <_Z5DoAndjPhPKhP6VMExec+0x6e0> */
/* @0xdf384 b 0xdf738 <_Z5DoAndjPhPKhP6VMExec+0x7c8> */
/* @0xdf388 b 0xdf738 <_Z5DoAndjPhPKhP6VMExec+0x7c8> */
/* @0xdf38c b 0xdf640 <_Z5DoAndjPhPKhP6VMExec+0x6d0> */
/* @0xdf390 b 0xdf738 <_Z5DoAndjPhPKhP6VMExec+0x7c8> */
/* @0xdf394 b 0xdf738 <_Z5DoAndjPhPKhP6VMExec+0x7c8> */
/* @0xdf398 b 0xdf6ac <_Z5DoAndjPhPKhP6VMExec+0x73c> */
/* @0xdf39c add r6, r10, #4 */
/* @0xdf3a0 b 0xdf0a4 <_Z5DoAndjPhPKhP6VMExec+0x134> */
/* @0xdf3a4 add r6, r10, #8 */
/* @0xdf3a8 b 0xdf0a4 <_Z5DoAndjPhPKhP6VMExec+0x134> */
/* @0xdf3ac add r10, r1, #4 */
/* @0xdf3b0 mov r5, r4 */
/* @0xdf3b4 b 0xdf064 <_Z5DoAndjPhPKhP6VMExec+0xf4> */
/* @0xdf3b8 ldr r3, [r1, #0xc] */
/* @0xdf3bc cmp r3, #13 */
/* @0xdf3c0 addls pc, pc, r3, lsl #2 */
/* @0xdf3c4 b 0xdf74c <_Z5DoAndjPhPKhP6VMExec+0x7dc> */
/* @0xdf3c8 b 0xdf730 <_Z5DoAndjPhPKhP6VMExec+0x7c0> */
/* @0xdf3cc b 0xdf718 <_Z5DoAndjPhPKhP6VMExec+0x7a8> */
/* @0xdf3d0 b 0xdf700 <_Z5DoAndjPhPKhP6VMExec+0x790> */
/* @0xdf3d4 b 0xdf6e8 <_Z5DoAndjPhPKhP6VMExec+0x778> */
/* @0xdf3d8 b 0xdf74c <_Z5DoAndjPhPKhP6VMExec+0x7dc> */
/* @0xdf3dc b 0xdf6d0 <_Z5DoAndjPhPKhP6VMExec+0x760> */
/* @0xdf3e0 b 0xdf74c <_Z5DoAndjPhPKhP6VMExec+0x7dc> */
/* @0xdf3e4 b 0xdf6c4 <_Z5DoAndjPhPKhP6VMExec+0x754> */
/* @0xdf3e8 b 0xdf74c <_Z5DoAndjPhPKhP6VMExec+0x7dc> */
/* @0xdf3ec b 0xdf74c <_Z5DoAndjPhPKhP6VMExec+0x7dc> */
/* @0xdf3f0 b 0xdf6b4 <_Z5DoAndjPhPKhP6VMExec+0x744> */
/* @0xdf3f4 b 0xdf74c <_Z5DoAndjPhPKhP6VMExec+0x7dc> */
/* @0xdf3f8 b 0xdf74c <_Z5DoAndjPhPKhP6VMExec+0x7dc> */
/* @0xdf3fc b 0xdf730 <_Z5DoAndjPhPKhP6VMExec+0x7c0> */
/* @0xdf400 ldr r1, [pc, #0x3bc] */
/* @0xdf404 mov r0, r3 */
/* @0xdf408 mov r5, r4 */
/* @0xdf40c mov r10, r9 */
/* @0xdf410 add r1, pc, r1 */
/* @0xdf414 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf418 b 0xdf064 <_Z5DoAndjPhPKhP6VMExec+0xf4> */
/* @0xdf41c ldr r4, [r10] */
/* @0xdf420 ldrd r0, r1, [r9] */
/* @0xdf424 asr r5, r4, #31 */
/* @0xdf428 bl 0x3194a0 <__fixdfdi> */
/* @0xdf42c and r0, r0, r4 */
/* @0xdf430 and r1, r1, r5 */
/* @0xdf434 bl 0x319164 <__floatdidf> */
/* @0xdf438 mov r12, #0 */
/* @0xdf43c strd r0, r1, [r8] */
/* @0xdf440 cmp r7, #0 */
/* @0xdf444 beq 0xdf050 <_Z5DoAndjPhPKhP6VMExec+0xe0> */
/* @0xdf448 mov r0, r6 */
/* @0xdf44c str r12, [r7, #0xc] */
/* @0xdf450 add sp, sp, #68 */
/* @0xdf454 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xdf458 ldrd r0, r1, [r10] */
/* @0xdf45c bl 0x3194a0 <__fixdfdi> */
/* @0xdf460 ldr r3, [r9] */
/* @0xdf464 and r0, r0, r3 */
/* @0xdf468 and r1, r1, r3, asr #31 */
/* @0xdf46c bl 0x319164 <__floatdidf> */
/* @0xdf470 mov r12, #0 */
/* @0xdf474 strd r0, r1, [r8] */
/* @0xdf478 b 0xdf440 <_Z5DoAndjPhPKhP6VMExec+0x4d0> */
/* @0xdf47c mov r8, #0 */
/* @0xdf480 mov r7, r8 */
/* @0xdf484 b 0xdf214 <_Z5DoAndjPhPKhP6VMExec+0x2a4> */
/* @0xdf488 ldr r0, [pc, #0x338] */
/* @0xdf48c add r0, pc, r0 */
/* @0xdf490 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xdf494 mov r0, r6 */
/* @0xdf498 b 0xdf054 <_Z5DoAndjPhPKhP6VMExec+0xe4> */
/* @0xdf49c ldrd r0, r1, [r10] */
/* @0xdf4a0 mov r12, #10 */
/* @0xdf4a4 ldrd r2, r3, [r9] */
/* @0xdf4a8 and r2, r2, r0 */
/* @0xdf4ac and r3, r3, r1 */
/* @0xdf4b0 strd r2, r3, [r8] */
/* @0xdf4b4 b 0xdf440 <_Z5DoAndjPhPKhP6VMExec+0x4d0> */
/* @0xdf4b8 ldr r1, [r10] */
/* @0xdf4bc mov r12, #10 */
/* @0xdf4c0 ldrd r2, r3, [r9] */
/* @0xdf4c4 and r2, r2, r1 */
/* @0xdf4c8 and r3, r3, r1, asr #31 */
/* @0xdf4cc strd r2, r3, [r8] */
/* @0xdf4d0 b 0xdf440 <_Z5DoAndjPhPKhP6VMExec+0x4d0> */
/* @0xdf4d4 ldr r2, [r10] */
/* @0xdf4d8 mov r12, #7 */
/* @0xdf4dc ldr r3, [r9] */
/* @0xdf4e0 and r3, r2, r3 */
/* @0xdf4e4 str r3, [r8] */
/* @0xdf4e8 b 0xdf440 <_Z5DoAndjPhPKhP6VMExec+0x4d0> */
/* @0xdf4ec ldr r1, [r9] */
/* @0xdf4f0 mov r12, #10 */
/* @0xdf4f4 ldrd r2, r3, [r10] */
/* @0xdf4f8 and r2, r2, r1 */
/* @0xdf4fc and r3, r3, r1, asr #31 */
/* @0xdf500 strd r2, r3, [r8] */
/* @0xdf504 b 0xdf440 <_Z5DoAndjPhPKhP6VMExec+0x4d0> */
/* @0xdf508 ldrd r0, r1, [r9] */
/* @0xdf50c bl 0x3194a0 <__fixdfdi> */
/* @0xdf510 ldrd r2, r3, [r10] */
/* @0xdf514 and r0, r0, r2 */
/* @0xdf518 and r1, r1, r3 */
/* @0xdf51c bl 0x319164 <__floatdidf> */
/* @0xdf520 mov r12, #0 */
/* @0xdf524 strd r0, r1, [r8] */
/* @0xdf528 b 0xdf440 <_Z5DoAndjPhPKhP6VMExec+0x4d0> */
/* @0xdf52c ldr r3, [r10] */
/* @0xdf530 cmp r3, #0 */
/* @0xdf534 beq 0xdf544 <_Z5DoAndjPhPKhP6VMExec+0x5d4> */
/* @0xdf538 ldr r3, [r9] */
/* @0xdf53c adds r3, r3, #0 */
/* @0xdf540 movne r3, #1 */
/* @0xdf544 str r3, [r8] */
/* @0xdf548 mov r12, #13 */
/* @0xdf54c b 0xdf440 <_Z5DoAndjPhPKhP6VMExec+0x4d0> */
/* @0xdf550 ldrd r0, r1, [r10] */
/* @0xdf554 bl 0x3194a0 <__fixdfdi> */
/* @0xdf558 ldrd r2, r3, [r9] */
/* @0xdf55c b 0xdf514 <_Z5DoAndjPhPKhP6VMExec+0x5a4> */
/* @0xdf560 ldrd r0, r1, [r10] */
/* @0xdf564 bl 0x3194a0 <__fixdfdi> */
/* @0xdf568 mov r4, r0 */
/* @0xdf56c mov r5, r1 */
/* @0xdf570 ldrd r0, r1, [r9] */
/* @0xdf574 b 0xdf428 <_Z5DoAndjPhPKhP6VMExec+0x4b8> */
/* @0xdf578 ldr r1, [pc, #0x24c] */
/* @0xdf57c mov r0, r11 */
/* @0xdf580 add r1, pc, r1 */
/* @0xdf584 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf588 mov r12, #0 */
/* @0xdf58c b 0xdf440 <_Z5DoAndjPhPKhP6VMExec+0x4d0> */
/* @0xdf590 add r7, sp, #48 */
/* @0xdf594 mov r1, r4 */
/* @0xdf598 mov r0, r7 */
/* @0xdf59c bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0xdf5a0 cmp r0, #1 */
/* @0xdf5a4 beq 0xdf798 <_Z5DoAndjPhPKhP6VMExec+0x828> */
/* @0xdf5a8 cmp r0, #0 */
/* @0xdf5ac bne 0xdf050 <_Z5DoAndjPhPKhP6VMExec+0xe0> */
/* @0xdf5b0 str r0, [r6, #-0x4] */
/* @0xdf5b4 sub r4, r6, #16 */
/* @0xdf5b8 vldr d7, [sp, #32] */
/* @0xdf5bc vldr d6, [sp, #48] */
/* @0xdf5c0 vcvt.s32.f64 s14, d7 */
/* @0xdf5c4 ldr r3, [sp, #0x2c] */
/* @0xdf5c8 sub r3, r3, #1 */
/* @0xdf5cc bic r3, r3, #-16777216 */
/* @0xdf5d0 bic r3, r3, #3 */
/* @0xdf5d4 cmp r3, #0 */
/* @0xdf5d8 vcvt.s32.f64 s11, d6 */
/* @0xdf5dc vmov r3, s14 */
/* @0xdf5e0 vmov r2, s11 */
/* @0xdf5e4 and r2, r2, r3 */
/* @0xdf5e8 vmov s15, r2 */
/* @0xdf5ec vcvt.f64.s32 d7, s15 */
/* @0xdf5f0 vmov r2, r3, d7 */
/* @0xdf5f4 vstr s14, [r6, #-16] */
/* @0xdf5f8 str r3, [r6, #-0xc] */
/* @0xdf5fc beq 0xdf78c <_Z5DoAndjPhPKhP6VMExec+0x81c> */
/* @0xdf600 ldr r1, [sp, #0x3c] */
/* @0xdf604 mov r3, #0 */
/* @0xdf608 str r3, [sp, #0x28] */
/* @0xdf60c mov r2, #5 */
/* @0xdf610 sub r1, r1, #1 */
/* @0xdf614 str r3, [sp, #0x20] */
/* @0xdf618 bic r3, r1, #-16777216 */
/* @0xdf61c str r2, [sp, #0x2c] */
/* @0xdf620 bic r3, r3, #3 */
/* @0xdf624 cmp r3, #0 */
/* @0xdf628 movne r0, r4 */
/* @0xdf62c bne 0xdf054 <_Z5DoAndjPhPKhP6VMExec+0xe4> */
/* @0xdf630 mov r0, r7 */
/* @0xdf634 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdf638 mov r0, r4 */
/* @0xdf63c b 0xdf054 <_Z5DoAndjPhPKhP6VMExec+0xe4> */
/* @0xdf640 and r5, r5, #15 */
/* @0xdf644 orr r5, r5, #48 */
/* @0xdf648 add r6, r10, #16 */
/* @0xdf64c b 0xdf0a4 <_Z5DoAndjPhPKhP6VMExec+0x134> */
/* @0xdf650 and r5, r5, #15 */
/* @0xdf654 orr r5, r5, #32 */
/* @0xdf658 b 0xdf648 <_Z5DoAndjPhPKhP6VMExec+0x6d8> */
/* @0xdf65c ldr r1, [pc, #0x16c] */
/* @0xdf660 mov r0, r11 */
/* @0xdf664 add r1, pc, r1 */
/* @0xdf668 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf66c b 0xdf648 <_Z5DoAndjPhPKhP6VMExec+0x6d8> */
/* @0xdf670 ldr r1, [pc, #0x15c] */
/* @0xdf674 mov r0, r11 */
/* @0xdf678 add r1, pc, r1 */
/* @0xdf67c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf680 b 0xdf648 <_Z5DoAndjPhPKhP6VMExec+0x6d8> */
/* @0xdf684 ldr r1, [pc, #0x14c] */
/* @0xdf688 mov r0, r11 */
/* @0xdf68c add r1, pc, r1 */
/* @0xdf690 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf694 b 0xdf648 <_Z5DoAndjPhPKhP6VMExec+0x6d8> */
/* @0xdf698 ldr r1, [pc, #0x13c] */
/* @0xdf69c mov r0, r11 */
/* @0xdf6a0 add r1, pc, r1 */
/* @0xdf6a4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf6a8 b 0xdf648 <_Z5DoAndjPhPKhP6VMExec+0x6d8> */
/* @0xdf6ac and r5, r5, #15 */
/* @0xdf6b0 b 0xdf648 <_Z5DoAndjPhPKhP6VMExec+0x6d8> */
/* @0xdf6b4 and r5, r5, #240 */
/* @0xdf6b8 orr r5, r5, #3 */
/* @0xdf6bc add r10, r9, #16 */
/* @0xdf6c0 b 0xdf064 <_Z5DoAndjPhPKhP6VMExec+0xf4> */
/* @0xdf6c4 and r5, r5, #240 */
/* @0xdf6c8 orr r5, r5, #2 */
/* @0xdf6cc b 0xdf6bc <_Z5DoAndjPhPKhP6VMExec+0x74c> */
/* @0xdf6d0 ldr r1, [pc, #0x108] */
/* @0xdf6d4 mov r0, r11 */
/* @0xdf6d8 mov r5, r4 */
/* @0xdf6dc add r1, pc, r1 */
/* @0xdf6e0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf6e4 b 0xdf6bc <_Z5DoAndjPhPKhP6VMExec+0x74c> */
/* @0xdf6e8 ldr r1, [pc, #0xf4] */
/* @0xdf6ec mov r0, r11 */
/* @0xdf6f0 mov r5, r4 */
/* @0xdf6f4 add r1, pc, r1 */
/* @0xdf6f8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf6fc b 0xdf6bc <_Z5DoAndjPhPKhP6VMExec+0x74c> */
/* @0xdf700 ldr r1, [pc, #0xe0] */
/* @0xdf704 mov r0, r11 */
/* @0xdf708 mov r5, r4 */
/* @0xdf70c add r1, pc, r1 */
/* @0xdf710 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf714 b 0xdf6bc <_Z5DoAndjPhPKhP6VMExec+0x74c> */
/* @0xdf718 ldr r1, [pc, #0xcc] */
/* @0xdf71c mov r0, r11 */
/* @0xdf720 mov r5, r4 */
/* @0xdf724 add r1, pc, r1 */
/* @0xdf728 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf72c b 0xdf6bc <_Z5DoAndjPhPKhP6VMExec+0x74c> */
/* @0xdf730 and r5, r4, #240 */
/* @0xdf734 b 0xdf6bc <_Z5DoAndjPhPKhP6VMExec+0x74c> */
/* @0xdf738 ldr r1, [pc, #0xb0] */
/* @0xdf73c mov r0, r11 */
/* @0xdf740 add r1, pc, r1 */
/* @0xdf744 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf748 b 0xdf648 <_Z5DoAndjPhPKhP6VMExec+0x6d8> */
/* @0xdf74c ldr r1, [pc, #0xa0] */
/* @0xdf750 mov r0, r11 */
/* @0xdf754 mov r5, r4 */
/* @0xdf758 add r1, pc, r1 */
/* @0xdf75c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf760 b 0xdf6bc <_Z5DoAndjPhPKhP6VMExec+0x74c> */
/* @0xdf764 ldr r0, [pc, #0x8c] */
/* @0xdf768 add r0, pc, r0 */
/* @0xdf76c bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xdf770 mov r0, r6 */
/* @0xdf774 b 0xdf054 <_Z5DoAndjPhPKhP6VMExec+0xe4> */
/* @0xdf778 ldr r0, [pc, #0x7c] */
/* @0xdf77c add r0, pc, r0 */
/* @0xdf780 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xdf784 mov r0, r6 */
/* @0xdf788 b 0xdf054 <_Z5DoAndjPhPKhP6VMExec+0xe4> */
/* @0xdf78c mov r0, r5 */
/* @0xdf790 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdf794 b 0xdf600 <_Z5DoAndjPhPKhP6VMExec+0x690> */
/* @0xdf798 ldr r0, [pc, #0x60] */
/* @0xdf79c add r0, pc, r0 */
/* @0xdf7a0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xdf7a4 mov r0, r6 */
/* @0xdf7a8 b 0xdf054 <_Z5DoAndjPhPKhP6VMExec+0xe4> */
/* @0xdf7ac mov r5, r4 */
/* @0xdf7b0 mov r10, r1 */
/* @0xdf7b4 b 0xdf064 <_Z5DoAndjPhPKhP6VMExec+0xf4> */
/* @0xdf7b8 mov r6, r10 */
/* @0xdf7bc b 0xdf0a4 <_Z5DoAndjPhPKhP6VMExec+0x134> */
/* @0xdf7c0 eoreq r4, r5, r12, ror r6 */
/* @0xdf7c4 eoreq r4, r5, r8, lsl #6 */
/* @0xdf7c8 eoreq r4, r5, r8, lsl #4 */
/* @0xdf7cc eoreq r4, r5, r12, lsr r3 */
/* @0xdf7d0 eoreq r4, r5, r0, lsl #4 */
/* @0xdf7d4 eoreq r4, r5, r12, asr #3 */
/* @0xdf7d8 .word 0x002541f4 */
/* @0xdf7dc eoreq r4, r5, r8, ror #2 */
/* @0xdf7e0 mlaeq r5, r8, r0, r4 */
/* @0xdf7e4 eoreq r4, r5, r0, rrx */
/* @0xdf7e8 eoreq r4, r5, r0, asr #1 */
/* @0xdf7ec eoreq r4, r5, r12, rrx */
/* @0xdf7f0 eoreq r4, r5, r12, asr r1 */
/* @0xdf7f4 mlaeq r5, r0, r0, r4 */
/* @0xdf7f8 eoreq r3, r5, r8, lsl #30 */
/* @0xdf7fc eoreq r3, r5, r12, lsr pc */
/* @0xdf800 eoreq r3, r5, r12, asr #30 */

/* ── FUNC 0xdf804 · DoOr(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=2260 · insn=565 */
/* @0xdf804 tst r0, #3840 */
/* @0xdf808 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xdf80c lsr r5, r0, #16 */
/* @0xdf810 sub sp, sp, #68 */
/* @0xdf814 mov r9, r1 */
/* @0xdf818 mov r11, r3 */
/* @0xdf81c bne 0xdf850 <_Z4DoOrjPhPKhP6VMExec+0x4c> */
/* @0xdf820 uxtb r4, r5 */
/* @0xdf824 and r2, r4, #15 */
/* @0xdf828 cmp r2, #6 */
/* @0xdf82c addls pc, pc, r2, lsl #2 */
/* @0xdf830 b 0xe0080 <_Z4DoOrjPhPKhP6VMExec+0x87c> */
/* @0xdf834 b 0xdf8f0 <_Z4DoOrjPhPKhP6VMExec+0xec> */
/* @0xdf838 b 0xdfc40 <_Z4DoOrjPhPKhP6VMExec+0x43c> */
/* @0xdf83c b 0xdfc40 <_Z4DoOrjPhPKhP6VMExec+0x43c> */
/* @0xdf840 b 0xdf8f0 <_Z4DoOrjPhPKhP6VMExec+0xec> */
/* @0xdf844 b 0xdfc40 <_Z4DoOrjPhPKhP6VMExec+0x43c> */
/* @0xdf848 b 0xdfc4c <_Z4DoOrjPhPKhP6VMExec+0x448> */
/* @0xdf84c b 0xdfc94 <_Z4DoOrjPhPKhP6VMExec+0x490> */
/* @0xdf850 add r4, sp, #16 */
/* @0xdf854 uxtb r5, r5 */
/* @0xdf858 mov r2, r1 */
/* @0xdf85c and r1, r5, #15 */
/* @0xdf860 mov r0, r4 */
/* @0xdf864 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xdf868 lsr r1, r5, #4 */
/* @0xdf86c mov r2, r0 */
/* @0xdf870 mov r0, sp */
/* @0xdf874 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xdf878 ldr r3, [sp, #0xc] */
/* @0xdf87c mvn r12, #-16777216 */
/* @0xdf880 and r3, r3, r12 */
/* @0xdf884 cmp r3, r12 */
/* @0xdf888 mov r6, r0 */
/* @0xdf88c beq 0xe0038 <_Z4DoOrjPhPKhP6VMExec+0x834> */
/* @0xdf890 ldr r3, [sp, #0x1c] */
/* @0xdf894 bic r3, r3, #-16777216 */
/* @0xdf898 cmp r3, r12 */
/* @0xdf89c beq 0xdfcbc <_Z4DoOrjPhPKhP6VMExec+0x4b8> */
/* @0xdf8a0 add r5, sp, #32 */
/* @0xdf8a4 mov r1, sp */
/* @0xdf8a8 mov r2, #0 */
/* @0xdf8ac mov r3, #0 */
/* @0xdf8b0 mov r0, r5 */
/* @0xdf8b4 str r12, [sp, #0x2c] */
/* @0xdf8b8 str r12, [sp, #0x3c] */
/* @0xdf8bc mov r12, #0 */
/* @0xdf8c0 strd r2, r3, [sp, #32] */
/* @0xdf8c4 strd r2, r3, [sp, #48] */
/* @0xdf8c8 str r12, [sp, #0x28] */
/* @0xdf8cc str r12, [sp, #0x38] */
/* @0xdf8d0 bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0xdf8d4 cmp r0, #1 */
/* @0xdf8d8 beq 0xe004c <_Z4DoOrjPhPKhP6VMExec+0x848> */
/* @0xdf8dc cmp r0, #0 */
/* @0xdf8e0 beq 0xdfe54 <_Z4DoOrjPhPKhP6VMExec+0x650> */
/* @0xdf8e4 mov r0, r6 */
/* @0xdf8e8 add sp, sp, #68 */
/* @0xdf8ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xdf8f0 add r10, r1, #8 */
/* @0xdf8f4 mov r5, r4 */
/* @0xdf8f8 asr r2, r5, #4 */
/* @0xdf8fc cmp r2, #6 */
/* @0xdf900 addls pc, pc, r2, lsl #2 */
/* @0xdf904 b 0xe008c <_Z4DoOrjPhPKhP6VMExec+0x888> */
/* @0xdf908 b 0xdfc38 <_Z4DoOrjPhPKhP6VMExec+0x434> */
/* @0xdf90c b 0xdfc30 <_Z4DoOrjPhPKhP6VMExec+0x42c> */
/* @0xdf910 b 0xdfc30 <_Z4DoOrjPhPKhP6VMExec+0x42c> */
/* @0xdf914 b 0xdfc38 <_Z4DoOrjPhPKhP6VMExec+0x434> */
/* @0xdf918 b 0xdfc30 <_Z4DoOrjPhPKhP6VMExec+0x42c> */
/* @0xdf91c b 0xdfbe8 <_Z4DoOrjPhPKhP6VMExec+0x3e4> */
/* @0xdf920 b 0xdf924 <_Z4DoOrjPhPKhP6VMExec+0x120> */
/* @0xdf924 ldr r1, [pc, #0x768] */
/* @0xdf928 mov r0, r11 */
/* @0xdf92c mov r6, r10 */
/* @0xdf930 add r1, pc, r1 */
/* @0xdf934 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf938 cmp r4, #85 */
/* @0xdf93c addls pc, pc, r4, lsl #2 */
/* @0xdf940 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf944 b 0xdfbd8 <_Z4DoOrjPhPKhP6VMExec+0x3d4> */
/* @0xdf948 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf94c b 0xdfbd8 <_Z4DoOrjPhPKhP6VMExec+0x3d4> */
/* @0xdf950 b 0xdfbd8 <_Z4DoOrjPhPKhP6VMExec+0x3d4> */
/* @0xdf954 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf958 b 0xdfbc8 <_Z4DoOrjPhPKhP6VMExec+0x3c4> */
/* @0xdf95c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf960 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf964 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf968 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf96c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf970 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf974 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf978 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf97c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf980 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf984 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf988 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf98c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf990 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf994 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf998 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf99c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf9a0 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf9a4 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf9a8 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf9ac b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf9b0 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf9b4 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf9b8 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf9bc b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf9c0 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf9c4 b 0xdfbd8 <_Z4DoOrjPhPKhP6VMExec+0x3d4> */
/* @0xdf9c8 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf9cc b 0xdfa9c <_Z4DoOrjPhPKhP6VMExec+0x298> */
/* @0xdf9d0 b 0xdfbd8 <_Z4DoOrjPhPKhP6VMExec+0x3d4> */
/* @0xdf9d4 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf9d8 b 0xdfbc8 <_Z4DoOrjPhPKhP6VMExec+0x3c4> */
/* @0xdf9dc b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf9e0 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf9e4 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf9e8 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf9ec b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf9f0 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf9f4 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf9f8 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdf9fc b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa00 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa04 b 0xdfbd8 <_Z4DoOrjPhPKhP6VMExec+0x3d4> */
/* @0xdfa08 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa0c b 0xdfbd8 <_Z4DoOrjPhPKhP6VMExec+0x3d4> */
/* @0xdfa10 b 0xdfbd8 <_Z4DoOrjPhPKhP6VMExec+0x3d4> */
/* @0xdfa14 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa18 b 0xdfbc8 <_Z4DoOrjPhPKhP6VMExec+0x3c4> */
/* @0xdfa1c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa20 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa24 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa28 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa2c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa30 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa34 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa38 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa3c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa40 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa44 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa48 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa4c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa50 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa54 b 0xdfa9c <_Z4DoOrjPhPKhP6VMExec+0x298> */
/* @0xdfa58 b 0xdfbc8 <_Z4DoOrjPhPKhP6VMExec+0x3c4> */
/* @0xdfa5c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa60 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa64 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa68 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa6c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa70 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa74 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa78 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa7c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa80 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa84 b 0xdfbc8 <_Z4DoOrjPhPKhP6VMExec+0x3c4> */
/* @0xdfa88 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0xdfa8c b 0xdfbc8 <_Z4DoOrjPhPKhP6VMExec+0x3c4> */
/* @0xdfa90 b 0xdfbc8 <_Z4DoOrjPhPKhP6VMExec+0x3c4> */
/* @0xdfa94 b 0xdfbc8 <_Z4DoOrjPhPKhP6VMExec+0x3c4> */
/* @0xdfa98 b 0xdfbc8 <_Z4DoOrjPhPKhP6VMExec+0x3c4> */
/* @0xdfa9c sub r6, r6, #4 */
/* @0xdfaa0 mov r7, #0 */
/* @0xdfaa4 mov r8, r6 */
/* @0xdfaa8 cmp r5, #68 */
/* @0xdfaac addls pc, pc, r5, lsl #2 */
/* @0xdfab0 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfab4 b 0xdfd24 <_Z4DoOrjPhPKhP6VMExec+0x520> */
/* @0xdfab8 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfabc b 0xdfd54 <_Z4DoOrjPhPKhP6VMExec+0x550> */
/* @0xdfac0 b 0xdfcec <_Z4DoOrjPhPKhP6VMExec+0x4e8> */
/* @0xdfac4 b 0xdfe20 <_Z4DoOrjPhPKhP6VMExec+0x61c> */
/* @0xdfac8 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfacc b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfad0 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfad4 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfad8 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfadc b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfae0 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfae4 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfae8 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfaec b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfaf0 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfaf4 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfaf8 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfafc b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb00 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb04 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb08 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb0c b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb10 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb14 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb18 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb1c b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb20 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb24 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb28 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb2c b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb30 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb34 b 0xdfe10 <_Z4DoOrjPhPKhP6VMExec+0x60c> */
/* @0xdfb38 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb3c b 0xdfdf8 <_Z4DoOrjPhPKhP6VMExec+0x5f4> */
/* @0xdfb40 b 0xdfddc <_Z4DoOrjPhPKhP6VMExec+0x5d8> */
/* @0xdfb44 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb48 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb4c b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb50 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb54 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb58 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb5c b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb60 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb64 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb68 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb6c b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb70 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb74 b 0xdfdcc <_Z4DoOrjPhPKhP6VMExec+0x5c8> */
/* @0xdfb78 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb7c b 0xdfdb0 <_Z4DoOrjPhPKhP6VMExec+0x5ac> */
/* @0xdfb80 b 0xdfd94 <_Z4DoOrjPhPKhP6VMExec+0x590> */
/* @0xdfb84 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb88 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb8c b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb90 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb94 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb98 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfb9c b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfba0 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfba4 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfba8 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfbac b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfbb0 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfbb4 b 0xdfd78 <_Z4DoOrjPhPKhP6VMExec+0x574> */
/* @0xdfbb8 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfbbc b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfbc0 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0xdfbc4 b 0xdfcd0 <_Z4DoOrjPhPKhP6VMExec+0x4cc> */
/* @0xdfbc8 sub r7, r6, #16 */
/* @0xdfbcc mov r8, r7 */
/* @0xdfbd0 mov r6, r7 */
/* @0xdfbd4 b 0xdfaa8 <_Z4DoOrjPhPKhP6VMExec+0x2a4> */
/* @0xdfbd8 sub r6, r6, #8 */
/* @0xdfbdc mov r7, #0 */
/* @0xdfbe0 mov r8, r6 */
/* @0xdfbe4 b 0xdfaa8 <_Z4DoOrjPhPKhP6VMExec+0x2a4> */
/* @0xdfbe8 ldr r3, [r10, #0xc] */
/* @0xdfbec cmp r3, #13 */
/* @0xdfbf0 addls pc, pc, r3, lsl #2 */
/* @0xdfbf4 b 0xe000c <_Z4DoOrjPhPKhP6VMExec+0x808> */
/* @0xdfbf8 b 0xdff80 <_Z4DoOrjPhPKhP6VMExec+0x77c> */
/* @0xdfbfc b 0xdff6c <_Z4DoOrjPhPKhP6VMExec+0x768> */
/* @0xdfc00 b 0xdff58 <_Z4DoOrjPhPKhP6VMExec+0x754> */
/* @0xdfc04 b 0xdff44 <_Z4DoOrjPhPKhP6VMExec+0x740> */
/* @0xdfc08 b 0xe000c <_Z4DoOrjPhPKhP6VMExec+0x808> */
/* @0xdfc0c b 0xdff30 <_Z4DoOrjPhPKhP6VMExec+0x72c> */
/* @0xdfc10 b 0xe000c <_Z4DoOrjPhPKhP6VMExec+0x808> */
/* @0xdfc14 b 0xdff24 <_Z4DoOrjPhPKhP6VMExec+0x720> */
/* @0xdfc18 b 0xe000c <_Z4DoOrjPhPKhP6VMExec+0x808> */
/* @0xdfc1c b 0xe000c <_Z4DoOrjPhPKhP6VMExec+0x808> */
/* @0xdfc20 b 0xdff14 <_Z4DoOrjPhPKhP6VMExec+0x710> */
/* @0xdfc24 b 0xe000c <_Z4DoOrjPhPKhP6VMExec+0x808> */
/* @0xdfc28 b 0xe000c <_Z4DoOrjPhPKhP6VMExec+0x808> */
/* @0xdfc2c b 0xdff80 <_Z4DoOrjPhPKhP6VMExec+0x77c> */
/* @0xdfc30 add r6, r10, #4 */
/* @0xdfc34 b 0xdf938 <_Z4DoOrjPhPKhP6VMExec+0x134> */
/* @0xdfc38 add r6, r10, #8 */
/* @0xdfc3c b 0xdf938 <_Z4DoOrjPhPKhP6VMExec+0x134> */
/* @0xdfc40 add r10, r1, #4 */
/* @0xdfc44 mov r5, r4 */
/* @0xdfc48 b 0xdf8f8 <_Z4DoOrjPhPKhP6VMExec+0xf4> */
/* @0xdfc4c ldr r3, [r1, #0xc] */
/* @0xdfc50 cmp r3, #13 */
/* @0xdfc54 addls pc, pc, r3, lsl #2 */
/* @0xdfc58 b 0xe0020 <_Z4DoOrjPhPKhP6VMExec+0x81c> */
/* @0xdfc5c b 0xe0004 <_Z4DoOrjPhPKhP6VMExec+0x800> */
/* @0xdfc60 b 0xdffec <_Z4DoOrjPhPKhP6VMExec+0x7e8> */
/* @0xdfc64 b 0xdffd4 <_Z4DoOrjPhPKhP6VMExec+0x7d0> */
/* @0xdfc68 b 0xdffbc <_Z4DoOrjPhPKhP6VMExec+0x7b8> */
/* @0xdfc6c b 0xe0020 <_Z4DoOrjPhPKhP6VMExec+0x81c> */
/* @0xdfc70 b 0xdffa4 <_Z4DoOrjPhPKhP6VMExec+0x7a0> */
/* @0xdfc74 b 0xe0020 <_Z4DoOrjPhPKhP6VMExec+0x81c> */
/* @0xdfc78 b 0xdff98 <_Z4DoOrjPhPKhP6VMExec+0x794> */
/* @0xdfc7c b 0xe0020 <_Z4DoOrjPhPKhP6VMExec+0x81c> */
/* @0xdfc80 b 0xe0020 <_Z4DoOrjPhPKhP6VMExec+0x81c> */
/* @0xdfc84 b 0xdff88 <_Z4DoOrjPhPKhP6VMExec+0x784> */
/* @0xdfc88 b 0xe0020 <_Z4DoOrjPhPKhP6VMExec+0x81c> */
/* @0xdfc8c b 0xe0020 <_Z4DoOrjPhPKhP6VMExec+0x81c> */
/* @0xdfc90 b 0xe0004 <_Z4DoOrjPhPKhP6VMExec+0x800> */
/* @0xdfc94 ldr r1, [pc, #0x3fc] */
/* @0xdfc98 mov r0, r3 */
/* @0xdfc9c mov r5, r4 */
/* @0xdfca0 mov r10, r9 */
/* @0xdfca4 add r1, pc, r1 */
/* @0xdfca8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdfcac b 0xdf8f8 <_Z4DoOrjPhPKhP6VMExec+0xf4> */
/* @0xdfcb0 mov r8, #0 */
/* @0xdfcb4 mov r7, r8 */
/* @0xdfcb8 b 0xdfaa8 <_Z4DoOrjPhPKhP6VMExec+0x2a4> */
/* @0xdfcbc ldr r0, [pc, #0x3d8] */
/* @0xdfcc0 add r0, pc, r0 */
/* @0xdfcc4 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xdfcc8 mov r0, r6 */
/* @0xdfccc b 0xdf8e8 <_Z4DoOrjPhPKhP6VMExec+0xe4> */
/* @0xdfcd0 ldr r3, [r10] */
/* @0xdfcd4 cmp r3, #0 */
/* @0xdfcd8 movne r3, #1 */
/* @0xdfcdc beq 0xdff04 <_Z4DoOrjPhPKhP6VMExec+0x700> */
/* @0xdfce0 str r3, [r8] */
/* @0xdfce4 mov r12, #13 */
/* @0xdfce8 b 0xdfd0c <_Z4DoOrjPhPKhP6VMExec+0x508> */
/* @0xdfcec ldrd r0, r1, [r10] */
/* @0xdfcf0 bl 0x3194a0 <__fixdfdi> */
/* @0xdfcf4 ldrd r2, r3, [r9] */
/* @0xdfcf8 orr r0, r0, r2 */
/* @0xdfcfc orr r1, r1, r3 */
/* @0xdfd00 bl 0x319164 <__floatdidf> */
/* @0xdfd04 mov r12, #0 */
/* @0xdfd08 strd r0, r1, [r8] */
/* @0xdfd0c cmp r7, #0 */
/* @0xdfd10 beq 0xdf8e4 <_Z4DoOrjPhPKhP6VMExec+0xe0> */
/* @0xdfd14 mov r0, r6 */
/* @0xdfd18 str r12, [r7, #0xc] */
/* @0xdfd1c add sp, sp, #68 */
/* @0xdfd20 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xdfd24 ldrd r0, r1, [r10] */
/* @0xdfd28 bl 0x3194a0 <__fixdfdi> */
/* @0xdfd2c mov r4, r0 */
/* @0xdfd30 mov r5, r1 */
/* @0xdfd34 ldrd r0, r1, [r9] */
/* @0xdfd38 bl 0x3194a0 <__fixdfdi> */
/* @0xdfd3c orr r0, r0, r4 */
/* @0xdfd40 orr r1, r1, r5 */
/* @0xdfd44 bl 0x319164 <__floatdidf> */
/* @0xdfd48 mov r12, #0 */
/* @0xdfd4c strd r0, r1, [r8] */
/* @0xdfd50 b 0xdfd0c <_Z4DoOrjPhPKhP6VMExec+0x508> */
/* @0xdfd54 ldrd r0, r1, [r10] */
/* @0xdfd58 bl 0x3194a0 <__fixdfdi> */
/* @0xdfd5c ldr r3, [r9] */
/* @0xdfd60 orr r0, r0, r3 */
/* @0xdfd64 orr r1, r1, r3, asr #31 */
/* @0xdfd68 bl 0x319164 <__floatdidf> */
/* @0xdfd6c mov r12, #0 */
/* @0xdfd70 strd r0, r1, [r8] */
/* @0xdfd74 b 0xdfd0c <_Z4DoOrjPhPKhP6VMExec+0x508> */
/* @0xdfd78 ldr r4, [r10] */
/* @0xdfd7c mov r5, #0 */
/* @0xdfd80 ldrd r0, r1, [r9] */
/* @0xdfd84 subs r2, r4, #1 */
/* @0xdfd88 rsbs r4, r2, #0 */
/* @0xdfd8c adcs r4, r4, r2 */
/* @0xdfd90 b 0xdfd38 <_Z4DoOrjPhPKhP6VMExec+0x534> */
/* @0xdfd94 ldrd r0, r1, [r10] */
/* @0xdfd98 mov r12, #10 */
/* @0xdfd9c ldrd r2, r3, [r9] */
/* @0xdfda0 orr r2, r2, r0 */
/* @0xdfda4 orr r3, r3, r1 */
/* @0xdfda8 strd r2, r3, [r8] */
/* @0xdfdac b 0xdfd0c <_Z4DoOrjPhPKhP6VMExec+0x508> */
/* @0xdfdb0 ldr r1, [r9] */
/* @0xdfdb4 mov r12, #10 */
/* @0xdfdb8 ldrd r2, r3, [r10] */
/* @0xdfdbc orr r2, r2, r1 */
/* @0xdfdc0 orr r3, r3, r1, asr #31 */
/* @0xdfdc4 strd r2, r3, [r8] */
/* @0xdfdc8 b 0xdfd0c <_Z4DoOrjPhPKhP6VMExec+0x508> */
/* @0xdfdcc ldrd r0, r1, [r9] */
/* @0xdfdd0 bl 0x3194a0 <__fixdfdi> */
/* @0xdfdd4 ldrd r2, r3, [r10] */
/* @0xdfdd8 b 0xdfcf8 <_Z4DoOrjPhPKhP6VMExec+0x4f4> */
/* @0xdfddc ldr r1, [r10] */
/* @0xdfde0 mov r12, #10 */
/* @0xdfde4 ldrd r2, r3, [r9] */
/* @0xdfde8 orr r2, r2, r1 */
/* @0xdfdec orr r3, r3, r1, asr #31 */
/* @0xdfdf0 strd r2, r3, [r8] */
/* @0xdfdf4 b 0xdfd0c <_Z4DoOrjPhPKhP6VMExec+0x508> */
/* @0xdfdf8 ldr r2, [r10] */
/* @0xdfdfc mov r12, #7 */
/* @0xdfe00 ldr r3, [r9] */
/* @0xdfe04 orr r3, r2, r3 */
/* @0xdfe08 str r3, [r8] */
/* @0xdfe0c b 0xdfd0c <_Z4DoOrjPhPKhP6VMExec+0x508> */
/* @0xdfe10 ldr r4, [r10] */
/* @0xdfe14 ldrd r0, r1, [r9] */
/* @0xdfe18 asr r5, r4, #31 */
/* @0xdfe1c b 0xdfd38 <_Z4DoOrjPhPKhP6VMExec+0x534> */
/* @0xdfe20 ldr r4, [r10] */
/* @0xdfe24 mov r5, #0 */
/* @0xdfe28 ldrd r0, r1, [r10] */
/* @0xdfe2c subs r3, r4, #1 */
/* @0xdfe30 rsbs r4, r3, #0 */
/* @0xdfe34 adcs r4, r4, r3 */
/* @0xdfe38 b 0xdfd38 <_Z4DoOrjPhPKhP6VMExec+0x534> */
/* @0xdfe3c ldr r1, [pc, #0x25c] */
/* @0xdfe40 mov r0, r11 */
/* @0xdfe44 add r1, pc, r1 */
/* @0xdfe48 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdfe4c mov r12, #0 */
/* @0xdfe50 b 0xdfd0c <_Z4DoOrjPhPKhP6VMExec+0x508> */
/* @0xdfe54 add r7, sp, #48 */
/* @0xdfe58 mov r1, r4 */
/* @0xdfe5c mov r0, r7 */
/* @0xdfe60 bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0xdfe64 cmp r0, #1 */
/* @0xdfe68 beq 0xe006c <_Z4DoOrjPhPKhP6VMExec+0x868> */
/* @0xdfe6c cmp r0, #0 */
/* @0xdfe70 bne 0xdf8e4 <_Z4DoOrjPhPKhP6VMExec+0xe0> */
/* @0xdfe74 str r0, [r6, #-0x4] */
/* @0xdfe78 sub r4, r6, #16 */
/* @0xdfe7c vldr d7, [sp, #32] */
/* @0xdfe80 vldr d6, [sp, #48] */
/* @0xdfe84 vcvt.s32.f64 s14, d7 */
/* @0xdfe88 ldr r3, [sp, #0x2c] */
/* @0xdfe8c sub r3, r3, #1 */
/* @0xdfe90 bic r3, r3, #-16777216 */
/* @0xdfe94 bic r3, r3, #3 */
/* @0xdfe98 cmp r3, #0 */
/* @0xdfe9c vcvt.s32.f64 s11, d6 */
/* @0xdfea0 vmov r3, s14 */
/* @0xdfea4 vmov r2, s11 */
/* @0xdfea8 orr r2, r2, r3 */
/* @0xdfeac vmov s15, r2 */
/* @0xdfeb0 vcvt.f64.s32 d7, s15 */
/* @0xdfeb4 vmov r2, r3, d7 */
/* @0xdfeb8 vstr s14, [r6, #-16] */
/* @0xdfebc str r3, [r6, #-0xc] */
/* @0xdfec0 beq 0xe0060 <_Z4DoOrjPhPKhP6VMExec+0x85c> */
/* @0xdfec4 ldr r1, [sp, #0x3c] */
/* @0xdfec8 mov r3, #0 */
/* @0xdfecc str r3, [sp, #0x28] */
/* @0xdfed0 mov r2, #5 */
/* @0xdfed4 sub r1, r1, #1 */
/* @0xdfed8 str r3, [sp, #0x20] */
/* @0xdfedc bic r3, r1, #-16777216 */
/* @0xdfee0 str r2, [sp, #0x2c] */
/* @0xdfee4 bic r3, r3, #3 */
/* @0xdfee8 cmp r3, #0 */
/* @0xdfeec movne r0, r4 */
/* @0xdfef0 bne 0xdf8e8 <_Z4DoOrjPhPKhP6VMExec+0xe4> */
/* @0xdfef4 mov r0, r7 */
/* @0xdfef8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdfefc mov r0, r4 */
/* @0xdff00 b 0xdf8e8 <_Z4DoOrjPhPKhP6VMExec+0xe4> */
/* @0xdff04 ldr r3, [r9] */
/* @0xdff08 adds r3, r3, #0 */
/* @0xdff0c movne r3, #1 */
/* @0xdff10 b 0xdfce0 <_Z4DoOrjPhPKhP6VMExec+0x4dc> */
/* @0xdff14 and r5, r5, #15 */
/* @0xdff18 orr r5, r5, #48 */
/* @0xdff1c add r6, r10, #16 */
/* @0xdff20 b 0xdf938 <_Z4DoOrjPhPKhP6VMExec+0x134> */
/* @0xdff24 and r5, r5, #15 */
/* @0xdff28 orr r5, r5, #32 */
/* @0xdff2c b 0xdff1c <_Z4DoOrjPhPKhP6VMExec+0x718> */
/* @0xdff30 ldr r1, [pc, #0x16c] */
/* @0xdff34 mov r0, r11 */
/* @0xdff38 add r1, pc, r1 */
/* @0xdff3c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdff40 b 0xdff1c <_Z4DoOrjPhPKhP6VMExec+0x718> */
/* @0xdff44 ldr r1, [pc, #0x15c] */
/* @0xdff48 mov r0, r11 */
/* @0xdff4c add r1, pc, r1 */
/* @0xdff50 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdff54 b 0xdff1c <_Z4DoOrjPhPKhP6VMExec+0x718> */
/* @0xdff58 ldr r1, [pc, #0x14c] */
/* @0xdff5c mov r0, r11 */
/* @0xdff60 add r1, pc, r1 */
/* @0xdff64 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdff68 b 0xdff1c <_Z4DoOrjPhPKhP6VMExec+0x718> */
/* @0xdff6c ldr r1, [pc, #0x13c] */
/* @0xdff70 mov r0, r11 */
/* @0xdff74 add r1, pc, r1 */
/* @0xdff78 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdff7c b 0xdff1c <_Z4DoOrjPhPKhP6VMExec+0x718> */
/* @0xdff80 and r5, r5, #15 */
/* @0xdff84 b 0xdff1c <_Z4DoOrjPhPKhP6VMExec+0x718> */
/* @0xdff88 and r5, r5, #240 */
/* @0xdff8c orr r5, r5, #3 */
/* @0xdff90 add r10, r9, #16 */
/* @0xdff94 b 0xdf8f8 <_Z4DoOrjPhPKhP6VMExec+0xf4> */
/* @0xdff98 and r5, r5, #240 */
/* @0xdff9c orr r5, r5, #2 */
/* @0xdffa0 b 0xdff90 <_Z4DoOrjPhPKhP6VMExec+0x78c> */
/* @0xdffa4 ldr r1, [pc, #0x108] */
/* @0xdffa8 mov r0, r11 */
/* @0xdffac mov r5, r4 */
/* @0xdffb0 add r1, pc, r1 */
/* @0xdffb4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdffb8 b 0xdff90 <_Z4DoOrjPhPKhP6VMExec+0x78c> */
/* @0xdffbc ldr r1, [pc, #0xf4] */
/* @0xdffc0 mov r0, r11 */
/* @0xdffc4 mov r5, r4 */
/* @0xdffc8 add r1, pc, r1 */
/* @0xdffcc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdffd0 b 0xdff90 <_Z4DoOrjPhPKhP6VMExec+0x78c> */
/* @0xdffd4 ldr r1, [pc, #0xe0] */
/* @0xdffd8 mov r0, r11 */
/* @0xdffdc mov r5, r4 */
/* @0xdffe0 add r1, pc, r1 */
/* @0xdffe4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdffe8 b 0xdff90 <_Z4DoOrjPhPKhP6VMExec+0x78c> */
/* @0xdffec ldr r1, [pc, #0xcc] */
/* @0xdfff0 mov r0, r11 */
/* @0xdfff4 mov r5, r4 */
/* @0xdfff8 add r1, pc, r1 */
/* @0xdfffc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0000 b 0xdff90 <_Z4DoOrjPhPKhP6VMExec+0x78c> */
/* @0xe0004 and r5, r4, #240 */
/* @0xe0008 b 0xdff90 <_Z4DoOrjPhPKhP6VMExec+0x78c> */
/* @0xe000c ldr r1, [pc, #0xb0] */
/* @0xe0010 mov r0, r11 */
/* @0xe0014 add r1, pc, r1 */
/* @0xe0018 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe001c b 0xdff1c <_Z4DoOrjPhPKhP6VMExec+0x718> */
/* @0xe0020 ldr r1, [pc, #0xa0] */
/* @0xe0024 mov r0, r11 */
/* @0xe0028 mov r5, r4 */
/* @0xe002c add r1, pc, r1 */
/* @0xe0030 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0034 b 0xdff90 <_Z4DoOrjPhPKhP6VMExec+0x78c> */
/* @0xe0038 ldr r0, [pc, #0x8c] */
/* @0xe003c add r0, pc, r0 */
/* @0xe0040 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe0044 mov r0, r6 */
/* @0xe0048 b 0xdf8e8 <_Z4DoOrjPhPKhP6VMExec+0xe4> */
/* @0xe004c ldr r0, [pc, #0x7c] */
/* @0xe0050 add r0, pc, r0 */
/* @0xe0054 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe0058 mov r0, r6 */
/* @0xe005c b 0xdf8e8 <_Z4DoOrjPhPKhP6VMExec+0xe4> */
/* @0xe0060 mov r0, r5 */
/* @0xe0064 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe0068 b 0xdfec4 <_Z4DoOrjPhPKhP6VMExec+0x6c0> */
/* @0xe006c ldr r0, [pc, #0x60] */
/* @0xe0070 add r0, pc, r0 */
/* @0xe0074 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe0078 mov r0, r6 */
/* @0xe007c b 0xdf8e8 <_Z4DoOrjPhPKhP6VMExec+0xe4> */
/* @0xe0080 mov r5, r4 */
/* @0xe0084 mov r10, r1 */
/* @0xe0088 b 0xdf8f8 <_Z4DoOrjPhPKhP6VMExec+0xf4> */
/* @0xe008c mov r6, r10 */
/* @0xe0090 b 0xdf938 <_Z4DoOrjPhPKhP6VMExec+0x134> */
/* @0xe0094 eoreq r4, r5, r12, lsr r1 */
/* @0xe0098 .word 0x00253cdc */
/* @0xe009c eoreq r3, r5, r12, lsr r12 */
/* @0xe00a0 .word 0x00253cd8 */
/* @0xe00a4 mlaeq r5, r0, r11, r3 */
/* @0xe00a8 eoreq r3, r5, r12, asr r11 */
/* @0xe00ac eoreq r3, r5, r4, lsl #23 */
/* @0xe00b0 .word 0x00253af8 */
/* @0xe00b4 eoreq r3, r5, r12, lsr #20 */
/* @0xe00b8 .word 0x002539f4 */
/* @0xe00bc eoreq r3, r5, r4, asr r10 */
/* @0xe00c0 eoreq r3, r5, r0, lsl #20 */
/* @0xe00c4 eoreq r3, r5, r12, ror #21 */
/* @0xe00c8 eoreq r3, r5, r4, lsr #20 */
/* @0xe00cc mlaeq r5, r12, r8, r3 */
/* @0xe00d0 .word 0x002538d0 */
/* @0xe00d4 eoreq r3, r5, r0, ror #17 */

/* ── FUNC 0xe00d8 · DoXor(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=2196 · insn=549 */
/* @0xe00d8 tst r0, #3840 */
/* @0xe00dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe00e0 lsr r5, r0, #16 */
/* @0xe00e4 sub sp, sp, #68 */
/* @0xe00e8 mov r9, r1 */
/* @0xe00ec mov r11, r3 */
/* @0xe00f0 bne 0xe0124 <_Z5DoXorjPhPKhP6VMExec+0x4c> */
/* @0xe00f4 uxtb r4, r5 */
/* @0xe00f8 and r2, r4, #15 */
/* @0xe00fc cmp r2, #6 */
/* @0xe0100 addls pc, pc, r2, lsl #2 */
/* @0xe0104 b 0xe0914 <_Z5DoXorjPhPKhP6VMExec+0x83c> */
/* @0xe0108 b 0xe01c4 <_Z5DoXorjPhPKhP6VMExec+0xec> */
/* @0xe010c b 0xe0514 <_Z5DoXorjPhPKhP6VMExec+0x43c> */
/* @0xe0110 b 0xe0514 <_Z5DoXorjPhPKhP6VMExec+0x43c> */
/* @0xe0114 b 0xe01c4 <_Z5DoXorjPhPKhP6VMExec+0xec> */
/* @0xe0118 b 0xe0514 <_Z5DoXorjPhPKhP6VMExec+0x43c> */
/* @0xe011c b 0xe0520 <_Z5DoXorjPhPKhP6VMExec+0x448> */
/* @0xe0120 b 0xe0568 <_Z5DoXorjPhPKhP6VMExec+0x490> */
/* @0xe0124 add r4, sp, #16 */
/* @0xe0128 uxtb r5, r5 */
/* @0xe012c mov r2, r1 */
/* @0xe0130 and r1, r5, #15 */
/* @0xe0134 mov r0, r4 */
/* @0xe0138 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe013c lsr r1, r5, #4 */
/* @0xe0140 mov r2, r0 */
/* @0xe0144 mov r0, sp */
/* @0xe0148 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe014c ldr r3, [sp, #0xc] */
/* @0xe0150 mvn r12, #-16777216 */
/* @0xe0154 and r3, r3, r12 */
/* @0xe0158 cmp r3, r12 */
/* @0xe015c mov r6, r0 */
/* @0xe0160 beq 0xe08cc <_Z5DoXorjPhPKhP6VMExec+0x7f4> */
/* @0xe0164 ldr r3, [sp, #0x1c] */
/* @0xe0168 bic r3, r3, #-16777216 */
/* @0xe016c cmp r3, r12 */
/* @0xe0170 beq 0xe0590 <_Z5DoXorjPhPKhP6VMExec+0x4b8> */
/* @0xe0174 add r5, sp, #32 */
/* @0xe0178 mov r1, sp */
/* @0xe017c mov r2, #0 */
/* @0xe0180 mov r3, #0 */
/* @0xe0184 mov r0, r5 */
/* @0xe0188 str r12, [sp, #0x2c] */
/* @0xe018c str r12, [sp, #0x3c] */
/* @0xe0190 mov r12, #0 */
/* @0xe0194 strd r2, r3, [sp, #32] */
/* @0xe0198 strd r2, r3, [sp, #48] */
/* @0xe019c str r12, [sp, #0x28] */
/* @0xe01a0 str r12, [sp, #0x38] */
/* @0xe01a4 bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0xe01a8 cmp r0, #1 */
/* @0xe01ac beq 0xe08e0 <_Z5DoXorjPhPKhP6VMExec+0x808> */
/* @0xe01b0 cmp r0, #0 */
/* @0xe01b4 beq 0xe06f8 <_Z5DoXorjPhPKhP6VMExec+0x620> */
/* @0xe01b8 mov r0, r6 */
/* @0xe01bc add sp, sp, #68 */
/* @0xe01c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe01c4 add r10, r1, #8 */
/* @0xe01c8 mov r5, r4 */
/* @0xe01cc asr r2, r5, #4 */
/* @0xe01d0 cmp r2, #6 */
/* @0xe01d4 addls pc, pc, r2, lsl #2 */
/* @0xe01d8 b 0xe0920 <_Z5DoXorjPhPKhP6VMExec+0x848> */
/* @0xe01dc b 0xe050c <_Z5DoXorjPhPKhP6VMExec+0x434> */
/* @0xe01e0 b 0xe0504 <_Z5DoXorjPhPKhP6VMExec+0x42c> */
/* @0xe01e4 b 0xe0504 <_Z5DoXorjPhPKhP6VMExec+0x42c> */
/* @0xe01e8 b 0xe050c <_Z5DoXorjPhPKhP6VMExec+0x434> */
/* @0xe01ec b 0xe0504 <_Z5DoXorjPhPKhP6VMExec+0x42c> */
/* @0xe01f0 b 0xe04bc <_Z5DoXorjPhPKhP6VMExec+0x3e4> */
/* @0xe01f4 b 0xe01f8 <_Z5DoXorjPhPKhP6VMExec+0x120> */
/* @0xe01f8 ldr r1, [pc, #0x728] */
/* @0xe01fc mov r0, r11 */
/* @0xe0200 mov r6, r10 */
/* @0xe0204 add r1, pc, r1 */
/* @0xe0208 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe020c cmp r4, #85 */
/* @0xe0210 addls pc, pc, r4, lsl #2 */
/* @0xe0214 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0218 b 0xe04ac <_Z5DoXorjPhPKhP6VMExec+0x3d4> */
/* @0xe021c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0220 b 0xe04ac <_Z5DoXorjPhPKhP6VMExec+0x3d4> */
/* @0xe0224 b 0xe04ac <_Z5DoXorjPhPKhP6VMExec+0x3d4> */
/* @0xe0228 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe022c b 0xe049c <_Z5DoXorjPhPKhP6VMExec+0x3c4> */
/* @0xe0230 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0234 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0238 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe023c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0240 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0244 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0248 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe024c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0250 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0254 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0258 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe025c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0260 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0264 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0268 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe026c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0270 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0274 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0278 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe027c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0280 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0284 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0288 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe028c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0290 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0294 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0298 b 0xe04ac <_Z5DoXorjPhPKhP6VMExec+0x3d4> */
/* @0xe029c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02a0 b 0xe0370 <_Z5DoXorjPhPKhP6VMExec+0x298> */
/* @0xe02a4 b 0xe04ac <_Z5DoXorjPhPKhP6VMExec+0x3d4> */
/* @0xe02a8 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02ac b 0xe049c <_Z5DoXorjPhPKhP6VMExec+0x3c4> */
/* @0xe02b0 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02b4 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02b8 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02bc b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02c0 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02c4 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02c8 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02cc b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02d0 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02d4 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02d8 b 0xe04ac <_Z5DoXorjPhPKhP6VMExec+0x3d4> */
/* @0xe02dc b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02e0 b 0xe04ac <_Z5DoXorjPhPKhP6VMExec+0x3d4> */
/* @0xe02e4 b 0xe04ac <_Z5DoXorjPhPKhP6VMExec+0x3d4> */
/* @0xe02e8 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02ec b 0xe049c <_Z5DoXorjPhPKhP6VMExec+0x3c4> */
/* @0xe02f0 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02f4 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02f8 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02fc b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0300 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0304 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0308 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe030c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0310 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0314 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0318 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe031c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0320 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0324 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0328 b 0xe0370 <_Z5DoXorjPhPKhP6VMExec+0x298> */
/* @0xe032c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0330 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0334 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0338 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe033c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0340 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0344 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0348 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe034c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0350 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0354 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0358 b 0xe049c <_Z5DoXorjPhPKhP6VMExec+0x3c4> */
/* @0xe035c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0360 b 0xe049c <_Z5DoXorjPhPKhP6VMExec+0x3c4> */
/* @0xe0364 b 0xe049c <_Z5DoXorjPhPKhP6VMExec+0x3c4> */
/* @0xe0368 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe036c b 0xe049c <_Z5DoXorjPhPKhP6VMExec+0x3c4> */
/* @0xe0370 sub r6, r6, #4 */
/* @0xe0374 mov r7, #0 */
/* @0xe0378 mov r8, r6 */
/* @0xe037c cmp r5, #68 */
/* @0xe0380 addls pc, pc, r5, lsl #2 */
/* @0xe0384 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0388 b 0xe0638 <_Z5DoXorjPhPKhP6VMExec+0x560> */
/* @0xe038c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0390 b 0xe0614 <_Z5DoXorjPhPKhP6VMExec+0x53c> */
/* @0xe0394 b 0xe05f0 <_Z5DoXorjPhPKhP6VMExec+0x518> */
/* @0xe0398 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe039c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03a0 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03a4 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03a8 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03ac b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03b0 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03b4 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03b8 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03bc b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03c0 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03c4 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03c8 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03cc b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03d0 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03d4 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03d8 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03dc b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03e0 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03e4 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03e8 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03ec b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03f0 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03f4 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03f8 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03fc b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0400 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0404 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0408 b 0xe06d0 <_Z5DoXorjPhPKhP6VMExec+0x5f8> */
/* @0xe040c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0410 b 0xe06b8 <_Z5DoXorjPhPKhP6VMExec+0x5e0> */
/* @0xe0414 b 0xe069c <_Z5DoXorjPhPKhP6VMExec+0x5c4> */
/* @0xe0418 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe041c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0420 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0424 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0428 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe042c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0430 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0434 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0438 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe043c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0440 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0444 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0448 b 0xe068c <_Z5DoXorjPhPKhP6VMExec+0x5b4> */
/* @0xe044c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0450 b 0xe05d4 <_Z5DoXorjPhPKhP6VMExec+0x4fc> */
/* @0xe0454 b 0xe05a4 <_Z5DoXorjPhPKhP6VMExec+0x4cc> */
/* @0xe0458 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe045c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0460 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0464 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0468 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe046c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0470 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0474 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0478 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe047c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0480 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0484 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0488 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe048c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0490 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0494 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0498 b 0xe0668 <_Z5DoXorjPhPKhP6VMExec+0x590> */
/* @0xe049c sub r7, r6, #16 */
/* @0xe04a0 mov r8, r7 */
/* @0xe04a4 mov r6, r7 */
/* @0xe04a8 b 0xe037c <_Z5DoXorjPhPKhP6VMExec+0x2a4> */
/* @0xe04ac sub r6, r6, #8 */
/* @0xe04b0 mov r7, #0 */
/* @0xe04b4 mov r8, r6 */
/* @0xe04b8 b 0xe037c <_Z5DoXorjPhPKhP6VMExec+0x2a4> */
/* @0xe04bc ldr r3, [r10, #0xc] */
/* @0xe04c0 cmp r3, #13 */
/* @0xe04c4 addls pc, pc, r3, lsl #2 */
/* @0xe04c8 b 0xe08a0 <_Z5DoXorjPhPKhP6VMExec+0x7c8> */
/* @0xe04cc b 0xe07e0 <_Z5DoXorjPhPKhP6VMExec+0x708> */
/* @0xe04d0 b 0xe07cc <_Z5DoXorjPhPKhP6VMExec+0x6f4> */
/* @0xe04d4 b 0xe07b8 <_Z5DoXorjPhPKhP6VMExec+0x6e0> */
/* @0xe04d8 b 0xe07fc <_Z5DoXorjPhPKhP6VMExec+0x724> */
/* @0xe04dc b 0xe08a0 <_Z5DoXorjPhPKhP6VMExec+0x7c8> */
/* @0xe04e0 b 0xe07e8 <_Z5DoXorjPhPKhP6VMExec+0x710> */
/* @0xe04e4 b 0xe08a0 <_Z5DoXorjPhPKhP6VMExec+0x7c8> */
/* @0xe04e8 b 0xe0810 <_Z5DoXorjPhPKhP6VMExec+0x738> */
/* @0xe04ec b 0xe08a0 <_Z5DoXorjPhPKhP6VMExec+0x7c8> */
/* @0xe04f0 b 0xe08a0 <_Z5DoXorjPhPKhP6VMExec+0x7c8> */
/* @0xe04f4 b 0xe07a8 <_Z5DoXorjPhPKhP6VMExec+0x6d0> */
/* @0xe04f8 b 0xe08a0 <_Z5DoXorjPhPKhP6VMExec+0x7c8> */
/* @0xe04fc b 0xe08a0 <_Z5DoXorjPhPKhP6VMExec+0x7c8> */
/* @0xe0500 b 0xe07e0 <_Z5DoXorjPhPKhP6VMExec+0x708> */
/* @0xe0504 add r6, r10, #4 */
/* @0xe0508 b 0xe020c <_Z5DoXorjPhPKhP6VMExec+0x134> */
/* @0xe050c add r6, r10, #8 */
/* @0xe0510 b 0xe020c <_Z5DoXorjPhPKhP6VMExec+0x134> */
/* @0xe0514 add r10, r1, #4 */
/* @0xe0518 mov r5, r4 */
/* @0xe051c b 0xe01cc <_Z5DoXorjPhPKhP6VMExec+0xf4> */
/* @0xe0520 ldr r3, [r1, #0xc] */
/* @0xe0524 cmp r3, #13 */
/* @0xe0528 addls pc, pc, r3, lsl #2 */
/* @0xe052c b 0xe08b4 <_Z5DoXorjPhPKhP6VMExec+0x7dc> */
/* @0xe0530 b 0xe0850 <_Z5DoXorjPhPKhP6VMExec+0x778> */
/* @0xe0534 b 0xe0838 <_Z5DoXorjPhPKhP6VMExec+0x760> */
/* @0xe0538 b 0xe081c <_Z5DoXorjPhPKhP6VMExec+0x744> */
/* @0xe053c b 0xe0888 <_Z5DoXorjPhPKhP6VMExec+0x7b0> */
/* @0xe0540 b 0xe08b4 <_Z5DoXorjPhPKhP6VMExec+0x7dc> */
/* @0xe0544 b 0xe0870 <_Z5DoXorjPhPKhP6VMExec+0x798> */
/* @0xe0548 b 0xe08b4 <_Z5DoXorjPhPKhP6VMExec+0x7dc> */
/* @0xe054c b 0xe0864 <_Z5DoXorjPhPKhP6VMExec+0x78c> */
/* @0xe0550 b 0xe08b4 <_Z5DoXorjPhPKhP6VMExec+0x7dc> */
/* @0xe0554 b 0xe08b4 <_Z5DoXorjPhPKhP6VMExec+0x7dc> */
/* @0xe0558 b 0xe0858 <_Z5DoXorjPhPKhP6VMExec+0x780> */
/* @0xe055c b 0xe08b4 <_Z5DoXorjPhPKhP6VMExec+0x7dc> */
/* @0xe0560 b 0xe08b4 <_Z5DoXorjPhPKhP6VMExec+0x7dc> */
/* @0xe0564 b 0xe0850 <_Z5DoXorjPhPKhP6VMExec+0x778> */
/* @0xe0568 ldr r1, [pc, #0x3bc] */
/* @0xe056c mov r0, r3 */
/* @0xe0570 mov r5, r4 */
/* @0xe0574 mov r10, r9 */
/* @0xe0578 add r1, pc, r1 */
/* @0xe057c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0580 b 0xe01cc <_Z5DoXorjPhPKhP6VMExec+0xf4> */
/* @0xe0584 mov r8, #0 */
/* @0xe0588 mov r7, r8 */
/* @0xe058c b 0xe037c <_Z5DoXorjPhPKhP6VMExec+0x2a4> */
/* @0xe0590 ldr r0, [pc, #0x398] */
/* @0xe0594 add r0, pc, r0 */
/* @0xe0598 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe059c mov r0, r6 */
/* @0xe05a0 b 0xe01bc <_Z5DoXorjPhPKhP6VMExec+0xe4> */
/* @0xe05a4 ldrd r0, r1, [r10] */
/* @0xe05a8 mov r12, #10 */
/* @0xe05ac ldrd r2, r3, [r9] */
/* @0xe05b0 eor r2, r2, r0 */
/* @0xe05b4 eor r3, r3, r1 */
/* @0xe05b8 strd r2, r3, [r8] */
/* @0xe05bc cmp r7, #0 */
/* @0xe05c0 beq 0xe01b8 <_Z5DoXorjPhPKhP6VMExec+0xe0> */
/* @0xe05c4 mov r0, r6 */
/* @0xe05c8 str r12, [r7, #0xc] */
/* @0xe05cc add sp, sp, #68 */
/* @0xe05d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe05d4 ldr r1, [r9] */
/* @0xe05d8 mov r12, #10 */
/* @0xe05dc ldrd r2, r3, [r10] */
/* @0xe05e0 eor r2, r2, r1 */
/* @0xe05e4 eor r3, r3, r1, asr #31 */
/* @0xe05e8 strd r2, r3, [r8] */
/* @0xe05ec b 0xe05bc <_Z5DoXorjPhPKhP6VMExec+0x4e4> */
/* @0xe05f0 ldrd r0, r1, [r10] */
/* @0xe05f4 bl 0x3194a0 <__fixdfdi> */
/* @0xe05f8 ldrd r2, r3, [r9] */
/* @0xe05fc eor r0, r0, r2 */
/* @0xe0600 eor r1, r1, r3 */
/* @0xe0604 bl 0x319164 <__floatdidf> */
/* @0xe0608 mov r12, #0 */
/* @0xe060c strd r0, r1, [r8] */
/* @0xe0610 b 0xe05bc <_Z5DoXorjPhPKhP6VMExec+0x4e4> */
/* @0xe0614 ldrd r0, r1, [r10] */
/* @0xe0618 bl 0x3194a0 <__fixdfdi> */
/* @0xe061c ldr r3, [r9] */
/* @0xe0620 eor r0, r0, r3 */
/* @0xe0624 eor r1, r1, r3, asr #31 */
/* @0xe0628 bl 0x319164 <__floatdidf> */
/* @0xe062c mov r12, #0 */
/* @0xe0630 strd r0, r1, [r8] */
/* @0xe0634 b 0xe05bc <_Z5DoXorjPhPKhP6VMExec+0x4e4> */
/* @0xe0638 ldrd r0, r1, [r10] */
/* @0xe063c bl 0x3194a0 <__fixdfdi> */
/* @0xe0640 mov r4, r0 */
/* @0xe0644 mov r5, r1 */
/* @0xe0648 ldrd r0, r1, [r9] */
/* @0xe064c bl 0x3194a0 <__fixdfdi> */
/* @0xe0650 eor r0, r0, r4 */
/* @0xe0654 eor r1, r1, r5 */
/* @0xe0658 bl 0x319164 <__floatdidf> */
/* @0xe065c mov r12, #0 */
/* @0xe0660 strd r0, r1, [r8] */
/* @0xe0664 b 0xe05bc <_Z5DoXorjPhPKhP6VMExec+0x4e4> */
/* @0xe0668 ldr r3, [r10] */
/* @0xe066c mov r12, #13 */
/* @0xe0670 ldr r2, [r9] */
/* @0xe0674 adds r3, r3, #0 */
/* @0xe0678 movne r3, #1 */
/* @0xe067c cmp r2, #0 */
/* @0xe0680 eorne r3, r3, #1 */
/* @0xe0684 str r3, [r8] */
/* @0xe0688 b 0xe05bc <_Z5DoXorjPhPKhP6VMExec+0x4e4> */
/* @0xe068c ldrd r0, r1, [r9] */
/* @0xe0690 bl 0x3194a0 <__fixdfdi> */
/* @0xe0694 ldrd r2, r3, [r10] */
/* @0xe0698 b 0xe05fc <_Z5DoXorjPhPKhP6VMExec+0x524> */
/* @0xe069c ldr r1, [r10] */
/* @0xe06a0 mov r12, #10 */
/* @0xe06a4 ldrd r2, r3, [r9] */
/* @0xe06a8 eor r2, r2, r1 */
/* @0xe06ac eor r3, r3, r1, asr #31 */
/* @0xe06b0 strd r2, r3, [r8] */
/* @0xe06b4 b 0xe05bc <_Z5DoXorjPhPKhP6VMExec+0x4e4> */
/* @0xe06b8 ldr r2, [r10] */
/* @0xe06bc mov r12, #7 */
/* @0xe06c0 ldr r3, [r9] */
/* @0xe06c4 eor r3, r2, r3 */
/* @0xe06c8 str r3, [r8] */
/* @0xe06cc b 0xe05bc <_Z5DoXorjPhPKhP6VMExec+0x4e4> */
/* @0xe06d0 ldr r4, [r10] */
/* @0xe06d4 ldrd r0, r1, [r9] */
/* @0xe06d8 asr r5, r4, #31 */
/* @0xe06dc b 0xe064c <_Z5DoXorjPhPKhP6VMExec+0x574> */
/* @0xe06e0 ldr r1, [pc, #0x24c] */
/* @0xe06e4 mov r0, r11 */
/* @0xe06e8 add r1, pc, r1 */
/* @0xe06ec bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe06f0 mov r12, #0 */
/* @0xe06f4 b 0xe05bc <_Z5DoXorjPhPKhP6VMExec+0x4e4> */
/* @0xe06f8 add r7, sp, #48 */
/* @0xe06fc mov r1, r4 */
/* @0xe0700 mov r0, r7 */
/* @0xe0704 bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0xe0708 cmp r0, #1 */
/* @0xe070c beq 0xe0900 <_Z5DoXorjPhPKhP6VMExec+0x828> */
/* @0xe0710 cmp r0, #0 */
/* @0xe0714 bne 0xe01b8 <_Z5DoXorjPhPKhP6VMExec+0xe0> */
/* @0xe0718 str r0, [r6, #-0x4] */
/* @0xe071c sub r4, r6, #16 */
/* @0xe0720 vldr d7, [sp, #32] */
/* @0xe0724 vldr d6, [sp, #48] */
/* @0xe0728 vcvt.s32.f64 s14, d7 */
/* @0xe072c ldr r3, [sp, #0x2c] */
/* @0xe0730 sub r3, r3, #1 */
/* @0xe0734 bic r3, r3, #-16777216 */
/* @0xe0738 bic r3, r3, #3 */
/* @0xe073c cmp r3, #0 */
/* @0xe0740 vcvt.s32.f64 s11, d6 */
/* @0xe0744 vmov r3, s14 */
/* @0xe0748 vmov r2, s11 */
/* @0xe074c eor r2, r2, r3 */
/* @0xe0750 vmov s15, r2 */
/* @0xe0754 vcvt.f64.s32 d7, s15 */
/* @0xe0758 vmov r2, r3, d7 */
/* @0xe075c vstr s14, [r6, #-16] */
/* @0xe0760 str r3, [r6, #-0xc] */
/* @0xe0764 beq 0xe08f4 <_Z5DoXorjPhPKhP6VMExec+0x81c> */
/* @0xe0768 ldr r1, [sp, #0x3c] */
/* @0xe076c mov r3, #0 */
/* @0xe0770 str r3, [sp, #0x28] */
/* @0xe0774 mov r2, #5 */
/* @0xe0778 sub r1, r1, #1 */
/* @0xe077c str r3, [sp, #0x20] */
/* @0xe0780 bic r3, r1, #-16777216 */
/* @0xe0784 str r2, [sp, #0x2c] */
/* @0xe0788 bic r3, r3, #3 */
/* @0xe078c cmp r3, #0 */
/* @0xe0790 movne r0, r4 */
/* @0xe0794 bne 0xe01bc <_Z5DoXorjPhPKhP6VMExec+0xe4> */
/* @0xe0798 mov r0, r7 */
/* @0xe079c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe07a0 mov r0, r4 */
/* @0xe07a4 b 0xe01bc <_Z5DoXorjPhPKhP6VMExec+0xe4> */
/* @0xe07a8 and r5, r5, #15 */
/* @0xe07ac orr r5, r5, #48 */
/* @0xe07b0 add r6, r10, #16 */
/* @0xe07b4 b 0xe020c <_Z5DoXorjPhPKhP6VMExec+0x134> */
/* @0xe07b8 ldr r1, [pc, #0x178] */
/* @0xe07bc mov r0, r11 */
/* @0xe07c0 add r1, pc, r1 */
/* @0xe07c4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe07c8 b 0xe07b0 <_Z5DoXorjPhPKhP6VMExec+0x6d8> */
/* @0xe07cc ldr r1, [pc, #0x168] */
/* @0xe07d0 mov r0, r11 */
/* @0xe07d4 add r1, pc, r1 */
/* @0xe07d8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe07dc b 0xe07b0 <_Z5DoXorjPhPKhP6VMExec+0x6d8> */
/* @0xe07e0 and r5, r5, #15 */
/* @0xe07e4 b 0xe07b0 <_Z5DoXorjPhPKhP6VMExec+0x6d8> */
/* @0xe07e8 ldr r1, [pc, #0x150] */
/* @0xe07ec mov r0, r11 */
/* @0xe07f0 add r1, pc, r1 */
/* @0xe07f4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe07f8 b 0xe07b0 <_Z5DoXorjPhPKhP6VMExec+0x6d8> */
/* @0xe07fc ldr r1, [pc, #0x140] */
/* @0xe0800 mov r0, r11 */
/* @0xe0804 add r1, pc, r1 */
/* @0xe0808 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe080c b 0xe07b0 <_Z5DoXorjPhPKhP6VMExec+0x6d8> */
/* @0xe0810 and r5, r5, #15 */
/* @0xe0814 orr r5, r5, #32 */
/* @0xe0818 b 0xe07b0 <_Z5DoXorjPhPKhP6VMExec+0x6d8> */
/* @0xe081c ldr r1, [pc, #0x124] */
/* @0xe0820 mov r0, r11 */
/* @0xe0824 mov r5, r4 */
/* @0xe0828 add r1, pc, r1 */
/* @0xe082c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0830 add r10, r9, #16 */
/* @0xe0834 b 0xe01cc <_Z5DoXorjPhPKhP6VMExec+0xf4> */
/* @0xe0838 ldr r1, [pc, #0x10c] */
/* @0xe083c mov r0, r11 */
/* @0xe0840 mov r5, r4 */
/* @0xe0844 add r1, pc, r1 */
/* @0xe0848 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe084c b 0xe0830 <_Z5DoXorjPhPKhP6VMExec+0x758> */
/* @0xe0850 and r5, r4, #240 */
/* @0xe0854 b 0xe0830 <_Z5DoXorjPhPKhP6VMExec+0x758> */
/* @0xe0858 and r5, r5, #240 */
/* @0xe085c orr r5, r5, #3 */
/* @0xe0860 b 0xe0830 <_Z5DoXorjPhPKhP6VMExec+0x758> */
/* @0xe0864 and r5, r5, #240 */
/* @0xe0868 orr r5, r5, #2 */
/* @0xe086c b 0xe0830 <_Z5DoXorjPhPKhP6VMExec+0x758> */
/* @0xe0870 ldr r1, [pc, #0xd8] */
/* @0xe0874 mov r0, r11 */
/* @0xe0878 mov r5, r4 */
/* @0xe087c add r1, pc, r1 */
/* @0xe0880 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0884 b 0xe0830 <_Z5DoXorjPhPKhP6VMExec+0x758> */
/* @0xe0888 ldr r1, [pc, #0xc4] */
/* @0xe088c mov r0, r11 */
/* @0xe0890 mov r5, r4 */
/* @0xe0894 add r1, pc, r1 */
/* @0xe0898 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe089c b 0xe0830 <_Z5DoXorjPhPKhP6VMExec+0x758> */
/* @0xe08a0 ldr r1, [pc, #0xb0] */
/* @0xe08a4 mov r0, r11 */
/* @0xe08a8 add r1, pc, r1 */
/* @0xe08ac bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe08b0 b 0xe07b0 <_Z5DoXorjPhPKhP6VMExec+0x6d8> */
/* @0xe08b4 ldr r1, [pc, #0xa0] */
/* @0xe08b8 mov r0, r11 */
/* @0xe08bc mov r5, r4 */
/* @0xe08c0 add r1, pc, r1 */
/* @0xe08c4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe08c8 b 0xe0830 <_Z5DoXorjPhPKhP6VMExec+0x758> */
/* @0xe08cc ldr r0, [pc, #0x8c] */
/* @0xe08d0 add r0, pc, r0 */
/* @0xe08d4 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe08d8 mov r0, r6 */
/* @0xe08dc b 0xe01bc <_Z5DoXorjPhPKhP6VMExec+0xe4> */
/* @0xe08e0 ldr r0, [pc, #0x7c] */
/* @0xe08e4 add r0, pc, r0 */
/* @0xe08e8 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe08ec mov r0, r6 */
/* @0xe08f0 b 0xe01bc <_Z5DoXorjPhPKhP6VMExec+0xe4> */
/* @0xe08f4 mov r0, r5 */
/* @0xe08f8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe08fc b 0xe0768 <_Z5DoXorjPhPKhP6VMExec+0x690> */
/* @0xe0900 ldr r0, [pc, #0x60] */
/* @0xe0904 add r0, pc, r0 */
/* @0xe0908 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe090c mov r0, r6 */
/* @0xe0910 b 0xe01bc <_Z5DoXorjPhPKhP6VMExec+0xe4> */
/* @0xe0914 mov r5, r4 */
/* @0xe0918 mov r10, r1 */
/* @0xe091c b 0xe01cc <_Z5DoXorjPhPKhP6VMExec+0xf4> */
/* @0xe0920 mov r6, r10 */
/* @0xe0924 b 0xe020c <_Z5DoXorjPhPKhP6VMExec+0x134> */
/* @0xe0928 eoreq r3, r5, r12, lsl #21 */
/* @0xe092c eoreq r3, r5, r4, ror #12 */
/* @0xe0930 eoreq r3, r5, r4, asr #11 */
/* @0xe0934 eoreq r3, r5, r12, asr r6 */
/* @0xe0938 eoreq r3, r5, r8, asr #10 */
/* @0xe093c .word 0x002534bc */
/* @0xe0940 .word 0x002534fc */
/* @0xe0944 eoreq r3, r5, r8, asr #9 */
/* @0xe0948 eoreq r3, r5, r12, lsr #8 */
/* @0xe094c mlaeq r5, r8, r3, r3 */
/* @0xe0950 .word 0x002533bc */
/* @0xe0954 eoreq r3, r5, r4, lsl #7 */
/* @0xe0958 eoreq r3, r5, r12, ror r4 */
/* @0xe095c .word 0x002533b0 */
/* @0xe0960 eoreq r3, r5, r4, ror #4 */
/* @0xe0964 mlaeq r5, r8, r2, r3 */
/* @0xe0968 eoreq r3, r5, r8, lsr #5 */

/* ── FUNC 0xe096c · DoNeg(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=896 · insn=224 */
/* @0xe096c ubfx r2, r0, #0x8, #0x4 */
/* @0xe0970 cmp r2, #0 */
/* @0xe0974 push {r4, r5, r6, r7, lr} */
/* @0xe0978 mov r6, r1 */
/* @0xe097c sub sp, sp, #36 */
/* @0xe0980 lsr r1, r0, #16 */
/* @0xe0984 beq 0xe0998 <_Z5DoNegjPhPKhP6VMExec+0x2c> */
/* @0xe0988 cmp r2, #1 */
/* @0xe098c beq 0xe0a8c <_Z5DoNegjPhPKhP6VMExec+0x120> */
/* @0xe0990 cmp r2, #2 */
/* @0xe0994 beq 0xe0b1c <_Z5DoNegjPhPKhP6VMExec+0x1b0> */
/* @0xe0998 and r2, r1, #15 */
/* @0xe099c cmp r2, #6 */
/* @0xe09a0 addls pc, pc, r2, lsl #2 */
/* @0xe09a4 b 0xe0cbc <_Z5DoNegjPhPKhP6VMExec+0x350> */
/* @0xe09a8 b 0xe0a5c <_Z5DoNegjPhPKhP6VMExec+0xf0> */
/* @0xe09ac b 0xe0a74 <_Z5DoNegjPhPKhP6VMExec+0x108> */
/* @0xe09b0 b 0xe09c4 <_Z5DoNegjPhPKhP6VMExec+0x58> */
/* @0xe09b4 b 0xe09dc <_Z5DoNegjPhPKhP6VMExec+0x70> */
/* @0xe09b8 b 0xe09c4 <_Z5DoNegjPhPKhP6VMExec+0x58> */
/* @0xe09bc b 0xe09f8 <_Z5DoNegjPhPKhP6VMExec+0x8c> */
/* @0xe09c0 b 0xe0a40 <_Z5DoNegjPhPKhP6VMExec+0xd4> */
/* @0xe09c4 ldr r3, [r6] */
/* @0xe09c8 mov r0, r6 */
/* @0xe09cc rsb r3, r3, #0 */
/* @0xe09d0 str r3, [r6] */
/* @0xe09d4 add sp, sp, #36 */
/* @0xe09d8 pop {r4, r5, r6, r7, pc} */
/* @0xe09dc ldrd r4, r5, [r6] */
/* @0xe09e0 mov r0, r6 */
/* @0xe09e4 rsbs r4, r4, #0 */
/* @0xe09e8 rsc r5, r5, #0 */
/* @0xe09ec strd r4, r5, [r6] */
/* @0xe09f0 add sp, sp, #36 */
/* @0xe09f4 pop {r4, r5, r6, r7, pc} */
/* @0xe09f8 ldr r2, [r6, #0xc] */
/* @0xe09fc cmp r2, #13 */
/* @0xe0a00 addls pc, pc, r2, lsl #2 */
/* @0xe0a04 b 0xe0c5c <_Z5DoNegjPhPKhP6VMExec+0x2f0> */
/* @0xe0a08 b 0xe0c28 <_Z5DoNegjPhPKhP6VMExec+0x2bc> */
/* @0xe0a0c b 0xe0c10 <_Z5DoNegjPhPKhP6VMExec+0x2a4> */
/* @0xe0a10 b 0xe0bf8 <_Z5DoNegjPhPKhP6VMExec+0x28c> */
/* @0xe0a14 b 0xe0be0 <_Z5DoNegjPhPKhP6VMExec+0x274> */
/* @0xe0a18 b 0xe0c5c <_Z5DoNegjPhPKhP6VMExec+0x2f0> */
/* @0xe0a1c b 0xe0bc8 <_Z5DoNegjPhPKhP6VMExec+0x25c> */
/* @0xe0a20 b 0xe0c5c <_Z5DoNegjPhPKhP6VMExec+0x2f0> */
/* @0xe0a24 b 0xe09c4 <_Z5DoNegjPhPKhP6VMExec+0x58> */
/* @0xe0a28 b 0xe0c5c <_Z5DoNegjPhPKhP6VMExec+0x2f0> */
/* @0xe0a2c b 0xe0c5c <_Z5DoNegjPhPKhP6VMExec+0x2f0> */
/* @0xe0a30 b 0xe0bac <_Z5DoNegjPhPKhP6VMExec+0x240> */
/* @0xe0a34 b 0xe0c5c <_Z5DoNegjPhPKhP6VMExec+0x2f0> */
/* @0xe0a38 b 0xe0c5c <_Z5DoNegjPhPKhP6VMExec+0x2f0> */
/* @0xe0a3c b 0xe0c28 <_Z5DoNegjPhPKhP6VMExec+0x2bc> */
/* @0xe0a40 ldr r1, [pc, #0x27c] */
/* @0xe0a44 mov r0, r3 */
/* @0xe0a48 add r1, pc, r1 */
/* @0xe0a4c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0a50 mov r0, r6 */
/* @0xe0a54 add sp, sp, #36 */
/* @0xe0a58 pop {r4, r5, r6, r7, pc} */
/* @0xe0a5c vldr d7, [r6] */
/* @0xe0a60 vneg.f64 d7, d7 */
/* @0xe0a64 mov r0, r6 */
/* @0xe0a68 vstr d7, [r6] */
/* @0xe0a6c add sp, sp, #36 */
/* @0xe0a70 pop {r4, r5, r6, r7, pc} */
/* @0xe0a74 vldr s15, [r6] */
/* @0xe0a78 vneg.f32 s15, s15 */
/* @0xe0a7c mov r0, r6 */
/* @0xe0a80 vstr s15, [r6] */
/* @0xe0a84 add sp, sp, #36 */
/* @0xe0a88 pop {r4, r5, r6, r7, pc} */
/* @0xe0a8c mov r2, r6 */
/* @0xe0a90 and r1, r1, #15 */
/* @0xe0a94 mov r0, sp */
/* @0xe0a98 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe0a9c ldr r2, [sp, #0xc] */
/* @0xe0aa0 mvn r3, #-16777216 */
/* @0xe0aa4 and r2, r2, r3 */
/* @0xe0aa8 cmp r2, r3 */
/* @0xe0aac mov r4, r0 */
/* @0xe0ab0 beq 0xe0b98 <_Z5DoNegjPhPKhP6VMExec+0x22c> */
/* @0xe0ab4 add r5, sp, #16 */
/* @0xe0ab8 mov r1, sp */
/* @0xe0abc str r3, [sp, #0x1c] */
/* @0xe0ac0 mov r2, #0 */
/* @0xe0ac4 mov r0, r5 */
/* @0xe0ac8 mov r3, #0 */
/* @0xe0acc strd r2, r3, [sp, #16] */
/* @0xe0ad0 mov r3, #0 */
/* @0xe0ad4 str r3, [sp, #0x18] */
/* @0xe0ad8 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xe0adc cmp r0, #1 */
/* @0xe0ae0 beq 0xe0cac <_Z5DoNegjPhPKhP6VMExec+0x340> */
/* @0xe0ae4 cmp r0, #0 */
/* @0xe0ae8 bne 0xe0c80 <_Z5DoNegjPhPKhP6VMExec+0x314> */
/* @0xe0aec str r0, [r4, #-0x4] */
/* @0xe0af0 sub r0, r4, #16 */
/* @0xe0af4 vldr d7, [sp, #16] */
/* @0xe0af8 vcmp.f64 d7, d7 */
/* @0xe0afc vmrs APSR_nzcv, fpscr */
/* @0xe0b00 vnegvc.f64 d6, d7 */
/* @0xe0b04 mvnvs r2, #0 */
/* @0xe0b08 mvnvs r3, #-2147483648 */
/* @0xe0b0c vmovvc r2, r3, d6 */
/* @0xe0b10 str r2, [r4, #-0x10] */
/* @0xe0b14 str r3, [r4, #-0xc] */
/* @0xe0b18 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0b1c mov r2, r6 */
/* @0xe0b20 and r1, r1, #15 */
/* @0xe0b24 mov r0, sp */
/* @0xe0b28 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe0b2c ldr r2, [sp, #0xc] */
/* @0xe0b30 mvn r3, #-16777216 */
/* @0xe0b34 and r2, r2, r3 */
/* @0xe0b38 cmp r2, r3 */
/* @0xe0b3c mov r4, r0 */
/* @0xe0b40 beq 0xe0c48 <_Z5DoNegjPhPKhP6VMExec+0x2dc> */
/* @0xe0b44 add r5, sp, #16 */
/* @0xe0b48 mov r1, sp */
/* @0xe0b4c str r3, [sp, #0x1c] */
/* @0xe0b50 mov r2, #0 */
/* @0xe0b54 mov r0, r5 */
/* @0xe0b58 mov r3, #0 */
/* @0xe0b5c strd r2, r3, [sp, #16] */
/* @0xe0b60 mov r3, #0 */
/* @0xe0b64 str r3, [sp, #0x18] */
/* @0xe0b68 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xe0b6c cmp r0, #1 */
/* @0xe0b70 beq 0xe0c74 <_Z5DoNegjPhPKhP6VMExec+0x308> */
/* @0xe0b74 cmp r0, #0 */
/* @0xe0b78 bne 0xe0c80 <_Z5DoNegjPhPKhP6VMExec+0x314> */
/* @0xe0b7c str r0, [r4, #-0x4] */
/* @0xe0b80 sub r0, r4, #16 */
/* @0xe0b84 ldr r2, [sp, #0x10] */
/* @0xe0b88 ldr r3, [sp, #0x14] */
/* @0xe0b8c str r2, [r4, #-0x10] */
/* @0xe0b90 str r3, [r4, #-0xc] */
/* @0xe0b94 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0b98 ldr r0, [pc, #0x128] */
/* @0xe0b9c add r0, pc, r0 */
/* @0xe0ba0 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe0ba4 mov r0, r4 */
/* @0xe0ba8 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0bac ldr r4, [r6] */
/* @0xe0bb0 mov r0, r6 */
/* @0xe0bb4 ldr r5, [r6, #0x4] */
/* @0xe0bb8 rsbs r4, r4, #0 */
/* @0xe0bbc rsc r5, r5, #0 */
/* @0xe0bc0 stm r6, {r4, r5} */
/* @0xe0bc4 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0bc8 ldr r1, [pc, #0xfc] */
/* @0xe0bcc mov r0, r3 */
/* @0xe0bd0 add r1, pc, r1 */
/* @0xe0bd4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0bd8 mov r0, r6 */
/* @0xe0bdc b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0be0 ldr r1, [pc, #0xe8] */
/* @0xe0be4 mov r0, r3 */
/* @0xe0be8 add r1, pc, r1 */
/* @0xe0bec bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0bf0 mov r0, r6 */
/* @0xe0bf4 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0bf8 ldr r1, [pc, #0xd4] */
/* @0xe0bfc mov r0, r3 */
/* @0xe0c00 add r1, pc, r1 */
/* @0xe0c04 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0c08 mov r0, r6 */
/* @0xe0c0c b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0c10 ldr r1, [pc, #0xc0] */
/* @0xe0c14 mov r0, r3 */
/* @0xe0c18 add r1, pc, r1 */
/* @0xe0c1c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0c20 mov r0, r6 */
/* @0xe0c24 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0c28 ldr r5, [r6, #0x4] */
/* @0xe0c2c mov r0, r6 */
/* @0xe0c30 ldr r4, [r6] */
/* @0xe0c34 eor r5, r5, #-2147483648 */
/* @0xe0c38 mov r2, r4 */
/* @0xe0c3c mov r3, r5 */
/* @0xe0c40 stm r6, {r2, r3} */
/* @0xe0c44 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0c48 ldr r0, [pc, #0x8c] */
/* @0xe0c4c add r0, pc, r0 */
/* @0xe0c50 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe0c54 mov r0, r4 */
/* @0xe0c58 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0c5c ldr r1, [pc, #0x7c] */
/* @0xe0c60 mov r0, r3 */
/* @0xe0c64 add r1, pc, r1 */
/* @0xe0c68 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0c6c mov r0, r6 */
/* @0xe0c70 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0c74 ldr r0, [pc, #0x68] */
/* @0xe0c78 add r0, pc, r0 */
/* @0xe0c7c bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe0c80 ldr r3, [sp, #0x1c] */
/* @0xe0c84 sub r3, r3, #1 */
/* @0xe0c88 bic r3, r3, #-16777216 */
/* @0xe0c8c bic r3, r3, #3 */
/* @0xe0c90 cmp r3, #0 */
/* @0xe0c94 movne r0, r4 */
/* @0xe0c98 bne 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0c9c mov r0, r5 */
/* @0xe0ca0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe0ca4 mov r0, r4 */
/* @0xe0ca8 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0cac ldr r0, [pc, #0x34] */
/* @0xe0cb0 add r0, pc, r0 */
/* @0xe0cb4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe0cb8 b 0xe0c80 <_Z5DoNegjPhPKhP6VMExec+0x314> */
/* @0xe0cbc mov r0, r6 */
/* @0xe0cc0 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0cc4 mlaeq r5, r8, r3, r3 */
/* @0xe0cc8 eoreq r3, r5, r4, asr #3 */
/* @0xe0ccc eoreq r3, r5, r12, ror #4 */
/* @0xe0cd0 eoreq r3, r5, r4, lsr r2 */
/* @0xe0cd4 mlaeq r5, r4, r2, r3 */
/* @0xe0cd8 eoreq r3, r5, r0, asr #4 */
/* @0xe0cdc eoreq r3, r5, r8, ror #2 */
/* @0xe0ce0 eoreq r3, r5, r12, asr #4 */
/* @0xe0ce4 eoreq r3, r5, r0, lsl r1 */
/* @0xe0ce8 .word 0x002530d8 */

/* ── FUNC 0xe0cec · DoShl(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=2172 · insn=543 */
/* @0xe0cec tst r0, #3840 */
/* @0xe0cf0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xe0cf4 lsr r5, r0, #16 */
/* @0xe0cf8 sub sp, sp, #64 */
/* @0xe0cfc mov r7, r1 */
/* @0xe0d00 mov r10, r3 */
/* @0xe0d04 bne 0xe0d38 <_Z5DoShljPhPKhP6VMExec+0x4c> */
/* @0xe0d08 uxtb r4, r5 */
/* @0xe0d0c and r2, r4, #15 */
/* @0xe0d10 cmp r2, #6 */
/* @0xe0d14 addls pc, pc, r2, lsl #2 */
/* @0xe0d18 b 0xe1510 <_Z5DoShljPhPKhP6VMExec+0x824> */
/* @0xe0d1c b 0xe0dd8 <_Z5DoShljPhPKhP6VMExec+0xec> */
/* @0xe0d20 b 0xe10e4 <_Z5DoShljPhPKhP6VMExec+0x3f8> */
/* @0xe0d24 b 0xe10e4 <_Z5DoShljPhPKhP6VMExec+0x3f8> */
/* @0xe0d28 b 0xe0dd8 <_Z5DoShljPhPKhP6VMExec+0xec> */
/* @0xe0d2c b 0xe10e4 <_Z5DoShljPhPKhP6VMExec+0x3f8> */
/* @0xe0d30 b 0xe10f0 <_Z5DoShljPhPKhP6VMExec+0x404> */
/* @0xe0d34 b 0xe1138 <_Z5DoShljPhPKhP6VMExec+0x44c> */
/* @0xe0d38 add r4, sp, #16 */
/* @0xe0d3c uxtb r5, r5 */
/* @0xe0d40 mov r2, r1 */
/* @0xe0d44 and r1, r5, #15 */
/* @0xe0d48 mov r0, r4 */
/* @0xe0d4c bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe0d50 lsr r1, r5, #4 */
/* @0xe0d54 mov r2, r0 */
/* @0xe0d58 mov r0, sp */
/* @0xe0d5c bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe0d60 ldr r3, [sp, #0xc] */
/* @0xe0d64 mvn r12, #-16777216 */
/* @0xe0d68 and r3, r3, r12 */
/* @0xe0d6c cmp r3, r12 */
/* @0xe0d70 mov r6, r0 */
/* @0xe0d74 beq 0xe14c8 <_Z5DoShljPhPKhP6VMExec+0x7dc> */
/* @0xe0d78 ldr r3, [sp, #0x1c] */
/* @0xe0d7c bic r3, r3, #-16777216 */
/* @0xe0d80 cmp r3, r12 */
/* @0xe0d84 beq 0xe12c4 <_Z5DoShljPhPKhP6VMExec+0x5d8> */
/* @0xe0d88 add r5, sp, #32 */
/* @0xe0d8c mov r1, sp */
/* @0xe0d90 mov r2, #0 */
/* @0xe0d94 mov r3, #0 */
/* @0xe0d98 mov r0, r5 */
/* @0xe0d9c str r12, [sp, #0x2c] */
/* @0xe0da0 str r12, [sp, #0x3c] */
/* @0xe0da4 mov r12, #0 */
/* @0xe0da8 strd r2, r3, [sp, #32] */
/* @0xe0dac strd r2, r3, [sp, #48] */
/* @0xe0db0 str r12, [sp, #0x28] */
/* @0xe0db4 str r12, [sp, #0x38] */
/* @0xe0db8 bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0xe0dbc cmp r0, #1 */
/* @0xe0dc0 beq 0xe14dc <_Z5DoShljPhPKhP6VMExec+0x7f0> */
/* @0xe0dc4 cmp r0, #0 */
/* @0xe0dc8 beq 0xe12f0 <_Z5DoShljPhPKhP6VMExec+0x604> */
/* @0xe0dcc mov r0, r6 */
/* @0xe0dd0 add sp, sp, #64 */
/* @0xe0dd4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xe0dd8 add r8, r1, #8 */
/* @0xe0ddc mov r5, r4 */
/* @0xe0de0 asr r2, r5, #4 */
/* @0xe0de4 cmp r2, #6 */
/* @0xe0de8 addls pc, pc, r2, lsl #2 */
/* @0xe0dec b 0xe151c <_Z5DoShljPhPKhP6VMExec+0x830> */
/* @0xe0df0 b 0xe10dc <_Z5DoShljPhPKhP6VMExec+0x3f0> */
/* @0xe0df4 b 0xe10d4 <_Z5DoShljPhPKhP6VMExec+0x3e8> */
/* @0xe0df8 b 0xe10d4 <_Z5DoShljPhPKhP6VMExec+0x3e8> */
/* @0xe0dfc b 0xe10dc <_Z5DoShljPhPKhP6VMExec+0x3f0> */
/* @0xe0e00 b 0xe10d4 <_Z5DoShljPhPKhP6VMExec+0x3e8> */
/* @0xe0e04 b 0xe108c <_Z5DoShljPhPKhP6VMExec+0x3a0> */
/* @0xe0e08 b 0xe0e0c <_Z5DoShljPhPKhP6VMExec+0x120> */
/* @0xe0e0c ldr r1, [pc, #0x710] */
/* @0xe0e10 mov r0, r10 */
/* @0xe0e14 mov r6, r8 */
/* @0xe0e18 add r1, pc, r1 */
/* @0xe0e1c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0e20 cmp r4, #85 */
/* @0xe0e24 addls pc, pc, r4, lsl #2 */
/* @0xe0e28 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e2c b 0xe107c <_Z5DoShljPhPKhP6VMExec+0x390> */
/* @0xe0e30 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e34 b 0xe107c <_Z5DoShljPhPKhP6VMExec+0x390> */
/* @0xe0e38 b 0xe107c <_Z5DoShljPhPKhP6VMExec+0x390> */
/* @0xe0e3c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e40 b 0xe106c <_Z5DoShljPhPKhP6VMExec+0x380> */
/* @0xe0e44 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e48 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e4c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e50 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e54 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e58 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e5c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e60 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e64 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e68 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e6c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e70 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e74 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e78 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e7c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e80 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e84 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e88 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e8c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e90 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e94 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e98 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e9c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ea0 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ea4 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ea8 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0eac b 0xe107c <_Z5DoShljPhPKhP6VMExec+0x390> */
/* @0xe0eb0 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0eb4 b 0xe0f84 <_Z5DoShljPhPKhP6VMExec+0x298> */
/* @0xe0eb8 b 0xe107c <_Z5DoShljPhPKhP6VMExec+0x390> */
/* @0xe0ebc b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ec0 b 0xe106c <_Z5DoShljPhPKhP6VMExec+0x380> */
/* @0xe0ec4 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ec8 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ecc b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ed0 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ed4 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ed8 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0edc b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ee0 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ee4 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ee8 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0eec b 0xe107c <_Z5DoShljPhPKhP6VMExec+0x390> */
/* @0xe0ef0 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ef4 b 0xe107c <_Z5DoShljPhPKhP6VMExec+0x390> */
/* @0xe0ef8 b 0xe107c <_Z5DoShljPhPKhP6VMExec+0x390> */
/* @0xe0efc b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f00 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f04 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f08 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f0c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f10 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f14 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f18 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f1c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f20 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f24 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f28 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f2c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f30 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f34 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f38 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f3c b 0xe0f84 <_Z5DoShljPhPKhP6VMExec+0x298> */
/* @0xe0f40 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f44 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f48 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f4c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f50 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f54 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f58 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f5c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f60 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f64 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f68 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f6c b 0xe106c <_Z5DoShljPhPKhP6VMExec+0x380> */
/* @0xe0f70 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f74 b 0xe106c <_Z5DoShljPhPKhP6VMExec+0x380> */
/* @0xe0f78 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f7c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f80 b 0xe106c <_Z5DoShljPhPKhP6VMExec+0x380> */
/* @0xe0f84 sub r6, r6, #4 */
/* @0xe0f88 mov r4, #0 */
/* @0xe0f8c mov r9, r6 */
/* @0xe0f90 cmp r5, #51 */
/* @0xe0f94 addls pc, pc, r5, lsl #2 */
/* @0xe0f98 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0f9c b 0xe11dc <_Z5DoShljPhPKhP6VMExec+0x4f0> */
/* @0xe0fa0 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fa4 b 0xe1154 <_Z5DoShljPhPKhP6VMExec+0x468> */
/* @0xe0fa8 b 0xe1154 <_Z5DoShljPhPKhP6VMExec+0x468> */
/* @0xe0fac b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fb0 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fb4 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fb8 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fbc b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fc0 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fc4 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fc8 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fcc b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fd0 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fd4 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fd8 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fdc b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fe0 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fe4 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fe8 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fec b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0ff0 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0ff4 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0ff8 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0ffc b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1000 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1004 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1008 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe100c b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1010 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1014 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1018 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe101c b 0xe12a0 <_Z5DoShljPhPKhP6VMExec+0x5b4> */
/* @0xe1020 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1024 b 0xe1288 <_Z5DoShljPhPKhP6VMExec+0x59c> */
/* @0xe1028 b 0xe1254 <_Z5DoShljPhPKhP6VMExec+0x568> */
/* @0xe102c b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1030 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1034 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1038 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe103c b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1040 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1044 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1048 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe104c b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1050 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1054 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1058 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe105c b 0xe121c <_Z5DoShljPhPKhP6VMExec+0x530> */
/* @0xe1060 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1064 b 0xe11a0 <_Z5DoShljPhPKhP6VMExec+0x4b4> */
/* @0xe1068 b 0xe11a0 <_Z5DoShljPhPKhP6VMExec+0x4b4> */
/* @0xe106c sub r4, r6, #16 */
/* @0xe1070 mov r9, r4 */
/* @0xe1074 mov r6, r4 */
/* @0xe1078 b 0xe0f90 <_Z5DoShljPhPKhP6VMExec+0x2a4> */
/* @0xe107c sub r6, r6, #8 */
/* @0xe1080 mov r4, #0 */
/* @0xe1084 mov r9, r6 */
/* @0xe1088 b 0xe0f90 <_Z5DoShljPhPKhP6VMExec+0x2a4> */
/* @0xe108c ldr r3, [r8, #0xc] */
/* @0xe1090 cmp r3, #13 */
/* @0xe1094 addls pc, pc, r3, lsl #2 */
/* @0xe1098 b 0xe149c <_Z5DoShljPhPKhP6VMExec+0x7b0> */
/* @0xe109c b 0xe13dc <_Z5DoShljPhPKhP6VMExec+0x6f0> */
/* @0xe10a0 b 0xe13c8 <_Z5DoShljPhPKhP6VMExec+0x6dc> */
/* @0xe10a4 b 0xe13b4 <_Z5DoShljPhPKhP6VMExec+0x6c8> */
/* @0xe10a8 b 0xe13f8 <_Z5DoShljPhPKhP6VMExec+0x70c> */
/* @0xe10ac b 0xe149c <_Z5DoShljPhPKhP6VMExec+0x7b0> */
/* @0xe10b0 b 0xe13e4 <_Z5DoShljPhPKhP6VMExec+0x6f8> */
/* @0xe10b4 b 0xe149c <_Z5DoShljPhPKhP6VMExec+0x7b0> */
/* @0xe10b8 b 0xe140c <_Z5DoShljPhPKhP6VMExec+0x720> */
/* @0xe10bc b 0xe149c <_Z5DoShljPhPKhP6VMExec+0x7b0> */
/* @0xe10c0 b 0xe149c <_Z5DoShljPhPKhP6VMExec+0x7b0> */
/* @0xe10c4 b 0xe13a4 <_Z5DoShljPhPKhP6VMExec+0x6b8> */
/* @0xe10c8 b 0xe149c <_Z5DoShljPhPKhP6VMExec+0x7b0> */
/* @0xe10cc b 0xe149c <_Z5DoShljPhPKhP6VMExec+0x7b0> */
/* @0xe10d0 b 0xe13dc <_Z5DoShljPhPKhP6VMExec+0x6f0> */
/* @0xe10d4 add r6, r8, #4 */
/* @0xe10d8 b 0xe0e20 <_Z5DoShljPhPKhP6VMExec+0x134> */
/* @0xe10dc add r6, r8, #8 */
/* @0xe10e0 b 0xe0e20 <_Z5DoShljPhPKhP6VMExec+0x134> */
/* @0xe10e4 add r8, r1, #4 */
/* @0xe10e8 mov r5, r4 */
/* @0xe10ec b 0xe0de0 <_Z5DoShljPhPKhP6VMExec+0xf4> */
/* @0xe10f0 ldr r3, [r1, #0xc] */
/* @0xe10f4 cmp r3, #13 */
/* @0xe10f8 addls pc, pc, r3, lsl #2 */
/* @0xe10fc b 0xe14b0 <_Z5DoShljPhPKhP6VMExec+0x7c4> */
/* @0xe1100 b 0xe144c <_Z5DoShljPhPKhP6VMExec+0x760> */
/* @0xe1104 b 0xe1434 <_Z5DoShljPhPKhP6VMExec+0x748> */
/* @0xe1108 b 0xe1418 <_Z5DoShljPhPKhP6VMExec+0x72c> */
/* @0xe110c b 0xe1484 <_Z5DoShljPhPKhP6VMExec+0x798> */
/* @0xe1110 b 0xe14b0 <_Z5DoShljPhPKhP6VMExec+0x7c4> */
/* @0xe1114 b 0xe146c <_Z5DoShljPhPKhP6VMExec+0x780> */
/* @0xe1118 b 0xe14b0 <_Z5DoShljPhPKhP6VMExec+0x7c4> */
/* @0xe111c b 0xe1460 <_Z5DoShljPhPKhP6VMExec+0x774> */
/* @0xe1120 b 0xe14b0 <_Z5DoShljPhPKhP6VMExec+0x7c4> */
/* @0xe1124 b 0xe14b0 <_Z5DoShljPhPKhP6VMExec+0x7c4> */
/* @0xe1128 b 0xe1454 <_Z5DoShljPhPKhP6VMExec+0x768> */
/* @0xe112c b 0xe14b0 <_Z5DoShljPhPKhP6VMExec+0x7c4> */
/* @0xe1130 b 0xe14b0 <_Z5DoShljPhPKhP6VMExec+0x7c4> */
/* @0xe1134 b 0xe144c <_Z5DoShljPhPKhP6VMExec+0x760> */
/* @0xe1138 ldr r1, [pc, #0x3e8] */
/* @0xe113c mov r0, r3 */
/* @0xe1140 mov r5, r4 */
/* @0xe1144 mov r8, r7 */
/* @0xe1148 add r1, pc, r1 */
/* @0xe114c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe1150 b 0xe0de0 <_Z5DoShljPhPKhP6VMExec+0xf4> */
/* @0xe1154 ldrd r0, r1, [r8] */
/* @0xe1158 bl 0x3194a0 <__fixdfdi> */
/* @0xe115c ldr r3, [r7] */
/* @0xe1160 sub lr, r3, #32 */
/* @0xe1164 rsb r12, r3, #32 */
/* @0xe1168 mov r2, r0 */
/* @0xe116c lsl r1, r1, r3 */
/* @0xe1170 orr r1, r1, r2, lsl lr */
/* @0xe1174 lsl r0, r0, r3 */
/* @0xe1178 orr r1, r1, r2, lsr r12 */
/* @0xe117c bl 0x319164 <__floatdidf> */
/* @0xe1180 mov r12, #0 */
/* @0xe1184 strd r0, r1, [r9] */
/* @0xe1188 cmp r4, #0 */
/* @0xe118c beq 0xe0dcc <_Z5DoShljPhPKhP6VMExec+0xe0> */
/* @0xe1190 mov r0, r6 */
/* @0xe1194 str r12, [r4, #0xc] */
/* @0xe1198 add sp, sp, #64 */
/* @0xe119c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xe11a0 ldr r3, [r8, #0x4] */
/* @0xe11a4 mov r12, #10 */
/* @0xe11a8 ldr r2, [r7] */
/* @0xe11ac ldr r1, [r8] */
/* @0xe11b0 sub r5, r2, #32 */
/* @0xe11b4 lsl r3, r3, r2 */
/* @0xe11b8 rsb r0, r2, #32 */
/* @0xe11bc orr r3, r3, r1, lsl r5 */
/* @0xe11c0 lsl r2, r1, r2 */
/* @0xe11c4 orr r3, r3, r1, lsr r0 */
/* @0xe11c8 stm r9, {r2, r3} */
/* @0xe11cc b 0xe1188 <_Z5DoShljPhPKhP6VMExec+0x49c> */
/* @0xe11d0 mov r9, #0 */
/* @0xe11d4 mov r4, r9 */
/* @0xe11d8 b 0xe0f90 <_Z5DoShljPhPKhP6VMExec+0x2a4> */
/* @0xe11dc ldrd r0, r1, [r8] */
/* @0xe11e0 bl 0x3194a0 <__fixdfdi> */
/* @0xe11e4 mov r5, r0 */
/* @0xe11e8 mov r8, r1 */
/* @0xe11ec ldrd r0, r1, [r7] */
/* @0xe11f0 bl 0x3194a0 <__fixdfdi> */
/* @0xe11f4 sub r2, r0, #32 */
/* @0xe11f8 lsl r1, r8, r0 */
/* @0xe11fc orr r1, r1, r5, lsl r2 */
/* @0xe1200 rsb r2, r0, #32 */
/* @0xe1204 orr r1, r1, r5, lsr r2 */
/* @0xe1208 lsl r0, r5, r0 */
/* @0xe120c bl 0x319164 <__floatdidf> */
/* @0xe1210 mov r12, #0 */
/* @0xe1214 strd r0, r1, [r9] */
/* @0xe1218 b 0xe1188 <_Z5DoShljPhPKhP6VMExec+0x49c> */
/* @0xe121c ldrd r0, r1, [r7] */
/* @0xe1220 bl 0x3194a0 <__fixdfdi> */
/* @0xe1224 ldr r3, [r8, #0x4] */
/* @0xe1228 ldr r2, [r8] */
/* @0xe122c sub r12, r0, #32 */
/* @0xe1230 lsl r3, r3, r0 */
/* @0xe1234 orr r3, r3, r2, lsl r12 */
/* @0xe1238 rsb r1, r0, #32 */
/* @0xe123c orr r1, r3, r2, lsr r1 */
/* @0xe1240 lsl r0, r2, r0 */
/* @0xe1244 bl 0x319164 <__floatdidf> */
/* @0xe1248 mov r12, #0 */
/* @0xe124c strd r0, r1, [r9] */
/* @0xe1250 b 0xe1188 <_Z5DoShljPhPKhP6VMExec+0x49c> */
/* @0xe1254 ldr r1, [r8] */
/* @0xe1258 mov r12, #10 */
/* @0xe125c ldr r0, [r7] */
/* @0xe1260 asr r3, r1, #31 */
/* @0xe1264 sub r5, r0, #32 */
/* @0xe1268 rsb r2, r0, #32 */
/* @0xe126c lsl r3, r3, r0 */
/* @0xe1270 lsl r0, r1, r0 */
/* @0xe1274 orr r3, r3, r1, lsl r5 */
/* @0xe1278 str r0, [r9] */
/* @0xe127c orr r3, r3, r1, lsr r2 */
/* @0xe1280 str r3, [r9, #0x4] */
/* @0xe1284 b 0xe1188 <_Z5DoShljPhPKhP6VMExec+0x49c> */
/* @0xe1288 ldr r2, [r8] */
/* @0xe128c mov r12, #7 */
/* @0xe1290 ldr r3, [r7] */
/* @0xe1294 lsl r3, r2, r3 */
/* @0xe1298 str r3, [r9] */
/* @0xe129c b 0xe1188 <_Z5DoShljPhPKhP6VMExec+0x49c> */
/* @0xe12a0 ldrd r0, r1, [r7] */
/* @0xe12a4 bl 0x3194a0 <__fixdfdi> */
/* @0xe12a8 ldr r3, [r8] */
/* @0xe12ac mov r12, #0 */
/* @0xe12b0 lsl r0, r3, r0 */
/* @0xe12b4 vmov s11, r0 */
/* @0xe12b8 vcvt.f64.s32 d7, s11 */
/* @0xe12bc vstr d7, [r9] */
/* @0xe12c0 b 0xe1188 <_Z5DoShljPhPKhP6VMExec+0x49c> */
/* @0xe12c4 ldr r0, [pc, #0x260] */
/* @0xe12c8 add r0, pc, r0 */
/* @0xe12cc bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe12d0 mov r0, r6 */
/* @0xe12d4 b 0xe0dd0 <_Z5DoShljPhPKhP6VMExec+0xe4> */
/* @0xe12d8 ldr r1, [pc, #0x250] */
/* @0xe12dc mov r0, r10 */
/* @0xe12e0 add r1, pc, r1 */
/* @0xe12e4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe12e8 mov r12, #0 */
/* @0xe12ec b 0xe1188 <_Z5DoShljPhPKhP6VMExec+0x49c> */
/* @0xe12f0 add r7, sp, #48 */
/* @0xe12f4 mov r1, r4 */
/* @0xe12f8 mov r0, r7 */
/* @0xe12fc bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0xe1300 cmp r0, #1 */
/* @0xe1304 beq 0xe14fc <_Z5DoShljPhPKhP6VMExec+0x810> */
/* @0xe1308 cmp r0, #0 */
/* @0xe130c bne 0xe0dcc <_Z5DoShljPhPKhP6VMExec+0xe0> */
/* @0xe1310 vldr d6, [sp, #48] */
/* @0xe1314 str r0, [r6, #-0x4] */
/* @0xe1318 vcvt.s32.f64 s11, d6 */
/* @0xe131c vldr d7, [sp, #32] */
/* @0xe1320 ldr r1, [sp, #0x2c] */
/* @0xe1324 sub r4, r6, #16 */
/* @0xe1328 sub r1, r1, #1 */
/* @0xe132c bic r1, r1, #-16777216 */
/* @0xe1330 bic r1, r1, #3 */
/* @0xe1334 cmp r1, #0 */
/* @0xe1338 vcvt.s32.f64 s13, d7 */
/* @0xe133c vmov r3, s11 */
/* @0xe1340 vmov r2, s13 */
/* @0xe1344 and r3, r3, #31 */
/* @0xe1348 lsl r2, r2, r3 */
/* @0xe134c vmov s15, r2 */
/* @0xe1350 vcvt.f64.s32 d7, s15 */
/* @0xe1354 vmov r2, r3, d7 */
/* @0xe1358 vstr s14, [r6, #-16] */
/* @0xe135c str r3, [r6, #-0xc] */
/* @0xe1360 beq 0xe14f0 <_Z5DoShljPhPKhP6VMExec+0x804> */
/* @0xe1364 ldr r1, [sp, #0x3c] */
/* @0xe1368 mov r3, #0 */
/* @0xe136c str r3, [sp, #0x28] */
/* @0xe1370 mov r2, #5 */
/* @0xe1374 sub r1, r1, #1 */
/* @0xe1378 str r3, [sp, #0x20] */
/* @0xe137c bic r3, r1, #-16777216 */
/* @0xe1380 str r2, [sp, #0x2c] */
/* @0xe1384 bic r3, r3, #3 */
/* @0xe1388 cmp r3, #0 */
/* @0xe138c movne r0, r4 */
/* @0xe1390 bne 0xe0dd0 <_Z5DoShljPhPKhP6VMExec+0xe4> */
/* @0xe1394 mov r0, r7 */
/* @0xe1398 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe139c mov r0, r4 */
/* @0xe13a0 b 0xe0dd0 <_Z5DoShljPhPKhP6VMExec+0xe4> */
/* @0xe13a4 and r5, r5, #15 */
/* @0xe13a8 orr r5, r5, #48 */
/* @0xe13ac add r6, r8, #16 */
/* @0xe13b0 b 0xe0e20 <_Z5DoShljPhPKhP6VMExec+0x134> */
/* @0xe13b4 ldr r1, [pc, #0x178] */
/* @0xe13b8 mov r0, r10 */
/* @0xe13bc add r1, pc, r1 */
/* @0xe13c0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe13c4 b 0xe13ac <_Z5DoShljPhPKhP6VMExec+0x6c0> */
/* @0xe13c8 ldr r1, [pc, #0x168] */
/* @0xe13cc mov r0, r10 */
/* @0xe13d0 add r1, pc, r1 */
/* @0xe13d4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe13d8 b 0xe13ac <_Z5DoShljPhPKhP6VMExec+0x6c0> */
/* @0xe13dc and r5, r5, #15 */
/* @0xe13e0 b 0xe13ac <_Z5DoShljPhPKhP6VMExec+0x6c0> */
/* @0xe13e4 ldr r1, [pc, #0x150] */
/* @0xe13e8 mov r0, r10 */
/* @0xe13ec add r1, pc, r1 */
/* @0xe13f0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe13f4 b 0xe13ac <_Z5DoShljPhPKhP6VMExec+0x6c0> */
/* @0xe13f8 ldr r1, [pc, #0x140] */
/* @0xe13fc mov r0, r10 */
/* @0xe1400 add r1, pc, r1 */
/* @0xe1404 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe1408 b 0xe13ac <_Z5DoShljPhPKhP6VMExec+0x6c0> */
/* @0xe140c and r5, r5, #15 */
/* @0xe1410 orr r5, r5, #32 */
/* @0xe1414 b 0xe13ac <_Z5DoShljPhPKhP6VMExec+0x6c0> */
/* @0xe1418 ldr r1, [pc, #0x124] */
/* @0xe141c mov r0, r10 */
/* @0xe1420 mov r5, r4 */
/* @0xe1424 add r1, pc, r1 */
/* @0xe1428 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe142c add r8, r7, #16 */
/* @0xe1430 b 0xe0de0 <_Z5DoShljPhPKhP6VMExec+0xf4> */
/* @0xe1434 ldr r1, [pc, #0x10c] */
/* @0xe1438 mov r0, r10 */
/* @0xe143c mov r5, r4 */
/* @0xe1440 add r1, pc, r1 */
/* @0xe1444 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe1448 b 0xe142c <_Z5DoShljPhPKhP6VMExec+0x740> */
/* @0xe144c and r5, r4, #240 */
/* @0xe1450 b 0xe142c <_Z5DoShljPhPKhP6VMExec+0x740> */
/* @0xe1454 and r5, r5, #240 */
/* @0xe1458 orr r5, r5, #3 */
/* @0xe145c b 0xe142c <_Z5DoShljPhPKhP6VMExec+0x740> */
/* @0xe1460 and r5, r5, #240 */
/* @0xe1464 orr r5, r5, #2 */
/* @0xe1468 b 0xe142c <_Z5DoShljPhPKhP6VMExec+0x740> */
/* @0xe146c ldr r1, [pc, #0xd8] */
/* @0xe1470 mov r0, r10 */
/* @0xe1474 mov r5, r4 */
/* @0xe1478 add r1, pc, r1 */
/* @0xe147c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe1480 b 0xe142c <_Z5DoShljPhPKhP6VMExec+0x740> */
/* @0xe1484 ldr r1, [pc, #0xc4] */
/* @0xe1488 mov r0, r10 */
/* @0xe148c mov r5, r4 */
/* @0xe1490 add r1, pc, r1 */
/* @0xe1494 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe1498 b 0xe142c <_Z5DoShljPhPKhP6VMExec+0x740> */
/* @0xe149c ldr r1, [pc, #0xb0] */
/* @0xe14a0 mov r0, r10 */
/* @0xe14a4 add r1, pc, r1 */
/* @0xe14a8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe14ac b 0xe13ac <_Z5DoShljPhPKhP6VMExec+0x6c0> */
/* @0xe14b0 ldr r1, [pc, #0xa0] */
/* @0xe14b4 mov r0, r10 */
/* @0xe14b8 mov r5, r4 */
/* @0xe14bc add r1, pc, r1 */
/* @0xe14c0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe14c4 b 0xe142c <_Z5DoShljPhPKhP6VMExec+0x740> */
/* @0xe14c8 ldr r0, [pc, #0x8c] */
/* @0xe14cc add r0, pc, r0 */
/* @0xe14d0 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe14d4 mov r0, r6 */
/* @0xe14d8 b 0xe0dd0 <_Z5DoShljPhPKhP6VMExec+0xe4> */
/* @0xe14dc ldr r0, [pc, #0x7c] */
/* @0xe14e0 add r0, pc, r0 */
/* @0xe14e4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe14e8 mov r0, r6 */
/* @0xe14ec b 0xe0dd0 <_Z5DoShljPhPKhP6VMExec+0xe4> */
/* @0xe14f0 mov r0, r5 */
/* @0xe14f4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe14f8 b 0xe1364 <_Z5DoShljPhPKhP6VMExec+0x678> */
/* @0xe14fc ldr r0, [pc, #0x60] */
/* @0xe1500 add r0, pc, r0 */
/* @0xe1504 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe1508 mov r0, r6 */
/* @0xe150c b 0xe0dd0 <_Z5DoShljPhPKhP6VMExec+0xe4> */
/* @0xe1510 mov r5, r4 */
/* @0xe1514 mov r8, r1 */
/* @0xe1518 b 0xe0de0 <_Z5DoShljPhPKhP6VMExec+0xf4> */
/* @0xe151c mov r6, r8 */
/* @0xe1520 b 0xe0e20 <_Z5DoShljPhPKhP6VMExec+0x134> */
/* @0xe1524 .word 0x002531b0 */
/* @0xe1528 .word 0x00252dd0 */
/* @0xe152c eoreq r2, r5, r12, lsr #24 */
/* @0xe1530 mlaeq r5, r12, sp, r2 */
/* @0xe1534 eoreq r2, r5, r4, lsl #25 */
/* @0xe1538 .word 0x00252bf8 */
/* @0xe153c eoreq r2, r5, r8, lsr r12 */
/* @0xe1540 eoreq r2, r5, r4, lsl #24 */
/* @0xe1544 eoreq r2, r5, r12, ror #22 */
/* @0xe1548 .word 0x00252ad8 */
/* @0xe154c .word 0x00252afc */
/* @0xe1550 eoreq r2, r5, r4, asr #21 */
/* @0xe1554 .word 0x00252bb8 */
/* @0xe1558 .word 0x00252af0 */
/* @0xe155c eoreq r2, r5, r4, lsl #20 */
/* @0xe1560 eoreq r2, r5, r0, asr #8 */
/* @0xe1564 eoreq r2, r5, r0, asr r4 */

/* ── FUNC 0xe1568 · DoShr(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=2548 · insn=637 */
/* @0xe1568 tst r0, #3840 */
/* @0xe156c lsr r2, r0, #16 */
/* @0xe1570 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe1574 mov r7, r0 */
/* @0xe1578 sub sp, sp, #76 */
/* @0xe157c mov r11, r1 */
/* @0xe1580 bne 0xe15b4 <_Z5DoShrjPhPKhP6VMExec+0x4c> */
/* @0xe1584 uxtb r4, r2 */
/* @0xe1588 and r1, r4, #15 */
/* @0xe158c cmp r1, #6 */
/* @0xe1590 addls pc, pc, r1, lsl #2 */
/* @0xe1594 b 0xe1f04 <_Z5DoShrjPhPKhP6VMExec+0x99c> */
/* @0xe1598 b 0xe19b8 <_Z5DoShrjPhPKhP6VMExec+0x450> */
/* @0xe159c b 0xe19c4 <_Z5DoShrjPhPKhP6VMExec+0x45c> */
/* @0xe15a0 b 0xe19c4 <_Z5DoShrjPhPKhP6VMExec+0x45c> */
/* @0xe15a4 b 0xe19b8 <_Z5DoShrjPhPKhP6VMExec+0x450> */
/* @0xe15a8 b 0xe19c4 <_Z5DoShrjPhPKhP6VMExec+0x45c> */
/* @0xe15ac b 0xe19d0 <_Z5DoShrjPhPKhP6VMExec+0x468> */
/* @0xe15b0 b 0xe1668 <_Z5DoShrjPhPKhP6VMExec+0x100> */
/* @0xe15b4 add r5, sp, #24 */
/* @0xe15b8 uxtb r4, r2 */
/* @0xe15bc mov r2, r1 */
/* @0xe15c0 and r1, r4, #15 */
/* @0xe15c4 mov r0, r5 */
/* @0xe15c8 add r9, sp, #8 */
/* @0xe15cc bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe15d0 lsr r1, r4, #4 */
/* @0xe15d4 mov r2, r0 */
/* @0xe15d8 mov r0, r9 */
/* @0xe15dc bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe15e0 ldr r3, [sp, #0x14] */
/* @0xe15e4 mvn r12, #-16777216 */
/* @0xe15e8 and r3, r3, r12 */
/* @0xe15ec cmp r3, r12 */
/* @0xe15f0 mov r4, r0 */
/* @0xe15f4 beq 0xe1e1c <_Z5DoShrjPhPKhP6VMExec+0x8b4> */
/* @0xe15f8 ldr r3, [sp, #0x24] */
/* @0xe15fc bic r3, r3, #-16777216 */
/* @0xe1600 cmp r3, r12 */
/* @0xe1604 beq 0xe1e30 <_Z5DoShrjPhPKhP6VMExec+0x8c8> */
/* @0xe1608 ands r7, r7, #32768 */
/* @0xe160c mov lr, #0 */
/* @0xe1610 add r6, sp, #40 */
/* @0xe1614 mov r1, r9 */
/* @0xe1618 sub r8, r0, #16 */
/* @0xe161c str lr, [r0, #-0x4] */
/* @0xe1620 bne 0xe1a68 <_Z5DoShrjPhPKhP6VMExec+0x500> */
/* @0xe1624 mov r0, r6 */
/* @0xe1628 mov r2, #0 */
/* @0xe162c mov r3, #0 */
/* @0xe1630 str r7, [sp, #0x30] */
/* @0xe1634 str r12, [sp, #0x34] */
/* @0xe1638 str r7, [sp, #0x40] */
/* @0xe163c str r12, [sp, #0x44] */
/* @0xe1640 strd r2, r3, [sp, #40] */
/* @0xe1644 strd r2, r3, [sp, #56] */
/* @0xe1648 bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0xe164c cmp r0, #1 */
/* @0xe1650 beq 0xe1ecc <_Z5DoShrjPhPKhP6VMExec+0x964> */
/* @0xe1654 cmp r0, #0 */
/* @0xe1658 beq 0xe1e44 <_Z5DoShrjPhPKhP6VMExec+0x8dc> */
/* @0xe165c mov r0, r8 */
/* @0xe1660 add sp, sp, #76 */
/* @0xe1664 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe1668 ldr r1, [pc, #0x8a0] */
/* @0xe166c mov r0, r3 */
/* @0xe1670 str r3, [sp] */
/* @0xe1674 mov r6, r11 */
/* @0xe1678 add r1, pc, r1 */
/* @0xe167c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe1680 ldr r3, [sp] */
/* @0xe1684 mov r2, r4 */
/* @0xe1688 asr r1, r2, #4 */
/* @0xe168c cmp r1, #6 */
/* @0xe1690 addls pc, pc, r1, lsl #2 */
/* @0xe1694 b 0xe1efc <_Z5DoShrjPhPKhP6VMExec+0x994> */
/* @0xe1698 b 0xe19b0 <_Z5DoShrjPhPKhP6VMExec+0x448> */
/* @0xe169c b 0xe19a8 <_Z5DoShrjPhPKhP6VMExec+0x440> */
/* @0xe16a0 b 0xe19a8 <_Z5DoShrjPhPKhP6VMExec+0x440> */
/* @0xe16a4 b 0xe19b0 <_Z5DoShrjPhPKhP6VMExec+0x448> */
/* @0xe16a8 b 0xe19a8 <_Z5DoShrjPhPKhP6VMExec+0x440> */
/* @0xe16ac b 0xe1960 <_Z5DoShrjPhPKhP6VMExec+0x3f8> */
/* @0xe16b0 b 0xe16b4 <_Z5DoShrjPhPKhP6VMExec+0x14c> */
/* @0xe16b4 ldr r1, [pc, #0x858] */
/* @0xe16b8 mov r0, r3 */
/* @0xe16bc str r2, [sp, #0x4] */
/* @0xe16c0 mov r8, r6 */
/* @0xe16c4 add r1, pc, r1 */
/* @0xe16c8 str r3, [sp] */
/* @0xe16cc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe16d0 ldr r2, [sp, #0x4] */
/* @0xe16d4 ldr r3, [sp] */
/* @0xe16d8 cmp r4, #85 */
/* @0xe16dc addls pc, pc, r4, lsl #2 */
/* @0xe16e0 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe16e4 b 0xe1950 <_Z5DoShrjPhPKhP6VMExec+0x3e8> */
/* @0xe16e8 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe16ec b 0xe1950 <_Z5DoShrjPhPKhP6VMExec+0x3e8> */
/* @0xe16f0 b 0xe1950 <_Z5DoShrjPhPKhP6VMExec+0x3e8> */
/* @0xe16f4 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe16f8 b 0xe1940 <_Z5DoShrjPhPKhP6VMExec+0x3d8> */
/* @0xe16fc b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1700 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1704 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1708 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe170c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1710 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1714 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1718 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe171c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1720 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1724 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1728 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe172c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1730 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1734 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1738 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe173c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1740 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1744 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1748 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe174c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1750 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1754 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1758 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe175c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1760 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1764 b 0xe1950 <_Z5DoShrjPhPKhP6VMExec+0x3e8> */
/* @0xe1768 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe176c b 0xe183c <_Z5DoShrjPhPKhP6VMExec+0x2d4> */
/* @0xe1770 b 0xe1950 <_Z5DoShrjPhPKhP6VMExec+0x3e8> */
/* @0xe1774 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1778 b 0xe1940 <_Z5DoShrjPhPKhP6VMExec+0x3d8> */
/* @0xe177c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1780 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1784 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1788 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe178c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1790 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1794 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1798 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe179c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe17a0 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe17a4 b 0xe1950 <_Z5DoShrjPhPKhP6VMExec+0x3e8> */
/* @0xe17a8 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe17ac b 0xe1950 <_Z5DoShrjPhPKhP6VMExec+0x3e8> */
/* @0xe17b0 b 0xe1950 <_Z5DoShrjPhPKhP6VMExec+0x3e8> */
/* @0xe17b4 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe17b8 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe17bc b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe17c0 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe17c4 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe17c8 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe17cc b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe17d0 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe17d4 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe17d8 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe17dc b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe17e0 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe17e4 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe17e8 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe17ec b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe17f0 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe17f4 b 0xe183c <_Z5DoShrjPhPKhP6VMExec+0x2d4> */
/* @0xe17f8 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe17fc b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1800 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1804 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1808 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe180c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1810 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1814 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1818 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe181c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1820 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1824 b 0xe1940 <_Z5DoShrjPhPKhP6VMExec+0x3d8> */
/* @0xe1828 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe182c b 0xe1940 <_Z5DoShrjPhPKhP6VMExec+0x3d8> */
/* @0xe1830 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1834 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0xe1838 b 0xe1940 <_Z5DoShrjPhPKhP6VMExec+0x3d8> */
/* @0xe183c sub r8, r8, #4 */
/* @0xe1840 mov r9, #0 */
/* @0xe1844 mov r10, r8 */
/* @0xe1848 tst r7, #32768 */
/* @0xe184c mvnne r7, #-2147483648 */
/* @0xe1850 mvnne r4, #0 */
/* @0xe1854 mvnne r5, #-2147483648 */
/* @0xe1858 mvneq r4, #0 */
/* @0xe185c mvneq r5, #0 */
/* @0xe1860 mvneq r7, #0 */
/* @0xe1864 cmp r2, #51 */
/* @0xe1868 addls pc, pc, r2, lsl #2 */
/* @0xe186c b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe1870 b 0xe1bd0 <_Z5DoShrjPhPKhP6VMExec+0x668> */
/* @0xe1874 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe1878 b 0xe1a18 <_Z5DoShrjPhPKhP6VMExec+0x4b0> */
/* @0xe187c b 0xe1a18 <_Z5DoShrjPhPKhP6VMExec+0x4b0> */
/* @0xe1880 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe1884 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe1888 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe188c b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe1890 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe1894 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe1898 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe189c b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18a0 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18a4 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18a8 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18ac b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18b0 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18b4 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18b8 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18bc b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18c0 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18c4 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18c8 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18cc b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18d0 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18d4 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18d8 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18dc b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18e0 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18e4 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18e8 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18ec b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18f0 b 0xe1c80 <_Z5DoShrjPhPKhP6VMExec+0x718> */
/* @0xe18f4 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe18f8 b 0xe1c68 <_Z5DoShrjPhPKhP6VMExec+0x700> */
/* @0xe18fc b 0xe1c30 <_Z5DoShrjPhPKhP6VMExec+0x6c8> */
/* @0xe1900 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe1904 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe1908 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe190c b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe1910 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe1914 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe1918 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe191c b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe1920 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe1924 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe1928 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe192c b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe1930 b 0xe1c04 <_Z5DoShrjPhPKhP6VMExec+0x69c> */
/* @0xe1934 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0xe1938 b 0xe1b5c <_Z5DoShrjPhPKhP6VMExec+0x5f4> */
/* @0xe193c b 0xe1b98 <_Z5DoShrjPhPKhP6VMExec+0x630> */
/* @0xe1940 sub r9, r8, #16 */
/* @0xe1944 mov r10, r9 */
/* @0xe1948 mov r8, r9 */
/* @0xe194c b 0xe1848 <_Z5DoShrjPhPKhP6VMExec+0x2e0> */
/* @0xe1950 sub r8, r8, #8 */
/* @0xe1954 mov r9, #0 */
/* @0xe1958 mov r10, r8 */
/* @0xe195c b 0xe1848 <_Z5DoShrjPhPKhP6VMExec+0x2e0> */
/* @0xe1960 ldr r1, [r6, #0xc] */
/* @0xe1964 cmp r1, #13 */
/* @0xe1968 addls pc, pc, r1, lsl #2 */
/* @0xe196c b 0xe1dd8 <_Z5DoShrjPhPKhP6VMExec+0x870> */
/* @0xe1970 b 0xe1d0c <_Z5DoShrjPhPKhP6VMExec+0x7a4> */
/* @0xe1974 b 0xe1cfc <_Z5DoShrjPhPKhP6VMExec+0x794> */
/* @0xe1978 b 0xe1cd8 <_Z5DoShrjPhPKhP6VMExec+0x770> */
/* @0xe197c b 0xe1d24 <_Z5DoShrjPhPKhP6VMExec+0x7bc> */
/* @0xe1980 b 0xe1dd8 <_Z5DoShrjPhPKhP6VMExec+0x870> */
/* @0xe1984 b 0xe1d14 <_Z5DoShrjPhPKhP6VMExec+0x7ac> */
/* @0xe1988 b 0xe1dd8 <_Z5DoShrjPhPKhP6VMExec+0x870> */
/* @0xe198c b 0xe1ccc <_Z5DoShrjPhPKhP6VMExec+0x764> */
/* @0xe1990 b 0xe1dd8 <_Z5DoShrjPhPKhP6VMExec+0x870> */
/* @0xe1994 b 0xe1dd8 <_Z5DoShrjPhPKhP6VMExec+0x870> */
/* @0xe1998 b 0xe1cbc <_Z5DoShrjPhPKhP6VMExec+0x754> */
/* @0xe199c b 0xe1dd8 <_Z5DoShrjPhPKhP6VMExec+0x870> */
/* @0xe19a0 b 0xe1dd8 <_Z5DoShrjPhPKhP6VMExec+0x870> */
/* @0xe19a4 b 0xe1d0c <_Z5DoShrjPhPKhP6VMExec+0x7a4> */
/* @0xe19a8 add r8, r6, #4 */
/* @0xe19ac b 0xe16d8 <_Z5DoShrjPhPKhP6VMExec+0x170> */
/* @0xe19b0 add r8, r6, #8 */
/* @0xe19b4 b 0xe16d8 <_Z5DoShrjPhPKhP6VMExec+0x170> */
/* @0xe19b8 add r6, r11, #8 */
/* @0xe19bc mov r2, r4 */
/* @0xe19c0 b 0xe1688 <_Z5DoShrjPhPKhP6VMExec+0x120> */
/* @0xe19c4 add r6, r11, #4 */
/* @0xe19c8 mov r2, r4 */
/* @0xe19cc b 0xe1688 <_Z5DoShrjPhPKhP6VMExec+0x120> */
/* @0xe19d0 ldr r1, [r11, #0xc] */
/* @0xe19d4 cmp r1, #13 */
/* @0xe19d8 addls pc, pc, r1, lsl #2 */
/* @0xe19dc b 0xe1dfc <_Z5DoShrjPhPKhP6VMExec+0x894> */
/* @0xe19e0 b 0xe1dd0 <_Z5DoShrjPhPKhP6VMExec+0x868> */
/* @0xe19e4 b 0xe1db0 <_Z5DoShrjPhPKhP6VMExec+0x848> */
/* @0xe19e8 b 0xe1d90 <_Z5DoShrjPhPKhP6VMExec+0x828> */
/* @0xe19ec b 0xe1d70 <_Z5DoShrjPhPKhP6VMExec+0x808> */
/* @0xe19f0 b 0xe1dfc <_Z5DoShrjPhPKhP6VMExec+0x894> */
/* @0xe19f4 b 0xe1d50 <_Z5DoShrjPhPKhP6VMExec+0x7e8> */
/* @0xe19f8 b 0xe1dfc <_Z5DoShrjPhPKhP6VMExec+0x894> */
/* @0xe19fc b 0xe1d44 <_Z5DoShrjPhPKhP6VMExec+0x7dc> */
/* @0xe1a00 b 0xe1dfc <_Z5DoShrjPhPKhP6VMExec+0x894> */
/* @0xe1a04 b 0xe1dfc <_Z5DoShrjPhPKhP6VMExec+0x894> */
/* @0xe1a08 b 0xe1d34 <_Z5DoShrjPhPKhP6VMExec+0x7cc> */
/* @0xe1a0c b 0xe1dfc <_Z5DoShrjPhPKhP6VMExec+0x894> */
/* @0xe1a10 b 0xe1dfc <_Z5DoShrjPhPKhP6VMExec+0x894> */
/* @0xe1a14 b 0xe1dd0 <_Z5DoShrjPhPKhP6VMExec+0x868> */
/* @0xe1a18 ldrd r0, r1, [r6] */
/* @0xe1a1c bl 0x3194a0 <__fixdfdi> */
/* @0xe1a20 ldr r12, [r11] */
/* @0xe1a24 subs r6, r12, #32 */
/* @0xe1a28 rsb lr, r12, #32 */
/* @0xe1a2c lsr r2, r0, r12 */
/* @0xe1a30 orr r2, r2, r1, lsl lr */
/* @0xe1a34 orrpl r2, r2, r1, asr r6 */
/* @0xe1a38 asr r3, r1, r12 */
/* @0xe1a3c and r0, r4, r2 */
/* @0xe1a40 and r1, r5, r3 */
/* @0xe1a44 bl 0x319150 <__floatundidf> */
/* @0xe1a48 mov r12, #0 */
/* @0xe1a4c strd r0, r1, [r10] */
/* @0xe1a50 cmp r9, #0 */
/* @0xe1a54 beq 0xe165c <_Z5DoShrjPhPKhP6VMExec+0xf4> */
/* @0xe1a58 mov r0, r8 */
/* @0xe1a5c str r12, [r9, #0xc] */
/* @0xe1a60 add sp, sp, #76 */
/* @0xe1a64 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe1a68 mov r0, r6 */
/* @0xe1a6c mov r2, #0 */
/* @0xe1a70 mov r3, #0 */
/* @0xe1a74 str lr, [sp, #0x30] */
/* @0xe1a78 str r12, [sp, #0x34] */
/* @0xe1a7c str lr, [sp, #0x40] */
/* @0xe1a80 str r12, [sp, #0x44] */
/* @0xe1a84 strd r2, r3, [sp, #40] */
/* @0xe1a88 strd r2, r3, [sp, #56] */
/* @0xe1a8c bl 0x24d4f4 <_Z13F_JS_ToUint32R6RValueS0_> */
/* @0xe1a90 cmp r0, #1 */
/* @0xe1a94 beq 0xe1ebc <_Z5DoShrjPhPKhP6VMExec+0x954> */
/* @0xe1a98 cmp r0, #0 */
/* @0xe1a9c bne 0xe165c <_Z5DoShrjPhPKhP6VMExec+0xf4> */
/* @0xe1aa0 add r7, sp, #56 */
/* @0xe1aa4 mov r1, r5 */
/* @0xe1aa8 mov r0, r7 */
/* @0xe1aac bl 0x24d4f4 <_Z13F_JS_ToUint32R6RValueS0_> */
/* @0xe1ab0 cmp r0, #1 */
/* @0xe1ab4 beq 0xe1eec <_Z5DoShrjPhPKhP6VMExec+0x984> */
/* @0xe1ab8 cmp r0, #0 */
/* @0xe1abc bne 0xe165c <_Z5DoShrjPhPKhP6VMExec+0xf4> */
/* @0xe1ac0 vldr d6, [sp, #56] */
/* @0xe1ac4 vcvt.u32.f64 s11, d6 */
/* @0xe1ac8 vldr d7, [sp, #40] */
/* @0xe1acc ldr r2, [sp, #0x34] */
/* @0xe1ad0 mvn r1, #0 */
/* @0xe1ad4 add r2, r2, r1 */
/* @0xe1ad8 bic r2, r2, #-16777216 */
/* @0xe1adc bic r2, r2, #3 */
/* @0xe1ae0 cmp r2, #0 */
/* @0xe1ae4 vcvt.u32.f64 s14, d7 */
/* @0xe1ae8 vmov r3, s11 */
/* @0xe1aec vmov r0, s14 */
/* @0xe1af0 and r3, r3, #31 */
/* @0xe1af4 rsb r2, r3, #32 */
/* @0xe1af8 lsr r3, r0, r3 */
/* @0xe1afc bic r2, r3, r1, lsl r2 */
/* @0xe1b00 vmov s15, r2 */
/* @0xe1b04 vcvt.f64.u32 d7, s15 */
/* @0xe1b08 vmov r2, r3, d7 */
/* @0xe1b0c vstr s14, [r4, #-16] */
/* @0xe1b10 str r3, [r4, #-0xc] */
/* @0xe1b14 beq 0xe1eb0 <_Z5DoShrjPhPKhP6VMExec+0x948> */
/* @0xe1b18 ldr r1, [sp, #0x44] */
/* @0xe1b1c mov r3, #0 */
/* @0xe1b20 str r3, [sp, #0x30] */
/* @0xe1b24 mov r2, #5 */
/* @0xe1b28 sub r1, r1, #1 */
/* @0xe1b2c str r3, [sp, #0x28] */
/* @0xe1b30 bic r3, r1, #-16777216 */
/* @0xe1b34 str r2, [sp, #0x34] */
/* @0xe1b38 bic r3, r3, #3 */
/* @0xe1b3c cmp r3, #0 */
/* @0xe1b40 bne 0xe165c <_Z5DoShrjPhPKhP6VMExec+0xf4> */
/* @0xe1b44 mov r0, r7 */
/* @0xe1b48 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe1b4c b 0xe165c <_Z5DoShrjPhPKhP6VMExec+0xf4> */
/* @0xe1b50 mov r10, #0 */
/* @0xe1b54 mov r9, r10 */
/* @0xe1b58 b 0xe1848 <_Z5DoShrjPhPKhP6VMExec+0x2e0> */
/* @0xe1b5c ldr r12, [r11] */
/* @0xe1b60 mov r1, #0 */
/* @0xe1b64 ldr r11, [r6] */
/* @0xe1b68 ldr r4, [r6, #0x4] */
/* @0xe1b6c rsb r5, r12, #32 */
/* @0xe1b70 subs r6, r12, #32 */
/* @0xe1b74 lsr r2, r11, r12 */
/* @0xe1b78 orr r2, r2, r4, lsl r5 */
/* @0xe1b7c asr r3, r4, r12 */
/* @0xe1b80 orrpl r2, r2, r4, asr r6 */
/* @0xe1b84 and r3, r3, r1 */
/* @0xe1b88 and r2, r2, r7 */
/* @0xe1b8c mov r12, #10 */
/* @0xe1b90 strd r2, r3, [r10] */
/* @0xe1b94 b 0xe1a50 <_Z5DoShrjPhPKhP6VMExec+0x4e8> */
/* @0xe1b98 ldr r7, [r6] */
/* @0xe1b9c ldr r1, [r11] */
/* @0xe1ba0 ldr r0, [r6, #0x4] */
/* @0xe1ba4 rsb r12, r1, #32 */
/* @0xe1ba8 lsr r2, r7, r1 */
/* @0xe1bac subs r6, r1, #32 */
/* @0xe1bb0 orr r2, r2, r0, lsl r12 */
/* @0xe1bb4 asr r3, r0, r1 */
/* @0xe1bb8 orrpl r2, r2, r0, asr r6 */
/* @0xe1bbc and r5, r5, r3 */
/* @0xe1bc0 and r4, r4, r2 */
/* @0xe1bc4 mov r12, #10 */
/* @0xe1bc8 strd r4, r5, [r10] */
/* @0xe1bcc b 0xe1a50 <_Z5DoShrjPhPKhP6VMExec+0x4e8> */
/* @0xe1bd0 ldrd r0, r1, [r6] */
/* @0xe1bd4 bl 0x3194a0 <__fixdfdi> */
/* @0xe1bd8 mov r6, r1 */
/* @0xe1bdc mov r7, r0 */
/* @0xe1be0 ldrd r0, r1, [r11] */
/* @0xe1be4 bl 0x3194a0 <__fixdfdi> */
/* @0xe1be8 lsr r2, r7, r0 */
/* @0xe1bec rsb r1, r0, #32 */
/* @0xe1bf0 subs r12, r0, #32 */
/* @0xe1bf4 orr r2, r2, r6, lsl r1 */
/* @0xe1bf8 orrpl r2, r2, r6, asr r12 */
/* @0xe1bfc asr r3, r6, r0 */
/* @0xe1c00 b 0xe1a3c <_Z5DoShrjPhPKhP6VMExec+0x4d4> */
/* @0xe1c04 ldrd r0, r1, [r11] */
/* @0xe1c08 bl 0x3194a0 <__fixdfdi> */
/* @0xe1c0c ldr lr, [r6] */
/* @0xe1c10 ldr r1, [r6, #0x4] */
/* @0xe1c14 rsb r12, r0, #32 */
/* @0xe1c18 lsr r2, lr, r0 */
/* @0xe1c1c subs r6, r0, #32 */
/* @0xe1c20 orr r2, r2, r1, lsl r12 */
/* @0xe1c24 orrpl r2, r2, r1, asr r6 */
/* @0xe1c28 asr r3, r1, r0 */
/* @0xe1c2c b 0xe1a3c <_Z5DoShrjPhPKhP6VMExec+0x4d4> */
/* @0xe1c30 ldr r0, [r6] */
/* @0xe1c34 ldr r1, [r11] */
/* @0xe1c38 asr r3, r0, #31 */
/* @0xe1c3c lsr r6, r0, r1 */
/* @0xe1c40 rsb r0, r1, #32 */
/* @0xe1c44 subs r12, r1, #32 */
/* @0xe1c48 orr r6, r6, r3, lsl r0 */
/* @0xe1c4c asr r7, r3, r1 */
/* @0xe1c50 orrpl r6, r6, r3, asr r12 */
/* @0xe1c54 and r5, r5, r7 */
/* @0xe1c58 and r4, r4, r6 */
/* @0xe1c5c mov r12, #10 */
/* @0xe1c60 strd r4, r5, [r10] */
/* @0xe1c64 b 0xe1a50 <_Z5DoShrjPhPKhP6VMExec+0x4e8> */
/* @0xe1c68 ldr r0, [r6] */
/* @0xe1c6c mov r12, #7 */
/* @0xe1c70 ldr r3, [r11] */
/* @0xe1c74 and r7, r7, r0, asr r3 */
/* @0xe1c78 str r7, [r10] */
/* @0xe1c7c b 0xe1a50 <_Z5DoShrjPhPKhP6VMExec+0x4e8> */
/* @0xe1c80 ldrd r0, r1, [r11] */
/* @0xe1c84 bl 0x3194a0 <__fixdfdi> */
/* @0xe1c88 ldr r3, [r6] */
/* @0xe1c8c mov r12, #0 */
/* @0xe1c90 and r0, r7, r3, asr r0 */
/* @0xe1c94 vmov s11, r0 */
/* @0xe1c98 vcvt.f64.u32 d7, s11 */
/* @0xe1c9c vstr d7, [r10] */
/* @0xe1ca0 b 0xe1a50 <_Z5DoShrjPhPKhP6VMExec+0x4e8> */
/* @0xe1ca4 ldr r1, [pc, #0x26c] */
/* @0xe1ca8 mov r0, r3 */
/* @0xe1cac add r1, pc, r1 */
/* @0xe1cb0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe1cb4 mov r12, #0 */
/* @0xe1cb8 b 0xe1a50 <_Z5DoShrjPhPKhP6VMExec+0x4e8> */
/* @0xe1cbc and r2, r2, #15 */
/* @0xe1cc0 orr r2, r2, #48 */
/* @0xe1cc4 add r8, r6, #16 */
/* @0xe1cc8 b 0xe16d8 <_Z5DoShrjPhPKhP6VMExec+0x170> */
/* @0xe1ccc and r2, r2, #15 */
/* @0xe1cd0 orr r2, r2, #32 */
/* @0xe1cd4 b 0xe1cc4 <_Z5DoShrjPhPKhP6VMExec+0x75c> */
/* @0xe1cd8 ldr r1, [pc, #0x23c] */
/* @0xe1cdc mov r0, r3 */
/* @0xe1ce0 add r1, pc, r1 */
/* @0xe1ce4 str r2, [sp, #0x4] */
/* @0xe1ce8 str r3, [sp] */
/* @0xe1cec bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe1cf0 ldr r2, [sp, #0x4] */
/* @0xe1cf4 ldr r3, [sp] */
/* @0xe1cf8 b 0xe1cc4 <_Z5DoShrjPhPKhP6VMExec+0x75c> */
/* @0xe1cfc ldr r1, [pc, #0x21c] */
/* @0xe1d00 mov r0, r3 */
/* @0xe1d04 add r1, pc, r1 */
/* @0xe1d08 b 0xe1ce4 <_Z5DoShrjPhPKhP6VMExec+0x77c> */
/* @0xe1d0c and r2, r2, #15 */
/* @0xe1d10 b 0xe1cc4 <_Z5DoShrjPhPKhP6VMExec+0x75c> */
/* @0xe1d14 ldr r1, [pc, #0x208] */
/* @0xe1d18 mov r0, r3 */
/* @0xe1d1c add r1, pc, r1 */
/* @0xe1d20 b 0xe1ce4 <_Z5DoShrjPhPKhP6VMExec+0x77c> */
/* @0xe1d24 ldr r1, [pc, #0x1fc] */
/* @0xe1d28 mov r0, r3 */
/* @0xe1d2c add r1, pc, r1 */
/* @0xe1d30 b 0xe1ce4 <_Z5DoShrjPhPKhP6VMExec+0x77c> */
/* @0xe1d34 and r2, r2, #240 */
/* @0xe1d38 orr r2, r2, #3 */
/* @0xe1d3c add r6, r11, #16 */
/* @0xe1d40 b 0xe1688 <_Z5DoShrjPhPKhP6VMExec+0x120> */
/* @0xe1d44 and r2, r2, #240 */
/* @0xe1d48 orr r2, r2, #2 */
/* @0xe1d4c b 0xe1d3c <_Z5DoShrjPhPKhP6VMExec+0x7d4> */
/* @0xe1d50 ldr r1, [pc, #0x1d4] */
/* @0xe1d54 mov r0, r3 */
/* @0xe1d58 str r3, [sp] */
/* @0xe1d5c add r1, pc, r1 */
/* @0xe1d60 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe1d64 mov r2, r4 */
/* @0xe1d68 ldr r3, [sp] */
/* @0xe1d6c b 0xe1d3c <_Z5DoShrjPhPKhP6VMExec+0x7d4> */
/* @0xe1d70 ldr r1, [pc, #0x1b8] */
/* @0xe1d74 mov r0, r3 */
/* @0xe1d78 str r3, [sp] */
/* @0xe1d7c add r1, pc, r1 */
/* @0xe1d80 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe1d84 mov r2, r4 */
/* @0xe1d88 ldr r3, [sp] */
/* @0xe1d8c b 0xe1d3c <_Z5DoShrjPhPKhP6VMExec+0x7d4> */
/* @0xe1d90 ldr r1, [pc, #0x19c] */
/* @0xe1d94 mov r0, r3 */
/* @0xe1d98 str r3, [sp] */
/* @0xe1d9c add r1, pc, r1 */
/* @0xe1da0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe1da4 mov r2, r4 */
/* @0xe1da8 ldr r3, [sp] */
/* @0xe1dac b 0xe1d3c <_Z5DoShrjPhPKhP6VMExec+0x7d4> */
/* @0xe1db0 ldr r1, [pc, #0x180] */
/* @0xe1db4 mov r0, r3 */
/* @0xe1db8 str r3, [sp] */
/* @0xe1dbc add r1, pc, r1 */
/* @0xe1dc0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe1dc4 mov r2, r4 */
/* @0xe1dc8 ldr r3, [sp] */
/* @0xe1dcc b 0xe1d3c <_Z5DoShrjPhPKhP6VMExec+0x7d4> */
/* @0xe1dd0 and r2, r4, #240 */
/* @0xe1dd4 b 0xe1d3c <_Z5DoShrjPhPKhP6VMExec+0x7d4> */
/* @0xe1dd8 ldr r1, [pc, #0x15c] */
/* @0xe1ddc mov r0, r3 */
/* @0xe1de0 str r2, [sp, #0x4] */
/* @0xe1de4 add r1, pc, r1 */
/* @0xe1de8 str r3, [sp] */
/* @0xe1dec bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe1df0 ldr r3, [sp] */
/* @0xe1df4 ldr r2, [sp, #0x4] */
/* @0xe1df8 b 0xe1cc4 <_Z5DoShrjPhPKhP6VMExec+0x75c> */
/* @0xe1dfc ldr r1, [pc, #0x13c] */
/* @0xe1e00 mov r0, r3 */
/* @0xe1e04 str r3, [sp] */
/* @0xe1e08 add r1, pc, r1 */
/* @0xe1e0c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe1e10 mov r2, r4 */
/* @0xe1e14 ldr r3, [sp] */
/* @0xe1e18 b 0xe1d3c <_Z5DoShrjPhPKhP6VMExec+0x7d4> */
/* @0xe1e1c ldr r0, [pc, #0x120] */
/* @0xe1e20 add r0, pc, r0 */
/* @0xe1e24 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe1e28 mov r0, r4 */
/* @0xe1e2c b 0xe1a60 <_Z5DoShrjPhPKhP6VMExec+0x4f8> */
/* @0xe1e30 ldr r0, [pc, #0x110] */
/* @0xe1e34 add r0, pc, r0 */
/* @0xe1e38 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe1e3c mov r0, r4 */
/* @0xe1e40 b 0xe1a60 <_Z5DoShrjPhPKhP6VMExec+0x4f8> */
/* @0xe1e44 add r7, sp, #56 */
/* @0xe1e48 mov r1, r5 */
/* @0xe1e4c mov r0, r7 */
/* @0xe1e50 bl 0x24d4f4 <_Z13F_JS_ToUint32R6RValueS0_> */
/* @0xe1e54 cmp r0, #1 */
/* @0xe1e58 beq 0xe1edc <_Z5DoShrjPhPKhP6VMExec+0x974> */
/* @0xe1e5c cmp r0, #0 */
/* @0xe1e60 bne 0xe165c <_Z5DoShrjPhPKhP6VMExec+0xf4> */
/* @0xe1e64 vldr d6, [sp, #56] */
/* @0xe1e68 vcvt.u32.f64 s11, d6 */
/* @0xe1e6c vldr d7, [sp, #40] */
/* @0xe1e70 ldr r2, [sp, #0x34] */
/* @0xe1e74 sub r2, r2, #1 */
/* @0xe1e78 bic r2, r2, #-16777216 */
/* @0xe1e7c bic r2, r2, #3 */
/* @0xe1e80 cmp r2, #0 */
/* @0xe1e84 vcvt.s32.f64 s14, d7 */
/* @0xe1e88 vmov r3, s11 */
/* @0xe1e8c vmov r0, s14 */
/* @0xe1e90 and r3, r3, #31 */
/* @0xe1e94 asr r3, r0, r3 */
/* @0xe1e98 vmov s15, r3 */
/* @0xe1e9c vcvt.f64.s32 d7, s15 */
/* @0xe1ea0 vmov r2, r3, d7 */
/* @0xe1ea4 vstr s14, [r4, #-16] */
/* @0xe1ea8 str r3, [r4, #-0xc] */
/* @0xe1eac bne 0xe1b18 <_Z5DoShrjPhPKhP6VMExec+0x5b0> */
/* @0xe1eb0 mov r0, r6 */
/* @0xe1eb4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe1eb8 b 0xe1b18 <_Z5DoShrjPhPKhP6VMExec+0x5b0> */
/* @0xe1ebc ldr r0, [pc, #0x88] */
/* @0xe1ec0 add r0, pc, r0 */
/* @0xe1ec4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe1ec8 b 0xe165c <_Z5DoShrjPhPKhP6VMExec+0xf4> */
/* @0xe1ecc ldr r0, [pc, #0x7c] */
/* @0xe1ed0 add r0, pc, r0 */
/* @0xe1ed4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe1ed8 b 0xe165c <_Z5DoShrjPhPKhP6VMExec+0xf4> */
/* @0xe1edc ldr r0, [pc, #0x70] */
/* @0xe1ee0 add r0, pc, r0 */
/* @0xe1ee4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe1ee8 b 0xe165c <_Z5DoShrjPhPKhP6VMExec+0xf4> */
/* @0xe1eec ldr r0, [pc, #0x64] */
/* @0xe1ef0 add r0, pc, r0 */
/* @0xe1ef4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe1ef8 b 0xe165c <_Z5DoShrjPhPKhP6VMExec+0xf4> */
/* @0xe1efc mov r8, r6 */
/* @0xe1f00 b 0xe16d8 <_Z5DoShrjPhPKhP6VMExec+0x170> */
/* @0xe1f04 mov r2, r4 */
/* @0xe1f08 mov r6, r11 */
/* @0xe1f0c b 0xe1688 <_Z5DoShrjPhPKhP6VMExec+0x120> */
/* @0xe1f10 eoreq r2, r5, r8, lsr r11 */
/* @0xe1f14 eoreq r2, r5, r0, lsr #23 */
/* @0xe1f18 eoreq r2, r5, r12, ror #12 */
/* @0xe1f1c .word 0x002525fc */
/* @0xe1f20 eoreq r2, r5, r0, ror #10 */
/* @0xe1f24 eoreq r2, r5, r4, lsr #11 */
/* @0xe1f28 eoreq r2, r5, r4, ror r5 */
/* @0xe1f2c .word 0x002524b0 */
/* @0xe1f30 eoreq r2, r5, r0, ror r4 */
/* @0xe1f34 eoreq r2, r5, r12, lsl #9 */
/* @0xe1f38 .word 0x002523f4 */
/* @0xe1f3c eoreq r2, r5, r4, lsl r5 */
/* @0xe1f40 eoreq r2, r5, r12, lsr r4 */
/* @0xe1f44 eoreq r2, r5, r8, ror r2 */
/* @0xe1f48 eoreq r2, r5, r8, lsl #5 */
/* @0xe1f4c eoreq r2, r5, r0, lsr #4 */
/* @0xe1f50 eoreq r2, r5, r8, ror r2 */
/* @0xe1f54 mlaeq r5, r12, r2, r2 */
/* @0xe1f58 eoreq r2, r5, r4, lsr #4 */

/* ── FUNC 0xe1f5c · DoPopLocalVariable(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=184 · insn=46 */
/* @0xe1f5c push {r3, r4, r5, r6, r7, lr} */
/* @0xe1f60 mov r4, r1 */
/* @0xe1f64 ldr r6, [r2] */
/* @0xe1f68 ldr r5, [r3, #0x10] */
/* @0xe1f6c cmp r6, #0 */
/* @0xe1f70 ldrge r7, [r4], #4 */
/* @0xe1f74 movlt r7, #-2147483648 */
/* @0xe1f78 tst r6, #536870912 */
/* @0xe1f7c addeq r4, r4, #4 */
/* @0xe1f80 cmp r5, #0 */
/* @0xe1f84 beq 0xe1fa0 <_Z18DoPopLocalVariablejPhPKhP6VMExec+0x44> */
/* @0xe1f88 mov r0, r5 */
/* @0xe1f8c bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0xe1f90 ldr r3, [r5, #0x24] */
/* @0xe1f94 cmp r3, #0 */
/* @0xe1f98 bne 0xe1fdc <_Z18DoPopLocalVariablejPhPKhP6VMExec+0x80> */
/* @0xe1f9c bl 0xd3a34 <_Z15PopContextStackv> */
/* @0xe1fa0 ldr r3, [r4, #0xc] */
/* @0xe1fa4 sub r3, r3, #1 */
/* @0xe1fa8 bic r3, r3, #-16777216 */
/* @0xe1fac bic r3, r3, #3 */
/* @0xe1fb0 cmp r3, #0 */
/* @0xe1fb4 bne 0xe1fc0 <_Z18DoPopLocalVariablejPhPKhP6VMExec+0x64> */
/* @0xe1fb8 mov r0, r4 */
/* @0xe1fbc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe1fc0 mov r0, r4 */
/* @0xe1fc4 mov r3, #0 */
/* @0xe1fc8 mov r2, #5 */
/* @0xe1fcc str r3, [r4, #0x8] */
/* @0xe1fd0 str r2, [r4, #0xc] */
/* @0xe1fd4 str r3, [r0], #16 */
/* @0xe1fd8 pop {r3, r4, r5, r6, r7, pc} */
/* @0xe1fdc ldr r3, [r5, #0x4] */
/* @0xe1fe0 bic r6, r6, #-268435456 */
/* @0xe1fe4 sub r6, r6, #99328 */
/* @0xe1fe8 cmp r3, #0 */
/* @0xe1fec sub r1, r6, #672 */
/* @0xe1ff0 beq 0xe2008 <_Z18DoPopLocalVariablejPhPKhP6VMExec+0xac> */
/* @0xe1ff4 add r0, r3, r1, lsl #4 */
/* @0xe1ff8 mov r2, r7 */
/* @0xe1ffc mov r1, r4 */
/* @0xe2000 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0xe2004 b 0xe1f9c <_Z18DoPopLocalVariablejPhPKhP6VMExec+0x40> */
/* @0xe2008 mov r0, r5 */
/* @0xe200c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe2010 b 0xe1ff8 <_Z18DoPopLocalVariablejPhPKhP6VMExec+0x9c> */

/* ── FUNC 0xe2014 · DoSet(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=7452 · insn=1863 */
/* @0xe2014 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe2018 ubfx r9, r0, #0x8, #0x4 */
/* @0xe201c sub r11, r9, #7 */
/* @0xe2020 ldr r6, [pc, #0xfd4] */
/* @0xe2024 sub sp, sp, #68 */
/* @0xe2028 mov r10, r1 */
/* @0xe202c uxtb r11, r11 */
/* @0xe2030 mov r8, r3 */
/* @0xe2034 cmp r11, #3 */
/* @0xe2038 lsr r12, r0, #16 */
/* @0xe203c add r6, pc, r6 */
/* @0xe2040 bhi 0xe215c <_Z5DoSetjPhPKhP6VMExec+0x148> */
/* @0xe2044 sub r9, r9, #8 */
/* @0xe2048 cmp r9, #1 */
/* @0xe204c bhi 0xe21d4 <_Z5DoSetjPhPKhP6VMExec+0x1c0> */
/* @0xe2050 add r6, sp, #16 */
/* @0xe2054 uxtb r4, r12 */
/* @0xe2058 mov r2, r1 */
/* @0xe205c and r1, r4, #15 */
/* @0xe2060 mov r0, r6 */
/* @0xe2064 add r7, sp, #32 */
/* @0xe2068 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe206c lsr r1, r4, #4 */
/* @0xe2070 mov r2, r0 */
/* @0xe2074 mov r0, r7 */
/* @0xe2078 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe207c mov r3, #0 */
/* @0xe2080 mov r8, r0 */
/* @0xe2084 ldr r2, [sp, #0x1c] */
/* @0xe2088 mvn r12, #-16777216 */
/* @0xe208c and r2, r2, r12 */
/* @0xe2090 cmp r2, r12 */
/* @0xe2094 beq 0xe2544 <_Z5DoSetjPhPKhP6VMExec+0x530> */
/* @0xe2098 ldr r2, [sp, #0x2c] */
/* @0xe209c bic r2, r2, #-16777216 */
/* @0xe20a0 cmp r2, r12 */
/* @0xe20a4 beq 0xe24dc <_Z5DoSetjPhPKhP6VMExec+0x4c8> */
/* @0xe20a8 add r0, sp, #48 */
/* @0xe20ac mov r1, r6 */
/* @0xe20b0 mov r2, r7 */
/* @0xe20b4 str r12, [sp, #0x3c] */
/* @0xe20b8 mov r4, #0 */
/* @0xe20bc mov r12, #0 */
/* @0xe20c0 mov r5, #0 */
/* @0xe20c4 str r12, [sp, #0x38] */
/* @0xe20c8 strd r4, r5, [sp, #48] */
/* @0xe20cc bl 0x25a518 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b> */
/* @0xe20d0 cmp r0, #0 */
/* @0xe20d4 bne 0xe247c <_Z5DoSetjPhPKhP6VMExec+0x468> */
/* @0xe20d8 cmp r11, #1 */
/* @0xe20dc ldr r3, [sp, #0x3c] */
/* @0xe20e0 sub r4, r8, #4 */
/* @0xe20e4 bls 0xe2458 <_Z5DoSetjPhPKhP6VMExec+0x444> */
/* @0xe20e8 cmp r3, #5 */
/* @0xe20ec beq 0xe2104 <_Z5DoSetjPhPKhP6VMExec+0xf0> */
/* @0xe20f0 vmov.f64 d6, #1.000000e+00 */
/* @0xe20f4 vldr d7, [sp, #48] */
/* @0xe20f8 vcmp.f64 d7, d6 */
/* @0xe20fc vmrs APSR_nzcv, fpscr */
/* @0xe2100 bne 0xe2470 <_Z5DoSetjPhPKhP6VMExec+0x45c> */
/* @0xe2104 mov r3, #0 */
/* @0xe2108 str r3, [r8, #-0x4] */
/* @0xe210c ldr r3, [sp, #0x1c] */
/* @0xe2110 sub r3, r3, #1 */
/* @0xe2114 bic r3, r3, #-16777216 */
/* @0xe2118 bic r3, r3, #3 */
/* @0xe211c cmp r3, #0 */
/* @0xe2120 beq 0xe2564 <_Z5DoSetjPhPKhP6VMExec+0x550> */
/* @0xe2124 ldr r1, [sp, #0x2c] */
/* @0xe2128 mov r3, #0 */
/* @0xe212c str r3, [sp, #0x18] */
/* @0xe2130 mov r2, #5 */
/* @0xe2134 sub r1, r1, #1 */
/* @0xe2138 str r3, [sp, #0x10] */
/* @0xe213c bic r3, r1, #-16777216 */
/* @0xe2140 str r2, [sp, #0x1c] */
/* @0xe2144 bic r3, r3, #3 */
/* @0xe2148 cmp r3, #0 */
/* @0xe214c beq 0xe2558 <_Z5DoSetjPhPKhP6VMExec+0x544> */
/* @0xe2150 mov r0, r4 */
/* @0xe2154 add sp, sp, #68 */
/* @0xe2158 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe215c sub r3, r9, #12 */
/* @0xe2160 cmp r3, #1 */
/* @0xe2164 bls 0xe23bc <_Z5DoSetjPhPKhP6VMExec+0x3a8> */
/* @0xe2168 sub r3, r9, #14 */
/* @0xe216c cmp r3, #1 */
/* @0xe2170 bls 0xe2570 <_Z5DoSetjPhPKhP6VMExec+0x55c> */
/* @0xe2174 cmp r9, #11 */
/* @0xe2178 beq 0xe2684 <_Z5DoSetjPhPKhP6VMExec+0x670> */
/* @0xe217c uxtb r11, r12 */
/* @0xe2180 mov r4, #0 */
/* @0xe2184 and r3, r11, #15 */
/* @0xe2188 mov r5, #0 */
/* @0xe218c mov r1, #0 */
/* @0xe2190 mvn r2, #-16777216 */
/* @0xe2194 strd r4, r5, [sp, #32] */
/* @0xe2198 strd r4, r5, [sp, #48] */
/* @0xe219c str r1, [sp, #0x28] */
/* @0xe21a0 str r1, [sp, #0x38] */
/* @0xe21a4 str r2, [sp, #0x2c] */
/* @0xe21a8 str r2, [sp, #0x3c] */
/* @0xe21ac cmp r3, #6 */
/* @0xe21b0 addls pc, pc, r3, lsl #2 */
/* @0xe21b4 b 0xe3d28 <_Z5DoSetjPhPKhP6VMExec+0x1d14> */
/* @0xe21b8 b 0xe23ac <_Z5DoSetjPhPKhP6VMExec+0x398> */
/* @0xe21bc b 0xe23a4 <_Z5DoSetjPhPKhP6VMExec+0x390> */
/* @0xe21c0 b 0xe23a4 <_Z5DoSetjPhPKhP6VMExec+0x390> */
/* @0xe21c4 b 0xe23ac <_Z5DoSetjPhPKhP6VMExec+0x398> */
/* @0xe21c8 b 0xe23a4 <_Z5DoSetjPhPKhP6VMExec+0x390> */
/* @0xe21cc b 0xe2340 <_Z5DoSetjPhPKhP6VMExec+0x32c> */
/* @0xe21d0 b 0xe220c <_Z5DoSetjPhPKhP6VMExec+0x1f8> */
/* @0xe21d4 add r7, sp, #32 */
/* @0xe21d8 uxtb r4, r12 */
/* @0xe21dc mov r2, r1 */
/* @0xe21e0 and r1, r4, #15 */
/* @0xe21e4 mov r0, r7 */
/* @0xe21e8 add r6, sp, #16 */
/* @0xe21ec bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe21f0 lsr r1, r4, #4 */
/* @0xe21f4 mov r2, r0 */
/* @0xe21f8 mov r0, r6 */
/* @0xe21fc bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe2200 mov r3, #1 */
/* @0xe2204 mov r8, r0 */
/* @0xe2208 b 0xe2084 <_Z5DoSetjPhPKhP6VMExec+0x70> */
/* @0xe220c mov r4, r10 */
/* @0xe2210 add r10, sp, #64 */
/* @0xe2214 ldr r3, [r4], #4 */
/* @0xe2218 mov r2, #1 */
/* @0xe221c str r2, [sp, #0x2c] */
/* @0xe2220 str r3, [r10, #-0x20]! */
/* @0xe2224 asr r3, r11, #4 */
/* @0xe2228 cmp r3, #6 */
/* @0xe222c addls pc, pc, r3, lsl #2 */
/* @0xe2230 b 0xe3d20 <_Z5DoSetjPhPKhP6VMExec+0x1d0c> */
/* @0xe2234 b 0xe23b4 <_Z5DoSetjPhPKhP6VMExec+0x3a0> */
/* @0xe2238 b 0xe2338 <_Z5DoSetjPhPKhP6VMExec+0x324> */
/* @0xe223c b 0xe2338 <_Z5DoSetjPhPKhP6VMExec+0x324> */
/* @0xe2240 b 0xe23b4 <_Z5DoSetjPhPKhP6VMExec+0x3a0> */
/* @0xe2244 b 0xe2338 <_Z5DoSetjPhPKhP6VMExec+0x324> */
/* @0xe2248 b 0xe22d4 <_Z5DoSetjPhPKhP6VMExec+0x2c0> */
/* @0xe224c b 0xe2250 <_Z5DoSetjPhPKhP6VMExec+0x23c> */
/* @0xe2250 mov r7, r4 */
/* @0xe2254 add r4, sp, #64 */
/* @0xe2258 ldr r3, [r7], #4 */
/* @0xe225c mov r2, #1 */
/* @0xe2260 str r2, [sp, #0x3c] */
/* @0xe2264 str r3, [r4, #-0x10]! */
/* @0xe2268 cmp r11, #48 */
/* @0xe226c sub r8, r7, #4 */
/* @0xe2270 beq 0xe3524 <_Z5DoSetjPhPKhP6VMExec+0x1510> */
/* @0xe2274 bls 0xe2488 <_Z5DoSetjPhPKhP6VMExec+0x474> */
/* @0xe2278 cmp r11, #68 */
/* @0xe227c beq 0xe37b4 <_Z5DoSetjPhPKhP6VMExec+0x17a0> */
/* @0xe2280 bls 0xe24f4 <_Z5DoSetjPhPKhP6VMExec+0x4e0> */
/* @0xe2284 cmp r11, #100 */
/* @0xe2288 beq 0xe3650 <_Z5DoSetjPhPKhP6VMExec+0x163c> */
/* @0xe228c bls 0xe2798 <_Z5DoSetjPhPKhP6VMExec+0x784> */
/* @0xe2290 cmp r11, #102 */
/* @0xe2294 beq 0xe31c0 <_Z5DoSetjPhPKhP6VMExec+0x11ac> */
/* @0xe2298 cmp r11, #255 */
/* @0xe229c bne 0xe33c0 <_Z5DoSetjPhPKhP6VMExec+0x13ac> */
/* @0xe22a0 ldr r2, [r4] */
/* @0xe22a4 sub r9, r9, #1 */
/* @0xe22a8 ldr r3, [r10] */
/* @0xe22ac rsb r3, r3, r2 */
/* @0xe22b0 cmp r9, #5 */
/* @0xe22b4 addls pc, pc, r9, lsl #2 */
/* @0xe22b8 b 0xe3bf4 <_Z5DoSetjPhPKhP6VMExec+0x1be0> */
/* @0xe22bc b 0xe3098 <_Z5DoSetjPhPKhP6VMExec+0x1084> */
/* @0xe22c0 b 0xe3070 <_Z5DoSetjPhPKhP6VMExec+0x105c> */
/* @0xe22c4 b 0xe3034 <_Z5DoSetjPhPKhP6VMExec+0x1020> */
/* @0xe22c8 b 0xe2fc0 <_Z5DoSetjPhPKhP6VMExec+0xfac> */
/* @0xe22cc b 0xe2f94 <_Z5DoSetjPhPKhP6VMExec+0xf80> */
/* @0xe22d0 b 0xe2f6c <_Z5DoSetjPhPKhP6VMExec+0xf58> */
/* @0xe22d4 ldr r3, [r4, #0xc] */
/* @0xe22d8 add r5, sp, #48 */
/* @0xe22dc ldr r0, [r4] */
/* @0xe22e0 ldr r1, [r4, #0x4] */
/* @0xe22e4 mov r12, r5 */
/* @0xe22e8 ldr r2, [r4, #0x8] */
/* @0xe22ec stm r12!, {r0, r1, r2, r3} */
/* @0xe22f0 ldr r3, [sp, #0x3c] */
/* @0xe22f4 cmp r3, #13 */
/* @0xe22f8 addls pc, pc, r3, lsl #2 */
/* @0xe22fc b 0xe28b8 <_Z5DoSetjPhPKhP6VMExec+0x8a4> */
/* @0xe2300 b 0xe2884 <_Z5DoSetjPhPKhP6VMExec+0x870> */
/* @0xe2304 b 0xe2878 <_Z5DoSetjPhPKhP6VMExec+0x864> */
/* @0xe2308 b 0xe2704 <_Z5DoSetjPhPKhP6VMExec+0x6f0> */
/* @0xe230c b 0xe2704 <_Z5DoSetjPhPKhP6VMExec+0x6f0> */
/* @0xe2310 b 0xe28b8 <_Z5DoSetjPhPKhP6VMExec+0x8a4> */
/* @0xe2314 b 0xe285c <_Z5DoSetjPhPKhP6VMExec+0x848> */
/* @0xe2318 b 0xe2704 <_Z5DoSetjPhPKhP6VMExec+0x6f0> */
/* @0xe231c b 0xe2704 <_Z5DoSetjPhPKhP6VMExec+0x6f0> */
/* @0xe2320 b 0xe28b8 <_Z5DoSetjPhPKhP6VMExec+0x8a4> */
/* @0xe2324 b 0xe28b8 <_Z5DoSetjPhPKhP6VMExec+0x8a4> */
/* @0xe2328 b 0xe286c <_Z5DoSetjPhPKhP6VMExec+0x858> */
/* @0xe232c b 0xe28b8 <_Z5DoSetjPhPKhP6VMExec+0x8a4> */
/* @0xe2330 b 0xe28b8 <_Z5DoSetjPhPKhP6VMExec+0x8a4> */
/* @0xe2334 b 0xe2884 <_Z5DoSetjPhPKhP6VMExec+0x870> */
/* @0xe2338 add r7, r4, #4 */
/* @0xe233c b 0xe2268 <_Z5DoSetjPhPKhP6VMExec+0x254> */
/* @0xe2340 ldr r3, [r10, #0xc] */
/* @0xe2344 add r7, sp, #32 */
/* @0xe2348 ldr r0, [r10] */
/* @0xe234c ldr r1, [r10, #0x4] */
/* @0xe2350 mov r4, r7 */
/* @0xe2354 ldr r2, [r10, #0x8] */
/* @0xe2358 stm r4!, {r0, r1, r2, r3} */
/* @0xe235c ldr r3, [sp, #0x2c] */
/* @0xe2360 cmp r3, #13 */
/* @0xe2364 addls pc, pc, r3, lsl #2 */
/* @0xe2368 b 0xe28a0 <_Z5DoSetjPhPKhP6VMExec+0x88c> */
/* @0xe236c b 0xe2864 <_Z5DoSetjPhPKhP6VMExec+0x850> */
/* @0xe2370 b 0xe2850 <_Z5DoSetjPhPKhP6VMExec+0x83c> */
/* @0xe2374 b 0xe26f0 <_Z5DoSetjPhPKhP6VMExec+0x6dc> */
/* @0xe2378 b 0xe26f0 <_Z5DoSetjPhPKhP6VMExec+0x6dc> */
/* @0xe237c b 0xe28a0 <_Z5DoSetjPhPKhP6VMExec+0x88c> */
/* @0xe2380 b 0xe283c <_Z5DoSetjPhPKhP6VMExec+0x828> */
/* @0xe2384 b 0xe26f0 <_Z5DoSetjPhPKhP6VMExec+0x6dc> */
/* @0xe2388 b 0xe26f0 <_Z5DoSetjPhPKhP6VMExec+0x6dc> */
/* @0xe238c b 0xe28a0 <_Z5DoSetjPhPKhP6VMExec+0x88c> */
/* @0xe2390 b 0xe28a0 <_Z5DoSetjPhPKhP6VMExec+0x88c> */
/* @0xe2394 b 0xe2844 <_Z5DoSetjPhPKhP6VMExec+0x830> */
/* @0xe2398 b 0xe28a0 <_Z5DoSetjPhPKhP6VMExec+0x88c> */
/* @0xe239c b 0xe28a0 <_Z5DoSetjPhPKhP6VMExec+0x88c> */
/* @0xe23a0 b 0xe2864 <_Z5DoSetjPhPKhP6VMExec+0x850> */
/* @0xe23a4 add r4, r10, #4 */
/* @0xe23a8 b 0xe2224 <_Z5DoSetjPhPKhP6VMExec+0x210> */
/* @0xe23ac add r4, r10, #8 */
/* @0xe23b0 b 0xe2224 <_Z5DoSetjPhPKhP6VMExec+0x210> */
/* @0xe23b4 add r7, r4, #8 */
/* @0xe23b8 b 0xe2268 <_Z5DoSetjPhPKhP6VMExec+0x254> */
/* @0xe23bc add r7, sp, #32 */
/* @0xe23c0 uxtb r4, r12 */
/* @0xe23c4 mov r2, r1 */
/* @0xe23c8 and r1, r4, #15 */
/* @0xe23cc mov r0, r7 */
/* @0xe23d0 add r6, sp, #16 */
/* @0xe23d4 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe23d8 lsr r1, r4, #4 */
/* @0xe23dc mov r2, r0 */
/* @0xe23e0 mov r0, r6 */
/* @0xe23e4 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe23e8 ldr r2, [sp, #0x1c] */
/* @0xe23ec mvn r3, #-16777216 */
/* @0xe23f0 and r2, r2, r3 */
/* @0xe23f4 cmp r2, r3 */
/* @0xe23f8 mov r8, r0 */
/* @0xe23fc beq 0xe3b5c <_Z5DoSetjPhPKhP6VMExec+0x1b48> */
/* @0xe2400 ldr r2, [sp, #0x2c] */
/* @0xe2404 bic r2, r2, #-16777216 */
/* @0xe2408 cmp r2, r3 */
/* @0xe240c beq 0xe2814 <_Z5DoSetjPhPKhP6VMExec+0x800> */
/* @0xe2410 add r0, sp, #48 */
/* @0xe2414 mov r1, r6 */
/* @0xe2418 mov r2, r7 */
/* @0xe241c mov r3, #5 */
/* @0xe2420 str r3, [sp, #0x3c] */
/* @0xe2424 bl 0x25a814 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_> */
/* @0xe2428 cmp r0, #0 */
/* @0xe242c bne 0xe247c <_Z5DoSetjPhPKhP6VMExec+0x468> */
/* @0xe2430 cmp r9, #12 */
/* @0xe2434 vldr d7, [sp, #48] */
/* @0xe2438 sub r4, r8, #4 */
/* @0xe243c vcmp.f64 d7, #0 */
/* @0xe2440 beq 0xe3bc0 <_Z5DoSetjPhPKhP6VMExec+0x1bac> */
/* @0xe2444 vmrs APSR_nzcv, fpscr */
/* @0xe2448 movne r3, #0 */
/* @0xe244c moveq r3, #1 */
/* @0xe2450 str r3, [r8, #-0x4] */
/* @0xe2454 b 0xe210c <_Z5DoSetjPhPKhP6VMExec+0xf8> */
/* @0xe2458 cmp r3, #5 */
/* @0xe245c beq 0xe2104 <_Z5DoSetjPhPKhP6VMExec+0xf0> */
/* @0xe2460 vldr d7, [sp, #48] */
/* @0xe2464 vcmp.f64 d7, #0 */
/* @0xe2468 vmrs APSR_nzcv, fpscr */
/* @0xe246c beq 0xe2104 <_Z5DoSetjPhPKhP6VMExec+0xf0> */
/* @0xe2470 mov r3, #1 */
/* @0xe2474 str r3, [r8, #-0x4] */
/* @0xe2478 b 0xe210c <_Z5DoSetjPhPKhP6VMExec+0xf8> */
/* @0xe247c mov r0, r8 */
/* @0xe2480 add sp, sp, #68 */
/* @0xe2484 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe2488 cmp r11, #4 */
/* @0xe248c beq 0xe3274 <_Z5DoSetjPhPKhP6VMExec+0x1260> */
/* @0xe2490 bhi 0xe2638 <_Z5DoSetjPhPKhP6VMExec+0x624> */
/* @0xe2494 cmp r11, #2 */
/* @0xe2498 beq 0xe27dc <_Z5DoSetjPhPKhP6VMExec+0x7c8> */
/* @0xe249c bhi 0xe33f8 <_Z5DoSetjPhPKhP6VMExec+0x13e4> */
/* @0xe24a0 cmp r11, #0 */
/* @0xe24a4 bne 0xe33c0 <_Z5DoSetjPhPKhP6VMExec+0x13ac> */
/* @0xe24a8 sub r9, r9, #1 */
/* @0xe24ac vldr d6, [r4] */
/* @0xe24b0 vldr d7, [r10] */
/* @0xe24b4 vsub.f64 d7, d6, d7 */
/* @0xe24b8 cmp r9, #5 */
/* @0xe24bc addls pc, pc, r9, lsl #2 */
/* @0xe24c0 b 0xe3c74 <_Z5DoSetjPhPKhP6VMExec+0x1c60> */
/* @0xe24c4 b 0xe2e40 <_Z5DoSetjPhPKhP6VMExec+0xe2c> */
/* @0xe24c8 b 0xe2e20 <_Z5DoSetjPhPKhP6VMExec+0xe0c> */
/* @0xe24cc b 0xe2dec <_Z5DoSetjPhPKhP6VMExec+0xdd8> */
/* @0xe24d0 b 0xe2db8 <_Z5DoSetjPhPKhP6VMExec+0xda4> */
/* @0xe24d4 b 0xe2d94 <_Z5DoSetjPhPKhP6VMExec+0xd80> */
/* @0xe24d8 b 0xe29f4 <_Z5DoSetjPhPKhP6VMExec+0x9e0> */
/* @0xe24dc ldr r0, [pc, #0xb1c] */
/* @0xe24e0 add r0, pc, r0 */
/* @0xe24e4 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe24e8 mov r0, r8 */
/* @0xe24ec add sp, sp, #68 */
/* @0xe24f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe24f4 cmp r11, #51 */
/* @0xe24f8 beq 0xe3908 <_Z5DoSetjPhPKhP6VMExec+0x18f4> */
/* @0xe24fc bls 0xe2758 <_Z5DoSetjPhPKhP6VMExec+0x744> */
/* @0xe2500 cmp r11, #64 */
/* @0xe2504 bne 0xe33b8 <_Z5DoSetjPhPKhP6VMExec+0x13a4> */
/* @0xe2508 vldr s14, [r4] */
/* @0xe250c vcvt.f64.s32 d7, s14 */
/* @0xe2510 vldr d6, [r10] */
/* @0xe2514 sub r9, r9, #1 */
/* @0xe2518 vsub.f64 d7, d7, d6 */
/* @0xe251c vcvt.s32.f64 s12, d7 */
/* @0xe2520 cmp r9, #5 */
/* @0xe2524 addls pc, pc, r9, lsl #2 */
/* @0xe2528 b 0xe3c84 <_Z5DoSetjPhPKhP6VMExec+0x1c70> */
/* @0xe252c b 0xe2f44 <_Z5DoSetjPhPKhP6VMExec+0xf30> */
/* @0xe2530 b 0xe2f20 <_Z5DoSetjPhPKhP6VMExec+0xf0c> */
/* @0xe2534 b 0xe2ee8 <_Z5DoSetjPhPKhP6VMExec+0xed4> */
/* @0xe2538 b 0xe2eb0 <_Z5DoSetjPhPKhP6VMExec+0xe9c> */
/* @0xe253c b 0xe2e88 <_Z5DoSetjPhPKhP6VMExec+0xe74> */
/* @0xe2540 b 0xe2e64 <_Z5DoSetjPhPKhP6VMExec+0xe50> */
/* @0xe2544 ldr r0, [pc, #0xab8] */
/* @0xe2548 add r0, pc, r0 */
/* @0xe254c bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe2550 mov r0, r8 */
/* @0xe2554 b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* @0xe2558 mov r0, r7 */
/* @0xe255c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe2560 b 0xe2150 <_Z5DoSetjPhPKhP6VMExec+0x13c> */
/* @0xe2564 mov r0, r6 */
/* @0xe2568 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe256c b 0xe2124 <_Z5DoSetjPhPKhP6VMExec+0x110> */
/* @0xe2570 add r5, sp, #48 */
/* @0xe2574 uxtb r4, r12 */
/* @0xe2578 mov r2, r1 */
/* @0xe257c and r1, r4, #15 */
/* @0xe2580 mov r0, r5 */
/* @0xe2584 add r7, sp, #32 */
/* @0xe2588 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe258c lsr r1, r4, #4 */
/* @0xe2590 mov r2, r0 */
/* @0xe2594 mov r0, r7 */
/* @0xe2598 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe259c ldr r2, [sp, #0x2c] */
/* @0xe25a0 mvn r3, #-16777216 */
/* @0xe25a4 and r2, r2, r3 */
/* @0xe25a8 cmp r2, r3 */
/* @0xe25ac mov r4, r0 */
/* @0xe25b0 beq 0xe2828 <_Z5DoSetjPhPKhP6VMExec+0x814> */
/* @0xe25b4 ldr r2, [sp, #0x3c] */
/* @0xe25b8 bic r2, r2, #-16777216 */
/* @0xe25bc cmp r2, r3 */
/* @0xe25c0 beq 0xe3a60 <_Z5DoSetjPhPKhP6VMExec+0x1a4c> */
/* @0xe25c4 mov r0, r7 */
/* @0xe25c8 mov r1, r5 */
/* @0xe25cc bl 0x240a08 <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_> */
/* @0xe25d0 cmp r9, #14 */
/* @0xe25d4 sub r8, r4, #4 */
/* @0xe25d8 eorne r0, r0, #1 */
/* @0xe25dc uxtbne r0, r0 */
/* @0xe25e0 str r0, [r4, #-0x4] */
/* @0xe25e4 ldr r3, [sp, #0x2c] */
/* @0xe25e8 sub r3, r3, #1 */
/* @0xe25ec bic r3, r3, #-16777216 */
/* @0xe25f0 bic r3, r3, #3 */
/* @0xe25f4 cmp r3, #0 */
/* @0xe25f8 beq 0xe3b50 <_Z5DoSetjPhPKhP6VMExec+0x1b3c> */
/* @0xe25fc ldr r1, [sp, #0x3c] */
/* @0xe2600 mov r3, #0 */
/* @0xe2604 str r3, [sp, #0x28] */
/* @0xe2608 mov r2, #5 */
/* @0xe260c sub r1, r1, #1 */
/* @0xe2610 str r3, [sp, #0x20] */
/* @0xe2614 bic r3, r1, #-16777216 */
/* @0xe2618 str r2, [sp, #0x2c] */
/* @0xe261c bic r3, r3, #3 */
/* @0xe2620 cmp r3, #0 */
/* @0xe2624 bne 0xe247c <_Z5DoSetjPhPKhP6VMExec+0x468> */
/* @0xe2628 mov r0, r5 */
/* @0xe262c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe2630 mov r0, r8 */
/* @0xe2634 b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* @0xe2638 cmp r11, #34 */
/* @0xe263c beq 0xe37b4 <_Z5DoSetjPhPKhP6VMExec+0x17a0> */
/* @0xe2640 bls 0xe2718 <_Z5DoSetjPhPKhP6VMExec+0x704> */
/* @0xe2644 cmp r11, #35 */
/* @0xe2648 bne 0xe37ac <_Z5DoSetjPhPKhP6VMExec+0x1798> */
/* @0xe264c ldr r12, [r4] */
/* @0xe2650 sub r9, r9, #1 */
/* @0xe2654 ldrd r2, r3, [r10] */
/* @0xe2658 rsbs r0, r2, r12 */
/* @0xe265c rsc r1, r3, r12, asr #31 */
/* @0xe2660 cmp r9, #5 */
/* @0xe2664 addls pc, pc, r9, lsl #2 */
/* @0xe2668 b 0xe3c14 <_Z5DoSetjPhPKhP6VMExec+0x1c00> */
/* @0xe266c b 0xe2c1c <_Z5DoSetjPhPKhP6VMExec+0xc08> */
/* @0xe2670 b 0xe2bf4 <_Z5DoSetjPhPKhP6VMExec+0xbe0> */
/* @0xe2674 b 0xe2bb8 <_Z5DoSetjPhPKhP6VMExec+0xba4> */
/* @0xe2678 b 0xe2b7c <_Z5DoSetjPhPKhP6VMExec+0xb68> */
/* @0xe267c b 0xe2c70 <_Z5DoSetjPhPKhP6VMExec+0xc5c> */
/* @0xe2680 b 0xe2c48 <_Z5DoSetjPhPKhP6VMExec+0xc34> */
/* @0xe2684 add r6, sp, #16 */
/* @0xe2688 uxtb r4, r12 */
/* @0xe268c mov r2, r1 */
/* @0xe2690 and r1, r4, #15 */
/* @0xe2694 mov r0, r6 */
/* @0xe2698 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe269c lsr r1, r4, #4 */
/* @0xe26a0 mvn r4, #-16777216 */
/* @0xe26a4 mov r2, r0 */
/* @0xe26a8 mov r0, sp */
/* @0xe26ac bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe26b0 ldr r3, [sp, #0xc] */
/* @0xe26b4 and r3, r3, r4 */
/* @0xe26b8 cmp r3, r4 */
/* @0xe26bc mov r8, r0 */
/* @0xe26c0 beq 0xe288c <_Z5DoSetjPhPKhP6VMExec+0x878> */
/* @0xe26c4 ldr r3, [sp, #0x1c] */
/* @0xe26c8 bic r3, r3, #-16777216 */
/* @0xe26cc cmp r3, r4 */
/* @0xe26d0 beq 0xe3bd4 <_Z5DoSetjPhPKhP6VMExec+0x1bc0> */
/* @0xe26d4 cmp r3, #6 */
/* @0xe26d8 beq 0xe3a74 <_Z5DoSetjPhPKhP6VMExec+0x1a60> */
/* @0xe26dc ldr r0, [pc, #0x924] */
/* @0xe26e0 add r0, pc, r0 */
/* @0xe26e4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe26e8 mov r0, r8 */
/* @0xe26ec b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* @0xe26f0 and r12, r12, #240 */
/* @0xe26f4 orr r11, r12, #2 */
/* @0xe26f8 add r4, r10, #16 */
/* @0xe26fc mov r10, r7 */
/* @0xe2700 b 0xe2224 <_Z5DoSetjPhPKhP6VMExec+0x210> */
/* @0xe2704 and r11, r11, #15 */
/* @0xe2708 orr r11, r11, #32 */
/* @0xe270c add r7, r4, #16 */
/* @0xe2710 mov r4, r5 */
/* @0xe2714 b 0xe2268 <_Z5DoSetjPhPKhP6VMExec+0x254> */
/* @0xe2718 cmp r11, #32 */
/* @0xe271c bne 0xe33c0 <_Z5DoSetjPhPKhP6VMExec+0x13ac> */
/* @0xe2720 vldr s12, [r4] */
/* @0xe2724 vcvt.f64.s32 d6, s12 */
/* @0xe2728 sub r9, r9, #1 */
/* @0xe272c vldr d7, [r10] */
/* @0xe2730 vsub.f64 d7, d6, d7 */
/* @0xe2734 cmp r9, #5 */
/* @0xe2738 addls pc, pc, r9, lsl #2 */
/* @0xe273c b 0xe3ca4 <_Z5DoSetjPhPKhP6VMExec+0x1c90> */
/* @0xe2740 b 0xe29d0 <_Z5DoSetjPhPKhP6VMExec+0x9bc> */
/* @0xe2744 b 0xe29b0 <_Z5DoSetjPhPKhP6VMExec+0x99c> */
/* @0xe2748 b 0xe297c <_Z5DoSetjPhPKhP6VMExec+0x968> */
/* @0xe274c b 0xe2948 <_Z5DoSetjPhPKhP6VMExec+0x934> */
/* @0xe2750 b 0xe28d0 <_Z5DoSetjPhPKhP6VMExec+0x8bc> */
/* @0xe2754 b 0xe2b5c <_Z5DoSetjPhPKhP6VMExec+0xb48> */
/* @0xe2758 cmp r11, #50 */
/* @0xe275c bne 0xe33c0 <_Z5DoSetjPhPKhP6VMExec+0x13ac> */
/* @0xe2760 ldr r12, [r10] */
/* @0xe2764 sub r9, r9, #1 */
/* @0xe2768 ldrd r2, r3, [r4] */
/* @0xe276c subs r0, r2, r12 */
/* @0xe2770 sbc r1, r3, r12, asr #31 */
/* @0xe2774 cmp r9, #5 */
/* @0xe2778 addls pc, pc, r9, lsl #2 */
/* @0xe277c b 0xe3ce4 <_Z5DoSetjPhPKhP6VMExec+0x1cd0> */
/* @0xe2780 b 0xe2d68 <_Z5DoSetjPhPKhP6VMExec+0xd54> */
/* @0xe2784 b 0xe2d40 <_Z5DoSetjPhPKhP6VMExec+0xd2c> */
/* @0xe2788 b 0xe2d04 <_Z5DoSetjPhPKhP6VMExec+0xcf0> */
/* @0xe278c b 0xe2cc8 <_Z5DoSetjPhPKhP6VMExec+0xcb4> */
/* @0xe2790 b 0xe2c9c <_Z5DoSetjPhPKhP6VMExec+0xc88> */
/* @0xe2794 b 0xe2a14 <_Z5DoSetjPhPKhP6VMExec+0xa00> */
/* @0xe2798 cmp r11, #70 */
/* @0xe279c bne 0xe33c0 <_Z5DoSetjPhPKhP6VMExec+0x13ac> */
/* @0xe27a0 ldr r3, [r10] */
/* @0xe27a4 sub r9, r9, #1 */
/* @0xe27a8 ldr r2, [r4] */
/* @0xe27ac cmp r3, #0 */
/* @0xe27b0 moveq r3, r2 */
/* @0xe27b4 subne r3, r2, #1 */
/* @0xe27b8 cmp r9, #5 */
/* @0xe27bc addls pc, pc, r9, lsl #2 */
/* @0xe27c0 b 0xe3c44 <_Z5DoSetjPhPKhP6VMExec+0x1c30> */
/* @0xe27c4 b 0xe2b30 <_Z5DoSetjPhPKhP6VMExec+0xb1c> */
/* @0xe27c8 b 0xe2b08 <_Z5DoSetjPhPKhP6VMExec+0xaf4> */
/* @0xe27cc b 0xe2acc <_Z5DoSetjPhPKhP6VMExec+0xab8> */
/* @0xe27d0 b 0xe2a90 <_Z5DoSetjPhPKhP6VMExec+0xa7c> */
/* @0xe27d4 b 0xe2a64 <_Z5DoSetjPhPKhP6VMExec+0xa50> */
/* @0xe27d8 b 0xe2a3c <_Z5DoSetjPhPKhP6VMExec+0xa28> */
/* @0xe27dc vldr s14, [r10] */
/* @0xe27e0 vcvt.f64.s32 d7, s14 */
/* @0xe27e4 sub r9, r9, #1 */
/* @0xe27e8 vldr d6, [r4] */
/* @0xe27ec vsub.f64 d7, d6, d7 */
/* @0xe27f0 cmp r9, #5 */
/* @0xe27f4 addls pc, pc, r9, lsl #2 */
/* @0xe27f8 b 0xe3c94 <_Z5DoSetjPhPKhP6VMExec+0x1c80> */
/* @0xe27fc b 0xe3190 <_Z5DoSetjPhPKhP6VMExec+0x117c> */
/* @0xe2800 b 0xe3170 <_Z5DoSetjPhPKhP6VMExec+0x115c> */
/* @0xe2804 b 0xe313c <_Z5DoSetjPhPKhP6VMExec+0x1128> */
/* @0xe2808 b 0xe3108 <_Z5DoSetjPhPKhP6VMExec+0x10f4> */
/* @0xe280c b 0xe30e4 <_Z5DoSetjPhPKhP6VMExec+0x10d0> */
/* @0xe2810 b 0xe30c4 <_Z5DoSetjPhPKhP6VMExec+0x10b0> */
/* @0xe2814 ldr r0, [pc, #0x7f0] */
/* @0xe2818 add r0, pc, r0 */
/* @0xe281c bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe2820 mov r0, r8 */
/* @0xe2824 b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* @0xe2828 ldr r0, [pc, #0x7e0] */
/* @0xe282c add r0, pc, r0 */
/* @0xe2830 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe2834 mov r0, r4 */
/* @0xe2838 b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* @0xe283c orr r11, r11, #15 */
/* @0xe2840 b 0xe26f8 <_Z5DoSetjPhPKhP6VMExec+0x6e4> */
/* @0xe2844 and r12, r12, #240 */
/* @0xe2848 orr r11, r12, #3 */
/* @0xe284c b 0xe26f8 <_Z5DoSetjPhPKhP6VMExec+0x6e4> */
/* @0xe2850 and r12, r12, #240 */
/* @0xe2854 orr r11, r12, #6 */
/* @0xe2858 b 0xe26f8 <_Z5DoSetjPhPKhP6VMExec+0x6e4> */
/* @0xe285c orr r11, r11, #240 */
/* @0xe2860 b 0xe270c <_Z5DoSetjPhPKhP6VMExec+0x6f8> */
/* @0xe2864 and r11, r11, #240 */
/* @0xe2868 b 0xe26f8 <_Z5DoSetjPhPKhP6VMExec+0x6e4> */
/* @0xe286c and r11, r11, #15 */
/* @0xe2870 orr r11, r11, #48 */
/* @0xe2874 b 0xe270c <_Z5DoSetjPhPKhP6VMExec+0x6f8> */
/* @0xe2878 and r11, r11, #15 */
/* @0xe287c orr r11, r11, #96 */
/* @0xe2880 b 0xe270c <_Z5DoSetjPhPKhP6VMExec+0x6f8> */
/* @0xe2884 and r11, r11, #15 */
/* @0xe2888 b 0xe270c <_Z5DoSetjPhPKhP6VMExec+0x6f8> */
/* @0xe288c ldr r0, [pc, #0x780] */
/* @0xe2890 add r0, pc, r0 */
/* @0xe2894 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe2898 mov r0, r8 */
/* @0xe289c b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* @0xe28a0 ldr r1, [pc, #0x770] */
/* @0xe28a4 mov r0, r8 */
/* @0xe28a8 mov r7, r10 */
/* @0xe28ac add r1, pc, r1 */
/* @0xe28b0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe28b4 b 0xe26f8 <_Z5DoSetjPhPKhP6VMExec+0x6e4> */
/* @0xe28b8 ldr r1, [pc, #0x75c] */
/* @0xe28bc mov r0, r8 */
/* @0xe28c0 mov r5, r4 */
/* @0xe28c4 add r1, pc, r1 */
/* @0xe28c8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe28cc b 0xe270c <_Z5DoSetjPhPKhP6VMExec+0x6f8> */
/* @0xe28d0 ldr r3, [pc, #0x748] */
/* @0xe28d4 ldr r3, [r6, r3] */
/* @0xe28d8 vldr d6, [r3] */
/* @0xe28dc vneg.f64 d6, d6 */
/* @0xe28e0 vcmpe.f64 d7, d6 */
/* @0xe28e4 vmrs APSR_nzcv, fpscr */
/* @0xe28e8 movlt r0, #0 */
/* @0xe28ec movge r0, #1 */
/* @0xe28f0 str r0, [r7, #-0x4] */
/* @0xe28f4 ldr r3, [sp, #0x2c] */
/* @0xe28f8 sub r3, r3, #1 */
/* @0xe28fc bic r3, r3, #-16777216 */
/* @0xe2900 bic r3, r3, #3 */
/* @0xe2904 cmp r3, #0 */
/* @0xe2908 beq 0xe31b4 <_Z5DoSetjPhPKhP6VMExec+0x11a0> */
/* @0xe290c ldr r1, [sp, #0x3c] */
/* @0xe2910 mov r3, #0 */
/* @0xe2914 str r3, [sp, #0x28] */
/* @0xe2918 mov r2, #5 */
/* @0xe291c sub r1, r1, #1 */
/* @0xe2920 str r3, [sp, #0x20] */
/* @0xe2924 bic r3, r1, #-16777216 */
/* @0xe2928 str r2, [sp, #0x2c] */
/* @0xe292c bic r3, r3, #3 */
/* @0xe2930 cmp r3, #0 */
/* @0xe2934 bne 0xe247c <_Z5DoSetjPhPKhP6VMExec+0x468> */
/* @0xe2938 add r0, sp, #48 */
/* @0xe293c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe2940 mov r0, r8 */
/* @0xe2944 b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* @0xe2948 ldr r3, [pc, #0x6d0] */
/* @0xe294c ldr r3, [r6, r3] */
/* @0xe2950 vldr d6, [r3] */
/* @0xe2954 vneg.f64 d5, d6 */
/* @0xe2958 vcmpe.f64 d7, d5 */
/* @0xe295c vmrs APSR_nzcv, fpscr */
/* @0xe2960 movmi r0, #1 */
/* @0xe2964 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2968 vcmpe.f64 d7, d6 */
/* @0xe296c vmrs APSR_nzcv, fpscr */
/* @0xe2970 movle r0, #0 */
/* @0xe2974 movgt r0, #1 */
/* @0xe2978 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe297c ldr r3, [pc, #0x69c] */
/* @0xe2980 ldr r3, [r6, r3] */
/* @0xe2984 vldr d6, [r3] */
/* @0xe2988 vneg.f64 d5, d6 */
/* @0xe298c vcmpe.f64 d7, d5 */
/* @0xe2990 vmrs APSR_nzcv, fpscr */
/* @0xe2994 movlt r0, #0 */
/* @0xe2998 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe299c vcmpe.f64 d7, d6 */
/* @0xe29a0 vmrs APSR_nzcv, fpscr */
/* @0xe29a4 movhi r0, #0 */
/* @0xe29a8 movls r0, #1 */
/* @0xe29ac b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe29b0 ldr r3, [pc, #0x668] */
/* @0xe29b4 ldr r3, [r6, r3] */
/* @0xe29b8 vldr d6, [r3] */
/* @0xe29bc vcmpe.f64 d7, d6 */
/* @0xe29c0 vmrs APSR_nzcv, fpscr */
/* @0xe29c4 movhi r0, #0 */
/* @0xe29c8 movls r0, #1 */
/* @0xe29cc b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe29d0 ldr r3, [pc, #0x648] */
/* @0xe29d4 ldr r3, [r6, r3] */
/* @0xe29d8 vldr d6, [r3] */
/* @0xe29dc vneg.f64 d6, d6 */
/* @0xe29e0 vcmpe.f64 d7, d6 */
/* @0xe29e4 vmrs APSR_nzcv, fpscr */
/* @0xe29e8 movpl r0, #0 */
/* @0xe29ec movmi r0, #1 */
/* @0xe29f0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe29f4 ldr r3, [pc, #0x624] */
/* @0xe29f8 ldr r3, [r6, r3] */
/* @0xe29fc vldr d6, [r3] */
/* @0xe2a00 vcmpe.f64 d7, d6 */
/* @0xe2a04 vmrs APSR_nzcv, fpscr */
/* @0xe2a08 movle r0, #0 */
/* @0xe2a0c movgt r0, #1 */
/* @0xe2a10 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2a14 bl 0x319164 <__floatdidf> */
/* @0xe2a18 ldr r3, [pc, #0x600] */
/* @0xe2a1c ldr r3, [r6, r3] */
/* @0xe2a20 vldr d7, [r3] */
/* @0xe2a24 vmov d6, r0, r1 */
/* @0xe2a28 vcmpe.f64 d6, d7 */
/* @0xe2a2c vmrs APSR_nzcv, fpscr */
/* @0xe2a30 movle r0, #0 */
/* @0xe2a34 movgt r0, #1 */
/* @0xe2a38 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2a3c vmov s15, r3 */
/* @0xe2a40 ldr r3, [pc, #0x5d8] */
/* @0xe2a44 vcvt.f64.s32 d6, s15 */
/* @0xe2a48 ldr r3, [r6, r3] */
/* @0xe2a4c vldr d7, [r3] */
/* @0xe2a50 vcmpe.f64 d6, d7 */
/* @0xe2a54 vmrs APSR_nzcv, fpscr */
/* @0xe2a58 movle r0, #0 */
/* @0xe2a5c movgt r0, #1 */
/* @0xe2a60 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2a64 vmov s15, r3 */
/* @0xe2a68 ldr r2, [pc, #0x5b0] */
/* @0xe2a6c vcvt.f64.s32 d6, s15 */
/* @0xe2a70 ldr r3, [r6, r2] */
/* @0xe2a74 vldr d7, [r3] */
/* @0xe2a78 vneg.f64 d7, d7 */
/* @0xe2a7c vcmpe.f64 d6, d7 */
/* @0xe2a80 vmrs APSR_nzcv, fpscr */
/* @0xe2a84 movlt r0, #0 */
/* @0xe2a88 movge r0, #1 */
/* @0xe2a8c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2a90 vmov s15, r3 */
/* @0xe2a94 ldr r2, [pc, #0x584] */
/* @0xe2a98 vcvt.f64.s32 d6, s15 */
/* @0xe2a9c ldr r3, [r6, r2] */
/* @0xe2aa0 vldr d7, [r3] */
/* @0xe2aa4 vneg.f64 d5, d7 */
/* @0xe2aa8 vcmpe.f64 d6, d5 */
/* @0xe2aac vmrs APSR_nzcv, fpscr */
/* @0xe2ab0 movmi r0, #1 */
/* @0xe2ab4 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2ab8 vcmpe.f64 d6, d7 */
/* @0xe2abc vmrs APSR_nzcv, fpscr */
/* @0xe2ac0 movle r0, #0 */
/* @0xe2ac4 movgt r0, #1 */
/* @0xe2ac8 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2acc vmov s15, r3 */
/* @0xe2ad0 ldr r2, [pc, #0x548] */
/* @0xe2ad4 vcvt.f64.s32 d6, s15 */
/* @0xe2ad8 ldr r3, [r6, r2] */
/* @0xe2adc vldr d7, [r3] */
/* @0xe2ae0 vneg.f64 d5, d7 */
/* @0xe2ae4 vcmpe.f64 d6, d5 */
/* @0xe2ae8 vmrs APSR_nzcv, fpscr */
/* @0xe2aec movlt r0, #0 */
/* @0xe2af0 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2af4 vcmpe.f64 d6, d7 */
/* @0xe2af8 vmrs APSR_nzcv, fpscr */
/* @0xe2afc movhi r0, #0 */
/* @0xe2b00 movls r0, #1 */
/* @0xe2b04 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2b08 vmov s15, r3 */
/* @0xe2b0c ldr r3, [pc, #0x50c] */
/* @0xe2b10 vcvt.f64.s32 d6, s15 */
/* @0xe2b14 ldr r3, [r6, r3] */
/* @0xe2b18 vldr d7, [r3] */
/* @0xe2b1c vcmpe.f64 d6, d7 */
/* @0xe2b20 vmrs APSR_nzcv, fpscr */
/* @0xe2b24 movhi r0, #0 */
/* @0xe2b28 movls r0, #1 */
/* @0xe2b2c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2b30 vmov s15, r3 */
/* @0xe2b34 ldr r2, [pc, #0x4e4] */
/* @0xe2b38 vcvt.f64.s32 d6, s15 */
/* @0xe2b3c ldr r3, [r6, r2] */
/* @0xe2b40 vldr d7, [r3] */
/* @0xe2b44 vneg.f64 d7, d7 */
/* @0xe2b48 vcmpe.f64 d6, d7 */
/* @0xe2b4c vmrs APSR_nzcv, fpscr */
/* @0xe2b50 movpl r0, #0 */
/* @0xe2b54 movmi r0, #1 */
/* @0xe2b58 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2b5c ldr r3, [pc, #0x4bc] */
/* @0xe2b60 ldr r3, [r6, r3] */
/* @0xe2b64 vldr d6, [r3] */
/* @0xe2b68 vcmpe.f64 d7, d6 */
/* @0xe2b6c vmrs APSR_nzcv, fpscr */
/* @0xe2b70 movle r0, #0 */
/* @0xe2b74 movgt r0, #1 */
/* @0xe2b78 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2b7c bl 0x319164 <__floatdidf> */
/* @0xe2b80 ldr r3, [pc, #0x498] */
/* @0xe2b84 ldr r3, [r6, r3] */
/* @0xe2b88 vldr d7, [r3] */
/* @0xe2b8c vneg.f64 d5, d7 */
/* @0xe2b90 vmov d6, r0, r1 */
/* @0xe2b94 vcmpe.f64 d6, d5 */
/* @0xe2b98 vmrs APSR_nzcv, fpscr */
/* @0xe2b9c movmi r0, #1 */
/* @0xe2ba0 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2ba4 vcmpe.f64 d6, d7 */
/* @0xe2ba8 vmrs APSR_nzcv, fpscr */
/* @0xe2bac movle r0, #0 */
/* @0xe2bb0 movgt r0, #1 */
/* @0xe2bb4 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2bb8 bl 0x319164 <__floatdidf> */
/* @0xe2bbc ldr r3, [pc, #0x45c] */
/* @0xe2bc0 ldr r3, [r6, r3] */
/* @0xe2bc4 vldr d7, [r3] */
/* @0xe2bc8 vneg.f64 d5, d7 */
/* @0xe2bcc vmov d6, r0, r1 */
/* @0xe2bd0 vcmpe.f64 d6, d5 */
/* @0xe2bd4 vmrs APSR_nzcv, fpscr */
/* @0xe2bd8 movlt r0, #0 */
/* @0xe2bdc blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2be0 vcmpe.f64 d6, d7 */
/* @0xe2be4 vmrs APSR_nzcv, fpscr */
/* @0xe2be8 movhi r0, #0 */
/* @0xe2bec movls r0, #1 */
/* @0xe2bf0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2bf4 bl 0x319164 <__floatdidf> */
/* @0xe2bf8 ldr r3, [pc, #0x420] */
/* @0xe2bfc ldr r3, [r6, r3] */
/* @0xe2c00 vldr d7, [r3] */
/* @0xe2c04 vmov d6, r0, r1 */
/* @0xe2c08 vcmpe.f64 d6, d7 */
/* @0xe2c0c vmrs APSR_nzcv, fpscr */
/* @0xe2c10 movhi r0, #0 */
/* @0xe2c14 movls r0, #1 */
/* @0xe2c18 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2c1c bl 0x319164 <__floatdidf> */
/* @0xe2c20 ldr r3, [pc, #0x3f8] */
/* @0xe2c24 ldr r3, [r6, r3] */
/* @0xe2c28 vldr d7, [r3] */
/* @0xe2c2c vneg.f64 d7, d7 */
/* @0xe2c30 vmov d6, r0, r1 */
/* @0xe2c34 vcmpe.f64 d6, d7 */
/* @0xe2c38 vmrs APSR_nzcv, fpscr */
/* @0xe2c3c movpl r0, #0 */
/* @0xe2c40 movmi r0, #1 */
/* @0xe2c44 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2c48 bl 0x319164 <__floatdidf> */
/* @0xe2c4c ldr r3, [pc, #0x3cc] */
/* @0xe2c50 ldr r3, [r6, r3] */
/* @0xe2c54 vldr d7, [r3] */
/* @0xe2c58 vmov d6, r0, r1 */
/* @0xe2c5c vcmpe.f64 d6, d7 */
/* @0xe2c60 vmrs APSR_nzcv, fpscr */
/* @0xe2c64 movle r0, #0 */
/* @0xe2c68 movgt r0, #1 */
/* @0xe2c6c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2c70 bl 0x319164 <__floatdidf> */
/* @0xe2c74 ldr r3, [pc, #0x3a4] */
/* @0xe2c78 ldr r3, [r6, r3] */
/* @0xe2c7c vldr d7, [r3] */
/* @0xe2c80 vneg.f64 d7, d7 */
/* @0xe2c84 vmov d6, r0, r1 */
/* @0xe2c88 vcmpe.f64 d6, d7 */
/* @0xe2c8c vmrs APSR_nzcv, fpscr */
/* @0xe2c90 movlt r0, #0 */
/* @0xe2c94 movge r0, #1 */
/* @0xe2c98 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2c9c bl 0x319164 <__floatdidf> */
/* @0xe2ca0 ldr r3, [pc, #0x378] */
/* @0xe2ca4 ldr r3, [r6, r3] */
/* @0xe2ca8 vldr d7, [r3] */
/* @0xe2cac vneg.f64 d7, d7 */
/* @0xe2cb0 vmov d6, r0, r1 */
/* @0xe2cb4 vcmpe.f64 d6, d7 */
/* @0xe2cb8 vmrs APSR_nzcv, fpscr */
/* @0xe2cbc movlt r0, #0 */
/* @0xe2cc0 movge r0, #1 */
/* @0xe2cc4 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2cc8 bl 0x319164 <__floatdidf> */
/* @0xe2ccc ldr r3, [pc, #0x34c] */
/* @0xe2cd0 ldr r3, [r6, r3] */
/* @0xe2cd4 vldr d7, [r3] */
/* @0xe2cd8 vneg.f64 d5, d7 */
/* @0xe2cdc vmov d6, r0, r1 */
/* @0xe2ce0 vcmpe.f64 d6, d5 */
/* @0xe2ce4 vmrs APSR_nzcv, fpscr */
/* @0xe2ce8 movmi r0, #1 */
/* @0xe2cec bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2cf0 vcmpe.f64 d6, d7 */
/* @0xe2cf4 vmrs APSR_nzcv, fpscr */
/* @0xe2cf8 movle r0, #0 */
/* @0xe2cfc movgt r0, #1 */
/* @0xe2d00 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2d04 bl 0x319164 <__floatdidf> */
/* @0xe2d08 ldr r3, [pc, #0x310] */
/* @0xe2d0c ldr r3, [r6, r3] */
/* @0xe2d10 vldr d7, [r3] */
/* @0xe2d14 vneg.f64 d5, d7 */
/* @0xe2d18 vmov d6, r0, r1 */
/* @0xe2d1c vcmpe.f64 d6, d5 */
/* @0xe2d20 vmrs APSR_nzcv, fpscr */
/* @0xe2d24 movlt r0, #0 */
/* @0xe2d28 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2d2c vcmpe.f64 d6, d7 */
/* @0xe2d30 vmrs APSR_nzcv, fpscr */
/* @0xe2d34 movhi r0, #0 */
/* @0xe2d38 movls r0, #1 */
/* @0xe2d3c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2d40 bl 0x319164 <__floatdidf> */
/* @0xe2d44 ldr r3, [pc, #0x2d4] */
/* @0xe2d48 ldr r3, [r6, r3] */
/* @0xe2d4c vldr d7, [r3] */
/* @0xe2d50 vmov d6, r0, r1 */
/* @0xe2d54 vcmpe.f64 d6, d7 */
/* @0xe2d58 vmrs APSR_nzcv, fpscr */
/* @0xe2d5c movhi r0, #0 */
/* @0xe2d60 movls r0, #1 */
/* @0xe2d64 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2d68 bl 0x319164 <__floatdidf> */
/* @0xe2d6c ldr r3, [pc, #0x2ac] */
/* @0xe2d70 ldr r3, [r6, r3] */
/* @0xe2d74 vldr d7, [r3] */
/* @0xe2d78 vneg.f64 d7, d7 */
/* @0xe2d7c vmov d6, r0, r1 */
/* @0xe2d80 vcmpe.f64 d6, d7 */
/* @0xe2d84 vmrs APSR_nzcv, fpscr */
/* @0xe2d88 movpl r0, #0 */
/* @0xe2d8c movmi r0, #1 */
/* @0xe2d90 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2d94 ldr r3, [pc, #0x284] */
/* @0xe2d98 ldr r3, [r6, r3] */
/* @0xe2d9c vldr d6, [r3] */
/* @0xe2da0 vneg.f64 d6, d6 */
/* @0xe2da4 vcmpe.f64 d7, d6 */
/* @0xe2da8 vmrs APSR_nzcv, fpscr */
/* @0xe2dac movlt r0, #0 */
/* @0xe2db0 movge r0, #1 */
/* @0xe2db4 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2db8 ldr r3, [pc, #0x260] */
/* @0xe2dbc ldr r3, [r6, r3] */
/* @0xe2dc0 vldr d6, [r3] */
/* @0xe2dc4 vneg.f64 d5, d6 */
/* @0xe2dc8 vcmpe.f64 d7, d5 */
/* @0xe2dcc vmrs APSR_nzcv, fpscr */
/* @0xe2dd0 movmi r0, #1 */
/* @0xe2dd4 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2dd8 vcmpe.f64 d7, d6 */
/* @0xe2ddc vmrs APSR_nzcv, fpscr */
/* @0xe2de0 movle r0, #0 */
/* @0xe2de4 movgt r0, #1 */
/* @0xe2de8 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2dec ldr r3, [pc, #0x22c] */
/* @0xe2df0 ldr r3, [r6, r3] */
/* @0xe2df4 vldr d6, [r3] */
/* @0xe2df8 vneg.f64 d5, d6 */
/* @0xe2dfc vcmpe.f64 d7, d5 */
/* @0xe2e00 vmrs APSR_nzcv, fpscr */
/* @0xe2e04 movlt r0, #0 */
/* @0xe2e08 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2e0c vcmpe.f64 d7, d6 */
/* @0xe2e10 vmrs APSR_nzcv, fpscr */
/* @0xe2e14 movhi r0, #0 */
/* @0xe2e18 movls r0, #1 */
/* @0xe2e1c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2e20 ldr r3, [pc, #0x1f8] */
/* @0xe2e24 ldr r3, [r6, r3] */
/* @0xe2e28 vldr d6, [r3] */
/* @0xe2e2c vcmpe.f64 d7, d6 */
/* @0xe2e30 vmrs APSR_nzcv, fpscr */
/* @0xe2e34 movhi r0, #0 */
/* @0xe2e38 movls r0, #1 */
/* @0xe2e3c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2e40 ldr r3, [pc, #0x1d8] */
/* @0xe2e44 ldr r3, [r6, r3] */
/* @0xe2e48 vldr d6, [r3] */
/* @0xe2e4c vneg.f64 d6, d6 */
/* @0xe2e50 vcmpe.f64 d7, d6 */
/* @0xe2e54 vmrs APSR_nzcv, fpscr */
/* @0xe2e58 movpl r0, #0 */
/* @0xe2e5c movmi r0, #1 */
/* @0xe2e60 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2e64 vcvt.f64.s32 d6, s12 */
/* @0xe2e68 ldr r3, [pc, #0x1b0] */
/* @0xe2e6c ldr r3, [r6, r3] */
/* @0xe2e70 vldr d7, [r3] */
/* @0xe2e74 vcmpe.f64 d6, d7 */
/* @0xe2e78 vmrs APSR_nzcv, fpscr */
/* @0xe2e7c movle r0, #0 */
/* @0xe2e80 movgt r0, #1 */
/* @0xe2e84 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2e88 ldr r3, [pc, #0x190] */
/* @0xe2e8c vcvt.f64.s32 d6, s12 */
/* @0xe2e90 ldr r3, [r6, r3] */
/* @0xe2e94 vldr d7, [r3] */
/* @0xe2e98 vneg.f64 d7, d7 */
/* @0xe2e9c vcmpe.f64 d6, d7 */
/* @0xe2ea0 vmrs APSR_nzcv, fpscr */
/* @0xe2ea4 movlt r0, #0 */
/* @0xe2ea8 movge r0, #1 */
/* @0xe2eac b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2eb0 ldr r3, [pc, #0x168] */
/* @0xe2eb4 vcvt.f64.s32 d6, s12 */
/* @0xe2eb8 ldr r3, [r6, r3] */
/* @0xe2ebc vldr d7, [r3] */
/* @0xe2ec0 vneg.f64 d5, d7 */
/* @0xe2ec4 vcmpe.f64 d6, d5 */
/* @0xe2ec8 vmrs APSR_nzcv, fpscr */
/* @0xe2ecc movmi r0, #1 */
/* @0xe2ed0 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2ed4 vcmpe.f64 d6, d7 */
/* @0xe2ed8 vmrs APSR_nzcv, fpscr */
/* @0xe2edc movle r0, #0 */
/* @0xe2ee0 movgt r0, #1 */
/* @0xe2ee4 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2ee8 ldr r3, [pc, #0x130] */
/* @0xe2eec vcvt.f64.s32 d6, s12 */
/* @0xe2ef0 ldr r3, [r6, r3] */
/* @0xe2ef4 vldr d7, [r3] */
/* @0xe2ef8 vneg.f64 d5, d7 */
/* @0xe2efc vcmpe.f64 d6, d5 */
/* @0xe2f00 vmrs APSR_nzcv, fpscr */
/* @0xe2f04 movlt r0, #0 */
/* @0xe2f08 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2f0c vcmpe.f64 d6, d7 */
/* @0xe2f10 vmrs APSR_nzcv, fpscr */
/* @0xe2f14 movhi r0, #0 */
/* @0xe2f18 movls r0, #1 */
/* @0xe2f1c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2f20 vcvt.f64.s32 d6, s12 */
/* @0xe2f24 ldr r3, [pc, #0xf4] */
/* @0xe2f28 ldr r3, [r6, r3] */
/* @0xe2f2c vldr d7, [r3] */
/* @0xe2f30 vcmpe.f64 d6, d7 */
/* @0xe2f34 vmrs APSR_nzcv, fpscr */
/* @0xe2f38 movhi r0, #0 */
/* @0xe2f3c movls r0, #1 */
/* @0xe2f40 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2f44 ldr r3, [pc, #0xd4] */
/* @0xe2f48 vcvt.f64.s32 d6, s12 */
/* @0xe2f4c ldr r3, [r6, r3] */
/* @0xe2f50 vldr d7, [r3] */
/* @0xe2f54 vneg.f64 d7, d7 */
/* @0xe2f58 vcmpe.f64 d6, d7 */
/* @0xe2f5c vmrs APSR_nzcv, fpscr */
/* @0xe2f60 movpl r0, #0 */
/* @0xe2f64 movmi r0, #1 */
/* @0xe2f68 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2f6c vmov s15, r3 */
/* @0xe2f70 ldr r3, [pc, #0xa8] */
/* @0xe2f74 vcvt.f64.s32 d6, s15 */
/* @0xe2f78 ldr r3, [r6, r3] */
/* @0xe2f7c vldr d7, [r3] */
/* @0xe2f80 vcmpe.f64 d6, d7 */
/* @0xe2f84 vmrs APSR_nzcv, fpscr */
/* @0xe2f88 movle r0, #0 */
/* @0xe2f8c movgt r0, #1 */
/* @0xe2f90 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2f94 vmov s15, r3 */
/* @0xe2f98 ldr r2, [pc, #0x80] */
/* @0xe2f9c vcvt.f64.s32 d6, s15 */
/* @0xe2fa0 ldr r3, [r6, r2] */
/* @0xe2fa4 vldr d7, [r3] */
/* @0xe2fa8 vneg.f64 d7, d7 */
/* @0xe2fac vcmpe.f64 d6, d7 */
/* @0xe2fb0 vmrs APSR_nzcv, fpscr */
/* @0xe2fb4 movlt r0, #0 */
/* @0xe2fb8 movge r0, #1 */
/* @0xe2fbc b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2fc0 vmov s15, r3 */
/* @0xe2fc4 ldr r2, [pc, #0x54] */
/* @0xe2fc8 vcvt.f64.s32 d6, s15 */
/* @0xe2fcc ldr r3, [r6, r2] */
/* @0xe2fd0 vldr d7, [r3] */
/* @0xe2fd4 vneg.f64 d5, d7 */
/* @0xe2fd8 vcmpe.f64 d6, d5 */
/* @0xe2fdc vmrs APSR_nzcv, fpscr */
/* @0xe2fe0 movmi r0, #1 */
/* @0xe2fe4 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2fe8 vcmpe.f64 d6, d7 */
/* @0xe2fec vmrs APSR_nzcv, fpscr */
/* @0xe2ff0 movle r0, #0 */
/* @0xe2ff4 movgt r0, #1 */
/* @0xe2ff8 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2ffc eorseq pc, r0, r4, lsl r12 */
/* @0xe3000 eoreq r1, r5, r4, asr lr */
/* @0xe3004 eoreq r1, r5, r12, ror #27 */
/* @0xe3008 eoreq r1, r5, r8, ror sp */
/* @0xe300c eoreq r1, r5, r4, ror r11 */
/* @0xe3010 eoreq r1, r5, r12, lsl #23 */
/* @0xe3014 eoreq r1, r5, r0, lsl #23 */
/* @0xe3018 eoreq r1, r5, r12, lsl r12 */
/* @0xe301c eoreq r1, r5, r4, lsr #24 */
/* @0xe3020 .word 0xffffc0c8 */
/* @0xe3024 eoreq r0, r5, r0, lsl #19 */
/* @0xe3028 eoreq r0, r5, r0, lsl #16 */
/* @0xe302c eoreq r0, r5, r12, asr r8 */
/* @0xe3030 mlaeq r5, r4, r7, r0 */
/* @0xe3034 vmov s15, r3 */
/* @0xe3038 ldr r2, [pc, #-0x20] */
/* @0xe303c vcvt.f64.s32 d6, s15 */
/* @0xe3040 ldr r3, [r6, r2] */
/* @0xe3044 vldr d7, [r3] */
/* @0xe3048 vneg.f64 d5, d7 */
/* @0xe304c vcmpe.f64 d6, d5 */
/* @0xe3050 vmrs APSR_nzcv, fpscr */
/* @0xe3054 movlt r0, #0 */
/* @0xe3058 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe305c vcmpe.f64 d6, d7 */
/* @0xe3060 vmrs APSR_nzcv, fpscr */
/* @0xe3064 movhi r0, #0 */
/* @0xe3068 movls r0, #1 */
/* @0xe306c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3070 vmov s15, r3 */
/* @0xe3074 ldr r3, [pc, #-0x5c] */
/* @0xe3078 vcvt.f64.s32 d6, s15 */
/* @0xe307c ldr r3, [r6, r3] */
/* @0xe3080 vldr d7, [r3] */
/* @0xe3084 vcmpe.f64 d6, d7 */
/* @0xe3088 vmrs APSR_nzcv, fpscr */
/* @0xe308c movhi r0, #0 */
/* @0xe3090 movls r0, #1 */
/* @0xe3094 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3098 vmov s15, r3 */
/* @0xe309c ldr r2, [pc, #-0x84] */
/* @0xe30a0 vcvt.f64.s32 d6, s15 */
/* @0xe30a4 ldr r3, [r6, r2] */
/* @0xe30a8 vldr d7, [r3] */
/* @0xe30ac vneg.f64 d7, d7 */
/* @0xe30b0 vcmpe.f64 d6, d7 */
/* @0xe30b4 vmrs APSR_nzcv, fpscr */
/* @0xe30b8 movpl r0, #0 */
/* @0xe30bc movmi r0, #1 */
/* @0xe30c0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe30c4 ldr r3, [pc, #-0xac] */
/* @0xe30c8 ldr r3, [r6, r3] */
/* @0xe30cc vldr d6, [r3] */
/* @0xe30d0 vcmpe.f64 d7, d6 */
/* @0xe30d4 vmrs APSR_nzcv, fpscr */
/* @0xe30d8 movle r0, #0 */
/* @0xe30dc movgt r0, #1 */
/* @0xe30e0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe30e4 ldr r3, [pc, #-0xcc] */
/* @0xe30e8 ldr r3, [r6, r3] */
/* @0xe30ec vldr d6, [r3] */
/* @0xe30f0 vneg.f64 d6, d6 */
/* @0xe30f4 vcmpe.f64 d7, d6 */
/* @0xe30f8 vmrs APSR_nzcv, fpscr */
/* @0xe30fc movlt r0, #0 */
/* @0xe3100 movge r0, #1 */
/* @0xe3104 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3108 ldr r3, [pc, #-0xf0] */
/* @0xe310c ldr r3, [r6, r3] */
/* @0xe3110 vldr d6, [r3] */
/* @0xe3114 vneg.f64 d5, d6 */
/* @0xe3118 vcmpe.f64 d7, d5 */
/* @0xe311c vmrs APSR_nzcv, fpscr */
/* @0xe3120 movmi r0, #1 */
/* @0xe3124 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3128 vcmpe.f64 d7, d6 */
/* @0xe312c vmrs APSR_nzcv, fpscr */
/* @0xe3130 movle r0, #0 */
/* @0xe3134 movgt r0, #1 */
/* @0xe3138 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe313c ldr r3, [pc, #-0x124] */
/* @0xe3140 ldr r3, [r6, r3] */
/* @0xe3144 vldr d6, [r3] */
/* @0xe3148 vneg.f64 d5, d6 */
/* @0xe314c vcmpe.f64 d7, d5 */
/* @0xe3150 vmrs APSR_nzcv, fpscr */
/* @0xe3154 movlt r0, #0 */
/* @0xe3158 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe315c vcmpe.f64 d7, d6 */
/* @0xe3160 vmrs APSR_nzcv, fpscr */
/* @0xe3164 movhi r0, #0 */
/* @0xe3168 movls r0, #1 */
/* @0xe316c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3170 ldr r3, [pc, #-0x158] */
/* @0xe3174 ldr r3, [r6, r3] */
/* @0xe3178 vldr d6, [r3] */
/* @0xe317c vcmpe.f64 d7, d6 */
/* @0xe3180 vmrs APSR_nzcv, fpscr */
/* @0xe3184 movhi r0, #0 */
/* @0xe3188 movls r0, #1 */
/* @0xe318c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3190 ldr r3, [pc, #-0x178] */
/* @0xe3194 ldr r3, [r6, r3] */
/* @0xe3198 vldr d6, [r3] */
/* @0xe319c vneg.f64 d6, d6 */
/* @0xe31a0 vcmpe.f64 d7, d6 */
/* @0xe31a4 vmrs APSR_nzcv, fpscr */
/* @0xe31a8 movpl r0, #0 */
/* @0xe31ac movmi r0, #1 */
/* @0xe31b0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe31b4 add r0, sp, #32 */
/* @0xe31b8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe31bc b 0xe290c <_Z5DoSetjPhPKhP6VMExec+0x8f8> */
/* @0xe31c0 ldr r2, [r10] */
/* @0xe31c4 ldr r3, [r4] */
/* @0xe31c8 cmp r2, #0 */
/* @0xe31cc moveq r1, r2 */
/* @0xe31d0 beq 0xe31e0 <_Z5DoSetjPhPKhP6VMExec+0x11cc> */
/* @0xe31d4 ldr r1, [r2] */
/* @0xe31d8 adds r2, r1, #0 */
/* @0xe31dc movne r2, #1 */
/* @0xe31e0 cmp r3, #0 */
/* @0xe31e4 beq 0xe3be8 <_Z5DoSetjPhPKhP6VMExec+0x1bd4> */
/* @0xe31e8 ldr r0, [r3] */
/* @0xe31ec adds r3, r0, #0 */
/* @0xe31f0 movne r3, #1 */
/* @0xe31f4 tst r2, r3 */
/* @0xe31f8 beq 0xe3b70 <_Z5DoSetjPhPKhP6VMExec+0x1b5c> */
/* @0xe31fc bl 0xb6574 <strcmp@plt> */
/* @0xe3200 sub r9, r9, #1 */
/* @0xe3204 cmp r9, #5 */
/* @0xe3208 addls pc, pc, r9, lsl #2 */
/* @0xe320c b 0xe3c24 <_Z5DoSetjPhPKhP6VMExec+0x1c10> */
/* @0xe3210 b 0xe326c <_Z5DoSetjPhPKhP6VMExec+0x1258> */
/* @0xe3214 b 0xe325c <_Z5DoSetjPhPKhP6VMExec+0x1248> */
/* @0xe3218 b 0xe3250 <_Z5DoSetjPhPKhP6VMExec+0x123c> */
/* @0xe321c b 0xe3244 <_Z5DoSetjPhPKhP6VMExec+0x1230> */
/* @0xe3220 b 0xe3238 <_Z5DoSetjPhPKhP6VMExec+0x1224> */
/* @0xe3224 b 0xe3228 <_Z5DoSetjPhPKhP6VMExec+0x1214> */
/* @0xe3228 cmp r0, #0 */
/* @0xe322c movle r0, #0 */
/* @0xe3230 movgt r0, #1 */
/* @0xe3234 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3238 mvn r0, r0 */
/* @0xe323c lsr r0, r0, #31 */
/* @0xe3240 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3244 adds r0, r0, #0 */
/* @0xe3248 movne r0, #1 */
/* @0xe324c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3250 rsbs r0, r0, #1 */
/* @0xe3254 movlo r0, #0 */
/* @0xe3258 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe325c cmp r0, #0 */
/* @0xe3260 movgt r0, #0 */
/* @0xe3264 movle r0, #1 */
/* @0xe3268 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe326c lsr r0, r0, #31 */
/* @0xe3270 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3274 vldr s14, [r10] */
/* @0xe3278 vcvt.f64.s32 d7, s14 */
/* @0xe327c vldr d6, [r4] */
/* @0xe3280 sub r9, r9, #1 */
/* @0xe3284 vsub.f64 d7, d6, d7 */
/* @0xe3288 vcvt.s32.f64 s12, d7 */
/* @0xe328c cmp r9, #5 */
/* @0xe3290 addls pc, pc, r9, lsl #2 */
/* @0xe3294 b 0xe3cd4 <_Z5DoSetjPhPKhP6VMExec+0x1cc0> */
/* @0xe3298 b 0xe3390 <_Z5DoSetjPhPKhP6VMExec+0x137c> */
/* @0xe329c b 0xe336c <_Z5DoSetjPhPKhP6VMExec+0x1358> */
/* @0xe32a0 b 0xe3334 <_Z5DoSetjPhPKhP6VMExec+0x1320> */
/* @0xe32a4 b 0xe32fc <_Z5DoSetjPhPKhP6VMExec+0x12e8> */
/* @0xe32a8 b 0xe32d4 <_Z5DoSetjPhPKhP6VMExec+0x12c0> */
/* @0xe32ac b 0xe32b0 <_Z5DoSetjPhPKhP6VMExec+0x129c> */
/* @0xe32b0 vcvt.f64.s32 d6, s12 */
/* @0xe32b4 ldr r3, [pc, #-0x29c] */
/* @0xe32b8 ldr r3, [r6, r3] */
/* @0xe32bc vldr d7, [r3] */
/* @0xe32c0 vcmpe.f64 d6, d7 */
/* @0xe32c4 vmrs APSR_nzcv, fpscr */
/* @0xe32c8 movle r0, #0 */
/* @0xe32cc movgt r0, #1 */
/* @0xe32d0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe32d4 ldr r3, [pc, #-0x2bc] */
/* @0xe32d8 vcvt.f64.s32 d6, s12 */
/* @0xe32dc ldr r3, [r6, r3] */
/* @0xe32e0 vldr d7, [r3] */
/* @0xe32e4 vneg.f64 d7, d7 */
/* @0xe32e8 vcmpe.f64 d6, d7 */
/* @0xe32ec vmrs APSR_nzcv, fpscr */
/* @0xe32f0 movlt r0, #0 */
/* @0xe32f4 movge r0, #1 */
/* @0xe32f8 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe32fc ldr r3, [pc, #-0x2e4] */
/* @0xe3300 vcvt.f64.s32 d6, s12 */
/* @0xe3304 ldr r3, [r6, r3] */
/* @0xe3308 vldr d7, [r3] */
/* @0xe330c vneg.f64 d5, d7 */
/* @0xe3310 vcmpe.f64 d6, d5 */
/* @0xe3314 vmrs APSR_nzcv, fpscr */
/* @0xe3318 movmi r0, #1 */
/* @0xe331c bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3320 vcmpe.f64 d6, d7 */
/* @0xe3324 vmrs APSR_nzcv, fpscr */
/* @0xe3328 movle r0, #0 */
/* @0xe332c movgt r0, #1 */
/* @0xe3330 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3334 ldr r3, [pc, #-0x31c] */
/* @0xe3338 vcvt.f64.s32 d6, s12 */
/* @0xe333c ldr r3, [r6, r3] */
/* @0xe3340 vldr d7, [r3] */
/* @0xe3344 vneg.f64 d5, d7 */
/* @0xe3348 vcmpe.f64 d6, d5 */
/* @0xe334c vmrs APSR_nzcv, fpscr */
/* @0xe3350 movlt r0, #0 */
/* @0xe3354 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3358 vcmpe.f64 d6, d7 */
/* @0xe335c vmrs APSR_nzcv, fpscr */
/* @0xe3360 movhi r0, #0 */
/* @0xe3364 movls r0, #1 */
/* @0xe3368 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe336c vcvt.f64.s32 d6, s12 */
/* @0xe3370 ldr r3, [pc, #-0x358] */
/* @0xe3374 ldr r3, [r6, r3] */
/* @0xe3378 vldr d7, [r3] */
/* @0xe337c vcmpe.f64 d6, d7 */
/* @0xe3380 vmrs APSR_nzcv, fpscr */
/* @0xe3384 movhi r0, #0 */
/* @0xe3388 movls r0, #1 */
/* @0xe338c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3390 ldr r3, [pc, #-0x378] */
/* @0xe3394 vcvt.f64.s32 d6, s12 */
/* @0xe3398 ldr r3, [r6, r3] */
/* @0xe339c vldr d7, [r3] */
/* @0xe33a0 vneg.f64 d7, d7 */
/* @0xe33a4 vcmpe.f64 d6, d7 */
/* @0xe33a8 vmrs APSR_nzcv, fpscr */
/* @0xe33ac movpl r0, #0 */
/* @0xe33b0 movmi r0, #1 */
/* @0xe33b4 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe33b8 cmp r11, #66 */
/* @0xe33bc beq 0xe37b4 <_Z5DoSetjPhPKhP6VMExec+0x17a0> */
/* @0xe33c0 sub r9, r9, #1 */
/* @0xe33c4 cmp r9, #5 */
/* @0xe33c8 addls pc, pc, r9, lsl #2 */
/* @0xe33cc b 0xe3cc4 <_Z5DoSetjPhPKhP6VMExec+0x1cb0> */
/* @0xe33d0 b 0xe33e8 <_Z5DoSetjPhPKhP6VMExec+0x13d4> */
/* @0xe33d4 b 0xe33e8 <_Z5DoSetjPhPKhP6VMExec+0x13d4> */
/* @0xe33d8 b 0xe33e8 <_Z5DoSetjPhPKhP6VMExec+0x13d4> */
/* @0xe33dc b 0xe33f0 <_Z5DoSetjPhPKhP6VMExec+0x13dc> */
/* @0xe33e0 b 0xe33e8 <_Z5DoSetjPhPKhP6VMExec+0x13d4> */
/* @0xe33e4 b 0xe33e8 <_Z5DoSetjPhPKhP6VMExec+0x13d4> */
/* @0xe33e8 mov r0, #0 */
/* @0xe33ec b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe33f0 mov r0, #1 */
/* @0xe33f4 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe33f8 ldrd r0, r1, [r10] */
/* @0xe33fc sub r9, r9, #1 */
/* @0xe3400 bl 0x319164 <__floatdidf> */
/* @0xe3404 vldr d7, [r4] */
/* @0xe3408 vmov d6, r0, r1 */
/* @0xe340c vsub.f64 d7, d7, d6 */
/* @0xe3410 cmp r9, #5 */
/* @0xe3414 addls pc, pc, r9, lsl #2 */
/* @0xe3418 b 0xe3cb4 <_Z5DoSetjPhPKhP6VMExec+0x1ca0> */
/* @0xe341c b 0xe3500 <_Z5DoSetjPhPKhP6VMExec+0x14ec> */
/* @0xe3420 b 0xe34e0 <_Z5DoSetjPhPKhP6VMExec+0x14cc> */
/* @0xe3424 b 0xe34ac <_Z5DoSetjPhPKhP6VMExec+0x1498> */
/* @0xe3428 b 0xe3478 <_Z5DoSetjPhPKhP6VMExec+0x1464> */
/* @0xe342c b 0xe3454 <_Z5DoSetjPhPKhP6VMExec+0x1440> */
/* @0xe3430 b 0xe3434 <_Z5DoSetjPhPKhP6VMExec+0x1420> */
/* @0xe3434 ldr r3, [pc, #-0x41c] */
/* @0xe3438 ldr r3, [r6, r3] */
/* @0xe343c vldr d6, [r3] */
/* @0xe3440 vcmpe.f64 d7, d6 */
/* @0xe3444 vmrs APSR_nzcv, fpscr */
/* @0xe3448 movle r0, #0 */
/* @0xe344c movgt r0, #1 */
/* @0xe3450 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3454 ldr r3, [pc, #-0x43c] */
/* @0xe3458 ldr r3, [r6, r3] */
/* @0xe345c vldr d6, [r3] */
/* @0xe3460 vneg.f64 d6, d6 */
/* @0xe3464 vcmpe.f64 d7, d6 */
/* @0xe3468 vmrs APSR_nzcv, fpscr */
/* @0xe346c movlt r0, #0 */
/* @0xe3470 movge r0, #1 */
/* @0xe3474 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3478 ldr r3, [pc, #-0x460] */
/* @0xe347c ldr r3, [r6, r3] */
/* @0xe3480 vldr d6, [r3] */
/* @0xe3484 vneg.f64 d5, d6 */
/* @0xe3488 vcmpe.f64 d7, d5 */
/* @0xe348c vmrs APSR_nzcv, fpscr */
/* @0xe3490 movmi r0, #1 */
/* @0xe3494 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3498 vcmpe.f64 d7, d6 */
/* @0xe349c vmrs APSR_nzcv, fpscr */
/* @0xe34a0 movle r0, #0 */
/* @0xe34a4 movgt r0, #1 */
/* @0xe34a8 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe34ac ldr r3, [pc, #-0x494] */
/* @0xe34b0 ldr r3, [r6, r3] */
/* @0xe34b4 vldr d6, [r3] */
/* @0xe34b8 vneg.f64 d5, d6 */
/* @0xe34bc vcmpe.f64 d7, d5 */
/* @0xe34c0 vmrs APSR_nzcv, fpscr */
/* @0xe34c4 movlt r0, #0 */
/* @0xe34c8 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe34cc vcmpe.f64 d7, d6 */
/* @0xe34d0 vmrs APSR_nzcv, fpscr */
/* @0xe34d4 movhi r0, #0 */
/* @0xe34d8 movls r0, #1 */
/* @0xe34dc b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe34e0 ldr r3, [pc, #-0x4c8] */
/* @0xe34e4 ldr r3, [r6, r3] */
/* @0xe34e8 vldr d6, [r3] */
/* @0xe34ec vcmpe.f64 d7, d6 */
/* @0xe34f0 vmrs APSR_nzcv, fpscr */
/* @0xe34f4 movhi r0, #0 */
/* @0xe34f8 movls r0, #1 */
/* @0xe34fc b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3500 ldr r3, [pc, #-0x4e8] */
/* @0xe3504 ldr r3, [r6, r3] */
/* @0xe3508 vldr d6, [r3] */
/* @0xe350c vneg.f64 d6, d6 */
/* @0xe3510 vcmpe.f64 d7, d6 */
/* @0xe3514 vmrs APSR_nzcv, fpscr */
/* @0xe3518 movpl r0, #0 */
/* @0xe351c movmi r0, #1 */
/* @0xe3520 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3524 ldrd r0, r1, [r4] */
/* @0xe3528 sub r9, r9, #1 */
/* @0xe352c bl 0x319164 <__floatdidf> */
/* @0xe3530 vldr d7, [r10] */
/* @0xe3534 vmov d6, r0, r1 */
/* @0xe3538 vsub.f64 d7, d6, d7 */
/* @0xe353c cmp r9, #5 */
/* @0xe3540 addls pc, pc, r9, lsl #2 */
/* @0xe3544 b 0xe3c04 <_Z5DoSetjPhPKhP6VMExec+0x1bf0> */
/* @0xe3548 b 0xe362c <_Z5DoSetjPhPKhP6VMExec+0x1618> */
/* @0xe354c b 0xe360c <_Z5DoSetjPhPKhP6VMExec+0x15f8> */
/* @0xe3550 b 0xe35d8 <_Z5DoSetjPhPKhP6VMExec+0x15c4> */
/* @0xe3554 b 0xe35a4 <_Z5DoSetjPhPKhP6VMExec+0x1590> */
/* @0xe3558 b 0xe3580 <_Z5DoSetjPhPKhP6VMExec+0x156c> */
/* @0xe355c b 0xe3560 <_Z5DoSetjPhPKhP6VMExec+0x154c> */
/* @0xe3560 ldr r3, [pc, #-0x548] */
/* @0xe3564 ldr r3, [r6, r3] */
/* @0xe3568 vldr d6, [r3] */
/* @0xe356c vcmpe.f64 d7, d6 */
/* @0xe3570 vmrs APSR_nzcv, fpscr */
/* @0xe3574 movle r0, #0 */
/* @0xe3578 movgt r0, #1 */
/* @0xe357c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3580 ldr r3, [pc, #-0x568] */
/* @0xe3584 ldr r3, [r6, r3] */
/* @0xe3588 vldr d6, [r3] */
/* @0xe358c vneg.f64 d6, d6 */
/* @0xe3590 vcmpe.f64 d7, d6 */
/* @0xe3594 vmrs APSR_nzcv, fpscr */
/* @0xe3598 movlt r0, #0 */
/* @0xe359c movge r0, #1 */
/* @0xe35a0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe35a4 ldr r3, [pc, #-0x58c] */
/* @0xe35a8 ldr r3, [r6, r3] */
/* @0xe35ac vldr d6, [r3] */
/* @0xe35b0 vneg.f64 d5, d6 */
/* @0xe35b4 vcmpe.f64 d7, d5 */
/* @0xe35b8 vmrs APSR_nzcv, fpscr */
/* @0xe35bc movmi r0, #1 */
/* @0xe35c0 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe35c4 vcmpe.f64 d7, d6 */
/* @0xe35c8 vmrs APSR_nzcv, fpscr */
/* @0xe35cc movle r0, #0 */
/* @0xe35d0 movgt r0, #1 */
/* @0xe35d4 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe35d8 ldr r3, [pc, #-0x5c0] */
/* @0xe35dc ldr r3, [r6, r3] */
/* @0xe35e0 vldr d6, [r3] */
/* @0xe35e4 vneg.f64 d5, d6 */
/* @0xe35e8 vcmpe.f64 d7, d5 */
/* @0xe35ec vmrs APSR_nzcv, fpscr */
/* @0xe35f0 movlt r0, #0 */
/* @0xe35f4 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe35f8 vcmpe.f64 d7, d6 */
/* @0xe35fc vmrs APSR_nzcv, fpscr */
/* @0xe3600 movhi r0, #0 */
/* @0xe3604 movls r0, #1 */
/* @0xe3608 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe360c ldr r3, [pc, #-0x5f4] */
/* @0xe3610 ldr r3, [r6, r3] */
/* @0xe3614 vldr d6, [r3] */
/* @0xe3618 vcmpe.f64 d7, d6 */
/* @0xe361c vmrs APSR_nzcv, fpscr */
/* @0xe3620 movhi r0, #0 */
/* @0xe3624 movls r0, #1 */
/* @0xe3628 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe362c ldr r3, [pc, #-0x614] */
/* @0xe3630 ldr r3, [r6, r3] */
/* @0xe3634 vldr d6, [r3] */
/* @0xe3638 vneg.f64 d6, d6 */
/* @0xe363c vcmpe.f64 d7, d6 */
/* @0xe3640 vmrs APSR_nzcv, fpscr */
/* @0xe3644 movpl r0, #0 */
/* @0xe3648 movmi r0, #1 */
/* @0xe364c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3650 ldr r2, [r4] */
/* @0xe3654 sub r9, r9, #1 */
/* @0xe3658 ldr r3, [r10] */
/* @0xe365c cmp r2, #0 */
/* @0xe3660 rsbeq r3, r3, #0 */
/* @0xe3664 rsbne r3, r3, #1 */
/* @0xe3668 cmp r9, #5 */
/* @0xe366c addls pc, pc, r9, lsl #2 */
/* @0xe3670 b 0xe3c64 <_Z5DoSetjPhPKhP6VMExec+0x1c50> */
/* @0xe3674 b 0xe3780 <_Z5DoSetjPhPKhP6VMExec+0x176c> */
/* @0xe3678 b 0xe3758 <_Z5DoSetjPhPKhP6VMExec+0x1744> */
/* @0xe367c b 0xe371c <_Z5DoSetjPhPKhP6VMExec+0x1708> */
/* @0xe3680 b 0xe36e0 <_Z5DoSetjPhPKhP6VMExec+0x16cc> */
/* @0xe3684 b 0xe36b4 <_Z5DoSetjPhPKhP6VMExec+0x16a0> */
/* @0xe3688 b 0xe368c <_Z5DoSetjPhPKhP6VMExec+0x1678> */
/* @0xe368c vmov s15, r3 */
/* @0xe3690 ldr r3, [pc, #-0x678] */
/* @0xe3694 vcvt.f64.s32 d6, s15 */
/* @0xe3698 ldr r3, [r6, r3] */
/* @0xe369c vldr d7, [r3] */
/* @0xe36a0 vcmpe.f64 d6, d7 */
/* @0xe36a4 vmrs APSR_nzcv, fpscr */
/* @0xe36a8 movle r0, #0 */
/* @0xe36ac movgt r0, #1 */
/* @0xe36b0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe36b4 vmov s15, r3 */
/* @0xe36b8 ldr r2, [pc, #-0x6a0] */
/* @0xe36bc vcvt.f64.s32 d6, s15 */
/* @0xe36c0 ldr r3, [r6, r2] */
/* @0xe36c4 vldr d7, [r3] */
/* @0xe36c8 vneg.f64 d7, d7 */
/* @0xe36cc vcmpe.f64 d6, d7 */
/* @0xe36d0 vmrs APSR_nzcv, fpscr */
/* @0xe36d4 movlt r0, #0 */
/* @0xe36d8 movge r0, #1 */
/* @0xe36dc b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe36e0 vmov s15, r3 */
/* @0xe36e4 ldr r2, [pc, #-0x6cc] */
/* @0xe36e8 vcvt.f64.s32 d6, s15 */
/* @0xe36ec ldr r3, [r6, r2] */
/* @0xe36f0 vldr d7, [r3] */
/* @0xe36f4 vneg.f64 d5, d7 */
/* @0xe36f8 vcmpe.f64 d6, d5 */
/* @0xe36fc vmrs APSR_nzcv, fpscr */
/* @0xe3700 movmi r0, #1 */
/* @0xe3704 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3708 vcmpe.f64 d6, d7 */
/* @0xe370c vmrs APSR_nzcv, fpscr */
/* @0xe3710 movle r0, #0 */
/* @0xe3714 movgt r0, #1 */
/* @0xe3718 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe371c vmov s15, r3 */
/* @0xe3720 ldr r2, [pc, #-0x708] */
/* @0xe3724 vcvt.f64.s32 d6, s15 */
/* @0xe3728 ldr r3, [r6, r2] */
/* @0xe372c vldr d7, [r3] */
/* @0xe3730 vneg.f64 d5, d7 */
/* @0xe3734 vcmpe.f64 d6, d5 */
/* @0xe3738 vmrs APSR_nzcv, fpscr */
/* @0xe373c movlt r0, #0 */
/* @0xe3740 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3744 vcmpe.f64 d6, d7 */
/* @0xe3748 vmrs APSR_nzcv, fpscr */
/* @0xe374c movhi r0, #0 */
/* @0xe3750 movls r0, #1 */
/* @0xe3754 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3758 vmov s15, r3 */
/* @0xe375c ldr r3, [pc, #-0x744] */
/* @0xe3760 vcvt.f64.s32 d6, s15 */
/* @0xe3764 ldr r3, [r6, r3] */
/* @0xe3768 vldr d7, [r3] */
/* @0xe376c vcmpe.f64 d6, d7 */
/* @0xe3770 vmrs APSR_nzcv, fpscr */
/* @0xe3774 movhi r0, #0 */
/* @0xe3778 movls r0, #1 */
/* @0xe377c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3780 vmov s15, r3 */
/* @0xe3784 ldr r2, [pc, #-0x76c] */
/* @0xe3788 vcvt.f64.s32 d6, s15 */
/* @0xe378c ldr r3, [r6, r2] */
/* @0xe3790 vldr d7, [r3] */
/* @0xe3794 vneg.f64 d7, d7 */
/* @0xe3798 vcmpe.f64 d6, d7 */
/* @0xe379c vmrs APSR_nzcv, fpscr */
/* @0xe37a0 movpl r0, #0 */
/* @0xe37a4 movmi r0, #1 */
/* @0xe37a8 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe37ac cmp r11, #36 */
/* @0xe37b0 bne 0xe33c0 <_Z5DoSetjPhPKhP6VMExec+0x13ac> */
/* @0xe37b4 ldr r2, [r4] */
/* @0xe37b8 sub r9, r9, #1 */
/* @0xe37bc ldr r3, [r10] */
/* @0xe37c0 rsb r3, r3, r2 */
/* @0xe37c4 cmp r9, #5 */
/* @0xe37c8 addls pc, pc, r9, lsl #2 */
/* @0xe37cc b 0xe3c54 <_Z5DoSetjPhPKhP6VMExec+0x1c40> */
/* @0xe37d0 b 0xe38dc <_Z5DoSetjPhPKhP6VMExec+0x18c8> */
/* @0xe37d4 b 0xe38b4 <_Z5DoSetjPhPKhP6VMExec+0x18a0> */
/* @0xe37d8 b 0xe3878 <_Z5DoSetjPhPKhP6VMExec+0x1864> */
/* @0xe37dc b 0xe383c <_Z5DoSetjPhPKhP6VMExec+0x1828> */
/* @0xe37e0 b 0xe3810 <_Z5DoSetjPhPKhP6VMExec+0x17fc> */
/* @0xe37e4 b 0xe37e8 <_Z5DoSetjPhPKhP6VMExec+0x17d4> */
/* @0xe37e8 vmov s15, r3 */
/* @0xe37ec ldr r3, [pc, #-0x7d4] */
/* @0xe37f0 vcvt.f64.s32 d6, s15 */
/* @0xe37f4 ldr r3, [r6, r3] */
/* @0xe37f8 vldr d7, [r3] */
/* @0xe37fc vcmpe.f64 d6, d7 */
/* @0xe3800 vmrs APSR_nzcv, fpscr */
/* @0xe3804 movle r0, #0 */
/* @0xe3808 movgt r0, #1 */
/* @0xe380c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3810 vmov s15, r3 */
/* @0xe3814 ldr r2, [pc, #-0x7fc] */
/* @0xe3818 vcvt.f64.s32 d6, s15 */
/* @0xe381c ldr r3, [r6, r2] */
/* @0xe3820 vldr d7, [r3] */
/* @0xe3824 vneg.f64 d7, d7 */
/* @0xe3828 vcmpe.f64 d6, d7 */
/* @0xe382c vmrs APSR_nzcv, fpscr */
/* @0xe3830 movlt r0, #0 */
/* @0xe3834 movge r0, #1 */
/* @0xe3838 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe383c vmov s15, r3 */
/* @0xe3840 ldr r2, [pc, #-0x828] */
/* @0xe3844 vcvt.f64.s32 d6, s15 */
/* @0xe3848 ldr r3, [r6, r2] */
/* @0xe384c vldr d7, [r3] */
/* @0xe3850 vneg.f64 d5, d7 */
/* @0xe3854 vcmpe.f64 d6, d5 */
/* @0xe3858 vmrs APSR_nzcv, fpscr */
/* @0xe385c movmi r0, #1 */
/* @0xe3860 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3864 vcmpe.f64 d6, d7 */
/* @0xe3868 vmrs APSR_nzcv, fpscr */
/* @0xe386c movle r0, #0 */
/* @0xe3870 movgt r0, #1 */
/* @0xe3874 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3878 vmov s15, r3 */
/* @0xe387c ldr r2, [pc, #-0x864] */
/* @0xe3880 vcvt.f64.s32 d6, s15 */
/* @0xe3884 ldr r3, [r6, r2] */
/* @0xe3888 vldr d7, [r3] */
/* @0xe388c vneg.f64 d5, d7 */
/* @0xe3890 vcmpe.f64 d6, d5 */
/* @0xe3894 vmrs APSR_nzcv, fpscr */
/* @0xe3898 movlt r0, #0 */
/* @0xe389c blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe38a0 vcmpe.f64 d6, d7 */
/* @0xe38a4 vmrs APSR_nzcv, fpscr */
/* @0xe38a8 movhi r0, #0 */
/* @0xe38ac movls r0, #1 */
/* @0xe38b0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe38b4 vmov s15, r3 */
/* @0xe38b8 ldr r3, [pc, #-0x8a0] */
/* @0xe38bc vcvt.f64.s32 d6, s15 */
/* @0xe38c0 ldr r3, [r6, r3] */
/* @0xe38c4 vldr d7, [r3] */
/* @0xe38c8 vcmpe.f64 d6, d7 */
/* @0xe38cc vmrs APSR_nzcv, fpscr */
/* @0xe38d0 movhi r0, #0 */
/* @0xe38d4 movls r0, #1 */
/* @0xe38d8 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe38dc vmov s15, r3 */
/* @0xe38e0 ldr r2, [pc, #-0x8c8] */
/* @0xe38e4 vcvt.f64.s32 d6, s15 */
/* @0xe38e8 ldr r3, [r6, r2] */
/* @0xe38ec vldr d7, [r3] */
/* @0xe38f0 vneg.f64 d7, d7 */
/* @0xe38f4 vcmpe.f64 d6, d7 */
/* @0xe38f8 vmrs APSR_nzcv, fpscr */
/* @0xe38fc movpl r0, #0 */
/* @0xe3900 movmi r0, #1 */
/* @0xe3904 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3908 ldrd r0, r1, [r4] */
/* @0xe390c sub r9, r9, #1 */
/* @0xe3910 ldrd r2, r3, [r10] */
/* @0xe3914 subs r0, r0, r2 */
/* @0xe3918 sbc r1, r1, r3 */
/* @0xe391c cmp r9, #5 */
/* @0xe3920 addls pc, pc, r9, lsl #2 */
/* @0xe3924 b 0xe3c34 <_Z5DoSetjPhPKhP6VMExec+0x1c20> */
/* @0xe3928 b 0xe3a34 <_Z5DoSetjPhPKhP6VMExec+0x1a20> */
/* @0xe392c b 0xe3a0c <_Z5DoSetjPhPKhP6VMExec+0x19f8> */
/* @0xe3930 b 0xe39d0 <_Z5DoSetjPhPKhP6VMExec+0x19bc> */
/* @0xe3934 b 0xe3994 <_Z5DoSetjPhPKhP6VMExec+0x1980> */
/* @0xe3938 b 0xe3968 <_Z5DoSetjPhPKhP6VMExec+0x1954> */
/* @0xe393c b 0xe3940 <_Z5DoSetjPhPKhP6VMExec+0x192c> */
/* @0xe3940 bl 0x319164 <__floatdidf> */
/* @0xe3944 ldr r3, [pc, #-0x92c] */
/* @0xe3948 ldr r3, [r6, r3] */
/* @0xe394c vldr d7, [r3] */
/* @0xe3950 vmov d6, r0, r1 */
/* @0xe3954 vcmpe.f64 d6, d7 */
/* @0xe3958 vmrs APSR_nzcv, fpscr */
/* @0xe395c movle r0, #0 */
/* @0xe3960 movgt r0, #1 */
/* @0xe3964 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3968 bl 0x319164 <__floatdidf> */
/* @0xe396c ldr r3, [pc, #-0x954] */
/* @0xe3970 ldr r3, [r6, r3] */
/* @0xe3974 vldr d7, [r3] */
/* @0xe3978 vneg.f64 d7, d7 */
/* @0xe397c vmov d6, r0, r1 */
/* @0xe3980 vcmpe.f64 d6, d7 */
/* @0xe3984 vmrs APSR_nzcv, fpscr */
/* @0xe3988 movlt r0, #0 */
/* @0xe398c movge r0, #1 */
/* @0xe3990 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3994 bl 0x319164 <__floatdidf> */
/* @0xe3998 ldr r3, [pc, #-0x980] */
/* @0xe399c ldr r3, [r6, r3] */
/* @0xe39a0 vldr d7, [r3] */
/* @0xe39a4 vneg.f64 d5, d7 */
/* @0xe39a8 vmov d6, r0, r1 */
/* @0xe39ac vcmpe.f64 d6, d5 */
/* @0xe39b0 vmrs APSR_nzcv, fpscr */
/* @0xe39b4 movmi r0, #1 */
/* @0xe39b8 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe39bc vcmpe.f64 d6, d7 */
/* @0xe39c0 vmrs APSR_nzcv, fpscr */
/* @0xe39c4 movle r0, #0 */
/* @0xe39c8 movgt r0, #1 */
/* @0xe39cc b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe39d0 bl 0x319164 <__floatdidf> */
/* @0xe39d4 ldr r3, [pc, #-0x9bc] */
/* @0xe39d8 ldr r3, [r6, r3] */
/* @0xe39dc vldr d7, [r3] */
/* @0xe39e0 vneg.f64 d5, d7 */
/* @0xe39e4 vmov d6, r0, r1 */
/* @0xe39e8 vcmpe.f64 d6, d5 */
/* @0xe39ec vmrs APSR_nzcv, fpscr */
/* @0xe39f0 movlt r0, #0 */
/* @0xe39f4 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe39f8 vcmpe.f64 d6, d7 */
/* @0xe39fc vmrs APSR_nzcv, fpscr */
/* @0xe3a00 movhi r0, #0 */
/* @0xe3a04 movls r0, #1 */
/* @0xe3a08 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3a0c bl 0x319164 <__floatdidf> */
/* @0xe3a10 ldr r3, [pc, #-0x9f8] */
/* @0xe3a14 ldr r3, [r6, r3] */
/* @0xe3a18 vldr d7, [r3] */
/* @0xe3a1c vmov d6, r0, r1 */
/* @0xe3a20 vcmpe.f64 d6, d7 */
/* @0xe3a24 vmrs APSR_nzcv, fpscr */
/* @0xe3a28 movhi r0, #0 */
/* @0xe3a2c movls r0, #1 */
/* @0xe3a30 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3a34 bl 0x319164 <__floatdidf> */
/* @0xe3a38 ldr r3, [pc, #-0xa20] */
/* @0xe3a3c ldr r3, [r6, r3] */
/* @0xe3a40 vldr d7, [r3] */
/* @0xe3a44 vneg.f64 d7, d7 */
/* @0xe3a48 vmov d6, r0, r1 */
/* @0xe3a4c vcmpe.f64 d6, d7 */
/* @0xe3a50 vmrs APSR_nzcv, fpscr */
/* @0xe3a54 movpl r0, #0 */
/* @0xe3a58 movmi r0, #1 */
/* @0xe3a5c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3a60 ldr r0, [pc, #-0xa44] */
/* @0xe3a64 add r0, pc, r0 */
/* @0xe3a68 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe3a6c mov r0, r4 */
/* @0xe3a70 b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* @0xe3a74 add r7, sp, #32 */
/* @0xe3a78 mov r1, sp */
/* @0xe3a7c mov r0, r7 */
/* @0xe3a80 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0xe3a84 cmp r0, #1 */
/* @0xe3a88 beq 0xe3cf4 <_Z5DoSetjPhPKhP6VMExec+0x1ce0> */
/* @0xe3a8c cmp r0, #0 */
/* @0xe3a90 bne 0xe247c <_Z5DoSetjPhPKhP6VMExec+0x468> */
/* @0xe3a94 ldr r3, [sp, #0x20] */
/* @0xe3a98 mov r2, #5 */
/* @0xe3a9c ldr r0, [sp, #0x10] */
/* @0xe3aa0 add r1, sp, #48 */
/* @0xe3aa4 str r2, [sp, #0x3c] */
/* @0xe3aa8 sub r9, r8, #4 */
/* @0xe3aac ldr r2, [r3] */
/* @0xe3ab0 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* @0xe3ab4 ldr r3, [sp, #0x3c] */
/* @0xe3ab8 bic r3, r3, #-16777216 */
/* @0xe3abc cmp r3, r4 */
/* @0xe3ac0 moveq r3, #0 */
/* @0xe3ac4 movne r3, #1 */
/* @0xe3ac8 str r3, [r8, #-0x4] */
/* @0xe3acc ldr r3, [sp, #0x2c] */
/* @0xe3ad0 sub r3, r3, #1 */
/* @0xe3ad4 bic r3, r3, #-16777216 */
/* @0xe3ad8 bic r3, r3, #3 */
/* @0xe3adc cmp r3, #0 */
/* @0xe3ae0 beq 0xe3d08 <_Z5DoSetjPhPKhP6VMExec+0x1cf4> */
/* @0xe3ae4 ldr r1, [sp, #0xc] */
/* @0xe3ae8 mov r3, #0 */
/* @0xe3aec str r3, [sp, #0x28] */
/* @0xe3af0 mov r2, #5 */
/* @0xe3af4 sub r1, r1, #1 */
/* @0xe3af8 str r3, [sp, #0x20] */
/* @0xe3afc bic r3, r1, #-16777216 */
/* @0xe3b00 str r2, [sp, #0x2c] */
/* @0xe3b04 bic r3, r3, #3 */
/* @0xe3b08 cmp r3, #0 */
/* @0xe3b0c beq 0xe3d14 <_Z5DoSetjPhPKhP6VMExec+0x1d00> */
/* @0xe3b10 ldr r1, [sp, #0x1c] */
/* @0xe3b14 mov r3, #0 */
/* @0xe3b18 str r3, [sp, #0x8] */
/* @0xe3b1c mov r2, #5 */
/* @0xe3b20 sub r1, r1, #1 */
/* @0xe3b24 str r3, [sp] */
/* @0xe3b28 bic r3, r1, #-16777216 */
/* @0xe3b2c str r2, [sp, #0xc] */
/* @0xe3b30 bic r3, r3, #3 */
/* @0xe3b34 cmp r3, #0 */
/* @0xe3b38 movne r0, r9 */
/* @0xe3b3c bne 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* @0xe3b40 mov r0, r6 */
/* @0xe3b44 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe3b48 mov r0, r9 */
/* @0xe3b4c b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* @0xe3b50 mov r0, r7 */
/* @0xe3b54 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe3b58 b 0xe25fc <_Z5DoSetjPhPKhP6VMExec+0x5e8> */
/* @0xe3b5c ldr r0, [pc, #-0xb3c] */
/* @0xe3b60 add r0, pc, r0 */
/* @0xe3b64 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe3b68 mov r0, r8 */
/* @0xe3b6c b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* @0xe3b70 rsbs r12, r0, #1 */
/* @0xe3b74 movlo r12, #0 */
/* @0xe3b78 tst r12, r2 */
/* @0xe3b7c beq 0xe3b90 <_Z5DoSetjPhPKhP6VMExec+0x1b7c> */
/* @0xe3b80 ldrb r2, [r1] */
/* @0xe3b84 cmp r2, #0 */
/* @0xe3b88 moveq r0, r2 */
/* @0xe3b8c beq 0xe3200 <_Z5DoSetjPhPKhP6VMExec+0x11ec> */
/* @0xe3b90 cmp r1, #0 */
/* @0xe3b94 movne r3, #0 */
/* @0xe3b98 andeq r3, r3, #1 */
/* @0xe3b9c cmp r3, #0 */
/* @0xe3ba0 beq 0xe3bb4 <_Z5DoSetjPhPKhP6VMExec+0x1ba0> */
/* @0xe3ba4 ldrb r3, [r0] */
/* @0xe3ba8 cmp r3, #0 */
/* @0xe3bac moveq r0, r3 */
/* @0xe3bb0 beq 0xe3200 <_Z5DoSetjPhPKhP6VMExec+0x11ec> */
/* @0xe3bb4 subs r0, r1, r0 */
/* @0xe3bb8 movne r0, #1 */
/* @0xe3bbc b 0xe3200 <_Z5DoSetjPhPKhP6VMExec+0x11ec> */
/* @0xe3bc0 vmrs APSR_nzcv, fpscr */
/* @0xe3bc4 moveq r3, #0 */
/* @0xe3bc8 movne r3, #1 */
/* @0xe3bcc str r3, [r8, #-0x4] */
/* @0xe3bd0 b 0xe210c <_Z5DoSetjPhPKhP6VMExec+0xf8> */
/* @0xe3bd4 ldr r0, [pc, #-0xbb0] */
/* @0xe3bd8 add r0, pc, r0 */
/* @0xe3bdc bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe3be0 mov r0, r8 */
/* @0xe3be4 b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* @0xe3be8 mov r12, #1 */
/* @0xe3bec mov r0, r3 */
/* @0xe3bf0 b 0xe3b78 <_Z5DoSetjPhPKhP6VMExec+0x1b64> */
/* @0xe3bf4 ldr r0, [r7, #-0x4] */
/* @0xe3bf8 adds r0, r0, #0 */
/* @0xe3bfc movne r0, #1 */
/* @0xe3c00 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3c04 ldr r0, [r7, #-0x4] */
/* @0xe3c08 adds r0, r0, #0 */
/* @0xe3c0c movne r0, #1 */
/* @0xe3c10 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3c14 ldr r0, [r7, #-0x4] */
/* @0xe3c18 adds r0, r0, #0 */
/* @0xe3c1c movne r0, #1 */
/* @0xe3c20 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3c24 ldr r0, [r7, #-0x4] */
/* @0xe3c28 adds r0, r0, #0 */
/* @0xe3c2c movne r0, #1 */
/* @0xe3c30 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3c34 ldr r0, [r7, #-0x4] */
/* @0xe3c38 adds r0, r0, #0 */
/* @0xe3c3c movne r0, #1 */
/* @0xe3c40 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3c44 ldr r0, [r7, #-0x4] */
/* @0xe3c48 adds r0, r0, #0 */
/* @0xe3c4c movne r0, #1 */
/* @0xe3c50 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3c54 ldr r0, [r7, #-0x4] */
/* @0xe3c58 adds r0, r0, #0 */
/* @0xe3c5c movne r0, #1 */
/* @0xe3c60 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3c64 ldr r0, [r7, #-0x4] */
/* @0xe3c68 adds r0, r0, #0 */
/* @0xe3c6c movne r0, #1 */
/* @0xe3c70 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3c74 ldr r0, [r7, #-0x4] */
/* @0xe3c78 adds r0, r0, #0 */
/* @0xe3c7c movne r0, #1 */
/* @0xe3c80 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3c84 ldr r0, [r7, #-0x4] */
/* @0xe3c88 adds r0, r0, #0 */
/* @0xe3c8c movne r0, #1 */
/* @0xe3c90 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3c94 ldr r0, [r7, #-0x4] */
/* @0xe3c98 adds r0, r0, #0 */
/* @0xe3c9c movne r0, #1 */
/* @0xe3ca0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3ca4 ldr r0, [r7, #-0x4] */
/* @0xe3ca8 adds r0, r0, #0 */
/* @0xe3cac movne r0, #1 */
/* @0xe3cb0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3cb4 ldr r0, [r7, #-0x4] */
/* @0xe3cb8 adds r0, r0, #0 */
/* @0xe3cbc movne r0, #1 */
/* @0xe3cc0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3cc4 ldr r0, [r7, #-0x4] */
/* @0xe3cc8 adds r0, r0, #0 */
/* @0xe3ccc movne r0, #1 */
/* @0xe3cd0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3cd4 ldr r0, [r7, #-0x4] */
/* @0xe3cd8 adds r0, r0, #0 */
/* @0xe3cdc movne r0, #1 */
/* @0xe3ce0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3ce4 ldr r0, [r7, #-0x4] */
/* @0xe3ce8 adds r0, r0, #0 */
/* @0xe3cec movne r0, #1 */
/* @0xe3cf0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3cf4 ldr r0, [pc, #-0xccc] */
/* @0xe3cf8 add r0, pc, r0 */
/* @0xe3cfc bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe3d00 mov r0, r8 */
/* @0xe3d04 b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* @0xe3d08 mov r0, r7 */
/* @0xe3d0c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe3d10 b 0xe3ae4 <_Z5DoSetjPhPKhP6VMExec+0x1ad0> */
/* @0xe3d14 mov r0, sp */
/* @0xe3d18 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe3d1c b 0xe3b10 <_Z5DoSetjPhPKhP6VMExec+0x1afc> */
/* @0xe3d20 mov r7, r4 */
/* @0xe3d24 b 0xe2268 <_Z5DoSetjPhPKhP6VMExec+0x254> */
/* @0xe3d28 mov r4, r10 */
/* @0xe3d2c b 0xe2224 <_Z5DoSetjPhPKhP6VMExec+0x210> */

/* ── FUNC 0xe3d30 · YYGML_CallLegacyFunction(CInstance*, CInstance*, YYRValue&, int, int, YYRValue**) · size=296 · insn=74 */
/* @0xe3d30 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe3d34 add r11, sp, #32 */
/* @0xe3d38 ldr r7, [pc, #0x10c] */
/* @0xe3d3c sub sp, sp, #28 */
/* @0xe3d40 mov r5, r3 */
/* @0xe3d44 ldr r3, [pc, #0x104] */
/* @0xe3d48 lsl r4, r5, #4 */
/* @0xe3d4c ldr r7, [pc, r7] */
/* @0xe3d50 ldr r12, [r11, #0x4] */
/* @0xe3d54 add r4, r4, #8 */
/* @0xe3d58 ldr r3, [pc, r3] */
/* @0xe3d5c ldr lr, [r7] */
/* @0xe3d60 sub sp, sp, r4 */
/* @0xe3d64 cmp r5, #0 */
/* @0xe3d68 ldr r3, [r3] */
/* @0xe3d6c add r12, r12, r12, lsl #2 */
/* @0xe3d70 add r9, sp, #8 */
/* @0xe3d74 ldr r10, [r11, #0x8] */
/* @0xe3d78 mov r6, r2 */
/* @0xe3d7c str lr, [r11, #-0x28] */
/* @0xe3d80 add r8, r3, r12, lsl #4 */
/* @0xe3d84 str r0, [r11, #-0x30] */
/* @0xe3d88 subgt r10, r10, #4 */
/* @0xe3d8c str r1, [r11, #-0x34] */
/* @0xe3d90 movgt r4, r9 */
/* @0xe3d94 movgt lr, #0 */
/* @0xe3d98 ble 0xe3dc8 <_Z24YYGML_CallLegacyFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x98> */
/* @0xe3d9c ldr r3, [r10, #0x4]! */
/* @0xe3da0 add lr, lr, #1 */
/* @0xe3da4 cmp lr, r5 */
/* @0xe3da8 mov r12, r4 */
/* @0xe3dac add r4, r4, #16 */
/* @0xe3db0 ldr r0, [r3] */
/* @0xe3db4 ldr r1, [r3, #0x4] */
/* @0xe3db8 ldr r2, [r3, #0x8] */
/* @0xe3dbc ldr r3, [r3, #0xc] */
/* @0xe3dc0 stm r12!, {r0, r1, r2, r3} */
/* @0xe3dc4 bne 0xe3d9c <_Z24YYGML_CallLegacyFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x6c> */
/* @0xe3dc8 ldr r3, [r6, #0xc] */
/* @0xe3dcc sub r3, r3, #1 */
/* @0xe3dd0 bic r3, r3, #-16777216 */
/* @0xe3dd4 bic r3, r3, #3 */
/* @0xe3dd8 cmp r3, #0 */
/* @0xe3ddc bne 0xe3de8 <_Z24YYGML_CallLegacyFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0xb8> */
/* @0xe3de0 mov r0, r6 */
/* @0xe3de4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe3de8 ldr r4, [pc, #0x64] */
/* @0xe3dec mov r3, r5 */
/* @0xe3df0 mov r0, #0 */
/* @0xe3df4 ldr r2, [r11, #-0x34] */
/* @0xe3df8 ldr r4, [pc, r4] */
/* @0xe3dfc str r0, [r6] */
/* @0xe3e00 str r0, [r6, #0x8] */
/* @0xe3e04 mov r12, #5 */
/* @0xe3e08 ldr r5, [r4] */
/* @0xe3e0c mov r0, r6 */
/* @0xe3e10 str r12, [r6, #0xc] */
/* @0xe3e14 str r8, [r4] */
/* @0xe3e18 ldr r1, [r11, #-0x30] */
/* @0xe3e1c str r9, [sp] */
/* @0xe3e20 ldr r12, [r8, #0x40] */
/* @0xe3e24 blx r12 */
/* @0xe3e28 ldr r2, [r11, #-0x28] */
/* @0xe3e2c ldr r3, [r7] */
/* @0xe3e30 mov r0, r6 */
/* @0xe3e34 str r5, [r4] */
/* @0xe3e38 cmp r2, r3 */
/* @0xe3e3c bne 0xe3e48 <_Z24YYGML_CallLegacyFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118> */
/* @0xe3e40 sub sp, r11, #32 */
/* @0xe3e44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe3e48 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xe3e4c eorseq r9, r0, r4, lsl #24 */
/* @0xe3e50 eorseq r9, r0, r0, asr #27 */
/* @0xe3e54 eorseq r9, r0, r8, lsr sp */

/* ── FUNC 0xe3e58 · DoCallLibrary(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=400 · insn=100 */
/* @0xe3e58 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe3e5c mov r6, r1 */
/* @0xe3e60 ldr r4, [pc, #0x164] */
/* @0xe3e64 sub sp, sp, #36 */
/* @0xe3e68 ldr lr, [pc, #0x160] */
/* @0xe3e6c mov r12, #0 */
/* @0xe3e70 ldr r1, [pc, #0x15c] */
/* @0xe3e74 add r4, pc, r4 */
/* @0xe3e78 mov r5, r3 */
/* @0xe3e7c uxth r8, r0 */
/* @0xe3e80 ldr r3, [r4, lr] */
/* @0xe3e84 str r12, [sp, #0x10] */
/* @0xe3e88 str r12, [sp, #0x14] */
/* @0xe3e8c str r12, [sp, #0x18] */
/* @0xe3e90 str r12, [sp, #0x1c] */
/* @0xe3e94 ldr r1, [r4, r1] */
/* @0xe3e98 ldr r2, [r2] */
/* @0xe3e9c str r1, [sp, #0xc] */
/* @0xe3ea0 ldr r0, [sp, #0xc] */
/* @0xe3ea4 add r11, r2, r2, lsl #2 */
/* @0xe3ea8 ldr r1, [r3] */
/* @0xe3eac ldrb r3, [r0] */
/* @0xe3eb0 add r11, r1, r11, lsl #4 */
/* @0xe3eb4 cmp r3, r12 */
/* @0xe3eb8 bne 0xe3fa8 <_Z13DoCallLibraryjPhPKhP6VMExec+0x150> */
/* @0xe3ebc ldr r3, [pc, #0x114] */
/* @0xe3ec0 mov r0, #0 */
/* @0xe3ec4 add r7, sp, #16 */
/* @0xe3ec8 ldr r9, [r4, r3] */
/* @0xe3ecc ldr r10, [r9] */
/* @0xe3ed0 str r11, [r9] */
/* @0xe3ed4 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0xe3ed8 ldr r1, [r5, #0x14] */
/* @0xe3edc mov r3, r8 */
/* @0xe3ee0 ldr r2, [r5, #0x18] */
/* @0xe3ee4 mov r0, r7 */
/* @0xe3ee8 str r6, [sp] */
/* @0xe3eec ldr r11, [r11, #0x40] */
/* @0xe3ef0 blx r11 */
/* @0xe3ef4 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0xe3ef8 ldr r1, [sp, #0xc] */
/* @0xe3efc ldr r3, [pc, #0xd8] */
/* @0xe3f00 str r10, [r9] */
/* @0xe3f04 ldrb r2, [r1] */
/* @0xe3f08 ldr r3, [r4, r3] */
/* @0xe3f0c cmp r2, #0 */
/* @0xe3f10 str r5, [r3] */
/* @0xe3f14 bne 0xe3fbc <_Z13DoCallLibraryjPhPKhP6VMExec+0x164> */
/* @0xe3f18 ldr r3, [pc, #0xc0] */
/* @0xe3f1c ldr r3, [r4, r3] */
/* @0xe3f20 ldrb r5, [r3] */
/* @0xe3f24 cmp r5, #0 */
/* @0xe3f28 movne r4, r6 */
/* @0xe3f2c bne 0xe3f9c <_Z13DoCallLibraryjPhPKhP6VMExec+0x144> */
/* @0xe3f30 cmp r8, #0 */
/* @0xe3f34 beq 0xe3f80 <_Z13DoCallLibraryjPhPKhP6VMExec+0x128> */
/* @0xe3f38 mov r4, r6 */
/* @0xe3f3c b 0xe3f4c <_Z13DoCallLibraryjPhPKhP6VMExec+0xf4> */
/* @0xe3f40 cmp r5, r8 */
/* @0xe3f44 add r4, r4, #16 */
/* @0xe3f48 beq 0xe3f7c <_Z13DoCallLibraryjPhPKhP6VMExec+0x124> */
/* @0xe3f4c ldr r2, [r4, #0xc] */
/* @0xe3f50 add r5, r5, #1 */
/* @0xe3f54 sub r2, r2, #1 */
/* @0xe3f58 bic r2, r2, #-16777216 */
/* @0xe3f5c bic r2, r2, #3 */
/* @0xe3f60 cmp r2, #0 */
/* @0xe3f64 bne 0xe3f40 <_Z13DoCallLibraryjPhPKhP6VMExec+0xe8> */
/* @0xe3f68 mov r0, r4 */
/* @0xe3f6c add r4, r4, #16 */
/* @0xe3f70 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe3f74 cmp r5, r8 */
/* @0xe3f78 bne 0xe3f4c <_Z13DoCallLibraryjPhPKhP6VMExec+0xf4> */
/* @0xe3f7c add r6, r6, r5, lsl #4 */
/* @0xe3f80 ldm r7!, {r0, r1, r2, r3} */
/* @0xe3f84 sub r12, r6, #16 */
/* @0xe3f88 mov r4, r12 */
/* @0xe3f8c str r0, [r6, #-0x10] */
/* @0xe3f90 str r1, [r6, #-0xc] */
/* @0xe3f94 str r2, [r6, #-0x8] */
/* @0xe3f98 str r3, [r6, #-0x4] */
/* @0xe3f9c mov r0, r4 */
/* @0xe3fa0 add sp, sp, #36 */
/* @0xe3fa4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe3fa8 ldr r3, [pc, #0x34] */
/* @0xe3fac mov r1, r12 */
/* @0xe3fb0 ldr r0, [r4, r3] */
/* @0xe3fb4 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0xe3fb8 b 0xe3ebc <_Z13DoCallLibraryjPhPKhP6VMExec+0x64> */
/* @0xe3fbc ldr r3, [pc, #0x20] */
/* @0xe3fc0 ldr r0, [r4, r3] */
/* @0xe3fc4 bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0xe3fc8 b 0xe3f18 <_Z13DoCallLibraryjPhPKhP6VMExec+0xc0> */
/* @0xe3fcc ldrsbteq sp, [r0], -r12 */
/* @0xe3fd0 .word 0xffffbec8 */
/* @0xe3fd4 .word 0xffffbf18 */
/* @0xe3fd8 .word 0xffffbee0 */
/* @0xe3fdc .word 0xffffbf58 */
/* @0xe3fe0 .word 0xffffc0cc */
/* @0xe3fe4 .word 0xffffbf1c */

/* ── FUNC 0xe3fe8 · DoRet(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=752 · insn=188 */
/* @0xe3fe8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe3fec mov r5, r3 */
/* @0xe3ff0 ldr r4, [pc, #0x2c8] */
/* @0xe3ff4 mov r8, r1 */
/* @0xe3ff8 ldr r3, [pc, #0x2c4] */
/* @0xe3ffc sub sp, sp, #12 */
/* @0xe4000 add r4, pc, r4 */
/* @0xe4004 ldr r2, [r5, #0x4c] */
/* @0xe4008 ldr r3, [r4, r3] */
/* @0xe400c cmp r2, #0 */
/* @0xe4010 ldr r1, [r3] */
/* @0xe4014 add r1, r1, #1 */
/* @0xe4018 str r1, [r3] */
/* @0xe401c bne 0xe4058 <_Z5DoRetjPhPKhP6VMExec+0x70> */
/* @0xe4020 ldr r2, [r5, #0x5c] */
/* @0xe4024 ldr r3, [r5, #0x50] */
/* @0xe4028 cmp r2, #0 */
/* @0xe402c str r3, [r5, #0x44] */
/* @0xe4030 beq 0xe4048 <_Z5DoRetjPhPKhP6VMExec+0x60> */
/* @0xe4034 add r1, r3, #3 */
/* @0xe4038 cmp r3, #0 */
/* @0xe403c movlt r3, r1 */
/* @0xe4040 asr r3, r3, #2 */
/* @0xe4044 ldr r2, [r2, r3, lsl #2] */
/* @0xe4048 str r2, [r5, #0x48] */
/* @0xe404c mov r0, r8 */
/* @0xe4050 add sp, sp, #12 */
/* @0xe4054 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe4058 ubfx r0, r0, #0x10, #0x8 */
/* @0xe405c cmp r0, #15 */
/* @0xe4060 addls pc, pc, r0, lsl #2 */
/* @0xe4064 b 0xe4248 <_Z5DoRetjPhPKhP6VMExec+0x260> */
/* @0xe4068 b 0xe4218 <_Z5DoRetjPhPKhP6VMExec+0x230> */
/* @0xe406c b 0xe40a8 <_Z5DoRetjPhPKhP6VMExec+0xc0> */
/* @0xe4070 b 0xe40a8 <_Z5DoRetjPhPKhP6VMExec+0xc0> */
/* @0xe4074 b 0xe4218 <_Z5DoRetjPhPKhP6VMExec+0x230> */
/* @0xe4078 b 0xe40a8 <_Z5DoRetjPhPKhP6VMExec+0xc0> */
/* @0xe407c b 0xe4220 <_Z5DoRetjPhPKhP6VMExec+0x238> */
/* @0xe4080 b 0xe40a8 <_Z5DoRetjPhPKhP6VMExec+0xc0> */
/* @0xe4084 b 0xe4248 <_Z5DoRetjPhPKhP6VMExec+0x260> */
/* @0xe4088 b 0xe4248 <_Z5DoRetjPhPKhP6VMExec+0x260> */
/* @0xe408c b 0xe4248 <_Z5DoRetjPhPKhP6VMExec+0x260> */
/* @0xe4090 b 0xe4248 <_Z5DoRetjPhPKhP6VMExec+0x260> */
/* @0xe4094 b 0xe4248 <_Z5DoRetjPhPKhP6VMExec+0x260> */
/* @0xe4098 b 0xe4248 <_Z5DoRetjPhPKhP6VMExec+0x260> */
/* @0xe409c b 0xe4248 <_Z5DoRetjPhPKhP6VMExec+0x260> */
/* @0xe40a0 b 0xe4248 <_Z5DoRetjPhPKhP6VMExec+0x260> */
/* @0xe40a4 b 0xe4228 <_Z5DoRetjPhPKhP6VMExec+0x240> */
/* @0xe40a8 mov r11, #4 */
/* @0xe40ac ldr r3, [pc, #0x214] */
/* @0xe40b0 sub r2, r2, #1 */
/* @0xe40b4 str r2, [r5, #0x4c] */
/* @0xe40b8 ldr r3, [r4, r3] */
/* @0xe40bc ldrb r3, [r3] */
/* @0xe40c0 cmp r3, #0 */
/* @0xe40c4 bne 0xe42a0 <_Z5DoRetjPhPKhP6VMExec+0x2b8> */
/* @0xe40c8 ldr r10, [r5, #0x28] */
/* @0xe40cc ldr r6, [r10, #0x18] */
/* @0xe40d0 cmp r6, #0 */
/* @0xe40d4 addeq r8, r10, #60 */
/* @0xe40d8 beq 0xe404c <_Z5DoRetjPhPKhP6VMExec+0x64> */
/* @0xe40dc ldr r3, [r10, #0xc] */
/* @0xe40e0 ldr r0, [r10, #0x24] */
/* @0xe40e4 ldr r1, [r10, #0x4] */
/* @0xe40e8 cmp r3, #0 */
/* @0xe40ec ldr r2, [r10, #0x10] */
/* @0xe40f0 ldr r9, [r10, #0x14] */
/* @0xe40f4 movlt r3, #0 */
/* @0xe40f8 ldr r7, [r10] */
/* @0xe40fc ldr lr, [r10, #0x1c] */
/* @0xe4100 ldr r12, [r10, #0x20] */
/* @0xe4104 str r0, [r5, #0x34] */
/* @0xe4108 ldrge r0, [r5, #0x40] */
/* @0xe410c str r1, [r5, #0x30] */
/* @0xe4110 ldrge r1, [r5, #0x8] */
/* @0xe4114 rsbge r3, r3, r0 */
/* @0xe4118 str r2, [r5, #0x14] */
/* @0xe411c addge r3, r1, r3 */
/* @0xe4120 ldr r1, [r5, #0xc] */
/* @0xe4124 str r9, [r5, #0x18] */
/* @0xe4128 cmp r1, #0 */
/* @0xe412c str r7, [r5, #0x44] */
/* @0xe4130 str r6, [r5, #0x2c] */
/* @0xe4134 str lr, [r5, #0x38] */
/* @0xe4138 str r12, [r5, #0x3c] */
/* @0xe413c str r3, [r5, #0x28] */
/* @0xe4140 beq 0xe42b0 <_Z5DoRetjPhPKhP6VMExec+0x2c8> */
/* @0xe4144 ldr r1, [r6, #0x10] */
/* @0xe4148 mov r0, r6 */
/* @0xe414c ldr r3, [r6, #0x4] */
/* @0xe4150 ldr lr, [r10, #0x30] */
/* @0xe4154 ldr r12, [r10, #0x2c] */
/* @0xe4158 str r1, [r5, #0x24] */
/* @0xe415c str lr, [r5, #0x10] */
/* @0xe4160 str r12, [r5, #0xc] */
/* @0xe4164 str r3, [r5, #0x50] */
/* @0xe4168 bl 0xec750 <_ZN8VMBuffer13convertBufferEv> */
/* @0xe416c ldr r3, [r5, #0x44] */
/* @0xe4170 ldr r1, [r5, #0x2c] */
/* @0xe4174 cmp r3, #0 */
/* @0xe4178 add r0, r3, #3 */
/* @0xe417c ldr r12, [r6, #0x14] */
/* @0xe4180 ldr r1, [r1, #0x18] */
/* @0xe4184 movlt r3, r0 */
/* @0xe4188 asr r3, r3, #2 */
/* @0xe418c ldr r0, [r10, #0x28] */
/* @0xe4190 str r12, [r5, #0x58] */
/* @0xe4194 ldr r3, [r1, r3, lsl #2] */
/* @0xe4198 str r1, [r5, #0x5c] */
/* @0xe419c str r3, [r5, #0x48] */
/* @0xe41a0 bl 0x27d1d0 <_ZdlPv> */
/* @0xe41a4 ldr r1, [pc, #0x120] */
/* @0xe41a8 ldr r3, [pc, #0x120] */
/* @0xe41ac ldr r1, [r4, r1] */
/* @0xe41b0 str r1, [sp] */
/* @0xe41b4 ldr r3, [r4, r3] */
/* @0xe41b8 str r3, [sp, #0x4] */
/* @0xe41bc ldr r3, [r1] */
/* @0xe41c0 ldr r2, [sp, #0x4] */
/* @0xe41c4 subs r6, r3, #1 */
/* @0xe41c8 ldr r4, [r2] */
/* @0xe41cc bmi 0xe4258 <_Z5DoRetjPhPKhP6VMExec+0x270> */
/* @0xe41d0 mov r7, #0 */
/* @0xe41d4 mov r9, #5 */
/* @0xe41d8 b 0xe41f0 <_Z5DoRetjPhPKhP6VMExec+0x208> */
/* @0xe41dc cmn r6, #1 */
/* @0xe41e0 str r7, [r4, #0x8] */
/* @0xe41e4 str r9, [r4, #0xc] */
/* @0xe41e8 str r7, [r4], #16 */
/* @0xe41ec beq 0xe4250 <_Z5DoRetjPhPKhP6VMExec+0x268> */
/* @0xe41f0 ldr r3, [r4, #0xc] */
/* @0xe41f4 sub r6, r6, #1 */
/* @0xe41f8 sub r3, r3, #1 */
/* @0xe41fc bic r3, r3, #-16777216 */
/* @0xe4200 bic r3, r3, #3 */
/* @0xe4204 cmp r3, #0 */
/* @0xe4208 bne 0xe41dc <_Z5DoRetjPhPKhP6VMExec+0x1f4> */
/* @0xe420c mov r0, r4 */
/* @0xe4210 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe4214 b 0xe41dc <_Z5DoRetjPhPKhP6VMExec+0x1f4> */
/* @0xe4218 mov r11, #8 */
/* @0xe421c b 0xe40ac <_Z5DoRetjPhPKhP6VMExec+0xc4> */
/* @0xe4220 mov r11, #16 */
/* @0xe4224 b 0xe40ac <_Z5DoRetjPhPKhP6VMExec+0xc4> */
/* @0xe4228 mov r3, #0 */
/* @0xe422c mov r1, #5 */
/* @0xe4230 str r3, [r8, #-0x10] */
/* @0xe4234 mov r11, #16 */
/* @0xe4238 str r3, [r8, #-0xc] */
/* @0xe423c sub r8, r8, #16 */
/* @0xe4240 str r1, [r8, #0xc] */
/* @0xe4244 b 0xe40ac <_Z5DoRetjPhPKhP6VMExec+0xc4> */
/* @0xe4248 mov r11, #0 */
/* @0xe424c b 0xe40ac <_Z5DoRetjPhPKhP6VMExec+0xc4> */
/* @0xe4250 ldr r4, [sp] */
/* @0xe4254 ldr r3, [r4] */
/* @0xe4258 ldr r4, [r5, #0x8] */
/* @0xe425c add r3, r10, r3, lsl #4 */
/* @0xe4260 ldr r12, [r10, #0x38] */
/* @0xe4264 add r3, r3, #44 */
/* @0xe4268 ldr lr, [r10, #0x8] */
/* @0xe426c mov r1, r8 */
/* @0xe4270 add r12, r4, r12 */
/* @0xe4274 ldr r4, [sp] */
/* @0xe4278 mov r2, r11 */
/* @0xe427c mov r0, r3 */
/* @0xe4280 mov r8, r3 */
/* @0xe4284 str lr, [r4] */
/* @0xe4288 ldr r4, [sp, #0x4] */
/* @0xe428c str r12, [r4] */
/* @0xe4290 bl 0xb65bc <memcpy@plt> */
/* @0xe4294 mov r0, r8 */
/* @0xe4298 add sp, sp, #12 */
/* @0xe429c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe42a0 ldr r3, [pc, #0x2c] */
/* @0xe42a4 ldr r0, [r4, r3] */
/* @0xe42a8 bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0xe42ac b 0xe40c8 <_Z5DoRetjPhPKhP6VMExec+0xe0> */
/* @0xe42b0 ldr r0, [r5, #0x10] */
/* @0xe42b4 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_> */
/* @0xe42b8 ldr r6, [r5, #0x2c] */
/* @0xe42bc b 0xe4144 <_Z5DoRetjPhPKhP6VMExec+0x15c> */
/* @0xe42c0 eorseq sp, r0, r0, asr r12 */
/* @0xe42c4 .word 0xffffc0d0 */
/* @0xe42c8 .word 0xffffbf18 */
/* @0xe42cc .word 0xffffc0bc */
/* @0xe42d0 .word 0xffffc0c0 */
/* @0xe42d4 .word 0xffffbf1c */

/* ── FUNC 0xe42d8 · PerformReturn(unsigned char*, VMExec*) · size=508 · insn=127 */
/* @0xe42d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe42dc mov r6, r1 */
/* @0xe42e0 ldr r5, [pc, #0x1d4] */
/* @0xe42e4 sub sp, sp, #12 */
/* @0xe42e8 ldr r3, [pc, #0x1d0] */
/* @0xe42ec add r5, pc, r5 */
/* @0xe42f0 ldr r2, [pc, #0x1cc] */
/* @0xe42f4 ldr r3, [r5, r3] */
/* @0xe42f8 ldr r1, [r3] */
/* @0xe42fc add r1, r1, #1 */
/* @0xe4300 str r1, [r3] */
/* @0xe4304 ldr r3, [r5, r2] */
/* @0xe4308 ldrb r3, [r3] */
/* @0xe430c cmp r3, #0 */
/* @0xe4310 bne 0xe449c <_Z13PerformReturnPhP6VMExec+0x1c4> */
/* @0xe4314 ldr r11, [r6, #0x28] */
/* @0xe4318 ldr r3, [r6, #0x4c] */
/* @0xe431c add r8, r11, #60 */
/* @0xe4320 ldr r4, [r11, #0x18] */
/* @0xe4324 sub r3, r3, #1 */
/* @0xe4328 str r3, [r6, #0x4c] */
/* @0xe432c cmp r4, #0 */
/* @0xe4330 beq 0xe4490 <_Z13PerformReturnPhP6VMExec+0x1b8> */
/* @0xe4334 ldr r3, [r11, #0xc] */
/* @0xe4338 ldr r1, [r11, #0x24] */
/* @0xe433c ldr r2, [r11, #0x4] */
/* @0xe4340 cmp r3, #0 */
/* @0xe4344 ldr r0, [r11, #0x20] */
/* @0xe4348 ldr r9, [r11, #0x10] */
/* @0xe434c movlt r3, #0 */
/* @0xe4350 ldr r7, [r11, #0x14] */
/* @0xe4354 ldr lr, [r11] */
/* @0xe4358 ldr r12, [r11, #0x1c] */
/* @0xe435c str r1, [r6, #0x34] */
/* @0xe4360 ldrge r1, [r6, #0x40] */
/* @0xe4364 str r2, [r6, #0x30] */
/* @0xe4368 ldrge r2, [r6, #0x8] */
/* @0xe436c rsbge r3, r3, r1 */
/* @0xe4370 str r0, [r6, #0x3c] */
/* @0xe4374 ldr r0, [r6, #0xc] */
/* @0xe4378 addge r3, r2, r3 */
/* @0xe437c ldr r1, [r4, #0x10] */
/* @0xe4380 ldr r2, [r4, #0x4] */
/* @0xe4384 cmp r0, #0 */
/* @0xe4388 str r9, [r6, #0x14] */
/* @0xe438c str r7, [r6, #0x18] */
/* @0xe4390 str lr, [r6, #0x44] */
/* @0xe4394 str r4, [r6, #0x2c] */
/* @0xe4398 str r12, [r6, #0x38] */
/* @0xe439c str r3, [r6, #0x28] */
/* @0xe43a0 str r1, [r6, #0x24] */
/* @0xe43a4 str r2, [r6, #0x50] */
/* @0xe43a8 beq 0xe44ac <_Z13PerformReturnPhP6VMExec+0x1d4> */
/* @0xe43ac ldr r2, [r11, #0x30] */
/* @0xe43b0 mov r0, r4 */
/* @0xe43b4 ldr r3, [r11, #0x2c] */
/* @0xe43b8 str r2, [r6, #0x10] */
/* @0xe43bc str r3, [r6, #0xc] */
/* @0xe43c0 bl 0xec750 <_ZN8VMBuffer13convertBufferEv> */
/* @0xe43c4 ldr r3, [r6, #0x44] */
/* @0xe43c8 ldr r2, [r6, #0x2c] */
/* @0xe43cc cmp r3, #0 */
/* @0xe43d0 add r0, r3, #3 */
/* @0xe43d4 ldr r1, [r4, #0x14] */
/* @0xe43d8 ldr r2, [r2, #0x18] */
/* @0xe43dc movlt r3, r0 */
/* @0xe43e0 asr r3, r3, #2 */
/* @0xe43e4 ldr r0, [r11, #0x28] */
/* @0xe43e8 str r1, [r6, #0x58] */
/* @0xe43ec ldr r3, [r2, r3, lsl #2] */
/* @0xe43f0 str r2, [r6, #0x5c] */
/* @0xe43f4 str r3, [r6, #0x48] */
/* @0xe43f8 bl 0x27d1d0 <_ZdlPv> */
/* @0xe43fc ldr r2, [pc, #0xc4] */
/* @0xe4400 ldr r3, [pc, #0xc4] */
/* @0xe4404 ldr r9, [r5, r2] */
/* @0xe4408 ldr r3, [r5, r3] */
/* @0xe440c str r3, [sp, #0x4] */
/* @0xe4410 ldr r3, [r9] */
/* @0xe4414 ldr r2, [sp, #0x4] */
/* @0xe4418 subs r5, r3, #1 */
/* @0xe441c ldr r4, [r2] */
/* @0xe4420 bmi 0xe4470 <_Z13PerformReturnPhP6VMExec+0x198> */
/* @0xe4424 mov r7, #0 */
/* @0xe4428 mov r10, #5 */
/* @0xe442c b 0xe4444 <_Z13PerformReturnPhP6VMExec+0x16c> */
/* @0xe4430 cmn r5, #1 */
/* @0xe4434 str r7, [r4, #0x8] */
/* @0xe4438 str r10, [r4, #0xc] */
/* @0xe443c str r7, [r4], #16 */
/* @0xe4440 beq 0xe446c <_Z13PerformReturnPhP6VMExec+0x194> */
/* @0xe4444 ldr r3, [r4, #0xc] */
/* @0xe4448 sub r5, r5, #1 */
/* @0xe444c sub r3, r3, #1 */
/* @0xe4450 bic r3, r3, #-16777216 */
/* @0xe4454 bic r3, r3, #3 */
/* @0xe4458 cmp r3, #0 */
/* @0xe445c bne 0xe4430 <_Z13PerformReturnPhP6VMExec+0x158> */
/* @0xe4460 mov r0, r4 */
/* @0xe4464 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe4468 b 0xe4430 <_Z13PerformReturnPhP6VMExec+0x158> */
/* @0xe446c ldr r3, [r9] */
/* @0xe4470 ldr r2, [r6, #0x8] */
/* @0xe4474 add r8, r8, r3, lsl #4 */
/* @0xe4478 ldr r3, [r11, #0x38] */
/* @0xe447c ldr r1, [r11, #0x8] */
/* @0xe4480 add r3, r2, r3 */
/* @0xe4484 ldr r2, [sp, #0x4] */
/* @0xe4488 str r1, [r9] */
/* @0xe448c str r3, [r2] */
/* @0xe4490 mov r0, r8 */
/* @0xe4494 add sp, sp, #12 */
/* @0xe4498 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe449c ldr r3, [pc, #0x2c] */
/* @0xe44a0 ldr r0, [r5, r3] */
/* @0xe44a4 bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0xe44a8 b 0xe4314 <_Z13PerformReturnPhP6VMExec+0x3c> */
/* @0xe44ac ldr r0, [r6, #0x10] */
/* @0xe44b0 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_> */
/* @0xe44b4 ldr r4, [r6, #0x2c] */
/* @0xe44b8 b 0xe43ac <_Z13PerformReturnPhP6VMExec+0xd4> */
/* @0xe44bc eorseq sp, r0, r4, ror #18 */
/* @0xe44c0 .word 0xffffc0d0 */
/* @0xe44c4 .word 0xffffbf18 */
/* @0xe44c8 .word 0xffffc0bc */
/* @0xe44cc .word 0xffffc0c0 */
/* @0xe44d0 .word 0xffffbf1c */

/* ── FUNC 0xe44d4 · DoExit(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=108 · insn=27 */
/* @0xe44d4 ldr r2, [r3, #0x4c] */
/* @0xe44d8 push {r3, lr} */
/* @0xe44dc cmp r2, #0 */
/* @0xe44e0 bgt 0xe4518 <_Z6DoExitjPhPKhP6VMExec+0x44> */
/* @0xe44e4 ldr r0, [r3, #0x5c] */
/* @0xe44e8 ldr r2, [r3, #0x50] */
/* @0xe44ec cmp r0, #0 */
/* @0xe44f0 str r2, [r3, #0x44] */
/* @0xe44f4 beq 0xe450c <_Z6DoExitjPhPKhP6VMExec+0x38> */
/* @0xe44f8 add r12, r2, #3 */
/* @0xe44fc cmp r2, #0 */
/* @0xe4500 movlt r2, r12 */
/* @0xe4504 asr r2, r2, #2 */
/* @0xe4508 ldr r0, [r0, r2, lsl #2] */
/* @0xe450c str r0, [r3, #0x48] */
/* @0xe4510 mov r0, r1 */
/* @0xe4514 pop {r3, pc} */
/* @0xe4518 mov r1, r3 */
/* @0xe451c ldr r0, [r3, #0x28] */
/* @0xe4520 bl 0xe42d8 <_Z13PerformReturnPhP6VMExec> */
/* @0xe4524 mov r3, #0 */
/* @0xe4528 sub r1, r0, #16 */
/* @0xe452c str r3, [r0, #-0x4] */
/* @0xe4530 str r3, [r0, #-0x10] */
/* @0xe4534 str r3, [r0, #-0xc] */
/* @0xe4538 mov r0, r1 */
/* @0xe453c pop {r3, pc} */

/* ── FUNC 0xe4540 · VM::ExecRelease(VMExec&, RValue*) · size=648 · insn=162 */
/* @0xe4540 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe4544 mov r9, r1 */
/* @0xe4548 ldr r5, [pc, #0x250] */
/* @0xe454c mov r4, r0 */
/* @0xe4550 ldr r3, [pc, #0x24c] */
/* @0xe4554 sub sp, sp, #12 */
/* @0xe4558 add r5, pc, r5 */
/* @0xe455c ldr r1, [pc, #0x244] */
/* @0xe4560 ldr r12, [r0, #0x28] */
/* @0xe4564 mov r7, #0 */
/* @0xe4568 ldr r3, [r5, r3] */
/* @0xe456c ldr r2, [pc, #0x238] */
/* @0xe4570 ldr r0, [r3] */
/* @0xe4574 add r0, r0, #1 */
/* @0xe4578 str r0, [r3] */
/* @0xe457c ldr r3, [r5, r1] */
/* @0xe4580 str r3, [sp] */
/* @0xe4584 ldr r8, [r5, r2] */
/* @0xe4588 ldr r2, [sp] */
/* @0xe458c str r4, [r8] */
/* @0xe4590 ldr r2, [r2] */
/* @0xe4594 str r2, [sp, #0x4] */
/* @0xe4598 ldr r2, [r4, #0x44] */
/* @0xe459c ldr r1, [r4, #0x5c] */
/* @0xe45a0 cmp r2, #0 */
/* @0xe45a4 add r6, r2, #3 */
/* @0xe45a8 ldr r3, [r4, #0x50] */
/* @0xe45ac movge r6, r2 */
/* @0xe45b0 ldr r0, [r4, #0x58] */
/* @0xe45b4 asr r6, r6, #2 */
/* @0xe45b8 cmp r2, r3 */
/* @0xe45bc mov r3, r2 */
/* @0xe45c0 ldr r1, [r1, r6, lsl #2] */
/* @0xe45c4 add r6, r1, #1 */
/* @0xe45c8 str r6, [r4, #0x48] */
/* @0xe45cc ldr r6, [r0, r1, lsl #2] */
/* @0xe45d0 bge 0xe46a0 <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x160> */
/* @0xe45d4 ldr r1, [pc, #0x1d4] */
/* @0xe45d8 ldr r10, [r5, r1] */
/* @0xe45dc ldr r11, [r4, #0x24] */
/* @0xe45e0 mov r1, #4 */
/* @0xe45e4 str r3, [r4, #0x54] */
/* @0xe45e8 ldr lr, [pc, #0x1c4] */
/* @0xe45ec ldr r0, [r11, r2] */
/* @0xe45f0 add r2, r11, r2 */
/* @0xe45f4 add r2, r2, r1 */
/* @0xe45f8 tst r0, #1073741824 */
/* @0xe45fc ubfx r11, r0, #0x10, #0x4 */
/* @0xe4600 ldrne r1, [r5, lr] */
/* @0xe4604 ldrne r1, [r1, r11, lsl #2] */
/* @0xe4608 ldr r11, [pc, #0x1a8] */
/* @0xe460c addne r1, r1, #4 */
/* @0xe4610 add r3, r1, r3 */
/* @0xe4614 mov r1, r12 */
/* @0xe4618 str r3, [r4, #0x44] */
/* @0xe461c mov r3, r4 */
/* @0xe4620 blx r6 */
/* @0xe4624 ldrb r2, [r10] */
/* @0xe4628 ldr r3, [r4, #0x48] */
/* @0xe462c cmp r2, #0 */
/* @0xe4630 ldr r2, [r4, #0x58] */
/* @0xe4634 add r6, r3, #1 */
/* @0xe4638 ldr r1, [pc, #0x17c] */
/* @0xe463c str r6, [r4, #0x48] */
/* @0xe4640 ldr r6, [r2, r3, lsl #2] */
/* @0xe4644 mov r12, r0 */
/* @0xe4648 ldr r0, [pc, #0x170] */
/* @0xe464c beq 0xe468c <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x14c> */
/* @0xe4650 ldr r3, [r5, r1] */
/* @0xe4654 ldr r2, [r8] */
/* @0xe4658 ldr r3, [r3] */
/* @0xe465c cmp r2, r3 */
/* @0xe4660 bne 0xe46a0 <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x160> */
/* @0xe4664 ldr r12, [r5, r11] */
/* @0xe4668 ldr r11, [r5, r0] */
/* @0xe466c ldm r12!, {r0, r1, r2, r3} */
/* @0xe4670 ldr r11, [r11] */
/* @0xe4674 sub r12, r11, #16 */
/* @0xe4678 str r0, [r11, #-0x10] */
/* @0xe467c str r1, [r12, #0x4] */
/* @0xe4680 str r2, [r12, #0x8] */
/* @0xe4684 str r3, [r12, #0xc] */
/* @0xe4688 strb r7, [r10] */
/* @0xe468c ldr r3, [r4, #0x44] */
/* @0xe4690 ldr r2, [r4, #0x50] */
/* @0xe4694 cmp r3, r2 */
/* @0xe4698 mov r2, r3 */
/* @0xe469c blt 0xe45dc <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x9c> */
/* @0xe46a0 ldr r3, [r4, #0x4c] */
/* @0xe46a4 cmp r3, #0 */
/* @0xe46a8 bgt 0xe4734 <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x1f4> */
/* @0xe46ac ldm sp, {r2, r3} */
/* @0xe46b0 cmp r9, #0 */
/* @0xe46b4 str r3, [r2] */
/* @0xe46b8 beq 0xe46c8 <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x188> */
/* @0xe46bc ldr r3, [r4, #0x28] */
/* @0xe46c0 cmp r3, r12 */
/* @0xe46c4 bhi 0xe477c <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x23c> */
/* @0xe46c8 ldr r3, [pc, #0xf4] */
/* @0xe46cc ldr r0, [r4, #0x8] */
/* @0xe46d0 ldr r12, [r5, r3] */
/* @0xe46d4 ldr r3, [r12, #0x4] */
/* @0xe46d8 cmp r3, #0 */
/* @0xe46dc beq 0xe4708 <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x1c8> */
/* @0xe46e0 add r1, r3, #8 */
/* @0xe46e4 add r2, r3, #1048576 */
/* @0xe46e8 cmp r0, r1 */
/* @0xe46ec add r2, r2, #8 */
/* @0xe46f0 blo 0xe46fc <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x1bc> */
/* @0xe46f4 cmp r2, r0 */
/* @0xe46f8 bhi 0xe4754 <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x214> */
/* @0xe46fc ldr r3, [r3] */
/* @0xe4700 cmp r3, #0 */
/* @0xe4704 bne 0xe46e0 <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x1a0> */
/* @0xe4708 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xe470c ldr r5, [r4, #0xc] */
/* @0xe4710 cmp r5, #0 */
/* @0xe4714 bne 0xe472c <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x1ec> */
/* @0xe4718 ldr r0, [r4, #0x10] */
/* @0xe471c cmp r0, #0 */
/* @0xe4720 beq 0xe472c <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x1ec> */
/* @0xe4724 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_> */
/* @0xe4728 str r5, [r4, #0x10] */
/* @0xe472c add sp, sp, #12 */
/* @0xe4730 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe4734 mov r0, r12 */
/* @0xe4738 mov r1, r4 */
/* @0xe473c bl 0xe42d8 <_Z13PerformReturnPhP6VMExec> */
/* @0xe4740 str r7, [r0, #-0x4] */
/* @0xe4744 sub r12, r0, #16 */
/* @0xe4748 str r7, [r0, #-0x10] */
/* @0xe474c str r7, [r0, #-0xc] */
/* @0xe4750 b 0xe4598 <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x58> */
/* @0xe4754 ldr r1, [r12, #0x8] */
/* @0xe4758 ldr r2, [r12, #0x10] */
/* @0xe475c ldr r3, [r12, #0xc] */
/* @0xe4760 add r2, r2, #1 */
/* @0xe4764 str r1, [r0] */
/* @0xe4768 sub r3, r3, #1 */
/* @0xe476c str r0, [r12, #0x8] */
/* @0xe4770 str r2, [r12, #0x10] */
/* @0xe4774 str r3, [r12, #0xc] */
/* @0xe4778 b 0xe470c <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x1cc> */
/* @0xe477c ldr r0, [r12] */
/* @0xe4780 ldr r1, [r12, #0x4] */
/* @0xe4784 ldr r2, [r12, #0x8] */
/* @0xe4788 ldr r3, [r12, #0xc] */
/* @0xe478c str r0, [r9] */
/* @0xe4790 str r1, [r9, #0x4] */
/* @0xe4794 str r2, [r9, #0x8] */
/* @0xe4798 str r3, [r9, #0xc] */
/* @0xe479c b 0xe46c8 <_ZN2VM11ExecReleaseER6VMExecP6RValue+0x188> */
/* @0xe47a0 ldrshteq sp, [r0], -r8 */
/* @0xe47a4 .word 0xffffc0d4 */
/* @0xe47a8 .word 0xffffc0bc */
/* @0xe47ac .word 0xffffbf58 */
/* @0xe47b0 .word 0xffffc0cc */
/* @0xe47b4 .word 0xffffc09c */
/* @0xe47b8 .word 0xffffc0d8 */
/* @0xe47bc .word 0xffffc0dc */
/* @0xe47c0 .word 0xffffc0e0 */
/* @0xe47c4 .word 0xffffc0e4 */

/* ── FUNC 0xe47c8 · VM::ExecDebug(VMExec&, RValue*, bool) · size=992 · insn=248 */
/* @0xe47c8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe47cc sub sp, sp, #20 */
/* @0xe47d0 ldr r5, [pc, #0x38c] */
/* @0xe47d4 mov r10, r1 */
/* @0xe47d8 ldr r3, [pc, #0x388] */
/* @0xe47dc mov r4, r0 */
/* @0xe47e0 add r5, pc, r5 */
/* @0xe47e4 str r2, [sp, #0xc] */
/* @0xe47e8 ldr r1, [pc, #0x37c] */
/* @0xe47ec mov r9, #0 */
/* @0xe47f0 ldr r3, [r5, r3] */
/* @0xe47f4 ldr r8, [r0, #0x28] */
/* @0xe47f8 ldr r2, [r3] */
/* @0xe47fc add r2, r2, #1 */
/* @0xe4800 str r2, [r3] */
/* @0xe4804 ldr r1, [r5, r1] */
/* @0xe4808 ldr r2, [r1] */
/* @0xe480c str r1, [sp, #0x4] */
/* @0xe4810 str r2, [sp, #0x8] */
/* @0xe4814 ldr r1, [r4, #0x44] */
/* @0xe4818 ldr r3, [r4, #0x50] */
/* @0xe481c cmp r1, r3 */
/* @0xe4820 bge 0xe48e0 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x118> */
/* @0xe4824 ldr r3, [r4, #0x24] */
/* @0xe4828 add r2, r1, #4 */
/* @0xe482c ldr r0, [pc, #0x33c] */
/* @0xe4830 str r1, [r4, #0x54] */
/* @0xe4834 ldr r6, [r3, r1] */
/* @0xe4838 add r3, r3, r2 */
/* @0xe483c str r2, [r4, #0x44] */
/* @0xe4840 ldr r2, [r5, r0] */
/* @0xe4844 ldr r2, [r2] */
/* @0xe4848 cmp r2, #0 */
/* @0xe484c beq 0xe4a80 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x2b8> */
/* @0xe4850 ldr r2, [pc, #0x31c] */
/* @0xe4854 ldr r11, [r5, r2] */
/* @0xe4858 ldr r2, [r11] */
/* @0xe485c cmp r2, #0 */
/* @0xe4860 bge 0xe4988 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x1c0> */
/* @0xe4864 ldr r2, [pc, #0x30c] */
/* @0xe4868 ldr r7, [r5, r2] */
/* @0xe486c ldr r2, [pc, #0x308] */
/* @0xe4870 ldr r2, [r5, r2] */
/* @0xe4874 ldrb r1, [r2] */
/* @0xe4878 cmp r1, #0 */
/* @0xe487c bne 0xe4a24 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x25c> */
/* @0xe4880 tst r6, #1073741824 */
/* @0xe4884 str r4, [r7] */
/* @0xe4888 ubfxeq lr, r6, #0x18, #0x5 */
/* @0xe488c bne 0xe4a98 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x2d0> */
/* @0xe4890 ldr r12, [pc, #0x2e8] */
/* @0xe4894 mov r1, r8 */
/* @0xe4898 mov r2, r3 */
/* @0xe489c mov r0, r6 */
/* @0xe48a0 mov r3, r4 */
/* @0xe48a4 ldr r12, [r5, r12] */
/* @0xe48a8 ldr r12, [r12, lr, lsl #2] */
/* @0xe48ac blx r12 */
/* @0xe48b0 ldr r3, [pc, #0x2cc] */
/* @0xe48b4 str r4, [r7] */
/* @0xe48b8 ldr r12, [r5, r3] */
/* @0xe48bc ldrb r3, [r12] */
/* @0xe48c0 cmp r3, #0 */
/* @0xe48c4 mov r8, r0 */
/* @0xe48c8 beq 0xe4814 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x4c> */
/* @0xe48cc ldr r3, [pc, #0x2b4] */
/* @0xe48d0 ldr r3, [r5, r3] */
/* @0xe48d4 ldr r3, [r3] */
/* @0xe48d8 cmp r4, r3 */
/* @0xe48dc beq 0xe4b0c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x344> */
/* @0xe48e0 ldr r3, [r4, #0x4c] */
/* @0xe48e4 cmp r3, #0 */
/* @0xe48e8 bgt 0xe4a60 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x298> */
/* @0xe48ec ldr r2, [sp, #0x8] */
/* @0xe48f0 cmp r10, #0 */
/* @0xe48f4 ldr r3, [sp, #0x4] */
/* @0xe48f8 str r2, [r3] */
/* @0xe48fc beq 0xe490c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x144> */
/* @0xe4900 ldr r3, [r4, #0x28] */
/* @0xe4904 cmp r3, r8 */
/* @0xe4908 bhi 0xe4b40 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x378> */
/* @0xe490c ldr r3, [pc, #0x278] */
/* @0xe4910 ldr r0, [r4, #0x8] */
/* @0xe4914 ldr r12, [r5, r3] */
/* @0xe4918 ldr r3, [r12, #0x4] */
/* @0xe491c cmp r3, #0 */
/* @0xe4920 beq 0xe494c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x184> */
/* @0xe4924 add r1, r3, #8 */
/* @0xe4928 add r2, r3, #1048576 */
/* @0xe492c cmp r0, r1 */
/* @0xe4930 add r2, r2, #8 */
/* @0xe4934 blo 0xe4940 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x178> */
/* @0xe4938 cmp r2, r0 */
/* @0xe493c bhi 0xe4adc <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x314> */
/* @0xe4940 ldr r3, [r3] */
/* @0xe4944 cmp r3, #0 */
/* @0xe4948 bne 0xe4924 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x15c> */
/* @0xe494c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xe4950 ldr r3, [sp, #0xc] */
/* @0xe4954 cmp r3, #0 */
/* @0xe4958 beq 0xe4980 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x1b8> */
/* @0xe495c ldr r3, [r4, #0xc] */
/* @0xe4960 cmp r3, #0 */
/* @0xe4964 ble 0xe4980 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x1b8> */
/* @0xe4968 ldr r0, [r4, #0x10] */
/* @0xe496c cmp r0, #0 */
/* @0xe4970 beq 0xe4980 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x1b8> */
/* @0xe4974 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_> */
/* @0xe4978 mov r3, #0 */
/* @0xe497c str r3, [r4, #0x10] */
/* @0xe4980 add sp, sp, #20 */
/* @0xe4984 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe4988 ldr r0, [r4, #0x38] */
/* @0xe498c str r3, [sp] */
/* @0xe4990 bl 0xec144 <_ZN2VM9DebugInfoEP8VMBufferi> */
/* @0xe4994 mov r2, #0 */
/* @0xe4998 ldr r1, [r4, #0x3c] */
/* @0xe499c bl 0xec2b8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc> */
/* @0xe49a0 ldr r2, [pc, #0x1d0] */
/* @0xe49a4 ldr r3, [sp] */
/* @0xe49a8 ldr r7, [r5, r2] */
/* @0xe49ac ldr r12, [r7] */
/* @0xe49b0 cmp r12, #0 */
/* @0xe49b4 beq 0xe4b04 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x33c> */
/* @0xe49b8 mov r2, #0 */
/* @0xe49bc ldr r1, [r12, #0x4c] */
/* @0xe49c0 add r2, r2, #1 */
/* @0xe49c4 ldr r12, [r12, #0x4] */
/* @0xe49c8 add r2, r2, r1 */
/* @0xe49cc cmp r12, #0 */
/* @0xe49d0 bne 0xe49bc <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x1f4> */
/* @0xe49d4 ldr r1, [r4, #0x3c] */
/* @0xe49d8 cmp r1, #0 */
/* @0xe49dc beq 0xe486c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0xa4> */
/* @0xe49e0 ldr r12, [pc, #0x1a8] */
/* @0xe49e4 ldr r12, [r5, r12] */
/* @0xe49e8 ldr r12, [r12] */
/* @0xe49ec cmp r1, r12 */
/* @0xe49f0 beq 0xe4aa4 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x2dc> */
/* @0xe49f4 ldr r0, [r11] */
/* @0xe49f8 cmp r0, #0 */
/* @0xe49fc beq 0xe4a1c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x254> */
/* @0xe4a00 cmp r0, #2 */
/* @0xe4a04 beq 0xe4abc <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x2f4> */
/* @0xe4a08 ldr r1, [pc, #0x184] */
/* @0xe4a0c ldr r1, [r5, r1] */
/* @0xe4a10 ldr r1, [r1] */
/* @0xe4a14 cmp r1, r2 */
/* @0xe4a18 blt 0xe486c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0xa4> */
/* @0xe4a1c ldr r2, [pc, #0x158] */
/* @0xe4a20 ldr r2, [r5, r2] */
/* @0xe4a24 mov r6, #0 */
/* @0xe4a28 movt r6, #0xff0f */
/* @0xe4a2c mov lr, #31 */
/* @0xe4a30 mov r0, #15 */
/* @0xe4a34 strb r9, [r2] */
/* @0xe4a38 mvn r2, #0 */
/* @0xe4a3c str r4, [r7] */
/* @0xe4a40 str r2, [r11] */
/* @0xe4a44 ldr r2, [pc, #0x14c] */
/* @0xe4a48 ldr r1, [r4, #0x44] */
/* @0xe4a4c ldr r2, [r5, r2] */
/* @0xe4a50 ldr r2, [r2, r0, lsl #2] */
/* @0xe4a54 add r2, r1, r2 */
/* @0xe4a58 str r2, [r4, #0x44] */
/* @0xe4a5c b 0xe4890 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0xc8> */
/* @0xe4a60 mov r0, r8 */
/* @0xe4a64 mov r1, r4 */
/* @0xe4a68 bl 0xe42d8 <_Z13PerformReturnPhP6VMExec> */
/* @0xe4a6c str r9, [r0, #-0x4] */
/* @0xe4a70 sub r8, r0, #16 */
/* @0xe4a74 str r9, [r0, #-0x10] */
/* @0xe4a78 str r9, [r0, #-0xc] */
/* @0xe4a7c b 0xe4814 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x4c> */
/* @0xe4a80 ldr r2, [pc, #0xf0] */
/* @0xe4a84 tst r6, #1073741824 */
/* @0xe4a88 ubfxeq lr, r6, #0x18, #0x5 */
/* @0xe4a8c ldr r7, [r5, r2] */
/* @0xe4a90 str r4, [r7] */
/* @0xe4a94 beq 0xe4890 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0xc8> */
/* @0xe4a98 ubfx r0, r6, #0x10, #0x4 */
/* @0xe4a9c ubfx lr, r6, #0x18, #0x5 */
/* @0xe4aa0 b 0xe4a44 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x27c> */
/* @0xe4aa4 ldr lr, [pc, #0xf0] */
/* @0xe4aa8 ldr lr, [r5, lr] */
/* @0xe4aac ldr lr, [lr] */
/* @0xe4ab0 cmp r0, lr */
/* @0xe4ab4 bne 0xe49f4 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x22c> */
/* @0xe4ab8 b 0xe486c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0xa4> */
/* @0xe4abc ldr r0, [pc, #0xd0] */
/* @0xe4ac0 ldr r0, [r5, r0] */
/* @0xe4ac4 ldr r0, [r0] */
/* @0xe4ac8 cmp r0, r2 */
/* @0xe4acc blt 0xe486c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0xa4> */
/* @0xe4ad0 cmp r1, r12 */
/* @0xe4ad4 bne 0xe4a1c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x254> */
/* @0xe4ad8 b 0xe486c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0xa4> */
/* @0xe4adc ldr r1, [r12, #0x8] */
/* @0xe4ae0 ldr r2, [r12, #0x10] */
/* @0xe4ae4 ldr r3, [r12, #0xc] */
/* @0xe4ae8 add r2, r2, #1 */
/* @0xe4aec str r1, [r0] */
/* @0xe4af0 sub r3, r3, #1 */
/* @0xe4af4 str r0, [r12, #0x8] */
/* @0xe4af8 str r2, [r12, #0x10] */
/* @0xe4afc str r3, [r12, #0xc] */
/* @0xe4b00 b 0xe4950 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x188> */
/* @0xe4b04 mov r2, r12 */
/* @0xe4b08 b 0xe49d4 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x20c> */
/* @0xe4b0c ldr r2, [pc, #0x8c] */
/* @0xe4b10 ldr r3, [pc, #0x8c] */
/* @0xe4b14 ldr r6, [r5, r2] */
/* @0xe4b18 ldr r7, [r5, r3] */
/* @0xe4b1c ldm r6!, {r0, r1, r2, r3} */
/* @0xe4b20 ldr r6, [r7] */
/* @0xe4b24 sub r8, r6, #16 */
/* @0xe4b28 str r0, [r6, #-0x10] */
/* @0xe4b2c str r1, [r8, #0x4] */
/* @0xe4b30 str r2, [r8, #0x8] */
/* @0xe4b34 str r3, [r8, #0xc] */
/* @0xe4b38 strb r9, [r12] */
/* @0xe4b3c b 0xe4814 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x4c> */
/* @0xe4b40 ldr r0, [r8] */
/* @0xe4b44 ldr r1, [r8, #0x4] */
/* @0xe4b48 ldr r2, [r8, #0x8] */
/* @0xe4b4c ldr r3, [r8, #0xc] */
/* @0xe4b50 str r0, [r10] */
/* @0xe4b54 str r1, [r10, #0x4] */
/* @0xe4b58 str r2, [r10, #0x8] */
/* @0xe4b5c str r3, [r10, #0xc] */
/* @0xe4b60 b 0xe490c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x144> */
/* @0xe4b64 eorseq sp, r0, r0, ror r4 */
/* @0xe4b68 .word 0xffffc0d4 */
/* @0xe4b6c .word 0xffffc0bc */
/* @0xe4b70 .word 0xffffc0a4 */
/* @0xe4b74 .word 0xffffc0e8 */
/* @0xe4b78 .word 0xffffbf58 */
/* @0xe4b7c .word 0xffffc0ec */
/* @0xe4b80 .word 0xffffc0a0 */
/* @0xe4b84 .word 0xffffc0cc */
/* @0xe4b88 .word 0xffffc0dc */
/* @0xe4b8c .word 0xffffc0e4 */
/* @0xe4b90 .word 0xffffc0f0 */
/* @0xe4b94 .word 0xffffc0f4 */
/* @0xe4b98 .word 0xffffc09c */
/* @0xe4b9c .word 0xffffc0f8 */
/* @0xe4ba0 .word 0xffffc0d8 */
/* @0xe4ba4 .word 0xffffc0e0 */

/* ── FUNC 0xe4ba8 · VM::PokeDSList(int, int, RValue&) · size=452 · insn=113 */
/* @0xe4ba8 cmp r0, #0 */
/* @0xe4bac push {r4, r5, lr} */
/* @0xe4bb0 sub sp, sp, #12 */
/* @0xe4bb4 blt 0xe4c8c <_ZN2VM10PokeDSListEiiR6RValue+0xe4> */
/* @0xe4bb8 ldr r3, [pc, #0x1a4] */
/* @0xe4bbc ldr r3, [pc, r3] */
/* @0xe4bc0 ldr r3, [r3] */
/* @0xe4bc4 cmp r0, r3 */
/* @0xe4bc8 bge 0xe4c8c <_ZN2VM10PokeDSListEiiR6RValue+0xe4> */
/* @0xe4bcc ldr r3, [pc, #0x194] */
/* @0xe4bd0 ldr r3, [pc, r3] */
/* @0xe4bd4 ldr r3, [r3, #0x4] */
/* @0xe4bd8 ldr r0, [r3, r0, lsl #2] */
/* @0xe4bdc cmp r0, #0 */
/* @0xe4be0 beq 0xe4c90 <_ZN2VM10PokeDSListEiiR6RValue+0xe8> */
/* @0xe4be4 cmp r1, #0 */
/* @0xe4be8 blt 0xe4c8c <_ZN2VM10PokeDSListEiiR6RValue+0xe4> */
/* @0xe4bec ldr r3, [r0, #0x4] */
/* @0xe4bf0 cmp r1, r3 */
/* @0xe4bf4 bge 0xe4c8c <_ZN2VM10PokeDSListEiiR6RValue+0xe4> */
/* @0xe4bf8 ldr r5, [r0, #0xc] */
/* @0xe4bfc add r4, r5, r1, lsl #4 */
/* @0xe4c00 ldr r3, [r4, #0xc] */
/* @0xe4c04 sub r3, r3, #1 */
/* @0xe4c08 bic r3, r3, #-16777216 */
/* @0xe4c0c bic r3, r3, #3 */
/* @0xe4c10 cmp r3, #0 */
/* @0xe4c14 beq 0xe4ca8 <_ZN2VM10PokeDSListEiiR6RValue+0x100> */
/* @0xe4c18 mov r3, #5 */
/* @0xe4c1c str r3, [r4, #0xc] */
/* @0xe4c20 ldr r12, [r2, #0xc] */
/* @0xe4c24 mov r3, #0 */
/* @0xe4c28 str r3, [r4, #0x8] */
/* @0xe4c2c str r3, [r5, r1, lsl #4] */
/* @0xe4c30 ldr r0, [r2, #0x8] */
/* @0xe4c34 str r12, [r4, #0xc] */
/* @0xe4c38 ldr r3, [r2, #0xc] */
/* @0xe4c3c str r0, [r4, #0x8] */
/* @0xe4c40 bic r3, r3, #-16777216 */
/* @0xe4c44 cmp r3, #14 */
/* @0xe4c48 addls pc, pc, r3, lsl #2 */
/* @0xe4c4c b 0xe4d2c <_ZN2VM10PokeDSListEiiR6RValue+0x184> */
/* @0xe4c50 b 0xe4cc4 <_ZN2VM10PokeDSListEiiR6RValue+0x11c> */
/* @0xe4c54 b 0xe4cdc <_ZN2VM10PokeDSListEiiR6RValue+0x134> */
/* @0xe4c58 b 0xe4cfc <_ZN2VM10PokeDSListEiiR6RValue+0x154> */
/* @0xe4c5c b 0xe4c98 <_ZN2VM10PokeDSListEiiR6RValue+0xf0> */
/* @0xe4c60 b 0xe4d2c <_ZN2VM10PokeDSListEiiR6RValue+0x184> */
/* @0xe4c64 b 0xe4d2c <_ZN2VM10PokeDSListEiiR6RValue+0x184> */
/* @0xe4c68 b 0xe4d34 <_ZN2VM10PokeDSListEiiR6RValue+0x18c> */
/* @0xe4c6c b 0xe4c98 <_ZN2VM10PokeDSListEiiR6RValue+0xf0> */
/* @0xe4c70 b 0xe4d2c <_ZN2VM10PokeDSListEiiR6RValue+0x184> */
/* @0xe4c74 b 0xe4d2c <_ZN2VM10PokeDSListEiiR6RValue+0x184> */
/* @0xe4c78 b 0xe4cc4 <_ZN2VM10PokeDSListEiiR6RValue+0x11c> */
/* @0xe4c7c b 0xe4d2c <_ZN2VM10PokeDSListEiiR6RValue+0x184> */
/* @0xe4c80 b 0xe4d2c <_ZN2VM10PokeDSListEiiR6RValue+0x184> */
/* @0xe4c84 b 0xe4cc4 <_ZN2VM10PokeDSListEiiR6RValue+0x11c> */
/* @0xe4c88 b 0xe4c98 <_ZN2VM10PokeDSListEiiR6RValue+0xf0> */
/* @0xe4c8c mov r0, #0 */
/* @0xe4c90 add sp, sp, #12 */
/* @0xe4c94 pop {r4, r5, pc} */
/* @0xe4c98 ldr r3, [r2] */
/* @0xe4c9c mov r0, #1 */
/* @0xe4ca0 str r3, [r5, r1, lsl #4] */
/* @0xe4ca4 b 0xe4c90 <_ZN2VM10PokeDSListEiiR6RValue+0xe8> */
/* @0xe4ca8 mov r0, r4 */
/* @0xe4cac str r1, [sp, #0x4] */
/* @0xe4cb0 str r2, [sp] */
/* @0xe4cb4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe4cb8 ldr r2, [sp] */
/* @0xe4cbc ldr r1, [sp, #0x4] */
/* @0xe4cc0 b 0xe4c18 <_ZN2VM10PokeDSListEiiR6RValue+0x70> */
/* @0xe4cc4 ldr r12, [r2] */
/* @0xe4cc8 mov r0, #1 */
/* @0xe4ccc ldr r3, [r2, #0x4] */
/* @0xe4cd0 str r12, [r5, r1, lsl #4] */
/* @0xe4cd4 str r3, [r4, #0x4] */
/* @0xe4cd8 b 0xe4c90 <_ZN2VM10PokeDSListEiiR6RValue+0xe8> */
/* @0xe4cdc ldr r3, [r2] */
/* @0xe4ce0 mov r0, #1 */
/* @0xe4ce4 cmp r3, #0 */
/* @0xe4ce8 ldrne r2, [r3, #0x4] */
/* @0xe4cec addne r2, r2, #1 */
/* @0xe4cf0 strne r2, [r3, #0x4] */
/* @0xe4cf4 str r3, [r5, r1, lsl #4] */
/* @0xe4cf8 b 0xe4c90 <_ZN2VM10PokeDSListEiiR6RValue+0xe8> */
/* @0xe4cfc ldr r3, [r2] */
/* @0xe4d00 cmp r3, #0 */
/* @0xe4d04 str r3, [r5, r1, lsl #4] */
/* @0xe4d08 beq 0xe4d2c <_ZN2VM10PokeDSListEiiR6RValue+0x184> */
/* @0xe4d0c ldr r1, [r3, #0x8] */
/* @0xe4d10 ldr r2, [r3] */
/* @0xe4d14 cmp r1, #0 */
/* @0xe4d18 streq r4, [r3, #0x8] */
/* @0xe4d1c add r2, r2, #1 */
/* @0xe4d20 str r2, [r3] */
/* @0xe4d24 moveq r0, #1 */
/* @0xe4d28 beq 0xe4c90 <_ZN2VM10PokeDSListEiiR6RValue+0xe8> */
/* @0xe4d2c mov r0, #1 */
/* @0xe4d30 b 0xe4c90 <_ZN2VM10PokeDSListEiiR6RValue+0xe8> */
/* @0xe4d34 ldr r3, [r2] */
/* @0xe4d38 str r3, [r5, r1, lsl #4] */
/* @0xe4d3c ldr r3, [r2] */
/* @0xe4d40 cmp r3, #0 */
/* @0xe4d44 beq 0xe4d2c <_ZN2VM10PokeDSListEiiR6RValue+0x184> */
/* @0xe4d48 str r2, [sp] */
/* @0xe4d4c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xe4d50 ldr r2, [sp] */
/* @0xe4d54 ldr r1, [r2] */
/* @0xe4d58 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xe4d5c mov r0, #1 */
/* @0xe4d60 b 0xe4c90 <_ZN2VM10PokeDSListEiiR6RValue+0xe8> */
/* @0xe4d64 eorseq r9, r0, r0, asr #1 */
/* @0xe4d68 ldrhteq r9, [r0], -r0 */

/* ── FUNC 0xe4d6c · VM::PokeDSStack(int, int, RValue&) · size=428 · insn=107 */
/* @0xe4d6c push {r4, r5, r6, r7, lr} */
/* @0xe4d70 sub sp, sp, #12 */
/* @0xe4d74 mov r4, r0 */
/* @0xe4d78 add r0, sp, #4 */
/* @0xe4d7c mov r5, r1 */
/* @0xe4d80 mov r6, r2 */
/* @0xe4d84 bl 0xffc9c <_Z12GetTheStacksRi> */
/* @0xe4d88 cmp r4, #0 */
/* @0xe4d8c blt 0xe4e58 <_ZN2VM11PokeDSStackEiiR6RValue+0xec> */
/* @0xe4d90 ldr r3, [sp, #0x4] */
/* @0xe4d94 cmp r4, r3 */
/* @0xe4d98 bge 0xe4e58 <_ZN2VM11PokeDSStackEiiR6RValue+0xec> */
/* @0xe4d9c ldr r0, [r0, r4, lsl #2] */
/* @0xe4da0 cmp r0, #0 */
/* @0xe4da4 beq 0xe4e5c <_ZN2VM11PokeDSStackEiiR6RValue+0xf0> */
/* @0xe4da8 cmp r5, #0 */
/* @0xe4dac blt 0xe4e58 <_ZN2VM11PokeDSStackEiiR6RValue+0xec> */
/* @0xe4db0 ldr r3, [r0, #0x4] */
/* @0xe4db4 cmp r5, r3 */
/* @0xe4db8 bge 0xe4e58 <_ZN2VM11PokeDSStackEiiR6RValue+0xec> */
/* @0xe4dbc sub r3, r3, #1 */
/* @0xe4dc0 ldr r7, [r0, #0xc] */
/* @0xe4dc4 rsb r5, r5, r3 */
/* @0xe4dc8 add r4, r7, r5, lsl #4 */
/* @0xe4dcc ldr r3, [r4, #0xc] */
/* @0xe4dd0 sub r3, r3, #1 */
/* @0xe4dd4 bic r3, r3, #-16777216 */
/* @0xe4dd8 bic r3, r3, #3 */
/* @0xe4ddc cmp r3, #0 */
/* @0xe4de0 beq 0xe4e74 <_ZN2VM11PokeDSStackEiiR6RValue+0x108> */
/* @0xe4de4 mov r3, #5 */
/* @0xe4de8 str r3, [r4, #0xc] */
/* @0xe4dec ldr r1, [r6, #0xc] */
/* @0xe4df0 mov r3, #0 */
/* @0xe4df4 str r3, [r4, #0x8] */
/* @0xe4df8 str r3, [r7, r5, lsl #4] */
/* @0xe4dfc ldr r2, [r6, #0x8] */
/* @0xe4e00 str r1, [r4, #0xc] */
/* @0xe4e04 ldr r3, [r6, #0xc] */
/* @0xe4e08 str r2, [r4, #0x8] */
/* @0xe4e0c bic r3, r3, #-16777216 */
/* @0xe4e10 cmp r3, #14 */
/* @0xe4e14 addls pc, pc, r3, lsl #2 */
/* @0xe4e18 b 0xe4ee8 <_ZN2VM11PokeDSStackEiiR6RValue+0x17c> */
/* @0xe4e1c b 0xe4e80 <_ZN2VM11PokeDSStackEiiR6RValue+0x114> */
/* @0xe4e20 b 0xe4e98 <_ZN2VM11PokeDSStackEiiR6RValue+0x12c> */
/* @0xe4e24 b 0xe4eb8 <_ZN2VM11PokeDSStackEiiR6RValue+0x14c> */
/* @0xe4e28 b 0xe4e64 <_ZN2VM11PokeDSStackEiiR6RValue+0xf8> */
/* @0xe4e2c b 0xe4ee8 <_ZN2VM11PokeDSStackEiiR6RValue+0x17c> */
/* @0xe4e30 b 0xe4ee8 <_ZN2VM11PokeDSStackEiiR6RValue+0x17c> */
/* @0xe4e34 b 0xe4ef0 <_ZN2VM11PokeDSStackEiiR6RValue+0x184> */
/* @0xe4e38 b 0xe4e64 <_ZN2VM11PokeDSStackEiiR6RValue+0xf8> */
/* @0xe4e3c b 0xe4ee8 <_ZN2VM11PokeDSStackEiiR6RValue+0x17c> */
/* @0xe4e40 b 0xe4ee8 <_ZN2VM11PokeDSStackEiiR6RValue+0x17c> */
/* @0xe4e44 b 0xe4e80 <_ZN2VM11PokeDSStackEiiR6RValue+0x114> */
/* @0xe4e48 b 0xe4ee8 <_ZN2VM11PokeDSStackEiiR6RValue+0x17c> */
/* @0xe4e4c b 0xe4ee8 <_ZN2VM11PokeDSStackEiiR6RValue+0x17c> */
/* @0xe4e50 b 0xe4e80 <_ZN2VM11PokeDSStackEiiR6RValue+0x114> */
/* @0xe4e54 b 0xe4e64 <_ZN2VM11PokeDSStackEiiR6RValue+0xf8> */
/* @0xe4e58 mov r0, #0 */
/* @0xe4e5c add sp, sp, #12 */
/* @0xe4e60 pop {r4, r5, r6, r7, pc} */
/* @0xe4e64 ldr r3, [r6] */
/* @0xe4e68 mov r0, #1 */
/* @0xe4e6c str r3, [r7, r5, lsl #4] */
/* @0xe4e70 b 0xe4e5c <_ZN2VM11PokeDSStackEiiR6RValue+0xf0> */
/* @0xe4e74 mov r0, r4 */
/* @0xe4e78 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe4e7c b 0xe4de4 <_ZN2VM11PokeDSStackEiiR6RValue+0x78> */
/* @0xe4e80 ldr r2, [r6] */
/* @0xe4e84 mov r0, #1 */
/* @0xe4e88 ldr r3, [r6, #0x4] */
/* @0xe4e8c str r2, [r7, r5, lsl #4] */
/* @0xe4e90 str r3, [r4, #0x4] */
/* @0xe4e94 b 0xe4e5c <_ZN2VM11PokeDSStackEiiR6RValue+0xf0> */
/* @0xe4e98 ldr r3, [r6] */
/* @0xe4e9c mov r0, #1 */
/* @0xe4ea0 cmp r3, #0 */
/* @0xe4ea4 ldrne r2, [r3, #0x4] */
/* @0xe4ea8 addne r2, r2, #1 */
/* @0xe4eac strne r2, [r3, #0x4] */
/* @0xe4eb0 str r3, [r7, r5, lsl #4] */
/* @0xe4eb4 b 0xe4e5c <_ZN2VM11PokeDSStackEiiR6RValue+0xf0> */
/* @0xe4eb8 ldr r3, [r6] */
/* @0xe4ebc cmp r3, #0 */
/* @0xe4ec0 str r3, [r7, r5, lsl #4] */
/* @0xe4ec4 beq 0xe4ee8 <_ZN2VM11PokeDSStackEiiR6RValue+0x17c> */
/* @0xe4ec8 ldr r1, [r3, #0x8] */
/* @0xe4ecc ldr r2, [r3] */
/* @0xe4ed0 cmp r1, #0 */
/* @0xe4ed4 streq r4, [r3, #0x8] */
/* @0xe4ed8 add r2, r2, #1 */
/* @0xe4edc str r2, [r3] */
/* @0xe4ee0 moveq r0, #1 */
/* @0xe4ee4 beq 0xe4e5c <_ZN2VM11PokeDSStackEiiR6RValue+0xf0> */
/* @0xe4ee8 mov r0, #1 */
/* @0xe4eec b 0xe4e5c <_ZN2VM11PokeDSStackEiiR6RValue+0xf0> */
/* @0xe4ef0 ldr r3, [r6] */
/* @0xe4ef4 str r3, [r7, r5, lsl #4] */
/* @0xe4ef8 ldr r3, [r6] */
/* @0xe4efc cmp r3, #0 */
/* @0xe4f00 beq 0xe4ee8 <_ZN2VM11PokeDSStackEiiR6RValue+0x17c> */
/* @0xe4f04 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xe4f08 ldr r1, [r6] */
/* @0xe4f0c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xe4f10 mov r0, #1 */
/* @0xe4f14 b 0xe4e5c <_ZN2VM11PokeDSStackEiiR6RValue+0xf0> */

/* ── FUNC 0xe4f18 · VM::PokeDSQueue(int, int, RValue&) · size=412 · insn=103 */
/* @0xe4f18 push {r4, r5, r6, r7, r8, lr} */
/* @0xe4f1c sub sp, sp, #8 */
/* @0xe4f20 mov r4, r0 */
/* @0xe4f24 add r0, sp, #4 */
/* @0xe4f28 mov r6, r1 */
/* @0xe4f2c mov r5, r2 */
/* @0xe4f30 bl 0xffee8 <_Z12GetTheQueuesRi> */
/* @0xe4f34 cmp r4, #0 */
/* @0xe4f38 blt 0xe500c <_ZN2VM11PokeDSQueueEiiR6RValue+0xf4> */
/* @0xe4f3c ldr r3, [sp, #0x4] */
/* @0xe4f40 cmp r4, r3 */
/* @0xe4f44 bge 0xe500c <_ZN2VM11PokeDSQueueEiiR6RValue+0xf4> */
/* @0xe4f48 ldr r3, [r0, r4, lsl #2] */
/* @0xe4f4c ldr r2, [r3, #0x8] */
/* @0xe4f50 ldr r4, [r3, #0x4] */
/* @0xe4f54 rsb r4, r2, r4 */
/* @0xe4f58 cmp r6, r4 */
/* @0xe4f5c movgt r4, #0 */
/* @0xe4f60 movle r4, #1 */
/* @0xe4f64 cmp r6, #0 */
/* @0xe4f68 movlt r4, #0 */
/* @0xe4f6c cmp r4, #0 */
/* @0xe4f70 beq 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8> */
/* @0xe4f74 ldr r8, [r3, #0x10] */
/* @0xe4f78 add r6, r2, r6 */
/* @0xe4f7c add r7, r8, r6, lsl #4 */
/* @0xe4f80 ldr r3, [r7, #0xc] */
/* @0xe4f84 sub r3, r3, #1 */
/* @0xe4f88 bic r3, r3, #-16777216 */
/* @0xe4f8c bic r3, r3, #3 */
/* @0xe4f90 cmp r3, #0 */
/* @0xe4f94 beq 0xe5040 <_ZN2VM11PokeDSQueueEiiR6RValue+0x128> */
/* @0xe4f98 mov r3, #5 */
/* @0xe4f9c str r3, [r7, #0xc] */
/* @0xe4fa0 ldr r1, [r5, #0xc] */
/* @0xe4fa4 mov r3, #0 */
/* @0xe4fa8 str r3, [r7, #0x8] */
/* @0xe4fac str r3, [r8, r6, lsl #4] */
/* @0xe4fb0 ldr r2, [r5, #0x8] */
/* @0xe4fb4 str r1, [r7, #0xc] */
/* @0xe4fb8 ldr r3, [r5, #0xc] */
/* @0xe4fbc str r2, [r7, #0x8] */
/* @0xe4fc0 bic r3, r3, #-16777216 */
/* @0xe4fc4 cmp r3, #14 */
/* @0xe4fc8 addls pc, pc, r3, lsl #2 */
/* @0xe4fcc b 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8> */
/* @0xe4fd0 b 0xe5030 <_ZN2VM11PokeDSQueueEiiR6RValue+0x118> */
/* @0xe4fd4 b 0xe5070 <_ZN2VM11PokeDSQueueEiiR6RValue+0x158> */
/* @0xe4fd8 b 0xe5088 <_ZN2VM11PokeDSQueueEiiR6RValue+0x170> */
/* @0xe4fdc b 0xe501c <_ZN2VM11PokeDSQueueEiiR6RValue+0x104> */
/* @0xe4fe0 b 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8> */
/* @0xe4fe4 b 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8> */
/* @0xe4fe8 b 0xe504c <_ZN2VM11PokeDSQueueEiiR6RValue+0x134> */
/* @0xe4fec b 0xe501c <_ZN2VM11PokeDSQueueEiiR6RValue+0x104> */
/* @0xe4ff0 b 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8> */
/* @0xe4ff4 b 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8> */
/* @0xe4ff8 b 0xe5030 <_ZN2VM11PokeDSQueueEiiR6RValue+0x118> */
/* @0xe4ffc b 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8> */
/* @0xe5000 b 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8> */
/* @0xe5004 b 0xe5030 <_ZN2VM11PokeDSQueueEiiR6RValue+0x118> */
/* @0xe5008 b 0xe501c <_ZN2VM11PokeDSQueueEiiR6RValue+0x104> */
/* @0xe500c mov r4, #0 */
/* @0xe5010 mov r0, r4 */
/* @0xe5014 add sp, sp, #8 */
/* @0xe5018 pop {r4, r5, r6, r7, r8, pc} */
/* @0xe501c ldr r3, [r5] */
/* @0xe5020 mov r0, r4 */
/* @0xe5024 str r3, [r8, r6, lsl #4] */
/* @0xe5028 add sp, sp, #8 */
/* @0xe502c pop {r4, r5, r6, r7, r8, pc} */
/* @0xe5030 ldm r5, {r2, r3} */
/* @0xe5034 str r2, [r8, r6, lsl #4] */
/* @0xe5038 str r3, [r7, #0x4] */
/* @0xe503c b 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8> */
/* @0xe5040 mov r0, r7 */
/* @0xe5044 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe5048 b 0xe4f98 <_ZN2VM11PokeDSQueueEiiR6RValue+0x80> */
/* @0xe504c ldr r3, [r5] */
/* @0xe5050 str r3, [r8, r6, lsl #4] */
/* @0xe5054 ldr r3, [r5] */
/* @0xe5058 cmp r3, #0 */
/* @0xe505c beq 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8> */
/* @0xe5060 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xe5064 ldr r1, [r5] */
/* @0xe5068 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xe506c b 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8> */
/* @0xe5070 ldr r3, [r5] */
/* @0xe5074 cmp r3, #0 */
/* @0xe5078 ldrne r2, [r3, #0x4] */
/* @0xe507c addne r2, r2, #1 */
/* @0xe5080 strne r2, [r3, #0x4] */
/* @0xe5084 b 0xe5020 <_ZN2VM11PokeDSQueueEiiR6RValue+0x108> */
/* @0xe5088 ldr r3, [r5] */
/* @0xe508c cmp r3, #0 */
/* @0xe5090 str r3, [r8, r6, lsl #4] */
/* @0xe5094 beq 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8> */
/* @0xe5098 ldr r1, [r3, #0x8] */
/* @0xe509c ldr r2, [r3] */
/* @0xe50a0 cmp r1, #0 */
/* @0xe50a4 streq r7, [r3, #0x8] */
/* @0xe50a8 add r2, r2, #1 */
/* @0xe50ac str r2, [r3] */
/* @0xe50b0 b 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8> */

/* ── FUNC 0xe50b4 · VM::PokeDSPriority(int, int, RValue&) · size=420 · insn=105 */
/* @0xe50b4 push {r4, r5, r6, r7, lr} */
/* @0xe50b8 sub sp, sp, #12 */
/* @0xe50bc mov r4, r0 */
/* @0xe50c0 add r0, sp, #4 */
/* @0xe50c4 mov r5, r1 */
/* @0xe50c8 mov r6, r2 */
/* @0xe50cc bl 0x100244 <_Z20GetThePriorityQueuesRi> */
/* @0xe50d0 cmp r4, #0 */
/* @0xe50d4 blt 0xe5198 <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe4> */
/* @0xe50d8 ldr r3, [sp, #0x4] */
/* @0xe50dc cmp r4, r3 */
/* @0xe50e0 bge 0xe5198 <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe4> */
/* @0xe50e4 ldr r0, [r0, r4, lsl #2] */
/* @0xe50e8 cmp r0, #0 */
/* @0xe50ec beq 0xe519c <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe8> */
/* @0xe50f0 cmp r5, #0 */
/* @0xe50f4 blt 0xe5198 <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe4> */
/* @0xe50f8 ldr r3, [r0, #0x4] */
/* @0xe50fc cmp r5, r3 */
/* @0xe5100 bge 0xe5198 <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe4> */
/* @0xe5104 ldr r7, [r0, #0xc] */
/* @0xe5108 add r4, r7, r5, lsl #4 */
/* @0xe510c ldr r3, [r4, #0xc] */
/* @0xe5110 sub r3, r3, #1 */
/* @0xe5114 bic r3, r3, #-16777216 */
/* @0xe5118 bic r3, r3, #3 */
/* @0xe511c cmp r3, #0 */
/* @0xe5120 beq 0xe51b4 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x100> */
/* @0xe5124 mov r3, #5 */
/* @0xe5128 str r3, [r4, #0xc] */
/* @0xe512c ldr r1, [r6, #0xc] */
/* @0xe5130 mov r3, #0 */
/* @0xe5134 str r3, [r4, #0x8] */
/* @0xe5138 str r3, [r7, r5, lsl #4] */
/* @0xe513c ldr r2, [r6, #0x8] */
/* @0xe5140 str r1, [r4, #0xc] */
/* @0xe5144 ldr r3, [r6, #0xc] */
/* @0xe5148 str r2, [r4, #0x8] */
/* @0xe514c bic r3, r3, #-16777216 */
/* @0xe5150 cmp r3, #14 */
/* @0xe5154 addls pc, pc, r3, lsl #2 */
/* @0xe5158 b 0xe5228 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x174> */
/* @0xe515c b 0xe51c0 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x10c> */
/* @0xe5160 b 0xe51d8 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x124> */
/* @0xe5164 b 0xe51f8 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x144> */
/* @0xe5168 b 0xe51a4 <_ZN2VM14PokeDSPriorityEiiR6RValue+0xf0> */
/* @0xe516c b 0xe5228 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x174> */
/* @0xe5170 b 0xe5228 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x174> */
/* @0xe5174 b 0xe5230 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x17c> */
/* @0xe5178 b 0xe51a4 <_ZN2VM14PokeDSPriorityEiiR6RValue+0xf0> */
/* @0xe517c b 0xe5228 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x174> */
/* @0xe5180 b 0xe5228 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x174> */
/* @0xe5184 b 0xe51c0 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x10c> */
/* @0xe5188 b 0xe5228 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x174> */
/* @0xe518c b 0xe5228 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x174> */
/* @0xe5190 b 0xe51c0 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x10c> */
/* @0xe5194 b 0xe51a4 <_ZN2VM14PokeDSPriorityEiiR6RValue+0xf0> */
/* @0xe5198 mov r0, #0 */
/* @0xe519c add sp, sp, #12 */
/* @0xe51a0 pop {r4, r5, r6, r7, pc} */
/* @0xe51a4 ldr r3, [r6] */
/* @0xe51a8 mov r0, #1 */
/* @0xe51ac str r3, [r7, r5, lsl #4] */
/* @0xe51b0 b 0xe519c <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe8> */
/* @0xe51b4 mov r0, r4 */
/* @0xe51b8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe51bc b 0xe5124 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x70> */
/* @0xe51c0 ldr r2, [r6] */
/* @0xe51c4 mov r0, #1 */
/* @0xe51c8 ldr r3, [r6, #0x4] */
/* @0xe51cc str r2, [r7, r5, lsl #4] */
/* @0xe51d0 str r3, [r4, #0x4] */
/* @0xe51d4 b 0xe519c <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe8> */
/* @0xe51d8 ldr r3, [r6] */
/* @0xe51dc mov r0, #1 */
/* @0xe51e0 cmp r3, #0 */
/* @0xe51e4 ldrne r2, [r3, #0x4] */
/* @0xe51e8 addne r2, r2, #1 */
/* @0xe51ec strne r2, [r3, #0x4] */
/* @0xe51f0 str r3, [r7, r5, lsl #4] */
/* @0xe51f4 b 0xe519c <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe8> */
/* @0xe51f8 ldr r3, [r6] */
/* @0xe51fc cmp r3, #0 */
/* @0xe5200 str r3, [r7, r5, lsl #4] */
/* @0xe5204 beq 0xe5228 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x174> */
/* @0xe5208 ldr r1, [r3, #0x8] */
/* @0xe520c ldr r2, [r3] */
/* @0xe5210 cmp r1, #0 */
/* @0xe5214 streq r4, [r3, #0x8] */
/* @0xe5218 add r2, r2, #1 */
/* @0xe521c str r2, [r3] */
/* @0xe5220 moveq r0, #1 */
/* @0xe5224 beq 0xe519c <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe8> */
/* @0xe5228 mov r0, #1 */
/* @0xe522c b 0xe519c <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe8> */
/* @0xe5230 ldr r3, [r6] */
/* @0xe5234 str r3, [r7, r5, lsl #4] */
/* @0xe5238 ldr r3, [r6] */
/* @0xe523c cmp r3, #0 */
/* @0xe5240 beq 0xe5228 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x174> */
/* @0xe5244 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xe5248 ldr r1, [r6] */
/* @0xe524c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xe5250 mov r0, #1 */
/* @0xe5254 b 0xe519c <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe8> */

/* ── FUNC 0xe5258 · YYCreateString(RValue*, char const*) · size=116 · insn=29 */
/* @0xe5258 ldr r3, [r0, #0xc] */
/* @0xe525c push {r4, r5, r6, lr} */
/* @0xe5260 sub r3, r3, #1 */
/* @0xe5264 bic r3, r3, #-16777216 */
/* @0xe5268 mov r4, r0 */
/* @0xe526c bic r3, r3, #3 */
/* @0xe5270 mov r6, r1 */
/* @0xe5274 cmp r3, #0 */
/* @0xe5278 bne 0xe5280 <_Z14YYCreateStringP6RValuePKc+0x28> */
/* @0xe527c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe5280 mov r3, #0 */
/* @0xe5284 mov r2, #5 */
/* @0xe5288 str r3, [r4, #0x8] */
/* @0xe528c mov r0, #12 */
/* @0xe5290 str r3, [r4] */
/* @0xe5294 str r2, [r4, #0xc] */
/* @0xe5298 bl 0x27c524 <_Znwj> */
/* @0xe529c mov r5, r0 */
/* @0xe52a0 subs r0, r6, #0 */
/* @0xe52a4 beq 0xe52ac <_Z14YYCreateStringP6RValuePKc+0x54> */
/* @0xe52a8 bl 0xb6538 <strlen@plt> */
/* @0xe52ac str r0, [r5, #0x8] */
/* @0xe52b0 mov r0, r6 */
/* @0xe52b4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xe52b8 mov r3, #1 */
/* @0xe52bc stm r5, {r0, r3} */
/* @0xe52c0 str r3, [r4, #0xc] */
/* @0xe52c4 str r5, [r4] */
/* @0xe52c8 pop {r4, r5, r6, pc} */

/* ── FUNC 0xe52cc · F_VMGetCallStack(RValue&, CInstance*, CInstance*, int, RValue*) · size=1348 · insn=337 */
/* @0xe52cc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe52d0 mov r11, r0 */
/* @0xe52d4 ldr r4, [pc, #0x520] */
/* @0xe52d8 sub sp, sp, #52 */
/* @0xe52dc ldr r4, [pc, r4] */
/* @0xe52e0 ldr r3, [r4] */
/* @0xe52e4 cmp r3, #0 */
/* @0xe52e8 beq 0xe57f0 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x524> */
/* @0xe52ec mov r2, #0 */
/* @0xe52f0 ldr r1, [r3, #0x4c] */
/* @0xe52f4 add r2, r2, #1 */
/* @0xe52f8 ldr r3, [r3, #0x4] */
/* @0xe52fc add r2, r2, r1 */
/* @0xe5300 cmp r3, #0 */
/* @0xe5304 bne 0xe52f0 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0xe5308 add r7, r2, #1 */
/* @0xe530c lsl r8, r7, #4 */
/* @0xe5310 mov r3, #2 */
/* @0xe5314 mov r0, r11 */
/* @0xe5318 str r3, [r11, #0xc] */
/* @0xe531c mov r6, #1 */
/* @0xe5320 bl 0xced9c <_Z14ARRAY_RefAllocPv> */
/* @0xe5324 ldr r1, [pc, #0x4d4] */
/* @0xe5328 mov r3, r6 */
/* @0xe532c mov r2, #70 */
/* @0xe5330 add r1, pc, r1 */
/* @0xe5334 mov r9, #0 */
/* @0xe5338 mov r5, r0 */
/* @0xe533c str r0, [r11] */
/* @0xe5340 str r6, [r5, #0x10] */
/* @0xe5344 mov r0, #8 */
/* @0xe5348 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xe534c ldr r1, [pc, #0x4b0] */
/* @0xe5350 mov r3, r6 */
/* @0xe5354 movw r2, #0x299f */
/* @0xe5358 add r1, pc, r1 */
/* @0xe535c str r0, [r5, #0x4] */
/* @0xe5360 mov r0, r8 */
/* @0xe5364 ldr r12, [r11] */
/* @0xe5368 ldr r5, [r12, #0x4] */
/* @0xe536c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xe5370 ldr r4, [r4] */
/* @0xe5374 cmp r4, r9 */
/* @0xe5378 str r0, [r5, #0x4] */
/* @0xe537c ldr r3, [r11] */
/* @0xe5380 ldr r3, [r3, #0x4] */
/* @0xe5384 str r7, [r3] */
/* @0xe5388 str r9, [sp, #0x24] */
/* @0xe538c str r9, [sp, #0x28] */
/* @0xe5390 str r9, [sp, #0x2c] */
/* @0xe5394 beq 0xe55c4 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x2f8> */
/* @0xe5398 ldr r3, [pc, #0x468] */
/* @0xe539c mov r10, r9 */
/* @0xe53a0 str r11, [sp, #0x4] */
/* @0xe53a4 add r3, pc, r3 */
/* @0xe53a8 str r3, [sp, #0x1c] */
/* @0xe53ac ldr r3, [pc, #0x458] */
/* @0xe53b0 add r3, pc, r3 */
/* @0xe53b4 str r3, [sp, #0x18] */
/* @0xe53b8 add r3, sp, #32 */
/* @0xe53bc str r3, [sp, #0xc] */
/* @0xe53c0 add r3, sp, #36 */
/* @0xe53c4 str r3, [sp, #0x10] */
/* @0xe53c8 ldr r0, [r4, #0x38] */
/* @0xe53cc str r10, [sp, #0x20] */
/* @0xe53d0 cmp r0, #0 */
/* @0xe53d4 beq 0xe57a0 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0xe53d8 ldr r1, [r4, #0x54] */
/* @0xe53dc bl 0xec144 <_ZN2VM9DebugInfoEP8VMBufferi> */
/* @0xe53e0 ldr r1, [r4, #0x3c] */
/* @0xe53e4 add r2, sp, #32 */
/* @0xe53e8 bl 0xec2b8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc> */
/* @0xe53ec ldr r8, [r4, #0x34] */
/* @0xe53f0 cmp r8, #0 */
/* @0xe53f4 ldreq r5, [sp, #0x2c] */
/* @0xe53f8 mov r6, r0 */
/* @0xe53fc beq 0xe54a0 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x1d4> */
/* @0xe5400 mov r0, r8 */
/* @0xe5404 bl 0xb6538 <strlen@plt> */
/* @0xe5408 ldr r2, [sp, #0x2c] */
/* @0xe540c ldr r3, [sp, #0x28] */
/* @0xe5410 add r1, r0, #1 */
/* @0xe5414 mov r5, r0 */
/* @0xe5418 mvn r0, r2 */
/* @0xe541c add r0, r3, r0 */
/* @0xe5420 cmp r1, r0 */
/* @0xe5424 ble 0xe5484 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0xe5428 cmp r3, #0 */
/* @0xe542c add r2, r1, r2 */
/* @0xe5430 ldr r7, [sp, #0x24] */
/* @0xe5434 moveq r3, r1 */
/* @0xe5438 add r3, r3, r3, lsl #1 */
/* @0xe543c add r3, r3, r3, lsr #31 */
/* @0xe5440 asr r11, r3, #1 */
/* @0xe5444 cmp r11, r2 */
/* @0xe5448 addlt r2, r2, r2, lsl #1 */
/* @0xe544c addlt r2, r2, r2, lsr #31 */
/* @0xe5450 asrlt r11, r2, #1 */
/* @0xe5454 mov r0, r11 */
/* @0xe5458 bl 0xcef4c <_Z7YYAlloci> */
/* @0xe545c ldr r2, [sp, #0x28] */
/* @0xe5460 mov r1, r7 */
/* @0xe5464 str r0, [sp, #0x24] */
/* @0xe5468 bl 0xb65bc <memcpy@plt> */
/* @0xe546c cmp r7, #0 */
/* @0xe5470 str r11, [sp, #0x28] */
/* @0xe5474 beq 0xe5480 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0xe5478 mov r0, r7 */
/* @0xe547c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe5480 ldr r2, [sp, #0x2c] */
/* @0xe5484 ldr r0, [sp, #0x24] */
/* @0xe5488 mov r1, r8 */
/* @0xe548c add r0, r0, r2 */
/* @0xe5490 bl 0xb65a4 <strcpy@plt> */
/* @0xe5494 ldr r3, [sp, #0x2c] */
/* @0xe5498 add r5, r5, r3 */
/* @0xe549c str r5, [sp, #0x2c] */
/* @0xe54a0 ldr r3, [sp, #0x28] */
/* @0xe54a4 mvn r2, r5 */
/* @0xe54a8 add r2, r3, r2 */
/* @0xe54ac cmp r2, #1 */
/* @0xe54b0 bgt 0xe5510 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x244> */
/* @0xe54b4 cmp r3, #0 */
/* @0xe54b8 add r5, r5, #2 */
/* @0xe54bc addne r3, r3, r3, lsl #1 */
/* @0xe54c0 moveq r7, #3 */
/* @0xe54c4 addne r3, r3, r3, lsr #31 */
/* @0xe54c8 asrne r7, r3, #1 */
/* @0xe54cc cmp r5, r7 */
/* @0xe54d0 addgt r5, r5, r5, lsl #1 */
/* @0xe54d4 addgt r5, r5, r5, lsr #31 */
/* @0xe54d8 asrgt r7, r5, #1 */
/* @0xe54dc ldr r5, [sp, #0x24] */
/* @0xe54e0 mov r0, r7 */
/* @0xe54e4 bl 0xcef4c <_Z7YYAlloci> */
/* @0xe54e8 ldr r2, [sp, #0x28] */
/* @0xe54ec mov r1, r5 */
/* @0xe54f0 str r0, [sp, #0x24] */
/* @0xe54f4 bl 0xb65bc <memcpy@plt> */
/* @0xe54f8 cmp r5, #0 */
/* @0xe54fc str r7, [sp, #0x28] */
/* @0xe5500 beq 0xe550c <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x240> */
/* @0xe5504 mov r0, r5 */
/* @0xe5508 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe550c ldr r5, [sp, #0x2c] */
/* @0xe5510 ldr r0, [sp, #0x1c] */
/* @0xe5514 mov r1, r6 */
/* @0xe5518 ldr r3, [sp, #0x24] */
/* @0xe551c add r8, r9, #1 */
/* @0xe5520 ldrh r2, [r0] */
/* @0xe5524 add r0, sp, #36 */
/* @0xe5528 strh r2, [r3, r5] */
/* @0xe552c ldr r3, [sp, #0x2c] */
/* @0xe5530 add r3, r3, #1 */
/* @0xe5534 str r3, [sp, #0x2c] */
/* @0xe5538 bl 0xd58c4 <_ZN12YYStrBuilderlsEi> */
/* @0xe553c ldr r2, [sp, #0x4] */
/* @0xe5540 ldr r3, [r2] */
/* @0xe5544 ldr r2, [sp, #0x2c] */
/* @0xe5548 ldr r3, [r3, #0x4] */
/* @0xe554c cmp r2, #0 */
/* @0xe5550 addeq r1, sp, #44 */
/* @0xe5554 ldrne r1, [sp, #0x24] */
/* @0xe5558 ldr r0, [r3, #0x4] */
/* @0xe555c str r10, [sp, #0x2c] */
/* @0xe5560 add r0, r0, r9, lsl #4 */
/* @0xe5564 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0xe5568 ldr r5, [r4, #0x28] */
/* @0xe556c add r7, r8, #1 */
/* @0xe5570 ldr r6, [r4, #0x4c] */
/* @0xe5574 lsl r11, r8, #4 */
/* @0xe5578 cmp r6, #0 */
/* @0xe557c sub r9, r7, #1 */
/* @0xe5580 ble 0xe5594 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x2c8> */
/* @0xe5584 ldr r3, [r5, #0x18] */
/* @0xe5588 cmp r3, #0 */
/* @0xe558c bne 0xe55cc <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x300> */
/* @0xe5590 b 0xe5590 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x2c4> */
/* @0xe5594 cmp r9, #49 */
/* @0xe5598 ldr r4, [r4, #0x4] */
/* @0xe559c movgt r3, #0 */
/* @0xe55a0 movle r3, #1 */
/* @0xe55a4 cmp r4, #0 */
/* @0xe55a8 moveq r3, #0 */
/* @0xe55ac cmp r3, #0 */
/* @0xe55b0 bne 0xe53c8 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0xe55b4 ldr r0, [sp, #0x24] */
/* @0xe55b8 cmp r0, #0 */
/* @0xe55bc beq 0xe55c4 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x2f8> */
/* @0xe55c0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe55c4 add sp, sp, #52 */
/* @0xe55c8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe55cc ldr r0, [r5, #0x1c] */
/* @0xe55d0 cmp r0, #0 */
/* @0xe55d4 beq 0xe57d0 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x504> */
/* @0xe55d8 ldr r1, [r5] */
/* @0xe55dc bl 0xec144 <_ZN2VM9DebugInfoEP8VMBufferi> */
/* @0xe55e0 ldr r1, [r5, #0x20] */
/* @0xe55e4 add r2, sp, #32 */
/* @0xe55e8 str r10, [sp, #0x20] */
/* @0xe55ec bl 0xec2b8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc> */
/* @0xe55f0 ldr r9, [r5, #0x24] */
/* @0xe55f4 str r10, [sp, #0x2c] */
/* @0xe55f8 cmp r9, #0 */
/* @0xe55fc str r0, [sp, #0x8] */
/* @0xe5600 beq 0xe57c4 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x4f8> */
/* @0xe5604 mov r0, r9 */
/* @0xe5608 bl 0xb6538 <strlen@plt> */
/* @0xe560c ldr r3, [sp, #0x28] */
/* @0xe5610 add r2, r0, #1 */
/* @0xe5614 mov r8, r0 */
/* @0xe5618 cmp r2, r3 */
/* @0xe561c movlt r0, #0 */
/* @0xe5620 blt 0xe568c <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x3c0> */
/* @0xe5624 cmp r3, #0 */
/* @0xe5628 moveq r3, r2 */
/* @0xe562c add r3, r3, r3, lsl #1 */
/* @0xe5630 add r3, r3, r3, lsr #31 */
/* @0xe5634 asr r3, r3, #1 */
/* @0xe5638 cmp r2, r3 */
/* @0xe563c addgt r2, r2, r2, lsl #1 */
/* @0xe5640 addgt r2, r2, r2, lsr #31 */
/* @0xe5644 asrgt r3, r2, #1 */
/* @0xe5648 ldr r2, [sp, #0x24] */
/* @0xe564c str r3, [sp] */
/* @0xe5650 mov r0, r3 */
/* @0xe5654 str r2, [sp, #0x14] */
/* @0xe5658 bl 0xcef4c <_Z7YYAlloci> */
/* @0xe565c ldr r2, [sp, #0x28] */
/* @0xe5660 ldr r1, [sp, #0x14] */
/* @0xe5664 str r0, [sp, #0x24] */
/* @0xe5668 bl 0xb65bc <memcpy@plt> */
/* @0xe566c ldr r0, [sp, #0x14] */
/* @0xe5670 ldr r3, [sp] */
/* @0xe5674 cmp r0, #0 */
/* @0xe5678 str r3, [sp, #0x28] */
/* @0xe567c beq 0xe5688 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x3bc> */
/* @0xe5680 ldr r0, [sp, #0x14] */
/* @0xe5684 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe5688 ldr r0, [sp, #0x2c] */
/* @0xe568c ldr r3, [sp, #0x24] */
/* @0xe5690 mov r1, r9 */
/* @0xe5694 add r0, r3, r0 */
/* @0xe5698 bl 0xb65a4 <strcpy@plt> */
/* @0xe569c ldr r3, [sp, #0x2c] */
/* @0xe56a0 add r8, r8, r3 */
/* @0xe56a4 str r8, [sp, #0x2c] */
/* @0xe56a8 mvn r2, r8 */
/* @0xe56ac ldr r3, [sp, #0x28] */
/* @0xe56b0 add r2, r3, r2 */
/* @0xe56b4 cmp r2, #1 */
/* @0xe56b8 bgt 0xe5718 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x44c> */
/* @0xe56bc cmp r3, #0 */
/* @0xe56c0 add r8, r8, #2 */
/* @0xe56c4 addne r3, r3, r3, lsl #1 */
/* @0xe56c8 moveq r9, #3 */
/* @0xe56cc addne r3, r3, r3, lsr #31 */
/* @0xe56d0 asrne r9, r3, #1 */
/* @0xe56d4 cmp r8, r9 */
/* @0xe56d8 addgt r8, r8, r8, lsl #1 */
/* @0xe56dc addgt r8, r8, r8, lsr #31 */
/* @0xe56e0 asrgt r9, r8, #1 */
/* @0xe56e4 ldr r8, [sp, #0x24] */
/* @0xe56e8 mov r0, r9 */
/* @0xe56ec bl 0xcef4c <_Z7YYAlloci> */
/* @0xe56f0 ldr r2, [sp, #0x28] */
/* @0xe56f4 mov r1, r8 */
/* @0xe56f8 str r0, [sp, #0x24] */
/* @0xe56fc bl 0xb65bc <memcpy@plt> */
/* @0xe5700 cmp r8, #0 */
/* @0xe5704 str r9, [sp, #0x28] */
/* @0xe5708 beq 0xe5714 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x448> */
/* @0xe570c mov r0, r8 */
/* @0xe5710 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe5714 ldr r8, [sp, #0x2c] */
/* @0xe5718 ldr r0, [sp, #0x18] */
/* @0xe571c ldr r3, [sp, #0x24] */
/* @0xe5720 ldr r1, [sp, #0x8] */
/* @0xe5724 ldrh r2, [r0] */
/* @0xe5728 add r0, sp, #36 */
/* @0xe572c strh r2, [r3, r8] */
/* @0xe5730 ldr r3, [sp, #0x2c] */
/* @0xe5734 add r3, r3, #1 */
/* @0xe5738 str r3, [sp, #0x2c] */
/* @0xe573c bl 0xd58c4 <_ZN12YYStrBuilderlsEi> */
/* @0xe5740 ldr r2, [sp, #0x4] */
/* @0xe5744 ldr r3, [r2] */
/* @0xe5748 ldr r2, [sp, #0x2c] */
/* @0xe574c ldr r3, [r3, #0x4] */
/* @0xe5750 cmp r2, #0 */
/* @0xe5754 addeq r1, sp, #44 */
/* @0xe5758 ldrne r1, [sp, #0x24] */
/* @0xe575c ldr r0, [r3, #0x4] */
/* @0xe5760 str r10, [sp, #0x2c] */
/* @0xe5764 add r0, r0, r11 */
/* @0xe5768 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0xe576c ldr r0, [sp, #0x20] */
/* @0xe5770 cmp r0, #0 */
/* @0xe5774 beq 0xe577c <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x4b0> */
/* @0xe5778 bl 0xb655c <free@plt> */
/* @0xe577c ldr r3, [r5, #0xc] */
/* @0xe5780 sub r6, r6, #1 */
/* @0xe5784 ldr r2, [r4, #0x40] */
/* @0xe5788 add r7, r7, #1 */
/* @0xe578c ldr r5, [r4, #0x8] */
/* @0xe5790 add r11, r11, #16 */
/* @0xe5794 rsb r3, r3, r2 */
/* @0xe5798 add r5, r5, r3 */
/* @0xe579c b 0xe5578 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x2ac> */
/* @0xe57a0 ldr r0, [sp, #0x4] */
/* @0xe57a4 add r8, r9, #1 */
/* @0xe57a8 ldr r1, [r4, #0x34] */
/* @0xe57ac ldr r3, [r0] */
/* @0xe57b0 ldr r3, [r3, #0x4] */
/* @0xe57b4 ldr r0, [r3, #0x4] */
/* @0xe57b8 add r0, r0, r9, lsl #4 */
/* @0xe57bc bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0xe57c0 b 0xe5568 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x29c> */
/* @0xe57c4 mov r8, r9 */
/* @0xe57c8 mvn r2, #0 */
/* @0xe57cc b 0xe56ac <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x3e0> */
/* @0xe57d0 ldr r0, [sp, #0x4] */
/* @0xe57d4 ldr r1, [r5, #0x24] */
/* @0xe57d8 ldr r3, [r0] */
/* @0xe57dc ldr r3, [r3, #0x4] */
/* @0xe57e0 ldr r0, [r3, #0x4] */
/* @0xe57e4 add r0, r0, r11 */
/* @0xe57e8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0xe57ec b 0xe577c <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x4b0> */
/* @0xe57f0 mov r8, #16 */
/* @0xe57f4 mov r7, #1 */
/* @0xe57f8 b 0xe5310 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0xe57fc eorseq r8, r0, r12, asr #17 */
/* @0xe5800 eoreq r11, r4, r0, lsl #26 */
/* @0xe5804 eoreq sp, r4, r4, lsr #8 */
/* @0xe5808 .word 0x0024d8f0 */
/* @0xe580c eoreq sp, r4, r4, ror #17 */

/* ── FUNC 0xe5810 · DoMul(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=2468 · insn=617 */
/* @0xe5810 ubfx r2, r0, #0x8, #0x4 */
/* @0xe5814 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xe5818 cmp r2, #1 */
/* @0xe581c lsr r7, r0, #16 */
/* @0xe5820 sub sp, sp, #72 */
/* @0xe5824 mov r8, r1 */
/* @0xe5828 uxtb r5, r7 */
/* @0xe582c beq 0xe5dd0 <_Z5DoMuljPhPKhP6VMExec+0x5c0> */
/* @0xe5830 and r2, r5, #15 */
/* @0xe5834 cmp r2, #6 */
/* @0xe5838 addls pc, pc, r2, lsl #2 */
/* @0xe583c b 0xe6168 <_Z5DoMuljPhPKhP6VMExec+0x958> */
/* @0xe5840 b 0xe5bdc <_Z5DoMuljPhPKhP6VMExec+0x3cc> */
/* @0xe5844 b 0xe585c <_Z5DoMuljPhPKhP6VMExec+0x4c> */
/* @0xe5848 b 0xe585c <_Z5DoMuljPhPKhP6VMExec+0x4c> */
/* @0xe584c b 0xe5bdc <_Z5DoMuljPhPKhP6VMExec+0x3cc> */
/* @0xe5850 b 0xe585c <_Z5DoMuljPhPKhP6VMExec+0x4c> */
/* @0xe5854 b 0xe5b94 <_Z5DoMuljPhPKhP6VMExec+0x384> */
/* @0xe5858 b 0xe585c <_Z5DoMuljPhPKhP6VMExec+0x4c> */
/* @0xe585c add r9, r1, #4 */
/* @0xe5860 mov r7, r5 */
/* @0xe5864 asr r2, r7, #4 */
/* @0xe5868 cmp r2, #6 */
/* @0xe586c addls pc, pc, r2, lsl #2 */
/* @0xe5870 b 0xe6174 <_Z5DoMuljPhPKhP6VMExec+0x964> */
/* @0xe5874 b 0xe5b8c <_Z5DoMuljPhPKhP6VMExec+0x37c> */
/* @0xe5878 b 0xe5890 <_Z5DoMuljPhPKhP6VMExec+0x80> */
/* @0xe587c b 0xe5890 <_Z5DoMuljPhPKhP6VMExec+0x80> */
/* @0xe5880 b 0xe5b8c <_Z5DoMuljPhPKhP6VMExec+0x37c> */
/* @0xe5884 b 0xe5890 <_Z5DoMuljPhPKhP6VMExec+0x80> */
/* @0xe5888 b 0xe5b44 <_Z5DoMuljPhPKhP6VMExec+0x334> */
/* @0xe588c b 0xe5890 <_Z5DoMuljPhPKhP6VMExec+0x80> */
/* @0xe5890 add r4, r9, #4 */
/* @0xe5894 cmp r5, #102 */
/* @0xe5898 addls pc, pc, r5, lsl #2 */
/* @0xe589c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58a0 b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0xe58a4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58a8 b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0xe58ac b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0xe58b0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58b4 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0xe58b8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58bc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58c0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58c4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58c8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58cc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58d0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58d4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58d8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58dc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58e0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58e4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58e8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58ec b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58f0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58f4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58f8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58fc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5900 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5904 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5908 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe590c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5910 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5914 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5918 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe591c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5920 b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0xe5924 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5928 b 0xe5a3c <_Z5DoMuljPhPKhP6VMExec+0x22c> */
/* @0xe592c b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0xe5930 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5934 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0xe5938 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe593c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5940 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5944 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5948 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe594c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5950 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5954 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5958 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe595c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5960 b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0xe5964 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5968 b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0xe596c b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0xe5970 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5974 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0xe5978 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe597c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5980 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5984 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5988 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe598c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5990 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5994 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5998 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe599c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59a0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59a4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59a8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59ac b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59b0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59b4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59b8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59bc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59c0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59c4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59c8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59cc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59d0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59d4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59d8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59dc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59e0 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0xe59e4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59e8 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0xe59ec b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0xe59f0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59f4 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0xe59f8 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0xe59fc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a00 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a04 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a08 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a0c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a10 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a14 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a18 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a1c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a20 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a24 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a28 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a2c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a30 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a34 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0xe5a38 b 0xe5a3c <_Z5DoMuljPhPKhP6VMExec+0x22c> */
/* @0xe5a3c sub r4, r4, #4 */
/* @0xe5a40 mov r6, #0 */
/* @0xe5a44 mov r5, r4 */
/* @0xe5a48 cmp r7, #51 */
/* @0xe5a4c addls pc, pc, r7, lsl #2 */
/* @0xe5a50 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a54 b 0xe5ca8 <_Z5DoMuljPhPKhP6VMExec+0x498> */
/* @0xe5a58 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a5c b 0xe5c8c <_Z5DoMuljPhPKhP6VMExec+0x47c> */
/* @0xe5a60 b 0xe5d98 <_Z5DoMuljPhPKhP6VMExec+0x588> */
/* @0xe5a64 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a68 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a6c b 0xe5cf4 <_Z5DoMuljPhPKhP6VMExec+0x4e4> */
/* @0xe5a70 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a74 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a78 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a7c b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a80 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a84 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a88 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a8c b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a90 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a94 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a98 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a9c b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5aa0 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5aa4 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5aa8 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5aac b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5ab0 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5ab4 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5ab8 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5abc b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5ac0 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5ac4 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5ac8 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5acc b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5ad0 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5ad4 b 0xe5cd8 <_Z5DoMuljPhPKhP6VMExec+0x4c8> */
/* @0xe5ad8 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5adc b 0xe5cc0 <_Z5DoMuljPhPKhP6VMExec+0x4b0> */
/* @0xe5ae0 b 0xe5c64 <_Z5DoMuljPhPKhP6VMExec+0x454> */
/* @0xe5ae4 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5ae8 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5aec b 0xe5cf4 <_Z5DoMuljPhPKhP6VMExec+0x4e4> */
/* @0xe5af0 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5af4 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5af8 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5afc b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5b00 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5b04 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5b08 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5b0c b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5b10 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5b14 b 0xe5c44 <_Z5DoMuljPhPKhP6VMExec+0x434> */
/* @0xe5b18 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5b1c b 0xe5c30 <_Z5DoMuljPhPKhP6VMExec+0x420> */
/* @0xe5b20 b 0xe5bf4 <_Z5DoMuljPhPKhP6VMExec+0x3e4> */
/* @0xe5b24 sub r6, r4, #16 */
/* @0xe5b28 mov r5, r6 */
/* @0xe5b2c mov r4, r6 */
/* @0xe5b30 b 0xe5a48 <_Z5DoMuljPhPKhP6VMExec+0x238> */
/* @0xe5b34 sub r4, r4, #8 */
/* @0xe5b38 mov r6, #0 */
/* @0xe5b3c mov r5, r4 */
/* @0xe5b40 b 0xe5a48 <_Z5DoMuljPhPKhP6VMExec+0x238> */
/* @0xe5b44 ldr r2, [r9, #0xc] */
/* @0xe5b48 cmp r2, #13 */
/* @0xe5b4c addls pc, pc, r2, lsl #2 */
/* @0xe5b50 b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0xe5b54 b 0xe5eec <_Z5DoMuljPhPKhP6VMExec+0x6dc> */
/* @0xe5b58 b 0xe5ee0 <_Z5DoMuljPhPKhP6VMExec+0x6d0> */
/* @0xe5b5c b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0xe5b60 b 0xe5ec4 <_Z5DoMuljPhPKhP6VMExec+0x6b4> */
/* @0xe5b64 b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0xe5b68 b 0xe5ea8 <_Z5DoMuljPhPKhP6VMExec+0x698> */
/* @0xe5b6c b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0xe5b70 b 0xe5e9c <_Z5DoMuljPhPKhP6VMExec+0x68c> */
/* @0xe5b74 b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0xe5b78 b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0xe5b7c b 0xe5e8c <_Z5DoMuljPhPKhP6VMExec+0x67c> */
/* @0xe5b80 b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0xe5b84 b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0xe5b88 b 0xe5eec <_Z5DoMuljPhPKhP6VMExec+0x6dc> */
/* @0xe5b8c add r4, r9, #8 */
/* @0xe5b90 b 0xe5894 <_Z5DoMuljPhPKhP6VMExec+0x84> */
/* @0xe5b94 ldr r2, [r1, #0xc] */
/* @0xe5b98 cmp r2, #13 */
/* @0xe5b9c addls pc, pc, r2, lsl #2 */
/* @0xe5ba0 b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0xe5ba4 b 0xe6028 <_Z5DoMuljPhPKhP6VMExec+0x818> */
/* @0xe5ba8 b 0xe601c <_Z5DoMuljPhPKhP6VMExec+0x80c> */
/* @0xe5bac b 0xe5ffc <_Z5DoMuljPhPKhP6VMExec+0x7ec> */
/* @0xe5bb0 b 0xe6050 <_Z5DoMuljPhPKhP6VMExec+0x840> */
/* @0xe5bb4 b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0xe5bb8 b 0xe6030 <_Z5DoMuljPhPKhP6VMExec+0x820> */
/* @0xe5bbc b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0xe5bc0 b 0xe5ff0 <_Z5DoMuljPhPKhP6VMExec+0x7e0> */
/* @0xe5bc4 b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0xe5bc8 b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0xe5bcc b 0xe5fe0 <_Z5DoMuljPhPKhP6VMExec+0x7d0> */
/* @0xe5bd0 b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0xe5bd4 b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0xe5bd8 b 0xe6028 <_Z5DoMuljPhPKhP6VMExec+0x818> */
/* @0xe5bdc add r9, r1, #8 */
/* @0xe5be0 mov r7, r5 */
/* @0xe5be4 b 0xe5864 <_Z5DoMuljPhPKhP6VMExec+0x54> */
/* @0xe5be8 mov r5, #0 */
/* @0xe5bec mov r6, r5 */
/* @0xe5bf0 b 0xe5a48 <_Z5DoMuljPhPKhP6VMExec+0x238> */
/* @0xe5bf4 ldr r1, [r8, #0x4] */
/* @0xe5bf8 mov r12, #10 */
/* @0xe5bfc ldr r2, [r9] */
/* @0xe5c00 ldr r3, [r8] */
/* @0xe5c04 ldr r0, [r9, #0x4] */
/* @0xe5c08 mul r1, r2, r1 */
/* @0xe5c0c mla r1, r3, r0, r1 */
/* @0xe5c10 umull r2, r3, r2, r3 */
/* @0xe5c14 add r3, r1, r3 */
/* @0xe5c18 strd r2, r3, [r5] */
/* @0xe5c1c cmp r6, #0 */
/* @0xe5c20 strne r12, [r6, #0xc] */
/* @0xe5c24 mov r0, r4 */
/* @0xe5c28 add sp, sp, #72 */
/* @0xe5c2c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xe5c30 ldr r3, [r8] */
/* @0xe5c34 mov r12, #10 */
/* @0xe5c38 ldr r2, [r9] */
/* @0xe5c3c asr r1, r3, #31 */
/* @0xe5c40 b 0xe5c04 <_Z5DoMuljPhPKhP6VMExec+0x3f4> */
/* @0xe5c44 ldrd r0, r1, [r9] */
/* @0xe5c48 bl 0x319164 <__floatdidf> */
/* @0xe5c4c vldr d7, [r8] */
/* @0xe5c50 mov r12, #0 */
/* @0xe5c54 vmov d6, r0, r1 */
/* @0xe5c58 vmul.f64 d7, d6, d7 */
/* @0xe5c5c vstr d7, [r5] */
/* @0xe5c60 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* @0xe5c64 ldr r3, [r9] */
/* @0xe5c68 mov r12, #10 */
/* @0xe5c6c ldm r8, {r2, r7} */
/* @0xe5c70 asr r1, r3, #31 */
/* @0xe5c74 mul r0, r3, r7 */
/* @0xe5c78 mla r1, r2, r1, r0 */
/* @0xe5c7c umull r2, r3, r2, r3 */
/* @0xe5c80 add r3, r1, r3 */
/* @0xe5c84 strd r2, r3, [r5] */
/* @0xe5c88 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* @0xe5c8c vldr s14, [r8] */
/* @0xe5c90 vcvt.f64.s32 d7, s14 */
/* @0xe5c94 vldr d6, [r9] */
/* @0xe5c98 mov r12, #0 */
/* @0xe5c9c vmul.f64 d7, d6, d7 */
/* @0xe5ca0 vstr d7, [r5] */
/* @0xe5ca4 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* @0xe5ca8 vldr d6, [r9] */
/* @0xe5cac vldr d7, [r8] */
/* @0xe5cb0 vmul.f64 d7, d6, d7 */
/* @0xe5cb4 mov r12, #0 */
/* @0xe5cb8 vstr d7, [r5] */
/* @0xe5cbc b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* @0xe5cc0 ldr r3, [r9] */
/* @0xe5cc4 mov r12, #7 */
/* @0xe5cc8 ldr r2, [r8] */
/* @0xe5ccc mul r3, r2, r3 */
/* @0xe5cd0 str r3, [r5] */
/* @0xe5cd4 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* @0xe5cd8 vldr s14, [r9] */
/* @0xe5cdc vcvt.f64.s32 d7, s14 */
/* @0xe5ce0 vldr d6, [r8] */
/* @0xe5ce4 mov r12, #0 */
/* @0xe5ce8 vmul.f64 d7, d7, d6 */
/* @0xe5cec vstr d7, [r5] */
/* @0xe5cf0 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* @0xe5cf4 ldr r10, [r8] */
/* @0xe5cf8 cmp r10, #0 */
/* @0xe5cfc ldrne r8, [r10] */
/* @0xe5d00 moveq r8, r10 */
/* @0xe5d04 asrs r7, r7, #4 */
/* @0xe5d08 beq 0xe60c0 <_Z5DoMuljPhPKhP6VMExec+0x8b0> */
/* @0xe5d0c cmp r7, #2 */
/* @0xe5d10 beq 0xe5ef4 <_Z5DoMuljPhPKhP6VMExec+0x6e4> */
/* @0xe5d14 ldr r1, [pc, #0x460] */
/* @0xe5d18 mov r0, #1 */
/* @0xe5d1c mov r3, r0 */
/* @0xe5d20 movw r2, #0xb54 */
/* @0xe5d24 add r1, pc, r1 */
/* @0xe5d28 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xe5d2c mov r3, #0 */
/* @0xe5d30 mov r9, r0 */
/* @0xe5d34 strb r3, [r0] */
/* @0xe5d38 mov r0, #12 */
/* @0xe5d3c mov r8, #1 */
/* @0xe5d40 bl 0x27c524 <_Znwj> */
/* @0xe5d44 mov r7, r0 */
/* @0xe5d48 mov r0, r9 */
/* @0xe5d4c bl 0xb6538 <strlen@plt> */
/* @0xe5d50 str r0, [r7, #0x8] */
/* @0xe5d54 mov r0, r9 */
/* @0xe5d58 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xe5d5c stm r7, {r0, r8} */
/* @0xe5d60 mov r0, r9 */
/* @0xe5d64 str r7, [r5] */
/* @0xe5d68 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xe5d6c cmp r10, #0 */
/* @0xe5d70 beq 0xe5d90 <_Z5DoMuljPhPKhP6VMExec+0x580> */
/* @0xe5d74 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe5d78 ldr r5, [r10, #0x4] */
/* @0xe5d7c sub r5, r5, #1 */
/* @0xe5d80 str r5, [r10, #0x4] */
/* @0xe5d84 cmp r5, #0 */
/* @0xe5d88 beq 0xe60d0 <_Z5DoMuljPhPKhP6VMExec+0x8c0> */
/* @0xe5d8c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe5d90 mov r12, #1 */
/* @0xe5d94 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* @0xe5d98 ldrd r0, r1, [r8] */
/* @0xe5d9c bl 0x319164 <__floatdidf> */
/* @0xe5da0 vldr d7, [r9] */
/* @0xe5da4 mov r12, #0 */
/* @0xe5da8 vmov d5, r0, r1 */
/* @0xe5dac vmul.f64 d7, d7, d5 */
/* @0xe5db0 vstr d7, [r5] */
/* @0xe5db4 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* @0xe5db8 ldr r1, [pc, #0x3c0] */
/* @0xe5dbc mov r0, r3 */
/* @0xe5dc0 add r1, pc, r1 */
/* @0xe5dc4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe5dc8 mov r12, #0 */
/* @0xe5dcc b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* @0xe5dd0 add r6, sp, #24 */
/* @0xe5dd4 mov r2, r1 */
/* @0xe5dd8 and r1, r5, #15 */
/* @0xe5ddc add r7, sp, #8 */
/* @0xe5de0 mov r0, r6 */
/* @0xe5de4 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe5de8 lsr r1, r5, #4 */
/* @0xe5dec mov r2, r0 */
/* @0xe5df0 mov r0, r7 */
/* @0xe5df4 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe5df8 ldr r3, [sp, #0x14] */
/* @0xe5dfc mvn r12, #-16777216 */
/* @0xe5e00 and r3, r3, r12 */
/* @0xe5e04 cmp r3, r12 */
/* @0xe5e08 mov r4, r0 */
/* @0xe5e0c beq 0xe6128 <_Z5DoMuljPhPKhP6VMExec+0x918> */
/* @0xe5e10 ldr r3, [sp, #0x24] */
/* @0xe5e14 bic r3, r3, #-16777216 */
/* @0xe5e18 cmp r3, r12 */
/* @0xe5e1c beq 0xe60ac <_Z5DoMuljPhPKhP6VMExec+0x89c> */
/* @0xe5e20 add r5, sp, #40 */
/* @0xe5e24 mov r1, r7 */
/* @0xe5e28 mov r2, #0 */
/* @0xe5e2c mov r3, #0 */
/* @0xe5e30 mov r0, r5 */
/* @0xe5e34 str r12, [sp, #0x34] */
/* @0xe5e38 str r12, [sp, #0x44] */
/* @0xe5e3c mov r12, #0 */
/* @0xe5e40 strd r2, r3, [sp, #40] */
/* @0xe5e44 strd r2, r3, [sp, #56] */
/* @0xe5e48 str r12, [sp, #0x30] */
/* @0xe5e4c str r12, [sp, #0x40] */
/* @0xe5e50 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xe5e54 cmp r0, #1 */
/* @0xe5e58 beq 0xe613c <_Z5DoMuljPhPKhP6VMExec+0x92c> */
/* @0xe5e5c cmp r0, #0 */
/* @0xe5e60 beq 0xe5f48 <_Z5DoMuljPhPKhP6VMExec+0x738> */
/* @0xe5e64 ldr r3, [sp, #0x34] */
/* @0xe5e68 sub r3, r3, #1 */
/* @0xe5e6c bic r3, r3, #-16777216 */
/* @0xe5e70 bic r3, r3, #3 */
/* @0xe5e74 cmp r3, #0 */
/* @0xe5e78 bne 0xe5c24 <_Z5DoMuljPhPKhP6VMExec+0x414> */
/* @0xe5e7c mov r0, r5 */
/* @0xe5e80 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe5e84 mov r0, r4 */
/* @0xe5e88 b 0xe5c28 <_Z5DoMuljPhPKhP6VMExec+0x418> */
/* @0xe5e8c and r7, r7, #15 */
/* @0xe5e90 orr r7, r7, #48 */
/* @0xe5e94 add r4, r9, #16 */
/* @0xe5e98 b 0xe5894 <_Z5DoMuljPhPKhP6VMExec+0x84> */
/* @0xe5e9c and r7, r7, #15 */
/* @0xe5ea0 orr r7, r7, #32 */
/* @0xe5ea4 b 0xe5e94 <_Z5DoMuljPhPKhP6VMExec+0x684> */
/* @0xe5ea8 ldr r1, [pc, #0x2d4] */
/* @0xe5eac mov r0, r3 */
/* @0xe5eb0 str r3, [sp, #0x4] */
/* @0xe5eb4 add r1, pc, r1 */
/* @0xe5eb8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe5ebc ldr r3, [sp, #0x4] */
/* @0xe5ec0 b 0xe5e94 <_Z5DoMuljPhPKhP6VMExec+0x684> */
/* @0xe5ec4 ldr r1, [pc, #0x2bc] */
/* @0xe5ec8 mov r0, r3 */
/* @0xe5ecc str r3, [sp, #0x4] */
/* @0xe5ed0 add r1, pc, r1 */
/* @0xe5ed4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe5ed8 ldr r3, [sp, #0x4] */
/* @0xe5edc b 0xe5e94 <_Z5DoMuljPhPKhP6VMExec+0x684> */
/* @0xe5ee0 and r7, r7, #15 */
/* @0xe5ee4 orr r7, r7, #96 */
/* @0xe5ee8 b 0xe5e94 <_Z5DoMuljPhPKhP6VMExec+0x684> */
/* @0xe5eec and r7, r7, #15 */
/* @0xe5ef0 b 0xe5e94 <_Z5DoMuljPhPKhP6VMExec+0x684> */
/* @0xe5ef4 ldr r7, [r9] */
/* @0xe5ef8 mov r0, r8 */
/* @0xe5efc bl 0xb6538 <strlen@plt> */
/* @0xe5f00 ldr r1, [pc, #0x284] */
/* @0xe5f04 mov r3, #1 */
/* @0xe5f08 movw r2, #0xb54 */
/* @0xe5f0c add r1, pc, r1 */
/* @0xe5f10 mul r0, r7, r0 */
/* @0xe5f14 add r0, r0, r3 */
/* @0xe5f18 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xe5f1c cmp r7, #0 */
/* @0xe5f20 mov r3, #0 */
/* @0xe5f24 mov r9, r0 */
/* @0xe5f28 strb r3, [r0] */
/* @0xe5f2c ble 0xe5d38 <_Z5DoMuljPhPKhP6VMExec+0x528> */
/* @0xe5f30 mov r0, r9 */
/* @0xe5f34 mov r1, r8 */
/* @0xe5f38 bl 0xb6628 <strcat@plt> */
/* @0xe5f3c subs r7, r7, #1 */
/* @0xe5f40 bne 0xe5f30 <_Z5DoMuljPhPKhP6VMExec+0x720> */
/* @0xe5f44 b 0xe5d38 <_Z5DoMuljPhPKhP6VMExec+0x528> */
/* @0xe5f48 add r7, sp, #56 */
/* @0xe5f4c mov r1, r6 */
/* @0xe5f50 mov r0, r7 */
/* @0xe5f54 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xe5f58 cmp r0, #1 */
/* @0xe5f5c beq 0xe6158 <_Z5DoMuljPhPKhP6VMExec+0x948> */
/* @0xe5f60 cmp r0, #0 */
/* @0xe5f64 bne 0xe5e64 <_Z5DoMuljPhPKhP6VMExec+0x654> */
/* @0xe5f68 str r0, [r4, #-0x4] */
/* @0xe5f6c sub r6, r4, #16 */
/* @0xe5f70 vldr d6, [sp, #40] */
/* @0xe5f74 vldr d7, [sp, #56] */
/* @0xe5f78 vmul.f64 d5, d6, d7 */
/* @0xe5f7c ldr r1, [sp, #0x34] */
/* @0xe5f80 sub r1, r1, #1 */
/* @0xe5f84 bic r1, r1, #-16777216 */
/* @0xe5f88 bic r1, r1, #3 */
/* @0xe5f8c cmp r1, #0 */
/* @0xe5f90 vmov r2, r3, d5 */
/* @0xe5f94 vstr s10, [r4, #-16] */
/* @0xe5f98 str r3, [r4, #-0xc] */
/* @0xe5f9c beq 0xe614c <_Z5DoMuljPhPKhP6VMExec+0x93c> */
/* @0xe5fa0 ldr r1, [sp, #0x44] */
/* @0xe5fa4 mov r3, #0 */
/* @0xe5fa8 str r3, [sp, #0x30] */
/* @0xe5fac mov r2, #5 */
/* @0xe5fb0 sub r1, r1, #1 */
/* @0xe5fb4 str r3, [sp, #0x28] */
/* @0xe5fb8 bic r3, r1, #-16777216 */
/* @0xe5fbc str r2, [sp, #0x34] */
/* @0xe5fc0 bic r3, r3, #3 */
/* @0xe5fc4 cmp r3, #0 */
/* @0xe5fc8 movne r0, r6 */
/* @0xe5fcc bne 0xe5c28 <_Z5DoMuljPhPKhP6VMExec+0x418> */
/* @0xe5fd0 mov r0, r7 */
/* @0xe5fd4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe5fd8 mov r0, r6 */
/* @0xe5fdc b 0xe5c28 <_Z5DoMuljPhPKhP6VMExec+0x418> */
/* @0xe5fe0 and r7, r7, #240 */
/* @0xe5fe4 orr r7, r7, #3 */
/* @0xe5fe8 add r9, r8, #16 */
/* @0xe5fec b 0xe5864 <_Z5DoMuljPhPKhP6VMExec+0x54> */
/* @0xe5ff0 and r7, r7, #240 */
/* @0xe5ff4 orr r7, r7, #2 */
/* @0xe5ff8 b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* @0xe5ffc ldr r1, [pc, #0x18c] */
/* @0xe6000 mov r0, r3 */
/* @0xe6004 str r3, [sp, #0x4] */
/* @0xe6008 mov r7, r5 */
/* @0xe600c add r1, pc, r1 */
/* @0xe6010 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe6014 ldr r3, [sp, #0x4] */
/* @0xe6018 b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* @0xe601c and r7, r7, #240 */
/* @0xe6020 orr r7, r7, #6 */
/* @0xe6024 b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* @0xe6028 and r7, r5, #240 */
/* @0xe602c b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* @0xe6030 ldr r1, [pc, #0x15c] */
/* @0xe6034 mov r0, r3 */
/* @0xe6038 str r3, [sp, #0x4] */
/* @0xe603c mov r7, r5 */
/* @0xe6040 add r1, pc, r1 */
/* @0xe6044 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe6048 ldr r3, [sp, #0x4] */
/* @0xe604c b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* @0xe6050 ldr r1, [pc, #0x140] */
/* @0xe6054 mov r0, r3 */
/* @0xe6058 str r3, [sp, #0x4] */
/* @0xe605c mov r7, r5 */
/* @0xe6060 add r1, pc, r1 */
/* @0xe6064 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe6068 ldr r3, [sp, #0x4] */
/* @0xe606c b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* @0xe6070 ldr r1, [pc, #0x124] */
/* @0xe6074 mov r0, r3 */
/* @0xe6078 str r3, [sp, #0x4] */
/* @0xe607c add r1, pc, r1 */
/* @0xe6080 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe6084 ldr r3, [sp, #0x4] */
/* @0xe6088 b 0xe5e94 <_Z5DoMuljPhPKhP6VMExec+0x684> */
/* @0xe608c ldr r1, [pc, #0x10c] */
/* @0xe6090 mov r0, r3 */
/* @0xe6094 str r3, [sp, #0x4] */
/* @0xe6098 mov r7, r5 */
/* @0xe609c add r1, pc, r1 */
/* @0xe60a0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe60a4 ldr r3, [sp, #0x4] */
/* @0xe60a8 b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* @0xe60ac ldr r0, [pc, #0xf0] */
/* @0xe60b0 add r0, pc, r0 */
/* @0xe60b4 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe60b8 mov r0, r4 */
/* @0xe60bc b 0xe5c28 <_Z5DoMuljPhPKhP6VMExec+0x418> */
/* @0xe60c0 vldr d7, [r9] */
/* @0xe60c4 vcvt.s32.f64 s11, d7 */
/* @0xe60c8 vmov r7, s11 */
/* @0xe60cc b 0xe5ef8 <_Z5DoMuljPhPKhP6VMExec+0x6e8> */
/* @0xe60d0 ldr r0, [r10] */
/* @0xe60d4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe60d8 str r5, [r10] */
/* @0xe60dc str r5, [r10, #0x8] */
/* @0xe60e0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe60e4 ldr r5, [r10, #0x4] */
/* @0xe60e8 sub r5, r5, #1 */
/* @0xe60ec str r5, [r10, #0x4] */
/* @0xe60f0 cmp r5, #0 */
/* @0xe60f4 bne 0xe6118 <_Z5DoMuljPhPKhP6VMExec+0x908> */
/* @0xe60f8 ldr r0, [r10] */
/* @0xe60fc bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe6100 mov r0, r10 */
/* @0xe6104 str r5, [r10] */
/* @0xe6108 str r5, [r10, #0x8] */
/* @0xe610c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xe6110 mov r0, r10 */
/* @0xe6114 bl 0x27d1d0 <_ZdlPv> */
/* @0xe6118 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe611c mov r0, r10 */
/* @0xe6120 bl 0x27d1d0 <_ZdlPv> */
/* @0xe6124 b 0xe5d8c <_Z5DoMuljPhPKhP6VMExec+0x57c> */
/* @0xe6128 ldr r0, [pc, #0x78] */
/* @0xe612c add r0, pc, r0 */
/* @0xe6130 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe6134 mov r0, r4 */
/* @0xe6138 b 0xe5c28 <_Z5DoMuljPhPKhP6VMExec+0x418> */
/* @0xe613c ldr r0, [pc, #0x68] */
/* @0xe6140 add r0, pc, r0 */
/* @0xe6144 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe6148 b 0xe5e64 <_Z5DoMuljPhPKhP6VMExec+0x654> */
/* @0xe614c mov r0, r5 */
/* @0xe6150 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe6154 b 0xe5fa0 <_Z5DoMuljPhPKhP6VMExec+0x790> */
/* @0xe6158 ldr r0, [pc, #0x50] */
/* @0xe615c add r0, pc, r0 */
/* @0xe6160 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe6164 b 0xe5e64 <_Z5DoMuljPhPKhP6VMExec+0x654> */
/* @0xe6168 mov r7, r5 */
/* @0xe616c mov r9, r1 */
/* @0xe6170 b 0xe5864 <_Z5DoMuljPhPKhP6VMExec+0x54> */
/* @0xe6174 mov r4, r9 */
/* @0xe6178 b 0xe5894 <_Z5DoMuljPhPKhP6VMExec+0x84> */
/* @0xe617c eoreq r12, r4, r8, asr r10 */
/* @0xe6180 eoreq lr, r4, r0, asr #15 */
/* @0xe6184 mlaeq r4, r0, r6, lr */
/* @0xe6188 eoreq lr, r4, r0, ror #12 */
/* @0xe618c eoreq r12, r4, r0, ror r8 */
/* @0xe6190 eoreq lr, r4, r8, asr #10 */
/* @0xe6194 eoreq lr, r4, r4, lsl #10 */
/* @0xe6198 .word 0x0024e4d0 */
/* @0xe619c eoreq lr, r4, r12, ror #9 */
/* @0xe61a0 eoreq lr, r4, r12, asr #9 */
/* @0xe61a4 eoreq lr, r4, r8, asr r4 */
/* @0xe61a8 .word 0x0024e3dc */
/* @0xe61ac .word 0x0024d0d4 */
/* @0xe61b0 .word 0x0024d0f8 */

/* ── FUNC 0xe61b4 · DoPopNull(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=432 · insn=108 */
/* @0xe61b4 push {r4, r5, r6, lr} */
/* @0xe61b8 mov r4, r1 */
/* @0xe61bc lsr r1, r0, #24 */
/* @0xe61c0 sub sp, sp, #8 */
/* @0xe61c4 cmp r1, #255 */
/* @0xe61c8 mov r5, r2 */
/* @0xe61cc lsr r1, r0, #16 */
/* @0xe61d0 beq 0xe6288 <_Z9DoPopNulljPhPKhP6VMExec+0xd4> */
/* @0xe61d4 and r12, r1, #15 */
/* @0xe61d8 cmp r12, #6 */
/* @0xe61dc addls pc, pc, r12, lsl #2 */
/* @0xe61e0 b 0xe6358 <_Z9DoPopNulljPhPKhP6VMExec+0x1a4> */
/* @0xe61e4 b 0xe6234 <_Z9DoPopNulljPhPKhP6VMExec+0x80> */
/* @0xe61e8 b 0xe6228 <_Z9DoPopNulljPhPKhP6VMExec+0x74> */
/* @0xe61ec b 0xe6228 <_Z9DoPopNulljPhPKhP6VMExec+0x74> */
/* @0xe61f0 b 0xe6234 <_Z9DoPopNulljPhPKhP6VMExec+0x80> */
/* @0xe61f4 b 0xe6228 <_Z9DoPopNulljPhPKhP6VMExec+0x74> */
/* @0xe61f8 b 0xe6240 <_Z9DoPopNulljPhPKhP6VMExec+0x8c> */
/* @0xe61fc b 0xe6200 <_Z9DoPopNulljPhPKhP6VMExec+0x4c> */
/* @0xe6200 ldr r5, [r4] */
/* @0xe6204 cmp r5, #0 */
/* @0xe6208 beq 0xe6228 <_Z9DoPopNulljPhPKhP6VMExec+0x74> */
/* @0xe620c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe6210 ldr r6, [r5, #0x4] */
/* @0xe6214 sub r6, r6, #1 */
/* @0xe6218 str r6, [r5, #0x4] */
/* @0xe621c cmp r6, #0 */
/* @0xe6220 beq 0xe62b4 <_Z9DoPopNulljPhPKhP6VMExec+0x100> */
/* @0xe6224 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe6228 add r0, r4, #4 */
/* @0xe622c add sp, sp, #8 */
/* @0xe6230 pop {r4, r5, r6, pc} */
/* @0xe6234 add r0, r4, #8 */
/* @0xe6238 add sp, sp, #8 */
/* @0xe623c pop {r4, r5, r6, pc} */
/* @0xe6240 ldr r3, [r4, #0xc] */
/* @0xe6244 mvn r2, #-16777216 */
/* @0xe6248 and r1, r3, r2 */
/* @0xe624c cmp r1, r2 */
/* @0xe6250 beq 0xe62ec <_Z9DoPopNulljPhPKhP6VMExec+0x138> */
/* @0xe6254 sub r3, r3, #1 */
/* @0xe6258 bic r3, r3, #-16777216 */
/* @0xe625c bic r3, r3, #3 */
/* @0xe6260 cmp r3, #0 */
/* @0xe6264 beq 0xe62a8 <_Z9DoPopNulljPhPKhP6VMExec+0xf4> */
/* @0xe6268 mov r0, r4 */
/* @0xe626c mov r3, #0 */
/* @0xe6270 mov r2, #5 */
/* @0xe6274 str r3, [r4, #0x8] */
/* @0xe6278 str r2, [r4, #0xc] */
/* @0xe627c str r3, [r0], #16 */
/* @0xe6280 add sp, sp, #8 */
/* @0xe6284 pop {r4, r5, r6, pc} */
/* @0xe6288 str r3, [sp] */
/* @0xe628c mov r12, #1 */
/* @0xe6290 uxtb r1, r1 */
/* @0xe6294 mov r2, r4 */
/* @0xe6298 mov r3, r5 */
/* @0xe629c str r12, [sp, #0x4] */
/* @0xe62a0 bl 0xd8434 <_Z7DoBreakjhPhPKhP6VMExecb> */
/* @0xe62a4 b 0xe622c <_Z9DoPopNulljPhPKhP6VMExec+0x78> */
/* @0xe62a8 mov r0, r4 */
/* @0xe62ac bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe62b0 b 0xe6268 <_Z9DoPopNulljPhPKhP6VMExec+0xb4> */
/* @0xe62b4 ldr r0, [r5] */
/* @0xe62b8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe62bc str r6, [r5] */
/* @0xe62c0 str r6, [r5, #0x8] */
/* @0xe62c4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe62c8 ldr r6, [r5, #0x4] */
/* @0xe62cc sub r6, r6, #1 */
/* @0xe62d0 str r6, [r5, #0x4] */
/* @0xe62d4 cmp r6, #0 */
/* @0xe62d8 beq 0xe6300 <_Z9DoPopNulljPhPKhP6VMExec+0x14c> */
/* @0xe62dc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe62e0 mov r0, r5 */
/* @0xe62e4 bl 0x27d1d0 <_ZdlPv> */
/* @0xe62e8 b 0xe6224 <_Z9DoPopNulljPhPKhP6VMExec+0x70> */
/* @0xe62ec ldr r0, [pc, #0x6c] */
/* @0xe62f0 add r0, pc, r0 */
/* @0xe62f4 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe62f8 ldr r3, [r4, #0xc] */
/* @0xe62fc b 0xe6254 <_Z9DoPopNulljPhPKhP6VMExec+0xa0> */
/* @0xe6300 ldr r0, [r5] */
/* @0xe6304 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe6308 str r6, [r5] */
/* @0xe630c str r6, [r5, #0x8] */
/* @0xe6310 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe6314 ldr r6, [r5, #0x4] */
/* @0xe6318 sub r6, r6, #1 */
/* @0xe631c str r6, [r5, #0x4] */
/* @0xe6320 cmp r6, #0 */
/* @0xe6324 bne 0xe6348 <_Z9DoPopNulljPhPKhP6VMExec+0x194> */
/* @0xe6328 ldr r0, [r5] */
/* @0xe632c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe6330 mov r0, r5 */
/* @0xe6334 str r6, [r5] */
/* @0xe6338 str r6, [r5, #0x8] */
/* @0xe633c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xe6340 mov r0, r5 */
/* @0xe6344 bl 0x27d1d0 <_ZdlPv> */
/* @0xe6348 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe634c mov r0, r5 */
/* @0xe6350 bl 0x27d1d0 <_ZdlPv> */
/* @0xe6354 b 0xe62dc <_Z9DoPopNulljPhPKhP6VMExec+0x128> */
/* @0xe6358 mov r0, r4 */
/* @0xe635c b 0xe622c <_Z9DoPopNulljPhPKhP6VMExec+0x78> */
/* @0xe6360 eoreq lr, r4, r12, lsr #5 */

/* ── FUNC 0xe6364 · VM::PokeDSMap(int, int, RValue&) · size=640 · insn=160 */
/* @0xe6364 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xe6368 subs r4, r0, #0 */
/* @0xe636c sub sp, sp, #8 */
/* @0xe6370 mov r7, r1 */
/* @0xe6374 mov r9, r2 */
/* @0xe6378 blt 0xe6390 <_ZN2VM9PokeDSMapEiiR6RValue+0x2c> */
/* @0xe637c ldr r3, [pc, #0x258] */
/* @0xe6380 ldr r3, [pc, r3] */
/* @0xe6384 ldr r3, [r3] */
/* @0xe6388 cmp r4, r3 */
/* @0xe638c blt 0xe63a0 <_ZN2VM9PokeDSMapEiiR6RValue+0x3c> */
/* @0xe6390 mov r5, #0 */
/* @0xe6394 mov r0, r5 */
/* @0xe6398 add sp, sp, #8 */
/* @0xe639c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xe63a0 add r8, sp, #4 */
/* @0xe63a4 mov r0, r8 */
/* @0xe63a8 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xe63ac ldr r3, [pc, #0x22c] */
/* @0xe63b0 ldr r3, [pc, r3] */
/* @0xe63b4 ldr r3, [r3, #0x4] */
/* @0xe63b8 ldr r4, [r3, r4, lsl #2] */
/* @0xe63bc cmp r4, #0 */
/* @0xe63c0 beq 0xe63e8 <_ZN2VM9PokeDSMapEiiR6RValue+0x84> */
/* @0xe63c4 mov r0, r4 */
/* @0xe63c8 bl 0x2052c0 <_ZN7CDS_Map4SizeEv> */
/* @0xe63cc cmp r7, r0 */
/* @0xe63d0 movge r5, #0 */
/* @0xe63d4 movlt r5, #1 */
/* @0xe63d8 cmp r7, #0 */
/* @0xe63dc movlt r5, #0 */
/* @0xe63e0 cmp r5, #0 */
/* @0xe63e4 bne 0xe6400 <_ZN2VM9PokeDSMapEiiR6RValue+0x9c> */
/* @0xe63e8 mov r0, r8 */
/* @0xe63ec mov r5, #0 */
/* @0xe63f0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xe63f4 mov r0, r5 */
/* @0xe63f8 add sp, sp, #8 */
/* @0xe63fc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xe6400 ldr r0, [r4] */
/* @0xe6404 mov r12, #0 */
/* @0xe6408 ldr r10, [r0] */
/* @0xe640c b 0xe6420 <_ZN2VM9PokeDSMapEiiR6RValue+0xbc> */
/* @0xe6410 ldr r2, [r0, #0x4] */
/* @0xe6414 add r12, r12, #1 */
/* @0xe6418 cmp r12, r2 */
/* @0xe641c bgt 0xe65d4 <_ZN2VM9PokeDSMapEiiR6RValue+0x270> */
/* @0xe6420 ldr r3, [r10, r12, lsl #3] */
/* @0xe6424 cmp r3, #0 */
/* @0xe6428 beq 0xe6410 <_ZN2VM9PokeDSMapEiiR6RValue+0xac> */
/* @0xe642c cmp r7, #0 */
/* @0xe6430 movne r6, #0 */
/* @0xe6434 bne 0xe6448 <_ZN2VM9PokeDSMapEiiR6RValue+0xe4> */
/* @0xe6438 b 0xe6498 <_ZN2VM9PokeDSMapEiiR6RValue+0x134> */
/* @0xe643c add r6, r6, #1 */
/* @0xe6440 cmp r6, r7 */
/* @0xe6444 beq 0xe6498 <_ZN2VM9PokeDSMapEiiR6RValue+0x134> */
/* @0xe6448 cmp r3, #0 */
/* @0xe644c beq 0xe643c <_ZN2VM9PokeDSMapEiiR6RValue+0xd8> */
/* @0xe6450 ldr r3, [r3, #0x4] */
/* @0xe6454 cmp r3, #0 */
/* @0xe6458 bne 0xe643c <_ZN2VM9PokeDSMapEiiR6RValue+0xd8> */
/* @0xe645c ldr r1, [r0, #0x4] */
/* @0xe6460 add r4, r12, #1 */
/* @0xe6464 cmp r4, r1 */
/* @0xe6468 bgt 0xe6490 <_ZN2VM9PokeDSMapEiiR6RValue+0x12c> */
/* @0xe646c add lr, r10, r12, lsl #3 */
/* @0xe6470 ldr r3, [lr, #0x8] */
/* @0xe6474 mov r12, r4 */
/* @0xe6478 add lr, lr, #8 */
/* @0xe647c add r4, r4, #1 */
/* @0xe6480 cmp r3, #0 */
/* @0xe6484 bne 0xe643c <_ZN2VM9PokeDSMapEiiR6RValue+0xd8> */
/* @0xe6488 cmp r1, r4 */
/* @0xe648c bge 0xe6470 <_ZN2VM9PokeDSMapEiiR6RValue+0x10c> */
/* @0xe6490 mvn r12, #0 */
/* @0xe6494 b 0xe643c <_ZN2VM9PokeDSMapEiiR6RValue+0xd8> */
/* @0xe6498 cmp r3, #0 */
/* @0xe649c beq 0xe63e8 <_ZN2VM9PokeDSMapEiiR6RValue+0x84> */
/* @0xe64a0 ldr r4, [r3, #0xc] */
/* @0xe64a4 cmp r4, #0 */
/* @0xe64a8 beq 0xe63e8 <_ZN2VM9PokeDSMapEiiR6RValue+0x84> */
/* @0xe64ac ldr r3, [r4, #0x1c] */
/* @0xe64b0 add r6, r4, #16 */
/* @0xe64b4 sub r3, r3, #1 */
/* @0xe64b8 bic r3, r3, #-16777216 */
/* @0xe64bc bic r3, r3, #3 */
/* @0xe64c0 cmp r3, #0 */
/* @0xe64c4 beq 0xe6550 <_ZN2VM9PokeDSMapEiiR6RValue+0x1ec> */
/* @0xe64c8 mov r3, #5 */
/* @0xe64cc str r3, [r4, #0x1c] */
/* @0xe64d0 ldr r3, [r9, #0xc] */
/* @0xe64d4 mov r2, #0 */
/* @0xe64d8 str r2, [r4, #0x18] */
/* @0xe64dc ldr r1, [r9, #0x8] */
/* @0xe64e0 str r3, [r4, #0x1c] */
/* @0xe64e4 ldr r3, [r9, #0xc] */
/* @0xe64e8 str r2, [r4, #0x10] */
/* @0xe64ec bic r3, r3, #-16777216 */
/* @0xe64f0 str r1, [r4, #0x18] */
/* @0xe64f4 cmp r3, #14 */
/* @0xe64f8 addls pc, pc, r3, lsl #2 */
/* @0xe64fc b 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0> */
/* @0xe6500 b 0xe655c <_ZN2VM9PokeDSMapEiiR6RValue+0x1f8> */
/* @0xe6504 b 0xe65bc <_ZN2VM9PokeDSMapEiiR6RValue+0x258> */
/* @0xe6508 b 0xe6590 <_ZN2VM9PokeDSMapEiiR6RValue+0x22c> */
/* @0xe650c b 0xe653c <_ZN2VM9PokeDSMapEiiR6RValue+0x1d8> */
/* @0xe6510 b 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0> */
/* @0xe6514 b 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0> */
/* @0xe6518 b 0xe656c <_ZN2VM9PokeDSMapEiiR6RValue+0x208> */
/* @0xe651c b 0xe653c <_ZN2VM9PokeDSMapEiiR6RValue+0x1d8> */
/* @0xe6520 b 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0> */
/* @0xe6524 b 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0> */
/* @0xe6528 b 0xe655c <_ZN2VM9PokeDSMapEiiR6RValue+0x1f8> */
/* @0xe652c b 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0> */
/* @0xe6530 b 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0> */
/* @0xe6534 b 0xe655c <_ZN2VM9PokeDSMapEiiR6RValue+0x1f8> */
/* @0xe6538 b 0xe653c <_ZN2VM9PokeDSMapEiiR6RValue+0x1d8> */
/* @0xe653c ldr r3, [r9] */
/* @0xe6540 str r3, [r4, #0x10] */
/* @0xe6544 mov r0, r8 */
/* @0xe6548 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xe654c b 0xe6394 <_ZN2VM9PokeDSMapEiiR6RValue+0x30> */
/* @0xe6550 mov r0, r6 */
/* @0xe6554 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe6558 b 0xe64c8 <_ZN2VM9PokeDSMapEiiR6RValue+0x164> */
/* @0xe655c ldm r9, {r2, r3} */
/* @0xe6560 str r2, [r4, #0x10] */
/* @0xe6564 str r3, [r4, #0x14] */
/* @0xe6568 b 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0> */
/* @0xe656c ldr r3, [r9] */
/* @0xe6570 str r3, [r4, #0x10] */
/* @0xe6574 ldr r3, [r9] */
/* @0xe6578 cmp r3, #0 */
/* @0xe657c beq 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0> */
/* @0xe6580 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xe6584 ldr r1, [r9] */
/* @0xe6588 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xe658c b 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0> */
/* @0xe6590 ldr r3, [r9] */
/* @0xe6594 cmp r3, #0 */
/* @0xe6598 str r3, [r4, #0x10] */
/* @0xe659c beq 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0> */
/* @0xe65a0 ldr r1, [r3, #0x8] */
/* @0xe65a4 ldr r2, [r3] */
/* @0xe65a8 cmp r1, #0 */
/* @0xe65ac streq r6, [r3, #0x8] */
/* @0xe65b0 add r2, r2, #1 */
/* @0xe65b4 str r2, [r3] */
/* @0xe65b8 b 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0> */
/* @0xe65bc ldr r3, [r9] */
/* @0xe65c0 cmp r3, #0 */
/* @0xe65c4 ldrne r2, [r3, #0x4] */
/* @0xe65c8 addne r2, r2, #1 */
/* @0xe65cc strne r2, [r3, #0x4] */
/* @0xe65d0 b 0xe6540 <_ZN2VM9PokeDSMapEiiR6RValue+0x1dc> */
/* @0xe65d4 mvn r12, #0 */
/* @0xe65d8 b 0xe642c <_ZN2VM9PokeDSMapEiiR6RValue+0xc8> */
/* @0xe65dc ldrshteq r7, [r0], -r8 */
/* @0xe65e0 eorseq r7, r0, r12, lsl #11 */
