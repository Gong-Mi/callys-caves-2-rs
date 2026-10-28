/* libyoyo.so 覆盖卡组 0291
 * 函数 0x2e64c9..0x2e6b51，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2e64c9 · FT_Outline_Render · size=84 · insn=0 */

/* ── FUNC 0x2e651d · FT_Outline_Get_Bitmap · size=44 · insn=0 */

/* ── FUNC 0x2e6549 · FT_Vector_Transform · size=56 · insn=0 */

/* ── FUNC 0x2e6581 · FT_Outline_Transform · size=36 · insn=0 */

/* ── FUNC 0x2e65a5 · FT_Outline_Get_Orientation · size=204 · insn=0 */

/* ── FUNC 0x2e6671 · FT_Outline_EmboldenXY · size=512 · insn=0 */

/* ── FUNC 0x2e6871 · FT_Outline_Embolden · size=6 · insn=0 */

/* ── FUNC 0x2e6876 · anon_2e6876 · size=88 · insn=22 */
/* @0x2e6876 stmvs r3, {r3, r4, r5, r8, r12, sp, pc} */
/* @0x2e687a movweq pc, #0x8013 */
/* @0x2e687e rfeia r0! */
/* @0x2e6882 .word 0x47700154 */
/* @0x2e6886 .word 0x47704618 */
/* @0x2e688a stm r0, {r8, r9, sp} */
/* @0x2e688e addvs r0, r3, r6 */
/* @0x2e6892 .word 0x61436203 */
/* @0x2e6896 ldrbmi r6, [r0, -r3, lsl #3]! */
/* @0x2e689a tstlt r0, r8, lsl #10 */
/* @0x2e689e smlabblt r3, r3, r9, r6 */
/* @0x2e68a2 stclt p7, c4, [r8, #-608] */
/* @0x2e68a6 .word 0x4604b570 */
/* @0x2e68aa strmi r6, [sp], -r6, asr #18 */
/* @0x2e68ae andhs r11, r0, #-2147483639 */
/* @0x2e68b2 .word 0x47b04613 */
/* @0x2e68b6 and r11, r2, r0, lsr r9 */
/* @0x2e68ba addsmi r6, r9, #4390912 */
/* @0x2e68be adcvs sp, r5, r2, lsl #16 */
/* @0x2e68c2 ldcllt p0, c2, [r0, #-0]! */
/* @0x2e68c6 ldcllt p0, c2, [r0, #-340]! */
/* @0x2e68ca .word 0xe92d0000 */

/* ── FUNC 0x2e6877 · FT_Get_Sfnt_Name_Count · size=20 · insn=0 */

/* ── FUNC 0x2e688b · FT_Stream_OpenMemory · size=16 · insn=0 */

/* ── FUNC 0x2e689b · FT_Stream_Close · size=12 · insn=0 */

/* ── FUNC 0x2e68a7 · FT_Stream_Seek · size=36 · insn=0 */

/* ── FUNC 0x2e68cc · anon_2e68cc · size=196 · insn=49 */
/* @0x2e68cc svcmi #0xf0e92d */
/* @0x2e68d0 .word 0xf8df2400 */
/* @0x2e68d4 addlt r11, r5, r8, asr r0 */
/* @0x2e68d8 strmi r4, [pc], -r0, lsl #13 */
/* @0x2e68dc .word 0x469144fb */
/* @0x2e68e0 ssatmi r4, #0x3, lr, lsl #12 */
/* @0x2e68e4 .word 0xf8464633 */
/* @0x2e68e8 .word 0xb147ab04 */
/* @0x2e68ec .word 0x21004638 */
/* @0x2e68f0 .word 0xf7ff9303 */
/* @0x2e68f4 stcls p15, c15, [pc, #-864] */
/* @0x2e68f8 blls 0x3bada0 <error_g0017+0x13a44> */
/* @0x2e68fc stcls p0, c14, [pc, #-4] */
/* @0x2e6900 stcls p1, c5, [pc, #-188] */
/* @0x2e6904 ldmdblt r2, {r1, r3, r5, r8, r11, r12, lr} ^ */
/* @0x2e6908 strbmi r9, [r0], -lr, lsl #20 */
/* @0x2e690c andspl pc, r4, r11, asr r8 */
/* @0x2e6910 strtmi r4, [r2], #-1593 */
/* @0x2e6914 strbmi r9, [r10], -r0, lsl #4 */
/* @0x2e6918 stcls p7, c4, [pc, #-672] */
/* @0x2e691c strlo r5, [r4], #-296 */
/* @0x2e6920 bicsle r2, pc, r4, lsr #24 */
/* @0x2e6924 pop {r0, r2, r12, sp, pc} */
/* @0x2e6928 svclt #0x8ff0 */
/* @0x2e692c andseq r2, r0, r8, lsl #1 */
/* @0x2e6930 blle 0x3b0d38 <error_g0017+0x99dc> */
/* @0x2e6934 ldrmi r6, [r9], #-2179 */
/* @0x2e6938 svclt #0xb5f7ff */
/* @0x2e693c .word 0x47702055 */
/* @0x2e6940 ldrbmi r6, [r0, -r0, lsl #17]! */
/* @0x2e6944 mvnsmi lr, sp, lsr #18 */
/* @0x2e6948 stmdavs r6, {r2, r9, r10, lr} ^ */
/* @0x2e694c ldrmi r4, [pc], -sp, lsl #12 */
/* @0x2e6950 andsle r4, r9, #268435467 */
/* @0x2e6954 ldrsbgt pc, [r4], -r0 */
/* @0x2e6958 svceq #0xf1bc */
/* @0x2e695c strbmi sp, [r0, r2]! */
/* @0x2e6960 and r4, r9, r6, lsl #12 */
/* @0x2e6964 stmdavs r1, {r1, r2, r4, r5, r6, r9, r11, r12} */
/* @0x2e6968 svclt #0x28429e */
/* @0x2e696c sadd16mi r4, r0, lr */
/* @0x2e6970 ldrtmi r4, [r2], -r9, lsr #8 */
/* @0x2e6974 cdp p5, #0x2, c15, c2, c15, #0x6 */
/* @0x2e6978 adcsmi r4, lr, #889192448 */
/* @0x2e697c subshs r11, r5, r4, lsr pc */
/* @0x2e6980 adcvs r2, r5, r0 */
/* @0x2e6984 ldrhhi lr, [r0, #141]! */
/* @0x2e6988 pop {r0, r2, r4, r6, sp} */
/* @0x2e698c ldrlt r8, [r0, #-0x1f0] */

/* ── FUNC 0x2e68cd · FT_Raccess_Guess · size=100 · insn=0 */

/* ── FUNC 0x2e6931 · FT_Stream_Skip · size=16 · insn=0 */

/* ── FUNC 0x2e6941 · FT_Stream_Pos · size=4 · insn=0 */

/* ── FUNC 0x2e6945 · FT_Stream_ReadAt · size=74 · insn=0 */

/* ── FUNC 0x2e698e · anon_2e698e · size=20 · insn=5 */
/* @0x2e698e .word 0x460cb510 */
/* @0x2e6992 stmvs r1, {r0, r1, r4, r9, r10, lr} */
/* @0x2e6996 pop {r1, r5, r9, r10, lr} */
/* @0x2e699a .word 0xf7ff4010 */
/* @0x2e699e ldrblt r11, [r8, #0xfd2]! */

/* ── FUNC 0x2e698f · FT_Stream_Read · size=18 · insn=0 */

/* ── FUNC 0x2e69a0 · anon_2e69a0 · size=64 · insn=16 */
/* @0x2e69a0 .word 0x460fb5f8 */
/* @0x2e69a4 strmi r6, [r4], -r5, asr #16 */
/* @0x2e69a8 ldrmi r6, [r3], -r1, lsl #17 */
/* @0x2e69ac andsle r4, r3, #-1879048182 */
/* @0x2e69b0 tstlt lr, r6, asr #18 */
/* @0x2e69b4 .word 0x47b0463a */
/* @0x2e69b8 and r4, r9, r5, lsl #12 */
/* @0x2e69bc stmdavs r3, {r0, r2, r3, r5, r6, r9, r11, r12} */
/* @0x2e69c0 svclt #0x3842aa */
/* @0x2e69c4 shadd16mi r4, r8, r5 */
/* @0x2e69c8 qadd16mi r4, r10, r9 */
/* @0x2e69cc ldcl p5, c15, [r6, #828]! */
/* @0x2e69d0 strtmi r6, [r11], #-2211 */
/* @0x2e69d4 and r6, r0, r3, lsr #1 */
/* @0x2e69d8 strtmi r2, [r8], -r0, lsl #10 */
/* @0x2e69dc bvs 0x3d61c4 <error_g0017+0x2ee68> */

/* ── FUNC 0x2e69a1 · FT_Stream_TryRead · size=62 · insn=0 */

/* ── FUNC 0x2e69de · anon_2e69de · size=296 · insn=74 */
/* @0x2e69de bvs 0x13811f2 <b2_toiTime+0xc27d4e> */
/* @0x2e69e2 svclt #0x3d4293 */
/* @0x2e69e6 andvs r1, r2, #23040 */
/* @0x2e69ea andhs r7, r0, r8, lsl r8 */
/* @0x2e69ee ldrbmi r11, [r0, -r0, asr #4]! */
/* @0x2e69f2 bvs 0x3b8202 <error_g0017+0x10ea6> */
/* @0x2e69f6 .word 0x1c586a51 */
/* @0x2e69fa stmdble r6, {r0, r7, r9, lr} */
/* @0x2e69fe movwlo r7, #0x2818 */
/* @0x2e6a02 .word 0x1c01f813 */
/* @0x2e6a06 andhs lr, r0, r1, asr #20 */
/* @0x2e6a0a andhs lr, r0, r0 */
/* @0x2e6a0e .word 0x47706213 */
/* @0x2e6a12 bvs 0x3b8222 <error_g0017+0x10ec6> */
/* @0x2e6a16 .word 0x1c586a51 */
/* @0x2e6a1a stmdble r6, {r0, r7, r9, lr} */
/* @0x2e6a1e movwlo r7, #0x2858 */
/* @0x2e6a22 .word 0x1c02f813 */
/* @0x2e6a26 andhs lr, r0, r1, asr #20 */
/* @0x2e6a2a andhs lr, r0, r0 */
/* @0x2e6a2e .word 0x47706213 */
/* @0x2e6a32 bvs 0x3b8242 <error_g0017+0x10ee6> */
/* @0x2e6a36 vldmiane r8, {s12, s13, s14, s15, s16, s17, s18, s19, s20, s21, s22, s23, s24, s25, s26, s27, s28, s29, s30, s31} */
/* @0x2e6a3a stmdble r10, {r0, r7, r9, lr} */
/* @0x2e6a3e movwlo r7, #0x3858 */
/* @0x2e6a42 .word 0x1c03f813 */
/* @0x2e6a46 b 0x12e724e <b2_toiTime+0xb8ddaa> */
/* @0x2e6a4a .word 0xf8134001 */
/* @0x2e6a4e movwmi r1, #0x8c01 */
/* @0x2e6a52 andhs lr, r0, r0 */
/* @0x2e6a56 .word 0x47706213 */
/* @0x2e6a5a bvs 0x3b826a <error_g0017+0x10f0e> */
/* @0x2e6a5e vldmiane r8, {s13, s14, s15, s16, s17, s18, s19, s20, s21, s22, s23, s24, s25, s26, s27, s28, s29, s30, s31} */
/* @0x2e6a62 stmdble lr, {r0, r7, r9, lr} */
/* @0x2e6a66 movwlo r7, #0x4858 */
/* @0x2e6a6a .word 0x1c04f813 */
/* @0x2e6a6e b 0x12e7a76 <b2_toiTime+0xb8e5d2> */
/* @0x2e6a72 .word 0xf8136001 */
/* @0x2e6a76 movwmi r1, #0x8c01 */
/* @0x2e6a7a .word 0x1c02f813 */
/* @0x2e6a7e andhs lr, r1, r0, asr #20 */
/* @0x2e6a82 andhs lr, r0, r0 */
/* @0x2e6a86 .word 0x47706213 */
/* @0x2e6a8a bvs 0x3b829a <error_g0017+0x10f3e> */
/* @0x2e6a8e vldmiane r8, {s13, s14, s15, s16, s17, s18, s19, s20, s21, s22, s23, s24, s25, s26, s27, s28, s29, s30, s31} */
/* @0x2e6a92 stmdble lr, {r0, r7, r9, lr} */
/* @0x2e6a96 movwlo r7, #0x4898 */
/* @0x2e6a9a .word 0x1c01f813 */
/* @0x2e6a9e b 0x12e7aa6 <b2_toiTime+0xb8e602> */
/* @0x2e6aa2 .word 0xf8136001 */
/* @0x2e6aa6 movwmi r1, #0x8c04 */
/* @0x2e6aaa .word 0x1c03f813 */
/* @0x2e6aae andhs lr, r1, r0, asr #20 */
/* @0x2e6ab2 andhs lr, r0, r0 */
/* @0x2e6ab6 .word 0x47706213 */
/* @0x2e6aba movwhs r11, #0x573 */
/* @0x2e6abe strmi r6, [r4], -r11 */
/* @0x2e6ac2 strmi r6, [sp], -r6, asr #18 */
/* @0x2e6ac6 andlo pc, r7, sp, lsl #17 */
/* @0x2e6aca stmvs r1, {r1, r2, r3, r4, r5, r8, r12, sp, pc} */
/* @0x2e6ace andeq pc, r7, #1073741827 */
/* @0x2e6ad2 ldrmi r2, [r0, r1, lsl #6]! */
/* @0x2e6ad6 .word 0xd10e2801 */
/* @0x2e6ada stmvs r3, {r0, r1, r2, sp, lr, pc} */
/* @0x2e6ade addsmi r6, r3, #4325376 */
/* @0x2e6ae2 stmdavs r2, {r0, r3, r9, r12, lr, pc} */
/* @0x2e6ae6 .word 0xf88d5cd3 */
/* @0x2e6aea stmvs r3!, {r0, r1, r2, r12, sp} */
/* @0x2e6aee muleq r7, sp, r8 */
/* @0x2e6af2 adcvs r3, r3, r1, lsl #6 */
/* @0x2e6af6 andhs lr, r0, r2 */
/* @0x2e6afa eorvs r2, r11, r5, asr r3 */
/* @0x2e6afe andlt r11, r2, r0, asr #4 */
/* @0x2e6b02 ldrblt r11, [r7, #0xd70]! */

/* ── FUNC 0x2e69df · FT_Stream_GetChar · size=20 · insn=0 */

/* ── FUNC 0x2e69f3 · FT_Stream_GetUShort · size=32 · insn=0 */

/* ── FUNC 0x2e6a13 · FT_Stream_GetUShortLE · size=32 · insn=0 */

/* ── FUNC 0x2e6a33 · FT_Stream_GetUOffset · size=40 · insn=0 */

/* ── FUNC 0x2e6a5b · FT_Stream_GetULong · size=48 · insn=0 */

/* ── FUNC 0x2e6a8b · FT_Stream_GetULongLE · size=48 · insn=0 */

/* ── FUNC 0x2e6abb · FT_Stream_ReadChar · size=74 · insn=0 */

/* ── FUNC 0x2e6b04 · anon_2e6b04 · size=1176 · insn=294 */
/* @0x2e6b04 movwhs r11, #0x5f7 */
/* @0x2e6b08 strmi r6, [sp], -r11 */
/* @0x2e6b0c strmi r6, [r4], -r3, lsl #17 */
/* @0x2e6b10 mrrcne p8, #0x4, r6, r9, c2 */
/* @0x2e6b14 andsle r4, r6, #268435465 */
/* @0x2e6b18 .word 0xb1476947 */
/* @0x2e6b1c ldrmi r10, [r9], -r1, lsl #28 */
/* @0x2e6b20 ldrtmi r2, [r2], -r2, lsl #6 */
/* @0x2e6b24 stmdahs r2, {r3, r4, r5, r7, r8, r9, r10, lr} */
/* @0x2e6b28 ldrtmi sp, [r3], -sp, lsl #2 */
/* @0x2e6b2c stmdavs r2, {r1, sp, lr, pc} */
/* @0x2e6b30 ldrdle r1, r2, [r3], -r3 */
/* @0x2e6b34 ldmdavc r11, {r3, r4, r11, r12, sp, lr} ^ */
/* @0x2e6b38 movwhs lr, #0xa43 */
/* @0x2e6b3c ldrmi r6, [r8], -r2, lsr #17 */
/* @0x2e6b40 adcvs r3, r2, r2, lsl #4 */
/* @0x2e6b44 andhs lr, r0, r2 */
/* @0x2e6b48 eorvs r2, r11, r5, asr r3 */
/* @0x2e6b4c ldcllt p0, c11, [r0, #12]! */
/* @0x2e6b50 svcmi #0xf0e92d */
/* @0x2e6b54 cdpmi p0, #0x7, c11, c2, c15, #0x4 */
/* @0x2e6b58 movwls r4, #0x2608 */
/* @0x2e6b5c ldrbtmi r4, [lr], #-1548 */
/* @0x2e6b60 sasxmi r6, r1, r6 */
/* @0x2e6b64 svcls #0x184615 */
/* @0x2e6b68 movwls r6, #0xd833 */
/* @0x2e6b6c mrc2 p7, #0x4, apsr_nzcv, c11, c15, #0x7 */
/* @0x2e6b70 andls r9, r4, r3, lsl #12 */
/* @0x2e6b74 .word 0xf0402800 */
/* @0x2e6b78 cdpge p0, #0x0, c8, c5, c9, #0x6 */
/* @0x2e6b7c andshs r4, r0, #32, #12 */
/* @0x2e6b80 .word 0xf7ff4631 */
/* @0x2e6b84 andls pc, r4, r4, lsl #30 */
/* @0x2e6b88 .word 0xf0402800 */
/* @0x2e6b8c .word 0xf89d80bf */
/* @0x2e6b90 .word 0x06081014 */
/* @0x2e6b94 andhs sp, r2, r1, lsl #10 */
/* @0x2e6b98 .word 0xf89de0b8 */
/* @0x2e6b9c .word 0xf01cc018 */
/* @0x2e6ba0 mvnsle r0, r0, lsl #31 */
/* @0x2e6ba4 mulseq r12, sp, r8 */
/* @0x2e6ba8 ldrbtle r0, [r4], #1538 */
/* @0x2e6bac mlahs r0, sp, r8, pc */
/* @0x2e6bb0 ldrbtle r0, [r0], #1555 */
/* @0x2e6bb4 mulslo r5, sp, r8 */
/* @0x2e6bb8 mulshi r7, sp, r8 */
/* @0x2e6bbc mulslt sp, sp, r8 */
/* @0x2e6bc0 .word 0xf89d041b */
/* @0x2e6bc4 b 0x13cec48 <b2_toiTime+0xc757a4> */
/* @0x2e6bc8 .word 0xf89d6101 */
/* @0x2e6bcc b 0x1332c2c <b2_toiTime+0xbd9788> */
/* @0x2e6bd0 .word 0xf89d0108 */
/* @0x2e6bd4 .word 0xf89d801b */
/* @0x2e6bd8 b 0x134ac6c <b2_toiTime+0xbf17c8> */
/* @0x2e6bdc .word 0xf89d2303 */
/* @0x2e6be0 eorsvs r1, r11, r9, lsl r0 */
/* @0x2e6be4 b 0x1327c10 <b2_toiTime+0xbce76c> */
/* @0x2e6be8 .word 0xf89d610c */
/* @0x2e6bec b 0x1356c5c <b2_toiTime+0xbfd7b8> */
/* @0x2e6bf0 .word 0xf89d0108 */
/* @0x2e6bf4 b 0x1746c74 <b2_toiTime+0xfed7d0> */
/* @0x2e6bf8 .word 0xf8cd210c */
/* @0x2e6bfc .word 0xf89d8000 */
/* @0x2e6c00 .word 0xf8cd8021 */
/* @0x2e6c04 .word 0xf89d8004 */
/* @0x2e6c08 sbcle r8, r4, r2, lsr #32 */
/* @0x2e6c0c .word 0xc000f8dd */
/* @0x2e6c10 blmi 0x5e1554 <g_SWFaavertbuff+0xe48c> */
/* @0x2e6c14 blvs 0x321548 */
/* @0x2e6c18 b 0x15b764c <b2_toiTime+0xe5e1a8> */
/* @0x2e6c1c b 0x15a984c <b2_toiTime+0xe503a8> */
/* @0x2e6c20 .word 0xf8dd2b0c */
/* @0x2e6c24 b 0x16d6c3c <b2_toiTime+0xf7d798> */
/* @0x2e6c28 b 0x12f6c60 <b2_toiTime+0xb9d7bc> */
/* @0x2e6c2c b 0x137f43c <b2_toiTime+0xc25f98> */
/* @0x2e6c30 b 0x152905c <b2_toiTime+0xdcfbb8> */
/* @0x2e6c34 ble 0x3b0c5c <error_g0017+0x9900> */
/* @0x2e6c38 andeq lr, r1, #207872 */
/* @0x2e6c3c mul r2, r3, r2 */
/* @0x2e6c40 andeq lr, r3, #200, #22 */
/* @0x2e6c44 stcle p2, c4, [r6], #580 */
/* @0x2e6c48 andmi pc, r0, #111 */
/* @0x2e6c4c andeq lr, r2, #207872 */
/* @0x2e6c50 blle 0xfeaf76c0 <b2_toiTime+0xfffffffffe39e21c> */
/* @0x2e6c54 andmi pc, r0, #111 */
/* @0x2e6c58 andeq lr, r2, #200, #22 */
/* @0x2e6c5c blle 0xfe97768c <b2_toiTime+0xfffffffffe21e1e8> */
/* @0x2e6c60 andeq lr, r11, r3, lsl #22 */
/* @0x2e6c64 andmi pc, r0, #111 */
/* @0x2e6c68 adcmi r1, r10, #73728 */
/* @0x2e6c6c bl 0x35dac0 <_ZTS7CFontGM+0x1188> */
/* @0x2e6c70 .word 0xf06f0008 */
/* @0x2e6c74 bne 0x77747c <b2_toiTime+0x1dfd8> */
/* @0x2e6c78 blle 0xfe5f7728 <b2_toiTime+0xfffffffffde9e284> */
/* @0x2e6c7c stmdavs r2!, {r0, r1, r3, r5, r10, lr} ^ */
/* @0x2e6c80 ldrmi r4, [r3, #0x49b] */
/* @0x2e6c84 strmi sp, [sp], #-2183 */
/* @0x2e6c88 ldrmi r4, [r0, #0x4a8] */
/* @0x2e6c8c eorsvs sp, r11, r3, lsl #17 */
/* @0x2e6c90 strtmi r4, [r9], -r0, lsr #12 */
/* @0x2e6c94 mcr2 p7, #0x0, pc, c7, c15, #0x7 */
/* @0x2e6c98 stmdahs r0, {r2, r12, pc} */
/* @0x2e6c9c svcge #0x9d136 */
/* @0x2e6ca0 mlalo r3, sp, r8, pc */
/* @0x2e6ca4 andshs r4, r0, #32, #12 */
/* @0x2e6ca8 movwlo r4, #0x1639 */
/* @0x2e6cac eorslo pc, r3, sp, lsl #17 */
/* @0x2e6cb0 mcr2 p7, #0x3, pc, c13, c15, #0x7 */
/* @0x2e6cb4 bllt 0x150accc <b2_toiTime+0xdb1828> */
/* @0x2e6cb8 ldrmi r2, [r10], -r1, lsl #6 */
/* @0x2e6cbc .word 0xf8165c39 */
/* @0x2e6cc0 andlo r12, r1, r0 */
/* @0x2e6cc4 svclt #0x182900 */
/* @0x2e6cc8 strmi r2, [r12, #0x200] */
/* @0x2e6ccc movwhs r11, #0xf18 */
/* @0x2e6cd0 mvnsle r2, r0, lsl r8 */
/* @0x2e6cd4 blhs 0x315124 <FT_Bitmap_Embolden+0x2de> */
/* @0x2e6cd8 svcge #0x5df43f */
/* @0x2e6cdc strtmi r2, [r0], -r8, lsl #2 */
/* @0x2e6ce0 mcr2 p7, #0x1, pc, c6, c15, #0x7 */
/* @0x2e6ce4 .word 0xf841a90e */
/* @0x2e6ce8 strtmi r0, [r0], -r8, lsr #26 */
/* @0x2e6cec .word 0xff0af7ff */
/* @0x2e6cf0 stmdals r4, {r0, r9, r12, sp, pc} */
/* @0x2e6cf4 stmdbhs r0, {r4, r6, r8, r11, r12, sp, pc} */
/* @0x2e6cf8 svcge #0x4df6ff */
/* @0x2e6cfc strtmi r4, [r0], -sp, lsl #8 */
/* @0x2e6d00 .word 0xf7ff4629 */
/* @0x2e6d04 stmdblt r8, {r4, r6, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2e6d08 andsvs r9, sp, r2, lsl #22 */
/* @0x2e6d0c bls 0x64d120 <g_SWFaavertbuff+0x7a058> */
/* @0x2e6d10 addsmi r6, r10, #720896 */
/* @0x2e6d14 .word 0xf5cfd001 */
/* @0x2e6d18 andlt lr, pc, lr, asr r12 */
/* @0x2e6d1c svchi #0xf0e8bd */
/* @0x2e6d20 ldrsheq r6, [r0], -r6 */
/* @0x2e6d24 movwhs r11, #0x5f7 */
/* @0x2e6d28 strmi r6, [sp], -r11 */
/* @0x2e6d2c strmi r6, [r4], -r3, lsl #17 */
/* @0x2e6d30 mrrcne p8, #0x4, r6, r9, c2 */
/* @0x2e6d34 andsle r4, r6, #268435465 */
/* @0x2e6d38 .word 0xb1476947 */
/* @0x2e6d3c ldrmi r10, [r9], -r1, lsl #28 */
/* @0x2e6d40 ldrtmi r2, [r2], -r2, lsl #6 */
/* @0x2e6d44 stmdahs r2, {r3, r4, r5, r7, r8, r9, r10, lr} */
/* @0x2e6d48 ldrtmi sp, [r3], -sp, lsl #2 */
/* @0x2e6d4c stmdavs r2, {r1, sp, lr, pc} */
/* @0x2e6d50 ldrdle r1, r2, [r3], -r3 */
/* @0x2e6d54 ldmdavc r11, {r3, r4, r6, r11, r12, sp, lr} */
/* @0x2e6d58 movwhs lr, #0xa43 */
/* @0x2e6d5c ldrmi r6, [r8], -r2, lsr #17 */
/* @0x2e6d60 adcvs r3, r2, r2, lsl #4 */
/* @0x2e6d64 andhs lr, r0, r2 */
/* @0x2e6d68 eorvs r2, r11, r5, asr r3 */
/* @0x2e6d6c ldcllt p0, c11, [r0, #12]! */
/* @0x2e6d70 movwhs r11, #0x5f7 */
/* @0x2e6d74 strmi r6, [sp], -r11 */
/* @0x2e6d78 strmi r6, [r4], -r3, lsl #17 */
/* @0x2e6d7c ldcne p8, c6, [r9], {66} */
/* @0x2e6d80 andsle r4, r10, #268435465 */
/* @0x2e6d84 .word 0xb1476947 */
/* @0x2e6d88 ldrmi r10, [r9], -r1, lsl #28 */
/* @0x2e6d8c ldrtmi r2, [r2], -r3, lsl #6 */
/* @0x2e6d90 stmdahs r3, {r3, r4, r5, r7, r8, r9, r10, lr} */
/* @0x2e6d94 shadd16mi sp, r2, r1 */
/* @0x2e6d98 stmdavs r2, {r1, sp, lr, pc} */
/* @0x2e6d9c ldrdle r1, r2, [r7], -r2 */
/* @0x2e6da0 ldmdavc r3, {r4, r6, r11, r12, sp, lr} */
/* @0x2e6da4 b 0x12e75ac <b2_toiTime+0xb8e108> */
/* @0x2e6da8 ldmvc r3, {r0, r1, lr} */
/* @0x2e6dac andeq lr, r3, #64, #20 */
/* @0x2e6db0 ldrmi r6, [r0], -r3, lsr #17 */
/* @0x2e6db4 adcvs r3, r3, r3, lsl #6 */
/* @0x2e6db8 andhs lr, r0, r2 */
/* @0x2e6dbc eorvs r2, r11, r5, asr r3 */
/* @0x2e6dc0 ldcllt p0, c11, [r0, #12]! */
/* @0x2e6dc4 movwhs r11, #0x5f7 */
/* @0x2e6dc8 strmi r6, [sp], -r11 */
/* @0x2e6dcc strmi r6, [r4], -r3, lsl #17 */
/* @0x2e6dd0 ldclne p8, c6, [r9], {66} */
/* @0x2e6dd4 andsle r4, r12, #268435465 */
/* @0x2e6dd8 .word 0xb1476947 */
/* @0x2e6ddc ldrmi r10, [r9], -r1, lsl #28 */
/* @0x2e6de0 ldrtmi r2, [r2], -r4, lsl #6 */
/* @0x2e6de4 stmdahs r4, {r3, r4, r5, r7, r8, r9, r10, lr} */
/* @0x2e6de8 shadd16mi sp, r2, r3 */
/* @0x2e6dec stmdavs r2, {r1, sp, lr, pc} */
/* @0x2e6df0 ldrdle r1, r2, [r9], -r2 */
/* @0x2e6df4 ldmdavc r3, {r4, r6, r11, r12, sp, lr} */
/* @0x2e6df8 b 0x12e7e00 <b2_toiTime+0xb8e95c> */
/* @0x2e6dfc ldmvc r3, {r0, r1, sp, lr} ^ */
/* @0x2e6e00 tstmi r8, #9568256 */
/* @0x2e6e04 andhs lr, r2, #64, #20 */
/* @0x2e6e08 ldrmi r6, [r0], -r3, lsr #17 */
/* @0x2e6e0c adcvs r3, r3, r4, lsl #6 */
/* @0x2e6e10 andhs lr, r0, r2 */
/* @0x2e6e14 eorvs r2, r11, r5, asr r3 */
/* @0x2e6e18 ldcllt p0, c11, [r0, #12]! */
/* @0x2e6e1c .word 0x43f7e92d */
/* @0x2e6e20 strmi r10, [lr], -r1, lsl #26 */
/* @0x2e6e24 strtmi r4, [r9], -r4, lsl #12 */
/* @0x2e6e28 .word 0xf7ff4690 */
/* @0x2e6e2c blls 0x366d60 <_ZTS12CDS_Priority+0x8db8> */
/* @0x2e6e30 teqle r12, r0, lsl #22 */
/* @0x2e6e34 strhle r4, [r1], -r0 */
/* @0x2e6e38 eors r2, r9, r2 */
/* @0x2e6e3c strtmi r4, [r9], -r0, lsr #12 */
/* @0x2e6e40 .word 0xffc0f7ff */
/* @0x2e6e44 stmdahs r0, {r0, r11, r12, pc} */
/* @0x2e6e48 qasxmi sp, r0, r2 */
/* @0x2e6e4c .word 0xf7ff2110 */
/* @0x2e6e50 andls pc, r1, pc, ror #26 */
/* @0x2e6e54 strtmi r11, [r0], -r0, ror #22 */
/* @0x2e6e58 .word 0xf7ff4629 */
/* @0x2e6e5c mcrls p14, #0x0, pc, c1, c3, #0x2 */
/* @0x2e6e60 bllt 0x878684 <b2_toiTime+0x11f1e0> */
/* @0x2e6e64 rscle r2, r7, r0, lsl #16 */
/* @0x2e6e68 ble 0xffc37968 <b2_toiTime+0xffffffffff4de4c4> */
/* @0x2e6e6c strtmi r4, [r9], -r0, lsr #12 */
/* @0x2e6e70 .word 0xffa8f7ff */
/* @0x2e6e74 ldmiblt r3, {r0, r8, r9, r11, r12, pc} ^ */
/* @0x2e6e78 strtmi r2, [r0], -r2, lsl #16 */
/* @0x2e6e7c strtmi sp, [r9], -lr, lsl #2 */
/* @0x2e6e80 .word 0xffa0f7ff */
/* @0x2e6e84 strmi r9, [r1], r1, lsl #22 */
/* @0x2e6e88 strtmi r11, [r0], -r11, ror #18 */
/* @0x2e6e8c .word 0xf7ff4629 */
/* @0x2e6e90 blls 0x366cfc <_ZTS12CDS_Priority+0x8d54> */
/* @0x2e6e94 .word 0xf8c8b93b */
/* @0x2e6e98 and r9, r8, r0 */
/* @0x2e6e9c .word 0xf7ff2108 */
/* @0x2e6ea0 andls pc, r1, r7, asr #26 */
/* @0x2e6ea4 strlo r11, [r1], -r0, lsr #18 */
/* @0x2e6ea8 .word 0x4630e7de */
/* @0x2e6eac ldrmi lr, [r8], -r0 */
/* @0x2e6eb0 pop {r0, r1, r12, sp, pc} */
/* @0x2e6eb4 strdeq r8, r9, [r0], -r0 */
/* @0x2e6eb8 bls 0x2eeec0 <FT_Done_Memory+0x524c> */
/* @0x2e6ebc tstlt r9, r8, lsl r0 */
/* @0x2e6ec0 stmdbmi r2, {r3, r9, r10, lr} */
/* @0x2e6ec4 svclt #0xaaf7ff */
/* @0x2e6ec8 .word 0x47702051 */
/* @0x2e6ecc andeq r1, r5, r0, lsl #12 */
/* @0x2e6ed0 bls 0x2eeed8 <FT_Done_Memory+0x5264> */
/* @0x2e6ed4 tstlt r9, r8, lsl r0 */
/* @0x2e6ed8 stmdbmi r2, {r3, r9, r10, lr} */
/* @0x2e6edc svclt #0x9ef7ff */
/* @0x2e6ee0 .word 0x47702051 */
/* @0x2e6ee4 andeq r1, r5, r7, lsl #12 */
/* @0x2e6ee8 movwhs r11, #0x5f7 */
/* @0x2e6eec strmi r6, [sp], -r11 */
/* @0x2e6ef0 strmi r6, [r4], -r3, lsl #17 */
/* @0x2e6ef4 ldclne p8, c6, [r9], {66} */
/* @0x2e6ef8 andsle r4, r12, #268435465 */
/* @0x2e6efc .word 0xb1476947 */
/* @0x2e6f00 ldrmi r10, [r9], -r1, lsl #28 */
/* @0x2e6f04 ldrtmi r2, [r2], -r4, lsl #6 */
/* @0x2e6f08 stmdahs r4, {r3, r4, r5, r7, r8, r9, r10, lr} */
/* @0x2e6f0c shadd16mi sp, r2, r3 */
/* @0x2e6f10 stmdavs r2, {r1, sp, lr, pc} */
/* @0x2e6f14 ldrdle r1, r2, [r9], -r2 */
/* @0x2e6f18 ldmvc r3, {r4, r7, r11, r12, sp, lr} ^ */
/* @0x2e6f1c b 0x12e7f24 <b2_toiTime+0xb8ea80> */
/* @0x2e6f20 ldmdavc r3, {r0, r1, sp, lr} */
/* @0x2e6f24 tstmi r8, #5373952 */
/* @0x2e6f28 andhs lr, r2, #64, #20 */
/* @0x2e6f2c ldrmi r6, [r0], -r3, lsr #17 */
/* @0x2e6f30 adcvs r3, r3, r4, lsl #6 */
/* @0x2e6f34 andhs lr, r0, r2 */
/* @0x2e6f38 eorvs r2, r11, r5, asr r3 */
/* @0x2e6f3c ldcllt p0, c11, [r0, #12]! */
/* @0x2e6f40 stmdblt r0, {r0, r1, r4, r8, r10, r12, sp, pc} */
/* @0x2e6f44 stm sp, {r0, r3, r6, r8, r12, sp, pc} */
/* @0x2e6f48 strbtmi r0, [r8], -r3 */
/* @0x2e6f4c mcr2 p7, #0x2, pc, c6, c13, #0x7 */
/* @0x2e6f50 .word 0xf7fd4668 */
/* @0x2e6f54 stmdals r1, {r0, r4, r5, r6, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2e6f58 strmi lr, [r8], -r0 */
/* @0x2e6f5c ldclt p0, c11, [r0, #-8] */
/* @0x2e6f60 .word 0x4604b510 */
/* @0x2e6f64 bmi 0x4d350c <SrcVerts+0x30550> */
/* @0x2e6f68 stm r0, {r8, r9, sp} */
/* @0x2e6f6c .word 0xf7fd000c */
/* @0x2e6f70 stmdavs r3!, {r0, r3, r5, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2e6f74 andsne r3, r11, #128, #6 */
/* @0x2e6f78 stmdavs r3!, {r0, r1, r5, sp, lr} ^ */
/* @0x2e6f7c andsne r3, r11, #128, #6 */
/* @0x2e6f80 ldclt p0, c6, [r0, #-396] */
/* @0x2e6f84 sbcseq sp, r11, r11, asr r9 */
/* @0x2e6f88 strmi r11, [r1], -r7, lsl #10 */
/* @0x2e6f8c .word 0xf7ff4668 */
/* @0x2e6f90 stmdals r0, {r0, r1, r2, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e6f94 .word 0xf85db003 */
/* @0x2e6f98 strlt pc, [r7, #-0xb04] */

/* ── FUNC 0x2e6b05 · FT_Stream_ReadUShort · size=76 · insn=0 */

/* ── FUNC 0x2e6b51 · FT_Raccess_Get_HeaderInfo · size=468 · insn=0 */
