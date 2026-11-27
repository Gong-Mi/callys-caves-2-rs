/* libyoyo.so 覆盖卡组 0078
 * 函数 0x144414..0x1451b0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x144414 · F_D3DDrawEllipsoid(RValue&, CInstance*, CInstance*, int, RValue*) · size=236 · insn=59 */
/* @0x144414 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x144418 sub sp, sp, #36 */
/* @0x14441c mov r1, #0 */
/* @0x144420 ldr r4, [sp, #0x48] */
/* @0x144424 mov r0, r4 */
/* @0x144428 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14442c mov r1, #1 */
/* @0x144430 mov r5, r0 */
/* @0x144434 mov r0, r4 */
/* @0x144438 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14443c mov r1, #2 */
/* @0x144440 mov r8, r0 */
/* @0x144444 mov r0, r4 */
/* @0x144448 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14444c mov r1, #3 */
/* @0x144450 mov r7, r0 */
/* @0x144454 mov r0, r4 */
/* @0x144458 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14445c mov r1, #4 */
/* @0x144460 mov r6, r0 */
/* @0x144464 mov r0, r4 */
/* @0x144468 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14446c mov r1, #5 */
/* @0x144470 mov r2, r0 */
/* @0x144474 mov r0, r4 */
/* @0x144478 str r2, [sp, #0x18] */
/* @0x14447c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144480 mov r1, #6 */
/* @0x144484 mov r3, r0 */
/* @0x144488 mov r0, r4 */
/* @0x14448c str r3, [sp, #0x1c] */
/* @0x144490 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei> */
/* @0x144494 mov r1, #7 */
/* @0x144498 mov r11, r0 */
/* @0x14449c mov r0, r4 */
/* @0x1444a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1444a4 mov r1, #8 */
/* @0x1444a8 mov r10, r0 */
/* @0x1444ac mov r0, r4 */
/* @0x1444b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1444b4 mov r1, #9 */
/* @0x1444b8 mov r9, r0 */
/* @0x1444bc mov r0, r4 */
/* @0x1444c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1444c4 ldr r2, [sp, #0x18] */
/* @0x1444c8 ldr r3, [sp, #0x1c] */
/* @0x1444cc mov r1, r8 */
/* @0x1444d0 str r11, [sp, #0x8] */
/* @0x1444d4 str r2, [sp] */
/* @0x1444d8 mov r2, r7 */
/* @0x1444dc str r3, [sp, #0x4] */
/* @0x1444e0 mov r3, r6 */
/* @0x1444e4 str r10, [sp, #0xc] */
/* @0x1444e8 str r9, [sp, #0x10] */
/* @0x1444ec str r0, [sp, #0x14] */
/* @0x1444f0 mov r0, r5 */
/* @0x1444f4 bl 0x17934c <_Z20GR_3D_Draw_Ellipsoidffffffiffi> */
/* @0x1444f8 add sp, sp, #36 */
/* @0x1444fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x144500 · F_D3DDrawWall(RValue&, CInstance*, CInstance*, int, RValue*) · size=208 · insn=52 */
/* @0x144500 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x144504 sub sp, sp, #36 */
/* @0x144508 mov r1, #0 */
/* @0x14450c ldr r4, [sp, #0x48] */
/* @0x144510 mov r0, r4 */
/* @0x144514 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144518 mov r1, #1 */
/* @0x14451c mov r5, r0 */
/* @0x144520 mov r0, r4 */
/* @0x144524 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144528 mov r1, #2 */
/* @0x14452c mov r8, r0 */
/* @0x144530 mov r0, r4 */
/* @0x144534 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144538 mov r1, #3 */
/* @0x14453c mov r7, r0 */
/* @0x144540 mov r0, r4 */
/* @0x144544 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144548 mov r1, #4 */
/* @0x14454c mov r6, r0 */
/* @0x144550 mov r0, r4 */
/* @0x144554 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144558 mov r1, #5 */
/* @0x14455c mov r3, r0 */
/* @0x144560 mov r0, r4 */
/* @0x144564 str r3, [sp, #0x1c] */
/* @0x144568 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14456c mov r1, #6 */
/* @0x144570 mov r11, r0 */
/* @0x144574 mov r0, r4 */
/* @0x144578 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei> */
/* @0x14457c mov r1, #7 */
/* @0x144580 mov r10, r0 */
/* @0x144584 mov r0, r4 */
/* @0x144588 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14458c mov r1, #8 */
/* @0x144590 mov r9, r0 */
/* @0x144594 mov r0, r4 */
/* @0x144598 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14459c ldr r3, [sp, #0x1c] */
/* @0x1445a0 str r11, [sp, #0x4] */
/* @0x1445a4 mov r1, r8 */
/* @0x1445a8 str r10, [sp, #0x8] */
/* @0x1445ac mov r2, r7 */
/* @0x1445b0 str r3, [sp] */
/* @0x1445b4 mov r3, r6 */
/* @0x1445b8 str r9, [sp, #0xc] */
/* @0x1445bc str r0, [sp, #0x10] */
/* @0x1445c0 mov r0, r5 */
/* @0x1445c4 bl 0x1796e0 <_Z15GR_3D_Draw_Wallffffffiff> */
/* @0x1445c8 add sp, sp, #36 */
/* @0x1445cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x1445d0 · F_D3DDrawFloor(RValue&, CInstance*, CInstance*, int, RValue*) · size=208 · insn=52 */
/* @0x1445d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1445d4 sub sp, sp, #36 */
/* @0x1445d8 mov r1, #0 */
/* @0x1445dc ldr r4, [sp, #0x48] */
/* @0x1445e0 mov r0, r4 */
/* @0x1445e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1445e8 mov r1, #1 */
/* @0x1445ec mov r5, r0 */
/* @0x1445f0 mov r0, r4 */
/* @0x1445f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1445f8 mov r1, #2 */
/* @0x1445fc mov r8, r0 */
/* @0x144600 mov r0, r4 */
/* @0x144604 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144608 mov r1, #3 */
/* @0x14460c mov r7, r0 */
/* @0x144610 mov r0, r4 */
/* @0x144614 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144618 mov r1, #4 */
/* @0x14461c mov r6, r0 */
/* @0x144620 mov r0, r4 */
/* @0x144624 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144628 mov r1, #5 */
/* @0x14462c mov r3, r0 */
/* @0x144630 mov r0, r4 */
/* @0x144634 str r3, [sp, #0x1c] */
/* @0x144638 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14463c mov r1, #6 */
/* @0x144640 mov r11, r0 */
/* @0x144644 mov r0, r4 */
/* @0x144648 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei> */
/* @0x14464c mov r1, #7 */
/* @0x144650 mov r10, r0 */
/* @0x144654 mov r0, r4 */
/* @0x144658 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14465c mov r1, #8 */
/* @0x144660 mov r9, r0 */
/* @0x144664 mov r0, r4 */
/* @0x144668 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14466c ldr r3, [sp, #0x1c] */
/* @0x144670 str r11, [sp, #0x4] */
/* @0x144674 mov r1, r8 */
/* @0x144678 str r10, [sp, #0x8] */
/* @0x14467c mov r2, r7 */
/* @0x144680 str r3, [sp] */
/* @0x144684 mov r3, r6 */
/* @0x144688 str r9, [sp, #0xc] */
/* @0x14468c str r0, [sp, #0x10] */
/* @0x144690 mov r0, r5 */
/* @0x144694 bl 0x179834 <_Z16GR_3D_Draw_Floorffffffiff> */
/* @0x144698 add sp, sp, #36 */
/* @0x14469c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x1446a0 · F_D3DSetProjection(RValue&, CInstance*, CInstance*, int, RValue*) · size=208 · insn=52 */
/* @0x1446a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1446a4 sub sp, sp, #36 */
/* @0x1446a8 mov r1, #0 */
/* @0x1446ac ldr r4, [sp, #0x48] */
/* @0x1446b0 mov r0, r4 */
/* @0x1446b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1446b8 mov r1, #1 */
/* @0x1446bc mov r5, r0 */
/* @0x1446c0 mov r0, r4 */
/* @0x1446c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1446c8 mov r1, #2 */
/* @0x1446cc mov r8, r0 */
/* @0x1446d0 mov r0, r4 */
/* @0x1446d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1446d8 mov r1, #3 */
/* @0x1446dc mov r7, r0 */
/* @0x1446e0 mov r0, r4 */
/* @0x1446e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1446e8 mov r1, #4 */
/* @0x1446ec mov r6, r0 */
/* @0x1446f0 mov r0, r4 */
/* @0x1446f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1446f8 mov r1, #5 */
/* @0x1446fc mov r3, r0 */
/* @0x144700 mov r0, r4 */
/* @0x144704 str r3, [sp, #0x1c] */
/* @0x144708 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14470c mov r1, #6 */
/* @0x144710 mov r11, r0 */
/* @0x144714 mov r0, r4 */
/* @0x144718 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14471c mov r1, #7 */
/* @0x144720 mov r10, r0 */
/* @0x144724 mov r0, r4 */
/* @0x144728 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14472c mov r1, #8 */
/* @0x144730 mov r9, r0 */
/* @0x144734 mov r0, r4 */
/* @0x144738 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14473c ldr r3, [sp, #0x1c] */
/* @0x144740 str r11, [sp, #0x4] */
/* @0x144744 mov r1, r8 */
/* @0x144748 str r10, [sp, #0x8] */
/* @0x14474c mov r2, r7 */
/* @0x144750 str r3, [sp] */
/* @0x144754 mov r3, r6 */
/* @0x144758 str r9, [sp, #0xc] */
/* @0x14475c str r0, [sp, #0x10] */
/* @0x144760 mov r0, r5 */
/* @0x144764 bl 0x163280 <_Z23GR_3D_Projection_LookAtfffffffff> */
/* @0x144768 add sp, sp, #36 */
/* @0x14476c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x144770 · F_D3DSetProjectionExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=304 · insn=76 */
/* @0x144770 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x144774 sub sp, sp, #68 */
/* @0x144778 mov r1, #0 */
/* @0x14477c ldr r4, [sp, #0x68] */
/* @0x144780 mov r0, r4 */
/* @0x144784 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144788 mov r1, #1 */
/* @0x14478c mov r5, r0 */
/* @0x144790 mov r0, r4 */
/* @0x144794 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144798 mov r1, #2 */
/* @0x14479c mov r6, r0 */
/* @0x1447a0 mov r0, r4 */
/* @0x1447a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1447a8 mov r1, #3 */
/* @0x1447ac mov r2, r0 */
/* @0x1447b0 mov r0, r4 */
/* @0x1447b4 str r2, [sp, #0x2c] */
/* @0x1447b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1447bc mov r1, #4 */
/* @0x1447c0 mov r3, r0 */
/* @0x1447c4 mov r0, r4 */
/* @0x1447c8 str r3, [sp, #0x30] */
/* @0x1447cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1447d0 mov r1, #5 */
/* @0x1447d4 mov r12, r0 */
/* @0x1447d8 mov r0, r4 */
/* @0x1447dc str r12, [sp, #0x34] */
/* @0x1447e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1447e4 mov r1, #6 */
/* @0x1447e8 str r0, [sp, #0x38] */
/* @0x1447ec mov r0, r4 */
/* @0x1447f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1447f4 mov r1, #7 */
/* @0x1447f8 str r0, [sp, #0x3c] */
/* @0x1447fc mov r0, r4 */
/* @0x144800 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144804 mov r1, #8 */
/* @0x144808 mov r11, r0 */
/* @0x14480c mov r0, r4 */
/* @0x144810 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144814 mov r1, #9 */
/* @0x144818 mov r10, r0 */
/* @0x14481c mov r0, r4 */
/* @0x144820 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144824 mov r1, #10 */
/* @0x144828 mov r9, r0 */
/* @0x14482c mov r0, r4 */
/* @0x144830 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144834 mov r1, #11 */
/* @0x144838 mov r8, r0 */
/* @0x14483c mov r0, r4 */
/* @0x144840 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144844 mov r1, #12 */
/* @0x144848 mov r7, r0 */
/* @0x14484c mov r0, r4 */
/* @0x144850 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144854 ldr r1, [sp, #0x38] */
/* @0x144858 ldr r12, [sp, #0x34] */
/* @0x14485c str r11, [sp, #0xc] */
/* @0x144860 str r1, [sp, #0x4] */
/* @0x144864 ldr r1, [sp, #0x3c] */
/* @0x144868 str r12, [sp] */
/* @0x14486c str r10, [sp, #0x10] */
/* @0x144870 str r1, [sp, #0x8] */
/* @0x144874 mov r1, r6 */
/* @0x144878 str r9, [sp, #0x14] */
/* @0x14487c str r8, [sp, #0x18] */
/* @0x144880 str r7, [sp, #0x1c] */
/* @0x144884 ldr r2, [sp, #0x2c] */
/* @0x144888 ldr r3, [sp, #0x30] */
/* @0x14488c str r0, [sp, #0x20] */
/* @0x144890 mov r0, r5 */
/* @0x144894 bl 0x1632f0 <_Z27GR_3D_Projection_LookAt_Extfffffffffffff> */
/* @0x144898 add sp, sp, #68 */
/* @0x14489c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x1448a0 · F_D3DSetProjectionOrtho(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x1448a0 push {r4, r5, r6, r7, r8, lr} */
/* @0x1448a4 mov r1, #0 */
/* @0x1448a8 ldr r4, [sp, #0x18] */
/* @0x1448ac mov r0, r4 */
/* @0x1448b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1448b4 mov r1, #1 */
/* @0x1448b8 mov r5, r0 */
/* @0x1448bc mov r0, r4 */
/* @0x1448c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1448c4 mov r1, #2 */
/* @0x1448c8 mov r8, r0 */
/* @0x1448cc mov r0, r4 */
/* @0x1448d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1448d4 mov r1, #3 */
/* @0x1448d8 mov r7, r0 */
/* @0x1448dc mov r0, r4 */
/* @0x1448e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1448e4 mov r1, #4 */
/* @0x1448e8 mov r6, r0 */
/* @0x1448ec mov r0, r4 */
/* @0x1448f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1448f4 mov r1, r8 */
/* @0x1448f8 mov r2, r7 */
/* @0x1448fc mov r3, r6 */
/* @0x144900 str r0, [sp, #0x18] */
/* @0x144904 mov r0, r5 */
/* @0x144908 pop {r4, r5, r6, r7, r8, lr} */
/* @0x14490c b 0x1633e8 <_Z22GR_3D_Projection_Orthofffff> */

/* ── FUNC 0x144910 · F_D3DSetProjectionPerspective(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x144910 push {r4, r5, r6, r7, r8, lr} */
/* @0x144914 mov r1, #0 */
/* @0x144918 ldr r4, [sp, #0x18] */
/* @0x14491c mov r0, r4 */
/* @0x144920 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144924 mov r1, #1 */
/* @0x144928 mov r5, r0 */
/* @0x14492c mov r0, r4 */
/* @0x144930 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144934 mov r1, #2 */
/* @0x144938 mov r8, r0 */
/* @0x14493c mov r0, r4 */
/* @0x144940 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144944 mov r1, #3 */
/* @0x144948 mov r7, r0 */
/* @0x14494c mov r0, r4 */
/* @0x144950 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144954 mov r1, #4 */
/* @0x144958 mov r6, r0 */
/* @0x14495c mov r0, r4 */
/* @0x144960 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144964 mov r1, r8 */
/* @0x144968 mov r2, r7 */
/* @0x14496c mov r3, r6 */
/* @0x144970 str r0, [sp, #0x18] */
/* @0x144974 mov r0, r5 */
/* @0x144978 pop {r4, r5, r6, r7, r8, lr} */
/* @0x14497c b 0x163548 <_Z28GR_3D_Projection_Perspectivefffff> */

/* ── FUNC 0x144980 · F_D3DMatrixStackTop(RValue&, CInstance*, CInstance*, int, RValue*) · size=248 · insn=62 */
/* @0x144980 ldr r2, [pc, #0xe8] */
/* @0x144984 mov r1, #16 */
/* @0x144988 ldr r3, [pc, #0xe4] */
/* @0x14498c ldr r2, [pc, r2] */
/* @0x144990 ldr r3, [pc, r3] */
/* @0x144994 ldr r2, [r2] */
/* @0x144998 str lr, [sp, #-0x4]! */
/* @0x14499c sub sp, sp, #124 */
/* @0x1449a0 add r3, r3, r2, lsl #6 */
/* @0x1449a4 vldr s14, [r3, #4] */
/* @0x1449a8 vcvt.f64.f32 d7, s14 */
/* @0x1449ac vldr s13, [r3] */
/* @0x1449b0 vstr d7, [sp] */
/* @0x1449b4 vldr s14, [r3, #8] */
/* @0x1449b8 vcvt.f64.f32 d7, s14 */
/* @0x1449bc vstr d7, [sp, #8] */
/* @0x1449c0 vldr s14, [r3, #12] */
/* @0x1449c4 vcvt.f64.f32 d7, s14 */
/* @0x1449c8 vstr d7, [sp, #16] */
/* @0x1449cc vldr s14, [r3, #16] */
/* @0x1449d0 vcvt.f64.f32 d7, s14 */
/* @0x1449d4 vstr d7, [sp, #24] */
/* @0x1449d8 vldr s14, [r3, #20] */
/* @0x1449dc vcvt.f64.f32 d7, s14 */
/* @0x1449e0 vstr d7, [sp, #32] */
/* @0x1449e4 vldr s14, [r3, #24] */
/* @0x1449e8 vcvt.f64.f32 d7, s14 */
/* @0x1449ec vstr d7, [sp, #40] */
/* @0x1449f0 vldr s14, [r3, #28] */
/* @0x1449f4 vcvt.f64.f32 d7, s14 */
/* @0x1449f8 vstr d7, [sp, #48] */
/* @0x1449fc vldr s14, [r3, #32] */
/* @0x144a00 vcvt.f64.f32 d7, s14 */
/* @0x144a04 vstr d7, [sp, #56] */
/* @0x144a08 vldr s14, [r3, #36] */
/* @0x144a0c vcvt.f64.f32 d7, s14 */
/* @0x144a10 vstr d7, [sp, #64] */
/* @0x144a14 vldr s14, [r3, #40] */
/* @0x144a18 vcvt.f64.f32 d7, s14 */
/* @0x144a1c vstr d7, [sp, #72] */
/* @0x144a20 vldr s14, [r3, #44] */
/* @0x144a24 vcvt.f64.f32 d7, s14 */
/* @0x144a28 vstr d7, [sp, #80] */
/* @0x144a2c vldr s14, [r3, #48] */
/* @0x144a30 vcvt.f64.f32 d7, s14 */
/* @0x144a34 vstr d7, [sp, #88] */
/* @0x144a38 vldr s14, [r3, #52] */
/* @0x144a3c vcvt.f64.f32 d7, s14 */
/* @0x144a40 vstr d7, [sp, #96] */
/* @0x144a44 vldr s14, [r3, #56] */
/* @0x144a48 vcvt.f64.f32 d7, s14 */
/* @0x144a4c vcvt.f64.f32 d5, s13 */
/* @0x144a50 vstr d7, [sp, #104] */
/* @0x144a54 vldr s14, [r3, #60] */
/* @0x144a58 vcvt.f64.f32 d7, s14 */
/* @0x144a5c vmov r2, r3, d5 */
/* @0x144a60 vstr d7, [sp, #112] */
/* @0x144a64 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x144a68 add sp, sp, #124 */
/* @0x144a6c ldr pc, [sp], #4 */
/* @0x144a70 eoreq r10, r10, r8, ror r12 */
/* @0x144a74 eoreq r10, r10, r8, ror r12 */

/* ── FUNC 0x144a78 · F_D3DBuildMatrixIdentity(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x144a78 push {r4, r5, lr} */
/* @0x144a7c sub sp, sp, #124 */
/* @0x144a80 mov r4, #0 */
/* @0x144a84 mov r5, #0 */
/* @0x144a88 mov r2, #0 */
/* @0x144a8c mov r1, #16 */
/* @0x144a90 strd r4, r5, [sp] */
/* @0x144a94 mov r3, #0 */
/* @0x144a98 strd r4, r5, [sp, #8] */
/* @0x144a9c movt r3, #0x3ff0 */
/* @0x144aa0 strd r4, r5, [sp, #16] */
/* @0x144aa4 strd r4, r5, [sp, #24] */
/* @0x144aa8 strd r4, r5, [sp, #40] */
/* @0x144aac strd r4, r5, [sp, #48] */
/* @0x144ab0 strd r4, r5, [sp, #56] */
/* @0x144ab4 strd r4, r5, [sp, #64] */
/* @0x144ab8 strd r4, r5, [sp, #80] */
/* @0x144abc strd r4, r5, [sp, #88] */
/* @0x144ac0 strd r4, r5, [sp, #96] */
/* @0x144ac4 strd r4, r5, [sp, #104] */
/* @0x144ac8 strd r2, r3, [sp, #32] */
/* @0x144acc strd r2, r3, [sp, #72] */
/* @0x144ad0 strd r2, r3, [sp, #112] */
/* @0x144ad4 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x144ad8 add sp, sp, #124 */
/* @0x144adc pop {r4, r5, pc} */

/* ── FUNC 0x144ae0 · F_D3DBuildMatrixLookat(RValue&, CInstance*, CInstance*, int, RValue*) · size=424 · insn=106 */
/* @0x144ae0 push {r4, r5, r6, r7, lr} */
/* @0x144ae4 vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x144ae8 sub sp, sp, #228 */
/* @0x144aec mov r5, r0 */
/* @0x144af0 mov r1, #0 */
/* @0x144af4 ldr r4, [sp, #0x130] */
/* @0x144af8 mov r0, r4 */
/* @0x144afc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144b00 mov r1, #1 */
/* @0x144b04 mov r7, r0 */
/* @0x144b08 mov r0, r4 */
/* @0x144b0c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144b10 mov r1, #2 */
/* @0x144b14 mov r6, r0 */
/* @0x144b18 mov r0, r4 */
/* @0x144b1c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144b20 mov r1, #3 */
/* @0x144b24 str r7, [sp, #0x7c] */
/* @0x144b28 str r6, [sp, #0x80] */
/* @0x144b2c str r0, [sp, #0x84] */
/* @0x144b30 mov r0, r4 */
/* @0x144b34 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144b38 mov r1, #4 */
/* @0x144b3c mov r7, r0 */
/* @0x144b40 mov r0, r4 */
/* @0x144b44 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144b48 mov r1, #5 */
/* @0x144b4c mov r6, r0 */
/* @0x144b50 mov r0, r4 */
/* @0x144b54 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144b58 mov r1, #6 */
/* @0x144b5c str r7, [sp, #0x88] */
/* @0x144b60 str r6, [sp, #0x8c] */
/* @0x144b64 str r0, [sp, #0x90] */
/* @0x144b68 mov r0, r4 */
/* @0x144b6c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144b70 mov r1, #7 */
/* @0x144b74 mov r7, r0 */
/* @0x144b78 mov r0, r4 */
/* @0x144b7c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144b80 mov r1, #8 */
/* @0x144b84 mov r6, r0 */
/* @0x144b88 mov r0, r4 */
/* @0x144b8c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144b90 add r1, sp, #124 */
/* @0x144b94 add r2, sp, #136 */
/* @0x144b98 add r3, sp, #148 */
/* @0x144b9c str r7, [sp, #0x94] */
/* @0x144ba0 str r6, [sp, #0x98] */
/* @0x144ba4 str r0, [sp, #0x9c] */
/* @0x144ba8 add r0, sp, #160 */
/* @0x144bac bl 0x27acb0 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_> */
/* @0x144bb0 vldr s14, [sp, #164] */
/* @0x144bb4 vcvt.f64.f32 d7, s14 */
/* @0x144bb8 vldr s26, [sp, #168] */
/* @0x144bbc vldr s24, [sp, #172] */
/* @0x144bc0 vldr s22, [sp, #176] */
/* @0x144bc4 vldr s20, [sp, #180] */
/* @0x144bc8 vldr s18, [sp, #184] */
/* @0x144bcc vldr s16, [sp, #188] */
/* @0x144bd0 vldr s0, [sp, #192] */
/* @0x144bd4 vldr s2, [sp, #196] */
/* @0x144bd8 vldr s4, [sp, #200] */
/* @0x144bdc vldr s6, [sp, #204] */
/* @0x144be0 vldr s8, [sp, #208] */
/* @0x144be4 vldr s10, [sp, #212] */
/* @0x144be8 vldr s12, [sp, #216] */
/* @0x144bec vstr d7, [sp] */
/* @0x144bf0 vldr s14, [sp, #220] */
/* @0x144bf4 vcvt.f64.f32 d7, s14 */
/* @0x144bf8 vldr s28, [sp, #160] */
/* @0x144bfc mov r0, r5 */
/* @0x144c00 mov r1, #16 */
/* @0x144c04 vcvt.f64.f32 d0, s0 */
/* @0x144c08 vstr d7, [sp, #112] */
/* @0x144c0c vcvt.f64.f32 d1, s2 */
/* @0x144c10 vstr d0, [sp, #56] */
/* @0x144c14 vcvt.f64.f32 d2, s4 */
/* @0x144c18 vstr d1, [sp, #64] */
/* @0x144c1c vcvt.f64.f32 d3, s6 */
/* @0x144c20 vstr d2, [sp, #72] */
/* @0x144c24 vcvt.f64.f32 d4, s8 */
/* @0x144c28 vstr d3, [sp, #80] */
/* @0x144c2c vcvt.f64.f32 d5, s10 */
/* @0x144c30 vstr d4, [sp, #88] */
/* @0x144c34 vcvt.f64.f32 d6, s12 */
/* @0x144c38 vstr d5, [sp, #96] */
/* @0x144c3c vcvt.f64.f32 d7, s28 */
/* @0x144c40 vstr d6, [sp, #104] */
/* @0x144c44 vcvt.f64.f32 d13, s26 */
/* @0x144c48 vmov r2, r3, d7 */
/* @0x144c4c vcvt.f64.f32 d12, s24 */
/* @0x144c50 vstr d13, [sp, #8] */
/* @0x144c54 vcvt.f64.f32 d11, s22 */
/* @0x144c58 vstr d12, [sp, #16] */
/* @0x144c5c vcvt.f64.f32 d10, s20 */
/* @0x144c60 vstr d11, [sp, #24] */
/* @0x144c64 vcvt.f64.f32 d9, s18 */
/* @0x144c68 vstr d10, [sp, #32] */
/* @0x144c6c vcvt.f64.f32 d8, s16 */
/* @0x144c70 vstr d9, [sp, #40] */
/* @0x144c74 vstr d8, [sp, #48] */
/* @0x144c78 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x144c7c add sp, sp, #228 */
/* @0x144c80 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x144c84 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x144c88 · F_D3DBuildMatrixProjOrtho(RValue&, CInstance*, CInstance*, int, RValue*) · size=320 · insn=80 */
/* @0x144c88 push {r4, r5, r6, r7, r8, lr} */
/* @0x144c8c vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x144c90 sub sp, sp, #184 */
/* @0x144c94 mov r5, r0 */
/* @0x144c98 mov r1, #0 */
/* @0x144c9c ldr r4, [sp, #0x108] */
/* @0x144ca0 mov r0, r4 */
/* @0x144ca4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144ca8 mov r1, #1 */
/* @0x144cac mov r8, r0 */
/* @0x144cb0 mov r0, r4 */
/* @0x144cb4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144cb8 mov r1, #2 */
/* @0x144cbc mov r7, r0 */
/* @0x144cc0 mov r0, r4 */
/* @0x144cc4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144cc8 mov r1, #3 */
/* @0x144ccc mov r6, r0 */
/* @0x144cd0 mov r0, r4 */
/* @0x144cd4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144cd8 mov r1, r8 */
/* @0x144cdc mov r2, r7 */
/* @0x144ce0 mov r3, r6 */
/* @0x144ce4 str r0, [sp] */
/* @0x144ce8 add r0, sp, #120 */
/* @0x144cec bl 0x27b274 <_ZN8yyMatrix7OrthoLHEPS_ffff> */
/* @0x144cf0 vldr s14, [sp, #124] */
/* @0x144cf4 vcvt.f64.f32 d7, s14 */
/* @0x144cf8 vldr s26, [sp, #128] */
/* @0x144cfc vldr s24, [sp, #132] */
/* @0x144d00 vldr s22, [sp, #136] */
/* @0x144d04 vldr s20, [sp, #140] */
/* @0x144d08 vldr s18, [sp, #144] */
/* @0x144d0c vldr s16, [sp, #148] */
/* @0x144d10 vldr s0, [sp, #152] */
/* @0x144d14 vldr s2, [sp, #156] */
/* @0x144d18 vldr s4, [sp, #160] */
/* @0x144d1c vldr s6, [sp, #164] */
/* @0x144d20 vldr s8, [sp, #168] */
/* @0x144d24 vldr s10, [sp, #172] */
/* @0x144d28 vldr s12, [sp, #176] */
/* @0x144d2c vstr d7, [sp] */
/* @0x144d30 vldr s14, [sp, #180] */
/* @0x144d34 vcvt.f64.f32 d7, s14 */
/* @0x144d38 vldr s28, [sp, #120] */
/* @0x144d3c mov r0, r5 */
/* @0x144d40 mov r1, #16 */
/* @0x144d44 vcvt.f64.f32 d0, s0 */
/* @0x144d48 vstr d7, [sp, #112] */
/* @0x144d4c vcvt.f64.f32 d1, s2 */
/* @0x144d50 vstr d0, [sp, #56] */
/* @0x144d54 vcvt.f64.f32 d2, s4 */
/* @0x144d58 vstr d1, [sp, #64] */
/* @0x144d5c vcvt.f64.f32 d3, s6 */
/* @0x144d60 vstr d2, [sp, #72] */
/* @0x144d64 vcvt.f64.f32 d4, s8 */
/* @0x144d68 vstr d3, [sp, #80] */
/* @0x144d6c vcvt.f64.f32 d5, s10 */
/* @0x144d70 vstr d4, [sp, #88] */
/* @0x144d74 vcvt.f64.f32 d6, s12 */
/* @0x144d78 vstr d5, [sp, #96] */
/* @0x144d7c vcvt.f64.f32 d7, s28 */
/* @0x144d80 vstr d6, [sp, #104] */
/* @0x144d84 vcvt.f64.f32 d13, s26 */
/* @0x144d88 vmov r2, r3, d7 */
/* @0x144d8c vcvt.f64.f32 d12, s24 */
/* @0x144d90 vstr d13, [sp, #8] */
/* @0x144d94 vcvt.f64.f32 d11, s22 */
/* @0x144d98 vstr d12, [sp, #16] */
/* @0x144d9c vcvt.f64.f32 d10, s20 */
/* @0x144da0 vstr d11, [sp, #24] */
/* @0x144da4 vcvt.f64.f32 d9, s18 */
/* @0x144da8 vstr d10, [sp, #32] */
/* @0x144dac vcvt.f64.f32 d8, s16 */
/* @0x144db0 vstr d9, [sp, #40] */
/* @0x144db4 vstr d8, [sp, #48] */
/* @0x144db8 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x144dbc add sp, sp, #184 */
/* @0x144dc0 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x144dc4 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x144dc8 · F_D3DTransformVertex(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x144dc8 push {r4, r5, lr} */
/* @0x144dcc sub sp, sp, #36 */
/* @0x144dd0 mov r5, r0 */
/* @0x144dd4 mov r1, #0 */
/* @0x144dd8 ldr r4, [sp, #0x30] */
/* @0x144ddc mov r0, r4 */
/* @0x144de0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144de4 mov r1, #1 */
/* @0x144de8 str r0, [sp, #0x14] */
/* @0x144dec mov r0, r4 */
/* @0x144df0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144df4 mov r1, #2 */
/* @0x144df8 str r0, [sp, #0x18] */
/* @0x144dfc mov r0, r4 */
/* @0x144e00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144e04 add r1, sp, #24 */
/* @0x144e08 add r2, sp, #28 */
/* @0x144e0c str r0, [sp, #0x1c] */
/* @0x144e10 add r0, sp, #20 */
/* @0x144e14 bl 0x163c3c <_Z21GR_3D_TransformVertexRfS_S_> */
/* @0x144e18 vldr s14, [sp, #28] */
/* @0x144e1c vcvt.f64.f32 d7, s14 */
/* @0x144e20 vldr s12, [sp, #24] */
/* @0x144e24 vldr s11, [sp, #20] */
/* @0x144e28 mov r0, r5 */
/* @0x144e2c mov r1, #3 */
/* @0x144e30 vcvt.f64.f32 d6, s12 */
/* @0x144e34 vstr d7, [sp, #8] */
/* @0x144e38 vcvt.f64.f32 d7, s11 */
/* @0x144e3c vstr d6, [sp] */
/* @0x144e40 vmov r2, r3, d7 */
/* @0x144e44 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x144e48 add sp, sp, #36 */
/* @0x144e4c pop {r4, r5, pc} */

/* ── FUNC 0x144e50 · F_D3DTransformSetIdentity(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x144e50 b 0x16369c <_Z28GR_3D_Transform_Set_Identityv> */

/* ── FUNC 0x144e54 · F_D3DTransformSetTranslation(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x144e54 push {r4, r5, r6, lr} */
/* @0x144e58 mov r1, #0 */
/* @0x144e5c ldr r4, [sp, #0x10] */
/* @0x144e60 mov r0, r4 */
/* @0x144e64 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144e68 mov r1, #1 */
/* @0x144e6c mov r6, r0 */
/* @0x144e70 mov r0, r4 */
/* @0x144e74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144e78 mov r1, #2 */
/* @0x144e7c mov r5, r0 */
/* @0x144e80 mov r0, r4 */
/* @0x144e84 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144e88 mov r1, r5 */
/* @0x144e8c mov r2, r0 */
/* @0x144e90 mov r0, r6 */
/* @0x144e94 pop {r4, r5, r6, lr} */
/* @0x144e98 b 0x163704 <_Z31GR_3D_Transform_Set_Translationfff> */

/* ── FUNC 0x144e9c · F_D3DTransformSetScaling(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x144e9c push {r4, r5, r6, lr} */
/* @0x144ea0 mov r1, #0 */
/* @0x144ea4 ldr r4, [sp, #0x10] */
/* @0x144ea8 mov r0, r4 */
/* @0x144eac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144eb0 mov r1, #1 */
/* @0x144eb4 mov r6, r0 */
/* @0x144eb8 mov r0, r4 */
/* @0x144ebc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144ec0 mov r1, #2 */
/* @0x144ec4 mov r5, r0 */
/* @0x144ec8 mov r0, r4 */
/* @0x144ecc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144ed0 mov r1, r5 */
/* @0x144ed4 mov r2, r0 */
/* @0x144ed8 mov r0, r6 */
/* @0x144edc pop {r4, r5, r6, lr} */
/* @0x144ee0 b 0x16376c <_Z27GR_3D_Transform_Set_Scalingfff> */

/* ── FUNC 0x144ee4 · F_D3DTransformSetRotationX(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x144ee4 push {r3, lr} */
/* @0x144ee8 mov r1, #0 */
/* @0x144eec ldr r0, [sp, #0x8] */
/* @0x144ef0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144ef4 pop {r3, lr} */
/* @0x144ef8 b 0x1637d4 <_Z30GR_3D_Transform_Set_Rotation_Xf> */

/* ── FUNC 0x144efc · F_D3DTransformSetRotationY(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x144efc push {r3, lr} */
/* @0x144f00 mov r1, #0 */
/* @0x144f04 ldr r0, [sp, #0x8] */
/* @0x144f08 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144f0c pop {r3, lr} */
/* @0x144f10 b 0x163800 <_Z30GR_3D_Transform_Set_Rotation_Yf> */

/* ── FUNC 0x144f14 · F_D3DTransformSetRotationZ(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x144f14 push {r3, lr} */
/* @0x144f18 mov r1, #0 */
/* @0x144f1c ldr r0, [sp, #0x8] */
/* @0x144f20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144f24 pop {r3, lr} */
/* @0x144f28 b 0x16382c <_Z30GR_3D_Transform_Set_Rotation_Zf> */

/* ── FUNC 0x144f2c · F_D3DTransformSetRotationAxis(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x144f2c push {r4, r5, r6, r7, r8, lr} */
/* @0x144f30 mov r1, #0 */
/* @0x144f34 ldr r4, [sp, #0x18] */
/* @0x144f38 mov r0, r4 */
/* @0x144f3c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144f40 mov r1, #1 */
/* @0x144f44 mov r7, r0 */
/* @0x144f48 mov r0, r4 */
/* @0x144f4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144f50 mov r1, #2 */
/* @0x144f54 mov r6, r0 */
/* @0x144f58 mov r0, r4 */
/* @0x144f5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144f60 mov r1, #3 */
/* @0x144f64 mov r5, r0 */
/* @0x144f68 mov r0, r4 */
/* @0x144f6c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144f70 mov r1, r6 */
/* @0x144f74 mov r2, r5 */
/* @0x144f78 mov r3, r0 */
/* @0x144f7c mov r0, r7 */
/* @0x144f80 pop {r4, r5, r6, r7, r8, lr} */
/* @0x144f84 b 0x163858 <_Z33GR_3D_Transform_Set_Rotation_Axisffff> */

/* ── FUNC 0x144f88 · F_D3DTransformAddTranslation(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x144f88 push {r4, r5, r6, lr} */
/* @0x144f8c mov r1, #0 */
/* @0x144f90 ldr r4, [sp, #0x10] */
/* @0x144f94 mov r0, r4 */
/* @0x144f98 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144f9c mov r1, #1 */
/* @0x144fa0 mov r6, r0 */
/* @0x144fa4 mov r0, r4 */
/* @0x144fa8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144fac mov r1, #2 */
/* @0x144fb0 mov r5, r0 */
/* @0x144fb4 mov r0, r4 */
/* @0x144fb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144fbc mov r1, r5 */
/* @0x144fc0 mov r2, r0 */
/* @0x144fc4 mov r0, r6 */
/* @0x144fc8 pop {r4, r5, r6, lr} */
/* @0x144fcc b 0x163898 <_Z31GR_3D_Transform_Add_Translationfff> */

/* ── FUNC 0x144fd0 · F_D3DTransformAddScaling(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x144fd0 push {r4, r5, r6, lr} */
/* @0x144fd4 mov r1, #0 */
/* @0x144fd8 ldr r4, [sp, #0x10] */
/* @0x144fdc mov r0, r4 */
/* @0x144fe0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144fe4 mov r1, #1 */
/* @0x144fe8 mov r6, r0 */
/* @0x144fec mov r0, r4 */
/* @0x144ff0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144ff4 mov r1, #2 */
/* @0x144ff8 mov r5, r0 */
/* @0x144ffc mov r0, r4 */
/* @0x145000 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145004 mov r1, r5 */
/* @0x145008 mov r2, r0 */
/* @0x14500c mov r0, r6 */
/* @0x145010 pop {r4, r5, r6, lr} */
/* @0x145014 b 0x163924 <_Z27GR_3D_Transform_Add_Scalingfff> */

/* ── FUNC 0x145018 · F_D3DTransformAddRotationX(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x145018 push {r3, lr} */
/* @0x14501c mov r1, #0 */
/* @0x145020 ldr r0, [sp, #0x8] */
/* @0x145024 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145028 pop {r3, lr} */
/* @0x14502c b 0x1639ac <_Z30GR_3D_Transform_Add_Rotation_Xf> */

/* ── FUNC 0x145030 · F_D3DTransformAddRotationY(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x145030 push {r3, lr} */
/* @0x145034 mov r1, #0 */
/* @0x145038 ldr r0, [sp, #0x8] */
/* @0x14503c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145040 pop {r3, lr} */
/* @0x145044 b 0x1639fc <_Z30GR_3D_Transform_Add_Rotation_Yf> */

/* ── FUNC 0x145048 · F_D3DTransformAddRotationZ(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x145048 push {r3, lr} */
/* @0x14504c mov r1, #0 */
/* @0x145050 ldr r0, [sp, #0x8] */
/* @0x145054 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145058 pop {r3, lr} */
/* @0x14505c b 0x163a4c <_Z30GR_3D_Transform_Add_Rotation_Zf> */

/* ── FUNC 0x145060 · F_D3DTransformAddRotationAxis(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x145060 push {r4, r5, r6, r7, r8, lr} */
/* @0x145064 mov r1, #0 */
/* @0x145068 ldr r4, [sp, #0x18] */
/* @0x14506c mov r0, r4 */
/* @0x145070 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145074 mov r1, #1 */
/* @0x145078 mov r7, r0 */
/* @0x14507c mov r0, r4 */
/* @0x145080 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145084 mov r1, #2 */
/* @0x145088 mov r6, r0 */
/* @0x14508c mov r0, r4 */
/* @0x145090 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145094 mov r1, #3 */
/* @0x145098 mov r5, r0 */
/* @0x14509c mov r0, r4 */
/* @0x1450a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1450a4 mov r1, r6 */
/* @0x1450a8 mov r2, r5 */
/* @0x1450ac mov r3, r0 */
/* @0x1450b0 mov r0, r7 */
/* @0x1450b4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1450b8 b 0x163a9c <_Z33GR_3D_Transform_Add_Rotation_Axisffff> */

/* ── FUNC 0x1450bc · F_D3DTransformStackClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x1450bc b 0x163b00 <_Z27GR_3D_Transform_Stack_Clearv> */

/* ── FUNC 0x1450c0 · F_D3DTransformStackEmpty(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1450c0 push {r4, lr} */
/* @0x1450c4 mov r3, #0 */
/* @0x1450c8 str r3, [r0, #0xc] */
/* @0x1450cc mov r4, r0 */
/* @0x1450d0 bl 0x163b18 <_Z27GR_3D_Transform_Stack_Emptyv> */
/* @0x1450d4 vmov s15, r0 */
/* @0x1450d8 vcvt.f64.u32 d7, s15 */
/* @0x1450dc vmov r0, r1, d7 */
/* @0x1450e0 vmov r2, s14 */
/* @0x1450e4 mov r3, r1 */
/* @0x1450e8 stm r4, {r2, r3} */
/* @0x1450ec pop {r4, pc} */

/* ── FUNC 0x1450f0 · F_D3DTransformStackPush(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1450f0 push {r4, lr} */
/* @0x1450f4 mov r3, #0 */
/* @0x1450f8 str r3, [r0, #0xc] */
/* @0x1450fc mov r4, r0 */
/* @0x145100 bl 0x163b30 <_Z26GR_3D_Transform_Stack_Pushv> */
/* @0x145104 vmov s15, r0 */
/* @0x145108 vcvt.f64.u32 d7, s15 */
/* @0x14510c vmov r0, r1, d7 */
/* @0x145110 vmov r2, s14 */
/* @0x145114 mov r3, r1 */
/* @0x145118 stm r4, {r2, r3} */
/* @0x14511c pop {r4, pc} */

/* ── FUNC 0x145120 · F_D3DTransformStackPop(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x145120 push {r4, lr} */
/* @0x145124 mov r3, #0 */
/* @0x145128 str r3, [r0, #0xc] */
/* @0x14512c mov r4, r0 */
/* @0x145130 bl 0x163b7c <_Z25GR_3D_Transform_Stack_Popv> */
/* @0x145134 vmov s15, r0 */
/* @0x145138 vcvt.f64.u32 d7, s15 */
/* @0x14513c vmov r0, r1, d7 */
/* @0x145140 vmov r2, s14 */
/* @0x145144 mov r3, r1 */
/* @0x145148 stm r4, {r2, r3} */
/* @0x14514c pop {r4, pc} */

/* ── FUNC 0x145150 · F_D3DTransformStackTop(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x145150 push {r4, lr} */
/* @0x145154 mov r3, #0 */
/* @0x145158 str r3, [r0, #0xc] */
/* @0x14515c mov r4, r0 */
/* @0x145160 bl 0x163bd0 <_Z25GR_3D_Transform_Stack_Topv> */
/* @0x145164 vmov s15, r0 */
/* @0x145168 vcvt.f64.u32 d7, s15 */
/* @0x14516c vmov r0, r1, d7 */
/* @0x145170 vmov r2, s14 */
/* @0x145174 mov r3, r1 */
/* @0x145178 stm r4, {r2, r3} */
/* @0x14517c pop {r4, pc} */

/* ── FUNC 0x145180 · F_D3DTransformStackDiscard(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x145180 push {r4, lr} */
/* @0x145184 mov r3, #0 */
/* @0x145188 str r3, [r0, #0xc] */
/* @0x14518c mov r4, r0 */
/* @0x145190 bl 0x163c14 <_Z29GR_3D_Transform_Stack_Discardv> */
/* @0x145194 vmov s15, r0 */
/* @0x145198 vcvt.f64.u32 d7, s15 */
/* @0x14519c vmov r0, r1, d7 */
/* @0x1451a0 vmov r2, s14 */
/* @0x1451a4 mov r3, r1 */
/* @0x1451a8 stm r4, {r2, r3} */
/* @0x1451ac pop {r4, pc} */

/* ── FUNC 0x1451b0 · F_D3DLightSetAmbient(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x1451b0 push {r3, lr} */
/* @0x1451b4 mov r1, #0 */
/* @0x1451b8 ldr r0, [sp, #0x8] */
/* @0x1451bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1451c0 ldr r3, [pc, #0xc] */
/* @0x1451c4 ldr r3, [pc, r3] */
/* @0x1451c8 str r0, [r3] */
/* @0x1451cc pop {r3, lr} */
/* @0x1451d0 b 0x17f5fc <_Z17GR_3D_Set_Ambientj> */
/* @0x1451d4 eoreq r10, r10, r8, asr #8 */
