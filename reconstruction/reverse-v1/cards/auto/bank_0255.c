/* libyoyo.so 覆盖卡组 0255
 * 函数 0x2a77e0..0x2a8ebe，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2a77e0 · png_read_rows · size=96 · insn=42 */
/* @0x2a77e0 push.w {r4, r5, r6, r7, r8, lr} */
/* @0x2a77e4 mov r7, r1 */
/* @0x2a77e6 mov r4, r2 */
/* @0x2a77e8 mov r8, r3 */
/* @0x2a77ea mov r6, r0 */
/* @0x2a77ec cbz r0, 0x2a783c <png_read_rows+0x5c> */
/* @0x2a77ee cbz r1, 0x2a7826 <png_read_rows+0x46> */
/* @0x2a77f0 cbz r2, 0x2a780e <png_read_rows+0x2e> */
/* @0x2a77f2 movs r5, #0x0 */
/* @0x2a77f4 cmp r5, r8 */
/* @0x2a77f6 beq 0x2a780a <png_read_rows+0x2a> */
/* @0x2a77f8 ldr.w r1, [r7, r5, lsl #2] */
/* @0x2a77fc mov r0, r6 */
/* @0x2a77fe ldr.w r2, [r4, r5, lsl #2] */
/* @0x2a7800 strlo r2, [r1, #-0x25] */
/* @0x2a7802 adds r5, #0x1 */
/* @0x2a7804 bl 0x2a7488 <png_read_row> */
/* @0x2a7808 b 0x2a77f4 <png_read_rows+0x14> */
/* @0x2a780a pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2a780c strbmi r8, [r4, #-0x1f0] */
/* @0x2a780e cmp r4, r8 */
/* @0x2a7810 beq 0x2a7822 <png_read_rows+0x42> */
/* @0x2a7812 ldr.w r1, [r7, r4, lsl #2] */
/* @0x2a7814 ldrtmi r1, [r0], -r4, lsr #32 */
/* @0x2a7816 mov r0, r6 */
/* @0x2a7818 movs r2, #0x0 */
/* @0x2a781a adds r4, #0x1 */
/* @0x2a781c bl 0x2a7488 <png_read_row> */
/* @0x2a7820 b 0x2a780e <png_read_rows+0x2e> */
/* @0x2a7822 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2a7824 strdlt r8, r9, [r10, #-16] */
/* @0x2a7826 cbz r2, 0x2a783c <png_read_rows+0x5c> */
/* @0x2a7828 cmp r7, r8 */
/* @0x2a782a beq 0x2a783c <png_read_rows+0x5c> */
/* @0x2a782c ldr.w r2, [r4, r7, lsl #2] */
/* @0x2a7830 mov r0, r6 */
/* @0x2a7832 movs r1, #0x0 */
/* @0x2a7834 adds r7, #0x1 */
/* @0x2a7836 bl 0x2a7488 <png_read_row> */
/* @0x2a7838 ldrb pc, [r5, r7, lsr #28]! */
/* @0x2a783a b 0x2a7828 <png_read_rows+0x48> */
/* @0x2a783c pop.w {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2a7840 · png_read_image · size=60 · insn=26 */
/* @0x2a7840 push.w {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2a7844 mov r8, r1 */
/* @0x2a7846 mov r5, r0 */
/* @0x2a7848 cbz r0, 0x2a7878 <png_read_image+0x38> */
/* @0x2a784a bl 0x2af7b2 <png_set_interlace_handling> */
/* @0x2a784c .word 0xf8d5ffb2 */
/* @0x2a784e ldr.w r7, [r5, #0x190] */
/* @0x2a7850 .word 0x26007190 */
/* @0x2a7852 movs r6, #0x0 */
/* @0x2a7854 str.w r7, [r5, #0x194] */
/* @0x2a7858 mov r9, r0 */
/* @0x2a785a cmp r6, r9 */
/* @0x2a785c bge 0x2a7878 <png_read_image+0x38> */
/* @0x2a785e movs r4, #0x0 */
/* @0x2a7860 cmp r4, r7 */
/* @0x2a7862 beq 0x2a7874 <png_read_image+0x34> */
/* @0x2a7864 ldr.w r1, [r8, r4, lsl #2] */
/* @0x2a7868 mov r0, r5 */
/* @0x2a786a movs r2, #0x0 */
/* @0x2a786c adds r4, #0x1 */
/* @0x2a786e bl 0x2a7488 <png_read_row> */
/* @0x2a7870 ldrb pc, [r5, r11, lsl #28]! */
/* @0x2a7872 b 0x2a7860 <png_read_image+0x20> */
/* @0x2a7874 adds r6, #0x1 */
/* @0x2a7876 b 0x2a785a <png_read_image+0x1a> */
/* @0x2a7878 pop.w {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x2a787c · png_read_end · size=1000 · insn=459 */
/* @0x2a787c push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a7880 mov r7, r1 */
/* @0x2a7882 sub sp, #0xb4 */
/* @0x2a7884 mov r4, r0 */
/* @0x2a7886 cmp r0, #0x0 */
/* @0x2a7888 beq.w 0x2a7c50 <png_read_end+0x3d4> */
/* @0x2a788c ldr.w r8, [pc, #0x3c8] */
/* @0x2a7890 movs r1, #0x0 */
/* @0x2a7892 bl 0x2abc94 <png_crc_finish> */
/* @0x2a7894 .word 0xf10df9ff */
/* @0x2a7896 add.w r9, sp, #0x8 */
/* @0x2a7898 ldrbtmi r0, [r8], #2312 */
/* @0x2a789a add r8, pc */
/* @0x2a789c ldrb.w r3, [r8, #0x4] */
/* @0x2a78a0 strb.w r3, [sp, #0x7] */
/* @0x2a78a4 ldrb.w r3, [sp, #0x7] */
/* @0x2a78a8 add.w r6, r4, #0x1e0 */
/* @0x2a78ac ldr.w r0, [r8] */
/* @0x2a78b0 add.w r11, sp, #0x10 */
/* @0x2a78b4 add.w r10, sp, #0x20 */
/* @0x2a78b8 strb.w r3, [r9, #0x4] */
/* @0x2a78bc mov r3, r8 */
/* @0x2a78be str.w r0, [r9] */
/* @0x2a78c0 .word 0xf8530000 */
/* @0x2a78c2 ldr r0, [r3, #5]! */
/* @0x2a78c4 ldmdbvc r11, {r0, r2, r8, r9, r10, r11} */
/* @0x2a78c6 ldrb r3, [r3, #0x4] */
/* @0x2a78c8 str r0, [sp, #0x10] */
/* @0x2a78ca strb.w r3, [sp, #0x14] */
/* @0x2a78cc .word 0x46433014 */
/* @0x2a78ce mov r3, r8 */
/* @0x2a78d0 ldr r0, [r3, #10]! */
/* @0x2a78d4 ldrb r3, [r3, #0x4] */
/* @0x2a78d6 str r0, [sp, #0x18] */
/* @0x2a78d8 strb.w r3, [sp, #0x1c] */
/* @0x2a78dc mov r3, r8 */
/* @0x2a78de ldr r0, [r3, #15]! */
/* @0x2a78e0 ldmdbvc r11, {r0, r1, r2, r3, r8, r9, r10, r11} */
/* @0x2a78e2 ldrb r3, [r3, #0x4] */
/* @0x2a78e4 str r0, [sp, #0x20] */
/* @0x2a78e6 strb.w r3, [sp, #0x24] */
/* @0x2a78e8 strbmi r3, [r3], -r4, lsr #32 */
/* @0x2a78ea mov r3, r8 */
/* @0x2a78ec ldr r0, [r3, #20]! */
/* @0x2a78f0 ldrb r3, [r3, #0x4] */
/* @0x2a78f2 str r0, [sp, #0x28] */
/* @0x2a78f4 strb.w r3, [sp, #0x2c] */
/* @0x2a78f8 mov r3, r8 */
/* @0x2a78fa ldr r0, [r3, #25]! */
/* @0x2a78fc ldmdbvc r11, {r0, r3, r4, r8, r9, r10, r11} */
/* @0x2a78fe ldrb r3, [r3, #0x4] */
/* @0x2a7900 str r0, [sp, #0x30] */
/* @0x2a7902 strb.w r3, [sp, #0x34] */
/* @0x2a7904 .word 0x46433034 */
/* @0x2a7906 mov r3, r8 */
/* @0x2a7908 ldr r0, [r3, #30]! */
/* @0x2a790c ldrb r3, [r3, #0x4] */
/* @0x2a790e str r0, [sp, #0x38] */
/* @0x2a7910 strb.w r3, [sp, #0x3c] */
/* @0x2a7914 mov r3, r8 */
/* @0x2a7916 ldr r0, [r3, #35]! */
/* @0x2a7918 ldmdbvc r11, {r0, r1, r5, r8, r9, r10, r11} */
/* @0x2a791a ldrb r3, [r3, #0x4] */
/* @0x2a791c str r0, [sp, #0x40] */
/* @0x2a791e strb.w r3, [sp, #0x44] */
/* @0x2a7920 strbmi r3, [r3], -r4, asr #32 */
/* @0x2a7922 mov r3, r8 */
/* @0x2a7924 ldr r0, [r3, #40]! */
/* @0x2a7928 str r0, [sp, #0x48] */
/* @0x2a792a ldrb r3, [r3, #0x4] */
/* @0x2a792c strb.w r3, [sp, #0x4c] */
/* @0x2a7930 mov r3, r8 */
/* @0x2a7932 ldr r0, [r3, #45]! */
/* @0x2a7934 ldmdbvc r11, {r0, r2, r3, r5, r8, r9, r10, r11} */
/* @0x2a7936 ldrb r3, [r3, #0x4] */
/* @0x2a7938 str r0, [sp, #0x50] */
/* @0x2a793a strb.w r3, [sp, #0x54] */
/* @0x2a793c .word 0x46433054 */
/* @0x2a793e mov r3, r8 */
/* @0x2a7940 ldr r0, [r3, #50]! */
/* @0x2a7944 ldrb r3, [r3, #0x4] */
/* @0x2a7946 str r0, [sp, #0x58] */
/* @0x2a7948 strb.w r3, [sp, #0x5c] */
/* @0x2a794c mov r3, r8 */
/* @0x2a794e ldr r0, [r3, #55]! */
/* @0x2a7950 ldmdbvc r11, {r0, r1, r2, r4, r5, r8, r9, r10, r11} */
/* @0x2a7952 ldrb r3, [r3, #0x4] */
/* @0x2a7954 str r0, [sp, #0x60] */
/* @0x2a7956 strb.w r3, [sp, #0x64] */
/* @0x2a7958 strbmi r3, [r3], -r4, rrx */
/* @0x2a795a mov r3, r8 */
/* @0x2a795c ldr r0, [r3, #60]! */
/* @0x2a7960 ldrb r3, [r3, #0x4] */
/* @0x2a7962 str r0, [sp, #0x68] */
/* @0x2a7964 strb.w r3, [sp, #0x6c] */
/* @0x2a7968 mov r3, r8 */
/* @0x2a796a ldr r0, [r3, #65]! */
/* @0x2a796c ldmdbvc r11, {r0, r6, r8, r9, r10, r11} */
/* @0x2a796e ldrb r3, [r3, #0x4] */
/* @0x2a7970 str r0, [sp, #0x70] */
/* @0x2a7972 strb.w r3, [sp, #0x74] */
/* @0x2a7974 .word 0x46433074 */
/* @0x2a7976 mov r3, r8 */
/* @0x2a7978 ldr r0, [r3, #70]! */
/* @0x2a797c ldrb r3, [r3, #0x4] */
/* @0x2a797e str r0, [sp, #0x78] */
/* @0x2a7980 strb.w r3, [sp, #0x7c] */
/* @0x2a7984 mov r3, r8 */
/* @0x2a7986 ldr r0, [r3, #75]! */
/* @0x2a7988 ldmdbvc r11, {r0, r1, r3, r6, r8, r9, r10, r11} */
/* @0x2a798a ldrb r3, [r3, #0x4] */
/* @0x2a798c str r0, [sp, #0x80] */
/* @0x2a798e strb.w r3, [sp, #0x84] */
/* @0x2a7990 strbmi r3, [r3], -r4, lsl #1 */
/* @0x2a7992 mov r3, r8 */
/* @0x2a7994 ldr r0, [r3, #80]! */
/* @0x2a7998 ldrb r3, [r3, #0x4] */
/* @0x2a799a str r0, [sp, #0x88] */
/* @0x2a799c strb.w r3, [sp, #0x8c] */
/* @0x2a79a0 mov r3, r8 */
/* @0x2a79a2 ldr r0, [r3, #85]! */
/* @0x2a79a4 ldmdbvc r11, {r0, r2, r4, r6, r8, r9, r10, r11} */
/* @0x2a79a6 ldrb r3, [r3, #0x4] */
/* @0x2a79a8 str r0, [sp, #0x90] */
/* @0x2a79aa strb.w r3, [sp, #0x94] */
/* @0x2a79ac .word 0x46433094 */
/* @0x2a79ae mov r3, r8 */
/* @0x2a79b0 ldr r0, [r3, #90]! */
/* @0x2a79b4 ldrb r3, [r3, #0x4] */
/* @0x2a79b6 str r0, [sp, #0x98] */
/* @0x2a79b8 strb.w r3, [sp, #0x9c] */
/* @0x2a79bc mov r3, r8 */
/* @0x2a79be ldr r0, [r3, #95]! */
/* @0x2a79c0 ldmdbvc r11, {r0, r1, r2, r3, r4, r6, r8, r9, r10, r11} */
/* @0x2a79c2 ldrb r3, [r3, #0x4] */
/* @0x2a79c4 str r0, [sp, #0xa0] */
/* @0x2a79c6 strb.w r3, [sp, #0xa4] */
/* @0x2a79c8 strbmi r3, [r3], -r4, lsr #1 */
/* @0x2a79ca mov r3, r8 */
/* @0x2a79cc ldr r0, [r3, #100]! */
/* @0x2a79d0 ldrb r3, [r3, #0x4] */
/* @0x2a79d2 str r0, [sp, #0xa8] */
/* @0x2a79d4 mov r0, r4 */
/* @0x2a79d6 strb.w r3, [sp, #0xac] */
/* @0x2a79d8 .word 0xf00630ac */
/* @0x2a79da bl 0x2adbc4 <png_read_chunk_header> */
/* @0x2a79dc .word 0x4649f8f3 */
/* @0x2a79de mov r1, r9 */
/* @0x2a79e0 movs r2, #0x4 */
/* @0x2a79e2 mov r5, r0 */
/* @0x2a79e4 mov r0, r6 */
/* @0x2a79e6 blx 0xb6c40 <memcmp@plt> */
/* @0x2a79e8 stmdblt r8!, {r2, r3, r5, r8, r11, sp, lr, pc} */
/* @0x2a79ea cbnz r0, 0x2a79f8 <png_read_end+0x17c> */
/* @0x2a79ec mov r0, r4 */
/* @0x2a79ee mov r1, r7 */
/* @0x2a79f0 mov r2, r5 */
/* @0x2a79f2 bl 0x2abe50 <png_handle_IHDR> */
/* @0x2a79f4 .word 0xe126fa2d */
/* @0x2a79f6 b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a79f8 mov r0, r6 */
/* @0x2a79fa add r1, sp, #0x18 */
/* @0x2a79fc movs r2, #0x4 */
/* @0x2a79fe blx 0xb6c40 <memcmp@plt> */
/* @0x2a7a00 stmdblt r8!, {r5, r8, r11, sp, lr, pc} */
/* @0x2a7a02 cbnz r0, 0x2a7a10 <png_read_end+0x194> */
/* @0x2a7a04 mov r0, r4 */
/* @0x2a7a06 mov r1, r7 */
/* @0x2a7a08 mov r2, r5 */
/* @0x2a7a0a bl 0x2ac0c8 <png_handle_IEND> */
/* @0x2a7a0c tst r10, sp, asr r11 */
/* @0x2a7a0e b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7a10 mov r0, r4 */
/* @0x2a7a12 mov r1, r6 */
/* @0x2a7a14 bl 0x2a5fe4 <png_handle_as_unknown> */
/* @0x2a7a18 cbz r0, 0x2a7a62 <png_read_end+0x1e6> */
/* @0x2a7a1a mov r0, r6 */
/* @0x2a7a1c mov r1, r11 */
/* @0x2a7a1e movs r2, #0x4 */
/* @0x2a7a20 blx 0xb6c40 <memcmp@plt> */
/* @0x2a7a24 cbnz r0, 0x2a7a3a <png_read_end+0x1be> */
/* @0x2a7a26 cbnz r5, 0x2a7a30 <png_read_end+0x1b4> */
/* @0x2a7a28 ldr.w r3, [r4, #0x12c] */
/* @0x2a7a2c lsls r1, r3, #0x12 */
/* @0x2a7a2e bpl 0x2a7a3a <png_read_end+0x1be> */
/* @0x2a7a30 ldr r1, [pc, #0x228] */
/* @0x2a7a32 mov r0, r4 */
/* @0x2a7a34 add r1, pc */
/* @0x2a7a36 bl 0x2a642c <png_error> */
/* @0x2a7a38 qsub8mi pc, r0, r9 */
/* @0x2a7a3a mov r0, r4 */
/* @0x2a7a3c mov r1, r7 */
/* @0x2a7a3e mov r2, r5 */
/* @0x2a7a40 bl 0x2ada34 <png_handle_unknown> */
/* @0x2a7a44 mov r0, r6 */
/* @0x2a7a46 mov r1, r10 */
/* @0x2a7a48 movs r2, #0x4 */
/* @0x2a7a4a blx 0xb6c40 <memcmp@plt> */
/* @0x2a7a4c stmdahs r0, {r1, r3, r4, r5, r6, r7, r11, sp, lr, pc} */
/* @0x2a7a4e cmp r0, #0x0 */
/* @0x2a7a50 bne.w 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7a54 ldr.w r3, [r4, #0x12c] */
/* @0x2a7a58 orr r3, r3, #0x2 */
/* @0x2a7a5c str.w r3, [r4, #0x12c] */
/* @0x2a7a60 b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7a62 mov r0, r6 */
/* @0x2a7a64 mov r1, r11 */
/* @0x2a7a66 movs r2, #0x4 */
/* @0x2a7a68 blx 0xb6c40 <memcmp@plt> */
/* @0x2a7a6c cbnz r0, 0x2a7a8c <png_read_end+0x210> */
/* @0x2a7a6e cbnz r5, 0x2a7a78 <png_read_end+0x1fc> */
/* @0x2a7a70 ldr.w r3, [r4, #0x12c] */
/* @0x2a7a74 lsls r2, r3, #0x12 */
/* @0x2a7a76 bpl 0x2a7a82 <png_read_end+0x206> */
/* @0x2a7a78 ldr r1, [pc, #0x1e4] */
/* @0x2a7a7a mov r0, r4 */
/* @0x2a7a7c add r1, pc */
/* @0x2a7a7e bl 0x2a642c <png_error> */
/* @0x2a7a80 .word 0x4620fcd5 */
/* @0x2a7a82 mov r0, r4 */
/* @0x2a7a84 mov r1, r5 */
/* @0x2a7a86 bl 0x2abc94 <png_crc_finish> */
/* @0x2a7a88 sbcs pc, r12, r5, lsl #18 */
/* @0x2a7a8a b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7a8c mov r0, r6 */
/* @0x2a7a8e mov r1, r10 */
/* @0x2a7a90 movs r2, #0x4 */
/* @0x2a7a92 blx 0xb6c40 <memcmp@plt> */
/* @0x2a7a94 stmdblt r8!, {r1, r2, r4, r6, r7, r11, sp, lr, pc} */
/* @0x2a7a96 cbnz r0, 0x2a7aa4 <png_read_end+0x228> */
/* @0x2a7a98 mov r0, r4 */
/* @0x2a7a9a mov r1, r7 */
/* @0x2a7a9c mov r2, r5 */
/* @0x2a7a9e bl 0x2abf64 <png_handle_PLTE> */
/* @0x2a7aa0 sbcs pc, r0, r1, ror #20 */
/* @0x2a7aa2 b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7aa4 mov r0, r6 */
/* @0x2a7aa6 add r1, sp, #0x28 */
/* @0x2a7aa8 movs r2, #0x4 */
/* @0x2a7aaa blx 0xb6c40 <memcmp@plt> */
/* @0x2a7aac stmdblt r8!, {r1, r3, r6, r7, r11, sp, lr, pc} */
/* @0x2a7aae cbnz r0, 0x2a7abc <png_read_end+0x240> */
/* @0x2a7ab0 mov r0, r4 */
/* @0x2a7ab2 mov r1, r7 */
/* @0x2a7ab4 mov r2, r5 */
/* @0x2a7ab6 bl 0x2acd60 <png_handle_bKGD> */
/* @0x2a7ab8 sbc pc, r4, r3, asr r9 */
/* @0x2a7aba b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7abc mov r0, r6 */
/* @0x2a7abe add r1, sp, #0x30 */
/* @0x2a7ac0 movs r2, #0x4 */
/* @0x2a7ac2 blx 0xb6c40 <memcmp@plt> */
/* @0x2a7ac4 stmdblt r8!, {r1, r2, r3, r4, r5, r7, r11, sp, lr, pc} */
/* @0x2a7ac6 cbnz r0, 0x2a7ad4 <png_read_end+0x258> */
/* @0x2a7ac8 mov r0, r4 */
/* @0x2a7aca mov r1, r7 */
/* @0x2a7acc mov r2, r5 */
/* @0x2a7ace bl 0x2ac328 <png_handle_cHRM> */
/* @0x2a7ad0 adcs pc, r8, r11, lsr #24 */
/* @0x2a7ad2 b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7ad4 mov r0, r6 */
/* @0x2a7ad6 add r1, sp, #0x38 */
/* @0x2a7ad8 movs r2, #0x4 */
/* @0x2a7ada blx 0xb6c40 <memcmp@plt> */
/* @0x2a7adc stmdblt r8!, {r1, r4, r5, r7, r11, sp, lr, pc} */
/* @0x2a7ade cbnz r0, 0x2a7aec <png_read_end+0x270> */
/* @0x2a7ae0 mov r0, r4 */
/* @0x2a7ae2 mov r1, r7 */
/* @0x2a7ae4 mov r2, r5 */
/* @0x2a7ae6 bl 0x2ac110 <png_handle_gAMA> */
/* @0x2a7ae8 adc pc, r12, r3, lsl r11 */
/* @0x2a7aea b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7aec mov r0, r6 */
/* @0x2a7aee add r1, sp, #0x40 */
/* @0x2a7af0 movs r2, #0x4 */
/* @0x2a7af2 blx 0xb6c40 <memcmp@plt> */
/* @0x2a7af4 stmdblt r8!, {r1, r2, r5, r7, r11, sp, lr, pc} */
/* @0x2a7af6 cbnz r0, 0x2a7b04 <png_read_end+0x288> */
/* @0x2a7af8 mov r0, r4 */
/* @0x2a7afa mov r1, r7 */
/* @0x2a7afc mov r2, r5 */
/* @0x2a7afe bl 0x2ace98 <png_handle_hIST> */
/* @0x2a7b00 adc pc, r0, r11, asr #19 */
/* @0x2a7b02 b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7b04 mov r0, r6 */
/* @0x2a7b06 add r1, sp, #0x58 */
/* @0x2a7b08 movs r2, #0x4 */
/* @0x2a7b0a blx 0xb6c40 <memcmp@plt> */
/* @0x2a7b0c stmdblt r8!, {r1, r3, r4, r7, r11, sp, lr, pc} */
/* @0x2a7b0e cbnz r0, 0x2a7b1c <png_read_end+0x2a0> */
/* @0x2a7b10 mov r0, r4 */
/* @0x2a7b12 mov r1, r7 */
/* @0x2a7b14 mov r2, r5 */
/* @0x2a7b16 bl 0x2ad030 <png_handle_oFFs> */
/* @0x2a7b18 adds pc, r4, r11, lsl #21 */
/* @0x2a7b1a b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7b1c mov r0, r6 */
/* @0x2a7b1e add r1, sp, #0x60 */
/* @0x2a7b20 movs r2, #0x4 */
/* @0x2a7b22 blx 0xb6c40 <memcmp@plt> */
/* @0x2a7b24 stmdblt r8!, {r1, r2, r3, r7, r11, sp, lr, pc} */
/* @0x2a7b26 cbnz r0, 0x2a7b34 <png_read_end+0x2b8> */
/* @0x2a7b28 mov r0, r4 */
/* @0x2a7b2a mov r1, r7 */
/* @0x2a7b2c mov r2, r5 */
/* @0x2a7b2e bl 0x2ad128 <png_handle_pCAL> */
/* @0x2a7b30 .word 0xe088fafb */
/* @0x2a7b32 b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7b34 mov r0, r6 */
/* @0x2a7b36 add r1, sp, #0x78 */
/* @0x2a7b38 movs r2, #0x4 */
/* @0x2a7b3a blx 0xb6c40 <memcmp@plt> */
/* @0x2a7b3c stmdblt r8!, {r1, r7, r11, sp, lr, pc} */
/* @0x2a7b3e cbnz r0, 0x2a7b4c <png_read_end+0x2d0> */
/* @0x2a7b40 mov r0, r4 */
/* @0x2a7b42 mov r1, r7 */
/* @0x2a7b44 mov r2, r5 */
/* @0x2a7b46 bl 0x2ad350 <png_handle_sCAL> */
/* @0x2a7b48 rsbs pc, r12, r3, lsl #24 */
/* @0x2a7b4a b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7b4c mov r0, r6 */
/* @0x2a7b4e add r1, sp, #0x68 */
/* @0x2a7b50 movs r2, #0x4 */
/* @0x2a7b52 blx 0xb6c40 <memcmp@plt> */
/* @0x2a7b54 stmdblt r8!, {r1, r2, r4, r5, r6, r11, sp, lr, pc} */
/* @0x2a7b56 cbnz r0, 0x2a7b64 <png_read_end+0x2e8> */
/* @0x2a7b58 mov r0, r4 */
/* @0x2a7b5a mov r1, r7 */
/* @0x2a7b5c mov r2, r5 */
/* @0x2a7b5e bl 0x2acf58 <png_handle_pHYs> */
/* @0x2a7b60 ldrsht pc, [r0], #-155 */
/* @0x2a7b62 b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7b64 mov r0, r6 */
/* @0x2a7b66 add r1, sp, #0x70 */
/* @0x2a7b68 movs r2, #0x4 */
/* @0x2a7b6a blx 0xb6c40 <memcmp@plt> */
/* @0x2a7b6c stmdblt r8!, {r1, r3, r5, r6, r11, sp, lr, pc} */
/* @0x2a7b6e cbnz r0, 0x2a7b7c <png_read_end+0x300> */
/* @0x2a7b70 mov r0, r4 */
/* @0x2a7b72 mov r1, r7 */
/* @0x2a7b74 mov r2, r5 */
/* @0x2a7b76 bl 0x2ac238 <png_handle_sBIT> */
/* @0x2a7b78 rsb pc, r4, pc, asr r11 */
/* @0x2a7b7a b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7b7c mov r0, r6 */
/* @0x2a7b7e add r1, sp, #0x88 */
/* @0x2a7b80 movs r2, #0x4 */
/* @0x2a7b82 blx 0xb6c40 <memcmp@plt> */
/* @0x2a7b84 stmdblt r8!, {r1, r2, r3, r4, r6, r11, sp, lr, pc} */
/* @0x2a7b86 cbnz r0, 0x2a7b94 <png_read_end+0x318> */
/* @0x2a7b88 mov r0, r4 */
/* @0x2a7b8a mov r1, r7 */
/* @0x2a7b8c mov r2, r5 */
/* @0x2a7b8e bl 0x2ac694 <png_handle_sRGB> */
/* @0x2a7b90 subs pc, r8, r1, lsl #27 */
/* @0x2a7b92 b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7b94 mov r0, r6 */
/* @0x2a7b96 add r1, sp, #0x48 */
/* @0x2a7b98 movs r2, #0x4 */
/* @0x2a7b9a blx 0xb6c40 <memcmp@plt> */
/* @0x2a7b9c stmdblt r8!, {r1, r4, r6, r11, sp, lr, pc} */
/* @0x2a7b9e cbnz r0, 0x2a7bac <png_read_end+0x330> */
/* @0x2a7ba0 mov r0, r4 */
/* @0x2a7ba2 mov r1, r7 */
/* @0x2a7ba4 mov r2, r5 */
/* @0x2a7ba6 bl 0x2ac814 <png_handle_iCCP> */
/* @0x2a7ba8 sub pc, r12, r5, lsr lr */
/* @0x2a7baa b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7bac mov r0, r6 */
/* @0x2a7bae add r1, sp, #0x80 */
/* @0x2a7bb0 movs r2, #0x4 */
/* @0x2a7bb2 blx 0xb6c40 <memcmp@plt> */
/* @0x2a7bb4 stmdblt r8!, {r1, r2, r6, r11, sp, lr, pc} */
/* @0x2a7bb6 cbnz r0, 0x2a7bc4 <png_read_end+0x348> */
/* @0x2a7bb8 mov r0, r4 */
/* @0x2a7bba mov r1, r7 */
/* @0x2a7bbc mov r2, r5 */
/* @0x2a7bbe bl 0x2ac9ec <png_handle_sPLT> */
/* @0x2a7bc0 sub pc, r0, r5, lsl pc */
/* @0x2a7bc2 b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7bc4 mov r0, r6 */
/* @0x2a7bc6 add r1, sp, #0x90 */
/* @0x2a7bc8 movs r2, #0x4 */
/* @0x2a7bca blx 0xb6c40 <memcmp@plt> */
/* @0x2a7bcc stmdblt r8!, {r1, r3, r4, r5, r11, sp, lr, pc} */
/* @0x2a7bce cbnz r0, 0x2a7bdc <png_read_end+0x360> */
/* @0x2a7bd0 mov r0, r4 */
/* @0x2a7bd2 mov r1, r7 */
/* @0x2a7bd4 mov r2, r5 */
/* @0x2a7bd6 bl 0x2ad584 <png_handle_tEXt> */
/* @0x2a7bd8 ldrsbt pc, [r4], -r5 */
/* @0x2a7bda b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7bdc mov r0, r6 */
/* @0x2a7bde add r1, sp, #0x98 */
/* @0x2a7be0 movs r2, #0x4 */
/* @0x2a7be2 blx 0xb6c40 <memcmp@plt> */
/* @0x2a7be4 stmdblt r8!, {r1, r2, r3, r5, r11, sp, lr, pc} */
/* @0x2a7be6 cbnz r0, 0x2a7bf4 <png_read_end+0x378> */
/* @0x2a7be8 mov r0, r4 */
/* @0x2a7bea mov r1, r7 */
/* @0x2a7bec mov r2, r5 */
/* @0x2a7bee bl 0x2ad4d0 <png_handle_tIME> */
/* @0x2a7bf0 eor pc, r8, pc, ror #24 */
/* @0x2a7bf2 b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7bf4 mov r0, r6 */
/* @0x2a7bf6 add r1, sp, #0xa0 */
/* @0x2a7bf8 movs r2, #0x4 */
/* @0x2a7bfa blx 0xb6c40 <memcmp@plt> */
/* @0x2a7bfc stmdblt r8!, {r1, r5, r11, sp, lr, pc} */
/* @0x2a7bfe cbnz r0, 0x2a7c0c <png_read_end+0x390> */
/* @0x2a7c00 mov r0, r4 */
/* @0x2a7c02 mov r1, r7 */
/* @0x2a7c04 mov r2, r5 */
/* @0x2a7c06 bl 0x2acbec <png_handle_tRNS> */
/* @0x2a7c08 ldrsh pc, [r12], -r1 */
/* @0x2a7c0a b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7c0c mov r0, r6 */
/* @0x2a7c0e add r1, sp, #0xa8 */
/* @0x2a7c10 movs r2, #0x4 */
/* @0x2a7c12 blx 0xb6c40 <memcmp@plt> */
/* @0x2a7c14 stmdblt r8!, {r1, r2, r4, r11, sp, lr, pc} */
/* @0x2a7c16 cbnz r0, 0x2a7c24 <png_read_end+0x3a8> */
/* @0x2a7c18 mov r0, r4 */
/* @0x2a7c1a mov r1, r7 */
/* @0x2a7c1c mov r2, r5 */
/* @0x2a7c1e bl 0x2ad6cc <png_handle_zTXt> */
/* @0x2a7c20 ands pc, r0, r5, asr sp */
/* @0x2a7c22 b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7c24 mov r0, r6 */
/* @0x2a7c26 add r1, sp, #0x50 */
/* @0x2a7c28 movs r2, #0x4 */
/* @0x2a7c2a blx 0xb6c40 <memcmp@plt> */
/* @0x2a7c2c stmdblt r8!, {r1, r3, r11, sp, lr, pc} */
/* @0x2a7c2e cbnz r0, 0x2a7c3c <png_read_end+0x3c0> */
/* @0x2a7c30 mov r0, r4 */
/* @0x2a7c32 mov r1, r7 */
/* @0x2a7c34 mov r2, r5 */
/* @0x2a7c36 bl 0x2ad850 <png_handle_iTXt> */
/* @0x2a7c38 and pc, r4, r11, lsl #28 */
/* @0x2a7c3a b 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7c3c mov r0, r4 */
/* @0x2a7c3e mov r1, r7 */
/* @0x2a7c40 mov r2, r5 */
/* @0x2a7c42 bl 0x2ada34 <png_handle_unknown> */
/* @0x2a7c44 .word 0xf8d4fef7 */
/* @0x2a7c46 ldr.w r3, [r4, #0x12c] */
/* @0x2a7c48 ldrbeq r3, [r11], r12, lsr #2 */
/* @0x2a7c4a lsls r3, r3, #0x1b */
/* @0x2a7c4c bpl.w 0x2a78a4 <png_read_end+0x28> */
/* @0x2a7c50 add sp, #0xb4 */
/* @0x2a7c52 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2a7c54 svclt #0x8ff0 */
/* @0x2a7c56 nop */
/* @0x2a7c58 strh r6, [r5, #0x2] */
/* @0x2a7c5a movs r6, r1 */
/* @0x2a7c5c ldr r6, [pc, #0x1f0] */
/* @0x2a7c5e movs r6, r1 */
/* @0x2a7c60 ldr r6, [pc, #0xd0] */
/* @0x2a7c62 movs r6, r1 */

/* ── FUNC 0x2a7c64 · png_read_destroy · size=456 · insn=197 */
/* @0x2a7c64 push.w {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2a7c68 mov r4, r0 */
/* @0x2a7c6a sub sp, #0x104 */
/* @0x2a7c6c mov r5, r2 */
/* @0x2a7c6e cbz r1, 0x2a7c74 <png_read_destroy+0x10> */
/* @0x2a7c70 bl 0x2a5ebe <png_info_destroy> */
/* @0x2a7c74 cbz r5, 0x2a7c7e <png_read_destroy+0x1a> */
/* @0x2a7c76 mov r0, r4 */
/* @0x2a7c78 mov r1, r5 */
/* @0x2a7c7a bl 0x2a5ebe <png_info_destroy> */
/* @0x2a7c7c strtmi pc, [r0], -r0, lsr #18 */
/* @0x2a7c7e mov r0, r4 */
/* @0x2a7c80 ldr.w r1, [r4, #0x170] */
/* @0x2a7c84 bl 0x2a6cfc <png_free> */
/* @0x2a7c88 mov r0, r4 */
/* @0x2a7c8a ldr.w r1, [r4, #0x2f4] */
/* @0x2a7c8c .word 0xf7ff12f4 */
/* @0x2a7c8e bl 0x2a6cfc <png_free> */
/* @0x2a7c90 qasxmi pc, r0, r5 */
/* @0x2a7c92 mov r0, r4 */
/* @0x2a7c94 ldr.w r1, [r4, #0x1ac] */
/* @0x2a7c98 bl 0x2a6cfc <png_free> */
/* @0x2a7c9c mov r0, r4 */
/* @0x2a7c9e ldr.w r1, [r4, #0x330] */
/* @0x2a7ca0 .word 0xf7ff1330 */
/* @0x2a7ca2 bl 0x2a6cfc <png_free> */
/* @0x2a7ca4 strtmi pc, [r0], -r11, lsr #16 */
/* @0x2a7ca6 mov r0, r4 */
/* @0x2a7ca8 ldr.w r1, [r4, #0x2b0] */
/* @0x2a7cac bl 0x2a6cfc <png_free> */
/* @0x2a7cb0 mov r0, r4 */
/* @0x2a7cb2 ldr.w r1, [r4, #0x2b4] */
/* @0x2a7cb4 .word 0xf7ff12b4 */
/* @0x2a7cb6 bl 0x2a6cfc <png_free> */
/* @0x2a7cb8 strtmi pc, [r0], -r1, lsr #16 */
/* @0x2a7cba mov r0, r4 */
/* @0x2a7cbc ldr.w r1, [r4, #0x228] */
/* @0x2a7cc0 bl 0x2a6cfc <png_free> */
/* @0x2a7cc4 mov r0, r4 */
/* @0x2a7cc6 ldr.w r1, [r4, #0x22c] */
/* @0x2a7cc8 .word 0xf7ff122c */
/* @0x2a7cca bl 0x2a6cfc <png_free> */
/* @0x2a7ccc .word 0xf8d4f817 */
/* @0x2a7cce ldr.w r1, [r4, #0x230] */
/* @0x2a7cd0 qasxmi r1, r0, r0 */
/* @0x2a7cd2 mov r0, r4 */
/* @0x2a7cd4 bl 0x2a6cfc <png_free> */
/* @0x2a7cd8 ldr.w r3, [r4, #0x2c0] */
/* @0x2a7cdc lsls r1, r3, #0x13 */
/* @0x2a7cde bpl 0x2a7cea <png_read_destroy+0x86> */
/* @0x2a7ce0 mov r0, r4 */
/* @0x2a7ce2 ldr.w r1, [r4, #0x1d8] */
/* @0x2a7ce4 .word 0xf7fd11d8 */
/* @0x2a7ce6 bl 0x2a5af0 <png_zfree> */
/* @0x2a7ce8 .word 0xf8d4ff03 */
/* @0x2a7cea ldr.w r3, [r4, #0x2c0] */
/* @0x2a7cec vld1.64 {d3, d4, d5, d6}, [r3], r0 */
/* @0x2a7cee bic r2, r3, #0x1000 */
/* @0x2a7cf0 .word 0xf8c45280 */
/* @0x2a7cf2 str.w r2, [r4, #0x2c0] */
/* @0x2a7cf4 ldreq r2, [r10], #704 */
/* @0x2a7cf6 lsls r2, r3, #0x12 */
/* @0x2a7cf8 bpl 0x2a7d04 <png_read_destroy+0xa0> */
/* @0x2a7cfa mov r0, r4 */
/* @0x2a7cfc ldr.w r1, [r4, #0x24c] */
/* @0x2a7d00 bl 0x2a6cfc <png_free> */
/* @0x2a7d04 ldr.w r3, [r4, #0x2c0] */
/* @0x2a7d08 bic r2, r3, #0x2000 */
/* @0x2a7d0c lsls r3, r3, #0x1c */
/* @0x2a7d0e str.w r2, [r4, #0x2c0] */
/* @0x2a7d10 strle r2, [r4, #-0x2c0] */
/* @0x2a7d12 bpl 0x2a7d1e <png_read_destroy+0xba> */
/* @0x2a7d14 mov r0, r4 */
/* @0x2a7d16 ldr.w r1, [r4, #0x2b8] */
/* @0x2a7d18 .word 0xf7fe12b8 */
/* @0x2a7d1a bl 0x2a6cfc <png_free> */
/* @0x2a7d1c .word 0xf8d4ffef */
/* @0x2a7d1e ldr.w r3, [r4, #0x2c0] */
/* @0x2a7d20 .word 0xf02332c0 */
/* @0x2a7d22 bic r3, r3, #0x8 */
/* @0x2a7d24 .word 0xf8c40308 */
/* @0x2a7d26 str.w r3, [r4, #0x2c0] */
/* @0x2a7d28 .word 0xf8d432c0 */
/* @0x2a7d2a ldr.w r3, [r4, #0x234] */
/* @0x2a7d2c .word 0xb1b33234 */
/* @0x2a7d2e cbz r3, 0x2a7d5e <png_read_destroy+0xfa> */
/* @0x2a7d30 ldr.w r3, [r4, #0x21c] */
/* @0x2a7d34 movs r6, #0x1 */
/* @0x2a7d36 movs r5, #0x0 */
/* @0x2a7d38 rsb.w r3, r3, #0x8 */
/* @0x2a7d3c lsls r6, r3 */
/* @0x2a7d3e cmp r5, r6 */
/* @0x2a7d40 bge 0x2a7d54 <png_read_destroy+0xf0> */
/* @0x2a7d42 ldr.w r3, [r4, #0x234] */
/* @0x2a7d44 qasxmi r3, r0, r4 */
/* @0x2a7d46 mov r0, r4 */
/* @0x2a7d48 ldr.w r1, [r3, r5, lsl #2] */
/* @0x2a7d4c adds r5, #0x1 */
/* @0x2a7d4e bl 0x2a6cfc <png_free> */
/* @0x2a7d50 ubfx pc, r5, #0x1f, #0x15 */
/* @0x2a7d52 b 0x2a7d3e <png_read_destroy+0xda> */
/* @0x2a7d54 mov r0, r4 */
/* @0x2a7d56 ldr.w r1, [r4, #0x234] */
/* @0x2a7d58 .word 0xf7fe1234 */
/* @0x2a7d5a bl 0x2a6cfc <png_free> */
/* @0x2a7d5c .word 0xf8d4ffcf */
/* @0x2a7d5e ldr.w r3, [r4, #0x238] */
/* @0x2a7d60 .word 0xb1b33238 */
/* @0x2a7d62 cbz r3, 0x2a7d92 <png_read_destroy+0x12e> */
/* @0x2a7d64 ldr.w r3, [r4, #0x21c] */
/* @0x2a7d68 movs r6, #0x1 */
/* @0x2a7d6a movs r5, #0x0 */
/* @0x2a7d6c rsb.w r3, r3, #0x8 */
/* @0x2a7d70 lsls r6, r3 */
/* @0x2a7d72 cmp r5, r6 */
/* @0x2a7d74 bge 0x2a7d88 <png_read_destroy+0x124> */
/* @0x2a7d76 ldr.w r3, [r4, #0x238] */
/* @0x2a7d78 qasxmi r3, r0, r8 */
/* @0x2a7d7a mov r0, r4 */
/* @0x2a7d7c ldr.w r1, [r3, r5, lsl #2] */
/* @0x2a7d80 adds r5, #0x1 */
/* @0x2a7d82 bl 0x2a6cfc <png_free> */
/* @0x2a7d84 .word 0xe7f4ffbb */
/* @0x2a7d86 b 0x2a7d72 <png_read_destroy+0x10e> */
/* @0x2a7d88 mov r0, r4 */
/* @0x2a7d8a ldr.w r1, [r4, #0x238] */
/* @0x2a7d8c .word 0xf7fe1238 */
/* @0x2a7d8e bl 0x2a6cfc <png_free> */
/* @0x2a7d90 .word 0xf8d4ffb5 */
/* @0x2a7d92 ldr.w r3, [r4, #0x23c] */
/* @0x2a7d94 .word 0xb1b3323c */
/* @0x2a7d96 cbz r3, 0x2a7dc6 <png_read_destroy+0x162> */
/* @0x2a7d98 ldr.w r3, [r4, #0x21c] */
/* @0x2a7d9c movs r6, #0x1 */
/* @0x2a7d9e movs r5, #0x0 */
/* @0x2a7da0 rsb.w r3, r3, #0x8 */
/* @0x2a7da4 lsls r6, r3 */
/* @0x2a7da6 cmp r5, r6 */
/* @0x2a7da8 bge 0x2a7dbc <png_read_destroy+0x158> */
/* @0x2a7daa ldr.w r3, [r4, #0x23c] */
/* @0x2a7dac qasxmi r3, r0, r12 */
/* @0x2a7dae mov r0, r4 */
/* @0x2a7db0 ldr.w r1, [r3, r5, lsl #2] */
/* @0x2a7db4 adds r5, #0x1 */
/* @0x2a7db6 bl 0x2a6cfc <png_free> */
/* @0x2a7db8 ldrb pc, [r4, r1, lsr #31]! */
/* @0x2a7dba b 0x2a7da6 <png_read_destroy+0x142> */
/* @0x2a7dbc mov r0, r4 */
/* @0x2a7dbe ldr.w r1, [r4, #0x23c] */
/* @0x2a7dc0 .word 0xf7fe123c */
/* @0x2a7dc2 bl 0x2a6cfc <png_free> */
/* @0x2a7dc4 .word 0xf8d4ff9b */
/* @0x2a7dc6 ldr.w r1, [r4, #0x2bc] */
/* @0x2a7dc8 .word 0x462012bc */
/* @0x2a7dca mov r0, r4 */
/* @0x2a7dcc bl 0x2a6cfc <png_free> */
/* @0x2a7dd0 add.w r0, r4, #0x138 */
/* @0x2a7dd4 blx 0xb69e8 <inflateEnd@plt> */
/* @0x2a7dd8 mov r0, r4 */
/* @0x2a7dda ldr.w r1, [r4, #0x274] */
/* @0x2a7ddc .word 0xf7fe1274 */
/* @0x2a7dde bl 0x2a6cfc <png_free> */
/* @0x2a7de0 strtmi pc, [r1], -sp, lsl #31 */
/* @0x2a7de2 mov r1, r4 */
/* @0x2a7de4 mov r0, sp */
/* @0x2a7de6 mov.w r2, #0x100 */
/* @0x2a7de8 .word 0xf60e7280 */
/* @0x2a7dea blx 0xb65bc <memcpy@plt> */
/* @0x2a7dec .word 0xf8d4ebe8 */
/* @0x2a7dee ldr.w r9, [r4, #0x104] */
/* @0x2a7df0 .word 0xf8d49104 */
/* @0x2a7df2 ldr.w r8, [r4, #0x108] */
/* @0x2a7df4 strtmi r8, [r0], -r8, lsl #2 */
/* @0x2a7df6 mov r0, r4 */
/* @0x2a7df8 ldr.w r7, [r4, #0x10c] */
/* @0x2a7dfc movs r1, #0x0 */
/* @0x2a7dfe ldr.w r6, [r4, #0x2f0] */
/* @0x2a7e00 vst1.64 {d22, d23, d24, d25}, [pc:256], r0 */
/* @0x2a7e02 mov.w r2, #0x338 */
/* @0x2a7e04 .word 0xf60e724e */
/* @0x2a7e06 blx 0xb65b0 <memset@plt> */
/* @0x2a7e08 .word 0xf8c4ebd4 */
/* @0x2a7e0a str.w r9, [r4, #0x104] */
/* @0x2a7e0c .word 0xf8c49104 */
/* @0x2a7e0e str.w r8, [r4, #0x108] */
/* @0x2a7e10 strtmi r8, [r0], -r8, lsl #2 */
/* @0x2a7e12 mov r0, r4 */
/* @0x2a7e14 str.w r7, [r4, #0x10c] */
/* @0x2a7e18 mov r1, sp */
/* @0x2a7e1a str.w r6, [r4, #0x2f0] */
/* @0x2a7e1c vst1.64 {d22, d23, d24, d25}, [pc:256], r0 */
/* @0x2a7e1e mov.w r2, #0x100 */
/* @0x2a7e20 .word 0xf60e7280 */
/* @0x2a7e22 blx 0xb65bc <memcpy@plt> */
/* @0x2a7e24 sublt lr, r1, r12, asr #23 */
/* @0x2a7e26 add sp, #0x104 */
/* @0x2a7e28 pop.w {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x2a7e2c · png_destroy_read_struct · size=140 · insn=60 */
/* @0x2a7e2c push.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a7e30 mov r8, r1 */
/* @0x2a7e32 mov r7, r2 */
/* @0x2a7e34 mov r9, r0 */
/* @0x2a7e36 cmp r0, #0x0 */
/* @0x2a7e38 beq 0x2a7eb4 <png_destroy_read_struct+0x88> */
/* @0x2a7e3a ldr r4, [r0] */
/* @0x2a7e3c cmp r4, #0x0 */
/* @0x2a7e3e beq 0x2a7eb4 <png_destroy_read_struct+0x88> */
/* @0x2a7e40 ldr.w r11, [r4, #0x2f0] */
/* @0x2a7e44 ldr.w r10, [r4, #0x2e8] */
/* @0x2a7e48 cbz r1, 0x2a7e4e <png_destroy_read_struct+0x22> */
/* @0x2a7e4a ldr r6, [r1] */
/* @0x2a7e4c b 0x2a7e50 <png_destroy_read_struct+0x24> */
/* @0x2a7e4e mov r6, r1 */
/* @0x2a7e50 cbz r7, 0x2a7e56 <png_destroy_read_struct+0x2a> */
/* @0x2a7e52 ldr r5, [r7] */
/* @0x2a7e54 b 0x2a7e58 <png_destroy_read_struct+0x2c> */
/* @0x2a7e56 mov r5, r7 */
/* @0x2a7e58 mov r0, r4 */
/* @0x2a7e5a mov r1, r6 */
/* @0x2a7e5c mov r2, r5 */
/* @0x2a7e5e bl 0x2a7c64 <png_read_destroy> */
/* @0x2a7e60 cmnlt lr, r1, lsl #30 */
/* @0x2a7e62 cbz r6, 0x2a7e84 <png_destroy_read_struct+0x58> */
/* @0x2a7e64 mov.w r3, #0xffffffff */
/* @0x2a7e68 mov r0, r4 */
/* @0x2a7e6a mov r1, r6 */
/* @0x2a7e6c mov.w r2, #0x4000 */
/* @0x2a7e70 bl 0x2a5bc0 <png_free_data> */
/* @0x2a7e74 mov r0, r6 */
/* @0x2a7e76 mov r1, r11 */
/* @0x2a7e78 mov r2, r10 */
/* @0x2a7e7a bl 0x2a6c5e <png_destroy_struct_2> */
/* @0x2a7e7c movwhs pc, #0xef0 */
/* @0x2a7e7e movs r3, #0x0 */
/* @0x2a7e80 str.w r3, [r8] */
/* @0x2a7e84 cbz r5, 0x2a7ea4 <png_destroy_read_struct+0x78> */
/* @0x2a7e86 mov.w r3, #0xffffffff */
/* @0x2a7e88 qsub8mi r3, r0, pc */
/* @0x2a7e8a mov r0, r4 */
/* @0x2a7e8c mov r1, r5 */
/* @0x2a7e8e mov.w r2, #0x4000 */
/* @0x2a7e90 .word 0xf7fd4280 */
/* @0x2a7e92 bl 0x2a5bc0 <png_free_data> */
/* @0x2a7e94 qadd8mi pc, r8, r5 */
/* @0x2a7e96 mov r0, r5 */
/* @0x2a7e98 mov r1, r11 */
/* @0x2a7e9a mov r2, r10 */
/* @0x2a7e9c bl 0x2a6c5e <png_destroy_struct_2> */
/* @0x2a7ea0 movs r3, #0x0 */
/* @0x2a7ea2 str r3, [r7] */
/* @0x2a7ea4 mov r0, r4 */
/* @0x2a7ea6 mov r1, r11 */
/* @0x2a7ea8 mov r2, r10 */
/* @0x2a7eaa bl 0x2a6c5e <png_destroy_struct_2> */
/* @0x2a7eac movwhs pc, #0xed8 */
/* @0x2a7eae movs r3, #0x0 */
/* @0x2a7eb0 str.w r3, [r9] */
/* @0x2a7eb4 pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x2a7eb8 · png_set_read_status_fn · size=8 · insn=4 */
/* @0x2a7eb8 cbz r0, 0x2a7ebe <png_set_read_status_fn+0x6> */
/* @0x2a7eba str.w r1, [r0, #0x25c] */
/* @0x2a7ebc .word 0x4770125c */
/* @0x2a7ebe bx lr */

/* ── FUNC 0x2a7ec0 · png_read_png · size=324 · insn=149 */
/* @0x2a7ec0 push {r3, r4, r5, r6, r7, lr} */
/* @0x2a7ec2 mov r5, r1 */
/* @0x2a7ec4 mov r6, r2 */
/* @0x2a7ec6 mov r4, r0 */
/* @0x2a7ec8 cmp r0, #0x0 */
/* @0x2a7eca beq.w 0x2a7ffe <png_read_png+0x13e> */
/* @0x2a7ecc .word 0xf7ff8098 */
/* @0x2a7ece bl 0x2a6ff0 <png_read_info> */
/* @0x2a7ed0 stmdavs r11!, {r0, r1, r2, r3, r7, r11, r12, sp, lr, pc} ^ */
/* @0x2a7ed2 ldr r3, [r5, #0x4] */
/* @0x2a7ed4 cmp.w r3, #0x40000000 */
/* @0x2a7ed8 blo 0x2a7ee4 <png_read_png+0x24> */
/* @0x2a7eda ldr r1, [pc, #0x124] */
/* @0x2a7edc mov r0, r4 */
/* @0x2a7ede add r1, pc */
/* @0x2a7ee0 bl 0x2a642c <png_error> */
/* @0x2a7ee4 lsls r1, r6, #0x1f */
/* @0x2a7ee6 bpl 0x2a7eee <png_read_png+0x2e> */
/* @0x2a7ee8 mov r0, r4 */
/* @0x2a7eea bl 0x2a8184 <png_set_strip_16> */
/* @0x2a7eec ldreq pc, [r2, r11, asr #18]! */
/* @0x2a7eee lsls r2, r6, #0x1e */
/* @0x2a7ef0 bpl 0x2a7ef8 <png_read_png+0x38> */
/* @0x2a7ef2 mov r0, r4 */
/* @0x2a7ef4 bl 0x2a8194 <png_set_strip_alpha> */
/* @0x2a7ef8 lsls r3, r6, #0x1c */
/* @0x2a7efa bpl 0x2a7f02 <png_read_png+0x42> */
/* @0x2a7efc mov r0, r4 */
/* @0x2a7efe bl 0x2af77e <png_set_packswap> */
/* @0x2a7f00 .word 0x06f7fc3e */
/* @0x2a7f02 lsls r7, r6, #0x1b */
/* @0x2a7f04 bpl 0x2a7f22 <png_read_png+0x62> */
/* @0x2a7f06 ldrb.w r3, [r4, #0x1eb] */
/* @0x2a7f08 blhs 0x4746bc <g_RomDisk+0x7ce9c> */
/* @0x2a7f0a cmp r3, #0x7 */
/* @0x2a7f0c bls 0x2a7f1c <png_read_png+0x5c> */
/* @0x2a7f0e ldrb.w r3, [r4, #0x1ea] */
/* @0x2a7f10 blhs 0x3746c0 <_ZTS13C_UTF16String+0xb76c> */
/* @0x2a7f12 cmp r3, #0x3 */
/* @0x2a7f14 beq 0x2a7f1c <png_read_png+0x5c> */
/* @0x2a7f16 ldr r3, [r5, #0x8] */
/* @0x2a7f18 lsls r0, r3, #0x1b */
/* @0x2a7f1a bpl 0x2a7f22 <png_read_png+0x62> */
/* @0x2a7f1c mov r0, r4 */
/* @0x2a7f1e bl 0x2a8790 <png_set_expand> */
/* @0x2a7f20 .word 0x06b1fc37 */
/* @0x2a7f22 lsls r1, r6, #0x1a */
/* @0x2a7f24 bpl 0x2a7f2c <png_read_png+0x6c> */
/* @0x2a7f26 mov r0, r4 */
/* @0x2a7f28 bl 0x2af84a <png_set_invert_mono> */
/* @0x2a7f2c lsls r2, r6, #0x19 */
/* @0x2a7f2e bpl 0x2a7f40 <png_read_png+0x80> */
/* @0x2a7f30 ldr r3, [r5, #0x8] */
/* @0x2a7f32 lsls r3, r3, #0x1e */
/* @0x2a7f34 bpl 0x2a7f40 <png_read_png+0x80> */
/* @0x2a7f36 mov r0, r4 */
/* @0x2a7f38 add.w r1, r5, #0x44 */
/* @0x2a7f3c bl 0x2af796 <png_set_shift> */
/* @0x2a7f40 lsls r7, r6, #0x18 */
/* @0x2a7f42 bpl 0x2a7f4a <png_read_png+0x8a> */
/* @0x2a7f44 mov r0, r4 */
/* @0x2a7f46 bl 0x2af738 <png_set_bgr> */
/* @0x2a7f48 ldrbeq pc, [r0, #0xbf7]! */
/* @0x2a7f4a lsls r0, r6, #0x17 */
/* @0x2a7f4c bpl 0x2a7f54 <png_read_png+0x94> */
/* @0x2a7f4e mov r0, r4 */
/* @0x2a7f50 bl 0x2af82a <png_set_swap_alpha> */
/* @0x2a7f54 lsls r1, r6, #0x16 */
/* @0x2a7f56 bpl 0x2a7f5e <png_read_png+0x9e> */
/* @0x2a7f58 mov r0, r4 */
/* @0x2a7f5a bl 0x2af748 <png_set_swap> */
/* @0x2a7f5c ldrbeq pc, [r2, #-0xbf5]! */
/* @0x2a7f5e lsls r2, r6, #0x15 */
/* @0x2a7f60 bpl 0x2a7f68 <png_read_png+0xa8> */
/* @0x2a7f62 mov r0, r4 */
/* @0x2a7f64 bl 0x2af83a <png_set_invert_alpha> */
/* @0x2a7f68 lsls r3, r6, #0x12 */
/* @0x2a7f6a bpl 0x2a7f72 <png_read_png+0xb2> */
/* @0x2a7f6c mov r0, r4 */
/* @0x2a7f6e bl 0x2a880a <png_set_gray_to_rgb> */
/* @0x2a7f70 strtmi pc, [r0], -r12, asr #24 */
/* @0x2a7f72 mov r0, r4 */
/* @0x2a7f74 mov r1, r5 */
/* @0x2a7f76 bl 0x2a7448 <png_read_update_info> */
/* @0x2a7f78 strtmi pc, [r0], -r7, ror #20 */
/* @0x2a7f7a mov r0, r4 */
/* @0x2a7f7c mov r1, r5 */
/* @0x2a7f7e movs r2, #0x40 */
/* @0x2a7f80 movs r3, #0x0 */
/* @0x2a7f82 bl 0x2a5bc0 <png_free_data> */
/* @0x2a7f84 .word 0xf8d5fe1d */
/* @0x2a7f86 ldr.w r6, [r5, #0xf8] */
/* @0x2a7f88 ldrshlt r6, [r6, #-8]! */
/* @0x2a7f8a cbz r6, 0x2a7faa <png_read_png+0xea> */
/* @0x2a7f8c mov r0, r4 */
/* @0x2a7f8e ldr.w r1, [r5, #0xf8] */
/* @0x2a7f90 .word 0xf7ff10f8 */
/* @0x2a7f92 bl 0x2a7840 <png_read_image> */
/* @0x2a7f94 stmvs r11!, {r0, r2, r4, r6, r10, r11, r12, sp, lr, pc} */
/* @0x2a7f96 ldr r3, [r5, #0x8] */
/* @0x2a7f98 mov r0, r4 */
/* @0x2a7f9a mov r1, r5 */
/* @0x2a7f9c orr r3, r3, #0x8000 */
/* @0x2a7fa0 str r3, [r5, #0x8] */
/* @0x2a7fa2 pop.w {r3, r4, r5, r6, r7, lr} */
/* @0x2a7fa4 .word 0xf7ff40f8 */
/* @0x2a7fa6 b.w 0x2a787c <png_read_end> */
/* @0x2a7fa8 stmdavs r9!, {r0, r3, r5, r6, r10, r11, r12, sp, pc} ^ */
/* @0x2a7faa ldr r1, [r5, #0x4] */
/* @0x2a7fac mov r0, r4 */
/* @0x2a7fae lsls r1, r1, #0x2 */
/* @0x2a7fb0 bl 0x2a6ca0 <png_malloc> */
/* @0x2a7fb4 mov r3, r6 */
/* @0x2a7fb6 mov r1, r6 */
/* @0x2a7fb8 str.w r0, [r5, #0xf8] */
/* @0x2a7fbc ldr r2, [r5, #0x4] */
/* @0x2a7fbe cmp r3, r2 */
/* @0x2a7fc0 bhs 0x2a7fce <png_read_png+0x10e> */
/* @0x2a7fc2 ldr.w r2, [r5, #0xf8] */
/* @0x2a7fc4 .word 0xf84220f8 */
/* @0x2a7fc6 str.w r1, [r2, r3, lsl #2] */
/* @0x2a7fc8 movwlo r1, #0x1023 */
/* @0x2a7fca adds r3, #0x1 */
/* @0x2a7fcc b 0x2a7fbc <png_read_png+0xfc> */
/* @0x2a7fce ldr.w r3, [r5, #0xb8] */
/* @0x2a7fd0 .word 0x260030b8 */
/* @0x2a7fd2 movs r6, #0x0 */
/* @0x2a7fd4 orr r3, r3, #0x40 */
/* @0x2a7fd8 str.w r3, [r5, #0xb8] */
/* @0x2a7fdc ldr r3, [r5, #0x4] */
/* @0x2a7fde cmp r6, r3 */
/* @0x2a7fe0 bge 0x2a7f8c <png_read_png+0xcc> */
/* @0x2a7fe2 mov r1, r5 */
/* @0x2a7fe4 mov r0, r4 */
/* @0x2a7fe6 ldr.w r7, [r5, #0xf8] */
/* @0x2a7fe8 .word 0xf7fe70f8 */
/* @0x2a7fea bl 0x2a6574 <png_get_rowbytes> */
/* @0x2a7fec strmi pc, [r1], -r3, asr #21 */
/* @0x2a7fee mov r1, r0 */
/* @0x2a7ff0 mov r0, r4 */
/* @0x2a7ff2 bl 0x2a6ca0 <png_malloc> */
/* @0x2a7ff4 .word 0xf847fe55 */
/* @0x2a7ff6 str.w r0, [r7, r6, lsl #2] */
/* @0x2a7ff8 strlo r0, [r1], -r6, lsr #32 */
/* @0x2a7ffa adds r6, #0x1 */
/* @0x2a7ffc b 0x2a7fdc <png_read_png+0x11c> */
/* @0x2a7ffe pop {r3, r4, r5, r6, r7, pc} */
/* @0x2a8000 ldr r1, [pc, #0x39c] */
/* @0x2a8002 movs r6, r1 */

/* ── FUNC 0x2a8004 · png_default_read_data · size=44 · insn=20 */
/* @0x2a8004 push {r3, r4, r5, lr} */
/* @0x2a8006 mov r5, r2 */
/* @0x2a8008 mov r4, r0 */
/* @0x2a800a cbz r0, 0x2a802a <png_default_read_data+0x26> */
/* @0x2a800c mov r0, r1 */
/* @0x2a800e ldr.w r3, [r4, #0x118] */
/* @0x2a8010 .word 0x21013118 */
/* @0x2a8012 movs r1, #0x1 */
/* @0x2a8014 blx 0xb68c8 <fread@plt> */
/* @0x2a8018 cmp r0, r5 */
/* @0x2a801a beq 0x2a802a <png_default_read_data+0x26> */
/* @0x2a801c ldr r1, [pc, #0xc] */
/* @0x2a801e mov r0, r4 */
/* @0x2a8020 pop.w {r3, r4, r5, lr} */
/* @0x2a8024 add r1, pc */
/* @0x2a8026 b.w 0x2a642c <png_error> */
/* @0x2a8028 vldmdblt r8!, {s22} */
/* @0x2a802a pop {r3, r4, r5, pc} */
/* @0x2a802c ldr r0, [pc, #0x348] */
/* @0x2a802e movs r6, r1 */

/* ── FUNC 0x2a8030 · png_read_data · size=28 · insn=13 */
/* @0x2a8030 push {r3, lr} */
/* @0x2a8032 ldr.w r3, [r0, #0x114] */
/* @0x2a8034 .word 0xb10b3114 */
/* @0x2a8036 cbz r3, 0x2a803c <png_read_data+0xc> */
/* @0x2a8038 blx r3 */
/* @0x2a803a pop {r3, pc} */
/* @0x2a803c ldr r1, [pc, #0x8] */
/* @0x2a803e pop.w {r3, lr} */
/* @0x2a8040 ldrbtmi r4, [r9], #-8 */
/* @0x2a8042 add r1, pc */
/* @0x2a8044 b.w 0x2a642c <png_error> */
/* @0x2a8048 ldr r0, [pc, #0x2fc] */
/* @0x2a804a movs r6, r1 */

/* ── FUNC 0x2a804c · png_set_read_fn · size=80 · insn=35 */
/* @0x2a804c push {r4, lr} */
/* @0x2a804e mov r4, r0 */
/* @0x2a8050 cbz r0, 0x2a808e <png_set_read_fn+0x42> */
/* @0x2a8052 str.w r1, [r0, #0x118] */
/* @0x2a8054 tstlt r2, r8, lsl r1 */
/* @0x2a8056 cbz r2, 0x2a805e <png_set_read_fn+0x12> */
/* @0x2a8058 str.w r2, [r0, #0x114] */
/* @0x2a805c b 0x2a8068 <png_set_read_fn+0x1c> */
/* @0x2a805e ldr r3, [pc, #0x30] */
/* @0x2a8060 add r3, pc */
/* @0x2a8062 ldr r3, [r3] */
/* @0x2a8064 str.w r3, [r0, #0x114] */
/* @0x2a8068 ldr.w r3, [r4, #0x110] */
/* @0x2a806c cbz r3, 0x2a8088 <png_set_read_fn+0x3c> */
/* @0x2a806e ldr r1, [pc, #0x24] */
/* @0x2a8070 movs r3, #0x0 */
/* @0x2a8072 mov r0, r4 */
/* @0x2a8074 str.w r3, [r4, #0x110] */
/* @0x2a8078 add r1, pc */
/* @0x2a807a bl 0x2a6474 <png_warning> */
/* @0x2a807c stmdbmi r6, {r0, r1, r3, r4, r5, r6, r7, r8, r11, r12, sp, lr, pc} */
/* @0x2a807e ldr r1, [pc, #0x18] */
/* @0x2a8080 mov r0, r4 */
/* @0x2a8082 add r1, pc */
/* @0x2a8084 bl 0x2a6474 <png_warning> */
/* @0x2a8088 movs r3, #0x0 */
/* @0x2a808a str.w r3, [r4, #0x210] */
/* @0x2a808c ldclt p2, c3, [r0, #-64] */
/* @0x2a808e pop {r4, pc} */
/* @0x2a8090 ldr r2, [sp, #0x100] */
/* @0x2a8092 movs r4, r2 */
/* @0x2a8094 ldr r0, [pc, #0x290] */
/* @0x2a8096 movs r6, r1 */
/* @0x2a8098 ldr r0, [pc, #0x36c] */
/* @0x2a809a movs r6, r1 */

/* ── FUNC 0x2a809c · png_set_crc_action · size=140 · insn=56 */
/* @0x2a809c push {r3, r4, r5, lr} */
/* @0x2a809e mov r5, r2 */
/* @0x2a80a0 mov r4, r0 */
/* @0x2a80a2 cmp r0, #0x0 */
/* @0x2a80a4 beq 0x2a8122 <png_set_crc_action+0x86> */
/* @0x2a80a6 subs r1, #0x2 */
/* @0x2a80a8 cmp r1, #0x3 */
/* @0x2a80aa bhi 0x2a80d4 <png_set_crc_action+0x38> */
/* @0x2a80ac tbb [pc, r1] */
/* @0x2a80b0 lsls r6, r1, #0x8 */
/* @0x2a80b2 adds r1, r1, r0 */
/* @0x2a80b4 ldr.w r3, [r0, #0x130] */
/* @0x2a80b8 bic r3, r3, #0xc00 */
/* @0x2a80bc orr r3, r3, #0x400 */
/* @0x2a80c0 b 0x2a80dc <png_set_crc_action+0x40> */
/* @0x2a80c2 ldr.w r3, [r0, #0x130] */
/* @0x2a80c4 vst4.8 {d19, d21, d23, d25}, [r3:256], r0 */
/* @0x2a80c6 orr r3, r3, #0xc00 */
/* @0x2a80c8 and r6, r7, r0, asr #6 */
/* @0x2a80ca b 0x2a80dc <png_set_crc_action+0x40> */
/* @0x2a80cc ldr r1, [pc, #0x54] */
/* @0x2a80ce add r1, pc */
/* @0x2a80d0 bl 0x2a6474 <png_warning> */
/* @0x2a80d4 ldr.w r3, [r4, #0x130] */
/* @0x2a80d8 bic r3, r3, #0xc00 */
/* @0x2a80dc str.w r3, [r4, #0x130] */
/* @0x2a80e0 subs r2, r5, #0x1 */
/* @0x2a80e2 cmp r2, #0x4 */
/* @0x2a80e4 bhi 0x2a8116 <png_set_crc_action+0x7a> */
/* @0x2a80e6 tbb [pc, r2] */
/* @0x2a80e8 strne pc, [pc], -r2 */
/* @0x2a80ea asrs r7, r1, #0x18 */
/* @0x2a80ec lsrs r3, r0, #0x8 */
/* @0x2a80ee movs r4, r3 */
/* @0x2a80f0 ldr.w r3, [r4, #0x130] */
/* @0x2a80f4 bic r3, r3, #0x300 */
/* @0x2a80f8 orr r3, r3, #0x100 */
/* @0x2a80fc b 0x2a811e <png_set_crc_action+0x82> */
/* @0x2a80fe ldr.w r3, [r4, #0x130] */
/* @0x2a8100 vst4.8 {d19, d21, d23, d25}, [r3:256], r0 */
/* @0x2a8102 orr r3, r3, #0x300 */
/* @0x2a8104 and r7, r10, r0, asr #6 */
/* @0x2a8106 b 0x2a811e <png_set_crc_action+0x82> */
/* @0x2a8108 ldr.w r3, [r4, #0x130] */
/* @0x2a810c bic r3, r3, #0x300 */
/* @0x2a8110 orr r3, r3, #0x200 */
/* @0x2a8114 b 0x2a811e <png_set_crc_action+0x82> */
/* @0x2a8116 ldr.w r3, [r4, #0x130] */
/* @0x2a8118 vld4.8 {d3, d5, d7, d9}, [r3:256], r0 */
/* @0x2a811a bic r3, r3, #0x300 */
/* @0x2a811c .word 0xf8c47340 */
/* @0x2a811e str.w r3, [r4, #0x130] */
/* @0x2a8120 ldclt p1, c3, [r8, #-192]! */
/* @0x2a8122 pop {r3, r4, r5, pc} */
/* @0x2a8124 ldr r0, [pc, #0x300] */
/* @0x2a8126 movs r6, r1 */

/* ── FUNC 0x2a8128 · png_set_background · size=92 · insn=37 */
/* @0x2a8128 push {r4, r5, lr} */
/* @0x2a812a vldr d7, [sp, #12] */
/* @0x2a812c strmi r7, [r4], -r3, lsl #22 */
/* @0x2a812e mov r4, r0 */
/* @0x2a8130 cbz r0, 0x2a817e <png_set_background+0x56> */
/* @0x2a8132 cbnz r2, 0x2a8140 <png_set_background+0x18> */
/* @0x2a8134 ldr r1, [pc, #0x48] */
/* @0x2a8136 pop.w {r4, r5, lr} */
/* @0x2a8138 ldrbtmi r4, [r9], #-48 */
/* @0x2a813a add r1, pc */
/* @0x2a813c b.w 0x2a6474 <png_warning> */
/* @0x2a8140 ldr.w r0, [r0, #0x134] */
/* @0x2a8144 vcvt.f32.f64 s14, d7 */
/* @0x2a8148 cmp r3, #0x0 */
/* @0x2a814a ite ne */
/* @0x2a814c movne.w r3, #0x100 */
/* @0x2a8150 moveq r3, #0x0 */
/* @0x2a8152 orr r0, r0, #0x80 */
/* @0x2a8154 .word 0xf8c40080 */
/* @0x2a8156 str.w r0, [r4, #0x134] */
/* @0x2a8158 stmdavs r8, {r2, r4, r5, r8} */
/* @0x2a815a ldr r0, [r1] */
/* @0x2a815c str.w r0, [r4, #0x1fc] */
/* @0x2a8160 ldr r0, [r1, #0x4] */
/* @0x2a8162 str.w r0, [r4, #0x200] */
/* @0x2a8164 stmdbhi r9, {r9} */
/* @0x2a8166 ldrh r1, [r1, #0x8] */
/* @0x2a8168 vstr s14, [r4, #504] */
/* @0x2a816c strb.w r2, [r4, #0x1f4] */
/* @0x2a8170 ldr.w r2, [r4, #0x134] */
/* @0x2a8174 strh.w r1, [r4, #0x204] */
/* @0x2a8178 orrs r2, r3 */
/* @0x2a817a str.w r2, [r4, #0x134] */
/* @0x2a817c ldclt p1, c2, [r0, #-208]! */
/* @0x2a817e pop {r4, r5, pc} */
/* @0x2a8180 ldr r0, [pc, #0x1f4] */
/* @0x2a8182 movs r6, r1 */

/* ── FUNC 0x2a8184 · png_set_strip_16 · size=16 · insn=8 */
/* @0x2a8184 cbz r0, 0x2a8192 <png_set_strip_16+0xe> */
/* @0x2a8186 ldr.w r3, [r0, #0x134] */
/* @0x2a8188 vst4.8 {d19, d21, d23, d25}, [r3:256], r4 */
/* @0x2a818a orr r3, r3, #0x400 */
/* @0x2a818c .word 0xf8c06380 */
/* @0x2a818e str.w r3, [r0, #0x134] */
/* @0x2a8190 .word 0x47703134 */
/* @0x2a8192 bx lr */

/* ── FUNC 0x2a8194 · png_set_strip_alpha · size=16 · insn=8 */
/* @0x2a8194 cbz r0, 0x2a81a2 <png_set_strip_alpha+0xe> */
/* @0x2a8196 ldr.w r3, [r0, #0x130] */
/* @0x2a8198 vst4.8 {d19, d21, d23, d25}, [r3:256], r0 */
/* @0x2a819a orr r3, r3, #0x400000 */
/* @0x2a819c .word 0xf8c00380 */
/* @0x2a819e str.w r3, [r0, #0x130] */
/* @0x2a81a0 .word 0x47703130 */
/* @0x2a81a2 bx lr */

/* ── FUNC 0x2a81a4 · png_set_quantize · size=1426 · insn=628 */
/* @0x2a81a4 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a81a8 sub sp, #0x34 */
/* @0x2a81aa mov r5, r2 */
/* @0x2a81ac mov r6, r1 */
/* @0x2a81ae ldr r2, [sp, #0x5c] */
/* @0x2a81b0 mov r4, r0 */
/* @0x2a81b2 str r3, [sp, #0x14] */
/* @0x2a81b4 ldr r7, [sp, #0x58] */
/* @0x2a81b6 str r2, [sp, #0x18] */
/* @0x2a81b8 cmp r0, #0x0 */
/* @0x2a81ba beq.w 0x2a8730 <png_set_quantize+0x58c> */
/* @0x2a81bc .word 0xf8d082b9 */
/* @0x2a81be ldr.w r3, [r0, #0x134] */
/* @0x2a81c0 .word 0xf0433134 */
/* @0x2a81c2 orr r3, r3, #0x40 */
/* @0x2a81c4 .word 0xf8c00340 */
/* @0x2a81c6 str.w r3, [r0, #0x134] */
/* @0x2a81c8 tstlt r10, r4, lsr r1 */
/* @0x2a81ca cbz r2, 0x2a81d4 <png_set_quantize+0x30> */
/* @0x2a81cc ldr r3, [sp, #0x14] */
/* @0x2a81ce cmp r5, r3 */
/* @0x2a81d0 bgt 0x2a81ee <png_set_quantize+0x4a> */
/* @0x2a81d2 b 0x2a8610 <png_set_quantize+0x46c> */
/* @0x2a81d4 mov r1, r5 */
/* @0x2a81d6 bl 0x2a6ca0 <png_malloc> */
/* @0x2a81d8 blls 0x46776c <g_RomDisk+0x6ff4c> */
/* @0x2a81da ldr r3, [sp, #0x18] */
/* @0x2a81dc str.w r0, [r4, #0x2b4] */
/* @0x2a81e0 cmp r3, r5 */
/* @0x2a81e2 bge 0x2a81cc <png_set_quantize+0x28> */
/* @0x2a81e4 ldr.w r2, [r4, #0x2b4] */
/* @0x2a81e8 strb r3, [r2, r3] */
/* @0x2a81ea adds r3, #0x1 */
/* @0x2a81ec b 0x2a81e0 <png_set_quantize+0x3c> */
/* @0x2a81ee mov r0, r4 */
/* @0x2a81f0 mov r1, r5 */
/* @0x2a81f2 cmp r7, #0x0 */
/* @0x2a81f4 beq.w 0x2a83ca <png_set_quantize+0x226> */
/* @0x2a81f8 bl 0x2a6ca0 <png_malloc> */
/* @0x2a81fc movs r3, #0x0 */
/* @0x2a81fe str.w r0, [r4, #0x2f8] */
/* @0x2a8200 adcmi r0, r11, #248, #4 */
/* @0x2a8202 cmp r3, r5 */
/* @0x2a8204 bge 0x2a8210 <png_set_quantize+0x6c> */
/* @0x2a8206 ldr.w r2, [r4, #0x2f8] */
/* @0x2a8208 ldrbpl r2, [r3], #760 */
/* @0x2a820a strb r3, [r2, r3] */
/* @0x2a820c adds r3, #0x1 */
/* @0x2a820e b 0x2a8202 <png_set_quantize+0x5e> */
/* @0x2a8210 subs r2, r5, #0x1 */
/* @0x2a8212 ldr.w r10, [sp, #0x14] */
/* @0x2a8214 ldrbmi r10, [r2, #-0x14] */
/* @0x2a8216 cmp r2, r10 */
/* @0x2a8218 bge 0x2a822a <png_set_quantize+0x86> */
/* @0x2a821a ldr r7, [sp, #0x18] */
/* @0x2a821c cbnz r7, 0x2a826c <png_set_quantize+0xc8> */
/* @0x2a821e mov r3, r6 */
/* @0x2a8220 mov r1, r5 */
/* @0x2a8222 ldr r2, [sp, #0x18] */
/* @0x2a8224 mov.w lr, #0x3 */
/* @0x2a8228 b 0x2a82bc <png_set_quantize+0x118> */
/* @0x2a822a movs r3, #0x0 */
/* @0x2a822c mov.w lr, #0x1 */
/* @0x2a8230 cmp r3, r2 */
/* @0x2a8232 bge 0x2a8262 <png_set_quantize+0xbe> */
/* @0x2a8234 ldr.w r0, [r4, #0x2f8] */
/* @0x2a8238 adds r1, r3, #0x1 */
/* @0x2a823a ldrb.w r12, [r0, r3] */
/* @0x2a823c .word 0xf810c003 */
/* @0x2a823e ldrb.w r8, [r0, r1] */
/* @0x2a8240 rfeda r7! */
/* @0x2a8242 ldrh.w r10, [r7, r12, lsl #1] */
/* @0x2a8244 rfeda r7! */
/* @0x2a8246 ldrh.w r9, [r7, r8, lsl #1] */
/* @0x2a8248 strbmi r9, [r10, #0x18] */
/* @0x2a824a cmp r10, r9 */
/* @0x2a824c bhs 0x2a825e <png_set_quantize+0xba> */
/* @0x2a824e strb.w r8, [r0, r3] */
/* @0x2a8250 .word 0xf04f8003 */
/* @0x2a8252 mov.w lr, #0x0 */
/* @0x2a8254 .word 0xf8d40e00 */
/* @0x2a8256 ldr.w r3, [r4, #0x2f8] */
/* @0x2a8258 .word 0xf80332f8 */
/* @0x2a825a strb.w r12, [r3, r1] */
/* @0x2a825c strmi r12, [r11], -r1 */
/* @0x2a825e mov r3, r1 */
/* @0x2a8260 b 0x2a8230 <png_set_quantize+0x8c> */
/* @0x2a8262 cmp.w lr, #0x0 */
/* @0x2a8264 bicsle r0, r8, r0, lsl #30 */
/* @0x2a8266 bne 0x2a821a <png_set_quantize+0x76> */
/* @0x2a8268 subs r2, #0x1 */
/* @0x2a826a b 0x2a8212 <png_set_quantize+0x6e> */
/* @0x2a826c movs r3, #0x0 */
/* @0x2a826e movs r2, #0x3 */
/* @0x2a8270 ldr r7, [sp, #0x14] */
/* @0x2a8272 cmp r3, r7 */
/* @0x2a8274 bge 0x2a82ca <png_set_quantize+0x126> */
/* @0x2a8276 ldr.w r1, [r4, #0x2f8] */
/* @0x2a8278 .word 0xf8dd12f8 */
/* @0x2a827a ldr.w r11, [sp, #0x14] */
/* @0x2a827c stclpl p0, c11, [r8], {20} */
/* @0x2a827e ldrb r0, [r1, r3] */
/* @0x2a8280 cmp r0, r11 */
/* @0x2a8282 blt 0x2a82a6 <png_set_quantize+0x102> */
/* @0x2a8284 subs r5, #0x1 */
/* @0x2a8286 ldr.w r12, [sp, #0x14] */
/* @0x2a8288 stclpl p0, c12, [r8, #-80] */
/* @0x2a828a ldrb r0, [r1, r5] */
/* @0x2a828c cmp r0, r12 */
/* @0x2a828e bge 0x2a8284 <png_set_quantize+0xe0> */
/* @0x2a8290 mla r1, r2, r5, r6 */
/* @0x2a8294 mul r0, r2, r3 */
/* @0x2a8298 ldrh.w lr, [r1] */
/* @0x2a829c adds r7, r6, r0 */
/* @0x2a829e strh.w lr, [r6, r0] */
/* @0x2a82a0 stmvc r9, {sp, lr, pc} */
/* @0x2a82a2 ldrb r1, [r1, #0x2] */
/* @0x2a82a4 strb r1, [r7, #0x2] */
/* @0x2a82a6 adds r3, #0x1 */
/* @0x2a82a8 b 0x2a8270 <png_set_quantize+0xcc> */
/* @0x2a82aa ldr.w r0, [r4, #0x2f8] */
/* @0x2a82ac .word 0xf8dd02f8 */
/* @0x2a82ae ldr.w r10, [sp, #0x14] */
/* @0x2a82b0 stcpl p0, c10, [r7], {20} */
/* @0x2a82b2 ldrb r7, [r0, r2] */
/* @0x2a82b4 cmp r7, r10 */
/* @0x2a82b6 bge 0x2a82dc <png_set_quantize+0x138> */
/* @0x2a82b8 adds r2, #0x1 */
/* @0x2a82ba adds r3, #0x3 */
/* @0x2a82bc ldr.w r12, [sp, #0x14] */
/* @0x2a82c0 cmp r2, r12 */
/* @0x2a82c2 blt 0x2a82aa <png_set_quantize+0x106> */
/* @0x2a82c4 movs r3, #0x0 */
/* @0x2a82c6 cmp r3, r5 */
/* @0x2a82c8 blt 0x2a8320 <png_set_quantize+0x17c> */
/* @0x2a82ca mov r0, r4 */
/* @0x2a82cc ldr.w r1, [r4, #0x2f8] */
/* @0x2a82d0 bl 0x2a6cfc <png_free> */
/* @0x2a82d4 movs r3, #0x0 */
/* @0x2a82d6 str.w r3, [r4, #0x2f8] */
/* @0x2a82d8 ldrsh r3, [r8, r8] */
/* @0x2a82da b 0x2a860e <png_set_quantize+0x46a> */
/* @0x2a82dc subs r1, #0x1 */
/* @0x2a82de ldr.w r11, [sp, #0x14] */
/* @0x2a82e0 mcrrpl p0, #0x1, r11, r7, c4 */
/* @0x2a82e2 ldrb r7, [r0, r1] */
/* @0x2a82e4 cmp r7, r11 */
/* @0x2a82e6 bge 0x2a82dc <png_set_quantize+0x138> */
/* @0x2a82e8 mul r7, lr, r1 */
/* @0x2a82ec ldrh.w r10, [r3] */
/* @0x2a82f0 adds r0, r6, r7 */
/* @0x2a82f2 ldrb.w r9, [r6, r7] */
/* @0x2a82f4 .word 0xf8909007 */
/* @0x2a82f6 ldrb.w r12, [r0, #0x2] */
/* @0x2a82f8 .word 0xf890c002 */
/* @0x2a82fa ldrb.w r8, [r0, #0x1] */
/* @0x2a82fc .word 0xf8268001 */
/* @0x2a82fe strh.w r10, [r6, r7] */
/* @0x2a8300 ldmvc pc, {r0, r1, r2, sp, pc} */
/* @0x2a8302 ldrb r7, [r3, #0x2] */
/* @0x2a8304 strb r7, [r0, #0x2] */
/* @0x2a8306 strb.w r9, [r3] */
/* @0x2a8308 .word 0xf8839000 */
/* @0x2a830a strb.w r8, [r3, #0x1] */
/* @0x2a830c .word 0xf8838001 */
/* @0x2a830e strb.w r12, [r3, #0x2] */
/* @0x2a8310 .word 0xf8d4c002 */
/* @0x2a8312 ldr.w r0, [r4, #0x2b4] */
/* @0x2a8314 strbpl r0, [r2], #-692 */
/* @0x2a8316 strb r2, [r0, r1] */
/* @0x2a8318 ldr.w r0, [r4, #0x2b4] */
/* @0x2a831c strb r1, [r0, r2] */
/* @0x2a831e b 0x2a82b8 <png_set_quantize+0x114> */
/* @0x2a8320 ldr.w r2, [r4, #0x2b4] */
/* @0x2a8324 ldr r7, [sp, #0x14] */
/* @0x2a8326 add.w r9, r2, r3 */
/* @0x2a8328 ldclpl p9, c0, [r2], {3} */
/* @0x2a832a ldrb r2, [r2, r3] */
/* @0x2a832c cmp r2, r7 */
/* @0x2a832e blt 0x2a83c6 <png_set_quantize+0x222> */
/* @0x2a8330 add.w r2, r2, r2, lsl #1 */
/* @0x2a8334 ldrb r0, [r6] */
/* @0x2a8336 adds r1, r6, r2 */
/* @0x2a8338 movs r7, #0x0 */
/* @0x2a833a ldrb.w lr, [r6, r2] */
/* @0x2a833c .word 0xf891e002 */
/* @0x2a833e ldrb.w r12, [r1, #0x1] */
/* @0x2a8340 ldmdavc r2!, {r0, lr, pc} ^ */
/* @0x2a8342 ldrb r2, [r6, #0x1] */
/* @0x2a8344 rsb r0, r0, lr */
/* @0x2a8348 cmp r0, #0x0 */
/* @0x2a834a it lt */
/* @0x2a834c rsblt r0, r0, #0 */
/* @0x2a834e ldrb.w r8, [r1, #0x2] */
/* @0x2a8350 bl 0xff348360 <b2_toiTime+0xfffffffffebeeebc> */
/* @0x2a8352 rsb r2, r2, r12 */
/* @0x2a8354 .word 0x2101020c */
/* @0x2a8356 movs r1, #0x1 */
/* @0x2a8358 cmp r2, #0x0 */
/* @0x2a835a it lt */
/* @0x2a835c rsblt r2, r2, #0 */
/* @0x2a835e add r0, r2 */
/* @0x2a8360 ldrb r2, [r6, #0x2] */
/* @0x2a8362 rsb r2, r2, r8 */
/* @0x2a8364 bhs 0x2a8b8c <png_do_unpack+0x5e> */
/* @0x2a8366 cmp r2, #0x0 */
/* @0x2a8368 it lt */
/* @0x2a836a rsblt r2, r2, #0 */
/* @0x2a836c add r0, r2 */
/* @0x2a836e mov r2, r6 */
/* @0x2a8370 ldr.w r10, [sp, #0x14] */
/* @0x2a8374 cmp r1, r10 */
/* @0x2a8376 bge 0x2a83c2 <png_set_quantize+0x21e> */
/* @0x2a8378 ldrb.w r11, [r2, #0x3] */
/* @0x2a837c adds r2, #0x3 */
/* @0x2a837e ldrb.w r10, [r2, #0x1] */
/* @0x2a8380 bl 0xff59038c <b2_toiTime+0xfffffffffee36ee8> */
/* @0x2a8382 rsb r11, r11, lr */
/* @0x2a8384 bl 0xff52afc4 <b2_toiTime+0xfffffffffedd1b20> */
/* @0x2a8386 rsb r10, r10, r12 */
/* @0x2a8388 .word 0xf1bb0a0c */
/* @0x2a838a cmp.w r11, #0x0 */
/* @0x2a838c svclt #0xb80f00 */
/* @0x2a838e it lt */
/* @0x2a8390 rsblt.w r11, r11, #0x0 */
/* @0x2a8394 cmp.w r10, #0x0 */
/* @0x2a8398 it lt */
/* @0x2a839a rsblt.w r10, r10, #0x0 */
/* @0x2a839c ldrbmi r0, [r3], #2560 */
/* @0x2a839e add r11, r10 */
/* @0x2a83a0 ldrb.w r10, [r2, #0x2] */
/* @0x2a83a4 rsb r10, r10, r8 */
/* @0x2a83a8 cmp.w r10, #0x0 */
/* @0x2a83ac it lt */
/* @0x2a83ae rsblt.w r10, r10, #0x0 */
/* @0x2a83b0 ldrbmi r0, [r10], #2560 */
/* @0x2a83b2 add r10, r11 */
/* @0x2a83b4 cmp r10, r0 */
/* @0x2a83b6 ite ge */
/* @0x2a83b8 movge r10, r0 */
/* @0x2a83ba movlt r7, r1 */
/* @0x2a83bc mov r0, r10 */
/* @0x2a83be adds r1, #0x1 */
/* @0x2a83c0 b 0x2a8370 <png_set_quantize+0x1cc> */
/* @0x2a83c2 strb.w r7, [r9] */
/* @0x2a83c4 movwlo r7, #0x1000 */
/* @0x2a83c6 adds r3, #0x1 */
/* @0x2a83c8 b 0x2a82c6 <png_set_quantize+0x122> */
/* @0x2a83ca bl 0x2a6ca0 <png_malloc> */
/* @0x2a83cc strtmi pc, [r9], -r9, ror #24 */
/* @0x2a83ce mov r1, r5 */
/* @0x2a83d0 str.w r0, [r4, #0x2fc] */
/* @0x2a83d4 mov r0, r4 */
/* @0x2a83d6 bl 0x2a6ca0 <png_malloc> */
/* @0x2a83d8 .word 0xf8c4fc63 */
/* @0x2a83da str.w r0, [r4, #0x300] */
/* @0x2a83dc adcmi r0, pc, #0, #6 */
/* @0x2a83de cmp r7, r5 */
/* @0x2a83e0 bge 0x2a83f4 <png_set_quantize+0x250> */
/* @0x2a83e2 ldr.w r2, [r4, #0x2fc] */
/* @0x2a83e4 rscslt r2, r11, #252, #4 */
/* @0x2a83e6 uxtb r3, r7 */
/* @0x2a83e8 strb r3, [r2, r7] */
/* @0x2a83ea ldr.w r2, [r4, #0x300] */
/* @0x2a83ec ldrbpl r2, [r3, #0x300] */
/* @0x2a83ee strb r3, [r2, r7] */
/* @0x2a83f0 adds r7, #0x1 */
/* @0x2a83f2 b 0x2a83de <png_set_quantize+0x23a> */
/* @0x2a83f4 mov r0, r4 */
/* @0x2a83f6 movw r1, #0xc04 */
/* @0x2a83f8 .word 0xf7fe4104 */
/* @0x2a83fa bl 0x2a6cd8 <png_calloc> */
/* @0x2a83fc strtmi pc, [pc], -sp, ror #24 */
/* @0x2a83fe mov r7, r5 */
/* @0x2a8400 mov.w r8, #0x0 */
/* @0x2a8404 mov.w r11, #0x60 */
/* @0x2a8408 str.w r11, [sp, #0x20] */
/* @0x2a840c str r0, [sp, #0x1c] */
/* @0x2a840e mov r9, r6 */
/* @0x2a8410 mov.w r10, #0x0 */
/* @0x2a8414 subs r2, r7, #0x1 */
/* @0x2a8416 str r2, [sp, #0x24] */
/* @0x2a8418 ldr r3, [sp, #0x24] */
/* @0x2a841a cmp r10, r3 */
/* @0x2a841c bge 0x2a84b2 <png_set_quantize+0x30e> */
/* @0x2a841e add.w r10, r10, #0x1 */
/* @0x2a8420 strbmi r0, [r11], r1, lsl #20 */
/* @0x2a8422 mov r11, r9 */
/* @0x2a8424 add.w r12, r10, #0xffffffff */
/* @0x2a8428 mov r3, r10 */
/* @0x2a842a cmp r3, r7 */
/* @0x2a842c beq 0x2a84a6 <png_set_quantize+0x302> */
/* @0x2a842e ldrb.w r2, [r11, #0x3] */
/* @0x2a8430 .word 0xf8992003 */
/* @0x2a8432 ldrb.w r1, [r9] */
/* @0x2a8434 .word 0xf8991000 */
/* @0x2a8436 ldrb.w r0, [r9, #0x1] */
/* @0x2a8438 bne 0xfe4e8444 <b2_toiTime+0xfffffffffdd8efa0> */
/* @0x2a843a subs r1, r1, r2 */
/* @0x2a843c ldrb.w r2, [r11, #0x4] */
/* @0x2a8440 cmp r1, #0x0 */
/* @0x2a8442 it lt */
/* @0x2a8444 rsblt r1, r1, #0 */
/* @0x2a8446 subs r2, r0, r2 */
/* @0x2a8448 ldrb.w r0, [r9, #0x2] */
/* @0x2a844c cmp r2, #0x0 */
/* @0x2a844e it lt */
/* @0x2a8450 rsblt r2, r2, #0 */
/* @0x2a8452 add r2, r1 */
/* @0x2a8454 ldrb.w r1, [r11, #0x5] */
/* @0x2a8458 subs r1, r0, r1 */
/* @0x2a845a ldr r0, [sp, #0x20] */
/* @0x2a845c cmp r1, #0x0 */
/* @0x2a845e it lt */
/* @0x2a8460 rsblt r1, r1, #0 */
/* @0x2a8462 add r2, r1 */
/* @0x2a8464 cmp r2, r0 */
/* @0x2a8466 bgt 0x2a849e <png_set_quantize+0x2fa> */
/* @0x2a8468 mov r0, r4 */
/* @0x2a846a movs r1, #0x8 */
/* @0x2a846c str r2, [sp, #0x10] */
/* @0x2a846e str r3, [sp, #0x8] */
/* @0x2a8470 str.w r12, [sp, #0xc] */
/* @0x2a8474 bl 0x2a6d16 <png_malloc_warn> */
/* @0x2a8478 ldr r2, [sp, #0x10] */
/* @0x2a847a ldr r3, [sp, #0x8] */
/* @0x2a847c ldr.w r12, [sp, #0xc] */
/* @0x2a8480 mov r8, r0 */
/* @0x2a8482 cmp r0, #0x0 */
/* @0x2a8484 beq.w 0x2a872a <png_set_quantize+0x586> */
/* @0x2a8488 ldr r0, [sp, #0x1c] */
/* @0x2a848a ldr.w r1, [r0, r2, lsl #2] */
/* @0x2a848c .word 0xf8881022 */
/* @0x2a848e strb.w r12, [r8, #0x4] */
/* @0x2a8490 .word 0xf888c004 */
/* @0x2a8492 strb.w r3, [r8, #0x5] */
/* @0x2a8494 .word 0xf8c83005 */
/* @0x2a8496 str.w r1, [r8] */
/* @0x2a8498 .word 0xf8401000 */
/* @0x2a849a str.w r8, [r0, r2, lsl #2] */
/* @0x2a849c movwlo r8, #0x1022 */
/* @0x2a849e adds r3, #0x1 */
/* @0x2a84a0 add.w r11, r11, #0x3 */
/* @0x2a84a4 b 0x2a842a <png_set_quantize+0x286> */
/* @0x2a84a6 add.w r9, r9, #0x3 */
/* @0x2a84a8 .word 0xf1b80903 */
/* @0x2a84aa cmp.w r8, #0x0 */
/* @0x2a84ac .word 0xd1b30f00 */
/* @0x2a84ae bne 0x2a8418 <png_set_quantize+0x274> */
/* @0x2a84b0 b 0x2a872a <png_set_quantize+0x586> */
/* @0x2a84b2 cmp.w r8, #0x0 */
/* @0x2a84b4 rsbsle r0, r0, r0, lsl #30 */
/* @0x2a84b6 beq 0x2a859a <png_set_quantize+0x3f6> */
/* @0x2a84b8 movs r0, #0x0 */
/* @0x2a84ba ldr r2, [sp, #0x1c] */
/* @0x2a84bc ldr.w r1, [r2, r0, lsl #2] */
/* @0x2a84c0 cmp r1, #0x0 */
/* @0x2a84c2 beq 0x2a8590 <png_set_quantize+0x3ec> */
/* @0x2a84c4 ldr.w r2, [r4, #0x2fc] */
/* @0x2a84c8 ldrb.w lr, [r1, #0x4] */
/* @0x2a84cc ldrb.w r3, [r2, lr] */
/* @0x2a84d0 cmp r3, r7 */
/* @0x2a84d2 bge 0x2a8586 <png_set_quantize+0x3e2> */
/* @0x2a84d4 ldrb.w r11, [r1, #0x5] */
/* @0x2a84d8 ldrb.w r3, [r2, r11] */
/* @0x2a84dc cmp r3, r7 */
/* @0x2a84de bge 0x2a8586 <png_set_quantize+0x3e2> */
/* @0x2a84e0 lsls r3, r7, #0x1f */
/* @0x2a84e2 add.w r7, r7, #0xffffffff */
/* @0x2a84e4 .word 0xf04f37ff */
/* @0x2a84e6 mov.w r10, #0x3 */
/* @0x2a84e8 svclt #0x560a03 */
/* @0x2a84ea itet pl */
/* @0x2a84ec movpl r3, r11 */
/* @0x2a84ee movmi r3, lr */
/* @0x2a84f0 movpl r11, lr */
/* @0x2a84f2 ldrb.w lr, [r2, r3] */
/* @0x2a84f4 blx 0x56050a <g_SWFlineaavertbuff+0xd442> */
/* @0x2a84f6 mla r2, r10, r7, r6 */
/* @0x2a84f8 bl 0x640d1c <g_SWFaavertbuff+0x6dc54> */
/* @0x2a84fa add.w lr, lr, lr, lsl #1 */
/* @0x2a84fc bl 0x42be3c <g_RomDisk+0x3461c> */
/* @0x2a84fe add.w r12, r6, lr */
/* @0x2a8500 rfeia r2! */
/* @0x2a8502 ldrh.w r9, [r2] */
/* @0x2a8504 .word 0xf8269000 */
/* @0x2a8506 strh.w r9, [r6, lr] */
/* @0x2a8508 ldmvc r2, {r1, r2, r3, r12, pc} */
/* @0x2a850a ldrb r2, [r2, #0x2] */
/* @0x2a850c strb.w r2, [r12, #0x2] */
/* @0x2a8510 ldr r2, [sp, #0x18] */
/* @0x2a8512 cbz r2, 0x2a8546 <png_set_quantize+0x3a2> */
/* @0x2a8514 ldr.w lr, [r4, #0x2fc] */
/* @0x2a8518 ldr.w r2, [r4, #0x300] */
/* @0x2a851c ldrb.w r12, [lr, r3] */
/* @0x2a8520 ldrb r2, [r2, r7] */
/* @0x2a8522 strb.w r12, [lr, r2] */
/* @0x2a8524 .word 0xf8d4c002 */
/* @0x2a8526 ldr.w lr, [r4, #0x300] */
/* @0x2a8528 .word 0xf8d4e300 */
/* @0x2a852a ldr.w r2, [r4, #0x2fc] */
/* @0x2a852c .word 0xf81e22fc */
/* @0x2a852e ldrb.w r12, [lr, r7] */
/* @0x2a8530 ldclpl p0, c12, [r2], {7} */
/* @0x2a8532 ldrb r2, [r2, r3] */
/* @0x2a8534 strb.w r12, [lr, r2] */
/* @0x2a8538 ldr.w r2, [r4, #0x2fc] */
/* @0x2a853c strb r7, [r2, r3] */
/* @0x2a853e ldr.w r2, [r4, #0x300] */
/* @0x2a8540 ldrbpl r2, [r3, #0x300] */
/* @0x2a8542 strb r3, [r2, r7] */
/* @0x2a8544 b 0x2a8586 <png_set_quantize+0x3e2> */
/* @0x2a8546 ldr.w lr, [sp, #0x18] */
/* @0x2a8548 strmi lr, [lr, #0x18]! */
/* @0x2a854a cmp lr, r5 */
/* @0x2a854c bge 0x2a8514 <png_set_quantize+0x370> */
/* @0x2a854e ldr.w r12, [r4, #0x2fc] */
/* @0x2a8550 .word 0xf8d4c2fc */
/* @0x2a8552 ldr.w r2, [r4, #0x2b4] */
/* @0x2a8554 .word 0xf81c22b4 */
/* @0x2a8556 ldrb.w r9, [r12, r3] */
/* @0x2a8558 .word 0xf8129003 */
/* @0x2a855a ldrb.w r10, [r2, lr] */
/* @0x2a855c strbmi r10, [r10, #0xe] */
/* @0x2a855e cmp r10, r9 */
/* @0x2a8560 itt eq */
/* @0x2a8562 ldrbeq.w r12, [r12, r11] */
/* @0x2a8564 .word 0xf802c00b */
/* @0x2a8566 strbeq.w r12, [r2, lr] */
/* @0x2a8568 .word 0xf8d4c00e */
/* @0x2a856a ldr.w r12, [r4, #0x2b4] */
/* @0x2a856c .word 0xf81cc2b4 */
/* @0x2a856e ldrb.w r2, [r12, lr] */
/* @0x2a8570 adcsmi r2, r10, #14 */
/* @0x2a8572 cmp r2, r7 */
/* @0x2a8574 bne 0x2a8580 <png_set_quantize+0x3dc> */
/* @0x2a8576 ldr.w r2, [r4, #0x2fc] */
/* @0x2a8578 ldclpl p2, c2, [r2], {252} */
/* @0x2a857a ldrb r2, [r2, r3] */
/* @0x2a857c strb.w r2, [r12, lr] */
/* @0x2a8580 add.w lr, lr, #0x1 */
/* @0x2a8584 b 0x2a854a <png_set_quantize+0x3a6> */
/* @0x2a8586 ldr r3, [sp, #0x14] */
/* @0x2a8588 cmp r7, r3 */
/* @0x2a858a ble 0x2a859a <png_set_quantize+0x3f6> */
/* @0x2a858c ldr r1, [r1] */
/* @0x2a858e b 0x2a84c0 <png_set_quantize+0x31c> */
/* @0x2a8590 ldr.w r10, [sp, #0x20] */
/* @0x2a8594 adds r0, #0x1 */
/* @0x2a8596 cmp r0, r10 */
/* @0x2a8598 ble 0x2a84ba <png_set_quantize+0x316> */
/* @0x2a859a mov.w r9, #0x0 */
/* @0x2a859c .word 0xf6400900 */
/* @0x2a859e movw r11, #0xc04 */
/* @0x2a85a0 strbmi r4, [r11], -r4, lsl #22 */
/* @0x2a85a2 mov r3, r9 */
/* @0x2a85a4 ldr.w r12, [sp, #0x1c] */
/* @0x2a85a8 ldr.w r1, [r12, r9] */
/* @0x2a85ac cbz r1, 0x2a85c6 <png_set_quantize+0x422> */
/* @0x2a85ae ldr.w r8, [r1] */
/* @0x2a85b0 strtmi r8, [r0], -r0 */
/* @0x2a85b2 mov r0, r4 */
/* @0x2a85b4 str r3, [sp, #0x8] */
/* @0x2a85b6 bl 0x2a6cfc <png_free> */
/* @0x2a85b8 blls 0x367444 <_ZTS12CDS_Priority+0x949c> */
/* @0x2a85ba ldr r3, [sp, #0x8] */
/* @0x2a85bc cmp.w r8, #0x0 */
/* @0x2a85c0 beq 0x2a85c6 <png_set_quantize+0x422> */
/* @0x2a85c2 mov r1, r8 */
/* @0x2a85c4 b 0x2a85ae <png_set_quantize+0x40a> */
/* @0x2a85c6 ldr r2, [sp, #0x1c] */
/* @0x2a85c8 mov.w r10, #0x0 */
/* @0x2a85cc str.w r3, [r2, r9] */
/* @0x2a85d0 add.w r9, r9, #0x4 */
/* @0x2a85d4 cmp r9, r11 */
/* @0x2a85d6 bne 0x2a85a4 <png_set_quantize+0x400> */
/* @0x2a85d8 ldr.w r11, [sp, #0x14] */
/* @0x2a85dc ldr r3, [sp, #0x20] */
/* @0x2a85de cmp r7, r11 */
/* @0x2a85e0 add.w r3, r3, #0x60 */
/* @0x2a85e4 str r3, [sp, #0x20] */
/* @0x2a85e6 bgt.w 0x2a840e <png_set_quantize+0x26a> */
/* @0x2a85e8 sadd16mi r10, r1, r2 */
/* @0x2a85ea mov r1, r2 */
/* @0x2a85ec mov r0, r4 */
/* @0x2a85ee bl 0x2a6cfc <png_free> */
/* @0x2a85f0 strtmi pc, [r0], -r5, lsl #23 */
/* @0x2a85f2 mov r0, r4 */
/* @0x2a85f4 ldr.w r1, [r4, #0x300] */
/* @0x2a85f8 bl 0x2a6cfc <png_free> */
/* @0x2a85fc mov r0, r4 */
/* @0x2a85fe ldr.w r1, [r4, #0x2fc] */
/* @0x2a8600 .word 0xf7fe12fc */
/* @0x2a8602 bl 0x2a6cfc <png_free> */
/* @0x2a8604 .word 0xf8c4fb7b */
/* @0x2a8606 str.w r10, [r4, #0x300] */
/* @0x2a8608 .word 0xf8c4a300 */
/* @0x2a860a str.w r10, [r4, #0x2fc] */
/* @0x2a860c stcls p2, c10, [r5, #-1008] */
/* @0x2a860e ldr r5, [sp, #0x14] */
/* @0x2a8610 ldr.w r3, [r4, #0x1d8] */
/* @0x2a8614 cbnz r3, 0x2a861a <png_set_quantize+0x476> */
/* @0x2a8616 str.w r6, [r4, #0x1d8] */
/* @0x2a8618 bls 0x440d80 <g_RomDisk+0x49560> */
/* @0x2a861a ldr r2, [sp, #0x18] */
/* @0x2a861c strh.w r5, [r4, #0x1dc] */
/* @0x2a8620 cmp r2, #0x0 */
/* @0x2a8622 beq.w 0x2a8730 <png_set_quantize+0x58c> */
/* @0x2a8624 vst4.32 {d24, d25, d26, d27}, [pc], r5 */
/* @0x2a8626 mov.w r1, #0x8000 */
/* @0x2a8628 strtmi r4, [r0], -r0, lsl #2 */
/* @0x2a862a mov r0, r4 */
/* @0x2a862c bl 0x2a6cd8 <png_calloc> */
/* @0x2a8630 mov.w r1, #0x8000 */
/* @0x2a8634 str.w r0, [r4, #0x2b0] */
/* @0x2a8638 mov r0, r4 */
/* @0x2a863a bl 0x2a6ca0 <png_malloc> */
/* @0x2a863c mvnshs pc, r1, lsr r11 */
/* @0x2a863e movs r1, #0xff */
/* @0x2a8640 mov.w r2, #0x8000 */
/* @0x2a8644 mov r9, r0 */
/* @0x2a8646 blx 0xb65b0 <memset@plt> */
/* @0x2a8648 .word 0xf04fefb4 */
/* @0x2a864a mov.w r12, #0x0 */
/* @0x2a864c strbtmi r0, [r0], r0, lsl #24 */
/* @0x2a864e mov r8, r12 */
/* @0x2a8650 cmp r8, r5 */
/* @0x2a8652 bge 0x2a871c <png_set_quantize+0x578> */
/* @0x2a8654 ldrb.w r3, [r6, r12] */
/* @0x2a8658 lsrs r3, r3, #0x3 */
/* @0x2a865a str r3, [sp, #0x14] */
/* @0x2a865c add.w r3, r6, r12 */
/* @0x2a8660 ldrb r2, [r3, #0x1] */
/* @0x2a8662 ldrb r3, [r3, #0x2] */
/* @0x2a8664 lsrs r2, r2, #0x3 */
/* @0x2a8666 str r2, [sp, #0x18] */
/* @0x2a8668 lsrs r3, r3, #0x3 */
/* @0x2a866a str r3, [sp, #0x1c] */
/* @0x2a866c movs r3, #0x0 */
/* @0x2a866e ldr r7, [sp, #0x14] */
/* @0x2a8670 cmp r3, r7 */
/* @0x2a8672 ble 0x2a867e <png_set_quantize+0x4da> */
/* @0x2a8674 rsb r10, r7, r3 */
/* @0x2a8678 str.w r10, [sp, #0x4] */
/* @0x2a867c b 0x2a868a <png_set_quantize+0x4e6> */
/* @0x2a867e ldr.w r11, [sp, #0x14] */
/* @0x2a8680 bl 0xff3946d8 <b2_toiTime+0xfffffffffec3b234> */
/* @0x2a8682 rsb r11, r3, r11 */
/* @0x2a8684 .word 0xf8cd0b0b */
/* @0x2a8686 str.w r11, [sp, #0x4] */
/* @0x2a8688 andhs r11, r0, #4 */
/* @0x2a868a movs r2, #0x0 */
/* @0x2a868c lsls r0, r3, #0xa */
/* @0x2a868e str r0, [sp, #0x20] */
/* @0x2a8690 ldr r1, [sp, #0x18] */
/* @0x2a8692 ldr.w r10, [sp, #0x4] */
/* @0x2a8694 addmi r10, r10, #4 */
/* @0x2a8696 cmp r2, r1 */
/* @0x2a8698 ldr.w r11, [sp, #0x4] */
/* @0x2a869c itee gt */
/* @0x2a869e rsbgt r0, r1, r2 */
/* @0x2a86a0 svcls #0x60002 */
/* @0x2a86a2 ldrle r7, [sp, #0x18] */
/* @0x2a86a4 rsble r0, r2, r7 */
/* @0x2a86a8 movs r7, #0x0 */
/* @0x2a86aa add r10, r0 */
/* @0x2a86ac cmp r0, r11 */
/* @0x2a86ae it ge */
/* @0x2a86b0 movge r11, r0 */
/* @0x2a86b2 ldr r0, [sp, #0x20] */
/* @0x2a86b4 str.w r10, [sp, #0x24] */
/* @0x2a86b8 orr.w r0, r0, r2, lsl #5 */
/* @0x2a86bc str.w r11, [sp, #0x28] */
/* @0x2a86c0 str r0, [sp, #0x2c] */
/* @0x2a86c2 ldr.w r10, [sp, #0x1c] */
/* @0x2a86c4 stmdbls r11, {r2, r3, r4, sp, pc} */
/* @0x2a86c6 ldr r1, [sp, #0x2c] */
/* @0x2a86c8 cmp r7, r10 */
/* @0x2a86ca orr.w r0, r7, r1 */
/* @0x2a86cc stmdbls r10, {r0} */
/* @0x2a86ce ldr r1, [sp, #0x28] */
/* @0x2a86d0 itet le */
/* @0x2a86d2 ldrle.w r11, [sp, #0x1c] */
/* @0x2a86d4 bl 0xff55474c <b2_toiTime+0xfffffffffedfb2a8> */
/* @0x2a86d6 rsbgt r10, r10, r7 */
/* @0x2a86d8 bl 0xff46aefc <b2_toiTime+0xfffffffffed11a58> */
/* @0x2a86da rsble r10, r7, r11 */
/* @0x2a86dc .word 0xf8dd0a0b */
/* @0x2a86de ldr.w r11, [sp, #0x24] */
/* @0x2a86e0 strmi r11, [r10, #0x24] */
/* @0x2a86e2 cmp r10, r1 */
/* @0x2a86e4 ite ge */
/* @0x2a86e6 addge r11, r10 */
/* @0x2a86e8 addlt r11, r1 */
/* @0x2a86ea add r10, r11 */
/* @0x2a86ec ldrb.w r11, [r9, r0] */
/* @0x2a86f0 cmp r10, r11 */
/* @0x2a86f2 bge 0x2a8700 <png_set_quantize+0x55c> */
/* @0x2a86f4 strb.w r10, [r9, r0] */
/* @0x2a86f8 ldr.w r1, [r4, #0x2b0] */
/* @0x2a86fc strb.w r8, [r1, r0] */
/* @0x2a8700 adds r7, #0x1 */
/* @0x2a8702 cmp r7, #0x20 */
/* @0x2a8704 bne 0x2a86c2 <png_set_quantize+0x51e> */
/* @0x2a8706 adds r2, #0x1 */
/* @0x2a8708 cmp r2, #0x20 */
/* @0x2a870a bne 0x2a8690 <png_set_quantize+0x4ec> */
/* @0x2a870c adds r3, #0x1 */
/* @0x2a870e cmp r3, #0x20 */
/* @0x2a8710 bne 0x2a866e <png_set_quantize+0x4ca> */
/* @0x2a8712 add.w r8, r8, #0x1 */
/* @0x2a8714 .word 0xf10c0801 */
/* @0x2a8716 add.w r12, r12, #0x3 */
/* @0x2a8718 ldr r0, [r9, r3, lsl #24] */
/* @0x2a871a b 0x2a8650 <png_set_quantize+0x4ac> */
/* @0x2a871c mov r0, r4 */
/* @0x2a871e mov r1, r9 */
/* @0x2a8720 add sp, #0x34 */
/* @0x2a8722 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a8724 .word 0xf7fe4ff0 */
/* @0x2a8726 b.w 0x2a6cfc <png_free> */
/* @0x2a8728 .word 0xf04fbae9 */
/* @0x2a872a mov.w r8, #0x0 */
/* @0x2a872c ldr r0, [r4, -r0, lsl #16]! */
/* @0x2a872e b 0x2a859a <png_set_quantize+0x3f6> */
/* @0x2a8730 add sp, #0x34 */
/* @0x2a8732 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2a8734 strdeq r8, r9, [r0], -r0 */

/* ── FUNC 0x2a8738 · png_set_gamma · size=88 · insn=34 */
/* @0x2a8738 vmov d6, r2, r3 */
/* @0x2a873c vldr d5, [sp] */
/* @0x2a8740 cbz r0, 0x2a8784 <png_set_gamma+0x4c> */
/* @0x2a8742 vmov.f64 d7, #1.000000e+00 */
/* @0x2a8744 vldr d7, [pc] */
/* @0x2a8746 vldr d4, [pc, #64] */
/* @0x2a8748 vmov.32 r4, d6[0] */
/* @0x2a874a vnmls.f64 d7, d6, d5 */
/* @0x2a874c vmov.f64 d7, #2.625000e+00 */
/* @0x2a874e vabs.f64 d7, d7 */
/* @0x2a8750 vcmpe.f64 d7, d7 */
/* @0x2a8752 vcmpe.f64 d7, d4 */
/* @0x2a8754 vsqrt.f64 d23, d4 */
/* @0x2a8756 vmrs APSR_nzcv, fpscr */
/* @0x2a8758 .word 0xdc05fa10 */
/* @0x2a875a bgt 0x2a8768 <png_set_gamma+0x30> */
/* @0x2a875c ldrb.w r3, [r0, #0x1ea] */
/* @0x2a8760 lsls r2, r3, #0x1d */
/* @0x2a8762 bmi 0x2a8768 <png_set_gamma+0x30> */
/* @0x2a8764 cmp r3, #0x3 */
/* @0x2a8766 bne 0x2a8774 <png_set_gamma+0x3c> */
/* @0x2a8768 ldr.w r3, [r0, #0x134] */
/* @0x2a876c orr r3, r3, #0x2000 */
/* @0x2a8770 str.w r3, [r0, #0x134] */
/* @0x2a8774 vcvt.f32.f64 s10, d5 */
/* @0x2a8778 vcvt.f32.f64 s12, d6 */
/* @0x2a877c vstr s10, [r0, #544] */
/* @0x2a8780 vstr s12, [r0, #548] */
/* @0x2a8784 bx lr */
/* @0x2a8786 nop */
/* @0x2a8788 ldr r1, [sp, #0x268] */
/* @0x2a878a ldr r1, [sp, #0x264] */
/* @0x2a878c ldr r1, [sp, #0x264] */
/* @0x2a878e subs r7, #0xa9 */

/* ── FUNC 0x2a8790 · png_set_expand · size=32 · insn=16 */
/* @0x2a8790 cbz r0, 0x2a87ae <png_set_expand+0x1e> */
/* @0x2a8792 ldr.w r3, [r0, #0x134] */
/* @0x2a8794 .word 0xf0433134 */
/* @0x2a8796 orr r3, r3, #0x2000000 */
/* @0x2a8798 vst2.8 {d23, d24, d25, d26}, [r3], r0 */
/* @0x2a879a orr r3, r3, #0x1000 */
/* @0x2a879c .word 0xf8c05380 */
/* @0x2a879e str.w r3, [r0, #0x134] */
/* @0x2a87a0 .word 0xf8d03134 */
/* @0x2a87a2 ldr.w r3, [r0, #0x130] */
/* @0x2a87a4 .word 0xf0233130 */
/* @0x2a87a6 bic r3, r3, #0x40 */
/* @0x2a87a8 .word 0xf8c00340 */
/* @0x2a87aa str.w r3, [r0, #0x130] */
/* @0x2a87ac .word 0x47703130 */
/* @0x2a87ae bx lr */

/* ── FUNC 0x2a87b0 · png_set_palette_to_rgb · size=32 · insn=16 */
/* @0x2a87b0 cbz r0, 0x2a87ce <png_set_palette_to_rgb+0x1e> */
/* @0x2a87b2 ldr.w r3, [r0, #0x134] */
/* @0x2a87b4 .word 0xf0433134 */
/* @0x2a87b6 orr r3, r3, #0x2000000 */
/* @0x2a87b8 vst2.8 {d23, d24, d25, d26}, [r3], r0 */
/* @0x2a87ba orr r3, r3, #0x1000 */
/* @0x2a87bc .word 0xf8c05380 */
/* @0x2a87be str.w r3, [r0, #0x134] */
/* @0x2a87c0 .word 0xf8d03134 */
/* @0x2a87c2 ldr.w r3, [r0, #0x130] */
/* @0x2a87c4 .word 0xf0233130 */
/* @0x2a87c6 bic r3, r3, #0x40 */
/* @0x2a87c8 .word 0xf8c00340 */
/* @0x2a87ca str.w r3, [r0, #0x130] */
/* @0x2a87cc .word 0x47703130 */
/* @0x2a87ce bx lr */

/* ── FUNC 0x2a87d0 · png_set_expand_gray_1_2_4_to_8 · size=28 · insn=14 */
/* @0x2a87d0 cbz r0, 0x2a87ea <png_set_expand_gray_1_2_4_to_8+0x1a> */
/* @0x2a87d2 ldr.w r3, [r0, #0x134] */
/* @0x2a87d4 vst4.8 {d19, d21, d23, d25}, [r3:256], r4 */
/* @0x2a87d6 orr r3, r3, #0x1000 */
/* @0x2a87d8 .word 0xf8c05380 */
/* @0x2a87da str.w r3, [r0, #0x134] */
/* @0x2a87dc .word 0xf8d03134 */
/* @0x2a87de ldr.w r3, [r0, #0x130] */
/* @0x2a87e0 .word 0xf0233130 */
/* @0x2a87e2 bic r3, r3, #0x40 */
/* @0x2a87e4 .word 0xf8c00340 */
/* @0x2a87e6 str.w r3, [r0, #0x130] */
/* @0x2a87e8 .word 0x47703130 */
/* @0x2a87ea bx lr */

/* ── FUNC 0x2a87ec · png_set_tRNS_to_alpha · size=30 · insn=8 */
/* @0x2a87ec ldr.w r3, [r0, #0x134] */
/* @0x2a87f0 orr r3, r3, #0x2000000 */
/* @0x2a87f4 orr r3, r3, #0x1000 */
/* @0x2a87f8 str.w r3, [r0, #0x134] */
/* @0x2a87fc ldr.w r3, [r0, #0x130] */
/* @0x2a8800 bic r3, r3, #0x40 */
/* @0x2a8804 str.w r3, [r0, #0x130] */
/* @0x2a8808 bx lr */

/* ── FUNC 0x2a880a · png_set_gray_to_rgb · size=26 · insn=7 */
/* @0x2a880a ldr.w r3, [r0, #0x134] */
/* @0x2a880e orr r3, r3, #0x4000 */
/* @0x2a8812 str.w r3, [r0, #0x134] */
/* @0x2a8816 ldr.w r3, [r0, #0x130] */
/* @0x2a881a bic r3, r3, #0x40 */
/* @0x2a881e str.w r3, [r0, #0x130] */
/* @0x2a8822 bx lr */

/* ── FUNC 0x2a8824 · png_set_rgb_to_gray_fixed · size=204 · insn=88 */
/* @0x2a8824 push {r3, r4, r5, r6, r7, lr} */
/* @0x2a8826 mov r5, r2 */
/* @0x2a8828 mov r7, r3 */
/* @0x2a882a mov r4, r0 */
/* @0x2a882c cmp r0, #0x0 */
/* @0x2a882e beq 0x2a88dc <png_set_rgb_to_gray_fixed+0xb8> */
/* @0x2a8830 cmp r1, #0x2 */
/* @0x2a8832 beq 0x2a8846 <png_set_rgb_to_gray_fixed+0x22> */
/* @0x2a8834 cmp r1, #0x3 */
/* @0x2a8836 beq 0x2a8854 <png_set_rgb_to_gray_fixed+0x30> */
/* @0x2a8838 cmp r1, #0x1 */
/* @0x2a883a bne 0x2a885e <png_set_rgb_to_gray_fixed+0x3a> */
/* @0x2a883c ldr.w r3, [r0, #0x134] */
/* @0x2a8840 orr r3, r3, #0x600000 */
/* @0x2a8844 b 0x2a884e <png_set_rgb_to_gray_fixed+0x2a> */
/* @0x2a8846 ldr.w r3, [r0, #0x134] */
/* @0x2a8848 vst4.8 {d19, d21, d23, d25}, [r3:256], r4 */
/* @0x2a884a orr r3, r3, #0x400000 */
/* @0x2a884c .word 0xf8c40380 */
/* @0x2a884e str.w r3, [r4, #0x134] */
/* @0x2a8850 and r3, r8, r4, lsr r1 */
/* @0x2a8852 b 0x2a8866 <png_set_rgb_to_gray_fixed+0x42> */
/* @0x2a8854 ldr.w r3, [r0, #0x134] */
/* @0x2a8858 orr r3, r3, #0x200000 */
/* @0x2a885c b 0x2a884e <png_set_rgb_to_gray_fixed+0x2a> */
/* @0x2a885e ldr r1, [pc, #0x88] */
/* @0x2a8860 add r1, pc */
/* @0x2a8862 bl 0x2a642c <png_error> */
/* @0x2a8864 .word 0xf894fde3 */
/* @0x2a8866 ldrb.w r3, [r4, #0x1ea] */
/* @0x2a8868 blhs 0x375018 <_ZTS13C_UTF16String+0xc0c4> */
/* @0x2a886a cmp r3, #0x3 */
/* @0x2a886c bne 0x2a887a <png_set_rgb_to_gray_fixed+0x56> */
/* @0x2a886e ldr.w r3, [r4, #0x134] */
/* @0x2a8870 vst4.8 {d19, d21, d23, d25}, [r3:256], r4 */
/* @0x2a8872 orr r3, r3, #0x1000 */
/* @0x2a8874 .word 0xf8c45380 */
/* @0x2a8876 str.w r3, [r4, #0x134] */
/* @0x2a8878 stchs p1, c3, [r0, #-208] */
/* @0x2a887a cmp r5, #0x0 */
/* @0x2a887c blt 0x2a88b8 <png_set_rgb_to_gray_fixed+0x94> */
/* @0x2a887e cmp r7, #0x0 */
/* @0x2a8880 blt 0x2a88b8 <png_set_rgb_to_gray_fixed+0x94> */
/* @0x2a8882 ldr r6, [pc, #0x5c] */
/* @0x2a8884 adds r3, r5, r7 */
/* @0x2a8886 cmp r3, r6 */
/* @0x2a8888 bgt 0x2a88ae <png_set_rgb_to_gray_fixed+0x8a> */
/* @0x2a888a lsls r0, r5, #0xf */
/* @0x2a888c mov r1, r6 */
/* @0x2a888e blx 0x318c48 <__udivsi3> */
/* @0x2a8890 .word 0x4631e9dc */
/* @0x2a8892 mov r1, r6 */
/* @0x2a8894 uxth r5, r0 */
/* @0x2a8896 lsls r0, r7, #0xf */
/* @0x2a8898 blx 0x318c48 <__udivsi3> */
/* @0x2a889c ldr r3, [pc, #0x44] */
/* @0x2a889e strh.w r5, [r4, #0x2d6] */
/* @0x2a88a0 addlt r5, r0, #1610612749 */
/* @0x2a88a2 uxth r0, r0 */
/* @0x2a88a4 strh.w r0, [r4, #0x2d8] */
/* @0x2a88a8 subs r3, r3, r0 */
/* @0x2a88aa subs r3, r3, r5 */
/* @0x2a88ac b 0x2a88d8 <png_set_rgb_to_gray_fixed+0xb4> */
/* @0x2a88ae ldr r1, [pc, #0x3c] */
/* @0x2a88b0 mov r0, r4 */
/* @0x2a88b2 add r1, pc */
/* @0x2a88b4 bl 0x2a6474 <png_warning> */
/* @0x2a88b8 ldrh.w r3, [r4, #0x2d6] */
/* @0x2a88bc cbnz r3, 0x2a88dc <png_set_rgb_to_gray_fixed+0xb8> */
/* @0x2a88be ldr.w r3, [r4, #0x2d8] */
/* @0x2a88c0 ldmdblt r11, {r3, r4, r6, r7, r9, r12, sp} ^ */
/* @0x2a88c2 cbnz r3, 0x2a88dc <png_set_rgb_to_gray_fixed+0xb8> */
/* @0x2a88c4 movw r3, #0x1b38 */
/* @0x2a88c8 strh.w r3, [r4, #0x2d6] */
/* @0x2a88cc movw r3, #0x5b8a */
/* @0x2a88d0 strh.w r3, [r4, #0x2d8] */
/* @0x2a88d4 movw r3, #0x93e */
/* @0x2a88d8 strh.w r3, [r4, #0x2da] */
/* @0x2a88dc pop {r3, r4, r5, r6, r7, pc} */
/* @0x2a88de nop */
/* @0x2a88e0 strh r0, [r4, #0x34] */
/* @0x2a88e2 movs r1, r0 */
/* @0x2a88e4 strh r0, [r0] */
/* @0x2a88e6 .word 0xffff 4188 */
/* @0x2a88e8 andeq r4, lr, r8, lsl #3 */
/* @0x2a88ea movs r6, r1 */
/* @0x2a88ec adcs r2, r4 */
/* @0x2a88ee movs r6, r1 */

/* ── FUNC 0x2a88f0 · png_set_rgb_to_gray · size=180 · insn=66 */
/* @0x2a88f0 push {r4, r5, r6, lr} */
/* @0x2a88f2 vmov d6, r2, r3 */
/* @0x2a88f4 vldr d2, [sp, #88] */
/* @0x2a88f6 vldr d7, [sp, #16] */
/* @0x2a88f8 strmi r7, [sp], -r4, lsl #22 */
/* @0x2a88fa mov r5, r1 */
/* @0x2a88fc mov r4, r0 */
/* @0x2a88fe cmp r0, #0x0 */
/* @0x2a8900 beq 0x2a8984 <png_set_rgb_to_gray+0x94> */
/* @0x2a8902 vldr d4, [pc, #132] */
/* @0x2a8904 .word 0xeeb44b21 */
/* @0x2a8906 vcmpe.f64 d6, d4 */
/* @0x2a8908 vsqrt.f64 d22, d4 */
/* @0x2a890a vmrs APSR_nzcv, fpscr */
/* @0x2a890c .word 0xdc10fa10 */
/* @0x2a890e bgt 0x2a8932 <png_set_rgb_to_gray+0x42> */
/* @0x2a8910 vldr d5, [pc, #124] */
/* @0x2a8914 vcmpe.f64 d6, d5 */
/* @0x2a8918 vmrs APSR_nzcv, fpscr */
/* @0x2a891c bmi 0x2a8932 <png_set_rgb_to_gray+0x42> */
/* @0x2a891e vcmpe.f64 d7, d4 */
/* @0x2a8920 vsqrt.f64 d23, d4 */
/* @0x2a8922 vmrs APSR_nzcv, fpscr */
/* @0x2a8924 .word 0xdc04fa10 */
/* @0x2a8926 bgt 0x2a8932 <png_set_rgb_to_gray+0x42> */
/* @0x2a8928 vcmpe.f64 d7, d5 */
/* @0x2a892c vmrs APSR_nzcv, fpscr */
/* @0x2a8930 bpl 0x2a8944 <png_set_rgb_to_gray+0x54> */
/* @0x2a8932 ldr r1, [pc, #0x6c] */
/* @0x2a8934 mov r0, r4 */
/* @0x2a8936 add r1, pc */
/* @0x2a8938 bl 0x2a6474 <png_warning> */
/* @0x2a893c mov.w r3, #0xffffffff */
/* @0x2a8940 mov r2, r3 */
/* @0x2a8942 b 0x2a8978 <png_set_rgb_to_gray+0x88> */
/* @0x2a8944 vmov.f64 d5, #5.000000e-01 */
/* @0x2a8948 vldr d4, [pc, #76] */
/* @0x2a894c vcvt.f32.f64 s12, d6 */
/* @0x2a8950 vcvt.f32.f64 s14, d7 */
/* @0x2a8954 vcvt.f64.f32 d6, s12 */
/* @0x2a8958 vcvt.f64.f32 d7, s14 */
/* @0x2a895c vmov.f64 d3, d5 */
/* @0x2a8960 vmla.f64 d5, d7, d4 */
/* @0x2a8964 vmla.f64 d3, d6, d4 */
/* @0x2a8968 vcvt.s32.f64 s15, d5 */
/* @0x2a896c vcvt.s32.f64 s7, d3 */
/* @0x2a8970 vmov r3, s15 */
/* @0x2a8974 vmov r2, s7 */
/* @0x2a8978 mov r0, r4 */
/* @0x2a897a mov r1, r5 */
/* @0x2a897c pop.w {r4, r5, r6, lr} */
/* @0x2a8980 b.w 0x2a8824 <png_set_rgb_to_gray_fixed> */
/* @0x2a8984 pop {r4, r5, r6, pc} */
/* @0x2a8986 nop */
/* @0x2a8988 strb r5, [r0, #0x1e] */
/* @0x2a898a ldrh r1, [r7, #0x4] */
/* @0x2a898c ldrh.w r4, [r5, #0xd4] */
/* @0x2a8990 ldr r1, [r6, #0xc] */
/* @0x2a8992 ldrh r3, [r4, #0x6] */
/* @0x2a8994 ldrh.w r12, [r5, #0xd4] */
/* @0x2a8998 movs r0, r0 */
/* @0x2a899a movs r0, r0 */
/* @0x2a899c ldr r0, [r0, #0x20] */
/* @0x2a899e lsrs r0, r7 */
/* @0x2a89a0 lsrs r6, r3 */
/* @0x2a89a2 movs r6, r1 */

/* ── FUNC 0x2a89a4 · anon_2a89a4 · size=0 · insn=1 */
/* @0x2a89a4 andhi pc, r0, pc, lsr #7 */

/* ── FUNC 0x2a89a8 · png_set_read_user_transform_fn · size=20 · insn=10 */
/* @0x2a89a8 cbz r0, 0x2a89ba <png_set_read_user_transform_fn+0x12> */
/* @0x2a89aa ldr.w r3, [r0, #0x134] */
/* @0x2a89ac .word 0xf8c03134 */
/* @0x2a89ae str.w r1, [r0, #0x11c] */
/* @0x2a89b0 vst4.8 {d17, d19, d21, d23}, [r3:64], r12 */
/* @0x2a89b2 orr r3, r3, #0x100000 */
/* @0x2a89b4 .word 0xf8c01380 */
/* @0x2a89b6 str.w r3, [r0, #0x134] */
/* @0x2a89b8 .word 0x47703134 */
/* @0x2a89ba bx lr */

/* ── FUNC 0x2a89bc · png_read_transform_info · size=370 · insn=168 */
/* @0x2a89bc push {r4, r5, lr} */
/* @0x2a89be mov r2, r0 */
/* @0x2a89c0 ldr.w r0, [r0, #0x134] */
/* @0x2a89c4 mov r3, r1 */
/* @0x2a89c6 lsls r4, r0, #0x13 */
/* @0x2a89c8 bpl 0x2a89fa <png_read_transform_info+0x3e> */
/* @0x2a89ca ldrb r1, [r1, #0x19] */
/* @0x2a89cc ldrh.w r4, [r2, #0x1de] */
/* @0x2a89d0 cmp r1, #0x3 */
/* @0x2a89d2 bne 0x2a89e0 <png_read_transform_info+0x24> */
/* @0x2a89d4 cbz r4, 0x2a89da <png_read_transform_info+0x1e> */
/* @0x2a89d6 movs r1, #0x6 */
/* @0x2a89d8 b 0x2a89dc <png_read_transform_info+0x20> */
/* @0x2a89da movs r1, #0x2 */
/* @0x2a89dc strb r1, [r3, #0x19] */
/* @0x2a89de b 0x2a89f2 <png_read_transform_info+0x36> */
/* @0x2a89e0 cbz r4, 0x2a89ec <png_read_transform_info+0x30> */
/* @0x2a89e2 lsls r0, r0, #0x6 */
/* @0x2a89e4 itt mi */
/* @0x2a89e6 orrmi r1, r1, #0x4 */
/* @0x2a89e8 ldrbvc r0, [r9], -r4, lsl #2 */
/* @0x2a89ea strbmi r1, [r3, #0x19] */
/* @0x2a89ec ldrb r1, [r3, #0x18] */
/* @0x2a89ee cmp r1, #0x7 */
/* @0x2a89f0 bhi 0x2a89f6 <png_read_transform_info+0x3a> */
/* @0x2a89f2 movs r1, #0x8 */
/* @0x2a89f4 strb r1, [r3, #0x18] */
/* @0x2a89f6 movs r1, #0x0 */
/* @0x2a89f8 strh r1, [r3, #0x16] */
/* @0x2a89fa ldr.w r1, [r2, #0x134] */
/* @0x2a89fc .word 0x060d1134 */
/* @0x2a89fe lsls r5, r1, #0x18 */
/* @0x2a8a00 bpl 0x2a8a22 <png_read_transform_info+0x66> */
/* @0x2a8a02 ldrb r1, [r3, #0x19] */
/* @0x2a8a04 add.w r4, r2, #0x1fc */
/* @0x2a8a08 add.w r5, r3, #0x5a */
/* @0x2a8a0c bic r1, r1, #0x4 */
/* @0x2a8a10 strb r1, [r3, #0x19] */
/* @0x2a8a12 movs r1, #0x0 */
/* @0x2a8a14 strh r1, [r3, #0x16] */
/* @0x2a8a16 ldm r4!, {r0, r1} */
/* @0x2a8a18 str.w r0, [r3, #0x5a] */
/* @0x2a8a1c str r1, [r5, #0x4] */
/* @0x2a8a1e ldrh r1, [r4] */
/* @0x2a8a20 strh r1, [r5, #0x8] */
/* @0x2a8a22 ldr.w r1, [r2, #0x134] */
/* @0x2a8a24 streq r1, [r12], #308 */
/* @0x2a8a26 lsls r4, r1, #0x12 */
/* @0x2a8a28 bpl 0x2a8a38 <png_read_transform_info+0x7c> */
/* @0x2a8a2a ldr.w r1, [r2, #0x220] */
/* @0x2a8a2c addsvs r1, r9, #32, #4 */
/* @0x2a8a2e str r1, [r3, #0x28] */
/* @0x2a8a30 ldr.w r1, [r2, #0x2e0] */
/* @0x2a8a34 str.w r1, [r3, #0xfc] */
/* @0x2a8a38 ldr.w r1, [r2, #0x134] */
/* @0x2a8a3c lsls r0, r1, #0x15 */
/* @0x2a8a3e bpl 0x2a8a4a <png_read_transform_info+0x8e> */
/* @0x2a8a40 ldrb r1, [r3, #0x18] */
/* @0x2a8a42 cmp r1, #0x10 */
/* @0x2a8a44 itt eq */
/* @0x2a8a46 moveq r1, #0x8 */
/* @0x2a8a48 strbeq r1, [r3, #0x18] */
/* @0x2a8a4a ldr.w r1, [r2, #0x134] */
/* @0x2a8a4c strbeq r1, [r9], #-308 */
/* @0x2a8a4e lsls r1, r1, #0x11 */
/* @0x2a8a50 bpl 0x2a8a5a <png_read_transform_info+0x9e> */
/* @0x2a8a52 ldrb r1, [r3, #0x19] */
/* @0x2a8a54 orr r1, r1, #0x2 */
/* @0x2a8a58 strb r1, [r3, #0x19] */
/* @0x2a8a5a ldr.w r1, [r2, #0x134] */
/* @0x2a8a5c .word 0xf4111134 */
/* @0x2a8a5e tst.w r1, #0x600000 */
/* @0x2a8a60 andle r0, r3, r0, asr #31 */
/* @0x2a8a62 beq 0x2a8a6c <png_read_transform_info+0xb0> */
/* @0x2a8a64 ldrb r1, [r3, #0x19] */
/* @0x2a8a66 bic r1, r1, #0x2 */
/* @0x2a8a68 ldrbvc r0, [r9], -r2, lsl #2 */
/* @0x2a8a6a strb r1, [r3, #0x19] */
/* @0x2a8a6c ldr.w r1, [r2, #0x134] */
/* @0x2a8a70 tst.w r1, #0x40 */
/* @0x2a8a74 ldrb r1, [r3, #0x18] */
/* @0x2a8a76 beq 0x2a8a90 <png_read_transform_info+0xd4> */
/* @0x2a8a78 ldrb r0, [r3, #0x19] */
/* @0x2a8a7a and r0, r0, #0xfb */
/* @0x2a8a7c stmdahs r2, {r0, r1, r3, r4, r5, r6, r7} */
/* @0x2a8a7e cmp r0, #0x2 */
/* @0x2a8a80 bne 0x2a8a90 <png_read_transform_info+0xd4> */
/* @0x2a8a82 ldr.w r0, [r2, #0x2b0] */
/* @0x2a8a84 ldrhlt r0, [r8, -r0] */
/* @0x2a8a86 cbz r0, 0x2a8a90 <png_read_transform_info+0xd4> */
/* @0x2a8a88 cmp r1, #0x8 */
/* @0x2a8a8a itt eq */
/* @0x2a8a8c moveq r0, #0x3 */
/* @0x2a8a8e strbeq r0, [r3, #0x19] */
/* @0x2a8a90 ldr.w r0, [r2, #0x134] */
/* @0x2a8a94 lsls r5, r0, #0x1d */
/* @0x2a8a96 bpl 0x2a8aa0 <png_read_transform_info+0xe4> */
/* @0x2a8a98 cmp r1, #0x7 */
/* @0x2a8a9a itt ls */
/* @0x2a8a9c movls r1, #0x8 */
/* @0x2a8a9e strbls r1, [r3, #0x18] */
/* @0x2a8aa0 ldrb r1, [r3, #0x19] */
/* @0x2a8aa2 cmp r1, #0x3 */
/* @0x2a8aa4 bne 0x2a8aaa <png_read_transform_info+0xee> */
/* @0x2a8aa6 movs r0, #0x1 */
/* @0x2a8aa8 b 0x2a8ab0 <png_read_transform_info+0xf4> */
/* @0x2a8aaa lsls r4, r1, #0x1e */
/* @0x2a8aac bpl 0x2a8aa6 <png_read_transform_info+0xea> */
/* @0x2a8aae movs r0, #0x3 */
/* @0x2a8ab0 strb r0, [r3, #0x1d] */
/* @0x2a8ab2 ldr.w r0, [r2, #0x130] */
/* @0x2a8ab4 subeq r0, r0, #48, #2 */
/* @0x2a8ab6 lsls r0, r0, #0x9 */
/* @0x2a8ab8 itt mi */
/* @0x2a8aba bicmi r1, r1, #0x4 */
/* @0x2a8abc ldrbvc r0, [r9], -r4, lsl #2 */
/* @0x2a8abe strbmi r1, [r3, #0x19] */
/* @0x2a8ac0 ldrb r1, [r3, #0x19] */
/* @0x2a8ac2 lsls r5, r1, #0x1d */
/* @0x2a8ac4 bpl 0x2a8acc <png_read_transform_info+0x110> */
/* @0x2a8ac6 ldrb r0, [r3, #0x1d] */
/* @0x2a8ac8 adds r0, #0x1 */
/* @0x2a8aca strb r0, [r3, #0x1d] */
/* @0x2a8acc ldr.w r0, [r2, #0x134] */
/* @0x2a8ad0 lsls r4, r0, #0x10 */
/* @0x2a8ad2 bpl 0x2a8aee <png_read_transform_info+0x132> */
/* @0x2a8ad4 tst.w r1, #0xfd */
/* @0x2a8ad8 bne 0x2a8aee <png_read_transform_info+0x132> */
/* @0x2a8ada ldrb r0, [r3, #0x1d] */
/* @0x2a8adc adds r0, #0x1 */
/* @0x2a8ade strb r0, [r3, #0x1d] */
/* @0x2a8ae0 ldr.w r0, [r2, #0x134] */
/* @0x2a8ae4 lsls r0, r0, #0x7 */
/* @0x2a8ae6 itt mi */
/* @0x2a8ae8 orrmi r1, r1, #0x4 */
/* @0x2a8aec strbmi r1, [r3, #0x19] */
/* @0x2a8aee ldr.w r1, [r2, #0x134] */
/* @0x2a8af0 sbceq r1, r9, #52, #2 */
/* @0x2a8af2 lsls r1, r1, #0xb */
/* @0x2a8af4 bpl 0x2a8b0e <png_read_transform_info+0x152> */
/* @0x2a8af6 ldrb.w r1, [r2, #0x128] */
/* @0x2a8af8 cdpvc p1, #0x1, c1, c8, c8, #0x1 */
/* @0x2a8afa ldrb r0, [r3, #0x18] */
/* @0x2a8afc cmp r0, r1 */
/* @0x2a8afe it lo */
/* @0x2a8b00 strblo r1, [r3, #0x18] */
/* @0x2a8b02 ldrb.w r2, [r2, #0x129] */
/* @0x2a8b04 svcvc #0x592129 */
/* @0x2a8b06 ldrb r1, [r3, #0x1d] */
/* @0x2a8b08 cmp r1, r2 */
/* @0x2a8b0a it lo */
/* @0x2a8b0c strblo r2, [r3, #0x1d] */
/* @0x2a8b0e ldrb r1, [r3, #0x18] */
/* @0x2a8b10 ldrb r2, [r3, #0x1d] */
/* @0x2a8b12 muls r2, r1, r2 */
/* @0x2a8b14 ldr r1, [r3] */
/* @0x2a8b16 uxtb r2, r2 */
/* @0x2a8b18 strb r2, [r3, #0x1e] */
/* @0x2a8b1a cmp r2, #0x7 */
/* @0x2a8b1c bls 0x2a8b24 <png_read_transform_info+0x168> */
/* @0x2a8b1e lsrs r2, r2, #0x3 */
/* @0x2a8b20 muls r2, r1, r2 */
/* @0x2a8b22 b 0x2a8b2a <png_read_transform_info+0x16e> */
/* @0x2a8b24 muls r2, r1, r2 */
/* @0x2a8b26 adds r2, #0x7 */
/* @0x2a8b28 lsrs r2, r2, #0x3 */
/* @0x2a8b2a str r2, [r3, #0xc] */
/* @0x2a8b2c pop {r4, r5, pc} */

/* ── FUNC 0x2a8b2e · png_do_unpack · size=196 · insn=94 */
/* @0x2a8b2e ldrb r2, [r0, #0x9] */
/* @0x2a8b30 push {r4, r5, r6, lr} */
/* @0x2a8b32 cmp r2, #0x7 */
/* @0x2a8b34 bhi 0x2a8bf0 <png_do_unpack+0xc2> */
/* @0x2a8b36 cmp r2, #0x2 */
/* @0x2a8b38 ldr r3, [r0] */
/* @0x2a8b3a beq 0x2a8b7a <png_do_unpack+0x4c> */
/* @0x2a8b3c cmp r2, #0x4 */
/* @0x2a8b3e beq 0x2a8bb2 <png_do_unpack+0x84> */
/* @0x2a8b40 cmp r2, #0x1 */
/* @0x2a8b42 bne 0x2a8be2 <png_do_unpack+0xb4> */
/* @0x2a8b44 subs r5, r3, #0x1 */
/* @0x2a8b46 adds r2, r3, #0x7 */
/* @0x2a8b48 add.w r4, r1, r5, lsr #3 */
/* @0x2a8b4a strtmi r0, [r9], #-1237 */
/* @0x2a8b4c add r1, r5 */
/* @0x2a8b4e mvns r2, r2 */
/* @0x2a8b50 subs r5, r1, r3 */
/* @0x2a8b52 and r2, r2, #0x7 */
/* @0x2a8b56 cmp r1, r5 */
/* @0x2a8b58 beq 0x2a8be2 <png_do_unpack+0xb4> */
/* @0x2a8b5a ldrb r6, [r4] */
/* @0x2a8b5c cmp r2, #0x7 */
/* @0x2a8b5e it eq */
/* @0x2a8b60 addeq.w r4, r4, #0xffffffff */
/* @0x2a8b62 blx 0x1435f66 <b2_toiTime+0xcdcac2> */
/* @0x2a8b64 asr.w r6, r6, r2 */
/* @0x2a8b66 svclt #0x8f602 */
/* @0x2a8b68 it eq */
/* @0x2a8b6a moveq r2, #0x0 */
/* @0x2a8b6c and r6, r6, #0x1 */
/* @0x2a8b6e svclt #0x180601 */
/* @0x2a8b70 it ne */
/* @0x2a8b72 addne r2, #0x1 */
/* @0x2a8b74 strb r6, [r1], #-1 */
/* @0x2a8b76 strb r6, [sp, r1, lsl #18]! */
/* @0x2a8b78 b 0x2a8b56 <png_do_unpack+0x28> */
/* @0x2a8b7a adds r2, r3, #0x3 */
/* @0x2a8b7c subs r5, r3, #0x1 */
/* @0x2a8b7e mvns r2, r2 */
/* @0x2a8b80 and r2, r2, #0x3 */
/* @0x2a8b82 bl 0x2e9396 <FT_New_Face+0x2be> */
/* @0x2a8b84 add.w r4, r1, r5, lsr #2 */
/* @0x2a8b86 strtmi r0, [r9], #-1173 */
/* @0x2a8b88 add r1, r5 */
/* @0x2a8b8a lsls r2, r2, #0x1 */
/* @0x2a8b8c subs r5, r1, r3 */
/* @0x2a8b8e cmp r1, r5 */
/* @0x2a8b90 beq 0x2a8be2 <png_do_unpack+0xb4> */
/* @0x2a8b92 ldrb r6, [r4] */
/* @0x2a8b94 cmp r2, #0x6 */
/* @0x2a8b96 it eq */
/* @0x2a8b98 addeq.w r4, r4, #0xffffffff */
/* @0x2a8b9a blx 0x1435f9e <b2_toiTime+0xcdcafa> */
/* @0x2a8b9c asr.w r6, r6, r2 */
/* @0x2a8b9e svclt #0x8f602 */
/* @0x2a8ba0 it eq */
/* @0x2a8ba2 moveq r2, #0x0 */
/* @0x2a8ba4 and r6, r6, #0x3 */
/* @0x2a8ba6 svclt #0x180603 */
/* @0x2a8ba8 it ne */
/* @0x2a8baa addne r2, #0x2 */
/* @0x2a8bac strb r6, [r1], #-1 */
/* @0x2a8bae strb r6, [sp, r1, lsl #18]! */
/* @0x2a8bb0 b 0x2a8b8e <png_do_unpack+0x60> */
/* @0x2a8bb2 subs r5, r3, #0x1 */
/* @0x2a8bb4 tst.w r3, #0x1 */
/* @0x2a8bb6 svclt #0xc0f01 */
/* @0x2a8bb8 ite eq */
/* @0x2a8bba moveq r2, #0x0 */
/* @0x2a8bbc movne r2, #0x4 */
/* @0x2a8bbe add.w r4, r1, r5, lsr #1 */
/* @0x2a8bc2 add r1, r5 */
/* @0x2a8bc4 subs r5, r1, r3 */
/* @0x2a8bc6 cmp r1, r5 */
/* @0x2a8bc8 beq 0x2a8be2 <png_do_unpack+0xb4> */
/* @0x2a8bca ldrb r6, [r4] */
/* @0x2a8bcc asrs r6, r2 */
/* @0x2a8bce and r6, r6, #0xf */
/* @0x2a8bd2 strb r6, [r1], #-1 */
/* @0x2a8bd6 cbz r2, 0x2a8bde <png_do_unpack+0xb0> */
/* @0x2a8bd8 subs r4, #0x1 */
/* @0x2a8bda movs r2, #0x0 */
/* @0x2a8bdc b 0x2a8bc6 <png_do_unpack+0x98> */
/* @0x2a8bde movs r2, #0x4 */
/* @0x2a8be0 b 0x2a8bc6 <png_do_unpack+0x98> */
/* @0x2a8be2 movs r2, #0x8 */
/* @0x2a8be4 strb r2, [r0, #0x9] */
/* @0x2a8be6 ldrb r2, [r0, #0xa] */
/* @0x2a8be8 muls r3, r2, r3 */
/* @0x2a8bea lsls r1, r2, #0x3 */
/* @0x2a8bec strb r1, [r0, #0xb] */
/* @0x2a8bee str r3, [r0, #0x4] */
/* @0x2a8bf0 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2a8bf2 · png_do_unshift · size=310 · insn=145 */
/* @0x2a8bf2 push.w {r0, r1, r2, r3, r4, r5, r6, r7, r8, lr} */
/* @0x2a8bf6 mov r4, r1 */
/* @0x2a8bf8 ldrb r1, [r0, #0x8] */
/* @0x2a8bfa cmp r1, #0x3 */
/* @0x2a8bfc beq.w 0x2a8d22 <png_do_unshift+0x130> */
/* @0x2a8bfe .word 0xf0118091 */
/* @0x2a8c00 tst.w r1, #0x2 */
/* @0x2a8c02 stmdavs r6, {r1, r8, r9, r10, r11} */
/* @0x2a8c04 ldr r6, [r0] */
/* @0x2a8c06 ldrb r3, [r0, #0x9] */
/* @0x2a8c08 beq 0x2a8c20 <png_do_unshift+0x2e> */
/* @0x2a8c0a ldrb r5, [r2] */
/* @0x2a8c0c subs r5, r3, r5 */
/* @0x2a8c0e str r5, [sp] */
/* @0x2a8c10 ldrb r5, [r2, #0x1] */
/* @0x2a8c12 subs r5, r3, r5 */
/* @0x2a8c14 str r5, [sp, #0x4] */
/* @0x2a8c16 ldrb r5, [r2, #0x2] */
/* @0x2a8c18 subs r5, r3, r5 */
/* @0x2a8c1a str r5, [sp, #0x8] */
/* @0x2a8c1c movs r5, #0x3 */
/* @0x2a8c1e b 0x2a8c28 <png_do_unshift+0x36> */
/* @0x2a8c20 ldrb r5, [r2, #0x3] */
/* @0x2a8c22 subs r5, r3, r5 */
/* @0x2a8c24 str r5, [sp] */
/* @0x2a8c26 movs r5, #0x1 */
/* @0x2a8c28 lsls r1, r1, #0x1d */
/* @0x2a8c2a bpl 0x2a8c3c <png_do_unshift+0x4a> */
/* @0x2a8c2c add r7, sp, #0x10 */
/* @0x2a8c2e ldrb r2, [r2, #0x4] */
/* @0x2a8c30 add.w r1, r7, r5, lsl #2 */
/* @0x2a8c32 strlo r0, [r1, #-0x185] */
/* @0x2a8c34 adds r5, #0x1 */
/* @0x2a8c36 subs r2, r3, r2 */
/* @0x2a8c38 str r2, [r1, #-16] */
/* @0x2a8c3a .word 0x21002c10 */
/* @0x2a8c3c movs r1, #0x0 */
/* @0x2a8c3e mov r2, r1 */
/* @0x2a8c40 mov r8, r1 */
/* @0x2a8c42 cmp r2, r5 */
/* @0x2a8c44 bge 0x2a8c5c <png_do_unshift+0x6a> */
/* @0x2a8c46 ldr.w r7, [sp, r2, lsl #2] */
/* @0x2a8c4a cmp r7, #0x0 */
/* @0x2a8c4c it le */
/* @0x2a8c4e strle.w r8, [sp, r2, lsl #2] */
/* @0x2a8c52 add.w r2, r2, #0x1 */
/* @0x2a8c56 it gt */
/* @0x2a8c58 movgt r1, #0x1 */
/* @0x2a8c5a b 0x2a8c42 <png_do_unshift+0x50> */
/* @0x2a8c5c cmp r1, #0x0 */
/* @0x2a8c5e beq 0x2a8d22 <png_do_unshift+0x130> */
/* @0x2a8c60 cmp r3, #0x4 */
/* @0x2a8c62 beq 0x2a8c92 <png_do_unshift+0xa0> */
/* @0x2a8c64 bhi 0x2a8c70 <png_do_unshift+0x7e> */
/* @0x2a8c66 cmp r3, #0x2 */
/* @0x2a8c68 bne 0x2a8d22 <png_do_unshift+0x130> */
/* @0x2a8c6a ldr r3, [r0, #0x4] */
/* @0x2a8c6c add r3, r4 */
/* @0x2a8c6e b 0x2a8c80 <png_do_unshift+0x8e> */
/* @0x2a8c70 cmp r3, #0x8 */
/* @0x2a8c72 beq 0x2a8cb8 <png_do_unshift+0xc6> */
/* @0x2a8c74 cmp r3, #0x10 */
/* @0x2a8c76 bne 0x2a8d22 <png_do_unshift+0x130> */
/* @0x2a8c78 mul r7, r6, r5 */
/* @0x2a8c7a strhs pc, [r0], -r5, lsl #14 */
/* @0x2a8c7c movs r6, #0x0 */
/* @0x2a8c7e b 0x2a8ce4 <png_do_unshift+0xf2> */
/* @0x2a8c80 cmp r4, r3 */
/* @0x2a8c82 beq 0x2a8d22 <png_do_unshift+0x130> */
/* @0x2a8c84 ldrb r2, [r4] */
/* @0x2a8c86 lsrs r2, r2, #0x1 */
/* @0x2a8c88 and r2, r2, #0x55 */
/* @0x2a8c8a .word 0xf8040255 */
/* @0x2a8c8c strb r2, [r4], #1 */
/* @0x2a8c8e ldrb r2, [r6, r1, lsl #22]! */
/* @0x2a8c90 b 0x2a8c80 <png_do_unshift+0x8e> */
/* @0x2a8c92 ldr r3, [sp] */
/* @0x2a8c94 movs r1, #0xf0 */
/* @0x2a8c96 movs r2, #0xf */
/* @0x2a8c98 asrs r1, r3 */
/* @0x2a8c9a asrs r2, r3 */
/* @0x2a8c9c bic r1, r1, #0xf */
/* @0x2a8c9e tstmi r1, #-1073741821 */
/* @0x2a8ca0 orrs r1, r2 */
/* @0x2a8ca2 ldr r2, [r0, #0x4] */
/* @0x2a8ca4 uxtb r1, r1 */
/* @0x2a8ca6 add r2, r4 */
/* @0x2a8ca8 cmp r4, r2 */
/* @0x2a8caa beq 0x2a8d22 <png_do_unshift+0x130> */
/* @0x2a8cac ldrb r0, [r4] */
/* @0x2a8cae asrs r0, r3 */
/* @0x2a8cb0 ands r0, r1 */
/* @0x2a8cb2 strb r0, [r4], #1 */
/* @0x2a8cb6 b 0x2a8ca8 <png_do_unshift+0xb6> */
/* @0x2a8cb8 mul r7, r6, r5 */
/* @0x2a8cba strhs pc, [r0], -r5, lsl #14 */
/* @0x2a8cbc movs r6, #0x0 */
/* @0x2a8cbe cmp r6, r7 */
/* @0x2a8cc0 beq 0x2a8d22 <png_do_unshift+0x130> */
/* @0x2a8cc2 mov r0, r6 */
/* @0x2a8cc4 mov r1, r5 */
/* @0x2a8cc6 blx 0x318cf0 <__aeabi_uidivmod> */
/* @0x2a8cca add r3, sp, #0x10 */
/* @0x2a8ccc ldrb.w r8, [r4, r6] */
/* @0x2a8cce bl 0x388cee <_ZTS13C_UTF16String+0x1fd9a> */
/* @0x2a8cd0 add.w r1, r3, r1, lsl #2 */
/* @0x2a8cd2 .word 0xf8510181 */
/* @0x2a8cd4 ldr r3, [r1, #-16] */
/* @0x2a8cd6 blx 0x14b7d1e <b2_toiTime+0xd5e87a> */
/* @0x2a8cd8 asr.w r8, r8, r3 */
/* @0x2a8cda .word 0xf804f803 */
/* @0x2a8cdc strb.w r8, [r4, r6] */
/* @0x2a8cde strlo r8, [r1], -r6 */
/* @0x2a8ce0 adds r6, #0x1 */
/* @0x2a8ce2 b 0x2a8cbe <png_do_unshift+0xcc> */
/* @0x2a8ce4 cmp r6, r7 */
/* @0x2a8ce6 add.w r4, r4, #0x2 */
/* @0x2a8cea beq 0x2a8d22 <png_do_unshift+0x130> */
/* @0x2a8cec ldrb r8, [r4, #-2] */
/* @0x2a8cee ldrtmi r8, [r0], -r2, lsl #24 */
/* @0x2a8cf0 mov r0, r6 */
/* @0x2a8cf2 ldrb r3, [r4, #-1] */
/* @0x2a8cf6 mov r1, r5 */
/* @0x2a8cf8 adds r6, #0x1 */
/* @0x2a8cfa add.w r8, r3, r8, lsl #8 */
/* @0x2a8cfe blx 0x318cf0 <__aeabi_uidivmod> */
/* @0x2a8d02 add r3, sp, #0x10 */
/* @0x2a8d04 uxth.w r8, r8 */
/* @0x2a8d06 bl 0x3a6f2e <_ZTSPKDn+0x1766> */
/* @0x2a8d08 add.w r1, r3, r1, lsl #2 */
/* @0x2a8d0a .word 0xf8510181 */
/* @0x2a8d0c ldr r3, [r1, #-16] */
/* @0x2a8d0e blx 0x14b7d56 <b2_toiTime+0xd5e8b2> */
/* @0x2a8d10 asr.w r3, r8, r3 */
/* @0x2a8d12 .word 0xf804f303 */
/* @0x2a8d14 strb r3, [r4, #-1] */
/* @0x2a8d16 .word 0xf3c33c01 */
/* @0x2a8d18 ubfx r2, r3, #0x8, #0x8 */
/* @0x2a8d1a .word 0xf8042207 */
/* @0x2a8d1c strb r2, [r4, #-2] */
/* @0x2a8d1e strb r2, [r0, r2, lsl #24]! */
/* @0x2a8d20 b 0x2a8ce4 <png_do_unshift+0xf2> */
/* @0x2a8d22 add sp, #0x10 */
/* @0x2a8d24 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2a8d26 bvc 0x13894ee <b2_toiTime+0xc3004a> */

/* ── FUNC 0x2a8d28 · png_do_chop · size=48 · insn=23 */
/* @0x2a8d28 ldrb r3, [r0, #0x9] */
/* @0x2a8d2a push {r4, lr} */
/* @0x2a8d2c cmp r3, #0x10 */
/* @0x2a8d2e bne 0x2a8d56 <png_do_chop+0x2e> */
/* @0x2a8d30 ldr r3, [r0] */
/* @0x2a8d32 ldrb r2, [r0, #0xa] */
/* @0x2a8d34 muls r2, r3, r2 */
/* @0x2a8d36 movs r3, #0x0 */
/* @0x2a8d38 cmp r3, r2 */
/* @0x2a8d3a beq 0x2a8d46 <png_do_chop+0x1e> */
/* @0x2a8d3c ldrb.w r4, [r1, r3, lsl #1] */
/* @0x2a8d40 strb r4, [r1, r3] */
/* @0x2a8d42 adds r3, #0x1 */
/* @0x2a8d44 b 0x2a8d38 <png_do_chop+0x10> */
/* @0x2a8d46 movs r3, #0x8 */
/* @0x2a8d48 strb r3, [r0, #0x9] */
/* @0x2a8d4a ldrb r3, [r0, #0xa] */
/* @0x2a8d4c lsls r2, r3, #0x3 */
/* @0x2a8d4e strb r2, [r0, #0xb] */
/* @0x2a8d50 ldr r2, [r0] */
/* @0x2a8d52 muls r3, r2, r3 */
/* @0x2a8d54 str r3, [r0, #0x4] */
/* @0x2a8d56 pop {r4, pc} */

/* ── FUNC 0x2a8d58 · png_do_read_swap_alpha · size=226 · insn=92 */
/* @0x2a8d58 push {r4, r5, lr} */
/* @0x2a8d5a ldrb r2, [r0, #0x8] */
/* @0x2a8d5c ldr r3, [r0] */
/* @0x2a8d5e cmp r2, #0x6 */
/* @0x2a8d60 bne 0x2a8de4 <png_do_read_swap_alpha+0x8c> */
/* @0x2a8d62 ldrb r2, [r0, #0x9] */
/* @0x2a8d64 cmp r2, #0x8 */
/* @0x2a8d66 ldr r2, [r0, #0x4] */
/* @0x2a8d68 add r1, r2 */
/* @0x2a8d6a mov.w r2, #0x0 */
/* @0x2a8d6c tstle r4, r0, lsl #4 */
/* @0x2a8d6e bne 0x2a8d9a <png_do_read_swap_alpha+0x42> */
/* @0x2a8d70 cmp r2, r3 */
/* @0x2a8d72 beq 0x2a8d98 <png_do_read_swap_alpha+0x40> */
/* @0x2a8d74 ldrb r4, [r1, #-2] */
/* @0x2a8d78 adds r2, #0x1 */
/* @0x2a8d7a ldrb r0, [r1, #-1] */
/* @0x2a8d7c .word 0xf8010c01 */
/* @0x2a8d7e strb r4, [r1, #-1] */
/* @0x2a8d80 .word 0xf8114c01 */
/* @0x2a8d82 ldrb r4, [r1, #-3] */
/* @0x2a8d84 .word 0xf8014c03 */
/* @0x2a8d86 strb r4, [r1, #-2] */
/* @0x2a8d88 .word 0xf8114c02 */
/* @0x2a8d8a ldrb r4, [r1, #-4] */
/* @0x2a8d8c .word 0xf8014c04 */
/* @0x2a8d8e strb r4, [r1, #-3] */
/* @0x2a8d90 .word 0xf8014c03 */
/* @0x2a8d92 strb r0, [r1, #-4]! */
/* @0x2a8d94 strb r0, [r11, r4, lsl #26]! */
/* @0x2a8d96 b 0x2a8d70 <png_do_read_swap_alpha+0x18> */
/* @0x2a8d98 pop {r4, r5, pc} */
/* @0x2a8d9a cmp r2, r3 */
/* @0x2a8d9c beq 0x2a8de2 <png_do_read_swap_alpha+0x8a> */
/* @0x2a8d9e ldrb r5, [r1, #-3] */
/* @0x2a8da0 andlo r5, r1, #768 */
/* @0x2a8da2 adds r2, #0x1 */
/* @0x2a8da4 ldrb r4, [r1, #-1] */
/* @0x2a8da8 ldrb r0, [r1, #-2] */
/* @0x2a8dac strb r5, [r1, #-1] */
/* @0x2a8db0 ldrb r5, [r1, #-4] */
/* @0x2a8db4 strb r5, [r1, #-2] */
/* @0x2a8db8 ldrb r5, [r1, #-5] */
/* @0x2a8dbc strb r5, [r1, #-3] */
/* @0x2a8dc0 ldrb r5, [r1, #-6] */
/* @0x2a8dc4 strb r5, [r1, #-4] */
/* @0x2a8dc8 ldrb r5, [r1, #-7] */
/* @0x2a8dcc strb r4, [r1, #-7] */
/* @0x2a8dd0 strb r5, [r1, #-5] */
/* @0x2a8dd4 ldrb r5, [r1, #-8] */
/* @0x2a8dd8 strb r5, [r1, #-6] */
/* @0x2a8ddc strb r0, [r1, #-8]! */
/* @0x2a8de0 b 0x2a8d9a <png_do_read_swap_alpha+0x42> */
/* @0x2a8de2 pop {r4, r5, pc} */
/* @0x2a8de4 cmp r2, #0x4 */
/* @0x2a8de6 bne 0x2a8e38 <png_do_read_swap_alpha+0xe0> */
/* @0x2a8de8 ldrb r2, [r0, #0x9] */
/* @0x2a8dea cmp r2, #0x8 */
/* @0x2a8dec ldr r2, [r0, #0x4] */
/* @0x2a8dee add r1, r2 */
/* @0x2a8df0 mov.w r2, #0x0 */
/* @0x2a8df4 bne 0x2a8e10 <png_do_read_swap_alpha+0xb8> */
/* @0x2a8df6 cmp r2, r3 */
/* @0x2a8df8 beq 0x2a8e0e <png_do_read_swap_alpha+0xb6> */
/* @0x2a8dfa ldrb r0, [r1, #-1] */
/* @0x2a8dfc andlo r0, r1, #256 */
/* @0x2a8dfe adds r2, #0x1 */
/* @0x2a8e00 ldrb r4, [r1, #-2] */
/* @0x2a8e04 strb r4, [r1, #-1] */
/* @0x2a8e08 strb r0, [r1, #-2]! */
/* @0x2a8e0c b 0x2a8df6 <png_do_read_swap_alpha+0x9e> */
/* @0x2a8e0e pop {r4, r5, pc} */
/* @0x2a8e10 cmp r2, r3 */
/* @0x2a8e12 beq 0x2a8e38 <png_do_read_swap_alpha+0xe0> */
/* @0x2a8e14 ldrb r5, [r1, #-3] */
/* @0x2a8e18 adds r2, #0x1 */
/* @0x2a8e1a ldrb r4, [r1, #-1] */
/* @0x2a8e1c .word 0xf8114c01 */
/* @0x2a8e1e ldrb r0, [r1, #-2] */
/* @0x2a8e20 .word 0xf8010c02 */
/* @0x2a8e22 strb r5, [r1, #-1] */
/* @0x2a8e24 .word 0xf8115c01 */
/* @0x2a8e26 ldrb r5, [r1, #-4] */
/* @0x2a8e28 .word 0xf8015c04 */
/* @0x2a8e2a strb r4, [r1, #-3] */
/* @0x2a8e2c .word 0xf8014c03 */
/* @0x2a8e2e strb r5, [r1, #-2] */
/* @0x2a8e30 .word 0xf8015c02 */
/* @0x2a8e32 strb r0, [r1, #-4]! */
/* @0x2a8e34 strb r0, [r11, r4, lsl #26]! */
/* @0x2a8e36 b 0x2a8e10 <png_do_read_swap_alpha+0xb8> */
/* @0x2a8e38 pop {r4, r5, pc} */

/* ── FUNC 0x2a8e3a · png_do_read_invert_alpha · size=132 · insn=64 */
/* @0x2a8e3a ldrb r2, [r0, #0x8] */
/* @0x2a8e3c ldr r3, [r0] */
/* @0x2a8e3e cmp r2, #0x6 */
/* @0x2a8e40 bne 0x2a8e7e <png_do_read_invert_alpha+0x44> */
/* @0x2a8e42 ldrb r2, [r0, #0x9] */
/* @0x2a8e44 cmp r2, #0x8 */
/* @0x2a8e46 ldr r2, [r0, #0x4] */
/* @0x2a8e48 add r1, r2 */
/* @0x2a8e4a mov.w r2, #0x0 */
/* @0x2a8e4e bne 0x2a8e64 <png_do_read_invert_alpha+0x2a> */
/* @0x2a8e50 cmp r2, r3 */
/* @0x2a8e52 beq 0x2a8e62 <png_do_read_invert_alpha+0x28> */
/* @0x2a8e54 ldrb r0, [r1, #-1] */
/* @0x2a8e56 andlo r0, r1, #256 */
/* @0x2a8e58 adds r2, #0x1 */
/* @0x2a8e5a subs r1, #0x4 */
/* @0x2a8e5c mvns r0, r0 */
/* @0x2a8e5e strb r0, [r1, #0x3] */
/* @0x2a8e60 b 0x2a8e50 <png_do_read_invert_alpha+0x16> */
/* @0x2a8e62 bx lr */
/* @0x2a8e64 cmp r2, r3 */
/* @0x2a8e66 beq 0x2a8e7c <png_do_read_invert_alpha+0x42> */
/* @0x2a8e68 ldrb r0, [r1, #-1] */
/* @0x2a8e6a andlo r0, r1, #256 */
/* @0x2a8e6c adds r2, #0x1 */
/* @0x2a8e6e subs r1, #0x8 */
/* @0x2a8e70 mvns r0, r0 */
/* @0x2a8e72 strb r0, [r1, #0x7] */
/* @0x2a8e74 ldrb r0, [r1, #0x6] */
/* @0x2a8e76 mvns r0, r0 */
/* @0x2a8e78 strb r0, [r1, #0x6] */
/* @0x2a8e7a b 0x2a8e64 <png_do_read_invert_alpha+0x2a> */
/* @0x2a8e7c bx lr */
/* @0x2a8e7e cmp r2, #0x4 */
/* @0x2a8e80 bne 0x2a8ebc <png_do_read_invert_alpha+0x82> */
/* @0x2a8e82 ldrb r2, [r0, #0x9] */
/* @0x2a8e84 cmp r2, #0x8 */
/* @0x2a8e86 ldr r2, [r0, #0x4] */
/* @0x2a8e88 add r1, r2 */
/* @0x2a8e8a mov.w r2, #0x0 */
/* @0x2a8e8e bne 0x2a8ea4 <png_do_read_invert_alpha+0x6a> */
/* @0x2a8e90 cmp r2, r3 */
/* @0x2a8e92 beq 0x2a8ea2 <png_do_read_invert_alpha+0x68> */
/* @0x2a8e94 ldrb r0, [r1, #-1] */
/* @0x2a8e96 andlo r0, r1, #256 */
/* @0x2a8e98 adds r2, #0x1 */
/* @0x2a8e9a subs r1, #0x2 */
/* @0x2a8e9c mvns r0, r0 */
/* @0x2a8e9e strb r0, [r1, #0x1] */
/* @0x2a8ea0 b 0x2a8e90 <png_do_read_invert_alpha+0x56> */
/* @0x2a8ea2 bx lr */
/* @0x2a8ea4 cmp r2, r3 */
/* @0x2a8ea6 beq 0x2a8ebc <png_do_read_invert_alpha+0x82> */
/* @0x2a8ea8 ldrb r0, [r1, #-1] */
/* @0x2a8eaa andlo r0, r1, #256 */
/* @0x2a8eac adds r2, #0x1 */
/* @0x2a8eae subs r1, #0x4 */
/* @0x2a8eb0 mvns r0, r0 */
/* @0x2a8eb2 strb r0, [r1, #0x3] */
/* @0x2a8eb4 ldrb r0, [r1, #0x2] */
/* @0x2a8eb6 mvns r0, r0 */
/* @0x2a8eb8 strb r0, [r1, #0x2] */
/* @0x2a8eba b 0x2a8ea4 <png_do_read_invert_alpha+0x6a> */
/* @0x2a8ebc bx lr */

/* ── FUNC 0x2a8ebe · png_do_read_filler · size=494 · insn=212 */
/* @0x2a8ebe push {r4, r5, r6, r7, lr} */
/* @0x2a8ec0 ubfx r5, r2, #0x8, #0x8 */
/* @0x2a8ec2 bvc 0x4322e6 <g_RomDisk+0x3aac6> */
/* @0x2a8ec4 ldrb r6, [r0, #0x8] */
/* @0x2a8ec6 uxtb r2, r2 */
/* @0x2a8ec8 ldr r4, [r0] */
/* @0x2a8eca cmp r6, #0x0 */
/* @0x2a8ecc bne 0x2a8f80 <png_do_read_filler+0xc2> */
/* @0x2a8ece ldrb r6, [r0, #0x9] */
/* @0x2a8ed0 cmp r6, #0x8 */
/* @0x2a8ed2 bne 0x2a8f16 <png_do_read_filler+0x58> */
/* @0x2a8ed4 tst.w r3, #0x80 */
/* @0x2a8ed6 strtmi r0, [r1], #-3968 */
/* @0x2a8ed8 add r1, r4 */
/* @0x2a8eda add.w r3, r1, r4 */
/* @0x2a8ede beq 0x2a8ef6 <png_do_read_filler+0x38> */
/* @0x2a8ee0 movs r5, #0x1 */
/* @0x2a8ee2 cmp r5, r4 */
/* @0x2a8ee4 strb r2, [r3, #-1] */
/* @0x2a8ee6 andle r2, pc, #256 */
/* @0x2a8ee8 bhs 0x2a8f0a <png_do_read_filler+0x4c> */
/* @0x2a8eea ldrb r6, [r1, #-1]! */
/* @0x2a8eee adds r5, #0x1 */
/* @0x2a8ef0 strb r6, [r3, #-2]! */
/* @0x2a8ef2 ldrb r6, [r5, r2, lsl #26]! */
/* @0x2a8ef4 b 0x2a8ee2 <png_do_read_filler+0x24> */
/* @0x2a8ef6 subs r5, r1, r4 */
/* @0x2a8ef8 cmp r1, r5 */
/* @0x2a8efa beq 0x2a8f0a <png_do_read_filler+0x4c> */
/* @0x2a8efc ldrb r6, [r1, #-1]! */
/* @0x2a8efe .word 0xf8036d01 */
/* @0x2a8f00 strb r6, [r3, #-1] */
/* @0x2a8f02 .word 0xf8036c01 */
/* @0x2a8f04 strb r2, [r3, #-2]! */
/* @0x2a8f06 ldrb r2, [r6, r2, lsl #26]! */
/* @0x2a8f08 b 0x2a8ef8 <png_do_read_filler+0x3a> */
/* @0x2a8f0a movs r3, #0x2 */
/* @0x2a8f0c lsls r4, r4, #0x1 */
/* @0x2a8f0e strb r3, [r0, #0xa] */
/* @0x2a8f10 movs r3, #0x10 */
/* @0x2a8f12 strb r3, [r0, #0xb] */
/* @0x2a8f14 b 0x2a905a <png_do_read_filler+0x19c> */
/* @0x2a8f16 cmp r6, #0x10 */
/* @0x2a8f18 bne.w 0x2a90aa <png_do_read_filler+0x1ec> */
/* @0x2a8f1a .word 0xf01380c7 */
/* @0x2a8f1c ands r3, r3, #0x80 */
/* @0x2a8f1e b 0x1669d26 <b2_toiTime+0xf10882> */
/* @0x2a8f20 lsl.w r6, r4, #0x1 */
/* @0x2a8f22 ldrtmi r0, [r1], #-1604 */
/* @0x2a8f24 add r1, r6 */
/* @0x2a8f26 beq 0x2a8f50 <png_do_read_filler+0x92> */
/* @0x2a8f28 adds r3, r1, r6 */
/* @0x2a8f2a movs r6, #0x1 */
/* @0x2a8f2c cmp r6, r4 */
/* @0x2a8f2e strb r5, [r3, #-1] */
/* @0x2a8f32 strb r2, [r3, #-2] */
/* @0x2a8f36 bhs 0x2a8f4c <png_do_read_filler+0x8e> */
/* @0x2a8f38 ldrb r7, [r1, #-1] */
/* @0x2a8f3a strlo r7, [r1], -r1, lsl #24 */
/* @0x2a8f3c adds r6, #0x1 */
/* @0x2a8f3e strb r7, [r3, #-3] */
/* @0x2a8f42 ldrb r7, [r1, #-2]! */
/* @0x2a8f46 strb r7, [r3, #-4]! */
/* @0x2a8f4a b 0x2a8f2c <png_do_read_filler+0x6e> */
/* @0x2a8f4c movs r3, #0x2 */
/* @0x2a8f4e b 0x2a8fee <png_do_read_filler+0x130> */
/* @0x2a8f50 add r6, r1 */
/* @0x2a8f52 cmp r3, r4 */
/* @0x2a8f54 beq 0x2a8f72 <png_do_read_filler+0xb4> */
/* @0x2a8f56 ldrb r7, [r1, #-1] */
/* @0x2a8f5a adds r3, #0x1 */
/* @0x2a8f5c strb r7, [r6, #-1] */
/* @0x2a8f5e .word 0xf8117c01 */
/* @0x2a8f60 ldrb r7, [r1, #-2]! */
/* @0x2a8f62 .word 0xf8067d02 */
/* @0x2a8f64 strb r5, [r6, #-3] */
/* @0x2a8f66 .word 0xf8065c03 */
/* @0x2a8f68 strb r7, [r6, #-2] */
/* @0x2a8f6a .word 0xf8067c02 */
/* @0x2a8f6c strb r2, [r6, #-4]! */
/* @0x2a8f6e strb r2, [pc, r4, lsl #26]! */
/* @0x2a8f70 b 0x2a8f52 <png_do_read_filler+0x94> */
/* @0x2a8f72 movs r2, #0x2 */
/* @0x2a8f74 lsls r3, r3, #0x2 */
/* @0x2a8f76 strb r2, [r0, #0xa] */
/* @0x2a8f78 movs r2, #0x20 */
/* @0x2a8f7a str r3, [r0, #0x4] */
/* @0x2a8f7c strb r2, [r0, #0xb] */
/* @0x2a8f7e pop {r4, r5, r6, r7, pc} */
/* @0x2a8f80 cmp r6, #0x2 */
/* @0x2a8f82 bne.w 0x2a90aa <png_do_read_filler+0x1ec> */
/* @0x2a8f86 ldrb r6, [r0, #0x9] */
/* @0x2a8f88 cmp r6, #0x8 */
/* @0x2a8f8a bne 0x2a8ff8 <png_do_read_filler+0x13a> */
/* @0x2a8f8c tst.w r3, #0x80 */
/* @0x2a8f8e .word 0xf04f0f80 */
/* @0x2a8f90 mov.w r5, #0x3 */
/* @0x2a8f92 andsle r0, r5, r3, lsl #10 */
/* @0x2a8f94 beq 0x2a8fc2 <png_do_read_filler+0x104> */
/* @0x2a8f96 mla r1, r5, r4, r1 */
/* @0x2a8f9a movs r5, #0x1 */
/* @0x2a8f9c adds r3, r1, r4 */
/* @0x2a8f9e cmp r5, r4 */
/* @0x2a8fa0 strb r2, [r3, #-1] */
/* @0x2a8fa2 eorle r2, r2, #256 */
/* @0x2a8fa4 bhs 0x2a8fec <png_do_read_filler+0x12e> */
/* @0x2a8fa6 ldrb r6, [r1, #-1] */
/* @0x2a8faa adds r5, #0x1 */
/* @0x2a8fac strb r6, [r3, #-2] */
/* @0x2a8fae .word 0xf8116c02 */
/* @0x2a8fb0 ldrb r6, [r1, #-2] */
/* @0x2a8fb2 .word 0xf8036c02 */
/* @0x2a8fb4 strb r6, [r3, #-3] */
/* @0x2a8fb6 .word 0xf8116c03 */
/* @0x2a8fb8 ldrb r6, [r1, #-3]! */
/* @0x2a8fba .word 0xf8036d03 */
/* @0x2a8fbc strb r6, [r3, #-4]! */
/* @0x2a8fbe strb r6, [sp, r4, lsl #26]! */
/* @0x2a8fc0 b 0x2a8f9e <png_do_read_filler+0xe0> */
/* @0x2a8fc2 muls r5, r4, r5 */
/* @0x2a8fc4 add r1, r5 */
/* @0x2a8fc6 adds r3, r1, r4 */
/* @0x2a8fc8 subs r5, r1, r5 */
/* @0x2a8fca cmp r1, r5 */
/* @0x2a8fcc beq 0x2a8fec <png_do_read_filler+0x12e> */
/* @0x2a8fce ldrb r6, [r1, #-1] */
/* @0x2a8fd2 strb r6, [r3, #-1] */
/* @0x2a8fd6 ldrb r6, [r1, #-2] */
/* @0x2a8fda strb r6, [r3, #-2] */
/* @0x2a8fde ldrb r6, [r1, #-3]! */
/* @0x2a8fe2 strb r6, [r3, #-3] */
/* @0x2a8fe6 strb r2, [r3, #-4]! */
/* @0x2a8fea b 0x2a8fca <png_do_read_filler+0x10c> */
/* @0x2a8fec movs r3, #0x4 */
/* @0x2a8fee strb r3, [r0, #0xa] */
/* @0x2a8ff0 lsls r4, r4, #0x2 */
/* @0x2a8ff2 movs r3, #0x20 */
/* @0x2a8ff4 strb r3, [r0, #0xb] */
/* @0x2a8ff6 b 0x2a905a <png_do_read_filler+0x19c> */
/* @0x2a8ff8 cmp r6, #0x10 */
/* @0x2a8ffa bne 0x2a90aa <png_do_read_filler+0x1ec> */
/* @0x2a8ffc movs r7, #0x6 */
/* @0x2a8ffe ands r6, r3, #0x80 */
/* @0x2a9002 mla r1, r7, r4, r1 */
/* @0x2a9006 lsl.w r3, r4, #0x1 */
/* @0x2a900a add r3, r1 */
/* @0x2a900c beq 0x2a905e <png_do_read_filler+0x1a0> */
/* @0x2a900e movs r6, #0x1 */
/* @0x2a9010 cmp r6, r4 */
/* @0x2a9012 strb r5, [r3, #-1] */
/* @0x2a9016 strb r2, [r3, #-2] */
/* @0x2a901a bhs 0x2a9050 <png_do_read_filler+0x192> */
/* @0x2a901c ldrb r7, [r1, #-1] */
/* @0x2a901e strlo r7, [r1], -r1, lsl #24 */
/* @0x2a9020 adds r6, #0x1 */
/* @0x2a9022 strb r7, [r3, #-3] */
/* @0x2a9026 ldrb r7, [r1, #-2] */
/* @0x2a902a strb r7, [r3, #-4] */
/* @0x2a902e ldrb r7, [r1, #-3] */
/* @0x2a9032 strb r7, [r3, #-5] */
/* @0x2a9036 ldrb r7, [r1, #-4] */
/* @0x2a903a strb r7, [r3, #-6] */
/* @0x2a903e ldrb r7, [r1, #-5] */
/* @0x2a9042 strb r7, [r3, #-7] */
/* @0x2a9046 ldrb r7, [r1, #-6]! */
/* @0x2a904a strb r7, [r3, #-8]! */
/* @0x2a904e b 0x2a9010 <png_do_read_filler+0x152> */
/* @0x2a9050 lsls r4, r4, #0x3 */
/* @0x2a9052 movs r3, #0x4 */
/* @0x2a9054 strb r3, [r0, #0xa] */
/* @0x2a9056 movs r3, #0x40 */
/* @0x2a9058 strb r3, [r0, #0xb] */
/* @0x2a905a str r4, [r0, #0x4] */
/* @0x2a905c pop {r4, r5, r6, r7, pc} */
/* @0x2a905e cmp r6, r4 */
/* @0x2a9060 beq 0x2a909e <png_do_read_filler+0x1e0> */
/* @0x2a9062 ldrb r7, [r1, #-1] */
/* @0x2a9066 adds r6, #0x1 */
/* @0x2a9068 strb r7, [r3, #-1] */
/* @0x2a906a .word 0xf8117c01 */
/* @0x2a906c ldrb r7, [r1, #-2] */
/* @0x2a906e .word 0xf8037c02 */
/* @0x2a9070 strb r7, [r3, #-2] */
/* @0x2a9072 .word 0xf8117c02 */
/* @0x2a9074 ldrb r7, [r1, #-3] */
/* @0x2a9076 .word 0xf8037c03 */
/* @0x2a9078 strb r7, [r3, #-3] */
/* @0x2a907a .word 0xf8117c03 */
/* @0x2a907c ldrb r7, [r1, #-4] */
/* @0x2a907e .word 0xf8037c04 */
/* @0x2a9080 strb r7, [r3, #-4] */
/* @0x2a9082 .word 0xf8117c04 */
/* @0x2a9084 ldrb r7, [r1, #-5] */
/* @0x2a9086 .word 0xf8037c05 */
/* @0x2a9088 strb r7, [r3, #-5] */
/* @0x2a908a .word 0xf8117c05 */
/* @0x2a908c ldrb r7, [r1, #-6]! */
/* @0x2a908e .word 0xf8037d06 */
/* @0x2a9090 strb r5, [r3, #-7] */
/* @0x2a9092 .word 0xf8035c07 */
/* @0x2a9094 strb r7, [r3, #-6] */
/* @0x2a9096 .word 0xf8037c06 */
/* @0x2a9098 strb r2, [r3, #-8]! */
/* @0x2a909a ldrb r2, [pc, r8, lsl #26] */
/* @0x2a909c b 0x2a905e <png_do_read_filler+0x1a0> */
/* @0x2a909e movs r3, #0x4 */
/* @0x2a90a0 lsls r6, r6, #0x3 */
/* @0x2a90a2 strb r3, [r0, #0xa] */
/* @0x2a90a4 movs r3, #0x40 */
/* @0x2a90a6 str r6, [r0, #0x4] */
/* @0x2a90a8 strb r3, [r0, #0xb] */
/* @0x2a90aa pop {r4, r5, r6, r7, pc} */
