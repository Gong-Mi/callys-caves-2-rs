/* libyoyo.so 覆盖卡组 0060
 * 函数 0x12c06c..0x12ced8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x12c06c · F_SpriteReplaceAlpha(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x12c06c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x12c070 sub sp, sp, #20 */
/* @0x12c074 mov r1, #0 */
/* @0x12c078 mov r5, r0 */
/* @0x12c07c ldr r4, [sp, #0x38] */
/* @0x12c080 mov r0, r4 */
/* @0x12c084 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c088 mov r6, r0 */
/* @0x12c08c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12c090 cmp r0, #0 */
/* @0x12c094 beq 0x12c128 <_Z20F_SpriteReplaceAlphaR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x12c098 mov r1, #1 */
/* @0x12c09c mov r0, r4 */
/* @0x12c0a0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12c0a4 mov r1, #2 */
/* @0x12c0a8 mov r9, r0 */
/* @0x12c0ac mov r0, r4 */
/* @0x12c0b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c0b4 mov r1, #3 */
/* @0x12c0b8 mov r8, r0 */
/* @0x12c0bc mov r0, r4 */
/* @0x12c0c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c0c4 mov r1, #4 */
/* @0x12c0c8 mov r7, r0 */
/* @0x12c0cc mov r0, r4 */
/* @0x12c0d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c0d4 mov r1, #5 */
/* @0x12c0d8 mov r11, r0 */
/* @0x12c0dc mov r0, r4 */
/* @0x12c0e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c0e4 mov r1, #6 */
/* @0x12c0e8 mov r10, r0 */
/* @0x12c0ec mov r0, r4 */
/* @0x12c0f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c0f4 cmp r11, #0 */
/* @0x12c0f8 str r10, [sp, #0x4] */
/* @0x12c0fc mov r1, r9 */
/* @0x12c100 movle r11, #0 */
/* @0x12c104 movgt r11, #1 */
/* @0x12c108 cmp r7, #0 */
/* @0x12c10c str r11, [sp] */
/* @0x12c110 mov r2, r8 */
/* @0x12c114 movle r3, #0 */
/* @0x12c118 movgt r3, #1 */
/* @0x12c11c str r0, [sp, #0x8] */
/* @0x12c120 mov r0, r6 */
/* @0x12c124 bl 0x1ef07c <_Z20Sprite_Replace_AlphaiPKcibbii> */
/* @0x12c128 mov r2, #0 */
/* @0x12c12c mov r3, r2 */
/* @0x12c130 movt r2, #0xbff0 */
/* @0x12c134 str r3, [r5, #0xc] */
/* @0x12c138 str r2, [r5, #0x4] */
/* @0x12c13c str r3, [r5] */
/* @0x12c140 add sp, sp, #20 */
/* @0x12c144 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x12c148 · F_SpriteDelete(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x12c148 push {r3, r4, r5, lr} */
/* @0x12c14c mov r1, #0 */
/* @0x12c150 mov r4, r0 */
/* @0x12c154 ldr r0, [sp, #0x10] */
/* @0x12c158 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c15c mov r5, r0 */
/* @0x12c160 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12c164 cmp r0, #0 */
/* @0x12c168 beq 0x12c190 <_Z14F_SpriteDeleteR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12c16c mov r0, r5 */
/* @0x12c170 bl 0x1ef1ec <_Z13Sprite_Deletei> */
/* @0x12c174 vmov s15, r0 */
/* @0x12c178 vcvt.f64.s32 d7, s15 */
/* @0x12c17c vmov r2, r3, d7 */
/* @0x12c180 mov r1, #0 */
/* @0x12c184 stm r4, {r2, r3} */
/* @0x12c188 str r1, [r4, #0xc] */
/* @0x12c18c pop {r3, r4, r5, pc} */
/* @0x12c190 mov r3, #0 */
/* @0x12c194 mov r2, #0 */
/* @0x12c198 movt r3, #0xbff0 */
/* @0x12c19c b 0x12c180 <_Z14F_SpriteDeleteR6RValueP9CInstanceS2_iPS_+0x38> */

/* ── FUNC 0x12c1a0 · F_BackgroundExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x12c1a0 push {r3, r4, r5, lr} */
/* @0x12c1a4 mov r4, #0 */
/* @0x12c1a8 mov r5, r0 */
/* @0x12c1ac mov r1, r4 */
/* @0x12c1b0 str r4, [r0, #0xc] */
/* @0x12c1b4 str r4, [r0] */
/* @0x12c1b8 str r4, [r0, #0x4] */
/* @0x12c1bc ldr r0, [sp, #0x10] */
/* @0x12c1c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c1c4 bl 0xc3640 <_Z17Background_Existsi> */
/* @0x12c1c8 cmp r0, r4 */
/* @0x12c1cc strne r4, [r5] */
/* @0x12c1d0 movne r3, r4 */
/* @0x12c1d4 movtne r3, #0x3ff0 */
/* @0x12c1d8 strne r3, [r5, #0x4] */
/* @0x12c1dc pop {r3, r4, r5, pc} */

/* ── FUNC 0x12c1e0 · F_BackgroundGetName(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x12c1e0 push {r4, lr} */
/* @0x12c1e4 mov r1, #0 */
/* @0x12c1e8 mov r4, r0 */
/* @0x12c1ec ldr r0, [sp, #0x8] */
/* @0x12c1f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c1f4 bl 0xc3688 <_Z15Background_Namei> */
/* @0x12c1f8 mov r1, r0 */
/* @0x12c1fc mov r0, r4 */
/* @0x12c200 pop {r4, lr} */
/* @0x12c204 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x12c208 · F_BackgroundGetWidth(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x12c208 push {r4, lr} */
/* @0x12c20c mov r1, #0 */
/* @0x12c210 mov r4, r0 */
/* @0x12c214 ldr r0, [sp, #0x8] */
/* @0x12c218 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c21c bl 0xc3794 <_Z15Background_Datai> */
/* @0x12c220 cmp r0, #0 */
/* @0x12c224 beq 0x12c248 <_Z20F_BackgroundGetWidthR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12c228 bl 0xc2d78 <_ZN11CBackground8GetWidthEv> */
/* @0x12c22c vmov s15, r0 */
/* @0x12c230 vcvt.f64.s32 d7, s15 */
/* @0x12c234 vmov r2, r3, d7 */
/* @0x12c238 mov r1, #0 */
/* @0x12c23c stm r4, {r2, r3} */
/* @0x12c240 str r1, [r4, #0xc] */
/* @0x12c244 pop {r4, pc} */
/* @0x12c248 mov r3, #0 */
/* @0x12c24c mov r2, #0 */
/* @0x12c250 movt r3, #0xbff0 */
/* @0x12c254 b 0x12c238 <_Z20F_BackgroundGetWidthR6RValueP9CInstanceS2_iPS_+0x30> */

/* ── FUNC 0x12c258 · F_BackgroundGetHeight(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x12c258 push {r4, lr} */
/* @0x12c25c mov r1, #0 */
/* @0x12c260 mov r4, r0 */
/* @0x12c264 ldr r0, [sp, #0x8] */
/* @0x12c268 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c26c bl 0xc3794 <_Z15Background_Datai> */
/* @0x12c270 cmp r0, #0 */
/* @0x12c274 beq 0x12c298 <_Z21F_BackgroundGetHeightR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12c278 bl 0xc2d80 <_ZN11CBackground9GetHeightEv> */
/* @0x12c27c vmov s15, r0 */
/* @0x12c280 vcvt.f64.s32 d7, s15 */
/* @0x12c284 vmov r2, r3, d7 */
/* @0x12c288 mov r1, #0 */
/* @0x12c28c stm r4, {r2, r3} */
/* @0x12c290 str r1, [r4, #0xc] */
/* @0x12c294 pop {r4, pc} */
/* @0x12c298 mov r3, #0 */
/* @0x12c29c mov r2, #0 */
/* @0x12c2a0 movt r3, #0xbff0 */
/* @0x12c2a4 b 0x12c288 <_Z21F_BackgroundGetHeightR6RValueP9CInstanceS2_iPS_+0x30> */

/* ── FUNC 0x12c2a8 · F_BackgroundGetTransparent(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x12c2a8 push {r4, lr} */
/* @0x12c2ac mov r1, #0 */
/* @0x12c2b0 mov r4, r0 */
/* @0x12c2b4 ldr r0, [sp, #0x8] */
/* @0x12c2b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c2bc bl 0xc3794 <_Z15Background_Datai> */
/* @0x12c2c0 cmp r0, #0 */
/* @0x12c2c4 beq 0x12c2e8 <_Z26F_BackgroundGetTransparentR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12c2c8 bl 0xc2d88 <_ZN11CBackground14GetTransparentEv> */
/* @0x12c2cc vmov s15, r0 */
/* @0x12c2d0 vcvt.f64.s32 d7, s15 */
/* @0x12c2d4 vmov r2, r3, d7 */
/* @0x12c2d8 mov r1, #0 */
/* @0x12c2dc stm r4, {r2, r3} */
/* @0x12c2e0 str r1, [r4, #0xc] */
/* @0x12c2e4 pop {r4, pc} */
/* @0x12c2e8 mov r3, #0 */
/* @0x12c2ec mov r2, #0 */
/* @0x12c2f0 movt r3, #0xbff0 */
/* @0x12c2f4 b 0x12c2d8 <_Z26F_BackgroundGetTransparentR6RValueP9CInstanceS2_iPS_+0x30> */

/* ── FUNC 0x12c2f8 · F_BackgroundGetSmooth(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x12c2f8 push {r4, lr} */
/* @0x12c2fc mov r1, #0 */
/* @0x12c300 mov r4, r0 */
/* @0x12c304 ldr r0, [sp, #0x8] */
/* @0x12c308 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c30c bl 0xc3794 <_Z15Background_Datai> */
/* @0x12c310 cmp r0, #0 */
/* @0x12c314 beq 0x12c338 <_Z21F_BackgroundGetSmoothR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12c318 bl 0xc2d90 <_ZN11CBackground6SmoothEv> */
/* @0x12c31c vmov s15, r0 */
/* @0x12c320 vcvt.f64.s32 d7, s15 */
/* @0x12c324 vmov r2, r3, d7 */
/* @0x12c328 mov r1, #0 */
/* @0x12c32c stm r4, {r2, r3} */
/* @0x12c330 str r1, [r4, #0xc] */
/* @0x12c334 pop {r4, pc} */
/* @0x12c338 mov r3, #0 */
/* @0x12c33c mov r2, #0 */
/* @0x12c340 movt r3, #0xbff0 */
/* @0x12c344 b 0x12c328 <_Z21F_BackgroundGetSmoothR6RValueP9CInstanceS2_iPS_+0x30> */

/* ── FUNC 0x12c348 · F_BackgroundGetPreload(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x12c348 push {r4, lr} */
/* @0x12c34c mov r1, #0 */
/* @0x12c350 mov r4, r0 */
/* @0x12c354 ldr r0, [sp, #0x8] */
/* @0x12c358 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c35c bl 0xc3794 <_Z15Background_Datai> */
/* @0x12c360 cmp r0, #0 */
/* @0x12c364 beq 0x12c388 <_Z22F_BackgroundGetPreloadR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12c368 bl 0xc2d98 <_ZN11CBackground10GetPreloadEv> */
/* @0x12c36c vmov s15, r0 */
/* @0x12c370 vcvt.f64.s32 d7, s15 */
/* @0x12c374 vmov r2, r3, d7 */
/* @0x12c378 mov r1, #0 */
/* @0x12c37c stm r4, {r2, r3} */
/* @0x12c380 str r1, [r4, #0xc] */
/* @0x12c384 pop {r4, pc} */
/* @0x12c388 mov r3, #0 */
/* @0x12c38c mov r2, #0 */
/* @0x12c390 movt r3, #0xbff0 */
/* @0x12c394 b 0x12c378 <_Z22F_BackgroundGetPreloadR6RValueP9CInstanceS2_iPS_+0x30> */

/* ── FUNC 0x12c398 · F_BackgroundSetAlphaFromBackground(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x12c398 push {r4, r5, r6, lr} */
/* @0x12c39c mov r1, #0 */
/* @0x12c3a0 ldr r4, [sp, #0x10] */
/* @0x12c3a4 mov r0, r4 */
/* @0x12c3a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c3ac mov r1, #1 */
/* @0x12c3b0 mov r5, r0 */
/* @0x12c3b4 mov r0, r4 */
/* @0x12c3b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c3bc mov r6, r0 */
/* @0x12c3c0 mov r0, r5 */
/* @0x12c3c4 bl 0xc3794 <_Z15Background_Datai> */
/* @0x12c3c8 mov r4, r0 */
/* @0x12c3cc mov r0, r6 */
/* @0x12c3d0 bl 0xc3794 <_Z15Background_Datai> */
/* @0x12c3d4 cmp r0, #0 */
/* @0x12c3d8 cmpne r4, #0 */
/* @0x12c3dc mov r1, r0 */
/* @0x12c3e0 popeq {r4, r5, r6, pc} */
/* @0x12c3e4 mov r0, r4 */
/* @0x12c3e8 pop {r4, r5, r6, lr} */
/* @0x12c3ec b 0xc1f50 <_ZN11CBackground22SetAlphaFromBackgroundEPS_> */

/* ── FUNC 0x12c3f0 · F_BackgroundCreateFromScreen(RValue&, CInstance*, CInstance*, int, RValue*) · size=372 · insn=93 */
/* @0x12c3f0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x12c3f4 sub sp, sp, #8 */
/* @0x12c3f8 mov r6, #0 */
/* @0x12c3fc str r6, [r0, #0xc] */
/* @0x12c400 ldr r4, [sp, #0x28] */
/* @0x12c404 mov r5, r0 */
/* @0x12c408 mov r7, r3 */
/* @0x12c40c bl 0xc41f0 <_Z19Background_AddEmptyv> */
/* @0x12c410 mov r9, r0 */
/* @0x12c414 bl 0xc3794 <_Z15Background_Datai> */
/* @0x12c418 vmov s15, r9 */
/* @0x12c41c mov r1, r6 */
/* @0x12c420 vcvt.f64.s32 d7, s15 */
/* @0x12c424 vmov r2, r3, d7 */
/* @0x12c428 stm r5, {r2, r3} */
/* @0x12c42c mov r8, r0 */
/* @0x12c430 mov r0, r4 */
/* @0x12c434 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c438 mov r1, #1 */
/* @0x12c43c mov r10, r0 */
/* @0x12c440 mov r0, r4 */
/* @0x12c444 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c448 mov r1, #2 */
/* @0x12c44c mov r9, r0 */
/* @0x12c450 mov r0, r4 */
/* @0x12c454 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c458 mov r1, #3 */
/* @0x12c45c mov r5, r0 */
/* @0x12c460 mov r0, r4 */
/* @0x12c464 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c468 mov r2, r5 */
/* @0x12c46c mov r1, r9 */
/* @0x12c470 mov r3, r0 */
/* @0x12c474 mov r0, r10 */
/* @0x12c478 bl 0x169b34 <_Z22GR_D3D_Screenshot_Partiiii> */
/* @0x12c47c subs r5, r0, #0 */
/* @0x12c480 beq 0x12c4a4 <_Z28F_BackgroundCreateFromScreenR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x12c484 cmp r7, #6 */
/* @0x12c488 beq 0x12c4ac <_Z28F_BackgroundCreateFromScreenR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x12c48c cmp r7, #7 */
/* @0x12c490 beq 0x12c4fc <_Z28F_BackgroundCreateFromScreenR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x12c494 ldr r3, [r5] */
/* @0x12c498 mov r0, r5 */
/* @0x12c49c ldr r3, [r3, #0x4] */
/* @0x12c4a0 blx r3 */
/* @0x12c4a4 add sp, sp, #8 */
/* @0x12c4a8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x12c4ac mov r0, r4 */
/* @0x12c4b0 mov r1, #4 */
/* @0x12c4b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c4b8 mov r1, #5 */
/* @0x12c4bc cmp r0, r6 */
/* @0x12c4c0 mov r0, r4 */
/* @0x12c4c4 movle r7, #0 */
/* @0x12c4c8 movgt r7, #1 */
/* @0x12c4cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c4d0 eor r3, r7, #1 */
/* @0x12c4d4 str r6, [sp] */
/* @0x12c4d8 mov r2, r7 */
/* @0x12c4dc str r3, [sp, #0x4] */
/* @0x12c4e0 mov r1, r5 */
/* @0x12c4e4 cmp r0, r6 */
/* @0x12c4e8 mov r0, r8 */
/* @0x12c4ec movle r3, #0 */
/* @0x12c4f0 movgt r3, #1 */
/* @0x12c4f4 bl 0xc244c <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb> */
/* @0x12c4f8 b 0x12c494 <_Z28F_BackgroundCreateFromScreenR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x12c4fc mov r0, r4 */
/* @0x12c500 mov r1, #4 */
/* @0x12c504 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c508 mov r1, #5 */
/* @0x12c50c mov r9, r0 */
/* @0x12c510 mov r0, r4 */
/* @0x12c514 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c518 mov r1, #6 */
/* @0x12c51c mov r7, r0 */
/* @0x12c520 mov r0, r4 */
/* @0x12c524 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c528 cmp r9, #0 */
/* @0x12c52c str r6, [sp, #0x4] */
/* @0x12c530 mov r1, r5 */
/* @0x12c534 movle r2, #0 */
/* @0x12c538 movgt r2, #1 */
/* @0x12c53c cmp r7, #0 */
/* @0x12c540 movle r3, #0 */
/* @0x12c544 movgt r3, #1 */
/* @0x12c548 cmp r0, #0 */
/* @0x12c54c mov r0, r8 */
/* @0x12c550 movle r12, #0 */
/* @0x12c554 movgt r12, #1 */
/* @0x12c558 str r12, [sp] */
/* @0x12c55c bl 0xc244c <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb> */
/* @0x12c560 b 0x12c494 <_Z28F_BackgroundCreateFromScreenR6RValueP9CInstanceS2_iPS_+0xa4> */

/* ── FUNC 0x12c564 · F_BackgroundCreateFromSurface(RValue&, CInstance*, CInstance*, int, RValue*) · size=284 · insn=71 */
/* @0x12c564 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x12c568 sub sp, sp, #8 */
/* @0x12c56c mov r6, #0 */
/* @0x12c570 str r6, [r0, #0xc] */
/* @0x12c574 ldr r4, [sp, #0x28] */
/* @0x12c578 mov r5, r0 */
/* @0x12c57c mov r8, r3 */
/* @0x12c580 bl 0xc41f0 <_Z19Background_AddEmptyv> */
/* @0x12c584 mov r9, r0 */
/* @0x12c588 bl 0xc3794 <_Z15Background_Datai> */
/* @0x12c58c vmov s15, r9 */
/* @0x12c590 mov r1, r6 */
/* @0x12c594 vcvt.f64.s32 d7, s15 */
/* @0x12c598 vmov r2, r3, d7 */
/* @0x12c59c stm r5, {r2, r3} */
/* @0x12c5a0 mov r7, r0 */
/* @0x12c5a4 mov r0, r4 */
/* @0x12c5a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c5ac mov r1, #1 */
/* @0x12c5b0 mov r5, r0 */
/* @0x12c5b4 mov r0, r4 */
/* @0x12c5b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c5bc mov r1, #2 */
/* @0x12c5c0 mov r10, r0 */
/* @0x12c5c4 mov r0, r4 */
/* @0x12c5c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c5cc mov r1, #3 */
/* @0x12c5d0 mov r9, r0 */
/* @0x12c5d4 mov r0, r4 */
/* @0x12c5d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c5dc mov r1, #4 */
/* @0x12c5e0 mov r6, r0 */
/* @0x12c5e4 mov r0, r4 */
/* @0x12c5e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c5ec mov r1, r10 */
/* @0x12c5f0 mov r2, r9 */
/* @0x12c5f4 mov r3, r6 */
/* @0x12c5f8 str r0, [sp] */
/* @0x12c5fc mov r0, r5 */
/* @0x12c600 bl 0x1720e4 <_Z26GR_Surface_Screenshot_Partiiiii> */
/* @0x12c604 subs r5, r0, #0 */
/* @0x12c608 beq 0x12c678 <_Z29F_BackgroundCreateFromSurfaceR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x12c60c mov r1, #5 */
/* @0x12c610 mov r0, r4 */
/* @0x12c614 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12c618 mov r1, #6 */
/* @0x12c61c eor r9, r0, #1 */
/* @0x12c620 mov r6, r0 */
/* @0x12c624 mov r0, r4 */
/* @0x12c628 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12c62c cmp r8, #7 */
/* @0x12c630 uxtb r9, r9 */
/* @0x12c634 mov r10, r0 */
/* @0x12c638 moveq r0, #1 */
/* @0x12c63c beq 0x12c64c <_Z29F_BackgroundCreateFromSurfaceR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x12c640 mov r0, r4 */
/* @0x12c644 mov r1, #7 */
/* @0x12c648 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12c64c str r0, [sp] */
/* @0x12c650 mov r3, r10 */
/* @0x12c654 mov r0, r7 */
/* @0x12c658 str r9, [sp, #0x4] */
/* @0x12c65c mov r2, r6 */
/* @0x12c660 mov r1, r5 */
/* @0x12c664 bl 0xc244c <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb> */
/* @0x12c668 ldr r3, [r5] */
/* @0x12c66c mov r0, r5 */
/* @0x12c670 ldr r3, [r3, #0x4] */
/* @0x12c674 blx r3 */
/* @0x12c678 add sp, sp, #8 */
/* @0x12c67c pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x12c680 · F_BackgroundCreateColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x12c680 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x12c684 mov r6, #0 */
/* @0x12c688 str r6, [r0, #0xc] */
/* @0x12c68c mov r7, r3 */
/* @0x12c690 mov r5, r0 */
/* @0x12c694 ldr r4, [sp, #0x20] */
/* @0x12c698 bl 0xc41f0 <_Z19Background_AddEmptyv> */
/* @0x12c69c mov r9, r0 */
/* @0x12c6a0 bl 0xc3794 <_Z15Background_Datai> */
/* @0x12c6a4 vmov s15, r9 */
/* @0x12c6a8 cmp r7, #4 */
/* @0x12c6ac mov r1, r6 */
/* @0x12c6b0 vcvt.f64.s32 d7, s15 */
/* @0x12c6b4 vmov r2, r3, d7 */
/* @0x12c6b8 stm r5, {r2, r3} */
/* @0x12c6bc mov r8, r0 */
/* @0x12c6c0 mov r0, r4 */
/* @0x12c6c4 beq 0x12c70c <_Z23F_BackgroundCreateColorR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x12c6c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c6cc mov r1, #1 */
/* @0x12c6d0 mov r6, r0 */
/* @0x12c6d4 mov r0, r4 */
/* @0x12c6d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c6dc mov r1, #2 */
/* @0x12c6e0 mov r5, r0 */
/* @0x12c6e4 mov r0, r4 */
/* @0x12c6e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c6ec mov r1, r6 */
/* @0x12c6f0 mov r2, r5 */
/* @0x12c6f4 mov r12, #1 */
/* @0x12c6f8 str r12, [sp, #0x20] */
/* @0x12c6fc mov r3, r0 */
/* @0x12c700 mov r0, r8 */
/* @0x12c704 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x12c708 b 0xc2a40 <_ZN11CBackground11CreateColorEiijb> */
/* @0x12c70c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c710 mov r1, #1 */
/* @0x12c714 mov r7, r0 */
/* @0x12c718 mov r0, r4 */
/* @0x12c71c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c720 mov r1, #2 */
/* @0x12c724 mov r6, r0 */
/* @0x12c728 mov r0, r4 */
/* @0x12c72c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c730 mov r1, #3 */
/* @0x12c734 mov r5, r0 */
/* @0x12c738 mov r0, r4 */
/* @0x12c73c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12c740 mov r1, r7 */
/* @0x12c744 mov r2, r6 */
/* @0x12c748 mov r3, r5 */
/* @0x12c74c str r0, [sp, #0x20] */
/* @0x12c750 mov r0, r8 */
/* @0x12c754 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x12c758 b 0xc2a40 <_ZN11CBackground11CreateColorEiijb> */

/* ── FUNC 0x12c75c · F_BackgroundCreateGradient(RValue&, CInstance*, CInstance*, int, RValue*) · size=208 · insn=52 */
/* @0x12c75c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x12c760 sub sp, sp, #20 */
/* @0x12c764 mov r6, #0 */
/* @0x12c768 str r6, [r0, #0xc] */
/* @0x12c76c ldr r4, [sp, #0x38] */
/* @0x12c770 mov r10, r3 */
/* @0x12c774 mov r5, r0 */
/* @0x12c778 bl 0xc41f0 <_Z19Background_AddEmptyv> */
/* @0x12c77c bl 0xc3794 <_Z15Background_Datai> */
/* @0x12c780 mov r7, r0 */
/* @0x12c784 bl 0xc41f0 <_Z19Background_AddEmptyv> */
/* @0x12c788 mov r1, r6 */
/* @0x12c78c vmov s15, r0 */
/* @0x12c790 mov r0, r4 */
/* @0x12c794 vcvt.f64.s32 d7, s15 */
/* @0x12c798 vmov r2, r3, d7 */
/* @0x12c79c stm r5, {r2, r3} */
/* @0x12c7a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c7a4 mov r1, #1 */
/* @0x12c7a8 mov r8, r0 */
/* @0x12c7ac mov r0, r4 */
/* @0x12c7b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c7b4 mov r1, #2 */
/* @0x12c7b8 mov r6, r0 */
/* @0x12c7bc mov r0, r4 */
/* @0x12c7c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c7c4 mov r1, #3 */
/* @0x12c7c8 mov r5, r0 */
/* @0x12c7cc mov r0, r4 */
/* @0x12c7d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c7d4 mov r1, #4 */
/* @0x12c7d8 mov r9, r0 */
/* @0x12c7dc mov r0, r4 */
/* @0x12c7e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c7e4 cmp r10, #5 */
/* @0x12c7e8 moveq r3, #1 */
/* @0x12c7ec mov r11, r0 */
/* @0x12c7f0 beq 0x12c804 <_Z26F_BackgroundCreateGradientR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x12c7f4 mov r0, r4 */
/* @0x12c7f8 mov r1, #5 */
/* @0x12c7fc bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12c800 mov r3, r0 */
/* @0x12c804 str r3, [sp, #0x8] */
/* @0x12c808 mov r0, r7 */
/* @0x12c80c str r9, [sp] */
/* @0x12c810 mov r1, r8 */
/* @0x12c814 str r11, [sp, #0x4] */
/* @0x12c818 mov r2, r6 */
/* @0x12c81c mov r3, r5 */
/* @0x12c820 bl 0xc2ac0 <_ZN11CBackground14CreateGradientEiijjib> */
/* @0x12c824 add sp, sp, #20 */
/* @0x12c828 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x12c82c · F_BackgroundAdd(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x12c82c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x12c830 mov r1, #0 */
/* @0x12c834 ldr r4, [sp, #0x20] */
/* @0x12c838 mov r5, r0 */
/* @0x12c83c str r1, [r0, #0xc] */
/* @0x12c840 mov r9, r3 */
/* @0x12c844 mov r0, r4 */
/* @0x12c848 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12c84c mov r1, #1 */
/* @0x12c850 mov r7, r0 */
/* @0x12c854 mov r0, r4 */
/* @0x12c858 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12c85c mov r1, #2 */
/* @0x12c860 mov r6, r0 */
/* @0x12c864 mov r0, r4 */
/* @0x12c868 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12c86c cmp r9, #3 */
/* @0x12c870 moveq r3, #1 */
/* @0x12c874 mov r8, r0 */
/* @0x12c878 beq 0x12c88c <_Z15F_BackgroundAddR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x12c87c mov r0, r4 */
/* @0x12c880 mov r1, #3 */
/* @0x12c884 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12c888 mov r3, r0 */
/* @0x12c88c mov r1, r6 */
/* @0x12c890 mov r2, r8 */
/* @0x12c894 mov r0, r7 */
/* @0x12c898 bl 0xc38d4 <_Z14Background_AddPKcbbb> */
/* @0x12c89c vmov s15, r0 */
/* @0x12c8a0 vcvt.f64.s32 d7, s15 */
/* @0x12c8a4 vmov r0, r1, d7 */
/* @0x12c8a8 vmov r2, s14 */
/* @0x12c8ac mov r3, r1 */
/* @0x12c8b0 stm r5, {r2, r3} */
/* @0x12c8b4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x12c8b8 · F_BackgroundAddAlpha(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x12c8b8 push {r4, r5, r6, lr} */
/* @0x12c8bc mov r1, #0 */
/* @0x12c8c0 ldr r5, [sp, #0x10] */
/* @0x12c8c4 mov r4, r0 */
/* @0x12c8c8 str r1, [r0, #0xc] */
/* @0x12c8cc mov r0, r5 */
/* @0x12c8d0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12c8d4 mov r1, #1 */
/* @0x12c8d8 mov r6, r0 */
/* @0x12c8dc mov r0, r5 */
/* @0x12c8e0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12c8e4 mov r1, r0 */
/* @0x12c8e8 mov r0, r6 */
/* @0x12c8ec bl 0xc3ccc <_Z20Background_Add_AlphaPKcb> */
/* @0x12c8f0 vmov s15, r0 */
/* @0x12c8f4 vcvt.f64.s32 d7, s15 */
/* @0x12c8f8 vmov r0, r1, d7 */
/* @0x12c8fc vmov r2, s14 */
/* @0x12c900 mov r3, r1 */
/* @0x12c904 stm r4, {r2, r3} */
/* @0x12c908 pop {r4, r5, r6, pc} */

/* ── FUNC 0x12c90c · F_BackgroundReplace(RValue&, CInstance*, CInstance*, int, RValue*) · size=284 · insn=71 */
/* @0x12c90c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x12c910 sub sp, sp, #12 */
/* @0x12c914 mov r1, #0 */
/* @0x12c918 mov r5, r0 */
/* @0x12c91c ldr r4, [sp, #0x28] */
/* @0x12c920 mov r7, r3 */
/* @0x12c924 mov r0, r4 */
/* @0x12c928 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c92c mov r6, r0 */
/* @0x12c930 bl 0xc3794 <_Z15Background_Datai> */
/* @0x12c934 subs r8, r0, #0 */
/* @0x12c938 beq 0x12ca0c <_Z19F_BackgroundReplaceR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x12c93c cmp r7, #5 */
/* @0x12c940 mov r0, r4 */
/* @0x12c944 mov r1, #1 */
/* @0x12c948 beq 0x12c9bc <_Z19F_BackgroundReplaceR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x12c94c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12c950 mov r1, #2 */
/* @0x12c954 mov r8, r0 */
/* @0x12c958 mov r0, r4 */
/* @0x12c95c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12c960 mov r1, #3 */
/* @0x12c964 mov r7, r0 */
/* @0x12c968 mov r0, r4 */
/* @0x12c96c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12c970 mov r12, #1 */
/* @0x12c974 mov r1, r8 */
/* @0x12c978 mov r2, r7 */
/* @0x12c97c str r12, [sp] */
/* @0x12c980 mov r3, r0 */
/* @0x12c984 mov r0, r6 */
/* @0x12c988 bl 0xc3aa4 <_Z18Background_ReplaceiPKcbbb> */
/* @0x12c98c cmp r0, #0 */
/* @0x12c990 mov r3, #0 */
/* @0x12c994 str r3, [r5, #0xc] */
/* @0x12c998 movne r2, #0 */
/* @0x12c99c movtne r2, #0x3ff0 */
/* @0x12c9a0 bne 0x12c9ac <_Z19F_BackgroundReplaceR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x12c9a4 mov r3, #0 */
/* @0x12c9a8 mov r2, r3 */
/* @0x12c9ac str r3, [r5] */
/* @0x12c9b0 str r2, [r5, #0x4] */
/* @0x12c9b4 add sp, sp, #12 */
/* @0x12c9b8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x12c9bc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12c9c0 mov r1, #2 */
/* @0x12c9c4 mov r9, r0 */
/* @0x12c9c8 mov r0, r4 */
/* @0x12c9cc bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12c9d0 mov r1, #3 */
/* @0x12c9d4 mov r8, r0 */
/* @0x12c9d8 mov r0, r4 */
/* @0x12c9dc bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12c9e0 mov r1, #4 */
/* @0x12c9e4 mov r7, r0 */
/* @0x12c9e8 mov r0, r4 */
/* @0x12c9ec bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12c9f0 mov r1, r9 */
/* @0x12c9f4 mov r2, r8 */
/* @0x12c9f8 mov r3, r7 */
/* @0x12c9fc str r0, [sp] */
/* @0x12ca00 mov r0, r6 */
/* @0x12ca04 bl 0xc3aa4 <_Z18Background_ReplaceiPKcbbb> */
/* @0x12ca08 b 0x12c98c <_Z19F_BackgroundReplaceR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12ca0c ldr r0, [pc, #0x10] */
/* @0x12ca10 mov r1, r8 */
/* @0x12ca14 add r0, pc, r0 */
/* @0x12ca18 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12ca1c str r8, [r5, #0xc] */
/* @0x12ca20 b 0x12c9a4 <_Z19F_BackgroundReplaceR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x12ca24 eoreq r0, r1, r4, lsr #21 */

/* ── FUNC 0x12ca28 · F_BackgroundReplaceAlpha(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x12ca28 push {r3, r4, r5, r6, r7, lr} */
/* @0x12ca2c mov r1, #0 */
/* @0x12ca30 ldr r5, [sp, #0x18] */
/* @0x12ca34 mov r4, r0 */
/* @0x12ca38 mov r0, r5 */
/* @0x12ca3c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ca40 mov r6, r0 */
/* @0x12ca44 bl 0xc3794 <_Z15Background_Datai> */
/* @0x12ca48 subs r7, r0, #0 */
/* @0x12ca4c beq 0x12caac <_Z24F_BackgroundReplaceAlphaR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x12ca50 mov r1, #1 */
/* @0x12ca54 mov r0, r5 */
/* @0x12ca58 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12ca5c mov r1, #2 */
/* @0x12ca60 mov r7, r0 */
/* @0x12ca64 mov r0, r5 */
/* @0x12ca68 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12ca6c mov r1, r7 */
/* @0x12ca70 mov r2, r0 */
/* @0x12ca74 mov r0, r6 */
/* @0x12ca78 bl 0xc3e60 <_Z24Background_Replace_AlphaiPKcb> */
/* @0x12ca7c mov r3, #0 */
/* @0x12ca80 str r3, [r4, #0xc] */
/* @0x12ca84 cmp r0, r3 */
/* @0x12ca88 bne 0x12caa0 <_Z24F_BackgroundReplaceAlphaR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x12ca8c mov r3, #0 */
/* @0x12ca90 mov r2, r3 */
/* @0x12ca94 str r3, [r4] */
/* @0x12ca98 str r2, [r4, #0x4] */
/* @0x12ca9c pop {r3, r4, r5, r6, r7, pc} */
/* @0x12caa0 mov r2, #0 */
/* @0x12caa4 movt r2, #0x3ff0 */
/* @0x12caa8 b 0x12ca94 <_Z24F_BackgroundReplaceAlphaR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x12caac ldr r0, [pc, #0x10] */
/* @0x12cab0 mov r1, r7 */
/* @0x12cab4 add r0, pc, r0 */
/* @0x12cab8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12cabc str r7, [r4, #0xc] */
/* @0x12cac0 b 0x12ca8c <_Z24F_BackgroundReplaceAlphaR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x12cac4 eoreq r0, r1, r4, lsl #20 */

/* ── FUNC 0x12cac8 · F_BackgroundDelete(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x12cac8 push {r4, r5, r6, lr} */
/* @0x12cacc mov r1, #0 */
/* @0x12cad0 mov r4, r0 */
/* @0x12cad4 ldr r0, [sp, #0x10] */
/* @0x12cad8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12cadc mov r6, r0 */
/* @0x12cae0 bl 0xc3640 <_Z17Background_Existsi> */
/* @0x12cae4 subs r5, r0, #0 */
/* @0x12cae8 bne 0x12cb14 <_Z18F_BackgroundDeleteR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x12caec ldr r0, [pc, #0x44] */
/* @0x12caf0 mov r1, r5 */
/* @0x12caf4 add r0, pc, r0 */
/* @0x12caf8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12cafc str r5, [r4, #0xc] */
/* @0x12cb00 mov r3, #0 */
/* @0x12cb04 mov r2, r3 */
/* @0x12cb08 str r3, [r4] */
/* @0x12cb0c str r2, [r4, #0x4] */
/* @0x12cb10 pop {r4, r5, r6, pc} */
/* @0x12cb14 mov r0, r6 */
/* @0x12cb18 bl 0xc3f74 <_Z17Background_Deletei> */
/* @0x12cb1c mov r3, #0 */
/* @0x12cb20 str r3, [r4, #0xc] */
/* @0x12cb24 cmp r0, r3 */
/* @0x12cb28 movne r2, #0 */
/* @0x12cb2c movtne r2, #0x3ff0 */
/* @0x12cb30 bne 0x12cb08 <_Z18F_BackgroundDeleteR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12cb34 b 0x12cb00 <_Z18F_BackgroundDeleteR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x12cb38 .word 0x002109f0 */

/* ── FUNC 0x12cb3c · F_BackgroundDuplicate(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x12cb3c push {r3, r4, r5, lr} */
/* @0x12cb40 mov r1, #0 */
/* @0x12cb44 mov r4, r0 */
/* @0x12cb48 ldr r0, [sp, #0x10] */
/* @0x12cb4c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12cb50 mov r5, r0 */
/* @0x12cb54 bl 0xc3640 <_Z17Background_Existsi> */
/* @0x12cb58 subs r1, r0, #0 */
/* @0x12cb5c beq 0x12cb84 <_Z21F_BackgroundDuplicateR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12cb60 mov r0, r5 */
/* @0x12cb64 bl 0xc3ff4 <_Z20Background_Duplicatei> */
/* @0x12cb68 vmov s15, r0 */
/* @0x12cb6c vcvt.f64.s32 d7, s15 */
/* @0x12cb70 vmov r2, r3, d7 */
/* @0x12cb74 mov r1, #0 */
/* @0x12cb78 stm r4, {r2, r3} */
/* @0x12cb7c str r1, [r4, #0xc] */
/* @0x12cb80 pop {r3, r4, r5, pc} */
/* @0x12cb84 ldr r0, [pc, #0x14] */
/* @0x12cb88 add r0, pc, r0 */
/* @0x12cb8c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12cb90 mov r3, #0 */
/* @0x12cb94 mov r2, #0 */
/* @0x12cb98 movt r3, #0xbff0 */
/* @0x12cb9c b 0x12cb74 <_Z21F_BackgroundDuplicateR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x12cba0 eoreq r0, r1, r8, lsl #19 */

/* ── FUNC 0x12cba4 · F_SoundExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x12cba4 push {r4, lr} */
/* @0x12cba8 mov r1, #0 */
/* @0x12cbac mov r4, r0 */
/* @0x12cbb0 ldr r0, [sp, #0x8] */
/* @0x12cbb4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12cbb8 ldr r3, [pc, #0x38] */
/* @0x12cbbc ldr r3, [pc, r3] */
/* @0x12cbc0 ldrb r3, [r3] */
/* @0x12cbc4 cmp r3, #0 */
/* @0x12cbc8 beq 0x12cbf0 <_Z13F_SoundExistsR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x12cbcc bl 0x217260 <_Z12Audio_Existsi> */
/* @0x12cbd0 cmp r0, #0 */
/* @0x12cbd4 mov r3, #0 */
/* @0x12cbd8 str r3, [r4, #0xc] */
/* @0x12cbdc movne r0, r3 */
/* @0x12cbe0 moveq r3, r0 */
/* @0x12cbe4 movtne r3, #0x3ff0 */
/* @0x12cbe8 stm r4, {r0, r3} */
/* @0x12cbec pop {r4, pc} */
/* @0x12cbf0 bl 0x21fbd0 <_Z12Sound_Existsi> */
/* @0x12cbf4 b 0x12cbd0 <_Z13F_SoundExistsR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x12cbf8 eoreq r2, r12, r4, ror r1 */

/* ── FUNC 0x12cbfc · F_SoundGetName(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x12cbfc push {r4, lr} */
/* @0x12cc00 mov r1, #0 */
/* @0x12cc04 mov r4, r0 */
/* @0x12cc08 ldr r0, [sp, #0x8] */
/* @0x12cc0c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12cc10 ldr r3, [pc, #0x34] */
/* @0x12cc14 ldr r3, [pc, r3] */
/* @0x12cc18 ldrb r3, [r3] */
/* @0x12cc1c cmp r3, #0 */
/* @0x12cc20 bne 0x12cc38 <_Z14F_SoundGetNameR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x12cc24 bl 0x21fc18 <_Z10Sound_Namei> */
/* @0x12cc28 mov r1, r0 */
/* @0x12cc2c mov r0, r4 */
/* @0x12cc30 pop {r4, lr} */
/* @0x12cc34 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x12cc38 bl 0x218348 <_Z13Audio_GetNamei> */
/* @0x12cc3c mov r1, r0 */
/* @0x12cc40 mov r0, r4 */
/* @0x12cc44 pop {r4, lr} */
/* @0x12cc48 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x12cc4c eoreq r2, r12, r12, lsl r1 */

/* ── FUNC 0x12cc50 · F_SoundGetPreload(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x12cc50 push {r4, lr} */
/* @0x12cc54 mov r1, #0 */
/* @0x12cc58 mov r4, r0 */
/* @0x12cc5c ldr r0, [sp, #0x8] */
/* @0x12cc60 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12cc64 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x12cc68 cmp r0, #0 */
/* @0x12cc6c beq 0x12cca0 <_Z17F_SoundGetPreloadR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x12cc70 ldrb r2, [r0, #0x14] */
/* @0x12cc74 mov r3, #0 */
/* @0x12cc78 str r3, [r4, #0xc] */
/* @0x12cc7c cmp r2, r3 */
/* @0x12cc80 movne r2, #0 */
/* @0x12cc84 movtne r2, #0x3ff0 */
/* @0x12cc88 bne 0x12cc94 <_Z17F_SoundGetPreloadR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x12cc8c mov r3, #0 */
/* @0x12cc90 mov r2, r3 */
/* @0x12cc94 str r3, [r4] */
/* @0x12cc98 str r2, [r4, #0x4] */
/* @0x12cc9c pop {r4, pc} */
/* @0x12cca0 str r0, [r4, #0xc] */
/* @0x12cca4 b 0x12cc8c <_Z17F_SoundGetPreloadR6RValueP9CInstanceS2_iPS_+0x3c> */

/* ── FUNC 0x12cca8 · F_SoundGetKind(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x12cca8 push {r4, lr} */
/* @0x12ccac mov r1, #0 */
/* @0x12ccb0 mov r4, r0 */
/* @0x12ccb4 ldr r0, [sp, #0x8] */
/* @0x12ccb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ccbc bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x12ccc0 mov r1, #0 */
/* @0x12ccc4 cmp r0, #0 */
/* @0x12ccc8 ldrne r2, [r0, #0x4] */
/* @0x12cccc moveq r3, #0 */
/* @0x12ccd0 moveq r2, #0 */
/* @0x12ccd4 movteq r3, #0xbff0 */
/* @0x12ccd8 str r1, [r4, #0xc] */
/* @0x12ccdc vmovne s15, r2 */
/* @0x12cce0 vcvtne.f64.s32 d7, s15 */
/* @0x12cce4 vmovne r2, r3, d7 */
/* @0x12cce8 stm r4, {r2, r3} */
/* @0x12ccec pop {r4, pc} */

/* ── FUNC 0x12ccf0 · F_FontExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x12ccf0 push {r3, r4, r5, lr} */
/* @0x12ccf4 mov r4, #0 */
/* @0x12ccf8 mov r5, r0 */
/* @0x12ccfc mov r1, r4 */
/* @0x12cd00 str r4, [r0, #0xc] */
/* @0x12cd04 str r4, [r0] */
/* @0x12cd08 str r4, [r0, #0x4] */
/* @0x12cd0c ldr r0, [sp, #0x10] */
/* @0x12cd10 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12cd14 bl 0xfa2a8 <_Z11Font_Existsi> */
/* @0x12cd18 cmp r0, r4 */
/* @0x12cd1c strne r4, [r5] */
/* @0x12cd20 movne r3, r4 */
/* @0x12cd24 movtne r3, #0x3ff0 */
/* @0x12cd28 strne r3, [r5, #0x4] */
/* @0x12cd2c pop {r3, r4, r5, pc} */

/* ── FUNC 0x12cd30 · F_FontGetName(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x12cd30 push {r4, lr} */
/* @0x12cd34 mov r1, #0 */
/* @0x12cd38 mov r4, r0 */
/* @0x12cd3c ldr r0, [sp, #0x8] */
/* @0x12cd40 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12cd44 bl 0xfa2f0 <_Z9Font_Namei> */
/* @0x12cd48 mov r1, r0 */
/* @0x12cd4c mov r0, r4 */
/* @0x12cd50 pop {r4, lr} */
/* @0x12cd54 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x12cd58 · F_FontGetFontName(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x12cd58 push {r4, lr} */
/* @0x12cd5c mov r1, #0 */
/* @0x12cd60 mov r4, r0 */
/* @0x12cd64 ldr r0, [sp, #0x8] */
/* @0x12cd68 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12cd6c bl 0xfa3fc <_Z9Font_Datai> */
/* @0x12cd70 subs r1, r0, #0 */
/* @0x12cd74 beq 0x12cd80 <_Z17F_FontGetFontNameR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x12cd78 bl 0xf93c8 <_ZN7CFontGM7GetNameEv> */
/* @0x12cd7c mov r1, r0 */
/* @0x12cd80 mov r0, r4 */
/* @0x12cd84 pop {r4, lr} */
/* @0x12cd88 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x12cd8c · F_FontGetSize(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x12cd8c push {r4, lr} */
/* @0x12cd90 mov r1, #0 */
/* @0x12cd94 mov r4, r0 */
/* @0x12cd98 ldr r0, [sp, #0x8] */
/* @0x12cd9c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12cda0 bl 0xfa3fc <_Z9Font_Datai> */
/* @0x12cda4 cmp r0, #0 */
/* @0x12cda8 beq 0x12cdcc <_Z13F_FontGetSizeR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12cdac bl 0xf93d0 <_ZN7CFontGM7GetSizeEv> */
/* @0x12cdb0 vmov s15, r0 */
/* @0x12cdb4 vcvt.f64.s32 d7, s15 */
/* @0x12cdb8 vmov r2, r3, d7 */
/* @0x12cdbc mov r1, #0 */
/* @0x12cdc0 stm r4, {r2, r3} */
/* @0x12cdc4 str r1, [r4, #0xc] */
/* @0x12cdc8 pop {r4, pc} */
/* @0x12cdcc mov r2, #0 */
/* @0x12cdd0 mov r3, #0 */
/* @0x12cdd4 b 0x12cdbc <_Z13F_FontGetSizeR6RValueP9CInstanceS2_iPS_+0x30> */

/* ── FUNC 0x12cdd8 · F_FontGetBold(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x12cdd8 push {r4, lr} */
/* @0x12cddc mov r1, #0 */
/* @0x12cde0 mov r4, r0 */
/* @0x12cde4 ldr r0, [sp, #0x8] */
/* @0x12cde8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12cdec bl 0xfa3fc <_Z9Font_Datai> */
/* @0x12cdf0 subs r3, r0, #0 */
/* @0x12cdf4 beq 0x12ce20 <_Z13F_FontGetBoldR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12cdf8 bl 0xf93d8 <_ZN7CFontGM7GetBoldEv> */
/* @0x12cdfc mov r3, #0 */
/* @0x12ce00 str r3, [r4, #0xc] */
/* @0x12ce04 cmp r0, r3 */
/* @0x12ce08 movne r2, #0 */
/* @0x12ce0c movtne r2, #0x3ff0 */
/* @0x12ce10 beq 0x12ce24 <_Z13F_FontGetBoldR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x12ce14 str r3, [r4] */
/* @0x12ce18 str r2, [r4, #0x4] */
/* @0x12ce1c pop {r4, pc} */
/* @0x12ce20 str r3, [r4, #0xc] */
/* @0x12ce24 mov r3, #0 */
/* @0x12ce28 mov r2, r3 */
/* @0x12ce2c b 0x12ce14 <_Z13F_FontGetBoldR6RValueP9CInstanceS2_iPS_+0x3c> */

/* ── FUNC 0x12ce30 · F_FontGetItalic(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x12ce30 push {r4, lr} */
/* @0x12ce34 mov r1, #0 */
/* @0x12ce38 mov r4, r0 */
/* @0x12ce3c ldr r0, [sp, #0x8] */
/* @0x12ce40 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ce44 bl 0xfa3fc <_Z9Font_Datai> */
/* @0x12ce48 subs r3, r0, #0 */
/* @0x12ce4c beq 0x12ce78 <_Z15F_FontGetItalicR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12ce50 bl 0xf93e0 <_ZN7CFontGM9GetItalicEv> */
/* @0x12ce54 mov r3, #0 */
/* @0x12ce58 str r3, [r4, #0xc] */
/* @0x12ce5c cmp r0, r3 */
/* @0x12ce60 movne r2, #0 */
/* @0x12ce64 movtne r2, #0x3ff0 */
/* @0x12ce68 beq 0x12ce7c <_Z15F_FontGetItalicR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x12ce6c str r3, [r4] */
/* @0x12ce70 str r2, [r4, #0x4] */
/* @0x12ce74 pop {r4, pc} */
/* @0x12ce78 str r3, [r4, #0xc] */
/* @0x12ce7c mov r3, #0 */
/* @0x12ce80 mov r2, r3 */
/* @0x12ce84 b 0x12ce6c <_Z15F_FontGetItalicR6RValueP9CInstanceS2_iPS_+0x3c> */

/* ── FUNC 0x12ce88 · F_FontGetFirst(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x12ce88 push {r4, lr} */
/* @0x12ce8c mov r1, #0 */
/* @0x12ce90 mov r4, r0 */
/* @0x12ce94 ldr r0, [sp, #0x8] */
/* @0x12ce98 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ce9c bl 0xfa3fc <_Z9Font_Datai> */
/* @0x12cea0 cmp r0, #0 */
/* @0x12cea4 beq 0x12cec8 <_Z14F_FontGetFirstR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12cea8 bl 0xf93e8 <_ZN7CFontGM8GetFirstEv> */
/* @0x12ceac vmov s15, r0 */
/* @0x12ceb0 vcvt.f64.s32 d7, s15 */
/* @0x12ceb4 vmov r2, r3, d7 */
/* @0x12ceb8 mov r1, #0 */
/* @0x12cebc stm r4, {r2, r3} */
/* @0x12cec0 str r1, [r4, #0xc] */
/* @0x12cec4 pop {r4, pc} */
/* @0x12cec8 mov r3, #0 */
/* @0x12cecc mov r2, #0 */
/* @0x12ced0 movt r3, #0xbff0 */
/* @0x12ced4 b 0x12ceb8 <_Z14F_FontGetFirstR6RValueP9CInstanceS2_iPS_+0x30> */

/* ── FUNC 0x12ced8 · F_FontGetLast(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x12ced8 push {r4, lr} */
/* @0x12cedc mov r1, #0 */
/* @0x12cee0 mov r4, r0 */
/* @0x12cee4 ldr r0, [sp, #0x8] */
/* @0x12cee8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ceec bl 0xfa3fc <_Z9Font_Datai> */
/* @0x12cef0 cmp r0, #0 */
/* @0x12cef4 beq 0x12cf18 <_Z13F_FontGetLastR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12cef8 bl 0xf93f0 <_ZN7CFontGM7GetLastEv> */
/* @0x12cefc vmov s15, r0 */
/* @0x12cf00 vcvt.f64.s32 d7, s15 */
/* @0x12cf04 vmov r2, r3, d7 */
/* @0x12cf08 mov r1, #0 */
/* @0x12cf0c stm r4, {r2, r3} */
/* @0x12cf10 str r1, [r4, #0xc] */
/* @0x12cf14 pop {r4, pc} */
/* @0x12cf18 mov r3, #0 */
/* @0x12cf1c mov r2, #0 */
/* @0x12cf20 movt r3, #0xbff0 */
/* @0x12cf24 b 0x12cf08 <_Z13F_FontGetLastR6RValueP9CInstanceS2_iPS_+0x30> */
