/* libyoyo.so 覆盖卡组 0114
 * 函数 0x17738c..0x17ac80，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x17738c · GR_3D_Vertex_N_Texture(float, float, float, float, float, float, float, float) · size=344 · insn=86 */
/* @0x17738c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x177390 vpush {d8} */
/* @0x177394 mov r7, r0 */
/* @0x177398 vldr s16, [sp, #48] */
/* @0x17739c ldr r4, [pc, #0x120] */
/* @0x1773a0 mov r8, r1 */
/* @0x1773a4 ldr r0, [pc, #0x11c] */
/* @0x1773a8 mov r10, r3 */
/* @0x1773ac ldr r1, [pc, #0x118] */
/* @0x1773b0 add r4, pc, r4 */
/* @0x1773b4 mov r9, r2 */
/* @0x1773b8 ldr r11, [sp, #0x34] */
/* @0x1773bc ldr r6, [r4, r0] */
/* @0x1773c0 ldr r3, [r4, r1] */
/* @0x1773c4 ldr r5, [r6] */
/* @0x1773c8 ldr r3, [r3] */
/* @0x1773cc cmp r5, r3 */
/* @0x1773d0 blt 0x1773dc <_Z22GR_3D_Vertex_N_Textureffffffff+0x50> */
/* @0x1773d4 bl 0x176bb0 <_Z14HandleOverflowv> */
/* @0x1773d8 ldr r5, [r6] */
/* @0x1773dc ldr r1, [pc, #0xec] */
/* @0x1773e0 add r12, r5, r5, lsl #3 */
/* @0x1773e4 ldr r2, [pc, #0xe8] */
/* @0x1773e8 ldr r3, [pc, #0xe8] */
/* @0x1773ec ldr r1, [r4, r1] */
/* @0x1773f0 add r12, r1, r12, lsl #2 */
/* @0x1773f4 vstr s16, [r12, #16] */
/* @0x1773f8 str r7, [r12] */
/* @0x1773fc str r8, [r12, #0x4] */
/* @0x177400 str r9, [r12, #0x8] */
/* @0x177404 str r10, [r12, #0xc] */
/* @0x177408 str r11, [r12, #0x14] */
/* @0x17740c ldr r2, [r4, r2] */
/* @0x177410 ldr r2, [r2] */
/* @0x177414 bic r2, r2, #1 */
/* @0x177418 str r2, [r12, #0x18] */
/* @0x17741c ldr r3, [r4, r3] */
/* @0x177420 ldr r3, [r3] */
/* @0x177424 cmp r3, #0 */
/* @0x177428 beq 0x1774a4 <_Z22GR_3D_Vertex_N_Textureffffffff+0x118> */
/* @0x17742c ldrsh r1, [r3] */
/* @0x177430 vldr s10, [sp, #56] */
/* @0x177434 ldrsh r2, [r3, #12] */
/* @0x177438 add r5, r5, #1 */
/* @0x17743c vmov s14, r1 */
/* @0x177440 ldrsh r1, [r3, #2] */
/* @0x177444 vmov s11, r2 */
/* @0x177448 ldrsh r3, [r3, #14] */
/* @0x17744c vcvt.f32.s32 s14, s14 */
/* @0x177450 ldr r2, [pc, #0x84] */
/* @0x177454 vmov s15, r1 */
/* @0x177458 vmov s13, r3 */
/* @0x17745c ldr r3, [r4, r2] */
/* @0x177460 vldr s12, [r3] */
/* @0x177464 ldr r3, [pc, #0x74] */
/* @0x177468 vcvt.f32.s32 s11, s11 */
/* @0x17746c vmla.f32 s14, s10, s11 */
/* @0x177470 vdiv.f32 s14, s14, s12 */
/* @0x177474 vldr s12, [sp, #60] */
/* @0x177478 vpop {d8} */
/* @0x17747c vcvt.f32.s32 s15, s15 */
/* @0x177480 vstr s14, [r12, #28] */
/* @0x177484 ldr r3, [r4, r3] */
/* @0x177488 vldr s14, [r3] */
/* @0x17748c str r5, [r6] */
/* @0x177490 vcvt.f32.s32 s13, s13 */
/* @0x177494 vmla.f32 s15, s12, s13 */
/* @0x177498 vdiv.f32 s15, s15, s14 */
/* @0x17749c vstr s15, [r12, #32] */
/* @0x1774a0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1774a4 vldr s10, [sp, #56] */
/* @0x1774a8 vldr s12, [sp, #60] */
/* @0x1774ac vpop {d8} */
/* @0x1774b0 vstr s10, [r12, #28] */
/* @0x1774b4 add r5, r5, #1 */
/* @0x1774b8 vstr s12, [r12, #32] */
/* @0x1774bc str r5, [r6] */
/* @0x1774c0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1774c4 eoreq r10, r7, r0, lsr #17 */
/* @0x1774c8 .word 0xffffe670 */
/* @0x1774cc .word 0xffffe67c */
/* @0x1774d0 .word 0xffffe680 */
/* @0x1774d4 .word 0xffffc0ac */
/* @0x1774d8 .word 0xffffe540 */
/* @0x1774dc .word 0xffffe544 */
/* @0x1774e0 .word 0xffffe548 */

/* ── FUNC 0x1774e4 · GR_3D_Vertex_N_Texture_Color(float, float, float, float, float, float, float, float, unsigned int, float) · size=344 · insn=86 */
/* @0x1774e4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1774e8 vpush {d8} */
/* @0x1774ec mov r10, r0 */
/* @0x1774f0 vldr s17, [sp, #48] */
/* @0x1774f4 ldr r5, [pc, #0x124] */
/* @0x1774f8 mov r9, r1 */
/* @0x1774fc ldr r0, [pc, #0x120] */
/* @0x177500 mov r7, r3 */
/* @0x177504 ldr r1, [pc, #0x11c] */
/* @0x177508 add r5, pc, r5 */
/* @0x17750c mov r8, r2 */
/* @0x177510 vldr s16, [sp, #52] */
/* @0x177514 ldr r6, [r5, r0] */
/* @0x177518 ldr r3, [r5, r1] */
/* @0x17751c ldr r11, [sp, #0x40] */
/* @0x177520 ldr r2, [r6] */
/* @0x177524 ldr r3, [r3] */
/* @0x177528 ldr r4, [sp, #0x44] */
/* @0x17752c cmp r2, r3 */
/* @0x177530 blt 0x177538 <_Z28GR_3D_Vertex_N_Texture_Colorffffffffjf+0x54> */
/* @0x177534 bl 0x176bb0 <_Z14HandleOverflowv> */
/* @0x177538 mov r0, r4 */
/* @0x17753c bl 0x16ca2c <_Z12ConvertAlphaf> */
/* @0x177540 ldr r4, [r6] */
/* @0x177544 ldr r3, [pc, #0xe0] */
/* @0x177548 add r4, r4, r4, lsl #3 */
/* @0x17754c ldr r3, [r5, r3] */
/* @0x177550 add r4, r3, r4, lsl #2 */
/* @0x177554 vstr s17, [r4, #16] */
/* @0x177558 vstr s16, [r4, #20] */
/* @0x17755c str r10, [r4] */
/* @0x177560 str r9, [r4, #0x4] */
/* @0x177564 str r8, [r4, #0x8] */
/* @0x177568 str r7, [r4, #0xc] */
/* @0x17756c mov r1, r0 */
/* @0x177570 orr r0, r11, #1 */
/* @0x177574 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x177578 ldr r3, [pc, #0xb0] */
/* @0x17757c str r0, [r4, #0x18] */
/* @0x177580 ldr r3, [r5, r3] */
/* @0x177584 ldr r3, [r3] */
/* @0x177588 cmp r3, #0 */
/* @0x17758c beq 0x17760c <_Z28GR_3D_Vertex_N_Texture_Colorffffffffjf+0x128> */
/* @0x177590 ldrsh r1, [r3] */
/* @0x177594 vldr s10, [sp, #56] */
/* @0x177598 ldrsh r2, [r3, #12] */
/* @0x17759c vmov s14, r1 */
/* @0x1775a0 ldrsh r1, [r3, #2] */
/* @0x1775a4 vmov s11, r2 */
/* @0x1775a8 ldrsh r3, [r3, #14] */
/* @0x1775ac vcvt.f32.s32 s14, s14 */
/* @0x1775b0 ldr r2, [pc, #0x7c] */
/* @0x1775b4 vmov s15, r1 */
/* @0x1775b8 vmov s13, r3 */
/* @0x1775bc ldr r3, [r5, r2] */
/* @0x1775c0 vldr s12, [r3] */
/* @0x1775c4 ldr r3, [pc, #0x6c] */
/* @0x1775c8 vcvt.f32.s32 s11, s11 */
/* @0x1775cc vmla.f32 s14, s10, s11 */
/* @0x1775d0 vdiv.f32 s14, s14, s12 */
/* @0x1775d4 vldr s12, [sp, #60] */
/* @0x1775d8 vcvt.f32.s32 s15, s15 */
/* @0x1775dc vstr s14, [r4, #28] */
/* @0x1775e0 ldr r3, [r5, r3] */
/* @0x1775e4 vldr s14, [r3] */
/* @0x1775e8 vcvt.f32.s32 s13, s13 */
/* @0x1775ec vmla.f32 s15, s12, s13 */
/* @0x1775f0 vdiv.f32 s15, s15, s14 */
/* @0x1775f4 vstr s15, [r4, #32] */
/* @0x1775f8 vpop {d8} */
/* @0x1775fc ldr r3, [r6] */
/* @0x177600 add r3, r3, #1 */
/* @0x177604 str r3, [r6] */
/* @0x177608 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17760c vldr s10, [sp, #56] */
/* @0x177610 vldr s12, [sp, #60] */
/* @0x177614 vstr s10, [r4, #28] */
/* @0x177618 vstr s12, [r4, #32] */
/* @0x17761c b 0x1775f8 <_Z28GR_3D_Vertex_N_Texture_Colorffffffffjf+0x114> */
/* @0x177620 eoreq r10, r7, r8, asr #14 */
/* @0x177624 .word 0xffffe670 */
/* @0x177628 .word 0xffffe67c */
/* @0x17762c .word 0xffffe680 */
/* @0x177630 .word 0xffffe540 */
/* @0x177634 .word 0xffffe544 */
/* @0x177638 .word 0xffffe548 */

/* ── FUNC 0x17763c · GR_3D_Draw_Block(float, float, float, float, float, float, int, float, float) · size=5896 · insn=1474 */
/* @0x17763c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x177640 vpush {d8, d9, d10} */
/* @0x177644 sub sp, sp, #148 */
/* @0x177648 vldr s18, [sp, #208] */
/* @0x17764c mov r9, r2 */
/* @0x177650 mov r11, r1 */
/* @0x177654 mov r4, r3 */
/* @0x177658 mov r10, r0 */
/* @0x17765c ldr r6, [sp, #0xd8] */
/* @0x177660 vldr s19, [sp, #212] */
/* @0x177664 vldr s16, [sp, #220] */
/* @0x177668 vldr s17, [sp, #224] */
/* @0x17766c bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x177670 ldr r5, [pc, #0x42c] */
/* @0x177674 bl 0x1689e0 <_Z25GR_D3D_Get_Texture_Repeatv> */
/* @0x177678 add r5, pc, r5 */
/* @0x17767c str r0, [sp, #0x68] */
/* @0x177680 mov r0, #1 */
/* @0x177684 bl 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb> */
/* @0x177688 mov r1, r6 */
/* @0x17768c mov r0, #4 */
/* @0x177690 bl 0x1769dc <_Z21GR_3D_Primitive_Beginii> */
/* @0x177694 ldr r1, [pc, #0x40c] */
/* @0x177698 ldr r3, [pc, #0x40c] */
/* @0x17769c vmov.f32 s12, #-1.000000e+00 */
/* @0x1776a0 ldr r2, [pc, #0x408] */
/* @0x1776a4 vldr s15, [pc, #1012] */
/* @0x1776a8 ldr r1, [r5, r1] */
/* @0x1776ac ldr r0, [pc, #0x400] */
/* @0x1776b0 str r1, [sp, #0x3c] */
/* @0x1776b4 ldr r3, [r5, r3] */
/* @0x1776b8 str r3, [sp, #0x40] */
/* @0x1776bc ldr r3, [r1] */
/* @0x1776c0 ldr r12, [r5, r2] */
/* @0x1776c4 ldr r1, [pc, #0x3ec] */
/* @0x1776c8 add r3, r3, r3, lsl #3 */
/* @0x1776cc add r2, r12, r3, lsl #2 */
/* @0x1776d0 ldr r3, [sp, #0x40] */
/* @0x1776d4 vstr s15, [r2, #12] */
/* @0x1776d8 vstr s15, [r2, #16] */
/* @0x1776dc str r10, [r2] */
/* @0x1776e0 vstr s12, [r2, #20] */
/* @0x1776e4 str r2, [r3] */
/* @0x1776e8 str r11, [r2, #0x4] */
/* @0x1776ec str r9, [r2, #0x8] */
/* @0x1776f0 ldr r3, [r5, r0] */
/* @0x1776f4 ldr r0, [r3] */
/* @0x1776f8 bic r0, r0, #1 */
/* @0x1776fc str r0, [r2, #0x18] */
/* @0x177700 ldr r3, [r5, r1] */
/* @0x177704 ldr r1, [r3] */
/* @0x177708 cmp r1, #0 */
/* @0x17770c beq 0x1787a0 <_Z16GR_3D_Draw_Blockffffffiff+0x1164> */
/* @0x177710 ldrsh r12, [r1] */
/* @0x177714 vmov.f32 s11, #1.000000e+00 */
/* @0x177718 ldrsh r3, [r1, #12] */
/* @0x17771c add r6, r2, #1120 */
/* @0x177720 add lr, r2, #1088 */
/* @0x177724 vmov s13, r12 */
/* @0x177728 add r12, r2, #900 */
/* @0x17772c vmov s10, r3 */
/* @0x177730 ldr r3, [pc, #0x384] */
/* @0x177734 str r12, [sp, #0x38] */
/* @0x177738 mov r7, r6 */
/* @0x17773c ldrsh r12, [r1, #2] */
/* @0x177740 mov r8, r6 */
/* @0x177744 ldr r3, [r5, r3] */
/* @0x177748 vldr s14, [r3] */
/* @0x17774c ldrsh r3, [r1, #14] */
/* @0x177750 vmov s6, r12 */
/* @0x177754 ldrsh r12, [r1] */
/* @0x177758 vcvt.f32.s32 s10, s10 */
/* @0x17775c vmov s1, r3 */
/* @0x177760 ldr r3, [pc, #0x358] */
/* @0x177764 vmov s9, r12 */
/* @0x177768 ldrsh r12, [r1, #12] */
/* @0x17776c vmov s4, r12 */
/* @0x177770 ldrsh r12, [r1] */
/* @0x177774 vcvt.f32.s32 s13, s13 */
/* @0x177778 vmla.f32 s13, s10, s15 */
/* @0x17777c vmov s10, r12 */
/* @0x177780 add r12, r2, #1024 */
/* @0x177784 add r12, r12, #12 */
/* @0x177788 vdiv.f32 s13, s13, s14 */
/* @0x17778c vcvt.f32.s32 s6, s6 */
/* @0x177790 vstr s13, [r2, #28] */
/* @0x177794 ldr r3, [r5, r3] */
/* @0x177798 vldr s13, [r3] */
/* @0x17779c ldrsh r3, [r1, #2] */
/* @0x1777a0 ldrsh r5, [r1, #14] */
/* @0x1777a4 vstr s12, [r2, #56] */
/* @0x1777a8 str r4, [r2, #0x48] */
/* @0x1777ac vstr s12, [r2, #92] */
/* @0x1777b0 vmov s8, r3 */
/* @0x1777b4 ldrsh r3, [r1, #12] */
/* @0x1777b8 vmov s3, r5 */
/* @0x1777bc add r5, r2, #1024 */
/* @0x1777c0 vcvt.f32.s32 s1, s1 */
/* @0x1777c4 add r5, r5, #4 */
/* @0x1777c8 vmov s5, r3 */
/* @0x1777cc str r10, [r2, #0x24] */
/* @0x1777d0 vstr s18, [r2, #40] */
/* @0x1777d4 str r9, [r2, #0x2c] */
/* @0x1777d8 vstr s15, [r2, #48] */
/* @0x1777dc vstr s15, [r2, #52] */
/* @0x1777e0 str r0, [r2, #0x3c] */
/* @0x1777e4 vstr s18, [r2, #76] */
/* @0x1777e8 str r9, [r2, #0x50] */
/* @0x1777ec vstr s15, [r2, #84] */
/* @0x1777f0 vstr s15, [r2, #88] */
/* @0x1777f4 str r0, [r2, #0x60] */
/* @0x1777f8 vcvt.f32.s32 s4, s4 */
/* @0x1777fc add r3, r2, #1040 */
/* @0x177800 add r3, r3, #4 */
/* @0x177804 vcvt.f32.s32 s9, s9 */
/* @0x177808 vmov.f32 s7, s6 */
/* @0x17780c vmla.f32 s9, s4, s15 */
/* @0x177810 vmla.f32 s6, s1, s15 */
/* @0x177814 vmla.f32 s7, s17, s1 */
/* @0x177818 vcvt.f32.s32 s3, s3 */
/* @0x17781c vcvt.f32.s32 s5, s5 */
/* @0x177820 vcvt.f32.s32 s8, s8 */
/* @0x177824 vcvt.f32.s32 s10, s10 */
/* @0x177828 vmla.f32 s8, s17, s3 */
/* @0x17782c vmla.f32 s10, s16, s5 */
/* @0x177830 vdiv.f32 s6, s6, s13 */
/* @0x177834 vdiv.f32 s7, s7, s13 */
/* @0x177838 vstr s6, [r2, #32] */
/* @0x17783c vdiv.f32 s9, s9, s14 */
/* @0x177840 vstr s7, [r2, #68] */
/* @0x177844 vdiv.f32 s8, s8, s13 */
/* @0x177848 vstr s9, [r2, #64] */
/* @0x17784c str r5, [sp, #0x8] */
/* @0x177850 add r5, r2, #1040 */
/* @0x177854 add r5, r5, #8 */
/* @0x177858 str r5, [sp, #0x14] */
/* @0x17785c add r5, r2, #1056 */
/* @0x177860 str r3, [sp, #0x10] */
/* @0x177864 add r5, r5, #8 */
/* @0x177868 str r5, [sp, #0x20] */
/* @0x17786c add r5, r2, #1056 */
/* @0x177870 add r3, r2, #1056 */
/* @0x177874 str r5, [sp, #0x74] */
/* @0x177878 add r5, r5, #24 */
/* @0x17787c str r5, [sp, #0x28] */
/* @0x177880 add r5, r2, #1088 */
/* @0x177884 str r12, [sp, #0xc] */
/* @0x177888 add r3, r3, #4 */
/* @0x17788c add r5, r5, #8 */
/* @0x177890 str r3, [sp, #0x1c] */
/* @0x177894 str r5, [sp, #0x34] */
/* @0x177898 add r3, r2, #1040 */
/* @0x17789c ldrsh r5, [r1, #2] */
/* @0x1778a0 add r12, r2, #1040 */
/* @0x1778a4 add r12, r12, #12 */
/* @0x1778a8 str r3, [sp, #0x70] */
/* @0x1778ac str r12, [sp, #0x18] */
/* @0x1778b0 add r3, r3, #36 */
/* @0x1778b4 add r12, r2, #1024 */
/* @0x1778b8 str r3, [sp, #0x24] */
/* @0x1778bc str r12, [sp, #0x6c] */
/* @0x1778c0 add r3, r2, #1088 */
/* @0x1778c4 add r12, r2, #1072 */
/* @0x1778c8 add r3, r3, #4 */
/* @0x1778cc str r12, [sp, #0x78] */
/* @0x1778d0 add r12, r12, #12 */
/* @0x1778d4 str r3, [sp, #0x30] */
/* @0x1778d8 add r3, r2, #1104 */
/* @0x1778dc str r12, [sp, #0x2c] */
/* @0x1778e0 add r12, r2, #1104 */
/* @0x1778e4 add r12, r12, #4 */
/* @0x1778e8 add r3, r3, #8 */
/* @0x1778ec str r12, [sp, #0x4] */
/* @0x1778f0 vmov s6, r5 */
/* @0x1778f4 ldrsh r12, [r1, #14] */
/* @0x1778f8 vstr s18, [r2, #112] */
/* @0x1778fc ldrsh r5, [r1, #12] */
/* @0x177900 str r3, [sp] */
/* @0x177904 ldrsh r3, [r1] */
/* @0x177908 vmov s1, r12 */
/* @0x17790c str r4, [r2, #0x6c] */
/* @0x177910 vmov s3, r5 */
/* @0x177914 ldrsh r12, [r1, #2] */
/* @0x177918 vstr s15, [r2, #120] */
/* @0x17791c str r9, [r2, #0x74] */
/* @0x177920 vmov s7, r12 */
/* @0x177924 vdiv.f32 s10, s10, s14 */
/* @0x177928 vstr s8, [r2, #104] */
/* @0x17792c vmov s8, r3 */
/* @0x177930 ldrsh r3, [r1, #14] */
/* @0x177934 vstr s12, [r2, #128] */
/* @0x177938 str r4, [r2, #0x90] */
/* @0x17793c vstr s15, [r2, #124] */
/* @0x177940 str r0, [r2, #0x84] */
/* @0x177944 vmov s2, r3 */
/* @0x177948 vstr s10, [r2, #100] */
/* @0x17794c str r11, [r2, #0x94] */
/* @0x177950 ldrsh r5, [r1] */
/* @0x177954 vcvt.f32.s32 s1, s1 */
/* @0x177958 ldrsh r12, [r1, #12] */
/* @0x17795c vstr s12, [r2, #164] */
/* @0x177960 ldrsh r3, [r1] */
/* @0x177964 vstr s12, [r2, #200] */
/* @0x177968 vmov s9, r5 */
/* @0x17796c ldrsh r5, [r1, #12] */
/* @0x177970 vmov s4, r12 */
/* @0x177974 add r12, r2, #1136 */
/* @0x177978 vmov s10, r3 */
/* @0x17797c add r3, r2, #1136 */
/* @0x177980 vmov s5, r5 */
/* @0x177984 add r12, r12, #8 */
/* @0x177988 vcvt.f32.s32 s6, s6 */
/* @0x17798c str r12, [sp, #0x44] */
/* @0x177990 add r3, r3, #12 */
/* @0x177994 add r12, r2, #1152 */
/* @0x177998 str r3, [sp, #0x48] */
/* @0x17799c add r3, r2, #1152 */
/* @0x1779a0 add r12, r12, #4 */
/* @0x1779a4 add r3, r3, #8 */
/* @0x1779a8 str r12, [sp, #0x4c] */
/* @0x1779ac vstr s15, [r2, #156] */
/* @0x1779b0 ldrsh r12, [r1, #2] */
/* @0x1779b4 vstr s15, [r2, #160] */
/* @0x1779b8 str r3, [sp, #0x50] */
/* @0x1779bc vstr s15, [r2, #192] */
/* @0x1779c0 vcvt.f32.s32 s2, s2 */
/* @0x1779c4 ldrsh r3, [r1, #14] */
/* @0x1779c8 str r9, [r2, #0x98] */
/* @0x1779cc vstr s15, [r2, #196] */
/* @0x1779d0 str r0, [r2, #0xa8] */
/* @0x1779d4 add r5, r2, #1104 */
/* @0x1779d8 str r10, [r2, #0xb4] */
/* @0x1779dc str r11, [r2, #0xb8] */
/* @0x1779e0 str r9, [r2, #0xbc] */
/* @0x1779e4 str r0, [r2, #0xcc] */
/* @0x1779e8 vcvt.f32.s32 s7, s7 */
/* @0x1779ec str r10, [r2, #0xd8] */
/* @0x1779f0 vcvt.f32.s32 s3, s3 */
/* @0x1779f4 vcvt.f32.s32 s4, s4 */
/* @0x1779f8 vcvt.f32.s32 s5, s5 */
/* @0x1779fc vcvt.f32.s32 s8, s8 */
/* @0x177a00 vcvt.f32.s32 s9, s9 */
/* @0x177a04 vcvt.f32.s32 s10, s10 */
/* @0x177a08 vmla.f32 s6, s17, s1 */
/* @0x177a0c vmov s1, r3 */
/* @0x177a10 ldrsh r3, [r1, #14] */
/* @0x177a14 vmla.f32 s7, s2, s15 */
/* @0x177a18 vmov s2, r3 */
/* @0x177a1c ldrsh r3, [r1, #12] */
/* @0x177a20 vmla.f32 s8, s16, s3 */
/* @0x177a24 vmla.f32 s9, s16, s4 */
/* @0x177a28 vmov s4, r3 */
/* @0x177a2c vmla.f32 s10, s5, s15 */
/* @0x177a30 vdiv.f32 s6, s6, s13 */
/* @0x177a34 vdiv.f32 s7, s7, s13 */
/* @0x177a38 vstr s6, [r2, #140] */
/* @0x177a3c vmov s6, r12 */
/* @0x177a40 ldrsh r12, [r1, #2] */
/* @0x177a44 str r11, [r2, #0xdc] */
/* @0x177a48 vdiv.f32 s8, s8, s14 */
/* @0x177a4c vstr s7, [r2, #176] */
/* @0x177a50 vmov s7, r12 */
/* @0x177a54 ldrsh r12, [r1] */
/* @0x177a58 vstr s19, [r2, #224] */
/* @0x177a5c vdiv.f32 s9, s9, s14 */
/* @0x177a60 vstr s8, [r2, #136] */
/* @0x177a64 vdiv.f32 s10, s10, s14 */
/* @0x177a68 vstr s9, [r2, #172] */
/* @0x177a6c vmov s9, r12 */
/* @0x177a70 vstr s10, [r2, #208] */
/* @0x177a74 vstr s15, [r2, #228] */
/* @0x177a78 ldrsh r12, [r1, #2] */
/* @0x177a7c vcvt.f32.s32 s1, s1 */
/* @0x177a80 ldrsh r3, [r1, #14] */
/* @0x177a84 vstr s11, [r2, #236] */
/* @0x177a88 str r4, [r2, #0xfc] */
/* @0x177a8c vstr s11, [r2, #272] */
/* @0x177a90 vmov s8, r12 */
/* @0x177a94 ldrsh r12, [r1] */
/* @0x177a98 vmov s3, r3 */
/* @0x177a9c b 0x177ac4 <_Z16GR_3D_Draw_Blockffffffiff+0x488> */
/* @0x177aa0 andeq r0, r0, r0 */
/* @0x177aa4 .word 0x0027a5d8 */
/* @0x177aa8 .word 0xffffe670 */
/* @0x177aac .word 0xffffe684 */
/* @0x177ab0 .word 0xffffe680 */
/* @0x177ab4 .word 0xffffc0ac */
/* @0x177ab8 .word 0xffffe540 */
/* @0x177abc .word 0xffffe544 */
/* @0x177ac0 .word 0xffffe548 */
/* @0x177ac4 ldrsh r3, [r1, #12] */
/* @0x177ac8 str lr, [sp, #0x7c] */
/* @0x177acc vstr s15, [r2, #232] */
/* @0x177ad0 vmov s10, r12 */
/* @0x177ad4 add r12, r2, #1152 */
/* @0x177ad8 vmov s5, r3 */
/* @0x177adc add r12, r12, #12 */
/* @0x177ae0 vcvt.f32.s32 s2, s2 */
/* @0x177ae4 str r12, [sp, #0x54] */
/* @0x177ae8 add r3, r2, #1136 */
/* @0x177aec add r12, r2, #1152 */
/* @0x177af0 str r3, [sp, #0x84] */
/* @0x177af4 vstr s19, [r2, #260] */
/* @0x177af8 ldrsh r3, [r1, #2] */
/* @0x177afc vstr s15, [r2, #264] */
/* @0x177b00 str r12, [sp, #0x88] */
/* @0x177b04 vstr s11, [r2, #308] */
/* @0x177b08 ldrsh r12, [r1, #14] */
/* @0x177b0c vstr s15, [r2, #268] */
/* @0x177b10 str r4, [r2, #0x120] */
/* @0x177b14 vstr s18, [r2, #292] */
/* @0x177b18 vcvt.f32.s32 s3, s3 */
/* @0x177b1c str r6, [sp, #0x80] */
/* @0x177b20 vmov s20, r12 */
/* @0x177b24 ldrsh r12, [r1, #12] */
/* @0x177b28 str r0, [r2, #0xf0] */
/* @0x177b2c vstr s19, [r2, #296] */
/* @0x177b30 str r11, [r2, #0x100] */
/* @0x177b34 vstr s15, [r2, #300] */
/* @0x177b38 str r0, [r2, #0x114] */
/* @0x177b3c vstr s15, [r2, #304] */
/* @0x177b40 vcvt.f32.s32 s4, s4 */
/* @0x177b44 vcvt.f32.s32 s5, s5 */
/* @0x177b48 vcvt.f32.s32 s6, s6 */
/* @0x177b4c vcvt.f32.s32 s7, s7 */
/* @0x177b50 vcvt.f32.s32 s8, s8 */
/* @0x177b54 vcvt.f32.s32 s9, s9 */
/* @0x177b58 vcvt.f32.s32 s10, s10 */
/* @0x177b5c vmla.f32 s6, s1, s15 */
/* @0x177b60 vmla.f32 s7, s2, s15 */
/* @0x177b64 vmov s2, r12 */
/* @0x177b68 vmla.f32 s8, s3, s15 */
/* @0x177b6c vmla.f32 s9, s4, s15 */
/* @0x177b70 vmla.f32 s10, s16, s5 */
/* @0x177b74 vmov s5, r3 */
/* @0x177b78 ldrsh r3, [r1] */
/* @0x177b7c vdiv.f32 s6, s6, s13 */
/* @0x177b80 vdiv.f32 s7, s7, s13 */
/* @0x177b84 vstr s6, [r2, #212] */
/* @0x177b88 vdiv.f32 s8, s8, s13 */
/* @0x177b8c vstr s7, [r2, #248] */
/* @0x177b90 vdiv.f32 s9, s9, s14 */
/* @0x177b94 vstr s8, [r2, #284] */
/* @0x177b98 vmov s8, r3 */
/* @0x177b9c ldrsh r3, [r1, #2] */
/* @0x177ba0 vmov s6, r3 */
/* @0x177ba4 vdiv.f32 s10, s10, s14 */
/* @0x177ba8 vstr s9, [r2, #244] */
/* @0x177bac vstr s10, [r2, #280] */
/* @0x177bb0 vstr s11, [r2, #344] */
/* @0x177bb4 ldrsh r12, [r1, #14] */
/* @0x177bb8 vcvt.f32.s32 s20, s20 */
/* @0x177bbc ldrsh r3, [r1] */
/* @0x177bc0 vstr s18, [r2, #328] */
/* @0x177bc4 str r4, [r2, #0x144] */
/* @0x177bc8 vstr s19, [r2, #332] */
/* @0x177bcc vmov s0, r12 */
/* @0x177bd0 ldrsh r12, [r1, #12] */
/* @0x177bd4 vmov s9, r3 */
/* @0x177bd8 ldrsh r3, [r1, #2] */
/* @0x177bdc vstr s11, [r2, #380] */
/* @0x177be0 str r0, [r2, #0x138] */
/* @0x177be4 vmov s3, r12 */
/* @0x177be8 ldrsh r12, [r1, #14] */
/* @0x177bec vmov s7, r3 */
/* @0x177bf0 ldrsh r3, [r1] */
/* @0x177bf4 vcvt.f32.s32 s0, s0 */
/* @0x177bf8 vstr s15, [r2, #336] */
/* @0x177bfc vmov s1, r12 */
/* @0x177c00 ldrsh r12, [r1, #12] */
/* @0x177c04 vmov s10, r3 */
/* @0x177c08 add r3, r2, #1168 */
/* @0x177c0c str r3, [sp, #0x8c] */
/* @0x177c10 vstr s15, [r2, #340] */
/* @0x177c14 vmov s4, r12 */
/* @0x177c18 add r12, r3, #4 */
/* @0x177c1c ldrsh r3, [r1, #2] */
/* @0x177c20 vstr s18, [r2, #364] */
/* @0x177c24 str r12, [sp, #0x58] */
/* @0x177c28 vstr s11, [r2, #416] */
/* @0x177c2c vcvt.f32.s32 s1, s1 */
/* @0x177c30 ldrsh r12, [r1, #14] */
/* @0x177c34 str r0, [r2, #0x15c] */
/* @0x177c38 vstr s19, [r2, #368] */
/* @0x177c3c str r10, [r2, #0x168] */
/* @0x177c40 vstr s15, [r2, #372] */
/* @0x177c44 vstr s15, [r2, #376] */
/* @0x177c48 str r0, [r2, #0x180] */
/* @0x177c4c str r10, [r2, #0x18c] */
/* @0x177c50 vcvt.f32.s32 s2, s2 */
/* @0x177c54 vcvt.f32.s32 s3, s3 */
/* @0x177c58 vcvt.f32.s32 s4, s4 */
/* @0x177c5c vcvt.f32.s32 s5, s5 */
/* @0x177c60 vcvt.f32.s32 s6, s6 */
/* @0x177c64 vcvt.f32.s32 s8, s8 */
/* @0x177c68 vcvt.f32.s32 s7, s7 */
/* @0x177c6c vcvt.f32.s32 s9, s9 */
/* @0x177c70 vcvt.f32.s32 s10, s10 */
/* @0x177c74 vmla.f32 s5, s17, s20 */
/* @0x177c78 vmla.f32 s6, s17, s0 */
/* @0x177c7c vmla.f32 s7, s17, s1 */
/* @0x177c80 vmov s1, r12 */
/* @0x177c84 vmla.f32 s8, s16, s2 */
/* @0x177c88 vmla.f32 s9, s16, s3 */
/* @0x177c8c vmla.f32 s10, s4, s15 */
/* @0x177c90 vdiv.f32 s5, s5, s13 */
/* @0x177c94 vdiv.f32 s6, s6, s13 */
/* @0x177c98 vstr s5, [r2, #320] */
/* @0x177c9c vdiv.f32 s7, s7, s13 */
/* @0x177ca0 vstr s6, [r2, #356] */
/* @0x177ca4 vmov s6, r3 */
/* @0x177ca8 ldrsh r3, [r1] */
/* @0x177cac vdiv.f32 s8, s8, s14 */
/* @0x177cb0 vstr s7, [r2, #392] */
/* @0x177cb4 vdiv.f32 s9, s9, s14 */
/* @0x177cb8 vstr s8, [r2, #316] */
/* @0x177cbc vmov s8, r3 */
/* @0x177cc0 vdiv.f32 s10, s10, s14 */
/* @0x177cc4 vstr s9, [r2, #352] */
/* @0x177cc8 vstr s10, [r2, #388] */
/* @0x177ccc str r11, [r2, #0x190] */
/* @0x177cd0 ldrsh r12, [r1, #12] */
/* @0x177cd4 vcvt.f32.s32 s1, s1 */
/* @0x177cd8 ldrsh r3, [r1, #2] */
/* @0x177cdc vstr s19, [r2, #404] */
/* @0x177ce0 vmov s3, r12 */
/* @0x177ce4 ldrsh r12, [r1, #14] */
/* @0x177ce8 vmov s7, r3 */
/* @0x177cec ldrsh r3, [r1] */
/* @0x177cf0 vstr s11, [r2, #448] */
/* @0x177cf4 vstr s15, [r2, #408] */
/* @0x177cf8 vmov s2, r12 */
/* @0x177cfc ldrsh r12, [r1, #12] */
/* @0x177d00 vmov s9, r3 */
/* @0x177d04 ldrsh r3, [r1] */
/* @0x177d08 vcvt.f32.s32 s2, s2 */
/* @0x177d0c vstr s11, [r2, #484] */
/* @0x177d10 vmov s4, r12 */
/* @0x177d14 ldrsh r12, [r1, #12] */
/* @0x177d18 vmov s10, r3 */
/* @0x177d1c add r3, r2, #1168 */
/* @0x177d20 add r3, r3, #12 */
/* @0x177d24 str r3, [sp, #0x5c] */
/* @0x177d28 vmov s5, r12 */
/* @0x177d2c ldrsh r3, [r1, #14] */
/* @0x177d30 ldrsh r12, [r1, #2] */
/* @0x177d34 vstr s15, [r2, #412] */
/* @0x177d38 str r0, [r2, #0x1a4] */
/* @0x177d3c vstr s18, [r2, #436] */
/* @0x177d40 vcvt.f32.s32 s3, s3 */
/* @0x177d44 str r10, [r2, #0x1b0] */
/* @0x177d48 str r9, [r2, #0x1b8] */
/* @0x177d4c vstr s15, [r2, #444] */
/* @0x177d50 vstr s15, [r2, #452] */
/* @0x177d54 str r0, [r2, #0x1c8] */
/* @0x177d58 str r10, [r2, #0x1d4] */
/* @0x177d5c vstr s18, [r2, #472] */
/* @0x177d60 vstr s19, [r2, #476] */
/* @0x177d64 vstr s15, [r2, #480] */
/* @0x177d68 vstr s15, [r2, #488] */
/* @0x177d6c str r0, [r2, #0x1ec] */
/* @0x177d70 vcvt.f32.s32 s4, s4 */
/* @0x177d74 vcvt.f32.s32 s5, s5 */
/* @0x177d78 vcvt.f32.s32 s6, s6 */
/* @0x177d7c vcvt.f32.s32 s7, s7 */
/* @0x177d80 vcvt.f32.s32 s8, s8 */
/* @0x177d84 vcvt.f32.s32 s9, s9 */
/* @0x177d88 vcvt.f32.s32 s10, s10 */
/* @0x177d8c vmla.f32 s6, s1, s15 */
/* @0x177d90 vmov s1, r3 */
/* @0x177d94 vmla.f32 s7, s2, s15 */
/* @0x177d98 vmla.f32 s8, s3, s15 */
/* @0x177d9c vmla.f32 s9, s4, s15 */
/* @0x177da0 vmla.f32 s10, s5, s15 */
/* @0x177da4 vdiv.f32 s6, s6, s13 */
/* @0x177da8 vdiv.f32 s7, s7, s13 */
/* @0x177dac vstr s6, [r2, #428] */
/* @0x177db0 vmov s6, r12 */
/* @0x177db4 vdiv.f32 s8, s8, s14 */
/* @0x177db8 vstr s7, [r2, #464] */
/* @0x177dbc vdiv.f32 s9, s9, s14 */
/* @0x177dc0 vstr s8, [r2, #424] */
/* @0x177dc4 vdiv.f32 s10, s10, s14 */
/* @0x177dc8 vstr s9, [r2, #460] */
/* @0x177dcc vstr s10, [r2, #496] */
/* @0x177dd0 vstr s11, [r2, #520] */
/* @0x177dd4 ldrsh r12, [r1, #2] */
/* @0x177dd8 vcvt.f32.s32 s1, s1 */
/* @0x177ddc ldrsh r3, [r1, #14] */
/* @0x177de0 str r4, [r2, #0x1f8] */
/* @0x177de4 vmov s7, r12 */
/* @0x177de8 ldrsh r12, [r1] */
/* @0x177dec vmov s2, r3 */
/* @0x177df0 ldrsh r3, [r1, #12] */
/* @0x177df4 vstr s18, [r2, #508] */
/* @0x177df8 vstr s11, [r2, #556] */
/* @0x177dfc vmov s9, r12 */
/* @0x177e00 ldrsh r12, [r1, #2] */
/* @0x177e04 vmov s4, r3 */
/* @0x177e08 ldrsh r3, [r1, #14] */
/* @0x177e0c vcvt.f32.s32 s2, s2 */
/* @0x177e10 str r4, [r2, #0x21c] */
/* @0x177e14 vmov s8, r12 */
/* @0x177e18 ldrsh r12, [r1] */
/* @0x177e1c vmov s3, r3 */
/* @0x177e20 ldrsh r3, [r1, #12] */
/* @0x177e24 vstr s19, [r2, #512] */
/* @0x177e28 str r4, [r2, #0x240] */
/* @0x177e2c vmov s10, r12 */
/* @0x177e30 ldrsh r12, [r1, #2] */
/* @0x177e34 vmov s5, r3 */
/* @0x177e38 ldrsh r3, [r1, #14] */
/* @0x177e3c vstr s11, [r2, #592] */
/* @0x177e40 vstr s15, [r2, #516] */
/* @0x177e44 vcvt.f32.s32 s3, s3 */
/* @0x177e48 vstr s15, [r2, #524] */
/* @0x177e4c vmov s20, r3 */
/* @0x177e50 ldrsh r3, [r1, #12] */
/* @0x177e54 str r0, [r2, #0x210] */
/* @0x177e58 vstr s18, [r2, #544] */
/* @0x177e5c vstr s19, [r2, #548] */
/* @0x177e60 vstr s15, [r2, #552] */
/* @0x177e64 vstr s15, [r2, #560] */
/* @0x177e68 str r0, [r2, #0x234] */
/* @0x177e6c vstr s18, [r2, #580] */
/* @0x177e70 str r9, [r2, #0x248] */
/* @0x177e74 vstr s15, [r2, #588] */
/* @0x177e78 vstr s15, [r2, #596] */
/* @0x177e7c vcvt.f32.s32 s4, s4 */
/* @0x177e80 vcvt.f32.s32 s5, s5 */
/* @0x177e84 vcvt.f32.s32 s6, s6 */
/* @0x177e88 vcvt.f32.s32 s7, s7 */
/* @0x177e8c vcvt.f32.s32 s8, s8 */
/* @0x177e90 vcvt.f32.s32 s9, s9 */
/* @0x177e94 vcvt.f32.s32 s10, s10 */
/* @0x177e98 vmla.f32 s6, s17, s1 */
/* @0x177e9c vmla.f32 s7, s17, s2 */
/* @0x177ea0 vmov s2, r3 */
/* @0x177ea4 vmla.f32 s8, s17, s3 */
/* @0x177ea8 vmla.f32 s9, s16, s4 */
/* @0x177eac vmla.f32 s10, s16, s5 */
/* @0x177eb0 vmov s5, r12 */
/* @0x177eb4 ldrsh r12, [r1] */
/* @0x177eb8 vdiv.f32 s6, s6, s13 */
/* @0x177ebc vdiv.f32 s7, s7, s13 */
/* @0x177ec0 vstr s6, [r2, #500] */
/* @0x177ec4 vdiv.f32 s8, s8, s13 */
/* @0x177ec8 vstr s7, [r2, #536] */
/* @0x177ecc vdiv.f32 s9, s9, s14 */
/* @0x177ed0 vstr s8, [r2, #572] */
/* @0x177ed4 vmov s8, r12 */
/* @0x177ed8 ldrsh r12, [r1, #2] */
/* @0x177edc vmov s6, r12 */
/* @0x177ee0 vdiv.f32 s10, s10, s14 */
/* @0x177ee4 vstr s9, [r2, #532] */
/* @0x177ee8 vstr s10, [r2, #568] */
/* @0x177eec vstr s11, [r2, #628] */
/* @0x177ef0 ldrsh r3, [r1, #14] */
/* @0x177ef4 vcvt.f32.s32 s2, s2 */
/* @0x177ef8 ldrsh r12, [r1] */
/* @0x177efc vstr s18, [r2, #616] */
/* @0x177f00 str r10, [r2, #0x264] */
/* @0x177f04 vstr s15, [r2, #624] */
/* @0x177f08 vmov s0, r3 */
/* @0x177f0c ldrsh r3, [r1, #12] */
/* @0x177f10 vmov s9, r12 */
/* @0x177f14 ldrsh r12, [r1, #2] */
/* @0x177f18 vstr s11, [r2, #660] */
/* @0x177f1c str r4, [r2, #0x288] */
/* @0x177f20 vmov s3, r3 */
/* @0x177f24 ldrsh r3, [r1, #14] */
/* @0x177f28 vmov s7, r12 */
/* @0x177f2c ldrsh r12, [r1] */
/* @0x177f30 vcvt.f32.s32 s0, s0 */
/* @0x177f34 str r0, [r2, #0x258] */
/* @0x177f38 vmov s1, r3 */
/* @0x177f3c ldrsh r3, [r1, #12] */
/* @0x177f40 vmov s10, r12 */
/* @0x177f44 add r12, r2, #1184 */
/* @0x177f48 add r12, r12, #4 */
/* @0x177f4c str r12, [sp, #0x60] */
/* @0x177f50 vmov s4, r3 */
/* @0x177f54 ldrsh r12, [r1, #14] */
/* @0x177f58 ldrsh r3, [r1, #2] */
/* @0x177f5c vstr s15, [r2, #632] */
/* @0x177f60 vstr s11, [r2, #696] */
/* @0x177f64 str r4, [r2, #0x2ac] */
/* @0x177f68 vcvt.f32.s32 s1, s1 */
/* @0x177f6c str r9, [r2, #0x26c] */
/* @0x177f70 str r0, [r2, #0x27c] */
/* @0x177f74 vstr s18, [r2, #652] */
/* @0x177f78 str r9, [r2, #0x290] */
/* @0x177f7c vstr s15, [r2, #664] */
/* @0x177f80 vstr s15, [r2, #668] */
/* @0x177f84 str r0, [r2, #0x2a0] */
/* @0x177f88 vcvt.f32.s32 s3, s3 */
/* @0x177f8c vcvt.f32.s32 s4, s4 */
/* @0x177f90 vcvt.f32.s32 s5, s5 */
/* @0x177f94 vcvt.f32.s32 s20, s20 */
/* @0x177f98 vcvt.f32.s32 s6, s6 */
/* @0x177f9c vcvt.f32.s32 s8, s8 */
/* @0x177fa0 vcvt.f32.s32 s7, s7 */
/* @0x177fa4 vcvt.f32.s32 s9, s9 */
/* @0x177fa8 vcvt.f32.s32 s10, s10 */
/* @0x177fac vmla.f32 s6, s0, s15 */
/* @0x177fb0 vmla.f32 s7, s1, s15 */
/* @0x177fb4 vmov s1, r12 */
/* @0x177fb8 vmla.f32 s8, s16, s2 */
/* @0x177fbc vmla.f32 s9, s3, s15 */
/* @0x177fc0 vmla.f32 s10, s4, s15 */
/* @0x177fc4 vmla.f32 s5, s20, s15 */
/* @0x177fc8 vdiv.f32 s6, s6, s13 */
/* @0x177fcc vdiv.f32 s5, s5, s13 */
/* @0x177fd0 vstr s6, [r2, #644] */
/* @0x177fd4 vmov s6, r3 */
/* @0x177fd8 ldrsh r3, [r1] */
/* @0x177fdc vdiv.f32 s7, s7, s13 */
/* @0x177fe0 vstr s5, [r2, #608] */
/* @0x177fe4 vdiv.f32 s8, s8, s14 */
/* @0x177fe8 vstr s7, [r2, #680] */
/* @0x177fec vdiv.f32 s9, s9, s14 */
/* @0x177ff0 vstr s8, [r2, #604] */
/* @0x177ff4 vmov s8, r3 */
/* @0x177ff8 vdiv.f32 s10, s10, s14 */
/* @0x177ffc vstr s9, [r2, #640] */
/* @0x178000 vstr s10, [r2, #676] */
/* @0x178004 vstr s18, [r2, #688] */
/* @0x178008 ldrsh r12, [r1, #12] */
/* @0x17800c vcvt.f32.s32 s1, s1 */
/* @0x178010 ldrsh r3, [r1, #2] */
/* @0x178014 vstr s11, [r2, #732] */
/* @0x178018 str r4, [r2, #0x2d0] */
/* @0x17801c vstr s19, [r2, #692] */
/* @0x178020 vmov s3, r12 */
/* @0x178024 ldrsh r12, [r1, #14] */
/* @0x178028 vmov s7, r3 */
/* @0x17802c ldrsh r3, [r1] */
/* @0x178030 vstr s15, [r2, #700] */
/* @0x178034 vstr s15, [r2, #704] */
/* @0x178038 vmov s2, r12 */
/* @0x17803c ldrsh r12, [r1, #12] */
/* @0x178040 vmov s9, r3 */
/* @0x178044 ldrsh r3, [r1] */
/* @0x178048 vcvt.f32.s32 s2, s2 */
/* @0x17804c vstr s11, [r2, #768] */
/* @0x178050 vmov s4, r12 */
/* @0x178054 ldrsh r12, [r1, #12] */
/* @0x178058 vmov s10, r3 */
/* @0x17805c ldrsh r3, [r1, #2] */
/* @0x178060 str r4, [r2, #0x2f4] */
/* @0x178064 vstr s19, [r2, #728] */
/* @0x178068 vmov s5, r12 */
/* @0x17806c ldrsh r12, [r1, #14] */
/* @0x178070 str r0, [r2, #0x2c4] */
/* @0x178074 vstr s11, [r2, #804] */
/* @0x178078 str r11, [r2, #0x2d4] */
/* @0x17807c vstr s15, [r2, #736] */
/* @0x178080 vcvt.f32.s32 s3, s3 */
/* @0x178084 vstr s15, [r2, #740] */
/* @0x178088 str r0, [r2, #0x2e8] */
/* @0x17808c vstr s19, [r2, #764] */
/* @0x178090 str r11, [r2, #0x2f8] */
/* @0x178094 vstr s15, [r2, #772] */
/* @0x178098 vstr s15, [r2, #776] */
/* @0x17809c str r0, [r2, #0x30c] */
/* @0x1780a0 vcvt.f32.s32 s4, s4 */
/* @0x1780a4 vcvt.f32.s32 s5, s5 */
/* @0x1780a8 vcvt.f32.s32 s6, s6 */
/* @0x1780ac vcvt.f32.s32 s7, s7 */
/* @0x1780b0 vcvt.f32.s32 s8, s8 */
/* @0x1780b4 vcvt.f32.s32 s9, s9 */
/* @0x1780b8 vcvt.f32.s32 s10, s10 */
/* @0x1780bc vmla.f32 s6, s17, s1 */
/* @0x1780c0 vmla.f32 s7, s17, s2 */
/* @0x1780c4 vmov s2, r12 */
/* @0x1780c8 vmla.f32 s8, s3, s15 */
/* @0x1780cc vmla.f32 s9, s16, s4 */
/* @0x1780d0 vmla.f32 s10, s16, s5 */
/* @0x1780d4 vdiv.f32 s6, s6, s13 */
/* @0x1780d8 vdiv.f32 s7, s7, s13 */
/* @0x1780dc vstr s6, [r2, #716] */
/* @0x1780e0 vdiv.f32 s8, s8, s14 */
/* @0x1780e4 vstr s7, [r2, #752] */
/* @0x1780e8 vmov s7, r3 */
/* @0x1780ec ldrsh r3, [r1] */
/* @0x1780f0 vdiv.f32 s9, s9, s14 */
/* @0x1780f4 vstr s8, [r2, #712] */
/* @0x1780f8 vdiv.f32 s10, s10, s14 */
/* @0x1780fc vstr s9, [r2, #748] */
/* @0x178100 vstr s10, [r2, #784] */
/* @0x178104 str r4, [r2, #0x318] */
/* @0x178108 ldrsh r12, [r1, #12] */
/* @0x17810c vmov s10, r3 */
/* @0x178110 ldrsh r3, [r1, #2] */
/* @0x178114 vcvt.f32.s32 s2, s2 */
/* @0x178118 str r11, [r2, #0x31c] */
/* @0x17811c vstr s15, [r2, #808] */
/* @0x178120 vmov s5, r12 */
/* @0x178124 ldrsh r12, [r1, #14] */
/* @0x178128 vmov s8, r3 */
/* @0x17812c ldrsh r3, [r1, #2] */
/* @0x178130 vstr s11, [r2, #840] */
/* @0x178134 str r4, [r2, #0x33c] */
/* @0x178138 vmov s3, r12 */
/* @0x17813c ldrsh r12, [r1, #14] */
/* @0x178140 vmov s9, r3 */
/* @0x178144 ldrsh r3, [r1] */
/* @0x178148 vcvt.f32.s32 s3, s3 */
/* @0x17814c str r9, [r2, #0x320] */
/* @0x178150 vmov s4, r12 */
/* @0x178154 ldrsh r12, [r1, #12] */
/* @0x178158 vmov s11, r3 */
/* @0x17815c ldrsh r3, [r1, #2] */
/* @0x178160 str r4, [r2, #0x360] */
/* @0x178164 vstr s12, [r2, #880] */
/* @0x178168 vmov s6, r12 */
/* @0x17816c ldrsh r12, [r1, #14] */
/* @0x178170 vstr s15, [r2, #812] */
/* @0x178174 str r0, [r2, #0x330] */
/* @0x178178 vstr s18, [r2, #832] */
/* @0x17817c str r9, [r2, #0x344] */
/* @0x178180 vcvt.f32.s32 s4, s4 */
/* @0x178184 vstr s15, [r2, #844] */
/* @0x178188 vmov s0, r12 */
/* @0x17818c ldrsh r12, [r1, #12] */
/* @0x178190 vstr s15, [r2, #848] */
/* @0x178194 str r0, [r2, #0x354] */
/* @0x178198 str r11, [r2, #0x364] */
/* @0x17819c vstr s15, [r2, #876] */
/* @0x1781a0 str r9, [r2, #0x368] */
/* @0x1781a4 vstr s15, [r2, #884] */
/* @0x1781a8 vcvt.f32.s32 s5, s5 */
/* @0x1781ac vcvt.f32.s32 s6, s6 */
/* @0x1781b0 vcvt.f32.s32 s7, s7 */
/* @0x1781b4 vcvt.f32.s32 s8, s8 */
/* @0x1781b8 vcvt.f32.s32 s9, s9 */
/* @0x1781bc vcvt.f32.s32 s10, s10 */
/* @0x1781c0 vcvt.f32.s32 s11, s11 */
/* @0x1781c4 vmla.f32 s7, s17, s2 */
/* @0x1781c8 vmla.f32 s8, s3, s15 */
/* @0x1781cc vmov s3, r12 */
/* @0x1781d0 vmla.f32 s9, s4, s15 */
/* @0x1781d4 vmla.f32 s10, s16, s5 */
/* @0x1781d8 vmla.f32 s11, s6, s15 */
/* @0x1781dc vmov s6, r3 */
/* @0x1781e0 ldrsh r3, [r1] */
/* @0x1781e4 vdiv.f32 s7, s7, s13 */
/* @0x1781e8 vdiv.f32 s8, s8, s13 */
/* @0x1781ec vstr s7, [r2, #788] */
/* @0x1781f0 vdiv.f32 s9, s9, s13 */
/* @0x1781f4 vstr s8, [r2, #824] */
/* @0x1781f8 vdiv.f32 s10, s10, s14 */
/* @0x1781fc vstr s9, [r2, #860] */
/* @0x178200 vmov s9, r3 */
/* @0x178204 ldrsh r3, [r1, #2] */
/* @0x178208 vmov s7, r3 */
/* @0x17820c vdiv.f32 s11, s11, s14 */
/* @0x178210 vstr s10, [r2, #820] */
/* @0x178214 vstr s11, [r2, #856] */
/* @0x178218 str r4, [r2, #0x384] */
/* @0x17821c ldrsh r12, [r1, #14] */
/* @0x178220 vcvt.f32.s32 s6, s6 */
/* @0x178224 ldr r3, [sp, #0x38] */
/* @0x178228 vstr s12, [r2, #916] */
/* @0x17822c str r11, [r2, #0x388] */
/* @0x178230 vstr s19, [r2, #908] */
/* @0x178234 vmov s1, r12 */
/* @0x178238 ldr r12, [sp, #0x40] */
/* @0x17823c str r0, [r2, #0x378] */
/* @0x178240 vstr s15, [r2, #912] */
/* @0x178244 vstr s15, [r2, #920] */
/* @0x178248 str r0, [r2, #0x39c] */
/* @0x17824c str r3, [r12] */
/* @0x178250 ldrsh r3, [r1] */
/* @0x178254 vcvt.f32.s32 s0, s0 */
/* @0x178258 ldrsh r12, [r1, #12] */
/* @0x17825c vstr s12, [r2, #952] */
/* @0x178260 str r10, [r2, #0x3a8] */
/* @0x178264 vstr s19, [r2, #944] */
/* @0x178268 vmov s10, r3 */
/* @0x17826c ldrsh r3, [r1, #2] */
/* @0x178270 vmov s4, r12 */
/* @0x178274 ldrsh r12, [r1, #14] */
/* @0x178278 str r11, [r2, #0x3ac] */
/* @0x17827c vstr s15, [r2, #948] */
/* @0x178280 vmov s8, r3 */
/* @0x178284 ldrsh r3, [r1] */
/* @0x178288 vmov s2, r12 */
/* @0x17828c ldrsh r12, [r1, #12] */
/* @0x178290 vcvt.f32.s32 s4, s4 */
/* @0x178294 vstr s15, [r2, #956] */
/* @0x178298 vmov s11, r3 */
/* @0x17829c add r3, r2, #1184 */
/* @0x1782a0 vmov s5, r12 */
/* @0x1782a4 add r12, r2, #1184 */
/* @0x1782a8 add r3, r3, #8 */
/* @0x1782ac add r12, r12, #12 */
/* @0x1782b0 str r3, [sp, #0x38] */
/* @0x1782b4 str r12, [sp, #0x64] */
/* @0x1782b8 ldrsh r3, [r1, #2] */
/* @0x1782bc vcvt.f32.s32 s5, s5 */
/* @0x1782c0 str r0, [r2, #0x3c0] */
/* @0x1782c4 vcvt.f32.s32 s7, s7 */
/* @0x1782c8 vcvt.f32.s32 s1, s1 */
/* @0x1782cc vcvt.f32.s32 s9, s9 */
/* @0x1782d0 vcvt.f32.s32 s8, s8 */
/* @0x1782d4 vcvt.f32.s32 s3, s3 */
/* @0x1782d8 vcvt.f32.s32 s2, s2 */
/* @0x1782dc vcvt.f32.s32 s10, s10 */
/* @0x1782e0 vcvt.f32.s32 s11, s11 */
/* @0x1782e4 vmla.f32 s10, s4, s15 */
/* @0x1782e8 vmla.f32 s11, s16, s5 */
/* @0x1782ec vmla.f32 s6, s0, s15 */
/* @0x1782f0 vmla.f32 s7, s17, s1 */
/* @0x1782f4 vmla.f32 s8, s17, s2 */
/* @0x1782f8 vmla.f32 s9, s3, s15 */
/* @0x1782fc vdiv.f32 s6, s6, s13 */
/* @0x178300 vdiv.f32 s7, s7, s13 */
/* @0x178304 vstr s6, [r2, #896] */
/* @0x178308 vdiv.f32 s8, s8, s13 */
/* @0x17830c vstr s7, [r2, #932] */
/* @0x178310 vmov s7, r3 */
/* @0x178314 vdiv.f32 s9, s9, s14 */
/* @0x178318 vstr s8, [r2, #968] */
/* @0x17831c vdiv.f32 s10, s10, s14 */
/* @0x178320 vstr s9, [r2, #892] */
/* @0x178324 vdiv.f32 s11, s11, s14 */
/* @0x178328 vstr s10, [r2, #928] */
/* @0x17832c vstr s11, [r2, #964] */
/* @0x178330 str r10, [r2, #0x3cc] */
/* @0x178334 ldrsh r12, [r1, #14] */
/* @0x178338 vcvt.f32.s32 s7, s7 */
/* @0x17833c ldrsh r3, [r1] */
/* @0x178340 vstr s19, [r2, #980] */
/* @0x178344 vstr s12, [r2, #988] */
/* @0x178348 str r11, [r2, #0x3d0] */
/* @0x17834c vmov s4, r12 */
/* @0x178350 ldrsh r12, [r1, #12] */
/* @0x178354 vmov s8, r3 */
/* @0x178358 ldrsh r3, [r1, #2] */
/* @0x17835c vstr s15, [r2, #984] */
/* @0x178360 vstr s15, [r2, #992] */
/* @0x178364 vmov s5, r12 */
/* @0x178368 ldrsh r12, [r1, #14] */
/* @0x17836c vmov s9, r3 */
/* @0x178370 ldrsh r3, [r1] */
/* @0x178374 vcvt.f32.s32 s5, s5 */
/* @0x178378 str r0, [r2, #0x3e4] */
/* @0x17837c vmov s6, r12 */
/* @0x178380 ldrsh r12, [r1, #12] */
/* @0x178384 vmov s10, r3 */
/* @0x178388 str r10, [r2, #0x3f0] */
/* @0x17838c str r11, [r2, #0x3f4] */
/* @0x178390 vstr s15, [r2, #1020] */
/* @0x178394 vmov s11, r12 */
/* @0x178398 str r9, [r2, #0x3f8] */
/* @0x17839c vcvt.f32.s32 s11, s11 */
/* @0x1783a0 vcvt.f32.s32 s4, s4 */
/* @0x1783a4 vcvt.f32.s32 s8, s8 */
/* @0x1783a8 vcvt.f32.s32 s10, s10 */
/* @0x1783ac vcvt.f32.s32 s6, s6 */
/* @0x1783b0 vcvt.f32.s32 s9, s9 */
/* @0x1783b4 vmla.f32 s8, s16, s5 */
/* @0x1783b8 vmla.f32 s10, s16, s11 */
/* @0x1783bc vmov s11, r3 */
/* @0x1783c0 ldr r3, [sp, #0x6c] */
/* @0x1783c4 vmla.f32 s7, s17, s4 */
/* @0x1783c8 vmla.f32 s9, s6, s15 */
/* @0x1783cc vmov s6, r12 */
/* @0x1783d0 ldr r12, [sp, #0x8] */
/* @0x1783d4 vcvt.f32.s32 s6, s6 */
/* @0x1783d8 vcvt.f32.s32 s11, s11 */
/* @0x1783dc vmla.f32 s11, s6, s15 */
/* @0x1783e0 vdiv.f32 s7, s7, s13 */
/* @0x1783e4 vdiv.f32 s8, s8, s14 */
/* @0x1783e8 vstr s7, [r2, #1004] */
/* @0x1783ec vdiv.f32 s10, s10, s14 */
/* @0x1783f0 vstr s8, [r2, #1000] */
/* @0x1783f4 vstr s12, [r3] */
/* @0x1783f8 vstr s15, [r12] */
/* @0x1783fc ldr r3, [sp, #0xc] */
/* @0x178400 str r0, [r2, #0x408] */
/* @0x178404 ldr r12, [sp, #0x70] */
/* @0x178408 vdiv.f32 s9, s9, s13 */
/* @0x17840c vstr s10, [r3] */
/* @0x178410 ldr r3, [sp, #0x10] */
/* @0x178414 vdiv.f32 s11, s11, s14 */
/* @0x178418 vstr s9, [r12] */
/* @0x17841c str r4, [r3] */
/* @0x178420 ldr r12, [sp, #0x18] */
/* @0x178424 ldr r4, [sp, #0x14] */
/* @0x178428 str r11, [r4] */
/* @0x17842c str r9, [r12] */
/* @0x178430 ldr r4, [sp, #0x1c] */
/* @0x178434 ldr r3, [sp, #0x74] */
/* @0x178438 vstr s15, [r3] */
/* @0x17843c ldr r12, [sp, #0x20] */
/* @0x178440 vstr s12, [r4] */
/* @0x178444 vstr s15, [r12] */
/* @0x178448 add r4, r2, #1200 */
/* @0x17844c add r12, r2, #1216 */
/* @0x178450 add r4, r4, #8 */
/* @0x178454 add r12, r12, #4 */
/* @0x178458 str r4, [sp, #0xc] */
/* @0x17845c str r12, [sp, #0x10] */
/* @0x178460 add r4, r2, #1216 */
/* @0x178464 add r12, r2, #1232 */
/* @0x178468 add r4, r4, #12 */
/* @0x17846c add r12, r12, #4 */
/* @0x178470 str r4, [sp, #0x18] */
/* @0x178474 str r12, [sp, #0x1c] */
/* @0x178478 add r3, r2, #1200 */
/* @0x17847c ldrsh r4, [r1, #2] */
/* @0x178480 add r3, r3, #4 */
/* @0x178484 ldrsh r12, [r1, #14] */
/* @0x178488 str r3, [sp, #0x8] */
/* @0x17848c add r3, r2, #1216 */
/* @0x178490 str r0, [r2, #0x42c] */
/* @0x178494 add r3, r3, #8 */
/* @0x178498 vmov s7, r4 */
/* @0x17849c str r3, [sp, #0x14] */
/* @0x1784a0 ldr r3, [sp, #0x78] */
/* @0x1784a4 ldrsh r4, [r1, #2] */
/* @0x1784a8 vmov s10, r4 */
/* @0x1784ac ldr r4, [sp, #0x2c] */
/* @0x1784b0 vstr s11, [r3] */
/* @0x1784b4 vmov s11, r12 */
/* @0x1784b8 vcvt.f32.s32 s7, s7 */
/* @0x1784bc ldrsh r12, [r1] */
/* @0x1784c0 ldrsh r3, [r1, #12] */
/* @0x1784c4 vmov s9, r12 */
/* @0x1784c8 ldrsh r12, [r1, #14] */
/* @0x1784cc vcvt.f32.s32 s11, s11 */
/* @0x1784d0 vmla.f32 s7, s11, s15 */
/* @0x1784d4 vmov s11, r3 */
/* @0x1784d8 ldr r3, [sp, #0x28] */
/* @0x1784dc vcvt.f32.s32 s11, s11 */
/* @0x1784e0 vcvt.f32.s32 s9, s9 */
/* @0x1784e4 vmla.f32 s9, s11, s15 */
/* @0x1784e8 vmov s11, r12 */
/* @0x1784ec ldr r12, [sp, #0x24] */
/* @0x1784f0 vcvt.f32.s32 s11, s11 */
/* @0x1784f4 vcvt.f32.s32 s10, s10 */
/* @0x1784f8 vmla.f32 s10, s17, s11 */
/* @0x1784fc vdiv.f32 s7, s7, s13 */
/* @0x178500 vdiv.f32 s9, s9, s14 */
/* @0x178504 vstr s7, [r12] */
/* @0x178508 str r10, [r3] */
/* @0x17850c str r11, [r4] */
/* @0x178510 ldr r3, [sp, #0x30] */
/* @0x178514 str r9, [lr] */
/* @0x178518 vstr s12, [r3] */
/* @0x17851c ldr r4, [sp, #0x34] */
/* @0x178520 vstr s15, [r4] */
/* @0x178524 vstr s15, [lr, #12] */
/* @0x178528 add r4, r2, #1200 */
/* @0x17852c str r0, [r2, #0x450] */
/* @0x178530 add lr, r2, #1264 */
/* @0x178534 str r4, [sp, #0x2c] */
/* @0x178538 add r4, r2, #1264 */
/* @0x17853c ldr r12, [sp, #0x4] */
/* @0x178540 add r4, r4, #4 */
/* @0x178544 ldr r3, [sp] */
/* @0x178548 str r4, [sp, #0x24] */
/* @0x17854c ldr r4, [sp, #0x44] */
/* @0x178550 vdiv.f32 s10, s10, s13 */
/* @0x178554 vstr s9, [r12] */
/* @0x178558 vstr s7, [r3] */
/* @0x17855c str r10, [r5, #0xc] */
/* @0x178560 str r11, [r6] */
/* @0x178564 vstr s19, [r6, #4] */
/* @0x178568 ldr r5, [sp, #0x84] */
/* @0x17856c vstr s12, [r7, #8] */
/* @0x178570 vstr s15, [r8, #12] */
/* @0x178574 vstr s15, [r5] */
/* @0x178578 str r0, [r2, #0x474] */
/* @0x17857c vstr s9, [r4] */
/* @0x178580 ldr r4, [sp, #0x48] */
/* @0x178584 add r12, r2, #1248 */
/* @0x178588 add r12, r12, #4 */
/* @0x17858c str r12, [sp, #0x20] */
/* @0x178590 add r12, r2, #1216 */
/* @0x178594 str r12, [sp, #0x30] */
/* @0x178598 add r12, r2, #1264 */
/* @0x17859c add r7, r2, #1232 */
/* @0x1785a0 add r3, r2, #1184 */
/* @0x1785a4 add r12, r12, #8 */
/* @0x1785a8 str r3, [sp, #0x28] */
/* @0x1785ac add r5, r2, #1248 */
/* @0x1785b0 str r12, [sp, #0x6c] */
/* @0x1785b4 mov r6, r7 */
/* @0x1785b8 str r7, [sp, #0x34] */
/* @0x1785bc mov r8, r5 */
/* @0x1785c0 add r12, r2, #1280 */
/* @0x1785c4 mov r3, r12 */
/* @0x1785c8 vstr s10, [r4] */
/* @0x1785cc ldr r4, [sp, #0x88] */
/* @0x1785d0 str r10, [r4] */
/* @0x1785d4 ldr r4, [sp, #0x4c] */
/* @0x1785d8 vstr s18, [r4] */
/* @0x1785dc ldr r4, [sp, #0x50] */
/* @0x1785e0 vstr s19, [r4] */
/* @0x1785e4 ldr r4, [sp, #0x54] */
/* @0x1785e8 vstr s12, [r4] */
/* @0x1785ec ldr r4, [sp, #0x8c] */
/* @0x1785f0 vstr s15, [r4] */
/* @0x1785f4 ldrsh r4, [r1, #2] */
/* @0x1785f8 vmov s6, r4 */
/* @0x1785fc ldr r4, [sp, #0x58] */
/* @0x178600 vstr s15, [r4] */
/* @0x178604 ldrsh r4, [r1, #14] */
/* @0x178608 vcvt.f32.s32 s6, s6 */
/* @0x17860c str r0, [r2, #0x498] */
/* @0x178610 vmov s10, r4 */
/* @0x178614 ldrsh r4, [r1] */
/* @0x178618 vmov s7, r4 */
/* @0x17861c ldrsh r4, [r1, #12] */
/* @0x178620 vcvt.f32.s32 s10, s10 */
/* @0x178624 vmov s11, r4 */
/* @0x178628 ldrsh r4, [r1, #2] */
/* @0x17862c vmov s8, r4 */
/* @0x178630 ldrsh r4, [r1, #2] */
/* @0x178634 vcvt.f32.s32 s8, s8 */
/* @0x178638 vcvt.f32.s32 s11, s11 */
/* @0x17863c vcvt.f32.s32 s7, s7 */
/* @0x178640 vmla.f32 s6, s17, s10 */
/* @0x178644 vmla.f32 s8, s17, s10 */
/* @0x178648 vmov s10, r4 */
/* @0x17864c ldrsh r4, [r1, #14] */
/* @0x178650 vmov s5, r4 */
/* @0x178654 ldr r4, [sp, #0x5c] */
/* @0x178658 vcvt.f32.s32 s10, s10 */
/* @0x17865c vcvt.f32.s32 s5, s5 */
/* @0x178660 vmla.f32 s7, s16, s11 */
/* @0x178664 vmla.f32 s10, s5, s15 */
/* @0x178668 vdiv.f32 s7, s7, s14 */
/* @0x17866c vdiv.f32 s6, s6, s13 */
/* @0x178670 vstr s7, [r4] */
/* @0x178674 ldr r4, [sp, #0x28] */
/* @0x178678 vdiv.f32 s8, s8, s13 */
/* @0x17867c vstr s6, [r4] */
/* @0x178680 ldr r4, [sp, #0x60] */
/* @0x178684 str r10, [r4] */
/* @0x178688 ldr r4, [sp, #0x38] */
/* @0x17868c vstr s18, [r4] */
/* @0x178690 ldr r4, [sp, #0x64] */
/* @0x178694 vstr s19, [r4] */
/* @0x178698 ldr r4, [sp, #0x2c] */
/* @0x17869c vstr s12, [r4] */
/* @0x1786a0 ldr r4, [sp, #0x8] */
/* @0x1786a4 vstr s15, [r4] */
/* @0x1786a8 ldr r4, [sp, #0xc] */
/* @0x1786ac vstr s15, [r4] */
/* @0x1786b0 str r0, [r2, #0x4bc] */
/* @0x1786b4 ldr r4, [sp, #0x30] */
/* @0x1786b8 vstr s7, [r4] */
/* @0x1786bc ldr r4, [sp, #0x10] */
/* @0x1786c0 vdiv.f32 s10, s10, s13 */
/* @0x1786c4 vstr s8, [r4] */
/* @0x1786c8 ldr r4, [sp, #0x14] */
/* @0x1786cc str r10, [r4] */
/* @0x1786d0 ldr r4, [sp, #0x18] */
/* @0x1786d4 vstr s18, [r4] */
/* @0x1786d8 ldr r4, [sp, #0x1c] */
/* @0x1786dc str r9, [r7] */
/* @0x1786e0 vstr s12, [r4] */
/* @0x1786e4 vstr s15, [r7, #8] */
/* @0x1786e8 ldr r4, [sp, #0x20] */
/* @0x1786ec vstr s15, [r6, #12] */
/* @0x1786f0 str r0, [r2, #0x4e0] */
/* @0x1786f4 vstr s7, [r4] */
/* @0x1786f8 ldrsh r4, [r1, #14] */
/* @0x1786fc vmov s9, r4 */
/* @0x178700 ldr r4, [sp, #0x6c] */
/* @0x178704 vstr s10, [r5, #8] */
/* @0x178708 ldrsh r5, [r1, #2] */
/* @0x17870c vcvt.f32.s32 s9, s9 */
/* @0x178710 vmov s11, r5 */
/* @0x178714 ldrsh r5, [r1] */
/* @0x178718 ldrsh r1, [r1, #12] */
/* @0x17871c str r10, [r8, #0xc]! */
/* @0x178720 vmov s8, r5 */
/* @0x178724 str r11, [lr] */
/* @0x178728 vmov s10, r1 */
/* @0x17872c ldr r1, [sp, #0x24] */
/* @0x178730 vcvt.f32.s32 s11, s11 */
/* @0x178734 str r9, [r1] */
/* @0x178738 vstr s12, [r4] */
/* @0x17873c vstr s15, [lr, #12] */
/* @0x178740 vstr s15, [r12] */
/* @0x178744 str r0, [r2, #0x504] */
/* @0x178748 vcvt.f32.s32 s12, s8 */
/* @0x17874c vcvt.f32.s32 s10, s10 */
/* @0x178750 vmla.f32 s11, s9, s15 */
/* @0x178754 vmla.f32 s12, s10, s15 */
/* @0x178758 vdiv.f32 s13, s11, s13 */
/* @0x17875c vdiv.f32 s14, s12, s14 */
/* @0x178760 vstr s14, [r12, #8] */
/* @0x178764 vstr s13, [r3, #12] */
/* @0x178768 ldr r1, [sp, #0x3c] */
/* @0x17876c add r2, r8, #36 */
/* @0x178770 ldr r4, [sp, #0x40] */
/* @0x178774 ldr r3, [r1] */
/* @0x178778 str r2, [r4] */
/* @0x17877c add r3, r3, #36 */
/* @0x178780 str r3, [r1] */
/* @0x178784 bl 0x176ad0 <_Z19GR_3D_Primitive_Endv> */
/* @0x178788 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x17878c ldr r0, [sp, #0x68] */
/* @0x178790 add sp, sp, #148 */
/* @0x178794 vpop {d8, d9, d10} */
/* @0x178798 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17879c b 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb> */
/* @0x1787a0 add r3, r2, #1024 */
/* @0x1787a4 mov r1, #1065353216 */
/* @0x1787a8 str r4, [r2, #0x48] */
/* @0x1787ac vstr s15, [r2, #28] */
/* @0x1787b0 str r4, [r2, #0x6c] */
/* @0x1787b4 vstr s15, [r2, #32] */
/* @0x1787b8 str r4, [r2, #0x90] */
/* @0x1787bc vstr s18, [r2, #40] */
/* @0x1787c0 str r10, [r2, #0x24] */
/* @0x1787c4 vstr s15, [r2, #48] */
/* @0x1787c8 str r9, [r2, #0x2c] */
/* @0x1787cc vstr s15, [r2, #52] */
/* @0x1787d0 vstr s12, [r2, #56] */
/* @0x1787d4 str r0, [r2, #0x3c] */
/* @0x1787d8 vstr s15, [r2, #64] */
/* @0x1787dc vstr s17, [r2, #68] */
/* @0x1787e0 vstr s18, [r2, #76] */
/* @0x1787e4 str r9, [r2, #0x50] */
/* @0x1787e8 vstr s15, [r2, #84] */
/* @0x1787ec vstr s15, [r2, #88] */
/* @0x1787f0 vstr s12, [r2, #92] */
/* @0x1787f4 str r0, [r2, #0x60] */
/* @0x1787f8 vstr s16, [r2, #100] */
/* @0x1787fc vstr s17, [r2, #104] */
/* @0x178800 vstr s18, [r2, #112] */
/* @0x178804 str r9, [r2, #0x74] */
/* @0x178808 vstr s15, [r2, #120] */
/* @0x17880c vstr s15, [r2, #124] */
/* @0x178810 vstr s12, [r2, #128] */
/* @0x178814 str r0, [r2, #0x84] */
/* @0x178818 vstr s16, [r2, #136] */
/* @0x17881c vstr s17, [r2, #140] */
/* @0x178820 str r11, [r2, #0x94] */
/* @0x178824 vstr s15, [r2, #156] */
/* @0x178828 str r9, [r2, #0x98] */
/* @0x17882c vstr s15, [r2, #160] */
/* @0x178830 str r4, [r2, #0xfc] */
/* @0x178834 vstr s12, [r2, #164] */
/* @0x178838 str r4, [r2, #0x120] */
/* @0x17883c vstr s16, [r2, #172] */
/* @0x178840 str r1, [r2, #0xec] */
/* @0x178844 vstr s15, [r2, #176] */
/* @0x178848 str r1, [r2, #0x110] */
/* @0x17884c vstr s15, [r2, #192] */
/* @0x178850 str r0, [r2, #0xa8] */
/* @0x178854 vstr s15, [r2, #196] */
/* @0x178858 str r10, [r2, #0xb4] */
/* @0x17885c vstr s12, [r2, #200] */
/* @0x178860 str r11, [r2, #0xb8] */
/* @0x178864 vstr s15, [r2, #208] */
/* @0x178868 str r9, [r2, #0xbc] */
/* @0x17886c vstr s15, [r2, #212] */
/* @0x178870 str r0, [r2, #0xcc] */
/* @0x178874 vstr s19, [r2, #224] */
/* @0x178878 str r10, [r2, #0xd8] */
/* @0x17887c vstr s15, [r2, #228] */
/* @0x178880 str r11, [r2, #0xdc] */
/* @0x178884 vstr s15, [r2, #232] */
/* @0x178888 str r0, [r2, #0xf0] */
/* @0x17888c vstr s15, [r2, #244] */
/* @0x178890 vstr s15, [r2, #248] */
/* @0x178894 str r11, [r2, #0x100] */
/* @0x178898 vstr s19, [r2, #260] */
/* @0x17889c vstr s15, [r2, #264] */
/* @0x1788a0 vstr s15, [r2, #268] */
/* @0x1788a4 str r0, [r2, #0x114] */
/* @0x1788a8 vstr s16, [r2, #280] */
/* @0x1788ac vstr s15, [r2, #284] */
/* @0x1788b0 vstr s18, [r2, #292] */
/* @0x1788b4 vstr s19, [r2, #296] */
/* @0x1788b8 str r1, [r2, #0x134] */
/* @0x1788bc vstr s15, [r2, #300] */
/* @0x1788c0 str r1, [r2, #0x158] */
/* @0x1788c4 vstr s15, [r2, #304] */
/* @0x1788c8 str r1, [r2, #0x17c] */
/* @0x1788cc vstr s16, [r2, #316] */
/* @0x1788d0 str r1, [r2, #0x1a0] */
/* @0x1788d4 vstr s17, [r2, #320] */
/* @0x1788d8 str r4, [r2, #0x144] */
/* @0x1788dc vstr s18, [r2, #328] */
/* @0x1788e0 str r0, [r2, #0x138] */
/* @0x1788e4 vstr s19, [r2, #332] */
/* @0x1788e8 vstr s15, [r2, #336] */
/* @0x1788ec vstr s15, [r2, #340] */
/* @0x1788f0 str r0, [r2, #0x15c] */
/* @0x1788f4 vstr s16, [r2, #352] */
/* @0x1788f8 vstr s17, [r2, #356] */
/* @0x1788fc str r10, [r2, #0x168] */
/* @0x178900 vstr s18, [r2, #364] */
/* @0x178904 vstr s19, [r2, #368] */
/* @0x178908 vstr s15, [r2, #372] */
/* @0x17890c vstr s15, [r2, #376] */
/* @0x178910 str r0, [r2, #0x180] */
/* @0x178914 vstr s15, [r2, #388] */
/* @0x178918 vstr s17, [r2, #392] */
/* @0x17891c str r10, [r2, #0x18c] */
/* @0x178920 str r11, [r2, #0x190] */
/* @0x178924 vstr s19, [r2, #404] */
/* @0x178928 vstr s15, [r2, #408] */
/* @0x17892c vstr s15, [r2, #412] */
/* @0x178930 str r0, [r2, #0x1a4] */
/* @0x178934 vstr s15, [r2, #424] */
/* @0x178938 vstr s15, [r2, #428] */
/* @0x17893c str r10, [r2, #0x1b0] */
/* @0x178940 str r1, [r2, #0x1c0] */
/* @0x178944 vstr s18, [r2, #436] */
/* @0x178948 str r1, [r2, #0x1e4] */
/* @0x17894c vstr s15, [r2, #444] */
/* @0x178950 str r1, [r2, #0x208] */
/* @0x178954 vstr s15, [r2, #452] */
/* @0x178958 str r1, [r2, #0x22c] */
/* @0x17895c vstr s15, [r2, #460] */
/* @0x178960 str r4, [r2, #0x1f8] */
/* @0x178964 vstr s15, [r2, #464] */
/* @0x178968 str r4, [r2, #0x21c] */
/* @0x17896c vstr s18, [r2, #472] */
/* @0x178970 str r9, [r2, #0x1b8] */
/* @0x178974 vstr s19, [r2, #476] */
/* @0x178978 str r0, [r2, #0x1c8] */
/* @0x17897c vstr s15, [r2, #480] */
/* @0x178980 str r10, [r2, #0x1d4] */
/* @0x178984 vstr s15, [r2, #488] */
/* @0x178988 str r0, [r2, #0x1ec] */
/* @0x17898c vstr s15, [r2, #496] */
/* @0x178990 vstr s17, [r2, #500] */
/* @0x178994 vstr s18, [r2, #508] */
/* @0x178998 vstr s19, [r2, #512] */
/* @0x17899c vstr s15, [r2, #516] */
/* @0x1789a0 vstr s15, [r2, #524] */
/* @0x1789a4 str r0, [r2, #0x210] */
/* @0x1789a8 vstr s16, [r2, #532] */
/* @0x1789ac vstr s17, [r2, #536] */
/* @0x1789b0 vstr s18, [r2, #544] */
/* @0x1789b4 vstr s19, [r2, #548] */
/* @0x1789b8 vstr s15, [r2, #552] */
/* @0x1789bc vstr s15, [r2, #560] */
/* @0x1789c0 str r0, [r2, #0x234] */
/* @0x1789c4 vstr s16, [r2, #568] */
/* @0x1789c8 str r1, [r2, #0x250] */
/* @0x1789cc vstr s17, [r2, #572] */
/* @0x1789d0 str r1, [r2, #0x274] */
/* @0x1789d4 vstr s18, [r2, #580] */
/* @0x1789d8 str r1, [r2, #0x294] */
/* @0x1789dc vstr s15, [r2, #588] */
/* @0x1789e0 str r1, [r2, #0x2b8] */
/* @0x1789e4 vstr s15, [r2, #596] */
/* @0x1789e8 str r4, [r2, #0x240] */
/* @0x1789ec vstr s16, [r2, #604] */
/* @0x1789f0 str r4, [r2, #0x288] */
/* @0x1789f4 vstr s15, [r2, #608] */
/* @0x1789f8 str r4, [r2, #0x2ac] */
/* @0x1789fc vstr s18, [r2, #616] */
/* @0x178a00 str r9, [r2, #0x248] */
/* @0x178a04 vstr s15, [r2, #624] */
/* @0x178a08 str r0, [r2, #0x258] */
/* @0x178a0c vstr s15, [r2, #632] */
/* @0x178a10 str r10, [r2, #0x264] */
/* @0x178a14 vstr s15, [r2, #640] */
/* @0x178a18 str r9, [r2, #0x26c] */
/* @0x178a1c vstr s15, [r2, #644] */
/* @0x178a20 str r0, [r2, #0x27c] */
/* @0x178a24 vstr s18, [r2, #652] */
/* @0x178a28 str r9, [r2, #0x290] */
/* @0x178a2c vstr s15, [r2, #664] */
/* @0x178a30 vstr s15, [r2, #668] */
/* @0x178a34 str r0, [r2, #0x2a0] */
/* @0x178a38 vstr s15, [r2, #676] */
/* @0x178a3c vstr s15, [r2, #680] */
/* @0x178a40 vstr s18, [r2, #688] */
/* @0x178a44 vstr s19, [r2, #692] */
/* @0x178a48 vstr s15, [r2, #700] */
/* @0x178a4c vstr s15, [r2, #704] */
/* @0x178a50 str r1, [r2, #0x2dc] */
/* @0x178a54 vstr s15, [r2, #712] */
/* @0x178a58 str r1, [r2, #0x300] */
/* @0x178a5c vstr s17, [r2, #716] */
/* @0x178a60 str r1, [r2, #0x324] */
/* @0x178a64 vstr s19, [r2, #728] */
/* @0x178a68 str r4, [r2, #0x2d0] */
/* @0x178a6c vstr s15, [r2, #736] */
/* @0x178a70 str r4, [r2, #0x2f4] */
/* @0x178a74 vstr s15, [r2, #740] */
/* @0x178a78 str r4, [r2, #0x318] */
/* @0x178a7c vstr s16, [r2, #748] */
/* @0x178a80 str r4, [r2, #0x33c] */
/* @0x178a84 vstr s17, [r2, #752] */
/* @0x178a88 str r0, [r2, #0x2c4] */
/* @0x178a8c vstr s19, [r2, #764] */
/* @0x178a90 str r11, [r2, #0x2d4] */
/* @0x178a94 vstr s15, [r2, #772] */
/* @0x178a98 str r0, [r2, #0x2e8] */
/* @0x178a9c vstr s15, [r2, #776] */
/* @0x178aa0 str r11, [r2, #0x2f8] */
/* @0x178aa4 vstr s16, [r2, #784] */
/* @0x178aa8 str r0, [r2, #0x30c] */
/* @0x178aac vstr s17, [r2, #788] */
/* @0x178ab0 str r11, [r2, #0x31c] */
/* @0x178ab4 vstr s15, [r2, #808] */
/* @0x178ab8 str r9, [r2, #0x320] */
/* @0x178abc vstr s15, [r2, #812] */
/* @0x178ac0 str r0, [r2, #0x330] */
/* @0x178ac4 vstr s16, [r2, #820] */
/* @0x178ac8 vstr s15, [r2, #824] */
/* @0x178acc vstr s18, [r2, #832] */
/* @0x178ad0 str r9, [r2, #0x344] */
/* @0x178ad4 add r8, r2, #1248 */
/* @0x178ad8 str r1, [r2, #0x348] */
/* @0x178adc mov r1, r3 */
/* @0x178ae0 str r4, [r2, #0x360] */
/* @0x178ae4 vstr s15, [r2, #844] */
/* @0x178ae8 str r4, [r2, #0x384] */
/* @0x178aec vstr s15, [r2, #848] */
/* @0x178af0 str r0, [r2, #0x354] */
/* @0x178af4 vstr s15, [r2, #856] */
/* @0x178af8 vstr s15, [r2, #860] */
/* @0x178afc str r11, [r2, #0x364] */
/* @0x178b00 str r9, [r2, #0x368] */
/* @0x178b04 vstr s15, [r2, #876] */
/* @0x178b08 vstr s12, [r2, #880] */
/* @0x178b0c vstr s15, [r2, #884] */
/* @0x178b10 str r0, [r2, #0x378] */
/* @0x178b14 vstr s15, [r2, #892] */
/* @0x178b18 vstr s15, [r2, #896] */
/* @0x178b1c str r11, [r2, #0x388] */
/* @0x178b20 vstr s19, [r2, #908] */
/* @0x178b24 vstr s15, [r2, #912] */
/* @0x178b28 vstr s12, [r2, #916] */
/* @0x178b2c vstr s15, [r2, #920] */
/* @0x178b30 str r0, [r2, #0x39c] */
/* @0x178b34 vstr s15, [r2, #928] */
/* @0x178b38 vstr s17, [r2, #932] */
/* @0x178b3c str r10, [r2, #0x3a8] */
/* @0x178b40 str r11, [r2, #0x3ac] */
/* @0x178b44 vstr s19, [r2, #944] */
/* @0x178b48 vstr s15, [r2, #948] */
/* @0x178b4c vstr s12, [r2, #952] */
/* @0x178b50 vstr s15, [r2, #956] */
/* @0x178b54 str r0, [r2, #0x3c0] */
/* @0x178b58 vstr s16, [r2, #964] */
/* @0x178b5c vstr s17, [r2, #968] */
/* @0x178b60 str r10, [r2, #0x3cc] */
/* @0x178b64 str r11, [r2, #0x3d0] */
/* @0x178b68 vstr s19, [r2, #980] */
/* @0x178b6c vstr s15, [r2, #984] */
/* @0x178b70 vstr s12, [r2, #988] */
/* @0x178b74 vstr s15, [r2, #992] */
/* @0x178b78 str r0, [r2, #0x3e4] */
/* @0x178b7c vstr s16, [r2, #1000] */
/* @0x178b80 vstr s17, [r2, #1004] */
/* @0x178b84 str r10, [r2, #0x3f0] */
/* @0x178b88 vstr s15, [r2, #1020] */
/* @0x178b8c str r11, [r2, #0x3f4] */
/* @0x178b90 str r9, [r2, #0x3f8] */
/* @0x178b94 vstr s12, [r3] */
/* @0x178b98 vstr s15, [r3, #4] */
/* @0x178b9c add r3, r2, #1040 */
/* @0x178ba0 str r0, [r2, #0x408] */
/* @0x178ba4 vstr s16, [r1, #12] */
/* @0x178ba8 mov r1, r3 */
/* @0x178bac str r4, [r3, #0x4] */
/* @0x178bb0 vstr s15, [r3] */
/* @0x178bb4 str r11, [r1, #0x8] */
/* @0x178bb8 str r9, [r1, #0xc] */
/* @0x178bbc add r3, r2, #1056 */
/* @0x178bc0 add r1, r2, #1072 */
/* @0x178bc4 vstr s15, [r3] */
/* @0x178bc8 vstr s12, [r3, #4] */
/* @0x178bcc mov r12, r3 */
/* @0x178bd0 mov r3, r1 */
/* @0x178bd4 vstr s15, [r12, #8] */
/* @0x178bd8 str r0, [r2, #0x42c] */
/* @0x178bdc mov r12, r1 */
/* @0x178be0 vstr s15, [r1, #4] */
/* @0x178be4 vstr s15, [r1] */
/* @0x178be8 add r1, r2, #1088 */
/* @0x178bec str r10, [r3, #0x8] */
/* @0x178bf0 str r11, [r12, #0xc] */
/* @0x178bf4 vstr s12, [r1, #4] */
/* @0x178bf8 str r9, [r1] */
/* @0x178bfc mov r3, r1 */
/* @0x178c00 mov r12, r1 */
/* @0x178c04 add r1, r2, #1104 */
/* @0x178c08 vstr s15, [r3, #8] */
/* @0x178c0c vstr s15, [r12, #12] */
/* @0x178c10 mov r3, r1 */
/* @0x178c14 mov r12, r1 */
/* @0x178c18 str r0, [r2, #0x450] */
/* @0x178c1c vstr s15, [r1, #4] */
/* @0x178c20 add r1, r2, #1120 */
/* @0x178c24 vstr s15, [r3, #8] */
/* @0x178c28 str r10, [r12, #0xc] */
/* @0x178c2c vstr s19, [r1, #4] */
/* @0x178c30 str r11, [r1] */
/* @0x178c34 mov r3, r1 */
/* @0x178c38 mov r12, r1 */
/* @0x178c3c vstr s12, [r3, #8] */
/* @0x178c40 add r1, r2, #1136 */
/* @0x178c44 vstr s15, [r12, #12] */
/* @0x178c48 add r12, r2, #1152 */
/* @0x178c4c vstr s15, [r1] */
/* @0x178c50 mov r3, r1 */
/* @0x178c54 str r0, [r2, #0x474] */
/* @0x178c58 vstr s15, [r1, #8] */
/* @0x178c5c vstr s17, [r3, #12] */
/* @0x178c60 mov r1, r12 */
/* @0x178c64 str r10, [r12] */
/* @0x178c68 vstr s18, [r12, #4] */
/* @0x178c6c mov r3, r12 */
/* @0x178c70 vstr s19, [r1, #8] */
/* @0x178c74 add r12, r2, #1168 */
/* @0x178c78 vstr s12, [r3, #12] */
/* @0x178c7c add r3, r2, #1184 */
/* @0x178c80 vstr s15, [r12] */
/* @0x178c84 vstr s15, [r12, #4] */
/* @0x178c88 mov r1, r12 */
/* @0x178c8c str r0, [r2, #0x498] */
/* @0x178c90 mov r12, r3 */
/* @0x178c94 vstr s16, [r1, #12] */
/* @0x178c98 vstr s17, [r3] */
/* @0x178c9c str r10, [r3, #0x4] */
/* @0x178ca0 vstr s18, [r12, #8] */
/* @0x178ca4 add r12, r2, #1216 */
/* @0x178ca8 add r4, r2, #1232 */
/* @0x178cac mov r1, r3 */
/* @0x178cb0 add r3, r2, #1200 */
/* @0x178cb4 vstr s19, [r1, #12] */
/* @0x178cb8 mov r1, r12 */
/* @0x178cbc vstr s12, [r3] */
/* @0x178cc0 vstr s15, [r3, #4] */
/* @0x178cc4 mov lr, r3 */
/* @0x178cc8 mov r3, r12 */
/* @0x178ccc vstr s15, [lr, #8] */
/* @0x178cd0 str r0, [r2, #0x4bc] */
/* @0x178cd4 mov lr, r4 */
/* @0x178cd8 vstr s16, [r12] */
/* @0x178cdc vstr s17, [r12, #4] */
/* @0x178ce0 str r10, [r1, #0x8] */
/* @0x178ce4 mov r12, r4 */
/* @0x178ce8 vstr s18, [r3, #12] */
/* @0x178cec add r1, r2, #1280 */
/* @0x178cf0 str r9, [r4] */
/* @0x178cf4 vstr s12, [r4, #4] */
/* @0x178cf8 add r4, r2, #1264 */
/* @0x178cfc vstr s15, [lr, #8] */
/* @0x178d00 mov r3, r1 */
/* @0x178d04 vstr s15, [r12, #12] */
/* @0x178d08 mov lr, r4 */
/* @0x178d0c str r0, [r2, #0x4e0] */
/* @0x178d10 mov r12, r4 */
/* @0x178d14 vstr s16, [r8, #4] */
/* @0x178d18 vstr s15, [r8, #8] */
/* @0x178d1c str r10, [r8, #0xc]! */
/* @0x178d20 str r11, [r4] */
/* @0x178d24 str r9, [r4, #0x4] */
/* @0x178d28 vstr s12, [lr, #8] */
/* @0x178d2c vstr s15, [r12, #12] */
/* @0x178d30 vstr s15, [r1] */
/* @0x178d34 str r0, [r2, #0x504] */
/* @0x178d38 vstr s15, [r1, #8] */
/* @0x178d3c vstr s15, [r3, #12] */
/* @0x178d40 b 0x178768 <_Z16GR_3D_Draw_Blockffffffiff+0x112c> */

/* ── FUNC 0x178d44 · GR_3D_Draw_Cylinder(float, float, float, float, float, float, int, float, float, bool, int) · size=848 · insn=212 */
/* @0x178d44 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x178d48 vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x178d4c sub sp, sp, #1056 */
/* @0x178d50 sub sp, sp, #12 */
/* @0x178d54 mov r7, r2 */
/* @0x178d58 add r2, sp, #2048 */
/* @0x178d5c vldr s19, [r2, #-888] */
/* @0x178d60 add r2, sp, #2048 */
/* @0x178d64 vmov s21, r3 */
/* @0x178d68 vldr s25, [r2, #-876] */
/* @0x178d6c ldr r3, [sp, #0x490] */
/* @0x178d70 ldr r8, [r2, #-0x374] */
/* @0x178d74 vmov s18, r1 */
/* @0x178d78 ldrb r2, [sp, #0x49c] */
/* @0x178d7c vmov s20, r0 */
/* @0x178d80 ldr r5, [sp, #0x4a0] */
/* @0x178d84 str r3, [sp, #0x18] */
/* @0x178d88 add r3, sp, #2048 */
/* @0x178d8c str r2, [sp, #0x14] */
/* @0x178d90 vldr s24, [r3, #-872] */
/* @0x178d94 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x178d98 bl 0x1689e0 <_Z25GR_D3D_Get_Texture_Repeatv> */
/* @0x178d9c str r0, [sp, #0x1c] */
/* @0x178da0 mov r0, #1 */
/* @0x178da4 bl 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb> */
/* @0x178da8 cmp r5, #2 */
/* @0x178dac ble 0x178f1c <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x1d8> */
/* @0x178db0 cmp r5, #128 */
/* @0x178db4 ble 0x179070 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x32c> */
/* @0x178db8 mov r10, #1065353216 */
/* @0x178dbc mov r5, #128 */
/* @0x178dc0 mov r0, #0 */
/* @0x178dc4 vldr s22, [pc, #700] */
/* @0x178dc8 add r2, sp, #548 */
/* @0x178dcc add r11, sp, #32 */
/* @0x178dd0 str r2, [sp, #0x10] */
/* @0x178dd4 mov r4, #0 */
/* @0x178dd8 mov r9, r2 */
/* @0x178ddc vldr s17, [pc, #680] */
/* @0x178de0 mov r6, r11 */
/* @0x178de4 b 0x178e10 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0xcc> */
/* @0x178de8 vmov s13, r4 */
/* @0x178dec vcvt.f32.s32 s16, s13 */
/* @0x178df0 vadd.f32 s16, s16, s16 */
/* @0x178df4 vmul.f32 s16, s16, s17 */
/* @0x178df8 vdiv.f32 s16, s16, s22 */
/* @0x178dfc vmov r0, s16 */
/* @0x178e00 bl 0xb658c <cosf@plt> */
/* @0x178e04 mov r10, r0 */
/* @0x178e08 vmov r0, s16 */
/* @0x178e0c bl 0xb6580 <sinf@plt> */
/* @0x178e10 add r4, r4, #1 */
/* @0x178e14 str r10, [r6], #4 */
/* @0x178e18 cmp r5, r4 */
/* @0x178e1c str r0, [r9], #4 */
/* @0x178e20 bge 0x178de8 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0xa4> */
/* @0x178e24 vmov.f32 s15, #5.000000e-01 */
/* @0x178e28 ldr r2, [sp, #0x14] */
/* @0x178e2c cmp r2, #0 */
/* @0x178e30 vadd.f32 s26, s21, s20 */
/* @0x178e34 vadd.f32 s23, s19, s18 */
/* @0x178e38 vsub.f32 s20, s21, s20 */
/* @0x178e3c vsub.f32 s18, s19, s18 */
/* @0x178e40 vmul.f32 s26, s26, s15 */
/* @0x178e44 vmul.f32 s27, s20, s15 */
/* @0x178e48 vmul.f32 s23, s23, s15 */
/* @0x178e4c vmul.f32 s28, s18, s15 */
/* @0x178e50 bne 0x178fdc <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x298> */
/* @0x178e54 mov r0, #5 */
/* @0x178e58 ldr r1, [sp, #0x18] */
/* @0x178e5c bl 0x1769dc <_Z21GR_3D_Primitive_Beginii> */
/* @0x178e60 add r10, sp, #548 */
/* @0x178e64 mov r6, r11 */
/* @0x178e68 mov r4, #0 */
/* @0x178e6c vldr s18, [pc, #540] */
/* @0x178e70 vmov s15, r4 */
/* @0x178e74 vldmia r6!, {s16} */
/* @0x178e78 vldmia r10!, {s17} */
/* @0x178e7c vmov r3, s16 */
/* @0x178e80 mov r2, r8 */
/* @0x178e84 vstr s18, [sp, #4] */
/* @0x178e88 vstr s24, [sp, #12] */
/* @0x178e8c vstr s17, [sp] */
/* @0x178e90 add r4, r4, #1 */
/* @0x178e94 mov r9, #0 */
/* @0x178e98 vcvt.f32.s32 s21, s15 */
/* @0x178e9c vmul.f32 s21, s21, s25 */
/* @0x178ea0 vdiv.f32 s21, s21, s22 */
/* @0x178ea4 vmov.f32 s20, s26 */
/* @0x178ea8 vstr s21, [sp, #8] */
/* @0x178eac vmov.f32 s19, s23 */
/* @0x178eb0 vmla.f32 s20, s16, s27 */
/* @0x178eb4 vmla.f32 s19, s17, s28 */
/* @0x178eb8 vmov r0, s20 */
/* @0x178ebc vmov r1, s19 */
/* @0x178ec0 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x178ec4 vstr s21, [sp, #8] */
/* @0x178ec8 vstr s17, [sp] */
/* @0x178ecc vstr s18, [sp, #4] */
/* @0x178ed0 vstr s18, [sp, #12] */
/* @0x178ed4 vmov r0, s20 */
/* @0x178ed8 vmov r1, s19 */
/* @0x178edc mov r2, r7 */
/* @0x178ee0 vmov r3, s16 */
/* @0x178ee4 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x178ee8 cmp r5, r4 */
/* @0x178eec bge 0x178e70 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x12c> */
/* @0x178ef0 bl 0x176ad0 <_Z19GR_3D_Primitive_Endv> */
/* @0x178ef4 ldr r2, [sp, #0x14] */
/* @0x178ef8 cmp r2, #0 */
/* @0x178efc bne 0x178f40 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x1fc> */
/* @0x178f00 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x178f04 ldr r0, [sp, #0x1c] */
/* @0x178f08 add sp, sp, #1056 */
/* @0x178f0c add sp, sp, #12 */
/* @0x178f10 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x178f14 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x178f18 b 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb> */
/* @0x178f1c vmov.f32 s22, #3.000000e+00 */
/* @0x178f20 mov r5, #3 */
/* @0x178f24 mov r4, #0 */
/* @0x178f28 mov r0, r4 */
/* @0x178f2c bl 0xb658c <cosf@plt> */
/* @0x178f30 mov r10, r0 */
/* @0x178f34 mov r0, r4 */
/* @0x178f38 bl 0xb6580 <sinf@plt> */
/* @0x178f3c b 0x178dc8 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x84> */
/* @0x178f40 ldr r1, [sp, #0x18] */
/* @0x178f44 mov r0, #6 */
/* @0x178f48 bl 0x1769dc <_Z21GR_3D_Primitive_Beginii> */
/* @0x178f4c mov r6, #0 */
/* @0x178f50 mov r2, r7 */
/* @0x178f54 mov r3, r9 */
/* @0x178f58 movt r6, #0xbf80 */
/* @0x178f5c str r9, [sp] */
/* @0x178f60 str r9, [sp, #0x8] */
/* @0x178f64 mov r4, r9 */
/* @0x178f68 str r9, [sp, #0xc] */
/* @0x178f6c vmov r0, s26 */
/* @0x178f70 vmov r1, s23 */
/* @0x178f74 str r6, [sp, #0x4] */
/* @0x178f78 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x178f7c add r3, r5, #1 */
/* @0x178f80 add r2, sp, #548 */
/* @0x178f84 lsl r3, r3, #2 */
/* @0x178f88 add r11, r11, r3 */
/* @0x178f8c add r10, r2, r3 */
/* @0x178f90 vmov.f32 s13, s26 */
/* @0x178f94 str r4, [sp] */
/* @0x178f98 str r6, [sp, #0x4] */
/* @0x178f9c mov r3, #0 */
/* @0x178fa0 str r4, [sp, #0x8] */
/* @0x178fa4 mov r2, r7 */
/* @0x178fa8 str r4, [sp, #0xc] */
/* @0x178fac vldmdb r10!, {s15} */
/* @0x178fb0 vldmdb r11!, {s14} */
/* @0x178fb4 vmla.f32 s13, s27, s14 */
/* @0x178fb8 vmov.f32 s14, s23 */
/* @0x178fbc vmov r0, s13 */
/* @0x178fc0 vmla.f32 s14, s28, s15 */
/* @0x178fc4 vmov r1, s14 */
/* @0x178fc8 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x178fcc subs r5, r5, #1 */
/* @0x178fd0 bpl 0x178f90 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x24c> */
/* @0x178fd4 bl 0x176ad0 <_Z19GR_3D_Primitive_Endv> */
/* @0x178fd8 b 0x178f00 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x1bc> */
/* @0x178fdc vmov.f32 s16, #1.000000e+00 */
/* @0x178fe0 mov r6, #0 */
/* @0x178fe4 mov r0, #6 */
/* @0x178fe8 ldr r1, [sp, #0x18] */
/* @0x178fec bl 0x1769dc <_Z21GR_3D_Primitive_Beginii> */
/* @0x178ff0 vstr s24, [sp, #12] */
/* @0x178ff4 str r6, [sp] */
/* @0x178ff8 mov r3, r6 */
/* @0x178ffc str r6, [sp, #0x8] */
/* @0x179000 mov r2, r8 */
/* @0x179004 vmov r0, s26 */
/* @0x179008 add r9, sp, #548 */
/* @0x17900c vmov r1, s23 */
/* @0x179010 mov r4, r11 */
/* @0x179014 mov r10, #0 */
/* @0x179018 vstr s16, [sp, #4] */
/* @0x17901c bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x179020 vmov.f32 s13, s26 */
/* @0x179024 str r6, [sp] */
/* @0x179028 vstr s16, [sp, #4] */
/* @0x17902c str r6, [sp, #0x8] */
/* @0x179030 vstr s24, [sp, #12] */
/* @0x179034 vldmia r4!, {s14} */
/* @0x179038 vldmia r9!, {s15} */
/* @0x17903c add r10, r10, #1 */
/* @0x179040 vmla.f32 s13, s14, s27 */
/* @0x179044 mov r2, r8 */
/* @0x179048 mov r3, #0 */
/* @0x17904c vmov.f32 s14, s23 */
/* @0x179050 vmov r0, s13 */
/* @0x179054 vmla.f32 s14, s15, s28 */
/* @0x179058 vmov r1, s14 */
/* @0x17905c bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x179060 cmp r5, r10 */
/* @0x179064 bge 0x179020 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x2dc> */
/* @0x179068 bl 0x176ad0 <_Z19GR_3D_Primitive_Endv> */
/* @0x17906c b 0x178e54 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x110> */
/* @0x179070 vmov s13, r5 */
/* @0x179074 vldr s15, [pc, #20] */
/* @0x179078 vcvt.f32.s32 s22, s13 */
/* @0x17907c vdiv.f32 s15, s15, s22 */
/* @0x179080 vmov r4, s15 */
/* @0x179084 b 0x178f28 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x1e4> */
/* @0x179088 movwmi r0, #0x0 */
/* @0x17908c ldrdmi r0, r1, [r9], #-251 */
/* @0x179090 andeq r0, r0, r0 */

/* ── FUNC 0x179094 · GR_3D_Draw_Cone(float, float, float, float, float, float, int, float, float, bool, int) · size=696 · insn=174 */
/* @0x179094 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x179098 vpush {d8, d9, d10, d11, d12} */
/* @0x17909c sub sp, sp, #1056 */
/* @0x1790a0 sub sp, sp, #12 */
/* @0x1790a4 mov r8, r2 */
/* @0x1790a8 add r2, sp, #2048 */
/* @0x1790ac vldr s25, [r2, #-904] */
/* @0x1790b0 add r2, sp, #2048 */
/* @0x1790b4 vmov s21, r3 */
/* @0x1790b8 vldr s22, [r2, #-892] */
/* @0x1790bc ldr r3, [sp, #0x480] */
/* @0x1790c0 ldr r9, [r2, #-0x384] */
/* @0x1790c4 vmov s24, r1 */
/* @0x1790c8 ldrb r2, [sp, #0x48c] */
/* @0x1790cc vmov s18, r0 */
/* @0x1790d0 ldr r4, [sp, #0x490] */
/* @0x1790d4 str r3, [sp, #0x14] */
/* @0x1790d8 add r3, sp, #2048 */
/* @0x1790dc str r2, [sp, #0x1c] */
/* @0x1790e0 vldr s23, [r3, #-888] */
/* @0x1790e4 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1790e8 bl 0x1689e0 <_Z25GR_D3D_Get_Texture_Repeatv> */
/* @0x1790ec str r0, [sp, #0x18] */
/* @0x1790f0 mov r0, #1 */
/* @0x1790f4 bl 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb> */
/* @0x1790f8 cmp r4, #2 */
/* @0x1790fc ble 0x179264 <_Z15GR_3D_Draw_Coneffffffiffbi+0x1d0> */
/* @0x179100 cmp r4, #128 */
/* @0x179104 ble 0x179328 <_Z15GR_3D_Draw_Coneffffffiffbi+0x294> */
/* @0x179108 mov r10, #1065353216 */
/* @0x17910c mov r4, #128 */
/* @0x179110 mov r0, #0 */
/* @0x179114 vldr s20, [pc, #548] */
/* @0x179118 add r2, sp, #548 */
/* @0x17911c add r11, sp, #32 */
/* @0x179120 str r2, [sp, #0x10] */
/* @0x179124 mov r5, #0 */
/* @0x179128 mov r7, r2 */
/* @0x17912c vldr s17, [pc, #528] */
/* @0x179130 mov r6, r11 */
/* @0x179134 b 0x179160 <_Z15GR_3D_Draw_Coneffffffiffbi+0xcc> */
/* @0x179138 vmov s13, r5 */
/* @0x17913c vcvt.f32.s32 s16, s13 */
/* @0x179140 vadd.f32 s16, s16, s16 */
/* @0x179144 vmul.f32 s16, s16, s17 */
/* @0x179148 vdiv.f32 s16, s16, s20 */
/* @0x17914c vmov r0, s16 */
/* @0x179150 bl 0xb658c <cosf@plt> */
/* @0x179154 mov r10, r0 */
/* @0x179158 vmov r0, s16 */
/* @0x17915c bl 0xb6580 <sinf@plt> */
/* @0x179160 add r5, r5, #1 */
/* @0x179164 str r10, [r6], #4 */
/* @0x179168 cmp r4, r5 */
/* @0x17916c str r0, [r7], #4 */
/* @0x179170 bge 0x179138 <_Z15GR_3D_Draw_Coneffffffiffbi+0xa4> */
/* @0x179174 vmov.f32 s15, #5.000000e-01 */
/* @0x179178 mov r0, #5 */
/* @0x17917c ldr r1, [sp, #0x14] */
/* @0x179180 add r7, sp, #548 */
/* @0x179184 mov r6, r11 */
/* @0x179188 mov r10, #0 */
/* @0x17918c vldr s16, [pc, #436] */
/* @0x179190 vadd.f32 s14, s25, s24 */
/* @0x179194 vadd.f32 s19, s21, s18 */
/* @0x179198 vsub.f32 s24, s25, s24 */
/* @0x17919c vsub.f32 s21, s21, s18 */
/* @0x1791a0 vmul.f32 s19, s19, s15 */
/* @0x1791a4 vmul.f32 s21, s21, s15 */
/* @0x1791a8 vmul.f32 s18, s14, s15 */
/* @0x1791ac vmul.f32 s24, s24, s15 */
/* @0x1791b0 bl 0x1769dc <_Z21GR_3D_Primitive_Beginii> */
/* @0x1791b4 vmov.f32 s25, #1.000000e+00 */
/* @0x1791b8 vmov s14, r10 */
/* @0x1791bc mov r5, #0 */
/* @0x1791c0 vmov r0, s19 */
/* @0x1791c4 mov r3, r5 */
/* @0x1791c8 vmov r1, s18 */
/* @0x1791cc mov r2, r9 */
/* @0x1791d0 vstr s16, [sp] */
/* @0x1791d4 vstr s25, [sp, #4] */
/* @0x1791d8 vstr s23, [sp, #12] */
/* @0x1791dc add r10, r10, #1 */
/* @0x1791e0 vcvt.f32.s32 s17, s14 */
/* @0x1791e4 vmul.f32 s17, s17, s22 */
/* @0x1791e8 vdiv.f32 s17, s17, s20 */
/* @0x1791ec vstr s17, [sp, #8] */
/* @0x1791f0 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x1791f4 vmov.f32 s13, s19 */
/* @0x1791f8 vstr s17, [sp, #8] */
/* @0x1791fc vstr s16, [sp, #4] */
/* @0x179200 vstr s16, [sp, #12] */
/* @0x179204 vldmia r6!, {s14} */
/* @0x179208 vmov r3, s14 */
/* @0x17920c vldmia r7!, {s15} */
/* @0x179210 vmla.f32 s13, s14, s21 */
/* @0x179214 vstr s15, [sp] */
/* @0x179218 mov r2, r8 */
/* @0x17921c vmov.f32 s14, s18 */
/* @0x179220 vmov r0, s13 */
/* @0x179224 vmla.f32 s14, s15, s24 */
/* @0x179228 vmov r1, s14 */
/* @0x17922c bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x179230 cmp r4, r10 */
/* @0x179234 bge 0x1791b8 <_Z15GR_3D_Draw_Coneffffffiffbi+0x124> */
/* @0x179238 bl 0x176ad0 <_Z19GR_3D_Primitive_Endv> */
/* @0x17923c ldr r2, [sp, #0x1c] */
/* @0x179240 cmp r2, #0 */
/* @0x179244 bne 0x179288 <_Z15GR_3D_Draw_Coneffffffiffbi+0x1f4> */
/* @0x179248 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x17924c ldr r0, [sp, #0x18] */
/* @0x179250 add sp, sp, #1056 */
/* @0x179254 add sp, sp, #12 */
/* @0x179258 vpop {d8, d9, d10, d11, d12} */
/* @0x17925c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x179260 b 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb> */
/* @0x179264 vmov.f32 s20, #3.000000e+00 */
/* @0x179268 mov r4, #3 */
/* @0x17926c mov r5, #0 */
/* @0x179270 mov r0, r5 */
/* @0x179274 bl 0xb658c <cosf@plt> */
/* @0x179278 mov r10, r0 */
/* @0x17927c mov r0, r5 */
/* @0x179280 bl 0xb6580 <sinf@plt> */
/* @0x179284 b 0x179118 <_Z15GR_3D_Draw_Coneffffffiffbi+0x84> */
/* @0x179288 ldr r1, [sp, #0x14] */
/* @0x17928c mov r0, #6 */
/* @0x179290 bl 0x1769dc <_Z21GR_3D_Primitive_Beginii> */
/* @0x179294 mov r7, #0 */
/* @0x179298 mov r3, r5 */
/* @0x17929c movt r7, #0xbf80 */
/* @0x1792a0 str r5, [sp] */
/* @0x1792a4 mov r2, r8 */
/* @0x1792a8 str r5, [sp, #0x8] */
/* @0x1792ac mov r6, r5 */
/* @0x1792b0 str r5, [sp, #0xc] */
/* @0x1792b4 mov r5, r7 */
/* @0x1792b8 vmov r0, s19 */
/* @0x1792bc vmov r1, s18 */
/* @0x1792c0 str r7, [sp, #0x4] */
/* @0x1792c4 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x1792c8 add r3, r4, #1 */
/* @0x1792cc add r2, sp, #548 */
/* @0x1792d0 lsl r3, r3, #2 */
/* @0x1792d4 add r11, r11, r3 */
/* @0x1792d8 add r10, r2, r3 */
/* @0x1792dc vmov.f32 s13, s19 */
/* @0x1792e0 str r6, [sp] */
/* @0x1792e4 str r5, [sp, #0x4] */
/* @0x1792e8 mov r3, #0 */
/* @0x1792ec str r6, [sp, #0x8] */
/* @0x1792f0 mov r2, r8 */
/* @0x1792f4 str r6, [sp, #0xc] */
/* @0x1792f8 vldmdb r10!, {s15} */
/* @0x1792fc vldmdb r11!, {s14} */
/* @0x179300 vmla.f32 s13, s21, s14 */
/* @0x179304 vmov.f32 s14, s18 */
/* @0x179308 vmov r0, s13 */
/* @0x17930c vmla.f32 s14, s24, s15 */
/* @0x179310 vmov r1, s14 */
/* @0x179314 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x179318 subs r4, r4, #1 */
/* @0x17931c bpl 0x1792dc <_Z15GR_3D_Draw_Coneffffffiffbi+0x248> */
/* @0x179320 bl 0x176ad0 <_Z19GR_3D_Primitive_Endv> */
/* @0x179324 b 0x179248 <_Z15GR_3D_Draw_Coneffffffiffbi+0x1b4> */
/* @0x179328 vmov s13, r4 */
/* @0x17932c vldr s15, [pc, #20] */
/* @0x179330 vcvt.f32.s32 s20, s13 */
/* @0x179334 vdiv.f32 s15, s15, s20 */
/* @0x179338 vmov r5, s15 */
/* @0x17933c b 0x179270 <_Z15GR_3D_Draw_Coneffffffiffbi+0x1dc> */
/* @0x179340 movwmi r0, #0x0 */
/* @0x179344 ldrdmi r0, r1, [r9], #-251 */
/* @0x179348 andeq r0, r0, r0 */

/* ── FUNC 0x17934c · GR_3D_Draw_Ellipsoid(float, float, float, float, float, float, int, float, float, int) · size=916 · insn=229 */
/* @0x17934c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x179350 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x179354 sub sp, sp, #1088 */
/* @0x179358 sub sp, sp, #12 */
/* @0x17935c vmov s16, r2 */
/* @0x179360 add r2, sp, #2048 */
/* @0x179364 vldr s17, [r2, #-844] */
/* @0x179368 add r2, sp, #2048 */
/* @0x17936c vmov s18, r1 */
/* @0x179370 add r1, sp, #2048 */
/* @0x179374 vldr s27, [r1, #-848] */
/* @0x179378 ldr r1, [r2, #-0x344] */
/* @0x17937c vmov s28, r3 */
/* @0x179380 ldr r3, [sp, #0x4b8] */
/* @0x179384 vmov s21, r0 */
/* @0x179388 ldr r6, [sp, #0x4c4] */
/* @0x17938c str r1, [sp, #0x1c] */
/* @0x179390 ldr r1, [r2, #-0x340] */
/* @0x179394 str r3, [sp, #0x38] */
/* @0x179398 str r1, [sp, #0x30] */
/* @0x17939c bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1793a0 bl 0x1689e0 <_Z25GR_D3D_Get_Texture_Repeatv> */
/* @0x1793a4 str r0, [sp, #0x3c] */
/* @0x1793a8 mov r0, #1 */
/* @0x1793ac bl 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb> */
/* @0x1793b0 cmp r6, #2 */
/* @0x1793b4 ble 0x179630 <_Z20GR_3D_Draw_Ellipsoidffffffiffi+0x2e4> */
/* @0x1793b8 cmp r6, #128 */
/* @0x1793bc ble 0x179694 <_Z20GR_3D_Draw_Ellipsoidffffffiffi+0x348> */
/* @0x1793c0 mov r5, #1065353216 */
/* @0x1793c4 mov r0, #0 */
/* @0x1793c8 vmov s20, r0 */
/* @0x1793cc mov r9, #64 */
/* @0x1793d0 vmov s26, r5 */
/* @0x1793d4 mov r6, #128 */
/* @0x1793d8 vldr s19, [pc, #740] */
/* @0x1793dc vldr s24, [pc, #740] */
/* @0x1793e0 vldr s25, [pc, #740] */
/* @0x1793e4 vldr s23, [pc, #740] */
/* @0x1793e8 add r1, sp, #580 */
/* @0x1793ec add r11, sp, #64 */
/* @0x1793f0 str r1, [sp, #0x34] */
/* @0x1793f4 mov r4, #0 */
/* @0x1793f8 mov r8, r1 */
/* @0x1793fc vldr s29, [pc, #720] */
/* @0x179400 mov r7, r11 */
/* @0x179404 b 0x179430 <_Z20GR_3D_Draw_Ellipsoidffffffiffi+0xe4> */
/* @0x179408 vmov s14, r4 */
/* @0x17940c vcvt.f32.s32 s22, s14 */
/* @0x179410 vadd.f32 s22, s22, s22 */
/* @0x179414 vmul.f32 s22, s22, s29 */
/* @0x179418 vdiv.f32 s22, s22, s23 */
/* @0x17941c vmov r0, s22 */
/* @0x179420 bl 0xb658c <cosf@plt> */
/* @0x179424 mov r5, r0 */
/* @0x179428 vmov r0, s22 */
/* @0x17942c bl 0xb6580 <sinf@plt> */
/* @0x179430 add r4, r4, #1 */
/* @0x179434 str r5, [r7], #4 */
/* @0x179438 cmp r6, r4 */
/* @0x17943c str r0, [r8], #4 */
/* @0x179440 bge 0x179408 <_Z20GR_3D_Draw_Ellipsoidffffffiffi+0xbc> */
/* @0x179444 vadd.f32 s22, s28, s21 */
/* @0x179448 vldr s15, [pc, #648] */
/* @0x17944c vstr s15, [sp, #32] */
/* @0x179450 mov r8, #1 */
/* @0x179454 vmov.f32 s15, #5.000000e-01 */
/* @0x179458 vsub.f32 s21, s28, s21 */
/* @0x17945c vmul.f32 s21, s21, s15 */
/* @0x179460 vadd.f32 s13, s27, s18 */
/* @0x179464 vstr s21, [sp, #36] */
/* @0x179468 vsub.f32 s18, s27, s18 */
/* @0x17946c vadd.f32 s14, s17, s16 */
/* @0x179470 vsub.f32 s16, s17, s16 */
/* @0x179474 vmul.f32 s18, s18, s15 */
/* @0x179478 vmul.f32 s16, s16, s15 */
/* @0x17947c vstr s18, [sp, #40] */
/* @0x179480 vmul.f32 s22, s22, s15 */
/* @0x179484 vstr s16, [sp, #44] */
/* @0x179488 vmul.f32 s21, s13, s15 */
/* @0x17948c vmul.f32 s27, s14, s15 */
/* @0x179490 mov r0, #5 */
/* @0x179494 ldr r1, [sp, #0x38] */
/* @0x179498 vldr s16, [sp, #32] */
/* @0x17949c bl 0x1769dc <_Z21GR_3D_Primitive_Beginii> */
/* @0x1794a0 vldr s14, [sp, #48] */
/* @0x1794a4 add r5, sp, #580 */
/* @0x1794a8 mov r10, r11 */
/* @0x1794ac mov r4, #0 */
/* @0x1794b0 vmov.f32 s15, s27 */
/* @0x1794b4 vmul.f32 s16, s16, s14 */
/* @0x1794b8 vldr s14, [sp, #44] */
/* @0x1794bc vmla.f32 s15, s14, s26 */
/* @0x1794c0 vldr s14, [sp, #36] */
/* @0x1794c4 vdiv.f32 s31, s16, s25 */
/* @0x1794c8 vmov r7, s15 */
/* @0x1794cc vmov s15, r8 */
/* @0x1794d0 vcvt.f32.s32 s15, s15 */
/* @0x1794d4 vmul.f32 s30, s14, s20 */
/* @0x1794d8 vldr s14, [sp, #48] */
/* @0x1794dc vstr s15, [sp, #32] */
/* @0x1794e0 vmul.f32 s29, s15, s14 */
/* @0x1794e4 vldr s14, [sp, #36] */
/* @0x1794e8 vldr s15, [sp, #40] */
/* @0x1794ec vmul.f32 s14, s14, s19 */
/* @0x1794f0 vmul.f32 s28, s15, s20 */
/* @0x1794f4 vstr s14, [sp, #16] */
/* @0x1794f8 vldr s14, [sp, #44] */
/* @0x1794fc vmul.f32 s15, s15, s19 */
/* @0x179500 vmul.f32 s14, s14, s24 */
/* @0x179504 vstr s15, [sp, #20] */
/* @0x179508 vstr s14, [sp, #24] */
/* @0x17950c vmov s15, r4 */
/* @0x179510 vldmia r5!, {s17} */
/* @0x179514 vldr s14, [sp, #28] */
/* @0x179518 vstr s26, [sp, #4] */
/* @0x17951c vcvt.f32.s32 s18, s15 */
/* @0x179520 vstr s31, [sp, #12] */
/* @0x179524 vldmia r10!, {s16} */
/* @0x179528 mov r2, r7 */
/* @0x17952c add r4, r4, #1 */
/* @0x179530 vmul.f32 s18, s18, s14 */
/* @0x179534 vmul.f32 s15, s17, s20 */
/* @0x179538 vdiv.f32 s18, s18, s23 */
/* @0x17953c vstr s15, [sp] */
/* @0x179540 vmov.f32 s15, s21 */
/* @0x179544 vstr s18, [sp, #8] */
/* @0x179548 vmla.f32 s15, s17, s28 */
/* @0x17954c vmov.f32 s14, s22 */
/* @0x179550 vmov r1, s15 */
/* @0x179554 vmla.f32 s14, s16, s30 */
/* @0x179558 vmul.f32 s15, s16, s20 */
/* @0x17955c vmov r0, s14 */
/* @0x179560 vmov r3, s15 */
/* @0x179564 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x179568 vdiv.f32 s14, s29, s25 */
/* @0x17956c vstr s18, [sp, #8] */
/* @0x179570 vstr s24, [sp, #4] */
/* @0x179574 vmul.f32 s15, s17, s19 */
/* @0x179578 vstr s14, [sp, #12] */
/* @0x17957c vmov.f32 s14, s22 */
/* @0x179580 vstr s15, [sp] */
/* @0x179584 vldr s15, [sp, #16] */
/* @0x179588 vmla.f32 s14, s16, s15 */
/* @0x17958c vldr s15, [sp, #20] */
/* @0x179590 vmov r0, s14 */
/* @0x179594 vmov.f32 s14, s21 */
/* @0x179598 vmla.f32 s14, s17, s15 */
/* @0x17959c vmul.f32 s16, s16, s19 */
/* @0x1795a0 vmov r1, s14 */
/* @0x1795a4 vldr s14, [sp, #24] */
/* @0x1795a8 vadd.f32 s14, s14, s27 */
/* @0x1795ac vmov r3, s16 */
/* @0x1795b0 vmov r2, s14 */
/* @0x1795b4 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x1795b8 cmp r6, r4 */
/* @0x1795bc bge 0x17950c <_Z20GR_3D_Draw_Ellipsoidffffffiffi+0x1c0> */
/* @0x1795c0 bl 0x176ad0 <_Z19GR_3D_Primitive_Endv> */
/* @0x1795c4 cmp r8, r9 */
/* @0x1795c8 bge 0x179614 <_Z20GR_3D_Draw_Ellipsoidffffffiffi+0x2c8> */
/* @0x1795cc add r8, r8, #1 */
/* @0x1795d0 movw r1, #0xfdb */
/* @0x1795d4 movt r1, #0x4049 */
/* @0x1795d8 vmov.f32 s26, s24 */
/* @0x1795dc vmov s15, r8 */
/* @0x1795e0 vmov s14, r1 */
/* @0x1795e4 vcvt.f32.s32 s16, s15 */
/* @0x1795e8 vmul.f32 s16, s16, s14 */
/* @0x1795ec vdiv.f32 s16, s16, s25 */
/* @0x1795f0 vmov r0, s16 */
/* @0x1795f4 bl 0xb658c <cosf@plt> */
/* @0x1795f8 vmov.f32 s20, s19 */
/* @0x1795fc mov r4, r0 */
/* @0x179600 vmov r0, s16 */
/* @0x179604 bl 0xb6580 <sinf@plt> */
/* @0x179608 vmov s24, r4 */
/* @0x17960c vmov s19, r0 */
/* @0x179610 b 0x179490 <_Z20GR_3D_Draw_Ellipsoidffffffiffi+0x144> */
/* @0x179614 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x179618 ldr r0, [sp, #0x3c] */
/* @0x17961c add sp, sp, #1088 */
/* @0x179620 add sp, sp, #12 */
/* @0x179624 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x179628 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17962c b 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb> */
/* @0x179630 vmov.f32 s25, #2.000000e+00 */
/* @0x179634 vldr s22, [pc, #156] */
/* @0x179638 mov r9, #2 */
/* @0x17963c mov r6, #3 */
/* @0x179640 vldr s19, [pc, #148] */
/* @0x179644 vmov.f32 s23, #3.000000e+00 */
/* @0x179648 vmov.f32 s20, s22 */
/* @0x17964c vmov r0, s20 */
/* @0x179650 bl 0xb658c <cosf@plt> */
/* @0x179654 vmov s26, r0 */
/* @0x179658 vmov r0, s20 */
/* @0x17965c bl 0xb6580 <sinf@plt> */
/* @0x179660 vmov s20, r0 */
/* @0x179664 vmov r0, s19 */
/* @0x179668 bl 0xb658c <cosf@plt> */
/* @0x17966c vmov s24, r0 */
/* @0x179670 vmov r0, s19 */
/* @0x179674 bl 0xb6580 <sinf@plt> */
/* @0x179678 vmov s19, r0 */
/* @0x17967c vmov r0, s22 */
/* @0x179680 bl 0xb658c <cosf@plt> */
/* @0x179684 mov r5, r0 */
/* @0x179688 vmov r0, s22 */
/* @0x17968c bl 0xb6580 <sinf@plt> */
/* @0x179690 b 0x1793e8 <_Z20GR_3D_Draw_Ellipsoidffffffiffi+0x9c> */
/* @0x179694 add r9, r6, #1 */
/* @0x179698 vmov s15, r6 */
/* @0x17969c vldr s20, [pc, #52] */
/* @0x1796a0 vldr s19, [pc, #44] */
/* @0x1796a4 asr r9, r9, #1 */
/* @0x1796a8 vcvt.f32.s32 s23, s15 */
/* @0x1796ac vmov s14, r9 */
/* @0x1796b0 vcvt.f32.s32 s25, s14 */
/* @0x1796b4 vdiv.f32 s22, s20, s23 */
/* @0x1796b8 vdiv.f32 s19, s19, s25 */
/* @0x1796bc vdiv.f32 s20, s20, s25 */
/* @0x1796c0 b 0x17964c <_Z20GR_3D_Draw_Ellipsoidffffffiffi+0x300> */
/* @0x1796c4 vstrlo d31, [r8, #-192] */
/* @0x1796c8 svclo #0x7fb10f */
/* @0x1796cc addmi r0, r0, #0 */
/* @0x1796d0 movwmi r0, #0x0 */
/* @0x1796d4 ldrdmi r0, r1, [r9], #-251 */
/* @0x1796d8 andeq r0, r0, r0 */
/* @0x1796dc svclo #0xc90fdb */

/* ── FUNC 0x1796e0 · GR_3D_Draw_Wall(float, float, float, float, float, float, int, float, float) · size=340 · insn=85 */
/* @0x1796e0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1796e4 vpush {d8, d9, d10} */
/* @0x1796e8 sub sp, sp, #16 */
/* @0x1796ec vldr s20, [sp, #72] */
/* @0x1796f0 vmov s18, r1 */
/* @0x1796f4 mov r6, r2 */
/* @0x1796f8 vmov s21, r3 */
/* @0x1796fc ldr r5, [sp, #0x4c] */
/* @0x179700 vmov s19, r0 */
/* @0x179704 ldr r10, [sp, #0x50] */
/* @0x179708 ldr r8, [sp, #0x54] */
/* @0x17970c ldr r7, [sp, #0x58] */
/* @0x179710 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x179714 bl 0x1689e0 <_Z25GR_D3D_Get_Texture_Repeatv> */
/* @0x179718 mov r9, r0 */
/* @0x17971c mov r0, #1 */
/* @0x179720 bl 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb> */
/* @0x179724 vsub.f32 s16, s20, s18 */
/* @0x179728 vmul.f32 s14, s16, s16 */
/* @0x17972c vsub.f32 s17, s21, s19 */
/* @0x179730 vmla.f32 s14, s17, s17 */
/* @0x179734 vsqrt.f32 s15, s14 */
/* @0x179738 vcmp.f32 s15, s15 */
/* @0x17973c vmrs APSR_nzcv, fpscr */
/* @0x179740 bne 0x179824 <_Z15GR_3D_Draw_Wallffffffiff+0x144> */
/* @0x179744 vcmp.f32 s15, #0 */
/* @0x179748 mov r4, #0 */
/* @0x17974c vmrs APSR_nzcv, fpscr */
/* @0x179750 bne 0x179760 <_Z15GR_3D_Draw_Wallffffffiff+0x80> */
/* @0x179754 add sp, sp, #16 */
/* @0x179758 vpop {d8, d9, d10} */
/* @0x17975c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x179760 vneg.f32 s17, s17 */
/* @0x179764 mov r1, r10 */
/* @0x179768 mov r0, #6 */
/* @0x17976c vdiv.f32 s17, s17, s15 */
/* @0x179770 vdiv.f32 s16, s16, s15 */
/* @0x179774 bl 0x1769dc <_Z21GR_3D_Primitive_Beginii> */
/* @0x179778 vmov r0, s19 */
/* @0x17977c mov r2, r6 */
/* @0x179780 vmov r1, s18 */
/* @0x179784 vstr s17, [sp] */
/* @0x179788 str r4, [sp, #0x4] */
/* @0x17978c str r4, [sp, #0x8] */
/* @0x179790 str r4, [sp, #0xc] */
/* @0x179794 vmov r3, s16 */
/* @0x179798 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x17979c mov r2, r6 */
/* @0x1797a0 vmov r3, s16 */
/* @0x1797a4 vstr s17, [sp] */
/* @0x1797a8 vmov r0, s21 */
/* @0x1797ac vmov r1, s20 */
/* @0x1797b0 str r4, [sp, #0x4] */
/* @0x1797b4 str r8, [sp, #0x8] */
/* @0x1797b8 str r4, [sp, #0xc] */
/* @0x1797bc bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x1797c0 vmov r3, s16 */
/* @0x1797c4 vmov r0, s21 */
/* @0x1797c8 mov r2, r5 */
/* @0x1797cc vmov r1, s20 */
/* @0x1797d0 vstr s17, [sp] */
/* @0x1797d4 str r4, [sp, #0x4] */
/* @0x1797d8 str r8, [sp, #0x8] */
/* @0x1797dc str r7, [sp, #0xc] */
/* @0x1797e0 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x1797e4 vmov r0, s19 */
/* @0x1797e8 mov r2, r5 */
/* @0x1797ec vmov r3, s16 */
/* @0x1797f0 vmov r1, s18 */
/* @0x1797f4 vstr s17, [sp] */
/* @0x1797f8 str r4, [sp, #0x4] */
/* @0x1797fc str r4, [sp, #0x8] */
/* @0x179800 str r7, [sp, #0xc] */
/* @0x179804 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x179808 bl 0x176ad0 <_Z19GR_3D_Primitive_Endv> */
/* @0x17980c bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x179810 mov r0, r9 */
/* @0x179814 add sp, sp, #16 */
/* @0x179818 vpop {d8, d9, d10} */
/* @0x17981c pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x179820 b 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb> */
/* @0x179824 vmov r0, s14 */
/* @0x179828 bl 0xb6700 <sqrtf@plt> */
/* @0x17982c vmov s15, r0 */
/* @0x179830 b 0x179744 <_Z15GR_3D_Draw_Wallffffffiff+0x64> */

/* ── FUNC 0x179834 · GR_3D_Draw_Floor(float, float, float, float, float, float, int, float, float) · size=340 · insn=85 */
/* @0x179834 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x179838 vpush {d8, d9, d10} */
/* @0x17983c sub sp, sp, #16 */
/* @0x179840 vldr s18, [sp, #76] */
/* @0x179844 vmov s20, r2 */
/* @0x179848 mov r5, r1 */
/* @0x17984c vmov s19, r3 */
/* @0x179850 ldr r6, [sp, #0x48] */
/* @0x179854 vmov s21, r0 */
/* @0x179858 ldr r10, [sp, #0x50] */
/* @0x17985c ldr r7, [sp, #0x54] */
/* @0x179860 ldr r8, [sp, #0x58] */
/* @0x179864 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x179868 bl 0x1689e0 <_Z25GR_D3D_Get_Texture_Repeatv> */
/* @0x17986c mov r9, r0 */
/* @0x179870 mov r0, #1 */
/* @0x179874 bl 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb> */
/* @0x179878 vsub.f32 s17, s18, s20 */
/* @0x17987c vmul.f32 s14, s17, s17 */
/* @0x179880 vsub.f32 s16, s19, s21 */
/* @0x179884 vmla.f32 s14, s16, s16 */
/* @0x179888 vsqrt.f32 s15, s14 */
/* @0x17988c vcmp.f32 s15, s15 */
/* @0x179890 vmrs APSR_nzcv, fpscr */
/* @0x179894 bne 0x179978 <_Z16GR_3D_Draw_Floorffffffiff+0x144> */
/* @0x179898 vcmp.f32 s15, #0 */
/* @0x17989c mov r4, #0 */
/* @0x1798a0 vmrs APSR_nzcv, fpscr */
/* @0x1798a4 bne 0x1798b4 <_Z16GR_3D_Draw_Floorffffffiff+0x80> */
/* @0x1798a8 add sp, sp, #16 */
/* @0x1798ac vpop {d8, d9, d10} */
/* @0x1798b0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1798b4 vneg.f32 s17, s17 */
/* @0x1798b8 mov r1, r10 */
/* @0x1798bc mov r0, #6 */
/* @0x1798c0 vdiv.f32 s17, s17, s15 */
/* @0x1798c4 vdiv.f32 s16, s16, s15 */
/* @0x1798c8 bl 0x1769dc <_Z21GR_3D_Primitive_Beginii> */
/* @0x1798cc vmov r3, s17 */
/* @0x1798d0 mov r1, r5 */
/* @0x1798d4 vmov r0, s21 */
/* @0x1798d8 vmov r2, s20 */
/* @0x1798dc str r4, [sp] */
/* @0x1798e0 str r4, [sp, #0x8] */
/* @0x1798e4 str r4, [sp, #0xc] */
/* @0x1798e8 vstr s16, [sp, #4] */
/* @0x1798ec bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x1798f0 vmov r3, s17 */
/* @0x1798f4 vmov r0, s21 */
/* @0x1798f8 mov r1, r6 */
/* @0x1798fc vmov r2, s20 */
/* @0x179900 vstr s16, [sp, #4] */
/* @0x179904 str r4, [sp] */
/* @0x179908 str r4, [sp, #0x8] */
/* @0x17990c str r8, [sp, #0xc] */
/* @0x179910 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x179914 mov r1, r6 */
/* @0x179918 vmov r3, s17 */
/* @0x17991c vstr s16, [sp, #4] */
/* @0x179920 vmov r0, s19 */
/* @0x179924 vmov r2, s18 */
/* @0x179928 str r4, [sp] */
/* @0x17992c str r7, [sp, #0x8] */
/* @0x179930 str r8, [sp, #0xc] */
/* @0x179934 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x179938 vmov r0, s19 */
/* @0x17993c mov r1, r5 */
/* @0x179940 vmov r3, s17 */
/* @0x179944 vmov r2, s18 */
/* @0x179948 vstr s16, [sp, #4] */
/* @0x17994c str r4, [sp] */
/* @0x179950 str r7, [sp, #0x8] */
/* @0x179954 str r4, [sp, #0xc] */
/* @0x179958 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x17995c bl 0x176ad0 <_Z19GR_3D_Primitive_Endv> */
/* @0x179960 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x179964 mov r0, r9 */
/* @0x179968 add sp, sp, #16 */
/* @0x17996c vpop {d8, d9, d10} */
/* @0x179970 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x179974 b 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb> */
/* @0x179978 vmov r0, s14 */
/* @0x17997c bl 0xb6700 <sqrtf@plt> */
/* @0x179980 vmov s15, r0 */
/* @0x179984 b 0x179898 <_Z16GR_3D_Draw_Floorffffffiff+0x64> */

/* ── FUNC 0x179988 · GR_Window_Get_Region_Width() · size=20 · insn=5 */
/* @0x179988 ldr r3, [pc, #0x8] */
/* @0x17998c ldr r3, [pc, r3] */
/* @0x179990 ldr r0, [r3] */
/* @0x179994 bx lr */
/* @0x179998 eoreq r6, r7, r12, asr #18 */

/* ── FUNC 0x17999c · GR_Window_Get_Region_Height() · size=20 · insn=5 */
/* @0x17999c ldr r3, [pc, #0x8] */
/* @0x1799a0 ldr r3, [pc, r3] */
/* @0x1799a4 ldr r0, [r3] */
/* @0x1799a8 bx lr */
/* @0x1799ac eoreq r6, r7, r12, lsr r9 */

/* ── FUNC 0x1799b0 · GR_Window_Set_Min_Width(int) · size=20 · insn=5 */
/* @0x1799b0 ldr r3, [pc, #0x8] */
/* @0x1799b4 ldr r3, [pc, r3] */
/* @0x1799b8 str r0, [r3] */
/* @0x1799bc b 0x17af14 <_Z24GR_Window_Set_Min_WidthMi> */
/* @0x1799c0 eoreq r6, r7, r12, lsr #18 */

/* ── FUNC 0x1799c4 · GR_Window_Set_Max_Width(int) · size=20 · insn=5 */
/* @0x1799c4 ldr r3, [pc, #0x8] */
/* @0x1799c8 ldr r3, [pc, r3] */
/* @0x1799cc str r0, [r3] */
/* @0x1799d0 b 0x17af18 <_Z24GR_Window_Set_Max_WidthMi> */
/* @0x1799d4 eoreq r6, r7, r12, lsl r9 */

/* ── FUNC 0x1799d8 · GR_Window_Set_Min_Height(int) · size=20 · insn=5 */
/* @0x1799d8 ldr r3, [pc, #0x8] */
/* @0x1799dc ldr r3, [pc, r3] */
/* @0x1799e0 str r0, [r3] */
/* @0x1799e4 b 0x17af1c <_Z25GR_Window_Set_Min_HeightMi> */
/* @0x1799e8 eoreq r6, r7, r12, lsl #18 */

/* ── FUNC 0x1799ec · GR_Window_Set_Max_Height(int) · size=20 · insn=5 */
/* @0x1799ec ldr r3, [pc, #0x8] */
/* @0x1799f0 ldr r3, [pc, r3] */
/* @0x1799f4 str r0, [r3] */
/* @0x1799f8 b 0x17af20 <_Z25GR_Window_Set_Max_HeightMi> */
/* @0x1799fc .word 0x002768fc */

/* ── FUNC 0x179a00 · Get_FullScreenOffset(int&, int&, int&, int&) · size=328 · insn=82 */
/* @0x179a00 ldr r12, [pc, #0x124] */
/* @0x179a04 push {r4, r5, r6} */
/* @0x179a08 add r12, pc, r12 */
/* @0x179a0c ldr r5, [pc, #0x11c] */
/* @0x179a10 mov r4, #0 */
/* @0x179a14 str r4, [r0] */
/* @0x179a18 str r4, [r1] */
/* @0x179a1c ldr r4, [r12, r5] */
/* @0x179a20 ldrb r4, [r4] */
/* @0x179a24 cmp r4, #0 */
/* @0x179a28 beq 0x179a40 <_Z20Get_FullScreenOffsetRiS_S_S_+0x40> */
/* @0x179a2c ldr r4, [pc, #0x100] */
/* @0x179a30 ldr r4, [r12, r4] */
/* @0x179a34 ldrb r4, [r4] */
/* @0x179a38 cmp r4, #0 */
/* @0x179a3c bne 0x179a68 <_Z20Get_FullScreenOffsetRiS_S_S_+0x68> */
/* @0x179a40 ldr r0, [pc, #0xf0] */
/* @0x179a44 ldr r1, [pc, #0xf0] */
/* @0x179a48 pop {r4, r5, r6} */
/* @0x179a4c ldr r0, [r12, r0] */
/* @0x179a50 ldr r0, [r0] */
/* @0x179a54 str r0, [r2] */
/* @0x179a58 ldr r2, [r12, r1] */
/* @0x179a5c ldr r2, [r2] */
/* @0x179a60 str r2, [r3] */
/* @0x179a64 bx lr */
/* @0x179a68 ldr r6, [pc, #0xd0] */
/* @0x179a6c ldr r5, [pc, #0xd0] */
/* @0x179a70 ldr r4, [pc, #0xc0] */
/* @0x179a74 ldr r6, [r12, r6] */
/* @0x179a78 vldr s12, [r6] */
/* @0x179a7c ldr r5, [r12, r5] */
/* @0x179a80 vcvt.f32.s32 s12, s12 */
/* @0x179a84 vldr s11, [r5] */
/* @0x179a88 ldr r4, [r12, r4] */
/* @0x179a8c vldr s9, [r4] */
/* @0x179a90 ldr r5, [pc, #0xa4] */
/* @0x179a94 ldr r12, [r12, r5] */
/* @0x179a98 vcvt.f32.s32 s11, s11 */
/* @0x179a9c vdiv.f32 s13, s12, s11 */
/* @0x179aa0 vcvt.f32.s32 s15, s9 */
/* @0x179aa4 vldr s9, [r12] */
/* @0x179aa8 vdiv.f32 s10, s15, s13 */
/* @0x179aac vcvt.f32.s32 s14, s9 */
/* @0x179ab0 vcmpe.f32 s10, s14 */
/* @0x179ab4 vmrs APSR_nzcv, fpscr */
/* @0x179ab8 bmi 0x179afc <_Z20Get_FullScreenOffsetRiS_S_S_+0xfc> */
/* @0x179abc vmul.f32 s14, s13, s14 */
/* @0x179ac0 vmov.f32 s13, #5.000000e-01 */
/* @0x179ac4 vsub.f32 s15, s15, s14 */
/* @0x179ac8 vmul.f32 s15, s15, s13 */
/* @0x179acc vcvt.s32.f32 s15, s15 */
/* @0x179ad0 vcvt.f32.s32 s13, s15 */
/* @0x179ad4 vstr s15, [r0] */
/* @0x179ad8 vldr s15, [r12] */
/* @0x179adc vadd.f32 s14, s14, s13 */
/* @0x179ae0 vcvt.f32.s32 s15, s15 */
/* @0x179ae4 pop {r4, r5, r6} */
/* @0x179ae8 vcvt.s32.f32 s14, s14 */
/* @0x179aec vcvt.s32.f32 s15, s15 */
/* @0x179af0 vstr s14, [r2] */
/* @0x179af4 vstr s15, [r3] */
/* @0x179af8 bx lr */
/* @0x179afc vdiv.f32 s12, s11, s12 */
/* @0x179b00 vmul.f32 s15, s15, s12 */
/* @0x179b04 vmov.f32 s13, #5.000000e-01 */
/* @0x179b08 vsub.f32 s14, s14, s15 */
/* @0x179b0c vmul.f32 s14, s14, s13 */
/* @0x179b10 vcvt.s32.f32 s14, s14 */
/* @0x179b14 vcvt.f32.s32 s12, s14 */
/* @0x179b18 vstr s14, [r1] */
/* @0x179b1c vldr s14, [r4] */
/* @0x179b20 vadd.f32 s15, s15, s12 */
/* @0x179b24 vcvt.f32.s32 s14, s14 */
/* @0x179b28 b 0x179ae4 <_Z20Get_FullScreenOffsetRiS_S_S_+0xe4> */
/* @0x179b2c eoreq r8, r7, r8, asr #4 */
/* @0x179b30 .word 0xffffe6a0 */
/* @0x179b34 .word 0xffffe6a4 */
/* @0x179b38 .word 0xffffe24c */
/* @0x179b3c .word 0xffffe250 */
/* @0x179b40 .word 0xffffdf38 */
/* @0x179b44 .word 0xffffdf40 */

/* ── FUNC 0x179b48 · GR_Window_GUI_Convert(int, int, int&, int&) · size=180 · insn=45 */
/* @0x179b48 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x179b4c mov r7, r1 */
/* @0x179b50 ldr r4, [pc, #0x88] */
/* @0x179b54 mov r9, r3 */
/* @0x179b58 ldr r1, [pc, #0x84] */
/* @0x179b5c mov r8, r2 */
/* @0x179b60 add r4, pc, r4 */
/* @0x179b64 ldr r12, [pc, #0x7c] */
/* @0x179b68 ldr r3, [r4, r1] */
/* @0x179b6c ldr r2, [r4, r12] */
/* @0x179b70 ldr r5, [r3] */
/* @0x179b74 ldr r3, [pc, #0x70] */
/* @0x179b78 ldr r12, [r2] */
/* @0x179b7c ldr r3, [r4, r3] */
/* @0x179b80 cmp r12, #0 */
/* @0x179b84 ldrlt r12, [r3] */
/* @0x179b88 ldrge r1, [r3] */
/* @0x179b8c ldr r3, [pc, #0x5c] */
/* @0x179b90 movlt r1, r12 */
/* @0x179b94 cmp r5, #0 */
/* @0x179b98 ldr r6, [r4, r3] */
/* @0x179b9c ldr r3, [pc, #0x50] */
/* @0x179ba0 ldrlt r5, [r6] */
/* @0x179ba4 ldr r3, [r4, r3] */
/* @0x179ba8 ldr r3, [r3] */
/* @0x179bac rsb r0, r3, r0 */
/* @0x179bb0 mul r0, r12, r0 */
/* @0x179bb4 bl 0x318d10 <__divsi3> */
/* @0x179bb8 ldr r3, [pc, #0x38] */
/* @0x179bbc str r0, [r8] */
/* @0x179bc0 ldr r3, [r4, r3] */
/* @0x179bc4 ldr r1, [r6] */
/* @0x179bc8 ldr r3, [r3] */
/* @0x179bcc rsb r0, r3, r7 */
/* @0x179bd0 mul r0, r5, r0 */
/* @0x179bd4 bl 0x318d10 <__divsi3> */
/* @0x179bd8 str r0, [r9] */
/* @0x179bdc pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x179be0 .word 0x002780f0 */
/* @0x179be4 .word 0xffffdf24 */
/* @0x179be8 .word 0xffffdf18 */
/* @0x179bec .word 0xffffe24c */
/* @0x179bf0 .word 0xffffe250 */
/* @0x179bf4 .word 0xffffe6a8 */
/* @0x179bf8 .word 0xffffe6ac */

/* ── FUNC 0x179bfc · GR_Window_View_Define(int, float, float, float, float, float, float, float, float, float, int, int) · size=176 · insn=44 */
/* @0x179bfc cmp r0, #31 */
/* @0x179c00 push {r4, r5, r6} */
/* @0x179c04 bhi 0x179c84 <_Z21GR_Window_View_Defineifffffffffii+0x88> */
/* @0x179c08 ldr r4, [pc, #0x94] */
/* @0x179c0c lsl r12, r0, #1 */
/* @0x179c10 add r5, r12, r0 */
/* @0x179c14 ldr r4, [pc, r4] */
/* @0x179c18 ldrb r5, [r4, r5, lsl #4] */
/* @0x179c1c cmp r5, #0 */
/* @0x179c20 beq 0x179c8c <_Z21GR_Window_View_Defineifffffffffii+0x90> */
/* @0x179c24 add r0, r12, r0 */
/* @0x179c28 mov r5, #1 */
/* @0x179c2c vldr s15, [sp, #12] */
/* @0x179c30 lsl r0, r0, #4 */
/* @0x179c34 add r12, r4, r0 */
/* @0x179c38 strb r5, [r4, r0] */
/* @0x179c3c vstr s15, [r12, #32] */
/* @0x179c40 str r3, [r12, #0x1c] */
/* @0x179c44 vldr s15, [sp, #16] */
/* @0x179c48 ldr r3, [sp, #0x24] */
/* @0x179c4c vstr s15, [r12, #4] */
/* @0x179c50 str r1, [r12, #0x14] */
/* @0x179c54 vldr s15, [sp, #20] */
/* @0x179c58 str r2, [r12, #0x18] */
/* @0x179c5c vstr s15, [r12, #8] */
/* @0x179c60 str r3, [r12, #0x28] */
/* @0x179c64 vldr s15, [sp, #24] */
/* @0x179c68 ldr r3, [sp, #0x28] */
/* @0x179c6c vstr s15, [r12, #12] */
/* @0x179c70 vldr s15, [sp, #28] */
/* @0x179c74 vstr s15, [r12, #16] */
/* @0x179c78 vldr s15, [sp, #32] */
/* @0x179c7c vstr s15, [r12, #36] */
/* @0x179c80 str r3, [r12, #0x2c] */
/* @0x179c84 pop {r4, r5, r6} */
/* @0x179c88 bx lr */
/* @0x179c8c ldr r5, [pc, #0x14] */
/* @0x179c90 ldr r5, [pc, r5] */
/* @0x179c94 ldr r6, [r5] */
/* @0x179c98 add r6, r6, #1 */
/* @0x179c9c str r6, [r5] */
/* @0x179ca0 b 0x179c24 <_Z21GR_Window_View_Defineifffffffffii+0x28> */
/* @0x179ca4 eoreq r6, r7, r12, ror #13 */
/* @0x179ca8 eoreq r6, r7, r4, ror r6 */

/* ── FUNC 0x179cac · GR_Window_View_UnDefine(int) · size=84 · insn=21 */
/* @0x179cac cmp r0, #31 */
/* @0x179cb0 bxhi lr */
/* @0x179cb4 ldr r3, [pc, #0x3c] */
/* @0x179cb8 lsl r2, r0, #1 */
/* @0x179cbc add r1, r2, r0 */
/* @0x179cc0 ldr r3, [pc, r3] */
/* @0x179cc4 ldrb r1, [r3, r1, lsl #4] */
/* @0x179cc8 cmp r1, #0 */
/* @0x179ccc beq 0x179ce4 <_Z23GR_Window_View_UnDefinei+0x38> */
/* @0x179cd0 ldr r1, [pc, #0x24] */
/* @0x179cd4 ldr r1, [pc, r1] */
/* @0x179cd8 ldr r12, [r1] */
/* @0x179cdc sub r12, r12, #1 */
/* @0x179ce0 str r12, [r1] */
/* @0x179ce4 add r2, r2, r0 */
/* @0x179ce8 mov r1, #0 */
/* @0x179cec lsl r2, r2, #4 */
/* @0x179cf0 strb r1, [r3, r2] */
/* @0x179cf4 bx lr */
/* @0x179cf8 eoreq r6, r7, r0, asr #12 */
/* @0x179cfc eoreq r6, r7, r0, lsr r6 */

/* ── FUNC 0x179d00 · GR_View_Undefine_All() · size=60 · insn=15 */
/* @0x179d00 ldr r2, [pc, #0x2c] */
/* @0x179d04 mov r3, #0 */
/* @0x179d08 mov r0, r3 */
/* @0x179d0c ldr r2, [pc, r2] */
/* @0x179d10 strb r0, [r2, r3] */
/* @0x179d14 add r3, r3, #48 */
/* @0x179d18 cmp r3, #1536 */
/* @0x179d1c mov r1, #0 */
/* @0x179d20 bne 0x179d10 <_Z20GR_View_Undefine_Allv+0x10> */
/* @0x179d24 ldr r3, [pc, #0xc] */
/* @0x179d28 ldr r3, [pc, r3] */
/* @0x179d2c str r1, [r3] */
/* @0x179d30 bx lr */
/* @0x179d34 .word 0x002765f4 */
/* @0x179d38 .word 0x002765dc */

/* ── FUNC 0x179d3c · INITIALIZE_Graphics_Window() · size=40 · insn=10 */
/* @0x179d3c ldr r2, [pc, #0x18] */
/* @0x179d40 mov r1, #1 */
/* @0x179d44 ldr r3, [pc, #0x14] */
/* @0x179d48 ldr r2, [pc, r2] */
/* @0x179d4c ldr r3, [pc, r3] */
/* @0x179d50 strb r1, [r2] */
/* @0x179d54 strb r1, [r3] */
/* @0x179d58 b 0x179d00 <_Z20GR_View_Undefine_Allv> */
/* @0x179d5c eoreq r5, r7, r0, lsl #28 */
/* @0x179d60 eoreq r6, r7, r8, lsr #11 */

/* ── FUNC 0x179d64 · GR_Window_View_Convert(int, int, int, int&, int&) · size=940 · insn=235 */
/* @0x179d64 push {r4, r5, r6, r7, r8, lr} */
/* @0x179d68 vpush {d8, d9, d10, d11, d12, d13} */
/* @0x179d6c cmp r0, #31 */
/* @0x179d70 ldr r4, [pc, #0x370] */
/* @0x179d74 sub sp, sp, #88 */
/* @0x179d78 mov r7, r1 */
/* @0x179d7c mov r6, r2 */
/* @0x179d80 mov r5, r3 */
/* @0x179d84 add r4, pc, r4 */
/* @0x179d88 bhi 0x179da8 <_Z22GR_Window_View_ConvertiiiRiS_+0x44> */
/* @0x179d8c ldr r3, [pc, #0x358] */
/* @0x179d90 add r0, r0, r0, lsl #1 */
/* @0x179d94 lsl r0, r0, #4 */
/* @0x179d98 ldr r12, [r4, r3] */
/* @0x179d9c ldrb r3, [r12, r0] */
/* @0x179da0 cmp r3, #0 */
/* @0x179da4 bne 0x179db4 <_Z22GR_Window_View_ConvertiiiRiS_+0x50> */
/* @0x179da8 add sp, sp, #88 */
/* @0x179dac vpop {d8, d9, d10, d11, d12, d13} */
/* @0x179db0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x179db4 add r8, r0, r12 */
/* @0x179db8 vldr s15, [r8, #28] */
/* @0x179dbc vcmp.f32 s15, #0 */
/* @0x179dc0 vmrs APSR_nzcv, fpscr */
/* @0x179dc4 beq 0x179da8 <_Z22GR_Window_View_ConvertiiiRiS_+0x44> */
/* @0x179dc8 vldr s15, [r8, #32] */
/* @0x179dcc vcmp.f32 s15, #0 */
/* @0x179dd0 vmrs APSR_nzcv, fpscr */
/* @0x179dd4 beq 0x179da8 <_Z22GR_Window_View_ConvertiiiRiS_+0x44> */
/* @0x179dd8 add r0, sp, #8 */
/* @0x179ddc add r1, sp, #12 */
/* @0x179de0 add r2, sp, #16 */
/* @0x179de4 add r3, sp, #20 */
/* @0x179de8 bl 0x179a00 <_Z20Get_FullScreenOffsetRiS_S_S_> */
/* @0x179dec ldr r2, [pc, #0x2fc] */
/* @0x179df0 ldr r3, [sp, #0x8] */
/* @0x179df4 vldr s15, [r8, #20] */
/* @0x179df8 ldr r0, [pc, #0x2f4] */
/* @0x179dfc vcvt.s32.f32 s15, s15 */
/* @0x179e00 ldr r2, [r4, r2] */
/* @0x179e04 rsb r7, r3, r7 */
/* @0x179e08 ldr r12, [r4, r0] */
/* @0x179e0c vldr s7, [r12] */
/* @0x179e10 ldr r2, [r2] */
/* @0x179e14 vmov s11, r7 */
/* @0x179e18 ldr r0, [pc, #0x2d8] */
/* @0x179e1c sub r2, r2, r3, lsl #1 */
/* @0x179e20 vcvt.f32.s32 s7, s7 */
/* @0x179e24 ldr r0, [r4, r0] */
/* @0x179e28 vldr s8, [r0] */
/* @0x179e2c vmov s10, r2 */
/* @0x179e30 ldr r0, [pc, #0x2c4] */
/* @0x179e34 ldr r3, [sp, #0xc] */
/* @0x179e38 ldr r2, [pc, #0x2c0] */
/* @0x179e3c ldr r12, [r4, r0] */
/* @0x179e40 rsb r6, r3, r6 */
/* @0x179e44 ldr r0, [pc, #0x2b8] */
/* @0x179e48 vcvt.f32.s32 s10, s10 */
/* @0x179e4c ldr r2, [r4, r2] */
/* @0x179e50 ldr r12, [r12] */
/* @0x179e54 vldr s12, [r2] */
/* @0x179e58 vmov r1, s15 */
/* @0x179e5c vldr s15, [r8, #24] */
/* @0x179e60 ldr r2, [pc, #0x2a0] */
/* @0x179e64 sub r3, r12, r3, lsl #1 */
/* @0x179e68 vdiv.f32 s10, s7, s10 */
/* @0x179e6c vdiv.f32 s10, s10, s8 */
/* @0x179e70 vmov s8, r3 */
/* @0x179e74 vcvt.f32.s32 s12, s12 */
/* @0x179e78 vcvt.f32.s32 s9, s8 */
/* @0x179e7c vdiv.f32 s12, s12, s9 */
/* @0x179e80 vcvt.f32.s32 s11, s11 */
/* @0x179e84 vmul.f32 s11, s11, s10 */
/* @0x179e88 vmov s10, r6 */
/* @0x179e8c vcvt.s32.f32 s11, s11 */
/* @0x179e90 vstr s11, [r5] */
/* @0x179e94 ldr r3, [r4, r0] */
/* @0x179e98 vldr s14, [r3] */
/* @0x179e9c vdiv.f32 s14, s12, s14 */
/* @0x179ea0 ldr r0, [sp, #0xa0] */
/* @0x179ea4 vcvt.f32.s32 s13, s10 */
/* @0x179ea8 vcvt.s32.f32 s15, s15 */
/* @0x179eac vmul.f32 s14, s13, s14 */
/* @0x179eb0 vmov r3, s15 */
/* @0x179eb4 vcvt.s32.f32 s14, s14 */
/* @0x179eb8 vstr s14, [r0] */
/* @0x179ebc ldr r0, [r5] */
/* @0x179ec0 rsb r1, r1, r0 */
/* @0x179ec4 ldr r0, [sp, #0xa0] */
/* @0x179ec8 str r1, [r5] */
/* @0x179ecc ldr r1, [r0] */
/* @0x179ed0 rsb r3, r3, r1 */
/* @0x179ed4 str r3, [r0] */
/* @0x179ed8 ldr r2, [r4, r2] */
/* @0x179edc ldrb r2, [r2] */
/* @0x179ee0 cmp r2, #0 */
/* @0x179ee4 bne 0x17a034 <_Z22GR_Window_View_ConvertiiiRiS_+0x2d0> */
/* @0x179ee8 vmov s8, r3 */
/* @0x179eec vldr s15, [r8, #12] */
/* @0x179ef0 vldr s17, [r8, #16] */
/* @0x179ef4 vldr s14, [r8, #36] */
/* @0x179ef8 vcvt.f32.s32 s12, s8 */
/* @0x179efc vldr s8, [r5] */
/* @0x179f00 vldr s9, [pc, #468] */
/* @0x179f04 vldr s11, [r8, #28] */
/* @0x179f08 vldr s13, [r8, #32] */
/* @0x179f0c vcvt.f32.s32 s10, s8 */
/* @0x179f10 vmul.f32 s12, s17, s12 */
/* @0x179f14 vmul.f32 s10, s15, s10 */
/* @0x179f18 vabs.f32 s8, s14 */
/* @0x179f1c vcmpe.f32 s8, s9 */
/* @0x179f20 vdiv.f32 s11, s10, s11 */
/* @0x179f24 vmrs APSR_nzcv, fpscr */
/* @0x179f28 vdiv.f32 s16, s12, s13 */
/* @0x179f2c bpl 0x179f68 <_Z22GR_Window_View_ConvertiiiRiS_+0x204> */
/* @0x179f30 vldr s15, [r8, #4] */
/* @0x179f34 vadd.f32 s11, s11, s15 */
/* @0x179f38 vcvt.f64.f32 d6, s11 */
/* @0x179f3c vmov r0, r1, d6 */
/* @0x179f40 bl 0xb66e8 <lrint@plt> */
/* @0x179f44 vldr s15, [r8, #8] */
/* @0x179f48 vadd.f32 s16, s16, s15 */
/* @0x179f4c vcvt.f64.f32 d7, s16 */
/* @0x179f50 str r0, [r5] */
/* @0x179f54 vmov r0, r1, d7 */
/* @0x179f58 bl 0xb66e8 <lrint@plt> */
/* @0x179f5c ldr r1, [sp, #0xa0] */
/* @0x179f60 str r0, [r1] */
/* @0x179f64 b 0x179da8 <_Z22GR_Window_View_ConvertiiiRiS_+0x44> */
/* @0x179f68 vldr s26, [pc, #368] */
/* @0x179f6c vnmul.f32 s14, s14, s26 */
/* @0x179f70 vldr s25, [pc, #364] */
/* @0x179f74 vdiv.f32 s20, s14, s25 */
/* @0x179f78 vmov.f32 s24, #5.000000e-01 */
/* @0x179f7c vmul.f32 s27, s15, s24 */
/* @0x179f80 vsub.f32 s11, s11, s27 */
/* @0x179f84 vcvt.f64.f32 d10, s20 */
/* @0x179f88 vmov r0, r1, d10 */
/* @0x179f8c vcvt.f64.f32 d9, s11 */
/* @0x179f90 bl 0xb67e4 <cos@plt> */
/* @0x179f94 vmls.f32 s16, s17, s24 */
/* @0x179f98 vcvt.f64.f32 d8, s16 */
/* @0x179f9c vmov d11, r0, r1 */
/* @0x179fa0 vmov r0, r1, d10 */
/* @0x179fa4 bl 0xb67d8 <sin@plt> */
/* @0x179fa8 vldr s14, [r8, #4] */
/* @0x179fac vadd.f32 s14, s27, s14 */
/* @0x179fb0 vcvt.f64.f32 d7, s14 */
/* @0x179fb4 vmla.f64 d7, d9, d11 */
/* @0x179fb8 vmov d6, r0, r1 */
/* @0x179fbc vmov.f64 d5, d7 */
/* @0x179fc0 vmla.f64 d5, d8, d6 */
/* @0x179fc4 vmov r0, r1, d5 */
/* @0x179fc8 bl 0xb66e8 <lrint@plt> */
/* @0x179fcc vldr s22, [r8, #36] */
/* @0x179fd0 vmul.f32 s15, s22, s26 */
/* @0x179fd4 vdiv.f32 s15, s15, s25 */
/* @0x179fd8 str r0, [r5] */
/* @0x179fdc vnmul.f32 s22, s22, s26 */
/* @0x179fe0 vdiv.f32 s25, s22, s25 */
/* @0x179fe4 vcvt.f64.f32 d5, s15 */
/* @0x179fe8 vmov r0, r1, d5 */
/* @0x179fec bl 0xb67d8 <sin@plt> */
/* @0x179ff0 vcvt.f64.f32 d6, s25 */
/* @0x179ff4 vmov d10, r0, r1 */
/* @0x179ff8 vmov r0, r1, d6 */
/* @0x179ffc bl 0xb67e4 <cos@plt> */
/* @0x17a000 vldr s15, [r8, #16] */
/* @0x17a004 vldr s14, [r8, #8] */
/* @0x17a008 vmla.f32 s14, s15, s24 */
/* @0x17a00c vcvt.f64.f32 d7, s14 */
/* @0x17a010 vmla.f64 d7, d9, d10 */
/* @0x17a014 vmov d6, r0, r1 */
/* @0x17a018 vmov.f64 d5, d7 */
/* @0x17a01c vmla.f64 d5, d8, d6 */
/* @0x17a020 vmov r0, r1, d5 */
/* @0x17a024 bl 0xb66e8 <lrint@plt> */
/* @0x17a028 ldr r1, [sp, #0xa0] */
/* @0x17a02c str r0, [r1] */
/* @0x17a030 b 0x179da8 <_Z22GR_Window_View_ConvertiiiRiS_+0x44> */
/* @0x17a034 ldr r3, [pc, #0xd0] */
/* @0x17a038 ldr r1, [r8, #0x2c] */
/* @0x17a03c ldr r0, [r4, r3] */
/* @0x17a040 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x17a044 subs r1, r0, #0 */
/* @0x17a048 beq 0x179da8 <_Z22GR_Window_View_ConvertiiiRiS_+0x44> */
/* @0x17a04c ldr r2, [sp, #0xa0] */
/* @0x17a050 vldr s13, [r8, #32] */
/* @0x17a054 vldr s10, [r5] */
/* @0x17a058 vcvt.f32.s32 s16, s10 */
/* @0x17a05c vldr s14, [r8, #28] */
/* @0x17a060 add r0, sp, #24 */
/* @0x17a064 ldr r2, [r2] */
/* @0x17a068 vmov s8, r2 */
/* @0x17a06c str r2, [sp, #0x4] */
/* @0x17a070 vcvt.f32.s32 s17, s8 */
/* @0x17a074 vdiv.f32 s17, s17, s13 */
/* @0x17a078 vdiv.f32 s16, s16, s14 */
/* @0x17a07c vmov.f32 s15, #1.000000e+00 */
/* @0x17a080 vadd.f32 s17, s17, s17 */
/* @0x17a084 vadd.f32 s16, s16, s16 */
/* @0x17a088 vsub.f32 s17, s17, s15 */
/* @0x17a08c vsub.f32 s16, s16, s15 */
/* @0x17a090 bl 0x16d260 <_ZN7CCamera17GetInvViewProjMatEv> */
/* @0x17a094 vldr s14, [sp, #40] */
/* @0x17a098 vldr s15, [sp, #44] */
/* @0x17a09c vldr s10, [sp, #24] */
/* @0x17a0a0 vldr s11, [sp, #28] */
/* @0x17a0a4 vldr s12, [sp, #72] */
/* @0x17a0a8 vldr s13, [sp, #76] */
/* @0x17a0ac ldr r0, [sp, #0xa0] */
/* @0x17a0b0 vmul.f32 s14, s17, s14 */
/* @0x17a0b4 vmul.f32 s15, s17, s15 */
/* @0x17a0b8 vmla.f32 s14, s16, s10 */
/* @0x17a0bc vmla.f32 s15, s16, s11 */
/* @0x17a0c0 vadd.f32 s14, s14, s12 */
/* @0x17a0c4 vadd.f32 s15, s15, s13 */
/* @0x17a0c8 vcvt.s32.f32 s14, s14 */
/* @0x17a0cc vcvt.s32.f32 s15, s15 */
/* @0x17a0d0 vstr s14, [r5] */
/* @0x17a0d4 vstr s15, [r0] */
/* @0x17a0d8 b 0x179da8 <_Z22GR_Window_View_ConvertiiiRiS_+0x44> */
/* @0x17a0dc ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^ */
/* @0x17a0e0 ldrdmi r0, r1, [r9], #-251 */
/* @0x17a0e4 teqmi r4, #0 */
/* @0x17a0e8 eoreq r7, r7, r12, asr #29 */
/* @0x17a0ec .word 0xffffe6b0 */
/* @0x17a0f0 .word 0xffffe6b8 */
/* @0x17a0f4 .word 0xffffdf38 */
/* @0x17a0f8 .word 0xffffe6bc */
/* @0x17a0fc .word 0xffffe6c0 */
/* @0x17a100 .word 0xffffdf40 */
/* @0x17a104 .word 0xffffe6c4 */
/* @0x17a108 .word 0xffffbcd4 */
/* @0x17a10c .word 0xffffc024 */

/* ── FUNC 0x17a110 · GR_Window_View_Convert_World(int, float, float, int&, int&) · size=676 · insn=169 */
/* @0x17a110 push {r4, r5, r6, lr} */
/* @0x17a114 vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x17a118 vmov s19, r1 */
/* @0x17a11c sub sp, sp, #64 */
/* @0x17a120 mov r4, r0 */
/* @0x17a124 vcvt.f64.f32 d5, s19 */
/* @0x17a128 mov r6, r3 */
/* @0x17a12c vmov s17, r2 */
/* @0x17a130 ldr r5, [sp, #0x88] */
/* @0x17a134 vmov r0, r1, d5 */
/* @0x17a138 bl 0xb66e8 <lrint@plt> */
/* @0x17a13c vcvt.f64.f32 d6, s17 */
/* @0x17a140 str r0, [r6] */
/* @0x17a144 vmov r0, r1, d6 */
/* @0x17a148 bl 0xb66e8 <lrint@plt> */
/* @0x17a14c cmp r4, #31 */
/* @0x17a150 str r0, [r5] */
/* @0x17a154 bhi 0x17a2a8 <_Z28GR_Window_View_Convert_WorldiffRiS_+0x198> */
/* @0x17a158 add r4, r4, r4, lsl #1 */
/* @0x17a15c ldr r2, [pc, #0x244] */
/* @0x17a160 lsl r4, r4, #4 */
/* @0x17a164 ldr r2, [pc, r2] */
/* @0x17a168 ldrb r3, [r2, r4] */
/* @0x17a16c cmp r3, #0 */
/* @0x17a170 bne 0x17a2a8 <_Z28GR_Window_View_Convert_WorldiffRiS_+0x198> */
/* @0x17a174 add r4, r4, r2 */
/* @0x17a178 vldr s11, [r4, #12] */
/* @0x17a17c vcmp.f32 s11, #0 */
/* @0x17a180 vmrs APSR_nzcv, fpscr */
/* @0x17a184 beq 0x17a2a8 <_Z28GR_Window_View_Convert_WorldiffRiS_+0x198> */
/* @0x17a188 vldr s10, [r4, #16] */
/* @0x17a18c vcmp.f32 s10, #0 */
/* @0x17a190 vmrs APSR_nzcv, fpscr */
/* @0x17a194 beq 0x17a2a8 <_Z28GR_Window_View_Convert_WorldiffRiS_+0x198> */
/* @0x17a198 ldr r3, [pc, #0x20c] */
/* @0x17a19c ldr r3, [pc, r3] */
/* @0x17a1a0 ldrb r3, [r3] */
/* @0x17a1a4 cmp r3, #0 */
/* @0x17a1a8 bne 0x17a2b4 <_Z28GR_Window_View_Convert_WorldiffRiS_+0x1a4> */
/* @0x17a1ac vldr s15, [r4, #4] */
/* @0x17a1b0 vldr s16, [r4, #8] */
/* @0x17a1b4 vsub.f32 s19, s19, s15 */
/* @0x17a1b8 vldr s8, [r4, #36] */
/* @0x17a1bc vldr s9, [r4, #28] */
/* @0x17a1c0 vldr s21, [r4, #32] */
/* @0x17a1c4 vldr d7, [pc, #460] */
/* @0x17a1c8 vsub.f32 s16, s17, s16 */
/* @0x17a1cc vabs.f32 s12, s8 */
/* @0x17a1d0 vmul.f32 s19, s9, s19 */
/* @0x17a1d4 vmul.f32 s16, s21, s16 */
/* @0x17a1d8 vcvt.f64.f32 d6, s12 */
/* @0x17a1dc vcmpe.f64 d6, d7 */
/* @0x17a1e0 vdiv.f32 s11, s19, s11 */
/* @0x17a1e4 vmrs APSR_nzcv, fpscr */
/* @0x17a1e8 vdiv.f32 s16, s16, s10 */
/* @0x17a1ec bmi 0x17a360 <_Z28GR_Window_View_Convert_WorldiffRiS_+0x250> */
/* @0x17a1f0 vldr s27, [pc, #424] */
/* @0x17a1f4 vldr s20, [pc, #424] */
/* @0x17a1f8 vmul.f32 s22, s8, s27 */
/* @0x17a1fc vdiv.f32 s22, s22, s20 */
/* @0x17a200 vmov.f32 s26, #5.000000e-01 */
/* @0x17a204 vmul.f32 s28, s9, s26 */
/* @0x17a208 vsub.f32 s11, s11, s28 */
/* @0x17a20c vcvt.f64.f32 d11, s22 */
/* @0x17a210 vmov r0, r1, d11 */
/* @0x17a214 vcvt.f64.f32 d9, s11 */
/* @0x17a218 bl 0xb67e4 <cos@plt> */
/* @0x17a21c vmls.f32 s16, s21, s26 */
/* @0x17a220 vcvt.f64.f32 d8, s16 */
/* @0x17a224 vmov d12, r0, r1 */
/* @0x17a228 vmov r0, r1, d11 */
/* @0x17a22c bl 0xb67d8 <sin@plt> */
/* @0x17a230 vldr s14, [r4, #20] */
/* @0x17a234 vadd.f32 s14, s28, s14 */
/* @0x17a238 vcvt.f64.f32 d7, s14 */
/* @0x17a23c vmla.f64 d7, d9, d12 */
/* @0x17a240 vmov d6, r0, r1 */
/* @0x17a244 vmov.f64 d5, d7 */
/* @0x17a248 vmla.f64 d5, d8, d6 */
/* @0x17a24c vmov r0, r1, d5 */
/* @0x17a250 bl 0xb66e8 <lrint@plt> */
/* @0x17a254 vldr s15, [r4, #36] */
/* @0x17a258 vmul.f32 s27, s15, s27 */
/* @0x17a25c vdiv.f32 s20, s27, s20 */
/* @0x17a260 str r0, [r6] */
/* @0x17a264 vcvt.f64.f32 d10, s20 */
/* @0x17a268 vmov r0, r1, d10 */
/* @0x17a26c bl 0xb67d8 <sin@plt> */
/* @0x17a270 vmov d11, r0, r1 */
/* @0x17a274 vmov r0, r1, d10 */
/* @0x17a278 bl 0xb67e4 <cos@plt> */
/* @0x17a27c vldr s15, [r4, #32] */
/* @0x17a280 vldr s14, [r4, #24] */
/* @0x17a284 vmla.f32 s14, s15, s26 */
/* @0x17a288 vcvt.f64.f32 d7, s14 */
/* @0x17a28c vmls.f64 d7, d9, d11 */
/* @0x17a290 vmov d6, r0, r1 */
/* @0x17a294 vmov.f64 d5, d7 */
/* @0x17a298 vmla.f64 d5, d8, d6 */
/* @0x17a29c vmov r0, r1, d5 */
/* @0x17a2a0 bl 0xb66e8 <lrint@plt> */
/* @0x17a2a4 str r0, [r5] */
/* @0x17a2a8 add sp, sp, #64 */
/* @0x17a2ac vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x17a2b0 pop {r4, r5, r6, pc} */
/* @0x17a2b4 ldr r0, [pc, #0xf4] */
/* @0x17a2b8 ldr r1, [r4, #0x2c] */
/* @0x17a2bc ldr r0, [pc, r0] */
/* @0x17a2c0 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x17a2c4 subs r1, r0, #0 */
/* @0x17a2c8 beq 0x17a2a8 <_Z28GR_Window_View_Convert_WorldiffRiS_+0x198> */
/* @0x17a2cc mov r0, sp */
/* @0x17a2d0 bl 0x16d1ac <_ZN7CCamera14GetViewProjMatEv> */
/* @0x17a2d4 vldr s11, [sp, #16] */
/* @0x17a2d8 vldr s12, [sp, #28] */
/* @0x17a2dc vmul.f32 s11, s17, s11 */
/* @0x17a2e0 vldr s2, [sp, #20] */
/* @0x17a2e4 vldr s3, [sp] */
/* @0x17a2e8 vldr s4, [sp, #12] */
/* @0x17a2ec vldr s5, [sp, #4] */
/* @0x17a2f0 vldr s8, [sp, #52] */
/* @0x17a2f4 vldr s6, [sp, #48] */
/* @0x17a2f8 vldr s7, [sp, #60] */
/* @0x17a2fc vldr s9, [r4, #28] */
/* @0x17a300 vldr s13, [r4, #20] */
/* @0x17a304 vldr s10, [r4, #32] */
/* @0x17a308 vldr s14, [r4, #24] */
/* @0x17a30c vmul.f32 s12, s17, s12 */
/* @0x17a310 vmul.f32 s17, s17, s2 */
/* @0x17a314 vmla.f32 s11, s19, s3 */
/* @0x17a318 vmla.f32 s12, s19, s4 */
/* @0x17a31c vmla.f32 s17, s19, s5 */
/* @0x17a320 vadd.f32 s12, s12, s7 */
/* @0x17a324 vadd.f32 s17, s17, s8 */
/* @0x17a328 vadd.f32 s11, s11, s6 */
/* @0x17a32c vdiv.f32 s11, s11, s12 */
/* @0x17a330 vdiv.f32 s12, s17, s12 */
/* @0x17a334 vmov.f32 s15, #5.000000e-01 */
/* @0x17a338 vmov.f32 s8, s15 */
/* @0x17a33c vmla.f32 s8, s11, s15 */
/* @0x17a340 vmla.f32 s15, s12, s15 */
/* @0x17a344 vmla.f32 s13, s8, s9 */
/* @0x17a348 vmla.f32 s14, s15, s10 */
/* @0x17a34c vcvt.s32.f32 s13, s13 */
/* @0x17a350 vcvt.s32.f32 s14, s14 */
/* @0x17a354 vstr s13, [r6] */
/* @0x17a358 vstr s14, [r5] */
/* @0x17a35c b 0x17a2a8 <_Z28GR_Window_View_Convert_WorldiffRiS_+0x198> */
/* @0x17a360 vldr s15, [r4, #20] */
/* @0x17a364 vadd.f32 s11, s11, s15 */
/* @0x17a368 vcvt.f64.f32 d6, s11 */
/* @0x17a36c vmov r0, r1, d6 */
/* @0x17a370 bl 0xb66e8 <lrint@plt> */
/* @0x17a374 vldr s15, [r4, #24] */
/* @0x17a378 vadd.f32 s16, s16, s15 */
/* @0x17a37c vcvt.f64.f32 d7, s16 */
/* @0x17a380 str r0, [r6] */
/* @0x17a384 vmov r0, r1, d7 */
/* @0x17a388 bl 0xb66e8 <lrint@plt> */
/* @0x17a38c str r0, [r5] */
/* @0x17a390 b 0x17a2a8 <_Z28GR_Window_View_Convert_WorldiffRiS_+0x198> */
/* @0x17a394 nop */
/* @0x17a398 .word 0x47ae147b */
/* @0x17a39c svclo #0x847ae1 */
/* @0x17a3a0 ldrdmi r0, r1, [r9], #-251 */
/* @0x17a3a4 teqmi r4, #0 */
/* @0x17a3a8 mlaeq r7, r12, r1, r6 */
/* @0x17a3ac eoreq r3, r7, r8, lsl #15 */
/* @0x17a3b0 .word 0x002739b8 */

/* ── FUNC 0x17a3b4 · anon_17a3b4 · size=0 · insn=1 */
/* @0x17a3b4 nop */

/* ── FUNC 0x17a3b8 · GR_Window_Views_Get_ID(int, int) · size=744 · insn=186 */
/* @0x17a3b8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17a3bc sub sp, sp, #68 */
/* @0x17a3c0 add r3, sp, #44 */
/* @0x17a3c4 mov r7, r0 */
/* @0x17a3c8 mov r8, r1 */
/* @0x17a3cc add r0, sp, #32 */
/* @0x17a3d0 add r1, sp, #36 */
/* @0x17a3d4 add r2, sp, #40 */
/* @0x17a3d8 ldr r11, [pc, #0x298] */
/* @0x17a3dc bl 0x179a00 <_Z20Get_FullScreenOffsetRiS_S_S_> */
/* @0x17a3e0 ldr r3, [pc, #0x294] */
/* @0x17a3e4 add r11, pc, r11 */
/* @0x17a3e8 ldr r6, [r11, r3] */
/* @0x17a3ec ldr r1, [r6] */
/* @0x17a3f0 cmp r1, #0 */
/* @0x17a3f4 beq 0x17a55c <_Z22GR_Window_Views_Get_IDii+0x1a4> */
/* @0x17a3f8 ldr r2, [pc, #0x280] */
/* @0x17a3fc mov r9, #0 */
/* @0x17a400 mov r3, #31 */
/* @0x17a404 ldr r5, [r11, r2] */
/* @0x17a408 mov r2, r5 */
/* @0x17a40c ldrb r0, [r2, #0x5d0] */
/* @0x17a410 cmp r0, #0 */
/* @0x17a414 beq 0x17a43c <_Z22GR_Window_Views_Get_IDii+0x84> */
/* @0x17a418 cmp r3, #7 */
/* @0x17a41c ldrls r0, [r1, #0xc4] */
/* @0x17a420 movhi r0, #0 */
/* @0x17a424 ldrb r12, [r0] */
/* @0x17a428 cmp r12, #0 */
/* @0x17a42c beq 0x17a43c <_Z22GR_Window_Views_Get_IDii+0x84> */
/* @0x17a430 ldr r0, [r0, #0x3c] */
/* @0x17a434 cmn r0, #1 */
/* @0x17a438 addeq r9, r9, #1 */
/* @0x17a43c sub r3, r3, #1 */
/* @0x17a440 sub r2, r2, #48 */
/* @0x17a444 cmn r3, #1 */
/* @0x17a448 sub r1, r1, #4 */
/* @0x17a44c bne 0x17a40c <_Z22GR_Window_Views_Get_IDii+0x54> */
/* @0x17a450 cmp r9, #0 */
/* @0x17a454 beq 0x17a55c <_Z22GR_Window_Views_Get_IDii+0x1a4> */
/* @0x17a458 add r3, sp, #48 */
/* @0x17a45c add r5, r5, #1520 */
/* @0x17a460 str r3, [sp, #0x8] */
/* @0x17a464 add r10, sp, #24 */
/* @0x17a468 add r3, sp, #52 */
/* @0x17a46c add r9, sp, #28 */
/* @0x17a470 str r3, [sp, #0xc] */
/* @0x17a474 mov r4, #31 */
/* @0x17a478 add r3, sp, #56 */
/* @0x17a47c str r3, [sp, #0x10] */
/* @0x17a480 add r3, sp, #60 */
/* @0x17a484 str r3, [sp, #0x14] */
/* @0x17a488 b 0x17a49c <_Z22GR_Window_Views_Get_IDii+0xe4> */
/* @0x17a48c sub r4, r4, #1 */
/* @0x17a490 sub r5, r5, #48 */
/* @0x17a494 cmn r4, #1 */
/* @0x17a498 beq 0x17a55c <_Z22GR_Window_Views_Get_IDii+0x1a4> */
/* @0x17a49c ldrb r0, [r5, #-0x20] */
/* @0x17a4a0 cmp r0, #0 */
/* @0x17a4a4 beq 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4> */
/* @0x17a4a8 cmp r4, #7 */
/* @0x17a4ac ldr r3, [r6] */
/* @0x17a4b0 addls r2, r4, #18 */
/* @0x17a4b4 movhi r3, #0 */
/* @0x17a4b8 ldrls r3, [r3, r2, lsl #2] */
/* @0x17a4bc ldrb r2, [r3] */
/* @0x17a4c0 cmp r2, #0 */
/* @0x17a4c4 beq 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4> */
/* @0x17a4c8 ldr r3, [r3, #0x3c] */
/* @0x17a4cc cmn r3, #1 */
/* @0x17a4d0 bne 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4> */
/* @0x17a4d4 mov r3, r10 */
/* @0x17a4d8 str r9, [sp] */
/* @0x17a4dc mov r0, r4 */
/* @0x17a4e0 mov r1, r7 */
/* @0x17a4e4 mov r2, r8 */
/* @0x17a4e8 bl 0x179d64 <_Z22GR_Window_View_ConvertiiiRiS_> */
/* @0x17a4ec ldr r3, [pc, #0x190] */
/* @0x17a4f0 ldr r3, [r11, r3] */
/* @0x17a4f4 ldrb r3, [r3] */
/* @0x17a4f8 cmp r3, #0 */
/* @0x17a4fc bne 0x17a568 <_Z22GR_Window_Views_Get_IDii+0x1b0> */
/* @0x17a500 vldr s13, [sp, #24] */
/* @0x17a504 vcvt.f32.s32 s15, s13 */
/* @0x17a508 vldr s14, [r5, #-28] */
/* @0x17a50c vcmpe.f32 s15, s14 */
/* @0x17a510 vmrs APSR_nzcv, fpscr */
/* @0x17a514 blt 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4> */
/* @0x17a518 vldr s13, [r5, #-20] */
/* @0x17a51c vadd.f32 s14, s14, s13 */
/* @0x17a520 vcmpe.f32 s15, s14 */
/* @0x17a524 vmrs APSR_nzcv, fpscr */
/* @0x17a528 bpl 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4> */
/* @0x17a52c vldr s12, [sp, #28] */
/* @0x17a530 vcvt.f32.s32 s15, s12 */
/* @0x17a534 vldr s14, [r5, #-24] */
/* @0x17a538 vcmpe.f32 s15, s14 */
/* @0x17a53c vmrs APSR_nzcv, fpscr */
/* @0x17a540 blt 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4> */
/* @0x17a544 vldr s13, [r5, #-16] */
/* @0x17a548 vadd.f32 s14, s14, s13 */
/* @0x17a54c vcmpe.f32 s15, s14 */
/* @0x17a550 vmrs APSR_nzcv, fpscr */
/* @0x17a554 bpl 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4> */
/* @0x17a558 b 0x17a670 <_Z22GR_Window_Views_Get_IDii+0x2b8> */
/* @0x17a55c mvn r0, #0 */
/* @0x17a560 add sp, sp, #68 */
/* @0x17a564 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17a568 add r0, sp, #48 */
/* @0x17a56c add r1, sp, #52 */
/* @0x17a570 add r2, sp, #56 */
/* @0x17a574 add r3, sp, #60 */
/* @0x17a578 bl 0x179a00 <_Z20Get_FullScreenOffsetRiS_S_S_> */
/* @0x17a57c ldr r2, [pc, #0x104] */
/* @0x17a580 ldr r3, [sp, #0x30] */
/* @0x17a584 vldr s14, [r5, #-12] */
/* @0x17a588 ldr r1, [pc, #0xfc] */
/* @0x17a58c ldr r2, [r11, r2] */
/* @0x17a590 ldr r0, [r11, r1] */
/* @0x17a594 vldr s12, [r0] */
/* @0x17a598 ldr r2, [r2] */
/* @0x17a59c vcvt.f32.s32 s12, s12 */
/* @0x17a5a0 ldr r1, [pc, #0xe8] */
/* @0x17a5a4 sub r2, r2, r3, lsl #1 */
/* @0x17a5a8 ldr r3, [pc, #0xe4] */
/* @0x17a5ac ldr r1, [r11, r1] */
/* @0x17a5b0 vldr s15, [r1] */
/* @0x17a5b4 vmov s13, r2 */
/* @0x17a5b8 ldr r2, [pc, #0xd8] */
/* @0x17a5bc ldr r3, [r11, r3] */
/* @0x17a5c0 vcvt.f32.s32 s13, s13 */
/* @0x17a5c4 ldr r1, [pc, #0xd0] */
/* @0x17a5c8 ldr r2, [r11, r2] */
/* @0x17a5cc ldr r1, [r11, r1] */
/* @0x17a5d0 vldr s11, [r1] */
/* @0x17a5d4 ldr r2, [r2] */
/* @0x17a5d8 ldr r1, [r3] */
/* @0x17a5dc ldr r3, [sp, #0x34] */
/* @0x17a5e0 vdiv.f32 s13, s12, s13 */
/* @0x17a5e4 vmov s12, r7 */
/* @0x17a5e8 vdiv.f32 s15, s13, s15 */
/* @0x17a5ec vcvt.f32.s32 s13, s12 */
/* @0x17a5f0 vmul.f32 s15, s13, s15 */
/* @0x17a5f4 vcvt.s32.f32 s15, s15 */
/* @0x17a5f8 vcvt.f32.s32 s15, s15 */
/* @0x17a5fc vcmpe.f32 s15, s14 */
/* @0x17a600 vmrs APSR_nzcv, fpscr */
/* @0x17a604 blt 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4> */
/* @0x17a608 vldr s13, [r5, #-4] */
/* @0x17a60c vadd.f32 s14, s14, s13 */
/* @0x17a610 vcmpe.f32 s15, s14 */
/* @0x17a614 vmrs APSR_nzcv, fpscr */
/* @0x17a618 bpl 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4> */
/* @0x17a61c sub r1, r1, r3, lsl #1 */
/* @0x17a620 vmov s14, r2 */
/* @0x17a624 vmov s12, r8 */
/* @0x17a628 vmov s15, r1 */
/* @0x17a62c vcvt.f32.s32 s13, s14 */
/* @0x17a630 vldr s14, [r5, #-8] */
/* @0x17a634 vcvt.f32.s32 s15, s15 */
/* @0x17a638 vdiv.f32 s15, s13, s15 */
/* @0x17a63c vdiv.f32 s11, s15, s11 */
/* @0x17a640 vcvt.f32.s32 s15, s12 */
/* @0x17a644 vmul.f32 s15, s15, s11 */
/* @0x17a648 vcvt.s32.f32 s15, s15 */
/* @0x17a64c vcvt.f32.s32 s15, s15 */
/* @0x17a650 vcmpe.f32 s15, s14 */
/* @0x17a654 vmrs APSR_nzcv, fpscr */
/* @0x17a658 blt 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4> */
/* @0x17a65c vldr s13, [r5] */
/* @0x17a660 vadd.f32 s14, s14, s13 */
/* @0x17a664 vcmpe.f32 s15, s14 */
/* @0x17a668 vmrs APSR_nzcv, fpscr */
/* @0x17a66c bpl 0x17a48c <_Z22GR_Window_Views_Get_IDii+0xd4> */
/* @0x17a670 mov r0, r4 */
/* @0x17a674 b 0x17a560 <_Z22GR_Window_Views_Get_IDii+0x1a8> */
/* @0x17a678 eoreq r7, r7, r12, ror #16 */
/* @0x17a67c .word 0xffffbcd8 */
/* @0x17a680 .word 0xffffe6b0 */
/* @0x17a684 .word 0xffffbcd4 */
/* @0x17a688 .word 0xffffe6b8 */
/* @0x17a68c .word 0xffffdf38 */
/* @0x17a690 .word 0xffffe6bc */
/* @0x17a694 .word 0xffffe6c0 */
/* @0x17a698 .word 0xffffdf40 */
/* @0x17a69c .word 0xffffe6c4 */

/* ── FUNC 0x17a6a0 · GR_Window_Views_Convert(int, int, int&, int&) · size=908 · insn=227 */
/* @0x17a6a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17a6a4 sub sp, sp, #60 */
/* @0x17a6a8 mov r9, r1 */
/* @0x17a6ac mov r7, r2 */
/* @0x17a6b0 str r0, [sp, #0x8] */
/* @0x17a6b4 add r1, sp, #28 */
/* @0x17a6b8 mov r8, r3 */
/* @0x17a6bc add r0, sp, #24 */
/* @0x17a6c0 add r3, sp, #36 */
/* @0x17a6c4 add r2, sp, #32 */
/* @0x17a6c8 ldr r10, [pc, #0x334] */
/* @0x17a6cc bl 0x179a00 <_Z20Get_FullScreenOffsetRiS_S_S_> */
/* @0x17a6d0 ldr r3, [pc, #0x330] */
/* @0x17a6d4 add r10, pc, r10 */
/* @0x17a6d8 ldr r6, [r10, r3] */
/* @0x17a6dc ldr r1, [r6] */
/* @0x17a6e0 cmp r1, #0 */
/* @0x17a6e4 beq 0x17a9e0 <_Z23GR_Window_Views_ConvertiiRiS_+0x340> */
/* @0x17a6e8 ldr r3, [pc, #0x31c] */
/* @0x17a6ec mov r4, r1 */
/* @0x17a6f0 mov r2, #0 */
/* @0x17a6f4 mov r0, #31 */
/* @0x17a6f8 ldr r11, [r10, r3] */
/* @0x17a6fc mov r12, r11 */
/* @0x17a700 ldrb r3, [r12, #0x5d0] */
/* @0x17a704 cmp r3, #0 */
/* @0x17a708 beq 0x17a730 <_Z23GR_Window_Views_ConvertiiRiS_+0x90> */
/* @0x17a70c cmp r0, #7 */
/* @0x17a710 ldrls r3, [r4, #0xc4] */
/* @0x17a714 movhi r3, #0 */
/* @0x17a718 ldrb r5, [r3] */
/* @0x17a71c cmp r5, #0 */
/* @0x17a720 beq 0x17a730 <_Z23GR_Window_Views_ConvertiiRiS_+0x90> */
/* @0x17a724 ldr r3, [r3, #0x3c] */
/* @0x17a728 cmn r3, #1 */
/* @0x17a72c addeq r2, r2, #1 */
/* @0x17a730 sub r0, r0, #1 */
/* @0x17a734 sub r12, r12, #48 */
/* @0x17a738 cmn r0, #1 */
/* @0x17a73c sub r4, r4, #4 */
/* @0x17a740 bne 0x17a700 <_Z23GR_Window_Views_ConvertiiRiS_+0x60> */
/* @0x17a744 cmp r2, #0 */
/* @0x17a748 beq 0x17a848 <_Z23GR_Window_Views_ConvertiiRiS_+0x1a8> */
/* @0x17a74c add r1, sp, #44 */
/* @0x17a750 add r3, sp, #48 */
/* @0x17a754 str r1, [sp, #0xc] */
/* @0x17a758 add r11, r11, #1520 */
/* @0x17a75c add r1, sp, #52 */
/* @0x17a760 add r5, sp, #40 */
/* @0x17a764 str r3, [sp, #0x10] */
/* @0x17a768 mov r4, #31 */
/* @0x17a76c str r1, [sp, #0x14] */
/* @0x17a770 b 0x17a784 <_Z23GR_Window_Views_ConvertiiRiS_+0xe4> */
/* @0x17a774 sub r4, r4, #1 */
/* @0x17a778 sub r11, r11, #48 */
/* @0x17a77c cmn r4, #1 */
/* @0x17a780 beq 0x17a840 <_Z23GR_Window_Views_ConvertiiRiS_+0x1a0> */
/* @0x17a784 ldrb r1, [r11, #-0x20] */
/* @0x17a788 cmp r1, #0 */
/* @0x17a78c beq 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4> */
/* @0x17a790 cmp r4, #7 */
/* @0x17a794 ldr r3, [r6] */
/* @0x17a798 addls r2, r4, #18 */
/* @0x17a79c movhi r3, #0 */
/* @0x17a7a0 ldrls r3, [r3, r2, lsl #2] */
/* @0x17a7a4 ldrb r2, [r3] */
/* @0x17a7a8 cmp r2, #0 */
/* @0x17a7ac beq 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4> */
/* @0x17a7b0 ldr r3, [r3, #0x3c] */
/* @0x17a7b4 cmn r3, #1 */
/* @0x17a7b8 bne 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4> */
/* @0x17a7bc mov r3, r7 */
/* @0x17a7c0 str r8, [sp] */
/* @0x17a7c4 mov r0, r4 */
/* @0x17a7c8 ldr r1, [sp, #0x8] */
/* @0x17a7cc mov r2, r9 */
/* @0x17a7d0 bl 0x179d64 <_Z22GR_Window_View_ConvertiiiRiS_> */
/* @0x17a7d4 ldr r3, [pc, #0x234] */
/* @0x17a7d8 ldr r3, [r10, r3] */
/* @0x17a7dc ldrb r3, [r3] */
/* @0x17a7e0 cmp r3, #0 */
/* @0x17a7e4 bne 0x17a8d4 <_Z23GR_Window_Views_ConvertiiRiS_+0x234> */
/* @0x17a7e8 vldr s10, [r7] */
/* @0x17a7ec vcvt.f32.s32 s15, s10 */
/* @0x17a7f0 vldr s14, [r11, #-28] */
/* @0x17a7f4 vcmpe.f32 s15, s14 */
/* @0x17a7f8 vmrs APSR_nzcv, fpscr */
/* @0x17a7fc blt 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4> */
/* @0x17a800 vldr s13, [r11, #-20] */
/* @0x17a804 vadd.f32 s14, s14, s13 */
/* @0x17a808 vcmpe.f32 s15, s14 */
/* @0x17a80c vmrs APSR_nzcv, fpscr */
/* @0x17a810 bpl 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4> */
/* @0x17a814 vldr s11, [r8] */
/* @0x17a818 vcvt.f32.s32 s15, s11 */
/* @0x17a81c vldr s14, [r11, #-24] */
/* @0x17a820 vcmpe.f32 s15, s14 */
/* @0x17a824 vmrs APSR_nzcv, fpscr */
/* @0x17a828 blt 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4> */
/* @0x17a82c vldr s13, [r11, #-16] */
/* @0x17a830 vadd.f32 s14, s14, s13 */
/* @0x17a834 vcmpe.f32 s15, s14 */
/* @0x17a838 vmrs APSR_nzcv, fpscr */
/* @0x17a83c bpl 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4> */
/* @0x17a840 add sp, sp, #60 */
/* @0x17a844 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17a848 ldr r0, [pc, #0x1c4] */
/* @0x17a84c vldr s14, [r1, #16] */
/* @0x17a850 ldr r3, [pc, #0x1c0] */
/* @0x17a854 vldr s15, [r1, #20] */
/* @0x17a858 ldr r2, [sp, #0x18] */
/* @0x17a85c vcvt.f32.s32 s14, s14 */
/* @0x17a860 ldr r12, [r10, r0] */
/* @0x17a864 ldr r0, [r10, r3] */
/* @0x17a868 ldr r3, [sp, #0x8] */
/* @0x17a86c ldr r12, [r12] */
/* @0x17a870 rsb r3, r2, r3 */
/* @0x17a874 ldr r0, [r0] */
/* @0x17a878 vmov s12, r3 */
/* @0x17a87c ldr r3, [sp, #0x1c] */
/* @0x17a880 sub r2, r12, r2, lsl #1 */
/* @0x17a884 vcvt.f32.s32 s15, s15 */
/* @0x17a888 rsb r9, r3, r9 */
/* @0x17a88c vmov s10, r2 */
/* @0x17a890 sub r3, r0, r3, lsl #1 */
/* @0x17a894 vcvt.f32.s32 s11, s10 */
/* @0x17a898 vmov s10, r3 */
/* @0x17a89c vcvt.f32.s32 s13, s10 */
/* @0x17a8a0 vdiv.f32 s14, s14, s11 */
/* @0x17a8a4 vdiv.f32 s15, s15, s13 */
/* @0x17a8a8 vmov s10, r9 */
/* @0x17a8ac vcvt.f32.s32 s12, s12 */
/* @0x17a8b0 vcvt.f32.s32 s13, s10 */
/* @0x17a8b4 vmul.f32 s14, s12, s14 */
/* @0x17a8b8 vmul.f32 s15, s13, s15 */
/* @0x17a8bc vcvt.s32.f32 s14, s14 */
/* @0x17a8c0 vcvt.s32.f32 s15, s15 */
/* @0x17a8c4 vstr s14, [r7] */
/* @0x17a8c8 vstr s15, [r8] */
/* @0x17a8cc add sp, sp, #60 */
/* @0x17a8d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17a8d4 mov r0, r5 */
/* @0x17a8d8 add r1, sp, #44 */
/* @0x17a8dc add r2, sp, #48 */
/* @0x17a8e0 add r3, sp, #52 */
/* @0x17a8e4 bl 0x179a00 <_Z20Get_FullScreenOffsetRiS_S_S_> */
/* @0x17a8e8 ldr r2, [pc, #0x124] */
/* @0x17a8ec ldr r3, [sp, #0x28] */
/* @0x17a8f0 vldr s10, [sp, #8] */
/* @0x17a8f4 ldr r1, [pc, #0x120] */
/* @0x17a8f8 vldr s14, [r11, #-12] */
/* @0x17a8fc ldr r2, [r10, r2] */
/* @0x17a900 ldr r0, [r10, r1] */
/* @0x17a904 vldr s12, [r0] */
/* @0x17a908 ldr r2, [r2] */
/* @0x17a90c vcvt.f32.s32 s12, s12 */
/* @0x17a910 ldr r1, [pc, #0x108] */
/* @0x17a914 sub r2, r2, r3, lsl #1 */
/* @0x17a918 ldr r3, [pc, #0xf8] */
/* @0x17a91c ldr r1, [r10, r1] */
/* @0x17a920 vldr s15, [r1] */
/* @0x17a924 vmov s13, r2 */
/* @0x17a928 ldr r2, [pc, #0xf4] */
/* @0x17a92c ldr r3, [r10, r3] */
/* @0x17a930 vcvt.f32.s32 s13, s13 */
/* @0x17a934 ldr r1, [pc, #0xec] */
/* @0x17a938 ldr r2, [r10, r2] */
/* @0x17a93c ldr r1, [r10, r1] */
/* @0x17a940 vldr s11, [r1] */
/* @0x17a944 ldr r2, [r2] */
/* @0x17a948 ldr r1, [r3] */
/* @0x17a94c ldr r3, [sp, #0x2c] */
/* @0x17a950 vdiv.f32 s13, s12, s13 */
/* @0x17a954 vdiv.f32 s15, s13, s15 */
/* @0x17a958 vcvt.f32.s32 s13, s10 */
/* @0x17a95c vmul.f32 s15, s13, s15 */
/* @0x17a960 vcvt.s32.f32 s15, s15 */
/* @0x17a964 vcvt.f32.s32 s15, s15 */
/* @0x17a968 vcmpe.f32 s15, s14 */
/* @0x17a96c vmrs APSR_nzcv, fpscr */
/* @0x17a970 blt 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4> */
/* @0x17a974 vldr s13, [r11, #-4] */
/* @0x17a978 vadd.f32 s14, s14, s13 */
/* @0x17a97c vcmpe.f32 s15, s14 */
/* @0x17a980 vmrs APSR_nzcv, fpscr */
/* @0x17a984 bpl 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4> */
/* @0x17a988 sub r1, r1, r3, lsl #1 */
/* @0x17a98c vmov s12, r2 */
/* @0x17a990 vldr s14, [r11, #-8] */
/* @0x17a994 vmov s15, r1 */
/* @0x17a998 vcvt.f32.s32 s13, s12 */
/* @0x17a99c vcvt.f32.s32 s15, s15 */
/* @0x17a9a0 vdiv.f32 s15, s13, s15 */
/* @0x17a9a4 vmov s13, r9 */
/* @0x17a9a8 vdiv.f32 s11, s15, s11 */
/* @0x17a9ac vcvt.f32.s32 s15, s13 */
/* @0x17a9b0 vmul.f32 s15, s15, s11 */
/* @0x17a9b4 vcvt.s32.f32 s15, s15 */
/* @0x17a9b8 vcvt.f32.s32 s15, s15 */
/* @0x17a9bc vcmpe.f32 s15, s14 */
/* @0x17a9c0 vmrs APSR_nzcv, fpscr */
/* @0x17a9c4 blt 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4> */
/* @0x17a9c8 vldr s13, [r11] */
/* @0x17a9cc vadd.f32 s14, s14, s13 */
/* @0x17a9d0 vcmpe.f32 s15, s14 */
/* @0x17a9d4 vmrs APSR_nzcv, fpscr */
/* @0x17a9d8 bpl 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4> */
/* @0x17a9dc b 0x17a840 <_Z23GR_Window_Views_ConvertiiRiS_+0x1a0> */
/* @0x17a9e0 vmov.f32 s15, #1.000000e+00 */
/* @0x17a9e4 ldr r2, [sp, #0x18] */
/* @0x17a9e8 ldr r1, [sp, #0x8] */
/* @0x17a9ec ldr r3, [sp, #0x1c] */
/* @0x17a9f0 rsb r1, r2, r1 */
/* @0x17a9f4 rsb r9, r3, r9 */
/* @0x17a9f8 vmov s12, r1 */
/* @0x17a9fc vmov.f32 s14, s15 */
/* @0x17aa00 b 0x17a8a8 <_Z23GR_Window_Views_ConvertiiRiS_+0x208> */
/* @0x17aa04 eoreq r7, r7, r12, ror r5 */
/* @0x17aa08 .word 0xffffbcd8 */
/* @0x17aa0c .word 0xffffe6b0 */
/* @0x17aa10 .word 0xffffbcd4 */
/* @0x17aa14 .word 0xffffe6b8 */
/* @0x17aa18 .word 0xffffe6c0 */
/* @0x17aa1c .word 0xffffdf38 */
/* @0x17aa20 .word 0xffffe6bc */
/* @0x17aa24 .word 0xffffdf40 */
/* @0x17aa28 .word 0xffffe6c4 */

/* ── FUNC 0x17aa2c · GR_Window_View_Mouse_Get_X(int) · size=68 · insn=17 */
/* @0x17aa2c ldr r1, [pc, #0x34] */
/* @0x17aa30 ldr r2, [pc, #0x34] */
/* @0x17aa34 str lr, [sp, #-0x4]! */
/* @0x17aa38 ldr r1, [pc, r1] */
/* @0x17aa3c sub sp, sp, #20 */
/* @0x17aa40 ldr r2, [pc, r2] */
/* @0x17aa44 ldr r1, [r1] */
/* @0x17aa48 add r12, sp, #12 */
/* @0x17aa4c ldr r2, [r2] */
/* @0x17aa50 add r3, sp, #8 */
/* @0x17aa54 str r12, [sp] */
/* @0x17aa58 bl 0x179d64 <_Z22GR_Window_View_ConvertiiiRiS_> */
/* @0x17aa5c ldr r0, [sp, #0x8] */
/* @0x17aa60 add sp, sp, #20 */
/* @0x17aa64 ldr pc, [sp], #4 */
/* @0x17aa68 eoreq r5, r7, r4, ror #2 */
/* @0x17aa6c eoreq r5, r7, r8, asr r1 */

/* ── FUNC 0x17aa70 · GR_Window_View_Mouse_Get_Y(int) · size=68 · insn=17 */
/* @0x17aa70 ldr r1, [pc, #0x34] */
/* @0x17aa74 ldr r2, [pc, #0x34] */
/* @0x17aa78 str lr, [sp, #-0x4]! */
/* @0x17aa7c ldr r1, [pc, r1] */
/* @0x17aa80 sub sp, sp, #20 */
/* @0x17aa84 ldr r2, [pc, r2] */
/* @0x17aa88 ldr r1, [r1] */
/* @0x17aa8c add r12, sp, #12 */
/* @0x17aa90 ldr r2, [r2] */
/* @0x17aa94 add r3, sp, #8 */
/* @0x17aa98 str r12, [sp] */
/* @0x17aa9c bl 0x179d64 <_Z22GR_Window_View_ConvertiiiRiS_> */
/* @0x17aaa0 ldr r0, [sp, #0xc] */
/* @0x17aaa4 add sp, sp, #20 */
/* @0x17aaa8 ldr pc, [sp], #4 */
/* @0x17aaac eoreq r5, r7, r0, lsr #2 */
/* @0x17aab0 eoreq r5, r7, r4, lsl r1 */

/* ── FUNC 0x17aab4 · GR_Window_Mouse_Get_X() · size=20 · insn=5 */
/* @0x17aab4 ldr r3, [pc, #0x8] */
/* @0x17aab8 ldr r3, [pc, r3] */
/* @0x17aabc ldr r0, [r3] */
/* @0x17aac0 bx lr */
/* @0x17aac4 eoreq r5, r7, r4, ror #1 */

/* ── FUNC 0x17aac8 · GR_Window_Mouse_Get_Y() · size=20 · insn=5 */
/* @0x17aac8 ldr r3, [pc, #0x8] */
/* @0x17aacc ldr r3, [pc, r3] */
/* @0x17aad0 ldr r0, [r3] */
/* @0x17aad4 bx lr */
/* @0x17aad8 eoreq r5, r7, r12, asr #1 */

/* ── FUNC 0x17aadc · anon_17aadc · size=0 · insn=1 */
/* @0x17aadc andeq r0, r0, r0 */

/* ── FUNC 0x17aae0 · GR_Window_View_Mouse_Set(int, int, int) · size=416 · insn=104 */
/* @0x17aae0 cmp r0, #31 */
/* @0x17aae4 push {r4, lr} */
/* @0x17aae8 vpush {d8, d9, d10} */
/* @0x17aaec sub sp, sp, #16 */
/* @0x17aaf0 bhi 0x17ac0c <_Z24GR_Window_View_Mouse_Setiii+0x12c> */
/* @0x17aaf4 add r3, r0, r0, lsl #1 */
/* @0x17aaf8 ldr r12, [pc, #0x178] */
/* @0x17aafc lsl r3, r3, #4 */
/* @0x17ab00 ldr r12, [pc, r12] */
/* @0x17ab04 add r4, r12, r3 */
/* @0x17ab08 ldrb r3, [r12, r3] */
/* @0x17ab0c cmp r3, #0 */
/* @0x17ab10 beq 0x17ac0c <_Z24GR_Window_View_Mouse_Setiii+0x12c> */
/* @0x17ab14 vldr s11, [r4, #12] */
/* @0x17ab18 vcmp.f32 s11, #0 */
/* @0x17ab1c vmrs APSR_nzcv, fpscr */
/* @0x17ab20 beq 0x17ac0c <_Z24GR_Window_View_Mouse_Setiii+0x12c> */
/* @0x17ab24 vldr s10, [r4, #16] */
/* @0x17ab28 vcmp.f32 s10, #0 */
/* @0x17ab2c vmrs APSR_nzcv, fpscr */
/* @0x17ab30 beq 0x17ac0c <_Z24GR_Window_View_Mouse_Setiii+0x12c> */
/* @0x17ab34 ldr r3, [pc, #0x140] */
/* @0x17ab38 ldr r3, [pc, r3] */
/* @0x17ab3c ldrb r3, [r3] */
/* @0x17ab40 cmp r3, #0 */
/* @0x17ab44 bne 0x17ac2c <_Z24GR_Window_View_Mouse_Setiii+0x14c> */
/* @0x17ab48 vmov s13, r1 */
/* @0x17ab4c vldr s12, [r4, #4] */
/* @0x17ab50 vmov s4, r2 */
/* @0x17ab54 vldr s7, [r4, #36] */
/* @0x17ab58 vcvt.f32.s32 s5, s13 */
/* @0x17ab5c vldr s13, [r4, #8] */
/* @0x17ab60 vldr s8, [r4, #28] */
/* @0x17ab64 vldr s9, [r4, #32] */
/* @0x17ab68 vldr d7, [pc, #248] */
/* @0x17ab6c vcvt.f32.s32 s6, s4 */
/* @0x17ab70 vsub.f32 s5, s5, s12 */
/* @0x17ab74 vsub.f32 s6, s6, s13 */
/* @0x17ab78 vabs.f32 s12, s7 */
/* @0x17ab7c vmul.f32 s5, s8, s5 */
/* @0x17ab80 vmul.f32 s6, s9, s6 */
/* @0x17ab84 vcvt.f64.f32 d6, s12 */
/* @0x17ab88 vcmpe.f64 d6, d7 */
/* @0x17ab8c vdiv.f32 s11, s5, s11 */
/* @0x17ab90 vmrs APSR_nzcv, fpscr */
/* @0x17ab94 vdiv.f32 s10, s6, s10 */
/* @0x17ab98 bmi 0x17ac18 <_Z24GR_Window_View_Mouse_Setiii+0x138> */
/* @0x17ab9c vldr s21, [pc, #204] */
/* @0x17aba0 vldr s15, [pc, #204] */
/* @0x17aba4 vmul.f32 s7, s7, s21 */
/* @0x17aba8 vdiv.f32 s21, s7, s15 */
/* @0x17abac vmov.f32 s19, #5.000000e-01 */
/* @0x17abb0 vmov r0, s21 */
/* @0x17abb4 vmul.f32 s20, s8, s19 */
/* @0x17abb8 vmul.f32 s19, s9, s19 */
/* @0x17abbc vsub.f32 s18, s11, s20 */
/* @0x17abc0 vsub.f32 s17, s10, s19 */
/* @0x17abc4 bl 0xb658c <cosf@plt> */
/* @0x17abc8 vmov s16, r0 */
/* @0x17abcc vmov r0, s21 */
/* @0x17abd0 bl 0xb6580 <sinf@plt> */
/* @0x17abd4 vldr s14, [r4, #20] */
/* @0x17abd8 vldr s15, [r4, #24] */
/* @0x17abdc vadd.f32 s14, s20, s14 */
/* @0x17abe0 vadd.f32 s15, s19, s15 */
/* @0x17abe4 vmla.f32 s14, s16, s18 */
/* @0x17abe8 vmov s13, r0 */
/* @0x17abec vmls.f32 s15, s18, s13 */
/* @0x17abf0 vmla.f32 s14, s13, s17 */
/* @0x17abf4 vmla.f32 s15, s17, s16 */
/* @0x17abf8 vcvt.s32.f32 s14, s14 */
/* @0x17abfc vcvt.s32.f32 s15, s15 */
/* @0x17ac00 vmov r0, s14 */
/* @0x17ac04 vmov r1, s15 */
/* @0x17ac08 bl 0x17af30 <_Z19GR_Window_Mouse_Setii> */
/* @0x17ac0c add sp, sp, #16 */
/* @0x17ac10 vpop {d8, d9, d10} */
/* @0x17ac14 pop {r4, pc} */
/* @0x17ac18 vldr s14, [r4, #20] */
/* @0x17ac1c vldr s15, [r4, #24] */
/* @0x17ac20 vadd.f32 s14, s11, s14 */
/* @0x17ac24 vadd.f32 s15, s10, s15 */
/* @0x17ac28 b 0x17abf8 <_Z24GR_Window_View_Mouse_Setiii+0x118> */
/* @0x17ac2c vmov s4, r1 */
/* @0x17ac30 add r12, sp, #12 */
/* @0x17ac34 vmov s13, r2 */
/* @0x17ac38 add r3, sp, #8 */
/* @0x17ac3c vcvt.f32.s32 s4, s4 */
/* @0x17ac40 str r12, [sp] */
/* @0x17ac44 vcvt.f32.s32 s13, s13 */
/* @0x17ac48 vmov r1, s4 */
/* @0x17ac4c vmov r2, s13 */
/* @0x17ac50 bl 0x17a110 <_Z28GR_Window_View_Convert_WorldiffRiS_> */
/* @0x17ac54 vldr s15, [sp, #8] */
/* @0x17ac58 vldr s4, [sp, #12] */
/* @0x17ac5c vcvt.f32.s32 s14, s15 */
/* @0x17ac60 vcvt.f32.s32 s15, s4 */
/* @0x17ac64 b 0x17abf8 <_Z24GR_Window_View_Mouse_Setiii+0x118> */
/* @0x17ac68 .word 0x47ae147b */
/* @0x17ac6c svclo #0x847ae1 */
/* @0x17ac70 ldrdmi r0, r1, [r9], #-251 */
/* @0x17ac74 teqmi r4, #0 */
/* @0x17ac78 eoreq r5, r7, r0, lsl #16 */
/* @0x17ac7c eoreq r2, r7, r12, ror #27 */

/* ── FUNC 0x17ac80 · GR_Window_Views_Mouse_Set(int, int) · size=108 · insn=27 */
/* @0x17ac80 ldr r3, [pc, #0x5c] */
/* @0x17ac84 mov r2, r1 */
/* @0x17ac88 push {r4, r5, r6} */
/* @0x17ac8c ldr r3, [pc, r3] */
/* @0x17ac90 mov r6, r0 */
/* @0x17ac94 ldr r3, [r3] */
/* @0x17ac98 cmp r3, #0 */
/* @0x17ac9c beq 0x17acdc <_Z25GR_Window_Views_Mouse_Setii+0x5c> */
/* @0x17aca0 ldr r5, [pc, #0x40] */
/* @0x17aca4 mov r3, #0 */
/* @0x17aca8 mov r0, r3 */
/* @0x17acac ldr r5, [pc, r5] */
/* @0x17acb0 b 0x17acc0 <_Z25GR_Window_Views_Mouse_Setii+0x40> */
/* @0x17acb4 add r0, r0, #1 */
/* @0x17acb8 cmp r0, #32 */
/* @0x17acbc beq 0x17acdc <_Z25GR_Window_Views_Mouse_Setii+0x5c> */
/* @0x17acc0 ldrb r4, [r5, r3] */
/* @0x17acc4 add r3, r3, #48 */
/* @0x17acc8 cmp r4, #0 */
/* @0x17accc beq 0x17acb4 <_Z25GR_Window_Views_Mouse_Setii+0x34> */
/* @0x17acd0 mov r1, r6 */
/* @0x17acd4 pop {r4, r5, r6} */
/* @0x17acd8 b 0x17aae0 <_Z24GR_Window_View_Mouse_Setiii> */
/* @0x17acdc pop {r4, r5, r6} */
/* @0x17ace0 bx lr */
/* @0x17ace4 eoreq r5, r7, r8, ror r6 */
/* @0x17ace8 eoreq r5, r7, r4, asr r6 */
