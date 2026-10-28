/* libyoyo.so 覆盖卡组 0049
 * 函数 0x11be38..0x11ccbc，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x11be38 · F_StringWidthExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x11be38 push {r3, r4, r5, r6, r7, lr} */
/* @0x11be3c mov r1, #0 */
/* @0x11be40 ldr r5, [sp, #0x18] */
/* @0x11be44 mov r4, r0 */
/* @0x11be48 str r1, [r0, #0xc] */
/* @0x11be4c mov r0, r5 */
/* @0x11be50 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11be54 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x11be58 mov r1, #1 */
/* @0x11be5c mov r6, r0 */
/* @0x11be60 mov r0, r5 */
/* @0x11be64 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11be68 mov r1, #2 */
/* @0x11be6c mov r7, r0 */
/* @0x11be70 mov r0, r5 */
/* @0x11be74 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11be78 mov r1, r7 */
/* @0x11be7c mov r2, r0 */
/* @0x11be80 mov r0, r6 */
/* @0x11be84 bl 0x172bc8 <_Z13GR_Text_WidthPKcii> */
/* @0x11be88 vmov s15, r0 */
/* @0x11be8c mov r0, r6 */
/* @0x11be90 vcvt.f64.s32 d7, s15 */
/* @0x11be94 vmov r2, r3, d7 */
/* @0x11be98 stm r4, {r2, r3} */
/* @0x11be9c pop {r3, r4, r5, r6, r7, lr} */
/* @0x11bea0 b 0xcef90 <_Z6YYFreePKv> */

/* ── FUNC 0x11bea4 · F_StringHeightExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x11bea4 push {r3, r4, r5, r6, r7, lr} */
/* @0x11bea8 mov r1, #0 */
/* @0x11beac ldr r5, [sp, #0x18] */
/* @0x11beb0 mov r4, r0 */
/* @0x11beb4 str r1, [r0, #0xc] */
/* @0x11beb8 mov r0, r5 */
/* @0x11bebc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11bec0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x11bec4 mov r1, #1 */
/* @0x11bec8 mov r6, r0 */
/* @0x11becc mov r0, r5 */
/* @0x11bed0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11bed4 mov r1, #2 */
/* @0x11bed8 mov r7, r0 */
/* @0x11bedc mov r0, r5 */
/* @0x11bee0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11bee4 mov r1, r7 */
/* @0x11bee8 mov r2, r0 */
/* @0x11beec mov r0, r6 */
/* @0x11bef0 bl 0x172d08 <_Z14GR_Text_HeightPKcii> */
/* @0x11bef4 vmov s15, r0 */
/* @0x11bef8 mov r0, r6 */
/* @0x11befc vcvt.f64.s32 d7, s15 */
/* @0x11bf00 vmov r2, r3, d7 */
/* @0x11bf04 stm r4, {r2, r3} */
/* @0x11bf08 pop {r3, r4, r5, r6, r7, lr} */
/* @0x11bf0c b 0xcef90 <_Z6YYFreePKv> */

/* ── FUNC 0x11bf10 · F_CollisionShape(RValue&, CInstance*, CInstance*, int, RValue*) · size=296 · insn=74 */
/* @0x11bf10 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11bf14 sub sp, sp, #36 */
/* @0x11bf18 mov r1, #0 */
/* @0x11bf1c mov r5, r0 */
/* @0x11bf20 ldr r4, [sp, #0x48] */
/* @0x11bf24 mov r0, r4 */
/* @0x11bf28 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11bf2c mov r6, r0 */
/* @0x11bf30 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x11bf34 subs r1, r0, #0 */
/* @0x11bf38 beq 0x11c024 <_Z16F_CollisionShapeR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x11bf3c mov r0, r6 */
/* @0x11bf40 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11bf44 mov r1, #1 */
/* @0x11bf48 mov r6, r0 */
/* @0x11bf4c mov r0, r4 */
/* @0x11bf50 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11bf54 mov r1, #2 */
/* @0x11bf58 mov r9, r0 */
/* @0x11bf5c mov r0, r4 */
/* @0x11bf60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11bf64 mov r1, #3 */
/* @0x11bf68 mov r8, r0 */
/* @0x11bf6c mov r0, r4 */
/* @0x11bf70 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11bf74 mov r1, #4 */
/* @0x11bf78 mov r7, r0 */
/* @0x11bf7c mov r0, r4 */
/* @0x11bf80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11bf84 mov r1, #5 */
/* @0x11bf88 mov r2, r0 */
/* @0x11bf8c mov r0, r4 */
/* @0x11bf90 str r2, [sp, #0x18] */
/* @0x11bf94 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11bf98 mov r1, #6 */
/* @0x11bf9c mov r3, r0 */
/* @0x11bfa0 mov r0, r4 */
/* @0x11bfa4 str r3, [sp, #0x1c] */
/* @0x11bfa8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11bfac mov r1, #7 */
/* @0x11bfb0 mov r11, r0 */
/* @0x11bfb4 mov r0, r4 */
/* @0x11bfb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11bfbc mov r1, #8 */
/* @0x11bfc0 mov r10, r0 */
/* @0x11bfc4 mov r0, r4 */
/* @0x11bfc8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11bfcc ldr r2, [sp, #0x18] */
/* @0x11bfd0 ldr r3, [sp, #0x1c] */
/* @0x11bfd4 mov r1, r9 */
/* @0x11bfd8 str r11, [sp, #0x8] */
/* @0x11bfdc str r2, [sp] */
/* @0x11bfe0 mov r2, r8 */
/* @0x11bfe4 str r3, [sp, #0x4] */
/* @0x11bfe8 mov r3, r7 */
/* @0x11bfec str r10, [sp, #0xc] */
/* @0x11bff0 str r0, [sp, #0x10] */
/* @0x11bff4 mov r0, r6 */
/* @0x11bff8 bl 0x1ed3d0 <_ZN7CSprite9CollisionEifffffff> */
/* @0x11bffc mov r3, #13 */
/* @0x11c000 str r3, [r5, #0xc] */
/* @0x11c004 cmp r0, #0 */
/* @0x11c008 movne r3, #0 */
/* @0x11c00c moveq r3, r0 */
/* @0x11c010 movne r0, r3 */
/* @0x11c014 movtne r3, #0x3ff0 */
/* @0x11c018 stm r5, {r0, r3} */
/* @0x11c01c add sp, sp, #36 */
/* @0x11c020 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11c024 ldr r0, [pc, #0x8] */
/* @0x11c028 add r0, pc, r0 */
/* @0x11c02c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11c030 b 0x11bf3c <_Z16F_CollisionShapeR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x11c034 eoreq sp, r1, r12, lsl #31 */

/* ── FUNC 0x11c038 · F_DrawShape(RValue&, CInstance*, CInstance*, int, RValue*) · size=324 · insn=81 */
/* @0x11c038 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11c03c sub sp, sp, #52 */
/* @0x11c040 mov r1, #0 */
/* @0x11c044 ldr r4, [sp, #0x58] */
/* @0x11c048 mov r0, r4 */
/* @0x11c04c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c050 mov r5, r0 */
/* @0x11c054 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x11c058 subs r1, r0, #0 */
/* @0x11c05c bne 0x11c06c <_Z11F_DrawShapeR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x11c060 ldr r0, [pc, #0x110] */
/* @0x11c064 add r0, pc, r0 */
/* @0x11c068 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11c06c mov r0, r5 */
/* @0x11c070 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11c074 mov r1, #1 */
/* @0x11c078 mov r5, r0 */
/* @0x11c07c mov r0, r4 */
/* @0x11c080 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c084 mov r1, #2 */
/* @0x11c088 mov r8, r0 */
/* @0x11c08c mov r0, r4 */
/* @0x11c090 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c094 mov r1, #3 */
/* @0x11c098 mov r6, r0 */
/* @0x11c09c mov r0, r4 */
/* @0x11c0a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c0a4 mov r1, #4 */
/* @0x11c0a8 mov r3, r0 */
/* @0x11c0ac mov r0, r4 */
/* @0x11c0b0 str r3, [sp, #0x20] */
/* @0x11c0b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c0b8 mov r1, #5 */
/* @0x11c0bc mov r12, r0 */
/* @0x11c0c0 mov r0, r4 */
/* @0x11c0c4 str r12, [sp, #0x24] */
/* @0x11c0c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c0cc mov r1, #6 */
/* @0x11c0d0 mov r2, r0 */
/* @0x11c0d4 mov r0, r4 */
/* @0x11c0d8 str r2, [sp, #0x28] */
/* @0x11c0dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c0e0 mov r1, #7 */
/* @0x11c0e4 str r0, [sp, #0x2c] */
/* @0x11c0e8 mov r0, r4 */
/* @0x11c0ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c0f0 mov r1, #8 */
/* @0x11c0f4 mov r11, r0 */
/* @0x11c0f8 mov r0, r4 */
/* @0x11c0fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c100 mov r1, #9 */
/* @0x11c104 mov r10, r0 */
/* @0x11c108 mov r0, r4 */
/* @0x11c10c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c110 mov r1, #10 */
/* @0x11c114 mov r9, r0 */
/* @0x11c118 mov r0, r4 */
/* @0x11c11c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c120 mov r1, #11 */
/* @0x11c124 mov r7, r0 */
/* @0x11c128 mov r0, r4 */
/* @0x11c12c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c130 ldr r2, [sp, #0x28] */
/* @0x11c134 ldr r12, [sp, #0x24] */
/* @0x11c138 mov r1, r8 */
/* @0x11c13c str r11, [sp, #0xc] */
/* @0x11c140 str r2, [sp, #0x4] */
/* @0x11c144 ldr r2, [sp, #0x2c] */
/* @0x11c148 str r12, [sp] */
/* @0x11c14c str r10, [sp, #0x10] */
/* @0x11c150 str r2, [sp, #0x8] */
/* @0x11c154 mov r2, r6 */
/* @0x11c158 str r9, [sp, #0x14] */
/* @0x11c15c str r7, [sp, #0x18] */
/* @0x11c160 ldr r3, [sp, #0x20] */
/* @0x11c164 str r0, [sp, #0x1c] */
/* @0x11c168 mov r0, r5 */
/* @0x11c16c bl 0x1ed768 <_ZN7CSprite9DrawShapeEiiifffffjjf> */
/* @0x11c170 add sp, sp, #52 */
/* @0x11c174 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11c178 eoreq sp, r1, r0, asr pc */

/* ── FUNC 0x11c17c · F_DrawShapeString(RValue&, CInstance*, CInstance*, int, RValue*) · size=304 · insn=76 */
/* @0x11c17c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11c180 sub sp, sp, #52 */
/* @0x11c184 mov r1, #0 */
/* @0x11c188 ldr r4, [sp, #0x58] */
/* @0x11c18c mov r0, r4 */
/* @0x11c190 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c194 mov r5, r0 */
/* @0x11c198 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x11c19c subs r1, r0, #0 */
/* @0x11c1a0 bne 0x11c1b0 <_Z17F_DrawShapeStringR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x11c1a4 ldr r0, [pc, #0xfc] */
/* @0x11c1a8 add r0, pc, r0 */
/* @0x11c1ac bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11c1b0 mov r0, r5 */
/* @0x11c1b4 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11c1b8 mov r1, #1 */
/* @0x11c1bc mov r5, r0 */
/* @0x11c1c0 mov r0, r4 */
/* @0x11c1c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c1c8 mov r1, #2 */
/* @0x11c1cc mov r8, r0 */
/* @0x11c1d0 mov r0, r4 */
/* @0x11c1d4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11c1d8 mov r1, #3 */
/* @0x11c1dc mov r7, r0 */
/* @0x11c1e0 mov r0, r4 */
/* @0x11c1e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c1e8 mov r1, #4 */
/* @0x11c1ec mov r6, r0 */
/* @0x11c1f0 mov r0, r4 */
/* @0x11c1f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c1f8 mov r1, #5 */
/* @0x11c1fc mov r12, r0 */
/* @0x11c200 mov r0, r4 */
/* @0x11c204 str r12, [sp, #0x24] */
/* @0x11c208 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c20c mov r1, #6 */
/* @0x11c210 mov r2, r0 */
/* @0x11c214 mov r0, r4 */
/* @0x11c218 str r2, [sp, #0x28] */
/* @0x11c21c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c220 mov r1, #7 */
/* @0x11c224 mov r3, r0 */
/* @0x11c228 mov r0, r4 */
/* @0x11c22c str r3, [sp, #0x2c] */
/* @0x11c230 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c234 mov r1, #8 */
/* @0x11c238 mov r11, r0 */
/* @0x11c23c mov r0, r4 */
/* @0x11c240 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c244 mov r1, #9 */
/* @0x11c248 mov r10, r0 */
/* @0x11c24c mov r0, r4 */
/* @0x11c250 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c254 mov r1, #10 */
/* @0x11c258 mov r9, r0 */
/* @0x11c25c mov r0, r4 */
/* @0x11c260 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c264 ldr r2, [sp, #0x28] */
/* @0x11c268 ldr r3, [sp, #0x2c] */
/* @0x11c26c mov r1, r8 */
/* @0x11c270 ldr r12, [sp, #0x24] */
/* @0x11c274 str r2, [sp, #0x4] */
/* @0x11c278 mov r2, r7 */
/* @0x11c27c str r3, [sp, #0x8] */
/* @0x11c280 mov r3, r6 */
/* @0x11c284 str r12, [sp] */
/* @0x11c288 str r11, [sp, #0xc] */
/* @0x11c28c str r10, [sp, #0x10] */
/* @0x11c290 str r9, [sp, #0x14] */
/* @0x11c294 str r0, [sp, #0x18] */
/* @0x11c298 mov r0, r5 */
/* @0x11c29c bl 0x1ee768 <_ZN7CSprite15DrawShapeStringEiPKcfffffjjf> */
/* @0x11c2a0 add sp, sp, #52 */
/* @0x11c2a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11c2a8 eoreq sp, r1, r12, lsl #28 */

/* ── FUNC 0x11c2ac · F_TileExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x11c2ac push {r3, r4, r5, lr} */
/* @0x11c2b0 mov r1, #0 */
/* @0x11c2b4 ldr r3, [pc, #0x3c] */
/* @0x11c2b8 mov r4, r0 */
/* @0x11c2bc ldr r0, [sp, #0x10] */
/* @0x11c2c0 ldr r3, [pc, r3] */
/* @0x11c2c4 ldr r5, [r3] */
/* @0x11c2c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c2cc mov r1, r0 */
/* @0x11c2d0 mov r0, r5 */
/* @0x11c2d4 bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x11c2d8 mov r3, #0 */
/* @0x11c2dc mov r2, r3 */
/* @0x11c2e0 str r3, [r4, #0xc] */
/* @0x11c2e4 str r3, [r4] */
/* @0x11c2e8 cmp r0, r3 */
/* @0x11c2ec movtge r2, #0x3ff0 */
/* @0x11c2f0 str r2, [r4, #0x4] */
/* @0x11c2f4 pop {r3, r4, r5, pc} */
/* @0x11c2f8 eoreq r1, sp, r8, ror #12 */

/* ── FUNC 0x11c2fc · F_TileAdd(RValue&, CInstance*, CInstance*, int, RValue*) · size=324 · insn=81 */
/* @0x11c2fc push {r4, r5, r6, r7, lr} */
/* @0x11c300 sub sp, sp, #60 */
/* @0x11c304 mov r5, r0 */
/* @0x11c308 mov r1, #0 */
/* @0x11c30c ldr r4, [sp, #0x50] */
/* @0x11c310 mov r6, r1 */
/* @0x11c314 mov r0, r4 */
/* @0x11c318 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c31c mov r3, r6 */
/* @0x11c320 str r6, [r5, #0xc] */
/* @0x11c324 movt r3, #0xbff0 */
/* @0x11c328 str r6, [r5] */
/* @0x11c32c str r3, [r5, #0x4] */
/* @0x11c330 mov r7, r0 */
/* @0x11c334 bl 0xc3640 <_Z17Background_Existsi> */
/* @0x11c338 subs r1, r0, #0 */
/* @0x11c33c bne 0x11c354 <_Z9F_TileAddR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x11c340 ldr r0, [pc, #0xf0] */
/* @0x11c344 add r0, pc, r0 */
/* @0x11c348 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11c34c add sp, sp, #60 */
/* @0x11c350 pop {r4, r5, r6, r7, pc} */
/* @0x11c354 mov r1, #1 */
/* @0x11c358 mov r0, r4 */
/* @0x11c35c str r7, [sp, #0x8] */
/* @0x11c360 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c364 mov r1, #2 */
/* @0x11c368 ldr r7, [pc, #0xcc] */
/* @0x11c36c str r0, [sp, #0xc] */
/* @0x11c370 mov r0, r4 */
/* @0x11c374 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c378 mov r1, #3 */
/* @0x11c37c str r0, [sp, #0x10] */
/* @0x11c380 mov r0, r4 */
/* @0x11c384 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c388 mov r1, #4 */
/* @0x11c38c str r0, [sp, #0x14] */
/* @0x11c390 mov r0, r4 */
/* @0x11c394 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c398 mov r1, #5 */
/* @0x11c39c str r0, [sp, #0x18] */
/* @0x11c3a0 mov r0, r4 */
/* @0x11c3a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c3a8 mov r1, #6 */
/* @0x11c3ac str r0, [sp] */
/* @0x11c3b0 mov r0, r4 */
/* @0x11c3b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c3b8 mov r1, #7 */
/* @0x11c3bc str r0, [sp, #0x4] */
/* @0x11c3c0 mov r0, r4 */
/* @0x11c3c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c3c8 ldr r7, [pc, r7] */
/* @0x11c3cc mov r1, sp */
/* @0x11c3d0 mov r3, #1065353216 */
/* @0x11c3d4 mvn r12, #-16777216 */
/* @0x11c3d8 mov r2, #1 */
/* @0x11c3dc str r12, [sp, #0x2c] */
/* @0x11c3e0 strb r2, [sp, #0x34] */
/* @0x11c3e4 str r3, [sp, #0x24] */
/* @0x11c3e8 str r3, [sp, #0x28] */
/* @0x11c3ec str r3, [sp, #0x30] */
/* @0x11c3f0 str r0, [sp, #0x1c] */
/* @0x11c3f4 ldr r0, [r7] */
/* @0x11c3f8 bl 0x1ac240 <_ZN5CRoom7AddTileEP5RTile> */
/* @0x11c3fc cmp r0, #0 */
/* @0x11c400 blt 0x11c34c <_Z9F_TileAddR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x11c404 ldr r3, [r7] */
/* @0x11c408 ldr r2, [r3, #0xb8] */
/* @0x11c40c cmp r0, r2 */
/* @0x11c410 rsblt r0, r0, r0, lsl #3 */
/* @0x11c414 ldrlt r3, [r3, #0xc0] */
/* @0x11c418 addlt r6, r3, r0, lsl #3 */
/* @0x11c41c ldr r2, [r6, #0x20] */
/* @0x11c420 vmov s15, r2 */
/* @0x11c424 vcvt.f64.s32 d7, s15 */
/* @0x11c428 vmov r2, r3, d7 */
/* @0x11c42c stm r5, {r2, r3} */
/* @0x11c430 add sp, sp, #60 */
/* @0x11c434 pop {r4, r5, r6, r7, pc} */
/* @0x11c438 mlaeq r1, r4, r12, sp */
/* @0x11c43c eoreq r1, sp, r0, ror #10 */

/* ── FUNC 0x11c440 · F_TileLayerHide(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x11c440 ldr r3, [pc, #0x24] */
/* @0x11c444 mov r1, #0 */
/* @0x11c448 push {r4, lr} */
/* @0x11c44c ldr r3, [pc, r3] */
/* @0x11c450 ldr r0, [sp, #0x8] */
/* @0x11c454 ldr r4, [r3] */
/* @0x11c458 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c45c mov r1, r0 */
/* @0x11c460 mov r0, r4 */
/* @0x11c464 pop {r4, lr} */
/* @0x11c468 b 0x1af584 <_ZN5CRoom14HideTilesDepthEf> */
/* @0x11c46c .word 0x002d14dc */

/* ── FUNC 0x11c470 · F_TileLayerShow(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x11c470 ldr r3, [pc, #0x24] */
/* @0x11c474 mov r1, #0 */
/* @0x11c478 push {r4, lr} */
/* @0x11c47c ldr r3, [pc, r3] */
/* @0x11c480 ldr r0, [sp, #0x8] */
/* @0x11c484 ldr r4, [r3] */
/* @0x11c488 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c48c mov r1, r0 */
/* @0x11c490 mov r0, r4 */
/* @0x11c494 pop {r4, lr} */
/* @0x11c498 b 0x1af5c4 <_ZN5CRoom14ShowTilesDepthEf> */
/* @0x11c49c eoreq r1, sp, r12, lsr #9 */

/* ── FUNC 0x11c4a0 · F_TileLayerDelete(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x11c4a0 ldr r3, [pc, #0x24] */
/* @0x11c4a4 mov r1, #0 */
/* @0x11c4a8 push {r4, lr} */
/* @0x11c4ac ldr r3, [pc, r3] */
/* @0x11c4b0 ldr r0, [sp, #0x8] */
/* @0x11c4b4 ldr r4, [r3] */
/* @0x11c4b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c4bc mov r1, r0 */
/* @0x11c4c0 mov r0, r4 */
/* @0x11c4c4 pop {r4, lr} */
/* @0x11c4c8 b 0x1af604 <_ZN5CRoom16DeleteTilesDepthEf> */
/* @0x11c4cc eoreq r1, sp, r12, ror r4 */

/* ── FUNC 0x11c4d0 · F_TileLayerShift(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x11c4d0 push {r4, r5, r6, r7, r8, lr} */
/* @0x11c4d4 mov r1, #0 */
/* @0x11c4d8 ldr r4, [sp, #0x18] */
/* @0x11c4dc ldr r3, [pc, #0x44] */
/* @0x11c4e0 ldr r3, [pc, r3] */
/* @0x11c4e4 mov r0, r4 */
/* @0x11c4e8 ldr r7, [r3] */
/* @0x11c4ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c4f0 mov r1, #1 */
/* @0x11c4f4 mov r6, r0 */
/* @0x11c4f8 mov r0, r4 */
/* @0x11c4fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c500 mov r1, #2 */
/* @0x11c504 mov r5, r0 */
/* @0x11c508 mov r0, r4 */
/* @0x11c50c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c510 mov r1, r6 */
/* @0x11c514 mov r2, r5 */
/* @0x11c518 mov r3, r0 */
/* @0x11c51c mov r0, r7 */
/* @0x11c520 pop {r4, r5, r6, r7, r8, lr} */
/* @0x11c524 b 0x1af6c8 <_ZN5CRoom15ShiftTilesDepthEfff> */
/* @0x11c528 eoreq r1, sp, r8, asr #8 */

/* ── FUNC 0x11c52c · F_TileLayerFind(RValue&, CInstance*, CInstance*, int, RValue*) · size=172 · insn=43 */
/* @0x11c52c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11c530 mov r6, #0 */
/* @0x11c534 ldr r7, [sp, #0x20] */
/* @0x11c538 mov r1, r6 */
/* @0x11c53c ldr r5, [pc, #0x90] */
/* @0x11c540 mov r4, r0 */
/* @0x11c544 str r6, [r0] */
/* @0x11c548 mov r3, r6 */
/* @0x11c54c ldr r5, [pc, r5] */
/* @0x11c550 movt r3, #0xbff0 */
/* @0x11c554 str r6, [r0, #0xc] */
/* @0x11c558 str r3, [r0, #0x4] */
/* @0x11c55c mov r0, r7 */
/* @0x11c560 ldr r10, [r5] */
/* @0x11c564 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c568 mov r1, #1 */
/* @0x11c56c mov r9, r0 */
/* @0x11c570 mov r0, r7 */
/* @0x11c574 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c578 mov r1, #2 */
/* @0x11c57c mov r8, r0 */
/* @0x11c580 mov r0, r7 */
/* @0x11c584 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c588 mov r1, r9 */
/* @0x11c58c mov r2, r8 */
/* @0x11c590 mov r3, r0 */
/* @0x11c594 mov r0, r10 */
/* @0x11c598 bl 0x1af72c <_ZN5CRoom15FindTileAtDepthEfff> */
/* @0x11c59c cmp r0, #0 */
/* @0x11c5a0 poplt {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x11c5a4 ldr r3, [r5] */
/* @0x11c5a8 ldr r2, [r3, #0xb8] */
/* @0x11c5ac cmp r0, r2 */
/* @0x11c5b0 rsblt r0, r0, r0, lsl #3 */
/* @0x11c5b4 ldrlt r3, [r3, #0xc0] */
/* @0x11c5b8 addlt r6, r3, r0, lsl #3 */
/* @0x11c5bc ldr r2, [r6, #0x20] */
/* @0x11c5c0 vmov s15, r2 */
/* @0x11c5c4 vcvt.f64.s32 d7, s15 */
/* @0x11c5c8 vmov r2, r3, d7 */
/* @0x11c5cc stm r4, {r2, r3} */
/* @0x11c5d0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x11c5d4 .word 0x002d13dc */

/* ── FUNC 0x11c5d8 · F_TileLayerDeleteAt(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x11c5d8 push {r4, r5, r6, r7, r8, lr} */
/* @0x11c5dc mov r1, #0 */
/* @0x11c5e0 ldr r4, [sp, #0x18] */
/* @0x11c5e4 ldr r3, [pc, #0x44] */
/* @0x11c5e8 ldr r3, [pc, r3] */
/* @0x11c5ec mov r0, r4 */
/* @0x11c5f0 ldr r7, [r3] */
/* @0x11c5f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c5f8 mov r1, #1 */
/* @0x11c5fc mov r6, r0 */
/* @0x11c600 mov r0, r4 */
/* @0x11c604 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c608 mov r1, #2 */
/* @0x11c60c mov r5, r0 */
/* @0x11c610 mov r0, r4 */
/* @0x11c614 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c618 mov r1, r6 */
/* @0x11c61c mov r2, r5 */
/* @0x11c620 mov r3, r0 */
/* @0x11c624 mov r0, r7 */
/* @0x11c628 pop {r4, r5, r6, r7, r8, lr} */
/* @0x11c62c b 0x1af860 <_ZN5CRoom18DeleteTilesAtDepthEfff> */
/* @0x11c630 eoreq r1, sp, r0, asr #6 */

/* ── FUNC 0x11c634 · F_TileLayerDepth(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x11c634 push {r4, r5, r6, lr} */
/* @0x11c638 mov r1, #0 */
/* @0x11c63c ldr r4, [sp, #0x10] */
/* @0x11c640 ldr r3, [pc, #0x30] */
/* @0x11c644 ldr r3, [pc, r3] */
/* @0x11c648 mov r0, r4 */
/* @0x11c64c ldr r6, [r3] */
/* @0x11c650 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c654 mov r1, #1 */
/* @0x11c658 mov r5, r0 */
/* @0x11c65c mov r0, r4 */
/* @0x11c660 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11c664 mov r1, r5 */
/* @0x11c668 mov r2, r0 */
/* @0x11c66c mov r0, r6 */
/* @0x11c670 pop {r4, r5, r6, lr} */
/* @0x11c674 b 0x1af9bc <_ZN5CRoom16ChangeTilesDepthEff> */
/* @0x11c678 eoreq r1, sp, r4, ror #5 */

/* ── FUNC 0x11c67c · F_TextureGlobalScale(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x11c67c push {r4, lr} */
/* @0x11c680 mov r1, #0 */
/* @0x11c684 ldr r0, [sp, #0x8] */
/* @0x11c688 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c68c subs r4, r0, #0 */
/* @0x11c690 ble 0x11c6a4 <_Z20F_TextureGlobalScaleR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x11c694 ldr r3, [pc, #0x24] */
/* @0x11c698 ldr r3, [pc, r3] */
/* @0x11c69c str r4, [r3] */
/* @0x11c6a0 pop {r4, pc} */
/* @0x11c6a4 sub r3, r4, #1 */
/* @0x11c6a8 tst r3, r4 */
/* @0x11c6ac beq 0x11c694 <_Z20F_TextureGlobalScaleR6RValueP9CInstanceS2_iPS_+0x18> */
/* @0x11c6b0 ldr r0, [pc, #0xc] */
/* @0x11c6b4 add r0, pc, r0 */
/* @0x11c6b8 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x11c6bc b 0x11c694 <_Z20F_TextureGlobalScaleR6RValueP9CInstanceS2_iPS_+0x18> */
/* @0x11c6c0 eoreq r1, sp, r12, lsr pc */
/* @0x11c6c4 eoreq sp, r1, r0, asr #18 */

/* ── FUNC 0x11c6c8 · F_SurfaceCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0x11c6c8 push {r4, r6, r7, r8, lr} */
/* @0x11c6cc sub sp, sp, #12 */
/* @0x11c6d0 mov r1, #0 */
/* @0x11c6d4 mov r6, r0 */
/* @0x11c6d8 ldr r4, [sp, #0x20] */
/* @0x11c6dc str r1, [r0, #0xc] */
/* @0x11c6e0 mov r0, r4 */
/* @0x11c6e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c6e8 mov r1, #1 */
/* @0x11c6ec mov r7, r0 */
/* @0x11c6f0 mov r0, r4 */
/* @0x11c6f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c6f8 cmp r7, #0 */
/* @0x11c6fc cmpne r0, #0 */
/* @0x11c700 mov r8, r0 */
/* @0x11c704 beq 0x11c780 <_Z15F_SurfaceCreateR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x11c708 mov r1, r8 */
/* @0x11c70c mov r0, r7 */
/* @0x11c710 mvn r2, #0 */
/* @0x11c714 bl 0x170f98 <_Z17GR_Surface_Createiii> */
/* @0x11c718 ldr r12, [pc, #0x70] */
/* @0x11c71c ldr r12, [pc, r12] */
/* @0x11c720 vmov s15, r0 */
/* @0x11c724 vcvt.f64.s32 d7, s15 */
/* @0x11c728 vmov r0, r1, d7 */
/* @0x11c72c vstr s14, [r6] */
/* @0x11c730 ldrb r3, [r12] */
/* @0x11c734 cmp r3, #0 */
/* @0x11c738 str r1, [r6, #0x4] */
/* @0x11c73c beq 0x11c754 <_Z15F_SurfaceCreateR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x11c740 ldr r3, [pc, #0x4c] */
/* @0x11c744 ldr r3, [pc, r3] */
/* @0x11c748 ldr r3, [r3] */
/* @0x11c74c cmp r3, #0 */
/* @0x11c750 beq 0x11c75c <_Z15F_SurfaceCreateR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x11c754 add sp, sp, #12 */
/* @0x11c758 pop {r4, r6, r7, r8, pc} */
/* @0x11c75c ldr r1, [pc, #0x34] */
/* @0x11c760 vstr d7, [sp] */
/* @0x11c764 mov r2, r7 */
/* @0x11c768 mov r3, r8 */
/* @0x11c76c mov r0, #4 */
/* @0x11c770 add r1, pc, r1 */
/* @0x11c774 bl 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz> */
/* @0x11c778 add sp, sp, #12 */
/* @0x11c77c pop {r4, r6, r7, r8, pc} */
/* @0x11c780 ldr r0, [pc, #0x14] */
/* @0x11c784 add r0, pc, r0 */
/* @0x11c788 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x11c78c b 0x11c708 <_Z15F_SurfaceCreateR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x11c790 eoreq r1, sp, r8, lsl #4 */
/* @0x11c794 .word 0x002d1cdc */
/* @0x11c798 eoreq sp, r1, r8, lsl r9 */
/* @0x11c79c eoreq sp, r1, r8, asr #17 */

/* ── FUNC 0x11c7a0 · F_SurfaceCreateSpecial(RValue&, CInstance*, CInstance*, int, RValue*) · size=232 · insn=58 */
/* @0x11c7a0 push {r4, r6, r7, r8, lr} */
/* @0x11c7a4 sub sp, sp, #12 */
/* @0x11c7a8 mov r1, #0 */
/* @0x11c7ac mov r6, r0 */
/* @0x11c7b0 ldr r4, [sp, #0x20] */
/* @0x11c7b4 str r1, [r0, #0xc] */
/* @0x11c7b8 mov r0, r4 */
/* @0x11c7bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c7c0 mov r1, #1 */
/* @0x11c7c4 mov r8, r0 */
/* @0x11c7c8 mov r0, r4 */
/* @0x11c7cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c7d0 cmp r8, #0 */
/* @0x11c7d4 cmpne r0, #0 */
/* @0x11c7d8 mov r7, r0 */
/* @0x11c7dc beq 0x11c868 <_Z22F_SurfaceCreateSpecialR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x11c7e0 mov r1, #2 */
/* @0x11c7e4 mov r0, r4 */
/* @0x11c7e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c7ec mov r1, r7 */
/* @0x11c7f0 mvn r2, #0 */
/* @0x11c7f4 mov r3, r0 */
/* @0x11c7f8 mov r0, r8 */
/* @0x11c7fc bl 0x171228 <_Z25GR_Surface_Create_Specialiiii> */
/* @0x11c800 ldr r12, [pc, #0x70] */
/* @0x11c804 ldr r12, [pc, r12] */
/* @0x11c808 vmov s15, r0 */
/* @0x11c80c vcvt.f64.s32 d7, s15 */
/* @0x11c810 vmov r0, r1, d7 */
/* @0x11c814 vstr s14, [r6] */
/* @0x11c818 ldrb r3, [r12] */
/* @0x11c81c cmp r3, #0 */
/* @0x11c820 str r1, [r6, #0x4] */
/* @0x11c824 beq 0x11c83c <_Z22F_SurfaceCreateSpecialR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x11c828 ldr r3, [pc, #0x4c] */
/* @0x11c82c ldr r3, [pc, r3] */
/* @0x11c830 ldr r3, [r3] */
/* @0x11c834 cmp r3, #0 */
/* @0x11c838 beq 0x11c844 <_Z22F_SurfaceCreateSpecialR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x11c83c add sp, sp, #12 */
/* @0x11c840 pop {r4, r6, r7, r8, pc} */
/* @0x11c844 ldr r1, [pc, #0x34] */
/* @0x11c848 vstr d7, [sp] */
/* @0x11c84c mov r2, r8 */
/* @0x11c850 mov r3, r7 */
/* @0x11c854 mov r0, #4 */
/* @0x11c858 add r1, pc, r1 */
/* @0x11c85c bl 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz> */
/* @0x11c860 add sp, sp, #12 */
/* @0x11c864 pop {r4, r6, r7, r8, pc} */
/* @0x11c868 ldr r0, [pc, #0x14] */
/* @0x11c86c add r0, pc, r0 */
/* @0x11c870 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x11c874 b 0x11c7e0 <_Z22F_SurfaceCreateSpecialR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x11c878 eoreq r1, sp, r0, lsr #2 */
/* @0x11c87c .word 0x002d1bf4 */
/* @0x11c880 eoreq sp, r1, r0, lsr r8 */
/* @0x11c884 eoreq sp, r1, r0, ror #15 */

/* ── FUNC 0x11c888 · F_SurfaceExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x11c888 push {r3, r4, r5, lr} */
/* @0x11c88c mov r5, #0 */
/* @0x11c890 mov r4, r0 */
/* @0x11c894 mov r1, r5 */
/* @0x11c898 str r5, [r0, #0xc] */
/* @0x11c89c ldr r0, [sp, #0x10] */
/* @0x11c8a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c8a4 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x11c8a8 cmp r0, #0 */
/* @0x11c8ac moveq r5, r0 */
/* @0x11c8b0 movne r3, r5 */
/* @0x11c8b4 moveq r3, r5 */
/* @0x11c8b8 movtne r3, #0x3ff0 */
/* @0x11c8bc str r5, [r4] */
/* @0x11c8c0 str r3, [r4, #0x4] */
/* @0x11c8c4 pop {r3, r4, r5, pc} */

/* ── FUNC 0x11c8c8 · F_SurfaceFree(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x11c8c8 push {r3, r4, r5, lr} */
/* @0x11c8cc mov r1, #0 */
/* @0x11c8d0 ldr r4, [sp, #0x10] */
/* @0x11c8d4 mov r0, r4 */
/* @0x11c8d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c8dc mov r1, #0 */
/* @0x11c8e0 mov r5, r0 */
/* @0x11c8e4 mov r0, r4 */
/* @0x11c8e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c8ec mov r1, #0 */
/* @0x11c8f0 bl 0x171ba0 <_Z15GR_Surface_Freeib> */
/* @0x11c8f4 ldr r3, [pc, #0x38] */
/* @0x11c8f8 ldr r3, [pc, r3] */
/* @0x11c8fc ldrb r3, [r3] */
/* @0x11c900 cmp r3, #0 */
/* @0x11c904 popeq {r3, r4, r5, pc} */
/* @0x11c908 ldr r3, [pc, #0x28] */
/* @0x11c90c ldr r3, [pc, r3] */
/* @0x11c910 ldr r3, [r3] */
/* @0x11c914 cmp r3, #0 */
/* @0x11c918 popne {r3, r4, r5, pc} */
/* @0x11c91c ldr r1, [pc, #0x18] */
/* @0x11c920 mov r2, r5 */
/* @0x11c924 mov r0, #4 */
/* @0x11c928 add r1, pc, r1 */
/* @0x11c92c pop {r3, r4, r5, lr} */
/* @0x11c930 b 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz> */
/* @0x11c934 eoreq r1, sp, r12, lsr #32 */
/* @0x11c938 eoreq r1, sp, r4, lsl r11 */
/* @0x11c93c eoreq sp, r1, r0, lsl #15 */

/* ── FUNC 0x11c940 · F_SurfaceGetWidth(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x11c940 push {r4, lr} */
/* @0x11c944 mov r3, #0 */
/* @0x11c948 mov r1, r3 */
/* @0x11c94c str r3, [r0, #0xc] */
/* @0x11c950 mov r4, r0 */
/* @0x11c954 ldr r0, [sp, #0x8] */
/* @0x11c958 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c95c bl 0x1714d4 <_Z20GR_Surface_Get_Widthi> */
/* @0x11c960 vmov s15, r0 */
/* @0x11c964 vcvt.f64.s32 d7, s15 */
/* @0x11c968 vmov r0, r1, d7 */
/* @0x11c96c vmov r2, s14 */
/* @0x11c970 mov r3, r1 */
/* @0x11c974 stm r4, {r2, r3} */
/* @0x11c978 pop {r4, pc} */

/* ── FUNC 0x11c97c · F_SurfaceGetHeight(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x11c97c push {r4, lr} */
/* @0x11c980 mov r3, #0 */
/* @0x11c984 mov r1, r3 */
/* @0x11c988 str r3, [r0, #0xc] */
/* @0x11c98c mov r4, r0 */
/* @0x11c990 ldr r0, [sp, #0x8] */
/* @0x11c994 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c998 bl 0x171518 <_Z21GR_Surface_Get_Heighti> */
/* @0x11c99c vmov s15, r0 */
/* @0x11c9a0 vcvt.f64.s32 d7, s15 */
/* @0x11c9a4 vmov r0, r1, d7 */
/* @0x11c9a8 vmov r2, s14 */
/* @0x11c9ac mov r3, r1 */
/* @0x11c9b0 stm r4, {r2, r3} */
/* @0x11c9b4 pop {r4, pc} */

/* ── FUNC 0x11c9b8 · F_SurfaceGetTexture(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x11c9b8 push {r4, lr} */
/* @0x11c9bc mov r4, r0 */
/* @0x11c9c0 mov r3, #3 */
/* @0x11c9c4 mov r1, #0 */
/* @0x11c9c8 str r3, [r4, #0xc] */
/* @0x11c9cc ldr r0, [sp, #0x8] */
/* @0x11c9d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c9d4 bl 0x17155c <_Z22GR_Surface_Get_Texturei> */
/* @0x11c9d8 str r0, [r4] */
/* @0x11c9dc pop {r4, pc} */

/* ── FUNC 0x11c9e0 · F_SurfaceSetTarget(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x11c9e0 push {r3, r4, r5, lr} */
/* @0x11c9e4 mov r5, #0 */
/* @0x11c9e8 mov r4, r0 */
/* @0x11c9ec mov r1, r5 */
/* @0x11c9f0 str r5, [r0, #0xc] */
/* @0x11c9f4 ldr r0, [sp, #0x10] */
/* @0x11c9f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11c9fc mov r1, r0 */
/* @0x11ca00 mov r0, r5 */
/* @0x11ca04 bl 0x171574 <_Z28YYGML_surface_set_target_extii> */
/* @0x11ca08 vmov s15, r0 */
/* @0x11ca0c vcvt.f64.u32 d7, s15 */
/* @0x11ca10 vmov r0, r1, d7 */
/* @0x11ca14 vmov r2, s14 */
/* @0x11ca18 mov r3, r1 */
/* @0x11ca1c stm r4, {r2, r3} */
/* @0x11ca20 pop {r3, r4, r5, pc} */

/* ── FUNC 0x11ca24 · F_SurfaceSetTargetExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x11ca24 push {r4, r5, r6, lr} */
/* @0x11ca28 mov r1, #0 */
/* @0x11ca2c ldr r5, [sp, #0x10] */
/* @0x11ca30 mov r4, r0 */
/* @0x11ca34 str r1, [r0, #0xc] */
/* @0x11ca38 mov r0, r5 */
/* @0x11ca3c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ca40 mov r1, #1 */
/* @0x11ca44 mov r6, r0 */
/* @0x11ca48 mov r0, r5 */
/* @0x11ca4c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ca50 mov r1, r0 */
/* @0x11ca54 mov r0, r6 */
/* @0x11ca58 bl 0x171574 <_Z28YYGML_surface_set_target_extii> */
/* @0x11ca5c vmov s15, r0 */
/* @0x11ca60 vcvt.f64.u32 d7, s15 */
/* @0x11ca64 vmov r0, r1, d7 */
/* @0x11ca68 vmov r2, s14 */
/* @0x11ca6c mov r3, r1 */
/* @0x11ca70 stm r4, {r2, r3} */
/* @0x11ca74 pop {r4, r5, r6, pc} */

/* ── FUNC 0x11ca78 · F_SurfaceResetTarget(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x11ca78 push {r3, r4, r5, lr} */
/* @0x11ca7c mov r5, #0 */
/* @0x11ca80 str r5, [r0, #0xc] */
/* @0x11ca84 mov r4, r0 */
/* @0x11ca88 bl 0x171808 <_Z26YYGML_surface_reset_targetv> */
/* @0x11ca8c cmp r0, #0 */
/* @0x11ca90 movne r0, r5 */
/* @0x11ca94 moveq r3, r0 */
/* @0x11ca98 movne r3, r0 */
/* @0x11ca9c movtne r3, #0x3ff0 */
/* @0x11caa0 stm r4, {r0, r3} */
/* @0x11caa4 pop {r3, r4, r5, pc} */

/* ── FUNC 0x11caa8 · F_SkeletonSetDrawCollision(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x11caa8 push {r4, r5, r6, lr} */
/* @0x11caac mov r4, r0 */
/* @0x11cab0 mov r5, #0 */
/* @0x11cab4 mov r3, #0 */
/* @0x11cab8 mov r0, r1 */
/* @0x11cabc movt r3, #0xbff0 */
/* @0x11cac0 str r5, [r4, #0xc] */
/* @0x11cac4 str r3, [r4, #0x4] */
/* @0x11cac8 str r5, [r4] */
/* @0x11cacc bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11cad0 subs r6, r0, #0 */
/* @0x11cad4 popeq {r4, r5, r6, pc} */
/* @0x11cad8 ldr r0, [sp, #0x10] */
/* @0x11cadc mov r1, r5 */
/* @0x11cae0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11cae4 mov r3, r5 */
/* @0x11cae8 movt r3, #0x3ff0 */
/* @0x11caec strb r0, [r6, #0x4] */
/* @0x11caf0 str r5, [r4] */
/* @0x11caf4 str r3, [r4, #0x4] */
/* @0x11caf8 pop {r4, r5, r6, pc} */

/* ── FUNC 0x11cafc · F_SkeletonSetAnimation(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x11cafc push {r4, r5, r6, lr} */
/* @0x11cb00 mov r4, r0 */
/* @0x11cb04 mov r0, r1 */
/* @0x11cb08 mov r5, r1 */
/* @0x11cb0c bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11cb10 subs r6, r0, #0 */
/* @0x11cb14 beq 0x11cb54 <_Z22F_SkeletonSetAnimationR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x11cb18 mov r1, #0 */
/* @0x11cb1c ldr r0, [sp, #0x10] */
/* @0x11cb20 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11cb24 mov r1, r0 */
/* @0x11cb28 mov r0, r6 */
/* @0x11cb2c bl 0xbe578 <_ZN17CSkeletonInstance15SelectAnimationEPKc> */
/* @0x11cb30 mov r1, #0 */
/* @0x11cb34 mov r3, r1 */
/* @0x11cb38 mov r2, r1 */
/* @0x11cb3c movt r3, #0x3ff0 */
/* @0x11cb40 mov r0, #0 */
/* @0x11cb44 str r0, [r5, #0x90] */
/* @0x11cb48 str r1, [r4, #0xc] */
/* @0x11cb4c stm r4, {r2, r3} */
/* @0x11cb50 pop {r4, r5, r6, pc} */
/* @0x11cb54 mov r2, r6 */
/* @0x11cb58 mov r3, r6 */
/* @0x11cb5c str r6, [r4, #0xc] */
/* @0x11cb60 stm r4, {r2, r3} */
/* @0x11cb64 pop {r4, r5, r6, pc} */

/* ── FUNC 0x11cb68 · F_SkeletonGetAnimation(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x11cb68 push {r4, r5, r6, r7, r8, lr} */
/* @0x11cb6c mov r4, r0 */
/* @0x11cb70 mov r2, #1 */
/* @0x11cb74 mov r0, r1 */
/* @0x11cb78 str r2, [r4, #0xc] */
/* @0x11cb7c mov r5, #0 */
/* @0x11cb80 str r5, [r4] */
/* @0x11cb84 mov r6, r3 */
/* @0x11cb88 ldr r8, [sp, #0x18] */
/* @0x11cb8c bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11cb90 subs r7, r0, #0 */
/* @0x11cb94 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x11cb98 cmp r6, #1 */
/* @0x11cb9c movne r1, r5 */
/* @0x11cba0 beq 0x11cbbc <_Z22F_SkeletonGetAnimationR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x11cba4 mov r0, r7 */
/* @0x11cba8 bl 0xc01b0 <_ZNK17CSkeletonInstance12GetAnimationEi> */
/* @0x11cbac mov r1, r0 */
/* @0x11cbb0 mov r0, r4 */
/* @0x11cbb4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x11cbb8 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x11cbbc mov r1, r5 */
/* @0x11cbc0 mov r0, r8 */
/* @0x11cbc4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11cbc8 mov r1, r0 */
/* @0x11cbcc b 0x11cba4 <_Z22F_SkeletonGetAnimationR6RValueP9CInstanceS2_iPS_+0x3c> */

/* ── FUNC 0x11cbd0 · F_SkeletonGetDuration(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x11cbd0 push {r4, r5, r6, lr} */
/* @0x11cbd4 mov r4, r0 */
/* @0x11cbd8 mov r5, #0 */
/* @0x11cbdc mov r0, r1 */
/* @0x11cbe0 str r5, [r4, #0xc] */
/* @0x11cbe4 str r5, [r4] */
/* @0x11cbe8 str r5, [r4, #0x4] */
/* @0x11cbec bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11cbf0 subs r6, r0, #0 */
/* @0x11cbf4 popeq {r4, r5, r6, pc} */
/* @0x11cbf8 mov r1, r5 */
/* @0x11cbfc ldr r0, [sp, #0x10] */
/* @0x11cc00 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11cc04 mov r1, r0 */
/* @0x11cc08 mov r0, r6 */
/* @0x11cc0c bl 0xc08c8 <_ZNK17CSkeletonInstance11GetDurationEPc> */
/* @0x11cc10 stm r4, {r0, r1} */
/* @0x11cc14 pop {r4, r5, r6, pc} */

/* ── FUNC 0x11cc18 · F_SkeletonGetFrames(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x11cc18 push {r4, r5, r6, lr} */
/* @0x11cc1c mov r4, r0 */
/* @0x11cc20 mov r5, #0 */
/* @0x11cc24 mov r0, r1 */
/* @0x11cc28 str r5, [r4, #0xc] */
/* @0x11cc2c str r5, [r4] */
/* @0x11cc30 str r5, [r4, #0x4] */
/* @0x11cc34 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11cc38 subs r6, r0, #0 */
/* @0x11cc3c popeq {r4, r5, r6, pc} */
/* @0x11cc40 mov r1, r5 */
/* @0x11cc44 ldr r0, [sp, #0x10] */
/* @0x11cc48 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11cc4c mov r1, r0 */
/* @0x11cc50 mov r0, r6 */
/* @0x11cc54 bl 0xc0930 <_ZNK17CSkeletonInstance9GetFramesEPc> */
/* @0x11cc58 vmov s15, r0 */
/* @0x11cc5c vcvt.f64.s32 d7, s15 */
/* @0x11cc60 vmov r0, r1, d7 */
/* @0x11cc64 vmov r2, s14 */
/* @0x11cc68 mov r3, r1 */
/* @0x11cc6c stm r4, {r2, r3} */
/* @0x11cc70 pop {r4, r5, r6, pc} */

/* ── FUNC 0x11cc74 · F_SkeletonClearAnimation(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x11cc74 mov r3, r0 */
/* @0x11cc78 mov r0, r1 */
/* @0x11cc7c push {r4, r5, r6, lr} */
/* @0x11cc80 mov r4, #0 */
/* @0x11cc84 str r4, [r3, #0xc] */
/* @0x11cc88 str r4, [r3] */
/* @0x11cc8c str r4, [r3, #0x4] */
/* @0x11cc90 ldr r5, [sp, #0x10] */
/* @0x11cc94 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11cc98 subs r6, r0, #0 */
/* @0x11cc9c popeq {r4, r5, r6, pc} */
/* @0x11cca0 mov r1, r4 */
/* @0x11cca4 mov r0, r5 */
/* @0x11cca8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ccac mov r1, r0 */
/* @0x11ccb0 mov r0, r6 */
/* @0x11ccb4 pop {r4, r5, r6, lr} */
/* @0x11ccb8 b 0xbe7f0 <_ZN17CSkeletonInstance14ClearAnimationEi> */

/* ── FUNC 0x11ccbc · F_SkeletonAnimationGetFrame(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x11ccbc push {r4, r5, r6, lr} */
/* @0x11ccc0 mov r4, r0 */
/* @0x11ccc4 mov r5, #0 */
/* @0x11ccc8 mov r0, r1 */
/* @0x11cccc str r5, [r4, #0xc] */
/* @0x11ccd0 str r5, [r4] */
/* @0x11ccd4 str r5, [r4, #0x4] */
/* @0x11ccd8 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11ccdc subs r6, r0, #0 */
/* @0x11cce0 popeq {r4, r5, r6, pc} */
/* @0x11cce4 mov r1, r5 */
/* @0x11cce8 ldr r0, [sp, #0x10] */
/* @0x11ccec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ccf0 mov r1, r0 */
/* @0x11ccf4 mov r0, r6 */
/* @0x11ccf8 bl 0xbe30c <_ZN17CSkeletonInstance10ImageIndexEi> */
/* @0x11ccfc vmov s15, r0 */
/* @0x11cd00 vcvt.f64.f32 d7, s15 */
/* @0x11cd04 vmov r0, r1, d7 */
/* @0x11cd08 vmov r2, s14 */
/* @0x11cd0c mov r3, r1 */
/* @0x11cd10 stm r4, {r2, r3} */
/* @0x11cd14 pop {r4, r5, r6, pc} */
