/* libyoyo.so 覆盖卡组 0107
 * 函数 0x16c2c0..0x16d134，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x16c2c0 · INITIALIZE_Graphics_Draw() · size=8 · insn=2 */
/* @0x16c2c0 mov r0, #24 */
/* @0x16c2c4 b 0x16ae64 <_Z24GR_Draw_Circle_Precisioni> */

/* ── FUNC 0x16c2c8 · anon_16c2c8 · size=48 · insn=12 */
/* @0x16c2c8 bx lr */
/* @0x16c2cc push {r4, r5, r6, lr} */
/* @0x16c2d0 mov r5, r1 */
/* @0x16c2d4 mov r4, r2 */
/* @0x16c2d8 blx 0x2a5f20 <png_get_io_ptr> */
/* @0x16c2dc subs r3, r0, #0 */
/* @0x16c2e0 popeq {r4, r5, r6, pc} */
/* @0x16c2e4 mov r0, r5 */
/* @0x16c2e8 mov r2, r4 */
/* @0x16c2ec mov r1, #1 */
/* @0x16c2f0 pop {r4, r5, r6, lr} */
/* @0x16c2f4 b 0x18e2b0 <_ZN8LoadSave6fwriteEPKvjjP7_YYFILE> */

/* ── FUNC 0x16c2f8 · F_ViewGetVisible(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x16c2f8 push {r3, r4, r5, lr} */
/* @0x16c2fc mov r4, r0 */
/* @0x16c300 mov r5, r1 */
/* @0x16c304 ldr r0, [sp, #0x10] */
/* @0x16c308 mov r1, #0 */
/* @0x16c30c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16c310 mov r2, r4 */
/* @0x16c314 mov r1, r0 */
/* @0x16c318 mov r0, r5 */
/* @0x16c31c pop {r3, r4, r5, lr} */
/* @0x16c320 b 0x1f81b4 <_Z14GV_ViewVisibleP9CInstanceiP6RValue> */

/* ── FUNC 0x16c324 · F_ViewGetXport(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x16c324 push {r3, r4, r5, lr} */
/* @0x16c328 mov r4, r0 */
/* @0x16c32c mov r5, r1 */
/* @0x16c330 ldr r0, [sp, #0x10] */
/* @0x16c334 mov r1, #0 */
/* @0x16c338 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16c33c mov r2, r4 */
/* @0x16c340 mov r1, r0 */
/* @0x16c344 mov r0, r5 */
/* @0x16c348 pop {r3, r4, r5, lr} */
/* @0x16c34c b 0x1f8348 <_Z12GV_ViewXportP9CInstanceiP6RValue> */

/* ── FUNC 0x16c350 · F_ViewGetYport(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x16c350 push {r3, r4, r5, lr} */
/* @0x16c354 mov r4, r0 */
/* @0x16c358 mov r5, r1 */
/* @0x16c35c ldr r0, [sp, #0x10] */
/* @0x16c360 mov r1, #0 */
/* @0x16c364 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16c368 mov r2, r4 */
/* @0x16c36c mov r1, r0 */
/* @0x16c370 mov r0, r5 */
/* @0x16c374 pop {r3, r4, r5, lr} */
/* @0x16c378 b 0x1f839c <_Z12GV_ViewYportP9CInstanceiP6RValue> */

/* ── FUNC 0x16c37c · F_ViewGetWport(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x16c37c push {r3, r4, r5, lr} */
/* @0x16c380 mov r4, r0 */
/* @0x16c384 mov r5, r1 */
/* @0x16c388 ldr r0, [sp, #0x10] */
/* @0x16c38c mov r1, #0 */
/* @0x16c390 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16c394 mov r2, r4 */
/* @0x16c398 mov r1, r0 */
/* @0x16c39c mov r0, r5 */
/* @0x16c3a0 pop {r3, r4, r5, lr} */
/* @0x16c3a4 b 0x1f83f0 <_Z12GV_ViewWportP9CInstanceiP6RValue> */

/* ── FUNC 0x16c3a8 · F_ViewGetHport(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x16c3a8 push {r3, r4, r5, lr} */
/* @0x16c3ac mov r4, r0 */
/* @0x16c3b0 mov r5, r1 */
/* @0x16c3b4 ldr r0, [sp, #0x10] */
/* @0x16c3b8 mov r1, #0 */
/* @0x16c3bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16c3c0 mov r2, r4 */
/* @0x16c3c4 mov r1, r0 */
/* @0x16c3c8 mov r0, r5 */
/* @0x16c3cc pop {r3, r4, r5, lr} */
/* @0x16c3d0 b 0x1f8444 <_Z12GV_ViewHportP9CInstanceiP6RValue> */

/* ── FUNC 0x16c3d4 · F_ViewGetSurfaceId(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x16c3d4 push {r3, r4, r5, lr} */
/* @0x16c3d8 mov r4, r0 */
/* @0x16c3dc mov r5, r1 */
/* @0x16c3e0 ldr r0, [sp, #0x10] */
/* @0x16c3e4 mov r1, #0 */
/* @0x16c3e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16c3ec mov r2, r4 */
/* @0x16c3f0 mov r1, r0 */
/* @0x16c3f4 mov r0, r5 */
/* @0x16c3f8 pop {r3, r4, r5, lr} */
/* @0x16c3fc b 0x1f8b18 <_Z16GV_ViewSurfaceIDP9CInstanceiP6RValue> */

/* ── FUNC 0x16c400 · F_ViewGetCamera(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x16c400 push {r3, r4, r5, lr} */
/* @0x16c404 mov r4, r0 */
/* @0x16c408 mov r5, r1 */
/* @0x16c40c ldr r0, [sp, #0x10] */
/* @0x16c410 mov r1, #0 */
/* @0x16c414 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16c418 mov r2, r4 */
/* @0x16c41c mov r1, r0 */
/* @0x16c420 mov r0, r5 */
/* @0x16c424 pop {r3, r4, r5, lr} */
/* @0x16c428 b 0x1f8b6c <_Z13GV_ViewCameraP9CInstanceiP6RValue> */

/* ── FUNC 0x16c42c · F_ViewSetVisible(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x16c42c push {r4, r5, r6, r7, lr} */
/* @0x16c430 sub sp, sp, #20 */
/* @0x16c434 mov r7, r1 */
/* @0x16c438 mov r1, #1 */
/* @0x16c43c ldr r5, [sp, #0x28] */
/* @0x16c440 mov r6, #0 */
/* @0x16c444 str r6, [sp, #0xc] */
/* @0x16c448 add r4, sp, #16 */
/* @0x16c44c mov r0, r5 */
/* @0x16c450 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x16c454 strd r0, r1, [r4, #-16]! */
/* @0x16c458 mov r1, r6 */
/* @0x16c45c mov r0, r5 */
/* @0x16c460 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16c464 mov r2, sp */
/* @0x16c468 mov r1, r0 */
/* @0x16c46c mov r0, r7 */
/* @0x16c470 bl 0x1fc1f4 <_Z14SV_ViewVisibleP9CInstanceiP6RValue> */
/* @0x16c474 add sp, sp, #20 */
/* @0x16c478 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x16c47c · F_ViewSetXport(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x16c47c push {r4, r5, r6, r7, lr} */
/* @0x16c480 sub sp, sp, #20 */
/* @0x16c484 mov r7, r1 */
/* @0x16c488 mov r1, #1 */
/* @0x16c48c ldr r5, [sp, #0x28] */
/* @0x16c490 mov r6, #0 */
/* @0x16c494 str r6, [sp, #0xc] */
/* @0x16c498 add r4, sp, #16 */
/* @0x16c49c mov r0, r5 */
/* @0x16c4a0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x16c4a4 strd r0, r1, [r4, #-16]! */
/* @0x16c4a8 mov r1, r6 */
/* @0x16c4ac mov r0, r5 */
/* @0x16c4b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16c4b4 mov r2, sp */
/* @0x16c4b8 mov r1, r0 */
/* @0x16c4bc mov r0, r7 */
/* @0x16c4c0 bl 0x1fc3d8 <_Z12SV_ViewXportP9CInstanceiP6RValue> */
/* @0x16c4c4 add sp, sp, #20 */
/* @0x16c4c8 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x16c4cc · F_ViewSetYport(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x16c4cc push {r4, r5, r6, r7, lr} */
/* @0x16c4d0 sub sp, sp, #20 */
/* @0x16c4d4 mov r7, r1 */
/* @0x16c4d8 mov r1, #1 */
/* @0x16c4dc ldr r5, [sp, #0x28] */
/* @0x16c4e0 mov r6, #0 */
/* @0x16c4e4 str r6, [sp, #0xc] */
/* @0x16c4e8 add r4, sp, #16 */
/* @0x16c4ec mov r0, r5 */
/* @0x16c4f0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x16c4f4 strd r0, r1, [r4, #-16]! */
/* @0x16c4f8 mov r1, r6 */
/* @0x16c4fc mov r0, r5 */
/* @0x16c500 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16c504 mov r2, sp */
/* @0x16c508 mov r1, r0 */
/* @0x16c50c mov r0, r7 */
/* @0x16c510 bl 0x1fc440 <_Z12SV_ViewYportP9CInstanceiP6RValue> */
/* @0x16c514 add sp, sp, #20 */
/* @0x16c518 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x16c51c · F_ViewSetWport(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x16c51c push {r4, r5, r6, r7, lr} */
/* @0x16c520 sub sp, sp, #20 */
/* @0x16c524 mov r7, r1 */
/* @0x16c528 mov r1, #1 */
/* @0x16c52c ldr r5, [sp, #0x28] */
/* @0x16c530 mov r6, #0 */
/* @0x16c534 str r6, [sp, #0xc] */
/* @0x16c538 add r4, sp, #16 */
/* @0x16c53c mov r0, r5 */
/* @0x16c540 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x16c544 strd r0, r1, [r4, #-16]! */
/* @0x16c548 mov r1, r6 */
/* @0x16c54c mov r0, r5 */
/* @0x16c550 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16c554 mov r2, sp */
/* @0x16c558 mov r1, r0 */
/* @0x16c55c mov r0, r7 */
/* @0x16c560 bl 0x1fc4a8 <_Z12SV_ViewWportP9CInstanceiP6RValue> */
/* @0x16c564 add sp, sp, #20 */
/* @0x16c568 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x16c56c · F_ViewSetHport(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x16c56c push {r4, r5, r6, r7, lr} */
/* @0x16c570 sub sp, sp, #20 */
/* @0x16c574 mov r7, r1 */
/* @0x16c578 mov r1, #1 */
/* @0x16c57c ldr r5, [sp, #0x28] */
/* @0x16c580 mov r6, #0 */
/* @0x16c584 str r6, [sp, #0xc] */
/* @0x16c588 add r4, sp, #16 */
/* @0x16c58c mov r0, r5 */
/* @0x16c590 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x16c594 strd r0, r1, [r4, #-16]! */
/* @0x16c598 mov r1, r6 */
/* @0x16c59c mov r0, r5 */
/* @0x16c5a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16c5a4 mov r2, sp */
/* @0x16c5a8 mov r1, r0 */
/* @0x16c5ac mov r0, r7 */
/* @0x16c5b0 bl 0x1fc510 <_Z12SV_ViewHportP9CInstanceiP6RValue> */
/* @0x16c5b4 add sp, sp, #20 */
/* @0x16c5b8 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x16c5bc · F_ViewSetSurfaceId(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x16c5bc push {r4, r5, r6, r7, lr} */
/* @0x16c5c0 sub sp, sp, #20 */
/* @0x16c5c4 mov r7, r1 */
/* @0x16c5c8 mov r1, #1 */
/* @0x16c5cc ldr r5, [sp, #0x28] */
/* @0x16c5d0 mov r6, #0 */
/* @0x16c5d4 str r6, [sp, #0xc] */
/* @0x16c5d8 add r4, sp, #16 */
/* @0x16c5dc mov r0, r5 */
/* @0x16c5e0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x16c5e4 strd r0, r1, [r4, #-16]! */
/* @0x16c5e8 mov r1, r6 */
/* @0x16c5ec mov r0, r5 */
/* @0x16c5f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16c5f4 mov r2, sp */
/* @0x16c5f8 mov r1, r0 */
/* @0x16c5fc mov r0, r7 */
/* @0x16c600 bl 0x1fc7d8 <_Z16SV_ViewSurfaceIDP9CInstanceiP6RValue> */
/* @0x16c604 add sp, sp, #20 */
/* @0x16c608 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x16c60c · F_ViewSetCamera(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x16c60c push {r4, r5, r6, r7, lr} */
/* @0x16c610 sub sp, sp, #20 */
/* @0x16c614 mov r7, r1 */
/* @0x16c618 mov r1, #1 */
/* @0x16c61c ldr r5, [sp, #0x28] */
/* @0x16c620 mov r6, #0 */
/* @0x16c624 str r6, [sp, #0xc] */
/* @0x16c628 add r4, sp, #16 */
/* @0x16c62c mov r0, r5 */
/* @0x16c630 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x16c634 strd r0, r1, [r4, #-16]! */
/* @0x16c638 mov r1, r6 */
/* @0x16c63c mov r0, r5 */
/* @0x16c640 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16c644 mov r2, sp */
/* @0x16c648 mov r1, r0 */
/* @0x16c64c mov r0, r7 */
/* @0x16c650 bl 0x1fc840 <_Z13SV_ViewCameraP9CInstanceiP6RValue> */
/* @0x16c654 add sp, sp, #20 */
/* @0x16c658 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x16c65c · yyMatrix::Invert() · size=976 · insn=244 */
/* @0x16c65c vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x16c660 vldr s9, [r0, #44] */
/* @0x16c664 vldr s7, [r0, #20] */
/* @0x16c668 vldr s22, [r0, #16] */
/* @0x16c66c vmul.f32 s15, s7, s9 */
/* @0x16c670 vldr s14, [r0, #56] */
/* @0x16c674 vldr s12, [r0, #40] */
/* @0x16c678 vldr s13, [r0, #60] */
/* @0x16c67c vldr s11, [r0, #36] */
/* @0x16c680 vldr s10, [r0, #52] */
/* @0x16c684 vldr s8, [r0, #24] */
/* @0x16c688 vldr s0, [r0, #32] */
/* @0x16c68c vldr s17, [r0, #48] */
/* @0x16c690 vldr s6, [r0, #28] */
/* @0x16c694 vldr s16, [r0, #32] */
/* @0x16c698 sub sp, sp, #96 */
/* @0x16c69c vldr s20, [r0, #4] */
/* @0x16c6a0 vldr s25, [r0] */
/* @0x16c6a4 vmul.f32 s3, s9, s22 */
/* @0x16c6a8 vneg.f32 s4, s22 */
/* @0x16c6ac vmul.f32 s5, s14, s3 */
/* @0x16c6b0 vmul.f32 s1, s12, s4 */
/* @0x16c6b4 vmul.f32 s15, s15, s14 */
/* @0x16c6b8 vmul.f32 s2, s7, s12 */
/* @0x16c6bc vmla.f32 s5, s13, s1 */
/* @0x16c6c0 vnmls.f32 s15, s2, s13 */
/* @0x16c6c4 vmul.f32 s2, s12, s22 */
/* @0x16c6c8 vmul.f32 s23, s8, s0 */
/* @0x16c6cc vmul.f32 s21, s10, s3 */
/* @0x16c6d0 vmul.f32 s0, s11, s8 */
/* @0x16c6d4 vmul.f32 s3, s11, s22 */
/* @0x16c6d8 vmul.f32 s31, s10, s2 */
/* @0x16c6dc vmul.f32 s4, s11, s4 */
/* @0x16c6e0 vmla.f32 s5, s13, s23 */
/* @0x16c6e4 vmls.f32 s15, s13, s0 */
/* @0x16c6e8 vnmls.f32 s21, s13, s3 */
/* @0x16c6ec vmul.f32 s17, s8, s17 */
/* @0x16c6f0 vmul.f32 s1, s6, s16 */
/* @0x16c6f4 vstr s17, [sp, #28] */
/* @0x16c6f8 vldr s27, [sp, #28] */
/* @0x16c6fc vmul.f32 s0, s7, s16 */
/* @0x16c700 vmul.f32 s3, s11, s6 */
/* @0x16c704 vmla.f32 s31, s14, s4 */
/* @0x16c708 vmul.f32 s17, s6, s20 */
/* @0x16c70c vmul.f32 s18, s9, s20 */
/* @0x16c710 vmul.f32 s26, s12, s25 */
/* @0x16c714 vmls.f32 s5, s14, s1 */
/* @0x16c718 vstr s26, [sp, #4] */
/* @0x16c71c vldr s26, [r0] */
/* @0x16c720 vmla.f32 s15, s14, s3 */
/* @0x16c724 vmls.f32 s21, s13, s0 */
/* @0x16c728 vmul.f32 s4, s6, s25 */
/* @0x16c72c vmul.f32 s24, s8, s25 */
/* @0x16c730 vmul.f32 s19, s9, s25 */
/* @0x16c734 vneg.f32 s25, s25 */
/* @0x16c738 vmul.f32 s16, s8, s10 */
/* @0x16c73c vmul.f32 s29, s14, s18 */
/* @0x16c740 vmul.f32 s28, s14, s17 */
/* @0x16c744 vmul.f32 s18, s11, s25 */
/* @0x16c748 vmla.f32 s31, s14, s0 */
/* @0x16c74c vstr s18, [sp, #8] */
/* @0x16c750 vmul.f32 s0, s8, s25 */
/* @0x16c754 vmul.f32 s30, s12, s17 */
/* @0x16c758 vstr s0, [sp, #20] */
/* @0x16c75c vmul.f32 s17, s8, s20 */
/* @0x16c760 vmul.f32 s26, s11, s26 */
/* @0x16c764 vstr s17, [sp, #16] */
/* @0x16c768 vneg.f32 s3, s20 */
/* @0x16c76c vstr s26, [sp, #12] */
/* @0x16c770 vmls.f32 s5, s9, s27 */
/* @0x16c774 vldr s27, [sp, #4] */
/* @0x16c778 vmul.f32 s2, s12, s3 */
/* @0x16c77c vmul.f32 s17, s10, s19 */
/* @0x16c780 vmla.f32 s15, s9, s16 */
/* @0x16c784 vmla.f32 s21, s10, s1 */
/* @0x16c788 vldr s1, [r0] */
/* @0x16c78c vmul.f32 s16, s10, s27 */
/* @0x16c790 vldr s27, [sp, #16] */
/* @0x16c794 vmul.f32 s26, s7, s1 */
/* @0x16c798 vmul.f32 s18, s14, s4 */
/* @0x16c79c vmul.f32 s0, s10, s4 */
/* @0x16c7a0 vmul.f32 s3, s8, s3 */
/* @0x16c7a4 vmul.f32 s19, s14, s19 */
/* @0x16c7a8 vmul.f32 s1, s11, s24 */
/* @0x16c7ac vmul.f32 s25, s7, s25 */
/* @0x16c7b0 vmla.f32 s29, s13, s2 */
/* @0x16c7b4 vmla.f32 s30, s9, s3 */
/* @0x16c7b8 vmul.f32 s2, s10, s24 */
/* @0x16c7bc vnmls.f32 s28, s13, s27 */
/* @0x16c7c0 vldr s27, [sp, #8] */
/* @0x16c7c4 vnmls.f32 s0, s13, s26 */
/* @0x16c7c8 vmla.f32 s17, s13, s27 */
/* @0x16c7cc vldr s27, [sp, #4] */
/* @0x16c7d0 vmul.f32 s3, s11, s4 */
/* @0x16c7d4 vnmls.f32 s19, s13, s27 */
/* @0x16c7d8 vldr s27, [sp, #12] */
/* @0x16c7dc vnmls.f32 s1, s12, s26 */
/* @0x16c7e0 vldr s26, [r0, #48] */
/* @0x16c7e4 vnmls.f32 s16, s14, s27 */
/* @0x16c7e8 vldr s27, [sp, #20] */
/* @0x16c7ec vmul.f32 s26, s6, s26 */
/* @0x16c7f0 vmla.f32 s18, s13, s27 */
/* @0x16c7f4 vldr s27, [r0, #48] */
/* @0x16c7f8 vstr s26, [sp, #8] */
/* @0x16c7fc vmul.f32 s27, s7, s27 */
/* @0x16c800 vmul.f32 s4, s12, s4 */
/* @0x16c804 vstr s27, [sp, #12] */
/* @0x16c808 vldr s27, [r0, #32] */
/* @0x16c80c vmla.f32 s2, s14, s25 */
/* @0x16c810 vmla.f32 s3, s9, s25 */
/* @0x16c814 vldr s25, [r0, #8] */
/* @0x16c818 vnmls.f32 s4, s9, s24 */
/* @0x16c81c vmla.f32 s5, s12, s26 */
/* @0x16c820 vldr s26, [r0, #8] */
/* @0x16c824 vmul.f32 s24, s6, s10 */
/* @0x16c828 vstr s5, [sp, #48] */
/* @0x16c82c vmul.f32 s25, s11, s25 */
/* @0x16c830 vmul.f32 s26, s7, s26 */
/* @0x16c834 vstr s25, [sp, #16] */
/* @0x16c838 vldr s25, [r0, #8] */
/* @0x16c83c vmls.f32 s31, s10, s23 */
/* @0x16c840 vstr s26, [sp, #20] */
/* @0x16c844 vldr s23, [sp, #12] */
/* @0x16c848 vmls.f32 s15, s12, s24 */
/* @0x16c84c vmul.f32 s24, s27, s25 */
/* @0x16c850 vstr s15, [sp, #32] */
/* @0x16c854 vmul.f32 s25, s27, s20 */
/* @0x16c858 vldr s27, [r0, #8] */
/* @0x16c85c vmul.f32 s26, s22, s27 */
/* @0x16c860 vmul.f32 s27, s22, s20 */
/* @0x16c864 vmla.f32 s21, s9, s23 */
/* @0x16c868 vldr s23, [sp, #16] */
/* @0x16c86c vmla.f32 s18, s13, s26 */
/* @0x16c870 vmla.f32 s29, s13, s23 */
/* @0x16c874 vldr s23, [sp, #20] */
/* @0x16c878 vmls.f32 s0, s13, s27 */
/* @0x16c87c vmla.f32 s30, s9, s23 */
/* @0x16c880 vmls.f32 s28, s13, s23 */
/* @0x16c884 vmla.f32 s2, s14, s27 */
/* @0x16c888 vmla.f32 s3, s9, s27 */
/* @0x16c88c vmls.f32 s4, s9, s26 */
/* @0x16c890 vmls.f32 s19, s13, s24 */
/* @0x16c894 vmla.f32 s17, s13, s25 */
/* @0x16c898 vldr s13, [r0, #12] */
/* @0x16c89c vmls.f32 s16, s14, s25 */
/* @0x16c8a0 vmls.f32 s1, s12, s27 */
/* @0x16c8a4 vldr s27, [r0, #32] */
/* @0x16c8a8 vmul.f32 s5, s5, s20 */
/* @0x16c8ac vmul.f32 s23, s27, s13 */
/* @0x16c8b0 vldr s27, [sp, #12] */
/* @0x16c8b4 vmls.f32 s31, s12, s27 */
/* @0x16c8b8 vldr s27, [r0, #12] */
/* @0x16c8bc vmul.f32 s27, s11, s27 */
/* @0x16c8c0 vmul.f32 s22, s22, s13 */
/* @0x16c8c4 vstr s27, [sp, #12] */
/* @0x16c8c8 vldr s27, [sp, #8] */
/* @0x16c8cc vmul.f32 s13, s7, s13 */
/* @0x16c8d0 vmls.f32 s21, s11, s27 */
/* @0x16c8d4 vldr s27, [r0] */
/* @0x16c8d8 vmla.f32 s5, s15, s27 */
/* @0x16c8dc vldr s27, [sp, #16] */
/* @0x16c8e0 vstr s21, [sp, #64] */
/* @0x16c8e4 vmla.f32 s28, s14, s13 */
/* @0x16c8e8 vmls.f32 s18, s14, s22 */
/* @0x16c8ec vmla.f32 s0, s10, s22 */
/* @0x16c8f0 vmls.f32 s2, s10, s26 */
/* @0x16c8f4 vmls.f32 s30, s12, s13 */
/* @0x16c8f8 vldr s13, [sp, #12] */
/* @0x16c8fc vmla.f32 s19, s14, s23 */
/* @0x16c900 vmls.f32 s29, s14, s13 */
/* @0x16c904 vldr s14, [r0, #48] */
/* @0x16c908 vmls.f32 s17, s10, s23 */
/* @0x16c90c vmla.f32 s16, s10, s24 */
/* @0x16c910 vmla.f32 s1, s11, s26 */
/* @0x16c914 vldr s26, [sp, #28] */
/* @0x16c918 vmls.f32 s3, s11, s22 */
/* @0x16c91c vmla.f32 s4, s12, s22 */
/* @0x16c920 vldr s22, [r0, #8] */
/* @0x16c924 vmul.f32 s20, s14, s20 */
/* @0x16c928 vmul.f32 s13, s10, s22 */
/* @0x16c92c vmul.f32 s14, s14, s22 */
/* @0x16c930 vmla.f32 s31, s11, s26 */
/* @0x16c934 vmla.f32 s5, s21, s22 */
/* @0x16c938 vldr s21, [sp, #12] */
/* @0x16c93c vstr s31, [sp, #80] */
/* @0x16c940 vmls.f32 s29, s9, s13 */
/* @0x16c944 vmla.f32 s28, s6, s13 */
/* @0x16c948 vmls.f32 s30, s6, s27 */
/* @0x16c94c vmla.f32 s19, s9, s14 */
/* @0x16c950 vmls.f32 s18, s6, s14 */
/* @0x16c954 vmls.f32 s17, s9, s20 */
/* @0x16c958 vldr s9, [r0, #48] */
/* @0x16c95c vmla.f32 s0, s6, s20 */
/* @0x16c960 vmls.f32 s3, s6, s25 */
/* @0x16c964 vmla.f32 s4, s6, s24 */
/* @0x16c968 vldr s6, [r0, #12] */
/* @0x16c96c vmla.f32 s16, s12, s20 */
/* @0x16c970 vmla.f32 s1, s8, s25 */
/* @0x16c974 vmls.f32 s2, s8, s20 */
/* @0x16c978 vmul.f32 s13, s9, s6 */
/* @0x16c97c vmul.f32 s10, s10, s6 */
/* @0x16c980 vmla.f32 s5, s31, s6 */
/* @0x16c984 vmla.f32 s30, s8, s21 */
/* @0x16c988 vmla.f32 s29, s12, s10 */
/* @0x16c98c vstr s30, [sp, #44] */
/* @0x16c990 vmls.f32 s28, s8, s10 */
/* @0x16c994 vstr s29, [sp, #36] */
/* @0x16c998 vmls.f32 s19, s12, s13 */
/* @0x16c99c vstr s28, [sp, #40] */
/* @0x16c9a0 vmla.f32 s18, s8, s13 */
/* @0x16c9a4 vstr s19, [sp, #52] */
/* @0x16c9a8 vmla.f32 s17, s11, s13 */
/* @0x16c9ac vstr s18, [sp, #56] */
/* @0x16c9b0 vmls.f32 s16, s11, s14 */
/* @0x16c9b4 vstr s17, [sp, #68] */
/* @0x16c9b8 vmls.f32 s0, s7, s13 */
/* @0x16c9bc vstr s16, [sp, #84] */
/* @0x16c9c0 vmls.f32 s1, s7, s24 */
/* @0x16c9c4 vstr s0, [sp, #72] */
/* @0x16c9c8 vmla.f32 s2, s7, s14 */
/* @0x16c9cc vstr s1, [sp, #92] */
/* @0x16c9d0 vmla.f32 s3, s7, s23 */
/* @0x16c9d4 vstr s2, [sp, #88] */
/* @0x16c9d8 vmls.f32 s4, s8, s23 */
/* @0x16c9dc vstr s3, [sp, #76] */
/* @0x16c9e0 vcmp.f32 s5, #0 */
/* @0x16c9e4 vstr s4, [sp, #60] */
/* @0x16c9e8 vmrs APSR_nzcv, fpscr */
/* @0x16c9ec moveq r0, #0 */
/* @0x16c9f0 beq 0x16ca20 <_ZN8yyMatrix6InvertEv+0x3c4> */
/* @0x16c9f4 vmov.f32 s14, #1.000000e+00 */
/* @0x16c9f8 add r3, sp, #36 */
/* @0x16c9fc add r2, sp, #96 */
/* @0x16ca00 vdiv.f32 s5, s14, s5 */
/* @0x16ca04 b 0x16ca0c <_ZN8yyMatrix6InvertEv+0x3b0> */
/* @0x16ca08 vldmia r3!, {s15} */
/* @0x16ca0c vmul.f32 s15, s5, s15 */
/* @0x16ca10 cmp r3, r2 */
/* @0x16ca14 vstmia r0!, {s15} */
/* @0x16ca18 bne 0x16ca08 <_ZN8yyMatrix6InvertEv+0x3ac> */
/* @0x16ca1c mov r0, #1 */
/* @0x16ca20 add sp, sp, #96 */
/* @0x16ca24 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x16ca28 bx lr */

/* ── FUNC 0x16ca2c · ConvertAlpha(float) · size=72 · insn=18 */
/* @0x16ca2c vmov.f32 s14, #1.000000e+00 */
/* @0x16ca30 vmov s15, r0 */
/* @0x16ca34 vcmpe.f32 s15, s14 */
/* @0x16ca38 vmrs APSR_nzcv, fpscr */
/* @0x16ca3c ble 0x16ca48 <_Z12ConvertAlphaf+0x1c> */
/* @0x16ca40 mov r0, #255 */
/* @0x16ca44 bx lr */
/* @0x16ca48 vcmpe.f32 s15, #0 */
/* @0x16ca4c vmrs APSR_nzcv, fpscr */
/* @0x16ca50 bpl 0x16ca5c <_Z12ConvertAlphaf+0x30> */
/* @0x16ca54 mov r0, #0 */
/* @0x16ca58 bx lr */
/* @0x16ca5c vldr s14, [pc, #12] */
/* @0x16ca60 vmul.f32 s15, s15, s14 */
/* @0x16ca64 vcvt.u32.f32 s15, s15 */
/* @0x16ca68 vmov r0, s15 */
/* @0x16ca6c bx lr */
/* @0x16ca70 cmnmi pc, #0 */

/* ── FUNC 0x16ca74 · GR_RGBA_To_D3DColor(int, int, int, unsigned int) · size=32 · insn=8 */
/* @0x16ca74 lsl r1, r1, #8 */
/* @0x16ca78 uxtb r2, r2 */
/* @0x16ca7c uxtb r0, r0 */
/* @0x16ca80 uxth r1, r1 */
/* @0x16ca84 orr r3, r1, r3, lsl #24 */
/* @0x16ca88 orr r2, r3, r2 */
/* @0x16ca8c orr r0, r2, r0, lsl #16 */
/* @0x16ca90 bx lr */

/* ── FUNC 0x16ca94 · GR_Color_To_D3DColor(unsigned int, unsigned int) · size=8 · insn=2 */
/* @0x16ca94 bfi r0, r1, #24, #8 */
/* @0x16ca98 bx lr */

/* ── FUNC 0x16ca9c · GR_D3DColor_Change_Alpha(unsigned int, unsigned int) · size=8 · insn=2 */
/* @0x16ca9c bfi r0, r1, #24, #8 */
/* @0x16caa0 bx lr */

/* ── FUNC 0x16caa4 · GR_D3DColor_To_Color(unsigned int) · size=4 · insn=1 */
/* @0x16caa4 bx lr */

/* ── FUNC 0x16caa8 · GR_Color_Merge(unsigned int, unsigned int, float) · size=196 · insn=49 */
/* @0x16caa8 push {r3, r4, r5, r6, r7, lr} */
/* @0x16caac vpush {d8} */
/* @0x16cab0 uxtb r3, r1 */
/* @0x16cab4 vmov.f32 s17, #1.000000e+00 */
/* @0x16cab8 mov r4, r1 */
/* @0x16cabc vmov s15, r3 */
/* @0x16cac0 uxtb r3, r0 */
/* @0x16cac4 vmov s16, r2 */
/* @0x16cac8 mov r5, r0 */
/* @0x16cacc vmov s14, r3 */
/* @0x16cad0 vcvt.f32.s32 s15, s15 */
/* @0x16cad4 vmul.f32 s15, s15, s16 */
/* @0x16cad8 vsub.f32 s17, s17, s16 */
/* @0x16cadc vcvt.f32.s32 s14, s14 */
/* @0x16cae0 vmla.f32 s15, s14, s17 */
/* @0x16cae4 vcvt.f64.f32 d6, s15 */
/* @0x16cae8 vmov r0, r1, d6 */
/* @0x16caec bl 0xb66e8 <lrint@plt> */
/* @0x16caf0 ubfx r3, r4, #0x8, #0x8 */
/* @0x16caf4 ubfx r4, r4, #0x10, #0x8 */
/* @0x16caf8 vmov s15, r3 */
/* @0x16cafc ubfx r3, r5, #0x8, #0x8 */
/* @0x16cb00 ubfx r5, r5, #0x10, #0x8 */
/* @0x16cb04 vcvt.f32.s32 s15, s15 */
/* @0x16cb08 vmov s14, r3 */
/* @0x16cb0c vmul.f32 s15, s15, s16 */
/* @0x16cb10 vcvt.f32.s32 s14, s14 */
/* @0x16cb14 vmla.f32 s15, s17, s14 */
/* @0x16cb18 mov r6, r0 */
/* @0x16cb1c vcvt.f64.f32 d6, s15 */
/* @0x16cb20 vmov r0, r1, d6 */
/* @0x16cb24 bl 0xb66e8 <lrint@plt> */
/* @0x16cb28 vmov s13, r4 */
/* @0x16cb2c vcvt.f32.s32 s14, s13 */
/* @0x16cb30 vmul.f32 s16, s14, s16 */
/* @0x16cb34 vmov s14, r5 */
/* @0x16cb38 vcvt.f32.s32 s15, s14 */
/* @0x16cb3c vmla.f32 s16, s17, s15 */
/* @0x16cb40 mov r7, r0 */
/* @0x16cb44 lsl r7, r7, #8 */
/* @0x16cb48 uxth r7, r7 */
/* @0x16cb4c uxtab r6, r7, r6 */
/* @0x16cb50 vcvt.f64.f32 d6, s16 */
/* @0x16cb54 vmov r0, r1, d6 */
/* @0x16cb58 bl 0xb66e8 <lrint@plt> */
/* @0x16cb5c vpop {d8} */
/* @0x16cb60 uxtb r0, r0 */
/* @0x16cb64 add r0, r6, r0, lsl #16 */
/* @0x16cb68 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x16cb6c · CreateBMP(void*, int, int, int*, int) · size=288 · insn=72 */
/* @0x16cb6c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x16cb70 add r7, r1, r1, lsl #1 */
/* @0x16cb74 mov r4, r2 */
/* @0x16cb78 mov r6, r1 */
/* @0x16cb7c mul r10, r4, r7 */
/* @0x16cb80 ldr r1, [pc, #0x100] */
/* @0x16cb84 mov r2, #182 */
/* @0x16cb88 mov r5, r0 */
/* @0x16cb8c add r1, pc, r1 */
/* @0x16cb90 ldr r8, [sp, #0x20] */
/* @0x16cb94 add r10, r10, #54 */
/* @0x16cb98 str r10, [r3] */
/* @0x16cb9c mov r3, #1 */
/* @0x16cba0 mov r0, r10 */
/* @0x16cba4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x16cba8 mul r1, r4, r6 */
/* @0x16cbac subs r9, r4, #1 */
/* @0x16cbb0 mov r12, #66 */
/* @0x16cbb4 mov r2, #77 */
/* @0x16cbb8 mov r3, #54 */
/* @0x16cbbc strb r12, [r0] */
/* @0x16cbc0 mov r12, #40 */
/* @0x16cbc4 strb r2, [r0, #0x1] */
/* @0x16cbc8 mov r2, #1 */
/* @0x16cbcc str r3, [r0, #0xa] */
/* @0x16cbd0 mov r3, #24 */
/* @0x16cbd4 str r12, [r0, #0xe] */
/* @0x16cbd8 add r12, r1, r1, lsl #1 */
/* @0x16cbdc strh r2, [r0, #26] */
/* @0x16cbe0 mov r2, #0 */
/* @0x16cbe4 strh r3, [r0, #28] */
/* @0x16cbe8 add r3, r0, #54 */
/* @0x16cbec str r10, [r0, #0x2] */
/* @0x16cbf0 str r6, [r0, #0x12] */
/* @0x16cbf4 str r4, [r0, #0x16] */
/* @0x16cbf8 str r12, [r0, #0x22] */
/* @0x16cbfc strh r2, [r0, #6] */
/* @0x16cc00 strh r2, [r0, #8] */
/* @0x16cc04 str r2, [r0, #0x1e] */
/* @0x16cc08 str r2, [r0, #0x26] */
/* @0x16cc0c str r2, [r0, #0x2a] */
/* @0x16cc10 str r2, [r0, #0x2e] */
/* @0x16cc14 str r2, [r0, #0x32] */
/* @0x16cc18 popmi {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x16cc1c rsb r1, r6, r1 */
/* @0x16cc20 rsb r10, r6, #0 */
/* @0x16cc24 cmp r6, #0 */
/* @0x16cc28 mla r1, r8, r1, r5 */
/* @0x16cc2c mul r10, r8, r10 */
/* @0x16cc30 mov r12, r1 */
/* @0x16cc34 ble 0x16cc80 <_Z9CreateBMPPviiPii+0x114> */
/* @0x16cc38 add r5, r3, r7 */
/* @0x16cc3c ldr r2, [r12], r8 */
/* @0x16cc40 add r3, r3, #3 */
/* @0x16cc44 strb r2, [r3, #-0x3] */
/* @0x16cc48 lsr r4, r2, #8 */
/* @0x16cc4c lsr r2, r2, #16 */
/* @0x16cc50 strb r4, [r3, #-0x2] */
/* @0x16cc54 strb r2, [r3, #-0x1] */
/* @0x16cc58 cmp r3, r5 */
/* @0x16cc5c bne 0x16cc3c <_Z9CreateBMPPviiPii+0xd0> */
/* @0x16cc60 sub r9, r9, #1 */
/* @0x16cc64 add r1, r1, r10 */
/* @0x16cc68 cmn r9, #1 */
/* @0x16cc6c popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x16cc70 cmp r6, #0 */
/* @0x16cc74 mov r3, r5 */
/* @0x16cc78 mov r12, r1 */
/* @0x16cc7c bgt 0x16cc38 <_Z9CreateBMPPviiPii+0xcc> */
/* @0x16cc80 mov r5, r3 */
/* @0x16cc84 b 0x16cc60 <_Z9CreateBMPPviiPii+0xf4> */
/* @0x16cc88 andseq sp, sp, r12, asr #25 */

/* ── FUNC 0x16cc8c · WritePNG32(char*, void*, int, int) · size=820 · insn=205 */
/* @0x16cc8c push {r4, lr} */
/* @0x16cc90 sub sp, sp, #2112 */
/* @0x16cc94 ldr r12, [pc, #0x2ec] */
/* @0x16cc98 add r4, sp, #60 */
/* @0x16cc9c str r1, [sp, #0x1c] */
/* @0x16cca0 mov lr, r0 */
/* @0x16cca4 add r12, pc, r12 */
/* @0x16cca8 str r12, [sp, #0x18] */
/* @0x16ccac ldr r1, [sp, #0x18] */
/* @0x16ccb0 mov r0, r4 */
/* @0x16ccb4 ldr r12, [pc, #0x2d0] */
/* @0x16ccb8 str r2, [sp, #0x28] */
/* @0x16ccbc mov r2, lr */
/* @0x16ccc0 ldr r12, [r1, r12] */
/* @0x16ccc4 mov r1, #2048 */
/* @0x16ccc8 str r3, [sp, #0x24] */
/* @0x16cccc ldr r3, [r12] */
/* @0x16ccd0 str r3, [sp, #0x83c] */
/* @0x16ccd4 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x16ccd8 mov r0, r4 */
/* @0x16ccdc bl 0x13ad20 <_Z24EnsureDirectoryIsCreatedPKc> */
/* @0x16cce0 ldr r1, [pc, #0x2a8] */
/* @0x16cce4 mov r0, r4 */
/* @0x16cce8 add r1, pc, r1 */
/* @0x16ccec bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_> */
/* @0x16ccf0 cmp r0, #0 */
/* @0x16ccf4 str r0, [sp, #0x20] */
/* @0x16ccf8 beq 0x16ce68 <_Z10WritePNG32PcPvii+0x1dc> */
/* @0x16ccfc ldr r0, [pc, #0x290] */
/* @0x16cd00 mov r1, #0 */
/* @0x16cd04 mov r2, r1 */
/* @0x16cd08 mov r3, r1 */
/* @0x16cd0c add r0, pc, r0 */
/* @0x16cd10 blx 0x2b0364 <png_create_write_struct> */
/* @0x16cd14 cmp r0, #0 */
/* @0x16cd18 str r0, [sp, #0x34] */
/* @0x16cd1c beq 0x16ce80 <_Z10WritePNG32PcPvii+0x1f4> */
/* @0x16cd20 blx 0x2a5b64 <png_create_info_struct> */
/* @0x16cd24 cmp r0, #0 */
/* @0x16cd28 str r0, [sp, #0x38] */
/* @0x16cd2c beq 0x16ce90 <_Z10WritePNG32PcPvii+0x204> */
/* @0x16cd30 ldr r3, [pc, #0x260] */
/* @0x16cd34 mov r2, #256 */
/* @0x16cd38 ldr r12, [sp, #0x18] */
/* @0x16cd3c ldr r0, [sp, #0x34] */
/* @0x16cd40 ldr r1, [r12, r3] */
/* @0x16cd44 blx 0x2a653c <png_set_longjmp_fn> */
/* @0x16cd48 bl 0xb6904 <setjmp@plt> */
/* @0x16cd4c cmp r0, #0 */
/* @0x16cd50 beq 0x16cdb8 <_Z10WritePNG32PcPvii+0x12c> */
/* @0x16cd54 ldr r1, [pc, #0x240] */
/* @0x16cd58 ldr r3, [pc, #0x240] */
/* @0x16cd5c add r1, pc, r1 */
/* @0x16cd60 ldr r2, [sp, #0x18] */
/* @0x16cd64 ldr r3, [r2, r3] */
/* @0x16cd68 ldr r0, [r3] */
/* @0x16cd6c ldr r3, [r0] */
/* @0x16cd70 ldr r3, [r3, #0xc] */
/* @0x16cd74 blx r3 */
/* @0x16cd78 mov r4, #0 */
/* @0x16cd7c add r0, sp, #52 */
/* @0x16cd80 add r1, sp, #56 */
/* @0x16cd84 blx 0x2b0692 <png_destroy_write_struct> */
/* @0x16cd88 ldr r0, [sp, #0x20] */
/* @0x16cd8c bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE> */
/* @0x16cd90 mov r0, r4 */
/* @0x16cd94 ldr r3, [pc, #0x1f0] */
/* @0x16cd98 ldr r12, [sp, #0x18] */
/* @0x16cd9c ldr r2, [sp, #0x83c] */
/* @0x16cda0 ldr r3, [r12, r3] */
/* @0x16cda4 ldr r3, [r3] */
/* @0x16cda8 cmp r2, r3 */
/* @0x16cdac bne 0x16cf84 <_Z10WritePNG32PcPvii+0x2f8> */
/* @0x16cdb0 add sp, sp, #2112 */
/* @0x16cdb4 pop {r4, pc} */
/* @0x16cdb8 ldr r2, [pc, #0x1e4] */
/* @0x16cdbc ldr r3, [pc, #0x1e4] */
/* @0x16cdc0 ldr r0, [sp, #0x34] */
/* @0x16cdc4 add r2, pc, r2 */
/* @0x16cdc8 ldr r1, [sp, #0x20] */
/* @0x16cdcc add r3, pc, r3 */
/* @0x16cdd0 blx 0x2afc18 <png_set_write_fn> */
/* @0x16cdd4 ldr r3, [pc, #0x1bc] */
/* @0x16cdd8 ldr r12, [sp, #0x18] */
/* @0x16cddc mov r2, #256 */
/* @0x16cde0 ldr r0, [sp, #0x34] */
/* @0x16cde4 ldr r1, [r12, r3] */
/* @0x16cde8 blx 0x2a653c <png_set_longjmp_fn> */
/* @0x16cdec bl 0xb6904 <setjmp@plt> */
/* @0x16cdf0 subs r3, r0, #0 */
/* @0x16cdf4 bne 0x16ce70 <_Z10WritePNG32PcPvii+0x1e4> */
/* @0x16cdf8 mov lr, #8 */
/* @0x16cdfc mov r12, #6 */
/* @0x16ce00 ldr r2, [sp, #0x28] */
/* @0x16ce04 str lr, [sp] */
/* @0x16ce08 str r12, [sp, #0x4] */
/* @0x16ce0c ldr r0, [sp, #0x34] */
/* @0x16ce10 ldr r1, [sp, #0x38] */
/* @0x16ce14 str r3, [sp, #0x8] */
/* @0x16ce18 str r3, [sp, #0xc] */
/* @0x16ce1c str r3, [sp, #0x10] */
/* @0x16ce20 ldr r3, [sp, #0x24] */
/* @0x16ce24 blx 0x2aea84 <png_set_IHDR> */
/* @0x16ce28 ldr r0, [sp, #0x34] */
/* @0x16ce2c ldr r1, [sp, #0x38] */
/* @0x16ce30 blx 0x2afe14 <png_write_info> */
/* @0x16ce34 ldr r3, [pc, #0x15c] */
/* @0x16ce38 ldr r12, [sp, #0x18] */
/* @0x16ce3c mov r2, #256 */
/* @0x16ce40 ldr r0, [sp, #0x34] */
/* @0x16ce44 ldr r1, [r12, r3] */
/* @0x16ce48 blx 0x2a653c <png_set_longjmp_fn> */
/* @0x16ce4c bl 0xb6904 <setjmp@plt> */
/* @0x16ce50 cmp r0, #0 */
/* @0x16ce54 beq 0x16ceb8 <_Z10WritePNG32PcPvii+0x22c> */
/* @0x16ce58 ldr r1, [pc, #0x14c] */
/* @0x16ce5c ldr r3, [pc, #0x13c] */
/* @0x16ce60 add r1, pc, r1 */
/* @0x16ce64 b 0x16cd60 <_Z10WritePNG32PcPvii+0xd4> */
/* @0x16ce68 ldr r0, [sp, #0x20] */
/* @0x16ce6c b 0x16cd94 <_Z10WritePNG32PcPvii+0x108> */
/* @0x16ce70 ldr r1, [pc, #0x138] */
/* @0x16ce74 ldr r3, [pc, #0x124] */
/* @0x16ce78 add r1, pc, r1 */
/* @0x16ce7c b 0x16cd60 <_Z10WritePNG32PcPvii+0xd4> */
/* @0x16ce80 ldr r1, [pc, #0x12c] */
/* @0x16ce84 ldr r3, [pc, #0x114] */
/* @0x16ce88 add r1, pc, r1 */
/* @0x16ce8c b 0x16cd60 <_Z10WritePNG32PcPvii+0xd4> */
/* @0x16ce90 ldr r12, [sp, #0x18] */
/* @0x16ce94 ldr r3, [pc, #0x104] */
/* @0x16ce98 ldr r1, [pc, #0x118] */
/* @0x16ce9c ldr r3, [r12, r3] */
/* @0x16cea0 add r1, pc, r1 */
/* @0x16cea4 ldr r0, [r3] */
/* @0x16cea8 ldr r3, [r0] */
/* @0x16ceac ldr r3, [r3, #0xc] */
/* @0x16ceb0 blx r3 */
/* @0x16ceb4 b 0x16cd78 <_Z10WritePNG32PcPvii+0xec> */
/* @0x16ceb8 ldr r3, [sp, #0x24] */
/* @0x16cebc lsl r4, r3, #2 */
/* @0x16cec0 mov r0, r4 */
/* @0x16cec4 bl 0xb6544 <malloc@plt> */
/* @0x16cec8 ldr r12, [sp, #0x24] */
/* @0x16cecc cmp r12, #0 */
/* @0x16ced0 str r0, [sp, #0x2c] */
/* @0x16ced4 ble 0x16cf00 <_Z10WritePNG32PcPvii+0x274> */
/* @0x16ced8 ldr r1, [sp, #0x28] */
/* @0x16cedc ldr r3, [sp, #0x2c] */
/* @0x16cee0 lsl r2, r1, #2 */
/* @0x16cee4 add r0, r3, r4 */
/* @0x16cee8 ldr r12, [sp, #0x1c] */
/* @0x16ceec str r12, [r3], #4 */
/* @0x16cef0 cmp r3, r0 */
/* @0x16cef4 add r12, r12, r2 */
/* @0x16cef8 str r12, [sp, #0x1c] */
/* @0x16cefc bne 0x16cee8 <_Z10WritePNG32PcPvii+0x25c> */
/* @0x16cf00 ldr r0, [sp, #0x34] */
/* @0x16cf04 ldr r1, [sp, #0x2c] */
/* @0x16cf08 blx 0x2b0510 <png_write_image> */
/* @0x16cf0c ldr r3, [pc, #0x84] */
/* @0x16cf10 ldr r12, [sp, #0x18] */
/* @0x16cf14 mov r2, #256 */
/* @0x16cf18 ldr r0, [sp, #0x34] */
/* @0x16cf1c ldr r1, [r12, r3] */
/* @0x16cf20 blx 0x2a653c <png_set_longjmp_fn> */
/* @0x16cf24 bl 0xb6904 <setjmp@plt> */
/* @0x16cf28 cmp r0, #0 */
/* @0x16cf2c bne 0x16cf58 <_Z10WritePNG32PcPvii+0x2cc> */
/* @0x16cf30 ldr r0, [sp, #0x34] */
/* @0x16cf34 mov r4, #1 */
/* @0x16cf38 ldr r1, [sp, #0x38] */
/* @0x16cf3c blx 0x2b002c <png_write_end> */
/* @0x16cf40 ldr r3, [sp, #0x2c] */
/* @0x16cf44 cmp r3, #0 */
/* @0x16cf48 beq 0x16cd7c <_Z10WritePNG32PcPvii+0xf0> */
/* @0x16cf4c mov r0, r3 */
/* @0x16cf50 bl 0xb655c <free@plt> */
/* @0x16cf54 b 0x16cd7c <_Z10WritePNG32PcPvii+0xf0> */
/* @0x16cf58 ldr r2, [sp, #0x18] */
/* @0x16cf5c mov r4, #0 */
/* @0x16cf60 ldr r3, [pc, #0x38] */
/* @0x16cf64 ldr r1, [pc, #0x50] */
/* @0x16cf68 ldr r3, [r2, r3] */
/* @0x16cf6c add r1, pc, r1 */
/* @0x16cf70 ldr r0, [r3] */
/* @0x16cf74 ldr r3, [r0] */
/* @0x16cf78 ldr r3, [r3, #0xc] */
/* @0x16cf7c blx r3 */
/* @0x16cf80 b 0x16cf40 <_Z10WritePNG32PcPvii+0x2b4> */
/* @0x16cf84 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x16cf88 eoreq r4, r8, r12, lsr #31 */
/* @0x16cf8c .word 0xffffbd00 */
/* @0x16cf90 andseq r3, sp, r12, asr r6 */
/* @0x16cf94 andseq sp, sp, r0, lsr r9 */
/* @0x16cf98 .word 0xffffe4ac */
/* @0x16cf9c andseq sp, sp, r12, asr #18 */
/* @0x16cfa0 .word 0xffffbac4 */
/* @0x16cfa4 .word 0xfffff500 */
/* @0x16cfa8 .word 0xfffff4f4 */
/* @0x16cfac andseq sp, sp, r8, lsr r10 */
/* @0x16cfb0 andseq sp, sp, r8, asr r8 */
/* @0x16cfb4 ldrheq sp, [sp], -r12 */
/* @0x16cfb8 ldrsbeq sp, [sp], -r8 */
/* @0x16cfbc andseq sp, sp, r8, asr r9 */

/* ── FUNC 0x16cfc0 · CCamera::CCamera() · size=352 · insn=88 */
/* @0x16cfc0 mov r2, #0 */
/* @0x16cfc4 mov r1, #1065353216 */
/* @0x16cfc8 mvn r12, #0 */
/* @0x16cfcc str r2, [r0, #0x3c] */
/* @0x16cfd0 push {r4, r5} */
/* @0x16cfd4 mov r5, #1 */
/* @0x16cfd8 mov r4, #0 */
/* @0x16cfdc str r2, [r0, #0x38] */
/* @0x16cfe0 str r2, [r0, #0x34] */
/* @0x16cfe4 str r2, [r0, #0x30] */
/* @0x16cfe8 str r2, [r0, #0x28] */
/* @0x16cfec str r2, [r0, #0x24] */
/* @0x16cff0 str r2, [r0, #0x20] */
/* @0x16cff4 str r2, [r0, #0x1c] */
/* @0x16cff8 str r2, [r0, #0x14] */
/* @0x16cffc str r2, [r0, #0x10] */
/* @0x16d000 str r2, [r0, #0xc] */
/* @0x16d004 str r2, [r0, #0x8] */
/* @0x16d008 str r2, [r0, #0x7c] */
/* @0x16d00c str r2, [r0, #0x78] */
/* @0x16d010 str r2, [r0, #0x74] */
/* @0x16d014 str r2, [r0, #0x70] */
/* @0x16d018 str r1, [r0, #0x40] */
/* @0x16d01c str r1, [r0, #0x2c] */
/* @0x16d020 str r1, [r0, #0x18] */
/* @0x16d024 str r1, [r0, #0x4] */
/* @0x16d028 str r1, [r0, #0x80] */
/* @0x16d02c str r1, [r0, #0x6c] */
/* @0x16d030 str r1, [r0, #0x58] */
/* @0x16d034 str r1, [r0, #0x44] */
/* @0x16d038 str r2, [r0, #0x68] */
/* @0x16d03c str r2, [r0, #0x64] */
/* @0x16d040 str r2, [r0, #0x60] */
/* @0x16d044 str r2, [r0, #0x5c] */
/* @0x16d048 str r2, [r0, #0x54] */
/* @0x16d04c str r2, [r0, #0x50] */
/* @0x16d050 str r2, [r0, #0x4c] */
/* @0x16d054 str r2, [r0, #0x48] */
/* @0x16d058 str r12, [r0] */
/* @0x16d05c str r1, [r0, #0x100] */
/* @0x16d060 str r1, [r0, #0xec] */
/* @0x16d064 str r1, [r0, #0xd8] */
/* @0x16d068 str r1, [r0, #0xc4] */
/* @0x16d06c str r2, [r0, #0xfc] */
/* @0x16d070 str r2, [r0, #0xf8] */
/* @0x16d074 str r2, [r0, #0xf4] */
/* @0x16d078 str r2, [r0, #0xf0] */
/* @0x16d07c str r2, [r0, #0xe8] */
/* @0x16d080 str r2, [r0, #0xe4] */
/* @0x16d084 str r2, [r0, #0xe0] */
/* @0x16d088 str r2, [r0, #0xdc] */
/* @0x16d08c str r2, [r0, #0xd4] */
/* @0x16d090 str r2, [r0, #0xd0] */
/* @0x16d094 str r2, [r0, #0xcc] */
/* @0x16d098 str r2, [r0, #0xc8] */
/* @0x16d09c str r1, [r0, #0x140] */
/* @0x16d0a0 str r1, [r0, #0x12c] */
/* @0x16d0a4 str r1, [r0, #0x118] */
/* @0x16d0a8 str r1, [r0, #0x104] */
/* @0x16d0ac str r2, [r0, #0x13c] */
/* @0x16d0b0 str r2, [r0, #0x138] */
/* @0x16d0b4 str r2, [r0, #0x134] */
/* @0x16d0b8 str r2, [r0, #0x130] */
/* @0x16d0bc str r2, [r0, #0x128] */
/* @0x16d0c0 str r2, [r0, #0x124] */
/* @0x16d0c4 str r2, [r0, #0x120] */
/* @0x16d0c8 str r2, [r0, #0x11c] */
/* @0x16d0cc str r2, [r0, #0x114] */
/* @0x16d0d0 str r2, [r0, #0x110] */
/* @0x16d0d4 str r2, [r0, #0x10c] */
/* @0x16d0d8 str r2, [r0, #0x108] */
/* @0x16d0dc str r2, [r0, #0x184] */
/* @0x16d0e0 str r2, [r0, #0x188] */
/* @0x16d0e4 strb r5, [r0, #0x1b8] */
/* @0x16d0e8 strb r4, [r0, #0x1b9] */
/* @0x16d0ec str r2, [r0, #0x18c] */
/* @0x16d0f0 str r2, [r0, #0x190] */
/* @0x16d0f4 str r2, [r0, #0x194] */
/* @0x16d0f8 str r2, [r0, #0x198] */
/* @0x16d0fc str r2, [r0, #0x19c] */
/* @0x16d100 str r2, [r0, #0x1a0] */
/* @0x16d104 str r2, [r0, #0x1a4] */
/* @0x16d108 str r12, [r0, #0x1a8] */
/* @0x16d10c str r12, [r0, #0x1ac] */
/* @0x16d110 str r12, [r0, #0x1b0] */
/* @0x16d114 str r12, [r0, #0x1b4] */
/* @0x16d118 pop {r4, r5} */
/* @0x16d11c bx lr */

/* ── FUNC 0x16cfc0 · CCamera::CCamera() · alias of the symbol above · insn=0 */

/* ── FUNC 0x16d120 · CCamera::~CCamera() · size=4 · insn=1 */
/* @0x16d120 bx lr */

/* ── FUNC 0x16d120 · CCamera::~CCamera() · alias of the symbol above · insn=0 */

/* ── FUNC 0x16d124 · CCamera::SetID(int) · size=8 · insn=2 */
/* @0x16d124 str r1, [r0] */
/* @0x16d128 bx lr */

/* ── FUNC 0x16d12c · CCamera::GetID() · size=8 · insn=2 */
/* @0x16d12c ldr r0, [r0] */
/* @0x16d130 bx lr */

/* ── FUNC 0x16d134 · CCamera::GetProjMat() · size=60 · insn=15 */
/* @0x16d134 push {r4, r5} */
/* @0x16d138 add r4, r1, #4 */
/* @0x16d13c mov r5, r0 */
/* @0x16d140 mov r12, r0 */
/* @0x16d144 ldm r4!, {r0, r1, r2, r3} */
/* @0x16d148 stm r12!, {r0, r1, r2, r3} */
/* @0x16d14c ldm r4!, {r0, r1, r2, r3} */
/* @0x16d150 stm r12!, {r0, r1, r2, r3} */
/* @0x16d154 ldm r4!, {r0, r1, r2, r3} */
/* @0x16d158 stm r12!, {r0, r1, r2, r3} */
/* @0x16d15c ldm r4, {r0, r1, r2, r3} */
/* @0x16d160 stm r12, {r0, r1, r2, r3} */
/* @0x16d164 mov r0, r5 */
/* @0x16d168 pop {r4, r5} */
/* @0x16d16c bx lr */
