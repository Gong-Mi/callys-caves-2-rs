/* libyoyo.so 覆盖卡组 0045
 * 函数 0x119b28..0x11a1fc，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x119b28 · F_WindowGetStayontop(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x119b28 mov r3, #0 */
/* @0x119b2c str r3, [r0, #0xc] */
/* @0x119b30 str r3, [r0] */
/* @0x119b34 str r3, [r0, #0x4] */
/* @0x119b38 bx lr */

/* ── FUNC 0x119b3c · F_WindowSetSizeable(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x119b3c bx lr */

/* ── FUNC 0x119b40 · F_WindowGetSizeable(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x119b40 mov r3, #0 */
/* @0x119b44 str r3, [r0, #0xc] */
/* @0x119b48 str r3, [r0] */
/* @0x119b4c str r3, [r0, #0x4] */
/* @0x119b50 bx lr */

/* ── FUNC 0x119b54 · F_WindowDefault(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x119b54 bx lr */

/* ── FUNC 0x119b58 · F_WindowViewMouseSet(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x119b58 bx lr */

/* ── FUNC 0x119b5c · F_WindowViewsMouseSet(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x119b5c bx lr */

/* ── FUNC 0x119b60 · F_TileCount(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x119b60 ldr r3, [pc, #0x24] */
/* @0x119b64 mov r2, #0 */
/* @0x119b68 str r2, [r0, #0xc] */
/* @0x119b6c ldr r3, [pc, r3] */
/* @0x119b70 ldr r3, [r3] */
/* @0x119b74 ldr r2, [r3, #0xb8] */
/* @0x119b78 vmov s15, r2 */
/* @0x119b7c vcvt.f64.s32 d7, s15 */
/* @0x119b80 vmov r2, r3, d7 */
/* @0x119b84 stm r0, {r2, r3} */
/* @0x119b88 bx lr */
/* @0x119b8c .word 0x002d3dbc */

/* ── FUNC 0x119b90 · F_SurfaceGetDepthDisable(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x119b90 ldr r3, [pc, #0x28] */
/* @0x119b94 mov r1, #0 */
/* @0x119b98 str r1, [r0, #0xc] */
/* @0x119b9c ldr r3, [pc, r3] */
/* @0x119ba0 ldrb r2, [r3] */
/* @0x119ba4 cmp r2, r1 */
/* @0x119ba8 movne r2, r1 */
/* @0x119bac moveq r3, #0 */
/* @0x119bb0 movne r3, r2 */
/* @0x119bb4 movteq r3, #0x3ff0 */
/* @0x119bb8 stm r0, {r2, r3} */
/* @0x119bbc bx lr */
/* @0x119bc0 eoreq r4, sp, r4, lsr #20 */

/* ── FUNC 0x119bc4 · F_DisplayGetWidth(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x119bc4 push {r4, lr} */
/* @0x119bc8 mov r3, #0 */
/* @0x119bcc str r3, [r0, #0xc] */
/* @0x119bd0 mov r4, r0 */
/* @0x119bd4 bl 0x17db24 <_Z21Graphics_DisplayWidthv> */
/* @0x119bd8 vmov s15, r0 */
/* @0x119bdc vcvt.f64.s32 d7, s15 */
/* @0x119be0 vmov r0, r1, d7 */
/* @0x119be4 vmov r2, s14 */
/* @0x119be8 mov r3, r1 */
/* @0x119bec stm r4, {r2, r3} */
/* @0x119bf0 pop {r4, pc} */

/* ── FUNC 0x119bf4 · F_DisplayGetHeight(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x119bf4 push {r4, lr} */
/* @0x119bf8 mov r3, #0 */
/* @0x119bfc str r3, [r0, #0xc] */
/* @0x119c00 mov r4, r0 */
/* @0x119c04 bl 0x17db38 <_Z22Graphics_DisplayHeightv> */
/* @0x119c08 vmov s15, r0 */
/* @0x119c0c vcvt.f64.s32 d7, s15 */
/* @0x119c10 vmov r0, r1, d7 */
/* @0x119c14 vmov r2, s14 */
/* @0x119c18 mov r3, r1 */
/* @0x119c1c stm r4, {r2, r3} */
/* @0x119c20 pop {r4, pc} */

/* ── FUNC 0x119c24 · F_DisplayGetColordepth(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x119c24 push {r4, lr} */
/* @0x119c28 mov r3, #0 */
/* @0x119c2c str r3, [r0, #0xc] */
/* @0x119c30 mov r4, r0 */
/* @0x119c34 bl 0x17db54 <_Z17DisplayColorDepthv> */
/* @0x119c38 vmov s15, r0 */
/* @0x119c3c vcvt.f64.s32 d7, s15 */
/* @0x119c40 vmov r0, r1, d7 */
/* @0x119c44 vmov r2, s14 */
/* @0x119c48 mov r3, r1 */
/* @0x119c4c stm r4, {r2, r3} */
/* @0x119c50 pop {r4, pc} */

/* ── FUNC 0x119c54 · F_DisplayGetFrequency(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x119c54 push {r4, lr} */
/* @0x119c58 mov r3, #0 */
/* @0x119c5c str r3, [r0, #0xc] */
/* @0x119c60 mov r4, r0 */
/* @0x119c64 bl 0x17db4c <_Z16DisplayFrequencyv> */
/* @0x119c68 vmov s15, r0 */
/* @0x119c6c vcvt.f64.s32 d7, s15 */
/* @0x119c70 vmov r0, r1, d7 */
/* @0x119c74 vmov r2, s14 */
/* @0x119c78 mov r3, r1 */
/* @0x119c7c stm r4, {r2, r3} */
/* @0x119c80 pop {r4, pc} */

/* ── FUNC 0x119c84 · F_DisplayGetOrientation(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x119c84 push {r4, lr} */
/* @0x119c88 mov r3, #0 */
/* @0x119c8c str r3, [r0, #0xc] */
/* @0x119c90 mov r4, r0 */
/* @0x119c94 bl 0x15e288 <GetOrientation> */
/* @0x119c98 vmov s15, r0 */
/* @0x119c9c vcvt.f64.s32 d7, s15 */
/* @0x119ca0 vmov r0, r1, d7 */
/* @0x119ca4 vmov r2, s14 */
/* @0x119ca8 mov r3, r1 */
/* @0x119cac stm r4, {r2, r3} */
/* @0x119cb0 pop {r4, pc} */

/* ── FUNC 0x119cb4 · F_DisplaySetTimingMethod(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x119cb4 push {r3, lr} */
/* @0x119cb8 mov r1, #0 */
/* @0x119cbc ldr r0, [sp, #0x8] */
/* @0x119cc0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x119cc4 cmp r0, #0 */
/* @0x119cc8 beq 0x119ce4 <_Z24F_DisplaySetTimingMethodR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x119ccc cmp r0, #1 */
/* @0x119cd0 ldreq r3, [pc, #0x20] */
/* @0x119cd4 moveq r2, #0 */
/* @0x119cd8 ldreq r3, [pc, r3] */
/* @0x119cdc strbeq r2, [r3] */
/* @0x119ce0 pop {r3, pc} */
/* @0x119ce4 ldr r3, [pc, #0x10] */
/* @0x119ce8 mov r2, #1 */
/* @0x119cec ldr r3, [pc, r3] */
/* @0x119cf0 strb r2, [r3] */
/* @0x119cf4 pop {r3, pc} */
/* @0x119cf8 .word 0x002d48d8 */
/* @0x119cfc eoreq r4, sp, r4, asr #17 */

/* ── FUNC 0x119d00 · F_DisplaySetSleepMargin(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x119d00 push {r3, lr} */
/* @0x119d04 mov r1, #0 */
/* @0x119d08 ldr r0, [sp, #0x8] */
/* @0x119d0c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x119d10 ldr r3, [pc, #0x8] */
/* @0x119d14 ldr r3, [pc, r3] */
/* @0x119d18 str r0, [r3] */
/* @0x119d1c pop {r3, pc} */
/* @0x119d20 eoreq r4, sp, r0, lsr #17 */

/* ── FUNC 0x119d24 · F_MakeColorRGB(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x119d24 push {r4, r5, r6, lr} */
/* @0x119d28 mov r1, #0 */
/* @0x119d2c ldr r4, [sp, #0x10] */
/* @0x119d30 mov r5, r0 */
/* @0x119d34 str r1, [r0, #0xc] */
/* @0x119d38 mov r0, r4 */
/* @0x119d3c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x119d40 mov r1, #1 */
/* @0x119d44 mov r6, r0 */
/* @0x119d48 mov r0, r4 */
/* @0x119d4c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x119d50 mov r1, #2 */
/* @0x119d54 add r6, r6, r0, lsl #8 */
/* @0x119d58 mov r0, r4 */
/* @0x119d5c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x119d60 add r0, r6, r0, lsl #16 */
/* @0x119d64 vmov s15, r0 */
/* @0x119d68 vcvt.f64.s32 d7, s15 */
/* @0x119d6c vmov r2, r3, d7 */
/* @0x119d70 stm r5, {r2, r3} */
/* @0x119d74 pop {r4, r5, r6, pc} */

/* ── FUNC 0x119d78 · F_ColorGetRed(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x119d78 push {r4, lr} */
/* @0x119d7c mov r3, #0 */
/* @0x119d80 mov r4, r0 */
/* @0x119d84 str r3, [r0, #0xc] */
/* @0x119d88 mov r1, r3 */
/* @0x119d8c ldr r0, [sp, #0x8] */
/* @0x119d90 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x119d94 asr r3, r0, #31 */
/* @0x119d98 lsr r3, r3, #24 */
/* @0x119d9c add r2, r0, r3 */
/* @0x119da0 uxtb r2, r2 */
/* @0x119da4 rsb r2, r3, r2 */
/* @0x119da8 vmov s15, r2 */
/* @0x119dac vcvt.f64.s32 d7, s15 */
/* @0x119db0 vmov r2, r3, d7 */
/* @0x119db4 stm r4, {r2, r3} */
/* @0x119db8 pop {r4, pc} */

/* ── FUNC 0x119dbc · F_ColorGetGreen(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x119dbc push {r4, lr} */
/* @0x119dc0 mov r3, #0 */
/* @0x119dc4 mov r4, r0 */
/* @0x119dc8 str r3, [r0, #0xc] */
/* @0x119dcc mov r1, r3 */
/* @0x119dd0 ldr r0, [sp, #0x8] */
/* @0x119dd4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x119dd8 add r3, r0, #255 */
/* @0x119ddc cmp r0, #0 */
/* @0x119de0 movlt r0, r3 */
/* @0x119de4 asr r3, r0, #31 */
/* @0x119de8 lsr r3, r3, #24 */
/* @0x119dec add r0, r3, r0, asr #8 */
/* @0x119df0 uxtb r2, r0 */
/* @0x119df4 rsb r2, r3, r2 */
/* @0x119df8 vmov s15, r2 */
/* @0x119dfc vcvt.f64.s32 d7, s15 */
/* @0x119e00 vmov r2, r3, d7 */
/* @0x119e04 stm r4, {r2, r3} */
/* @0x119e08 pop {r4, pc} */

/* ── FUNC 0x119e0c · F_ColorGetBlue(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x119e0c push {r4, lr} */
/* @0x119e10 mov r3, #0 */
/* @0x119e14 mov r1, r3 */
/* @0x119e18 str r3, [r0, #0xc] */
/* @0x119e1c mov r4, r0 */
/* @0x119e20 ldr r0, [sp, #0x8] */
/* @0x119e24 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x119e28 add r3, r0, #65280 */
/* @0x119e2c cmp r0, #0 */
/* @0x119e30 add r3, r3, #255 */
/* @0x119e34 movlt r0, r3 */
/* @0x119e38 asr r1, r0, #31 */
/* @0x119e3c lsr r1, r1, #24 */
/* @0x119e40 add r0, r1, r0, asr #16 */
/* @0x119e44 uxtb r2, r0 */
/* @0x119e48 rsb r2, r1, r2 */
/* @0x119e4c vmov s15, r2 */
/* @0x119e50 vcvt.f64.s32 d7, s15 */
/* @0x119e54 vmov r2, r3, d7 */
/* @0x119e58 stm r4, {r2, r3} */
/* @0x119e5c pop {r4, pc} */

/* ── FUNC 0x119e60 · F_TileGetID(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x119e60 push {r3, r4, r5, lr} */
/* @0x119e64 mov r4, r0 */
/* @0x119e68 ldr r3, [pc, #0x64] */
/* @0x119e6c mov r1, #0 */
/* @0x119e70 ldr r0, [sp, #0x10] */
/* @0x119e74 ldr r3, [pc, r3] */
/* @0x119e78 str r1, [r4, #0xc] */
/* @0x119e7c ldr r5, [r3] */
/* @0x119e80 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x119e84 cmp r0, #0 */
/* @0x119e88 blt 0x119ec0 <_Z11F_TileGetIDR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x119e8c ldr r3, [r5, #0xb8] */
/* @0x119e90 cmp r0, r3 */
/* @0x119e94 bge 0x119ec0 <_Z11F_TileGetIDR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x119e98 ldr r3, [r5, #0xc0] */
/* @0x119e9c rsb r0, r0, r0, lsl #3 */
/* @0x119ea0 adds r0, r3, r0, lsl #3 */
/* @0x119ea4 beq 0x119ec0 <_Z11F_TileGetIDR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x119ea8 ldr r2, [r0, #0x20] */
/* @0x119eac vmov s15, r2 */
/* @0x119eb0 vcvt.f64.s32 d7, s15 */
/* @0x119eb4 vmov r2, r3, d7 */
/* @0x119eb8 stm r4, {r2, r3} */
/* @0x119ebc pop {r3, r4, r5, pc} */
/* @0x119ec0 mov r3, #0 */
/* @0x119ec4 mov r2, r3 */
/* @0x119ec8 movt r3, #0xbff0 */
/* @0x119ecc stm r4, {r2, r3} */
/* @0x119ed0 pop {r3, r4, r5, pc} */
/* @0x119ed4 .word 0x002d3ab4 */

/* ── FUNC 0x119ed8 · F_DisplaySetSize(RValue&, CInstance*, CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x119ed8 push {r3, r4, r5, r6, r7, lr} */
/* @0x119edc mov r5, #0 */
/* @0x119ee0 ldr r6, [sp, #0x18] */
/* @0x119ee4 mov r4, r0 */
/* @0x119ee8 str r5, [r0, #0xc] */
/* @0x119eec mov r1, r5 */
/* @0x119ef0 mov r0, r6 */
/* @0x119ef4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x119ef8 mov r1, #1 */
/* @0x119efc mov r7, r0 */
/* @0x119f00 mov r0, r6 */
/* @0x119f04 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x119f08 mov r1, r0 */
/* @0x119f0c mov r0, r7 */
/* @0x119f10 bl 0x17db6c <_Z14DisplaySetSizeii> */
/* @0x119f14 cmp r0, #0 */
/* @0x119f18 moveq r5, r0 */
/* @0x119f1c movne r3, r5 */
/* @0x119f20 moveq r3, r5 */
/* @0x119f24 movtne r3, #0x3ff0 */
/* @0x119f28 str r5, [r4] */
/* @0x119f2c str r3, [r4, #0x4] */
/* @0x119f30 pop {r3, r4, r5, r6, r7, lr} */
/* @0x119f34 b 0x168c24 <_Z12GR_D3D_Resetv> */

/* ── FUNC 0x119f38 · F_DisplaySetColordepth(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x119f38 push {r3, r4, r5, lr} */
/* @0x119f3c mov r5, #0 */
/* @0x119f40 ldr r3, [sp, #0x10] */
/* @0x119f44 mov r4, r0 */
/* @0x119f48 str r5, [r0, #0xc] */
/* @0x119f4c mov r1, r5 */
/* @0x119f50 mov r0, r3 */
/* @0x119f54 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x119f58 bl 0x17db8c <_Z20DisplaySetColorDepthi> */
/* @0x119f5c cmp r0, #0 */
/* @0x119f60 moveq r5, r0 */
/* @0x119f64 movne r3, r5 */
/* @0x119f68 moveq r3, r5 */
/* @0x119f6c movtne r3, #0x3ff0 */
/* @0x119f70 str r5, [r4] */
/* @0x119f74 str r3, [r4, #0x4] */
/* @0x119f78 pop {r3, r4, r5, lr} */
/* @0x119f7c b 0x168c24 <_Z12GR_D3D_Resetv> */

/* ── FUNC 0x119f80 · F_DisplaySetFrequency(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x119f80 push {r3, r4, r5, lr} */
/* @0x119f84 mov r5, #0 */
/* @0x119f88 ldr r3, [sp, #0x10] */
/* @0x119f8c mov r4, r0 */
/* @0x119f90 str r5, [r0, #0xc] */
/* @0x119f94 mov r1, r5 */
/* @0x119f98 mov r0, r3 */
/* @0x119f9c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x119fa0 bl 0x17db78 <_Z19DisplaySetFrequencyi> */
/* @0x119fa4 cmp r0, #0 */
/* @0x119fa8 moveq r5, r0 */
/* @0x119fac movne r3, r5 */
/* @0x119fb0 moveq r3, r5 */
/* @0x119fb4 movtne r3, #0x3ff0 */
/* @0x119fb8 str r5, [r4] */
/* @0x119fbc str r3, [r4, #0x4] */
/* @0x119fc0 pop {r3, r4, r5, lr} */
/* @0x119fc4 b 0x168c24 <_Z12GR_D3D_Resetv> */

/* ── FUNC 0x119fc8 · F_DisplaySetAll(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x119fc8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x119fcc mov r6, #0 */
/* @0x119fd0 ldr r4, [sp, #0x20] */
/* @0x119fd4 mov r5, r0 */
/* @0x119fd8 str r6, [r0, #0xc] */
/* @0x119fdc mov r1, r6 */
/* @0x119fe0 mov r0, r4 */
/* @0x119fe4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x119fe8 mov r1, #1 */
/* @0x119fec mov r9, r0 */
/* @0x119ff0 mov r0, r4 */
/* @0x119ff4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x119ff8 mov r1, #2 */
/* @0x119ffc mov r8, r0 */
/* @0x11a000 mov r0, r4 */
/* @0x11a004 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a008 mov r1, #3 */
/* @0x11a00c mov r7, r0 */
/* @0x11a010 mov r0, r4 */
/* @0x11a014 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a018 mov r1, r8 */
/* @0x11a01c mov r2, r7 */
/* @0x11a020 mov r3, r0 */
/* @0x11a024 mov r0, r9 */
/* @0x11a028 bl 0x17db64 <_Z10DisplaySetiiii> */
/* @0x11a02c cmp r0, #0 */
/* @0x11a030 moveq r6, r0 */
/* @0x11a034 movne r3, r6 */
/* @0x11a038 moveq r3, r6 */
/* @0x11a03c movtne r3, #0x3ff0 */
/* @0x11a040 str r6, [r5] */
/* @0x11a044 str r3, [r5, #0x4] */
/* @0x11a048 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x11a04c b 0x168c24 <_Z12GR_D3D_Resetv> */

/* ── FUNC 0x11a050 · F_DisplayTestAll(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x11a050 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x11a054 mov r6, #0 */
/* @0x11a058 ldr r4, [sp, #0x20] */
/* @0x11a05c mov r5, r0 */
/* @0x11a060 str r6, [r0, #0xc] */
/* @0x11a064 mov r1, r6 */
/* @0x11a068 mov r0, r4 */
/* @0x11a06c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a070 mov r1, #1 */
/* @0x11a074 mov r9, r0 */
/* @0x11a078 mov r0, r4 */
/* @0x11a07c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a080 mov r1, #2 */
/* @0x11a084 mov r8, r0 */
/* @0x11a088 mov r0, r4 */
/* @0x11a08c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a090 mov r1, #3 */
/* @0x11a094 mov r7, r0 */
/* @0x11a098 mov r0, r4 */
/* @0x11a09c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a0a0 mov r1, r8 */
/* @0x11a0a4 mov r2, r7 */
/* @0x11a0a8 mov r3, r0 */
/* @0x11a0ac mov r0, r9 */
/* @0x11a0b0 bl 0x17db5c <_Z11DisplayTestiiii> */
/* @0x11a0b4 cmp r0, #0 */
/* @0x11a0b8 moveq r6, r0 */
/* @0x11a0bc movne r3, r6 */
/* @0x11a0c0 moveq r3, r6 */
/* @0x11a0c4 movtne r3, #0x3ff0 */
/* @0x11a0c8 str r6, [r5] */
/* @0x11a0cc str r3, [r5, #0x4] */
/* @0x11a0d0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x11a0d4 · F_DrawEnableDrawEvent(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x11a0d4 push {r3, lr} */
/* @0x11a0d8 mov r1, #0 */
/* @0x11a0dc ldr r0, [sp, #0x8] */
/* @0x11a0e0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11a0e4 ldr r3, [pc, #0x8] */
/* @0x11a0e8 ldr r3, [pc, r3] */
/* @0x11a0ec strb r0, [r3] */
/* @0x11a0f0 pop {r3, pc} */
/* @0x11a0f4 .word 0x002d44dc */

/* ── FUNC 0x11a0f8 · F_DrawEnableSWFAA(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x11a0f8 push {r3, lr} */
/* @0x11a0fc mov r1, #0 */
/* @0x11a100 ldr r0, [sp, #0x8] */
/* @0x11a104 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11a108 ldr r3, [pc, #0x8] */
/* @0x11a10c ldr r3, [pc, r3] */
/* @0x11a110 strb r0, [r3] */
/* @0x11a114 pop {r3, pc} */
/* @0x11a118 .word 0x002d44bc */

/* ── FUNC 0x11a11c · F_SurfaceDepthDisable(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x11a11c push {r3, lr} */
/* @0x11a120 mov r1, #0 */
/* @0x11a124 ldr r0, [sp, #0x8] */
/* @0x11a128 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11a12c cmp r0, #0 */
/* @0x11a130 bne 0x11a148 <_Z21F_SurfaceDepthDisableR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x11a134 ldr r3, [pc, #0x20] */
/* @0x11a138 mov r2, #1 */
/* @0x11a13c ldr r3, [pc, r3] */
/* @0x11a140 strb r2, [r3] */
/* @0x11a144 pop {r3, pc} */
/* @0x11a148 ldr r3, [pc, #0x10] */
/* @0x11a14c mov r2, #0 */
/* @0x11a150 ldr r3, [pc, r3] */
/* @0x11a154 strb r2, [r3] */
/* @0x11a158 pop {r3, pc} */
/* @0x11a15c eoreq r4, sp, r4, lsl #9 */
/* @0x11a160 eoreq r4, sp, r0, ror r4 */

/* ── FUNC 0x11a164 · F_DrawEnableCornerID(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x11a164 push {r3, lr} */
/* @0x11a168 mov r1, #0 */
/* @0x11a16c ldr r0, [sp, #0x8] */
/* @0x11a170 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11a174 ldr r3, [pc, #0x8] */
/* @0x11a178 ldr r3, [pc, r3] */
/* @0x11a17c strb r0, [r3] */
/* @0x11a180 pop {r3, pc} */
/* @0x11a184 .word 0x002d3cd4 */

/* ── FUNC 0x11a188 · F_DisplayReset(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x11a188 push {r4, lr} */
/* @0x11a18c mov r1, #0 */
/* @0x11a190 ldr r4, [sp, #0x8] */
/* @0x11a194 mov r0, r4 */
/* @0x11a198 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a19c uxtb r0, r0 */
/* @0x11a1a0 bl 0x17db20 <_ZN8Graphics14SetMultiSampleEi> */
/* @0x11a1a4 mov r1, #1 */
/* @0x11a1a8 mov r0, r4 */
/* @0x11a1ac bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11a1b0 bl 0x17db0c <_ZN8Graphics8SetVSyncEb> */
/* @0x11a1b4 ldr r3, [pc, #0xc] */
/* @0x11a1b8 mov r2, #1 */
/* @0x11a1bc ldr r3, [pc, r3] */
/* @0x11a1c0 str r2, [r3] */
/* @0x11a1c4 pop {r4, pc} */
/* @0x11a1c8 eoreq r4, sp, r0, lsl r4 */

/* ── FUNC 0x11a1cc · F_DisplayMouseGetX(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x11a1cc push {r4, lr} */
/* @0x11a1d0 mov r3, #0 */
/* @0x11a1d4 str r3, [r0, #0xc] */
/* @0x11a1d8 mov r4, r0 */
/* @0x11a1dc bl 0x17dba4 <_Z16DisplayGetMouseXv> */
/* @0x11a1e0 vmov s15, r0 */
/* @0x11a1e4 vcvt.f64.s32 d7, s15 */
/* @0x11a1e8 vmov r0, r1, d7 */
/* @0x11a1ec vmov r2, s14 */
/* @0x11a1f0 mov r3, r1 */
/* @0x11a1f4 stm r4, {r2, r3} */
/* @0x11a1f8 pop {r4, pc} */

/* ── FUNC 0x11a1fc · F_DisplayMouseGetY(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x11a1fc push {r4, lr} */
/* @0x11a200 mov r3, #0 */
/* @0x11a204 str r3, [r0, #0xc] */
/* @0x11a208 mov r4, r0 */
/* @0x11a20c bl 0x17dbac <_Z16DisplayGetMouseYv> */
/* @0x11a210 vmov s15, r0 */
/* @0x11a214 vcvt.f64.s32 d7, s15 */
/* @0x11a218 vmov r0, r1, d7 */
/* @0x11a21c vmov r2, s14 */
/* @0x11a220 mov r3, r1 */
/* @0x11a224 stm r4, {r2, r3} */
/* @0x11a228 pop {r4, pc} */
