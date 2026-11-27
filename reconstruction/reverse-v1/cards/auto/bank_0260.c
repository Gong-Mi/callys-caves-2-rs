/* libyoyo.so 覆盖卡组 0260
 * 函数 0x2b0884..0x2b1814，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2b0884 · png_set_filter_heuristics · size=2 · insn=1 */
/* @0x2b0884 bx lr */

/* ── FUNC 0x2b0886 · png_set_compression_level · size=20 · insn=10 */
/* @0x2b0886 cbz r0, 0x2b0898 <png_set_compression_level+0x12> */
/* @0x2b0888 ldr.w r3, [r0, #0x130] */
/* @0x2b088a .word 0xf8c03130 */
/* @0x2b088c str.w r1, [r0, #0x178] */
/* @0x2b088e .word 0xf0431178 */
/* @0x2b0890 orr r3, r3, #0x2 */
/* @0x2b0892 .word 0xf8c00302 */
/* @0x2b0894 str.w r3, [r0, #0x130] */
/* @0x2b0896 .word 0x47703130 */
/* @0x2b0898 bx lr */

/* ── FUNC 0x2b089a · png_set_compression_mem_level · size=20 · insn=10 */
/* @0x2b089a cbz r0, 0x2b08ac <png_set_compression_mem_level+0x12> */
/* @0x2b089c ldr.w r3, [r0, #0x130] */
/* @0x2b089e .word 0xf8c03130 */
/* @0x2b08a0 str.w r1, [r0, #0x184] */
/* @0x2b08a2 .word 0xf0431184 */
/* @0x2b08a4 orr r3, r3, #0x4 */
/* @0x2b08a6 .word 0xf8c00304 */
/* @0x2b08a8 str.w r3, [r0, #0x130] */
/* @0x2b08aa .word 0x47703130 */
/* @0x2b08ac bx lr */

/* ── FUNC 0x2b08ae · png_set_compression_strategy · size=20 · insn=10 */
/* @0x2b08ae cbz r0, 0x2b08c0 <png_set_compression_strategy+0x12> */
/* @0x2b08b0 ldr.w r3, [r0, #0x130] */
/* @0x2b08b2 .word 0xf8c03130 */
/* @0x2b08b4 str.w r1, [r0, #0x188] */
/* @0x2b08b6 .word 0xf0431188 */
/* @0x2b08b8 orr r3, r3, #0x1 */
/* @0x2b08ba .word 0xf8c00301 */
/* @0x2b08bc str.w r3, [r0, #0x130] */
/* @0x2b08be .word 0x47703130 */
/* @0x2b08c0 bx lr */

/* ── FUNC 0x2b08c2 · anon_2b08c2 · size=0 · insn=1 */
/* @0x2b08c2 ldrlt r0, [r8, #-0x0]! */

/* ── FUNC 0x2b08c4 · png_set_compression_window_bits · size=76 · insn=38 */
/* @0x2b08c4 push {r3, r4, r5, lr} */
/* @0x2b08c6 mov r4, r1 */
/* @0x2b08c8 mov r5, r0 */
/* @0x2b08ca cbz r0, 0x2b0902 <png_set_compression_window_bits+0x3e> */
/* @0x2b08cc cmp r1, #0xf */
/* @0x2b08ce ble 0x2b08d6 <png_set_compression_window_bits+0x12> */
/* @0x2b08d0 ldr r1, [pc, #0x30] */
/* @0x2b08d2 add r1, pc */
/* @0x2b08d4 b 0x2b08de <png_set_compression_window_bits+0x1a> */
/* @0x2b08d6 cmp r1, #0x7 */
/* @0x2b08d8 bgt 0x2b08e4 <png_set_compression_window_bits+0x20> */
/* @0x2b08da ldr r1, [pc, #0x2c] */
/* @0x2b08dc add r1, pc */
/* @0x2b08de bl 0x2a6474 <png_warning> */
/* @0x2b08e0 and pc, r6, r9, asr #27 */
/* @0x2b08e2 b 0x2b08f2 <png_set_compression_window_bits+0x2e> */
/* @0x2b08e4 cmp r1, #0x8 */
/* @0x2b08e6 bne 0x2b08f2 <png_set_compression_window_bits+0x2e> */
/* @0x2b08e8 ldr r1, [pc, #0x20] */
/* @0x2b08ea movs r4, #0x9 */
/* @0x2b08ec add r1, pc */
/* @0x2b08ee bl 0x2a6474 <png_warning> */
/* @0x2b08f0 .word 0xf8d5fdc1 */
/* @0x2b08f2 ldr.w r3, [r5, #0x130] */
/* @0x2b08f4 .word 0xf8c53130 */
/* @0x2b08f6 str.w r4, [r5, #0x180] */
/* @0x2b08f8 .word 0xf0434180 */
/* @0x2b08fa orr r3, r3, #0x8 */
/* @0x2b08fc .word 0xf8c50308 */
/* @0x2b08fe str.w r3, [r5, #0x130] */
/* @0x2b0900 ldclt p1, c3, [r8, #-192]! */
/* @0x2b0902 pop {r3, r4, r5, pc} */
/* @0x2b0904 bvc 0x2b09d0 <png_write_png+0x78> */
/* @0x2b0906 movs r5, r1 */
/* @0x2b0908 bvc 0x2b0822 <png_set_filter+0x112> */
/* @0x2b090a movs r5, r1 */
/* @0x2b090c bvc 0x2b0868 <png_set_filter+0x158> */
/* @0x2b090e movs r5, r1 */

/* ── FUNC 0x2b0910 · png_set_compression_method · size=44 · insn=17 */
/* @0x2b0910 push {r3, r4, r5, lr} */
/* @0x2b0912 mov r5, r1 */
/* @0x2b0914 mov r4, r0 */
/* @0x2b0916 cbz r0, 0x2b0934 <png_set_compression_method+0x24> */
/* @0x2b0918 cmp r1, #0x8 */
/* @0x2b091a beq 0x2b0924 <png_set_compression_method+0x14> */
/* @0x2b091c ldr r1, [pc, #0x18] */
/* @0x2b091e add r1, pc */
/* @0x2b0920 bl 0x2a6474 <png_warning> */
/* @0x2b0924 ldr.w r3, [r4, #0x130] */
/* @0x2b0928 str.w r5, [r4, #0x17c] */
/* @0x2b092c orr r3, r3, #0x10 */
/* @0x2b0930 str.w r3, [r4, #0x130] */
/* @0x2b0934 pop {r3, r4, r5, pc} */
/* @0x2b0936 nop */
/* @0x2b0938 bvc 0x2b0882 <png_set_filter+0x172> */
/* @0x2b093a movs r5, r1 */

/* ── FUNC 0x2b093c · png_set_write_status_fn · size=8 · insn=4 */
/* @0x2b093c cbz r0, 0x2b0942 <png_set_write_status_fn+0x6> */
/* @0x2b093e str.w r1, [r0, #0x260] */
/* @0x2b0940 ldrbmi r1, [r0, -r0, ror #4]! */
/* @0x2b0942 bx lr */

/* ── FUNC 0x2b0944 · png_set_write_user_transform_fn · size=20 · insn=10 */
/* @0x2b0944 cbz r0, 0x2b0956 <png_set_write_user_transform_fn+0x12> */
/* @0x2b0946 ldr.w r3, [r0, #0x134] */
/* @0x2b0948 .word 0xf8c03134 */
/* @0x2b094a str.w r1, [r0, #0x120] */
/* @0x2b094c vst4.8 {d17, d19, d21, d23}, [r3:128], r0 */
/* @0x2b094e orr r3, r3, #0x100000 */
/* @0x2b0950 .word 0xf8c01380 */
/* @0x2b0952 str.w r3, [r0, #0x134] */
/* @0x2b0954 .word 0x47703134 */
/* @0x2b0956 bx lr */

/* ── FUNC 0x2b0958 · png_write_png · size=166 · insn=74 */
/* @0x2b0958 push {r4, r5, r6, lr} */
/* @0x2b095a mov r6, r1 */
/* @0x2b095c mov r5, r2 */
/* @0x2b095e mov r4, r0 */
/* @0x2b0960 cmp r0, #0x0 */
/* @0x2b0962 beq 0x2b09fc <png_write_png+0xa4> */
/* @0x2b0964 cmp r1, #0x0 */
/* @0x2b0966 beq 0x2b09fc <png_write_png+0xa4> */
/* @0x2b0968 bl 0x2afe14 <png_write_info> */
/* @0x2b096c lsls r1, r5, #0x1a */
/* @0x2b096e bpl 0x2b0976 <png_write_png+0x1e> */
/* @0x2b0970 mov r0, r4 */
/* @0x2b0972 bl 0x2af84a <png_set_invert_mono> */
/* @0x2b0974 strbteq pc, [r10], -r10, ror #30 */
/* @0x2b0976 lsls r2, r5, #0x19 */
/* @0x2b0978 bpl 0x2b098a <png_write_png+0x32> */
/* @0x2b097a ldr r3, [r6, #0x8] */
/* @0x2b097c lsls r3, r3, #0x1e */
/* @0x2b097e bpl 0x2b098a <png_write_png+0x32> */
/* @0x2b0980 mov r0, r4 */
/* @0x2b0982 add.w r1, r6, #0x44 */
/* @0x2b0984 .word 0xf7fe0144 */
/* @0x2b0986 bl 0x2af796 <png_set_shift> */
/* @0x2b0988 strbeq pc, [r8, -r6, lsl #30]! */
/* @0x2b098a lsls r0, r5, #0x1d */
/* @0x2b098c bpl 0x2b0994 <png_write_png+0x3c> */
/* @0x2b098e mov r0, r4 */
/* @0x2b0990 bl 0x2af760 <png_set_packing> */
/* @0x2b0994 lsls r1, r5, #0x17 */
/* @0x2b0996 bpl 0x2b099e <png_write_png+0x46> */
/* @0x2b0998 mov r0, r4 */
/* @0x2b099a bl 0x2af82a <png_set_swap_alpha> */
/* @0x2b099c .word 0xf415ff46 */
/* @0x2b099e ands r1, r5, #0x1000 */
/* @0x2b09a0 andle r5, r3, r0, lsl #3 */
/* @0x2b09a2 beq 0x2b09ac <png_write_png+0x54> */
/* @0x2b09a4 mov r0, r4 */
/* @0x2b09a6 movs r1, #0x0 */
/* @0x2b09a8 movs r2, #0x1 */
/* @0x2b09aa b 0x2b09b4 <png_write_png+0x5c> */
/* @0x2b09ac lsls r2, r5, #0x14 */
/* @0x2b09ae bpl 0x2b09b8 <png_write_png+0x60> */
/* @0x2b09b0 mov r0, r4 */
/* @0x2b09b2 mov r2, r1 */
/* @0x2b09b4 bl 0x2af7ce <png_set_filler> */
/* @0x2b09b8 lsls r3, r5, #0x18 */
/* @0x2b09ba bpl 0x2b09c2 <png_write_png+0x6a> */
/* @0x2b09bc mov r0, r4 */
/* @0x2b09be bl 0x2af738 <png_set_bgr> */
/* @0x2b09c0 streq pc, [r8, #0xebb]! */
/* @0x2b09c2 lsls r0, r5, #0x16 */
/* @0x2b09c4 bpl 0x2b09cc <png_write_png+0x74> */
/* @0x2b09c6 mov r0, r4 */
/* @0x2b09c8 bl 0x2af748 <png_set_swap> */
/* @0x2b09cc lsls r1, r5, #0x1c */
/* @0x2b09ce bpl 0x2b09d6 <png_write_png+0x7e> */
/* @0x2b09d0 mov r0, r4 */
/* @0x2b09d2 bl 0x2af77e <png_set_packswap> */
/* @0x2b09d4 strbeq pc, [r10, #-0xed4]! */
/* @0x2b09d6 lsls r2, r5, #0x15 */
/* @0x2b09d8 bpl 0x2b09e0 <png_write_png+0x88> */
/* @0x2b09da mov r0, r4 */
/* @0x2b09dc bl 0x2af83a <png_set_invert_alpha> */
/* @0x2b09e0 ldr r3, [r6, #0x8] */
/* @0x2b09e2 lsls r3, r3, #0x10 */
/* @0x2b09e4 bpl 0x2b09f0 <png_write_png+0x98> */
/* @0x2b09e6 mov r0, r4 */
/* @0x2b09e8 ldr.w r1, [r6, #0xf8] */
/* @0x2b09ec bl 0x2b0510 <png_write_image> */
/* @0x2b09f0 mov r0, r4 */
/* @0x2b09f2 mov r1, r6 */
/* @0x2b09f4 pop.w {r4, r5, r6, lr} */
/* @0x2b09f8 b.w 0x2b002c <png_write_end> */
/* @0x2b09fc pop {r4, r5, r6, pc} */

/* ── FUNC 0x2b09fe · png_do_pack · size=214 · insn=96 */
/* @0x2b09fe ldr r3, [r0, #0x8] */
/* @0x2b0a00 push {r4, r5, r6, r7, lr} */
/* @0x2b0a02 bic r3, r3, #0xff000000 */
/* @0x2b0a06 bic r3, r3, #0xff */
/* @0x2b0a0a cmp.w r3, #0x10800 */
/* @0x2b0a0e bne 0x2b0ad2 <png_do_pack+0xd4> */
/* @0x2b0a10 cmp r2, #0x2 */
/* @0x2b0a12 ldr r6, [r0] */
/* @0x2b0a14 beq 0x2b0a4e <png_do_pack+0x50> */
/* @0x2b0a16 cmp r2, #0x4 */
/* @0x2b0a18 beq 0x2b0a80 <png_do_pack+0x82> */
/* @0x2b0a1a cmp r2, #0x1 */
/* @0x2b0a1c bne 0x2b0ab4 <png_do_pack+0xb6> */
/* @0x2b0a1e movs r5, #0x0 */
/* @0x2b0a20 mov r7, r1 */
/* @0x2b0a22 mov r4, r5 */
/* @0x2b0a24 movs r3, #0x80 */
/* @0x2b0a26 cmp r5, r6 */
/* @0x2b0a28 beq 0x2b0a4a <png_do_pack+0x4c> */
/* @0x2b0a2a ldrb.w r12, [r1, r5] */
/* @0x2b0a2e cmp.w r12, #0x0 */
/* @0x2b0a32 beq 0x2b0a36 <png_do_pack+0x38> */
/* @0x2b0a34 orrs r4, r3 */
/* @0x2b0a36 cmp r3, #0x1 */
/* @0x2b0a38 add.w r5, r5, #0x1 */
/* @0x2b0a3a svclt #0xd70501 */
/* @0x2b0a3c itett le */
/* @0x2b0a3e strble r4, [r7], #1 */
/* @0x2b0a42 asrgt r3, r3, #0x1 */
/* @0x2b0a44 movle r4, #0x0 */
/* @0x2b0a46 movle r3, #0x80 */
/* @0x2b0a48 b 0x2b0a26 <png_do_pack+0x28> */
/* @0x2b0a4a cmp r3, #0x80 */
/* @0x2b0a4c b 0x2b0ab0 <png_do_pack+0xb2> */
/* @0x2b0a4e movs r5, #0x0 */
/* @0x2b0a50 mov r7, r1 */
/* @0x2b0a52 mov r4, r5 */
/* @0x2b0a54 movs r3, #0x6 */
/* @0x2b0a56 cmp r5, r6 */
/* @0x2b0a58 beq 0x2b0a7c <png_do_pack+0x7e> */
/* @0x2b0a5a ldrb.w r12, [r1, r5] */
/* @0x2b0a5e and r12, r12, #0x3 */
/* @0x2b0a62 lsl.w r12, r12, r3 */
/* @0x2b0a66 orr.w r4, r4, r12 */
/* @0x2b0a6a cbnz r3, 0x2b0a76 <png_do_pack+0x78> */
/* @0x2b0a6c strb r4, [r7], #1 */
/* @0x2b0a6e ldrmi r4, [r12], -r1, lsl #22 */
/* @0x2b0a70 mov r4, r3 */
/* @0x2b0a72 movs r3, #0x6 */
/* @0x2b0a74 b 0x2b0a78 <png_do_pack+0x7a> */
/* @0x2b0a76 subs r3, #0x2 */
/* @0x2b0a78 adds r5, #0x1 */
/* @0x2b0a7a b 0x2b0a56 <png_do_pack+0x58> */
/* @0x2b0a7c cmp r3, #0x6 */
/* @0x2b0a7e b 0x2b0ab0 <png_do_pack+0xb2> */
/* @0x2b0a80 movs r5, #0x0 */
/* @0x2b0a82 mov r7, r1 */
/* @0x2b0a84 mov r4, r5 */
/* @0x2b0a86 mov r3, r2 */
/* @0x2b0a88 cmp r5, r6 */
/* @0x2b0a8a beq 0x2b0aae <png_do_pack+0xb0> */
/* @0x2b0a8c ldrb.w r12, [r1, r5] */
/* @0x2b0a8e .word 0xf00cc005 */
/* @0x2b0a90 and r12, r12, #0xf */
/* @0x2b0a92 blx 0x5b3ad6 <g_SWFlineaavertbuff+0x60a0e> */
/* @0x2b0a94 lsl.w r12, r12, r3 */
/* @0x2b0a96 b 0x13efaaa <b2_toiTime+0xc96606> */
/* @0x2b0a98 orr.w r4, r4, r12 */
/* @0x2b0a9a stmdblt r3!, {r2, r3, r10} */
/* @0x2b0a9c cbnz r3, 0x2b0aa8 <png_do_pack+0xaa> */
/* @0x2b0a9e strb r4, [r7], #1 */
/* @0x2b0aa2 mov r4, r3 */
/* @0x2b0aa4 movs r3, #0x4 */
/* @0x2b0aa6 b 0x2b0aaa <png_do_pack+0xac> */
/* @0x2b0aa8 subs r3, #0x4 */
/* @0x2b0aaa adds r5, #0x1 */
/* @0x2b0aac b 0x2b0a88 <png_do_pack+0x8a> */
/* @0x2b0aae cmp r3, #0x4 */
/* @0x2b0ab0 it ne */
/* @0x2b0ab2 strbne r4, [r7] */
/* @0x2b0ab4 ldrb r3, [r0, #0xa] */
/* @0x2b0ab6 strb r2, [r0, #0x9] */
/* @0x2b0ab8 muls r2, r3, r2 */
/* @0x2b0aba ldr r3, [r0] */
/* @0x2b0abc uxtb r2, r2 */
/* @0x2b0abe strb r2, [r0, #0xb] */
/* @0x2b0ac0 cmp r2, #0x7 */
/* @0x2b0ac2 bls 0x2b0aca <png_do_pack+0xcc> */
/* @0x2b0ac4 lsrs r2, r2, #0x3 */
/* @0x2b0ac6 muls r2, r3, r2 */
/* @0x2b0ac8 b 0x2b0ad0 <png_do_pack+0xd2> */
/* @0x2b0aca muls r2, r3, r2 */
/* @0x2b0acc adds r2, #0x7 */
/* @0x2b0ace lsrs r2, r2, #0x3 */
/* @0x2b0ad0 str r2, [r0, #0x4] */
/* @0x2b0ad2 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2b0ad4 · png_do_shift · size=388 · insn=174 */
/* @0x2b0ad4 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b0ad8 sub sp, #0x24 */
/* @0x2b0ada ldrb r5, [r0, #0x8] */
/* @0x2b0adc cmp r5, #0x3 */
/* @0x2b0ade beq.w 0x2b0c52 <png_do_shift+0x17e> */
/* @0x2b0ae0 .word 0xf01580b8 */
/* @0x2b0ae2 tst.w r5, #0x2 */
/* @0x2b0ae4 bvc 0x13746f4 <b2_toiTime+0xc1b250> */
/* @0x2b0ae6 ldrb r3, [r0, #0x9] */
/* @0x2b0ae8 beq 0x2b0b06 <png_do_shift+0x32> */
/* @0x2b0aea ldrb r4, [r2] */
/* @0x2b0aec subs r6, r3, r4 */
/* @0x2b0aee str r6, [sp] */
/* @0x2b0af0 str r4, [sp, #0x10] */
/* @0x2b0af2 ldrb r4, [r2, #0x1] */
/* @0x2b0af4 subs r6, r3, r4 */
/* @0x2b0af6 str r6, [sp, #0x4] */
/* @0x2b0af8 str r4, [sp, #0x14] */
/* @0x2b0afa ldrb r4, [r2, #0x2] */
/* @0x2b0afc subs r6, r3, r4 */
/* @0x2b0afe str r6, [sp, #0x8] */
/* @0x2b0b00 str r4, [sp, #0x18] */
/* @0x2b0b02 movs r4, #0x3 */
/* @0x2b0b04 b 0x2b0b10 <png_do_shift+0x3c> */
/* @0x2b0b06 ldrb r4, [r2, #0x3] */
/* @0x2b0b08 subs r6, r3, r4 */
/* @0x2b0b0a str r6, [sp] */
/* @0x2b0b0c str r4, [sp, #0x10] */
/* @0x2b0b0e movs r4, #0x1 */
/* @0x2b0b10 lsls r5, r5, #0x1d */
/* @0x2b0b12 bpl 0x2b0b28 <png_do_shift+0x54> */
/* @0x2b0b14 ldrb r6, [r2, #0x4] */
/* @0x2b0b16 add r7, sp, #0x20 */
/* @0x2b0b18 add.w r5, r7, r4, lsl #2 */
/* @0x2b0b1c adds r4, #0x1 */
/* @0x2b0b1e subs r7, r3, r6 */
/* @0x2b0b20 str r6, [r5, #-16] */
/* @0x2b0b24 str r7, [r5, #-32] */
/* @0x2b0b28 cmp r3, #0x7 */
/* @0x2b0b2a bhi 0x2b0b96 <png_do_shift+0xc2> */
/* @0x2b0b2c ldrb r2, [r2, #0x3] */
/* @0x2b0b2e ldr r4, [r0, #0x4] */
/* @0x2b0b30 cmp r2, #0x1 */
/* @0x2b0b32 bne 0x2b0b3e <png_do_shift+0x6a> */
/* @0x2b0b34 cmp r3, #0x2 */
/* @0x2b0b36 ite eq */
/* @0x2b0b38 moveq r3, #0x55 */
/* @0x2b0b3a movne r3, #0xff */
/* @0x2b0b3c b 0x2b0b4e <png_do_shift+0x7a> */
/* @0x2b0b3e cmp r3, #0x4 */
/* @0x2b0b40 bne 0x2b0b4c <png_do_shift+0x78> */
/* @0x2b0b42 cmp r2, #0x3 */
/* @0x2b0b44 ite eq */
/* @0x2b0b46 moveq r3, #0x11 */
/* @0x2b0b48 movne r3, #0xff */
/* @0x2b0b4a b 0x2b0b4e <png_do_shift+0x7a> */
/* @0x2b0b4c movs r3, #0xff */
/* @0x2b0b4e ldr r5, [sp] */
/* @0x2b0b50 add.w r12, r1, r4 */
/* @0x2b0b54 ldr r0, [sp, #0x10] */
/* @0x2b0b56 mov.w r9, #0x0 */
/* @0x2b0b58 .word 0xf1c50900 */
/* @0x2b0b5a rsb.w r10, r5, #0x0 */
/* @0x2b0b5c .word 0xf1c00a00 */
/* @0x2b0b5e rsb.w r8, r0, #0x0 */
/* @0x2b0b60 strbmi r0, [r1, #-0x800]! */
/* @0x2b0b62 cmp r1, r12 */
/* @0x2b0b64 beq 0x2b0c52 <png_do_shift+0x17e> */
/* @0x2b0b66 mov r4, r10 */
/* @0x2b0b68 mov r2, r5 */
/* @0x2b0b6a ldrb r6, [r1] */
/* @0x2b0b6c strb r9, [r1], #1 */
/* @0x2b0b70 cmp r2, r8 */
/* @0x2b0b72 ble 0x2b0b62 <png_do_shift+0x8e> */
/* @0x2b0b74 cmp r2, #0x0 */
/* @0x2b0b76 ldrb r7, [r1, #-1] */
/* @0x2b0b78 svclt #0xd67c01 */
/* @0x2b0b7a itet le */
/* @0x2b0b7c asrle.w r11, r6, r4 */
/* @0x2b0b80 lslgt.w r11, r6, r2 */
/* @0x2b0b84 andle.w r11, r11, r3 */
/* @0x2b0b88 subs r2, r2, r0 */
/* @0x2b0b8a orr.w r7, r11, r7 */
/* @0x2b0b8c strmi r0, [r4], #-1799 */
/* @0x2b0b8e add r4, r0 */
/* @0x2b0b90 strb r7, [r1, #-1] */
/* @0x2b0b94 b 0x2b0b70 <png_do_shift+0x9c> */
/* @0x2b0b96 cmp r3, #0x8 */
/* @0x2b0b98 ldr r3, [r0] */
/* @0x2b0b9a mul r8, r3, r4 */
/* @0x2b0b9c .word 0xd128f804 */
/* @0x2b0b9e bne 0x2b0bf2 <png_do_shift+0x11e> */
/* @0x2b0ba0 movs r6, #0x0 */
/* @0x2b0ba2 mov r5, r1 */
/* @0x2b0ba4 mov r9, r6 */
/* @0x2b0ba6 cmp r6, r8 */
/* @0x2b0ba8 beq 0x2b0c52 <png_do_shift+0x17e> */
/* @0x2b0baa mov r0, r6 */
/* @0x2b0bac mov r1, r4 */
/* @0x2b0bae blx 0x318cf0 <__aeabi_uidivmod> */
/* @0x2b0bb0 blge 0x4eae38 <SrcVerts+0x47e7c> */
/* @0x2b0bb2 add r3, sp, #0x20 */
/* @0x2b0bb4 ldrb r0, [r5] */
/* @0x2b0bb6 strb r9, [r5], #1 */
/* @0x2b0bb8 bl 0x3977c4 <ft_adobe_glyph_list+0x6ea0> */
/* @0x2b0bba add.w r1, r3, r1, lsl #2 */
/* @0x2b0bbc .word 0xf8510181 */
/* @0x2b0bbe ldr r3, [r1, #-32] */
/* @0x2b0bc0 .word 0xf8513c20 */
/* @0x2b0bc2 ldr r1, [r1, #-16] */
/* @0x2b0bc4 subsmi r1, r10, #16, #24 */
/* @0x2b0bc6 rsbs r2, r3, #0 */
/* @0x2b0bc8 rsb.w r12, r1, #0x0 */
/* @0x2b0bcc cmp r3, r12 */
/* @0x2b0bce ble 0x2b0bee <png_do_shift+0x11a> */
/* @0x2b0bd0 cmp r3, #0x0 */
/* @0x2b0bd2 ldrb r7, [r5, #-1] */
/* @0x2b0bd4 svclt #0xcc7c01 */
/* @0x2b0bd6 ite gt */
/* @0x2b0bd8 lslgt.w r10, r0, r3 */
/* @0x2b0bdc asrle.w r10, r0, r2 */
/* @0x2b0be0 orr.w r7, r10, r7 */
/* @0x2b0be4 subs r3, r3, r1 */
/* @0x2b0be6 strb r7, [r5, #-1] */
/* @0x2b0be8 strmi r7, [r10], #-3073 */
/* @0x2b0bea add r2, r1 */
/* @0x2b0bec b 0x2b0bcc <png_do_shift+0xf8> */
/* @0x2b0bee adds r6, #0x1 */
/* @0x2b0bf0 b 0x2b0ba6 <png_do_shift+0xd2> */
/* @0x2b0bf2 adds r5, r1, #0x2 */
/* @0x2b0bf4 movs r6, #0x0 */
/* @0x2b0bf6 cmp r6, r8 */
/* @0x2b0bf8 beq 0x2b0c52 <png_do_shift+0x17e> */
/* @0x2b0bfa mov r0, r6 */
/* @0x2b0bfc mov r1, r4 */
/* @0x2b0bfe blx 0x318cf0 <__aeabi_uidivmod> */
/* @0x2b0c00 .word 0xf815e878 */
/* @0x2b0c02 ldrb r7, [r5, #-2] */
/* @0x2b0c04 .word 0xf8157c02 */
/* @0x2b0c06 ldrb r3, [r5, #-1] */
/* @0x2b0c08 bl 0x37fc14 <_ZTS13C_UTF16String+0x16cc0> */
/* @0x2b0c0a add.w r7, r3, r7, lsl #8 */
/* @0x2b0c0c blge 0x4ba830 <SrcVerts+0x17874> */
/* @0x2b0c0e add r3, sp, #0x20 */
/* @0x2b0c10 uxth r7, r7 */
/* @0x2b0c12 add.w r1, r3, r1, lsl #2 */
/* @0x2b0c14 movwhs r0, #0x181 */
/* @0x2b0c16 movs r3, #0x0 */
/* @0x2b0c18 ldr r0, [r1, #-16] */
/* @0x2b0c1c ldr r2, [r1, #-32] */
/* @0x2b0c20 rsb.w r12, r0, #0x0 */
/* @0x2b0c24 rsbs r1, r2, #0 */
/* @0x2b0c26 cmp r2, r12 */
/* @0x2b0c28 ble 0x2b0c42 <png_do_shift+0x16e> */
/* @0x2b0c2a cmp r2, #0x0 */
/* @0x2b0c2c ite gt */
/* @0x2b0c2e lslgt.w r9, r7, r2 */
/* @0x2b0c30 blx 0x14af040 <b2_toiTime+0xd55b9c> */
/* @0x2b0c32 asrle.w r9, r7, r1 */
/* @0x2b0c34 b 0x13af040 <b2_toiTime+0xc55b9c> */
/* @0x2b0c36 orr.w r3, r3, r9 */
/* @0x2b0c38 bne 0x731864 <g_SWFvertbuff+0x5e79c> */
/* @0x2b0c3a subs r2, r2, r0 */
/* @0x2b0c3c add r1, r0 */
/* @0x2b0c3e uxth r3, r3 */
/* @0x2b0c40 b 0x2b0c26 <png_do_shift+0x152> */
/* @0x2b0c42 lsrs r2, r3, #0x8 */
/* @0x2b0c44 strb r3, [r5, #-1] */
/* @0x2b0c48 strb r2, [r5, #-2] */
/* @0x2b0c4c adds r6, #0x1 */
/* @0x2b0c4e adds r5, #0x2 */
/* @0x2b0c50 b 0x2b0bf6 <png_do_shift+0x122> */
/* @0x2b0c52 add sp, #0x24 */
/* @0x2b0c54 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x2b0c58 · png_do_write_swap_alpha · size=218 · insn=88 */
/* @0x2b0c58 push {r4, r5, lr} */
/* @0x2b0c5a ldrb r3, [r0, #0x8] */
/* @0x2b0c5c cmp r3, #0x6 */
/* @0x2b0c5e bne 0x2b0cdc <png_do_write_swap_alpha+0x84> */
/* @0x2b0c60 ldrb r3, [r0, #0x9] */
/* @0x2b0c62 ldr r2, [r0] */
/* @0x2b0c64 cmp r3, #0x8 */
/* @0x2b0c66 mov.w r3, #0x0 */
/* @0x2b0c68 tstle r3, r0, lsl #6 */
/* @0x2b0c6a bne 0x2b0c94 <png_do_write_swap_alpha+0x3c> */
/* @0x2b0c6c cmp r3, r2 */
/* @0x2b0c6e beq 0x2b0c92 <png_do_write_swap_alpha+0x3a> */
/* @0x2b0c70 ldrb r4, [r1, #0x1] */
/* @0x2b0c72 adds r3, #0x1 */
/* @0x2b0c74 ldrb r0, [r1] */
/* @0x2b0c76 adds r1, #0x4 */
/* @0x2b0c78 strb r4, [r1, #-4] */
/* @0x2b0c7c ldrb r4, [r1, #-2] */
/* @0x2b0c80 strb r4, [r1, #-3] */
/* @0x2b0c84 ldrb r4, [r1, #-1] */
/* @0x2b0c88 strb r0, [r1, #-1] */
/* @0x2b0c8c strb r4, [r1, #-2] */
/* @0x2b0c90 b 0x2b0c6c <png_do_write_swap_alpha+0x14> */
/* @0x2b0c92 pop {r4, r5, pc} */
/* @0x2b0c94 cmp r3, r2 */
/* @0x2b0c96 beq 0x2b0cda <png_do_write_swap_alpha+0x82> */
/* @0x2b0c98 ldrb r5, [r1, #0x2] */
/* @0x2b0c9a adds r3, #0x1 */
/* @0x2b0c9c ldrb r4, [r1] */
/* @0x2b0c9e adds r1, #0x8 */
/* @0x2b0ca0 ldrb r0, [r1, #-7] */
/* @0x2b0ca4 strb r5, [r1, #-8] */
/* @0x2b0ca8 ldrb r5, [r1, #-5] */
/* @0x2b0cac strb r5, [r1, #-7] */
/* @0x2b0cb0 ldrb r5, [r1, #-4] */
/* @0x2b0cb4 strb r5, [r1, #-6] */
/* @0x2b0cb8 ldrb r5, [r1, #-3] */
/* @0x2b0cbc strb r5, [r1, #-5] */
/* @0x2b0cc0 ldrb r5, [r1, #-2] */
/* @0x2b0cc4 strb r4, [r1, #-2] */
/* @0x2b0cc8 strb r5, [r1, #-4] */
/* @0x2b0ccc ldrb r5, [r1, #-1] */
/* @0x2b0cd0 strb r0, [r1, #-1] */
/* @0x2b0cd4 strb r5, [r1, #-3] */
/* @0x2b0cd8 b 0x2b0c94 <png_do_write_swap_alpha+0x3c> */
/* @0x2b0cda pop {r4, r5, pc} */
/* @0x2b0cdc cmp r3, #0x4 */
/* @0x2b0cde bne 0x2b0d30 <png_do_write_swap_alpha+0xd8> */
/* @0x2b0ce0 ldrb r3, [r0, #0x9] */
/* @0x2b0ce2 ldr r2, [r0] */
/* @0x2b0ce4 cmp r3, #0x8 */
/* @0x2b0ce6 mov.w r3, #0x0 */
/* @0x2b0ce8 .word 0xd10e0300 */
/* @0x2b0cea bne 0x2b0d0a <png_do_write_swap_alpha+0xb2> */
/* @0x2b0cec cmp r3, r2 */
/* @0x2b0cee add.w r1, r1, #0x2 */
/* @0x2b0cf0 andle r0, r9, r2, lsl #2 */
/* @0x2b0cf2 beq 0x2b0d08 <png_do_write_swap_alpha+0xb0> */
/* @0x2b0cf4 ldrb r0, [r1, #-2] */
/* @0x2b0cf8 adds r3, #0x1 */
/* @0x2b0cfa ldrb r4, [r1, #-1] */
/* @0x2b0cfc .word 0xf8014c01 */
/* @0x2b0cfe strb r0, [r1, #-1] */
/* @0x2b0d00 .word 0xf8010c01 */
/* @0x2b0d02 strb r4, [r1, #-2] */
/* @0x2b0d04 ldrb r4, [r1, r2, lsl #24]! */
/* @0x2b0d06 b 0x2b0cec <png_do_write_swap_alpha+0x94> */
/* @0x2b0d08 pop {r4, r5, pc} */
/* @0x2b0d0a cmp r3, r2 */
/* @0x2b0d0c beq 0x2b0d30 <png_do_write_swap_alpha+0xd8> */
/* @0x2b0d0e ldrb r5, [r1, #0x2] */
/* @0x2b0d10 adds r3, #0x1 */
/* @0x2b0d12 ldrb r4, [r1] */
/* @0x2b0d14 adds r1, #0x4 */
/* @0x2b0d16 ldrb r0, [r1, #-3] */
/* @0x2b0d18 .word 0xf8010c03 */
/* @0x2b0d1a strb r5, [r1, #-4] */
/* @0x2b0d1c .word 0xf8115c04 */
/* @0x2b0d1e ldrb r5, [r1, #-1] */
/* @0x2b0d20 .word 0xf8015c01 */
/* @0x2b0d22 strb r4, [r1, #-2] */
/* @0x2b0d24 .word 0xf8014c02 */
/* @0x2b0d26 strb r0, [r1, #-1] */
/* @0x2b0d28 .word 0xf8010c01 */
/* @0x2b0d2a strb r5, [r1, #-3] */
/* @0x2b0d2c strb r5, [r12, r3, lsl #24]! */
/* @0x2b0d2e b 0x2b0d0a <png_do_write_swap_alpha+0xb2> */
/* @0x2b0d30 pop {r4, r5, pc} */

/* ── FUNC 0x2b0d32 · png_do_write_invert_alpha · size=138 · insn=63 */
/* @0x2b0d32 ldrb r3, [r0, #0x8] */
/* @0x2b0d34 cmp r3, #0x6 */
/* @0x2b0d36 bne 0x2b0d76 <png_do_write_invert_alpha+0x44> */
/* @0x2b0d38 ldrb r3, [r0, #0x9] */
/* @0x2b0d3a ldr r2, [r0] */
/* @0x2b0d3c cmp r3, #0x8 */
/* @0x2b0d3e mov.w r3, #0x0 */
/* @0x2b0d42 bne 0x2b0d58 <png_do_write_invert_alpha+0x26> */
/* @0x2b0d44 cmp r3, r2 */
/* @0x2b0d46 beq 0x2b0d56 <png_do_write_invert_alpha+0x24> */
/* @0x2b0d48 ldrb r0, [r1, #0x3] */
/* @0x2b0d4a adds r3, #0x1 */
/* @0x2b0d4c adds r1, #0x4 */
/* @0x2b0d4e mvns r0, r0 */
/* @0x2b0d50 strb r0, [r1, #-1] */
/* @0x2b0d52 ldrb r0, [r6, r1, lsl #24]! */
/* @0x2b0d54 b 0x2b0d44 <png_do_write_invert_alpha+0x12> */
/* @0x2b0d56 bx lr */
/* @0x2b0d58 cmp r3, r2 */
/* @0x2b0d5a beq 0x2b0d74 <png_do_write_invert_alpha+0x42> */
/* @0x2b0d5c ldrb r0, [r1, #0x6] */
/* @0x2b0d5e adds r3, #0x1 */
/* @0x2b0d60 adds r1, #0x8 */
/* @0x2b0d62 mvns r0, r0 */
/* @0x2b0d64 strb r0, [r1, #-2] */
/* @0x2b0d66 .word 0xf8110c02 */
/* @0x2b0d68 ldrb r0, [r1, #-1] */
/* @0x2b0d6a bicmi r0, r0, #256 */
/* @0x2b0d6c mvns r0, r0 */
/* @0x2b0d6e strb r0, [r1, #-1] */
/* @0x2b0d72 b 0x2b0d58 <png_do_write_invert_alpha+0x26> */
/* @0x2b0d74 bx lr */
/* @0x2b0d76 cmp r3, #0x4 */
/* @0x2b0d78 bne 0x2b0dba <png_do_write_invert_alpha+0x88> */
/* @0x2b0d7a ldrb r3, [r0, #0x9] */
/* @0x2b0d7c ldr r2, [r0] */
/* @0x2b0d7e cmp r3, #0x8 */
/* @0x2b0d80 mov.w r3, #0x0 */
/* @0x2b0d82 .word 0xd10b0300 */
/* @0x2b0d84 bne 0x2b0d9e <png_do_write_invert_alpha+0x6c> */
/* @0x2b0d86 cmp r3, r2 */
/* @0x2b0d88 add.w r1, r1, #0x2 */
/* @0x2b0d8a andle r0, r6, r2, lsl #2 */
/* @0x2b0d8c beq 0x2b0d9c <png_do_write_invert_alpha+0x6a> */
/* @0x2b0d8e ldrb r0, [r1, #-1] */
/* @0x2b0d92 adds r3, #0x1 */
/* @0x2b0d94 mvns r0, r0 */
/* @0x2b0d96 strb r0, [r1, #-1] */
/* @0x2b0d9a b 0x2b0d86 <png_do_write_invert_alpha+0x54> */
/* @0x2b0d9c bx lr */
/* @0x2b0d9e cmp r3, r2 */
/* @0x2b0da0 beq 0x2b0dba <png_do_write_invert_alpha+0x88> */
/* @0x2b0da2 ldrb r0, [r1, #0x2] */
/* @0x2b0da4 adds r3, #0x1 */
/* @0x2b0da6 adds r1, #0x4 */
/* @0x2b0da8 mvns r0, r0 */
/* @0x2b0daa strb r0, [r1, #-2] */
/* @0x2b0dae ldrb r0, [r1, #-1] */
/* @0x2b0db2 mvns r0, r0 */
/* @0x2b0db4 strb r0, [r1, #-1] */
/* @0x2b0db6 ldrb r0, [r1, r1, lsl #24]! */
/* @0x2b0db8 b 0x2b0d9e <png_do_write_invert_alpha+0x6c> */
/* @0x2b0dba bx lr */

/* ── FUNC 0x2b0dbc · png_do_write_transformations · size=250 · insn=106 */
/* @0x2b0dbc push {r4, lr} */
/* @0x2b0dbe mov r4, r0 */
/* @0x2b0dc0 cmp r0, #0x0 */
/* @0x2b0dc2 beq 0x2b0eb4 <png_do_write_transformations+0xf8> */
/* @0x2b0dc4 ldr.w r3, [r0, #0x134] */
/* @0x2b0dc8 lsls r2, r3, #0xb */
/* @0x2b0dca bpl 0x2b0dde <png_do_write_transformations+0x22> */
/* @0x2b0dcc ldr.w r3, [r0, #0x120] */
/* @0x2b0dd0 cbz r3, 0x2b0dde <png_do_write_transformations+0x22> */
/* @0x2b0dd2 ldr.w r2, [r0, #0x1b0] */
/* @0x2b0dd4 .word 0xf50021b0 */
/* @0x2b0dd6 add.w r1, r0, #0x1c4 */
/* @0x2b0dd8 andlo r7, r1, #-2147483592 */
/* @0x2b0dda adds r2, #0x1 */
/* @0x2b0ddc blx r3 */
/* @0x2b0dde ldr.w r3, [r4, #0x134] */
/* @0x2b0de0 ldreq r3, [r11], #-308 */
/* @0x2b0de2 lsls r3, r3, #0x10 */
/* @0x2b0de4 bpl 0x2b0df8 <png_do_write_transformations+0x3c> */
/* @0x2b0de6 ldr.w r1, [r4, #0x1b0] */
/* @0x2b0de8 .word 0xf50411b0 */
/* @0x2b0dea add.w r0, r4, #0x1c4 */
/* @0x2b0dec .word 0xf8d470e2 */
/* @0x2b0dee ldr.w r2, [r4, #0x130] */
/* @0x2b0df0 .word 0x31012130 */
/* @0x2b0df2 adds r1, #0x1 */
/* @0x2b0df4 bl 0x2af930 <png_do_strip_filler> */
/* @0x2b0df8 ldr.w r3, [r4, #0x134] */
/* @0x2b0dfc lsls r0, r3, #0xf */
/* @0x2b0dfe bpl 0x2b0e0e <png_do_write_transformations+0x52> */
/* @0x2b0e00 ldr.w r1, [r4, #0x1b0] */
/* @0x2b0e04 add.w r0, r4, #0x1c4 */
/* @0x2b0e08 adds r1, #0x1 */
/* @0x2b0e0a bl 0x2af8e4 <png_do_packswap> */
/* @0x2b0e0c .word 0xf8d4fd6b */
/* @0x2b0e0e ldr.w r3, [r4, #0x134] */
/* @0x2b0e10 smmlareq r9, r4, r1, r3 */
/* @0x2b0e12 lsls r1, r3, #0x1d */
/* @0x2b0e14 bpl 0x2b0e28 <png_do_write_transformations+0x6c> */
/* @0x2b0e16 ldr.w r1, [r4, #0x1b0] */
/* @0x2b0e18 .word 0xf50411b0 */
/* @0x2b0e1a add.w r0, r4, #0x1c4 */
/* @0x2b0e1c .word 0xf89470e2 */
/* @0x2b0e1e ldrb.w r2, [r4, #0x1eb] */
/* @0x2b0e20 smlattlo r1, r11, r1, r2 */
/* @0x2b0e22 adds r1, #0x1 */
/* @0x2b0e24 bl 0x2b09fe <png_do_pack> */
/* @0x2b0e28 ldr.w r3, [r4, #0x134] */
/* @0x2b0e2c lsls r2, r3, #0x1b */
/* @0x2b0e2e bpl 0x2b0e3e <png_do_write_transformations+0x82> */
/* @0x2b0e30 ldr.w r1, [r4, #0x1b0] */
/* @0x2b0e34 add.w r0, r4, #0x1c4 */
/* @0x2b0e38 adds r1, #0x1 */
/* @0x2b0e3a bl 0x2af8b6 <png_do_swap> */
/* @0x2b0e3c .word 0xf8d4fd3c */
/* @0x2b0e3e ldr.w r3, [r4, #0x134] */
/* @0x2b0e40 .word 0x071b3134 */
/* @0x2b0e42 lsls r3, r3, #0x1c */
/* @0x2b0e44 bpl 0x2b0e58 <png_do_write_transformations+0x9c> */
/* @0x2b0e46 ldr.w r1, [r4, #0x1b0] */
/* @0x2b0e48 .word 0xf50411b0 */
/* @0x2b0e4a add.w r0, r4, #0x1c4 */
/* @0x2b0e4c .word 0xf20470e2 */
/* @0x2b0e4e addw r2, r4, #0x245 */
/* @0x2b0e50 .word 0x31012245 */
/* @0x2b0e52 adds r1, #0x1 */
/* @0x2b0e54 bl 0x2b0ad4 <png_do_shift> */
/* @0x2b0e58 ldr.w r3, [r4, #0x134] */
/* @0x2b0e5c lsls r0, r3, #0xe */
/* @0x2b0e5e bpl 0x2b0e6e <png_do_write_transformations+0xb2> */
/* @0x2b0e60 ldr.w r1, [r4, #0x1b0] */
/* @0x2b0e64 add.w r0, r4, #0x1c4 */
/* @0x2b0e68 adds r1, #0x1 */
/* @0x2b0e6a bl 0x2b0c58 <png_do_write_swap_alpha> */
/* @0x2b0e6c .word 0xf8d4fef5 */
/* @0x2b0e6e ldr.w r3, [r4, #0x134] */
/* @0x2b0e70 tsteq r9, #52, #2 */
/* @0x2b0e72 lsls r1, r3, #0xc */
/* @0x2b0e74 bpl 0x2b0e84 <png_do_write_transformations+0xc8> */
/* @0x2b0e76 ldr.w r1, [r4, #0x1b0] */
/* @0x2b0e78 .word 0xf50411b0 */
/* @0x2b0e7a add.w r0, r4, #0x1c4 */
/* @0x2b0e7c smlattlo r1, r2, r0, r7 */
/* @0x2b0e7e adds r1, #0x1 */
/* @0x2b0e80 bl 0x2b0d32 <png_do_write_invert_alpha> */
/* @0x2b0e84 ldr.w r3, [r4, #0x134] */
/* @0x2b0e88 lsls r2, r3, #0x1f */
/* @0x2b0e8a bpl 0x2b0e9a <png_do_write_transformations+0xde> */
/* @0x2b0e8c ldr.w r1, [r4, #0x1b0] */
/* @0x2b0e90 add.w r0, r4, #0x1c4 */
/* @0x2b0e94 adds r1, #0x1 */
/* @0x2b0e96 bl 0x2afae8 <png_do_bgr> */
/* @0x2b0e98 .word 0xf8d4fe27 */
/* @0x2b0e9a ldr.w r3, [r4, #0x134] */
/* @0x2b0e9c .word 0x069b3134 */
/* @0x2b0e9e lsls r3, r3, #0x1a */
/* @0x2b0ea0 bpl 0x2b0eb4 <png_do_write_transformations+0xf8> */
/* @0x2b0ea2 ldr.w r1, [r4, #0x1b0] */
/* @0x2b0ea4 .word 0xf50411b0 */
/* @0x2b0ea6 add.w r0, r4, #0x1c4 */
/* @0x2b0ea8 pop {r1, r5, r6, r7, r12, sp, lr} */
/* @0x2b0eaa pop.w {r4, lr} */
/* @0x2b0eac .word 0x31014010 */
/* @0x2b0eae adds r1, #0x1 */
/* @0x2b0eb0 b.w 0x2af85a <png_do_invert> */
/* @0x2b0eb4 pop {r4, pc} */

/* ── FUNC 0x2b0eb6 · png_do_write_intrapixel · size=134 · insn=67 */
/* @0x2b0eb6 push {r4, r5, r6, r7, lr} */
/* @0x2b0eb8 ldrb r3, [r0, #0x8] */
/* @0x2b0eba lsls r2, r3, #0x1e */
/* @0x2b0ebc bpl 0x2b0f3a <png_do_write_intrapixel+0x84> */
/* @0x2b0ebe ldr r2, [r0] */
/* @0x2b0ec0 ldrb r0, [r0, #0x9] */
/* @0x2b0ec2 cmp r0, #0x8 */
/* @0x2b0ec4 bne 0x2b0ef0 <png_do_write_intrapixel+0x3a> */
/* @0x2b0ec6 cmp r3, #0x2 */
/* @0x2b0ec8 beq 0x2b0ed2 <png_do_write_intrapixel+0x1c> */
/* @0x2b0eca cmp r3, #0x6 */
/* @0x2b0ecc bne 0x2b0f3a <png_do_write_intrapixel+0x84> */
/* @0x2b0ece movs r0, #0x4 */
/* @0x2b0ed0 b 0x2b0ed4 <png_do_write_intrapixel+0x1e> */
/* @0x2b0ed2 movs r0, #0x3 */
/* @0x2b0ed4 movs r3, #0x0 */
/* @0x2b0ed6 cmp r3, r2 */
/* @0x2b0ed8 beq 0x2b0eee <png_do_write_intrapixel+0x38> */
/* @0x2b0eda ldrb r4, [r1, #0x1] */
/* @0x2b0edc adds r3, #0x1 */
/* @0x2b0ede ldrb r5, [r1] */
/* @0x2b0ee0 subs r5, r5, r4 */
/* @0x2b0ee2 strb r5, [r1] */
/* @0x2b0ee4 ldrb r5, [r1, #0x2] */
/* @0x2b0ee6 subs r4, r5, r4 */
/* @0x2b0ee8 strb r4, [r1, #0x2] */
/* @0x2b0eea add r1, r0 */
/* @0x2b0eec b 0x2b0ed6 <png_do_write_intrapixel+0x20> */
/* @0x2b0eee pop {r4, r5, r6, r7, pc} */
/* @0x2b0ef0 cmp r0, #0x10 */
/* @0x2b0ef2 bne 0x2b0f3a <png_do_write_intrapixel+0x84> */
/* @0x2b0ef4 cmp r3, #0x2 */
/* @0x2b0ef6 beq 0x2b0f00 <png_do_write_intrapixel+0x4a> */
/* @0x2b0ef8 cmp r3, #0x6 */
/* @0x2b0efa bne 0x2b0f3a <png_do_write_intrapixel+0x84> */
/* @0x2b0efc movs r0, #0x8 */
/* @0x2b0efe b 0x2b0f02 <png_do_write_intrapixel+0x4c> */
/* @0x2b0f00 movs r0, #0x6 */
/* @0x2b0f02 movs r3, #0x0 */
/* @0x2b0f04 cmp r3, r2 */
/* @0x2b0f06 beq 0x2b0f3a <png_do_write_intrapixel+0x84> */
/* @0x2b0f08 ldrb r6, [r1, #0x2] */
/* @0x2b0f0a adds r3, #0x1 */
/* @0x2b0f0c ldrb r4, [r1, #0x3] */
/* @0x2b0f0e ldrb r5, [r1] */
/* @0x2b0f10 orr.w r6, r4, r6, lsl #8 */
/* @0x2b0f12 stmdavc r12, {r1, r2, r9, r10, sp} ^ */
/* @0x2b0f14 ldrb r4, [r1, #0x1] */
/* @0x2b0f16 ldrb r7, [r1, #0x4] */
/* @0x2b0f18 orr.w r5, r4, r5, lsl #8 */
/* @0x2b0f1a stmdbvc r12, {r0, r2, r8, r10, sp} ^ */
/* @0x2b0f1c ldrb r4, [r1, #0x5] */
/* @0x2b0f1e subs r5, r5, r6 */
/* @0x2b0f20 orr.w r4, r4, r7, lsl #8 */
/* @0x2b0f22 blne 0xfebb9f46 <b2_toiTime+0xfffffffffe460aa2> */
/* @0x2b0f24 subs r4, r4, r6 */
/* @0x2b0f26 uxth r5, r5 */
/* @0x2b0f28 strb r5, [r1, #0x1] */
/* @0x2b0f2a uxth r4, r4 */
/* @0x2b0f2c lsrs r6, r5, #0x8 */
/* @0x2b0f2e strb r4, [r1, #0x5] */
/* @0x2b0f30 strb r6, [r1] */
/* @0x2b0f32 lsrs r5, r4, #0x8 */
/* @0x2b0f34 strb r5, [r1, #0x4] */
/* @0x2b0f36 add r1, r0 */
/* @0x2b0f38 b 0x2b0f04 <png_do_write_intrapixel+0x4e> */
/* @0x2b0f3a pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2b0f3e · anon_2b0f3e · size=484 · insn=122 */
/* @0x2b0f3e .word 0x468947f0 */
/* @0x2b0f42 addlt r4, lr, r4, ror pc */
/* @0x2b0f46 strmi r2, [r4], -r0, lsl #12 */
/* @0x2b0f4a ldmdavs pc!, {r0, r1, r2, r3, r4, r5, r6, r10, lr} */
/* @0x2b0f4e .word 0x46909d16 */
/* @0x2b0f52 adcvs r6, lr, r9, lsr r8 */
/* @0x2b0f56 smlattls sp, lr, r0, r6 */
/* @0x2b0f5a qsubvs r1, r9, lr */
/* @0x2b0f5e rsbvs r6, lr, lr, lsr #32 */
/* @0x2b0f62 .word 0xf8c5d104 */
/* @0x2b0f66 .word 0xf8c59000 */
/* @0x2b0f6a sbc r8, r7, r4 */
/* @0x2b0f6e vstrle d2, [r9, #-8] */
/* @0x2b0f72 teqhs r2, r9, ror #20 */
/* @0x2b0f76 ldrbtmi r4, [r10], #-1640 */
/* @0x2b0f7a bl 0xc6e796 <b2_toiTime+0x5152f2> */
/* @0x2b0f7e strbtmi r4, [r9], -r0, lsr #12 */
/* @0x2b0f82 blx 0x20aef5e <b2_toiTime+0x1955aba> */
/* @0x2b0f86 ldrsblo pc, [r4, #-132]! */
/* @0x2b0f8a ldrsbge pc, [r0, pc] */
/* @0x2b0f8e teqhi r12, r4, asr #17 */
/* @0x2b0f92 ldmvc r12, {r2, r8, r10, r12, sp, lr, pc} */
/* @0x2b0f96 smlalbtlo pc, r8, r4, r8 */
/* @0x2b0f9a .word 0xf8d444fa */
/* @0x2b0f9e .word 0xf8c43170 */
/* @0x2b0fa2 .word 0xf8c49138 */
/* @0x2b0fa6 strbmi r3, [r0], -r4, asr #2 */
/* @0x2b0faa .word 0xf6052100 */
/* @0x2b0fae ldrshlt lr, [r0, -lr]! */
/* @0x2b0fb2 ldrsbne pc, [r0, #-132] */
/* @0x2b0fb6 stmdblt r1, {r5, r9, r10, lr} */
/* @0x2b0fba .word 0xf7f54651 */
/* @0x2b0fbe .word 0xf8d4fa36 */
/* @0x2b0fc2 blhs 0x2bd4ea <jpeg_alloc_huff_table+0xbe2> */
/* @0x2b0fc6 stmvs r9!, {r0, r3, r4, r5, r8, r12, lr, pc} */
/* @0x2b0fca .word 0x900cf8d5 */
/* @0x2b0fce blle 0x8024fa <b2_toiTime+0xa9056> */
/* @0x2b0fd2 stmdbvs lr!, {r2, r8, r12, sp} */
/* @0x2b0fd6 strtmi r6, [r0], -r9, ror #1 */
/* @0x2b0fda smulbblt r6, r9, r0 */
/* @0x2b0fde mrc2 p7, #0x2, apsr_nzcv, c15, c5, #0x7 */
/* @0x2b0fe2 b 0x16828ae <b2_toiTime+0xf2940a> */
/* @0x2b0fe6 smlawbvs r8, r9, r2, r0 */
/* @0x2b0fea b 0xffcee806 <b2_toiTime+0xffffffffff595362> */
/* @0x2b0fee ldrtmi r4, [r1], -r0, lsr #12 */
/* @0x2b0ff2 mcr2 p7, #0x4, pc, c3, c5, #0x7 */
/* @0x2b0ff6 .word 0xf7f5e002 */
/* @0x2b0ffa qsubvs pc, r2, r8 */
/* @0x2b0ffe ldrsbne pc, [r4, #-132]! */
/* @0x2b1002 .word 0xf8d54620 */
/* @0x2b1006 stmdbvs lr!, {r3, r12, pc} */
/* @0x2b100a mcr2 p7, #0x2, pc, c9, c5, #0x7 */
/* @0x2b100e eoreq pc, r9, r6, asr #16 */
/* @0x2b1012 stmdbvs r11!, {r1, r3, r5, r7, r11, sp, lr} */
/* @0x2b1016 ldrsbne pc, [r0, #-132]! */
/* @0x2b101a eoreq pc, r2, r3, asr r8 */
/* @0x2b101e ldrsbhs pc, [r4, #-132]! */
/* @0x2b1022 b 0xff5ee83e <b2_toiTime+0xfffffffffee9539a> */
/* @0x2b1026 movwlo r6, #0x18ab */
/* @0x2b102a .word 0xf8d460ab */
/* @0x2b102e .word 0xf8c43174 */
/* @0x2b1032 .word 0xf8d43148 */
/* @0x2b1036 .word 0xf8c43170 */
/* @0x2b103a .word 0xf8d43144 */
/* @0x2b103e blhs 0x2bd536 <jpeg_alloc_huff_table+0xc2e> */
/* @0x2b1042 .word 0xf8dfd1b1 */
/* @0x2b1046 ldrbtmi r10, [r10], #216 */
/* @0x2b104a .word 0x21044640 */
/* @0x2b104e stc p6, c15, [lr], #20 */
/* @0x2b1052 teqle lr, r0, lsl #16 */
/* @0x2b1056 .word 0x3148f8d4 */
/* @0x2b105a mvnsle r2, r0, lsl #22 */
/* @0x2b105e .word 0xf8d568a9 */
/* @0x2b1062 strbmi r9, [r9, #-0xc] */
/* @0x2b1066 .word 0x3104db15 */
/* @0x2b106a rscvs r6, r9, lr, lsr #18 */
/* @0x2b106e addeq r4, r9, r0, lsr #12 */
/* @0x2b1072 .word 0xf7f5b166 */
/* @0x2b1076 shadd16mi pc, r1, r4 */
/* @0x2b107a addeq lr, r9, #323584 */
/* @0x2b107e .word 0xf6056128 */
/* @0x2b1082 qadd8mi lr, r0, r12 */
/* @0x2b1086 .word 0xf7f54631 */
/* @0x2b108a and pc, r2, r8, lsr lr */
/* @0x2b108e mcr2 p7, #0x0, pc, c7, c5, #0x7 */
/* @0x2b1092 .word 0xf8d46128 */
/* @0x2b1096 qsub16mi r1, r0, r4 */
/* @0x2b109a .word 0x9008f8d5 */
/* @0x2b109e .word 0xf7f5692e */
/* @0x2b10a2 .word 0xf846fdfe */
/* @0x2b10a6 stmvs r10!, {r0, r3, r5} */
/* @0x2b10aa .word 0xf8d4692b */
/* @0x2b10ae .word 0xf8531170 */
/* @0x2b10b2 .word 0xf8d40022 */
/* @0x2b10b6 .word 0xf6052174 */
/* @0x2b10ba stmvs r11!, {r7, r9, r11, sp, lr, pc} */
/* @0x2b10be adcvs r3, r11, r1, lsl #6 */
/* @0x2b10c2 ldrsblo pc, [r4, #-132]! */
/* @0x2b10c6 smlalbtlo pc, r8, r4, r8 */
/* @0x2b10ca ldrsblo pc, [r0, #-132]! */
/* @0x2b10ce smlalbtlo pc, r4, r4, r8 */
/* @0x2b10d2 stmdahs r1, {r1, r3, r4, r5, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2b10d6 .word 0xf8d4d007 */
/* @0x2b10da qsaxmi r1, r0, r0 */
/* @0x2b10de ldrbmi r11, [r1], -r1, lsl #18 */
/* @0x2b10e2 .word 0xf9a3f7f5 */
/* @0x2b10e6 .word 0xf8d4e7b0 */
/* @0x2b10ea stmvs r10!, {r2, r4, r5, r6, r8, r12, sp} */
/* @0x2b10ee .word 0xf803fb02 */
/* @0x2b10f2 .word 0x2148f8d4 */
/* @0x2b10f6 andle r4, r1, #-1610612727 */
/* @0x2b10fa ldrmi r1, [r8], #2715 */
/* @0x2b10fe strbmi r9, [r0], -sp, lsl #20 */
/* @0x2b1102 addsmi r6, r10, #3866624 */
/* @0x2b1106 .word 0xf605d001 */
/* @0x2b110a andlt lr, lr, r4, ror #20 */
/* @0x2b110e .word 0x87f0e8bd */
/* @0x2b1112 bgt 0x560d1a <g_SWFlineaavertbuff+0xdc52> */
/* @0x2b1116 cmnle r7, r3, lsl r0 */
/* @0x2b111a svcgt #0xe3000d */
/* @0x2b111e svcgt #0x35000d */
/* @0x2b1122 cdpeq p0, #0x0, c0, c11, c13, #0x0 */

/* ── FUNC 0x2b1124 · png_save_uint_32 · size=16 · insn=8 */
/* @0x2b1124 lsrs r3, r1, #0x18 */
/* @0x2b1126 strb r1, [r0, #0x3] */
/* @0x2b1128 strb r3, [r0] */
/* @0x2b112a lsrs r3, r1, #0x10 */
/* @0x2b112c strb r3, [r0, #0x1] */
/* @0x2b112e lsrs r3, r1, #0x8 */
/* @0x2b1130 strb r3, [r0, #0x2] */
/* @0x2b1132 bx lr */

/* ── FUNC 0x2b1134 · png_save_int_32 · size=4 · insn=1 */
/* @0x2b1134 b.w 0x2b1124 <png_save_uint_32> */

/* ── FUNC 0x2b1138 · png_save_uint_16 · size=8 · insn=4 */
/* @0x2b1138 lsrs r3, r1, #0x8 */
/* @0x2b113a strb r1, [r0, #0x1] */
/* @0x2b113c strb r3, [r0] */
/* @0x2b113e bx lr */

/* ── FUNC 0x2b1140 · png_write_sig · size=96 · insn=40 */
/* @0x2b1140 push {r4, r5, lr} */
/* @0x2b1142 sub sp, #0x14 */
/* @0x2b1144 ldr r5, [pc, #0x50] */
/* @0x2b1146 mov r4, r0 */
/* @0x2b1148 ldr r2, [pc, #0x50] */
/* @0x2b114a add r5, pc */
/* @0x2b114c ldr r5, [r5] */
/* @0x2b114e add r2, pc */
/* @0x2b1150 ldr r3, [r5] */
/* @0x2b1152 ldr r0, [r2] */
/* @0x2b1154 ldr r1, [r2, #0x4] */
/* @0x2b1156 str r3, [sp, #0xc] */
/* @0x2b1158 add r3, sp, #0x4 */
/* @0x2b115a ldrb.w r2, [r4, #0x1f0] */
/* @0x2b115c movwgt r2, #0x31f0 */
/* @0x2b115e stm r3!, {r0, r1} */
/* @0x2b1160 add r1, sp, #0x4 */
/* @0x2b1162 movs r3, #0x12 */
/* @0x2b1164 add r1, r2 */
/* @0x2b1166 str.w r3, [r4, #0x334] */
/* @0x2b1168 qasxmi r3, r0, r4 */
/* @0x2b116a mov r0, r4 */
/* @0x2b116c rsb.w r2, r2, #0x8 */
/* @0x2b1170 bl 0x2afbf0 <png_write_data> */
/* @0x2b1174 ldrb.w r3, [r4, #0x1f0] */
/* @0x2b1178 cmp r3, #0x2 */
/* @0x2b117a bhi 0x2b1188 <png_write_sig+0x48> */
/* @0x2b117c ldr.w r3, [r4, #0x12c] */
/* @0x2b1180 orr r3, r3, #0x1000 */
/* @0x2b1184 str.w r3, [r4, #0x12c] */
/* @0x2b1188 ldr r2, [sp, #0xc] */
/* @0x2b118a ldr r3, [r5] */
/* @0x2b118c cmp r2, r3 */
/* @0x2b118e beq 0x2b1194 <png_write_sig+0x54> */
/* @0x2b1190 blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2b1194 add sp, #0x14 */
/* @0x2b1196 pop {r4, r5, pc} */
/* @0x2b1198 ldm r0!, {r1, r3} */
/* @0x2b119a movs r3, r2 */
/* @0x2b119c .word 0xec12 000d */

/* ── FUNC 0x2b11a0 · png_write_chunk_start · size=100 · insn=44 */
/* @0x2b11a0 ldr r3, [pc, #0x5c] */
/* @0x2b11a2 push {r4, r5, r6, r7, lr} */
/* @0x2b11a4 add r3, pc */
/* @0x2b11a6 ldr r3, [r3] */
/* @0x2b11a8 mov r5, r1 */
/* @0x2b11aa sub sp, #0x14 */
/* @0x2b11ac ldr r1, [r3] */
/* @0x2b11ae mov r4, r0 */
/* @0x2b11b0 mov r7, r3 */
/* @0x2b11b2 str r1, [sp, #0xc] */
/* @0x2b11b4 cbz r0, 0x2b11f0 <png_write_chunk_start+0x50> */
/* @0x2b11b6 add r6, sp, #0x4 */
/* @0x2b11b8 movs r3, #0x22 */
/* @0x2b11ba mov r1, r2 */
/* @0x2b11bc str.w r3, [r0, #0x334] */
/* @0x2b11c0 mov r0, r6 */
/* @0x2b11c2 bl 0x2b1124 <png_save_uint_32> */
/* @0x2b11c4 stmdavs r8!, {r0, r1, r2, r3, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2b11c6 ldr r0, [r5] */
/* @0x2b11c8 mov r1, r6 */
/* @0x2b11ca movs r2, #0x8 */
/* @0x2b11cc str r0, [sp, #0x8] */
/* @0x2b11ce mov r0, r4 */
/* @0x2b11d0 bl 0x2afbf0 <png_write_data> */
/* @0x2b11d4 ldr r3, [r5] */
/* @0x2b11d6 mov r0, r4 */
/* @0x2b11d8 str.w r3, [r4, #0x1e0] */
/* @0x2b11dc bl 0x2a5af4 <png_reset_crc> */
/* @0x2b11e0 mov r0, r4 */
/* @0x2b11e2 mov r1, r5 */
/* @0x2b11e4 movs r2, #0x4 */
/* @0x2b11e6 bl 0x2a5b08 <png_calculate_crc> */
/* @0x2b11e8 movths pc, #0x2c8f */
/* @0x2b11ea movs r3, #0x42 */
/* @0x2b11ec str.w r3, [r4, #0x334] */
/* @0x2b11f0 ldr r2, [sp, #0xc] */
/* @0x2b11f2 ldr r3, [r7] */
/* @0x2b11f4 cmp r2, r3 */
/* @0x2b11f6 beq 0x2b11fc <png_write_chunk_start+0x5c> */
/* @0x2b11f8 blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2b11fc add sp, #0x14 */
/* @0x2b11fe pop {r4, r5, r6, r7, pc} */
/* @0x2b1200 stm r7!, {r4, r5, r7} */
/* @0x2b1202 movs r3, r2 */

/* ── FUNC 0x2b1204 · png_write_chunk_data · size=34 · insn=15 */
/* @0x2b1204 push {r4, r5, r6, lr} */
/* @0x2b1206 mov r5, r1 */
/* @0x2b1208 mov r4, r2 */
/* @0x2b120a mov r6, r0 */
/* @0x2b120c cbz r0, 0x2b1224 <png_write_chunk_data+0x20> */
/* @0x2b120e cbz r1, 0x2b1224 <png_write_chunk_data+0x20> */
/* @0x2b1210 cbz r2, 0x2b1224 <png_write_chunk_data+0x20> */
/* @0x2b1212 bl 0x2afbf0 <png_write_data> */
/* @0x2b1214 ldrtmi pc, [r0], -sp, ror #25 */
/* @0x2b1216 mov r0, r6 */
/* @0x2b1218 mov r1, r5 */
/* @0x2b121a mov r2, r4 */
/* @0x2b121c pop.w {r4, r5, r6, lr} */
/* @0x2b1220 b.w 0x2a5b08 <png_calculate_crc> */
/* @0x2b1224 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2b1228 · anon_2b1228 · size=108 · insn=28 */
/* @0x2b1228 stmdavs r9, {r0, r2, r3, r9, r10, lr} */
/* @0x2b122c bllt 0x1d02a44 <b2_toiTime+0x15a95a0> */
/* @0x2b1230 stmvs r11!, {r1, r2, r3, r9, r10, lr} */
/* @0x2b1234 ble 0x681cb4 <g_SWFlinevertbuff+0x2ebec> */
/* @0x2b1238 strtmi r6, [r0], -r11, lsr #18 */
/* @0x2b123c ldrsbhs pc, [r4, #-132]! */
/* @0x2b1240 eorne pc, r6, r3, asr r8 */
/* @0x2b1244 .word 0xffdef7ff */
/* @0x2b1248 strtmi r6, [r0], -r11, lsr #18 */
/* @0x2b124c eorne pc, r6, r3, asr r8 */
/* @0x2b1250 .word 0xf7f53601 */
/* @0x2b1254 ubfx pc, r3, #0x1a, #0xd */
/* @0x2b1258 tstlt r11, r11, ror #17 */
/* @0x2b125c stmdbvs r9!, {r5, r9, r10, lr} */
/* @0x2b1260 stc2l p7, c15, [r12, #-980] */
/* @0x2b1264 .word 0x3148f8d4 */
/* @0x2b1268 ldrsbhs pc, [r4, #-132]! */
/* @0x2b126c andle r4, r5, #805306377 */
/* @0x2b1270 .word 0xf8d44620 */
/* @0x2b1274 bne 0xff73583c <b2_toiTime+0xfffffffffefdc398> */
/* @0x2b1278 .word 0xffc4f7ff */
/* @0x2b127c addsvc pc, r12, r4, lsl #10 */
/* @0x2b1280 cdp p6, #0x6, c15, c10, c5, #0x0 */
/* @0x2b1284 .word 0xf8c42300 */
/* @0x2b1288 ldcllt p1, c3, [r0, #-400]! */
/* @0x2b128c pop {r1, r3, r5, r6, r11, sp, lr} */
/* @0x2b1290 .word 0xf7ff4070 */
/* @0x2b1294 ldrlt r11, [r7, #-0xfb7]! */

/* ── FUNC 0x2b1296 · png_write_chunk_end · size=38 · insn=17 */
/* @0x2b1296 push {r0, r1, r2, r4, r5, lr} */
/* @0x2b1298 mov r4, r0 */
/* @0x2b129a cbz r0, 0x2b12b8 <png_write_chunk_end+0x22> */
/* @0x2b129c add r5, sp, #0x4 */
/* @0x2b129e movs r3, #0x82 */
/* @0x2b12a0 str.w r3, [r0, #0x334] */
/* @0x2b12a2 qasxmi r3, r8, r4 */
/* @0x2b12a4 mov r0, r5 */
/* @0x2b12a6 ldr.w r1, [r4, #0x1d4] */
/* @0x2b12aa bl 0x2b1124 <png_save_uint_32> */
/* @0x2b12ae mov r0, r4 */
/* @0x2b12b0 mov r1, r5 */
/* @0x2b12b2 movs r2, #0x4 */
/* @0x2b12b4 bl 0x2afbf0 <png_write_data> */
/* @0x2b12b6 mullt r3, r12, r12 */
/* @0x2b12b8 add sp, #0xc */
/* @0x2b12ba pop {r4, r5, pc} */

/* ── FUNC 0x2b12bc · png_write_chunk · size=38 · insn=16 */
/* @0x2b12bc push {r4, r5, r6, lr} */
/* @0x2b12be mov r6, r2 */
/* @0x2b12c0 mov r5, r3 */
/* @0x2b12c2 mov r4, r0 */
/* @0x2b12c4 cbz r0, 0x2b12e0 <png_write_chunk+0x24> */
/* @0x2b12c6 mov r2, r3 */
/* @0x2b12c8 bl 0x2b11a0 <png_write_chunk_start> */
/* @0x2b12cc mov r0, r4 */
/* @0x2b12ce mov r1, r6 */
/* @0x2b12d0 mov r2, r5 */
/* @0x2b12d2 bl 0x2b1204 <png_write_chunk_data> */
/* @0x2b12d4 qadd8mi pc, r0, r7 */
/* @0x2b12d6 mov r0, r4 */
/* @0x2b12d8 pop.w {r4, r5, r6, lr} */
/* @0x2b12dc b.w 0x2b1296 <png_write_chunk_end> */
/* @0x2b12e0 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2b12e4 · png_write_IHDR · size=748 · insn=332 */
/* @0x2b12e4 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b12e8 mov r5, r3 */
/* @0x2b12ea ldr r3, [pc, #0x29c] */
/* @0x2b12ec mov r11, r2 */
/* @0x2b12ee sub sp, #0x3c */
/* @0x2b12f0 mov r4, r0 */
/* @0x2b12f2 add r3, pc */
/* @0x2b12f4 ldr r3, [r3] */
/* @0x2b12f6 mov r6, r1 */
/* @0x2b12f8 ldr.w r8, [sp, #0x60] */
/* @0x2b12fc ldr r2, [r3] */
/* @0x2b12fe ldr r7, [sp, #0x68] */
/* @0x2b1300 ldr.w r10, [sp, #0x6c] */
/* @0x2b1304 str r2, [sp, #0x34] */
/* @0x2b1306 ldr r2, [pc, #0x284] */
/* @0x2b1308 str r3, [sp, #0x14] */
/* @0x2b130a add r2, pc */
/* @0x2b130c ldr r0, [r2, #8]! */
/* @0x2b1310 ldrb r2, [r2, #0x4] */
/* @0x2b1312 str r0, [sp, #0x1c] */
/* @0x2b1314 strb.w r2, [sp, #0x20] */
/* @0x2b1318 movs r2, #0x1 */
/* @0x2b131a cmp.w r8, #0x6 */
/* @0x2b131c stmdale r2, {r1, r2, r8, r9, r10, r11} ^ */
/* @0x2b131e bhi 0x2b13a6 <png_write_IHDR+0xc2> */
/* @0x2b1320 tbb [pc, r8] */
/* @0x2b1324 asrs r4, r0 */
/* @0x2b1326 subs r0, r2, r4 */
/* @0x2b1328 asrs r1, r5 */
/* @0x2b132a movs r4, r6 */
/* @0x2b132c subs r3, r5, #0x1 */
/* @0x2b132e cmp r3, #0xf */
/* @0x2b1330 bhi 0x2b133c <png_write_IHDR+0x58> */
/* @0x2b1332 lsls r2, r3 */
/* @0x2b1334 movw r3, #0x808b */
/* @0x2b1338 ands r3, r2 */
/* @0x2b133a cbnz r3, 0x2b136a <png_write_IHDR+0x86> */
/* @0x2b133c ldr r1, [pc, #0x250] */
/* @0x2b133e mov r0, r4 */
/* @0x2b1340 add r1, pc */
/* @0x2b1342 b 0x2b13ac <png_write_IHDR+0xc8> */
/* @0x2b1344 cmp r5, #0x8 */
/* @0x2b1346 beq 0x2b1356 <png_write_IHDR+0x72> */
/* @0x2b1348 cmp r5, #0x10 */
/* @0x2b134a beq 0x2b1356 <png_write_IHDR+0x72> */
/* @0x2b134c ldr r1, [pc, #0x244] */
/* @0x2b134e mov r0, r4 */
/* @0x2b1350 add r1, pc */
/* @0x2b1352 bl 0x2a642c <png_error> */
/* @0x2b1354 movwhs pc, #0x386b */
/* @0x2b1356 movs r3, #0x3 */
/* @0x2b1358 b 0x2b13a0 <png_write_IHDR+0xbc> */
/* @0x2b135a subs r3, r5, #0x1 */
/* @0x2b135c cmp r3, #0x7 */
/* @0x2b135e bhi 0x2b136e <png_write_IHDR+0x8a> */
/* @0x2b1360 lsl.w r3, r2, r3 */
/* @0x2b1364 tst.w r3, #0x8b */
/* @0x2b1368 beq 0x2b136e <png_write_IHDR+0x8a> */
/* @0x2b136a movs r3, #0x1 */
/* @0x2b136c b 0x2b13a0 <png_write_IHDR+0xbc> */
/* @0x2b136e ldr r1, [pc, #0x228] */
/* @0x2b1370 mov r0, r4 */
/* @0x2b1372 add r1, pc */
/* @0x2b1374 b 0x2b13ac <png_write_IHDR+0xc8> */
/* @0x2b1376 cmp r5, #0x8 */
/* @0x2b1378 beq 0x2b1388 <png_write_IHDR+0xa4> */
/* @0x2b137a cmp r5, #0x10 */
/* @0x2b137c beq 0x2b1388 <png_write_IHDR+0xa4> */
/* @0x2b137e ldr r1, [pc, #0x21c] */
/* @0x2b1380 mov r0, r4 */
/* @0x2b1382 add r1, pc */
/* @0x2b1384 bl 0x2a642c <png_error> */
/* @0x2b1388 movs r3, #0x2 */
/* @0x2b138a b 0x2b13a0 <png_write_IHDR+0xbc> */
/* @0x2b138c cmp r5, #0x8 */
/* @0x2b138e beq 0x2b139e <png_write_IHDR+0xba> */
/* @0x2b1390 cmp r5, #0x10 */
/* @0x2b1392 beq 0x2b139e <png_write_IHDR+0xba> */
/* @0x2b1394 ldr r1, [pc, #0x208] */
/* @0x2b1396 mov r0, r4 */
/* @0x2b1398 add r1, pc */
/* @0x2b139a bl 0x2a642c <png_error> */
/* @0x2b139c movwhs pc, #0x4847 */
/* @0x2b139e movs r3, #0x4 */
/* @0x2b13a0 strb.w r3, [r4, #0x1ee] */
/* @0x2b13a4 b 0x2b13b0 <png_write_IHDR+0xcc> */
/* @0x2b13a6 ldr r1, [pc, #0x1fc] */
/* @0x2b13a8 mov r0, r4 */
/* @0x2b13aa add r1, pc */
/* @0x2b13ac bl 0x2a642c <png_error> */
/* @0x2b13b0 ldr r3, [sp, #0x64] */
/* @0x2b13b2 cbz r3, 0x2b13be <png_write_IHDR+0xda> */
/* @0x2b13b4 ldr r1, [pc, #0x1f0] */
/* @0x2b13b6 mov r0, r4 */
/* @0x2b13b8 add r1, pc */
/* @0x2b13ba bl 0x2a6474 <png_warning> */
/* @0x2b13bc .word 0xf8d4f85b */
/* @0x2b13be ldr.w r3, [r4, #0x2dc] */
/* @0x2b13c0 smmlseq r10, r12, r2, r3 */
/* @0x2b13c2 lsls r2, r3, #0x1d */
/* @0x2b13c4 bpl 0x2b13da <png_write_IHDR+0xf6> */
/* @0x2b13c6 ldr.w r3, [r4, #0x12c] */
/* @0x2b13c8 ldrbeq r3, [r11], #300 */
/* @0x2b13ca lsls r3, r3, #0x13 */
/* @0x2b13cc bmi 0x2b13da <png_write_IHDR+0xf6> */
/* @0x2b13ce bic r3, r8, #0x4 */
/* @0x2b13d0 blhs 0x331fe8 */
/* @0x2b13d2 cmp r3, #0x2 */
/* @0x2b13d4 bne 0x2b13da <png_write_IHDR+0xf6> */
/* @0x2b13d6 cmp r7, #0x40 */
/* @0x2b13d8 beq 0x2b13e8 <png_write_IHDR+0x104> */
/* @0x2b13da cbz r7, 0x2b13e8 <png_write_IHDR+0x104> */
/* @0x2b13dc ldr r1, [pc, #0x1cc] */
/* @0x2b13de mov r0, r4 */
/* @0x2b13e0 movs r7, #0x0 */
/* @0x2b13e2 add r1, pc */
/* @0x2b13e4 bl 0x2a6474 <png_warning> */
/* @0x2b13e8 cmp.w r10, #0x1 */
/* @0x2b13ec bls 0x2b13fc <png_write_IHDR+0x118> */
/* @0x2b13ee ldr r1, [pc, #0x1c0] */
/* @0x2b13f0 mov r0, r4 */
/* @0x2b13f2 mov.w r10, #0x1 */
/* @0x2b13f4 ldrbtmi r0, [r9], #-2561 */
/* @0x2b13f6 add r1, pc */
/* @0x2b13f8 bl 0x2a6474 <png_warning> */
/* @0x2b13fc movs r2, #0x0 */
/* @0x2b13fe strb.w r2, [r4, #0x304] */
/* @0x2b1400 .word 0xf8942304 */
/* @0x2b1402 ldrb.w r2, [r4, #0x1ee] */
/* @0x2b1404 blx 0x1a79bc4 <b2_toiTime+0x1320720> */
/* @0x2b1406 uxtb.w r9, r5 */
/* @0x2b1408 blx 0x1aafa24 <b2_toiTime+0x1356580> */
/* @0x2b140a uxtb.w r8, r8 */
/* @0x2b140c blx 0x1aaf634 <b2_toiTime+0x1356190> */
/* @0x2b140e uxtb.w r10, r10 */
/* @0x2b1410 rscslt pc, pc, #565248 */
/* @0x2b1412 uxtb r7, r7 */
/* @0x2b1414 strb.w r9, [r4, #0x1eb] */
/* @0x2b1418 muls r5, r2, r5 */
/* @0x2b141a strb.w r8, [r4, #0x1ea] */
/* @0x2b141c .word 0xf88481ea */
/* @0x2b141e strb.w r10, [r4, #0x1e7] */
/* @0x2b1420 .word 0xf884a1e7 */
/* @0x2b1422 strb.w r7, [r4, #0x2e4] */
/* @0x2b1424 .word 0xf8c472e4 */
/* @0x2b1426 str.w r6, [r4, #0x18c] */
/* @0x2b1428 .word 0xf8c4618c */
/* @0x2b142a str.w r11, [r4, #0x190] */
/* @0x2b142c rsclt r11, sp, #144, #2 */
/* @0x2b142e uxtb r5, r5 */
/* @0x2b1430 strb.w r5, [r4, #0x1ed] */
/* @0x2b1434 cmp r5, #0x7 */
/* @0x2b1436 bls 0x2b143e <png_write_IHDR+0x15a> */
/* @0x2b1438 lsrs r5, r5, #0x3 */
/* @0x2b143a muls r5, r6, r5 */
/* @0x2b143c b 0x2b1444 <png_write_IHDR+0x160> */
/* @0x2b143e muls r5, r6, r5 */
/* @0x2b1440 adds r5, #0x7 */
/* @0x2b1442 lsrs r5, r5, #0x3 */
/* @0x2b1444 str.w r5, [r4, #0x19c] */
/* @0x2b1448 add r5, sp, #0x24 */
/* @0x2b144a strb.w r2, [r4, #0x1ef] */
/* @0x2b144c ldrtmi r2, [r1], -pc, ror #3 */
/* @0x2b144e mov r1, r6 */
/* @0x2b1450 mov r0, r5 */
/* @0x2b1452 str.w r6, [r4, #0x198] */
/* @0x2b1454 .word 0xf8846198 */
/* @0x2b1456 strb.w r9, [r4, #0x1ec] */
/* @0x2b1458 .word 0xf7ff91ec */
/* @0x2b145a bl 0x2b1124 <png_save_uint_32> */
/* @0x2b145c stcne p14, c15, [r8, #-396]! */
/* @0x2b145e adds r0, r5, #0x4 */
/* @0x2b1460 mov r1, r11 */
/* @0x2b1462 bl 0x2b1124 <png_save_uint_32> */
/* @0x2b1464 movwhs pc, #0xe5f */
/* @0x2b1466 movs r3, #0x0 */
/* @0x2b1468 mov r0, r4 */
/* @0x2b146a strb.w r3, [sp, #0x2e] */
/* @0x2b146c stmdbge r7, {r1, r2, r3, r5, r12, sp} */
/* @0x2b146e add r1, sp, #0x1c */
/* @0x2b1470 movs r3, #0xd */
/* @0x2b1472 mov r2, r5 */
/* @0x2b1474 strb.w r9, [sp, #0x2c] */
/* @0x2b1478 strb.w r8, [sp, #0x2d] */
/* @0x2b147c strb.w r7, [sp, #0x2f] */
/* @0x2b1480 strb.w r10, [sp, #0x30] */
/* @0x2b1484 bl 0x2b12bc <png_write_chunk> */
/* @0x2b1488 ldr r3, [pc, #0x128] */
/* @0x2b148a str.w r4, [r4, #0x160] */
/* @0x2b148c ldrbtmi r4, [r11], #-352 */
/* @0x2b148e add r3, pc */
/* @0x2b1490 ldr r3, [r3] */
/* @0x2b1492 str.w r3, [r4, #0x158] */
/* @0x2b1494 blmi 0x14bd9fc <b2_toiTime+0xd64558> */
/* @0x2b1496 ldr r3, [pc, #0x120] */
/* @0x2b1498 add r3, pc */
/* @0x2b149a ldr r3, [r3] */
/* @0x2b149c str.w r3, [r4, #0x15c] */
/* @0x2b14a0 ldrb.w r3, [r4, #0x1e9] */
/* @0x2b14a4 cbnz r3, 0x2b14c0 <png_write_IHDR+0x1dc> */
/* @0x2b14a6 ldrb.w r3, [r4, #0x1ea] */
/* @0x2b14a8 blhs 0x37dc58 <_ZTS13C_UTF16String+0x14d04> */
/* @0x2b14aa cmp r3, #0x3 */
/* @0x2b14ac beq 0x2b14b6 <png_write_IHDR+0x1d2> */
/* @0x2b14ae ldrb.w r3, [r4, #0x1eb] */
/* @0x2b14b0 blhs 0x47dc64 <targetStr+0x2a24> */
/* @0x2b14b2 cmp r3, #0x7 */
/* @0x2b14b4 bhi 0x2b14ba <png_write_IHDR+0x1d6> */
/* @0x2b14b6 movs r3, #0x8 */
/* @0x2b14b8 b 0x2b14bc <png_write_IHDR+0x1d8> */
/* @0x2b14ba movs r3, #0xf8 */
/* @0x2b14bc strb.w r3, [r4, #0x1e9] */
/* @0x2b14c0 ldr.w r3, [r4, #0x130] */
/* @0x2b14c4 ands r2, r3, #0x1 */
/* @0x2b14c8 bne 0x2b14d8 <png_write_IHDR+0x1f4> */
/* @0x2b14ca ldrb.w r1, [r4, #0x1e9] */
/* @0x2b14cc stmdbhs r8, {r0, r3, r5, r6, r7, r8, r12} */
/* @0x2b14ce cmp r1, #0x8 */
/* @0x2b14d0 it ne */
/* @0x2b14d2 movne r2, #0x1 */
/* @0x2b14d4 str.w r2, [r4, #0x188] */
/* @0x2b14d8 lsls r6, r3, #0x1e */
/* @0x2b14da itt pl */
/* @0x2b14dc movpl.w r2, #0xffffffff */
/* @0x2b14e0 strpl.w r2, [r4, #0x178] */
/* @0x2b14e4 lsls r5, r3, #0x1d */
/* @0x2b14e6 itt pl */
/* @0x2b14e8 movpl r2, #0x8 */
/* @0x2b14ea strpl.w r2, [r4, #0x184] */
/* @0x2b14ec ldreq r2, [r8, -r4, lsl #3] */
/* @0x2b14ee lsls r0, r3, #0x1c */
/* @0x2b14f0 add.w r0, r4, #0x138 */
/* @0x2b14f4 itt pl */
/* @0x2b14f6 movpl r2, #0xf */
/* @0x2b14f8 strpl.w r2, [r4, #0x180] */
/* @0x2b14fc lsls r1, r3, #0x1b */
/* @0x2b14fe add.w r1, r4, #0x178 */
/* @0x2b1500 svclt #0x5c71bc */
/* @0x2b1502 itt pl */
/* @0x2b1504 movpl r3, #0x8 */
/* @0x2b1506 strpl.w r3, [r4, #0x17c] */
/* @0x2b1508 .word 0xf8d4317c */
/* @0x2b150a ldr.w r3, [r4, #0x184] */
/* @0x2b150c movwls r3, #0x184 */
/* @0x2b150e str r3, [sp] */
/* @0x2b1510 ldr.w r3, [r4, #0x188] */
/* @0x2b1514 str r3, [sp, #0x4] */
/* @0x2b1516 ldr r3, [pc, #0xa4] */
/* @0x2b1518 add r3, pc */
/* @0x2b151a str r3, [sp, #0x8] */
/* @0x2b151c movs r3, #0x38 */
/* @0x2b151e str r3, [sp, #0xc] */
/* @0x2b1520 ldm r1, {r1, r2, r3} */
/* @0x2b1522 blx 0xb6eb0 <deflateInit2_@plt> */
/* @0x2b1524 .word 0xb1b8ecc6 */
/* @0x2b1526 cbz r0, 0x2b1558 <png_write_IHDR+0x274> */
/* @0x2b1528 adds r2, r0, #0x6 */
/* @0x2b152a bne 0x2b1534 <png_write_IHDR+0x250> */
/* @0x2b152c ldr r1, [pc, #0x90] */
/* @0x2b152e mov r0, r4 */
/* @0x2b1530 add r1, pc */
/* @0x2b1532 b 0x2b154a <png_write_IHDR+0x266> */
/* @0x2b1534 adds r3, r0, #0x2 */
/* @0x2b1536 bne 0x2b1540 <png_write_IHDR+0x25c> */
/* @0x2b1538 ldr r1, [pc, #0x88] */
/* @0x2b153a mov r0, r4 */
/* @0x2b153c add r1, pc */
/* @0x2b153e b 0x2b154a <png_write_IHDR+0x266> */
/* @0x2b1540 adds r0, #0x4 */
/* @0x2b1542 bne 0x2b154e <png_write_IHDR+0x26a> */
/* @0x2b1544 ldr r1, [pc, #0x80] */
/* @0x2b1546 mov r0, r4 */
/* @0x2b1548 add r1, pc */
/* @0x2b154a bl 0x2a642c <png_error> */
/* @0x2b154c ldmdbmi pc, {r0, r1, r2, r3, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2b154e ldr r1, [pc, #0x7c] */
/* @0x2b1550 mov r0, r4 */
/* @0x2b1552 add r1, pc */
/* @0x2b1554 bl 0x2a642c <png_error> */
/* @0x2b1558 ldr.w r3, [r4, #0x170] */
/* @0x2b155c ldr r1, [sp, #0x14] */
/* @0x2b155e ldr r2, [sp, #0x34] */
/* @0x2b1560 str.w r3, [r4, #0x144] */
/* @0x2b1564 ldr.w r3, [r4, #0x174] */
/* @0x2b1568 str.w r3, [r4, #0x148] */
/* @0x2b156c movs r3, #0x0 */
/* @0x2b156e str.w r3, [r4, #0x164] */
/* @0x2b1570 movwhs r3, #0x1164 */
/* @0x2b1572 movs r3, #0x1 */
/* @0x2b1574 str.w r3, [r4, #0x12c] */
/* @0x2b1578 ldr r3, [r1] */
/* @0x2b157a cmp r2, r3 */
/* @0x2b157c beq 0x2b1582 <png_write_IHDR+0x29e> */
/* @0x2b157e blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2b1580 andlt lr, pc, r10, lsr #16 */
/* @0x2b1582 add sp, #0x3c */
/* @0x2b1584 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b1588 stm r6!, {r1, r5, r6} */
/* @0x2b158a movs r3, r2 */
/* @0x2b158c orrs.w r0, r6, sp */
/* @0x2b1590 ldm r5!, {r0, r1, r3, r6, r7} */
/* @0x2b1592 movs r5, r1 */
/* @0x2b1594 ldm r5, {r0, r5, r6, r7} */
/* @0x2b1596 movs r5, r1 */
/* @0x2b1598 ldm r5!, {r0, r1, r2, r3, r4, r6, r7} */
/* @0x2b159a movs r5, r1 */
/* @0x2b159c ldm r5, {r2, r4, r5, r6, r7} */
/* @0x2b159e movs r5, r1 */
/* @0x2b15a0 ldm r6!, {r1, r3} */
/* @0x2b15a2 movs r5, r1 */
/* @0x2b15a4 ldm r6!, {r0, r3, r4} */
/* @0x2b15a6 movs r5, r1 */
/* @0x2b15a8 ldm r6!, {r1, r2, r3, r5} */
/* @0x2b15aa movs r5, r1 */
/* @0x2b15ac ldm r6!, {r0, r1, r2, r5} */
/* @0x2b15ae movs r5, r1 */
/* @0x2b15b0 ldm r6!, {r0, r4, r5} */
/* @0x2b15b2 movs r5, r1 */
/* @0x2b15b4 lsls r2, r1, #0x18 */
/* @0x2b15b6 movs r4, r2 */
/* @0x2b15b8 lsls r4, r0, #0x18 */
/* @0x2b15ba movs r4, r2 */
/* @0x2b15bc add r2, sp, #0x2c0 */
/* @0x2b15be movs r5, r1 */
/* @0x2b15c0 ldm r5!, {r3, r4} */
/* @0x2b15c2 movs r5, r1 */
/* @0x2b15c4 ldm r5!, {r1, r6} */
/* @0x2b15c6 movs r5, r1 */
/* @0x2b15c8 ldm r5, {r0, r1, r3, r5, r6} */
/* @0x2b15ca movs r5, r1 */
/* @0x2b15cc ldm r5!, {r0, r1, r4, r7} */
/* @0x2b15ce movs r5, r1 */

/* ── FUNC 0x2b15d0 · png_write_PLTE · size=208 · insn=87 */
/* @0x2b15d0 ldr r3, [pc, #0xbc] */
/* @0x2b15d2 push {r4, r5, r6, r7, lr} */
/* @0x2b15d4 add r3, pc */
/* @0x2b15d6 mov r4, r0 */
/* @0x2b15d8 sub sp, #0x14 */
/* @0x2b15da ldr r0, [r3, #13]! */
/* @0x2b15dc ldrmi r0, [r6], -sp, lsl #30 */
/* @0x2b15de mov r6, r2 */
/* @0x2b15e0 mov r5, r1 */
/* @0x2b15e2 ldrb r3, [r3, #0x4] */
/* @0x2b15e4 str r0, [sp, #0x8] */
/* @0x2b15e6 strb.w r3, [sp, #0xc] */
/* @0x2b15e8 .word 0xf894300c */
/* @0x2b15ea ldrb.w r3, [r4, #0x1ea] */
/* @0x2b15ec blhs 0x37dd9c <_ZTS13C_UTF16String+0x14e48> */
/* @0x2b15ee cmp r3, #0x3 */
/* @0x2b15f0 ittet eq */
/* @0x2b15f2 ldrbeq.w r2, [r4, #0x1eb] */
/* @0x2b15f4 smlatths r1, r11, r1, r2 */
/* @0x2b15f6 moveq r1, #0x1 */
/* @0x2b15f8 movne.w r2, #0x100 */
/* @0x2b15fc lsleq.w r2, r1, r2 */
/* @0x2b1600 ldr.w r1, [r4, #0x2dc] */
/* @0x2b1604 lsls r1, r1, #0x1f */
/* @0x2b1606 bmi 0x2b160a <png_write_PLTE+0x3a> */
/* @0x2b1608 cbz r6, 0x2b160e <png_write_PLTE+0x3e> */
/* @0x2b160a cmp r6, r2 */
/* @0x2b160c bls 0x2b1624 <png_write_PLTE+0x54> */
/* @0x2b160e cmp r3, #0x3 */
/* @0x2b1610 mov r0, r4 */
/* @0x2b1612 bne 0x2b161e <png_write_PLTE+0x4e> */
/* @0x2b1614 ldr r1, [pc, #0x7c] */
/* @0x2b1616 add r1, pc */
/* @0x2b1618 bl 0x2a642c <png_error> */
/* @0x2b161c b 0x2b1624 <png_write_PLTE+0x54> */
/* @0x2b161e ldr r1, [pc, #0x78] */
/* @0x2b1620 add r1, pc */
/* @0x2b1622 b 0x2b1632 <png_write_PLTE+0x62> */
/* @0x2b1624 ldrb.w r3, [r4, #0x1ea] */
/* @0x2b1628 lsls r3, r3, #0x1e */
/* @0x2b162a bmi 0x2b1638 <png_write_PLTE+0x68> */
/* @0x2b162c ldr r1, [pc, #0x6c] */
/* @0x2b162e mov r0, r4 */
/* @0x2b1630 add r1, pc */
/* @0x2b1632 bl 0x2a6474 <png_warning> */
/* @0x2b1634 eor pc, r9, pc, lsl pc */
/* @0x2b1636 b 0x2b168c <png_write_PLTE+0xbc> */
/* @0x2b1638 movs r3, #0x3 */
/* @0x2b163a strh.w r6, [r4, #0x1dc] */
/* @0x2b163c cmpmi lr, #220, #2 */
/* @0x2b163e muls r6, r3, r6 */
/* @0x2b1640 mov r0, r4 */
/* @0x2b1642 add r1, sp, #0x8 */
/* @0x2b1644 adds r5, #0x3 */
/* @0x2b1646 add r7, sp, #0x4 */
/* @0x2b1648 mov r2, r6 */
/* @0x2b164a add r6, r5 */
/* @0x2b164c bl 0x2b11a0 <png_write_chunk_start> */
/* @0x2b1650 cmp r5, r6 */
/* @0x2b1652 beq 0x2b167a <png_write_PLTE+0xaa> */
/* @0x2b1654 ldrb r3, [r5, #-3] */
/* @0x2b1658 mov r0, r4 */
/* @0x2b165a mov r1, r7 */
/* @0x2b165c movs r2, #0x3 */
/* @0x2b165e adds r5, #0x3 */
/* @0x2b1660 strb.w r3, [sp, #0x4] */
/* @0x2b1664 ldrb r3, [r5, #-5] */
/* @0x2b1668 strb.w r3, [sp, #0x5] */
/* @0x2b166c ldrb r3, [r5, #-4] */
/* @0x2b1670 strb.w r3, [sp, #0x6] */
/* @0x2b1674 bl 0x2b1204 <png_write_chunk_data> */
/* @0x2b1678 b 0x2b1650 <png_write_PLTE+0x80> */
/* @0x2b167a mov r0, r4 */
/* @0x2b167c bl 0x2b1296 <png_write_chunk_end> */
/* @0x2b1680 ldr.w r3, [r4, #0x12c] */
/* @0x2b1684 orr r3, r3, #0x2 */
/* @0x2b1688 str.w r3, [r4, #0x12c] */
/* @0x2b168c add sp, #0x14 */
/* @0x2b168e pop {r4, r5, r6, r7, pc} */
/* @0x2b1690 b 0x2b15ac <png_write_IHDR+0x2c8> */
/* @0x2b1692 movs r5, r1 */
/* @0x2b1694 ldm r4, {r2, r4, r5, r6, r7} */
/* @0x2b1696 movs r5, r1 */
/* @0x2b1698 ldm r4!, {r1, r3, r5, r6, r7} */
/* @0x2b169a movs r5, r1 */
/* @0x2b169c ldm r4, {r1, r2, r3, r4, r5, r6, r7} */
/* @0x2b169e movs r5, r1 */

/* ── FUNC 0x2b16a0 · png_write_IDAT · size=236 · insn=103 */
/* @0x2b16a0 push.w {r0, r1, r4, r5, r6, r7, r8, lr} */
/* @0x2b16a4 mov r5, r1 */
/* @0x2b16a6 ldr r1, [pc, #0xdc] */
/* @0x2b16a8 mov r4, r0 */
/* @0x2b16aa mov r8, r2 */
/* @0x2b16ac add r1, pc */
/* @0x2b16ae ldr r0, [r1, #18]! */
/* @0x2b16b0 stmdbvc r11, {r1, r4, r8, r9, r10, r11} */
/* @0x2b16b2 ldrb r3, [r1, #0x4] */
/* @0x2b16b4 str r0, [sp] */
/* @0x2b16b6 strb.w r3, [sp, #0x4] */
/* @0x2b16b8 .word 0xf8d43004 */
/* @0x2b16ba ldr.w r3, [r4, #0x12c] */
/* @0x2b16bc ldrbeq r3, [r11, -r12, lsr #2] */
/* @0x2b16be lsls r3, r3, #0x1d */
/* @0x2b16c0 bmi 0x2b1766 <png_write_IDAT+0xc6> */
/* @0x2b16c2 ldrb.w r3, [r4, #0x304] */
/* @0x2b16c4 blhs 0x2be2dc <jinit_color_deconverter+0x374> */
/* @0x2b16c6 cmp r3, #0x0 */
/* @0x2b16c8 bne 0x2b1766 <png_write_IDAT+0xc6> */
/* @0x2b16ca ldrb r6, [r5] */
/* @0x2b16cc and r3, r6, #0xf */
/* @0x2b16d0 cmp r3, #0x8 */
/* @0x2b16d2 bne 0x2b175c <png_write_IDAT+0xbc> */
/* @0x2b16d4 and r3, r6, #0xf0 */
/* @0x2b16d8 cmp r3, #0x70 */
/* @0x2b16da bhi 0x2b175c <png_write_IDAT+0xbc> */
/* @0x2b16dc cmp r2, #0x1 */
/* @0x2b16de bls 0x2b1766 <png_write_IDAT+0xc6> */
/* @0x2b16e0 ldr.w r3, [r4, #0x190] */
/* @0x2b16e4 movw r2, #0x3fff */
/* @0x2b16e8 cmp r3, r2 */
/* @0x2b16ea bhi 0x2b1766 <png_write_IDAT+0xc6> */
/* @0x2b16ec ldr.w r1, [r4, #0x18c] */
/* @0x2b16f0 cmp r1, r2 */
/* @0x2b16f2 bhi 0x2b1766 <png_write_IDAT+0xc6> */
/* @0x2b16f4 ldrb.w r7, [r4, #0x1ee] */
/* @0x2b16f8 ldrb.w r2, [r4, #0x1eb] */
/* @0x2b16fc smulbb r7, r7, r2 */
/* @0x2b1700 muls r7, r1, r7 */
/* @0x2b1702 ldrb.w r1, [r4, #0x1e7] */
/* @0x2b1704 strlo r1, [pc, -r7, ror #3] */
/* @0x2b1706 adds r7, #0xf */
/* @0x2b1708 lsrs r7, r7, #0x3 */
/* @0x2b170a muls r7, r3, r7 */
/* @0x2b170c cbz r1, 0x2b171e <png_write_IDAT+0x7e> */
/* @0x2b170e adds r3, #0x7 */
/* @0x2b1710 cmp r2, #0x7 */
/* @0x2b1712 ite hi */
/* @0x2b1714 movhi r2, #0x6 */
/* @0x2b1716 movls r2, #0xc */
/* @0x2b1718 lsrs r3, r3, #0x3 */
/* @0x2b171a mla r7, r3, r2, r7 */
/* @0x2b171c ldmdbeq r1!, {r1, r8, r9, r10, r12, sp, lr} */
/* @0x2b171e lsrs r1, r6, #0x4 */
/* @0x2b1720 movs r0, #0x1 */
/* @0x2b1722 adds r3, r1, #0x7 */
/* @0x2b1724 lsls r0, r3 */
/* @0x2b1726 cmp r7, r0 */
/* @0x2b1728 bls 0x2b1752 <png_write_IDAT+0xb2> */
/* @0x2b172a lsls r1, r1, #0x4 */
/* @0x2b172c orr r0, r1, #0x8 */
/* @0x2b1730 uxtb r3, r0 */
/* @0x2b1732 cmp r6, r3 */
/* @0x2b1734 beq 0x2b1766 <png_write_IDAT+0xc6> */
/* @0x2b1736 strb r3, [r5] */
/* @0x2b1738 movs r1, #0x1f */
/* @0x2b173a ldrb r3, [r5, #0x1] */
/* @0x2b173c and r3, r3, #0xe0 */
/* @0x2b1740 add.w r0, r3, r0, lsl #8 */
/* @0x2b1744 add.w r6, r3, #0x1f */
/* @0x2b1748 blx 0x318cf0 <__aeabi_uidivmod> */
/* @0x2b174c subs r1, r6, r1 */
/* @0x2b174e strb r1, [r5, #0x1] */
/* @0x2b1750 b 0x2b1766 <png_write_IDAT+0xc6> */
/* @0x2b1752 cmp r0, #0xff */
/* @0x2b1754 bls 0x2b172a <png_write_IDAT+0x8a> */
/* @0x2b1756 subs r1, #0x1 */
/* @0x2b1758 lsrs r0, r0, #0x1 */
/* @0x2b175a b 0x2b1726 <png_write_IDAT+0x86> */
/* @0x2b175c ldr r1, [pc, #0x28] */
/* @0x2b175e mov r0, r4 */
/* @0x2b1760 add r1, pc */
/* @0x2b1762 bl 0x2a642c <png_error> */
/* @0x2b1764 strbmi pc, [r3], -r3, ror #28 */
/* @0x2b1766 mov r3, r8 */
/* @0x2b1768 mov r0, r4 */
/* @0x2b176a mov r1, sp */
/* @0x2b176c mov r2, r5 */
/* @0x2b176e bl 0x2b12bc <png_write_chunk> */
/* @0x2b1770 .word 0xf8d4fda5 */
/* @0x2b1772 ldr.w r3, [r4, #0x12c] */
/* @0x2b1774 .word 0xf043312c */
/* @0x2b1776 orr r3, r3, #0x4 */
/* @0x2b1778 .word 0xf8c40304 */
/* @0x2b177a str.w r3, [r4, #0x12c] */
/* @0x2b177c andlt r3, r2, r12, lsr #2 */
/* @0x2b177e add sp, #0x8 */
/* @0x2b1780 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2b1784 b 0x2b14f0 <png_write_IHDR+0x20c> */
/* @0x2b1786 movs r5, r1 */
/* @0x2b1788 ldm r4!, {r1, r2} */
/* @0x2b178a movs r5, r1 */

/* ── FUNC 0x2b178c · png_write_IEND · size=52 · insn=21 */
/* @0x2b178c ldr r3, [pc, #0x2c] */
/* @0x2b178e movs r2, #0x0 */
/* @0x2b1790 push {r0, r1, r4, lr} */
/* @0x2b1792 add r3, pc */
/* @0x2b1794 mov r4, r0 */
/* @0x2b1796 mov r1, sp */
/* @0x2b1798 ldr r0, [r3, #23]! */
/* @0x2b179c ldrb r3, [r3, #0x4] */
/* @0x2b179e str r0, [sp] */
/* @0x2b17a0 mov r0, r4 */
/* @0x2b17a2 strb.w r3, [sp, #0x4] */
/* @0x2b17a4 ldrmi r3, [r3], -r4 */
/* @0x2b17a6 mov r3, r2 */
/* @0x2b17a8 bl 0x2b12bc <png_write_chunk> */
/* @0x2b17ac ldr.w r3, [r4, #0x12c] */
/* @0x2b17b0 orr r3, r3, #0x10 */
/* @0x2b17b4 str.w r3, [r4, #0x12c] */
/* @0x2b17b8 add sp, #0x8 */
/* @0x2b17ba pop {r4, pc} */
/* @0x2b17bc b 0x2b135c <png_write_IHDR+0x78> */
/* @0x2b17be movs r5, r1 */

/* ── FUNC 0x2b17c0 · png_write_gAMA · size=84 · insn=39 */
/* @0x2b17c0 vmov.f64 d7, #5.000000e-01 */
/* @0x2b17c4 vldr d6, [pc, #64] */
/* @0x2b17c8 vmov d5, r2, r3 */
/* @0x2b17cc ldr r1, [pc, #0x40] */
/* @0x2b17ce push {r4, r5, lr} */
/* @0x2b17d0 add r1, pc */
/* @0x2b17d2 mov r5, r0 */
/* @0x2b17d4 sub sp, #0x14 */
/* @0x2b17d6 ldr r0, [r1, #28]! */
/* @0x2b17d8 .word 0xac010f1c */
/* @0x2b17da add r4, sp, #0x4 */
/* @0x2b17dc ldrb r1, [r1, #0x4] */
/* @0x2b17de str r0, [sp, #0x8] */
/* @0x2b17e0 mov r0, r4 */
/* @0x2b17e2 vmla.f64 d7, d5, d6 */
/* @0x2b17e4 .word 0xf88d7b06 */
/* @0x2b17e6 strb.w r1, [sp, #0xc] */
/* @0x2b17e8 cdp p0, #0xf, c1, c12, c12, #0x0 */
/* @0x2b17ea vcvt.u32.f64 s11, d7 */
/* @0x2b17ec vnmla.f64 d5, d21, d7 */
/* @0x2b17ee vmov r1, s11 */
/* @0x2b17f0 .word 0xf7ff1a90 */
/* @0x2b17f2 bl 0x2b1124 <png_save_uint_32> */
/* @0x2b17f4 qadd8mi pc, r8, r7 */
/* @0x2b17f6 mov r0, r5 */
/* @0x2b17f8 add r1, sp, #0x8 */
/* @0x2b17fa mov r2, r4 */
/* @0x2b17fc movs r3, #0x4 */
/* @0x2b17fe bl 0x2b12bc <png_write_chunk> */
/* @0x2b1800 andlt pc, r5, sp, asr sp */
/* @0x2b1802 add sp, #0x14 */
/* @0x2b1804 pop {r4, r5, pc} */
/* @0x2b1806 nop */
/* @0x2b1808 movs r0, r0 */
/* @0x2b180a movs r0, r0 */
/* @0x2b180c ldr r0, [r0, #0x20] */
/* @0x2b180e lsrs r0, r7 */
/* @0x2b1810 b 0x2b1334 <png_write_IHDR+0x50> */
/* @0x2b1812 movs r5, r1 */

/* ── FUNC 0x2b1814 · anon_2b1814 · size=0 · insn=1 */
/* @0x2b1814 andhi pc, r0, pc, lsr #7 */
