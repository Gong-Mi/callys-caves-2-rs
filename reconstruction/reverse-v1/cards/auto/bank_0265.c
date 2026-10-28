/* libyoyo.so 覆盖卡组 0265
 * 函数 0x2bc81c..0x2c1394，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2bc81c · jcopy_sample_rows · size=56 · insn=14 */
/* @0x2bc81c push {r3, r4, r5, r6, r7, lr} */
/* @0x2bc820 add r5, r0, r1, lsl #2 */
/* @0x2bc824 ldr r4, [sp, #0x18] */
/* @0x2bc828 add r6, r2, r3, lsl #2 */
/* @0x2bc82c ldr r7, [sp, #0x1c] */
/* @0x2bc830 cmp r4, #0 */
/* @0x2bc834 pople {r3, r4, r5, r6, r7, pc} */
/* @0x2bc838 ldr r0, [r6], #4 */
/* @0x2bc83c mov r2, r7 */
/* @0x2bc840 ldr r1, [r5], #4 */
/* @0x2bc844 bl 0xb65bc <memcpy@plt> */
/* @0x2bc848 subs r4, r4, #1 */
/* @0x2bc84c bne 0x2bc838 <jcopy_sample_rows+0x1c> */
/* @0x2bc850 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2bc854 · jcopy_block_row · size=20 · insn=5 */
/* @0x2bc854 mov r3, r0 */
/* @0x2bc858 lsl r2, r2, #7 */
/* @0x2bc85c mov r0, r1 */
/* @0x2bc860 mov r1, r3 */
/* @0x2bc864 b 0xb65bc <memcpy@plt> */

/* ── FUNC 0x2bc868 · jzero_far · size=12 · insn=3 */
/* @0x2bc868 mov r2, r1 */
/* @0x2bc86c mov r1, #0 */
/* @0x2bc870 b 0xb65b0 <memset@plt> */

/* ── FUNC 0x2bc874 · jpeg_abort · size=68 · insn=17 */
/* @0x2bc874 ldr r3, [r0, #0x4] */
/* @0x2bc878 push {r4, lr} */
/* @0x2bc87c cmp r3, #0 */
/* @0x2bc880 mov r4, r0 */
/* @0x2bc884 popeq {r4, pc} */
/* @0x2bc888 ldr r3, [r3, #0x24] */
/* @0x2bc88c mov r1, #1 */
/* @0x2bc890 blx r3 */
/* @0x2bc894 ldrb r3, [r4, #0x10] */
/* @0x2bc898 cmp r3, #0 */
/* @0x2bc89c movne r2, #200 */
/* @0x2bc8a0 movne r3, #0 */
/* @0x2bc8a4 moveq r3, #100 */
/* @0x2bc8a8 strne r3, [r4, #0x10c] */
/* @0x2bc8ac streq r3, [r4, #0x14] */
/* @0x2bc8b0 strne r2, [r4, #0x14] */
/* @0x2bc8b4 pop {r4, pc} */

/* ── FUNC 0x2bc8b8 · jpeg_destroy · size=44 · insn=11 */
/* @0x2bc8b8 ldr r3, [r0, #0x4] */
/* @0x2bc8bc push {r4, lr} */
/* @0x2bc8c0 cmp r3, #0 */
/* @0x2bc8c4 mov r4, r0 */
/* @0x2bc8c8 beq 0x2bc8d4 <jpeg_destroy+0x1c> */
/* @0x2bc8cc ldr r3, [r3, #0x28] */
/* @0x2bc8d0 blx r3 */
/* @0x2bc8d4 mov r3, #0 */
/* @0x2bc8d8 str r3, [r4, #0x4] */
/* @0x2bc8dc str r3, [r4, #0x14] */
/* @0x2bc8e0 pop {r4, pc} */

/* ── FUNC 0x2bc8e4 · jpeg_alloc_quant_table · size=36 · insn=9 */
/* @0x2bc8e4 push {r3, lr} */
/* @0x2bc8e8 mov r1, #0 */
/* @0x2bc8ec ldr r3, [r0, #0x4] */
/* @0x2bc8f0 mov r2, #130 */
/* @0x2bc8f4 ldr r3, [r3] */
/* @0x2bc8f8 blx r3 */
/* @0x2bc8fc mov r2, #0 */
/* @0x2bc900 strb r2, [r0, #0x80] */
/* @0x2bc904 pop {r3, pc} */

/* ── FUNC 0x2bc908 · jpeg_alloc_huff_table · size=36 · insn=9 */
/* @0x2bc908 push {r3, lr} */
/* @0x2bc90c mov r1, #0 */
/* @0x2bc910 ldr r3, [r0, #0x4] */
/* @0x2bc914 movw r2, #0x112 */
/* @0x2bc918 ldr r3, [r3] */
/* @0x2bc91c blx r3 */
/* @0x2bc920 mov r2, #0 */
/* @0x2bc924 strb r2, [r0, #0x111] */
/* @0x2bc928 pop {r3, pc} */

/* ── FUNC 0x2bc92c · anon_2bc92c · size=4212 · insn=1053 */
/* @0x2bc92c ldr r2, [r0, #0x124] */
/* @0x2bc930 ldr r3, [r0, #0x188] */
/* @0x2bc934 cmp r2, #1 */
/* @0x2bc938 ble 0x2bc954 <jpeg_alloc_huff_table+0x4c> */
/* @0x2bc93c mov r2, #1 */
/* @0x2bc940 str r2, [r3, #0x1c] */
/* @0x2bc944 mov r2, #0 */
/* @0x2bc948 str r2, [r3, #0x14] */
/* @0x2bc94c str r2, [r3, #0x18] */
/* @0x2bc950 bx lr */
/* @0x2bc954 ldr r2, [r0, #0x11c] */
/* @0x2bc958 ldr r1, [r0, #0x80] */
/* @0x2bc95c sub r2, r2, #1 */
/* @0x2bc960 cmp r1, r2 */
/* @0x2bc964 ldr r2, [r0, #0x128] */
/* @0x2bc968 ldrlo r2, [r2, #0xc] */
/* @0x2bc96c ldrhs r2, [r2, #0x48] */
/* @0x2bc970 str r2, [r3, #0x1c] */
/* @0x2bc974 b 0x2bc944 <jpeg_alloc_huff_table+0x3c> */
/* @0x2bc978 mov r2, #0 */
/* @0x2bc97c str r2, [r0, #0x80] */
/* @0x2bc980 b 0x2bc92c <jpeg_alloc_huff_table+0x24> */
/* @0x2bc984 mov r0, #0 */
/* @0x2bc988 bx lr */
/* @0x2bc98c ldr r3, [r0, #0x124] */
/* @0x2bc990 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2bc994 cmp r3, #0 */
/* @0x2bc998 sub sp, sp, #52 */
/* @0x2bc99c mov r11, r0 */
/* @0x2bc9a0 ldr r6, [r0, #0x188] */
/* @0x2bc9a4 ble 0x2bca04 <jpeg_alloc_huff_table+0xfc> */
/* @0x2bc9a8 add r8, sp, #32 */
/* @0x2bc9ac mov r5, r0 */
/* @0x2bc9b0 mov r4, #0 */
/* @0x2bc9b4 mov r7, #1 */
/* @0x2bc9b8 ldr r3, [r5, #0x128] */
/* @0x2bc9bc mov r0, r11 */
/* @0x2bc9c0 ldr lr, [r11, #0x80] */
/* @0x2bc9c4 add r5, r5, #4 */
/* @0x2bc9c8 ldr r12, [r11, #0x4] */
/* @0x2bc9cc ldr r1, [r3, #0x4] */
/* @0x2bc9d0 ldr r2, [r3, #0xc] */
/* @0x2bc9d4 add r3, r1, #18 */
/* @0x2bc9d8 ldr r1, [r6, r3, lsl #2] */
/* @0x2bc9dc mov r3, r2 */
/* @0x2bc9e0 str r7, [sp] */
/* @0x2bc9e4 mul r2, lr, r2 */
/* @0x2bc9e8 ldr r12, [r12, #0x20] */
/* @0x2bc9ec blx r12 */
/* @0x2bc9f0 ldr r3, [r11, #0x124] */
/* @0x2bc9f4 str r0, [r8, r4, lsl #2] */
/* @0x2bc9f8 add r4, r4, #1 */
/* @0x2bc9fc cmp r3, r4 */
/* @0x2bca00 bgt 0x2bc9b8 <jpeg_alloc_huff_table+0xb0> */
/* @0x2bca04 ldr r2, [r6, #0x18] */
/* @0x2bca08 str r2, [sp, #0x10] */
/* @0x2bca0c ldr r3, [sp, #0x10] */
/* @0x2bca10 ldr r2, [r6, #0x1c] */
/* @0x2bca14 cmp r3, r2 */
/* @0x2bca18 bge 0x2bcb88 <jpeg_alloc_huff_table+0x280> */
/* @0x2bca1c ldr r3, [r6, #0x14] */
/* @0x2bca20 add r1, r6, #32 */
/* @0x2bca24 str r11, [sp, #0x18] */
/* @0x2bca28 str r1, [sp, #0x1c] */
/* @0x2bca2c str r3, [sp, #0xc] */
/* @0x2bca30 ldr r3, [sp, #0x10] */
/* @0x2bca34 lsl r3, r3, #2 */
/* @0x2bca38 str r3, [sp, #0x14] */
/* @0x2bca3c ldr r3, [r11, #0x138] */
/* @0x2bca40 ldr r1, [sp, #0xc] */
/* @0x2bca44 cmp r3, r1 */
/* @0x2bca48 bls 0x2bcb34 <jpeg_alloc_huff_table+0x22c> */
/* @0x2bca4c ldr r3, [sp, #0x18] */
/* @0x2bca50 ldr r11, [r3, #0x124] */
/* @0x2bca54 cmp r11, #0 */
/* @0x2bca58 ble 0x2bcaf4 <jpeg_alloc_huff_table+0x1ec> */
/* @0x2bca5c mov r9, #0 */
/* @0x2bca60 lsl r11, r11, #2 */
/* @0x2bca64 mov lr, r9 */
/* @0x2bca68 mov r10, r3 */
/* @0x2bca6c ldr r3, [r10, #0x128] */
/* @0x2bca70 ldr r2, [r3, #0x38] */
/* @0x2bca74 ldr r4, [r3, #0x34] */
/* @0x2bca78 cmp r2, #0 */
/* @0x2bca7c ble 0x2bcae4 <jpeg_alloc_huff_table+0x1dc> */
/* @0x2bca80 ldr r3, [sp, #0x10] */
/* @0x2bca84 lsl r8, r4, #7 */
/* @0x2bca88 add r2, r3, r2 */
/* @0x2bca8c ldr r3, [sp, #0xc] */
/* @0x2bca90 mul r7, r3, r8 */
/* @0x2bca94 add r3, sp, #32 */
/* @0x2bca98 ldr r12, [r9, r3] */
/* @0x2bca9c add r5, r12, r2, lsl #2 */
/* @0x2bcaa0 ldr r2, [sp, #0x14] */
/* @0x2bcaa4 add r12, r12, r2 */
/* @0x2bcaa8 ldr r3, [r12], #4 */
/* @0x2bcaac cmp r4, #0 */
/* @0x2bcab0 add r3, r3, r7 */
/* @0x2bcab4 ble 0x2bcadc <jpeg_alloc_huff_table+0x1d4> */
/* @0x2bcab8 add r1, lr, #7 */
/* @0x2bcabc add r0, r3, r8 */
/* @0x2bcac0 add r1, r6, r1, lsl #2 */
/* @0x2bcac4 add r2, r3, #128 */
/* @0x2bcac8 str r3, [r1, #0x4]! */
/* @0x2bcacc cmp r2, r0 */
/* @0x2bcad0 mov r3, r2 */
/* @0x2bcad4 bne 0x2bcac4 <jpeg_alloc_huff_table+0x1bc> */
/* @0x2bcad8 add lr, r4, lr */
/* @0x2bcadc cmp r12, r5 */
/* @0x2bcae0 bne 0x2bcaa8 <jpeg_alloc_huff_table+0x1a0> */
/* @0x2bcae4 add r9, r9, #4 */
/* @0x2bcae8 add r10, r10, #4 */
/* @0x2bcaec cmp r9, r11 */
/* @0x2bcaf0 bne 0x2bca6c <jpeg_alloc_huff_table+0x164> */
/* @0x2bcaf4 ldr r2, [sp, #0x18] */
/* @0x2bcaf8 ldr r1, [sp, #0x1c] */
/* @0x2bcafc ldr r3, [r2, #0x198] */
/* @0x2bcb00 mov r0, r2 */
/* @0x2bcb04 ldr r3, [r3, #0x4] */
/* @0x2bcb08 blx r3 */
/* @0x2bcb0c cmp r0, #0 */
/* @0x2bcb10 beq 0x2bcb6c <jpeg_alloc_huff_table+0x264> */
/* @0x2bcb14 ldr r2, [sp, #0x18] */
/* @0x2bcb18 ldr r3, [r2, #0x138] */
/* @0x2bcb1c ldr r2, [sp, #0xc] */
/* @0x2bcb20 add r2, r2, #1 */
/* @0x2bcb24 str r2, [sp, #0xc] */
/* @0x2bcb28 cmp r3, r2 */
/* @0x2bcb2c bhi 0x2bca4c <jpeg_alloc_huff_table+0x144> */
/* @0x2bcb30 ldr r2, [r6, #0x1c] */
/* @0x2bcb34 ldr r1, [sp, #0x10] */
/* @0x2bcb38 add r1, r1, #1 */
/* @0x2bcb3c str r1, [sp, #0x10] */
/* @0x2bcb40 mov r1, #0 */
/* @0x2bcb44 str r1, [r6, #0x14] */
/* @0x2bcb48 ldr r1, [sp, #0x10] */
/* @0x2bcb4c cmp r2, r1 */
/* @0x2bcb50 ldr r1, [sp, #0x14] */
/* @0x2bcb54 add r1, r1, #4 */
/* @0x2bcb58 str r1, [sp, #0x14] */
/* @0x2bcb5c ble 0x2bcb84 <jpeg_alloc_huff_table+0x27c> */
/* @0x2bcb60 mov r1, #0 */
/* @0x2bcb64 str r1, [sp, #0xc] */
/* @0x2bcb68 b 0x2bca40 <jpeg_alloc_huff_table+0x138> */
/* @0x2bcb6c ldr r3, [sp, #0x10] */
/* @0x2bcb70 ldr r2, [sp, #0xc] */
/* @0x2bcb74 str r3, [r6, #0x18] */
/* @0x2bcb78 str r2, [r6, #0x14] */
/* @0x2bcb7c add sp, sp, #52 */
/* @0x2bcb80 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bcb84 ldr r11, [sp, #0x18] */
/* @0x2bcb88 ldr r3, [r11, #0x80] */
/* @0x2bcb8c ldr r2, [r11, #0x11c] */
/* @0x2bcb90 add r3, r3, #1 */
/* @0x2bcb94 str r3, [r11, #0x80] */
/* @0x2bcb98 cmp r3, r2 */
/* @0x2bcb9c bhs 0x2bcbb4 <jpeg_alloc_huff_table+0x2ac> */
/* @0x2bcba0 mov r0, r11 */
/* @0x2bcba4 bl 0x2bc92c <jpeg_alloc_huff_table+0x24> */
/* @0x2bcba8 mov r0, #3 */
/* @0x2bcbac add sp, sp, #52 */
/* @0x2bcbb0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bcbb4 ldr r3, [r11, #0x190] */
/* @0x2bcbb8 mov r0, r11 */
/* @0x2bcbbc ldr r3, [r3, #0xc] */
/* @0x2bcbc0 blx r3 */
/* @0x2bcbc4 mov r0, #4 */
/* @0x2bcbc8 add sp, sp, #52 */
/* @0x2bcbcc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bcbd0 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2bcbd4 mov r6, r0 */
/* @0x2bcbd8 ldr r7, [r0, #0x188] */
/* @0x2bcbdc ldr r3, [r7, #0x10] */
/* @0x2bcbe0 cmp r3, #0 */
/* @0x2bcbe4 beq 0x2bcc00 <jpeg_alloc_huff_table+0x2f8> */
/* @0x2bcbe8 ldrb r3, [r0, #0x49] */
/* @0x2bcbec cmp r3, #0 */
/* @0x2bcbf0 bne 0x2bcc0c <jpeg_alloc_huff_table+0x304> */
/* @0x2bcbf4 ldr r3, [pc, #0x174] */
/* @0x2bcbf8 add r3, pc, r3 */
/* @0x2bcbfc str r3, [r7, #0xc] */
/* @0x2bcc00 mov r3, #0 */
/* @0x2bcc04 str r3, [r6, #0x88] */
/* @0x2bcc08 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2bcc0c ldrb r3, [r0, #0xc8] */
/* @0x2bcc10 cmp r3, #0 */
/* @0x2bcc14 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec> */
/* @0x2bcc18 ldr r3, [r0, #0x8c] */
/* @0x2bcc1c cmp r3, #0 */
/* @0x2bcc20 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec> */
/* @0x2bcc24 ldr r9, [r7, #0x70] */
/* @0x2bcc28 cmp r9, #0 */
/* @0x2bcc2c beq 0x2bcd48 <jpeg_alloc_huff_table+0x440> */
/* @0x2bcc30 ldr r3, [r6, #0x24] */
/* @0x2bcc34 ldr r8, [r6, #0xc4] */
/* @0x2bcc38 cmp r3, #0 */
/* @0x2bcc3c ble 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec> */
/* @0x2bcc40 ldr r3, [r8, #0x4c] */
/* @0x2bcc44 cmp r3, #0 */
/* @0x2bcc48 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec> */
/* @0x2bcc4c ldrh r2, [r3] */
/* @0x2bcc50 cmp r2, #0 */
/* @0x2bcc54 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec> */
/* @0x2bcc58 ldrh r2, [r3, #2] */
/* @0x2bcc5c cmp r2, #0 */
/* @0x2bcc60 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec> */
/* @0x2bcc64 ldrh r2, [r3, #16] */
/* @0x2bcc68 cmp r2, #0 */
/* @0x2bcc6c beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec> */
/* @0x2bcc70 ldrh r2, [r3, #32] */
/* @0x2bcc74 cmp r2, #0 */
/* @0x2bcc78 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec> */
/* @0x2bcc7c mov r4, #0 */
/* @0x2bcc80 mov r0, r4 */
/* @0x2bcc84 ldrh r2, [r3, #18] */
/* @0x2bcc88 cmp r2, #0 */
/* @0x2bcc8c beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec> */
/* @0x2bcc90 ldrh r3, [r3, #4] */
/* @0x2bcc94 cmp r3, #0 */
/* @0x2bcc98 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec> */
/* @0x2bcc9c ldr r3, [r6, #0x8c] */
/* @0x2bcca0 add r2, r3, r0, lsl #8 */
/* @0x2bcca4 ldr r3, [r3, r0, lsl #8] */
/* @0x2bcca8 cmp r3, #0 */
/* @0x2bccac blt 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec> */
/* @0x2bccb0 mov r12, r9 */
/* @0x2bccb4 mov r1, r2 */
/* @0x2bccb8 mov r3, #5 */
/* @0x2bccbc ldr r5, [r2, #0x4]! */
/* @0x2bccc0 str r5, [r12, #0x4]! */
/* @0x2bccc4 ldr r5, [r1, #0x4]! */
/* @0x2bccc8 cmp r5, #0 */
/* @0x2bcccc movne r4, #1 */
/* @0x2bccd0 subs r3, r3, #1 */
/* @0x2bccd4 bne 0x2bccbc <jpeg_alloc_huff_table+0x3b4> */
/* @0x2bccd8 ldr r3, [r6, #0x24] */
/* @0x2bccdc add r0, r0, #1 */
/* @0x2bcce0 add r9, r9, #24 */
/* @0x2bcce4 add r8, r8, #84 */
/* @0x2bcce8 cmp r0, r3 */
/* @0x2bccec bge 0x2bcd30 <jpeg_alloc_huff_table+0x428> */
/* @0x2bccf0 ldr r3, [r8, #0x4c] */
/* @0x2bccf4 cmp r3, #0 */
/* @0x2bccf8 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec> */
/* @0x2bccfc ldrh r2, [r3] */
/* @0x2bcd00 cmp r2, #0 */
/* @0x2bcd04 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec> */
/* @0x2bcd08 ldrh r2, [r3, #2] */
/* @0x2bcd0c cmp r2, #0 */
/* @0x2bcd10 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec> */
/* @0x2bcd14 ldrh r2, [r3, #16] */
/* @0x2bcd18 cmp r2, #0 */
/* @0x2bcd1c beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec> */
/* @0x2bcd20 ldrh r2, [r3, #32] */
/* @0x2bcd24 cmp r2, #0 */
/* @0x2bcd28 bne 0x2bcc84 <jpeg_alloc_huff_table+0x37c> */
/* @0x2bcd2c b 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec> */
/* @0x2bcd30 cmp r4, #0 */
/* @0x2bcd34 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec> */
/* @0x2bcd38 ldr r3, [pc, #0x34] */
/* @0x2bcd3c add r3, pc, r3 */
/* @0x2bcd40 str r3, [r7, #0xc] */
/* @0x2bcd44 b 0x2bcc00 <jpeg_alloc_huff_table+0x2f8> */
/* @0x2bcd48 ldr r3, [r0, #0x24] */
/* @0x2bcd4c mov r1, #1 */
/* @0x2bcd50 ldr r12, [r0, #0x4] */
/* @0x2bcd54 add r2, r3, r3, lsl #1 */
/* @0x2bcd58 ldr r12, [r12] */
/* @0x2bcd5c lsl r2, r2, #3 */
/* @0x2bcd60 blx r12 */
/* @0x2bcd64 mov r9, r0 */
/* @0x2bcd68 str r0, [r7, #0x70] */
/* @0x2bcd6c b 0x2bcc30 <jpeg_alloc_huff_table+0x328> */
/* @0x2bcd70 ldrdeq r0, r1, [r0], -r8 */
/* @0x2bcd74 andeq r0, r0, r4, lsr r0 */
/* @0x2bcd78 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2bcd7c sub sp, sp, #292 */
/* @0x2bcd80 ldr r4, [r0, #0x188] */
/* @0x2bcd84 mov r6, r0 */
/* @0x2bcd88 str r0, [sp, #0x38] */
/* @0x2bcd8c str r1, [sp, #0x98] */
/* @0x2bcd90 str r4, [sp, #0x94] */
/* @0x2bcd94 ldr r4, [r0, #0x11c] */
/* @0x2bcd98 b 0x2bcde4 <jpeg_alloc_huff_table+0x4dc> */
/* @0x2bcd9c ldr r1, [r6, #0x190] */
/* @0x2bcda0 ldrb r12, [r1, #0x11] */
/* @0x2bcda4 cmp r12, #0 */
/* @0x2bcda8 bne 0x2bcdf8 <jpeg_alloc_huff_table+0x4f0> */
/* @0x2bcdac cmp r3, r2 */
/* @0x2bcdb0 bne 0x2bcdd4 <jpeg_alloc_huff_table+0x4cc> */
/* @0x2bcdb4 ldr r5, [r6, #0x88] */
/* @0x2bcdb8 ldr r3, [r6, #0x16c] */
/* @0x2bcdbc ldr r2, [r6, #0x80] */
/* @0x2bcdc0 cmp r3, #0 */
/* @0x2bcdc4 movne r3, r5 */
/* @0x2bcdc8 addeq r3, r5, #1 */
/* @0x2bcdcc cmp r2, r3 */
/* @0x2bcdd0 bhi 0x2bce00 <jpeg_alloc_huff_table+0x4f8> */
/* @0x2bcdd4 ldr r3, [r1] */
/* @0x2bcdd8 blx r3 */
/* @0x2bcddc cmp r0, #0 */
/* @0x2bcde0 beq 0x2bd344 <jpeg_alloc_huff_table+0xa3c> */
/* @0x2bcde4 ldr r3, [r6, #0x7c] */
/* @0x2bcde8 mov r0, r6 */
/* @0x2bcdec ldr r2, [r6, #0x84] */
/* @0x2bcdf0 cmp r3, r2 */
/* @0x2bcdf4 ble 0x2bcd9c <jpeg_alloc_huff_table+0x494> */
/* @0x2bcdf8 ldr r12, [sp, #0x38] */
/* @0x2bcdfc ldr r5, [r12, #0x88] */
/* @0x2bce00 ldr r12, [sp, #0x38] */
/* @0x2bce04 ldr r2, [r12, #0x24] */
/* @0x2bce08 ldr r12, [r12, #0xc4] */
/* @0x2bce0c cmp r2, #0 */
/* @0x2bce10 str r12, [sp, #0xc] */
/* @0x2bce14 ble 0x2bd328 <jpeg_alloc_huff_table+0xa20> */
/* @0x2bce18 sub r4, r4, #1 */
/* @0x2bce1c str r4, [sp, #0x9c] */
/* @0x2bce20 mov r4, #0 */
/* @0x2bce24 str r4, [sp, #0x88] */
/* @0x2bce28 ldr r4, [sp, #0x94] */
/* @0x2bce2c add r12, sp, #160 */
/* @0x2bce30 str r12, [sp, #0x1c] */
/* @0x2bce34 str r4, [sp, #0x90] */
/* @0x2bce38 ldr r12, [sp, #0xc] */
/* @0x2bce3c ldrb r3, [r12, #0x30] */
/* @0x2bce40 cmp r3, #0 */
/* @0x2bce44 beq 0x2bd2fc <jpeg_alloc_huff_table+0x9f4> */
/* @0x2bce48 ldr r4, [sp, #0x9c] */
/* @0x2bce4c cmp r4, r5 */
/* @0x2bce50 bls 0x2bd450 <jpeg_alloc_huff_table+0xb48> */
/* @0x2bce54 ldr r4, [r12, #0xc] */
/* @0x2bce58 mov r12, #0 */
/* @0x2bce5c str r12, [sp, #0x80] */
/* @0x2bce60 cmp r5, #0 */
/* @0x2bce64 ldr r12, [sp, #0x90] */
/* @0x2bce68 str r4, [sp, #0x7c] */
/* @0x2bce6c lsl r3, r4, #1 */
/* @0x2bce70 ldr r1, [r12, #0x48] */
/* @0x2bce74 beq 0x2bd498 <jpeg_alloc_huff_table+0xb90> */
/* @0x2bce78 ldr lr, [sp, #0x38] */
/* @0x2bce7c sub r2, r5, #1 */
/* @0x2bce80 add r3, r4, r3 */
/* @0x2bce84 mov r0, #0 */
/* @0x2bce88 mul r2, r2, r4 */
/* @0x2bce8c ldr r12, [lr, #0x4] */
/* @0x2bce90 str r0, [sp] */
/* @0x2bce94 mov r0, lr */
/* @0x2bce98 mov r6, #0 */
/* @0x2bce9c ldr r12, [r12, #0x20] */
/* @0x2bcea0 blx r12 */
/* @0x2bcea4 ldr r4, [sp, #0xc] */
/* @0x2bcea8 ldr r5, [r4, #0xc] */
/* @0x2bceac add r5, r0, r5, lsl #2 */
/* @0x2bceb0 ldr r12, [sp, #0x38] */
/* @0x2bceb4 ldr r4, [sp, #0x7c] */
/* @0x2bceb8 ldr r1, [r12, #0x19c] */
/* @0x2bcebc cmp r4, #0 */
/* @0x2bcec0 ldr r12, [sp, #0xc] */
/* @0x2bcec4 ldr r4, [sp, #0x88] */
/* @0x2bcec8 ldr r3, [r12, #0x4c] */
/* @0x2bcecc ldr r12, [sp, #0x94] */
/* @0x2bced0 add r1, r1, r4, lsl #2 */
/* @0x2bced4 add r2, r4, r4, lsl #1 */
/* @0x2bced8 ldr r1, [r1, #0x4] */
/* @0x2bcedc ldr r0, [r12, #0x70] */
/* @0x2bcee0 ldr r12, [sp, #0x98] */
/* @0x2bcee4 add r11, r0, r2, lsl #3 */
/* @0x2bcee8 str r1, [sp, #0x3c] */
/* @0x2bceec ldrh r0, [r3, #16] */
/* @0x2bcef0 ldr r4, [r12, r4, lsl #2] */
/* @0x2bcef4 ldrh r1, [r3, #32] */
/* @0x2bcef8 ldrh r12, [r3, #2] */
/* @0x2bcefc str r4, [sp, #0x2c] */
/* @0x2bcf00 ldrh r2, [r3, #18] */
/* @0x2bcf04 ldrh r4, [r3] */
/* @0x2bcf08 ldrh r3, [r3, #4] */
/* @0x2bcf0c ble 0x2bd2f0 <jpeg_alloc_huff_table+0x9e8> */
/* @0x2bcf10 add lr, r4, r4, lsl #3 */
/* @0x2bcf14 add r4, r4, r4, lsl #2 */
/* @0x2bcf18 str r4, [sp, #0x68] */
/* @0x2bcf1c lsl r4, r12, #7 */
/* @0x2bcf20 lsl r12, r12, #8 */
/* @0x2bcf24 str r12, [sp, #0x54] */
/* @0x2bcf28 lsl r12, r0, #7 */
/* @0x2bcf2c str r12, [sp, #0x58] */
/* @0x2bcf30 lsl r12, r2, #7 */
/* @0x2bcf34 str r12, [sp, #0x6c] */
/* @0x2bcf38 ldr r12, [sp, #0x7c] */
/* @0x2bcf3c sub r5, r5, #4 */
/* @0x2bcf40 str r4, [sp, #0x50] */
/* @0x2bcf44 lsl r0, r0, #8 */
/* @0x2bcf48 lsl r4, lr, #2 */
/* @0x2bcf4c lsl r2, r2, #8 */
/* @0x2bcf50 str r4, [sp, #0x44] */
/* @0x2bcf54 sub r12, r12, #1 */
/* @0x2bcf58 lsl r4, r1, #7 */
/* @0x2bcf5c str lr, [sp, #0x40] */
/* @0x2bcf60 str r4, [sp, #0x60] */
/* @0x2bcf64 lsl r1, r1, #8 */
/* @0x2bcf68 lsl r4, r3, #7 */
/* @0x2bcf6c str r5, [sp, #0x4c] */
/* @0x2bcf70 str r4, [sp, #0x74] */
/* @0x2bcf74 lsl r3, r3, #8 */
/* @0x2bcf78 mov r4, #0 */
/* @0x2bcf7c str r0, [sp, #0x5c] */
/* @0x2bcf80 str r1, [sp, #0x64] */
/* @0x2bcf84 str r2, [sp, #0x70] */
/* @0x2bcf88 str r3, [sp, #0x78] */
/* @0x2bcf8c str r12, [sp, #0x8c] */
/* @0x2bcf90 str r6, [sp, #0x84] */
/* @0x2bcf94 str r4, [sp, #0x48] */
/* @0x2bcf98 ldr r4, [sp, #0x4c] */
/* @0x2bcf9c ldr r12, [sp, #0x48] */
/* @0x2bcfa0 ldr r3, [sp, #0x84] */
/* @0x2bcfa4 ldr r5, [r4, #0x4]! */
/* @0x2bcfa8 cmp r12, #0 */
/* @0x2bcfac movne r3, #0 */
/* @0x2bcfb0 andeq r3, r3, #1 */
/* @0x2bcfb4 cmp r3, #0 */
/* @0x2bcfb8 str r4, [sp, #0x4c] */
/* @0x2bcfbc ldreq r12, [r4, #-0x4] */
/* @0x2bcfc0 ldr r4, [sp, #0x80] */
/* @0x2bcfc4 strne r5, [sp, #0x34] */
/* @0x2bcfc8 streq r12, [sp, #0x34] */
/* @0x2bcfcc cmp r4, #0 */
/* @0x2bcfd0 beq 0x2bcfe4 <jpeg_alloc_huff_table+0x6dc> */
/* @0x2bcfd4 ldr r12, [sp, #0x8c] */
/* @0x2bcfd8 ldr r4, [sp, #0x48] */
/* @0x2bcfdc cmp r12, r4 */
/* @0x2bcfe0 beq 0x2bd4d0 <jpeg_alloc_huff_table+0xbc8> */
/* @0x2bcfe4 ldr r12, [sp, #0x4c] */
/* @0x2bcfe8 ldr r12, [r12, #0x4] */
/* @0x2bcfec str r12, [sp, #0x30] */
/* @0x2bcff0 ldr r12, [sp, #0x30] */
/* @0x2bcff4 mov r6, #0 */
/* @0x2bcff8 ldr r4, [sp, #0x34] */
/* @0x2bcffc ldrsh r10, [r5] */
/* @0x2bd000 ldrsh r7, [r12] */
/* @0x2bd004 ldr r12, [sp, #0xc] */
/* @0x2bd008 ldrsh r9, [r4] */
/* @0x2bd00c mov r4, r6 */
/* @0x2bd010 str r10, [sp, #0x20] */
/* @0x2bd014 ldr r3, [r12, #0x1c] */
/* @0x2bd018 str r9, [sp, #0x28] */
/* @0x2bd01c sub r3, r3, #1 */
/* @0x2bd020 str r7, [sp, #0x24] */
/* @0x2bd024 str r3, [sp, #0x18] */
/* @0x2bd028 b 0x2bd044 <jpeg_alloc_huff_table+0x73c> */
/* @0x2bd02c str r7, [sp, #0x24] */
/* @0x2bd030 str r9, [sp, #0x28] */
/* @0x2bd034 ldr r7, [sp, #0x14] */
/* @0x2bd038 ldr r9, [sp, #0x10] */
/* @0x2bd03c str r10, [sp, #0x20] */
/* @0x2bd040 mov r10, r8 */
/* @0x2bd044 mov r0, r5 */
/* @0x2bd048 add r1, sp, #160 */
/* @0x2bd04c mov r2, #1 */
/* @0x2bd050 bl 0x2bc854 <jcopy_block_row> */
/* @0x2bd054 ldr r12, [sp, #0x18] */
/* @0x2bd058 cmp r12, r4 */
/* @0x2bd05c bls 0x2bd4c0 <jpeg_alloc_huff_table+0xbb8> */
/* @0x2bd060 ldr r12, [sp, #0x34] */
/* @0x2bd064 lsl r3, r4, #7 */
/* @0x2bd068 ldrsh r8, [r5, #128] */
/* @0x2bd06c add r1, r12, #128 */
/* @0x2bd070 ldr r12, [sp, #0x30] */
/* @0x2bd074 add r2, r12, #128 */
/* @0x2bd078 ldrsh r1, [r1, r3] */
/* @0x2bd07c ldrsh r2, [r2, r3] */
/* @0x2bd080 str r1, [sp, #0x10] */
/* @0x2bd084 str r2, [sp, #0x14] */
/* @0x2bd088 ldr r3, [r11, #0x4] */
/* @0x2bd08c cmp r3, #0 */
/* @0x2bd090 beq 0x2bd0ec <jpeg_alloc_huff_table+0x7e4> */
/* @0x2bd094 ldrsh r2, [sp, #162] */
/* @0x2bd098 cmp r2, #0 */
/* @0x2bd09c bne 0x2bd0ec <jpeg_alloc_huff_table+0x7e4> */
/* @0x2bd0a0 ldr r12, [sp, #0x20] */
/* @0x2bd0a4 rsb r0, r8, r12 */
/* @0x2bd0a8 ldr r12, [sp, #0x44] */
/* @0x2bd0ac mul r0, r0, r12 */
/* @0x2bd0b0 ldr r12, [sp, #0x50] */
/* @0x2bd0b4 cmp r0, #0 */
/* @0x2bd0b8 blt 0x2bd380 <jpeg_alloc_huff_table+0xa78> */
/* @0x2bd0bc add r0, r12, r0 */
/* @0x2bd0c0 ldr r1, [sp, #0x54] */
/* @0x2bd0c4 str r3, [sp, #0x8] */
/* @0x2bd0c8 bl 0x318d10 <__divsi3> */
/* @0x2bd0cc ldr r3, [sp, #0x8] */
/* @0x2bd0d0 cmp r3, #0 */
/* @0x2bd0d4 ble 0x2bd0e8 <jpeg_alloc_huff_table+0x7e0> */
/* @0x2bd0d8 mov lr, #1 */
/* @0x2bd0dc lsl r3, lr, r3 */
/* @0x2bd0e0 cmp r0, r3 */
/* @0x2bd0e4 subge r0, r3, #1 */
/* @0x2bd0e8 strh r0, [sp, #162] */
/* @0x2bd0ec ldr r3, [r11, #0x8] */
/* @0x2bd0f0 cmp r3, #0 */
/* @0x2bd0f4 beq 0x2bd14c <jpeg_alloc_huff_table+0x844> */
/* @0x2bd0f8 ldrsh r2, [sp, #176] */
/* @0x2bd0fc cmp r2, #0 */
/* @0x2bd100 bne 0x2bd14c <jpeg_alloc_huff_table+0x844> */
/* @0x2bd104 ldr r12, [sp, #0x44] */
/* @0x2bd108 rsb r0, r7, r9 */
/* @0x2bd10c mul r0, r0, r12 */
/* @0x2bd110 ldr r12, [sp, #0x58] */
/* @0x2bd114 cmp r0, #0 */
/* @0x2bd118 blt 0x2bd34c <jpeg_alloc_huff_table+0xa44> */
/* @0x2bd11c add r0, r12, r0 */
/* @0x2bd120 ldr r1, [sp, #0x5c] */
/* @0x2bd124 str r3, [sp, #0x8] */
/* @0x2bd128 bl 0x318d10 <__divsi3> */
/* @0x2bd12c ldr r3, [sp, #0x8] */
/* @0x2bd130 cmp r3, #0 */
/* @0x2bd134 ble 0x2bd148 <jpeg_alloc_huff_table+0x840> */
/* @0x2bd138 mov lr, #1 */
/* @0x2bd13c lsl r3, lr, r3 */
/* @0x2bd140 cmp r0, r3 */
/* @0x2bd144 subge r0, r3, #1 */
/* @0x2bd148 strh r0, [sp, #176] */
/* @0x2bd14c ldr r3, [r11, #0xc] */
/* @0x2bd150 cmp r3, #0 */
/* @0x2bd154 beq 0x2bd1b0 <jpeg_alloc_huff_table+0x8a8> */
/* @0x2bd158 ldrsh r2, [sp, #192] */
/* @0x2bd15c cmp r2, #0 */
/* @0x2bd160 bne 0x2bd1b0 <jpeg_alloc_huff_table+0x8a8> */
/* @0x2bd164 add r0, r9, r7 */
/* @0x2bd168 ldr r12, [sp, #0x40] */
/* @0x2bd16c sub r0, r0, r10, lsl #1 */
/* @0x2bd170 mul r0, r0, r12 */
/* @0x2bd174 ldr r12, [sp, #0x60] */
/* @0x2bd178 cmp r0, #0 */
/* @0x2bd17c blt 0x2bd3e8 <jpeg_alloc_huff_table+0xae0> */
/* @0x2bd180 add r0, r12, r0 */
/* @0x2bd184 ldr r1, [sp, #0x64] */
/* @0x2bd188 str r3, [sp, #0x8] */
/* @0x2bd18c bl 0x318d10 <__divsi3> */
/* @0x2bd190 ldr r3, [sp, #0x8] */
/* @0x2bd194 cmp r3, #0 */
/* @0x2bd198 ble 0x2bd1ac <jpeg_alloc_huff_table+0x8a4> */
/* @0x2bd19c mov lr, #1 */
/* @0x2bd1a0 lsl r3, lr, r3 */
/* @0x2bd1a4 cmp r0, r3 */
/* @0x2bd1a8 subge r0, r3, #1 */
/* @0x2bd1ac strh r0, [sp, #192] */
/* @0x2bd1b0 ldr r3, [r11, #0x10] */
/* @0x2bd1b4 cmp r3, #0 */
/* @0x2bd1b8 beq 0x2bd228 <jpeg_alloc_huff_table+0x920> */
/* @0x2bd1bc ldrsh r2, [sp, #178] */
/* @0x2bd1c0 cmp r2, #0 */
/* @0x2bd1c4 bne 0x2bd228 <jpeg_alloc_huff_table+0x920> */
/* @0x2bd1c8 ldr r12, [sp, #0x28] */
/* @0x2bd1cc ldr lr, [sp, #0x10] */
/* @0x2bd1d0 rsb r0, lr, r12 */
/* @0x2bd1d4 ldr r12, [sp, #0x24] */
/* @0x2bd1d8 rsb r0, r12, r0 */
/* @0x2bd1dc ldr r12, [sp, #0x14] */
/* @0x2bd1e0 add r0, r0, r12 */
/* @0x2bd1e4 ldr r12, [sp, #0x68] */
/* @0x2bd1e8 mul r0, r0, r12 */
/* @0x2bd1ec ldr r12, [sp, #0x6c] */
/* @0x2bd1f0 cmp r0, #0 */
/* @0x2bd1f4 blt 0x2bd3b4 <jpeg_alloc_huff_table+0xaac> */
/* @0x2bd1f8 add r0, r12, r0 */
/* @0x2bd1fc ldr r1, [sp, #0x70] */
/* @0x2bd200 str r3, [sp, #0x8] */
/* @0x2bd204 bl 0x318d10 <__divsi3> */
/* @0x2bd208 ldr r3, [sp, #0x8] */
/* @0x2bd20c cmp r3, #0 */
/* @0x2bd210 ble 0x2bd224 <jpeg_alloc_huff_table+0x91c> */
/* @0x2bd214 mov lr, #1 */
/* @0x2bd218 lsl r3, lr, r3 */
/* @0x2bd21c cmp r0, r3 */
/* @0x2bd220 subge r0, r3, #1 */
/* @0x2bd224 strh r0, [sp, #178] */
/* @0x2bd228 ldr r3, [r11, #0x14] */
/* @0x2bd22c cmp r3, #0 */
/* @0x2bd230 beq 0x2bd290 <jpeg_alloc_huff_table+0x988> */
/* @0x2bd234 ldrsh r2, [sp, #164] */
/* @0x2bd238 cmp r2, #0 */
/* @0x2bd23c bne 0x2bd290 <jpeg_alloc_huff_table+0x988> */
/* @0x2bd240 ldr r12, [sp, #0x20] */
/* @0x2bd244 add r0, r12, r8 */
/* @0x2bd248 ldr r12, [sp, #0x40] */
/* @0x2bd24c sub r0, r0, r10, lsl #1 */
/* @0x2bd250 mul r0, r0, r12 */
/* @0x2bd254 ldr r12, [sp, #0x74] */
/* @0x2bd258 cmp r0, #0 */
/* @0x2bd25c blt 0x2bd41c <jpeg_alloc_huff_table+0xb14> */
/* @0x2bd260 add r0, r12, r0 */
/* @0x2bd264 ldr r1, [sp, #0x78] */
/* @0x2bd268 str r3, [sp, #0x8] */
/* @0x2bd26c bl 0x318d10 <__divsi3> */
/* @0x2bd270 ldr r3, [sp, #0x8] */
/* @0x2bd274 cmp r3, #0 */
/* @0x2bd278 ble 0x2bd28c <jpeg_alloc_huff_table+0x984> */
/* @0x2bd27c mov lr, #1 */
/* @0x2bd280 lsl r3, lr, r3 */
/* @0x2bd284 cmp r0, r3 */
/* @0x2bd288 subge r0, r3, #1 */
/* @0x2bd28c strh r0, [sp, #164] */
/* @0x2bd290 str r6, [sp] */
/* @0x2bd294 add r2, sp, #160 */
/* @0x2bd298 ldr r3, [sp, #0x2c] */
/* @0x2bd29c add r4, r4, #1 */
/* @0x2bd2a0 ldr r12, [sp, #0x3c] */
/* @0x2bd2a4 add r5, r5, #128 */
/* @0x2bd2a8 ldr r0, [sp, #0x38] */
/* @0x2bd2ac ldr r1, [sp, #0xc] */
/* @0x2bd2b0 blx r12 */
/* @0x2bd2b4 ldr r12, [sp, #0x18] */
/* @0x2bd2b8 cmp r12, r4 */
/* @0x2bd2bc ldr r12, [sp, #0xc] */
/* @0x2bd2c0 ldr r3, [r12, #0x24] */
/* @0x2bd2c4 add r6, r6, r3 */
/* @0x2bd2c8 bhs 0x2bd02c <jpeg_alloc_huff_table+0x724> */
/* @0x2bd2cc ldr r12, [sp, #0x2c] */
/* @0x2bd2d0 ldr r4, [sp, #0x48] */
/* @0x2bd2d4 add r12, r12, r3, lsl #2 */
/* @0x2bd2d8 str r12, [sp, #0x2c] */
/* @0x2bd2dc ldr r12, [sp, #0x7c] */
/* @0x2bd2e0 add r4, r4, #1 */
/* @0x2bd2e4 str r4, [sp, #0x48] */
/* @0x2bd2e8 cmp r4, r12 */
/* @0x2bd2ec bne 0x2bcf98 <jpeg_alloc_huff_table+0x690> */
/* @0x2bd2f0 ldr r4, [sp, #0x38] */
/* @0x2bd2f4 ldr r5, [r4, #0x88] */
/* @0x2bd2f8 ldr r2, [r4, #0x24] */
/* @0x2bd2fc ldr r12, [sp, #0x88] */
/* @0x2bd300 ldr r4, [sp, #0xc] */
/* @0x2bd304 add r12, r12, #1 */
/* @0x2bd308 str r12, [sp, #0x88] */
/* @0x2bd30c cmp r2, r12 */
/* @0x2bd310 ldr r12, [sp, #0x90] */
/* @0x2bd314 add r4, r4, #84 */
/* @0x2bd318 str r4, [sp, #0xc] */
/* @0x2bd31c add r12, r12, #4 */
/* @0x2bd320 str r12, [sp, #0x90] */
/* @0x2bd324 bgt 0x2bce38 <jpeg_alloc_huff_table+0x530> */
/* @0x2bd328 ldr r4, [sp, #0x38] */
/* @0x2bd32c add r5, r5, #1 */
/* @0x2bd330 ldr r0, [r4, #0x11c] */
/* @0x2bd334 str r5, [r4, #0x88] */
/* @0x2bd338 cmp r5, r0 */
/* @0x2bd33c movhs r0, #4 */
/* @0x2bd340 movlo r0, #3 */
/* @0x2bd344 add sp, sp, #292 */
/* @0x2bd348 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bd34c rsb r0, r0, r12 */
/* @0x2bd350 ldr r1, [sp, #0x5c] */
/* @0x2bd354 str r3, [sp, #0x8] */
/* @0x2bd358 bl 0x318d10 <__divsi3> */
/* @0x2bd35c ldr r3, [sp, #0x8] */
/* @0x2bd360 cmp r3, #0 */
/* @0x2bd364 ble 0x2bd378 <jpeg_alloc_huff_table+0xa70> */
/* @0x2bd368 mov lr, #1 */
/* @0x2bd36c lsl r3, lr, r3 */
/* @0x2bd370 cmp r0, r3 */
/* @0x2bd374 subge r0, r3, #1 */
/* @0x2bd378 rsb r0, r0, #0 */
/* @0x2bd37c b 0x2bd148 <jpeg_alloc_huff_table+0x840> */
/* @0x2bd380 rsb r0, r0, r12 */
/* @0x2bd384 ldr r1, [sp, #0x54] */
/* @0x2bd388 str r3, [sp, #0x8] */
/* @0x2bd38c bl 0x318d10 <__divsi3> */
/* @0x2bd390 ldr r3, [sp, #0x8] */
/* @0x2bd394 cmp r3, #0 */
/* @0x2bd398 ble 0x2bd3ac <jpeg_alloc_huff_table+0xaa4> */
/* @0x2bd39c mov lr, #1 */
/* @0x2bd3a0 lsl r3, lr, r3 */
/* @0x2bd3a4 cmp r0, r3 */
/* @0x2bd3a8 subge r0, r3, #1 */
/* @0x2bd3ac rsb r0, r0, #0 */
/* @0x2bd3b0 b 0x2bd0e8 <jpeg_alloc_huff_table+0x7e0> */
/* @0x2bd3b4 rsb r0, r0, r12 */
/* @0x2bd3b8 ldr r1, [sp, #0x70] */
/* @0x2bd3bc str r3, [sp, #0x8] */
/* @0x2bd3c0 bl 0x318d10 <__divsi3> */
/* @0x2bd3c4 ldr r3, [sp, #0x8] */
/* @0x2bd3c8 cmp r3, #0 */
/* @0x2bd3cc ble 0x2bd3e0 <jpeg_alloc_huff_table+0xad8> */
/* @0x2bd3d0 mov lr, #1 */
/* @0x2bd3d4 lsl r3, lr, r3 */
/* @0x2bd3d8 cmp r0, r3 */
/* @0x2bd3dc subge r0, r3, #1 */
/* @0x2bd3e0 rsb r0, r0, #0 */
/* @0x2bd3e4 b 0x2bd224 <jpeg_alloc_huff_table+0x91c> */
/* @0x2bd3e8 rsb r0, r0, r12 */
/* @0x2bd3ec ldr r1, [sp, #0x64] */
/* @0x2bd3f0 str r3, [sp, #0x8] */
/* @0x2bd3f4 bl 0x318d10 <__divsi3> */
/* @0x2bd3f8 ldr r3, [sp, #0x8] */
/* @0x2bd3fc cmp r3, #0 */
/* @0x2bd400 ble 0x2bd414 <jpeg_alloc_huff_table+0xb0c> */
/* @0x2bd404 mov lr, #1 */
/* @0x2bd408 lsl r3, lr, r3 */
/* @0x2bd40c cmp r0, r3 */
/* @0x2bd410 subge r0, r3, #1 */
/* @0x2bd414 rsb r0, r0, #0 */
/* @0x2bd418 b 0x2bd1ac <jpeg_alloc_huff_table+0x8a4> */
/* @0x2bd41c rsb r0, r0, r12 */
/* @0x2bd420 ldr r1, [sp, #0x78] */
/* @0x2bd424 str r3, [sp, #0x8] */
/* @0x2bd428 bl 0x318d10 <__divsi3> */
/* @0x2bd42c ldr r3, [sp, #0x8] */
/* @0x2bd430 cmp r3, #0 */
/* @0x2bd434 ble 0x2bd448 <jpeg_alloc_huff_table+0xb40> */
/* @0x2bd438 mov lr, #1 */
/* @0x2bd43c lsl r3, lr, r3 */
/* @0x2bd440 cmp r0, r3 */
/* @0x2bd444 subge r0, r3, #1 */
/* @0x2bd448 rsb r0, r0, #0 */
/* @0x2bd44c b 0x2bd28c <jpeg_alloc_huff_table+0x984> */
/* @0x2bd450 ldr r12, [sp, #0xc] */
/* @0x2bd454 ldr r4, [r12, #0xc] */
/* @0x2bd458 mov r12, #1 */
/* @0x2bd45c str r12, [sp, #0x80] */
/* @0x2bd460 ldr r12, [sp, #0xc] */
/* @0x2bd464 mov r1, r4 */
/* @0x2bd468 ldr r0, [r12, #0x20] */
/* @0x2bd46c bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x2bd470 cmp r1, #0 */
/* @0x2bd474 moveq r12, r4 */
/* @0x2bd478 movne r12, r1 */
/* @0x2bd47c str r12, [sp, #0x7c] */
/* @0x2bd480 ldr r12, [sp, #0x90] */
/* @0x2bd484 moveq r3, r4 */
/* @0x2bd488 movne r3, r1 */
/* @0x2bd48c cmp r5, #0 */
/* @0x2bd490 ldr r1, [r12, #0x48] */
/* @0x2bd494 bne 0x2bce78 <jpeg_alloc_huff_table+0x570> */
/* @0x2bd498 ldr r4, [sp, #0x38] */
/* @0x2bd49c mov r2, r5 */
/* @0x2bd4a0 mov r6, #1 */
/* @0x2bd4a4 ldr r12, [r4, #0x4] */
/* @0x2bd4a8 mov r0, r4 */
/* @0x2bd4ac str r5, [sp] */
/* @0x2bd4b0 ldr r12, [r12, #0x20] */
/* @0x2bd4b4 blx r12 */
/* @0x2bd4b8 mov r5, r0 */
/* @0x2bd4bc b 0x2bceb0 <jpeg_alloc_huff_table+0x5a8> */
/* @0x2bd4c0 str r7, [sp, #0x14] */
/* @0x2bd4c4 mov r8, r10 */
/* @0x2bd4c8 str r9, [sp, #0x10] */
/* @0x2bd4cc b 0x2bd088 <jpeg_alloc_huff_table+0x780> */
/* @0x2bd4d0 str r5, [sp, #0x30] */
/* @0x2bd4d4 b 0x2bcff0 <jpeg_alloc_huff_table+0x6e8> */
/* @0x2bd4d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2bd4dc sub sp, sp, #36 */
/* @0x2bd4e0 ldr r4, [r0, #0x188] */
/* @0x2bd4e4 mov r11, r0 */
/* @0x2bd4e8 ldr r6, [r0, #0x11c] */
/* @0x2bd4ec str r1, [sp, #0x18] */
/* @0x2bd4f0 ldr r2, [r11, #0x7c] */
/* @0x2bd4f4 mov r0, r11 */
/* @0x2bd4f8 ldr r3, [r11, #0x84] */
/* @0x2bd4fc cmp r2, r3 */
/* @0x2bd500 blt 0x2bd518 <jpeg_alloc_huff_table+0xc10> */
/* @0x2bd504 bne 0x2bd534 <jpeg_alloc_huff_table+0xc2c> */
/* @0x2bd508 ldr r3, [r11, #0x88] */
/* @0x2bd50c ldr r2, [r11, #0x80] */
/* @0x2bd510 cmp r2, r3 */
/* @0x2bd514 bhi 0x2bd6b8 <jpeg_alloc_huff_table+0xdb0> */
/* @0x2bd518 ldr r3, [r11, #0x190] */
/* @0x2bd51c ldr r3, [r3] */
/* @0x2bd520 blx r3 */
/* @0x2bd524 cmp r0, #0 */
/* @0x2bd528 bne 0x2bd4f0 <jpeg_alloc_huff_table+0xbe8> */
/* @0x2bd52c add sp, sp, #36 */
/* @0x2bd530 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bd534 ldr r2, [r11, #0x88] */
/* @0x2bd538 ldr r0, [r11, #0x24] */
/* @0x2bd53c ldr r5, [r11, #0xc4] */
/* @0x2bd540 cmp r0, #0 */
/* @0x2bd544 ble 0x2bd698 <jpeg_alloc_huff_table+0xd90> */
/* @0x2bd548 sub r6, r6, #1 */
/* @0x2bd54c mov r12, #0 */
/* @0x2bd550 str r6, [sp, #0x1c] */
/* @0x2bd554 str r12, [sp, #0x10] */
/* @0x2bd558 str r4, [sp, #0x14] */
/* @0x2bd55c b 0x2bd584 <jpeg_alloc_huff_table+0xc7c> */
/* @0x2bd560 ldr r12, [sp, #0x10] */
/* @0x2bd564 add r5, r5, #84 */
/* @0x2bd568 add r12, r12, #1 */
/* @0x2bd56c str r12, [sp, #0x10] */
/* @0x2bd570 cmp r0, r12 */
/* @0x2bd574 ldr r12, [sp, #0x14] */
/* @0x2bd578 add r12, r12, #4 */
/* @0x2bd57c str r12, [sp, #0x14] */
/* @0x2bd580 ble 0x2bd698 <jpeg_alloc_huff_table+0xd90> */
/* @0x2bd584 ldrb r3, [r5, #0x30] */
/* @0x2bd588 cmp r3, #0 */
/* @0x2bd58c beq 0x2bd560 <jpeg_alloc_huff_table+0xc58> */
/* @0x2bd590 ldr r12, [sp, #0x14] */
/* @0x2bd594 mov lr, #0 */
/* @0x2bd598 ldr r3, [r5, #0xc] */
/* @0x2bd59c mov r0, r11 */
/* @0x2bd5a0 ldr r1, [r12, #0x48] */
/* @0x2bd5a4 ldr r12, [r11, #0x4] */
/* @0x2bd5a8 mul r2, r2, r3 */
/* @0x2bd5ac str lr, [sp] */
/* @0x2bd5b0 ldr r12, [r12, #0x20] */
/* @0x2bd5b4 blx r12 */
/* @0x2bd5b8 ldr r12, [sp, #0x1c] */
/* @0x2bd5bc ldr r4, [r11, #0x88] */
/* @0x2bd5c0 cmp r12, r4 */
/* @0x2bd5c4 ldr r12, [r5, #0xc] */
/* @0x2bd5c8 str r12, [sp, #0xc] */
/* @0x2bd5cc mov r10, r0 */
/* @0x2bd5d0 bhi 0x2bd5f0 <jpeg_alloc_huff_table+0xce8> */
/* @0x2bd5d4 mov r1, r12 */
/* @0x2bd5d8 ldr r0, [r5, #0x20] */
/* @0x2bd5dc bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x2bd5e0 ldr r12, [sp, #0xc] */
/* @0x2bd5e4 cmp r1, #0 */
/* @0x2bd5e8 movne r12, r1 */
/* @0x2bd5ec str r12, [sp, #0xc] */
/* @0x2bd5f0 ldr r12, [sp, #0xc] */
/* @0x2bd5f4 ldr r3, [r11, #0x19c] */
/* @0x2bd5f8 cmp r12, #0 */
/* @0x2bd5fc ldr r12, [sp, #0x10] */
/* @0x2bd600 ldr r1, [sp, #0x18] */
/* @0x2bd604 add r3, r3, r12, lsl #2 */
/* @0x2bd608 ldr r7, [r1, r12, lsl #2] */
/* @0x2bd60c ldr r8, [r3, #0x4] */
/* @0x2bd610 ble 0x2bd6c0 <jpeg_alloc_huff_table+0xdb8> */
/* @0x2bd614 ldr r3, [r5, #0x1c] */
/* @0x2bd618 mov r9, #0 */
/* @0x2bd61c sub r10, r10, #4 */
/* @0x2bd620 str r10, [sp, #0x8] */
/* @0x2bd624 ldr r12, [sp, #0x8] */
/* @0x2bd628 cmp r3, #0 */
/* @0x2bd62c ldreq r2, [r5, #0x24] */
/* @0x2bd630 ldr r6, [r12, #0x4]! */
/* @0x2bd634 str r12, [sp, #0x8] */
/* @0x2bd638 beq 0x2bd678 <jpeg_alloc_huff_table+0xd70> */
/* @0x2bd63c mov r4, #0 */
/* @0x2bd640 mov r10, r4 */
/* @0x2bd644 mov r2, r6 */
/* @0x2bd648 str r4, [sp] */
/* @0x2bd64c mov r3, r7 */
/* @0x2bd650 mov r0, r11 */
/* @0x2bd654 mov r1, r5 */
/* @0x2bd658 add r10, r10, #1 */
/* @0x2bd65c blx r8 */
/* @0x2bd660 ldr r3, [r5, #0x1c] */
/* @0x2bd664 ldr r2, [r5, #0x24] */
/* @0x2bd668 add r6, r6, #128 */
/* @0x2bd66c cmp r3, r10 */
/* @0x2bd670 add r4, r4, r2 */
/* @0x2bd674 bhi 0x2bd644 <jpeg_alloc_huff_table+0xd3c> */
/* @0x2bd678 ldr r12, [sp, #0xc] */
/* @0x2bd67c add r9, r9, #1 */
/* @0x2bd680 add r7, r7, r2, lsl #2 */
/* @0x2bd684 cmp r9, r12 */
/* @0x2bd688 bne 0x2bd624 <jpeg_alloc_huff_table+0xd1c> */
/* @0x2bd68c ldr r2, [r11, #0x88] */
/* @0x2bd690 ldr r0, [r11, #0x24] */
/* @0x2bd694 b 0x2bd560 <jpeg_alloc_huff_table+0xc58> */
/* @0x2bd698 ldr r0, [r11, #0x11c] */
/* @0x2bd69c add r2, r2, #1 */
/* @0x2bd6a0 str r2, [r11, #0x88] */
/* @0x2bd6a4 cmp r2, r0 */
/* @0x2bd6a8 movhs r0, #4 */
/* @0x2bd6ac movlo r0, #3 */
/* @0x2bd6b0 add sp, sp, #36 */
/* @0x2bd6b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bd6b8 mov r2, r3 */
/* @0x2bd6bc b 0x2bd538 <jpeg_alloc_huff_table+0xc30> */
/* @0x2bd6c0 ldr r0, [r11, #0x24] */
/* @0x2bd6c4 mov r2, r4 */
/* @0x2bd6c8 b 0x2bd560 <jpeg_alloc_huff_table+0xc58> */
/* @0x2bd6cc ldr r12, [r0, #0x188] */
/* @0x2bd6d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2bd6d4 sub sp, sp, #60 */
/* @0x2bd6d8 ldr r3, [r0, #0x138] */
/* @0x2bd6dc mov r11, r0 */
/* @0x2bd6e0 str r12, [sp, #0x14] */
/* @0x2bd6e4 ldr r12, [r12, #0x18] */
/* @0x2bd6e8 sub r3, r3, #1 */
/* @0x2bd6ec ldr r2, [r0, #0x11c] */
/* @0x2bd6f0 str r3, [sp, #0x2c] */
/* @0x2bd6f4 str r12, [sp, #0x20] */
/* @0x2bd6f8 ldr r12, [sp, #0x14] */
/* @0x2bd6fc str r1, [sp, #0x30] */
/* @0x2bd700 ldr r3, [r12, #0x1c] */
/* @0x2bd704 sub r12, r2, #1 */
/* @0x2bd708 str r12, [sp, #0x10] */
/* @0x2bd70c ldr r12, [sp, #0x20] */
/* @0x2bd710 cmp r12, r3 */
/* @0x2bd714 bge 0x2bd94c <jpeg_alloc_huff_table+0x1044> */
/* @0x2bd718 ldr r12, [sp, #0x14] */
/* @0x2bd71c ldr r12, [r12, #0x14] */
/* @0x2bd720 str r12, [sp, #0x28] */
/* @0x2bd724 ldr r12, [sp, #0x14] */
/* @0x2bd728 ldr lr, [sp, #0x28] */
/* @0x2bd72c add r12, r12, #32 */
/* @0x2bd730 str r12, [sp, #0x34] */
/* @0x2bd734 ldr r12, [sp, #0x2c] */
/* @0x2bd738 cmp r12, lr */
/* @0x2bd73c blo 0x2bd7f4 <jpeg_alloc_huff_table+0xeec> */
/* @0x2bd740 ldr r12, [sp, #0x14] */
/* @0x2bd744 ldr r1, [r11, #0x140] */
/* @0x2bd748 ldr r0, [r12, #0x20] */
/* @0x2bd74c lsl r1, r1, #7 */
/* @0x2bd750 bl 0x2bc868 <jzero_far> */
/* @0x2bd754 ldr r3, [r11, #0x198] */
/* @0x2bd758 mov r0, r11 */
/* @0x2bd75c ldr r1, [sp, #0x34] */
/* @0x2bd760 ldr r3, [r3, #0x4] */
/* @0x2bd764 blx r3 */
/* @0x2bd768 cmp r0, #0 */
/* @0x2bd76c beq 0x2bd930 <jpeg_alloc_huff_table+0x1028> */
/* @0x2bd770 ldr r1, [r11, #0x124] */
/* @0x2bd774 cmp r1, #0 */
/* @0x2bd778 ble 0x2bd7d4 <jpeg_alloc_huff_table+0xecc> */
/* @0x2bd77c mov r12, #0 */
/* @0x2bd780 str r11, [sp, #0x24] */
/* @0x2bd784 str r12, [sp, #0x1c] */
/* @0x2bd788 str r12, [sp, #0xc] */
/* @0x2bd78c ldr r12, [sp, #0x24] */
/* @0x2bd790 ldr r6, [r12, #0x128] */
/* @0x2bd794 ldrb r3, [r6, #0x30] */
/* @0x2bd798 cmp r3, #0 */
/* @0x2bd79c bne 0x2bd828 <jpeg_alloc_huff_table+0xf20> */
/* @0x2bd7a0 ldr r12, [sp, #0xc] */
/* @0x2bd7a4 ldr r3, [r6, #0x3c] */
/* @0x2bd7a8 add r12, r12, r3 */
/* @0x2bd7ac str r12, [sp, #0xc] */
/* @0x2bd7b0 ldr r12, [sp, #0x1c] */
/* @0x2bd7b4 add r12, r12, #1 */
/* @0x2bd7b8 str r12, [sp, #0x1c] */
/* @0x2bd7bc ldr r12, [sp, #0x24] */
/* @0x2bd7c0 add r12, r12, #4 */
/* @0x2bd7c4 str r12, [sp, #0x24] */
/* @0x2bd7c8 ldr r12, [sp, #0x1c] */
/* @0x2bd7cc cmp r1, r12 */
/* @0x2bd7d0 bgt 0x2bd78c <jpeg_alloc_huff_table+0xe84> */
/* @0x2bd7d4 ldr r12, [sp, #0x28] */
/* @0x2bd7d8 ldr lr, [sp, #0x2c] */
/* @0x2bd7dc add r12, r12, #1 */
/* @0x2bd7e0 str r12, [sp, #0x28] */
/* @0x2bd7e4 cmp lr, r12 */
/* @0x2bd7e8 bhs 0x2bd740 <jpeg_alloc_huff_table+0xe38> */
/* @0x2bd7ec ldr r12, [sp, #0x14] */
/* @0x2bd7f0 ldr r3, [r12, #0x1c] */
/* @0x2bd7f4 ldr r12, [sp, #0x20] */
/* @0x2bd7f8 mov lr, #0 */
/* @0x2bd7fc add r12, r12, #1 */
/* @0x2bd800 str r12, [sp, #0x20] */
/* @0x2bd804 ldr r12, [sp, #0x14] */
/* @0x2bd808 str lr, [r12, #0x14] */
/* @0x2bd80c ldr r12, [sp, #0x20] */
/* @0x2bd810 cmp r3, r12 */
/* @0x2bd814 movgt r12, #0 */
/* @0x2bd818 strgt r12, [sp, #0x28] */
/* @0x2bd81c bgt 0x2bd740 <jpeg_alloc_huff_table+0xe38> */
/* @0x2bd820 ldr r3, [r11, #0x11c] */
/* @0x2bd824 b 0x2bd950 <jpeg_alloc_huff_table+0x1048> */
/* @0x2bd828 ldr r0, [r6, #0x4] */
/* @0x2bd82c ldr r12, [sp, #0x2c] */
/* @0x2bd830 ldr lr, [sp, #0x28] */
/* @0x2bd834 ldr r3, [r11, #0x19c] */
/* @0x2bd838 cmp r12, lr */
/* @0x2bd83c ldr r12, [sp, #0x30] */
/* @0x2bd840 add r3, r3, r0, lsl #2 */
/* @0x2bd844 ldr lr, [sp, #0x28] */
/* @0x2bd848 ldr r2, [r6, #0x38] */
/* @0x2bd84c ldr r0, [r12, r0, lsl #2] */
/* @0x2bd850 ldr r9, [r3, #0x4] */
/* @0x2bd854 ldr r12, [sp, #0x20] */
/* @0x2bd858 ldr r3, [r6, #0x24] */
/* @0x2bd85c ldrhi r8, [r6, #0x34] */
/* @0x2bd860 ldrls r8, [r6, #0x44] */
/* @0x2bd864 cmp r2, #0 */
/* @0x2bd868 mul r7, r3, r12 */
/* @0x2bd86c ldr r12, [r6, #0x40] */
/* @0x2bd870 mul r12, r12, lr */
/* @0x2bd874 add r7, r0, r7, lsl #2 */
/* @0x2bd878 str r12, [sp, #0x18] */
/* @0x2bd87c ble 0x2bd7b0 <jpeg_alloc_huff_table+0xea8> */
/* @0x2bd880 mov r12, #0 */
/* @0x2bd884 str r12, [sp, #0x8] */
/* @0x2bd888 ldr r1, [r11, #0x80] */
/* @0x2bd88c ldr r12, [sp, #0x10] */
/* @0x2bd890 cmp r12, r1 */
/* @0x2bd894 bhi 0x2bd8b0 <jpeg_alloc_huff_table+0xfa8> */
/* @0x2bd898 ldr r12, [sp, #0x8] */
/* @0x2bd89c ldr lr, [sp, #0x20] */
/* @0x2bd8a0 ldr r1, [r6, #0x48] */
/* @0x2bd8a4 add r0, r12, lr */
/* @0x2bd8a8 cmp r0, r1 */
/* @0x2bd8ac bge 0x2bd900 <jpeg_alloc_huff_table+0xff8> */
/* @0x2bd8b0 cmp r8, #0 */
/* @0x2bd8b4 ble 0x2bd900 <jpeg_alloc_huff_table+0xff8> */
/* @0x2bd8b8 ldr r0, [sp, #0xc] */
/* @0x2bd8bc mov r4, #0 */
/* @0x2bd8c0 ldr r1, [sp, #0x14] */
/* @0x2bd8c4 add r12, r0, #7 */
/* @0x2bd8c8 ldr r5, [sp, #0x18] */
/* @0x2bd8cc add r10, r1, r12, lsl #2 */
/* @0x2bd8d0 ldr r2, [r10, #0x4]! */
/* @0x2bd8d4 mov r3, r7 */
/* @0x2bd8d8 str r5, [sp] */
/* @0x2bd8dc add r4, r4, #1 */
/* @0x2bd8e0 mov r0, r11 */
/* @0x2bd8e4 mov r1, r6 */
/* @0x2bd8e8 blx r9 */
/* @0x2bd8ec ldr r3, [r6, #0x24] */
/* @0x2bd8f0 cmp r4, r8 */
/* @0x2bd8f4 add r5, r5, r3 */
/* @0x2bd8f8 bne 0x2bd8d0 <jpeg_alloc_huff_table+0xfc8> */
/* @0x2bd8fc ldr r2, [r6, #0x38] */
/* @0x2bd900 ldr r12, [sp, #0x8] */
/* @0x2bd904 add r7, r7, r3, lsl #2 */
/* @0x2bd908 ldr r1, [r6, #0x34] */
/* @0x2bd90c add r12, r12, #1 */
/* @0x2bd910 str r12, [sp, #0x8] */
/* @0x2bd914 cmp r2, r12 */
/* @0x2bd918 ldr r12, [sp, #0xc] */
/* @0x2bd91c add r12, r12, r1 */
/* @0x2bd920 str r12, [sp, #0xc] */
/* @0x2bd924 bgt 0x2bd888 <jpeg_alloc_huff_table+0xf80> */
/* @0x2bd928 ldr r1, [r11, #0x124] */
/* @0x2bd92c b 0x2bd7b0 <jpeg_alloc_huff_table+0xea8> */
/* @0x2bd930 ldr r12, [sp, #0x20] */
/* @0x2bd934 ldr r1, [sp, #0x14] */
/* @0x2bd938 str r12, [r1, #0x18] */
/* @0x2bd93c ldr r12, [sp, #0x28] */
/* @0x2bd940 str r12, [r1, #0x14] */
/* @0x2bd944 add sp, sp, #60 */
/* @0x2bd948 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bd94c mov r3, r2 */
/* @0x2bd950 ldr r2, [r11, #0x80] */
/* @0x2bd954 ldr r1, [r11, #0x88] */
/* @0x2bd958 add r2, r2, #1 */
/* @0x2bd95c str r2, [r11, #0x80] */
/* @0x2bd960 cmp r2, r3 */
/* @0x2bd964 add r3, r1, #1 */
/* @0x2bd968 str r3, [r11, #0x88] */
/* @0x2bd96c bhs 0x2bd984 <jpeg_alloc_huff_table+0x107c> */
/* @0x2bd970 mov r0, r11 */
/* @0x2bd974 bl 0x2bc92c <jpeg_alloc_huff_table+0x24> */
/* @0x2bd978 mov r0, #3 */
/* @0x2bd97c add sp, sp, #60 */
/* @0x2bd980 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bd984 ldr r3, [r11, #0x190] */
/* @0x2bd988 mov r0, r11 */
/* @0x2bd98c ldr r3, [r3, #0xc] */
/* @0x2bd990 blx r3 */
/* @0x2bd994 mov r0, #4 */
/* @0x2bd998 add sp, sp, #60 */
/* @0x2bd99c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x2bd9a0 · jinit_d_coef_controller · size=372 · insn=93 */
/* @0x2bd9a0 ldr r3, [r0, #0x4] */
/* @0x2bd9a4 mov r2, #116 */
/* @0x2bd9a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2bd9ac mov r4, r1 */
/* @0x2bd9b0 ldr r3, [r3] */
/* @0x2bd9b4 sub sp, sp, #12 */
/* @0x2bd9b8 mov r1, #1 */
/* @0x2bd9bc mov r5, r0 */
/* @0x2bd9c0 blx r3 */
/* @0x2bd9c4 ldr r2, [pc, #0x130] */
/* @0x2bd9c8 ldr r3, [pc, #0x130] */
/* @0x2bd9cc cmp r4, #0 */
/* @0x2bd9d0 add r2, pc, r2 */
/* @0x2bd9d4 mov r8, #0 */
/* @0x2bd9d8 add r3, pc, r3 */
/* @0x2bd9dc str r0, [r5, #0x188] */
/* @0x2bd9e0 mov r11, r0 */
/* @0x2bd9e4 str r2, [r0] */
/* @0x2bd9e8 str r3, [r0, #0x8] */
/* @0x2bd9ec str r8, [r0, #0x70] */
/* @0x2bd9f0 beq 0x2bda9c <jinit_d_coef_controller+0xfc> */
/* @0x2bd9f4 ldr r3, [r5, #0x24] */
/* @0x2bd9f8 ldr r4, [r5, #0xc4] */
/* @0x2bd9fc cmp r3, r8 */
/* @0x2bda00 movgt r7, r0 */
/* @0x2bda04 ble 0x2bda74 <jinit_d_coef_controller+0xd4> */
/* @0x2bda08 ldrb r3, [r5, #0xc8] */
/* @0x2bda0c add r8, r8, #1 */
/* @0x2bda10 ldr r6, [r4, #0xc] */
/* @0x2bda14 add r7, r7, #4 */
/* @0x2bda18 cmp r3, #0 */
/* @0x2bda1c ldr r3, [r5, #0x4] */
/* @0x2bda20 ldr r1, [r4, #0x8] */
/* @0x2bda24 add r4, r4, #84 */
/* @0x2bda28 ldr r0, [r4, #-0x38] */
/* @0x2bda2c addne r6, r6, r6, lsl #1 */
/* @0x2bda30 ldr r9, [r3, #0x14] */
/* @0x2bda34 bl 0x2bc800 <jround_up> */
/* @0x2bda38 ldr r1, [r4, #-0x48] */
/* @0x2bda3c mov r10, r0 */
/* @0x2bda40 ldr r0, [r4, #-0x34] */
/* @0x2bda44 bl 0x2bc800 <jround_up> */
/* @0x2bda48 mov r1, #1 */
/* @0x2bda4c mov r3, r10 */
/* @0x2bda50 str r6, [sp, #0x4] */
/* @0x2bda54 mov r2, r1 */
/* @0x2bda58 str r0, [sp] */
/* @0x2bda5c mov r0, r5 */
/* @0x2bda60 blx r9 */
/* @0x2bda64 str r0, [r7, #0x44] */
/* @0x2bda68 ldr r3, [r5, #0x24] */
/* @0x2bda6c cmp r3, r8 */
/* @0x2bda70 bgt 0x2bda08 <jinit_d_coef_controller+0x68> */
/* @0x2bda74 ldr r2, [pc, #0x88] */
/* @0x2bda78 add r1, r11, #72 */
/* @0x2bda7c ldr r3, [pc, #0x84] */
/* @0x2bda80 add r2, pc, r2 */
/* @0x2bda84 str r1, [r11, #0x10] */
/* @0x2bda88 add r3, pc, r3 */
/* @0x2bda8c str r2, [r11, #0x4] */
/* @0x2bda90 str r3, [r11, #0xc] */
/* @0x2bda94 add sp, sp, #12 */
/* @0x2bda98 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bda9c ldr r3, [r5, #0x4] */
/* @0x2bdaa0 mov r1, #1 */
/* @0x2bdaa4 mov r0, r5 */
/* @0x2bdaa8 mov r2, #1280 */
/* @0x2bdaac ldr r3, [r3, #0x4] */
/* @0x2bdab0 blx r3 */
/* @0x2bdab4 mov r1, r4 */
/* @0x2bdab8 mov r3, r11 */
/* @0x2bdabc add r2, r0, r1 */
/* @0x2bdac0 add r1, r1, #128 */
/* @0x2bdac4 cmp r1, #1280 */
/* @0x2bdac8 str r2, [r3, #0x20] */
/* @0x2bdacc add r3, r3, #4 */
/* @0x2bdad0 bne 0x2bdabc <jinit_d_coef_controller+0x11c> */
/* @0x2bdad4 ldr r2, [pc, #0x30] */
/* @0x2bdad8 mov r1, #0 */
/* @0x2bdadc ldr r3, [pc, #0x2c] */
/* @0x2bdae0 add r2, pc, r2 */
/* @0x2bdae4 str r1, [r11, #0x10] */
/* @0x2bdae8 add r3, pc, r3 */
/* @0x2bdaec str r2, [r11, #0x4] */
/* @0x2bdaf0 str r3, [r11, #0xc] */
/* @0x2bdaf4 add sp, sp, #12 */
/* @0x2bdaf8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bdafc .word 0xffffefa0 */
/* @0x2bdb00 .word 0xfffff1f0 */
/* @0x2bdb04 .word 0xffffef04 */
/* @0x2bdb08 .word 0xfffffa48 */
/* @0x2bdb0c .word 0xffffee9c */
/* @0x2bdb10 .word 0xfffffbdc */

/* ── FUNC 0x2bdb14 · anon_2bdb14 · size=1108 · insn=277 */
/* @0x2bdb14 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2bdb18 mov r1, #1 */
/* @0x2bdb1c ldr r3, [r0, #0x4] */
/* @0x2bdb20 mov r2, #1024 */
/* @0x2bdb24 mov r4, r0 */
/* @0x2bdb28 ldr r5, [r0, #0x1a4] */
/* @0x2bdb2c ldr r3, [r3] */
/* @0x2bdb30 blx r3 */
/* @0x2bdb34 ldr r3, [r4, #0x4] */
/* @0x2bdb38 mov r1, #1 */
/* @0x2bdb3c mov r2, #1024 */
/* @0x2bdb40 ldr r3, [r3] */
/* @0x2bdb44 str r0, [r5, #0x8] */
/* @0x2bdb48 mov r0, r4 */
/* @0x2bdb4c blx r3 */
/* @0x2bdb50 ldr r3, [r4, #0x4] */
/* @0x2bdb54 mov r1, #1 */
/* @0x2bdb58 mov r2, #1024 */
/* @0x2bdb5c ldr r3, [r3] */
/* @0x2bdb60 str r0, [r5, #0xc] */
/* @0x2bdb64 mov r0, r4 */
/* @0x2bdb68 blx r3 */
/* @0x2bdb6c ldr r3, [r4, #0x4] */
/* @0x2bdb70 mov r1, #1 */
/* @0x2bdb74 mov r2, #1024 */
/* @0x2bdb78 ldr r3, [r3] */
/* @0x2bdb7c str r0, [r5, #0x10] */
/* @0x2bdb80 mov r0, r4 */
/* @0x2bdb84 blx r3 */
/* @0x2bdb88 ldr r9, [r5, #0x8] */
/* @0x2bdb8c ldr r8, [r5, #0xc] */
/* @0x2bdb90 mov r4, #36096 */
/* @0x2bdb94 ldr r7, [r5, #0x10] */
/* @0x2bdb98 mov r12, #26880 */
/* @0x2bdb9c mov r2, #44800 */
/* @0x2bdba0 mov r3, #2944 */
/* @0x2bdba4 movt r4, #0x2c */
/* @0x2bdba8 movt r12, #0x5b */
/* @0x2bdbac movt r2, #0xff1d */
/* @0x2bdbb0 movt r3, #0xff4d */
/* @0x2bdbb4 mov r1, #0 */
/* @0x2bdbb8 str r0, [r5, #0x14] */
/* @0x2bdbbc asr r6, r3, #16 */
/* @0x2bdbc0 asr r5, r2, #16 */
/* @0x2bdbc4 str r6, [r9, r1] */
/* @0x2bdbc8 add r3, r3, #91136 */
/* @0x2bdbcc str r5, [r8, r1] */
/* @0x2bdbd0 add r2, r2, #115712 */
/* @0x2bdbd4 str r12, [r7, r1] */
/* @0x2bdbd8 add r3, r3, #744 */
/* @0x2bdbdc str r4, [r0, r1] */
/* @0x2bdbe0 add r1, r1, #4 */
/* @0x2bdbe4 cmp r1, #1024 */
/* @0x2bdbe8 add r2, r2, #416 */
/* @0x2bdbec sub r12, r12, #46592 */
/* @0x2bdbf0 sub r4, r4, #22528 */
/* @0x2bdbf4 add r3, r3, #1 */
/* @0x2bdbf8 add r2, r2, #2 */
/* @0x2bdbfc sub r12, r12, #210 */
/* @0x2bdc00 sub r4, r4, #26 */
/* @0x2bdc04 bne 0x2bdbbc <jinit_d_coef_controller+0x21c> */
/* @0x2bdc08 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2bdc0c push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2bdc10 sub sp, sp, #24 */
/* @0x2bdc14 ldr r6, [r0, #0x5c] */
/* @0x2bdc18 str r3, [sp, #0xc] */
/* @0x2bdc1c ldr r3, [r0, #0x1a4] */
/* @0x2bdc20 ldr r0, [r0, #0x120] */
/* @0x2bdc24 ldr r4, [sp, #0xc] */
/* @0x2bdc28 ldr r11, [r3, #0xc] */
/* @0x2bdc2c ldr r12, [r3, #0x10] */
/* @0x2bdc30 rsb r2, r4, r2, lsl #2 */
/* @0x2bdc34 ldr r10, [r3, #0x8] */
/* @0x2bdc38 ldr r9, [r3, #0x14] */
/* @0x2bdc3c str r2, [sp, #0x14] */
/* @0x2bdc40 str r1, [sp, #0x10] */
/* @0x2bdc44 str r11, [sp, #0x4] */
/* @0x2bdc48 str r12, [sp, #0x8] */
/* @0x2bdc4c ldr r11, [sp, #0x38] */
/* @0x2bdc50 subs r11, r11, #1 */
/* @0x2bdc54 str r11, [sp, #0x38] */
/* @0x2bdc58 bmi 0x2bdd10 <jinit_d_coef_controller+0x370> */
/* @0x2bdc5c ldr r2, [sp, #0x10] */
/* @0x2bdc60 cmp r6, #0 */
/* @0x2bdc64 ldr r4, [sp, #0xc] */
/* @0x2bdc68 ldr r11, [sp, #0x14] */
/* @0x2bdc6c ldr r12, [r2] */
/* @0x2bdc70 ldr r1, [r2, #0x4] */
/* @0x2bdc74 add r3, r4, r11 */
/* @0x2bdc78 ldr r2, [r2, #0x8] */
/* @0x2bdc7c ldr r12, [r12, r3] */
/* @0x2bdc80 ldr r7, [r1, r3] */
/* @0x2bdc84 ldr r8, [r2, r3] */
/* @0x2bdc88 ldr r2, [r4], #4 */
/* @0x2bdc8c str r12, [sp] */
/* @0x2bdc90 str r4, [sp, #0xc] */
/* @0x2bdc94 beq 0x2bdc4c <jinit_d_coef_controller+0x2ac> */
/* @0x2bdc98 mov r3, #0 */
/* @0x2bdc9c ldrb r4, [r8, r3] */
/* @0x2bdca0 add r2, r2, #3 */
/* @0x2bdca4 ldr r12, [sp] */
/* @0x2bdca8 ldr r11, [r10, r4, lsl #2] */
/* @0x2bdcac ldrb r1, [r12, r3] */
/* @0x2bdcb0 add r11, r0, r11 */
/* @0x2bdcb4 ldrb r12, [r7, r3] */
/* @0x2bdcb8 add r5, r0, r1 */
/* @0x2bdcbc add r3, r3, #1 */
/* @0x2bdcc0 ldrb r11, [r11, r1] */
/* @0x2bdcc4 cmp r3, r6 */
/* @0x2bdcc8 sxth r12, r12 */
/* @0x2bdccc strb r11, [r2, #-0x3] */
/* @0x2bdcd0 ldr r11, [sp, #0x8] */
/* @0x2bdcd4 ldr r4, [r11, r4, lsl #2] */
/* @0x2bdcd8 ldr r11, [r9, r12, lsl #2] */
/* @0x2bdcdc add r4, r11, r4 */
/* @0x2bdce0 ldrb r4, [r5, r4, asr #16] */
/* @0x2bdce4 strb r4, [r2, #-0x2] */
/* @0x2bdce8 ldr r4, [sp, #0x4] */
/* @0x2bdcec ldr r12, [r4, r12, lsl #2] */
/* @0x2bdcf0 add r12, r0, r12 */
/* @0x2bdcf4 ldrb r1, [r12, r1] */
/* @0x2bdcf8 strb r1, [r2, #-0x1] */
/* @0x2bdcfc bne 0x2bdc9c <jinit_d_coef_controller+0x2fc> */
/* @0x2bdd00 ldr r11, [sp, #0x38] */
/* @0x2bdd04 subs r11, r11, #1 */
/* @0x2bdd08 str r11, [sp, #0x38] */
/* @0x2bdd0c bpl 0x2bdc5c <jinit_d_coef_controller+0x2bc> */
/* @0x2bdd10 add sp, sp, #24 */
/* @0x2bdd14 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2bdd18 bx lr */
/* @0x2bdd1c push {r4, r5, r6, r7, r8, r9, r10} */
/* @0x2bdd20 ldr r9, [sp, #0x1c] */
/* @0x2bdd24 ldr r8, [r0, #0x24] */
/* @0x2bdd28 subs r9, r9, #1 */
/* @0x2bdd2c ldr r7, [r0, #0x5c] */
/* @0x2bdd30 bmi 0x2bdd94 <jinit_d_coef_controller+0x3f4> */
/* @0x2bdd34 sub r10, r3, r2, lsl #2 */
/* @0x2bdd38 lsl r5, r2, #2 */
/* @0x2bdd3c cmp r8, #0 */
/* @0x2bdd40 ble 0x2bdd84 <jinit_d_coef_controller+0x3e4> */
/* @0x2bdd44 sub r6, r1, #4 */
/* @0x2bdd48 mov r4, #0 */
/* @0x2bdd4c ldr r3, [r6, #0x4]! */
/* @0x2bdd50 cmp r7, #0 */
/* @0x2bdd54 ldr r2, [r10, r5] */
/* @0x2bdd58 ldr r3, [r3, r5] */
/* @0x2bdd5c add r2, r2, r4 */
/* @0x2bdd60 addne r12, r3, r7 */
/* @0x2bdd64 beq 0x2bdd78 <jinit_d_coef_controller+0x3d8> */
/* @0x2bdd68 ldrb r0, [r3], #1 */
/* @0x2bdd6c cmp r3, r12 */
/* @0x2bdd70 strb r0, [r2], r8 */
/* @0x2bdd74 bne 0x2bdd68 <jinit_d_coef_controller+0x3c8> */
/* @0x2bdd78 add r4, r4, #1 */
/* @0x2bdd7c cmp r4, r8 */
/* @0x2bdd80 bne 0x2bdd4c <jinit_d_coef_controller+0x3ac> */
/* @0x2bdd84 sub r9, r9, #1 */
/* @0x2bdd88 add r5, r5, #4 */
/* @0x2bdd8c cmn r9, #1 */
/* @0x2bdd90 bne 0x2bdd3c <jinit_d_coef_controller+0x39c> */
/* @0x2bdd94 pop {r4, r5, r6, r7, r8, r9, r10} */
/* @0x2bdd98 bx lr */
/* @0x2bdd9c push {r4, r5, r6, r7} */
/* @0x2bdda0 rsb r2, r3, r2, lsl #2 */
/* @0x2bdda4 ldr r7, [r0, #0x5c] */
/* @0x2bdda8 ldr r6, [sp, #0x10] */
/* @0x2bddac subs r6, r6, #1 */
/* @0x2bddb0 bmi 0x2bddf0 <jinit_d_coef_controller+0x450> */
/* @0x2bddb4 ldr r4, [r1] */
/* @0x2bddb8 add r12, r3, r2 */
/* @0x2bddbc cmp r7, #0 */
/* @0x2bddc0 ldr r0, [r3], #4 */
/* @0x2bddc4 ldr r4, [r4, r12] */
/* @0x2bddc8 beq 0x2bddac <jinit_d_coef_controller+0x40c> */
/* @0x2bddcc add r5, r4, r7 */
/* @0x2bddd0 ldrb r12, [r4], #1 */
/* @0x2bddd4 cmp r4, r5 */
/* @0x2bddd8 strb r12, [r0, #0x2] */
/* @0x2bdddc strb r12, [r0, #0x1] */
/* @0x2bdde0 strb r12, [r0], #3 */
/* @0x2bdde4 bne 0x2bddd0 <jinit_d_coef_controller+0x430> */
/* @0x2bdde8 subs r6, r6, #1 */
/* @0x2bddec bpl 0x2bddb4 <jinit_d_coef_controller+0x414> */
/* @0x2bddf0 pop {r4, r5, r6, r7} */
/* @0x2bddf4 bx lr */
/* @0x2bddf8 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2bddfc sub sp, sp, #24 */
/* @0x2bde00 ldr r5, [r0, #0x5c] */
/* @0x2bde04 str r3, [sp, #0x10] */
/* @0x2bde08 ldr r3, [r0, #0x1a4] */
/* @0x2bde0c ldr r0, [r0, #0x120] */
/* @0x2bde10 ldr r4, [sp, #0x10] */
/* @0x2bde14 ldr r6, [r3, #0xc] */
/* @0x2bde18 ldr r11, [r3, #0x10] */
/* @0x2bde1c rsb r2, r4, r2, lsl #2 */
/* @0x2bde20 ldr r10, [r3, #0x8] */
/* @0x2bde24 ldr r9, [r3, #0x14] */
/* @0x2bde28 str r2, [sp, #0x14] */
/* @0x2bde2c str r1, [sp, #0xc] */
/* @0x2bde30 str r6, [sp, #0x4] */
/* @0x2bde34 str r11, [sp, #0x8] */
/* @0x2bde38 ldr r6, [sp, #0x38] */
/* @0x2bde3c subs r6, r6, #1 */
/* @0x2bde40 str r6, [sp, #0x38] */
/* @0x2bde44 bmi 0x2bdf20 <jinit_d_coef_controller+0x580> */
/* @0x2bde48 ldr r12, [sp, #0xc] */
/* @0x2bde4c cmp r5, #0 */
/* @0x2bde50 ldr r2, [sp, #0xc] */
/* @0x2bde54 ldr r6, [sp, #0x10] */
/* @0x2bde58 ldr r11, [sp, #0x14] */
/* @0x2bde5c ldr r4, [r12] */
/* @0x2bde60 ldr r1, [r2, #0x8] */
/* @0x2bde64 add r3, r6, r11 */
/* @0x2bde68 ldr r2, [r2, #0xc] */
/* @0x2bde6c ldr r12, [r12, #0x4] */
/* @0x2bde70 ldr r4, [r4, r3] */
/* @0x2bde74 ldr r8, [r2, r3] */
/* @0x2bde78 ldr r6, [r12, r3] */
/* @0x2bde7c ldr r7, [r1, r3] */
/* @0x2bde80 ldr r3, [sp, #0x10] */
/* @0x2bde84 str r4, [sp] */
/* @0x2bde88 ldr r2, [r3], #4 */
/* @0x2bde8c str r3, [sp, #0x10] */
/* @0x2bde90 beq 0x2bde38 <jinit_d_coef_controller+0x498> */
/* @0x2bde94 mov r3, #0 */
/* @0x2bde98 ldrb r4, [r7, r3] */
/* @0x2bde9c add r2, r2, #4 */
/* @0x2bdea0 ldr r11, [sp] */
/* @0x2bdea4 ldrb r12, [r6, r3] */
/* @0x2bdea8 ldrb r1, [r11, r3] */
/* @0x2bdeac ldr r11, [r10, r4, lsl #2] */
/* @0x2bdeb0 sxth r12, r12 */
/* @0x2bdeb4 add r11, r1, r11 */
/* @0x2bdeb8 rsb r11, r11, #255 */
/* @0x2bdebc ldrb r11, [r0, r11] */
/* @0x2bdec0 strb r11, [r2, #-0x4] */
/* @0x2bdec4 ldr r11, [sp, #0x8] */
/* @0x2bdec8 ldr r4, [r11, r4, lsl #2] */
/* @0x2bdecc ldr r11, [r9, r12, lsl #2] */
/* @0x2bded0 add r4, r11, r4 */
/* @0x2bded4 add r4, r1, r4, asr #16 */
/* @0x2bded8 rsb r4, r4, #255 */
/* @0x2bdedc ldrb r4, [r0, r4] */
/* @0x2bdee0 strb r4, [r2, #-0x3] */
/* @0x2bdee4 ldr r4, [sp, #0x4] */
/* @0x2bdee8 ldr r12, [r4, r12, lsl #2] */
/* @0x2bdeec add r1, r1, r12 */
/* @0x2bdef0 rsb r1, r1, #255 */
/* @0x2bdef4 ldrb r1, [r0, r1] */
/* @0x2bdef8 strb r1, [r2, #-0x2] */
/* @0x2bdefc ldrb r1, [r8, r3] */
/* @0x2bdf00 add r3, r3, #1 */
/* @0x2bdf04 cmp r3, r5 */
/* @0x2bdf08 strb r1, [r2, #-0x1] */
/* @0x2bdf0c bne 0x2bde98 <jinit_d_coef_controller+0x4f8> */
/* @0x2bdf10 ldr r6, [sp, #0x38] */
/* @0x2bdf14 subs r6, r6, #1 */
/* @0x2bdf18 str r6, [sp, #0x38] */
/* @0x2bdf1c bpl 0x2bde48 <jinit_d_coef_controller+0x4a8> */
/* @0x2bdf20 add sp, sp, #24 */
/* @0x2bdf24 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2bdf28 bx lr */
/* @0x2bdf2c bx lr */
/* @0x2bdf30 str lr, [sp, #-0x4]! */
/* @0x2bdf34 sub sp, sp, #12 */
/* @0x2bdf38 ldr lr, [r1] */
/* @0x2bdf3c mov r1, r2 */
/* @0x2bdf40 ldr r12, [sp, #0x10] */
/* @0x2bdf44 mov r2, r3 */
/* @0x2bdf48 mov r3, #0 */
/* @0x2bdf4c str r12, [sp] */
/* @0x2bdf50 ldr r12, [r0, #0x5c] */
/* @0x2bdf54 mov r0, lr */
/* @0x2bdf58 str r12, [sp, #0x4] */
/* @0x2bdf5c bl 0x2bc81c <jcopy_sample_rows> */
/* @0x2bdf60 add sp, sp, #12 */
/* @0x2bdf64 ldr pc, [sp], #4 */

/* ── FUNC 0x2bdf68 · jinit_color_deconverter · size=556 · insn=139 */
/* @0x2bdf68 push {r3, r4, r5, lr} */
/* @0x2bdf6c mov r1, #1 */
/* @0x2bdf70 ldr r3, [r0, #0x4] */
/* @0x2bdf74 mov r2, #24 */
/* @0x2bdf78 mov r4, r0 */
/* @0x2bdf7c ldr r3, [r3] */
/* @0x2bdf80 blx r3 */
/* @0x2bdf84 ldr r2, [r4, #0x28] */
/* @0x2bdf88 ldr r1, [pc, #0x1e4] */
/* @0x2bdf8c sub r3, r2, #1 */
/* @0x2bdf90 add r1, pc, r1 */
/* @0x2bdf94 str r0, [r4, #0x1a4] */
/* @0x2bdf98 mov r5, r0 */
/* @0x2bdf9c str r1, [r0] */
/* @0x2bdfa0 cmp r3, #4 */
/* @0x2bdfa4 addls pc, pc, r3, lsl #2 */
/* @0x2bdfa8 b 0x2be10c <jinit_color_deconverter+0x1a4> */
/* @0x2bdfac b 0x2be084 <jinit_color_deconverter+0x11c> */
/* @0x2bdfb0 b 0x2be03c <jinit_color_deconverter+0xd4> */
/* @0x2bdfb4 b 0x2be03c <jinit_color_deconverter+0xd4> */
/* @0x2bdfb8 b 0x2bdfc0 <jinit_color_deconverter+0x58> */
/* @0x2bdfbc b 0x2bdfc0 <jinit_color_deconverter+0x58> */
/* @0x2bdfc0 ldr r3, [r4, #0x24] */
/* @0x2bdfc4 cmp r3, #4 */
/* @0x2bdfc8 beq 0x2bdfe8 <jinit_color_deconverter+0x80> */
/* @0x2bdfcc ldr r3, [r4] */
/* @0x2bdfd0 mov r2, #10 */
/* @0x2bdfd4 mov r0, r4 */
/* @0x2bdfd8 str r2, [r3, #0x14] */
/* @0x2bdfdc ldr r3, [r3] */
/* @0x2bdfe0 blx r3 */
/* @0x2bdfe4 ldr r2, [r4, #0x28] */
/* @0x2bdfe8 ldr r3, [r4, #0x2c] */
/* @0x2bdfec cmp r3, #2 */
/* @0x2bdff0 beq 0x2be054 <jinit_color_deconverter+0xec> */
/* @0x2bdff4 cmp r3, #4 */
/* @0x2bdff8 beq 0x2be0e8 <jinit_color_deconverter+0x180> */
/* @0x2bdffc cmp r3, #1 */
/* @0x2be000 beq 0x2be094 <jinit_color_deconverter+0x12c> */
/* @0x2be004 cmp r3, r2 */
/* @0x2be008 beq 0x2be11c <jinit_color_deconverter+0x1b4> */
/* @0x2be00c ldr r3, [r4] */
/* @0x2be010 mov r2, #27 */
/* @0x2be014 mov r0, r4 */
/* @0x2be018 str r2, [r3, #0x14] */
/* @0x2be01c ldr r3, [r3] */
/* @0x2be020 blx r3 */
/* @0x2be024 ldrb r3, [r4, #0x4a] */
/* @0x2be028 cmp r3, #0 */
/* @0x2be02c ldreq r3, [r4, #0x64] */
/* @0x2be030 movne r3, #1 */
/* @0x2be034 str r3, [r4, #0x68] */
/* @0x2be038 pop {r3, r4, r5, pc} */
/* @0x2be03c ldr r3, [r4, #0x24] */
/* @0x2be040 cmp r3, #3 */
/* @0x2be044 bne 0x2bdfcc <jinit_color_deconverter+0x64> */
/* @0x2be048 ldr r3, [r4, #0x2c] */
/* @0x2be04c cmp r3, #2 */
/* @0x2be050 bne 0x2bdff4 <jinit_color_deconverter+0x8c> */
/* @0x2be054 cmp r2, #3 */
/* @0x2be058 mov r3, #3 */
/* @0x2be05c str r3, [r4, #0x64] */
/* @0x2be060 beq 0x2be15c <jinit_color_deconverter+0x1f4> */
/* @0x2be064 cmp r2, #1 */
/* @0x2be068 beq 0x2be134 <jinit_color_deconverter+0x1cc> */
/* @0x2be06c cmp r2, #2 */
/* @0x2be070 bne 0x2be00c <jinit_color_deconverter+0xa4> */
/* @0x2be074 ldr r3, [pc, #0xfc] */
/* @0x2be078 add r3, pc, r3 */
/* @0x2be07c str r3, [r5, #0x4] */
/* @0x2be080 b 0x2be024 <jinit_color_deconverter+0xbc> */
/* @0x2be084 ldr r2, [r4, #0x24] */
/* @0x2be088 cmp r2, #1 */
/* @0x2be08c bne 0x2bdfcc <jinit_color_deconverter+0x64> */
/* @0x2be090 b 0x2bdfe8 <jinit_color_deconverter+0x80> */
/* @0x2be094 bic r2, r2, #2 */
/* @0x2be098 str r3, [r4, #0x64] */
/* @0x2be09c cmp r2, #1 */
/* @0x2be0a0 bne 0x2be00c <jinit_color_deconverter+0xa4> */
/* @0x2be0a4 ldr r1, [r4, #0x24] */
/* @0x2be0a8 ldr r3, [pc, #0xcc] */
/* @0x2be0ac cmp r1, #1 */
/* @0x2be0b0 add r3, pc, r3 */
/* @0x2be0b4 str r3, [r5, #0x4] */
/* @0x2be0b8 ble 0x2be024 <jinit_color_deconverter+0xbc> */
/* @0x2be0bc mov r3, #84 */
/* @0x2be0c0 mov r0, #0 */
/* @0x2be0c4 ldr r1, [r4, #0xc4] */
/* @0x2be0c8 add r2, r2, #1 */
/* @0x2be0cc add r1, r1, r3 */
/* @0x2be0d0 add r3, r3, #84 */
/* @0x2be0d4 strb r0, [r1, #0x30] */
/* @0x2be0d8 ldr r1, [r4, #0x24] */
/* @0x2be0dc cmp r1, r2 */
/* @0x2be0e0 bgt 0x2be0c4 <jinit_color_deconverter+0x15c> */
/* @0x2be0e4 b 0x2be024 <jinit_color_deconverter+0xbc> */
/* @0x2be0e8 cmp r2, #5 */
/* @0x2be0ec str r3, [r4, #0x64] */
/* @0x2be0f0 beq 0x2be144 <jinit_color_deconverter+0x1dc> */
/* @0x2be0f4 cmp r2, #4 */
/* @0x2be0f8 bne 0x2be00c <jinit_color_deconverter+0xa4> */
/* @0x2be0fc ldr r3, [pc, #0x7c] */
/* @0x2be100 add r3, pc, r3 */
/* @0x2be104 str r3, [r5, #0x4] */
/* @0x2be108 b 0x2be024 <jinit_color_deconverter+0xbc> */
/* @0x2be10c ldr r3, [r4, #0x24] */
/* @0x2be110 cmp r3, #0 */
/* @0x2be114 bgt 0x2bdfe8 <jinit_color_deconverter+0x80> */
/* @0x2be118 b 0x2bdfcc <jinit_color_deconverter+0x64> */
/* @0x2be11c ldr r2, [r4, #0x24] */
/* @0x2be120 ldr r3, [pc, #0x5c] */
/* @0x2be124 str r2, [r4, #0x64] */
/* @0x2be128 add r3, pc, r3 */
/* @0x2be12c str r3, [r5, #0x4] */
/* @0x2be130 b 0x2be024 <jinit_color_deconverter+0xbc> */
/* @0x2be134 ldr r3, [pc, #0x4c] */
/* @0x2be138 add r3, pc, r3 */
/* @0x2be13c str r3, [r5, #0x4] */
/* @0x2be140 b 0x2be024 <jinit_color_deconverter+0xbc> */
/* @0x2be144 ldr r3, [pc, #0x40] */
/* @0x2be148 mov r0, r4 */
/* @0x2be14c add r3, pc, r3 */
/* @0x2be150 str r3, [r5, #0x4] */
/* @0x2be154 bl 0x2bdb14 <jinit_d_coef_controller+0x174> */
/* @0x2be158 b 0x2be024 <jinit_color_deconverter+0xbc> */
/* @0x2be15c ldr r3, [pc, #0x2c] */
/* @0x2be160 mov r0, r4 */
/* @0x2be164 add r3, pc, r3 */
/* @0x2be168 str r3, [r5, #0x4] */
/* @0x2be16c bl 0x2bdb14 <jinit_d_coef_controller+0x174> */
/* @0x2be170 b 0x2be024 <jinit_color_deconverter+0xbc> */
/* @0x2be174 .word 0xffffff94 */
/* @0x2be178 .word 0xfffffc9c */
/* @0x2be17c .word 0xfffffe78 */
/* @0x2be180 .word 0xfffffc14 */
/* @0x2be184 .word 0xfffffbec */
/* @0x2be188 .word 0xfffffc5c */
/* @0x2be18c .word 0xfffffca4 */
/* @0x2be190 .word 0xfffffaa0 */

/* ── FUNC 0x2be194 · anon_2be194 · size=744 · insn=186 */
/* @0x2be194 ldr r3, [r0, #0x24] */
/* @0x2be198 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2be19c cmp r3, #0 */
/* @0x2be1a0 sub sp, sp, #28 */
/* @0x2be1a4 ldr r1, [pc, #0x2ac] */
/* @0x2be1a8 mov r8, r0 */
/* @0x2be1ac ldr r6, [r0, #0x19c] */
/* @0x2be1b0 add r1, pc, r1 */
/* @0x2be1b4 ldr r5, [r0, #0xc4] */
/* @0x2be1b8 str r1, [sp, #0x8] */
/* @0x2be1bc ble 0x2be2b0 <jinit_color_deconverter+0x348> */
/* @0x2be1c0 ldr r4, [pc, #0x294] */
/* @0x2be1c4 mov r10, #0 */
/* @0x2be1c8 ldr r2, [pc, #0x290] */
/* @0x2be1cc sub r6, r6, #4 */
/* @0x2be1d0 add r4, pc, r4 */
/* @0x2be1d4 mov r9, r10 */
/* @0x2be1d8 add r2, pc, r2 */
/* @0x2be1dc mov r7, r10 */
/* @0x2be1e0 add r3, r2, #128 */
/* @0x2be1e4 str r2, [sp, #0xc] */
/* @0x2be1e8 str r3, [sp, #0x10] */
/* @0x2be1ec str r10, [sp, #0x4] */
/* @0x2be1f0 ldr r2, [r5, #0x24] */
/* @0x2be1f4 sub r3, r2, #1 */
/* @0x2be1f8 cmp r3, #7 */
/* @0x2be1fc addls pc, pc, r3, lsl #2 */
/* @0x2be200 b 0x2be31c <jinit_color_deconverter+0x3b4> */
/* @0x2be204 b 0x2be304 <jinit_color_deconverter+0x39c> */
/* @0x2be208 b 0x2be224 <jinit_color_deconverter+0x2bc> */
/* @0x2be20c b 0x2be31c <jinit_color_deconverter+0x3b4> */
/* @0x2be210 b 0x2be2ec <jinit_color_deconverter+0x384> */
/* @0x2be214 b 0x2be31c <jinit_color_deconverter+0x3b4> */
/* @0x2be218 b 0x2be31c <jinit_color_deconverter+0x3b4> */
/* @0x2be21c b 0x2be31c <jinit_color_deconverter+0x3b4> */
/* @0x2be220 b 0x2be2b8 <jinit_color_deconverter+0x350> */
/* @0x2be224 ldr r3, [pc, #0x238] */
/* @0x2be228 mov r9, #0 */
/* @0x2be22c ldr r2, [sp, #0x8] */
/* @0x2be230 ldr r3, [r2, r3] */
/* @0x2be234 str r3, [sp, #0x4] */
/* @0x2be238 ldr r2, [sp, #0x4] */
/* @0x2be23c add r6, r6, #4 */
/* @0x2be240 str r2, [r6, #0x4] */
/* @0x2be244 ldrb r3, [r5, #0x30] */
/* @0x2be248 cmp r3, #0 */
/* @0x2be24c beq 0x2be29c <jinit_color_deconverter+0x334> */
/* @0x2be250 ldr r3, [r6, #0x2c] */
/* @0x2be254 cmp r3, r9 */
/* @0x2be258 beq 0x2be29c <jinit_color_deconverter+0x334> */
/* @0x2be25c ldr r11, [r5, #0x4c] */
/* @0x2be260 cmp r11, #0 */
/* @0x2be264 beq 0x2be29c <jinit_color_deconverter+0x334> */
/* @0x2be268 cmp r9, #1 */
/* @0x2be26c str r9, [r6, #0x2c] */
/* @0x2be270 beq 0x2be3d8 <jinit_color_deconverter+0x470> */
/* @0x2be274 cmp r9, #2 */
/* @0x2be278 beq 0x2be364 <jinit_color_deconverter+0x3fc> */
/* @0x2be27c cmp r9, #0 */
/* @0x2be280 beq 0x2be340 <jinit_color_deconverter+0x3d8> */
/* @0x2be284 ldr r3, [r8] */
/* @0x2be288 mov r2, #48 */
/* @0x2be28c mov r0, r8 */
/* @0x2be290 str r2, [r3, #0x14] */
/* @0x2be294 ldr r3, [r3] */
/* @0x2be298 blx r3 */
/* @0x2be29c ldr r3, [r8, #0x24] */
/* @0x2be2a0 add r7, r7, #1 */
/* @0x2be2a4 add r5, r5, #84 */
/* @0x2be2a8 cmp r3, r7 */
/* @0x2be2ac bgt 0x2be1f0 <jinit_color_deconverter+0x288> */
/* @0x2be2b0 add sp, sp, #28 */
/* @0x2be2b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2be2b8 ldr r3, [r8, #0x44] */
/* @0x2be2bc cmp r3, #1 */
/* @0x2be2c0 beq 0x2be440 <jinit_color_deconverter+0x4d8> */
/* @0x2be2c4 blo 0x2be428 <jinit_color_deconverter+0x4c0> */
/* @0x2be2c8 cmp r3, #2 */
/* @0x2be2cc bne 0x2be40c <jinit_color_deconverter+0x4a4> */
/* @0x2be2d0 ldr r2, [pc, #0x190] */
/* @0x2be2d4 mov r9, r3 */
/* @0x2be2d8 mov r3, r2 */
/* @0x2be2dc ldr r2, [sp, #0x8] */
/* @0x2be2e0 ldr r3, [r2, r3] */
/* @0x2be2e4 str r3, [sp, #0x4] */
/* @0x2be2e8 b 0x2be238 <jinit_color_deconverter+0x2d0> */
/* @0x2be2ec ldr r3, [pc, #0x178] */
/* @0x2be2f0 mov r9, #0 */
/* @0x2be2f4 ldr r2, [sp, #0x8] */
/* @0x2be2f8 ldr r3, [r2, r3] */
/* @0x2be2fc str r3, [sp, #0x4] */
/* @0x2be300 b 0x2be238 <jinit_color_deconverter+0x2d0> */
/* @0x2be304 ldr r3, [pc, #0x164] */
/* @0x2be308 mov r9, #0 */
/* @0x2be30c ldr r1, [sp, #0x8] */
/* @0x2be310 ldr r3, [r1, r3] */
/* @0x2be314 str r3, [sp, #0x4] */
/* @0x2be318 b 0x2be238 <jinit_color_deconverter+0x2d0> */
/* @0x2be31c ldr r3, [r8] */
/* @0x2be320 mov r1, #7 */
/* @0x2be324 mov r0, r8 */
/* @0x2be328 str r2, [r3, #0x18] */
/* @0x2be32c ldr r2, [r8] */
/* @0x2be330 str r1, [r3, #0x14] */
/* @0x2be334 ldr r3, [r2] */
/* @0x2be338 blx r3 */
/* @0x2be33c b 0x2be238 <jinit_color_deconverter+0x2d0> */
/* @0x2be340 ldr r2, [r5, #0x50] */
/* @0x2be344 mov r3, r9 */
/* @0x2be348 sub r2, r2, #4 */
/* @0x2be34c ldrh r1, [r11, r3] */
/* @0x2be350 add r3, r3, #2 */
/* @0x2be354 cmp r3, #128 */
/* @0x2be358 str r1, [r2, #0x4]! */
/* @0x2be35c bne 0x2be34c <jinit_color_deconverter+0x3e4> */
/* @0x2be360 b 0x2be29c <jinit_color_deconverter+0x334> */
/* @0x2be364 ldr r3, [sp, #0xc] */
/* @0x2be368 sub r11, r11, #2 */
/* @0x2be36c ldr r0, [sp, #0x10] */
/* @0x2be370 ldr r10, [r5, #0x50] */
/* @0x2be374 add r12, r3, #192 */
/* @0x2be378 str r9, [sp, #0x14] */
/* @0x2be37c mov r9, r0 */
/* @0x2be380 mov r1, r10 */
/* @0x2be384 mov r3, r9 */
/* @0x2be388 mov r2, r11 */
/* @0x2be38c vldmia r0!, {d5} */
/* @0x2be390 str r0, [sp] */
/* @0x2be394 ldrh r0, [r2, #2]! */
/* @0x2be398 vldmia r3!, {d6} */
/* @0x2be39c cmp r12, r3 */
/* @0x2be3a0 vmov s14, r0 */
/* @0x2be3a4 vcvt.f64.u32 d7, s14 */
/* @0x2be3a8 vmul.f64 d7, d7, d5 */
/* @0x2be3ac vmul.f64 d7, d7, d6 */
/* @0x2be3b0 vcvt.f32.f64 s14, d7 */
/* @0x2be3b4 vstmia r1!, {s14} */
/* @0x2be3b8 bne 0x2be394 <jinit_color_deconverter+0x42c> */
/* @0x2be3bc ldr r0, [sp] */
/* @0x2be3c0 add r11, r11, #16 */
/* @0x2be3c4 add r10, r10, #32 */
/* @0x2be3c8 cmp r0, r12 */
/* @0x2be3cc bne 0x2be380 <jinit_color_deconverter+0x418> */
/* @0x2be3d0 ldr r9, [sp, #0x14] */
/* @0x2be3d4 b 0x2be29c <jinit_color_deconverter+0x334> */
/* @0x2be3d8 ldr r2, [r5, #0x50] */
/* @0x2be3dc mov r3, #0 */
/* @0x2be3e0 sub r2, r2, #4 */
/* @0x2be3e4 ldrh r1, [r11, r3] */
/* @0x2be3e8 ldrsh r0, [r3, r4] */
/* @0x2be3ec add r3, r3, #2 */
/* @0x2be3f0 cmp r3, #128 */
/* @0x2be3f4 mul r1, r0, r1 */
/* @0x2be3f8 add r1, r1, #2048 */
/* @0x2be3fc asr r1, r1, #12 */
/* @0x2be400 str r1, [r2, #0x4]! */
/* @0x2be404 bne 0x2be3e4 <jinit_color_deconverter+0x47c> */
/* @0x2be408 b 0x2be29c <jinit_color_deconverter+0x334> */
/* @0x2be40c ldr r3, [r8] */
/* @0x2be410 mov r2, #48 */
/* @0x2be414 mov r0, r8 */
/* @0x2be418 str r2, [r3, #0x14] */
/* @0x2be41c ldr r3, [r3] */
/* @0x2be420 blx r3 */
/* @0x2be424 b 0x2be238 <jinit_color_deconverter+0x2d0> */
/* @0x2be428 ldr r3, [pc, #0x44] */
/* @0x2be42c mov r9, #0 */
/* @0x2be430 ldr r1, [sp, #0x8] */
/* @0x2be434 ldr r3, [r1, r3] */
/* @0x2be438 str r3, [sp, #0x4] */
/* @0x2be43c b 0x2be238 <jinit_color_deconverter+0x2d0> */
/* @0x2be440 ldr r2, [pc, #0x30] */
/* @0x2be444 mov r9, r3 */
/* @0x2be448 ldr r1, [sp, #0x8] */
/* @0x2be44c ldr r3, [r1, r2] */
/* @0x2be450 str r3, [sp, #0x4] */
/* @0x2be454 b 0x2be238 <jinit_color_deconverter+0x2d0> */
/* @0x2be458 andseq r3, r3, r0, lsr #21 */
/* @0x2be45c andeq r1, sp, r0, asr pc */
/* @0x2be460 andeq r1, sp, r8, asr #30 */
/* @0x2be464 .word 0xfffffe60 */
/* @0x2be468 .word 0xfffffe64 */
/* @0x2be46c .word 0xfffffe68 */
/* @0x2be470 .word 0xfffffe6c */
/* @0x2be474 .word 0xfffffe70 */
/* @0x2be478 .word 0xfffffe74 */

/* ── FUNC 0x2be47c · jinit_inverse_dct · size=148 · insn=37 */
/* @0x2be47c ldr r3, [r0, #0x4] */
/* @0x2be480 mov r2, #84 */
/* @0x2be484 push {r4, r5, r6, r7, r8, lr} */
/* @0x2be488 mov r1, #1 */
/* @0x2be48c ldr r3, [r3] */
/* @0x2be490 mov r4, r0 */
/* @0x2be494 blx r3 */
/* @0x2be498 ldr r2, [r4, #0x24] */
/* @0x2be49c ldr r3, [pc, #0x68] */
/* @0x2be4a0 cmp r2, #0 */
/* @0x2be4a4 ldr r5, [r4, #0xc4] */
/* @0x2be4a8 add r3, pc, r3 */
/* @0x2be4ac str r0, [r4, #0x19c] */
/* @0x2be4b0 str r3, [r0] */
/* @0x2be4b4 pople {r4, r5, r6, r7, r8, pc} */
/* @0x2be4b8 mov r7, r0 */
/* @0x2be4bc mov r6, #0 */
/* @0x2be4c0 mvn r8, #0 */
/* @0x2be4c4 ldr r3, [r4, #0x4] */
/* @0x2be4c8 mov r1, #1 */
/* @0x2be4cc mov r2, #256 */
/* @0x2be4d0 mov r0, r4 */
/* @0x2be4d4 add r6, r6, r1 */
/* @0x2be4d8 add r5, r5, #84 */
/* @0x2be4dc ldr r3, [r3] */
/* @0x2be4e0 add r7, r7, #4 */
/* @0x2be4e4 blx r3 */
/* @0x2be4e8 mov r1, #0 */
/* @0x2be4ec mov r2, #256 */
/* @0x2be4f0 str r0, [r5, #-0x4] */
/* @0x2be4f4 bl 0xb65b0 <memset@plt> */
/* @0x2be4f8 str r8, [r7, #0x28] */
/* @0x2be4fc ldr r3, [r4, #0x24] */
/* @0x2be500 cmp r3, r6 */
/* @0x2be504 bgt 0x2be4c4 <jinit_inverse_dct+0x48> */
/* @0x2be508 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2be50c .word 0xfffffce4 */

/* ── FUNC 0x2be510 · jpeg_make_d_derived_tbl · size=928 · insn=232 */
/* @0x2be510 ldr r12, [pc, #0x394] */
/* @0x2be514 cmp r2, #3 */
/* @0x2be518 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2be51c ldr r12, [pc, r12] */
/* @0x2be520 sub sp, sp, #1328 */
/* @0x2be524 mov r5, r3 */
/* @0x2be528 ldr r3, [r12] */
/* @0x2be52c sub sp, sp, #4 */
/* @0x2be530 mov r4, r2 */
/* @0x2be534 mov r11, r0 */
/* @0x2be538 str r1, [sp, #0x14] */
/* @0x2be53c str r12, [sp, #0x10] */
/* @0x2be540 str r3, [sp, #0x52c] */
/* @0x2be544 bls 0x2be564 <jpeg_make_d_derived_tbl+0x54> */
/* @0x2be548 ldr r3, [r0] */
/* @0x2be54c mov r1, #50 */
/* @0x2be550 str r2, [r3, #0x18] */
/* @0x2be554 ldr r2, [r0] */
/* @0x2be558 str r1, [r3, #0x14] */
/* @0x2be55c ldr r3, [r2] */
/* @0x2be560 blx r3 */
/* @0x2be564 ldr r12, [sp, #0x14] */
/* @0x2be568 cmp r12, #0 */
/* @0x2be56c addne r3, r4, #40 */
/* @0x2be570 addeq r3, r4, #44 */
/* @0x2be574 ldr r7, [r11, r3, lsl #2] */
/* @0x2be578 cmp r7, #0 */
/* @0x2be57c bne 0x2be5a0 <jpeg_make_d_derived_tbl+0x90> */
/* @0x2be580 ldr r3, [r11] */
/* @0x2be584 mov r1, #50 */
/* @0x2be588 mov r0, r11 */
/* @0x2be58c str r4, [r3, #0x18] */
/* @0x2be590 ldr r2, [r11] */
/* @0x2be594 str r1, [r3, #0x14] */
/* @0x2be598 ldr r3, [r2] */
/* @0x2be59c blx r3 */
/* @0x2be5a0 ldr r8, [r5] */
/* @0x2be5a4 cmp r8, #0 */
/* @0x2be5a8 bne 0x2be5cc <jpeg_make_d_derived_tbl+0xbc> */
/* @0x2be5ac ldr r3, [r11, #0x4] */
/* @0x2be5b0 mov r0, r11 */
/* @0x2be5b4 mov r1, #1 */
/* @0x2be5b8 mov r2, #1424 */
/* @0x2be5bc ldr r3, [r3] */
/* @0x2be5c0 blx r3 */
/* @0x2be5c4 mov r8, r0 */
/* @0x2be5c8 str r0, [r5] */
/* @0x2be5cc add r10, sp, #1056 */
/* @0x2be5d0 mov r3, #0 */
/* @0x2be5d4 add r10, r10, #8 */
/* @0x2be5d8 str r7, [r8, #0x8c] */
/* @0x2be5dc mov r12, r8 */
/* @0x2be5e0 mov r5, #1 */
/* @0x2be5e4 mov r9, #8 */
/* @0x2be5e8 mov r8, r7 */
/* @0x2be5ec mov r6, r3 */
/* @0x2be5f0 str r3, [sp, #0xc] */
/* @0x2be5f4 ldrb r4, [r7, #0x1]! */
/* @0x2be5f8 add r3, r6, r4 */
/* @0x2be5fc cmp r3, #256 */
/* @0x2be600 ble 0x2be620 <jpeg_make_d_derived_tbl+0x110> */
/* @0x2be604 ldr r2, [r11] */
/* @0x2be608 mov r0, r11 */
/* @0x2be60c str r9, [r2, #0x14] */
/* @0x2be610 ldr r3, [r2] */
/* @0x2be614 str r12, [sp, #0x4] */
/* @0x2be618 blx r3 */
/* @0x2be61c ldr r12, [sp, #0x4] */
/* @0x2be620 cmp r4, #0 */
/* @0x2be624 sub r0, r4, #1 */
/* @0x2be628 beq 0x2be650 <jpeg_make_d_derived_tbl+0x140> */
/* @0x2be62c uxtb r1, r5 */
/* @0x2be630 add r2, r10, r6 */
/* @0x2be634 mov r3, #0 */
/* @0x2be638 strb r1, [r2, r3] */
/* @0x2be63c add r3, r3, #1 */
/* @0x2be640 cmp r3, r4 */
/* @0x2be644 bne 0x2be638 <jpeg_make_d_derived_tbl+0x128> */
/* @0x2be648 add r6, r6, #1 */
/* @0x2be64c add r6, r0, r6 */
/* @0x2be650 add r5, r5, #1 */
/* @0x2be654 cmp r5, #17 */
/* @0x2be658 bne 0x2be5f4 <jpeg_make_d_derived_tbl+0xe4> */
/* @0x2be65c mov r7, r8 */
/* @0x2be660 mov r8, r12 */
/* @0x2be664 add r12, sp, #1328 */
/* @0x2be668 mov r4, #0 */
/* @0x2be66c add r3, r12, r6 */
/* @0x2be670 str r6, [sp, #0xc] */
/* @0x2be674 strb r4, [r3, #-0x108] */
/* @0x2be678 ldrb r5, [sp, #0x428] */
/* @0x2be67c cmp r5, r4 */
/* @0x2be680 mov r9, r5 */
/* @0x2be684 beq 0x2be6f0 <jpeg_make_d_derived_tbl+0x1e0> */
/* @0x2be688 add r10, sp, #36 */
/* @0x2be68c add r1, sp, #1056 */
/* @0x2be690 mov r6, r4 */
/* @0x2be694 mov r12, #1 */
/* @0x2be698 add r1, r1, #8 */
/* @0x2be69c str r1, [sp, #0x8] */
/* @0x2be6a0 cmp r5, r9 */
/* @0x2be6a4 mov r1, r5 */
/* @0x2be6a8 bne 0x2be6d8 <jpeg_make_d_derived_tbl+0x1c8> */
/* @0x2be6ac sub r3, r6, #1 */
/* @0x2be6b0 add lr, sp, #1056 */
/* @0x2be6b4 add lr, lr, #8 */
/* @0x2be6b8 add r2, lr, r6 */
/* @0x2be6bc add r3, r10, r3, lsl #2 */
/* @0x2be6c0 ldrb r5, [r2, #0x1]! */
/* @0x2be6c4 add r6, r6, #1 */
/* @0x2be6c8 str r4, [r3, #0x4]! */
/* @0x2be6cc add r4, r4, #1 */
/* @0x2be6d0 cmp r5, r1 */
/* @0x2be6d4 beq 0x2be6c0 <jpeg_make_d_derived_tbl+0x1b0> */
/* @0x2be6d8 cmp r4, r12, lsl r9 */
/* @0x2be6dc bge 0x2be884 <jpeg_make_d_derived_tbl+0x374> */
/* @0x2be6e0 cmp r5, #0 */
/* @0x2be6e4 lsl r4, r4, #1 */
/* @0x2be6e8 add r9, r9, #1 */
/* @0x2be6ec bne 0x2be6a0 <jpeg_make_d_derived_tbl+0x190> */
/* @0x2be6f0 mov r1, r8 */
/* @0x2be6f4 mov r2, #1 */
/* @0x2be6f8 mov r3, #0 */
/* @0x2be6fc mvn r0, #0 */
/* @0x2be700 ldrb r12, [r7, r2] */
/* @0x2be704 cmp r12, #0 */
/* @0x2be708 streq r0, [r1, #0x4] */
/* @0x2be70c beq 0x2be738 <jpeg_make_d_derived_tbl+0x228> */
/* @0x2be710 add lr, sp, #1328 */
/* @0x2be714 add r12, lr, r3, lsl #2 */
/* @0x2be718 ldr r12, [r12, #-0x50c] */
/* @0x2be71c rsb r12, r12, r3 */
/* @0x2be720 str r12, [r1, #0x4c] */
/* @0x2be724 ldrb r12, [r7, r2] */
/* @0x2be728 add r3, r3, r12 */
/* @0x2be72c add r12, lr, r3, lsl #2 */
/* @0x2be730 ldr r12, [r12, #-0x510] */
/* @0x2be734 str r12, [r1, #0x4] */
/* @0x2be738 add r2, r2, #1 */
/* @0x2be73c add r1, r1, #4 */
/* @0x2be740 cmp r2, #17 */
/* @0x2be744 bne 0x2be700 <jpeg_make_d_derived_tbl+0x1f0> */
/* @0x2be748 mov r1, #0 */
/* @0x2be74c movw r3, #0xffff */
/* @0x2be750 add r0, r8, #144 */
/* @0x2be754 movt r3, #0xf */
/* @0x2be758 mov r2, #1024 */
/* @0x2be75c str r3, [r8, #0x44] */
/* @0x2be760 bl 0xb65b0 <memset@plt> */
/* @0x2be764 mov r5, #0 */
/* @0x2be768 mov r0, #1 */
/* @0x2be76c add r3, sp, #36 */
/* @0x2be770 add r1, r8, #140 */
/* @0x2be774 str r3, [sp, #0x18] */
/* @0x2be778 str r1, [sp, #0x8] */
/* @0x2be77c str r11, [sp, #0x1c] */
/* @0x2be780 ldrb r3, [r7, r0] */
/* @0x2be784 cmp r3, #0 */
/* @0x2be788 beq 0x2be7fc <jpeg_make_d_derived_tbl+0x2ec> */
/* @0x2be78c sub r9, r5, #1 */
/* @0x2be790 ldr r3, [sp, #0x18] */
/* @0x2be794 mov r2, #1 */
/* @0x2be798 rsb r10, r0, #8 */
/* @0x2be79c lsl r11, r2, r10 */
/* @0x2be7a0 add r9, r3, r9, lsl #2 */
/* @0x2be7a4 mov r6, r2 */
/* @0x2be7a8 ldr r12, [r9, #0x4]! */
/* @0x2be7ac add r4, r7, r5 */
/* @0x2be7b0 ldr r1, [sp, #0x8] */
/* @0x2be7b4 lsl r12, r12, r10 */
/* @0x2be7b8 add r2, r12, #1152 */
/* @0x2be7bc add r3, r12, #35 */
/* @0x2be7c0 add r12, r12, r11 */
/* @0x2be7c4 add r2, r2, #15 */
/* @0x2be7c8 add r2, r8, r2 */
/* @0x2be7cc add r3, r8, r3, lsl #2 */
/* @0x2be7d0 add r12, r1, r12, lsl #2 */
/* @0x2be7d4 str r0, [r3, #0x4]! */
/* @0x2be7d8 cmp r3, r12 */
/* @0x2be7dc ldrb r1, [r4, #0x11] */
/* @0x2be7e0 strb r1, [r2, #0x1]! */
/* @0x2be7e4 bne 0x2be7d4 <jpeg_make_d_derived_tbl+0x2c4> */
/* @0x2be7e8 ldrb r3, [r7, r0] */
/* @0x2be7ec add r6, r6, #1 */
/* @0x2be7f0 add r5, r5, #1 */
/* @0x2be7f4 cmp r3, r6 */
/* @0x2be7f8 bge 0x2be7a8 <jpeg_make_d_derived_tbl+0x298> */
/* @0x2be7fc add r0, r0, #1 */
/* @0x2be800 cmp r0, #9 */
/* @0x2be804 bne 0x2be780 <jpeg_make_d_derived_tbl+0x270> */
/* @0x2be808 ldr r12, [sp, #0x14] */
/* @0x2be80c ldr r11, [sp, #0x1c] */
/* @0x2be810 cmp r12, #0 */
/* @0x2be814 beq 0x2be864 <jpeg_make_d_derived_tbl+0x354> */
/* @0x2be818 ldr r3, [sp, #0xc] */
/* @0x2be81c cmp r3, #0 */
/* @0x2be820 beq 0x2be864 <jpeg_make_d_derived_tbl+0x354> */
/* @0x2be824 add r7, r7, #16 */
/* @0x2be828 mov r5, #8 */
/* @0x2be82c add r4, r7, r3 */
/* @0x2be830 b 0x2be83c <jpeg_make_d_derived_tbl+0x32c> */
/* @0x2be834 cmp r7, r4 */
/* @0x2be838 beq 0x2be864 <jpeg_make_d_derived_tbl+0x354> */
/* @0x2be83c ldrb r3, [r7, #0x1]! */
/* @0x2be840 cmp r3, #15 */
/* @0x2be844 bls 0x2be834 <jpeg_make_d_derived_tbl+0x324> */
/* @0x2be848 ldr r3, [r11] */
/* @0x2be84c mov r0, r11 */
/* @0x2be850 str r5, [r3, #0x14] */
/* @0x2be854 ldr r3, [r3] */
/* @0x2be858 blx r3 */
/* @0x2be85c cmp r7, r4 */
/* @0x2be860 bne 0x2be83c <jpeg_make_d_derived_tbl+0x32c> */
/* @0x2be864 ldr r12, [sp, #0x10] */
/* @0x2be868 ldr r2, [sp, #0x52c] */
/* @0x2be86c ldr r3, [r12] */
/* @0x2be870 cmp r2, r3 */
/* @0x2be874 bne 0x2be8a8 <jpeg_make_d_derived_tbl+0x398> */
/* @0x2be878 add sp, sp, #1328 */
/* @0x2be87c add sp, sp, #4 */
/* @0x2be880 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2be884 ldr r3, [r11] */
/* @0x2be888 mov r2, #8 */
/* @0x2be88c mov r0, r11 */
/* @0x2be890 str r2, [r3, #0x14] */
/* @0x2be894 ldr r3, [r3] */
/* @0x2be898 str r12, [sp, #0x4] */
/* @0x2be89c blx r3 */
/* @0x2be8a0 ldr r12, [sp, #0x4] */
/* @0x2be8a4 b 0x2be6e0 <jpeg_make_d_derived_tbl+0x1d0> */
/* @0x2be8a8 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2be8ac andseq pc, r2, r4, lsr r4 */

/* ── FUNC 0x2be8b0 · anon_2be8b0 · size=380 · insn=95 */
/* @0x2be8b0 ldr r3, [r0, #0x16c] */
/* @0x2be8b4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2be8b8 cmp r3, #0 */
/* @0x2be8bc mov r4, r0 */
/* @0x2be8c0 ldr r5, [r0, #0x198] */
/* @0x2be8c4 bne 0x2be8d4 <jpeg_make_d_derived_tbl+0x3c4> */
/* @0x2be8c8 ldr r3, [r0, #0x170] */
/* @0x2be8cc cmp r3, #63 */
/* @0x2be8d0 beq 0x2bea10 <jpeg_make_d_derived_tbl+0x500> */
/* @0x2be8d4 ldr r3, [r4] */
/* @0x2be8d8 mov r2, #122 */
/* @0x2be8dc mov r0, r4 */
/* @0x2be8e0 mvn r1, #0 */
/* @0x2be8e4 str r2, [r3, #0x14] */
/* @0x2be8e8 ldr r3, [r3, #0x4] */
/* @0x2be8ec blx r3 */
/* @0x2be8f0 ldr r3, [r4, #0x124] */
/* @0x2be8f4 cmp r3, #0 */
/* @0x2be8f8 ble 0x2be960 <jpeg_make_d_derived_tbl+0x450> */
/* @0x2be8fc mov r6, #0 */
/* @0x2be900 mov r8, r4 */
/* @0x2be904 mov r10, r6 */
/* @0x2be908 mov r7, r5 */
/* @0x2be90c ldr r3, [r8, #0x128] */
/* @0x2be910 mov r1, #1 */
/* @0x2be914 mov r0, r4 */
/* @0x2be918 add r6, r6, r1 */
/* @0x2be91c add r8, r8, #4 */
/* @0x2be920 add r7, r7, #4 */
/* @0x2be924 ldr r2, [r3, #0x14] */
/* @0x2be928 ldr r9, [r3, #0x18] */
/* @0x2be92c add r3, r2, #10 */
/* @0x2be930 add r3, r5, r3, lsl #2 */
/* @0x2be934 bl 0x2be510 <jpeg_make_d_derived_tbl> */
/* @0x2be938 add r3, r9, #14 */
/* @0x2be93c mov r2, r9 */
/* @0x2be940 mov r0, r4 */
/* @0x2be944 add r3, r5, r3, lsl #2 */
/* @0x2be948 mov r1, #0 */
/* @0x2be94c bl 0x2be510 <jpeg_make_d_derived_tbl> */
/* @0x2be950 str r10, [r7, #0x10] */
/* @0x2be954 ldr r3, [r4, #0x124] */
/* @0x2be958 cmp r3, r6 */
/* @0x2be95c bgt 0x2be90c <jpeg_make_d_derived_tbl+0x3fc> */
/* @0x2be960 ldr r3, [r4, #0x140] */
/* @0x2be964 cmp r3, #0 */
/* @0x2be968 ble 0x2be9f4 <jpeg_make_d_derived_tbl+0x4e4> */
/* @0x2be96c mov r12, r4 */
/* @0x2be970 mov r2, r5 */
/* @0x2be974 mov r1, r5 */
/* @0x2be978 mov r0, #0 */
/* @0x2be97c mov r7, #1 */
/* @0x2be980 ldr r3, [r12, #0x144] */
/* @0x2be984 add r3, r3, #74 */
/* @0x2be988 ldr r3, [r4, r3, lsl #2] */
/* @0x2be98c ldr r6, [r3, #0x14] */
/* @0x2be990 add r6, r6, #10 */
/* @0x2be994 ldr r6, [r5, r6, lsl #2] */
/* @0x2be998 str r6, [r2, #0x48] */
/* @0x2be99c ldr r6, [r3, #0x18] */
/* @0x2be9a0 add r6, r6, #14 */
/* @0x2be9a4 ldr r6, [r5, r6, lsl #2] */
/* @0x2be9a8 str r6, [r2, #0x70] */
/* @0x2be9ac ldrb r6, [r3, #0x30] */
/* @0x2be9b0 cmp r6, #0 */
/* @0x2be9b4 strbeq r6, [r1, #0xa2] */
/* @0x2be9b8 strbeq r6, [r1, #0x98] */
/* @0x2be9bc beq 0x2be9d8 <jpeg_make_d_derived_tbl+0x4c8> */
/* @0x2be9c0 strb r7, [r1, #0x98] */
/* @0x2be9c4 ldr r3, [r3, #0x24] */
/* @0x2be9c8 cmp r3, #1 */
/* @0x2be9cc movle r3, #0 */
/* @0x2be9d0 movgt r3, #1 */
/* @0x2be9d4 strb r3, [r1, #0xa2] */
/* @0x2be9d8 ldr r3, [r4, #0x140] */
/* @0x2be9dc add r0, r0, #1 */
/* @0x2be9e0 add r12, r12, #4 */
/* @0x2be9e4 add r2, r2, #4 */
/* @0x2be9e8 cmp r3, r0 */
/* @0x2be9ec add r1, r1, #1 */
/* @0x2be9f0 bgt 0x2be980 <jpeg_make_d_derived_tbl+0x470> */
/* @0x2be9f4 mov r3, #0 */
/* @0x2be9f8 strb r3, [r5, #0x8] */
/* @0x2be9fc ldr r2, [r4, #0xfc] */
/* @0x2bea00 str r3, [r5, #0x10] */
/* @0x2bea04 str r3, [r5, #0xc] */
/* @0x2bea08 str r2, [r5, #0x24] */
/* @0x2bea0c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2bea10 ldr r3, [r0, #0x174] */
/* @0x2bea14 cmp r3, #0 */
/* @0x2bea18 bne 0x2be8d4 <jpeg_make_d_derived_tbl+0x3c4> */
/* @0x2bea1c ldr r3, [r0, #0x178] */
/* @0x2bea20 cmp r3, #0 */
/* @0x2bea24 beq 0x2be8f0 <jpeg_make_d_derived_tbl+0x3e0> */
/* @0x2bea28 b 0x2be8d4 <jpeg_make_d_derived_tbl+0x3c4> */

/* ── FUNC 0x2bea2c · jpeg_fill_bit_buffer · size=352 · insn=88 */
/* @0x2bea2c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2bea30 sub sp, sp, #12 */
/* @0x2bea34 ldr r7, [r0, #0x10] */
/* @0x2bea38 mov r9, r0 */
/* @0x2bea3c str r3, [sp, #0x4] */
/* @0x2bea40 mov r8, r1 */
/* @0x2bea44 mov r11, r2 */
/* @0x2bea48 ldr r5, [r0] */
/* @0x2bea4c ldr r3, [r7, #0x17c] */
/* @0x2bea50 ldr r4, [r0, #0x4] */
/* @0x2bea54 cmp r3, #0 */
/* @0x2bea58 bne 0x2beb28 <jpeg_fill_bit_buffer+0xfc> */
/* @0x2bea5c cmp r2, #24 */
/* @0x2bea60 ble 0x2beac0 <jpeg_fill_bit_buffer+0x94> */
/* @0x2bea64 mov r0, #1 */
/* @0x2bea68 str r5, [r9] */
/* @0x2bea6c stmib r9, {r4, r8, r11} */
/* @0x2bea70 add sp, sp, #12 */
/* @0x2bea74 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bea78 ldr r3, [r7, #0x18] */
/* @0x2bea7c mov r0, r7 */
/* @0x2bea80 ldr r3, [r3, #0xc] */
/* @0x2bea84 blx r3 */
/* @0x2bea88 cmp r0, #0 */
/* @0x2bea8c beq 0x2beb54 <jpeg_fill_bit_buffer+0x128> */
/* @0x2bea90 ldr r3, [r7, #0x18] */
/* @0x2bea94 ldr r5, [r3] */
/* @0x2bea98 ldr r4, [r3, #0x4] */
/* @0x2bea9c ldrb r10, [r5] */
/* @0x2beaa0 sub r4, r4, #1 */
/* @0x2beaa4 add r5, r5, #1 */
/* @0x2beaa8 cmp r10, #255 */
/* @0x2beaac beq 0x2beacc <jpeg_fill_bit_buffer+0xa0> */
/* @0x2beab0 add r11, r11, #8 */
/* @0x2beab4 orr r8, r10, r8, lsl #8 */
/* @0x2beab8 cmp r11, #24 */
/* @0x2beabc bgt 0x2bea64 <jpeg_fill_bit_buffer+0x38> */
/* @0x2beac0 cmp r4, #0 */
/* @0x2beac4 bne 0x2bea9c <jpeg_fill_bit_buffer+0x70> */
/* @0x2beac8 b 0x2bea78 <jpeg_fill_bit_buffer+0x4c> */
/* @0x2beacc mov r12, r5 */
/* @0x2bead0 b 0x2beaec <jpeg_fill_bit_buffer+0xc0> */
/* @0x2bead4 ldrb r6, [r12] */
/* @0x2bead8 add r5, r12, #1 */
/* @0x2beadc sub r4, r4, #1 */
/* @0x2beae0 cmp r6, #255 */
/* @0x2beae4 mov r12, r5 */
/* @0x2beae8 bne 0x2beb1c <jpeg_fill_bit_buffer+0xf0> */
/* @0x2beaec cmp r4, #0 */
/* @0x2beaf0 bne 0x2bead4 <jpeg_fill_bit_buffer+0xa8> */
/* @0x2beaf4 ldr r3, [r7, #0x18] */
/* @0x2beaf8 mov r0, r7 */
/* @0x2beafc ldr r3, [r3, #0xc] */
/* @0x2beb00 blx r3 */
/* @0x2beb04 cmp r0, #0 */
/* @0x2beb08 beq 0x2beb54 <jpeg_fill_bit_buffer+0x128> */
/* @0x2beb0c ldr r3, [r7, #0x18] */
/* @0x2beb10 ldr r12, [r3] */
/* @0x2beb14 ldr r4, [r3, #0x4] */
/* @0x2beb18 b 0x2bead4 <jpeg_fill_bit_buffer+0xa8> */
/* @0x2beb1c cmp r6, #0 */
/* @0x2beb20 beq 0x2beab0 <jpeg_fill_bit_buffer+0x84> */
/* @0x2beb24 str r6, [r7, #0x17c] */
/* @0x2beb28 ldr r3, [sp, #0x4] */
/* @0x2beb2c cmp r11, r3 */
/* @0x2beb30 bge 0x2bea64 <jpeg_fill_bit_buffer+0x38> */
/* @0x2beb34 ldr r3, [r7, #0x198] */
/* @0x2beb38 ldrb r3, [r3, #0x8] */
/* @0x2beb3c cmp r3, #0 */
/* @0x2beb40 beq 0x2beb60 <jpeg_fill_bit_buffer+0x134> */
/* @0x2beb44 rsb r3, r11, #25 */
/* @0x2beb48 mov r11, #25 */
/* @0x2beb4c lsl r8, r8, r3 */
/* @0x2beb50 b 0x2bea64 <jpeg_fill_bit_buffer+0x38> */
/* @0x2beb54 mov r0, #0 */
/* @0x2beb58 add sp, sp, #12 */
/* @0x2beb5c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2beb60 ldr r3, [r7] */
/* @0x2beb64 mov r2, #117 */
/* @0x2beb68 mov r0, r7 */
/* @0x2beb6c mvn r1, #0 */
/* @0x2beb70 str r2, [r3, #0x14] */
/* @0x2beb74 ldr r3, [r3, #0x4] */
/* @0x2beb78 blx r3 */
/* @0x2beb7c ldr r3, [r7, #0x198] */
/* @0x2beb80 mov r2, #1 */
/* @0x2beb84 strb r2, [r3, #0x8] */
/* @0x2beb88 b 0x2beb44 <jpeg_fill_bit_buffer+0x118> */

/* ── FUNC 0x2beb8c · jpeg_huff_decode · size=264 · insn=66 */
/* @0x2beb8c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2beb90 mov r12, r2 */
/* @0x2beb94 ldr r4, [sp, #0x20] */
/* @0x2beb98 mov r8, r3 */
/* @0x2beb9c mov r9, r0 */
/* @0x2beba0 mov r3, r1 */
/* @0x2beba4 cmp r4, r2 */
/* @0x2beba8 bgt 0x2bec4c <jpeg_huff_decode+0xc0> */
/* @0x2bebac rsb r2, r4, r12 */
/* @0x2bebb0 ldr r1, [r8, r4, lsl #2] */
/* @0x2bebb4 mvn r12, #0 */
/* @0x2bebb8 mvn r12, r12, lsl r4 */
/* @0x2bebbc and r12, r12, r3, asr r2 */
/* @0x2bebc0 cmp r12, r1 */
/* @0x2bebc4 ble 0x2bec20 <jpeg_huff_decode+0x94> */
/* @0x2bebc8 add r5, r8, r4, lsl #2 */
/* @0x2bebcc b 0x2bebec <jpeg_huff_decode+0x60> */
/* @0x2bebd0 sub r2, r2, #1 */
/* @0x2bebd4 ldr r7, [r5, #0x4]! */
/* @0x2bebd8 asr r12, r3, r2 */
/* @0x2bebdc and r12, r12, #1 */
/* @0x2bebe0 orr r12, r12, r6 */
/* @0x2bebe4 cmp r7, r12 */
/* @0x2bebe8 bge 0x2bec20 <jpeg_huff_decode+0x94> */
/* @0x2bebec cmp r2, #0 */
/* @0x2bebf0 lsl r6, r12, #1 */
/* @0x2bebf4 add r4, r4, #1 */
/* @0x2bebf8 bgt 0x2bebd0 <jpeg_huff_decode+0x44> */
/* @0x2bebfc mov r1, r3 */
/* @0x2bec00 mov r0, r9 */
/* @0x2bec04 mov r3, #1 */
/* @0x2bec08 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2bec0c cmp r0, #0 */
/* @0x2bec10 beq 0x2bec8c <jpeg_huff_decode+0x100> */
/* @0x2bec14 ldr r3, [r9, #0x8] */
/* @0x2bec18 ldr r2, [r9, #0xc] */
/* @0x2bec1c b 0x2bebd0 <jpeg_huff_decode+0x44> */
/* @0x2bec20 cmp r4, #16 */
/* @0x2bec24 str r3, [r9, #0x8] */
/* @0x2bec28 str r2, [r9, #0xc] */
/* @0x2bec2c bgt 0x2bec68 <jpeg_huff_decode+0xdc> */
/* @0x2bec30 add r4, r4, #18 */
/* @0x2bec34 ldr r2, [r8, #0x8c] */
/* @0x2bec38 ldr r3, [r8, r4, lsl #2] */
/* @0x2bec3c add r12, r2, r12 */
/* @0x2bec40 add r12, r12, r3 */
/* @0x2bec44 ldrb r0, [r12, #0x11] */
/* @0x2bec48 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2bec4c mov r3, r4 */
/* @0x2bec50 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2bec54 cmp r0, #0 */
/* @0x2bec58 beq 0x2bec8c <jpeg_huff_decode+0x100> */
/* @0x2bec5c ldr r3, [r9, #0x8] */
/* @0x2bec60 ldr r12, [r9, #0xc] */
/* @0x2bec64 b 0x2bebac <jpeg_huff_decode+0x20> */
/* @0x2bec68 ldr r0, [r9, #0x10] */
/* @0x2bec6c mov r2, #118 */
/* @0x2bec70 mvn r1, #0 */
/* @0x2bec74 ldr r3, [r0] */
/* @0x2bec78 str r2, [r3, #0x14] */
/* @0x2bec7c ldr r3, [r3, #0x4] */
/* @0x2bec80 blx r3 */
/* @0x2bec84 mov r0, #0 */
/* @0x2bec88 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2bec8c mvn r0, #0 */
/* @0x2bec90 pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x2bec94 · anon_2bec94 · size=1288 · insn=322 */
/* @0x2bec94 ldr r3, [r0, #0xfc] */
/* @0x2bec98 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2bec9c cmp r3, #0 */
/* @0x2beca0 sub sp, sp, #84 */
/* @0x2beca4 mov r10, r0 */
/* @0x2beca8 mov r6, r1 */
/* @0x2becac ldr r9, [r0, #0x198] */
/* @0x2becb0 beq 0x2becc0 <jpeg_huff_decode+0x134> */
/* @0x2becb4 ldr r4, [r9, #0x24] */
/* @0x2becb8 cmp r4, #0 */
/* @0x2becbc beq 0x2bf0fc <jpeg_huff_decode+0x570> */
/* @0x2becc0 ldrb r3, [r9, #0x8] */
/* @0x2becc4 cmp r3, #0 */
/* @0x2becc8 bne 0x2bef18 <jpeg_huff_decode+0x38c> */
/* @0x2beccc add r4, r9, #20 */
/* @0x2becd0 str r4, [sp, #0x10] */
/* @0x2becd4 add r4, sp, #44 */
/* @0x2becd8 str r4, [sp, #0x14] */
/* @0x2becdc ldr r4, [sp, #0x10] */
/* @0x2bece0 ldr r5, [r10, #0x18] */
/* @0x2bece4 ldr r12, [r10, #0x140] */
/* @0x2bece8 ldm r4, {r0, r1, r2, r3} */
/* @0x2becec cmp r12, #0 */
/* @0x2becf0 ldm r5, {r7, r8} */
/* @0x2becf4 ldr r12, [sp, #0x14] */
/* @0x2becf8 str r10, [sp, #0x4c] */
/* @0x2becfc str r7, [sp, #0x3c] */
/* @0x2bed00 stm r12, {r0, r1, r2, r3} */
/* @0x2bed04 str r8, [sp, #0x40] */
/* @0x2bed08 ldr r4, [r9, #0xc] */
/* @0x2bed0c ldr r12, [r9, #0x10] */
/* @0x2bed10 ble 0x2beefc <jpeg_huff_decode+0x370> */
/* @0x2bed14 ldr r7, [pc, #0x474] */
/* @0x2bed18 mov r8, r9 */
/* @0x2bed1c ldr r0, [pc, #0x470] */
/* @0x2bed20 mov r1, r4 */
/* @0x2bed24 add r7, pc, r7 */
/* @0x2bed28 mov r2, r12 */
/* @0x2bed2c mov r4, r10 */
/* @0x2bed30 mov r11, r8 */
/* @0x2bed34 add r0, pc, r0 */
/* @0x2bed38 sub r6, r6, #4 */
/* @0x2bed3c mov r3, #0 */
/* @0x2bed40 str r0, [sp, #0x1c] */
/* @0x2bed44 str r6, [sp, #0xc] */
/* @0x2bed48 str r3, [sp, #0x18] */
/* @0x2bed4c str r9, [sp, #0x24] */
/* @0x2bed50 str r10, [sp, #0x20] */
/* @0x2bed54 ldr r6, [sp, #0xc] */
/* @0x2bed58 cmp r2, #7 */
/* @0x2bed5c ldr r5, [r9, #0x70] */
/* @0x2bed60 ldr r8, [r6, #0x4]! */
/* @0x2bed64 str r6, [sp, #0xc] */
/* @0x2bed68 ldr r6, [r9, #0x48] */
/* @0x2bed6c ble 0x2bf0cc <jpeg_huff_decode+0x540> */
/* @0x2bed70 sub r0, r2, #8 */
/* @0x2bed74 asr r0, r1, r0 */
/* @0x2bed78 uxtb r0, r0 */
/* @0x2bed7c add r3, r0, #36 */
/* @0x2bed80 ldr r3, [r6, r3, lsl #2] */
/* @0x2bed84 cmp r3, #0 */
/* @0x2bed88 beq 0x2bf0a0 <jpeg_huff_decode+0x514> */
/* @0x2bed8c add r0, r6, r0 */
/* @0x2bed90 rsb r2, r3, r2 */
/* @0x2bed94 ldrb r6, [r0, #0x490] */
/* @0x2bed98 cmp r6, #0 */
/* @0x2bed9c beq 0x2bedd8 <jpeg_huff_decode+0x24c> */
/* @0x2beda0 cmp r2, r6 */
/* @0x2beda4 blt 0x2bf170 <jpeg_huff_decode+0x5e4> */
/* @0x2beda8 mov r12, #1 */
/* @0x2bedac rsb r2, r6, r2 */
/* @0x2bedb0 lsl r3, r12, r6 */
/* @0x2bedb4 ldr r12, [sp, #0x1c] */
/* @0x2bedb8 sub r3, r3, #1 */
/* @0x2bedbc and r3, r3, r1, asr r2 */
/* @0x2bedc0 ldr r0, [r12, r6, lsl #2] */
/* @0x2bedc4 cmp r3, r0 */
/* @0x2bedc8 addlt r6, r12, r6, lsl #2 */
/* @0x2bedcc movge r6, r3 */
/* @0x2bedd0 ldrlt r6, [r6, #0x40] */
/* @0x2bedd4 addlt r6, r6, r3 */
/* @0x2bedd8 ldrb r3, [r11, #0x98] */
/* @0x2beddc cmp r3, #0 */
/* @0x2bede0 beq 0x2bee00 <jpeg_huff_decode+0x274> */
/* @0x2bede4 ldr r3, [r4, #0x144] */
/* @0x2bede8 add r0, sp, #80 */
/* @0x2bedec add r3, r0, r3, lsl #2 */
/* @0x2bedf0 ldr r0, [r3, #-0x24] */
/* @0x2bedf4 add r6, r6, r0 */
/* @0x2bedf8 str r6, [r3, #-0x24] */
/* @0x2bedfc strh r6, [r8] */
/* @0x2bee00 ldrb r3, [r11, #0xa2] */
/* @0x2bee04 cmp r3, #0 */
/* @0x2bee08 beq 0x2befac <jpeg_huff_decode+0x420> */
/* @0x2bee0c mov r10, #1 */
/* @0x2bee10 b 0x2bee68 <jpeg_huff_decode+0x2dc> */
/* @0x2bee14 cmp r2, r6 */
/* @0x2bee18 add r10, r10, r0 */
/* @0x2bee1c blt 0x2bef8c <jpeg_huff_decode+0x400> */
/* @0x2bee20 mov r12, #1 */
/* @0x2bee24 ldr r0, [r7, r6, lsl #2] */
/* @0x2bee28 lsl r3, r12, r6 */
/* @0x2bee2c rsb r2, r6, r2 */
/* @0x2bee30 sub r3, r3, #1 */
/* @0x2bee34 and r3, r3, r1, asr r2 */
/* @0x2bee38 cmp r3, r0 */
/* @0x2bee3c addlt r6, r7, r6, lsl #2 */
/* @0x2bee40 ldrlt r0, [r6, #0x40] */
/* @0x2bee44 addlt r3, r3, r0 */
/* @0x2bee48 ldr r0, [pc, #0x348] */
/* @0x2bee4c ldr r0, [pc, r0] */
/* @0x2bee50 ldr r0, [r0, r10, lsl #2] */
/* @0x2bee54 add r10, r10, #1 */
/* @0x2bee58 cmp r10, #63 */
/* @0x2bee5c lsl r0, r0, #1 */
/* @0x2bee60 strh r3, [r8, r0] */
/* @0x2bee64 bgt 0x2beebc <jpeg_huff_decode+0x330> */
/* @0x2bee68 cmp r2, #7 */
/* @0x2bee6c ble 0x2bef5c <jpeg_huff_decode+0x3d0> */
/* @0x2bee70 sub r0, r2, #8 */
/* @0x2bee74 asr r0, r1, r0 */
/* @0x2bee78 uxtb r0, r0 */
/* @0x2bee7c add r3, r0, #36 */
/* @0x2bee80 ldr r3, [r5, r3, lsl #2] */
/* @0x2bee84 cmp r3, #0 */
/* @0x2bee88 beq 0x2bef30 <jpeg_huff_decode+0x3a4> */
/* @0x2bee8c add r0, r5, r0 */
/* @0x2bee90 rsb r2, r3, r2 */
/* @0x2bee94 ldrb r0, [r0, #0x490] */
/* @0x2bee98 ands r6, r0, #15 */
/* @0x2bee9c asr r0, r0, #4 */
/* @0x2beea0 bne 0x2bee14 <jpeg_huff_decode+0x288> */
/* @0x2beea4 cmp r0, #15 */
/* @0x2beea8 bne 0x2beebc <jpeg_huff_decode+0x330> */
/* @0x2beeac add r10, r10, #15 */
/* @0x2beeb0 add r10, r10, #1 */
/* @0x2beeb4 cmp r10, #63 */
/* @0x2beeb8 ble 0x2bee68 <jpeg_huff_decode+0x2dc> */
/* @0x2beebc ldr r6, [sp, #0x20] */
/* @0x2beec0 add r9, r9, #4 */
/* @0x2beec4 ldr r12, [sp, #0x18] */
/* @0x2beec8 add r11, r11, #1 */
/* @0x2beecc add r4, r4, #4 */
/* @0x2beed0 ldr r3, [r6, #0x140] */
/* @0x2beed4 add r12, r12, #1 */
/* @0x2beed8 str r12, [sp, #0x18] */
/* @0x2beedc cmp r3, r12 */
/* @0x2beee0 bgt 0x2bed54 <jpeg_huff_decode+0x1c8> */
/* @0x2beee4 ldr r9, [sp, #0x24] */
/* @0x2beee8 mov r4, r1 */
/* @0x2beeec ldr r5, [r6, #0x18] */
/* @0x2beef0 mov r12, r2 */
/* @0x2beef4 ldr r7, [sp, #0x3c] */
/* @0x2beef8 ldr r8, [sp, #0x40] */
/* @0x2beefc ldr r6, [sp, #0x14] */
/* @0x2bef00 stm r5, {r7, r8} */
/* @0x2bef04 str r12, [r9, #0x10] */
/* @0x2bef08 ldm r6, {r0, r1, r2, r3} */
/* @0x2bef0c ldr r12, [sp, #0x10] */
/* @0x2bef10 str r4, [r9, #0xc] */
/* @0x2bef14 stm r12, {r0, r1, r2, r3} */
/* @0x2bef18 ldr r3, [r9, #0x24] */
/* @0x2bef1c mov r0, #1 */
/* @0x2bef20 sub r3, r3, #1 */
/* @0x2bef24 str r3, [r9, #0x24] */
/* @0x2bef28 add sp, sp, #84 */
/* @0x2bef2c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bef30 add r6, sp, #60 */
/* @0x2bef34 mov r3, #9 */
/* @0x2bef38 str r3, [sp] */
/* @0x2bef3c mov r0, r6 */
/* @0x2bef40 mov r3, r5 */
/* @0x2bef44 bl 0x2beb8c <jpeg_huff_decode> */
/* @0x2bef48 cmp r0, #0 */
/* @0x2bef4c blt 0x2bf094 <jpeg_huff_decode+0x508> */
/* @0x2bef50 ldr r1, [sp, #0x44] */
/* @0x2bef54 ldr r2, [sp, #0x48] */
/* @0x2bef58 b 0x2bee98 <jpeg_huff_decode+0x30c> */
/* @0x2bef5c add r6, sp, #60 */
/* @0x2bef60 mov r3, #0 */
/* @0x2bef64 mov r0, r6 */
/* @0x2bef68 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2bef6c cmp r0, #0 */
/* @0x2bef70 beq 0x2bf094 <jpeg_huff_decode+0x508> */
/* @0x2bef74 ldr r2, [sp, #0x48] */
/* @0x2bef78 ldr r1, [sp, #0x44] */
/* @0x2bef7c cmp r2, #7 */
/* @0x2bef80 bgt 0x2bee70 <jpeg_huff_decode+0x2e4> */
/* @0x2bef84 mov r3, #1 */
/* @0x2bef88 b 0x2bef38 <jpeg_huff_decode+0x3ac> */
/* @0x2bef8c add r0, sp, #60 */
/* @0x2bef90 mov r3, r6 */
/* @0x2bef94 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2bef98 cmp r0, #0 */
/* @0x2bef9c beq 0x2bf094 <jpeg_huff_decode+0x508> */
/* @0x2befa0 ldr r1, [sp, #0x44] */
/* @0x2befa4 ldr r2, [sp, #0x48] */
/* @0x2befa8 b 0x2bee20 <jpeg_huff_decode+0x294> */
/* @0x2befac mov r6, #1 */
/* @0x2befb0 b 0x2befd0 <jpeg_huff_decode+0x444> */
/* @0x2befb4 cmp r2, r8 */
/* @0x2befb8 add r6, r6, r0 */
/* @0x2befbc blt 0x2bf078 <jpeg_huff_decode+0x4ec> */
/* @0x2befc0 rsb r2, r8, r2 */
/* @0x2befc4 add r6, r6, #1 */
/* @0x2befc8 cmp r6, #63 */
/* @0x2befcc bgt 0x2beebc <jpeg_huff_decode+0x330> */
/* @0x2befd0 cmp r2, #7 */
/* @0x2befd4 ble 0x2bf048 <jpeg_huff_decode+0x4bc> */
/* @0x2befd8 sub r0, r2, #8 */
/* @0x2befdc asr r0, r1, r0 */
/* @0x2befe0 uxtb r0, r0 */
/* @0x2befe4 add r3, r0, #36 */
/* @0x2befe8 ldr r3, [r5, r3, lsl #2] */
/* @0x2befec cmp r3, #0 */
/* @0x2beff0 beq 0x2bf01c <jpeg_huff_decode+0x490> */
/* @0x2beff4 add r0, r5, r0 */
/* @0x2beff8 rsb r2, r3, r2 */
/* @0x2beffc ldrb r0, [r0, #0x490] */
/* @0x2bf000 ands r8, r0, #15 */
/* @0x2bf004 asr r0, r0, #4 */
/* @0x2bf008 bne 0x2befb4 <jpeg_huff_decode+0x428> */
/* @0x2bf00c cmp r0, #15 */
/* @0x2bf010 bne 0x2beebc <jpeg_huff_decode+0x330> */
/* @0x2bf014 add r6, r6, #15 */
/* @0x2bf018 b 0x2befc4 <jpeg_huff_decode+0x438> */
/* @0x2bf01c add r8, sp, #60 */
/* @0x2bf020 mov r3, #9 */
/* @0x2bf024 str r3, [sp] */
/* @0x2bf028 mov r0, r8 */
/* @0x2bf02c mov r3, r5 */
/* @0x2bf030 bl 0x2beb8c <jpeg_huff_decode> */
/* @0x2bf034 cmp r0, #0 */
/* @0x2bf038 blt 0x2bf094 <jpeg_huff_decode+0x508> */
/* @0x2bf03c ldr r1, [sp, #0x44] */
/* @0x2bf040 ldr r2, [sp, #0x48] */
/* @0x2bf044 b 0x2bf000 <jpeg_huff_decode+0x474> */
/* @0x2bf048 add r8, sp, #60 */
/* @0x2bf04c mov r3, #0 */
/* @0x2bf050 mov r0, r8 */
/* @0x2bf054 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2bf058 cmp r0, #0 */
/* @0x2bf05c beq 0x2bf094 <jpeg_huff_decode+0x508> */
/* @0x2bf060 ldr r2, [sp, #0x48] */
/* @0x2bf064 ldr r1, [sp, #0x44] */
/* @0x2bf068 cmp r2, #7 */
/* @0x2bf06c bgt 0x2befd8 <jpeg_huff_decode+0x44c> */
/* @0x2bf070 mov r3, #1 */
/* @0x2bf074 b 0x2bf024 <jpeg_huff_decode+0x498> */
/* @0x2bf078 add r0, sp, #60 */
/* @0x2bf07c mov r3, r8 */
/* @0x2bf080 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2bf084 cmp r0, #0 */
/* @0x2bf088 ldrne r1, [sp, #0x44] */
/* @0x2bf08c ldrne r2, [sp, #0x48] */
/* @0x2bf090 bne 0x2befc0 <jpeg_huff_decode+0x434> */
/* @0x2bf094 mov r0, #0 */
/* @0x2bf098 add sp, sp, #84 */
/* @0x2bf09c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bf0a0 add r10, sp, #60 */
/* @0x2bf0a4 mov r3, #9 */
/* @0x2bf0a8 str r3, [sp] */
/* @0x2bf0ac mov r0, r10 */
/* @0x2bf0b0 mov r3, r6 */
/* @0x2bf0b4 bl 0x2beb8c <jpeg_huff_decode> */
/* @0x2bf0b8 subs r6, r0, #0 */
/* @0x2bf0bc blt 0x2bf094 <jpeg_huff_decode+0x508> */
/* @0x2bf0c0 ldr r1, [sp, #0x44] */
/* @0x2bf0c4 ldr r2, [sp, #0x48] */
/* @0x2bf0c8 b 0x2bed98 <jpeg_huff_decode+0x20c> */
/* @0x2bf0cc add r10, sp, #60 */
/* @0x2bf0d0 mov r3, #0 */
/* @0x2bf0d4 mov r0, r10 */
/* @0x2bf0d8 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2bf0dc cmp r0, #0 */
/* @0x2bf0e0 beq 0x2bf094 <jpeg_huff_decode+0x508> */
/* @0x2bf0e4 ldr r2, [sp, #0x48] */
/* @0x2bf0e8 ldr r1, [sp, #0x44] */
/* @0x2bf0ec cmp r2, #7 */
/* @0x2bf0f0 bgt 0x2bed70 <jpeg_huff_decode+0x1e4> */
/* @0x2bf0f4 mov r3, #1 */
/* @0x2bf0f8 b 0x2bf0a8 <jpeg_huff_decode+0x51c> */
/* @0x2bf0fc ldr r2, [r9, #0x10] */
/* @0x2bf100 ldr r3, [r0, #0x194] */
/* @0x2bf104 cmp r2, #0 */
/* @0x2bf108 add r1, r2, #7 */
/* @0x2bf10c ldr r12, [r3, #0x14] */
/* @0x2bf110 movlt r2, r1 */
/* @0x2bf114 ldr r1, [r3, #0x8] */
/* @0x2bf118 add r2, r12, r2, asr #3 */
/* @0x2bf11c str r2, [r3, #0x14] */
/* @0x2bf120 str r4, [r9, #0x10] */
/* @0x2bf124 blx r1 */
/* @0x2bf128 cmp r0, #0 */
/* @0x2bf12c beq 0x2bf094 <jpeg_huff_decode+0x508> */
/* @0x2bf130 ldr r2, [r10, #0x124] */
/* @0x2bf134 cmp r2, #0 */
/* @0x2bf138 addgt r2, r9, r2, lsl #2 */
/* @0x2bf13c movgt r3, r9 */
/* @0x2bf140 ble 0x2bf154 <jpeg_huff_decode+0x5c8> */
/* @0x2bf144 str r4, [r3, #0x14] */
/* @0x2bf148 add r3, r3, #4 */
/* @0x2bf14c cmp r3, r2 */
/* @0x2bf150 bne 0x2bf144 <jpeg_huff_decode+0x5b8> */
/* @0x2bf154 ldr r3, [r10, #0x17c] */
/* @0x2bf158 ldr r2, [r10, #0xfc] */
/* @0x2bf15c cmp r3, #0 */
/* @0x2bf160 strbeq r3, [r9, #0x8] */
/* @0x2bf164 str r2, [r9, #0x24] */
/* @0x2bf168 beq 0x2beccc <jpeg_huff_decode+0x140> */
/* @0x2bf16c b 0x2becc0 <jpeg_huff_decode+0x134> */
/* @0x2bf170 add r0, sp, #60 */
/* @0x2bf174 mov r3, r6 */
/* @0x2bf178 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2bf17c cmp r0, #0 */
/* @0x2bf180 beq 0x2bf094 <jpeg_huff_decode+0x508> */
/* @0x2bf184 ldr r1, [sp, #0x44] */
/* @0x2bf188 ldr r2, [sp, #0x48] */
/* @0x2bf18c b 0x2beda8 <jpeg_huff_decode+0x21c> */
/* @0x2bf190 strheq r1, [sp], -r12 */
/* @0x2bf194 andeq r1, sp, r12, lsr #9 */
/* @0x2bf198 andseq r2, r3, r12, asr r12 */

/* ── FUNC 0x2bf19c · jinit_huff_decoder · size=100 · insn=25 */
/* @0x2bf19c ldr r3, [r0, #0x4] */
/* @0x2bf1a0 mov r1, #1 */
/* @0x2bf1a4 push {r4, lr} */
/* @0x2bf1a8 mov r2, #172 */
/* @0x2bf1ac ldr r3, [r3] */
/* @0x2bf1b0 mov r4, r0 */
/* @0x2bf1b4 blx r3 */
/* @0x2bf1b8 ldr r1, [pc, #0x38] */
/* @0x2bf1bc ldr r2, [pc, #0x38] */
/* @0x2bf1c0 mov r3, #0 */
/* @0x2bf1c4 add r1, pc, r1 */
/* @0x2bf1c8 add r2, pc, r2 */
/* @0x2bf1cc str r0, [r4, #0x198] */
/* @0x2bf1d0 stm r0, {r1, r2} */
/* @0x2bf1d4 str r3, [r0, #0x38] */
/* @0x2bf1d8 str r3, [r0, #0x28] */
/* @0x2bf1dc str r3, [r0, #0x3c] */
/* @0x2bf1e0 str r3, [r0, #0x2c] */
/* @0x2bf1e4 str r3, [r0, #0x40] */
/* @0x2bf1e8 str r3, [r0, #0x30] */
/* @0x2bf1ec str r3, [r0, #0x44] */
/* @0x2bf1f0 str r3, [r0, #0x34] */
/* @0x2bf1f4 pop {r4, pc} */
/* @0x2bf1f8 .word 0xfffff6e4 */
/* @0x2bf1fc .word 0xfffffac4 */

/* ── FUNC 0x2bf200 · anon_2bf200 · size=1556 · insn=389 */
/* @0x2bf200 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2bf204 mov r5, r0 */
/* @0x2bf208 ldr r4, [r0, #0x184] */
/* @0x2bf20c sub sp, sp, #20 */
/* @0x2bf210 mov r8, r1 */
/* @0x2bf214 mov r7, r2 */
/* @0x2bf218 mov r9, r3 */
/* @0x2bf21c ldrb r12, [r4, #0x30] */
/* @0x2bf220 cmp r12, #0 */
/* @0x2bf224 addne r6, r4, #8 */
/* @0x2bf228 bne 0x2bf250 <jinit_huff_decoder+0xb4> */
/* @0x2bf22c ldr r3, [r0, #0x188] */
/* @0x2bf230 add r6, r4, #8 */
/* @0x2bf234 mov r1, r6 */
/* @0x2bf238 ldr r3, [r3, #0xc] */
/* @0x2bf23c blx r3 */
/* @0x2bf240 cmp r0, #0 */
/* @0x2bf244 beq 0x2bf28c <jinit_huff_decoder+0xf0> */
/* @0x2bf248 mov r3, #1 */
/* @0x2bf24c strb r3, [r4, #0x30] */
/* @0x2bf250 ldr r12, [r5, #0x18c] */
/* @0x2bf254 mov r1, r6 */
/* @0x2bf258 ldr r6, [r5, #0x118] */
/* @0x2bf25c mov r0, r5 */
/* @0x2bf260 str r8, [sp] */
/* @0x2bf264 add r2, r4, #52 */
/* @0x2bf268 stmib sp, {r7, r9} */
/* @0x2bf26c mov r3, r6 */
/* @0x2bf270 ldr r12, [r12, #0x4] */
/* @0x2bf274 blx r12 */
/* @0x2bf278 ldr r3, [r4, #0x34] */
/* @0x2bf27c cmp r6, r3 */
/* @0x2bf280 movls r3, #0 */
/* @0x2bf284 strbls r3, [r4, #0x30] */
/* @0x2bf288 strls r3, [r4, #0x34] */
/* @0x2bf28c add sp, sp, #20 */
/* @0x2bf290 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2bf294 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2bf298 mov r6, r3 */
/* @0x2bf29c ldr r4, [r0, #0x184] */
/* @0x2bf2a0 sub sp, sp, #44 */
/* @0x2bf2a4 mov r5, r0 */
/* @0x2bf2a8 mov r7, r2 */
/* @0x2bf2ac str r1, [sp, #0x10] */
/* @0x2bf2b0 ldrb r3, [r4, #0x30] */
/* @0x2bf2b4 cmp r3, #0 */
/* @0x2bf2b8 beq 0x2bf344 <jinit_huff_decoder+0x1a8> */
/* @0x2bf2bc ldr r3, [r4, #0x44] */
/* @0x2bf2c0 cmp r3, #1 */
/* @0x2bf2c4 beq 0x2bf384 <jinit_huff_decoder+0x1e8> */
/* @0x2bf2c8 cmp r3, #2 */
/* @0x2bf2cc beq 0x2bf2e0 <jinit_huff_decoder+0x144> */
/* @0x2bf2d0 cmp r3, #0 */
/* @0x2bf2d4 beq 0x2bf394 <jinit_huff_decoder+0x1f8> */
/* @0x2bf2d8 add sp, sp, #44 */
/* @0x2bf2dc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bf2e0 ldr r1, [r4, #0x40] */
/* @0x2bf2e4 add r3, r4, #52 */
/* @0x2bf2e8 ldr r12, [r5, #0x18c] */
/* @0x2bf2ec mov r0, r5 */
/* @0x2bf2f0 ldr lr, [sp, #0x10] */
/* @0x2bf2f4 add r1, r1, #14 */
/* @0x2bf2f8 str r3, [sp, #0x14] */
/* @0x2bf2fc ldr r1, [r4, r1, lsl #2] */
/* @0x2bf300 ldr r3, [r4, #0x48] */
/* @0x2bf304 ldr r2, [sp, #0x14] */
/* @0x2bf308 str lr, [sp] */
/* @0x2bf30c str r7, [sp, #0x4] */
/* @0x2bf310 str r6, [sp, #0x8] */
/* @0x2bf314 ldr r12, [r12, #0x4] */
/* @0x2bf318 blx r12 */
/* @0x2bf31c ldr r2, [r4, #0x34] */
/* @0x2bf320 ldr r3, [r4, #0x48] */
/* @0x2bf324 cmp r2, r3 */
/* @0x2bf328 blo 0x2bf2d8 <jinit_huff_decoder+0x13c> */
/* @0x2bf32c mov r3, #0 */
/* @0x2bf330 str r3, [r4, #0x44] */
/* @0x2bf334 ldr r3, [r7] */
/* @0x2bf338 cmp r6, r3 */
/* @0x2bf33c bhi 0x2bf39c <jinit_huff_decoder+0x200> */
/* @0x2bf340 b 0x2bf2d8 <jinit_huff_decoder+0x13c> */
/* @0x2bf344 ldr r2, [r4, #0x40] */
/* @0x2bf348 ldr r3, [r0, #0x188] */
/* @0x2bf34c add r2, r2, #14 */
/* @0x2bf350 ldr r3, [r3, #0xc] */
/* @0x2bf354 ldr r1, [r4, r2, lsl #2] */
/* @0x2bf358 blx r3 */
/* @0x2bf35c cmp r0, #0 */
/* @0x2bf360 beq 0x2bf2d8 <jinit_huff_decoder+0x13c> */
/* @0x2bf364 ldr r3, [r4, #0x4c] */
/* @0x2bf368 mov r2, #1 */
/* @0x2bf36c strb r2, [r4, #0x30] */
/* @0x2bf370 add r3, r3, r2 */
/* @0x2bf374 str r3, [r4, #0x4c] */
/* @0x2bf378 ldr r3, [r4, #0x44] */
/* @0x2bf37c cmp r3, #1 */
/* @0x2bf380 bne 0x2bf2c8 <jinit_huff_decoder+0x12c> */
/* @0x2bf384 add r3, r4, #52 */
/* @0x2bf388 str r3, [sp, #0x14] */
/* @0x2bf38c ldr r3, [r4, #0x48] */
/* @0x2bf390 b 0x2bf3c8 <jinit_huff_decoder+0x22c> */
/* @0x2bf394 add lr, r4, #52 */
/* @0x2bf398 str lr, [sp, #0x14] */
/* @0x2bf39c ldr r3, [r5, #0x11c] */
/* @0x2bf3a0 mov r12, #0 */
/* @0x2bf3a4 ldr r2, [r4, #0x4c] */
/* @0x2bf3a8 ldr r10, [r5, #0x118] */
/* @0x2bf3ac cmp r2, r3 */
/* @0x2bf3b0 str r12, [r4, #0x34] */
/* @0x2bf3b4 sub r3, r10, #1 */
/* @0x2bf3b8 str r3, [r4, #0x48] */
/* @0x2bf3bc beq 0x2bf53c <jinit_huff_decoder+0x3a0> */
/* @0x2bf3c0 mov r2, #1 */
/* @0x2bf3c4 str r2, [r4, #0x44] */
/* @0x2bf3c8 ldr r1, [r4, #0x40] */
/* @0x2bf3cc mov r0, r5 */
/* @0x2bf3d0 ldr r12, [r5, #0x18c] */
/* @0x2bf3d4 ldr lr, [sp, #0x10] */
/* @0x2bf3d8 add r1, r1, #14 */
/* @0x2bf3dc ldr r2, [sp, #0x14] */
/* @0x2bf3e0 ldr r1, [r4, r1, lsl #2] */
/* @0x2bf3e4 str lr, [sp] */
/* @0x2bf3e8 str r7, [sp, #0x4] */
/* @0x2bf3ec str r6, [sp, #0x8] */
/* @0x2bf3f0 ldr r12, [r12, #0x4] */
/* @0x2bf3f4 blx r12 */
/* @0x2bf3f8 ldr r2, [r4, #0x34] */
/* @0x2bf3fc ldr r3, [r4, #0x48] */
/* @0x2bf400 cmp r2, r3 */
/* @0x2bf404 blo 0x2bf2d8 <jinit_huff_decoder+0x13c> */
/* @0x2bf408 ldr r3, [r4, #0x4c] */
/* @0x2bf40c cmp r3, #1 */
/* @0x2bf410 beq 0x2bf44c <jinit_huff_decoder+0x2b0> */
/* @0x2bf414 ldr r2, [r4, #0x40] */
/* @0x2bf418 mov r3, #0 */
/* @0x2bf41c strb r3, [r4, #0x30] */
/* @0x2bf420 mov r1, #2 */
/* @0x2bf424 ldr r3, [r5, #0x118] */
/* @0x2bf428 eor r2, r2, #1 */
/* @0x2bf42c str r1, [r4, #0x44] */
/* @0x2bf430 str r2, [r4, #0x40] */
/* @0x2bf434 add r1, r3, #1 */
/* @0x2bf438 add r3, r3, #2 */
/* @0x2bf43c str r1, [r4, #0x34] */
/* @0x2bf440 str r3, [r4, #0x48] */
/* @0x2bf444 add sp, sp, #44 */
/* @0x2bf448 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bf44c ldr r3, [r5, #0x24] */
/* @0x2bf450 ldr r7, [r5, #0x118] */
/* @0x2bf454 cmp r3, #0 */
/* @0x2bf458 ldr r8, [r5, #0x184] */
/* @0x2bf45c str r3, [sp, #0x18] */
/* @0x2bf460 str r7, [sp, #0x14] */
/* @0x2bf464 ldr r9, [r5, #0xc4] */
/* @0x2bf468 ble 0x2bf414 <jinit_huff_decoder+0x278> */
/* @0x2bf46c add r3, r7, #1 */
/* @0x2bf470 mov r7, #0 */
/* @0x2bf474 str r3, [sp, #0x1c] */
/* @0x2bf478 str r4, [sp, #0x20] */
/* @0x2bf47c str r5, [sp, #0x24] */
/* @0x2bf480 ldr r3, [r9, #0xc] */
/* @0x2bf484 ldr r0, [r9, #0x24] */
/* @0x2bf488 ldr r1, [sp, #0x14] */
/* @0x2bf48c mul r0, r0, r3 */
/* @0x2bf490 bl 0x318d10 <__divsi3> */
/* @0x2bf494 ldr r2, [r8, #0x38] */
/* @0x2bf498 ldr r3, [r8, #0x3c] */
/* @0x2bf49c ldr r1, [r2, r7, lsl #2] */
/* @0x2bf4a0 ldr r2, [r3, r7, lsl #2] */
/* @0x2bf4a4 subs r4, r0, #0 */
/* @0x2bf4a8 ble 0x2bf51c <jinit_huff_decoder+0x380> */
/* @0x2bf4ac ldr r3, [sp, #0x1c] */
/* @0x2bf4b0 rsb r6, r4, r4, lsl #30 */
/* @0x2bf4b4 lsl r11, r4, #2 */
/* @0x2bf4b8 str r7, [sp, #0x10] */
/* @0x2bf4bc lsl r6, r6, #2 */
/* @0x2bf4c0 mul r0, r3, r4 */
/* @0x2bf4c4 add r10, r1, r6 */
/* @0x2bf4c8 add r6, r2, r6 */
/* @0x2bf4cc mov r3, #0 */
/* @0x2bf4d0 add r4, r0, r4 */
/* @0x2bf4d4 lsl r0, r0, #2 */
/* @0x2bf4d8 lsl r4, r4, #2 */
/* @0x2bf4dc add r5, r1, r4 */
/* @0x2bf4e0 add r12, r1, r0 */
/* @0x2bf4e4 add r4, r2, r4 */
/* @0x2bf4e8 add r0, r2, r0 */
/* @0x2bf4ec ldr r7, [r12, r3] */
/* @0x2bf4f0 str r7, [r10, r3] */
/* @0x2bf4f4 ldr r7, [r0, r3] */
/* @0x2bf4f8 str r7, [r6, r3] */
/* @0x2bf4fc ldr r7, [r1, r3] */
/* @0x2bf500 str r7, [r5, r3] */
/* @0x2bf504 ldr r7, [r2, r3] */
/* @0x2bf508 str r7, [r4, r3] */
/* @0x2bf50c add r3, r3, #4 */
/* @0x2bf510 cmp r3, r11 */
/* @0x2bf514 bne 0x2bf4ec <jinit_huff_decoder+0x350> */
/* @0x2bf518 ldr r7, [sp, #0x10] */
/* @0x2bf51c ldr r3, [sp, #0x18] */
/* @0x2bf520 add r7, r7, #1 */
/* @0x2bf524 add r9, r9, #84 */
/* @0x2bf528 cmp r7, r3 */
/* @0x2bf52c bne 0x2bf480 <jinit_huff_decoder+0x2e4> */
/* @0x2bf530 ldr r4, [sp, #0x20] */
/* @0x2bf534 ldr r5, [sp, #0x24] */
/* @0x2bf538 b 0x2bf414 <jinit_huff_decoder+0x278> */
/* @0x2bf53c ldr r2, [r5, #0x24] */
/* @0x2bf540 ldr r8, [r5, #0x184] */
/* @0x2bf544 cmp r2, r12 */
/* @0x2bf548 ldr r9, [r5, #0xc4] */
/* @0x2bf54c ble 0x2bf3c0 <jinit_huff_decoder+0x224> */
/* @0x2bf550 ldr r3, [r8, #0x40] */
/* @0x2bf554 str r5, [sp, #0x1c] */
/* @0x2bf558 mov r5, r12 */
/* @0x2bf55c add r3, r3, #14 */
/* @0x2bf560 str r6, [sp, #0x24] */
/* @0x2bf564 mov r6, r9 */
/* @0x2bf568 mov r9, r2 */
/* @0x2bf56c mov r11, r3 */
/* @0x2bf570 str r4, [sp, #0x18] */
/* @0x2bf574 str r7, [sp, #0x20] */
/* @0x2bf578 ldr r3, [r6, #0xc] */
/* @0x2bf57c mov r1, r10 */
/* @0x2bf580 ldr r4, [r6, #0x24] */
/* @0x2bf584 mul r7, r4, r3 */
/* @0x2bf588 mov r0, r7 */
/* @0x2bf58c bl 0x318d10 <__divsi3> */
/* @0x2bf590 mov r1, r7 */
/* @0x2bf594 mov r4, r0 */
/* @0x2bf598 ldr r0, [r6, #0x2c] */
/* @0x2bf59c bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x2bf5a0 cmp r1, #0 */
/* @0x2bf5a4 movne r7, r1 */
/* @0x2bf5a8 cmp r5, #0 */
/* @0x2bf5ac bne 0x2bf5c4 <jinit_huff_decoder+0x428> */
/* @0x2bf5b0 sub r0, r7, #1 */
/* @0x2bf5b4 mov r1, r4 */
/* @0x2bf5b8 bl 0x318d10 <__divsi3> */
/* @0x2bf5bc add r0, r0, #1 */
/* @0x2bf5c0 str r0, [r8, #0x48] */
/* @0x2bf5c4 lsl r4, r4, #1 */
/* @0x2bf5c8 ldr r1, [r8, r11, lsl #2] */
/* @0x2bf5cc cmp r4, #0 */
/* @0x2bf5d0 ldr r1, [r1, r5, lsl #2] */
/* @0x2bf5d4 ble 0x2bf604 <jinit_huff_decoder+0x468> */
/* @0x2bf5d8 sub r0, r7, #-1073741823 */
/* @0x2bf5dc add r4, r4, r7 */
/* @0x2bf5e0 lsl r0, r0, #2 */
/* @0x2bf5e4 add r4, r1, r4, lsl #2 */
/* @0x2bf5e8 add r3, r0, #4 */
/* @0x2bf5ec add r0, r1, r0 */
/* @0x2bf5f0 add r3, r1, r3 */
/* @0x2bf5f4 ldr r2, [r0] */
/* @0x2bf5f8 str r2, [r3], #4 */
/* @0x2bf5fc cmp r3, r4 */
/* @0x2bf600 bne 0x2bf5f4 <jinit_huff_decoder+0x458> */
/* @0x2bf604 add r5, r5, #1 */
/* @0x2bf608 add r6, r6, #84 */
/* @0x2bf60c cmp r5, r9 */
/* @0x2bf610 bne 0x2bf578 <jinit_huff_decoder+0x3dc> */
/* @0x2bf614 add r4, sp, #24 */
/* @0x2bf618 ldr r6, [sp, #0x24] */
/* @0x2bf61c ldm r4, {r4, r5, r7} */
/* @0x2bf620 ldr r3, [r4, #0x48] */
/* @0x2bf624 b 0x2bf3c0 <jinit_huff_decoder+0x224> */
/* @0x2bf628 str lr, [sp, #-0x4]! */
/* @0x2bf62c sub sp, sp, #20 */
/* @0x2bf630 ldr r12, [r0, #0x18c] */
/* @0x2bf634 str r1, [sp] */
/* @0x2bf638 mov r1, #0 */
/* @0x2bf63c str r2, [sp, #0x4] */
/* @0x2bf640 mov r2, r1 */
/* @0x2bf644 str r3, [sp, #0x8] */
/* @0x2bf648 mov r3, r1 */
/* @0x2bf64c ldr r12, [r12, #0x4] */
/* @0x2bf650 blx r12 */
/* @0x2bf654 add sp, sp, #20 */
/* @0x2bf658 ldr pc, [sp], #4 */
/* @0x2bf65c cmp r1, #0 */
/* @0x2bf660 mov r3, r0 */
/* @0x2bf664 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2bf668 sub sp, sp, #20 */
/* @0x2bf66c ldr r7, [r0, #0x184] */
/* @0x2bf670 beq 0x2bf6ac <jinit_huff_decoder+0x510> */
/* @0x2bf674 cmp r1, #2 */
/* @0x2bf678 beq 0x2bf698 <jinit_huff_decoder+0x4fc> */
/* @0x2bf67c ldr r3, [r0] */
/* @0x2bf680 mov r1, #4 */
/* @0x2bf684 ldr r2, [r3] */
/* @0x2bf688 str r1, [r3, #0x14] */
/* @0x2bf68c blx r2 */
/* @0x2bf690 add sp, sp, #20 */
/* @0x2bf694 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bf698 ldr r3, [pc, #0x168] */
/* @0x2bf69c add r3, pc, r3 */
/* @0x2bf6a0 str r3, [r7, #0x4] */
/* @0x2bf6a4 add sp, sp, #20 */
/* @0x2bf6a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bf6ac ldr r2, [r0, #0x1a0] */
/* @0x2bf6b0 ldrb r2, [r2, #0x8] */
/* @0x2bf6b4 cmp r2, #0 */
/* @0x2bf6b8 bne 0x2bf6dc <jinit_huff_decoder+0x540> */
/* @0x2bf6bc ldr r3, [pc, #0x148] */
/* @0x2bf6c0 add r3, pc, r3 */
/* @0x2bf6c4 str r3, [r7, #0x4] */
/* @0x2bf6c8 mov r3, #0 */
/* @0x2bf6cc strb r3, [r7, #0x30] */
/* @0x2bf6d0 str r3, [r7, #0x34] */
/* @0x2bf6d4 add sp, sp, #20 */
/* @0x2bf6d8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bf6dc ldr r2, [r0, #0x24] */
/* @0x2bf6e0 ldr r0, [r0, #0x118] */
/* @0x2bf6e4 ldr r1, [pc, #0x124] */
/* @0x2bf6e8 cmp r2, #0 */
/* @0x2bf6ec ldr r9, [r3, #0xc4] */
/* @0x2bf6f0 add r1, pc, r1 */
/* @0x2bf6f4 str r0, [sp, #0x4] */
/* @0x2bf6f8 str r1, [r7, #0x4] */
/* @0x2bf6fc ble 0x2bf7f4 <jinit_huff_decoder+0x658> */
/* @0x2bf700 ldr r3, [sp, #0x4] */
/* @0x2bf704 mov r8, r7 */
/* @0x2bf708 add r2, r7, r2, lsl #2 */
/* @0x2bf70c str r2, [sp, #0x8] */
/* @0x2bf710 add r3, r3, #2 */
/* @0x2bf714 str r3, [sp, #0xc] */
/* @0x2bf718 ldr r3, [r9, #0xc] */
/* @0x2bf71c ldr r0, [r9, #0x24] */
/* @0x2bf720 ldr r1, [sp, #0x4] */
/* @0x2bf724 mul r0, r0, r3 */
/* @0x2bf728 bl 0x318d10 <__divsi3> */
/* @0x2bf72c ldr r3, [sp, #0xc] */
/* @0x2bf730 ldr r2, [r7, #0x38] */
/* @0x2bf734 ldr r12, [r7, #0x3c] */
/* @0x2bf738 ldr r1, [r8, #0x8] */
/* @0x2bf73c mul r10, r3, r0 */
/* @0x2bf740 rsb r3, r7, r8 */
/* @0x2bf744 ldr r2, [r2, r3] */
/* @0x2bf748 cmp r10, #0 */
/* @0x2bf74c ldr r12, [r12, r3] */
/* @0x2bf750 lslgt r5, r10, #2 */
/* @0x2bf754 movgt r3, #0 */
/* @0x2bf758 ble 0x2bf774 <jinit_huff_decoder+0x5d8> */
/* @0x2bf75c ldr r4, [r1, r3] */
/* @0x2bf760 str r4, [r12, r3] */
/* @0x2bf764 str r4, [r2, r3] */
/* @0x2bf768 add r3, r3, #4 */
/* @0x2bf76c cmp r3, r5 */
/* @0x2bf770 bne 0x2bf75c <jinit_huff_decoder+0x5c0> */
/* @0x2bf774 lsl r11, r0, #1 */
/* @0x2bf778 cmp r11, #0 */
/* @0x2bf77c ble 0x2bf7c4 <jinit_huff_decoder+0x628> */
/* @0x2bf780 sub r10, r10, r0, lsl #2 */
/* @0x2bf784 lsl r6, r0, #3 */
/* @0x2bf788 add r11, r11, r10 */
/* @0x2bf78c mov r3, #0 */
/* @0x2bf790 lsl r10, r10, #2 */
/* @0x2bf794 lsl r11, r11, #2 */
/* @0x2bf798 add r5, r12, r10 */
/* @0x2bf79c add r4, r1, r11 */
/* @0x2bf7a0 add r12, r12, r11 */
/* @0x2bf7a4 add r1, r1, r10 */
/* @0x2bf7a8 ldr r10, [r4, r3] */
/* @0x2bf7ac str r10, [r5, r3] */
/* @0x2bf7b0 ldr r10, [r1, r3] */
/* @0x2bf7b4 str r10, [r12, r3] */
/* @0x2bf7b8 add r3, r3, #4 */
/* @0x2bf7bc cmp r3, r6 */
/* @0x2bf7c0 bne 0x2bf7a8 <jinit_huff_decoder+0x60c> */
/* @0x2bf7c4 cmp r0, #0 */
/* @0x2bf7c8 subgt r0, r2, r0, lsl #2 */
/* @0x2bf7cc ble 0x2bf7e0 <jinit_huff_decoder+0x644> */
/* @0x2bf7d0 ldr r3, [r2] */
/* @0x2bf7d4 str r3, [r0], #4 */
/* @0x2bf7d8 cmp r0, r2 */
/* @0x2bf7dc bne 0x2bf7d0 <jinit_huff_decoder+0x634> */
/* @0x2bf7e0 ldr r3, [sp, #0x8] */
/* @0x2bf7e4 add r8, r8, #4 */
/* @0x2bf7e8 add r9, r9, #84 */
/* @0x2bf7ec cmp r8, r3 */
/* @0x2bf7f0 bne 0x2bf718 <jinit_huff_decoder+0x57c> */
/* @0x2bf7f4 mov r3, #0 */
/* @0x2bf7f8 str r3, [r7, #0x40] */
/* @0x2bf7fc str r3, [r7, #0x44] */
/* @0x2bf800 str r3, [r7, #0x4c] */
/* @0x2bf804 b 0x2bf6c8 <jinit_huff_decoder+0x52c> */
/* @0x2bf808 .word 0xffffff84 */
/* @0x2bf80c .word 0xfffffb38 */
/* @0x2bf810 .word 0xfffffb9c */

/* ── FUNC 0x2bf814 · jinit_d_main_controller · size=456 · insn=114 */
/* @0x2bf814 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2bf818 mov r2, #80 */
/* @0x2bf81c ldr r3, [r0, #0x4] */
/* @0x2bf820 mov r5, r1 */
/* @0x2bf824 mov r1, #1 */
/* @0x2bf828 mov r4, r0 */
/* @0x2bf82c ldr r3, [r3] */
/* @0x2bf830 blx r3 */
/* @0x2bf834 ldr r3, [pc, #0x19c] */
/* @0x2bf838 cmp r5, #0 */
/* @0x2bf83c add r3, pc, r3 */
/* @0x2bf840 str r0, [r4, #0x184] */
/* @0x2bf844 mov r7, r0 */
/* @0x2bf848 str r3, [r0] */
/* @0x2bf84c bne 0x2bf99c <jinit_d_main_controller+0x188> */
/* @0x2bf850 ldr r3, [r4, #0x1a0] */
/* @0x2bf854 ldrb r3, [r3, #0x8] */
/* @0x2bf858 cmp r3, #0 */
/* @0x2bf85c beq 0x2bf984 <jinit_d_main_controller+0x170> */
/* @0x2bf860 ldr r10, [r4, #0x118] */
/* @0x2bf864 cmp r10, #1 */
/* @0x2bf868 ble 0x2bf9b8 <jinit_d_main_controller+0x1a4> */
/* @0x2bf86c ldr r3, [r4, #0x4] */
/* @0x2bf870 mov r0, r4 */
/* @0x2bf874 ldr r2, [r4, #0x24] */
/* @0x2bf878 mov r1, #1 */
/* @0x2bf87c ldr r11, [r4, #0x184] */
/* @0x2bf880 ldr r3, [r3] */
/* @0x2bf884 lsl r2, r2, #3 */
/* @0x2bf888 blx r3 */
/* @0x2bf88c ldr r3, [r4, #0x24] */
/* @0x2bf890 ldr r6, [r4, #0xc4] */
/* @0x2bf894 cmp r3, #0 */
/* @0x2bf898 mov r5, r6 */
/* @0x2bf89c str r0, [r11, #0x38] */
/* @0x2bf8a0 add r0, r0, r3, lsl #2 */
/* @0x2bf8a4 str r0, [r11, #0x3c] */
/* @0x2bf8a8 ble 0x2bf918 <jinit_d_main_controller+0x104> */
/* @0x2bf8ac add r10, r10, #4 */
/* @0x2bf8b0 mov r5, #0 */
/* @0x2bf8b4 ldr r3, [r6, #0xc] */
/* @0x2bf8b8 add r6, r6, #84 */
/* @0x2bf8bc ldr r0, [r6, #-0x30] */
/* @0x2bf8c0 ldr r1, [r4, #0x118] */
/* @0x2bf8c4 mul r0, r0, r3 */
/* @0x2bf8c8 bl 0x318d10 <__divsi3> */
/* @0x2bf8cc ldr r3, [r4, #0x4] */
/* @0x2bf8d0 mov r1, #1 */
/* @0x2bf8d4 ldr r3, [r3] */
/* @0x2bf8d8 mul r8, r10, r0 */
/* @0x2bf8dc mov r9, r0 */
/* @0x2bf8e0 mov r0, r4 */
/* @0x2bf8e4 lsl r2, r8, #3 */
/* @0x2bf8e8 blx r3 */
/* @0x2bf8ec ldr r2, [r11, #0x38] */
/* @0x2bf8f0 ldr r3, [r4, #0x24] */
/* @0x2bf8f4 add r0, r0, r9, lsl #2 */
/* @0x2bf8f8 str r0, [r2, r5, lsl #2] */
/* @0x2bf8fc ldr r2, [r11, #0x3c] */
/* @0x2bf900 add r9, r0, r8, lsl #2 */
/* @0x2bf904 str r9, [r2, r5, lsl #2] */
/* @0x2bf908 add r5, r5, #1 */
/* @0x2bf90c cmp r5, r3 */
/* @0x2bf910 blt 0x2bf8b4 <jinit_d_main_controller+0xa0> */
/* @0x2bf914 ldr r5, [r4, #0xc4] */
/* @0x2bf918 ldr r8, [r4, #0x118] */
/* @0x2bf91c cmp r3, #0 */
/* @0x2bf920 add r8, r8, #2 */
/* @0x2bf924 pople {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bf928 mov r6, #0 */
/* @0x2bf92c ldr r3, [r5, #0x24] */
/* @0x2bf930 add r6, r6, #1 */
/* @0x2bf934 ldr r0, [r5, #0xc] */
/* @0x2bf938 add r7, r7, #4 */
/* @0x2bf93c ldr r9, [r5, #0x1c] */
/* @0x2bf940 add r5, r5, #84 */
/* @0x2bf944 ldr r1, [r4, #0x118] */
/* @0x2bf948 mul r0, r0, r3 */
/* @0x2bf94c ldr r10, [r4, #0x4] */
/* @0x2bf950 mul r9, r9, r3 */
/* @0x2bf954 bl 0x318d10 <__divsi3> */
/* @0x2bf958 mov r1, #1 */
/* @0x2bf95c ldr r12, [r10, #0x8] */
/* @0x2bf960 mov r2, r9 */
/* @0x2bf964 mul r3, r8, r0 */
/* @0x2bf968 mov r0, r4 */
/* @0x2bf96c blx r12 */
/* @0x2bf970 str r0, [r7, #0x4] */
/* @0x2bf974 ldr r3, [r4, #0x24] */
/* @0x2bf978 cmp r3, r6 */
/* @0x2bf97c bgt 0x2bf92c <jinit_d_main_controller+0x118> */
/* @0x2bf980 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bf984 ldr r3, [r4, #0x24] */
/* @0x2bf988 ldr r8, [r4, #0x118] */
/* @0x2bf98c cmp r3, #0 */
/* @0x2bf990 ldr r5, [r4, #0xc4] */
/* @0x2bf994 bgt 0x2bf928 <jinit_d_main_controller+0x114> */
/* @0x2bf998 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bf99c ldr r3, [r4] */
/* @0x2bf9a0 mov r2, #4 */
/* @0x2bf9a4 mov r0, r4 */
/* @0x2bf9a8 str r2, [r3, #0x14] */
/* @0x2bf9ac ldr r3, [r3] */
/* @0x2bf9b0 blx r3 */
/* @0x2bf9b4 b 0x2bf850 <jinit_d_main_controller+0x3c> */
/* @0x2bf9b8 ldr r3, [r4] */
/* @0x2bf9bc mov r2, #47 */
/* @0x2bf9c0 mov r0, r4 */
/* @0x2bf9c4 str r2, [r3, #0x14] */
/* @0x2bf9c8 ldr r3, [r3] */
/* @0x2bf9cc blx r3 */
/* @0x2bf9d0 ldr r10, [r4, #0x118] */
/* @0x2bf9d4 b 0x2bf86c <jinit_d_main_controller+0x58> */
/* @0x2bf9d8 .word 0xfffffe18 */

/* ── FUNC 0x2bf9dc · jpeg_idct_float · size=1144 · insn=286 */
/* @0x2bf9dc push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2bf9e0 vpush {d8, d9} */
/* @0x2bf9e4 sub sp, sp, #272 */
/* @0x2bf9e8 vldr s4, [pc, #968] */
/* @0x2bf9ec ldr r12, [r0, #0x120] */
/* @0x2bf9f0 vldr s1, [pc, #964] */
/* @0x2bf9f4 ldr r0, [r1, #0x50] */
/* @0x2bf9f8 add r1, sp, #16 */
/* @0x2bf9fc str r1, [sp, #0x4] */
/* @0x2bfa00 mov r1, r2 */
/* @0x2bfa04 add r4, r1, #16 */
/* @0x2bfa08 add r12, r12, #128 */
/* @0x2bfa0c add r5, r0, #4 */
/* @0x2bfa10 str r3, [sp, #0x8] */
/* @0x2bfa14 add r2, r2, #2 */
/* @0x2bfa18 add r0, r0, #64 */
/* @0x2bfa1c add r3, sp, #16 */
/* @0x2bfa20 vldr s2, [pc, #920] */
/* @0x2bfa24 vldr s3, [pc, #920] */
/* @0x2bfa28 str r12, [sp, #0xc] */
/* @0x2bfa2c mov r11, r4 */
/* @0x2bfa30 b 0x2bfbbc <jpeg_idct_float+0x1e0> */
/* @0x2bfa34 cmp r7, #0 */
/* @0x2bfa38 bne 0x2bfbcc <jpeg_idct_float+0x1f0> */
/* @0x2bfa3c ldrh r10, [r1, #48] */
/* @0x2bfa40 ldrh r4, [r1, #64] */
/* @0x2bfa44 cmp r10, #0 */
/* @0x2bfa48 beq 0x2bfd98 <jpeg_idct_float+0x3bc> */
/* @0x2bfa4c ldrh r6, [r1, #96] */
/* @0x2bfa50 mov r7, r12 */
/* @0x2bfa54 ldrh r9, [r1, #80] */
/* @0x2bfa58 ldrh r8, [r1, #112] */
/* @0x2bfa5c sxth r12, r12 */
/* @0x2bfa60 sxth r10, r10 */
/* @0x2bfa64 sxth r9, r9 */
/* @0x2bfa68 sxth r8, r8 */
/* @0x2bfa6c vmov s5, r12 */
/* @0x2bfa70 vldr s19, [r0, #-32] */
/* @0x2bfa74 vmov s15, r10 */
/* @0x2bfa78 vldr s9, [r0, #160] */
/* @0x2bfa7c vmov s12, r9 */
/* @0x2bfa80 vldr s13, [r0, #32] */
/* @0x2bfa84 vmov s6, r8 */
/* @0x2bfa88 vldr s14, [r0, #96] */
/* @0x2bfa8c vcvt.f32.s32 s5, s5 */
/* @0x2bfa90 sxth r7, r7 */
/* @0x2bfa94 sxth r6, r6 */
/* @0x2bfa98 vldr s18, [r0] */
/* @0x2bfa9c vmov s7, r7 */
/* @0x2bfaa0 vldr s17, [r0, #128] */
/* @0x2bfaa4 vmov s10, r6 */
/* @0x2bfaa8 ldrsh r12, [r2, #-2] */
/* @0x2bfaac sxth r4, r4 */
/* @0x2bfab0 vldr s16, [r0, #64] */
/* @0x2bfab4 vldr s0, [r5, #-4] */
/* @0x2bfab8 add r3, r3, #4 */
/* @0x2bfabc vmov s11, r12 */
/* @0x2bfac0 vcvt.f32.s32 s6, s6 */
/* @0x2bfac4 vmov s8, r4 */
/* @0x2bfac8 vcvt.f32.s32 s15, s15 */
/* @0x2bfacc vcvt.f32.s32 s12, s12 */
/* @0x2bfad0 vmul.f32 s15, s15, s13 */
/* @0x2bfad4 vmul.f32 s5, s5, s19 */
/* @0x2bfad8 vmul.f32 s6, s6, s9 */
/* @0x2bfadc vmul.f32 s12, s12, s14 */
/* @0x2bfae0 vsub.f32 s13, s5, s6 */
/* @0x2bfae4 vsub.f32 s14, s12, s15 */
/* @0x2bfae8 vadd.f32 s9, s14, s13 */
/* @0x2bfaec vmul.f32 s9, s9, s1 */
/* @0x2bfaf0 vmov.f32 s19, s9 */
/* @0x2bfaf4 vmla.f32 s19, s14, s2 */
/* @0x2bfaf8 vadd.f32 s12, s12, s15 */
/* @0x2bfafc vadd.f32 s6, s5, s6 */
/* @0x2bfb00 vadd.f32 s15, s6, s12 */
/* @0x2bfb04 vcvt.f32.s32 s7, s7 */
/* @0x2bfb08 vcvt.f32.s32 s10, s10 */
/* @0x2bfb0c vmul.f32 s7, s7, s18 */
/* @0x2bfb10 vmul.f32 s10, s10, s17 */
/* @0x2bfb14 vsub.f32 s14, s19, s15 */
/* @0x2bfb18 vsub.f32 s6, s6, s12 */
/* @0x2bfb1c vcvt.f32.s32 s8, s8 */
/* @0x2bfb20 vcvt.f32.s32 s11, s11 */
/* @0x2bfb24 vadd.f32 s12, s7, s10 */
/* @0x2bfb28 vnmls.f32 s9, s13, s3 */
/* @0x2bfb2c vmov.f32 s13, s14 */
/* @0x2bfb30 vmul.f32 s8, s8, s16 */
/* @0x2bfb34 vmul.f32 s11, s11, s0 */
/* @0x2bfb38 vsub.f32 s10, s7, s10 */
/* @0x2bfb3c vnmls.f32 s13, s6, s4 */
/* @0x2bfb40 vmov.f32 s7, s12 */
/* @0x2bfb44 vnmls.f32 s7, s10, s4 */
/* @0x2bfb48 vadd.f32 s10, s11, s8 */
/* @0x2bfb4c vadd.f32 s9, s9, s13 */
/* @0x2bfb50 vsub.f32 s11, s11, s8 */
/* @0x2bfb54 vsub.f32 s8, s10, s12 */
/* @0x2bfb58 vadd.f32 s12, s10, s12 */
/* @0x2bfb5c vsub.f32 s10, s11, s7 */
/* @0x2bfb60 vadd.f32 s11, s11, s7 */
/* @0x2bfb64 vadd.f32 s7, s8, s9 */
/* @0x2bfb68 vsub.f32 s9, s8, s9 */
/* @0x2bfb6c vstr s7, [r3, #124] */
/* @0x2bfb70 vadd.f32 s7, s10, s13 */
/* @0x2bfb74 vstr s9, [r3, #92] */
/* @0x2bfb78 vsub.f32 s13, s10, s13 */
/* @0x2bfb7c vstr s7, [r3, #60] */
/* @0x2bfb80 vadd.f32 s9, s11, s14 */
/* @0x2bfb84 vstr s13, [r3, #156] */
/* @0x2bfb88 vsub.f32 s14, s11, s14 */
/* @0x2bfb8c vstr s9, [r3, #28] */
/* @0x2bfb90 vadd.f32 s13, s12, s15 */
/* @0x2bfb94 vstr s14, [r3, #188] */
/* @0x2bfb98 vsub.f32 s12, s12, s15 */
/* @0x2bfb9c vstr s13, [r3, #-4] */
/* @0x2bfba0 vstr s12, [r3, #220] */
/* @0x2bfba4 add r1, r1, #2 */
/* @0x2bfba8 add r2, r2, #2 */
/* @0x2bfbac cmp r1, r11 */
/* @0x2bfbb0 add r5, r5, #4 */
/* @0x2bfbb4 add r0, r0, #4 */
/* @0x2bfbb8 beq 0x2bfbe4 <jpeg_idct_float+0x208> */
/* @0x2bfbbc ldrh r12, [r1, #16] */
/* @0x2bfbc0 ldrh r7, [r1, #32] */
/* @0x2bfbc4 cmp r12, #0 */
/* @0x2bfbc8 beq 0x2bfa34 <jpeg_idct_float+0x58> */
/* @0x2bfbcc ldrh r4, [r1, #64] */
/* @0x2bfbd0 ldrh r6, [r1, #96] */
/* @0x2bfbd4 ldrh r10, [r1, #48] */
/* @0x2bfbd8 ldrh r9, [r1, #80] */
/* @0x2bfbdc ldrh r8, [r1, #112] */
/* @0x2bfbe0 b 0x2bfa5c <jpeg_idct_float+0x80> */
/* @0x2bfbe4 ldr r1, [sp, #0x8] */
/* @0x2bfbe8 add r3, sp, #16 */
/* @0x2bfbec ldr r12, [sp, #0xc] */
/* @0x2bfbf0 vldr s4, [pc, #448] */
/* @0x2bfbf4 ldr r4, [sp, #0x140] */
/* @0x2bfbf8 sub r0, r1, #4 */
/* @0x2bfbfc vldr s1, [pc, #440] */
/* @0x2bfc00 vldr s2, [pc, #440] */
/* @0x2bfc04 vldr s3, [pc, #440] */
/* @0x2bfc08 vldr s5, [r3, #20] */
/* @0x2bfc0c vldr s13, [r3, #28] */
/* @0x2bfc10 vldr s8, [r3, #12] */
/* @0x2bfc14 vldr s7, [r3, #4] */
/* @0x2bfc18 vsub.f32 s14, s5, s8 */
/* @0x2bfc1c vldr s12, [r3, #24] */
/* @0x2bfc20 vldr s6, [r3, #8] */
/* @0x2bfc24 vldr s15, [r3, #16] */
/* @0x2bfc28 vldr s10, [r3] */
/* @0x2bfc2c add r5, sp, #272 */
/* @0x2bfc30 add r3, r3, #32 */
/* @0x2bfc34 ldr r1, [r0, #0x4]! */
/* @0x2bfc38 cmp r3, r5 */
/* @0x2bfc3c add r2, r1, r4 */
/* @0x2bfc40 vsub.f32 s9, s7, s13 */
/* @0x2bfc44 vadd.f32 s11, s14, s9 */
/* @0x2bfc48 vmul.f32 s11, s11, s1 */
/* @0x2bfc4c vmov.f32 s0, s11 */
/* @0x2bfc50 vmla.f32 s0, s14, s2 */
/* @0x2bfc54 vadd.f32 s8, s5, s8 */
/* @0x2bfc58 vadd.f32 s7, s7, s13 */
/* @0x2bfc5c vadd.f32 s13, s6, s12 */
/* @0x2bfc60 vsub.f32 s6, s6, s12 */
/* @0x2bfc64 vadd.f32 s12, s7, s8 */
/* @0x2bfc68 vmov.f32 s5, s13 */
/* @0x2bfc6c vsub.f32 s14, s0, s12 */
/* @0x2bfc70 vnmls.f32 s5, s6, s4 */
/* @0x2bfc74 vsub.f32 s7, s7, s8 */
/* @0x2bfc78 vadd.f32 s8, s10, s15 */
/* @0x2bfc7c vsub.f32 s10, s10, s15 */
/* @0x2bfc80 vmov.f32 s15, s14 */
/* @0x2bfc84 vnmls.f32 s15, s7, s4 */
/* @0x2bfc88 vadd.f32 s7, s8, s13 */
/* @0x2bfc8c vmov.f32 s6, s5 */
/* @0x2bfc90 vnmls.f32 s11, s9, s3 */
/* @0x2bfc94 vadd.f32 s9, s10, s5 */
/* @0x2bfc98 vadd.f32 s5, s7, s12 */
/* @0x2bfc9c vcvt.s32.f32 s5, s5 */
/* @0x2bfca0 vmov r5, s5 */
/* @0x2bfca4 vsub.f32 s12, s7, s12 */
/* @0x2bfca8 vcvt.s32.f32 s12, s12 */
/* @0x2bfcac vsub.f32 s10, s10, s6 */
/* @0x2bfcb0 add r5, r5, #4 */
/* @0x2bfcb4 ubfx r5, r5, #0x3, #0xa */
/* @0x2bfcb8 ldrb r5, [r12, r5] */
/* @0x2bfcbc strb r5, [r1, r4] */
/* @0x2bfcc0 vmov r1, s12 */
/* @0x2bfcc4 vadd.f32 s6, s9, s14 */
/* @0x2bfcc8 vcvt.s32.f32 s6, s6 */
/* @0x2bfccc vsub.f32 s14, s9, s14 */
/* @0x2bfcd0 add r1, r1, #4 */
/* @0x2bfcd4 ubfx r1, r1, #0x3, #0xa */
/* @0x2bfcd8 ldrb r1, [r12, r1] */
/* @0x2bfcdc strb r1, [r2, #0x7] */
/* @0x2bfce0 vmov r1, s6 */
/* @0x2bfce4 vcvt.s32.f32 s14, s14 */
/* @0x2bfce8 vsub.f32 s13, s8, s13 */
/* @0x2bfcec vadd.f32 s8, s10, s15 */
/* @0x2bfcf0 add r1, r1, #4 */
/* @0x2bfcf4 ubfx r1, r1, #0x3, #0xa */
/* @0x2bfcf8 ldrb r1, [r12, r1] */
/* @0x2bfcfc strb r1, [r2, #0x1] */
/* @0x2bfd00 vmov r1, s14 */
/* @0x2bfd04 vadd.f32 s11, s11, s15 */
/* @0x2bfd08 vsub.f32 s15, s10, s15 */
/* @0x2bfd0c add r1, r1, #4 */
/* @0x2bfd10 vcvt.s32.f32 s8, s8 */
/* @0x2bfd14 ubfx r1, r1, #0x3, #0xa */
/* @0x2bfd18 ldrb r1, [r12, r1] */
/* @0x2bfd1c strb r1, [r2, #0x6] */
/* @0x2bfd20 vcvt.s32.f32 s15, s15 */
/* @0x2bfd24 vmov r5, s8 */
/* @0x2bfd28 vmov r1, s15 */
/* @0x2bfd2c vadd.f32 s12, s13, s11 */
/* @0x2bfd30 vsub.f32 s13, s13, s11 */
/* @0x2bfd34 add r5, r5, #4 */
/* @0x2bfd38 ubfx r5, r5, #0x3, #0xa */
/* @0x2bfd3c ldrb r5, [r12, r5] */
/* @0x2bfd40 add r1, r1, #4 */
/* @0x2bfd44 strb r5, [r2, #0x2] */
/* @0x2bfd48 vcvt.s32.f32 s12, s12 */
/* @0x2bfd4c ubfx r1, r1, #0x3, #0xa */
/* @0x2bfd50 ldrb r1, [r12, r1] */
/* @0x2bfd54 strb r1, [r2, #0x5] */
/* @0x2bfd58 vcvt.s32.f32 s13, s13 */
/* @0x2bfd5c vmov r5, s12 */
/* @0x2bfd60 vmov r1, s13 */
/* @0x2bfd64 add r5, r5, #4 */
/* @0x2bfd68 ubfx r5, r5, #0x3, #0xa */
/* @0x2bfd6c ldrb r5, [r12, r5] */
/* @0x2bfd70 add r1, r1, #4 */
/* @0x2bfd74 strb r5, [r2, #0x4] */
/* @0x2bfd78 ubfx r1, r1, #0x3, #0xa */
/* @0x2bfd7c ldrb r1, [r12, r1] */
/* @0x2bfd80 strb r1, [r2, #0x3] */
/* @0x2bfd84 bne 0x2bfc08 <jpeg_idct_float+0x22c> */
/* @0x2bfd88 add sp, sp, #272 */
/* @0x2bfd8c vpop {d8, d9} */
/* @0x2bfd90 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2bfd94 bx lr */
/* @0x2bfd98 cmp r4, #0 */
/* @0x2bfd9c beq 0x2bfdc8 <jpeg_idct_float+0x3ec> */
/* @0x2bfda0 ldrh r6, [r1, #96] */
/* @0x2bfda4 mov r10, r12 */
/* @0x2bfda8 ldrh r9, [r1, #80] */
/* @0x2bfdac mov r7, r12 */
/* @0x2bfdb0 ldrh r8, [r1, #112] */
/* @0x2bfdb4 b 0x2bfa5c <jpeg_idct_float+0x80> */
/* @0x2bfdb8 svclo #0xb504f3 */
/* @0x2bfdbc svclo #0xec835e */
/* @0x2bfdc0 eorgt r3, r7, r5, ror sp */
/* @0x2bfdc4 svclo #0x8a8bd4 */
/* @0x2bfdc8 ldrh r9, [r1, #80] */
/* @0x2bfdcc ldrh r6, [r1, #96] */
/* @0x2bfdd0 cmp r9, #0 */
/* @0x2bfdd4 ldrh r8, [r1, #112] */
/* @0x2bfdd8 bne 0x2bfe2c <jpeg_idct_float+0x450> */
/* @0x2bfddc cmp r6, #0 */
/* @0x2bfde0 bne 0x2bfe28 <jpeg_idct_float+0x44c> */
/* @0x2bfde4 cmp r8, #0 */
/* @0x2bfde8 bne 0x2bfe3c <jpeg_idct_float+0x460> */
/* @0x2bfdec ldrsh r12, [r2, #-2] */
/* @0x2bfdf0 vldr s14, [r5, #-4] */
/* @0x2bfdf4 add r3, r3, #4 */
/* @0x2bfdf8 vmov s15, r12 */
/* @0x2bfdfc vcvt.f32.s32 s15, s15 */
/* @0x2bfe00 vmul.f32 s15, s15, s14 */
/* @0x2bfe04 vstr s15, [r3, #-4] */
/* @0x2bfe08 vstr s15, [r3, #28] */
/* @0x2bfe0c vstr s15, [r3, #60] */
/* @0x2bfe10 vstr s15, [r3, #92] */
/* @0x2bfe14 vstr s15, [r3, #124] */
/* @0x2bfe18 vstr s15, [r3, #156] */
/* @0x2bfe1c vstr s15, [r3, #188] */
/* @0x2bfe20 vstr s15, [r3, #220] */
/* @0x2bfe24 b 0x2bfba4 <jpeg_idct_float+0x1c8> */
/* @0x2bfe28 mov r9, r12 */
/* @0x2bfe2c mov r10, r12 */
/* @0x2bfe30 mov r4, r12 */
/* @0x2bfe34 mov r7, r12 */
/* @0x2bfe38 b 0x2bfa5c <jpeg_idct_float+0x80> */
/* @0x2bfe3c mov r9, r12 */
/* @0x2bfe40 mov r10, r12 */
/* @0x2bfe44 mov r6, r12 */
/* @0x2bfe48 mov r4, r12 */
/* @0x2bfe4c mov r7, r12 */
/* @0x2bfe50 b 0x2bfa5c <jpeg_idct_float+0x80> */

/* ── FUNC 0x2bfe54 · jpeg_idct_ifast · size=1380 · insn=345 */
/* @0x2bfe54 ldr r12, [r0, #0x120] */
/* @0x2bfe58 ldr r0, [r1, #0x50] */
/* @0x2bfe5c push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2bfe60 sub sp, sp, #296 */
/* @0x2bfe64 add r1, sp, #40 */
/* @0x2bfe68 add r12, r12, #128 */
/* @0x2bfe6c str r1, [sp, #0x20] */
/* @0x2bfe70 add r4, r0, #4 */
/* @0x2bfe74 mov r1, r2 */
/* @0x2bfe78 str r3, [sp, #0x1c] */
/* @0x2bfe7c add r2, r2, #2 */
/* @0x2bfe80 str r12, [sp, #0x24] */
/* @0x2bfe84 str r2, [sp, #0x10] */
/* @0x2bfe88 add r3, sp, #40 */
/* @0x2bfe8c add r2, r1, #16 */
/* @0x2bfe90 str r4, [sp, #0xc] */
/* @0x2bfe94 str r2, [sp, #0x18] */
/* @0x2bfe98 mov r2, r0 */
/* @0x2bfe9c b 0x2c0034 <jpeg_idct_ifast+0x1e0> */
/* @0x2bfea0 cmp r8, #0 */
/* @0x2bfea4 bne 0x2c0044 <jpeg_idct_ifast+0x1f0> */
/* @0x2bfea8 ldrh r10, [r1, #48] */
/* @0x2bfeac ldrh r4, [r1, #64] */
/* @0x2bfeb0 cmp r10, #0 */
/* @0x2bfeb4 beq 0x2c0254 <jpeg_idct_ifast+0x400> */
/* @0x2bfeb8 ldrh r7, [r1, #96] */
/* @0x2bfebc mov r8, r0 */
/* @0x2bfec0 ldrh r5, [r1, #80] */
/* @0x2bfec4 ldrh r9, [r1, #112] */
/* @0x2bfec8 ldr r6, [r2, #0x60] */
/* @0x2bfecc sxth r10, r10 */
/* @0x2bfed0 ldr r11, [r2, #0xa0] */
/* @0x2bfed4 sxth r0, r0 */
/* @0x2bfed8 ldr r12, [r2, #0x20] */
/* @0x2bfedc sxth r5, r5 */
/* @0x2bfee0 mul r10, r6, r10 */
/* @0x2bfee4 ldr r6, [r2, #0xe0] */
/* @0x2bfee8 sxth r9, r9 */
/* @0x2bfeec sxth r8, r8 */
/* @0x2bfef0 mul r0, r12, r0 */
/* @0x2bfef4 ldr r12, [r2, #0x40] */
/* @0x2bfef8 mul r9, r6, r9 */
/* @0x2bfefc ldr r6, [r2, #0xc0] */
/* @0x2bff00 mul r5, r11, r5 */
/* @0x2bff04 sxth r7, r7 */
/* @0x2bff08 mul r8, r12, r8 */
/* @0x2bff0c rsb r11, r9, r0 */
/* @0x2bff10 rsb r12, r10, r5 */
/* @0x2bff14 add r0, r0, r9 */
/* @0x2bff18 mul r7, r6, r7 */
/* @0x2bff1c add r6, r12, r11 */
/* @0x2bff20 movw r9, #0x1d9 */
/* @0x2bff24 add r5, r5, r10 */
/* @0x2bff28 mul r6, r9, r6 */
/* @0x2bff2c mvn r9, #668 */
/* @0x2bff30 mul r12, r9, r12 */
/* @0x2bff34 rsb r10, r5, r0 */
/* @0x2bff38 add r0, r0, r5 */
/* @0x2bff3c rsb r9, r7, r8 */
/* @0x2bff40 sxth r4, r4 */
/* @0x2bff44 add r7, r8, r7 */
/* @0x2bff48 asr r6, r6, #8 */
/* @0x2bff4c add r3, r3, #4 */
/* @0x2bff50 str r12, [sp, #0x14] */
/* @0x2bff54 movw r12, #0x115 */
/* @0x2bff58 mul r11, r12, r11 */
/* @0x2bff5c add r12, r12, #85 */
/* @0x2bff60 mul r10, r12, r10 */
/* @0x2bff64 mul r9, r12, r9 */
/* @0x2bff68 str r11, [sp, #0x4] */
/* @0x2bff6c ldr r11, [sp, #0x10] */
/* @0x2bff70 ldr r12, [r2, #0x80] */
/* @0x2bff74 ldr r8, [sp, #0x4] */
/* @0x2bff78 ldrsh r5, [r11, #-2] */
/* @0x2bff7c ldr r11, [sp, #0xc] */
/* @0x2bff80 rsb r9, r7, r9, asr #8 */
/* @0x2bff84 mul r4, r12, r4 */
/* @0x2bff88 ldr r11, [r11, #-0x4] */
/* @0x2bff8c str r11, [sp, #0x8] */
/* @0x2bff90 ldr r11, [sp, #0x14] */
/* @0x2bff94 add r12, r6, r11, asr #8 */
/* @0x2bff98 ldr r11, [sp, #0x8] */
/* @0x2bff9c rsb r12, r0, r12 */
/* @0x2bffa0 rsb r6, r6, r8, asr #8 */
/* @0x2bffa4 rsb r10, r12, r10, asr #8 */
/* @0x2bffa8 mul r5, r11, r5 */
/* @0x2bffac add r6, r6, r10 */
/* @0x2bffb0 add r8, r5, r4 */
/* @0x2bffb4 rsb r4, r4, r5 */
/* @0x2bffb8 rsb r11, r7, r8 */
/* @0x2bffbc add r7, r8, r7 */
/* @0x2bffc0 rsb r8, r9, r4 */
/* @0x2bffc4 add r9, r4, r9 */
/* @0x2bffc8 add r4, r11, r6 */
/* @0x2bffcc rsb r6, r6, r11 */
/* @0x2bffd0 str r4, [r3, #0x7c] */
/* @0x2bffd4 add r4, r8, r10 */
/* @0x2bffd8 str r6, [r3, #0x5c] */
/* @0x2bffdc rsb r10, r10, r8 */
/* @0x2bffe0 str r4, [r3, #0x3c] */
/* @0x2bffe4 add r4, r9, r12 */
/* @0x2bffe8 str r10, [r3, #0x9c] */
/* @0x2bffec rsb r9, r12, r9 */
/* @0x2bfff0 str r4, [r3, #0x1c] */
/* @0x2bfff4 add r12, r7, r0 */
/* @0x2bfff8 str r9, [r3, #0xbc] */
/* @0x2bfffc rsb r7, r0, r7 */
/* @0x2c0000 str r12, [r3, #-0x4] */
/* @0x2c0004 str r7, [r3, #0xdc] */
/* @0x2c0008 ldr r10, [sp, #0x18] */
/* @0x2c000c add r1, r1, #2 */
/* @0x2c0010 ldr r9, [sp, #0x10] */
/* @0x2c0014 add r2, r2, #4 */
/* @0x2c0018 ldr r11, [sp, #0xc] */
/* @0x2c001c cmp r1, r10 */
/* @0x2c0020 add r9, r9, #2 */
/* @0x2c0024 str r9, [sp, #0x10] */
/* @0x2c0028 add r11, r11, #4 */
/* @0x2c002c str r11, [sp, #0xc] */
/* @0x2c0030 beq 0x2c005c <jpeg_idct_ifast+0x208> */
/* @0x2c0034 ldrh r0, [r1, #16] */
/* @0x2c0038 ldrh r8, [r1, #32] */
/* @0x2c003c cmp r0, #0 */
/* @0x2c0040 beq 0x2bfea0 <jpeg_idct_ifast+0x4c> */
/* @0x2c0044 ldrh r4, [r1, #64] */
/* @0x2c0048 ldrh r7, [r1, #96] */
/* @0x2c004c ldrh r10, [r1, #48] */
/* @0x2c0050 ldrh r5, [r1, #80] */
/* @0x2c0054 ldrh r9, [r1, #112] */
/* @0x2c0058 b 0x2bfec8 <jpeg_idct_ifast+0x74> */
/* @0x2c005c add r6, sp, #40 */
/* @0x2c0060 mov r12, #0 */
/* @0x2c0064 ldr r2, [sp, #0x24] */
/* @0x2c0068 str r12, [sp, #0x10] */
/* @0x2c006c mov r8, r6 */
/* @0x2c0070 b 0x2c01f4 <jpeg_idct_ifast+0x3a0> */
/* @0x2c0074 ldr r1, [r8, #0x8] */
/* @0x2c0078 cmp r1, #0 */
/* @0x2c007c beq 0x2c0234 <jpeg_idct_ifast+0x3e0> */
/* @0x2c0080 ldr r12, [r8, #0x10] */
/* @0x2c0084 ldr r10, [r8, #0x18] */
/* @0x2c0088 ldr r11, [r8, #0x14] */
/* @0x2c008c ldr r5, [r8, #0xc] */
/* @0x2c0090 ldr r9, [r8, #0x1c] */
/* @0x2c0094 rsb r6, r9, r4 */
/* @0x2c0098 rsb r0, r5, r11 */
/* @0x2c009c add r11, r11, r5 */
/* @0x2c00a0 add r5, r0, r6 */
/* @0x2c00a4 str r6, [sp, #0x14] */
/* @0x2c00a8 rsb r6, r10, r1 */
/* @0x2c00ac str r6, [sp, #0x20] */
/* @0x2c00b0 movw r6, #0x1d9 */
/* @0x2c00b4 mul r5, r6, r5 */
/* @0x2c00b8 ldr r7, [r8], #32 */
/* @0x2c00bc add r9, r4, r9 */
/* @0x2c00c0 add r1, r1, r10 */
/* @0x2c00c4 add r4, r7, r12 */
/* @0x2c00c8 rsb r7, r12, r7 */
/* @0x2c00cc add r12, r9, r11 */
/* @0x2c00d0 rsb r9, r11, r9 */
/* @0x2c00d4 movw r10, #0x16a */
/* @0x2c00d8 str r5, [sp, #0x18] */
/* @0x2c00dc ldr r5, [sp, #0x20] */
/* @0x2c00e0 str r9, [sp, #0x20] */
/* @0x2c00e4 ldr r9, [sp, #0x18] */
/* @0x2c00e8 mul r6, r10, r5 */
/* @0x2c00ec mvn r10, #668 */
/* @0x2c00f0 asr r5, r9, #8 */
/* @0x2c00f4 ldr r9, [sp, #0x20] */
/* @0x2c00f8 mul r0, r10, r0 */
/* @0x2c00fc add r10, r4, r1 */
/* @0x2c0100 add r11, r10, r12 */
/* @0x2c0104 rsb r10, r12, r10 */
/* @0x2c0108 ubfx r10, r10, #0x5, #0xa */
/* @0x2c010c str r10, [sp, #0x18] */
/* @0x2c0110 movw r10, #0x16a */
/* @0x2c0114 ubfx r11, r11, #0x5, #0xa */
/* @0x2c0118 mul r10, r10, r9 */
/* @0x2c011c add r0, r5, r0, asr #8 */
/* @0x2c0120 ldrb r11, [r2, r11] */
/* @0x2c0124 rsb r0, r12, r0 */
/* @0x2c0128 ldr r9, [sp, #0x18] */
/* @0x2c012c rsb r6, r1, r6, asr #8 */
/* @0x2c0130 ldr r12, [sp, #0xc] */
/* @0x2c0134 rsb r1, r1, r4 */
/* @0x2c0138 str r10, [sp, #0x20] */
/* @0x2c013c ldr r10, [sp, #0x148] */
/* @0x2c0140 strb r11, [r12, r10] */
/* @0x2c0144 movw r11, #0x115 */
/* @0x2c0148 ldrb r9, [r2, r9] */
/* @0x2c014c add r12, r7, r6 */
/* @0x2c0150 add r10, r12, r0 */
/* @0x2c0154 rsb r12, r0, r12 */
/* @0x2c0158 ubfx r10, r10, #0x5, #0xa */
/* @0x2c015c ubfx r12, r12, #0x5, #0xa */
/* @0x2c0160 str r9, [sp, #0x18] */
/* @0x2c0164 rsb r6, r6, r7 */
/* @0x2c0168 ldr r9, [sp, #0x14] */
/* @0x2c016c mul r11, r11, r9 */
/* @0x2c0170 ldr r9, [sp, #0x20] */
/* @0x2c0174 rsb r0, r0, r9, asr #8 */
/* @0x2c0178 add r9, r6, r0 */
/* @0x2c017c rsb r6, r0, r6 */
/* @0x2c0180 str r11, [sp, #0xc] */
/* @0x2c0184 ubfx r9, r9, #0x5, #0xa */
/* @0x2c0188 ldr r11, [sp, #0x18] */
/* @0x2c018c ubfx r6, r6, #0x5, #0xa */
/* @0x2c0190 strb r11, [r3, #0x7] */
/* @0x2c0194 ldrb r10, [r2, r10] */
/* @0x2c0198 strb r10, [r3, #0x1] */
/* @0x2c019c ldrb r12, [r2, r12] */
/* @0x2c01a0 ldr r10, [sp, #0xc] */
/* @0x2c01a4 strb r12, [r3, #0x6] */
/* @0x2c01a8 ldrb r7, [r2, r9] */
/* @0x2c01ac rsb r5, r5, r10, asr #8 */
/* @0x2c01b0 add r0, r5, r0 */
/* @0x2c01b4 add r12, r1, r0 */
/* @0x2c01b8 rsb r0, r0, r1 */
/* @0x2c01bc strb r7, [r3, #0x2] */
/* @0x2c01c0 ubfx r12, r12, #0x5, #0xa */
/* @0x2c01c4 ldrb r1, [r2, r6] */
/* @0x2c01c8 ubfx r0, r0, #0x5, #0xa */
/* @0x2c01cc strb r1, [r3, #0x5] */
/* @0x2c01d0 ldrb r1, [r2, r12] */
/* @0x2c01d4 strb r1, [r3, #0x4] */
/* @0x2c01d8 ldrb r1, [r2, r0] */
/* @0x2c01dc strb r1, [r3, #0x3] */
/* @0x2c01e0 ldr r11, [sp, #0x10] */
/* @0x2c01e4 add r11, r11, #4 */
/* @0x2c01e8 str r11, [sp, #0x10] */
/* @0x2c01ec cmp r11, #32 */
/* @0x2c01f0 beq 0x2c0274 <jpeg_idct_ifast+0x420> */
/* @0x2c01f4 ldr r1, [sp, #0x1c] */
/* @0x2c01f8 ldr r0, [sp, #0x10] */
/* @0x2c01fc ldr r4, [r8, #0x4] */
/* @0x2c0200 ldr r5, [sp, #0x148] */
/* @0x2c0204 ldr r0, [r1, r0] */
/* @0x2c0208 cmp r4, #0 */
/* @0x2c020c add r3, r0, r5 */
/* @0x2c0210 str r0, [sp, #0xc] */
/* @0x2c0214 beq 0x2c0074 <jpeg_idct_ifast+0x220> */
/* @0x2c0218 ldr r12, [r8, #0x10] */
/* @0x2c021c ldr r1, [r8, #0x8] */
/* @0x2c0220 ldr r10, [r8, #0x18] */
/* @0x2c0224 ldr r11, [r8, #0x14] */
/* @0x2c0228 ldr r5, [r8, #0xc] */
/* @0x2c022c ldr r9, [r8, #0x1c] */
/* @0x2c0230 b 0x2c0094 <jpeg_idct_ifast+0x240> */
/* @0x2c0234 ldr r5, [r8, #0xc] */
/* @0x2c0238 ldr r12, [r8, #0x10] */
/* @0x2c023c cmp r5, #0 */
/* @0x2c0240 beq 0x2c0280 <jpeg_idct_ifast+0x42c> */
/* @0x2c0244 ldr r10, [r8, #0x18] */
/* @0x2c0248 ldr r11, [r8, #0x14] */
/* @0x2c024c ldr r9, [r8, #0x1c] */
/* @0x2c0250 b 0x2c0094 <jpeg_idct_ifast+0x240> */
/* @0x2c0254 cmp r4, #0 */
/* @0x2c0258 beq 0x2c029c <jpeg_idct_ifast+0x448> */
/* @0x2c025c ldrh r7, [r1, #96] */
/* @0x2c0260 mov r10, r0 */
/* @0x2c0264 ldrh r5, [r1, #80] */
/* @0x2c0268 mov r8, r0 */
/* @0x2c026c ldrh r9, [r1, #112] */
/* @0x2c0270 b 0x2bfec8 <jpeg_idct_ifast+0x74> */
/* @0x2c0274 add sp, sp, #296 */
/* @0x2c0278 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2c027c bx lr */
/* @0x2c0280 cmp r12, #0 */
/* @0x2c0284 beq 0x2c02fc <jpeg_idct_ifast+0x4a8> */
/* @0x2c0288 ldr r10, [r8, #0x18] */
/* @0x2c028c mov r1, r5 */
/* @0x2c0290 ldr r11, [r8, #0x14] */
/* @0x2c0294 ldr r9, [r8, #0x1c] */
/* @0x2c0298 b 0x2c0094 <jpeg_idct_ifast+0x240> */
/* @0x2c029c ldrh r5, [r1, #80] */
/* @0x2c02a0 ldrh r7, [r1, #96] */
/* @0x2c02a4 cmp r5, #0 */
/* @0x2c02a8 ldrh r9, [r1, #112] */
/* @0x2c02ac bne 0x2c035c <jpeg_idct_ifast+0x508> */
/* @0x2c02b0 cmp r7, #0 */
/* @0x2c02b4 bne 0x2c0358 <jpeg_idct_ifast+0x504> */
/* @0x2c02b8 cmp r9, #0 */
/* @0x2c02bc bne 0x2c03a0 <jpeg_idct_ifast+0x54c> */
/* @0x2c02c0 ldr r5, [sp, #0x10] */
/* @0x2c02c4 add r3, r3, #4 */
/* @0x2c02c8 ldr r6, [sp, #0xc] */
/* @0x2c02cc ldrsh r0, [r5, #-2] */
/* @0x2c02d0 ldr r12, [r6, #-0x4] */
/* @0x2c02d4 mul r0, r12, r0 */
/* @0x2c02d8 str r0, [r3, #-0x4] */
/* @0x2c02dc str r0, [r3, #0x1c] */
/* @0x2c02e0 str r0, [r3, #0x3c] */
/* @0x2c02e4 str r0, [r3, #0x5c] */
/* @0x2c02e8 str r0, [r3, #0x7c] */
/* @0x2c02ec str r0, [r3, #0x9c] */
/* @0x2c02f0 str r0, [r3, #0xbc] */
/* @0x2c02f4 str r0, [r3, #0xdc] */
/* @0x2c02f8 b 0x2c0008 <jpeg_idct_ifast+0x1b4> */
/* @0x2c02fc ldr r11, [r8, #0x14] */
/* @0x2c0300 ldr r10, [r8, #0x18] */
/* @0x2c0304 cmp r11, #0 */
/* @0x2c0308 bne 0x2c036c <jpeg_idct_ifast+0x518> */
/* @0x2c030c cmp r10, #0 */
/* @0x2c0310 ldr r9, [r8, #0x1c] */
/* @0x2c0314 bne 0x2c037c <jpeg_idct_ifast+0x528> */
/* @0x2c0318 cmp r9, #0 */
/* @0x2c031c bne 0x2c038c <jpeg_idct_ifast+0x538> */
/* @0x2c0320 ldr r1, [r8], #32 */
/* @0x2c0324 ldr r7, [sp, #0xc] */
/* @0x2c0328 ubfx r1, r1, #0x5, #0xa */
/* @0x2c032c ldr r6, [sp, #0x148] */
/* @0x2c0330 ldrb r1, [r2, r1] */
/* @0x2c0334 strb r1, [r7, r6] */
/* @0x2c0338 strb r1, [r3, #0x1] */
/* @0x2c033c strb r1, [r3, #0x2] */
/* @0x2c0340 strb r1, [r3, #0x3] */
/* @0x2c0344 strb r1, [r3, #0x4] */
/* @0x2c0348 strb r1, [r3, #0x5] */
/* @0x2c034c strb r1, [r3, #0x6] */
/* @0x2c0350 strb r1, [r3, #0x7] */
/* @0x2c0354 b 0x2c01e0 <jpeg_idct_ifast+0x38c> */
/* @0x2c0358 mov r5, r0 */
/* @0x2c035c mov r10, r0 */
/* @0x2c0360 mov r4, r0 */
/* @0x2c0364 mov r8, r0 */
/* @0x2c0368 b 0x2bfec8 <jpeg_idct_ifast+0x74> */
/* @0x2c036c mov r5, r12 */
/* @0x2c0370 ldr r9, [r8, #0x1c] */
/* @0x2c0374 mov r1, r12 */
/* @0x2c0378 b 0x2c0094 <jpeg_idct_ifast+0x240> */
/* @0x2c037c mov r5, r11 */
/* @0x2c0380 mov r1, r11 */
/* @0x2c0384 mov r12, r11 */
/* @0x2c0388 b 0x2c0094 <jpeg_idct_ifast+0x240> */
/* @0x2c038c mov r5, r10 */
/* @0x2c0390 mov r11, r10 */
/* @0x2c0394 mov r1, r10 */
/* @0x2c0398 mov r12, r10 */
/* @0x2c039c b 0x2c0094 <jpeg_idct_ifast+0x240> */
/* @0x2c03a0 mov r5, r0 */
/* @0x2c03a4 mov r10, r0 */
/* @0x2c03a8 mov r7, r0 */
/* @0x2c03ac mov r4, r0 */
/* @0x2c03b0 mov r8, r0 */
/* @0x2c03b4 b 0x2bfec8 <jpeg_idct_ifast+0x74> */

/* ── FUNC 0x2c03b8 · jpeg_idct_islow · size=1900 · insn=475 */
/* @0x2c03b8 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2c03bc sub sp, sp, #328 */
/* @0x2c03c0 ldr r1, [r1, #0x50] */
/* @0x2c03c4 add r4, sp, #72 */
/* @0x2c03c8 str r2, [sp, #0xc] */
/* @0x2c03cc movw r7, #0xc4df */
/* @0x2c03d0 ldr r0, [r0, #0x120] */
/* @0x2c03d4 add r2, r2, #2 */
/* @0x2c03d8 ldr r5, [sp, #0xc] */
/* @0x2c03dc add r6, r1, #4 */
/* @0x2c03e0 add r0, r0, #128 */
/* @0x2c03e4 movw r8, #0xe333 */
/* @0x2c03e8 add r5, r5, #16 */
/* @0x2c03ec movt r7, #0xffff */
/* @0x2c03f0 movt r8, #0xffff */
/* @0x2c03f4 movw r9, #0xadfd */
/* @0x2c03f8 movw r10, #0xc13b */
/* @0x2c03fc movt r9, #0xffff */
/* @0x2c0400 movt r10, #0xffff */
/* @0x2c0404 movw r11, #0xf384 */
/* @0x2c0408 str r3, [sp, #0x40] */
/* @0x2c040c movt r11, #0xffff */
/* @0x2c0410 str r4, [sp, #0x44] */
/* @0x2c0414 mov r3, r1 */
/* @0x2c0418 str r0, [sp, #0x14] */
/* @0x2c041c str r2, [sp, #0x1c] */
/* @0x2c0420 str r5, [sp, #0x3c] */
/* @0x2c0424 str r6, [sp, #0x20] */
/* @0x2c0428 str r7, [sp, #0x28] */
/* @0x2c042c str r8, [sp, #0x2c] */
/* @0x2c0430 str r9, [sp, #0x30] */
/* @0x2c0434 str r10, [sp, #0x34] */
/* @0x2c0438 str r11, [sp, #0x38] */
/* @0x2c043c str r4, [sp, #0x10] */
/* @0x2c0440 b 0x2c0664 <jpeg_idct_islow+0x2ac> */
/* @0x2c0444 ldrh r6, [r0, #32] */
/* @0x2c0448 cmp r6, #0 */
/* @0x2c044c beq 0x2c0698 <jpeg_idct_islow+0x2e0> */
/* @0x2c0450 ldr r4, [sp, #0xc] */
/* @0x2c0454 ldrh r5, [r0, #96] */
/* @0x2c0458 ldrh r12, [r0, #64] */
/* @0x2c045c ldrh r2, [r4, #80] */
/* @0x2c0460 ldrh r0, [r0, #112] */
/* @0x2c0464 ldrh r4, [r4, #48] */
/* @0x2c0468 ldr r8, [r3, #0x60] */
/* @0x2c046c sxth r4, r4 */
/* @0x2c0470 ldr r10, [r3, #0xe0] */
/* @0x2c0474 sxth r0, r0 */
/* @0x2c0478 ldr r7, [r3, #0xa0] */
/* @0x2c047c sxth r2, r2 */
/* @0x2c0480 ldr r9, [r3, #0x20] */
/* @0x2c0484 sxth r1, r1 */
/* @0x2c0488 mul r8, r8, r4 */
/* @0x2c048c ldr r11, [r3, #0x40] */
/* @0x2c0490 mul r2, r7, r2 */
/* @0x2c0494 sxth r6, r6 */
/* @0x2c0498 mul r1, r9, r1 */
/* @0x2c049c sxth r5, r5 */
/* @0x2c04a0 mul r0, r10, r0 */
/* @0x2c04a4 str r8, [sp, #0x18] */
/* @0x2c04a8 add r4, r2, r1 */
/* @0x2c04ac ldr r10, [r3, #0xc0] */
/* @0x2c04b0 mul r6, r11, r6 */
/* @0x2c04b4 add r7, r0, r8 */
/* @0x2c04b8 add r9, r7, r4 */
/* @0x2c04bc ldr r11, [sp, #0x18] */
/* @0x2c04c0 movw r8, #0x25a1 */
/* @0x2c04c4 sxth r12, r12 */
/* @0x2c04c8 mul r9, r8, r9 */
/* @0x2c04cc add r8, r2, r11 */
/* @0x2c04d0 ldr r11, [sp, #0x34] */
/* @0x2c04d4 mul r5, r10, r5 */
/* @0x2c04d8 add r10, r0, r1 */
/* @0x2c04dc mla r7, r11, r7, r9 */
/* @0x2c04e0 ldr r11, [sp, #0x38] */
/* @0x2c04e4 mla r9, r11, r4, r9 */
/* @0x2c04e8 ldr r4, [sp, #0x1c] */
/* @0x2c04ec ldr r11, [sp, #0x2c] */
/* @0x2c04f0 ldrsh r4, [r4, #-2] */
/* @0x2c04f4 mul r10, r11, r10 */
/* @0x2c04f8 ldr r11, [sp, #0x30] */
/* @0x2c04fc str r4, [sp, #0x24] */
/* @0x2c0500 ldr r4, [sp, #0x20] */
/* @0x2c0504 mul r8, r11, r8 */
/* @0x2c0508 add r11, r10, r7 */
/* @0x2c050c ldr r4, [r4, #-0x4] */
/* @0x2c0510 add r10, r10, r9 */
/* @0x2c0514 str r11, [sp, #0x4] */
/* @0x2c0518 ldr r11, [sp, #0x24] */
/* @0x2c051c add r9, r8, r9 */
/* @0x2c0520 str r4, [sp, #0x8] */
/* @0x2c0524 add r7, r8, r7 */
/* @0x2c0528 ldr r4, [r3, #0x80] */
/* @0x2c052c add r8, r6, r5 */
/* @0x2c0530 mul r12, r4, r12 */
/* @0x2c0534 ldr r4, [sp, #0x8] */
/* @0x2c0538 mul r4, r4, r11 */
/* @0x2c053c ldr r11, [sp, #0x4] */
/* @0x2c0540 str r4, [sp, #0x24] */
/* @0x2c0544 movw r4, #0x98e */
/* @0x2c0548 mla r0, r4, r0, r11 */
/* @0x2c054c movw r4, #0x1151 */
/* @0x2c0550 mul r8, r4, r8 */
/* @0x2c0554 ldr r4, [sp, #0x28] */
/* @0x2c0558 movw r11, #0x187e */
/* @0x2c055c mla r6, r11, r6, r8 */
/* @0x2c0560 mla r5, r4, r5, r8 */
/* @0x2c0564 ldr r8, [sp, #0x24] */
/* @0x2c0568 movw r4, #0x300b */
/* @0x2c056c mla r10, r4, r1, r10 */
/* @0x2c0570 ldr r1, [sp, #0x18] */
/* @0x2c0574 add r11, r8, r12 */
/* @0x2c0578 rsb r12, r12, r8 */
/* @0x2c057c movw r8, #0x41b3 */
/* @0x2c0580 mla r9, r8, r2, r9 */
/* @0x2c0584 movw r2, #0x6254 */
/* @0x2c0588 mla r7, r2, r1, r7 */
/* @0x2c058c lsl r11, r11, #13 */
/* @0x2c0590 lsl r12, r12, #13 */
/* @0x2c0594 add r1, r11, r6 */
/* @0x2c0598 rsb r6, r6, r11 */
/* @0x2c059c add r11, r12, r5 */
/* @0x2c05a0 rsb r5, r5, r12 */
/* @0x2c05a4 add r2, r11, r7 */
/* @0x2c05a8 add r4, r1, r10 */
/* @0x2c05ac add r8, r6, r0 */
/* @0x2c05b0 rsb r7, r7, r11 */
/* @0x2c05b4 rsb r10, r10, r1 */
/* @0x2c05b8 add r11, r5, r9 */
/* @0x2c05bc rsb r0, r0, r6 */
/* @0x2c05c0 rsb r9, r9, r5 */
/* @0x2c05c4 ldr r5, [sp, #0x10] */
/* @0x2c05c8 add r4, r4, #1024 */
/* @0x2c05cc add r10, r10, #1024 */
/* @0x2c05d0 add r8, r8, #1024 */
/* @0x2c05d4 add r0, r0, #1024 */
/* @0x2c05d8 add r2, r2, #1024 */
/* @0x2c05dc add r7, r7, #1024 */
/* @0x2c05e0 add r11, r11, #1024 */
/* @0x2c05e4 add r9, r9, #1024 */
/* @0x2c05e8 asr r4, r4, #11 */
/* @0x2c05ec asr r10, r10, #11 */
/* @0x2c05f0 str r4, [r5] */
/* @0x2c05f4 asr r8, r8, #11 */
/* @0x2c05f8 str r10, [r5, #0xe0] */
/* @0x2c05fc asr r0, r0, #11 */
/* @0x2c0600 str r8, [r5, #0x60] */
/* @0x2c0604 asr r2, r2, #11 */
/* @0x2c0608 str r0, [r5, #0x80] */
/* @0x2c060c asr r7, r7, #11 */
/* @0x2c0610 str r2, [r5, #0x20] */
/* @0x2c0614 asr r11, r11, #11 */
/* @0x2c0618 str r7, [r5, #0xc0] */
/* @0x2c061c asr r9, r9, #11 */
/* @0x2c0620 str r11, [r5, #0x40] */
/* @0x2c0624 add r5, r5, #4 */
/* @0x2c0628 str r9, [r5, #0x9c] */
/* @0x2c062c str r5, [sp, #0x10] */
/* @0x2c0630 ldr r6, [sp, #0xc] */
/* @0x2c0634 add r3, r3, #4 */
/* @0x2c0638 ldr r8, [sp, #0x3c] */
/* @0x2c063c add r6, r6, #2 */
/* @0x2c0640 ldr r7, [sp, #0x1c] */
/* @0x2c0644 ldr r9, [sp, #0x20] */
/* @0x2c0648 cmp r6, r8 */
/* @0x2c064c add r7, r7, #2 */
/* @0x2c0650 str r6, [sp, #0xc] */
/* @0x2c0654 add r9, r9, #4 */
/* @0x2c0658 str r7, [sp, #0x1c] */
/* @0x2c065c str r9, [sp, #0x20] */
/* @0x2c0660 beq 0x2c06cc <jpeg_idct_islow+0x314> */
/* @0x2c0664 ldr r0, [sp, #0xc] */
/* @0x2c0668 ldrh r1, [r0, #16] */
/* @0x2c066c cmp r1, #0 */
/* @0x2c0670 beq 0x2c0444 <jpeg_idct_islow+0x8c> */
/* @0x2c0674 ldr r2, [sp, #0xc] */
/* @0x2c0678 ldr r7, [sp, #0xc] */
/* @0x2c067c ldrh r6, [r2, #32] */
/* @0x2c0680 ldrh r5, [r2, #96] */
/* @0x2c0684 ldrh r12, [r2, #64] */
/* @0x2c0688 ldrh r0, [r2, #112] */
/* @0x2c068c ldrh r4, [r7, #48] */
/* @0x2c0690 ldrh r2, [r2, #80] */
/* @0x2c0694 b 0x2c0468 <jpeg_idct_islow+0xb0> */
/* @0x2c0698 ldr r5, [sp, #0xc] */
/* @0x2c069c ldrh r2, [r5, #48] */
/* @0x2c06a0 cmp r2, #0 */
/* @0x2c06a4 beq 0x2c0960 <jpeg_idct_islow+0x5a8> */
/* @0x2c06a8 ldr r6, [sp, #0xc] */
/* @0x2c06ac mov r4, r2 */
/* @0x2c06b0 ldr r7, [sp, #0xc] */
/* @0x2c06b4 ldrh r5, [r5, #96] */
/* @0x2c06b8 ldrh r12, [r6, #64] */
/* @0x2c06bc mov r6, r1 */
/* @0x2c06c0 ldrh r0, [r7, #112] */
/* @0x2c06c4 ldrh r2, [r7, #80] */
/* @0x2c06c8 b 0x2c0468 <jpeg_idct_islow+0xb0> */
/* @0x2c06cc movw r12, #0xadfd */
/* @0x2c06d0 movt r12, #0xffff */
/* @0x2c06d4 str r12, [sp, #0x2c] */
/* @0x2c06d8 add r12, sp, #72 */
/* @0x2c06dc movw r10, #0xc4df */
/* @0x2c06e0 movw r11, #0xe333 */
/* @0x2c06e4 movt r10, #0xffff */
/* @0x2c06e8 movt r11, #0xffff */
/* @0x2c06ec movw r0, #0xc13b */
/* @0x2c06f0 movw r1, #0xf384 */
/* @0x2c06f4 movt r0, #0xffff */
/* @0x2c06f8 movt r1, #0xffff */
/* @0x2c06fc mov r2, #0 */
/* @0x2c0700 str r10, [sp, #0x24] */
/* @0x2c0704 str r11, [sp, #0x28] */
/* @0x2c0708 mov r4, r12 */
/* @0x2c070c str r0, [sp, #0x30] */
/* @0x2c0710 str r1, [sp, #0x34] */
/* @0x2c0714 str r2, [sp, #0x10] */
/* @0x2c0718 b 0x2c08f4 <jpeg_idct_islow+0x53c> */
/* @0x2c071c cmp r1, #0 */
/* @0x2c0720 beq 0x2c093c <jpeg_idct_islow+0x584> */
/* @0x2c0724 ldr r7, [r4, #0x1c] */
/* @0x2c0728 ldr r11, [r4, #0x18] */
/* @0x2c072c ldr r6, [r4, #0x10] */
/* @0x2c0730 ldr r2, [r4, #0x14] */
/* @0x2c0734 ldr r3, [r4, #0xc] */
/* @0x2c0738 str r7, [sp, #0x18] */
/* @0x2c073c ldr r10, [sp, #0x18] */
/* @0x2c0740 add r7, r0, r2 */
/* @0x2c0744 add r5, r1, r11 */
/* @0x2c0748 add r9, r10, r3 */
/* @0x2c074c add r8, r0, r10 */
/* @0x2c0750 add r12, r9, r7 */
/* @0x2c0754 movw r10, #0x25a1 */
/* @0x2c0758 mul r12, r10, r12 */
/* @0x2c075c ldr r10, [sp, #0x34] */
/* @0x2c0760 mla r7, r10, r7, r12 */
/* @0x2c0764 ldr r10, [sp, #0x28] */
/* @0x2c0768 mul r8, r10, r8 */
/* @0x2c076c ldr r10, [r4], #32 */
/* @0x2c0770 str r8, [sp, #0x20] */
/* @0x2c0774 movw r8, #0x1151 */
/* @0x2c0778 mul r5, r8, r5 */
/* @0x2c077c add r8, r2, r3 */
/* @0x2c0780 str r8, [sp, #0x3c] */
/* @0x2c0784 movw r8, #0x187e */
/* @0x2c0788 mla r1, r8, r1, r5 */
/* @0x2c078c ldr r8, [sp, #0x20] */
/* @0x2c0790 add r8, r8, r7 */
/* @0x2c0794 str r8, [sp, #0x44] */
/* @0x2c0798 str r1, [sp, #0x38] */
/* @0x2c079c ldr r1, [sp, #0x30] */
/* @0x2c07a0 mla r12, r1, r9, r12 */
/* @0x2c07a4 ldr r9, [sp, #0x2c] */
/* @0x2c07a8 movw r1, #0x300b */
/* @0x2c07ac str r12, [sp, #0x4] */
/* @0x2c07b0 ldr r12, [sp, #0x3c] */
/* @0x2c07b4 mul r8, r9, r12 */
/* @0x2c07b8 ldr r12, [sp, #0x44] */
/* @0x2c07bc mla r9, r1, r0, r12 */
/* @0x2c07c0 add r0, r10, r6 */
/* @0x2c07c4 ldr r1, [sp, #0x24] */
/* @0x2c07c8 rsb r6, r6, r10 */
/* @0x2c07cc ldr r10, [sp, #0x38] */
/* @0x2c07d0 lsl r0, r0, #13 */
/* @0x2c07d4 ldr r12, [sp, #0x4] */
/* @0x2c07d8 lsl r6, r6, #13 */
/* @0x2c07dc mla r5, r1, r11, r5 */
/* @0x2c07e0 add r11, r0, r10 */
/* @0x2c07e4 add r10, r11, r9 */
/* @0x2c07e8 rsb r9, r9, r11 */
/* @0x2c07ec add r11, r8, r12 */
/* @0x2c07f0 movw r1, #0x6254 */
/* @0x2c07f4 add r10, r10, #131072 */
/* @0x2c07f8 ldr r12, [sp, #0x168] */
/* @0x2c07fc mla r3, r1, r3, r11 */
/* @0x2c0800 ldr r11, [sp, #0x14] */
/* @0x2c0804 ubfx r10, r10, #0x12, #0xa */
/* @0x2c0808 ldr r1, [sp, #0x1c] */
/* @0x2c080c add r9, r9, #131072 */
/* @0x2c0810 add r7, r8, r7 */
/* @0x2c0814 ldrb r10, [r11, r10] */
/* @0x2c0818 ubfx r9, r9, #0x12, #0xa */
/* @0x2c081c add r11, r6, r5 */
/* @0x2c0820 rsb r5, r5, r6 */
/* @0x2c0824 add r8, r11, r3 */
/* @0x2c0828 rsb r3, r3, r11 */
/* @0x2c082c strb r10, [r1, r12] */
/* @0x2c0830 add r8, r8, #131072 */
/* @0x2c0834 ldr r10, [sp, #0x14] */
/* @0x2c0838 movw r12, #0x41b3 */
/* @0x2c083c ldr r1, [sp, #0xc] */
/* @0x2c0840 ubfx r8, r8, #0x12, #0xa */
/* @0x2c0844 mla r7, r12, r2, r7 */
/* @0x2c0848 ldrb r9, [r10, r9] */
/* @0x2c084c ldr r2, [sp, #0x20] */
/* @0x2c0850 add r3, r3, #131072 */
/* @0x2c0854 ldr r6, [sp, #0x4] */
/* @0x2c0858 ubfx r3, r3, #0x12, #0xa */
/* @0x2c085c strb r9, [r1, #0x7] */
/* @0x2c0860 ldrb r9, [r10, r8] */
/* @0x2c0864 add r12, r2, r6 */
/* @0x2c0868 add r2, r5, r7 */
/* @0x2c086c ldr r8, [sp, #0x18] */
/* @0x2c0870 add r2, r2, #131072 */
/* @0x2c0874 ldr r11, [sp, #0xc] */
/* @0x2c0878 strb r9, [r1, #0x1] */
/* @0x2c087c ubfx r2, r2, #0x12, #0xa */
/* @0x2c0880 ldrb r3, [r10, r3] */
/* @0x2c0884 movw r9, #0x98e */
/* @0x2c0888 mla r12, r9, r8, r12 */
/* @0x2c088c rsb r7, r7, r5 */
/* @0x2c0890 strb r3, [r1, #0x6] */
/* @0x2c0894 add r7, r7, #131072 */
/* @0x2c0898 ldrb r3, [r10, r2] */
/* @0x2c089c ubfx r7, r7, #0x12, #0xa */
/* @0x2c08a0 ldr r10, [sp, #0x38] */
/* @0x2c08a4 strb r3, [r11, #0x2] */
/* @0x2c08a8 rsb r1, r10, r0 */
/* @0x2c08ac ldr r0, [sp, #0x14] */
/* @0x2c08b0 add r2, r1, r12 */
/* @0x2c08b4 add r2, r2, #131072 */
/* @0x2c08b8 rsb r12, r12, r1 */
/* @0x2c08bc ubfx r2, r2, #0x12, #0xa */
/* @0x2c08c0 add r12, r12, #131072 */
/* @0x2c08c4 ldrb r3, [r0, r7] */
/* @0x2c08c8 ubfx r12, r12, #0x12, #0xa */
/* @0x2c08cc strb r3, [r11, #0x5] */
/* @0x2c08d0 ldrb r3, [r0, r2] */
/* @0x2c08d4 strb r3, [r11, #0x3] */
/* @0x2c08d8 ldrb r3, [r0, r12] */
/* @0x2c08dc strb r3, [r11, #0x4] */
/* @0x2c08e0 ldr r1, [sp, #0x10] */
/* @0x2c08e4 add r1, r1, #4 */
/* @0x2c08e8 str r1, [sp, #0x10] */
/* @0x2c08ec cmp r1, #32 */
/* @0x2c08f0 beq 0x2c0988 <jpeg_idct_islow+0x5d0> */
/* @0x2c08f4 ldr r5, [sp, #0x40] */
/* @0x2c08f8 ldr r3, [sp, #0x10] */
/* @0x2c08fc ldr r0, [r4, #0x4] */
/* @0x2c0900 ldr r6, [sp, #0x168] */
/* @0x2c0904 ldr r3, [r5, r3] */
/* @0x2c0908 cmp r0, #0 */
/* @0x2c090c ldr r1, [r4, #0x8] */
/* @0x2c0910 add r6, r3, r6 */
/* @0x2c0914 str r6, [sp, #0xc] */
/* @0x2c0918 str r3, [sp, #0x1c] */
/* @0x2c091c beq 0x2c071c <jpeg_idct_islow+0x364> */
/* @0x2c0920 ldr r8, [r4, #0x1c] */
/* @0x2c0924 ldr r11, [r4, #0x18] */
/* @0x2c0928 ldr r6, [r4, #0x10] */
/* @0x2c092c str r8, [sp, #0x18] */
/* @0x2c0930 ldr r2, [r4, #0x14] */
/* @0x2c0934 ldr r3, [r4, #0xc] */
/* @0x2c0938 b 0x2c073c <jpeg_idct_islow+0x384> */
/* @0x2c093c ldr r3, [r4, #0xc] */
/* @0x2c0940 cmp r3, #0 */
/* @0x2c0944 beq 0x2c0994 <jpeg_idct_islow+0x5dc> */
/* @0x2c0948 ldr r8, [r4, #0x1c] */
/* @0x2c094c ldr r11, [r4, #0x18] */
/* @0x2c0950 ldr r6, [r4, #0x10] */
/* @0x2c0954 str r8, [sp, #0x18] */
/* @0x2c0958 ldr r2, [r4, #0x14] */
/* @0x2c095c b 0x2c073c <jpeg_idct_islow+0x384> */
/* @0x2c0960 ldr r8, [sp, #0xc] */
/* @0x2c0964 ldrh r12, [r8, #64] */
/* @0x2c0968 cmp r12, #0 */
/* @0x2c096c beq 0x2c09b8 <jpeg_idct_islow+0x600> */
/* @0x2c0970 ldrh r5, [r8, #96] */
/* @0x2c0974 mov r4, r1 */
/* @0x2c0978 ldrh r0, [r8, #112] */
/* @0x2c097c mov r6, r1 */
/* @0x2c0980 ldrh r2, [r8, #80] */
/* @0x2c0984 b 0x2c0468 <jpeg_idct_islow+0xb0> */
/* @0x2c0988 add sp, sp, #328 */
/* @0x2c098c pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2c0990 bx lr */
/* @0x2c0994 ldr r6, [r4, #0x10] */
/* @0x2c0998 cmp r6, #0 */
/* @0x2c099c beq 0x2c0a30 <jpeg_idct_islow+0x678> */
/* @0x2c09a0 ldr r9, [r4, #0x1c] */
/* @0x2c09a4 mov r1, r3 */
/* @0x2c09a8 ldr r11, [r4, #0x18] */
/* @0x2c09ac ldr r2, [r4, #0x14] */
/* @0x2c09b0 str r9, [sp, #0x18] */
/* @0x2c09b4 b 0x2c073c <jpeg_idct_islow+0x384> */
/* @0x2c09b8 ldr r9, [sp, #0xc] */
/* @0x2c09bc ldrh r2, [r9, #80] */
/* @0x2c09c0 cmp r2, #0 */
/* @0x2c09c4 bne 0x2c0ab0 <jpeg_idct_islow+0x6f8> */
/* @0x2c09c8 ldr r10, [sp, #0xc] */
/* @0x2c09cc ldrh r5, [r10, #96] */
/* @0x2c09d0 cmp r5, #0 */
/* @0x2c09d4 bne 0x2c0ac8 <jpeg_idct_islow+0x710> */
/* @0x2c09d8 ldr r11, [sp, #0xc] */
/* @0x2c09dc ldrh r0, [r11, #112] */
/* @0x2c09e0 cmp r0, #0 */
/* @0x2c09e4 bne 0x2c0af8 <jpeg_idct_islow+0x740> */
/* @0x2c09e8 ldr r12, [sp, #0x1c] */
/* @0x2c09ec ldr r0, [sp, #0x20] */
/* @0x2c09f0 ldrsh r2, [r12, #-2] */
/* @0x2c09f4 ldr r1, [r0, #-0x4] */
/* @0x2c09f8 mul r2, r1, r2 */
/* @0x2c09fc ldr r1, [sp, #0x10] */
/* @0x2c0a00 add r1, r1, #4 */
/* @0x2c0a04 lsl r2, r2, #2 */
/* @0x2c0a08 str r2, [r1, #-0x4] */
/* @0x2c0a0c str r2, [r1, #0x1c] */
/* @0x2c0a10 str r2, [r1, #0x3c] */
/* @0x2c0a14 str r2, [r1, #0x5c] */
/* @0x2c0a18 str r2, [r1, #0x7c] */
/* @0x2c0a1c str r2, [r1, #0x9c] */
/* @0x2c0a20 str r2, [r1, #0xbc] */
/* @0x2c0a24 str r2, [r1, #0xdc] */
/* @0x2c0a28 str r1, [sp, #0x10] */
/* @0x2c0a2c b 0x2c0630 <jpeg_idct_islow+0x278> */
/* @0x2c0a30 ldr r2, [r4, #0x14] */
/* @0x2c0a34 ldr r11, [r4, #0x18] */
/* @0x2c0a38 cmp r2, #0 */
/* @0x2c0a3c bne 0x2c0a9c <jpeg_idct_islow+0x6e4> */
/* @0x2c0a40 cmp r11, #0 */
/* @0x2c0a44 bne 0x2c0ae0 <jpeg_idct_islow+0x728> */
/* @0x2c0a48 ldr r1, [r4, #0x1c] */
/* @0x2c0a4c cmp r1, #0 */
/* @0x2c0a50 str r1, [sp, #0x18] */
/* @0x2c0a54 bne 0x2c0b10 <jpeg_idct_islow+0x758> */
/* @0x2c0a58 ldr r3, [r4], #32 */
/* @0x2c0a5c ldr r2, [sp, #0x14] */
/* @0x2c0a60 add r3, r3, #16 */
/* @0x2c0a64 ldr r7, [sp, #0xc] */
/* @0x2c0a68 ubfx r3, r3, #0x5, #0xa */
/* @0x2c0a6c ldr r6, [sp, #0x1c] */
/* @0x2c0a70 ldr r5, [sp, #0x168] */
/* @0x2c0a74 ldrb r3, [r2, r3] */
/* @0x2c0a78 strb r3, [r6, r5] */
/* @0x2c0a7c strb r3, [r7, #0x1] */
/* @0x2c0a80 strb r3, [r7, #0x2] */
/* @0x2c0a84 strb r3, [r7, #0x3] */
/* @0x2c0a88 strb r3, [r7, #0x4] */
/* @0x2c0a8c strb r3, [r7, #0x5] */
/* @0x2c0a90 strb r3, [r7, #0x6] */
/* @0x2c0a94 strb r3, [r7, #0x7] */
/* @0x2c0a98 b 0x2c08e0 <jpeg_idct_islow+0x528> */
/* @0x2c0a9c ldr r10, [r4, #0x1c] */
/* @0x2c0aa0 mov r3, r6 */
/* @0x2c0aa4 mov r1, r6 */
/* @0x2c0aa8 str r10, [sp, #0x18] */
/* @0x2c0aac b 0x2c073c <jpeg_idct_islow+0x384> */
/* @0x2c0ab0 ldrh r5, [r9, #96] */
/* @0x2c0ab4 mov r4, r1 */
/* @0x2c0ab8 ldrh r0, [r9, #112] */
/* @0x2c0abc mov r12, r1 */
/* @0x2c0ac0 mov r6, r1 */
/* @0x2c0ac4 b 0x2c0468 <jpeg_idct_islow+0xb0> */
/* @0x2c0ac8 ldrh r0, [r10, #112] */
/* @0x2c0acc mov r4, r1 */
/* @0x2c0ad0 mov r2, r1 */
/* @0x2c0ad4 mov r12, r1 */
/* @0x2c0ad8 mov r6, r1 */
/* @0x2c0adc b 0x2c0468 <jpeg_idct_islow+0xb0> */
/* @0x2c0ae0 ldr r12, [r4, #0x1c] */
/* @0x2c0ae4 mov r3, r2 */
/* @0x2c0ae8 mov r6, r2 */
/* @0x2c0aec mov r1, r2 */
/* @0x2c0af0 str r12, [sp, #0x18] */
/* @0x2c0af4 b 0x2c073c <jpeg_idct_islow+0x384> */
/* @0x2c0af8 mov r4, r1 */
/* @0x2c0afc mov r2, r1 */
/* @0x2c0b00 mov r12, r1 */
/* @0x2c0b04 mov r5, r1 */
/* @0x2c0b08 mov r6, r1 */
/* @0x2c0b0c b 0x2c0468 <jpeg_idct_islow+0xb0> */
/* @0x2c0b10 mov r3, r11 */
/* @0x2c0b14 mov r2, r11 */
/* @0x2c0b18 mov r6, r11 */
/* @0x2c0b1c mov r1, r11 */
/* @0x2c0b20 b 0x2c073c <jpeg_idct_islow+0x384> */

/* ── FUNC 0x2c0b24 · jpeg_idct_4x4 · size=1168 · insn=292 */
/* @0x2c0b24 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2c0b28 sub sp, sp, #176 */
/* @0x2c0b2c ldr r1, [r1, #0x50] */
/* @0x2c0b30 add r4, sp, #48 */
/* @0x2c0b34 ldr r0, [r0, #0x120] */
/* @0x2c0b38 movw r5, #0xe782 */
/* @0x2c0b3c str r4, [sp, #0x28] */
/* @0x2c0b40 movw r7, #0xf93e */
/* @0x2c0b44 add r0, r0, #128 */
/* @0x2c0b48 str r3, [sp, #0x24] */
/* @0x2c0b4c add r4, r2, #2 */
/* @0x2c0b50 str r0, [sp, #0x2c] */
/* @0x2c0b54 mov r3, r2 */
/* @0x2c0b58 movt r5, #0xffff */
/* @0x2c0b5c movt r7, #0xffff */
/* @0x2c0b60 movw r8, #0xba79 */
/* @0x2c0b64 movw r9, #0xefb0 */
/* @0x2c0b68 movt r8, #0xffff */
/* @0x2c0b6c movt r9, #0xffff */
/* @0x2c0b70 movw r11, #0xecc2 */
/* @0x2c0b74 add r12, r1, #4 */
/* @0x2c0b78 movt r11, #0xffff */
/* @0x2c0b7c add r0, sp, #48 */
/* @0x2c0b80 str r5, [sp, #0x10] */
/* @0x2c0b84 str r7, [sp, #0x14] */
/* @0x2c0b88 mov r2, #7 */
/* @0x2c0b8c str r8, [sp, #0x18] */
/* @0x2c0b90 str r9, [sp, #0x1c] */
/* @0x2c0b94 str r11, [sp, #0x20] */
/* @0x2c0b98 b 0x2c0cf0 <jpeg_idct_4x4+0x1cc> */
/* @0x2c0b9c cmp r7, #0 */
/* @0x2c0ba0 bne 0x2c0d08 <jpeg_idct_4x4+0x1e4> */
/* @0x2c0ba4 ldrh r6, [r3, #48] */
/* @0x2c0ba8 cmp r6, #0 */
/* @0x2c0bac beq 0x2c0ec8 <jpeg_idct_4x4+0x3a4> */
/* @0x2c0bb0 ldrh r8, [r3, #96] */
/* @0x2c0bb4 mov r7, r5 */
/* @0x2c0bb8 ldrh r9, [r3, #112] */
/* @0x2c0bbc ldrh r10, [r3, #80] */
/* @0x2c0bc0 sxth r8, r8 */
/* @0x2c0bc4 str r8, [sp, #0x4] */
/* @0x2c0bc8 ldr r8, [r1, #0xa0] */
/* @0x2c0bcc sxth r10, r10 */
/* @0x2c0bd0 ldr r11, [r1, #0xe0] */
/* @0x2c0bd4 sxth r9, r9 */
/* @0x2c0bd8 sxth r6, r6 */
/* @0x2c0bdc sxth r5, r5 */
/* @0x2c0be0 mul r10, r8, r10 */
/* @0x2c0be4 ldr r8, [r1, #0x60] */
/* @0x2c0be8 mul r9, r11, r9 */
/* @0x2c0bec str r5, [sp, #0x8] */
/* @0x2c0bf0 mul r6, r8, r6 */
/* @0x2c0bf4 ldr r8, [sp, #0x20] */
/* @0x2c0bf8 movw r5, #0x2e75 */
/* @0x2c0bfc sxth r7, r7 */
/* @0x2c0c00 mul r11, r5, r10 */
/* @0x2c0c04 ldr r5, [sp, #0x14] */
/* @0x2c0c08 mul r10, r8, r10 */
/* @0x2c0c0c ldr r8, [sp, #0x1c] */
/* @0x2c0c10 mla r11, r5, r9, r11 */
/* @0x2c0c14 ldr r5, [sp, #0x4] */
/* @0x2c0c18 mla r10, r8, r9, r10 */
/* @0x2c0c1c ldr r9, [r1, #0xc0] */
/* @0x2c0c20 mul r8, r9, r5 */
/* @0x2c0c24 ldr r9, [r1, #0x40] */
/* @0x2c0c28 ldr r5, [r1, #0x20] */
/* @0x2c0c2c mul r7, r9, r7 */
/* @0x2c0c30 ldrsh r9, [r4, #-2] */
/* @0x2c0c34 str r7, [sp, #0xc] */
/* @0x2c0c38 ldr r7, [sp, #0x8] */
/* @0x2c0c3c mul r5, r5, r7 */
/* @0x2c0c40 ldr r7, [r12, #-0x4] */
/* @0x2c0c44 mul r9, r7, r9 */
/* @0x2c0c48 ldr r7, [sp, #0x10] */
/* @0x2c0c4c str r5, [sp, #0x4] */
/* @0x2c0c50 ldr r5, [sp, #0x18] */
/* @0x2c0c54 mul r8, r7, r8 */
/* @0x2c0c58 movw r7, #0x3b21 */
/* @0x2c0c5c mla r11, r5, r6, r11 */
/* @0x2c0c60 movw r5, #0x1ccd */
/* @0x2c0c64 mla r6, r5, r6, r10 */
/* @0x2c0c68 ldr r5, [sp, #0xc] */
/* @0x2c0c6c lsl r9, r9, #14 */
/* @0x2c0c70 mla r8, r7, r5, r8 */
/* @0x2c0c74 ldr r5, [sp, #0x4] */
/* @0x2c0c78 movw r7, #0x21f9 */
/* @0x2c0c7c mla r11, r7, r5, r11 */
/* @0x2c0c80 movw r7, #0x5203 */
/* @0x2c0c84 mla r6, r7, r5, r6 */
/* @0x2c0c88 add r5, r9, r8 */
/* @0x2c0c8c rsb r8, r8, r9 */
/* @0x2c0c90 add r7, r8, r11 */
/* @0x2c0c94 rsb r11, r11, r8 */
/* @0x2c0c98 add r8, r5, r6 */
/* @0x2c0c9c rsb r6, r6, r5 */
/* @0x2c0ca0 add r8, r8, #2048 */
/* @0x2c0ca4 add r6, r6, #2048 */
/* @0x2c0ca8 add r7, r7, #2048 */
/* @0x2c0cac add r11, r11, #2048 */
/* @0x2c0cb0 asr r8, r8, #12 */
/* @0x2c0cb4 asr r6, r6, #12 */
/* @0x2c0cb8 asr r7, r7, #12 */
/* @0x2c0cbc asr r11, r11, #12 */
/* @0x2c0cc0 str r8, [r0] */
/* @0x2c0cc4 str r6, [r0, #0x60] */
/* @0x2c0cc8 str r7, [r0, #0x20] */
/* @0x2c0ccc str r11, [r0, #0x40] */
/* @0x2c0cd0 cmp r2, #0 */
/* @0x2c0cd4 add r0, r0, #4 */
/* @0x2c0cd8 beq 0x2c0d24 <jpeg_idct_4x4+0x200> */
/* @0x2c0cdc add r4, r4, #2 */
/* @0x2c0ce0 add r3, r3, #2 */
/* @0x2c0ce4 add r12, r12, #4 */
/* @0x2c0ce8 add r1, r1, #4 */
/* @0x2c0cec sub r2, r2, #1 */
/* @0x2c0cf0 cmp r2, #3 */
/* @0x2c0cf4 beq 0x2c0d1c <jpeg_idct_4x4+0x1f8> */
/* @0x2c0cf8 ldrh r5, [r3, #16] */
/* @0x2c0cfc ldrh r7, [r3, #32] */
/* @0x2c0d00 cmp r5, #0 */
/* @0x2c0d04 beq 0x2c0b9c <jpeg_idct_4x4+0x78> */
/* @0x2c0d08 ldrh r8, [r3, #96] */
/* @0x2c0d0c ldrh r9, [r3, #112] */
/* @0x2c0d10 ldrh r10, [r3, #80] */
/* @0x2c0d14 ldrh r6, [r3, #48] */
/* @0x2c0d18 b 0x2c0bc0 <jpeg_idct_4x4+0x9c> */
/* @0x2c0d1c add r0, r0, #4 */
/* @0x2c0d20 b 0x2c0cdc <jpeg_idct_4x4+0x1b8> */
/* @0x2c0d24 movw r10, #0xf93e */
/* @0x2c0d28 movw r12, #0xecc2 */
/* @0x2c0d2c movt r10, #0xffff */
/* @0x2c0d30 movt r12, #0xffff */
/* @0x2c0d34 str r10, [sp, #0x14] */
/* @0x2c0d38 add r3, sp, #48 */
/* @0x2c0d3c str r12, [sp, #0xc] */
/* @0x2c0d40 movw r11, #0xe782 */
/* @0x2c0d44 ldr r12, [sp, #0x2c] */
/* @0x2c0d48 movt r11, #0xffff */
/* @0x2c0d4c ldr r10, [sp, #0xd0] */
/* @0x2c0d50 movw r8, #0xba79 */
/* @0x2c0d54 movw r9, #0xefb0 */
/* @0x2c0d58 movt r8, #0xffff */
/* @0x2c0d5c movt r9, #0xffff */
/* @0x2c0d60 str r8, [sp, #0x4] */
/* @0x2c0d64 str r9, [sp, #0x8] */
/* @0x2c0d68 str r11, [sp, #0x10] */
/* @0x2c0d6c ldr r1, [sp, #0x24] */
/* @0x2c0d70 ldr r0, [r3, #0x4] */
/* @0x2c0d74 ldr r8, [r3, #0x8] */
/* @0x2c0d78 ldr r6, [r1, r2] */
/* @0x2c0d7c cmp r0, #0 */
/* @0x2c0d80 add r1, r6, r10 */
/* @0x2c0d84 bne 0x2c0e90 <jpeg_idct_4x4+0x36c> */
/* @0x2c0d88 cmp r8, #0 */
/* @0x2c0d8c beq 0x2c0ea8 <jpeg_idct_4x4+0x384> */
/* @0x2c0d90 ldr r4, [r3, #0x18] */
/* @0x2c0d94 ldr r7, [r3, #0x1c] */
/* @0x2c0d98 ldr r5, [r3, #0x14] */
/* @0x2c0d9c str r4, [sp, #0x20] */
/* @0x2c0da0 ldr r4, [r3, #0xc] */
/* @0x2c0da4 ldr r11, [sp, #0xc] */
/* @0x2c0da8 ldr r9, [sp, #0x8] */
/* @0x2c0dac mul r11, r11, r5 */
/* @0x2c0db0 mla r9, r9, r7, r11 */
/* @0x2c0db4 movw r11, #0x2e75 */
/* @0x2c0db8 mul r5, r11, r5 */
/* @0x2c0dbc movw r11, #0x1ccd */
/* @0x2c0dc0 str r9, [sp, #0x1c] */
/* @0x2c0dc4 ldr r9, [sp, #0x14] */
/* @0x2c0dc8 mla r5, r9, r7, r5 */
/* @0x2c0dcc ldr r7, [sp, #0x1c] */
/* @0x2c0dd0 mla r11, r11, r4, r7 */
/* @0x2c0dd4 ldr r7, [sp, #0x10] */
/* @0x2c0dd8 str r5, [sp, #0x18] */
/* @0x2c0ddc ldr r5, [r3], #32 */
/* @0x2c0de0 str r11, [sp, #0x1c] */
/* @0x2c0de4 lsl r5, r5, #14 */
/* @0x2c0de8 ldr r11, [sp, #0x20] */
/* @0x2c0dec mul r9, r7, r11 */
/* @0x2c0df0 movw r7, #0x3b21 */
/* @0x2c0df4 mla r9, r7, r8, r9 */
/* @0x2c0df8 ldr r7, [sp, #0x1c] */
/* @0x2c0dfc movw r8, #0x5203 */
/* @0x2c0e00 mla r11, r8, r0, r7 */
/* @0x2c0e04 ldr r7, [sp, #0x18] */
/* @0x2c0e08 ldr r8, [sp, #0x4] */
/* @0x2c0e0c mla r4, r8, r4, r7 */
/* @0x2c0e10 add r8, r5, r9 */
/* @0x2c0e14 rsb r9, r9, r5 */
/* @0x2c0e18 str r4, [sp, #0x18] */
/* @0x2c0e1c add r4, r8, r11 */
/* @0x2c0e20 ldr r5, [sp, #0x18] */
/* @0x2c0e24 rsb r11, r11, r8 */
/* @0x2c0e28 add r4, r4, #262144 */
/* @0x2c0e2c movw r8, #0x21f9 */
/* @0x2c0e30 ubfx r4, r4, #0x13, #0xa */
/* @0x2c0e34 add r11, r11, #262144 */
/* @0x2c0e38 mla r7, r8, r0, r5 */
/* @0x2c0e3c ldrb r4, [r12, r4] */
/* @0x2c0e40 ubfx r11, r11, #0x13, #0xa */
/* @0x2c0e44 add r0, r9, r7 */
/* @0x2c0e48 strb r4, [r6, r10] */
/* @0x2c0e4c add r0, r0, #262144 */
/* @0x2c0e50 ldrb r6, [r12, r11] */
/* @0x2c0e54 ubfx r0, r0, #0x13, #0xa */
/* @0x2c0e58 rsb r7, r7, r9 */
/* @0x2c0e5c add r7, r7, #262144 */
/* @0x2c0e60 strb r6, [r1, #0x3] */
/* @0x2c0e64 ubfx r7, r7, #0x13, #0xa */
/* @0x2c0e68 ldrb r0, [r12, r0] */
/* @0x2c0e6c strb r0, [r1, #0x1] */
/* @0x2c0e70 ldrb r0, [r12, r7] */
/* @0x2c0e74 strb r0, [r1, #0x2] */
/* @0x2c0e78 add r2, r2, #4 */
/* @0x2c0e7c cmp r2, #16 */
/* @0x2c0e80 bne 0x2c0d6c <jpeg_idct_4x4+0x248> */
/* @0x2c0e84 add sp, sp, #176 */
/* @0x2c0e88 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2c0e8c bx lr */
/* @0x2c0e90 ldr r9, [r3, #0x18] */
/* @0x2c0e94 ldr r7, [r3, #0x1c] */
/* @0x2c0e98 ldr r5, [r3, #0x14] */
/* @0x2c0e9c str r9, [sp, #0x20] */
/* @0x2c0ea0 ldr r4, [r3, #0xc] */
/* @0x2c0ea4 b 0x2c0da4 <jpeg_idct_4x4+0x280> */
/* @0x2c0ea8 ldr r4, [r3, #0xc] */
/* @0x2c0eac cmp r4, #0 */
/* @0x2c0eb0 beq 0x2c0f18 <jpeg_idct_4x4+0x3f4> */
/* @0x2c0eb4 ldr r5, [r3, #0x18] */
/* @0x2c0eb8 ldr r7, [r3, #0x1c] */
/* @0x2c0ebc str r5, [sp, #0x20] */
/* @0x2c0ec0 ldr r5, [r3, #0x14] */
/* @0x2c0ec4 b 0x2c0da4 <jpeg_idct_4x4+0x280> */
/* @0x2c0ec8 ldrh r10, [r3, #80] */
/* @0x2c0ecc ldrh r8, [r3, #96] */
/* @0x2c0ed0 cmp r10, #0 */
/* @0x2c0ed4 ldrh r9, [r3, #112] */
/* @0x2c0ed8 movne r6, r5 */
/* @0x2c0edc movne r7, r5 */
/* @0x2c0ee0 bne 0x2c0bc0 <jpeg_idct_4x4+0x9c> */
/* @0x2c0ee4 cmp r8, #0 */
/* @0x2c0ee8 bne 0x2c0f80 <jpeg_idct_4x4+0x45c> */
/* @0x2c0eec cmp r9, #0 */
/* @0x2c0ef0 bne 0x2c0f90 <jpeg_idct_4x4+0x46c> */
/* @0x2c0ef4 ldrsh r5, [r4, #-2] */
/* @0x2c0ef8 ldr r6, [r12, #-0x4] */
/* @0x2c0efc mul r5, r6, r5 */
/* @0x2c0f00 lsl r5, r5, #2 */
/* @0x2c0f04 str r5, [r0] */
/* @0x2c0f08 str r5, [r0, #0x20] */
/* @0x2c0f0c str r5, [r0, #0x40] */
/* @0x2c0f10 str r5, [r0, #0x60] */
/* @0x2c0f14 b 0x2c0cd0 <jpeg_idct_4x4+0x1ac> */
/* @0x2c0f18 ldr r5, [r3, #0x14] */
/* @0x2c0f1c cmp r5, #0 */
/* @0x2c0f20 bne 0x2c0f6c <jpeg_idct_4x4+0x448> */
/* @0x2c0f24 ldr r8, [r3, #0x18] */
/* @0x2c0f28 ldr r7, [r3, #0x1c] */
/* @0x2c0f2c cmp r8, #0 */
/* @0x2c0f30 str r8, [sp, #0x20] */
/* @0x2c0f34 movne r4, r5 */
/* @0x2c0f38 movne r8, r5 */
/* @0x2c0f3c bne 0x2c0da4 <jpeg_idct_4x4+0x280> */
/* @0x2c0f40 cmp r7, #0 */
/* @0x2c0f44 bne 0x2c0fa4 <jpeg_idct_4x4+0x480> */
/* @0x2c0f48 ldr r0, [r3], #32 */
/* @0x2c0f4c add r0, r0, #16 */
/* @0x2c0f50 ubfx r0, r0, #0x5, #0xa */
/* @0x2c0f54 ldrb r0, [r12, r0] */
/* @0x2c0f58 strb r0, [r6, r10] */
/* @0x2c0f5c strb r0, [r1, #0x1] */
/* @0x2c0f60 strb r0, [r1, #0x2] */
/* @0x2c0f64 strb r0, [r1, #0x3] */
/* @0x2c0f68 b 0x2c0e78 <jpeg_idct_4x4+0x354> */
/* @0x2c0f6c ldr r7, [r3, #0x18] */
/* @0x2c0f70 mov r8, r4 */
/* @0x2c0f74 str r7, [sp, #0x20] */
/* @0x2c0f78 ldr r7, [r3, #0x1c] */
/* @0x2c0f7c b 0x2c0da4 <jpeg_idct_4x4+0x280> */
/* @0x2c0f80 mov r6, r5 */
/* @0x2c0f84 mov r10, r5 */
/* @0x2c0f88 mov r7, r5 */
/* @0x2c0f8c b 0x2c0bc0 <jpeg_idct_4x4+0x9c> */
/* @0x2c0f90 mov r6, r5 */
/* @0x2c0f94 mov r10, r5 */
/* @0x2c0f98 mov r8, r5 */
/* @0x2c0f9c mov r7, r5 */
/* @0x2c0fa0 b 0x2c0bc0 <jpeg_idct_4x4+0x9c> */
/* @0x2c0fa4 ldr r4, [sp, #0x20] */
/* @0x2c0fa8 mov r5, r4 */
/* @0x2c0fac mov r8, r4 */
/* @0x2c0fb0 b 0x2c0da4 <jpeg_idct_4x4+0x280> */

/* ── FUNC 0x2c0fb4 · jpeg_idct_2x2 · size=652 · insn=163 */
/* @0x2c0fb4 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2c0fb8 sub sp, sp, #88 */
/* @0x2c0fbc add r6, sp, #24 */
/* @0x2c0fc0 ldr r1, [r1, #0x50] */
/* @0x2c0fc4 ldr r0, [r0, #0x120] */
/* @0x2c0fc8 movw r11, #0xe8ee */
/* @0x2c0fcc str r3, [sp, #0x10] */
/* @0x2c0fd0 movw r7, #0xd746 */
/* @0x2c0fd4 add r0, r0, #128 */
/* @0x2c0fd8 movt r11, #0xffff */
/* @0x2c0fdc str r0, [sp, #0x8] */
/* @0x2c0fe0 movt r7, #0xffff */
/* @0x2c0fe4 str r6, [sp, #0x14] */
/* @0x2c0fe8 add r5, r2, #2 */
/* @0x2c0fec add r4, r1, #4 */
/* @0x2c0ff0 mov r12, r6 */
/* @0x2c0ff4 str r7, [sp, #0xc] */
/* @0x2c0ff8 mov r0, #7 */
/* @0x2c0ffc mov r3, #8 */
/* @0x2c1000 str r11, [sp, #0x4] */
/* @0x2c1004 b 0x2c10c0 <jpeg_idct_2x2+0x10c> */
/* @0x2c1008 ldrh r6, [r2, #48] */
/* @0x2c100c cmp r6, #0 */
/* @0x2c1010 beq 0x2c11b8 <jpeg_idct_2x2+0x204> */
/* @0x2c1014 ldrh r10, [r2, #112] */
/* @0x2c1018 ldrh r9, [r2, #80] */
/* @0x2c101c ldr r7, [r1, #0xa0] */
/* @0x2c1020 sxth r9, r9 */
/* @0x2c1024 ldr r11, [r1, #0xe0] */
/* @0x2c1028 sxth r10, r10 */
/* @0x2c102c sxth r6, r6 */
/* @0x2c1030 sxth r8, r8 */
/* @0x2c1034 mul r9, r7, r9 */
/* @0x2c1038 ldrsh r7, [r5, #-2] */
/* @0x2c103c mul r10, r11, r10 */
/* @0x2c1040 ldr r11, [r1, #0x60] */
/* @0x2c1044 mul r6, r11, r6 */
/* @0x2c1048 movw r11, #0x1b37 */
/* @0x2c104c mul r9, r11, r9 */
/* @0x2c1050 ldr r11, [sp, #0x4] */
/* @0x2c1054 mla r9, r11, r10, r9 */
/* @0x2c1058 ldr r10, [r4, #-0x4] */
/* @0x2c105c ldr r11, [r1, #0x20] */
/* @0x2c1060 mul r7, r10, r7 */
/* @0x2c1064 ldr r10, [sp, #0xc] */
/* @0x2c1068 mul r8, r11, r8 */
/* @0x2c106c movw r11, #0x73fc */
/* @0x2c1070 mla r9, r10, r6, r9 */
/* @0x2c1074 lsl r7, r7, #15 */
/* @0x2c1078 mla r8, r11, r8, r9 */
/* @0x2c107c add r6, r7, r8 */
/* @0x2c1080 rsb r8, r8, r7 */
/* @0x2c1084 add r6, r6, #4096 */
/* @0x2c1088 add r8, r8, #4096 */
/* @0x2c108c asr r6, r6, #13 */
/* @0x2c1090 asr r8, r8, #13 */
/* @0x2c1094 str r6, [r12] */
/* @0x2c1098 str r8, [r12, #0x20] */
/* @0x2c109c cmp r0, #0 */
/* @0x2c10a0 add r12, r12, #4 */
/* @0x2c10a4 beq 0x2c10f8 <jpeg_idct_2x2+0x144> */
/* @0x2c10a8 sub r3, r3, #1 */
/* @0x2c10ac add r5, r5, #2 */
/* @0x2c10b0 add r2, r2, #2 */
/* @0x2c10b4 add r4, r4, #4 */
/* @0x2c10b8 add r1, r1, #4 */
/* @0x2c10bc sub r0, r0, #1 */
/* @0x2c10c0 bic r6, r3, #2 */
/* @0x2c10c4 cmp r6, #4 */
/* @0x2c10c8 beq 0x2c109c <jpeg_idct_2x2+0xe8> */
/* @0x2c10cc cmp r3, #2 */
/* @0x2c10d0 beq 0x2c10f0 <jpeg_idct_2x2+0x13c> */
/* @0x2c10d4 ldrh r8, [r2, #16] */
/* @0x2c10d8 cmp r8, #0 */
/* @0x2c10dc beq 0x2c1008 <jpeg_idct_2x2+0x54> */
/* @0x2c10e0 ldrh r10, [r2, #112] */
/* @0x2c10e4 ldrh r9, [r2, #80] */
/* @0x2c10e8 ldrh r6, [r2, #48] */
/* @0x2c10ec b 0x2c101c <jpeg_idct_2x2+0x68> */
/* @0x2c10f0 add r12, r12, #4 */
/* @0x2c10f4 b 0x2c10a8 <jpeg_idct_2x2+0xf4> */
/* @0x2c10f8 movw r7, #0xe8ee */
/* @0x2c10fc movw r6, #0xd746 */
/* @0x2c1100 movt r7, #0xffff */
/* @0x2c1104 movt r6, #0xffff */
/* @0x2c1108 add r3, sp, #24 */
/* @0x2c110c movw r11, #0x1b37 */
/* @0x2c1110 movw r10, #0x73fc */
/* @0x2c1114 ldr r12, [sp, #0x10] */
/* @0x2c1118 ldr r1, [r3, #0x4] */
/* @0x2c111c ldr r2, [r12, r0] */
/* @0x2c1120 cmp r1, #0 */
/* @0x2c1124 ldr r12, [sp, #0x78] */
/* @0x2c1128 add r5, r2, r12 */
/* @0x2c112c bne 0x2c11a8 <jpeg_idct_2x2+0x1f4> */
/* @0x2c1130 ldr r12, [r3, #0xc] */
/* @0x2c1134 cmp r12, #0 */
/* @0x2c1138 beq 0x2c11f0 <jpeg_idct_2x2+0x23c> */
/* @0x2c113c ldr r4, [r3, #0x1c] */
/* @0x2c1140 ldr r9, [r3, #0x14] */
/* @0x2c1144 mul r9, r11, r9 */
/* @0x2c1148 ldr r8, [r3], #32 */
/* @0x2c114c mla r4, r7, r4, r9 */
/* @0x2c1150 lsl r8, r8, #15 */
/* @0x2c1154 mla r4, r6, r12, r4 */
/* @0x2c1158 ldr r12, [sp, #0x8] */
/* @0x2c115c mla r1, r10, r1, r4 */
/* @0x2c1160 add r9, r8, r1 */
/* @0x2c1164 rsb r8, r1, r8 */
/* @0x2c1168 add r9, r9, #524288 */
/* @0x2c116c add r8, r8, #524288 */
/* @0x2c1170 ubfx r9, r9, #0x14, #0xa */
/* @0x2c1174 ubfx r8, r8, #0x14, #0xa */
/* @0x2c1178 ldrb r1, [r12, r9] */
/* @0x2c117c ldr r12, [sp, #0x78] */
/* @0x2c1180 strb r1, [r2, r12] */
/* @0x2c1184 ldr r1, [sp, #0x8] */
/* @0x2c1188 ldrb r2, [r1, r8] */
/* @0x2c118c strb r2, [r5, #0x1] */
/* @0x2c1190 add r0, r0, #4 */
/* @0x2c1194 cmp r0, #8 */
/* @0x2c1198 bne 0x2c1114 <jpeg_idct_2x2+0x160> */
/* @0x2c119c add sp, sp, #88 */
/* @0x2c11a0 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2c11a4 bx lr */
/* @0x2c11a8 ldr r4, [r3, #0x1c] */
/* @0x2c11ac ldr r9, [r3, #0x14] */
/* @0x2c11b0 ldr r12, [r3, #0xc] */
/* @0x2c11b4 b 0x2c1144 <jpeg_idct_2x2+0x190> */
/* @0x2c11b8 ldrh r9, [r2, #80] */
/* @0x2c11bc ldrh r10, [r2, #112] */
/* @0x2c11c0 cmp r9, #0 */
/* @0x2c11c4 movne r6, r8 */
/* @0x2c11c8 bne 0x2c101c <jpeg_idct_2x2+0x68> */
/* @0x2c11cc cmp r10, #0 */
/* @0x2c11d0 bne 0x2c122c <jpeg_idct_2x2+0x278> */
/* @0x2c11d4 ldrsh r6, [r5, #-2] */
/* @0x2c11d8 ldr r7, [r4, #-0x4] */
/* @0x2c11dc mul r6, r7, r6 */
/* @0x2c11e0 lsl r6, r6, #2 */
/* @0x2c11e4 str r6, [r12] */
/* @0x2c11e8 str r6, [r12, #0x20] */
/* @0x2c11ec b 0x2c109c <jpeg_idct_2x2+0xe8> */
/* @0x2c11f0 ldr r9, [r3, #0x14] */
/* @0x2c11f4 ldr r4, [r3, #0x1c] */
/* @0x2c11f8 cmp r9, #0 */
/* @0x2c11fc bne 0x2c1144 <jpeg_idct_2x2+0x190> */
/* @0x2c1200 cmp r4, #0 */
/* @0x2c1204 bne 0x2c1238 <jpeg_idct_2x2+0x284> */
/* @0x2c1208 ldr r1, [r3], #32 */
/* @0x2c120c ldr r12, [sp, #0x8] */
/* @0x2c1210 add r1, r1, #16 */
/* @0x2c1214 ubfx r1, r1, #0x5, #0xa */
/* @0x2c1218 ldrb r1, [r12, r1] */
/* @0x2c121c ldr r12, [sp, #0x78] */
/* @0x2c1220 strb r1, [r2, r12] */
/* @0x2c1224 strb r1, [r5, #0x1] */
/* @0x2c1228 b 0x2c1190 <jpeg_idct_2x2+0x1dc> */
/* @0x2c122c mov r6, r8 */
/* @0x2c1230 mov r9, r8 */
/* @0x2c1234 b 0x2c101c <jpeg_idct_2x2+0x68> */
/* @0x2c1238 mov r12, r9 */
/* @0x2c123c b 0x2c1144 <jpeg_idct_2x2+0x190> */

/* ── FUNC 0x2c1240 · jpeg_idct_1x1 · size=52 · insn=13 */
/* @0x2c1240 ldr r1, [r1, #0x50] */
/* @0x2c1244 ldrsh r2, [r2] */
/* @0x2c1248 ldr r0, [r0, #0x120] */
/* @0x2c124c ldr r1, [r1] */
/* @0x2c1250 ldr r12, [r3] */
/* @0x2c1254 ldr r3, [sp] */
/* @0x2c1258 mul r2, r1, r2 */
/* @0x2c125c add r2, r2, #4 */
/* @0x2c1260 ubfx r2, r2, #0x3, #0xa */
/* @0x2c1264 add r0, r0, r2 */
/* @0x2c1268 ldrb r2, [r0, #0x80] */
/* @0x2c126c strb r2, [r12, r3] */
/* @0x2c1270 bx lr */

/* ── FUNC 0x2c1274 · anon_2c1274 · size=264 · insn=66 */
/* @0x2c1274 ldr r0, [r1, #0xc] */
/* @0x2c1278 b 0xb6850 <fclose@plt> */
/* @0x2c127c push {r3, r4, r5, r6, r7, lr} */
/* @0x2c1280 mov r5, r1 */
/* @0x2c1284 mov r6, r0 */
/* @0x2c1288 mov r7, r2 */
/* @0x2c128c mov r1, r3 */
/* @0x2c1290 ldr r0, [r5, #0xc] */
/* @0x2c1294 mov r2, #0 */
/* @0x2c1298 ldr r4, [sp, #0x18] */
/* @0x2c129c bl 0xb68d4 <fseek@plt> */
/* @0x2c12a0 cmp r0, #0 */
/* @0x2c12a4 bne 0x2c12e0 <jpeg_idct_1x1+0xa0> */
/* @0x2c12a8 mov r0, r7 */
/* @0x2c12ac ldr r3, [r5, #0xc] */
/* @0x2c12b0 mov r1, #1 */
/* @0x2c12b4 mov r2, r4 */
/* @0x2c12b8 bl 0xb68bc <fwrite@plt> */
/* @0x2c12bc cmp r4, r0 */
/* @0x2c12c0 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x2c12c4 ldr r3, [r6] */
/* @0x2c12c8 mov r1, #66 */
/* @0x2c12cc mov r0, r6 */
/* @0x2c12d0 ldr r2, [r3] */
/* @0x2c12d4 str r1, [r3, #0x14] */
/* @0x2c12d8 blx r2 */
/* @0x2c12dc pop {r3, r4, r5, r6, r7, pc} */
/* @0x2c12e0 ldr r3, [r6] */
/* @0x2c12e4 mov r2, #65 */
/* @0x2c12e8 mov r0, r6 */
/* @0x2c12ec str r2, [r3, #0x14] */
/* @0x2c12f0 ldr r3, [r3] */
/* @0x2c12f4 blx r3 */
/* @0x2c12f8 b 0x2c12a8 <jpeg_idct_1x1+0x68> */
/* @0x2c12fc push {r3, r4, r5, r6, r7, lr} */
/* @0x2c1300 mov r5, r1 */
/* @0x2c1304 mov r6, r0 */
/* @0x2c1308 mov r7, r2 */
/* @0x2c130c mov r1, r3 */
/* @0x2c1310 ldr r0, [r5, #0xc] */
/* @0x2c1314 mov r2, #0 */
/* @0x2c1318 ldr r4, [sp, #0x18] */
/* @0x2c131c bl 0xb68d4 <fseek@plt> */
/* @0x2c1320 cmp r0, #0 */
/* @0x2c1324 bne 0x2c1360 <jpeg_idct_1x1+0x120> */
/* @0x2c1328 mov r0, r7 */
/* @0x2c132c ldr r3, [r5, #0xc] */
/* @0x2c1330 mov r1, #1 */
/* @0x2c1334 mov r2, r4 */
/* @0x2c1338 bl 0xb68c8 <fread@plt> */
/* @0x2c133c cmp r4, r0 */
/* @0x2c1340 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x2c1344 ldr r3, [r6] */
/* @0x2c1348 mov r1, #64 */
/* @0x2c134c mov r0, r6 */
/* @0x2c1350 ldr r2, [r3] */
/* @0x2c1354 str r1, [r3, #0x14] */
/* @0x2c1358 blx r2 */
/* @0x2c135c pop {r3, r4, r5, r6, r7, pc} */
/* @0x2c1360 ldr r3, [r6] */
/* @0x2c1364 mov r2, #65 */
/* @0x2c1368 mov r0, r6 */
/* @0x2c136c str r2, [r3, #0x14] */
/* @0x2c1370 ldr r3, [r3] */
/* @0x2c1374 blx r3 */
/* @0x2c1378 b 0x2c1328 <jpeg_idct_1x1+0xe8> */

/* ── FUNC 0x2c137c · jpeg_get_small · size=8 · insn=2 */
/* @0x2c137c mov r0, r1 */
/* @0x2c1380 b 0xb6544 <malloc@plt> */

/* ── FUNC 0x2c1384 · jpeg_free_small · size=8 · insn=2 */
/* @0x2c1384 mov r0, r1 */
/* @0x2c1388 b 0xb655c <free@plt> */

/* ── FUNC 0x2c138c · jpeg_get_large · size=8 · insn=2 */
/* @0x2c138c mov r0, r1 */
/* @0x2c1390 b 0xb6544 <malloc@plt> */

/* ── FUNC 0x2c1394 · jpeg_free_large · size=8 · insn=2 */
/* @0x2c1394 mov r0, r1 */
/* @0x2c1398 b 0xb655c <free@plt> */
