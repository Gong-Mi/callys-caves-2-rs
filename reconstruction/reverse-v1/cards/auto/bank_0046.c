/* libyoyo.so 覆盖卡组 0046
 * 函数 0x11a22c..0x11a8ec，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x11a22c · F_DisplayMouseSet(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x11a22c push {r3, r4, r5, lr} */
/* @0x11a230 mov r1, #0 */
/* @0x11a234 ldr r4, [sp, #0x10] */
/* @0x11a238 mov r0, r4 */
/* @0x11a23c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a240 mov r1, #1 */
/* @0x11a244 mov r5, r0 */
/* @0x11a248 mov r0, r4 */
/* @0x11a24c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a250 mov r1, r0 */
/* @0x11a254 mov r0, r5 */
/* @0x11a258 pop {r3, r4, r5, lr} */
/* @0x11a25c b 0x17dbb4 <_Z15DisplaySetMouseii> */

/* ── FUNC 0x11a260 · F_DisplaySetUIVisibility(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x11a260 push {r3, r4, r5, lr} */
/* @0x11a264 mov r4, #0 */
/* @0x11a268 ldr r3, [pc, #0x3c] */
/* @0x11a26c str r4, [r0] */
/* @0x11a270 ldr r3, [pc, r3] */
/* @0x11a274 str r4, [r0, #0x4] */
/* @0x11a278 str r4, [r0, #0xc] */
/* @0x11a27c ldr r0, [r3] */
/* @0x11a280 ldr r5, [sp, #0x10] */
/* @0x11a284 ldr r1, [pc, #0x24] */
/* @0x11a288 ldr r2, [r0] */
/* @0x11a28c add r1, pc, r1 */
/* @0x11a290 ldr r3, [r2, #0xc] */
/* @0x11a294 blx r3 */
/* @0x11a298 mov r0, r5 */
/* @0x11a29c mov r1, r4 */
/* @0x11a2a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a2a4 pop {r3, r4, r5, lr} */
/* @0x11a2a8 b 0x15e2b8 <_Z22DisplaySetUIVisibilityi> */
/* @0x11a2ac eoreq r3, sp, r4, lsr #9 */
/* @0x11a2b0 eoreq pc, r1, r4, lsr #25 */

/* ── FUNC 0x11a2b4 · F_DrawSetSWFAAlevel(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x11a2b4 push {r3, lr} */
/* @0x11a2b8 mov r1, #0 */
/* @0x11a2bc ldr r0, [sp, #0x8] */
/* @0x11a2c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11a2c4 vmov s15, r0 */
/* @0x11a2c8 vcmpe.f32 s15, #0 */
/* @0x11a2cc vmrs APSR_nzcv, fpscr */
/* @0x11a2d0 bmi 0x11a2f4 <_Z19F_DrawSetSWFAAlevelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x11a2d4 vmov.f32 s14, #1.000000e+00 */
/* @0x11a2d8 vcmp.f32 s15, s14 */
/* @0x11a2dc vmrs APSR_nzcv, fpscr */
/* @0x11a2e0 vmovgt.f32 s15, s14 */
/* @0x11a2e4 ldr r3, [pc, #0x14] */
/* @0x11a2e8 ldr r3, [pc, r3] */
/* @0x11a2ec vstr s15, [r3] */
/* @0x11a2f0 pop {r3, pc} */
/* @0x11a2f4 vldr s15, [pc] */
/* @0x11a2f8 b 0x11a2e4 <_Z19F_DrawSetSWFAAlevelR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x11a2fc andeq r0, r0, r0 */
/* @0x11a300 .word 0x002d42d0 */

/* ── FUNC 0x11a304 · F_WindowSetFullscreen(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x11a304 push {r3, lr} */
/* @0x11a308 mov r1, #0 */
/* @0x11a30c ldr r0, [sp, #0x8] */
/* @0x11a310 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11a314 pop {r3, lr} */
/* @0x11a318 b 0x17af10 <_Z24GR_Window_Set_FullScreenb> */

/* ── FUNC 0x11a31c · F_WindowGetFullscreen(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x11a31c push {r3, r4, r5, lr} */
/* @0x11a320 mov r5, #0 */
/* @0x11a324 str r5, [r0, #0xc] */
/* @0x11a328 mov r4, r0 */
/* @0x11a32c bl 0x17af24 <_Z24GR_Window_Get_FullScreenv> */
/* @0x11a330 cmp r0, #0 */
/* @0x11a334 movne r0, r5 */
/* @0x11a338 moveq r3, r0 */
/* @0x11a33c movne r3, r0 */
/* @0x11a340 movtne r3, #0x3ff0 */
/* @0x11a344 stm r4, {r0, r3} */
/* @0x11a348 pop {r3, r4, r5, pc} */

/* ── FUNC 0x11a34c · F_WindowSetCaption(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x11a34c push {r3, lr} */
/* @0x11a350 mov r1, #0 */
/* @0x11a354 ldr r0, [sp, #0x8] */
/* @0x11a358 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11a35c mov r1, #0 */
/* @0x11a360 pop {r3, lr} */
/* @0x11a364 b 0x17ae38 <_Z21GR_Window_Set_CaptionPKcb> */

/* ── FUNC 0x11a368 · F_WindowSetMinWidth(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x11a368 push {r3, lr} */
/* @0x11a36c mov r1, #0 */
/* @0x11a370 ldr r0, [sp, #0x8] */
/* @0x11a374 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a378 pop {r3, lr} */
/* @0x11a37c b 0x1799b0 <_Z23GR_Window_Set_Min_Widthi> */

/* ── FUNC 0x11a380 · F_WindowSetMaxWidth(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x11a380 push {r3, lr} */
/* @0x11a384 mov r1, #0 */
/* @0x11a388 ldr r0, [sp, #0x8] */
/* @0x11a38c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a390 pop {r3, lr} */
/* @0x11a394 b 0x1799c4 <_Z23GR_Window_Set_Max_Widthi> */

/* ── FUNC 0x11a398 · F_WindowSetMinHeight(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x11a398 push {r3, lr} */
/* @0x11a39c mov r1, #0 */
/* @0x11a3a0 ldr r0, [sp, #0x8] */
/* @0x11a3a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a3a8 pop {r3, lr} */
/* @0x11a3ac b 0x1799d8 <_Z24GR_Window_Set_Min_Heighti> */

/* ── FUNC 0x11a3b0 · F_WindowSetMaxHeight(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x11a3b0 push {r3, lr} */
/* @0x11a3b4 mov r1, #0 */
/* @0x11a3b8 ldr r0, [sp, #0x8] */
/* @0x11a3bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a3c0 pop {r3, lr} */
/* @0x11a3c4 b 0x1799ec <_Z24GR_Window_Set_Max_Heighti> */

/* ── FUNC 0x11a3c8 · F_WindowGetCaption(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x11a3c8 push {r4, lr} */
/* @0x11a3cc mov r4, r0 */
/* @0x11a3d0 bl 0x17aefc <_Z21GR_Window_Get_Captionv> */
/* @0x11a3d4 mov r1, r0 */
/* @0x11a3d8 mov r0, r4 */
/* @0x11a3dc pop {r4, lr} */
/* @0x11a3e0 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x11a3e4 · F_WindowSetCursor(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x11a3e4 push {r3, lr} */
/* @0x11a3e8 mov r1, #0 */
/* @0x11a3ec ldr r0, [sp, #0x8] */
/* @0x11a3f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a3f4 pop {r3, lr} */
/* @0x11a3f8 b 0x17af8c <_Z20GR_Window_Set_Cursori> */

/* ── FUNC 0x11a3fc · F_WindowGetCursor(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x11a3fc push {r4, lr} */
/* @0x11a400 mov r3, #0 */
/* @0x11a404 str r3, [r0, #0xc] */
/* @0x11a408 mov r4, r0 */
/* @0x11a40c bl 0x17af84 <_Z20GR_Window_Get_Cursorv> */
/* @0x11a410 vmov s15, r0 */
/* @0x11a414 vcvt.f64.s32 d7, s15 */
/* @0x11a418 vmov r0, r1, d7 */
/* @0x11a41c vmov r2, s14 */
/* @0x11a420 mov r3, r1 */
/* @0x11a424 stm r4, {r2, r3} */
/* @0x11a428 pop {r4, pc} */

/* ── FUNC 0x11a42c · F_WindowSetColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x11a42c push {r3, lr} */
/* @0x11a430 mov r1, #0 */
/* @0x11a434 ldr r0, [sp, #0x8] */
/* @0x11a438 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a43c pop {r3, lr} */
/* @0x11a440 b 0x17ae08 <_Z19GR_Window_Set_Colorj> */

/* ── FUNC 0x11a444 · F_WindowGetColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x11a444 push {r4, lr} */
/* @0x11a448 mov r3, #0 */
/* @0x11a44c str r3, [r0, #0xc] */
/* @0x11a450 mov r4, r0 */
/* @0x11a454 bl 0x17ae20 <_Z19GR_Window_Get_Colorv> */
/* @0x11a458 vmov s15, r0 */
/* @0x11a45c vcvt.f64.u32 d7, s15 */
/* @0x11a460 vmov r0, r1, d7 */
/* @0x11a464 vmov r2, s14 */
/* @0x11a468 mov r3, r1 */
/* @0x11a46c stm r4, {r2, r3} */
/* @0x11a470 pop {r4, pc} */

/* ── FUNC 0x11a474 · F_WindowSetPosition(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x11a474 push {r3, r4, r5, lr} */
/* @0x11a478 mov r1, #0 */
/* @0x11a47c ldr r4, [sp, #0x10] */
/* @0x11a480 mov r0, r4 */
/* @0x11a484 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a488 mov r1, #1 */
/* @0x11a48c mov r5, r0 */
/* @0x11a490 mov r0, r4 */
/* @0x11a494 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a498 mov r1, r0 */
/* @0x11a49c mov r0, r5 */
/* @0x11a4a0 pop {r3, r4, r5, lr} */
/* @0x11a4a4 b 0x17af38 <_Z22GR_Window_Set_Positionii> */

/* ── FUNC 0x11a4a8 · F_WindowSetSize(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x11a4a8 push {r3, r4, r5, lr} */
/* @0x11a4ac mov r1, #0 */
/* @0x11a4b0 ldr r4, [sp, #0x10] */
/* @0x11a4b4 mov r0, r4 */
/* @0x11a4b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a4bc mov r1, #1 */
/* @0x11a4c0 mov r5, r0 */
/* @0x11a4c4 mov r0, r4 */
/* @0x11a4c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a4cc mov r1, r0 */
/* @0x11a4d0 mov r0, r5 */
/* @0x11a4d4 pop {r3, r4, r5, lr} */
/* @0x11a4d8 b 0x17af3c <_Z18GR_Window_Set_Sizeii> */

/* ── FUNC 0x11a4dc · F_WindowSetRectangle(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x11a4dc push {r4, r5, r6, r7, r8, lr} */
/* @0x11a4e0 mov r1, #0 */
/* @0x11a4e4 ldr r4, [sp, #0x18] */
/* @0x11a4e8 mov r0, r4 */
/* @0x11a4ec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a4f0 mov r1, #1 */
/* @0x11a4f4 mov r7, r0 */
/* @0x11a4f8 mov r0, r4 */
/* @0x11a4fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a500 mov r1, #2 */
/* @0x11a504 mov r6, r0 */
/* @0x11a508 mov r0, r4 */
/* @0x11a50c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a510 mov r1, #3 */
/* @0x11a514 mov r5, r0 */
/* @0x11a518 mov r0, r4 */
/* @0x11a51c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a520 mov r1, r6 */
/* @0x11a524 mov r2, r5 */
/* @0x11a528 mov r3, r0 */
/* @0x11a52c mov r0, r7 */
/* @0x11a530 pop {r4, r5, r6, r7, r8, lr} */
/* @0x11a534 b 0x17add4 <_Z23GR_Window_Set_Rectangleiiii> */

/* ── FUNC 0x11a538 · F_WindowCenter(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x11a538 b 0x17af34 <_Z16GR_Window_Centerv> */

/* ── FUNC 0x11a53c · F_WindowGetX(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x11a53c push {r4, lr} */
/* @0x11a540 mov r3, #0 */
/* @0x11a544 str r3, [r0, #0xc] */
/* @0x11a548 mov r4, r0 */
/* @0x11a54c bl 0x17af40 <_Z15GR_Window_Get_Xv> */
/* @0x11a550 vmov s15, r0 */
/* @0x11a554 vcvt.f64.s32 d7, s15 */
/* @0x11a558 vmov r0, r1, d7 */
/* @0x11a55c vmov r2, s14 */
/* @0x11a560 mov r3, r1 */
/* @0x11a564 stm r4, {r2, r3} */
/* @0x11a568 pop {r4, pc} */

/* ── FUNC 0x11a56c · F_WindowGetY(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x11a56c push {r4, lr} */
/* @0x11a570 mov r3, #0 */
/* @0x11a574 str r3, [r0, #0xc] */
/* @0x11a578 mov r4, r0 */
/* @0x11a57c bl 0x17af48 <_Z15GR_Window_Get_Yv> */
/* @0x11a580 vmov s15, r0 */
/* @0x11a584 vcvt.f64.s32 d7, s15 */
/* @0x11a588 vmov r0, r1, d7 */
/* @0x11a58c vmov r2, s14 */
/* @0x11a590 mov r3, r1 */
/* @0x11a594 stm r4, {r2, r3} */
/* @0x11a598 pop {r4, pc} */

/* ── FUNC 0x11a59c · F_WindowGetWidth(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x11a59c push {r4, lr} */
/* @0x11a5a0 mov r3, #0 */
/* @0x11a5a4 str r3, [r0, #0xc] */
/* @0x11a5a8 mov r4, r0 */
/* @0x11a5ac bl 0x17af50 <_Z19GR_Window_Get_Widthv> */
/* @0x11a5b0 vmov s15, r0 */
/* @0x11a5b4 vcvt.f64.s32 d7, s15 */
/* @0x11a5b8 vmov r0, r1, d7 */
/* @0x11a5bc vmov r2, s14 */
/* @0x11a5c0 mov r3, r1 */
/* @0x11a5c4 stm r4, {r2, r3} */
/* @0x11a5c8 pop {r4, pc} */

/* ── FUNC 0x11a5cc · F_WindowGetHeight(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x11a5cc push {r4, lr} */
/* @0x11a5d0 mov r3, #0 */
/* @0x11a5d4 str r3, [r0, #0xc] */
/* @0x11a5d8 mov r4, r0 */
/* @0x11a5dc bl 0x17af64 <_Z20GR_Window_Get_Heightv> */
/* @0x11a5e0 vmov s15, r0 */
/* @0x11a5e4 vcvt.f64.s32 d7, s15 */
/* @0x11a5e8 vmov r0, r1, d7 */
/* @0x11a5ec vmov r2, s14 */
/* @0x11a5f0 mov r3, r1 */
/* @0x11a5f4 stm r4, {r2, r3} */
/* @0x11a5f8 pop {r4, pc} */

/* ── FUNC 0x11a5fc · F_DisplayGetVisibleRects(RValue&, CInstance*, CInstance*, int, RValue*) · size=380 · insn=95 */
/* @0x11a5fc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11a600 sub sp, sp, #44 */
/* @0x11a604 mov r8, r0 */
/* @0x11a608 mov r1, #0 */
/* @0x11a60c ldr r9, [sp, #0x50] */
/* @0x11a610 mov r11, r1 */
/* @0x11a614 mov r10, #1 */
/* @0x11a618 mov r0, r9 */
/* @0x11a61c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x11a620 mov r4, r0 */
/* @0x11a624 mov r5, r1 */
/* @0x11a628 mov r0, r9 */
/* @0x11a62c mov r1, r10 */
/* @0x11a630 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x11a634 mov r2, r0 */
/* @0x11a638 mov r3, r1 */
/* @0x11a63c mov r0, r9 */
/* @0x11a640 mov r1, #2 */
/* @0x11a644 str r2, [sp, #0x1c] */
/* @0x11a648 str r3, [sp, #0x18] */
/* @0x11a64c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x11a650 mov r6, r0 */
/* @0x11a654 mov r7, r1 */
/* @0x11a658 mov r0, r9 */
/* @0x11a65c mov r1, #3 */
/* @0x11a660 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x11a664 add r12, sp, #40 */
/* @0x11a668 ldr r2, [sp, #0x1c] */
/* @0x11a66c strd r6, r7, [sp] */
/* @0x11a670 ldr r3, [sp, #0x18] */
/* @0x11a674 str r11, [r12, #-0x4]! */
/* @0x11a678 str r12, [sp, #0x10] */
/* @0x11a67c strd r0, r1, [sp, #8] */
/* @0x11a680 mov r1, r5 */
/* @0x11a684 mov r0, r4 */
/* @0x11a688 bl 0x17af78 <_Z28GR_Display_Get_Visible_RectsddddPPd> */
/* @0x11a68c mov r3, #2 */
/* @0x11a690 str r3, [r8, #0xc] */
/* @0x11a694 mov r4, r0 */
/* @0x11a698 mov r0, r8 */
/* @0x11a69c bl 0xced9c <_Z14ARRAY_RefAllocPv> */
/* @0x11a6a0 ldr r1, [pc, #0xc8] */
/* @0x11a6a4 mov r3, r10 */
/* @0x11a6a8 mov r2, #70 */
/* @0x11a6ac add r1, pc, r1 */
/* @0x11a6b0 lsl r6, r4, #3 */
/* @0x11a6b4 mov r5, r0 */
/* @0x11a6b8 str r0, [r8] */
/* @0x11a6bc str r10, [r5, #0x10] */
/* @0x11a6c0 mov r0, #8 */
/* @0x11a6c4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x11a6c8 ldr r1, [pc, #0xa4] */
/* @0x11a6cc mov r3, r10 */
/* @0x11a6d0 mov r2, #672 */
/* @0x11a6d4 add r1, pc, r1 */
/* @0x11a6d8 str r0, [r5, #0x4] */
/* @0x11a6dc lsl r0, r4, #7 */
/* @0x11a6e0 ldr r12, [r8] */
/* @0x11a6e4 ldr r5, [r12, #0x4] */
/* @0x11a6e8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x11a6ec cmp r6, r11 */
/* @0x11a6f0 str r0, [r5, #0x4] */
/* @0x11a6f4 ldr r3, [r8] */
/* @0x11a6f8 ldr r5, [sp, #0x24] */
/* @0x11a6fc ldr r1, [r3, #0x4] */
/* @0x11a700 str r6, [r1] */
/* @0x11a704 ble 0x11a758 <_Z24F_DisplayGetVisibleRectsR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x11a708 ldr r2, [r8] */
/* @0x11a70c mov r0, r11 */
/* @0x11a710 add r6, r5, r4, lsl #6 */
/* @0x11a714 mov r3, r5 */
/* @0x11a718 b 0x11a724 <_Z24F_DisplayGetVisibleRectsR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x11a71c ldr r2, [r8] */
/* @0x11a720 ldr r1, [r2, #0x4] */
/* @0x11a724 ldr r2, [r2, #0x4] */
/* @0x11a728 add r3, r3, #8 */
/* @0x11a72c ldr r4, [r1, #0x4] */
/* @0x11a730 ldr r12, [r3, #-0x8] */
/* @0x11a734 ldr r1, [r3, #-0x4] */
/* @0x11a738 add r4, r4, r11 */
/* @0x11a73c ldr r2, [r2, #0x4] */
/* @0x11a740 cmp r3, r6 */
/* @0x11a744 str r0, [r4, #0xc] */
/* @0x11a748 str r12, [r2, r11]! */
/* @0x11a74c add r11, r11, #16 */
/* @0x11a750 str r1, [r2, #0x4] */
/* @0x11a754 bne 0x11a71c <_Z24F_DisplayGetVisibleRectsR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x11a758 cmp r5, #0 */
/* @0x11a75c beq 0x11a768 <_Z24F_DisplayGetVisibleRectsR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x11a760 mov r0, r5 */
/* @0x11a764 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x11a768 add sp, sp, #44 */
/* @0x11a76c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11a770 eoreq r6, r1, r4, lsl #19 */
/* @0x11a774 eoreq pc, r1, r12, ror r8 */

/* ── FUNC 0x11a778 · F_WindowMouseGetX(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x11a778 push {r4, lr} */
/* @0x11a77c mov r3, #0 */
/* @0x11a780 str r3, [r0, #0xc] */
/* @0x11a784 mov r4, r0 */
/* @0x11a788 bl 0x17aab4 <_Z21GR_Window_Mouse_Get_Xv> */
/* @0x11a78c vmov s15, r0 */
/* @0x11a790 vcvt.f64.s32 d7, s15 */
/* @0x11a794 vmov r0, r1, d7 */
/* @0x11a798 vmov r2, s14 */
/* @0x11a79c mov r3, r1 */
/* @0x11a7a0 stm r4, {r2, r3} */
/* @0x11a7a4 pop {r4, pc} */

/* ── FUNC 0x11a7a8 · F_WindowMouseGetY(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x11a7a8 push {r4, lr} */
/* @0x11a7ac mov r3, #0 */
/* @0x11a7b0 str r3, [r0, #0xc] */
/* @0x11a7b4 mov r4, r0 */
/* @0x11a7b8 bl 0x17aac8 <_Z21GR_Window_Mouse_Get_Yv> */
/* @0x11a7bc vmov s15, r0 */
/* @0x11a7c0 vcvt.f64.s32 d7, s15 */
/* @0x11a7c4 vmov r0, r1, d7 */
/* @0x11a7c8 vmov r2, s14 */
/* @0x11a7cc mov r3, r1 */
/* @0x11a7d0 stm r4, {r2, r3} */
/* @0x11a7d4 pop {r4, pc} */

/* ── FUNC 0x11a7d8 · F_WindowMouseSet(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x11a7d8 push {r3, r4, r5, lr} */
/* @0x11a7dc mov r1, #0 */
/* @0x11a7e0 ldr r4, [sp, #0x10] */
/* @0x11a7e4 mov r0, r4 */
/* @0x11a7e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a7ec mov r1, #1 */
/* @0x11a7f0 mov r5, r0 */
/* @0x11a7f4 mov r0, r4 */
/* @0x11a7f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a7fc mov r1, r0 */
/* @0x11a800 mov r0, r5 */
/* @0x11a804 pop {r3, r4, r5, lr} */
/* @0x11a808 b 0x17af30 <_Z19GR_Window_Mouse_Setii> */

/* ── FUNC 0x11a80c · F_WindowViewMouseGetX(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x11a80c push {r4, lr} */
/* @0x11a810 mov r3, #0 */
/* @0x11a814 mov r1, r3 */
/* @0x11a818 str r3, [r0, #0xc] */
/* @0x11a81c mov r4, r0 */
/* @0x11a820 ldr r0, [sp, #0x8] */
/* @0x11a824 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a828 bl 0x17aa2c <_Z26GR_Window_View_Mouse_Get_Xi> */
/* @0x11a82c vmov s15, r0 */
/* @0x11a830 vcvt.f64.s32 d7, s15 */
/* @0x11a834 vmov r0, r1, d7 */
/* @0x11a838 vmov r2, s14 */
/* @0x11a83c mov r3, r1 */
/* @0x11a840 stm r4, {r2, r3} */
/* @0x11a844 pop {r4, pc} */

/* ── FUNC 0x11a848 · F_WindowViewMouseGetY(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x11a848 push {r4, lr} */
/* @0x11a84c mov r3, #0 */
/* @0x11a850 mov r1, r3 */
/* @0x11a854 str r3, [r0, #0xc] */
/* @0x11a858 mov r4, r0 */
/* @0x11a85c ldr r0, [sp, #0x8] */
/* @0x11a860 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a864 bl 0x17aa70 <_Z26GR_Window_View_Mouse_Get_Yi> */
/* @0x11a868 vmov s15, r0 */
/* @0x11a86c vcvt.f64.s32 d7, s15 */
/* @0x11a870 vmov r0, r1, d7 */
/* @0x11a874 vmov r2, s14 */
/* @0x11a878 mov r3, r1 */
/* @0x11a87c stm r4, {r2, r3} */
/* @0x11a880 pop {r4, pc} */

/* ── FUNC 0x11a884 · F_WindowViewsMouseGetX(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x11a884 mov r3, #0 */
/* @0x11a888 push {r4, lr} */
/* @0x11a88c mov r4, r0 */
/* @0x11a890 str r3, [r4, #0xc] */
/* @0x11a894 mov r0, r3 */
/* @0x11a898 bl 0x17ad8c <_Z27GR_Window_Views_Mouse_Get_Xi> */
/* @0x11a89c vmov s15, r0 */
/* @0x11a8a0 vcvt.f64.s32 d7, s15 */
/* @0x11a8a4 vmov r0, r1, d7 */
/* @0x11a8a8 vmov r2, s14 */
/* @0x11a8ac mov r3, r1 */
/* @0x11a8b0 stm r4, {r2, r3} */
/* @0x11a8b4 pop {r4, pc} */

/* ── FUNC 0x11a8b8 · F_WindowViewsMouseGetY(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x11a8b8 mov r3, #0 */
/* @0x11a8bc push {r4, lr} */
/* @0x11a8c0 mov r4, r0 */
/* @0x11a8c4 str r3, [r4, #0xc] */
/* @0x11a8c8 mov r0, r3 */
/* @0x11a8cc bl 0x17adb0 <_Z27GR_Window_Views_Mouse_Get_Yi> */
/* @0x11a8d0 vmov s15, r0 */
/* @0x11a8d4 vcvt.f64.s32 d7, s15 */
/* @0x11a8d8 vmov r0, r1, d7 */
/* @0x11a8dc vmov r2, s14 */
/* @0x11a8e0 mov r3, r1 */
/* @0x11a8e4 stm r4, {r2, r3} */
/* @0x11a8e8 pop {r4, pc} */

/* ── FUNC 0x11a8ec · F_DrawGetPixelExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x11a8ec push {r4, r5, r6, r7, r8, lr} */
/* @0x11a8f0 sub sp, sp, #16 */
/* @0x11a8f4 ldr r3, [pc, #0x80] */
/* @0x11a8f8 mov r4, #0 */
/* @0x11a8fc ldr r6, [sp, #0x28] */
/* @0x11a900 mov r5, r0 */
/* @0x11a904 ldr r3, [pc, r3] */
/* @0x11a908 mov r1, r4 */
/* @0x11a90c str r4, [sp, #0x8] */
/* @0x11a910 mov r0, r6 */
/* @0x11a914 ldr r7, [r3] */
/* @0x11a918 str r4, [sp, #0xc] */
/* @0x11a91c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11a920 mov r1, #1 */
/* @0x11a924 mov r8, r0 */
/* @0x11a928 mov r0, r6 */
/* @0x11a92c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11a930 add r3, sp, #8 */
/* @0x11a934 add r12, sp, #12 */
/* @0x11a938 mov r1, r8 */
/* @0x11a93c str r12, [sp] */
/* @0x11a940 mov r2, r0 */
/* @0x11a944 mov r0, r7 */
/* @0x11a948 bl 0x17a110 <_Z28GR_Window_View_Convert_WorldiffRiS_> */
/* @0x11a94c ldr r1, [sp, #0xc] */
/* @0x11a950 str r4, [r5, #0xc] */
/* @0x11a954 ldr r0, [sp, #0x8] */
/* @0x11a958 bl 0x169d00 <_Z15GR_D3D_GetPixelii> */
/* @0x11a95c vmov s15, r0 */
/* @0x11a960 vcvt.f64.u32 d7, s15 */
/* @0x11a964 vmov r0, r1, d7 */
/* @0x11a968 vmov r2, s14 */
/* @0x11a96c mov r3, r1 */
/* @0x11a970 stm r5, {r2, r3} */
/* @0x11a974 add sp, sp, #16 */
/* @0x11a978 pop {r4, r5, r6, r7, r8, pc} */
/* @0x11a97c eoreq r3, sp, r12, asr #25 */
