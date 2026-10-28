/* libyoyo.so 覆盖卡组 0047
 * 函数 0x11a980..0x11b2e4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x11a980 · F_DrawGetPixel(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x11a980 push {r4, lr} */
/* @0x11a984 sub sp, sp, #8 */
/* @0x11a988 mov r4, r0 */
/* @0x11a98c ldr r12, [sp, #0x10] */
/* @0x11a990 str r12, [sp] */
/* @0x11a994 bl 0x11a8ec <_Z17F_DrawGetPixelExtR6RValueP9CInstanceS2_iPS_> */
/* @0x11a998 ldm r4, {r2, r3} */
/* @0x11a99c vmov d7, r2, r3 */
/* @0x11a9a0 vcvt.u32.f64 s15, d7 */
/* @0x11a9a4 vmov r2, s15 */
/* @0x11a9a8 bic r2, r2, #-16777216 */
/* @0x11a9ac vmov s15, r2 */
/* @0x11a9b0 vcvt.f64.s32 d7, s15 */
/* @0x11a9b4 vmov r2, r3, d7 */
/* @0x11a9b8 stm r4, {r2, r3} */
/* @0x11a9bc add sp, sp, #8 */
/* @0x11a9c0 pop {r4, pc} */

/* ── FUNC 0x11a9c4 · F_DrawSetColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x11a9c4 push {r3, lr} */
/* @0x11a9c8 mov r1, #0 */
/* @0x11a9cc ldr r0, [sp, #0x8] */
/* @0x11a9d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a9d4 pop {r3, lr} */
/* @0x11a9d8 b 0x169d98 <_Z21YYGML_draw_set_colourj> */

/* ── FUNC 0x11a9dc · F_DrawSetAlpha(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x11a9dc push {r3, lr} */
/* @0x11a9e0 mov r1, #0 */
/* @0x11a9e4 ldr r0, [sp, #0x8] */
/* @0x11a9e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11a9ec pop {r3, lr} */
/* @0x11a9f0 b 0x169dc4 <_Z20YYGML_draw_set_alphaf> */

/* ── FUNC 0x11a9f4 · F_DrawGetColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x11a9f4 push {r4, lr} */
/* @0x11a9f8 mov r3, #0 */
/* @0x11a9fc str r3, [r0, #0xc] */
/* @0x11aa00 mov r4, r0 */
/* @0x11aa04 bl 0x169ecc <_Z17GR_Draw_Get_Colorv> */
/* @0x11aa08 bic r0, r0, #-16777216 */
/* @0x11aa0c vmov s15, r0 */
/* @0x11aa10 vcvt.f64.s32 d7, s15 */
/* @0x11aa14 vmov r2, r3, d7 */
/* @0x11aa18 stm r4, {r2, r3} */
/* @0x11aa1c pop {r4, pc} */

/* ── FUNC 0x11aa20 · F_DrawGetAlpha(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x11aa20 push {r4, lr} */
/* @0x11aa24 mov r3, #0 */
/* @0x11aa28 str r3, [r0, #0xc] */
/* @0x11aa2c mov r4, r0 */
/* @0x11aa30 bl 0x169f1c <_Z17GR_Draw_Get_Alphav> */
/* @0x11aa34 vmov s15, r0 */
/* @0x11aa38 vcvt.f64.f32 d7, s15 */
/* @0x11aa3c vmov r0, r1, d7 */
/* @0x11aa40 vmov r2, s14 */
/* @0x11aa44 mov r3, r1 */
/* @0x11aa48 stm r4, {r2, r3} */
/* @0x11aa4c pop {r4, pc} */

/* ── FUNC 0x11aa50 · F_MakeColorHSV(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x11aa50 push {r4, r5, r6, r7, lr} */
/* @0x11aa54 sub sp, sp, #12 */
/* @0x11aa58 mov r5, r0 */
/* @0x11aa5c mov r1, #0 */
/* @0x11aa60 ldr r4, [sp, #0x20] */
/* @0x11aa64 str r1, [r0, #0xc] */
/* @0x11aa68 mov r0, r4 */
/* @0x11aa6c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11aa70 mov r1, #1 */
/* @0x11aa74 mov r7, r0 */
/* @0x11aa78 mov r0, r4 */
/* @0x11aa7c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11aa80 mov r1, #2 */
/* @0x11aa84 mov r6, r0 */
/* @0x11aa88 mov r0, r4 */
/* @0x11aa8c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11aa90 mov r1, r6 */
/* @0x11aa94 mov r2, r0 */
/* @0x11aa98 mov r0, r7 */
/* @0x11aa9c bl 0x20f9d8 <_Z9Color_HSViii> */
/* @0x11aaa0 mov r3, r0 */
/* @0x11aaa4 add r0, sp, #4 */
/* @0x11aaa8 ubfx r2, r3, #0x8, #0x8 */
/* @0x11aaac strb r3, [sp, #0x4] */
/* @0x11aab0 strb r2, [sp, #0x5] */
/* @0x11aab4 ubfx r3, r3, #0x10, #0x8 */
/* @0x11aab8 strb r3, [sp, #0x6] */
/* @0x11aabc bl 0x20feac <_Z16Color_HSVToColorR4THSV> */
/* @0x11aac0 vmov s15, r0 */
/* @0x11aac4 vcvt.f64.u32 d7, s15 */
/* @0x11aac8 vmov r0, r1, d7 */
/* @0x11aacc vmov r2, s14 */
/* @0x11aad0 mov r3, r1 */
/* @0x11aad4 stm r5, {r2, r3} */
/* @0x11aad8 add sp, sp, #12 */
/* @0x11aadc pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x11aae0 · F_ColorGetHue(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x11aae0 push {r4, lr} */
/* @0x11aae4 sub sp, sp, #8 */
/* @0x11aae8 mov r3, #0 */
/* @0x11aaec mov r4, r0 */
/* @0x11aaf0 mov r1, r3 */
/* @0x11aaf4 str r3, [r0, #0xc] */
/* @0x11aaf8 ldr r0, [sp, #0x10] */
/* @0x11aafc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ab00 bl 0x20fca8 <_Z16Color_ColorToHSVj> */
/* @0x11ab04 uxtb r0, r0 */
/* @0x11ab08 vmov s15, r0 */
/* @0x11ab0c vcvt.f64.u32 d7, s15 */
/* @0x11ab10 vmov r2, r3, d7 */
/* @0x11ab14 stm r4, {r2, r3} */
/* @0x11ab18 add sp, sp, #8 */
/* @0x11ab1c pop {r4, pc} */

/* ── FUNC 0x11ab20 · F_ColorGetSaturation(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x11ab20 push {r4, lr} */
/* @0x11ab24 sub sp, sp, #8 */
/* @0x11ab28 mov r3, #0 */
/* @0x11ab2c mov r4, r0 */
/* @0x11ab30 mov r1, r3 */
/* @0x11ab34 str r3, [r0, #0xc] */
/* @0x11ab38 ldr r0, [sp, #0x10] */
/* @0x11ab3c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ab40 bl 0x20fca8 <_Z16Color_ColorToHSVj> */
/* @0x11ab44 ubfx r0, r0, #0x8, #0x8 */
/* @0x11ab48 vmov s15, r0 */
/* @0x11ab4c vcvt.f64.u32 d7, s15 */
/* @0x11ab50 vmov r2, r3, d7 */
/* @0x11ab54 stm r4, {r2, r3} */
/* @0x11ab58 add sp, sp, #8 */
/* @0x11ab5c pop {r4, pc} */

/* ── FUNC 0x11ab60 · F_ColorGetValue(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x11ab60 push {r4, lr} */
/* @0x11ab64 sub sp, sp, #8 */
/* @0x11ab68 mov r3, #0 */
/* @0x11ab6c mov r4, r0 */
/* @0x11ab70 mov r1, r3 */
/* @0x11ab74 str r3, [r0, #0xc] */
/* @0x11ab78 ldr r0, [sp, #0x10] */
/* @0x11ab7c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ab80 bl 0x20fca8 <_Z16Color_ColorToHSVj> */
/* @0x11ab84 ubfx r0, r0, #0x10, #0x8 */
/* @0x11ab88 vmov s15, r0 */
/* @0x11ab8c vcvt.f64.u32 d7, s15 */
/* @0x11ab90 vmov r2, r3, d7 */
/* @0x11ab94 stm r4, {r2, r3} */
/* @0x11ab98 add sp, sp, #8 */
/* @0x11ab9c pop {r4, pc} */

/* ── FUNC 0x11aba0 · F_MergeColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x11aba0 push {r3, r4, r5, r6, r7, lr} */
/* @0x11aba4 mov r1, #0 */
/* @0x11aba8 ldr r4, [sp, #0x18] */
/* @0x11abac mov r5, r0 */
/* @0x11abb0 str r1, [r0, #0xc] */
/* @0x11abb4 mov r0, r4 */
/* @0x11abb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11abbc mov r1, #1 */
/* @0x11abc0 mov r7, r0 */
/* @0x11abc4 mov r0, r4 */
/* @0x11abc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11abcc mov r1, #2 */
/* @0x11abd0 mov r6, r0 */
/* @0x11abd4 mov r0, r4 */
/* @0x11abd8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11abdc mov r1, r6 */
/* @0x11abe0 mov r2, r0 */
/* @0x11abe4 mov r0, r7 */
/* @0x11abe8 bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0x11abec vmov s15, r0 */
/* @0x11abf0 vcvt.f64.u32 d7, s15 */
/* @0x11abf4 vmov r0, r1, d7 */
/* @0x11abf8 vmov r2, s14 */
/* @0x11abfc mov r3, r1 */
/* @0x11ac00 stm r5, {r2, r3} */
/* @0x11ac04 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x11ac08 · F_DrawSetBlendMode(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x11ac08 push {r3, lr} */
/* @0x11ac0c mov r1, #0 */
/* @0x11ac10 ldr r0, [sp, #0x8] */
/* @0x11ac14 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ac18 pop {r3, lr} */
/* @0x11ac1c b 0x168360 <_Z16GR_D3D_Set_Blendi> */

/* ── FUNC 0x11ac20 · F_DrawSetBlendModeExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x11ac20 push {r3, r4, r5, lr} */
/* @0x11ac24 mov r1, #0 */
/* @0x11ac28 ldr r4, [sp, #0x10] */
/* @0x11ac2c mov r0, r4 */
/* @0x11ac30 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ac34 mov r1, #1 */
/* @0x11ac38 mov r5, r0 */
/* @0x11ac3c mov r0, r4 */
/* @0x11ac40 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ac44 mov r1, r0 */
/* @0x11ac48 mov r0, r5 */
/* @0x11ac4c pop {r3, r4, r5, lr} */
/* @0x11ac50 b 0x168304 <_Z20GR_D3D_Set_Blend_Extii> */

/* ── FUNC 0x11ac54 · F_DrawSetColorWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x11ac54 push {r4, r5, r6, r7, r8, lr} */
/* @0x11ac58 mov r1, #0 */
/* @0x11ac5c ldr r4, [sp, #0x18] */
/* @0x11ac60 mov r0, r4 */
/* @0x11ac64 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11ac68 mov r1, #1 */
/* @0x11ac6c mov r7, r0 */
/* @0x11ac70 mov r0, r4 */
/* @0x11ac74 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11ac78 mov r1, #2 */
/* @0x11ac7c mov r6, r0 */
/* @0x11ac80 mov r0, r4 */
/* @0x11ac84 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11ac88 mov r1, #3 */
/* @0x11ac8c mov r5, r0 */
/* @0x11ac90 mov r0, r4 */
/* @0x11ac94 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11ac98 mov r1, r6 */
/* @0x11ac9c mov r2, r5 */
/* @0x11aca0 mov r3, r0 */
/* @0x11aca4 mov r0, r7 */
/* @0x11aca8 pop {r4, r5, r6, r7, r8, lr} */
/* @0x11acac b 0x1683a4 <_Z30GR_D3D_Set_Colour_Write_Enablebbbb> */

/* ── FUNC 0x11acb0 · F_DrawSetAlphaTest(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x11acb0 push {r3, lr} */
/* @0x11acb4 mov r1, #0 */
/* @0x11acb8 ldr r0, [sp, #0x8] */
/* @0x11acbc bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11acc0 pop {r3, lr} */
/* @0x11acc4 b 0x168664 <_Z28GR_D3D_Set_Alpha_Test_Enableb> */

/* ── FUNC 0x11acc8 · F_DrawGetAlphaTest(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x11acc8 push {r4, lr} */
/* @0x11accc mov r3, #0 */
/* @0x11acd0 str r3, [r0, #0xc] */
/* @0x11acd4 mov r4, r0 */
/* @0x11acd8 bl 0x168694 <_Z28GR_D3D_Get_Alpha_Test_Enablev> */
/* @0x11acdc vmov s15, r0 */
/* @0x11ace0 vcvt.f64.u32 d7, s15 */
/* @0x11ace4 vmov r0, r1, d7 */
/* @0x11ace8 vmov r2, s14 */
/* @0x11acec mov r3, r1 */
/* @0x11acf0 stm r4, {r2, r3} */
/* @0x11acf4 pop {r4, pc} */

/* ── FUNC 0x11acf8 · F_DrawSetAlphaTestRefValue(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x11acf8 push {r3, lr} */
/* @0x11acfc mov r1, #0 */
/* @0x11ad00 ldr r0, [sp, #0x8] */
/* @0x11ad04 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ad08 pop {r3, lr} */
/* @0x11ad0c b 0x1686b8 <_Z25GR_D3D_Set_Alpha_Test_Refj> */

/* ── FUNC 0x11ad10 · F_DrawGetAlphaTestRefValue(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x11ad10 push {r4, lr} */
/* @0x11ad14 mov r3, #0 */
/* @0x11ad18 str r3, [r0, #0xc] */
/* @0x11ad1c mov r4, r0 */
/* @0x11ad20 bl 0x1686d0 <_Z25GR_D3D_Get_Alpha_Test_Refv> */
/* @0x11ad24 vmov s15, r0 */
/* @0x11ad28 vcvt.f64.u32 d7, s15 */
/* @0x11ad2c vmov r0, r1, d7 */
/* @0x11ad30 vmov r2, s14 */
/* @0x11ad34 mov r3, r1 */
/* @0x11ad38 stm r4, {r2, r3} */
/* @0x11ad3c pop {r4, pc} */

/* ── FUNC 0x11ad40 · F_DrawClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x11ad40 push {r3, lr} */
/* @0x11ad44 mov r1, #0 */
/* @0x11ad48 ldr r0, [sp, #0x8] */
/* @0x11ad4c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ad50 pop {r3, lr} */
/* @0x11ad54 orr r0, r0, #-16777216 */
/* @0x11ad58 b 0x169f58 <_Z13GR_Draw_Clearj> */

/* ── FUNC 0x11ad5c · F_DrawClearAlpha(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x11ad5c push {r3, r4, r5, lr} */
/* @0x11ad60 mov r1, #0 */
/* @0x11ad64 ldr r4, [sp, #0x10] */
/* @0x11ad68 mov r0, r4 */
/* @0x11ad6c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ad70 mov r1, #1 */
/* @0x11ad74 mov r5, r0 */
/* @0x11ad78 mov r0, r4 */
/* @0x11ad7c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ad80 mov r1, r0 */
/* @0x11ad84 mov r0, r5 */
/* @0x11ad88 pop {r3, r4, r5, lr} */
/* @0x11ad8c b 0x16a0a4 <_Z19GR_Draw_Clear_Alphajf> */

/* ── FUNC 0x11ad90 · F_DrawPoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x11ad90 push {r3, r4, r5, lr} */
/* @0x11ad94 mov r1, #0 */
/* @0x11ad98 ldr r4, [sp, #0x10] */
/* @0x11ad9c mov r0, r4 */
/* @0x11ada0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ada4 mov r1, #1 */
/* @0x11ada8 mov r5, r0 */
/* @0x11adac mov r0, r4 */
/* @0x11adb0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11adb4 mov r1, r0 */
/* @0x11adb8 mov r0, r5 */
/* @0x11adbc pop {r3, r4, r5, lr} */
/* @0x11adc0 b 0x16a0c0 <_Z16YYGML_draw_pointff> */

/* ── FUNC 0x11adc4 · F_DrawPointExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x11adc4 push {r4, r5, r6, lr} */
/* @0x11adc8 mov r1, #0 */
/* @0x11adcc ldr r4, [sp, #0x10] */
/* @0x11add0 mov r0, r4 */
/* @0x11add4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11add8 mov r1, #1 */
/* @0x11addc mov r6, r0 */
/* @0x11ade0 mov r0, r4 */
/* @0x11ade4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ade8 mov r1, #2 */
/* @0x11adec mov r5, r0 */
/* @0x11adf0 mov r0, r4 */
/* @0x11adf4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11adf8 mov r1, r5 */
/* @0x11adfc mov r2, r0 */
/* @0x11ae00 mov r0, r6 */
/* @0x11ae04 pop {r4, r5, r6, lr} */
/* @0x11ae08 b 0x16a168 <_Z20YYGML_draw_point_extffj> */

/* ── FUNC 0x11ae0c · F_DrawLine(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x11ae0c push {r4, r5, r6, r7, r8, lr} */
/* @0x11ae10 mov r1, #0 */
/* @0x11ae14 ldr r4, [sp, #0x18] */
/* @0x11ae18 mov r0, r4 */
/* @0x11ae1c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ae20 mov r1, #1 */
/* @0x11ae24 mov r7, r0 */
/* @0x11ae28 mov r0, r4 */
/* @0x11ae2c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ae30 mov r1, #2 */
/* @0x11ae34 mov r6, r0 */
/* @0x11ae38 mov r0, r4 */
/* @0x11ae3c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ae40 mov r1, #3 */
/* @0x11ae44 mov r5, r0 */
/* @0x11ae48 mov r0, r4 */
/* @0x11ae4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ae50 mov r1, r6 */
/* @0x11ae54 mov r2, r5 */
/* @0x11ae58 mov r3, r0 */
/* @0x11ae5c mov r0, r7 */
/* @0x11ae60 pop {r4, r5, r6, r7, r8, lr} */
/* @0x11ae64 b 0x16a21c <_Z12GR_Draw_Lineffff> */

/* ── FUNC 0x11ae68 · F_DrawLineWidth(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x11ae68 push {r4, r5, r6, r7, r8, lr} */
/* @0x11ae6c mov r1, #0 */
/* @0x11ae70 ldr r4, [sp, #0x18] */
/* @0x11ae74 mov r0, r4 */
/* @0x11ae78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ae7c mov r1, #1 */
/* @0x11ae80 mov r5, r0 */
/* @0x11ae84 mov r0, r4 */
/* @0x11ae88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ae8c mov r1, #2 */
/* @0x11ae90 mov r8, r0 */
/* @0x11ae94 mov r0, r4 */
/* @0x11ae98 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ae9c mov r1, #3 */
/* @0x11aea0 mov r7, r0 */
/* @0x11aea4 mov r0, r4 */
/* @0x11aea8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11aeac mov r1, #4 */
/* @0x11aeb0 mov r6, r0 */
/* @0x11aeb4 mov r0, r4 */
/* @0x11aeb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11aebc mov r1, r8 */
/* @0x11aec0 mov r2, r7 */
/* @0x11aec4 mov r3, r6 */
/* @0x11aec8 str r0, [sp, #0x18] */
/* @0x11aecc mov r0, r5 */
/* @0x11aed0 pop {r4, r5, r6, r7, r8, lr} */
/* @0x11aed4 b 0x16a2ec <_Z18GR_Draw_Line_Widthfffff> */

/* ── FUNC 0x11aed8 · F_DrawRectangle(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x11aed8 push {r4, r5, r6, r7, r8, lr} */
/* @0x11aedc mov r1, #0 */
/* @0x11aee0 ldr r4, [sp, #0x18] */
/* @0x11aee4 mov r0, r4 */
/* @0x11aee8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11aeec mov r1, #1 */
/* @0x11aef0 mov r5, r0 */
/* @0x11aef4 mov r0, r4 */
/* @0x11aef8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11aefc mov r1, #2 */
/* @0x11af00 mov r8, r0 */
/* @0x11af04 mov r0, r4 */
/* @0x11af08 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11af0c mov r1, #3 */
/* @0x11af10 mov r7, r0 */
/* @0x11af14 mov r0, r4 */
/* @0x11af18 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11af1c mov r1, #4 */
/* @0x11af20 mov r6, r0 */
/* @0x11af24 mov r0, r4 */
/* @0x11af28 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11af2c mov r1, r8 */
/* @0x11af30 mov r2, r7 */
/* @0x11af34 mov r3, r6 */
/* @0x11af38 str r0, [sp, #0x18] */
/* @0x11af3c mov r0, r5 */
/* @0x11af40 pop {r4, r5, r6, r7, r8, lr} */
/* @0x11af44 b 0x16aa1c <_Z20YYGML_draw_rectangleffffb> */

/* ── FUNC 0x11af48 · F_DrawRoundRect(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x11af48 push {r4, r5, r6, r7, r8, lr} */
/* @0x11af4c sub sp, sp, #16 */
/* @0x11af50 mov r1, #0 */
/* @0x11af54 ldr r4, [sp, #0x28] */
/* @0x11af58 mov r0, r4 */
/* @0x11af5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11af60 mov r1, #1 */
/* @0x11af64 mov r5, r0 */
/* @0x11af68 mov r0, r4 */
/* @0x11af6c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11af70 mov r1, #2 */
/* @0x11af74 mov r8, r0 */
/* @0x11af78 mov r0, r4 */
/* @0x11af7c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11af80 mov r1, #3 */
/* @0x11af84 mov r7, r0 */
/* @0x11af88 mov r0, r4 */
/* @0x11af8c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11af90 mov r1, #4 */
/* @0x11af94 mov r6, r0 */
/* @0x11af98 mov r0, r4 */
/* @0x11af9c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11afa0 mov r1, r8 */
/* @0x11afa4 mov r2, r7 */
/* @0x11afa8 mov r3, r6 */
/* @0x11afac mov r12, #0 */
/* @0x11afb0 movt r12, #0x4120 */
/* @0x11afb4 str r12, [sp] */
/* @0x11afb8 str r12, [sp, #0x4] */
/* @0x11afbc str r0, [sp, #0x8] */
/* @0x11afc0 mov r0, r5 */
/* @0x11afc4 bl 0x16b77c <_Z17GR_Draw_RoundRectffffffb> */
/* @0x11afc8 add sp, sp, #16 */
/* @0x11afcc pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x11afd0 · F_DrawRoundRect_EXT(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0x11afd0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11afd4 sub sp, sp, #16 */
/* @0x11afd8 mov r1, #4 */
/* @0x11afdc ldr r4, [sp, #0x30] */
/* @0x11afe0 mov r0, r4 */
/* @0x11afe4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11afe8 mov r1, #5 */
/* @0x11afec mov r10, r0 */
/* @0x11aff0 mov r0, r4 */
/* @0x11aff4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11aff8 mov r1, #0 */
/* @0x11affc mov r9, r0 */
/* @0x11b000 mov r0, r4 */
/* @0x11b004 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b008 mov r1, #1 */
/* @0x11b00c mov r5, r0 */
/* @0x11b010 mov r0, r4 */
/* @0x11b014 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b018 mov r1, #2 */
/* @0x11b01c mov r8, r0 */
/* @0x11b020 mov r0, r4 */
/* @0x11b024 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b028 mov r1, #3 */
/* @0x11b02c mov r7, r0 */
/* @0x11b030 mov r0, r4 */
/* @0x11b034 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b038 mov r1, #6 */
/* @0x11b03c mov r6, r0 */
/* @0x11b040 mov r0, r4 */
/* @0x11b044 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b048 str r10, [sp] */
/* @0x11b04c str r9, [sp, #0x4] */
/* @0x11b050 mov r1, r8 */
/* @0x11b054 mov r2, r7 */
/* @0x11b058 mov r3, r6 */
/* @0x11b05c vmov s15, r0 */
/* @0x11b060 mov r0, r5 */
/* @0x11b064 vcmpe.f32 s15, #0 */
/* @0x11b068 vmrs APSR_nzcv, fpscr */
/* @0x11b06c movle r12, #0 */
/* @0x11b070 movgt r12, #1 */
/* @0x11b074 str r12, [sp, #0x8] */
/* @0x11b078 bl 0x16b77c <_Z17GR_Draw_RoundRectffffffb> */
/* @0x11b07c add sp, sp, #16 */
/* @0x11b080 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x11b084 · F_DrawTriangle(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0x11b084 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11b088 sub sp, sp, #16 */
/* @0x11b08c mov r1, #0 */
/* @0x11b090 ldr r4, [sp, #0x30] */
/* @0x11b094 mov r0, r4 */
/* @0x11b098 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b09c mov r1, #1 */
/* @0x11b0a0 mov r5, r0 */
/* @0x11b0a4 mov r0, r4 */
/* @0x11b0a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b0ac mov r1, #2 */
/* @0x11b0b0 mov r8, r0 */
/* @0x11b0b4 mov r0, r4 */
/* @0x11b0b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b0bc mov r1, #3 */
/* @0x11b0c0 mov r7, r0 */
/* @0x11b0c4 mov r0, r4 */
/* @0x11b0c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b0cc mov r1, #4 */
/* @0x11b0d0 mov r6, r0 */
/* @0x11b0d4 mov r0, r4 */
/* @0x11b0d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b0dc mov r1, #5 */
/* @0x11b0e0 mov r10, r0 */
/* @0x11b0e4 mov r0, r4 */
/* @0x11b0e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b0ec mov r1, #6 */
/* @0x11b0f0 mov r9, r0 */
/* @0x11b0f4 mov r0, r4 */
/* @0x11b0f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b0fc str r10, [sp] */
/* @0x11b100 str r9, [sp, #0x4] */
/* @0x11b104 mov r1, r8 */
/* @0x11b108 mov r2, r7 */
/* @0x11b10c mov r3, r6 */
/* @0x11b110 vmov s15, r0 */
/* @0x11b114 mov r0, r5 */
/* @0x11b118 vcmpe.f32 s15, #0 */
/* @0x11b11c vmrs APSR_nzcv, fpscr */
/* @0x11b120 movle r12, #0 */
/* @0x11b124 movgt r12, #1 */
/* @0x11b128 str r12, [sp, #0x8] */
/* @0x11b12c bl 0x16a6f0 <_Z16GR_Draw_Triangleffffffb> */
/* @0x11b130 add sp, sp, #16 */
/* @0x11b134 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x11b138 · F_DrawCircle(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x11b138 push {r4, r5, r6, r7, r8, lr} */
/* @0x11b13c mov r1, #0 */
/* @0x11b140 ldr r4, [sp, #0x18] */
/* @0x11b144 mov r0, r4 */
/* @0x11b148 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b14c mov r1, #1 */
/* @0x11b150 mov r7, r0 */
/* @0x11b154 mov r0, r4 */
/* @0x11b158 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b15c mov r1, #2 */
/* @0x11b160 mov r6, r0 */
/* @0x11b164 mov r0, r4 */
/* @0x11b168 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b16c mov r1, #3 */
/* @0x11b170 mov r5, r0 */
/* @0x11b174 mov r0, r4 */
/* @0x11b178 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11b17c mov r1, r6 */
/* @0x11b180 mov r2, r5 */
/* @0x11b184 mov r3, r0 */
/* @0x11b188 mov r0, r7 */
/* @0x11b18c pop {r4, r5, r6, r7, r8, lr} */
/* @0x11b190 b 0x16b198 <_Z14GR_Draw_Circlefffb> */

/* ── FUNC 0x11b194 · F_DrawEllipse(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x11b194 push {r4, r5, r6, r7, r8, lr} */
/* @0x11b198 mov r1, #0 */
/* @0x11b19c ldr r4, [sp, #0x18] */
/* @0x11b1a0 mov r0, r4 */
/* @0x11b1a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b1a8 mov r1, #1 */
/* @0x11b1ac mov r5, r0 */
/* @0x11b1b0 mov r0, r4 */
/* @0x11b1b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b1b8 mov r1, #2 */
/* @0x11b1bc mov r8, r0 */
/* @0x11b1c0 mov r0, r4 */
/* @0x11b1c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b1c8 mov r1, #3 */
/* @0x11b1cc mov r7, r0 */
/* @0x11b1d0 mov r0, r4 */
/* @0x11b1d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b1d8 mov r1, #4 */
/* @0x11b1dc mov r6, r0 */
/* @0x11b1e0 mov r0, r4 */
/* @0x11b1e4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11b1e8 mov r1, r8 */
/* @0x11b1ec mov r2, r7 */
/* @0x11b1f0 mov r3, r6 */
/* @0x11b1f4 str r0, [sp, #0x18] */
/* @0x11b1f8 mov r0, r5 */
/* @0x11b1fc pop {r4, r5, r6, r7, r8, lr} */
/* @0x11b200 b 0x16b278 <_Z15GR_Draw_Ellipseffffb> */

/* ── FUNC 0x11b204 · F_DrawArrow(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x11b204 push {r4, r5, r6, r7, r8, lr} */
/* @0x11b208 mov r1, #0 */
/* @0x11b20c ldr r4, [sp, #0x18] */
/* @0x11b210 mov r0, r4 */
/* @0x11b214 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b218 mov r1, #1 */
/* @0x11b21c mov r5, r0 */
/* @0x11b220 mov r0, r4 */
/* @0x11b224 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b228 mov r1, #2 */
/* @0x11b22c mov r8, r0 */
/* @0x11b230 mov r0, r4 */
/* @0x11b234 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b238 mov r1, #3 */
/* @0x11b23c mov r7, r0 */
/* @0x11b240 mov r0, r4 */
/* @0x11b244 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b248 mov r1, #4 */
/* @0x11b24c mov r6, r0 */
/* @0x11b250 mov r0, r4 */
/* @0x11b254 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b258 mov r1, r8 */
/* @0x11b25c mov r2, r7 */
/* @0x11b260 mov r3, r6 */
/* @0x11b264 str r0, [sp, #0x18] */
/* @0x11b268 mov r0, r5 */
/* @0x11b26c pop {r4, r5, r6, r7, r8, lr} */
/* @0x11b270 b 0x16bee4 <_Z13GR_Draw_Arrowfffff> */

/* ── FUNC 0x11b274 · F_DrawButton(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x11b274 push {r4, r5, r6, r7, r8, lr} */
/* @0x11b278 mov r1, #0 */
/* @0x11b27c ldr r4, [sp, #0x18] */
/* @0x11b280 mov r0, r4 */
/* @0x11b284 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b288 mov r1, #1 */
/* @0x11b28c mov r5, r0 */
/* @0x11b290 mov r0, r4 */
/* @0x11b294 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b298 mov r1, #2 */
/* @0x11b29c mov r8, r0 */
/* @0x11b2a0 mov r0, r4 */
/* @0x11b2a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b2a8 mov r1, #3 */
/* @0x11b2ac mov r7, r0 */
/* @0x11b2b0 mov r0, r4 */
/* @0x11b2b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b2b8 mov r1, #4 */
/* @0x11b2bc mov r6, r0 */
/* @0x11b2c0 mov r0, r4 */
/* @0x11b2c4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11b2c8 mov r1, r8 */
/* @0x11b2cc mov r2, r7 */
/* @0x11b2d0 mov r3, r6 */
/* @0x11b2d4 str r0, [sp, #0x18] */
/* @0x11b2d8 mov r0, r5 */
/* @0x11b2dc pop {r4, r5, r6, r7, r8, lr} */
/* @0x11b2e0 b 0x16bfc4 <_Z14GR_Draw_Buttonffffb> */

/* ── FUNC 0x11b2e4 · F_DrawHealthbar(RValue&, CInstance*, CInstance*, int, RValue*) · size=276 · insn=69 */
/* @0x11b2e4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11b2e8 sub sp, sp, #52 */
/* @0x11b2ec mov r1, #0 */
/* @0x11b2f0 ldr r4, [sp, #0x58] */
/* @0x11b2f4 mov r0, r4 */
/* @0x11b2f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b2fc mov r1, #1 */
/* @0x11b300 mov r7, r0 */
/* @0x11b304 mov r0, r4 */
/* @0x11b308 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b30c mov r1, #2 */
/* @0x11b310 mov r9, r0 */
/* @0x11b314 mov r0, r4 */
/* @0x11b318 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b31c mov r1, #3 */
/* @0x11b320 mov r8, r0 */
/* @0x11b324 mov r0, r4 */
/* @0x11b328 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b32c mov r1, #4 */
/* @0x11b330 mov r3, r0 */
/* @0x11b334 mov r0, r4 */
/* @0x11b338 str r3, [sp, #0x24] */
/* @0x11b33c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b340 mov r1, #5 */
/* @0x11b344 mov r12, r0 */
/* @0x11b348 mov r0, r4 */
/* @0x11b34c str r12, [sp, #0x28] */
/* @0x11b350 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b354 mov r1, #6 */
/* @0x11b358 str r0, [sp, #0x2c] */
/* @0x11b35c mov r0, r4 */
/* @0x11b360 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b364 mov r1, #7 */
/* @0x11b368 mov r6, r0 */
/* @0x11b36c mov r0, r4 */
/* @0x11b370 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b374 mov r1, #8 */
/* @0x11b378 mov r5, r0 */
/* @0x11b37c mov r0, r4 */
/* @0x11b380 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b384 mov r1, #9 */
/* @0x11b388 mov r11, r0 */
/* @0x11b38c mov r0, r4 */
/* @0x11b390 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11b394 mov r1, #10 */
/* @0x11b398 mov r10, r0 */
/* @0x11b39c mov r0, r4 */
/* @0x11b3a0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11b3a4 mov r1, r5 */
/* @0x11b3a8 mov r2, #1056964608 */
/* @0x11b3ac mov r4, r0 */
/* @0x11b3b0 mov r0, r6 */
/* @0x11b3b4 bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0x11b3b8 ldr r2, [sp, #0x2c] */
/* @0x11b3bc ldr r12, [sp, #0x28] */
/* @0x11b3c0 mov r1, r9 */
/* @0x11b3c4 str r5, [sp, #0x10] */
/* @0x11b3c8 stmib sp, {r2, r6} */
/* @0x11b3cc mov r2, r8 */
/* @0x11b3d0 str r12, [sp] */
/* @0x11b3d4 str r11, [sp, #0x14] */
/* @0x11b3d8 str r10, [sp, #0x18] */
/* @0x11b3dc str r4, [sp, #0x1c] */
/* @0x11b3e0 ldr r3, [sp, #0x24] */
/* @0x11b3e4 str r0, [sp, #0xc] */
/* @0x11b3e8 mov r0, r7 */
/* @0x11b3ec bl 0x16c0d8 <_Z17GR_Draw_Healthbarfffffjjjjibb> */
/* @0x11b3f0 add sp, sp, #52 */
/* @0x11b3f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
