/* libyoyo.so 覆盖卡组 0262
 * 函数 0x2b093d..0x2b184d，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2b093d · png_set_write_status_fn · size=8 · insn=0 */

/* ── FUNC 0x2b0945 · png_set_write_user_transform_fn · size=20 · insn=0 */

/* ── FUNC 0x2b0959 · png_write_png · size=166 · insn=0 */

/* ── FUNC 0x2b09fe · anon_2b09fe · size=216 · insn=54 */
/* @0x2b09fe ldrblt r6, [r0, #0x883]! */
/* @0x2b0a02 cmnmi pc, #35 */
/* @0x2b0a06 .word 0x03fff023 */
/* @0x2b0a0a svclo #0x84f5b3 */
/* @0x2b0a0e bhs 0x364f96 <_ZTS12CDS_Priority+0x6fee> */
/* @0x2b0a12 andsle r6, r11, r6, lsl #16 */
/* @0x2b0a16 eorsle r2, r2, r4, lsl #20 */
/* @0x2b0a1a .word 0xd14a2a01 */
/* @0x2b0a1e strmi r2, [pc], -r0, lsl #10 */
/* @0x2b0a22 orrhs r4, r0, #44, #12 */
/* @0x2b0a26 strhle r4, [pc], -r5 */
/* @0x2b0a2a andgt pc, r5, r1, lsl r8 */
/* @0x2b0a2e svceq #0xf1bc */
/* @0x2b0a32 tstmi r12, #0 */
/* @0x2b0a36 .word 0xf1052b01 */
/* @0x2b0a3a svclt #0xd70501 */
/* @0x2b0a3e blmi 0x32ea62 */
/* @0x2b0a42 strhs r1, [r0], #-91 */
/* @0x2b0a46 strb r2, [sp, r0, lsl #7]! */
/* @0x2b0a4a eors r2, r0, r0, lsl #23 */
/* @0x2b0a4e strmi r2, [pc], -r0, lsl #10 */
/* @0x2b0a52 movwhs r4, #0x662c */
/* @0x2b0a56 ldrhle r4, [r0], -r5 */
/* @0x2b0a5a andgt pc, r5, r1, lsl r8 */
/* @0x2b0a5e .word 0x0c03f00c */
/* @0x2b0a62 .word 0xfc03fa0c */
/* @0x2b0a66 streq lr, [r12], #-2628 */
/* @0x2b0a6a .word 0xf807b923 */
/* @0x2b0a6e ldrmi r4, [r12], -r1, lsl #22 */
/* @0x2b0a72 and r2, r0, r6, lsl #6 */
/* @0x2b0a76 strlo r3, [r1, #-0xb02] */
/* @0x2b0a7a blhs 0x46aa32 <g_RomDisk+0x73212> */
/* @0x2b0a7e strhs lr, [r0, #-0x17] */
/* @0x2b0a82 strtmi r4, [r12], -pc, lsl #12 */
/* @0x2b0a86 adcsmi r4, r5, #19922944 */
/* @0x2b0a8a .word 0xf811d010 */
/* @0x2b0a8e .word 0xf00cc005 */
/* @0x2b0a92 blx 0x5b3ad6 <g_SWFlineaavertbuff+0x60a0e> */
/* @0x2b0a96 b 0x13efaaa <b2_toiTime+0xc96606> */
/* @0x2b0a9a stmdblt r3!, {r2, r3, r10} */
/* @0x2b0a9e blmi 0x32eac2 */
/* @0x2b0aa2 movwhs r4, #0x461c */
/* @0x2b0aa6 bllo 0x3e8aae <pcf_driver_class+0x86> */
/* @0x2b0aaa strb r3, [r12, r1, lsl #10]! */
/* @0x2b0aae svclt #0x182b04 */
/* @0x2b0ab2 bvc 0xfe38cbaa <b2_toiTime+0xfffffffffdc33706> */
/* @0x2b0ab6 cmpmi r10, #536870916 */
/* @0x2b0aba sbcslt r6, r2, #196608 */
/* @0x2b0abe bhs 0x48d5ce <prim_v+0x3c1a> */
/* @0x2b0ac2 ldmeq r2, {r1, r8, r11, r12, lr, pc} ^ */
/* @0x2b0ac6 and r4, r2, r10, asr r3 */
/* @0x2b0aca andlo r4, r7, #1744830465 */
/* @0x2b0ace ldrdvs r0, r1, [r2], #-130 */
/* @0x2b0ad2 push {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc} */

/* ── FUNC 0x2b09ff · png_do_pack · size=214 · insn=0 */

/* ── FUNC 0x2b0ad4 · anon_2b0ad4 · size=608 · insn=152 */
/* @0x2b0ad4 svcmi #0xf0e92d */
/* @0x2b0ad8 bvc 0x41cd04 <g_RomDisk+0x254e4> */
/* @0x2b0adc .word 0xf0002d03 */
/* @0x2b0ae0 .word 0xf01580b8 */
/* @0x2b0ae4 bvc 0x13746f4 <b2_toiTime+0xc1b250> */
/* @0x2b0ae8 ldmdavc r4, {r0, r2, r3, r12, lr, pc} */
/* @0x2b0aec .word 0x96001b1e */
/* @0x2b0af0 ldmdavc r4, {r2, r10, r12, pc} ^ */
/* @0x2b0af4 .word 0x96011b1e */
/* @0x2b0af8 ldmvc r4, {r0, r2, r10, r12, pc} */
/* @0x2b0afc .word 0x96021b1e */
/* @0x2b0b00 strhs r9, [r3], #-1030 */
/* @0x2b0b04 ldmvc r4, {r2, sp, lr, pc} ^ */
/* @0x2b0b08 .word 0x96001b1e */
/* @0x2b0b0c strhs r9, [r1], #-1028 */
/* @0x2b0b10 strle r0, [r9, #-0x76d] */
/* @0x2b0b14 svcge #0x87916 */
/* @0x2b0b18 streq lr, [r4, #0xb07] */
/* @0x2b0b1c blne 0xfea7db28 <b2_toiTime+0xfffffffffe324684> */
/* @0x2b0b20 .word 0x6c10f845 */
/* @0x2b0b24 stcvc p8, c15, [r0], #-276 */
/* @0x2b0b28 ldmdale r4!, {r0, r1, r2, r8, r9, r11, sp} */
/* @0x2b0b2c stmdavs r4, {r1, r4, r6, r7, r11, r12, sp, lr} ^ */
/* @0x2b0b30 .word 0xd1042a01 */
/* @0x2b0b34 svclt #0xc2b02 */
/* @0x2b0b38 .word 0x23ff2355 */
/* @0x2b0b3c blhs 0x3e8b60 <pfr_cmap_class_rec+0x1c> */
/* @0x2b0b40 bhs 0x3a4f58 <af_blue_strings+0x2c34> */
/* @0x2b0b44 tsths r1, #12, #30 */
/* @0x2b0b48 strd r2, r3, [r0], -pc */
/* @0x2b0b4c stcls p3, c2, [r0, #-1020] */
/* @0x2b0b50 .word 0x0c04eb01 */
/* @0x2b0b54 .word 0xf04f9804 */
/* @0x2b0b58 .word 0xf1c50900 */
/* @0x2b0b5c .word 0xf1c00a00 */
/* @0x2b0b60 strbmi r0, [r1, #-0x800]! */
/* @0x2b0b64 usub16mi sp, r4, r5 */
/* @0x2b0b68 stmdavc lr, {r1, r3, r5, r9, r10, lr} */
/* @0x2b0b6c blls 0x32eb78 */
/* @0x2b0b70 ldclle p5, c4, [r6, #264]! */
/* @0x2b0b74 .word 0xf8112a00 */
/* @0x2b0b78 svclt #0xd67c01 */
/* @0x2b0b7c blx 0x3ef49e */
/* @0x2b0b80 blx 0x36f3a2 <_ZTS13C_UTF16String+0x644e> */
/* @0x2b0b84 bleq 0x3ab3b8 <error_g0017+0x405c> */
/* @0x2b0b88 b 0x15773d8 <b2_toiTime+0xe1df34> */
/* @0x2b0b8c strmi r0, [r4], #-1799 */
/* @0x2b0b90 .word 0x7c01f801 */
/* @0x2b0b94 blhs 0x4eab4c <SrcVerts+0x47b90> */
/* @0x2b0b98 blx 0x38abae <bigtens_D2A+0x107e> */
/* @0x2b0b9c .word 0xd128f804 */
/* @0x2b0ba0 strmi r2, [sp], -r0, lsl #12 */
/* @0x2b0ba4 strbmi r4, [r6, #-0x6b1] */
/* @0x2b0ba8 shsaxmi sp, r0, r3 */
/* @0x2b0bac .word 0xf0684621 */
/* @0x2b0bb0 blge 0x4eae38 <SrcVerts+0x47e7c> */
/* @0x2b0bb4 .word 0xf8057828 */
/* @0x2b0bb8 bl 0x3977c4 <ft_adobe_glyph_list+0x6ea0> */
/* @0x2b0bbc .word 0xf8510181 */
/* @0x2b0bc0 .word 0xf8513c20 */
/* @0x2b0bc4 subsmi r1, r10, #16, #24 */
/* @0x2b0bc8 .word 0x0c00f1c1 */
/* @0x2b0bcc stcle p5, c4, [lr, #-396] */
/* @0x2b0bd0 .word 0xf8152b00 */
/* @0x2b0bd4 svclt #0xcc7c01 */
/* @0x2b0bd8 blx 0x3af3e0 <error_g0017+0x8084> */
/* @0x2b0bdc blx 0x36f4e4 <_ZTS13C_UTF16String+0x6590> */
/* @0x2b0be0 streq lr, [r7, -r10, asr #20] */
/* @0x2b0be4 .word 0xf8051a5b */
/* @0x2b0be8 strmi r7, [r10], #-3073 */
/* @0x2b0bec strlo lr, [r1], -lr, ror #15 */
/* @0x2b0bf0 stcne p7, c14, [sp], {217} */
/* @0x2b0bf4 strbmi r2, [r6, #-0x600] */
/* @0x2b0bf8 ldrtmi sp, [r0], -r11, lsr #32 */
/* @0x2b0bfc .word 0xf0684621 */
/* @0x2b0c00 .word 0xf815e878 */
/* @0x2b0c04 .word 0xf8157c02 */
/* @0x2b0c08 bl 0x37fc14 <_ZTS13C_UTF16String+0x16cc0> */
/* @0x2b0c0c blge 0x4ba830 <SrcVerts+0x17874> */
/* @0x2b0c10 bl 0x39d714 <ft_adobe_glyph_list+0xcdf0> */
/* @0x2b0c14 movwhs r0, #0x181 */
/* @0x2b0c18 .word 0x0c10f851 */
/* @0x2b0c1c stchs p8, c15, [r0], #-324 */
/* @0x2b0c20 .word 0x0c00f1c0 */
/* @0x2b0c24 strbmi r4, [r2, #-0x251]! */
/* @0x2b0c28 bhs 0x2e805c <ft_mem_qrealloc+0x4c> */
/* @0x2b0c2c blx 0x4a0b64 <TimingData+0x6b4c> */
/* @0x2b0c30 blx 0x14af040 <b2_toiTime+0xd55b9c> */
/* @0x2b0c34 b 0x13af040 <b2_toiTime+0xc55b9c> */
/* @0x2b0c38 bne 0x731864 <g_SWFvertbuff+0x5e79c> */
/* @0x2b0c3c addslt r4, r11, #16777216 */
/* @0x2b0c40 beq 0x96ac0c <b2_toiTime+0x211768> */
/* @0x2b0c44 .word 0x3c01f805 */
/* @0x2b0c48 .word 0x2c02f805 */
/* @0x2b0c4c strlo r3, [r2, #-0x601] */
/* @0x2b0c50 ldrdlt lr, pc, [r9], -r1 */
/* @0x2b0c54 svchi #0xf0e8bd */
/* @0x2b0c58 bvc 0x39e120 <ft_adobe_glyph_list+0xd7fc> */
/* @0x2b0c5c teqle sp, r6, lsl #22 */
/* @0x2b0c60 stmdavs r2, {r0, r1, r6, r9, r11, r12, sp, lr} */
/* @0x2b0c64 .word 0xf04f2b08 */
/* @0x2b0c68 tstle r3, r0, lsl #6 */
/* @0x2b0c6c mulsle r0, r3, r2 */
/* @0x2b0c70 movwlo r7, #0x184c */
/* @0x2b0c74 .word 0x31047808 */
/* @0x2b0c78 .word 0x4c04f801 */
/* @0x2b0c7c .word 0x4c02f811 */
/* @0x2b0c80 .word 0x4c03f801 */
/* @0x2b0c84 .word 0x4c01f811 */
/* @0x2b0c88 .word 0x0c01f801 */
/* @0x2b0c8c .word 0x4c02f801 */
/* @0x2b0c90 ldclt p7, c14, [r0, #-944]! */
/* @0x2b0c94 mlale r0, r3, r2, r4 */
/* @0x2b0c98 movwlo r7, #0x188d */
/* @0x2b0c9c .word 0x3108780c */
/* @0x2b0ca0 .word 0x0c07f811 */
/* @0x2b0ca4 .word 0x5c08f801 */
/* @0x2b0ca8 .word 0x5c05f811 */
/* @0x2b0cac .word 0x5c07f801 */
/* @0x2b0cb0 .word 0x5c04f811 */
/* @0x2b0cb4 .word 0x5c06f801 */
/* @0x2b0cb8 .word 0x5c03f811 */
/* @0x2b0cbc .word 0x5c05f801 */
/* @0x2b0cc0 .word 0x5c02f811 */
/* @0x2b0cc4 .word 0x4c02f801 */
/* @0x2b0cc8 .word 0x5c04f801 */
/* @0x2b0ccc .word 0x5c01f811 */
/* @0x2b0cd0 .word 0x0c01f801 */
/* @0x2b0cd4 .word 0x5c03f801 */
/* @0x2b0cd8 ldclt p7, c14, [r0, #-880]! */
/* @0x2b0cdc .word 0xd1272b04 */
/* @0x2b0ce0 stmdavs r2, {r0, r1, r6, r9, r11, r12, sp, lr} */
/* @0x2b0ce4 .word 0xf04f2b08 */
/* @0x2b0ce8 .word 0xd10e0300 */
/* @0x2b0cec .word 0xf1014293 */
/* @0x2b0cf0 andle r0, r9, r2, lsl #2 */
/* @0x2b0cf4 .word 0x0c02f811 */
/* @0x2b0cf8 .word 0xf8113301 */
/* @0x2b0cfc .word 0xf8014c01 */
/* @0x2b0d00 .word 0xf8010c01 */
/* @0x2b0d04 ldrb r4, [r1, r2, lsl #24]! */
/* @0x2b0d08 addsmi r11, r3, #48, #26 */
/* @0x2b0d0c stmvc sp, {r4, r12, lr, pc} */
/* @0x2b0d10 stmdavc r12, {r0, r8, r9, r12, sp} */
/* @0x2b0d14 .word 0xf8113104 */
/* @0x2b0d18 .word 0xf8010c03 */
/* @0x2b0d1c .word 0xf8115c04 */
/* @0x2b0d20 .word 0xf8015c01 */
/* @0x2b0d24 .word 0xf8014c02 */
/* @0x2b0d28 .word 0xf8010c01 */
/* @0x2b0d2c strb r5, [r12, r3, lsl #24]! */
/* @0x2b0d30 bvc 0x3a01f8 <ft_standard_glyph_names+0x1504> */

/* ── FUNC 0x2b0ad5 · png_do_shift · size=388 · insn=0 */

/* ── FUNC 0x2b0c59 · png_do_write_swap_alpha · size=218 · insn=0 */

/* ── FUNC 0x2b0d32 · anon_2b0d32 · size=140 · insn=35 */
/* @0x2b0d32 blhs 0x44f546 <g_RomDisk+0x57d26> */
/* @0x2b0d36 bvc 0x13a51b6 <b2_toiTime+0xc4bd12> */
/* @0x2b0d3a blhs 0x4cad4a <SrcVerts+0x27d8e> */
/* @0x2b0d3e movweq pc, #0x4f */
/* @0x2b0d42 addsmi sp, r3, #1073741826 */
/* @0x2b0d46 stmvc r8, {r1, r2, r12, lr, pc} ^ */
/* @0x2b0d4a .word 0x31043301 */
/* @0x2b0d4e .word 0xf80143c0 */
/* @0x2b0d52 ldrb r0, [r6, r1, lsl #24]! */
/* @0x2b0d56 addsmi r4, r3, #112, #14 */
/* @0x2b0d5a stmibvc r8, {r0, r1, r3, r12, lr, pc} */
/* @0x2b0d5e .word 0x31083301 */
/* @0x2b0d62 .word 0xf80143c0 */
/* @0x2b0d66 .word 0xf8110c02 */
/* @0x2b0d6a bicmi r0, r0, #256 */
/* @0x2b0d6e .word 0x0c01f801 */
/* @0x2b0d72 .word 0x4770e7f1 */
/* @0x2b0d76 tstle pc, r4, lsl #22 */
/* @0x2b0d7a stmdavs r2, {r0, r1, r6, r9, r11, r12, sp, lr} */
/* @0x2b0d7e .word 0xf04f2b08 */
/* @0x2b0d82 .word 0xd10b0300 */
/* @0x2b0d86 .word 0xf1014293 */
/* @0x2b0d8a andle r0, r6, r2, lsl #2 */
/* @0x2b0d8e .word 0x0c01f811 */
/* @0x2b0d92 bicmi r3, r0, #67108864 */
/* @0x2b0d96 .word 0x0c01f801 */
/* @0x2b0d9a .word 0x4770e7f4 */
/* @0x2b0d9e mulle r11, r3, r2 */
/* @0x2b0da2 movwlo r7, #0x1888 */
/* @0x2b0da6 bicmi r3, r0, #4, #2 */
/* @0x2b0daa .word 0x0c02f801 */
/* @0x2b0dae .word 0x0c01f811 */
/* @0x2b0db2 .word 0xf80143c0 */
/* @0x2b0db6 ldrb r0, [r1, r1, lsl #24]! */
/* @0x2b0dba ldrlt r4, [r0, #-0x770] */

/* ── FUNC 0x2b0d33 · png_do_write_invert_alpha · size=138 · insn=0 */

/* ── FUNC 0x2b0dbc · anon_2b0dbc · size=252 · insn=63 */
/* @0x2b0dbc .word 0x4604b510 */
/* @0x2b0dc0 rsbsle r2, r7, r0, lsl #16 */
/* @0x2b0dc4 ldrsblo pc, [r4, -r0]! */
/* @0x2b0dc8 strle r0, [r8, #-0x2da] */
/* @0x2b0dcc .word 0x3120f8d0 */
/* @0x2b0dd0 .word 0xf8d0b12b */
/* @0x2b0dd4 .word 0xf50021b0 */
/* @0x2b0dd8 andlo r7, r1, #-2147483592 */
/* @0x2b0ddc .word 0xf8d44798 */
/* @0x2b0de0 ldreq r3, [r11], #-308 */
/* @0x2b0de4 .word 0xf8d4d508 */
/* @0x2b0de8 .word 0xf50411b0 */
/* @0x2b0dec .word 0xf8d470e2 */
/* @0x2b0df0 .word 0x31012130 */
/* @0x2b0df4 ldc2 p7, c15, [r12, #1016] */
/* @0x2b0df8 ldrsblo pc, [r4, -r4]! */
/* @0x2b0dfc strle r0, [r6, #-0x3d8] */
/* @0x2b0e00 ldrsbne pc, [r0, r4]! */
/* @0x2b0e04 rscvc pc, r2, r4, lsl #10 */
/* @0x2b0e08 .word 0xf7fe3101 */
/* @0x2b0e0c .word 0xf8d4fd6b */
/* @0x2b0e10 smmlareq r9, r4, r1, r3 */
/* @0x2b0e14 .word 0xf8d4d508 */
/* @0x2b0e18 .word 0xf50411b0 */
/* @0x2b0e1c .word 0xf89470e2 */
/* @0x2b0e20 smlattlo r1, r11, r1, r2 */
/* @0x2b0e24 stc2l p7, c15, [r11, #1020]! */
/* @0x2b0e28 ldrsblo pc, [r4, -r4]! */
/* @0x2b0e2c strle r0, [r6, #-0x6da] */
/* @0x2b0e30 ldrsbne pc, [r0, r4]! */
/* @0x2b0e34 rscvc pc, r2, r4, lsl #10 */
/* @0x2b0e38 .word 0xf7fe3101 */
/* @0x2b0e3c .word 0xf8d4fd3c */
/* @0x2b0e40 .word 0x071b3134 */
/* @0x2b0e44 .word 0xf8d4d508 */
/* @0x2b0e48 .word 0xf50411b0 */
/* @0x2b0e4c .word 0xf20470e2 */
/* @0x2b0e50 .word 0x31012245 */
/* @0x2b0e54 mrc2 p7, #0x1, apsr_nzcv, c14, c15, #0x7 */
/* @0x2b0e58 ldrsblo pc, [r4, -r4]! */
/* @0x2b0e5c strle r0, [r6, #-0x398] */
/* @0x2b0e60 ldrsbne pc, [r0, r4]! */
/* @0x2b0e64 rscvc pc, r2, r4, lsl #10 */
/* @0x2b0e68 .word 0xf7ff3101 */
/* @0x2b0e6c .word 0xf8d4fef5 */
/* @0x2b0e70 tsteq r9, #52, #2 */
/* @0x2b0e74 .word 0xf8d4d506 */
/* @0x2b0e78 .word 0xf50411b0 */
/* @0x2b0e7c smlattlo r1, r2, r0, r7 */
/* @0x2b0e80 .word 0xff57f7ff */
/* @0x2b0e84 ldrsblo pc, [r4, -r4]! */
/* @0x2b0e88 strle r0, [r6, #-0x7da] */
/* @0x2b0e8c ldrsbne pc, [r0, r4]! */
/* @0x2b0e90 rscvc pc, r2, r4, lsl #10 */
/* @0x2b0e94 .word 0xf7fe3101 */
/* @0x2b0e98 .word 0xf8d4fe27 */
/* @0x2b0e9c .word 0x069b3134 */
/* @0x2b0ea0 .word 0xf8d4d508 */
/* @0x2b0ea4 .word 0xf50411b0 */
/* @0x2b0ea8 pop {r1, r5, r6, r7, r12, sp, lr} */
/* @0x2b0eac .word 0x31014010 */
/* @0x2b0eb0 ldcllt p7, c15, [r3], {254} */
/* @0x2b0eb4 ldrblt r11, [r0, #0xd10]! */

/* ── FUNC 0x2b0dbd · png_do_write_transformations · size=250 · insn=0 */

/* ── FUNC 0x2b0eb6 · anon_2b0eb6 · size=624 · insn=156 */
/* @0x2b0eb6 bvc 0x39e67e <t1_standard_encoding+0x9c> */
/* @0x2b0eba ldrle r0, [sp, #-0x79a]! */
/* @0x2b0ebe bvc 0x12caece <b2_toiTime+0xb71a2a> */
/* @0x2b0ec2 tstle r4, r8, lsl #16 */
/* @0x2b0ec6 andle r2, r3, r2, lsl #22 */
/* @0x2b0eca teqle r5, r6, lsl #22 */
/* @0x2b0ece and r2, r0, r4 */
/* @0x2b0ed2 movwhs r2, #0x3 */
/* @0x2b0ed6 mulle r9, r3, r2 */
/* @0x2b0eda movwlo r7, #0x184c */
/* @0x2b0ede blne 0xe0ef1a <b2_toiTime+0x6b5a76> */
/* @0x2b0ee2 stmvc sp, {r0, r2, r3, r12, sp, lr} */
/* @0x2b0ee6 addvc r1, r12, r12, lsr #22 */
/* @0x2b0eea ldrb r4, [r3, r1, lsl #8]! */
/* @0x2b0eee ldmdahs r0, {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc} */
/* @0x2b0ef2 blhs 0x365382 <_ZTS12CDS_Priority+0x73da> */
/* @0x2b0ef6 blhs 0x464f0a <g_RomDisk+0x6d6ea> */
/* @0x2b0efa andhs sp, r8, lr, lsl r1 */
/* @0x2b0efe andhs lr, r6, r0 */
/* @0x2b0f02 addsmi r2, r3, #0, #6 */
/* @0x2b0f06 stmvc lr, {r3, r4, r12, lr, pc} */
/* @0x2b0f0a stmvc r12, {r0, r8, r9, r12, sp} ^ */
/* @0x2b0f0e b 0x13cef4a <b2_toiTime+0xc75aa6> */
/* @0x2b0f12 stmdavc r12, {r1, r2, r9, r10, sp} ^ */
/* @0x2b0f16 b 0x13cf35a <b2_toiTime+0xc75eb6> */
/* @0x2b0f1a stmdbvc r12, {r0, r2, r8, r10, sp} ^ */
/* @0x2b0f1e b 0x13b7dda <b2_toiTime+0xc5e936> */
/* @0x2b0f22 blne 0xfebb9f46 <b2_toiTime+0xfffffffffe460aa2> */
/* @0x2b0f26 subvc r11, sp, sp, lsr #5 */
/* @0x2b0f2a beq 0xe5d9c2 <b2_toiTime+0x70451e> */
/* @0x2b0f2e andvc r7, lr, r12, asr #2 */
/* @0x2b0f32 .word 0x710d0a25 */
/* @0x2b0f36 strb r4, [r4, r1, lsl #8]! */
/* @0x2b0f3a push {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc} */
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

/* ── FUNC 0x2b0eb7 · png_do_write_intrapixel · size=134 · insn=0 */

/* ── FUNC 0x2b1124 · anon_2b1124 · size=372 · insn=93 */
/* @0x2b1124 sbcvc r0, r1, r11, lsl #28 */
/* @0x2b1128 .word 0x0c0b7003 */
/* @0x2b112c beq 0x58d240 <g_SWFlineaavertbuff+0x3a178> */
/* @0x2b1130 ldrbmi r7, [r0, -r3, lsl #1]! */
/* @0x2b1134 svclt #0xf6f7ff */
/* @0x2b1138 subvc r0, r1, r11, lsl #20 */
/* @0x2b113c ldrbmi r7, [r0, -r3]! */
/* @0x2b1140 addlt r11, r5, r0, lsr r5 */
/* @0x2b1144 .word 0x46044d14 */
/* @0x2b1148 ldrbtmi r4, [sp], #-2580 */
/* @0x2b114c ldrbtmi r6, [r10], #-2093 */
/* @0x2b1150 ldmdavs r0, {r0, r1, r3, r5, r11, sp, lr} */
/* @0x2b1154 movwls r6, #0x3851 */
/* @0x2b1158 .word 0xf894ab01 */
/* @0x2b115c movwgt r2, #0x31f0 */
/* @0x2b1160 tsths r2, #16384 */
/* @0x2b1164 .word 0xf8c44411 */
/* @0x2b1168 qasxmi r3, r0, r4 */
/* @0x2b116c andeq pc, r8, #-2147483600 */
/* @0x2b1170 ldc2 p7, c15, [lr, #-1016]! */
/* @0x2b1174 .word 0x31f0f894 */
/* @0x2b1178 stmdale r5, {r1, r8, r9, r11, sp} */
/* @0x2b117c .word 0x312cf8d4 */
/* @0x2b1180 orrpl pc, r0, #1124073472 */
/* @0x2b1184 smlawtlo r12, r4, r8, pc */
/* @0x2b1188 stmdavs r11!, {r0, r1, r9, r11, r12, pc} */
/* @0x2b118c mulle r1, r10, r2 */
/* @0x2b1190 b 0xaee9ac <b2_toiTime+0x395508> */
/* @0x2b1194 ldclt p0, c11, [r0, #-20]! */
/* @0x2b1198 andseq r12, r3, r10, lsl #16 */
/* @0x2b119c andeq lr, sp, r2, lsl r12 */
/* @0x2b11a0 ldrblt r4, [r0, #0xb17]! */
/* @0x2b11a4 ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr} */
/* @0x2b11a8 addlt r4, r5, sp, lsl #12 */
/* @0x2b11ac .word 0x46046819 */
/* @0x2b11b0 .word 0x9103461f */
/* @0x2b11b4 cdpge p1, #0x0, c11, c1, c0, #0x7 */
/* @0x2b11b8 ldrmi r2, [r1], -r2, lsr #6 */
/* @0x2b11bc teqlo r4, #192, #16 */
/* @0x2b11c0 .word 0xf7ff4630 */
/* @0x2b11c4 stmdavs r8!, {r0, r1, r2, r3, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2b11c8 andhs r4, r8, #51380224 */
/* @0x2b11cc strtmi r9, [r0], -r2 */
/* @0x2b11d0 stc2 p7, c15, [lr, #-1016] */
/* @0x2b11d4 strtmi r6, [r0], -r11, lsr #16 */
/* @0x2b11d8 mvnlo pc, r4, asr #17 */
/* @0x2b11dc stc2 p7, c15, [r10], {244} */
/* @0x2b11e0 strtmi r4, [r9], -r0, lsr #12 */
/* @0x2b11e4 .word 0xf7f42204 */
/* @0x2b11e8 movths pc, #0x2c8f */
/* @0x2b11ec teqlo r4, #196, #16 */
/* @0x2b11f0 ldmdavs r11!, {r0, r1, r9, r11, r12, pc} */
/* @0x2b11f4 mulle r1, r10, r2 */
/* @0x2b11f8 stmib r12!, {r0, r2, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2b11fc ldcllt p0, c11, [r0, #20]! */
/* @0x2b1200 ldrheq r12, [r3], -r0 */
/* @0x2b1204 .word 0x460db570 */
/* @0x2b1208 .word 0x46064614 */
/* @0x2b120c qdaddlt r11, r0, r9 */
/* @0x2b1210 .word 0xf7feb142 */
/* @0x2b1214 ldrtmi pc, [r0], -sp, ror #25 */
/* @0x2b1218 strtmi r4, [r2], -r9, lsr #12 */
/* @0x2b121c ldrhtmi lr, [r0], #-141 */
/* @0x2b1220 ldcllt p7, c15, [r2], #-976 */
/* @0x2b1224 ldrblt r11, [r0, #-0xd70]! */
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

/* ── FUNC 0x2b1125 · png_save_uint_32 · size=16 · insn=0 */

/* ── FUNC 0x2b1135 · png_save_int_32 · size=4 · insn=0 */

/* ── FUNC 0x2b1139 · png_save_uint_16 · size=8 · insn=0 */

/* ── FUNC 0x2b1141 · png_write_sig · size=96 · insn=0 */

/* ── FUNC 0x2b11a1 · png_write_chunk_start · size=100 · insn=0 */

/* ── FUNC 0x2b1205 · png_write_chunk_data · size=34 · insn=0 */

/* ── FUNC 0x2b1296 · anon_2b1296 · size=40 · insn=10 */
/* @0x2b1296 .word 0x4604b537 */
/* @0x2b129a stcge p1, c11, [r1, #-416] */
/* @0x2b129e .word 0xf8c02382 */
/* @0x2b12a2 qasxmi r3, r8, r4 */
/* @0x2b12a6 ldrsbne pc, [r4, #132] */
/* @0x2b12aa .word 0xff3bf7ff */
/* @0x2b12ae strtmi r4, [r9], -r0, lsr #12 */
/* @0x2b12b2 .word 0xf7fe2204 */
/* @0x2b12b6 mullt r3, r12, r12 */
/* @0x2b12ba ldrblt r11, [r0, #-0xd30]! */

/* ── FUNC 0x2b1297 · png_write_chunk_end · size=38 · insn=0 */

/* ── FUNC 0x2b12bc · anon_2b12bc · size=6976 · insn=1744 */
/* @0x2b12bc ssub16mi r11, r6, r0 */
/* @0x2b12c0 .word 0x4604461d */
/* @0x2b12c4 ldrmi r11, [r10], -r0, ror #2 */
/* @0x2b12c8 .word 0xff6af7ff */
/* @0x2b12cc ldrtmi r4, [r1], -r0, lsr #12 */
/* @0x2b12d0 .word 0xf7ff462a */
/* @0x2b12d4 qadd8mi pc, r0, r7 */
/* @0x2b12d8 ldrhtmi lr, [r0], #-141 */
/* @0x2b12dc svclt #0xdbf7ff */
/* @0x2b12e0 andeq r11, r0, r0, ror sp */
/* @0x2b12e4 svcmi #0xf0e92d */
/* @0x2b12e8 blmi 0xfec82b64 <b2_toiTime+0xfffffffffe5296c0> */
/* @0x2b12ec umulllt r4, pc, r3, r6 */
/* @0x2b12f0 ldrbtmi r4, [r11], #-1540 */
/* @0x2b12f4 .word 0x460e681b */
/* @0x2b12f8 .word 0x8060f8dd */
/* @0x2b12fc svcls #0x1a681a */
/* @0x2b1300 .word 0xa06cf8dd */
/* @0x2b1304 bmi 0xfeb15b40 <b2_toiTime+0xfffffffffe3bc69c> */
/* @0x2b1308 ldrbtmi r9, [r10], #-773 */
/* @0x2b130c svceq #0x8f852 */
/* @0x2b1310 andls r7, r7, r2, lsl r9 */
/* @0x2b1314 eorhs pc, r0, sp, lsl #17 */
/* @0x2b1318 .word 0xf1b82201 */
/* @0x2b131c stmdale r2, {r1, r2, r8, r9, r10, r11} ^ */
/* @0x2b1320 .word 0xf008e8df */
/* @0x2b1324 blne 0x6c173c <g_SWFlinevertbuff+0x6e674> */
/* @0x2b1328 eorseq r4, r4, r9, lsr #2 */
/* @0x2b132c blhs 0x678ce0 <g_SWFlinevertbuff+0x25c18> */
/* @0x2b1330 addsmi sp, r10, r4, lsl #16 */
/* @0x2b1334 orreq pc, r11, #72, #4 */
/* @0x2b1338 ldmiblt r3!, {r0, r1, r4, lr} */
/* @0x2b133c qadd8mi r4, r0, r4 */
/* @0x2b1340 eors r4, r3, r9, ror r4 */
/* @0x2b1344 andle r2, r6, r8, lsl #26 */
/* @0x2b1348 andle r2, r4, r0, lsl sp */
/* @0x2b134c qadd8mi r4, r0, r1 */
/* @0x2b1350 .word 0xf7f54479 */
/* @0x2b1354 movwhs pc, #0x386b */
/* @0x2b1358 cdpne p0, #0x6, c14, c11, c2, #0x1 */
/* @0x2b135c stmdale r6, {r0, r1, r2, r8, r9, r11, sp} */
/* @0x2b1360 vpmax.u8 d15, d3, d2 */
/* @0x2b1364 svceq #0x8bf013 */
/* @0x2b1368 movwhs sp, #0x1001 */
/* @0x2b136c stmibmi r10, {r3, r4, sp, lr, pc} */
/* @0x2b1370 ldrbtmi r4, [r9], #-1568 */
/* @0x2b1374 stchs p0, c14, [r8, #-104] */
/* @0x2b1378 ldchs p0, c13, [r0, #-24] */
/* @0x2b137c stmibmi r7, {r2, r12, lr, pc} */
/* @0x2b1380 ldrbtmi r4, [r9], #-1568 */
/* @0x2b1384 .word 0xf852f7f5 */
/* @0x2b1388 and r2, r9, r2, lsl #6 */
/* @0x2b138c andle r2, r6, r8, lsl #26 */
/* @0x2b1390 andle r2, r4, r0, lsl sp */
/* @0x2b1394 strtmi r4, [r0], -r2, lsl #19 */
/* @0x2b1398 .word 0xf7f54479 */
/* @0x2b139c movwhs pc, #0x4847 */
/* @0x2b13a0 mvnlo pc, r4, lsl #17 */
/* @0x2b13a4 ldmdbmi pc!, {r2, sp, lr, pc} ^ */
/* @0x2b13a8 ldrbtmi r4, [r9], #-1568 */
/* @0x2b13ac rfeda lr! */
/* @0x2b13b0 .word 0xb1239b19 */
/* @0x2b13b4 qsub16mi r4, r0, r12 */
/* @0x2b13b8 .word 0xf7f54479 */
/* @0x2b13bc .word 0xf8d4f85b */
/* @0x2b13c0 smmlseq r10, r12, r2, r3 */
/* @0x2b13c4 .word 0xf8d4d509 */
/* @0x2b13c8 ldrbeq r3, [r11], #300 */
/* @0x2b13cc .word 0xf028d405 */
/* @0x2b13d0 blhs 0x331fe8 */
/* @0x2b13d4 svchs #0x40d101 */
/* @0x2b13d8 .word 0xb12fd006 */
/* @0x2b13dc qsub16mi r4, r0, r3 */
/* @0x2b13e0 ldrbtmi r2, [r9], #-1792 */
/* @0x2b13e4 .word 0xf846f7f5 */
/* @0x2b13e8 svceq #0x1f1ba */
/* @0x2b13ec ldmdbmi r0!, {r1, r2, r8, r11, r12, lr, pc} ^ */
/* @0x2b13f0 .word 0xf04f4620 */
/* @0x2b13f4 ldrbtmi r0, [r9], #-2561 */
/* @0x2b13f8 rfeda r12! */
/* @0x2b13fc .word 0xf8842200 */
/* @0x2b1400 .word 0xf8942304 */
/* @0x2b1404 blx 0x1a79bc4 <b2_toiTime+0x1320720> */
/* @0x2b1408 blx 0x1aafa24 <b2_toiTime+0x1356580> */
/* @0x2b140c blx 0x1aaf634 <b2_toiTime+0x1356190> */
/* @0x2b1410 rscslt pc, pc, #565248 */
/* @0x2b1414 mvnls pc, r4, lsl #17 */
/* @0x2b1418 .word 0xf8844355 */
/* @0x2b141c .word 0xf88481ea */
/* @0x2b1420 .word 0xf884a1e7 */
/* @0x2b1424 .word 0xf8c472e4 */
/* @0x2b1428 .word 0xf8c4618c */
/* @0x2b142c rsclt r11, sp, #144, #2 */
/* @0x2b1430 mvnpl pc, r4, lsl #17 */
/* @0x2b1434 stmdble r2, {r0, r1, r2, r8, r10, r11, sp} */
/* @0x2b1438 cmnmi r5, #15532032 */
/* @0x2b143c cmnmi r5, #2 */
/* @0x2b1440 stmeq sp!, {r0, r1, r2, r8, r10, r12, sp} ^ */
/* @0x2b1444 orrspl pc, r12, r4, asr #17 */
/* @0x2b1448 .word 0xf884ad09 */
/* @0x2b144c ldrtmi r2, [r1], -pc, ror #3 */
/* @0x2b1450 .word 0xf8c44628 */
/* @0x2b1454 .word 0xf8846198 */
/* @0x2b1458 .word 0xf7ff91ec */
/* @0x2b145c stcne p14, c15, [r8, #-396]! */
/* @0x2b1460 .word 0xf7ff4659 */
/* @0x2b1464 movwhs pc, #0xe5f */
/* @0x2b1468 .word 0xf88d4620 */
/* @0x2b146c stmdbge r7, {r1, r2, r3, r5, r12, sp} */
/* @0x2b1470 strtmi r2, [r10], -sp, lsl #6 */
/* @0x2b1474 eorls pc, r12, sp, lsl #17 */
/* @0x2b1478 eorhi pc, sp, sp, lsl #17 */
/* @0x2b147c eorvc pc, pc, sp, lsl #17 */
/* @0x2b1480 eorsge pc, r0, sp, lsl #17 */
/* @0x2b1484 .word 0xff1af7ff */
/* @0x2b1488 .word 0xf8c44b4a */
/* @0x2b148c ldrbtmi r4, [r11], #-352 */
/* @0x2b1490 .word 0xf8c4681b */
/* @0x2b1494 blmi 0x14bd9fc <b2_toiTime+0xd64558> */
/* @0x2b1498 ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr} */
/* @0x2b149c cmplo r12, r4, asr #17 */
/* @0x2b14a0 .word 0x31e9f894 */
/* @0x2b14a4 .word 0xf894b963 */
/* @0x2b14a8 blhs 0x37dc58 <_ZTS13C_UTF16String+0x14d04> */
/* @0x2b14ac .word 0xf894d003 */
/* @0x2b14b0 blhs 0x47dc64 <targetStr+0x2a24> */
/* @0x2b14b4 movwhs sp, #0x8801 */
/* @0x2b14b8 .word 0x23f8e000 */
/* @0x2b14bc mvnlo pc, r4, lsl #17 */
/* @0x2b14c0 ldrsblo pc, [r0, -r4]! */
/* @0x2b14c4 andeq pc, r1, #19 */
/* @0x2b14c8 .word 0xf894d106 */
/* @0x2b14cc stmdbhs r8, {r0, r3, r5, r6, r7, r8, r12} */
/* @0x2b14d0 andhs r11, r1, #24, #30 */
/* @0x2b14d4 orrhs pc, r8, r4, asr #17 */
/* @0x2b14d8 svclt #0x5c079e */
/* @0x2b14dc rscslo pc, pc, #79 */
/* @0x2b14e0 cmnhs r8, r4, asr #17 */
/* @0x2b14e4 svclt #0x5c075d */
/* @0x2b14e8 .word 0xf8c42208 */
/* @0x2b14ec ldreq r2, [r8, -r4, lsl #3] */
/* @0x2b14f0 addsvc pc, r12, r4, lsl #10 */
/* @0x2b14f4 andhs r11, pc, #92, #30 */
/* @0x2b14f8 orrhs pc, r0, r4, asr #17 */
/* @0x2b14fc .word 0xf50406d9 */
/* @0x2b1500 svclt #0x5c71bc */
/* @0x2b1504 .word 0xf8c42308 */
/* @0x2b1508 .word 0xf8d4317c */
/* @0x2b150c movwls r3, #0x184 */
/* @0x2b1510 .word 0x3188f8d4 */
/* @0x2b1514 blmi 0xd16120 <b2_toiTime+0x5bcc7c> */
/* @0x2b1518 movwls r4, #0x247b */
/* @0x2b151c movwls r2, #0x3338 */
/* @0x2b1520 .word 0xf605c90e */
/* @0x2b1524 .word 0xb1b8ecc6 */
/* @0x2b1528 smlabble r3, r2, sp, r1 */
/* @0x2b152c strtmi r4, [r0], -r4, lsr #18 */
/* @0x2b1530 and r4, r10, r9, ror r4 */
/* @0x2b1534 smlabble r3, r3, r12, r1 */
/* @0x2b1538 strtmi r4, [r0], -r2, lsr #18 */
/* @0x2b153c and r4, r4, r9, ror r4 */
/* @0x2b1540 .word 0xd1043004 */
/* @0x2b1544 strtmi r4, [r0], -r0, lsr #18 */
/* @0x2b1548 .word 0xf7f44479 */
/* @0x2b154c ldmdbmi pc, {r0, r1, r2, r3, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2b1550 ldrbtmi r4, [r9], #-1568 */
/* @0x2b1554 .word 0xff6af7f4 */
/* @0x2b1558 ldrsblo pc, [r0, #-132]! */
/* @0x2b155c bls 0x617978 <g_SWFaavertbuff+0x448b0> */
/* @0x2b1560 smlalbtlo pc, r4, r4, r8 */
/* @0x2b1564 ldrsblo pc, [r4, #-132]! */
/* @0x2b1568 smlalbtlo pc, r8, r4, r8 */
/* @0x2b156c .word 0xf8c42300 */
/* @0x2b1570 movwhs r3, #0x1164 */
/* @0x2b1574 smlawtlo r12, r4, r8, pc */
/* @0x2b1578 addsmi r6, r10, #720896 */
/* @0x2b157c .word 0xf605d001 */
/* @0x2b1580 andlt lr, pc, r10, lsr #16 */
/* @0x2b1584 svchi #0xf0e8bd */
/* @0x2b1588 andseq r12, r3, r2, ror #12 */
/* @0x2b158c andeq lr, sp, r6, asr r10 */
/* @0x2b1590 andeq r12, sp, r11, asr #27 */
/* @0x2b1594 andeq r12, sp, r1, ror #27 */
/* @0x2b1598 ldrdeq r12, sp, [sp], -pc */
/* @0x2b159c strdeq r12, sp, [sp], -r4 */
/* @0x2b15a0 andeq r12, sp, r10, lsl #28 */
/* @0x2b15a4 andeq r12, sp, r9, lsl lr */
/* @0x2b15a8 andeq r12, sp, lr, lsr #28 */
/* @0x2b15ac andeq r12, sp, r7, lsr #28 */
/* @0x2b15b0 andeq r12, sp, r1, lsr lr */
/* @0x2b15b4 andseq r0, r4, r10, lsl #12 */
/* @0x2b15b8 andseq r0, r4, r4, lsl #12 */
/* @0x2b15bc strheq r10, [sp], -r0 */
/* @0x2b15c0 andeq r12, sp, r8, lsl sp */
/* @0x2b15c4 andeq r12, sp, r2, asr #26 */
/* @0x2b15c8 andeq r12, sp, r11, ror #26 */
/* @0x2b15cc muleq sp, r3, sp */
/* @0x2b15d0 ldrblt r4, [r0, #0xb2f]! */
/* @0x2b15d4 .word 0x4604447b */
/* @0x2b15d8 .word 0xf853b085 */
/* @0x2b15dc ldrmi r0, [r6], -sp, lsl #30 */
/* @0x2b15e0 ldmdbvc r11, {r0, r2, r3, r9, r10, lr} */
/* @0x2b15e4 .word 0xf88d9002 */
/* @0x2b15e8 .word 0xf894300c */
/* @0x2b15ec blhs 0x37dd9c <_ZTS13C_UTF16String+0x14e48> */
/* @0x2b15f0 .word 0xf894bf05 */
/* @0x2b15f4 smlatths r1, r11, r1, r2 */
/* @0x2b15f8 addvc pc, r0, #1325400064 */
/* @0x2b15fc vpmax.s8 d15, d2, d1 */
/* @0x2b1600 sbcsne pc, r12, #212, #16 */
/* @0x2b1604 strle r0, [r0], #-1993 */
/* @0x2b1608 addsmi r11, r6, #-2147483645 */
/* @0x2b160c blhs 0x3a7a3c <error_g0017+0x6e0> */
/* @0x2b1610 .word 0xd1044620 */
/* @0x2b1614 ldrbtmi r4, [r9], #-2335 */
/* @0x2b1618 .word 0xff08f7f4 */
/* @0x2b161c ldmdbmi lr, {r1, sp, lr, pc} */
/* @0x2b1620 and r4, r6, r9, ror r4 */
/* @0x2b1624 .word 0x31eaf894 */
/* @0x2b1628 strle r0, [r5], #-1947 */
/* @0x2b162c qadd16mi r4, r0, r11 */
/* @0x2b1630 .word 0xf7f44479 */
/* @0x2b1634 eor pc, r9, pc, lsl pc */
/* @0x2b1638 .word 0xf8a42303 */
/* @0x2b163c cmpmi lr, #220, #2 */
/* @0x2b1640 stmdbge r2, {r5, r9, r10, lr} */
/* @0x2b1644 svcge #0x13503 */
/* @0x2b1648 strtmi r4, [lr], #-1586 */
/* @0x2b164c stc2 p7, c15, [r8, #1020]! */
/* @0x2b1650 ldrhle r4, [r2], -r5 */
/* @0x2b1654 .word 0x3c03f815 */
/* @0x2b1658 ldrtmi r4, [r9], -r0, lsr #12 */
/* @0x2b165c strlo r2, [r3, #-0x203] */
/* @0x2b1660 andlo pc, r4, sp, lsl #17 */
/* @0x2b1664 .word 0x3c05f815 */
/* @0x2b1668 andlo pc, r5, sp, lsl #17 */
/* @0x2b166c .word 0x3c04f815 */
/* @0x2b1670 andlo pc, r6, sp, lsl #17 */
/* @0x2b1674 stc2l p7, c15, [r6, #1020] */
/* @0x2b1678 strtmi lr, [r0], -r10, ror #15 */
/* @0x2b167c mcr2 p7, #0x0, pc, c11, c15, #0x7 */
/* @0x2b1680 .word 0x312cf8d4 */
/* @0x2b1684 movweq pc, #0x2043 */
/* @0x2b1688 smlawtlo r12, r4, r8, pc */
/* @0x2b168c ldcllt p0, c11, [r0, #20]! */
/* @0x2b1690 andeq lr, sp, r12, lsl #15 */
/* @0x2b1694 strdeq r12, sp, [sp], -r4 */
/* @0x2b1698 andeq r12, sp, r10, ror #25 */
/* @0x2b169c strdeq r12, sp, [sp], -lr */
/* @0x2b16a0 mvnsmi lr, sp, lsr #18 */
/* @0x2b16a4 ldmdbmi r7!, {r0, r2, r3, r9, r10, lr} */
/* @0x2b16a8 ldrmi r4, [r0], r4, lsl #12 */
/* @0x2b16ac .word 0xf8514479 */
/* @0x2b16b0 stmdbvc r11, {r1, r4, r8, r9, r10, r11} */
/* @0x2b16b4 .word 0xf88d9000 */
/* @0x2b16b8 .word 0xf8d43004 */
/* @0x2b16bc ldrbeq r3, [r11, -r12, lsr #2] */
/* @0x2b16c0 .word 0xf894d451 */
/* @0x2b16c4 blhs 0x2be2dc <jinit_color_deconverter+0x374> */
/* @0x2b16c8 stmdavc lr!, {r0, r2, r3, r6, r8, r12, lr, pc} */
/* @0x2b16cc movweq pc, #0xf006 */
/* @0x2b16d0 .word 0xd1432b08 */
/* @0x2b16d4 mvnseq pc, #6 */
/* @0x2b16d8 ldmdale pc!, {r4, r5, r6, r8, r9, r11, sp} */
/* @0x2b16dc stmdble r2, {r0, r9, r11, sp} ^ */
/* @0x2b16e0 ldrsblo pc, [r0, r4] */
/* @0x2b16e4 rscsvc pc, pc, #70254592 */
/* @0x2b16e8 ldmdale r12!, {r0, r1, r4, r7, r9, lr} */
/* @0x2b16ec .word 0x118cf8d4 */
/* @0x2b16f0 ldmdale r8!, {r0, r4, r7, r9, lr} */
/* @0x2b16f4 .word 0x71eef894 */
/* @0x2b16f8 .word 0x21ebf894 */
/* @0x2b16fc .word 0xf702fb17 */
/* @0x2b1700 .word 0xf894434f */
/* @0x2b1704 strlo r1, [pc, -r7, ror #3] */
/* @0x2b1708 cmpmi pc, #16711680 */
/* @0x2b170c movwlo r11, #0x7139 */
/* @0x2b1710 svclt #0x8c2a07 */
/* @0x2b1714 andhs r2, r12, #1610612736 */
/* @0x2b1718 blx 0x373a8e <_ZTS13C_UTF16String+0xab3a> */
/* @0x2b171c ldmdbeq r1!, {r1, r8, r9, r10, r12, sp, lr} */
/* @0x2b1720 stclne p0, c2, [r11, #4] */
/* @0x2b1724 addmi r4, r7, #152 */
/* @0x2b1728 .word 0x0109d913 */
/* @0x2b172c andeq pc, r8, r1, asr #32 */
/* @0x2b1730 addsmi r11, lr, #805306380 */
/* @0x2b1734 eorvc sp, r11, r7, lsl r0 */
/* @0x2b1738 stmdavc r11!, {r0, r1, r2, r3, r4, r8, sp} ^ */
/* @0x2b173c mvneq pc, #3 */
/* @0x2b1740 andhs lr, r0, r3, lsl #22 */
/* @0x2b1744 ldreq pc, [pc], -r3, lsl #2 */
/* @0x2b1748 b 0xff76d8ec <b2_toiTime+0xffffffffff014448> */
/* @0x2b174c rsbvc r1, r9, r1, ror r10 */
/* @0x2b1750 ldmhs pc!, {r0, r3, sp, lr, pc} ^ */
/* @0x2b1754 stmdblo r1, {r0, r3, r5, r6, r7, r8, r11, r12, lr, pc} */
/* @0x2b1758 strb r0, [r4, r0, asr #16]! */
/* @0x2b175c strtmi r4, [r0], -r10, lsl #18 */
/* @0x2b1760 .word 0xf7f44479 */
/* @0x2b1764 strbmi pc, [r3], -r3, ror #28 */
/* @0x2b1768 strbtmi r4, [r9], -r0, lsr #12 */
/* @0x2b176c .word 0xf7ff462a */
/* @0x2b1770 .word 0xf8d4fda5 */
/* @0x2b1774 .word 0xf043312c */
/* @0x2b1778 .word 0xf8c40304 */
/* @0x2b177c andlt r3, r2, r12, lsr #2 */
/* @0x2b1780 ldrhhi lr, [r0, #141]! */
/* @0x2b1784 strheq lr, [sp], -r4 */
/* @0x2b1788 andeq r12, sp, r6, lsl #24 */
/* @0x2b178c andhs r4, r0, #11264 */
/* @0x2b1790 ldrbtmi r11, [r11], #-1299 */
/* @0x2b1794 strbtmi r4, [r9], -r4, lsl #12 */
/* @0x2b1798 svceq #0x17f853 */
/* @0x2b179c andls r7, r0, r11, lsl r9 */
/* @0x2b17a0 .word 0xf88d4620 */
/* @0x2b17a4 ldrmi r3, [r3], -r4 */
/* @0x2b17a8 stc2 p7, c15, [r8, #1020] */
/* @0x2b17ac .word 0x312cf8d4 */
/* @0x2b17b0 tsteq r0, #67 */
/* @0x2b17b4 smlawtlo r12, r4, r8, pc */
/* @0x2b17b8 ldclt p0, c11, [r0, #-8] */
/* @0x2b17bc andeq lr, sp, lr, asr #11 */
/* @0x2b17c0 blvc 0x2ed2a0 <FT_Done_Memory+0x362c> */
/* @0x2b17c4 blvs 0x6ece48 <g_SWFvertbuff+0x19d80> */
/* @0x2b17c8 blhs 0x82c8dc <b2_toiTime+0xd3438> */
/* @0x2b17cc ldrlt r4, [r0, #-0x910]! */
/* @0x2b17d0 .word 0x46054479 */
/* @0x2b17d4 .word 0xf851b085 */
/* @0x2b17d8 .word 0xac010f1c */
/* @0x2b17dc andls r7, r2, r9, lsl #18 */
/* @0x2b17e0 cdp p6, #0x0, c4, c5, c0, #0x1 */
/* @0x2b17e4 .word 0xf88d7b06 */
/* @0x2b17e8 cdp p0, #0xf, c1, c12, c12, #0x0 */
/* @0x2b17ec vnmla.f64 d5, d21, d7 */
/* @0x2b17f0 .word 0xf7ff1a90 */
/* @0x2b17f4 qadd8mi pc, r8, r7 */
/* @0x2b17f8 strtmi r10, [r2], -r2, lsl #18 */
/* @0x2b17fc .word 0xf7ff2304 */
/* @0x2b1800 andlt pc, r5, sp, asr sp */
/* @0x2b1804 svclt #0xbd30 */
/* @0x2b1808 andeq r0, r0, r0 */
/* @0x2b180c rscsmi r6, r8, r0, lsl #20 */
/* @0x2b1810 muleq sp, r0, r5 */
/* @0x2b1814 andhi pc, r0, pc, lsr #7 */
/* @0x2b1818 ldrlt r4, [r0, #-0xb0b]! */
/* @0x2b181c .word 0x4605447b */
/* @0x2b1820 .word 0xf853b085 */
/* @0x2b1824 .word 0xac010f1c */
/* @0x2b1828 andls r7, r2, r11, lsl r9 */
/* @0x2b182c .word 0xf88d4620 */
/* @0x2b1830 .word 0xf7ff300c */
/* @0x2b1834 qsub16mi pc, r8, r7 */
/* @0x2b1838 strtmi r10, [r2], -r2, lsl #18 */
/* @0x2b183c .word 0xf7ff2304 */
/* @0x2b1840 andlt pc, r5, sp, lsr sp */
/* @0x2b1844 svclt #0xbd30 */
/* @0x2b1848 andeq lr, sp, r4, asr #10 */
/* @0x2b184c stmdbhs r3, {r1, r2, r3, r8, r9, r11, lr} */
/* @0x2b1850 ldrbtmi r11, [r11], #-1328 */
/* @0x2b1854 addlt r4, r5, r4, lsl #12 */
/* @0x2b1858 svceq #0x21f853 */
/* @0x2b185c ldmdbvc r11, {r0, r2, r3, r9, r10, lr} */
/* @0x2b1860 .word 0xf88d9002 */
/* @0x2b1864 stcle p0, c3, [r4, #-48] */
/* @0x2b1868 strtmi r4, [r0], -r8, lsl #18 */
/* @0x2b186c .word 0xf7f44479 */
/* @0x2b1870 strtmi pc, [r0], -r1, lsl #28 */
/* @0x2b1874 bge 0x31bc84 */
/* @0x2b1878 .word 0xf88d2301 */
/* @0x2b187c .word 0xf7ff5004 */
/* @0x2b1880 andlt pc, r5, sp, lsl sp */
/* @0x2b1884 svclt #0xbd30 */
/* @0x2b1888 andeq lr, sp, lr, lsl #10 */
/* @0x2b188c andeq r12, sp, r11, lsr #22 */
/* @0x2b1890 mvnsmi lr, sp, lsr #18 */
/* @0x2b1894 blmi 0x10c3114 <b2_toiTime+0x969c70> */
/* @0x2b1898 addlt r4, r10, r4, lsl #12 */
/* @0x2b189c ldrbtmi r4, [r11], #-1680 */
/* @0x2b18a0 vldrls s20, [r0, #-8] */
/* @0x2b18a4 svceq #0x26f853 */
/* @0x2b18a8 andls r7, r3, r11, lsl r9 */
/* @0x2b18ac .word 0xf88d4620 */
/* @0x2b18b0 movwhs r3, #0x10 */
/* @0x2b18b4 movwls r9, #0x8307 */
/* @0x2b18b8 movwls r9, #0x5309 */
/* @0x2b18bc .word 0xf7fd9306 */
/* @0x2b18c0 .word 0x4607fe77 */
/* @0x2b18c4 subsle r2, r3, r0, lsl #16 */
/* @0x2b18c8 svceq #0xf1b8 */
/* @0x2b18cc stmdbmi r11!, {r2, r12, lr, pc} */
/* @0x2b18d0 ldrbtmi r4, [r9], #-1568 */
/* @0x2b18d4 stc2l p7, c15, [lr, #976] */
/* @0x2b18d8 stchs p1, c11, [r3, #-632] */
/* @0x2b18dc .word 0xf896dd12 */
/* @0x2b18e0 ldmdavc r3!, {r0, pc} */
/* @0x2b18e4 stmdami r8, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x2b18e8 stmdavs r3, {r3, r6, r9, r11, sp, lr, pc} */
/* @0x2b18ec b 0x14cfcc0 <b2_toiTime+0xd7681c> */
/* @0x2b18f0 ldmvc r3!, {r0, r1, r11} */
/* @0x2b18f4 stmdahs r3, {r3, r4, r6, r9, r11, sp, lr, pc} */
/* @0x2b18f8 stmdbmi r1!, {r1, r2, r8, r10, r12, lr, pc} */
/* @0x2b18fc ldrbtmi r4, [r9], #-1568 */
/* @0x2b1900 ldrtmi lr, [r5], -r7 */
/* @0x2b1904 stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2b1908 ble 0x402e24 <g_RomDisk+0xb604> */
/* @0x2b190c qadd16mi r4, r0, sp */
/* @0x2b1910 .word 0xf7f44479 */
/* @0x2b1914 eor pc, r7, pc, lsr #27 */
/* @0x2b1918 ldmdbmi r11, {r0, r2, r8, r10, r11, r12, lr, pc} */
/* @0x2b191c strbmi r4, [r5], -r0, lsr #12 */
/* @0x2b1920 .word 0xf7f44479 */
/* @0x2b1924 smlaltblt pc, r5, r7, sp */
/* @0x2b1928 strtmi r10, [r10], -r5, lsl #22 */
/* @0x2b192c strtmi r9, [r0], -r0, lsl #6 */
/* @0x2b1930 movwhs r4, #0x631 */
/* @0x2b1934 blx 0x36f93a <_ZTS13C_UTF16String+0x69e6> */
/* @0x2b1938 ldcne p6, c4, [lr], #20 */
/* @0x2b193c stmdbge r3, {r5, r9, r10, lr} */
/* @0x2b1940 .word 0xf7ff19aa */
/* @0x2b1944 blls 0x370a00 <_ZTS13C_UTF16String+0x7aac> */
/* @0x2b1948 ldrtmi r4, [r2], -r0, lsr #12 */
/* @0x2b194c movwhs r4, #0x41f */
/* @0x2b1950 stmdbls r2, {r0, r1, r3, r4, r5, r6, r12, sp, lr} */
/* @0x2b1954 mrrc2 p7, #0xf, pc, r6, c15 */
/* @0x2b1958 qadd16mi r11, r0, sp */
/* @0x2b195c .word 0xf7ffa905 */
/* @0x2b1960 strtmi pc, [r0], -r2, ror #24 */
/* @0x2b1964 ldc2 p7, c15, [r7], {255} */
/* @0x2b1968 stmdbls r2, {r5, r9, r10, lr} */
/* @0x2b196c .word 0xf9c6f7f5 */
/* @0x2b1970 pop {r1, r3, r12, sp, pc} */
/* @0x2b1974 svclt #0x81f0 */
/* @0x2b1978 andeq lr, sp, r2, asr #9 */
/* @0x2b197c andeq r12, sp, sp, ror #21 */
/* @0x2b1980 andeq r12, sp, r8, ror #21 */
/* @0x2b1984 andeq r12, sp, r8, lsl #22 */
/* @0x2b1988 andeq r12, sp, r8, lsr #22 */
/* @0x2b198c push {r0, r2, r6, r8, r9, r11, lr} */
/* @0x2b1990 ldrbtmi r4, [r11], #-4080 */
/* @0x2b1994 addlt r6, r9, r11, lsl r8 */
/* @0x2b1998 ldmdavs r10, {r1, r2, r9, r10, lr} */
/* @0x2b199c .word 0xf891460d */
/* @0x2b19a0 ldrmi r8, [r9], r4 */
/* @0x2b19a4 andls r6, r7, #13565952 */
/* @0x2b19a8 svceq #0x8f1b8 */
/* @0x2b19ac .word 0xf04fbf14 */
/* @0x2b19b0 .word 0xf04f080a */
/* @0x2b19b4 bmi 0x11b39d4 <b2_toiTime+0xa5a530> */
/* @0x2b19b8 ldrbtmi r6, [r10], #-2057 */
/* @0x2b19bc svceq #0x2bf852 */
/* @0x2b19c0 andls r7, r2, r2, lsl r9 */
/* @0x2b19c4 .word 0xf88d4630 */
/* @0x2b19c8 bge 0x2f9a00 <ps_hints_apply+0x8600> */
/* @0x2b19cc ldc2l p7, c15, [r0, #1012]! */
/* @0x2b19d0 stmdahs r0, {r2, r9, r10, lr} */
/* @0x2b19d4 stcne p0, c13, [r2], {92} */
/* @0x2b19d8 ldrtmi r10, [r0], -r2, lsl #18 */
/* @0x2b19dc beq 0x56db20 <g_SWFlineaavertbuff+0x1aa58> */
/* @0x2b19e0 andhs pc, r8, #7168 */
/* @0x2b19e4 blx 0xff9ef9ea <b2_toiTime+0xffffffffff296546> */
/* @0x2b19e8 ldrtmi r1, [r0], -r2, ror #24 */
/* @0x2b19ec .word 0xf7ff9901 */
/* @0x2b19f0 ldrtmi pc, [r0], -r9, lsl #24 */
/* @0x2b19f4 andhs r1, r1, #2624 */
/* @0x2b19f8 .word 0xfc04f7ff */
/* @0x2b19fc svcge #0x468ac */
/* @0x2b1a00 .word 0xf107340a */
/* @0x2b1a04 stmvs r10!, {r1, r8, r9, r11} ^ */
/* @0x2b1a08 smlatbeq r10, r4, r1, pc */
/* @0x2b1a0c blx 0x54bcc2 <gp_ActiveMaskObjects+0x6ffa> */
/* @0x2b1a10 addsmi r3, r9, #134217728 */
/* @0x2b1a14 stmdbvc r11!, {r0, r2, r4, r5, r9, r12, lr, pc} */
/* @0x2b1a18 tstle r1, r8, lsl #22 */
/* @0x2b1a1c .word 0x3c0af834 */
/* @0x2b1a20 .word 0xf88d1d38 */
/* @0x2b1a24 rfeda r4! */
/* @0x2b1a28 .word 0xf88d3c08 */
/* @0x2b1a2c rfeda r4! */
/* @0x2b1a30 .word 0xf88d3c06 */
/* @0x2b1a34 rfeda r4! */
/* @0x2b1a38 .word 0xf88d3c04 */
/* @0x2b1a3c ands r3, r5, r3, lsl r0 */
/* @0x2b1a40 rfeda r4! */
/* @0x2b1a44 .word 0xf7ff1c0a */
/* @0x2b1a48 usub16mi pc, r8, r7 */
/* @0x2b1a4c .word 0x1c08f834 */
/* @0x2b1a50 blx 0x1f6fa56 <b2_toiTime+0x18165b2> */
/* @0x2b1a54 rfeda r4! */
/* @0x2b1a58 .word 0xf7ff1c06 */
/* @0x2b1a5c .word 0x1db8fb6d */
/* @0x2b1a60 .word 0x1c04f834 */
/* @0x2b1a64 blx 0x1cefa6a <b2_toiTime+0x15965c6> */
/* @0x2b1a68 andeq pc, r8, r7, lsl #2 */
/* @0x2b1a6c .word 0x1c02f834 */
/* @0x2b1a70 .word 0xf7ff340a */
/* @0x2b1a74 ldrtmi pc, [r0], -r1, ror #22 */
/* @0x2b1a78 .word 0x46424639 */
/* @0x2b1a7c blx 0xff36fa82 <b2_toiTime+0xfffffffffec165de> */
/* @0x2b1a80 ldrtmi lr, [r0], -r1, asr #15 */
/* @0x2b1a84 .word 0xfc07f7ff */
/* @0x2b1a88 stmdbls r1, {r4, r5, r9, r10, lr} */
/* @0x2b1a8c rfedb r6! */
/* @0x2b1a90 .word 0xf8d99a07 */
/* @0x2b1a94 addsmi r3, r10, #0 */
/* @0x2b1a98 .word 0xf604d001 */
/* @0x2b1a9c mullt r9, r12, sp */
/* @0x2b1aa0 svchi #0xf0e8bd */
/* @0x2b1aa4 andseq r11, r3, r2, asr #31 */
/* @0x2b1aa8 andeq lr, sp, r6, lsr #7 */
/* @0x2b1aac .word 0x4604b57f */
/* @0x2b1ab0 ldrbtmi r4, [r11], #-2852 */
/* @0x2b1ab4 svceq #0x30f853 */
/* @0x2b1ab8 andls r7, r2, r11, lsl r9 */
/* @0x2b1abc .word 0xf88d0790 */
/* @0x2b1ac0 strle r3, [r0, #-0xc]! */
/* @0x2b1ac4 stmdavc lr, {r0, r1, r9, r11, sp} */
/* @0x2b1ac8 .word 0xf894bf14 */
/* @0x2b1acc movwhs r3, #0x81ec */
/* @0x2b1ad0 ldmdbmi sp, {r1, r2, r3, r5, r8, r11, r12, sp, pc} */
/* @0x2b1ad4 ldrbtmi r4, [r9], #-1568 */
/* @0x2b1ad8 stc2l p7, c15, [r12], {244} */
/* @0x2b1adc addsmi lr, lr, #48 */
/* @0x2b1ae0 stmdavc sp, {r0, r1, r2, r4, r5, r6, r7, r11, r12, lr, pc} ^ */
/* @0x2b1ae4 rscsle r2, r4, r0, lsl #26 */
/* @0x2b1ae8 ldmle r2!, {r0, r2, r3, r4, r7, r9, lr} ^ */
/* @0x2b1aec stmdahs r0, {r3, r7, r11, r12, sp, lr} */
/* @0x2b1af0 addsmi sp, r8, #239 */
/* @0x2b1af4 .word 0xf88dd8ed */
/* @0x2b1af8 movwhs r6, #0x3004 */
/* @0x2b1afc andpl pc, r5, sp, lsl #17 */
/* @0x2b1b00 andeq pc, r6, sp, lsl #17 */
/* @0x2b1b04 stmvc r11, {r0, r3, sp, lr, pc} ^ */
/* @0x2b1b08 rscle r2, r2, r0, lsl #22 */
/* @0x2b1b0c .word 0x01ecf894 */
/* @0x2b1b10 bicsle r4, lr, #152, #4 */
/* @0x2b1b14 andlo pc, r4, sp, lsl #17 */
/* @0x2b1b18 ldrbeq r2, [r2, -r1, lsl #6] */
/* @0x2b1b1c stmdbvc r10, {r0, r1, r3, r8, r10, r12, lr, pc} */
/* @0x2b1b20 sbcsle r2, r6, r0, lsl #20 */
/* @0x2b1b24 .word 0x11ecf894 */
/* @0x2b1b28 bicsle r4, r2, #268435465 */
/* @0x2b1b2c ldrmi r10, [r9], #-2308 */
/* @0x2b1b30 .word 0xf8013301 */
/* @0x2b1b34 strtmi r2, [r0], -r12, lsl #24 */
/* @0x2b1b38 bge 0x31bf48 */
/* @0x2b1b3c blx 0xff26fb42 <b2_toiTime+0xfffffffffeb1669e> */
/* @0x2b1b40 ldcllt p0, c11, [r0, #-16]! */
/* @0x2b1b44 andeq lr, sp, lr, lsr #5 */
/* @0x2b1b48 andeq r12, sp, r4, lsr #19 */
/* @0x2b1b4c andeq r0, r0, r0 */
/* @0x2b1b50 blvc 0x2ed630 <FT_Done_Memory+0x39bc> */
/* @0x2b1b54 blvs 0x186d1d8 <b2_toiTime+0x1113d34> */
/* @0x2b1b58 blhs 0x7ecc6c <b2_toiTime+0x937c8> */
/* @0x2b1b5c svcmi #0xf0e92d */
/* @0x2b1b60 blhi 0x3ed01c <af_avst_script_class+0xc> */
/* @0x2b1b64 .word 0xf8dfb093 */
/* @0x2b1b68 pkhtbmi r8, r1, r0, asr #2 */
/* @0x2b1b6c .word 0xf8d844f8 */
/* @0x2b1b70 .word 0xf8d88000 */
/* @0x2b1b74 strbmi r1, [r3], r0 */
/* @0x2b1b78 blpl 0x14ad640 <b2_toiTime+0xd5419c> */
/* @0x2b1b7c stmdbmi pc, {r0, r4, r8, r12, pc} ^ */
/* @0x2b1b80 blpl 0x46d398 <g_RomDisk+0x75b78> */
/* @0x2b1b84 .word 0xf8514479 */
/* @0x2b1b88 stmdbvc r9, {r0, r2, r4, r5, r8, r9, r10, r11} */
/* @0x2b1b8c strbmi r9, [r8], -r7 */
/* @0x2b1b90 eorne pc, r0, sp, lsl #17 */
/* @0x2b1b94 blmi 0xff42d78c <b2_toiTime+0xfffffffffecd42e8> */
/* @0x2b1b98 blpl 0xaed214 <b2_toiTime+0x393d70> */
/* @0x2b1b9c bmi 0xfe6ed3f4 <b2_toiTime+0xfffffffffdf93f50> */
/* @0x2b1ba0 blmi 0x14ad668 <b2_toiTime+0xd541c4> */
/* @0x2b1ba4 blmi 0x46d3c0 <g_RomDisk+0x75ba0> */
/* @0x2b1ba8 blpl 0xb6d224 <b2_toiTime+0x413d80> */
/* @0x2b1bac cdp p6, #0xf, c4, c12, c1, #0x1 */
/* @0x2b1bb0 vnmla.f64 d4, d20, d4 */
/* @0x2b1bb4 .word 0xeeb05a90 */
/* @0x2b1bb8 vmls.f64 d4, d5, d7 */
/* @0x2b1bbc vldr d4, [sp, #24] */
/* @0x2b1bc0 strtmi r5, [r10], -r4, lsr #22 */
/* @0x2b1bc4 blmi 0xff3ed7bc <b2_toiTime+0xfffffffffec94318> */
/* @0x2b1bc8 bvs 0xfe6ed420 <b2_toiTime+0xfffffffffdf93f7c> */
/* @0x2b1bcc blmi 0x14ad694 <b2_toiTime+0xd541f0> */
/* @0x2b1bd0 blmi 0x46d3ec <g_RomDisk+0x75bcc> */
/* @0x2b1bd4 blpl 0xc6d250 <b2_toiTime+0x513dac> */
/* @0x2b1bd8 mrc p6, #0x7, r4, c12, c3, #0x1 */
/* @0x2b1bdc vnmla.f64 d4, d20, d4 */
/* @0x2b1be0 .word 0xeeb07a90 */
/* @0x2b1be4 vmls.f64 d4, d5, d7 */
/* @0x2b1be8 vldr d4, [sp, #24] */
/* @0x2b1bec .word 0xeefc5b28 */
/* @0x2b1bf0 vnmla.f64 d4, d20, d4 */
/* @0x2b1bf4 .word 0xeeb0aa90 */
/* @0x2b1bf8 vmls.f64 d4, d5, d7 */
/* @0x2b1bfc vldr d4, [sp, #24] */
/* @0x2b1c00 stm sp, {r1, r3, r5, r8, r9, r11, r12, lr} */
/* @0x2b1c04 cdp p4, #0xb, c0, c12, c0, #0x4 */
/* @0x2b1c08 vabs.f64 d9, d4 */
/* @0x2b1c0c vstr d4, [sp, #284] */
/* @0x2b1c10 vmla.f32 s18, s10, s4 */
/* @0x2b1c14 vldr d4, [sp, #24] */
/* @0x2b1c18 vmla.f64 d5, d5, d28 */
/* @0x2b1c1c vmov.f64 d23, #-1.718750e-01 */
/* @0x2b1c20 vcvt.u32.f64 s16, d4 */
/* @0x2b1c24 vstr d24, [sp, #796] */
/* @0x2b1c28 vstr s16, [sp, #12] */
/* @0x2b1c2c .word 0xf7f48a04 */
/* @0x2b1c30 orrlt pc, r8, #110592 */
/* @0x2b1c34 stmdaeq r4!, {r0, r2, r3, r8, r12, sp, lr, pc} */
/* @0x2b1c38 strbmi r4, [r0], -r1, lsr #12 */
/* @0x2b1c3c blx 0x1f6fc40 <b2_toiTime+0x181679c> */
/* @0x2b1c40 andeq pc, r4, r8, lsl #2 */
/* @0x2b1c44 .word 0xf7ff4629 */
/* @0x2b1c48 .word 0xf108fa6d */
/* @0x2b1c4c ldrtmi r0, [r1], -r8 */
/* @0x2b1c50 blx 0x1cefc54 <b2_toiTime+0x15967b0> */
/* @0x2b1c54 andeq pc, r12, r8, lsl #2 */
/* @0x2b1c58 .word 0xf7ff4639 */
/* @0x2b1c5c .word 0xf108fa63 */
/* @0x2b1c60 uadd16mi r0, r1, r0 */
/* @0x2b1c64 blx 0x1a6fc68 <b2_toiTime+0x13167c4> */
/* @0x2b1c68 andseq pc, r4, r8, lsl #2 */
/* @0x2b1c6c bne 0x6ed4d8 <g_SWFvertbuff+0x1a410> */
/* @0x2b1c70 blx 0x18efc74 <b2_toiTime+0x11967d0> */
/* @0x2b1c74 andseq pc, r8, r8, lsl #2 */
/* @0x2b1c78 bne 0xfe6ed4e0 <b2_toiTime+0xfffffffffdf9403c> */
/* @0x2b1c7c blx 0x176fc80 <b2_toiTime+0x10167dc> */
/* @0x2b1c80 andseq pc, r12, r8, lsl #2 */
/* @0x2b1c84 bne 0x6ed4ec <g_SWFvertbuff+0x1a424> */
/* @0x2b1c88 blx 0x15efc8c <b2_toiTime+0xe967e8> */
/* @0x2b1c8c stmdbge r7, {r3, r6, r9, r10, lr} */
/* @0x2b1c90 .word 0x23204642 */
/* @0x2b1c94 blx 0x76fc9a <b2_toiTime+0x167f6> */
/* @0x2b1c98 .word 0xf8db9a11 */
/* @0x2b1c9c addsmi r3, r10, #0 */
/* @0x2b1ca0 .word 0xf604d001 */
/* @0x2b1ca4 mulslt r3, r8, r12 */
/* @0x2b1ca8 blhi 0x3ecfa4 <af_cari_script_class+0xc> */
/* @0x2b1cac svchi #0xf0e8bd */
/* @0x2b1cb0 andeq r0, r0, r0 */
/* @0x2b1cb4 rscsmi r6, r8, r0, lsl #20 */
/* @0x2b1cb8 andseq r11, r3, r8, ror #27 */
/* @0x2b1cbc ldrdeq lr, pc, [sp], -r12 */
/* @0x2b1cc0 svcmi #0xf0e92d */
/* @0x2b1cc4 stcmi p6, c4, [r12], #-20 */
/* @0x2b1cc8 .word 0xf8dfb093 */
/* @0x2b1ccc selmi lr, r8, r0 */
/* @0x2b1cd0 stmdavs r4!, {r2, r3, r4, r5, r6, r10, lr} */
/* @0x2b1cd4 ldrbtmi r9, [lr], #3869 */
/* @0x2b1cd8 stmdavs r0!, {r1, r2, r3, r4, r9, r10, r11, r12, pc} */
/* @0x2b1cdc .word 0x469a4693 */
/* @0x2b1ce0 strls r4, [r2], -r1, lsr #13 */
/* @0x2b1ce4 .word 0xf85e9011 */
/* @0x2b1ce8 andls r0, r7, r5, lsr pc */
/* @0x2b1cec muleq r4, lr, r8 */
/* @0x2b1cf0 eoreq pc, r0, sp, lsl #17 */
/* @0x2b1cf4 stm sp, {r2, r3, r4, r11, r12, pc} */
/* @0x2b1cf8 ldmdals pc, {r0, r7} */
/* @0x2b1cfc stmdals r0!, {r0, r1, r12, pc} */
/* @0x2b1d00 strtmi r9, [r8], -r4 */
/* @0x2b1d04 rfeib r0! */
/* @0x2b1d08 .word 0xac09b360 */
/* @0x2b1d0c strtmi r4, [r0], -r1, asr #12 */
/* @0x2b1d10 blx 0x4efd14 <SrcVerts+0x4cd58> */
/* @0x2b1d14 ldrbmi r1, [r9], -r0, lsr #26 */
/* @0x2b1d18 blx 0x3efd1c */
/* @0x2b1d1c andeq pc, r8, r4, lsl #2 */
/* @0x2b1d20 .word 0xf7ff4651 */
/* @0x2b1d24 .word 0xf104f9ff */
/* @0x2b1d28 ldmdbls r12, {r2, r3} */
/* @0x2b1d2c .word 0xf9faf7ff */
/* @0x2b1d30 andseq pc, r0, r4, lsl #2 */
/* @0x2b1d34 .word 0xf7ff4639 */
/* @0x2b1d38 .word 0xf104f9f5 */
/* @0x2b1d3c shadd16mi r0, r1, r4 */
/* @0x2b1d40 .word 0xf9f0f7ff */
/* @0x2b1d44 andseq pc, r8, r4, lsl #2 */
/* @0x2b1d48 .word 0xf7ff991f */
/* @0x2b1d4c .word 0xf104f9eb */
/* @0x2b1d50 stmdbls r0!, {r2, r3, r4} */
/* @0x2b1d54 .word 0xf9e6f7ff */
/* @0x2b1d58 stmdbge r7, {r3, r5, r9, r10, lr} */
/* @0x2b1d5c .word 0x23204622 */
/* @0x2b1d60 blx 0xfedefd64 <b2_toiTime+0xfffffffffe6968c0> */
/* @0x2b1d64 .word 0xf8d99a11 */
/* @0x2b1d68 addsmi r3, r10, #0 */
/* @0x2b1d6c .word 0xf604d001 */
/* @0x2b1d70 andslt lr, r3, r2, lsr r12 */
/* @0x2b1d74 svchi #0xf0e8bd */
/* @0x2b1d78 andseq r11, r3, r4, lsl #25 */
/* @0x2b1d7c andeq lr, sp, r10, lsl #1 */
/* @0x2b1d80 ssub8mi r11, r6, r0 */
/* @0x2b1d84 addlt r4, r5, lr, lsr #20 */
/* @0x2b1d88 strmi r4, [r12], r4, lsl #12 */
/* @0x2b1d8c stcls p4, c4, [r10, #-488] */
/* @0x2b1d90 svceq #0x3af852 */
/* @0x2b1d94 ldmdbvc r2, {r0, r1, r8, r10, r11, sp} */
/* @0x2b1d98 .word 0xf88d9000 */
/* @0x2b1d9c .word 0xd10c2004 */
/* @0x2b1da0 strtmi r2, [r0], -r0, lsl #22 */
/* @0x2b1da4 rfeia r4! */
/* @0x2b1da8 addsmi r2, r3, #220, #2 */
/* @0x2b1dac stmdbmi r5!, {r1, r8, r10, r11, r12, lr, pc} */
/* @0x2b1db0 sub r4, r1, r9, ror r4 */
/* @0x2b1db4 strbtmi r4, [r2], -r9, ror #12 */
/* @0x2b1db8 stmiblt r5!, {r3, r4, r5, sp, lr, pc} */
/* @0x2b1dbc .word 0x31ebf894 */
/* @0x2b1dc0 ldmdbhi r1!, {r0, r9, sp} */
/* @0x2b1dc4 vpmax.u8 d15, d3, d2 */
/* @0x2b1dc8 blle 0x382834 <_ZTS13C_UTF16String+0x198e0> */
/* @0x2b1dcc qadd16mi r4, r0, lr */
/* @0x2b1dd0 eors r4, r1, r9, ror r4 */
/* @0x2b1dd4 strtmi r10, [r8], -r2, lsl #26 */
/* @0x2b1dd8 .word 0xf9aef7ff */
/* @0x2b1ddc strbtmi r4, [r9], -r0, lsr #12 */
/* @0x2b1de0 movwhs r4, #0x262a */
/* @0x2b1de4 stchs p0, c14, [r2, #-136] */
/* @0x2b1de8 stcge p1, c13, [r2, #-140] */
/* @0x2b1dec qsub16mi r8, r8, r1 */
/* @0x2b1df0 .word 0xf9a2f7ff */
/* @0x2b1df4 ldmhi r1!, {r3, r5, r7, r10, r11, r12} */
/* @0x2b1df8 .word 0xf99ef7ff */
/* @0x2b1dfc ldmhi r1!, {r3, r5, r8, r10, r11, r12} ^ */
/* @0x2b1e00 .word 0xf99af7ff */
/* @0x2b1e04 .word 0x31ebf894 */
/* @0x2b1e08 blhs 0x4c3690 <SrcVerts+0x206d4> */
/* @0x2b1e0c .word 0xf89dd10b */
/* @0x2b1e10 .word 0xf89d3008 */
/* @0x2b1e14 tstmi r10, #10 */
/* @0x2b1e18 mullo r12, sp, r8 */
/* @0x2b1e1c andle r4, r2, r3, lsl r3 */
/* @0x2b1e20 ldrbtmi r4, [r9], #-2314 */
/* @0x2b1e24 strbtmi lr, [r9], -r8 */
/* @0x2b1e28 movwhs r4, #0x662a */
/* @0x2b1e2c blx 0x146fe30 <b2_toiTime+0xd1698c> */
/* @0x2b1e30 stmdbmi r7, {r2, sp, lr, pc} */
/* @0x2b1e34 ldrbtmi r4, [r9], #-1568 */
/* @0x2b1e38 blx 0x9efe12 <b2_toiTime+0x29696e> */
/* @0x2b1e3c ldcllt p0, c11, [r0, #20]! */
/* @0x2b1e40 ldrdeq sp, lr, [sp], -r4 */
/* @0x2b1e44 andeq r12, sp, r7, ror #13 */
/* @0x2b1e48 strdeq r12, sp, [sp], -r6 */
/* @0x2b1e4c andeq r12, sp, r4, ror #13 */
/* @0x2b1e50 andeq r12, sp, r0, lsl r7 */
/* @0x2b1e54 bhs 0x384b1c <_ZTS13C_UTF16String+0x1bbc8> */
/* @0x2b1e58 ldrbtmi r11, [r11], #-1520 */
/* @0x2b1e5c addlt r4, r5, r4, lsl #12 */
/* @0x2b1e60 svceq #0x3ff853 */
/* @0x2b1e64 ldmdbvc r11, {r0, r2, r3, r9, r10, lr} */
/* @0x2b1e68 .word 0xf88d9000 */
/* @0x2b1e6c tstle r4, r4 */
/* @0x2b1e70 ldrhhs pc, [r12, #132] */
/* @0x2b1e74 ldmdblt r10, {r0, r1, r3, r11, r12, sp, lr} */
/* @0x2b1e78 sbcsne pc, r12, #212, #16 */
/* @0x2b1e7c strle r0, [r5], #-1993 */
/* @0x2b1e80 movwle r4, #0x3293 */
/* @0x2b1e84 strtmi r4, [r0], -r5, lsr #18 */
/* @0x2b1e88 eors r4, r5, r9, ror r4 */
/* @0x2b1e8c strtmi r10, [r0], -r4, lsl #20 */
/* @0x2b1e90 .word 0xf8024669 */
/* @0x2b1e94 movwhs r3, #0x1d08 */
/* @0x2b1e98 .word 0x0793e039 */
/* @0x2b1e9c cdpge p5, #0x0, c13, c2, c1, #0x1 */
/* @0x2b1ea0 ldrtmi r8, [r0], -r9, asr #16 */
/* @0x2b1ea4 .word 0xf948f7ff */
/* @0x2b1ea8 stmhi r9!, {r4, r5, r7, r10, r11, r12} */
/* @0x2b1eac .word 0xf944f7ff */
/* @0x2b1eb0 stmhi r9!, {r4, r5, r8, r10, r11, r12} ^ */
/* @0x2b1eb4 .word 0xf940f7ff */
/* @0x2b1eb8 .word 0x31ebf894 */
/* @0x2b1ebc blhs 0x4c3744 <SrcVerts+0x20788> */
/* @0x2b1ec0 .word 0xf89dd10b */
/* @0x2b1ec4 .word 0xf89d3008 */
/* @0x2b1ec8 tstmi r10, #10 */
/* @0x2b1ecc mullo r12, sp, r8 */
/* @0x2b1ed0 andle r4, r2, r3, lsl r3 */
/* @0x2b1ed4 ldrbtmi r4, [r9], #-2322 */
/* @0x2b1ed8 strbtmi lr, [r9], -lr */
/* @0x2b1edc movwhs r4, #0x6632 */
/* @0x2b1ee0 .word 0xf894e015 */
/* @0x2b1ee4 andhs r3, r1, #-1073741766 */
/* @0x2b1ee8 blx 0x354314 */
/* @0x2b1eec addsmi pc, r9, #201326592 */
/* @0x2b1ef0 stmdbmi r12, {r0, r2, r8, r9, r11, r12, lr, pc} */
/* @0x2b1ef4 ldrbtmi r4, [r9], #-1568 */
/* @0x2b1ef8 blx 0xff1efed0 <b2_toiTime+0xfffffffffea96a2c> */
/* @0x2b1efc stcge p0, c14, [r2, #-36] */
/* @0x2b1f00 .word 0xf7ff4628 */
/* @0x2b1f04 qadd16mi pc, r0, r9 */
/* @0x2b1f08 strtmi r4, [r10], -r9, ror #12 */
/* @0x2b1f0c .word 0xf7ff2302 */
/* @0x2b1f10 .word 0xb005f9d5 */
/* @0x2b1f14 svclt #0xbdf0 */
/* @0x2b1f18 andeq sp, sp, r6, lsl #30 */
/* @0x2b1f1c andeq r12, sp, r5, ror #13 */
/* @0x2b1f20 strheq r12, [sp], -r8 */
/* @0x2b1f24 ldrdeq r12, sp, [sp], -r8 */
/* @0x2b1f28 mvnsmi lr, sp, lsr #18 */
/* @0x2b1f2c blmi 0x883744 <b2_toiTime+0x12a2a0> */
/* @0x2b1f30 ldrmi r4, [r6], -r8, lsl #13 */
/* @0x2b1f34 .word 0xf853447b */
/* @0x2b1f38 ldmdbvc r11, {r2, r6, r8, r9, r10, r11} */
/* @0x2b1f3c strtmi r9, [r0], -r2 */
/* @0x2b1f40 andlo pc, r12, sp, lsl #17 */
/* @0x2b1f44 ldrhlo pc, [r12, #132] */
/* @0x2b1f48 stcle p2, c4, [r4, #-616] */
/* @0x2b1f4c ldrbtmi r4, [r9], #-2320 */
/* @0x2b1f50 blx 0xfe6eff28 <b2_toiTime+0xfffffffffdf96a84> */
/* @0x2b1f54 stmdbge r2, {r1, r2, r4, sp, lr, pc} */
/* @0x2b1f58 .word 0xf7ff0052 */
/* @0x2b1f5c svcge #0x1f921 */
/* @0x2b1f60 adcsmi r2, r5, #0, #10 */
/* @0x2b1f64 rfeda r8! */
/* @0x2b1f68 shadd16mi r1, r8, r5 */
/* @0x2b1f6c .word 0xf8e4f7ff */
/* @0x2b1f70 ldrtmi r4, [r9], -r0, lsr #12 */
/* @0x2b1f74 .word 0xf7ff2202 */
/* @0x2b1f78 strlo pc, [r1, #-0x945] */
/* @0x2b1f7c qsub8mi lr, r0, r1 */
/* @0x2b1f80 .word 0xf989f7ff */
/* @0x2b1f84 pop {r2, r12, sp, pc} */
/* @0x2b1f88 svclt #0x81f0 */
/* @0x2b1f8c andeq sp, sp, r12, lsr #28 */
/* @0x2b1f90 andeq r12, sp, r0, asr #13 */
/* @0x2b1f94 ldrblt r4, [r0, #0xb1a]! */
/* @0x2b1f98 .word 0x4604447b */
/* @0x2b1f9c .word 0xf853b085 */
/* @0x2b1fa0 ldrmi r0, [r5], -r9, asr #30 */
/* @0x2b1fa4 ldmdbvc r11, {r0, r9, r11, sp, pc} */
/* @0x2b1fa8 strtmi r9, [r0], -r2 */
/* @0x2b1fac andlo pc, r12, sp, lsl #17 */
/* @0x2b1fb0 blx 0x26ffac <pcre_dfa_exec+0x1a44> */
/* @0x2b1fb4 movwlt r4, #0x607 */
/* @0x2b1fb8 stmdavc lr!, {r0, r2, r4, r5, r8, r12, sp, pc} */
/* @0x2b1fbc strtmi r11, [r8], -lr, lsr #2 */
/* @0x2b1fc0 b 0xff16f7d8 <b2_toiTime+0xfffffffffea16334> */
/* @0x2b1fc4 and r4, r0, r6, lsl #12 */
/* @0x2b1fc8 strlo r4, [r1, -lr, lsr #12] */
/* @0x2b1fcc stmdbge r2, {r5, r9, r10, lr} */
/* @0x2b1fd0 .word 0xf7ff19f2 */
/* @0x2b1fd4 strtmi pc, [r0], -r5, ror #17 */
/* @0x2b1fd8 ldrtmi r9, [r10], -r1, lsl #18 */
/* @0x2b1fdc .word 0xf912f7ff */
/* @0x2b1fe0 strtmi r11, [r0], -r6, lsr #2 */
/* @0x2b1fe4 ldrtmi r4, [r2], -r9, lsr #12 */
/* @0x2b1fe8 .word 0xf90cf7ff */
/* @0x2b1fec .word 0xf7ff4620 */
/* @0x2b1ff0 qsaxmi pc, r0, r2 */
/* @0x2b1ff4 .word 0xf7f49901 */
/* @0x2b1ff8 andlt pc, r5, r1, lsl #29 */
/* @0x2b1ffc svclt #0xbdf0 */
/* @0x2b2000 andeq sp, sp, r8, asr #27 */
/* @0x2b2004 push {r0, r1, r3, r5, r8, r9, r11, lr} */
/* @0x2b2008 ldrbtmi r4, [r11], #-496 */
/* @0x2b200c addlt r4, r12, r4, lsl #12 */
/* @0x2b2010 svceq #0x4ef853 */
/* @0x2b2014 andhs r4, r0, #22020096 */
/* @0x2b2018 andls r9, r10, #-1879048192 */
/* @0x2b201c andls r7, r5, r11, lsl r9 */
/* @0x2b2020 andls r4, r11, #32, #12 */
/* @0x2b2024 andls r9, r8, #1879048192 */
/* @0x2b2028 vnmlsls.f32 s20, s4, s8 */
/* @0x2b202c andslo pc, r8, sp, lsl #17 */
/* @0x2b2030 blx 0xff27002c <b2_toiTime+0xfffffffffeb16b88> */
/* @0x2b2034 cmplt r0, r7, lsl #12 */
/* @0x2b2038 stmdavc r11!, {r0, r2, r3, r4, r8, r12, sp, pc} */
/* @0x2b203c ldclne p1, c11, [r3], #-44 */
/* @0x2b2040 strtmi sp, [r0], -r10, lsl #2 */
/* @0x2b2044 strtmi r9, [r10], -r4, lsl #18 */
/* @0x2b2048 .word 0xf7ff2300 */
/* @0x2b204c strtmi pc, [r0], -r3, lsr #31 */
/* @0x2b2050 .word 0xf7f49904 */
/* @0x2b2054 eor pc, r9, r3, asr lr */
/* @0x2b2058 .word 0xf10d4628 */
/* @0x2b205c .word 0xf604081c */
/* @0x2b2060 ldrtmi lr, [r3], -r12, ror #20 */
/* @0x2b2064 .word 0xf8cd4629 */
/* @0x2b2068 strmi r8, [r2], -r0 */
/* @0x2b206c .word 0xf7fe4620 */
/* @0x2b2070 ldcne p15, c15, [r10], #404 */
/* @0x2b2074 strmi r10, [r2], #-2309 */
/* @0x2b2078 .word 0xf7ff4620 */
/* @0x2b207c ldclne p8, c15, [r10], #-580 */
/* @0x2b2080 stmdbls r4, {r5, r9, r10, lr} */
/* @0x2b2084 rfeia lr! */
/* @0x2b2088 stmdbls r4, {r5, r9, r10, lr} */
/* @0x2b208c mrc2 p7, #0x1, apsr_nzcv, c6, c4, #0x7 */
/* @0x2b2090 strtmi r10, [r0], -r12, lsl #18 */
/* @0x2b2094 .word 0xf8012201 */
/* @0x2b2098 .word 0xf7ff6d24 */
/* @0x2b209c .word 0x4620f8b3 */
/* @0x2b20a0 .word 0xf7ff4641 */
/* @0x2b20a4 strtmi pc, [r0], -r0, asr #17 */
/* @0x2b20a8 .word 0xf8f5f7ff */
/* @0x2b20ac pop {r2, r3, r12, sp, pc} */
/* @0x2b20b0 svclt #0x81f0 */
/* @0x2b20b4 andeq sp, sp, r6, asr sp */
/* @0x2b20b8 svcmi #0xf0e92d */
/* @0x2b20bc cdpmi p6, #0x4, c4, c4, c4, #0x0 */
/* @0x2b20c0 ldrmi r11, [r8], sp, lsl #1 */
/* @0x2b20c4 ldrbtmi r4, [lr], #-1673 */
/* @0x2b20c8 bge 0x3c3914 <error_g0017+0x1c5b8> */
/* @0x2b20cc .word 0xf8569d16 */
/* @0x2b20d0 svcls #0x170f53 */
/* @0x2b20d4 .word 0x26007933 */
/* @0x2b20d8 strtmi r9, [r0], -r5 */
/* @0x2b20dc .word 0xf88d9604 */
/* @0x2b20e0 .word 0x96093018 */
/* @0x2b20e4 strls r9, [r11], -r10, lsl #12 */
/* @0x2b20e8 .word 0xf7fd9607 */
/* @0x2b20ec strmi pc, [r2], r1, ror #20 */
/* @0x2b20f0 rsble r2, r10, r0, lsl #16 */
/* @0x2b20f4 strbmi r4, [r1], -r0, lsr #12 */
/* @0x2b20f8 .word 0xf7fdaa03 */
/* @0x2b20fc .word 0x4606fa59 */
/* @0x2b2100 ldmdbmi r4!, {r3, r5, r8, r11, r12, sp, pc} */
/* @0x2b2104 ldrbtmi r4, [r9], #-1568 */
/* @0x2b2108 rfeib r4! */
/* @0x2b210c .word 0xb1259603 */
/* @0x2b2110 .word 0xf6044628 */
/* @0x2b2114 pkhbtmi lr, r0, r2, lsl #20 */
/* @0x2b2118 strtmi lr, [r8], r0 */
/* @0x2b211c ldrtmi r11, [r8], -r7, lsr #2 */
/* @0x2b2120 b 0x56f938 <g_SWFlineaavertbuff+0x1c870> */
/* @0x2b2124 and r4, r0, r2, lsl #12 */
/* @0x2b2128 .word 0xf1a9463a */
/* @0x2b212c ldrtmi r0, [r9], -r2, lsl #6 */
/* @0x2b2130 bleq 0x9ee56c <b2_toiTime+0x2950c8> */
/* @0x2b2134 .word 0xf8cd4620 */
/* @0x2b2138 .word 0xf7feb000 */
/* @0x2b213c .word 0xf10afeff */
/* @0x2b2140 ldrtmi r0, [r2], #-517 */
/* @0x2b2144 strbmi r10, [r2], #-2309 */
/* @0x2b2148 strtmi r4, [r0], -r2, lsl #8 */
/* @0x2b214c .word 0xf828f7ff */
/* @0x2b2150 stmdbls r4, {r5, r9, r10, lr} */
/* @0x2b2154 andeq pc, r1, #-2147483646 */
/* @0x2b2158 .word 0xf854f7ff */
/* @0x2b215c svceq #0x1f1b9 */
/* @0x2b2160 .word 0xf1b9d002 */
/* @0x2b2164 strdle r3, r4, [r1, -pc] */
/* @0x2b2168 and r2, r0, r0, lsl #6 */
/* @0x2b216c svcge #0x22301 */
/* @0x2b2170 andhs r4, r2, #32, #12 */
/* @0x2b2174 andlo pc, r8, sp, lsl #17 */
/* @0x2b2178 .word 0xf04f4639 */
/* @0x2b217c .word 0xf88d0900 */
/* @0x2b2180 .word 0xf7ff9009 */
/* @0x2b2184 stmdbls r3, {r0, r1, r2, r3, r4, r5, r11, r12, sp, lr, pc} */
/* @0x2b2188 ldclne p6, c4, [r2], #-128 */
/* @0x2b218c andls pc, r8, sp, lsl #17 */
/* @0x2b2190 svclt #0x84549 */
/* @0x2b2194 .word 0xf7ff4639 */
/* @0x2b2198 .word 0xf108f835 */
/* @0x2b219c strtmi r0, [r0], -r1, lsl #4 */
/* @0x2b21a0 svclt #0x14454d */
/* @0x2b21a4 ldrtmi r4, [r9], -r9, lsr #12 */
/* @0x2b21a8 .word 0xf82cf7ff */
/* @0x2b21ac qsaxmi r4, r0, r9 */
/* @0x2b21b0 rfeda r9! */
/* @0x2b21b4 .word 0xf7ff4620 */
/* @0x2b21b8 strtmi pc, [r0], -lr, ror #16 */
/* @0x2b21bc .word 0xf7f49904 */
/* @0x2b21c0 qadd8mi pc, r0, sp */
/* @0x2b21c4 .word 0xf7f49903 */
/* @0x2b21c8 mullt sp, r9, sp */
/* @0x2b21cc svchi #0xf0e8bd */
/* @0x2b21d0 muleq sp, r10, r12 */
/* @0x2b21d4 andeq r12, sp, r6, lsr r5 */
/* @0x2b21d8 mvnsmi lr, #737280 */
/* @0x2b21dc .word 0x4c19461f */
/* @0x2b21e0 ldcmi p6, c4, [r9, #-24] */
/* @0x2b21e4 ldrbtmi r11, [r12], #-135 */
/* @0x2b21e8 svchs #0x16824 */
/* @0x2b21ec sxtab16mi r4, r9, sp, ror #8 */
/* @0x2b21f0 ldrmi r6, [r0], r3, lsr #16 */
/* @0x2b21f4 svceq #0x58f855 */
/* @0x2b21f8 stmdbvc r11!, {r0, r2, r8, r9, r12, pc} */
/* @0x2b21fc .word 0xf88d9000 */
/* @0x2b2200 stcle p0, c3, [r4, #-16] */
/* @0x2b2204 shadd16mi r4, r0, r1 */
/* @0x2b2208 .word 0xf7f44479 */
/* @0x2b220c stcge p9, c15, [r2, #-204] */
/* @0x2b2210 strtmi r4, [r8], -r9, asr #12 */
/* @0x2b2214 .word 0xff8ef7fe */
/* @0x2b2218 strbmi r1, [r1], -r8, lsr #26 */
/* @0x2b221c .word 0xff8af7fe */
/* @0x2b2220 movwhs r4, #0x962a */
/* @0x2b2224 uqasxmi r4, r9, r0 */
/* @0x2b2228 andsvc pc, r0, sp, lsl #17 */
/* @0x2b222c .word 0xf846f7ff */
/* @0x2b2230 stmdavs r3!, {r0, r2, r9, r11, r12, pc} */
/* @0x2b2234 mulle r1, r10, r2 */
/* @0x2b2238 stmib r12, {r2, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2b223c pop {r0, r1, r2, r12, sp, pc} */
/* @0x2b2240 svclt #0x83f0 */
/* @0x2b2244 andseq r11, r3, lr, ror #14 */
/* @0x2b2248 andeq sp, sp, r4, ror r11 */
/* @0x2b224c andeq r12, sp, r7, asr r4 */
/* @0x2b2250 svcmi #0xf0e92d */
/* @0x2b2254 strmi r11, [r4], -pc, lsl #1 */
/* @0x2b2258 movwls r4, #0x460e */
/* @0x2b225c andls r4, r3, #71680 */
/* @0x2b2260 ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr} */
/* @0x2b2264 ldcls p9, c9, [r9, #-96] */
/* @0x2b2268 stmdbhs r3, {r1, r3, r4, r11, sp, lr} */
/* @0x2b226c .word 0x9068f8dd */
/* @0x2b2270 andls r9, sp, #27, #30 */
/* @0x2b2274 movwls r4, #0x5a41 */
/* @0x2b2278 .word 0xf852447a */
/* @0x2b227c ldmdbvc r2, {r0, r2, r3, r4, r6, r8, r9, r10, r11} */
/* @0x2b2280 .word 0xf88d9008 */
/* @0x2b2284 stcle p0, c2, [r4, #-144] */
/* @0x2b2288 qasxmi r4, r0, sp */
/* @0x2b228c .word 0xf7f44479 */
/* @0x2b2290 shsub8mi pc, r1, r1 */
/* @0x2b2294 strtmi r10, [r0], -r7, lsl #20 */
/* @0x2b2298 .word 0xf98af7fd */
/* @0x2b229c beq 0x32e6a4 */
/* @0x2b22a0 .word 0xf6044648 */
/* @0x2b22a4 adceq lr, r9, r10, asr #18 */
/* @0x2b22a8 svclt #0xc2d00 */
/* @0x2b22ac cps #0x0 */
/* @0x2b22b0 strtmi r0, [r0], -r1, lsl #16 */
/* @0x2b22b4 andeq lr, r8, #10240 */
/* @0x2b22b8 bleq 0x56e6c8 <g_SWFlineaavertbuff+0x1b600> */
/* @0x2b22bc ldc2l p7, c15, [r0], #976 */
/* @0x2b22c0 movwhs r1, #0xe69 */
/* @0x2b22c4 adcmi r4, r11, #6291456 */
/* @0x2b22c8 .word 0xf857da0f */
/* @0x2b22cc .word 0x91010023 */
/* @0x2b22d0 .word 0xf6049302 */
/* @0x2b22d4 blls 0x36c7a4 <_ZTS13C_UTF16String+0x3850> */
/* @0x2b22d8 addmi r9, r11, #16384 */
/* @0x2b22dc andlo r11, r1, r8, lsl pc */
/* @0x2b22e0 eoreq pc, r3, r6, asr #16 */
/* @0x2b22e4 movwlo r4, #0x1483 */
/* @0x2b22e8 strtmi lr, [r0], -sp, ror #15 */
/* @0x2b22ec ldrbmi r10, [r10], -r8, lsl #18 */
/* @0x2b22f0 .word 0xff56f7fe */
/* @0x2b22f4 .word 0xf10d4652 */
/* @0x2b22f8 strtmi r0, [r0], -r8, lsr #20 */
/* @0x2b22fc .word 0xf7fe9907 */
/* @0x2b2300 ldrbmi pc, [r0], -r1, lsl #31 */
/* @0x2b2304 .word 0xf7fe9903 */
/* @0x2b2308 .word 0xf10aff15 */
/* @0x2b230c stmdbls r4, {r2} */
/* @0x2b2310 .word 0xff10f7fe */
/* @0x2b2314 qadd16mi r9, r0, r8 */
/* @0x2b2318 andhs r4, r10, #84934656 */
/* @0x2b231c eorspl pc, r1, sp, lsl #17 */
/* @0x2b2320 eorslo pc, r0, sp, lsl #17 */
/* @0x2b2324 .word 0xff6ef7fe */
/* @0x2b2328 strtmi r4, [r0], -r2, asr #12 */
/* @0x2b232c .word 0xf04f4649 */
/* @0x2b2330 .word 0xf7fe0800 */
/* @0x2b2334 strtmi pc, [r0], -r7, ror #30 */
/* @0x2b2338 .word 0xf7f49907 */
/* @0x2b233c strmi pc, [r8, #0xcdf]! */
/* @0x2b2340 ble 0x4c3bc8 <SrcVerts+0x20c0c> */
/* @0x2b2344 eorne pc, r8, r7, asr r8 */
/* @0x2b2348 eorhs pc, r8, r6, asr r8 */
/* @0x2b234c stmdaeq r1, {r3, r8, r12, sp, lr, pc} */
/* @0x2b2350 .word 0xff58f7fe */
/* @0x2b2354 shsub8mi lr, r1, r3 */
/* @0x2b2358 ldc2l p7, c15, [r0], {244} */
/* @0x2b235c .word 0xf7fe4620 */
/* @0x2b2360 stmdbls r5, {r1, r3, r4, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2b2364 stmdavs r11, {r0, r2, r3, r9, r11, r12, pc} */
/* @0x2b2368 mulle r1, r10, r2 */
/* @0x2b236c ldmdb r2!, {r2, r9, r10, r12, sp, lr, pc} */
/* @0x2b2370 pop {r0, r1, r2, r3, r12, sp, pc} */
/* @0x2b2374 svclt #0x8ff0 */
/* @0x2b2378 ldrsheq r11, [r3], -r4 */
/* @0x2b237c andeq sp, sp, r8, ror #21 */
/* @0x2b2380 andeq r11, sp, r10, lsl r3 */
/* @0x2b2384 svcmi #0xf0e92d */
/* @0x2b2388 svcmi #0x204682 */
/* @0x2b238c stcmi p0, c11, [r0], #-604 */
/* @0x2b2390 ldrbtmi r10, [pc], #-3606 */
/* @0x2b2394 .word 0xf8df683f */
/* @0x2b2398 ldrbtmi r11, [r12], #-124 */
/* @0x2b239c stclne p8, c15, [r4, #-24] */
/* @0x2b23a0 ldrbtmi r6, [r11], #2104 */
/* @0x2b23a4 movwhs lr, #0x9cd */
/* @0x2b23a8 uasxmi r2, r10, pc */
/* @0x2b23ac .word 0xf8549015 */
/* @0x2b23b0 andls r0, r3, r2, ror #30 */
/* @0x2b23b4 ldclne p9, c7, [r4], #-128 */
/* @0x2b23b8 andseq pc, r0, sp, lsl #17 */
/* @0x2b23bc .word 0xf6044620 */
/* @0x2b23c0 strtmi lr, [r0], -r4, lsl #18 */
/* @0x2b23c4 ldm r8!, {r2, r9, r10, r12, sp, lr, pc} */
/* @0x2b23c8 strmi lr, [r0, #-0x9dd]! */
/* @0x2b23cc stmib sp, {r1, r3, r4, r6, r9, r10, lr} ^ */
/* @0x2b23d0 .word 0xf1004500 */
/* @0x2b23d4 strmi r0, [r1], -r2, lsl #16 */
/* @0x2b23d8 stmdbeq r8, {r1, r2, r8, r9, r11, sp, lr, pc} */
/* @0x2b23dc teqeq lr, r1, asr #3 */
/* @0x2b23e0 .word 0xf6044648 */
/* @0x2b23e4 .word 0x4648e8f2 */
/* @0x2b23e8 stm r6!, {r2, r9, r10, r12, sp, lr, pc} */
/* @0x2b23ec stmdbge r3, {r1, r4, r5, r9, r10, lr} */
/* @0x2b23f0 movweq lr, #0xb08 */
/* @0x2b23f4 .word 0xf7fe4650 */
/* @0x2b23f8 bls 0x832184 <b2_toiTime+0xd8ce0> */
/* @0x2b23fc addsmi r6, r10, #3866624 */
/* @0x2b2400 .word 0xf604d001 */
/* @0x2b2404 andslt lr, r7, r8, ror #17 */
/* @0x2b2408 svchi #0xf0e8bd */
/* @0x2b240c andseq r11, r3, r2, asr #11 */
/* @0x2b2410 andeq sp, sp, r6, asr #19 */
/* @0x2b2414 andeq r12, sp, r3, ror #5 */
/* @0x2b2418 mvnsmi lr, #737280 */
/* @0x2b241c .word 0x4c19461f */
/* @0x2b2420 ldcmi p6, c4, [r9, #-24] */
/* @0x2b2424 ldrbtmi r11, [r12], #-135 */
/* @0x2b2428 svchs #0x16824 */
/* @0x2b242c sxtab16mi r4, r9, sp, ror #8 */
/* @0x2b2430 ldrmi r6, [r0], r3, lsr #16 */
/* @0x2b2434 svceq #0x67f855 */
/* @0x2b2438 stmdbvc r11!, {r0, r2, r8, r9, r12, pc} */
/* @0x2b243c .word 0xf88d9000 */
/* @0x2b2440 stcle p0, c3, [r4, #-16] */
/* @0x2b2444 shadd16mi r4, r0, r1 */
/* @0x2b2448 .word 0xf7f44479 */
/* @0x2b244c stcge p8, c15, [r2, #-76] */
/* @0x2b2450 strtmi r4, [r8], -r9, asr #12 */
/* @0x2b2454 mcr2 p7, #0x3, pc, c6, c14, #0x7 */
/* @0x2b2458 strbmi r1, [r1], -r8, lsr #26 */
/* @0x2b245c mcr2 p7, #0x3, pc, c2, c14, #0x7 */
/* @0x2b2460 movwhs r4, #0x962a */
/* @0x2b2464 uqasxmi r4, r9, r0 */
/* @0x2b2468 andsvc pc, r0, sp, lsl #17 */
/* @0x2b246c .word 0xff26f7fe */
/* @0x2b2470 stmdavs r3!, {r0, r2, r9, r11, r12, pc} */
/* @0x2b2474 mulle r1, r10, r2 */
/* @0x2b2478 stm r12!, {r2, r9, r10, r12, sp, lr, pc} */
/* @0x2b247c pop {r0, r1, r2, r12, sp, pc} */
/* @0x2b2480 svclt #0x83f0 */
/* @0x2b2484 andseq r11, r3, lr, lsr #10 */
/* @0x2b2488 andeq sp, sp, r4, lsr r9 */
/* @0x2b248c andeq r12, sp, r5, asr #4 */
/* @0x2b2490 .word 0x4606b57f */
/* @0x2b2494 .word 0x460c4b1c */
/* @0x2b2498 .word 0xf853447b */
/* @0x2b249c ldmdbvc r11, {r2, r3, r5, r6, r8, r9, r10, r11} */
/* @0x2b24a0 .word 0xf88d9000 */
/* @0x2b24a4 stmvc r11, {r2, r12, sp} */
/* @0x2b24a8 blhs 0x5810b4 <g_SWFlineaavertbuff+0x2dfec> */
/* @0x2b24ac stmvc r11, {r0, r3, r11, r12, lr, pc} ^ */
/* @0x2b24b0 blhs 0xa410bc <b2_toiTime+0x2e7c18> */
/* @0x2b24b4 stmdbvc r11, {r0, r2, r11, r12, lr, pc} */
/* @0x2b24b8 stmdale r2, {r0, r1, r2, r4, r8, r9, r11, sp} */
/* @0x2b24bc blhs 0x11d0af0 <b2_toiTime+0xa7764c> */
/* @0x2b24c0 ldmdbmi r2, {r0, r2, r8, r11, r12, lr, pc} */
/* @0x2b24c4 ldrbtmi r4, [r9], #-1584 */
/* @0x2b24c8 .word 0xffd4f7f3 */
/* @0x2b24cc stcge p0, c14, [r2, #-100] */
/* @0x2b24d0 strtmi r8, [r8], -r9, lsl #16 */
/* @0x2b24d4 mrc2 p7, #0x1, apsr_nzcv, c0, c14, #0x7 */
/* @0x2b24d8 ldrtmi r7, [r0], -r3, lsr #17 */
/* @0x2b24dc strtmi r4, [r10], -r9, ror #12 */
/* @0x2b24e0 andlo pc, r10, sp, lsl #17 */
/* @0x2b24e4 .word 0xf88d78e3 */
/* @0x2b24e8 stmdbvc r3!, {r0, r1, r3, r12, sp} */
/* @0x2b24ec andlo pc, r12, sp, lsl #17 */
/* @0x2b24f0 .word 0xf88d7963 */
/* @0x2b24f4 stmibvc r3!, {r0, r2, r3, r12, sp} */
/* @0x2b24f8 andlo pc, lr, sp, lsl #17 */
/* @0x2b24fc .word 0xf7fe2307 */
/* @0x2b2500 .word 0xb004fedd */
/* @0x2b2504 svclt #0xbd70 */
/* @0x2b2508 andeq sp, sp, r8, asr #17 */
/* @0x2b250c andeq r12, sp, sp, ror #3 */
/* @0x2b2510 .word 0x4604b538 */
/* @0x2b2514 .word 0x51eff890 */
/* @0x2b2518 .word 0x31ecf890 */
/* @0x2b251c .word 0x218cf8d0 */
/* @0x2b2520 .word 0xf303fb15 */
/* @0x2b2524 vstrle d2, [r2, #-28] */
/* @0x2b2528 cmpmi r5, #14483456 */
/* @0x2b252c blx 0x36a542 <_ZTS13C_UTF16String+0x15ee> */
/* @0x2b2530 strlo pc, [r7, #-0x503] */
/* @0x2b2534 strlo r0, [r1, #-0x8ed] */
/* @0x2b2538 strtmi r4, [r9], -r0, lsr #12 */
/* @0x2b253c blx 0xfeef0516 <b2_toiTime+0xfffffffffe797072> */
/* @0x2b2540 .word 0xf8c42300 */
/* @0x2b2544 strhvc r0, [r3], -r0 */
/* @0x2b2548 .word 0x31e9f894 */
/* @0x2b254c strle r0, [r9, #-0x6db] */
/* @0x2b2550 ldrsbne pc, [r12, r4] */
/* @0x2b2554 .word 0x31014620 */
/* @0x2b2558 blx 0xfeb70532 <b2_toiTime+0xfffffffffe41708e> */
/* @0x2b255c .word 0xf8c42301 */
/* @0x2b2560 strhvc r0, [r3], -r4 */
/* @0x2b2564 .word 0x31e9f894 */
/* @0x2b2568 svceq #0xe0f013 */
/* @0x2b256c strtmi sp, [r9], -pc, lsr #32 */
/* @0x2b2570 .word 0xf7f44620 */
/* @0x2b2574 .word 0xf894fbb1 */
/* @0x2b2578 ldreq r3, [sp], r9, ror #3 */
/* @0x2b257c .word 0x01acf8c4 */
/* @0x2b2580 .word 0xf8d4d509 */
/* @0x2b2584 qadd8mi r1, r0, r12 */
/* @0x2b2588 .word 0xf7f43101 */
/* @0x2b258c movwhs pc, #0x2b89 */
/* @0x2b2590 .word 0x01b8f8c4 */
/* @0x2b2594 .word 0xf8947003 */
/* @0x2b2598 ldrbeq r3, [r8], -r9, ror #3 */
/* @0x2b259c .word 0xf8d4d509 */
/* @0x2b25a0 qadd8mi r1, r0, r12 */
/* @0x2b25a4 .word 0xf7f43101 */
/* @0x2b25a8 movwhs pc, #0x3b7b */
/* @0x2b25ac .word 0x01bcf8c4 */
/* @0x2b25b0 .word 0xf9947003 */
/* @0x2b25b4 blhs 0x2bed60 <jpeg_huff_decode+0x1d4> */
/* @0x2b25b8 .word 0xf8d4da09 */
/* @0x2b25bc qadd8mi r1, r0, r12 */
/* @0x2b25c0 .word 0xf7f43101 */
/* @0x2b25c4 movwhs pc, #0x4b6d */
/* @0x2b25c8 biceq pc, r0, r4, asr #17 */
/* @0x2b25cc .word 0xf8947003 */
/* @0x2b25d0 .word 0xf8d411e7 */
/* @0x2b25d4 .word 0xf8d4318c */
/* @0x2b25d8 .word 0xb1512190 */
/* @0x2b25dc ldrsbne pc, [r4, -r4]! */
/* @0x2b25e0 strle r0, [r6], #-1929 */
/* @0x2b25e4 movwlo r3, #0x7207 */
/* @0x2b25e8 ldmeq r11, {r1, r4, r6, r7, r11} ^ */
/* @0x2b25ec orrshs pc, r4, r4, asr #17 */
/* @0x2b25f0 .word 0xf8c4e001 */
/* @0x2b25f4 .word 0xf8c42194 */
/* @0x2b25f8 .word 0xf8d43198 */
/* @0x2b25fc .word 0xf8c43174 */
/* @0x2b2600 .word 0xf8d43148 */
/* @0x2b2604 .word 0xf8c43170 */
/* @0x2b2608 ldclt p1, c3, [r8, #-272]! */
/* @0x2b260c .word 0x4604b5f0 */
/* @0x2b2610 addslt r4, sp, r0, ror #28 */
/* @0x2b2614 uqsub16mi r4, sp, lr */
/* @0x2b2618 ldrbeq pc, [r4, -r6, lsl #2]! */
/* @0x2b261c strgt r12, [pc, #-0xf0f] */
/* @0x2b2620 muleq r7, r7, r8 */
/* @0x2b2624 ldreq pc, [r0, r6, lsl #2] */
/* @0x2b2628 andeq lr, r7, r5, lsl #17 */
/* @0x2b262c svcgt #0xfad07 */
/* @0x2b2630 ldm r7, {r0, r1, r2, r3, r8, r10, lr, pc} */
/* @0x2b2634 .word 0xf1060007 */
/* @0x2b2638 strblo r0, [r8], r12, lsr #15 */
/* @0x2b263c andeq lr, r7, r5, lsl #17 */
/* @0x2b2640 svcgt #0xfad0e */
/* @0x2b2644 ldm r7, {r0, r1, r2, r3, r8, r10, lr, pc} */
/* @0x2b2648 stm r5, {r0, r1, r2} */
/* @0x2b264c ldcge p0, c0, [r5, #-28] */
/* @0x2b2650 strgt r12, [pc, #-0xe0f] */
/* @0x2b2654 muleq r7, r6, r8 */
/* @0x2b2658 .word 0x31a8f8d4 */
/* @0x2b265c .word 0xf8c43301 */
/* @0x2b2660 stm r5, {r3, r5, r7, r8, r12, sp} */
/* @0x2b2664 .word 0xf8d40007 */
/* @0x2b2668 addsmi r2, r3, #148, #2 */
/* @0x2b266c addshi pc, r0, r0, asr #1 */
/* @0x2b2670 .word 0x31e7f894 */
/* @0x2b2674 subsle r2, r2, r0, lsl #22 */
/* @0x2b2678 .word 0xf8c42300 */
/* @0x2b267c .word 0xf8d431a8 */
/* @0x2b2680 .word 0xf8943134 */
/* @0x2b2684 .word 0xf01351e8 */
/* @0x2b2688 eorle r0, r0, r2, lsl #30 */
/* @0x2b268c eor r3, r5, r1, lsl #10 */
/* @0x2b2690 bl 0x39d308 <ft_adobe_glyph_list+0xc9e4> */
/* @0x2b2694 .word 0xf8d40685 */
/* @0x2b2698 .word 0xf856318c */
/* @0x2b269c bllo 0x2f97f4 <ps_hints_apply+0x83f4> */
/* @0x2b26a0 .word 0xf8561858 */
/* @0x2b26a4 bne 0xff2c186c <b2_toiTime+0xfffffffffeb683c8> */
/* @0x2b26a8 b 0xff66e848 <b2_toiTime+0xfffffffffef153a4> */
/* @0x2b26ac ldrsblo pc, [r0, r4] */
/* @0x2b26b0 .word 0x1c1cf856 */
/* @0x2b26b4 .word 0xf8563b01 */
/* @0x2b26b8 .word 0xf8c42c38 */
/* @0x2b26bc .word 0x46070198 */
/* @0x2b26c0 bne 0xfe2b8828 <b2_toiTime+0xfffffffffdb5f384> */
/* @0x2b26c4 b 0xff2ee864 <b2_toiTime+0xfffffffffeb953c0> */
/* @0x2b26c8 orrseq pc, r4, r4, asr #17 */
/* @0x2b26cc strlo r11, [r1, #-0x927] */
/* @0x2b26d0 stchs p2, c11, [r6, #-948] */
/* @0x2b26d4 ldrd sp, lr, [r1], -r12 */
/* @0x2b26d8 rscsle r2, r8, r0, lsl #16 */
/* @0x2b26dc mvnpl pc, r4, lsl #17 */
/* @0x2b26e0 .word 0x31e8f894 */
/* @0x2b26e4 ldmdale r10, {r1, r2, r8, r9, r11, sp} */
/* @0x2b26e8 .word 0x01acf8d4 */
/* @0x2b26ec suble r2, pc, r0, lsl #16 */
/* @0x2b26f0 .word 0x21eff894 */
/* @0x2b26f4 .word 0x31ecf894 */
/* @0x2b26f8 .word 0xf303fb12 */
/* @0x2b26fc .word 0x218cf8d4 */
/* @0x2b2700 vstrle d2, [r2, #-28] */
/* @0x2b2704 cmpmi r10, #14352384 */
/* @0x2b2708 cmpmi r10, #2 */
/* @0x2b270c ldmeq r2, {r0, r1, r2, r9, r12, sp} ^ */
/* @0x2b2710 .word 0x21003201 */
/* @0x2b2714 pop {r0, r2, r3, r4, r12, sp, pc} */
/* @0x2b2718 .word 0xf06940f0 */
/* @0x2b271c mrcmi p9, #0x0, r11, c14, c7, #0x6 */
/* @0x2b2720 ldrvc pc, [r12, #0x504] */
/* @0x2b2724 qsub16mi r4, r8, lr */
/* @0x2b2728 .word 0xf6042104 */
/* @0x2b272c ldmiblt r8, {r6, r8, r11, sp, lr, pc} */
/* @0x2b2730 .word 0x3148f8d4 */
/* @0x2b2734 mvnsle r2, r0, lsl #22 */
/* @0x2b2738 .word 0xf8d44620 */
/* @0x2b273c .word 0xf8d41170 */
/* @0x2b2740 .word 0xf7fe2174 */
/* @0x2b2744 .word 0xf8d4ffad */
/* @0x2b2748 .word 0xf8c43170 */
/* @0x2b274c .word 0xf8d43144 */
/* @0x2b2750 .word 0xf8c43174 */
/* @0x2b2754 strb r3, [r6, r8, asr #2]! */
/* @0x2b2758 andle r2, r7, r1, lsl #16 */
/* @0x2b275c ldrsbne pc, [r0, #-132] */
/* @0x2b2760 stmdblt r1, {r5, r9, r10, lr} */
/* @0x2b2764 .word 0xf7f34631 */
/* @0x2b2768 ldrb pc, [r12, r1, ror #28] */
/* @0x2b276c .word 0x3148f8d4 */
/* @0x2b2770 ldrsbhs pc, [r4, #-132]! */
/* @0x2b2774 andle r4, r5, #805306377 */
/* @0x2b2778 .word 0xf8d44620 */
/* @0x2b277c bne 0xff736d44 <b2_toiTime+0xfffffffffefdd8a0> */
/* @0x2b2780 .word 0xff8ef7fe */
/* @0x2b2784 .word 0xf6044628 */
/* @0x2b2788 movwhs lr, #0xbe8 */
/* @0x2b278c smulbtlo r4, r4, r8 */
/* @0x2b2790 ldcllt p0, c11, [r0, #116]! */
/* @0x2b2794 andeq sp, sp, r12, asr #14 */
/* @0x2b2798 andeq r11, sp, r9, asr r8 */
/* @0x2b279c ldrbmi lr, [r0, sp, lsr #18]! */
/* @0x2b27a0 stclmi p6, c4, [r5, #-592]! */
/* @0x2b27a4 strmi r4, [pc], -r0, lsl #13 */
/* @0x2b27a8 ldrbtmi r11, [sp], #-142 */
/* @0x2b27ac svceq #0x5f1bc */
/* @0x2b27b0 ldrbteq pc, [r4], -r5, lsl #2 */
/* @0x2b27b4 .word 0xf105466c */
/* @0x2b27b8 mcrgt p5, #0x0, r0, c15, c0, #0x4 */
/* @0x2b27bc ldm r6, {r0, r1, r2, r3, r10, lr, pc} */
/* @0x2b27c0 stm r4, {r0, r1, r2} */
/* @0x2b27c4 .word 0xac070007 */
/* @0x2b27c8 strgt r12, [pc], #-3343 */
/* @0x2b27cc muleq r7, r5, r8 */
/* @0x2b27d0 andeq lr, r7, r4, lsl #17 */
/* @0x2b27d4 adchi pc, r12, r0, lsl #6 */
/* @0x2b27d8 mullo r11, r8, r8 */
/* @0x2b27dc streq lr, [r12], #2639 */
/* @0x2b27e0 .word 0x5000f8d8 */
/* @0x2b27e4 eorle r2, r6, r2, lsl #22 */
/* @0x2b27e8 suble r2, r8, r4, lsl #22 */
/* @0x2b27ec .word 0xd16c2b01 */
/* @0x2b27f0 ldrtmi r10, [lr], -lr, lsl #16 */
/* @0x2b27f4 andhs r4, r0, #32, #8 */
/* @0x2b27f8 .word 0xf8502307 */
/* @0x2b27fc .word 0x46861c38 */
/* @0x2b2800 andsle r4, r6, #-1879048182 */
/* @0x2b2804 .word 0xf81708c8 */
/* @0x2b2808 bicmi r12, r8, #0 */
/* @0x2b280c andeq pc, r7, r0 */
/* @0x2b2810 .word 0xf000fa4c */
/* @0x2b2814 andeq pc, r1, r0 */
/* @0x2b2818 movwmi r4, #0x2098 */
/* @0x2b281c eorsvc r11, r2, r3, lsr #18 */
/* @0x2b2820 .word 0x3601461a */
/* @0x2b2824 and r2, r0, r7, lsl #6 */
/* @0x2b2828 .word 0xf85e3b01 */
/* @0x2b282c strmi r0, [r1], #-3100 */
/* @0x2b2830 blhs 0x4ac7d0 <SrcVerts+0x9814> */
/* @0x2b2834 stmdage lr, {r1, r2, r6, sp, lr, pc} */
/* @0x2b2838 strtmi r4, [r0], #-1598 */
/* @0x2b283c movwhs r2, #0x6200 */
/* @0x2b2840 ldcne p8, c15, [r8], #-320 */
/* @0x2b2844 adcmi r4, r9, #140509184 */
/* @0x2b2848 stmeq r8, {r0, r1, r2, r4, r9, r12, lr, pc} */
/* @0x2b284c andgt pc, r0, r7, lsl r8 */
/* @0x2b2850 .word 0xf00043c8 */
/* @0x2b2854 subeq r0, r0, r3 */
/* @0x2b2858 .word 0xf000fa4c */
/* @0x2b285c andeq pc, r3, r0 */
/* @0x2b2860 movwmi r4, #0x2098 */
/* @0x2b2864 eorsvc r11, r2, r3, lsr #18 */
/* @0x2b2868 .word 0x3601461a */
/* @0x2b286c and r2, r0, r6, lsl #6 */
/* @0x2b2870 .word 0xf85e3b02 */
/* @0x2b2874 strmi r0, [r1], #-3100 */
/* @0x2b2878 blhs 0x46c814 <g_RomDisk+0x74ff4> */
/* @0x2b287c stmdage lr, {r1, r5, sp, lr, pc} */
/* @0x2b2880 strtmi r4, [r0], #-1598 */
/* @0x2b2884 .word 0xf8502200 */
/* @0x2b2888 .word 0x46861c38 */
/* @0x2b288c andsle r4, r8, #-1879048182 */
/* @0x2b2890 .word 0xf0110848 */
/* @0x2b2894 .word 0xf8170f01 */
/* @0x2b2898 svclt #0x14c000 */
/* @0x2b289c andhs r2, r4, r0 */
/* @0x2b28a0 .word 0xf000fa4c */
/* @0x2b28a4 andeq pc, pc, r0 */
/* @0x2b28a8 movwmi r4, #0x2098 */
/* @0x2b28ac eorsvc r11, r2, r3, lsr #18 */
/* @0x2b28b0 .word 0x3601461a */
/* @0x2b28b4 and r2, r0, r4, lsl #6 */
/* @0x2b28b8 .word 0xf85e3b04 */
/* @0x2b28bc strmi r0, [r1], #-3100 */
/* @0x2b28c0 blhs 0x3ec858 <ft_smooth_lcd_renderer_class+0x8> */
/* @0x2b28c4 eorsvc sp, r2, r9, lsl r0 */
/* @0x2b28c8 b 0x16aa92c <b2_toiTime+0xf51488> */
/* @0x2b28cc blge 0x635020 <g_SWFaavertbuff+0x61f58> */
/* @0x2b28d0 ldrtmi r4, [r12], r3, lsr #8 */
/* @0x2b28d4 ldcvs p8, c15, [r8], #-332 */
/* @0x2b28d8 adcmi r4, lr, #161480704 */
/* @0x2b28dc blx 0x52711a <SrcVerts+0x8415e> */
/* @0x2b28e0 strmi r7, [r12, #0x106] */
/* @0x2b28e4 strbtmi sp, [r0], -r4 */
/* @0x2b28e8 .word 0xf603464a */
/* @0x2b28ec strmi lr, [r4], r8, ror #28 */
/* @0x2b28f0 .word 0x2c1cf85a */
/* @0x2b28f4 ldrmi r4, [r6], #-1228 */
/* @0x2b28f8 blge 0x66c8bc <g_SWFlinevertbuff+0x197f4> */
/* @0x2b28fc .word 0xf8d8441c */
/* @0x2b2900 .word 0xf8543000 */
/* @0x2b2904 bllo 0x2f997c <ps_hints_apply+0x857c> */
/* @0x2b2908 ldchs p8, c15, [r8], #-336 */
/* @0x2b290c bne 0xfe2b8a74 <b2_toiTime+0xfffffffffdb5f5d0> */
/* @0x2b2910 ldmib r10, {r1, r2, r5, r6, r12, sp, lr, pc} */
/* @0x2b2914 mullo r11, r8, r8 */
/* @0x2b2918 .word 0xf8c82b07 */
/* @0x2b291c .word 0xd9020000 */
/* @0x2b2920 cmpmi r8, #14352384 */
/* @0x2b2924 cmpmi r8, #2 */
/* @0x2b2928 stmeq r0, {r0, r1, r2, r12, sp} ^ */
/* @0x2b292c andeq pc, r4, r8, asr #17 */
/* @0x2b2930 pop {r1, r2, r3, r12, sp, pc} */
/* @0x2b2934 svclt #0x87f0 */
/* @0x2b2938 strheq sp, [sp], -r6 */
/* @0x2b293c .word 0xf500b570 */
/* @0x2b2940 mcrmi p5, #0x1, r7, c4, c12, #0x4 */
/* @0x2b2944 .word 0xf8d04604 */
/* @0x2b2948 ldrbtmi r3, [lr], #-456 */
/* @0x2b294c teqne r8, r0, asr #17 */
/* @0x2b2950 .word 0xf8c03301 */
/* @0x2b2954 qasxmi r3, r8, r12 */
/* @0x2b2958 .word 0xf6042100 */
/* @0x2b295c teqlt r0, r8, lsr #16 */
/* @0x2b2960 ldrsbne pc, [r0, #-132] */
/* @0x2b2964 stmdblt r1, {r5, r9, r10, lr} */
/* @0x2b2968 .word 0xf7f34631 */
/* @0x2b296c .word 0xf8d4fd5f */
/* @0x2b2970 ldmdblt r3!, {r3, r6, r8, r12, sp} ^ */
/* @0x2b2974 .word 0xf8d44620 */
/* @0x2b2978 .word 0xf8d41170 */
/* @0x2b297c .word 0xf7fe2174 */
/* @0x2b2980 .word 0xf8d4fe8f */
/* @0x2b2984 .word 0xf8c43170 */
/* @0x2b2988 .word 0xf8d43144 */
/* @0x2b298c .word 0xf8c43174 */
/* @0x2b2990 .word 0xf8d43148 */
/* @0x2b2994 blhs 0x2bee8c <jpeg_huff_decode+0x300> */
/* @0x2b2998 .word 0xf8d4d1dd */
/* @0x2b299c smulwblt r11, r12, r1 */
/* @0x2b29a0 ldrsbhs pc, [r0, r4]! */
/* @0x2b29a4 asrslo pc, r4, #17 */
/* @0x2b29a8 .word 0x21acf8c4 */
/* @0x2b29ac .word 0xf7ff4620 */
/* @0x2b29b0 .word 0xf8d4fe2d */
/* @0x2b29b4 .word 0xf8d42218 */
/* @0x2b29b8 andlo r3, r1, #20, #4 */
/* @0x2b29bc andshs pc, r8, #196, #16 */
/* @0x2b29c0 addsmi r11, r10, #-1073741812 */
/* @0x2b29c4 strtmi sp, [r0], -r4, lsl #6 */
/* @0x2b29c8 ldrhtmi lr, [r0], #-141 */
/* @0x2b29cc stcllt p7, c15, [r2, #1012] */
/* @0x2b29d0 svclt #0xbd70 */
/* @0x2b29d4 andeq r11, sp, r3, lsr r6 */
/* @0x2b29d8 svcmi #0xf0e92d */
/* @0x2b29dc bvc 0xff5843f0 <b2_toiTime+0xfffffffffee2af4c> */
/* @0x2b29e0 .word 0xf890b087 */
/* @0x2b29e4 stmdavs r10, {r0, r3, r5, r6, r7, r8} ^ */
/* @0x2b29e8 .word 0xf8db3307 */
/* @0x2b29ec streq r4, [r7, -r12, lsr #3] */
/* @0x2b29f0 .word 0x03e3ea4f */
/* @0x2b29f4 strls r9, [r1], #-515 */
/* @0x2b29f8 ldrsbhs pc, [r0, r11]! */
/* @0x2b29fc stmdahs r8, {r0, r1, r2, r3, r8, r10, r12, lr, pc} */
/* @0x2b2a00 mcrls p0, #0x0, sp, c3, c8, #0x1 */
/* @0x2b2a04 .word 0x21004614 */
/* @0x2b2a08 adcsmi r4, r4, #369098752 */
/* @0x2b2a0c .word 0xf814d009 */
/* @0x2b2a10 ldclhs p15, c5, [pc, #-4]! */
/* @0x2b2a14 .word 0xf5c5bfc8 */
/* @0x2b2a18 strtmi r7, [r9], #-1408 */
/* @0x2b2a1c .word 0xf06fe7f5 */
/* @0x2b2a20 ldmdahs r0, {r8, lr} */
/* @0x2b2a24 .word 0xf8dbd128 */
/* @0x2b2a28 mrrcne p1, #0xb, r5, r6, c4 */
/* @0x2b2a2c stclne p4, c2, [pc], #-0 */
/* @0x2b2a30 mulle r9, r12, r2 */
/* @0x2b2a34 .word 0x0c04eb02 */
/* @0x2b2a38 mulhi r1, r12, r8 */
/* @0x2b2a3c .word 0x0c04eb05 */
/* @0x2b2a40 .word 0xf88c3401 */
/* @0x2b2a44 ldrb r8, [r3, r1]! */
/* @0x2b2a48 bne 0xff884534 <b2_toiTime+0xffffffffff12b090> */
/* @0x2b2a4c stcls p6, c4, [r3, #-112] */
/* @0x2b2a50 andle r4, r11, #172, #4 */
/* @0x2b2a54 .word 0x0c04eb07 */
/* @0x2b2a58 andhi pc, r4, r6, lsl r8 */
/* @0x2b2a5c mulgt r1, r12, r8 */
/* @0x2b2a60 .word 0x0c08ebcc */
/* @0x2b2a64 andgt pc, r4, r9, lsl #16 */
/* @0x2b2a68 ldrb r3, [r0, r1, lsl #8]! */
/* @0x2b2a6c ldrsbvs pc, [r4, r11]! */
/* @0x2b2a70 subs r9, r12, r2, lsl #12 */
/* @0x2b2a74 .word 0x4100f06f */
/* @0x2b2a78 ldrle r0, [pc, #-0x6c6]! */
/* @0x2b2a7c ldrsbvc pc, [r4, r11]! */
/* @0x2b2a80 .word 0xf1022500 */
/* @0x2b2a84 strtmi r0, [r12], -r1, lsl #16 */
/* @0x2b2a88 .word 0x0c01f107 */
/* @0x2b2a8c mulle r12, sp, r2 */
/* @0x2b2a90 bl 0x478ff0 <g_RomDisk+0x817d0> */
/* @0x2b2a94 strlo r0, [r1, #-0x905] */
/* @0x2b2a98 mrchs p8, #0x3, r7, c15, c6, #0x3 */
/* @0x2b2a9c andvs pc, r1, r9, lsl #17 */
/* @0x2b2aa0 .word 0xf5c6bfc8 */
/* @0x2b2aa4 ldrtmi r7, [r4], #-1664 */
/* @0x2b2aa8 bl 0x5eca70 <g_SWFaavertbuff+0x199a8> */
/* @0x2b2aac .word 0xf1c30903 */
/* @0x2b2ab0 bl 0x335ab8 */
/* @0x2b2ab4 strbmi r0, [r12], #1804 */
/* @0x2b2ab8 .word 0x46c2461d */
/* @0x2b2abc adcsmi r9, r5, #3, #28 */
/* @0x2b2ac0 bl 0x4a731c <SrcVerts+0x4360> */
/* @0x2b2ac4 .word 0xf81a0805 */
/* @0x2b2ac8 .word 0xf8989005 */
/* @0x2b2acc bl 0xff4d2ad8 <b2_toiTime+0xfffffffffed79634> */
/* @0x2b2ad0 blx 0x1a74afc <b2_toiTime+0x131b658> */
/* @0x2b2ad4 .word 0xf80cf888 */
/* @0x2b2ad8 .word 0xf1b88005 */
/* @0x2b2adc svclt #0xc80f7f */
/* @0x2b2ae0 stmvc r0, {r3, r6, r7, r8, r10, r12, sp, lr, pc} */
/* @0x2b2ae4 addmi r4, r12, #68, #8 */
/* @0x2b2ae8 strlo sp, [r1, #-0x808] */
/* @0x2b2aec addmi lr, r12, #60293120 */
/* @0x2b2af0 .word 0xf8dbd204 */
/* @0x2b2af4 strhls r1, [r2, -r4] */
/* @0x2b2af8 and r4, r0, r1, lsr #12 */
/* @0x2b2afc stmdahs r0!, {r1, r9, r12, pc} */
/* @0x2b2b00 .word 0x9c03d115 */
/* @0x2b2b04 ldrsbvs pc, [r8, r11]! */
/* @0x2b2b08 strhs r1, [r0], #-3173 */
/* @0x2b2b0c adcmi r3, r12, #16777216 */
/* @0x2b2b10 .word 0xf8ddd009 */
/* @0x2b2b14 .word 0xf8128004 */
/* @0x2b2b18 .word 0xf818c004 */
/* @0x2b2b1c bl 0xff48eb34 <b2_toiTime+0xfffffffffed35690> */
/* @0x2b2b20 ldrpl r0, [r7, #-0x70c]! */
/* @0x2b2b24 .word 0xf8dbe7f2 */
/* @0x2b2b28 strls r4, [r2], #-440 */
/* @0x2b2b2c pkhtbeq lr, r5, r9, asr #32 */
/* @0x2b2b30 stcls p5, c13, [r3, #-144] */
/* @0x2b2b34 .word 0xf8db2401 */
/* @0x2b2b38 stclne p1, c7, [lr], #-736 */
/* @0x2b2b3c adcsmi r2, r4, #0, #10 */
/* @0x2b2b40 .word 0xf8ddd016 */
/* @0x2b2b44 .word 0xf8129004 */
/* @0x2b2b48 .word 0xf8198004 */
/* @0x2b2b4c bl 0xff5e2b64 <b2_toiTime+0xfffffffffee896c0> */
/* @0x2b2b50 blx 0x1a75b78 <b2_toiTime+0x131c6d4> */
/* @0x2b2b54 .word 0xf807fc8c */
/* @0x2b2b58 .word 0xf1bcc004 */
/* @0x2b2b5c .word 0xf1040f7f */
/* @0x2b2b60 svclt #0xc80401 */
/* @0x2b2b64 stcvc p5, c15, [r0], {204} */
/* @0x2b2b68 addmi r4, sp, #1694498816 */
/* @0x2b2b6c and sp, r5, r7, ror #19 */
/* @0x2b2b70 andle r4, r3, #-805306360 */
/* @0x2b2b74 ldrsbne pc, [r8, r11]! */
/* @0x2b2b78 strtmi r9, [r9], -r2, lsl #2 */
/* @0x2b2b7c teqle r0, r0, asr #16 */
/* @0x2b2b80 ldrsbpl pc, [r12, r11]! */
/* @0x2b2b84 .word 0x9c011c57 */
/* @0x2b2b88 stmdaeq r1, {r0, r1, r8, r12, sp, lr, pc} */
/* @0x2b2b8c .word 0x0c01f105 */
/* @0x2b2b90 strhs r1, [r0], #-3174 */
/* @0x2b2b94 strbmi r3, [r4, #-0x401] */
/* @0x2b2b98 .word 0xf8ddd00a */
/* @0x2b2b9c .word 0xf81aa004 */
/* @0x2b2ba0 .word 0xf8129004 */
/* @0x2b2ba4 bl 0xfed5abbc <b2_toiTime+0xfffffffffe601718> */
/* @0x2b2ba8 .word 0xf8050959 */
/* @0x2b2bac ldrb r9, [r1, r4]! */
/* @0x2b2bb0 beq 0x36dac4 <_ZTS13C_UTF16String+0x4b70> */
/* @0x2b2bb4 stcls p6, c4, [r3, #-112] */
/* @0x2b2bb8 andle r4, lr, #172, #4 */
/* @0x2b2bbc stmdaeq r4, {r1, r3, r8, r9, r11, sp, lr, pc} */
/* @0x2b2bc0 andls pc, r4, r6, lsl r8 */
/* @0x2b2bc4 mulhi r1, r8, r8 */
/* @0x2b2bc8 .word 0xf81744c8 */
/* @0x2b2bcc bl 0xfed16be4 <b2_toiTime+0xfffffffffe5bd740> */
/* @0x2b2bd0 .word 0xf80c0858 */
/* @0x2b2bd4 strlo r8, [r1], #-4 */
/* @0x2b2bd8 .word 0xf8dbe7ed */
/* @0x2b2bdc .word 0x960261bc */
/* @0x2b2be0 .word 0x0644e09a */
/* @0x2b2be4 .word 0xf8dbd547 */
/* @0x2b2be8 .word 0xf10261bc */
/* @0x2b2bec .word 0x9c010a01 */
/* @0x2b2bf0 stmdaeq r1, {r0, r1, r8, r12, sp, lr, pc} */
/* @0x2b2bf4 stmdbeq r1, {r1, r2, r8, r12, sp, lr, pc} */
/* @0x2b2bf8 strlo r2, [r1], #-1281 */
/* @0x2b2bfc strhs r9, [r0], #-1028 */
/* @0x2b2c00 andsle r4, r1, r5, asr #10 */
/* @0x2b2c04 .word 0xc004f8dd */
/* @0x2b2c08 andvc pc, r5, r12, lsl r8 */
/* @0x2b2c0c andgt pc, r5, r2, lsl r8 */
/* @0x2b2c10 ldrbeq lr, [r7, -r12, lsr #23] */
/* @0x2b2c14 ldrbpl r11, [r7, #-0x2ff]! */
/* @0x2b2c18 .word 0xf1052f7f */
/* @0x2b2c1c svclt #0xc80501 */
/* @0x2b2c20 strvc pc, [r0, r7, asr #11] */
/* @0x2b2c24 .word 0xe7eb443c */
/* @0x2b2c28 ldrmi r4, [r9], #606 */
/* @0x2b2c2c ldrsbhi pc, [r0], -sp */
/* @0x2b2c30 .word 0x0c06eb02 */
/* @0x2b2c34 .word 0x461d44b1 */
/* @0x2b2c38 adcsmi r9, r5, #3, #28 */
/* @0x2b2c3c bl 0x5e7498 <g_SWFaavertbuff+0x143d0> */
/* @0x2b2c40 .word 0xf8180605 */
/* @0x2b2c44 ldmdavc r6!, {r0, r2, r12, sp, lr} ^ */
/* @0x2b2c48 .word 0xf81a443e */
/* @0x2b2c4c bl 0xfec8ec68 <b2_toiTime+0xfffffffffe5357c4> */
/* @0x2b2c50 rscslt r0, r6, #90177536 */
/* @0x2b2c54 andvs pc, r5, r9, lsl #16 */
/* @0x2b2c58 svclt #0xc82e7f */
/* @0x2b2c5c strvc pc, [r0], r6, asr #11 */
/* @0x2b2c60 addmi r4, r12, #52, #8 */
/* @0x2b2c64 strlo sp, [r1, #-0x807] */
/* @0x2b2c68 addmi lr, r12, #60293120 */
/* @0x2b2c6c .word 0xf8dbd203 */
/* @0x2b2c70 strhls r1, [r2, -r12] */
/* @0x2b2c74 stmhs r0, {r0, r5, r9, r10, lr} */
/* @0x2b2c78 stcls p1, c13, [r1, #-312] */
/* @0x2b2c7c .word 0xf8db1c54 */
/* @0x2b2c80 smlabths r0, r0, r1, r0 */
/* @0x2b2c84 .word 0x0c01f105 */
/* @0x2b2c88 cps #0x1d */
/* @0x2b2c8c .word 0x31010a01 */
/* @0x2b2c90 andle r4, r7, r9, lsr #5 */
/* @0x2b2c94 .word 0x8004f8dd */
/* @0x2b2c98 .word 0xf8185c57 */
/* @0x2b2c9c blne 0xff24aca8 <b2_toiTime+0xfffffffffeaf1804> */
/* @0x2b2ca0 ldrb r5, [r4, r6, asr #8]! */
/* @0x2b2ca4 .word 0x8004f8dd */
/* @0x2b2ca8 stmne r0!, {r0, r3, r4, r6, r9, lr} ^ */
/* @0x2b2cac ldrmi r4, [r12], #1178 */
/* @0x2b2cb0 strmi r4, [r12], #1160 */
/* @0x2b2cb4 stmdbeq r1, {r1, r8, r9, r11, sp, lr, pc} */
/* @0x2b2cb8 stmdane r1, {r1, r3, r7, r10, lr} ^ */
/* @0x2b2cbc stmdbls r3, {r0, r8, r12, pc} */
/* @0x2b2cc0 eorle r4, r5, #-1342177272 */
/* @0x2b2cc4 andeq lr, r3, #8, #22 */
/* @0x2b2cc8 .word 0x0103eb09 */
/* @0x2b2ccc andeq pc, r3, r12, lsl r8 */
/* @0x2b2cd0 stmdavc r9, {r1, r4, r6, r11, r12, sp, lr} ^ */
/* @0x2b2cd4 bne 0xfe6396f8 <b2_toiTime+0xfffffffffdee0254> */
/* @0x2b2cd8 strbvc lr, [r7, #0xa87]! */
/* @0x2b2cdc strbvc lr, [r7, #0xba5]! */
/* @0x2b2ce0 strbtvc lr, [r6], #2694 */
/* @0x2b2ce4 strbtvc lr, [r6], #2980 */
/* @0x2b2ce8 mcrhs p4, #0x0, r4, c0, c14, #0x1 */
/* @0x2b2cec rsbsmi r11, r6, #184, #30 */
/* @0x2b2cf0 .word 0xdc0142a5 */
/* @0x2b2cf4 stcle p2, c4, [r3, #-724] */
/* @0x2b2cf8 svclt #0xd842b4 */
/* @0x2b2cfc and r4, r0, r2, lsl #12 */
/* @0x2b2d00 stmdals r1, {r1, r3, r9, r10, lr} */
/* @0x2b2d04 bne 0xfe54a010 <b2_toiTime+0xfffffffffddf0b6c> */
/* @0x2b2d08 andhs pc, r3, r10, lsl #16 */
/* @0x2b2d0c ldrb r3, [r6, r1, lsl #6] */
/* @0x2b2d10 .word 0x21c0f8db */
/* @0x2b2d14 rsb r9, r10, r2, lsl #4 */
/* @0x2b2d18 strble r0, [r8, #-0x600]! */
/* @0x2b2d1c .word 0x51c0f8db */
/* @0x2b2d20 stmdbeq r1, {r1, r8, r12, sp, lr, pc} */
/* @0x2b2d24 andhs r9, r0, r1, lsl #24 */
/* @0x2b2d28 beq 0x32f144 */
/* @0x2b2d2c .word 0xf1041c5e */
/* @0x2b2d30 strhs r0, [r1], #-2049 */
/* @0x2b2d34 .word 0xf8dd9604 */
/* @0x2b2d38 strbmi r12, [r4, #-0x10]! */
/* @0x2b2d3c cdpls p0, #0x0, c13, c1, c15, #0x0 */
/* @0x2b2d40 andgt pc, r4, r2, lsl r8 */
/* @0x2b2d44 bl 0xff48a228 <b2_toiTime+0xfffffffffed30d84> */
/* @0x2b2d48 rscslt r0, pc, #12, #14 */
/* @0x2b2d4c svchs #0x7f552f */
/* @0x2b2d50 streq pc, [r1], #-260 */
/* @0x2b2d54 .word 0xf5c7bfc8 */
/* @0x2b2d58 ldrtmi r7, [r8], #-1920 */
/* @0x2b2d5c subsmi lr, r12, #61603840 */
/* @0x2b2d60 ldrmi r4, [r10], #1177 */
/* @0x2b2d64 strtmi r9, [r1], #3329 */
/* @0x2b2d68 ldrmi r4, [r8], #1186 */
/* @0x2b2d6c strtmi r4, [r0], #1061 */
/* @0x2b2d70 .word 0xf8cd4422 */
/* @0x2b2d74 strls r8, [r1, #-0x10] */
/* @0x2b2d78 bls 0x397594 <ft_adobe_glyph_list+0x6c70> */
/* @0x2b2d7c eorsle r4, r1, #805306377 */
/* @0x2b2d80 .word 0x9c059a01 */
/* @0x2b2d84 ldrmi r9, [r10], #-3588 */
/* @0x2b2d88 ldmdavc r2, {r2, r3, r4, r10, lr} ^ */
/* @0x2b2d8c stmdavc r4!, {r0, r2, r4, r5, r6, r7, r10, r11, r12, lr} ^ */
/* @0x2b2d90 stmdaeq r5, {r1, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0x2b2d94 .word 0x0c04ebc2 */
/* @0x2b2d98 strbvc lr, [r8, r8, lsl #21]! */
/* @0x2b2d9c strbvc lr, [r8, r7, lsr #23]! */
/* @0x2b2da0 strbtvc lr, [r12], r12, lsl #21 */
/* @0x2b2da4 strbtvc lr, [r12], r6, lsr #23 */
/* @0x2b2da8 .word 0xf1bc44c4 */
/* @0x2b2dac svclt #0xb80f00 */
/* @0x2b2db0 .word 0x0c00f1cc */
/* @0x2b2db4 .word 0xdc0142b7 */
/* @0x2b2db8 stcle p5, c4, [r3, #-412] */
/* @0x2b2dbc svclt #0xd84566 */
/* @0x2b2dc0 and r4, r0, r10, lsr #12 */
/* @0x2b2dc4 .word 0xf8194622 */
/* @0x2b2dc8 bne 0xfeb42ddc <b2_toiTime+0xfffffffffe3e9938> */
/* @0x2b2dcc .word 0xf80ab2d2 */
/* @0x2b2dd0 bhs 0x227ade4 <b2_toiTime+0x1b21940> */
/* @0x2b2dd4 .word 0xf5c2bfc8 */
/* @0x2b2dd8 ldrmi r7, [r0], #-640 */
/* @0x2b2ddc stmdale r6, {r3, r7, r9, lr} */
/* @0x2b2de0 strb r3, [r10, r1, lsl #6] */
/* @0x2b2de4 svclt #0x3c4288 */
/* @0x2b2de8 .word 0x31c0f8db */
/* @0x2b2dec ldrbmi r9, [r8], -r2, lsl #6 */
/* @0x2b2df0 andlt r9, r7, r2, lsl #18 */
/* @0x2b2df4 svcmi #0xf0e8bd */
/* @0x2b2df8 stclt p7, c15, [r0, #1020]! */

/* ── FUNC 0x2b12bd · png_write_chunk · size=38 · insn=0 */

/* ── FUNC 0x2b12e5 · png_write_IHDR · size=748 · insn=0 */

/* ── FUNC 0x2b15d1 · png_write_PLTE · size=208 · insn=0 */

/* ── FUNC 0x2b16a1 · png_write_IDAT · size=236 · insn=0 */

/* ── FUNC 0x2b178d · png_write_IEND · size=52 · insn=0 */

/* ── FUNC 0x2b17c1 · png_write_gAMA · size=84 · insn=0 */

/* ── FUNC 0x2b1819 · png_write_gAMA_fixed · size=52 · insn=0 */

/* ── FUNC 0x2b184d · png_write_sRGB · size=68 · insn=0 */
