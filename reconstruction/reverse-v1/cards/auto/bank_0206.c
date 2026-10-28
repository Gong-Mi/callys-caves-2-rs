/* libyoyo.so 覆盖卡组 0206
 * 函数 0x22f598..0x232cec，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x22f598 · vorbis_book_clear · size=108 · insn=27 */
/* @0x22f598 push {r4, lr} */
/* @0x22f59c mov r4, r0 */
/* @0x22f5a0 ldr r0, [r0, #0x10] */
/* @0x22f5a4 cmp r0, #0 */
/* @0x22f5a8 beq 0x22f5b0 <vorbis_book_clear+0x18> */
/* @0x22f5ac bl 0xb655c <free@plt> */
/* @0x22f5b0 ldr r0, [r4, #0x14] */
/* @0x22f5b4 cmp r0, #0 */
/* @0x22f5b8 beq 0x22f5c0 <vorbis_book_clear+0x28> */
/* @0x22f5bc bl 0xb655c <free@plt> */
/* @0x22f5c0 ldr r0, [r4, #0x18] */
/* @0x22f5c4 cmp r0, #0 */
/* @0x22f5c8 beq 0x22f5d0 <vorbis_book_clear+0x38> */
/* @0x22f5cc bl 0xb655c <free@plt> */
/* @0x22f5d0 ldr r0, [r4, #0x1c] */
/* @0x22f5d4 cmp r0, #0 */
/* @0x22f5d8 beq 0x22f5e0 <vorbis_book_clear+0x48> */
/* @0x22f5dc bl 0xb655c <free@plt> */
/* @0x22f5e0 ldr r0, [r4, #0x20] */
/* @0x22f5e4 cmp r0, #0 */
/* @0x22f5e8 beq 0x22f5f0 <vorbis_book_clear+0x58> */
/* @0x22f5ec bl 0xb655c <free@plt> */
/* @0x22f5f0 mov r0, r4 */
/* @0x22f5f4 mov r1, #0 */
/* @0x22f5f8 mov r2, #52 */
/* @0x22f5fc pop {r4, lr} */
/* @0x22f600 b 0xb65b0 <memset@plt> */

/* ── FUNC 0x22f604 · vorbis_book_init_decode · size=1140 · insn=285 */
/* @0x22f604 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x22f608 add r11, sp, #32 */
/* @0x22f60c ldr r12, [pc, #0x45c] */
/* @0x22f610 sub sp, sp, #44 */
/* @0x22f614 mov r7, r1 */
/* @0x22f618 ldr r12, [pc, r12] */
/* @0x22f61c mov r1, #0 */
/* @0x22f620 mov r2, #52 */
/* @0x22f624 str r12, [r11, #-0x34] */
/* @0x22f628 ldr r3, [r12] */
/* @0x22f62c mov r4, r0 */
/* @0x22f630 str r3, [r11, #-0x28] */
/* @0x22f634 bl 0xb65b0 <memset@plt> */
/* @0x22f638 ldr r1, [r7, #0x4] */
/* @0x22f63c cmp r1, #0 */
/* @0x22f640 ble 0x22fa2c <vorbis_book_init_decode+0x428> */
/* @0x22f644 ldr r0, [r7, #0x8] */
/* @0x22f648 mov r5, #0 */
/* @0x22f64c add r12, r0, r1, lsl #2 */
/* @0x22f650 mov r3, r0 */
/* @0x22f654 ldr r2, [r3], #4 */
/* @0x22f658 cmp r2, #0 */
/* @0x22f65c addgt r5, r5, #1 */
/* @0x22f660 cmp r3, r12 */
/* @0x22f664 bne 0x22f654 <vorbis_book_init_decode+0x50> */
/* @0x22f668 ldr r3, [r7] */
/* @0x22f66c cmp r5, #0 */
/* @0x22f670 stmib r4, {r1, r5} */
/* @0x22f674 str r3, [r4] */
/* @0x22f678 beq 0x22f8f4 <vorbis_book_init_decode+0x2f0> */
/* @0x22f67c mov r2, r5 */
/* @0x22f680 lsl r12, r5, #2 */
/* @0x22f684 str r12, [r11, #-0x30] */
/* @0x22f688 bl 0x22eb14 <_make_words> */
/* @0x22f68c ldr r12, [r11, #-0x30] */
/* @0x22f690 add r12, r12, #14 */
/* @0x22f694 str r12, [r11, #-0x40] */
/* @0x22f698 bic r3, r12, #7 */
/* @0x22f69c sub sp, sp, r3 */
/* @0x22f6a0 str sp, [r11, #-0x38] */
/* @0x22f6a4 subs r10, r0, #0 */
/* @0x22f6a8 beq 0x22fa5c <vorbis_book_init_decode+0x458> */
/* @0x22f6ac sub r12, sp, #4 */
/* @0x22f6b0 str r4, [r11, #-0x44] */
/* @0x22f6b4 mov r8, r10 */
/* @0x22f6b8 mov r6, #0 */
/* @0x22f6bc mov r4, r12 */
/* @0x22f6c0 str r12, [r11, #-0x3c] */
/* @0x22f6c4 ldr r0, [r8] */
/* @0x22f6c8 add r6, r6, #1 */
/* @0x22f6cc bl 0x22ea70 <res2_inverse+0x25c> */
/* @0x22f6d0 cmp r6, r5 */
/* @0x22f6d4 mov r9, r8 */
/* @0x22f6d8 str r0, [r8], #4 */
/* @0x22f6dc str r9, [r4, #0x4]! */
/* @0x22f6e0 blt 0x22f6c4 <vorbis_book_init_decode+0xc0> */
/* @0x22f6e4 ldr r3, [pc, #0x388] */
/* @0x22f6e8 mov r2, #4 */
/* @0x22f6ec ldr r0, [r11, #-0x38] */
/* @0x22f6f0 mov r1, r5 */
/* @0x22f6f4 add r3, pc, r3 */
/* @0x22f6f8 ldr r4, [r11, #-0x44] */
/* @0x22f6fc bl 0xb66dc <qsort@plt> */
/* @0x22f700 ldr r12, [r11, #-0x40] */
/* @0x22f704 ldr r0, [r11, #-0x30] */
/* @0x22f708 bic r9, r12, #7 */
/* @0x22f70c sub sp, sp, r9 */
/* @0x22f710 bl 0xb6544 <malloc@plt> */
/* @0x22f714 ldr r2, [r11, #-0x3c] */
/* @0x22f718 mov r9, sp */
/* @0x22f71c mov r3, #0 */
/* @0x22f720 str r0, [r4, #0x14] */
/* @0x22f724 ldr r1, [r2, #0x4]! */
/* @0x22f728 rsb r1, r10, r1 */
/* @0x22f72c asr r1, r1, #2 */
/* @0x22f730 str r3, [r9, r1, lsl #2] */
/* @0x22f734 add r3, r3, #1 */
/* @0x22f738 cmp r3, r5 */
/* @0x22f73c blt 0x22f724 <vorbis_book_init_decode+0x120> */
/* @0x22f740 mov r3, #0 */
/* @0x22f744 mov r2, r3 */
/* @0x22f748 ldr r12, [r10, r3] */
/* @0x22f74c add r2, r2, #1 */
/* @0x22f750 ldr r1, [r9, r3] */
/* @0x22f754 cmp r2, r5 */
/* @0x22f758 add r3, r3, #4 */
/* @0x22f75c str r12, [r0, r1, lsl #2] */
/* @0x22f760 blt 0x22f748 <vorbis_book_init_decode+0x144> */
/* @0x22f764 mov r0, r10 */
/* @0x22f768 bl 0xb655c <free@plt> */
/* @0x22f76c mov r1, r5 */
/* @0x22f770 mov r2, r9 */
/* @0x22f774 add r3, r4, #12 */
/* @0x22f778 mov r0, r7 */
/* @0x22f77c bl 0x22ee18 <_book_unquantize> */
/* @0x22f780 str r0, [r4, #0x10] */
/* @0x22f784 ldr r0, [r11, #-0x30] */
/* @0x22f788 bl 0xb6544 <malloc@plt> */
/* @0x22f78c ldr lr, [r7, #0x4] */
/* @0x22f790 cmp lr, #0 */
/* @0x22f794 str r0, [r4, #0x18] */
/* @0x22f798 ble 0x22fa48 <vorbis_book_init_decode+0x444> */
/* @0x22f79c ldr r1, [r7, #0x8] */
/* @0x22f7a0 mov r2, #0 */
/* @0x22f7a4 mov r3, r2 */
/* @0x22f7a8 sub r1, r1, #4 */
/* @0x22f7ac ldr r12, [r1, #0x4]! */
/* @0x22f7b0 cmp r12, #0 */
/* @0x22f7b4 ldrgt r12, [r9, r2, lsl #2] */
/* @0x22f7b8 addgt r2, r2, #1 */
/* @0x22f7bc strgt r3, [r0, r12, lsl #2] */
/* @0x22f7c0 add r3, r3, #1 */
/* @0x22f7c4 cmp r3, lr */
/* @0x22f7c8 bne 0x22f7ac <vorbis_book_init_decode+0x1a8> */
/* @0x22f7cc mov r0, r2 */
/* @0x22f7d0 mov r6, #0 */
/* @0x22f7d4 bl 0xb6544 <malloc@plt> */
/* @0x22f7d8 mov r3, r6 */
/* @0x22f7dc str r0, [r4, #0x1c] */
/* @0x22f7e0 ldr r2, [r7, #0x8] */
/* @0x22f7e4 ldr r2, [r2, r3, lsl #2] */
/* @0x22f7e8 add r3, r3, #1 */
/* @0x22f7ec cmp r2, #0 */
/* @0x22f7f0 ldrgt r1, [r9, r6, lsl #2] */
/* @0x22f7f4 addgt r6, r6, #1 */
/* @0x22f7f8 ldrgt r0, [r4, #0x1c] */
/* @0x22f7fc strbgt r2, [r0, r1] */
/* @0x22f800 ldr r2, [r7, #0x4] */
/* @0x22f804 cmp r2, r3 */
/* @0x22f808 bgt 0x22f7e0 <vorbis_book_init_decode+0x1dc> */
/* @0x22f80c ldr r0, [r4, #0x8] */
/* @0x22f810 bl 0x22eaf0 <_ilog> */
/* @0x22f814 sub r7, r0, #4 */
/* @0x22f818 cmp r7, #4 */
/* @0x22f81c ble 0x22f914 <vorbis_book_init_decode+0x310> */
/* @0x22f820 cmp r7, #8 */
/* @0x22f824 strle r7, [r4, #0x24] */
/* @0x22f828 movle r3, #1 */
/* @0x22f82c movgt r3, #8 */
/* @0x22f830 lslle r3, r3, r7 */
/* @0x22f834 movgt r7, r3 */
/* @0x22f838 movgt r0, #256 */
/* @0x22f83c strle r3, [r11, #-0x30] */
/* @0x22f840 movle r0, r3 */
/* @0x22f844 strgt r0, [r11, #-0x30] */
/* @0x22f848 strgt r3, [r4, #0x24] */
/* @0x22f84c mov r1, #4 */
/* @0x22f850 mov r9, #0 */
/* @0x22f854 bl 0xb6c34 <calloc@plt> */
/* @0x22f858 cmp r6, #0 */
/* @0x22f85c str r9, [r4, #0x28] */
/* @0x22f860 mov r8, r0 */
/* @0x22f864 str r0, [r4, #0x20] */
/* @0x22f868 beq 0x22f938 <vorbis_book_init_decode+0x334> */
/* @0x22f86c ldr r10, [r4, #0x1c] */
/* @0x22f870 mov r3, r9 */
/* @0x22f874 mov r12, #1 */
/* @0x22f878 ldrb r5, [r10, r9] */
/* @0x22f87c cmp r5, r3 */
/* @0x22f880 strgt r5, [r4, #0x28] */
/* @0x22f884 ldrbgt r5, [r10, r9] */
/* @0x22f888 cmp r7, r5 */
/* @0x22f88c blt 0x22f928 <vorbis_book_init_decode+0x324> */
/* @0x22f890 ldr r3, [r4, #0x14] */
/* @0x22f894 ldr r0, [r3, r9, lsl #2] */
/* @0x22f898 str r12, [r11, #-0x48] */
/* @0x22f89c bl 0x22ea70 <res2_inverse+0x25c> */
/* @0x22f8a0 ldr r12, [r11, #-0x48] */
/* @0x22f8a4 rsb r3, r5, r7 */
/* @0x22f8a8 lsl r3, r12, r3 */
/* @0x22f8ac cmp r3, #0 */
/* @0x22f8b0 ble 0x22f928 <vorbis_book_init_decode+0x324> */
/* @0x22f8b4 ldr r2, [r4, #0x24] */
/* @0x22f8b8 add lr, r9, #1 */
/* @0x22f8bc mov r3, #0 */
/* @0x22f8c0 orr r5, r0, r3, lsl r5 */
/* @0x22f8c4 add r3, r3, #1 */
/* @0x22f8c8 mov r7, r2 */
/* @0x22f8cc str lr, [r8, r5, lsl #2] */
/* @0x22f8d0 ldrb r5, [r10, r9] */
/* @0x22f8d4 rsb r1, r5, r2 */
/* @0x22f8d8 cmp r3, r12, lsl r1 */
/* @0x22f8dc blt 0x22f8c0 <vorbis_book_init_decode+0x2bc> */
/* @0x22f8e0 cmp r6, lr */
/* @0x22f8e4 mov r9, lr */
/* @0x22f8e8 ble 0x22f938 <vorbis_book_init_decode+0x334> */
/* @0x22f8ec ldr r3, [r4, #0x28] */
/* @0x22f8f0 b 0x22f878 <vorbis_book_init_decode+0x274> */
/* @0x22f8f4 mov r0, #0 */
/* @0x22f8f8 ldr r12, [r11, #-0x34] */
/* @0x22f8fc ldr r2, [r11, #-0x28] */
/* @0x22f900 ldr r3, [r12] */
/* @0x22f904 cmp r2, r3 */
/* @0x22f908 bne 0x22fa6c <vorbis_book_init_decode+0x468> */
/* @0x22f90c sub sp, r11, #32 */
/* @0x22f910 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22f914 mov r7, #5 */
/* @0x22f918 mov r0, #32 */
/* @0x22f91c str r7, [r4, #0x24] */
/* @0x22f920 str r0, [r11, #-0x30] */
/* @0x22f924 b 0x22f84c <vorbis_book_init_decode+0x248> */
/* @0x22f928 add lr, r9, #1 */
/* @0x22f92c cmp r6, lr */
/* @0x22f930 mov r9, lr */
/* @0x22f934 bgt 0x22f8ec <vorbis_book_init_decode+0x2e8> */
/* @0x22f938 rsb r3, r7, #31 */
/* @0x22f93c mvn r10, #1 */
/* @0x22f940 mov r5, #0 */
/* @0x22f944 lsl r10, r10, r3 */
/* @0x22f948 mov r12, r8 */
/* @0x22f94c mov r9, r5 */
/* @0x22f950 mov r8, r5 */
/* @0x22f954 rsb r7, r7, #32 */
/* @0x22f958 str r12, [r11, #-0x48] */
/* @0x22f95c lsl r7, r8, r7 */
/* @0x22f960 mov r0, r7 */
/* @0x22f964 bl 0x22ea70 <res2_inverse+0x25c> */
/* @0x22f968 ldr r12, [r11, #-0x48] */
/* @0x22f96c ldr r3, [r12, r0, lsl #2] */
/* @0x22f970 cmp r3, #0 */
/* @0x22f974 bne 0x22fa14 <vorbis_book_init_decode+0x410> */
/* @0x22f978 add r3, r9, #1 */
/* @0x22f97c lsl r2, r3, #2 */
/* @0x22f980 b 0x22f9a0 <vorbis_book_init_decode+0x39c> */
/* @0x22f984 ldr r1, [r4, #0x14] */
/* @0x22f988 ldr r1, [r1, r2] */
/* @0x22f98c add r2, r2, #4 */
/* @0x22f990 cmp r7, r1 */
/* @0x22f994 blo 0x22f9a8 <vorbis_book_init_decode+0x3a4> */
/* @0x22f998 mov r9, r3 */
/* @0x22f99c add r3, r3, #1 */
/* @0x22f9a0 cmp r3, r6 */
/* @0x22f9a4 blt 0x22f984 <vorbis_book_init_decode+0x380> */
/* @0x22f9a8 cmp r6, r5 */
/* @0x22f9ac ble 0x22f9e8 <vorbis_book_init_decode+0x3e4> */
/* @0x22f9b0 ldr r2, [r4, #0x14] */
/* @0x22f9b4 add r3, r2, r5, lsl #2 */
/* @0x22f9b8 ldr r2, [r2, r5, lsl #2] */
/* @0x22f9bc and r2, r10, r2 */
/* @0x22f9c0 cmp r7, r2 */
/* @0x22f9c4 bhs 0x22f9dc <vorbis_book_init_decode+0x3d8> */
/* @0x22f9c8 b 0x22f9e8 <vorbis_book_init_decode+0x3e4> */
/* @0x22f9cc ldr r2, [r3, #0x4]! */
/* @0x22f9d0 and r2, r2, r10 */
/* @0x22f9d4 cmp r7, r2 */
/* @0x22f9d8 blo 0x22f9e8 <vorbis_book_init_decode+0x3e4> */
/* @0x22f9dc add r5, r5, #1 */
/* @0x22f9e0 cmp r5, r6 */
/* @0x22f9e4 bne 0x22f9cc <vorbis_book_init_decode+0x3c8> */
/* @0x22f9e8 movw r2, #0x7fff */
/* @0x22f9ec cmp r9, r2 */
/* @0x22f9f0 movlo r2, r9 */
/* @0x22f9f4 rsb r3, r5, r6 */
/* @0x22f9f8 movw r1, #0x7fff */
/* @0x22f9fc lsl r2, r2, #15 */
/* @0x22fa00 orr r2, r2, #-2147483648 */
/* @0x22fa04 cmp r3, r1 */
/* @0x22fa08 orrls r3, r2, r3 */
/* @0x22fa0c orrhi r3, r2, r1 */
/* @0x22fa10 str r3, [r12, r0, lsl #2] */
/* @0x22fa14 ldr r2, [r11, #-0x30] */
/* @0x22fa18 add r8, r8, #1 */
/* @0x22fa1c cmp r8, r2 */
/* @0x22fa20 beq 0x22f8f4 <vorbis_book_init_decode+0x2f0> */
/* @0x22fa24 ldr r7, [r4, #0x24] */
/* @0x22fa28 b 0x22f954 <vorbis_book_init_decode+0x350> */
/* @0x22fa2c ldr r2, [r7] */
/* @0x22fa30 mov r3, #0 */
/* @0x22fa34 str r1, [r4, #0x4] */
/* @0x22fa38 mov r0, r3 */
/* @0x22fa3c str r3, [r4, #0x8] */
/* @0x22fa40 str r2, [r4] */
/* @0x22fa44 b 0x22f8f8 <vorbis_book_init_decode+0x2f4> */
/* @0x22fa48 mov r0, #0 */
/* @0x22fa4c mov r6, r0 */
/* @0x22fa50 bl 0xb6544 <malloc@plt> */
/* @0x22fa54 str r0, [r4, #0x1c] */
/* @0x22fa58 b 0x22f80c <vorbis_book_init_decode+0x208> */
/* @0x22fa5c mov r0, r4 */
/* @0x22fa60 bl 0x22f598 <vorbis_book_clear> */
/* @0x22fa64 mvn r0, #0 */
/* @0x22fa68 b 0x22f8f8 <vorbis_book_init_decode+0x2f4> */
/* @0x22fa6c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x22fa70 andseq lr, r11, r8, lsr r3 */
/* @0x22fa74 .word 0xfffff3d0 */

/* ── FUNC 0x22fa78 · anon_22fa78 · size=500 · insn=125 */
/* @0x22fa78 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x22fa7c subs r11, r0, #0 */
/* @0x22fa80 sub sp, sp, #12 */
/* @0x22fa84 mov r5, r1 */
/* @0x22fa88 mov r7, r2 */
/* @0x22fa8c beq 0x22fba8 <vorbis_book_init_decode+0x5a4> */
/* @0x22fa90 ldr r2, [r11, #0x40] */
/* @0x22fa94 cmp r2, #0 */
/* @0x22fa98 beq 0x22fc58 <vorbis_book_init_decode+0x654> */
/* @0x22fa9c ldr r6, [r2, #0x4] */
/* @0x22faa0 ldr r10, [r2, #0x48] */
/* @0x22faa4 cmp r6, #0 */
/* @0x22faa8 moveq r9, r6 */
/* @0x22faac ldrne r9, [r6, #0x1c] */
/* @0x22fab0 cmp r2, #0 */
/* @0x22fab4 cmpne r10, #0 */
/* @0x22fab8 add r4, r11, #4 */
/* @0x22fabc beq 0x22fba8 <vorbis_book_init_decode+0x5a4> */
/* @0x22fac0 cmp r9, #0 */
/* @0x22fac4 cmpne r6, #0 */
/* @0x22fac8 beq 0x22fba8 <vorbis_book_init_decode+0x5a4> */
/* @0x22facc cmp r4, #0 */
/* @0x22fad0 beq 0x22fba8 <vorbis_book_init_decode+0x5a4> */
/* @0x22fad4 mov r0, r11 */
/* @0x22fad8 bl 0x227164 <_vorbis_block_ripcord> */
/* @0x22fadc ldm r5, {r1, r2} */
/* @0x22fae0 mov r0, r4 */
/* @0x22fae4 bl 0x23385c <oggpack_readinit> */
/* @0x22fae8 mov r0, r4 */
/* @0x22faec mov r1, #1 */
/* @0x22faf0 bl 0x233b28 <oggpack_read> */
/* @0x22faf4 cmp r0, #0 */
/* @0x22faf8 bne 0x22fc50 <vorbis_book_init_decode+0x64c> */
/* @0x22fafc mov r0, r4 */
/* @0x22fb00 ldr r1, [r10, #0x8] */
/* @0x22fb04 bl 0x233b28 <oggpack_read> */
/* @0x22fb08 cmn r0, #1 */
/* @0x22fb0c mov r8, r0 */
/* @0x22fb10 beq 0x22fba8 <vorbis_book_init_decode+0x5a4> */
/* @0x22fb14 add r2, r9, r0, lsl #2 */
/* @0x22fb18 str r2, [sp, #0x4] */
/* @0x22fb1c str r0, [r11, #0x28] */
/* @0x22fb20 ldr r2, [r2, #0x20] */
/* @0x22fb24 cmp r2, #0 */
/* @0x22fb28 beq 0x22fba8 <vorbis_book_init_decode+0x5a4> */
/* @0x22fb2c ldr r2, [r2] */
/* @0x22fb30 cmp r2, #0 */
/* @0x22fb34 str r2, [r11, #0x1c] */
/* @0x22fb38 streq r2, [r11, #0x18] */
/* @0x22fb3c streq r2, [r11, #0x20] */
/* @0x22fb40 bne 0x22fb80 <vorbis_book_init_decode+0x57c> */
/* @0x22fb44 ldrd r2, r3, [r5, #16] */
/* @0x22fb48 ldrd r0, r1, [r5, #24] */
/* @0x22fb4c strd r2, r3, [r11, #48] */
/* @0x22fb50 subs r4, r0, #3 */
/* @0x22fb54 ldr r2, [r5, #0xc] */
/* @0x22fb58 sbc r5, r1, #0 */
/* @0x22fb5c cmp r7, #0 */
/* @0x22fb60 strd r4, r5, [r11, #56] */
/* @0x22fb64 streq r7, [r11, #0x24] */
/* @0x22fb68 str r2, [r11, #0x2c] */
/* @0x22fb6c moveq r0, r7 */
/* @0x22fb70 streq r7, [r11] */
/* @0x22fb74 bne 0x22fbb4 <vorbis_book_init_decode+0x5b0> */
/* @0x22fb78 add sp, sp, #12 */
/* @0x22fb7c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22fb80 mov r1, #1 */
/* @0x22fb84 mov r0, r4 */
/* @0x22fb88 bl 0x233b28 <oggpack_read> */
/* @0x22fb8c mov r1, #1 */
/* @0x22fb90 str r0, [r11, #0x18] */
/* @0x22fb94 mov r0, r4 */
/* @0x22fb98 bl 0x233b28 <oggpack_read> */
/* @0x22fb9c cmn r0, #1 */
/* @0x22fba0 str r0, [r11, #0x20] */
/* @0x22fba4 bne 0x22fb44 <vorbis_book_init_decode+0x540> */
/* @0x22fba8 mvn r0, #135 */
/* @0x22fbac add sp, sp, #12 */
/* @0x22fbb0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22fbb4 ldr r2, [r11, #0x1c] */
/* @0x22fbb8 mov r0, r11 */
/* @0x22fbbc ldr r1, [r6, #0x4] */
/* @0x22fbc0 ldr r2, [r9, r2, lsl #2] */
/* @0x22fbc4 lsl r1, r1, #2 */
/* @0x22fbc8 str r2, [r11, #0x24] */
/* @0x22fbcc bl 0x2270e4 <_vorbis_block_alloc> */
/* @0x22fbd0 ldr r2, [r6, #0x4] */
/* @0x22fbd4 cmp r2, #0 */
/* @0x22fbd8 movgt r4, #0 */
/* @0x22fbdc str r0, [r11] */
/* @0x22fbe0 movgt r5, r0 */
/* @0x22fbe4 bgt 0x22fbf0 <vorbis_book_init_decode+0x5ec> */
/* @0x22fbe8 b 0x22fc14 <vorbis_book_init_decode+0x610> */
/* @0x22fbec ldr r5, [r11] */
/* @0x22fbf0 ldr r1, [r11, #0x24] */
/* @0x22fbf4 mov r0, r11 */
/* @0x22fbf8 lsl r1, r1, #2 */
/* @0x22fbfc bl 0x2270e4 <_vorbis_block_alloc> */
/* @0x22fc00 ldr r2, [r6, #0x4] */
/* @0x22fc04 str r0, [r5, r4, lsl #2] */
/* @0x22fc08 add r4, r4, #1 */
/* @0x22fc0c cmp r2, r4 */
/* @0x22fc10 bgt 0x22fbec <vorbis_book_init_decode+0x5e8> */
/* @0x22fc14 ldr r3, [sp, #0x4] */
/* @0x22fc18 mov r0, r11 */
/* @0x22fc1c ldr r1, [r10, #0xc] */
/* @0x22fc20 ldr r2, [r3, #0x20] */
/* @0x22fc24 ldr r3, [pc, #0x3c] */
/* @0x22fc28 ldr r1, [r1, r8, lsl #2] */
/* @0x22fc2c ldr r2, [r2, #0xc] */
/* @0x22fc30 ldr r3, [pc, r3] */
/* @0x22fc34 add r2, r2, #72 */
/* @0x22fc38 ldr r2, [r9, r2, lsl #2] */
/* @0x22fc3c ldr r3, [r3, r2, lsl #2] */
/* @0x22fc40 ldr r3, [r3, #0x10] */
/* @0x22fc44 blx r3 */
/* @0x22fc48 add sp, sp, #12 */
/* @0x22fc4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22fc50 mvn r0, #134 */
/* @0x22fc54 b 0x22fb78 <vorbis_book_init_decode+0x574> */
/* @0x22fc58 mov r10, r2 */
/* @0x22fc5c mov r6, r2 */
/* @0x22fc60 mov r9, r2 */
/* @0x22fc64 b 0x22fab0 <vorbis_book_init_decode+0x4ac> */
/* @0x22fc68 andseq r1, r12, r0, asr r8 */

/* ── FUNC 0x22fc6c · vorbis_synthesis · size=8 · insn=2 */
/* @0x22fc6c mov r2, #1 */
/* @0x22fc70 b 0x22fa78 <vorbis_book_init_decode+0x474> */

/* ── FUNC 0x22fc74 · vorbis_synthesis_trackonly · size=8 · insn=2 */
/* @0x22fc74 mov r2, #0 */
/* @0x22fc78 b 0x22fa78 <vorbis_book_init_decode+0x474> */

/* ── FUNC 0x22fc7c · vorbis_packet_blocksize · size=144 · insn=36 */
/* @0x22fc7c push {r4, r5, lr} */
/* @0x22fc80 sub sp, sp, #28 */
/* @0x22fc84 add r4, sp, #4 */
/* @0x22fc88 mov r3, r1 */
/* @0x22fc8c ldr r5, [r0, #0x1c] */
/* @0x22fc90 ldr r1, [r1] */
/* @0x22fc94 mov r0, r4 */
/* @0x22fc98 ldr r2, [r3, #0x4] */
/* @0x22fc9c bl 0x23385c <oggpack_readinit> */
/* @0x22fca0 mov r0, r4 */
/* @0x22fca4 mov r1, #1 */
/* @0x22fca8 bl 0x233b28 <oggpack_read> */
/* @0x22fcac cmp r0, #0 */
/* @0x22fcb0 bne 0x22fcfc <vorbis_packet_blocksize+0x80> */
/* @0x22fcb4 ldr r3, [r5, #0x8] */
/* @0x22fcb8 mov r1, r0 */
/* @0x22fcbc cmp r3, #1 */
/* @0x22fcc0 ble 0x22fcd4 <vorbis_packet_blocksize+0x58> */
/* @0x22fcc4 asr r3, r3, #1 */
/* @0x22fcc8 add r1, r1, #1 */
/* @0x22fccc cmp r3, #1 */
/* @0x22fcd0 bgt 0x22fcc4 <vorbis_packet_blocksize+0x48> */
/* @0x22fcd4 mov r0, r4 */
/* @0x22fcd8 bl 0x233b28 <oggpack_read> */
/* @0x22fcdc cmn r0, #1 */
/* @0x22fce0 beq 0x22fd04 <vorbis_packet_blocksize+0x88> */
/* @0x22fce4 add r0, r0, #8 */
/* @0x22fce8 ldr r3, [r5, r0, lsl #2] */
/* @0x22fcec ldr r3, [r3] */
/* @0x22fcf0 ldr r0, [r5, r3, lsl #2] */
/* @0x22fcf4 add sp, sp, #28 */
/* @0x22fcf8 pop {r4, r5, pc} */
/* @0x22fcfc mvn r0, #134 */
/* @0x22fd00 b 0x22fcf4 <vorbis_packet_blocksize+0x78> */
/* @0x22fd04 mvn r0, #135 */
/* @0x22fd08 b 0x22fcf4 <vorbis_packet_blocksize+0x78> */

/* ── FUNC 0x22fd0c · anon_22fd0c · size=4536 · insn=1134 */
/* @0x22fd0c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x22fd10 mov r4, r2 */
/* @0x22fd14 mov r5, r3 */
/* @0x22fd18 cmp r4, #1 */
/* @0x22fd1c sbcs r3, r5, #0 */
/* @0x22fd20 mov r6, r0 */
/* @0x22fd24 mov r8, r1 */
/* @0x22fd28 blt 0x22fd38 <vorbis_packet_blocksize+0xbc> */
/* @0x22fd2c ldrd r2, r3, [r0, #8] */
/* @0x22fd30 adds r4, r4, r2 */
/* @0x22fd34 adc r5, r5, r3 */
/* @0x22fd38 cmp r4, #1 */
/* @0x22fd3c sbcs r1, r5, #0 */
/* @0x22fd40 add r7, r6, #24 */
/* @0x22fd44 blt 0x22fdf0 <vorbis_packet_blocksize+0x174> */
/* @0x22fd48 ldrd r2, r3, [r6, #8] */
/* @0x22fd4c cmp r2, r4 */
/* @0x22fd50 sbcs r1, r3, r5 */
/* @0x22fd54 bge 0x22fe7c <vorbis_packet_blocksize+0x200> */
/* @0x22fd58 mov r0, r7 */
/* @0x22fd5c mov r1, r8 */
/* @0x22fd60 bl 0x234c90 <ogg_sync_pageseek> */
/* @0x22fd64 subs r9, r0, #0 */
/* @0x22fd68 blt 0x22fe88 <vorbis_packet_blocksize+0x20c> */
/* @0x22fd6c bne 0x22feb8 <vorbis_packet_blocksize+0x23c> */
/* @0x22fd70 orrs r3, r4, r5 */
/* @0x22fd74 beq 0x22fe7c <vorbis_packet_blocksize+0x200> */
/* @0x22fd78 bl 0xb6bf8 <__errno@plt> */
/* @0x22fd7c ldr r3, [r6, #0x288] */
/* @0x22fd80 cmp r3, #0 */
/* @0x22fd84 str r9, [r0] */
/* @0x22fd88 beq 0x22fea0 <vorbis_packet_blocksize+0x224> */
/* @0x22fd8c ldr r3, [r6] */
/* @0x22fd90 cmp r3, #0 */
/* @0x22fd94 beq 0x22fdd4 <vorbis_packet_blocksize+0x158> */
/* @0x22fd98 mov r1, #32768 */
/* @0x22fd9c mov r0, r7 */
/* @0x22fda0 bl 0x234b8c <ogg_sync_buffer> */
/* @0x22fda4 mov r1, #1 */
/* @0x22fda8 ldr r12, [r6, #0x288] */
/* @0x22fdac mov r2, #32768 */
/* @0x22fdb0 ldr r3, [r6] */
/* @0x22fdb4 blx r12 */
/* @0x22fdb8 subs r1, r0, #0 */
/* @0x22fdbc bgt 0x22fe64 <vorbis_packet_blocksize+0x1e8> */
/* @0x22fdc0 bne 0x22fe9c <vorbis_packet_blocksize+0x220> */
/* @0x22fdc4 bl 0xb6bf8 <__errno@plt> */
/* @0x22fdc8 ldr r3, [r0] */
/* @0x22fdcc cmp r3, #0 */
/* @0x22fdd0 bne 0x22fea0 <vorbis_packet_blocksize+0x224> */
/* @0x22fdd4 mvn r0, #1 */
/* @0x22fdd8 mvn r1, #0 */
/* @0x22fddc pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x22fde0 ldrd r2, r3, [r6, #8] */
/* @0x22fde4 subs r2, r2, r9 */
/* @0x22fde8 sbc r3, r3, r9, asr #31 */
/* @0x22fdec strd r2, r3, [r6, #8] */
/* @0x22fdf0 mov r0, r7 */
/* @0x22fdf4 mov r1, r8 */
/* @0x22fdf8 bl 0x234c90 <ogg_sync_pageseek> */
/* @0x22fdfc subs r9, r0, #0 */
/* @0x22fe00 blt 0x22fde0 <vorbis_packet_blocksize+0x164> */
/* @0x22fe04 bne 0x22feb8 <vorbis_packet_blocksize+0x23c> */
/* @0x22fe08 orrs r3, r4, r5 */
/* @0x22fe0c beq 0x22fe7c <vorbis_packet_blocksize+0x200> */
/* @0x22fe10 bl 0xb6bf8 <__errno@plt> */
/* @0x22fe14 ldr r3, [r6, #0x288] */
/* @0x22fe18 cmp r3, #0 */
/* @0x22fe1c str r9, [r0] */
/* @0x22fe20 beq 0x22fea0 <vorbis_packet_blocksize+0x224> */
/* @0x22fe24 ldr r3, [r6] */
/* @0x22fe28 cmp r3, #0 */
/* @0x22fe2c beq 0x22fdd4 <vorbis_packet_blocksize+0x158> */
/* @0x22fe30 mov r1, #32768 */
/* @0x22fe34 mov r0, r7 */
/* @0x22fe38 bl 0x234b8c <ogg_sync_buffer> */
/* @0x22fe3c mov r1, #1 */
/* @0x22fe40 ldr r12, [r6, #0x288] */
/* @0x22fe44 mov r2, #32768 */
/* @0x22fe48 ldr r3, [r6] */
/* @0x22fe4c blx r12 */
/* @0x22fe50 subs r1, r0, #0 */
/* @0x22fe54 ble 0x22feac <vorbis_packet_blocksize+0x230> */
/* @0x22fe58 mov r0, r7 */
/* @0x22fe5c bl 0x234c54 <ogg_sync_wrote> */
/* @0x22fe60 b 0x22fdf0 <vorbis_packet_blocksize+0x174> */
/* @0x22fe64 mov r0, r7 */
/* @0x22fe68 bl 0x234c54 <ogg_sync_wrote> */
/* @0x22fe6c ldrd r2, r3, [r6, #8] */
/* @0x22fe70 cmp r2, r4 */
/* @0x22fe74 sbcs r1, r3, r5 */
/* @0x22fe78 blt 0x22fd58 <vorbis_packet_blocksize+0xdc> */
/* @0x22fe7c mvn r0, #0 */
/* @0x22fe80 mov r1, r0 */
/* @0x22fe84 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x22fe88 ldrd r2, r3, [r6, #8] */
/* @0x22fe8c subs r2, r2, r9 */
/* @0x22fe90 sbc r3, r3, r9, asr #31 */
/* @0x22fe94 strd r2, r3, [r6, #8] */
/* @0x22fe98 b 0x22fd48 <vorbis_packet_blocksize+0xcc> */
/* @0x22fe9c bge 0x22fd48 <vorbis_packet_blocksize+0xcc> */
/* @0x22fea0 mvn r0, #127 */
/* @0x22fea4 mvn r1, #0 */
/* @0x22fea8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x22feac beq 0x22fdc4 <vorbis_packet_blocksize+0x148> */
/* @0x22feb0 bge 0x22fdf0 <vorbis_packet_blocksize+0x174> */
/* @0x22feb4 b 0x22fea0 <vorbis_packet_blocksize+0x224> */
/* @0x22feb8 ldrd r2, r3, [r6, #8] */
/* @0x22febc adds r0, r2, r9 */
/* @0x22fec0 adc r1, r3, r9, asr #31 */
/* @0x22fec4 strd r0, r1, [r6, #8] */
/* @0x22fec8 mov r0, r2 */
/* @0x22fecc mov r1, r3 */
/* @0x22fed0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x22fed4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x22fed8 sub sp, sp, #60 */
/* @0x22fedc ldr r8, [r0, #0x1c8] */
/* @0x22fee0 add r5, r0, #120 */
/* @0x22fee4 add r4, sp, #8 */
/* @0x22fee8 add r6, sp, #24 */
/* @0x22feec mov r7, r0 */
/* @0x22fef0 mov r10, #0 */
/* @0x22fef4 mov r11, #0 */
/* @0x22fef8 mvn r9, #0 */
/* @0x22fefc str r1, [sp, #0x4] */
/* @0x22ff00 mvn r2, #0 */
/* @0x22ff04 mov r0, r7 */
/* @0x22ff08 mov r1, r4 */
/* @0x22ff0c mvn r3, #0 */
/* @0x22ff10 bl 0x22fd0c <vorbis_packet_blocksize+0x90> */
/* @0x22ff14 cmp r0, #0 */
/* @0x22ff18 sbcs r2, r1, #0 */
/* @0x22ff1c blt 0x22ff94 <vorbis_packet_blocksize+0x318> */
/* @0x22ff20 mov r0, r4 */
/* @0x22ff24 bl 0x233f90 <ogg_page_bos> */
/* @0x22ff28 cmp r0, #0 */
/* @0x22ff2c bne 0x22ff94 <vorbis_packet_blocksize+0x318> */
/* @0x22ff30 mov r0, r4 */
/* @0x22ff34 bl 0x23409c <ogg_page_serialno> */
/* @0x22ff38 cmp r0, r8 */
/* @0x22ff3c bne 0x22ff00 <vorbis_packet_blocksize+0x284> */
/* @0x22ff40 mov r0, r5 */
/* @0x22ff44 mov r1, r4 */
/* @0x22ff48 bl 0x234eac <ogg_stream_pagein> */
/* @0x22ff4c b 0x22ff54 <vorbis_packet_blocksize+0x2d8> */
/* @0x22ff50 bgt 0x22ffb4 <vorbis_packet_blocksize+0x338> */
/* @0x22ff54 mov r0, r5 */
/* @0x22ff58 mov r1, r6 */
/* @0x22ff5c bl 0x235328 <ogg_stream_packetout> */
/* @0x22ff60 cmp r0, #0 */
/* @0x22ff64 bne 0x22ff50 <vorbis_packet_blocksize+0x2d4> */
/* @0x22ff68 mov r0, r4 */
/* @0x22ff6c bl 0x233fb0 <ogg_page_granulepos> */
/* @0x22ff70 mvn r2, #0 */
/* @0x22ff74 mvn r3, #0 */
/* @0x22ff78 cmp r1, r3 */
/* @0x22ff7c cmpeq r0, r2 */
/* @0x22ff80 beq 0x22ff00 <vorbis_packet_blocksize+0x284> */
/* @0x22ff84 mov r0, r4 */
/* @0x22ff88 bl 0x233fb0 <ogg_page_granulepos> */
/* @0x22ff8c subs r10, r0, r10 */
/* @0x22ff90 sbc r11, r1, r11 */
/* @0x22ff94 mov r0, r10 */
/* @0x22ff98 mov r1, r11 */
/* @0x22ff9c cmp r0, #0 */
/* @0x22ffa0 sbcs r3, r1, #0 */
/* @0x22ffa4 movlt r0, #0 */
/* @0x22ffa8 movlt r1, #0 */
/* @0x22ffac add sp, sp, #60 */
/* @0x22ffb0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22ffb4 ldr r0, [sp, #0x4] */
/* @0x22ffb8 mov r1, r6 */
/* @0x22ffbc bl 0x22fc7c <vorbis_packet_blocksize> */
/* @0x22ffc0 cmn r9, #1 */
/* @0x22ffc4 add r3, r9, r0 */
/* @0x22ffc8 mov r9, r0 */
/* @0x22ffcc asr r3, r3, #2 */
/* @0x22ffd0 beq 0x22ff54 <vorbis_packet_blocksize+0x2d8> */
/* @0x22ffd4 adds r10, r10, r3 */
/* @0x22ffd8 adc r11, r11, r3, asr #31 */
/* @0x22ffdc b 0x22ff54 <vorbis_packet_blocksize+0x2d8> */
/* @0x22ffe0 push {r4, r5, r6, r7, lr} */
/* @0x22ffe4 mov r6, r0 */
/* @0x22ffe8 ldr r0, [r0] */
/* @0x22ffec sub sp, sp, #12 */
/* @0x22fff0 mov r4, r2 */
/* @0x22fff4 mov r5, r3 */
/* @0x22fff8 cmp r0, #0 */
/* @0x22fffc beq 0x230040 <vorbis_packet_blocksize+0x3c4> */
/* @0x230000 ldr r1, [r6, #0x28c] */
/* @0x230004 cmp r1, #0 */
/* @0x230008 beq 0x230038 <vorbis_packet_blocksize+0x3bc> */
/* @0x23000c mov r7, #0 */
/* @0x230010 str r7, [sp] */
/* @0x230014 blx r1 */
/* @0x230018 cmn r0, #1 */
/* @0x23001c beq 0x230038 <vorbis_packet_blocksize+0x3bc> */
/* @0x230020 strd r4, r5, [r6, #8] */
/* @0x230024 add r0, r6, #24 */
/* @0x230028 bl 0x235268 <ogg_sync_reset> */
/* @0x23002c mov r0, r7 */
/* @0x230030 add sp, sp, #12 */
/* @0x230034 pop {r4, r5, r6, r7, pc} */
/* @0x230038 mvn r0, #127 */
/* @0x23003c b 0x230030 <vorbis_packet_blocksize+0x3b4> */
/* @0x230040 mvn r0, #128 */
/* @0x230044 b 0x230030 <vorbis_packet_blocksize+0x3b4> */
/* @0x230048 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x23004c sub sp, sp, #84 */
/* @0x230050 ldrd r4, r5, [r0, #8] */
/* @0x230054 mvn r10, #0 */
/* @0x230058 add r6, sp, #64 */
/* @0x23005c add r9, r2, r10 */
/* @0x230060 mov r8, r0 */
/* @0x230064 mov r7, r1 */
/* @0x230068 mov r11, r3 */
/* @0x23006c strd r4, r5, [sp, #16] */
/* @0x230070 str r2, [sp, #0x2c] */
/* @0x230074 str r10, [sp, #0x18] */
/* @0x230078 str r10, [sp, #0x20] */
/* @0x23007c str r10, [sp, #0x38] */
/* @0x230080 strd r4, r5, [sp, #48] */
/* @0x230084 str r10, [sp, #0x28] */
/* @0x230088 str r10, [sp, #0x1c] */
/* @0x23008c str r10, [sp, #0x24] */
/* @0x230090 str r10, [sp, #0x3c] */
/* @0x230094 ldrd r4, r5, [sp, #48] */
/* @0x230098 mov r0, r8 */
/* @0x23009c subs r4, r4, #32768 */
/* @0x2300a0 sbc r5, r5, #0 */
/* @0x2300a4 strd r4, r5, [sp, #48] */
/* @0x2300a8 cmp r4, #0 */
/* @0x2300ac sbcs r5, r5, #0 */
/* @0x2300b0 movlt r4, #0 */
/* @0x2300b4 movlt r5, #0 */
/* @0x2300b8 strdlt r4, r5, [sp, #48] */
/* @0x2300bc ldrd r2, r3, [sp, #48] */
/* @0x2300c0 bl 0x22ffe0 <vorbis_packet_blocksize+0x364> */
/* @0x2300c4 asr r1, r0, #31 */
/* @0x2300c8 orrs r5, r0, r1 */
/* @0x2300cc bne 0x230238 <vorbis_packet_blocksize+0x5bc> */
/* @0x2300d0 mvn r4, #0 */
/* @0x2300d4 mvn r5, #0 */
/* @0x2300d8 str r11, [sp, #0x4] */
/* @0x2300dc ldrd r2, r3, [r8, #8] */
/* @0x2300e0 ldrd r0, r1, [sp, #16] */
/* @0x2300e4 cmp r2, r0 */
/* @0x2300e8 sbcs r1, r3, r1 */
/* @0x2300ec bge 0x230204 <vorbis_packet_blocksize+0x588> */
/* @0x2300f0 ldrd r0, r1, [sp, #16] */
/* @0x2300f4 subs r2, r0, r2 */
/* @0x2300f8 sbc r3, r1, r3 */
/* @0x2300fc mov r0, r8 */
/* @0x230100 mov r1, r6 */
/* @0x230104 bl 0x22fd0c <vorbis_packet_blocksize+0x90> */
/* @0x230108 mov r2, r0 */
/* @0x23010c mov r3, r1 */
/* @0x230110 mvn r0, #127 */
/* @0x230114 mvn r1, #0 */
/* @0x230118 cmp r3, r1 */
/* @0x23011c cmpeq r2, r0 */
/* @0x230120 beq 0x230240 <vorbis_packet_blocksize+0x5c4> */
/* @0x230124 cmp r2, #0 */
/* @0x230128 sbcs r1, r3, #0 */
/* @0x23012c blt 0x230204 <vorbis_packet_blocksize+0x588> */
/* @0x230130 mov r0, r6 */
/* @0x230134 str r2, [sp, #0xc] */
/* @0x230138 str r3, [sp, #0x8] */
/* @0x23013c bl 0x23409c <ogg_page_serialno> */
/* @0x230140 mov r4, r0 */
/* @0x230144 mov r0, r6 */
/* @0x230148 asr r11, r4, #31 */
/* @0x23014c mov r10, r4 */
/* @0x230150 strd r10, r11, [sp, #24] */
/* @0x230154 bl 0x233fb0 <ogg_page_granulepos> */
/* @0x230158 ldr r5, [sp, #0x4] */
/* @0x23015c ldr r2, [sp, #0xc] */
/* @0x230160 ldr r3, [sp, #0x8] */
/* @0x230164 str r1, [sp, #0x28] */
/* @0x230168 mov r10, r0 */
/* @0x23016c ldr r1, [r5] */
/* @0x230170 cmp r4, r1 */
/* @0x230174 strdeq r2, r3, [sp, #32] */
/* @0x230178 ldreq r11, [sp, #0x78] */
/* @0x23017c ldreq r5, [sp, #0x28] */
/* @0x230180 streq r10, [r11] */
/* @0x230184 streq r5, [r11, #0x4] */
/* @0x230188 cmp r7, #0 */
/* @0x23018c beq 0x2301f4 <vorbis_packet_blocksize+0x578> */
/* @0x230190 ldr r11, [sp, #0x2c] */
/* @0x230194 cmp r11, #0 */
/* @0x230198 beq 0x2301f4 <vorbis_packet_blocksize+0x578> */
/* @0x23019c ldr r1, [r7] */
/* @0x2301a0 cmp r4, r1 */
/* @0x2301a4 beq 0x2301e0 <vorbis_packet_blocksize+0x564> */
/* @0x2301a8 mov r0, r7 */
/* @0x2301ac mov r1, #0 */
/* @0x2301b0 ldr r11, [sp, #0x4] */
/* @0x2301b4 b 0x2301c4 <vorbis_packet_blocksize+0x548> */
/* @0x2301b8 ldr r12, [r0, #0x4]! */
/* @0x2301bc cmp r4, r12 */
/* @0x2301c0 beq 0x2301ec <vorbis_packet_blocksize+0x570> */
/* @0x2301c4 cmp r1, r9 */
/* @0x2301c8 add r1, r1, #1 */
/* @0x2301cc bne 0x2301b8 <vorbis_packet_blocksize+0x53c> */
/* @0x2301d0 mvn r4, #0 */
/* @0x2301d4 mvn r5, #0 */
/* @0x2301d8 str r11, [sp, #0x4] */
/* @0x2301dc strd r4, r5, [sp, #32] */
/* @0x2301e0 mov r4, r2 */
/* @0x2301e4 mov r5, r3 */
/* @0x2301e8 b 0x2300dc <vorbis_packet_blocksize+0x460> */
/* @0x2301ec str r11, [sp, #0x4] */
/* @0x2301f0 b 0x2301e0 <vorbis_packet_blocksize+0x564> */
/* @0x2301f4 mvn r4, #0 */
/* @0x2301f8 mvn r5, #0 */
/* @0x2301fc strd r4, r5, [sp, #32] */
/* @0x230200 b 0x2301e0 <vorbis_packet_blocksize+0x564> */
/* @0x230204 ldrd r2, r3, [sp, #56] */
/* @0x230208 ldr r11, [sp, #0x4] */
/* @0x23020c cmp r5, r3 */
/* @0x230210 cmpeq r4, r2 */
/* @0x230214 mvn r2, #0 */
/* @0x230218 mvn r3, #0 */
/* @0x23021c beq 0x230094 <vorbis_packet_blocksize+0x418> */
/* @0x230220 ldrd r0, r1, [sp, #32] */
/* @0x230224 cmp r1, r3 */
/* @0x230228 cmpeq r0, r2 */
/* @0x23022c beq 0x230250 <vorbis_packet_blocksize+0x5d4> */
/* @0x230230 ldr r0, [sp, #0x20] */
/* @0x230234 ldr r1, [sp, #0x24] */
/* @0x230238 add sp, sp, #84 */
/* @0x23023c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x230240 mov r0, r2 */
/* @0x230244 mov r1, r3 */
/* @0x230248 add sp, sp, #84 */
/* @0x23024c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x230250 ldr r2, [sp, #0x18] */
/* @0x230254 mov r0, r4 */
/* @0x230258 ldr r4, [sp, #0x28] */
/* @0x23025c mov r1, r5 */
/* @0x230260 str r2, [r11] */
/* @0x230264 ldr r11, [sp, #0x78] */
/* @0x230268 str r10, [r11] */
/* @0x23026c str r4, [r11, #0x4] */
/* @0x230270 b 0x230238 <vorbis_packet_blocksize+0x5bc> */
/* @0x230274 cmp r0, #0 */
/* @0x230278 ldr r3, [sp] */
/* @0x23027c beq 0x23028c <vorbis_packet_blocksize+0x610> */
/* @0x230280 mov r1, r2 */
/* @0x230284 mov r2, r3 */
/* @0x230288 b 0xb68d4 <fseek@plt> */
/* @0x23028c mvn r0, #0 */
/* @0x230290 bx lr */
/* @0x230294 push {r3, r4, r5, lr} */
/* @0x230298 mov r4, r0 */
/* @0x23029c ldr r3, [r0, #0x58] */
/* @0x2302a0 cmp r3, #3 */
/* @0x2302a4 bgt 0x230324 <vorbis_packet_blocksize+0x6a8> */
/* @0x2302a8 bne 0x23032c <vorbis_packet_blocksize+0x6b0> */
/* @0x2302ac ldr r3, [r0, #0x4] */
/* @0x2302b0 cmp r3, #0 */
/* @0x2302b4 bne 0x2302fc <vorbis_packet_blocksize+0x680> */
/* @0x2302b8 add r5, r0, #480 */
/* @0x2302bc ldr r1, [r0, #0x48] */
/* @0x2302c0 mov r0, r5 */
/* @0x2302c4 bl 0x2273d0 <vorbis_synthesis_init> */
/* @0x2302c8 cmp r0, #0 */
/* @0x2302cc bne 0x23031c <vorbis_packet_blocksize+0x6a0> */
/* @0x2302d0 add r1, r4, #560 */
/* @0x2302d4 mov r0, r5 */
/* @0x2302d8 bl 0x2270bc <vorbis_block_init> */
/* @0x2302dc mov r2, #0 */
/* @0x2302e0 mov r3, #0 */
/* @0x2302e4 mov r1, #4 */
/* @0x2302e8 strd r2, r3, [r4, #104] */
/* @0x2302ec mov r0, #0 */
/* @0x2302f0 str r1, [r4, #0x58] */
/* @0x2302f4 strd r2, r3, [r4, #112] */
/* @0x2302f8 pop {r3, r4, r5, pc} */
/* @0x2302fc ldr r1, [r0, #0x60] */
/* @0x230300 add r5, r0, #480 */
/* @0x230304 ldr r3, [r0, #0x48] */
/* @0x230308 mov r0, r5 */
/* @0x23030c add r1, r3, r1, lsl #5 */
/* @0x230310 bl 0x2273d0 <vorbis_synthesis_init> */
/* @0x230314 cmp r0, #0 */
/* @0x230318 beq 0x2302d0 <vorbis_packet_blocksize+0x654> */
/* @0x23031c mvn r0, #136 */
/* @0x230320 pop {r3, r4, r5, pc} */
/* @0x230324 mov r0, #0 */
/* @0x230328 pop {r3, r4, r5, pc} */
/* @0x23032c mvn r0, #128 */
/* @0x230330 pop {r3, r4, r5, pc} */
/* @0x230334 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x230338 sub sp, sp, #60 */
/* @0x23033c mov r7, r3 */
/* @0x230340 mov r6, r0 */
/* @0x230344 ldr r4, [sp, #0x64] */
/* @0x230348 stm sp, {r1, r2} */
/* @0x23034c cmp r4, #0 */
/* @0x230350 ldr r8, [sp, #0x60] */
/* @0x230354 beq 0x230610 <vorbis_packet_blocksize+0x994> */
/* @0x230358 ldr r0, [sp] */
/* @0x23035c add r5, r6, #120 */
/* @0x230360 add r11, sp, #24 */
/* @0x230364 bl 0x22ace8 <vorbis_info_init> */
/* @0x230368 ldr r0, [sp, #0x4] */
/* @0x23036c bl 0x22aa80 <vorbis_comment_init> */
/* @0x230370 mov r3, #2 */
/* @0x230374 str r3, [r6, #0x58] */
/* @0x230378 mov r0, r4 */
/* @0x23037c bl 0x233f90 <ogg_page_bos> */
/* @0x230380 cmp r0, #0 */
/* @0x230384 beq 0x2304d4 <vorbis_packet_blocksize+0x858> */
/* @0x230388 cmp r7, #0 */
/* @0x23038c beq 0x230424 <vorbis_packet_blocksize+0x7a8> */
/* @0x230390 ldr r10, [r7] */
/* @0x230394 mov r0, r4 */
/* @0x230398 ldr r9, [r8] */
/* @0x23039c bl 0x23409c <ogg_page_serialno> */
/* @0x2303a0 cmp r10, #0 */
/* @0x2303a4 beq 0x2303e4 <vorbis_packet_blocksize+0x768> */
/* @0x2303a8 cmp r9, #0 */
/* @0x2303ac beq 0x2303e4 <vorbis_packet_blocksize+0x768> */
/* @0x2303b0 ldr r3, [r10] */
/* @0x2303b4 cmp r0, r3 */
/* @0x2303b8 beq 0x230508 <vorbis_packet_blocksize+0x88c> */
/* @0x2303bc mov r2, r10 */
/* @0x2303c0 sub r12, r9, #1 */
/* @0x2303c4 mov r3, #0 */
/* @0x2303c8 b 0x2303d8 <vorbis_packet_blocksize+0x75c> */
/* @0x2303cc ldr r1, [r2, #0x4]! */
/* @0x2303d0 cmp r0, r1 */
/* @0x2303d4 beq 0x230508 <vorbis_packet_blocksize+0x88c> */
/* @0x2303d8 cmp r3, r12 */
/* @0x2303dc add r3, r3, #1 */
/* @0x2303e0 bne 0x2303cc <vorbis_packet_blocksize+0x750> */
/* @0x2303e4 mov r0, r4 */
/* @0x2303e8 bl 0x23409c <ogg_page_serialno> */
/* @0x2303ec ldr r1, [r8] */
/* @0x2303f0 add r1, r1, #1 */
/* @0x2303f4 mov r10, r0 */
/* @0x2303f8 ldr r0, [r7] */
/* @0x2303fc str r1, [r8] */
/* @0x230400 cmp r0, #0 */
/* @0x230404 beq 0x23052c <vorbis_packet_blocksize+0x8b0> */
/* @0x230408 lsl r1, r1, #2 */
/* @0x23040c bl 0xb6c28 <realloc@plt> */
/* @0x230410 mov r3, r0 */
/* @0x230414 str r0, [r7] */
/* @0x230418 ldr r2, [r8] */
/* @0x23041c sub r2, r2, #-1073741823 */
/* @0x230420 str r10, [r3, r2, lsl #2] */
/* @0x230424 ldr r3, [r6, #0x58] */
/* @0x230428 cmp r3, #2 */
/* @0x23042c bgt 0x230474 <vorbis_packet_blocksize+0x7f8> */
/* @0x230430 mov r0, r4 */
/* @0x230434 bl 0x23409c <ogg_page_serialno> */
/* @0x230438 mov r1, r0 */
/* @0x23043c mov r0, r5 */
/* @0x230440 bl 0x2352f4 <ogg_stream_reset_serialno> */
/* @0x230444 mov r1, r4 */
/* @0x230448 mov r0, r5 */
/* @0x23044c bl 0x234eac <ogg_stream_pagein> */
/* @0x230450 mov r0, r5 */
/* @0x230454 mov r1, r11 */
/* @0x230458 bl 0x235328 <ogg_stream_packetout> */
/* @0x23045c cmp r0, #0 */
/* @0x230460 ble 0x230474 <vorbis_packet_blocksize+0x7f8> */
/* @0x230464 mov r0, r11 */
/* @0x230468 bl 0x22aec4 <vorbis_synthesis_idheader> */
/* @0x23046c cmp r0, #0 */
/* @0x230470 bne 0x230540 <vorbis_packet_blocksize+0x8c4> */
/* @0x230474 mov r2, #32768 */
/* @0x230478 mov r3, #0 */
/* @0x23047c mov r0, r6 */
/* @0x230480 mov r1, r4 */
/* @0x230484 bl 0x22fd0c <vorbis_packet_blocksize+0x90> */
/* @0x230488 mvn r2, #127 */
/* @0x23048c mvn r3, #0 */
/* @0x230490 cmp r1, r3 */
/* @0x230494 cmpeq r0, r2 */
/* @0x230498 beq 0x230564 <vorbis_packet_blocksize+0x8e8> */
/* @0x23049c cmp r0, #0 */
/* @0x2304a0 sbcs r3, r1, #0 */
/* @0x2304a4 blt 0x2304e0 <vorbis_packet_blocksize+0x864> */
/* @0x2304a8 ldr r3, [r6, #0x58] */
/* @0x2304ac cmp r3, #3 */
/* @0x2304b0 bne 0x230378 <vorbis_packet_blocksize+0x6fc> */
/* @0x2304b4 mov r0, r4 */
/* @0x2304b8 ldr r10, [r6, #0x1c8] */
/* @0x2304bc bl 0x23409c <ogg_page_serialno> */
/* @0x2304c0 cmp r10, r0 */
/* @0x2304c4 bne 0x230378 <vorbis_packet_blocksize+0x6fc> */
/* @0x2304c8 add r0, r6, #120 */
/* @0x2304cc mov r1, r4 */
/* @0x2304d0 bl 0x234eac <ogg_stream_pagein> */
/* @0x2304d4 ldr r3, [r6, #0x58] */
/* @0x2304d8 cmp r3, #3 */
/* @0x2304dc beq 0x23056c <vorbis_packet_blocksize+0x8f0> */
/* @0x2304e0 mvn r11, #131 */
/* @0x2304e4 ldr r0, [sp] */
/* @0x2304e8 bl 0x22ad10 <vorbis_info_clear> */
/* @0x2304ec ldr r0, [sp, #0x4] */
/* @0x2304f0 bl 0x22ac4c <vorbis_comment_clear> */
/* @0x2304f4 mov r0, r11 */
/* @0x2304f8 mov r3, #2 */
/* @0x2304fc str r3, [r6, #0x58] */
/* @0x230500 add sp, sp, #60 */
/* @0x230504 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x230508 ldr r0, [r7] */
/* @0x23050c cmp r0, #0 */
/* @0x230510 beq 0x230518 <vorbis_packet_blocksize+0x89c> */
/* @0x230514 bl 0xb655c <free@plt> */
/* @0x230518 mov r3, #0 */
/* @0x23051c mvn r11, #132 */
/* @0x230520 str r3, [r7] */
/* @0x230524 str r3, [r8] */
/* @0x230528 b 0x2304e4 <vorbis_packet_blocksize+0x868> */
/* @0x23052c mov r0, #4 */
/* @0x230530 bl 0xb6544 <malloc@plt> */
/* @0x230534 mov r3, r0 */
/* @0x230538 str r0, [r7] */
/* @0x23053c b 0x230418 <vorbis_packet_blocksize+0x79c> */
/* @0x230540 mov r3, #3 */
/* @0x230544 ldm sp, {r0, r1} */
/* @0x230548 str r3, [r6, #0x58] */
/* @0x23054c mov r2, r11 */
/* @0x230550 bl 0x22af64 <vorbis_synthesis_headerin> */
/* @0x230554 cmp r0, #0 */
/* @0x230558 beq 0x230474 <vorbis_packet_blocksize+0x7f8> */
/* @0x23055c mvn r11, #132 */
/* @0x230560 b 0x2304e4 <vorbis_packet_blocksize+0x868> */
/* @0x230564 mvn r11, #127 */
/* @0x230568 b 0x2304e4 <vorbis_packet_blocksize+0x868> */
/* @0x23056c mov r10, #0 */
/* @0x230570 add r8, r6, #120 */
/* @0x230574 mov r7, r10 */
/* @0x230578 add r5, sp, #24 */
/* @0x23057c b 0x2305a8 <vorbis_packet_blocksize+0x92c> */
/* @0x230580 cmn r0, #1 */
/* @0x230584 beq 0x23055c <vorbis_packet_blocksize+0x8e0> */
/* @0x230588 ldm sp, {r0, r1} */
/* @0x23058c mov r2, r5 */
/* @0x230590 bl 0x22af64 <vorbis_synthesis_headerin> */
/* @0x230594 subs r11, r0, #0 */
/* @0x230598 bne 0x2304e4 <vorbis_packet_blocksize+0x868> */
/* @0x23059c cmp r7, #0 */
/* @0x2305a0 bne 0x23064c <vorbis_packet_blocksize+0x9d0> */
/* @0x2305a4 mov r7, #1 */
/* @0x2305a8 mov r0, r8 */
/* @0x2305ac mov r1, r5 */
/* @0x2305b0 bl 0x235328 <ogg_stream_packetout> */
/* @0x2305b4 cmp r0, #0 */
/* @0x2305b8 bne 0x230580 <vorbis_packet_blocksize+0x904> */
/* @0x2305bc mov r3, #0 */
/* @0x2305c0 mov r0, r6 */
/* @0x2305c4 mov r1, r4 */
/* @0x2305c8 mov r2, #32768 */
/* @0x2305cc bl 0x22fd0c <vorbis_packet_blocksize+0x90> */
/* @0x2305d0 cmp r0, #0 */
/* @0x2305d4 sbcs r3, r1, #0 */
/* @0x2305d8 mov r0, r4 */
/* @0x2305dc blt 0x23055c <vorbis_packet_blocksize+0x8e0> */
/* @0x2305e0 ldr r11, [r6, #0x1c8] */
/* @0x2305e4 bl 0x23409c <ogg_page_serialno> */
/* @0x2305e8 cmp r11, r0 */
/* @0x2305ec mov r0, r4 */
/* @0x2305f0 beq 0x230654 <vorbis_packet_blocksize+0x9d8> */
/* @0x2305f4 bl 0x233f90 <ogg_page_bos> */
/* @0x2305f8 cmp r0, #0 */
/* @0x2305fc beq 0x2305bc <vorbis_packet_blocksize+0x940> */
/* @0x230600 cmp r10, #0 */
/* @0x230604 mov r10, #1 */
/* @0x230608 beq 0x2305bc <vorbis_packet_blocksize+0x940> */
/* @0x23060c b 0x23055c <vorbis_packet_blocksize+0x8e0> */
/* @0x230610 add r10, sp, #8 */
/* @0x230614 mov r2, #32768 */
/* @0x230618 mov r3, #0 */
/* @0x23061c mvn r4, #127 */
/* @0x230620 mov r1, r10 */
/* @0x230624 mvn r5, #0 */
/* @0x230628 bl 0x22fd0c <vorbis_packet_blocksize+0x90> */
/* @0x23062c cmp r1, r5 */
/* @0x230630 cmpeq r0, r4 */
/* @0x230634 beq 0x23066c <vorbis_packet_blocksize+0x9f0> */
/* @0x230638 cmp r0, #0 */
/* @0x23063c sbcs r3, r1, #0 */
/* @0x230640 blt 0x230664 <vorbis_packet_blocksize+0x9e8> */
/* @0x230644 mov r4, r10 */
/* @0x230648 b 0x230358 <vorbis_packet_blocksize+0x6dc> */
/* @0x23064c mov r0, #0 */
/* @0x230650 b 0x230500 <vorbis_packet_blocksize+0x884> */
/* @0x230654 mov r0, r8 */
/* @0x230658 mov r1, r4 */
/* @0x23065c bl 0x234eac <ogg_stream_pagein> */
/* @0x230660 b 0x2305a8 <vorbis_packet_blocksize+0x92c> */
/* @0x230664 mvn r0, #131 */
/* @0x230668 b 0x230500 <vorbis_packet_blocksize+0x884> */
/* @0x23066c mvn r0, #127 */
/* @0x230670 b 0x230500 <vorbis_packet_blocksize+0x884> */
/* @0x230674 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x230678 sub sp, sp, #172 */
/* @0x23067c mov r6, r0 */
/* @0x230680 mov r4, r2 */
/* @0x230684 ldr r8, [sp, #0xec] */
/* @0x230688 mov r5, r3 */
/* @0x23068c ldr r9, [r0, #0x1c8] */
/* @0x230690 mvn r2, #0 */
/* @0x230694 cmp r8, #0 */
/* @0x230698 mvn r3, #0 */
/* @0x23069c ldr r10, [sp, #0xf0] */
/* @0x2306a0 strd r2, r3, [sp, #96] */
/* @0x2306a4 ldr r0, [sp, #0xe8] */
/* @0x2306a8 beq 0x2306e8 <vorbis_packet_blocksize+0xa6c> */
/* @0x2306ac cmp r10, #0 */
/* @0x2306b0 beq 0x2306e8 <vorbis_packet_blocksize+0xa6c> */
/* @0x2306b4 ldr r3, [r8] */
/* @0x2306b8 cmp r0, r3 */
/* @0x2306bc subne r12, r10, #1 */
/* @0x2306c0 movne r2, r8 */
/* @0x2306c4 movne r3, #0 */
/* @0x2306c8 bne 0x2306dc <vorbis_packet_blocksize+0xa60> */
/* @0x2306cc b 0x230a28 <vorbis_packet_blocksize+0xdac> */
/* @0x2306d0 ldr r1, [r2, #0x4]! */
/* @0x2306d4 cmp r0, r1 */
/* @0x2306d8 beq 0x230a28 <vorbis_packet_blocksize+0xdac> */
/* @0x2306dc cmp r3, r12 */
/* @0x2306e0 add r3, r3, #1 */
/* @0x2306e4 bne 0x2306d0 <vorbis_packet_blocksize+0xa54> */
/* @0x2306e8 ldrd r2, r3, [sp, #216] */
/* @0x2306ec ldrd r0, r1, [sp, #208] */
/* @0x2306f0 cmp r0, r2 */
/* @0x2306f4 sbcs r3, r1, r3 */
/* @0x2306f8 mov r3, #0 */
/* @0x2306fc str r3, [sp, #0x58] */
/* @0x230700 str r3, [sp, #0x5c] */
/* @0x230704 bge 0x230b5c <vorbis_packet_blocksize+0xee0> */
/* @0x230708 ldrd r0, r1, [sp, #216] */
/* @0x23070c sub r7, r10, #1 */
/* @0x230710 add r11, sp, #104 */
/* @0x230714 str r9, [sp, #0x54] */
/* @0x230718 str r8, [sp, #0x44] */
/* @0x23071c mov r9, r6 */
/* @0x230720 str r10, [sp, #0x50] */
/* @0x230724 mov r8, r7 */
/* @0x230728 str r11, [sp, #0x38] */
/* @0x23072c mov r10, r0 */
/* @0x230730 mov r11, r1 */
/* @0x230734 strd r0, r1, [sp, #72] */
/* @0x230738 ldrd r2, r3, [sp, #208] */
/* @0x23073c movw r0, #0x7fff */
/* @0x230740 mov r1, #0 */
/* @0x230744 ldrd r4, r5, [sp, #208] */
/* @0x230748 subs r2, r10, r2 */
/* @0x23074c sbc r3, r11, r3 */
/* @0x230750 cmp r0, r2 */
/* @0x230754 sbcs r1, r1, r3 */
/* @0x230758 bge 0x230778 <vorbis_packet_blocksize+0xafc> */
/* @0x23075c adds r4, r4, r10 */
/* @0x230760 adc r5, r5, r11 */
/* @0x230764 lsr r3, r5, #31 */
/* @0x230768 adds r4, r4, r3 */
/* @0x23076c adc r5, r5, #0 */
/* @0x230770 asrs r5, r5, #1 */
/* @0x230774 rrx r4, r4 */
/* @0x230778 ldrd r2, r3, [r9, #8] */
/* @0x23077c cmp r3, r5 */
/* @0x230780 cmpeq r2, r4 */
/* @0x230784 beq 0x2307a0 <vorbis_packet_blocksize+0xb24> */
/* @0x230788 mov r0, r9 */
/* @0x23078c mov r2, r4 */
/* @0x230790 mov r3, r5 */
/* @0x230794 bl 0x22ffe0 <vorbis_packet_blocksize+0x364> */
/* @0x230798 cmp r0, #0 */
/* @0x23079c bne 0x230b4c <vorbis_packet_blocksize+0xed0> */
/* @0x2307a0 mvn r2, #0 */
/* @0x2307a4 mvn r3, #0 */
/* @0x2307a8 mov r0, r9 */
/* @0x2307ac ldr r1, [sp, #0x38] */
/* @0x2307b0 bl 0x22fd0c <vorbis_packet_blocksize+0x90> */
/* @0x2307b4 mvn r2, #127 */
/* @0x2307b8 mvn r3, #0 */
/* @0x2307bc mov r6, r0 */
/* @0x2307c0 mov r7, r1 */
/* @0x2307c4 cmp r7, r3 */
/* @0x2307c8 cmpeq r6, r2 */
/* @0x2307cc beq 0x230b3c <vorbis_packet_blocksize+0xec0> */
/* @0x2307d0 cmp r6, #0 */
/* @0x2307d4 sbcs r3, r7, #0 */
/* @0x2307d8 blt 0x230830 <vorbis_packet_blocksize+0xbb4> */
/* @0x2307dc ldr r0, [sp, #0x38] */
/* @0x2307e0 bl 0x23409c <ogg_page_serialno> */
/* @0x2307e4 ldr r1, [sp, #0x44] */
/* @0x2307e8 cmp r1, #0 */
/* @0x2307ec beq 0x23082c <vorbis_packet_blocksize+0xbb0> */
/* @0x2307f0 ldr r2, [sp, #0x50] */
/* @0x2307f4 cmp r2, #0 */
/* @0x2307f8 beq 0x23082c <vorbis_packet_blocksize+0xbb0> */
/* @0x2307fc ldr r3, [r1] */
/* @0x230800 cmp r0, r3 */
/* @0x230804 beq 0x230a1c <vorbis_packet_blocksize+0xda0> */
/* @0x230808 mov r2, r1 */
/* @0x23080c mov r3, #0 */
/* @0x230810 b 0x230820 <vorbis_packet_blocksize+0xba4> */
/* @0x230814 ldr r1, [r2, #0x4]! */
/* @0x230818 cmp r0, r1 */
/* @0x23081c beq 0x230a1c <vorbis_packet_blocksize+0xda0> */
/* @0x230820 cmp r3, r8 */
/* @0x230824 add r3, r3, #1 */
/* @0x230828 bne 0x230814 <vorbis_packet_blocksize+0xb98> */
/* @0x23082c strd r6, r7, [sp, #72] */
/* @0x230830 mov r10, r4 */
/* @0x230834 mov r11, r5 */
/* @0x230838 ldrd r0, r1, [sp, #208] */
/* @0x23083c cmp r0, r10 */
/* @0x230840 sbcs r1, r1, r11 */
/* @0x230844 blt 0x230738 <vorbis_packet_blocksize+0xabc> */
/* @0x230848 mov r6, r9 */
/* @0x23084c ldr r8, [sp, #0x44] */
/* @0x230850 ldr r9, [sp, #0x54] */
/* @0x230854 ldr r10, [sp, #0x50] */
/* @0x230858 ldrd r0, r1, [sp, #72] */
/* @0x23085c add r4, sp, #136 */
/* @0x230860 add r5, sp, #96 */
/* @0x230864 strd r0, r1, [r6, #8] */
/* @0x230868 mov r3, r4 */
/* @0x23086c str r5, [sp] */
/* @0x230870 mov r0, r6 */
/* @0x230874 mov r1, r8 */
/* @0x230878 mov r2, r10 */
/* @0x23087c str r9, [sp, #0x88] */
/* @0x230880 bl 0x230048 <vorbis_packet_blocksize+0x3cc> */
/* @0x230884 ldr r3, [sp, #0x88] */
/* @0x230888 cmp r3, r9 */
/* @0x23088c strd r0, r1, [r6, #8] */
/* @0x230890 bne 0x230868 <vorbis_packet_blocksize+0xbec> */
/* @0x230894 ldrd r8, r9, [sp, #72] */
/* @0x230898 cmp r1, r9 */
/* @0x23089c cmpeq r0, r8 */
/* @0x2308a0 beq 0x2308b8 <vorbis_packet_blocksize+0xc3c> */
/* @0x2308a4 mov r0, r6 */
/* @0x2308a8 ldrd r2, r3, [sp, #72] */
/* @0x2308ac bl 0x22ffe0 <vorbis_packet_blocksize+0x364> */
/* @0x2308b0 subs r12, r0, #0 */
/* @0x2308b4 bne 0x230b30 <vorbis_packet_blocksize+0xeb4> */
/* @0x2308b8 add r5, sp, #120 */
/* @0x2308bc mov r3, #0 */
/* @0x2308c0 add r2, sp, #92 */
/* @0x2308c4 str r3, [sp, #0x4] */
/* @0x2308c8 str r2, [sp] */
/* @0x2308cc mov r0, r6 */
/* @0x2308d0 mov r2, r5 */
/* @0x2308d4 mov r1, r4 */
/* @0x2308d8 add r3, sp, #88 */
/* @0x2308dc bl 0x230334 <vorbis_packet_blocksize+0x6b8> */
/* @0x2308e0 subs r12, r0, #0 */
/* @0x2308e4 bne 0x230b30 <vorbis_packet_blocksize+0xeb4> */
/* @0x2308e8 ldr r9, [sp, #0xf4] */
/* @0x2308ec mov r0, r6 */
/* @0x2308f0 mov r1, r4 */
/* @0x2308f4 ldr r10, [r6, #0x1c8] */
/* @0x2308f8 add r7, r9, #1 */
/* @0x2308fc ldrd r8, r9, [r6, #8] */
/* @0x230900 strd r8, r9, [sp, #56] */
/* @0x230904 bl 0x22fed4 <vorbis_packet_blocksize+0x258> */
/* @0x230908 ldrd r8, r9, [r6, #8] */
/* @0x23090c ldrd r2, r3, [sp, #216] */
/* @0x230910 ldr r12, [sp, #0x58] */
/* @0x230914 strd r8, r9, [sp] */
/* @0x230918 ldrd r8, r9, [sp, #224] */
/* @0x23091c strd r2, r3, [sp, #8] */
/* @0x230920 str r12, [sp, #0x1c] */
/* @0x230924 str r7, [sp, #0x24] */
/* @0x230928 ldrd r2, r3, [sp, #72] */
/* @0x23092c strd r8, r9, [sp, #16] */
/* @0x230930 strd r0, r1, [sp, #48] */
/* @0x230934 mov r0, r6 */
/* @0x230938 ldr r1, [sp, #0xe8] */
/* @0x23093c str r1, [sp, #0x18] */
/* @0x230940 ldr r1, [sp, #0x5c] */
/* @0x230944 str r1, [sp, #0x20] */
/* @0x230948 bl 0x230674 <vorbis_packet_blocksize+0x9f8> */
/* @0x23094c subs r12, r0, #0 */
/* @0x230950 bne 0x230b30 <vorbis_packet_blocksize+0xeb4> */
/* @0x230954 ldr r0, [sp, #0x58] */
/* @0x230958 cmp r0, #0 */
/* @0x23095c beq 0x23096c <vorbis_packet_blocksize+0xcf0> */
/* @0x230960 str r12, [sp, #0x2c] */
/* @0x230964 bl 0xb655c <free@plt> */
/* @0x230968 ldr r12, [sp, #0x2c] */
/* @0x23096c lsl r8, r7, #3 */
/* @0x230970 str r8, [sp, #0x44] */
/* @0x230974 ldr r2, [r6, #0x38] */
/* @0x230978 ldr r3, [r6, #0x40] */
/* @0x23097c ldrd r8, r9, [sp, #72] */
/* @0x230980 ldr r11, [sp, #0x44] */
/* @0x230984 strd r8, r9, [r2, r11] */
/* @0x230988 lsl r8, r7, #4 */
/* @0x23098c str r10, [r3, r7, lsl #2] */
/* @0x230990 add r9, r8, #8 */
/* @0x230994 ldr r3, [r6, #0x48] */
/* @0x230998 ldr r11, [r6, #0x4c] */
/* @0x23099c add r7, r3, r7, lsl #5 */
/* @0x2309a0 str r8, [sp, #0x54] */
/* @0x2309a4 ldm r4!, {r0, r1, r2, r3} */
/* @0x2309a8 add r11, r11, r8 */
/* @0x2309ac str r9, [sp, #0x48] */
/* @0x2309b0 ldr r8, [sp, #0x44] */
/* @0x2309b4 ldr r9, [r6, #0x3c] */
/* @0x2309b8 str r11, [sp, #0x50] */
/* @0x2309bc ldrd r10, r11, [sp, #56] */
/* @0x2309c0 ldr r6, [r6, #0x44] */
/* @0x2309c4 strd r10, r11, [r9, r8] */
/* @0x2309c8 ldr r10, [sp, #0x54] */
/* @0x2309cc stm r7!, {r0, r1, r2, r3} */
/* @0x2309d0 add r8, r6, r10 */
/* @0x2309d4 ldm r4, {r0, r1, r2, r3} */
/* @0x2309d8 ldrd r10, r11, [sp, #96] */
/* @0x2309dc strd r10, r11, [sp, #56] */
/* @0x2309e0 stm r7, {r0, r1, r2, r3} */
/* @0x2309e4 ldm r5, {r0, r1, r2, r3} */
/* @0x2309e8 ldr r11, [sp, #0x50] */
/* @0x2309ec stm r11, {r0, r1, r2, r3} */
/* @0x2309f0 ldrd r10, r11, [sp, #56] */
/* @0x2309f4 strd r10, r11, [r8, #-8] */
/* @0x2309f8 ldrd r8, r9, [sp, #48] */
/* @0x2309fc ldr r10, [sp, #0x54] */
/* @0x230a00 ldr r11, [sp, #0x48] */
/* @0x230a04 strd r8, r9, [r6, r10] */
/* @0x230a08 ldrd r2, r3, [r6, r11] */
/* @0x230a0c subs r2, r2, r8 */
/* @0x230a10 sbc r3, r3, r9 */
/* @0x230a14 strd r2, r3, [r6, r11] */
/* @0x230a18 b 0x230b30 <vorbis_packet_blocksize+0xeb4> */
/* @0x230a1c ldrd r2, r3, [r9, #8] */
/* @0x230a20 strd r2, r3, [sp, #208] */
/* @0x230a24 b 0x230838 <vorbis_packet_blocksize+0xbbc> */
/* @0x230a28 cmp r9, r0 */
/* @0x230a2c addne r11, sp, #232 */
/* @0x230a30 addne r7, sp, #224 */
/* @0x230a34 beq 0x230a64 <vorbis_packet_blocksize+0xde8> */
/* @0x230a38 mov r3, r11 */
/* @0x230a3c str r7, [sp] */
/* @0x230a40 mov r0, r6 */
/* @0x230a44 mov r1, r8 */
/* @0x230a48 mov r2, r10 */
/* @0x230a4c str r9, [sp, #0xe8] */
/* @0x230a50 bl 0x230048 <vorbis_packet_blocksize+0x3cc> */
/* @0x230a54 ldr r3, [sp, #0xe8] */
/* @0x230a58 cmp r3, r9 */
/* @0x230a5c strd r0, r1, [r6, #8] */
/* @0x230a60 bne 0x230a38 <vorbis_packet_blocksize+0xdbc> */
/* @0x230a64 ldr r0, [r6, #0x38] */
/* @0x230a68 ldr r8, [sp, #0xf4] */
/* @0x230a6c cmp r0, #0 */
/* @0x230a70 add r7, r8, #1 */
/* @0x230a74 str r7, [r6, #0x34] */
/* @0x230a78 beq 0x230a80 <vorbis_packet_blocksize+0xe04> */
/* @0x230a7c bl 0xb655c <free@plt> */
/* @0x230a80 ldr r0, [r6, #0x40] */
/* @0x230a84 cmp r0, #0 */
/* @0x230a88 beq 0x230a90 <vorbis_packet_blocksize+0xe14> */
/* @0x230a8c bl 0xb655c <free@plt> */
/* @0x230a90 ldr r0, [r6, #0x3c] */
/* @0x230a94 cmp r0, #0 */
/* @0x230a98 beq 0x230aa0 <vorbis_packet_blocksize+0xe24> */
/* @0x230a9c bl 0xb655c <free@plt> */
/* @0x230aa0 ldr r8, [r6, #0x34] */
/* @0x230aa4 mov r12, #0 */
/* @0x230aa8 str r12, [sp, #0x2c] */
/* @0x230aac lsl r7, r7, #3 */
/* @0x230ab0 add r0, r8, #1 */
/* @0x230ab4 lsl r0, r0, #3 */
/* @0x230ab8 bl 0xb6544 <malloc@plt> */
/* @0x230abc lsl r1, r8, #5 */
/* @0x230ac0 str r0, [r6, #0x38] */
/* @0x230ac4 ldr r0, [r6, #0x48] */
/* @0x230ac8 bl 0xb6c28 <realloc@plt> */
/* @0x230acc ldr r1, [r6, #0x34] */
/* @0x230ad0 lsl r1, r1, #4 */
/* @0x230ad4 str r0, [r6, #0x48] */
/* @0x230ad8 ldr r0, [r6, #0x4c] */
/* @0x230adc bl 0xb6c28 <realloc@plt> */
/* @0x230ae0 ldr r8, [r6, #0x34] */
/* @0x230ae4 str r0, [r6, #0x4c] */
/* @0x230ae8 lsl r0, r8, #2 */
/* @0x230aec bl 0xb6544 <malloc@plt> */
/* @0x230af0 str r0, [r6, #0x40] */
/* @0x230af4 lsl r0, r8, #3 */
/* @0x230af8 bl 0xb6544 <malloc@plt> */
/* @0x230afc str r0, [r6, #0x3c] */
/* @0x230b00 lsl r0, r8, #4 */
/* @0x230b04 bl 0xb6544 <malloc@plt> */
/* @0x230b08 ldr r3, [r6, #0x38] */
/* @0x230b0c ldrd r10, r11, [sp, #216] */
/* @0x230b10 ldr r9, [sp, #0xf4] */
/* @0x230b14 ldr r12, [sp, #0x2c] */
/* @0x230b18 str r0, [r6, #0x44] */
/* @0x230b1c add r0, r0, r9, lsl #4 */
/* @0x230b20 strd r10, r11, [r3, r7]! */
/* @0x230b24 strd r4, r5, [r3, #-8] */
/* @0x230b28 ldrd r2, r3, [sp, #224] */
/* @0x230b2c strd r2, r3, [r0, #8] */
/* @0x230b30 mov r0, r12 */
/* @0x230b34 add sp, sp, #172 */
/* @0x230b38 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x230b3c mvn r12, #127 */
/* @0x230b40 mov r0, r12 */
/* @0x230b44 add sp, sp, #172 */
/* @0x230b48 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x230b4c mov r12, r0 */
/* @0x230b50 mov r0, r12 */
/* @0x230b54 add sp, sp, #172 */
/* @0x230b58 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x230b5c ldrd r2, r3, [sp, #216] */
/* @0x230b60 strd r2, r3, [sp, #72] */
/* @0x230b64 b 0x230858 <vorbis_packet_blocksize+0xbdc> */
/* @0x230b68 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x230b6c sub sp, sp, #60 */
/* @0x230b70 add r6, sp, #24 */
/* @0x230b74 add r9, r0, #120 */
/* @0x230b78 add r10, r0, #560 */
/* @0x230b7c add r7, sp, #8 */
/* @0x230b80 mov r8, r0 */
/* @0x230b84 mov r11, #3 */
/* @0x230b88 ldr r3, [r8, #0x58] */
/* @0x230b8c cmp r3, #3 */
/* @0x230b90 beq 0x230d04 <vorbis_packet_blocksize+0x1088> */
/* @0x230b94 cmp r3, #4 */
/* @0x230b98 beq 0x230ca4 <vorbis_packet_blocksize+0x1028> */
/* @0x230b9c cmp r3, #1 */
/* @0x230ba0 ble 0x230d28 <vorbis_packet_blocksize+0x10ac> */
/* @0x230ba4 mvn r3, #0 */
/* @0x230ba8 mov r0, r8 */
/* @0x230bac mov r1, r7 */
/* @0x230bb0 mvn r2, #0 */
/* @0x230bb4 bl 0x22fd0c <vorbis_packet_blocksize+0x90> */
/* @0x230bb8 cmp r0, #0 */
/* @0x230bbc sbcs r3, r1, #0 */
/* @0x230bc0 mov r0, r7 */
/* @0x230bc4 blt 0x230e70 <vorbis_packet_blocksize+0x11f4> */
/* @0x230bc8 ldr r12, [sp, #0xc] */
/* @0x230bcc ldrd r2, r3, [r8, #104] */
/* @0x230bd0 ldr r1, [r8, #0x58] */
/* @0x230bd4 lsl r12, r12, #3 */
/* @0x230bd8 adds r2, r2, r12 */
/* @0x230bdc adc r3, r3, r12, asr #31 */
/* @0x230be0 cmp r1, #4 */
/* @0x230be4 strd r2, r3, [r8, #104] */
/* @0x230be8 bne 0x230ce4 <vorbis_packet_blocksize+0x1068> */
/* @0x230bec ldr r4, [r8, #0x5c] */
/* @0x230bf0 bl 0x23409c <ogg_page_serialno> */
/* @0x230bf4 cmp r4, r0 */
/* @0x230bf8 mov r0, r7 */
/* @0x230bfc beq 0x230ce0 <vorbis_packet_blocksize+0x1064> */
/* @0x230c00 bl 0x233f90 <ogg_page_bos> */
/* @0x230c04 cmp r0, #0 */
/* @0x230c08 beq 0x230ba4 <vorbis_packet_blocksize+0xf28> */
/* @0x230c0c add r0, r8, #480 */
/* @0x230c10 bl 0x2272ac <vorbis_dsp_clear> */
/* @0x230c14 mov r0, r10 */
/* @0x230c18 bl 0x227208 <vorbis_block_clear> */
/* @0x230c1c ldr r3, [r8, #0x4] */
/* @0x230c20 mov r2, #2 */
/* @0x230c24 str r2, [r8, #0x58] */
/* @0x230c28 cmp r3, #0 */
/* @0x230c2c beq 0x230cd0 <vorbis_packet_blocksize+0x1054> */
/* @0x230c30 mov r0, r7 */
/* @0x230c34 bl 0x23409c <ogg_page_serialno> */
/* @0x230c38 ldr r1, [r8, #0x34] */
/* @0x230c3c cmp r1, #0 */
/* @0x230c40 ble 0x230eb8 <vorbis_packet_blocksize+0x123c> */
/* @0x230c44 ldr r2, [r8, #0x40] */
/* @0x230c48 ldr r3, [r2] */
/* @0x230c4c cmp r0, r3 */
/* @0x230c50 mov r3, #0 */
/* @0x230c54 beq 0x230c70 <vorbis_packet_blocksize+0xff4> */
/* @0x230c58 add r3, r3, #1 */
/* @0x230c5c cmp r3, r1 */
/* @0x230c60 beq 0x230b88 <vorbis_packet_blocksize+0xf0c> */
/* @0x230c64 ldr r12, [r2, #0x4]! */
/* @0x230c68 cmp r0, r12 */
/* @0x230c6c bne 0x230c58 <vorbis_packet_blocksize+0xfdc> */
/* @0x230c70 str r0, [r8, #0x5c] */
/* @0x230c74 mov r1, r0 */
/* @0x230c78 str r3, [r8, #0x60] */
/* @0x230c7c mov r0, r9 */
/* @0x230c80 bl 0x2352f4 <ogg_stream_reset_serialno> */
/* @0x230c84 str r11, [r8, #0x58] */
/* @0x230c88 b 0x230cec <vorbis_packet_blocksize+0x1070> */
/* @0x230c8c cmp r3, #0 */
/* @0x230c90 ble 0x230d1c <vorbis_packet_blocksize+0x10a0> */
/* @0x230c94 ldrd r4, r5, [sp, #40] */
/* @0x230c98 bl 0x22fc6c <vorbis_synthesis> */
/* @0x230c9c cmp r0, #0 */
/* @0x230ca0 beq 0x230d70 <vorbis_packet_blocksize+0x10f4> */
/* @0x230ca4 mov r1, r6 */
/* @0x230ca8 mov r0, r9 */
/* @0x230cac bl 0x235328 <ogg_stream_packetout> */
/* @0x230cb0 mov r1, r6 */
/* @0x230cb4 mov r3, r0 */
/* @0x230cb8 cmn r3, #1 */
/* @0x230cbc mov r0, r10 */
/* @0x230cc0 bne 0x230c8c <vorbis_packet_blocksize+0x1010> */
/* @0x230cc4 mvn r0, #2 */
/* @0x230cc8 add sp, sp, #60 */
/* @0x230ccc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x230cd0 ldr r0, [r8, #0x48] */
/* @0x230cd4 bl 0x22ad10 <vorbis_info_clear> */
/* @0x230cd8 ldr r0, [r8, #0x4c] */
/* @0x230cdc bl 0x22ac4c <vorbis_comment_clear> */
/* @0x230ce0 ldr r1, [r8, #0x58] */
/* @0x230ce4 cmp r1, #2 */
/* @0x230ce8 ble 0x230d28 <vorbis_packet_blocksize+0x10ac> */
/* @0x230cec mov r0, r9 */
/* @0x230cf0 mov r1, r7 */
/* @0x230cf4 bl 0x234eac <ogg_stream_pagein> */
/* @0x230cf8 ldr r3, [r8, #0x58] */
/* @0x230cfc cmp r3, #3 */
/* @0x230d00 bne 0x230b94 <vorbis_packet_blocksize+0xf18> */
/* @0x230d04 mov r0, r8 */
/* @0x230d08 bl 0x230294 <vorbis_packet_blocksize+0x618> */
/* @0x230d0c cmp r0, #0 */
/* @0x230d10 blt 0x230cc8 <vorbis_packet_blocksize+0x104c> */
/* @0x230d14 ldr r3, [r8, #0x58] */
/* @0x230d18 b 0x230b94 <vorbis_packet_blocksize+0xf18> */
/* @0x230d1c ldr r3, [r8, #0x58] */
/* @0x230d20 cmp r3, #1 */
/* @0x230d24 bgt 0x230ba4 <vorbis_packet_blocksize+0xf28> */
/* @0x230d28 ldr r12, [r8, #0x4] */
/* @0x230d2c cmp r12, #0 */
/* @0x230d30 bne 0x230c30 <vorbis_packet_blocksize+0xfb4> */
/* @0x230d34 ldr r1, [r8, #0x48] */
/* @0x230d38 mov r3, r12 */
/* @0x230d3c ldr r2, [r8, #0x4c] */
/* @0x230d40 mov r0, r8 */
/* @0x230d44 str r12, [sp] */
/* @0x230d48 str r7, [sp, #0x4] */
/* @0x230d4c bl 0x230334 <vorbis_packet_blocksize+0x6b8> */
/* @0x230d50 cmp r0, #0 */
/* @0x230d54 bne 0x230cc8 <vorbis_packet_blocksize+0x104c> */
/* @0x230d58 ldr r2, [r8, #0x1c8] */
/* @0x230d5c ldr r3, [r8, #0x60] */
/* @0x230d60 str r2, [r8, #0x5c] */
/* @0x230d64 add r3, r3, #1 */
/* @0x230d68 str r3, [r8, #0x60] */
/* @0x230d6c b 0x230cec <vorbis_packet_blocksize+0x1070> */
/* @0x230d70 add r9, r8, #480 */
/* @0x230d74 mov r1, r0 */
/* @0x230d78 mov r0, r9 */
/* @0x230d7c bl 0x227c80 <vorbis_synthesis_pcmout> */
/* @0x230d80 subs r6, r0, #0 */
/* @0x230d84 mvnne r0, #128 */
/* @0x230d88 bne 0x230cc8 <vorbis_packet_blocksize+0x104c> */
/* @0x230d8c mov r1, r10 */
/* @0x230d90 mov r0, r9 */
/* @0x230d94 bl 0x227638 <vorbis_synthesis_blockin> */
/* @0x230d98 mov r1, r6 */
/* @0x230d9c mov r0, r9 */
/* @0x230da0 ldrd r6, r7, [r8, #112] */
/* @0x230da4 bl 0x227c80 <vorbis_synthesis_pcmout> */
/* @0x230da8 ldr r1, [sp, #0x1c] */
/* @0x230dac ldrd r2, r3, [r8, #104] */
/* @0x230db0 mvn r10, #0 */
/* @0x230db4 mvn r11, #0 */
/* @0x230db8 lsl r1, r1, #3 */
/* @0x230dbc adds r2, r2, r1 */
/* @0x230dc0 adc r3, r3, r1, asr #31 */
/* @0x230dc4 strd r2, r3, [r8, #104] */
/* @0x230dc8 adds r2, r6, r0 */
/* @0x230dcc adc r3, r7, r0, asr #31 */
/* @0x230dd0 cmp r5, r11 */
/* @0x230dd4 cmpeq r4, r10 */
/* @0x230dd8 mov r0, r2 */
/* @0x230ddc mov r1, r3 */
/* @0x230de0 strd r0, r1, [r8, #112] */
/* @0x230de4 beq 0x230e78 <vorbis_packet_blocksize+0x11fc> */
/* @0x230de8 ldr r3, [sp, #0x24] */
/* @0x230dec cmp r3, #0 */
/* @0x230df0 bne 0x230e78 <vorbis_packet_blocksize+0x11fc> */
/* @0x230df4 ldr r3, [r8, #0x4] */
/* @0x230df8 cmp r3, #0 */
/* @0x230dfc beq 0x230e80 <vorbis_packet_blocksize+0x1204> */
/* @0x230e00 ldr r6, [r8, #0x60] */
/* @0x230e04 cmp r6, #0 */
/* @0x230e08 ble 0x230e80 <vorbis_packet_blocksize+0x1204> */
/* @0x230e0c ldr r3, [r8, #0x44] */
/* @0x230e10 lsl r6, r6, #4 */
/* @0x230e14 mov r1, #0 */
/* @0x230e18 mov r0, r9 */
/* @0x230e1c ldrd r2, r3, [r3, r6] */
/* @0x230e20 subs r4, r4, r2 */
/* @0x230e24 sbc r5, r5, r3 */
/* @0x230e28 cmp r4, #0 */
/* @0x230e2c sbcs r3, r5, #0 */
/* @0x230e30 movlt r4, #0 */
/* @0x230e34 movlt r5, #0 */
/* @0x230e38 bl 0x227c80 <vorbis_synthesis_pcmout> */
/* @0x230e3c ldr r12, [r8, #0x44] */
/* @0x230e40 add r6, r6, r12 */
/* @0x230e44 subs r2, r4, r0 */
/* @0x230e48 sbc r3, r5, r0, asr #31 */
/* @0x230e4c mov r0, r2 */
/* @0x230e50 mov r1, r3 */
/* @0x230e54 ldrd r2, r3, [r12, #8] */
/* @0x230e58 add r12, r12, #16 */
/* @0x230e5c adds r0, r0, r2 */
/* @0x230e60 adc r1, r1, r3 */
/* @0x230e64 cmp r12, r6 */
/* @0x230e68 bne 0x230e54 <vorbis_packet_blocksize+0x11d8> */
/* @0x230e6c b 0x230eac <vorbis_packet_blocksize+0x1230> */
/* @0x230e70 mvn r0, #1 */
/* @0x230e74 b 0x230cc8 <vorbis_packet_blocksize+0x104c> */
/* @0x230e78 mov r0, #1 */
/* @0x230e7c b 0x230cc8 <vorbis_packet_blocksize+0x104c> */
/* @0x230e80 cmp r4, #0 */
/* @0x230e84 sbcs r2, r5, #0 */
/* @0x230e88 mov r1, #0 */
/* @0x230e8c mov r0, r9 */
/* @0x230e90 movlt r4, #0 */
/* @0x230e94 movlt r5, #0 */
/* @0x230e98 bl 0x227c80 <vorbis_synthesis_pcmout> */
/* @0x230e9c subs r2, r4, r0 */
/* @0x230ea0 sbc r3, r5, r0, asr #31 */
/* @0x230ea4 mov r0, r2 */
/* @0x230ea8 mov r1, r3 */
/* @0x230eac strd r0, r1, [r8, #80] */
/* @0x230eb0 mov r0, #1 */
/* @0x230eb4 b 0x230cc8 <vorbis_packet_blocksize+0x104c> */
/* @0x230eb8 beq 0x230b88 <vorbis_packet_blocksize+0xf0c> */
/* @0x230ebc mov r3, #0 */
/* @0x230ec0 b 0x230c70 <vorbis_packet_blocksize+0xff4> */

/* ── FUNC 0x230ec4 · ov_clear · size=248 · insn=62 */
/* @0x230ec4 push {r3, r4, r5, lr} */
/* @0x230ec8 subs r4, r0, #0 */
/* @0x230ecc beq 0x230f74 <ov_clear+0xb0> */
/* @0x230ed0 add r0, r4, #560 */
/* @0x230ed4 bl 0x227208 <vorbis_block_clear> */
/* @0x230ed8 add r0, r4, #480 */
/* @0x230edc bl 0x2272ac <vorbis_dsp_clear> */
/* @0x230ee0 add r0, r4, #120 */
/* @0x230ee4 bl 0x234150 <ogg_stream_clear> */
/* @0x230ee8 ldr r0, [r4, #0x48] */
/* @0x230eec cmp r0, #0 */
/* @0x230ef0 beq 0x230f00 <ov_clear+0x3c> */
/* @0x230ef4 ldr r3, [r4, #0x34] */
/* @0x230ef8 cmp r3, #0 */
/* @0x230efc bne 0x230f7c <ov_clear+0xb8> */
/* @0x230f00 ldr r0, [r4, #0x3c] */
/* @0x230f04 cmp r0, #0 */
/* @0x230f08 beq 0x230f10 <ov_clear+0x4c> */
/* @0x230f0c bl 0xb655c <free@plt> */
/* @0x230f10 ldr r0, [r4, #0x44] */
/* @0x230f14 cmp r0, #0 */
/* @0x230f18 beq 0x230f20 <ov_clear+0x5c> */
/* @0x230f1c bl 0xb655c <free@plt> */
/* @0x230f20 ldr r0, [r4, #0x40] */
/* @0x230f24 cmp r0, #0 */
/* @0x230f28 beq 0x230f30 <ov_clear+0x6c> */
/* @0x230f2c bl 0xb655c <free@plt> */
/* @0x230f30 ldr r0, [r4, #0x38] */
/* @0x230f34 cmp r0, #0 */
/* @0x230f38 beq 0x230f40 <ov_clear+0x7c> */
/* @0x230f3c bl 0xb655c <free@plt> */
/* @0x230f40 add r0, r4, #24 */
/* @0x230f44 bl 0x234b2c <ogg_sync_clear> */
/* @0x230f48 ldr r0, [r4] */
/* @0x230f4c cmp r0, #0 */
/* @0x230f50 beq 0x230f64 <ov_clear+0xa0> */
/* @0x230f54 ldr r3, [r4, #0x290] */
/* @0x230f58 cmp r3, #0 */
/* @0x230f5c beq 0x230f64 <ov_clear+0xa0> */
/* @0x230f60 blx r3 */
/* @0x230f64 mov r0, r4 */
/* @0x230f68 mov r1, #0 */
/* @0x230f6c mov r2, #664 */
/* @0x230f70 bl 0xb65b0 <memset@plt> */
/* @0x230f74 mov r0, #0 */
/* @0x230f78 pop {r3, r4, r5, pc} */
/* @0x230f7c ble 0x230fac <ov_clear+0xe8> */
/* @0x230f80 mov r5, #0 */
/* @0x230f84 add r0, r0, r5, lsl #5 */
/* @0x230f88 bl 0x22ad10 <vorbis_info_clear> */
/* @0x230f8c ldr r0, [r4, #0x4c] */
/* @0x230f90 add r0, r0, r5, lsl #4 */
/* @0x230f94 add r5, r5, #1 */
/* @0x230f98 bl 0x22ac4c <vorbis_comment_clear> */
/* @0x230f9c ldr r3, [r4, #0x34] */
/* @0x230fa0 ldr r0, [r4, #0x48] */
/* @0x230fa4 cmp r3, r5 */
/* @0x230fa8 bgt 0x230f84 <ov_clear+0xc0> */
/* @0x230fac bl 0xb655c <free@plt> */
/* @0x230fb0 ldr r0, [r4, #0x4c] */
/* @0x230fb4 bl 0xb655c <free@plt> */
/* @0x230fb8 b 0x230f00 <ov_clear+0x3c> */

/* ── FUNC 0x230fbc · anon_230fbc · size=460 · insn=115 */
/* @0x230fbc push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x230fc0 subs r8, r0, #0 */
/* @0x230fc4 sub sp, sp, #20 */
/* @0x230fc8 mov r6, r1 */
/* @0x230fcc mov r7, r2 */
/* @0x230fd0 mov r5, r3 */
/* @0x230fd4 ldr r1, [sp, #0x34] */
/* @0x230fd8 beq 0x23116c <ov_clear+0x2a8> */
/* @0x230fdc cmp r1, #0 */
/* @0x230fe0 beq 0x23116c <ov_clear+0x2a8> */
/* @0x230fe4 mov r12, #1 */
/* @0x230fe8 mov r2, #0 */
/* @0x230fec mov r3, #0 */
/* @0x230ff0 str r12, [sp] */
/* @0x230ff4 blx r1 */
/* @0x230ff8 mov r9, r0 */
/* @0x230ffc mov r12, #0 */
/* @0x231000 mov r2, #664 */
/* @0x231004 mov r1, r12 */
/* @0x231008 mov r0, r6 */
/* @0x23100c str r12, [sp, #0x8] */
/* @0x231010 add r4, r6, #24 */
/* @0x231014 str r12, [sp, #0xc] */
/* @0x231018 bl 0xb65b0 <memset@plt> */
/* @0x23101c add r12, sp, #44 */
/* @0x231020 ldmib r12, {r0, r1, r2, r3} */
/* @0x231024 mov r12, r6 */
/* @0x231028 str r8, [r12], #648 */
/* @0x23102c stm r12, {r0, r1, r2, r3} */
/* @0x231030 mov r0, r4 */
/* @0x231034 bl 0x234b04 <ogg_sync_init> */
/* @0x231038 cmp r7, #0 */
/* @0x23103c beq 0x231064 <ov_clear+0x1a0> */
/* @0x231040 mov r1, r5 */
/* @0x231044 mov r0, r4 */
/* @0x231048 bl 0x234b8c <ogg_sync_buffer> */
/* @0x23104c mov r1, r7 */
/* @0x231050 mov r2, r5 */
/* @0x231054 bl 0xb65bc <memcpy@plt> */
/* @0x231058 mov r0, r4 */
/* @0x23105c mov r1, r5 */
/* @0x231060 bl 0x234c54 <ogg_sync_wrote> */
/* @0x231064 cmn r9, #1 */
/* @0x231068 mov r7, #1 */
/* @0x23106c mov r1, #32 */
/* @0x231070 str r7, [r6, #0x34] */
/* @0x231074 movne r3, #1 */
/* @0x231078 mov r0, r7 */
/* @0x23107c strne r3, [r6, #0x4] */
/* @0x231080 mov r4, #0 */
/* @0x231084 bl 0xb6c34 <calloc@plt> */
/* @0x231088 mov r1, #16 */
/* @0x23108c str r0, [r6, #0x48] */
/* @0x231090 mov r0, r7 */
/* @0x231094 bl 0xb6c34 <calloc@plt> */
/* @0x231098 mvn r1, #0 */
/* @0x23109c str r0, [r6, #0x4c] */
/* @0x2310a0 add r0, r6, #120 */
/* @0x2310a4 bl 0x2341a4 <ogg_stream_init> */
/* @0x2310a8 ldr r1, [r6, #0x48] */
/* @0x2310ac ldr r2, [r6, #0x4c] */
/* @0x2310b0 add r3, sp, #12 */
/* @0x2310b4 str r4, [sp, #0x4] */
/* @0x2310b8 mov r0, r6 */
/* @0x2310bc str r3, [sp] */
/* @0x2310c0 add r3, sp, #8 */
/* @0x2310c4 bl 0x230334 <vorbis_packet_blocksize+0x6b8> */
/* @0x2310c8 subs r8, r0, #0 */
/* @0x2310cc blt 0x231174 <ov_clear+0x2b0> */
/* @0x2310d0 ldr r0, [sp, #0xc] */
/* @0x2310d4 mov r1, #4 */
/* @0x2310d8 mov r5, #0 */
/* @0x2310dc add r0, r0, #2 */
/* @0x2310e0 bl 0xb6c34 <calloc@plt> */
/* @0x2310e4 ldr lr, [r6, #0x1c8] */
/* @0x2310e8 ldr r12, [sp, #0xc] */
/* @0x2310ec ldr r4, [sp, #0x8] */
/* @0x2310f0 str lr, [r6, #0x5c] */
/* @0x2310f4 lsl r2, r12, #2 */
/* @0x2310f8 mov r1, r4 */
/* @0x2310fc mov r3, r0 */
/* @0x231100 add r0, r0, #8 */
/* @0x231104 str r3, [r6, #0x40] */
/* @0x231108 str lr, [r3] */
/* @0x23110c str r12, [r3, #0x4] */
/* @0x231110 bl 0xb65bc <memcpy@plt> */
/* @0x231114 mov r1, #8 */
/* @0x231118 mov r0, r7 */
/* @0x23111c bl 0xb6c34 <calloc@plt> */
/* @0x231120 mov r1, #8 */
/* @0x231124 mov r9, r0 */
/* @0x231128 str r0, [r6, #0x38] */
/* @0x23112c mov r0, r7 */
/* @0x231130 bl 0xb6c34 <calloc@plt> */
/* @0x231134 ldrd r2, r3, [r6, #8] */
/* @0x231138 str r7, [r6, #0x58] */
/* @0x23113c mov r1, r4 */
/* @0x231140 mov r4, #0 */
/* @0x231144 str r0, [r6, #0x3c] */
/* @0x231148 strd r4, r5, [r9] */
/* @0x23114c strd r2, r3, [r0] */
/* @0x231150 cmp r1, #0 */
/* @0x231154 beq 0x231160 <ov_clear+0x29c> */
/* @0x231158 mov r0, r1 */
/* @0x23115c bl 0xb655c <free@plt> */
/* @0x231160 mov r0, r8 */
/* @0x231164 add sp, sp, #20 */
/* @0x231168 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x23116c mvn r9, #0 */
/* @0x231170 b 0x230ffc <ov_clear+0x138> */
/* @0x231174 str r4, [r6] */
/* @0x231178 mov r0, r6 */
/* @0x23117c bl 0x230ec4 <ov_clear> */
/* @0x231180 ldr r1, [sp, #0x8] */
/* @0x231184 b 0x231150 <ov_clear+0x28c> */

/* ── FUNC 0x231188 · ov_test_callbacks · size=44 · insn=11 */
/* @0x231188 push {r4, r5, r6, r7} */
/* @0x23118c mov r7, r0 */
/* @0x231190 mov r6, r1 */
/* @0x231194 mov r5, r2 */
/* @0x231198 mov r4, r3 */
/* @0x23119c mov r0, r7 */
/* @0x2311a0 mov r1, r6 */
/* @0x2311a4 mov r2, r5 */
/* @0x2311a8 mov r3, r4 */
/* @0x2311ac pop {r4, r5, r6, r7} */
/* @0x2311b0 b 0x230fbc <ov_clear+0xf8> */

/* ── FUNC 0x2311b4 · ov_test · size=80 · insn=20 */
/* @0x2311b4 ldr r12, [pc, #0x44] */
/* @0x2311b8 push {r4, r5, r6, lr} */
/* @0x2311bc add r12, pc, r12 */
/* @0x2311c0 mov lr, r3 */
/* @0x2311c4 mov r6, r0 */
/* @0x2311c8 mov r5, r1 */
/* @0x2311cc mov r4, r2 */
/* @0x2311d0 ldm r12, {r0, r1, r2, r3} */
/* @0x2311d4 sub sp, sp, #32 */
/* @0x2311d8 add r12, sp, #16 */
/* @0x2311dc stm r12, {r0, r1, r2, r3} */
/* @0x2311e0 stm sp, {r0, r1, r2, r3} */
/* @0x2311e4 mov r0, r6 */
/* @0x2311e8 mov r1, r5 */
/* @0x2311ec mov r2, r4 */
/* @0x2311f0 mov r3, lr */
/* @0x2311f4 bl 0x231188 <ov_test_callbacks> */
/* @0x2311f8 add sp, sp, #32 */
/* @0x2311fc pop {r4, r5, r6, pc} */
/* @0x231200 ldrsbeq r6, [r12], -r0 */

/* ── FUNC 0x231204 · ov_streams · size=8 · insn=2 */
/* @0x231204 ldr r0, [r0, #0x34] */
/* @0x231208 bx lr */

/* ── FUNC 0x23120c · ov_seekable · size=8 · insn=2 */
/* @0x23120c ldr r0, [r0, #0x4] */
/* @0x231210 bx lr */

/* ── FUNC 0x231214 · ov_bitrate_instant · size=108 · insn=27 */
/* @0x231214 push {r3, r4, r5, lr} */
/* @0x231218 mov r4, r0 */
/* @0x23121c ldr r3, [r0, #0x4] */
/* @0x231220 ldr r2, [r0, #0x58] */
/* @0x231224 cmp r3, #0 */
/* @0x231228 ldrne r5, [r0, #0x60] */
/* @0x23122c moveq r5, r3 */
/* @0x231230 cmp r2, #1 */
/* @0x231234 ble 0x231278 <ov_bitrate_instant+0x64> */
/* @0x231238 ldrd r2, r3, [r0, #112] */
/* @0x23123c orrs r1, r2, r3 */
/* @0x231240 beq 0x231270 <ov_bitrate_instant+0x5c> */
/* @0x231244 ldrd r0, r1, [r0, #104] */
/* @0x231248 bl 0x319414 <__aeabi_ldivmod> */
/* @0x23124c ldr r1, [r4, #0x48] */
/* @0x231250 mov r2, #0 */
/* @0x231254 mov r3, #0 */
/* @0x231258 add r5, r1, r5, lsl #5 */
/* @0x23125c ldr r1, [r5, #0x8] */
/* @0x231260 strd r2, r3, [r4, #104] */
/* @0x231264 strd r2, r3, [r4, #112] */
/* @0x231268 mul r0, r0, r1 */
/* @0x23126c pop {r3, r4, r5, pc} */
/* @0x231270 mvn r0, #0 */
/* @0x231274 pop {r3, r4, r5, pc} */
/* @0x231278 mvn r0, #130 */
/* @0x23127c pop {r3, r4, r5, pc} */

/* ── FUNC 0x231280 · ov_serialnumber · size=88 · insn=22 */
/* @0x231280 ldr r2, [r0, #0x4] */
/* @0x231284 ldr r3, [r0, #0x34] */
/* @0x231288 cmp r2, #0 */
/* @0x23128c bne 0x2312b0 <ov_serialnumber+0x30> */
/* @0x231290 cmp r1, r3 */
/* @0x231294 subge r1, r3, #1 */
/* @0x231298 bge 0x231290 <ov_serialnumber+0x10> */
/* @0x23129c cmp r1, #0 */
/* @0x2312a0 mvn r1, #0 */
/* @0x2312a4 bge 0x231290 <ov_serialnumber+0x10> */
/* @0x2312a8 ldr r0, [r0, #0x5c] */
/* @0x2312ac bx lr */
/* @0x2312b0 cmp r3, r1 */
/* @0x2312b4 bgt 0x2312c4 <ov_serialnumber+0x44> */
/* @0x2312b8 sub r1, r3, #1 */
/* @0x2312bc cmp r3, r1 */
/* @0x2312c0 ble 0x2312b8 <ov_serialnumber+0x38> */
/* @0x2312c4 cmp r1, #0 */
/* @0x2312c8 blt 0x2312a8 <ov_serialnumber+0x28> */
/* @0x2312cc ldr r3, [r0, #0x40] */
/* @0x2312d0 ldr r0, [r3, r1, lsl #2] */
/* @0x2312d4 bx lr */

/* ── FUNC 0x2312d8 · ov_raw_total · size=180 · insn=45 */
/* @0x2312d8 push {r3, r4, r5, r6, r7, lr} */
/* @0x2312dc mov r7, r0 */
/* @0x2312e0 ldr r3, [r0, #0x58] */
/* @0x2312e4 cmp r3, #1 */
/* @0x2312e8 ble 0x231374 <ov_raw_total+0x9c> */
/* @0x2312ec ldr r3, [r0, #0x4] */
/* @0x2312f0 cmp r3, #0 */
/* @0x2312f4 beq 0x231374 <ov_raw_total+0x9c> */
/* @0x2312f8 ldr r3, [r0, #0x34] */
/* @0x2312fc cmp r3, r1 */
/* @0x231300 ble 0x231374 <ov_raw_total+0x9c> */
/* @0x231304 cmp r1, #0 */
/* @0x231308 blt 0x231330 <ov_raw_total+0x58> */
/* @0x23130c add r1, r1, #1 */
/* @0x231310 ldr r3, [r0, #0x38] */
/* @0x231314 lsl r1, r1, #3 */
/* @0x231318 add r2, r3, r1 */
/* @0x23131c ldrd r0, r1, [r1, r3] */
/* @0x231320 ldrd r2, r3, [r2, #-8] */
/* @0x231324 subs r0, r0, r2 */
/* @0x231328 sbc r1, r1, r3 */
/* @0x23132c pop {r3, r4, r5, r6, r7, pc} */
/* @0x231330 cmp r3, #0 */
/* @0x231334 ble 0x231380 <ov_raw_total+0xa8> */
/* @0x231338 mov r4, #0 */
/* @0x23133c mov r5, #0 */
/* @0x231340 mov r6, #0 */
/* @0x231344 mov r1, r6 */
/* @0x231348 mov r0, r7 */
/* @0x23134c bl 0x2312d8 <ov_raw_total> */
/* @0x231350 ldr r3, [r7, #0x34] */
/* @0x231354 add r6, r6, #1 */
/* @0x231358 adds r4, r4, r0 */
/* @0x23135c adc r5, r5, r1 */
/* @0x231360 cmp r3, r6 */
/* @0x231364 bgt 0x231344 <ov_raw_total+0x6c> */
/* @0x231368 mov r0, r4 */
/* @0x23136c mov r1, r5 */
/* @0x231370 pop {r3, r4, r5, r6, r7, pc} */
/* @0x231374 mvn r0, #130 */
/* @0x231378 mvn r1, #0 */
/* @0x23137c pop {r3, r4, r5, r6, r7, pc} */
/* @0x231380 mov r0, #0 */
/* @0x231384 mov r1, #0 */
/* @0x231388 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x23138c · ov_pcm_total · size=152 · insn=38 */
/* @0x23138c push {r3, r4, r5, r6, r7, lr} */
/* @0x231390 mov r7, r0 */
/* @0x231394 ldr r3, [r0, #0x58] */
/* @0x231398 cmp r3, #1 */
/* @0x23139c ble 0x231418 <ov_pcm_total+0x8c> */
/* @0x2313a0 ldr r3, [r0, #0x4] */
/* @0x2313a4 cmp r3, #0 */
/* @0x2313a8 beq 0x231418 <ov_pcm_total+0x8c> */
/* @0x2313ac ldr r3, [r0, #0x34] */
/* @0x2313b0 cmp r3, r1 */
/* @0x2313b4 ble 0x231418 <ov_pcm_total+0x8c> */
/* @0x2313b8 cmp r1, #0 */
/* @0x2313bc blt 0x2313d4 <ov_pcm_total+0x48> */
/* @0x2313c0 ldr r3, [r0, #0x44] */
/* @0x2313c4 add r1, r3, r1, lsl #4 */
/* @0x2313c8 ldr r0, [r1, #0x8] */
/* @0x2313cc ldr r1, [r1, #0xc] */
/* @0x2313d0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2313d4 cmp r3, #0 */
/* @0x2313d8 mov r4, #0 */
/* @0x2313dc mov r5, #0 */
/* @0x2313e0 ble 0x23140c <ov_pcm_total+0x80> */
/* @0x2313e4 mov r6, #0 */
/* @0x2313e8 mov r1, r6 */
/* @0x2313ec mov r0, r7 */
/* @0x2313f0 bl 0x23138c <ov_pcm_total> */
/* @0x2313f4 ldr r3, [r7, #0x34] */
/* @0x2313f8 add r6, r6, #1 */
/* @0x2313fc adds r4, r4, r0 */
/* @0x231400 adc r5, r5, r1 */
/* @0x231404 cmp r6, r3 */
/* @0x231408 blt 0x2313e8 <ov_pcm_total+0x5c> */
/* @0x23140c mov r0, r4 */
/* @0x231410 mov r1, r5 */
/* @0x231414 pop {r3, r4, r5, r6, r7, pc} */
/* @0x231418 mvn r0, #130 */
/* @0x23141c mvn r1, #0 */
/* @0x231420 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x231424 · ov_time_total · size=184 · insn=46 */
/* @0x231424 push {r3, r4, r5, r6, r7, lr} */
/* @0x231428 mov r6, r0 */
/* @0x23142c ldr r3, [r0, #0x58] */
/* @0x231430 cmp r3, #1 */
/* @0x231434 ble 0x2314d0 <ov_time_total+0xac> */
/* @0x231438 ldr r3, [r0, #0x4] */
/* @0x23143c cmp r3, #0 */
/* @0x231440 beq 0x2314d0 <ov_time_total+0xac> */
/* @0x231444 ldr r3, [r0, #0x34] */
/* @0x231448 cmp r3, r1 */
/* @0x23144c ble 0x2314d0 <ov_time_total+0xac> */
/* @0x231450 cmp r1, #0 */
/* @0x231454 blt 0x23148c <ov_time_total+0x68> */
/* @0x231458 ldr r3, [r0, #0x44] */
/* @0x23145c mov r12, #1000 */
/* @0x231460 ldr r2, [r0, #0x48] */
/* @0x231464 add r3, r3, r1, lsl #4 */
/* @0x231468 add r1, r2, r1, lsl #5 */
/* @0x23146c ldr r0, [r3, #0x8] */
/* @0x231470 ldr r2, [r1, #0x8] */
/* @0x231474 ldr lr, [r3, #0xc] */
/* @0x231478 umull r0, r1, r0, r12 */
/* @0x23147c asr r3, r2, #31 */
/* @0x231480 mla r1, r12, lr, r1 */
/* @0x231484 bl 0x319414 <__aeabi_ldivmod> */
/* @0x231488 pop {r3, r4, r5, r6, r7, pc} */
/* @0x23148c cmp r3, #0 */
/* @0x231490 mov r4, #0 */
/* @0x231494 mov r5, #0 */
/* @0x231498 ble 0x2314c4 <ov_time_total+0xa0> */
/* @0x23149c mov r7, #0 */
/* @0x2314a0 mov r1, r7 */
/* @0x2314a4 mov r0, r6 */
/* @0x2314a8 bl 0x231424 <ov_time_total> */
/* @0x2314ac ldr r3, [r6, #0x34] */
/* @0x2314b0 add r7, r7, #1 */
/* @0x2314b4 adds r4, r4, r0 */
/* @0x2314b8 adc r5, r5, r1 */
/* @0x2314bc cmp r7, r3 */
/* @0x2314c0 blt 0x2314a0 <ov_time_total+0x7c> */
/* @0x2314c4 mov r0, r4 */
/* @0x2314c8 mov r1, r5 */
/* @0x2314cc pop {r3, r4, r5, r6, r7, pc} */
/* @0x2314d0 mvn r0, #130 */
/* @0x2314d4 mvn r1, #0 */
/* @0x2314d8 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2314dc · ov_bitrate · size=316 · insn=79 */
/* @0x2314dc push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2314e0 ldr r3, [r0, #0x58] */
/* @0x2314e4 cmp r3, #1 */
/* @0x2314e8 ble 0x231544 <ov_bitrate+0x68> */
/* @0x2314ec ldr r2, [r0, #0x34] */
/* @0x2314f0 cmp r2, r1 */
/* @0x2314f4 ble 0x231544 <ov_bitrate+0x68> */
/* @0x2314f8 ldr r3, [r0, #0x4] */
/* @0x2314fc cmp r3, #0 */
/* @0x231500 bne 0x23154c <ov_bitrate+0x70> */
/* @0x231504 cmp r1, #0 */
/* @0x231508 mov r1, r3 */
/* @0x23150c bne 0x2314f0 <ov_bitrate+0x14> */
/* @0x231510 ldr r3, [r0, #0x48] */
/* @0x231514 ldr r0, [r3, #0x10] */
/* @0x231518 cmp r0, #0 */
/* @0x23151c ble 0x231524 <ov_bitrate+0x48> */
/* @0x231520 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x231524 ldr r0, [r3, #0xc] */
/* @0x231528 cmp r0, #0 */
/* @0x23152c ble 0x2315d8 <ov_bitrate+0xfc> */
/* @0x231530 ldr r3, [r3, #0x14] */
/* @0x231534 cmp r3, #0 */
/* @0x231538 addgt r0, r0, r3 */
/* @0x23153c asrgt r0, r0, #1 */
/* @0x231540 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x231544 mvn r0, #130 */
/* @0x231548 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x23154c cmp r1, #0 */
/* @0x231550 bge 0x2315e0 <ov_bitrate+0x104> */
/* @0x231554 cmp r2, #0 */
/* @0x231558 ble 0x2315cc <ov_bitrate+0xf0> */
/* @0x23155c ldr r1, [r0, #0x38] */
/* @0x231560 mov r6, #0 */
/* @0x231564 ldr r12, [r0, #0x3c] */
/* @0x231568 mov r7, #0 */
/* @0x23156c add lr, r1, r2, lsl #3 */
/* @0x231570 sub r12, r12, #8 */
/* @0x231574 ldrd r2, r3, [r1, #8]! */
/* @0x231578 ldrd r8, r9, [r12, #8]! */
/* @0x23157c subs r2, r2, r8 */
/* @0x231580 sbc r3, r3, r9 */
/* @0x231584 lsl r5, r3, #3 */
/* @0x231588 lsl r4, r2, #3 */
/* @0x23158c adds r6, r6, r4 */
/* @0x231590 orr r5, r5, r2, lsr #29 */
/* @0x231594 adc r7, r7, r5 */
/* @0x231598 cmp r1, lr */
/* @0x23159c bne 0x231574 <ov_bitrate+0x98> */
/* @0x2315a0 mov r3, #1000 */
/* @0x2315a4 umull r4, r5, r6, r3 */
/* @0x2315a8 mla r5, r3, r7, r5 */
/* @0x2315ac mvn r1, #0 */
/* @0x2315b0 bl 0x231424 <ov_time_total> */
/* @0x2315b4 mov r2, r0 */
/* @0x2315b8 mov r3, r1 */
/* @0x2315bc mov r0, r4 */
/* @0x2315c0 mov r1, r5 */
/* @0x2315c4 bl 0x319414 <__aeabi_ldivmod> */
/* @0x2315c8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2315cc mov r4, #0 */
/* @0x2315d0 mov r5, #0 */
/* @0x2315d4 b 0x2315ac <ov_bitrate+0xd0> */
/* @0x2315d8 mvn r0, #0 */
/* @0x2315dc pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2315e0 add r3, r1, #1 */
/* @0x2315e4 ldr lr, [r0, #0x3c] */
/* @0x2315e8 ldr r2, [r0, #0x38] */
/* @0x2315ec mov r12, #8000 */
/* @0x2315f0 lsl r3, r3, #3 */
/* @0x2315f4 add lr, lr, r3 */
/* @0x2315f8 add r2, r2, r3 */
/* @0x2315fc ldrd r4, r5, [lr, #-8] */
/* @0x231600 ldrd r2, r3, [r2] */
/* @0x231604 subs r2, r2, r4 */
/* @0x231608 sbc r3, r3, r5 */
/* @0x23160c umull r4, r5, r2, r12 */
/* @0x231610 mla r5, r12, r3, r5 */
/* @0x231614 b 0x2315b0 <ov_bitrate+0xd4> */

/* ── FUNC 0x231618 · ov_raw_seek · size=1196 · insn=299 */
/* @0x231618 ldr r12, [pc, #0x4a0] */
/* @0x23161c ldr r1, [r0, #0x58] */
/* @0x231620 ldr r12, [pc, r12] */
/* @0x231624 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x231628 mov r7, r3 */
/* @0x23162c ldr r3, [r12] */
/* @0x231630 sub sp, sp, #460 */
/* @0x231634 cmp r1, #1 */
/* @0x231638 mov r11, r0 */
/* @0x23163c mov r6, r2 */
/* @0x231640 str r12, [sp, #0x8] */
/* @0x231644 str r3, [sp, #0x1c4] */
/* @0x231648 ble 0x231a7c <ov_raw_seek+0x464> */
/* @0x23164c ldr r3, [r0, #0x4] */
/* @0x231650 cmp r3, #0 */
/* @0x231654 beq 0x231a84 <ov_raw_seek+0x46c> */
/* @0x231658 cmp r6, #0 */
/* @0x23165c sbcs r0, r7, #0 */
/* @0x231660 blt 0x231a7c <ov_raw_seek+0x464> */
/* @0x231664 ldrd r2, r3, [r11, #16] */
/* @0x231668 cmp r2, r6 */
/* @0x23166c sbcs r12, r3, r7 */
/* @0x231670 blt 0x231a7c <ov_raw_seek+0x464> */
/* @0x231674 cmp r1, #2 */
/* @0x231678 bne 0x231988 <ov_raw_seek+0x370> */
/* @0x23167c add r12, r11, #480 */
/* @0x231680 str r12, [sp, #0x1c] */
/* @0x231684 add r8, r11, #120 */
/* @0x231688 ldr r1, [r11, #0x5c] */
/* @0x23168c mvn r5, #0 */
/* @0x231690 str r5, [r11, #0x50] */
/* @0x231694 mov r0, r8 */
/* @0x231698 str r5, [r11, #0x54] */
/* @0x23169c bl 0x2352f4 <ogg_stream_reset_serialno> */
/* @0x2316a0 ldr r0, [sp, #0x1c] */
/* @0x2316a4 bl 0x22723c <vorbis_synthesis_restart> */
/* @0x2316a8 mov r0, r11 */
/* @0x2316ac mov r2, r6 */
/* @0x2316b0 mov r3, r7 */
/* @0x2316b4 bl 0x22ffe0 <vorbis_packet_blocksize+0x364> */
/* @0x2316b8 cmp r0, #0 */
/* @0x2316bc bne 0x231a8c <ov_raw_seek+0x474> */
/* @0x2316c0 add r7, sp, #88 */
/* @0x2316c4 mov r10, r0 */
/* @0x2316c8 ldr r1, [r11, #0x5c] */
/* @0x2316cc movw r12, #0xfe80 */
/* @0x2316d0 mov r0, r7 */
/* @0x2316d4 str r12, [sp, #0x18] */
/* @0x2316d8 str r10, [sp, #0xc] */
/* @0x2316dc bl 0x2341a4 <ogg_stream_init> */
/* @0x2316e0 mov r0, r7 */
/* @0x2316e4 add r6, sp, #40 */
/* @0x2316e8 bl 0x235294 <ogg_stream_reset> */
/* @0x2316ec ldr r12, [sp, #0x18] */
/* @0x2316f0 mov r9, r10 */
/* @0x2316f4 str r5, [sp, #0x10] */
/* @0x2316f8 movt r12, #0xffff */
/* @0x2316fc str r5, [sp, #0x14] */
/* @0x231700 str r12, [sp, #0x18] */
/* @0x231704 add r12, r11, #560 */
/* @0x231708 str r10, [sp, #0x20] */
/* @0x23170c str r12, [sp, #0x24] */
/* @0x231710 ldr r3, [r11, #0x58] */
/* @0x231714 cmp r3, #2 */
/* @0x231718 bgt 0x231818 <ov_raw_seek+0x200> */
/* @0x23171c cmp r9, #0 */
/* @0x231720 bne 0x231a34 <ov_raw_seek+0x41c> */
/* @0x231724 mvn r3, #0 */
/* @0x231728 mov r0, r11 */
/* @0x23172c mov r1, r6 */
/* @0x231730 mvn r2, #0 */
/* @0x231734 bl 0x22fd0c <vorbis_packet_blocksize+0x90> */
/* @0x231738 mov r4, r0 */
/* @0x23173c mov r5, r1 */
/* @0x231740 cmp r4, #0 */
/* @0x231744 sbcs r3, r5, #0 */
/* @0x231748 blt 0x231a54 <ov_raw_seek+0x43c> */
/* @0x23174c ldr r3, [r11, #0x58] */
/* @0x231750 cmp r3, #2 */
/* @0x231754 bgt 0x23194c <ov_raw_seek+0x334> */
/* @0x231758 mov r0, r6 */
/* @0x23175c bl 0x23409c <ogg_page_serialno> */
/* @0x231760 mov r12, r0 */
/* @0x231764 ldr r0, [r11, #0x34] */
/* @0x231768 cmp r0, #0 */
/* @0x23176c ble 0x231a44 <ov_raw_seek+0x42c> */
/* @0x231770 ldr r2, [r11, #0x40] */
/* @0x231774 ldr r3, [r2] */
/* @0x231778 cmp r3, r12 */
/* @0x23177c beq 0x231a48 <ov_raw_seek+0x430> */
/* @0x231780 mov r3, #0 */
/* @0x231784 add r3, r3, #1 */
/* @0x231788 cmp r3, r0 */
/* @0x23178c beq 0x231710 <ov_raw_seek+0xf8> */
/* @0x231790 ldr r1, [r2, #0x4]! */
/* @0x231794 cmp r1, r12 */
/* @0x231798 bne 0x231784 <ov_raw_seek+0x16c> */
/* @0x23179c lsl r10, r3, #3 */
/* @0x2317a0 str r3, [r11, #0x60] */
/* @0x2317a4 mov r1, r12 */
/* @0x2317a8 str r12, [r11, #0x5c] */
/* @0x2317ac mov r0, r8 */
/* @0x2317b0 str r12, [sp, #0x4] */
/* @0x2317b4 bl 0x2352f4 <ogg_stream_reset_serialno> */
/* @0x2317b8 ldr r12, [sp, #0x4] */
/* @0x2317bc mov r0, r7 */
/* @0x2317c0 mov r1, r12 */
/* @0x2317c4 bl 0x2352f4 <ogg_stream_reset_serialno> */
/* @0x2317c8 ldr r3, [r11, #0x3c] */
/* @0x2317cc mov r0, #3 */
/* @0x2317d0 str r0, [r11, #0x58] */
/* @0x2317d4 ldrd r2, r3, [r3, r10] */
/* @0x2317d8 cmp r2, r4 */
/* @0x2317dc sbcs r1, r3, r5 */
/* @0x2317e0 movlt r10, #0 */
/* @0x2317e4 movge r10, #1 */
/* @0x2317e8 mov r1, r6 */
/* @0x2317ec mov r0, r8 */
/* @0x2317f0 bl 0x234eac <ogg_stream_pagein> */
/* @0x2317f4 mov r1, r6 */
/* @0x2317f8 mov r0, r7 */
/* @0x2317fc bl 0x234eac <ogg_stream_pagein> */
/* @0x231800 mov r0, r6 */
/* @0x231804 bl 0x233fa0 <ogg_page_eos> */
/* @0x231808 ldr r3, [r11, #0x58] */
/* @0x23180c cmp r3, #2 */
/* @0x231810 str r0, [sp, #0xc] */
/* @0x231814 ble 0x23171c <ov_raw_seek+0x104> */
/* @0x231818 add r4, sp, #56 */
/* @0x23181c mov r0, r7 */
/* @0x231820 mov r1, r4 */
/* @0x231824 bl 0x235328 <ogg_stream_packetout> */
/* @0x231828 cmp r0, #0 */
/* @0x23182c ble 0x23171c <ov_raw_seek+0x104> */
/* @0x231830 ldr r0, [r11, #0x60] */
/* @0x231834 ldr r3, [r11, #0x48] */
/* @0x231838 add r0, r3, r0, lsl #5 */
/* @0x23183c ldr r1, [r0, #0x1c] */
/* @0x231840 cmp r1, #0 */
/* @0x231844 beq 0x231a24 <ov_raw_seek+0x40c> */
/* @0x231848 mov r1, r4 */
/* @0x23184c bl 0x22fc7c <vorbis_packet_blocksize> */
/* @0x231850 subs r4, r0, #0 */
/* @0x231854 blt 0x231a68 <ov_raw_seek+0x450> */
/* @0x231858 rsbs r3, r10, #1 */
/* @0x23185c ldr r12, [sp, #0xc] */
/* @0x231860 movlo r3, #0 */
/* @0x231864 cmp r12, #0 */
/* @0x231868 moveq r3, #0 */
/* @0x23186c cmp r3, #0 */
/* @0x231870 bne 0x2319e4 <ov_raw_seek+0x3cc> */
/* @0x231874 cmp r9, #0 */
/* @0x231878 addne r9, r9, r4 */
/* @0x23187c ldrne r12, [sp, #0x20] */
/* @0x231880 addne r12, r12, r9, asr #2 */
/* @0x231884 strne r12, [sp, #0x20] */
/* @0x231888 ldr r12, [sp, #0x18] */
/* @0x23188c add r2, sp, #456 */
/* @0x231890 ldrd r0, r1, [r2, r12] */
/* @0x231894 ldrd r2, r3, [sp, #16] */
/* @0x231898 cmp r1, r3 */
/* @0x23189c cmpeq r0, r2 */
/* @0x2318a0 beq 0x2319dc <ov_raw_seek+0x3c4> */
/* @0x2318a4 ldr r5, [r11, #0x60] */
/* @0x2318a8 ldr lr, [r11, #0x44] */
/* @0x2318ac lsl r4, r5, #4 */
/* @0x2318b0 ldrd r2, r3, [lr, r4] */
/* @0x2318b4 subs r0, r0, r2 */
/* @0x2318b8 sbc r1, r1, r3 */
/* @0x2318bc cmp r0, #0 */
/* @0x2318c0 sbcs r3, r1, #0 */
/* @0x2318c4 movlt r0, #0 */
/* @0x2318c8 movlt r1, #0 */
/* @0x2318cc cmp r5, #0 */
/* @0x2318d0 ble 0x2318f0 <ov_raw_seek+0x2d8> */
/* @0x2318d4 add r4, lr, r4 */
/* @0x2318d8 ldrd r2, r3, [lr, #8] */
/* @0x2318dc add lr, lr, #16 */
/* @0x2318e0 adds r0, r0, r2 */
/* @0x2318e4 adc r1, r1, r3 */
/* @0x2318e8 cmp lr, r4 */
/* @0x2318ec bne 0x2318d8 <ov_raw_seek+0x2c0> */
/* @0x2318f0 ldr r12, [sp, #0x20] */
/* @0x2318f4 subs r0, r0, r12 */
/* @0x2318f8 sbc r1, r1, r12, asr #31 */
/* @0x2318fc cmp r0, #0 */
/* @0x231900 sbcs r2, r1, #0 */
/* @0x231904 movlt r2, #0 */
/* @0x231908 movlt r3, #0 */
/* @0x23190c strdlt r2, r3, [r11, #80] */
/* @0x231910 strdge r0, r1, [r11, #80] */
/* @0x231914 mov r0, r7 */
/* @0x231918 bl 0x234150 <ogg_stream_clear> */
/* @0x23191c mov r0, #0 */
/* @0x231920 mov r2, #0 */
/* @0x231924 mov r3, #0 */
/* @0x231928 strd r2, r3, [r11, #104] */
/* @0x23192c strd r2, r3, [r11, #112] */
/* @0x231930 ldr r12, [sp, #0x8] */
/* @0x231934 ldr r2, [sp, #0x1c4] */
/* @0x231938 ldr r3, [r12] */
/* @0x23193c cmp r2, r3 */
/* @0x231940 bne 0x231abc <ov_raw_seek+0x4a4> */
/* @0x231944 add sp, sp, #460 */
/* @0x231948 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x23194c ldr r3, [r11, #0x5c] */
/* @0x231950 mov r0, r6 */
/* @0x231954 str r3, [sp, #0x4] */
/* @0x231958 bl 0x23409c <ogg_page_serialno> */
/* @0x23195c ldr r3, [sp, #0x4] */
/* @0x231960 cmp r3, r0 */
/* @0x231964 beq 0x231978 <ov_raw_seek+0x360> */
/* @0x231968 mov r0, r6 */
/* @0x23196c bl 0x233f90 <ogg_page_bos> */
/* @0x231970 cmp r0, #0 */
/* @0x231974 bne 0x2319f4 <ov_raw_seek+0x3dc> */
/* @0x231978 ldr r3, [r11, #0x58] */
/* @0x23197c cmp r3, #2 */
/* @0x231980 bgt 0x2317e8 <ov_raw_seek+0x1d0> */
/* @0x231984 b 0x231758 <ov_raw_seek+0x140> */
/* @0x231988 ldr r1, [r11, #0x60] */
/* @0x23198c ldr r0, [r11, #0x38] */
/* @0x231990 lsl r1, r1, #3 */
/* @0x231994 ldrd r2, r3, [r0, r1] */
/* @0x231998 cmp r6, r2 */
/* @0x23199c sbcs r12, r7, r3 */
/* @0x2319a0 blt 0x2319b8 <ov_raw_seek+0x3a0> */
/* @0x2319a4 add r1, r0, r1 */
/* @0x2319a8 ldrd r2, r3, [r1, #8] */
/* @0x2319ac cmp r6, r2 */
/* @0x2319b0 sbcs r0, r7, r3 */
/* @0x2319b4 blt 0x23167c <ov_raw_seek+0x64> */
/* @0x2319b8 add r12, r11, #480 */
/* @0x2319bc str r12, [sp, #0x1c] */
/* @0x2319c0 mov r0, r12 */
/* @0x2319c4 bl 0x2272ac <vorbis_dsp_clear> */
/* @0x2319c8 add r0, r11, #560 */
/* @0x2319cc bl 0x227208 <vorbis_block_clear> */
/* @0x2319d0 mov r3, #2 */
/* @0x2319d4 str r3, [r11, #0x58] */
/* @0x2319d8 b 0x231684 <ov_raw_seek+0x6c> */
/* @0x2319dc mov r9, r4 */
/* @0x2319e0 b 0x231710 <ov_raw_seek+0xf8> */
/* @0x2319e4 mov r0, r8 */
/* @0x2319e8 mov r1, #0 */
/* @0x2319ec bl 0x235328 <ogg_stream_packetout> */
/* @0x2319f0 b 0x231888 <ov_raw_seek+0x270> */
/* @0x2319f4 ldr r0, [sp, #0x1c] */
/* @0x2319f8 bl 0x2272ac <vorbis_dsp_clear> */
/* @0x2319fc ldr r0, [sp, #0x24] */
/* @0x231a00 bl 0x227208 <vorbis_block_clear> */
/* @0x231a04 mov r12, #2 */
/* @0x231a08 mov r0, r7 */
/* @0x231a0c str r12, [r11, #0x58] */
/* @0x231a10 bl 0x234150 <ogg_stream_clear> */
/* @0x231a14 ldr r3, [r11, #0x58] */
/* @0x231a18 cmp r3, #2 */
/* @0x231a1c bgt 0x2317e8 <ov_raw_seek+0x1d0> */
/* @0x231a20 b 0x231758 <ov_raw_seek+0x140> */
/* @0x231a24 mov r0, r8 */
/* @0x231a28 bl 0x235328 <ogg_stream_packetout> */
/* @0x231a2c cmp r9, #0 */
/* @0x231a30 beq 0x231724 <ov_raw_seek+0x10c> */
/* @0x231a34 mvn r2, #0 */
/* @0x231a38 mvn r3, #0 */
/* @0x231a3c strd r2, r3, [r11, #80] */
/* @0x231a40 b 0x231914 <ov_raw_seek+0x2fc> */
/* @0x231a44 beq 0x231710 <ov_raw_seek+0xf8> */
/* @0x231a48 mov r10, #0 */
/* @0x231a4c mov r3, r10 */
/* @0x231a50 b 0x2317a0 <ov_raw_seek+0x188> */
/* @0x231a54 mov r0, r11 */
/* @0x231a58 mvn r1, #0 */
/* @0x231a5c bl 0x23138c <ov_pcm_total> */
/* @0x231a60 strd r0, r1, [r11, #80] */
/* @0x231a64 b 0x231914 <ov_raw_seek+0x2fc> */
/* @0x231a68 mov r0, r8 */
/* @0x231a6c mov r1, #0 */
/* @0x231a70 bl 0x235328 <ogg_stream_packetout> */
/* @0x231a74 mov r4, #0 */
/* @0x231a78 b 0x231888 <ov_raw_seek+0x270> */
/* @0x231a7c mvn r0, #130 */
/* @0x231a80 b 0x231930 <ov_raw_seek+0x318> */
/* @0x231a84 mvn r0, #137 */
/* @0x231a88 b 0x231930 <ov_raw_seek+0x318> */
/* @0x231a8c str r5, [r11, #0x50] */
/* @0x231a90 add r0, sp, #88 */
/* @0x231a94 str r5, [r11, #0x54] */
/* @0x231a98 bl 0x234150 <ogg_stream_clear> */
/* @0x231a9c ldr r0, [sp, #0x1c] */
/* @0x231aa0 bl 0x2272ac <vorbis_dsp_clear> */
/* @0x231aa4 add r0, r11, #560 */
/* @0x231aa8 bl 0x227208 <vorbis_block_clear> */
/* @0x231aac mov r3, #2 */
/* @0x231ab0 mvn r0, #136 */
/* @0x231ab4 str r3, [r11, #0x58] */
/* @0x231ab8 b 0x231930 <ov_raw_seek+0x318> */
/* @0x231abc bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x231ac0 andseq r12, r11, r0, lsr r3 */

/* ── FUNC 0x231ac4 · anon_231ac4 · size=388 · insn=97 */
/* @0x231ac4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x231ac8 sub sp, sp, #60 */
/* @0x231acc ldr r3, [r0, #0x3c] */
/* @0x231ad0 mov r10, r0 */
/* @0x231ad4 ldr r11, [r0, #0x1c8] */
/* @0x231ad8 mvn r6, #0 */
/* @0x231adc ldr r1, [r0, #0x48] */
/* @0x231ae0 mvn r7, #0 */
/* @0x231ae4 ldrd r4, r5, [r3] */
/* @0x231ae8 str r11, [sp, #0x2c] */
/* @0x231aec strd r6, r7, [sp, #48] */
/* @0x231af0 bl 0x22fed4 <vorbis_packet_blocksize+0x258> */
/* @0x231af4 mov r9, r1 */
/* @0x231af8 ldr r1, [r10, #0x28c] */
/* @0x231afc mov r8, r0 */
/* @0x231b00 cmp r1, #0 */
/* @0x231b04 beq 0x231c1c <ov_raw_seek+0x604> */
/* @0x231b08 ldr r3, [r10, #0x294] */
/* @0x231b0c cmp r3, #0 */
/* @0x231b10 beq 0x231c1c <ov_raw_seek+0x604> */
/* @0x231b14 mov r12, #2 */
/* @0x231b18 ldr r0, [r10] */
/* @0x231b1c mov r2, #0 */
/* @0x231b20 mov r3, #0 */
/* @0x231b24 str r12, [sp] */
/* @0x231b28 blx r1 */
/* @0x231b2c ldr r3, [r10, #0x294] */
/* @0x231b30 ldr r0, [r10] */
/* @0x231b34 blx r3 */
/* @0x231b38 asr r1, r0, #31 */
/* @0x231b3c strd r0, r1, [r10, #16] */
/* @0x231b40 cmp r1, r7 */
/* @0x231b44 cmpeq r0, r6 */
/* @0x231b48 strd r0, r1, [r10, #8] */
/* @0x231b4c beq 0x231c40 <ov_raw_seek+0x628> */
/* @0x231b50 ldr r2, [r10, #0x40] */
/* @0x231b54 add r3, sp, #44 */
/* @0x231b58 add r12, sp, #48 */
/* @0x231b5c mov r0, r10 */
/* @0x231b60 add r1, r2, #8 */
/* @0x231b64 ldr r2, [r2, #0x4] */
/* @0x231b68 str r12, [sp] */
/* @0x231b6c bl 0x230048 <vorbis_packet_blocksize+0x3cc> */
/* @0x231b70 cmp r0, #0 */
/* @0x231b74 sbcs r3, r1, #0 */
/* @0x231b78 blt 0x231c14 <ov_raw_seek+0x5fc> */
/* @0x231b7c ldr r1, [r10, #0x40] */
/* @0x231b80 mov r12, #0 */
/* @0x231b84 ldrd r2, r3, [r10, #8] */
/* @0x231b88 mov r0, r10 */
/* @0x231b8c add lr, r1, #8 */
/* @0x231b90 ldrd r6, r7, [sp, #48] */
/* @0x231b94 str lr, [sp, #0x1c] */
/* @0x231b98 ldr lr, [sp, #0x2c] */
/* @0x231b9c strd r2, r3, [sp, #8] */
/* @0x231ba0 mov r2, #0 */
/* @0x231ba4 strd r4, r5, [sp] */
/* @0x231ba8 mov r3, #0 */
/* @0x231bac strd r6, r7, [sp, #16] */
/* @0x231bb0 str lr, [sp, #0x18] */
/* @0x231bb4 ldr r1, [r1, #0x4] */
/* @0x231bb8 str r12, [sp, #0x24] */
/* @0x231bbc str r1, [sp, #0x20] */
/* @0x231bc0 bl 0x230674 <vorbis_packet_blocksize+0x9f8> */
/* @0x231bc4 cmp r0, #0 */
/* @0x231bc8 blt 0x231c38 <ov_raw_seek+0x620> */
/* @0x231bcc ldr lr, [r10, #0x38] */
/* @0x231bd0 mov r0, r10 */
/* @0x231bd4 ldr r12, [r10, #0x40] */
/* @0x231bd8 mov r6, #0 */
/* @0x231bdc ldr r1, [r10, #0x3c] */
/* @0x231be0 mov r7, #0 */
/* @0x231be4 ldr r10, [r10, #0x44] */
/* @0x231be8 mov r2, r4 */
/* @0x231bec strd r6, r7, [lr] */
/* @0x231bf0 mov r3, r5 */
/* @0x231bf4 str r11, [r12] */
/* @0x231bf8 strd r4, r5, [r1] */
/* @0x231bfc ldrd r4, r5, [r10, #8] */
/* @0x231c00 strd r8, r9, [r10] */
/* @0x231c04 subs r4, r4, r8 */
/* @0x231c08 sbc r5, r5, r9 */
/* @0x231c0c strd r4, r5, [r10, #8] */
/* @0x231c10 bl 0x231618 <ov_raw_seek> */
/* @0x231c14 add sp, sp, #60 */
/* @0x231c18 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x231c1c mvn r2, #0 */
/* @0x231c20 mvn r3, #0 */
/* @0x231c24 mvn r0, #130 */
/* @0x231c28 strd r2, r3, [r10, #16] */
/* @0x231c2c strd r2, r3, [r10, #8] */
/* @0x231c30 add sp, sp, #60 */
/* @0x231c34 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x231c38 mvn r0, #127 */
/* @0x231c3c b 0x231c14 <ov_raw_seek+0x5fc> */
/* @0x231c40 mvn r0, #130 */
/* @0x231c44 b 0x231c14 <ov_raw_seek+0x5fc> */

/* ── FUNC 0x231c48 · ov_open_callbacks · size=164 · insn=41 */
/* @0x231c48 push {r4, r5, r6, lr} */
/* @0x231c4c sub sp, sp, #16 */
/* @0x231c50 add r6, sp, #28 */
/* @0x231c54 mov r5, r0 */
/* @0x231c58 mov lr, r2 */
/* @0x231c5c mov r12, r3 */
/* @0x231c60 mov r4, r1 */
/* @0x231c64 ldmib r6, {r0, r1, r2, r3} */
/* @0x231c68 stm sp, {r0, r1, r2, r3} */
/* @0x231c6c mov r0, r5 */
/* @0x231c70 mov r2, lr */
/* @0x231c74 mov r3, r12 */
/* @0x231c78 mov r1, r4 */
/* @0x231c7c bl 0x230fbc <ov_clear+0xf8> */
/* @0x231c80 subs r5, r0, #0 */
/* @0x231c84 movne r0, r5 */
/* @0x231c88 beq 0x231c94 <ov_open_callbacks+0x4c> */
/* @0x231c8c add sp, sp, #16 */
/* @0x231c90 pop {r4, r5, r6, pc} */
/* @0x231c94 ldr r3, [r4, #0x58] */
/* @0x231c98 cmp r3, #1 */
/* @0x231c9c bne 0x231ce4 <ov_open_callbacks+0x9c> */
/* @0x231ca0 ldr r0, [r4, #0x4] */
/* @0x231ca4 mov r3, #2 */
/* @0x231ca8 str r3, [r4, #0x58] */
/* @0x231cac cmp r0, #0 */
/* @0x231cb0 moveq r3, #3 */
/* @0x231cb4 streq r3, [r4, #0x58] */
/* @0x231cb8 beq 0x231c8c <ov_open_callbacks+0x44> */
/* @0x231cbc mov r0, r4 */
/* @0x231cc0 bl 0x231ac4 <ov_raw_seek+0x4ac> */
/* @0x231cc4 subs r6, r0, #0 */
/* @0x231cc8 beq 0x231cd8 <ov_open_callbacks+0x90> */
/* @0x231ccc str r5, [r4] */
/* @0x231cd0 mov r0, r4 */
/* @0x231cd4 bl 0x230ec4 <ov_clear> */
/* @0x231cd8 mov r0, r6 */
/* @0x231cdc add sp, sp, #16 */
/* @0x231ce0 pop {r4, r5, r6, pc} */
/* @0x231ce4 mvn r0, #130 */
/* @0x231ce8 b 0x231c8c <ov_open_callbacks+0x44> */

/* ── FUNC 0x231cec · ov_open · size=80 · insn=20 */
/* @0x231cec ldr r12, [pc, #0x44] */
/* @0x231cf0 push {r4, r5, r6, lr} */
/* @0x231cf4 add r12, pc, r12 */
/* @0x231cf8 mov lr, r3 */
/* @0x231cfc mov r6, r0 */
/* @0x231d00 mov r5, r1 */
/* @0x231d04 mov r4, r2 */
/* @0x231d08 ldm r12, {r0, r1, r2, r3} */
/* @0x231d0c sub sp, sp, #32 */
/* @0x231d10 add r12, sp, #16 */
/* @0x231d14 stm r12, {r0, r1, r2, r3} */
/* @0x231d18 stm sp, {r0, r1, r2, r3} */
/* @0x231d1c mov r0, r6 */
/* @0x231d20 mov r1, r5 */
/* @0x231d24 mov r2, r4 */
/* @0x231d28 mov r3, lr */
/* @0x231d2c bl 0x231c48 <ov_open_callbacks> */
/* @0x231d30 add sp, sp, #32 */
/* @0x231d34 pop {r4, r5, r6, pc} */
/* @0x231d38 mulseq r12, r8, r6 */

/* ── FUNC 0x231d3c · ov_fopen · size=88 · insn=22 */
/* @0x231d3c push {r3, r4, r5, lr} */
/* @0x231d40 mov r4, r1 */
/* @0x231d44 ldr r1, [pc, #0x44] */
/* @0x231d48 add r1, pc, r1 */
/* @0x231d4c bl 0xb6844 <fopen@plt> */
/* @0x231d50 subs r5, r0, #0 */
/* @0x231d54 beq 0x231d88 <ov_fopen+0x4c> */
/* @0x231d58 mov r2, #0 */
/* @0x231d5c mov r1, r4 */
/* @0x231d60 mov r3, r2 */
/* @0x231d64 bl 0x231cec <ov_open> */
/* @0x231d68 subs r4, r0, #0 */
/* @0x231d6c bne 0x231d78 <ov_fopen+0x3c> */
/* @0x231d70 mov r0, r4 */
/* @0x231d74 pop {r3, r4, r5, pc} */
/* @0x231d78 mov r0, r5 */
/* @0x231d7c bl 0xb6850 <fclose@plt> */
/* @0x231d80 mov r0, r4 */
/* @0x231d84 pop {r3, r4, r5, pc} */
/* @0x231d88 mvn r0, #0 */
/* @0x231d8c pop {r3, r4, r5, pc} */
/* @0x231d90 ldrheq r5, [r0], -r0 */

/* ── FUNC 0x231d94 · ov_test_open · size=104 · insn=26 */
/* @0x231d94 push {r3, r4, r5, lr} */
/* @0x231d98 mov r4, r0 */
/* @0x231d9c ldr r3, [r0, #0x58] */
/* @0x231da0 cmp r3, #1 */
/* @0x231da4 mvnne r3, #130 */
/* @0x231da8 bne 0x231dc8 <ov_test_open+0x34> */
/* @0x231dac ldr r3, [r0, #0x4] */
/* @0x231db0 mov r2, #2 */
/* @0x231db4 str r2, [r0, #0x58] */
/* @0x231db8 cmp r3, #0 */
/* @0x231dbc moveq r2, #3 */
/* @0x231dc0 streq r2, [r0, #0x58] */
/* @0x231dc4 bne 0x231dd0 <ov_test_open+0x3c> */
/* @0x231dc8 mov r0, r3 */
/* @0x231dcc pop {r3, r4, r5, pc} */
/* @0x231dd0 bl 0x231ac4 <ov_raw_seek+0x4ac> */
/* @0x231dd4 subs r5, r0, #0 */
/* @0x231dd8 bne 0x231de8 <ov_test_open+0x54> */
/* @0x231ddc mov r3, r5 */
/* @0x231de0 mov r0, r3 */
/* @0x231de4 pop {r3, r4, r5, pc} */
/* @0x231de8 mov r3, #0 */
/* @0x231dec mov r0, r4 */
/* @0x231df0 str r3, [r4] */
/* @0x231df4 bl 0x230ec4 <ov_clear> */
/* @0x231df8 b 0x231ddc <ov_test_open+0x48> */

/* ── FUNC 0x231dfc · rescale64 · size=216 · insn=54 */
/* @0x231dfc push {r4, r5, r6, r7, r8, r9, r10} */
/* @0x231e00 cmp r0, r2 */
/* @0x231e04 sbcs r10, r1, r3 */
/* @0x231e08 ldrd r8, r9, [sp, #28] */
/* @0x231e0c movge r0, r8 */
/* @0x231e10 movge r1, r9 */
/* @0x231e14 bge 0x231ebc <rescale64+0xc0> */
/* @0x231e18 cmp r0, #1 */
/* @0x231e1c sbcs r12, r1, #0 */
/* @0x231e20 blt 0x231ec4 <rescale64+0xc8> */
/* @0x231e24 mov r12, #64 */
/* @0x231e28 mov r4, #0 */
/* @0x231e2c mov r5, #0 */
/* @0x231e30 mov r6, #1 */
/* @0x231e34 mov r7, #0 */
/* @0x231e38 adds r0, r0, r0 */
/* @0x231e3c adc r1, r1, r1 */
/* @0x231e40 adds r4, r4, r4 */
/* @0x231e44 adc r5, r5, r5 */
/* @0x231e48 subs r12, r12, #1 */
/* @0x231e4c beq 0x231e70 <rescale64+0x74> */
/* @0x231e50 cmp r0, r2 */
/* @0x231e54 sbcs r10, r1, r3 */
/* @0x231e58 blt 0x231e38 <rescale64+0x3c> */
/* @0x231e5c orr r4, r4, r6 */
/* @0x231e60 orr r5, r5, r7 */
/* @0x231e64 subs r0, r0, r2 */
/* @0x231e68 sbc r1, r1, r3 */
/* @0x231e6c b 0x231e38 <rescale64+0x3c> */
/* @0x231e70 mov r2, #0 */
/* @0x231e74 mov r3, #0 */
/* @0x231e78 mov r6, #1 */
/* @0x231e7c mov r7, #0 */
/* @0x231e80 mov r12, #64 */
/* @0x231e84 and r0, r4, r6 */
/* @0x231e88 and r1, r5, r7 */
/* @0x231e8c orrs r10, r0, r1 */
/* @0x231e90 beq 0x231e9c <rescale64+0xa0> */
/* @0x231e94 adds r2, r2, r8 */
/* @0x231e98 adc r3, r3, r9 */
/* @0x231e9c asrs r5, r5, #1 */
/* @0x231ea0 rrx r4, r4 */
/* @0x231ea4 asrs r3, r3, #1 */
/* @0x231ea8 rrx r2, r2 */
/* @0x231eac subs r12, r12, #1 */
/* @0x231eb0 bne 0x231e84 <rescale64+0x88> */
/* @0x231eb4 mov r0, r2 */
/* @0x231eb8 mov r1, r3 */
/* @0x231ebc pop {r4, r5, r6, r7, r8, r9, r10} */
/* @0x231ec0 bx lr */
/* @0x231ec4 mov r0, #0 */
/* @0x231ec8 mov r1, r0 */
/* @0x231ecc pop {r4, r5, r6, r7, r8, r9, r10} */
/* @0x231ed0 bx lr */

/* ── FUNC 0x231ed4 · ov_pcm_seek_page · size=2080 · insn=520 */
/* @0x231ed4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x231ed8 sub sp, sp, #156 */
/* @0x231edc mvn r1, #0 */
/* @0x231ee0 mov r8, r0 */
/* @0x231ee4 strd r2, r3, [sp, #40] */
/* @0x231ee8 bl 0x23138c <ov_pcm_total> */
/* @0x231eec ldr r3, [r8, #0x58] */
/* @0x231ef0 cmp r3, #1 */
/* @0x231ef4 strd r0, r1, [sp, #32] */
/* @0x231ef8 ble 0x232314 <ov_pcm_seek_page+0x440> */
/* @0x231efc ldr r3, [r8, #0x4] */
/* @0x231f00 cmp r3, #0 */
/* @0x231f04 beq 0x232538 <ov_pcm_seek_page+0x664> */
/* @0x231f08 ldrd r4, r5, [sp, #40] */
/* @0x231f0c ldr r6, [sp, #0x2c] */
/* @0x231f10 cmp r0, r4 */
/* @0x231f14 sbcs r5, r1, r5 */
/* @0x231f18 movge r3, #0 */
/* @0x231f1c movlt r3, #1 */
/* @0x231f20 orrs r3, r3, r6, lsr #31 */
/* @0x231f24 bne 0x232314 <ov_pcm_seek_page+0x440> */
/* @0x231f28 ldr r3, [r8, #0x34] */
/* @0x231f2c subs r3, r3, #1 */
/* @0x231f30 str r3, [sp, #0x34] */
/* @0x231f34 ldr r3, [r8, #0x44] */
/* @0x231f38 bmi 0x232524 <ov_pcm_seek_page+0x650> */
/* @0x231f3c ldr r10, [sp, #0x34] */
/* @0x231f40 ldrd r4, r5, [sp, #32] */
/* @0x231f44 ldrd r6, r7, [sp, #40] */
/* @0x231f48 lsl r2, r10, #4 */
/* @0x231f4c add r1, r3, r2 */
/* @0x231f50 ldrd r0, r1, [r1, #8] */
/* @0x231f54 subs r4, r4, r0 */
/* @0x231f58 sbc r5, r5, r1 */
/* @0x231f5c strd r4, r5, [sp, #32] */
/* @0x231f60 cmp r6, r4 */
/* @0x231f64 sbcs r7, r7, r5 */
/* @0x231f68 bge 0x231fc8 <ov_pcm_seek_page+0xf4> */
/* @0x231f6c add r2, r2, #16 */
/* @0x231f70 movw r12, #0xffe0 */
/* @0x231f74 movt r12, #0xffff */
/* @0x231f78 add r2, r3, r2 */
/* @0x231f7c rsb r12, r3, r12 */
/* @0x231f80 mov r9, r10 */
/* @0x231f84 ldrd r6, r7, [sp, #40] */
/* @0x231f88 b 0x231fa8 <ov_pcm_seek_page+0xd4> */
/* @0x231f8c ldrd r0, r1, [r2, #-24] */
/* @0x231f90 sub r2, r2, #16 */
/* @0x231f94 subs r4, r4, r0 */
/* @0x231f98 sbc r5, r5, r1 */
/* @0x231f9c cmp r6, r4 */
/* @0x231fa0 sbcs r10, r7, r5 */
/* @0x231fa4 bge 0x232304 <ov_pcm_seek_page+0x430> */
/* @0x231fa8 sub r9, r9, #1 */
/* @0x231fac add lr, r12, r2 */
/* @0x231fb0 cmn r9, #1 */
/* @0x231fb4 bne 0x231f8c <ov_pcm_seek_page+0xb8> */
/* @0x231fb8 ldrd r0, r1, [r3, #-8] */
/* @0x231fbc mvn r2, #15 */
/* @0x231fc0 str r9, [sp, #0x34] */
/* @0x231fc4 strd r4, r5, [sp, #32] */
/* @0x231fc8 ldr r12, [sp, #0x34] */
/* @0x231fcc ldrd r4, r5, [r3, r2] */
/* @0x231fd0 add lr, r12, #1 */
/* @0x231fd4 ldrd r6, r7, [sp, #32] */
/* @0x231fd8 ldr r12, [r8, #0x38] */
/* @0x231fdc ldrd r2, r3, [sp, #40] */
/* @0x231fe0 lsl lr, lr, #3 */
/* @0x231fe4 strd r4, r5, [sp, #56] */
/* @0x231fe8 subs r2, r2, r6 */
/* @0x231fec sbc r3, r3, r7 */
/* @0x231ff0 adds r4, r4, r0 */
/* @0x231ff4 adc r5, r5, r1 */
/* @0x231ff8 ldrd r6, r7, [r12, lr]! */
/* @0x231ffc strd r4, r5, [sp, #80] */
/* @0x232000 ldrd r4, r5, [sp, #56] */
/* @0x232004 adds r4, r4, r2 */
/* @0x232008 adc r5, r5, r3 */
/* @0x23200c strd r4, r5, [sp, #64] */
/* @0x232010 ldrd r4, r5, [r12, #-8] */
/* @0x232014 strd r4, r5, [sp, #16] */
/* @0x232018 cmp r4, r6 */
/* @0x23201c sbcs r5, r5, r7 */
/* @0x232020 bge 0x23254c <ov_pcm_seek_page+0x678> */
/* @0x232024 ldr r10, [sp, #0x34] */
/* @0x232028 add r9, sp, #88 */
/* @0x23202c ldr r12, [sp, #0x10] */
/* @0x232030 ldr r4, [sp, #0x14] */
/* @0x232034 lsl r10, r10, #2 */
/* @0x232038 str r10, [sp, #0x18] */
/* @0x23203c str r12, [sp, #0x48] */
/* @0x232040 str r4, [sp, #0x4c] */
/* @0x232044 ldrd r2, r3, [sp, #16] */
/* @0x232048 movw r0, #0x7fff */
/* @0x23204c mov r1, #0 */
/* @0x232050 subs r2, r6, r2 */
/* @0x232054 sbc r3, r7, r3 */
/* @0x232058 cmp r0, r2 */
/* @0x23205c sbcs r1, r1, r3 */
/* @0x232060 blt 0x2322a8 <ov_pcm_seek_page+0x3d4> */
/* @0x232064 ldrd r4, r5, [sp, #16] */
/* @0x232068 ldrd r2, r3, [r8, #8] */
/* @0x23206c cmp r3, r5 */
/* @0x232070 cmpeq r2, r4 */
/* @0x232074 moveq r2, r4 */
/* @0x232078 moveq r3, r5 */
/* @0x23207c beq 0x2320d0 <ov_pcm_seek_page+0x1fc> */
/* @0x232080 mov r0, r8 */
/* @0x232084 mov r2, r4 */
/* @0x232088 mov r3, r5 */
/* @0x23208c bl 0x22ffe0 <vorbis_packet_blocksize+0x364> */
/* @0x232090 asr r1, r0, #31 */
/* @0x232094 orrs r12, r0, r1 */
/* @0x232098 beq 0x2320cc <ov_pcm_seek_page+0x1f8> */
/* @0x23209c b 0x2321c0 <ov_pcm_seek_page+0x2ec> */
/* @0x2320a0 mov r0, r9 */
/* @0x2320a4 bl 0x23409c <ogg_page_serialno> */
/* @0x2320a8 ldr r3, [r8, #0x40] */
/* @0x2320ac ldr r12, [sp, #0x18] */
/* @0x2320b0 ldr r3, [r3, r12] */
/* @0x2320b4 cmp r0, r3 */
/* @0x2320b8 beq 0x2321d0 <ov_pcm_seek_page+0x2fc> */
/* @0x2320bc ldrd r0, r1, [sp, #16] */
/* @0x2320c0 cmp r0, r6 */
/* @0x2320c4 sbcs r1, r1, r7 */
/* @0x2320c8 bge 0x232124 <ov_pcm_seek_page+0x250> */
/* @0x2320cc ldrd r2, r3, [r8, #8] */
/* @0x2320d0 subs r2, r6, r2 */
/* @0x2320d4 sbc r3, r7, r3 */
/* @0x2320d8 mov r0, r8 */
/* @0x2320dc mov r1, r9 */
/* @0x2320e0 bl 0x22fd0c <vorbis_packet_blocksize+0x90> */
/* @0x2320e4 mov r10, r0 */
/* @0x2320e8 mov r11, r1 */
/* @0x2320ec mvn r0, #127 */
/* @0x2320f0 mvn r1, #0 */
/* @0x2320f4 cmp r11, r1 */
/* @0x2320f8 cmpeq r10, r0 */
/* @0x2320fc beq 0x2322a0 <ov_pcm_seek_page+0x3cc> */
/* @0x232100 cmp r10, #0 */
/* @0x232104 sbcs r1, r11, #0 */
/* @0x232108 bge 0x2320a0 <ov_pcm_seek_page+0x1cc> */
/* @0x23210c ldrd r2, r3, [sp, #16] */
/* @0x232110 adds r2, r2, #1 */
/* @0x232114 adc r3, r3, #0 */
/* @0x232118 cmp r2, r4 */
/* @0x23211c sbcs r12, r3, r5 */
/* @0x232120 blt 0x232180 <ov_pcm_seek_page+0x2ac> */
/* @0x232124 ldr r2, [sp, #0x48] */
/* @0x232128 mov r0, r8 */
/* @0x23212c ldr r3, [sp, #0x4c] */
/* @0x232130 bl 0x22ffe0 <vorbis_packet_blocksize+0x364> */
/* @0x232134 mvn r2, #0 */
/* @0x232138 mvn r3, #0 */
/* @0x23213c strd r2, r3, [r8, #80] */
/* @0x232140 subs r10, r0, #0 */
/* @0x232144 beq 0x23231c <ov_pcm_seek_page+0x448> */
/* @0x232148 add r6, r8, #480 */
/* @0x23214c str r6, [sp, #0x10] */
/* @0x232150 mvn r3, #0 */
/* @0x232154 mvn r2, #0 */
/* @0x232158 ldr r0, [sp, #0x10] */
/* @0x23215c strd r2, r3, [r8, #80] */
/* @0x232160 bl 0x2272ac <vorbis_dsp_clear> */
/* @0x232164 add r0, r8, #560 */
/* @0x232168 bl 0x227208 <vorbis_block_clear> */
/* @0x23216c mov r3, #2 */
/* @0x232170 str r3, [r8, #0x58] */
/* @0x232174 mov r0, r10 */
/* @0x232178 add sp, sp, #156 */
/* @0x23217c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x232180 orrs r0, r4, r5 */
/* @0x232184 beq 0x2321c4 <ov_pcm_seek_page+0x2f0> */
/* @0x232188 subs r4, r4, #32768 */
/* @0x23218c ldrd r0, r1, [sp, #16] */
/* @0x232190 sbc r5, r5, #0 */
/* @0x232194 cmp r0, r4 */
/* @0x232198 sbcs r1, r1, r5 */
/* @0x23219c mov r0, r8 */
/* @0x2321a0 movge r4, r2 */
/* @0x2321a4 movge r5, r3 */
/* @0x2321a8 mov r2, r4 */
/* @0x2321ac mov r3, r5 */
/* @0x2321b0 bl 0x22ffe0 <vorbis_packet_blocksize+0x364> */
/* @0x2321b4 asr r1, r0, #31 */
/* @0x2321b8 orrs r2, r0, r1 */
/* @0x2321bc beq 0x2320bc <ov_pcm_seek_page+0x1e8> */
/* @0x2321c0 mov r10, r0 */
/* @0x2321c4 add r4, r8, #480 */
/* @0x2321c8 str r4, [sp, #0x10] */
/* @0x2321cc b 0x232150 <ov_pcm_seek_page+0x27c> */
/* @0x2321d0 mov r0, r9 */
/* @0x2321d4 bl 0x233fb0 <ogg_page_granulepos> */
/* @0x2321d8 mvn r2, #0 */
/* @0x2321dc mvn r3, #0 */
/* @0x2321e0 cmp r1, r3 */
/* @0x2321e4 cmpeq r0, r2 */
/* @0x2321e8 beq 0x2320bc <ov_pcm_seek_page+0x1e8> */
/* @0x2321ec ldrd r2, r3, [sp, #64] */
/* @0x2321f0 cmp r0, r2 */
/* @0x2321f4 sbcs r3, r1, r3 */
/* @0x2321f8 bge 0x232234 <ov_pcm_seek_page+0x360> */
/* @0x2321fc ldrd r2, r3, [sp, #64] */
/* @0x232200 movw r4, #0xac44 */
/* @0x232204 mov r5, #0 */
/* @0x232208 subs r2, r2, r0 */
/* @0x23220c sbc r3, r3, r1 */
/* @0x232210 cmp r4, r2 */
/* @0x232214 sbcs r5, r5, r3 */
/* @0x232218 ldrd r4, r5, [r8, #8] */
/* @0x23221c blt 0x23257c <ov_pcm_seek_page+0x6a8> */
/* @0x232220 strd r0, r1, [sp, #56] */
/* @0x232224 str r10, [sp, #0x48] */
/* @0x232228 str r11, [sp, #0x4c] */
/* @0x23222c strd r4, r5, [sp, #16] */
/* @0x232230 b 0x2320bc <ov_pcm_seek_page+0x1e8> */
/* @0x232234 ldrd r2, r3, [sp, #16] */
/* @0x232238 adds r2, r2, #1 */
/* @0x23223c adc r3, r3, #0 */
/* @0x232240 strd r2, r3, [sp, #8] */
/* @0x232244 cmp r2, r4 */
/* @0x232248 sbcs r3, r3, r5 */
/* @0x23224c bge 0x232124 <ov_pcm_seek_page+0x250> */
/* @0x232250 ldrd r2, r3, [r8, #8] */
/* @0x232254 cmp r3, r7 */
/* @0x232258 cmpeq r2, r6 */
/* @0x23225c bne 0x232560 <ov_pcm_seek_page+0x68c> */
/* @0x232260 subs r4, r4, #32768 */
/* @0x232264 ldrd r6, r7, [sp, #16] */
/* @0x232268 sbc r5, r5, #0 */
/* @0x23226c mov r0, r8 */
/* @0x232270 cmp r6, r4 */
/* @0x232274 sbcs r7, r7, r5 */
/* @0x232278 ldrdge r4, r5, [sp, #8] */
/* @0x23227c mov r2, r4 */
/* @0x232280 mov r3, r5 */
/* @0x232284 bl 0x22ffe0 <vorbis_packet_blocksize+0x364> */
/* @0x232288 asr r1, r0, #31 */
/* @0x23228c orrs r12, r0, r1 */
/* @0x232290 bne 0x2321c0 <ov_pcm_seek_page+0x2ec> */
/* @0x232294 mov r6, r10 */
/* @0x232298 mov r7, r11 */
/* @0x23229c b 0x2320bc <ov_pcm_seek_page+0x1e8> */
/* @0x2322a0 mvn r10, #127 */
/* @0x2322a4 b 0x232148 <ov_pcm_seek_page+0x274> */
/* @0x2322a8 ldrd r4, r5, [sp, #56] */
/* @0x2322ac strd r2, r3, [sp] */
/* @0x2322b0 ldrd r0, r1, [sp, #64] */
/* @0x2322b4 ldrd r2, r3, [sp, #80] */
/* @0x2322b8 subs r0, r0, r4 */
/* @0x2322bc sbc r1, r1, r5 */
/* @0x2322c0 subs r2, r2, r4 */
/* @0x2322c4 sbc r3, r3, r5 */
/* @0x2322c8 movw r4, #0x7fff */
/* @0x2322cc bl 0x231dfc <rescale64> */
/* @0x2322d0 ldrd r2, r3, [sp, #16] */
/* @0x2322d4 mov r5, #0 */
/* @0x2322d8 adds r2, r2, r4 */
/* @0x2322dc adc r3, r3, r5 */
/* @0x2322e0 ldrd r4, r5, [sp, #16] */
/* @0x2322e4 adds r0, r0, r4 */
/* @0x2322e8 adc r1, r1, r5 */
/* @0x2322ec subs r4, r0, #32768 */
/* @0x2322f0 sbc r5, r1, #0 */
/* @0x2322f4 cmp r2, r4 */
/* @0x2322f8 sbcs r10, r3, r5 */
/* @0x2322fc bge 0x232064 <ov_pcm_seek_page+0x190> */
/* @0x232300 b 0x232068 <ov_pcm_seek_page+0x194> */
/* @0x232304 str r9, [sp, #0x34] */
/* @0x232308 mov r2, lr */
/* @0x23230c strd r4, r5, [sp, #32] */
/* @0x232310 b 0x231fc8 <ov_pcm_seek_page+0xf4> */
/* @0x232314 mvn r10, #130 */
/* @0x232318 b 0x232174 <ov_pcm_seek_page+0x2a0> */
/* @0x23231c add r5, sp, #104 */
/* @0x232320 mov r0, r8 */
/* @0x232324 mov r1, r5 */
/* @0x232328 bl 0x22fd0c <vorbis_packet_blocksize+0x90> */
/* @0x23232c cmp r0, #0 */
/* @0x232330 sbcs r7, r1, #0 */
/* @0x232334 addlt r12, r8, #480 */
/* @0x232338 strlt r12, [sp, #0x10] */
/* @0x23233c movlt r10, r0 */
/* @0x232340 blt 0x232150 <ov_pcm_seek_page+0x27c> */
/* @0x232344 ldr r3, [r8, #0x60] */
/* @0x232348 ldr r4, [sp, #0x34] */
/* @0x23234c cmp r3, r4 */
/* @0x232350 beq 0x2325d8 <ov_pcm_seek_page+0x704> */
/* @0x232354 add r6, r8, #480 */
/* @0x232358 str r6, [sp, #0x10] */
/* @0x23235c mov r0, r6 */
/* @0x232360 bl 0x2272ac <vorbis_dsp_clear> */
/* @0x232364 add r0, r8, #560 */
/* @0x232368 bl 0x227208 <vorbis_block_clear> */
/* @0x23236c ldr r2, [r8, #0x40] */
/* @0x232370 mov r3, #2 */
/* @0x232374 str r4, [r8, #0x60] */
/* @0x232378 str r3, [r8, #0x58] */
/* @0x23237c mov r3, #3 */
/* @0x232380 ldr r1, [r2, r4, lsl #2] */
/* @0x232384 str r3, [r8, #0x58] */
/* @0x232388 str r1, [r8, #0x5c] */
/* @0x23238c add r4, r8, #120 */
/* @0x232390 add r6, sp, #120 */
/* @0x232394 mov r0, r4 */
/* @0x232398 bl 0x2352f4 <ogg_stream_reset_serialno> */
/* @0x23239c mov r0, r4 */
/* @0x2323a0 mov r1, r5 */
/* @0x2323a4 bl 0x234eac <ogg_stream_pagein> */
/* @0x2323a8 b 0x2323d4 <ov_pcm_seek_page+0x500> */
/* @0x2323ac cmp r2, #0 */
/* @0x2323b0 sbcs r7, r3, #0 */
/* @0x2323b4 blt 0x232650 <ov_pcm_seek_page+0x77c> */
/* @0x2323b8 ldrd r10, r11, [sp, #136] */
/* @0x2323bc mvn r2, #0 */
/* @0x2323c0 mvn r3, #0 */
/* @0x2323c4 cmp r11, r3 */
/* @0x2323c8 cmpeq r10, r2 */
/* @0x2323cc bne 0x2325f0 <ov_pcm_seek_page+0x71c> */
/* @0x2323d0 bl 0x235328 <ogg_stream_packetout> */
/* @0x2323d4 mov r1, r6 */
/* @0x2323d8 mov r0, r4 */
/* @0x2323dc bl 0x23535c <ogg_stream_packetpeek> */
/* @0x2323e0 mov r1, #0 */
/* @0x2323e4 asr r3, r0, #31 */
/* @0x2323e8 mov r2, r0 */
/* @0x2323ec orrs r10, r2, r3 */
/* @0x2323f0 mov r0, r4 */
/* @0x2323f4 bne 0x2323ac <ov_pcm_seek_page+0x4d8> */
/* @0x2323f8 ldr r2, [sp, #0x48] */
/* @0x2323fc mov r0, r8 */
/* @0x232400 ldr r3, [sp, #0x4c] */
/* @0x232404 bl 0x22ffe0 <vorbis_packet_blocksize+0x364> */
/* @0x232408 subs r10, r0, #0 */
/* @0x23240c blt 0x232150 <ov_pcm_seek_page+0x27c> */
/* @0x232410 ldrd r10, r11, [r8, #8] */
/* @0x232414 mov r9, #0 */
/* @0x232418 mov r4, r8 */
/* @0x23241c mov r8, r5 */
/* @0x232420 strd r10, r11, [sp, #24] */
/* @0x232424 ldrd r6, r7, [sp, #24] */
/* @0x232428 mov r0, r4 */
/* @0x23242c subs r6, r6, #32768 */
/* @0x232430 sbc r7, r7, #0 */
/* @0x232434 strd r6, r7, [sp, #24] */
/* @0x232438 cmp r6, #0 */
/* @0x23243c sbcs r7, r7, #0 */
/* @0x232440 movlt r6, #0 */
/* @0x232444 movlt r7, #0 */
/* @0x232448 strdlt r6, r7, [sp, #24] */
/* @0x23244c ldrd r2, r3, [sp, #24] */
/* @0x232450 bl 0x22ffe0 <vorbis_packet_blocksize+0x364> */
/* @0x232454 asr r7, r0, #31 */
/* @0x232458 mov r6, r0 */
/* @0x23245c orrs r12, r6, r7 */
/* @0x232460 bne 0x232658 <ov_pcm_seek_page+0x784> */
/* @0x232464 mvn r6, #0 */
/* @0x232468 mvn r7, #0 */
/* @0x23246c b 0x2324b4 <ov_pcm_seek_page+0x5e0> */
/* @0x232470 subs r2, r10, r2 */
/* @0x232474 sbc r3, r11, r3 */
/* @0x232478 str r9, [r8] */
/* @0x23247c str r9, [sp, #0x6c] */
/* @0x232480 str r9, [sp, #0x70] */
/* @0x232484 str r9, [sp, #0x74] */
/* @0x232488 bl 0x22fd0c <vorbis_packet_blocksize+0x90> */
/* @0x23248c mvn r2, #127 */
/* @0x232490 mvn r3, #0 */
/* @0x232494 cmp r1, r3 */
/* @0x232498 cmpeq r0, r2 */
/* @0x23249c beq 0x232540 <ov_pcm_seek_page+0x66c> */
/* @0x2324a0 cmp r0, #0 */
/* @0x2324a4 sbcs r3, r1, #0 */
/* @0x2324a8 blt 0x2324cc <ov_pcm_seek_page+0x5f8> */
/* @0x2324ac mov r6, r0 */
/* @0x2324b0 mov r7, r1 */
/* @0x2324b4 ldrd r2, r3, [r4, #8] */
/* @0x2324b8 mov r0, r4 */
/* @0x2324bc mov r1, r8 */
/* @0x2324c0 cmp r2, r10 */
/* @0x2324c4 sbcs r5, r3, r11 */
/* @0x2324c8 blt 0x232470 <ov_pcm_seek_page+0x59c> */
/* @0x2324cc mvn r0, #0 */
/* @0x2324d0 mvn r1, #0 */
/* @0x2324d4 cmp r7, r1 */
/* @0x2324d8 cmpeq r6, r0 */
/* @0x2324dc beq 0x232424 <ov_pcm_seek_page+0x550> */
/* @0x2324e0 ldr r3, [sp, #0x6c] */
/* @0x2324e4 mov r5, r8 */
/* @0x2324e8 mov r8, r4 */
/* @0x2324ec cmp r3, #0 */
/* @0x2324f0 beq 0x2326ac <ov_pcm_seek_page+0x7d8> */
/* @0x2324f4 cmp r6, #0 */
/* @0x2324f8 sbcs r0, r7, #0 */
/* @0x2324fc blt 0x2326a4 <ov_pcm_seek_page+0x7d0> */
/* @0x232500 mov r0, r5 */
/* @0x232504 bl 0x23409c <ogg_page_serialno> */
/* @0x232508 ldr r3, [r8, #0x5c] */
/* @0x23250c cmp r0, r3 */
/* @0x232510 beq 0x23259c <ov_pcm_seek_page+0x6c8> */
/* @0x232514 strd r6, r7, [r8, #8] */
/* @0x232518 mov r10, r6 */
/* @0x23251c mov r11, r7 */
/* @0x232520 b 0x232418 <ov_pcm_seek_page+0x544> */
/* @0x232524 ldr r7, [sp, #0x34] */
/* @0x232528 lsl r2, r7, #4 */
/* @0x23252c add r1, r3, r2 */
/* @0x232530 ldrd r0, r1, [r1, #8] */
/* @0x232534 b 0x231fc8 <ov_pcm_seek_page+0xf4> */
/* @0x232538 mvn r10, #137 */
/* @0x23253c b 0x232174 <ov_pcm_seek_page+0x2a0> */
/* @0x232540 mov r8, r4 */
/* @0x232544 mvn r10, #127 */
/* @0x232548 b 0x232150 <ov_pcm_seek_page+0x27c> */
/* @0x23254c ldr r4, [sp, #0x10] */
/* @0x232550 ldr r5, [sp, #0x14] */
/* @0x232554 str r4, [sp, #0x48] */
/* @0x232558 str r5, [sp, #0x4c] */
/* @0x23255c b 0x232124 <ov_pcm_seek_page+0x250> */
/* @0x232560 strd r0, r1, [sp, #80] */
/* @0x232564 mov r6, r4 */
/* @0x232568 mov r7, r5 */
/* @0x23256c ldr r10, [sp, #0x48] */
/* @0x232570 ldrd r0, r1, [sp, #56] */
/* @0x232574 ldrd r4, r5, [sp, #16] */
/* @0x232578 ldr r11, [sp, #0x4c] */
/* @0x23257c cmp r4, r6 */
/* @0x232580 sbcs r2, r5, r7 */
/* @0x232584 bge 0x232698 <ov_pcm_seek_page+0x7c4> */
/* @0x232588 strd r0, r1, [sp, #56] */
/* @0x23258c strd r4, r5, [sp, #16] */
/* @0x232590 str r10, [sp, #0x48] */
/* @0x232594 str r11, [sp, #0x4c] */
/* @0x232598 b 0x232044 <ov_pcm_seek_page+0x170> */
/* @0x23259c mov r0, r5 */
/* @0x2325a0 bl 0x233fb0 <ogg_page_granulepos> */
/* @0x2325a4 cmp r0, #0 */
/* @0x2325a8 sbcs r2, r1, #0 */
/* @0x2325ac bge 0x2325c0 <ov_pcm_seek_page+0x6ec> */
/* @0x2325b0 mov r0, r5 */
/* @0x2325b4 bl 0x233f80 <ogg_page_continued> */
/* @0x2325b8 cmp r0, #0 */
/* @0x2325bc bne 0x232514 <ov_pcm_seek_page+0x640> */
/* @0x2325c0 mov r0, r8 */
/* @0x2325c4 mov r2, r6 */
/* @0x2325c8 mov r3, r7 */
/* @0x2325cc bl 0x231618 <ov_raw_seek> */
/* @0x2325d0 mov r10, r0 */
/* @0x2325d4 b 0x232174 <ov_pcm_seek_page+0x2a0> */
/* @0x2325d8 add r7, r8, #480 */
/* @0x2325dc str r7, [sp, #0x10] */
/* @0x2325e0 mov r0, r7 */
/* @0x2325e4 bl 0x22723c <vorbis_synthesis_restart> */
/* @0x2325e8 ldr r1, [r8, #0x5c] */
/* @0x2325ec b 0x23238c <ov_pcm_seek_page+0x4b8> */
/* @0x2325f0 ldr r1, [r8, #0x60] */
/* @0x2325f4 mov r2, #0 */
/* @0x2325f8 ldr r0, [r8, #0x44] */
/* @0x2325fc mov r3, #0 */
/* @0x232600 ldrd r6, r7, [sp, #32] */
/* @0x232604 lsl r1, r1, #4 */
/* @0x232608 add r0, r0, r1 */
/* @0x23260c ldrd r0, r1, [r0] */
/* @0x232610 subs r0, r10, r0 */
/* @0x232614 sbc r1, r11, r1 */
/* @0x232618 strd r0, r1, [r8, #80] */
/* @0x23261c cmp r2, r0 */
/* @0x232620 sbcs r4, r3, r1 */
/* @0x232624 ldrd r4, r5, [sp, #40] */
/* @0x232628 movlt r3, r1 */
/* @0x23262c movlt r2, r0 */
/* @0x232630 adds r2, r2, r6 */
/* @0x232634 adc r3, r3, r7 */
/* @0x232638 strd r2, r3, [r8, #80] */
/* @0x23263c cmp r4, r2 */
/* @0x232640 sbcs r5, r5, r3 */
/* @0x232644 bge 0x232664 <ov_pcm_seek_page+0x790> */
/* @0x232648 mvn r10, #128 */
/* @0x23264c b 0x232150 <ov_pcm_seek_page+0x27c> */
/* @0x232650 mvn r10, #135 */
/* @0x232654 b 0x232150 <ov_pcm_seek_page+0x27c> */
/* @0x232658 mov r5, r8 */
/* @0x23265c mov r8, r4 */
/* @0x232660 b 0x2324f4 <ov_pcm_seek_page+0x620> */
/* @0x232664 mov r0, r8 */
/* @0x232668 mvn r1, #0 */
/* @0x23266c bl 0x23138c <ov_pcm_total> */
/* @0x232670 ldrd r4, r5, [sp, #40] */
/* @0x232674 cmp r0, r4 */
/* @0x232678 sbcs r5, r1, r5 */
/* @0x23267c blt 0x232648 <ov_pcm_seek_page+0x774> */
/* @0x232680 mov r2, #0 */
/* @0x232684 mov r3, #0 */
/* @0x232688 mov r10, #0 */
/* @0x23268c strd r2, r3, [r8, #104] */
/* @0x232690 strd r2, r3, [r8, #112] */
/* @0x232694 b 0x232174 <ov_pcm_seek_page+0x2a0> */
/* @0x232698 str r10, [sp, #0x48] */
/* @0x23269c str r11, [sp, #0x4c] */
/* @0x2326a0 b 0x232124 <ov_pcm_seek_page+0x250> */
/* @0x2326a4 mov r10, r6 */
/* @0x2326a8 b 0x232150 <ov_pcm_seek_page+0x27c> */
/* @0x2326ac mov r2, r6 */
/* @0x2326b0 mov r3, r7 */
/* @0x2326b4 mov r0, r4 */
/* @0x2326b8 bl 0x22ffe0 <vorbis_packet_blocksize+0x364> */
/* @0x2326bc asr r1, r0, #31 */
/* @0x2326c0 orrs r10, r0, r1 */
/* @0x2326c4 movne r6, r0 */
/* @0x2326c8 movne r7, r1 */
/* @0x2326cc bne 0x2324f4 <ov_pcm_seek_page+0x620> */
/* @0x2326d0 mov r0, r4 */
/* @0x2326d4 mov r1, r5 */
/* @0x2326d8 mov r2, #32768 */
/* @0x2326dc mov r3, #0 */
/* @0x2326e0 bl 0x22fd0c <vorbis_packet_blocksize+0x90> */
/* @0x2326e4 cmp r0, #0 */
/* @0x2326e8 sbcs r12, r1, #0 */
/* @0x2326ec bge 0x2324f4 <ov_pcm_seek_page+0x620> */
/* @0x2326f0 b 0x232648 <ov_pcm_seek_page+0x774> */

/* ── FUNC 0x2326f4 · ov_pcm_seek · size=848 · insn=212 */
/* @0x2326f4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2326f8 sub sp, sp, #68 */
/* @0x2326fc mov r6, r0 */
/* @0x232700 strd r2, r3, [sp, #8] */
/* @0x232704 bl 0x231ed4 <ov_pcm_seek_page> */
/* @0x232708 cmp r0, #0 */
/* @0x23270c blt 0x2328d0 <ov_pcm_seek+0x1dc> */
/* @0x232710 mov r0, r6 */
/* @0x232714 bl 0x230294 <vorbis_packet_blocksize+0x618> */
/* @0x232718 cmp r0, #0 */
/* @0x23271c bne 0x2328d0 <ov_pcm_seek+0x1dc> */
/* @0x232720 add r9, r6, #120 */
/* @0x232724 add r7, sp, #32 */
/* @0x232728 add r10, sp, #16 */
/* @0x23272c add r11, r6, #560 */
/* @0x232730 mov r4, r0 */
/* @0x232734 add r1, r6, #480 */
/* @0x232738 str r1, [sp, #0x4] */
/* @0x23273c mov r0, r9 */
/* @0x232740 mov r1, r7 */
/* @0x232744 bl 0x23535c <ogg_stream_packetpeek> */
/* @0x232748 cmp r0, #0 */
/* @0x23274c ble 0x2328d8 <ov_pcm_seek+0x1e4> */
/* @0x232750 ldr r0, [r6, #0x60] */
/* @0x232754 mov r1, r7 */
/* @0x232758 ldr r3, [r6, #0x48] */
/* @0x23275c add r0, r3, r0, lsl #5 */
/* @0x232760 bl 0x22fc7c <vorbis_packet_blocksize> */
/* @0x232764 subs r8, r0, #0 */
/* @0x232768 blt 0x2329f0 <ov_pcm_seek+0x2fc> */
/* @0x23276c cmp r4, #0 */
/* @0x232770 bne 0x23293c <ov_pcm_seek+0x248> */
/* @0x232774 ldrd r4, r5, [r6, #80] */
/* @0x232778 ldr r0, [r6, #0x48] */
/* @0x23277c mov r1, #1 */
/* @0x232780 bl 0x22acd4 <vorbis_info_blocksize> */
/* @0x232784 add r0, r0, r8 */
/* @0x232788 asr r3, r0, #2 */
/* @0x23278c adds r4, r4, r3 */
/* @0x232790 adc r5, r5, r3, asr #31 */
/* @0x232794 ldrd r2, r3, [sp, #8] */
/* @0x232798 cmp r4, r2 */
/* @0x23279c sbcs r3, r5, r3 */
/* @0x2327a0 bge 0x232840 <ov_pcm_seek+0x14c> */
/* @0x2327a4 mov r1, #0 */
/* @0x2327a8 mov r0, r9 */
/* @0x2327ac bl 0x235328 <ogg_stream_packetout> */
/* @0x2327b0 mov r1, r7 */
/* @0x2327b4 mov r0, r11 */
/* @0x2327b8 bl 0x22fc74 <vorbis_synthesis_trackonly> */
/* @0x2327bc mov r1, r11 */
/* @0x2327c0 ldr r0, [sp, #0x4] */
/* @0x2327c4 bl 0x227638 <vorbis_synthesis_blockin> */
/* @0x2327c8 ldrd r0, r1, [sp, #48] */
/* @0x2327cc cmp r0, #0 */
/* @0x2327d0 sbcs r2, r1, #0 */
/* @0x2327d4 blt 0x232838 <ov_pcm_seek+0x144> */
/* @0x2327d8 ldr r4, [r6, #0x60] */
/* @0x2327dc ldr r12, [r6, #0x44] */
/* @0x2327e0 lsl lr, r4, #4 */
/* @0x2327e4 ldrd r2, r3, [r12, lr] */
/* @0x2327e8 subs r2, r0, r2 */
/* @0x2327ec sbc r3, r1, r3 */
/* @0x2327f0 cmp r2, #0 */
/* @0x2327f4 sbcs r1, r3, #0 */
/* @0x2327f8 movlt r2, #0 */
/* @0x2327fc movlt r3, #0 */
/* @0x232800 cmp r4, #0 */
/* @0x232804 strd r2, r3, [r6, #80] */
/* @0x232808 ble 0x232838 <ov_pcm_seek+0x144> */
/* @0x23280c ldrd r0, r1, [r6, #80] */
/* @0x232810 add lr, r12, lr */
/* @0x232814 ldrd r2, r3, [r12, #8] */
/* @0x232818 add r12, r12, #16 */
/* @0x23281c adds r2, r2, r0 */
/* @0x232820 adc r3, r3, r1 */
/* @0x232824 cmp r12, lr */
/* @0x232828 mov r0, r2 */
/* @0x23282c strd r2, r3, [r6, #80] */
/* @0x232830 mov r1, r3 */
/* @0x232834 bne 0x232814 <ov_pcm_seek+0x120> */
/* @0x232838 mov r4, r8 */
/* @0x23283c b 0x23273c <ov_pcm_seek+0x48> */
/* @0x232840 mov r2, #0 */
/* @0x232844 mov r3, #0 */
/* @0x232848 ldrd r4, r5, [r6, #80] */
/* @0x23284c add r7, r6, #480 */
/* @0x232850 strd r2, r3, [r6, #104] */
/* @0x232854 strd r2, r3, [r6, #112] */
/* @0x232858 ldrd r10, r11, [sp, #8] */
/* @0x23285c b 0x2328b8 <ov_pcm_seek+0x1c4> */
/* @0x232860 bl 0x227c80 <vorbis_synthesis_pcmout> */
/* @0x232864 subs r4, r10, r4 */
/* @0x232868 sbc r5, r11, r5 */
/* @0x23286c mov r1, r0 */
/* @0x232870 mov r0, r7 */
/* @0x232874 asr r9, r1, #31 */
/* @0x232878 mov r8, r1 */
/* @0x23287c cmp r4, r8 */
/* @0x232880 sbcs r2, r5, r9 */
/* @0x232884 movlt r8, r4 */
/* @0x232888 movlt r1, r4 */
/* @0x23288c asrlt r9, r8, #31 */
/* @0x232890 bl 0x227cfc <vorbis_synthesis_read> */
/* @0x232894 ldrd r2, r3, [r6, #80] */
/* @0x232898 adds r2, r2, r8 */
/* @0x23289c adc r3, r3, r9 */
/* @0x2328a0 cmp r8, r4 */
/* @0x2328a4 sbcs r1, r9, r5 */
/* @0x2328a8 strd r2, r3, [r6, #80] */
/* @0x2328ac mov r4, r2 */
/* @0x2328b0 mov r5, r3 */
/* @0x2328b4 blt 0x232a00 <ov_pcm_seek+0x30c> */
/* @0x2328b8 cmp r4, r10 */
/* @0x2328bc sbcs r2, r5, r11 */
/* @0x2328c0 mov r0, r7 */
/* @0x2328c4 mov r1, #0 */
/* @0x2328c8 blt 0x232860 <ov_pcm_seek+0x16c> */
/* @0x2328cc mov r0, r1 */
/* @0x2328d0 add sp, sp, #68 */
/* @0x2328d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2328d8 adds r3, r0, #3 */
/* @0x2328dc movne r3, #1 */
/* @0x2328e0 ands r3, r3, r0, lsr #31 */
/* @0x2328e4 bne 0x232840 <ov_pcm_seek+0x14c> */
/* @0x2328e8 mvn r2, #0 */
/* @0x2328ec mov r0, r6 */
/* @0x2328f0 mov r1, r10 */
/* @0x2328f4 mvn r3, #0 */
/* @0x2328f8 bl 0x22fd0c <vorbis_packet_blocksize+0x90> */
/* @0x2328fc cmp r0, #0 */
/* @0x232900 sbcs r2, r1, #0 */
/* @0x232904 blt 0x232840 <ov_pcm_seek+0x14c> */
/* @0x232908 mov r0, r10 */
/* @0x23290c bl 0x233f90 <ogg_page_bos> */
/* @0x232910 cmp r0, #0 */
/* @0x232914 bne 0x232958 <ov_pcm_seek+0x264> */
/* @0x232918 ldr r3, [r6, #0x58] */
/* @0x23291c cmp r3, #2 */
/* @0x232920 ble 0x232970 <ov_pcm_seek+0x27c> */
/* @0x232924 mov r0, r9 */
/* @0x232928 mov r1, r10 */
/* @0x23292c mov r8, r4 */
/* @0x232930 bl 0x234eac <ogg_stream_pagein> */
/* @0x232934 mov r4, r8 */
/* @0x232938 b 0x23273c <ov_pcm_seek+0x48> */
/* @0x23293c add r3, r4, r8 */
/* @0x232940 ldrd r4, r5, [r6, #80] */
/* @0x232944 asr r3, r3, #2 */
/* @0x232948 adds r4, r4, r3 */
/* @0x23294c adc r5, r5, r3, asr #31 */
/* @0x232950 strd r4, r5, [r6, #80] */
/* @0x232954 b 0x232778 <ov_pcm_seek+0x84> */
/* @0x232958 ldr r0, [sp, #0x4] */
/* @0x23295c bl 0x2272ac <vorbis_dsp_clear> */
/* @0x232960 mov r0, r11 */
/* @0x232964 bl 0x227208 <vorbis_block_clear> */
/* @0x232968 mov r3, #2 */
/* @0x23296c str r3, [r6, #0x58] */
/* @0x232970 mov r0, r10 */
/* @0x232974 bl 0x23409c <ogg_page_serialno> */
/* @0x232978 ldr r1, [r6, #0x34] */
/* @0x23297c cmp r1, #0 */
/* @0x232980 mov r5, r0 */
/* @0x232984 ble 0x232a18 <ov_pcm_seek+0x324> */
/* @0x232988 ldr r2, [r6, #0x40] */
/* @0x23298c ldr r3, [r2] */
/* @0x232990 cmp r3, r0 */
/* @0x232994 mov r3, #0 */
/* @0x232998 beq 0x2329b4 <ov_pcm_seek+0x2c0> */
/* @0x23299c add r3, r3, #1 */
/* @0x2329a0 cmp r3, r1 */
/* @0x2329a4 beq 0x23273c <ov_pcm_seek+0x48> */
/* @0x2329a8 ldr r0, [r2, #0x4]! */
/* @0x2329ac cmp r0, r5 */
/* @0x2329b0 bne 0x23299c <ov_pcm_seek+0x2a8> */
/* @0x2329b4 str r3, [r6, #0x60] */
/* @0x2329b8 mov r0, r10 */
/* @0x2329bc mov r3, #3 */
/* @0x2329c0 str r3, [r6, #0x58] */
/* @0x2329c4 bl 0x23409c <ogg_page_serialno> */
/* @0x2329c8 mov r1, r5 */
/* @0x2329cc str r0, [r6, #0x5c] */
/* @0x2329d0 mov r0, r9 */
/* @0x2329d4 bl 0x2352f4 <ogg_stream_reset_serialno> */
/* @0x2329d8 mov r0, r6 */
/* @0x2329dc bl 0x230294 <vorbis_packet_blocksize+0x618> */
/* @0x2329e0 cmp r0, #0 */
/* @0x2329e4 bne 0x2328d0 <ov_pcm_seek+0x1dc> */
/* @0x2329e8 mov r4, r0 */
/* @0x2329ec b 0x232924 <ov_pcm_seek+0x230> */
/* @0x2329f0 mov r0, r9 */
/* @0x2329f4 mov r1, #0 */
/* @0x2329f8 bl 0x235328 <ogg_stream_packetout> */
/* @0x2329fc b 0x23273c <ov_pcm_seek+0x48> */
/* @0x232a00 mov r0, r6 */
/* @0x232a04 bl 0x230b68 <vorbis_packet_blocksize+0xeec> */
/* @0x232a08 cmp r0, #0 */
/* @0x232a0c ble 0x232a24 <ov_pcm_seek+0x330> */
/* @0x232a10 ldrd r4, r5, [r6, #80] */
/* @0x232a14 b 0x2328b8 <ov_pcm_seek+0x1c4> */
/* @0x232a18 beq 0x23273c <ov_pcm_seek+0x48> */
/* @0x232a1c mov r3, #0 */
/* @0x232a20 b 0x2329b4 <ov_pcm_seek+0x2c0> */
/* @0x232a24 mov r0, r6 */
/* @0x232a28 mvn r1, #0 */
/* @0x232a2c bl 0x23138c <ov_pcm_total> */
/* @0x232a30 str r1, [r6, #0x54] */
/* @0x232a34 mov r4, r0 */
/* @0x232a38 str r0, [r6, #0x50] */
/* @0x232a3c mov r5, r1 */
/* @0x232a40 b 0x2328b8 <ov_pcm_seek+0x1c4> */

/* ── FUNC 0x232a44 · ov_time_seek · size=328 · insn=82 */
/* @0x232a44 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x232a48 sub sp, sp, #20 */
/* @0x232a4c mov r9, r0 */
/* @0x232a50 strd r2, r3, [sp, #8] */
/* @0x232a54 ldr r3, [r0, #0x58] */
/* @0x232a58 cmp r3, #1 */
/* @0x232a5c ble 0x232b60 <ov_time_seek+0x11c> */
/* @0x232a60 ldr r3, [r0, #0x4] */
/* @0x232a64 cmp r3, #0 */
/* @0x232a68 beq 0x232b84 <ov_time_seek+0x140> */
/* @0x232a6c ldrd r2, r3, [sp, #8] */
/* @0x232a70 cmp r2, #0 */
/* @0x232a74 sbcs r3, r3, #0 */
/* @0x232a78 blt 0x232b60 <ov_time_seek+0x11c> */
/* @0x232a7c ldr r1, [r0, #0x34] */
/* @0x232a80 cmp r1, #0 */
/* @0x232a84 ble 0x232b6c <ov_time_seek+0x128> */
/* @0x232a88 mov r4, #0 */
/* @0x232a8c mov r5, #0 */
/* @0x232a90 mov r6, #8 */
/* @0x232a94 mov r10, r4 */
/* @0x232a98 mov r11, r5 */
/* @0x232a9c mov r8, #0 */
/* @0x232aa0 b 0x232ad0 <ov_time_seek+0x8c> */
/* @0x232aa4 ldr r12, [r9, #0x44] */
/* @0x232aa8 add r8, r8, #1 */
/* @0x232aac ldr r7, [r9, #0x34] */
/* @0x232ab0 mov r4, r2 */
/* @0x232ab4 mov r5, r3 */
/* @0x232ab8 ldrd r0, r1, [r12, r6] */
/* @0x232abc add r6, r6, #16 */
/* @0x232ac0 adds r10, r10, r0 */
/* @0x232ac4 adc r11, r11, r1 */
/* @0x232ac8 cmp r7, r8 */
/* @0x232acc ble 0x232b58 <ov_time_seek+0x114> */
/* @0x232ad0 mov r0, r9 */
/* @0x232ad4 mov r1, r8 */
/* @0x232ad8 bl 0x231424 <ov_time_total> */
/* @0x232adc adds r2, r4, r0 */
/* @0x232ae0 adc r3, r5, r1 */
/* @0x232ae4 ldrd r0, r1, [sp, #8] */
/* @0x232ae8 cmp r0, r2 */
/* @0x232aec sbcs r1, r1, r3 */
/* @0x232af0 bge 0x232aa4 <ov_time_seek+0x60> */
/* @0x232af4 ldr r1, [r9, #0x34] */
/* @0x232af8 mov r2, r4 */
/* @0x232afc mov r3, r5 */
/* @0x232b00 cmp r1, r8 */
/* @0x232b04 beq 0x232b60 <ov_time_seek+0x11c> */
/* @0x232b08 ldr r1, [r9, #0x48] */
/* @0x232b0c ldrd r4, r5, [sp, #8] */
/* @0x232b10 add r8, r1, r8, lsl #5 */
/* @0x232b14 subs r4, r4, r2 */
/* @0x232b18 sbc r5, r5, r3 */
/* @0x232b1c mov r2, #1000 */
/* @0x232b20 ldr r12, [r8, #0x8] */
/* @0x232b24 mov r3, #0 */
/* @0x232b28 asr r7, r12, #31 */
/* @0x232b2c umull r0, r1, r4, r12 */
/* @0x232b30 mul lr, r4, r7 */
/* @0x232b34 mla r12, r12, r5, lr */
/* @0x232b38 add r1, r12, r1 */
/* @0x232b3c bl 0x319414 <__aeabi_ldivmod> */
/* @0x232b40 adds r2, r0, r10 */
/* @0x232b44 mov r0, r9 */
/* @0x232b48 adc r3, r1, r11 */
/* @0x232b4c add sp, sp, #20 */
/* @0x232b50 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x232b54 b 0x2326f4 <ov_pcm_seek> */
/* @0x232b58 mov r1, r7 */
/* @0x232b5c b 0x232b00 <ov_time_seek+0xbc> */
/* @0x232b60 mvn r0, #130 */
/* @0x232b64 add sp, sp, #20 */
/* @0x232b68 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x232b6c mov r2, #0 */
/* @0x232b70 mov r3, #0 */
/* @0x232b74 mov r8, #0 */
/* @0x232b78 mov r10, r2 */
/* @0x232b7c mov r11, r3 */
/* @0x232b80 b 0x232b00 <ov_time_seek+0xbc> */
/* @0x232b84 mvn r0, #137 */
/* @0x232b88 b 0x232b64 <ov_time_seek+0x120> */

/* ── FUNC 0x232b8c · ov_time_seek_page · size=328 · insn=82 */
/* @0x232b8c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x232b90 sub sp, sp, #20 */
/* @0x232b94 mov r9, r0 */
/* @0x232b98 strd r2, r3, [sp, #8] */
/* @0x232b9c ldr r3, [r0, #0x58] */
/* @0x232ba0 cmp r3, #1 */
/* @0x232ba4 ble 0x232ca8 <ov_time_seek_page+0x11c> */
/* @0x232ba8 ldr r3, [r0, #0x4] */
/* @0x232bac cmp r3, #0 */
/* @0x232bb0 beq 0x232ccc <ov_time_seek_page+0x140> */
/* @0x232bb4 ldrd r2, r3, [sp, #8] */
/* @0x232bb8 cmp r2, #0 */
/* @0x232bbc sbcs r3, r3, #0 */
/* @0x232bc0 blt 0x232ca8 <ov_time_seek_page+0x11c> */
/* @0x232bc4 ldr r1, [r0, #0x34] */
/* @0x232bc8 cmp r1, #0 */
/* @0x232bcc ble 0x232cb4 <ov_time_seek_page+0x128> */
/* @0x232bd0 mov r4, #0 */
/* @0x232bd4 mov r5, #0 */
/* @0x232bd8 mov r6, #8 */
/* @0x232bdc mov r10, r4 */
/* @0x232be0 mov r11, r5 */
/* @0x232be4 mov r8, #0 */
/* @0x232be8 b 0x232c18 <ov_time_seek_page+0x8c> */
/* @0x232bec ldr r12, [r9, #0x44] */
/* @0x232bf0 add r8, r8, #1 */
/* @0x232bf4 ldr r7, [r9, #0x34] */
/* @0x232bf8 mov r4, r2 */
/* @0x232bfc mov r5, r3 */
/* @0x232c00 ldrd r0, r1, [r12, r6] */
/* @0x232c04 add r6, r6, #16 */
/* @0x232c08 adds r10, r10, r0 */
/* @0x232c0c adc r11, r11, r1 */
/* @0x232c10 cmp r7, r8 */
/* @0x232c14 ble 0x232ca0 <ov_time_seek_page+0x114> */
/* @0x232c18 mov r0, r9 */
/* @0x232c1c mov r1, r8 */
/* @0x232c20 bl 0x231424 <ov_time_total> */
/* @0x232c24 adds r2, r4, r0 */
/* @0x232c28 adc r3, r5, r1 */
/* @0x232c2c ldrd r0, r1, [sp, #8] */
/* @0x232c30 cmp r0, r2 */
/* @0x232c34 sbcs r1, r1, r3 */
/* @0x232c38 bge 0x232bec <ov_time_seek_page+0x60> */
/* @0x232c3c ldr r1, [r9, #0x34] */
/* @0x232c40 mov r2, r4 */
/* @0x232c44 mov r3, r5 */
/* @0x232c48 cmp r1, r8 */
/* @0x232c4c beq 0x232ca8 <ov_time_seek_page+0x11c> */
/* @0x232c50 ldr r1, [r9, #0x48] */
/* @0x232c54 ldrd r4, r5, [sp, #8] */
/* @0x232c58 add r8, r1, r8, lsl #5 */
/* @0x232c5c subs r4, r4, r2 */
/* @0x232c60 sbc r5, r5, r3 */
/* @0x232c64 mov r2, #1000 */
/* @0x232c68 ldr r12, [r8, #0x8] */
/* @0x232c6c mov r3, #0 */
/* @0x232c70 asr r7, r12, #31 */
/* @0x232c74 umull r0, r1, r4, r12 */
/* @0x232c78 mul lr, r4, r7 */
/* @0x232c7c mla r12, r12, r5, lr */
/* @0x232c80 add r1, r12, r1 */
/* @0x232c84 bl 0x319414 <__aeabi_ldivmod> */
/* @0x232c88 adds r2, r0, r10 */
/* @0x232c8c mov r0, r9 */
/* @0x232c90 adc r3, r1, r11 */
/* @0x232c94 add sp, sp, #20 */
/* @0x232c98 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x232c9c b 0x231ed4 <ov_pcm_seek_page> */
/* @0x232ca0 mov r1, r7 */
/* @0x232ca4 b 0x232c48 <ov_time_seek_page+0xbc> */
/* @0x232ca8 mvn r0, #130 */
/* @0x232cac add sp, sp, #20 */
/* @0x232cb0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x232cb4 mov r2, #0 */
/* @0x232cb8 mov r3, #0 */
/* @0x232cbc mov r8, #0 */
/* @0x232cc0 mov r10, r2 */
/* @0x232cc4 mov r11, r3 */
/* @0x232cc8 b 0x232c48 <ov_time_seek_page+0xbc> */
/* @0x232ccc mvn r0, #137 */
/* @0x232cd0 b 0x232cac <ov_time_seek_page+0x120> */

/* ── FUNC 0x232cd4 · ov_raw_tell · size=24 · insn=6 */
/* @0x232cd4 ldr r3, [r0, #0x58] */
/* @0x232cd8 cmp r3, #1 */
/* @0x232cdc ldrdgt r0, r1, [r0, #8] */
/* @0x232ce0 mvnle r0, #130 */
/* @0x232ce4 mvnle r1, #0 */
/* @0x232ce8 bx lr */

/* ── FUNC 0x232cec · ov_pcm_tell · size=24 · insn=6 */
/* @0x232cec ldr r3, [r0, #0x58] */
/* @0x232cf0 cmp r3, #1 */
/* @0x232cf4 ldrdgt r0, r1, [r0, #80] */
/* @0x232cf8 mvnle r0, #130 */
/* @0x232cfc mvnle r1, #0 */
/* @0x232d00 bx lr */
