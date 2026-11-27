/* libyoyo.so 覆盖卡组 0149
 * 函数 0x1bce08..0x1be34c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1bce08 · F_LayerBackgroundGetYscale(RValue&, CInstance*, CInstance*, int, RValue*) · size=172 · insn=43 */
/* @0x1bce08 cmp r3, #1 */
/* @0x1bce0c push {r3, r4, r5, r6, r7, lr} */
/* @0x1bce10 mov r3, #0 */
/* @0x1bce14 mov r5, r3 */
/* @0x1bce18 mov r4, r0 */
/* @0x1bce1c movt r3, #0xbff0 */
/* @0x1bce20 str r5, [r0, #0xc] */
/* @0x1bce24 str r3, [r0, #0x4] */
/* @0x1bce28 str r5, [r0] */
/* @0x1bce2c ldr r6, [sp, #0x18] */
/* @0x1bce30 beq 0x1bce48 <_Z26F_LayerBackgroundGetYscaleR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bce34 ldr r0, [pc, #0x74] */
/* @0x1bce38 mov r1, r5 */
/* @0x1bce3c pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bce40 add r0, pc, r0 */
/* @0x1bce44 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bce48 str r5, [r0] */
/* @0x1bce4c mov r3, #0 */
/* @0x1bce50 movt r3, #0x3ff0 */
/* @0x1bce54 str r3, [r0, #0x4] */
/* @0x1bce58 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bce5c mov r1, r5 */
/* @0x1bce60 mov r7, r0 */
/* @0x1bce64 mov r0, r6 */
/* @0x1bce68 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bce6c mov r2, r5 */
/* @0x1bce70 mov r1, r0 */
/* @0x1bce74 mov r0, r7 */
/* @0x1bce78 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bce7c cmp r0, #0 */
/* @0x1bce80 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bce84 ldr r3, [r0] */
/* @0x1bce88 cmp r3, #1 */
/* @0x1bce8c popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bce90 ldr r3, [r0, #0x1c] */
/* @0x1bce94 cmp r3, #0 */
/* @0x1bce98 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bce9c vldr s15, [r3, #16] */
/* @0x1bcea0 vcvt.f64.f32 d6, s15 */
/* @0x1bcea4 vmov r2, r3, d6 */
/* @0x1bcea8 stm r4, {r2, r3} */
/* @0x1bceac pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bceb0 andseq r1, r9, r4, ror #7 */

/* ── FUNC 0x1bceb4 · F_LayerBackgroundGetBlend(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x1bceb4 cmp r3, #1 */
/* @0x1bceb8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bcebc mov r3, #0 */
/* @0x1bcec0 mov r4, r3 */
/* @0x1bcec4 mov r5, r0 */
/* @0x1bcec8 movt r3, #0xbff0 */
/* @0x1bcecc str r4, [r0, #0xc] */
/* @0x1bced0 str r3, [r0, #0x4] */
/* @0x1bced4 str r4, [r0] */
/* @0x1bced8 ldr r6, [sp, #0x18] */
/* @0x1bcedc beq 0x1bcef4 <_Z25F_LayerBackgroundGetBlendR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bcee0 ldr r0, [pc, #0x70] */
/* @0x1bcee4 mov r1, r4 */
/* @0x1bcee8 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bceec add r0, pc, r0 */
/* @0x1bcef0 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bcef4 str r4, [r0] */
/* @0x1bcef8 str r4, [r0, #0x4] */
/* @0x1bcefc bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bcf00 mov r1, r4 */
/* @0x1bcf04 mov r7, r0 */
/* @0x1bcf08 mov r0, r6 */
/* @0x1bcf0c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bcf10 mov r2, r4 */
/* @0x1bcf14 mov r1, r0 */
/* @0x1bcf18 mov r0, r7 */
/* @0x1bcf1c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bcf20 cmp r0, #0 */
/* @0x1bcf24 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bcf28 ldr r3, [r0] */
/* @0x1bcf2c cmp r3, #1 */
/* @0x1bcf30 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bcf34 ldr r3, [r0, #0x1c] */
/* @0x1bcf38 cmp r3, #0 */
/* @0x1bcf3c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bcf40 ldr r2, [r3, #0x18] */
/* @0x1bcf44 vmov s15, r2 */
/* @0x1bcf48 vcvt.f64.s32 d7, s15 */
/* @0x1bcf4c vmov r2, r3, d7 */
/* @0x1bcf50 stm r5, {r2, r3} */
/* @0x1bcf54 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bcf58 andseq r1, r9, r4, ror r3 */

/* ── FUNC 0x1bcf5c · F_LayerBackgroundGetAlpha(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0x1bcf5c cmp r3, #1 */
/* @0x1bcf60 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bcf64 mov r3, #0 */
/* @0x1bcf68 mov r4, r3 */
/* @0x1bcf6c mov r5, r0 */
/* @0x1bcf70 movt r3, #0xbff0 */
/* @0x1bcf74 str r4, [r0, #0xc] */
/* @0x1bcf78 str r3, [r0, #0x4] */
/* @0x1bcf7c str r4, [r0] */
/* @0x1bcf80 ldr r6, [sp, #0x18] */
/* @0x1bcf84 beq 0x1bcf9c <_Z25F_LayerBackgroundGetAlphaR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bcf88 ldr r0, [pc, #0x6c] */
/* @0x1bcf8c mov r1, r4 */
/* @0x1bcf90 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bcf94 add r0, pc, r0 */
/* @0x1bcf98 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bcf9c str r4, [r0] */
/* @0x1bcfa0 str r4, [r0, #0x4] */
/* @0x1bcfa4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bcfa8 mov r1, r4 */
/* @0x1bcfac mov r7, r0 */
/* @0x1bcfb0 mov r0, r6 */
/* @0x1bcfb4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bcfb8 mov r2, r4 */
/* @0x1bcfbc mov r1, r0 */
/* @0x1bcfc0 mov r0, r7 */
/* @0x1bcfc4 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bcfc8 cmp r0, #0 */
/* @0x1bcfcc popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bcfd0 ldr r3, [r0] */
/* @0x1bcfd4 cmp r3, #1 */
/* @0x1bcfd8 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bcfdc ldr r3, [r0, #0x1c] */
/* @0x1bcfe0 cmp r3, #0 */
/* @0x1bcfe4 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bcfe8 vldr s15, [r3, #28] */
/* @0x1bcfec vcvt.f64.f32 d6, s15 */
/* @0x1bcff0 vmov r2, r3, d6 */
/* @0x1bcff4 stm r5, {r2, r3} */
/* @0x1bcff8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bcffc andseq r1, r9, r8, lsl #6 */

/* ── FUNC 0x1bd000 · F_LayerBackgroundGetIndex(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x1bd000 cmp r3, #1 */
/* @0x1bd004 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bd008 mov r3, #0 */
/* @0x1bd00c mov r4, r3 */
/* @0x1bd010 mov r5, r0 */
/* @0x1bd014 movt r3, #0xbff0 */
/* @0x1bd018 str r4, [r0, #0xc] */
/* @0x1bd01c str r3, [r0, #0x4] */
/* @0x1bd020 str r4, [r0] */
/* @0x1bd024 ldr r6, [sp, #0x18] */
/* @0x1bd028 beq 0x1bd040 <_Z25F_LayerBackgroundGetIndexR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bd02c ldr r0, [pc, #0x64] */
/* @0x1bd030 mov r1, r4 */
/* @0x1bd034 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bd038 add r0, pc, r0 */
/* @0x1bd03c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bd040 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bd044 mov r1, r4 */
/* @0x1bd048 mov r7, r0 */
/* @0x1bd04c mov r0, r6 */
/* @0x1bd050 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bd054 mov r2, r4 */
/* @0x1bd058 mov r1, r0 */
/* @0x1bd05c mov r0, r7 */
/* @0x1bd060 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bd064 cmp r0, #0 */
/* @0x1bd068 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bd06c ldr r3, [r0] */
/* @0x1bd070 cmp r3, #1 */
/* @0x1bd074 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bd078 ldr r3, [r0, #0x1c] */
/* @0x1bd07c cmp r3, #0 */
/* @0x1bd080 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bd084 vldr s15, [r3, #32] */
/* @0x1bd088 vcvt.f64.f32 d6, s15 */
/* @0x1bd08c vmov r2, r3, d6 */
/* @0x1bd090 stm r5, {r2, r3} */
/* @0x1bd094 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bd098 andseq r1, r9, r0, lsr #5 */

/* ── FUNC 0x1bd09c · F_LayerBackgroundGetSpeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0x1bd09c cmp r3, #1 */
/* @0x1bd0a0 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bd0a4 mov r3, #0 */
/* @0x1bd0a8 mov r4, r3 */
/* @0x1bd0ac mov r5, r0 */
/* @0x1bd0b0 movt r3, #0xbff0 */
/* @0x1bd0b4 str r4, [r0, #0xc] */
/* @0x1bd0b8 str r3, [r0, #0x4] */
/* @0x1bd0bc str r4, [r0] */
/* @0x1bd0c0 ldr r6, [sp, #0x18] */
/* @0x1bd0c4 beq 0x1bd0dc <_Z25F_LayerBackgroundGetSpeedR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bd0c8 ldr r0, [pc, #0x6c] */
/* @0x1bd0cc mov r1, r4 */
/* @0x1bd0d0 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bd0d4 add r0, pc, r0 */
/* @0x1bd0d8 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bd0dc str r4, [r0] */
/* @0x1bd0e0 str r4, [r0, #0x4] */
/* @0x1bd0e4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bd0e8 mov r1, r4 */
/* @0x1bd0ec mov r7, r0 */
/* @0x1bd0f0 mov r0, r6 */
/* @0x1bd0f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bd0f8 mov r2, r4 */
/* @0x1bd0fc mov r1, r0 */
/* @0x1bd100 mov r0, r7 */
/* @0x1bd104 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bd108 cmp r0, #0 */
/* @0x1bd10c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bd110 ldr r3, [r0] */
/* @0x1bd114 cmp r3, #1 */
/* @0x1bd118 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bd11c ldr r3, [r0, #0x1c] */
/* @0x1bd120 cmp r3, #0 */
/* @0x1bd124 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bd128 vldr s15, [r3, #36] */
/* @0x1bd12c vcvt.f64.f32 d6, s15 */
/* @0x1bd130 vmov r2, r3, d6 */
/* @0x1bd134 stm r5, {r2, r3} */
/* @0x1bd138 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bd13c andseq r1, r9, r0, asr #4 */

/* ── FUNC 0x1bd140 · F_LayerSpriteChange(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1bd140 cmp r3, #2 */
/* @0x1bd144 mov r3, #0 */
/* @0x1bd148 push {r4, r5, r6, lr} */
/* @0x1bd14c mov r4, r3 */
/* @0x1bd150 ldr r5, [sp, #0x10] */
/* @0x1bd154 movt r3, #0xbff0 */
/* @0x1bd158 str r4, [r0, #0xc] */
/* @0x1bd15c str r3, [r0, #0x4] */
/* @0x1bd160 str r4, [r0] */
/* @0x1bd164 beq 0x1bd17c <_Z19F_LayerSpriteChangeR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bd168 ldr r0, [pc, #0x58] */
/* @0x1bd16c mov r1, r4 */
/* @0x1bd170 pop {r4, r5, r6, lr} */
/* @0x1bd174 add r0, pc, r0 */
/* @0x1bd178 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bd17c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bd180 mov r1, r4 */
/* @0x1bd184 mov r6, r0 */
/* @0x1bd188 mov r0, r5 */
/* @0x1bd18c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bd190 mov r2, r4 */
/* @0x1bd194 mov r1, r0 */
/* @0x1bd198 mov r0, r6 */
/* @0x1bd19c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bd1a0 subs r4, r0, #0 */
/* @0x1bd1a4 popeq {r4, r5, r6, pc} */
/* @0x1bd1a8 ldr r3, [r4] */
/* @0x1bd1ac cmp r3, #4 */
/* @0x1bd1b0 popne {r4, r5, r6, pc} */
/* @0x1bd1b4 mov r0, r5 */
/* @0x1bd1b8 mov r1, #1 */
/* @0x1bd1bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bd1c0 str r0, [r4, #0x1c] */
/* @0x1bd1c4 pop {r4, r5, r6, pc} */
/* @0x1bd1c8 ldrsbeq r1, [r9], -r12 */

/* ── FUNC 0x1bd1cc · F_LayerSpriteIndex(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1bd1cc cmp r3, #2 */
/* @0x1bd1d0 mov r3, #0 */
/* @0x1bd1d4 push {r4, r5, r6, lr} */
/* @0x1bd1d8 mov r4, r3 */
/* @0x1bd1dc ldr r5, [sp, #0x10] */
/* @0x1bd1e0 movt r3, #0xbff0 */
/* @0x1bd1e4 str r4, [r0, #0xc] */
/* @0x1bd1e8 str r3, [r0, #0x4] */
/* @0x1bd1ec str r4, [r0] */
/* @0x1bd1f0 beq 0x1bd208 <_Z18F_LayerSpriteIndexR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bd1f4 ldr r0, [pc, #0x58] */
/* @0x1bd1f8 mov r1, r4 */
/* @0x1bd1fc pop {r4, r5, r6, lr} */
/* @0x1bd200 add r0, pc, r0 */
/* @0x1bd204 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bd208 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bd20c mov r1, r4 */
/* @0x1bd210 mov r6, r0 */
/* @0x1bd214 mov r0, r5 */
/* @0x1bd218 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bd21c mov r2, r4 */
/* @0x1bd220 mov r1, r0 */
/* @0x1bd224 mov r0, r6 */
/* @0x1bd228 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bd22c subs r4, r0, #0 */
/* @0x1bd230 popeq {r4, r5, r6, pc} */
/* @0x1bd234 ldr r3, [r4] */
/* @0x1bd238 cmp r3, #4 */
/* @0x1bd23c popne {r4, r5, r6, pc} */
/* @0x1bd240 mov r0, r5 */
/* @0x1bd244 mov r1, #1 */
/* @0x1bd248 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bd24c str r0, [r4, #0x20] */
/* @0x1bd250 pop {r4, r5, r6, pc} */
/* @0x1bd254 andseq r1, r9, r4, lsl #3 */

/* ── FUNC 0x1bd258 · F_LayerSpriteSpeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1bd258 cmp r3, #2 */
/* @0x1bd25c mov r3, #0 */
/* @0x1bd260 push {r4, r5, r6, lr} */
/* @0x1bd264 mov r4, r3 */
/* @0x1bd268 ldr r5, [sp, #0x10] */
/* @0x1bd26c movt r3, #0xbff0 */
/* @0x1bd270 str r4, [r0, #0xc] */
/* @0x1bd274 str r3, [r0, #0x4] */
/* @0x1bd278 str r4, [r0] */
/* @0x1bd27c beq 0x1bd294 <_Z18F_LayerSpriteSpeedR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bd280 ldr r0, [pc, #0x58] */
/* @0x1bd284 mov r1, r4 */
/* @0x1bd288 pop {r4, r5, r6, lr} */
/* @0x1bd28c add r0, pc, r0 */
/* @0x1bd290 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bd294 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bd298 mov r1, r4 */
/* @0x1bd29c mov r6, r0 */
/* @0x1bd2a0 mov r0, r5 */
/* @0x1bd2a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bd2a8 mov r2, r4 */
/* @0x1bd2ac mov r1, r0 */
/* @0x1bd2b0 mov r0, r6 */
/* @0x1bd2b4 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bd2b8 subs r4, r0, #0 */
/* @0x1bd2bc popeq {r4, r5, r6, pc} */
/* @0x1bd2c0 ldr r3, [r4] */
/* @0x1bd2c4 cmp r3, #4 */
/* @0x1bd2c8 popne {r4, r5, r6, pc} */
/* @0x1bd2cc mov r0, r5 */
/* @0x1bd2d0 mov r1, #1 */
/* @0x1bd2d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bd2d8 str r0, [r4, #0x24] */
/* @0x1bd2dc pop {r4, r5, r6, pc} */
/* @0x1bd2e0 andseq r1, r9, r12, lsr #2 */

/* ── FUNC 0x1bd2e4 · F_LayerSpriteXScale(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1bd2e4 cmp r3, #2 */
/* @0x1bd2e8 mov r3, #0 */
/* @0x1bd2ec push {r4, r5, r6, lr} */
/* @0x1bd2f0 mov r4, r3 */
/* @0x1bd2f4 ldr r5, [sp, #0x10] */
/* @0x1bd2f8 movt r3, #0xbff0 */
/* @0x1bd2fc str r4, [r0, #0xc] */
/* @0x1bd300 str r3, [r0, #0x4] */
/* @0x1bd304 str r4, [r0] */
/* @0x1bd308 beq 0x1bd320 <_Z19F_LayerSpriteXScaleR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bd30c ldr r0, [pc, #0x58] */
/* @0x1bd310 mov r1, r4 */
/* @0x1bd314 pop {r4, r5, r6, lr} */
/* @0x1bd318 add r0, pc, r0 */
/* @0x1bd31c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bd320 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bd324 mov r1, r4 */
/* @0x1bd328 mov r6, r0 */
/* @0x1bd32c mov r0, r5 */
/* @0x1bd330 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bd334 mov r2, r4 */
/* @0x1bd338 mov r1, r0 */
/* @0x1bd33c mov r0, r6 */
/* @0x1bd340 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bd344 subs r4, r0, #0 */
/* @0x1bd348 popeq {r4, r5, r6, pc} */
/* @0x1bd34c ldr r3, [r4] */
/* @0x1bd350 cmp r3, #4 */
/* @0x1bd354 popne {r4, r5, r6, pc} */
/* @0x1bd358 mov r0, r5 */
/* @0x1bd35c mov r1, #1 */
/* @0x1bd360 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bd364 str r0, [r4, #0x2c] */
/* @0x1bd368 pop {r4, r5, r6, pc} */
/* @0x1bd36c ldrsbeq r1, [r9], -r4 */

/* ── FUNC 0x1bd370 · F_LayerSpriteYScale(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1bd370 cmp r3, #2 */
/* @0x1bd374 mov r3, #0 */
/* @0x1bd378 push {r4, r5, r6, lr} */
/* @0x1bd37c mov r4, r3 */
/* @0x1bd380 ldr r5, [sp, #0x10] */
/* @0x1bd384 movt r3, #0xbff0 */
/* @0x1bd388 str r4, [r0, #0xc] */
/* @0x1bd38c str r3, [r0, #0x4] */
/* @0x1bd390 str r4, [r0] */
/* @0x1bd394 beq 0x1bd3ac <_Z19F_LayerSpriteYScaleR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bd398 ldr r0, [pc, #0x58] */
/* @0x1bd39c mov r1, r4 */
/* @0x1bd3a0 pop {r4, r5, r6, lr} */
/* @0x1bd3a4 add r0, pc, r0 */
/* @0x1bd3a8 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bd3ac bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bd3b0 mov r1, r4 */
/* @0x1bd3b4 mov r6, r0 */
/* @0x1bd3b8 mov r0, r5 */
/* @0x1bd3bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bd3c0 mov r2, r4 */
/* @0x1bd3c4 mov r1, r0 */
/* @0x1bd3c8 mov r0, r6 */
/* @0x1bd3cc bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bd3d0 subs r4, r0, #0 */
/* @0x1bd3d4 popeq {r4, r5, r6, pc} */
/* @0x1bd3d8 ldr r3, [r4] */
/* @0x1bd3dc cmp r3, #4 */
/* @0x1bd3e0 popne {r4, r5, r6, pc} */
/* @0x1bd3e4 mov r0, r5 */
/* @0x1bd3e8 mov r1, #1 */
/* @0x1bd3ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bd3f0 str r0, [r4, #0x30] */
/* @0x1bd3f4 pop {r4, r5, r6, pc} */
/* @0x1bd3f8 andseq r1, r9, r12, ror r0 */

/* ── FUNC 0x1bd3fc · F_LayerSpriteAngle(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1bd3fc cmp r3, #2 */
/* @0x1bd400 mov r3, #0 */
/* @0x1bd404 push {r4, r5, r6, lr} */
/* @0x1bd408 mov r4, r3 */
/* @0x1bd40c ldr r5, [sp, #0x10] */
/* @0x1bd410 movt r3, #0xbff0 */
/* @0x1bd414 str r4, [r0, #0xc] */
/* @0x1bd418 str r3, [r0, #0x4] */
/* @0x1bd41c str r4, [r0] */
/* @0x1bd420 beq 0x1bd438 <_Z18F_LayerSpriteAngleR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bd424 ldr r0, [pc, #0x58] */
/* @0x1bd428 mov r1, r4 */
/* @0x1bd42c pop {r4, r5, r6, lr} */
/* @0x1bd430 add r0, pc, r0 */
/* @0x1bd434 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bd438 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bd43c mov r1, r4 */
/* @0x1bd440 mov r6, r0 */
/* @0x1bd444 mov r0, r5 */
/* @0x1bd448 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bd44c mov r2, r4 */
/* @0x1bd450 mov r1, r0 */
/* @0x1bd454 mov r0, r6 */
/* @0x1bd458 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bd45c subs r4, r0, #0 */
/* @0x1bd460 popeq {r4, r5, r6, pc} */
/* @0x1bd464 ldr r3, [r4] */
/* @0x1bd468 cmp r3, #4 */
/* @0x1bd46c popne {r4, r5, r6, pc} */
/* @0x1bd470 mov r0, r5 */
/* @0x1bd474 mov r1, #1 */
/* @0x1bd478 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bd47c str r0, [r4, #0x34] */
/* @0x1bd480 pop {r4, r5, r6, pc} */
/* @0x1bd484 andseq r1, r9, r4, lsr #32 */

/* ── FUNC 0x1bd488 · F_LayerSpriteBlend(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1bd488 cmp r3, #2 */
/* @0x1bd48c mov r3, #0 */
/* @0x1bd490 push {r4, r5, r6, lr} */
/* @0x1bd494 mov r4, r3 */
/* @0x1bd498 ldr r5, [sp, #0x10] */
/* @0x1bd49c movt r3, #0xbff0 */
/* @0x1bd4a0 str r4, [r0, #0xc] */
/* @0x1bd4a4 str r3, [r0, #0x4] */
/* @0x1bd4a8 str r4, [r0] */
/* @0x1bd4ac beq 0x1bd4c4 <_Z18F_LayerSpriteBlendR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bd4b0 ldr r0, [pc, #0x58] */
/* @0x1bd4b4 mov r1, r4 */
/* @0x1bd4b8 pop {r4, r5, r6, lr} */
/* @0x1bd4bc add r0, pc, r0 */
/* @0x1bd4c0 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bd4c4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bd4c8 mov r1, r4 */
/* @0x1bd4cc mov r6, r0 */
/* @0x1bd4d0 mov r0, r5 */
/* @0x1bd4d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bd4d8 mov r2, r4 */
/* @0x1bd4dc mov r1, r0 */
/* @0x1bd4e0 mov r0, r6 */
/* @0x1bd4e4 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bd4e8 subs r4, r0, #0 */
/* @0x1bd4ec popeq {r4, r5, r6, pc} */
/* @0x1bd4f0 ldr r3, [r4] */
/* @0x1bd4f4 cmp r3, #4 */
/* @0x1bd4f8 popne {r4, r5, r6, pc} */
/* @0x1bd4fc mov r0, r5 */
/* @0x1bd500 mov r1, #1 */
/* @0x1bd504 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bd508 str r0, [r4, #0x38] */
/* @0x1bd50c pop {r4, r5, r6, pc} */
/* @0x1bd510 andseq r0, r9, r12, asr #31 */

/* ── FUNC 0x1bd514 · F_LayerSpriteAlpha(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1bd514 cmp r3, #2 */
/* @0x1bd518 mov r3, #0 */
/* @0x1bd51c push {r4, r5, r6, lr} */
/* @0x1bd520 mov r4, r3 */
/* @0x1bd524 ldr r5, [sp, #0x10] */
/* @0x1bd528 movt r3, #0xbff0 */
/* @0x1bd52c str r4, [r0, #0xc] */
/* @0x1bd530 str r3, [r0, #0x4] */
/* @0x1bd534 str r4, [r0] */
/* @0x1bd538 beq 0x1bd550 <_Z18F_LayerSpriteAlphaR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bd53c ldr r0, [pc, #0x58] */
/* @0x1bd540 mov r1, r4 */
/* @0x1bd544 pop {r4, r5, r6, lr} */
/* @0x1bd548 add r0, pc, r0 */
/* @0x1bd54c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bd550 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bd554 mov r1, r4 */
/* @0x1bd558 mov r6, r0 */
/* @0x1bd55c mov r0, r5 */
/* @0x1bd560 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bd564 mov r2, r4 */
/* @0x1bd568 mov r1, r0 */
/* @0x1bd56c mov r0, r6 */
/* @0x1bd570 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bd574 subs r4, r0, #0 */
/* @0x1bd578 popeq {r4, r5, r6, pc} */
/* @0x1bd57c ldr r3, [r4] */
/* @0x1bd580 cmp r3, #4 */
/* @0x1bd584 popne {r4, r5, r6, pc} */
/* @0x1bd588 mov r0, r5 */
/* @0x1bd58c mov r1, #1 */
/* @0x1bd590 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bd594 str r0, [r4, #0x3c] */
/* @0x1bd598 pop {r4, r5, r6, pc} */
/* @0x1bd59c andseq r0, r9, r4, ror pc */

/* ── FUNC 0x1bd5a0 · F_LayerSpriteX(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1bd5a0 cmp r3, #2 */
/* @0x1bd5a4 mov r3, #0 */
/* @0x1bd5a8 push {r4, r5, r6, lr} */
/* @0x1bd5ac mov r4, r3 */
/* @0x1bd5b0 ldr r5, [sp, #0x10] */
/* @0x1bd5b4 movt r3, #0xbff0 */
/* @0x1bd5b8 str r4, [r0, #0xc] */
/* @0x1bd5bc str r3, [r0, #0x4] */
/* @0x1bd5c0 str r4, [r0] */
/* @0x1bd5c4 beq 0x1bd5dc <_Z14F_LayerSpriteXR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bd5c8 ldr r0, [pc, #0x58] */
/* @0x1bd5cc mov r1, r4 */
/* @0x1bd5d0 pop {r4, r5, r6, lr} */
/* @0x1bd5d4 add r0, pc, r0 */
/* @0x1bd5d8 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bd5dc bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bd5e0 mov r1, r4 */
/* @0x1bd5e4 mov r6, r0 */
/* @0x1bd5e8 mov r0, r5 */
/* @0x1bd5ec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bd5f0 mov r2, r4 */
/* @0x1bd5f4 mov r1, r0 */
/* @0x1bd5f8 mov r0, r6 */
/* @0x1bd5fc bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bd600 subs r4, r0, #0 */
/* @0x1bd604 popeq {r4, r5, r6, pc} */
/* @0x1bd608 ldr r3, [r4] */
/* @0x1bd60c cmp r3, #4 */
/* @0x1bd610 popne {r4, r5, r6, pc} */
/* @0x1bd614 mov r0, r5 */
/* @0x1bd618 mov r1, #1 */
/* @0x1bd61c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bd620 str r0, [r4, #0x40] */
/* @0x1bd624 pop {r4, r5, r6, pc} */
/* @0x1bd628 andseq r0, r9, r12, lsl pc */

/* ── FUNC 0x1bd62c · F_LayerSpriteY(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1bd62c cmp r3, #2 */
/* @0x1bd630 mov r3, #0 */
/* @0x1bd634 push {r4, r5, r6, lr} */
/* @0x1bd638 mov r4, r3 */
/* @0x1bd63c ldr r5, [sp, #0x10] */
/* @0x1bd640 movt r3, #0xbff0 */
/* @0x1bd644 str r4, [r0, #0xc] */
/* @0x1bd648 str r3, [r0, #0x4] */
/* @0x1bd64c str r4, [r0] */
/* @0x1bd650 beq 0x1bd668 <_Z14F_LayerSpriteYR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bd654 ldr r0, [pc, #0x58] */
/* @0x1bd658 mov r1, r4 */
/* @0x1bd65c pop {r4, r5, r6, lr} */
/* @0x1bd660 add r0, pc, r0 */
/* @0x1bd664 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bd668 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bd66c mov r1, r4 */
/* @0x1bd670 mov r6, r0 */
/* @0x1bd674 mov r0, r5 */
/* @0x1bd678 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bd67c mov r2, r4 */
/* @0x1bd680 mov r1, r0 */
/* @0x1bd684 mov r0, r6 */
/* @0x1bd688 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bd68c subs r4, r0, #0 */
/* @0x1bd690 popeq {r4, r5, r6, pc} */
/* @0x1bd694 ldr r3, [r4] */
/* @0x1bd698 cmp r3, #4 */
/* @0x1bd69c popne {r4, r5, r6, pc} */
/* @0x1bd6a0 mov r0, r5 */
/* @0x1bd6a4 mov r1, #1 */
/* @0x1bd6a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bd6ac str r0, [r4, #0x44] */
/* @0x1bd6b0 pop {r4, r5, r6, pc} */
/* @0x1bd6b4 andseq r0, r9, r0, asr #29 */

/* ── FUNC 0x1bd6b8 · F_LayerSpriteGetSprite(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1bd6b8 cmp r3, #1 */
/* @0x1bd6bc push {r3, r4, r5, r6, r7, lr} */
/* @0x1bd6c0 mov r3, #0 */
/* @0x1bd6c4 mov r4, r3 */
/* @0x1bd6c8 mov r5, r0 */
/* @0x1bd6cc movt r3, #0xbff0 */
/* @0x1bd6d0 str r4, [r0, #0xc] */
/* @0x1bd6d4 str r3, [r0, #0x4] */
/* @0x1bd6d8 str r4, [r0] */
/* @0x1bd6dc ldr r6, [sp, #0x18] */
/* @0x1bd6e0 beq 0x1bd6f8 <_Z22F_LayerSpriteGetSpriteR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bd6e4 ldr r0, [pc, #0x5c] */
/* @0x1bd6e8 mov r1, r4 */
/* @0x1bd6ec pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bd6f0 add r0, pc, r0 */
/* @0x1bd6f4 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bd6f8 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bd6fc mov r1, r4 */
/* @0x1bd700 mov r7, r0 */
/* @0x1bd704 mov r0, r6 */
/* @0x1bd708 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bd70c mov r2, r4 */
/* @0x1bd710 mov r1, r0 */
/* @0x1bd714 mov r0, r7 */
/* @0x1bd718 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bd71c cmp r0, #0 */
/* @0x1bd720 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bd724 ldr r3, [r0] */
/* @0x1bd728 cmp r3, #4 */
/* @0x1bd72c popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bd730 ldr r2, [r0, #0x1c] */
/* @0x1bd734 vmov s15, r2 */
/* @0x1bd738 vcvt.f64.s32 d7, s15 */
/* @0x1bd73c vmov r2, r3, d7 */
/* @0x1bd740 stm r5, {r2, r3} */
/* @0x1bd744 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bd748 andseq r0, r9, r0, ror #28 */

/* ── FUNC 0x1bd74c · F_LayerSpriteGetIndex(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x1bd74c cmp r3, #1 */
/* @0x1bd750 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bd754 mov r3, #0 */
/* @0x1bd758 mov r4, r3 */
/* @0x1bd75c mov r5, r0 */
/* @0x1bd760 movt r3, #0xbff0 */
/* @0x1bd764 str r4, [r0, #0xc] */
/* @0x1bd768 str r3, [r0, #0x4] */
/* @0x1bd76c str r4, [r0] */
/* @0x1bd770 ldr r6, [sp, #0x18] */
/* @0x1bd774 beq 0x1bd78c <_Z21F_LayerSpriteGetIndexR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bd778 ldr r0, [pc, #0x58] */
/* @0x1bd77c mov r1, r4 */
/* @0x1bd780 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bd784 add r0, pc, r0 */
/* @0x1bd788 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bd78c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bd790 mov r1, r4 */
/* @0x1bd794 mov r7, r0 */
/* @0x1bd798 mov r0, r6 */
/* @0x1bd79c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bd7a0 mov r2, r4 */
/* @0x1bd7a4 mov r1, r0 */
/* @0x1bd7a8 mov r0, r7 */
/* @0x1bd7ac bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bd7b0 cmp r0, #0 */
/* @0x1bd7b4 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bd7b8 ldr r3, [r0] */
/* @0x1bd7bc cmp r3, #4 */
/* @0x1bd7c0 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bd7c4 vldr s15, [r0, #32] */
/* @0x1bd7c8 vcvt.f64.f32 d6, s15 */
/* @0x1bd7cc vmov r2, r3, d6 */
/* @0x1bd7d0 stm r5, {r2, r3} */
/* @0x1bd7d4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bd7d8 andseq r0, r9, r4, lsl #28 */

/* ── FUNC 0x1bd7dc · F_LayerSpriteGetSpeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x1bd7dc cmp r3, #1 */
/* @0x1bd7e0 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bd7e4 mov r3, #0 */
/* @0x1bd7e8 mov r4, r3 */
/* @0x1bd7ec mov r5, r0 */
/* @0x1bd7f0 movt r3, #0xbff0 */
/* @0x1bd7f4 str r4, [r0, #0xc] */
/* @0x1bd7f8 str r3, [r0, #0x4] */
/* @0x1bd7fc str r4, [r0] */
/* @0x1bd800 ldr r6, [sp, #0x18] */
/* @0x1bd804 beq 0x1bd81c <_Z21F_LayerSpriteGetSpeedR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bd808 ldr r0, [pc, #0x60] */
/* @0x1bd80c mov r1, r4 */
/* @0x1bd810 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bd814 add r0, pc, r0 */
/* @0x1bd818 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bd81c str r4, [r0] */
/* @0x1bd820 str r4, [r0, #0x4] */
/* @0x1bd824 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bd828 mov r1, r4 */
/* @0x1bd82c mov r7, r0 */
/* @0x1bd830 mov r0, r6 */
/* @0x1bd834 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bd838 mov r2, r4 */
/* @0x1bd83c mov r1, r0 */
/* @0x1bd840 mov r0, r7 */
/* @0x1bd844 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bd848 cmp r0, #0 */
/* @0x1bd84c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bd850 ldr r3, [r0] */
/* @0x1bd854 cmp r3, #4 */
/* @0x1bd858 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bd85c vldr s15, [r0, #36] */
/* @0x1bd860 vcvt.f64.f32 d6, s15 */
/* @0x1bd864 vmov r2, r3, d6 */
/* @0x1bd868 stm r5, {r2, r3} */
/* @0x1bd86c pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bd870 andseq r0, r9, r12, lsr #27 */

/* ── FUNC 0x1bd874 · F_LayerSpriteGetXScale(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x1bd874 cmp r3, #1 */
/* @0x1bd878 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bd87c mov r3, #0 */
/* @0x1bd880 mov r5, r3 */
/* @0x1bd884 mov r4, r0 */
/* @0x1bd888 movt r3, #0xbff0 */
/* @0x1bd88c str r5, [r0, #0xc] */
/* @0x1bd890 str r3, [r0, #0x4] */
/* @0x1bd894 str r5, [r0] */
/* @0x1bd898 ldr r6, [sp, #0x18] */
/* @0x1bd89c beq 0x1bd8b4 <_Z22F_LayerSpriteGetXScaleR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bd8a0 ldr r0, [pc, #0x68] */
/* @0x1bd8a4 mov r1, r5 */
/* @0x1bd8a8 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bd8ac add r0, pc, r0 */
/* @0x1bd8b0 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bd8b4 str r5, [r0] */
/* @0x1bd8b8 mov r3, #0 */
/* @0x1bd8bc movt r3, #0x3ff0 */
/* @0x1bd8c0 str r3, [r0, #0x4] */
/* @0x1bd8c4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bd8c8 mov r1, r5 */
/* @0x1bd8cc mov r7, r0 */
/* @0x1bd8d0 mov r0, r6 */
/* @0x1bd8d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bd8d8 mov r2, r5 */
/* @0x1bd8dc mov r1, r0 */
/* @0x1bd8e0 mov r0, r7 */
/* @0x1bd8e4 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bd8e8 cmp r0, #0 */
/* @0x1bd8ec popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bd8f0 ldr r3, [r0] */
/* @0x1bd8f4 cmp r3, #4 */
/* @0x1bd8f8 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bd8fc vldr s15, [r0, #44] */
/* @0x1bd900 vcvt.f64.f32 d6, s15 */
/* @0x1bd904 vmov r2, r3, d6 */
/* @0x1bd908 stm r4, {r2, r3} */
/* @0x1bd90c pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bd910 andseq r0, r9, r12, asr #26 */

/* ── FUNC 0x1bd914 · F_LayerSpriteGetYScale(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x1bd914 cmp r3, #1 */
/* @0x1bd918 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bd91c mov r3, #0 */
/* @0x1bd920 mov r5, r3 */
/* @0x1bd924 mov r4, r0 */
/* @0x1bd928 movt r3, #0xbff0 */
/* @0x1bd92c str r5, [r0, #0xc] */
/* @0x1bd930 str r3, [r0, #0x4] */
/* @0x1bd934 str r5, [r0] */
/* @0x1bd938 ldr r6, [sp, #0x18] */
/* @0x1bd93c beq 0x1bd954 <_Z22F_LayerSpriteGetYScaleR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bd940 ldr r0, [pc, #0x68] */
/* @0x1bd944 mov r1, r5 */
/* @0x1bd948 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bd94c add r0, pc, r0 */
/* @0x1bd950 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bd954 str r5, [r0] */
/* @0x1bd958 mov r3, #0 */
/* @0x1bd95c movt r3, #0x3ff0 */
/* @0x1bd960 str r3, [r0, #0x4] */
/* @0x1bd964 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bd968 mov r1, r5 */
/* @0x1bd96c mov r7, r0 */
/* @0x1bd970 mov r0, r6 */
/* @0x1bd974 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bd978 mov r2, r5 */
/* @0x1bd97c mov r1, r0 */
/* @0x1bd980 mov r0, r7 */
/* @0x1bd984 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bd988 cmp r0, #0 */
/* @0x1bd98c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bd990 ldr r3, [r0] */
/* @0x1bd994 cmp r3, #4 */
/* @0x1bd998 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bd99c vldr s15, [r0, #48] */
/* @0x1bd9a0 vcvt.f64.f32 d6, s15 */
/* @0x1bd9a4 vmov r2, r3, d6 */
/* @0x1bd9a8 stm r4, {r2, r3} */
/* @0x1bd9ac pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bd9b0 andseq r0, r9, r4, ror #25 */

/* ── FUNC 0x1bd9b4 · F_LayerSpriteGetAngle(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x1bd9b4 cmp r3, #1 */
/* @0x1bd9b8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bd9bc mov r3, #0 */
/* @0x1bd9c0 mov r4, r3 */
/* @0x1bd9c4 mov r5, r0 */
/* @0x1bd9c8 movt r3, #0xbff0 */
/* @0x1bd9cc str r4, [r0, #0xc] */
/* @0x1bd9d0 str r3, [r0, #0x4] */
/* @0x1bd9d4 str r4, [r0] */
/* @0x1bd9d8 ldr r6, [sp, #0x18] */
/* @0x1bd9dc beq 0x1bd9f4 <_Z21F_LayerSpriteGetAngleR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bd9e0 ldr r0, [pc, #0x60] */
/* @0x1bd9e4 mov r1, r4 */
/* @0x1bd9e8 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bd9ec add r0, pc, r0 */
/* @0x1bd9f0 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bd9f4 str r4, [r0] */
/* @0x1bd9f8 str r4, [r0, #0x4] */
/* @0x1bd9fc bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bda00 mov r1, r4 */
/* @0x1bda04 mov r7, r0 */
/* @0x1bda08 mov r0, r6 */
/* @0x1bda0c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bda10 mov r2, r4 */
/* @0x1bda14 mov r1, r0 */
/* @0x1bda18 mov r0, r7 */
/* @0x1bda1c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bda20 cmp r0, #0 */
/* @0x1bda24 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bda28 ldr r3, [r0] */
/* @0x1bda2c cmp r3, #4 */
/* @0x1bda30 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bda34 vldr s15, [r0, #52] */
/* @0x1bda38 vcvt.f64.f32 d6, s15 */
/* @0x1bda3c vmov r2, r3, d6 */
/* @0x1bda40 stm r5, {r2, r3} */
/* @0x1bda44 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bda48 andseq r0, r9, r12, ror r12 */

/* ── FUNC 0x1bda4c · F_LayerSpriteGetBlend(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x1bda4c cmp r3, #1 */
/* @0x1bda50 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bda54 mov r3, #0 */
/* @0x1bda58 mov r4, r3 */
/* @0x1bda5c mov r5, r0 */
/* @0x1bda60 movt r3, #0xbff0 */
/* @0x1bda64 str r4, [r0, #0xc] */
/* @0x1bda68 str r3, [r0, #0x4] */
/* @0x1bda6c str r4, [r0] */
/* @0x1bda70 ldr r6, [sp, #0x18] */
/* @0x1bda74 beq 0x1bda8c <_Z21F_LayerSpriteGetBlendR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bda78 ldr r0, [pc, #0x64] */
/* @0x1bda7c mov r1, r4 */
/* @0x1bda80 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bda84 add r0, pc, r0 */
/* @0x1bda88 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bda8c str r4, [r0] */
/* @0x1bda90 str r4, [r0, #0x4] */
/* @0x1bda94 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bda98 mov r1, r4 */
/* @0x1bda9c mov r7, r0 */
/* @0x1bdaa0 mov r0, r6 */
/* @0x1bdaa4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bdaa8 mov r2, r4 */
/* @0x1bdaac mov r1, r0 */
/* @0x1bdab0 mov r0, r7 */
/* @0x1bdab4 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bdab8 cmp r0, #0 */
/* @0x1bdabc popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bdac0 ldr r3, [r0] */
/* @0x1bdac4 cmp r3, #4 */
/* @0x1bdac8 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bdacc ldr r2, [r0, #0x38] */
/* @0x1bdad0 vmov s15, r2 */
/* @0x1bdad4 vcvt.f64.u32 d7, s15 */
/* @0x1bdad8 vmov r2, r3, d7 */
/* @0x1bdadc stm r5, {r2, r3} */
/* @0x1bdae0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bdae4 andseq r0, r9, r12, lsl r12 */

/* ── FUNC 0x1bdae8 · F_LayerSpriteGetAlpha(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x1bdae8 cmp r3, #1 */
/* @0x1bdaec push {r3, r4, r5, r6, r7, lr} */
/* @0x1bdaf0 mov r3, #0 */
/* @0x1bdaf4 mov r4, r3 */
/* @0x1bdaf8 mov r5, r0 */
/* @0x1bdafc movt r3, #0xbff0 */
/* @0x1bdb00 str r4, [r0, #0xc] */
/* @0x1bdb04 str r3, [r0, #0x4] */
/* @0x1bdb08 str r4, [r0] */
/* @0x1bdb0c ldr r6, [sp, #0x18] */
/* @0x1bdb10 beq 0x1bdb28 <_Z21F_LayerSpriteGetAlphaR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bdb14 ldr r0, [pc, #0x60] */
/* @0x1bdb18 mov r1, r4 */
/* @0x1bdb1c pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bdb20 add r0, pc, r0 */
/* @0x1bdb24 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bdb28 str r4, [r0] */
/* @0x1bdb2c str r4, [r0, #0x4] */
/* @0x1bdb30 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bdb34 mov r1, r4 */
/* @0x1bdb38 mov r7, r0 */
/* @0x1bdb3c mov r0, r6 */
/* @0x1bdb40 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bdb44 mov r2, r4 */
/* @0x1bdb48 mov r1, r0 */
/* @0x1bdb4c mov r0, r7 */
/* @0x1bdb50 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bdb54 cmp r0, #0 */
/* @0x1bdb58 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bdb5c ldr r3, [r0] */
/* @0x1bdb60 cmp r3, #4 */
/* @0x1bdb64 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bdb68 vldr s15, [r0, #60] */
/* @0x1bdb6c vcvt.f64.f32 d6, s15 */
/* @0x1bdb70 vmov r2, r3, d6 */
/* @0x1bdb74 stm r5, {r2, r3} */
/* @0x1bdb78 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bdb7c ldrheq r0, [r9], -r8 */

/* ── FUNC 0x1bdb80 · F_LayerSpriteGetX(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x1bdb80 cmp r3, #1 */
/* @0x1bdb84 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bdb88 mov r3, #0 */
/* @0x1bdb8c mov r4, r3 */
/* @0x1bdb90 mov r5, r0 */
/* @0x1bdb94 movt r3, #0xbff0 */
/* @0x1bdb98 str r4, [r0, #0xc] */
/* @0x1bdb9c str r3, [r0, #0x4] */
/* @0x1bdba0 str r4, [r0] */
/* @0x1bdba4 ldr r6, [sp, #0x18] */
/* @0x1bdba8 beq 0x1bdbc0 <_Z17F_LayerSpriteGetXR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bdbac ldr r0, [pc, #0x60] */
/* @0x1bdbb0 mov r1, r4 */
/* @0x1bdbb4 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bdbb8 add r0, pc, r0 */
/* @0x1bdbbc b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bdbc0 str r4, [r0] */
/* @0x1bdbc4 str r4, [r0, #0x4] */
/* @0x1bdbc8 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bdbcc mov r1, r4 */
/* @0x1bdbd0 mov r7, r0 */
/* @0x1bdbd4 mov r0, r6 */
/* @0x1bdbd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bdbdc mov r2, r4 */
/* @0x1bdbe0 mov r1, r0 */
/* @0x1bdbe4 mov r0, r7 */
/* @0x1bdbe8 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bdbec cmp r0, #0 */
/* @0x1bdbf0 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bdbf4 ldr r3, [r0] */
/* @0x1bdbf8 cmp r3, #4 */
/* @0x1bdbfc popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bdc00 vldr s15, [r0, #64] */
/* @0x1bdc04 vcvt.f64.f32 d6, s15 */
/* @0x1bdc08 vmov r2, r3, d6 */
/* @0x1bdc0c stm r5, {r2, r3} */
/* @0x1bdc10 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bdc14 andseq r0, r9, r8, asr r11 */

/* ── FUNC 0x1bdc18 · F_LayerSpriteGetY(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x1bdc18 cmp r3, #1 */
/* @0x1bdc1c push {r3, r4, r5, r6, r7, lr} */
/* @0x1bdc20 mov r3, #0 */
/* @0x1bdc24 mov r4, r3 */
/* @0x1bdc28 mov r5, r0 */
/* @0x1bdc2c movt r3, #0xbff0 */
/* @0x1bdc30 str r4, [r0, #0xc] */
/* @0x1bdc34 str r3, [r0, #0x4] */
/* @0x1bdc38 str r4, [r0] */
/* @0x1bdc3c ldr r6, [sp, #0x18] */
/* @0x1bdc40 beq 0x1bdc58 <_Z17F_LayerSpriteGetYR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bdc44 ldr r0, [pc, #0x60] */
/* @0x1bdc48 mov r1, r4 */
/* @0x1bdc4c pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bdc50 add r0, pc, r0 */
/* @0x1bdc54 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bdc58 str r4, [r0] */
/* @0x1bdc5c str r4, [r0, #0x4] */
/* @0x1bdc60 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bdc64 mov r1, r4 */
/* @0x1bdc68 mov r7, r0 */
/* @0x1bdc6c mov r0, r6 */
/* @0x1bdc70 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bdc74 mov r2, r4 */
/* @0x1bdc78 mov r1, r0 */
/* @0x1bdc7c mov r0, r7 */
/* @0x1bdc80 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bdc84 cmp r0, #0 */
/* @0x1bdc88 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bdc8c ldr r3, [r0] */
/* @0x1bdc90 cmp r3, #4 */
/* @0x1bdc94 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bdc98 vldr s15, [r0, #68] */
/* @0x1bdc9c vcvt.f64.f32 d6, s15 */
/* @0x1bdca0 vmov r2, r3, d6 */
/* @0x1bdca4 stm r5, {r2, r3} */
/* @0x1bdca8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bdcac ldrsheq r0, [r9], -r4 */

/* ── FUNC 0x1bdcb0 · F_TilemapTileset(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1bdcb0 cmp r3, #2 */
/* @0x1bdcb4 mov r3, #0 */
/* @0x1bdcb8 push {r4, r5, r6, lr} */
/* @0x1bdcbc mov r4, r3 */
/* @0x1bdcc0 ldr r5, [sp, #0x10] */
/* @0x1bdcc4 movt r3, #0xbff0 */
/* @0x1bdcc8 str r4, [r0, #0xc] */
/* @0x1bdccc str r3, [r0, #0x4] */
/* @0x1bdcd0 str r4, [r0] */
/* @0x1bdcd4 beq 0x1bdcec <_Z16F_TilemapTilesetR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bdcd8 ldr r0, [pc, #0x58] */
/* @0x1bdcdc mov r1, r4 */
/* @0x1bdce0 pop {r4, r5, r6, lr} */
/* @0x1bdce4 add r0, pc, r0 */
/* @0x1bdce8 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bdcec bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bdcf0 mov r1, r4 */
/* @0x1bdcf4 mov r6, r0 */
/* @0x1bdcf8 mov r0, r5 */
/* @0x1bdcfc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bdd00 mov r2, r4 */
/* @0x1bdd04 mov r1, r0 */
/* @0x1bdd08 mov r0, r6 */
/* @0x1bdd0c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bdd10 subs r4, r0, #0 */
/* @0x1bdd14 popeq {r4, r5, r6, pc} */
/* @0x1bdd18 ldr r3, [r4] */
/* @0x1bdd1c cmp r3, #5 */
/* @0x1bdd20 popne {r4, r5, r6, pc} */
/* @0x1bdd24 mov r0, r5 */
/* @0x1bdd28 mov r1, #1 */
/* @0x1bdd2c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bdd30 str r0, [r4, #0x1c] */
/* @0x1bdd34 pop {r4, r5, r6, pc} */
/* @0x1bdd38 mulseq r9, r4, r10 */

/* ── FUNC 0x1bdd3c · F_TilemapX(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1bdd3c cmp r3, #2 */
/* @0x1bdd40 mov r3, #0 */
/* @0x1bdd44 push {r4, r5, r6, lr} */
/* @0x1bdd48 mov r4, r3 */
/* @0x1bdd4c ldr r5, [sp, #0x10] */
/* @0x1bdd50 movt r3, #0xbff0 */
/* @0x1bdd54 str r4, [r0, #0xc] */
/* @0x1bdd58 str r3, [r0, #0x4] */
/* @0x1bdd5c str r4, [r0] */
/* @0x1bdd60 beq 0x1bdd78 <_Z10F_TilemapXR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bdd64 ldr r0, [pc, #0x58] */
/* @0x1bdd68 mov r1, r4 */
/* @0x1bdd6c pop {r4, r5, r6, lr} */
/* @0x1bdd70 add r0, pc, r0 */
/* @0x1bdd74 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bdd78 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bdd7c mov r1, r4 */
/* @0x1bdd80 mov r6, r0 */
/* @0x1bdd84 mov r0, r5 */
/* @0x1bdd88 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bdd8c mov r2, r4 */
/* @0x1bdd90 mov r1, r0 */
/* @0x1bdd94 mov r0, r6 */
/* @0x1bdd98 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bdd9c subs r4, r0, #0 */
/* @0x1bdda0 popeq {r4, r5, r6, pc} */
/* @0x1bdda4 ldr r3, [r4] */
/* @0x1bdda8 cmp r3, #5 */
/* @0x1bddac popne {r4, r5, r6, pc} */
/* @0x1bddb0 mov r0, r5 */
/* @0x1bddb4 mov r1, #1 */
/* @0x1bddb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bddbc str r0, [r4, #0x20] */
/* @0x1bddc0 pop {r4, r5, r6, pc} */
/* @0x1bddc4 andseq r0, r9, r8, lsr r10 */

/* ── FUNC 0x1bddc8 · F_TilemapY(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1bddc8 cmp r3, #2 */
/* @0x1bddcc mov r3, #0 */
/* @0x1bddd0 push {r4, r5, r6, lr} */
/* @0x1bddd4 mov r4, r3 */
/* @0x1bddd8 ldr r5, [sp, #0x10] */
/* @0x1bdddc movt r3, #0xbff0 */
/* @0x1bdde0 str r4, [r0, #0xc] */
/* @0x1bdde4 str r3, [r0, #0x4] */
/* @0x1bdde8 str r4, [r0] */
/* @0x1bddec beq 0x1bde04 <_Z10F_TilemapYR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bddf0 ldr r0, [pc, #0x58] */
/* @0x1bddf4 mov r1, r4 */
/* @0x1bddf8 pop {r4, r5, r6, lr} */
/* @0x1bddfc add r0, pc, r0 */
/* @0x1bde00 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bde04 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bde08 mov r1, r4 */
/* @0x1bde0c mov r6, r0 */
/* @0x1bde10 mov r0, r5 */
/* @0x1bde14 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bde18 mov r2, r4 */
/* @0x1bde1c mov r1, r0 */
/* @0x1bde20 mov r0, r6 */
/* @0x1bde24 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bde28 subs r4, r0, #0 */
/* @0x1bde2c popeq {r4, r5, r6, pc} */
/* @0x1bde30 ldr r3, [r4] */
/* @0x1bde34 cmp r3, #5 */
/* @0x1bde38 popne {r4, r5, r6, pc} */
/* @0x1bde3c mov r0, r5 */
/* @0x1bde40 mov r1, #1 */
/* @0x1bde44 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bde48 str r0, [r4, #0x24] */
/* @0x1bde4c pop {r4, r5, r6, pc} */
/* @0x1bde50 ldrsbeq r0, [r9], -r4 */

/* ── FUNC 0x1bde54 · F_TilemapSet(RValue&, CInstance*, CInstance*, int, RValue*) · size=412 · insn=103 */
/* @0x1bde54 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1bde58 cmp r3, #4 */
/* @0x1bde5c ldr r6, [pc, #0x170] */
/* @0x1bde60 mov r4, #0 */
/* @0x1bde64 mov r3, #13 */
/* @0x1bde68 mov r5, r0 */
/* @0x1bde6c add r6, pc, r6 */
/* @0x1bde70 str r3, [r0, #0xc] */
/* @0x1bde74 str r4, [r0] */
/* @0x1bde78 str r4, [r0, #0x4] */
/* @0x1bde7c ldr r7, [sp, #0x20] */
/* @0x1bde80 beq 0x1bde98 <_Z12F_TilemapSetR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1bde84 ldr r0, [pc, #0x14c] */
/* @0x1bde88 mov r1, r4 */
/* @0x1bde8c pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1bde90 add r0, pc, r0 */
/* @0x1bde94 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bde98 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bde9c mov r1, r4 */
/* @0x1bdea0 mov r8, r0 */
/* @0x1bdea4 mov r0, r7 */
/* @0x1bdea8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bdeac mov r2, r4 */
/* @0x1bdeb0 mov r1, r0 */
/* @0x1bdeb4 mov r0, r8 */
/* @0x1bdeb8 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bdebc subs r4, r0, #0 */
/* @0x1bdec0 beq 0x1bded0 <_Z12F_TilemapSetR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x1bdec4 ldr r3, [r4] */
/* @0x1bdec8 cmp r3, #5 */
/* @0x1bdecc beq 0x1bdef4 <_Z12F_TilemapSetR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x1bded0 ldr r1, [pc, #0x104] */
/* @0x1bded4 ldr r3, [pc, #0x104] */
/* @0x1bded8 add r1, pc, r1 */
/* @0x1bdedc ldr r3, [r6, r3] */
/* @0x1bdee0 ldr r0, [r3] */
/* @0x1bdee4 ldr r3, [r0] */
/* @0x1bdee8 ldr r3, [r3, #0xc] */
/* @0x1bdeec blx r3 */
/* @0x1bdef0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1bdef4 ldr r3, [r4, #0x34] */
/* @0x1bdef8 cmp r3, #0 */
/* @0x1bdefc beq 0x1bdfa0 <_Z12F_TilemapSetR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x1bdf00 mov r1, #2 */
/* @0x1bdf04 mov r0, r7 */
/* @0x1bdf08 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bdf0c mov r1, #3 */
/* @0x1bdf10 mov r8, r0 */
/* @0x1bdf14 mov r0, r7 */
/* @0x1bdf18 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bdf1c cmp r8, #0 */
/* @0x1bdf20 mov r9, r0 */
/* @0x1bdf24 poplt {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1bdf28 ldr r3, [r4, #0x28] */
/* @0x1bdf2c cmp r8, r3 */
/* @0x1bdf30 popge {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1bdf34 cmp r0, #0 */
/* @0x1bdf38 poplt {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1bdf3c ldr r3, [r4, #0x2c] */
/* @0x1bdf40 cmp r0, r3 */
/* @0x1bdf44 popge {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1bdf48 ldr r0, [r4, #0x1c] */
/* @0x1bdf4c bl 0xc3794 <_Z15Background_Datai> */
/* @0x1bdf50 ldr r2, [pc, #0x8c] */
/* @0x1bdf54 ldr r3, [r4, #0x38] */
/* @0x1bdf58 mov r1, #1 */
/* @0x1bdf5c ldr r2, [r6, r2] */
/* @0x1bdf60 mov r10, r0 */
/* @0x1bdf64 mov r0, r7 */
/* @0x1bdf68 ldr r7, [r2] */
/* @0x1bdf6c and r7, r7, r3 */
/* @0x1bdf70 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bdf74 cmp r10, #0 */
/* @0x1bdf78 and r7, r7, r0 */
/* @0x1bdf7c ubfx r7, r7, #0x0, #0x13 */
/* @0x1bdf80 beq 0x1bdfb0 <_Z12F_TilemapSetR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x1bdf84 ldr r3, [r10, #0x34] */
/* @0x1bdf88 cmp r7, r3 */
/* @0x1bdf8c blt 0x1bdfb0 <_Z12F_TilemapSetR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x1bdf90 ldr r1, [pc, #0x50] */
/* @0x1bdf94 ldr r3, [pc, #0x44] */
/* @0x1bdf98 add r1, pc, r1 */
/* @0x1bdf9c b 0x1bdedc <_Z12F_TilemapSetR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1bdfa0 ldr r1, [pc, #0x44] */
/* @0x1bdfa4 ldr r3, [pc, #0x34] */
/* @0x1bdfa8 add r1, pc, r1 */
/* @0x1bdfac b 0x1bdedc <_Z12F_TilemapSetR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1bdfb0 mov r3, #0 */
/* @0x1bdfb4 mov r2, r3 */
/* @0x1bdfb8 movt r3, #0x3ff0 */
/* @0x1bdfbc stm r5, {r2, r3} */
/* @0x1bdfc0 ldr r2, [r4, #0x28] */
/* @0x1bdfc4 ldr r3, [r4, #0x34] */
/* @0x1bdfc8 mla r8, r2, r9, r8 */
/* @0x1bdfcc str r0, [r3, r8, lsl #2] */
/* @0x1bdfd0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1bdfd4 eoreq r3, r3, r4, ror #27 */
/* @0x1bdfd8 andseq r0, r9, r8, ror #18 */
/* @0x1bdfdc andseq r0, r9, r8, lsl #19 */
/* @0x1bdfe0 .word 0xffffbac4 */
/* @0x1bdfe4 .word 0xffffebc8 */
/* @0x1bdfe8 ldrsheq r0, [r9], -r12 */
/* @0x1bdfec andseq r0, r9, r12, ror r8 */

/* ── FUNC 0x1bdff0 · F_TilemapSetAtPixel(RValue&, CInstance*, CInstance*, int, RValue*) · size=712 · insn=178 */
/* @0x1bdff0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1bdff4 vpush {d8, d9} */
/* @0x1bdff8 cmp r3, #4 */
/* @0x1bdffc ldr r6, [pc, #0x294] */
/* @0x1be000 mov r4, #0 */
/* @0x1be004 sub sp, sp, #20 */
/* @0x1be008 mov r3, #13 */
/* @0x1be00c str r4, [r0] */
/* @0x1be010 mov r5, r0 */
/* @0x1be014 str r3, [r0, #0xc] */
/* @0x1be018 add r6, pc, r6 */
/* @0x1be01c str r4, [r0, #0x4] */
/* @0x1be020 beq 0x1be040 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x1be024 ldr r0, [pc, #0x270] */
/* @0x1be028 mov r1, r4 */
/* @0x1be02c add r0, pc, r0 */
/* @0x1be030 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1be034 add sp, sp, #20 */
/* @0x1be038 vpop {d8, d9} */
/* @0x1be03c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1be040 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1be044 add r7, sp, #16 */
/* @0x1be048 mov r1, r4 */
/* @0x1be04c str r4, [r7, #-0x4]! */
/* @0x1be050 mov r8, r0 */
/* @0x1be054 ldr r0, [sp, #0x48] */
/* @0x1be058 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1be05c mov r2, r7 */
/* @0x1be060 mov r1, r0 */
/* @0x1be064 mov r0, r8 */
/* @0x1be068 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1be06c subs r10, r0, #0 */
/* @0x1be070 beq 0x1be080 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x1be074 ldr r2, [r10] */
/* @0x1be078 cmp r2, #5 */
/* @0x1be07c beq 0x1be0ac <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x1be080 ldr r1, [pc, #0x218] */
/* @0x1be084 ldr r3, [pc, #0x218] */
/* @0x1be088 add r1, pc, r1 */
/* @0x1be08c ldr r3, [r6, r3] */
/* @0x1be090 ldr r0, [r3] */
/* @0x1be094 ldr r3, [r0] */
/* @0x1be098 ldr r3, [r3, #0xc] */
/* @0x1be09c blx r3 */
/* @0x1be0a0 add sp, sp, #20 */
/* @0x1be0a4 vpop {d8, d9} */
/* @0x1be0a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1be0ac ldr r2, [sp, #0xc] */
/* @0x1be0b0 cmp r2, #0 */
/* @0x1be0b4 beq 0x1be080 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x1be0b8 ldr r1, [r10, #0x34] */
/* @0x1be0bc cmp r1, #0 */
/* @0x1be0c0 beq 0x1be268 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x278> */
/* @0x1be0c4 ldr r0, [r10, #0x1c] */
/* @0x1be0c8 bl 0xc3794 <_Z15Background_Datai> */
/* @0x1be0cc subs r11, r0, #0 */
/* @0x1be0d0 beq 0x1be254 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x1be0d4 ldr lr, [pc, #0x1cc] */
/* @0x1be0d8 mov r1, #2 */
/* @0x1be0dc ldr r2, [r10, #0x38] */
/* @0x1be0e0 vldr s16, [r10, #32] */
/* @0x1be0e4 ldr r12, [sp, #0xc] */
/* @0x1be0e8 vldr s15, [r12, #8] */
/* @0x1be0ec vldr s18, [r12, #12] */
/* @0x1be0f0 ldr r0, [sp, #0x48] */
/* @0x1be0f4 str r2, [sp] */
/* @0x1be0f8 vadd.f32 s16, s16, s15 */
/* @0x1be0fc ldr r12, [r6, lr] */
/* @0x1be100 vldr s19, [r10, #36] */
/* @0x1be104 ldr r4, [r11, #0x1c] */
/* @0x1be108 ldr r8, [r11, #0x20] */
/* @0x1be10c ldr r12, [r12] */
/* @0x1be110 ldr r7, [r10, #0x28] */
/* @0x1be114 ldr r9, [r10, #0x2c] */
/* @0x1be118 str r12, [sp, #0x4] */
/* @0x1be11c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1be120 mov r1, #3 */
/* @0x1be124 vmov s17, r0 */
/* @0x1be128 ldr r0, [sp, #0x48] */
/* @0x1be12c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1be130 vsub.f32 s15, s17, s16 */
/* @0x1be134 vcmpe.f32 s15, #0 */
/* @0x1be138 vmrs APSR_nzcv, fpscr */
/* @0x1be13c vmov s13, r0 */
/* @0x1be140 bmi 0x1be034 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1be144 mul r7, r7, r4 */
/* @0x1be148 vmov s12, r7 */
/* @0x1be14c vcvt.f32.s32 s14, s12 */
/* @0x1be150 vcmpe.f32 s14, s15 */
/* @0x1be154 vmrs APSR_nzcv, fpscr */
/* @0x1be158 bls 0x1be034 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1be15c vadd.f32 s18, s19, s18 */
/* @0x1be160 vsub.f32 s18, s13, s18 */
/* @0x1be164 vcmpe.f32 s18, #0 */
/* @0x1be168 vmrs APSR_nzcv, fpscr */
/* @0x1be16c bmi 0x1be034 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1be170 mul r9, r9, r8 */
/* @0x1be174 vmov s13, r9 */
/* @0x1be178 vcvt.f32.s32 s14, s13 */
/* @0x1be17c vcmpe.f32 s14, s18 */
/* @0x1be180 vmrs APSR_nzcv, fpscr */
/* @0x1be184 bls 0x1be034 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1be188 vmov.f32 s16, #1.000000e+00 */
/* @0x1be18c vmov s12, r4 */
/* @0x1be190 vcvt.f32.s32 s14, s12 */
/* @0x1be194 vdiv.f32 s14, s16, s14 */
/* @0x1be198 vmul.f32 s14, s15, s14 */
/* @0x1be19c vmov r0, s14 */
/* @0x1be1a0 bl 0xb6910 <floorf@plt> */
/* @0x1be1a4 vmov s13, r8 */
/* @0x1be1a8 vcvt.f32.s32 s15, s13 */
/* @0x1be1ac vdiv.f32 s16, s16, s15 */
/* @0x1be1b0 vmov s14, r0 */
/* @0x1be1b4 vmul.f32 s16, s18, s16 */
/* @0x1be1b8 vcvt.s32.f32 s14, s14 */
/* @0x1be1bc vmov r0, s16 */
/* @0x1be1c0 vmov r4, s14 */
/* @0x1be1c4 bl 0xb6910 <floorf@plt> */
/* @0x1be1c8 ldr r1, [r10, #0x28] */
/* @0x1be1cc cmp r4, r1 */
/* @0x1be1d0 lsrge r12, r1, #31 */
/* @0x1be1d4 lsrlt r12, r4, #31 */
/* @0x1be1d8 cmp r4, r1 */
/* @0x1be1dc movge r4, r1 */
/* @0x1be1e0 vmov s15, r0 */
/* @0x1be1e4 cmp r12, #0 */
/* @0x1be1e8 ldr r12, [r10, #0x2c] */
/* @0x1be1ec vcvt.s32.f32 s15, s15 */
/* @0x1be1f0 movne r4, #0 */
/* @0x1be1f4 vmov r0, s15 */
/* @0x1be1f8 cmp r0, r12 */
/* @0x1be1fc lsrge lr, r12, #31 */
/* @0x1be200 lsrlt lr, r0, #31 */
/* @0x1be204 cmp lr, #0 */
/* @0x1be208 movne r7, #0 */
/* @0x1be20c bne 0x1be21c <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x22c> */
/* @0x1be210 cmp r0, r12 */
/* @0x1be214 movge r0, r12 */
/* @0x1be218 mul r7, r0, r1 */
/* @0x1be21c mov r1, #1 */
/* @0x1be220 ldr r0, [sp, #0x48] */
/* @0x1be224 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1be228 ldm sp, {r2, r3} */
/* @0x1be22c and r1, r2, r3 */
/* @0x1be230 ldr r2, [r11, #0x34] */
/* @0x1be234 and r1, r1, r0 */
/* @0x1be238 ubfx r1, r1, #0x0, #0x13 */
/* @0x1be23c cmp r1, r2 */
/* @0x1be240 blt 0x1be278 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x288> */
/* @0x1be244 ldr r1, [pc, #0x60] */
/* @0x1be248 ldr r3, [pc, #0x54] */
/* @0x1be24c add r1, pc, r1 */
/* @0x1be250 b 0x1be08c <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x1be254 ldr r0, [pc, #0x54] */
/* @0x1be258 mov r1, r11 */
/* @0x1be25c add r0, pc, r0 */
/* @0x1be260 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1be264 b 0x1be034 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1be268 ldr r0, [pc, #0x44] */
/* @0x1be26c add r0, pc, r0 */
/* @0x1be270 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1be274 b 0x1be034 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1be278 mov r2, #0 */
/* @0x1be27c add r4, r4, r7 */
/* @0x1be280 mov r1, r2 */
/* @0x1be284 movt r2, #0x3ff0 */
/* @0x1be288 stm r5, {r1, r2} */
/* @0x1be28c ldr r3, [r10, #0x34] */
/* @0x1be290 str r0, [r3, r4, lsl #2] */
/* @0x1be294 b 0x1be034 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1be298 eoreq r3, r3, r8, lsr r12 */
/* @0x1be29c mulseq r9, r12, r8 */
/* @0x1be2a0 andseq r0, r9, r8, ror #17 */
/* @0x1be2a4 .word 0xffffbac4 */
/* @0x1be2a8 .word 0xffffebc8 */
/* @0x1be2ac andseq r0, r9, r0, ror #14 */
/* @0x1be2b0 ldrsbeq r0, [r9], -r4 */
/* @0x1be2b4 mulseq r9, r0, r6 */

/* ── FUNC 0x1be2b8 · F_TilemapGetTileset(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1be2b8 cmp r3, #1 */
/* @0x1be2bc push {r3, r4, r5, r6, r7, lr} */
/* @0x1be2c0 mov r3, #0 */
/* @0x1be2c4 mov r4, r3 */
/* @0x1be2c8 mov r5, r0 */
/* @0x1be2cc movt r3, #0xbff0 */
/* @0x1be2d0 str r4, [r0, #0xc] */
/* @0x1be2d4 str r3, [r0, #0x4] */
/* @0x1be2d8 str r4, [r0] */
/* @0x1be2dc ldr r6, [sp, #0x18] */
/* @0x1be2e0 beq 0x1be2f8 <_Z19F_TilemapGetTilesetR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1be2e4 ldr r0, [pc, #0x5c] */
/* @0x1be2e8 mov r1, r4 */
/* @0x1be2ec pop {r3, r4, r5, r6, r7, lr} */
/* @0x1be2f0 add r0, pc, r0 */
/* @0x1be2f4 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1be2f8 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1be2fc mov r1, r4 */
/* @0x1be300 mov r7, r0 */
/* @0x1be304 mov r0, r6 */
/* @0x1be308 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1be30c mov r2, r4 */
/* @0x1be310 mov r1, r0 */
/* @0x1be314 mov r0, r7 */
/* @0x1be318 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1be31c cmp r0, #0 */
/* @0x1be320 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1be324 ldr r3, [r0] */
/* @0x1be328 cmp r3, #5 */
/* @0x1be32c popne {r3, r4, r5, r6, r7, pc} */
/* @0x1be330 ldr r2, [r0, #0x1c] */
/* @0x1be334 vmov s15, r2 */
/* @0x1be338 vcvt.f64.s32 d7, s15 */
/* @0x1be33c vmov r2, r3, d7 */
/* @0x1be340 stm r5, {r2, r3} */
/* @0x1be344 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1be348 ldrsheq r0, [r9], -r8 */

/* ── FUNC 0x1be34c · F_TilemapGetTileWidth(RValue&, CInstance*, CInstance*, int, RValue*) · size=188 · insn=47 */
/* @0x1be34c cmp r3, #1 */
/* @0x1be350 push {r3, r4, r5, r6, r7, lr} */
/* @0x1be354 mov r3, #0 */
/* @0x1be358 mov r4, r3 */
/* @0x1be35c mov r5, r0 */
/* @0x1be360 movt r3, #0xbff0 */
/* @0x1be364 str r4, [r0, #0xc] */
/* @0x1be368 str r3, [r0, #0x4] */
/* @0x1be36c str r4, [r0] */
/* @0x1be370 ldr r6, [sp, #0x18] */
/* @0x1be374 beq 0x1be38c <_Z21F_TilemapGetTileWidthR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1be378 ldr r0, [pc, #0x80] */
/* @0x1be37c mov r1, r4 */
/* @0x1be380 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1be384 add r0, pc, r0 */
/* @0x1be388 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1be38c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1be390 mov r1, r4 */
/* @0x1be394 mov r7, r0 */
/* @0x1be398 mov r0, r6 */
/* @0x1be39c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1be3a0 mov r2, r4 */
/* @0x1be3a4 mov r1, r0 */
/* @0x1be3a8 mov r0, r7 */
/* @0x1be3ac bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1be3b0 cmp r0, #0 */
/* @0x1be3b4 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1be3b8 ldr r3, [r0] */
/* @0x1be3bc cmp r3, #5 */
/* @0x1be3c0 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1be3c4 ldr r0, [r0, #0x1c] */
/* @0x1be3c8 bl 0xc3794 <_Z15Background_Datai> */
/* @0x1be3cc cmp r0, #0 */
/* @0x1be3d0 beq 0x1be3ec <_Z21F_TilemapGetTileWidthR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x1be3d4 ldr r2, [r0, #0x1c] */
/* @0x1be3d8 vmov s15, r2 */
/* @0x1be3dc vcvt.f64.s32 d7, s15 */
/* @0x1be3e0 vmov r2, r3, d7 */
/* @0x1be3e4 stm r5, {r2, r3} */
/* @0x1be3e8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1be3ec mov r1, r0 */
/* @0x1be3f0 ldr r0, [pc, #0xc] */
/* @0x1be3f4 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1be3f8 add r0, pc, r0 */
/* @0x1be3fc b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1be400 mulseq r9, r8, r6 */
/* @0x1be404 andseq r0, r9, r12, asr r6 */
