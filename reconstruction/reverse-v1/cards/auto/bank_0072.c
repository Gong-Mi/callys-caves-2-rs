/* libyoyo.so 覆盖卡组 0072
 * 函数 0x13c3c0..0x13dae8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x13c3c0 · F_ParameterCount(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x13c3c0 push {r4, lr} */
/* @0x13c3c4 mov r3, #0 */
/* @0x13c3c8 str r3, [r0, #0xc] */
/* @0x13c3cc mov r4, r0 */
/* @0x13c3d0 bl 0x13c3ac <_Z10ParamCountv> */
/* @0x13c3d4 vmov s15, r0 */
/* @0x13c3d8 vcvt.f64.s32 d7, s15 */
/* @0x13c3dc vmov r0, r1, d7 */
/* @0x13c3e0 vmov r2, s14 */
/* @0x13c3e4 mov r3, r1 */
/* @0x13c3e8 stm r4, {r2, r3} */
/* @0x13c3ec pop {r4, pc} */

/* ── FUNC 0x13c3f0 · ParamStr(char const*&, int) · size=80 · insn=20 */
/* @0x13c3f0 cmp r1, #0 */
/* @0x13c3f4 push {r4, lr} */
/* @0x13c3f8 mov r4, r0 */
/* @0x13c3fc blt 0x13c414 <_Z8ParamStrRPKci+0x24> */
/* @0x13c400 ldr r3, [pc, #0x30] */
/* @0x13c404 ldr r3, [pc, r3] */
/* @0x13c408 ldr r3, [r3] */
/* @0x13c40c cmp r1, r3 */
/* @0x13c410 blt 0x13c420 <_Z8ParamStrRPKci+0x30> */
/* @0x13c414 mov r3, #0 */
/* @0x13c418 str r3, [r4] */
/* @0x13c41c pop {r4, pc} */
/* @0x13c420 ldr r3, [pc, #0x14] */
/* @0x13c424 ldr r3, [pc, r3] */
/* @0x13c428 ldr r0, [r3, r1, lsl #2] */
/* @0x13c42c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x13c430 str r0, [r4] */
/* @0x13c434 pop {r4, pc} */
/* @0x13c438 mlaeq r11, r12, lr, r2 */
/* @0x13c43c eoreq r2, r11, r0, lsl #29 */

/* ── FUNC 0x13c440 · F_ParameterString(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x13c440 push {r4, r5, lr} */
/* @0x13c444 sub sp, sp, #12 */
/* @0x13c448 add r4, sp, #8 */
/* @0x13c44c mov r1, #0 */
/* @0x13c450 mov r5, r0 */
/* @0x13c454 ldr r0, [sp, #0x18] */
/* @0x13c458 str r1, [r4, #-0x4]! */
/* @0x13c45c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13c460 mov r1, r0 */
/* @0x13c464 mov r0, r4 */
/* @0x13c468 bl 0x13c3f0 <_Z8ParamStrRPKci> */
/* @0x13c46c mov r0, r5 */
/* @0x13c470 ldr r1, [sp, #0x4] */
/* @0x13c474 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x13c478 ldr r0, [sp, #0x4] */
/* @0x13c47c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x13c480 add sp, sp, #12 */
/* @0x13c484 pop {r4, r5, pc} */

/* ── FUNC 0x13c488 · GetSecure() · size=24 · insn=6 */
/* @0x13c488 ldr r3, [pc, #0xc] */
/* @0x13c48c mov r2, #0 */
/* @0x13c490 ldr r3, [pc, r3] */
/* @0x13c494 strb r2, [r3] */
/* @0x13c498 bx lr */
/* @0x13c49c eoreq r2, r11, r8, lsl lr */

/* ── FUNC 0x13c4a0 · InitFileFunctions() · size=2660 · insn=665 */
/* @0x13c4a0 push {r4, lr} */
/* @0x13c4a4 bl 0x13c488 <_Z9GetSecurev> */
/* @0x13c4a8 ldr r4, [pc, #0x808] */
/* @0x13c4ac bl 0x13b830 <_Z12InitBinFilesv> */
/* @0x13c4b0 bl 0x13b874 <_Z13InitTextFilesv> */
/* @0x13c4b4 ldr r1, [pc, #0x800] */
/* @0x13c4b8 add r4, pc, r4 */
/* @0x13c4bc ldr r0, [pc, #0x7fc] */
/* @0x13c4c0 mov r2, #2 */
/* @0x13c4c4 mov r3, #0 */
/* @0x13c4c8 ldr r1, [r4, r1] */
/* @0x13c4cc add r0, pc, r0 */
/* @0x13c4d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c4d4 ldr r1, [pc, #0x7e8] */
/* @0x13c4d8 ldr r0, [pc, #0x7e8] */
/* @0x13c4dc mov r2, #1 */
/* @0x13c4e0 mov r3, #0 */
/* @0x13c4e4 ldr r1, [r4, r1] */
/* @0x13c4e8 add r0, pc, r0 */
/* @0x13c4ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c4f0 ldr r1, [pc, #0x7d4] */
/* @0x13c4f4 ldr r0, [pc, #0x7d4] */
/* @0x13c4f8 mov r2, #1 */
/* @0x13c4fc mov r3, #0 */
/* @0x13c500 ldr r1, [r4, r1] */
/* @0x13c504 add r0, pc, r0 */
/* @0x13c508 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c50c ldr r1, [pc, #0x7c0] */
/* @0x13c510 ldr r0, [pc, #0x7c0] */
/* @0x13c514 mov r2, #1 */
/* @0x13c518 mov r3, #0 */
/* @0x13c51c ldr r1, [r4, r1] */
/* @0x13c520 add r0, pc, r0 */
/* @0x13c524 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c528 ldr r1, [pc, #0x7ac] */
/* @0x13c52c ldr r0, [pc, #0x7ac] */
/* @0x13c530 mov r2, #1 */
/* @0x13c534 mov r3, #0 */
/* @0x13c538 ldr r1, [r4, r1] */
/* @0x13c53c add r0, pc, r0 */
/* @0x13c540 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c544 ldr r1, [pc, #0x798] */
/* @0x13c548 ldr r0, [pc, #0x798] */
/* @0x13c54c mov r2, #2 */
/* @0x13c550 mov r3, #0 */
/* @0x13c554 ldr r1, [r4, r1] */
/* @0x13c558 add r0, pc, r0 */
/* @0x13c55c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c560 ldr r1, [pc, #0x784] */
/* @0x13c564 ldr r0, [pc, #0x784] */
/* @0x13c568 mov r2, #1 */
/* @0x13c56c mov r3, #0 */
/* @0x13c570 ldr r1, [r4, r1] */
/* @0x13c574 add r0, pc, r0 */
/* @0x13c578 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c57c ldr r1, [pc, #0x770] */
/* @0x13c580 ldr r0, [pc, #0x770] */
/* @0x13c584 mov r2, #2 */
/* @0x13c588 mov r3, #0 */
/* @0x13c58c ldr r1, [r4, r1] */
/* @0x13c590 add r0, pc, r0 */
/* @0x13c594 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c598 ldr r1, [pc, #0x75c] */
/* @0x13c59c ldr r0, [pc, #0x75c] */
/* @0x13c5a0 mov r2, #1 */
/* @0x13c5a4 mov r3, #0 */
/* @0x13c5a8 ldr r1, [r4, r1] */
/* @0x13c5ac add r0, pc, r0 */
/* @0x13c5b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c5b4 ldr r1, [pc, #0x748] */
/* @0x13c5b8 ldr r0, [pc, #0x748] */
/* @0x13c5bc mov r2, #1 */
/* @0x13c5c0 mov r3, #0 */
/* @0x13c5c4 ldr r1, [r4, r1] */
/* @0x13c5c8 add r0, pc, r0 */
/* @0x13c5cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c5d0 ldr r1, [pc, #0x734] */
/* @0x13c5d4 ldr r0, [pc, #0x734] */
/* @0x13c5d8 mov r2, #1 */
/* @0x13c5dc mov r3, #0 */
/* @0x13c5e0 ldr r1, [r4, r1] */
/* @0x13c5e4 add r0, pc, r0 */
/* @0x13c5e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c5ec ldr r1, [pc, #0x720] */
/* @0x13c5f0 ldr r0, [pc, #0x720] */
/* @0x13c5f4 mov r2, #1 */
/* @0x13c5f8 mov r3, #0 */
/* @0x13c5fc ldr r1, [r4, r1] */
/* @0x13c600 add r0, pc, r0 */
/* @0x13c604 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c608 ldr r1, [pc, #0x70c] */
/* @0x13c60c ldr r0, [pc, #0x70c] */
/* @0x13c610 mov r2, #1 */
/* @0x13c614 mov r3, #0 */
/* @0x13c618 ldr r1, [r4, r1] */
/* @0x13c61c add r0, pc, r0 */
/* @0x13c620 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c624 ldr r1, [pc, #0x6f8] */
/* @0x13c628 ldr r0, [pc, #0x6f8] */
/* @0x13c62c mov r2, #1 */
/* @0x13c630 mov r3, #0 */
/* @0x13c634 ldr r1, [r4, r1] */
/* @0x13c638 add r0, pc, r0 */
/* @0x13c63c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c640 ldr r1, [pc, #0x6e4] */
/* @0x13c644 ldr r0, [pc, #0x6e4] */
/* @0x13c648 mov r2, #1 */
/* @0x13c64c mov r3, #0 */
/* @0x13c650 ldr r1, [r4, r1] */
/* @0x13c654 add r0, pc, r0 */
/* @0x13c658 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c65c ldr r1, [pc, #0x6d0] */
/* @0x13c660 ldr r0, [pc, #0x6d0] */
/* @0x13c664 mov r2, #1 */
/* @0x13c668 mov r3, #0 */
/* @0x13c66c ldr r1, [r4, r1] */
/* @0x13c670 add r0, pc, r0 */
/* @0x13c674 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c678 ldr r1, [pc, #0x6bc] */
/* @0x13c67c ldr r0, [pc, #0x6bc] */
/* @0x13c680 mov r2, #1 */
/* @0x13c684 mov r3, #0 */
/* @0x13c688 ldr r1, [r4, r1] */
/* @0x13c68c add r0, pc, r0 */
/* @0x13c690 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c694 ldr r1, [pc, #0x6a8] */
/* @0x13c698 ldr r0, [pc, #0x6a8] */
/* @0x13c69c mov r2, #1 */
/* @0x13c6a0 mov r3, #0 */
/* @0x13c6a4 ldr r1, [r4, r1] */
/* @0x13c6a8 add r0, pc, r0 */
/* @0x13c6ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c6b0 ldr r1, [pc, #0x694] */
/* @0x13c6b4 ldr r0, [pc, #0x694] */
/* @0x13c6b8 mov r2, #2 */
/* @0x13c6bc mov r3, #0 */
/* @0x13c6c0 ldr r1, [r4, r1] */
/* @0x13c6c4 add r0, pc, r0 */
/* @0x13c6c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c6cc ldr r1, [pc, #0x680] */
/* @0x13c6d0 ldr r0, [pc, #0x680] */
/* @0x13c6d4 mov r2, #2 */
/* @0x13c6d8 mov r3, #0 */
/* @0x13c6dc ldr r1, [r4, r1] */
/* @0x13c6e0 add r0, pc, r0 */
/* @0x13c6e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c6e8 ldr r1, [pc, #0x66c] */
/* @0x13c6ec ldr r0, [pc, #0x66c] */
/* @0x13c6f0 mov r2, #1 */
/* @0x13c6f4 mov r3, #0 */
/* @0x13c6f8 ldr r1, [r4, r1] */
/* @0x13c6fc add r0, pc, r0 */
/* @0x13c700 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c704 ldr r1, [pc, #0x658] */
/* @0x13c708 ldr r0, [pc, #0x658] */
/* @0x13c70c mov r2, #1 */
/* @0x13c710 mov r3, #0 */
/* @0x13c714 ldr r1, [r4, r1] */
/* @0x13c718 add r0, pc, r0 */
/* @0x13c71c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c720 ldr r1, [pc, #0x644] */
/* @0x13c724 ldr r0, [pc, #0x644] */
/* @0x13c728 mov r2, #1 */
/* @0x13c72c mov r3, #0 */
/* @0x13c730 ldr r1, [r4, r1] */
/* @0x13c734 add r0, pc, r0 */
/* @0x13c738 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c73c ldr r1, [pc, #0x630] */
/* @0x13c740 ldr r0, [pc, #0x630] */
/* @0x13c744 mov r2, #1 */
/* @0x13c748 mov r3, #0 */
/* @0x13c74c ldr r1, [r4, r1] */
/* @0x13c750 add r0, pc, r0 */
/* @0x13c754 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c758 ldr r1, [pc, #0x61c] */
/* @0x13c75c ldr r0, [pc, #0x61c] */
/* @0x13c760 mov r2, #0 */
/* @0x13c764 mov r3, r2 */
/* @0x13c768 ldr r1, [r4, r1] */
/* @0x13c76c add r0, pc, r0 */
/* @0x13c770 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c774 ldr r1, [pc, #0x608] */
/* @0x13c778 ldr r0, [pc, #0x608] */
/* @0x13c77c mov r2, #0 */
/* @0x13c780 mov r3, r2 */
/* @0x13c784 ldr r1, [r4, r1] */
/* @0x13c788 add r0, pc, r0 */
/* @0x13c78c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c790 ldr r1, [pc, #0x5f4] */
/* @0x13c794 ldr r0, [pc, #0x5f4] */
/* @0x13c798 mov r2, #0 */
/* @0x13c79c mov r3, r2 */
/* @0x13c7a0 ldr r1, [r4, r1] */
/* @0x13c7a4 add r0, pc, r0 */
/* @0x13c7a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c7ac ldr r1, [pc, #0x5e0] */
/* @0x13c7b0 ldr r0, [pc, #0x5e0] */
/* @0x13c7b4 mov r2, #0 */
/* @0x13c7b8 mov r3, r2 */
/* @0x13c7bc ldr r1, [r4, r1] */
/* @0x13c7c0 add r0, pc, r0 */
/* @0x13c7c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c7c8 ldr r1, [pc, #0x5cc] */
/* @0x13c7cc ldr r0, [pc, #0x5cc] */
/* @0x13c7d0 mov r2, #0 */
/* @0x13c7d4 mov r3, r2 */
/* @0x13c7d8 ldr r1, [r4, r1] */
/* @0x13c7dc add r0, pc, r0 */
/* @0x13c7e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c7e4 ldr r1, [pc, #0x5b8] */
/* @0x13c7e8 ldr r0, [pc, #0x5b8] */
/* @0x13c7ec mov r2, #1 */
/* @0x13c7f0 mov r3, #0 */
/* @0x13c7f4 ldr r1, [r4, r1] */
/* @0x13c7f8 add r0, pc, r0 */
/* @0x13c7fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c800 ldr r1, [pc, #0x5a4] */
/* @0x13c804 ldr r0, [pc, #0x5a4] */
/* @0x13c808 mov r2, #1 */
/* @0x13c80c mov r3, #0 */
/* @0x13c810 ldr r1, [r4, r1] */
/* @0x13c814 add r0, pc, r0 */
/* @0x13c818 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c81c ldr r1, [pc, #0x590] */
/* @0x13c820 ldr r0, [pc, #0x590] */
/* @0x13c824 mov r2, #0 */
/* @0x13c828 mov r3, r2 */
/* @0x13c82c ldr r1, [r4, r1] */
/* @0x13c830 add r0, pc, r0 */
/* @0x13c834 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c838 ldr r1, [pc, #0x57c] */
/* @0x13c83c ldr r0, [pc, #0x57c] */
/* @0x13c840 mov r2, #1 */
/* @0x13c844 mov r3, #0 */
/* @0x13c848 ldr r1, [r4, r1] */
/* @0x13c84c add r0, pc, r0 */
/* @0x13c850 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c854 ldr r1, [pc, #0x568] */
/* @0x13c858 ldr r0, [pc, #0x568] */
/* @0x13c85c mov r2, #1 */
/* @0x13c860 mov r3, #0 */
/* @0x13c864 ldr r1, [r4, r1] */
/* @0x13c868 add r0, pc, r0 */
/* @0x13c86c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c870 ldr r1, [pc, #0x554] */
/* @0x13c874 ldr r0, [pc, #0x554] */
/* @0x13c878 mov r2, #2 */
/* @0x13c87c mov r3, #0 */
/* @0x13c880 ldr r1, [r4, r1] */
/* @0x13c884 add r0, pc, r0 */
/* @0x13c888 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c88c ldr r1, [pc, #0x540] */
/* @0x13c890 ldr r0, [pc, #0x540] */
/* @0x13c894 mov r2, #2 */
/* @0x13c898 mov r3, #0 */
/* @0x13c89c ldr r1, [r4, r1] */
/* @0x13c8a0 add r0, pc, r0 */
/* @0x13c8a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c8a8 ldr r1, [pc, #0x52c] */
/* @0x13c8ac ldr r0, [pc, #0x52c] */
/* @0x13c8b0 mov r2, #1 */
/* @0x13c8b4 mov r3, #0 */
/* @0x13c8b8 ldr r1, [r4, r1] */
/* @0x13c8bc add r0, pc, r0 */
/* @0x13c8c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c8c4 ldr r1, [pc, #0x518] */
/* @0x13c8c8 ldr r0, [pc, #0x518] */
/* @0x13c8cc mov r2, #1 */
/* @0x13c8d0 mov r3, #0 */
/* @0x13c8d4 ldr r1, [r4, r1] */
/* @0x13c8d8 add r0, pc, r0 */
/* @0x13c8dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c8e0 ldr r1, [pc, #0x504] */
/* @0x13c8e4 ldr r0, [pc, #0x504] */
/* @0x13c8e8 mov r2, #1 */
/* @0x13c8ec mov r3, #0 */
/* @0x13c8f0 ldr r1, [r4, r1] */
/* @0x13c8f4 add r0, pc, r0 */
/* @0x13c8f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c8fc ldr r1, [pc, #0x4f0] */
/* @0x13c900 ldr r0, [pc, #0x4f0] */
/* @0x13c904 mov r2, #2 */
/* @0x13c908 mov r3, #0 */
/* @0x13c90c ldr r1, [r4, r1] */
/* @0x13c910 add r0, pc, r0 */
/* @0x13c914 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c918 ldr r1, [pc, #0x4dc] */
/* @0x13c91c ldr r0, [pc, #0x4dc] */
/* @0x13c920 mov r2, #0 */
/* @0x13c924 mov r3, r2 */
/* @0x13c928 ldr r1, [r4, r1] */
/* @0x13c92c add r0, pc, r0 */
/* @0x13c930 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c934 ldr r1, [pc, #0x4c8] */
/* @0x13c938 ldr r0, [pc, #0x4c8] */
/* @0x13c93c mov r2, #0 */
/* @0x13c940 mov r3, r2 */
/* @0x13c944 ldr r1, [r4, r1] */
/* @0x13c948 add r0, pc, r0 */
/* @0x13c94c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c950 ldr r1, [pc, #0x4b4] */
/* @0x13c954 ldr r0, [pc, #0x4b4] */
/* @0x13c958 mov r2, #2 */
/* @0x13c95c mov r3, #0 */
/* @0x13c960 ldr r1, [r4, r1] */
/* @0x13c964 add r0, pc, r0 */
/* @0x13c968 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c96c ldr r1, [pc, #0x4a0] */
/* @0x13c970 ldr r0, [pc, #0x4a0] */
/* @0x13c974 mov r2, #1 */
/* @0x13c978 mov r3, #0 */
/* @0x13c97c ldr r1, [r4, r1] */
/* @0x13c980 add r0, pc, r0 */
/* @0x13c984 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c988 ldr r1, [pc, #0x48c] */
/* @0x13c98c ldr r0, [pc, #0x48c] */
/* @0x13c990 mov r2, #1 */
/* @0x13c994 mov r3, #0 */
/* @0x13c998 ldr r1, [r4, r1] */
/* @0x13c99c add r0, pc, r0 */
/* @0x13c9a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c9a4 ldr r1, [pc, #0x478] */
/* @0x13c9a8 ldr r0, [pc, #0x478] */
/* @0x13c9ac mov r2, #1 */
/* @0x13c9b0 mov r3, #0 */
/* @0x13c9b4 ldr r1, [r4, r1] */
/* @0x13c9b8 add r0, pc, r0 */
/* @0x13c9bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c9c0 ldr r1, [pc, #0x464] */
/* @0x13c9c4 ldr r0, [pc, #0x464] */
/* @0x13c9c8 mov r2, #1 */
/* @0x13c9cc mov r3, #0 */
/* @0x13c9d0 ldr r1, [r4, r1] */
/* @0x13c9d4 add r0, pc, r0 */
/* @0x13c9d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c9dc ldr r1, [pc, #0x450] */
/* @0x13c9e0 ldr r0, [pc, #0x450] */
/* @0x13c9e4 mov r2, #1 */
/* @0x13c9e8 mov r3, #0 */
/* @0x13c9ec ldr r1, [r4, r1] */
/* @0x13c9f0 add r0, pc, r0 */
/* @0x13c9f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13c9f8 ldr r1, [pc, #0x43c] */
/* @0x13c9fc ldr r0, [pc, #0x43c] */
/* @0x13ca00 mov r2, #2 */
/* @0x13ca04 mov r3, #0 */
/* @0x13ca08 ldr r1, [r4, r1] */
/* @0x13ca0c add r0, pc, r0 */
/* @0x13ca10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13ca14 ldr r1, [pc, #0x428] */
/* @0x13ca18 ldr r0, [pc, #0x428] */
/* @0x13ca1c mov r2, #3 */
/* @0x13ca20 mov r3, #0 */
/* @0x13ca24 ldr r1, [r4, r1] */
/* @0x13ca28 add r0, pc, r0 */
/* @0x13ca2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13ca30 ldr r1, [pc, #0x414] */
/* @0x13ca34 ldr r0, [pc, #0x414] */
/* @0x13ca38 mov r2, #2 */
/* @0x13ca3c mov r3, #0 */
/* @0x13ca40 ldr r1, [r4, r1] */
/* @0x13ca44 add r0, pc, r0 */
/* @0x13ca48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13ca4c ldr r1, [pc, #0x400] */
/* @0x13ca50 ldr r0, [pc, #0x400] */
/* @0x13ca54 mov r2, #0 */
/* @0x13ca58 mov r3, r2 */
/* @0x13ca5c ldr r1, [r4, r1] */
/* @0x13ca60 add r0, pc, r0 */
/* @0x13ca64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13ca68 ldr r1, [pc, #0x3ec] */
/* @0x13ca6c ldr r0, [pc, #0x3ec] */
/* @0x13ca70 mov r2, #1 */
/* @0x13ca74 mov r3, #0 */
/* @0x13ca78 ldr r1, [r4, r1] */
/* @0x13ca7c add r0, pc, r0 */
/* @0x13ca80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13ca84 ldr r1, [pc, #0x3d8] */
/* @0x13ca88 ldr r0, [pc, #0x3d8] */
/* @0x13ca8c mov r2, #1 */
/* @0x13ca90 mov r3, #0 */
/* @0x13ca94 ldr r1, [r4, r1] */
/* @0x13ca98 add r0, pc, r0 */
/* @0x13ca9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13caa0 ldr r1, [pc, #0x3c4] */
/* @0x13caa4 ldr r0, [pc, #0x3c4] */
/* @0x13caa8 mov r2, #1 */
/* @0x13caac mov r3, #0 */
/* @0x13cab0 ldr r1, [r4, r1] */
/* @0x13cab4 add r0, pc, r0 */
/* @0x13cab8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13cabc ldr r1, [pc, #0x3b0] */
/* @0x13cac0 ldr r0, [pc, #0x3b0] */
/* @0x13cac4 mov r2, #1 */
/* @0x13cac8 mov r3, #0 */
/* @0x13cacc ldr r1, [r4, r1] */
/* @0x13cad0 add r0, pc, r0 */
/* @0x13cad4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13cad8 ldr r1, [pc, #0x39c] */
/* @0x13cadc ldr r0, [pc, #0x39c] */
/* @0x13cae0 mov r2, #0 */
/* @0x13cae4 mov r3, r2 */
/* @0x13cae8 ldr r1, [r4, r1] */
/* @0x13caec add r0, pc, r0 */
/* @0x13caf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13caf4 ldr r1, [pc, #0x388] */
/* @0x13caf8 ldr r0, [pc, #0x388] */
/* @0x13cafc mov r2, #3 */
/* @0x13cb00 mov r3, #0 */
/* @0x13cb04 ldr r1, [r4, r1] */
/* @0x13cb08 add r0, pc, r0 */
/* @0x13cb0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13cb10 ldr r1, [pc, #0x374] */
/* @0x13cb14 ldr r0, [pc, #0x374] */
/* @0x13cb18 mov r2, #3 */
/* @0x13cb1c mov r3, #0 */
/* @0x13cb20 ldr r1, [r4, r1] */
/* @0x13cb24 add r0, pc, r0 */
/* @0x13cb28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13cb2c ldr r1, [pc, #0x360] */
/* @0x13cb30 ldr r0, [pc, #0x360] */
/* @0x13cb34 mov r2, #3 */
/* @0x13cb38 mov r3, #0 */
/* @0x13cb3c ldr r1, [r4, r1] */
/* @0x13cb40 add r0, pc, r0 */
/* @0x13cb44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13cb48 ldr r1, [pc, #0x34c] */
/* @0x13cb4c ldr r0, [pc, #0x34c] */
/* @0x13cb50 mov r2, #3 */
/* @0x13cb54 mov r3, #0 */
/* @0x13cb58 ldr r1, [r4, r1] */
/* @0x13cb5c add r0, pc, r0 */
/* @0x13cb60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13cb64 ldr r1, [pc, #0x338] */
/* @0x13cb68 ldr r0, [pc, #0x338] */
/* @0x13cb6c mov r2, #2 */
/* @0x13cb70 mov r3, #0 */
/* @0x13cb74 ldr r1, [r4, r1] */
/* @0x13cb78 add r0, pc, r0 */
/* @0x13cb7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13cb80 ldr r1, [pc, #0x324] */
/* @0x13cb84 ldr r0, [pc, #0x324] */
/* @0x13cb88 mov r2, #1 */
/* @0x13cb8c mov r3, #0 */
/* @0x13cb90 ldr r1, [r4, r1] */
/* @0x13cb94 add r0, pc, r0 */
/* @0x13cb98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13cb9c ldr r1, [pc, #0x310] */
/* @0x13cba0 ldr r0, [pc, #0x310] */
/* @0x13cba4 mov r2, #2 */
/* @0x13cba8 mov r3, #0 */
/* @0x13cbac ldr r1, [r4, r1] */
/* @0x13cbb0 add r0, pc, r0 */
/* @0x13cbb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13cbb8 ldr r1, [pc, #0x2fc] */
/* @0x13cbbc ldr r0, [pc, #0x2fc] */
/* @0x13cbc0 mov r2, #1 */
/* @0x13cbc4 mov r3, #0 */
/* @0x13cbc8 ldr r1, [r4, r1] */
/* @0x13cbcc add r0, pc, r0 */
/* @0x13cbd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13cbd4 ldr r1, [pc, #0x2e8] */
/* @0x13cbd8 ldr r0, [pc, #0x2e8] */
/* @0x13cbdc mov r2, #2 */
/* @0x13cbe0 mov r3, #0 */
/* @0x13cbe4 ldr r1, [r4, r1] */
/* @0x13cbe8 add r0, pc, r0 */
/* @0x13cbec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13cbf0 ldr r1, [pc, #0x2d4] */
/* @0x13cbf4 ldr r0, [pc, #0x2d4] */
/* @0x13cbf8 mov r2, #1 */
/* @0x13cbfc mov r3, #0 */
/* @0x13cc00 ldr r1, [r4, r1] */
/* @0x13cc04 add r0, pc, r0 */
/* @0x13cc08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13cc0c ldr r1, [pc, #0x2c0] */
/* @0x13cc10 ldr r0, [pc, #0x2c0] */
/* @0x13cc14 mov r2, #2 */
/* @0x13cc18 mov r3, #0 */
/* @0x13cc1c ldr r1, [r4, r1] */
/* @0x13cc20 add r0, pc, r0 */
/* @0x13cc24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13cc28 ldr r1, [pc, #0x2ac] */
/* @0x13cc2c ldr r0, [pc, #0x2ac] */
/* @0x13cc30 mov r2, #4 */
/* @0x13cc34 mov r3, #0 */
/* @0x13cc38 ldr r1, [r4, r1] */
/* @0x13cc3c add r0, pc, r0 */
/* @0x13cc40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13cc44 ldr r1, [pc, #0x298] */
/* @0x13cc48 ldr r0, [pc, #0x298] */
/* @0x13cc4c mov r2, #1 */
/* @0x13cc50 mov r3, #0 */
/* @0x13cc54 ldr r1, [r4, r1] */
/* @0x13cc58 add r0, pc, r0 */
/* @0x13cc5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13cc60 ldr r1, [pc, #0x284] */
/* @0x13cc64 ldr r0, [pc, #0x284] */
/* @0x13cc68 mov r2, #1 */
/* @0x13cc6c mov r3, #0 */
/* @0x13cc70 ldr r1, [r4, r1] */
/* @0x13cc74 add r0, pc, r0 */
/* @0x13cc78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13cc7c ldr r1, [pc, #0x270] */
/* @0x13cc80 ldr r0, [pc, #0x270] */
/* @0x13cc84 mov r2, #2 */
/* @0x13cc88 mov r3, #0 */
/* @0x13cc8c ldr r1, [r4, r1] */
/* @0x13cc90 add r0, pc, r0 */
/* @0x13cc94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13cc98 ldr r1, [pc, #0x25c] */
/* @0x13cc9c ldr r0, [pc, #0x25c] */
/* @0x13cca0 mov r2, #1 */
/* @0x13cca4 mov r3, r2 */
/* @0x13cca8 ldr r1, [r4, r1] */
/* @0x13ccac add r0, pc, r0 */
/* @0x13ccb0 pop {r4, lr} */
/* @0x13ccb4 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13ccb8 mlaeq r11, r8, r7, r5 */
/* @0x13ccbc .word 0xffffd65c */
/* @0x13ccc0 eoreq r3, r0, r12, ror #29 */
/* @0x13ccc4 .word 0xffffd660 */
/* @0x13ccc8 eoreq r3, r0, r0, ror #29 */
/* @0x13cccc .word 0xffffd664 */
/* @0x13ccd0 .word 0x00203ed8 */
/* @0x13ccd4 .word 0xffffd668 */
/* @0x13ccd8 eoreq r3, r0, r12, asr #29 */
/* @0x13ccdc .word 0xffffd66c */
/* @0x13cce0 eoreq r3, r0, r4, asr #29 */
/* @0x13cce4 .word 0xffffd670 */
/* @0x13cce8 .word 0x00203eb8 */
/* @0x13ccec .word 0xffffd674 */
/* @0x13ccf0 eoreq r3, r0, r12, lsr #29 */
/* @0x13ccf4 .word 0xffffd678 */
/* @0x13ccf8 eoreq r3, r0, r4, lsr #29 */
/* @0x13ccfc .word 0xffffd67c */
/* @0x13cd00 mlaeq r0, r12, lr, r3 */
/* @0x13cd04 .word 0xffffd680 */
/* @0x13cd08 mlaeq r0, r12, lr, r3 */
/* @0x13cd0c .word 0xffffd684 */
/* @0x13cd10 mlaeq r0, r4, lr, r3 */
/* @0x13cd14 .word 0xffffd688 */
/* @0x13cd18 mlaeq r0, r0, lr, r3 */
/* @0x13cd1c .word 0xffffd68c */
/* @0x13cd20 eoreq r3, r0, r12, lsl #29 */
/* @0x13cd24 .word 0xffffd690 */
/* @0x13cd28 eoreq r3, r0, r0, lsl #29 */
/* @0x13cd2c .word 0xffffd694 */
/* @0x13cd30 eoreq r3, r0, r12, ror lr */
/* @0x13cd34 .word 0xffffd698 */
/* @0x13cd38 eoreq r3, r0, r4, ror lr */
/* @0x13cd3c .word 0xffffd69c */
/* @0x13cd40 eoreq r3, r0, r12, ror #28 */
/* @0x13cd44 .word 0xffffd6a0 */
/* @0x13cd48 eoreq r3, r0, r0, ror #28 */
/* @0x13cd4c .word 0xffffd6a4 */
/* @0x13cd50 eoreq r3, r0, r4, asr lr */
/* @0x13cd54 .word 0xffffd6a8 */
/* @0x13cd58 eoreq r3, r0, r0, asr lr */
/* @0x13cd5c .word 0xffffd6ac */
/* @0x13cd60 eoreq r3, r0, r12, asr #28 */
/* @0x13cd64 .word 0xffffd6b0 */
/* @0x13cd68 eoreq r3, r0, r4, asr #28 */
/* @0x13cd6c .word 0xffffd6b4 */
/* @0x13cd70 eoreq r3, r0, r8, lsr lr */
/* @0x13cd74 .word 0xffffd6b8 */
/* @0x13cd78 eoreq r3, r0, r12, lsr #28 */
/* @0x13cd7c .word 0xffffd6bc */
/* @0x13cd80 eoreq r3, r0, r4, lsr #28 */
/* @0x13cd84 .word 0xffffd6c0 */
/* @0x13cd88 eoreq r3, r0, r4, lsl lr */
/* @0x13cd8c .word 0xffffd6c4 */
/* @0x13cd90 eoreq r3, r0, r12, lsl #28 */
/* @0x13cd94 .word 0xffffd6c8 */
/* @0x13cd98 eoreq r3, r0, r0, lsl #28 */
/* @0x13cd9c .word 0xffffd6cc */
/* @0x13cda0 .word 0x00203df0 */
/* @0x13cda4 .word 0xffffd6d0 */
/* @0x13cda8 eoreq r3, r0, r0, ror #27 */
/* @0x13cdac .word 0xffffd6d4 */
/* @0x13cdb0 .word 0x00203dd8 */
/* @0x13cdb4 .word 0xffffd6d8 */
/* @0x13cdb8 eoreq r3, r0, r12, asr #27 */
/* @0x13cdbc .word 0xffffd6dc */
/* @0x13cdc0 eoreq r3, r0, r0, asr #27 */
/* @0x13cdc4 .word 0xffffd6e0 */
/* @0x13cdc8 .word 0x00203db0 */
/* @0x13cdcc .word 0xffffd6e4 */
/* @0x13cdd0 eoreq r3, r0, r0, lsr #27 */
/* @0x13cdd4 .word 0xffffd6e8 */
/* @0x13cdd8 mlaeq r0, r0, sp, r3 */
/* @0x13cddc .word 0xffffd6ec */
/* @0x13cde0 eoreq r3, r0, r0, lsl #27 */
/* @0x13cde4 .word 0xffffd6f0 */
/* @0x13cde8 eoreq r3, r0, r8, ror sp */
/* @0x13cdec .word 0xffffd6f4 */
/* @0x13cdf0 eoreq r3, r0, r0, ror sp */
/* @0x13cdf4 .word 0xffffd6f8 */
/* @0x13cdf8 eoreq r3, r0, r8, ror #26 */
/* @0x13cdfc .word 0xffffd6fc */
/* @0x13ce00 eoreq r3, r0, r12, asr sp */
/* @0x13ce04 .word 0xffffd700 */
/* @0x13ce08 eoreq r3, r0, r0, asr sp */
/* @0x13ce0c .word 0xffffd704 */
/* @0x13ce10 eoreq r3, r0, r4, asr #26 */
/* @0x13ce14 .word 0xffffd708 */
/* @0x13ce18 eoreq r3, r0, r8, lsr sp */
/* @0x13ce1c .word 0xffffd70c */
/* @0x13ce20 eoreq r3, r0, r12, lsr #26 */
/* @0x13ce24 .word 0xffffd710 */
/* @0x13ce28 eoreq r3, r0, r0, lsr #26 */
/* @0x13ce2c .word 0xffffd714 */
/* @0x13ce30 eoreq r3, r0, r4, lsl sp */
/* @0x13ce34 .word 0xffffd718 */
/* @0x13ce38 eoreq r3, r0, r8, lsl #26 */
/* @0x13ce3c .word 0xffffd71c */
/* @0x13ce40 .word 0x00203cfc */
/* @0x13ce44 .word 0xffffd720 */
/* @0x13ce48 .word 0x00203cf4 */
/* @0x13ce4c .word 0xffffd724 */
/* @0x13ce50 eoreq r3, r0, r8, ror #25 */
/* @0x13ce54 .word 0xffffd728 */
/* @0x13ce58 .word 0x00203cdc */
/* @0x13ce5c .word 0xffffd72c */
/* @0x13ce60 .word 0x00203cd0 */
/* @0x13ce64 .word 0xffffd730 */
/* @0x13ce68 eoreq r3, r0, r8, asr #25 */
/* @0x13ce6c .word 0xffffd734 */
/* @0x13ce70 eoreq r3, r0, r8, asr #25 */
/* @0x13ce74 .word 0xffffd738 */
/* @0x13ce78 eoreq r3, r0, r4, asr #25 */
/* @0x13ce7c .word 0xffffd73c */
/* @0x13ce80 .word 0x00203cb4 */
/* @0x13ce84 .word 0xffffd740 */
/* @0x13ce88 eoreq r3, r0, r4, lsr #25 */
/* @0x13ce8c .word 0xffffd744 */
/* @0x13ce90 mlaeq r0, r8, r12, r3 */
/* @0x13ce94 .word 0xffffd748 */
/* @0x13ce98 eoreq r3, r0, r12, lsl #25 */
/* @0x13ce9c .word 0xffffd74c */
/* @0x13cea0 eoreq r3, r0, r4, lsl #25 */
/* @0x13cea4 .word 0xffffd750 */
/* @0x13cea8 eoreq r3, r0, r8, ror r12 */
/* @0x13ceac .word 0xffffd754 */
/* @0x13ceb0 eoreq r3, r0, r12, ror #24 */
/* @0x13ceb4 .word 0xffffd758 */
/* @0x13ceb8 eoreq r3, r0, r4, ror #24 */
/* @0x13cebc .word 0xffffd75c */
/* @0x13cec0 eoreq r3, r0, r8, asr r12 */
/* @0x13cec4 .word 0xffffd760 */
/* @0x13cec8 eoreq r3, r0, r0, asr r12 */
/* @0x13cecc .word 0xffffd764 */
/* @0x13ced0 eoreq r3, r0, r8, asr #24 */
/* @0x13ced4 .word 0xffffd768 */
/* @0x13ced8 eoreq r3, r0, r8, lsr r12 */
/* @0x13cedc .word 0xffffd76c */
/* @0x13cee0 eoreq r3, r0, r12, lsr #24 */
/* @0x13cee4 .word 0xffffd770 */
/* @0x13cee8 eoreq r3, r0, r0, lsr #24 */
/* @0x13ceec .word 0xffffd774 */
/* @0x13cef0 eoreq r3, r0, r0, lsl r12 */
/* @0x13cef4 .word 0xffffd778 */
/* @0x13cef8 eoreq r3, r0, r0, lsl #24 */
/* @0x13cefc .word 0xffffd77c */
/* @0x13cf00 .word 0x00203bf0 */

/* ── FUNC 0x13cf04 · FINALIZE_Function_File() · size=100 · insn=25 */
/* @0x13cf04 push {r3, r4, r5, r6, r7, lr} */
/* @0x13cf08 mov r6, #0 */
/* @0x13cf0c ldr r5, [pc, #0x4c] */
/* @0x13cf10 ldr r5, [pc, r5] */
/* @0x13cf14 add r4, r5, #8 */
/* @0x13cf18 add r7, r5, #392 */
/* @0x13cf1c ldr r0, [r5, #0x8] */
/* @0x13cf20 cmp r0, #0 */
/* @0x13cf24 beq 0x13cf30 <_Z22FINALIZE_Function_Filev+0x2c> */
/* @0x13cf28 bl 0xb6850 <fclose@plt> */
/* @0x13cf2c str r6, [r5, #0x8] */
/* @0x13cf30 ldr r0, [r4, #-0x8] */
/* @0x13cf34 add r4, r4, #12 */
/* @0x13cf38 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x13cf3c str r6, [r4, #-0x14] */
/* @0x13cf40 cmp r4, r7 */
/* @0x13cf44 add r5, r5, #12 */
/* @0x13cf48 mov r3, #0 */
/* @0x13cf4c bne 0x13cf1c <_Z22FINALIZE_Function_Filev+0x18> */
/* @0x13cf50 ldr r2, [pc, #0xc] */
/* @0x13cf54 ldr r2, [pc, r2] */
/* @0x13cf58 str r3, [r2] */
/* @0x13cf5c pop {r3, r4, r5, r6, r7, pc} */
/* @0x13cf60 eoreq r2, r11, r0, lsl #7 */
/* @0x13cf64 eoreq r0, r11, r4, lsr #29 */

/* ── FUNC 0x13cf68 · json_parse_to_map(json_object*, CDS_Map*) · size=372 · insn=93 */
/* @0x13cf68 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13cf6c sub sp, sp, #44 */
/* @0x13cf70 mov r9, r1 */
/* @0x13cf74 str r0, [sp, #0x4] */
/* @0x13cf78 bl 0x27e8f4 <json_object_get_object> */
/* @0x13cf7c ldr r5, [r0, #0x20] */
/* @0x13cf80 cmp r5, #0 */
/* @0x13cf84 beq 0x13d080 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x118> */
/* @0x13cf88 add r8, sp, #24 */
/* @0x13cf8c mov r4, #0 */
/* @0x13cf90 ldm r5, {r7, r11} */
/* @0x13cf94 cmp r11, #0 */
/* @0x13cf98 beq 0x13d074 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x10c> */
/* @0x13cf9c mov r0, r11 */
/* @0x13cfa0 add r6, sp, #8 */
/* @0x13cfa4 bl 0x27e828 <json_object_get_type> */
/* @0x13cfa8 mov r1, r7 */
/* @0x13cfac str r4, [sp, #0x8] */
/* @0x13cfb0 str r4, [sp, #0xc] */
/* @0x13cfb4 str r4, [sp, #0x10] */
/* @0x13cfb8 str r4, [sp, #0x14] */
/* @0x13cfbc str r4, [r8] */
/* @0x13cfc0 str r4, [sp, #0x1c] */
/* @0x13cfc4 str r4, [sp, #0x20] */
/* @0x13cfc8 str r4, [sp, #0x24] */
/* @0x13cfcc mov r10, r0 */
/* @0x13cfd0 mov r0, r6 */
/* @0x13cfd4 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x13cfd8 sub r0, r10, #1 */
/* @0x13cfdc cmp r0, #5 */
/* @0x13cfe0 addls pc, pc, r0, lsl #2 */
/* @0x13cfe4 b 0x13d024 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0xbc> */
/* @0x13cfe8 b 0x13d088 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x120> */
/* @0x13cfec b 0x13d088 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x120> */
/* @0x13cff0 b 0x13d088 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x120> */
/* @0x13cff4 b 0x13d098 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x130> */
/* @0x13cff8 b 0x13d000 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x98> */
/* @0x13cffc b 0x13d088 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x120> */
/* @0x13d000 mov r1, r7 */
/* @0x13d004 ldr r0, [sp, #0x4] */
/* @0x13d008 bl 0x13d274 <_Z16json_parse_arrayP11json_objectPc> */
/* @0x13d00c ldr r3, [sp, #0x24] */
/* @0x13d010 orr r3, r3, #1073741824 */
/* @0x13d014 str r3, [sp, #0x24] */
/* @0x13d018 vmov s13, r0 */
/* @0x13d01c vcvt.f64.s32 d7, s13 */
/* @0x13d020 vstr d7, [sp, #24] */
/* @0x13d024 mov r0, r9 */
/* @0x13d028 mov r1, r6 */
/* @0x13d02c mov r2, r8 */
/* @0x13d030 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_> */
/* @0x13d034 ldr r3, [sp, #0x14] */
/* @0x13d038 sub r3, r3, #1 */
/* @0x13d03c bic r3, r3, #-16777216 */
/* @0x13d040 bic r3, r3, #3 */
/* @0x13d044 cmp r3, #0 */
/* @0x13d048 beq 0x13d0d0 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x168> */
/* @0x13d04c ldr r3, [sp, #0x24] */
/* @0x13d050 mov r2, #5 */
/* @0x13d054 str r4, [sp, #0x10] */
/* @0x13d058 sub r3, r3, #1 */
/* @0x13d05c str r2, [sp, #0x14] */
/* @0x13d060 bic r3, r3, #-16777216 */
/* @0x13d064 str r4, [sp, #0x8] */
/* @0x13d068 bic r3, r3, #3 */
/* @0x13d06c cmp r3, #0 */
/* @0x13d070 beq 0x13d0c4 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x15c> */
/* @0x13d074 ldr r5, [r5, #0x8] */
/* @0x13d078 cmp r5, #0 */
/* @0x13d07c bne 0x13cf90 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x28> */
/* @0x13d080 add sp, sp, #44 */
/* @0x13d084 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x13d088 mov r0, r11 */
/* @0x13d08c mov r1, r8 */
/* @0x13d090 bl 0x13c274 <_Z10json_valueP11json_objectP6RValue> */
/* @0x13d094 b 0x13d024 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0xbc> */
/* @0x13d098 mov r1, r7 */
/* @0x13d09c ldr r0, [sp, #0x4] */
/* @0x13d0a0 bl 0x27ea38 <json_object_object_get> */
/* @0x13d0a4 bl 0x13d0dc <_Z10json_parseP11json_object> */
/* @0x13d0a8 ldr r3, [sp, #0x24] */
/* @0x13d0ac orr r3, r3, #-2147483648 */
/* @0x13d0b0 str r3, [sp, #0x24] */
/* @0x13d0b4 vmov s13, r0 */
/* @0x13d0b8 vcvt.f64.s32 d7, s13 */
/* @0x13d0bc vstr d7, [sp, #24] */
/* @0x13d0c0 b 0x13d024 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0xbc> */
/* @0x13d0c4 mov r0, r8 */
/* @0x13d0c8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x13d0cc b 0x13d074 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x10c> */
/* @0x13d0d0 mov r0, r6 */
/* @0x13d0d4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x13d0d8 b 0x13d04c <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0xe4> */

/* ── FUNC 0x13d0dc · json_parse(json_object*) · size=100 · insn=25 */
/* @0x13d0dc push {r4, r5, r6, lr} */
/* @0x13d0e0 sub sp, sp, #8 */
/* @0x13d0e4 add r5, sp, #4 */
/* @0x13d0e8 mov r6, r0 */
/* @0x13d0ec mov r0, r5 */
/* @0x13d0f0 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x13d0f4 mov r0, #4 */
/* @0x13d0f8 bl 0x27c524 <_Znwj> */
/* @0x13d0fc mov r4, r0 */
/* @0x13d100 bl 0x203624 <_ZN7CDS_MapC2Ev> */
/* @0x13d104 mov r1, r4 */
/* @0x13d108 mov r0, r6 */
/* @0x13d10c bl 0x13cf68 <_Z17json_parse_to_mapP11json_objectP7CDS_Map> */
/* @0x13d110 bl 0x100014 <_Z18FindFreeDsMapIndexv> */
/* @0x13d114 ldr r3, [pc, #0x20] */
/* @0x13d118 ldr r3, [pc, r3] */
/* @0x13d11c ldr r3, [r3, #0x4] */
/* @0x13d120 mov r6, r0 */
/* @0x13d124 mov r0, r5 */
/* @0x13d128 str r4, [r3, r6, lsl #2] */
/* @0x13d12c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x13d130 mov r0, r6 */
/* @0x13d134 add sp, sp, #8 */
/* @0x13d138 pop {r4, r5, r6, pc} */
/* @0x13d13c eoreq r0, r11, r4, lsr #16 */

/* ── FUNC 0x13d140 · json_parse_array_to_list(json_object*, char*, CDS_List*) · size=308 · insn=77 */
/* @0x13d140 cmp r1, #0 */
/* @0x13d144 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13d148 mov r9, r2 */
/* @0x13d14c sub sp, sp, #36 */
/* @0x13d150 mov r7, r0 */
/* @0x13d154 beq 0x13d160 <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List+0x20> */
/* @0x13d158 bl 0x27ea38 <json_object_object_get> */
/* @0x13d15c mov r7, r0 */
/* @0x13d160 mov r0, r7 */
/* @0x13d164 bl 0x27ede8 <json_object_array_length> */
/* @0x13d168 subs r8, r0, #0 */
/* @0x13d16c ble 0x13d248 <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List+0x108> */
/* @0x13d170 mov r4, #0 */
/* @0x13d174 add r3, sp, #24 */
/* @0x13d178 add r6, sp, #16 */
/* @0x13d17c str r3, [sp, #0x4] */
/* @0x13d180 add r11, sp, #20 */
/* @0x13d184 add r3, sp, #28 */
/* @0x13d188 str r6, [sp, #0xc] */
/* @0x13d18c mov r5, r4 */
/* @0x13d190 str r3, [sp, #0x8] */
/* @0x13d194 b 0x13d1b4 <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List+0x74> */
/* @0x13d198 bl 0x13c274 <_Z10json_valueP11json_objectP6RValue> */
/* @0x13d19c mov r0, r9 */
/* @0x13d1a0 mov r1, r6 */
/* @0x13d1a4 add r4, r4, #1 */
/* @0x13d1a8 bl 0x205d18 <_ZN8CDS_List3AddEP6RValue> */
/* @0x13d1ac cmp r4, r8 */
/* @0x13d1b0 beq 0x13d248 <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List+0x108> */
/* @0x13d1b4 mov r0, r7 */
/* @0x13d1b8 mov r1, r4 */
/* @0x13d1bc bl 0x27ee00 <json_object_array_get_idx> */
/* @0x13d1c0 subs r10, r0, #0 */
/* @0x13d1c4 beq 0x13d21c <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List+0xdc> */
/* @0x13d1c8 bl 0x27e828 <json_object_get_type> */
/* @0x13d1cc mov r1, r6 */
/* @0x13d1d0 str r5, [r6] */
/* @0x13d1d4 str r5, [r11] */
/* @0x13d1d8 str r5, [sp, #0x18] */
/* @0x13d1dc str r5, [sp, #0x1c] */
/* @0x13d1e0 mov r2, r0 */
/* @0x13d1e4 cmp r2, #5 */
/* @0x13d1e8 mov r0, r10 */
/* @0x13d1ec beq 0x13d250 <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List+0x110> */
/* @0x13d1f0 cmp r2, #4 */
/* @0x13d1f4 bne 0x13d198 <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List+0x58> */
/* @0x13d1f8 mov r0, r10 */
/* @0x13d1fc bl 0x13d0dc <_Z10json_parseP11json_object> */
/* @0x13d200 ldr r3, [sp, #0x1c] */
/* @0x13d204 orr r3, r3, #-2147483648 */
/* @0x13d208 str r3, [sp, #0x1c] */
/* @0x13d20c vmov s13, r0 */
/* @0x13d210 vcvt.f64.s32 d7, s13 */
/* @0x13d214 vstr d7, [sp, #16] */
/* @0x13d218 b 0x13d19c <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List+0x5c> */
/* @0x13d21c add r1, sp, #16 */
/* @0x13d220 mov r0, r9 */
/* @0x13d224 add r4, r4, #1 */
/* @0x13d228 str r10, [r6] */
/* @0x13d22c str r10, [r11] */
/* @0x13d230 mov r6, r1 */
/* @0x13d234 str r10, [sp, #0x18] */
/* @0x13d238 str r10, [sp, #0x1c] */
/* @0x13d23c bl 0x205d18 <_ZN8CDS_List3AddEP6RValue> */
/* @0x13d240 cmp r4, r8 */
/* @0x13d244 bne 0x13d1b4 <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List+0x74> */
/* @0x13d248 add sp, sp, #36 */
/* @0x13d24c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x13d250 mov r1, #0 */
/* @0x13d254 bl 0x13d274 <_Z16json_parse_arrayP11json_objectPc> */
/* @0x13d258 ldr r3, [sp, #0x1c] */
/* @0x13d25c orr r3, r3, #1073741824 */
/* @0x13d260 str r3, [sp, #0x1c] */
/* @0x13d264 vmov s13, r0 */
/* @0x13d268 vcvt.f64.s32 d7, s13 */
/* @0x13d26c vstr d7, [sp, #16] */
/* @0x13d270 b 0x13d19c <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List+0x5c> */

/* ── FUNC 0x13d274 · json_parse_array(json_object*, char*) · size=72 · insn=18 */
/* @0x13d274 push {r4, r5, r6, lr} */
/* @0x13d278 mov r5, r0 */
/* @0x13d27c mov r0, #16 */
/* @0x13d280 mov r6, r1 */
/* @0x13d284 bl 0x27c524 <_Znwj> */
/* @0x13d288 mov r4, r0 */
/* @0x13d28c bl 0x202ff8 <_ZN8CDS_ListC2Ev> */
/* @0x13d290 mov r0, r5 */
/* @0x13d294 mov r1, r6 */
/* @0x13d298 mov r2, r4 */
/* @0x13d29c bl 0x13d140 <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List> */
/* @0x13d2a0 bl 0xfff10 <_Z19FindFreeDsListIndexv> */
/* @0x13d2a4 ldr r3, [pc, #0xc] */
/* @0x13d2a8 ldr r3, [pc, r3] */
/* @0x13d2ac ldr r3, [r3, #0x4] */
/* @0x13d2b0 str r4, [r3, r0, lsl #2] */
/* @0x13d2b4 pop {r4, r5, r6, pc} */
/* @0x13d2b8 .word 0x002b09d8 */

/* ── FUNC 0x13d2bc · JSONToDSList(char*, char*, int) · size=140 · insn=35 */
/* @0x13d2bc push {r4, r5, r6, lr} */
/* @0x13d2c0 mov r5, r1 */
/* @0x13d2c4 mov r6, r2 */
/* @0x13d2c8 bl 0x28075c <json_tokener_parse> */
/* @0x13d2cc cmn r0, #4000 */
/* @0x13d2d0 mov r4, r0 */
/* @0x13d2d4 bhi 0x13d33c <_Z12JSONToDSListPcS_i+0x80> */
/* @0x13d2d8 mov r1, r5 */
/* @0x13d2dc bl 0x27ea38 <json_object_object_get> */
/* @0x13d2e0 bl 0x27ede8 <json_object_array_length> */
/* @0x13d2e4 cmp r0, #0 */
/* @0x13d2e8 mvnle r5, #0 */
/* @0x13d2ec ble 0x13d318 <_Z12JSONToDSListPcS_i+0x5c> */
/* @0x13d2f0 cmp r6, #0 */
/* @0x13d2f4 blt 0x13d328 <_Z12JSONToDSListPcS_i+0x6c> */
/* @0x13d2f8 ldr r3, [pc, #0x44] */
/* @0x13d2fc mov r1, r5 */
/* @0x13d300 mov r0, r4 */
/* @0x13d304 mvn r5, #0 */
/* @0x13d308 ldr r3, [pc, r3] */
/* @0x13d30c ldr r3, [r3, #0x4] */
/* @0x13d310 ldr r2, [r3, r6, lsl #2] */
/* @0x13d314 bl 0x13d140 <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List> */
/* @0x13d318 mov r0, r4 */
/* @0x13d31c bl 0x27e7c8 <json_object_put> */
/* @0x13d320 mov r0, r5 */
/* @0x13d324 pop {r4, r5, r6, pc} */
/* @0x13d328 mov r1, r5 */
/* @0x13d32c mov r0, r4 */
/* @0x13d330 bl 0x13d274 <_Z16json_parse_arrayP11json_objectPc> */
/* @0x13d334 mov r5, r0 */
/* @0x13d338 b 0x13d318 <_Z12JSONToDSListPcS_i+0x5c> */
/* @0x13d33c mvn r5, #0 */
/* @0x13d340 b 0x13d320 <_Z12JSONToDSListPcS_i+0x64> */
/* @0x13d344 eoreq r0, r11, r8, ror r9 */

/* ── FUNC 0x13d348 · F_JsonDecode(RValue&, CInstance*, CInstance*, int, RValue*) · size=612 · insn=153 */
/* @0x13d348 push {r4, r5, r6, r7, r8, lr} */
/* @0x13d34c mov r7, r0 */
/* @0x13d350 ldr r4, [sp, #0x18] */
/* @0x13d354 ldr r3, [r4, #0xc] */
/* @0x13d358 bic r3, r3, #-16777216 */
/* @0x13d35c cmp r3, #1 */
/* @0x13d360 beq 0x13d3c8 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x13d364 ldr r1, [pc, #0x218] */
/* @0x13d368 movw r2, #0xb87 */
/* @0x13d36c mov r3, #1 */
/* @0x13d370 mov r0, #54 */
/* @0x13d374 add r1, pc, r1 */
/* @0x13d378 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x13d37c mov r1, #0 */
/* @0x13d380 mov r6, r0 */
/* @0x13d384 mov r0, r4 */
/* @0x13d388 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13d38c mov r3, r1 */
/* @0x13d390 ldr r1, [pc, #0x1f0] */
/* @0x13d394 mov r2, r0 */
/* @0x13d398 mov r0, r6 */
/* @0x13d39c add r1, pc, r1 */
/* @0x13d3a0 bl 0xb6550 <sprintf@plt> */
/* @0x13d3a4 cmp r6, #0 */
/* @0x13d3a8 bne 0x13d57c <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x234> */
/* @0x13d3ac mov r3, #0 */
/* @0x13d3b0 movt r3, #0xbff0 */
/* @0x13d3b4 mov r2, #0 */
/* @0x13d3b8 mov r1, #0 */
/* @0x13d3bc stm r7, {r2, r3} */
/* @0x13d3c0 str r1, [r7, #0xc] */
/* @0x13d3c4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x13d3c8 ldr r3, [r4] */
/* @0x13d3cc cmp r3, #0 */
/* @0x13d3d0 beq 0x13d364 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x1c> */
/* @0x13d3d4 ldr r6, [r3] */
/* @0x13d3d8 cmp r6, #0 */
/* @0x13d3dc movne r8, #0 */
/* @0x13d3e0 beq 0x13d364 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x1c> */
/* @0x13d3e4 mov r0, r6 */
/* @0x13d3e8 bl 0xb6538 <strlen@plt> */
/* @0x13d3ec mov r1, #1 */
/* @0x13d3f0 mov r4, r0 */
/* @0x13d3f4 mov r0, r6 */
/* @0x13d3f8 mov r2, r4 */
/* @0x13d3fc bl 0x13c350 <_Z17findfirstnonspacePKcii> */
/* @0x13d400 mov r2, r4 */
/* @0x13d404 mvn r1, #0 */
/* @0x13d408 mov r5, r0 */
/* @0x13d40c sub r0, r4, #1 */
/* @0x13d410 add r0, r6, r0 */
/* @0x13d414 bl 0x13c350 <_Z17findfirstnonspacePKcii> */
/* @0x13d418 ldrb r3, [r5] */
/* @0x13d41c cmp r3, #123 */
/* @0x13d420 beq 0x13d500 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0x13d424 ldr r4, [pc, #0x160] */
/* @0x13d428 cmp r3, #91 */
/* @0x13d42c mov r5, #20 */
/* @0x13d430 add r4, pc, r4 */
/* @0x13d434 beq 0x13d528 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x13d438 mov r0, r6 */
/* @0x13d43c bl 0xb6538 <strlen@plt> */
/* @0x13d440 ldr r1, [pc, #0x148] */
/* @0x13d444 movw r2, #0xb9d */
/* @0x13d448 mov r3, #1 */
/* @0x13d44c add r1, pc, r1 */
/* @0x13d450 add r0, r0, r5 */
/* @0x13d454 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x13d458 mov r1, r4 */
/* @0x13d45c mov r2, r6 */
/* @0x13d460 mov r5, r0 */
/* @0x13d464 bl 0xb6550 <sprintf@plt> */
/* @0x13d468 cmp r8, #0 */
/* @0x13d46c moveq r8, #1 */
/* @0x13d470 bne 0x13d51c <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x1d4> */
/* @0x13d474 mov r0, r5 */
/* @0x13d478 bl 0x28075c <json_tokener_parse> */
/* @0x13d47c cmn r0, #4000 */
/* @0x13d480 mov r4, r0 */
/* @0x13d484 bhi 0x13d4ac <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x13d488 mov r0, r4 */
/* @0x13d48c bl 0x13d0dc <_Z10json_parseP11json_object> */
/* @0x13d490 mov r5, r0 */
/* @0x13d494 mov r0, r4 */
/* @0x13d498 bl 0x27e7c8 <json_object_put> */
/* @0x13d49c vmov s15, r5 */
/* @0x13d4a0 vcvt.f64.s32 d7, s15 */
/* @0x13d4a4 vmov r2, r3, d7 */
/* @0x13d4a8 b 0x13d3b8 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x13d4ac mov r0, r5 */
/* @0x13d4b0 bl 0xb6538 <strlen@plt> */
/* @0x13d4b4 ldr r1, [pc, #0xd8] */
/* @0x13d4b8 movw r2, #0xbaa */
/* @0x13d4bc mov r3, #1 */
/* @0x13d4c0 add r1, pc, r1 */
/* @0x13d4c4 add r0, r0, #20 */
/* @0x13d4c8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x13d4cc ldr r1, [pc, #0xc4] */
/* @0x13d4d0 mov r2, r5 */
/* @0x13d4d4 add r1, pc, r1 */
/* @0x13d4d8 mov r4, r0 */
/* @0x13d4dc bl 0xb6550 <sprintf@plt> */
/* @0x13d4e0 cmp r8, #0 */
/* @0x13d4e4 bne 0x13d544 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x13d4e8 mov r0, r4 */
/* @0x13d4ec bl 0x28075c <json_tokener_parse> */
/* @0x13d4f0 cmn r0, #4000 */
/* @0x13d4f4 mov r4, r0 */
/* @0x13d4f8 bhi 0x13d3ac <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x13d4fc b 0x13d488 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x13d500 ldrb r3, [r0] */
/* @0x13d504 cmp r3, #125 */
/* @0x13d508 beq 0x13d550 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x208> */
/* @0x13d50c ldr r4, [pc, #0x88] */
/* @0x13d510 mov r5, #20 */
/* @0x13d514 add r4, pc, r4 */
/* @0x13d518 b 0x13d438 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x13d51c mov r0, r6 */
/* @0x13d520 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x13d524 b 0x13d474 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x13d528 ldrb r3, [r0] */
/* @0x13d52c cmp r3, #93 */
/* @0x13d530 beq 0x13d56c <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x224> */
/* @0x13d534 ldr r4, [pc, #0x64] */
/* @0x13d538 mov r5, #20 */
/* @0x13d53c add r4, pc, r4 */
/* @0x13d540 b 0x13d438 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x13d544 mov r0, r5 */
/* @0x13d548 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x13d54c b 0x13d4e8 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x13d550 cmp r5, r0 */
/* @0x13d554 movls r5, r6 */
/* @0x13d558 bls 0x13d474 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x13d55c ldr r4, [pc, #0x40] */
/* @0x13d560 mov r5, #20 */
/* @0x13d564 add r4, pc, r4 */
/* @0x13d568 b 0x13d438 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x13d56c ldr r4, [pc, #0x34] */
/* @0x13d570 mov r5, #18 */
/* @0x13d574 add r4, pc, r4 */
/* @0x13d578 b 0x13d438 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x13d57c mov r8, #1 */
/* @0x13d580 b 0x13d3e4 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x13d584 .word 0x00202cdc */
/* @0x13d588 eoreq r3, r0, r8, lsr r5 */
/* @0x13d58c eoreq r3, r0, r12, lsl #9 */
/* @0x13d590 eoreq r2, r0, r4, lsl #24 */
/* @0x13d594 mlaeq r0, r0, r11, r2 */
/* @0x13d598 eoreq r3, r0, r8, ror #7 */
/* @0x13d59c eoreq r3, r0, r8, lsr #7 */
/* @0x13d5a0 eoreq r3, r0, r0, lsl #7 */
/* @0x13d5a4 eoreq r3, r0, r8, asr r3 */
/* @0x13d5a8 eoreq r3, r0, r4, lsr r3 */

/* ── FUNC 0x13d5ac · JSONToDSMap(char*, int) · size=132 · insn=33 */
/* @0x13d5ac push {r4, r5, r6, r7, lr} */
/* @0x13d5b0 sub sp, sp, #12 */
/* @0x13d5b4 mov r6, r1 */
/* @0x13d5b8 bl 0x28075c <json_tokener_parse> */
/* @0x13d5bc cmn r0, #4000 */
/* @0x13d5c0 mov r4, r0 */
/* @0x13d5c4 bhi 0x13d624 <_Z11JSONToDSMapPci+0x78> */
/* @0x13d5c8 add r5, sp, #4 */
/* @0x13d5cc mov r0, r5 */
/* @0x13d5d0 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x13d5d4 cmp r6, #0 */
/* @0x13d5d8 blt 0x13d614 <_Z11JSONToDSMapPci+0x68> */
/* @0x13d5dc ldr r3, [pc, #0x48] */
/* @0x13d5e0 mov r0, r4 */
/* @0x13d5e4 mvn r7, #0 */
/* @0x13d5e8 ldr r3, [pc, r3] */
/* @0x13d5ec ldr r3, [r3, #0x4] */
/* @0x13d5f0 ldr r1, [r3, r6, lsl #2] */
/* @0x13d5f4 bl 0x13cf68 <_Z17json_parse_to_mapP11json_objectP7CDS_Map> */
/* @0x13d5f8 mov r0, r4 */
/* @0x13d5fc bl 0x27e7c8 <json_object_put> */
/* @0x13d600 mov r0, r5 */
/* @0x13d604 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x13d608 mov r0, r7 */
/* @0x13d60c add sp, sp, #12 */
/* @0x13d610 pop {r4, r5, r6, r7, pc} */
/* @0x13d614 mov r0, r4 */
/* @0x13d618 bl 0x13d0dc <_Z10json_parseP11json_object> */
/* @0x13d61c mov r7, r0 */
/* @0x13d620 b 0x13d5f8 <_Z11JSONToDSMapPci+0x4c> */
/* @0x13d624 mvn r7, #0 */
/* @0x13d628 b 0x13d608 <_Z11JSONToDSMapPci+0x5c> */
/* @0x13d62c eoreq r0, r11, r4, asr r3 */

/* ── FUNC 0x13d630 · F_ActionUnknown(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x13d630 bx lr */

/* ── FUNC 0x13d634 · F_ActionTimelineStart(RValue&, CInstance*, CInstance*, int, RValue*) · size=12 · insn=3 */
/* @0x13d634 mov r3, #1 */
/* @0x13d638 strb r3, [r1, #0x15c] */
/* @0x13d63c bx lr */

/* ── FUNC 0x13d640 · F_ActionTimelinePause(RValue&, CInstance*, CInstance*, int, RValue*) · size=12 · insn=3 */
/* @0x13d640 mov r3, #0 */
/* @0x13d644 strb r3, [r1, #0x15c] */
/* @0x13d648 bx lr */

/* ── FUNC 0x13d64c · F_ActionTimelineStop(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x13d64c mov r2, #0 */
/* @0x13d650 mov r3, #0 */
/* @0x13d654 str r2, [r1, #0x154] */
/* @0x13d658 strb r3, [r1, #0x15c] */
/* @0x13d65c bx lr */

/* ── FUNC 0x13d660 · F_ActionSetScore(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x13d660 push {r3, lr} */
/* @0x13d664 mov r1, #0 */
/* @0x13d668 ldr r0, [sp, #0x8] */
/* @0x13d66c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13d670 ldr r3, [pc, #0x28] */
/* @0x13d674 ldr r2, [pc, #0x28] */
/* @0x13d678 add r3, pc, r3 */
/* @0x13d67c ldr r2, [r3, r2] */
/* @0x13d680 ldrb r2, [r2] */
/* @0x13d684 cmp r2, #0 */
/* @0x13d688 ldr r2, [pc, #0x18] */
/* @0x13d68c ldr r3, [r3, r2] */
/* @0x13d690 ldrne r2, [r3] */
/* @0x13d694 addne r0, r0, r2 */
/* @0x13d698 str r0, [r3] */
/* @0x13d69c pop {r3, pc} */
/* @0x13d6a0 .word 0x002b45d8 */
/* @0x13d6a4 .word 0xffffbeec */
/* @0x13d6a8 .word 0xffffce34 */

/* ── FUNC 0x13d6ac · F_ActionIfLife(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0x13d6ac push {r3, r4, r5, r6, r7, lr} */
/* @0x13d6b0 mov r1, #0 */
/* @0x13d6b4 ldr r5, [sp, #0x18] */
/* @0x13d6b8 mov r4, r0 */
/* @0x13d6bc ldr r6, [pc, #0x84] */
/* @0x13d6c0 mov r0, r5 */
/* @0x13d6c4 add r6, pc, r6 */
/* @0x13d6c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13d6cc mov r1, #1 */
/* @0x13d6d0 mov r7, r0 */
/* @0x13d6d4 mov r0, r5 */
/* @0x13d6d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13d6dc ldr r3, [pc, #0x68] */
/* @0x13d6e0 ldr r3, [r6, r3] */
/* @0x13d6e4 cmp r0, #1 */
/* @0x13d6e8 beq 0x13d724 <_Z14F_ActionIfLifeR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x13d6ec cmp r0, #2 */
/* @0x13d6f0 ldr r0, [r3] */
/* @0x13d6f4 beq 0x13d738 <_Z14F_ActionIfLifeR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x13d6f8 subs r3, r0, r7 */
/* @0x13d6fc rsbs r0, r3, #0 */
/* @0x13d700 adcs r0, r0, r3 */
/* @0x13d704 cmp r0, #0 */
/* @0x13d708 mov r3, #0 */
/* @0x13d70c str r3, [r4, #0xc] */
/* @0x13d710 movne r0, r3 */
/* @0x13d714 moveq r3, r0 */
/* @0x13d718 movtne r3, #0x3ff0 */
/* @0x13d71c stm r4, {r0, r3} */
/* @0x13d720 pop {r3, r4, r5, r6, r7, pc} */
/* @0x13d724 ldr r0, [r3] */
/* @0x13d728 cmp r0, r7 */
/* @0x13d72c movge r0, #0 */
/* @0x13d730 movlt r0, #1 */
/* @0x13d734 b 0x13d704 <_Z14F_ActionIfLifeR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x13d738 cmp r0, r7 */
/* @0x13d73c movle r0, #0 */
/* @0x13d740 movgt r0, #1 */
/* @0x13d744 b 0x13d704 <_Z14F_ActionIfLifeR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x13d748 eoreq r4, r11, r12, lsl #11 */
/* @0x13d74c .word 0xffffd780 */

/* ── FUNC 0x13d750 · F_ActionSetFriction(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x13d750 push {r4, lr} */
/* @0x13d754 mov r4, r1 */
/* @0x13d758 ldr r0, [sp, #0x8] */
/* @0x13d75c mov r1, #0 */
/* @0x13d760 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13d764 ldr r3, [pc, #0x1c] */
/* @0x13d768 ldr r3, [pc, r3] */
/* @0x13d76c ldrb r3, [r3] */
/* @0x13d770 cmp r3, #0 */
/* @0x13d774 vldrne s14, [r4, #212] */
/* @0x13d778 vmov s15, r0 */
/* @0x13d77c vaddne.f32 s15, s14, s15 */
/* @0x13d780 vstr s15, [r4, #212] */
/* @0x13d784 pop {r4, pc} */
/* @0x13d788 .word 0x002b03d4 */

/* ── FUNC 0x13d78c · F_ActionSetTimelinePosition(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x13d78c push {r4, lr} */
/* @0x13d790 mov r4, r1 */
/* @0x13d794 ldr r0, [sp, #0x8] */
/* @0x13d798 mov r1, #0 */
/* @0x13d79c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13d7a0 ldr r3, [pc, #0x1c] */
/* @0x13d7a4 ldr r3, [pc, r3] */
/* @0x13d7a8 ldrb r3, [r3] */
/* @0x13d7ac cmp r3, #0 */
/* @0x13d7b0 vldrne s14, [r4, #340] */
/* @0x13d7b4 vmov s15, r0 */
/* @0x13d7b8 vaddne.f32 s15, s14, s15 */
/* @0x13d7bc vstr s15, [r4, #340] */
/* @0x13d7c0 pop {r4, pc} */
/* @0x13d7c4 mlaeq r11, r8, r3, r0 */

/* ── FUNC 0x13d7c8 · F_ActionSetTimelineSpeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x13d7c8 push {r4, lr} */
/* @0x13d7cc mov r4, r1 */
/* @0x13d7d0 ldr r0, [sp, #0x8] */
/* @0x13d7d4 mov r1, #0 */
/* @0x13d7d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13d7dc ldr r3, [pc, #0x1c] */
/* @0x13d7e0 ldr r3, [pc, r3] */
/* @0x13d7e4 ldrb r3, [r3] */
/* @0x13d7e8 cmp r3, #0 */
/* @0x13d7ec vldrne s14, [r4, #344] */
/* @0x13d7f0 vmov s15, r0 */
/* @0x13d7f4 vaddne.f32 s15, s14, s15 */
/* @0x13d7f8 vstr s15, [r4, #344] */
/* @0x13d7fc pop {r4, pc} */
/* @0x13d800 eoreq r0, r11, r12, asr r3 */

/* ── FUNC 0x13d804 · F_ActionSetTimeline(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x13d804 push {r4, r5, r6, lr} */
/* @0x13d808 mov r4, r1 */
/* @0x13d80c ldr r5, [sp, #0x10] */
/* @0x13d810 mov r1, #0 */
/* @0x13d814 mov r0, r5 */
/* @0x13d818 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13d81c mov r1, #1 */
/* @0x13d820 mov r6, r0 */
/* @0x13d824 mov r0, r5 */
/* @0x13d828 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13d82c mov r3, #1 */
/* @0x13d830 str r6, [r4, #0x14c] */
/* @0x13d834 strb r3, [r4, #0x15c] */
/* @0x13d838 str r0, [r4, #0x154] */
/* @0x13d83c pop {r4, r5, r6, pc} */

/* ── FUNC 0x13d840 · F_ActionTimelineSet(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x13d840 push {r4, r5, r6, r7, r8, lr} */
/* @0x13d844 mov r5, r1 */
/* @0x13d848 ldr r4, [sp, #0x18] */
/* @0x13d84c mov r1, #0 */
/* @0x13d850 mov r0, r4 */
/* @0x13d854 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13d858 mov r1, #1 */
/* @0x13d85c mov r8, r0 */
/* @0x13d860 mov r0, r4 */
/* @0x13d864 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13d868 mov r1, #2 */
/* @0x13d86c mov r6, r0 */
/* @0x13d870 mov r0, r4 */
/* @0x13d874 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13d878 mov r1, #3 */
/* @0x13d87c mov r7, r0 */
/* @0x13d880 mov r0, r4 */
/* @0x13d884 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13d888 rsbs r7, r7, #1 */
/* @0x13d88c str r8, [r5, #0x14c] */
/* @0x13d890 movlo r7, #0 */
/* @0x13d894 str r6, [r5, #0x154] */
/* @0x13d898 strb r7, [r5, #0x15c] */
/* @0x13d89c subs r3, r0, #1 */
/* @0x13d8a0 rsbs r0, r3, #0 */
/* @0x13d8a4 adcs r0, r0, r3 */
/* @0x13d8a8 strb r0, [r5, #0x15d] */
/* @0x13d8ac pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x13d8b0 · F_ActionSpriteColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x13d8b0 push {r3, r4, r5, lr} */
/* @0x13d8b4 mov r4, r1 */
/* @0x13d8b8 ldr r5, [sp, #0x10] */
/* @0x13d8bc mov r1, #0 */
/* @0x13d8c0 mov r0, r5 */
/* @0x13d8c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13d8c8 mov r1, #1 */
/* @0x13d8cc str r0, [r4, #0xa8] */
/* @0x13d8d0 mov r0, r5 */
/* @0x13d8d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13d8d8 str r0, [r4, #0xa4] */
/* @0x13d8dc pop {r3, r4, r5, pc} */

/* ── FUNC 0x13d8e0 · F_ActionSpriteSet(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x13d8e0 push {r4, r5, r6, lr} */
/* @0x13d8e4 vpush {d8} */
/* @0x13d8e8 mov r5, r1 */
/* @0x13d8ec ldr r4, [sp, #0x18] */
/* @0x13d8f0 mov r1, #0 */
/* @0x13d8f4 mov r0, r4 */
/* @0x13d8f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13d8fc mov r1, #1 */
/* @0x13d900 mov r6, r0 */
/* @0x13d904 mov r0, r4 */
/* @0x13d908 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13d90c mov r1, #2 */
/* @0x13d910 vmov s16, r0 */
/* @0x13d914 mov r0, r4 */
/* @0x13d918 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13d91c mov r1, r6 */
/* @0x13d920 mov r4, r0 */
/* @0x13d924 mov r0, r5 */
/* @0x13d928 bl 0x1c9dbc <_Z17Command_SetSpriteP9CInstancei> */
/* @0x13d92c vcmpe.f32 s16, #0 */
/* @0x13d930 str r4, [r5, #0x94] */
/* @0x13d934 vmrs APSR_nzcv, fpscr */
/* @0x13d938 vstrge s16, [r5, #144] */
/* @0x13d93c vpop {d8} */
/* @0x13d940 pop {r4, r5, r6, pc} */

/* ── FUNC 0x13d944 · F_ActionSetSprite(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x13d944 push {r4, r5, r6, lr} */
/* @0x13d948 vpush {d8} */
/* @0x13d94c mov r4, r1 */
/* @0x13d950 ldr r5, [sp, #0x18] */
/* @0x13d954 mov r1, #0 */
/* @0x13d958 mov r0, r5 */
/* @0x13d95c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13d960 mov r1, #1 */
/* @0x13d964 mov r6, r0 */
/* @0x13d968 mov r0, r5 */
/* @0x13d96c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13d970 mov r1, r6 */
/* @0x13d974 vmov s16, r0 */
/* @0x13d978 mov r0, r4 */
/* @0x13d97c bl 0x1c9dbc <_Z17Command_SetSpriteP9CInstancei> */
/* @0x13d980 vcmpe.f32 s16, #0 */
/* @0x13d984 vmrs APSR_nzcv, fpscr */
/* @0x13d988 ble 0x13d9ac <_Z17F_ActionSetSpriteR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x13d98c mov r0, r4 */
/* @0x13d990 vmov r1, s16 */
/* @0x13d994 bl 0x192fec <_ZN9CInstance14SetImageScaleXEf> */
/* @0x13d998 vmov r1, s16 */
/* @0x13d99c vpop {d8} */
/* @0x13d9a0 mov r0, r4 */
/* @0x13d9a4 pop {r4, r5, r6, lr} */
/* @0x13d9a8 b 0x193014 <_ZN9CInstance14SetImageScaleYEf> */
/* @0x13d9ac vpop {d8} */
/* @0x13d9b0 pop {r4, r5, r6, pc} */

/* ── FUNC 0x13d9b4 · F_ActionSetMotion(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x13d9b4 push {r4, r5, r6, lr} */
/* @0x13d9b8 mov r5, r1 */
/* @0x13d9bc ldr r4, [sp, #0x10] */
/* @0x13d9c0 mov r1, #0 */
/* @0x13d9c4 mov r0, r4 */
/* @0x13d9c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13d9cc mov r1, #1 */
/* @0x13d9d0 mov r6, r0 */
/* @0x13d9d4 mov r0, r4 */
/* @0x13d9d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13d9dc ldr r3, [pc, #0x40] */
/* @0x13d9e0 ldr r3, [pc, r3] */
/* @0x13d9e4 ldrb r3, [r3] */
/* @0x13d9e8 cmp r3, #0 */
/* @0x13d9ec mov r4, r0 */
/* @0x13d9f0 bne 0x13da10 <_Z17F_ActionSetMotionR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x13d9f4 mov r1, r6 */
/* @0x13d9f8 mov r0, r5 */
/* @0x13d9fc bl 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x13da00 mov r0, r5 */
/* @0x13da04 mov r1, r4 */
/* @0x13da08 pop {r4, r5, r6, lr} */
/* @0x13da0c b 0x1930d4 <_ZN9CInstance8SetSpeedEf> */
/* @0x13da10 mov r0, r5 */
/* @0x13da14 mov r1, r6 */
/* @0x13da18 mov r2, r4 */
/* @0x13da1c pop {r4, r5, r6, lr} */
/* @0x13da20 b 0x193ec0 <_ZN9CInstance11AddTo_SpeedEff> */
/* @0x13da24 eoreq r0, r11, r12, asr r1 */

/* ── FUNC 0x13da28 · F_ActionSetHspeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x13da28 push {r4, lr} */
/* @0x13da2c mov r4, r1 */
/* @0x13da30 ldr r0, [sp, #0x8] */
/* @0x13da34 mov r1, #0 */
/* @0x13da38 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13da3c ldr r3, [pc, #0x38] */
/* @0x13da40 ldr r3, [pc, r3] */
/* @0x13da44 ldrb r3, [r3] */
/* @0x13da48 cmp r3, #0 */
/* @0x13da4c vmov s15, r0 */
/* @0x13da50 bne 0x13da64 <_Z17F_ActionSetHspeedR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x13da54 mov r0, r4 */
/* @0x13da58 vmov r1, s15 */
/* @0x13da5c pop {r4, lr} */
/* @0x13da60 b 0x1930f4 <_ZN9CInstance9SetHspeedEf> */
/* @0x13da64 vldr s14, [r4, #224] */
/* @0x13da68 vadd.f32 s14, s15, s14 */
/* @0x13da6c mov r0, r4 */
/* @0x13da70 pop {r4, lr} */
/* @0x13da74 vmov r1, s14 */
/* @0x13da78 b 0x1930f4 <_ZN9CInstance9SetHspeedEf> */
/* @0x13da7c .word 0x002b00fc */

/* ── FUNC 0x13da80 · F_ActionReverseXDir(RValue&, CInstance*, CInstance*, int, RValue*) · size=16 · insn=4 */
/* @0x13da80 mov r0, r1 */
/* @0x13da84 ldr r1, [r1, #0xe0] */
/* @0x13da88 eor r1, r1, #-2147483648 */
/* @0x13da8c b 0x1930f4 <_ZN9CInstance9SetHspeedEf> */

/* ── FUNC 0x13da90 · F_ActionSetVspeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x13da90 push {r4, lr} */
/* @0x13da94 mov r4, r1 */
/* @0x13da98 ldr r0, [sp, #0x8] */
/* @0x13da9c mov r1, #0 */
/* @0x13daa0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13daa4 ldr r3, [pc, #0x38] */
/* @0x13daa8 ldr r3, [pc, r3] */
/* @0x13daac ldrb r3, [r3] */
/* @0x13dab0 cmp r3, #0 */
/* @0x13dab4 vmov s15, r0 */
/* @0x13dab8 bne 0x13dacc <_Z17F_ActionSetVspeedR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x13dabc mov r0, r4 */
/* @0x13dac0 vmov r1, s15 */
/* @0x13dac4 pop {r4, lr} */
/* @0x13dac8 b 0x193114 <_ZN9CInstance9SetVspeedEf> */
/* @0x13dacc vldr s14, [r4, #228] */
/* @0x13dad0 vadd.f32 s14, s15, s14 */
/* @0x13dad4 mov r0, r4 */
/* @0x13dad8 pop {r4, lr} */
/* @0x13dadc vmov r1, s14 */
/* @0x13dae0 b 0x193114 <_ZN9CInstance9SetVspeedEf> */
/* @0x13dae4 mlaeq r11, r4, r0, r0 */

/* ── FUNC 0x13dae8 · F_ActionReverseYDir(RValue&, CInstance*, CInstance*, int, RValue*) · size=16 · insn=4 */
/* @0x13dae8 mov r0, r1 */
/* @0x13daec ldr r1, [r1, #0xe4] */
/* @0x13daf0 eor r1, r1, #-2147483648 */
/* @0x13daf4 b 0x193114 <_ZN9CInstance9SetVspeedEf> */
