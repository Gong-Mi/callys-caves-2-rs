/* libyoyo.so 覆盖卡组 0252
 * 函数 0x2a58e9..0x2a6037，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2a58e9 · zip_file_error_get · size=6 · insn=0 */

/* ── FUNC 0x2a58ee · anon_2a58ee · size=312 · insn=78 */
/* @0x2a58ee eorshs r11, r12, #240, #10 */
/* @0x2a58f2 addslt r6, r3, r3, lsl #20 */
/* @0x2a58f6 strmi r6, [r4], -r5, asr #16 */
/* @0x2a58fa streq pc, [r12, -r0, lsl #2] */
/* @0x2a58fe blx 0x33f974 */
/* @0x2a5902 blvs 0xfe631d0e <b2_toiTime+0xfffffffffded886a> */
/* @0x2a5906 strtmi r11, [r8], -sp, asr #3 */
/* @0x2a590a andhs r4, r0, #51380224 */
/* @0x2a590e b 0xffb6315a <b2_toiTime+0xffffffffff409cb6> */
/* @0x2a5912 .word 0xb1404605 */
/* @0x2a5916 ldmdb r0!, {r0, r4, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2a591a stmdavs r2, {r2, r8, sp} */
/* @0x2a591e .word 0xf7fe4638 */
/* @0x2a5922 andhs pc, r0, r10, lsl sp */
/* @0x2a5926 movwhs lr, #0x1028 */
/* @0x2a592a stm sp, {r0, r1, r11, sp, pc} */
/* @0x2a592e strtmi r0, [r10], -r8, lsl #1 */
/* @0x2a5932 strtmi r6, [r11], -r1, ror #16 */
/* @0x2a5936 blx 0xff9a3936 <b2_toiTime+0xffffffffff24a492> */
/* @0x2a593a stmvs r0, {r1, r4, sp, lr, pc} */
/* @0x2a593e ldrtmi r4, [r2], -r9, lsr #12 */
/* @0x2a5942 ldmdbvs r11, {r0, r1, r11, sp, lr} */
/* @0x2a5946 stmvs r1!, {r3, r4, r7, r8, r9, r10, lr} */
/* @0x2a594a stmvs r10, {r0, r1, r11, sp, pc} ^ */
/* @0x2a594e ldrmi r6, [r3], #-2507 */
/* @0x2a5952 movwls r10, #0x2a02 */
/* @0x2a5956 stm sp, {r0, r8, r9, sp} */
/* @0x2a595a strtmi r0, [r11], -r8, lsl #1 */
/* @0x2a595e blx 0xff7a3960 <b2_toiTime+0xffffffffff04a4bc> */
/* @0x2a5962 rfeia sp! */
/* @0x2a5966 stmdage r3, {r3, r5, r12, lr} */
/* @0x2a596a ldrhtlo pc, [r0], -sp */
/* @0x2a596e ldrmi r3, [sp], #-1310 */
/* @0x2a5972 .word 0xf7fe4435 */
/* @0x2a5976 strtmi pc, [r8], -pc, lsr #18 */
/* @0x2a597a ldcllt p0, c11, [r0, #76]! */
/* @0x2a597e .word 0x4605b538 */
/* @0x2a5982 .word 0xf6102044 */
/* @0x2a5986 .word 0x4604edde */
/* @0x2a598a strtmi r11, [r8], -r8, lsr #18 */
/* @0x2a598e strtmi r2, [r2], -lr, lsl #2 */
/* @0x2a5992 stc2l p7, c15, [r1], #1016 */
/* @0x2a5996 strhs lr, [r0, #-0x16] */
/* @0x2a599a .word 0xf840300c */
/* @0x2a599e .word 0xf8405c0c */
/* @0x2a59a2 .word 0xf8405c08 */
/* @0x2a59a6 .word 0xf7fe5c04 */
/* @0x2a59aa .word 0xf04ffcd1 */
/* @0x2a59ae eorvs r3, r5, #-67108861 */
/* @0x2a59b2 adcvs r6, r3, #1342177286 */
/* @0x2a59b6 rscvs r6, r5, #-1811939328 */
/* @0x2a59ba .word 0x63e56365 */
/* @0x2a59be strtvs r6, [r5], #-933 */
/* @0x2a59c2 .word 0x61a561e5 */
/* @0x2a59c6 ldclt p6, c4, [r8, #-128]! */
/* @0x2a59ca .word 0x460eb5f8 */
/* @0x2a59ce .word 0x46054617 */
/* @0x2a59d2 andhs r11, r8, r8, ror r1 */
/* @0x2a59d6 ldc p6, c15, [r6, #64]! */
/* @0x2a59da ldmdblt r0!, {r2, r9, r10, lr} */
/* @0x2a59de andeq pc, r12, r5, lsl #2 */
/* @0x2a59e2 strtmi r2, [r2], -lr, lsl #2 */
/* @0x2a59e6 ldc2 p7, c15, [r7], #1016 */
/* @0x2a59ea stm r0, {r0, sp, lr, pc} */
/* @0x2a59ee strtmi r0, [r0], -r0, asr #1 */
/* @0x2a59f2 ldcllt p13, c11, [r8, #992]! */
/* @0x2a59f6 .word 0x4604b538 */
/* @0x2a59fa cmplt r3, r3, asr #16 */
/* @0x2a59fe ldmdavs sp, {r8, sp} */
/* @0x2a5a02 .word 0x460a6858 */
/* @0x2a5a06 strmi r2, [r8, r5, lsl #6]! */
/* @0x2a5a0a .word 0xf6106860 */
/* @0x2a5a0e movwhs lr, #0xda6 */
/* @0x2a5a12 stmvs r3!, {r0, r1, r5, r6, sp, lr} */
/* @0x2a5a16 svclt #0x142b00 */
/* @0x2a5a1a movwhs r2, #0x304 */
/* @0x2a5a1e ldclt p0, c6, [r8, #-140]! */
/* @0x2a5a22 ldrlt r0, [r8, #-0x0]! */

/* ── FUNC 0x2a58ef · _zip_file_get_offset(zip*, int) · size=144 · insn=0 */

/* ── FUNC 0x2a597f · _zip_new(zip_error*) · size=76 · insn=0 */

/* ── FUNC 0x2a59cb · zip_source_function · size=44 · insn=0 */

/* ── FUNC 0x2a59f7 · _zip_unchange_data(zip_entry*) · size=44 · insn=0 */

/* ── FUNC 0x2a5a24 · anon_2a5a24 · size=1180 · insn=295 */
/* @0x2a5a24 .word 0x4605b538 */
/* @0x2a5a28 stmdbhs r0, {r5, r6, r8, r12, sp, pc} */
/* @0x2a5a2c stmdbhs r8, {r0, r1, r2, r8, r9, r11, r12, lr, pc} */
/* @0x2a5a30 stmdble r5, {r2, r3, r9, r10, lr} */
/* @0x2a5a34 ldrbtmi r4, [r9], #-2308 */
/* @0x2a5a38 ldc2l p0, c15, [r8], #0 */
/* @0x2a5a3c strhs lr, [r0], #-0 */
/* @0x2a5a40 mvnsmi pc, r5, lsl #17 */
/* @0x2a5a44 svclt #0xbd38 */
/* @0x2a5a48 andeq r6, lr, r4, ror #15 */
/* @0x2a5a4c .word 0x460bb57f */
/* @0x2a5a50 .word 0x46064c13 */
/* @0x2a5a54 bhs 0x4d0e60 <SrcVerts+0x2dea4> */
/* @0x2a5a58 stmdavs r4!, {r2, r3, r4, r5, r6, r10, lr} */
/* @0x2a5a5c .word 0x91036821 */
/* @0x2a5a60 ldrbtmi r4, [r9], #-2320 */
/* @0x2a5a64 stmdavs r9, {r3, r11, sp, lr} ^ */
/* @0x2a5a68 stmdale r1, {r0, r1, r8, r10, lr, pc} */
/* @0x2a5a6c and r11, sp, r10, lsl #18 */
/* @0x2a5a70 blhs 0x46e298 <g_RomDisk+0x76a78> */
/* @0x2a5a74 ldmne r1, {r1, r3, r11, r12, lr, pc} ^ */
/* @0x2a5a78 stmdbhs r8, {r4, r5, r6, r7, r11, r12} */
/* @0x2a5a7c svclt #0x88a901 */
/* @0x2a5a80 andeq pc, r8, #-1073741776 */
/* @0x2a5a84 .word 0xf6114419 */
/* @0x2a5a88 ldrd lr, pc, [r1], -r12 */
/* @0x2a5a8c rscslo pc, pc, pc, asr #32 */
/* @0x2a5a90 stmdavs r3!, {r0, r1, r9, r11, r12, pc} */
/* @0x2a5a94 mulle r1, r10, r2 */
/* @0x2a5a98 ldc p6, c15, [r12, #64] */
/* @0x2a5a9c ldcllt p0, c11, [r0, #-16]! */
/* @0x2a5aa0 ldrsheq r7, [r4], -r12 */
/* @0x2a5aa4 andeq r9, lr, lr, asr lr */
/* @0x2a5aa8 .word 0x460eb5f8 */
/* @0x2a5aac .word 0x46044617 */
/* @0x2a5ab0 .word 0xf8d0b168 */
/* @0x2a5ab4 sasxmi r5, r1, r0 */
/* @0x2a5ab8 rscslo pc, pc, pc, asr #32 */
/* @0x2a5abc stm r4, {r0, r1, r4, r5, r6, r12, sp, lr, pc} ^ */
/* @0x2a5ac0 stmdble r6, {r1, r2, r7, r9, lr} */
/* @0x2a5ac4 strtmi r4, [r0], -r9, lsl #18 */
/* @0x2a5ac8 .word 0xf0004479 */
/* @0x2a5acc .word 0x2000fcd3 */
/* @0x2a5ad0 .word 0xf445bdf8 */
/* @0x2a5ad4 strtmi r1, [r0], -r0, lsl #7 */
/* @0x2a5ad8 teqlo r0, r4, asr #17 */
/* @0x2a5adc .word 0xf107fb06 */
/* @0x2a5ae0 .word 0xf8def001 */
/* @0x2a5ae4 teqpl r0, r4, asr #17 */
/* @0x2a5ae8 svclt #0xbdf8 */
/* @0x2a5aec andeq r6, lr, r3, ror r7 */
/* @0x2a5af0 stmdblt r4, {r0, r12, sp, lr, pc} */
/* @0x2a5af4 .word 0x4604b510 */
/* @0x2a5af8 strmi r2, [r1], -r0 */
/* @0x2a5afc .word 0xf6114602 */
/* @0x2a5b00 .word 0xf8c4e9d2 */
/* @0x2a5b04 ldclt p1, c0, [r0, #-848] */
/* @0x2a5b08 .word 0x4604b510 */
/* @0x2a5b0c .word 0x31e0f890 */
/* @0x2a5b10 svceq #0x20f013 */
/* @0x2a5b14 ldrsblo pc, [r0, -r0]! */
/* @0x2a5b18 vst4.8 {d13, d14, d15, d16}, [r3], r5 */
/* @0x2a5b1c .word 0xf5b37340 */
/* @0x2a5b20 .word 0xd1027f40 */
/* @0x2a5b24 ldreq r11, [r11, #-0xd10] */
/* @0x2a5b28 .word 0xf8d4d405 */
/* @0x2a5b2c .word 0xf61101d4 */
/* @0x2a5b30 .word 0xf8c4e9ba */
/* @0x2a5b34 ldclt p1, c0, [r0, #-848] */
/* @0x2a5b38 .word 0x4604b510 */
/* @0x2a5b3c orrlt r6, r0, r0, lsl #16 */
/* @0x2a5b40 svcvc #0x90f5b1 */
/* @0x2a5b44 .word 0xf001d206 */
/* @0x2a5b48 mulhs r2, pc, r8 */
/* @0x2a5b4c .word 0xf883f001 */
/* @0x2a5b50 teqlt r0, r0, lsr #32 */
/* @0x2a5b54 vst4.8 {d18, d20, d22, d24}, [pc], r0 */
/* @0x2a5b58 pop {r4, r7, r9, r12, sp, lr} */
/* @0x2a5b5c .word 0xf0754010 */
/* @0x2a5b60 ldclt p15, c11, [r0, #-724] */
/* @0x2a5b64 strmi r11, [r3], -r7, lsl #10 */
/* @0x2a5b68 andhs r11, r2, r8, ror r1 */
/* @0x2a5b6c rscne pc, r12, #13828096 */
/* @0x2a5b70 rschs pc, r8, #13828096 */
/* @0x2a5b74 .word 0xf845f001 */
/* @0x2a5b78 .word 0xb1209001 */
/* @0x2a5b7c vst2.8 {d26, d27}, [pc], r1 */
/* @0x2a5b80 .word 0xf7ff7190 */
/* @0x2a5b84 stmdals r1, {r0, r3, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2a5b88 strdlt lr, pc, [r3], -pc */
/* @0x2a5b8c blx 0x3e3d0a <error_g0017+0x3c9ae> */
/* @0x2a5b90 .word 0xb191b198 */
/* @0x2a5b94 .word 0xd1032a01 */
/* @0x2a5b98 ldrsbths pc, [r8], r1 */
/* @0x2a5b9c and r4, r5, r3, lsl r3 */
/* @0x2a5ba0 .word 0xd1062a02 */
/* @0x2a5ba4 ldrsbths pc, [r8], r1 */
/* @0x2a5ba8 movweq lr, #0x3a22 */
/* @0x2a5bac adcslo pc, r8, r1, asr #17 */
/* @0x2a5bb0 stmdbmi r2, {r4, r5, r6, r8, r9, r10, lr} */
/* @0x2a5bb4 .word 0xf0004479 */
/* @0x2a5bb8 .word 0x4770bc5d */
/* @0x2a5bbc andeq r6, lr, r10, lsr #13 */
/* @0x2a5bc0 .word 0x43f8e92d */
/* @0x2a5bc4 ldrmi r4, [r6], -r12, lsl #12 */
/* @0x2a5bc8 .word 0x4605461f */
/* @0x2a5bcc .word 0xf0002800 */
/* @0x2a5bd0 stmdbhs r0, {r2, r4, r5, r6, r8, pc} */
/* @0x2a5bd4 cmnhi r1, r0 */
/* @0x2a5bd8 ldrsbtlo pc, [r8], r1 */
/* @0x2a5bdc orrmi pc, r0, #50331648 */
/* @0x2a5be0 eorle r4, r7, r3, lsl r2 */
/* @0x2a5be4 .word 0xd1021c7b */
/* @0x2a5be8 stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2a5bec blvs 0xfe59dc30 <b2_toiTime+0xfffffffffde4478c> */
/* @0x2a5bf0 .word 0xf04fb303 */
/* @0x2a5bf4 blx 0x4a7c6e <SrcVerts+0x4cb2> */
/* @0x2a5bf8 strbmi pc, [r3], #-2055 */
/* @0x2a5bfc biclt r6, r9, r9, asr r8 */
/* @0x2a5c00 .word 0xf87cf001 */
/* @0x2a5c04 andhs r6, r0, #166912 */
/* @0x2a5c08 subsvs r4, r10, r3, asr #8 */
/* @0x2a5c0c blvs 0xb9dc5c <b2_toiTime+0x4447b8> */
/* @0x2a5c10 ldrmi r4, [r8, #0x628] */
/* @0x2a5c14 strbmi sp, [r3], -r8, lsl #20 */
/* @0x2a5c18 .word 0xf44f4621 */
/* @0x2a5c1c cpsie i */
/* @0x2a5c20 .word 0xf7ff0801 */
/* @0x2a5c24 ldrb pc, [r2, sp, asr #31]! */
/* @0x2a5c28 .word 0xf0016ba1 */
/* @0x2a5c2c movwhs pc, #0x867 */
/* @0x2a5c30 .word 0x632363a3 */
/* @0x2a5c34 ldrsbtlo pc, [r8], r4 */
/* @0x2a5c38 movwpl pc, #0x403 */
/* @0x2a5c3c andle r4, r9, r3, lsr r2 */
/* @0x2a5c40 stclvs p6, c4, [r1], #160 */
/* @0x2a5c44 .word 0xf85af001 */
/* @0x2a5c48 strbtvs r2, [r3], #768 */
/* @0x2a5c4c .word 0xf02368a3 */
/* @0x2a5c50 adcvs r0, r3, r0, lsl r3 */
/* @0x2a5c54 ldrsbtlo pc, [r8], r4 */
/* @0x2a5c58 ldrbeq r4, [r8, #0x33] */
/* @0x2a5c5c stmvs r2!, {r0, r1, r8, r10, r12, lr, pc} */
/* @0x2a5c60 addmi pc, r0, #570425344 */
/* @0x2a5c64 ldreq r6, [r9], -r2, lsr #1 */
/* @0x2a5c68 qasxmi sp, r8, r1 */
/* @0x2a5c6c .word 0x10a0f8d4 */
/* @0x2a5c70 .word 0xf844f001 */
/* @0x2a5c74 .word 0xf8d44628 */
/* @0x2a5c78 .word 0xf00110ac */
/* @0x2a5c7c .word 0xf8d4f83f */
/* @0x2a5c80 movwhs r2, #0xb0 */
/* @0x2a5c84 adclo pc, r0, r4, asr #17 */
/* @0x2a5c88 adclo pc, r12, r4, asr #17 */
/* @0x2a5c8c .word 0x4698b1da */
/* @0x2a5c90 .word 0xf8944699 */
/* @0x2a5c94 ldrmi r3, [r8, #0xb5] */
/* @0x2a5c98 .word 0xf8d4da0d */
/* @0x2a5c9c .word 0x462830b0 */
/* @0x2a5ca0 eorne pc, r8, r3, asr r8 */
/* @0x2a5ca4 .word 0xf82af001 */
/* @0x2a5ca8 ldrsbtlo pc, [r0], r4 */
/* @0x2a5cac eorls pc, r8, r3, asr #16 */
/* @0x2a5cb0 stmdaeq r1, {r3, r8, r12, sp, lr, pc} */
/* @0x2a5cb4 strtmi lr, [r8], -sp, ror #15 */
/* @0x2a5cb8 ldrsbtne pc, [r0], r4 */
/* @0x2a5cbc .word 0xf81ef001 */
/* @0x2a5cc0 .word 0xf8c42300 */
/* @0x2a5cc4 stmvs r3!, {r4, r5, r7, r12, sp} */
/* @0x2a5cc8 orrvs pc, r0, #587202560 */
/* @0x2a5ccc .word 0xf8d460a3 */
/* @0x2a5cd0 .word 0xf00330b8 */
/* @0x2a5cd4 eorsmi r0, r3, #16, #6 */
/* @0x2a5cd8 qadd16mi sp, r8, r2 */
/* @0x2a5cdc .word 0x10c4f8d4 */
/* @0x2a5ce0 .word 0xf80cf001 */
/* @0x2a5ce4 .word 0xf8d44628 */
/* @0x2a5ce8 .word 0xf00110c8 */
/* @0x2a5cec movwhs pc, #0x807 */
/* @0x2a5cf0 sbclo pc, r4, r4, asr #17 */
/* @0x2a5cf4 sbclo pc, r8, r4, asr #17 */
/* @0x2a5cf8 vld2.32 {d6, d7}, [r3:128], r3 */
/* @0x2a5cfc adcvs r5, r3, r0, lsl #7 */
/* @0x2a5d00 ldrsbtlo pc, [r8], r4 */
/* @0x2a5d04 wfieq */
/* @0x2a5d08 eorsle r4, r11, r3, lsr r2 */
/* @0x2a5d0c andsle r1, r10, r10, ror r12 */
/* @0x2a5d10 ldrsblo pc, [r4], #132 */
/* @0x2a5d14 b 0x1692be8 <b2_toiTime+0xf39744> */
/* @0x2a5d18 strtmi r1, [r8], -r7, lsl #16 */
/* @0x2a5d1c andne pc, r8, r3, asr r8 */
/* @0x2a5d20 .word 0xffecf000 */
/* @0x2a5d24 ldrsblo pc, [r4], #132 */
/* @0x2a5d28 strbmi r4, [r3], #-1576 */
/* @0x2a5d2c .word 0xf0006899 */
/* @0x2a5d30 .word 0xf8d4ffe5 */
/* @0x2a5d34 movwhs r2, #0xd4 */
/* @0x2a5d38 andlo pc, r8, r2, asr #16 */
/* @0x2a5d3c ldrsbhs pc, [r4], #132 */
/* @0x2a5d40 addsvs r4, r3, r2, asr #8 */
/* @0x2a5d44 .word 0xf8d4e01e */
/* @0x2a5d48 ldrsblt r3, [r11, r8]! */
/* @0x2a5d4c stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2a5d50 ldrsblo pc, [r8], #132 */
/* @0x2a5d54 ldrmi r4, [r8, #0x628] */
/* @0x2a5d58 strbmi sp, [r3], -r7, lsl #20 */
/* @0x2a5d5c eorhs r4, r0, #34603008 */
/* @0x2a5d60 stmdaeq r1, {r3, r8, r12, sp, lr, pc} */
/* @0x2a5d64 .word 0xff2cf7ff */
/* @0x2a5d68 .word 0xf8d4e7f2 */
/* @0x2a5d6c .word 0xf00010d4 */
/* @0x2a5d70 movwhs pc, #0xfc5 */
/* @0x2a5d74 sbcslo pc, r4, r4, asr #17 */
/* @0x2a5d78 sbcslo pc, r8, r4, asr #17 */
/* @0x2a5d7c vld2.32 {d6, d7}, [r3:128], r3 */
/* @0x2a5d80 adcvs r5, r3, r0, lsl #6 */
/* @0x2a5d84 tstne r12, #13959168 */
/* @0x2a5d88 strtmi r11, [r8], -r9, lsr #2 */
/* @0x2a5d8c .word 0xffb6f000 */
/* @0x2a5d90 .word 0xf8c52300 */
/* @0x2a5d94 .word 0xf8d4331c */
/* @0x2a5d98 vst4.32 {d3, d4, d5, d6}, [r3:256], r8 */
/* @0x2a5d9c eorsmi r7, r3, #0, #6 */
/* @0x2a5da0 ldclne p0, c13, [r11], #-188 */
/* @0x2a5da4 .word 0xf8d4d011 */
/* @0x2a5da8 cmplt r3, #188 */
/* @0x2a5dac ldmdaeq r4, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2a5db0 blx 0x4b765a <SrcVerts+0x1469e> */
/* @0x2a5db4 strbmi pc, [r3], #-2055 */
/* @0x2a5db8 .word 0xf0006899 */
/* @0x2a5dbc .word 0xf8d4ff9f */
/* @0x2a5dc0 andhs r3, r0, #188 */
/* @0x2a5dc4 addsvs r4, r10, r3, asr #8 */
/* @0x2a5dc8 .word 0xf8d4e01b */
/* @0x2a5dcc biclt r3, r3, r0, asr #1 */
/* @0x2a5dd0 stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2a5dd4 .word 0x30c0f8d4 */
/* @0x2a5dd8 ldrmi r4, [r8, #0x628] */
/* @0x2a5ddc strbmi sp, [r3], -r8, lsl #20 */
/* @0x2a5de0 .word 0xf44f4621 */
/* @0x2a5de4 .word 0xf1087200 */
/* @0x2a5de8 .word 0xf7ff0801 */
/* @0x2a5dec ldrb pc, [r1, r9, ror #29]! */
/* @0x2a5df0 ldrsbtne pc, [r12], r4 */
/* @0x2a5df4 .word 0xff82f000 */
/* @0x2a5df8 .word 0xf8c42300 */
/* @0x2a5dfc .word 0xf8c430bc */
/* @0x2a5e00 .word 0xf8d430c0 */
/* @0x2a5e04 .word 0xf00330b8 */
/* @0x2a5e08 eorsmi r0, r3, #8, #6 */
/* @0x2a5e0c strtmi sp, [r8], -r9 */
/* @0x2a5e10 .word 0xf0006fe1 */
/* @0x2a5e14 movwhs pc, #0xf73 */
/* @0x2a5e18 stmvs r3!, {r0, r1, r5, r6, r7, r8, r9, r10, sp, lr} */
/* @0x2a5e1c movteq pc, #0x23 */
/* @0x2a5e20 .word 0xf8d460a3 */
/* @0x2a5e24 vst4.32 {d3, d4, d5, d6}, [r3:256], r8 */
/* @0x2a5e28 eorsmi r5, r3, #128, #6 */
/* @0x2a5e2c strtmi sp, [r8], -r10 */
/* @0x2a5e30 .word 0xf7ff6921 */
/* @0x2a5e34 stmvs r2!, {r0, r2, r3, r4, r6, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2a5e38 .word 0x61232300 */
/* @0x2a5e3c andeq pc, r8, #34 */
/* @0x2a5e40 adcvs r8, r2, r3, lsr #5 */
/* @0x2a5e44 ldrsbtlo pc, [r8], r4 */
/* @0x2a5e48 movteq pc, #0x3 */
/* @0x2a5e4c eorle r4, r2, r3, lsr r2 */
/* @0x2a5e50 ldrsbtlo pc, [r8], #132 */
/* @0x2a5e54 .word 0xf04fb1db */
/* @0x2a5e58 strbmi r0, [r1], r0, lsl #16 */
/* @0x2a5e5c ldrmi r6, [r8, #0x863] */
/* @0x2a5e60 .word 0xf8d4da0d */
/* @0x2a5e64 qsub8mi r3, r8, r8 */
/* @0x2a5e68 eorne pc, r8, r3, asr r8 */
/* @0x2a5e6c .word 0xff46f000 */
/* @0x2a5e70 ldrsbtlo pc, [r8], #132 */
/* @0x2a5e74 eorls pc, r8, r3, asr #16 */
/* @0x2a5e78 stmdaeq r1, {r3, r8, r12, sp, lr, pc} */
/* @0x2a5e7c strtmi lr, [r8], -lr, ror #15 */
/* @0x2a5e80 ldrsbtne pc, [r8], #132 */
/* @0x2a5e84 .word 0xff3af000 */
/* @0x2a5e88 .word 0xf8c42300 */
/* @0x2a5e8c stmvs r3!, {r3, r4, r5, r6, r7, r12, sp} */
/* @0x2a5e90 movwmi pc, #0x423 */
/* @0x2a5e94 strlo r6, [r1, -r3, lsr #1] */
/* @0x2a5e98 ldrsbtlo pc, [r8], r4 */
/* @0x2a5e9c b 0xb9a2b8 <b2_toiTime+0x440e14> */
/* @0x2a5ea0 .word 0xf8c40606 */
/* @0x2a5ea4 pop {r3, r4, r5, r7, sp, lr} */
/* @0x2a5ea8 .word 0xf42683f8 */
/* @0x2a5eac .word 0xf0264684 */
/* @0x2a5eb0 b 0xb67738 <b2_toiTime+0x40e294> */
/* @0x2a5eb4 .word 0xf8c40306 */
/* @0x2a5eb8 pop {r3, r4, r5, r7, r12, sp} */
/* @0x2a5ebc ldrlt r8, [r3, #-0x3f8] */

/* ── FUNC 0x2a5a25 · png_set_sig_bytes · size=40 · insn=0 */

/* ── FUNC 0x2a5a4d · png_sig_cmp · size=92 · insn=0 */

/* ── FUNC 0x2a5aa9 · png_zalloc · size=72 · insn=0 */

/* ── FUNC 0x2a5af1 · png_zfree · size=4 · insn=0 */

/* ── FUNC 0x2a5af5 · png_reset_crc · size=20 · insn=0 */

/* ── FUNC 0x2a5b09 · png_calculate_crc · size=48 · insn=0 */

/* ── FUNC 0x2a5b39 · png_info_init_3 · size=44 · insn=0 */

/* ── FUNC 0x2a5b65 · png_create_info_struct · size=44 · insn=0 */

/* ── FUNC 0x2a5b91 · png_data_freer · size=48 · insn=0 */

/* ── FUNC 0x2a5bc1 · png_free_data · size=766 · insn=0 */

/* ── FUNC 0x2a5ebe · anon_2a5ebe · size=60 · insn=15 */
/* @0x2a5ebe .word 0xf04fb513 */
/* @0x2a5ec2 .word 0x460433ff */
/* @0x2a5ec6 rscsvc pc, pc, #74448896 */
/* @0x2a5eca .word 0xf7ff9101 */
/* @0x2a5ece .word 0xf8d4fe78 */
/* @0x2a5ed2 smlalbtlt r3, r11, r12, r2 */
/* @0x2a5ed6 .word 0xf8d44620 */
/* @0x2a5eda .word 0xf00012d0 */
/* @0x2a5ede movwhs pc, #0xf0e */
/* @0x2a5ee2 sbcslo pc, r0, #196, #16 */
/* @0x2a5ee6 sbclo pc, r12, #196, #16 */
/* @0x2a5eea vst2.8 {d26, d27}, [pc], r1 */
/* @0x2a5eee .word 0xf7ff7190 */
/* @0x2a5ef2 andlt pc, r2, r2, lsr #28 */
/* @0x2a5ef6 ldrblt r11, [r0, #-0xd10]! */

/* ── FUNC 0x2a5ebf · png_info_destroy · size=58 · insn=0 */

/* ── FUNC 0x2a5ef8 · anon_2a5ef8 · size=304 · insn=76 */
/* @0x2a5ef8 .word 0x460cb570 */
/* @0x2a5efc cmnlt r0, r6, lsl #12 */
/* @0x2a5f00 stmdavs sp, {r0, r3, r5, r6, r8, r12, sp, pc} */
/* @0x2a5f04 qsaxmi r11, r9, sp */
/* @0x2a5f08 .word 0xffd9f7ff */
/* @0x2a5f0c .word 0xf8d64628 */
/* @0x2a5f10 .word 0xf8d612f0 */
/* @0x2a5f14 .word 0xf00022e8 */
/* @0x2a5f18 movwhs pc, #0xea2 */
/* @0x2a5f1c ldcllt p0, c6, [r0, #-140]! */
/* @0x2a5f20 .word 0xf8d0b108 */
/* @0x2a5f24 .word 0x47700118 */
/* @0x2a5f28 .word 0xf8c0b108 */
/* @0x2a5f2c .word 0x47701118 */
/* @0x2a5f30 .word 0x460cb570 */
/* @0x2a5f34 strmi r11, [r5], -r6, lsl #1 */
/* @0x2a5f38 eorsle r2, r4, r0, lsl #16 */
/* @0x2a5f3c adcslo pc, r12, #208, #16 */
/* @0x2a5f40 tsths sp, r3, lsr #18 */
/* @0x2a5f44 cdp2 p0, #0xa, c15, c12, c0, #0x0 */
/* @0x2a5f48 adcseq pc, r12, #12910592 */
/* @0x2a5f4c smlatbhs r12, r0, r8, r7 */
/* @0x2a5f50 stmdalo r1, {r1, r2, r5, r6, r7, r11, r12, sp, lr} */
/* @0x2a5f54 mcr p0, #0x6, pc, c12, c2, #0x3 */
/* @0x2a5f58 stmdbvc r0!, {r2, r4, r8, r9, r11, lr} */
/* @0x2a5f5c ldreq pc, [pc], -r6 */
/* @0x2a5f60 movwlo r4, #0x847b */
/* @0x2a5f64 orreq lr, r1, r3, lsl #22 */
/* @0x2a5f68 .word 0x91008823 */
/* @0x2a5f6c movwls r2, #0x1118 */
/* @0x2a5f70 mrc p0, #0x5, apsr_nzcv, c14, c2, #0x3 */
/* @0x2a5f74 sbclt r7, r9, #96, #18 */
/* @0x2a5f78 teqhs r12, r2, lsl #2 */
/* @0x2a5f7c mrc p0, #0x5, apsr_nzcv, c8, c2, #0x3 */
/* @0x2a5f80 sbclt r7, r9, #160, #18 */
/* @0x2a5f84 teqhs sp, r3, lsl #2 */
/* @0x2a5f88 mrc p0, #0x5, apsr_nzcv, c2, c2, #0x3 */
/* @0x2a5f8c ldrtmi r4, [r3], -r8, lsl #20 */
/* @0x2a5f90 sbclt r4, r9, #2046820352 */
/* @0x2a5f94 tsths sp, r4, lsl #2 */
/* @0x2a5f98 adcseq pc, r12, #13959168 */
/* @0x2a5f9c bl 0x7e37e4 <b2_toiTime+0x8a340> */
/* @0x2a5fa0 adcseq pc, r12, #13959168 */
/* @0x2a5fa4 strdlt lr, pc, [r6], -pc */
/* @0x2a5fa8 svclt #0xbd70 */
/* @0x2a5fac andeq r9, lr, r0, ror #18 */
/* @0x2a5fb0 strdeq r6, r7, [lr], -r8 */
/* @0x2a5fb4 ldrbtmi r4, [r8], #-2049 */
/* @0x2a5fb8 svclt #0x4770 */
/* @0x2a5fbc strdeq r6, r7, [lr], -r0 */
/* @0x2a5fc0 ldrbtmi r4, [r8], #-2049 */
/* @0x2a5fc4 svclt #0x4770 */
/* @0x2a5fc8 andeq r6, lr, lr, lsr #7 */
/* @0x2a5fcc ldrbtmi r4, [r8], #-2049 */
/* @0x2a5fd0 svclt #0x4770 */
/* @0x2a5fd4 andeq r6, lr, r2, lsr #7 */
/* @0x2a5fd8 ldrbtmi r4, [r8], #-2049 */
/* @0x2a5fdc svclt #0x4770 */
/* @0x2a5fe0 muleq lr, sp, r3 */
/* @0x2a5fe4 .word 0x460eb570 */
/* @0x2a5fe8 .word 0xb1b9b1e0 */
/* @0x2a5fec sbcmi pc, r12, #208, #16 */
/* @0x2a5ff0 ldcle p12, c2, [r5, #-0] */
/* @0x2a5ff4 .word 0xf8d02505 */
/* @0x2a5ff8 .word 0x436532d0 */
/* @0x2a5ffc ldrmi r3, [sp], #-3333 */
/* @0x2a6000 qasxmi r4, r9, r0 */
/* @0x2a6004 .word 0xf6102204 */
/* @0x2a6008 stmdblt r8, {r2, r3, r4, r9, r10, r11, sp, lr, pc} */
/* @0x2a600c ldcllt p9, c7, [r0, #-160]! */
/* @0x2a6010 .word 0xf1a53c01 */
/* @0x2a6014 mvnsle r0, r5, lsl #10 */
/* @0x2a6018 and r4, r3, r0, lsr #12 */
/* @0x2a601c ldcllt p6, c4, [r0, #-32]! */
/* @0x2a6020 ldcllt p0, c2, [r0, #-0]! */
/* @0x2a6024 tstlt r8, r0, ror sp */

/* ── FUNC 0x2a5ef9 · png_destroy_info_struct · size=40 · insn=0 */

/* ── FUNC 0x2a5f21 · png_get_io_ptr · size=8 · insn=0 */

/* ── FUNC 0x2a5f29 · png_init_io · size=8 · insn=0 */

/* ── FUNC 0x2a5f31 · png_convert_to_rfc1123 · size=132 · insn=0 */

/* ── FUNC 0x2a5fb5 · png_get_copyright · size=12 · insn=0 */

/* ── FUNC 0x2a5fc1 · png_get_libpng_ver · size=12 · insn=0 */

/* ── FUNC 0x2a5fcd · png_get_header_ver · size=12 · insn=0 */

/* ── FUNC 0x2a5fd9 · png_get_header_version · size=12 · insn=0 */

/* ── FUNC 0x2a5fe5 · png_handle_as_unknown · size=66 · insn=0 */

/* ── FUNC 0x2a6026 · anon_2a6026 · size=24 · insn=6 */
/* @0x2a6026 .word 0xf500b118 */
/* @0x2a602a .word 0xf075709c */
/* @0x2a602e .word 0xf06fbd56 */
/* @0x2a6032 ldrbmi r0, [r0, -r1]! */
/* @0x2a6036 adcseq pc, r3, r2, asr #12 */
/* @0x2a603a ldrblt r4, [r0, #-0x770]! */

/* ── FUNC 0x2a6027 · png_reset_zstream · size=16 · insn=0 */

/* ── FUNC 0x2a6037 · png_access_version_number · size=6 · insn=0 */
