/* libyoyo.so 覆盖卡组 0151
 * 函数 0x1bfe08..0x1c33e4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1bfe08 · F_LayerTileRegion(RValue&, CInstance*, CInstance*, int, RValue*) · size=188 · insn=47 */
/* @0x1bfe08 cmp r3, #5 */
/* @0x1bfe0c mov r3, #0 */
/* @0x1bfe10 push {r4, r5, r6, lr} */
/* @0x1bfe14 mov r4, r3 */
/* @0x1bfe18 ldr r5, [sp, #0x10] */
/* @0x1bfe1c movt r3, #0xbff0 */
/* @0x1bfe20 str r4, [r0, #0xc] */
/* @0x1bfe24 str r3, [r0, #0x4] */
/* @0x1bfe28 str r4, [r0] */
/* @0x1bfe2c beq 0x1bfe44 <_Z17F_LayerTileRegionR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bfe30 ldr r0, [pc, #0x88] */
/* @0x1bfe34 mov r1, r4 */
/* @0x1bfe38 pop {r4, r5, r6, lr} */
/* @0x1bfe3c add r0, pc, r0 */
/* @0x1bfe40 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bfe44 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bfe48 mov r1, r4 */
/* @0x1bfe4c mov r6, r0 */
/* @0x1bfe50 mov r0, r5 */
/* @0x1bfe54 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bfe58 mov r2, r4 */
/* @0x1bfe5c mov r1, r0 */
/* @0x1bfe60 mov r0, r6 */
/* @0x1bfe64 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bfe68 subs r4, r0, #0 */
/* @0x1bfe6c popeq {r4, r5, r6, pc} */
/* @0x1bfe70 ldr r3, [r4] */
/* @0x1bfe74 cmp r3, #7 */
/* @0x1bfe78 popne {r4, r5, r6, pc} */
/* @0x1bfe7c mov r1, #1 */
/* @0x1bfe80 mov r0, r5 */
/* @0x1bfe84 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bfe88 mov r1, #2 */
/* @0x1bfe8c str r0, [r4, #0x48] */
/* @0x1bfe90 mov r0, r5 */
/* @0x1bfe94 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bfe98 mov r1, #3 */
/* @0x1bfe9c str r0, [r4, #0x4c] */
/* @0x1bfea0 mov r0, r5 */
/* @0x1bfea4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bfea8 mov r1, #4 */
/* @0x1bfeac str r0, [r4, #0x2c] */
/* @0x1bfeb0 mov r0, r5 */
/* @0x1bfeb4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bfeb8 str r0, [r4, #0x30] */
/* @0x1bfebc pop {r4, r5, r6, pc} */
/* @0x1bfec0 ldrheq pc, [r8], -r0 */

/* ── FUNC 0x1bfec4 · F_LayerTileGetRegion(RValue&, CInstance*, CInstance*, int, RValue*) · size=208 · insn=52 */
/* @0x1bfec4 push {r4, r5, r6, r7, lr} */
/* @0x1bfec8 cmp r3, #1 */
/* @0x1bfecc sub sp, sp, #28 */
/* @0x1bfed0 mov r3, #0 */
/* @0x1bfed4 mov r4, r3 */
/* @0x1bfed8 mov r5, r0 */
/* @0x1bfedc movt r3, #0xbff0 */
/* @0x1bfee0 str r4, [r0, #0xc] */
/* @0x1bfee4 str r3, [r0, #0x4] */
/* @0x1bfee8 str r4, [r0] */
/* @0x1bfeec ldr r6, [sp, #0x30] */
/* @0x1bfef0 beq 0x1bff0c <_Z20F_LayerTileGetRegionR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1bfef4 ldr r0, [pc, #0x94] */
/* @0x1bfef8 mov r1, r4 */
/* @0x1bfefc add r0, pc, r0 */
/* @0x1bff00 add sp, sp, #28 */
/* @0x1bff04 pop {r4, r5, r6, r7, lr} */
/* @0x1bff08 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bff0c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bff10 mov r1, r4 */
/* @0x1bff14 mov r7, r0 */
/* @0x1bff18 mov r0, r6 */
/* @0x1bff1c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bff20 mov r2, r4 */
/* @0x1bff24 mov r1, r0 */
/* @0x1bff28 mov r0, r7 */
/* @0x1bff2c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bff30 subs r12, r0, #0 */
/* @0x1bff34 beq 0x1bff44 <_Z20F_LayerTileGetRegionR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x1bff38 ldr r3, [r12] */
/* @0x1bff3c cmp r3, #7 */
/* @0x1bff40 beq 0x1bff4c <_Z20F_LayerTileGetRegionR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1bff44 add sp, sp, #28 */
/* @0x1bff48 pop {r4, r5, r6, r7, pc} */
/* @0x1bff4c vldr s13, [r12, #76] */
/* @0x1bff50 vcvt.f64.s32 d7, s13 */
/* @0x1bff54 ldr r2, [r12, #0x48] */
/* @0x1bff58 mov r0, r5 */
/* @0x1bff5c mov r1, #4 */
/* @0x1bff60 vstr d7, [sp] */
/* @0x1bff64 vmov s15, r2 */
/* @0x1bff68 vldr s13, [r12, #44] */
/* @0x1bff6c vcvt.f64.s32 d7, s15 */
/* @0x1bff70 vmov r2, r3, d7 */
/* @0x1bff74 vcvt.f64.s32 d7, s13 */
/* @0x1bff78 vstr d7, [sp, #8] */
/* @0x1bff7c vldr s14, [r12, #48] */
/* @0x1bff80 vcvt.f64.s32 d7, s14 */
/* @0x1bff84 vstr d7, [sp, #16] */
/* @0x1bff88 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x1bff8c b 0x1bff44 <_Z20F_LayerTileGetRegionR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x1bff90 andseq pc, r8, r0, lsr #14 */

/* ── FUNC 0x1bff94 · F_LayerInstanceGetInstance(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1bff94 cmp r3, #1 */
/* @0x1bff98 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bff9c mov r3, #0 */
/* @0x1bffa0 mov r4, r3 */
/* @0x1bffa4 mov r5, r0 */
/* @0x1bffa8 movt r3, #0xc010 */
/* @0x1bffac str r4, [r0, #0xc] */
/* @0x1bffb0 str r3, [r0, #0x4] */
/* @0x1bffb4 str r4, [r0] */
/* @0x1bffb8 ldr r6, [sp, #0x18] */
/* @0x1bffbc beq 0x1bffd4 <_Z26F_LayerInstanceGetInstanceR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bffc0 ldr r0, [pc, #0x5c] */
/* @0x1bffc4 mov r1, r4 */
/* @0x1bffc8 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bffcc add r0, pc, r0 */
/* @0x1bffd0 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bffd4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bffd8 mov r1, r4 */
/* @0x1bffdc mov r7, r0 */
/* @0x1bffe0 mov r0, r6 */
/* @0x1bffe4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bffe8 mov r2, r4 */
/* @0x1bffec mov r1, r0 */
/* @0x1bfff0 mov r0, r7 */
/* @0x1bfff4 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bfff8 cmp r0, #0 */
/* @0x1bfffc popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1c0000 ldr r3, [r0] */
/* @0x1c0004 cmp r3, #2 */
/* @0x1c0008 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1c000c ldr r2, [r0, #0x1c] */
/* @0x1c0010 vmov s15, r2 */
/* @0x1c0014 vcvt.f64.s32 d7, s15 */
/* @0x1c0018 vmov r2, r3, d7 */
/* @0x1c001c stm r5, {r2, r3} */
/* @0x1c0020 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c0024 andseq pc, r8, r4, lsl #13 */

/* ── FUNC 0x1c0028 · F_LayerElementMove(RValue&, CInstance*, CInstance*, int, RValue*) · size=276 · insn=69 */
/* @0x1c0028 push {r4, r5, r6, r7, lr} */
/* @0x1c002c cmp r3, #2 */
/* @0x1c0030 ldr r5, [pc, #0xec] */
/* @0x1c0034 mov r3, #0 */
/* @0x1c0038 mov r4, r3 */
/* @0x1c003c sub sp, sp, #12 */
/* @0x1c0040 movt r3, #0xbff0 */
/* @0x1c0044 str r4, [r0, #0xc] */
/* @0x1c0048 str r3, [r0, #0x4] */
/* @0x1c004c add r5, pc, r5 */
/* @0x1c0050 str r4, [r0] */
/* @0x1c0054 beq 0x1c0070 <_Z18F_LayerElementMoveR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1c0058 ldr r0, [pc, #0xc8] */
/* @0x1c005c mov r1, r4 */
/* @0x1c0060 add r0, pc, r0 */
/* @0x1c0064 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c0068 add sp, sp, #12 */
/* @0x1c006c pop {r4, r5, r6, r7, pc} */
/* @0x1c0070 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1c0074 subs r7, r0, #0 */
/* @0x1c0078 beq 0x1c0104 <_Z18F_LayerElementMoveR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x1c007c add r6, sp, #8 */
/* @0x1c0080 mov r1, r4 */
/* @0x1c0084 ldr r0, [sp, #0x20] */
/* @0x1c0088 str r4, [r6, #-0x4]! */
/* @0x1c008c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c0090 mov r2, r6 */
/* @0x1c0094 mov r1, r0 */
/* @0x1c0098 mov r0, r7 */
/* @0x1c009c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1c00a0 subs r4, r0, #0 */
/* @0x1c00a4 beq 0x1c0114 <_Z18F_LayerElementMoveR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x1c00a8 mov r1, #1 */
/* @0x1c00ac ldr r0, [sp, #0x20] */
/* @0x1c00b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c00b4 mov r1, r0 */
/* @0x1c00b8 mov r0, r7 */
/* @0x1c00bc bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c00c0 subs r2, r0, #0 */
/* @0x1c00c4 beq 0x1c00dc <_Z18F_LayerElementMoveR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x1c00c8 mov r0, r7 */
/* @0x1c00cc mov r1, r4 */
/* @0x1c00d0 bl 0x1bc1b4 <_ZN13CLayerManager11MoveElementEP5CRoomP17CLayerElementBaseP6CLayer> */
/* @0x1c00d4 add sp, sp, #12 */
/* @0x1c00d8 pop {r4, r5, r6, r7, pc} */
/* @0x1c00dc ldr r1, [pc, #0x48] */
/* @0x1c00e0 ldr r3, [pc, #0x48] */
/* @0x1c00e4 add r1, pc, r1 */
/* @0x1c00e8 ldr r3, [r5, r3] */
/* @0x1c00ec ldr r0, [r3] */
/* @0x1c00f0 ldr r3, [r0] */
/* @0x1c00f4 ldr r3, [r3, #0xc] */
/* @0x1c00f8 blx r3 */
/* @0x1c00fc add sp, sp, #12 */
/* @0x1c0100 pop {r4, r5, r6, r7, pc} */
/* @0x1c0104 ldr r1, [pc, #0x28] */
/* @0x1c0108 ldr r3, [pc, #0x20] */
/* @0x1c010c add r1, pc, r1 */
/* @0x1c0110 b 0x1c00e8 <_Z18F_LayerElementMoveR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x1c0114 ldr r1, [pc, #0x1c] */
/* @0x1c0118 ldr r3, [pc, #0x10] */
/* @0x1c011c add r1, pc, r1 */
/* @0x1c0120 b 0x1c00e8 <_Z18F_LayerElementMoveR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x1c0124 eoreq r1, r3, r4, lsl #24 */
/* @0x1c0128 andseq pc, r8, r12, lsr #12 */
/* @0x1c012c ldrsbeq pc, [r8], -r4 */
/* @0x1c0130 .word 0xffffbac4 */
/* @0x1c0134 andseq pc, r8, r4, lsl r6 */
/* @0x1c0138 andseq pc, r8, r12, asr #11 */

/* ── FUNC 0x1c013c · CLayerManager::RemoveElement(CRoom*, int, bool, bool) · size=120 · insn=30 */
/* @0x1c013c push {r4, r5, r6, lr} */
/* @0x1c0140 subs r4, r0, #0 */
/* @0x1c0144 sub sp, sp, #8 */
/* @0x1c0148 mov r5, r2 */
/* @0x1c014c mov r6, r3 */
/* @0x1c0150 beq 0x1c01ac <_ZN13CLayerManager13RemoveElementEP5CRoomibb+0x70> */
/* @0x1c0154 add r2, sp, #8 */
/* @0x1c0158 mov r3, #0 */
/* @0x1c015c str r3, [r2, #-0x4]! */
/* @0x1c0160 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1c0164 subs r2, r0, #0 */
/* @0x1c0168 beq 0x1c01ac <_ZN13CLayerManager13RemoveElementEP5CRoomibb+0x70> */
/* @0x1c016c mov r3, r6 */
/* @0x1c0170 mov r0, r4 */
/* @0x1c0174 ldr r1, [sp, #0x4] */
/* @0x1c0178 bl 0x1b8fdc <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c017c cmp r5, #0 */
/* @0x1c0180 beq 0x1c01ac <_ZN13CLayerManager13RemoveElementEP5CRoomibb+0x70> */
/* @0x1c0184 ldr r3, [sp, #0x4] */
/* @0x1c0188 ldrb r2, [r3, #0x19] */
/* @0x1c018c cmp r2, #0 */
/* @0x1c0190 beq 0x1c01ac <_ZN13CLayerManager13RemoveElementEP5CRoomibb+0x70> */
/* @0x1c0194 ldr r2, [r3, #0x60] */
/* @0x1c0198 cmp r2, #0 */
/* @0x1c019c bne 0x1c01ac <_ZN13CLayerManager13RemoveElementEP5CRoomibb+0x70> */
/* @0x1c01a0 mov r0, r4 */
/* @0x1c01a4 ldr r1, [r3] */
/* @0x1c01a8 bl 0x1b95d8 <_ZN13CLayerManager11RemoveLayerEP5CRoomib> */
/* @0x1c01ac add sp, sp, #8 */
/* @0x1c01b0 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1c01b4 · F_LayerDestroyInstances(RValue&, CInstance*, CInstance*, int, RValue*) · size=280 · insn=70 */
/* @0x1c01b4 cmp r3, #1 */
/* @0x1c01b8 mov r3, #0 */
/* @0x1c01bc push {r4, r5, r6, lr} */
/* @0x1c01c0 mov r4, r3 */
/* @0x1c01c4 ldr r5, [sp, #0x10] */
/* @0x1c01c8 movt r3, #0xbff0 */
/* @0x1c01cc str r4, [r0, #0xc] */
/* @0x1c01d0 str r3, [r0, #0x4] */
/* @0x1c01d4 str r4, [r0] */
/* @0x1c01d8 beq 0x1c01f0 <_Z23F_LayerDestroyInstancesR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1c01dc ldr r0, [pc, #0xdc] */
/* @0x1c01e0 mov r1, r4 */
/* @0x1c01e4 pop {r4, r5, r6, lr} */
/* @0x1c01e8 add r0, pc, r0 */
/* @0x1c01ec b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c01f0 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1c01f4 subs r6, r0, #0 */
/* @0x1c01f8 popeq {r4, r5, r6, pc} */
/* @0x1c01fc ldr r3, [r5, #0xc] */
/* @0x1c0200 mov r0, r5 */
/* @0x1c0204 mov r1, r4 */
/* @0x1c0208 bic r3, r3, #-16777216 */
/* @0x1c020c cmp r3, #1 */
/* @0x1c0210 beq 0x1c0284 <_Z23F_LayerDestroyInstancesR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x1c0214 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c0218 mov r1, r0 */
/* @0x1c021c mov r0, r6 */
/* @0x1c0220 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c0224 mov r5, r0 */
/* @0x1c0228 cmp r5, #0 */
/* @0x1c022c beq 0x1c029c <_Z23F_LayerDestroyInstancesR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x1c0230 ldr r3, [r5, #0x58] */
/* @0x1c0234 cmp r3, #0 */
/* @0x1c0238 popeq {r4, r5, r6, pc} */
/* @0x1c023c ldr r2, [r3] */
/* @0x1c0240 cmp r2, #2 */
/* @0x1c0244 ldrne r3, [r3, #0x14] */
/* @0x1c0248 beq 0x1c0258 <_Z23F_LayerDestroyInstancesR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x1c024c cmp r3, #0 */
/* @0x1c0250 bne 0x1c023c <_Z23F_LayerDestroyInstancesR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1c0254 pop {r4, r5, r6, pc} */
/* @0x1c0258 ldr r4, [r3, #0x18] */
/* @0x1c025c mov r0, r6 */
/* @0x1c0260 ldr r1, [r3, #0x4] */
/* @0x1c0264 mov r2, #0 */
/* @0x1c0268 mov r3, #1 */
/* @0x1c026c bl 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb> */
/* @0x1c0270 cmp r4, #0 */
/* @0x1c0274 mov r3, r4 */
/* @0x1c0278 ldreq r3, [r5, #0x58] */
/* @0x1c027c bne 0x1c023c <_Z23F_LayerDestroyInstancesR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1c0280 b 0x1c024c <_Z23F_LayerDestroyInstancesR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x1c0284 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1c0288 mov r1, r0 */
/* @0x1c028c mov r0, r6 */
/* @0x1c0290 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1c0294 mov r5, r0 */
/* @0x1c0298 b 0x1c0228 <_Z23F_LayerDestroyInstancesR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x1c029c ldr r3, [pc, #0x20] */
/* @0x1c02a0 ldr r1, [pc, #0x20] */
/* @0x1c02a4 ldr r3, [pc, r3] */
/* @0x1c02a8 add r1, pc, r1 */
/* @0x1c02ac ldr r0, [r3] */
/* @0x1c02b0 ldr r3, [r0] */
/* @0x1c02b4 ldr r3, [r3, #0xc] */
/* @0x1c02b8 blx r3 */
/* @0x1c02bc pop {r4, r5, r6, pc} */
/* @0x1c02c0 andseq pc, r8, r0, ror #10 */
/* @0x1c02c4 eoreq sp, r2, r0, ror r4 */
/* @0x1c02c8 ldrsbeq pc, [r8], -r0 */

/* ── FUNC 0x1c02cc · F_LayerBackgroundDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x1c02cc cmp r3, #1 */
/* @0x1c02d0 mov r1, #0 */
/* @0x1c02d4 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c02d8 mov r4, r1 */
/* @0x1c02dc mov r5, r3 */
/* @0x1c02e0 movt r1, #0xbff0 */
/* @0x1c02e4 str r4, [r0, #0xc] */
/* @0x1c02e8 str r1, [r0, #0x4] */
/* @0x1c02ec str r4, [r0] */
/* @0x1c02f0 ldr r6, [sp, #0x18] */
/* @0x1c02f4 beq 0x1c030c <_Z24F_LayerBackgroundDestroyR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1c02f8 ldr r0, [pc, #0x38] */
/* @0x1c02fc mov r1, r4 */
/* @0x1c0300 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c0304 add r0, pc, r0 */
/* @0x1c0308 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c030c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1c0310 mov r1, r4 */
/* @0x1c0314 mov r7, r0 */
/* @0x1c0318 mov r0, r6 */
/* @0x1c031c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c0320 mov r2, r5 */
/* @0x1c0324 mov r3, r4 */
/* @0x1c0328 mov r1, r0 */
/* @0x1c032c mov r0, r7 */
/* @0x1c0330 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c0334 b 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb> */
/* @0x1c0338 andseq pc, r8, r12, lsr #9 */

/* ── FUNC 0x1c033c · F_LayerSpriteDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x1c033c cmp r3, #1 */
/* @0x1c0340 mov r1, #0 */
/* @0x1c0344 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c0348 mov r4, r1 */
/* @0x1c034c mov r5, r3 */
/* @0x1c0350 movt r1, #0xbff0 */
/* @0x1c0354 str r4, [r0, #0xc] */
/* @0x1c0358 str r1, [r0, #0x4] */
/* @0x1c035c str r4, [r0] */
/* @0x1c0360 ldr r6, [sp, #0x18] */
/* @0x1c0364 beq 0x1c037c <_Z20F_LayerSpriteDestroyR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1c0368 ldr r0, [pc, #0x38] */
/* @0x1c036c mov r1, r4 */
/* @0x1c0370 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c0374 add r0, pc, r0 */
/* @0x1c0378 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c037c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1c0380 mov r1, r4 */
/* @0x1c0384 mov r7, r0 */
/* @0x1c0388 mov r0, r6 */
/* @0x1c038c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c0390 mov r2, r5 */
/* @0x1c0394 mov r3, r4 */
/* @0x1c0398 mov r1, r0 */
/* @0x1c039c mov r0, r7 */
/* @0x1c03a0 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c03a4 b 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb> */
/* @0x1c03a8 andseq pc, r8, r4, ror r4 */

/* ── FUNC 0x1c03ac · F_LayerTilemapDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x1c03ac cmp r3, #1 */
/* @0x1c03b0 mov r1, #0 */
/* @0x1c03b4 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c03b8 mov r4, r1 */
/* @0x1c03bc mov r5, r3 */
/* @0x1c03c0 movt r1, #0xbff0 */
/* @0x1c03c4 str r4, [r0, #0xc] */
/* @0x1c03c8 str r1, [r0, #0x4] */
/* @0x1c03cc str r4, [r0] */
/* @0x1c03d0 ldr r6, [sp, #0x18] */
/* @0x1c03d4 beq 0x1c03ec <_Z21F_LayerTilemapDestroyR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1c03d8 ldr r0, [pc, #0x38] */
/* @0x1c03dc mov r1, r4 */
/* @0x1c03e0 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c03e4 add r0, pc, r0 */
/* @0x1c03e8 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c03ec bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1c03f0 mov r1, r4 */
/* @0x1c03f4 mov r7, r0 */
/* @0x1c03f8 mov r0, r6 */
/* @0x1c03fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c0400 mov r2, r5 */
/* @0x1c0404 mov r3, r4 */
/* @0x1c0408 mov r1, r0 */
/* @0x1c040c mov r0, r7 */
/* @0x1c0410 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c0414 b 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb> */
/* @0x1c0418 andseq pc, r8, r8, lsr r4 */

/* ── FUNC 0x1c041c · F_LayerTileDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x1c041c cmp r3, #1 */
/* @0x1c0420 mov r1, #0 */
/* @0x1c0424 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c0428 mov r4, r1 */
/* @0x1c042c mov r5, r3 */
/* @0x1c0430 movt r1, #0xbff0 */
/* @0x1c0434 str r4, [r0, #0xc] */
/* @0x1c0438 str r1, [r0, #0x4] */
/* @0x1c043c str r4, [r0] */
/* @0x1c0440 ldr r6, [sp, #0x18] */
/* @0x1c0444 beq 0x1c045c <_Z18F_LayerTileDestroyR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1c0448 ldr r0, [pc, #0x38] */
/* @0x1c044c mov r1, r4 */
/* @0x1c0450 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c0454 add r0, pc, r0 */
/* @0x1c0458 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c045c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1c0460 mov r1, r4 */
/* @0x1c0464 mov r7, r0 */
/* @0x1c0468 mov r0, r6 */
/* @0x1c046c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c0470 mov r2, r5 */
/* @0x1c0474 mov r3, r4 */
/* @0x1c0478 mov r1, r0 */
/* @0x1c047c mov r0, r7 */
/* @0x1c0480 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c0484 b 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb> */
/* @0x1c0488 ldrsheq pc, [r8], -r12 */

/* ── FUNC 0x1c048c · CLayerManager::GetElementFromName(CLayer*, char const*) · size=92 · insn=23 */
/* @0x1c048c cmp r0, #0 */
/* @0x1c0490 push {r3, r4, r5, lr} */
/* @0x1c0494 mov r5, r1 */
/* @0x1c0498 popeq {r3, r4, r5, pc} */
/* @0x1c049c cmp r1, #0 */
/* @0x1c04a0 beq 0x1c04e0 <_ZN13CLayerManager18GetElementFromNameEP6CLayerPKc+0x54> */
/* @0x1c04a4 ldr r4, [r0, #0x58] */
/* @0x1c04a8 cmp r4, #0 */
/* @0x1c04ac beq 0x1c04d8 <_ZN13CLayerManager18GetElementFromNameEP6CLayerPKc+0x4c> */
/* @0x1c04b0 ldr r1, [r4, #0xc] */
/* @0x1c04b4 mov r0, r5 */
/* @0x1c04b8 cmp r1, #0 */
/* @0x1c04bc beq 0x1c04cc <_ZN13CLayerManager18GetElementFromNameEP6CLayerPKc+0x40> */
/* @0x1c04c0 bl 0xb66d0 <strcasecmp@plt> */
/* @0x1c04c4 cmp r0, #0 */
/* @0x1c04c8 beq 0x1c04d8 <_ZN13CLayerManager18GetElementFromNameEP6CLayerPKc+0x4c> */
/* @0x1c04cc ldr r4, [r4, #0x14] */
/* @0x1c04d0 cmp r4, #0 */
/* @0x1c04d4 bne 0x1c04b0 <_ZN13CLayerManager18GetElementFromNameEP6CLayerPKc+0x24> */
/* @0x1c04d8 mov r0, r4 */
/* @0x1c04dc pop {r3, r4, r5, pc} */
/* @0x1c04e0 mov r0, r1 */
/* @0x1c04e4 pop {r3, r4, r5, pc} */

/* ── FUNC 0x1c04e8 · CLayerManager::GetElementFromName(CRoom*, char const*, CLayer**) · size=92 · insn=23 */
/* @0x1c04e8 cmp r0, #0 */
/* @0x1c04ec push {r4, r5, r6, lr} */
/* @0x1c04f0 mov r5, r1 */
/* @0x1c04f4 mov r6, r2 */
/* @0x1c04f8 beq 0x1c0530 <_ZN13CLayerManager18GetElementFromNameEP5CRoomPKcPP6CLayer+0x48> */
/* @0x1c04fc cmp r1, #0 */
/* @0x1c0500 beq 0x1c0530 <_ZN13CLayerManager18GetElementFromNameEP5CRoomPKcPP6CLayer+0x48> */
/* @0x1c0504 ldr r4, [r0, #0xd4] */
/* @0x1c0508 cmp r4, #0 */
/* @0x1c050c beq 0x1c0530 <_ZN13CLayerManager18GetElementFromNameEP5CRoomPKcPP6CLayer+0x48> */
/* @0x1c0510 mov r0, r4 */
/* @0x1c0514 mov r1, r5 */
/* @0x1c0518 bl 0x1c048c <_ZN13CLayerManager18GetElementFromNameEP6CLayerPKc> */
/* @0x1c051c cmp r0, #0 */
/* @0x1c0520 bne 0x1c0538 <_ZN13CLayerManager18GetElementFromNameEP5CRoomPKcPP6CLayer+0x50> */
/* @0x1c0524 ldr r4, [r4, #0x68] */
/* @0x1c0528 cmp r4, #0 */
/* @0x1c052c bne 0x1c0510 <_ZN13CLayerManager18GetElementFromNameEP5CRoomPKcPP6CLayer+0x28> */
/* @0x1c0530 mov r0, #0 */
/* @0x1c0534 pop {r4, r5, r6, pc} */
/* @0x1c0538 cmp r6, #0 */
/* @0x1c053c strne r4, [r6] */
/* @0x1c0540 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1c0544 · F_LayerBackgroundGetID(RValue&, CInstance*, CInstance*, int, RValue*) · size=204 · insn=51 */
/* @0x1c0544 cmp r3, #1 */
/* @0x1c0548 push {r3, r4, r5, r6, r7, lr} */
/* @0x1c054c mov r3, #0 */
/* @0x1c0550 mov r5, r3 */
/* @0x1c0554 mov r4, r0 */
/* @0x1c0558 movt r3, #0xbff0 */
/* @0x1c055c str r5, [r0, #0xc] */
/* @0x1c0560 str r3, [r0, #0x4] */
/* @0x1c0564 str r5, [r0] */
/* @0x1c0568 ldr r6, [sp, #0x18] */
/* @0x1c056c beq 0x1c0584 <_Z22F_LayerBackgroundGetIDR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1c0570 ldr r0, [pc, #0x94] */
/* @0x1c0574 mov r1, r5 */
/* @0x1c0578 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1c057c add r0, pc, r0 */
/* @0x1c0580 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c0584 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1c0588 ldr r3, [r6, #0xc] */
/* @0x1c058c mov r1, r5 */
/* @0x1c0590 bic r3, r3, #-16777216 */
/* @0x1c0594 cmp r3, #1 */
/* @0x1c0598 mov r7, r0 */
/* @0x1c059c mov r0, r6 */
/* @0x1c05a0 beq 0x1c05f0 <_Z22F_LayerBackgroundGetIDR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x1c05a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c05a8 mov r1, r0 */
/* @0x1c05ac mov r0, r7 */
/* @0x1c05b0 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c05b4 cmp r0, #0 */
/* @0x1c05b8 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1c05bc ldr r1, [r0, #0x1c] */
/* @0x1c05c0 bl 0x1c048c <_ZN13CLayerManager18GetElementFromNameEP6CLayerPKc> */
/* @0x1c05c4 cmp r0, #0 */
/* @0x1c05c8 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1c05cc ldr r3, [r0] */
/* @0x1c05d0 cmp r3, #1 */
/* @0x1c05d4 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1c05d8 ldr r2, [r0, #0x4] */
/* @0x1c05dc vmov s15, r2 */
/* @0x1c05e0 vcvt.f64.s32 d7, s15 */
/* @0x1c05e4 vmov r2, r3, d7 */
/* @0x1c05e8 stm r4, {r2, r3} */
/* @0x1c05ec pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c05f0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1c05f4 mov r1, r0 */
/* @0x1c05f8 mov r0, r7 */
/* @0x1c05fc bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1c0600 cmp r0, #0 */
/* @0x1c0604 bne 0x1c05bc <_Z22F_LayerBackgroundGetIDR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1c0608 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c060c andseq pc, r8, r8, lsl #6 */

/* ── FUNC 0x1c0610 · F_LayerSpriteGetID(RValue&, CInstance*, CInstance*, int, RValue*) · size=228 · insn=57 */
/* @0x1c0610 cmp r3, #2 */
/* @0x1c0614 push {r3, r4, r5, r6, r7, lr} */
/* @0x1c0618 mov r3, #0 */
/* @0x1c061c mov r5, r3 */
/* @0x1c0620 mov r4, r0 */
/* @0x1c0624 movt r3, #0xbff0 */
/* @0x1c0628 str r5, [r0, #0xc] */
/* @0x1c062c str r3, [r0, #0x4] */
/* @0x1c0630 str r5, [r0] */
/* @0x1c0634 ldr r6, [sp, #0x18] */
/* @0x1c0638 beq 0x1c0650 <_Z18F_LayerSpriteGetIDR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1c063c ldr r0, [pc, #0xac] */
/* @0x1c0640 mov r1, r5 */
/* @0x1c0644 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1c0648 add r0, pc, r0 */
/* @0x1c064c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c0650 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1c0654 ldr r3, [r6, #0xc] */
/* @0x1c0658 mov r1, r5 */
/* @0x1c065c bic r3, r3, #-16777216 */
/* @0x1c0660 cmp r3, #1 */
/* @0x1c0664 mov r7, r0 */
/* @0x1c0668 mov r0, r6 */
/* @0x1c066c beq 0x1c06d0 <_Z18F_LayerSpriteGetIDR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x1c0670 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c0674 mov r1, r0 */
/* @0x1c0678 mov r0, r7 */
/* @0x1c067c bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c0680 mov r5, r0 */
/* @0x1c0684 cmp r5, #0 */
/* @0x1c0688 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1c068c mov r1, #1 */
/* @0x1c0690 mov r0, r6 */
/* @0x1c0694 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1c0698 mov r1, r0 */
/* @0x1c069c mov r0, r5 */
/* @0x1c06a0 bl 0x1c048c <_ZN13CLayerManager18GetElementFromNameEP6CLayerPKc> */
/* @0x1c06a4 cmp r0, #0 */
/* @0x1c06a8 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1c06ac ldr r3, [r0] */
/* @0x1c06b0 cmp r3, #4 */
/* @0x1c06b4 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1c06b8 ldr r2, [r0, #0x4] */
/* @0x1c06bc vmov s15, r2 */
/* @0x1c06c0 vcvt.f64.s32 d7, s15 */
/* @0x1c06c4 vmov r2, r3, d7 */
/* @0x1c06c8 stm r4, {r2, r3} */
/* @0x1c06cc pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c06d0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1c06d4 mov r1, r0 */
/* @0x1c06d8 mov r0, r7 */
/* @0x1c06dc bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1c06e0 mov r5, r0 */
/* @0x1c06e4 cmp r5, #0 */
/* @0x1c06e8 bne 0x1c068c <_Z18F_LayerSpriteGetIDR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x1c06ec pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c06f0 andseq pc, r8, r4, ror r2 */

/* ── FUNC 0x1c06f4 · F_LayerTilemapGetID(RValue&, CInstance*, CInstance*, int, RValue*) · size=240 · insn=60 */
/* @0x1c06f4 cmp r3, #1 */
/* @0x1c06f8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1c06fc mov r3, #0 */
/* @0x1c0700 mov r5, r3 */
/* @0x1c0704 mov r4, r0 */
/* @0x1c0708 movt r3, #0xbff0 */
/* @0x1c070c str r5, [r0, #0xc] */
/* @0x1c0710 str r3, [r0, #0x4] */
/* @0x1c0714 str r5, [r0] */
/* @0x1c0718 ldr r6, [sp, #0x18] */
/* @0x1c071c beq 0x1c0734 <_Z19F_LayerTilemapGetIDR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1c0720 ldr r0, [pc, #0xb0] */
/* @0x1c0724 mov r1, r5 */
/* @0x1c0728 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1c072c add r0, pc, r0 */
/* @0x1c0730 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c0734 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1c0738 ldr r3, [r6, #0xc] */
/* @0x1c073c mov r1, r5 */
/* @0x1c0740 bic r3, r3, #-16777216 */
/* @0x1c0744 cmp r3, #1 */
/* @0x1c0748 mov r7, r0 */
/* @0x1c074c mov r0, r6 */
/* @0x1c0750 beq 0x1c07a0 <_Z19F_LayerTilemapGetIDR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x1c0754 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c0758 mov r1, r0 */
/* @0x1c075c mov r0, r7 */
/* @0x1c0760 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c0764 cmp r0, #0 */
/* @0x1c0768 beq 0x1c07b4 <_Z19F_LayerTilemapGetIDR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x1c076c ldr r1, [r0, #0x1c] */
/* @0x1c0770 bl 0x1c048c <_ZN13CLayerManager18GetElementFromNameEP6CLayerPKc> */
/* @0x1c0774 cmp r0, #0 */
/* @0x1c0778 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1c077c ldr r3, [r0] */
/* @0x1c0780 cmp r3, #5 */
/* @0x1c0784 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1c0788 ldr r2, [r0, #0x4] */
/* @0x1c078c vmov s15, r2 */
/* @0x1c0790 vcvt.f64.s32 d7, s15 */
/* @0x1c0794 vmov r2, r3, d7 */
/* @0x1c0798 stm r4, {r2, r3} */
/* @0x1c079c pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c07a0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1c07a4 mov r1, r0 */
/* @0x1c07a8 mov r0, r7 */
/* @0x1c07ac bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1c07b0 b 0x1c0764 <_Z19F_LayerTilemapGetIDR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x1c07b4 ldr r3, [pc, #0x20] */
/* @0x1c07b8 ldr r1, [pc, #0x20] */
/* @0x1c07bc ldr r3, [pc, r3] */
/* @0x1c07c0 add r1, pc, r1 */
/* @0x1c07c4 ldr r0, [r3] */
/* @0x1c07c8 ldr r3, [r0] */
/* @0x1c07cc ldr r3, [r3, #0xc] */
/* @0x1c07d0 blx r3 */
/* @0x1c07d4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c07d8 andseq pc, r8, r4, asr #3 */
/* @0x1c07dc eoreq r12, r2, r8, asr pc */
/* @0x1c07e0 andseq pc, r8, r4, ror #2 */

/* ── FUNC 0x1c07e4 · CLayerManager::GetElementFromID(CLayer*, int) · size=68 · insn=17 */
/* @0x1c07e4 cmp r0, #0 */
/* @0x1c07e8 bxeq lr */
/* @0x1c07ec ldr r0, [r0, #0x58] */
/* @0x1c07f0 cmp r0, #0 */
/* @0x1c07f4 bxeq lr */
/* @0x1c07f8 ldr r3, [r0, #0x4] */
/* @0x1c07fc cmp r3, r1 */
/* @0x1c0800 beq 0x1c0824 <_ZN13CLayerManager16GetElementFromIDEP6CLayeri+0x40> */
/* @0x1c0804 ldr r0, [r0, #0x14] */
/* @0x1c0808 cmp r0, #0 */
/* @0x1c080c beq 0x1c0820 <_ZN13CLayerManager16GetElementFromIDEP6CLayeri+0x3c> */
/* @0x1c0810 ldr r3, [r0, #0x4] */
/* @0x1c0814 cmp r3, r1 */
/* @0x1c0818 bne 0x1c0804 <_ZN13CLayerManager16GetElementFromIDEP6CLayeri+0x20> */
/* @0x1c081c bx lr */
/* @0x1c0820 bx lr */
/* @0x1c0824 bx lr */

/* ── FUNC 0x1c0828 · F_LayerBackgroundExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0x1c0828 cmp r3, #2 */
/* @0x1c082c push {r3, r4, r5, r6, r7, lr} */
/* @0x1c0830 mov r4, #0 */
/* @0x1c0834 mov r5, r0 */
/* @0x1c0838 ldr r6, [sp, #0x18] */
/* @0x1c083c str r4, [r0, #0xc] */
/* @0x1c0840 str r4, [r0] */
/* @0x1c0844 str r4, [r0, #0x4] */
/* @0x1c0848 beq 0x1c0860 <_Z23F_LayerBackgroundExistsR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1c084c ldr r0, [pc, #0xa4] */
/* @0x1c0850 mov r1, r4 */
/* @0x1c0854 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1c0858 add r0, pc, r0 */
/* @0x1c085c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c0860 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1c0864 ldr r3, [r6, #0xc] */
/* @0x1c0868 mov r1, r4 */
/* @0x1c086c bic r3, r3, #-16777216 */
/* @0x1c0870 cmp r3, #1 */
/* @0x1c0874 mov r7, r0 */
/* @0x1c0878 mov r0, r6 */
/* @0x1c087c beq 0x1c08d8 <_Z23F_LayerBackgroundExistsR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x1c0880 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c0884 mov r1, r0 */
/* @0x1c0888 mov r0, r7 */
/* @0x1c088c bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c0890 mov r4, r0 */
/* @0x1c0894 cmp r4, #0 */
/* @0x1c0898 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1c089c mov r1, #1 */
/* @0x1c08a0 mov r0, r6 */
/* @0x1c08a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c08a8 mov r1, r0 */
/* @0x1c08ac mov r0, r4 */
/* @0x1c08b0 bl 0x1c07e4 <_ZN13CLayerManager16GetElementFromIDEP6CLayeri> */
/* @0x1c08b4 cmp r0, #0 */
/* @0x1c08b8 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1c08bc ldr r3, [r0] */
/* @0x1c08c0 cmp r3, #1 */
/* @0x1c08c4 moveq r3, #0 */
/* @0x1c08c8 moveq r2, r3 */
/* @0x1c08cc movteq r3, #0x3ff0 */
/* @0x1c08d0 stmeq r5, {r2, r3} */
/* @0x1c08d4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c08d8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1c08dc mov r1, r0 */
/* @0x1c08e0 mov r0, r7 */
/* @0x1c08e4 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1c08e8 mov r4, r0 */
/* @0x1c08ec cmp r4, #0 */
/* @0x1c08f0 bne 0x1c089c <_Z23F_LayerBackgroundExistsR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x1c08f4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c08f8 andseq pc, r8, r4, lsl #2 */

/* ── FUNC 0x1c08fc · F_LayerSpriteExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0x1c08fc cmp r3, #2 */
/* @0x1c0900 push {r3, r4, r5, r6, r7, lr} */
/* @0x1c0904 mov r4, #0 */
/* @0x1c0908 mov r5, r0 */
/* @0x1c090c ldr r6, [sp, #0x18] */
/* @0x1c0910 str r4, [r0, #0xc] */
/* @0x1c0914 str r4, [r0] */
/* @0x1c0918 str r4, [r0, #0x4] */
/* @0x1c091c beq 0x1c0934 <_Z19F_LayerSpriteExistsR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1c0920 ldr r0, [pc, #0xa4] */
/* @0x1c0924 mov r1, r4 */
/* @0x1c0928 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1c092c add r0, pc, r0 */
/* @0x1c0930 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c0934 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1c0938 ldr r3, [r6, #0xc] */
/* @0x1c093c mov r1, r4 */
/* @0x1c0940 bic r3, r3, #-16777216 */
/* @0x1c0944 cmp r3, #1 */
/* @0x1c0948 mov r7, r0 */
/* @0x1c094c mov r0, r6 */
/* @0x1c0950 beq 0x1c09ac <_Z19F_LayerSpriteExistsR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x1c0954 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c0958 mov r1, r0 */
/* @0x1c095c mov r0, r7 */
/* @0x1c0960 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c0964 mov r4, r0 */
/* @0x1c0968 cmp r4, #0 */
/* @0x1c096c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1c0970 mov r1, #1 */
/* @0x1c0974 mov r0, r6 */
/* @0x1c0978 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c097c mov r1, r0 */
/* @0x1c0980 mov r0, r4 */
/* @0x1c0984 bl 0x1c07e4 <_ZN13CLayerManager16GetElementFromIDEP6CLayeri> */
/* @0x1c0988 cmp r0, #0 */
/* @0x1c098c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1c0990 ldr r3, [r0] */
/* @0x1c0994 cmp r3, #4 */
/* @0x1c0998 moveq r3, #0 */
/* @0x1c099c moveq r2, r3 */
/* @0x1c09a0 movteq r3, #0x3ff0 */
/* @0x1c09a4 stmeq r5, {r2, r3} */
/* @0x1c09a8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c09ac bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1c09b0 mov r1, r0 */
/* @0x1c09b4 mov r0, r7 */
/* @0x1c09b8 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1c09bc mov r4, r0 */
/* @0x1c09c0 cmp r4, #0 */
/* @0x1c09c4 bne 0x1c0970 <_Z19F_LayerSpriteExistsR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x1c09c8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c09cc andseq pc, r8, r8, rrx */

/* ── FUNC 0x1c09d0 · F_LayerTilemapExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=248 · insn=62 */
/* @0x1c09d0 cmp r3, #2 */
/* @0x1c09d4 push {r3, r4, r5, r6, r7, lr} */
/* @0x1c09d8 mov r4, #0 */
/* @0x1c09dc mov r5, r0 */
/* @0x1c09e0 ldr r6, [sp, #0x18] */
/* @0x1c09e4 str r4, [r0, #0xc] */
/* @0x1c09e8 str r4, [r0] */
/* @0x1c09ec str r4, [r0, #0x4] */
/* @0x1c09f0 beq 0x1c0a08 <_Z20F_LayerTilemapExistsR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1c09f4 ldr r0, [pc, #0xc0] */
/* @0x1c09f8 mov r1, r4 */
/* @0x1c09fc pop {r3, r4, r5, r6, r7, lr} */
/* @0x1c0a00 add r0, pc, r0 */
/* @0x1c0a04 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c0a08 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1c0a0c ldr r3, [r6, #0xc] */
/* @0x1c0a10 mov r1, r4 */
/* @0x1c0a14 bic r3, r3, #-16777216 */
/* @0x1c0a18 cmp r3, #1 */
/* @0x1c0a1c mov r7, r0 */
/* @0x1c0a20 mov r0, r6 */
/* @0x1c0a24 beq 0x1c0a80 <_Z20F_LayerTilemapExistsR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x1c0a28 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c0a2c mov r1, r0 */
/* @0x1c0a30 mov r0, r7 */
/* @0x1c0a34 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c0a38 mov r4, r0 */
/* @0x1c0a3c cmp r4, #0 */
/* @0x1c0a40 beq 0x1c0a98 <_Z20F_LayerTilemapExistsR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x1c0a44 mov r1, #1 */
/* @0x1c0a48 mov r0, r6 */
/* @0x1c0a4c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c0a50 mov r1, r0 */
/* @0x1c0a54 mov r0, r4 */
/* @0x1c0a58 bl 0x1c07e4 <_ZN13CLayerManager16GetElementFromIDEP6CLayeri> */
/* @0x1c0a5c cmp r0, #0 */
/* @0x1c0a60 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1c0a64 ldr r3, [r0] */
/* @0x1c0a68 cmp r3, #5 */
/* @0x1c0a6c moveq r3, #0 */
/* @0x1c0a70 moveq r2, r3 */
/* @0x1c0a74 movteq r3, #0x3ff0 */
/* @0x1c0a78 stmeq r5, {r2, r3} */
/* @0x1c0a7c pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c0a80 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1c0a84 mov r1, r0 */
/* @0x1c0a88 mov r0, r7 */
/* @0x1c0a8c bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1c0a90 mov r4, r0 */
/* @0x1c0a94 b 0x1c0a3c <_Z20F_LayerTilemapExistsR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x1c0a98 ldr r3, [pc, #0x20] */
/* @0x1c0a9c ldr r1, [pc, #0x20] */
/* @0x1c0aa0 ldr r3, [pc, r3] */
/* @0x1c0aa4 add r1, pc, r1 */
/* @0x1c0aa8 ldr r0, [r3] */
/* @0x1c0aac ldr r3, [r0] */
/* @0x1c0ab0 ldr r3, [r3, #0xc] */
/* @0x1c0ab4 blx r3 */
/* @0x1c0ab8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c0abc andseq lr, r8, r8, asr #31 */
/* @0x1c0ac0 eoreq r12, r2, r4, ror r12 */
/* @0x1c0ac4 andseq lr, r8, r8, asr pc */

/* ── FUNC 0x1c0ac8 · F_LayerTileExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=272 · insn=68 */
/* @0x1c0ac8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c0acc mov r6, r3 */
/* @0x1c0ad0 sub r3, r3, #1 */
/* @0x1c0ad4 mov r4, #0 */
/* @0x1c0ad8 cmp r3, #1 */
/* @0x1c0adc mov r5, r0 */
/* @0x1c0ae0 ldr r7, [sp, #0x18] */
/* @0x1c0ae4 str r4, [r0, #0xc] */
/* @0x1c0ae8 str r4, [r0] */
/* @0x1c0aec str r4, [r0, #0x4] */
/* @0x1c0af0 bls 0x1c0b08 <_Z17F_LayerTileExistsR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1c0af4 ldr r0, [pc, #0xd8] */
/* @0x1c0af8 mov r1, r4 */
/* @0x1c0afc pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c0b00 add r0, pc, r0 */
/* @0x1c0b04 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c0b08 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1c0b0c cmp r6, #1 */
/* @0x1c0b10 mov r8, r0 */
/* @0x1c0b14 beq 0x1c0b88 <_Z17F_LayerTileExistsR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x1c0b18 ldr r3, [r7, #0xc] */
/* @0x1c0b1c mov r1, r4 */
/* @0x1c0b20 mov r0, r7 */
/* @0x1c0b24 bic r3, r3, #-16777216 */
/* @0x1c0b28 cmp r3, #1 */
/* @0x1c0b2c beq 0x1c0bbc <_Z17F_LayerTileExistsR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x1c0b30 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c0b34 mov r1, r0 */
/* @0x1c0b38 mov r0, r8 */
/* @0x1c0b3c bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c0b40 mov r4, r0 */
/* @0x1c0b44 cmp r4, #0 */
/* @0x1c0b48 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1c0b4c mov r1, #1 */
/* @0x1c0b50 mov r0, r7 */
/* @0x1c0b54 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c0b58 mov r1, r0 */
/* @0x1c0b5c mov r0, r4 */
/* @0x1c0b60 bl 0x1c07e4 <_ZN13CLayerManager16GetElementFromIDEP6CLayeri> */
/* @0x1c0b64 cmp r0, #0 */
/* @0x1c0b68 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1c0b6c ldr r3, [r0] */
/* @0x1c0b70 cmp r3, #7 */
/* @0x1c0b74 moveq r3, #0 */
/* @0x1c0b78 moveq r2, r3 */
/* @0x1c0b7c movteq r3, #0x3ff0 */
/* @0x1c0b80 stmeq r5, {r2, r3} */
/* @0x1c0b84 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c0b88 mov r1, r4 */
/* @0x1c0b8c mov r0, r7 */
/* @0x1c0b90 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c0b94 mov r2, r4 */
/* @0x1c0b98 mov r1, r0 */
/* @0x1c0b9c mov r0, r8 */
/* @0x1c0ba0 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1c0ba4 cmp r0, #0 */
/* @0x1c0ba8 movne r3, #0 */
/* @0x1c0bac strne r4, [r5] */
/* @0x1c0bb0 movtne r3, #0x3ff0 */
/* @0x1c0bb4 strne r3, [r5, #0x4] */
/* @0x1c0bb8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c0bbc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1c0bc0 mov r1, r0 */
/* @0x1c0bc4 mov r0, r8 */
/* @0x1c0bc8 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1c0bcc mov r4, r0 */
/* @0x1c0bd0 b 0x1c0b44 <_Z17F_LayerTileExistsR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x1c0bd4 andseq lr, r8, r4, lsr pc */

/* ── FUNC 0x1c0bd8 · CLayerManager::GetNewBackgroundElement() · size=260 · insn=65 */
/* @0x1c0bd8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1c0bdc ldr r4, [pc, #0xf0] */
/* @0x1c0be0 ldr r4, [pc, r4] */
/* @0x1c0be4 ldr r6, [r4, #0x8] */
/* @0x1c0be8 cmp r6, #0 */
/* @0x1c0bec bne 0x1c0c9c <_ZN13CLayerManager23GetNewBackgroundElementEv+0xc4> */
/* @0x1c0bf0 ldr r3, [r4, #0x10] */
/* @0x1c0bf4 cmp r3, #0 */
/* @0x1c0bf8 ble 0x1c0c94 <_ZN13CLayerManager23GetNewBackgroundElementEv+0xbc> */
/* @0x1c0bfc ldr r7, [pc, #0xd4] */
/* @0x1c0c00 mov r5, r6 */
/* @0x1c0c04 mov r9, #1 */
/* @0x1c0c08 mvn r8, #0 */
/* @0x1c0c0c add r7, pc, r7 */
/* @0x1c0c10 mov r0, #32 */
/* @0x1c0c14 mov r1, r7 */
/* @0x1c0c18 mov r2, #63 */
/* @0x1c0c1c mov r3, #1 */
/* @0x1c0c20 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c0c24 cmp r0, #0 */
/* @0x1c0c28 beq 0x1c0c4c <_ZN13CLayerManager23GetNewBackgroundElementEv+0x74> */
/* @0x1c0c2c strb r5, [r0, #0x8] */
/* @0x1c0c30 str r5, [r0, #0xc] */
/* @0x1c0c34 str r5, [r0, #0x10] */
/* @0x1c0c38 str r5, [r0, #0x14] */
/* @0x1c0c3c str r5, [r0, #0x18] */
/* @0x1c0c40 str r8, [r0, #0x4] */
/* @0x1c0c44 str r5, [r0, #0x1c] */
/* @0x1c0c48 str r9, [r0] */
/* @0x1c0c4c ldr r3, [r4] */
/* @0x1c0c50 add r6, r6, #1 */
/* @0x1c0c54 ldr r2, [r4, #0x8] */
/* @0x1c0c58 cmp r3, #0 */
/* @0x1c0c5c streq r0, [r4, #0x4] */
/* @0x1c0c60 strne r0, [r3, #0x18] */
/* @0x1c0c64 add r2, r2, #1 */
/* @0x1c0c68 streq r3, [r0, #0x18] */
/* @0x1c0c6c streq r3, [r0, #0x14] */
/* @0x1c0c70 strne r3, [r0, #0x14] */
/* @0x1c0c74 ldr r3, [r4, #0x10] */
/* @0x1c0c78 streq r0, [r4] */
/* @0x1c0c7c strne r0, [r4] */
/* @0x1c0c80 strne r5, [r0, #0x18] */
/* @0x1c0c84 cmp r6, r3 */
/* @0x1c0c88 str r2, [r4, #0x8] */
/* @0x1c0c8c blt 0x1c0c10 <_ZN13CLayerManager23GetNewBackgroundElementEv+0x38> */
/* @0x1c0c90 ldr r6, [r4, #0x8] */
/* @0x1c0c94 lsl r3, r3, #1 */
/* @0x1c0c98 str r3, [r4, #0x10] */
/* @0x1c0c9c ldr r0, [r4] */
/* @0x1c0ca0 sub r6, r6, #1 */
/* @0x1c0ca4 str r6, [r4, #0x8] */
/* @0x1c0ca8 ldr r3, [r0, #0x18] */
/* @0x1c0cac ldr r2, [r0, #0x14] */
/* @0x1c0cb0 cmp r3, #0 */
/* @0x1c0cb4 strne r2, [r3, #0x14] */
/* @0x1c0cb8 ldrne r2, [r0, #0x14] */
/* @0x1c0cbc ldrne r3, [r0, #0x18] */
/* @0x1c0cc0 streq r2, [r4] */
/* @0x1c0cc4 cmp r2, #0 */
/* @0x1c0cc8 streq r3, [r4, #0x4] */
/* @0x1c0ccc strne r3, [r2, #0x18] */
/* @0x1c0cd0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1c0cd4 eoreq pc, r2, r0, lsl #25 */
/* @0x1c0cd8 andseq r12, r8, r8, lsl #21 */

/* ── FUNC 0x1c0cdc · CLayerManager::GetNewInstanceElement() · size=264 · insn=66 */
/* @0x1c0cdc push {r4, r5, r6, r7, r8, lr} */
/* @0x1c0ce0 ldr r4, [pc, #0xf4] */
/* @0x1c0ce4 ldr r4, [pc, r4] */
/* @0x1c0ce8 ldr r6, [r4, #0x8] */
/* @0x1c0cec cmp r6, #0 */
/* @0x1c0cf0 bne 0x1c0da4 <_ZN13CLayerManager21GetNewInstanceElementEv+0xc8> */
/* @0x1c0cf4 ldr r3, [r4, #0x10] */
/* @0x1c0cf8 cmp r3, #0 */
/* @0x1c0cfc ble 0x1c0d9c <_ZN13CLayerManager21GetNewInstanceElementEv+0xc0> */
/* @0x1c0d00 ldr r8, [pc, #0xd8] */
/* @0x1c0d04 mov r5, r6 */
/* @0x1c0d08 mvn r7, #0 */
/* @0x1c0d0c add r8, pc, r8 */
/* @0x1c0d10 mov r3, #1 */
/* @0x1c0d14 mov r0, #36 */
/* @0x1c0d18 mov r1, r8 */
/* @0x1c0d1c mov r2, #63 */
/* @0x1c0d20 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c0d24 mov r3, #2 */
/* @0x1c0d28 cmp r0, #0 */
/* @0x1c0d2c beq 0x1c0d54 <_ZN13CLayerManager21GetNewInstanceElementEv+0x78> */
/* @0x1c0d30 strb r5, [r0, #0x8] */
/* @0x1c0d34 str r5, [r0, #0xc] */
/* @0x1c0d38 str r5, [r0, #0x10] */
/* @0x1c0d3c str r5, [r0, #0x14] */
/* @0x1c0d40 str r5, [r0, #0x18] */
/* @0x1c0d44 str r7, [r0, #0x4] */
/* @0x1c0d48 str r7, [r0, #0x1c] */
/* @0x1c0d4c str r5, [r0, #0x20] */
/* @0x1c0d50 str r3, [r0] */
/* @0x1c0d54 ldr r3, [r4] */
/* @0x1c0d58 add r6, r6, #1 */
/* @0x1c0d5c ldr r2, [r4, #0x8] */
/* @0x1c0d60 cmp r3, #0 */
/* @0x1c0d64 streq r0, [r4, #0x4] */
/* @0x1c0d68 strne r0, [r3, #0x18] */
/* @0x1c0d6c add r2, r2, #1 */
/* @0x1c0d70 streq r3, [r0, #0x18] */
/* @0x1c0d74 streq r3, [r0, #0x14] */
/* @0x1c0d78 strne r3, [r0, #0x14] */
/* @0x1c0d7c ldr r3, [r4, #0x10] */
/* @0x1c0d80 streq r0, [r4] */
/* @0x1c0d84 strne r0, [r4] */
/* @0x1c0d88 strne r5, [r0, #0x18] */
/* @0x1c0d8c cmp r6, r3 */
/* @0x1c0d90 str r2, [r4, #0x8] */
/* @0x1c0d94 blt 0x1c0d10 <_ZN13CLayerManager21GetNewInstanceElementEv+0x34> */
/* @0x1c0d98 ldr r6, [r4, #0x8] */
/* @0x1c0d9c lsl r3, r3, #1 */
/* @0x1c0da0 str r3, [r4, #0x10] */
/* @0x1c0da4 ldr r0, [r4] */
/* @0x1c0da8 sub r6, r6, #1 */
/* @0x1c0dac str r6, [r4, #0x8] */
/* @0x1c0db0 ldr r3, [r0, #0x18] */
/* @0x1c0db4 ldr r2, [r0, #0x14] */
/* @0x1c0db8 cmp r3, #0 */
/* @0x1c0dbc strne r2, [r3, #0x14] */
/* @0x1c0dc0 ldrne r2, [r0, #0x14] */
/* @0x1c0dc4 ldrne r3, [r0, #0x18] */
/* @0x1c0dc8 streq r2, [r4] */
/* @0x1c0dcc cmp r2, #0 */
/* @0x1c0dd0 streq r3, [r4, #0x4] */
/* @0x1c0dd4 strne r3, [r2, #0x18] */
/* @0x1c0dd8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c0ddc eoreq pc, r2, r0, lsl #23 */
/* @0x1c0de0 andseq r12, r8, r8, lsl #19 */

/* ── FUNC 0x1c0de4 · CLayerManager::GetNewOldTilemapElement() · size=284 · insn=71 */
/* @0x1c0de4 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1c0de8 ldr r5, [pc, #0x108] */
/* @0x1c0dec ldr r5, [pc, r5] */
/* @0x1c0df0 ldr r6, [r5, #0x8] */
/* @0x1c0df4 cmp r6, #0 */
/* @0x1c0df8 bne 0x1c0ec0 <_ZN13CLayerManager23GetNewOldTilemapElementEv+0xdc> */
/* @0x1c0dfc ldr r3, [r5, #0x10] */
/* @0x1c0e00 cmp r3, #0 */
/* @0x1c0e04 ble 0x1c0eb8 <_ZN13CLayerManager23GetNewOldTilemapElementEv+0xd4> */
/* @0x1c0e08 ldr r7, [pc, #0xec] */
/* @0x1c0e0c mov r4, r6 */
/* @0x1c0e10 mov r9, #1 */
/* @0x1c0e14 mvn r8, #0 */
/* @0x1c0e18 add r7, pc, r7 */
/* @0x1c0e1c mov r3, #1 */
/* @0x1c0e20 mov r0, #52 */
/* @0x1c0e24 mov r1, r7 */
/* @0x1c0e28 mov r2, #63 */
/* @0x1c0e2c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c0e30 mov r3, #3 */
/* @0x1c0e34 cmp r0, #0 */
/* @0x1c0e38 beq 0x1c0e70 <_ZN13CLayerManager23GetNewOldTilemapElementEv+0x8c> */
/* @0x1c0e3c strb r4, [r0, #0x8] */
/* @0x1c0e40 str r4, [r0, #0xc] */
/* @0x1c0e44 str r4, [r0, #0x10] */
/* @0x1c0e48 str r4, [r0, #0x14] */
/* @0x1c0e4c str r4, [r0, #0x18] */
/* @0x1c0e50 str r8, [r0, #0x4] */
/* @0x1c0e54 str r4, [r0, #0x1c] */
/* @0x1c0e58 str r4, [r0, #0x20] */
/* @0x1c0e5c str r4, [r0, #0x28] */
/* @0x1c0e60 str r4, [r0, #0x24] */
/* @0x1c0e64 str r4, [r0, #0x2c] */
/* @0x1c0e68 str r9, [r0, #0x30] */
/* @0x1c0e6c str r3, [r0] */
/* @0x1c0e70 ldr r3, [r5] */
/* @0x1c0e74 add r6, r6, #1 */
/* @0x1c0e78 ldr r2, [r5, #0x8] */
/* @0x1c0e7c cmp r3, #0 */
/* @0x1c0e80 streq r0, [r5, #0x4] */
/* @0x1c0e84 strne r0, [r3, #0x18] */
/* @0x1c0e88 add r2, r2, #1 */
/* @0x1c0e8c streq r3, [r0, #0x18] */
/* @0x1c0e90 streq r3, [r0, #0x14] */
/* @0x1c0e94 strne r3, [r0, #0x14] */
/* @0x1c0e98 ldr r3, [r5, #0x10] */
/* @0x1c0e9c streq r0, [r5] */
/* @0x1c0ea0 strne r0, [r5] */
/* @0x1c0ea4 strne r4, [r0, #0x18] */
/* @0x1c0ea8 cmp r6, r3 */
/* @0x1c0eac str r2, [r5, #0x8] */
/* @0x1c0eb0 blt 0x1c0e1c <_ZN13CLayerManager23GetNewOldTilemapElementEv+0x38> */
/* @0x1c0eb4 ldr r6, [r5, #0x8] */
/* @0x1c0eb8 lsl r3, r3, #1 */
/* @0x1c0ebc str r3, [r5, #0x10] */
/* @0x1c0ec0 ldr r0, [r5] */
/* @0x1c0ec4 sub r6, r6, #1 */
/* @0x1c0ec8 str r6, [r5, #0x8] */
/* @0x1c0ecc ldr r3, [r0, #0x18] */
/* @0x1c0ed0 ldr r2, [r0, #0x14] */
/* @0x1c0ed4 cmp r3, #0 */
/* @0x1c0ed8 strne r2, [r3, #0x14] */
/* @0x1c0edc ldrne r2, [r0, #0x14] */
/* @0x1c0ee0 ldrne r3, [r0, #0x18] */
/* @0x1c0ee4 streq r2, [r5] */
/* @0x1c0ee8 cmp r2, #0 */
/* @0x1c0eec streq r3, [r5, #0x4] */
/* @0x1c0ef0 strne r3, [r2, #0x18] */
/* @0x1c0ef4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1c0ef8 eoreq pc, r2, r12, ror r10 */
/* @0x1c0efc andseq r12, r8, r12, ror r8 */

/* ── FUNC 0x1c0f00 · CLayerManager::GetNewSpriteElement() · size=308 · insn=77 */
/* @0x1c0f00 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c0f04 ldr r4, [pc, #0x120] */
/* @0x1c0f08 ldr r4, [pc, r4] */
/* @0x1c0f0c ldr r8, [r4, #0x8] */
/* @0x1c0f10 cmp r8, #0 */
/* @0x1c0f14 bne 0x1c0ff4 <_ZN13CLayerManager19GetNewSpriteElementEv+0xf4> */
/* @0x1c0f18 ldr r3, [r4, #0x10] */
/* @0x1c0f1c cmp r3, #0 */
/* @0x1c0f20 ble 0x1c0fec <_ZN13CLayerManager19GetNewSpriteElementEv+0xec> */
/* @0x1c0f24 ldr r7, [pc, #0x104] */
/* @0x1c0f28 mov r5, r8 */
/* @0x1c0f2c mov r6, #0 */
/* @0x1c0f30 add r7, pc, r7 */
/* @0x1c0f34 mov r1, r7 */
/* @0x1c0f38 mov r2, #63 */
/* @0x1c0f3c mov r0, #72 */
/* @0x1c0f40 mov r3, #1 */
/* @0x1c0f44 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c0f48 mvn r2, #0 */
/* @0x1c0f4c mov r1, #4 */
/* @0x1c0f50 cmp r0, #0 */
/* @0x1c0f54 beq 0x1c0fa4 <_ZN13CLayerManager19GetNewSpriteElementEv+0xa4> */
/* @0x1c0f58 mov r3, #1065353216 */
/* @0x1c0f5c strb r5, [r0, #0x8] */
/* @0x1c0f60 str r5, [r0, #0xc] */
/* @0x1c0f64 str r6, [r0, #0x20] */
/* @0x1c0f68 str r5, [r0, #0x10] */
/* @0x1c0f6c str r6, [r0, #0x34] */
/* @0x1c0f70 str r5, [r0, #0x14] */
/* @0x1c0f74 str r6, [r0, #0x40] */
/* @0x1c0f78 str r5, [r0, #0x18] */
/* @0x1c0f7c str r6, [r0, #0x44] */
/* @0x1c0f80 str r2, [r0, #0x4] */
/* @0x1c0f84 str r2, [r0, #0x1c] */
/* @0x1c0f88 str r5, [r0, #0x28] */
/* @0x1c0f8c str r2, [r0, #0x38] */
/* @0x1c0f90 str r1, [r0] */
/* @0x1c0f94 str r3, [r0, #0x24] */
/* @0x1c0f98 str r3, [r0, #0x2c] */
/* @0x1c0f9c str r3, [r0, #0x30] */
/* @0x1c0fa0 str r3, [r0, #0x3c] */
/* @0x1c0fa4 ldr r3, [r4] */
/* @0x1c0fa8 add r8, r8, #1 */
/* @0x1c0fac ldr r2, [r4, #0x8] */
/* @0x1c0fb0 cmp r3, #0 */
/* @0x1c0fb4 streq r0, [r4, #0x4] */
/* @0x1c0fb8 strne r0, [r3, #0x18] */
/* @0x1c0fbc add r2, r2, #1 */
/* @0x1c0fc0 streq r3, [r0, #0x18] */
/* @0x1c0fc4 streq r3, [r0, #0x14] */
/* @0x1c0fc8 strne r3, [r0, #0x14] */
/* @0x1c0fcc ldr r3, [r4, #0x10] */
/* @0x1c0fd0 streq r0, [r4] */
/* @0x1c0fd4 strne r0, [r4] */
/* @0x1c0fd8 strne r5, [r0, #0x18] */
/* @0x1c0fdc cmp r8, r3 */
/* @0x1c0fe0 str r2, [r4, #0x8] */
/* @0x1c0fe4 blt 0x1c0f34 <_ZN13CLayerManager19GetNewSpriteElementEv+0x34> */
/* @0x1c0fe8 ldr r8, [r4, #0x8] */
/* @0x1c0fec lsl r3, r3, #1 */
/* @0x1c0ff0 str r3, [r4, #0x10] */
/* @0x1c0ff4 ldr r0, [r4] */
/* @0x1c0ff8 sub r8, r8, #1 */
/* @0x1c0ffc str r8, [r4, #0x8] */
/* @0x1c1000 ldr r3, [r0, #0x18] */
/* @0x1c1004 ldr r2, [r0, #0x14] */
/* @0x1c1008 cmp r3, #0 */
/* @0x1c100c strne r2, [r3, #0x14] */
/* @0x1c1010 ldrne r2, [r0, #0x14] */
/* @0x1c1014 ldrne r3, [r0, #0x18] */
/* @0x1c1018 streq r2, [r4] */
/* @0x1c101c cmp r2, #0 */
/* @0x1c1020 streq r3, [r4, #0x4] */
/* @0x1c1024 strne r3, [r2, #0x18] */
/* @0x1c1028 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c102c eoreq pc, r2, r4, ror #18 */
/* @0x1c1030 andseq r12, r8, r4, ror #14 */

/* ── FUNC 0x1c1034 · CLayerManager::GetNewTilemapElement() · size=296 · insn=74 */
/* @0x1c1034 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c1038 ldr r5, [pc, #0x114] */
/* @0x1c103c ldr r5, [pc, r5] */
/* @0x1c1040 ldr r6, [r5, #0x8] */
/* @0x1c1044 cmp r6, #0 */
/* @0x1c1048 bne 0x1c111c <_ZN13CLayerManager20GetNewTilemapElementEv+0xe8> */
/* @0x1c104c ldr r3, [r5, #0x10] */
/* @0x1c1050 cmp r3, #0 */
/* @0x1c1054 ble 0x1c1114 <_ZN13CLayerManager20GetNewTilemapElementEv+0xe0> */
/* @0x1c1058 ldr r8, [pc, #0xf8] */
/* @0x1c105c mov r4, r6 */
/* @0x1c1060 mov r7, #0 */
/* @0x1c1064 add r8, pc, r8 */
/* @0x1c1068 mov r1, r8 */
/* @0x1c106c mov r2, #63 */
/* @0x1c1070 mov r3, #1 */
/* @0x1c1074 mov r0, #60 */
/* @0x1c1078 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c107c mvn r3, #0 */
/* @0x1c1080 mvn r1, #-2147483648 */
/* @0x1c1084 mov r2, #5 */
/* @0x1c1088 cmp r0, #0 */
/* @0x1c108c beq 0x1c10cc <_ZN13CLayerManager20GetNewTilemapElementEv+0x98> */
/* @0x1c1090 strb r4, [r0, #0x8] */
/* @0x1c1094 str r7, [r0, #0x20] */
/* @0x1c1098 str r4, [r0, #0xc] */
/* @0x1c109c str r7, [r0, #0x24] */
/* @0x1c10a0 str r4, [r0, #0x10] */
/* @0x1c10a4 str r7, [r0, #0x30] */
/* @0x1c10a8 str r4, [r0, #0x14] */
/* @0x1c10ac str r4, [r0, #0x18] */
/* @0x1c10b0 str r3, [r0, #0x4] */
/* @0x1c10b4 str r3, [r0, #0x1c] */
/* @0x1c10b8 str r4, [r0, #0x28] */
/* @0x1c10bc str r4, [r0, #0x2c] */
/* @0x1c10c0 str r4, [r0, #0x34] */
/* @0x1c10c4 str r1, [r0, #0x38] */
/* @0x1c10c8 str r2, [r0] */
/* @0x1c10cc ldr r3, [r5] */
/* @0x1c10d0 add r6, r6, #1 */
/* @0x1c10d4 ldr r2, [r5, #0x8] */
/* @0x1c10d8 cmp r3, #0 */
/* @0x1c10dc streq r0, [r5, #0x4] */
/* @0x1c10e0 strne r0, [r3, #0x18] */
/* @0x1c10e4 add r2, r2, #1 */
/* @0x1c10e8 streq r3, [r0, #0x18] */
/* @0x1c10ec streq r3, [r0, #0x14] */
/* @0x1c10f0 strne r3, [r0, #0x14] */
/* @0x1c10f4 ldr r3, [r5, #0x10] */
/* @0x1c10f8 streq r0, [r5] */
/* @0x1c10fc strne r0, [r5] */
/* @0x1c1100 strne r4, [r0, #0x18] */
/* @0x1c1104 cmp r6, r3 */
/* @0x1c1108 str r2, [r5, #0x8] */
/* @0x1c110c blt 0x1c1068 <_ZN13CLayerManager20GetNewTilemapElementEv+0x34> */
/* @0x1c1110 ldr r6, [r5, #0x8] */
/* @0x1c1114 lsl r3, r3, #1 */
/* @0x1c1118 str r3, [r5, #0x10] */
/* @0x1c111c ldr r0, [r5] */
/* @0x1c1120 sub r6, r6, #1 */
/* @0x1c1124 str r6, [r5, #0x8] */
/* @0x1c1128 ldr r3, [r0, #0x18] */
/* @0x1c112c ldr r2, [r0, #0x14] */
/* @0x1c1130 cmp r3, #0 */
/* @0x1c1134 strne r2, [r3, #0x14] */
/* @0x1c1138 ldrne r2, [r0, #0x14] */
/* @0x1c113c ldrne r3, [r0, #0x18] */
/* @0x1c1140 streq r2, [r5] */
/* @0x1c1144 cmp r2, #0 */
/* @0x1c1148 streq r3, [r5, #0x4] */
/* @0x1c114c strne r3, [r2, #0x18] */
/* @0x1c1150 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c1154 eoreq pc, r2, r4, lsr r8 */
/* @0x1c1158 andseq r12, r8, r0, lsr r6 */

/* ── FUNC 0x1c115c · CLayerManager::GetNewParticleElement() · size=260 · insn=65 */
/* @0x1c115c push {r4, r5, r6, r7, r8, lr} */
/* @0x1c1160 ldr r4, [pc, #0xf0] */
/* @0x1c1164 ldr r4, [pc, r4] */
/* @0x1c1168 ldr r6, [r4, #0x8] */
/* @0x1c116c cmp r6, #0 */
/* @0x1c1170 bne 0x1c1220 <_ZN13CLayerManager21GetNewParticleElementEv+0xc4> */
/* @0x1c1174 ldr r3, [r4, #0x10] */
/* @0x1c1178 cmp r3, #0 */
/* @0x1c117c ble 0x1c1218 <_ZN13CLayerManager21GetNewParticleElementEv+0xbc> */
/* @0x1c1180 ldr r8, [pc, #0xd4] */
/* @0x1c1184 mov r5, r6 */
/* @0x1c1188 mvn r7, #0 */
/* @0x1c118c add r8, pc, r8 */
/* @0x1c1190 mov r3, #1 */
/* @0x1c1194 mov r0, #32 */
/* @0x1c1198 mov r1, r8 */
/* @0x1c119c mov r2, #63 */
/* @0x1c11a0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c11a4 mov r3, #6 */
/* @0x1c11a8 cmp r0, #0 */
/* @0x1c11ac beq 0x1c11d0 <_ZN13CLayerManager21GetNewParticleElementEv+0x74> */
/* @0x1c11b0 strb r5, [r0, #0x8] */
/* @0x1c11b4 str r5, [r0, #0xc] */
/* @0x1c11b8 str r5, [r0, #0x10] */
/* @0x1c11bc str r5, [r0, #0x14] */
/* @0x1c11c0 str r5, [r0, #0x18] */
/* @0x1c11c4 str r7, [r0, #0x4] */
/* @0x1c11c8 str r7, [r0, #0x1c] */
/* @0x1c11cc str r3, [r0] */
/* @0x1c11d0 ldr r3, [r4] */
/* @0x1c11d4 add r6, r6, #1 */
/* @0x1c11d8 ldr r2, [r4, #0x8] */
/* @0x1c11dc cmp r3, #0 */
/* @0x1c11e0 streq r0, [r4, #0x4] */
/* @0x1c11e4 strne r0, [r3, #0x18] */
/* @0x1c11e8 add r2, r2, #1 */
/* @0x1c11ec streq r3, [r0, #0x18] */
/* @0x1c11f0 streq r3, [r0, #0x14] */
/* @0x1c11f4 strne r3, [r0, #0x14] */
/* @0x1c11f8 ldr r3, [r4, #0x10] */
/* @0x1c11fc streq r0, [r4] */
/* @0x1c1200 strne r0, [r4] */
/* @0x1c1204 strne r5, [r0, #0x18] */
/* @0x1c1208 cmp r6, r3 */
/* @0x1c120c str r2, [r4, #0x8] */
/* @0x1c1210 blt 0x1c1190 <_ZN13CLayerManager21GetNewParticleElementEv+0x34> */
/* @0x1c1214 ldr r6, [r4, #0x8] */
/* @0x1c1218 lsl r3, r3, #1 */
/* @0x1c121c str r3, [r4, #0x10] */
/* @0x1c1220 ldr r0, [r4] */
/* @0x1c1224 sub r6, r6, #1 */
/* @0x1c1228 str r6, [r4, #0x8] */
/* @0x1c122c ldr r3, [r0, #0x18] */
/* @0x1c1230 ldr r2, [r0, #0x14] */
/* @0x1c1234 cmp r3, #0 */
/* @0x1c1238 strne r2, [r3, #0x14] */
/* @0x1c123c ldrne r2, [r0, #0x14] */
/* @0x1c1240 ldrne r3, [r0, #0x18] */
/* @0x1c1244 streq r2, [r4] */
/* @0x1c1248 cmp r2, #0 */
/* @0x1c124c streq r3, [r4, #0x4] */
/* @0x1c1250 strne r3, [r2, #0x18] */
/* @0x1c1254 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c1258 eoreq pc, r2, r0, lsl r7 */
/* @0x1c125c andseq r12, r8, r8, lsl #10 */

/* ── FUNC 0x1c1260 · CLayerManager::GetNewTileElement() · size=312 · insn=78 */
/* @0x1c1260 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c1264 ldr r5, [pc, #0x124] */
/* @0x1c1268 ldr r5, [pc, r5] */
/* @0x1c126c ldr r6, [r5, #0x8] */
/* @0x1c1270 cmp r6, #0 */
/* @0x1c1274 bne 0x1c1358 <_ZN13CLayerManager17GetNewTileElementEv+0xf8> */
/* @0x1c1278 ldr r3, [r5, #0x10] */
/* @0x1c127c cmp r3, #0 */
/* @0x1c1280 ble 0x1c1350 <_ZN13CLayerManager17GetNewTileElementEv+0xf0> */
/* @0x1c1284 ldr r7, [pc, #0x108] */
/* @0x1c1288 mov r4, r6 */
/* @0x1c128c mov r8, #0 */
/* @0x1c1290 add r7, pc, r7 */
/* @0x1c1294 mov r1, r7 */
/* @0x1c1298 mov r3, #1 */
/* @0x1c129c mov r0, #80 */
/* @0x1c12a0 mov r2, #63 */
/* @0x1c12a4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c12a8 mvn r3, #0 */
/* @0x1c12ac mov r1, #7 */
/* @0x1c12b0 cmp r0, #0 */
/* @0x1c12b4 beq 0x1c1308 <_ZN13CLayerManager17GetNewTileElementEv+0xa8> */
/* @0x1c12b8 mov r2, #1065353216 */
/* @0x1c12bc strb r4, [r0, #0x8] */
/* @0x1c12c0 str r4, [r0, #0xc] */
/* @0x1c12c4 str r8, [r0, #0x24] */
/* @0x1c12c8 str r4, [r0, #0x10] */
/* @0x1c12cc str r8, [r0, #0x28] */
/* @0x1c12d0 str r4, [r0, #0x14] */
/* @0x1c12d4 str r8, [r0, #0x3c] */
/* @0x1c12d8 str r4, [r0, #0x18] */
/* @0x1c12dc str r3, [r0, #0x4] */
/* @0x1c12e0 str r3, [r0, #0x20] */
/* @0x1c12e4 str r4, [r0, #0x2c] */
/* @0x1c12e8 str r4, [r0, #0x30] */
/* @0x1c12ec str r3, [r0, #0x40] */
/* @0x1c12f0 str r4, [r0, #0x48] */
/* @0x1c12f4 str r2, [r0, #0x34] */
/* @0x1c12f8 str r4, [r0, #0x4c] */
/* @0x1c12fc str r2, [r0, #0x38] */
/* @0x1c1300 str r1, [r0] */
/* @0x1c1304 str r2, [r0, #0x44] */
/* @0x1c1308 ldr r3, [r5] */
/* @0x1c130c add r6, r6, #1 */
/* @0x1c1310 ldr r2, [r5, #0x8] */
/* @0x1c1314 cmp r3, #0 */
/* @0x1c1318 streq r0, [r5, #0x4] */
/* @0x1c131c strne r0, [r3, #0x18] */
/* @0x1c1320 add r2, r2, #1 */
/* @0x1c1324 streq r3, [r0, #0x18] */
/* @0x1c1328 streq r3, [r0, #0x14] */
/* @0x1c132c strne r3, [r0, #0x14] */
/* @0x1c1330 ldr r3, [r5, #0x10] */
/* @0x1c1334 streq r0, [r5] */
/* @0x1c1338 strne r0, [r5] */
/* @0x1c133c strne r4, [r0, #0x18] */
/* @0x1c1340 cmp r6, r3 */
/* @0x1c1344 str r2, [r5, #0x8] */
/* @0x1c1348 blt 0x1c1294 <_ZN13CLayerManager17GetNewTileElementEv+0x34> */
/* @0x1c134c ldr r6, [r5, #0x8] */
/* @0x1c1350 lsl r3, r3, #1 */
/* @0x1c1354 str r3, [r5, #0x10] */
/* @0x1c1358 ldr r0, [r5] */
/* @0x1c135c sub r6, r6, #1 */
/* @0x1c1360 str r6, [r5, #0x8] */
/* @0x1c1364 ldr r3, [r0, #0x18] */
/* @0x1c1368 ldr r2, [r0, #0x14] */
/* @0x1c136c cmp r3, #0 */
/* @0x1c1370 strne r2, [r3, #0x14] */
/* @0x1c1374 ldrne r2, [r0, #0x14] */
/* @0x1c1378 ldrne r3, [r0, #0x18] */
/* @0x1c137c streq r2, [r5] */
/* @0x1c1380 cmp r2, #0 */
/* @0x1c1384 streq r3, [r5, #0x4] */
/* @0x1c1388 strne r3, [r2, #0x18] */
/* @0x1c138c pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c1390 eoreq pc, r2, r0, lsl r6 */
/* @0x1c1394 andseq r12, r8, r4, lsl #8 */

/* ── FUNC 0x1c1398 · F_LayerRemoveInstance(RValue&, CInstance*, CInstance*, int, RValue*) · size=424 · insn=106 */
/* @0x1c1398 push {r3, r4, r5, r6, r7, lr} */
/* @0x1c139c cmp r3, #2 */
/* @0x1c13a0 ldr r5, [pc, #0x174] */
/* @0x1c13a4 mov r3, #0 */
/* @0x1c13a8 mov r4, r3 */
/* @0x1c13ac ldr r6, [sp, #0x18] */
/* @0x1c13b0 movt r3, #0xbff0 */
/* @0x1c13b4 add r5, pc, r5 */
/* @0x1c13b8 str r4, [r0, #0xc] */
/* @0x1c13bc str r3, [r0, #0x4] */
/* @0x1c13c0 str r4, [r0] */
/* @0x1c13c4 beq 0x1c13dc <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1c13c8 ldr r0, [pc, #0x150] */
/* @0x1c13cc mov r1, r4 */
/* @0x1c13d0 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1c13d4 add r0, pc, r0 */
/* @0x1c13d8 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c13dc bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1c13e0 ldr r3, [r6, #0xc] */
/* @0x1c13e4 mov r1, r4 */
/* @0x1c13e8 bic r3, r3, #-16777216 */
/* @0x1c13ec cmp r3, #1 */
/* @0x1c13f0 mov r7, r0 */
/* @0x1c13f4 mov r0, r6 */
/* @0x1c13f8 beq 0x1c14b4 <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x1c13fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c1400 mov r1, r0 */
/* @0x1c1404 mov r0, r7 */
/* @0x1c1408 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c140c mov r4, r0 */
/* @0x1c1410 cmp r4, #0 */
/* @0x1c1414 beq 0x1c14f4 <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x1c1418 mov r0, r6 */
/* @0x1c141c mov r1, #1 */
/* @0x1c1420 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c1424 cmp r0, #0 */
/* @0x1c1428 blt 0x1c1508 <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x1c142c ldr r3, [pc, #0xf0] */
/* @0x1c1430 ldr r3, [r5, r3] */
/* @0x1c1434 ldr r2, [r3, #0x4] */
/* @0x1c1438 ldr r3, [r3] */
/* @0x1c143c and r2, r0, r2 */
/* @0x1c1440 ldr r3, [r3, r2, lsl #3] */
/* @0x1c1444 cmp r3, #0 */
/* @0x1c1448 bne 0x1c145c <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x1c144c b 0x1c1508 <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x1c1450 ldr r3, [r3, #0x4] */
/* @0x1c1454 cmp r3, #0 */
/* @0x1c1458 beq 0x1c1508 <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x1c145c ldr r2, [r3, #0x8] */
/* @0x1c1460 cmp r0, r2 */
/* @0x1c1464 bne 0x1c1450 <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x1c1468 ldr r2, [r3, #0xc] */
/* @0x1c146c cmp r2, #0 */
/* @0x1c1470 beq 0x1c1508 <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x1c1474 ldrb r3, [r2, #0x174] */
/* @0x1c1478 cmp r3, #0 */
/* @0x1c147c beq 0x1c14e4 <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x1c1480 ldr r1, [r2, #0x170] */
/* @0x1c1484 ldr r3, [r4] */
/* @0x1c1488 cmp r1, r3 */
/* @0x1c148c beq 0x1c14cc <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1c1490 ldr r1, [pc, #0x90] */
/* @0x1c1494 ldr r3, [pc, #0x90] */
/* @0x1c1498 add r1, pc, r1 */
/* @0x1c149c ldr r3, [r5, r3] */
/* @0x1c14a0 ldr r0, [r3] */
/* @0x1c14a4 ldr r3, [r0] */
/* @0x1c14a8 ldr r3, [r3, #0xc] */
/* @0x1c14ac blx r3 */
/* @0x1c14b0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c14b4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1c14b8 mov r1, r0 */
/* @0x1c14bc mov r0, r7 */
/* @0x1c14c0 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1c14c4 mov r4, r0 */
/* @0x1c14c8 b 0x1c1410 <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1c14cc ldr r3, [pc, #0x5c] */
/* @0x1c14d0 mov r1, r4 */
/* @0x1c14d4 ldr r3, [r5, r3] */
/* @0x1c14d8 ldr r0, [r3] */
/* @0x1c14dc pop {r3, r4, r5, r6, r7, lr} */
/* @0x1c14e0 b 0x1b991c <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance> */
/* @0x1c14e4 ldr r1, [pc, #0x48] */
/* @0x1c14e8 ldr r3, [pc, #0x3c] */
/* @0x1c14ec add r1, pc, r1 */
/* @0x1c14f0 b 0x1c149c <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x1c14f4 ldr r0, [pc, #0x3c] */
/* @0x1c14f8 mov r1, r4 */
/* @0x1c14fc pop {r3, r4, r5, r6, r7, lr} */
/* @0x1c1500 add r0, pc, r0 */
/* @0x1c1504 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c1508 ldr r0, [pc, #0x2c] */
/* @0x1c150c mov r1, #0 */
/* @0x1c1510 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1c1514 add r0, pc, r0 */
/* @0x1c1518 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c151c mlaeq r3, r12, r8, r0 */
/* @0x1c1520 mulseq r8, r4, r6 */
/* @0x1c1524 .word 0xffffbff4 */
/* @0x1c1528 andseq lr, r8, r4, asr #13 */
/* @0x1c152c .word 0xffffbac4 */
/* @0x1c1530 .word 0xffffbcd8 */
/* @0x1c1534 andseq lr, r8, r8, lsr r6 */
/* @0x1c1538 mulseq r8, r12, r5 */
/* @0x1c153c ldrsbeq lr, [r8], -r4 */

/* ── FUNC 0x1c1540 · CLayerManager::InitLayerFunctions() · size=5456 · insn=1364 */
/* @0x1c1540 push {r4, r5, r6, lr} */
/* @0x1c1544 mov r2, #1 */
/* @0x1c1548 ldr r4, [pc, #0xff8] */
/* @0x1c154c mov r3, r2 */
/* @0x1c1550 ldr r1, [pc, #0xff4] */
/* @0x1c1554 add r4, pc, r4 */
/* @0x1c1558 ldr r0, [pc, #0xff0] */
/* @0x1c155c ldr r1, [r4, r1] */
/* @0x1c1560 add r0, pc, r0 */
/* @0x1c1564 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1568 ldr r1, [pc, #0xfe4] */
/* @0x1c156c ldr r0, [pc, #0xfe4] */
/* @0x1c1570 mov r2, #1 */
/* @0x1c1574 mov r3, r2 */
/* @0x1c1578 ldr r1, [r4, r1] */
/* @0x1c157c add r0, pc, r0 */
/* @0x1c1580 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1584 ldr r1, [pc, #0xfd0] */
/* @0x1c1588 ldr r0, [pc, #0xfd0] */
/* @0x1c158c mov r2, #1 */
/* @0x1c1590 mov r3, r2 */
/* @0x1c1594 ldr r1, [r4, r1] */
/* @0x1c1598 add r0, pc, r0 */
/* @0x1c159c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c15a0 ldr r1, [pc, #0xfbc] */
/* @0x1c15a4 ldr r0, [pc, #0xfbc] */
/* @0x1c15a8 mov r2, #2 */
/* @0x1c15ac mov r3, #1 */
/* @0x1c15b0 ldr r1, [r4, r1] */
/* @0x1c15b4 add r0, pc, r0 */
/* @0x1c15b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c15bc ldr r1, [pc, #0xfa8] */
/* @0x1c15c0 ldr r0, [pc, #0xfa8] */
/* @0x1c15c4 mov r2, #1 */
/* @0x1c15c8 mov r3, r2 */
/* @0x1c15cc ldr r1, [r4, r1] */
/* @0x1c15d0 add r0, pc, r0 */
/* @0x1c15d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c15d8 ldr r1, [pc, #0xf94] */
/* @0x1c15dc ldr r0, [pc, #0xf94] */
/* @0x1c15e0 mov r2, #1 */
/* @0x1c15e4 mov r3, r2 */
/* @0x1c15e8 ldr r1, [r4, r1] */
/* @0x1c15ec add r0, pc, r0 */
/* @0x1c15f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c15f4 ldr r1, [pc, #0xf80] */
/* @0x1c15f8 ldr r0, [pc, #0xf80] */
/* @0x1c15fc mov r2, #2 */
/* @0x1c1600 mov r3, #1 */
/* @0x1c1604 ldr r1, [r4, r1] */
/* @0x1c1608 add r0, pc, r0 */
/* @0x1c160c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1610 ldr r1, [pc, #0xf6c] */
/* @0x1c1614 ldr r0, [pc, #0xf6c] */
/* @0x1c1618 mov r2, #2 */
/* @0x1c161c mov r3, #1 */
/* @0x1c1620 ldr r1, [r4, r1] */
/* @0x1c1624 add r0, pc, r0 */
/* @0x1c1628 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c162c ldr r1, [pc, #0xf58] */
/* @0x1c1630 ldr r0, [pc, #0xf58] */
/* @0x1c1634 mov r2, #2 */
/* @0x1c1638 mov r3, #1 */
/* @0x1c163c ldr r1, [r4, r1] */
/* @0x1c1640 add r0, pc, r0 */
/* @0x1c1644 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1648 ldr r1, [pc, #0xf44] */
/* @0x1c164c ldr r0, [pc, #0xf44] */
/* @0x1c1650 mov r2, #1 */
/* @0x1c1654 mov r3, r2 */
/* @0x1c1658 ldr r1, [r4, r1] */
/* @0x1c165c add r0, pc, r0 */
/* @0x1c1660 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1664 ldr r1, [pc, #0xf30] */
/* @0x1c1668 ldr r0, [pc, #0xf30] */
/* @0x1c166c mov r2, #1 */
/* @0x1c1670 mov r3, r2 */
/* @0x1c1674 ldr r1, [r4, r1] */
/* @0x1c1678 add r0, pc, r0 */
/* @0x1c167c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1680 ldr r1, [pc, #0xf1c] */
/* @0x1c1684 ldr r0, [pc, #0xf1c] */
/* @0x1c1688 mov r2, #2 */
/* @0x1c168c mov r3, #1 */
/* @0x1c1690 ldr r1, [r4, r1] */
/* @0x1c1694 add r0, pc, r0 */
/* @0x1c1698 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c169c ldr r1, [pc, #0xf08] */
/* @0x1c16a0 ldr r0, [pc, #0xf08] */
/* @0x1c16a4 mov r2, #2 */
/* @0x1c16a8 mov r3, #1 */
/* @0x1c16ac ldr r1, [r4, r1] */
/* @0x1c16b0 add r0, pc, r0 */
/* @0x1c16b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c16b8 ldr r1, [pc, #0xef4] */
/* @0x1c16bc ldr r0, [pc, #0xef4] */
/* @0x1c16c0 mov r2, #1 */
/* @0x1c16c4 mov r3, r2 */
/* @0x1c16c8 ldr r1, [r4, r1] */
/* @0x1c16cc add r0, pc, r0 */
/* @0x1c16d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c16d4 ldr r1, [pc, #0xee0] */
/* @0x1c16d8 ldr r0, [pc, #0xee0] */
/* @0x1c16dc mov r2, #1 */
/* @0x1c16e0 mov r3, r2 */
/* @0x1c16e4 ldr r1, [r4, r1] */
/* @0x1c16e8 add r0, pc, r0 */
/* @0x1c16ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c16f0 ldr r1, [pc, #0xecc] */
/* @0x1c16f4 ldr r0, [pc, #0xecc] */
/* @0x1c16f8 mov r2, #2 */
/* @0x1c16fc mov r3, #1 */
/* @0x1c1700 ldr r1, [r4, r1] */
/* @0x1c1704 add r0, pc, r0 */
/* @0x1c1708 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c170c ldr r1, [pc, #0xeb8] */
/* @0x1c1710 ldr r0, [pc, #0xeb8] */
/* @0x1c1714 mov r2, #2 */
/* @0x1c1718 mov r3, #1 */
/* @0x1c171c ldr r1, [r4, r1] */
/* @0x1c1720 add r0, pc, r0 */
/* @0x1c1724 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1728 ldr r1, [pc, #0xea4] */
/* @0x1c172c ldr r0, [pc, #0xea4] */
/* @0x1c1730 mov r2, #1 */
/* @0x1c1734 mov r3, r2 */
/* @0x1c1738 ldr r1, [r4, r1] */
/* @0x1c173c add r0, pc, r0 */
/* @0x1c1740 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1744 ldr r1, [pc, #0xe90] */
/* @0x1c1748 ldr r0, [pc, #0xe90] */
/* @0x1c174c mov r2, #1 */
/* @0x1c1750 mov r3, r2 */
/* @0x1c1754 ldr r1, [r4, r1] */
/* @0x1c1758 add r0, pc, r0 */
/* @0x1c175c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1760 ldr r1, [pc, #0xe7c] */
/* @0x1c1764 ldr r0, [pc, #0xe7c] */
/* @0x1c1768 mov r2, #2 */
/* @0x1c176c mov r3, #1 */
/* @0x1c1770 ldr r1, [r4, r1] */
/* @0x1c1774 add r0, pc, r0 */
/* @0x1c1778 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c177c ldr r1, [pc, #0xe68] */
/* @0x1c1780 ldr r0, [pc, #0xe68] */
/* @0x1c1784 mov r2, #2 */
/* @0x1c1788 mov r3, #1 */
/* @0x1c178c ldr r1, [r4, r1] */
/* @0x1c1790 add r0, pc, r0 */
/* @0x1c1794 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1798 ldr r1, [pc, #0xe54] */
/* @0x1c179c ldr r0, [pc, #0xe54] */
/* @0x1c17a0 mov r2, #2 */
/* @0x1c17a4 mov r3, #1 */
/* @0x1c17a8 ldr r1, [r4, r1] */
/* @0x1c17ac add r0, pc, r0 */
/* @0x1c17b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c17b4 ldr r1, [pc, #0xe40] */
/* @0x1c17b8 ldr r0, [pc, #0xe40] */
/* @0x1c17bc mov r2, #1 */
/* @0x1c17c0 mov r3, r2 */
/* @0x1c17c4 ldr r1, [r4, r1] */
/* @0x1c17c8 add r0, pc, r0 */
/* @0x1c17cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c17d0 ldr r1, [pc, #0xe2c] */
/* @0x1c17d4 ldr r0, [pc, #0xe2c] */
/* @0x1c17d8 mov r2, #1 */
/* @0x1c17dc mov r3, r2 */
/* @0x1c17e0 ldr r1, [r4, r1] */
/* @0x1c17e4 add r0, pc, r0 */
/* @0x1c17e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c17ec ldr r1, [pc, #0xe18] */
/* @0x1c17f0 ldr r0, [pc, #0xe18] */
/* @0x1c17f4 mov r2, #1 */
/* @0x1c17f8 mov r3, r2 */
/* @0x1c17fc ldr r1, [r4, r1] */
/* @0x1c1800 add r0, pc, r0 */
/* @0x1c1804 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1808 ldr r1, [pc, #0xe04] */
/* @0x1c180c ldr r0, [pc, #0xe04] */
/* @0x1c1810 mov r2, #1 */
/* @0x1c1814 mov r3, r2 */
/* @0x1c1818 ldr r1, [r4, r1] */
/* @0x1c181c add r0, pc, r0 */
/* @0x1c1820 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1824 ldr r1, [pc, #0xdf0] */
/* @0x1c1828 ldr r0, [pc, #0xdf0] */
/* @0x1c182c mov r2, #0 */
/* @0x1c1830 mov r3, #1 */
/* @0x1c1834 ldr r1, [r4, r1] */
/* @0x1c1838 add r0, pc, r0 */
/* @0x1c183c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1840 ldr r1, [pc, #0xddc] */
/* @0x1c1844 ldr r0, [pc, #0xddc] */
/* @0x1c1848 mov r2, #0 */
/* @0x1c184c mov r3, #1 */
/* @0x1c1850 ldr r1, [r4, r1] */
/* @0x1c1854 add r0, pc, r0 */
/* @0x1c1858 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c185c ldr r1, [pc, #0xdc8] */
/* @0x1c1860 ldr r0, [pc, #0xdc8] */
/* @0x1c1864 mov r2, #0 */
/* @0x1c1868 mov r3, #1 */
/* @0x1c186c ldr r1, [r4, r1] */
/* @0x1c1870 add r0, pc, r0 */
/* @0x1c1874 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1878 ldr r1, [pc, #0xdb4] */
/* @0x1c187c ldr r0, [pc, #0xdb4] */
/* @0x1c1880 mov r2, #1 */
/* @0x1c1884 mov r3, r2 */
/* @0x1c1888 ldr r1, [r4, r1] */
/* @0x1c188c add r0, pc, r0 */
/* @0x1c1890 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1894 ldr r1, [pc, #0xda0] */
/* @0x1c1898 ldr r0, [pc, #0xda0] */
/* @0x1c189c mov r2, #1 */
/* @0x1c18a0 mov r3, r2 */
/* @0x1c18a4 ldr r1, [r4, r1] */
/* @0x1c18a8 add r0, pc, r0 */
/* @0x1c18ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c18b0 ldr r1, [pc, #0xd8c] */
/* @0x1c18b4 ldr r0, [pc, #0xd8c] */
/* @0x1c18b8 mov r2, #2 */
/* @0x1c18bc mov r3, #1 */
/* @0x1c18c0 ldr r1, [r4, r1] */
/* @0x1c18c4 add r0, pc, r0 */
/* @0x1c18c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c18cc ldr r1, [pc, #0xd78] */
/* @0x1c18d0 ldr r0, [pc, #0xd78] */
/* @0x1c18d4 mov r2, #1 */
/* @0x1c18d8 mov r3, r2 */
/* @0x1c18dc ldr r1, [r4, r1] */
/* @0x1c18e0 add r0, pc, r0 */
/* @0x1c18e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c18e8 ldr r1, [pc, #0xd64] */
/* @0x1c18ec ldr r0, [pc, #0xd64] */
/* @0x1c18f0 mov r2, #1 */
/* @0x1c18f4 mov r3, r2 */
/* @0x1c18f8 ldr r1, [r4, r1] */
/* @0x1c18fc add r0, pc, r0 */
/* @0x1c1900 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1904 ldr r1, [pc, #0xd50] */
/* @0x1c1908 ldr r0, [pc, #0xd50] */
/* @0x1c190c mov r2, #2 */
/* @0x1c1910 mov r3, #1 */
/* @0x1c1914 ldr r1, [r4, r1] */
/* @0x1c1918 add r0, pc, r0 */
/* @0x1c191c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1920 ldr r1, [pc, #0xd3c] */
/* @0x1c1924 ldr r0, [pc, #0xd3c] */
/* @0x1c1928 mov r2, #2 */
/* @0x1c192c mov r3, #1 */
/* @0x1c1930 ldr r1, [r4, r1] */
/* @0x1c1934 add r0, pc, r0 */
/* @0x1c1938 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c193c ldr r1, [pc, #0xd28] */
/* @0x1c1940 ldr r0, [pc, #0xd28] */
/* @0x1c1944 mov r2, #0 */
/* @0x1c1948 mov r3, #1 */
/* @0x1c194c ldr r1, [r4, r1] */
/* @0x1c1950 add r0, pc, r0 */
/* @0x1c1954 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1958 ldr r1, [pc, #0xd14] */
/* @0x1c195c ldr r0, [pc, #0xd14] */
/* @0x1c1960 mov r2, #0 */
/* @0x1c1964 mov r3, #1 */
/* @0x1c1968 ldr r1, [r4, r1] */
/* @0x1c196c add r0, pc, r0 */
/* @0x1c1970 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1974 ldr r1, [pc, #0xd00] */
/* @0x1c1978 ldr r0, [pc, #0xd00] */
/* @0x1c197c mov r2, #1 */
/* @0x1c1980 mov r3, r2 */
/* @0x1c1984 ldr r1, [r4, r1] */
/* @0x1c1988 add r0, pc, r0 */
/* @0x1c198c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1990 ldr r1, [pc, #0xcec] */
/* @0x1c1994 ldr r0, [pc, #0xcec] */
/* @0x1c1998 mov r2, #2 */
/* @0x1c199c mov r3, #1 */
/* @0x1c19a0 ldr r1, [r4, r1] */
/* @0x1c19a4 add r0, pc, r0 */
/* @0x1c19a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c19ac ldr r1, [pc, #0xcd8] */
/* @0x1c19b0 ldr r0, [pc, #0xcd8] */
/* @0x1c19b4 mov r2, #2 */
/* @0x1c19b8 mov r3, #1 */
/* @0x1c19bc ldr r1, [r4, r1] */
/* @0x1c19c0 add r0, pc, r0 */
/* @0x1c19c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c19c8 ldr r1, [pc, #0xcc4] */
/* @0x1c19cc ldr r0, [pc, #0xcc4] */
/* @0x1c19d0 mov r2, #1 */
/* @0x1c19d4 mov r3, r2 */
/* @0x1c19d8 ldr r1, [r4, r1] */
/* @0x1c19dc add r0, pc, r0 */
/* @0x1c19e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c19e4 ldr r1, [pc, #0xcb0] */
/* @0x1c19e8 ldr r0, [pc, #0xcb0] */
/* @0x1c19ec mov r2, #2 */
/* @0x1c19f0 mov r3, #1 */
/* @0x1c19f4 ldr r1, [r4, r1] */
/* @0x1c19f8 add r0, pc, r0 */
/* @0x1c19fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1a00 ldr r1, [pc, #0xc9c] */
/* @0x1c1a04 ldr r0, [pc, #0xc9c] */
/* @0x1c1a08 mov r2, #2 */
/* @0x1c1a0c mov r3, #1 */
/* @0x1c1a10 ldr r1, [r4, r1] */
/* @0x1c1a14 add r0, pc, r0 */
/* @0x1c1a18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1a1c ldr r1, [pc, #0xc88] */
/* @0x1c1a20 ldr r0, [pc, #0xc88] */
/* @0x1c1a24 mov r2, #2 */
/* @0x1c1a28 mov r3, #1 */
/* @0x1c1a2c ldr r1, [r4, r1] */
/* @0x1c1a30 add r0, pc, r0 */
/* @0x1c1a34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1a38 ldr r1, [pc, #0xc74] */
/* @0x1c1a3c ldr r0, [pc, #0xc74] */
/* @0x1c1a40 mov r2, #2 */
/* @0x1c1a44 mov r3, #1 */
/* @0x1c1a48 ldr r1, [r4, r1] */
/* @0x1c1a4c add r0, pc, r0 */
/* @0x1c1a50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1a54 ldr r1, [pc, #0xc60] */
/* @0x1c1a58 ldr r0, [pc, #0xc60] */
/* @0x1c1a5c mov r2, #2 */
/* @0x1c1a60 mov r3, #1 */
/* @0x1c1a64 ldr r1, [r4, r1] */
/* @0x1c1a68 add r0, pc, r0 */
/* @0x1c1a6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1a70 ldr r1, [pc, #0xc4c] */
/* @0x1c1a74 ldr r0, [pc, #0xc4c] */
/* @0x1c1a78 mov r2, #2 */
/* @0x1c1a7c mov r3, #1 */
/* @0x1c1a80 ldr r1, [r4, r1] */
/* @0x1c1a84 add r0, pc, r0 */
/* @0x1c1a88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1a8c ldr r1, [pc, #0xc38] */
/* @0x1c1a90 ldr r0, [pc, #0xc38] */
/* @0x1c1a94 mov r2, #2 */
/* @0x1c1a98 mov r3, #1 */
/* @0x1c1a9c ldr r1, [r4, r1] */
/* @0x1c1aa0 add r0, pc, r0 */
/* @0x1c1aa4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1aa8 ldr r1, [pc, #0xc24] */
/* @0x1c1aac ldr r0, [pc, #0xc24] */
/* @0x1c1ab0 mov r2, #2 */
/* @0x1c1ab4 mov r3, #1 */
/* @0x1c1ab8 ldr r1, [r4, r1] */
/* @0x1c1abc add r0, pc, r0 */
/* @0x1c1ac0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1ac4 ldr r1, [pc, #0xc10] */
/* @0x1c1ac8 ldr r0, [pc, #0xc10] */
/* @0x1c1acc mov r2, #2 */
/* @0x1c1ad0 mov r3, #1 */
/* @0x1c1ad4 ldr r1, [r4, r1] */
/* @0x1c1ad8 add r0, pc, r0 */
/* @0x1c1adc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1ae0 ldr r1, [pc, #0xbfc] */
/* @0x1c1ae4 ldr r0, [pc, #0xbfc] */
/* @0x1c1ae8 mov r2, #2 */
/* @0x1c1aec mov r3, #1 */
/* @0x1c1af0 ldr r1, [r4, r1] */
/* @0x1c1af4 add r0, pc, r0 */
/* @0x1c1af8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1afc ldr r1, [pc, #0xbe8] */
/* @0x1c1b00 ldr r0, [pc, #0xbe8] */
/* @0x1c1b04 mov r2, #2 */
/* @0x1c1b08 mov r3, #1 */
/* @0x1c1b0c ldr r5, [r4, r1] */
/* @0x1c1b10 add r0, pc, r0 */
/* @0x1c1b14 mov r1, r5 */
/* @0x1c1b18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1b1c ldr r0, [pc, #0xbd0] */
/* @0x1c1b20 mov r1, r5 */
/* @0x1c1b24 mov r2, #2 */
/* @0x1c1b28 add r0, pc, r0 */
/* @0x1c1b2c mov r3, #1 */
/* @0x1c1b30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1b34 ldr r1, [pc, #0xbbc] */
/* @0x1c1b38 ldr r0, [pc, #0xbbc] */
/* @0x1c1b3c mov r2, #1 */
/* @0x1c1b40 mov r3, r2 */
/* @0x1c1b44 ldr r1, [r4, r1] */
/* @0x1c1b48 add r0, pc, r0 */
/* @0x1c1b4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1b50 ldr r1, [pc, #0xba8] */
/* @0x1c1b54 ldr r0, [pc, #0xba8] */
/* @0x1c1b58 mov r2, #1 */
/* @0x1c1b5c mov r3, r2 */
/* @0x1c1b60 ldr r1, [r4, r1] */
/* @0x1c1b64 add r0, pc, r0 */
/* @0x1c1b68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1b6c ldr r1, [pc, #0xb94] */
/* @0x1c1b70 ldr r0, [pc, #0xb94] */
/* @0x1c1b74 mov r2, #1 */
/* @0x1c1b78 mov r3, r2 */
/* @0x1c1b7c ldr r1, [r4, r1] */
/* @0x1c1b80 add r0, pc, r0 */
/* @0x1c1b84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1b88 ldr r1, [pc, #0xb80] */
/* @0x1c1b8c ldr r0, [pc, #0xb80] */
/* @0x1c1b90 mov r2, #1 */
/* @0x1c1b94 mov r3, r2 */
/* @0x1c1b98 ldr r1, [r4, r1] */
/* @0x1c1b9c add r0, pc, r0 */
/* @0x1c1ba0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1ba4 ldr r1, [pc, #0xb6c] */
/* @0x1c1ba8 ldr r0, [pc, #0xb6c] */
/* @0x1c1bac mov r2, #1 */
/* @0x1c1bb0 mov r3, r2 */
/* @0x1c1bb4 ldr r1, [r4, r1] */
/* @0x1c1bb8 add r0, pc, r0 */
/* @0x1c1bbc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1bc0 ldr r1, [pc, #0xb58] */
/* @0x1c1bc4 ldr r0, [pc, #0xb58] */
/* @0x1c1bc8 mov r2, #1 */
/* @0x1c1bcc mov r3, r2 */
/* @0x1c1bd0 ldr r1, [r4, r1] */
/* @0x1c1bd4 add r0, pc, r0 */
/* @0x1c1bd8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1bdc ldr r1, [pc, #0xb44] */
/* @0x1c1be0 ldr r0, [pc, #0xb44] */
/* @0x1c1be4 mov r2, #1 */
/* @0x1c1be8 mov r3, r2 */
/* @0x1c1bec ldr r1, [r4, r1] */
/* @0x1c1bf0 add r0, pc, r0 */
/* @0x1c1bf4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1bf8 ldr r1, [pc, #0xb30] */
/* @0x1c1bfc ldr r0, [pc, #0xb30] */
/* @0x1c1c00 mov r2, #1 */
/* @0x1c1c04 mov r3, r2 */
/* @0x1c1c08 ldr r1, [r4, r1] */
/* @0x1c1c0c add r0, pc, r0 */
/* @0x1c1c10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1c14 ldr r1, [pc, #0xb1c] */
/* @0x1c1c18 ldr r0, [pc, #0xb1c] */
/* @0x1c1c1c mov r2, #1 */
/* @0x1c1c20 mov r3, r2 */
/* @0x1c1c24 ldr r1, [r4, r1] */
/* @0x1c1c28 add r0, pc, r0 */
/* @0x1c1c2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1c30 ldr r1, [pc, #0xb08] */
/* @0x1c1c34 ldr r0, [pc, #0xb08] */
/* @0x1c1c38 mov r2, #1 */
/* @0x1c1c3c mov r3, r2 */
/* @0x1c1c40 ldr r1, [r4, r1] */
/* @0x1c1c44 add r0, pc, r0 */
/* @0x1c1c48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1c4c ldr r1, [pc, #0xaf4] */
/* @0x1c1c50 ldr r0, [pc, #0xaf4] */
/* @0x1c1c54 mov r2, #1 */
/* @0x1c1c58 mov r3, r2 */
/* @0x1c1c5c ldr r1, [r4, r1] */
/* @0x1c1c60 add r0, pc, r0 */
/* @0x1c1c64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1c68 ldr r1, [pc, #0xae0] */
/* @0x1c1c6c ldr r0, [pc, #0xae0] */
/* @0x1c1c70 mov r2, #2 */
/* @0x1c1c74 mov r3, #1 */
/* @0x1c1c78 ldr r1, [r4, r1] */
/* @0x1c1c7c add r0, pc, r0 */
/* @0x1c1c80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1c84 ldr r1, [pc, #0xacc] */
/* @0x1c1c88 ldr r0, [pc, #0xacc] */
/* @0x1c1c8c mov r2, #2 */
/* @0x1c1c90 mov r3, #1 */
/* @0x1c1c94 ldr r1, [r4, r1] */
/* @0x1c1c98 add r0, pc, r0 */
/* @0x1c1c9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1ca0 ldr r1, [pc, #0xab8] */
/* @0x1c1ca4 ldr r0, [pc, #0xab8] */
/* @0x1c1ca8 mov r2, #4 */
/* @0x1c1cac mov r3, #1 */
/* @0x1c1cb0 ldr r1, [r4, r1] */
/* @0x1c1cb4 add r0, pc, r0 */
/* @0x1c1cb8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1cbc ldr r1, [pc, #0xaa4] */
/* @0x1c1cc0 ldr r0, [pc, #0xaa4] */
/* @0x1c1cc4 mov r2, #1 */
/* @0x1c1cc8 mov r3, r2 */
/* @0x1c1ccc ldr r1, [r4, r1] */
/* @0x1c1cd0 add r0, pc, r0 */
/* @0x1c1cd4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1cd8 ldr r1, [pc, #0xa90] */
/* @0x1c1cdc ldr r0, [pc, #0xa90] */
/* @0x1c1ce0 mov r2, #2 */
/* @0x1c1ce4 mov r3, #1 */
/* @0x1c1ce8 ldr r1, [r4, r1] */
/* @0x1c1cec add r0, pc, r0 */
/* @0x1c1cf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1cf4 ldr r1, [pc, #0xa7c] */
/* @0x1c1cf8 ldr r0, [pc, #0xa7c] */
/* @0x1c1cfc mov r2, #2 */
/* @0x1c1d00 mov r3, #1 */
/* @0x1c1d04 ldr r1, [r4, r1] */
/* @0x1c1d08 add r0, pc, r0 */
/* @0x1c1d0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1d10 ldr r1, [pc, #0xa68] */
/* @0x1c1d14 ldr r0, [pc, #0xa68] */
/* @0x1c1d18 mov r2, #2 */
/* @0x1c1d1c mov r3, #1 */
/* @0x1c1d20 ldr r1, [r4, r1] */
/* @0x1c1d24 add r0, pc, r0 */
/* @0x1c1d28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1d2c ldr r1, [pc, #0xa54] */
/* @0x1c1d30 ldr r0, [pc, #0xa54] */
/* @0x1c1d34 mov r2, #2 */
/* @0x1c1d38 mov r3, #1 */
/* @0x1c1d3c ldr r1, [r4, r1] */
/* @0x1c1d40 add r0, pc, r0 */
/* @0x1c1d44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1d48 ldr r1, [pc, #0xa40] */
/* @0x1c1d4c ldr r0, [pc, #0xa40] */
/* @0x1c1d50 mov r2, #2 */
/* @0x1c1d54 mov r3, #1 */
/* @0x1c1d58 ldr r1, [r4, r1] */
/* @0x1c1d5c add r0, pc, r0 */
/* @0x1c1d60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1d64 ldr r1, [pc, #0xa2c] */
/* @0x1c1d68 ldr r0, [pc, #0xa2c] */
/* @0x1c1d6c mov r2, #2 */
/* @0x1c1d70 mov r3, #1 */
/* @0x1c1d74 ldr r1, [r4, r1] */
/* @0x1c1d78 add r0, pc, r0 */
/* @0x1c1d7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1d80 ldr r1, [pc, #0xa18] */
/* @0x1c1d84 ldr r0, [pc, #0xa18] */
/* @0x1c1d88 mov r2, #2 */
/* @0x1c1d8c mov r3, #1 */
/* @0x1c1d90 ldr r1, [r4, r1] */
/* @0x1c1d94 add r0, pc, r0 */
/* @0x1c1d98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1d9c ldr r1, [pc, #0xa04] */
/* @0x1c1da0 ldr r0, [pc, #0xa04] */
/* @0x1c1da4 mov r2, #2 */
/* @0x1c1da8 mov r3, #1 */
/* @0x1c1dac ldr r1, [r4, r1] */
/* @0x1c1db0 add r0, pc, r0 */
/* @0x1c1db4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1db8 ldr r1, [pc, #0x9f0] */
/* @0x1c1dbc ldr r0, [pc, #0x9f0] */
/* @0x1c1dc0 mov r2, #2 */
/* @0x1c1dc4 mov r3, #1 */
/* @0x1c1dc8 ldr r1, [r4, r1] */
/* @0x1c1dcc add r0, pc, r0 */
/* @0x1c1dd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1dd4 ldr r1, [pc, #0x9dc] */
/* @0x1c1dd8 ldr r0, [pc, #0x9dc] */
/* @0x1c1ddc mov r2, #2 */
/* @0x1c1de0 mov r3, #1 */
/* @0x1c1de4 ldr r1, [r4, r1] */
/* @0x1c1de8 add r0, pc, r0 */
/* @0x1c1dec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1df0 ldr r1, [pc, #0x9c8] */
/* @0x1c1df4 ldr r0, [pc, #0x9c8] */
/* @0x1c1df8 mov r2, #1 */
/* @0x1c1dfc mov r3, r2 */
/* @0x1c1e00 ldr r1, [r4, r1] */
/* @0x1c1e04 add r0, pc, r0 */
/* @0x1c1e08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1e0c ldr r1, [pc, #0x9b4] */
/* @0x1c1e10 ldr r0, [pc, #0x9b4] */
/* @0x1c1e14 mov r2, #1 */
/* @0x1c1e18 mov r3, r2 */
/* @0x1c1e1c ldr r1, [r4, r1] */
/* @0x1c1e20 add r0, pc, r0 */
/* @0x1c1e24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1e28 ldr r1, [pc, #0x9a0] */
/* @0x1c1e2c ldr r0, [pc, #0x9a0] */
/* @0x1c1e30 mov r2, #1 */
/* @0x1c1e34 mov r3, r2 */
/* @0x1c1e38 ldr r1, [r4, r1] */
/* @0x1c1e3c add r0, pc, r0 */
/* @0x1c1e40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1e44 ldr r1, [pc, #0x98c] */
/* @0x1c1e48 ldr r0, [pc, #0x98c] */
/* @0x1c1e4c mov r2, #1 */
/* @0x1c1e50 mov r3, r2 */
/* @0x1c1e54 ldr r1, [r4, r1] */
/* @0x1c1e58 add r0, pc, r0 */
/* @0x1c1e5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1e60 ldr r1, [pc, #0x978] */
/* @0x1c1e64 ldr r0, [pc, #0x978] */
/* @0x1c1e68 mov r2, #1 */
/* @0x1c1e6c mov r3, r2 */
/* @0x1c1e70 ldr r1, [r4, r1] */
/* @0x1c1e74 add r0, pc, r0 */
/* @0x1c1e78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1e7c ldr r1, [pc, #0x964] */
/* @0x1c1e80 ldr r0, [pc, #0x964] */
/* @0x1c1e84 mov r2, #1 */
/* @0x1c1e88 mov r3, r2 */
/* @0x1c1e8c ldr r1, [r4, r1] */
/* @0x1c1e90 add r0, pc, r0 */
/* @0x1c1e94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1e98 ldr r1, [pc, #0x950] */
/* @0x1c1e9c ldr r0, [pc, #0x950] */
/* @0x1c1ea0 mov r2, #1 */
/* @0x1c1ea4 mov r3, r2 */
/* @0x1c1ea8 ldr r1, [r4, r1] */
/* @0x1c1eac add r0, pc, r0 */
/* @0x1c1eb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1eb4 ldr r1, [pc, #0x93c] */
/* @0x1c1eb8 ldr r0, [pc, #0x93c] */
/* @0x1c1ebc mov r2, #1 */
/* @0x1c1ec0 mov r3, r2 */
/* @0x1c1ec4 ldr r1, [r4, r1] */
/* @0x1c1ec8 add r0, pc, r0 */
/* @0x1c1ecc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1ed0 ldr r1, [pc, #0x928] */
/* @0x1c1ed4 ldr r0, [pc, #0x928] */
/* @0x1c1ed8 mov r2, #1 */
/* @0x1c1edc mov r3, r2 */
/* @0x1c1ee0 ldr r1, [r4, r1] */
/* @0x1c1ee4 add r0, pc, r0 */
/* @0x1c1ee8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1eec ldr r1, [pc, #0x914] */
/* @0x1c1ef0 ldr r0, [pc, #0x914] */
/* @0x1c1ef4 mov r2, #1 */
/* @0x1c1ef8 mov r3, r2 */
/* @0x1c1efc ldr r1, [r4, r1] */
/* @0x1c1f00 add r0, pc, r0 */
/* @0x1c1f04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1f08 ldr r1, [pc, #0x900] */
/* @0x1c1f0c ldr r0, [pc, #0x900] */
/* @0x1c1f10 mov r2, #1 */
/* @0x1c1f14 mov r3, r2 */
/* @0x1c1f18 ldr r1, [r4, r1] */
/* @0x1c1f1c add r0, pc, r0 */
/* @0x1c1f20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1f24 ldr r1, [pc, #0x8ec] */
/* @0x1c1f28 ldr r0, [pc, #0x8ec] */
/* @0x1c1f2c mov r2, #1 */
/* @0x1c1f30 mov r3, r2 */
/* @0x1c1f34 ldr r1, [r4, r1] */
/* @0x1c1f38 add r0, pc, r0 */
/* @0x1c1f3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1f40 ldr r1, [pc, #0x8d8] */
/* @0x1c1f44 ldr r0, [pc, #0x8d8] */
/* @0x1c1f48 mov r2, #1 */
/* @0x1c1f4c mov r3, r2 */
/* @0x1c1f50 ldr r1, [r4, r1] */
/* @0x1c1f54 add r0, pc, r0 */
/* @0x1c1f58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1f5c ldr r1, [pc, #0x8c4] */
/* @0x1c1f60 ldr r0, [pc, #0x8c4] */
/* @0x1c1f64 mov r2, #2 */
/* @0x1c1f68 mov r3, #1 */
/* @0x1c1f6c ldr r1, [r4, r1] */
/* @0x1c1f70 add r0, pc, r0 */
/* @0x1c1f74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1f78 ldr r1, [pc, #0x8b0] */
/* @0x1c1f7c ldr r0, [pc, #0x8b0] */
/* @0x1c1f80 mov r2, #6 */
/* @0x1c1f84 mov r3, #1 */
/* @0x1c1f88 ldr r1, [r4, r1] */
/* @0x1c1f8c add r0, pc, r0 */
/* @0x1c1f90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1f94 ldr r1, [pc, #0x89c] */
/* @0x1c1f98 ldr r0, [pc, #0x89c] */
/* @0x1c1f9c mov r2, #1 */
/* @0x1c1fa0 mov r3, r2 */
/* @0x1c1fa4 ldr r1, [r4, r1] */
/* @0x1c1fa8 add r0, pc, r0 */
/* @0x1c1fac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1fb0 ldr r1, [pc, #0x888] */
/* @0x1c1fb4 ldr r0, [pc, #0x888] */
/* @0x1c1fb8 mov r2, #2 */
/* @0x1c1fbc mov r3, #1 */
/* @0x1c1fc0 ldr r1, [r4, r1] */
/* @0x1c1fc4 add r0, pc, r0 */
/* @0x1c1fc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1fcc ldr r1, [pc, #0x874] */
/* @0x1c1fd0 ldr r0, [pc, #0x874] */
/* @0x1c1fd4 mov r2, #2 */
/* @0x1c1fd8 mov r3, #1 */
/* @0x1c1fdc ldr r1, [r4, r1] */
/* @0x1c1fe0 add r0, pc, r0 */
/* @0x1c1fe4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1fe8 ldr r1, [pc, #0x860] */
/* @0x1c1fec ldr r0, [pc, #0x860] */
/* @0x1c1ff0 mov r2, #2 */
/* @0x1c1ff4 mov r3, #1 */
/* @0x1c1ff8 ldr r1, [r4, r1] */
/* @0x1c1ffc add r0, pc, r0 */
/* @0x1c2000 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2004 ldr r1, [pc, #0x84c] */
/* @0x1c2008 ldr r0, [pc, #0x84c] */
/* @0x1c200c mov r2, #4 */
/* @0x1c2010 mov r3, #1 */
/* @0x1c2014 ldr r1, [r4, r1] */
/* @0x1c2018 add r0, pc, r0 */
/* @0x1c201c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2020 ldr r1, [pc, #0x838] */
/* @0x1c2024 ldr r0, [pc, #0x838] */
/* @0x1c2028 mov r2, #4 */
/* @0x1c202c mov r3, #1 */
/* @0x1c2030 ldr r1, [r4, r1] */
/* @0x1c2034 add r0, pc, r0 */
/* @0x1c2038 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c203c ldr r1, [pc, #0x824] */
/* @0x1c2040 ldr r0, [pc, #0x824] */
/* @0x1c2044 mov r2, #1 */
/* @0x1c2048 mov r3, r2 */
/* @0x1c204c ldr r1, [r4, r1] */
/* @0x1c2050 add r0, pc, r0 */
/* @0x1c2054 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2058 ldr r1, [pc, #0x810] */
/* @0x1c205c ldr r0, [pc, #0x810] */
/* @0x1c2060 mov r2, #1 */
/* @0x1c2064 mov r3, r2 */
/* @0x1c2068 ldr r1, [r4, r1] */
/* @0x1c206c add r0, pc, r0 */
/* @0x1c2070 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2074 ldr r1, [pc, #0x7fc] */
/* @0x1c2078 ldr r0, [pc, #0x7fc] */
/* @0x1c207c mov r2, #1 */
/* @0x1c2080 mov r3, r2 */
/* @0x1c2084 ldr r1, [r4, r1] */
/* @0x1c2088 add r0, pc, r0 */
/* @0x1c208c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2090 ldr r1, [pc, #0x7e8] */
/* @0x1c2094 ldr r0, [pc, #0x7e8] */
/* @0x1c2098 mov r2, #1 */
/* @0x1c209c mov r3, r2 */
/* @0x1c20a0 ldr r1, [r4, r1] */
/* @0x1c20a4 add r0, pc, r0 */
/* @0x1c20a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c20ac ldr r1, [pc, #0x7d4] */
/* @0x1c20b0 ldr r0, [pc, #0x7d4] */
/* @0x1c20b4 mov r2, #1 */
/* @0x1c20b8 mov r3, r2 */
/* @0x1c20bc ldr r1, [r4, r1] */
/* @0x1c20c0 add r0, pc, r0 */
/* @0x1c20c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c20c8 ldr r1, [pc, #0x7c0] */
/* @0x1c20cc ldr r0, [pc, #0x7c0] */
/* @0x1c20d0 mov r2, #1 */
/* @0x1c20d4 mov r3, r2 */
/* @0x1c20d8 ldr r1, [r4, r1] */
/* @0x1c20dc add r0, pc, r0 */
/* @0x1c20e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c20e4 ldr r1, [pc, #0x7ac] */
/* @0x1c20e8 ldr r0, [pc, #0x7ac] */
/* @0x1c20ec mov r2, #1 */
/* @0x1c20f0 mov r3, r2 */
/* @0x1c20f4 ldr r1, [r4, r1] */
/* @0x1c20f8 add r0, pc, r0 */
/* @0x1c20fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2100 ldr r1, [pc, #0x798] */
/* @0x1c2104 ldr r0, [pc, #0x798] */
/* @0x1c2108 mov r2, #3 */
/* @0x1c210c mov r3, #1 */
/* @0x1c2110 ldr r1, [r4, r1] */
/* @0x1c2114 add r0, pc, r0 */
/* @0x1c2118 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c211c ldr r1, [pc, #0x784] */
/* @0x1c2120 ldr r0, [pc, #0x784] */
/* @0x1c2124 mov r2, #3 */
/* @0x1c2128 mov r3, #1 */
/* @0x1c212c ldr r1, [r4, r1] */
/* @0x1c2130 add r0, pc, r0 */
/* @0x1c2134 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2138 ldr r1, [pc, #0x770] */
/* @0x1c213c ldr r0, [pc, #0x770] */
/* @0x1c2140 mov r2, #3 */
/* @0x1c2144 mov r3, #1 */
/* @0x1c2148 ldr r1, [r4, r1] */
/* @0x1c214c add r0, pc, r0 */
/* @0x1c2150 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2154 ldr r1, [pc, #0x75c] */
/* @0x1c2158 ldr r0, [pc, #0x75c] */
/* @0x1c215c mov r2, #3 */
/* @0x1c2160 mov r3, #1 */
/* @0x1c2164 ldr r1, [r4, r1] */
/* @0x1c2168 add r0, pc, r0 */
/* @0x1c216c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2170 ldr r1, [pc, #0x748] */
/* @0x1c2174 ldr r0, [pc, #0x748] */
/* @0x1c2178 mov r2, #2 */
/* @0x1c217c mov r3, #1 */
/* @0x1c2180 ldr r1, [r4, r1] */
/* @0x1c2184 add r0, pc, r0 */
/* @0x1c2188 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c218c ldr r1, [pc, #0x734] */
/* @0x1c2190 ldr r0, [pc, #0x734] */
/* @0x1c2194 mov r2, #3 */
/* @0x1c2198 mov r3, #1 */
/* @0x1c219c ldr r1, [r4, r1] */
/* @0x1c21a0 add r0, pc, r0 */
/* @0x1c21a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c21a8 ldr r1, [pc, #0x720] */
/* @0x1c21ac ldr r0, [pc, #0x720] */
/* @0x1c21b0 mov r2, #5 */
/* @0x1c21b4 mov r3, #1 */
/* @0x1c21b8 ldr r1, [r4, r1] */
/* @0x1c21bc add r0, pc, r0 */
/* @0x1c21c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c21c4 ldr r1, [pc, #0x70c] */
/* @0x1c21c8 ldr r0, [pc, #0x70c] */
/* @0x1c21cc mov r2, #1 */
/* @0x1c21d0 mov r3, r2 */
/* @0x1c21d4 ldr r1, [r4, r1] */
/* @0x1c21d8 add r0, pc, r0 */
/* @0x1c21dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c21e0 ldr r1, [pc, #0x6f8] */
/* @0x1c21e4 ldr r0, [pc, #0x6f8] */
/* @0x1c21e8 mov r2, #0 */
/* @0x1c21ec mov r3, #1 */
/* @0x1c21f0 ldr r1, [r4, r1] */
/* @0x1c21f4 add r0, pc, r0 */
/* @0x1c21f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c21fc ldr r1, [pc, #0x6e4] */
/* @0x1c2200 ldr r0, [pc, #0x6e4] */
/* @0x1c2204 mov r2, #2 */
/* @0x1c2208 mov r3, #1 */
/* @0x1c220c ldr r1, [r4, r1] */
/* @0x1c2210 add r0, pc, r0 */
/* @0x1c2214 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2218 ldr r1, [pc, #0x6d0] */
/* @0x1c221c ldr r0, [pc, #0x6d0] */
/* @0x1c2220 mov r2, #1 */
/* @0x1c2224 mov r3, r2 */
/* @0x1c2228 ldr r1, [r4, r1] */
/* @0x1c222c add r0, pc, r0 */
/* @0x1c2230 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2234 ldr r1, [pc, #0x6bc] */
/* @0x1c2238 ldr r0, [pc, #0x6bc] */
/* @0x1c223c mov r2, #1 */
/* @0x1c2240 mov r3, r2 */
/* @0x1c2244 ldr r1, [r4, r1] */
/* @0x1c2248 add r0, pc, r0 */
/* @0x1c224c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2250 ldr r1, [pc, #0x6a8] */
/* @0x1c2254 ldr r0, [pc, #0x6a8] */
/* @0x1c2258 mov r2, #1 */
/* @0x1c225c mov r3, r2 */
/* @0x1c2260 ldr r1, [r4, r1] */
/* @0x1c2264 add r0, pc, r0 */
/* @0x1c2268 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c226c ldr r1, [pc, #0x694] */
/* @0x1c2270 ldr r0, [pc, #0x694] */
/* @0x1c2274 mov r2, #2 */
/* @0x1c2278 mov r3, #1 */
/* @0x1c227c ldr r1, [r4, r1] */
/* @0x1c2280 add r0, pc, r0 */
/* @0x1c2284 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2288 ldr r1, [pc, #0x680] */
/* @0x1c228c ldr r0, [pc, #0x680] */
/* @0x1c2290 mov r2, #2 */
/* @0x1c2294 mov r3, #1 */
/* @0x1c2298 ldr r1, [r4, r1] */
/* @0x1c229c add r0, pc, r0 */
/* @0x1c22a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c22a4 ldr r1, [pc, #0x66c] */
/* @0x1c22a8 ldr r0, [pc, #0x66c] */
/* @0x1c22ac mov r2, #2 */
/* @0x1c22b0 mov r3, #1 */
/* @0x1c22b4 ldr r1, [r4, r1] */
/* @0x1c22b8 add r0, pc, r0 */
/* @0x1c22bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c22c0 ldr r1, [pc, #0x658] */
/* @0x1c22c4 ldr r0, [pc, #0x658] */
/* @0x1c22c8 mov r2, #2 */
/* @0x1c22cc mov r3, #1 */
/* @0x1c22d0 ldr r1, [r4, r1] */
/* @0x1c22d4 add r0, pc, r0 */
/* @0x1c22d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c22dc ldr r1, [pc, #0x644] */
/* @0x1c22e0 ldr r0, [pc, #0x644] */
/* @0x1c22e4 mov r2, #1 */
/* @0x1c22e8 mov r3, r2 */
/* @0x1c22ec ldr r1, [r4, r1] */
/* @0x1c22f0 add r0, pc, r0 */
/* @0x1c22f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c22f8 ldr r1, [pc, #0x630] */
/* @0x1c22fc ldr r0, [pc, #0x630] */
/* @0x1c2300 mov r2, #1 */
/* @0x1c2304 mov r3, r2 */
/* @0x1c2308 ldr r1, [r4, r1] */
/* @0x1c230c add r0, pc, r0 */
/* @0x1c2310 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2314 ldr r1, [pc, #0x61c] */
/* @0x1c2318 ldr r0, [pc, #0x61c] */
/* @0x1c231c mov r2, #1 */
/* @0x1c2320 mov r3, r2 */
/* @0x1c2324 ldr r1, [r4, r1] */
/* @0x1c2328 add r0, pc, r0 */
/* @0x1c232c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2330 ldr r1, [pc, #0x608] */
/* @0x1c2334 ldr r0, [pc, #0x608] */
/* @0x1c2338 mov r2, #1 */
/* @0x1c233c mov r3, r2 */
/* @0x1c2340 ldr r1, [r4, r1] */
/* @0x1c2344 add r0, pc, r0 */
/* @0x1c2348 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c234c ldr r1, [pc, #0x5f4] */
/* @0x1c2350 ldr r0, [pc, #0x5f4] */
/* @0x1c2354 mov r2, #1 */
/* @0x1c2358 mov r3, r2 */
/* @0x1c235c ldr r1, [r4, r1] */
/* @0x1c2360 add r0, pc, r0 */
/* @0x1c2364 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2368 ldr r1, [pc, #0x5e0] */
/* @0x1c236c ldr r0, [pc, #0x5e0] */
/* @0x1c2370 mov r2, #2 */
/* @0x1c2374 mov r3, #1 */
/* @0x1c2378 ldr r1, [r4, r1] */
/* @0x1c237c add r0, pc, r0 */
/* @0x1c2380 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2384 ldr r1, [pc, #0x5cc] */
/* @0x1c2388 ldr r0, [pc, #0x5cc] */
/* @0x1c238c mov r2, #8 */
/* @0x1c2390 mov r3, #1 */
/* @0x1c2394 ldr r1, [r4, r1] */
/* @0x1c2398 add r0, pc, r0 */
/* @0x1c239c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c23a0 ldr r1, [pc, #0x5b8] */
/* @0x1c23a4 ldr r0, [pc, #0x5b8] */
/* @0x1c23a8 mov r2, #1 */
/* @0x1c23ac mov r3, r2 */
/* @0x1c23b0 ldr r1, [r4, r1] */
/* @0x1c23b4 add r0, pc, r0 */
/* @0x1c23b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c23bc ldr r1, [pc, #0x5a4] */
/* @0x1c23c0 ldr r0, [pc, #0x5a4] */
/* @0x1c23c4 mov r2, #2 */
/* @0x1c23c8 mov r3, #1 */
/* @0x1c23cc ldr r1, [r4, r1] */
/* @0x1c23d0 add r0, pc, r0 */
/* @0x1c23d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c23d8 ldr r1, [pc, #0x590] */
/* @0x1c23dc ldr r0, [pc, #0x590] */
/* @0x1c23e0 mov r2, #2 */
/* @0x1c23e4 mov r3, #1 */
/* @0x1c23e8 ldr r1, [r4, r1] */
/* @0x1c23ec add r0, pc, r0 */
/* @0x1c23f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c23f4 ldr r1, [pc, #0x57c] */
/* @0x1c23f8 ldr r0, [pc, #0x57c] */
/* @0x1c23fc mov r2, #2 */
/* @0x1c2400 mov r3, #1 */
/* @0x1c2404 ldr r1, [r4, r1] */
/* @0x1c2408 add r0, pc, r0 */
/* @0x1c240c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2410 ldr r1, [pc, #0x568] */
/* @0x1c2414 ldr r0, [pc, #0x568] */
/* @0x1c2418 mov r2, #2 */
/* @0x1c241c mov r3, #1 */
/* @0x1c2420 ldr r1, [r4, r1] */
/* @0x1c2424 add r0, pc, r0 */
/* @0x1c2428 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c242c ldr r1, [pc, #0x554] */
/* @0x1c2430 ldr r0, [pc, #0x554] */
/* @0x1c2434 mov r2, #2 */
/* @0x1c2438 mov r3, #1 */
/* @0x1c243c ldr r1, [r4, r1] */
/* @0x1c2440 add r0, pc, r0 */
/* @0x1c2444 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2448 ldr r1, [pc, #0x540] */
/* @0x1c244c ldr r0, [pc, #0x540] */
/* @0x1c2450 mov r2, #2 */
/* @0x1c2454 mov r3, #1 */
/* @0x1c2458 ldr r1, [r4, r1] */
/* @0x1c245c add r0, pc, r0 */
/* @0x1c2460 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2464 ldr r1, [pc, #0x52c] */
/* @0x1c2468 ldr r0, [pc, #0x52c] */
/* @0x1c246c mov r2, #2 */
/* @0x1c2470 mov r3, #1 */
/* @0x1c2474 ldr r1, [r4, r1] */
/* @0x1c2478 add r0, pc, r0 */
/* @0x1c247c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2480 ldr r1, [pc, #0x518] */
/* @0x1c2484 ldr r0, [pc, #0x518] */
/* @0x1c2488 mov r2, #5 */
/* @0x1c248c mov r3, #1 */
/* @0x1c2490 ldr r1, [r4, r1] */
/* @0x1c2494 add r0, pc, r0 */
/* @0x1c2498 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c249c ldr r1, [pc, #0x504] */
/* @0x1c24a0 ldr r0, [pc, #0x504] */
/* @0x1c24a4 mov r2, #2 */
/* @0x1c24a8 mov r3, #1 */
/* @0x1c24ac ldr r1, [r4, r1] */
/* @0x1c24b0 add r0, pc, r0 */
/* @0x1c24b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c24b8 ldr r1, [pc, #0x4f0] */
/* @0x1c24bc ldr r0, [pc, #0x4f0] */
/* @0x1c24c0 mov r2, #1 */
/* @0x1c24c4 mov r3, r2 */
/* @0x1c24c8 ldr r1, [r4, r1] */
/* @0x1c24cc add r0, pc, r0 */
/* @0x1c24d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c24d4 ldr r1, [pc, #0x4dc] */
/* @0x1c24d8 ldr r0, [pc, #0x4dc] */
/* @0x1c24dc mov r2, #1 */
/* @0x1c24e0 mov r3, r2 */
/* @0x1c24e4 ldr r1, [r4, r1] */
/* @0x1c24e8 add r0, pc, r0 */
/* @0x1c24ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c24f0 ldr r1, [pc, #0x4c8] */
/* @0x1c24f4 ldr r0, [pc, #0x4c8] */
/* @0x1c24f8 mov r2, #1 */
/* @0x1c24fc mov r3, r2 */
/* @0x1c2500 ldr r1, [r4, r1] */
/* @0x1c2504 add r0, pc, r0 */
/* @0x1c2508 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c250c ldr r1, [pc, #0x4b4] */
/* @0x1c2510 ldr r0, [pc, #0x4b4] */
/* @0x1c2514 mov r2, #1 */
/* @0x1c2518 mov r3, r2 */
/* @0x1c251c ldr r1, [r4, r1] */
/* @0x1c2520 add r0, pc, r0 */
/* @0x1c2524 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2528 ldr r1, [pc, #0x4a0] */
/* @0x1c252c ldr r0, [pc, #0x4a0] */
/* @0x1c2530 mov r2, #1 */
/* @0x1c2534 mov r3, r2 */
/* @0x1c2538 ldr r1, [r4, r1] */
/* @0x1c253c add r0, pc, r0 */
/* @0x1c2540 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2544 b 0x1c2a00 <_ZN13CLayerManager18InitLayerFunctionsEv+0x14c0> */
/* @0x1c2548 .word 0x002306fc */
/* @0x1c254c .word 0xffffec34 */
/* @0x1c2550 andseq lr, r8, r8, lsr r6 */
/* @0x1c2554 .word 0xffffec38 */
/* @0x1c2558 andseq lr, r8, r12, lsr #12 */
/* @0x1c255c .word 0xffffec3c */
/* @0x1c2560 andseq lr, r8, r8, lsr #12 */
/* @0x1c2564 .word 0xffffec40 */
/* @0x1c2568 andseq lr, r8, r12, lsl r6 */
/* @0x1c256c .word 0xffffec44 */
/* @0x1c2570 andseq lr, r8, r0, lsl r6 */
/* @0x1c2574 .word 0xffffec48 */
/* @0x1c2578 andseq lr, r8, r4, lsl #12 */
/* @0x1c257c .word 0xffffec4c */
/* @0x1c2580 andseq lr, r8, r0, lsl #12 */
/* @0x1c2584 .word 0xffffec50 */
/* @0x1c2588 ldrsheq lr, [r8], -r8 */
/* @0x1c258c .word 0xffffec54 */
/* @0x1c2590 ldrsheq lr, [r8], -r0 */
/* @0x1c2594 .word 0xffffec58 */
/* @0x1c2598 andseq lr, r8, r8, ror #11 */
/* @0x1c259c .word 0xffffec5c */
/* @0x1c25a0 andseq lr, r8, r0, ror #11 */
/* @0x1c25a4 .word 0xffffec60 */
/* @0x1c25a8 ldrsbeq lr, [r8], -r4 */
/* @0x1c25ac .word 0xffffec64 */
/* @0x1c25b0 andseq lr, r8, r0, asr #11 */
/* @0x1c25b4 .word 0xffffec68 */
/* @0x1c25b8 andseq lr, r8, r12, lsr #11 */
/* @0x1c25bc .word 0xffffec6c */
/* @0x1c25c0 mulseq r8, r12, r5 */
/* @0x1c25c4 .word 0xffffec70 */
/* @0x1c25c8 andseq lr, r8, r12, lsl #11 */
/* @0x1c25cc .word 0xffffec74 */
/* @0x1c25d0 andseq lr, r8, r0, lsl #11 */
/* @0x1c25d4 .word 0xffffec78 */
/* @0x1c25d8 andseq lr, r8, r4, ror r5 */
/* @0x1c25dc .word 0xffffec7c */
/* @0x1c25e0 andseq lr, r8, r12, ror #10 */
/* @0x1c25e4 .word 0xffffec80 */
/* @0x1c25e8 andseq lr, r8, r4, ror #10 */
/* @0x1c25ec .word 0xffffec84 */
/* @0x1c25f0 andseq lr, r8, r12, asr r5 */
/* @0x1c25f4 .word 0xffffec88 */
/* @0x1c25f8 andseq lr, r8, r4, asr r5 */
/* @0x1c25fc .word 0xffffec8c */
/* @0x1c2600 andseq lr, r8, r8, asr #10 */
/* @0x1c2604 .word 0xffffec90 */
/* @0x1c2608 andseq lr, r8, r4, asr #10 */
/* @0x1c260c .word 0xffffec94 */
/* @0x1c2610 andseq lr, r8, r0, asr #10 */
/* @0x1c2614 .word 0xffffec98 */
/* @0x1c2618 andseq lr, r8, r8, lsr r5 */
/* @0x1c261c .word 0xffffec9c */
/* @0x1c2620 andseq lr, r8, r4, lsr r5 */
/* @0x1c2624 .word 0xffffeca0 */
/* @0x1c2628 andseq lr, r8, r0, lsr r5 */
/* @0x1c262c .word 0xffffeca4 */
/* @0x1c2630 andseq lr, r8, r12, lsr #10 */
/* @0x1c2634 .word 0xffffeca8 */
/* @0x1c2638 andseq lr, r8, r0, lsr #10 */
/* @0x1c263c .word 0xffffecac */
/* @0x1c2640 andseq lr, r8, r12, lsl r5 */
/* @0x1c2644 .word 0xffffecb0 */
/* @0x1c2648 andseq lr, r8, r0, lsl r5 */
/* @0x1c264c .word 0xffffecb4 */
/* @0x1c2650 andseq lr, r8, r0, lsl #10 */
/* @0x1c2654 .word 0xffffecb8 */
/* @0x1c2658 ldrsheq lr, [r8], -r12 */
/* @0x1c265c .word 0xffffecbc */
/* @0x1c2660 ldrsheq lr, [r8], -r8 */
/* @0x1c2664 .word 0xffffecc0 */
/* @0x1c2668 ldrsheq lr, [r8], -r0 */
/* @0x1c266c .word 0xffffecc4 */
/* @0x1c2670 andseq lr, r8, r12, ror #9 */
/* @0x1c2674 .word 0xffffecc8 */
/* @0x1c2678 andseq lr, r8, r12, ror #9 */
/* @0x1c267c .word 0xffffeccc */
/* @0x1c2680 andseq lr, r8, r8, ror #9 */
/* @0x1c2684 .word 0xffffecd0 */
/* @0x1c2688 andseq lr, r8, r4, ror #9 */
/* @0x1c268c .word 0xffffecd4 */
/* @0x1c2690 andseq lr, r8, r0, ror #9 */
/* @0x1c2694 .word 0xffffecd8 */
/* @0x1c2698 ldrsbeq lr, [r8], -r12 */
/* @0x1c269c .word 0xffffecdc */
/* @0x1c26a0 ldrsbeq lr, [r8], -r12 */
/* @0x1c26a4 .word 0xffffece0 */
/* @0x1c26a8 ldrsbeq lr, [r8], -r12 */
/* @0x1c26ac .word 0xffffece4 */
/* @0x1c26b0 ldrsbeq lr, [r8], -r8 */
/* @0x1c26b4 .word 0xffffece8 */
/* @0x1c26b8 ldrsbeq lr, [r8], -r4 */
/* @0x1c26bc .word 0xffffecec */
/* @0x1c26c0 ldrsbeq lr, [r8], -r0 */
/* @0x1c26c4 .word 0xffffecf0 */
/* @0x1c26c8 andseq lr, r8, r12, asr #9 */
/* @0x1c26cc .word 0xffffecf4 */
/* @0x1c26d0 andseq lr, r8, r12, asr #9 */
/* @0x1c26d4 .word 0xffffecf8 */
/* @0x1c26d8 andseq lr, r8, r8, asr #9 */
/* @0x1c26dc .word 0xffffecfc */
/* @0x1c26e0 andseq lr, r8, r4, asr #9 */
/* @0x1c26e4 .word 0xffffed00 */
/* @0x1c26e8 andseq lr, r8, r0, asr #9 */
/* @0x1c26ec .word 0xffffed04 */
/* @0x1c26f0 ldrheq lr, [r8], -r12 */
/* @0x1c26f4 ldrheq lr, [r8], -r12 */
/* @0x1c26f8 .word 0xffffed08 */
/* @0x1c26fc ldrheq lr, [r8], -r4 */
/* @0x1c2700 .word 0xffffed0c */
/* @0x1c2704 ldrheq lr, [r8], -r8 */
/* @0x1c2708 .word 0xffffed10 */
/* @0x1c270c ldrheq lr, [r8], -r8 */
/* @0x1c2710 .word 0xffffed14 */
/* @0x1c2714 ldrheq lr, [r8], -r8 */
/* @0x1c2718 .word 0xffffed18 */
/* @0x1c271c ldrheq lr, [r8], -r8 */
/* @0x1c2720 .word 0xffffed1c */
/* @0x1c2724 ldrheq lr, [r8], -r8 */
/* @0x1c2728 .word 0xffffed20 */
/* @0x1c272c ldrheq lr, [r8], -r8 */
/* @0x1c2730 .word 0xffffed24 */
/* @0x1c2734 ldrheq lr, [r8], -r12 */
/* @0x1c2738 .word 0xffffed28 */
/* @0x1c273c ldrheq lr, [r8], -r12 */
/* @0x1c2740 .word 0xffffed2c */
/* @0x1c2744 ldrheq lr, [r8], -r12 */
/* @0x1c2748 .word 0xffffed30 */
/* @0x1c274c ldrheq lr, [r8], -r12 */
/* @0x1c2750 .word 0xffffed34 */
/* @0x1c2754 ldrheq lr, [r8], -r12 */
/* @0x1c2758 .word 0xffffed38 */
/* @0x1c275c ldrheq lr, [r8], -r4 */
/* @0x1c2760 .word 0xffffed3c */
/* @0x1c2764 andseq lr, r8, r12, lsr #9 */
/* @0x1c2768 .word 0xffffed40 */
/* @0x1c276c andseq lr, r8, r4, lsr #9 */
/* @0x1c2770 .word 0xffffed44 */
/* @0x1c2774 andseq lr, r8, r0, lsr #9 */
/* @0x1c2778 .word 0xffffed48 */
/* @0x1c277c mulseq r8, r8, r4 */
/* @0x1c2780 .word 0xffffed4c */
/* @0x1c2784 mulseq r8, r0, r4 */
/* @0x1c2788 .word 0xffffed50 */
/* @0x1c278c andseq lr, r8, r8, lsl #9 */
/* @0x1c2790 .word 0xffffed54 */
/* @0x1c2794 andseq lr, r8, r0, lsl #9 */
/* @0x1c2798 .word 0xffffed58 */
/* @0x1c279c andseq lr, r8, r8, ror r4 */
/* @0x1c27a0 .word 0xffffed5c */
/* @0x1c27a4 andseq lr, r8, r0, ror r4 */
/* @0x1c27a8 .word 0xffffed60 */
/* @0x1c27ac andseq lr, r8, r8, ror #8 */
/* @0x1c27b0 .word 0xffffed64 */
/* @0x1c27b4 andseq lr, r8, r0, ror #8 */
/* @0x1c27b8 .word 0xffffed68 */
/* @0x1c27bc andseq lr, r8, r4, asr r4 */
/* @0x1c27c0 .word 0xffffed6c */
/* @0x1c27c4 andseq lr, r8, r8, asr #8 */
/* @0x1c27c8 .word 0xffffed70 */
/* @0x1c27cc andseq lr, r8, r4, asr #8 */
/* @0x1c27d0 .word 0xffffed74 */
/* @0x1c27d4 andseq lr, r8, r0, asr #8 */
/* @0x1c27d8 .word 0xffffed78 */
/* @0x1c27dc andseq lr, r8, r12, lsr r4 */
/* @0x1c27e0 .word 0xffffed7c */
/* @0x1c27e4 andseq lr, r8, r8, lsr r4 */
/* @0x1c27e8 .word 0xffffed80 */
/* @0x1c27ec andseq lr, r8, r4, lsr r4 */
/* @0x1c27f0 .word 0xffffed84 */
/* @0x1c27f4 andseq lr, r8, r0, lsr r4 */
/* @0x1c27f8 .word 0xffffed88 */
/* @0x1c27fc andseq lr, r8, r12, lsr #8 */
/* @0x1c2800 .word 0xffffed8c */
/* @0x1c2804 andseq lr, r8, r8, lsr #8 */
/* @0x1c2808 .word 0xffffed90 */
/* @0x1c280c andseq lr, r8, r0, lsr #8 */
/* @0x1c2810 .word 0xffffed94 */
/* @0x1c2814 andseq lr, r8, r8, lsl r4 */
/* @0x1c2818 .word 0xffffed98 */
/* @0x1c281c andseq lr, r8, r4, lsl r4 */
/* @0x1c2820 .word 0xffffed9c */
/* @0x1c2824 andseq lr, r8, r4, lsl r4 */
/* @0x1c2828 .word 0xffffeda0 */
/* @0x1c282c andseq lr, r8, r0, lsl r4 */
/* @0x1c2830 .word 0xffffeda4 */
/* @0x1c2834 andseq lr, r8, r12, lsl #8 */
/* @0x1c2838 .word 0xffffeda8 */
/* @0x1c283c andseq lr, r8, r8, lsl #8 */
/* @0x1c2840 .word 0xffffedac */
/* @0x1c2844 andseq lr, r8, r4, lsl #8 */
/* @0x1c2848 .word 0xffffedb0 */
/* @0x1c284c ldrsheq lr, [r8], -r8 */
/* @0x1c2850 .word 0xffffedb4 */
/* @0x1c2854 andseq lr, r8, r8, ror #7 */
/* @0x1c2858 .word 0xffffedb8 */
/* @0x1c285c ldrsbeq lr, [r8], -r8 */
/* @0x1c2860 .word 0xffffedbc */
/* @0x1c2864 andseq lr, r8, r8, asr #7 */
/* @0x1c2868 .word 0xffffedc0 */
/* @0x1c286c andseq lr, r8, r4, asr #7 */
/* @0x1c2870 .word 0xffffedc4 */
/* @0x1c2874 ldrheq lr, [r8], -r12 */
/* @0x1c2878 .word 0xffffedc8 */
/* @0x1c287c ldrheq lr, [r8], -r8 */
/* @0x1c2880 .word 0xffffedcc */
/* @0x1c2884 ldrheq lr, [r8], -r4 */
/* @0x1c2888 .word 0xffffedd0 */
/* @0x1c288c andseq lr, r8, r12, lsr #7 */
/* @0x1c2890 .word 0xffffedd4 */
/* @0x1c2894 andseq lr, r8, r4, lsr #7 */
/* @0x1c2898 .word 0xffffedd8 */
/* @0x1c289c mulseq r8, r8, r3 */
/* @0x1c28a0 .word 0xffffeddc */
/* @0x1c28a4 andseq lr, r8, r12, lsl #7 */
/* @0x1c28a8 .word 0xffffede0 */
/* @0x1c28ac andseq lr, r8, r12, ror r3 */
/* @0x1c28b0 .word 0xffffede4 */
/* @0x1c28b4 andseq lr, r8, r8, ror r3 */
/* @0x1c28b8 .word 0xffffede8 */
/* @0x1c28bc andseq lr, r8, r8, ror r3 */
/* @0x1c28c0 .word 0xffffedec */
/* @0x1c28c4 andseq lr, r8, r8, ror r3 */
/* @0x1c28c8 .word 0xffffedf0 */
/* @0x1c28cc andseq lr, r8, r12, ror #6 */
/* @0x1c28d0 .word 0xffffedf4 */
/* @0x1c28d4 andseq lr, r8, r0, ror #6 */
/* @0x1c28d8 .word 0xffffedf8 */
/* @0x1c28dc andseq lr, r8, r0, asr r3 */
/* @0x1c28e0 .word 0xffffedfc */
/* @0x1c28e4 andseq lr, r8, r12, asr #6 */
/* @0x1c28e8 .word 0xffffee00 */
/* @0x1c28ec andseq lr, r8, r8, asr #6 */
/* @0x1c28f0 .word 0xffffee04 */
/* @0x1c28f4 andseq lr, r8, r0, asr #6 */
/* @0x1c28f8 .word 0xffffee08 */
/* @0x1c28fc andseq lr, r8, r8, lsr r3 */
/* @0x1c2900 .word 0xffffee0c */
/* @0x1c2904 andseq lr, r8, r0, lsr r3 */
/* @0x1c2908 .word 0xffffee10 */
/* @0x1c290c andseq lr, r8, r4, lsr #6 */
/* @0x1c2910 .word 0xffffee14 */
/* @0x1c2914 andseq lr, r8, r8, lsl r3 */
/* @0x1c2918 .word 0xffffee18 */
/* @0x1c291c andseq lr, r8, r12, lsl #6 */
/* @0x1c2920 .word 0xffffee1c */
/* @0x1c2924 andseq lr, r8, r0, lsl #6 */
/* @0x1c2928 .word 0xffffee20 */
/* @0x1c292c ldrsheq lr, [r8], -r4 */
/* @0x1c2930 .word 0xffffee24 */
/* @0x1c2934 andseq lr, r8, r8, ror #5 */
/* @0x1c2938 .word 0xffffee28 */
/* @0x1c293c ldrsbeq lr, [r8], -r12 */
/* @0x1c2940 .word 0xffffee2c */
/* @0x1c2944 ldrsbeq lr, [r8], -r0 */
/* @0x1c2948 .word 0xffffee30 */
/* @0x1c294c andseq lr, r8, r4, asr #5 */
/* @0x1c2950 .word 0xffffee34 */
/* @0x1c2954 ldrheq lr, [r8], -r8 */
/* @0x1c2958 .word 0xffffee38 */
/* @0x1c295c ldrheq lr, [r8], -r0 */
/* @0x1c2960 .word 0xffffee3c */
/* @0x1c2964 andseq lr, r8, r8, lsr #5 */
/* @0x1c2968 .word 0xffffee40 */
/* @0x1c296c andseq lr, r8, r0, lsr #5 */
/* @0x1c2970 .word 0xffffee44 */
/* @0x1c2974 mulseq r8, r8, r2 */
/* @0x1c2978 .word 0xffffee48 */
/* @0x1c297c mulseq r8, r0, r2 */
/* @0x1c2980 .word 0xffffee4c */
/* @0x1c2984 andseq lr, r8, r8, lsl #5 */
/* @0x1c2988 .word 0xffffee50 */
/* @0x1c298c andseq lr, r8, r0, lsl #5 */
/* @0x1c2990 .word 0xffffee54 */
/* @0x1c2994 andseq lr, r8, r8, ror r2 */
/* @0x1c2998 .word 0xffffee58 */
/* @0x1c299c andseq lr, r8, r12, ror #4 */
/* @0x1c29a0 .word 0xffffee5c */
/* @0x1c29a4 andseq lr, r8, r0, ror #4 */
/* @0x1c29a8 .word 0xffffee60 */
/* @0x1c29ac andseq lr, r8, r8, asr r2 */
/* @0x1c29b0 .word 0xffffee64 */
/* @0x1c29b4 andseq lr, r8, r0, asr r2 */
/* @0x1c29b8 .word 0xffffee68 */
/* @0x1c29bc andseq lr, r8, r12, asr #4 */
/* @0x1c29c0 .word 0xffffee6c */
/* @0x1c29c4 andseq lr, r8, r8, asr #4 */
/* @0x1c29c8 .word 0xffffee70 */
/* @0x1c29cc andseq lr, r8, r4, asr #4 */
/* @0x1c29d0 .word 0xffffee74 */
/* @0x1c29d4 andseq lr, r8, r0, asr #4 */
/* @0x1c29d8 .word 0xffffee78 */
/* @0x1c29dc andseq sp, r8, r0, lsl #27 */
/* @0x1c29e0 .word 0xffffee7c */
/* @0x1c29e4 andseq sp, r8, r8, ror sp */
/* @0x1c29e8 .word 0xffffee80 */
/* @0x1c29ec andseq sp, r8, r0, ror sp */
/* @0x1c29f0 .word 0xffffee84 */
/* @0x1c29f4 andseq sp, r8, r12, ror #26 */
/* @0x1c29f8 .word 0xffffee88 */
/* @0x1c29fc andseq sp, r8, r8, ror #26 */
/* @0x1c2a00 ldr r1, [pc, #-0x30] */
/* @0x1c2a04 ldr r0, [pc, #-0x30] */
/* @0x1c2a08 mov r2, #1 */
/* @0x1c2a0c mov r3, r2 */
/* @0x1c2a10 ldr r1, [r4, r1] */
/* @0x1c2a14 add r0, pc, r0 */
/* @0x1c2a18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2a1c ldr r1, [pc, #-0x44] */
/* @0x1c2a20 ldr r0, [pc, #-0x44] */
/* @0x1c2a24 mov r2, #1 */
/* @0x1c2a28 mov r3, r2 */
/* @0x1c2a2c ldr r1, [r4, r1] */
/* @0x1c2a30 add r0, pc, r0 */
/* @0x1c2a34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2a38 ldr r1, [pc, #-0x58] */
/* @0x1c2a3c ldr r0, [pc, #-0x58] */
/* @0x1c2a40 mov r2, #1 */
/* @0x1c2a44 mov r3, r2 */
/* @0x1c2a48 ldr r1, [r4, r1] */
/* @0x1c2a4c add r0, pc, r0 */
/* @0x1c2a50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2a54 ldr r1, [pc, #-0x6c] */
/* @0x1c2a58 ldr r0, [pc, #-0x6c] */
/* @0x1c2a5c mov r2, #1 */
/* @0x1c2a60 mov r3, r2 */
/* @0x1c2a64 ldr r1, [r4, r1] */
/* @0x1c2a68 add r0, pc, r0 */
/* @0x1c2a6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2a70 ldr r1, [pc, #-0x80] */
/* @0x1c2a74 ldr r0, [pc, #-0x80] */
/* @0x1c2a78 mov r2, #1 */
/* @0x1c2a7c mov r3, r2 */
/* @0x1c2a80 ldr r1, [r4, r1] */
/* @0x1c2a84 add r0, pc, r0 */
/* @0x1c2a88 pop {r4, r5, r6, lr} */
/* @0x1c2a8c b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */

/* ── FUNC 0x1c2a90 · CHashMap<int, CLayer*, 7>::Insert(int, CLayer*) · size=1640 · insn=410 */
/* @0x1c2a90 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c2a94 vpush {d8} */
/* @0x1c2a98 sub sp, sp, #60 */
/* @0x1c2a9c ldr r3, [r0, #0x4] */
/* @0x1c2aa0 mov r11, r0 */
/* @0x1c2aa4 str r2, [sp, #0x24] */
/* @0x1c2aa8 ldr r2, [r0, #0xc] */
/* @0x1c2aac str r1, [sp, #0x1c] */
/* @0x1c2ab0 cmp r3, r2 */
/* @0x1c2ab4 bgt 0x1c2bc4 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x134> */
/* @0x1c2ab8 add r3, r3, #1 */
/* @0x1c2abc ldr r0, [sp, #0x1c] */
/* @0x1c2ac0 str r3, [r11, #0x4] */
/* @0x1c2ac4 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1c2ac8 ldr r4, [r11, #0x8] */
/* @0x1c2acc ldr r6, [r11, #0x10] */
/* @0x1c2ad0 bic r0, r0, #-2147483648 */
/* @0x1c2ad4 and r3, r0, r4 */
/* @0x1c2ad8 add r2, r3, r3, lsl #1 */
/* @0x1c2adc add r2, r6, r2, lsl #2 */
/* @0x1c2ae0 ldr r12, [r2, #0x8] */
/* @0x1c2ae4 cmp r12, #0 */
/* @0x1c2ae8 beq 0x1c2ba4 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x114> */
/* @0x1c2aec ldr r7, [r11] */
/* @0x1c2af0 mov r1, #0 */
/* @0x1c2af4 ldr r8, [sp, #0x1c] */
/* @0x1c2af8 ldr r9, [sp, #0x24] */
/* @0x1c2afc b 0x1c2b44 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0xb4> */
/* @0x1c2b00 ldr r10, [r2] */
/* @0x1c2b04 mov r1, r5 */
/* @0x1c2b08 ldr r5, [r2, #0x4] */
/* @0x1c2b0c str r0, [r2, #0x8] */
/* @0x1c2b10 mov r0, r12 */
/* @0x1c2b14 str r8, [r2] */
/* @0x1c2b18 mov r8, r10 */
/* @0x1c2b1c str r9, [r2, #0x4] */
/* @0x1c2b20 mov r9, r5 */
/* @0x1c2b24 add r3, r3, #1 */
/* @0x1c2b28 add r1, r1, #1 */
/* @0x1c2b2c and r3, r3, r4 */
/* @0x1c2b30 add r2, r3, r3, lsl #1 */
/* @0x1c2b34 add r2, r6, r2, lsl #2 */
/* @0x1c2b38 ldr r12, [r2, #0x8] */
/* @0x1c2b3c cmp r12, #0 */
/* @0x1c2b40 beq 0x1c2b9c <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x10c> */
/* @0x1c2b44 add r5, r7, r3 */
/* @0x1c2b48 and r10, r12, r4 */
/* @0x1c2b4c rsb r5, r10, r5 */
/* @0x1c2b50 and r5, r5, r4 */
/* @0x1c2b54 cmp r5, r1 */
/* @0x1c2b58 blt 0x1c2b00 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x70> */
/* @0x1c2b5c cmp r1, r5 */
/* @0x1c2b60 bne 0x1c2b24 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x94> */
/* @0x1c2b64 cmp r0, r12 */
/* @0x1c2b68 bne 0x1c2b24 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x94> */
/* @0x1c2b6c ldr r12, [r2] */
/* @0x1c2b70 cmp r8, r12 */
/* @0x1c2b74 bne 0x1c2b24 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x94> */
/* @0x1c2b78 ldr r3, [r11, #0x4] */
/* @0x1c2b7c str r8, [sp, #0x1c] */
/* @0x1c2b80 str r8, [r2] */
/* @0x1c2b84 sub r3, r3, #1 */
/* @0x1c2b88 str r9, [r2, #0x4] */
/* @0x1c2b8c str r0, [r2, #0x8] */
/* @0x1c2b90 str r9, [sp, #0x24] */
/* @0x1c2b94 str r3, [r11, #0x4] */
/* @0x1c2b98 b 0x1c2bb8 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x128> */
/* @0x1c2b9c str r8, [sp, #0x1c] */
/* @0x1c2ba0 str r9, [sp, #0x24] */
/* @0x1c2ba4 ldr r12, [sp, #0x1c] */
/* @0x1c2ba8 str r0, [r2, #0x8] */
/* @0x1c2bac str r12, [r2] */
/* @0x1c2bb0 ldr r12, [sp, #0x24] */
/* @0x1c2bb4 str r12, [r2, #0x4] */
/* @0x1c2bb8 add sp, sp, #60 */
/* @0x1c2bbc vpop {d8} */
/* @0x1c2bc0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c2bc4 ldr r12, [r0] */
/* @0x1c2bc8 mov r3, #1 */
/* @0x1c2bcc ldr r1, [pc, #0x430] */
/* @0x1c2bd0 mov r2, #70 */
/* @0x1c2bd4 str r12, [sp, #0x20] */
/* @0x1c2bd8 add r1, pc, r1 */
/* @0x1c2bdc ldr r12, [r0, #0x10] */
/* @0x1c2be0 str r12, [sp, #0x30] */
/* @0x1c2be4 ldr r12, [sp, #0x20] */
/* @0x1c2be8 lsl r0, r12, r3 */
/* @0x1c2bec str r0, [r11] */
/* @0x1c2bf0 add r4, r0, r12, lsl #2 */
/* @0x1c2bf4 sub r0, r0, #1 */
/* @0x1c2bf8 str r0, [r11, #0x8] */
/* @0x1c2bfc lsl r4, r4, #2 */
/* @0x1c2c00 mov r0, r4 */
/* @0x1c2c04 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c2c08 mov r2, r4 */
/* @0x1c2c0c mov r1, #0 */
/* @0x1c2c10 str r0, [r11, #0x10] */
/* @0x1c2c14 bl 0xb65b0 <memset@plt> */
/* @0x1c2c18 ldr r2, [r11] */
/* @0x1c2c1c vldr s15, [pc, #988] */
/* @0x1c2c20 mov r1, #0 */
/* @0x1c2c24 cmp r2, r1 */
/* @0x1c2c28 str r1, [r11, #0x4] */
/* @0x1c2c2c vmov s13, r2 */
/* @0x1c2c30 vcvt.f32.s32 s14, s13 */
/* @0x1c2c34 vmul.f32 s15, s14, s15 */
/* @0x1c2c38 vcvt.s32.f32 s15, s15 */
/* @0x1c2c3c vstr s15, [r11, #12] */
/* @0x1c2c40 ble 0x1c2c60 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x1d0> */
/* @0x1c2c44 add r2, r2, r2, lsl #1 */
/* @0x1c2c48 ldr r3, [r11, #0x10] */
/* @0x1c2c4c add r2, r3, r2, lsl #2 */
/* @0x1c2c50 str r1, [r3, #0x8] */
/* @0x1c2c54 add r3, r3, #12 */
/* @0x1c2c58 cmp r3, r2 */
/* @0x1c2c5c bne 0x1c2c50 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x1c0> */
/* @0x1c2c60 ldr r12, [sp, #0x20] */
/* @0x1c2c64 cmp r12, #0 */
/* @0x1c2c68 ble 0x1c2dd0 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x340> */
/* @0x1c2c6c ldr r12, [pc, #0x394] */
/* @0x1c2c70 vldr s16, [pc, #904] */
/* @0x1c2c74 add r12, pc, r12 */
/* @0x1c2c78 str r12, [sp, #0x34] */
/* @0x1c2c7c mov r12, #0 */
/* @0x1c2c80 str r12, [sp, #0xc] */
/* @0x1c2c84 ldr r12, [pc, #0x380] */
/* @0x1c2c88 add r12, pc, r12 */
/* @0x1c2c8c str r12, [sp, #0x2c] */
/* @0x1c2c90 ldr r12, [sp, #0x30] */
/* @0x1c2c94 str r12, [sp, #0x8] */
/* @0x1c2c98 ldr r12, [sp, #0x8] */
/* @0x1c2c9c ldr r3, [r12, #0x8] */
/* @0x1c2ca0 cmp r3, #0 */
/* @0x1c2ca4 ble 0x1c2da8 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x318> */
/* @0x1c2ca8 ldr r12, [r12] */
/* @0x1c2cac ldr r3, [r11, #0x4] */
/* @0x1c2cb0 ldr r2, [r11, #0xc] */
/* @0x1c2cb4 str r12, [sp, #0x10] */
/* @0x1c2cb8 ldr r12, [sp, #0x8] */
/* @0x1c2cbc cmp r3, r2 */
/* @0x1c2cc0 ldr r12, [r12, #0x4] */
/* @0x1c2cc4 str r12, [sp, #0x18] */
/* @0x1c2cc8 bgt 0x1c2e18 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x388> */
/* @0x1c2ccc add r3, r3, #1 */
/* @0x1c2cd0 ldr r0, [sp, #0x10] */
/* @0x1c2cd4 str r3, [r11, #0x4] */
/* @0x1c2cd8 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1c2cdc ldr lr, [r11, #0x8] */
/* @0x1c2ce0 ldr r6, [r11, #0x10] */
/* @0x1c2ce4 bic r0, r0, #-2147483648 */
/* @0x1c2ce8 and r3, r0, lr */
/* @0x1c2cec add r2, r3, r3, lsl #1 */
/* @0x1c2cf0 add r2, r6, r2, lsl #2 */
/* @0x1c2cf4 ldr r1, [r2, #0x8] */
/* @0x1c2cf8 cmp r1, #0 */
/* @0x1c2cfc beq 0x1c2e00 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x370> */
/* @0x1c2d00 ldr r7, [r11] */
/* @0x1c2d04 mov r4, #0 */
/* @0x1c2d08 ldr r8, [sp, #0x10] */
/* @0x1c2d0c ldr r9, [sp, #0x18] */
/* @0x1c2d10 b 0x1c2d54 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x2c4> */
/* @0x1c2d14 ldr r5, [r2] */
/* @0x1c2d18 ldr r4, [r2, #0x4] */
/* @0x1c2d1c str r0, [r2, #0x8] */
/* @0x1c2d20 mov r0, r1 */
/* @0x1c2d24 str r8, [r2] */
/* @0x1c2d28 mov r8, r5 */
/* @0x1c2d2c str r9, [r2, #0x4] */
/* @0x1c2d30 mov r9, r4 */
/* @0x1c2d34 add r3, r3, #1 */
/* @0x1c2d38 add r4, r12, #1 */
/* @0x1c2d3c and r3, r3, lr */
/* @0x1c2d40 add r2, r3, r3, lsl #1 */
/* @0x1c2d44 add r2, r6, r2, lsl #2 */
/* @0x1c2d48 ldr r1, [r2, #0x8] */
/* @0x1c2d4c cmp r1, #0 */
/* @0x1c2d50 beq 0x1c2df8 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x368> */
/* @0x1c2d54 add r12, r7, r3 */
/* @0x1c2d58 and r5, r1, lr */
/* @0x1c2d5c rsb r12, r5, r12 */
/* @0x1c2d60 and r12, r12, lr */
/* @0x1c2d64 cmp r12, r4 */
/* @0x1c2d68 blt 0x1c2d14 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x284> */
/* @0x1c2d6c movne r12, r4 */
/* @0x1c2d70 bne 0x1c2d34 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x2a4> */
/* @0x1c2d74 cmp r1, r0 */
/* @0x1c2d78 bne 0x1c2d34 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x2a4> */
/* @0x1c2d7c ldr r4, [r2] */
/* @0x1c2d80 cmp r8, r4 */
/* @0x1c2d84 bne 0x1c2d34 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x2a4> */
/* @0x1c2d88 ldr r3, [r11, #0x4] */
/* @0x1c2d8c str r8, [sp, #0x10] */
/* @0x1c2d90 str r8, [r2] */
/* @0x1c2d94 sub r3, r3, #1 */
/* @0x1c2d98 str r9, [r2, #0x4] */
/* @0x1c2d9c str r1, [r2, #0x8] */
/* @0x1c2da0 str r9, [sp, #0x18] */
/* @0x1c2da4 str r3, [r11, #0x4] */
/* @0x1c2da8 ldr r12, [sp, #0xc] */
/* @0x1c2dac ldr r0, [sp, #0x20] */
/* @0x1c2db0 add r12, r12, #1 */
/* @0x1c2db4 str r12, [sp, #0xc] */
/* @0x1c2db8 ldr r12, [sp, #0x8] */
/* @0x1c2dbc add r12, r12, #12 */
/* @0x1c2dc0 str r12, [sp, #0x8] */
/* @0x1c2dc4 ldr r12, [sp, #0xc] */
/* @0x1c2dc8 cmp r12, r0 */
/* @0x1c2dcc bne 0x1c2c98 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x208> */
/* @0x1c2dd0 ldr r0, [sp, #0x30] */
/* @0x1c2dd4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1c2dd8 vldr s13, [r11] */
/* @0x1c2ddc vcvt.f32.s32 s14, s13 */
/* @0x1c2de0 vldr s15, [pc, #536] */
/* @0x1c2de4 ldr r3, [r11, #0x4] */
/* @0x1c2de8 vmul.f32 s15, s14, s15 */
/* @0x1c2dec vcvt.s32.f32 s15, s15 */
/* @0x1c2df0 vstr s15, [r11, #12] */
/* @0x1c2df4 b 0x1c2ab8 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x28> */
/* @0x1c2df8 str r8, [sp, #0x10] */
/* @0x1c2dfc str r9, [sp, #0x18] */
/* @0x1c2e00 ldr r12, [sp, #0x10] */
/* @0x1c2e04 str r0, [r2, #0x8] */
/* @0x1c2e08 str r12, [r2] */
/* @0x1c2e0c ldr r12, [sp, #0x18] */
/* @0x1c2e10 str r12, [r2, #0x4] */
/* @0x1c2e14 b 0x1c2da8 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x318> */
/* @0x1c2e18 ldr r12, [r11] */
/* @0x1c2e1c mov r3, #1 */
/* @0x1c2e20 ldr r1, [sp, #0x34] */
/* @0x1c2e24 mov r2, #70 */
/* @0x1c2e28 str r12, [sp, #0x14] */
/* @0x1c2e2c ldr r12, [r11, #0x10] */
/* @0x1c2e30 str r12, [sp, #0x28] */
/* @0x1c2e34 ldr r12, [sp, #0x14] */
/* @0x1c2e38 lsl r0, r12, r3 */
/* @0x1c2e3c str r0, [r11] */
/* @0x1c2e40 add r4, r0, r12, lsl #2 */
/* @0x1c2e44 sub r0, r0, #1 */
/* @0x1c2e48 str r0, [r11, #0x8] */
/* @0x1c2e4c lsl r4, r4, #2 */
/* @0x1c2e50 mov r0, r4 */
/* @0x1c2e54 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c2e58 mov r2, r4 */
/* @0x1c2e5c mov r1, #0 */
/* @0x1c2e60 str r0, [r11, #0x10] */
/* @0x1c2e64 bl 0xb65b0 <memset@plt> */
/* @0x1c2e68 ldr r2, [r11] */
/* @0x1c2e6c mov r0, #0 */
/* @0x1c2e70 str r0, [r11, #0x4] */
/* @0x1c2e74 cmp r2, r0 */
/* @0x1c2e78 vmov s13, r2 */
/* @0x1c2e7c vcvt.f32.s32 s15, s13 */
/* @0x1c2e80 vmul.f32 s15, s15, s16 */
/* @0x1c2e84 vcvt.s32.f32 s15, s15 */
/* @0x1c2e88 vstr s15, [r11, #12] */
/* @0x1c2e8c ble 0x1c2eb0 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x420> */
/* @0x1c2e90 add r2, r2, r2, lsl #1 */
/* @0x1c2e94 ldr r3, [r11, #0x10] */
/* @0x1c2e98 add r2, r3, r2, lsl #2 */
/* @0x1c2e9c mov r0, #0 */
/* @0x1c2ea0 add r3, r3, #12 */
/* @0x1c2ea4 str r0, [r3, #-0x4] */
/* @0x1c2ea8 cmp r3, r2 */
/* @0x1c2eac bne 0x1c2e9c <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x40c> */
/* @0x1c2eb0 ldr r12, [sp, #0x14] */
/* @0x1c2eb4 cmp r12, #0 */
/* @0x1c2eb8 ble 0x1c2fd0 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x540> */
/* @0x1c2ebc ldr r6, [sp, #0x28] */
/* @0x1c2ec0 mov r12, #0 */
/* @0x1c2ec4 str r12, [sp, #0x4] */
/* @0x1c2ec8 ldr r3, [r6, #0x8] */
/* @0x1c2ecc cmp r3, #0 */
/* @0x1c2ed0 ble 0x1c2fb4 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x524> */
/* @0x1c2ed4 ldr r3, [r11, #0x4] */
/* @0x1c2ed8 ldr r2, [r11, #0xc] */
/* @0x1c2edc ldr r4, [r6] */
/* @0x1c2ee0 cmp r3, r2 */
/* @0x1c2ee4 ldr r5, [r6, #0x4] */
/* @0x1c2ee8 bgt 0x1c3010 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x580> */
/* @0x1c2eec add r3, r3, #1 */
/* @0x1c2ef0 mov r0, r4 */
/* @0x1c2ef4 str r3, [r11, #0x4] */
/* @0x1c2ef8 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1c2efc ldr lr, [r11, #0x8] */
/* @0x1c2f00 ldr r9, [r11, #0x10] */
/* @0x1c2f04 bic r0, r0, #-2147483648 */
/* @0x1c2f08 and r3, r0, lr */
/* @0x1c2f0c add r2, r3, r3, lsl #1 */
/* @0x1c2f10 add r2, r9, r2, lsl #2 */
/* @0x1c2f14 ldr r1, [r2, #0x8] */
/* @0x1c2f18 cmp r1, #0 */
/* @0x1c2f1c ldrne r10, [r11] */
/* @0x1c2f20 movne r7, #0 */
/* @0x1c2f24 bne 0x1c2f6c <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x4dc> */
/* @0x1c2f28 b 0x1c2ff4 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x564> */
/* @0x1c2f2c ldr r8, [r2] */
/* @0x1c2f30 ldr r7, [r2, #0x4] */
/* @0x1c2f34 str r0, [r2, #0x8] */
/* @0x1c2f38 mov r0, r1 */
/* @0x1c2f3c str r4, [r2] */
/* @0x1c2f40 mov r4, r8 */
/* @0x1c2f44 str r5, [r2, #0x4] */
/* @0x1c2f48 mov r5, r7 */
/* @0x1c2f4c add r3, r3, #1 */
/* @0x1c2f50 add r7, r12, #1 */
/* @0x1c2f54 and r3, r3, lr */
/* @0x1c2f58 add r2, r3, r3, lsl #1 */
/* @0x1c2f5c add r2, r9, r2, lsl #2 */
/* @0x1c2f60 ldr r1, [r2, #0x8] */
/* @0x1c2f64 cmp r1, #0 */
/* @0x1c2f68 beq 0x1c2ff4 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x564> */
/* @0x1c2f6c add r12, r3, r10 */
/* @0x1c2f70 and r8, r1, lr */
/* @0x1c2f74 rsb r12, r8, r12 */
/* @0x1c2f78 and r12, r12, lr */
/* @0x1c2f7c cmp r12, r7 */
/* @0x1c2f80 blt 0x1c2f2c <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x49c> */
/* @0x1c2f84 movne r12, r7 */
/* @0x1c2f88 bne 0x1c2f4c <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x4bc> */
/* @0x1c2f8c cmp r1, r0 */
/* @0x1c2f90 bne 0x1c2f4c <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x4bc> */
/* @0x1c2f94 ldr r7, [r2] */
/* @0x1c2f98 cmp r4, r7 */
/* @0x1c2f9c bne 0x1c2f4c <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x4bc> */
/* @0x1c2fa0 ldr r3, [r11, #0x4] */
/* @0x1c2fa4 stm r2, {r4, r5} */
/* @0x1c2fa8 sub r3, r3, #1 */
/* @0x1c2fac str r1, [r2, #0x8] */
/* @0x1c2fb0 str r3, [r11, #0x4] */
/* @0x1c2fb4 ldr r12, [sp, #0x4] */
/* @0x1c2fb8 add r6, r6, #12 */
/* @0x1c2fbc ldr r0, [sp, #0x14] */
/* @0x1c2fc0 add r12, r12, #1 */
/* @0x1c2fc4 str r12, [sp, #0x4] */
/* @0x1c2fc8 cmp r12, r0 */
/* @0x1c2fcc bne 0x1c2ec8 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x438> */
/* @0x1c2fd0 ldr r0, [sp, #0x28] */
/* @0x1c2fd4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1c2fd8 vldr s13, [r11] */
/* @0x1c2fdc vcvt.f32.s32 s15, s13 */
/* @0x1c2fe0 ldr r3, [r11, #0x4] */
/* @0x1c2fe4 vmul.f32 s15, s15, s16 */
/* @0x1c2fe8 vcvt.s32.f32 s15, s15 */
/* @0x1c2fec vstr s15, [r11, #12] */
/* @0x1c2ff0 b 0x1c2ccc <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x23c> */
/* @0x1c2ff4 stm r2, {r4, r5} */
/* @0x1c2ff8 str r0, [r2, #0x8] */
/* @0x1c2ffc b 0x1c2fb4 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x524> */
/* @0x1c3000 svclo #0x19999a */
/* @0x1c3004 andseq lr, r6, r8, asr r4 */
/* @0x1c3008 ldrheq lr, [r6], -r12 */
/* @0x1c300c andseq lr, r6, r8, lsr #7 */
/* @0x1c3010 ldr r8, [r11] */
/* @0x1c3014 mov r3, #1 */
/* @0x1c3018 ldr r1, [sp, #0x2c] */
/* @0x1c301c mov r2, #70 */
/* @0x1c3020 ldr r7, [r11, #0x10] */
/* @0x1c3024 lsl r0, r8, r3 */
/* @0x1c3028 str r0, [r11] */
/* @0x1c302c add r9, r0, r8, lsl #2 */
/* @0x1c3030 sub r0, r0, #1 */
/* @0x1c3034 str r0, [r11, #0x8] */
/* @0x1c3038 lsl r9, r9, #2 */
/* @0x1c303c mov r0, r9 */
/* @0x1c3040 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c3044 mov r2, r9 */
/* @0x1c3048 mov r1, #0 */
/* @0x1c304c str r0, [r11, #0x10] */
/* @0x1c3050 bl 0xb65b0 <memset@plt> */
/* @0x1c3054 ldr r2, [r11] */
/* @0x1c3058 mov r0, #0 */
/* @0x1c305c str r0, [r11, #0x4] */
/* @0x1c3060 cmp r2, r0 */
/* @0x1c3064 vmov s13, r2 */
/* @0x1c3068 vcvt.f32.s32 s15, s13 */
/* @0x1c306c vmul.f32 s15, s15, s16 */
/* @0x1c3070 vcvt.s32.f32 s15, s15 */
/* @0x1c3074 vstr s15, [r11, #12] */
/* @0x1c3078 ble 0x1c309c <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x60c> */
/* @0x1c307c add r2, r2, r2, lsl #1 */
/* @0x1c3080 ldr r3, [r11, #0x10] */
/* @0x1c3084 add r2, r3, r2, lsl #2 */
/* @0x1c3088 mov r0, #0 */
/* @0x1c308c add r3, r3, #12 */
/* @0x1c3090 str r0, [r3, #-0x4] */
/* @0x1c3094 cmp r3, r2 */
/* @0x1c3098 bne 0x1c3088 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x5f8> */
/* @0x1c309c cmp r8, #0 */
/* @0x1c30a0 movgt r9, r7 */
/* @0x1c30a4 movgt r10, #0 */
/* @0x1c30a8 ble 0x1c30d4 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x644> */
/* @0x1c30ac ldr r3, [r9, #0x8] */
/* @0x1c30b0 mov r0, r11 */
/* @0x1c30b4 add r10, r10, #1 */
/* @0x1c30b8 cmp r3, #0 */
/* @0x1c30bc ble 0x1c30c8 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x638> */
/* @0x1c30c0 ldm r9, {r1, r2} */
/* @0x1c30c4 bl 0x1c2a90 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_> */
/* @0x1c30c8 cmp r10, r8 */
/* @0x1c30cc add r9, r9, #12 */
/* @0x1c30d0 bne 0x1c30ac <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x61c> */
/* @0x1c30d4 mov r0, r7 */
/* @0x1c30d8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1c30dc vldr s13, [r11] */
/* @0x1c30e0 vcvt.f32.s32 s15, s13 */
/* @0x1c30e4 ldr r3, [r11, #0x4] */
/* @0x1c30e8 vmul.f32 s15, s15, s16 */
/* @0x1c30ec vcvt.s32.f32 s15, s15 */
/* @0x1c30f0 vstr s15, [r11, #12] */
/* @0x1c30f4 b 0x1c2eec <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x45c> */

/* ── FUNC 0x1c30f8 · CLayerManager::InsertLayerIntoActiveList(CRoom*, CLayer*) · size=748 · insn=187 */
/* @0x1c30f8 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c30fc subs r9, r0, #0 */
/* @0x1c3100 mov r7, r1 */
/* @0x1c3104 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c3108 cmp r1, #0 */
/* @0x1c310c popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c3110 ldr r2, [r9, #0xd4] */
/* @0x1c3114 cmp r2, #0 */
/* @0x1c3118 beq 0x1c3264 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x16c> */
/* @0x1c311c ldr r3, [r1, #0x4] */
/* @0x1c3120 ldr r1, [r2, #0x4] */
/* @0x1c3124 cmp r3, r1 */
/* @0x1c3128 movge r1, r2 */
/* @0x1c312c blt 0x1c32a8 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x1b0> */
/* @0x1c3130 ldr r1, [r1, #0x68] */
/* @0x1c3134 cmp r1, #0 */
/* @0x1c3138 beq 0x1c3264 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x16c> */
/* @0x1c313c ldr r0, [r1, #0x4] */
/* @0x1c3140 cmp r0, r3 */
/* @0x1c3144 ble 0x1c3130 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x38> */
/* @0x1c3148 ldr r3, [r1, #0x6c] */
/* @0x1c314c cmp r3, #0 */
/* @0x1c3150 beq 0x1c33a4 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x2ac> */
/* @0x1c3154 ldr r2, [r9, #0xdc] */
/* @0x1c3158 add r2, r2, #1 */
/* @0x1c315c str r2, [r9, #0xdc] */
/* @0x1c3160 str r3, [r7, #0x6c] */
/* @0x1c3164 ldr r2, [r3, #0x68] */
/* @0x1c3168 str r2, [r7, #0x68] */
/* @0x1c316c ldr r2, [r3, #0x68] */
/* @0x1c3170 cmp r2, #0 */
/* @0x1c3174 streq r7, [r9, #0xd8] */
/* @0x1c3178 strne r7, [r2, #0x6c] */
/* @0x1c317c str r7, [r3, #0x68] */
/* @0x1c3180 ldr r3, [r9, #0xe8] */
/* @0x1c3184 ldr r2, [r9, #0xf0] */
/* @0x1c3188 ldr r8, [r7] */
/* @0x1c318c cmp r3, r2 */
/* @0x1c3190 bgt 0x1c32b0 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x1b8> */
/* @0x1c3194 add r3, r3, #1 */
/* @0x1c3198 mov r0, r8 */
/* @0x1c319c str r3, [r9, #0xe8] */
/* @0x1c31a0 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1c31a4 ldr r5, [r9, #0xec] */
/* @0x1c31a8 ldr r1, [r9, #0xf4] */
/* @0x1c31ac bic r0, r0, #-2147483648 */
/* @0x1c31b0 and r3, r0, r5 */
/* @0x1c31b4 add r2, r3, r3, lsl #1 */
/* @0x1c31b8 add r2, r1, r2, lsl #2 */
/* @0x1c31bc ldr r12, [r2, #0x8] */
/* @0x1c31c0 cmp r12, #0 */
/* @0x1c31c4 ldrne r10, [r9, #0xe4] */
/* @0x1c31c8 movne r6, #0 */
/* @0x1c31cc bne 0x1c3214 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x11c> */
/* @0x1c31d0 b 0x1c3298 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x1a0> */
/* @0x1c31d4 ldr r11, [r2] */
/* @0x1c31d8 ldr r6, [r2, #0x4] */
/* @0x1c31dc str r0, [r2, #0x8] */
/* @0x1c31e0 mov r0, r12 */
/* @0x1c31e4 str r8, [r2] */
/* @0x1c31e8 mov r8, r11 */
/* @0x1c31ec str r7, [r2, #0x4] */
/* @0x1c31f0 mov r7, r6 */
/* @0x1c31f4 add r3, r3, #1 */
/* @0x1c31f8 add r6, r4, #1 */
/* @0x1c31fc and r3, r3, r5 */
/* @0x1c3200 add r2, r3, r3, lsl #1 */
/* @0x1c3204 add r2, r1, r2, lsl #2 */
/* @0x1c3208 ldr r12, [r2, #0x8] */
/* @0x1c320c cmp r12, #0 */
/* @0x1c3210 beq 0x1c3298 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x1a0> */
/* @0x1c3214 add r4, r10, r3 */
/* @0x1c3218 and r11, r12, r5 */
/* @0x1c321c rsb r4, r11, r4 */
/* @0x1c3220 and r4, r4, r5 */
/* @0x1c3224 cmp r4, r6 */
/* @0x1c3228 blt 0x1c31d4 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0xdc> */
/* @0x1c322c movne r4, r6 */
/* @0x1c3230 bne 0x1c31f4 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0xfc> */
/* @0x1c3234 cmp r12, r0 */
/* @0x1c3238 bne 0x1c31f4 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0xfc> */
/* @0x1c323c ldr r6, [r2] */
/* @0x1c3240 cmp r8, r6 */
/* @0x1c3244 bne 0x1c31f4 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0xfc> */
/* @0x1c3248 ldr r3, [r9, #0xe8] */
/* @0x1c324c str r8, [r2] */
/* @0x1c3250 str r7, [r2, #0x4] */
/* @0x1c3254 sub r3, r3, #1 */
/* @0x1c3258 str r12, [r2, #0x8] */
/* @0x1c325c str r3, [r9, #0xe8] */
/* @0x1c3260 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c3264 ldr r3, [r9, #0xd8] */
/* @0x1c3268 ldr r2, [r9, #0xdc] */
/* @0x1c326c cmp r3, #0 */
/* @0x1c3270 add r2, r2, #1 */
/* @0x1c3274 str r2, [r9, #0xdc] */
/* @0x1c3278 beq 0x1c33c8 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x2d0> */
/* @0x1c327c str r7, [r3, #0x68] */
/* @0x1c3280 mov r3, #0 */
/* @0x1c3284 ldr r2, [r9, #0xd8] */
/* @0x1c3288 str r2, [r7, #0x6c] */
/* @0x1c328c str r7, [r9, #0xd8] */
/* @0x1c3290 str r3, [r7, #0x68] */
/* @0x1c3294 b 0x1c3180 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x88> */
/* @0x1c3298 str r8, [r2] */
/* @0x1c329c str r7, [r2, #0x4] */
/* @0x1c32a0 str r0, [r2, #0x8] */
/* @0x1c32a4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c32a8 mov r1, r2 */
/* @0x1c32ac b 0x1c3148 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x50> */
/* @0x1c32b0 ldr r10, [r9, #0xe4] */
/* @0x1c32b4 mov r3, #1 */
/* @0x1c32b8 ldr r1, [pc, #0x120] */
/* @0x1c32bc mov r2, #70 */
/* @0x1c32c0 ldr r6, [r9, #0xf4] */
/* @0x1c32c4 lsl r0, r10, r3 */
/* @0x1c32c8 add r1, pc, r1 */
/* @0x1c32cc add r4, r0, r10, lsl #2 */
/* @0x1c32d0 str r0, [r9, #0xe4] */
/* @0x1c32d4 sub r0, r0, #1 */
/* @0x1c32d8 str r0, [r9, #0xec] */
/* @0x1c32dc lsl r4, r4, #2 */
/* @0x1c32e0 mov r0, r4 */
/* @0x1c32e4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c32e8 mov r2, r4 */
/* @0x1c32ec mov r1, #0 */
/* @0x1c32f0 str r0, [r9, #0xf4] */
/* @0x1c32f4 bl 0xb65b0 <memset@plt> */
/* @0x1c32f8 ldr r2, [r9, #0xe4] */
/* @0x1c32fc vldr s15, [pc, #216] */
/* @0x1c3300 mov r1, #0 */
/* @0x1c3304 cmp r2, r1 */
/* @0x1c3308 str r1, [r9, #0xe8] */
/* @0x1c330c vmov s13, r2 */
/* @0x1c3310 vcvt.f32.s32 s14, s13 */
/* @0x1c3314 vmul.f32 s15, s14, s15 */
/* @0x1c3318 vcvt.s32.f32 s15, s15 */
/* @0x1c331c vstr s15, [r9, #240] */
/* @0x1c3320 ble 0x1c3340 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x248> */
/* @0x1c3324 add r2, r2, r2, lsl #1 */
/* @0x1c3328 ldr r3, [r9, #0xf4] */
/* @0x1c332c add r2, r3, r2, lsl #2 */
/* @0x1c3330 str r1, [r3, #0x8] */
/* @0x1c3334 add r3, r3, #12 */
/* @0x1c3338 cmp r3, r2 */
/* @0x1c333c bne 0x1c3330 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x238> */
/* @0x1c3340 cmp r10, #0 */
/* @0x1c3344 addgt r11, r9, #228 */
/* @0x1c3348 movgt r4, r6 */
/* @0x1c334c movgt r5, #0 */
/* @0x1c3350 ble 0x1c337c <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x284> */
/* @0x1c3354 ldr r3, [r4, #0x8] */
/* @0x1c3358 mov r0, r11 */
/* @0x1c335c add r5, r5, #1 */
/* @0x1c3360 cmp r3, #0 */
/* @0x1c3364 ble 0x1c3370 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x278> */
/* @0x1c3368 ldm r4, {r1, r2} */
/* @0x1c336c bl 0x1c2a90 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_> */
/* @0x1c3370 cmp r5, r10 */
/* @0x1c3374 add r4, r4, #12 */
/* @0x1c3378 bne 0x1c3354 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x25c> */
/* @0x1c337c mov r0, r6 */
/* @0x1c3380 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1c3384 vldr s13, [r9, #228] */
/* @0x1c3388 vcvt.f32.s32 s14, s13 */
/* @0x1c338c vldr s15, [pc, #72] */
/* @0x1c3390 ldr r3, [r9, #0xe8] */
/* @0x1c3394 vmul.f32 s15, s14, s15 */
/* @0x1c3398 vcvt.s32.f32 s15, s15 */
/* @0x1c339c vstr s15, [r9, #240] */
/* @0x1c33a0 b 0x1c3194 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x9c> */
/* @0x1c33a4 ldr r1, [r9, #0xdc] */
/* @0x1c33a8 add r1, r1, #1 */
/* @0x1c33ac str r1, [r9, #0xdc] */
/* @0x1c33b0 str r7, [r2, #0x6c] */
/* @0x1c33b4 ldr r2, [r9, #0xd4] */
/* @0x1c33b8 str r2, [r7, #0x68] */
/* @0x1c33bc str r7, [r9, #0xd4] */
/* @0x1c33c0 str r3, [r7, #0x6c] */
/* @0x1c33c4 b 0x1c3180 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x88> */
/* @0x1c33c8 str r7, [r9, #0xd8] */
/* @0x1c33cc str r7, [r9, #0xd4] */
/* @0x1c33d0 str r3, [r7, #0x6c] */
/* @0x1c33d4 str r3, [r7, #0x68] */
/* @0x1c33d8 b 0x1c3180 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x88> */
/* @0x1c33dc svclo #0x19999a */
/* @0x1c33e0 andseq sp, r6, r8, ror #26 */

/* ── FUNC 0x1c33e4 · CLayerManager::AddDynamicLayer(CRoom*, int) · size=436 · insn=109 */
/* @0x1c33e4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c33e8 vpush {d8} */
/* @0x1c33ec sub sp, sp, #12 */
/* @0x1c33f0 ldr r10, [pc, #0x190] */
/* @0x1c33f4 stm sp, {r0, r1} */
/* @0x1c33f8 ldr r10, [pc, r10] */
/* @0x1c33fc ldr r7, [r10, #0x8] */
/* @0x1c3400 cmp r7, #0 */
/* @0x1c3404 bne 0x1c34f8 <_ZN13CLayerManager15AddDynamicLayerEP5CRoomi+0x114> */
/* @0x1c3408 ldr r3, [r10, #0x10] */
/* @0x1c340c cmp r3, #0 */
/* @0x1c3410 ble 0x1c34f0 <_ZN13CLayerManager15AddDynamicLayerEP5CRoomi+0x10c> */
/* @0x1c3414 ldr r9, [pc, #0x170] */
/* @0x1c3418 mov r8, #1 */
/* @0x1c341c mov r4, #0 */
/* @0x1c3420 mov r5, #0 */
/* @0x1c3424 add r9, pc, r9 */
/* @0x1c3428 vldr s16, [pc, #340] */
/* @0x1c342c mov r2, #63 */
/* @0x1c3430 mov r0, #112 */
/* @0x1c3434 mov r1, r9 */
/* @0x1c3438 mov r3, #1 */
/* @0x1c343c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c3440 mov r11, #0 */
/* @0x1c3444 mvn r2, #0 */
/* @0x1c3448 subs r6, r0, #0 */
/* @0x1c344c add r0, r6, #48 */
/* @0x1c3450 beq 0x1c34a4 <_ZN13CLayerManager15AddDynamicLayerEP5CRoomi+0xc0> */
/* @0x1c3454 str r2, [r6] */
/* @0x1c3458 vstr s16, [r6, #8] */
/* @0x1c345c str r11, [r6, #0x4] */
/* @0x1c3460 vstr s16, [r6, #12] */
/* @0x1c3464 vstr s16, [r6, #16] */
/* @0x1c3468 vstr s16, [r6, #20] */
/* @0x1c346c strb r8, [r6, #0x18] */
/* @0x1c3470 strd r4, r5, [r6, #72] */
/* @0x1c3474 strb r11, [r6, #0x19] */
/* @0x1c3478 str r11, [r6, #0x1c] */
/* @0x1c347c str r2, [r6, #0x20] */
/* @0x1c3480 str r2, [r6, #0x24] */
/* @0x1c3484 str r2, [r6, #0x28] */
/* @0x1c3488 bl 0x214728 <_ZN13CTimingSource5ResetEv> */
/* @0x1c348c str r11, [r6, #0x5c] */
/* @0x1c3490 str r11, [r6, #0x58] */
/* @0x1c3494 str r11, [r6, #0x60] */
/* @0x1c3498 str r8, [r6, #0x64] */
/* @0x1c349c str r11, [r6, #0x68] */
/* @0x1c34a0 str r11, [r6, #0x6c] */
/* @0x1c34a4 ldr r3, [r10] */
/* @0x1c34a8 mov r1, #0 */
/* @0x1c34ac add r7, r7, #1 */
/* @0x1c34b0 ldr r2, [r10, #0x8] */
/* @0x1c34b4 cmp r3, r1 */
/* @0x1c34b8 streq r6, [r10, #0x4] */
/* @0x1c34bc strne r6, [r3, #0x6c] */
/* @0x1c34c0 add r2, r2, #1 */
/* @0x1c34c4 streq r3, [r6, #0x6c] */
/* @0x1c34c8 streq r3, [r6, #0x68] */
/* @0x1c34cc strne r3, [r6, #0x68] */
/* @0x1c34d0 ldr r3, [r10, #0x10] */
/* @0x1c34d4 streq r6, [r10] */
/* @0x1c34d8 strne r6, [r10] */
/* @0x1c34dc strne r1, [r6, #0x6c] */
/* @0x1c34e0 cmp r7, r3 */
/* @0x1c34e4 str r2, [r10, #0x8] */
/* @0x1c34e8 blt 0x1c342c <_ZN13CLayerManager15AddDynamicLayerEP5CRoomi+0x48> */
/* @0x1c34ec ldr r7, [r10, #0x8] */
/* @0x1c34f0 lsl r3, r3, #1 */
/* @0x1c34f4 str r3, [r10, #0x10] */
/* @0x1c34f8 ldr r4, [r10] */
/* @0x1c34fc mov lr, #1 */
/* @0x1c3500 ldr r1, [sp, #0x4] */
/* @0x1c3504 sub r7, r7, #1 */
/* @0x1c3508 ldr r0, [sp] */
/* @0x1c350c ldr r3, [r4, #0x6c] */
/* @0x1c3510 ldr r2, [r4, #0x68] */
/* @0x1c3514 cmp r3, #0 */
/* @0x1c3518 str r7, [r10, #0x8] */
/* @0x1c351c strne r2, [r3, #0x68] */
/* @0x1c3520 ldrne r2, [r4, #0x68] */
/* @0x1c3524 ldrne r3, [r4, #0x6c] */
/* @0x1c3528 streq r2, [r10] */
/* @0x1c352c cmp r2, #0 */
/* @0x1c3530 streq r3, [r10, #0x4] */
/* @0x1c3534 strne r3, [r2, #0x6c] */
/* @0x1c3538 ldr r2, [pc, #0x50] */
/* @0x1c353c ldr r3, [pc, #0x50] */
/* @0x1c3540 ldr r2, [pc, r2] */
/* @0x1c3544 str r1, [r4, #0x4] */
/* @0x1c3548 ldr r3, [pc, r3] */
/* @0x1c354c mov r1, r4 */
/* @0x1c3550 ldr r12, [r2] */
/* @0x1c3554 ldr r2, [r3] */
/* @0x1c3558 strb lr, [r4, #0x19] */
/* @0x1c355c cmp r2, r12 */
/* @0x1c3560 movlt r2, r12 */
/* @0x1c3564 add r2, r2, lr */
/* @0x1c3568 str r2, [r3] */
/* @0x1c356c str r2, [r4] */
/* @0x1c3570 bl 0x1c30f8 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer> */
/* @0x1c3574 mov r0, r4 */
/* @0x1c3578 add sp, sp, #12 */
/* @0x1c357c vpop {d8} */
/* @0x1c3580 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c3584 andeq r0, r0, r0 */
/* @0x1c3588 eoreq sp, r2, r4, ror #8 */
/* @0x1c358c andseq r10, r8, r0, ror r2 */
/* @0x1c3590 eoreq sp, r2, r0, asr #6 */
/* @0x1c3594 mlaeq r2, r4, r5, sp */
