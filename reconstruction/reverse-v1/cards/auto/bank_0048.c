/* libyoyo.so 覆盖卡组 0048
 * 函数 0x11b3f8..0x11bdec，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x11b3f8 · F_SurfaceCreateEmpty(RValue&, CInstance*, CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x11b3f8 push {r4, lr} */
/* @0x11b3fc mov r4, r0 */
/* @0x11b400 ldr r0, [pc, #0x24] */
/* @0x11b404 mov r1, #0 */
/* @0x11b408 add r0, pc, r0 */
/* @0x11b40c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11b410 mov r2, #0 */
/* @0x11b414 mov r3, r2 */
/* @0x11b418 movt r2, #0xbff0 */
/* @0x11b41c str r3, [r4, #0xc] */
/* @0x11b420 str r2, [r4, #0x4] */
/* @0x11b424 str r3, [r4] */
/* @0x11b428 pop {r4, pc} */
/* @0x11b42c eoreq lr, r1, r8, lsl #23 */

/* ── FUNC 0x11b430 · F_DrawLineExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x11b430 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x11b434 sub sp, sp, #12 */
/* @0x11b438 mov r1, #0 */
/* @0x11b43c ldr r4, [sp, #0x28] */
/* @0x11b440 mov r0, r4 */
/* @0x11b444 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b448 mov r1, #1 */
/* @0x11b44c mov r5, r0 */
/* @0x11b450 mov r0, r4 */
/* @0x11b454 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b458 mov r1, #2 */
/* @0x11b45c mov r8, r0 */
/* @0x11b460 mov r0, r4 */
/* @0x11b464 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b468 mov r1, #3 */
/* @0x11b46c mov r7, r0 */
/* @0x11b470 mov r0, r4 */
/* @0x11b474 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b478 mov r1, #4 */
/* @0x11b47c mov r6, r0 */
/* @0x11b480 mov r0, r4 */
/* @0x11b484 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b488 mov r1, #5 */
/* @0x11b48c mov r9, r0 */
/* @0x11b490 mov r0, r4 */
/* @0x11b494 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b498 str r9, [sp] */
/* @0x11b49c mov r1, r8 */
/* @0x11b4a0 mov r2, r7 */
/* @0x11b4a4 mov r3, r6 */
/* @0x11b4a8 str r0, [sp, #0x4] */
/* @0x11b4ac mov r0, r5 */
/* @0x11b4b0 bl 0x16a45c <_Z16GR_Draw_Line_Extffffjj> */
/* @0x11b4b4 add sp, sp, #12 */
/* @0x11b4b8 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x11b4bc · F_DrawLineWidthExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x11b4bc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11b4c0 sub sp, sp, #16 */
/* @0x11b4c4 mov r1, #0 */
/* @0x11b4c8 ldr r4, [sp, #0x30] */
/* @0x11b4cc mov r0, r4 */
/* @0x11b4d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b4d4 mov r1, #1 */
/* @0x11b4d8 mov r5, r0 */
/* @0x11b4dc mov r0, r4 */
/* @0x11b4e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b4e4 mov r1, #2 */
/* @0x11b4e8 mov r8, r0 */
/* @0x11b4ec mov r0, r4 */
/* @0x11b4f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b4f4 mov r1, #3 */
/* @0x11b4f8 mov r7, r0 */
/* @0x11b4fc mov r0, r4 */
/* @0x11b500 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b504 mov r1, #4 */
/* @0x11b508 mov r6, r0 */
/* @0x11b50c mov r0, r4 */
/* @0x11b510 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b514 mov r1, #5 */
/* @0x11b518 mov r10, r0 */
/* @0x11b51c mov r0, r4 */
/* @0x11b520 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b524 mov r1, #6 */
/* @0x11b528 mov r9, r0 */
/* @0x11b52c mov r0, r4 */
/* @0x11b530 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b534 str r10, [sp] */
/* @0x11b538 str r9, [sp, #0x4] */
/* @0x11b53c mov r1, r8 */
/* @0x11b540 mov r2, r7 */
/* @0x11b544 mov r3, r6 */
/* @0x11b548 str r0, [sp, #0x8] */
/* @0x11b54c mov r0, r5 */
/* @0x11b550 bl 0x16a550 <_Z22GR_Draw_Line_Width_Extfffffjj> */
/* @0x11b554 add sp, sp, #16 */
/* @0x11b558 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x11b55c · F_DrawRectangleExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=204 · insn=51 */
/* @0x11b55c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11b560 sub sp, sp, #36 */
/* @0x11b564 mov r1, #0 */
/* @0x11b568 ldr r4, [sp, #0x48] */
/* @0x11b56c mov r0, r4 */
/* @0x11b570 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b574 mov r1, #1 */
/* @0x11b578 mov r5, r0 */
/* @0x11b57c mov r0, r4 */
/* @0x11b580 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b584 mov r1, #2 */
/* @0x11b588 mov r8, r0 */
/* @0x11b58c mov r0, r4 */
/* @0x11b590 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b594 mov r1, #3 */
/* @0x11b598 mov r7, r0 */
/* @0x11b59c mov r0, r4 */
/* @0x11b5a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b5a4 mov r1, #4 */
/* @0x11b5a8 mov r6, r0 */
/* @0x11b5ac mov r0, r4 */
/* @0x11b5b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b5b4 mov r1, #5 */
/* @0x11b5b8 mov r3, r0 */
/* @0x11b5bc mov r0, r4 */
/* @0x11b5c0 str r3, [sp, #0x1c] */
/* @0x11b5c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b5c8 mov r1, #6 */
/* @0x11b5cc mov r11, r0 */
/* @0x11b5d0 mov r0, r4 */
/* @0x11b5d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b5d8 mov r1, #7 */
/* @0x11b5dc mov r10, r0 */
/* @0x11b5e0 mov r0, r4 */
/* @0x11b5e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b5e8 mov r1, #8 */
/* @0x11b5ec mov r9, r0 */
/* @0x11b5f0 mov r0, r4 */
/* @0x11b5f4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11b5f8 ldr r3, [sp, #0x1c] */
/* @0x11b5fc str r10, [sp, #0x8] */
/* @0x11b600 mov r1, r8 */
/* @0x11b604 str r9, [sp, #0xc] */
/* @0x11b608 mov r2, r7 */
/* @0x11b60c stm sp, {r3, r11} */
/* @0x11b610 mov r3, r6 */
/* @0x11b614 str r0, [sp, #0x10] */
/* @0x11b618 mov r0, r5 */
/* @0x11b61c bl 0x16ac60 <_Z21GR_Draw_Rectangle_Extffffjjjjb> */
/* @0x11b620 add sp, sp, #36 */
/* @0x11b624 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x11b628 · F_DrawRoundRectColour(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x11b628 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11b62c sub sp, sp, #24 */
/* @0x11b630 mov r1, #0 */
/* @0x11b634 ldr r4, [sp, #0x38] */
/* @0x11b638 mov r0, r4 */
/* @0x11b63c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b640 mov r1, #1 */
/* @0x11b644 mov r5, r0 */
/* @0x11b648 mov r0, r4 */
/* @0x11b64c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b650 mov r1, #2 */
/* @0x11b654 mov r8, r0 */
/* @0x11b658 mov r0, r4 */
/* @0x11b65c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b660 mov r1, #3 */
/* @0x11b664 mov r7, r0 */
/* @0x11b668 mov r0, r4 */
/* @0x11b66c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b670 mov r1, #4 */
/* @0x11b674 mov r6, r0 */
/* @0x11b678 mov r0, r4 */
/* @0x11b67c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b680 mov r1, #5 */
/* @0x11b684 mov r10, r0 */
/* @0x11b688 mov r0, r4 */
/* @0x11b68c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b690 mov r1, #6 */
/* @0x11b694 mov r9, r0 */
/* @0x11b698 mov r0, r4 */
/* @0x11b69c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11b6a0 str r10, [sp, #0x8] */
/* @0x11b6a4 str r9, [sp, #0xc] */
/* @0x11b6a8 mov r1, r8 */
/* @0x11b6ac mov r2, r7 */
/* @0x11b6b0 mov r3, r6 */
/* @0x11b6b4 mov r12, #0 */
/* @0x11b6b8 movt r12, #0x4120 */
/* @0x11b6bc str r12, [sp] */
/* @0x11b6c0 str r12, [sp, #0x4] */
/* @0x11b6c4 str r0, [sp, #0x10] */
/* @0x11b6c8 mov r0, r5 */
/* @0x11b6cc bl 0x16b864 <_Z21GR_Draw_RoundRect_Extffffffjjb> */
/* @0x11b6d0 add sp, sp, #24 */
/* @0x11b6d4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x11b6d8 · F_DrawRoundRectColour_EXT(RValue&, CInstance*, CInstance*, int, RValue*) · size=208 · insn=52 */
/* @0x11b6d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11b6dc sub sp, sp, #36 */
/* @0x11b6e0 mov r1, #4 */
/* @0x11b6e4 ldr r4, [sp, #0x48] */
/* @0x11b6e8 mov r0, r4 */
/* @0x11b6ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b6f0 mov r1, #5 */
/* @0x11b6f4 mov r3, r0 */
/* @0x11b6f8 mov r0, r4 */
/* @0x11b6fc str r3, [sp, #0x1c] */
/* @0x11b700 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b704 mov r1, #0 */
/* @0x11b708 mov r11, r0 */
/* @0x11b70c mov r0, r4 */
/* @0x11b710 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b714 mov r1, #1 */
/* @0x11b718 mov r5, r0 */
/* @0x11b71c mov r0, r4 */
/* @0x11b720 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b724 mov r1, #2 */
/* @0x11b728 mov r8, r0 */
/* @0x11b72c mov r0, r4 */
/* @0x11b730 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b734 mov r1, #3 */
/* @0x11b738 mov r7, r0 */
/* @0x11b73c mov r0, r4 */
/* @0x11b740 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b744 mov r1, #6 */
/* @0x11b748 mov r6, r0 */
/* @0x11b74c mov r0, r4 */
/* @0x11b750 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b754 mov r1, #7 */
/* @0x11b758 mov r10, r0 */
/* @0x11b75c mov r0, r4 */
/* @0x11b760 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b764 mov r1, #8 */
/* @0x11b768 mov r9, r0 */
/* @0x11b76c mov r0, r4 */
/* @0x11b770 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11b774 ldr r3, [sp, #0x1c] */
/* @0x11b778 str r11, [sp, #0x4] */
/* @0x11b77c mov r1, r8 */
/* @0x11b780 str r10, [sp, #0x8] */
/* @0x11b784 mov r2, r7 */
/* @0x11b788 str r3, [sp] */
/* @0x11b78c mov r3, r6 */
/* @0x11b790 str r9, [sp, #0xc] */
/* @0x11b794 str r0, [sp, #0x10] */
/* @0x11b798 mov r0, r5 */
/* @0x11b79c bl 0x16b864 <_Z21GR_Draw_RoundRect_Extffffffjjb> */
/* @0x11b7a0 add sp, sp, #36 */
/* @0x11b7a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x11b7a8 · F_DrawTriangleExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=236 · insn=59 */
/* @0x11b7a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11b7ac sub sp, sp, #36 */
/* @0x11b7b0 mov r1, #0 */
/* @0x11b7b4 ldr r4, [sp, #0x48] */
/* @0x11b7b8 mov r0, r4 */
/* @0x11b7bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b7c0 mov r1, #1 */
/* @0x11b7c4 mov r5, r0 */
/* @0x11b7c8 mov r0, r4 */
/* @0x11b7cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b7d0 mov r1, #2 */
/* @0x11b7d4 mov r8, r0 */
/* @0x11b7d8 mov r0, r4 */
/* @0x11b7dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b7e0 mov r1, #3 */
/* @0x11b7e4 mov r7, r0 */
/* @0x11b7e8 mov r0, r4 */
/* @0x11b7ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b7f0 mov r1, #4 */
/* @0x11b7f4 mov r6, r0 */
/* @0x11b7f8 mov r0, r4 */
/* @0x11b7fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b800 mov r1, #5 */
/* @0x11b804 mov r2, r0 */
/* @0x11b808 mov r0, r4 */
/* @0x11b80c str r2, [sp, #0x18] */
/* @0x11b810 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b814 mov r1, #6 */
/* @0x11b818 mov r3, r0 */
/* @0x11b81c mov r0, r4 */
/* @0x11b820 str r3, [sp, #0x1c] */
/* @0x11b824 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b828 mov r1, #7 */
/* @0x11b82c mov r11, r0 */
/* @0x11b830 mov r0, r4 */
/* @0x11b834 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b838 mov r1, #8 */
/* @0x11b83c mov r10, r0 */
/* @0x11b840 mov r0, r4 */
/* @0x11b844 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b848 mov r1, #9 */
/* @0x11b84c mov r9, r0 */
/* @0x11b850 mov r0, r4 */
/* @0x11b854 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11b858 ldr r2, [sp, #0x18] */
/* @0x11b85c ldr r3, [sp, #0x1c] */
/* @0x11b860 mov r1, r8 */
/* @0x11b864 str r11, [sp, #0x8] */
/* @0x11b868 str r2, [sp] */
/* @0x11b86c mov r2, r7 */
/* @0x11b870 str r3, [sp, #0x4] */
/* @0x11b874 mov r3, r6 */
/* @0x11b878 str r10, [sp, #0xc] */
/* @0x11b87c str r9, [sp, #0x10] */
/* @0x11b880 str r0, [sp, #0x14] */
/* @0x11b884 mov r0, r5 */
/* @0x11b888 bl 0x16a85c <_Z20GR_Draw_Triangle_Extffffffjjjb> */
/* @0x11b88c add sp, sp, #36 */
/* @0x11b890 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x11b894 · F_DrawCircleExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x11b894 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x11b898 sub sp, sp, #12 */
/* @0x11b89c mov r1, #0 */
/* @0x11b8a0 ldr r4, [sp, #0x28] */
/* @0x11b8a4 mov r0, r4 */
/* @0x11b8a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b8ac mov r1, #1 */
/* @0x11b8b0 mov r5, r0 */
/* @0x11b8b4 mov r0, r4 */
/* @0x11b8b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b8bc mov r1, #2 */
/* @0x11b8c0 mov r8, r0 */
/* @0x11b8c4 mov r0, r4 */
/* @0x11b8c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b8cc mov r1, #3 */
/* @0x11b8d0 mov r6, r0 */
/* @0x11b8d4 mov r0, r4 */
/* @0x11b8d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b8dc mov r1, #4 */
/* @0x11b8e0 mov r7, r0 */
/* @0x11b8e4 mov r0, r4 */
/* @0x11b8e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b8ec mov r1, #5 */
/* @0x11b8f0 mov r9, r0 */
/* @0x11b8f4 mov r0, r4 */
/* @0x11b8f8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11b8fc str r9, [sp] */
/* @0x11b900 mov r1, r8 */
/* @0x11b904 mov r3, r7 */
/* @0x11b908 mov r2, r6 */
/* @0x11b90c str r0, [sp, #0x4] */
/* @0x11b910 mov r0, r5 */
/* @0x11b914 bl 0x16b1f4 <_Z18GR_Draw_Circle_Extfffjjb> */
/* @0x11b918 add sp, sp, #12 */
/* @0x11b91c pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x11b920 · F_DrawEllipseExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x11b920 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11b924 sub sp, sp, #16 */
/* @0x11b928 mov r1, #0 */
/* @0x11b92c ldr r4, [sp, #0x30] */
/* @0x11b930 mov r0, r4 */
/* @0x11b934 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b938 mov r1, #1 */
/* @0x11b93c mov r5, r0 */
/* @0x11b940 mov r0, r4 */
/* @0x11b944 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b948 mov r1, #2 */
/* @0x11b94c mov r8, r0 */
/* @0x11b950 mov r0, r4 */
/* @0x11b954 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b958 mov r1, #3 */
/* @0x11b95c mov r7, r0 */
/* @0x11b960 mov r0, r4 */
/* @0x11b964 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b968 mov r1, #4 */
/* @0x11b96c mov r6, r0 */
/* @0x11b970 mov r0, r4 */
/* @0x11b974 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b978 mov r1, #5 */
/* @0x11b97c mov r10, r0 */
/* @0x11b980 mov r0, r4 */
/* @0x11b984 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b988 mov r1, #6 */
/* @0x11b98c mov r9, r0 */
/* @0x11b990 mov r0, r4 */
/* @0x11b994 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11b998 str r10, [sp] */
/* @0x11b99c str r9, [sp, #0x4] */
/* @0x11b9a0 mov r1, r8 */
/* @0x11b9a4 mov r2, r7 */
/* @0x11b9a8 mov r3, r6 */
/* @0x11b9ac str r0, [sp, #0x8] */
/* @0x11b9b0 mov r0, r5 */
/* @0x11b9b4 bl 0x16b2ac <_Z19GR_Draw_Ellipse_Extffffjjb> */
/* @0x11b9b8 add sp, sp, #16 */
/* @0x11b9bc pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x11b9c0 · F_DrawSetCirclePrecision(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x11b9c0 push {r3, lr} */
/* @0x11b9c4 mov r1, #0 */
/* @0x11b9c8 ldr r0, [sp, #0x8] */
/* @0x11b9cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b9d0 pop {r3, lr} */
/* @0x11b9d4 b 0x16ae64 <_Z24GR_Draw_Circle_Precisioni> */

/* ── FUNC 0x11b9d8 · F_DrawPrimitiveBegin(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x11b9d8 push {r3, lr} */
/* @0x11b9dc mov r1, #0 */
/* @0x11b9e0 ldr r0, [sp, #0x8] */
/* @0x11b9e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b9e8 mvn r1, #0 */
/* @0x11b9ec pop {r3, lr} */
/* @0x11b9f0 b 0x16b964 <_Z23GR_Draw_Primitive_Beginii> */

/* ── FUNC 0x11b9f4 · F_DrawPrimitiveBeginTexture(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x11b9f4 push {r3, r4, r5, lr} */
/* @0x11b9f8 mov r1, #0 */
/* @0x11b9fc ldr r4, [sp, #0x10] */
/* @0x11ba00 mov r0, r4 */
/* @0x11ba04 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ba08 mov r1, #1 */
/* @0x11ba0c mov r5, r0 */
/* @0x11ba10 mov r0, r4 */
/* @0x11ba14 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei> */
/* @0x11ba18 mov r1, r0 */
/* @0x11ba1c mov r0, r5 */
/* @0x11ba20 pop {r3, r4, r5, lr} */
/* @0x11ba24 b 0x16b964 <_Z23GR_Draw_Primitive_Beginii> */

/* ── FUNC 0x11ba28 · F_DrawPrimitiveEnd(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x11ba28 b 0x16bdb0 <_Z21GR_Draw_Primitive_Endv> */

/* ── FUNC 0x11ba2c · F_DrawVertex(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x11ba2c push {r3, r4, r5, lr} */
/* @0x11ba30 mov r1, #0 */
/* @0x11ba34 ldr r4, [sp, #0x10] */
/* @0x11ba38 mov r0, r4 */
/* @0x11ba3c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ba40 mov r1, #1 */
/* @0x11ba44 mov r5, r0 */
/* @0x11ba48 mov r0, r4 */
/* @0x11ba4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ba50 mov r1, r0 */
/* @0x11ba54 mov r0, r5 */
/* @0x11ba58 pop {r3, r4, r5, lr} */
/* @0x11ba5c b 0x16ba58 <_Z14GR_Draw_Vertexff> */

/* ── FUNC 0x11ba60 · F_DrawVertexColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x11ba60 push {r4, r5, r6, r7, r8, lr} */
/* @0x11ba64 mov r1, #0 */
/* @0x11ba68 ldr r4, [sp, #0x18] */
/* @0x11ba6c mov r0, r4 */
/* @0x11ba70 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ba74 mov r1, #1 */
/* @0x11ba78 mov r7, r0 */
/* @0x11ba7c mov r0, r4 */
/* @0x11ba80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ba84 mov r1, #2 */
/* @0x11ba88 mov r6, r0 */
/* @0x11ba8c mov r0, r4 */
/* @0x11ba90 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ba94 mov r1, #3 */
/* @0x11ba98 mov r5, r0 */
/* @0x11ba9c mov r0, r4 */
/* @0x11baa0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11baa4 mov r1, r6 */
/* @0x11baa8 mov r2, r5 */
/* @0x11baac mov r3, r0 */
/* @0x11bab0 mov r0, r7 */
/* @0x11bab4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x11bab8 b 0x16bae0 <_Z20GR_Draw_Vertex_Colorffjf> */

/* ── FUNC 0x11babc · F_DrawVertexTexture(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x11babc push {r4, r5, r6, r7, r8, lr} */
/* @0x11bac0 mov r1, #0 */
/* @0x11bac4 ldr r4, [sp, #0x18] */
/* @0x11bac8 mov r0, r4 */
/* @0x11bacc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11bad0 mov r1, #1 */
/* @0x11bad4 mov r7, r0 */
/* @0x11bad8 mov r0, r4 */
/* @0x11badc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11bae0 mov r1, #2 */
/* @0x11bae4 mov r6, r0 */
/* @0x11bae8 mov r0, r4 */
/* @0x11baec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11baf0 mov r1, #3 */
/* @0x11baf4 mov r5, r0 */
/* @0x11baf8 mov r0, r4 */
/* @0x11bafc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11bb00 mov r1, r6 */
/* @0x11bb04 mov r2, r5 */
/* @0x11bb08 mov r3, r0 */
/* @0x11bb0c mov r0, r7 */
/* @0x11bb10 pop {r4, r5, r6, r7, r8, lr} */
/* @0x11bb14 b 0x16bb70 <_Z22GR_Draw_Vertex_Textureffff> */

/* ── FUNC 0x11bb18 · F_DrawVertexTextureColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x11bb18 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x11bb1c sub sp, sp, #12 */
/* @0x11bb20 mov r1, #0 */
/* @0x11bb24 ldr r4, [sp, #0x28] */
/* @0x11bb28 mov r0, r4 */
/* @0x11bb2c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11bb30 mov r1, #1 */
/* @0x11bb34 mov r5, r0 */
/* @0x11bb38 mov r0, r4 */
/* @0x11bb3c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11bb40 mov r1, #2 */
/* @0x11bb44 mov r8, r0 */
/* @0x11bb48 mov r0, r4 */
/* @0x11bb4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11bb50 mov r1, #3 */
/* @0x11bb54 mov r7, r0 */
/* @0x11bb58 mov r0, r4 */
/* @0x11bb5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11bb60 mov r1, #4 */
/* @0x11bb64 mov r6, r0 */
/* @0x11bb68 mov r0, r4 */
/* @0x11bb6c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11bb70 mov r1, #5 */
/* @0x11bb74 mov r9, r0 */
/* @0x11bb78 mov r0, r4 */
/* @0x11bb7c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11bb80 str r9, [sp] */
/* @0x11bb84 mov r1, r8 */
/* @0x11bb88 mov r2, r7 */
/* @0x11bb8c mov r3, r6 */
/* @0x11bb90 str r0, [sp, #0x4] */
/* @0x11bb94 mov r0, r5 */
/* @0x11bb98 bl 0x16bc84 <_Z28GR_Draw_Vertex_Texture_Colorffffjf> */
/* @0x11bb9c add sp, sp, #12 */
/* @0x11bba0 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x11bba4 · F_TextureExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x11bba4 push {r3, r4, r5, lr} */
/* @0x11bba8 mov r5, #0 */
/* @0x11bbac mov r4, r0 */
/* @0x11bbb0 mov r1, r5 */
/* @0x11bbb4 str r5, [r0, #0xc] */
/* @0x11bbb8 ldr r0, [sp, #0x10] */
/* @0x11bbbc bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei> */
/* @0x11bbc0 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x11bbc4 cmp r0, #0 */
/* @0x11bbc8 moveq r5, r0 */
/* @0x11bbcc movne r3, r5 */
/* @0x11bbd0 moveq r3, r5 */
/* @0x11bbd4 movtne r3, #0x3ff0 */
/* @0x11bbd8 str r5, [r4] */
/* @0x11bbdc str r3, [r4, #0x4] */
/* @0x11bbe0 pop {r3, r4, r5, pc} */

/* ── FUNC 0x11bbe4 · F_TextureGetWidth(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x11bbe4 push {r4, lr} */
/* @0x11bbe8 mov r3, #0 */
/* @0x11bbec mov r1, r3 */
/* @0x11bbf0 str r3, [r0, #0xc] */
/* @0x11bbf4 mov r4, r0 */
/* @0x11bbf8 ldr r0, [sp, #0x8] */
/* @0x11bbfc bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei> */
/* @0x11bc00 bl 0x1741f8 <_Z20GR_Texture_Get_Widthi> */
/* @0x11bc04 vmov s15, r0 */
/* @0x11bc08 vcvt.f64.f32 d7, s15 */
/* @0x11bc0c vmov r0, r1, d7 */
/* @0x11bc10 vmov r2, s14 */
/* @0x11bc14 mov r3, r1 */
/* @0x11bc18 stm r4, {r2, r3} */
/* @0x11bc1c pop {r4, pc} */

/* ── FUNC 0x11bc20 · F_TextureGetHeight(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x11bc20 push {r4, lr} */
/* @0x11bc24 mov r3, #0 */
/* @0x11bc28 mov r1, r3 */
/* @0x11bc2c str r3, [r0, #0xc] */
/* @0x11bc30 mov r4, r0 */
/* @0x11bc34 ldr r0, [sp, #0x8] */
/* @0x11bc38 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei> */
/* @0x11bc3c bl 0x174240 <_Z21GR_Texture_Get_Heighti> */
/* @0x11bc40 vmov s15, r0 */
/* @0x11bc44 vcvt.f64.f32 d7, s15 */
/* @0x11bc48 vmov r0, r1, d7 */
/* @0x11bc4c vmov r2, s14 */
/* @0x11bc50 mov r3, r1 */
/* @0x11bc54 stm r4, {r2, r3} */
/* @0x11bc58 pop {r4, pc} */

/* ── FUNC 0x11bc5c · F_TextureSetInterpolation(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x11bc5c push {r3, lr} */
/* @0x11bc60 mov r1, #0 */
/* @0x11bc64 ldr r0, [sp, #0x8] */
/* @0x11bc68 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11bc6c pop {r3, lr} */
/* @0x11bc70 b 0x168710 <_Z32GR_D3D_Set_Texture_Interpolationb> */

/* ── FUNC 0x11bc74 · F_TextureSetInterpolationExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x11bc74 push {r3, r4, r5, lr} */
/* @0x11bc78 mov r1, #0 */
/* @0x11bc7c ldr r4, [sp, #0x10] */
/* @0x11bc80 mov r0, r4 */
/* @0x11bc84 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11bc88 mov r1, #1 */
/* @0x11bc8c mov r5, r0 */
/* @0x11bc90 mov r0, r4 */
/* @0x11bc94 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11bc98 mov r1, r0 */
/* @0x11bc9c mov r0, r5 */
/* @0x11bca0 pop {r3, r4, r5, lr} */
/* @0x11bca4 b 0x1687d4 <_Z36GR_D3D_Set_Texture_Interpolation_Extib> */

/* ── FUNC 0x11bca8 · F_TextureSetBlending(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x11bca8 push {r3, lr} */
/* @0x11bcac mov r1, #0 */
/* @0x11bcb0 ldr r0, [sp, #0x8] */
/* @0x11bcb4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11bcb8 pop {r3, lr} */
/* @0x11bcbc b 0x1689c8 <_Z27GR_D3D_Set_Texture_Blendingb> */

/* ── FUNC 0x11bcc0 · F_TextureSetRepeat(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x11bcc0 push {r3, lr} */
/* @0x11bcc4 mov r1, #0 */
/* @0x11bcc8 ldr r0, [sp, #0x8] */
/* @0x11bccc bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11bcd0 pop {r3, lr} */
/* @0x11bcd4 b 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb> */

/* ── FUNC 0x11bcd8 · F_TextureSetRepeatExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x11bcd8 push {r3, r4, r5, lr} */
/* @0x11bcdc mov r1, #0 */
/* @0x11bce0 ldr r4, [sp, #0x10] */
/* @0x11bce4 mov r0, r4 */
/* @0x11bce8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11bcec mov r1, #1 */
/* @0x11bcf0 mov r5, r0 */
/* @0x11bcf4 mov r0, r4 */
/* @0x11bcf8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11bcfc mov r1, r0 */
/* @0x11bd00 mov r0, r5 */
/* @0x11bd04 pop {r3, r4, r5, lr} */
/* @0x11bd08 b 0x168934 <_Z29GR_D3D_Set_Texture_Repeat_Extib> */

/* ── FUNC 0x11bd0c · F_TexturePreload(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x11bd0c push {r3, lr} */
/* @0x11bd10 mov r1, #0 */
/* @0x11bd14 ldr r0, [sp, #0x8] */
/* @0x11bd18 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei> */
/* @0x11bd1c pop {r3, lr} */
/* @0x11bd20 b 0x174288 <_Z18GR_Texture_Preloadi> */

/* ── FUNC 0x11bd24 · F_TextureSetPriority(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x11bd24 push {r3, r4, r5, lr} */
/* @0x11bd28 mov r1, #0 */
/* @0x11bd2c ldr r4, [sp, #0x10] */
/* @0x11bd30 mov r0, r4 */
/* @0x11bd34 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei> */
/* @0x11bd38 mov r1, #1 */
/* @0x11bd3c mov r5, r0 */
/* @0x11bd40 mov r0, r4 */
/* @0x11bd44 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11bd48 mov r1, r0 */
/* @0x11bd4c mov r0, r5 */
/* @0x11bd50 pop {r3, r4, r5, lr} */
/* @0x11bd54 b 0x1742bc <_Z23GR_Texture_Set_Priorityii> */

/* ── FUNC 0x11bd58 · F_DrawSetFont(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x11bd58 push {r3, lr} */
/* @0x11bd5c mov r1, #0 */
/* @0x11bd60 ldr r0, [sp, #0x8] */
/* @0x11bd64 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11bd68 pop {r3, lr} */
/* @0x11bd6c b 0x172ac8 <_Z16GR_Text_Set_Fonti> */

/* ── FUNC 0x11bd70 · F_DrawSetHAlign(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x11bd70 push {r3, lr} */
/* @0x11bd74 mov r1, #0 */
/* @0x11bd78 ldr r0, [sp, #0x8] */
/* @0x11bd7c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11bd80 pop {r3, lr} */
/* @0x11bd84 b 0x172b30 <_Z18GR_Text_Set_HAligni> */

/* ── FUNC 0x11bd88 · F_DrawSetVAlign(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x11bd88 push {r3, lr} */
/* @0x11bd8c mov r1, #0 */
/* @0x11bd90 ldr r0, [sp, #0x8] */
/* @0x11bd94 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11bd98 pop {r3, lr} */
/* @0x11bd9c b 0x172b7c <_Z18GR_Text_Set_VAligni> */

/* ── FUNC 0x11bda0 · F_StringWidth(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x11bda0 push {r3, r4, r5, lr} */
/* @0x11bda4 mov r1, #0 */
/* @0x11bda8 ldr r3, [sp, #0x10] */
/* @0x11bdac mov r4, r0 */
/* @0x11bdb0 str r1, [r0, #0xc] */
/* @0x11bdb4 mov r0, r3 */
/* @0x11bdb8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11bdbc bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x11bdc0 mvn r1, #0 */
/* @0x11bdc4 mov r2, r1 */
/* @0x11bdc8 mov r5, r0 */
/* @0x11bdcc bl 0x172bc8 <_Z13GR_Text_WidthPKcii> */
/* @0x11bdd0 vmov s15, r0 */
/* @0x11bdd4 mov r0, r5 */
/* @0x11bdd8 vcvt.f64.s32 d7, s15 */
/* @0x11bddc vmov r2, r3, d7 */
/* @0x11bde0 stm r4, {r2, r3} */
/* @0x11bde4 pop {r3, r4, r5, lr} */
/* @0x11bde8 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */

/* ── FUNC 0x11bdec · F_StringHeight(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x11bdec push {r3, r4, r5, lr} */
/* @0x11bdf0 mov r1, #0 */
/* @0x11bdf4 ldr r3, [sp, #0x10] */
/* @0x11bdf8 mov r4, r0 */
/* @0x11bdfc str r1, [r0, #0xc] */
/* @0x11be00 mov r0, r3 */
/* @0x11be04 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11be08 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x11be0c mvn r1, #0 */
/* @0x11be10 mov r2, r1 */
/* @0x11be14 mov r5, r0 */
/* @0x11be18 bl 0x172d08 <_Z14GR_Text_HeightPKcii> */
/* @0x11be1c vmov s15, r0 */
/* @0x11be20 mov r0, r5 */
/* @0x11be24 vcvt.f64.s32 d7, s15 */
/* @0x11be28 vmov r2, r3, d7 */
/* @0x11be2c stm r4, {r2, r3} */
/* @0x11be30 pop {r3, r4, r5, lr} */
/* @0x11be34 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
