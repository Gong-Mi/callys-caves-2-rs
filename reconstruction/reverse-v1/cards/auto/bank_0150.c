/* libyoyo.so 覆盖卡组 0150
 * 函数 0x1be408..0x1bfd6c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1be408 · F_TilemapGetTileHeight(RValue&, CInstance*, CInstance*, int, RValue*) · size=188 · insn=47 */
/* @0x1be408 cmp r3, #1 */
/* @0x1be40c push {r3, r4, r5, r6, r7, lr} */
/* @0x1be410 mov r3, #0 */
/* @0x1be414 mov r4, r3 */
/* @0x1be418 mov r5, r0 */
/* @0x1be41c movt r3, #0xbff0 */
/* @0x1be420 str r4, [r0, #0xc] */
/* @0x1be424 str r3, [r0, #0x4] */
/* @0x1be428 str r4, [r0] */
/* @0x1be42c ldr r6, [sp, #0x18] */
/* @0x1be430 beq 0x1be448 <_Z22F_TilemapGetTileHeightR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1be434 ldr r0, [pc, #0x80] */
/* @0x1be438 mov r1, r4 */
/* @0x1be43c pop {r3, r4, r5, r6, r7, lr} */
/* @0x1be440 add r0, pc, r0 */
/* @0x1be444 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1be448 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1be44c mov r1, r4 */
/* @0x1be450 mov r7, r0 */
/* @0x1be454 mov r0, r6 */
/* @0x1be458 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1be45c mov r2, r4 */
/* @0x1be460 mov r1, r0 */
/* @0x1be464 mov r0, r7 */
/* @0x1be468 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1be46c cmp r0, #0 */
/* @0x1be470 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1be474 ldr r3, [r0] */
/* @0x1be478 cmp r3, #5 */
/* @0x1be47c popne {r3, r4, r5, r6, r7, pc} */
/* @0x1be480 ldr r0, [r0, #0x1c] */
/* @0x1be484 bl 0xc3794 <_Z15Background_Datai> */
/* @0x1be488 cmp r0, #0 */
/* @0x1be48c beq 0x1be4a8 <_Z22F_TilemapGetTileHeightR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x1be490 ldr r2, [r0, #0x20] */
/* @0x1be494 vmov s15, r2 */
/* @0x1be498 vcvt.f64.s32 d7, s15 */
/* @0x1be49c vmov r2, r3, d7 */
/* @0x1be4a0 stm r5, {r2, r3} */
/* @0x1be4a4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1be4a8 mov r1, r0 */
/* @0x1be4ac ldr r0, [pc, #0xc] */
/* @0x1be4b0 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1be4b4 add r0, pc, r0 */
/* @0x1be4b8 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1be4bc andseq r0, r9, r4, asr r6 */
/* @0x1be4c0 andseq r0, r9, r8, lsl r6 */

/* ── FUNC 0x1be4c4 · F_TilemapGetWidth(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1be4c4 cmp r3, #1 */
/* @0x1be4c8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1be4cc mov r3, #0 */
/* @0x1be4d0 mov r4, r3 */
/* @0x1be4d4 mov r5, r0 */
/* @0x1be4d8 movt r3, #0xbff0 */
/* @0x1be4dc str r4, [r0, #0xc] */
/* @0x1be4e0 str r3, [r0, #0x4] */
/* @0x1be4e4 str r4, [r0] */
/* @0x1be4e8 ldr r6, [sp, #0x18] */
/* @0x1be4ec beq 0x1be504 <_Z17F_TilemapGetWidthR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1be4f0 ldr r0, [pc, #0x5c] */
/* @0x1be4f4 mov r1, r4 */
/* @0x1be4f8 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1be4fc add r0, pc, r0 */
/* @0x1be500 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1be504 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1be508 mov r1, r4 */
/* @0x1be50c mov r7, r0 */
/* @0x1be510 mov r0, r6 */
/* @0x1be514 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1be518 mov r2, r4 */
/* @0x1be51c mov r1, r0 */
/* @0x1be520 mov r0, r7 */
/* @0x1be524 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1be528 cmp r0, #0 */
/* @0x1be52c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1be530 ldr r3, [r0] */
/* @0x1be534 cmp r3, #5 */
/* @0x1be538 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1be53c ldr r2, [r0, #0x28] */
/* @0x1be540 vmov s15, r2 */
/* @0x1be544 vcvt.f64.s32 d7, s15 */
/* @0x1be548 vmov r2, r3, d7 */
/* @0x1be54c stm r5, {r2, r3} */
/* @0x1be550 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1be554 andseq r0, r9, r0, lsl r6 */

/* ── FUNC 0x1be558 · F_TilemapGetHeight(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1be558 cmp r3, #1 */
/* @0x1be55c push {r3, r4, r5, r6, r7, lr} */
/* @0x1be560 mov r3, #0 */
/* @0x1be564 mov r4, r3 */
/* @0x1be568 mov r5, r0 */
/* @0x1be56c movt r3, #0xbff0 */
/* @0x1be570 str r4, [r0, #0xc] */
/* @0x1be574 str r3, [r0, #0x4] */
/* @0x1be578 str r4, [r0] */
/* @0x1be57c ldr r6, [sp, #0x18] */
/* @0x1be580 beq 0x1be598 <_Z18F_TilemapGetHeightR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1be584 ldr r0, [pc, #0x5c] */
/* @0x1be588 mov r1, r4 */
/* @0x1be58c pop {r3, r4, r5, r6, r7, lr} */
/* @0x1be590 add r0, pc, r0 */
/* @0x1be594 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1be598 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1be59c mov r1, r4 */
/* @0x1be5a0 mov r7, r0 */
/* @0x1be5a4 mov r0, r6 */
/* @0x1be5a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1be5ac mov r2, r4 */
/* @0x1be5b0 mov r1, r0 */
/* @0x1be5b4 mov r0, r7 */
/* @0x1be5b8 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1be5bc cmp r0, #0 */
/* @0x1be5c0 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1be5c4 ldr r3, [r0] */
/* @0x1be5c8 cmp r3, #5 */
/* @0x1be5cc popne {r3, r4, r5, r6, r7, pc} */
/* @0x1be5d0 ldr r2, [r0, #0x2c] */
/* @0x1be5d4 vmov s15, r2 */
/* @0x1be5d8 vcvt.f64.s32 d7, s15 */
/* @0x1be5dc vmov r2, r3, d7 */
/* @0x1be5e0 stm r5, {r2, r3} */
/* @0x1be5e4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1be5e8 andseq r0, r9, r12, lsr #11 */

/* ── FUNC 0x1be5ec · F_TilemapGetX(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x1be5ec cmp r3, #1 */
/* @0x1be5f0 push {r3, r4, r5, r6, r7, lr} */
/* @0x1be5f4 mov r3, #0 */
/* @0x1be5f8 mov r4, r3 */
/* @0x1be5fc mov r5, r0 */
/* @0x1be600 movt r3, #0xbff0 */
/* @0x1be604 str r4, [r0, #0xc] */
/* @0x1be608 str r3, [r0, #0x4] */
/* @0x1be60c str r4, [r0] */
/* @0x1be610 ldr r6, [sp, #0x18] */
/* @0x1be614 beq 0x1be62c <_Z13F_TilemapGetXR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1be618 ldr r0, [pc, #0x58] */
/* @0x1be61c mov r1, r4 */
/* @0x1be620 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1be624 add r0, pc, r0 */
/* @0x1be628 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1be62c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1be630 mov r1, r4 */
/* @0x1be634 mov r7, r0 */
/* @0x1be638 mov r0, r6 */
/* @0x1be63c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1be640 mov r2, r4 */
/* @0x1be644 mov r1, r0 */
/* @0x1be648 mov r0, r7 */
/* @0x1be64c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1be650 cmp r0, #0 */
/* @0x1be654 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1be658 ldr r3, [r0] */
/* @0x1be65c cmp r3, #5 */
/* @0x1be660 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1be664 vldr s15, [r0, #32] */
/* @0x1be668 vcvt.f64.f32 d6, s15 */
/* @0x1be66c vmov r2, r3, d6 */
/* @0x1be670 stm r5, {r2, r3} */
/* @0x1be674 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1be678 andseq r0, r9, r12, asr #10 */

/* ── FUNC 0x1be67c · F_TilemapGetY(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x1be67c cmp r3, #1 */
/* @0x1be680 push {r3, r4, r5, r6, r7, lr} */
/* @0x1be684 mov r3, #0 */
/* @0x1be688 mov r4, r3 */
/* @0x1be68c mov r5, r0 */
/* @0x1be690 movt r3, #0xbff0 */
/* @0x1be694 str r4, [r0, #0xc] */
/* @0x1be698 str r3, [r0, #0x4] */
/* @0x1be69c str r4, [r0] */
/* @0x1be6a0 ldr r6, [sp, #0x18] */
/* @0x1be6a4 beq 0x1be6bc <_Z13F_TilemapGetYR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1be6a8 ldr r0, [pc, #0x58] */
/* @0x1be6ac mov r1, r4 */
/* @0x1be6b0 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1be6b4 add r0, pc, r0 */
/* @0x1be6b8 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1be6bc bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1be6c0 mov r1, r4 */
/* @0x1be6c4 mov r7, r0 */
/* @0x1be6c8 mov r0, r6 */
/* @0x1be6cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1be6d0 mov r2, r4 */
/* @0x1be6d4 mov r1, r0 */
/* @0x1be6d8 mov r0, r7 */
/* @0x1be6dc bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1be6e0 cmp r0, #0 */
/* @0x1be6e4 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1be6e8 ldr r3, [r0] */
/* @0x1be6ec cmp r3, #5 */
/* @0x1be6f0 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1be6f4 vldr s15, [r0, #36] */
/* @0x1be6f8 vcvt.f64.f32 d6, s15 */
/* @0x1be6fc vmov r2, r3, d6 */
/* @0x1be700 stm r5, {r2, r3} */
/* @0x1be704 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1be708 andseq r0, r9, r8, ror #9 */

/* ── FUNC 0x1be70c · F_TilemapGet(RValue&, CInstance*, CInstance*, int, RValue*) · size=300 · insn=75 */
/* @0x1be70c cmp r3, #3 */
/* @0x1be710 push {r3, r4, r5, r6, r7, lr} */
/* @0x1be714 mov r3, #0 */
/* @0x1be718 mov r4, r3 */
/* @0x1be71c mov r5, r0 */
/* @0x1be720 movt r3, #0xbff0 */
/* @0x1be724 str r4, [r0, #0xc] */
/* @0x1be728 str r3, [r0, #0x4] */
/* @0x1be72c str r4, [r0] */
/* @0x1be730 ldr r6, [sp, #0x18] */
/* @0x1be734 beq 0x1be74c <_Z12F_TilemapGetR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1be738 ldr r0, [pc, #0xe8] */
/* @0x1be73c mov r1, r4 */
/* @0x1be740 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1be744 add r0, pc, r0 */
/* @0x1be748 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1be74c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1be750 mov r1, r4 */
/* @0x1be754 mov r7, r0 */
/* @0x1be758 mov r0, r6 */
/* @0x1be75c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1be760 mov r2, r4 */
/* @0x1be764 mov r1, r0 */
/* @0x1be768 mov r0, r7 */
/* @0x1be76c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1be770 subs r4, r0, #0 */
/* @0x1be774 beq 0x1be784 <_Z12F_TilemapGetR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1be778 ldr r3, [r4] */
/* @0x1be77c cmp r3, #5 */
/* @0x1be780 beq 0x1be7a8 <_Z12F_TilemapGetR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x1be784 ldr r3, [pc, #0xa0] */
/* @0x1be788 ldr r1, [pc, #0xa0] */
/* @0x1be78c ldr r3, [pc, r3] */
/* @0x1be790 add r1, pc, r1 */
/* @0x1be794 ldr r0, [r3] */
/* @0x1be798 ldr r3, [r0] */
/* @0x1be79c ldr r3, [r3, #0xc] */
/* @0x1be7a0 blx r3 */
/* @0x1be7a4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1be7a8 ldr r1, [r4, #0x34] */
/* @0x1be7ac cmp r1, #0 */
/* @0x1be7b0 beq 0x1be818 <_Z12F_TilemapGetR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x1be7b4 mov r1, #1 */
/* @0x1be7b8 mov r0, r6 */
/* @0x1be7bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1be7c0 mov r1, #2 */
/* @0x1be7c4 mov r7, r0 */
/* @0x1be7c8 mov r0, r6 */
/* @0x1be7cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1be7d0 cmp r7, #0 */
/* @0x1be7d4 poplt {r3, r4, r5, r6, r7, pc} */
/* @0x1be7d8 ldr r3, [r4, #0x28] */
/* @0x1be7dc cmp r7, r3 */
/* @0x1be7e0 popge {r3, r4, r5, r6, r7, pc} */
/* @0x1be7e4 cmp r0, #0 */
/* @0x1be7e8 poplt {r3, r4, r5, r6, r7, pc} */
/* @0x1be7ec ldr r2, [r4, #0x2c] */
/* @0x1be7f0 cmp r0, r2 */
/* @0x1be7f4 popge {r3, r4, r5, r6, r7, pc} */
/* @0x1be7f8 mla r3, r3, r0, r7 */
/* @0x1be7fc ldr r2, [r4, #0x34] */
/* @0x1be800 ldr r2, [r2, r3, lsl #2] */
/* @0x1be804 vmov s15, r2 */
/* @0x1be808 vcvt.f64.u32 d7, s15 */
/* @0x1be80c vmov r2, r3, d7 */
/* @0x1be810 stm r5, {r2, r3} */
/* @0x1be814 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1be818 ldr r0, [pc, #0x14] */
/* @0x1be81c pop {r3, r4, r5, r6, r7, lr} */
/* @0x1be820 add r0, pc, r0 */
/* @0x1be824 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1be828 andseq r0, r9, r4, lsl #9 */
/* @0x1be82c eoreq lr, r2, r8, lsl #31 */
/* @0x1be830 mulseq r9, r0, r4 */
/* @0x1be834 ldrsbeq r0, [r9], -r4 */

/* ── FUNC 0x1be838 · F_TilemapGetAtPixel(RValue&, CInstance*, CInstance*, int, RValue*) · size=616 · insn=154 */
/* @0x1be838 cmp r3, #3 */
/* @0x1be83c mov r3, #0 */
/* @0x1be840 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1be844 vpush {d8, d9} */
/* @0x1be848 mov r4, r3 */
/* @0x1be84c sub sp, sp, #12 */
/* @0x1be850 movt r3, #0xbff0 */
/* @0x1be854 mov r5, r0 */
/* @0x1be858 str r4, [r0, #0xc] */
/* @0x1be85c str r3, [r0, #0x4] */
/* @0x1be860 str r4, [r0] */
/* @0x1be864 beq 0x1be884 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x1be868 ldr r0, [pc, #0x21c] */
/* @0x1be86c mov r1, r4 */
/* @0x1be870 add r0, pc, r0 */
/* @0x1be874 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1be878 add sp, sp, #12 */
/* @0x1be87c vpop {d8, d9} */
/* @0x1be880 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1be884 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1be888 add r6, sp, #8 */
/* @0x1be88c mov r1, r4 */
/* @0x1be890 str r4, [r6, #-0x4]! */
/* @0x1be894 mov r7, r0 */
/* @0x1be898 ldr r0, [sp, #0x38] */
/* @0x1be89c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1be8a0 mov r2, r6 */
/* @0x1be8a4 mov r1, r0 */
/* @0x1be8a8 mov r0, r7 */
/* @0x1be8ac bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1be8b0 subs r4, r0, #0 */
/* @0x1be8b4 beq 0x1be8c4 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x1be8b8 ldr r3, [r4] */
/* @0x1be8bc cmp r3, #5 */
/* @0x1be8c0 beq 0x1be8f0 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x1be8c4 ldr r3, [pc, #0x1c4] */
/* @0x1be8c8 ldr r1, [pc, #0x1c4] */
/* @0x1be8cc ldr r3, [pc, r3] */
/* @0x1be8d0 add r1, pc, r1 */
/* @0x1be8d4 ldr r0, [r3] */
/* @0x1be8d8 ldr r3, [r0] */
/* @0x1be8dc ldr r3, [r3, #0xc] */
/* @0x1be8e0 blx r3 */
/* @0x1be8e4 add sp, sp, #12 */
/* @0x1be8e8 vpop {d8, d9} */
/* @0x1be8ec pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1be8f0 ldr r3, [sp, #0x4] */
/* @0x1be8f4 cmp r3, #0 */
/* @0x1be8f8 beq 0x1be8c4 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x1be8fc ldr r1, [r4, #0x34] */
/* @0x1be900 cmp r1, #0 */
/* @0x1be904 beq 0x1bea7c <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x244> */
/* @0x1be908 ldr r0, [r4, #0x1c] */
/* @0x1be90c bl 0xc3794 <_Z15Background_Datai> */
/* @0x1be910 subs r3, r0, #0 */
/* @0x1be914 beq 0x1bea68 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x230> */
/* @0x1be918 mov r1, #1 */
/* @0x1be91c ldr r0, [sp, #0x38] */
/* @0x1be920 ldr r2, [sp, #0x4] */
/* @0x1be924 vldr s16, [r4, #32] */
/* @0x1be928 vldr s15, [r2, #8] */
/* @0x1be92c vldr s18, [r2, #12] */
/* @0x1be930 vadd.f32 s16, s16, s15 */
/* @0x1be934 ldr r6, [r3, #0x1c] */
/* @0x1be938 ldr r8, [r3, #0x20] */
/* @0x1be93c vldr s19, [r4, #36] */
/* @0x1be940 ldr r7, [r4, #0x28] */
/* @0x1be944 ldr r9, [r4, #0x2c] */
/* @0x1be948 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1be94c mov r1, #2 */
/* @0x1be950 vmov s17, r0 */
/* @0x1be954 ldr r0, [sp, #0x38] */
/* @0x1be958 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1be95c vsub.f32 s15, s17, s16 */
/* @0x1be960 vcmpe.f32 s15, #0 */
/* @0x1be964 vmrs APSR_nzcv, fpscr */
/* @0x1be968 vmov s13, r0 */
/* @0x1be96c bmi 0x1be878 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1be970 mul r7, r7, r6 */
/* @0x1be974 vmov s12, r7 */
/* @0x1be978 vcvt.f32.s32 s14, s12 */
/* @0x1be97c vcmpe.f32 s14, s15 */
/* @0x1be980 vmrs APSR_nzcv, fpscr */
/* @0x1be984 bls 0x1be878 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1be988 vadd.f32 s18, s19, s18 */
/* @0x1be98c vsub.f32 s18, s13, s18 */
/* @0x1be990 vcmpe.f32 s18, #0 */
/* @0x1be994 vmrs APSR_nzcv, fpscr */
/* @0x1be998 bmi 0x1be878 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1be99c mul r9, r9, r8 */
/* @0x1be9a0 vmov s13, r9 */
/* @0x1be9a4 vcvt.f32.s32 s14, s13 */
/* @0x1be9a8 vcmpe.f32 s14, s18 */
/* @0x1be9ac vmrs APSR_nzcv, fpscr */
/* @0x1be9b0 bls 0x1be878 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1be9b4 vmov.f32 s16, #1.000000e+00 */
/* @0x1be9b8 vmov s12, r6 */
/* @0x1be9bc vcvt.f32.s32 s14, s12 */
/* @0x1be9c0 vdiv.f32 s14, s16, s14 */
/* @0x1be9c4 vmul.f32 s14, s15, s14 */
/* @0x1be9c8 vmov r0, s14 */
/* @0x1be9cc bl 0xb6910 <floorf@plt> */
/* @0x1be9d0 vmov s13, r8 */
/* @0x1be9d4 vcvt.f32.s32 s15, s13 */
/* @0x1be9d8 vdiv.f32 s16, s16, s15 */
/* @0x1be9dc vmov s14, r0 */
/* @0x1be9e0 vmul.f32 s16, s18, s16 */
/* @0x1be9e4 vcvt.s32.f32 s14, s14 */
/* @0x1be9e8 vmov r0, s16 */
/* @0x1be9ec vmov r6, s14 */
/* @0x1be9f0 bl 0xb6910 <floorf@plt> */
/* @0x1be9f4 ldr r3, [r4, #0x28] */
/* @0x1be9f8 cmp r6, r3 */
/* @0x1be9fc lsrge r2, r3, #31 */
/* @0x1bea00 lsrlt r2, r6, #31 */
/* @0x1bea04 cmp r6, r3 */
/* @0x1bea08 movge r6, r3 */
/* @0x1bea0c vmov s15, r0 */
/* @0x1bea10 cmp r2, #0 */
/* @0x1bea14 ldr r2, [r4, #0x2c] */
/* @0x1bea18 vcvt.s32.f32 s15, s15 */
/* @0x1bea1c movne r6, #0 */
/* @0x1bea20 vmov r0, s15 */
/* @0x1bea24 cmp r0, r2 */
/* @0x1bea28 lsrge r1, r2, #31 */
/* @0x1bea2c lsrlt r1, r0, #31 */
/* @0x1bea30 cmp r1, #0 */
/* @0x1bea34 movne r3, #0 */
/* @0x1bea38 bne 0x1bea48 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x210> */
/* @0x1bea3c cmp r2, r0 */
/* @0x1bea40 movge r2, r0 */
/* @0x1bea44 mul r3, r2, r3 */
/* @0x1bea48 ldr r2, [r4, #0x34] */
/* @0x1bea4c add r3, r6, r3 */
/* @0x1bea50 ldr r2, [r2, r3, lsl #2] */
/* @0x1bea54 vmov s13, r2 */
/* @0x1bea58 vcvt.f64.u32 d6, s13 */
/* @0x1bea5c vmov r2, r3, d6 */
/* @0x1bea60 stm r5, {r2, r3} */
/* @0x1bea64 b 0x1be878 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bea68 ldr r0, [pc, #0x28] */
/* @0x1bea6c mov r1, r3 */
/* @0x1bea70 add r0, pc, r0 */
/* @0x1bea74 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bea78 b 0x1be878 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bea7c ldr r0, [pc, #0x18] */
/* @0x1bea80 add r0, pc, r0 */
/* @0x1bea84 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bea88 b 0x1be878 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bea8c andseq r0, r9, r4, ror #7 */
/* @0x1bea90 eoreq lr, r2, r8, asr #28 */
/* @0x1bea94 andseq r0, r9, r12, lsr #8 */
/* @0x1bea98 andseq r0, r9, r12, asr #4 */
/* @0x1bea9c andseq r0, r9, r8, lsl #4 */

/* ── FUNC 0x1beaa0 · F_TilemapGetCellXAtPixel(RValue&, CInstance*, CInstance*, int, RValue*) · size=488 · insn=122 */
/* @0x1beaa0 cmp r3, #3 */
/* @0x1beaa4 mov r3, #0 */
/* @0x1beaa8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1beaac vpush {d8, d9} */
/* @0x1beab0 mov r4, r3 */
/* @0x1beab4 sub sp, sp, #8 */
/* @0x1beab8 movt r3, #0xbff0 */
/* @0x1beabc mov r5, r0 */
/* @0x1beac0 str r4, [r0, #0xc] */
/* @0x1beac4 str r3, [r0, #0x4] */
/* @0x1beac8 str r4, [r0] */
/* @0x1beacc beq 0x1beaec <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x1bead0 ldr r0, [pc, #0x19c] */
/* @0x1bead4 mov r1, r4 */
/* @0x1bead8 add r0, pc, r0 */
/* @0x1beadc bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1beae0 add sp, sp, #8 */
/* @0x1beae4 vpop {d8, d9} */
/* @0x1beae8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1beaec bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1beaf0 add r6, sp, #8 */
/* @0x1beaf4 mov r1, r4 */
/* @0x1beaf8 str r4, [r6, #-0x4]! */
/* @0x1beafc mov r7, r0 */
/* @0x1beb00 ldr r0, [sp, #0x30] */
/* @0x1beb04 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1beb08 mov r2, r6 */
/* @0x1beb0c mov r1, r0 */
/* @0x1beb10 mov r0, r7 */
/* @0x1beb14 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1beb18 subs r4, r0, #0 */
/* @0x1beb1c beq 0x1beb2c <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x1beb20 ldr r3, [r4] */
/* @0x1beb24 cmp r3, #5 */
/* @0x1beb28 beq 0x1beb58 <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x1beb2c ldr r3, [pc, #0x144] */
/* @0x1beb30 ldr r1, [pc, #0x144] */
/* @0x1beb34 ldr r3, [pc, r3] */
/* @0x1beb38 add r1, pc, r1 */
/* @0x1beb3c ldr r0, [r3] */
/* @0x1beb40 ldr r3, [r0] */
/* @0x1beb44 ldr r3, [r3, #0xc] */
/* @0x1beb48 blx r3 */
/* @0x1beb4c add sp, sp, #8 */
/* @0x1beb50 vpop {d8, d9} */
/* @0x1beb54 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1beb58 ldr r3, [sp, #0x4] */
/* @0x1beb5c cmp r3, #0 */
/* @0x1beb60 beq 0x1beb2c <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x1beb64 ldr r1, [r4, #0x34] */
/* @0x1beb68 cmp r1, #0 */
/* @0x1beb6c beq 0x1bec64 <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x1c4> */
/* @0x1beb70 ldr r0, [r4, #0x1c] */
/* @0x1beb74 bl 0xc3794 <_Z15Background_Datai> */
/* @0x1beb78 subs r3, r0, #0 */
/* @0x1beb7c beq 0x1bec50 <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x1b0> */
/* @0x1beb80 mov r1, #1 */
/* @0x1beb84 ldr r0, [sp, #0x30] */
/* @0x1beb88 ldr r2, [sp, #0x4] */
/* @0x1beb8c vldr s16, [r4, #32] */
/* @0x1beb90 vldr s15, [r2, #8] */
/* @0x1beb94 vldr s18, [r2, #12] */
/* @0x1beb98 vadd.f32 s16, s16, s15 */
/* @0x1beb9c ldr r6, [r3, #0x1c] */
/* @0x1beba0 ldr r8, [r3, #0x20] */
/* @0x1beba4 vldr s19, [r4, #36] */
/* @0x1beba8 ldr r7, [r4, #0x28] */
/* @0x1bebac ldr r4, [r4, #0x2c] */
/* @0x1bebb0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bebb4 mov r1, #2 */
/* @0x1bebb8 vmov s17, r0 */
/* @0x1bebbc ldr r0, [sp, #0x30] */
/* @0x1bebc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bebc4 vsub.f32 s15, s17, s16 */
/* @0x1bebc8 vcmpe.f32 s15, #0 */
/* @0x1bebcc vmrs APSR_nzcv, fpscr */
/* @0x1bebd0 vmov s13, r0 */
/* @0x1bebd4 bmi 0x1beae0 <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bebd8 mul r7, r7, r6 */
/* @0x1bebdc vmov s12, r7 */
/* @0x1bebe0 vcvt.f32.s32 s14, s12 */
/* @0x1bebe4 vcmpe.f32 s14, s15 */
/* @0x1bebe8 vmrs APSR_nzcv, fpscr */
/* @0x1bebec bls 0x1beae0 <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bebf0 vadd.f32 s18, s19, s18 */
/* @0x1bebf4 vsub.f32 s13, s13, s18 */
/* @0x1bebf8 vcmpe.f32 s13, #0 */
/* @0x1bebfc vmrs APSR_nzcv, fpscr */
/* @0x1bec00 bmi 0x1beae0 <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bec04 mul r4, r4, r8 */
/* @0x1bec08 vmov s12, r4 */
/* @0x1bec0c vcvt.f32.s32 s14, s12 */
/* @0x1bec10 vcmpe.f32 s14, s13 */
/* @0x1bec14 vmrs APSR_nzcv, fpscr */
/* @0x1bec18 bls 0x1beae0 <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bec1c vmov.f32 s13, #1.000000e+00 */
/* @0x1bec20 vmov s12, r6 */
/* @0x1bec24 vcvt.f32.s32 s14, s12 */
/* @0x1bec28 vdiv.f32 s14, s13, s14 */
/* @0x1bec2c vmul.f32 s14, s15, s14 */
/* @0x1bec30 vmov r0, s14 */
/* @0x1bec34 bl 0xb6910 <floorf@plt> */
/* @0x1bec38 vmov s13, r0 */
/* @0x1bec3c vcvt.s32.f32 s15, s13 */
/* @0x1bec40 vcvt.f64.s32 d6, s15 */
/* @0x1bec44 vmov r2, r3, d6 */
/* @0x1bec48 stm r5, {r2, r3} */
/* @0x1bec4c b 0x1beae0 <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bec50 ldr r0, [pc, #0x28] */
/* @0x1bec54 mov r1, r3 */
/* @0x1bec58 add r0, pc, r0 */
/* @0x1bec5c bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bec60 b 0x1beae0 <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bec64 ldr r0, [pc, #0x18] */
/* @0x1bec68 add r0, pc, r0 */
/* @0x1bec6c bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bec70 b 0x1beae0 <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bec74 andseq r0, r9, r0, ror #4 */
/* @0x1bec78 eoreq lr, r2, r0, ror #23 */
/* @0x1bec7c ldrheq r0, [r9], -r12 */
/* @0x1bec80 andseq r0, r9, r8, asr r1 */
/* @0x1bec84 andseq r0, r9, r12, lsl #2 */

/* ── FUNC 0x1bec88 · F_TilemapGetCellYAtPixel(RValue&, CInstance*, CInstance*, int, RValue*) · size=488 · insn=122 */
/* @0x1bec88 cmp r3, #3 */
/* @0x1bec8c mov r3, #0 */
/* @0x1bec90 push {r4, r5, r6, r7, r8, lr} */
/* @0x1bec94 vpush {d8, d9} */
/* @0x1bec98 mov r4, r3 */
/* @0x1bec9c sub sp, sp, #8 */
/* @0x1beca0 movt r3, #0xbff0 */
/* @0x1beca4 mov r5, r0 */
/* @0x1beca8 str r4, [r0, #0xc] */
/* @0x1becac str r3, [r0, #0x4] */
/* @0x1becb0 str r4, [r0] */
/* @0x1becb4 beq 0x1becd4 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x1becb8 ldr r0, [pc, #0x19c] */
/* @0x1becbc mov r1, r4 */
/* @0x1becc0 add r0, pc, r0 */
/* @0x1becc4 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1becc8 add sp, sp, #8 */
/* @0x1beccc vpop {d8, d9} */
/* @0x1becd0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1becd4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1becd8 add r6, sp, #8 */
/* @0x1becdc mov r1, r4 */
/* @0x1bece0 str r4, [r6, #-0x4]! */
/* @0x1bece4 mov r7, r0 */
/* @0x1bece8 ldr r0, [sp, #0x30] */
/* @0x1becec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1becf0 mov r2, r6 */
/* @0x1becf4 mov r1, r0 */
/* @0x1becf8 mov r0, r7 */
/* @0x1becfc bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bed00 subs r4, r0, #0 */
/* @0x1bed04 beq 0x1bed14 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x1bed08 ldr r3, [r4] */
/* @0x1bed0c cmp r3, #5 */
/* @0x1bed10 beq 0x1bed40 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x1bed14 ldr r3, [pc, #0x144] */
/* @0x1bed18 ldr r1, [pc, #0x144] */
/* @0x1bed1c ldr r3, [pc, r3] */
/* @0x1bed20 add r1, pc, r1 */
/* @0x1bed24 ldr r0, [r3] */
/* @0x1bed28 ldr r3, [r0] */
/* @0x1bed2c ldr r3, [r3, #0xc] */
/* @0x1bed30 blx r3 */
/* @0x1bed34 add sp, sp, #8 */
/* @0x1bed38 vpop {d8, d9} */
/* @0x1bed3c pop {r4, r5, r6, r7, r8, pc} */
/* @0x1bed40 ldr r3, [sp, #0x4] */
/* @0x1bed44 cmp r3, #0 */
/* @0x1bed48 beq 0x1bed14 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x1bed4c ldr r1, [r4, #0x34] */
/* @0x1bed50 cmp r1, #0 */
/* @0x1bed54 beq 0x1bee4c <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x1c4> */
/* @0x1bed58 ldr r0, [r4, #0x1c] */
/* @0x1bed5c bl 0xc3794 <_Z15Background_Datai> */
/* @0x1bed60 subs r3, r0, #0 */
/* @0x1bed64 beq 0x1bee38 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x1b0> */
/* @0x1bed68 mov r1, #1 */
/* @0x1bed6c ldr r0, [sp, #0x30] */
/* @0x1bed70 ldr r2, [sp, #0x4] */
/* @0x1bed74 vldr s16, [r4, #32] */
/* @0x1bed78 vldr s15, [r2, #8] */
/* @0x1bed7c vldr s18, [r2, #12] */
/* @0x1bed80 vadd.f32 s16, s16, s15 */
/* @0x1bed84 ldr r6, [r3, #0x1c] */
/* @0x1bed88 ldr r8, [r3, #0x20] */
/* @0x1bed8c vldr s19, [r4, #36] */
/* @0x1bed90 ldr r7, [r4, #0x28] */
/* @0x1bed94 ldr r4, [r4, #0x2c] */
/* @0x1bed98 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bed9c mov r1, #2 */
/* @0x1beda0 vmov s17, r0 */
/* @0x1beda4 ldr r0, [sp, #0x30] */
/* @0x1beda8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bedac vsub.f32 s15, s17, s16 */
/* @0x1bedb0 vcmpe.f32 s15, #0 */
/* @0x1bedb4 vmrs APSR_nzcv, fpscr */
/* @0x1bedb8 vmov s13, r0 */
/* @0x1bedbc bmi 0x1becc8 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bedc0 mul r6, r7, r6 */
/* @0x1bedc4 vmov s12, r6 */
/* @0x1bedc8 vcvt.f32.s32 s14, s12 */
/* @0x1bedcc vcmpe.f32 s14, s15 */
/* @0x1bedd0 vmrs APSR_nzcv, fpscr */
/* @0x1bedd4 bls 0x1becc8 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bedd8 vadd.f32 s18, s19, s18 */
/* @0x1beddc vsub.f32 s13, s13, s18 */
/* @0x1bede0 vcmpe.f32 s13, #0 */
/* @0x1bede4 vmrs APSR_nzcv, fpscr */
/* @0x1bede8 bmi 0x1becc8 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bedec mul r4, r4, r8 */
/* @0x1bedf0 vmov s14, r4 */
/* @0x1bedf4 vcvt.f32.s32 s15, s14 */
/* @0x1bedf8 vcmpe.f32 s15, s13 */
/* @0x1bedfc vmrs APSR_nzcv, fpscr */
/* @0x1bee00 bls 0x1becc8 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bee04 vmov.f32 s14, #1.000000e+00 */
/* @0x1bee08 vmov s12, r8 */
/* @0x1bee0c vcvt.f32.s32 s15, s12 */
/* @0x1bee10 vdiv.f32 s15, s14, s15 */
/* @0x1bee14 vmul.f32 s15, s13, s15 */
/* @0x1bee18 vmov r0, s15 */
/* @0x1bee1c bl 0xb6910 <floorf@plt> */
/* @0x1bee20 vmov s13, r0 */
/* @0x1bee24 vcvt.s32.f32 s15, s13 */
/* @0x1bee28 vcvt.f64.s32 d6, s15 */
/* @0x1bee2c vmov r2, r3, d6 */
/* @0x1bee30 stm r5, {r2, r3} */
/* @0x1bee34 b 0x1becc8 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bee38 ldr r0, [pc, #0x28] */
/* @0x1bee3c mov r1, r3 */
/* @0x1bee40 add r0, pc, r0 */
/* @0x1bee44 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bee48 b 0x1becc8 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bee4c ldr r0, [pc, #0x18] */
/* @0x1bee50 add r0, pc, r0 */
/* @0x1bee54 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bee58 b 0x1becc8 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bee5c andseq r0, r9, r8, ror r1 */
/* @0x1bee60 .word 0x0022e9f8 */
/* @0x1bee64 ldrsbeq r0, [r9], -r4 */
/* @0x1bee68 andseq r0, r9, r0, ror r0 */
/* @0x1bee6c andseq r0, r9, r4, lsr #32 */

/* ── FUNC 0x1bee70 · F_TilemapClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=284 · insn=71 */
/* @0x1bee70 cmp r3, #2 */
/* @0x1bee74 mov r3, #0 */
/* @0x1bee78 push {r4, r5, r6, lr} */
/* @0x1bee7c mov r5, r3 */
/* @0x1bee80 sub sp, sp, #8 */
/* @0x1bee84 movt r3, #0xbff0 */
/* @0x1bee88 str r5, [r0, #0xc] */
/* @0x1bee8c str r3, [r0, #0x4] */
/* @0x1bee90 str r5, [r0] */
/* @0x1bee94 beq 0x1beeb0 <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bee98 ldr r0, [pc, #0xe4] */
/* @0x1bee9c mov r1, r5 */
/* @0x1beea0 add r0, pc, r0 */
/* @0x1beea4 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1beea8 add sp, sp, #8 */
/* @0x1beeac pop {r4, r5, r6, pc} */
/* @0x1beeb0 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1beeb4 add r4, sp, #8 */
/* @0x1beeb8 mov r1, r5 */
/* @0x1beebc str r5, [r4, #-0x4]! */
/* @0x1beec0 mov r6, r0 */
/* @0x1beec4 ldr r0, [sp, #0x18] */
/* @0x1beec8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1beecc mov r2, r4 */
/* @0x1beed0 mov r1, r0 */
/* @0x1beed4 mov r0, r6 */
/* @0x1beed8 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1beedc subs r4, r0, #0 */
/* @0x1beee0 beq 0x1beea8 <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1beee4 ldr r3, [r4] */
/* @0x1beee8 cmp r3, #5 */
/* @0x1beeec bne 0x1beea8 <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1beef0 ldr r3, [sp, #0x4] */
/* @0x1beef4 cmp r3, #0 */
/* @0x1beef8 beq 0x1beea8 <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1beefc ldr r1, [r4, #0x34] */
/* @0x1bef00 cmp r1, #0 */
/* @0x1bef04 beq 0x1bef74 <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x1bef08 ldr r0, [sp, #0x18] */
/* @0x1bef0c mov r1, #1 */
/* @0x1bef10 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bef14 ldr r3, [r4, #0x2c] */
/* @0x1bef18 cmp r3, #0 */
/* @0x1bef1c ble 0x1beea8 <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1bef20 ldr r2, [r4, #0x28] */
/* @0x1bef24 mov r1, r5 */
/* @0x1bef28 mov r6, r5 */
/* @0x1bef2c cmp r2, #0 */
/* @0x1bef30 ble 0x1bef64 <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x1bef34 ldr r2, [r4, #0x34] */
/* @0x1bef38 sub r12, r6, #-1073741823 */
/* @0x1bef3c mov r5, r6 */
/* @0x1bef40 mov r3, #0 */
/* @0x1bef44 add r12, r2, r12, lsl #2 */
/* @0x1bef48 str r0, [r12, #0x4]! */
/* @0x1bef4c add r3, r3, #1 */
/* @0x1bef50 ldr r2, [r4, #0x28] */
/* @0x1bef54 add r6, r3, r5 */
/* @0x1bef58 cmp r2, r3 */
/* @0x1bef5c bgt 0x1bef48 <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x1bef60 ldr r3, [r4, #0x2c] */
/* @0x1bef64 add r1, r1, #1 */
/* @0x1bef68 cmp r3, r1 */
/* @0x1bef6c bgt 0x1bef2c <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x1bef70 b 0x1beea8 <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1bef74 ldr r0, [pc, #0xc] */
/* @0x1bef78 add r0, pc, r0 */
/* @0x1bef7c bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bef80 b 0x1beea8 <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1bef84 mulseq r9, r8, r0 */
/* @0x1bef88 andseq pc, r8, r12, ror #31 */

/* ── FUNC 0x1bef8c · F_DrawTilemap(RValue&, CInstance*, CInstance*, int, RValue*) · size=284 · insn=71 */
/* @0x1bef8c push {r4, r5, r6, r7, r8, lr} */
/* @0x1bef90 cmp r3, #3 */
/* @0x1bef94 sub sp, sp, #8 */
/* @0x1bef98 mov r3, #0 */
/* @0x1bef9c mov r4, r3 */
/* @0x1befa0 mov r6, r1 */
/* @0x1befa4 movt r3, #0xbff0 */
/* @0x1befa8 str r4, [r0, #0xc] */
/* @0x1befac str r3, [r0, #0x4] */
/* @0x1befb0 str r4, [r0] */
/* @0x1befb4 ldr r5, [sp, #0x20] */
/* @0x1befb8 beq 0x1befd4 <_Z13F_DrawTilemapR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1befbc ldr r0, [pc, #0xd0] */
/* @0x1befc0 mov r1, r4 */
/* @0x1befc4 add r0, pc, r0 */
/* @0x1befc8 add sp, sp, #8 */
/* @0x1befcc pop {r4, r5, r6, r7, r8, lr} */
/* @0x1befd0 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1befd4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1befd8 mov r1, r4 */
/* @0x1befdc mov r7, r0 */
/* @0x1befe0 mov r0, r5 */
/* @0x1befe4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1befe8 mov r2, r4 */
/* @0x1befec mov r1, r0 */
/* @0x1beff0 mov r0, r7 */
/* @0x1beff4 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1beff8 subs r7, r0, #0 */
/* @0x1beffc beq 0x1bf00c <_Z13F_DrawTilemapR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x1bf000 ldr r3, [r7] */
/* @0x1bf004 cmp r3, #5 */
/* @0x1bf008 beq 0x1bf034 <_Z13F_DrawTilemapR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x1bf00c ldr r3, [pc, #0x84] */
/* @0x1bf010 ldr r1, [pc, #0x84] */
/* @0x1bf014 ldr r3, [pc, r3] */
/* @0x1bf018 add r1, pc, r1 */
/* @0x1bf01c ldr r0, [r3] */
/* @0x1bf020 ldr r3, [r0] */
/* @0x1bf024 ldr r3, [r3, #0xc] */
/* @0x1bf028 blx r3 */
/* @0x1bf02c add sp, sp, #8 */
/* @0x1bf030 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1bf034 ldr r1, [r7, #0x34] */
/* @0x1bf038 cmp r1, #0 */
/* @0x1bf03c beq 0x1bf088 <_Z13F_DrawTilemapR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x1bf040 mov r0, r5 */
/* @0x1bf044 mov r1, #1 */
/* @0x1bf048 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bf04c mov r1, #2 */
/* @0x1bf050 mov r8, r0 */
/* @0x1bf054 mov r0, r5 */
/* @0x1bf058 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bf05c ldr r12, [pc, #0x3c] */
/* @0x1bf060 ldr r2, [r6, #0x180] */
/* @0x1bf064 mov r3, r8 */
/* @0x1bf068 ldr r12, [pc, r12] */
/* @0x1bf06c mov r1, r4 */
/* @0x1bf070 str r2, [sp, #0x4] */
/* @0x1bf074 mov r2, r7 */
/* @0x1bf078 str r0, [sp] */
/* @0x1bf07c mov r0, r12 */
/* @0x1bf080 bl 0x1b2124 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff> */
/* @0x1bf084 b 0x1bf02c <_Z13F_DrawTilemapR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x1bf088 ldr r0, [pc, #0x14] */
/* @0x1bf08c add r0, pc, r0 */
/* @0x1bf090 b 0x1befc8 <_Z13F_DrawTilemapR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bf094 andseq pc, r8, r12, asr #31 */
/* @0x1bf098 eoreq lr, r2, r0, lsl #14 */
/* @0x1bf09c ldrsbeq pc, [r8], -r0 */
/* @0x1bf0a0 eoreq r1, r3, r4, ror #1 */
/* @0x1bf0a4 andseq pc, r8, r0, lsr pc */

/* ── FUNC 0x1bf0a8 · F_TilemapSetMask(RValue&, CInstance*, CInstance*, int, RValue*) · size=184 · insn=46 */
/* @0x1bf0a8 cmp r3, #2 */
/* @0x1bf0ac mov r3, #0 */
/* @0x1bf0b0 push {r4, r5, r6, lr} */
/* @0x1bf0b4 mov r4, r3 */
/* @0x1bf0b8 ldr r5, [sp, #0x10] */
/* @0x1bf0bc movt r3, #0xbff0 */
/* @0x1bf0c0 str r4, [r0, #0xc] */
/* @0x1bf0c4 str r3, [r0, #0x4] */
/* @0x1bf0c8 str r4, [r0] */
/* @0x1bf0cc beq 0x1bf0e4 <_Z16F_TilemapSetMaskR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bf0d0 ldr r0, [pc, #0x7c] */
/* @0x1bf0d4 mov r1, r4 */
/* @0x1bf0d8 pop {r4, r5, r6, lr} */
/* @0x1bf0dc add r0, pc, r0 */
/* @0x1bf0e0 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bf0e4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bf0e8 mov r1, r4 */
/* @0x1bf0ec mov r6, r0 */
/* @0x1bf0f0 mov r0, r5 */
/* @0x1bf0f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bf0f8 mov r2, r4 */
/* @0x1bf0fc mov r1, r0 */
/* @0x1bf100 mov r0, r6 */
/* @0x1bf104 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bf108 subs r4, r0, #0 */
/* @0x1bf10c beq 0x1bf11c <_Z16F_TilemapSetMaskR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x1bf110 ldr r3, [r4] */
/* @0x1bf114 cmp r3, #5 */
/* @0x1bf118 beq 0x1bf140 <_Z16F_TilemapSetMaskR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x1bf11c ldr r3, [pc, #0x34] */
/* @0x1bf120 ldr r1, [pc, #0x34] */
/* @0x1bf124 ldr r3, [pc, r3] */
/* @0x1bf128 add r1, pc, r1 */
/* @0x1bf12c ldr r0, [r3] */
/* @0x1bf130 ldr r3, [r0] */
/* @0x1bf134 ldr r3, [r3, #0xc] */
/* @0x1bf138 blx r3 */
/* @0x1bf13c pop {r4, r5, r6, pc} */
/* @0x1bf140 mov r0, r5 */
/* @0x1bf144 mov r1, #1 */
/* @0x1bf148 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x1bf14c str r0, [r4, #0x38] */
/* @0x1bf150 pop {r4, r5, r6, pc} */
/* @0x1bf154 andseq pc, r8, r0, asr #30 */
/* @0x1bf158 .word 0x0022e5f0 */
/* @0x1bf15c andseq pc, r8, r4, lsr #30 */

/* ── FUNC 0x1bf160 · F_TilemapGetMask(RValue&, CInstance*, CInstance*, int, RValue*) · size=192 · insn=48 */
/* @0x1bf160 cmp r3, #1 */
/* @0x1bf164 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bf168 mov r3, #0 */
/* @0x1bf16c mov r4, r3 */
/* @0x1bf170 mov r5, r0 */
/* @0x1bf174 movt r3, #0xbff0 */
/* @0x1bf178 str r4, [r0, #0xc] */
/* @0x1bf17c str r3, [r0, #0x4] */
/* @0x1bf180 str r4, [r0] */
/* @0x1bf184 ldr r6, [sp, #0x18] */
/* @0x1bf188 beq 0x1bf1a0 <_Z16F_TilemapGetMaskR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bf18c ldr r0, [pc, #0x80] */
/* @0x1bf190 mov r1, r4 */
/* @0x1bf194 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bf198 add r0, pc, r0 */
/* @0x1bf19c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bf1a0 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bf1a4 mov r1, r4 */
/* @0x1bf1a8 mov r7, r0 */
/* @0x1bf1ac mov r0, r6 */
/* @0x1bf1b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bf1b4 mov r2, r4 */
/* @0x1bf1b8 mov r1, r0 */
/* @0x1bf1bc mov r0, r7 */
/* @0x1bf1c0 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bf1c4 cmp r0, #0 */
/* @0x1bf1c8 beq 0x1bf1d8 <_Z16F_TilemapGetMaskR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1bf1cc ldr r3, [r0] */
/* @0x1bf1d0 cmp r3, #5 */
/* @0x1bf1d4 beq 0x1bf1fc <_Z16F_TilemapGetMaskR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x1bf1d8 ldr r3, [pc, #0x38] */
/* @0x1bf1dc ldr r1, [pc, #0x38] */
/* @0x1bf1e0 ldr r3, [pc, r3] */
/* @0x1bf1e4 add r1, pc, r1 */
/* @0x1bf1e8 ldr r0, [r3] */
/* @0x1bf1ec ldr r3, [r0] */
/* @0x1bf1f0 ldr r3, [r3, #0xc] */
/* @0x1bf1f4 blx r3 */
/* @0x1bf1f8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bf1fc ldr r2, [r0, #0x38] */
/* @0x1bf200 vmov s15, r2 */
/* @0x1bf204 vcvt.f64.u32 d7, s15 */
/* @0x1bf208 vmov r2, r3, d7 */
/* @0x1bf20c stm r5, {r2, r3} */
/* @0x1bf210 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bf214 andseq pc, r8, r12, ror #29 */
/* @0x1bf218 eoreq lr, r2, r4, lsr r5 */
/* @0x1bf21c andseq pc, r8, r8, ror #28 */

/* ── FUNC 0x1bf220 · F_TilemapGetFrame(RValue&, CInstance*, CInstance*, int, RValue*) · size=188 · insn=47 */
/* @0x1bf220 cmp r3, #1 */
/* @0x1bf224 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bf228 mov r3, #0 */
/* @0x1bf22c mov r4, r3 */
/* @0x1bf230 mov r5, r0 */
/* @0x1bf234 movt r3, #0xbff0 */
/* @0x1bf238 str r4, [r0, #0xc] */
/* @0x1bf23c str r3, [r0, #0x4] */
/* @0x1bf240 str r4, [r0] */
/* @0x1bf244 ldr r6, [sp, #0x18] */
/* @0x1bf248 beq 0x1bf260 <_Z17F_TilemapGetFrameR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bf24c ldr r0, [pc, #0x7c] */
/* @0x1bf250 mov r1, r4 */
/* @0x1bf254 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bf258 add r0, pc, r0 */
/* @0x1bf25c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bf260 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bf264 mov r1, r4 */
/* @0x1bf268 mov r7, r0 */
/* @0x1bf26c mov r0, r6 */
/* @0x1bf270 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bf274 mov r2, r4 */
/* @0x1bf278 mov r1, r0 */
/* @0x1bf27c mov r0, r7 */
/* @0x1bf280 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bf284 cmp r0, #0 */
/* @0x1bf288 beq 0x1bf298 <_Z17F_TilemapGetFrameR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1bf28c ldr r3, [r0] */
/* @0x1bf290 cmp r3, #5 */
/* @0x1bf294 beq 0x1bf2bc <_Z17F_TilemapGetFrameR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x1bf298 ldr r3, [pc, #0x34] */
/* @0x1bf29c ldr r1, [pc, #0x34] */
/* @0x1bf2a0 ldr r3, [pc, r3] */
/* @0x1bf2a4 add r1, pc, r1 */
/* @0x1bf2a8 ldr r0, [r3] */
/* @0x1bf2ac ldr r3, [r0] */
/* @0x1bf2b0 ldr r3, [r3, #0xc] */
/* @0x1bf2b4 blx r3 */
/* @0x1bf2b8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bf2bc vldr s15, [r0, #48] */
/* @0x1bf2c0 vcvt.f64.f32 d6, s15 */
/* @0x1bf2c4 vmov r2, r3, d6 */
/* @0x1bf2c8 stm r5, {r2, r3} */
/* @0x1bf2cc pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bf2d0 andseq pc, r8, r12, asr lr */
/* @0x1bf2d4 eoreq lr, r2, r4, ror r4 */
/* @0x1bf2d8 andseq pc, r8, r0, asr #28 */

/* ── FUNC 0x1bf2dc · F_LayerGetElementLayer(RValue&, CInstance*, CInstance*, int, RValue*) · size=248 · insn=62 */
/* @0x1bf2dc push {r4, r5, r6, r7, r8, lr} */
/* @0x1bf2e0 cmp r3, #1 */
/* @0x1bf2e4 ldr r6, [pc, #0xd0] */
/* @0x1bf2e8 mov r3, #0 */
/* @0x1bf2ec mov r5, r3 */
/* @0x1bf2f0 mov r4, r0 */
/* @0x1bf2f4 movt r3, #0xbff0 */
/* @0x1bf2f8 add r6, pc, r6 */
/* @0x1bf2fc str r5, [r0, #0xc] */
/* @0x1bf300 str r3, [r0, #0x4] */
/* @0x1bf304 str r5, [r0] */
/* @0x1bf308 ldr r7, [sp, #0x18] */
/* @0x1bf30c beq 0x1bf324 <_Z22F_LayerGetElementLayerR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1bf310 ldr r0, [pc, #0xa8] */
/* @0x1bf314 mov r1, r5 */
/* @0x1bf318 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1bf31c add r0, pc, r0 */
/* @0x1bf320 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bf324 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bf328 subs r8, r0, #0 */
/* @0x1bf32c beq 0x1bf378 <_Z22F_LayerGetElementLayerR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x1bf330 mov r1, r5 */
/* @0x1bf334 mov r0, r7 */
/* @0x1bf338 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bf33c mov r2, r5 */
/* @0x1bf340 mov r1, r0 */
/* @0x1bf344 mov r0, r8 */
/* @0x1bf348 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bf34c cmp r0, #0 */
/* @0x1bf350 beq 0x1bf3ac <_Z22F_LayerGetElementLayerR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x1bf354 ldr r3, [r0, #0x10] */
/* @0x1bf358 cmp r3, #0 */
/* @0x1bf35c beq 0x1bf39c <_Z22F_LayerGetElementLayerR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x1bf360 ldr r2, [r3] */
/* @0x1bf364 vmov s15, r2 */
/* @0x1bf368 vcvt.f64.s32 d7, s15 */
/* @0x1bf36c vmov r2, r3, d7 */
/* @0x1bf370 stm r4, {r2, r3} */
/* @0x1bf374 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1bf378 ldr r1, [pc, #0x44] */
/* @0x1bf37c ldr r3, [pc, #0x44] */
/* @0x1bf380 add r1, pc, r1 */
/* @0x1bf384 ldr r3, [r6, r3] */
/* @0x1bf388 ldr r0, [r3] */
/* @0x1bf38c ldr r3, [r0] */
/* @0x1bf390 ldr r3, [r3, #0xc] */
/* @0x1bf394 blx r3 */
/* @0x1bf398 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1bf39c ldr r1, [pc, #0x28] */
/* @0x1bf3a0 ldr r3, [pc, #0x20] */
/* @0x1bf3a4 add r1, pc, r1 */
/* @0x1bf3a8 b 0x1bf384 <_Z22F_LayerGetElementLayerR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x1bf3ac ldr r1, [pc, #0x1c] */
/* @0x1bf3b0 ldr r3, [pc, #0x10] */
/* @0x1bf3b4 add r1, pc, r1 */
/* @0x1bf3b8 b 0x1bf384 <_Z22F_LayerGetElementLayerR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x1bf3bc eoreq r2, r3, r8, asr r9 */
/* @0x1bf3c0 andseq pc, r8, r0, lsl #28 */
/* @0x1bf3c4 andseq pc, r8, r0, asr lr */
/* @0x1bf3c8 .word 0xffffbac4 */
/* @0x1bf3cc ldrheq pc, [r8], -r0 */
/* @0x1bf3d0 andseq pc, r8, r0, ror #27 */

/* ── FUNC 0x1bf3d4 · F_LayerGetElementType(RValue&, CInstance*, CInstance*, int, RValue*) · size=228 · insn=57 */
/* @0x1bf3d4 cmp r3, #1 */
/* @0x1bf3d8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bf3dc mov r3, #0 */
/* @0x1bf3e0 mov r5, r3 */
/* @0x1bf3e4 mov r4, r0 */
/* @0x1bf3e8 movt r3, #0xbff0 */
/* @0x1bf3ec str r5, [r0, #0xc] */
/* @0x1bf3f0 str r3, [r0, #0x4] */
/* @0x1bf3f4 str r5, [r0] */
/* @0x1bf3f8 ldr r6, [sp, #0x18] */
/* @0x1bf3fc beq 0x1bf414 <_Z21F_LayerGetElementTypeR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bf400 ldr r0, [pc, #0x9c] */
/* @0x1bf404 mov r1, r5 */
/* @0x1bf408 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bf40c add r0, pc, r0 */
/* @0x1bf410 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bf414 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bf418 subs r7, r0, #0 */
/* @0x1bf41c beq 0x1bf45c <_Z21F_LayerGetElementTypeR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1bf420 mov r1, r5 */
/* @0x1bf424 mov r0, r6 */
/* @0x1bf428 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bf42c mov r2, r5 */
/* @0x1bf430 mov r1, r0 */
/* @0x1bf434 mov r0, r7 */
/* @0x1bf438 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bf43c cmp r0, #0 */
/* @0x1bf440 beq 0x1bf480 <_Z21F_LayerGetElementTypeR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x1bf444 ldr r2, [r0] */
/* @0x1bf448 vmov s15, r2 */
/* @0x1bf44c vcvt.f64.s32 d7, s15 */
/* @0x1bf450 vmov r2, r3, d7 */
/* @0x1bf454 stm r4, {r2, r3} */
/* @0x1bf458 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bf45c ldr r3, [pc, #0x44] */
/* @0x1bf460 ldr r1, [pc, #0x44] */
/* @0x1bf464 ldr r3, [pc, r3] */
/* @0x1bf468 add r1, pc, r1 */
/* @0x1bf46c ldr r0, [r3] */
/* @0x1bf470 ldr r3, [r0] */
/* @0x1bf474 ldr r3, [r3, #0xc] */
/* @0x1bf478 blx r3 */
/* @0x1bf47c pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bf480 ldr r3, [pc, #0x28] */
/* @0x1bf484 ldr r1, [pc, #0x28] */
/* @0x1bf488 ldr r3, [pc, r3] */
/* @0x1bf48c add r1, pc, r1 */
/* @0x1bf490 ldr r0, [r3] */
/* @0x1bf494 ldr r3, [r0] */
/* @0x1bf498 ldr r3, [r3, #0xc] */
/* @0x1bf49c blx r3 */
/* @0x1bf4a0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bf4a4 ldrsheq pc, [r8], -r4 */
/* @0x1bf4a8 .word 0x0022e2b0 */
/* @0x1bf4ac andseq pc, r8, r8, lsl #28 */
/* @0x1bf4b0 eoreq lr, r2, r12, lsl #5 */
/* @0x1bf4b4 andseq pc, r8, r8, lsr #27 */

/* ── FUNC 0x1bf4b8 · F_LayerTileChange(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1bf4b8 cmp r3, #2 */
/* @0x1bf4bc mov r3, #0 */
/* @0x1bf4c0 push {r4, r5, r6, lr} */
/* @0x1bf4c4 mov r4, r3 */
/* @0x1bf4c8 ldr r5, [sp, #0x10] */
/* @0x1bf4cc movt r3, #0xbff0 */
/* @0x1bf4d0 str r4, [r0, #0xc] */
/* @0x1bf4d4 str r3, [r0, #0x4] */
/* @0x1bf4d8 str r4, [r0] */
/* @0x1bf4dc beq 0x1bf4f4 <_Z17F_LayerTileChangeR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bf4e0 ldr r0, [pc, #0x58] */
/* @0x1bf4e4 mov r1, r4 */
/* @0x1bf4e8 pop {r4, r5, r6, lr} */
/* @0x1bf4ec add r0, pc, r0 */
/* @0x1bf4f0 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bf4f4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bf4f8 mov r1, r4 */
/* @0x1bf4fc mov r6, r0 */
/* @0x1bf500 mov r0, r5 */
/* @0x1bf504 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bf508 mov r2, r4 */
/* @0x1bf50c mov r1, r0 */
/* @0x1bf510 mov r0, r6 */
/* @0x1bf514 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bf518 subs r4, r0, #0 */
/* @0x1bf51c popeq {r4, r5, r6, pc} */
/* @0x1bf520 ldr r3, [r4] */
/* @0x1bf524 cmp r3, #7 */
/* @0x1bf528 popne {r4, r5, r6, pc} */
/* @0x1bf52c mov r0, r5 */
/* @0x1bf530 mov r1, #1 */
/* @0x1bf534 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bf538 str r0, [r4, #0x20] */
/* @0x1bf53c pop {r4, r5, r6, pc} */
/* @0x1bf540 ldrheq pc, [r8], -r0 */

/* ── FUNC 0x1bf544 · F_LayerTileXScale(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1bf544 cmp r3, #2 */
/* @0x1bf548 mov r3, #0 */
/* @0x1bf54c push {r4, r5, r6, lr} */
/* @0x1bf550 mov r4, r3 */
/* @0x1bf554 ldr r5, [sp, #0x10] */
/* @0x1bf558 movt r3, #0xbff0 */
/* @0x1bf55c str r4, [r0, #0xc] */
/* @0x1bf560 str r3, [r0, #0x4] */
/* @0x1bf564 str r4, [r0] */
/* @0x1bf568 beq 0x1bf580 <_Z17F_LayerTileXScaleR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bf56c ldr r0, [pc, #0x58] */
/* @0x1bf570 mov r1, r4 */
/* @0x1bf574 pop {r4, r5, r6, lr} */
/* @0x1bf578 add r0, pc, r0 */
/* @0x1bf57c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bf580 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bf584 mov r1, r4 */
/* @0x1bf588 mov r6, r0 */
/* @0x1bf58c mov r0, r5 */
/* @0x1bf590 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bf594 mov r2, r4 */
/* @0x1bf598 mov r1, r0 */
/* @0x1bf59c mov r0, r6 */
/* @0x1bf5a0 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bf5a4 subs r4, r0, #0 */
/* @0x1bf5a8 popeq {r4, r5, r6, pc} */
/* @0x1bf5ac ldr r3, [r4] */
/* @0x1bf5b0 cmp r3, #7 */
/* @0x1bf5b4 popne {r4, r5, r6, pc} */
/* @0x1bf5b8 mov r0, r5 */
/* @0x1bf5bc mov r1, #1 */
/* @0x1bf5c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bf5c4 str r0, [r4, #0x34] */
/* @0x1bf5c8 pop {r4, r5, r6, pc} */
/* @0x1bf5cc andseq pc, r8, r8, asr sp */

/* ── FUNC 0x1bf5d0 · F_LayerTileYScale(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1bf5d0 cmp r3, #2 */
/* @0x1bf5d4 mov r3, #0 */
/* @0x1bf5d8 push {r4, r5, r6, lr} */
/* @0x1bf5dc mov r4, r3 */
/* @0x1bf5e0 ldr r5, [sp, #0x10] */
/* @0x1bf5e4 movt r3, #0xbff0 */
/* @0x1bf5e8 str r4, [r0, #0xc] */
/* @0x1bf5ec str r3, [r0, #0x4] */
/* @0x1bf5f0 str r4, [r0] */
/* @0x1bf5f4 beq 0x1bf60c <_Z17F_LayerTileYScaleR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bf5f8 ldr r0, [pc, #0x58] */
/* @0x1bf5fc mov r1, r4 */
/* @0x1bf600 pop {r4, r5, r6, lr} */
/* @0x1bf604 add r0, pc, r0 */
/* @0x1bf608 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bf60c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bf610 mov r1, r4 */
/* @0x1bf614 mov r6, r0 */
/* @0x1bf618 mov r0, r5 */
/* @0x1bf61c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bf620 mov r2, r4 */
/* @0x1bf624 mov r1, r0 */
/* @0x1bf628 mov r0, r6 */
/* @0x1bf62c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bf630 subs r4, r0, #0 */
/* @0x1bf634 popeq {r4, r5, r6, pc} */
/* @0x1bf638 ldr r3, [r4] */
/* @0x1bf63c cmp r3, #7 */
/* @0x1bf640 popne {r4, r5, r6, pc} */
/* @0x1bf644 mov r0, r5 */
/* @0x1bf648 mov r1, #1 */
/* @0x1bf64c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bf650 str r0, [r4, #0x38] */
/* @0x1bf654 pop {r4, r5, r6, pc} */
/* @0x1bf658 andseq pc, r8, r0, lsl #26 */

/* ── FUNC 0x1bf65c · F_LayerTileBlend(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1bf65c cmp r3, #2 */
/* @0x1bf660 mov r3, #0 */
/* @0x1bf664 push {r4, r5, r6, lr} */
/* @0x1bf668 mov r4, r3 */
/* @0x1bf66c ldr r5, [sp, #0x10] */
/* @0x1bf670 movt r3, #0xbff0 */
/* @0x1bf674 str r4, [r0, #0xc] */
/* @0x1bf678 str r3, [r0, #0x4] */
/* @0x1bf67c str r4, [r0] */
/* @0x1bf680 beq 0x1bf698 <_Z16F_LayerTileBlendR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bf684 ldr r0, [pc, #0x60] */
/* @0x1bf688 mov r1, r4 */
/* @0x1bf68c pop {r4, r5, r6, lr} */
/* @0x1bf690 add r0, pc, r0 */
/* @0x1bf694 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bf698 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bf69c mov r1, r4 */
/* @0x1bf6a0 mov r6, r0 */
/* @0x1bf6a4 mov r0, r5 */
/* @0x1bf6a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bf6ac mov r2, r4 */
/* @0x1bf6b0 mov r1, r0 */
/* @0x1bf6b4 mov r0, r6 */
/* @0x1bf6b8 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bf6bc subs r4, r0, #0 */
/* @0x1bf6c0 popeq {r4, r5, r6, pc} */
/* @0x1bf6c4 ldr r3, [r4] */
/* @0x1bf6c8 cmp r3, #7 */
/* @0x1bf6cc popne {r4, r5, r6, pc} */
/* @0x1bf6d0 mov r0, r5 */
/* @0x1bf6d4 mov r1, #1 */
/* @0x1bf6d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bf6dc vmov s15, r0 */
/* @0x1bf6e0 vcvt.u32.f32 s15, s15 */
/* @0x1bf6e4 vstr s15, [r4, #64] */
/* @0x1bf6e8 pop {r4, r5, r6, pc} */
/* @0x1bf6ec andseq pc, r8, r8, lsr #25 */

/* ── FUNC 0x1bf6f0 · F_LayerTileAlpha(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1bf6f0 cmp r3, #2 */
/* @0x1bf6f4 mov r3, #0 */
/* @0x1bf6f8 push {r4, r5, r6, lr} */
/* @0x1bf6fc mov r4, r3 */
/* @0x1bf700 ldr r5, [sp, #0x10] */
/* @0x1bf704 movt r3, #0xbff0 */
/* @0x1bf708 str r4, [r0, #0xc] */
/* @0x1bf70c str r3, [r0, #0x4] */
/* @0x1bf710 str r4, [r0] */
/* @0x1bf714 beq 0x1bf72c <_Z16F_LayerTileAlphaR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bf718 ldr r0, [pc, #0x58] */
/* @0x1bf71c mov r1, r4 */
/* @0x1bf720 pop {r4, r5, r6, lr} */
/* @0x1bf724 add r0, pc, r0 */
/* @0x1bf728 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bf72c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bf730 mov r1, r4 */
/* @0x1bf734 mov r6, r0 */
/* @0x1bf738 mov r0, r5 */
/* @0x1bf73c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bf740 mov r2, r4 */
/* @0x1bf744 mov r1, r0 */
/* @0x1bf748 mov r0, r6 */
/* @0x1bf74c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bf750 subs r4, r0, #0 */
/* @0x1bf754 popeq {r4, r5, r6, pc} */
/* @0x1bf758 ldr r3, [r4] */
/* @0x1bf75c cmp r3, #7 */
/* @0x1bf760 popne {r4, r5, r6, pc} */
/* @0x1bf764 mov r0, r5 */
/* @0x1bf768 mov r1, #1 */
/* @0x1bf76c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bf770 str r0, [r4, #0x44] */
/* @0x1bf774 pop {r4, r5, r6, pc} */
/* @0x1bf778 andseq pc, r8, r8, asr #24 */

/* ── FUNC 0x1bf77c · F_LayerTileX(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1bf77c cmp r3, #2 */
/* @0x1bf780 mov r3, #0 */
/* @0x1bf784 push {r4, r5, r6, lr} */
/* @0x1bf788 mov r4, r3 */
/* @0x1bf78c ldr r5, [sp, #0x10] */
/* @0x1bf790 movt r3, #0xbff0 */
/* @0x1bf794 str r4, [r0, #0xc] */
/* @0x1bf798 str r3, [r0, #0x4] */
/* @0x1bf79c str r4, [r0] */
/* @0x1bf7a0 beq 0x1bf7b8 <_Z12F_LayerTileXR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bf7a4 ldr r0, [pc, #0x58] */
/* @0x1bf7a8 mov r1, r4 */
/* @0x1bf7ac pop {r4, r5, r6, lr} */
/* @0x1bf7b0 add r0, pc, r0 */
/* @0x1bf7b4 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bf7b8 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bf7bc mov r1, r4 */
/* @0x1bf7c0 mov r6, r0 */
/* @0x1bf7c4 mov r0, r5 */
/* @0x1bf7c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bf7cc mov r2, r4 */
/* @0x1bf7d0 mov r1, r0 */
/* @0x1bf7d4 mov r0, r6 */
/* @0x1bf7d8 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bf7dc subs r4, r0, #0 */
/* @0x1bf7e0 popeq {r4, r5, r6, pc} */
/* @0x1bf7e4 ldr r3, [r4] */
/* @0x1bf7e8 cmp r3, #7 */
/* @0x1bf7ec popne {r4, r5, r6, pc} */
/* @0x1bf7f0 mov r0, r5 */
/* @0x1bf7f4 mov r1, #1 */
/* @0x1bf7f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bf7fc str r0, [r4, #0x24] */
/* @0x1bf800 pop {r4, r5, r6, pc} */
/* @0x1bf804 ldrsheq pc, [r8], -r0 */

/* ── FUNC 0x1bf808 · F_LayerTileY(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1bf808 cmp r3, #2 */
/* @0x1bf80c mov r3, #0 */
/* @0x1bf810 push {r4, r5, r6, lr} */
/* @0x1bf814 mov r4, r3 */
/* @0x1bf818 ldr r5, [sp, #0x10] */
/* @0x1bf81c movt r3, #0xbff0 */
/* @0x1bf820 str r4, [r0, #0xc] */
/* @0x1bf824 str r3, [r0, #0x4] */
/* @0x1bf828 str r4, [r0] */
/* @0x1bf82c beq 0x1bf844 <_Z12F_LayerTileYR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bf830 ldr r0, [pc, #0x58] */
/* @0x1bf834 mov r1, r4 */
/* @0x1bf838 pop {r4, r5, r6, lr} */
/* @0x1bf83c add r0, pc, r0 */
/* @0x1bf840 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bf844 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bf848 mov r1, r4 */
/* @0x1bf84c mov r6, r0 */
/* @0x1bf850 mov r0, r5 */
/* @0x1bf854 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bf858 mov r2, r4 */
/* @0x1bf85c mov r1, r0 */
/* @0x1bf860 mov r0, r6 */
/* @0x1bf864 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bf868 subs r4, r0, #0 */
/* @0x1bf86c popeq {r4, r5, r6, pc} */
/* @0x1bf870 ldr r3, [r4] */
/* @0x1bf874 cmp r3, #7 */
/* @0x1bf878 popne {r4, r5, r6, pc} */
/* @0x1bf87c mov r0, r5 */
/* @0x1bf880 mov r1, #1 */
/* @0x1bf884 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bf888 str r0, [r4, #0x28] */
/* @0x1bf88c pop {r4, r5, r6, pc} */
/* @0x1bf890 mulseq r8, r4, r11 */

/* ── FUNC 0x1bf894 · F_LayerTileVisible(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x1bf894 cmp r3, #2 */
/* @0x1bf898 mov r3, #0 */
/* @0x1bf89c push {r4, r5, r6, lr} */
/* @0x1bf8a0 mov r4, r3 */
/* @0x1bf8a4 ldr r5, [sp, #0x10] */
/* @0x1bf8a8 movt r3, #0xbff0 */
/* @0x1bf8ac str r4, [r0, #0xc] */
/* @0x1bf8b0 str r3, [r0, #0x4] */
/* @0x1bf8b4 str r4, [r0] */
/* @0x1bf8b8 beq 0x1bf8d0 <_Z18F_LayerTileVisibleR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bf8bc ldr r0, [pc, #0x6c] */
/* @0x1bf8c0 mov r1, r4 */
/* @0x1bf8c4 pop {r4, r5, r6, lr} */
/* @0x1bf8c8 add r0, pc, r0 */
/* @0x1bf8cc b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bf8d0 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bf8d4 mov r1, r4 */
/* @0x1bf8d8 mov r6, r0 */
/* @0x1bf8dc mov r0, r5 */
/* @0x1bf8e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bf8e4 mov r2, r4 */
/* @0x1bf8e8 mov r1, r0 */
/* @0x1bf8ec mov r0, r6 */
/* @0x1bf8f0 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bf8f4 subs r4, r0, #0 */
/* @0x1bf8f8 popeq {r4, r5, r6, pc} */
/* @0x1bf8fc ldr r3, [r4] */
/* @0x1bf900 cmp r3, #7 */
/* @0x1bf904 popne {r4, r5, r6, pc} */
/* @0x1bf908 mov r0, r5 */
/* @0x1bf90c mov r1, #1 */
/* @0x1bf910 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bf914 vmov s15, r0 */
/* @0x1bf918 vcmp.f32 s15, #0 */
/* @0x1bf91c vmrs APSR_nzcv, fpscr */
/* @0x1bf920 moveq r3, #0 */
/* @0x1bf924 movne r3, #1 */
/* @0x1bf928 strb r3, [r4, #0x1c] */
/* @0x1bf92c pop {r4, r5, r6, pc} */
/* @0x1bf930 andseq pc, r8, r8, lsr r11 */

/* ── FUNC 0x1bf934 · F_LayerTileGetSprite(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1bf934 cmp r3, #1 */
/* @0x1bf938 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bf93c mov r3, #0 */
/* @0x1bf940 mov r4, r3 */
/* @0x1bf944 mov r5, r0 */
/* @0x1bf948 movt r3, #0xbff0 */
/* @0x1bf94c str r4, [r0, #0xc] */
/* @0x1bf950 str r3, [r0, #0x4] */
/* @0x1bf954 str r4, [r0] */
/* @0x1bf958 ldr r6, [sp, #0x18] */
/* @0x1bf95c beq 0x1bf974 <_Z20F_LayerTileGetSpriteR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bf960 ldr r0, [pc, #0x5c] */
/* @0x1bf964 mov r1, r4 */
/* @0x1bf968 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bf96c add r0, pc, r0 */
/* @0x1bf970 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bf974 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bf978 mov r1, r4 */
/* @0x1bf97c mov r7, r0 */
/* @0x1bf980 mov r0, r6 */
/* @0x1bf984 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bf988 mov r2, r4 */
/* @0x1bf98c mov r1, r0 */
/* @0x1bf990 mov r0, r7 */
/* @0x1bf994 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bf998 cmp r0, #0 */
/* @0x1bf99c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bf9a0 ldr r3, [r0] */
/* @0x1bf9a4 cmp r3, #7 */
/* @0x1bf9a8 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bf9ac ldr r2, [r0, #0x20] */
/* @0x1bf9b0 vmov s15, r2 */
/* @0x1bf9b4 vcvt.f64.s32 d7, s15 */
/* @0x1bf9b8 vmov r2, r3, d7 */
/* @0x1bf9bc stm r5, {r2, r3} */
/* @0x1bf9c0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bf9c4 andseq pc, r8, r8, asr #21 */

/* ── FUNC 0x1bf9c8 · F_LayerTileGetXScale(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x1bf9c8 cmp r3, #1 */
/* @0x1bf9cc push {r3, r4, r5, r6, r7, lr} */
/* @0x1bf9d0 mov r3, #0 */
/* @0x1bf9d4 mov r5, r3 */
/* @0x1bf9d8 mov r4, r0 */
/* @0x1bf9dc movt r3, #0xbff0 */
/* @0x1bf9e0 str r5, [r0, #0xc] */
/* @0x1bf9e4 str r3, [r0, #0x4] */
/* @0x1bf9e8 str r5, [r0] */
/* @0x1bf9ec ldr r6, [sp, #0x18] */
/* @0x1bf9f0 beq 0x1bfa08 <_Z20F_LayerTileGetXScaleR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bf9f4 ldr r0, [pc, #0x68] */
/* @0x1bf9f8 mov r1, r5 */
/* @0x1bf9fc pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bfa00 add r0, pc, r0 */
/* @0x1bfa04 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bfa08 str r5, [r0] */
/* @0x1bfa0c mov r3, #0 */
/* @0x1bfa10 movt r3, #0x3ff0 */
/* @0x1bfa14 str r3, [r0, #0x4] */
/* @0x1bfa18 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bfa1c mov r1, r5 */
/* @0x1bfa20 mov r7, r0 */
/* @0x1bfa24 mov r0, r6 */
/* @0x1bfa28 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bfa2c mov r2, r5 */
/* @0x1bfa30 mov r1, r0 */
/* @0x1bfa34 mov r0, r7 */
/* @0x1bfa38 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bfa3c cmp r0, #0 */
/* @0x1bfa40 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bfa44 ldr r3, [r0] */
/* @0x1bfa48 cmp r3, #7 */
/* @0x1bfa4c popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bfa50 vldr s15, [r0, #52] */
/* @0x1bfa54 vcvt.f64.f32 d6, s15 */
/* @0x1bfa58 vmov r2, r3, d6 */
/* @0x1bfa5c stm r4, {r2, r3} */
/* @0x1bfa60 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bfa64 andseq pc, r8, r12, ror #20 */

/* ── FUNC 0x1bfa68 · F_LayerTileGetYScale(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x1bfa68 cmp r3, #1 */
/* @0x1bfa6c push {r3, r4, r5, r6, r7, lr} */
/* @0x1bfa70 mov r3, #0 */
/* @0x1bfa74 mov r5, r3 */
/* @0x1bfa78 mov r4, r0 */
/* @0x1bfa7c movt r3, #0xbff0 */
/* @0x1bfa80 str r5, [r0, #0xc] */
/* @0x1bfa84 str r3, [r0, #0x4] */
/* @0x1bfa88 str r5, [r0] */
/* @0x1bfa8c ldr r6, [sp, #0x18] */
/* @0x1bfa90 beq 0x1bfaa8 <_Z20F_LayerTileGetYScaleR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bfa94 ldr r0, [pc, #0x68] */
/* @0x1bfa98 mov r1, r5 */
/* @0x1bfa9c pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bfaa0 add r0, pc, r0 */
/* @0x1bfaa4 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bfaa8 str r5, [r0] */
/* @0x1bfaac mov r3, #0 */
/* @0x1bfab0 movt r3, #0x3ff0 */
/* @0x1bfab4 str r3, [r0, #0x4] */
/* @0x1bfab8 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bfabc mov r1, r5 */
/* @0x1bfac0 mov r7, r0 */
/* @0x1bfac4 mov r0, r6 */
/* @0x1bfac8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bfacc mov r2, r5 */
/* @0x1bfad0 mov r1, r0 */
/* @0x1bfad4 mov r0, r7 */
/* @0x1bfad8 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bfadc cmp r0, #0 */
/* @0x1bfae0 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bfae4 ldr r3, [r0] */
/* @0x1bfae8 cmp r3, #7 */
/* @0x1bfaec popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bfaf0 vldr s15, [r0, #56] */
/* @0x1bfaf4 vcvt.f64.f32 d6, s15 */
/* @0x1bfaf8 vmov r2, r3, d6 */
/* @0x1bfafc stm r4, {r2, r3} */
/* @0x1bfb00 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bfb04 andseq pc, r8, r4, lsl #20 */

/* ── FUNC 0x1bfb08 · F_LayerTileGetBlend(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x1bfb08 cmp r3, #1 */
/* @0x1bfb0c push {r3, r4, r5, r6, r7, lr} */
/* @0x1bfb10 mov r3, #0 */
/* @0x1bfb14 mov r4, r3 */
/* @0x1bfb18 mov r5, r0 */
/* @0x1bfb1c movt r3, #0xbff0 */
/* @0x1bfb20 str r4, [r0, #0xc] */
/* @0x1bfb24 str r3, [r0, #0x4] */
/* @0x1bfb28 str r4, [r0] */
/* @0x1bfb2c ldr r6, [sp, #0x18] */
/* @0x1bfb30 beq 0x1bfb48 <_Z19F_LayerTileGetBlendR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bfb34 ldr r0, [pc, #0x64] */
/* @0x1bfb38 mov r1, r4 */
/* @0x1bfb3c pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bfb40 add r0, pc, r0 */
/* @0x1bfb44 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bfb48 str r4, [r0] */
/* @0x1bfb4c str r4, [r0, #0x4] */
/* @0x1bfb50 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bfb54 mov r1, r4 */
/* @0x1bfb58 mov r7, r0 */
/* @0x1bfb5c mov r0, r6 */
/* @0x1bfb60 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bfb64 mov r2, r4 */
/* @0x1bfb68 mov r1, r0 */
/* @0x1bfb6c mov r0, r7 */
/* @0x1bfb70 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bfb74 cmp r0, #0 */
/* @0x1bfb78 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bfb7c ldr r3, [r0] */
/* @0x1bfb80 cmp r3, #7 */
/* @0x1bfb84 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bfb88 ldr r2, [r0, #0x40] */
/* @0x1bfb8c vmov s15, r2 */
/* @0x1bfb90 vcvt.f64.u32 d7, s15 */
/* @0x1bfb94 vmov r2, r3, d7 */
/* @0x1bfb98 stm r5, {r2, r3} */
/* @0x1bfb9c pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bfba0 mulseq r8, r12, r9 */

/* ── FUNC 0x1bfba4 · F_LayerTileGetAlpha(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x1bfba4 cmp r3, #1 */
/* @0x1bfba8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bfbac mov r3, #0 */
/* @0x1bfbb0 mov r4, r3 */
/* @0x1bfbb4 mov r5, r0 */
/* @0x1bfbb8 movt r3, #0xbff0 */
/* @0x1bfbbc str r4, [r0, #0xc] */
/* @0x1bfbc0 str r3, [r0, #0x4] */
/* @0x1bfbc4 str r4, [r0] */
/* @0x1bfbc8 ldr r6, [sp, #0x18] */
/* @0x1bfbcc beq 0x1bfbe4 <_Z19F_LayerTileGetAlphaR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bfbd0 ldr r0, [pc, #0x60] */
/* @0x1bfbd4 mov r1, r4 */
/* @0x1bfbd8 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bfbdc add r0, pc, r0 */
/* @0x1bfbe0 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bfbe4 str r4, [r0] */
/* @0x1bfbe8 str r4, [r0, #0x4] */
/* @0x1bfbec bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bfbf0 mov r1, r4 */
/* @0x1bfbf4 mov r7, r0 */
/* @0x1bfbf8 mov r0, r6 */
/* @0x1bfbfc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bfc00 mov r2, r4 */
/* @0x1bfc04 mov r1, r0 */
/* @0x1bfc08 mov r0, r7 */
/* @0x1bfc0c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bfc10 cmp r0, #0 */
/* @0x1bfc14 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bfc18 ldr r3, [r0] */
/* @0x1bfc1c cmp r3, #7 */
/* @0x1bfc20 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bfc24 vldr s15, [r0, #68] */
/* @0x1bfc28 vcvt.f64.f32 d6, s15 */
/* @0x1bfc2c vmov r2, r3, d6 */
/* @0x1bfc30 stm r5, {r2, r3} */
/* @0x1bfc34 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bfc38 andseq pc, r8, r8, lsr r9 */

/* ── FUNC 0x1bfc3c · F_LayerTileGetX(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x1bfc3c cmp r3, #1 */
/* @0x1bfc40 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bfc44 mov r3, #0 */
/* @0x1bfc48 mov r4, r3 */
/* @0x1bfc4c mov r5, r0 */
/* @0x1bfc50 movt r3, #0xbff0 */
/* @0x1bfc54 str r4, [r0, #0xc] */
/* @0x1bfc58 str r3, [r0, #0x4] */
/* @0x1bfc5c str r4, [r0] */
/* @0x1bfc60 ldr r6, [sp, #0x18] */
/* @0x1bfc64 beq 0x1bfc7c <_Z15F_LayerTileGetXR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bfc68 ldr r0, [pc, #0x60] */
/* @0x1bfc6c mov r1, r4 */
/* @0x1bfc70 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bfc74 add r0, pc, r0 */
/* @0x1bfc78 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bfc7c str r4, [r0] */
/* @0x1bfc80 str r4, [r0, #0x4] */
/* @0x1bfc84 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bfc88 mov r1, r4 */
/* @0x1bfc8c mov r7, r0 */
/* @0x1bfc90 mov r0, r6 */
/* @0x1bfc94 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bfc98 mov r2, r4 */
/* @0x1bfc9c mov r1, r0 */
/* @0x1bfca0 mov r0, r7 */
/* @0x1bfca4 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bfca8 cmp r0, #0 */
/* @0x1bfcac popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bfcb0 ldr r3, [r0] */
/* @0x1bfcb4 cmp r3, #7 */
/* @0x1bfcb8 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bfcbc vldr s15, [r0, #36] */
/* @0x1bfcc0 vcvt.f64.f32 d6, s15 */
/* @0x1bfcc4 vmov r2, r3, d6 */
/* @0x1bfcc8 stm r5, {r2, r3} */
/* @0x1bfccc pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bfcd0 ldrsbeq pc, [r8], -r8 */

/* ── FUNC 0x1bfcd4 · F_LayerTileGetY(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x1bfcd4 cmp r3, #1 */
/* @0x1bfcd8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bfcdc mov r3, #0 */
/* @0x1bfce0 mov r4, r3 */
/* @0x1bfce4 mov r5, r0 */
/* @0x1bfce8 movt r3, #0xbff0 */
/* @0x1bfcec str r4, [r0, #0xc] */
/* @0x1bfcf0 str r3, [r0, #0x4] */
/* @0x1bfcf4 str r4, [r0] */
/* @0x1bfcf8 ldr r6, [sp, #0x18] */
/* @0x1bfcfc beq 0x1bfd14 <_Z15F_LayerTileGetYR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bfd00 ldr r0, [pc, #0x60] */
/* @0x1bfd04 mov r1, r4 */
/* @0x1bfd08 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bfd0c add r0, pc, r0 */
/* @0x1bfd10 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bfd14 str r4, [r0] */
/* @0x1bfd18 str r4, [r0, #0x4] */
/* @0x1bfd1c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bfd20 mov r1, r4 */
/* @0x1bfd24 mov r7, r0 */
/* @0x1bfd28 mov r0, r6 */
/* @0x1bfd2c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bfd30 mov r2, r4 */
/* @0x1bfd34 mov r1, r0 */
/* @0x1bfd38 mov r0, r7 */
/* @0x1bfd3c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bfd40 cmp r0, #0 */
/* @0x1bfd44 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bfd48 ldr r3, [r0] */
/* @0x1bfd4c cmp r3, #7 */
/* @0x1bfd50 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bfd54 vldr s15, [r0, #40] */
/* @0x1bfd58 vcvt.f64.f32 d6, s15 */
/* @0x1bfd5c vmov r2, r3, d6 */
/* @0x1bfd60 stm r5, {r2, r3} */
/* @0x1bfd64 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bfd68 andseq pc, r8, r4, ror r8 */

/* ── FUNC 0x1bfd6c · F_LayerTileGetVisible(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x1bfd6c cmp r3, #1 */
/* @0x1bfd70 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bfd74 mov r3, #0 */
/* @0x1bfd78 mov r4, r3 */
/* @0x1bfd7c mov r5, r0 */
/* @0x1bfd80 movt r3, #0xbff0 */
/* @0x1bfd84 str r4, [r0, #0xc] */
/* @0x1bfd88 str r3, [r0, #0x4] */
/* @0x1bfd8c str r4, [r0] */
/* @0x1bfd90 ldr r6, [sp, #0x18] */
/* @0x1bfd94 beq 0x1bfdac <_Z21F_LayerTileGetVisibleR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bfd98 ldr r0, [pc, #0x64] */
/* @0x1bfd9c mov r1, r4 */
/* @0x1bfda0 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bfda4 add r0, pc, r0 */
/* @0x1bfda8 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bfdac str r4, [r0] */
/* @0x1bfdb0 str r4, [r0, #0x4] */
/* @0x1bfdb4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bfdb8 mov r1, r4 */
/* @0x1bfdbc mov r7, r0 */
/* @0x1bfdc0 mov r0, r6 */
/* @0x1bfdc4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bfdc8 mov r2, r4 */
/* @0x1bfdcc mov r1, r0 */
/* @0x1bfdd0 mov r0, r7 */
/* @0x1bfdd4 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bfdd8 cmp r0, #0 */
/* @0x1bfddc popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bfde0 ldr r3, [r0] */
/* @0x1bfde4 cmp r3, #7 */
/* @0x1bfde8 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bfdec ldrb r2, [r0, #0x1c] */
/* @0x1bfdf0 vmov s15, r2 */
/* @0x1bfdf4 vcvt.f64.u32 d7, s15 */
/* @0x1bfdf8 vmov r2, r3, d7 */
/* @0x1bfdfc stm r5, {r2, r3} */
/* @0x1bfe00 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bfe04 andseq pc, r8, r0, lsl r8 */
