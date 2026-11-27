/* libyoyo.so 覆盖卡组 0179
 * 函数 0x1fc840..0x1fe9ec，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1fc840 · SV_ViewCamera(CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x1fc840 ldr r3, [pc, #0x5c] */
/* @0x1fc844 cmp r1, #7 */
/* @0x1fc848 ldr r0, [r2, #0xc] */
/* @0x1fc84c ldr r3, [pc, r3] */
/* @0x1fc850 movhi r1, #0 */
/* @0x1fc854 bic r0, r0, #-16777216 */
/* @0x1fc858 add r1, r1, #18 */
/* @0x1fc85c ldr r3, [r3] */
/* @0x1fc860 cmp r0, #0 */
/* @0x1fc864 push {r4, lr} */
/* @0x1fc868 ldr r4, [r3, r1, lsl #2] */
/* @0x1fc86c bne 0x1fc890 <_Z13SV_ViewCameraP9CInstanceiP6RValue+0x50> */
/* @0x1fc870 ldr r12, [r2] */
/* @0x1fc874 ldr r3, [r2, #0x4] */
/* @0x1fc878 mov r0, r12 */
/* @0x1fc87c mov r1, r3 */
/* @0x1fc880 bl 0xb66e8 <lrint@plt> */
/* @0x1fc884 str r0, [r4, #0x40] */
/* @0x1fc888 mov r0, #1 */
/* @0x1fc88c pop {r4, pc} */
/* @0x1fc890 mov r0, r2 */
/* @0x1fc894 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc898 mov r12, r0 */
/* @0x1fc89c mov r3, r1 */
/* @0x1fc8a0 b 0x1fc878 <_Z13SV_ViewCameraP9CInstanceiP6RValue+0x38> */
/* @0x1fc8a4 ldrsbeq r1, [pc], -r12 */

/* ── FUNC 0x1fc8a8 · SV_BackgroundVisible(CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x1fc8a8 ldr r3, [pc, #0x78] */
/* @0x1fc8ac cmp r1, #7 */
/* @0x1fc8b0 ldr r0, [r2, #0xc] */
/* @0x1fc8b4 ldr r3, [pc, r3] */
/* @0x1fc8b8 movhi r1, #0 */
/* @0x1fc8bc bic r0, r0, #-16777216 */
/* @0x1fc8c0 ldr r3, [r3] */
/* @0x1fc8c4 cmp r0, #0 */
/* @0x1fc8c8 push {r4, lr} */
/* @0x1fc8cc add r1, r3, r1, lsl #2 */
/* @0x1fc8d0 ldr r4, [r1, #0x24] */
/* @0x1fc8d4 bne 0x1fc914 <_Z20SV_BackgroundVisibleP9CInstanceiP6RValue+0x6c> */
/* @0x1fc8d8 ldr r12, [r2] */
/* @0x1fc8dc ldr r3, [r2, #0x4] */
/* @0x1fc8e0 mov r1, r3 */
/* @0x1fc8e4 mov r0, r12 */
/* @0x1fc8e8 bl 0xb66e8 <lrint@plt> */
/* @0x1fc8ec vmov.f64 d7, #5.000000e-01 */
/* @0x1fc8f0 vmov s11, r0 */
/* @0x1fc8f4 mov r0, #1 */
/* @0x1fc8f8 vcvt.f64.s32 d6, s11 */
/* @0x1fc8fc vcmpe.f64 d6, d7 */
/* @0x1fc900 vmrs APSR_nzcv, fpscr */
/* @0x1fc904 movle r3, #0 */
/* @0x1fc908 movgt r3, #1 */
/* @0x1fc90c strb r3, [r4] */
/* @0x1fc910 pop {r4, pc} */
/* @0x1fc914 mov r0, r2 */
/* @0x1fc918 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc91c mov r12, r0 */
/* @0x1fc920 mov r3, r1 */
/* @0x1fc924 b 0x1fc8e0 <_Z20SV_BackgroundVisibleP9CInstanceiP6RValue+0x38> */
/* @0x1fc928 andseq r1, pc, r4, ror r0 */

/* ── FUNC 0x1fc92c · SV_BackgroundForeground(CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x1fc92c ldr r3, [pc, #0x78] */
/* @0x1fc930 cmp r1, #7 */
/* @0x1fc934 ldr r0, [r2, #0xc] */
/* @0x1fc938 ldr r3, [pc, r3] */
/* @0x1fc93c movhi r1, #0 */
/* @0x1fc940 bic r0, r0, #-16777216 */
/* @0x1fc944 ldr r3, [r3] */
/* @0x1fc948 cmp r0, #0 */
/* @0x1fc94c push {r4, lr} */
/* @0x1fc950 add r1, r3, r1, lsl #2 */
/* @0x1fc954 ldr r4, [r1, #0x24] */
/* @0x1fc958 bne 0x1fc998 <_Z23SV_BackgroundForegroundP9CInstanceiP6RValue+0x6c> */
/* @0x1fc95c ldr r12, [r2] */
/* @0x1fc960 ldr r3, [r2, #0x4] */
/* @0x1fc964 mov r1, r3 */
/* @0x1fc968 mov r0, r12 */
/* @0x1fc96c bl 0xb66e8 <lrint@plt> */
/* @0x1fc970 vmov.f64 d7, #5.000000e-01 */
/* @0x1fc974 vmov s11, r0 */
/* @0x1fc978 mov r0, #1 */
/* @0x1fc97c vcvt.f64.s32 d6, s11 */
/* @0x1fc980 vcmpe.f64 d6, d7 */
/* @0x1fc984 vmrs APSR_nzcv, fpscr */
/* @0x1fc988 movle r3, #0 */
/* @0x1fc98c movgt r3, #1 */
/* @0x1fc990 strb r3, [r4, #0x1] */
/* @0x1fc994 pop {r4, pc} */
/* @0x1fc998 mov r0, r2 */
/* @0x1fc99c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc9a0 mov r12, r0 */
/* @0x1fc9a4 mov r3, r1 */
/* @0x1fc9a8 b 0x1fc964 <_Z23SV_BackgroundForegroundP9CInstanceiP6RValue+0x38> */
/* @0x1fc9ac ldrsheq r0, [pc], -r0 */

/* ── FUNC 0x1fc9b0 · SV_BackgroundIndex(CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x1fc9b0 ldr r3, [pc, #0x5c] */
/* @0x1fc9b4 cmp r1, #7 */
/* @0x1fc9b8 ldr r0, [r2, #0xc] */
/* @0x1fc9bc ldr r3, [pc, r3] */
/* @0x1fc9c0 movhi r1, #0 */
/* @0x1fc9c4 bic r0, r0, #-16777216 */
/* @0x1fc9c8 ldr r3, [r3] */
/* @0x1fc9cc cmp r0, #0 */
/* @0x1fc9d0 push {r4, lr} */
/* @0x1fc9d4 add r1, r3, r1, lsl #2 */
/* @0x1fc9d8 ldr r4, [r1, #0x24] */
/* @0x1fc9dc bne 0x1fca00 <_Z18SV_BackgroundIndexP9CInstanceiP6RValue+0x50> */
/* @0x1fc9e0 ldr r12, [r2] */
/* @0x1fc9e4 ldr r3, [r2, #0x4] */
/* @0x1fc9e8 mov r0, r12 */
/* @0x1fc9ec mov r1, r3 */
/* @0x1fc9f0 bl 0xb66e8 <lrint@plt> */
/* @0x1fc9f4 str r0, [r4, #0x4] */
/* @0x1fc9f8 mov r0, #1 */
/* @0x1fc9fc pop {r4, pc} */
/* @0x1fca00 mov r0, r2 */
/* @0x1fca04 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fca08 mov r12, r0 */
/* @0x1fca0c mov r3, r1 */
/* @0x1fca10 b 0x1fc9e8 <_Z18SV_BackgroundIndexP9CInstanceiP6RValue+0x38> */
/* @0x1fca14 andseq r0, pc, r12, ror #30 */

/* ── FUNC 0x1fca18 · SV_BackgroundX(CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1fca18 ldr r3, [pc, #0x4c] */
/* @0x1fca1c cmp r1, #7 */
/* @0x1fca20 ldr r0, [r2, #0xc] */
/* @0x1fca24 ldr r3, [pc, r3] */
/* @0x1fca28 movhi r1, #0 */
/* @0x1fca2c bic r0, r0, #-16777216 */
/* @0x1fca30 ldr r3, [r3] */
/* @0x1fca34 cmp r0, #0 */
/* @0x1fca38 push {r4, lr} */
/* @0x1fca3c add r1, r3, r1, lsl #2 */
/* @0x1fca40 ldr r4, [r1, #0x24] */
/* @0x1fca44 bne 0x1fca60 <_Z14SV_BackgroundXP9CInstanceiP6RValue+0x48> */
/* @0x1fca48 ldm r2, {r0, r1} */
/* @0x1fca4c vmov d6, r0, r1 */
/* @0x1fca50 mov r0, #1 */
/* @0x1fca54 vcvt.f32.f64 s15, d6 */
/* @0x1fca58 vstr s15, [r4, #8] */
/* @0x1fca5c pop {r4, pc} */
/* @0x1fca60 mov r0, r2 */
/* @0x1fca64 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fca68 b 0x1fca4c <_Z14SV_BackgroundXP9CInstanceiP6RValue+0x34> */
/* @0x1fca6c andseq r0, pc, r4, lsl #30 */

/* ── FUNC 0x1fca70 · SV_BackgroundY(CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1fca70 ldr r3, [pc, #0x4c] */
/* @0x1fca74 cmp r1, #7 */
/* @0x1fca78 ldr r0, [r2, #0xc] */
/* @0x1fca7c ldr r3, [pc, r3] */
/* @0x1fca80 movhi r1, #0 */
/* @0x1fca84 bic r0, r0, #-16777216 */
/* @0x1fca88 ldr r3, [r3] */
/* @0x1fca8c cmp r0, #0 */
/* @0x1fca90 push {r4, lr} */
/* @0x1fca94 add r1, r3, r1, lsl #2 */
/* @0x1fca98 ldr r4, [r1, #0x24] */
/* @0x1fca9c bne 0x1fcab8 <_Z14SV_BackgroundYP9CInstanceiP6RValue+0x48> */
/* @0x1fcaa0 ldm r2, {r0, r1} */
/* @0x1fcaa4 vmov d6, r0, r1 */
/* @0x1fcaa8 mov r0, #1 */
/* @0x1fcaac vcvt.f32.f64 s15, d6 */
/* @0x1fcab0 vstr s15, [r4, #12] */
/* @0x1fcab4 pop {r4, pc} */
/* @0x1fcab8 mov r0, r2 */
/* @0x1fcabc bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fcac0 b 0x1fcaa4 <_Z14SV_BackgroundYP9CInstanceiP6RValue+0x34> */
/* @0x1fcac4 andseq r0, pc, r12, lsr #29 */

/* ── FUNC 0x1fcac8 · SV_BackgroundHTiled(CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x1fcac8 ldr r3, [pc, #0x78] */
/* @0x1fcacc cmp r1, #7 */
/* @0x1fcad0 ldr r0, [r2, #0xc] */
/* @0x1fcad4 ldr r3, [pc, r3] */
/* @0x1fcad8 movhi r1, #0 */
/* @0x1fcadc bic r0, r0, #-16777216 */
/* @0x1fcae0 ldr r3, [r3] */
/* @0x1fcae4 cmp r0, #0 */
/* @0x1fcae8 push {r4, lr} */
/* @0x1fcaec add r1, r3, r1, lsl #2 */
/* @0x1fcaf0 ldr r4, [r1, #0x24] */
/* @0x1fcaf4 bne 0x1fcb34 <_Z19SV_BackgroundHTiledP9CInstanceiP6RValue+0x6c> */
/* @0x1fcaf8 ldr r12, [r2] */
/* @0x1fcafc ldr r3, [r2, #0x4] */
/* @0x1fcb00 mov r1, r3 */
/* @0x1fcb04 mov r0, r12 */
/* @0x1fcb08 bl 0xb66e8 <lrint@plt> */
/* @0x1fcb0c vmov.f64 d7, #5.000000e-01 */
/* @0x1fcb10 vmov s11, r0 */
/* @0x1fcb14 mov r0, #1 */
/* @0x1fcb18 vcvt.f64.s32 d6, s11 */
/* @0x1fcb1c vcmpe.f64 d6, d7 */
/* @0x1fcb20 vmrs APSR_nzcv, fpscr */
/* @0x1fcb24 movle r3, #0 */
/* @0x1fcb28 movgt r3, #1 */
/* @0x1fcb2c strb r3, [r4, #0x10] */
/* @0x1fcb30 pop {r4, pc} */
/* @0x1fcb34 mov r0, r2 */
/* @0x1fcb38 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fcb3c mov r12, r0 */
/* @0x1fcb40 mov r3, r1 */
/* @0x1fcb44 b 0x1fcb00 <_Z19SV_BackgroundHTiledP9CInstanceiP6RValue+0x38> */
/* @0x1fcb48 andseq r0, pc, r4, asr lr */

/* ── FUNC 0x1fcb4c · SV_BackgroundVTiled(CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x1fcb4c ldr r3, [pc, #0x78] */
/* @0x1fcb50 cmp r1, #7 */
/* @0x1fcb54 ldr r0, [r2, #0xc] */
/* @0x1fcb58 ldr r3, [pc, r3] */
/* @0x1fcb5c movhi r1, #0 */
/* @0x1fcb60 bic r0, r0, #-16777216 */
/* @0x1fcb64 ldr r3, [r3] */
/* @0x1fcb68 cmp r0, #0 */
/* @0x1fcb6c push {r4, lr} */
/* @0x1fcb70 add r1, r3, r1, lsl #2 */
/* @0x1fcb74 ldr r4, [r1, #0x24] */
/* @0x1fcb78 bne 0x1fcbb8 <_Z19SV_BackgroundVTiledP9CInstanceiP6RValue+0x6c> */
/* @0x1fcb7c ldr r12, [r2] */
/* @0x1fcb80 ldr r3, [r2, #0x4] */
/* @0x1fcb84 mov r1, r3 */
/* @0x1fcb88 mov r0, r12 */
/* @0x1fcb8c bl 0xb66e8 <lrint@plt> */
/* @0x1fcb90 vmov.f64 d7, #5.000000e-01 */
/* @0x1fcb94 vmov s11, r0 */
/* @0x1fcb98 mov r0, #1 */
/* @0x1fcb9c vcvt.f64.s32 d6, s11 */
/* @0x1fcba0 vcmpe.f64 d6, d7 */
/* @0x1fcba4 vmrs APSR_nzcv, fpscr */
/* @0x1fcba8 movle r3, #0 */
/* @0x1fcbac movgt r3, #1 */
/* @0x1fcbb0 strb r3, [r4, #0x11] */
/* @0x1fcbb4 pop {r4, pc} */
/* @0x1fcbb8 mov r0, r2 */
/* @0x1fcbbc bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fcbc0 mov r12, r0 */
/* @0x1fcbc4 mov r3, r1 */
/* @0x1fcbc8 b 0x1fcb84 <_Z19SV_BackgroundVTiledP9CInstanceiP6RValue+0x38> */
/* @0x1fcbcc ldrsbeq r0, [pc], -r0 */

/* ── FUNC 0x1fcbd0 · SV_BackgroundXScale(CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1fcbd0 ldr r3, [pc, #0x4c] */
/* @0x1fcbd4 cmp r1, #7 */
/* @0x1fcbd8 ldr r0, [r2, #0xc] */
/* @0x1fcbdc ldr r3, [pc, r3] */
/* @0x1fcbe0 movhi r1, #0 */
/* @0x1fcbe4 bic r0, r0, #-16777216 */
/* @0x1fcbe8 ldr r3, [r3] */
/* @0x1fcbec cmp r0, #0 */
/* @0x1fcbf0 push {r4, lr} */
/* @0x1fcbf4 add r1, r3, r1, lsl #2 */
/* @0x1fcbf8 ldr r4, [r1, #0x24] */
/* @0x1fcbfc bne 0x1fcc18 <_Z19SV_BackgroundXScaleP9CInstanceiP6RValue+0x48> */
/* @0x1fcc00 ldm r2, {r0, r1} */
/* @0x1fcc04 vmov d6, r0, r1 */
/* @0x1fcc08 mov r0, #1 */
/* @0x1fcc0c vcvt.f32.f64 s15, d6 */
/* @0x1fcc10 vstr s15, [r4, #28] */
/* @0x1fcc14 pop {r4, pc} */
/* @0x1fcc18 mov r0, r2 */
/* @0x1fcc1c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fcc20 b 0x1fcc04 <_Z19SV_BackgroundXScaleP9CInstanceiP6RValue+0x34> */
/* @0x1fcc24 andseq r0, pc, r12, asr #26 */

/* ── FUNC 0x1fcc28 · SV_BackgroundYScale(CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1fcc28 ldr r3, [pc, #0x4c] */
/* @0x1fcc2c cmp r1, #7 */
/* @0x1fcc30 ldr r0, [r2, #0xc] */
/* @0x1fcc34 ldr r3, [pc, r3] */
/* @0x1fcc38 movhi r1, #0 */
/* @0x1fcc3c bic r0, r0, #-16777216 */
/* @0x1fcc40 ldr r3, [r3] */
/* @0x1fcc44 cmp r0, #0 */
/* @0x1fcc48 push {r4, lr} */
/* @0x1fcc4c add r1, r3, r1, lsl #2 */
/* @0x1fcc50 ldr r4, [r1, #0x24] */
/* @0x1fcc54 bne 0x1fcc70 <_Z19SV_BackgroundYScaleP9CInstanceiP6RValue+0x48> */
/* @0x1fcc58 ldm r2, {r0, r1} */
/* @0x1fcc5c vmov d6, r0, r1 */
/* @0x1fcc60 mov r0, #1 */
/* @0x1fcc64 vcvt.f32.f64 s15, d6 */
/* @0x1fcc68 vstr s15, [r4, #32] */
/* @0x1fcc6c pop {r4, pc} */
/* @0x1fcc70 mov r0, r2 */
/* @0x1fcc74 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fcc78 b 0x1fcc5c <_Z19SV_BackgroundYScaleP9CInstanceiP6RValue+0x34> */
/* @0x1fcc7c ldrsheq r0, [pc], -r4 */

/* ── FUNC 0x1fcc80 · SV_BackgroundHSpeed(CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1fcc80 ldr r3, [pc, #0x4c] */
/* @0x1fcc84 cmp r1, #7 */
/* @0x1fcc88 ldr r0, [r2, #0xc] */
/* @0x1fcc8c ldr r3, [pc, r3] */
/* @0x1fcc90 movhi r1, #0 */
/* @0x1fcc94 bic r0, r0, #-16777216 */
/* @0x1fcc98 ldr r3, [r3] */
/* @0x1fcc9c cmp r0, #0 */
/* @0x1fcca0 push {r4, lr} */
/* @0x1fcca4 add r1, r3, r1, lsl #2 */
/* @0x1fcca8 ldr r4, [r1, #0x24] */
/* @0x1fccac bne 0x1fccc8 <_Z19SV_BackgroundHSpeedP9CInstanceiP6RValue+0x48> */
/* @0x1fccb0 ldm r2, {r0, r1} */
/* @0x1fccb4 vmov d6, r0, r1 */
/* @0x1fccb8 mov r0, #1 */
/* @0x1fccbc vcvt.f32.f64 s15, d6 */
/* @0x1fccc0 vstr s15, [r4, #20] */
/* @0x1fccc4 pop {r4, pc} */
/* @0x1fccc8 mov r0, r2 */
/* @0x1fcccc bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fccd0 b 0x1fccb4 <_Z19SV_BackgroundHSpeedP9CInstanceiP6RValue+0x34> */
/* @0x1fccd4 mulseq pc, r12, r12 */

/* ── FUNC 0x1fccd8 · SV_BackgroundVSpeed(CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1fccd8 ldr r3, [pc, #0x4c] */
/* @0x1fccdc cmp r1, #7 */
/* @0x1fcce0 ldr r0, [r2, #0xc] */
/* @0x1fcce4 ldr r3, [pc, r3] */
/* @0x1fcce8 movhi r1, #0 */
/* @0x1fccec bic r0, r0, #-16777216 */
/* @0x1fccf0 ldr r3, [r3] */
/* @0x1fccf4 cmp r0, #0 */
/* @0x1fccf8 push {r4, lr} */
/* @0x1fccfc add r1, r3, r1, lsl #2 */
/* @0x1fcd00 ldr r4, [r1, #0x24] */
/* @0x1fcd04 bne 0x1fcd20 <_Z19SV_BackgroundVSpeedP9CInstanceiP6RValue+0x48> */
/* @0x1fcd08 ldm r2, {r0, r1} */
/* @0x1fcd0c vmov d6, r0, r1 */
/* @0x1fcd10 mov r0, #1 */
/* @0x1fcd14 vcvt.f32.f64 s15, d6 */
/* @0x1fcd18 vstr s15, [r4, #24] */
/* @0x1fcd1c pop {r4, pc} */
/* @0x1fcd20 mov r0, r2 */
/* @0x1fcd24 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fcd28 b 0x1fcd0c <_Z19SV_BackgroundVSpeedP9CInstanceiP6RValue+0x34> */
/* @0x1fcd2c andseq r0, pc, r4, asr #24 */

/* ── FUNC 0x1fcd30 · SV_BackgroundBlend(CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x1fcd30 ldr r3, [pc, #0x88] */
/* @0x1fcd34 cmp r1, #7 */
/* @0x1fcd38 push {r4, lr} */
/* @0x1fcd3c ldr r3, [pc, r3] */
/* @0x1fcd40 movls r0, r1 */
/* @0x1fcd44 movhi r0, #0 */
/* @0x1fcd48 ldrb r1, [r3] */
/* @0x1fcd4c cmp r1, #0 */
/* @0x1fcd50 beq 0x1fcdac <_Z18SV_BackgroundBlendP9CInstanceiP6RValue+0x7c> */
/* @0x1fcd54 ldr r3, [pc, #0x68] */
/* @0x1fcd58 ldr r1, [r2, #0xc] */
/* @0x1fcd5c ldr r3, [pc, r3] */
/* @0x1fcd60 bic r1, r1, #-16777216 */
/* @0x1fcd64 ldr r3, [r3] */
/* @0x1fcd68 cmp r1, #0 */
/* @0x1fcd6c add r0, r3, r0, lsl #2 */
/* @0x1fcd70 ldr r4, [r0, #0x24] */
/* @0x1fcd74 bne 0x1fcd98 <_Z18SV_BackgroundBlendP9CInstanceiP6RValue+0x68> */
/* @0x1fcd78 ldr r12, [r2] */
/* @0x1fcd7c ldr r3, [r2, #0x4] */
/* @0x1fcd80 mov r0, r12 */
/* @0x1fcd84 mov r1, r3 */
/* @0x1fcd88 bl 0xb66e8 <lrint@plt> */
/* @0x1fcd8c str r0, [r4, #0x24] */
/* @0x1fcd90 mov r0, #1 */
/* @0x1fcd94 pop {r4, pc} */
/* @0x1fcd98 mov r0, r2 */
/* @0x1fcd9c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fcda0 mov r12, r0 */
/* @0x1fcda4 mov r3, r1 */
/* @0x1fcda8 b 0x1fcd80 <_Z18SV_BackgroundBlendP9CInstanceiP6RValue+0x50> */
/* @0x1fcdac ldr r0, [pc, #0x14] */
/* @0x1fcdb0 add r0, pc, r0 */
/* @0x1fcdb4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1fcdb8 mov r0, #1 */
/* @0x1fcdbc pop {r4, pc} */
/* @0x1fcdc0 andseq r3, pc, r0, lsl #31 */
/* @0x1fcdc4 andseq r0, pc, r12, asr #23 */
/* @0x1fcdc8 andseq r5, r5, r0, asr r12 */

/* ── FUNC 0x1fcdcc · SV_BackgroundAlpha(CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1fcdcc ldr r3, [pc, #0x4c] */
/* @0x1fcdd0 cmp r1, #7 */
/* @0x1fcdd4 ldr r0, [r2, #0xc] */
/* @0x1fcdd8 ldr r3, [pc, r3] */
/* @0x1fcddc movhi r1, #0 */
/* @0x1fcde0 bic r0, r0, #-16777216 */
/* @0x1fcde4 ldr r3, [r3] */
/* @0x1fcde8 cmp r0, #0 */
/* @0x1fcdec push {r4, lr} */
/* @0x1fcdf0 add r1, r3, r1, lsl #2 */
/* @0x1fcdf4 ldr r4, [r1, #0x24] */
/* @0x1fcdf8 bne 0x1fce14 <_Z18SV_BackgroundAlphaP9CInstanceiP6RValue+0x48> */
/* @0x1fcdfc ldm r2, {r0, r1} */
/* @0x1fce00 vmov d6, r0, r1 */
/* @0x1fce04 mov r0, #1 */
/* @0x1fce08 vcvt.f32.f64 s15, d6 */
/* @0x1fce0c vstr s15, [r4, #40] */
/* @0x1fce10 pop {r4, pc} */
/* @0x1fce14 mov r0, r2 */
/* @0x1fce18 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fce1c b 0x1fce00 <_Z18SV_BackgroundAlphaP9CInstanceiP6RValue+0x34> */
/* @0x1fce20 andseq r0, pc, r0, asr r11 */

/* ── FUNC 0x1fce24 · SV_RoomHeight(CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1fce24 ldr r1, [r2, #0xc] */
/* @0x1fce28 ldr r3, [pc, #0x48] */
/* @0x1fce2c bic r1, r1, #-16777216 */
/* @0x1fce30 ldr r3, [pc, r3] */
/* @0x1fce34 cmp r1, #0 */
/* @0x1fce38 push {r4, lr} */
/* @0x1fce3c ldr r4, [r3] */
/* @0x1fce40 bne 0x1fce64 <_Z13SV_RoomHeightP9CInstanceiP6RValue+0x40> */
/* @0x1fce44 ldr r12, [r2] */
/* @0x1fce48 ldr r3, [r2, #0x4] */
/* @0x1fce4c mov r0, r12 */
/* @0x1fce50 mov r1, r3 */
/* @0x1fce54 bl 0xb66e8 <lrint@plt> */
/* @0x1fce58 str r0, [r4, #0x14] */
/* @0x1fce5c mov r0, #1 */
/* @0x1fce60 pop {r4, pc} */
/* @0x1fce64 mov r0, r2 */
/* @0x1fce68 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fce6c mov r12, r0 */
/* @0x1fce70 mov r3, r1 */
/* @0x1fce74 b 0x1fce4c <_Z13SV_RoomHeightP9CInstanceiP6RValue+0x28> */
/* @0x1fce78 ldrsheq r0, [pc], -r8 */

/* ── FUNC 0x1fce7c · SV_RoomWidth(CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1fce7c ldr r1, [r2, #0xc] */
/* @0x1fce80 ldr r3, [pc, #0x48] */
/* @0x1fce84 bic r1, r1, #-16777216 */
/* @0x1fce88 ldr r3, [pc, r3] */
/* @0x1fce8c cmp r1, #0 */
/* @0x1fce90 push {r4, lr} */
/* @0x1fce94 ldr r4, [r3] */
/* @0x1fce98 bne 0x1fcebc <_Z12SV_RoomWidthP9CInstanceiP6RValue+0x40> */
/* @0x1fce9c ldr r12, [r2] */
/* @0x1fcea0 ldr r3, [r2, #0x4] */
/* @0x1fcea4 mov r0, r12 */
/* @0x1fcea8 mov r1, r3 */
/* @0x1fceac bl 0xb66e8 <lrint@plt> */
/* @0x1fceb0 str r0, [r4, #0x10] */
/* @0x1fceb4 mov r0, #1 */
/* @0x1fceb8 pop {r4, pc} */
/* @0x1fcebc mov r0, r2 */
/* @0x1fcec0 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fcec4 mov r12, r0 */
/* @0x1fcec8 mov r3, r1 */
/* @0x1fcecc b 0x1fcea4 <_Z12SV_RoomWidthP9CInstanceiP6RValue+0x28> */
/* @0x1fced0 andseq r0, pc, r0, lsr #21 */

/* ── FUNC 0x1fced4 · SV_RoomSpeed(CInstance*, int, RValue*) · size=200 · insn=50 */
/* @0x1fced4 ldr r3, [r2, #0xc] */
/* @0x1fced8 push {r4, r5, r6, lr} */
/* @0x1fcedc bic r3, r3, #-16777216 */
/* @0x1fcee0 cmp r3, #0 */
/* @0x1fcee4 bne 0x1fcf44 <_Z12SV_RoomSpeedP9CInstanceiP6RValue+0x70> */
/* @0x1fcee8 ldm r2, {r4, r5} */
/* @0x1fceec mov r0, r4 */
/* @0x1fcef0 mov r1, r5 */
/* @0x1fcef4 bl 0xb66e8 <lrint@plt> */
/* @0x1fcef8 cmp r0, #0 */
/* @0x1fcefc movle r6, #0 */
/* @0x1fcf00 movgt r6, #1 */
/* @0x1fcf04 cmp r6, #0 */
/* @0x1fcf08 beq 0x1fcf58 <_Z12SV_RoomSpeedP9CInstanceiP6RValue+0x84> */
/* @0x1fcf0c ldr r3, [pc, #0x78] */
/* @0x1fcf10 ldr r3, [pc, r3] */
/* @0x1fcf14 ldrb r3, [r3] */
/* @0x1fcf18 cmp r3, #0 */
/* @0x1fcf1c bne 0x1fcf70 <_Z12SV_RoomSpeedP9CInstanceiP6RValue+0x9c> */
/* @0x1fcf20 vmov d7, r4, r5 */
/* @0x1fcf24 ldr r3, [pc, #0x64] */
/* @0x1fcf28 mov r0, r6 */
/* @0x1fcf2c vcvt.s32.f64 s15, d7 */
/* @0x1fcf30 ldr r3, [pc, r3] */
/* @0x1fcf34 ldr r3, [r3] */
/* @0x1fcf38 vmov r4, s15 */
/* @0x1fcf3c vstr s15, [r3, #12] */
/* @0x1fcf40 pop {r4, r5, r6, pc} */
/* @0x1fcf44 mov r0, r2 */
/* @0x1fcf48 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fcf4c mov r4, r0 */
/* @0x1fcf50 mov r5, r1 */
/* @0x1fcf54 b 0x1fceec <_Z12SV_RoomSpeedP9CInstanceiP6RValue+0x18> */
/* @0x1fcf58 ldr r0, [pc, #0x34] */
/* @0x1fcf5c mov r1, r6 */
/* @0x1fcf60 add r0, pc, r0 */
/* @0x1fcf64 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1fcf68 mov r0, r6 */
/* @0x1fcf6c pop {r4, r5, r6, pc} */
/* @0x1fcf70 ldr r0, [pc, #0x20] */
/* @0x1fcf74 mov r2, r4 */
/* @0x1fcf78 mov r3, r5 */
/* @0x1fcf7c ldr r0, [pc, r0] */
/* @0x1fcf80 bl 0x214800 <_ZN13CTimingSource12SetFrameRateEd> */
/* @0x1fcf84 mov r0, r6 */
/* @0x1fcf88 pop {r4, r5, r6, pc} */
/* @0x1fcf8c andseq r0, pc, r4, lsl r10 */
/* @0x1fcf90 ldrsheq r0, [pc], -r8 */
/* @0x1fcf94 andseq r5, r5, r8, ror #21 */
/* @0x1fcf98 ldrheq r0, [pc], -r0 */

/* ── FUNC 0x1fcf9c · SV_RoomPersistent(CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x1fcf9c ldr r1, [r2, #0xc] */
/* @0x1fcfa0 ldr r3, [pc, #0x64] */
/* @0x1fcfa4 bic r1, r1, #-16777216 */
/* @0x1fcfa8 ldr r3, [pc, r3] */
/* @0x1fcfac cmp r1, #0 */
/* @0x1fcfb0 push {r4, lr} */
/* @0x1fcfb4 ldr r4, [r3] */
/* @0x1fcfb8 bne 0x1fcff8 <_Z17SV_RoomPersistentP9CInstanceiP6RValue+0x5c> */
/* @0x1fcfbc ldr r12, [r2] */
/* @0x1fcfc0 ldr r3, [r2, #0x4] */
/* @0x1fcfc4 mov r1, r3 */
/* @0x1fcfc8 mov r0, r12 */
/* @0x1fcfcc bl 0xb66e8 <lrint@plt> */
/* @0x1fcfd0 vmov.f64 d7, #5.000000e-01 */
/* @0x1fcfd4 vmov s11, r0 */
/* @0x1fcfd8 mov r0, #1 */
/* @0x1fcfdc vcvt.f64.s32 d6, s11 */
/* @0x1fcfe0 vcmpe.f64 d6, d7 */
/* @0x1fcfe4 vmrs APSR_nzcv, fpscr */
/* @0x1fcfe8 movle r3, #0 */
/* @0x1fcfec movgt r3, #1 */
/* @0x1fcff0 strb r3, [r4, #0x18] */
/* @0x1fcff4 pop {r4, pc} */
/* @0x1fcff8 mov r0, r2 */
/* @0x1fcffc bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fd000 mov r12, r0 */
/* @0x1fd004 mov r3, r1 */
/* @0x1fd008 b 0x1fcfc4 <_Z17SV_RoomPersistentP9CInstanceiP6RValue+0x28> */
/* @0x1fd00c andseq r0, pc, r0, lsl #19 */

/* ── FUNC 0x1fd010 · SV_BackgroundColor(CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1fd010 ldr r1, [r2, #0xc] */
/* @0x1fd014 ldr r3, [pc, #0x48] */
/* @0x1fd018 bic r1, r1, #-16777216 */
/* @0x1fd01c ldr r3, [pc, r3] */
/* @0x1fd020 cmp r1, #0 */
/* @0x1fd024 push {r4, lr} */
/* @0x1fd028 ldr r4, [r3] */
/* @0x1fd02c bne 0x1fd050 <_Z18SV_BackgroundColorP9CInstanceiP6RValue+0x40> */
/* @0x1fd030 ldr r12, [r2] */
/* @0x1fd034 ldr r3, [r2, #0x4] */
/* @0x1fd038 mov r0, r12 */
/* @0x1fd03c mov r1, r3 */
/* @0x1fd040 bl 0xb66e8 <lrint@plt> */
/* @0x1fd044 str r0, [r4, #0x1c] */
/* @0x1fd048 mov r0, #1 */
/* @0x1fd04c pop {r4, pc} */
/* @0x1fd050 mov r0, r2 */
/* @0x1fd054 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fd058 mov r12, r0 */
/* @0x1fd05c mov r3, r1 */
/* @0x1fd060 b 0x1fd038 <_Z18SV_BackgroundColorP9CInstanceiP6RValue+0x28> */
/* @0x1fd064 andseq r0, pc, r12, lsl #18 */

/* ── FUNC 0x1fd068 · SV_BackgroundShowColor(CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x1fd068 ldr r1, [r2, #0xc] */
/* @0x1fd06c ldr r3, [pc, #0x64] */
/* @0x1fd070 bic r1, r1, #-16777216 */
/* @0x1fd074 ldr r3, [pc, r3] */
/* @0x1fd078 cmp r1, #0 */
/* @0x1fd07c push {r4, lr} */
/* @0x1fd080 ldr r4, [r3] */
/* @0x1fd084 bne 0x1fd0c4 <_Z22SV_BackgroundShowColorP9CInstanceiP6RValue+0x5c> */
/* @0x1fd088 ldr r12, [r2] */
/* @0x1fd08c ldr r3, [r2, #0x4] */
/* @0x1fd090 mov r1, r3 */
/* @0x1fd094 mov r0, r12 */
/* @0x1fd098 bl 0xb66e8 <lrint@plt> */
/* @0x1fd09c vmov.f64 d7, #5.000000e-01 */
/* @0x1fd0a0 vmov s11, r0 */
/* @0x1fd0a4 mov r0, #1 */
/* @0x1fd0a8 vcvt.f64.s32 d6, s11 */
/* @0x1fd0ac vcmpe.f64 d6, d7 */
/* @0x1fd0b0 vmrs APSR_nzcv, fpscr */
/* @0x1fd0b4 movle r3, #0 */
/* @0x1fd0b8 movgt r3, #1 */
/* @0x1fd0bc strb r3, [r4, #0x20] */
/* @0x1fd0c0 pop {r4, pc} */
/* @0x1fd0c4 mov r0, r2 */
/* @0x1fd0c8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fd0cc mov r12, r0 */
/* @0x1fd0d0 mov r3, r1 */
/* @0x1fd0d4 b 0x1fd090 <_Z22SV_BackgroundShowColorP9CInstanceiP6RValue+0x28> */
/* @0x1fd0d8 ldrheq r0, [pc], -r4 */

/* ── FUNC 0x1fd0dc · SV_ViewEnabled(CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x1fd0dc ldr r1, [r2, #0xc] */
/* @0x1fd0e0 ldr r3, [pc, #0x64] */
/* @0x1fd0e4 bic r1, r1, #-16777216 */
/* @0x1fd0e8 ldr r3, [pc, r3] */
/* @0x1fd0ec cmp r1, #0 */
/* @0x1fd0f0 push {r4, lr} */
/* @0x1fd0f4 ldr r4, [r3] */
/* @0x1fd0f8 bne 0x1fd138 <_Z14SV_ViewEnabledP9CInstanceiP6RValue+0x5c> */
/* @0x1fd0fc ldr r12, [r2] */
/* @0x1fd100 ldr r3, [r2, #0x4] */
/* @0x1fd104 mov r1, r3 */
/* @0x1fd108 mov r0, r12 */
/* @0x1fd10c bl 0xb66e8 <lrint@plt> */
/* @0x1fd110 vmov.f64 d7, #5.000000e-01 */
/* @0x1fd114 vmov s11, r0 */
/* @0x1fd118 mov r0, #1 */
/* @0x1fd11c vcvt.f64.s32 d6, s11 */
/* @0x1fd120 vcmpe.f64 d6, d7 */
/* @0x1fd124 vmrs APSR_nzcv, fpscr */
/* @0x1fd128 movle r3, #0 */
/* @0x1fd12c movgt r3, #1 */
/* @0x1fd130 strb r3, [r4, #0x44] */
/* @0x1fd134 pop {r4, pc} */
/* @0x1fd138 mov r0, r2 */
/* @0x1fd13c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fd140 mov r12, r0 */
/* @0x1fd144 mov r3, r1 */
/* @0x1fd148 b 0x1fd104 <_Z14SV_ViewEnabledP9CInstanceiP6RValue+0x28> */
/* @0x1fd14c andseq r0, pc, r0, asr #16 */

/* ── FUNC 0x1fd150 · SetWorkingDirectory() · size=52 · insn=13 */
/* @0x1fd150 push {r4, lr} */
/* @0x1fd154 ldr r4, [pc, #0x20] */
/* @0x1fd158 ldr r4, [pc, r4] */
/* @0x1fd15c ldr r3, [r4] */
/* @0x1fd160 cmp r3, #0 */
/* @0x1fd164 popne {r4, pc} */
/* @0x1fd168 ldr r0, [pc, #0x10] */
/* @0x1fd16c add r0, pc, r0 */
/* @0x1fd170 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1fd174 str r0, [r4] */
/* @0x1fd178 pop {r4, pc} */
/* @0x1fd17c andseq r3, pc, r0, lsl #10 */
/* @0x1fd180 andseq r5, r5, r12, lsl #18 */

/* ── FUNC 0x1fd184 · InitGlobalVariables() · size=4988 · insn=1247 */
/* @0x1fd184 push {r4, r5, r6, r7, r8, lr} */
/* @0x1fd188 mov r2, #0 */
/* @0x1fd18c ldr r4, [pc, #0xe78] */
/* @0x1fd190 mov r3, r2 */
/* @0x1fd194 ldr r12, [pc, #0xe74] */
/* @0x1fd198 add r4, pc, r4 */
/* @0x1fd19c ldr r0, [pc, #0xe70] */
/* @0x1fd1a0 ldr r1, [pc, #0xe70] */
/* @0x1fd1a4 ldr lr, [r4, r12] */
/* @0x1fd1a8 ldr r12, [r4, r0] */
/* @0x1fd1ac ldr r0, [pc, #0xe68] */
/* @0x1fd1b0 ldr lr, [lr] */
/* @0x1fd1b4 add r0, pc, r0 */
/* @0x1fd1b8 str lr, [r12] */
/* @0x1fd1bc ldr r1, [r4, r1] */
/* @0x1fd1c0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd1c4 ldr r1, [pc, #0xe54] */
/* @0x1fd1c8 ldr r2, [pc, #0xe54] */
/* @0x1fd1cc mov r3, #1 */
/* @0x1fd1d0 ldr r0, [pc, #0xe50] */
/* @0x1fd1d4 ldr r1, [r4, r1] */
/* @0x1fd1d8 ldr r2, [r4, r2] */
/* @0x1fd1dc add r0, pc, r0 */
/* @0x1fd1e0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd1e4 ldr r1, [pc, #0xe40] */
/* @0x1fd1e8 ldr r2, [pc, #0xe40] */
/* @0x1fd1ec mov r3, #1 */
/* @0x1fd1f0 ldr r0, [pc, #0xe3c] */
/* @0x1fd1f4 ldr r1, [r4, r1] */
/* @0x1fd1f8 ldr r2, [r4, r2] */
/* @0x1fd1fc add r0, pc, r0 */
/* @0x1fd200 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd204 ldr r1, [pc, #0xe2c] */
/* @0x1fd208 ldr r2, [pc, #0xe2c] */
/* @0x1fd20c mov r3, #1 */
/* @0x1fd210 ldr r0, [pc, #0xe28] */
/* @0x1fd214 ldr r1, [r4, r1] */
/* @0x1fd218 ldr r2, [r4, r2] */
/* @0x1fd21c add r0, pc, r0 */
/* @0x1fd220 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd224 ldr r1, [pc, #0xe18] */
/* @0x1fd228 ldr r2, [pc, #0xe18] */
/* @0x1fd22c mov r3, #1 */
/* @0x1fd230 ldr r0, [pc, #0xe14] */
/* @0x1fd234 ldr r1, [r4, r1] */
/* @0x1fd238 ldr r2, [r4, r2] */
/* @0x1fd23c add r0, pc, r0 */
/* @0x1fd240 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd244 ldr r1, [pc, #0xe04] */
/* @0x1fd248 ldr r2, [pc, #0xe04] */
/* @0x1fd24c mov r3, #1 */
/* @0x1fd250 ldr r0, [pc, #0xe00] */
/* @0x1fd254 ldr r1, [r4, r1] */
/* @0x1fd258 ldr r2, [r4, r2] */
/* @0x1fd25c add r0, pc, r0 */
/* @0x1fd260 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd264 ldr r1, [pc, #0xdf0] */
/* @0x1fd268 ldr r2, [pc, #0xdf0] */
/* @0x1fd26c mov r3, #1 */
/* @0x1fd270 ldr r0, [pc, #0xdec] */
/* @0x1fd274 ldr r1, [r4, r1] */
/* @0x1fd278 ldr r2, [r4, r2] */
/* @0x1fd27c add r0, pc, r0 */
/* @0x1fd280 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd284 ldr r1, [pc, #0xddc] */
/* @0x1fd288 ldr r2, [pc, #0xddc] */
/* @0x1fd28c mov r3, #1 */
/* @0x1fd290 ldr r0, [pc, #0xdd8] */
/* @0x1fd294 ldr r1, [r4, r1] */
/* @0x1fd298 ldr r2, [r4, r2] */
/* @0x1fd29c add r0, pc, r0 */
/* @0x1fd2a0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd2a4 ldr r1, [pc, #0xdc8] */
/* @0x1fd2a8 ldr r2, [pc, #0xdc8] */
/* @0x1fd2ac mov r3, #1 */
/* @0x1fd2b0 ldr r0, [pc, #0xdc4] */
/* @0x1fd2b4 ldr r1, [r4, r1] */
/* @0x1fd2b8 ldr r2, [r4, r2] */
/* @0x1fd2bc add r0, pc, r0 */
/* @0x1fd2c0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd2c4 ldr r1, [pc, #0xdb4] */
/* @0x1fd2c8 ldr r2, [pc, #0xdb4] */
/* @0x1fd2cc mov r3, #1 */
/* @0x1fd2d0 ldr r0, [pc, #0xdb0] */
/* @0x1fd2d4 ldr r1, [r4, r1] */
/* @0x1fd2d8 ldr r2, [r4, r2] */
/* @0x1fd2dc add r0, pc, r0 */
/* @0x1fd2e0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd2e4 ldr r1, [pc, #0xda0] */
/* @0x1fd2e8 ldr r2, [pc, #0xda0] */
/* @0x1fd2ec mov r3, #1 */
/* @0x1fd2f0 ldr r0, [pc, #0xd9c] */
/* @0x1fd2f4 ldr r1, [r4, r1] */
/* @0x1fd2f8 ldr r2, [r4, r2] */
/* @0x1fd2fc add r0, pc, r0 */
/* @0x1fd300 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd304 ldr r1, [pc, #0xd8c] */
/* @0x1fd308 ldr r2, [pc, #0xd8c] */
/* @0x1fd30c mov r3, #1 */
/* @0x1fd310 ldr r0, [pc, #0xd88] */
/* @0x1fd314 ldr r1, [r4, r1] */
/* @0x1fd318 ldr r2, [r4, r2] */
/* @0x1fd31c add r0, pc, r0 */
/* @0x1fd320 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd324 ldr r1, [pc, #0xd78] */
/* @0x1fd328 ldr r2, [pc, #0xd78] */
/* @0x1fd32c mov r3, #1 */
/* @0x1fd330 ldr r0, [pc, #0xd74] */
/* @0x1fd334 ldr r1, [r4, r1] */
/* @0x1fd338 ldr r2, [r4, r2] */
/* @0x1fd33c add r0, pc, r0 */
/* @0x1fd340 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd344 ldr r1, [pc, #0xd64] */
/* @0x1fd348 ldr r2, [pc, #0xd64] */
/* @0x1fd34c mov r3, #1 */
/* @0x1fd350 ldr r0, [pc, #0xd60] */
/* @0x1fd354 ldr r1, [r4, r1] */
/* @0x1fd358 ldr r2, [r4, r2] */
/* @0x1fd35c add r0, pc, r0 */
/* @0x1fd360 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd364 ldr r1, [pc, #0xd50] */
/* @0x1fd368 ldr r2, [pc, #0xd50] */
/* @0x1fd36c mov r3, #1 */
/* @0x1fd370 ldr r0, [pc, #0xd4c] */
/* @0x1fd374 ldr r1, [r4, r1] */
/* @0x1fd378 ldr r2, [r4, r2] */
/* @0x1fd37c add r0, pc, r0 */
/* @0x1fd380 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd384 ldr r1, [pc, #0xd3c] */
/* @0x1fd388 ldr r2, [pc, #0xd3c] */
/* @0x1fd38c mov r3, #1 */
/* @0x1fd390 ldr r0, [pc, #0xd38] */
/* @0x1fd394 ldr r1, [r4, r1] */
/* @0x1fd398 ldr r2, [r4, r2] */
/* @0x1fd39c add r0, pc, r0 */
/* @0x1fd3a0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd3a4 ldr r1, [pc, #0xd28] */
/* @0x1fd3a8 ldr r2, [pc, #0xd28] */
/* @0x1fd3ac mov r3, #1 */
/* @0x1fd3b0 ldr r0, [pc, #0xd24] */
/* @0x1fd3b4 ldr r1, [r4, r1] */
/* @0x1fd3b8 ldr r2, [r4, r2] */
/* @0x1fd3bc add r0, pc, r0 */
/* @0x1fd3c0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd3c4 ldr r1, [pc, #0xd14] */
/* @0x1fd3c8 ldr r2, [pc, #0xd14] */
/* @0x1fd3cc mov r3, #1 */
/* @0x1fd3d0 ldr r0, [pc, #0xd10] */
/* @0x1fd3d4 ldr r1, [r4, r1] */
/* @0x1fd3d8 ldr r2, [r4, r2] */
/* @0x1fd3dc add r0, pc, r0 */
/* @0x1fd3e0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd3e4 ldr r1, [pc, #0xd00] */
/* @0x1fd3e8 ldr r0, [pc, #0xd00] */
/* @0x1fd3ec mov r2, #0 */
/* @0x1fd3f0 mov r3, #1 */
/* @0x1fd3f4 ldr r1, [r4, r1] */
/* @0x1fd3f8 add r0, pc, r0 */
/* @0x1fd3fc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd400 ldr r1, [pc, #0xcec] */
/* @0x1fd404 ldr r0, [pc, #0xcec] */
/* @0x1fd408 mov r2, #0 */
/* @0x1fd40c mov r3, #1 */
/* @0x1fd410 ldr r1, [r4, r1] */
/* @0x1fd414 add r0, pc, r0 */
/* @0x1fd418 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd41c ldr r1, [pc, #0xcd8] */
/* @0x1fd420 ldr r0, [pc, #0xcd8] */
/* @0x1fd424 mov r2, #0 */
/* @0x1fd428 mov r3, r2 */
/* @0x1fd42c ldr r1, [r4, r1] */
/* @0x1fd430 add r0, pc, r0 */
/* @0x1fd434 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd438 ldr r1, [pc, #0xcc4] */
/* @0x1fd43c ldr r0, [pc, #0xcc4] */
/* @0x1fd440 mov r2, #0 */
/* @0x1fd444 mov r3, r2 */
/* @0x1fd448 ldr r1, [r4, r1] */
/* @0x1fd44c add r0, pc, r0 */
/* @0x1fd450 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd454 ldr r1, [pc, #0xcb0] */
/* @0x1fd458 ldr r0, [pc, #0xcb0] */
/* @0x1fd45c mov r2, #0 */
/* @0x1fd460 mov r3, r2 */
/* @0x1fd464 ldr r1, [r4, r1] */
/* @0x1fd468 add r0, pc, r0 */
/* @0x1fd46c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd470 ldr r1, [pc, #0xc9c] */
/* @0x1fd474 ldr r2, [pc, #0xc9c] */
/* @0x1fd478 mov r3, #1 */
/* @0x1fd47c ldr r0, [pc, #0xc98] */
/* @0x1fd480 ldr r1, [r4, r1] */
/* @0x1fd484 ldr r2, [r4, r2] */
/* @0x1fd488 add r0, pc, r0 */
/* @0x1fd48c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd490 ldr r1, [pc, #0xc88] */
/* @0x1fd494 ldr r0, [pc, #0xc88] */
/* @0x1fd498 mov r2, #0 */
/* @0x1fd49c mov r3, r2 */
/* @0x1fd4a0 ldr r1, [r4, r1] */
/* @0x1fd4a4 add r0, pc, r0 */
/* @0x1fd4a8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd4ac ldr r1, [pc, #0xc74] */
/* @0x1fd4b0 ldr r0, [pc, #0xc74] */
/* @0x1fd4b4 mov r2, #0 */
/* @0x1fd4b8 mov r3, r2 */
/* @0x1fd4bc ldr r1, [r4, r1] */
/* @0x1fd4c0 add r0, pc, r0 */
/* @0x1fd4c4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd4c8 ldr r1, [pc, #0xc60] */
/* @0x1fd4cc ldr r2, [pc, #0xc60] */
/* @0x1fd4d0 mov r3, #1 */
/* @0x1fd4d4 ldr r0, [pc, #0xc5c] */
/* @0x1fd4d8 ldr r1, [r4, r1] */
/* @0x1fd4dc ldr r2, [r4, r2] */
/* @0x1fd4e0 add r0, pc, r0 */
/* @0x1fd4e4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd4e8 ldr r1, [pc, #0xc4c] */
/* @0x1fd4ec ldr r2, [pc, #0xc4c] */
/* @0x1fd4f0 mov r3, #1 */
/* @0x1fd4f4 ldr r0, [pc, #0xc48] */
/* @0x1fd4f8 ldr r1, [r4, r1] */
/* @0x1fd4fc ldr r2, [r4, r2] */
/* @0x1fd500 add r0, pc, r0 */
/* @0x1fd504 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd508 ldr r1, [pc, #0xc38] */
/* @0x1fd50c ldr r2, [pc, #0xc38] */
/* @0x1fd510 mov r3, #1 */
/* @0x1fd514 ldr r0, [pc, #0xc34] */
/* @0x1fd518 ldr r1, [r4, r1] */
/* @0x1fd51c ldr r2, [r4, r2] */
/* @0x1fd520 add r0, pc, r0 */
/* @0x1fd524 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd528 ldr r1, [pc, #0xc24] */
/* @0x1fd52c ldr r2, [pc, #0xc24] */
/* @0x1fd530 mov r3, #1 */
/* @0x1fd534 ldr r0, [pc, #0xc20] */
/* @0x1fd538 ldr r1, [r4, r1] */
/* @0x1fd53c ldr r2, [r4, r2] */
/* @0x1fd540 add r0, pc, r0 */
/* @0x1fd544 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd548 ldr r1, [pc, #0xc10] */
/* @0x1fd54c ldr r2, [pc, #0xc10] */
/* @0x1fd550 mov r3, #1 */
/* @0x1fd554 ldr r0, [pc, #0xc0c] */
/* @0x1fd558 ldr r1, [r4, r1] */
/* @0x1fd55c ldr r2, [r4, r2] */
/* @0x1fd560 add r0, pc, r0 */
/* @0x1fd564 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd568 ldr r1, [pc, #0xbfc] */
/* @0x1fd56c ldr r0, [pc, #0xbfc] */
/* @0x1fd570 mov r2, #0 */
/* @0x1fd574 mov r3, r2 */
/* @0x1fd578 ldr r1, [r4, r1] */
/* @0x1fd57c add r0, pc, r0 */
/* @0x1fd580 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd584 ldr r1, [pc, #0xbe8] */
/* @0x1fd588 ldr r0, [pc, #0xbe8] */
/* @0x1fd58c mov r2, #0 */
/* @0x1fd590 mov r3, r2 */
/* @0x1fd594 ldr r1, [r4, r1] */
/* @0x1fd598 add r0, pc, r0 */
/* @0x1fd59c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd5a0 ldr r1, [pc, #0xbd4] */
/* @0x1fd5a4 ldr r0, [pc, #0xbd4] */
/* @0x1fd5a8 mov r2, #0 */
/* @0x1fd5ac mov r3, r2 */
/* @0x1fd5b0 ldr r1, [r4, r1] */
/* @0x1fd5b4 add r0, pc, r0 */
/* @0x1fd5b8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd5bc ldr r1, [pc, #0xbc0] */
/* @0x1fd5c0 ldr r0, [pc, #0xbc0] */
/* @0x1fd5c4 mov r2, #0 */
/* @0x1fd5c8 mov r3, r2 */
/* @0x1fd5cc ldr r1, [r4, r1] */
/* @0x1fd5d0 add r0, pc, r0 */
/* @0x1fd5d4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd5d8 ldr r1, [pc, #0xbac] */
/* @0x1fd5dc ldr r0, [pc, #0xbac] */
/* @0x1fd5e0 mov r2, #0 */
/* @0x1fd5e4 mov r3, r2 */
/* @0x1fd5e8 ldr r1, [r4, r1] */
/* @0x1fd5ec add r0, pc, r0 */
/* @0x1fd5f0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd5f4 ldr r1, [pc, #0xb98] */
/* @0x1fd5f8 ldr r0, [pc, #0xb98] */
/* @0x1fd5fc mov r2, #0 */
/* @0x1fd600 mov r3, r2 */
/* @0x1fd604 ldr r1, [r4, r1] */
/* @0x1fd608 add r0, pc, r0 */
/* @0x1fd60c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd610 ldr r1, [pc, #0xb84] */
/* @0x1fd614 ldr r0, [pc, #0xb84] */
/* @0x1fd618 mov r2, #0 */
/* @0x1fd61c mov r3, r2 */
/* @0x1fd620 ldr r1, [r4, r1] */
/* @0x1fd624 add r0, pc, r0 */
/* @0x1fd628 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd62c ldr r1, [pc, #0xb70] */
/* @0x1fd630 ldr r0, [pc, #0xb70] */
/* @0x1fd634 mov r2, #0 */
/* @0x1fd638 mov r3, r2 */
/* @0x1fd63c ldr r1, [r4, r1] */
/* @0x1fd640 add r0, pc, r0 */
/* @0x1fd644 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd648 ldr r1, [pc, #0xb5c] */
/* @0x1fd64c ldr r0, [pc, #0xb5c] */
/* @0x1fd650 mov r2, #0 */
/* @0x1fd654 mov r3, r2 */
/* @0x1fd658 ldr r1, [r4, r1] */
/* @0x1fd65c add r0, pc, r0 */
/* @0x1fd660 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd664 ldr r1, [pc, #0xb48] */
/* @0x1fd668 ldr r0, [pc, #0xb48] */
/* @0x1fd66c mov r2, #0 */
/* @0x1fd670 mov r3, r2 */
/* @0x1fd674 ldr r1, [r4, r1] */
/* @0x1fd678 add r0, pc, r0 */
/* @0x1fd67c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd680 ldr r1, [pc, #0xb34] */
/* @0x1fd684 ldr r2, [pc, #0xb34] */
/* @0x1fd688 mov r3, #0 */
/* @0x1fd68c ldr r0, [pc, #0xb30] */
/* @0x1fd690 ldr r1, [r4, r1] */
/* @0x1fd694 ldr r2, [r4, r2] */
/* @0x1fd698 add r0, pc, r0 */
/* @0x1fd69c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd6a0 ldr r1, [pc, #0xb20] */
/* @0x1fd6a4 ldr r2, [pc, #0xb20] */
/* @0x1fd6a8 mov r3, #0 */
/* @0x1fd6ac ldr r0, [pc, #0xb1c] */
/* @0x1fd6b0 ldr r1, [r4, r1] */
/* @0x1fd6b4 ldr r2, [r4, r2] */
/* @0x1fd6b8 add r0, pc, r0 */
/* @0x1fd6bc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd6c0 ldr r1, [pc, #0xb0c] */
/* @0x1fd6c4 ldr r2, [pc, #0xb0c] */
/* @0x1fd6c8 mov r3, #1 */
/* @0x1fd6cc ldr r0, [pc, #0xb08] */
/* @0x1fd6d0 ldr r1, [r4, r1] */
/* @0x1fd6d4 ldr r2, [r4, r2] */
/* @0x1fd6d8 add r0, pc, r0 */
/* @0x1fd6dc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd6e0 ldr r1, [pc, #0xaf8] */
/* @0x1fd6e4 ldr r2, [pc, #0xaf8] */
/* @0x1fd6e8 mov r3, #1 */
/* @0x1fd6ec ldr r0, [pc, #0xaf4] */
/* @0x1fd6f0 ldr r1, [r4, r1] */
/* @0x1fd6f4 ldr r2, [r4, r2] */
/* @0x1fd6f8 add r0, pc, r0 */
/* @0x1fd6fc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd700 ldr r1, [pc, #0xae4] */
/* @0x1fd704 ldr r2, [pc, #0xae4] */
/* @0x1fd708 mov r3, #1 */
/* @0x1fd70c ldr r0, [pc, #0xae0] */
/* @0x1fd710 ldr r1, [r4, r1] */
/* @0x1fd714 ldr r2, [r4, r2] */
/* @0x1fd718 add r0, pc, r0 */
/* @0x1fd71c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd720 ldr r1, [pc, #0xad0] */
/* @0x1fd724 ldr r2, [pc, #0xad0] */
/* @0x1fd728 mov r3, #1 */
/* @0x1fd72c ldr r0, [pc, #0xacc] */
/* @0x1fd730 ldr r8, [r4, r1] */
/* @0x1fd734 ldr r7, [r4, r2] */
/* @0x1fd738 add r0, pc, r0 */
/* @0x1fd73c mov r1, r8 */
/* @0x1fd740 mov r2, r7 */
/* @0x1fd744 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd748 ldr r1, [pc, #0xab4] */
/* @0x1fd74c ldr r2, [pc, #0xab4] */
/* @0x1fd750 mov r3, #1 */
/* @0x1fd754 ldr r0, [pc, #0xab0] */
/* @0x1fd758 ldr r6, [r4, r1] */
/* @0x1fd75c ldr r5, [r4, r2] */
/* @0x1fd760 add r0, pc, r0 */
/* @0x1fd764 mov r1, r6 */
/* @0x1fd768 mov r2, r5 */
/* @0x1fd76c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd770 ldr r0, [pc, #0xa98] */
/* @0x1fd774 mov r1, r8 */
/* @0x1fd778 mov r2, r7 */
/* @0x1fd77c add r0, pc, r0 */
/* @0x1fd780 mov r3, #1 */
/* @0x1fd784 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd788 ldr r0, [pc, #0xa84] */
/* @0x1fd78c mov r1, r6 */
/* @0x1fd790 mov r2, r5 */
/* @0x1fd794 add r0, pc, r0 */
/* @0x1fd798 mov r3, #1 */
/* @0x1fd79c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd7a0 ldr r1, [pc, #0xa70] */
/* @0x1fd7a4 ldr r2, [pc, #0xa70] */
/* @0x1fd7a8 mov r3, #1 */
/* @0x1fd7ac ldr r0, [pc, #0xa6c] */
/* @0x1fd7b0 ldr r1, [r4, r1] */
/* @0x1fd7b4 ldr r2, [r4, r2] */
/* @0x1fd7b8 add r0, pc, r0 */
/* @0x1fd7bc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd7c0 ldr r1, [pc, #0xa5c] */
/* @0x1fd7c4 ldr r2, [pc, #0xa5c] */
/* @0x1fd7c8 mov r3, #1 */
/* @0x1fd7cc ldr r0, [pc, #0xa58] */
/* @0x1fd7d0 ldr r1, [r4, r1] */
/* @0x1fd7d4 ldr r2, [r4, r2] */
/* @0x1fd7d8 add r0, pc, r0 */
/* @0x1fd7dc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd7e0 ldr r1, [pc, #0xa48] */
/* @0x1fd7e4 ldr r2, [pc, #0xa48] */
/* @0x1fd7e8 mov r3, #1 */
/* @0x1fd7ec ldr r0, [pc, #0xa44] */
/* @0x1fd7f0 ldr r1, [r4, r1] */
/* @0x1fd7f4 ldr r2, [r4, r2] */
/* @0x1fd7f8 add r0, pc, r0 */
/* @0x1fd7fc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd800 ldr r1, [pc, #0xa34] */
/* @0x1fd804 ldr r2, [pc, #0xa34] */
/* @0x1fd808 mov r3, #1 */
/* @0x1fd80c ldr r0, [pc, #0xa30] */
/* @0x1fd810 ldr r1, [r4, r1] */
/* @0x1fd814 ldr r2, [r4, r2] */
/* @0x1fd818 add r0, pc, r0 */
/* @0x1fd81c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd820 ldr r1, [pc, #0xa20] */
/* @0x1fd824 ldr r2, [pc, #0xa20] */
/* @0x1fd828 mov r3, #1 */
/* @0x1fd82c ldr r0, [pc, #0xa1c] */
/* @0x1fd830 ldr r1, [r4, r1] */
/* @0x1fd834 ldr r2, [r4, r2] */
/* @0x1fd838 add r0, pc, r0 */
/* @0x1fd83c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd840 ldr r1, [pc, #0xa0c] */
/* @0x1fd844 ldr r0, [pc, #0xa0c] */
/* @0x1fd848 mov r2, #0 */
/* @0x1fd84c mov r3, r2 */
/* @0x1fd850 ldr r1, [r4, r1] */
/* @0x1fd854 add r0, pc, r0 */
/* @0x1fd858 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd85c ldr r1, [pc, #0x9f8] */
/* @0x1fd860 ldr r0, [pc, #0x9f8] */
/* @0x1fd864 mov r2, #0 */
/* @0x1fd868 mov r3, r2 */
/* @0x1fd86c ldr r1, [r4, r1] */
/* @0x1fd870 add r0, pc, r0 */
/* @0x1fd874 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd878 ldr r1, [pc, #0x9e4] */
/* @0x1fd87c ldr r2, [pc, #0x9e4] */
/* @0x1fd880 mov r3, #1 */
/* @0x1fd884 ldr r0, [pc, #0x9e0] */
/* @0x1fd888 ldr r1, [r4, r1] */
/* @0x1fd88c ldr r2, [r4, r2] */
/* @0x1fd890 add r0, pc, r0 */
/* @0x1fd894 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd898 ldr r1, [pc, #0x9d0] */
/* @0x1fd89c ldr r2, [pc, #0x9d0] */
/* @0x1fd8a0 mov r3, #1 */
/* @0x1fd8a4 ldr r0, [pc, #0x9cc] */
/* @0x1fd8a8 ldr r1, [r4, r1] */
/* @0x1fd8ac ldr r2, [r4, r2] */
/* @0x1fd8b0 add r0, pc, r0 */
/* @0x1fd8b4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd8b8 ldr r1, [pc, #0x9bc] */
/* @0x1fd8bc ldr r2, [pc, #0x9bc] */
/* @0x1fd8c0 mov r3, #1 */
/* @0x1fd8c4 ldr r0, [pc, #0x9b8] */
/* @0x1fd8c8 ldr r1, [r4, r1] */
/* @0x1fd8cc ldr r2, [r4, r2] */
/* @0x1fd8d0 add r0, pc, r0 */
/* @0x1fd8d4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd8d8 ldr r1, [pc, #0x9a8] */
/* @0x1fd8dc ldr r2, [pc, #0x9a8] */
/* @0x1fd8e0 mov r3, #1 */
/* @0x1fd8e4 ldr r0, [pc, #0x9a4] */
/* @0x1fd8e8 ldr r1, [r4, r1] */
/* @0x1fd8ec ldr r2, [r4, r2] */
/* @0x1fd8f0 add r0, pc, r0 */
/* @0x1fd8f4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd8f8 ldr r1, [pc, #0x994] */
/* @0x1fd8fc ldr r2, [pc, #0x994] */
/* @0x1fd900 mov r3, #1 */
/* @0x1fd904 ldr r0, [pc, #0x990] */
/* @0x1fd908 ldr r1, [r4, r1] */
/* @0x1fd90c ldr r2, [r4, r2] */
/* @0x1fd910 add r0, pc, r0 */
/* @0x1fd914 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd918 ldr r1, [pc, #0x980] */
/* @0x1fd91c ldr r2, [pc, #0x980] */
/* @0x1fd920 mov r3, #1 */
/* @0x1fd924 ldr r0, [pc, #0x97c] */
/* @0x1fd928 ldr r1, [r4, r1] */
/* @0x1fd92c ldr r2, [r4, r2] */
/* @0x1fd930 add r0, pc, r0 */
/* @0x1fd934 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd938 ldr r1, [pc, #0x96c] */
/* @0x1fd93c ldr r2, [pc, #0x96c] */
/* @0x1fd940 mov r3, #1 */
/* @0x1fd944 ldr r0, [pc, #0x968] */
/* @0x1fd948 ldr r1, [r4, r1] */
/* @0x1fd94c ldr r2, [r4, r2] */
/* @0x1fd950 add r0, pc, r0 */
/* @0x1fd954 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd958 ldr r1, [pc, #0x958] */
/* @0x1fd95c ldr r2, [pc, #0x958] */
/* @0x1fd960 mov r3, #1 */
/* @0x1fd964 ldr r0, [pc, #0x954] */
/* @0x1fd968 ldr r1, [r4, r1] */
/* @0x1fd96c ldr r2, [r4, r2] */
/* @0x1fd970 add r0, pc, r0 */
/* @0x1fd974 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd978 ldr r1, [pc, #0x944] */
/* @0x1fd97c ldr r2, [pc, #0x944] */
/* @0x1fd980 mov r3, #1 */
/* @0x1fd984 ldr r0, [pc, #0x940] */
/* @0x1fd988 ldr r1, [r4, r1] */
/* @0x1fd98c ldr r2, [r4, r2] */
/* @0x1fd990 add r0, pc, r0 */
/* @0x1fd994 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd998 ldr r1, [pc, #0x930] */
/* @0x1fd99c ldr r0, [pc, #0x930] */
/* @0x1fd9a0 mov r2, #0 */
/* @0x1fd9a4 mov r3, r2 */
/* @0x1fd9a8 ldr r1, [r4, r1] */
/* @0x1fd9ac add r0, pc, r0 */
/* @0x1fd9b0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd9b4 ldr r1, [pc, #0x91c] */
/* @0x1fd9b8 ldr r2, [pc, #0x91c] */
/* @0x1fd9bc mov r3, #1 */
/* @0x1fd9c0 ldr r0, [pc, #0x918] */
/* @0x1fd9c4 ldr r1, [r4, r1] */
/* @0x1fd9c8 ldr r2, [r4, r2] */
/* @0x1fd9cc add r0, pc, r0 */
/* @0x1fd9d0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd9d4 ldr r1, [pc, #0x908] */
/* @0x1fd9d8 ldr r2, [pc, #0x908] */
/* @0x1fd9dc mov r3, #1 */
/* @0x1fd9e0 ldr r0, [pc, #0x904] */
/* @0x1fd9e4 ldr r1, [r4, r1] */
/* @0x1fd9e8 ldr r2, [r4, r2] */
/* @0x1fd9ec add r0, pc, r0 */
/* @0x1fd9f0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd9f4 ldr r1, [pc, #0x8f4] */
/* @0x1fd9f8 ldr r2, [pc, #0x8f4] */
/* @0x1fd9fc mov r3, #1 */
/* @0x1fda00 ldr r0, [pc, #0x8f0] */
/* @0x1fda04 ldr r1, [r4, r1] */
/* @0x1fda08 ldr r2, [r4, r2] */
/* @0x1fda0c add r0, pc, r0 */
/* @0x1fda10 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fda14 ldr r1, [pc, #0x8e0] */
/* @0x1fda18 ldr r2, [pc, #0x8e0] */
/* @0x1fda1c mov r3, #1 */
/* @0x1fda20 ldr r0, [pc, #0x8dc] */
/* @0x1fda24 ldr r1, [r4, r1] */
/* @0x1fda28 ldr r2, [r4, r2] */
/* @0x1fda2c add r0, pc, r0 */
/* @0x1fda30 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fda34 ldr r1, [pc, #0x8cc] */
/* @0x1fda38 ldr r2, [pc, #0x8cc] */
/* @0x1fda3c mov r3, #1 */
/* @0x1fda40 ldr r0, [pc, #0x8c8] */
/* @0x1fda44 ldr r1, [r4, r1] */
/* @0x1fda48 ldr r2, [r4, r2] */
/* @0x1fda4c add r0, pc, r0 */
/* @0x1fda50 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fda54 ldr r1, [pc, #0x8b8] */
/* @0x1fda58 ldr r2, [pc, #0x8b8] */
/* @0x1fda5c mov r3, #1 */
/* @0x1fda60 ldr r0, [pc, #0x8b4] */
/* @0x1fda64 ldr r1, [r4, r1] */
/* @0x1fda68 ldr r2, [r4, r2] */
/* @0x1fda6c add r0, pc, r0 */
/* @0x1fda70 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fda74 ldr r1, [pc, #0x8a4] */
/* @0x1fda78 ldr r2, [pc, #0x8a4] */
/* @0x1fda7c mov r3, #1 */
/* @0x1fda80 ldr r0, [pc, #0x8a0] */
/* @0x1fda84 ldr r1, [r4, r1] */
/* @0x1fda88 ldr r2, [r4, r2] */
/* @0x1fda8c add r0, pc, r0 */
/* @0x1fda90 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fda94 ldr r1, [pc, #0x890] */
/* @0x1fda98 ldr r2, [pc, #0x890] */
/* @0x1fda9c mov r3, #1 */
/* @0x1fdaa0 ldr r0, [pc, #0x88c] */
/* @0x1fdaa4 ldr r1, [r4, r1] */
/* @0x1fdaa8 ldr r2, [r4, r2] */
/* @0x1fdaac add r0, pc, r0 */
/* @0x1fdab0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdab4 ldr r1, [pc, #0x87c] */
/* @0x1fdab8 ldr r2, [pc, #0x87c] */
/* @0x1fdabc mov r3, #1 */
/* @0x1fdac0 ldr r0, [pc, #0x878] */
/* @0x1fdac4 ldr r1, [r4, r1] */
/* @0x1fdac8 ldr r2, [r4, r2] */
/* @0x1fdacc add r0, pc, r0 */
/* @0x1fdad0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdad4 ldr r1, [pc, #0x868] */
/* @0x1fdad8 ldr r2, [pc, #0x868] */
/* @0x1fdadc mov r3, #1 */
/* @0x1fdae0 ldr r0, [pc, #0x864] */
/* @0x1fdae4 ldr r1, [r4, r1] */
/* @0x1fdae8 ldr r2, [r4, r2] */
/* @0x1fdaec add r0, pc, r0 */
/* @0x1fdaf0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdaf4 ldr r1, [pc, #0x854] */
/* @0x1fdaf8 ldr r2, [pc, #0x854] */
/* @0x1fdafc mov r3, #1 */
/* @0x1fdb00 ldr r0, [pc, #0x850] */
/* @0x1fdb04 ldr r1, [r4, r1] */
/* @0x1fdb08 ldr r2, [r4, r2] */
/* @0x1fdb0c add r0, pc, r0 */
/* @0x1fdb10 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdb14 ldr r1, [pc, #0x840] */
/* @0x1fdb18 ldr r2, [pc, #0x840] */
/* @0x1fdb1c mov r3, #1 */
/* @0x1fdb20 ldr r0, [pc, #0x83c] */
/* @0x1fdb24 ldr r1, [r4, r1] */
/* @0x1fdb28 ldr r2, [r4, r2] */
/* @0x1fdb2c add r0, pc, r0 */
/* @0x1fdb30 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdb34 ldr r1, [pc, #0x82c] */
/* @0x1fdb38 ldr r2, [pc, #0x82c] */
/* @0x1fdb3c mov r3, #1 */
/* @0x1fdb40 ldr r0, [pc, #0x828] */
/* @0x1fdb44 ldr r1, [r4, r1] */
/* @0x1fdb48 ldr r2, [r4, r2] */
/* @0x1fdb4c add r0, pc, r0 */
/* @0x1fdb50 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdb54 ldr r1, [pc, #0x818] */
/* @0x1fdb58 ldr r2, [pc, #0x818] */
/* @0x1fdb5c mov r3, #1 */
/* @0x1fdb60 ldr r0, [pc, #0x814] */
/* @0x1fdb64 ldr r1, [r4, r1] */
/* @0x1fdb68 ldr r2, [r4, r2] */
/* @0x1fdb6c add r0, pc, r0 */
/* @0x1fdb70 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdb74 ldr r1, [pc, #0x804] */
/* @0x1fdb78 ldr r2, [pc, #0x804] */
/* @0x1fdb7c mov r3, #1 */
/* @0x1fdb80 ldr r0, [pc, #0x800] */
/* @0x1fdb84 ldr r1, [r4, r1] */
/* @0x1fdb88 ldr r2, [r4, r2] */
/* @0x1fdb8c add r0, pc, r0 */
/* @0x1fdb90 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdb94 ldr r1, [pc, #0x7f0] */
/* @0x1fdb98 ldr r2, [pc, #0x7f0] */
/* @0x1fdb9c mov r3, #1 */
/* @0x1fdba0 ldr r0, [pc, #0x7ec] */
/* @0x1fdba4 ldr r1, [r4, r1] */
/* @0x1fdba8 ldr r2, [r4, r2] */
/* @0x1fdbac add r0, pc, r0 */
/* @0x1fdbb0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdbb4 ldr r1, [pc, #0x7dc] */
/* @0x1fdbb8 ldr r2, [pc, #0x7dc] */
/* @0x1fdbbc mov r3, #1 */
/* @0x1fdbc0 ldr r0, [pc, #0x7d8] */
/* @0x1fdbc4 ldr r1, [r4, r1] */
/* @0x1fdbc8 ldr r2, [r4, r2] */
/* @0x1fdbcc add r0, pc, r0 */
/* @0x1fdbd0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdbd4 ldr r1, [pc, #0x7c8] */
/* @0x1fdbd8 ldr r0, [pc, #0x7c8] */
/* @0x1fdbdc mov r2, #0 */
/* @0x1fdbe0 mov r3, r2 */
/* @0x1fdbe4 ldr r1, [r4, r1] */
/* @0x1fdbe8 add r0, pc, r0 */
/* @0x1fdbec bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdbf0 ldr r1, [pc, #0x7b4] */
/* @0x1fdbf4 ldr r0, [pc, #0x7b4] */
/* @0x1fdbf8 mov r2, #0 */
/* @0x1fdbfc mov r3, r2 */
/* @0x1fdc00 ldr r1, [r4, r1] */
/* @0x1fdc04 add r0, pc, r0 */
/* @0x1fdc08 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdc0c ldr r1, [pc, #0x7a0] */
/* @0x1fdc10 ldr r2, [pc, #0x7a0] */
/* @0x1fdc14 mov r3, #1 */
/* @0x1fdc18 ldr r0, [pc, #0x79c] */
/* @0x1fdc1c ldr r1, [r4, r1] */
/* @0x1fdc20 ldr r2, [r4, r2] */
/* @0x1fdc24 add r0, pc, r0 */
/* @0x1fdc28 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdc2c ldr r1, [pc, #0x78c] */
/* @0x1fdc30 ldr r2, [pc, #0x78c] */
/* @0x1fdc34 mov r3, #1 */
/* @0x1fdc38 ldr r0, [pc, #0x788] */
/* @0x1fdc3c ldr r1, [r4, r1] */
/* @0x1fdc40 ldr r2, [r4, r2] */
/* @0x1fdc44 add r0, pc, r0 */
/* @0x1fdc48 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdc4c ldr r1, [pc, #0x778] */
/* @0x1fdc50 ldr r2, [pc, #0x778] */
/* @0x1fdc54 mov r3, #1 */
/* @0x1fdc58 ldr r0, [pc, #0x774] */
/* @0x1fdc5c ldr r1, [r4, r1] */
/* @0x1fdc60 ldr r2, [r4, r2] */
/* @0x1fdc64 add r0, pc, r0 */
/* @0x1fdc68 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdc6c ldr r1, [pc, #0x764] */
/* @0x1fdc70 ldr r2, [pc, #0x764] */
/* @0x1fdc74 mov r3, #1 */
/* @0x1fdc78 ldr r0, [pc, #0x760] */
/* @0x1fdc7c ldr r1, [r4, r1] */
/* @0x1fdc80 ldr r2, [r4, r2] */
/* @0x1fdc84 add r0, pc, r0 */
/* @0x1fdc88 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdc8c ldr r1, [pc, #0x750] */
/* @0x1fdc90 ldr r2, [pc, #0x750] */
/* @0x1fdc94 mov r3, #1 */
/* @0x1fdc98 ldr r0, [pc, #0x74c] */
/* @0x1fdc9c ldr r1, [r4, r1] */
/* @0x1fdca0 ldr r2, [r4, r2] */
/* @0x1fdca4 add r0, pc, r0 */
/* @0x1fdca8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdcac ldr r1, [pc, #0x73c] */
/* @0x1fdcb0 ldr r2, [pc, #0x73c] */
/* @0x1fdcb4 mov r3, #1 */
/* @0x1fdcb8 ldr r0, [pc, #0x738] */
/* @0x1fdcbc ldr r1, [r4, r1] */
/* @0x1fdcc0 ldr r2, [r4, r2] */
/* @0x1fdcc4 add r0, pc, r0 */
/* @0x1fdcc8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdccc ldr r1, [pc, #0x728] */
/* @0x1fdcd0 ldr r2, [pc, #0x728] */
/* @0x1fdcd4 mov r3, #1 */
/* @0x1fdcd8 ldr r0, [pc, #0x724] */
/* @0x1fdcdc ldr r1, [r4, r1] */
/* @0x1fdce0 ldr r2, [r4, r2] */
/* @0x1fdce4 add r0, pc, r0 */
/* @0x1fdce8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdcec ldr r1, [pc, #0x714] */
/* @0x1fdcf0 ldr r2, [pc, #0x714] */
/* @0x1fdcf4 mov r3, #1 */
/* @0x1fdcf8 ldr r0, [pc, #0x710] */
/* @0x1fdcfc ldr r1, [r4, r1] */
/* @0x1fdd00 ldr r2, [r4, r2] */
/* @0x1fdd04 add r0, pc, r0 */
/* @0x1fdd08 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdd0c ldr r1, [pc, #0x700] */
/* @0x1fdd10 ldr r2, [pc, #0x700] */
/* @0x1fdd14 mov r3, #1 */
/* @0x1fdd18 ldr r0, [pc, #0x6fc] */
/* @0x1fdd1c ldr r1, [r4, r1] */
/* @0x1fdd20 ldr r2, [r4, r2] */
/* @0x1fdd24 add r0, pc, r0 */
/* @0x1fdd28 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdd2c ldr r1, [pc, #0x6ec] */
/* @0x1fdd30 ldr r2, [pc, #0x6ec] */
/* @0x1fdd34 mov r3, #1 */
/* @0x1fdd38 ldr r0, [pc, #0x6e8] */
/* @0x1fdd3c ldr r1, [r4, r1] */
/* @0x1fdd40 ldr r2, [r4, r2] */
/* @0x1fdd44 add r0, pc, r0 */
/* @0x1fdd48 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdd4c ldr r1, [pc, #0x6d8] */
/* @0x1fdd50 ldr r2, [pc, #0x6d8] */
/* @0x1fdd54 mov r3, #1 */
/* @0x1fdd58 ldr r0, [pc, #0x6d4] */
/* @0x1fdd5c ldr r1, [r4, r1] */
/* @0x1fdd60 ldr r2, [r4, r2] */
/* @0x1fdd64 add r0, pc, r0 */
/* @0x1fdd68 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdd6c ldr r1, [pc, #0x6c4] */
/* @0x1fdd70 ldr r2, [pc, #0x6c4] */
/* @0x1fdd74 mov r3, #1 */
/* @0x1fdd78 ldr r0, [pc, #0x6c0] */
/* @0x1fdd7c ldr r1, [r4, r1] */
/* @0x1fdd80 ldr r2, [r4, r2] */
/* @0x1fdd84 add r0, pc, r0 */
/* @0x1fdd88 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdd8c ldr r1, [pc, #0x6b0] */
/* @0x1fdd90 ldr r2, [pc, #0x6b0] */
/* @0x1fdd94 mov r3, #1 */
/* @0x1fdd98 ldr r0, [pc, #0x6ac] */
/* @0x1fdd9c ldr r1, [r4, r1] */
/* @0x1fdda0 ldr r2, [r4, r2] */
/* @0x1fdda4 add r0, pc, r0 */
/* @0x1fdda8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fddac ldr r1, [pc, #0x69c] */
/* @0x1fddb0 ldr r0, [pc, #0x69c] */
/* @0x1fddb4 mov r2, #0 */
/* @0x1fddb8 mov r3, r2 */
/* @0x1fddbc ldr r1, [r4, r1] */
/* @0x1fddc0 add r0, pc, r0 */
/* @0x1fddc4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fddc8 ldr r1, [pc, #0x688] */
/* @0x1fddcc ldr r0, [pc, #0x688] */
/* @0x1fddd0 mov r2, #0 */
/* @0x1fddd4 mov r3, r2 */
/* @0x1fddd8 ldr r1, [r4, r1] */
/* @0x1fdddc add r0, pc, r0 */
/* @0x1fdde0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdde4 ldr r1, [pc, #0x674] */
/* @0x1fdde8 ldr r0, [pc, #0x674] */
/* @0x1fddec mov r2, #0 */
/* @0x1fddf0 mov r3, r2 */
/* @0x1fddf4 ldr r1, [r4, r1] */
/* @0x1fddf8 add r0, pc, r0 */
/* @0x1fddfc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fde00 ldr r1, [pc, #0x660] */
/* @0x1fde04 ldr r0, [pc, #0x660] */
/* @0x1fde08 mov r2, #0 */
/* @0x1fde0c mov r3, r2 */
/* @0x1fde10 ldr r1, [r4, r1] */
/* @0x1fde14 add r0, pc, r0 */
/* @0x1fde18 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fde1c ldr r1, [pc, #0x64c] */
/* @0x1fde20 ldr r0, [pc, #0x64c] */
/* @0x1fde24 mov r2, #0 */
/* @0x1fde28 mov r3, r2 */
/* @0x1fde2c ldr r1, [r4, r1] */
/* @0x1fde30 add r0, pc, r0 */
/* @0x1fde34 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fde38 ldr r1, [pc, #0x638] */
/* @0x1fde3c ldr r0, [pc, #0x638] */
/* @0x1fde40 mov r2, #0 */
/* @0x1fde44 mov r3, r2 */
/* @0x1fde48 ldr r1, [r4, r1] */
/* @0x1fde4c add r0, pc, r0 */
/* @0x1fde50 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fde54 ldr r1, [pc, #0x624] */
/* @0x1fde58 ldr r0, [pc, #0x624] */
/* @0x1fde5c mov r2, #0 */
/* @0x1fde60 mov r3, r2 */
/* @0x1fde64 ldr r1, [r4, r1] */
/* @0x1fde68 add r0, pc, r0 */
/* @0x1fde6c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fde70 ldr r1, [pc, #0x610] */
/* @0x1fde74 ldr r0, [pc, #0x610] */
/* @0x1fde78 mov r2, #0 */
/* @0x1fde7c mov r3, r2 */
/* @0x1fde80 ldr r1, [r4, r1] */
/* @0x1fde84 add r0, pc, r0 */
/* @0x1fde88 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fde8c ldr r1, [pc, #0x5fc] */
/* @0x1fde90 ldr r0, [pc, #0x5fc] */
/* @0x1fde94 mov r2, #0 */
/* @0x1fde98 mov r3, r2 */
/* @0x1fde9c ldr r1, [r4, r1] */
/* @0x1fdea0 add r0, pc, r0 */
/* @0x1fdea4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdea8 ldr r1, [pc, #0x5e8] */
/* @0x1fdeac ldr r0, [pc, #0x5e8] */
/* @0x1fdeb0 mov r2, #0 */
/* @0x1fdeb4 mov r3, r2 */
/* @0x1fdeb8 ldr r1, [r4, r1] */
/* @0x1fdebc add r0, pc, r0 */
/* @0x1fdec0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdec4 ldr r1, [pc, #0x5d4] */
/* @0x1fdec8 ldr r0, [pc, #0x5d4] */
/* @0x1fdecc mov r2, #0 */
/* @0x1fded0 mov r3, r2 */
/* @0x1fded4 ldr r1, [r4, r1] */
/* @0x1fded8 add r0, pc, r0 */
/* @0x1fdedc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdee0 ldr r1, [pc, #0x5c0] */
/* @0x1fdee4 ldr r0, [pc, #0x5c0] */
/* @0x1fdee8 mov r2, #0 */
/* @0x1fdeec mov r3, r2 */
/* @0x1fdef0 ldr r1, [r4, r1] */
/* @0x1fdef4 add r0, pc, r0 */
/* @0x1fdef8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdefc ldr r1, [pc, #0x5ac] */
/* @0x1fdf00 ldr r0, [pc, #0x5ac] */
/* @0x1fdf04 mov r2, #0 */
/* @0x1fdf08 mov r3, r2 */
/* @0x1fdf0c ldr r1, [r4, r1] */
/* @0x1fdf10 add r0, pc, r0 */
/* @0x1fdf14 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdf18 ldr r1, [pc, #0x598] */
/* @0x1fdf1c ldr r0, [pc, #0x598] */
/* @0x1fdf20 mov r2, #0 */
/* @0x1fdf24 mov r3, r2 */
/* @0x1fdf28 ldr r1, [r4, r1] */
/* @0x1fdf2c add r0, pc, r0 */
/* @0x1fdf30 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdf34 ldr r1, [pc, #0x584] */
/* @0x1fdf38 ldr r0, [pc, #0x584] */
/* @0x1fdf3c mov r2, #0 */
/* @0x1fdf40 mov r3, r2 */
/* @0x1fdf44 ldr r1, [r4, r1] */
/* @0x1fdf48 add r0, pc, r0 */
/* @0x1fdf4c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdf50 ldr r1, [pc, #0x570] */
/* @0x1fdf54 ldr r2, [pc, #0x570] */
/* @0x1fdf58 mov r3, #1 */
/* @0x1fdf5c ldr r0, [pc, #0x56c] */
/* @0x1fdf60 ldr r1, [r4, r1] */
/* @0x1fdf64 ldr r2, [r4, r2] */
/* @0x1fdf68 add r0, pc, r0 */
/* @0x1fdf6c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdf70 ldr r1, [pc, #0x55c] */
/* @0x1fdf74 ldr r2, [pc, #0x55c] */
/* @0x1fdf78 mov r3, #1 */
/* @0x1fdf7c ldr r0, [pc, #0x558] */
/* @0x1fdf80 ldr r1, [r4, r1] */
/* @0x1fdf84 ldr r2, [r4, r2] */
/* @0x1fdf88 add r0, pc, r0 */
/* @0x1fdf8c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdf90 ldr r1, [pc, #0x548] */
/* @0x1fdf94 ldr r0, [pc, #0x548] */
/* @0x1fdf98 mov r2, #0 */
/* @0x1fdf9c mov r3, r2 */
/* @0x1fdfa0 ldr r5, [r4, r1] */
/* @0x1fdfa4 add r0, pc, r0 */
/* @0x1fdfa8 mov r1, r5 */
/* @0x1fdfac bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdfb0 ldr r0, [pc, #0x530] */
/* @0x1fdfb4 mov r2, #0 */
/* @0x1fdfb8 mov r1, r5 */
/* @0x1fdfbc mov r3, r2 */
/* @0x1fdfc0 add r0, pc, r0 */
/* @0x1fdfc4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdfc8 ldr r1, [pc, #0x51c] */
/* @0x1fdfcc ldr r0, [pc, #0x51c] */
/* @0x1fdfd0 mov r2, #0 */
/* @0x1fdfd4 mov r3, r2 */
/* @0x1fdfd8 ldr r1, [r4, r1] */
/* @0x1fdfdc add r0, pc, r0 */
/* @0x1fdfe0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdfe4 ldr r1, [pc, #0x508] */
/* @0x1fdfe8 ldr r2, [pc, #0x508] */
/* @0x1fdfec mov r3, #0 */
/* @0x1fdff0 ldr r0, [pc, #0x504] */
/* @0x1fdff4 ldr r1, [r4, r1] */
/* @0x1fdff8 ldr r2, [r4, r2] */
/* @0x1fdffc add r0, pc, r0 */
/* @0x1fe000 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fe004 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1fe008 b 0x15dafc <_Z24InitYoYoBuiltInVariablesv> */
/* @0x1fe00c ldrheq r4, [pc], -r8 */
/* @0x1fe010 .word 0xffffbfe4 */
/* @0x1fe014 .word 0xffffc7d8 */
/* @0x1fe018 .word 0xfffff1f0 */
/* @0x1fe01c andseq r5, r5, r12, asr #17 */
/* @0x1fe020 .word 0xfffff1f4 */
/* @0x1fe024 .word 0xfffff1f8 */
/* @0x1fe028 ldrheq r5, [r5], -r8 */
/* @0x1fe02c .word 0xfffff1fc */
/* @0x1fe030 .word 0xfffff200 */
/* @0x1fe034 andseq r5, r5, r4, lsr #17 */
/* @0x1fe038 .word 0xfffff204 */
/* @0x1fe03c .word 0xfffff208 */
/* @0x1fe040 mulseq r5, r0, r8 */
/* @0x1fe044 .word 0xfffff20c */
/* @0x1fe048 .word 0xfffff210 */
/* @0x1fe04c andseq r5, r5, r12, ror r8 */
/* @0x1fe050 .word 0xfffff214 */
/* @0x1fe054 .word 0xfffff218 */
/* @0x1fe058 andseq r5, r5, r8, ror #16 */
/* @0x1fe05c .word 0xfffff21c */
/* @0x1fe060 .word 0xfffff220 */
/* @0x1fe064 andseq r5, r5, r4, asr r8 */
/* @0x1fe068 .word 0xfffff224 */
/* @0x1fe06c .word 0xfffff228 */
/* @0x1fe070 andseq r5, r5, r0, asr #16 */
/* @0x1fe074 .word 0xfffff22c */
/* @0x1fe078 .word 0xfffff230 */
/* @0x1fe07c andseq r5, r5, r12, lsr #16 */
/* @0x1fe080 .word 0xfffff234 */
/* @0x1fe084 .word 0xfffff238 */
/* @0x1fe088 andseq r5, r5, r8, lsl r8 */
/* @0x1fe08c .word 0xfffff23c */
/* @0x1fe090 .word 0xfffff240 */
/* @0x1fe094 andseq r5, r5, r4, lsl #16 */
/* @0x1fe098 .word 0xfffff244 */
/* @0x1fe09c .word 0xfffff248 */
/* @0x1fe0a0 ldrsheq r5, [r5], -r0 */
/* @0x1fe0a4 .word 0xfffff24c */
/* @0x1fe0a8 .word 0xfffff250 */
/* @0x1fe0ac ldrsbeq r5, [r5], -r12 */
/* @0x1fe0b0 .word 0xfffff254 */
/* @0x1fe0b4 .word 0xfffff258 */
/* @0x1fe0b8 andseq r5, r5, r8, asr #15 */
/* @0x1fe0bc .word 0xfffff25c */
/* @0x1fe0c0 .word 0xfffff260 */
/* @0x1fe0c4 ldrheq r5, [r5], -r4 */
/* @0x1fe0c8 .word 0xfffff264 */
/* @0x1fe0cc .word 0xfffff268 */
/* @0x1fe0d0 andseq r5, r5, r0, lsr #15 */
/* @0x1fe0d4 .word 0xfffff26c */
/* @0x1fe0d8 .word 0xfffff270 */
/* @0x1fe0dc andseq r5, r5, r12, lsl #15 */
/* @0x1fe0e0 .word 0xfffff274 */
/* @0x1fe0e4 .word 0xfffff278 */
/* @0x1fe0e8 andseq r5, r5, r8, ror r7 */
/* @0x1fe0ec .word 0xfffff27c */
/* @0x1fe0f0 andseq r5, r5, r8, ror #14 */
/* @0x1fe0f4 .word 0xfffff280 */
/* @0x1fe0f8 andseq r5, r5, r12, asr r7 */
/* @0x1fe0fc .word 0xfffff284 */
/* @0x1fe100 andseq r5, r5, r12, asr #14 */
/* @0x1fe104 .word 0xfffff288 */
/* @0x1fe108 andseq r5, r5, r0, asr #14 */
/* @0x1fe10c .word 0xfffff28c */
/* @0x1fe110 ldrsheq r4, [r3], -r8 */
/* @0x1fe114 .word 0xfffff290 */
/* @0x1fe118 .word 0xfffff294 */
/* @0x1fe11c andseq r5, r5, r4, lsl r7 */
/* @0x1fe120 .word 0xfffff298 */
/* @0x1fe124 andseq r5, r5, r0, lsl #14 */
/* @0x1fe128 .word 0xfffff29c */
/* @0x1fe12c ldrsheq r5, [r5], -r0 */
/* @0x1fe130 .word 0xfffff2a0 */
/* @0x1fe134 .word 0xfffff2a4 */
/* @0x1fe138 ldrsbeq r5, [r5], -r12 */
/* @0x1fe13c .word 0xfffff2a8 */
/* @0x1fe140 .word 0xfffff2ac */
/* @0x1fe144 andseq r5, r5, r12, asr #13 */
/* @0x1fe148 .word 0xfffff2b0 */
/* @0x1fe14c .word 0xfffff2b4 */
/* @0x1fe150 andseq r5, r5, r0, asr #13 */
/* @0x1fe154 .word 0xfffff2b8 */
/* @0x1fe158 .word 0xfffff2bc */
/* @0x1fe15c andseq r5, r5, r8, lsr #13 */
/* @0x1fe160 .word 0xfffff2c0 */
/* @0x1fe164 .word 0xfffff2c4 */
/* @0x1fe168 mulseq r5, r0, r6 */
/* @0x1fe16c .word 0xfffff2c8 */
/* @0x1fe170 andseq r5, r5, r12, ror r6 */
/* @0x1fe174 .word 0xfffff2cc */
/* @0x1fe178 andseq r5, r5, r8, ror #12 */
/* @0x1fe17c .word 0xfffff2d0 */
/* @0x1fe180 andseq r5, r5, r8, asr r6 */
/* @0x1fe184 .word 0xfffff2d4 */
/* @0x1fe188 andseq r5, r5, r0, asr r6 */
/* @0x1fe18c .word 0xfffff2d8 */
/* @0x1fe190 andseq r5, r5, r8, asr #12 */
/* @0x1fe194 .word 0xfffff2dc */
/* @0x1fe198 andseq r5, r5, r12, lsr r6 */
/* @0x1fe19c .word 0xfffff2e0 */
/* @0x1fe1a0 andseq r5, r5, r4, lsr r6 */
/* @0x1fe1a4 .word 0xfffff2e4 */
/* @0x1fe1a8 andseq r5, r5, r8, lsr #12 */
/* @0x1fe1ac .word 0xfffff2e8 */
/* @0x1fe1b0 andseq r5, r5, r0, lsr #12 */
/* @0x1fe1b4 .word 0xfffff2ec */
/* @0x1fe1b8 andseq r5, r5, r4, lsl r6 */
/* @0x1fe1bc .word 0xfffff2f0 */
/* @0x1fe1c0 .word 0xfffff2f4 */
/* @0x1fe1c4 andseq r5, r5, r0, lsl #12 */
/* @0x1fe1c8 .word 0xfffff2f8 */
/* @0x1fe1cc .word 0xfffff2fc */
/* @0x1fe1d0 andseq r5, r5, r12, ror #11 */
/* @0x1fe1d4 .word 0xfffff300 */
/* @0x1fe1d8 .word 0xfffff304 */
/* @0x1fe1dc ldrsbeq r5, [r5], -r8 */
/* @0x1fe1e0 .word 0xfffff308 */
/* @0x1fe1e4 .word 0xfffff30c */
/* @0x1fe1e8 andseq r5, r5, r8, asr #11 */
/* @0x1fe1ec .word 0xfffff310 */
/* @0x1fe1f0 .word 0xfffff314 */
/* @0x1fe1f4 ldrheq r5, [r5], -r4 */
/* @0x1fe1f8 .word 0xfffff318 */
/* @0x1fe1fc .word 0xfffff31c */
/* @0x1fe200 andseq r5, r5, r4, lsr #11 */
/* @0x1fe204 .word 0xfffff320 */
/* @0x1fe208 .word 0xfffff324 */
/* @0x1fe20c mulseq r5, r0, r5 */
/* @0x1fe210 andseq r5, r5, r12, lsl #11 */
/* @0x1fe214 andseq r5, r5, r8, lsl #11 */
/* @0x1fe218 .word 0xfffff328 */
/* @0x1fe21c .word 0xfffff32c */
/* @0x1fe220 andseq r5, r5, r12, ror r5 */
/* @0x1fe224 .word 0xfffff330 */
/* @0x1fe228 .word 0xfffff334 */
/* @0x1fe22c andseq r5, r5, r0, ror r5 */
/* @0x1fe230 .word 0xfffff338 */
/* @0x1fe234 .word 0xfffff33c */
/* @0x1fe238 andseq r5, r5, r8, ror #10 */
/* @0x1fe23c .word 0xfffff340 */
/* @0x1fe240 .word 0xfffff344 */
/* @0x1fe244 andseq r5, r5, r12, asr r5 */
/* @0x1fe248 .word 0xfffff348 */
/* @0x1fe24c .word 0xfffff34c */
/* @0x1fe250 andseq r5, r5, r12, asr #10 */
/* @0x1fe254 .word 0xfffff350 */
/* @0x1fe258 andseq r5, r5, r0, asr #10 */
/* @0x1fe25c .word 0xfffff354 */
/* @0x1fe260 andseq r5, r5, r8, lsr r5 */
/* @0x1fe264 .word 0xfffff358 */
/* @0x1fe268 .word 0xfffff35c */
/* @0x1fe26c andseq r5, r5, r12, lsr #10 */
/* @0x1fe270 .word 0xfffff360 */
/* @0x1fe274 .word 0xfffff364 */
/* @0x1fe278 andseq r5, r5, r0, lsr #10 */
/* @0x1fe27c .word 0xfffff368 */
/* @0x1fe280 .word 0xfffff36c */
/* @0x1fe284 andseq r5, r5, r4, lsl r5 */
/* @0x1fe288 .word 0xfffff370 */
/* @0x1fe28c .word 0xfffff374 */
/* @0x1fe290 andseq r5, r5, r8, lsl #10 */
/* @0x1fe294 .word 0xfffff378 */
/* @0x1fe298 .word 0xfffff37c */
/* @0x1fe29c ldrsheq r5, [r5], -r12 */
/* @0x1fe2a0 .word 0xfffff380 */
/* @0x1fe2a4 .word 0xfffff384 */
/* @0x1fe2a8 ldrsheq r5, [r5], -r0 */
/* @0x1fe2ac .word 0xfffff388 */
/* @0x1fe2b0 .word 0xfffff38c */
/* @0x1fe2b4 andseq r5, r5, r4, ror #9 */
/* @0x1fe2b8 .word 0xfffff390 */
/* @0x1fe2bc .word 0xfffff394 */
/* @0x1fe2c0 ldrsbeq r5, [r5], -r8 */
/* @0x1fe2c4 .word 0xfffff398 */
/* @0x1fe2c8 .word 0xfffff39c */
/* @0x1fe2cc andseq r5, r5, r12, asr #9 */
/* @0x1fe2d0 .word 0xfffff3a0 */
/* @0x1fe2d4 andseq r5, r5, r0, asr #9 */
/* @0x1fe2d8 .word 0xfffff3a4 */
/* @0x1fe2dc .word 0xfffff3a8 */
/* @0x1fe2e0 ldrheq r5, [r5], -r0 */
/* @0x1fe2e4 .word 0xfffff3ac */
/* @0x1fe2e8 .word 0xfffff3b0 */
/* @0x1fe2ec andseq r5, r5, r0, lsr #9 */
/* @0x1fe2f0 .word 0xfffff3b4 */
/* @0x1fe2f4 .word 0xfffff3b8 */
/* @0x1fe2f8 andseq r5, r5, r12, lsl #9 */
/* @0x1fe2fc .word 0xfffff3bc */
/* @0x1fe300 .word 0xfffff3c0 */
/* @0x1fe304 andseq r5, r5, r8, ror r4 */
/* @0x1fe308 .word 0xfffff3c4 */
/* @0x1fe30c .word 0xfffff3c8 */
/* @0x1fe310 andseq r5, r5, r4, ror #8 */
/* @0x1fe314 .word 0xfffff3cc */
/* @0x1fe318 .word 0xfffff3d0 */
/* @0x1fe31c andseq r5, r5, r0, asr r4 */
/* @0x1fe320 .word 0xfffff3d4 */
/* @0x1fe324 .word 0xfffff3d8 */
/* @0x1fe328 andseq r5, r5, r12, lsr r4 */
/* @0x1fe32c .word 0xfffff3dc */
/* @0x1fe330 .word 0xfffff3e0 */
/* @0x1fe334 andseq r5, r5, r8, lsr #8 */
/* @0x1fe338 .word 0xfffff3e4 */
/* @0x1fe33c .word 0xfffff3e8 */
/* @0x1fe340 andseq r5, r5, r4, lsl r4 */
/* @0x1fe344 .word 0xfffff3ec */
/* @0x1fe348 .word 0xfffff3f0 */
/* @0x1fe34c andseq r5, r5, r0, lsl #8 */
/* @0x1fe350 .word 0xfffff3f4 */
/* @0x1fe354 .word 0xfffff3f8 */
/* @0x1fe358 andseq r5, r5, r12, ror #7 */
/* @0x1fe35c .word 0xfffff3fc */
/* @0x1fe360 .word 0xfffff400 */
/* @0x1fe364 ldrsbeq r5, [r5], -r12 */
/* @0x1fe368 .word 0xfffff404 */
/* @0x1fe36c .word 0xfffff408 */
/* @0x1fe370 andseq r5, r5, r12, asr #7 */
/* @0x1fe374 .word 0xfffff40c */
/* @0x1fe378 .word 0xfffff410 */
/* @0x1fe37c ldrheq r5, [r5], -r8 */
/* @0x1fe380 .word 0xfffff414 */
/* @0x1fe384 .word 0xfffff418 */
/* @0x1fe388 andseq r5, r5, r4, lsr #7 */
/* @0x1fe38c .word 0xfffff41c */
/* @0x1fe390 .word 0xfffff420 */
/* @0x1fe394 mulseq r5, r0, r3 */
/* @0x1fe398 .word 0xfffff424 */
/* @0x1fe39c .word 0xfffff428 */
/* @0x1fe3a0 andseq r5, r5, r0, lsl #7 */
/* @0x1fe3a4 .word 0xfffff42c */
/* @0x1fe3a8 andseq r5, r5, r0, ror r3 */
/* @0x1fe3ac .word 0xfffff430 */
/* @0x1fe3b0 andseq r5, r5, r12, asr r3 */
/* @0x1fe3b4 .word 0xfffff434 */
/* @0x1fe3b8 .word 0xfffff438 */
/* @0x1fe3bc andseq r5, r5, r4, asr #6 */
/* @0x1fe3c0 .word 0xfffff43c */
/* @0x1fe3c4 .word 0xfffff440 */
/* @0x1fe3c8 andseq r5, r5, r4, lsr r3 */
/* @0x1fe3cc .word 0xfffff444 */
/* @0x1fe3d0 .word 0xfffff448 */
/* @0x1fe3d4 andseq r5, r5, r8, lsr #6 */
/* @0x1fe3d8 .word 0xfffff44c */
/* @0x1fe3dc .word 0xfffff450 */
/* @0x1fe3e0 andseq r5, r5, r8, lsl r3 */
/* @0x1fe3e4 .word 0xfffff454 */
/* @0x1fe3e8 .word 0xfffff458 */
/* @0x1fe3ec andseq r5, r5, r12, lsl #6 */
/* @0x1fe3f0 .word 0xfffff45c */
/* @0x1fe3f4 .word 0xfffff460 */
/* @0x1fe3f8 andseq r5, r5, r0, lsl #6 */
/* @0x1fe3fc .word 0xfffff464 */
/* @0x1fe400 .word 0xfffff468 */
/* @0x1fe404 ldrsheq r5, [r5], -r0 */
/* @0x1fe408 .word 0xfffff46c */
/* @0x1fe40c .word 0xfffff470 */
/* @0x1fe410 andseq r5, r5, r0, ror #5 */
/* @0x1fe414 .word 0xfffff474 */
/* @0x1fe418 .word 0xfffff478 */
/* @0x1fe41c andseq r5, r5, r12, asr #5 */
/* @0x1fe420 .word 0xfffff47c */
/* @0x1fe424 .word 0xfffff480 */
/* @0x1fe428 ldrheq r5, [r5], -r8 */
/* @0x1fe42c .word 0xfffff484 */
/* @0x1fe430 .word 0xfffff488 */
/* @0x1fe434 andseq r5, r5, r4, lsr #5 */
/* @0x1fe438 .word 0xfffff48c */
/* @0x1fe43c .word 0xfffff490 */
/* @0x1fe440 mulseq r5, r4, r2 */
/* @0x1fe444 .word 0xfffff494 */
/* @0x1fe448 .word 0xfffff498 */
/* @0x1fe44c andseq r5, r5, r4, lsl #5 */
/* @0x1fe450 .word 0xfffff49c */
/* @0x1fe454 andseq r5, r5, r8, ror r2 */
/* @0x1fe458 .word 0xfffff4a0 */
/* @0x1fe45c andseq r5, r5, r0, ror #4 */
/* @0x1fe460 .word 0xfffff4a4 */
/* @0x1fe464 andseq r5, r5, r0, asr r2 */
/* @0x1fe468 .word 0xfffff4a8 */
/* @0x1fe46c andseq r5, r5, r4, asr #4 */
/* @0x1fe470 .word 0xfffff4ac */
/* @0x1fe474 andseq r5, r5, r8, lsr r2 */
/* @0x1fe478 .word 0xfffff4b0 */
/* @0x1fe47c andseq r5, r5, r12, lsr #4 */
/* @0x1fe480 .word 0xfffff4b4 */
/* @0x1fe484 andseq r5, r5, r12, lsl r2 */
/* @0x1fe488 .word 0xfffff4b8 */
/* @0x1fe48c andseq r5, r5, r0, lsl r2 */
/* @0x1fe490 .word 0xfffff4bc */
/* @0x1fe494 andseq r5, r5, r4, lsl #4 */
/* @0x1fe498 .word 0xfffff4c0 */
/* @0x1fe49c ldrsheq r5, [r5], -r8 */
/* @0x1fe4a0 .word 0xfffff4c4 */
/* @0x1fe4a4 andseq lr, r4, r12, lsr #9 */
/* @0x1fe4a8 .word 0xfffff4c8 */
/* @0x1fe4ac ldrsbeq r5, [r5], -r0 */
/* @0x1fe4b0 .word 0xfffff4cc */
/* @0x1fe4b4 andseq r5, r5, r4, asr #3 */
/* @0x1fe4b8 .word 0xfffff4d0 */
/* @0x1fe4bc ldrheq r5, [r5], -r8 */
/* @0x1fe4c0 .word 0xfffff4d4 */
/* @0x1fe4c4 andseq r5, r5, r12, lsr #3 */
/* @0x1fe4c8 .word 0xfffff4d8 */
/* @0x1fe4cc .word 0xfffff4dc */
/* @0x1fe4d0 mulseq r5, r8, r1 */
/* @0x1fe4d4 .word 0xfffff4e0 */
/* @0x1fe4d8 .word 0xfffff4e4 */
/* @0x1fe4dc andseq r5, r5, r8, lsl #3 */
/* @0x1fe4e0 .word 0xfffff4e8 */
/* @0x1fe4e4 andseq r5, r5, r8, ror r1 */
/* @0x1fe4e8 andseq r5, r5, r4, ror r1 */
/* @0x1fe4ec .word 0xfffff4ec */
/* @0x1fe4f0 andseq r5, r5, r8, ror #2 */
/* @0x1fe4f4 .word 0xfffff4f0 */
/* @0x1fe4f8 .word 0xfffff4f4 */
/* @0x1fe4fc andseq r5, r5, r12, asr r1 */

/* ── FUNC 0x1fe500 · CheckPhysicsError(CInstance*, bool, bool) · size=132 · insn=33 */
/* @0x1fe500 cmp r2, #0 */
/* @0x1fe504 push {r4, lr} */
/* @0x1fe508 beq 0x1fe524 <_Z17CheckPhysicsErrorP9CInstancebb+0x24> */
/* @0x1fe50c ldr r3, [pc, #0x64] */
/* @0x1fe510 ldr r3, [pc, r3] */
/* @0x1fe514 ldr r3, [r3] */
/* @0x1fe518 ldr r4, [r3, #0xb4] */
/* @0x1fe51c cmp r4, #0 */
/* @0x1fe520 beq 0x1fe560 <_Z17CheckPhysicsErrorP9CInstancebb+0x60> */
/* @0x1fe524 cmp r1, #0 */
/* @0x1fe528 beq 0x1fe538 <_Z17CheckPhysicsErrorP9CInstancebb+0x38> */
/* @0x1fe52c ldr r4, [r0, #0x84] */
/* @0x1fe530 cmp r4, #0 */
/* @0x1fe534 beq 0x1fe540 <_Z17CheckPhysicsErrorP9CInstancebb+0x40> */
/* @0x1fe538 mov r0, #1 */
/* @0x1fe53c pop {r4, pc} */
/* @0x1fe540 ldr r3, [r0, #0x80] */
/* @0x1fe544 mov r2, #1 */
/* @0x1fe548 ldr r0, [pc, #0x2c] */
/* @0x1fe54c ldr r1, [r3, #0x14] */
/* @0x1fe550 add r0, pc, r0 */
/* @0x1fe554 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x1fe558 mov r0, r4 */
/* @0x1fe55c pop {r4, pc} */
/* @0x1fe560 ldr r0, [pc, #0x18] */
/* @0x1fe564 mov r1, #1 */
/* @0x1fe568 add r0, pc, r0 */
/* @0x1fe56c bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x1fe570 mov r0, r4 */
/* @0x1fe574 pop {r4, pc} */
/* @0x1fe578 andseq pc, lr, r8, lsl r4 */
/* @0x1fe57c andseq r4, r5, r12, ror #24 */
/* @0x1fe580 andseq r4, r5, r8, lsl #24 */

/* ── FUNC 0x1fe584 · SV_PhysicsAngularVelocity(CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x1fe584 push {r4, r5, r6, r7, r8, lr} */
/* @0x1fe588 mov r1, #1 */
/* @0x1fe58c mov r6, r2 */
/* @0x1fe590 mov r2, #0 */
/* @0x1fe594 mov r4, r0 */
/* @0x1fe598 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb> */
/* @0x1fe59c subs r7, r0, #0 */
/* @0x1fe5a0 beq 0x1fe5d8 <_Z25SV_PhysicsAngularVelocityP9CInstanceiP6RValue+0x54> */
/* @0x1fe5a4 ldr r8, [r4, #0x84] */
/* @0x1fe5a8 cmp r8, #0 */
/* @0x1fe5ac beq 0x1fe5f4 <_Z25SV_PhysicsAngularVelocityP9CInstanceiP6RValue+0x70> */
/* @0x1fe5b0 ldr r3, [r6, #0xc] */
/* @0x1fe5b4 bic r3, r3, #-16777216 */
/* @0x1fe5b8 cmp r3, #0 */
/* @0x1fe5bc bne 0x1fe5e0 <_Z25SV_PhysicsAngularVelocityP9CInstanceiP6RValue+0x5c> */
/* @0x1fe5c0 ldm r6, {r4, r5} */
/* @0x1fe5c4 vmov d7, r4, r5 */
/* @0x1fe5c8 mov r0, r8 */
/* @0x1fe5cc vcvt.f32.f64 s15, d7 */
/* @0x1fe5d0 vmov r1, s15 */
/* @0x1fe5d4 bl 0x236f44 <_ZN14CPhysicsObject18SetAngularVelocityEf> */
/* @0x1fe5d8 mov r0, r7 */
/* @0x1fe5dc pop {r4, r5, r6, r7, r8, pc} */
/* @0x1fe5e0 mov r0, r6 */
/* @0x1fe5e4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fe5e8 mov r4, r0 */
/* @0x1fe5ec mov r5, r1 */
/* @0x1fe5f0 b 0x1fe5c4 <_Z25SV_PhysicsAngularVelocityP9CInstanceiP6RValue+0x40> */
/* @0x1fe5f4 mov r7, r8 */
/* @0x1fe5f8 b 0x1fe5d8 <_Z25SV_PhysicsAngularVelocityP9CInstanceiP6RValue+0x54> */

/* ── FUNC 0x1fe5fc · SV_PhysicsAngle(CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x1fe5fc push {r4, r5, r6, r7, r8, lr} */
/* @0x1fe600 mov r1, #1 */
/* @0x1fe604 mov r6, r2 */
/* @0x1fe608 mov r2, #0 */
/* @0x1fe60c mov r4, r0 */
/* @0x1fe610 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb> */
/* @0x1fe614 subs r7, r0, #0 */
/* @0x1fe618 beq 0x1fe650 <_Z15SV_PhysicsAngleP9CInstanceiP6RValue+0x54> */
/* @0x1fe61c ldr r8, [r4, #0x84] */
/* @0x1fe620 cmp r8, #0 */
/* @0x1fe624 beq 0x1fe66c <_Z15SV_PhysicsAngleP9CInstanceiP6RValue+0x70> */
/* @0x1fe628 ldr r3, [r6, #0xc] */
/* @0x1fe62c bic r3, r3, #-16777216 */
/* @0x1fe630 cmp r3, #0 */
/* @0x1fe634 bne 0x1fe658 <_Z15SV_PhysicsAngleP9CInstanceiP6RValue+0x5c> */
/* @0x1fe638 ldm r6, {r4, r5} */
/* @0x1fe63c vmov d7, r4, r5 */
/* @0x1fe640 mov r0, r8 */
/* @0x1fe644 vcvt.f32.f64 s15, d7 */
/* @0x1fe648 vmov r1, s15 */
/* @0x1fe64c bl 0x236e48 <_ZN14CPhysicsObject11SetRotationEf> */
/* @0x1fe650 mov r0, r7 */
/* @0x1fe654 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1fe658 mov r0, r6 */
/* @0x1fe65c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fe660 mov r4, r0 */
/* @0x1fe664 mov r5, r1 */
/* @0x1fe668 b 0x1fe63c <_Z15SV_PhysicsAngleP9CInstanceiP6RValue+0x40> */
/* @0x1fe66c mov r7, r8 */
/* @0x1fe670 b 0x1fe650 <_Z15SV_PhysicsAngleP9CInstanceiP6RValue+0x54> */

/* ── FUNC 0x1fe674 · SV_PhysicsPositionX(CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x1fe674 mov r1, #1 */
/* @0x1fe678 push {r3, r4, r6, r7, r8, r9, r10, lr} */
/* @0x1fe67c mov r9, r2 */
/* @0x1fe680 mov r2, r1 */
/* @0x1fe684 mov r4, r0 */
/* @0x1fe688 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb> */
/* @0x1fe68c subs r6, r0, #0 */
/* @0x1fe690 beq 0x1fe6f8 <_Z19SV_PhysicsPositionXP9CInstanceiP6RValue+0x84> */
/* @0x1fe694 ldr r3, [pc, #0x70] */
/* @0x1fe698 ldr r7, [r4, #0x84] */
/* @0x1fe69c ldr r3, [pc, r3] */
/* @0x1fe6a0 ldr r3, [r3] */
/* @0x1fe6a4 ldr r8, [r3, #0xb4] */
/* @0x1fe6a8 cmp r7, #0 */
/* @0x1fe6ac cmpne r8, #0 */
/* @0x1fe6b0 moveq r6, #0 */
/* @0x1fe6b4 movne r6, #1 */
/* @0x1fe6b8 beq 0x1fe6f8 <_Z19SV_PhysicsPositionXP9CInstanceiP6RValue+0x84> */
/* @0x1fe6bc ldr r3, [r9, #0xc] */
/* @0x1fe6c0 ldr r2, [r7] */
/* @0x1fe6c4 bic r3, r3, #-16777216 */
/* @0x1fe6c8 cmp r3, #0 */
/* @0x1fe6cc ldr r10, [r2, #0x10] */
/* @0x1fe6d0 bne 0x1fe700 <_Z19SV_PhysicsPositionXP9CInstanceiP6RValue+0x8c> */
/* @0x1fe6d4 ldm r9, {r0, r1} */
/* @0x1fe6d8 vmov d6, r0, r1 */
/* @0x1fe6dc vldr s15, [r8, #96] */
/* @0x1fe6e0 mov r0, r7 */
/* @0x1fe6e4 mov r2, r10 */
/* @0x1fe6e8 vcvt.f32.f64 s14, d6 */
/* @0x1fe6ec vmul.f32 s15, s14, s15 */
/* @0x1fe6f0 vmov r1, s15 */
/* @0x1fe6f4 bl 0x236e00 <_ZN14CPhysicsObject11SetPositionEff> */
/* @0x1fe6f8 mov r0, r6 */
/* @0x1fe6fc pop {r3, r4, r6, r7, r8, r9, r10, pc} */
/* @0x1fe700 mov r0, r9 */
/* @0x1fe704 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fe708 b 0x1fe6d8 <_Z19SV_PhysicsPositionXP9CInstanceiP6RValue+0x64> */
/* @0x1fe70c andseq pc, lr, r12, lsl #5 */

/* ── FUNC 0x1fe710 · SV_PhysicsPositionY(CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x1fe710 mov r1, #1 */
/* @0x1fe714 push {r3, r4, r6, r7, r8, r9, r10, lr} */
/* @0x1fe718 mov r9, r2 */
/* @0x1fe71c mov r2, r1 */
/* @0x1fe720 mov r4, r0 */
/* @0x1fe724 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb> */
/* @0x1fe728 subs r6, r0, #0 */
/* @0x1fe72c beq 0x1fe794 <_Z19SV_PhysicsPositionYP9CInstanceiP6RValue+0x84> */
/* @0x1fe730 ldr r3, [pc, #0x70] */
/* @0x1fe734 ldr r7, [r4, #0x84] */
/* @0x1fe738 ldr r3, [pc, r3] */
/* @0x1fe73c ldr r3, [r3] */
/* @0x1fe740 ldr r8, [r3, #0xb4] */
/* @0x1fe744 cmp r7, #0 */
/* @0x1fe748 cmpne r8, #0 */
/* @0x1fe74c moveq r6, #0 */
/* @0x1fe750 movne r6, #1 */
/* @0x1fe754 beq 0x1fe794 <_Z19SV_PhysicsPositionYP9CInstanceiP6RValue+0x84> */
/* @0x1fe758 ldr r3, [r9, #0xc] */
/* @0x1fe75c ldr r2, [r7] */
/* @0x1fe760 bic r3, r3, #-16777216 */
/* @0x1fe764 cmp r3, #0 */
/* @0x1fe768 ldr r10, [r2, #0xc] */
/* @0x1fe76c bne 0x1fe79c <_Z19SV_PhysicsPositionYP9CInstanceiP6RValue+0x8c> */
/* @0x1fe770 ldm r9, {r0, r1} */
/* @0x1fe774 vmov d6, r0, r1 */
/* @0x1fe778 vldr s15, [r8, #96] */
/* @0x1fe77c mov r0, r7 */
/* @0x1fe780 mov r1, r10 */
/* @0x1fe784 vcvt.f32.f64 s14, d6 */
/* @0x1fe788 vmul.f32 s15, s14, s15 */
/* @0x1fe78c vmov r2, s15 */
/* @0x1fe790 bl 0x236e00 <_ZN14CPhysicsObject11SetPositionEff> */
/* @0x1fe794 mov r0, r6 */
/* @0x1fe798 pop {r3, r4, r6, r7, r8, r9, r10, pc} */
/* @0x1fe79c mov r0, r9 */
/* @0x1fe7a0 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fe7a4 b 0x1fe774 <_Z19SV_PhysicsPositionYP9CInstanceiP6RValue+0x64> */
/* @0x1fe7a8 ldrsheq pc, [lr], -r0 */

/* ── FUNC 0x1fe7ac · SV_PhysicsLinearVelocityX(CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x1fe7ac mov r1, #1 */
/* @0x1fe7b0 push {r4, r6, r7, r8, r9, lr} */
/* @0x1fe7b4 mov r9, r2 */
/* @0x1fe7b8 mov r2, r1 */
/* @0x1fe7bc mov r4, r0 */
/* @0x1fe7c0 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb> */
/* @0x1fe7c4 subs r6, r0, #0 */
/* @0x1fe7c8 beq 0x1fe82c <_Z25SV_PhysicsLinearVelocityXP9CInstanceiP6RValue+0x80> */
/* @0x1fe7cc ldr r3, [pc, #0x6c] */
/* @0x1fe7d0 ldr r7, [r4, #0x84] */
/* @0x1fe7d4 ldr r3, [pc, r3] */
/* @0x1fe7d8 ldr r3, [r3] */
/* @0x1fe7dc ldr r8, [r3, #0xb4] */
/* @0x1fe7e0 cmp r7, #0 */
/* @0x1fe7e4 cmpne r8, #0 */
/* @0x1fe7e8 moveq r6, #0 */
/* @0x1fe7ec movne r6, #1 */
/* @0x1fe7f0 beq 0x1fe82c <_Z25SV_PhysicsLinearVelocityXP9CInstanceiP6RValue+0x80> */
/* @0x1fe7f4 ldr r3, [r9, #0xc] */
/* @0x1fe7f8 bic r3, r3, #-16777216 */
/* @0x1fe7fc cmp r3, #0 */
/* @0x1fe800 bne 0x1fe834 <_Z25SV_PhysicsLinearVelocityXP9CInstanceiP6RValue+0x88> */
/* @0x1fe804 ldm r9, {r0, r1} */
/* @0x1fe808 vmov d6, r0, r1 */
/* @0x1fe80c vldr s15, [r8, #96] */
/* @0x1fe810 ldr r3, [r7] */
/* @0x1fe814 mov r0, r7 */
/* @0x1fe818 vcvt.f32.f64 s14, d6 */
/* @0x1fe81c ldr r2, [r3, #0x54] */
/* @0x1fe820 vmul.f32 s15, s14, s15 */
/* @0x1fe824 vmov r1, s15 */
/* @0x1fe828 bl 0x236e9c <_ZN14CPhysicsObject17SetLinearVelocityEff> */
/* @0x1fe82c mov r0, r6 */
/* @0x1fe830 pop {r4, r6, r7, r8, r9, pc} */
/* @0x1fe834 mov r0, r9 */
/* @0x1fe838 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fe83c b 0x1fe808 <_Z25SV_PhysicsLinearVelocityXP9CInstanceiP6RValue+0x5c> */
/* @0x1fe840 andseq pc, lr, r4, asr r1 */

/* ── FUNC 0x1fe844 · SV_PhysicsLinearVelocityY(CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x1fe844 mov r1, #1 */
/* @0x1fe848 push {r4, r6, r7, r8, r9, lr} */
/* @0x1fe84c mov r9, r2 */
/* @0x1fe850 mov r2, r1 */
/* @0x1fe854 mov r4, r0 */
/* @0x1fe858 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb> */
/* @0x1fe85c subs r6, r0, #0 */
/* @0x1fe860 beq 0x1fe8c4 <_Z25SV_PhysicsLinearVelocityYP9CInstanceiP6RValue+0x80> */
/* @0x1fe864 ldr r3, [pc, #0x6c] */
/* @0x1fe868 ldr r7, [r4, #0x84] */
/* @0x1fe86c ldr r3, [pc, r3] */
/* @0x1fe870 ldr r3, [r3] */
/* @0x1fe874 ldr r8, [r3, #0xb4] */
/* @0x1fe878 cmp r7, #0 */
/* @0x1fe87c cmpne r8, #0 */
/* @0x1fe880 moveq r6, #0 */
/* @0x1fe884 movne r6, #1 */
/* @0x1fe888 beq 0x1fe8c4 <_Z25SV_PhysicsLinearVelocityYP9CInstanceiP6RValue+0x80> */
/* @0x1fe88c ldr r3, [r9, #0xc] */
/* @0x1fe890 bic r3, r3, #-16777216 */
/* @0x1fe894 cmp r3, #0 */
/* @0x1fe898 bne 0x1fe8cc <_Z25SV_PhysicsLinearVelocityYP9CInstanceiP6RValue+0x88> */
/* @0x1fe89c ldm r9, {r0, r1} */
/* @0x1fe8a0 vmov d6, r0, r1 */
/* @0x1fe8a4 vldr s15, [r8, #96] */
/* @0x1fe8a8 ldr r3, [r7] */
/* @0x1fe8ac mov r0, r7 */
/* @0x1fe8b0 vcvt.f32.f64 s14, d6 */
/* @0x1fe8b4 ldr r1, [r3, #0x50] */
/* @0x1fe8b8 vmul.f32 s15, s14, s15 */
/* @0x1fe8bc vmov r2, s15 */
/* @0x1fe8c0 bl 0x236e9c <_ZN14CPhysicsObject17SetLinearVelocityEff> */
/* @0x1fe8c4 mov r0, r6 */
/* @0x1fe8c8 pop {r4, r6, r7, r8, r9, pc} */
/* @0x1fe8cc mov r0, r9 */
/* @0x1fe8d0 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fe8d4 b 0x1fe8a0 <_Z25SV_PhysicsLinearVelocityYP9CInstanceiP6RValue+0x5c> */
/* @0x1fe8d8 ldrheq pc, [lr], -r12 */

/* ── FUNC 0x1fe8dc · SV_PhysicsSpeedX(CInstance*, int, RValue*) · size=272 · insn=68 */
/* @0x1fe8dc mov r1, #1 */
/* @0x1fe8e0 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1fe8e4 vpush {d8} */
/* @0x1fe8e8 mov r9, r2 */
/* @0x1fe8ec mov r2, r1 */
/* @0x1fe8f0 mov r5, r0 */
/* @0x1fe8f4 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb> */
/* @0x1fe8f8 subs r6, r0, #0 */
/* @0x1fe8fc beq 0x1fe980 <_Z16SV_PhysicsSpeedXP9CInstanceiP6RValue+0xa4> */
/* @0x1fe900 ldr r4, [pc, #0xd8] */
/* @0x1fe904 ldr r7, [r5, #0x84] */
/* @0x1fe908 ldr r4, [pc, r4] */
/* @0x1fe90c ldr r2, [r4] */
/* @0x1fe910 ldr r8, [r2, #0xb4] */
/* @0x1fe914 cmp r7, #0 */
/* @0x1fe918 cmpne r8, #0 */
/* @0x1fe91c moveq r6, #0 */
/* @0x1fe920 movne r6, #1 */
/* @0x1fe924 beq 0x1fe980 <_Z16SV_PhysicsSpeedXP9CInstanceiP6RValue+0xa4> */
/* @0x1fe928 ldr r3, [pc, #0xb4] */
/* @0x1fe92c ldr r3, [pc, r3] */
/* @0x1fe930 ldrb r3, [r3] */
/* @0x1fe934 cmp r3, #0 */
/* @0x1fe938 ldr r3, [r9, #0xc] */
/* @0x1fe93c bic r3, r3, #-16777216 */
/* @0x1fe940 bne 0x1fe98c <_Z16SV_PhysicsSpeedXP9CInstanceiP6RValue+0xb0> */
/* @0x1fe944 cmp r3, #0 */
/* @0x1fe948 bne 0x1fe9c4 <_Z16SV_PhysicsSpeedXP9CInstanceiP6RValue+0xe8> */
/* @0x1fe94c ldm r9, {r0, r1} */
/* @0x1fe950 vmov d7, r0, r1 */
/* @0x1fe954 vldr s13, [r8, #96] */
/* @0x1fe958 vcvt.f32.f64 s12, d7 */
/* @0x1fe95c vldr s14, [r2, #12] */
/* @0x1fe960 vmul.f32 s13, s12, s13 */
/* @0x1fe964 vcvt.f32.s32 s14, s14 */
/* @0x1fe968 vmul.f32 s15, s13, s14 */
/* @0x1fe96c ldr r3, [r7] */
/* @0x1fe970 mov r0, r7 */
/* @0x1fe974 vmov r1, s15 */
/* @0x1fe978 ldr r2, [r3, #0x54] */
/* @0x1fe97c bl 0x236e9c <_ZN14CPhysicsObject17SetLinearVelocityEff> */
/* @0x1fe980 vpop {d8} */
/* @0x1fe984 mov r0, r6 */
/* @0x1fe988 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1fe98c cmp r3, #0 */
/* @0x1fe990 bne 0x1fe9d4 <_Z16SV_PhysicsSpeedXP9CInstanceiP6RValue+0xf8> */
/* @0x1fe994 ldm r9, {r0, r1} */
/* @0x1fe998 vmov d6, r0, r1 */
/* @0x1fe99c ldr r0, [pc, #0x44] */
/* @0x1fe9a0 vldr s15, [r8, #96] */
/* @0x1fe9a4 vcvt.f32.f64 s16, d6 */
/* @0x1fe9a8 ldr r0, [pc, r0] */
/* @0x1fe9ac vmul.f32 s16, s16, s15 */
/* @0x1fe9b0 bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0x1fe9b4 vmov d6, r0, r1 */
/* @0x1fe9b8 vcvt.f32.f64 s15, d6 */
/* @0x1fe9bc vmul.f32 s15, s16, s15 */
/* @0x1fe9c0 b 0x1fe96c <_Z16SV_PhysicsSpeedXP9CInstanceiP6RValue+0x90> */
/* @0x1fe9c4 mov r0, r9 */
/* @0x1fe9c8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fe9cc ldr r2, [r4] */
/* @0x1fe9d0 b 0x1fe950 <_Z16SV_PhysicsSpeedXP9CInstanceiP6RValue+0x74> */
/* @0x1fe9d4 mov r0, r9 */
/* @0x1fe9d8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fe9dc b 0x1fe998 <_Z16SV_PhysicsSpeedXP9CInstanceiP6RValue+0xbc> */
/* @0x1fe9e0 andseq pc, lr, r0, lsr #32 */
/* @0x1fe9e4 ldrsheq lr, [lr], -r8 */
/* @0x1fe9e8 andseq lr, lr, r4, lsl #31 */

/* ── FUNC 0x1fe9ec · SV_PhysicsSpeedY(CInstance*, int, RValue*) · size=272 · insn=68 */
/* @0x1fe9ec mov r1, #1 */
/* @0x1fe9f0 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1fe9f4 vpush {d8} */
/* @0x1fe9f8 mov r9, r2 */
/* @0x1fe9fc mov r2, r1 */
/* @0x1fea00 mov r5, r0 */
/* @0x1fea04 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb> */
/* @0x1fea08 subs r6, r0, #0 */
/* @0x1fea0c beq 0x1fea90 <_Z16SV_PhysicsSpeedYP9CInstanceiP6RValue+0xa4> */
/* @0x1fea10 ldr r4, [pc, #0xd8] */
/* @0x1fea14 ldr r7, [r5, #0x84] */
/* @0x1fea18 ldr r4, [pc, r4] */
/* @0x1fea1c ldr r2, [r4] */
/* @0x1fea20 ldr r8, [r2, #0xb4] */
/* @0x1fea24 cmp r7, #0 */
/* @0x1fea28 cmpne r8, #0 */
/* @0x1fea2c moveq r6, #0 */
/* @0x1fea30 movne r6, #1 */
/* @0x1fea34 beq 0x1fea90 <_Z16SV_PhysicsSpeedYP9CInstanceiP6RValue+0xa4> */
/* @0x1fea38 ldr r3, [pc, #0xb4] */
/* @0x1fea3c ldr r3, [pc, r3] */
/* @0x1fea40 ldrb r3, [r3] */
/* @0x1fea44 cmp r3, #0 */
/* @0x1fea48 ldr r3, [r9, #0xc] */
/* @0x1fea4c bic r3, r3, #-16777216 */
/* @0x1fea50 bne 0x1fea9c <_Z16SV_PhysicsSpeedYP9CInstanceiP6RValue+0xb0> */
/* @0x1fea54 cmp r3, #0 */
/* @0x1fea58 bne 0x1fead4 <_Z16SV_PhysicsSpeedYP9CInstanceiP6RValue+0xe8> */
/* @0x1fea5c ldm r9, {r0, r1} */
/* @0x1fea60 vmov d7, r0, r1 */
/* @0x1fea64 vldr s13, [r8, #96] */
/* @0x1fea68 vcvt.f32.f64 s12, d7 */
/* @0x1fea6c vldr s14, [r2, #12] */
/* @0x1fea70 vmul.f32 s13, s12, s13 */
/* @0x1fea74 vcvt.f32.s32 s14, s14 */
/* @0x1fea78 vmul.f32 s15, s13, s14 */
/* @0x1fea7c ldr r3, [r7] */
/* @0x1fea80 mov r0, r7 */
/* @0x1fea84 vmov r2, s15 */
/* @0x1fea88 ldr r1, [r3, #0x50] */
/* @0x1fea8c bl 0x236e9c <_ZN14CPhysicsObject17SetLinearVelocityEff> */
/* @0x1fea90 vpop {d8} */
/* @0x1fea94 mov r0, r6 */
/* @0x1fea98 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1fea9c cmp r3, #0 */
/* @0x1feaa0 bne 0x1feae4 <_Z16SV_PhysicsSpeedYP9CInstanceiP6RValue+0xf8> */
/* @0x1feaa4 ldm r9, {r0, r1} */
/* @0x1feaa8 vmov d6, r0, r1 */
/* @0x1feaac ldr r0, [pc, #0x44] */
/* @0x1feab0 vldr s15, [r8, #96] */
/* @0x1feab4 vcvt.f32.f64 s16, d6 */
/* @0x1feab8 ldr r0, [pc, r0] */
/* @0x1feabc vmul.f32 s16, s16, s15 */
/* @0x1feac0 bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0x1feac4 vmov d6, r0, r1 */
/* @0x1feac8 vcvt.f32.f64 s15, d6 */
/* @0x1feacc vmul.f32 s15, s16, s15 */
/* @0x1fead0 b 0x1fea7c <_Z16SV_PhysicsSpeedYP9CInstanceiP6RValue+0x90> */
/* @0x1fead4 mov r0, r9 */
/* @0x1fead8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1feadc ldr r2, [r4] */
/* @0x1feae0 b 0x1fea60 <_Z16SV_PhysicsSpeedYP9CInstanceiP6RValue+0x74> */
/* @0x1feae4 mov r0, r9 */
/* @0x1feae8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1feaec b 0x1feaa8 <_Z16SV_PhysicsSpeedYP9CInstanceiP6RValue+0xbc> */
/* @0x1feaf0 andseq lr, lr, r0, lsl pc */
/* @0x1feaf4 andseq lr, lr, r8, ror #29 */
/* @0x1feaf8 andseq lr, lr, r4, ror lr */
