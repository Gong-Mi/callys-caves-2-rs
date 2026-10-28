/* libyoyo.so 覆盖卡组 0287
 * 函数 0x2e58f4..0x2e5fa6，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2e58f4 · FT_Select_Charmap · size=68 · insn=32 */
/* @0x2e58f4 push {r4, r5, lr} */
/* @0x2e58f6 mov r3, r0 */
/* @0x2e58f8 cbz r0, 0x2e5928 <FT_Select_Charmap+0x34> */
/* @0x2e58fa cbz r1, 0x2e592c <FT_Select_Charmap+0x38> */
/* @0x2e58fc ldr r2, [pc, #0x34] */
/* @0x2e58fe cmp r1, r2 */
/* @0x2e5900 bne 0x2e590a <FT_Select_Charmap+0x16> */
/* @0x2e5902 pop.w {r4, r5, lr} */
/* @0x2e5904 .word 0xf7ff4030 */
/* @0x2e5906 b.w 0x2e49fc <_ZNK11b2GearJoint8GetRatioEv+0xf8> */
/* @0x2e5908 bvs 0xfe393af4 <b2_toiTime+0xfffffffffdc3a650> */
/* @0x2e590a ldr r2, [r0, #0x28] */
/* @0x2e590c cbz r2, 0x2e5930 <FT_Select_Charmap+0x3c> */
/* @0x2e590e ldr r0, [r0, #0x24] */
/* @0x2e5910 add.w r5, r2, r0, lsl #2 */
/* @0x2e5914 cmp r2, r5 */
/* @0x2e5916 bhs 0x2e592c <FT_Select_Charmap+0x38> */
/* @0x2e5918 ldr r0, [r2], #4 */
/* @0x2e591c ldr r4, [r0, #0x4] */
/* @0x2e591e cmp r4, r1 */
/* @0x2e5920 bne 0x2e5914 <FT_Select_Charmap+0x20> */
/* @0x2e5922 str r0, [r3, #0x5c] */
/* @0x2e5924 movs r0, #0x0 */
/* @0x2e5926 pop {r4, r5, pc} */
/* @0x2e5928 movs r0, #0x23 */
/* @0x2e592a pop {r4, r5, pc} */
/* @0x2e592c movs r0, #0x6 */
/* @0x2e592e pop {r4, r5, pc} */
/* @0x2e5930 movs r0, #0x26 */
/* @0x2e5932 pop {r4, r5, pc} */
/* @0x2e5934 ldr r3, [r4, #0x14] */
/* @0x2e5936 strb r6, [r5, #0x15] */

/* ── FUNC 0x2e5938 · FT_Get_Charmap_Index · size=40 · insn=20 */
/* @0x2e5938 push {r4, lr} */
/* @0x2e593a cbz r0, 0x2e5956 <FT_Get_Charmap_Index+0x1e> */
/* @0x2e593c ldr r2, [r0] */
/* @0x2e593e cbz r2, 0x2e5956 <FT_Get_Charmap_Index+0x1e> */
/* @0x2e5940 ldr r4, [r2, #0x24] */
/* @0x2e5942 movs r3, #0x0 */
/* @0x2e5944 cmp r3, r4 */
/* @0x2e5946 bge 0x2e595c <FT_Get_Charmap_Index+0x24> */
/* @0x2e5948 ldr r1, [r2, #0x28] */
/* @0x2e594a ldr.w r1, [r1, r3, lsl #2] */
/* @0x2e594c addmi r1, r1, #35 */
/* @0x2e594e cmp r1, r0 */
/* @0x2e5950 beq 0x2e595c <FT_Get_Charmap_Index+0x24> */
/* @0x2e5952 adds r3, #0x1 */
/* @0x2e5954 b 0x2e5944 <FT_Get_Charmap_Index+0xc> */
/* @0x2e5956 mov.w r0, #0xffffffff */
/* @0x2e5958 ldclt p0, c3, [r0, #-1020] */
/* @0x2e595a pop {r4, pc} */
/* @0x2e595c mov r0, r3 */
/* @0x2e595e pop {r4, pc} */

/* ── FUNC 0x2e5960 · FT_Get_Char_Index · size=30 · insn=15 */
/* @0x2e5960 push {r4, lr} */
/* @0x2e5962 mov r4, r0 */
/* @0x2e5964 cbnz r0, 0x2e596a <FT_Get_Char_Index+0xa> */
/* @0x2e5966 movs r0, #0x0 */
/* @0x2e5968 pop {r4, pc} */
/* @0x2e596a ldr r0, [r0, #0x5c] */
/* @0x2e596c cmp r0, #0x0 */
/* @0x2e596e beq 0x2e5966 <FT_Get_Char_Index+0x6> */
/* @0x2e5970 ldr r3, [r0, #0xc] */
/* @0x2e5972 ldr r3, [r3, #0xc] */
/* @0x2e5974 blx r3 */
/* @0x2e5976 ldr r3, [r4, #0x10] */
/* @0x2e5978 cmp r0, r3 */
/* @0x2e597a bhs 0x2e5966 <FT_Get_Char_Index+0x6> */
/* @0x2e597c pop {r4, pc} */

/* ── FUNC 0x2e597e · FT_Get_Next_Char · size=62 · insn=31 */
/* @0x2e597e push {r0, r1, r2, r4, r5, r6, r7, lr} */
/* @0x2e5980 mov r7, r2 */
/* @0x2e5982 mov r4, r0 */
/* @0x2e5984 cbz r0, 0x2e59ac <FT_Get_Next_Char+0x2e> */
/* @0x2e5986 ldr r5, [r0, #0x5c] */
/* @0x2e5988 cbz r5, 0x2e59b0 <FT_Get_Next_Char+0x32> */
/* @0x2e598a ldr r3, [r0, #0x10] */
/* @0x2e598c cbz r3, 0x2e59b2 <FT_Get_Next_Char+0x34> */
/* @0x2e598e add r6, sp, #0x8 */
/* @0x2e5990 str r1, [r6, #-4]! */
/* @0x2e5992 stmvs r11!, {r2, r8, r10, r11, r12} ^ */
/* @0x2e5994 ldr r3, [r5, #0xc] */
/* @0x2e5996 mov r0, r5 */
/* @0x2e5998 mov r1, r6 */
/* @0x2e599a ldr r3, [r3, #0x10] */
/* @0x2e599c blx r3 */
/* @0x2e599e ldr r2, [r4, #0x10] */
/* @0x2e59a0 cmp r0, r2 */
/* @0x2e59a2 mov r3, r0 */
/* @0x2e59a4 bhs 0x2e5994 <FT_Get_Next_Char+0x16> */
/* @0x2e59a6 cbz r0, 0x2e59b2 <FT_Get_Next_Char+0x34> */
/* @0x2e59a8 ldr r0, [sp, #0x4] */
/* @0x2e59aa b 0x2e59b4 <FT_Get_Next_Char+0x36> */
/* @0x2e59ac mov r3, r0 */
/* @0x2e59ae b 0x2e59b2 <FT_Get_Next_Char+0x34> */
/* @0x2e59b0 mov r3, r5 */
/* @0x2e59b2 mov r0, r3 */
/* @0x2e59b4 cbz r7, 0x2e59b8 <FT_Get_Next_Char+0x3a> */
/* @0x2e59b6 str r3, [r7] */
/* @0x2e59b8 add sp, #0xc */
/* @0x2e59ba pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2e59bc · FT_Get_First_Char · size=58 · insn=27 */
/* @0x2e59bc push {r0, r1, r2, r4, r5, lr} */
/* @0x2e59be mov r5, r1 */
/* @0x2e59c0 mov r4, r0 */
/* @0x2e59c2 movs r1, #0x0 */
/* @0x2e59c4 str r1, [sp, #0x4] */
/* @0x2e59c6 cbnz r0, 0x2e59cc <FT_Get_First_Char+0x10> */
/* @0x2e59c8 movs r0, #0x0 */
/* @0x2e59ca b 0x2e59ec <FT_Get_First_Char+0x30> */
/* @0x2e59cc ldr r3, [r0, #0x5c] */
/* @0x2e59ce cmp r3, #0x0 */
/* @0x2e59d0 beq 0x2e59c8 <FT_Get_First_Char+0xc> */
/* @0x2e59d2 ldr r3, [r0, #0x10] */
/* @0x2e59d4 cmp r3, #0x0 */
/* @0x2e59d6 beq 0x2e59c8 <FT_Get_First_Char+0xc> */
/* @0x2e59d8 bl 0x2e5960 <FT_Get_Char_Index> */
/* @0x2e59dc mov r1, r0 */
/* @0x2e59de str r0, [sp, #0x4] */
/* @0x2e59e0 cmp r0, #0x0 */
/* @0x2e59e2 bne 0x2e59c8 <FT_Get_First_Char+0xc> */
/* @0x2e59e4 mov r0, r4 */
/* @0x2e59e6 add r2, sp, #0x4 */
/* @0x2e59e8 bl 0x2e597e <FT_Get_Next_Char> */
/* @0x2e59ec cbz r5, 0x2e59f2 <FT_Get_First_Char+0x36> */
/* @0x2e59ee ldr r3, [sp, #0x4] */
/* @0x2e59f0 str r3, [r5] */
/* @0x2e59f2 add sp, #0xc */
/* @0x2e59f4 pop {r4, r5, pc} */

/* ── FUNC 0x2e59f8 · FT_Face_Properties · size=168 · insn=77 */
/* @0x2e59f8 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e59fc cbnz r1, 0x2e5a18 <FT_Face_Properties+0x20> */
/* @0x2e59fe adds r2, #0x8 */
/* @0x2e5a00 ldr.w r11, [pc, #0x98] */
/* @0x2e5a04 ldr r6, [pc, #0x8c] */
/* @0x2e5a06 mov.w r12, #0xffffffff */
/* @0x2e5a08 svcmi #0x233cff */
/* @0x2e5a0a ldr r7, [pc, #0x8c] */
/* @0x2e5a0c movs r4, #0x0 */
/* @0x2e5a0e mov.w r8, #0xff */
/* @0x2e5a10 .word 0xf04f08ff */
/* @0x2e5a12 mov.w r9, #0x1 */
/* @0x2e5a14 ands r0, r10, r1, lsl #18 */
/* @0x2e5a16 b 0x2e5a4e <FT_Face_Properties+0x56> */
/* @0x2e5a18 cmp r2, #0x0 */
/* @0x2e5a1a bne 0x2e59fe <FT_Face_Properties+0x6> */
/* @0x2e5a1c movs r0, #0x6 */
/* @0x2e5a1e pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e5a20 .word 0xf8528ff0 */
/* @0x2e5a22 ldr r3, [r2, #-8] */
/* @0x2e5a24 ldrbmi r3, [r11, #-0xc08] */
/* @0x2e5a26 cmp r3, r11 */
/* @0x2e5a28 bne 0x2e5a5a <FT_Face_Properties+0x62> */
/* @0x2e5a2a ldr r10, [r2, #-4] */
/* @0x2e5a2c .word 0xf8d0ac04 */
/* @0x2e5a2e ldr.w r3, [r0, #0x80] */
/* @0x2e5a30 .word 0xf1ba3080 */
/* @0x2e5a32 cmp.w r10, #0x0 */
/* @0x2e5a34 andle r0, sp, r0, lsl #30 */
/* @0x2e5a36 beq 0x2e5a54 <FT_Face_Properties+0x5c> */
/* @0x2e5a38 ldrb.w r10, [r10] */
/* @0x2e5a3c cmp.w r10, #0x1 */
/* @0x2e5a40 ite ne */
/* @0x2e5a42 movne r10, r9 */
/* @0x2e5a44 moveq r10, r4 */
/* @0x2e5a46 strb.w r10, [r3, #0x38] */
/* @0x2e5a48 stmdblo r1, {r3, r4, r5, sp, pc} */
/* @0x2e5a4a subs r1, #0x1 */
/* @0x2e5a4c adds r2, #0x8 */
/* @0x2e5a4e cmp r1, #0x0 */
/* @0x2e5a50 bne 0x2e5a22 <FT_Face_Properties+0x2a> */
/* @0x2e5a52 b 0x2e5a86 <FT_Face_Properties+0x8e> */
/* @0x2e5a54 strb.w r8, [r3, #0x38] */
/* @0x2e5a58 b 0x2e5a4a <FT_Face_Properties+0x52> */
/* @0x2e5a5a cmp r3, r6 */
/* @0x2e5a5c beq 0x2e5a8c <FT_Face_Properties+0x94> */
/* @0x2e5a5e cmp r3, r7 */
/* @0x2e5a60 bne 0x2e5a1c <FT_Face_Properties+0x24> */
/* @0x2e5a62 ldr r3, [r2, #-4] */
/* @0x2e5a64 .word 0xf8d03c04 */
/* @0x2e5a66 ldr.w r10, [r0, #0x80] */
/* @0x2e5a68 smlalbblt r10, r11, r0, r0 */
/* @0x2e5a6a cbz r3, 0x2e5a80 <FT_Face_Properties+0x88> */
/* @0x2e5a6c ldr r3, [r3] */
/* @0x2e5a6e str.w r3, [r10, #0x3c] */
/* @0x2e5a70 .word 0xf8d0303c */
/* @0x2e5a72 ldr.w r3, [r0, #0x80] */
/* @0x2e5a74 blvs 0xffa31c7c <b2_toiTime+0xffffffffff2d87d8> */
/* @0x2e5a76 ldr r5, [r3, #0x3c] */
/* @0x2e5a78 cmp r5, #0x0 */
/* @0x2e5a7a bge 0x2e5a4a <FT_Face_Properties+0x52> */
/* @0x2e5a7c str r4, [r3, #0x3c] */
/* @0x2e5a7e b 0x2e5a4a <FT_Face_Properties+0x52> */
/* @0x2e5a80 str.w r12, [r10, #0x3c] */
/* @0x2e5a84 b 0x2e5a4a <FT_Face_Properties+0x52> */
/* @0x2e5a86 mov r0, r1 */
/* @0x2e5a88 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e5a8c movs r0, #0x7 */
/* @0x2e5a8e pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e5a90 svclt #0x8ff0 */
/* @0x2e5a92 nop */
/* @0x2e5a94 str r6, [r4, #0x44] */
/* @0x2e5a96 ldr r3, [r4, #0x44] */
/* @0x2e5a98 str r4, [r4, #0x54] */
/* @0x2e5a9a strb r5, [r4, #0xd] */
/* @0x2e5a9c strb r3, [r5, #0x9] */
/* @0x2e5a9e str r1, [r4, #0x44] */

/* ── FUNC 0x2e5aa0 · FT_Get_Name_Index · size=88 · insn=43 */
/* @0x2e5aa0 push {r3, r4, r5, lr} */
/* @0x2e5aa2 mov r5, r1 */
/* @0x2e5aa4 mov r4, r0 */
/* @0x2e5aa6 cbnz r0, 0x2e5aac <FT_Get_Name_Index+0xc> */
/* @0x2e5aa8 movs r0, #0x0 */
/* @0x2e5aaa pop {r3, r4, r5, pc} */
/* @0x2e5aac ldr r3, [r0, #0x8] */
/* @0x2e5aae lsls r1, r3, #0x16 */
/* @0x2e5ab0 bpl 0x2e5aa8 <FT_Get_Name_Index+0x8> */
/* @0x2e5ab2 cmp r5, #0x0 */
/* @0x2e5ab4 beq 0x2e5aa8 <FT_Get_Name_Index+0x8> */
/* @0x2e5ab6 ldr.w r3, [r0, #0x80] */
/* @0x2e5ab8 bvs 0xfe9b1cc0 <b2_toiTime+0xfffffffffe25881c> */
/* @0x2e5aba ldr r3, [r3, #0x28] */
/* @0x2e5abc adds r2, r3, #0x2 */
/* @0x2e5abe beq 0x2e5aa8 <FT_Get_Name_Index+0x8> */
/* @0x2e5ac0 cbnz r3, 0x2e5ae4 <FT_Get_Name_Index+0x44> */
/* @0x2e5ac2 ldr r0, [r0, #0x60] */
/* @0x2e5ac4 ldr r2, [r0] */
/* @0x2e5ac6 ldr r2, [r2, #0x20] */
/* @0x2e5ac8 cbz r2, 0x2e5ad2 <FT_Get_Name_Index+0x32> */
/* @0x2e5aca ldr r1, [pc, #0x28] */
/* @0x2e5acc add r1, pc */
/* @0x2e5ace blx r2 */
/* @0x2e5ad0 mov r3, r0 */
/* @0x2e5ad2 ldr.w r2, [r4, #0x80] */
/* @0x2e5ad4 blhs 0x2edcdc <FT_Done_Memory+0x4068> */
/* @0x2e5ad6 cmp r3, #0x0 */
/* @0x2e5ad8 ite ne */
/* @0x2e5ada movne r1, r3 */
/* @0x2e5adc mvneq r1, #0x1 */
/* @0x2e5ae0 str r1, [r2, #0x28] */
/* @0x2e5ae2 beq 0x2e5aa8 <FT_Get_Name_Index+0x8> */
/* @0x2e5ae4 ldr r3, [r3, #0x4] */
/* @0x2e5ae6 cmp r3, #0x0 */
/* @0x2e5ae8 beq 0x2e5aa8 <FT_Get_Name_Index+0x8> */
/* @0x2e5aea mov r0, r4 */
/* @0x2e5aec mov r1, r5 */
/* @0x2e5aee blx r3 */
/* @0x2e5af0 pop {r3, r4, r5, pc} */
/* @0x2e5af2 nop */
/* @0x2e5af4 ldrh r0, [r4, #0x20] */
/* @0x2e5af6 movs r2, r1 */

/* ── FUNC 0x2e5af8 · FT_Get_Glyph_Name · size=128 · insn=59 */
/* @0x2e5af8 push.w {r4, r5, r6, r7, r8, lr} */
/* @0x2e5afc mov r7, r1 */
/* @0x2e5afe mov r5, r2 */
/* @0x2e5b00 mov r8, r3 */
/* @0x2e5b02 mov r4, r0 */
/* @0x2e5b04 cmp r0, #0x0 */
/* @0x2e5b06 beq 0x2e5b66 <FT_Get_Glyph_Name+0x6e> */
/* @0x2e5b08 cbnz r2, 0x2e5b10 <FT_Get_Glyph_Name+0x18> */
/* @0x2e5b0a movs r0, #0x6 */
/* @0x2e5b0c pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e5b10 cmp r3, #0x0 */
/* @0x2e5b12 beq 0x2e5b0a <FT_Get_Glyph_Name+0x12> */
/* @0x2e5b14 movs r3, #0x0 */
/* @0x2e5b16 strb r3, [r2] */
/* @0x2e5b18 ldr r3, [r0, #0x10] */
/* @0x2e5b1a cmp r1, r3 */
/* @0x2e5b1c bge 0x2e5b6c <FT_Get_Glyph_Name+0x74> */
/* @0x2e5b1e ldr r3, [r0, #0x8] */
/* @0x2e5b20 lsls r2, r3, #0x16 */
/* @0x2e5b22 bpl 0x2e5b0a <FT_Get_Glyph_Name+0x12> */
/* @0x2e5b24 ldr.w r3, [r0, #0x80] */
/* @0x2e5b28 ldr r0, [r3, #0x28] */
/* @0x2e5b2a adds r3, r0, #0x2 */
/* @0x2e5b2c beq 0x2e5b0a <FT_Get_Glyph_Name+0x12> */
/* @0x2e5b2e cbnz r0, 0x2e5b52 <FT_Get_Glyph_Name+0x5a> */
/* @0x2e5b30 ldr r2, [r4, #0x60] */
/* @0x2e5b32 ldr r3, [r2] */
/* @0x2e5b34 ldr r3, [r3, #0x20] */
/* @0x2e5b36 cbz r3, 0x2e5b40 <FT_Get_Glyph_Name+0x48> */
/* @0x2e5b38 ldr r1, [pc, #0x38] */
/* @0x2e5b3a mov r0, r2 */
/* @0x2e5b3c add r1, pc */
/* @0x2e5b3e blx r3 */
/* @0x2e5b40 ldr.w r3, [r4, #0x80] */
/* @0x2e5b44 cmp r0, #0x0 */
/* @0x2e5b46 ite ne */
/* @0x2e5b48 movne r2, r0 */
/* @0x2e5b4a mvneq r2, #0x1 */
/* @0x2e5b4c addsvs r0, r10, #268435456 */
/* @0x2e5b4e str r2, [r3, #0x28] */
/* @0x2e5b50 beq 0x2e5b0a <FT_Get_Glyph_Name+0x12> */
/* @0x2e5b52 ldr r6, [r0] */
/* @0x2e5b54 cmp r6, #0x0 */
/* @0x2e5b56 beq 0x2e5b0a <FT_Get_Glyph_Name+0x12> */
/* @0x2e5b58 mov r0, r4 */
/* @0x2e5b5a mov r1, r7 */
/* @0x2e5b5c mov r2, r5 */
/* @0x2e5b5e mov r3, r8 */
/* @0x2e5b60 blx r6 */
/* @0x2e5b62 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e5b64 .word 0x202381f0 */
/* @0x2e5b66 movs r0, #0x23 */
/* @0x2e5b68 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e5b6c movs r0, #0x10 */
/* @0x2e5b6e pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e5b70 svclt #0x81f0 */
/* @0x2e5b72 nop */
/* @0x2e5b74 ldrh r0, [r6, #0x1c] */
/* @0x2e5b76 movs r2, r1 */

/* ── FUNC 0x2e5b78 · FT_Get_Postscript_Name · size=72 · insn=35 */
/* @0x2e5b78 push {r4, lr} */
/* @0x2e5b7a mov r4, r0 */
/* @0x2e5b7c cbnz r0, 0x2e5b82 <FT_Get_Postscript_Name+0xa> */
/* @0x2e5b7e movs r0, #0x0 */
/* @0x2e5b80 pop {r4, pc} */
/* @0x2e5b82 ldr.w r3, [r0, #0x80] */
/* @0x2e5b84 ldmibvs r11, {r7, r12, sp} ^ */
/* @0x2e5b86 ldr r3, [r3, #0x1c] */
/* @0x2e5b88 adds r2, r3, #0x2 */
/* @0x2e5b8a beq 0x2e5b7e <FT_Get_Postscript_Name+0x6> */
/* @0x2e5b8c cbnz r3, 0x2e5bb0 <FT_Get_Postscript_Name+0x38> */
/* @0x2e5b8e ldr r0, [r0, #0x60] */
/* @0x2e5b90 ldr r2, [r0] */
/* @0x2e5b92 ldr r2, [r2, #0x20] */
/* @0x2e5b94 cbz r2, 0x2e5b9e <FT_Get_Postscript_Name+0x26> */
/* @0x2e5b96 ldr r1, [pc, #0x24] */
/* @0x2e5b98 add r1, pc */
/* @0x2e5b9a blx r2 */
/* @0x2e5b9c mov r3, r0 */
/* @0x2e5b9e ldr.w r2, [r4, #0x80] */
/* @0x2e5ba0 blhs 0x2edda8 <FT_Done_Memory+0x4134> */
/* @0x2e5ba2 cmp r3, #0x0 */
/* @0x2e5ba4 ite ne */
/* @0x2e5ba6 movne r1, r3 */
/* @0x2e5ba8 mvneq r1, #0x1 */
/* @0x2e5bac str r1, [r2, #0x1c] */
/* @0x2e5bae beq 0x2e5b7e <FT_Get_Postscript_Name+0x6> */
/* @0x2e5bb0 ldr r3, [r3] */
/* @0x2e5bb2 cmp r3, #0x0 */
/* @0x2e5bb4 beq 0x2e5b7e <FT_Get_Postscript_Name+0x6> */
/* @0x2e5bb6 mov r0, r4 */
/* @0x2e5bb8 blx r3 */
/* @0x2e5bba pop {r4, pc} */
/* @0x2e5bbc ldrh r7, [r3, #0x1a] */
/* @0x2e5bbe movs r2, r1 */

/* ── FUNC 0x2e5bc0 · FT_Get_Sfnt_Table · size=52 · insn=26 */
/* @0x2e5bc0 push {r3, r4, r5, lr} */
/* @0x2e5bc2 mov r5, r1 */
/* @0x2e5bc4 mov r4, r0 */
/* @0x2e5bc6 cbnz r0, 0x2e5bcc <FT_Get_Sfnt_Table+0xc> */
/* @0x2e5bc8 movs r0, #0x0 */
/* @0x2e5bca pop {r3, r4, r5, pc} */
/* @0x2e5bcc ldr r3, [r0, #0x8] */
/* @0x2e5bce lsls r3, r3, #0x1c */
/* @0x2e5bd0 bpl 0x2e5bc8 <FT_Get_Sfnt_Table+0x8> */
/* @0x2e5bd2 ldr r0, [r0, #0x60] */
/* @0x2e5bd4 ldr r3, [r0] */
/* @0x2e5bd6 ldr r3, [r3, #0x20] */
/* @0x2e5bd8 cmp r3, #0x0 */
/* @0x2e5bda beq 0x2e5bc8 <FT_Get_Sfnt_Table+0x8> */
/* @0x2e5bdc ldr r1, [pc, #0x10] */
/* @0x2e5bde add r1, pc */
/* @0x2e5be0 blx r3 */
/* @0x2e5be2 cmp r0, #0x0 */
/* @0x2e5be4 beq 0x2e5bc8 <FT_Get_Sfnt_Table+0x8> */
/* @0x2e5be6 ldr r3, [r0, #0x4] */
/* @0x2e5be8 mov r1, r5 */
/* @0x2e5bea mov r0, r4 */
/* @0x2e5bec blx r3 */
/* @0x2e5bee pop {r3, r4, r5, pc} */
/* @0x2e5bf0 ldrh r6, [r5, #0x18] */
/* @0x2e5bf2 movs r2, r1 */

/* ── FUNC 0x2e5bf4 · FT_Load_Sfnt_Table · size=72 · insn=34 */
/* @0x2e5bf4 push.w {r0, r1, r4, r5, r6, r7, r8, lr} */
/* @0x2e5bf8 mov r6, r1 */
/* @0x2e5bfa mov r8, r2 */
/* @0x2e5bfc mov r7, r3 */
/* @0x2e5bfe mov r4, r0 */
/* @0x2e5c00 cbz r0, 0x2e5c30 <FT_Load_Sfnt_Table+0x3c> */
/* @0x2e5c02 ldr r0, [r0, #0x8] */
/* @0x2e5c04 lsls r3, r0, #0x1c */
/* @0x2e5c06 bpl 0x2e5c30 <FT_Load_Sfnt_Table+0x3c> */
/* @0x2e5c08 ldr r0, [r4, #0x60] */
/* @0x2e5c0a ldr r5, [r0] */
/* @0x2e5c0c ldr r5, [r5, #0x20] */
/* @0x2e5c0e cbnz r5, 0x2e5c14 <FT_Load_Sfnt_Table+0x20> */
/* @0x2e5c10 movs r0, #0x7 */
/* @0x2e5c12 b 0x2e5c32 <FT_Load_Sfnt_Table+0x3e> */
/* @0x2e5c14 ldr r1, [pc, #0x20] */
/* @0x2e5c16 add r1, pc */
/* @0x2e5c18 blx r5 */
/* @0x2e5c1a cmp r0, #0x0 */
/* @0x2e5c1c beq 0x2e5c10 <FT_Load_Sfnt_Table+0x1c> */
/* @0x2e5c1e ldr r5, [sp, #0x20] */
/* @0x2e5c20 mov r1, r6 */
/* @0x2e5c22 mov r2, r8 */
/* @0x2e5c24 mov r3, r7 */
/* @0x2e5c26 str r5, [sp] */
/* @0x2e5c28 ldr r5, [r0] */
/* @0x2e5c2a mov r0, r4 */
/* @0x2e5c2c blx r5 */
/* @0x2e5c2e b 0x2e5c32 <FT_Load_Sfnt_Table+0x3e> */
/* @0x2e5c30 movs r0, #0x23 */
/* @0x2e5c32 add sp, #0x8 */
/* @0x2e5c34 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e5c38 ldrh r6, [r6, #0x16] */
/* @0x2e5c3a movs r2, r1 */

/* ── FUNC 0x2e5c3c · FT_Sfnt_Table_Info · size=72 · insn=34 */
/* @0x2e5c3c push.w {r0, r1, r2, r3, r4, r5, r6, r7, r8, lr} */
/* @0x2e5c40 mov r6, r1 */
/* @0x2e5c42 mov r7, r2 */
/* @0x2e5c44 mov r8, r3 */
/* @0x2e5c46 mov r4, r0 */
/* @0x2e5c48 cbz r0, 0x2e5c78 <FT_Sfnt_Table_Info+0x3c> */
/* @0x2e5c4a ldr r0, [r0, #0x8] */
/* @0x2e5c4c lsls r3, r0, #0x1c */
/* @0x2e5c4e bpl 0x2e5c78 <FT_Sfnt_Table_Info+0x3c> */
/* @0x2e5c50 ldr r0, [r4, #0x60] */
/* @0x2e5c52 ldr r5, [r0] */
/* @0x2e5c54 ldr r5, [r5, #0x20] */
/* @0x2e5c56 cbnz r5, 0x2e5c5c <FT_Sfnt_Table_Info+0x20> */
/* @0x2e5c58 movs r0, #0x7 */
/* @0x2e5c5a b 0x2e5c7a <FT_Sfnt_Table_Info+0x3e> */
/* @0x2e5c5c ldr r1, [pc, #0x20] */
/* @0x2e5c5e add r1, pc */
/* @0x2e5c60 blx r5 */
/* @0x2e5c62 cmp r0, #0x0 */
/* @0x2e5c64 beq 0x2e5c58 <FT_Sfnt_Table_Info+0x1c> */
/* @0x2e5c66 str.w r8, [sp] */
/* @0x2e5c68 ldrtmi r8, [r1], -r0 */
/* @0x2e5c6a mov r1, r6 */
/* @0x2e5c6c ldr r5, [r0, #0x8] */
/* @0x2e5c6e mov r2, r7 */
/* @0x2e5c70 mov r0, r4 */
/* @0x2e5c72 add r3, sp, #0xc */
/* @0x2e5c74 blx r5 */
/* @0x2e5c76 b 0x2e5c7a <FT_Sfnt_Table_Info+0x3e> */
/* @0x2e5c78 movs r0, #0x23 */
/* @0x2e5c7a add sp, #0x10 */
/* @0x2e5c7c pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e5c80 ldrh r6, [r5, #0x14] */
/* @0x2e5c82 movs r2, r1 */

/* ── FUNC 0x2e5c84 · FT_Get_CMap_Language_ID · size=60 · insn=30 */
/* @0x2e5c84 push {r0, r1, r4, lr} */
/* @0x2e5c86 mov r4, r0 */
/* @0x2e5c88 cbnz r0, 0x2e5c8e <FT_Get_CMap_Language_ID+0xa> */
/* @0x2e5c8a movs r0, #0x0 */
/* @0x2e5c8c b 0x2e5cb6 <FT_Get_CMap_Language_ID+0x32> */
/* @0x2e5c8e ldr r3, [r0] */
/* @0x2e5c90 cmp r3, #0x0 */
/* @0x2e5c92 beq 0x2e5c8a <FT_Get_CMap_Language_ID+0x6> */
/* @0x2e5c94 ldr r0, [r3, #0x60] */
/* @0x2e5c96 ldr r3, [r0] */
/* @0x2e5c98 ldr r3, [r3, #0x20] */
/* @0x2e5c9a cmp r3, #0x0 */
/* @0x2e5c9c beq 0x2e5c8a <FT_Get_CMap_Language_ID+0x6> */
/* @0x2e5c9e ldr r1, [pc, #0x1c] */
/* @0x2e5ca0 add r1, pc */
/* @0x2e5ca2 blx r3 */
/* @0x2e5ca4 cmp r0, #0x0 */
/* @0x2e5ca6 beq 0x2e5c8a <FT_Get_CMap_Language_ID+0x6> */
/* @0x2e5ca8 ldr r3, [r0] */
/* @0x2e5caa mov r1, sp */
/* @0x2e5cac mov r0, r4 */
/* @0x2e5cae blx r3 */
/* @0x2e5cb0 cmp r0, #0x0 */
/* @0x2e5cb2 bne 0x2e5c8a <FT_Get_CMap_Language_ID+0x6> */
/* @0x2e5cb4 ldr r0, [sp] */
/* @0x2e5cb6 add sp, #0x8 */
/* @0x2e5cb8 pop {r4, pc} */
/* @0x2e5cba nop */
/* @0x2e5cbc ldrh r7, [r6, #0x12] */
/* @0x2e5cbe movs r2, r1 */

/* ── FUNC 0x2e5cc0 · FT_Get_CMap_Format · size=60 · insn=30 */
/* @0x2e5cc0 push {r0, r1, r4, lr} */
/* @0x2e5cc2 mov r4, r0 */
/* @0x2e5cc4 cbnz r0, 0x2e5ccc <FT_Get_CMap_Format+0xc> */
/* @0x2e5cc6 mov.w r0, #0xffffffff */
/* @0x2e5cc8 ldrsh r3, [r3], -pc */
/* @0x2e5cca b 0x2e5cf4 <FT_Get_CMap_Format+0x34> */
/* @0x2e5ccc ldr r3, [r0] */
/* @0x2e5cce cmp r3, #0x0 */
/* @0x2e5cd0 beq 0x2e5cc6 <FT_Get_CMap_Format+0x6> */
/* @0x2e5cd2 ldr r0, [r3, #0x60] */
/* @0x2e5cd4 ldr r3, [r0] */
/* @0x2e5cd6 ldr r3, [r3, #0x20] */
/* @0x2e5cd8 cmp r3, #0x0 */
/* @0x2e5cda beq 0x2e5cc6 <FT_Get_CMap_Format+0x6> */
/* @0x2e5cdc ldr r1, [pc, #0x18] */
/* @0x2e5cde add r1, pc */
/* @0x2e5ce0 blx r3 */
/* @0x2e5ce2 cmp r0, #0x0 */
/* @0x2e5ce4 beq 0x2e5cc6 <FT_Get_CMap_Format+0x6> */
/* @0x2e5ce6 ldr r3, [r0] */
/* @0x2e5ce8 mov r1, sp */
/* @0x2e5cea mov r0, r4 */
/* @0x2e5cec blx r3 */
/* @0x2e5cee cmp r0, #0x0 */
/* @0x2e5cf0 bne 0x2e5cc6 <FT_Get_CMap_Format+0x6> */
/* @0x2e5cf2 ldr r0, [sp, #0x4] */
/* @0x2e5cf4 add sp, #0x8 */
/* @0x2e5cf6 pop {r4, pc} */
/* @0x2e5cf8 ldrh r1, [r7, #0x10] */
/* @0x2e5cfa movs r2, r1 */

/* ── FUNC 0x2e5cfc · FT_Set_Charmap · size=60 · insn=29 */
/* @0x2e5cfc push {r4, r5, r6, lr} */
/* @0x2e5cfe mov r5, r1 */
/* @0x2e5d00 mov r4, r0 */
/* @0x2e5d02 cbz r0, 0x2e5d2c <FT_Set_Charmap+0x30> */
/* @0x2e5d04 ldr r6, [r0, #0x28] */
/* @0x2e5d06 cbz r6, 0x2e5d30 <FT_Set_Charmap+0x34> */
/* @0x2e5d08 cbz r1, 0x2e5d30 <FT_Set_Charmap+0x34> */
/* @0x2e5d0a mov r0, r1 */
/* @0x2e5d0c bl 0x2e5cc0 <FT_Get_CMap_Format> */
/* @0x2e5d10 cmp r0, #0xe */
/* @0x2e5d12 beq 0x2e5d34 <FT_Set_Charmap+0x38> */
/* @0x2e5d14 ldr r3, [r4, #0x24] */
/* @0x2e5d16 add.w r3, r6, r3, lsl #2 */
/* @0x2e5d18 addsmi r0, lr, #201326594 */
/* @0x2e5d1a cmp r6, r3 */
/* @0x2e5d1c bhs 0x2e5d34 <FT_Set_Charmap+0x38> */
/* @0x2e5d1e ldr r2, [r6], #4 */
/* @0x2e5d20 adcmi r2, r10, #4, #22 */
/* @0x2e5d22 cmp r2, r5 */
/* @0x2e5d24 bne 0x2e5d1a <FT_Set_Charmap+0x1e> */
/* @0x2e5d26 str r5, [r4, #0x5c] */
/* @0x2e5d28 movs r0, #0x0 */
/* @0x2e5d2a pop {r4, r5, r6, pc} */
/* @0x2e5d2c movs r0, #0x23 */
/* @0x2e5d2e pop {r4, r5, r6, pc} */
/* @0x2e5d30 movs r0, #0x26 */
/* @0x2e5d32 pop {r4, r5, r6, pc} */
/* @0x2e5d34 movs r0, #0x6 */
/* @0x2e5d36 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2e5d38 · anon_2e5d38 · size=44 · insn=12 */
/* @0x2e5d38 bvs 0xfe413300 <b2_toiTime+0xfffffffffdcb9e5c> */
/* @0x2e5d3c andhs r11, r0, r12, lsl #18 */
/* @0x2e5d40 bvs 0x1495308 <b2_toiTime+0xd3be64> */
/* @0x2e5d44 streq lr, [r6], r4, lsl #22 */
/* @0x2e5d48 .word 0x462542b4 */
/* @0x2e5d4c .word 0xf854d2f7 */
/* @0x2e5d50 stmvs r3, {r2, r8, r9, r11} */
/* @0x2e5d54 svchs #0xa0f5b3 */
/* @0x2e5d58 .word 0xf7ffd1f6 */
/* @0x2e5d5c stmdahs lr, {r0, r4, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e5d60 stmdavs r8!, {r1, r4, r5, r6, r7, r8, r12, lr, pc} */
/* @0x2e5d64 andeq r11, r0, r0, ror sp */

/* ── FUNC 0x2e5d68 · FT_Face_GetCharVariantIndex · size=56 · insn=27 */
/* @0x2e5d68 push {r3, r4, r5, r6, r7, lr} */
/* @0x2e5d6a mov r7, r1 */
/* @0x2e5d6c mov r6, r2 */
/* @0x2e5d6e mov r4, r0 */
/* @0x2e5d70 cbnz r0, 0x2e5d76 <FT_Face_GetCharVariantIndex+0xe> */
/* @0x2e5d72 movs r0, #0x0 */
/* @0x2e5d74 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2e5d76 ldr r5, [r0, #0x5c] */
/* @0x2e5d78 cmp r5, #0x0 */
/* @0x2e5d7a beq 0x2e5d72 <FT_Face_GetCharVariantIndex+0xa> */
/* @0x2e5d7c ldr r2, [r5, #0x4] */
/* @0x2e5d7e ldr r3, [pc, #0x1c] */
/* @0x2e5d80 cmp r2, r3 */
/* @0x2e5d82 bne 0x2e5d72 <FT_Face_GetCharVariantIndex+0xa> */
/* @0x2e5d84 bl 0x2e5d38 <FT_Set_Charmap+0x3c> */
/* @0x2e5d88 ldr r1, [r4, #0x5c] */
/* @0x2e5d8a cmp r0, #0x0 */
/* @0x2e5d8c beq 0x2e5d72 <FT_Face_GetCharVariantIndex+0xa> */
/* @0x2e5d8e ldr r3, [r0, #0xc] */
/* @0x2e5d90 mov r2, r7 */
/* @0x2e5d92 ldr r4, [r3, #0x14] */
/* @0x2e5d94 mov r3, r6 */
/* @0x2e5d96 blx r4 */
/* @0x2e5d98 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2e5d9a nop */
/* @0x2e5d9c ldr r3, [r4, #0x14] */
/* @0x2e5d9e strb r6, [r5, #0x15] */

/* ── FUNC 0x2e5da0 · FT_Face_GetCharVariantIsDefault · size=34 · insn=16 */
/* @0x2e5da0 push {r3, r4, r5, lr} */
/* @0x2e5da2 mov r5, r1 */
/* @0x2e5da4 mov r4, r2 */
/* @0x2e5da6 cbnz r0, 0x2e5dae <FT_Face_GetCharVariantIsDefault+0xe> */
/* @0x2e5da8 mov.w r0, #0xffffffff */
/* @0x2e5dac pop {r3, r4, r5, pc} */
/* @0x2e5dae bl 0x2e5d38 <FT_Set_Charmap+0x3c> */
/* @0x2e5db0 stmdahs r0, {r0, r1, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e5db2 cmp r0, #0x0 */
/* @0x2e5db4 beq 0x2e5da8 <FT_Face_GetCharVariantIsDefault+0x8> */
/* @0x2e5db6 ldr r3, [r0, #0xc] */
/* @0x2e5db8 mov r1, r5 */
/* @0x2e5dba mov r2, r4 */
/* @0x2e5dbc ldr r3, [r3, #0x18] */
/* @0x2e5dbe blx r3 */
/* @0x2e5dc0 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2e5dc2 · FT_Face_GetVariantSelectors · size=28 · insn=14 */
/* @0x2e5dc2 push {r4, lr} */
/* @0x2e5dc4 mov r4, r0 */
/* @0x2e5dc6 cbnz r0, 0x2e5dcc <FT_Face_GetVariantSelectors+0xa> */
/* @0x2e5dc8 movs r0, #0x0 */
/* @0x2e5dca pop {r4, pc} */
/* @0x2e5dcc bl 0x2e5d38 <FT_Set_Charmap+0x3c> */
/* @0x2e5dce stmdahs r0, {r2, r4, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e5dd0 cmp r0, #0x0 */
/* @0x2e5dd2 beq 0x2e5dc8 <FT_Face_GetVariantSelectors+0x6> */
/* @0x2e5dd4 ldr r3, [r0, #0xc] */
/* @0x2e5dd6 ldr r1, [r4, #0x64] */
/* @0x2e5dd8 ldr r3, [r3, #0x1c] */
/* @0x2e5dda blx r3 */
/* @0x2e5ddc pop {r4, pc} */

/* ── FUNC 0x2e5dde · FT_Face_GetVariantsOfChar · size=32 · insn=15 */
/* @0x2e5dde push {r3, r4, r5, lr} */
/* @0x2e5de0 mov r4, r1 */
/* @0x2e5de2 mov r5, r0 */
/* @0x2e5de4 cbnz r0, 0x2e5dea <FT_Face_GetVariantsOfChar+0xc> */
/* @0x2e5de6 movs r0, #0x0 */
/* @0x2e5de8 pop {r3, r4, r5, pc} */
/* @0x2e5dea bl 0x2e5d38 <FT_Set_Charmap+0x3c> */
/* @0x2e5dee cmp r0, #0x0 */
/* @0x2e5df0 beq 0x2e5de6 <FT_Face_GetVariantsOfChar+0x8> */
/* @0x2e5df2 ldr r3, [r0, #0xc] */
/* @0x2e5df4 mov r2, r4 */
/* @0x2e5df6 ldr r1, [r5, #0x64] */
/* @0x2e5df8 ldr r3, [r3, #0x20] */
/* @0x2e5dfa blx r3 */
/* @0x2e5dfc pop {r3, r4, r5, pc} */

/* ── FUNC 0x2e5dfe · FT_Face_GetCharsOfVariant · size=32 · insn=15 */
/* @0x2e5dfe push {r3, r4, r5, lr} */
/* @0x2e5e00 mov r4, r1 */
/* @0x2e5e02 mov r5, r0 */
/* @0x2e5e04 cbnz r0, 0x2e5e0a <FT_Face_GetCharsOfVariant+0xc> */
/* @0x2e5e06 movs r0, #0x0 */
/* @0x2e5e08 pop {r3, r4, r5, pc} */
/* @0x2e5e0a bl 0x2e5d38 <FT_Set_Charmap+0x3c> */
/* @0x2e5e0e cmp r0, #0x0 */
/* @0x2e5e10 beq 0x2e5e06 <FT_Face_GetCharsOfVariant+0x8> */
/* @0x2e5e12 ldr r3, [r0, #0xc] */
/* @0x2e5e14 mov r2, r4 */
/* @0x2e5e16 ldr r1, [r5, #0x64] */
/* @0x2e5e18 ldr r3, [r3, #0x24] */
/* @0x2e5e1a blx r3 */
/* @0x2e5e1c pop {r3, r4, r5, pc} */

/* ── FUNC 0x2e5e1e · FT_Activate_Size · size=24 · insn=12 */
/* @0x2e5e1e cbz r0, 0x2e5e2e <FT_Activate_Size+0x10> */
/* @0x2e5e20 ldr r3, [r0] */
/* @0x2e5e22 cbz r3, 0x2e5e32 <FT_Activate_Size+0x14> */
/* @0x2e5e24 ldr r2, [r3, #0x60] */
/* @0x2e5e26 cbz r2, 0x2e5e32 <FT_Activate_Size+0x14> */
/* @0x2e5e28 str r0, [r3, #0x58] */
/* @0x2e5e2a movs r0, #0x0 */
/* @0x2e5e2c bx lr */
/* @0x2e5e2e movs r0, #0x24 */
/* @0x2e5e30 bx lr */
/* @0x2e5e32 movs r0, #0x23 */
/* @0x2e5e34 bx lr */

/* ── FUNC 0x2e5e36 · FT_Lookup_Renderer · size=50 · insn=24 */
/* @0x2e5e36 push {r4, lr} */
/* @0x2e5e38 cbnz r0, 0x2e5e3e <FT_Lookup_Renderer+0x8> */
/* @0x2e5e3a movs r0, #0x0 */
/* @0x2e5e3c pop {r4, pc} */
/* @0x2e5e3e ldr.w r3, [r0, #0x94] */
/* @0x2e5e42 cbz r2, 0x2e5e5a <FT_Lookup_Renderer+0x24> */
/* @0x2e5e44 ldr r0, [r2] */
/* @0x2e5e46 cbz r0, 0x2e5e4a <FT_Lookup_Renderer+0x14> */
/* @0x2e5e48 ldr r3, [r0, #0x4] */
/* @0x2e5e4a movs r0, #0x0 */
/* @0x2e5e4c str r0, [r2] */
/* @0x2e5e4e b 0x2e5e5a <FT_Lookup_Renderer+0x24> */
/* @0x2e5e50 ldr r0, [r3, #0x8] */
/* @0x2e5e52 ldr r4, [r0, #0x10] */
/* @0x2e5e54 cmp r4, r1 */
/* @0x2e5e56 beq 0x2e5e60 <FT_Lookup_Renderer+0x2a> */
/* @0x2e5e58 ldr r3, [r3, #0x4] */
/* @0x2e5e5a cmp r3, #0x0 */
/* @0x2e5e5c bne 0x2e5e50 <FT_Lookup_Renderer+0x1a> */
/* @0x2e5e5e b 0x2e5e3a <FT_Lookup_Renderer+0x4> */
/* @0x2e5e60 cbz r2, 0x2e5e66 <FT_Lookup_Renderer+0x30> */
/* @0x2e5e62 str r3, [r2] */
/* @0x2e5e64 pop {r4, pc} */
/* @0x2e5e66 pop {r4, pc} */

/* ── FUNC 0x2e5e68 · FT_Get_Renderer · size=6 · insn=3 */
/* @0x2e5e68 movs r2, #0x0 */
/* @0x2e5e6a b.w 0x2e5e36 <FT_Lookup_Renderer> */
/* @0x2e5e6c andeq r11, r0, r4, ror #31 */

/* ── FUNC 0x2e5e70 · FT_Render_Glyph_Internal · size=104 · insn=48 */
/* @0x2e5e70 push.w {r0, r1, r4, r5, r6, r7, r8, lr} */
/* @0x2e5e74 mov r6, r1 */
/* @0x2e5e76 ldr r3, [pc, #0x58] */
/* @0x2e5e78 mov r5, r0 */
/* @0x2e5e7a ldr r1, [r1, #0x48] */
/* @0x2e5e7c mov r7, r2 */
/* @0x2e5e7e movs r4, #0x0 */
/* @0x2e5e80 cmp r1, r3 */
/* @0x2e5e82 beq 0x2e5ec6 <FT_Render_Glyph_Internal+0x56> */
/* @0x2e5e84 ldr r3, [pc, #0x4c] */
/* @0x2e5e86 str r4, [sp, #0x4] */
/* @0x2e5e88 cmp r1, r3 */
/* @0x2e5e8a bne 0x2e5e98 <FT_Render_Glyph_Internal+0x28> */
/* @0x2e5e8c ldr.w r3, [r5, #0x94] */
/* @0x2e5e90 ldr.w r0, [r0, #0x9c] */
/* @0x2e5e94 str r3, [sp, #0x4] */
/* @0x2e5e96 b 0x2e5e9e <FT_Render_Glyph_Internal+0x2e> */
/* @0x2e5e98 add r2, sp, #0x4 */
/* @0x2e5e9a bl 0x2e5e36 <FT_Lookup_Renderer> */
/* @0x2e5e9c .word 0xf10dffcc */
/* @0x2e5e9e add.w r8, sp, #0x4 */
/* @0x2e5ea0 strhs r0, [r7], #-2052 */
/* @0x2e5ea2 movs r4, #0x7 */
/* @0x2e5ea4 cbz r0, 0x2e5ec6 <FT_Render_Glyph_Internal+0x56> */
/* @0x2e5ea6 ldr r4, [r0, #0x3c] */
/* @0x2e5ea8 mov r1, r6 */
/* @0x2e5eaa mov r2, r7 */
/* @0x2e5eac movs r3, #0x0 */
/* @0x2e5eae blx r4 */
/* @0x2e5eb0 mov r4, r0 */
/* @0x2e5eb2 cbz r0, 0x2e5ec6 <FT_Render_Glyph_Internal+0x56> */
/* @0x2e5eb4 uxtb r3, r0 */
/* @0x2e5eb6 cmp r3, #0x13 */
/* @0x2e5eb8 bne 0x2e5ec6 <FT_Render_Glyph_Internal+0x56> */
/* @0x2e5eba mov r0, r5 */
/* @0x2e5ebc ldr r1, [r6, #0x48] */
/* @0x2e5ebe mov r2, r8 */
/* @0x2e5ec0 bl 0x2e5e36 <FT_Lookup_Renderer> */
/* @0x2e5ec4 b 0x2e5ea4 <FT_Render_Glyph_Internal+0x34> */
/* @0x2e5ec6 mov r0, r4 */
/* @0x2e5ec8 add sp, #0x8 */
/* @0x2e5eca pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e5ecc svclt #0x81f0 */
/* @0x2e5ece nop */
/* @0x2e5ed0 strb r3, [r6, #0x11] */
/* @0x2e5ed2 str r1, [r5, #0x24] */
/* @0x2e5ed4 strb r4, [r5, #0x11] */
/* @0x2e5ed6 ldr r5, [r6, #0x74] */

/* ── FUNC 0x2e5ed8 · FT_Render_Glyph · size=24 · insn=11 */
/* @0x2e5ed8 mov r2, r1 */
/* @0x2e5eda mov r3, r0 */
/* @0x2e5edc cbz r0, 0x2e5eec <FT_Render_Glyph+0x14> */
/* @0x2e5ede ldr r0, [r0, #0x4] */
/* @0x2e5ee0 cbz r0, 0x2e5eec <FT_Render_Glyph+0x14> */
/* @0x2e5ee2 ldr r1, [r0, #0x60] */
/* @0x2e5ee4 ldr r0, [r1, #0x4] */
/* @0x2e5ee6 mov r1, r3 */
/* @0x2e5ee8 b.w 0x2e5e70 <FT_Render_Glyph_Internal> */
/* @0x2e5eec movs r0, #0x6 */
/* @0x2e5eee bx lr */

/* ── FUNC 0x2e5ef0 · FT_Get_Module · size=56 · insn=27 */
/* @0x2e5ef0 push {r3, r4, r5, r6, r7, lr} */
/* @0x2e5ef2 mov r5, r1 */
/* @0x2e5ef4 cbz r0, 0x2e5f1e <FT_Get_Module+0x2e> */
/* @0x2e5ef6 cbz r1, 0x2e5f22 <FT_Get_Module+0x32> */
/* @0x2e5ef8 ldr r7, [r0, #0x10] */
/* @0x2e5efa add.w r6, r0, #0x14 */
/* @0x2e5efc bl 0x467754 <g_RomDisk+0x6ff34> */
/* @0x2e5efe add.w r7, r6, r7, lsl #2 */
/* @0x2e5f00 adcsmi r0, lr, #35389440 */
/* @0x2e5f02 cmp r6, r7 */
/* @0x2e5f04 bhs 0x2e5f1a <FT_Get_Module+0x2a> */
/* @0x2e5f06 ldr r4, [r6], #4 */
/* @0x2e5f08 strtmi r4, [r9], -r4, lsl #22 */
/* @0x2e5f0a mov r1, r5 */
/* @0x2e5f0c ldr r3, [r4] */
/* @0x2e5f0e ldr r0, [r3, #0x8] */
/* @0x2e5f10 blx 0xb6574 <strcmp@plt> */
/* @0x2e5f14 cmp r0, #0x0 */
/* @0x2e5f16 bne 0x2e5f02 <FT_Get_Module+0x12> */
/* @0x2e5f18 b 0x2e5f24 <FT_Get_Module+0x34> */
/* @0x2e5f1a movs r4, #0x0 */
/* @0x2e5f1c b 0x2e5f24 <FT_Get_Module+0x34> */
/* @0x2e5f1e mov r4, r0 */
/* @0x2e5f20 b 0x2e5f24 <FT_Get_Module+0x34> */
/* @0x2e5f22 mov r4, r1 */
/* @0x2e5f24 mov r0, r4 */
/* @0x2e5f26 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2e5f28 · FT_Get_Module_Interface · size=14 · insn=7 */
/* @0x2e5f28 push {r3, lr} */
/* @0x2e5f2a bl 0x2e5ef0 <FT_Get_Module> */
/* @0x2e5f2c smlattlt r8, r1, pc, pc */
/* @0x2e5f2e cbz r0, 0x2e5f34 <FT_Get_Module_Interface+0xc> */
/* @0x2e5f30 ldr r3, [r0] */
/* @0x2e5f32 ldr r0, [r3, #0x14] */
/* @0x2e5f34 pop {r3, pc} */

/* ── FUNC 0x2e5f36 · ft_module_get_service · size=76 · insn=37 */
/* @0x2e5f36 push {r3, r4, r5, r6, r7, lr} */
/* @0x2e5f38 mov r6, r1 */
/* @0x2e5f3a mov r5, r2 */
/* @0x2e5f3c mov r4, r0 */
/* @0x2e5f3e cbnz r0, 0x2e5f44 <ft_module_get_service+0xe> */
/* @0x2e5f40 movs r0, #0x0 */
/* @0x2e5f42 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2e5f44 ldr r3, [r0] */
/* @0x2e5f46 ldr r3, [r3, #0x20] */
/* @0x2e5f48 cbz r3, 0x2e5f7a <ft_module_get_service+0x44> */
/* @0x2e5f4a blx r3 */
/* @0x2e5f4c cbz r5, 0x2e5f80 <ft_module_get_service+0x4a> */
/* @0x2e5f4e cbnz r0, 0x2e5f80 <ft_module_get_service+0x4a> */
/* @0x2e5f50 ldr r3, [r4, #0x4] */
/* @0x2e5f52 add.w r5, r3, #0x14 */
/* @0x2e5f56 ldr r7, [r3, #0x10] */
/* @0x2e5f58 add.w r7, r5, r7, lsl #2 */
/* @0x2e5f5a adcsmi r0, sp, #35389440 */
/* @0x2e5f5c cmp r5, r7 */
/* @0x2e5f5e bhs 0x2e5f40 <ft_module_get_service+0xa> */
/* @0x2e5f60 ldr r0, [r5], #4 */
/* @0x2e5f62 adcmi r0, r0, #4, #22 */
/* @0x2e5f64 cmp r0, r4 */
/* @0x2e5f66 beq 0x2e5f5c <ft_module_get_service+0x26> */
/* @0x2e5f68 ldr r3, [r0] */
/* @0x2e5f6a ldr r3, [r3, #0x20] */
/* @0x2e5f6c cmp r3, #0x0 */
/* @0x2e5f6e beq 0x2e5f5c <ft_module_get_service+0x26> */
/* @0x2e5f70 mov r1, r6 */
/* @0x2e5f72 blx r3 */
/* @0x2e5f74 cmp r0, #0x0 */
/* @0x2e5f76 beq 0x2e5f5c <ft_module_get_service+0x26> */
/* @0x2e5f78 b 0x2e5f80 <ft_module_get_service+0x4a> */
/* @0x2e5f7a cmp r2, #0x0 */
/* @0x2e5f7c bne 0x2e5f50 <ft_module_get_service+0x1a> */
/* @0x2e5f7e b 0x2e5f40 <ft_module_get_service+0xa> */
/* @0x2e5f80 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2e5f82 · FT_Property_Set · size=20 · insn=8 */
/* @0x2e5f82 push {r0, r1, r4, lr} */
/* @0x2e5f84 mov.w lr, #0x0 */
/* @0x2e5f86 strhs r0, [r1], #-3584 */
/* @0x2e5f88 movs r4, #0x1 */
/* @0x2e5f8a stm.w sp, {r4, lr} */
/* @0x2e5f8e bl 0x2e4c80 <_ZNK11b2GearJoint8GetRatioEv+0x37c> */
/* @0x2e5f92 add sp, #0x8 */
/* @0x2e5f94 pop {r4, pc} */

/* ── FUNC 0x2e5f96 · FT_Property_Get · size=16 · insn=7 */
/* @0x2e5f96 push {r0, r1, r4, lr} */
/* @0x2e5f98 movs r4, #0x0 */
/* @0x2e5f9a str r4, [sp] */
/* @0x2e5f9c str r4, [sp, #0x4] */
/* @0x2e5f9e bl 0x2e4c80 <_ZNK11b2GearJoint8GetRatioEv+0x37c> */
/* @0x2e5fa2 add sp, #0x8 */
/* @0x2e5fa4 pop {r4, pc} */

/* ── FUNC 0x2e5fa6 · ft_property_string_set · size=16 · insn=7 */
/* @0x2e5fa6 push {r0, r1, r4, lr} */
/* @0x2e5fa8 movs r4, #0x1 */
/* @0x2e5faa str r4, [sp] */
/* @0x2e5fac str r4, [sp, #0x4] */
/* @0x2e5fae bl 0x2e4c80 <_ZNK11b2GearJoint8GetRatioEv+0x37c> */
/* @0x2e5fb2 add sp, #0x8 */
/* @0x2e5fb4 pop {r4, pc} */
