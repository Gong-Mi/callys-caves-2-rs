/* libyoyo.so 覆盖卡组 0079
 * 函数 0x1451d8..0x146598，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1451d8 · F_D3DModelCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1451d8 push {r4, lr} */
/* @0x1451dc mov r3, #0 */
/* @0x1451e0 str r3, [r0, #0xc] */
/* @0x1451e4 mov r4, r0 */
/* @0x1451e8 bl 0x1650c0 <_Z13GR_3DM_Createv> */
/* @0x1451ec vmov s15, r0 */
/* @0x1451f0 vcvt.f64.s32 d7, s15 */
/* @0x1451f4 vmov r0, r1, d7 */
/* @0x1451f8 vmov r2, s14 */
/* @0x1451fc mov r3, r1 */
/* @0x145200 stm r4, {r2, r3} */
/* @0x145204 pop {r4, pc} */

/* ── FUNC 0x145208 · F_D3DModelDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x145208 push {r3, lr} */
/* @0x14520c mov r1, #0 */
/* @0x145210 ldr r0, [sp, #0x8] */
/* @0x145214 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145218 pop {r3, lr} */
/* @0x14521c b 0x1651b0 <_Z14GR_3DM_Destroyi> */

/* ── FUNC 0x145220 · F_D3DModelClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x145220 push {r3, lr} */
/* @0x145224 mov r1, #0 */
/* @0x145228 ldr r0, [sp, #0x8] */
/* @0x14522c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145230 pop {r3, lr} */
/* @0x145234 b 0x165210 <_Z12GR_3DM_Cleari> */

/* ── FUNC 0x145238 · F_D3DModelLoad(RValue&, CInstance*, CInstance*, int, RValue*) · size=252 · insn=63 */
/* @0x145238 push {r4, r5, r6, r7, lr} */
/* @0x14523c sub sp, sp, #1024 */
/* @0x145240 ldr r4, [pc, #0xe0] */
/* @0x145244 sub sp, sp, #12 */
/* @0x145248 mov r1, #1 */
/* @0x14524c mov r5, r0 */
/* @0x145250 ldr r4, [pc, r4] */
/* @0x145254 ldr r6, [sp, #0x420] */
/* @0x145258 ldr r3, [r4] */
/* @0x14525c mov r0, r6 */
/* @0x145260 str r3, [sp, #0x404] */
/* @0x145264 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x145268 mov r7, r0 */
/* @0x14526c bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x145270 cmp r0, #0 */
/* @0x145274 beq 0x1452cc <_Z14F_D3DModelLoadR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x145278 mov r2, r7 */
/* @0x14527c add r7, sp, #4 */
/* @0x145280 mov r1, #1024 */
/* @0x145284 mov r0, r7 */
/* @0x145288 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x14528c mov r1, #0 */
/* @0x145290 mov r0, r6 */
/* @0x145294 mov r3, r1 */
/* @0x145298 str r1, [r5] */
/* @0x14529c movt r3, #0x3ff0 */
/* @0x1452a0 str r3, [r5, #0x4] */
/* @0x1452a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1452a8 mov r1, r7 */
/* @0x1452ac bl 0x165250 <_Z19GR_3DM_LoadFromFileiPKc> */
/* @0x1452b0 ldr r2, [sp, #0x404] */
/* @0x1452b4 ldr r3, [r4] */
/* @0x1452b8 cmp r2, r3 */
/* @0x1452bc bne 0x145324 <_Z14F_D3DModelLoadR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x1452c0 add sp, sp, #1024 */
/* @0x1452c4 add sp, sp, #12 */
/* @0x1452c8 pop {r4, r5, r6, r7, pc} */
/* @0x1452cc mov r0, r7 */
/* @0x1452d0 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x1452d4 cmp r0, #0 */
/* @0x1452d8 bne 0x14530c <_Z14F_D3DModelLoadR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x1452dc ldr r3, [pc, #0x48] */
/* @0x1452e0 mov r2, r7 */
/* @0x1452e4 str r0, [r5] */
/* @0x1452e8 ldr r3, [pc, r3] */
/* @0x1452ec str r0, [r5, #0x4] */
/* @0x1452f0 ldr r1, [pc, #0x38] */
/* @0x1452f4 ldr r0, [r3] */
/* @0x1452f8 add r1, pc, r1 */
/* @0x1452fc ldr r3, [r0] */
/* @0x145300 ldr r3, [r3, #0xc] */
/* @0x145304 blx r3 */
/* @0x145308 b 0x1452b0 <_Z14F_D3DModelLoadR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x14530c mov r2, r7 */
/* @0x145310 add r7, sp, #4 */
/* @0x145314 mov r1, #1024 */
/* @0x145318 mov r0, r7 */
/* @0x14531c bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x145320 b 0x14528c <_Z14F_D3DModelLoadR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x145324 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x145328 eoreq r8, r10, r0, lsl #14 */
/* @0x14532c eoreq r8, r10, r12, lsr #8 */
/* @0x145330 ldrheq r12, [pc], -r0 */

/* ── FUNC 0x145334 · F_D3DModelLoadBuffer(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x145334 push {r3, r4, r5, lr} */
/* @0x145338 ldr r3, [pc, #0x44] */
/* @0x14533c ldr r4, [sp, #0x10] */
/* @0x145340 ldr r3, [pc, r3] */
/* @0x145344 ldr r1, [pc, #0x3c] */
/* @0x145348 ldr r0, [r3] */
/* @0x14534c add r1, pc, r1 */
/* @0x145350 ldr r3, [r0] */
/* @0x145354 ldr r3, [r3, #0xc] */
/* @0x145358 blx r3 */
/* @0x14535c mov r0, r4 */
/* @0x145360 mov r1, #1 */
/* @0x145364 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145368 mov r1, #0 */
/* @0x14536c mov r5, r0 */
/* @0x145370 mov r0, r4 */
/* @0x145374 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145378 mov r1, r5 */
/* @0x14537c pop {r3, r4, r5, lr} */
/* @0x145380 b 0x165298 <_Z21GR_3DM_LoadFromBufferii> */
/* @0x145384 .word 0x002a83d4 */
/* @0x145388 andseq r12, pc, r8, lsl #5 */

/* ── FUNC 0x14538c · F_D3DModelSave(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x14538c push {r4, r5, r6, lr} */
/* @0x145390 sub sp, sp, #1024 */
/* @0x145394 ldr r4, [pc, #0x6c] */
/* @0x145398 sub sp, sp, #8 */
/* @0x14539c mov r1, #1 */
/* @0x1453a0 add r5, sp, #4 */
/* @0x1453a4 ldr r4, [pc, r4] */
/* @0x1453a8 ldr r6, [sp, #0x418] */
/* @0x1453ac ldr r3, [r4] */
/* @0x1453b0 mov r0, r6 */
/* @0x1453b4 str r3, [sp, #0x404] */
/* @0x1453b8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1453bc mov r1, #1024 */
/* @0x1453c0 mov r2, r0 */
/* @0x1453c4 mov r0, r5 */
/* @0x1453c8 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x1453cc mov r0, r5 */
/* @0x1453d0 bl 0x13ad20 <_Z24EnsureDirectoryIsCreatedPKc> */
/* @0x1453d4 mov r1, #0 */
/* @0x1453d8 mov r0, r6 */
/* @0x1453dc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1453e0 mov r1, r5 */
/* @0x1453e4 bl 0x1652e0 <_Z17GR_3DM_SaveToFileiPKc> */
/* @0x1453e8 ldr r2, [sp, #0x404] */
/* @0x1453ec ldr r3, [r4] */
/* @0x1453f0 cmp r2, r3 */
/* @0x1453f4 bne 0x145404 <_Z14F_D3DModelSaveR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1453f8 add sp, sp, #1024 */
/* @0x1453fc add sp, sp, #8 */
/* @0x145400 pop {r4, r5, r6, pc} */
/* @0x145404 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x145408 eoreq r8, r10, r12, lsr #11 */

/* ── FUNC 0x14540c · F_D3DModelSaveBuffer(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x14540c push {r3, r4, r5, lr} */
/* @0x145410 mov r1, #0 */
/* @0x145414 ldr r4, [sp, #0x10] */
/* @0x145418 mov r0, r4 */
/* @0x14541c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145420 mov r1, #1 */
/* @0x145424 mov r5, r0 */
/* @0x145428 mov r0, r4 */
/* @0x14542c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145430 mov r1, r0 */
/* @0x145434 mov r0, r5 */
/* @0x145438 pop {r3, r4, r5, lr} */
/* @0x14543c b 0x165328 <_Z19GR_3DM_SaveToBufferii> */

/* ── FUNC 0x145440 · F_D3DModelDraw(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x145440 push {r4, r5, r6, r7, r8, lr} */
/* @0x145444 mov r1, #4 */
/* @0x145448 ldr r4, [sp, #0x18] */
/* @0x14544c mov r0, r4 */
/* @0x145450 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei> */
/* @0x145454 mov r1, #0 */
/* @0x145458 mov r8, r0 */
/* @0x14545c mov r0, r4 */
/* @0x145460 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145464 mov r1, #1 */
/* @0x145468 mov r7, r0 */
/* @0x14546c mov r0, r4 */
/* @0x145470 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145474 mov r1, #2 */
/* @0x145478 mov r6, r0 */
/* @0x14547c mov r0, r4 */
/* @0x145480 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145484 mov r1, #3 */
/* @0x145488 mov r5, r0 */
/* @0x14548c mov r0, r4 */
/* @0x145490 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145494 str r8, [sp, #0x18] */
/* @0x145498 mov r1, r6 */
/* @0x14549c mov r2, r5 */
/* @0x1454a0 mov r3, r0 */
/* @0x1454a4 mov r0, r7 */
/* @0x1454a8 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1454ac b 0x165370 <_Z11GR_3DM_Drawifffi> */

/* ── FUNC 0x1454b0 · F_D3DModelPrimitiveBegin(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1454b0 push {r3, r4, r5, lr} */
/* @0x1454b4 mov r1, #0 */
/* @0x1454b8 ldr r4, [sp, #0x10] */
/* @0x1454bc mov r0, r4 */
/* @0x1454c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1454c4 mov r1, #1 */
/* @0x1454c8 mov r5, r0 */
/* @0x1454cc mov r0, r4 */
/* @0x1454d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1454d4 mov r1, r0 */
/* @0x1454d8 mov r0, r5 */
/* @0x1454dc pop {r3, r4, r5, lr} */
/* @0x1454e0 b 0x1653c0 <_Z22GR_3DM_Primitive_Beginii> */

/* ── FUNC 0x1454e4 · F_D3DModelPrimitiveEnd(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x1454e4 push {r3, lr} */
/* @0x1454e8 mov r1, #0 */
/* @0x1454ec ldr r0, [sp, #0x8] */
/* @0x1454f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1454f4 pop {r3, lr} */
/* @0x1454f8 b 0x1658d0 <_Z20GR_3DM_Primitive_Endi> */

/* ── FUNC 0x1454fc · F_D3DModelVertex(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x1454fc push {r4, r5, r6, r7, r8, lr} */
/* @0x145500 mov r1, #0 */
/* @0x145504 ldr r4, [sp, #0x18] */
/* @0x145508 mov r0, r4 */
/* @0x14550c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145510 mov r1, #1 */
/* @0x145514 mov r7, r0 */
/* @0x145518 mov r0, r4 */
/* @0x14551c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145520 mov r1, #2 */
/* @0x145524 mov r6, r0 */
/* @0x145528 mov r0, r4 */
/* @0x14552c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145530 mov r1, #3 */
/* @0x145534 mov r5, r0 */
/* @0x145538 mov r0, r4 */
/* @0x14553c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145540 mov r1, r6 */
/* @0x145544 mov r2, r5 */
/* @0x145548 mov r3, r0 */
/* @0x14554c mov r0, r7 */
/* @0x145550 pop {r4, r5, r6, r7, r8, lr} */
/* @0x145554 b 0x165444 <_Z13GR_3DM_Vertexifff> */

/* ── FUNC 0x145558 · F_D3DModelVertexColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x145558 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x14555c sub sp, sp, #12 */
/* @0x145560 mov r1, #0 */
/* @0x145564 ldr r4, [sp, #0x28] */
/* @0x145568 mov r0, r4 */
/* @0x14556c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145570 mov r1, #1 */
/* @0x145574 mov r5, r0 */
/* @0x145578 mov r0, r4 */
/* @0x14557c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145580 mov r1, #2 */
/* @0x145584 mov r8, r0 */
/* @0x145588 mov r0, r4 */
/* @0x14558c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145590 mov r1, #3 */
/* @0x145594 mov r7, r0 */
/* @0x145598 mov r0, r4 */
/* @0x14559c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1455a0 mov r1, #4 */
/* @0x1455a4 mov r6, r0 */
/* @0x1455a8 mov r0, r4 */
/* @0x1455ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1455b0 mov r1, #5 */
/* @0x1455b4 mov r9, r0 */
/* @0x1455b8 mov r0, r4 */
/* @0x1455bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1455c0 str r9, [sp] */
/* @0x1455c4 mov r1, r8 */
/* @0x1455c8 mov r2, r7 */
/* @0x1455cc mov r3, r6 */
/* @0x1455d0 str r0, [sp, #0x4] */
/* @0x1455d4 mov r0, r5 */
/* @0x1455d8 bl 0x1654c8 <_Z19GR_3DM_Vertex_Colorifffjf> */
/* @0x1455dc add sp, sp, #12 */
/* @0x1455e0 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x1455e4 · F_D3DModelVertexTexture(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1455e4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1455e8 sub sp, sp, #12 */
/* @0x1455ec mov r1, #0 */
/* @0x1455f0 ldr r4, [sp, #0x28] */
/* @0x1455f4 mov r0, r4 */
/* @0x1455f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1455fc mov r1, #1 */
/* @0x145600 mov r5, r0 */
/* @0x145604 mov r0, r4 */
/* @0x145608 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14560c mov r1, #2 */
/* @0x145610 mov r8, r0 */
/* @0x145614 mov r0, r4 */
/* @0x145618 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14561c mov r1, #3 */
/* @0x145620 mov r7, r0 */
/* @0x145624 mov r0, r4 */
/* @0x145628 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14562c mov r1, #4 */
/* @0x145630 mov r6, r0 */
/* @0x145634 mov r0, r4 */
/* @0x145638 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14563c mov r1, #5 */
/* @0x145640 mov r9, r0 */
/* @0x145644 mov r0, r4 */
/* @0x145648 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14564c str r9, [sp] */
/* @0x145650 mov r1, r8 */
/* @0x145654 mov r2, r7 */
/* @0x145658 mov r3, r6 */
/* @0x14565c str r0, [sp, #0x4] */
/* @0x145660 mov r0, r5 */
/* @0x145664 bl 0x165554 <_Z21GR_3DM_Vertex_Textureifffff> */
/* @0x145668 add sp, sp, #12 */
/* @0x14566c pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x145670 · F_D3DModelVertexTextureColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0x145670 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x145674 sub sp, sp, #20 */
/* @0x145678 mov r1, #0 */
/* @0x14567c ldr r4, [sp, #0x38] */
/* @0x145680 mov r0, r4 */
/* @0x145684 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145688 mov r1, #1 */
/* @0x14568c mov r5, r0 */
/* @0x145690 mov r0, r4 */
/* @0x145694 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145698 mov r1, #2 */
/* @0x14569c mov r8, r0 */
/* @0x1456a0 mov r0, r4 */
/* @0x1456a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1456a8 mov r1, #3 */
/* @0x1456ac mov r7, r0 */
/* @0x1456b0 mov r0, r4 */
/* @0x1456b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1456b8 mov r1, #4 */
/* @0x1456bc mov r6, r0 */
/* @0x1456c0 mov r0, r4 */
/* @0x1456c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1456c8 mov r1, #5 */
/* @0x1456cc mov r11, r0 */
/* @0x1456d0 mov r0, r4 */
/* @0x1456d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1456d8 mov r1, #6 */
/* @0x1456dc mov r10, r0 */
/* @0x1456e0 mov r0, r4 */
/* @0x1456e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1456e8 mov r1, #7 */
/* @0x1456ec mov r9, r0 */
/* @0x1456f0 mov r0, r4 */
/* @0x1456f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1456f8 str r11, [sp] */
/* @0x1456fc str r10, [sp, #0x4] */
/* @0x145700 mov r1, r8 */
/* @0x145704 str r9, [sp, #0x8] */
/* @0x145708 mov r2, r7 */
/* @0x14570c mov r3, r6 */
/* @0x145710 str r0, [sp, #0xc] */
/* @0x145714 mov r0, r5 */
/* @0x145718 bl 0x1655e0 <_Z27GR_3DM_Vertex_Texture_Colorifffffjf> */
/* @0x14571c add sp, sp, #20 */
/* @0x145720 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x145724 · F_D3DModelVertexNormal(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x145724 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x145728 sub sp, sp, #16 */
/* @0x14572c mov r1, #0 */
/* @0x145730 ldr r4, [sp, #0x30] */
/* @0x145734 mov r0, r4 */
/* @0x145738 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14573c mov r1, #1 */
/* @0x145740 mov r5, r0 */
/* @0x145744 mov r0, r4 */
/* @0x145748 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14574c mov r1, #2 */
/* @0x145750 mov r8, r0 */
/* @0x145754 mov r0, r4 */
/* @0x145758 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14575c mov r1, #3 */
/* @0x145760 mov r7, r0 */
/* @0x145764 mov r0, r4 */
/* @0x145768 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14576c mov r1, #4 */
/* @0x145770 mov r6, r0 */
/* @0x145774 mov r0, r4 */
/* @0x145778 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14577c mov r1, #5 */
/* @0x145780 mov r10, r0 */
/* @0x145784 mov r0, r4 */
/* @0x145788 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14578c mov r1, #6 */
/* @0x145790 mov r9, r0 */
/* @0x145794 mov r0, r4 */
/* @0x145798 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14579c str r10, [sp] */
/* @0x1457a0 str r9, [sp, #0x4] */
/* @0x1457a4 mov r1, r8 */
/* @0x1457a8 mov r2, r7 */
/* @0x1457ac mov r3, r6 */
/* @0x1457b0 str r0, [sp, #0x8] */
/* @0x1457b4 mov r0, r5 */
/* @0x1457b8 bl 0x165674 <_Z15GR_3DM_Vertex_Niffffff> */
/* @0x1457bc add sp, sp, #16 */
/* @0x1457c0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x1457c4 · F_D3DModelVertexNormalColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=208 · insn=52 */
/* @0x1457c4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1457c8 sub sp, sp, #36 */
/* @0x1457cc mov r1, #0 */
/* @0x1457d0 ldr r4, [sp, #0x48] */
/* @0x1457d4 mov r0, r4 */
/* @0x1457d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1457dc mov r1, #1 */
/* @0x1457e0 mov r5, r0 */
/* @0x1457e4 mov r0, r4 */
/* @0x1457e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1457ec mov r1, #2 */
/* @0x1457f0 mov r8, r0 */
/* @0x1457f4 mov r0, r4 */
/* @0x1457f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1457fc mov r1, #3 */
/* @0x145800 mov r7, r0 */
/* @0x145804 mov r0, r4 */
/* @0x145808 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14580c mov r1, #4 */
/* @0x145810 mov r6, r0 */
/* @0x145814 mov r0, r4 */
/* @0x145818 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14581c mov r1, #5 */
/* @0x145820 mov r3, r0 */
/* @0x145824 mov r0, r4 */
/* @0x145828 str r3, [sp, #0x1c] */
/* @0x14582c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145830 mov r1, #6 */
/* @0x145834 mov r11, r0 */
/* @0x145838 mov r0, r4 */
/* @0x14583c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145840 mov r1, #7 */
/* @0x145844 mov r10, r0 */
/* @0x145848 mov r0, r4 */
/* @0x14584c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145850 mov r1, #8 */
/* @0x145854 mov r9, r0 */
/* @0x145858 mov r0, r4 */
/* @0x14585c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145860 ldr r3, [sp, #0x1c] */
/* @0x145864 str r11, [sp, #0x4] */
/* @0x145868 mov r1, r8 */
/* @0x14586c str r10, [sp, #0x8] */
/* @0x145870 mov r2, r7 */
/* @0x145874 str r3, [sp] */
/* @0x145878 mov r3, r6 */
/* @0x14587c str r9, [sp, #0xc] */
/* @0x145880 str r0, [sp, #0x10] */
/* @0x145884 mov r0, r5 */
/* @0x145888 bl 0x165704 <_Z21GR_3DM_Vertex_N_Coloriffffffjf> */
/* @0x14588c add sp, sp, #36 */
/* @0x145890 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x145894 · F_D3DModelVertexNormalTexture(RValue&, CInstance*, CInstance*, int, RValue*) · size=208 · insn=52 */
/* @0x145894 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x145898 sub sp, sp, #36 */
/* @0x14589c mov r1, #0 */
/* @0x1458a0 ldr r4, [sp, #0x48] */
/* @0x1458a4 mov r0, r4 */
/* @0x1458a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1458ac mov r1, #1 */
/* @0x1458b0 mov r5, r0 */
/* @0x1458b4 mov r0, r4 */
/* @0x1458b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1458bc mov r1, #2 */
/* @0x1458c0 mov r8, r0 */
/* @0x1458c4 mov r0, r4 */
/* @0x1458c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1458cc mov r1, #3 */
/* @0x1458d0 mov r7, r0 */
/* @0x1458d4 mov r0, r4 */
/* @0x1458d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1458dc mov r1, #4 */
/* @0x1458e0 mov r6, r0 */
/* @0x1458e4 mov r0, r4 */
/* @0x1458e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1458ec mov r1, #5 */
/* @0x1458f0 mov r3, r0 */
/* @0x1458f4 mov r0, r4 */
/* @0x1458f8 str r3, [sp, #0x1c] */
/* @0x1458fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145900 mov r1, #6 */
/* @0x145904 mov r11, r0 */
/* @0x145908 mov r0, r4 */
/* @0x14590c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145910 mov r1, #7 */
/* @0x145914 mov r10, r0 */
/* @0x145918 mov r0, r4 */
/* @0x14591c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145920 mov r1, #8 */
/* @0x145924 mov r9, r0 */
/* @0x145928 mov r0, r4 */
/* @0x14592c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145930 ldr r3, [sp, #0x1c] */
/* @0x145934 str r11, [sp, #0x4] */
/* @0x145938 mov r1, r8 */
/* @0x14593c str r10, [sp, #0x8] */
/* @0x145940 mov r2, r7 */
/* @0x145944 str r3, [sp] */
/* @0x145948 mov r3, r6 */
/* @0x14594c str r9, [sp, #0xc] */
/* @0x145950 str r0, [sp, #0x10] */
/* @0x145954 mov r0, r5 */
/* @0x145958 bl 0x16579c <_Z23GR_3DM_Vertex_N_Textureiffffffff> */
/* @0x14595c add sp, sp, #36 */
/* @0x145960 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x145964 · F_D3DModelVertexNormalTextureColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=264 · insn=66 */
/* @0x145964 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x145968 sub sp, sp, #52 */
/* @0x14596c mov r1, #0 */
/* @0x145970 ldr r4, [sp, #0x58] */
/* @0x145974 mov r0, r4 */
/* @0x145978 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14597c mov r1, #1 */
/* @0x145980 mov r5, r0 */
/* @0x145984 mov r0, r4 */
/* @0x145988 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14598c mov r1, #2 */
/* @0x145990 mov r8, r0 */
/* @0x145994 mov r0, r4 */
/* @0x145998 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14599c mov r1, #3 */
/* @0x1459a0 mov r7, r0 */
/* @0x1459a4 mov r0, r4 */
/* @0x1459a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1459ac mov r1, #4 */
/* @0x1459b0 mov r6, r0 */
/* @0x1459b4 mov r0, r4 */
/* @0x1459b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1459bc mov r1, #5 */
/* @0x1459c0 mov r12, r0 */
/* @0x1459c4 mov r0, r4 */
/* @0x1459c8 str r12, [sp, #0x24] */
/* @0x1459cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1459d0 mov r1, #6 */
/* @0x1459d4 mov r2, r0 */
/* @0x1459d8 mov r0, r4 */
/* @0x1459dc str r2, [sp, #0x28] */
/* @0x1459e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1459e4 mov r1, #7 */
/* @0x1459e8 mov r3, r0 */
/* @0x1459ec mov r0, r4 */
/* @0x1459f0 str r3, [sp, #0x2c] */
/* @0x1459f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1459f8 mov r1, #8 */
/* @0x1459fc mov r11, r0 */
/* @0x145a00 mov r0, r4 */
/* @0x145a04 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145a08 mov r1, #9 */
/* @0x145a0c mov r10, r0 */
/* @0x145a10 mov r0, r4 */
/* @0x145a14 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145a18 mov r1, #10 */
/* @0x145a1c mov r9, r0 */
/* @0x145a20 mov r0, r4 */
/* @0x145a24 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145a28 ldr r2, [sp, #0x28] */
/* @0x145a2c ldr r3, [sp, #0x2c] */
/* @0x145a30 mov r1, r8 */
/* @0x145a34 ldr r12, [sp, #0x24] */
/* @0x145a38 str r2, [sp, #0x4] */
/* @0x145a3c mov r2, r7 */
/* @0x145a40 str r3, [sp, #0x8] */
/* @0x145a44 mov r3, r6 */
/* @0x145a48 str r12, [sp] */
/* @0x145a4c str r11, [sp, #0xc] */
/* @0x145a50 str r10, [sp, #0x10] */
/* @0x145a54 str r9, [sp, #0x14] */
/* @0x145a58 str r0, [sp, #0x18] */
/* @0x145a5c mov r0, r5 */
/* @0x145a60 bl 0x165834 <_Z29GR_3DM_Vertex_N_Texture_Coloriffffffffjf> */
/* @0x145a64 add sp, sp, #52 */
/* @0x145a68 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x145a6c · F_D3DModelBlock(RValue&, CInstance*, CInstance*, int, RValue*) · size=208 · insn=52 */
/* @0x145a6c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x145a70 sub sp, sp, #36 */
/* @0x145a74 mov r1, #0 */
/* @0x145a78 ldr r4, [sp, #0x48] */
/* @0x145a7c mov r0, r4 */
/* @0x145a80 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145a84 mov r1, #1 */
/* @0x145a88 mov r5, r0 */
/* @0x145a8c mov r0, r4 */
/* @0x145a90 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145a94 mov r1, #2 */
/* @0x145a98 mov r8, r0 */
/* @0x145a9c mov r0, r4 */
/* @0x145aa0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145aa4 mov r1, #3 */
/* @0x145aa8 mov r7, r0 */
/* @0x145aac mov r0, r4 */
/* @0x145ab0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145ab4 mov r1, #4 */
/* @0x145ab8 mov r6, r0 */
/* @0x145abc mov r0, r4 */
/* @0x145ac0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145ac4 mov r1, #5 */
/* @0x145ac8 mov r3, r0 */
/* @0x145acc mov r0, r4 */
/* @0x145ad0 str r3, [sp, #0x1c] */
/* @0x145ad4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145ad8 mov r1, #6 */
/* @0x145adc mov r11, r0 */
/* @0x145ae0 mov r0, r4 */
/* @0x145ae4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145ae8 mov r1, #7 */
/* @0x145aec mov r10, r0 */
/* @0x145af0 mov r0, r4 */
/* @0x145af4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145af8 mov r1, #8 */
/* @0x145afc mov r9, r0 */
/* @0x145b00 mov r0, r4 */
/* @0x145b04 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145b08 ldr r3, [sp, #0x1c] */
/* @0x145b0c str r11, [sp, #0x4] */
/* @0x145b10 mov r1, r8 */
/* @0x145b14 str r10, [sp, #0x8] */
/* @0x145b18 mov r2, r7 */
/* @0x145b1c str r3, [sp] */
/* @0x145b20 mov r3, r6 */
/* @0x145b24 str r9, [sp, #0xc] */
/* @0x145b28 str r0, [sp, #0x10] */
/* @0x145b2c mov r0, r5 */
/* @0x145b30 bl 0x16594c <_Z12GR_3DM_Blockiffffffff> */
/* @0x145b34 add sp, sp, #36 */
/* @0x145b38 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x145b3c · F_D3DModelCylinder(RValue&, CInstance*, CInstance*, int, RValue*) · size=264 · insn=66 */
/* @0x145b3c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x145b40 sub sp, sp, #52 */
/* @0x145b44 mov r1, #0 */
/* @0x145b48 ldr r4, [sp, #0x58] */
/* @0x145b4c mov r0, r4 */
/* @0x145b50 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145b54 mov r1, #1 */
/* @0x145b58 mov r5, r0 */
/* @0x145b5c mov r0, r4 */
/* @0x145b60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145b64 mov r1, #2 */
/* @0x145b68 mov r8, r0 */
/* @0x145b6c mov r0, r4 */
/* @0x145b70 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145b74 mov r1, #3 */
/* @0x145b78 mov r7, r0 */
/* @0x145b7c mov r0, r4 */
/* @0x145b80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145b84 mov r1, #4 */
/* @0x145b88 mov r6, r0 */
/* @0x145b8c mov r0, r4 */
/* @0x145b90 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145b94 mov r1, #5 */
/* @0x145b98 mov r12, r0 */
/* @0x145b9c mov r0, r4 */
/* @0x145ba0 str r12, [sp, #0x24] */
/* @0x145ba4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145ba8 mov r1, #6 */
/* @0x145bac mov r2, r0 */
/* @0x145bb0 mov r0, r4 */
/* @0x145bb4 str r2, [sp, #0x28] */
/* @0x145bb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145bbc mov r1, #7 */
/* @0x145bc0 mov r3, r0 */
/* @0x145bc4 mov r0, r4 */
/* @0x145bc8 str r3, [sp, #0x2c] */
/* @0x145bcc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145bd0 mov r1, #8 */
/* @0x145bd4 mov r11, r0 */
/* @0x145bd8 mov r0, r4 */
/* @0x145bdc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145be0 mov r1, #9 */
/* @0x145be4 mov r10, r0 */
/* @0x145be8 mov r0, r4 */
/* @0x145bec bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x145bf0 mov r1, #10 */
/* @0x145bf4 mov r9, r0 */
/* @0x145bf8 mov r0, r4 */
/* @0x145bfc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145c00 ldr r2, [sp, #0x28] */
/* @0x145c04 ldr r3, [sp, #0x2c] */
/* @0x145c08 mov r1, r8 */
/* @0x145c0c ldr r12, [sp, #0x24] */
/* @0x145c10 str r2, [sp, #0x4] */
/* @0x145c14 mov r2, r7 */
/* @0x145c18 str r3, [sp, #0x8] */
/* @0x145c1c mov r3, r6 */
/* @0x145c20 str r12, [sp] */
/* @0x145c24 str r11, [sp, #0xc] */
/* @0x145c28 str r10, [sp, #0x10] */
/* @0x145c2c str r9, [sp, #0x14] */
/* @0x145c30 str r0, [sp, #0x18] */
/* @0x145c34 mov r0, r5 */
/* @0x145c38 bl 0x1659e4 <_Z15GR_3DM_Cylinderiffffffffbi> */
/* @0x145c3c add sp, sp, #52 */
/* @0x145c40 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x145c44 · F_D3DModelCone(RValue&, CInstance*, CInstance*, int, RValue*) · size=264 · insn=66 */
/* @0x145c44 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x145c48 sub sp, sp, #52 */
/* @0x145c4c mov r1, #0 */
/* @0x145c50 ldr r4, [sp, #0x58] */
/* @0x145c54 mov r0, r4 */
/* @0x145c58 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145c5c mov r1, #1 */
/* @0x145c60 mov r5, r0 */
/* @0x145c64 mov r0, r4 */
/* @0x145c68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145c6c mov r1, #2 */
/* @0x145c70 mov r8, r0 */
/* @0x145c74 mov r0, r4 */
/* @0x145c78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145c7c mov r1, #3 */
/* @0x145c80 mov r7, r0 */
/* @0x145c84 mov r0, r4 */
/* @0x145c88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145c8c mov r1, #4 */
/* @0x145c90 mov r6, r0 */
/* @0x145c94 mov r0, r4 */
/* @0x145c98 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145c9c mov r1, #5 */
/* @0x145ca0 mov r12, r0 */
/* @0x145ca4 mov r0, r4 */
/* @0x145ca8 str r12, [sp, #0x24] */
/* @0x145cac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145cb0 mov r1, #6 */
/* @0x145cb4 mov r2, r0 */
/* @0x145cb8 mov r0, r4 */
/* @0x145cbc str r2, [sp, #0x28] */
/* @0x145cc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145cc4 mov r1, #7 */
/* @0x145cc8 mov r3, r0 */
/* @0x145ccc mov r0, r4 */
/* @0x145cd0 str r3, [sp, #0x2c] */
/* @0x145cd4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145cd8 mov r1, #8 */
/* @0x145cdc mov r11, r0 */
/* @0x145ce0 mov r0, r4 */
/* @0x145ce4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145ce8 mov r1, #9 */
/* @0x145cec mov r10, r0 */
/* @0x145cf0 mov r0, r4 */
/* @0x145cf4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x145cf8 mov r1, #10 */
/* @0x145cfc mov r9, r0 */
/* @0x145d00 mov r0, r4 */
/* @0x145d04 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145d08 ldr r2, [sp, #0x28] */
/* @0x145d0c ldr r3, [sp, #0x2c] */
/* @0x145d10 mov r1, r8 */
/* @0x145d14 ldr r12, [sp, #0x24] */
/* @0x145d18 str r2, [sp, #0x4] */
/* @0x145d1c mov r2, r7 */
/* @0x145d20 str r3, [sp, #0x8] */
/* @0x145d24 mov r3, r6 */
/* @0x145d28 str r12, [sp] */
/* @0x145d2c str r11, [sp, #0xc] */
/* @0x145d30 str r10, [sp, #0x10] */
/* @0x145d34 str r9, [sp, #0x14] */
/* @0x145d38 str r0, [sp, #0x18] */
/* @0x145d3c mov r0, r5 */
/* @0x145d40 bl 0x165a80 <_Z11GR_3DM_Coneiffffffffbi> */
/* @0x145d44 add sp, sp, #52 */
/* @0x145d48 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x145d4c · F_D3DModelEllipsoid(RValue&, CInstance*, CInstance*, int, RValue*) · size=236 · insn=59 */
/* @0x145d4c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x145d50 sub sp, sp, #36 */
/* @0x145d54 mov r1, #0 */
/* @0x145d58 ldr r4, [sp, #0x48] */
/* @0x145d5c mov r0, r4 */
/* @0x145d60 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145d64 mov r1, #1 */
/* @0x145d68 mov r5, r0 */
/* @0x145d6c mov r0, r4 */
/* @0x145d70 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145d74 mov r1, #2 */
/* @0x145d78 mov r8, r0 */
/* @0x145d7c mov r0, r4 */
/* @0x145d80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145d84 mov r1, #3 */
/* @0x145d88 mov r7, r0 */
/* @0x145d8c mov r0, r4 */
/* @0x145d90 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145d94 mov r1, #4 */
/* @0x145d98 mov r6, r0 */
/* @0x145d9c mov r0, r4 */
/* @0x145da0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145da4 mov r1, #5 */
/* @0x145da8 mov r2, r0 */
/* @0x145dac mov r0, r4 */
/* @0x145db0 str r2, [sp, #0x18] */
/* @0x145db4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145db8 mov r1, #6 */
/* @0x145dbc mov r3, r0 */
/* @0x145dc0 mov r0, r4 */
/* @0x145dc4 str r3, [sp, #0x1c] */
/* @0x145dc8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145dcc mov r1, #7 */
/* @0x145dd0 mov r11, r0 */
/* @0x145dd4 mov r0, r4 */
/* @0x145dd8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145ddc mov r1, #8 */
/* @0x145de0 mov r10, r0 */
/* @0x145de4 mov r0, r4 */
/* @0x145de8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145dec mov r1, #9 */
/* @0x145df0 mov r9, r0 */
/* @0x145df4 mov r0, r4 */
/* @0x145df8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145dfc ldr r2, [sp, #0x18] */
/* @0x145e00 ldr r3, [sp, #0x1c] */
/* @0x145e04 mov r1, r8 */
/* @0x145e08 str r11, [sp, #0x8] */
/* @0x145e0c str r2, [sp] */
/* @0x145e10 mov r2, r7 */
/* @0x145e14 str r3, [sp, #0x4] */
/* @0x145e18 mov r3, r6 */
/* @0x145e1c str r10, [sp, #0xc] */
/* @0x145e20 str r9, [sp, #0x10] */
/* @0x145e24 str r0, [sp, #0x14] */
/* @0x145e28 mov r0, r5 */
/* @0x145e2c bl 0x165b1c <_Z16GR_3DM_Ellipsoidiffffffffi> */
/* @0x145e30 add sp, sp, #36 */
/* @0x145e34 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x145e38 · F_D3DModelWall(RValue&, CInstance*, CInstance*, int, RValue*) · size=208 · insn=52 */
/* @0x145e38 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x145e3c sub sp, sp, #36 */
/* @0x145e40 mov r1, #0 */
/* @0x145e44 ldr r4, [sp, #0x48] */
/* @0x145e48 mov r0, r4 */
/* @0x145e4c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145e50 mov r1, #1 */
/* @0x145e54 mov r5, r0 */
/* @0x145e58 mov r0, r4 */
/* @0x145e5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145e60 mov r1, #2 */
/* @0x145e64 mov r8, r0 */
/* @0x145e68 mov r0, r4 */
/* @0x145e6c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145e70 mov r1, #3 */
/* @0x145e74 mov r7, r0 */
/* @0x145e78 mov r0, r4 */
/* @0x145e7c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145e80 mov r1, #4 */
/* @0x145e84 mov r6, r0 */
/* @0x145e88 mov r0, r4 */
/* @0x145e8c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145e90 mov r1, #5 */
/* @0x145e94 mov r3, r0 */
/* @0x145e98 mov r0, r4 */
/* @0x145e9c str r3, [sp, #0x1c] */
/* @0x145ea0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145ea4 mov r1, #6 */
/* @0x145ea8 mov r11, r0 */
/* @0x145eac mov r0, r4 */
/* @0x145eb0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145eb4 mov r1, #7 */
/* @0x145eb8 mov r10, r0 */
/* @0x145ebc mov r0, r4 */
/* @0x145ec0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145ec4 mov r1, #8 */
/* @0x145ec8 mov r9, r0 */
/* @0x145ecc mov r0, r4 */
/* @0x145ed0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145ed4 ldr r3, [sp, #0x1c] */
/* @0x145ed8 str r11, [sp, #0x4] */
/* @0x145edc mov r1, r8 */
/* @0x145ee0 str r10, [sp, #0x8] */
/* @0x145ee4 mov r2, r7 */
/* @0x145ee8 str r3, [sp] */
/* @0x145eec mov r3, r6 */
/* @0x145ef0 str r9, [sp, #0xc] */
/* @0x145ef4 str r0, [sp, #0x10] */
/* @0x145ef8 mov r0, r5 */
/* @0x145efc bl 0x165bb8 <_Z11GR_3DM_Walliffffffff> */
/* @0x145f00 add sp, sp, #36 */
/* @0x145f04 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x145f08 · F_D3DModelFloor(RValue&, CInstance*, CInstance*, int, RValue*) · size=208 · insn=52 */
/* @0x145f08 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x145f0c sub sp, sp, #36 */
/* @0x145f10 mov r1, #0 */
/* @0x145f14 ldr r4, [sp, #0x48] */
/* @0x145f18 mov r0, r4 */
/* @0x145f1c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x145f20 mov r1, #1 */
/* @0x145f24 mov r5, r0 */
/* @0x145f28 mov r0, r4 */
/* @0x145f2c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145f30 mov r1, #2 */
/* @0x145f34 mov r8, r0 */
/* @0x145f38 mov r0, r4 */
/* @0x145f3c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145f40 mov r1, #3 */
/* @0x145f44 mov r7, r0 */
/* @0x145f48 mov r0, r4 */
/* @0x145f4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145f50 mov r1, #4 */
/* @0x145f54 mov r6, r0 */
/* @0x145f58 mov r0, r4 */
/* @0x145f5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145f60 mov r1, #5 */
/* @0x145f64 mov r3, r0 */
/* @0x145f68 mov r0, r4 */
/* @0x145f6c str r3, [sp, #0x1c] */
/* @0x145f70 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145f74 mov r1, #6 */
/* @0x145f78 mov r11, r0 */
/* @0x145f7c mov r0, r4 */
/* @0x145f80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145f84 mov r1, #7 */
/* @0x145f88 mov r10, r0 */
/* @0x145f8c mov r0, r4 */
/* @0x145f90 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145f94 mov r1, #8 */
/* @0x145f98 mov r9, r0 */
/* @0x145f9c mov r0, r4 */
/* @0x145fa0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x145fa4 ldr r3, [sp, #0x1c] */
/* @0x145fa8 str r11, [sp, #0x4] */
/* @0x145fac mov r1, r8 */
/* @0x145fb0 str r10, [sp, #0x8] */
/* @0x145fb4 mov r2, r7 */
/* @0x145fb8 str r3, [sp] */
/* @0x145fbc mov r3, r6 */
/* @0x145fc0 str r9, [sp, #0xc] */
/* @0x145fc4 str r0, [sp, #0x10] */
/* @0x145fc8 mov r0, r5 */
/* @0x145fcc bl 0x165c50 <_Z12GR_3DM_Flooriffffffff> */
/* @0x145fd0 add sp, sp, #36 */
/* @0x145fd4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x145fd8 · F_GPUGetFog(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=43 */
/* @0x145fd8 push {r4, r5, lr} */
/* @0x145fdc vpush {d8} */
/* @0x145fe0 mov r5, r0 */
/* @0x145fe4 ldr r4, [pc, #0x9c] */
/* @0x145fe8 sub sp, sp, #36 */
/* @0x145fec mov r1, #17 */
/* @0x145ff0 ldr r4, [pc, r4] */
/* @0x145ff4 mov r0, r4 */
/* @0x145ff8 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x145ffc mov r1, #18 */
/* @0x146000 vmov s17, r0 */
/* @0x146004 mov r0, r4 */
/* @0x146008 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x14600c mov r1, #13 */
/* @0x146010 vmov s16, r0 */
/* @0x146014 mov r0, r4 */
/* @0x146018 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x14601c vmov.f64 d5, #1.000000e+00 */
/* @0x146020 vldr d4, [pc, #88] */
/* @0x146024 mov r1, #15 */
/* @0x146028 cmp r0, #0 */
/* @0x14602c mov r0, r4 */
/* @0x146030 vmovne r2, r3, d5 */
/* @0x146034 vmoveq r2, r3, d4 */
/* @0x146038 str r2, [sp, #0x1c] */
/* @0x14603c str r3, [sp, #0x18] */
/* @0x146040 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x146044 vcvt.f64.f32 d6, s17 */
/* @0x146048 mov r1, #4 */
/* @0x14604c ldr r2, [sp, #0x1c] */
/* @0x146050 ldr r3, [sp, #0x18] */
/* @0x146054 vcvt.f64.f32 d7, s16 */
/* @0x146058 vstr d6, [sp, #8] */
/* @0x14605c vstr d7, [sp, #16] */
/* @0x146060 vmov s13, r0 */
/* @0x146064 mov r0, r5 */
/* @0x146068 vcvt.f64.u32 d7, s13 */
/* @0x14606c vstr d7, [sp] */
/* @0x146070 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x146074 add sp, sp, #36 */
/* @0x146078 vpop {d8} */
/* @0x14607c pop {r4, r5, pc} */
/* @0x146088 eoreq r7, r10, r8, lsl #26 */

/* ── FUNC 0x14608c · anon_14608c · size=4 · insn=1 */
/* @0x14608c nop */

/* ── FUNC 0x146090 · F_GPUPushState(RValue&, CInstance*, CInstance*, int, RValue*) · size=16 · insn=4 */
/* @0x146090 ldr r0, [pc, #0x4] */
/* @0x146094 ldr r0, [pc, r0] */
/* @0x146098 b 0x167fcc <_ZN18RenderStateManager10SaveStatesEv> */
/* @0x14609c eoreq r7, r10, r4, ror #24 */

/* ── FUNC 0x1460a0 · F_GPUPopState(RValue&, CInstance*, CInstance*, int, RValue*) · size=16 · insn=4 */
/* @0x1460a0 ldr r0, [pc, #0x4] */
/* @0x1460a4 ldr r0, [pc, r0] */
/* @0x1460a8 b 0x168050 <_ZN18RenderStateManager13RestoreStatesEv> */
/* @0x1460ac eoreq r7, r10, r4, asr r12 */

/* ── FUNC 0x1460b0 · F_GPUGetState(RValue&, CInstance*, CInstance*, int, RValue*) · size=548 · insn=137 */
/* @0x1460b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1460b4 vpush {d8} */
/* @0x1460b8 sub sp, sp, #292 */
/* @0x1460bc ldr r4, [pc, #0x1f8] */
/* @0x1460c0 add r1, sp, #24 */
/* @0x1460c4 ldr r2, [pc, #0x1f4] */
/* @0x1460c8 mov r3, #0 */
/* @0x1460cc add r4, pc, r4 */
/* @0x1460d0 str r0, [sp, #0xc] */
/* @0x1460d4 str r1, [sp, #0x14] */
/* @0x1460d8 mov r0, r1 */
/* @0x1460dc ldr r2, [r4, r2] */
/* @0x1460e0 mov r5, r3 */
/* @0x1460e4 movt r3, #0xbff0 */
/* @0x1460e8 mov r8, r5 */
/* @0x1460ec str r2, [sp, #0x10] */
/* @0x1460f0 ldr r1, [sp, #0x10] */
/* @0x1460f4 ldr r2, [sp, #0xc] */
/* @0x1460f8 str r3, [r2, #0x4] */
/* @0x1460fc ldr r3, [r1] */
/* @0x146100 str r5, [r2, #0xc] */
/* @0x146104 str r5, [r2] */
/* @0x146108 str r3, [sp, #0x11c] */
/* @0x14610c bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x146110 mov r0, r5 */
/* @0x146114 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x146118 vmov s17, r0 */
/* @0x14611c bl 0x2052d4 <_Z8GetDsMapi> */
/* @0x146120 ldr r1, [pc, #0x19c] */
/* @0x146124 ldr r3, [pc, #0x19c] */
/* @0x146128 ldr r5, [r4, r1] */
/* @0x14612c ldr r7, [r4, r3] */
/* @0x146130 add r9, r5, #8 */
/* @0x146134 add r5, r5, #224 */
/* @0x146138 mov r6, r0 */
/* @0x14613c b 0x14616c <_Z13F_GPUGetStateR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x146140 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x146144 vmov s15, r11 */
/* @0x146148 str r8, [sp] */
/* @0x14614c add r9, r9, #12 */
/* @0x146150 vcvt.f64.f32 d7, s15 */
/* @0x146154 vmov r2, r3, d7 */
/* @0x146158 mov r1, r0 */
/* @0x14615c mov r0, r6 */
/* @0x146160 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0x146164 cmp r9, r5 */
/* @0x146168 beq 0x1461b8 <_Z13F_GPUGetStateR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x14616c mov r0, r7 */
/* @0x146170 ldr r1, [r9, #-0x4] */
/* @0x146174 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x146178 ldrb r10, [r9] */
/* @0x14617c cmp r10, #0 */
/* @0x146180 mov r11, r0 */
/* @0x146184 ldr r0, [r9, #-0x8] */
/* @0x146188 bne 0x146140 <_Z13F_GPUGetStateR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x14618c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x146190 vmov s15, r11 */
/* @0x146194 str r10, [sp] */
/* @0x146198 add r9, r9, #12 */
/* @0x14619c vcvt.f64.u32 d7, s15 */
/* @0x1461a0 vmov r2, r3, d7 */
/* @0x1461a4 mov r1, r0 */
/* @0x1461a8 mov r0, r6 */
/* @0x1461ac bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0x1461b0 cmp r9, r5 */
/* @0x1461b4 bne 0x14616c <_Z13F_GPUGetStateR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x1461b8 ldr r3, [pc, #0x10c] */
/* @0x1461bc add r9, sp, #28 */
/* @0x1461c0 ldr r8, [pc, #0x108] */
/* @0x1461c4 mov r10, #0 */
/* @0x1461c8 ldr r11, [r4, r3] */
/* @0x1461cc add r8, pc, r8 */
/* @0x1461d0 add r5, r11, #8 */
/* @0x1461d4 add r11, r11, #128 */
/* @0x1461d8 str r11, [sp, #0x8] */
/* @0x1461dc mov r4, #0 */
/* @0x1461e0 b 0x14620c <_Z13F_GPUGetStateR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x1461e4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1461e8 vcvt.f64.f32 d7, s16 */
/* @0x1461ec str r10, [sp] */
/* @0x1461f0 add r4, r4, #1 */
/* @0x1461f4 vmov r2, r3, d7 */
/* @0x1461f8 mov r1, r0 */
/* @0x1461fc mov r0, r6 */
/* @0x146200 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0x146204 cmp r4, #8 */
/* @0x146208 beq 0x146270 <_Z13F_GPUGetStateR6RValueP9CInstanceS2_iPS_+0x1c0> */
/* @0x14620c ldr r3, [r5, #-0x8] */
/* @0x146210 mov r1, #255 */
/* @0x146214 mov r2, r8 */
/* @0x146218 mov r0, r9 */
/* @0x14621c str r4, [sp] */
/* @0x146220 bl 0xb65c8 <snprintf@plt> */
/* @0x146224 mov r0, r7 */
/* @0x146228 mov r1, r4 */
/* @0x14622c ldr r2, [r5, #-0x4] */
/* @0x146230 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x146234 ldrb r11, [r5] */
/* @0x146238 cmp r11, #0 */
/* @0x14623c vmov s16, r0 */
/* @0x146240 ldr r0, [r5, #-0x8] */
/* @0x146244 bne 0x1461e4 <_Z13F_GPUGetStateR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x146248 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x14624c vcvt.f64.u32 d7, s16 */
/* @0x146250 str r11, [sp] */
/* @0x146254 add r4, r4, #1 */
/* @0x146258 vmov r2, r3, d7 */
/* @0x14625c mov r1, r0 */
/* @0x146260 mov r0, r6 */
/* @0x146264 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0x146268 cmp r4, #8 */
/* @0x14626c bne 0x14620c <_Z13F_GPUGetStateR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x146270 ldr r1, [sp, #0x8] */
/* @0x146274 add r5, r5, #12 */
/* @0x146278 cmp r5, r1 */
/* @0x14627c bne 0x1461dc <_Z13F_GPUGetStateR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x146280 vcvt.f64.s32 d7, s17 */
/* @0x146284 ldr r1, [sp, #0xc] */
/* @0x146288 add r0, sp, #24 */
/* @0x14628c vmov r2, r3, d7 */
/* @0x146290 stm r1, {r2, r3} */
/* @0x146294 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x146298 ldr r1, [sp, #0x10] */
/* @0x14629c ldr r2, [sp, #0x11c] */
/* @0x1462a0 ldr r3, [r1] */
/* @0x1462a4 cmp r2, r3 */
/* @0x1462a8 bne 0x1462b8 <_Z13F_GPUGetStateR6RValueP9CInstanceS2_iPS_+0x208> */
/* @0x1462ac add sp, sp, #292 */
/* @0x1462b0 vpop {d8} */
/* @0x1462b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1462b8 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1462bc eoreq r11, r10, r4, lsl #23 */
/* @0x1462c0 .word 0xffffbd00 */
/* @0x1462c4 .word 0xffffd9c4 */
/* @0x1462c8 .word 0xffffc0a8 */
/* @0x1462cc .word 0xffffd9c8 */
/* @0x1462d0 andseq r11, pc, r8, lsr #8 */

/* ── FUNC 0x1462d4 · F_GPUSetState(RValue&, CInstance*, CInstance*, int, RValue*) · size=604 · insn=151 */
/* @0x1462d4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1462d8 cmp r3, #1 */
/* @0x1462dc ldr r8, [pc, #0x234] */
/* @0x1462e0 mov r3, #0 */
/* @0x1462e4 mov r4, r3 */
/* @0x1462e8 sub sp, sp, #68 */
/* @0x1462ec movt r3, #0xbff0 */
/* @0x1462f0 str r4, [r0, #0xc] */
/* @0x1462f4 str r3, [r0, #0x4] */
/* @0x1462f8 add r8, pc, r8 */
/* @0x1462fc str r4, [r0] */
/* @0x146300 beq 0x14631c <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x146304 ldr r0, [pc, #0x210] */
/* @0x146308 mov r1, r4 */
/* @0x14630c add r0, pc, r0 */
/* @0x146310 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x146314 add sp, sp, #68 */
/* @0x146318 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x14631c add r1, sp, #28 */
/* @0x146320 str r1, [sp, #0x14] */
/* @0x146324 mov r0, r1 */
/* @0x146328 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x14632c mov r1, r4 */
/* @0x146330 ldr r0, [sp, #0x68] */
/* @0x146334 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x146338 bl 0x2052d4 <_Z8GetDsMapi> */
/* @0x14633c subs r2, r0, #0 */
/* @0x146340 str r2, [sp, #0x10] */
/* @0x146344 beq 0x1464fc <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x228> */
/* @0x146348 bl 0x203c8c <_ZN7CDS_Map9FindFirstEv> */
/* @0x14634c subs r3, r0, #0 */
/* @0x146350 beq 0x146440 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x146354 ldr r2, [pc, #0x1c4] */
/* @0x146358 add r1, sp, #48 */
/* @0x14635c str r1, [sp, #0x8] */
/* @0x146360 add r7, sp, #32 */
/* @0x146364 ldr r2, [r8, r2] */
/* @0x146368 add r5, r2, #216 */
/* @0x14636c str r2, [sp, #0xc] */
/* @0x146370 ldr r0, [r3] */
/* @0x146374 mov r4, r3 */
/* @0x146378 ldr r1, [r3, #0x4] */
/* @0x14637c mov lr, r7 */
/* @0x146380 ldr r2, [r3, #0x8] */
/* @0x146384 add r12, sp, #48 */
/* @0x146388 ldr r3, [r3, #0xc] */
/* @0x14638c stm lr!, {r0, r1, r2, r3} */
/* @0x146390 ldr r0, [r4, #0x10]! */
/* @0x146394 ldr lr, [sp, #0x2c] */
/* @0x146398 ldr r3, [r4, #0xc] */
/* @0x14639c bic lr, lr, #-16777216 */
/* @0x1463a0 ldr r1, [r4, #0x4] */
/* @0x1463a4 cmp lr, #1 */
/* @0x1463a8 ldr r2, [r4, #0x8] */
/* @0x1463ac str lr, [sp, #0x2c] */
/* @0x1463b0 movne r6, #0 */
/* @0x1463b4 stm r12!, {r0, r1, r2, r3} */
/* @0x1463b8 ldr r3, [sp, #0x3c] */
/* @0x1463bc bic r3, r3, #-16777216 */
/* @0x1463c0 str r3, [sp, #0x3c] */
/* @0x1463c4 beq 0x146480 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0x1463c8 ldr r4, [sp, #0xc] */
/* @0x1463cc mov r0, r6 */
/* @0x1463d0 ldr r1, [r4] */
/* @0x1463d4 bl 0xb6574 <strcmp@plt> */
/* @0x1463d8 cmp r0, #0 */
/* @0x1463dc beq 0x146450 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x1463e0 add r4, r4, #12 */
/* @0x1463e4 cmp r4, r5 */
/* @0x1463e8 bne 0x1463cc <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x1463ec ldr r3, [pc, #0x130] */
/* @0x1463f0 ldr r10, [r8, r3] */
/* @0x1463f4 add r4, r10, #120 */
/* @0x1463f8 ldr r9, [r10] */
/* @0x1463fc mov r0, r9 */
/* @0x146400 bl 0xb6538 <strlen@plt> */
/* @0x146404 mov r1, r9 */
/* @0x146408 mov r11, r0 */
/* @0x14640c mov r0, r6 */
/* @0x146410 mov r2, r11 */
/* @0x146414 bl 0xb65e0 <strncmp@plt> */
/* @0x146418 cmp r0, #0 */
/* @0x14641c beq 0x1464a0 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x1cc> */
/* @0x146420 add r10, r10, #12 */
/* @0x146424 cmp r10, r4 */
/* @0x146428 bne 0x1463f8 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x14642c ldr r0, [sp, #0x10] */
/* @0x146430 mov r1, r7 */
/* @0x146434 bl 0x203b94 <_ZN7CDS_Map8FindNextEP6RValue> */
/* @0x146438 subs r3, r0, #0 */
/* @0x14643c bne 0x146370 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x146440 add r0, sp, #28 */
/* @0x146444 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x146448 add sp, sp, #68 */
/* @0x14644c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x146450 ldrb r1, [r4, #0x8] */
/* @0x146454 cmp r1, #0 */
/* @0x146458 beq 0x146490 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x1bc> */
/* @0x14645c mov r1, r0 */
/* @0x146460 add r0, sp, #48 */
/* @0x146464 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x146468 mov r2, r0 */
/* @0x14646c ldr r3, [pc, #0xb4] */
/* @0x146470 ldr r1, [r4, #0x4] */
/* @0x146474 ldr r0, [r8, r3] */
/* @0x146478 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x14647c b 0x14642c <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x146480 ldr r6, [sp, #0x20] */
/* @0x146484 cmp r6, #0 */
/* @0x146488 ldrne r6, [r6] */
/* @0x14648c b 0x1463c8 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x146490 add r0, sp, #48 */
/* @0x146494 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x146498 mov r2, r0 */
/* @0x14649c b 0x14646c <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x1464a0 mov r2, r0 */
/* @0x1464a4 add r0, r6, r11 */
/* @0x1464a8 str r2, [sp, #0x4] */
/* @0x1464ac bl 0xb66b8 <atoi@plt> */
/* @0x1464b0 ldrb r1, [r10, #0x8] */
/* @0x1464b4 ldr r2, [sp, #0x4] */
/* @0x1464b8 cmp r1, #0 */
/* @0x1464bc mov r4, r0 */
/* @0x1464c0 bne 0x1464e8 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x1464c4 add r0, sp, #48 */
/* @0x1464c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1464cc mov r3, r0 */
/* @0x1464d0 ldr lr, [pc, #0x50] */
/* @0x1464d4 mov r1, r4 */
/* @0x1464d8 ldr r2, [r10, #0x4] */
/* @0x1464dc ldr r0, [r8, lr] */
/* @0x1464e0 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1464e4 b 0x14642c <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x1464e8 mov r1, r2 */
/* @0x1464ec add r0, sp, #48 */
/* @0x1464f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1464f4 mov r3, r0 */
/* @0x1464f8 b 0x1464d0 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x1464fc ldr r0, [pc, #0x28] */
/* @0x146500 mov r1, r2 */
/* @0x146504 add r0, pc, r0 */
/* @0x146508 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14650c add r0, sp, #28 */
/* @0x146510 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x146514 b 0x146314 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x146518 eoreq r11, r10, r8, asr r9 */
/* @0x14651c ldrsheq r11, [pc], -r0 */
/* @0x146520 .word 0xffffd9c4 */
/* @0x146524 .word 0xffffd9c8 */
/* @0x146528 .word 0xffffc0a8 */
/* @0x14652c andseq r11, pc, r12, lsr r1 */

/* ── FUNC 0x146530 · F_YoYo_DrawTextureFlush(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x146530 push {r4, lr} */
/* @0x146534 mov r4, #0 */
/* @0x146538 str r4, [r0, #0xc] */
/* @0x14653c str r4, [r0] */
/* @0x146540 str r4, [r0, #0x4] */
/* @0x146544 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x146548 mov r0, r4 */
/* @0x14654c bl 0x1767d0 <_ZN8Graphics12TextureFlushEb> */
/* @0x146550 ldr r3, [pc, #0x34] */
/* @0x146554 ldr r3, [pc, r3] */
/* @0x146558 ldrb r3, [r3] */
/* @0x14655c cmp r3, r4 */
/* @0x146560 popeq {r4, pc} */
/* @0x146564 ldr r3, [pc, #0x24] */
/* @0x146568 ldr r3, [pc, r3] */
/* @0x14656c ldr r3, [r3] */
/* @0x146570 cmp r3, r4 */
/* @0x146574 popne {r4, pc} */
/* @0x146578 ldr r1, [pc, #0x14] */
/* @0x14657c mov r0, #4 */
/* @0x146580 pop {r4, lr} */
/* @0x146584 add r1, pc, r1 */
/* @0x146588 b 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz> */
/* @0x14658c .word 0x002a73d0 */
/* @0x146590 .word 0x002a7eb8 */
/* @0x146594 andseq r11, pc, r8, ror #1 */

/* ── FUNC 0x146598 · F_GPUSetBlendEnable(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x146598 cmp r3, #1 */
/* @0x14659c push {r3, lr} */
/* @0x1465a0 mov r3, #0 */
/* @0x1465a4 mov r1, r3 */
/* @0x1465a8 movt r3, #0xbff0 */
/* @0x1465ac str r1, [r0, #0xc] */
/* @0x1465b0 stm r0, {r1, r3} */
/* @0x1465b4 ldr r0, [sp, #0x8] */
/* @0x1465b8 beq 0x1465cc <_Z19F_GPUSetBlendEnableR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x1465bc ldr r0, [pc, #0x24] */
/* @0x1465c0 pop {r3, lr} */
/* @0x1465c4 add r0, pc, r0 */
/* @0x1465c8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1465cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1465d0 ldr r3, [pc, #0x14] */
/* @0x1465d4 mov r1, #12 */
/* @0x1465d8 mov r2, r0 */
/* @0x1465dc ldr r0, [pc, r3] */
/* @0x1465e0 pop {r3, lr} */
/* @0x1465e4 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1465e8 andseq r11, pc, r0, asr #1 */
/* @0x1465ec eoreq r7, r10, r12, lsl r7 */
