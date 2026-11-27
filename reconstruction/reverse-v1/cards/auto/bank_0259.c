/* libyoyo.so 覆盖卡组 0259
 * 函数 0x2af82a..0x2b0710，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2af82a · png_set_swap_alpha · size=16 · insn=8 */
/* @0x2af82a cbz r0, 0x2af838 <png_set_swap_alpha+0xe> */
/* @0x2af82c ldr.w r3, [r0, #0x134] */
/* @0x2af82e vst4.8 {d19, d21, d23, d25}, [r3:256], r4 */
/* @0x2af830 orr r3, r3, #0x20000 */
/* @0x2af832 .word 0xf8c03300 */
/* @0x2af834 str.w r3, [r0, #0x134] */
/* @0x2af836 .word 0x47703134 */
/* @0x2af838 bx lr */

/* ── FUNC 0x2af83a · png_set_invert_alpha · size=16 · insn=8 */
/* @0x2af83a cbz r0, 0x2af848 <png_set_invert_alpha+0xe> */
/* @0x2af83c ldr.w r3, [r0, #0x134] */
/* @0x2af83e vst4.8 {d19, d21, d23, d25}, [r3:256], r4 */
/* @0x2af840 orr r3, r3, #0x80000 */
/* @0x2af842 .word 0xf8c02300 */
/* @0x2af844 str.w r3, [r0, #0x134] */
/* @0x2af846 .word 0x47703134 */
/* @0x2af848 bx lr */

/* ── FUNC 0x2af84a · png_set_invert_mono · size=16 · insn=8 */
/* @0x2af84a cbz r0, 0x2af858 <png_set_invert_mono+0xe> */
/* @0x2af84c ldr.w r3, [r0, #0x134] */
/* @0x2af84e .word 0xf0433134 */
/* @0x2af850 orr r3, r3, #0x20 */
/* @0x2af852 .word 0xf8c00320 */
/* @0x2af854 str.w r3, [r0, #0x134] */
/* @0x2af856 .word 0x47703134 */
/* @0x2af858 bx lr */

/* ── FUNC 0x2af85a · png_do_invert · size=92 · insn=44 */
/* @0x2af85a push {r4, lr} */
/* @0x2af85c ldrb r3, [r0, #0x8] */
/* @0x2af85e cbnz r3, 0x2af874 <png_do_invert+0x1a> */
/* @0x2af860 ldr r3, [r0, #0x4] */
/* @0x2af862 add r3, r1 */
/* @0x2af864 cmp r1, r3 */
/* @0x2af866 beq 0x2af872 <png_do_invert+0x18> */
/* @0x2af868 ldrb r2, [r1] */
/* @0x2af86a mvns r2, r2 */
/* @0x2af86c strb r2, [r1], #1 */
/* @0x2af86e ldrb r2, [r8, r1, lsl #22]! */
/* @0x2af870 b 0x2af864 <png_do_invert+0xa> */
/* @0x2af872 pop {r4, pc} */
/* @0x2af874 ldrh r3, [r0, #0x8] */
/* @0x2af876 movw r2, #0x804 */
/* @0x2af87a cmp r3, r2 */
/* @0x2af87c bne 0x2af892 <png_do_invert+0x38> */
/* @0x2af87e ldr r2, [r0, #0x4] */
/* @0x2af880 movs r3, #0x0 */
/* @0x2af882 cmp r3, r2 */
/* @0x2af884 bhs 0x2af890 <png_do_invert+0x36> */
/* @0x2af886 ldrb r0, [r1, r3] */
/* @0x2af888 mvns r0, r0 */
/* @0x2af88a strb r0, [r1, r3] */
/* @0x2af88c adds r3, #0x2 */
/* @0x2af88e b 0x2af882 <png_do_invert+0x28> */
/* @0x2af890 pop {r4, pc} */
/* @0x2af892 movw r2, #0x1004 */
/* @0x2af896 cmp r3, r2 */
/* @0x2af898 bne 0x2af8b4 <png_do_invert+0x5a> */
/* @0x2af89a ldr r0, [r0, #0x4] */
/* @0x2af89c movs r3, #0x0 */
/* @0x2af89e cmp r3, r0 */
/* @0x2af8a0 bhs 0x2af8b4 <png_do_invert+0x5a> */
/* @0x2af8a2 ldrb r2, [r1, r3] */
/* @0x2af8a4 mvns r2, r2 */
/* @0x2af8a6 strb r2, [r1, r3] */
/* @0x2af8a8 adds r2, r1, r3 */
/* @0x2af8aa adds r3, #0x4 */
/* @0x2af8ac ldrb r4, [r2, #0x1] */
/* @0x2af8ae mvns r4, r4 */
/* @0x2af8b0 strb r4, [r2, #0x1] */
/* @0x2af8b2 b 0x2af89e <png_do_invert+0x44> */
/* @0x2af8b4 pop {r4, pc} */

/* ── FUNC 0x2af8b6 · png_do_swap · size=46 · insn=22 */
/* @0x2af8b6 push {r4, lr} */
/* @0x2af8b8 ldrb r3, [r0, #0x9] */
/* @0x2af8ba cmp r3, #0x10 */
/* @0x2af8bc bne 0x2af8e2 <png_do_swap+0x2c> */
/* @0x2af8be ldrb r3, [r0, #0xa] */
/* @0x2af8c0 ldr r2, [r0] */
/* @0x2af8c2 muls r2, r3, r2 */
/* @0x2af8c4 movs r3, #0x0 */
/* @0x2af8c6 cmp r3, r2 */
/* @0x2af8c8 add.w r1, r1, #0x2 */
/* @0x2af8ca andle r0, r9, r2, lsl #2 */
/* @0x2af8cc beq 0x2af8e2 <png_do_swap+0x2c> */
/* @0x2af8ce ldrb r0, [r1, #-2] */
/* @0x2af8d2 adds r3, #0x1 */
/* @0x2af8d4 ldrb r4, [r1, #-1] */
/* @0x2af8d6 .word 0xf8014c01 */
/* @0x2af8d8 strb r0, [r1, #-1] */
/* @0x2af8da .word 0xf8010c01 */
/* @0x2af8dc strb r4, [r1, #-2] */
/* @0x2af8de ldrb r4, [r1, r2, lsl #24]! */
/* @0x2af8e0 b 0x2af8c6 <png_do_swap+0x10> */
/* @0x2af8e2 pop {r4, pc} */

/* ── FUNC 0x2af8e4 · png_do_packswap · size=76 · insn=35 */
/* @0x2af8e4 ldrb r3, [r0, #0x9] */
/* @0x2af8e6 cmp r3, #0x7 */
/* @0x2af8e8 bhi 0x2af922 <png_do_packswap+0x3e> */
/* @0x2af8ea cmp r3, #0x1 */
/* @0x2af8ec ldr r2, [r0, #0x4] */
/* @0x2af8ee beq 0x2af902 <png_do_packswap+0x1e> */
/* @0x2af8f0 cmp r3, #0x2 */
/* @0x2af8f2 beq 0x2af908 <png_do_packswap+0x24> */
/* @0x2af8f4 cmp r3, #0x4 */
/* @0x2af8f6 bne 0x2af922 <png_do_packswap+0x3e> */
/* @0x2af8f8 ldr r3, [pc, #0x28] */
/* @0x2af8fa add r3, pc */
/* @0x2af8fc add.w r3, r3, #0x200 */
/* @0x2af900 b 0x2af910 <png_do_packswap+0x2c> */
/* @0x2af902 ldr r3, [pc, #0x24] */
/* @0x2af904 add r3, pc */
/* @0x2af906 b 0x2af910 <png_do_packswap+0x2c> */
/* @0x2af908 ldr r3, [pc, #0x20] */
/* @0x2af90a add r3, pc */
/* @0x2af90c add.w r3, r3, #0x100 */
/* @0x2af910 add r2, r1 */
/* @0x2af912 cmp r1, r2 */
/* @0x2af914 mov r0, r1 */
/* @0x2af916 bhs 0x2af922 <png_do_packswap+0x3e> */
/* @0x2af918 ldrb r0, [r0] */
/* @0x2af91a ldrb r0, [r3, r0] */
/* @0x2af91c strb r0, [r1], #1 */
/* @0x2af920 b 0x2af912 <png_do_packswap+0x2e> */
/* @0x2af922 bx lr */
/* @0x2af924 lsls r6, r4, #0x5 */
/* @0x2af926 movs r6, r1 */
/* @0x2af928 lsls r4, r3, #0x5 */
/* @0x2af92a movs r6, r1 */
/* @0x2af92c lsls r6, r2, #0x5 */
/* @0x2af92e movs r6, r1 */

/* ── FUNC 0x2af930 · png_do_strip_filler · size=440 · insn=181 */
/* @0x2af930 push {r4, r5, r6, lr} */
/* @0x2af932 ldrb r4, [r0, #0x8] */
/* @0x2af934 ldr r3, [r0] */
/* @0x2af936 cmp r4, #0x2 */
/* @0x2af938 beq 0x2af946 <png_do_strip_filler+0x16> */
/* @0x2af93a cmp r4, #0x6 */
/* @0x2af93c bne.w 0x2afa42 <png_do_strip_filler+0x112> */
/* @0x2af940 lsls r5, r2, #0x9 */
/* @0x2af942 bpl.w 0x2afada <png_do_strip_filler+0x1aa> */
/* @0x2af944 bvc 0xfe40fc74 <b2_toiTime+0xfffffffffdcb67d0> */
/* @0x2af946 ldrb r5, [r0, #0xa] */
/* @0x2af948 cmp r5, #0x4 */
/* @0x2af94a bne 0x2afa42 <png_do_strip_filler+0x112> */
/* @0x2af94c ldrb r4, [r0, #0x9] */
/* @0x2af94e and r5, r2, #0x80 */
/* @0x2af950 .word 0x2c080580 */
/* @0x2af952 cmp r4, #0x8 */
/* @0x2af954 bne 0x2af9b2 <png_do_strip_filler+0x82> */
/* @0x2af956 cbnz r5, 0x2af962 <png_do_strip_filler+0x32> */
/* @0x2af958 movs r5, #0x3 */
/* @0x2af95a mov r4, r1 */
/* @0x2af95c mla r5, r5, r3, r1 */
/* @0x2af960 b 0x2af992 <png_do_strip_filler+0x62> */
/* @0x2af962 adds r4, r1, #0x4 */
/* @0x2af964 adds r1, #0x3 */
/* @0x2af966 movs r5, #0x1 */
/* @0x2af968 cmp r5, r3 */
/* @0x2af96a bhs 0x2af98a <png_do_strip_filler+0x5a> */
/* @0x2af96c ldrb r6, [r4] */
/* @0x2af96e adds r5, #0x1 */
/* @0x2af970 adds r4, #0x4 */
/* @0x2af972 adds r1, #0x3 */
/* @0x2af974 strb r6, [r1, #-3] */
/* @0x2af978 ldrb r6, [r4, #-3] */
/* @0x2af97c strb r6, [r1, #-2] */
/* @0x2af980 ldrb r6, [r4, #-2] */
/* @0x2af984 strb r6, [r1, #-1] */
/* @0x2af988 b 0x2af968 <png_do_strip_filler+0x38> */
/* @0x2af98a movs r1, #0x18 */
/* @0x2af98c strb r1, [r0, #0xb] */
/* @0x2af98e movs r1, #0x3 */
/* @0x2af990 b 0x2afa00 <png_do_strip_filler+0xd0> */
/* @0x2af992 cmp r4, r5 */
/* @0x2af994 beq 0x2af98a <png_do_strip_filler+0x5a> */
/* @0x2af996 ldrb r6, [r1, #0x1] */
/* @0x2af998 adds r4, #0x3 */
/* @0x2af99a adds r1, #0x4 */
/* @0x2af99c strb r6, [r4, #-3] */
/* @0x2af9a0 ldrb r6, [r1, #-2] */
/* @0x2af9a4 strb r6, [r4, #-2] */
/* @0x2af9a8 ldrb r6, [r1, #-1] */
/* @0x2af9ac strb r6, [r4, #-1] */
/* @0x2af9b0 b 0x2af992 <png_do_strip_filler+0x62> */
/* @0x2af9b2 cbnz r5, 0x2af9b8 <png_do_strip_filler+0x88> */
/* @0x2af9b4 mov r4, r1 */
/* @0x2af9b6 b 0x2afa08 <png_do_strip_filler+0xd8> */
/* @0x2af9b8 add.w r4, r1, #0x8 */
/* @0x2af9bc adds r1, #0x6 */
/* @0x2af9be movs r5, #0x1 */
/* @0x2af9c0 cmp r5, r3 */
/* @0x2af9c2 bhs 0x2af9fa <png_do_strip_filler+0xca> */
/* @0x2af9c4 ldrb r6, [r4] */
/* @0x2af9c6 adds r5, #0x1 */
/* @0x2af9c8 adds r4, #0x8 */
/* @0x2af9ca adds r1, #0x6 */
/* @0x2af9cc strb r6, [r1, #-6] */
/* @0x2af9d0 ldrb r6, [r4, #-7] */
/* @0x2af9d4 strb r6, [r1, #-5] */
/* @0x2af9d8 ldrb r6, [r4, #-6] */
/* @0x2af9dc strb r6, [r1, #-4] */
/* @0x2af9e0 ldrb r6, [r4, #-5] */
/* @0x2af9e4 strb r6, [r1, #-3] */
/* @0x2af9e8 ldrb r6, [r4, #-4] */
/* @0x2af9ec strb r6, [r1, #-2] */
/* @0x2af9f0 ldrb r6, [r4, #-3] */
/* @0x2af9f4 strb r6, [r1, #-1] */
/* @0x2af9f8 b 0x2af9c0 <png_do_strip_filler+0x90> */
/* @0x2af9fa movs r1, #0x30 */
/* @0x2af9fc strb r1, [r0, #0xb] */
/* @0x2af9fe movs r1, #0x6 */
/* @0x2afa00 muls r3, r1, r3 */
/* @0x2afa02 str r3, [r0, #0x4] */
/* @0x2afa04 movs r3, #0x3 */
/* @0x2afa06 b 0x2afad8 <png_do_strip_filler+0x1a8> */
/* @0x2afa08 cmp r5, r3 */
/* @0x2afa0a beq 0x2af9fa <png_do_strip_filler+0xca> */
/* @0x2afa0c ldrb r6, [r1, #0x2] */
/* @0x2afa0e adds r5, #0x1 */
/* @0x2afa10 adds r1, #0x8 */
/* @0x2afa12 adds r4, #0x6 */
/* @0x2afa14 strb r6, [r4, #-6] */
/* @0x2afa18 ldrb r6, [r1, #-5] */
/* @0x2afa1c strb r6, [r4, #-5] */
/* @0x2afa20 ldrb r6, [r1, #-4] */
/* @0x2afa24 strb r6, [r4, #-4] */
/* @0x2afa28 ldrb r6, [r1, #-3] */
/* @0x2afa2c strb r6, [r4, #-3] */
/* @0x2afa30 ldrb r6, [r1, #-2] */
/* @0x2afa34 strb r6, [r4, #-2] */
/* @0x2afa38 ldrb r6, [r1, #-1] */
/* @0x2afa3c strb r6, [r4, #-1] */
/* @0x2afa40 b 0x2afa08 <png_do_strip_filler+0xd8> */
/* @0x2afa42 cbz r4, 0x2afa4c <png_do_strip_filler+0x11c> */
/* @0x2afa44 cmp r4, #0x4 */
/* @0x2afa46 bne 0x2afada <png_do_strip_filler+0x1aa> */
/* @0x2afa48 lsls r4, r2, #0x9 */
/* @0x2afa4a bpl 0x2afada <png_do_strip_filler+0x1aa> */
/* @0x2afa4c ldrb r4, [r0, #0xa] */
/* @0x2afa4e cmp r4, #0x2 */
/* @0x2afa50 bne 0x2afada <png_do_strip_filler+0x1aa> */
/* @0x2afa52 ldrb r4, [r0, #0x9] */
/* @0x2afa54 cmp r4, #0x8 */
/* @0x2afa56 and r4, r2, #0x80 */
/* @0x2afa58 tstle r3, r0, lsl #9 */
/* @0x2afa5a bne 0x2afa84 <png_do_strip_filler+0x154> */
/* @0x2afa5c cbz r4, 0x2afa74 <png_do_strip_filler+0x144> */
/* @0x2afa5e movs r4, #0x0 */
/* @0x2afa60 cmp r4, r3 */
/* @0x2afa62 beq 0x2afa6e <png_do_strip_filler+0x13e> */
/* @0x2afa64 ldrb.w r5, [r1, r4, lsl #1] */
/* @0x2afa68 strb r5, [r1, r4] */
/* @0x2afa6a adds r4, #0x1 */
/* @0x2afa6c b 0x2afa60 <png_do_strip_filler+0x130> */
/* @0x2afa6e movs r1, #0x8 */
/* @0x2afa70 strb r1, [r0, #0xb] */
/* @0x2afa72 b 0x2afab6 <png_do_strip_filler+0x186> */
/* @0x2afa74 cmp r4, r3 */
/* @0x2afa76 beq 0x2afa6e <png_do_strip_filler+0x13e> */
/* @0x2afa78 add.w r5, r1, r4, lsl #1 */
/* @0x2afa7c ldrb r5, [r5, #0x1] */
/* @0x2afa7e strb r5, [r1, r4] */
/* @0x2afa80 adds r4, #0x1 */
/* @0x2afa82 b 0x2afa74 <png_do_strip_filler+0x144> */
/* @0x2afa84 cbnz r4, 0x2afa8a <png_do_strip_filler+0x15a> */
/* @0x2afa86 mov r5, r1 */
/* @0x2afa88 b 0x2afabc <png_do_strip_filler+0x18c> */
/* @0x2afa8a adds r4, r1, #0x4 */
/* @0x2afa8c adds r1, #0x2 */
/* @0x2afa8e movs r5, #0x1 */
/* @0x2afa90 cmp r5, r3 */
/* @0x2afa92 add.w r4, r4, #0x4 */
/* @0x2afa94 .word 0xf1010404 */
/* @0x2afa96 add.w r1, r1, #0x2 */
/* @0x2afa98 andle r0, r9, #-2147483648 */
/* @0x2afa9a bhs 0x2afab0 <png_do_strip_filler+0x180> */
/* @0x2afa9c ldrb r6, [r4, #-4] */
/* @0x2afaa0 adds r5, #0x1 */
/* @0x2afaa2 strb r6, [r1, #-2] */
/* @0x2afaa4 .word 0xf8146c02 */
/* @0x2afaa6 ldrb r6, [r4, #-3] */
/* @0x2afaa8 .word 0xf8016c03 */
/* @0x2afaaa strb r6, [r1, #-1] */
/* @0x2afaac strb r6, [pc, r1, lsl #24]! */
/* @0x2afaae b 0x2afa90 <png_do_strip_filler+0x160> */
/* @0x2afab0 lsls r3, r3, #0x1 */
/* @0x2afab2 movs r1, #0x10 */
/* @0x2afab4 strb r1, [r0, #0xb] */
/* @0x2afab6 str r3, [r0, #0x4] */
/* @0x2afab8 movs r3, #0x1 */
/* @0x2afaba b 0x2afad8 <png_do_strip_filler+0x1a8> */
/* @0x2afabc cmp r4, r3 */
/* @0x2afabe add.w r5, r5, #0x2 */
/* @0x2afac0 rscsle r0, r5, r2, lsl #10 */
/* @0x2afac2 beq 0x2afab0 <png_do_strip_filler+0x180> */
/* @0x2afac4 ldrb r6, [r1, #0x2] */
/* @0x2afac6 adds r4, #0x1 */
/* @0x2afac8 adds r1, #0x4 */
/* @0x2afaca strb r6, [r5, #-2] */
/* @0x2afacc .word 0xf8116c02 */
/* @0x2aface ldrb r6, [r1, #-1] */
/* @0x2afad0 .word 0xf8056c01 */
/* @0x2afad2 strb r6, [r5, #-1] */
/* @0x2afad4 ldrb r6, [r1, r1, lsl #24]! */
/* @0x2afad6 b 0x2afabc <png_do_strip_filler+0x18c> */
/* @0x2afad8 strb r3, [r0, #0xa] */
/* @0x2afada lsls r3, r2, #0x9 */
/* @0x2afadc bpl 0x2afae6 <png_do_strip_filler+0x1b6> */
/* @0x2afade ldrb r3, [r0, #0x8] */
/* @0x2afae0 bic r3, r3, #0x4 */
/* @0x2afae4 strb r3, [r0, #0x8] */
/* @0x2afae6 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2afae8 · png_do_bgr · size=182 · insn=84 */
/* @0x2afae8 push {r4, lr} */
/* @0x2afaea ldrb r3, [r0, #0x8] */
/* @0x2afaec lsls r2, r3, #0x1e */
/* @0x2afaee bpl 0x2afb9c <png_do_bgr+0xb4> */
/* @0x2afaf0 ldr r2, [r0] */
/* @0x2afaf2 ldrb r0, [r0, #0x9] */
/* @0x2afaf4 cmp r0, #0x8 */
/* @0x2afaf6 bne 0x2afb3e <png_do_bgr+0x56> */
/* @0x2afaf8 cmp r3, #0x2 */
/* @0x2afafa bne 0x2afb1a <png_do_bgr+0x32> */
/* @0x2afafc movs r3, #0x3 */
/* @0x2afafe mla r2, r3, r2, r1 */
/* @0x2afb00 addsmi r1, r1, #536870912 */
/* @0x2afb02 cmp r1, r2 */
/* @0x2afb04 beq 0x2afb18 <png_do_bgr+0x30> */
/* @0x2afb06 ldrb r3, [r1] */
/* @0x2afb08 adds r1, #0x3 */
/* @0x2afb0a ldrb r0, [r1, #-1] */
/* @0x2afb0c .word 0xf8010c01 */
/* @0x2afb0e strb r3, [r1, #-1] */
/* @0x2afb10 .word 0xf8013c01 */
/* @0x2afb12 strb r0, [r1, #-3] */
/* @0x2afb14 ldrb r0, [r4, r3, lsl #24]! */
/* @0x2afb16 b 0x2afb02 <png_do_bgr+0x1a> */
/* @0x2afb18 pop {r4, pc} */
/* @0x2afb1a cmp r3, #0x6 */
/* @0x2afb1c bne 0x2afb9c <png_do_bgr+0xb4> */
/* @0x2afb1e movs r3, #0x0 */
/* @0x2afb20 cmp r3, r2 */
/* @0x2afb22 add.w r1, r1, #0x4 */
/* @0x2afb24 andle r0, r9, r4, lsl #2 */
/* @0x2afb26 beq 0x2afb3c <png_do_bgr+0x54> */
/* @0x2afb28 ldrb r0, [r1, #-4] */
/* @0x2afb2c adds r3, #0x1 */
/* @0x2afb2e ldrb r4, [r1, #-2] */
/* @0x2afb30 .word 0xf8014c02 */
/* @0x2afb32 strb r0, [r1, #-2] */
/* @0x2afb34 .word 0xf8010c02 */
/* @0x2afb36 strb r4, [r1, #-4] */
/* @0x2afb38 ldrb r4, [r1, r4, lsl #24]! */
/* @0x2afb3a b 0x2afb20 <png_do_bgr+0x38> */
/* @0x2afb3c pop {r4, pc} */
/* @0x2afb3e cmp r0, #0x10 */
/* @0x2afb40 bne 0x2afb9c <png_do_bgr+0xb4> */
/* @0x2afb42 cmp r3, #0x2 */
/* @0x2afb44 bne 0x2afb70 <png_do_bgr+0x88> */
/* @0x2afb46 movs r3, #0x0 */
/* @0x2afb48 cmp r3, r2 */
/* @0x2afb4a beq 0x2afb6e <png_do_bgr+0x86> */
/* @0x2afb4c ldrb r0, [r1] */
/* @0x2afb4e adds r3, #0x1 */
/* @0x2afb50 ldrb r4, [r1, #0x4] */
/* @0x2afb52 adds r1, #0x6 */
/* @0x2afb54 strb r0, [r1, #-2] */
/* @0x2afb58 strb r4, [r1, #-6] */
/* @0x2afb5c ldrb r0, [r1, #-5] */
/* @0x2afb60 ldrb r4, [r1, #-1] */
/* @0x2afb64 strb r0, [r1, #-1] */
/* @0x2afb68 strb r4, [r1, #-5] */
/* @0x2afb6c b 0x2afb48 <png_do_bgr+0x60> */
/* @0x2afb6e pop {r4, pc} */
/* @0x2afb70 cmp r3, #0x6 */
/* @0x2afb72 bne 0x2afb9c <png_do_bgr+0xb4> */
/* @0x2afb74 movs r3, #0x0 */
/* @0x2afb76 cmp r3, r2 */
/* @0x2afb78 beq 0x2afb9c <png_do_bgr+0xb4> */
/* @0x2afb7a ldrb r0, [r1] */
/* @0x2afb7c adds r3, #0x1 */
/* @0x2afb7e ldrb r4, [r1, #0x4] */
/* @0x2afb80 adds r1, #0x8 */
/* @0x2afb82 strb r0, [r1, #-4] */
/* @0x2afb84 .word 0xf8010c04 */
/* @0x2afb86 strb r4, [r1, #-8] */
/* @0x2afb88 .word 0xf8114c08 */
/* @0x2afb8a ldrb r0, [r1, #-7] */
/* @0x2afb8c .word 0xf8110c07 */
/* @0x2afb8e ldrb r4, [r1, #-3] */
/* @0x2afb90 .word 0xf8014c03 */
/* @0x2afb92 strb r0, [r1, #-3] */
/* @0x2afb94 .word 0xf8010c03 */
/* @0x2afb96 strb r4, [r1, #-7] */
/* @0x2afb98 strb r4, [r12, r7, lsl #24]! */
/* @0x2afb9a b 0x2afb76 <png_do_bgr+0x8e> */
/* @0x2afb9c pop {r4, pc} */

/* ── FUNC 0x2afb9e · png_set_user_transform_info · size=16 · insn=8 */
/* @0x2afb9e cbz r0, 0x2afbac <png_set_user_transform_info+0xe> */
/* @0x2afba0 str.w r1, [r0, #0x124] */
/* @0x2afba2 .word 0xf8801124 */
/* @0x2afba4 strb.w r2, [r0, #0x128] */
/* @0x2afba6 .word 0xf8802128 */
/* @0x2afba8 strb.w r3, [r0, #0x129] */
/* @0x2afbaa ldrbmi r3, [r0, -r9, lsr #2]! */
/* @0x2afbac bx lr */

/* ── FUNC 0x2afbae · png_get_user_transform_ptr · size=8 · insn=4 */
/* @0x2afbae cbz r0, 0x2afbb4 <png_get_user_transform_ptr+0x6> */
/* @0x2afbb0 ldr.w r0, [r0, #0x124] */
/* @0x2afbb2 ldrbmi r0, [r0, -r4, lsr #2]! */
/* @0x2afbb4 bx lr */

/* ── FUNC 0x2afbb6 · anon_2afbb6 · size=0 · insn=1 */
/* @0x2afbb6 ldrlt r0, [r8, #-0x0]! */

/* ── FUNC 0x2afbb8 · png_default_write_data · size=44 · insn=20 */
/* @0x2afbb8 push {r3, r4, r5, lr} */
/* @0x2afbba mov r5, r2 */
/* @0x2afbbc mov r4, r0 */
/* @0x2afbbe cbz r0, 0x2afbde <png_default_write_data+0x26> */
/* @0x2afbc0 mov r0, r1 */
/* @0x2afbc2 ldr.w r3, [r4, #0x118] */
/* @0x2afbc4 .word 0x21013118 */
/* @0x2afbc6 movs r1, #0x1 */
/* @0x2afbc8 blx 0xb68bc <fwrite@plt> */
/* @0x2afbcc cmp r0, r5 */
/* @0x2afbce beq 0x2afbde <png_default_write_data+0x26> */
/* @0x2afbd0 ldr r1, [pc, #0xc] */
/* @0x2afbd2 mov r0, r4 */
/* @0x2afbd4 pop.w {r3, r4, r5, lr} */
/* @0x2afbd8 add r1, pc */
/* @0x2afbda b.w 0x2a642c <png_error> */
/* @0x2afbdc ldclt p12, c11, [r8, #-156]! */
/* @0x2afbde pop {r3, r4, r5, pc} */
/* @0x2afbe0 b 0x2b00cc <png_write_end+0xa0> */
/* @0x2afbe2 movs r5, r1 */

/* ── FUNC 0x2afbe4 · png_default_flush · size=12 · insn=6 */
/* @0x2afbe4 cbz r0, 0x2afbee <png_default_flush+0xa> */
/* @0x2afbe6 ldr.w r0, [r0, #0x118] */
/* @0x2afbe8 .word 0xf06b0118 */
/* @0x2afbea b.w 0x31bb1c <__udivdi3+0x484> */
/* @0x2afbec .word 0x4770bf97 */
/* @0x2afbee bx lr */

/* ── FUNC 0x2afbf0 · png_write_data · size=28 · insn=13 */
/* @0x2afbf0 push {r3, lr} */
/* @0x2afbf2 ldr.w r3, [r0, #0x110] */
/* @0x2afbf4 .word 0xb10b3110 */
/* @0x2afbf6 cbz r3, 0x2afbfc <png_write_data+0xc> */
/* @0x2afbf8 blx r3 */
/* @0x2afbfa pop {r3, pc} */
/* @0x2afbfc ldr r1, [pc, #0x8] */
/* @0x2afbfe pop.w {r3, lr} */
/* @0x2afc00 ldrbtmi r4, [r9], #-8 */
/* @0x2afc02 add r1, pc */
/* @0x2afc04 b.w 0x2a642c <png_error> */
/* @0x2afc08 b 0x2b00b8 <png_write_end+0x8c> */
/* @0x2afc0a movs r5, r1 */

/* ── FUNC 0x2afc0c · png_flush · size=12 · insn=6 */
/* @0x2afc0c push {r3, lr} */
/* @0x2afc0e ldr.w r3, [r0, #0x210] */
/* @0x2afc10 .word 0xb1033210 */
/* @0x2afc12 cbz r3, 0x2afc16 <png_flush+0xa> */
/* @0x2afc14 blx r3 */
/* @0x2afc16 pop {r3, pc} */

/* ── FUNC 0x2afc18 · png_set_write_fn · size=88 · insn=43 */
/* @0x2afc18 push {r4, lr} */
/* @0x2afc1a mov r4, r0 */
/* @0x2afc1c cbz r0, 0x2afc5e <png_set_write_fn+0x46> */
/* @0x2afc1e str.w r1, [r0, #0x118] */
/* @0x2afc20 ldmdblt r2, {r3, r4, r8, r12} */
/* @0x2afc22 cbnz r2, 0x2afc2a <png_set_write_fn+0x12> */
/* @0x2afc24 ldr r2, [pc, #0x38] */
/* @0x2afc26 add r2, pc */
/* @0x2afc28 ldr r2, [r2] */
/* @0x2afc2a str.w r2, [r4, #0x110] */
/* @0x2afc2c ldmdblt r3, {r4, r8, sp} */
/* @0x2afc2e cbnz r3, 0x2afc36 <png_set_write_fn+0x1e> */
/* @0x2afc30 ldr r3, [pc, #0x30] */
/* @0x2afc32 add r3, pc */
/* @0x2afc34 ldr r3, [r3] */
/* @0x2afc36 str.w r3, [r4, #0x210] */
/* @0x2afc38 .word 0xf8d43210 */
/* @0x2afc3a ldr.w r3, [r4, #0x114] */
/* @0x2afc3c cmnlt r3, r4, lsl r1 */
/* @0x2afc3e cbz r3, 0x2afc5e <png_set_write_fn+0x46> */
/* @0x2afc40 ldr r1, [pc, #0x24] */
/* @0x2afc42 mov r0, r4 */
/* @0x2afc44 movs r3, #0x0 */
/* @0x2afc46 str.w r3, [r4, #0x114] */
/* @0x2afc48 ldrbtmi r3, [r9], #-276 */
/* @0x2afc4a add r1, pc */
/* @0x2afc4c bl 0x2a6474 <png_warning> */
/* @0x2afc50 ldr r1, [pc, #0x18] */
/* @0x2afc52 mov r0, r4 */
/* @0x2afc54 add r1, pc */
/* @0x2afc56 pop.w {r4, lr} */
/* @0x2afc58 .word 0xf7f64010 */
/* @0x2afc5a b.w 0x2a6474 <png_warning> */
/* @0x2afc5c ldclt p12, c11, [r0, #-44] */
/* @0x2afc5e pop {r4, pc} */
/* @0x2afc60 subs r6, r7, #0x1 */
/* @0x2afc62 movs r4, r2 */
/* @0x2afc64 subs r6, r6, #0x1 */
/* @0x2afc66 movs r4, r2 */
/* @0x2afc68 b 0x2b00c0 <png_write_end+0x94> */
/* @0x2afc6a movs r5, r1 */
/* @0x2afc6c b 0x2b0120 <png_write_end+0xf4> */
/* @0x2afc6e movs r5, r1 */

/* ── FUNC 0x2afc70 · png_write_info_before_PLTE · size=420 · insn=172 */
/* @0x2afc70 push.w {r4, r5, r6, r7, r8, lr} */
/* @0x2afc74 mov r4, r1 */
/* @0x2afc76 sub sp, #0x38 */
/* @0x2afc78 mov r5, r0 */
/* @0x2afc7a cmp r0, #0x0 */
/* @0x2afc7c beq.w 0x2afe04 <png_write_info_before_PLTE+0x194> */
/* @0x2afc80 cmp r1, #0x0 */
/* @0x2afc82 beq.w 0x2afe04 <png_write_info_before_PLTE+0x194> */
/* @0x2afc84 .word 0xf8d080bf */
/* @0x2afc86 ldr.w r3, [r0, #0x12c] */
/* @0x2afc88 .word 0xf413312c */
/* @0x2afc8a ands r6, r3, #0x400 */
/* @0x2afc8c .word 0xf0406680 */
/* @0x2afc8e bne.w 0x2afe04 <png_write_info_before_PLTE+0x194> */
/* @0x2afc90 .word 0xf00180b9 */
/* @0x2afc92 bl 0x2b1140 <png_write_sig> */
/* @0x2afc94 .word 0xf8d5fa55 */
/* @0x2afc96 ldr.w r3, [r5, #0x12c] */
/* @0x2afc98 ldrbeq r3, [r10], #300 */
/* @0x2afc9a lsls r2, r3, #0x13 */
/* @0x2afc9c bpl 0x2afcb2 <png_write_info_before_PLTE+0x42> */
/* @0x2afc9e ldr.w r3, [r5, #0x2dc] */
/* @0x2afca0 ldrsblt r3, [r3, -r12]! */
/* @0x2afca2 cbz r3, 0x2afcb2 <png_write_info_before_PLTE+0x42> */
/* @0x2afca4 ldr r1, [pc, #0x164] */
/* @0x2afca6 mov r0, r5 */
/* @0x2afca8 add r1, pc */
/* @0x2afcaa bl 0x2a6474 <png_warning> */
/* @0x2afcac .word 0xf8c5fbe3 */
/* @0x2afcae str.w r6, [r5, #0x2dc] */
/* @0x2afcb0 mcrvc p2, #0x3, r6, c2, c12, #0x6 */
/* @0x2afcb2 ldrb r2, [r4, #0x19] */
/* @0x2afcb4 mov r0, r5 */
/* @0x2afcb6 ldrb r3, [r4, #0x18] */
/* @0x2afcb8 str r2, [sp] */
/* @0x2afcba ldrb r2, [r4, #0x1a] */
/* @0x2afcbc str r2, [sp, #0x4] */
/* @0x2afcbe ldrb r2, [r4, #0x1b] */
/* @0x2afcc0 str r2, [sp, #0x8] */
/* @0x2afcc2 ldrb r2, [r4, #0x1c] */
/* @0x2afcc4 str r2, [sp, #0xc] */
/* @0x2afcc6 ldm.w r4, {r1, r2} */
/* @0x2afcc8 .word 0xf0010006 */
/* @0x2afcca bl 0x2b12e4 <png_write_IHDR> */
/* @0x2afccc stmvs r3!, {r0, r1, r3, r8, r9, r11, r12, sp, lr, pc} */
/* @0x2afcce ldr r3, [r4, #0x8] */
/* @0x2afcd0 lsls r3, r3, #0x1f */
/* @0x2afcd2 bpl 0x2afce6 <png_write_info_before_PLTE+0x76> */
/* @0x2afcd4 vldr s15, [r4, #40] */
/* @0x2afcd8 vcvt.f64.f32 d6, s15 */
/* @0x2afcdc mov r0, r5 */
/* @0x2afcde vmov r2, r3, d6 */
/* @0x2afce0 .word 0xf0012b16 */
/* @0x2afce2 bl 0x2b17c0 <png_write_gAMA> */
/* @0x2afce4 stmvs r3!, {r0, r2, r3, r5, r6, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2afce6 ldr r3, [r4, #0x8] */
/* @0x2afce8 lsls r7, r3, #0x14 */
/* @0x2afcea bpl 0x2afcf6 <png_write_info_before_PLTE+0x86> */
/* @0x2afcec mov r0, r5 */
/* @0x2afcee ldrb.w r1, [r4, #0x2c] */
/* @0x2afcf0 .word 0xf001102c */
/* @0x2afcf2 bl 0x2b184c <png_write_sRGB> */
/* @0x2afcf4 stmvs r3!, {r0, r1, r3, r5, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2afcf6 ldr r3, [r4, #0x8] */
/* @0x2afcf8 lsls r6, r3, #0x13 */
/* @0x2afcfa bpl 0x2afd12 <png_write_info_before_PLTE+0xa2> */
/* @0x2afcfc ldr.w r3, [r4, #0xcc] */
/* @0x2afd00 mov r0, r5 */
/* @0x2afd02 ldr.w r1, [r4, #0xc4] */
/* @0x2afd04 andhs r1, r0, #196 */
/* @0x2afd06 movs r2, #0x0 */
/* @0x2afd08 str r3, [sp] */
/* @0x2afd0a ldr.w r3, [r4, #0xc8] */
/* @0x2afd0c .word 0xf00130c8 */
/* @0x2afd0e bl 0x2b1890 <png_write_iCCP> */
/* @0x2afd10 stmvs r3!, {r0, r1, r2, r3, r4, r5, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2afd12 ldr r3, [r4, #0x8] */
/* @0x2afd14 lsls r0, r3, #0x1e */
/* @0x2afd16 bpl 0x2afd24 <png_write_info_before_PLTE+0xb4> */
/* @0x2afd18 mov r0, r5 */
/* @0x2afd1a add.w r1, r4, #0x44 */
/* @0x2afd1c cdpvc p1, #0x6, c0, c2, c4, #0x2 */
/* @0x2afd1e ldrb r2, [r4, #0x19] */
/* @0x2afd20 bl 0x2b1aac <png_write_sBIT> */
/* @0x2afd24 ldr r3, [r4, #0x8] */
/* @0x2afd26 lsls r1, r3, #0x1d */
/* @0x2afd28 bpl 0x2afd90 <png_write_info_before_PLTE+0x120> */
/* @0x2afd2a vldr s14, [r4, #132] */
/* @0x2afd2c .word 0xeeb77a21 */
/* @0x2afd2e vcvt.f64.f32 d7, s14 */
/* @0x2afd30 vldr s15, [r4, #796] */
/* @0x2afd32 vldr s13, [r4, #128] */
/* @0x2afd34 strtmi r6, [r8], -r0, lsr #20 */
/* @0x2afd36 mov r0, r5 */
/* @0x2afd38 vstr d7, [sp] */
/* @0x2afd3c vldr s14, [r4, #136] */
/* @0x2afd40 vcvt.f64.f32 d7, s14 */
/* @0x2afd44 vstr d7, [sp, #8] */
/* @0x2afd48 vldr s14, [r4, #140] */
/* @0x2afd4c vcvt.f64.f32 d7, s14 */
/* @0x2afd50 vstr d7, [sp, #16] */
/* @0x2afd54 vldr s14, [r4, #144] */
/* @0x2afd58 vcvt.f64.f32 d7, s14 */
/* @0x2afd5c vstr d7, [sp, #24] */
/* @0x2afd60 vldr s14, [r4, #148] */
/* @0x2afd64 vcvt.f64.f32 d7, s14 */
/* @0x2afd68 vstr d7, [sp, #32] */
/* @0x2afd6c vldr s14, [r4, #152] */
/* @0x2afd70 vcvt.f64.f32 d7, s14 */
/* @0x2afd74 vstr d7, [sp, #40] */
/* @0x2afd78 vldr s14, [r4, #156] */
/* @0x2afd7c vcvt.f64.f32 d7, s14 */
/* @0x2afd80 vstr d7, [sp, #48] */
/* @0x2afd84 vcvt.f64.f32 d7, s13 */
/* @0x2afd88 vmov r2, r3, d7 */
/* @0x2afd8c bl 0x2b1b50 <png_write_cHRM> */
/* @0x2afd90 ldr.w r3, [r4, #0xc0] */
/* @0x2afd94 cbnz r3, 0x2afda4 <png_write_info_before_PLTE+0x134> */
/* @0x2afd96 ldr.w r3, [r5, #0x12c] */
/* @0x2afd98 vst4.8 {d19, d21, d23, d25}, [r3:128], r12 */
/* @0x2afd9a orr r3, r3, #0x400 */
/* @0x2afd9c .word 0xf8c56380 */
/* @0x2afd9e str.w r3, [r5, #0x12c] */
/* @0x2afda0 eor r3, pc, r12, lsr #2 */
/* @0x2afda2 b 0x2afe04 <png_write_info_before_PLTE+0x194> */
/* @0x2afda4 ldr.w r8, [pc, #0x68] */
/* @0x2afda8 movs r7, #0x14 */
/* @0x2afdaa ldr.w r6, [r4, #0xbc] */
/* @0x2afdac ldrbtmi r6, [r8], #188 */
/* @0x2afdae add r8, pc */
/* @0x2afdb0 ldr.w r2, [r4, #0xc0] */
/* @0x2afdb4 ldr.w r3, [r4, #0xbc] */
/* @0x2afdb8 mla r3, r7, r2, r3 */
/* @0x2afdbc cmp r6, r3 */
/* @0x2afdbe bhs 0x2afd96 <png_write_info_before_PLTE+0x126> */
/* @0x2afdc0 mov r0, r5 */
/* @0x2afdc2 mov r1, r6 */
/* @0x2afdc4 bl 0x2a5fe4 <png_handle_as_unknown> */
/* @0x2afdc8 cmp r0, #0x1 */
/* @0x2afdca beq 0x2afe00 <png_write_info_before_PLTE+0x190> */
/* @0x2afdcc ldrb r3, [r6, #0x10] */
/* @0x2afdce cbz r3, 0x2afe00 <png_write_info_before_PLTE+0x190> */
/* @0x2afdd0 tst.w r3, #0x6 */
/* @0x2afdd4 bne 0x2afe00 <png_write_info_before_PLTE+0x190> */
/* @0x2afdd6 ldrb r3, [r6, #0x3] */
/* @0x2afdd8 lsls r2, r3, #0x1a */
/* @0x2afdda bmi 0x2afde8 <png_write_info_before_PLTE+0x178> */
/* @0x2afddc cmp r0, #0x3 */
/* @0x2afdde beq 0x2afde8 <png_write_info_before_PLTE+0x178> */
/* @0x2afde0 ldr.w r3, [r5, #0x130] */
/* @0x2afde4 lsls r3, r3, #0xf */
/* @0x2afde6 bpl 0x2afe00 <png_write_info_before_PLTE+0x190> */
/* @0x2afde8 ldr r3, [r6, #0xc] */
/* @0x2afdea cbnz r3, 0x2afdf4 <png_write_info_before_PLTE+0x184> */
/* @0x2afdec mov r0, r5 */
/* @0x2afdee mov r1, r8 */
/* @0x2afdf0 bl 0x2a6474 <png_warning> */
/* @0x2afdf4 mov r0, r5 */
/* @0x2afdf6 mov r1, r6 */
/* @0x2afdf8 ldr r2, [r6, #0x8] */
/* @0x2afdfa ldr r3, [r6, #0xc] */
/* @0x2afdfc bl 0x2b12bc <png_write_chunk> */
/* @0x2afe00 adds r6, #0x14 */
/* @0x2afe02 b 0x2afdb0 <png_write_info_before_PLTE+0x140> */
/* @0x2afe04 add sp, #0x38 */
/* @0x2afe06 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2afe08 svclt #0x81f0 */
/* @0x2afe0a nop */
/* @0x2afe0c ldm r1, {r1, r5, r7} */
/* @0x2afe0e movs r5, r1 */
/* @0x2afe10 b 0x2b0078 <png_write_end+0x4c> */
/* @0x2afe12 movs r5, r1 */

/* ── FUNC 0x2afe14 · png_write_info · size=536 · insn=233 */
/* @0x2afe14 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2afe18 mov r6, r1 */
/* @0x2afe1a sub sp, #0x14 */
/* @0x2afe1c mov r7, r0 */
/* @0x2afe1e cmp r0, #0x0 */
/* @0x2afe20 beq.w 0x2b0022 <png_write_info+0x20e> */
/* @0x2afe24 cmp r1, #0x0 */
/* @0x2afe26 beq.w 0x2b0022 <png_write_info+0x20e> */
/* @0x2afe28 .word 0xf7ff80fc */
/* @0x2afe2a bl 0x2afc70 <png_write_info_before_PLTE> */
/* @0x2afe2c ldmvs r3!, {r0, r5, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2afe2e ldr r3, [r6, #0x8] */
/* @0x2afe30 lsls r2, r3, #0x1c */
/* @0x2afe32 bpl 0x2afe40 <png_write_info+0x2c> */
/* @0x2afe34 mov r0, r7 */
/* @0x2afe36 ldr r1, [r6, #0x10] */
/* @0x2afe38 ldrh r2, [r6, #0x14] */
/* @0x2afe3a bl 0x2b15d0 <png_write_PLTE> */
/* @0x2afe3c and pc, r7, r9, asr #23 */
/* @0x2afe3e b 0x2afe50 <png_write_info+0x3c> */
/* @0x2afe40 ldrb r3, [r6, #0x19] */
/* @0x2afe42 cmp r3, #0x3 */
/* @0x2afe44 bne 0x2afe50 <png_write_info+0x3c> */
/* @0x2afe46 ldr r1, [pc, #0x1e0] */
/* @0x2afe48 mov r0, r7 */
/* @0x2afe4a add r1, pc */
/* @0x2afe4c bl 0x2a642c <png_error> */
/* @0x2afe50 ldr r3, [r6, #0x8] */
/* @0x2afe52 lsls r3, r3, #0x1b */
/* @0x2afe54 bpl 0x2afe8c <png_write_info+0x78> */
/* @0x2afe56 ldr.w r3, [r7, #0x134] */
/* @0x2afe58 tsteq sp, #52, #2 */
/* @0x2afe5a lsls r5, r3, #0xc */
/* @0x2afe5c bmi 0x2afe72 <png_write_info+0x5e> */
/* @0x2afe5e ldrb r2, [r6, #0x19] */
/* @0x2afe60 mov r0, r7 */
/* @0x2afe62 ldrh r3, [r6, #0x16] */
/* @0x2afe64 ldr r1, [r6, #0x4c] */
/* @0x2afe66 str r2, [sp] */
/* @0x2afe68 add.w r2, r6, #0x50 */
/* @0x2afe6c bl 0x2b1d80 <png_write_tRNS> */
/* @0x2afe70 b 0x2afe8c <png_write_info+0x78> */
/* @0x2afe72 ldrb r3, [r6, #0x19] */
/* @0x2afe74 cmp r3, #0x3 */
/* @0x2afe76 bne 0x2afe5e <png_write_info+0x4a> */
/* @0x2afe78 movs r3, #0x0 */
/* @0x2afe7a ldrh r2, [r6, #0x16] */
/* @0x2afe7c cmp r3, r2 */
/* @0x2afe7e bge 0x2afe5e <png_write_info+0x4a> */
/* @0x2afe80 ldr r2, [r6, #0x4c] */
/* @0x2afe82 ldrb r1, [r2, r3] */
/* @0x2afe84 mvns r1, r1 */
/* @0x2afe86 strb r1, [r2, r3] */
/* @0x2afe88 adds r3, #0x1 */
/* @0x2afe8a b 0x2afe7a <png_write_info+0x66> */
/* @0x2afe8c ldr r3, [r6, #0x8] */
/* @0x2afe8e lsls r4, r3, #0x1a */
/* @0x2afe90 bpl 0x2afe9e <png_write_info+0x8a> */
/* @0x2afe92 mov r0, r7 */
/* @0x2afe94 add.w r1, r6, #0x5a */
/* @0x2afe98 ldrb r2, [r6, #0x19] */
/* @0x2afe9a bl 0x2b1e54 <png_write_bKGD> */
/* @0x2afe9c ldmvs r3!, {r0, r1, r3, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2afe9e ldr r3, [r6, #0x8] */
/* @0x2afea0 lsls r0, r3, #0x19 */
/* @0x2afea2 bpl 0x2afeae <png_write_info+0x9a> */
/* @0x2afea4 mov r0, r7 */
/* @0x2afea6 ldr r1, [r6, #0x7c] */
/* @0x2afea8 ldrh r2, [r6, #0x14] */
/* @0x2afeaa bl 0x2b1f28 <png_write_hIST> */
/* @0x2afeac ldmvs r3!, {r0, r2, r3, r4, r5, r11, r12, sp, lr, pc} */
/* @0x2afeae ldr r3, [r6, #0x8] */
/* @0x2afeb0 lsls r1, r3, #0x17 */
/* @0x2afeb2 bpl 0x2afec2 <png_write_info+0xae> */
/* @0x2afeb4 mov r0, r7 */
/* @0x2afeb6 ldr r1, [r6, #0x64] */
/* @0x2afeb8 ldr r2, [r6, #0x68] */
/* @0x2afeba ldrb.w r3, [r6, #0x6c] */
/* @0x2afebc .word 0xf002306c */
/* @0x2afebe bl 0x2b21d8 <png_write_oFFs> */
/* @0x2afec0 ldmvs r3!, {r0, r1, r3, r7, r8, r11, r12, sp, lr, pc} */
/* @0x2afec2 ldr r3, [r6, #0x8] */
/* @0x2afec4 lsls r2, r3, #0x15 */
/* @0x2afec6 bpl 0x2afeec <png_write_info+0xd8> */
/* @0x2afec8 ldrb.w r3, [r6, #0xb4] */
/* @0x2afecc add.w r1, r6, #0xa0 */
/* @0x2afed0 mov r0, r7 */
/* @0x2afed2 str r3, [sp] */
/* @0x2afed4 ldrb.w r3, [r6, #0xb5] */
/* @0x2afed8 str r3, [sp, #0x4] */
/* @0x2afeda ldr.w r3, [r6, #0xac] */
/* @0x2afedc movwls r3, #0x20ac */
/* @0x2afede str r3, [sp, #0x8] */
/* @0x2afee0 ldr.w r3, [r6, #0xb0] */
/* @0x2afee4 str r3, [sp, #0xc] */
/* @0x2afee6 ldm r1, {r1, r2, r3} */
/* @0x2afee8 bl 0x2b2250 <png_write_pCAL> */
/* @0x2afeec ldr r3, [r6, #0x8] */
/* @0x2afeee lsls r3, r3, #0x11 */
/* @0x2afef0 bpl 0x2aff08 <png_write_info+0xf4> */
/* @0x2afef2 ldrd r4, r5, [r6, #232] */
/* @0x2afef4 shasxmi r4, r8, r10 */
/* @0x2afef6 mov r0, r7 */
/* @0x2afef8 ldrb.w r1, [r6, #0xdc] */
/* @0x2afefc ldrd r2, r3, [r6, #224] */
/* @0x2aff00 strd r4, r5, [sp] */
/* @0x2aff04 bl 0x2b2384 <png_write_sCAL> */
/* @0x2aff08 ldr r3, [r6, #0x8] */
/* @0x2aff0a lsls r5, r3, #0x18 */
/* @0x2aff0c bpl 0x2aff1c <png_write_info+0x108> */
/* @0x2aff0e mov r0, r7 */
/* @0x2aff10 ldr r1, [r6, #0x70] */
/* @0x2aff12 ldr r2, [r6, #0x74] */
/* @0x2aff14 ldrb.w r3, [r6, #0x78] */
/* @0x2aff18 bl 0x2b2418 <png_write_pHYs> */
/* @0x2aff1c ldr r3, [r6, #0x8] */
/* @0x2aff1e lsls r4, r3, #0x16 */
/* @0x2aff20 bpl 0x2aff38 <png_write_info+0x124> */
/* @0x2aff22 mov r0, r7 */
/* @0x2aff24 add.w r1, r6, #0x3c */
/* @0x2aff28 bl 0x2b2490 <png_write_tIME> */
/* @0x2aff2c ldr.w r3, [r7, #0x12c] */
/* @0x2aff30 orr r3, r3, #0x200 */
/* @0x2aff34 str.w r3, [r7, #0x12c] */
/* @0x2aff38 ldr r3, [r6, #0x8] */
/* @0x2aff3a lsls r0, r3, #0x12 */
/* @0x2aff3c bpl 0x2aff42 <png_write_info+0x12e> */
/* @0x2aff3e movs r4, #0x0 */
/* @0x2aff40 b 0x2aff54 <png_write_info+0x140> */
/* @0x2aff42 mov.w r8, #0x0 */
/* @0x2aff44 .word 0xf04f0800 */
/* @0x2aff46 mov.w r10, #0x1c */
/* @0x2aff48 .word 0xf06f0a1c */
/* @0x2aff4a mvn r9, #0x2 */
/* @0x2aff4c .word 0xf06f0902 */
/* @0x2aff4e mvn r11, #0x1 */
/* @0x2aff50 ands r0, r8, r1, lsl #22 */
/* @0x2aff52 b 0x2aff86 <png_write_info+0x172> */
/* @0x2aff54 ldr.w r3, [r6, #0xd8] */
/* @0x2aff58 cmp r4, r3 */
/* @0x2aff5a bge 0x2aff42 <png_write_info+0x12e> */
/* @0x2aff5c ldr.w r1, [r6, #0xd4] */
/* @0x2aff60 mov r0, r7 */
/* @0x2aff62 add.w r1, r1, r4, lsl #4 */
/* @0x2aff64 strlo r1, [r1], #-260 */
/* @0x2aff66 adds r4, #0x1 */
/* @0x2aff68 bl 0x2b198c <png_write_sPLT> */
/* @0x2aff6c b 0x2aff54 <png_write_info+0x140> */
/* @0x2aff6e bne 0x2affb0 <png_write_info+0x19c> */
/* @0x2aff70 str r3, [sp] */
/* @0x2aff72 mov r0, r7 */
/* @0x2aff74 ldr r1, [r4, #0x4] */
/* @0x2aff76 ldr r2, [r4, #0x8] */
/* @0x2aff78 bl 0x2b2004 <png_write_zTXt> */
/* @0x2aff7c ldr r3, [r6, #0x38] */
/* @0x2aff7e str.w r11, [r3, r5] */
/* @0x2aff80 .word 0xf108b005 */
/* @0x2aff82 add.w r8, r8, #0x1 */
/* @0x2aff84 blvs 0xf71f90 <b2_toiTime+0x818aec> */
/* @0x2aff86 ldr r3, [r6, #0x30] */
/* @0x2aff88 cmp r8, r3 */
/* @0x2aff8a bge 0x2affc8 <png_write_info+0x1b4> */
/* @0x2aff8c mul r5, r10, r8 */
/* @0x2aff90 ldr r3, [r6, #0x38] */
/* @0x2aff92 adds r4, r3, r5 */
/* @0x2aff94 ldr r3, [r3, r5] */
/* @0x2aff96 cmp r3, #0x0 */
/* @0x2aff98 ble 0x2aff6e <png_write_info+0x15a> */
/* @0x2aff9a ldr r2, [r4, #0x18] */
/* @0x2aff9c mov r1, r3 */
/* @0x2aff9e mov r0, r7 */
/* @0x2affa0 str r2, [sp] */
/* @0x2affa2 ldr r2, [r4, #0x8] */
/* @0x2affa4 str r2, [sp, #0x4] */
/* @0x2affa6 ldr r2, [r4, #0x4] */
/* @0x2affa8 ldr r3, [r4, #0x14] */
/* @0x2affaa bl 0x2b20b8 <png_write_iTXt> */
/* @0x2affac and pc, r7, r5, lsl #17 */
/* @0x2affae b 0x2affc0 <png_write_info+0x1ac> */
/* @0x2affb0 adds r3, #0x1 */
/* @0x2affb2 bne 0x2aff82 <png_write_info+0x16e> */
/* @0x2affb4 mov r0, r7 */
/* @0x2affb6 ldr r1, [r4, #0x4] */
/* @0x2affb8 ldr r2, [r4, #0x8] */
/* @0x2affba movs r3, #0x0 */
/* @0x2affbc bl 0x2b1f94 <png_write_tEXt> */
/* @0x2affc0 ldr r3, [r6, #0x38] */
/* @0x2affc2 str.w r9, [r3, r5] */
/* @0x2affc4 ldrb r9, [r12, r5] */
/* @0x2affc6 b 0x2aff82 <png_write_info+0x16e> */
/* @0x2affc8 ldr.w r3, [r6, #0xc0] */
/* @0x2affcc cbz r3, 0x2b0022 <png_write_info+0x20e> */
/* @0x2affce ldr.w r4, [r6, #0xbc] */
/* @0x2affd0 ldrhs r4, [r4, #-0xbc] */
/* @0x2affd2 movs r5, #0x14 */
/* @0x2affd4 ldr.w r2, [r6, #0xc0] */
/* @0x2affd8 ldr.w r3, [r6, #0xbc] */
/* @0x2affdc mla r3, r5, r2, r3 */
/* @0x2affe0 cmp r4, r3 */
/* @0x2affe2 bhs 0x2b0022 <png_write_info+0x20e> */
/* @0x2affe4 mov r0, r7 */
/* @0x2affe6 mov r1, r4 */
/* @0x2affe8 bl 0x2a5fe4 <png_handle_as_unknown> */
/* @0x2affec cmp r0, #0x1 */
/* @0x2affee beq 0x2b001e <png_write_info+0x20a> */
/* @0x2afff0 ldrb r3, [r4, #0x10] */
/* @0x2afff2 cbz r3, 0x2b001e <png_write_info+0x20a> */
/* @0x2afff4 and r2, r3, #0x6 */
/* @0x2afff8 cmp r2, #0x2 */
/* @0x2afffa bne 0x2b001e <png_write_info+0x20a> */
/* @0x2afffc lsls r1, r3, #0x1c */
/* @0x2afffe bmi 0x2b001e <png_write_info+0x20a> */
/* @0x2b0000 ldrb r3, [r4, #0x3] */
/* @0x2b0002 lsls r2, r3, #0x1a */
/* @0x2b0004 bmi 0x2b0012 <png_write_info+0x1fe> */
/* @0x2b0006 cmp r0, #0x3 */
/* @0x2b0008 beq 0x2b0012 <png_write_info+0x1fe> */
/* @0x2b000a ldr.w r3, [r7, #0x130] */
/* @0x2b000c bicseq r3, r11, #48, #2 */
/* @0x2b000e lsls r3, r3, #0xf */
/* @0x2b0010 bpl 0x2b001e <png_write_info+0x20a> */
/* @0x2b0012 mov r0, r7 */
/* @0x2b0014 mov r1, r4 */
/* @0x2b0016 ldr r2, [r4, #0x8] */
/* @0x2b0018 ldr r3, [r4, #0xc] */
/* @0x2b001a bl 0x2b12bc <png_write_chunk> */
/* @0x2b001c ldrlo pc, [r4], #-2383 */
/* @0x2b001e adds r4, #0x14 */
/* @0x2b0020 b 0x2affd4 <png_write_info+0x1c0> */
/* @0x2b0022 add sp, #0x14 */
/* @0x2b0024 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b0028 b 0x2b019c <png_create_write_struct_2+0x18> */
/* @0x2b002a movs r5, r1 */

/* ── FUNC 0x2b002c · png_write_end · size=284 · insn=125 */
/* @0x2b002c push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b0030 mov r5, r1 */
/* @0x2b0032 mov r4, r0 */
/* @0x2b0034 cmp r0, #0x0 */
/* @0x2b0036 beq.w 0x2b013c <png_write_end+0x110> */
/* @0x2b0038 .word 0xf8d08081 */
/* @0x2b003a ldr.w r3, [r0, #0x12c] */
/* @0x2b003c ldrbeq r3, [pc, -r12, lsr #2] */
/* @0x2b003e lsls r7, r3, #0x1d */
/* @0x2b0040 bmi 0x2b004a <png_write_end+0x1e> */
/* @0x2b0042 ldr r1, [pc, #0x100] */
/* @0x2b0044 add r1, pc */
/* @0x2b0046 bl 0x2a642c <png_error> */
/* @0x2b0048 ldmdblt sp, {r0, r4, r5, r6, r7, r8, r11, r12, sp, lr, pc} ^ */
/* @0x2b004a cbnz r5, 0x2b0064 <png_write_end+0x38> */
/* @0x2b004c ldr.w r3, [r4, #0x12c] */
/* @0x2b0050 mov r0, r4 */
/* @0x2b0052 orr r3, r3, #0x8 */
/* @0x2b0054 .word 0xf8c40308 */
/* @0x2b0056 str.w r3, [r4, #0x12c] */
/* @0x2b0058 andlt r3, r3, r12, lsr #2 */
/* @0x2b005a add sp, #0xc */
/* @0x2b005c pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b0060 b.w 0x2b178c <png_write_IEND> */
/* @0x2b0064 ldr r3, [r5, #0x8] */
/* @0x2b0066 lsls r6, r3, #0x16 */
/* @0x2b0068 bpl 0x2b007c <png_write_end+0x50> */
/* @0x2b006a ldr.w r3, [r4, #0x12c] */
/* @0x2b006c ldreq r3, [r8, #0x12c] */
/* @0x2b006e lsls r0, r3, #0x16 */
/* @0x2b0070 bmi 0x2b007c <png_write_end+0x50> */
/* @0x2b0072 mov r0, r4 */
/* @0x2b0074 add.w r1, r5, #0x3c */
/* @0x2b0078 bl 0x2b2490 <png_write_tIME> */
/* @0x2b007c mov.w r8, #0x0 */
/* @0x2b0080 mov.w r10, #0x1c */
/* @0x2b0084 mvn r9, #0x2 */
/* @0x2b0088 mvn r11, #0x1 */
/* @0x2b008c ldr r3, [r5, #0x30] */
/* @0x2b008e cmp r8, r3 */
/* @0x2b0090 bge 0x2b00e8 <png_write_end+0xbc> */
/* @0x2b0092 mul r7, r10, r8 */
/* @0x2b0094 blvs 0xfedadcbc <b2_toiTime+0xfffffffffe654818> */
/* @0x2b0096 ldr r3, [r5, #0x38] */
/* @0x2b0098 adds r6, r3, r7 */
/* @0x2b009a ldr r3, [r3, r7] */
/* @0x2b009c cmp r3, #0x0 */
/* @0x2b009e ble 0x2b00b6 <png_write_end+0x8a> */
/* @0x2b00a0 ldr r2, [r6, #0x18] */
/* @0x2b00a2 mov r1, r3 */
/* @0x2b00a4 mov r0, r4 */
/* @0x2b00a6 str r2, [sp] */
/* @0x2b00a8 ldr r2, [r6, #0x8] */
/* @0x2b00aa str r2, [sp, #0x4] */
/* @0x2b00ac ldr r2, [r6, #0x4] */
/* @0x2b00ae ldr r3, [r6, #0x14] */
/* @0x2b00b0 bl 0x2b20b8 <png_write_iTXt> */
/* @0x2b00b4 b 0x2b00dc <png_write_end+0xb0> */
/* @0x2b00b6 bne 0x2b00cc <png_write_end+0xa0> */
/* @0x2b00b8 str r3, [sp] */
/* @0x2b00ba mov r0, r4 */
/* @0x2b00bc ldr r1, [r6, #0x4] */
/* @0x2b00be ldr r2, [r6, #0x8] */
/* @0x2b00c0 bl 0x2b2004 <png_write_zTXt> */
/* @0x2b00c4 ldr r3, [r5, #0x38] */
/* @0x2b00c6 str.w r11, [r3, r7] */
/* @0x2b00c8 and r11, r10, r7 */
/* @0x2b00ca b 0x2b00e2 <png_write_end+0xb6> */
/* @0x2b00cc adds r3, #0x1 */
/* @0x2b00ce bne 0x2b00e2 <png_write_end+0xb6> */
/* @0x2b00d0 mov r0, r4 */
/* @0x2b00d2 ldr r1, [r6, #0x4] */
/* @0x2b00d4 ldr r2, [r6, #0x8] */
/* @0x2b00d6 movs r3, #0x0 */
/* @0x2b00d8 bl 0x2b1f94 <png_write_tEXt> */
/* @0x2b00dc ldr r3, [r5, #0x38] */
/* @0x2b00de str.w r9, [r3, r7] */
/* @0x2b00e0 .word 0xf1089007 */
/* @0x2b00e2 add.w r8, r8, #0x1 */
/* @0x2b00e4 ldrb r0, [r1, r1, lsl #16] */
/* @0x2b00e6 b 0x2b008c <png_write_end+0x60> */
/* @0x2b00e8 ldr.w r3, [r5, #0xc0] */
/* @0x2b00ec cmp r3, #0x0 */
/* @0x2b00ee beq 0x2b004c <png_write_end+0x20> */
/* @0x2b00f0 ldr.w r6, [r5, #0xbc] */
/* @0x2b00f4 movs r7, #0x14 */
/* @0x2b00f6 ldr.w r2, [r5, #0xc0] */
/* @0x2b00f8 .word 0xf8d520c0 */
/* @0x2b00fa ldr.w r3, [r5, #0xbc] */
/* @0x2b00fc blx 0x47c3f6 <targetStr+0x11b6> */
/* @0x2b00fe mla r3, r7, r2, r3 */
/* @0x2b0100 addsmi r3, lr, #134217728 */
/* @0x2b0102 cmp r6, r3 */
/* @0x2b0104 bhs 0x2b004c <png_write_end+0x20> */
/* @0x2b0106 mov r0, r4 */
/* @0x2b0108 mov r1, r6 */
/* @0x2b010a bl 0x2a5fe4 <png_handle_as_unknown> */
/* @0x2b010c stmdahs r1, {r0, r1, r3, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2b010e cmp r0, #0x1 */
/* @0x2b0110 beq 0x2b0138 <png_write_end+0x10c> */
/* @0x2b0112 ldrb r3, [r6, #0x10] */
/* @0x2b0114 cbz r3, 0x2b0138 <png_write_end+0x10c> */
/* @0x2b0116 lsls r1, r3, #0x1c */
/* @0x2b0118 bpl 0x2b0138 <png_write_end+0x10c> */
/* @0x2b011a ldrb r3, [r6, #0x3] */
/* @0x2b011c lsls r2, r3, #0x1a */
/* @0x2b011e bmi 0x2b012c <png_write_end+0x100> */
/* @0x2b0120 cmp r0, #0x3 */
/* @0x2b0122 beq 0x2b012c <png_write_end+0x100> */
/* @0x2b0124 ldr.w r3, [r4, #0x130] */
/* @0x2b0128 lsls r3, r3, #0xf */
/* @0x2b012a bpl 0x2b0138 <png_write_end+0x10c> */
/* @0x2b012c mov r0, r4 */
/* @0x2b012e mov r1, r6 */
/* @0x2b0130 ldr r2, [r6, #0x8] */
/* @0x2b0132 ldr r3, [r6, #0xc] */
/* @0x2b0134 bl 0x2b12bc <png_write_chunk> */
/* @0x2b0138 adds r6, #0x14 */
/* @0x2b013a b 0x2b00f6 <png_write_end+0xca> */
/* @0x2b013c add sp, #0xc */
/* @0x2b013e pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b0140 svclt #0x8ff0 */
/* @0x2b0142 nop */
/* @0x2b0144 udf #0xe9 */
/* @0x2b0146 movs r5, r1 */

/* ── FUNC 0x2b0148 · png_convert_from_struct_tm · size=32 · insn=16 */
/* @0x2b0148 ldr r3, [r1, #0x14] */
/* @0x2b014a addw r3, r3, #0x76c */
/* @0x2b014c andhi r7, r3, r12, ror #6 */
/* @0x2b014e strh r3, [r0] */
/* @0x2b0150 ldr r3, [r1, #0x10] */
/* @0x2b0152 adds r3, #0x1 */
/* @0x2b0154 strb r3, [r0, #0x2] */
/* @0x2b0156 ldr r3, [r1, #0xc] */
/* @0x2b0158 strb r3, [r0, #0x3] */
/* @0x2b015a ldr r3, [r1, #0x8] */
/* @0x2b015c strb r3, [r0, #0x4] */
/* @0x2b015e ldr r3, [r1, #0x4] */
/* @0x2b0160 strb r3, [r0, #0x5] */
/* @0x2b0162 ldr r3, [r1] */
/* @0x2b0164 strb r3, [r0, #0x6] */
/* @0x2b0166 bx lr */

/* ── FUNC 0x2b0168 · png_convert_from_time_t · size=26 · insn=13 */
/* @0x2b0168 push {r0, r1, r4, lr} */
/* @0x2b016a mov r4, r0 */
/* @0x2b016c add r0, sp, #0x8 */
/* @0x2b016e str r1, [r0, #-4]! */
/* @0x2b0170 .word 0xf6061d04 */
/* @0x2b0172 blx 0xb6f4c <gmtime@plt> */
/* @0x2b0174 strmi lr, [r1], -r12, ror #29 */
/* @0x2b0176 mov r1, r0 */
/* @0x2b0178 mov r0, r4 */
/* @0x2b017a bl 0x2b0148 <png_convert_from_struct_tm> */
/* @0x2b017c andlt pc, r2, r5, ror #31 */
/* @0x2b017e add sp, #0x8 */
/* @0x2b0180 pop {r4, pc} */

/* ── FUNC 0x2b0184 · png_create_write_struct_2 · size=480 · insn=222 */
/* @0x2b0184 push {r4, r5, r6, r7, lr} */
/* @0x2b0186 sub sp, #0x84 */
/* @0x2b0188 str r0, [sp] */
/* @0x2b018a ldr r0, [sp, #0x98] */
/* @0x2b018c str r3, [sp, #0x1c] */
/* @0x2b018e ldr r3, [sp, #0xa0] */
/* @0x2b0190 str r0, [sp, #0x8] */
/* @0x2b0192 ldr r0, [pc, #0x1b4] */
/* @0x2b0194 str r2, [sp, #0x18] */
/* @0x2b0196 str r3, [sp, #0x10] */
/* @0x2b0198 add r0, pc */
/* @0x2b019a ldr r2, [sp, #0x9c] */
/* @0x2b019c ldr r3, [pc, #0x1ac] */
/* @0x2b019e str r0, [sp, #0x4] */
/* @0x2b01a0 str r1, [sp, #0x14] */
/* @0x2b01a2 mov r1, r2 */
/* @0x2b01a4 str r2, [sp, #0xc] */
/* @0x2b01a6 ldr r3, [r0, r3] */
/* @0x2b01a8 movs r0, #0x1 */
/* @0x2b01aa ldr r2, [sp, #0x8] */
/* @0x2b01ac ldr r3, [r3] */
/* @0x2b01ae str r3, [sp, #0x7c] */
/* @0x2b01b0 movs r3, #0x0 */
/* @0x2b01b2 str r3, [sp, #0x24] */
/* @0x2b01b4 bl 0x2a6c02 <png_create_struct_2> */
/* @0x2b01b8 str r0, [sp, #0x28] */
/* @0x2b01ba ldr r0, [sp, #0x28] */
/* @0x2b01bc cmp r0, #0x0 */
/* @0x2b01be beq.w 0x2b032e <png_create_write_struct_2+0x1aa> */
/* @0x2b01c0 bls 0x5504a0 <gp_ActiveMaskObjects+0xb7d8> */
/* @0x2b01c2 ldr r2, [sp, #0x28] */
/* @0x2b01c4 ldr r3, [pc, #0x17c] */
/* @0x2b01c6 str.w r3, [r2, #0x308] */
/* @0x2b01c8 bls 0x53cdf0 <obj_has_event+0x2280> */
/* @0x2b01ca ldr r2, [sp, #0x28] */
/* @0x2b01cc ldr r0, [sp, #0x28] */
/* @0x2b01ce str.w r3, [r2, #0x30c] */
/* @0x2b01d0 bls 0x2fce08 <TT_RunIns+0x14> */
/* @0x2b01d2 ldr r2, [sp, #0x4] */
/* @0x2b01d4 ldr r3, [pc, #0x178] */
/* @0x2b01d6 ldr r1, [r2, r3] */
/* @0x2b01d8 mov.w r2, #0x100 */
/* @0x2b01dc bl 0x2a653c <png_set_longjmp_fn> */
/* @0x2b01e0 blx 0xb6904 <setjmp@plt> */
/* @0x2b01e4 mov r4, r0 */
/* @0x2b01e6 cbz r0, 0x2b01ec <png_create_write_struct_2+0x68> */
/* @0x2b01e8 blx 0xb6c88 <abort@plt> */
/* @0x2b01ec add r1, sp, #0x8 */
/* @0x2b01ee ldr r0, [sp, #0x28] */
/* @0x2b01f0 ldm r1, {r1, r2, r3} */
/* @0x2b01f2 bl 0x2a6d34 <png_set_mem_fn> */
/* @0x2b01f4 stmdbge r5, {r0, r1, r2, r3, r4, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2b01f6 add r1, sp, #0x14 */
/* @0x2b01f8 ldr r0, [sp, #0x28] */
/* @0x2b01fa ldm r1, {r1, r2, r3} */
/* @0x2b01fc bl 0x2a654e <png_set_error_fn> */
/* @0x2b0200 ldr r3, [sp] */
/* @0x2b0202 cbnz r3, 0x2b0210 <png_create_write_struct_2+0x8c> */
/* @0x2b0204 ldr r3, [sp, #0x28] */
/* @0x2b0206 ldr.w r3, [r3, #0x130] */
/* @0x2b0208 orrseq r3, r11, #48, #2 */
/* @0x2b020a lsls r3, r3, #0xe */
/* @0x2b020c bmi 0x2b0250 <png_create_write_struct_2+0xcc> */
/* @0x2b020e b 0x2b02d2 <png_create_write_struct_2+0x14e> */
/* @0x2b0210 ldr r5, [pc, #0x140] */
/* @0x2b0212 mov.w r3, #0xffffffff */
/* @0x2b0214 .word 0x260133ff */
/* @0x2b0216 movs r6, #0x1 */
/* @0x2b0218 add r5, pc */
/* @0x2b021a ldr r0, [sp] */
/* @0x2b021c adds r3, #0x1 */
/* @0x2b021e ldrb r2, [r3, r5] */
/* @0x2b0220 mov r7, r3 */
/* @0x2b0222 ldrb r1, [r0, r3] */
/* @0x2b0224 cmp r1, r2 */
/* @0x2b0226 beq 0x2b0236 <png_create_write_struct_2+0xb2> */
/* @0x2b0228 ldr r1, [sp, #0x28] */
/* @0x2b022a ldr.w r0, [r1, #0x130] */
/* @0x2b022c vst4.8 {d16, d18, d20, d22}, [r0:256], r0 */
/* @0x2b022e orr r0, r0, #0x20000 */
/* @0x2b0230 .word 0xf8c13000 */
/* @0x2b0232 str.w r0, [r1, #0x130] */
/* @0x2b0234 stmdals r0, {r4, r5, r8} */
/* @0x2b0236 ldr r0, [sp] */
/* @0x2b0238 ldrb r1, [r0, r7] */
/* @0x2b023a cmp r1, #0x2e */
/* @0x2b023c bne 0x2b0246 <png_create_write_struct_2+0xc2> */
/* @0x2b023e cmp r4, #0x0 */
/* @0x2b0240 bne 0x2b0204 <png_create_write_struct_2+0x80> */
/* @0x2b0242 mov r4, r6 */
/* @0x2b0244 b 0x2b024a <png_create_write_struct_2+0xc6> */
/* @0x2b0246 cmp r1, #0x0 */
/* @0x2b0248 beq 0x2b0204 <png_create_write_struct_2+0x80> */
/* @0x2b024a cmp r2, #0x0 */
/* @0x2b024c bne 0x2b021a <png_create_write_struct_2+0x96> */
/* @0x2b024e b 0x2b0204 <png_create_write_struct_2+0x80> */
/* @0x2b0250 ldr r2, [sp] */
/* @0x2b0252 cbz r2, 0x2b02a6 <png_create_write_struct_2+0x122> */
/* @0x2b0254 movs r0, #0x0 */
/* @0x2b0256 ldrb r4, [r2] */
/* @0x2b0258 bl 0x2a5fcc <png_get_header_ver> */
/* @0x2b025c ldrb r3, [r0] */
/* @0x2b025e cmp r3, r4 */
/* @0x2b0260 bne 0x2b028e <png_create_write_struct_2+0x10a> */
/* @0x2b0262 ldr r0, [sp] */
/* @0x2b0264 ldrb r3, [r0] */
/* @0x2b0266 cmp r3, #0x31 */
/* @0x2b0268 beq 0x2b0274 <png_create_write_struct_2+0xf0> */
/* @0x2b026a ldr r2, [sp] */
/* @0x2b026c ldrb r3, [r2] */
/* @0x2b026e cmp r3, #0x30 */
/* @0x2b0270 bne 0x2b02d2 <png_create_write_struct_2+0x14e> */
/* @0x2b0272 b 0x2b0286 <png_create_write_struct_2+0x102> */
/* @0x2b0274 ldr r3, [sp] */
/* @0x2b0276 movs r0, #0x0 */
/* @0x2b0278 ldrb r4, [r3, #0x2] */
/* @0x2b027a bl 0x2a5fcc <png_get_header_ver> */
/* @0x2b027c stmvc r3, {r0, r1, r2, r5, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2b027e ldrb r3, [r0, #0x2] */
/* @0x2b0280 cmp r3, r4 */
/* @0x2b0282 bne 0x2b028e <png_create_write_struct_2+0x10a> */
/* @0x2b0284 b 0x2b026a <png_create_write_struct_2+0xe6> */
/* @0x2b0286 ldr r0, [sp] */
/* @0x2b0288 ldrb r3, [r0, #0x2] */
/* @0x2b028a cmp r3, #0x38 */
/* @0x2b028c bhi 0x2b02d2 <png_create_write_struct_2+0x14e> */
/* @0x2b028e add r4, sp, #0x2c */
/* @0x2b0290 ldr r2, [pc, #0xc4] */
/* @0x2b0292 movs r1, #0x50 */
/* @0x2b0294 ldr r3, [sp] */
/* @0x2b0296 mov r0, r4 */
/* @0x2b0298 add r2, pc */
/* @0x2b029a blx 0xb65c8 <snprintf@plt> */
/* @0x2b029c stmdals r10, {r1, r2, r4, r7, r8, r11, sp, lr, pc} */
/* @0x2b029e ldr r0, [sp, #0x28] */
/* @0x2b02a0 mov r1, r4 */
/* @0x2b02a2 bl 0x2a6474 <png_warning> */
/* @0x2b02a4 andhs pc, r0, r7, ror #17 */
/* @0x2b02a6 movs r0, #0x0 */
/* @0x2b02a8 add r4, sp, #0x2c */
/* @0x2b02aa bl 0x2a5fcc <png_get_header_ver> */
/* @0x2b02ac bmi 0xdafcf0 <b2_toiTime+0x65684c> */
/* @0x2b02ae ldr r2, [pc, #0xac] */
/* @0x2b02b0 movs r1, #0x50 */
/* @0x2b02b2 add r2, pc */
/* @0x2b02b4 mov r3, r0 */
/* @0x2b02b6 mov r0, r4 */
/* @0x2b02b8 blx 0xb65c8 <snprintf@plt> */
/* @0x2b02bc ldr r0, [sp, #0x28] */
/* @0x2b02be mov r1, r4 */
/* @0x2b02c0 bl 0x2a6474 <png_warning> */
/* @0x2b02c4 ldr r1, [pc, #0x98] */
/* @0x2b02c6 ldr r0, [sp, #0x28] */
/* @0x2b02c8 add r1, pc */
/* @0x2b02ca bl 0x2a6474 <png_warning> */
/* @0x2b02cc movwhs pc, #0x18d3 */
/* @0x2b02ce movs r3, #0x1 */
/* @0x2b02d0 str r3, [sp, #0x24] */
/* @0x2b02d2 ldr r3, [sp, #0x28] */
/* @0x2b02d4 mov.w r2, #0x2000 */
/* @0x2b02d8 str.w r2, [r3, #0x174] */
/* @0x2b02dc ldr r3, [sp, #0x24] */
/* @0x2b02de cbnz r3, 0x2b02fe <png_create_write_struct_2+0x17a> */
/* @0x2b02e0 ldr r4, [sp, #0x28] */
/* @0x2b02e2 ldr r0, [sp, #0x28] */
/* @0x2b02e4 ldr r3, [sp, #0x28] */
/* @0x2b02e6 ldr.w r1, [r3, #0x174] */
/* @0x2b02e8 .word 0xf7f61174 */
/* @0x2b02ea bl 0x2a6d16 <png_malloc_warn> */
/* @0x2b02ec blls 0x56f744 <g_SWFlineaavertbuff+0x1c67c> */
/* @0x2b02ee ldr r3, [sp, #0x28] */
/* @0x2b02f0 str.w r0, [r4, #0x170] */
/* @0x2b02f4 ldr.w r3, [r3, #0x170] */
/* @0x2b02f8 cbnz r3, 0x2b02fe <png_create_write_struct_2+0x17a> */
/* @0x2b02fa movs r3, #0x1 */
/* @0x2b02fc str r3, [sp, #0x24] */
/* @0x2b02fe ldr r1, [sp, #0x24] */
/* @0x2b0300 ldr r0, [sp, #0x28] */
/* @0x2b0302 cbz r1, 0x2b0324 <png_create_write_struct_2+0x1a0> */
/* @0x2b0304 ldr r3, [sp, #0x28] */
/* @0x2b0306 movs r4, #0x0 */
/* @0x2b0308 ldr.w r1, [r3, #0x170] */
/* @0x2b030c bl 0x2a6cfc <png_free> */
/* @0x2b0310 ldr r3, [sp, #0x28] */
/* @0x2b0312 ldr r1, [sp, #0x10] */
/* @0x2b0314 ldr r0, [sp, #0x28] */
/* @0x2b0316 str.w r4, [r3, #0x170] */
/* @0x2b0318 bls 0x3408e0 */
/* @0x2b031a ldr r2, [sp, #0x8] */
/* @0x2b031c bl 0x2a6c5e <png_destroy_struct_2> */
/* @0x2b0320 mov r0, r4 */
/* @0x2b0322 b 0x2b032e <png_create_write_struct_2+0x1aa> */
/* @0x2b0324 mov r2, r1 */
/* @0x2b0326 mov r3, r1 */
/* @0x2b0328 bl 0x2afc18 <png_set_write_fn> */
/* @0x2b032c ldr r0, [sp, #0x28] */
/* @0x2b032e ldr r2, [sp, #0x4] */
/* @0x2b0330 ldr r3, [pc, #0x18] */
/* @0x2b0332 ldr r3, [r2, r3] */
/* @0x2b0334 ldr r2, [sp, #0x7c] */
/* @0x2b0336 ldr r3, [r3] */
/* @0x2b0338 cmp r2, r3 */
/* @0x2b033a beq 0x2b0340 <png_create_write_struct_2+0x1bc> */
/* @0x2b033c blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2b0340 add sp, #0x84 */
/* @0x2b0342 pop {r4, r5, r6, r7, pc} */
/* @0x2b0344 rsbs r0, r0, #0 */
/* @0x2b0346 movs r7, r1 */
/* @0x2b0348 subs r4, r7, r2 */
/* @0x2b034a movs r4, r2 */
/* @0x2b034c pop {pc} */
/* @0x2b034e .word 0xffff e4ac */
/* @0x2b0350 .word 0xffffe4ac */
/* @0x2b0352 vsra.u32 q14, q4, #0x1 */
/* @0x2b0354 andeq r12, sp, r8, asr r1 */
/* @0x2b0356 movs r5, r1 */
/* @0x2b0358 stm r5!, {r3} */
/* @0x2b035a movs r5, r1 */
/* @0x2b035c stm r4!, {r0, r3, r6} */
/* @0x2b035e movs r5, r1 */
/* @0x2b0360 stm r4!, {r0, r3, r5, r6} */
/* @0x2b0362 movs r5, r1 */

/* ── FUNC 0x2b0364 · png_create_write_struct · size=18 · insn=9 */
/* @0x2b0364 push {r0, r1, r2, r3, r4, lr} */
/* @0x2b0366 movs r4, #0x0 */
/* @0x2b0368 str r4, [sp] */
/* @0x2b036a str r4, [sp, #0x4] */
/* @0x2b036c str r4, [sp, #0x8] */
/* @0x2b036e bl 0x2b0184 <png_create_write_struct_2> */
/* @0x2b0370 andlt pc, r4, r9, lsl #30 */
/* @0x2b0372 add sp, #0x10 */
/* @0x2b0374 pop {r4, pc} */

/* ── FUNC 0x2b0378 · png_write_row · size=376 · insn=161 */
/* @0x2b0378 push {r3, r4, r5, lr} */
/* @0x2b037a mov r5, r1 */
/* @0x2b037c mov r4, r0 */
/* @0x2b037e cmp r0, #0x0 */
/* @0x2b0380 beq.w 0x2b04e8 <png_write_row+0x170> */
/* @0x2b0384 ldr.w r3, [r0, #0x1a8] */
/* @0x2b0388 cbnz r3, 0x2b03a6 <png_write_row+0x2e> */
/* @0x2b038a ldrb.w r3, [r0, #0x1e8] */
/* @0x2b038c ldmdblt r3, {r3, r5, r6, r7, r8, r12, sp} ^ */
/* @0x2b038e cbnz r3, 0x2b03a6 <png_write_row+0x2e> */
/* @0x2b0390 ldr.w r3, [r0, #0x12c] */
/* @0x2b0394 lsls r2, r3, #0x15 */
/* @0x2b0396 bmi 0x2b03a0 <png_write_row+0x28> */
/* @0x2b0398 ldr r1, [pc, #0x150] */
/* @0x2b039a add r1, pc */
/* @0x2b039c bl 0x2a642c <png_error> */
/* @0x2b03a0 mov r0, r4 */
/* @0x2b03a2 bl 0x2b2510 <png_write_start_row> */
/* @0x2b03a4 .word 0xf894f8b5 */
/* @0x2b03a6 ldrb.w r3, [r4, #0x1e7] */
/* @0x2b03a8 blhs 0x2bcb4c <jpeg_alloc_huff_table+0x244> */
/* @0x2b03aa cmp r3, #0x0 */
/* @0x2b03ac beq 0x2b0430 <png_write_row+0xb8> */
/* @0x2b03ae ldr.w r3, [r4, #0x134] */
/* @0x2b03b0 .word 0x079b3134 */
/* @0x2b03b2 lsls r3, r3, #0x1e */
/* @0x2b03b4 bpl 0x2b0430 <png_write_row+0xb8> */
/* @0x2b03b6 ldrb.w r3, [r4, #0x1e8] */
/* @0x2b03b8 blhs 0x43cb60 <g_RomDisk+0x45340> */
/* @0x2b03ba cmp r3, #0x6 */
/* @0x2b03bc bhi 0x2b0430 <png_write_row+0xb8> */
/* @0x2b03be tbb [pc, r3] */
/* @0x2b03c0 stceq p0, c15, [r4, #-12] */
/* @0x2b03c2 lsrs r4, r0, #0x14 */
/* @0x2b03c4 subs r5, r2, r4 */
/* @0x2b03c6 cmp r2, #0x23 */
/* @0x2b03c8 movs r3, r6 */
/* @0x2b03ca ldr.w r3, [r4, #0x1a8] */
/* @0x2b03cc ldrbeq r3, [r8, -r8, lsr #3] */
/* @0x2b03ce lsls r0, r3, #0x1d */
/* @0x2b03d0 beq 0x2b0430 <png_write_row+0xb8> */
/* @0x2b03d2 mov r0, r4 */
/* @0x2b03d4 pop.w {r3, r4, r5, lr} */
/* @0x2b03d8 b.w 0x2b260c <png_write_finish_row> */
/* @0x2b03dc ldr.w r3, [r4, #0x1a8] */
/* @0x2b03e0 lsls r1, r3, #0x1d */
/* @0x2b03e2 bne 0x2b03d2 <png_write_row+0x5a> */
/* @0x2b03e4 ldr.w r3, [r4, #0x18c] */
/* @0x2b03e8 cmp r3, #0x4 */
/* @0x2b03ea b 0x2b0424 <png_write_row+0xac> */
/* @0x2b03ec ldr.w r3, [r4, #0x1a8] */
/* @0x2b03f0 and r3, r3, #0x7 */
/* @0x2b03f4 cmp r3, #0x4 */
/* @0x2b03f6 b 0x2b0412 <png_write_row+0x9a> */
/* @0x2b03f8 ldr.w r3, [r4, #0x1a8] */
/* @0x2b03fc lsls r2, r3, #0x1e */
/* @0x2b03fe bne 0x2b03d2 <png_write_row+0x5a> */
/* @0x2b0400 ldr.w r3, [r4, #0x18c] */
/* @0x2b0404 cmp r3, #0x2 */
/* @0x2b0406 b 0x2b0424 <png_write_row+0xac> */
/* @0x2b0408 ldr.w r3, [r4, #0x1a8] */
/* @0x2b040c and r3, r3, #0x3 */
/* @0x2b0410 cmp r3, #0x2 */
/* @0x2b0412 beq 0x2b0430 <png_write_row+0xb8> */
/* @0x2b0414 b 0x2b03d2 <png_write_row+0x5a> */
/* @0x2b0416 ldr.w r3, [r4, #0x1a8] */
/* @0x2b0418 ldrbeq r3, [r11, r8, lsr #3] */
/* @0x2b041a lsls r3, r3, #0x1f */
/* @0x2b041c bmi 0x2b03d2 <png_write_row+0x5a> */
/* @0x2b041e ldr.w r3, [r4, #0x18c] */
/* @0x2b0420 blhs 0x2fca58 <ps_hints_apply+0xb658> */
/* @0x2b0422 cmp r3, #0x1 */
/* @0x2b0424 bhi 0x2b0430 <png_write_row+0xb8> */
/* @0x2b0426 b 0x2b03d2 <png_write_row+0x5a> */
/* @0x2b0428 ldr.w r3, [r4, #0x1a8] */
/* @0x2b042c lsls r0, r3, #0x1f */
/* @0x2b042e bpl 0x2b03d2 <png_write_row+0x5a> */
/* @0x2b0430 ldrb.w r3, [r4, #0x1ea] */
/* @0x2b0434 ldrb.w r0, [r4, #0x1ef] */
/* @0x2b0438 ldr.w r2, [r4, #0x198] */
/* @0x2b043c strb.w r3, [r4, #0x1cc] */
/* @0x2b0440 ldrb.w r3, [r4, #0x1ec] */
/* @0x2b0444 str.w r2, [r4, #0x1c4] */
/* @0x2b0448 strb.w r0, [r4, #0x1ce] */
/* @0x2b044c strb.w r3, [r4, #0x1cd] */
/* @0x2b0450 muls r3, r0, r3 */
/* @0x2b0452 uxtb r3, r3 */
/* @0x2b0454 strb.w r3, [r4, #0x1cf] */
/* @0x2b0458 cmp r3, #0x7 */
/* @0x2b045a bls 0x2b0462 <png_write_row+0xea> */
/* @0x2b045c lsrs r3, r3, #0x3 */
/* @0x2b045e muls r2, r3, r2 */
/* @0x2b0460 b 0x2b0468 <png_write_row+0xf0> */
/* @0x2b0462 muls r2, r3, r2 */
/* @0x2b0464 adds r2, #0x7 */
/* @0x2b0466 lsrs r2, r2, #0x3 */
/* @0x2b0468 ldr.w r0, [r4, #0x1b0] */
/* @0x2b046c mov r1, r5 */
/* @0x2b046e str.w r2, [r4, #0x1c8] */
/* @0x2b0470 .word 0xf50421c8 */
/* @0x2b0472 add.w r5, r4, #0x1c4 */
/* @0x2b0474 andlo r7, r1, r2, ror #11 */
/* @0x2b0476 adds r0, #0x1 */
/* @0x2b0478 blx 0xb65bc <memcpy@plt> */
/* @0x2b047c ldrb.w r3, [r4, #0x1e7] */
/* @0x2b0480 cbz r3, 0x2b04a6 <png_write_row+0x12e> */
/* @0x2b0482 ldrb.w r2, [r4, #0x1e8] */
/* @0x2b0484 bhs 0x3f8c2c <g_RomDisk+0x140c> */
/* @0x2b0486 cmp r2, #0x5 */
/* @0x2b0488 bhi 0x2b04a6 <png_write_row+0x12e> */
/* @0x2b048a ldr.w r3, [r4, #0x134] */
/* @0x2b048c .word 0x07993134 */
/* @0x2b048e lsls r1, r3, #0x1e */
/* @0x2b0490 bpl 0x2b04a6 <png_write_row+0x12e> */
/* @0x2b0492 ldr.w r1, [r4, #0x1b0] */
/* @0x2b0494 .word 0x462811b0 */
/* @0x2b0496 mov r0, r5 */
/* @0x2b0498 adds r1, #0x1 */
/* @0x2b049a bl 0x2b279c <png_do_write_interlace> */
/* @0x2b049c .word 0xf8d4f97f */
/* @0x2b049e ldr.w r3, [r4, #0x1c4] */
/* @0x2b04a0 blhs 0x2bcbb8 <jpeg_alloc_huff_table+0x2b0> */
/* @0x2b04a2 cmp r3, #0x0 */
/* @0x2b04a4 beq 0x2b03d2 <png_write_row+0x5a> */
/* @0x2b04a6 ldr.w r3, [r4, #0x134] */
/* @0x2b04a8 tstlt r3, r4, lsr r1 */
/* @0x2b04aa cbz r3, 0x2b04b2 <png_write_row+0x13a> */
/* @0x2b04ac mov r0, r4 */
/* @0x2b04ae bl 0x2b0dbc <png_do_write_transformations> */
/* @0x2b04b0 .word 0xf8d4fc85 */
/* @0x2b04b2 ldr.w r3, [r4, #0x2dc] */
/* @0x2b04b4 smmlseq r11, r12, r2, r3 */
/* @0x2b04b6 lsls r3, r3, #0x1d */
/* @0x2b04b8 bpl 0x2b04ce <png_write_row+0x156> */
/* @0x2b04ba ldrb.w r3, [r4, #0x2e4] */
/* @0x2b04bc blhs 0x12bd054 <b2_toiTime+0xb63bb0> */
/* @0x2b04be cmp r3, #0x40 */
/* @0x2b04c0 bne 0x2b04ce <png_write_row+0x156> */
/* @0x2b04c2 ldr.w r1, [r4, #0x1b0] */
/* @0x2b04c4 .word 0x462811b0 */
/* @0x2b04c6 mov r0, r5 */
/* @0x2b04c8 adds r1, #0x1 */
/* @0x2b04ca bl 0x2b0eb6 <png_do_write_intrapixel> */
/* @0x2b04cc qsub8mi pc, r0, r4 */
/* @0x2b04ce mov r0, r4 */
/* @0x2b04d0 mov r1, r5 */
/* @0x2b04d2 bl 0x2b29d8 <png_write_find_filter> */
/* @0x2b04d4 .word 0xf8d4fa81 */
/* @0x2b04d6 ldr.w r3, [r4, #0x260] */
/* @0x2b04d8 .word 0xb12b3260 */
/* @0x2b04da cbz r3, 0x2b04e8 <png_write_row+0x170> */
/* @0x2b04dc mov r0, r4 */
/* @0x2b04de ldr.w r1, [r4, #0x1a8] */
/* @0x2b04e0 .word 0xf89411a8 */
/* @0x2b04e2 ldrb.w r2, [r4, #0x1e8] */
/* @0x2b04e4 ldrmi r2, [r8, r8, ror #3] */
/* @0x2b04e6 blx r3 */
/* @0x2b04e8 pop {r3, r4, r5, pc} */
/* @0x2b04ea nop */
/* @0x2b04ec blt 0x2b044c <png_write_row+0xd4> */
/* @0x2b04ee movs r5, r1 */

/* ── FUNC 0x2b04f0 · png_write_rows · size=32 · insn=15 */
/* @0x2b04f0 push {r3, r4, r5, r6, r7, lr} */
/* @0x2b04f2 mov r6, r1 */
/* @0x2b04f4 mov r7, r2 */
/* @0x2b04f6 mov r5, r0 */
/* @0x2b04f8 cbz r0, 0x2b050e <png_write_rows+0x1e> */
/* @0x2b04fa movs r4, #0x0 */
/* @0x2b04fc cmp r4, r7 */
/* @0x2b04fe beq 0x2b050e <png_write_rows+0x1e> */
/* @0x2b0500 ldr.w r1, [r6, r4, lsl #2] */
/* @0x2b0504 mov r0, r5 */
/* @0x2b0506 bl 0x2b0378 <png_write_row> */
/* @0x2b0508 strlo pc, [r1], #-3895 */
/* @0x2b050a adds r4, #0x1 */
/* @0x2b050c b 0x2b04fc <png_write_rows+0xc> */
/* @0x2b050e pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2b0510 · png_write_image · size=54 · insn=24 */
/* @0x2b0510 push.w {r4, r5, r6, r7, r8, lr} */
/* @0x2b0514 mov r7, r1 */
/* @0x2b0516 mov r6, r0 */
/* @0x2b0518 cbz r0, 0x2b0542 <png_write_image+0x32> */
/* @0x2b051a bl 0x2af7b2 <png_set_interlace_handling> */
/* @0x2b051c strhs pc, [r0, #-0x94a] */
/* @0x2b051e movs r5, #0x0 */
/* @0x2b0520 mov r8, r0 */
/* @0x2b0522 cmp r5, r8 */
/* @0x2b0524 bge 0x2b0542 <png_write_image+0x32> */
/* @0x2b0526 movs r4, #0x0 */
/* @0x2b0528 ldr.w r3, [r6, #0x190] */
/* @0x2b052c cmp r4, r3 */
/* @0x2b052e bhs 0x2b053e <png_write_image+0x2e> */
/* @0x2b0530 ldr.w r1, [r7, r4, lsl #2] */
/* @0x2b0534 mov r0, r6 */
/* @0x2b0536 bl 0x2b0378 <png_write_row> */
/* @0x2b0538 strlo pc, [r1], #-3871 */
/* @0x2b053a adds r4, #0x1 */
/* @0x2b053c b 0x2b0528 <png_write_image+0x18> */
/* @0x2b053e adds r5, #0x1 */
/* @0x2b0540 b 0x2b0522 <png_write_image+0x12> */
/* @0x2b0542 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2b0544 ldrshlt r8, [r8, -r0] */

/* ── FUNC 0x2b0546 · png_set_flush · size=12 · insn=6 */
/* @0x2b0546 cbz r0, 0x2b0550 <png_set_flush+0xa> */
/* @0x2b0548 bic.w r1, r1, r1, asr #31 */
/* @0x2b054a .word 0xf8c071e1 */
/* @0x2b054c str.w r1, [r0, #0x214] */
/* @0x2b054e .word 0x47701214 */
/* @0x2b0550 bx lr */

/* ── FUNC 0x2b0552 · anon_2b0552 · size=0 · insn=1 */
/* @0x2b0552 ldrblt r0, [r0, #-0x0]! */

/* ── FUNC 0x2b0554 · png_write_flush · size=148 · insn=62 */
/* @0x2b0554 push {r4, r5, r6, lr} */
/* @0x2b0556 mov r4, r0 */
/* @0x2b0558 cmp r0, #0x0 */
/* @0x2b055a beq 0x2b05e2 <png_write_flush+0x8e> */
/* @0x2b055c ldr.w r2, [r0, #0x1a8] */
/* @0x2b0560 ldr.w r3, [r0, #0x194] */
/* @0x2b0564 cmp r2, r3 */
/* @0x2b0566 bhs 0x2b05e2 <png_write_flush+0x8e> */
/* @0x2b0568 ldr r6, [pc, #0x78] */
/* @0x2b056a add.w r5, r0, #0x138 */
/* @0x2b056c ldrbtmi r7, [lr], #-1436 */
/* @0x2b056e add r6, pc */
/* @0x2b0570 mov r0, r5 */
/* @0x2b0572 movs r1, #0x2 */
/* @0x2b0574 blx 0xb69ac <deflate@plt> */
/* @0x2b0578 cbz r0, 0x2b0588 <png_write_flush+0x34> */
/* @0x2b057a ldr.w r1, [r4, #0x150] */
/* @0x2b057c qsaxmi r1, r0, r0 */
/* @0x2b057e mov r0, r4 */
/* @0x2b0580 cbnz r1, 0x2b0584 <png_write_flush+0x30> */
/* @0x2b0582 mov r1, r6 */
/* @0x2b0584 bl 0x2a642c <png_error> */
/* @0x2b0588 ldr.w r3, [r4, #0x148] */
/* @0x2b058c cbnz r3, 0x2b05ae <png_write_flush+0x5a> */
/* @0x2b058e mov r0, r4 */
/* @0x2b0590 ldr.w r1, [r4, #0x170] */
/* @0x2b0594 ldr.w r2, [r4, #0x174] */
/* @0x2b0598 bl 0x2b16a0 <png_write_IDAT> */
/* @0x2b059c ldr.w r3, [r4, #0x170] */
/* @0x2b05a0 str.w r3, [r4, #0x144] */
/* @0x2b05a4 ldr.w r3, [r4, #0x174] */
/* @0x2b05a8 str.w r3, [r4, #0x148] */
/* @0x2b05ac b 0x2b0570 <png_write_flush+0x1c> */
/* @0x2b05ae ldr.w r2, [r4, #0x174] */
/* @0x2b05b0 addsmi r2, r10, #116, #2 */
/* @0x2b05b2 cmp r2, r3 */
/* @0x2b05b4 beq 0x2b05d2 <png_write_flush+0x7e> */
/* @0x2b05b6 subs r2, r2, r3 */
/* @0x2b05b8 mov r0, r4 */
/* @0x2b05ba ldr.w r1, [r4, #0x170] */
/* @0x2b05bc .word 0xf0011170 */
/* @0x2b05be bl 0x2b16a0 <png_write_IDAT> */
/* @0x2b05c0 .word 0xf8d4f86f */
/* @0x2b05c2 ldr.w r3, [r4, #0x170] */
/* @0x2b05c4 .word 0xf8c43170 */
/* @0x2b05c6 str.w r3, [r4, #0x144] */
/* @0x2b05c8 .word 0xf8d43144 */
/* @0x2b05ca ldr.w r3, [r4, #0x174] */
/* @0x2b05cc .word 0xf8c43174 */
/* @0x2b05ce str.w r3, [r4, #0x148] */
/* @0x2b05d0 movwhs r3, #0x148 */
/* @0x2b05d2 movs r3, #0x0 */
/* @0x2b05d4 mov r0, r4 */
/* @0x2b05d6 str.w r3, [r4, #0x218] */
/* @0x2b05d8 pop {r3, r4, r9, r12, sp} */
/* @0x2b05da pop.w {r4, r5, r6, lr} */
/* @0x2b05dc .word 0xf7ff4070 */
/* @0x2b05de b.w 0x2afc0c <png_flush> */
/* @0x2b05e0 .word 0xbd70bb15 */
/* @0x2b05e2 pop {r4, r5, r6, pc} */
/* @0x2b05e4 bge 0x2b0606 <png_write_destroy+0x1e> */
/* @0x2b05e6 movs r5, r1 */

/* ── FUNC 0x2b05e8 · png_write_destroy · size=170 · insn=71 */
/* @0x2b05e8 push.w {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2b05ec mov r4, r0 */
/* @0x2b05ee sub sp, #0x100 */
/* @0x2b05f0 add.w r0, r0, #0x138 */
/* @0x2b05f4 blx 0xb69b8 <deflateEnd@plt> */
/* @0x2b05f8 mov r0, r4 */
/* @0x2b05fa ldr.w r1, [r4, #0x170] */
/* @0x2b05fc vst4.16 {d17, d19, d21, d23}, [pc:256], r0 */
/* @0x2b05fe mov.w r5, #0x100 */
/* @0x2b0600 .word 0xf7f67580 */
/* @0x2b0602 bl 0x2a6cfc <png_free> */
/* @0x2b0604 qsub16mi pc, r0, r11 */
/* @0x2b0606 mov r0, r4 */
/* @0x2b0608 ldr.w r1, [r4, #0x1b0] */
/* @0x2b060c bl 0x2a6cfc <png_free> */
/* @0x2b0610 mov r0, r4 */
/* @0x2b0612 ldr.w r1, [r4, #0x1ac] */
/* @0x2b0614 .word 0xf7f611ac */
/* @0x2b0616 bl 0x2a6cfc <png_free> */
/* @0x2b0618 qsub16mi pc, r0, r1 */
/* @0x2b061a mov r0, r4 */
/* @0x2b061c ldr.w r1, [r4, #0x1b4] */
/* @0x2b0620 bl 0x2a6cfc <png_free> */
/* @0x2b0624 mov r0, r4 */
/* @0x2b0626 ldr.w r1, [r4, #0x1b8] */
/* @0x2b0628 .word 0xf7f611b8 */
/* @0x2b062a bl 0x2a6cfc <png_free> */
/* @0x2b062c strtmi pc, [r0], -r7, ror #22 */
/* @0x2b062e mov r0, r4 */
/* @0x2b0630 ldr.w r1, [r4, #0x1bc] */
/* @0x2b0634 bl 0x2a6cfc <png_free> */
/* @0x2b0638 mov r0, r4 */
/* @0x2b063a ldr.w r1, [r4, #0x1c0] */
/* @0x2b063c .word 0xf7f611c0 */
/* @0x2b063e bl 0x2a6cfc <png_free> */
/* @0x2b0640 qsaxmi pc, r0, sp */
/* @0x2b0642 mov r0, r4 */
/* @0x2b0644 ldr.w r1, [r4, #0x2bc] */
/* @0x2b0648 bl 0x2a6cfc <png_free> */
/* @0x2b064c mov r1, r4 */
/* @0x2b064e mov r2, r5 */
/* @0x2b0650 mov r0, sp */
/* @0x2b0652 blx 0xb65bc <memcpy@plt> */
/* @0x2b0654 .word 0xf8d4efb4 */
/* @0x2b0656 ldr.w r10, [r4, #0x104] */
/* @0x2b0658 .word 0xf8d4a104 */
/* @0x2b065a ldr.w r9, [r4, #0x108] */
/* @0x2b065c strtmi r9, [r0], -r8, lsl #2 */
/* @0x2b065e mov r0, r4 */
/* @0x2b0660 ldr.w r8, [r4, #0x10c] */
/* @0x2b0664 movs r1, #0x0 */
/* @0x2b0666 ldr.w r7, [r4, #0x2f0] */
/* @0x2b0668 vst1.64 {d23, d24, d25, d26}, [pc:256], r0 */
/* @0x2b066a mov.w r2, #0x338 */
/* @0x2b066c .word 0xf605724e */
/* @0x2b066e blx 0xb65b0 <memset@plt> */
/* @0x2b0670 .word 0xf8c4efa0 */
/* @0x2b0672 str.w r10, [r4, #0x104] */
/* @0x2b0674 .word 0xf8c4a104 */
/* @0x2b0676 str.w r9, [r4, #0x108] */
/* @0x2b0678 strtmi r9, [r0], -r8, lsl #2 */
/* @0x2b067a mov r0, r4 */
/* @0x2b067c str.w r8, [r4, #0x10c] */
/* @0x2b0680 mov r1, sp */
/* @0x2b0682 str.w r7, [r4, #0x2f0] */
/* @0x2b0684 qsub8mi r7, r10, r0 */
/* @0x2b0686 mov r2, r5 */
/* @0x2b0688 blx 0xb65bc <memcpy@plt> */
/* @0x2b068c add sp, #0x100 */
/* @0x2b068e pop.w {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b0690 push {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x2b0692 · png_destroy_write_struct · size=126 · insn=56 */
/* @0x2b0692 push.w {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2b0696 mov r8, r1 */
/* @0x2b0698 mov r5, r0 */
/* @0x2b069a cbz r0, 0x2b06a8 <png_destroy_write_struct+0x16> */
/* @0x2b069c ldr r4, [r0] */
/* @0x2b069e ldr.w r7, [r4, #0x2f0] */
/* @0x2b06a2 ldr.w r6, [r4, #0x2e8] */
/* @0x2b06a6 b 0x2b06ae <png_destroy_write_struct+0x1c> */
/* @0x2b06a8 mov r4, r0 */
/* @0x2b06aa mov r6, r0 */
/* @0x2b06ac mov r7, r0 */
/* @0x2b06ae cmp.w r8, #0x0 */
/* @0x2b06b2 beq 0x2b06f6 <png_destroy_write_struct+0x64> */
/* @0x2b06b4 ldr.w r9, [r8] */
/* @0x2b06b6 .word 0xf1b99000 */
/* @0x2b06b8 cmp.w r9, #0x0 */
/* @0x2b06ba andsle r0, r11, r0, lsl #30 */
/* @0x2b06bc beq 0x2b06f6 <png_destroy_write_struct+0x64> */
/* @0x2b06be cbz r4, 0x2b06e6 <png_destroy_write_struct+0x54> */
/* @0x2b06c0 mov.w r3, #0xffffffff */
/* @0x2b06c2 qsub8mi r3, r0, pc */
/* @0x2b06c4 mov r0, r4 */
/* @0x2b06c6 mov r1, r9 */
/* @0x2b06c8 movw r2, #0x7fff */
/* @0x2b06ca .word 0xf7f572ff */
/* @0x2b06cc bl 0x2a5bc0 <png_free_data> */
/* @0x2b06ce .word 0xf8d4fa78 */
/* @0x2b06d0 ldr.w r3, [r4, #0x2cc] */
/* @0x2b06d2 teqlt r11, r12, asr #5 */
/* @0x2b06d4 cbz r3, 0x2b06e6 <png_destroy_write_struct+0x54> */
/* @0x2b06d6 mov r0, r4 */
/* @0x2b06d8 ldr.w r1, [r4, #0x2d0] */
/* @0x2b06da .word 0xf7f612d0 */
/* @0x2b06dc bl 0x2a6cfc <png_free> */
/* @0x2b06de movwhs pc, #0xb0e */
/* @0x2b06e0 movs r3, #0x0 */
/* @0x2b06e2 str.w r3, [r4, #0x2cc] */
/* @0x2b06e6 mov r0, r9 */
/* @0x2b06e8 mov r1, r7 */
/* @0x2b06ea mov r2, r6 */
/* @0x2b06ec bl 0x2a6c5e <png_destroy_struct_2> */
/* @0x2b06ee movwhs pc, #0xab7 */
/* @0x2b06f0 movs r3, #0x0 */
/* @0x2b06f2 str.w r3, [r8] */
/* @0x2b06f6 cbz r4, 0x2b070c <png_destroy_write_struct+0x7a> */
/* @0x2b06f8 mov r0, r4 */
/* @0x2b06fa bl 0x2b05e8 <png_write_destroy> */
/* @0x2b06fe mov r0, r4 */
/* @0x2b0700 mov r1, r7 */
/* @0x2b0702 mov r2, r6 */
/* @0x2b0704 bl 0x2a6c5e <png_destroy_struct_2> */
/* @0x2b0706 movwhs pc, #0xaab */
/* @0x2b0708 movs r3, #0x0 */
/* @0x2b070a str r3, [r5] */
/* @0x2b070c pop.w {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2b070e ldrlt r8, [r0, #-0x3f8] */

/* ── FUNC 0x2b0710 · png_set_filter · size=372 · insn=166 */
/* @0x2b0710 push {r4, lr} */
/* @0x2b0712 mov r4, r0 */
/* @0x2b0714 cmp r0, #0x0 */
/* @0x2b0716 beq.w 0x2b086c <png_set_filter+0x15c> */
/* @0x2b0718 .word 0xf8d080a9 */
/* @0x2b071a ldr.w r3, [r0, #0x2dc] */
/* @0x2b071c smmlseq r8, r12, r2, r3 */
/* @0x2b071e lsls r0, r3, #0x1d */
/* @0x2b0720 bpl 0x2b0726 <png_set_filter+0x16> */
/* @0x2b0722 cmp r1, #0x40 */
/* @0x2b0724 beq 0x2b072c <png_set_filter+0x1c> */
/* @0x2b0726 cmp r1, #0x0 */
/* @0x2b0728 bne.w 0x2b085e <png_set_filter+0x14e> */
/* @0x2b072c uxtb r3, r2 */
/* @0x2b072e cmp r3, #0x7 */
/* @0x2b0730 bhi 0x2b0762 <png_set_filter+0x52> */
/* @0x2b0732 tbb [pc, r3] */
/* @0x2b0734 .word 0x0c04f003 */
/* @0x2b0736 lsrs r4, r0, #0x10 */
/* @0x2b0738 asrs r0, r2, #0x8 */
/* @0x2b073a lsls r4, r2, #0x18 */
/* @0x2b073c lsls r6, r0, #0x18 */
/* @0x2b073e movs r3, #0x8 */
/* @0x2b0740 b 0x2b0750 <png_set_filter+0x40> */
/* @0x2b0742 ldr r1, [pc, #0x12c] */
/* @0x2b0744 mov r0, r4 */
/* @0x2b0746 add r1, pc */
/* @0x2b0748 bl 0x2a6474 <png_warning> */
/* @0x2b074c b 0x2b0766 <png_set_filter+0x56> */
/* @0x2b074e movs r3, #0x10 */
/* @0x2b0750 strb.w r3, [r4, #0x1e9] */
/* @0x2b0754 b 0x2b0766 <png_set_filter+0x56> */
/* @0x2b0756 movs r3, #0x20 */
/* @0x2b0758 b 0x2b0750 <png_set_filter+0x40> */
/* @0x2b075a movs r3, #0x40 */
/* @0x2b075c b 0x2b0750 <png_set_filter+0x40> */
/* @0x2b075e movs r3, #0x80 */
/* @0x2b0760 b 0x2b0750 <png_set_filter+0x40> */
/* @0x2b0762 strb.w r2, [r4, #0x1e9] */
/* @0x2b0764 .word 0xf8d421e9 */
/* @0x2b0766 ldr.w r3, [r4, #0x1b0] */
/* @0x2b0768 blhs 0x2bce30 <jpeg_alloc_huff_table+0x528> */
/* @0x2b076a cmp r3, #0x0 */
/* @0x2b076c beq 0x2b086c <png_set_filter+0x15c> */
/* @0x2b076e ldrb.w r3, [r4, #0x1e9] */
/* @0x2b0770 ldrbeq r3, [r9], r9, ror #3 */
/* @0x2b0772 lsls r1, r3, #0x1b */
/* @0x2b0774 bpl 0x2b0790 <png_set_filter+0x80> */
/* @0x2b0776 ldr.w r3, [r4, #0x1b4] */
/* @0x2b0778 stmdblt r11, {r2, r4, r5, r7, r8, r12, sp} ^ */
/* @0x2b077a cbnz r3, 0x2b0790 <png_set_filter+0x80> */
/* @0x2b077c ldr.w r1, [r4, #0x19c] */
/* @0x2b0780 mov r0, r4 */
/* @0x2b0782 adds r1, #0x1 */
/* @0x2b0784 bl 0x2a6ca0 <png_malloc> */
/* @0x2b0788 movs r3, #0x1 */
/* @0x2b078a str.w r0, [r4, #0x1b4] */
/* @0x2b078c strhvc r0, [r3], -r4 */
/* @0x2b078e strb r3, [r0] */
/* @0x2b0790 ldrb.w r3, [r4, #0x1e9] */
/* @0x2b0794 lsls r2, r3, #0x1a */
/* @0x2b0796 bpl 0x2b07d0 <png_set_filter+0xc0> */
/* @0x2b0798 ldr.w r3, [r4, #0x1b8] */
/* @0x2b079c cbnz r3, 0x2b07d0 <png_set_filter+0xc0> */
/* @0x2b079e ldr.w r3, [r4, #0x1ac] */
/* @0x2b07a0 ldmdblt r11, {r2, r3, r5, r7, r8, r12, sp} ^ */
/* @0x2b07a2 cbnz r3, 0x2b07bc <png_set_filter+0xac> */
/* @0x2b07a4 ldr r1, [pc, #0xcc] */
/* @0x2b07a6 mov r0, r4 */
/* @0x2b07a8 add r1, pc */
/* @0x2b07aa bl 0x2a6474 <png_warning> */
/* @0x2b07ac .word 0xf894fe63 */
/* @0x2b07ae ldrb.w r3, [r4, #0x1e9] */
/* @0x2b07b0 .word 0xf02331e9 */
/* @0x2b07b2 bic r3, r3, #0x20 */
/* @0x2b07b4 .word 0xf8840320 */
/* @0x2b07b6 strb.w r3, [r4, #0x1e9] */
/* @0x2b07b8 and r3, r9, r9, ror #3 */
/* @0x2b07ba b 0x2b07d0 <png_set_filter+0xc0> */
/* @0x2b07bc ldr.w r1, [r4, #0x19c] */
/* @0x2b07c0 mov r0, r4 */
/* @0x2b07c2 adds r1, #0x1 */
/* @0x2b07c4 bl 0x2a6ca0 <png_malloc> */
/* @0x2b07c8 movs r3, #0x2 */
/* @0x2b07ca str.w r0, [r4, #0x1b8] */
/* @0x2b07cc strhvc r0, [r3], -r8 */
/* @0x2b07ce strb r3, [r0] */
/* @0x2b07d0 ldrb.w r3, [r4, #0x1e9] */
/* @0x2b07d4 lsls r3, r3, #0x19 */
/* @0x2b07d6 bpl 0x2b0810 <png_set_filter+0x100> */
/* @0x2b07d8 ldr.w r3, [r4, #0x1bc] */
/* @0x2b07dc cbnz r3, 0x2b0810 <png_set_filter+0x100> */
/* @0x2b07de ldr.w r3, [r4, #0x1ac] */
/* @0x2b07e0 ldmdblt r11, {r2, r3, r5, r7, r8, r12, sp} ^ */
/* @0x2b07e2 cbnz r3, 0x2b07fc <png_set_filter+0xec> */
/* @0x2b07e4 ldr r1, [pc, #0x90] */
/* @0x2b07e6 mov r0, r4 */
/* @0x2b07e8 add r1, pc */
/* @0x2b07ea bl 0x2a6474 <png_warning> */
/* @0x2b07ec .word 0xf894fe43 */
/* @0x2b07ee ldrb.w r3, [r4, #0x1e9] */
/* @0x2b07f0 .word 0xf02331e9 */
/* @0x2b07f2 bic r3, r3, #0x40 */
/* @0x2b07f4 .word 0xf8840340 */
/* @0x2b07f6 strb.w r3, [r4, #0x1e9] */
/* @0x2b07f8 and r3, r9, r9, ror #3 */
/* @0x2b07fa b 0x2b0810 <png_set_filter+0x100> */
/* @0x2b07fc ldr.w r1, [r4, #0x19c] */
/* @0x2b0800 mov r0, r4 */
/* @0x2b0802 adds r1, #0x1 */
/* @0x2b0804 bl 0x2a6ca0 <png_malloc> */
/* @0x2b0808 movs r3, #0x3 */
/* @0x2b080a str.w r0, [r4, #0x1bc] */
/* @0x2b080c strhvc r0, [r3], -r12 */
/* @0x2b080e strb r3, [r0] */
/* @0x2b0810 ldrsb.w r3, [r4, #0x1e9] */
/* @0x2b0814 cmp r3, #0x0 */
/* @0x2b0816 bge 0x2b0850 <png_set_filter+0x140> */
/* @0x2b0818 ldr.w r3, [r4, #0x1c0] */
/* @0x2b081c cbnz r3, 0x2b0850 <png_set_filter+0x140> */
/* @0x2b081e ldr.w r3, [r4, #0x1ac] */
/* @0x2b0820 ldmdblt r11, {r2, r3, r5, r7, r8, r12, sp} ^ */
/* @0x2b0822 cbnz r3, 0x2b083c <png_set_filter+0x12c> */
/* @0x2b0824 ldr r1, [pc, #0x54] */
/* @0x2b0826 mov r0, r4 */
/* @0x2b0828 add r1, pc */
/* @0x2b082a bl 0x2a6474 <png_warning> */
/* @0x2b082c .word 0xf894fe23 */
/* @0x2b082e ldrb.w r3, [r4, #0x1e9] */
/* @0x2b0830 .word 0xf00331e9 */
/* @0x2b0832 and r3, r3, #0x7f */
/* @0x2b0834 .word 0xf884037f */
/* @0x2b0836 strb.w r3, [r4, #0x1e9] */
/* @0x2b0838 and r3, r9, r9, ror #3 */
/* @0x2b083a b 0x2b0850 <png_set_filter+0x140> */
/* @0x2b083c ldr.w r1, [r4, #0x19c] */
/* @0x2b0840 mov r0, r4 */
/* @0x2b0842 adds r1, #0x1 */
/* @0x2b0844 bl 0x2a6ca0 <png_malloc> */
/* @0x2b0848 movs r3, #0x4 */
/* @0x2b084a str.w r0, [r4, #0x1c0] */
/* @0x2b084c andvc r0, r3, r0, asr #3 */
/* @0x2b084e strb r3, [r0] */
/* @0x2b0850 ldrb.w r3, [r4, #0x1e9] */
/* @0x2b0854 cbnz r3, 0x2b086c <png_set_filter+0x15c> */
/* @0x2b0856 movs r3, #0x8 */
/* @0x2b0858 strb.w r3, [r4, #0x1e9] */
/* @0x2b085c pop {r4, pc} */
/* @0x2b085e ldr r1, [pc, #0x20] */
/* @0x2b0860 mov r0, r4 */
/* @0x2b0862 pop.w {r4, lr} */
/* @0x2b0864 ldrbtmi r4, [r9], #-16 */
/* @0x2b0866 add r1, pc */
/* @0x2b0868 b.w 0x2a642c <png_error> */
/* @0x2b086c pop {r4, pc} */
/* @0x2b086e nop */
/* @0x2b0870 bhi 0x2b08f8 <png_set_compression_window_bits+0x34> */
/* @0x2b0872 movs r5, r1 */
/* @0x2b0874 bhi 0x2b0878 <png_set_filter+0x168> */
/* @0x2b0876 movs r5, r1 */
/* @0x2b0878 bvc 0x2b0842 <png_set_filter+0x132> */
/* @0x2b087a movs r5, r1 */
/* @0x2b087c bvc 0x2b0816 <png_set_filter+0x106> */
/* @0x2b087e movs r5, r1 */
/* @0x2b0880 bvc 0x2b07ea <png_set_filter+0xda> */
/* @0x2b0882 movs r5, r1 */
