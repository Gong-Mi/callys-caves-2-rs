/* libyoyo.so 覆盖卡组 0007
 * 函数 0xc73f4..0xc9108，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xc73f4 · F_BUFFER_Load_Async(RValue&, CInstance*, CInstance*, int, RValue*) · size=312 · insn=78 */
/* @0xc73f4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc73f8 mov r5, r0 */
/* @0xc73fc ldr r4, [sp, #0x28] */
/* @0xc7400 mov r3, #0 */
/* @0xc7404 mov r6, r3 */
/* @0xc7408 mov r1, #1 */
/* @0xc740c movt r3, #0xbff0 */
/* @0xc7410 str r6, [r0] */
/* @0xc7414 str r3, [r0, #0x4] */
/* @0xc7418 mov r0, r4 */
/* @0xc741c str r6, [r5, #0xc] */
/* @0xc7420 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xc7424 mov r1, r6 */
/* @0xc7428 mov r8, r0 */
/* @0xc742c mov r0, r4 */
/* @0xc7430 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc7434 mov r1, #2 */
/* @0xc7438 mov r9, r0 */
/* @0xc743c mov r0, r4 */
/* @0xc7440 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc7444 mov r1, #3 */
/* @0xc7448 mov r7, r0 */
/* @0xc744c mov r0, r4 */
/* @0xc7450 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc7454 ldr r3, [pc, #0xb8] */
/* @0xc7458 ldr r3, [pc, r3] */
/* @0xc745c ldr r4, [r3] */
/* @0xc7460 cmp r4, r6 */
/* @0xc7464 mov r11, r0 */
/* @0xc7468 beq 0xc747c <_Z19F_BUFFER_Load_AsyncR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0xc746c ldr r0, [pc, #0xa4] */
/* @0xc7470 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc7474 add r0, pc, r0 */
/* @0xc7478 b 0xd547c <_Z7YYErrorPKcz> */
/* @0xc747c mov r0, #24 */
/* @0xc7480 ldr r10, [pc, #0x94] */
/* @0xc7484 bl 0x27c524 <_Znwj> */
/* @0xc7488 ldr r10, [pc, r10] */
/* @0xc748c ldr r3, [r10] */
/* @0xc7490 mov r6, r0 */
/* @0xc7494 mov r0, r8 */
/* @0xc7498 str r3, [r6] */
/* @0xc749c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xc74a0 ldr r2, [pc, #0x78] */
/* @0xc74a4 ldr r3, [pc, #0x78] */
/* @0xc74a8 add r2, pc, r2 */
/* @0xc74ac ldr r3, [pc, r3] */
/* @0xc74b0 ldr r2, [r2, #0x4] */
/* @0xc74b4 ldr r8, [r3] */
/* @0xc74b8 cmp r8, #0 */
/* @0xc74bc str r0, [r6, #0x8] */
/* @0xc74c0 ldr r3, [r2, r9, lsl #2] */
/* @0xc74c4 str r6, [r10] */
/* @0xc74c8 str r4, [r6, #0xc] */
/* @0xc74cc str r3, [r6, #0x4] */
/* @0xc74d0 str r11, [r6, #0x10] */
/* @0xc74d4 str r7, [r6, #0x14] */
/* @0xc74d8 popne {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xc74dc ldr r2, [pc, #0x44] */
/* @0xc74e0 mov r1, r6 */
/* @0xc74e4 mov r3, r8 */
/* @0xc74e8 mov r0, r8 */
/* @0xc74ec add r2, pc, r2 */
/* @0xc74f0 bl 0xc70c4 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb> */
/* @0xc74f4 vmov s15, r0 */
/* @0xc74f8 vcvt.f64.s32 d7, s15 */
/* @0xc74fc vmov r0, r1, d7 */
/* @0xc7500 vmov r2, s14 */
/* @0xc7504 mov r3, r1 */
/* @0xc7508 stm r5, {r2, r3} */
/* @0xc750c str r8, [r10] */
/* @0xc7510 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xc7514 eorseq r6, r2, r0, lsl #11 */
/* @0xc7518 strhteq r10, [r6], -r8 */
/* @0xc751c eorseq r6, r2, r4, asr r5 */
/* @0xc7520 eorseq r2, r11, r12, ror #24 */
/* @0xc7524 eorseq r6, r2, r12, lsl #10 */
/* @0xc7528 eoreq r10, r6, r12, lsr #1 */

/* ── FUNC 0xc752c · F_BUFFER_Async_Group_End(RValue&, CInstance*, CInstance*, int, RValue*) · size=208 · insn=52 */
/* @0xc752c push {r3, r4, r5, lr} */
/* @0xc7530 mov r5, r0 */
/* @0xc7534 ldr r4, [pc, #0xac] */
/* @0xc7538 mov r0, #0 */
/* @0xc753c str r0, [r5] */
/* @0xc7540 mov r3, r0 */
/* @0xc7544 ldr r4, [pc, r4] */
/* @0xc7548 movt r3, #0xbff0 */
/* @0xc754c str r0, [r5, #0xc] */
/* @0xc7550 ldr r2, [r4] */
/* @0xc7554 str r3, [r5, #0x4] */
/* @0xc7558 cmp r2, r0 */
/* @0xc755c beq 0xc75c8 <_Z24F_BUFFER_Async_Group_EndR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0xc7560 ldr r3, [pc, #0x84] */
/* @0xc7564 ldr r3, [pc, r3] */
/* @0xc7568 ldr r1, [r3] */
/* @0xc756c cmp r1, #0 */
/* @0xc7570 movne r3, #1 */
/* @0xc7574 beq 0xc75a8 <_Z24F_BUFFER_Async_Group_EndR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xc7578 bl 0xc70c4 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb> */
/* @0xc757c vmov s15, r0 */
/* @0xc7580 vcvt.f64.s32 d7, s15 */
/* @0xc7584 vmov r0, r1, d7 */
/* @0xc7588 vmov r2, s14 */
/* @0xc758c mov r3, r1 */
/* @0xc7590 stm r5, {r2, r3} */
/* @0xc7594 ldr r0, [r4] */
/* @0xc7598 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc759c mov r3, #0 */
/* @0xc75a0 str r3, [r4] */
/* @0xc75a4 pop {r3, r4, r5, pc} */
/* @0xc75a8 ldr r3, [pc, #0x40] */
/* @0xc75ac ldr r3, [pc, r3] */
/* @0xc75b0 ldr r1, [r3] */
/* @0xc75b4 cmp r1, #0 */
/* @0xc75b8 beq 0xc75d8 <_Z24F_BUFFER_Async_Group_EndR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xc75bc mov r0, #1 */
/* @0xc75c0 mov r3, r0 */
/* @0xc75c4 b 0xc7578 <_Z24F_BUFFER_Async_Group_EndR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xc75c8 ldr r0, [pc, #0x24] */
/* @0xc75cc pop {r3, r4, r5, lr} */
/* @0xc75d0 add r0, pc, r0 */
/* @0xc75d4 b 0xd547c <_Z7YYErrorPKcz> */
/* @0xc75d8 ldr r0, [pc, #0x18] */
/* @0xc75dc add r0, pc, r0 */
/* @0xc75e0 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xc75e4 b 0xc7594 <_Z24F_BUFFER_Async_Group_EndR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0xc75e8 eorseq r6, r2, r4, ror r4 */
/* @0xc75ec eorseq r6, r2, r8, ror r4 */
/* @0xc75f0 eorseq r6, r2, r12, lsr #8 */
/* @0xc75f4 .word 0x00269fd0 */
/* @0xc75f8 eoreq r9, r6, r4, ror #31 */

/* ── FUNC 0xc75fc · InitBufferFunctions() · size=1352 · insn=338 */
/* @0xc75fc push {r4, lr} */
/* @0xc7600 mov r2, #3 */
/* @0xc7604 ldr r4, [pc, #0x40c] */
/* @0xc7608 mov r3, #0 */
/* @0xc760c ldr r1, [pc, #0x408] */
/* @0xc7610 add r4, pc, r4 */
/* @0xc7614 ldr r0, [pc, #0x404] */
/* @0xc7618 ldr r1, [r4, r1] */
/* @0xc761c add r0, pc, r0 */
/* @0xc7620 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc7624 ldr r1, [pc, #0x3f8] */
/* @0xc7628 ldr r0, [pc, #0x3f8] */
/* @0xc762c mov r2, #1 */
/* @0xc7630 mov r3, #0 */
/* @0xc7634 ldr r1, [r4, r1] */
/* @0xc7638 add r0, pc, r0 */
/* @0xc763c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc7640 ldr r1, [pc, #0x3e4] */
/* @0xc7644 ldr r0, [pc, #0x3e4] */
/* @0xc7648 mov r2, #3 */
/* @0xc764c mov r3, #0 */
/* @0xc7650 ldr r1, [r4, r1] */
/* @0xc7654 add r0, pc, r0 */
/* @0xc7658 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc765c ldr r1, [pc, #0x3d0] */
/* @0xc7660 ldr r0, [pc, #0x3d0] */
/* @0xc7664 mov r2, #2 */
/* @0xc7668 mov r3, #0 */
/* @0xc766c ldr r1, [r4, r1] */
/* @0xc7670 add r0, pc, r0 */
/* @0xc7674 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc7678 ldr r1, [pc, #0x3bc] */
/* @0xc767c ldr r0, [pc, #0x3bc] */
/* @0xc7680 mov r2, #4 */
/* @0xc7684 mov r3, #0 */
/* @0xc7688 ldr r1, [r4, r1] */
/* @0xc768c add r0, pc, r0 */
/* @0xc7690 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc7694 ldr r1, [pc, #0x3a8] */
/* @0xc7698 ldr r0, [pc, #0x3a8] */
/* @0xc769c mov r2, #3 */
/* @0xc76a0 mov r3, #0 */
/* @0xc76a4 ldr r1, [r4, r1] */
/* @0xc76a8 add r0, pc, r0 */
/* @0xc76ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc76b0 ldr r1, [pc, #0x394] */
/* @0xc76b4 ldr r0, [pc, #0x394] */
/* @0xc76b8 mov r2, #3 */
/* @0xc76bc mov r3, #0 */
/* @0xc76c0 ldr r1, [r4, r1] */
/* @0xc76c4 add r0, pc, r0 */
/* @0xc76c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc76cc ldr r1, [pc, #0x380] */
/* @0xc76d0 ldr r0, [pc, #0x380] */
/* @0xc76d4 mov r2, #2 */
/* @0xc76d8 mov r3, #0 */
/* @0xc76dc ldr r1, [r4, r1] */
/* @0xc76e0 add r0, pc, r0 */
/* @0xc76e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc76e8 ldr r1, [pc, #0x36c] */
/* @0xc76ec ldr r0, [pc, #0x36c] */
/* @0xc76f0 mov r2, #4 */
/* @0xc76f4 mov r3, #0 */
/* @0xc76f8 ldr r1, [r4, r1] */
/* @0xc76fc add r0, pc, r0 */
/* @0xc7700 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc7704 ldr r1, [pc, #0x358] */
/* @0xc7708 ldr r0, [pc, #0x358] */
/* @0xc770c mov r2, #1 */
/* @0xc7710 mov r3, #0 */
/* @0xc7714 ldr r1, [r4, r1] */
/* @0xc7718 add r0, pc, r0 */
/* @0xc771c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc7720 ldr r1, [pc, #0x344] */
/* @0xc7724 ldr r0, [pc, #0x344] */
/* @0xc7728 mov r2, #3 */
/* @0xc772c mov r3, #0 */
/* @0xc7730 ldr r1, [r4, r1] */
/* @0xc7734 add r0, pc, r0 */
/* @0xc7738 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc773c ldr r1, [pc, #0x330] */
/* @0xc7740 ldr r0, [pc, #0x330] */
/* @0xc7744 mov r2, #5 */
/* @0xc7748 mov r3, #0 */
/* @0xc774c ldr r1, [r4, r1] */
/* @0xc7750 add r0, pc, r0 */
/* @0xc7754 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc7758 ldr r1, [pc, #0x31c] */
/* @0xc775c ldr r0, [pc, #0x31c] */
/* @0xc7760 mov r2, #4 */
/* @0xc7764 mov r3, #0 */
/* @0xc7768 ldr r1, [r4, r1] */
/* @0xc776c add r0, pc, r0 */
/* @0xc7770 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc7774 ldr r1, [pc, #0x308] */
/* @0xc7778 ldr r0, [pc, #0x308] */
/* @0xc777c mov r2, #4 */
/* @0xc7780 mov r3, #0 */
/* @0xc7784 ldr r1, [r4, r1] */
/* @0xc7788 add r0, pc, r0 */
/* @0xc778c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc7790 ldr r1, [pc, #0x2f4] */
/* @0xc7794 ldr r0, [pc, #0x2f4] */
/* @0xc7798 mov r2, #1 */
/* @0xc779c mov r3, #0 */
/* @0xc77a0 ldr r1, [r4, r1] */
/* @0xc77a4 add r0, pc, r0 */
/* @0xc77a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc77ac ldr r1, [pc, #0x2e0] */
/* @0xc77b0 ldr r0, [pc, #0x2e0] */
/* @0xc77b4 mov r2, #0 */
/* @0xc77b8 mov r3, r2 */
/* @0xc77bc ldr r1, [r4, r1] */
/* @0xc77c0 add r0, pc, r0 */
/* @0xc77c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc77c8 ldr r1, [pc, #0x2cc] */
/* @0xc77cc ldr r0, [pc, #0x2cc] */
/* @0xc77d0 mov r2, #2 */
/* @0xc77d4 mov r3, #0 */
/* @0xc77d8 ldr r1, [r4, r1] */
/* @0xc77dc add r0, pc, r0 */
/* @0xc77e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc77e4 ldr r1, [pc, #0x2b8] */
/* @0xc77e8 ldr r0, [pc, #0x2b8] */
/* @0xc77ec mov r2, #5 */
/* @0xc77f0 mov r3, #0 */
/* @0xc77f4 ldr r1, [r4, r1] */
/* @0xc77f8 add r0, pc, r0 */
/* @0xc77fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc7800 ldr r1, [pc, #0x2a4] */
/* @0xc7804 ldr r0, [pc, #0x2a4] */
/* @0xc7808 mov r2, #1 */
/* @0xc780c mov r3, #0 */
/* @0xc7810 ldr r1, [r4, r1] */
/* @0xc7814 add r0, pc, r0 */
/* @0xc7818 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc781c ldr r1, [pc, #0x290] */
/* @0xc7820 ldr r0, [pc, #0x290] */
/* @0xc7824 mov r2, #1 */
/* @0xc7828 mov r3, #0 */
/* @0xc782c ldr r1, [r4, r1] */
/* @0xc7830 add r0, pc, r0 */
/* @0xc7834 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc7838 ldr r1, [pc, #0x27c] */
/* @0xc783c ldr r0, [pc, #0x27c] */
/* @0xc7840 mov r2, #1 */
/* @0xc7844 mov r3, #0 */
/* @0xc7848 ldr r1, [r4, r1] */
/* @0xc784c add r0, pc, r0 */
/* @0xc7850 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc7854 ldr r1, [pc, #0x268] */
/* @0xc7858 ldr r0, [pc, #0x268] */
/* @0xc785c mov r2, #5 */
/* @0xc7860 mov r3, #0 */
/* @0xc7864 ldr r1, [r4, r1] */
/* @0xc7868 add r0, pc, r0 */
/* @0xc786c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc7870 ldr r1, [pc, #0x254] */
/* @0xc7874 ldr r0, [pc, #0x254] */
/* @0xc7878 mov r2, #1 */
/* @0xc787c mov r3, #0 */
/* @0xc7880 ldr r1, [r4, r1] */
/* @0xc7884 add r0, pc, r0 */
/* @0xc7888 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc788c ldr r1, [pc, #0x240] */
/* @0xc7890 ldr r0, [pc, #0x240] */
/* @0xc7894 mov r2, #1 */
/* @0xc7898 mov r3, #0 */
/* @0xc789c ldr r1, [r4, r1] */
/* @0xc78a0 add r0, pc, r0 */
/* @0xc78a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc78a8 ldr r1, [pc, #0x22c] */
/* @0xc78ac ldr r0, [pc, #0x22c] */
/* @0xc78b0 mov r2, #2 */
/* @0xc78b4 mov r3, #0 */
/* @0xc78b8 ldr r1, [r4, r1] */
/* @0xc78bc add r0, pc, r0 */
/* @0xc78c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc78c4 ldr r1, [pc, #0x218] */
/* @0xc78c8 ldr r0, [pc, #0x218] */
/* @0xc78cc mov r2, #3 */
/* @0xc78d0 mov r3, #0 */
/* @0xc78d4 ldr r1, [r4, r1] */
/* @0xc78d8 add r0, pc, r0 */
/* @0xc78dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc78e0 ldr r1, [pc, #0x204] */
/* @0xc78e4 ldr r0, [pc, #0x204] */
/* @0xc78e8 mov r2, #3 */
/* @0xc78ec mov r3, #0 */
/* @0xc78f0 ldr r1, [r4, r1] */
/* @0xc78f4 add r0, pc, r0 */
/* @0xc78f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc78fc ldr r1, [pc, #0x1f0] */
/* @0xc7900 ldr r0, [pc, #0x1f0] */
/* @0xc7904 mov r2, #3 */
/* @0xc7908 mov r3, #0 */
/* @0xc790c ldr r1, [r4, r1] */
/* @0xc7910 add r0, pc, r0 */
/* @0xc7914 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc7918 ldr r1, [pc, #0x1dc] */
/* @0xc791c ldr r0, [pc, #0x1dc] */
/* @0xc7920 mov r2, #1 */
/* @0xc7924 mov r3, #0 */
/* @0xc7928 ldr r1, [r4, r1] */
/* @0xc792c add r0, pc, r0 */
/* @0xc7930 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc7934 ldr r1, [pc, #0x1c8] */
/* @0xc7938 ldr r0, [pc, #0x1c8] */
/* @0xc793c mov r2, #3 */
/* @0xc7940 mov r3, #0 */
/* @0xc7944 ldr r1, [r4, r1] */
/* @0xc7948 add r0, pc, r0 */
/* @0xc794c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc7950 ldr r1, [pc, #0x1b4] */
/* @0xc7954 ldr r0, [pc, #0x1b4] */
/* @0xc7958 mov r2, #1 */
/* @0xc795c mov r3, #0 */
/* @0xc7960 ldr r1, [r4, r1] */
/* @0xc7964 add r0, pc, r0 */
/* @0xc7968 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc796c ldr r1, [pc, #0x1a0] */
/* @0xc7970 ldr r0, [pc, #0x1a0] */
/* @0xc7974 mov r2, #1 */
/* @0xc7978 mov r3, #0 */
/* @0xc797c ldr r1, [r4, r1] */
/* @0xc7980 add r0, pc, r0 */
/* @0xc7984 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc7988 ldr r1, [pc, #0x18c] */
/* @0xc798c ldr r0, [pc, #0x18c] */
/* @0xc7990 mov r2, #5 */
/* @0xc7994 mov r3, #0 */
/* @0xc7998 ldr r1, [r4, r1] */
/* @0xc799c add r0, pc, r0 */
/* @0xc79a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc79a4 ldr r1, [pc, #0x178] */
/* @0xc79a8 ldr r0, [pc, #0x178] */
/* @0xc79ac mov r2, #5 */
/* @0xc79b0 mov r3, #0 */
/* @0xc79b4 ldr r1, [r4, r1] */
/* @0xc79b8 add r0, pc, r0 */
/* @0xc79bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc79c0 ldr r1, [pc, #0x164] */
/* @0xc79c4 ldr r0, [pc, #0x164] */
/* @0xc79c8 mov r2, #3 */
/* @0xc79cc mov r3, #0 */
/* @0xc79d0 ldr r1, [r4, r1] */
/* @0xc79d4 add r0, pc, r0 */
/* @0xc79d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc79dc ldr r1, [pc, #0x150] */
/* @0xc79e0 ldr r0, [pc, #0x150] */
/* @0xc79e4 mov r2, #5 */
/* @0xc79e8 mov r3, #0 */
/* @0xc79ec ldr r1, [r4, r1] */
/* @0xc79f0 add r0, pc, r0 */
/* @0xc79f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc79f8 ldr r1, [pc, #0x13c] */
/* @0xc79fc ldr r0, [pc, #0x13c] */
/* @0xc7a00 mov r2, #5 */
/* @0xc7a04 mov r3, #0 */
/* @0xc7a08 ldr r1, [r4, r1] */
/* @0xc7a0c add r0, pc, r0 */
/* @0xc7a10 pop {r4, lr} */
/* @0xc7a14 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xc7a18 eorseq r10, r2, r0, asr #12 */
/* @0xc7a1c .word 0xffffbd98 */
/* @0xc7a20 eoreq r9, r6, r0, asr #31 */
/* @0xc7a24 .word 0xffffbd9c */
/* @0xc7a28 .word 0x00269fb4 */
/* @0xc7a2c .word 0xffffbda0 */
/* @0xc7a30 eoreq r9, r6, r8, lsr #31 */
/* @0xc7a34 .word 0xffffbda4 */
/* @0xc7a38 mlaeq r6, r12, pc, r9 */
/* @0xc7a3c .word 0xffffbda8 */
/* @0xc7a40 eoreq r9, r6, r12, lsl #31 */
/* @0xc7a44 .word 0xffffbdac */
/* @0xc7a48 eoreq r9, r6, r12, ror pc */
/* @0xc7a4c .word 0xffffbdb0 */
/* @0xc7a50 eoreq r9, r6, r12, ror #30 */
/* @0xc7a54 .word 0xffffbdb4 */
/* @0xc7a58 eoreq r9, r6, r12, asr pc */
/* @0xc7a5c .word 0xffffbdb8 */
/* @0xc7a60 eoreq r9, r6, r12, asr #30 */
/* @0xc7a64 .word 0xffffbdbc */
/* @0xc7a68 eoreq r9, r6, r0, asr #30 */
/* @0xc7a6c .word 0xffffbdc0 */
/* @0xc7a70 eoreq r9, r6, r0, lsr pc */
/* @0xc7a74 .word 0xffffbdc4 */
/* @0xc7a78 eoreq r9, r6, r4, lsr #30 */
/* @0xc7a7c .word 0xffffbdc8 */
/* @0xc7a80 eoreq r9, r6, r12, lsl pc */
/* @0xc7a84 .word 0xffffbdcc */
/* @0xc7a88 eoreq r9, r6, r4, lsl pc */
/* @0xc7a8c .word 0xffffbdd0 */
/* @0xc7a90 eoreq r9, r6, r12, lsl #30 */
/* @0xc7a94 .word 0xffffbdd4 */
/* @0xc7a98 eoreq r9, r6, r12, lsl #30 */
/* @0xc7a9c .word 0xffffbdd8 */
/* @0xc7aa0 eoreq r9, r6, r8, lsl #30 */
/* @0xc7aa4 .word 0xffffbddc */
/* @0xc7aa8 eoreq r9, r6, r8, lsl #30 */
/* @0xc7aac .word 0xffffbde0 */
/* @0xc7ab0 .word 0x00269ef8 */
/* @0xc7ab4 .word 0xffffbde4 */
/* @0xc7ab8 eoreq r9, r6, r12, ror #29 */
/* @0xc7abc .word 0xffffbde8 */
/* @0xc7ac0 eoreq r9, r6, r0, ror #29 */
/* @0xc7ac4 .word 0xffffbdec */
/* @0xc7ac8 .word 0x00269edc */
/* @0xc7acc .word 0xffffbdf0 */
/* @0xc7ad0 eoreq r9, r6, r12, asr #29 */
/* @0xc7ad4 .word 0xffffbdf4 */
/* @0xc7ad8 eoreq r9, r6, r0, asr #29 */
/* @0xc7adc .word 0xffffbdf8 */
/* @0xc7ae0 .word 0x00269eb0 */
/* @0xc7ae4 .word 0xffffbdfc */
/* @0xc7ae8 eoreq r9, r6, r4, lsr #29 */
/* @0xc7aec .word 0xffffbe00 */
/* @0xc7af0 mlaeq r6, r4, lr, r9 */
/* @0xc7af4 .word 0xffffbe04 */
/* @0xc7af8 eoreq r9, r6, r4, lsl #29 */
/* @0xc7afc .word 0xffffbe08 */
/* @0xc7b00 eoreq r9, r6, r0, lsl #29 */
/* @0xc7b04 .word 0xffffbe0c */
/* @0xc7b08 eoreq r9, r6, r12, ror lr */
/* @0xc7b0c .word 0xffffbe10 */
/* @0xc7b10 eoreq r9, r6, r12, ror lr */
/* @0xc7b14 .word 0xffffbe14 */
/* @0xc7b18 eoreq r9, r6, r0, ror lr */
/* @0xc7b1c .word 0xffffbe18 */
/* @0xc7b20 eoreq r9, r6, r8, ror #28 */
/* @0xc7b24 .word 0xffffbe1c */
/* @0xc7b28 eoreq r9, r6, r0, ror #28 */
/* @0xc7b2c .word 0xffffbe20 */
/* @0xc7b30 eoreq r9, r6, r8, asr lr */
/* @0xc7b34 .word 0xffffbe24 */
/* @0xc7b38 eoreq r9, r6, r0, ror #28 */
/* @0xc7b3c .word 0xffffbe28 */
/* @0xc7b40 eoreq r9, r6, r12, ror #28 */

/* ── FUNC 0xc7b44 · FreeAllBuffers() · size=100 · insn=25 */
/* @0xc7b44 push {r3, r4, r5, r6, r7, lr} */
/* @0xc7b48 ldr r5, [pc, #0x54] */
/* @0xc7b4c add r5, pc, r5 */
/* @0xc7b50 ldr r3, [r5] */
/* @0xc7b54 cmp r3, #0 */
/* @0xc7b58 pople {r3, r4, r5, r6, r7, pc} */
/* @0xc7b5c mov r4, #0 */
/* @0xc7b60 mov r7, r5 */
/* @0xc7b64 mov r6, r4 */
/* @0xc7b68 ldr r3, [r5, #0x4] */
/* @0xc7b6c ldr r3, [r3, r4, lsl #2] */
/* @0xc7b70 cmp r3, #0 */
/* @0xc7b74 mov r0, r3 */
/* @0xc7b78 beq 0xc7b90 <_Z14FreeAllBuffersv+0x4c> */
/* @0xc7b7c ldr r3, [r3] */
/* @0xc7b80 ldr r3, [r3, #0x4] */
/* @0xc7b84 blx r3 */
/* @0xc7b88 ldr r3, [r5, #0x4] */
/* @0xc7b8c str r6, [r3, r4, lsl #2] */
/* @0xc7b90 ldr r3, [r7] */
/* @0xc7b94 add r4, r4, #1 */
/* @0xc7b98 cmp r3, r4 */
/* @0xc7b9c bgt 0xc7b68 <_Z14FreeAllBuffersv+0x24> */
/* @0xc7ba0 pop {r3, r4, r5, r6, r7, pc} */
/* @0xc7ba4 eorseq r2, r11, r8, asr #11 */

/* ── FUNC 0xc7ba8 · TestBuffers() · size=4 · insn=1 */
/* @0xc7ba8 bx lr */

/* ── FUNC 0xc7bac · F_Vertex_Float4_release(RValue&, CInstance*, CInstance*, int, RValue*) · size=264 · insn=66 */
/* @0xc7bac push {r4, r5, r6, lr} */
/* @0xc7bb0 sub sp, sp, #8 */
/* @0xc7bb4 ldr r3, [pc, #0xf0] */
/* @0xc7bb8 mov r1, #0 */
/* @0xc7bbc ldr r5, [sp, #0x18] */
/* @0xc7bc0 add r3, pc, r3 */
/* @0xc7bc4 mov r0, r5 */
/* @0xc7bc8 ldr r4, [r3] */
/* @0xc7bcc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc7bd0 ldr r4, [r4, r0, lsl #2] */
/* @0xc7bd4 ldr r1, [r4, #0x2c] */
/* @0xc7bd8 ldr r3, [r4, #0xc] */
/* @0xc7bdc ldr r2, [r4, #0x4] */
/* @0xc7be0 ldr r1, [r1, #0x14] */
/* @0xc7be4 add r0, r1, r3 */
/* @0xc7be8 cmp r2, r0 */
/* @0xc7bec blo 0xc7c74 <_Z23F_Vertex_Float4_releaseR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0xc7bf0 ldr r6, [r4] */
/* @0xc7bf4 mov r0, r5 */
/* @0xc7bf8 mov r1, #1 */
/* @0xc7bfc add r6, r6, r3 */
/* @0xc7c00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc7c04 mov r1, #2 */
/* @0xc7c08 str r0, [r6] */
/* @0xc7c0c mov r0, r5 */
/* @0xc7c10 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc7c14 mov r1, #3 */
/* @0xc7c18 str r0, [r6, #0x4] */
/* @0xc7c1c mov r0, r5 */
/* @0xc7c20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc7c24 mov r1, #4 */
/* @0xc7c28 str r0, [r6, #0x8] */
/* @0xc7c2c mov r0, r5 */
/* @0xc7c30 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc7c34 ldr r3, [r4, #0x10] */
/* @0xc7c38 ldr r1, [r4, #0x14] */
/* @0xc7c3c add r3, r3, #1 */
/* @0xc7c40 ldr r2, [r4, #0xc] */
/* @0xc7c44 cmp r3, r1 */
/* @0xc7c48 add r2, r2, #16 */
/* @0xc7c4c str r0, [r6, #0xc] */
/* @0xc7c50 str r3, [r4, #0x10] */
/* @0xc7c54 ldrhs r3, [r4, #0x1c] */
/* @0xc7c58 str r2, [r4, #0xc] */
/* @0xc7c5c movhs r2, #0 */
/* @0xc7c60 addhs r3, r3, #1 */
/* @0xc7c64 strhs r2, [r4, #0x10] */
/* @0xc7c68 strhs r3, [r4, #0x1c] */
/* @0xc7c6c add sp, sp, #8 */
/* @0xc7c70 pop {r4, r5, r6, pc} */
/* @0xc7c74 add r1, r1, r2 */
/* @0xc7c78 ldr r0, [r4] */
/* @0xc7c7c add r1, r1, r2, lsr #1 */
/* @0xc7c80 mov r2, #0 */
/* @0xc7c84 str r1, [r4, #0x4] */
/* @0xc7c88 mov r3, #74 */
/* @0xc7c8c str r2, [sp] */
/* @0xc7c90 ldr r2, [pc, #0x18] */
/* @0xc7c94 add r2, pc, r2 */
/* @0xc7c98 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc7c9c ldr r3, [r4, #0xc] */
/* @0xc7ca0 mov r6, r0 */
/* @0xc7ca4 str r0, [r4] */
/* @0xc7ca8 b 0xc7bf4 <_Z23F_Vertex_Float4_releaseR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0xc7cac eorseq r2, r11, r4, ror r5 */
/* @0xc7cb0 mlaeq r6, r12, r3, r9 */

/* ── FUNC 0xc7cb4 · F_Vertex_Float1_release(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0xc7cb4 push {r4, r5, lr} */
/* @0xc7cb8 sub sp, sp, #12 */
/* @0xc7cbc ldr r3, [pc, #0xc0] */
/* @0xc7cc0 mov r1, #0 */
/* @0xc7cc4 ldr r5, [sp, #0x18] */
/* @0xc7cc8 add r3, pc, r3 */
/* @0xc7ccc mov r0, r5 */
/* @0xc7cd0 ldr r4, [r3] */
/* @0xc7cd4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc7cd8 ldr r4, [r4, r0, lsl #2] */
/* @0xc7cdc ldr r1, [r4, #0x2c] */
/* @0xc7ce0 ldr r3, [r4, #0xc] */
/* @0xc7ce4 ldr r2, [r4, #0x4] */
/* @0xc7ce8 ldr r1, [r1, #0x14] */
/* @0xc7cec add r0, r1, r3 */
/* @0xc7cf0 cmp r2, r0 */
/* @0xc7cf4 blo 0xc7d4c <_Z23F_Vertex_Float1_releaseR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0xc7cf8 ldr r2, [r4] */
/* @0xc7cfc mov r0, r5 */
/* @0xc7d00 mov r1, #1 */
/* @0xc7d04 add r5, r2, r3 */
/* @0xc7d08 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc7d0c ldr r2, [r4, #0x10] */
/* @0xc7d10 ldr r1, [r4, #0x14] */
/* @0xc7d14 add r2, r2, #1 */
/* @0xc7d18 ldr r3, [r4, #0xc] */
/* @0xc7d1c cmp r2, r1 */
/* @0xc7d20 add r3, r3, #4 */
/* @0xc7d24 str r0, [r5] */
/* @0xc7d28 str r3, [r4, #0xc] */
/* @0xc7d2c ldrhs r3, [r4, #0x1c] */
/* @0xc7d30 str r2, [r4, #0x10] */
/* @0xc7d34 movhs r2, #0 */
/* @0xc7d38 addhs r3, r3, #1 */
/* @0xc7d3c strhs r2, [r4, #0x10] */
/* @0xc7d40 strhs r3, [r4, #0x1c] */
/* @0xc7d44 add sp, sp, #12 */
/* @0xc7d48 pop {r4, r5, pc} */
/* @0xc7d4c add r1, r1, r2 */
/* @0xc7d50 ldr r0, [r4] */
/* @0xc7d54 add r1, r1, r2, lsr #1 */
/* @0xc7d58 mov r2, #0 */
/* @0xc7d5c str r1, [r4, #0x4] */
/* @0xc7d60 mov r3, #74 */
/* @0xc7d64 str r2, [sp] */
/* @0xc7d68 ldr r2, [pc, #0x18] */
/* @0xc7d6c add r2, pc, r2 */
/* @0xc7d70 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc7d74 ldr r3, [r4, #0xc] */
/* @0xc7d78 mov r2, r0 */
/* @0xc7d7c str r0, [r4] */
/* @0xc7d80 b 0xc7cfc <_Z23F_Vertex_Float1_releaseR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0xc7d84 eorseq r2, r11, r12, ror #8 */
/* @0xc7d88 eoreq r9, r6, r4, asr #5 */

/* ── FUNC 0xc7d8c · F_Vertex_ARGB_release(RValue&, CInstance*, CInstance*, int, RValue*) · size=236 · insn=59 */
/* @0xc7d8c push {r4, r5, r6, r7, lr} */
/* @0xc7d90 sub sp, sp, #12 */
/* @0xc7d94 ldr r3, [pc, #0xd4] */
/* @0xc7d98 mov r1, #0 */
/* @0xc7d9c ldr r6, [sp, #0x20] */
/* @0xc7da0 add r3, pc, r3 */
/* @0xc7da4 mov r0, r6 */
/* @0xc7da8 ldr r4, [r3] */
/* @0xc7dac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc7db0 ldr r4, [r4, r0, lsl #2] */
/* @0xc7db4 ldr r2, [r4, #0x2c] */
/* @0xc7db8 ldr r5, [r4, #0xc] */
/* @0xc7dbc ldr r3, [r4, #0x4] */
/* @0xc7dc0 ldr r2, [r2, #0x14] */
/* @0xc7dc4 add r1, r2, r5 */
/* @0xc7dc8 cmp r3, r1 */
/* @0xc7dcc blo 0xc7e38 <_Z21F_Vertex_ARGB_releaseR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xc7dd0 ldr r7, [r4] */
/* @0xc7dd4 mov r0, r6 */
/* @0xc7dd8 mov r1, #1 */
/* @0xc7ddc bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0xc7de0 bic r3, r0, #16711680 */
/* @0xc7de4 ubfx r2, r0, #0x10, #0x8 */
/* @0xc7de8 bic r3, r3, #255 */
/* @0xc7dec uxtb r0, r0 */
/* @0xc7df0 orr r3, r3, r2 */
/* @0xc7df4 orr r3, r3, r0, lsl #16 */
/* @0xc7df8 str r3, [r7, r5] */
/* @0xc7dfc ldr r3, [r4, #0x10] */
/* @0xc7e00 ldr r1, [r4, #0x14] */
/* @0xc7e04 add r3, r3, #1 */
/* @0xc7e08 ldr r2, [r4, #0xc] */
/* @0xc7e0c cmp r3, r1 */
/* @0xc7e10 str r3, [r4, #0x10] */
/* @0xc7e14 add r3, r2, #4 */
/* @0xc7e18 str r3, [r4, #0xc] */
/* @0xc7e1c ldrhs r3, [r4, #0x1c] */
/* @0xc7e20 movhs r2, #0 */
/* @0xc7e24 strhs r2, [r4, #0x10] */
/* @0xc7e28 addhs r3, r3, #1 */
/* @0xc7e2c strhs r3, [r4, #0x1c] */
/* @0xc7e30 add sp, sp, #12 */
/* @0xc7e34 pop {r4, r5, r6, r7, pc} */
/* @0xc7e38 add r2, r2, r3 */
/* @0xc7e3c ldr r0, [r4] */
/* @0xc7e40 add r1, r2, r3, lsr #1 */
/* @0xc7e44 mov r2, #0 */
/* @0xc7e48 str r1, [r4, #0x4] */
/* @0xc7e4c mov r3, #74 */
/* @0xc7e50 str r2, [sp] */
/* @0xc7e54 ldr r2, [pc, #0x18] */
/* @0xc7e58 add r2, pc, r2 */
/* @0xc7e5c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc7e60 ldr r5, [r4, #0xc] */
/* @0xc7e64 mov r7, r0 */
/* @0xc7e68 str r0, [r4] */
/* @0xc7e6c b 0xc7dd4 <_Z21F_Vertex_ARGB_releaseR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0xc7e70 mlaseq r11, r4, r3, r2 */
/* @0xc7e74 .word 0x002691d8 */

/* ── FUNC 0xc7e78 · F_Vertex_TexCoord_release(RValue&, CInstance*, CInstance*, int, RValue*) · size=232 · insn=58 */
/* @0xc7e78 push {r4, r5, r6, lr} */
/* @0xc7e7c sub sp, sp, #8 */
/* @0xc7e80 ldr r3, [pc, #0xd0] */
/* @0xc7e84 mov r1, #0 */
/* @0xc7e88 ldr r5, [sp, #0x18] */
/* @0xc7e8c add r3, pc, r3 */
/* @0xc7e90 mov r0, r5 */
/* @0xc7e94 ldr r4, [r3] */
/* @0xc7e98 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc7e9c ldr r4, [r4, r0, lsl #2] */
/* @0xc7ea0 ldr r1, [r4, #0x2c] */
/* @0xc7ea4 ldr r3, [r4, #0xc] */
/* @0xc7ea8 ldr r2, [r4, #0x4] */
/* @0xc7eac ldr r1, [r1, #0x14] */
/* @0xc7eb0 add r0, r1, r3 */
/* @0xc7eb4 cmp r2, r0 */
/* @0xc7eb8 blo 0xc7f20 <_Z25F_Vertex_TexCoord_releaseR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0xc7ebc ldr r6, [r4] */
/* @0xc7ec0 mov r0, r5 */
/* @0xc7ec4 mov r1, #1 */
/* @0xc7ec8 add r6, r6, r3 */
/* @0xc7ecc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc7ed0 mov r1, #2 */
/* @0xc7ed4 str r0, [r6] */
/* @0xc7ed8 mov r0, r5 */
/* @0xc7edc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc7ee0 ldr r3, [r4, #0x10] */
/* @0xc7ee4 ldr r1, [r4, #0x14] */
/* @0xc7ee8 add r3, r3, #1 */
/* @0xc7eec ldr r2, [r4, #0xc] */
/* @0xc7ef0 cmp r3, r1 */
/* @0xc7ef4 add r2, r2, #8 */
/* @0xc7ef8 str r0, [r6, #0x4] */
/* @0xc7efc str r3, [r4, #0x10] */
/* @0xc7f00 ldrhs r3, [r4, #0x1c] */
/* @0xc7f04 str r2, [r4, #0xc] */
/* @0xc7f08 movhs r2, #0 */
/* @0xc7f0c addhs r3, r3, #1 */
/* @0xc7f10 strhs r2, [r4, #0x10] */
/* @0xc7f14 strhs r3, [r4, #0x1c] */
/* @0xc7f18 add sp, sp, #8 */
/* @0xc7f1c pop {r4, r5, r6, pc} */
/* @0xc7f20 add r1, r1, r2 */
/* @0xc7f24 ldr r0, [r4] */
/* @0xc7f28 add r1, r1, r2, lsr #1 */
/* @0xc7f2c mov r2, #0 */
/* @0xc7f30 str r1, [r4, #0x4] */
/* @0xc7f34 mov r3, #74 */
/* @0xc7f38 str r2, [sp] */
/* @0xc7f3c ldr r2, [pc, #0x18] */
/* @0xc7f40 add r2, pc, r2 */
/* @0xc7f44 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc7f48 ldr r3, [r4, #0xc] */
/* @0xc7f4c mov r6, r0 */
/* @0xc7f50 str r0, [r4] */
/* @0xc7f54 b 0xc7ec0 <_Z25F_Vertex_TexCoord_releaseR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0xc7f58 eorseq r2, r11, r8, lsr #5 */
/* @0xc7f5c .word 0x002690f0 */

/* ── FUNC 0xc7f60 · F_Vertex_Float2_release(RValue&, CInstance*, CInstance*, int, RValue*) · size=232 · insn=58 */
/* @0xc7f60 push {r4, r5, r6, lr} */
/* @0xc7f64 sub sp, sp, #8 */
/* @0xc7f68 ldr r3, [pc, #0xd0] */
/* @0xc7f6c mov r1, #0 */
/* @0xc7f70 ldr r5, [sp, #0x18] */
/* @0xc7f74 add r3, pc, r3 */
/* @0xc7f78 mov r0, r5 */
/* @0xc7f7c ldr r4, [r3] */
/* @0xc7f80 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc7f84 ldr r4, [r4, r0, lsl #2] */
/* @0xc7f88 ldr r1, [r4, #0x2c] */
/* @0xc7f8c ldr r3, [r4, #0xc] */
/* @0xc7f90 ldr r2, [r4, #0x4] */
/* @0xc7f94 ldr r1, [r1, #0x14] */
/* @0xc7f98 add r0, r1, r3 */
/* @0xc7f9c cmp r2, r0 */
/* @0xc7fa0 blo 0xc8008 <_Z23F_Vertex_Float2_releaseR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0xc7fa4 ldr r6, [r4] */
/* @0xc7fa8 mov r0, r5 */
/* @0xc7fac mov r1, #1 */
/* @0xc7fb0 add r6, r6, r3 */
/* @0xc7fb4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc7fb8 mov r1, #2 */
/* @0xc7fbc str r0, [r6] */
/* @0xc7fc0 mov r0, r5 */
/* @0xc7fc4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc7fc8 ldr r3, [r4, #0x10] */
/* @0xc7fcc ldr r1, [r4, #0x14] */
/* @0xc7fd0 add r3, r3, #1 */
/* @0xc7fd4 ldr r2, [r4, #0xc] */
/* @0xc7fd8 cmp r3, r1 */
/* @0xc7fdc add r2, r2, #8 */
/* @0xc7fe0 str r0, [r6, #0x4] */
/* @0xc7fe4 str r3, [r4, #0x10] */
/* @0xc7fe8 ldrhs r3, [r4, #0x1c] */
/* @0xc7fec str r2, [r4, #0xc] */
/* @0xc7ff0 movhs r2, #0 */
/* @0xc7ff4 addhs r3, r3, #1 */
/* @0xc7ff8 strhs r2, [r4, #0x10] */
/* @0xc7ffc strhs r3, [r4, #0x1c] */
/* @0xc8000 add sp, sp, #8 */
/* @0xc8004 pop {r4, r5, r6, pc} */
/* @0xc8008 add r1, r1, r2 */
/* @0xc800c ldr r0, [r4] */
/* @0xc8010 add r1, r1, r2, lsr #1 */
/* @0xc8014 mov r2, #0 */
/* @0xc8018 str r1, [r4, #0x4] */
/* @0xc801c mov r3, #74 */
/* @0xc8020 str r2, [sp] */
/* @0xc8024 ldr r2, [pc, #0x18] */
/* @0xc8028 add r2, pc, r2 */
/* @0xc802c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc8030 ldr r3, [r4, #0xc] */
/* @0xc8034 mov r6, r0 */
/* @0xc8038 str r0, [r4] */
/* @0xc803c b 0xc7fa8 <_Z23F_Vertex_Float2_releaseR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0xc8040 eorseq r2, r11, r0, asr #3 */
/* @0xc8044 eoreq r9, r6, r8 */

/* ── FUNC 0xc8048 · F_Vertex_Position_release(RValue&, CInstance*, CInstance*, int, RValue*) · size=232 · insn=58 */
/* @0xc8048 push {r4, r5, r6, lr} */
/* @0xc804c sub sp, sp, #8 */
/* @0xc8050 ldr r3, [pc, #0xd0] */
/* @0xc8054 mov r1, #0 */
/* @0xc8058 ldr r5, [sp, #0x18] */
/* @0xc805c add r3, pc, r3 */
/* @0xc8060 mov r0, r5 */
/* @0xc8064 ldr r4, [r3] */
/* @0xc8068 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc806c ldr r4, [r4, r0, lsl #2] */
/* @0xc8070 ldr r1, [r4, #0x2c] */
/* @0xc8074 ldr r3, [r4, #0xc] */
/* @0xc8078 ldr r2, [r4, #0x4] */
/* @0xc807c ldr r1, [r1, #0x14] */
/* @0xc8080 add r0, r1, r3 */
/* @0xc8084 cmp r2, r0 */
/* @0xc8088 blo 0xc80f0 <_Z25F_Vertex_Position_releaseR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0xc808c ldr r6, [r4] */
/* @0xc8090 mov r0, r5 */
/* @0xc8094 mov r1, #1 */
/* @0xc8098 add r6, r6, r3 */
/* @0xc809c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc80a0 mov r1, #2 */
/* @0xc80a4 str r0, [r6] */
/* @0xc80a8 mov r0, r5 */
/* @0xc80ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc80b0 ldr r3, [r4, #0x10] */
/* @0xc80b4 ldr r1, [r4, #0x14] */
/* @0xc80b8 add r3, r3, #1 */
/* @0xc80bc ldr r2, [r4, #0xc] */
/* @0xc80c0 cmp r3, r1 */
/* @0xc80c4 add r2, r2, #8 */
/* @0xc80c8 str r0, [r6, #0x4] */
/* @0xc80cc str r3, [r4, #0x10] */
/* @0xc80d0 ldrhs r3, [r4, #0x1c] */
/* @0xc80d4 str r2, [r4, #0xc] */
/* @0xc80d8 movhs r2, #0 */
/* @0xc80dc addhs r3, r3, #1 */
/* @0xc80e0 strhs r2, [r4, #0x10] */
/* @0xc80e4 strhs r3, [r4, #0x1c] */
/* @0xc80e8 add sp, sp, #8 */
/* @0xc80ec pop {r4, r5, r6, pc} */
/* @0xc80f0 add r1, r1, r2 */
/* @0xc80f4 ldr r0, [r4] */
/* @0xc80f8 add r1, r1, r2, lsr #1 */
/* @0xc80fc mov r2, #0 */
/* @0xc8100 str r1, [r4, #0x4] */
/* @0xc8104 mov r3, #74 */
/* @0xc8108 str r2, [sp] */
/* @0xc810c ldr r2, [pc, #0x18] */
/* @0xc8110 add r2, pc, r2 */
/* @0xc8114 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc8118 ldr r3, [r4, #0xc] */
/* @0xc811c mov r6, r0 */
/* @0xc8120 str r0, [r4] */
/* @0xc8124 b 0xc8090 <_Z25F_Vertex_Position_releaseR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0xc8128 ldrsbteq r2, [r11], -r8 */
/* @0xc812c eoreq r8, r6, r0, lsr #30 */

/* ── FUNC 0xc8130 · F_Vertex_Colour_release(RValue&, CInstance*, CInstance*, int, RValue*) · size=288 · insn=72 */
/* @0xc8130 push {r4, r5, r6, r7, lr} */
/* @0xc8134 sub sp, sp, #12 */
/* @0xc8138 ldr r3, [pc, #0x108] */
/* @0xc813c mov r1, #0 */
/* @0xc8140 ldr r5, [sp, #0x20] */
/* @0xc8144 add r3, pc, r3 */
/* @0xc8148 mov r0, r5 */
/* @0xc814c ldr r4, [r3] */
/* @0xc8150 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc8154 ldr r4, [r4, r0, lsl #2] */
/* @0xc8158 ldr r1, [r4, #0x2c] */
/* @0xc815c ldr r3, [r4, #0xc] */
/* @0xc8160 ldr r2, [r4, #0x4] */
/* @0xc8164 ldr r1, [r1, #0x14] */
/* @0xc8168 add r0, r1, r3 */
/* @0xc816c cmp r2, r0 */
/* @0xc8170 blo 0xc820c <_Z23F_Vertex_Colour_releaseR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0xc8174 ldr r6, [r4] */
/* @0xc8178 mov r1, #1 */
/* @0xc817c mov r0, r5 */
/* @0xc8180 add r6, r6, r3 */
/* @0xc8184 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0xc8188 mov r1, #2 */
/* @0xc818c mov r7, r0 */
/* @0xc8190 mov r0, r5 */
/* @0xc8194 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc8198 vldr s15, [pc, #164] */
/* @0xc819c vmov s14, r0 */
/* @0xc81a0 vmul.f32 s15, s14, s15 */
/* @0xc81a4 vcvt.s32.f32 s15, s15 */
/* @0xc81a8 vmov r2, s15 */
/* @0xc81ac cmp r2, #255 */
/* @0xc81b0 movgt r2, #-16777216 */
/* @0xc81b4 bgt 0xc81c4 <_Z23F_Vertex_Colour_releaseR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0xc81b8 cmp r2, #0 */
/* @0xc81bc lslge r2, r2, #24 */
/* @0xc81c0 movlt r2, #0 */
/* @0xc81c4 bic r7, r7, #-16777216 */
/* @0xc81c8 orr r7, r2, r7 */
/* @0xc81cc str r7, [r6] */
/* @0xc81d0 ldr r3, [r4, #0x10] */
/* @0xc81d4 ldr r1, [r4, #0x14] */
/* @0xc81d8 add r3, r3, #1 */
/* @0xc81dc ldr r2, [r4, #0xc] */
/* @0xc81e0 cmp r3, r1 */
/* @0xc81e4 str r3, [r4, #0x10] */
/* @0xc81e8 add r3, r2, #4 */
/* @0xc81ec str r3, [r4, #0xc] */
/* @0xc81f0 ldrhs r3, [r4, #0x1c] */
/* @0xc81f4 movhs r2, #0 */
/* @0xc81f8 strhs r2, [r4, #0x10] */
/* @0xc81fc addhs r3, r3, #1 */
/* @0xc8200 strhs r3, [r4, #0x1c] */
/* @0xc8204 add sp, sp, #12 */
/* @0xc8208 pop {r4, r5, r6, r7, pc} */
/* @0xc820c add r1, r1, r2 */
/* @0xc8210 ldr r0, [r4] */
/* @0xc8214 add r1, r1, r2, lsr #1 */
/* @0xc8218 mov r2, #0 */
/* @0xc821c str r1, [r4, #0x4] */
/* @0xc8220 mov r3, #74 */
/* @0xc8224 str r2, [sp] */
/* @0xc8228 ldr r2, [pc, #0x1c] */
/* @0xc822c add r2, pc, r2 */
/* @0xc8230 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc8234 ldr r3, [r4, #0xc] */
/* @0xc8238 mov r6, r0 */
/* @0xc823c str r0, [r4] */
/* @0xc8240 b 0xc8178 <_Z23F_Vertex_Colour_releaseR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0xc8244 cmnmi pc, #0 */
/* @0xc8248 ldrshteq r1, [r11], -r0 */
/* @0xc824c eoreq r8, r6, r4, lsl #28 */

/* ── FUNC 0xc8250 · F_Vertex_Float3_release(RValue&, CInstance*, CInstance*, int, RValue*) · size=248 · insn=62 */
/* @0xc8250 push {r4, r5, r6, lr} */
/* @0xc8254 sub sp, sp, #8 */
/* @0xc8258 ldr r3, [pc, #0xe0] */
/* @0xc825c mov r1, #0 */
/* @0xc8260 ldr r5, [sp, #0x18] */
/* @0xc8264 add r3, pc, r3 */
/* @0xc8268 mov r0, r5 */
/* @0xc826c ldr r4, [r3] */
/* @0xc8270 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc8274 ldr r4, [r4, r0, lsl #2] */
/* @0xc8278 ldr r1, [r4, #0x2c] */
/* @0xc827c ldr r3, [r4, #0xc] */
/* @0xc8280 ldr r2, [r4, #0x4] */
/* @0xc8284 ldr r1, [r1, #0x14] */
/* @0xc8288 add r0, r1, r3 */
/* @0xc828c cmp r2, r0 */
/* @0xc8290 blo 0xc8308 <_Z23F_Vertex_Float3_releaseR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xc8294 ldr r6, [r4] */
/* @0xc8298 mov r0, r5 */
/* @0xc829c mov r1, #1 */
/* @0xc82a0 add r6, r6, r3 */
/* @0xc82a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc82a8 mov r1, #2 */
/* @0xc82ac str r0, [r6] */
/* @0xc82b0 mov r0, r5 */
/* @0xc82b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc82b8 mov r1, #3 */
/* @0xc82bc str r0, [r6, #0x4] */
/* @0xc82c0 mov r0, r5 */
/* @0xc82c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc82c8 ldr r3, [r4, #0x10] */
/* @0xc82cc ldr r1, [r4, #0x14] */
/* @0xc82d0 add r3, r3, #1 */
/* @0xc82d4 ldr r2, [r4, #0xc] */
/* @0xc82d8 cmp r3, r1 */
/* @0xc82dc add r2, r2, #12 */
/* @0xc82e0 str r0, [r6, #0x8] */
/* @0xc82e4 str r3, [r4, #0x10] */
/* @0xc82e8 ldrhs r3, [r4, #0x1c] */
/* @0xc82ec str r2, [r4, #0xc] */
/* @0xc82f0 movhs r2, #0 */
/* @0xc82f4 addhs r3, r3, #1 */
/* @0xc82f8 strhs r2, [r4, #0x10] */
/* @0xc82fc strhs r3, [r4, #0x1c] */
/* @0xc8300 add sp, sp, #8 */
/* @0xc8304 pop {r4, r5, r6, pc} */
/* @0xc8308 add r1, r1, r2 */
/* @0xc830c ldr r0, [r4] */
/* @0xc8310 add r1, r1, r2, lsr #1 */
/* @0xc8314 mov r2, #0 */
/* @0xc8318 str r1, [r4, #0x4] */
/* @0xc831c mov r3, #74 */
/* @0xc8320 str r2, [sp] */
/* @0xc8324 ldr r2, [pc, #0x18] */
/* @0xc8328 add r2, pc, r2 */
/* @0xc832c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc8330 ldr r3, [r4, #0xc] */
/* @0xc8334 mov r6, r0 */
/* @0xc8338 str r0, [r4] */
/* @0xc833c b 0xc8298 <_Z23F_Vertex_Float3_releaseR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0xc8340 ldrsbteq r1, [r11], -r0 */
/* @0xc8344 eoreq r8, r6, r8, lsl #26 */

/* ── FUNC 0xc8348 · F_Vertex_Position_3d_release(RValue&, CInstance*, CInstance*, int, RValue*) · size=248 · insn=62 */
/* @0xc8348 push {r4, r5, r6, lr} */
/* @0xc834c sub sp, sp, #8 */
/* @0xc8350 ldr r3, [pc, #0xe0] */
/* @0xc8354 mov r1, #0 */
/* @0xc8358 ldr r5, [sp, #0x18] */
/* @0xc835c add r3, pc, r3 */
/* @0xc8360 mov r0, r5 */
/* @0xc8364 ldr r4, [r3] */
/* @0xc8368 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc836c ldr r4, [r4, r0, lsl #2] */
/* @0xc8370 ldr r1, [r4, #0x2c] */
/* @0xc8374 ldr r3, [r4, #0xc] */
/* @0xc8378 ldr r2, [r4, #0x4] */
/* @0xc837c ldr r1, [r1, #0x14] */
/* @0xc8380 add r0, r1, r3 */
/* @0xc8384 cmp r2, r0 */
/* @0xc8388 blo 0xc8400 <_Z28F_Vertex_Position_3d_releaseR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xc838c ldr r6, [r4] */
/* @0xc8390 mov r0, r5 */
/* @0xc8394 mov r1, #1 */
/* @0xc8398 add r6, r6, r3 */
/* @0xc839c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc83a0 mov r1, #2 */
/* @0xc83a4 str r0, [r6] */
/* @0xc83a8 mov r0, r5 */
/* @0xc83ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc83b0 mov r1, #3 */
/* @0xc83b4 str r0, [r6, #0x4] */
/* @0xc83b8 mov r0, r5 */
/* @0xc83bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc83c0 ldr r3, [r4, #0x10] */
/* @0xc83c4 ldr r1, [r4, #0x14] */
/* @0xc83c8 add r3, r3, #1 */
/* @0xc83cc ldr r2, [r4, #0xc] */
/* @0xc83d0 cmp r3, r1 */
/* @0xc83d4 add r2, r2, #12 */
/* @0xc83d8 str r0, [r6, #0x8] */
/* @0xc83dc str r3, [r4, #0x10] */
/* @0xc83e0 ldrhs r3, [r4, #0x1c] */
/* @0xc83e4 str r2, [r4, #0xc] */
/* @0xc83e8 movhs r2, #0 */
/* @0xc83ec addhs r3, r3, #1 */
/* @0xc83f0 strhs r2, [r4, #0x10] */
/* @0xc83f4 strhs r3, [r4, #0x1c] */
/* @0xc83f8 add sp, sp, #8 */
/* @0xc83fc pop {r4, r5, r6, pc} */
/* @0xc8400 add r1, r1, r2 */
/* @0xc8404 ldr r0, [r4] */
/* @0xc8408 add r1, r1, r2, lsr #1 */
/* @0xc840c mov r2, #0 */
/* @0xc8410 str r1, [r4, #0x4] */
/* @0xc8414 mov r3, #74 */
/* @0xc8418 str r2, [sp] */
/* @0xc841c ldr r2, [pc, #0x18] */
/* @0xc8420 add r2, pc, r2 */
/* @0xc8424 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc8428 ldr r3, [r4, #0xc] */
/* @0xc842c mov r6, r0 */
/* @0xc8430 str r0, [r4] */
/* @0xc8434 b 0xc8390 <_Z28F_Vertex_Position_3d_releaseR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0xc8438 ldrsbteq r1, [r11], -r8 */
/* @0xc843c eoreq r8, r6, r0, lsl r12 */

/* ── FUNC 0xc8440 · F_Vertex_Normal_release(RValue&, CInstance*, CInstance*, int, RValue*) · size=256 · insn=64 */
/* @0xc8440 push {r4, r5, r6, lr} */
/* @0xc8444 sub sp, sp, #8 */
/* @0xc8448 ldr r3, [pc, #0xe8] */
/* @0xc844c mov r1, #0 */
/* @0xc8450 ldr r5, [sp, #0x18] */
/* @0xc8454 add r3, pc, r3 */
/* @0xc8458 mov r0, r5 */
/* @0xc845c ldr r4, [r3] */
/* @0xc8460 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc8464 ldr r4, [r4, r0, lsl #2] */
/* @0xc8468 cmp r4, #0 */
/* @0xc846c beq 0xc84f8 <_Z23F_Vertex_Normal_releaseR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xc8470 ldr r1, [r4, #0x2c] */
/* @0xc8474 ldr r3, [r4, #0xc] */
/* @0xc8478 ldr r2, [r4, #0x4] */
/* @0xc847c ldr r1, [r1, #0x14] */
/* @0xc8480 add r0, r1, r3 */
/* @0xc8484 cmp r2, r0 */
/* @0xc8488 blo 0xc8500 <_Z23F_Vertex_Normal_releaseR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0xc848c ldr r6, [r4] */
/* @0xc8490 mov r1, #1 */
/* @0xc8494 mov r0, r5 */
/* @0xc8498 add r6, r6, r3 */
/* @0xc849c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc84a0 mov r1, #2 */
/* @0xc84a4 str r0, [r6] */
/* @0xc84a8 mov r0, r5 */
/* @0xc84ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc84b0 mov r1, #3 */
/* @0xc84b4 str r0, [r6, #0x4] */
/* @0xc84b8 mov r0, r5 */
/* @0xc84bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc84c0 ldr r3, [r4, #0x10] */
/* @0xc84c4 ldr r1, [r4, #0x14] */
/* @0xc84c8 add r3, r3, #1 */
/* @0xc84cc ldr r2, [r4, #0xc] */
/* @0xc84d0 cmp r3, r1 */
/* @0xc84d4 add r2, r2, #12 */
/* @0xc84d8 str r0, [r6, #0x8] */
/* @0xc84dc str r3, [r4, #0x10] */
/* @0xc84e0 ldrhs r3, [r4, #0x1c] */
/* @0xc84e4 str r2, [r4, #0xc] */
/* @0xc84e8 movhs r2, #0 */
/* @0xc84ec addhs r3, r3, #1 */
/* @0xc84f0 strhs r2, [r4, #0x10] */
/* @0xc84f4 strhs r3, [r4, #0x1c] */
/* @0xc84f8 add sp, sp, #8 */
/* @0xc84fc pop {r4, r5, r6, pc} */
/* @0xc8500 add r1, r1, r2 */
/* @0xc8504 ldr r0, [r4] */
/* @0xc8508 add r1, r1, r2, lsr #1 */
/* @0xc850c mov r2, #0 */
/* @0xc8510 str r1, [r4, #0x4] */
/* @0xc8514 mov r3, #74 */
/* @0xc8518 str r2, [sp] */
/* @0xc851c ldr r2, [pc, #0x18] */
/* @0xc8520 add r2, pc, r2 */
/* @0xc8524 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc8528 ldr r3, [r4, #0xc] */
/* @0xc852c mov r6, r0 */
/* @0xc8530 str r0, [r4] */
/* @0xc8534 b 0xc8490 <_Z23F_Vertex_Normal_releaseR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0xc8538 eorseq r1, r11, r0, ror #25 */
/* @0xc853c eoreq r8, r6, r0, lsl r11 */

/* ── FUNC 0xc8540 · F_Vertex_ubyte4_release(RValue&, CInstance*, CInstance*, int, RValue*) · size=264 · insn=66 */
/* @0xc8540 push {r4, r5, r6, r7, r8, lr} */
/* @0xc8544 sub sp, sp, #8 */
/* @0xc8548 ldr r3, [pc, #0xf0] */
/* @0xc854c mov r1, #0 */
/* @0xc8550 ldr r5, [sp, #0x20] */
/* @0xc8554 add r3, pc, r3 */
/* @0xc8558 mov r0, r5 */
/* @0xc855c ldr r4, [r3] */
/* @0xc8560 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc8564 ldr r4, [r4, r0, lsl #2] */
/* @0xc8568 ldr r2, [r4, #0x2c] */
/* @0xc856c ldr r6, [r4, #0xc] */
/* @0xc8570 ldr r3, [r4, #0x4] */
/* @0xc8574 ldr r2, [r2, #0x14] */
/* @0xc8578 add r1, r2, r6 */
/* @0xc857c cmp r3, r1 */
/* @0xc8580 blo 0xc8608 <_Z23F_Vertex_ubyte4_releaseR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0xc8584 ldr r8, [r4] */
/* @0xc8588 mov r0, r5 */
/* @0xc858c mov r1, #1 */
/* @0xc8590 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0xc8594 mov r1, #2 */
/* @0xc8598 add r7, r8, r6 */
/* @0xc859c strb r0, [r8, r6] */
/* @0xc85a0 mov r0, r5 */
/* @0xc85a4 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0xc85a8 mov r1, #3 */
/* @0xc85ac strb r0, [r7, #0x1] */
/* @0xc85b0 mov r0, r5 */
/* @0xc85b4 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0xc85b8 mov r1, #4 */
/* @0xc85bc strb r0, [r7, #0x2] */
/* @0xc85c0 mov r0, r5 */
/* @0xc85c4 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0xc85c8 strb r0, [r7, #0x3] */
/* @0xc85cc ldr r3, [r4, #0x10] */
/* @0xc85d0 ldr r1, [r4, #0x14] */
/* @0xc85d4 add r3, r3, #1 */
/* @0xc85d8 ldr r2, [r4, #0xc] */
/* @0xc85dc cmp r3, r1 */
/* @0xc85e0 str r3, [r4, #0x10] */
/* @0xc85e4 add r3, r2, #4 */
/* @0xc85e8 str r3, [r4, #0xc] */
/* @0xc85ec ldrhs r3, [r4, #0x1c] */
/* @0xc85f0 movhs r2, #0 */
/* @0xc85f4 strhs r2, [r4, #0x10] */
/* @0xc85f8 addhs r3, r3, #1 */
/* @0xc85fc strhs r3, [r4, #0x1c] */
/* @0xc8600 add sp, sp, #8 */
/* @0xc8604 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc8608 add r2, r2, r3 */
/* @0xc860c ldr r0, [r4] */
/* @0xc8610 add r1, r2, r3, lsr #1 */
/* @0xc8614 mov r2, #0 */
/* @0xc8618 str r1, [r4, #0x4] */
/* @0xc861c mov r3, #74 */
/* @0xc8620 str r2, [sp] */
/* @0xc8624 ldr r2, [pc, #0x18] */
/* @0xc8628 add r2, pc, r2 */
/* @0xc862c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc8630 ldr r6, [r4, #0xc] */
/* @0xc8634 mov r8, r0 */
/* @0xc8638 str r0, [r4] */
/* @0xc863c b 0xc8588 <_Z23F_Vertex_ubyte4_releaseR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0xc8640 eorseq r1, r11, r0, ror #23 */
/* @0xc8644 eoreq r8, r6, r8, lsl #20 */

/* ── FUNC 0xc8648 · Buffer_Vertex::FindNextUsage(yyVertexUsage, yyVertexType) · size=276 · insn=69 */
/* @0xc8648 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xc864c mov r7, r0 */
/* @0xc8650 ldr r0, [r0, #0x24] */
/* @0xc8654 mov r5, r1 */
/* @0xc8658 mov r6, r2 */
/* @0xc865c bl 0x1e2cd0 <_Z15GetVertexFormati> */
/* @0xc8660 subs r9, r0, #0 */
/* @0xc8664 beq 0xc8738 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType+0xf0> */
/* @0xc8668 ldr r4, [r9, #0x4] */
/* @0xc866c ldr r3, [r9, #0x8] */
/* @0xc8670 cmp r4, #0 */
/* @0xc8674 ble 0xc8720 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType+0xd8> */
/* @0xc8678 mov r8, #0 */
/* @0xc867c b 0xc868c <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType+0x44> */
/* @0xc8680 subs r4, r4, #1 */
/* @0xc8684 add r3, r3, #16 */
/* @0xc8688 beq 0xc8700 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType+0xb8> */
/* @0xc868c ldr r12, [r3, #0x8] */
/* @0xc8690 cmp r12, r5 */
/* @0xc8694 bne 0xc8680 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType+0x38> */
/* @0xc8698 ldr r1, [r3, #0x4] */
/* @0xc869c cmp r1, r6 */
/* @0xc86a0 bne 0xc8680 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType+0x38> */
/* @0xc86a4 ldr r1, [r3, #0xc] */
/* @0xc86a8 mov r8, #1 */
/* @0xc86ac ldr r2, [r7, #0x18] */
/* @0xc86b0 ands r12, r1, r2 */
/* @0xc86b4 bne 0xc8680 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType+0x38> */
/* @0xc86b8 ldr r0, [r9, #0x10] */
/* @0xc86bc orr r2, r1, r2 */
/* @0xc86c0 ldr r1, [r3] */
/* @0xc86c4 ldr r3, [r7, #0xc] */
/* @0xc86c8 cmp r2, r0 */
/* @0xc86cc ldr r0, [r7] */
/* @0xc86d0 add r1, r3, r1 */
/* @0xc86d4 str r2, [r7, #0x18] */
/* @0xc86d8 add r0, r0, r1 */
/* @0xc86dc popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xc86e0 ldr r1, [r9, #0x14] */
/* @0xc86e4 ldr r2, [r7, #0x1c] */
/* @0xc86e8 add r3, r1, r3 */
/* @0xc86ec str r12, [r7, #0x18] */
/* @0xc86f0 str r3, [r7, #0xc] */
/* @0xc86f4 add r3, r2, r8 */
/* @0xc86f8 str r3, [r7, #0x1c] */
/* @0xc86fc pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xc8700 cmp r8, #0 */
/* @0xc8704 beq 0xc8720 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType+0xd8> */
/* @0xc8708 ldr r0, [pc, #0x40] */
/* @0xc870c mov r1, #1 */
/* @0xc8710 add r0, pc, r0 */
/* @0xc8714 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc8718 mov r0, r4 */
/* @0xc871c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xc8720 ldr r0, [pc, #0x2c] */
/* @0xc8724 mov r1, #1 */
/* @0xc8728 add r0, pc, r0 */
/* @0xc872c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc8730 mov r0, #0 */
/* @0xc8734 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xc8738 ldr r0, [pc, #0x18] */
/* @0xc873c mov r1, #1 */
/* @0xc8740 add r0, pc, r0 */
/* @0xc8744 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc8748 mov r0, r9 */
/* @0xc874c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xc8750 .word 0x002691b0 */
/* @0xc8754 eoreq r9, r6, r8, ror #3 */
/* @0xc8758 eoreq r9, r6, r8, asr r1 */

/* ── FUNC 0xc875c · Buffer_Vertex::FindNextType(yyVertexType) · size=260 · insn=65 */
/* @0xc875c push {r4, r5, r6, r7, r8, lr} */
/* @0xc8760 mov r6, r0 */
/* @0xc8764 ldr r0, [r0, #0x24] */
/* @0xc8768 mov r5, r1 */
/* @0xc876c bl 0x1e2cd0 <_Z15GetVertexFormati> */
/* @0xc8770 subs r8, r0, #0 */
/* @0xc8774 beq 0xc883c <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType+0xe0> */
/* @0xc8778 ldr r4, [r8, #0x4] */
/* @0xc877c ldr r3, [r8, #0x8] */
/* @0xc8780 cmp r4, #0 */
/* @0xc8784 ble 0xc8824 <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType+0xc8> */
/* @0xc8788 mov r12, #0 */
/* @0xc878c b 0xc879c <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType+0x40> */
/* @0xc8790 subs r4, r4, #1 */
/* @0xc8794 add r3, r3, #16 */
/* @0xc8798 beq 0xc8804 <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType+0xa8> */
/* @0xc879c ldr r2, [r3, #0x4] */
/* @0xc87a0 cmp r2, r5 */
/* @0xc87a4 bne 0xc8790 <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType+0x34> */
/* @0xc87a8 ldr r1, [r3, #0xc] */
/* @0xc87ac mov r12, #1 */
/* @0xc87b0 ldr r2, [r6, #0x18] */
/* @0xc87b4 ands r7, r1, r2 */
/* @0xc87b8 bne 0xc8790 <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType+0x34> */
/* @0xc87bc ldr r0, [r8, #0x10] */
/* @0xc87c0 orr r2, r1, r2 */
/* @0xc87c4 ldr r1, [r3] */
/* @0xc87c8 ldr r3, [r6, #0xc] */
/* @0xc87cc cmp r2, r0 */
/* @0xc87d0 ldr r0, [r6] */
/* @0xc87d4 add r1, r3, r1 */
/* @0xc87d8 str r2, [r6, #0x18] */
/* @0xc87dc add r0, r0, r1 */
/* @0xc87e0 popne {r4, r5, r6, r7, r8, pc} */
/* @0xc87e4 ldr r1, [r8, #0x14] */
/* @0xc87e8 ldr r2, [r6, #0x1c] */
/* @0xc87ec add r3, r1, r3 */
/* @0xc87f0 str r7, [r6, #0x18] */
/* @0xc87f4 str r3, [r6, #0xc] */
/* @0xc87f8 add r3, r2, r12 */
/* @0xc87fc str r3, [r6, #0x1c] */
/* @0xc8800 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc8804 cmp r12, #0 */
/* @0xc8808 beq 0xc8824 <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType+0xc8> */
/* @0xc880c ldr r0, [pc, #0x40] */
/* @0xc8810 mov r1, #1 */
/* @0xc8814 add r0, pc, r0 */
/* @0xc8818 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc881c mov r0, r4 */
/* @0xc8820 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc8824 ldr r0, [pc, #0x2c] */
/* @0xc8828 mov r1, #1 */
/* @0xc882c add r0, pc, r0 */
/* @0xc8830 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc8834 mov r0, #0 */
/* @0xc8838 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc883c ldr r0, [pc, #0x18] */
/* @0xc8840 mov r1, #1 */
/* @0xc8844 add r0, pc, r0 */
/* @0xc8848 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc884c mov r0, r8 */
/* @0xc8850 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc8854 eoreq r9, r6, r12, lsr #1 */
/* @0xc8858 eoreq r9, r6, r4, ror #1 */
/* @0xc885c eoreq r9, r6, r4, asr r0 */

/* ── FUNC 0xc8860 · GetBufferVertex(int) · size=52 · insn=13 */
/* @0xc8860 cmp r0, #0 */
/* @0xc8864 blt 0xc8888 <_Z15GetBufferVertexi+0x28> */
/* @0xc8868 ldr r3, [pc, #0x20] */
/* @0xc886c add r3, pc, r3 */
/* @0xc8870 ldr r2, [r3, #0x4] */
/* @0xc8874 cmp r0, r2 */
/* @0xc8878 bge 0xc8888 <_Z15GetBufferVertexi+0x28> */
/* @0xc887c ldr r3, [r3] */
/* @0xc8880 ldr r0, [r3, r0, lsl #2] */
/* @0xc8884 bx lr */
/* @0xc8888 mov r0, #0 */
/* @0xc888c bx lr */
/* @0xc8890 eorseq r1, r11, r8, asr #17 */

/* ── FUNC 0xc8894 · F_Vertex_Get_Number_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0xc8894 cmp r3, #1 */
/* @0xc8898 mov r1, #0 */
/* @0xc889c push {r3, r4, r5, lr} */
/* @0xc88a0 mov r4, r0 */
/* @0xc88a4 mov r5, r3 */
/* @0xc88a8 ldr r0, [sp, #0x10] */
/* @0xc88ac str r1, [r4, #0xc] */
/* @0xc88b0 str r1, [r4] */
/* @0xc88b4 str r1, [r4, #0x4] */
/* @0xc88b8 beq 0xc88d0 <_Z25F_Vertex_Get_Number_debugR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0xc88bc ldr r0, [pc, #0x48] */
/* @0xc88c0 mov r1, #1 */
/* @0xc88c4 pop {r3, r4, r5, lr} */
/* @0xc88c8 add r0, pc, r0 */
/* @0xc88cc b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc88d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc88d4 bl 0xc8860 <_Z15GetBufferVertexi> */
/* @0xc88d8 cmp r0, #0 */
/* @0xc88dc beq 0xc88f8 <_Z25F_Vertex_Get_Number_debugR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0xc88e0 ldr r2, [r0, #0x1c] */
/* @0xc88e4 vmov s15, r2 */
/* @0xc88e8 vcvt.f64.s32 d7, s15 */
/* @0xc88ec vmov r2, r3, d7 */
/* @0xc88f0 stm r4, {r2, r3} */
/* @0xc88f4 pop {r3, r4, r5, pc} */
/* @0xc88f8 ldr r0, [pc, #0x10] */
/* @0xc88fc mov r1, r5 */
/* @0xc8900 pop {r3, r4, r5, lr} */
/* @0xc8904 add r0, pc, r0 */
/* @0xc8908 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc890c eoreq r9, r6, r8, lsl #1 */
/* @0xc8910 eoreq r9, r6, r8, ror r0 */

/* ── FUNC 0xc8914 · F_Vertex_Get_Buffer_Size(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0xc8914 push {r4, lr} */
/* @0xc8918 mov r1, #0 */
/* @0xc891c ldr r3, [sp, #0x8] */
/* @0xc8920 mov r4, r0 */
/* @0xc8924 str r1, [r0, #0xc] */
/* @0xc8928 mov r0, r3 */
/* @0xc892c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc8930 bl 0xc8860 <_Z15GetBufferVertexi> */
/* @0xc8934 cmp r0, #0 */
/* @0xc8938 beq 0xc8954 <_Z24F_Vertex_Get_Buffer_SizeR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0xc893c ldr r2, [r0, #0x4] */
/* @0xc8940 vmov s15, r2 */
/* @0xc8944 vcvt.f64.u32 d7, s15 */
/* @0xc8948 vmov r2, r3, d7 */
/* @0xc894c stm r4, {r2, r3} */
/* @0xc8950 pop {r4, pc} */
/* @0xc8954 str r0, [r4] */
/* @0xc8958 mov r3, #0 */
/* @0xc895c ldr r0, [pc, #0x10] */
/* @0xc8960 movt r3, #0xbff0 */
/* @0xc8964 str r3, [r4, #0x4] */
/* @0xc8968 add r0, pc, r0 */
/* @0xc896c pop {r4, lr} */
/* @0xc8970 b 0xd547c <_Z7YYErrorPKcz> */
/* @0xc8974 eoreq r9, r6, r0, asr r0 */

/* ── FUNC 0xc8978 · AllocBufferVertex(int) · size=420 · insn=105 */
/* @0xc8978 ldr r3, [pc, #0x180] */
/* @0xc897c push {r4, r5, r6, r7, r8, lr} */
/* @0xc8980 add r3, pc, r3 */
/* @0xc8984 mov r7, r0 */
/* @0xc8988 sub sp, sp, #8 */
/* @0xc898c ldm r3, {r0, r5} */
/* @0xc8990 cmp r5, #0 */
/* @0xc8994 ble 0xc8aec <_Z17AllocBufferVertexi+0x174> */
/* @0xc8998 ldr r6, [r0] */
/* @0xc899c cmp r6, #0 */
/* @0xc89a0 movne r3, r0 */
/* @0xc89a4 movne r4, #0 */
/* @0xc89a8 bne 0xc89bc <_Z17AllocBufferVertexi+0x44> */
/* @0xc89ac b 0xc8a70 <_Z17AllocBufferVertexi+0xf8> */
/* @0xc89b0 ldr r2, [r3, #0x4]! */
/* @0xc89b4 cmp r2, #0 */
/* @0xc89b8 beq 0xc8a74 <_Z17AllocBufferVertexi+0xfc> */
/* @0xc89bc add r4, r4, #1 */
/* @0xc89c0 cmp r4, r5 */
/* @0xc89c4 lsl r6, r4, #2 */
/* @0xc89c8 bne 0xc89b0 <_Z17AllocBufferVertexi+0x38> */
/* @0xc89cc ldr r3, [pc, #0x130] */
/* @0xc89d0 lsl r1, r5, #3 */
/* @0xc89d4 lsl r2, r5, #1 */
/* @0xc89d8 add r3, pc, r3 */
/* @0xc89dc str r2, [r3, #0x4] */
/* @0xc89e0 ldr r2, [pc, #0x120] */
/* @0xc89e4 mov r8, #0 */
/* @0xc89e8 mov r3, #74 */
/* @0xc89ec str r8, [sp] */
/* @0xc89f0 add r2, pc, r2 */
/* @0xc89f4 ldr r4, [pc, #0x110] */
/* @0xc89f8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc89fc add r4, pc, r4 */
/* @0xc8a00 str r0, [r4] */
/* @0xc8a04 mov r0, #52 */
/* @0xc8a08 bl 0x27c524 <_Znwj> */
/* @0xc8a0c ldr r1, [pc, #0xfc] */
/* @0xc8a10 mov r2, #66 */
/* @0xc8a14 mov r3, #1 */
/* @0xc8a18 add r1, pc, r1 */
/* @0xc8a1c mov r6, r0 */
/* @0xc8a20 mov r0, r7 */
/* @0xc8a24 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xc8a28 ldr r2, [r4] */
/* @0xc8a2c mov r4, r5 */
/* @0xc8a30 mvn r3, #0 */
/* @0xc8a34 stmib r6, {r7, r8} */
/* @0xc8a38 str r8, [r6, #0xc] */
/* @0xc8a3c str r8, [r6, #0x18] */
/* @0xc8a40 str r8, [r6, #0x10] */
/* @0xc8a44 str r8, [r6, #0x14] */
/* @0xc8a48 strb r8, [r6, #0x20] */
/* @0xc8a4c str r8, [r6, #0x30] */
/* @0xc8a50 str r8, [r6, #0x2c] */
/* @0xc8a54 str r3, [r6, #0x24] */
/* @0xc8a58 str r3, [r6, #0x28] */
/* @0xc8a5c str r0, [r6] */
/* @0xc8a60 mov r0, r4 */
/* @0xc8a64 str r6, [r2, r5, lsl #2] */
/* @0xc8a68 add sp, sp, #8 */
/* @0xc8a6c pop {r4, r5, r6, r7, r8, pc} */
/* @0xc8a70 mov r4, r6 */
/* @0xc8a74 mov r0, #52 */
/* @0xc8a78 bl 0x27c524 <_Znwj> */
/* @0xc8a7c ldr r1, [pc, #0x90] */
/* @0xc8a80 mov r2, #66 */
/* @0xc8a84 mov r3, #1 */
/* @0xc8a88 add r1, pc, r1 */
/* @0xc8a8c mov r5, r0 */
/* @0xc8a90 mov r0, r7 */
/* @0xc8a94 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xc8a98 ldr r1, [pc, #0x78] */
/* @0xc8a9c mov r3, #0 */
/* @0xc8aa0 mvn r2, #0 */
/* @0xc8aa4 add r1, pc, r1 */
/* @0xc8aa8 str r7, [r5, #0x4] */
/* @0xc8aac str r3, [r5, #0x8] */
/* @0xc8ab0 ldr r1, [r1] */
/* @0xc8ab4 str r3, [r5, #0xc] */
/* @0xc8ab8 str r3, [r5, #0x18] */
/* @0xc8abc str r3, [r5, #0x10] */
/* @0xc8ac0 str r3, [r5, #0x14] */
/* @0xc8ac4 strb r3, [r5, #0x20] */
/* @0xc8ac8 str r3, [r5, #0x30] */
/* @0xc8acc str r3, [r5, #0x2c] */
/* @0xc8ad0 str r2, [r5, #0x24] */
/* @0xc8ad4 str r2, [r5, #0x28] */
/* @0xc8ad8 str r0, [r5] */
/* @0xc8adc mov r0, r4 */
/* @0xc8ae0 str r5, [r1, r6] */
/* @0xc8ae4 add sp, sp, #8 */
/* @0xc8ae8 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc8aec moveq r2, #32 */
/* @0xc8af0 moveq r1, #128 */
/* @0xc8af4 streq r2, [r3, #0x4] */
/* @0xc8af8 beq 0xc89e0 <_Z17AllocBufferVertexi+0x68> */
/* @0xc8afc b 0xc89cc <_Z17AllocBufferVertexi+0x54> */
/* @0xc8b00 ldrhteq r1, [r11], -r4 */
/* @0xc8b04 eorseq r1, r11, r12, asr r7 */
/* @0xc8b08 eoreq r8, r6, r0, asr #12 */
/* @0xc8b0c eorseq r1, r11, r8, lsr r7 */
/* @0xc8b10 eoreq r8, r6, r4, asr #31 */
/* @0xc8b14 eoreq r8, r6, r4, asr pc */
/* @0xc8b18 mlaseq r11, r0, r6, r1 */

/* ── FUNC 0xc8b1c · F_Vertex_Create_Buffer_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0xc8b1c cmp r3, #0 */
/* @0xc8b20 mov r2, #0 */
/* @0xc8b24 push {r4, lr} */
/* @0xc8b28 mov r3, r2 */
/* @0xc8b2c mov r4, r0 */
/* @0xc8b30 movt r2, #0xbff0 */
/* @0xc8b34 str r3, [r0, #0xc] */
/* @0xc8b38 str r2, [r0, #0x4] */
/* @0xc8b3c str r3, [r0] */
/* @0xc8b40 bne 0xc8b68 <_Z28F_Vertex_Create_Buffer_debugR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xc8b44 mov r0, #32768 */
/* @0xc8b48 bl 0xc8978 <_Z17AllocBufferVertexi> */
/* @0xc8b4c vmov s15, r0 */
/* @0xc8b50 vcvt.f64.s32 d7, s15 */
/* @0xc8b54 vmov r0, r1, d7 */
/* @0xc8b58 vmov r2, s14 */
/* @0xc8b5c mov r3, r1 */
/* @0xc8b60 stm r4, {r2, r3} */
/* @0xc8b64 pop {r4, pc} */
/* @0xc8b68 ldr r0, [pc, #0xc] */
/* @0xc8b6c mov r1, #1 */
/* @0xc8b70 pop {r4, lr} */
/* @0xc8b74 add r0, pc, r0 */
/* @0xc8b78 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc8b7c eoreq r8, r6, r0, lsr #29 */

/* ── FUNC 0xc8b80 · F_Vertex_Create_Buffer_Ext_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0xc8b80 push {r4, lr} */
/* @0xc8b84 mov r3, #0 */
/* @0xc8b88 mov r1, r3 */
/* @0xc8b8c str r3, [r0, #0xc] */
/* @0xc8b90 mov r4, r0 */
/* @0xc8b94 ldr r0, [sp, #0x8] */
/* @0xc8b98 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0xc8b9c cmp r0, #256 */
/* @0xc8ba0 movlo r0, #256 */
/* @0xc8ba4 bl 0xc8978 <_Z17AllocBufferVertexi> */
/* @0xc8ba8 vmov s15, r0 */
/* @0xc8bac vcvt.f64.s32 d7, s15 */
/* @0xc8bb0 vmov r0, r1, d7 */
/* @0xc8bb4 vmov r2, s14 */
/* @0xc8bb8 mov r3, r1 */
/* @0xc8bbc stm r4, {r2, r3} */
/* @0xc8bc0 pop {r4, pc} */

/* ── FUNC 0xc8bc4 · F_Vertex_Create_Buffer_From_Buffer(RValue&, CInstance*, CInstance*, int, RValue*) · size=376 · insn=94 */
/* @0xc8bc4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc8bc8 cmp r3, #2 */
/* @0xc8bcc sub sp, sp, #12 */
/* @0xc8bd0 mov r3, #0 */
/* @0xc8bd4 mov r1, r3 */
/* @0xc8bd8 mov r6, r0 */
/* @0xc8bdc movt r3, #0xbff0 */
/* @0xc8be0 str r1, [r0, #0xc] */
/* @0xc8be4 stm r0, {r1, r3} */
/* @0xc8be8 ldr r4, [sp, #0x30] */
/* @0xc8bec beq 0xc8c08 <_Z34F_Vertex_Create_Buffer_From_BufferR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0xc8bf0 ldr r0, [pc, #0x134] */
/* @0xc8bf4 add r0, pc, r0 */
/* @0xc8bf8 mov r1, #1 */
/* @0xc8bfc add sp, sp, #12 */
/* @0xc8c00 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc8c04 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc8c08 mov r0, r4 */
/* @0xc8c0c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc8c10 bl 0xc6720 <_Z10GetIBufferi> */
/* @0xc8c14 subs r5, r0, #0 */
/* @0xc8c18 beq 0xc8d20 <_Z34F_Vertex_Create_Buffer_From_BufferR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0xc8c1c mov r0, r4 */
/* @0xc8c20 mov r1, #1 */
/* @0xc8c24 ldr r4, [r5, #0x20] */
/* @0xc8c28 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc8c2c bl 0x1e2cd0 <_Z15GetVertexFormati> */
/* @0xc8c30 cmp r4, #255 */
/* @0xc8c34 movls r4, #256 */
/* @0xc8c38 subs r9, r0, #0 */
/* @0xc8c3c beq 0xc8d14 <_Z34F_Vertex_Create_Buffer_From_BufferR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0xc8c40 mov r0, r4 */
/* @0xc8c44 bl 0xc8978 <_Z17AllocBufferVertexi> */
/* @0xc8c48 mov r4, r0 */
/* @0xc8c4c bl 0xc8860 <_Z15GetBufferVertexi> */
/* @0xc8c50 subs r7, r0, #0 */
/* @0xc8c54 beq 0xc8c64 <_Z34F_Vertex_Create_Buffer_From_BufferR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0xc8c58 ldrb r8, [r7, #0x20] */
/* @0xc8c5c cmp r8, #0 */
/* @0xc8c60 beq 0xc8c7c <_Z34F_Vertex_Create_Buffer_From_BufferR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xc8c64 ldr r0, [pc, #0xc4] */
/* @0xc8c68 mov r1, #1 */
/* @0xc8c6c add r0, pc, r0 */
/* @0xc8c70 add sp, sp, #12 */
/* @0xc8c74 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc8c78 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc8c7c ldr r2, [r5, #0x20] */
/* @0xc8c80 mvn r10, #0 */
/* @0xc8c84 ldr r1, [r5, #0xc] */
/* @0xc8c88 ldr r0, [r7] */
/* @0xc8c8c bl 0xb65bc <memcpy@plt> */
/* @0xc8c90 ldr r11, [r5, #0x20] */
/* @0xc8c94 ldr r1, [r9, #0x14] */
/* @0xc8c98 mov r0, r11 */
/* @0xc8c9c bl 0x318c48 <__udivsi3> */
/* @0xc8ca0 vmov s15, r4 */
/* @0xc8ca4 ldr r1, [r9] */
/* @0xc8ca8 vcvt.f64.s32 d7, s15 */
/* @0xc8cac vmov r2, r3, d7 */
/* @0xc8cb0 mov r5, r0 */
/* @0xc8cb4 ldr r0, [r9, #0x4] */
/* @0xc8cb8 str r1, [r7, #0x28] */
/* @0xc8cbc vmov r1, s14 */
/* @0xc8cc0 str r8, [r7, #0x18] */
/* @0xc8cc4 str r11, [r7, #0xc] */
/* @0xc8cc8 str r5, [r7, #0x1c] */
/* @0xc8ccc str r8, [r7, #0x8] */
/* @0xc8cd0 str r8, [r7, #0x10] */
/* @0xc8cd4 str r0, [r7, #0x14] */
/* @0xc8cd8 str r8, [r7, #0x2c] */
/* @0xc8cdc str r10, [r7, #0x24] */
/* @0xc8ce0 stm r6, {r1, r3} */
/* @0xc8ce4 bl 0x212e98 <_Z11IsBigEndianv> */
/* @0xc8ce8 cmp r0, #0 */
/* @0xc8cec beq 0xc8d0c <_Z34F_Vertex_Create_Buffer_From_BufferR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0xc8cf0 ldr r1, [r7] */
/* @0xc8cf4 mov r0, r9 */
/* @0xc8cf8 str r10, [sp] */
/* @0xc8cfc mov r2, r5 */
/* @0xc8d00 str r8, [sp, #0x4] */
/* @0xc8d04 mov r3, r8 */
/* @0xc8d08 bl 0x1e251c <_ZN12VertexFormat16EndianSwapBufferEPhiiib> */
/* @0xc8d0c add sp, sp, #12 */
/* @0xc8d10 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xc8d14 ldr r0, [pc, #0x18] */
/* @0xc8d18 add r0, pc, r0 */
/* @0xc8d1c b 0xc8bf8 <_Z34F_Vertex_Create_Buffer_From_BufferR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0xc8d20 ldr r0, [pc, #0x10] */
/* @0xc8d24 add r0, pc, r0 */
/* @0xc8d28 b 0xc8bf8 <_Z34F_Vertex_Create_Buffer_From_BufferR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0xc8d2c eoreq r8, r6, r0, asr lr */
/* @0xc8d30 eoreq r8, r6, r0, lsr #29 */
/* @0xc8d34 eoreq r8, r6, r12, lsr #27 */
/* @0xc8d38 eoreq r8, r6, r12, asr sp */

/* ── FUNC 0xc8d3c · F_Vertex_Create_Buffer_From_Buffer_Ext(RValue&, CInstance*, CInstance*, int, RValue*) · size=420 · insn=105 */
/* @0xc8d3c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc8d40 cmp r3, #4 */
/* @0xc8d44 sub sp, sp, #36 */
/* @0xc8d48 mov r3, #0 */
/* @0xc8d4c mov r1, r3 */
/* @0xc8d50 mov r4, r0 */
/* @0xc8d54 movt r3, #0xbff0 */
/* @0xc8d58 str r1, [r0, #0xc] */
/* @0xc8d5c stm r0, {r1, r3} */
/* @0xc8d60 ldr r5, [sp, #0x48] */
/* @0xc8d64 beq 0xc8d80 <_Z38F_Vertex_Create_Buffer_From_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0xc8d68 ldr r0, [pc, #0x160] */
/* @0xc8d6c add r0, pc, r0 */
/* @0xc8d70 mov r1, #1 */
/* @0xc8d74 add sp, sp, #36 */
/* @0xc8d78 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc8d7c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc8d80 mov r0, r5 */
/* @0xc8d84 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc8d88 bl 0xc6720 <_Z10GetIBufferi> */
/* @0xc8d8c subs r9, r0, #0 */
/* @0xc8d90 beq 0xc8eb8 <_Z38F_Vertex_Create_Buffer_From_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0xc8d94 mov r1, #1 */
/* @0xc8d98 mov r0, r5 */
/* @0xc8d9c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc8da0 bl 0x1e2cd0 <_Z15GetVertexFormati> */
/* @0xc8da4 subs r11, r0, #0 */
/* @0xc8da8 beq 0xc8ec4 <_Z38F_Vertex_Create_Buffer_From_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x188> */
/* @0xc8dac mov r0, r5 */
/* @0xc8db0 mov r1, #2 */
/* @0xc8db4 ldr r7, [r11, #0x14] */
/* @0xc8db8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc8dbc mov r1, #3 */
/* @0xc8dc0 mov r10, r0 */
/* @0xc8dc4 mov r0, r5 */
/* @0xc8dc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc8dcc mul r7, r7, r0 */
/* @0xc8dd0 mov r8, r0 */
/* @0xc8dd4 mov r0, r7 */
/* @0xc8dd8 bl 0xc8978 <_Z17AllocBufferVertexi> */
/* @0xc8ddc str r0, [sp, #0x1c] */
/* @0xc8de0 bl 0xc8860 <_Z15GetBufferVertexi> */
/* @0xc8de4 subs r5, r0, #0 */
/* @0xc8de8 beq 0xc8df8 <_Z38F_Vertex_Create_Buffer_From_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0xc8dec ldrb r6, [r5, #0x20] */
/* @0xc8df0 cmp r6, #0 */
/* @0xc8df4 beq 0xc8e10 <_Z38F_Vertex_Create_Buffer_From_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0xc8df8 ldr r0, [pc, #0xd4] */
/* @0xc8dfc mov r1, #1 */
/* @0xc8e00 add r0, pc, r0 */
/* @0xc8e04 add sp, sp, #36 */
/* @0xc8e08 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc8e0c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc8e10 ldr r2, [r9, #0xc] */
/* @0xc8e14 mov r1, r7 */
/* @0xc8e18 ldr r3, [r9, #0x10] */
/* @0xc8e1c ldr r0, [r5] */
/* @0xc8e20 str r10, [sp] */
/* @0xc8e24 str r7, [sp, #0x4] */
/* @0xc8e28 str r6, [sp, #0x8] */
/* @0xc8e2c str r6, [sp, #0xc] */
/* @0xc8e30 ldr lr, [r9, #0x18] */
/* @0xc8e34 subs r12, lr, #2 */
/* @0xc8e38 rsbs lr, r12, #0 */
/* @0xc8e3c adcs lr, lr, r12 */
/* @0xc8e40 str lr, [sp, #0x10] */
/* @0xc8e44 bl 0xccd94 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb> */
/* @0xc8e48 vldr s15, [sp, #28] */
/* @0xc8e4c vcvt.f64.s32 d7, s15 */
/* @0xc8e50 ldm r11, {r0, r1} */
/* @0xc8e54 str r6, [r5, #0x18] */
/* @0xc8e58 str r6, [r5, #0x8] */
/* @0xc8e5c str r1, [r5, #0x14] */
/* @0xc8e60 mvn r1, #0 */
/* @0xc8e64 str r0, [r5, #0x28] */
/* @0xc8e68 str r7, [r5, #0xc] */
/* @0xc8e6c str r8, [r5, #0x1c] */
/* @0xc8e70 vmov r2, r3, d7 */
/* @0xc8e74 str r6, [r5, #0x10] */
/* @0xc8e78 str r6, [r5, #0x2c] */
/* @0xc8e7c str r1, [r5, #0x24] */
/* @0xc8e80 stm r4, {r2, r3} */
/* @0xc8e84 bl 0x212e98 <_Z11IsBigEndianv> */
/* @0xc8e88 cmp r0, #0 */
/* @0xc8e8c beq 0xc8eb0 <_Z38F_Vertex_Create_Buffer_From_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0xc8e90 ldr r1, [r5] */
/* @0xc8e94 mvn r3, #0 */
/* @0xc8e98 mov r0, r11 */
/* @0xc8e9c str r3, [sp] */
/* @0xc8ea0 mov r2, r8 */
/* @0xc8ea4 str r6, [sp, #0x4] */
/* @0xc8ea8 mov r3, r6 */
/* @0xc8eac bl 0x1e251c <_ZN12VertexFormat16EndianSwapBufferEPhiiib> */
/* @0xc8eb0 add sp, sp, #36 */
/* @0xc8eb4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xc8eb8 ldr r0, [pc, #0x18] */
/* @0xc8ebc add r0, pc, r0 */
/* @0xc8ec0 b 0xc8d70 <_Z38F_Vertex_Create_Buffer_From_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0xc8ec4 ldr r0, [pc, #0x10] */
/* @0xc8ec8 add r0, pc, r0 */
/* @0xc8ecc b 0xc8d70 <_Z38F_Vertex_Create_Buffer_From_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0xc8ed0 eoreq r8, r6, r4, ror #27 */
/* @0xc8ed4 eoreq r8, r6, r4, lsr #28 */
/* @0xc8ed8 .word 0x00268cd4 */
/* @0xc8edc eoreq r8, r6, r0, lsl sp */

/* ── FUNC 0xc8ee0 · FreeBufferVertex(int) · size=160 · insn=40 */
/* @0xc8ee0 push {r4, r5, r6, lr} */
/* @0xc8ee4 subs r4, r0, #0 */
/* @0xc8ee8 blt 0xc8f70 <_Z16FreeBufferVertexi+0x90> */
/* @0xc8eec ldr r3, [pc, #0x84] */
/* @0xc8ef0 add r3, pc, r3 */
/* @0xc8ef4 ldr r2, [r3, #0x4] */
/* @0xc8ef8 cmp r4, r2 */
/* @0xc8efc bge 0xc8f70 <_Z16FreeBufferVertexi+0x90> */
/* @0xc8f00 ldr r3, [r3] */
/* @0xc8f04 ldr r5, [r3, r4, lsl #2] */
/* @0xc8f08 cmp r5, #0 */
/* @0xc8f0c beq 0xc8f70 <_Z16FreeBufferVertexi+0x90> */
/* @0xc8f10 ldr r0, [r5] */
/* @0xc8f14 cmp r0, #0 */
/* @0xc8f18 beq 0xc8f28 <_Z16FreeBufferVertexi+0x48> */
/* @0xc8f1c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc8f20 mov r3, #0 */
/* @0xc8f24 str r3, [r5] */
/* @0xc8f28 ldr r6, [r5, #0x30] */
/* @0xc8f2c cmp r6, #0 */
/* @0xc8f30 beq 0xc8f4c <_Z16FreeBufferVertexi+0x6c> */
/* @0xc8f34 mov r0, r6 */
/* @0xc8f38 bl 0x18373c <_ZN12VertexBufferD2Ev> */
/* @0xc8f3c mov r0, r6 */
/* @0xc8f40 bl 0x27d1d0 <_ZdlPv> */
/* @0xc8f44 mov r3, #0 */
/* @0xc8f48 str r3, [r5, #0x30] */
/* @0xc8f4c mov r0, r5 */
/* @0xc8f50 bl 0x27d1d0 <_ZdlPv> */
/* @0xc8f54 ldr r3, [pc, #0x20] */
/* @0xc8f58 mov r2, #0 */
/* @0xc8f5c mov r0, #1 */
/* @0xc8f60 add r3, pc, r3 */
/* @0xc8f64 ldr r3, [r3] */
/* @0xc8f68 str r2, [r3, r4, lsl #2] */
/* @0xc8f6c pop {r4, r5, r6, pc} */
/* @0xc8f70 mov r0, #0 */
/* @0xc8f74 pop {r4, r5, r6, pc} */
/* @0xc8f78 eorseq r1, r11, r4, asr #4 */
/* @0xc8f7c ldrsbteq r1, [r11], -r4 */

/* ── FUNC 0xc8f80 · F_Vertex_Delete_Buffer_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0xc8f80 cmp r3, #1 */
/* @0xc8f84 mov r2, #0 */
/* @0xc8f88 push {r4, lr} */
/* @0xc8f8c mov r1, r2 */
/* @0xc8f90 mov r4, r3 */
/* @0xc8f94 movt r2, #0xbff0 */
/* @0xc8f98 str r1, [r0, #0xc] */
/* @0xc8f9c stm r0, {r1, r2} */
/* @0xc8fa0 ldr r0, [sp, #0x8] */
/* @0xc8fa4 beq 0xc8fbc <_Z28F_Vertex_Delete_Buffer_debugR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0xc8fa8 ldr r0, [pc, #0x30] */
/* @0xc8fac mov r1, #1 */
/* @0xc8fb0 pop {r4, lr} */
/* @0xc8fb4 add r0, pc, r0 */
/* @0xc8fb8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc8fbc bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0xc8fc0 bl 0xc8ee0 <_Z16FreeBufferVertexi> */
/* @0xc8fc4 cmp r0, #0 */
/* @0xc8fc8 popne {r4, pc} */
/* @0xc8fcc ldr r0, [pc, #0x10] */
/* @0xc8fd0 mov r1, r4 */
/* @0xc8fd4 pop {r4, lr} */
/* @0xc8fd8 add r0, pc, r0 */
/* @0xc8fdc b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc8fe0 .word 0x00268cb8 */
/* @0xc8fe4 eoreq r8, r6, r4, asr #25 */

/* ── FUNC 0xc8fe8 · InvalidateFrozenVBs() · size=108 · insn=27 */
/* @0xc8fe8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xc8fec ldr r7, [pc, #0x5c] */
/* @0xc8ff0 add r7, pc, r7 */
/* @0xc8ff4 ldr r3, [r7, #0x4] */
/* @0xc8ff8 cmp r3, #0 */
/* @0xc8ffc pople {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xc9000 mov r4, #0 */
/* @0xc9004 mov r8, r7 */
/* @0xc9008 mov r9, r4 */
/* @0xc900c ldr r3, [r7] */
/* @0xc9010 ldr r5, [r3, r4, lsl #2] */
/* @0xc9014 add r4, r4, #1 */
/* @0xc9018 cmp r5, #0 */
/* @0xc901c beq 0xc9040 <_Z19InvalidateFrozenVBsv+0x58> */
/* @0xc9020 ldr r6, [r5, #0x30] */
/* @0xc9024 cmp r6, #0 */
/* @0xc9028 mov r0, r6 */
/* @0xc902c beq 0xc9040 <_Z19InvalidateFrozenVBsv+0x58> */
/* @0xc9030 bl 0x18373c <_ZN12VertexBufferD2Ev> */
/* @0xc9034 mov r0, r6 */
/* @0xc9038 bl 0x27d1d0 <_ZdlPv> */
/* @0xc903c str r9, [r5, #0x30] */
/* @0xc9040 ldr r3, [r8, #0x4] */
/* @0xc9044 cmp r3, r4 */
/* @0xc9048 bgt 0xc900c <_Z19InvalidateFrozenVBsv+0x24> */
/* @0xc904c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xc9050 eorseq r1, r11, r4, asr #2 */

/* ── FUNC 0xc9054 · YYGML_vertex_begin(int, int) · size=128 · insn=32 */
/* @0xc9054 push {r4, r5, r6, lr} */
/* @0xc9058 mov r6, r1 */
/* @0xc905c bl 0xc8860 <_Z15GetBufferVertexi> */
/* @0xc9060 subs r4, r0, #0 */
/* @0xc9064 beq 0xc9074 <_Z18YYGML_vertex_beginii+0x20> */
/* @0xc9068 ldrb r5, [r4, #0x20] */
/* @0xc906c cmp r5, #0 */
/* @0xc9070 beq 0xc9084 <_Z18YYGML_vertex_beginii+0x30> */
/* @0xc9074 ldr r0, [pc, #0x50] */
/* @0xc9078 pop {r4, r5, r6, lr} */
/* @0xc907c add r0, pc, r0 */
/* @0xc9080 b 0xd547c <_Z7YYErrorPKcz> */
/* @0xc9084 mov r0, r6 */
/* @0xc9088 bl 0x1e2cd0 <_Z15GetVertexFormati> */
/* @0xc908c cmp r0, #0 */
/* @0xc9090 beq 0xc90bc <_Z18YYGML_vertex_beginii+0x68> */
/* @0xc9094 ldm r0, {r2, r3} */
/* @0xc9098 str r5, [r4, #0x18] */
/* @0xc909c str r5, [r4, #0x8] */
/* @0xc90a0 str r2, [r4, #0x24] */
/* @0xc90a4 str r5, [r4, #0xc] */
/* @0xc90a8 str r5, [r4, #0x1c] */
/* @0xc90ac str r5, [r4, #0x10] */
/* @0xc90b0 str r3, [r4, #0x14] */
/* @0xc90b4 str r0, [r4, #0x2c] */
/* @0xc90b8 pop {r4, r5, r6, pc} */
/* @0xc90bc ldr r0, [pc, #0xc] */
/* @0xc90c0 pop {r4, r5, r6, lr} */
/* @0xc90c4 add r0, pc, r0 */
/* @0xc90c8 b 0xd547c <_Z7YYErrorPKcz> */
/* @0xc90cc eoreq r8, r6, r8, asr r12 */
/* @0xc90d0 eoreq r8, r6, r0, lsr r12 */

/* ── FUNC 0xc90d4 · F_Vertex_Begin_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0xc90d4 push {r3, r4, r5, lr} */
/* @0xc90d8 mov r1, #0 */
/* @0xc90dc ldr r4, [sp, #0x10] */
/* @0xc90e0 mov r0, r4 */
/* @0xc90e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc90e8 mov r1, #1 */
/* @0xc90ec mov r5, r0 */
/* @0xc90f0 mov r0, r4 */
/* @0xc90f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc90f8 mov r1, r0 */
/* @0xc90fc mov r0, r5 */
/* @0xc9100 pop {r3, r4, r5, lr} */
/* @0xc9104 b 0xc9054 <_Z18YYGML_vertex_beginii> */

/* ── FUNC 0xc9108 · YYGML_vertex_end(int) · size=104 · insn=26 */
/* @0xc9108 push {r3, lr} */
/* @0xc910c bl 0xc8860 <_Z15GetBufferVertexi> */
/* @0xc9110 cmp r0, #0 */
/* @0xc9114 beq 0xc9148 <_Z16YYGML_vertex_endi+0x40> */
/* @0xc9118 ldrb r3, [r0, #0x20] */
/* @0xc911c cmp r3, #0 */
/* @0xc9120 bne 0xc9148 <_Z16YYGML_vertex_endi+0x40> */
/* @0xc9124 ldr r3, [r0, #0x18] */
/* @0xc9128 cmp r3, #0 */
/* @0xc912c bne 0xc9158 <_Z16YYGML_vertex_endi+0x50> */
/* @0xc9130 ldr r2, [r0, #0x24] */
/* @0xc9134 mvn r1, #0 */
/* @0xc9138 str r3, [r0, #0x2c] */
/* @0xc913c str r1, [r0, #0x24] */
/* @0xc9140 str r2, [r0, #0x28] */
/* @0xc9144 pop {r3, pc} */
/* @0xc9148 ldr r0, [pc, #0x18] */
/* @0xc914c pop {r3, lr} */
/* @0xc9150 add r0, pc, r0 */
/* @0xc9154 b 0xd547c <_Z7YYErrorPKcz> */
/* @0xc9158 ldr r0, [pc, #0xc] */
/* @0xc915c pop {r3, lr} */
/* @0xc9160 add r0, pc, r0 */
/* @0xc9164 b 0xd547c <_Z7YYErrorPKcz> */
/* @0xc9168 eoreq r8, r6, r4, asr #23 */
/* @0xc916c .word 0x00268bd8 */
