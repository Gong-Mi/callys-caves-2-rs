/* libyoyo.so 覆盖卡组 0053
 * 函数 0x121f10..0x125da8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x121f10 · F_DrawTextExtTransformed(RValue&, CInstance*, CInstance*, int, RValue*) · size=200 · insn=50 */
/* @0x121f10 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x121f14 sub sp, sp, #28 */
/* @0x121f18 add r2, sp, #24 */
/* @0x121f1c mov r5, #0 */
/* @0x121f20 ldr r4, [sp, #0x40] */
/* @0x121f24 mov r1, #1024 */
/* @0x121f28 str r5, [r2, #-0x4]! */
/* @0x121f2c add r0, r4, #32 */
/* @0x121f30 bl 0x121ce0 <_Z14GetTextFromArgPK6RValueiPPc> */
/* @0x121f34 mov r1, r5 */
/* @0x121f38 mov r0, r4 */
/* @0x121f3c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x121f40 mov r1, #1 */
/* @0x121f44 mov r5, r0 */
/* @0x121f48 mov r0, r4 */
/* @0x121f4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x121f50 mov r1, #3 */
/* @0x121f54 ldr r7, [sp, #0x14] */
/* @0x121f58 mov r8, r0 */
/* @0x121f5c mov r0, r4 */
/* @0x121f60 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x121f64 mov r1, #4 */
/* @0x121f68 mov r6, r0 */
/* @0x121f6c mov r0, r4 */
/* @0x121f70 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x121f74 mov r1, #5 */
/* @0x121f78 mov r11, r0 */
/* @0x121f7c mov r0, r4 */
/* @0x121f80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x121f84 mov r1, #6 */
/* @0x121f88 mov r10, r0 */
/* @0x121f8c mov r0, r4 */
/* @0x121f90 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x121f94 mov r1, #7 */
/* @0x121f98 mov r9, r0 */
/* @0x121f9c mov r0, r4 */
/* @0x121fa0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x121fa4 mov r1, r8 */
/* @0x121fa8 mov r2, r7 */
/* @0x121fac mov r3, r6 */
/* @0x121fb0 str r11, [sp] */
/* @0x121fb4 str r10, [sp, #0x4] */
/* @0x121fb8 str r9, [sp, #0x8] */
/* @0x121fbc str r0, [sp, #0xc] */
/* @0x121fc0 mov r0, r5 */
/* @0x121fc4 bl 0x173068 <_Z24GR_Text_Draw_TransformedffPKciifff> */
/* @0x121fc8 ldr r0, [sp, #0x14] */
/* @0x121fcc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x121fd0 add sp, sp, #28 */
/* @0x121fd4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x121fd8 · F_DrawTextColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0x121fd8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x121fdc sub sp, sp, #36 */
/* @0x121fe0 add r2, sp, #32 */
/* @0x121fe4 mov r5, #0 */
/* @0x121fe8 ldr r4, [sp, #0x48] */
/* @0x121fec mov r1, #1024 */
/* @0x121ff0 str r5, [r2, #-0x4]! */
/* @0x121ff4 add r0, r4, #32 */
/* @0x121ff8 bl 0x121ce0 <_Z14GetTextFromArgPK6RValueiPPc> */
/* @0x121ffc mov r1, r5 */
/* @0x122000 mov r0, r4 */
/* @0x122004 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122008 mov r1, #1 */
/* @0x12200c mov r5, r0 */
/* @0x122010 mov r0, r4 */
/* @0x122014 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122018 mov r1, #3 */
/* @0x12201c ldr r10, [sp, #0x1c] */
/* @0x122020 mov r6, r0 */
/* @0x122024 mov r0, r4 */
/* @0x122028 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12202c mov r1, #4 */
/* @0x122030 mov r11, r0 */
/* @0x122034 mov r0, r4 */
/* @0x122038 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12203c mov r1, #5 */
/* @0x122040 mov r9, r0 */
/* @0x122044 mov r0, r4 */
/* @0x122048 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12204c mov r1, #6 */
/* @0x122050 mov r8, r0 */
/* @0x122054 mov r0, r4 */
/* @0x122058 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12205c mov r1, #7 */
/* @0x122060 mov r7, r0 */
/* @0x122064 mov r0, r4 */
/* @0x122068 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12206c mvn r12, #0 */
/* @0x122070 mov r2, r10 */
/* @0x122074 mov r3, r12 */
/* @0x122078 mov r1, r6 */
/* @0x12207c str r12, [sp] */
/* @0x122080 str r11, [sp, #0x4] */
/* @0x122084 str r9, [sp, #0x8] */
/* @0x122088 str r8, [sp, #0xc] */
/* @0x12208c str r7, [sp, #0x10] */
/* @0x122090 str r0, [sp, #0x14] */
/* @0x122094 mov r0, r5 */
/* @0x122098 bl 0x173338 <_Z18GR_Text_Draw_ColorffPKciijjjjf> */
/* @0x12209c ldr r0, [sp, #0x1c] */
/* @0x1220a0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1220a4 add sp, sp, #36 */
/* @0x1220a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x1220ac · F_DrawTextTransformedColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=292 · insn=73 */
/* @0x1220ac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1220b0 sub sp, sp, #68 */
/* @0x1220b4 add r2, sp, #64 */
/* @0x1220b8 mov r5, #0 */
/* @0x1220bc ldr r4, [sp, #0x68] */
/* @0x1220c0 mov r1, #1024 */
/* @0x1220c4 str r5, [r2, #-0x4]! */
/* @0x1220c8 add r0, r4, #32 */
/* @0x1220cc bl 0x121ce0 <_Z14GetTextFromArgPK6RValueiPPc> */
/* @0x1220d0 mov r1, r5 */
/* @0x1220d4 mov r0, r4 */
/* @0x1220d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1220dc mov r1, #1 */
/* @0x1220e0 mov r5, r0 */
/* @0x1220e4 mov r0, r4 */
/* @0x1220e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1220ec mov r1, #3 */
/* @0x1220f0 ldr r9, [sp, #0x3c] */
/* @0x1220f4 mov r6, r0 */
/* @0x1220f8 mov r0, r4 */
/* @0x1220fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122100 mov r1, #4 */
/* @0x122104 str r0, [sp, #0x34] */
/* @0x122108 mov r0, r4 */
/* @0x12210c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122110 mov r1, #5 */
/* @0x122114 mov r12, r0 */
/* @0x122118 mov r0, r4 */
/* @0x12211c str r12, [sp, #0x2c] */
/* @0x122120 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122124 mov r1, #6 */
/* @0x122128 mov r2, r0 */
/* @0x12212c mov r0, r4 */
/* @0x122130 str r2, [sp, #0x30] */
/* @0x122134 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x122138 mov r1, #7 */
/* @0x12213c mov r11, r0 */
/* @0x122140 mov r0, r4 */
/* @0x122144 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x122148 mov r1, #8 */
/* @0x12214c mov r10, r0 */
/* @0x122150 mov r0, r4 */
/* @0x122154 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x122158 mov r1, #9 */
/* @0x12215c mov r8, r0 */
/* @0x122160 mov r0, r4 */
/* @0x122164 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x122168 mov r1, #10 */
/* @0x12216c mov r7, r0 */
/* @0x122170 mov r0, r4 */
/* @0x122174 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122178 ldr r3, [sp, #0x34] */
/* @0x12217c ldr r12, [sp, #0x2c] */
/* @0x122180 mvn lr, #0 */
/* @0x122184 ldr r2, [sp, #0x30] */
/* @0x122188 mov r1, r6 */
/* @0x12218c str r3, [sp, #0x4] */
/* @0x122190 mov r3, lr */
/* @0x122194 str r12, [sp, #0x8] */
/* @0x122198 str r2, [sp, #0xc] */
/* @0x12219c mov r2, r9 */
/* @0x1221a0 str lr, [sp] */
/* @0x1221a4 str r11, [sp, #0x10] */
/* @0x1221a8 str r10, [sp, #0x14] */
/* @0x1221ac str r8, [sp, #0x18] */
/* @0x1221b0 str r7, [sp, #0x1c] */
/* @0x1221b4 str r0, [sp, #0x20] */
/* @0x1221b8 mov r0, r5 */
/* @0x1221bc bl 0x1735a0 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf> */
/* @0x1221c0 ldr r0, [sp, #0x3c] */
/* @0x1221c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1221c8 add sp, sp, #68 */
/* @0x1221cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x1221d0 · F_DrawTextExtColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=256 · insn=64 */
/* @0x1221d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1221d4 sub sp, sp, #44 */
/* @0x1221d8 add r2, sp, #40 */
/* @0x1221dc mov r5, #0 */
/* @0x1221e0 ldr r4, [sp, #0x50] */
/* @0x1221e4 mov r1, #1024 */
/* @0x1221e8 str r5, [r2, #-0x4]! */
/* @0x1221ec add r0, r4, #32 */
/* @0x1221f0 bl 0x121ce0 <_Z14GetTextFromArgPK6RValueiPPc> */
/* @0x1221f4 mov r1, r5 */
/* @0x1221f8 mov r0, r4 */
/* @0x1221fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122200 mov r1, #1 */
/* @0x122204 mov r5, r0 */
/* @0x122208 mov r0, r4 */
/* @0x12220c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122210 mov r1, #3 */
/* @0x122214 ldr r11, [sp, #0x24] */
/* @0x122218 mov r6, r0 */
/* @0x12221c mov r0, r4 */
/* @0x122220 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x122224 mov r1, #4 */
/* @0x122228 mov r9, r0 */
/* @0x12222c mov r0, r4 */
/* @0x122230 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x122234 mov r1, #5 */
/* @0x122238 mov r2, r0 */
/* @0x12223c mov r0, r4 */
/* @0x122240 str r2, [sp, #0x18] */
/* @0x122244 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x122248 mov r1, #6 */
/* @0x12224c mov r3, r0 */
/* @0x122250 mov r0, r4 */
/* @0x122254 str r3, [sp, #0x1c] */
/* @0x122258 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12225c mov r1, #7 */
/* @0x122260 mov r10, r0 */
/* @0x122264 mov r0, r4 */
/* @0x122268 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12226c mov r1, #8 */
/* @0x122270 mov r8, r0 */
/* @0x122274 mov r0, r4 */
/* @0x122278 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12227c mov r1, #9 */
/* @0x122280 mov r7, r0 */
/* @0x122284 mov r0, r4 */
/* @0x122288 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12228c ldr r2, [sp, #0x18] */
/* @0x122290 ldr r3, [sp, #0x1c] */
/* @0x122294 mov r1, r6 */
/* @0x122298 str r10, [sp, #0x8] */
/* @0x12229c str r2, [sp] */
/* @0x1222a0 mov r2, r11 */
/* @0x1222a4 str r3, [sp, #0x4] */
/* @0x1222a8 mov r3, r9 */
/* @0x1222ac str r8, [sp, #0xc] */
/* @0x1222b0 str r7, [sp, #0x10] */
/* @0x1222b4 str r0, [sp, #0x14] */
/* @0x1222b8 mov r0, r5 */
/* @0x1222bc bl 0x173338 <_Z18GR_Text_Draw_ColorffPKciijjjjf> */
/* @0x1222c0 ldr r0, [sp, #0x24] */
/* @0x1222c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1222c8 add sp, sp, #44 */
/* @0x1222cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x1222d0 · F_DrawTextExtTransformedColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=324 · insn=81 */
/* @0x1222d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1222d4 sub sp, sp, #76 */
/* @0x1222d8 add r2, sp, #72 */
/* @0x1222dc mov r5, #0 */
/* @0x1222e0 ldr r4, [sp, #0x70] */
/* @0x1222e4 mov r1, #1024 */
/* @0x1222e8 str r5, [r2, #-0x4]! */
/* @0x1222ec add r0, r4, #32 */
/* @0x1222f0 bl 0x121ce0 <_Z14GetTextFromArgPK6RValueiPPc> */
/* @0x1222f4 mov r1, r5 */
/* @0x1222f8 mov r0, r4 */
/* @0x1222fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122300 mov r1, #1 */
/* @0x122304 mov r5, r0 */
/* @0x122308 mov r0, r4 */
/* @0x12230c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122310 ldr r2, [sp, #0x44] */
/* @0x122314 mov r1, #3 */
/* @0x122318 str r2, [sp, #0x2c] */
/* @0x12231c str r0, [sp, #0x38] */
/* @0x122320 mov r0, r4 */
/* @0x122324 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x122328 mov r1, #4 */
/* @0x12232c mov r7, r0 */
/* @0x122330 mov r0, r4 */
/* @0x122334 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x122338 mov r1, #5 */
/* @0x12233c mov r12, r0 */
/* @0x122340 mov r0, r4 */
/* @0x122344 str r12, [sp, #0x30] */
/* @0x122348 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12234c mov r1, #6 */
/* @0x122350 str r0, [sp, #0x3c] */
/* @0x122354 mov r0, r4 */
/* @0x122358 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12235c mov r1, #7 */
/* @0x122360 mov r3, r0 */
/* @0x122364 mov r0, r4 */
/* @0x122368 str r3, [sp, #0x34] */
/* @0x12236c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122370 mov r1, #8 */
/* @0x122374 mov r11, r0 */
/* @0x122378 mov r0, r4 */
/* @0x12237c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x122380 mov r1, #9 */
/* @0x122384 mov r10, r0 */
/* @0x122388 mov r0, r4 */
/* @0x12238c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x122390 mov r1, #10 */
/* @0x122394 mov r9, r0 */
/* @0x122398 mov r0, r4 */
/* @0x12239c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1223a0 mov r1, #11 */
/* @0x1223a4 mov r8, r0 */
/* @0x1223a8 mov r0, r4 */
/* @0x1223ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1223b0 mov r1, #12 */
/* @0x1223b4 mov r6, r0 */
/* @0x1223b8 mov r0, r4 */
/* @0x1223bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1223c0 ldr r12, [sp, #0x30] */
/* @0x1223c4 ldr r1, [sp, #0x3c] */
/* @0x1223c8 ldr r3, [sp, #0x34] */
/* @0x1223cc str r12, [sp] */
/* @0x1223d0 str r1, [sp, #0x4] */
/* @0x1223d4 str r3, [sp, #0x8] */
/* @0x1223d8 mov r3, r7 */
/* @0x1223dc ldr r2, [sp, #0x2c] */
/* @0x1223e0 ldr r1, [sp, #0x38] */
/* @0x1223e4 str r11, [sp, #0xc] */
/* @0x1223e8 str r10, [sp, #0x10] */
/* @0x1223ec str r9, [sp, #0x14] */
/* @0x1223f0 str r8, [sp, #0x18] */
/* @0x1223f4 str r6, [sp, #0x1c] */
/* @0x1223f8 str r0, [sp, #0x20] */
/* @0x1223fc mov r0, r5 */
/* @0x122400 bl 0x1735a0 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf> */
/* @0x122404 ldr r0, [sp, #0x44] */
/* @0x122408 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x12240c add sp, sp, #76 */
/* @0x122410 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x122414 · YYGML_draw_text(float, float, char const*) · size=68 · insn=17 */
/* @0x122414 push {r4, r5, r6, lr} */
/* @0x122418 mov r5, r0 */
/* @0x12241c sub sp, sp, #8 */
/* @0x122420 mov r0, r2 */
/* @0x122424 mov r6, r1 */
/* @0x122428 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x12242c mvn r3, #0 */
/* @0x122430 mov r1, r6 */
/* @0x122434 str r3, [sp] */
/* @0x122438 mov r4, r0 */
/* @0x12243c mov r0, r5 */
/* @0x122440 mov r2, r4 */
/* @0x122444 bl 0x172df8 <_Z12GR_Text_DrawffPKcii> */
/* @0x122448 mov r0, r4 */
/* @0x12244c add sp, sp, #8 */
/* @0x122450 pop {r4, r5, r6, lr} */
/* @0x122454 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */

/* ── FUNC 0x122458 · YYGML_draw_text_transformed(float, float, char const*, float, float, float) · size=96 · insn=24 */
/* @0x122458 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x12245c sub sp, sp, #20 */
/* @0x122460 mov r5, r0 */
/* @0x122464 mov r0, r2 */
/* @0x122468 mov r7, r3 */
/* @0x12246c mov r6, r1 */
/* @0x122470 ldr r8, [sp, #0x30] */
/* @0x122474 ldr r9, [sp, #0x34] */
/* @0x122478 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x12247c mvn r12, #0 */
/* @0x122480 str r7, [sp, #0x4] */
/* @0x122484 str r8, [sp, #0x8] */
/* @0x122488 mov r1, r6 */
/* @0x12248c str r9, [sp, #0xc] */
/* @0x122490 mov r3, r12 */
/* @0x122494 str r12, [sp] */
/* @0x122498 mov r4, r0 */
/* @0x12249c mov r2, r0 */
/* @0x1224a0 mov r0, r5 */
/* @0x1224a4 bl 0x173068 <_Z24GR_Text_Draw_TransformedffPKciifff> */
/* @0x1224a8 mov r0, r4 */
/* @0x1224ac add sp, sp, #20 */
/* @0x1224b0 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1224b4 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */

/* ── FUNC 0x1224b8 · YYGML_draw_text_color(float, float, char const*, int, int, int, int, float) · size=112 · insn=28 */
/* @0x1224b8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1224bc sub sp, sp, #28 */
/* @0x1224c0 mov r5, r0 */
/* @0x1224c4 mov r0, r2 */
/* @0x1224c8 mov r10, r3 */
/* @0x1224cc ldr r7, [sp, #0x40] */
/* @0x1224d0 ldr r6, [sp, #0x44] */
/* @0x1224d4 mov r8, r1 */
/* @0x1224d8 ldr r9, [sp, #0x48] */
/* @0x1224dc ldr r11, [sp, #0x4c] */
/* @0x1224e0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1224e4 mvn r12, #0 */
/* @0x1224e8 str r10, [sp, #0x4] */
/* @0x1224ec str r7, [sp, #0x8] */
/* @0x1224f0 mov r3, r12 */
/* @0x1224f4 str r11, [sp, #0x14] */
/* @0x1224f8 mov r1, r8 */
/* @0x1224fc str r6, [sp, #0xc] */
/* @0x122500 str r9, [sp, #0x10] */
/* @0x122504 str r12, [sp] */
/* @0x122508 mov r4, r0 */
/* @0x12250c mov r2, r0 */
/* @0x122510 mov r0, r5 */
/* @0x122514 bl 0x173338 <_Z18GR_Text_Draw_ColorffPKciijjjjf> */
/* @0x122518 mov r0, r4 */
/* @0x12251c add sp, sp, #28 */
/* @0x122520 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x122524 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */

/* ── FUNC 0x122528 · YYGML_draw_text_transformed_color(float, float, char const*, float, float, float, int, int, int, int, float) · size=140 · insn=35 */
/* @0x122528 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x12252c vpush {d8} */
/* @0x122530 sub sp, sp, #44 */
/* @0x122534 vldr s17, [sp, #88] */
/* @0x122538 mov r8, r0 */
/* @0x12253c mov r0, r2 */
/* @0x122540 ldr r5, [sp, #0x68] */
/* @0x122544 mov r10, r3 */
/* @0x122548 ldr r7, [sp, #0x60] */
/* @0x12254c mov r9, r1 */
/* @0x122550 ldr r6, [sp, #0x64] */
/* @0x122554 vldr s16, [sp, #92] */
/* @0x122558 ldr r11, [sp, #0x70] */
/* @0x12255c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x122560 mvn r12, #0 */
/* @0x122564 str r10, [sp, #0x4] */
/* @0x122568 vstr s17, [sp, #8] */
/* @0x12256c vstr s16, [sp, #12] */
/* @0x122570 str r7, [sp, #0x10] */
/* @0x122574 mov r3, r12 */
/* @0x122578 str r11, [sp, #0x20] */
/* @0x12257c mov r1, r9 */
/* @0x122580 str r6, [sp, #0x14] */
/* @0x122584 str r5, [sp, #0x18] */
/* @0x122588 str r5, [sp, #0x1c] */
/* @0x12258c str r12, [sp] */
/* @0x122590 mov r4, r0 */
/* @0x122594 mov r0, r8 */
/* @0x122598 mov r2, r4 */
/* @0x12259c bl 0x1735a0 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf> */
/* @0x1225a0 mov r0, r4 */
/* @0x1225a4 add sp, sp, #44 */
/* @0x1225a8 vpop {d8} */
/* @0x1225ac pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1225b0 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */

/* ── FUNC 0x1225b4 · YYGML_draw_text_ext_color(float, float, char const*, int, int, int, int, int, int, float) · size=124 · insn=31 */
/* @0x1225b4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1225b8 vpush {d8} */
/* @0x1225bc sub sp, sp, #36 */
/* @0x1225c0 vldr s16, [sp, #100] */
/* @0x1225c4 mov r7, r0 */
/* @0x1225c8 mov r0, r2 */
/* @0x1225cc ldr r6, [sp, #0x50] */
/* @0x1225d0 mov r8, r1 */
/* @0x1225d4 ldr r5, [sp, #0x54] */
/* @0x1225d8 ldr r11, [sp, #0x58] */
/* @0x1225dc ldr r10, [sp, #0x5c] */
/* @0x1225e0 ldr r9, [sp, #0x60] */
/* @0x1225e4 str r3, [sp, #0x1c] */
/* @0x1225e8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1225ec str r6, [sp] */
/* @0x1225f0 vstr s16, [sp, #20] */
/* @0x1225f4 str r5, [sp, #0x4] */
/* @0x1225f8 mov r1, r8 */
/* @0x1225fc ldr r3, [sp, #0x1c] */
/* @0x122600 str r11, [sp, #0x8] */
/* @0x122604 str r10, [sp, #0xc] */
/* @0x122608 str r9, [sp, #0x10] */
/* @0x12260c mov r4, r0 */
/* @0x122610 mov r0, r7 */
/* @0x122614 mov r2, r4 */
/* @0x122618 bl 0x173338 <_Z18GR_Text_Draw_ColorffPKciijjjjf> */
/* @0x12261c mov r0, r4 */
/* @0x122620 add sp, sp, #36 */
/* @0x122624 vpop {d8} */
/* @0x122628 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x12262c b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */

/* ── FUNC 0x122630 · YYGML_draw_text_ext_transformed_color(float, float, char const*, int, int, float, float, float, int, int, int, int, float) · size=148 · insn=37 */
/* @0x122630 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x122634 vpush {d8, d9} */
/* @0x122638 sub sp, sp, #52 */
/* @0x12263c vldr s19, [sp, #108] */
/* @0x122640 mov r7, r0 */
/* @0x122644 mov r0, r2 */
/* @0x122648 ldr r6, [sp, #0x68] */
/* @0x12264c mov r8, r1 */
/* @0x122650 ldr r5, [sp, #0x78] */
/* @0x122654 vldr s18, [sp, #112] */
/* @0x122658 ldr r10, [sp, #0x7c] */
/* @0x12265c vldr s17, [sp, #116] */
/* @0x122660 ldr r11, [sp, #0x80] */
/* @0x122664 vldr s16, [sp, #136] */
/* @0x122668 ldr r9, [sp, #0x84] */
/* @0x12266c str r3, [sp, #0x2c] */
/* @0x122670 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x122674 str r6, [sp] */
/* @0x122678 vstr s19, [sp, #4] */
/* @0x12267c vstr s18, [sp, #8] */
/* @0x122680 vstr s17, [sp, #12] */
/* @0x122684 str r5, [sp, #0x10] */
/* @0x122688 vstr s16, [sp, #32] */
/* @0x12268c str r10, [sp, #0x14] */
/* @0x122690 mov r1, r8 */
/* @0x122694 ldr r3, [sp, #0x2c] */
/* @0x122698 str r11, [sp, #0x18] */
/* @0x12269c str r9, [sp, #0x1c] */
/* @0x1226a0 mov r4, r0 */
/* @0x1226a4 mov r0, r7 */
/* @0x1226a8 mov r2, r4 */
/* @0x1226ac bl 0x1735a0 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf> */
/* @0x1226b0 mov r0, r4 */
/* @0x1226b4 add sp, sp, #52 */
/* @0x1226b8 vpop {d8, d9} */
/* @0x1226bc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1226c0 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */

/* ── FUNC 0x1226c4 · GetSpriteIndices(CInstance*, RValue*, int&, int&) · size=132 · insn=33 */
/* @0x1226c4 push {r3, r4, r5, r6, r7, lr} */
/* @0x1226c8 mov r4, r1 */
/* @0x1226cc mov r7, r0 */
/* @0x1226d0 mov r1, #1 */
/* @0x1226d4 mov r0, r4 */
/* @0x1226d8 mov r5, r3 */
/* @0x1226dc mov r6, r2 */
/* @0x1226e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1226e4 cmp r0, #0 */
/* @0x1226e8 str r0, [r5] */
/* @0x1226ec blt 0x122724 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_+0x60> */
/* @0x1226f0 mov r0, r4 */
/* @0x1226f4 mov r1, #0 */
/* @0x1226f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1226fc str r0, [r6] */
/* @0x122700 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x122704 subs r4, r0, #0 */
/* @0x122708 bne 0x12271c <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_+0x58> */
/* @0x12270c ldr r0, [pc, #0x30] */
/* @0x122710 mov r1, r4 */
/* @0x122714 add r0, pc, r0 */
/* @0x122718 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12271c mov r0, r4 */
/* @0x122720 pop {r3, r4, r5, r6, r7, pc} */
/* @0x122724 vldr s15, [r7, #144] */
/* @0x122728 vcvt.f64.f32 d6, s15 */
/* @0x12272c vmov r0, r1, d6 */
/* @0x122730 bl 0xb6598 <floor@plt> */
/* @0x122734 vmov d7, r0, r1 */
/* @0x122738 vcvt.s32.f64 s15, d7 */
/* @0x12273c vstr s15, [r5] */
/* @0x122740 b 0x1226f0 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_+0x2c> */
/* @0x122744 eoreq r7, r1, r0, lsr #17 */

/* ── FUNC 0x122748 · F_DrawSprite(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x122748 push {r4, r5, r6, r7, lr} */
/* @0x12274c sub sp, sp, #12 */
/* @0x122750 mov r0, r1 */
/* @0x122754 add r3, sp, #4 */
/* @0x122758 ldr r4, [sp, #0x20] */
/* @0x12275c mov r2, sp */
/* @0x122760 mov r1, r4 */
/* @0x122764 bl 0x1226c4 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_> */
/* @0x122768 cmp r0, #0 */
/* @0x12276c bne 0x122778 <_Z12F_DrawSpriteR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x122770 add sp, sp, #12 */
/* @0x122774 pop {r4, r5, r6, r7, pc} */
/* @0x122778 ldr r0, [sp] */
/* @0x12277c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x122780 mov r1, #2 */
/* @0x122784 ldr r6, [sp, #0x4] */
/* @0x122788 mov r7, r0 */
/* @0x12278c mov r0, r4 */
/* @0x122790 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122794 mov r1, #3 */
/* @0x122798 mov r5, r0 */
/* @0x12279c mov r0, r4 */
/* @0x1227a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1227a4 mov r1, r6 */
/* @0x1227a8 mov r2, r5 */
/* @0x1227ac mov r3, r0 */
/* @0x1227b0 mov r0, r7 */
/* @0x1227b4 bl 0x1ecab4 <_ZN7CSprite10DrawSimpleEiff> */
/* @0x1227b8 add sp, sp, #12 */
/* @0x1227bc pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x1227c0 · F_DrawSpriteExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=228 · insn=57 */
/* @0x1227c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1227c4 sub sp, sp, #44 */
/* @0x1227c8 mov r0, r1 */
/* @0x1227cc add r2, sp, #32 */
/* @0x1227d0 ldr r4, [sp, #0x50] */
/* @0x1227d4 add r3, sp, #36 */
/* @0x1227d8 mov r1, r4 */
/* @0x1227dc bl 0x1226c4 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_> */
/* @0x1227e0 cmp r0, #0 */
/* @0x1227e4 bne 0x1227f0 <_Z15F_DrawSpriteExtR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x1227e8 add sp, sp, #44 */
/* @0x1227ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1227f0 ldr r0, [sp, #0x20] */
/* @0x1227f4 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1227f8 mov r1, #2 */
/* @0x1227fc ldr r8, [sp, #0x24] */
/* @0x122800 mov r5, r0 */
/* @0x122804 mov r0, r4 */
/* @0x122808 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12280c mov r1, #3 */
/* @0x122810 mov r7, r0 */
/* @0x122814 mov r0, r4 */
/* @0x122818 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12281c mov r1, #4 */
/* @0x122820 mov r6, r0 */
/* @0x122824 mov r0, r4 */
/* @0x122828 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12282c mov r1, #5 */
/* @0x122830 mov r3, r0 */
/* @0x122834 mov r0, r4 */
/* @0x122838 str r3, [sp, #0x1c] */
/* @0x12283c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122840 mov r1, #6 */
/* @0x122844 mov r11, r0 */
/* @0x122848 mov r0, r4 */
/* @0x12284c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122850 mov r1, #7 */
/* @0x122854 mov r10, r0 */
/* @0x122858 mov r0, r4 */
/* @0x12285c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x122860 mov r1, #8 */
/* @0x122864 mov r9, r0 */
/* @0x122868 mov r0, r4 */
/* @0x12286c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122870 ldr r3, [sp, #0x1c] */
/* @0x122874 str r11, [sp, #0x4] */
/* @0x122878 mov r1, r8 */
/* @0x12287c str r10, [sp, #0x8] */
/* @0x122880 mov r2, r7 */
/* @0x122884 str r3, [sp] */
/* @0x122888 mov r3, r6 */
/* @0x12288c str r9, [sp, #0xc] */
/* @0x122890 str r0, [sp, #0x10] */
/* @0x122894 mov r0, r5 */
/* @0x122898 bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */
/* @0x12289c add sp, sp, #44 */
/* @0x1228a0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x1228a4 · F_DrawSpritePart(RValue&, CInstance*, CInstance*, int, RValue*) · size=300 · insn=75 */
/* @0x1228a4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1228a8 sub sp, sp, #44 */
/* @0x1228ac mov r0, r1 */
/* @0x1228b0 add r2, sp, #32 */
/* @0x1228b4 ldr r4, [sp, #0x50] */
/* @0x1228b8 add r3, sp, #36 */
/* @0x1228bc mov r1, r4 */
/* @0x1228c0 bl 0x1226c4 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_> */
/* @0x1228c4 cmp r0, #0 */
/* @0x1228c8 bne 0x1228d4 <_Z16F_DrawSpritePartR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x1228cc add sp, sp, #44 */
/* @0x1228d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1228d4 ldr r0, [sp, #0x20] */
/* @0x1228d8 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1228dc ldr r3, [r0, #0x74] */
/* @0x1228e0 mov r5, r0 */
/* @0x1228e4 cmp r3, #1 */
/* @0x1228e8 beq 0x1229b4 <_Z16F_DrawSpritePartR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x1228ec cmp r3, #2 */
/* @0x1228f0 beq 0x1229a0 <_Z16F_DrawSpritePartR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x1228f4 mov r0, r4 */
/* @0x1228f8 mov r1, #2 */
/* @0x1228fc ldr r8, [sp, #0x24] */
/* @0x122900 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122904 mov r1, #3 */
/* @0x122908 mov r7, r0 */
/* @0x12290c mov r0, r4 */
/* @0x122910 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122914 mov r1, #4 */
/* @0x122918 mov r6, r0 */
/* @0x12291c mov r0, r4 */
/* @0x122920 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122924 mov r1, #5 */
/* @0x122928 mov r11, r0 */
/* @0x12292c mov r0, r4 */
/* @0x122930 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122934 mov r1, #6 */
/* @0x122938 mov r10, r0 */
/* @0x12293c mov r0, r4 */
/* @0x122940 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122944 mov r1, #7 */
/* @0x122948 mov r9, r0 */
/* @0x12294c mov r0, r4 */
/* @0x122950 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122954 mov r4, r0 */
/* @0x122958 bl 0x169f1c <_Z17GR_Draw_Get_Alphav> */
/* @0x12295c mov r12, #1065353216 */
/* @0x122960 mvn lr, #-16777216 */
/* @0x122964 str r11, [sp] */
/* @0x122968 mov r1, r8 */
/* @0x12296c str r10, [sp, #0x4] */
/* @0x122970 mov r2, r7 */
/* @0x122974 str r9, [sp, #0x8] */
/* @0x122978 mov r3, r6 */
/* @0x12297c str r4, [sp, #0xc] */
/* @0x122980 str lr, [sp, #0x18] */
/* @0x122984 str r12, [sp, #0x10] */
/* @0x122988 str r12, [sp, #0x14] */
/* @0x12298c str r0, [sp, #0x1c] */
/* @0x122990 mov r0, r5 */
/* @0x122994 bl 0x1e5e34 <_ZN7CSprite8DrawPartEiffffffffjf> */
/* @0x122998 add sp, sp, #44 */
/* @0x12299c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1229a0 ldr r0, [pc, #0x20] */
/* @0x1229a4 mov r1, #0 */
/* @0x1229a8 add r0, pc, r0 */
/* @0x1229ac bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1229b0 b 0x1228cc <_Z16F_DrawSpritePartR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x1229b4 ldr r0, [pc, #0x10] */
/* @0x1229b8 mov r1, #0 */
/* @0x1229bc add r0, pc, r0 */
/* @0x1229c0 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1229c4 b 0x1228cc <_Z16F_DrawSpritePartR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x1229c8 eoreq r7, r1, r0, lsl r11 */
/* @0x1229cc eoreq r7, r1, r8, asr #21 */

/* ── FUNC 0x1229d0 · F_DrawSpritePartExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=372 · insn=93 */
/* @0x1229d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1229d4 sub sp, sp, #60 */
/* @0x1229d8 mov r0, r1 */
/* @0x1229dc add r2, sp, #48 */
/* @0x1229e0 ldr r4, [sp, #0x60] */
/* @0x1229e4 add r3, sp, #52 */
/* @0x1229e8 mov r1, r4 */
/* @0x1229ec bl 0x1226c4 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_> */
/* @0x1229f0 cmp r0, #0 */
/* @0x1229f4 bne 0x122a00 <_Z19F_DrawSpritePartExtR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x1229f8 add sp, sp, #60 */
/* @0x1229fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x122a00 ldr r0, [sp, #0x30] */
/* @0x122a04 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x122a08 ldr r3, [r0, #0x74] */
/* @0x122a0c mov r5, r0 */
/* @0x122a10 cmp r3, #1 */
/* @0x122a14 beq 0x122b28 <_Z19F_DrawSpritePartExtR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x122a18 cmp r3, #2 */
/* @0x122a1c beq 0x122b14 <_Z19F_DrawSpritePartExtR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x122a20 mov r0, r4 */
/* @0x122a24 mov r1, #2 */
/* @0x122a28 ldr r7, [sp, #0x34] */
/* @0x122a2c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122a30 mov r1, #3 */
/* @0x122a34 mov r6, r0 */
/* @0x122a38 mov r0, r4 */
/* @0x122a3c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122a40 mov r1, #4 */
/* @0x122a44 mov r3, r0 */
/* @0x122a48 mov r0, r4 */
/* @0x122a4c str r3, [sp, #0x20] */
/* @0x122a50 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122a54 mov r1, #5 */
/* @0x122a58 mov r12, r0 */
/* @0x122a5c mov r0, r4 */
/* @0x122a60 str r12, [sp, #0x24] */
/* @0x122a64 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122a68 mov r1, #6 */
/* @0x122a6c mov r2, r0 */
/* @0x122a70 mov r0, r4 */
/* @0x122a74 str r2, [sp, #0x28] */
/* @0x122a78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122a7c mov r1, #7 */
/* @0x122a80 str r0, [sp, #0x2c] */
/* @0x122a84 mov r0, r4 */
/* @0x122a88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122a8c mov r1, #8 */
/* @0x122a90 mov r11, r0 */
/* @0x122a94 mov r0, r4 */
/* @0x122a98 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122a9c mov r1, #9 */
/* @0x122aa0 mov r10, r0 */
/* @0x122aa4 mov r0, r4 */
/* @0x122aa8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122aac mov r1, #10 */
/* @0x122ab0 mov r9, r0 */
/* @0x122ab4 mov r0, r4 */
/* @0x122ab8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x122abc mov r1, #11 */
/* @0x122ac0 mov r8, r0 */
/* @0x122ac4 mov r0, r4 */
/* @0x122ac8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122acc ldr r2, [sp, #0x28] */
/* @0x122ad0 ldr r12, [sp, #0x24] */
/* @0x122ad4 mov r1, r7 */
/* @0x122ad8 str r11, [sp, #0xc] */
/* @0x122adc str r2, [sp, #0x4] */
/* @0x122ae0 ldr r2, [sp, #0x2c] */
/* @0x122ae4 str r12, [sp] */
/* @0x122ae8 str r10, [sp, #0x10] */
/* @0x122aec str r2, [sp, #0x8] */
/* @0x122af0 mov r2, r6 */
/* @0x122af4 str r9, [sp, #0x14] */
/* @0x122af8 str r8, [sp, #0x18] */
/* @0x122afc ldr r3, [sp, #0x20] */
/* @0x122b00 str r0, [sp, #0x1c] */
/* @0x122b04 mov r0, r5 */
/* @0x122b08 bl 0x1e5e34 <_ZN7CSprite8DrawPartEiffffffffjf> */
/* @0x122b0c add sp, sp, #60 */
/* @0x122b10 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x122b14 ldr r0, [pc, #0x20] */
/* @0x122b18 mov r1, #0 */
/* @0x122b1c add r0, pc, r0 */
/* @0x122b20 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x122b24 b 0x1229f8 <_Z19F_DrawSpritePartExtR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x122b28 ldr r0, [pc, #0x10] */
/* @0x122b2c mov r1, #0 */
/* @0x122b30 add r0, pc, r0 */
/* @0x122b34 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x122b38 b 0x1229f8 <_Z19F_DrawSpritePartExtR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x122b3c eoreq r7, r1, r0, lsl r10 */
/* @0x122b40 eoreq r7, r1, r4, asr #19 */

/* ── FUNC 0x122b44 · F_DrawSpriteGeneral(RValue&, CInstance*, CInstance*, int, RValue*) · size=464 · insn=116 */
/* @0x122b44 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x122b48 sub sp, sp, #92 */
/* @0x122b4c mov r0, r1 */
/* @0x122b50 add r2, sp, #80 */
/* @0x122b54 ldr r4, [sp, #0x80] */
/* @0x122b58 add r3, sp, #84 */
/* @0x122b5c mov r1, r4 */
/* @0x122b60 bl 0x1226c4 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_> */
/* @0x122b64 cmp r0, #0 */
/* @0x122b68 bne 0x122b74 <_Z19F_DrawSpriteGeneralR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x122b6c add sp, sp, #92 */
/* @0x122b70 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x122b74 ldr r0, [sp, #0x50] */
/* @0x122b78 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x122b7c ldr r3, [r0, #0x74] */
/* @0x122b80 mov r5, r0 */
/* @0x122b84 cmp r3, #1 */
/* @0x122b88 beq 0x122cf8 <_Z19F_DrawSpriteGeneralR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x122b8c cmp r3, #2 */
/* @0x122b90 beq 0x122ce4 <_Z19F_DrawSpriteGeneralR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x122b94 ldr r3, [sp, #0x54] */
/* @0x122b98 mov r0, r4 */
/* @0x122b9c mov r1, #2 */
/* @0x122ba0 str r3, [sp, #0x3c] */
/* @0x122ba4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122ba8 mov r1, #3 */
/* @0x122bac mov r2, r0 */
/* @0x122bb0 mov r0, r4 */
/* @0x122bb4 str r2, [sp, #0x30] */
/* @0x122bb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122bbc mov r1, #4 */
/* @0x122bc0 mov r3, r0 */
/* @0x122bc4 mov r0, r4 */
/* @0x122bc8 str r3, [sp, #0x34] */
/* @0x122bcc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122bd0 mov r1, #5 */
/* @0x122bd4 mov r12, r0 */
/* @0x122bd8 mov r0, r4 */
/* @0x122bdc str r12, [sp, #0x38] */
/* @0x122be0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122be4 mov r1, #6 */
/* @0x122be8 str r0, [sp, #0x40] */
/* @0x122bec mov r0, r4 */
/* @0x122bf0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122bf4 mov r1, #7 */
/* @0x122bf8 str r0, [sp, #0x44] */
/* @0x122bfc mov r0, r4 */
/* @0x122c00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122c04 mov r1, #8 */
/* @0x122c08 mov r11, r0 */
/* @0x122c0c mov r0, r4 */
/* @0x122c10 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122c14 mov r1, #9 */
/* @0x122c18 mov r10, r0 */
/* @0x122c1c mov r0, r4 */
/* @0x122c20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122c24 mov r1, #10 */
/* @0x122c28 str r0, [sp, #0x48] */
/* @0x122c2c mov r0, r4 */
/* @0x122c30 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122c34 mov r1, #11 */
/* @0x122c38 str r0, [sp, #0x4c] */
/* @0x122c3c mov r0, r4 */
/* @0x122c40 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x122c44 mov r1, #12 */
/* @0x122c48 mov r9, r0 */
/* @0x122c4c mov r0, r4 */
/* @0x122c50 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x122c54 mov r1, #13 */
/* @0x122c58 mov r8, r0 */
/* @0x122c5c mov r0, r4 */
/* @0x122c60 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x122c64 mov r1, #14 */
/* @0x122c68 mov r7, r0 */
/* @0x122c6c mov r0, r4 */
/* @0x122c70 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x122c74 mov r1, #15 */
/* @0x122c78 mov r6, r0 */
/* @0x122c7c mov r0, r4 */
/* @0x122c80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122c84 ldr r1, [sp, #0x40] */
/* @0x122c88 ldr r12, [sp, #0x38] */
/* @0x122c8c str r11, [sp, #0xc] */
/* @0x122c90 str r1, [sp, #0x4] */
/* @0x122c94 ldr r1, [sp, #0x44] */
/* @0x122c98 str r12, [sp] */
/* @0x122c9c str r10, [sp, #0x10] */
/* @0x122ca0 str r1, [sp, #0x8] */
/* @0x122ca4 ldr r1, [sp, #0x48] */
/* @0x122ca8 str r9, [sp, #0x1c] */
/* @0x122cac str r8, [sp, #0x20] */
/* @0x122cb0 str r1, [sp, #0x14] */
/* @0x122cb4 ldr r1, [sp, #0x4c] */
/* @0x122cb8 str r7, [sp, #0x24] */
/* @0x122cbc str r6, [sp, #0x28] */
/* @0x122cc0 str r1, [sp, #0x18] */
/* @0x122cc4 ldr r2, [sp, #0x30] */
/* @0x122cc8 ldr r1, [sp, #0x3c] */
/* @0x122ccc ldr r3, [sp, #0x34] */
/* @0x122cd0 str r0, [sp, #0x2c] */
/* @0x122cd4 mov r0, r5 */
/* @0x122cd8 bl 0x1e5fa8 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf> */
/* @0x122cdc add sp, sp, #92 */
/* @0x122ce0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x122ce4 ldr r0, [pc, #0x20] */
/* @0x122ce8 mov r1, #0 */
/* @0x122cec add r0, pc, r0 */
/* @0x122cf0 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x122cf4 b 0x122b6c <_Z19F_DrawSpriteGeneralR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x122cf8 ldr r0, [pc, #0x10] */
/* @0x122cfc mov r1, #0 */
/* @0x122d00 add r0, pc, r0 */
/* @0x122d04 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x122d08 b 0x122b6c <_Z19F_DrawSpriteGeneralR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x122d0c .word 0x002178b8 */
/* @0x122d10 eoreq r7, r1, r12, ror #16 */

/* ── FUNC 0x122d14 · F_DrawSpriteStretched(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0x122d14 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x122d18 sub sp, sp, #28 */
/* @0x122d1c mov r0, r1 */
/* @0x122d20 add r2, sp, #16 */
/* @0x122d24 ldr r4, [sp, #0x38] */
/* @0x122d28 add r3, sp, #20 */
/* @0x122d2c mov r1, r4 */
/* @0x122d30 bl 0x1226c4 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_> */
/* @0x122d34 cmp r0, #0 */
/* @0x122d38 bne 0x122d44 <_Z21F_DrawSpriteStretchedR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x122d3c add sp, sp, #28 */
/* @0x122d40 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x122d44 ldr r0, [sp, #0x10] */
/* @0x122d48 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x122d4c mov r1, #2 */
/* @0x122d50 ldr r8, [sp, #0x14] */
/* @0x122d54 mov r5, r0 */
/* @0x122d58 mov r0, r4 */
/* @0x122d5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122d60 mov r1, #3 */
/* @0x122d64 mov r7, r0 */
/* @0x122d68 mov r0, r4 */
/* @0x122d6c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122d70 mov r1, #4 */
/* @0x122d74 mov r6, r0 */
/* @0x122d78 mov r0, r4 */
/* @0x122d7c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122d80 mov r1, #5 */
/* @0x122d84 mov r9, r0 */
/* @0x122d88 mov r0, r4 */
/* @0x122d8c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122d90 mov r4, r0 */
/* @0x122d94 bl 0x169f1c <_Z17GR_Draw_Get_Alphav> */
/* @0x122d98 mvn r12, #-16777216 */
/* @0x122d9c str r9, [sp] */
/* @0x122da0 str r4, [sp, #0x4] */
/* @0x122da4 mov r1, r8 */
/* @0x122da8 mov r2, r7 */
/* @0x122dac mov r3, r6 */
/* @0x122db0 str r12, [sp, #0x8] */
/* @0x122db4 str r0, [sp, #0xc] */
/* @0x122db8 mov r0, r5 */
/* @0x122dbc bl 0x1ecdc4 <_ZN7CSprite13DrawStretchedEiffffjf> */
/* @0x122dc0 add sp, sp, #28 */
/* @0x122dc4 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x122dc8 · F_DrawSpriteStretchedExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=200 · insn=50 */
/* @0x122dc8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x122dcc sub sp, sp, #28 */
/* @0x122dd0 mov r0, r1 */
/* @0x122dd4 add r2, sp, #16 */
/* @0x122dd8 ldr r4, [sp, #0x40] */
/* @0x122ddc add r3, sp, #20 */
/* @0x122de0 mov r1, r4 */
/* @0x122de4 bl 0x1226c4 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_> */
/* @0x122de8 cmp r0, #0 */
/* @0x122dec bne 0x122df8 <_Z24F_DrawSpriteStretchedExtR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x122df0 add sp, sp, #28 */
/* @0x122df4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x122df8 ldr r0, [sp, #0x10] */
/* @0x122dfc bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x122e00 mov r1, #2 */
/* @0x122e04 ldr r8, [sp, #0x14] */
/* @0x122e08 mov r5, r0 */
/* @0x122e0c mov r0, r4 */
/* @0x122e10 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122e14 mov r1, #3 */
/* @0x122e18 mov r7, r0 */
/* @0x122e1c mov r0, r4 */
/* @0x122e20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122e24 mov r1, #4 */
/* @0x122e28 mov r6, r0 */
/* @0x122e2c mov r0, r4 */
/* @0x122e30 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122e34 mov r1, #5 */
/* @0x122e38 mov r11, r0 */
/* @0x122e3c mov r0, r4 */
/* @0x122e40 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122e44 mov r1, #6 */
/* @0x122e48 mov r10, r0 */
/* @0x122e4c mov r0, r4 */
/* @0x122e50 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x122e54 mov r1, #7 */
/* @0x122e58 mov r9, r0 */
/* @0x122e5c mov r0, r4 */
/* @0x122e60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122e64 str r11, [sp] */
/* @0x122e68 str r10, [sp, #0x4] */
/* @0x122e6c mov r1, r8 */
/* @0x122e70 str r9, [sp, #0x8] */
/* @0x122e74 mov r2, r7 */
/* @0x122e78 mov r3, r6 */
/* @0x122e7c str r0, [sp, #0xc] */
/* @0x122e80 mov r0, r5 */
/* @0x122e84 bl 0x1ecdc4 <_ZN7CSprite13DrawStretchedEiffffjf> */
/* @0x122e88 add sp, sp, #28 */
/* @0x122e8c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x122e90 · F_DrawSpriteTiled(RValue&, CInstance*, CInstance*, int, RValue*) · size=228 · insn=57 */
/* @0x122e90 push {r4, r5, r6, r7, lr} */
/* @0x122e94 vpush {d8} */
/* @0x122e98 sub sp, sp, #52 */
/* @0x122e9c mov r0, r1 */
/* @0x122ea0 add r2, sp, #40 */
/* @0x122ea4 ldr r4, [sp, #0x50] */
/* @0x122ea8 add r3, sp, #44 */
/* @0x122eac mov r1, r4 */
/* @0x122eb0 bl 0x1226c4 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_> */
/* @0x122eb4 cmp r0, #0 */
/* @0x122eb8 bne 0x122ec8 <_Z17F_DrawSpriteTiledR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x122ebc add sp, sp, #52 */
/* @0x122ec0 vpop {d8} */
/* @0x122ec4 pop {r4, r5, r6, r7, pc} */
/* @0x122ec8 ldr r0, [sp, #0x28] */
/* @0x122ecc bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x122ed0 mov r1, #2 */
/* @0x122ed4 ldr r7, [sp, #0x2c] */
/* @0x122ed8 mov r5, r0 */
/* @0x122edc mov r0, r4 */
/* @0x122ee0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122ee4 mov r1, #3 */
/* @0x122ee8 mov r6, r0 */
/* @0x122eec mov r0, r4 */
/* @0x122ef0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122ef4 ldr r12, [pc, #0x74] */
/* @0x122ef8 ldr r12, [pc, r12] */
/* @0x122efc ldr r12, [r12] */
/* @0x122f00 vldr s17, [r12, #16] */
/* @0x122f04 vldr s16, [r12, #20] */
/* @0x122f08 vcvt.f32.s32 s17, s17 */
/* @0x122f0c vcvt.f32.s32 s16, s16 */
/* @0x122f10 mov r4, r0 */
/* @0x122f14 bl 0x169f1c <_Z17GR_Draw_Get_Alphav> */
/* @0x122f18 mov lr, #0 */
/* @0x122f1c mov r12, #1 */
/* @0x122f20 vstr s17, [sp, #24] */
/* @0x122f24 str r12, [sp, #0x8] */
/* @0x122f28 str r12, [sp, #0xc] */
/* @0x122f2c mov r1, r7 */
/* @0x122f30 mov r2, r6 */
/* @0x122f34 mov r3, r4 */
/* @0x122f38 str lr, [sp, #0x10] */
/* @0x122f3c mvn r12, #-16777216 */
/* @0x122f40 str lr, [sp, #0x14] */
/* @0x122f44 vstr s16, [sp, #28] */
/* @0x122f48 str r12, [sp, #0x20] */
/* @0x122f4c mov r12, #1065353216 */
/* @0x122f50 str r12, [sp] */
/* @0x122f54 str r12, [sp, #0x4] */
/* @0x122f58 str r0, [sp, #0x24] */
/* @0x122f5c mov r0, r5 */
/* @0x122f60 bl 0x1ed1dc <_ZN7CSprite9DrawTiledEiffffbbffffjf> */
/* @0x122f64 add sp, sp, #52 */
/* @0x122f68 vpop {d8} */
/* @0x122f6c pop {r4, r5, r6, r7, pc} */
/* @0x122f70 eoreq r10, r12, r0, lsr r10 */

/* ── FUNC 0x122f74 · F_DrawSpriteTiledExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=276 · insn=69 */
/* @0x122f74 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x122f78 vpush {d8} */
/* @0x122f7c sub sp, sp, #52 */
/* @0x122f80 mov r0, r1 */
/* @0x122f84 add r2, sp, #40 */
/* @0x122f88 ldr r4, [sp, #0x60] */
/* @0x122f8c add r3, sp, #44 */
/* @0x122f90 mov r1, r4 */
/* @0x122f94 bl 0x1226c4 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_> */
/* @0x122f98 cmp r0, #0 */
/* @0x122f9c bne 0x122fac <_Z20F_DrawSpriteTiledExtR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x122fa0 add sp, sp, #52 */
/* @0x122fa4 vpop {d8} */
/* @0x122fa8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x122fac ldr r0, [sp, #0x28] */
/* @0x122fb0 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x122fb4 mov r1, #2 */
/* @0x122fb8 ldr r8, [sp, #0x2c] */
/* @0x122fbc mov r5, r0 */
/* @0x122fc0 mov r0, r4 */
/* @0x122fc4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122fc8 mov r1, #3 */
/* @0x122fcc mov r7, r0 */
/* @0x122fd0 mov r0, r4 */
/* @0x122fd4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122fd8 mov r1, #4 */
/* @0x122fdc mov r6, r0 */
/* @0x122fe0 mov r0, r4 */
/* @0x122fe4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122fe8 mov r1, #5 */
/* @0x122fec mov r11, r0 */
/* @0x122ff0 mov r0, r4 */
/* @0x122ff4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122ff8 ldr r12, [pc, #0x84] */
/* @0x122ffc mov r1, #6 */
/* @0x123000 ldr r12, [pc, r12] */
/* @0x123004 ldr r12, [r12] */
/* @0x123008 vldr s17, [r12, #16] */
/* @0x12300c vldr s16, [r12, #20] */
/* @0x123010 vcvt.f32.s32 s17, s17 */
/* @0x123014 vcvt.f32.s32 s16, s16 */
/* @0x123018 mov r10, r0 */
/* @0x12301c mov r0, r4 */
/* @0x123020 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x123024 mov r1, #7 */
/* @0x123028 mov r9, r0 */
/* @0x12302c mov r0, r4 */
/* @0x123030 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x123034 mov r12, #1 */
/* @0x123038 mov lr, #0 */
/* @0x12303c str r11, [sp] */
/* @0x123040 vstr s17, [sp, #24] */
/* @0x123044 str r10, [sp, #0x4] */
/* @0x123048 str r9, [sp, #0x20] */
/* @0x12304c mov r1, r8 */
/* @0x123050 mov r2, r7 */
/* @0x123054 vstr s16, [sp, #28] */
/* @0x123058 mov r3, r6 */
/* @0x12305c str r12, [sp, #0x8] */
/* @0x123060 str r12, [sp, #0xc] */
/* @0x123064 str lr, [sp, #0x10] */
/* @0x123068 str lr, [sp, #0x14] */
/* @0x12306c str r0, [sp, #0x24] */
/* @0x123070 mov r0, r5 */
/* @0x123074 bl 0x1ed1dc <_ZN7CSprite9DrawTiledEiffffbbffffjf> */
/* @0x123078 add sp, sp, #52 */
/* @0x12307c vpop {d8} */
/* @0x123080 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x123084 eoreq r10, r12, r8, lsr #18 */

/* ── FUNC 0x123088 · YYGML_draw_self(CInstance*) · size=172 · insn=43 */
/* @0x123088 push {r4, r5, r6, lr} */
/* @0x12308c mov r4, r0 */
/* @0x123090 sub sp, sp, #24 */
/* @0x123094 ldr r0, [r0, #0x8c] */
/* @0x123098 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12309c subs r6, r0, #0 */
/* @0x1230a0 beq 0x123114 <_Z15YYGML_draw_selfP9CInstance+0x8c> */
/* @0x1230a4 vldr s15, [r4, #144] */
/* @0x1230a8 vcvt.f64.f32 d6, s15 */
/* @0x1230ac ldr r5, [pc, #0x78] */
/* @0x1230b0 ldr r5, [pc, r5] */
/* @0x1230b4 str r4, [r5] */
/* @0x1230b8 vmov r0, r1, d6 */
/* @0x1230bc bl 0xb6598 <floor@plt> */
/* @0x1230c0 ldr r12, [r4, #0xa8] */
/* @0x1230c4 ldr lr, [r4, #0x98] */
/* @0x1230c8 ldr r3, [r4, #0xb8] */
/* @0x1230cc ldr r2, [r4, #0xb4] */
/* @0x1230d0 str r12, [sp, #0xc] */
/* @0x1230d4 str lr, [sp] */
/* @0x1230d8 ldr r12, [r4, #0xa0] */
/* @0x1230dc ldr lr, [r4, #0x9c] */
/* @0x1230e0 str r12, [sp, #0x8] */
/* @0x1230e4 str lr, [sp, #0x4] */
/* @0x1230e8 ldr r12, [r4, #0xa4] */
/* @0x1230ec str r12, [sp, #0x10] */
/* @0x1230f0 vmov d7, r0, r1 */
/* @0x1230f4 mov r0, r6 */
/* @0x1230f8 vcvt.s32.f64 s15, d7 */
/* @0x1230fc vmov r1, s15 */
/* @0x123100 bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */
/* @0x123104 mov r3, #0 */
/* @0x123108 str r3, [r5] */
/* @0x12310c add sp, sp, #24 */
/* @0x123110 pop {r4, r5, r6, pc} */
/* @0x123114 ldr r0, [pc, #0x14] */
/* @0x123118 mov r1, r6 */
/* @0x12311c add r0, pc, r0 */
/* @0x123120 add sp, sp, #24 */
/* @0x123124 pop {r4, r5, r6, lr} */
/* @0x123128 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12312c eoreq r10, r12, r4, lsl #17 */
/* @0x123130 mlaeq r1, r8, lr, r6 */

/* ── FUNC 0x123134 · F_DrawSelf(RValue&, CInstance*, CInstance*, int, RValue*) · size=8 · insn=2 */
/* @0x123134 mov r0, r1 */
/* @0x123138 b 0x123088 <_Z15YYGML_draw_selfP9CInstance> */

/* ── FUNC 0x12313c · YYGML_draw_sprite(CInstance*, int, int, float, float) · size=56 · insn=14 */
/* @0x12313c push {r4, r5, r6, lr} */
/* @0x123140 subs r4, r2, #0 */
/* @0x123144 vldrlt s15, [r0, #144] */
/* @0x123148 ldr r5, [sp, #0x10] */
/* @0x12314c mov r6, r3 */
/* @0x123150 vcvtlt.s32.f32 s15, s15 */
/* @0x123154 mov r0, r1 */
/* @0x123158 vmovlt r4, s15 */
/* @0x12315c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x123160 mov r2, r6 */
/* @0x123164 mov r3, r5 */
/* @0x123168 mov r1, r4 */
/* @0x12316c pop {r4, r5, r6, lr} */
/* @0x123170 b 0x1ecab4 <_ZN7CSprite10DrawSimpleEiff> */

/* ── FUNC 0x123174 · YYGML_draw_sprite_ext(CInstance*, int, int, float, float, float, float, float, int, float) · size=104 · insn=26 */
/* @0x123174 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x123178 subs r4, r2, #0 */
/* @0x12317c vldrlt s15, [r0, #144] */
/* @0x123180 sub sp, sp, #4 */
/* @0x123184 mov r0, r1 */
/* @0x123188 vcvtlt.s32.f32 s15, s15 */
/* @0x12318c mov r6, r3 */
/* @0x123190 ldr r5, [sp, #0x28] */
/* @0x123194 ldr r11, [sp, #0x2c] */
/* @0x123198 ldr r10, [sp, #0x30] */
/* @0x12319c ldr r9, [sp, #0x34] */
/* @0x1231a0 ldr r7, [sp, #0x38] */
/* @0x1231a4 ldr r8, [sp, #0x3c] */
/* @0x1231a8 vmovlt r4, s15 */
/* @0x1231ac bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1231b0 str r11, [sp, #0x28] */
/* @0x1231b4 mov r2, r6 */
/* @0x1231b8 str r10, [sp, #0x2c] */
/* @0x1231bc mov r3, r5 */
/* @0x1231c0 str r9, [sp, #0x30] */
/* @0x1231c4 str r7, [sp, #0x34] */
/* @0x1231c8 str r8, [sp, #0x38] */
/* @0x1231cc mov r1, r4 */
/* @0x1231d0 add sp, sp, #4 */
/* @0x1231d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1231d8 b 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */

/* ── FUNC 0x1231dc · YYGML_draw_sprite_part(CInstance*, int, int, float, float, float, float, float, float) · size=132 · insn=33 */
/* @0x1231dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1231e0 subs r4, r2, #0 */
/* @0x1231e4 vldrlt s15, [r0, #144] */
/* @0x1231e8 sub sp, sp, #36 */
/* @0x1231ec mov r0, r1 */
/* @0x1231f0 vcvtlt.s32.f32 s15, s15 */
/* @0x1231f4 mov r7, r3 */
/* @0x1231f8 ldr r5, [sp, #0x48] */
/* @0x1231fc ldr r11, [sp, #0x4c] */
/* @0x123200 ldr r10, [sp, #0x50] */
/* @0x123204 ldr r9, [sp, #0x54] */
/* @0x123208 ldr r8, [sp, #0x58] */
/* @0x12320c vmovlt r4, s15 */
/* @0x123210 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x123214 mov r6, r0 */
/* @0x123218 bl 0x169f1c <_Z17GR_Draw_Get_Alphav> */
/* @0x12321c mov r12, #1065353216 */
/* @0x123220 mvn lr, #-16777216 */
/* @0x123224 str r11, [sp] */
/* @0x123228 mov r1, r4 */
/* @0x12322c str r10, [sp, #0x4] */
/* @0x123230 mov r2, r7 */
/* @0x123234 str r9, [sp, #0x8] */
/* @0x123238 mov r3, r5 */
/* @0x12323c str r8, [sp, #0xc] */
/* @0x123240 str lr, [sp, #0x18] */
/* @0x123244 str r12, [sp, #0x10] */
/* @0x123248 str r12, [sp, #0x14] */
/* @0x12324c str r0, [sp, #0x1c] */
/* @0x123250 mov r0, r6 */
/* @0x123254 bl 0x1e5e34 <_ZN7CSprite8DrawPartEiffffffffjf> */
/* @0x123258 add sp, sp, #36 */
/* @0x12325c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x123260 · YYGML_surface_set_target(int) · size=12 · insn=3 */
/* @0x123260 mov r1, r0 */
/* @0x123264 mov r0, #0 */
/* @0x123268 b 0x171574 <_Z28YYGML_surface_set_target_extii> */

/* ── FUNC 0x12326c · InitGraphicFunctions() · size=10904 · insn=2726 */
/* @0x12326c push {r4, r5, r6, lr} */
/* @0x123270 mov r2, #0 */
/* @0x123274 ldr r4, [pc, #0xff4] */
/* @0x123278 mov r3, r2 */
/* @0x12327c ldr r1, [pc, #0xff0] */
/* @0x123280 add r4, pc, r4 */
/* @0x123284 ldr r0, [pc, #0xfec] */
/* @0x123288 ldr r1, [r4, r1] */
/* @0x12328c add r0, pc, r0 */
/* @0x123290 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123294 ldr r1, [pc, #0xfe0] */
/* @0x123298 ldr r0, [pc, #0xfe0] */
/* @0x12329c mov r2, #0 */
/* @0x1232a0 mov r3, r2 */
/* @0x1232a4 ldr r1, [r4, r1] */
/* @0x1232a8 add r0, pc, r0 */
/* @0x1232ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1232b0 ldr r1, [pc, #0xfcc] */
/* @0x1232b4 ldr r0, [pc, #0xfcc] */
/* @0x1232b8 mov r2, #0 */
/* @0x1232bc mov r3, r2 */
/* @0x1232c0 ldr r1, [r4, r1] */
/* @0x1232c4 add r0, pc, r0 */
/* @0x1232c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1232cc ldr r1, [pc, #0xfb8] */
/* @0x1232d0 ldr r0, [pc, #0xfb8] */
/* @0x1232d4 mov r2, #0 */
/* @0x1232d8 mov r3, r2 */
/* @0x1232dc ldr r1, [r4, r1] */
/* @0x1232e0 add r0, pc, r0 */
/* @0x1232e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1232e8 ldr r1, [pc, #0xfa4] */
/* @0x1232ec ldr r0, [pc, #0xfa4] */
/* @0x1232f0 mov r2, #0 */
/* @0x1232f4 mov r3, r2 */
/* @0x1232f8 ldr r1, [r4, r1] */
/* @0x1232fc add r0, pc, r0 */
/* @0x123300 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123304 ldr r1, [pc, #0xf90] */
/* @0x123308 ldr r0, [pc, #0xf90] */
/* @0x12330c mov r2, #2 */
/* @0x123310 mov r3, #1 */
/* @0x123314 ldr r1, [r4, r1] */
/* @0x123318 add r0, pc, r0 */
/* @0x12331c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123320 ldr r1, [pc, #0xf7c] */
/* @0x123324 ldr r0, [pc, #0xf7c] */
/* @0x123328 mov r2, #1 */
/* @0x12332c mov r3, r2 */
/* @0x123330 ldr r1, [r4, r1] */
/* @0x123334 add r0, pc, r0 */
/* @0x123338 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12333c ldr r1, [pc, #0xf68] */
/* @0x123340 ldr r0, [pc, #0xf68] */
/* @0x123344 mov r2, #1 */
/* @0x123348 mov r3, r2 */
/* @0x12334c ldr r1, [r4, r1] */
/* @0x123350 add r0, pc, r0 */
/* @0x123354 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123358 ldr r1, [pc, #0xf54] */
/* @0x12335c ldr r0, [pc, #0xf54] */
/* @0x123360 mov r2, #4 */
/* @0x123364 mov r3, #1 */
/* @0x123368 ldr r1, [r4, r1] */
/* @0x12336c add r0, pc, r0 */
/* @0x123370 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123374 ldr r1, [pc, #0xf40] */
/* @0x123378 ldr r0, [pc, #0xf40] */
/* @0x12337c mov r2, #4 */
/* @0x123380 mov r3, #1 */
/* @0x123384 ldr r1, [r4, r1] */
/* @0x123388 add r0, pc, r0 */
/* @0x12338c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123390 ldr r1, [pc, #0xf2c] */
/* @0x123394 ldr r0, [pc, #0xf2c] */
/* @0x123398 mov r2, #1 */
/* @0x12339c mov r3, r2 */
/* @0x1233a0 ldr r1, [r4, r1] */
/* @0x1233a4 add r0, pc, r0 */
/* @0x1233a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1233ac ldr r1, [pc, #0xf18] */
/* @0x1233b0 ldr r0, [pc, #0xf18] */
/* @0x1233b4 mov r2, #0 */
/* @0x1233b8 mov r3, r2 */
/* @0x1233bc ldr r1, [r4, r1] */
/* @0x1233c0 add r0, pc, r0 */
/* @0x1233c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1233c8 ldr r1, [pc, #0xf04] */
/* @0x1233cc ldr r0, [pc, #0xf04] */
/* @0x1233d0 mov r2, #0 */
/* @0x1233d4 mov r3, r2 */
/* @0x1233d8 ldr r1, [r4, r1] */
/* @0x1233dc add r0, pc, r0 */
/* @0x1233e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1233e4 ldr r1, [pc, #0xef0] */
/* @0x1233e8 ldr r0, [pc, #0xef0] */
/* @0x1233ec mov r2, #2 */
/* @0x1233f0 mov r3, #0 */
/* @0x1233f4 ldr r1, [r4, r1] */
/* @0x1233f8 add r0, pc, r0 */
/* @0x1233fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123400 ldr r1, [pc, #0xedc] */
/* @0x123404 ldr r0, [pc, #0xedc] */
/* @0x123408 mov r2, #1 */
/* @0x12340c mov r3, #0 */
/* @0x123410 ldr r1, [r4, r1] */
/* @0x123414 add r0, pc, r0 */
/* @0x123418 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12341c ldr r1, [pc, #0xec8] */
/* @0x123420 ldr r0, [pc, #0xec8] */
/* @0x123424 mov r2, #0 */
/* @0x123428 mov r3, r2 */
/* @0x12342c ldr r1, [r4, r1] */
/* @0x123430 add r0, pc, r0 */
/* @0x123434 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123438 ldr r1, [pc, #0xeb4] */
/* @0x12343c ldr r0, [pc, #0xeb4] */
/* @0x123440 mov r2, #0 */
/* @0x123444 mov r3, r2 */
/* @0x123448 ldr r1, [r4, r1] */
/* @0x12344c add r0, pc, r0 */
/* @0x123450 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123454 ldr r1, [pc, #0xea0] */
/* @0x123458 ldr r0, [pc, #0xea0] */
/* @0x12345c mov r2, #1 */
/* @0x123460 mov r3, #0 */
/* @0x123464 ldr r1, [r4, r1] */
/* @0x123468 add r0, pc, r0 */
/* @0x12346c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123470 ldr r1, [pc, #0xe8c] */
/* @0x123474 ldr r0, [pc, #0xe8c] */
/* @0x123478 mov r2, #1 */
/* @0x12347c mov r3, #0 */
/* @0x123480 ldr r1, [r4, r1] */
/* @0x123484 add r0, pc, r0 */
/* @0x123488 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12348c ldr r1, [pc, #0xe78] */
/* @0x123490 ldr r0, [pc, #0xe78] */
/* @0x123494 mov r2, #1 */
/* @0x123498 mov r3, #0 */
/* @0x12349c ldr r1, [r4, r1] */
/* @0x1234a0 add r0, pc, r0 */
/* @0x1234a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1234a8 ldr r1, [pc, #0xe64] */
/* @0x1234ac ldr r0, [pc, #0xe64] */
/* @0x1234b0 mov r2, #1 */
/* @0x1234b4 mov r3, #0 */
/* @0x1234b8 ldr r1, [r4, r1] */
/* @0x1234bc add r0, pc, r0 */
/* @0x1234c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1234c4 ldr r1, [pc, #0xe50] */
/* @0x1234c8 ldr r0, [pc, #0xe50] */
/* @0x1234cc mov r2, #0 */
/* @0x1234d0 mov r3, r2 */
/* @0x1234d4 ldr r1, [r4, r1] */
/* @0x1234d8 add r0, pc, r0 */
/* @0x1234dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1234e0 ldr r1, [pc, #0xe3c] */
/* @0x1234e4 ldr r0, [pc, #0xe3c] */
/* @0x1234e8 mov r2, #1 */
/* @0x1234ec mov r3, #0 */
/* @0x1234f0 ldr r1, [r4, r1] */
/* @0x1234f4 add r0, pc, r0 */
/* @0x1234f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1234fc ldr r1, [pc, #0xe28] */
/* @0x123500 ldr r0, [pc, #0xe28] */
/* @0x123504 mov r2, #0 */
/* @0x123508 mov r3, r2 */
/* @0x12350c ldr r1, [r4, r1] */
/* @0x123510 add r0, pc, r0 */
/* @0x123514 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123518 ldr r1, [pc, #0xe14] */
/* @0x12351c ldr r0, [pc, #0xe14] */
/* @0x123520 mov r2, #1 */
/* @0x123524 mov r3, #0 */
/* @0x123528 ldr r1, [r4, r1] */
/* @0x12352c add r0, pc, r0 */
/* @0x123530 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123534 ldr r1, [pc, #0xe00] */
/* @0x123538 ldr r0, [pc, #0xe00] */
/* @0x12353c mov r2, #0 */
/* @0x123540 mov r3, r2 */
/* @0x123544 ldr r1, [r4, r1] */
/* @0x123548 add r0, pc, r0 */
/* @0x12354c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123550 ldr r1, [pc, #0xdec] */
/* @0x123554 ldr r0, [pc, #0xdec] */
/* @0x123558 mov r2, #1 */
/* @0x12355c mov r3, #0 */
/* @0x123560 ldr r1, [r4, r1] */
/* @0x123564 add r0, pc, r0 */
/* @0x123568 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12356c ldr r1, [pc, #0xdd8] */
/* @0x123570 ldr r0, [pc, #0xdd8] */
/* @0x123574 mov r2, #0 */
/* @0x123578 mov r3, r2 */
/* @0x12357c ldr r1, [r4, r1] */
/* @0x123580 add r0, pc, r0 */
/* @0x123584 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123588 ldr r1, [pc, #0xdc4] */
/* @0x12358c ldr r0, [pc, #0xdc4] */
/* @0x123590 mov r2, #1 */
/* @0x123594 mov r3, #0 */
/* @0x123598 ldr r1, [r4, r1] */
/* @0x12359c add r0, pc, r0 */
/* @0x1235a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1235a4 ldr r1, [pc, #0xdb0] */
/* @0x1235a8 ldr r0, [pc, #0xdb0] */
/* @0x1235ac mov r2, #0 */
/* @0x1235b0 mov r3, r2 */
/* @0x1235b4 ldr r1, [r4, r1] */
/* @0x1235b8 add r0, pc, r0 */
/* @0x1235bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1235c0 ldr r1, [pc, #0xd9c] */
/* @0x1235c4 ldr r0, [pc, #0xd9c] */
/* @0x1235c8 mov r2, #1 */
/* @0x1235cc mov r3, #0 */
/* @0x1235d0 ldr r1, [r4, r1] */
/* @0x1235d4 add r0, pc, r0 */
/* @0x1235d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1235dc ldr r1, [pc, #0xd88] */
/* @0x1235e0 ldr r0, [pc, #0xd88] */
/* @0x1235e4 mov r2, #0 */
/* @0x1235e8 mov r3, r2 */
/* @0x1235ec ldr r1, [r4, r1] */
/* @0x1235f0 add r0, pc, r0 */
/* @0x1235f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1235f8 ldr r1, [pc, #0xd74] */
/* @0x1235fc ldr r0, [pc, #0xd74] */
/* @0x123600 mov r2, #1 */
/* @0x123604 mov r3, #0 */
/* @0x123608 ldr r1, [r4, r1] */
/* @0x12360c add r0, pc, r0 */
/* @0x123610 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123614 ldr r1, [pc, #0xd60] */
/* @0x123618 ldr r0, [pc, #0xd60] */
/* @0x12361c mov r2, #0 */
/* @0x123620 mov r3, r2 */
/* @0x123624 ldr r1, [r4, r1] */
/* @0x123628 add r0, pc, r0 */
/* @0x12362c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123630 ldr r1, [pc, #0xd4c] */
/* @0x123634 ldr r0, [pc, #0xd4c] */
/* @0x123638 mov r2, #1 */
/* @0x12363c mov r3, #0 */
/* @0x123640 ldr r1, [r4, r1] */
/* @0x123644 add r0, pc, r0 */
/* @0x123648 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12364c ldr r1, [pc, #0xd38] */
/* @0x123650 ldr r0, [pc, #0xd38] */
/* @0x123654 mov r2, #0 */
/* @0x123658 mov r3, r2 */
/* @0x12365c ldr r1, [r4, r1] */
/* @0x123660 add r0, pc, r0 */
/* @0x123664 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123668 ldr r1, [pc, #0xd24] */
/* @0x12366c ldr r0, [pc, #0xd24] */
/* @0x123670 mov r2, #1 */
/* @0x123674 mov r3, #0 */
/* @0x123678 ldr r1, [r4, r1] */
/* @0x12367c add r0, pc, r0 */
/* @0x123680 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123684 ldr r1, [pc, #0xd10] */
/* @0x123688 ldr r0, [pc, #0xd10] */
/* @0x12368c mov r2, #0 */
/* @0x123690 mov r3, r2 */
/* @0x123694 ldr r1, [r4, r1] */
/* @0x123698 add r0, pc, r0 */
/* @0x12369c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1236a0 ldr r1, [pc, #0xcfc] */
/* @0x1236a4 ldr r0, [pc, #0xcfc] */
/* @0x1236a8 mov r2, #1 */
/* @0x1236ac mov r3, #0 */
/* @0x1236b0 ldr r1, [r4, r1] */
/* @0x1236b4 add r0, pc, r0 */
/* @0x1236b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1236bc ldr r1, [pc, #0xce8] */
/* @0x1236c0 ldr r0, [pc, #0xce8] */
/* @0x1236c4 mov r2, #0 */
/* @0x1236c8 mov r3, r2 */
/* @0x1236cc ldr r1, [r4, r1] */
/* @0x1236d0 add r0, pc, r0 */
/* @0x1236d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1236d8 ldr r1, [pc, #0xcd4] */
/* @0x1236dc ldr r0, [pc, #0xcd4] */
/* @0x1236e0 mov r2, #1 */
/* @0x1236e4 mov r3, #0 */
/* @0x1236e8 ldr r5, [r4, r1] */
/* @0x1236ec add r0, pc, r0 */
/* @0x1236f0 mov r1, r5 */
/* @0x1236f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1236f8 ldr r0, [pc, #0xcbc] */
/* @0x1236fc mov r1, r5 */
/* @0x123700 mov r2, #1 */
/* @0x123704 add r0, pc, r0 */
/* @0x123708 mov r3, #0 */
/* @0x12370c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123710 ldr r1, [pc, #0xca8] */
/* @0x123714 ldr r0, [pc, #0xca8] */
/* @0x123718 mov r2, #0 */
/* @0x12371c mov r3, r2 */
/* @0x123720 ldr r5, [r4, r1] */
/* @0x123724 add r0, pc, r0 */
/* @0x123728 mov r1, r5 */
/* @0x12372c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123730 ldr r0, [pc, #0xc90] */
/* @0x123734 mov r2, #0 */
/* @0x123738 mov r1, r5 */
/* @0x12373c mov r3, r2 */
/* @0x123740 add r0, pc, r0 */
/* @0x123744 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123748 ldr r1, [pc, #0xc7c] */
/* @0x12374c ldr r0, [pc, #0xc7c] */
/* @0x123750 mov r2, #1 */
/* @0x123754 mov r3, #0 */
/* @0x123758 ldr r1, [r4, r1] */
/* @0x12375c add r0, pc, r0 */
/* @0x123760 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123764 ldr r1, [pc, #0xc68] */
/* @0x123768 ldr r0, [pc, #0xc68] */
/* @0x12376c mov r2, #1 */
/* @0x123770 mov r3, #0 */
/* @0x123774 ldr r1, [r4, r1] */
/* @0x123778 add r0, pc, r0 */
/* @0x12377c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123780 ldr r1, [pc, #0xc54] */
/* @0x123784 ldr r0, [pc, #0xc54] */
/* @0x123788 mov r2, #1 */
/* @0x12378c mov r3, #0 */
/* @0x123790 ldr r1, [r4, r1] */
/* @0x123794 add r0, pc, r0 */
/* @0x123798 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12379c ldr r1, [pc, #0xc40] */
/* @0x1237a0 ldr r0, [pc, #0xc40] */
/* @0x1237a4 mov r2, #1 */
/* @0x1237a8 mov r3, #0 */
/* @0x1237ac ldr r1, [r4, r1] */
/* @0x1237b0 add r0, pc, r0 */
/* @0x1237b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1237b8 ldr r1, [pc, #0xc2c] */
/* @0x1237bc ldr r0, [pc, #0xc2c] */
/* @0x1237c0 mov r2, #2 */
/* @0x1237c4 mov r3, #0 */
/* @0x1237c8 ldr r1, [r4, r1] */
/* @0x1237cc add r0, pc, r0 */
/* @0x1237d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1237d4 ldr r1, [pc, #0xc18] */
/* @0x1237d8 ldr r0, [pc, #0xc18] */
/* @0x1237dc mov r2, #2 */
/* @0x1237e0 mov r3, #0 */
/* @0x1237e4 ldr r1, [r4, r1] */
/* @0x1237e8 add r0, pc, r0 */
/* @0x1237ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1237f0 ldr r1, [pc, #0xc04] */
/* @0x1237f4 ldr r0, [pc, #0xc04] */
/* @0x1237f8 mov r2, #4 */
/* @0x1237fc mov r3, #0 */
/* @0x123800 ldr r1, [r4, r1] */
/* @0x123804 add r0, pc, r0 */
/* @0x123808 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12380c ldr r1, [pc, #0xbf0] */
/* @0x123810 ldr r0, [pc, #0xbf0] */
/* @0x123814 mov r2, #0 */
/* @0x123818 mov r3, r2 */
/* @0x12381c ldr r1, [r4, r1] */
/* @0x123820 add r0, pc, r0 */
/* @0x123824 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123828 ldr r1, [pc, #0xbdc] */
/* @0x12382c ldr r0, [pc, #0xbdc] */
/* @0x123830 mov r2, #0 */
/* @0x123834 mov r3, r2 */
/* @0x123838 ldr r1, [r4, r1] */
/* @0x12383c add r0, pc, r0 */
/* @0x123840 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123844 ldr r1, [pc, #0xbc8] */
/* @0x123848 ldr r0, [pc, #0xbc8] */
/* @0x12384c mov r2, #0 */
/* @0x123850 mov r3, r2 */
/* @0x123854 ldr r1, [r4, r1] */
/* @0x123858 add r0, pc, r0 */
/* @0x12385c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123860 ldr r1, [pc, #0xbb4] */
/* @0x123864 ldr r0, [pc, #0xbb4] */
/* @0x123868 mov r2, #0 */
/* @0x12386c mov r3, r2 */
/* @0x123870 ldr r1, [r4, r1] */
/* @0x123874 add r0, pc, r0 */
/* @0x123878 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12387c ldr r1, [pc, #0xba0] */
/* @0x123880 ldr r0, [pc, #0xba0] */
/* @0x123884 mov r2, #0 */
/* @0x123888 mov r3, r2 */
/* @0x12388c ldr r1, [r4, r1] */
/* @0x123890 add r0, pc, r0 */
/* @0x123894 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123898 ldr r1, [pc, #0xb8c] */
/* @0x12389c ldr r0, [pc, #0xb8c] */
/* @0x1238a0 mov r2, #0 */
/* @0x1238a4 mov r3, r2 */
/* @0x1238a8 ldr r1, [r4, r1] */
/* @0x1238ac add r0, pc, r0 */
/* @0x1238b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1238b4 ldr r1, [pc, #0xb78] */
/* @0x1238b8 ldr r0, [pc, #0xb78] */
/* @0x1238bc mov r2, #4 */
/* @0x1238c0 mov r3, #0 */
/* @0x1238c4 ldr r1, [r4, r1] */
/* @0x1238c8 add r0, pc, r0 */
/* @0x1238cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1238d0 ldr r1, [pc, #0xb64] */
/* @0x1238d4 ldr r0, [pc, #0xb64] */
/* @0x1238d8 mov r2, #0 */
/* @0x1238dc mov r3, r2 */
/* @0x1238e0 ldr r1, [r4, r1] */
/* @0x1238e4 add r0, pc, r0 */
/* @0x1238e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1238ec ldr r1, [pc, #0xb50] */
/* @0x1238f0 ldr r0, [pc, #0xb50] */
/* @0x1238f4 mov r2, #0 */
/* @0x1238f8 mov r3, r2 */
/* @0x1238fc ldr r1, [r4, r1] */
/* @0x123900 add r0, pc, r0 */
/* @0x123904 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123908 ldr r1, [pc, #0xb3c] */
/* @0x12390c ldr r0, [pc, #0xb3c] */
/* @0x123910 mov r2, #2 */
/* @0x123914 mov r3, #0 */
/* @0x123918 ldr r1, [r4, r1] */
/* @0x12391c add r0, pc, r0 */
/* @0x123920 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123924 ldr r1, [pc, #0xb28] */
/* @0x123928 ldr r0, [pc, #0xb28] */
/* @0x12392c mov r2, #1 */
/* @0x123930 mov r3, #0 */
/* @0x123934 ldr r1, [r4, r1] */
/* @0x123938 add r0, pc, r0 */
/* @0x12393c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123940 ldr r1, [pc, #0xb14] */
/* @0x123944 ldr r0, [pc, #0xb14] */
/* @0x123948 mov r2, #1 */
/* @0x12394c mov r3, #0 */
/* @0x123950 ldr r1, [r4, r1] */
/* @0x123954 add r0, pc, r0 */
/* @0x123958 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12395c ldr r1, [pc, #0xb00] */
/* @0x123960 ldr r0, [pc, #0xb00] */
/* @0x123964 mov r2, #3 */
/* @0x123968 mov r3, #0 */
/* @0x12396c ldr r1, [r4, r1] */
/* @0x123970 add r0, pc, r0 */
/* @0x123974 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123978 ldr r1, [pc, #0xaec] */
/* @0x12397c ldr r0, [pc, #0xaec] */
/* @0x123980 mov r2, #0 */
/* @0x123984 mov r3, r2 */
/* @0x123988 ldr r1, [r4, r1] */
/* @0x12398c add r0, pc, r0 */
/* @0x123990 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123994 ldr r1, [pc, #0xad8] */
/* @0x123998 ldr r0, [pc, #0xad8] */
/* @0x12399c mov r2, #0 */
/* @0x1239a0 mov r3, r2 */
/* @0x1239a4 ldr r1, [r4, r1] */
/* @0x1239a8 add r0, pc, r0 */
/* @0x1239ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1239b0 ldr r1, [pc, #0xac4] */
/* @0x1239b4 ldr r0, [pc, #0xac4] */
/* @0x1239b8 mov r2, #2 */
/* @0x1239bc mov r3, #0 */
/* @0x1239c0 ldr r1, [r4, r1] */
/* @0x1239c4 add r0, pc, r0 */
/* @0x1239c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1239cc ldr r1, [pc, #0xab0] */
/* @0x1239d0 ldr r0, [pc, #0xab0] */
/* @0x1239d4 mov r2, #1 */
/* @0x1239d8 mov r3, #0 */
/* @0x1239dc ldr r1, [r4, r1] */
/* @0x1239e0 add r0, pc, r0 */
/* @0x1239e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1239e8 ldr r1, [pc, #0xa9c] */
/* @0x1239ec ldr r0, [pc, #0xa9c] */
/* @0x1239f0 mov r2, #5 */
/* @0x1239f4 mov r3, #0 */
/* @0x1239f8 ldr r1, [r4, r1] */
/* @0x1239fc add r0, pc, r0 */
/* @0x123a00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123a04 ldr r1, [pc, #0xa88] */
/* @0x123a08 ldr r0, [pc, #0xa88] */
/* @0x123a0c mov r2, #2 */
/* @0x123a10 mov r3, #0 */
/* @0x123a14 ldr r1, [r4, r1] */
/* @0x123a18 add r0, pc, r0 */
/* @0x123a1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123a20 ldr r1, [pc, #0xa74] */
/* @0x123a24 ldr r0, [pc, #0xa74] */
/* @0x123a28 mov r2, #2 */
/* @0x123a2c mov r3, #0 */
/* @0x123a30 ldr r1, [r4, r1] */
/* @0x123a34 add r0, pc, r0 */
/* @0x123a38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123a3c ldr r1, [pc, #0xa60] */
/* @0x123a40 ldr r0, [pc, #0xa60] */
/* @0x123a44 mov r2, #1 */
/* @0x123a48 mov r3, #0 */
/* @0x123a4c ldr r5, [r4, r1] */
/* @0x123a50 add r0, pc, r0 */
/* @0x123a54 mov r1, r5 */
/* @0x123a58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123a5c ldr r0, [pc, #0xa48] */
/* @0x123a60 mov r1, r5 */
/* @0x123a64 mov r2, #1 */
/* @0x123a68 add r0, pc, r0 */
/* @0x123a6c mov r3, #0 */
/* @0x123a70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123a74 ldr r1, [pc, #0xa34] */
/* @0x123a78 ldr r0, [pc, #0xa34] */
/* @0x123a7c mov r2, #1 */
/* @0x123a80 mov r3, #0 */
/* @0x123a84 ldr r1, [r4, r1] */
/* @0x123a88 add r0, pc, r0 */
/* @0x123a8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123a90 ldr r1, [pc, #0xa20] */
/* @0x123a94 ldr r0, [pc, #0xa20] */
/* @0x123a98 mov r2, #0 */
/* @0x123a9c mov r3, r2 */
/* @0x123aa0 ldr r5, [r4, r1] */
/* @0x123aa4 add r0, pc, r0 */
/* @0x123aa8 mov r1, r5 */
/* @0x123aac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123ab0 ldr r0, [pc, #0xa08] */
/* @0x123ab4 mov r2, #0 */
/* @0x123ab8 mov r1, r5 */
/* @0x123abc mov r3, r2 */
/* @0x123ac0 add r0, pc, r0 */
/* @0x123ac4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123ac8 ldr r1, [pc, #0x9f4] */
/* @0x123acc ldr r0, [pc, #0x9f4] */
/* @0x123ad0 mov r2, #0 */
/* @0x123ad4 mov r3, r2 */
/* @0x123ad8 ldr r1, [r4, r1] */
/* @0x123adc add r0, pc, r0 */
/* @0x123ae0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123ae4 ldr r1, [pc, #0x9e0] */
/* @0x123ae8 ldr r0, [pc, #0x9e0] */
/* @0x123aec mov r2, #3 */
/* @0x123af0 mov r3, #0 */
/* @0x123af4 ldr r5, [r4, r1] */
/* @0x123af8 add r0, pc, r0 */
/* @0x123afc mov r1, r5 */
/* @0x123b00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123b04 ldr r0, [pc, #0x9c8] */
/* @0x123b08 mov r1, r5 */
/* @0x123b0c mov r2, #3 */
/* @0x123b10 add r0, pc, r0 */
/* @0x123b14 mov r3, #0 */
/* @0x123b18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123b1c ldr r0, [pc, #0x9b4] */
/* @0x123b20 mov r1, r5 */
/* @0x123b24 mov r2, #3 */
/* @0x123b28 add r0, pc, r0 */
/* @0x123b2c mov r3, #0 */
/* @0x123b30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123b34 ldr r0, [pc, #0x9a0] */
/* @0x123b38 mov r1, r5 */
/* @0x123b3c mov r2, #3 */
/* @0x123b40 add r0, pc, r0 */
/* @0x123b44 mov r3, #0 */
/* @0x123b48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123b4c ldr r1, [pc, #0x98c] */
/* @0x123b50 ldr r0, [pc, #0x98c] */
/* @0x123b54 mov r2, #3 */
/* @0x123b58 mov r3, #0 */
/* @0x123b5c ldr r5, [r4, r1] */
/* @0x123b60 add r0, pc, r0 */
/* @0x123b64 mov r1, r5 */
/* @0x123b68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123b6c ldr r0, [pc, #0x974] */
/* @0x123b70 mov r1, r5 */
/* @0x123b74 mov r2, #3 */
/* @0x123b78 add r0, pc, r0 */
/* @0x123b7c mov r3, #0 */
/* @0x123b80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123b84 ldr r1, [pc, #0x960] */
/* @0x123b88 ldr r0, [pc, #0x960] */
/* @0x123b8c mov r2, #1 */
/* @0x123b90 mov r3, #0 */
/* @0x123b94 ldr r5, [r4, r1] */
/* @0x123b98 add r0, pc, r0 */
/* @0x123b9c mov r1, r5 */
/* @0x123ba0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123ba4 ldr r0, [pc, #0x948] */
/* @0x123ba8 mov r1, r5 */
/* @0x123bac mov r2, #1 */
/* @0x123bb0 add r0, pc, r0 */
/* @0x123bb4 mov r3, #0 */
/* @0x123bb8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123bbc ldr r1, [pc, #0x934] */
/* @0x123bc0 ldr r0, [pc, #0x934] */
/* @0x123bc4 mov r2, #1 */
/* @0x123bc8 mov r3, #0 */
/* @0x123bcc ldr r5, [r4, r1] */
/* @0x123bd0 add r0, pc, r0 */
/* @0x123bd4 mov r1, r5 */
/* @0x123bd8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123bdc ldr r0, [pc, #0x91c] */
/* @0x123be0 mov r1, r5 */
/* @0x123be4 mov r2, #1 */
/* @0x123be8 add r0, pc, r0 */
/* @0x123bec mov r3, #0 */
/* @0x123bf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123bf4 ldr r1, [pc, #0x908] */
/* @0x123bf8 ldr r0, [pc, #0x908] */
/* @0x123bfc mov r2, #1 */
/* @0x123c00 mov r3, #0 */
/* @0x123c04 ldr r5, [r4, r1] */
/* @0x123c08 add r0, pc, r0 */
/* @0x123c0c mov r1, r5 */
/* @0x123c10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123c14 ldr r0, [pc, #0x8f0] */
/* @0x123c18 mov r1, r5 */
/* @0x123c1c mov r2, #1 */
/* @0x123c20 add r0, pc, r0 */
/* @0x123c24 mov r3, #0 */
/* @0x123c28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123c2c ldr r1, [pc, #0x8dc] */
/* @0x123c30 ldr r0, [pc, #0x8dc] */
/* @0x123c34 mov r2, #1 */
/* @0x123c38 mov r3, #0 */
/* @0x123c3c ldr r5, [r4, r1] */
/* @0x123c40 add r0, pc, r0 */
/* @0x123c44 mov r1, r5 */
/* @0x123c48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123c4c ldr r0, [pc, #0x8c4] */
/* @0x123c50 mov r1, r5 */
/* @0x123c54 mov r2, #1 */
/* @0x123c58 add r0, pc, r0 */
/* @0x123c5c mov r3, #0 */
/* @0x123c60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123c64 ldr r1, [pc, #0x8b0] */
/* @0x123c68 ldr r0, [pc, #0x8b0] */
/* @0x123c6c mov r2, #1 */
/* @0x123c70 mov r3, #0 */
/* @0x123c74 ldr r5, [r4, r1] */
/* @0x123c78 add r0, pc, r0 */
/* @0x123c7c mov r1, r5 */
/* @0x123c80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123c84 ldr r0, [pc, #0x898] */
/* @0x123c88 mov r1, r5 */
/* @0x123c8c mov r2, #1 */
/* @0x123c90 add r0, pc, r0 */
/* @0x123c94 mov r3, #0 */
/* @0x123c98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123c9c ldr r1, [pc, #0x884] */
/* @0x123ca0 ldr r0, [pc, #0x884] */
/* @0x123ca4 mov r2, #1 */
/* @0x123ca8 mov r3, #0 */
/* @0x123cac ldr r5, [r4, r1] */
/* @0x123cb0 add r0, pc, r0 */
/* @0x123cb4 mov r1, r5 */
/* @0x123cb8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123cbc ldr r0, [pc, #0x86c] */
/* @0x123cc0 mov r1, r5 */
/* @0x123cc4 mov r2, #1 */
/* @0x123cc8 add r0, pc, r0 */
/* @0x123ccc mov r3, #0 */
/* @0x123cd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123cd4 ldr r1, [pc, #0x858] */
/* @0x123cd8 ldr r0, [pc, #0x858] */
/* @0x123cdc mov r2, #3 */
/* @0x123ce0 mov r3, #0 */
/* @0x123ce4 ldr r5, [r4, r1] */
/* @0x123ce8 add r0, pc, r0 */
/* @0x123cec mov r1, r5 */
/* @0x123cf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123cf4 ldr r0, [pc, #0x840] */
/* @0x123cf8 mov r1, r5 */
/* @0x123cfc mov r2, #3 */
/* @0x123d00 add r0, pc, r0 */
/* @0x123d04 mov r3, #0 */
/* @0x123d08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123d0c ldr r1, [pc, #0x82c] */
/* @0x123d10 ldr r0, [pc, #0x82c] */
/* @0x123d14 mov r2, #1 */
/* @0x123d18 mov r3, r2 */
/* @0x123d1c ldr r1, [r4, r1] */
/* @0x123d20 add r0, pc, r0 */
/* @0x123d24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123d28 ldr r1, [pc, #0x818] */
/* @0x123d2c ldr r0, [pc, #0x818] */
/* @0x123d30 mov r2, #2 */
/* @0x123d34 mov r3, #1 */
/* @0x123d38 ldr r1, [r4, r1] */
/* @0x123d3c add r0, pc, r0 */
/* @0x123d40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123d44 ldr r1, [pc, #0x804] */
/* @0x123d48 ldr r0, [pc, #0x804] */
/* @0x123d4c mov r2, #4 */
/* @0x123d50 mov r3, #1 */
/* @0x123d54 ldr r5, [r4, r1] */
/* @0x123d58 add r0, pc, r0 */
/* @0x123d5c mov r1, r5 */
/* @0x123d60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123d64 ldr r0, [pc, #0x7ec] */
/* @0x123d68 mov r1, r5 */
/* @0x123d6c mov r2, #4 */
/* @0x123d70 add r0, pc, r0 */
/* @0x123d74 mov r3, #1 */
/* @0x123d78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123d7c ldr r1, [pc, #0x7d8] */
/* @0x123d80 ldr r0, [pc, #0x7d8] */
/* @0x123d84 mov r2, #1 */
/* @0x123d88 mov r3, #0 */
/* @0x123d8c ldr r1, [r4, r1] */
/* @0x123d90 add r0, pc, r0 */
/* @0x123d94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123d98 ldr r1, [pc, #0x7c4] */
/* @0x123d9c ldr r0, [pc, #0x7c4] */
/* @0x123da0 mov r2, #1 */
/* @0x123da4 mov r3, #0 */
/* @0x123da8 ldr r1, [r4, r1] */
/* @0x123dac add r0, pc, r0 */
/* @0x123db0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123db4 ldr r1, [pc, #0x7b0] */
/* @0x123db8 ldr r0, [pc, #0x7b0] */
/* @0x123dbc mov r2, #0 */
/* @0x123dc0 mov r3, r2 */
/* @0x123dc4 ldr r1, [r4, r1] */
/* @0x123dc8 add r0, pc, r0 */
/* @0x123dcc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123dd0 ldr r1, [pc, #0x79c] */
/* @0x123dd4 ldr r0, [pc, #0x79c] */
/* @0x123dd8 mov r2, #0 */
/* @0x123ddc mov r3, r2 */
/* @0x123de0 ldr r1, [r4, r1] */
/* @0x123de4 add r0, pc, r0 */
/* @0x123de8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123dec ldr r1, [pc, #0x788] */
/* @0x123df0 ldr r0, [pc, #0x788] */
/* @0x123df4 mov r2, #1 */
/* @0x123df8 mov r3, #0 */
/* @0x123dfc ldr r1, [r4, r1] */
/* @0x123e00 add r0, pc, r0 */
/* @0x123e04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123e08 ldr r1, [pc, #0x774] */
/* @0x123e0c ldr r0, [pc, #0x774] */
/* @0x123e10 mov r2, #2 */
/* @0x123e14 mov r3, #0 */
/* @0x123e18 ldr r1, [r4, r1] */
/* @0x123e1c add r0, pc, r0 */
/* @0x123e20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123e24 ldr r1, [pc, #0x760] */
/* @0x123e28 ldr r0, [pc, #0x760] */
/* @0x123e2c mov r2, #2 */
/* @0x123e30 mov r3, #0 */
/* @0x123e34 ldr r1, [r4, r1] */
/* @0x123e38 add r0, pc, r0 */
/* @0x123e3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123e40 ldr r1, [pc, #0x74c] */
/* @0x123e44 ldr r0, [pc, #0x74c] */
/* @0x123e48 mov r2, #4 */
/* @0x123e4c mov r3, #0 */
/* @0x123e50 ldr r1, [r4, r1] */
/* @0x123e54 add r0, pc, r0 */
/* @0x123e58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123e5c ldr r1, [pc, #0x738] */
/* @0x123e60 ldr r0, [pc, #0x738] */
/* @0x123e64 mov r2, #5 */
/* @0x123e68 mov r3, #0 */
/* @0x123e6c ldr r1, [r4, r1] */
/* @0x123e70 add r0, pc, r0 */
/* @0x123e74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123e78 ldr r1, [pc, #0x724] */
/* @0x123e7c ldr r0, [pc, #0x724] */
/* @0x123e80 mov r2, #5 */
/* @0x123e84 mov r3, #0 */
/* @0x123e88 ldr r1, [r4, r1] */
/* @0x123e8c add r0, pc, r0 */
/* @0x123e90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123e94 ldr r1, [pc, #0x710] */
/* @0x123e98 ldr r0, [pc, #0x710] */
/* @0x123e9c mov r2, #5 */
/* @0x123ea0 mov r3, #0 */
/* @0x123ea4 ldr r1, [r4, r1] */
/* @0x123ea8 add r0, pc, r0 */
/* @0x123eac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123eb0 ldr r1, [pc, #0x6fc] */
/* @0x123eb4 ldr r0, [pc, #0x6fc] */
/* @0x123eb8 mov r2, #5 */
/* @0x123ebc mov r3, #0 */
/* @0x123ec0 ldr r1, [r4, r1] */
/* @0x123ec4 add r0, pc, r0 */
/* @0x123ec8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123ecc ldr r1, [pc, #0x6e8] */
/* @0x123ed0 ldr r0, [pc, #0x6e8] */
/* @0x123ed4 mov r2, #7 */
/* @0x123ed8 mov r3, #0 */
/* @0x123edc ldr r1, [r4, r1] */
/* @0x123ee0 add r0, pc, r0 */
/* @0x123ee4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123ee8 ldr r1, [pc, #0x6d4] */
/* @0x123eec ldr r0, [pc, #0x6d4] */
/* @0x123ef0 mov r2, #4 */
/* @0x123ef4 mov r3, #0 */
/* @0x123ef8 ldr r1, [r4, r1] */
/* @0x123efc add r0, pc, r0 */
/* @0x123f00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123f04 ldr r1, [pc, #0x6c0] */
/* @0x123f08 ldr r0, [pc, #0x6c0] */
/* @0x123f0c mov r2, #5 */
/* @0x123f10 mov r3, #0 */
/* @0x123f14 ldr r1, [r4, r1] */
/* @0x123f18 add r0, pc, r0 */
/* @0x123f1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123f20 ldr r1, [pc, #0x6ac] */
/* @0x123f24 ldr r0, [pc, #0x6ac] */
/* @0x123f28 mov r2, #5 */
/* @0x123f2c mov r3, #0 */
/* @0x123f30 ldr r1, [r4, r1] */
/* @0x123f34 add r0, pc, r0 */
/* @0x123f38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123f3c ldr r1, [pc, #0x698] */
/* @0x123f40 ldr r0, [pc, #0x698] */
/* @0x123f44 mov r2, #5 */
/* @0x123f48 mov r3, #0 */
/* @0x123f4c ldr r1, [r4, r1] */
/* @0x123f50 add r0, pc, r0 */
/* @0x123f54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123f58 ldr r1, [pc, #0x684] */
/* @0x123f5c ldr r0, [pc, #0x684] */
/* @0x123f60 mov r2, #11 */
/* @0x123f64 mov r3, #0 */
/* @0x123f68 ldr r1, [r4, r1] */
/* @0x123f6c add r0, pc, r0 */
/* @0x123f70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123f74 ldr r1, [pc, #0x670] */
/* @0x123f78 ldr r0, [pc, #0x670] */
/* @0x123f7c mov r2, #4 */
/* @0x123f80 mov r3, #0 */
/* @0x123f84 ldr r1, [r4, r1] */
/* @0x123f88 add r0, pc, r0 */
/* @0x123f8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123f90 ldr r1, [pc, #0x65c] */
/* @0x123f94 ldr r0, [pc, #0x65c] */
/* @0x123f98 mov r2, #3 */
/* @0x123f9c mov r3, #1 */
/* @0x123fa0 ldr r5, [r4, r1] */
/* @0x123fa4 add r0, pc, r0 */
/* @0x123fa8 mov r1, r5 */
/* @0x123fac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123fb0 ldr r0, [pc, #0x644] */
/* @0x123fb4 mov r1, r5 */
/* @0x123fb8 mov r2, #3 */
/* @0x123fbc add r0, pc, r0 */
/* @0x123fc0 mov r3, #1 */
/* @0x123fc4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123fc8 ldr r1, [pc, #0x630] */
/* @0x123fcc ldr r0, [pc, #0x630] */
/* @0x123fd0 mov r2, #6 */
/* @0x123fd4 mov r3, #1 */
/* @0x123fd8 ldr r5, [r4, r1] */
/* @0x123fdc add r0, pc, r0 */
/* @0x123fe0 mov r1, r5 */
/* @0x123fe4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x123fe8 ldr r0, [pc, #0x618] */
/* @0x123fec mov r1, r5 */
/* @0x123ff0 mov r2, #6 */
/* @0x123ff4 add r0, pc, r0 */
/* @0x123ff8 mov r3, #1 */
/* @0x123ffc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124000 ldr r1, [pc, #0x604] */
/* @0x124004 ldr r0, [pc, #0x604] */
/* @0x124008 mov r2, #7 */
/* @0x12400c mov r3, #1 */
/* @0x124010 ldr r5, [r4, r1] */
/* @0x124014 add r0, pc, r0 */
/* @0x124018 mov r1, r5 */
/* @0x12401c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124020 ldr r0, [pc, #0x5ec] */
/* @0x124024 mov r1, r5 */
/* @0x124028 mov r2, #7 */
/* @0x12402c add r0, pc, r0 */
/* @0x124030 mov r3, #1 */
/* @0x124034 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124038 ldr r1, [pc, #0x5d8] */
/* @0x12403c ldr r0, [pc, #0x5d8] */
/* @0x124040 mov r2, #9 */
/* @0x124044 mov r3, #1 */
/* @0x124048 ldr r5, [r4, r1] */
/* @0x12404c add r0, pc, r0 */
/* @0x124050 mov r1, r5 */
/* @0x124054 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124058 ldr r0, [pc, #0x5c0] */
/* @0x12405c mov r1, r5 */
/* @0x124060 mov r2, #9 */
/* @0x124064 add r0, pc, r0 */
/* @0x124068 mov r3, #1 */
/* @0x12406c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124070 ldr r1, [pc, #0x5ac] */
/* @0x124074 ldr r0, [pc, #0x5ac] */
/* @0x124078 mov r2, #7 */
/* @0x12407c mov r3, #1 */
/* @0x124080 ldr r5, [r4, r1] */
/* @0x124084 add r0, pc, r0 */
/* @0x124088 mov r1, r5 */
/* @0x12408c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124090 ldr r0, [pc, #0x594] */
/* @0x124094 mov r1, r5 */
/* @0x124098 mov r2, #7 */
/* @0x12409c add r0, pc, r0 */
/* @0x1240a0 mov r3, #1 */
/* @0x1240a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1240a8 ldr r1, [pc, #0x580] */
/* @0x1240ac ldr r0, [pc, #0x580] */
/* @0x1240b0 mov r2, #7 */
/* @0x1240b4 mov r3, #1 */
/* @0x1240b8 ldr r5, [r4, r1] */
/* @0x1240bc add r0, pc, r0 */
/* @0x1240c0 mov r1, r5 */
/* @0x1240c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1240c8 ldr r0, [pc, #0x568] */
/* @0x1240cc mov r1, r5 */
/* @0x1240d0 mov r2, #7 */
/* @0x1240d4 add r0, pc, r0 */
/* @0x1240d8 mov r3, #1 */
/* @0x1240dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1240e0 ldr r1, [pc, #0x554] */
/* @0x1240e4 ldr r0, [pc, #0x554] */
/* @0x1240e8 mov r2, #10 */
/* @0x1240ec mov r3, #1 */
/* @0x1240f0 ldr r5, [r4, r1] */
/* @0x1240f4 add r0, pc, r0 */
/* @0x1240f8 mov r1, r5 */
/* @0x1240fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124100 ldr r0, [pc, #0x53c] */
/* @0x124104 mov r1, r5 */
/* @0x124108 mov r2, #10 */
/* @0x12410c add r0, pc, r0 */
/* @0x124110 mov r3, #1 */
/* @0x124114 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124118 ldr r1, [pc, #0x528] */
/* @0x12411c ldr r0, [pc, #0x528] */
/* @0x124120 mov r2, #6 */
/* @0x124124 mov r3, #1 */
/* @0x124128 ldr r5, [r4, r1] */
/* @0x12412c add r0, pc, r0 */
/* @0x124130 mov r1, r5 */
/* @0x124134 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124138 ldr r0, [pc, #0x510] */
/* @0x12413c mov r1, r5 */
/* @0x124140 mov r2, #6 */
/* @0x124144 add r0, pc, r0 */
/* @0x124148 mov r3, #1 */
/* @0x12414c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124150 ldr r1, [pc, #0x4fc] */
/* @0x124154 ldr r0, [pc, #0x4fc] */
/* @0x124158 mov r2, #7 */
/* @0x12415c mov r3, #1 */
/* @0x124160 ldr r5, [r4, r1] */
/* @0x124164 add r0, pc, r0 */
/* @0x124168 mov r1, r5 */
/* @0x12416c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124170 ldr r0, [pc, #0x4e4] */
/* @0x124174 mov r1, r5 */
/* @0x124178 mov r2, #7 */
/* @0x12417c add r0, pc, r0 */
/* @0x124180 mov r3, #1 */
/* @0x124184 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124188 ldr r1, [pc, #0x4d0] */
/* @0x12418c ldr r0, [pc, #0x4d0] */
/* @0x124190 mov r2, #1 */
/* @0x124194 mov r3, r2 */
/* @0x124198 ldr r1, [r4, r1] */
/* @0x12419c add r0, pc, r0 */
/* @0x1241a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1241a4 ldr r1, [pc, #0x4bc] */
/* @0x1241a8 ldr r0, [pc, #0x4bc] */
/* @0x1241ac mov r2, #1 */
/* @0x1241b0 mov r3, r2 */
/* @0x1241b4 ldr r1, [r4, r1] */
/* @0x1241b8 add r0, pc, r0 */
/* @0x1241bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1241c0 ldr r1, [pc, #0x4a8] */
/* @0x1241c4 ldr r0, [pc, #0x4a8] */
/* @0x1241c8 mov r2, #2 */
/* @0x1241cc mov r3, #1 */
/* @0x1241d0 ldr r1, [r4, r1] */
/* @0x1241d4 add r0, pc, r0 */
/* @0x1241d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1241dc ldr r1, [pc, #0x494] */
/* @0x1241e0 ldr r0, [pc, #0x494] */
/* @0x1241e4 mov r2, #0 */
/* @0x1241e8 mov r3, #1 */
/* @0x1241ec ldr r1, [r4, r1] */
/* @0x1241f0 add r0, pc, r0 */
/* @0x1241f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1241f8 ldr r1, [pc, #0x480] */
/* @0x1241fc ldr r0, [pc, #0x480] */
/* @0x124200 mov r2, #2 */
/* @0x124204 mov r3, #1 */
/* @0x124208 ldr r1, [r4, r1] */
/* @0x12420c add r0, pc, r0 */
/* @0x124210 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124214 ldr r1, [pc, #0x46c] */
/* @0x124218 ldr r0, [pc, #0x46c] */
/* @0x12421c mov r2, #4 */
/* @0x124220 mov r3, #1 */
/* @0x124224 ldr r5, [r4, r1] */
/* @0x124228 add r0, pc, r0 */
/* @0x12422c mov r1, r5 */
/* @0x124230 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124234 ldr r0, [pc, #0x454] */
/* @0x124238 mov r1, r5 */
/* @0x12423c mov r2, #4 */
/* @0x124240 add r0, pc, r0 */
/* @0x124244 mov r3, #1 */
/* @0x124248 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12424c ldr r1, [pc, #0x440] */
/* @0x124250 ldr r0, [pc, #0x440] */
/* @0x124254 mov r2, #4 */
/* @0x124258 mov r3, #1 */
/* @0x12425c ldr r1, [r4, r1] */
/* @0x124260 add r0, pc, r0 */
/* @0x124264 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124268 ldr r1, [pc, #0x42c] */
/* @0x12426c b 0x124b14 <_Z20InitGraphicFunctionsv+0x18a8> */
/* @0x124270 .word 0x002ce9d0 */
/* @0x124274 .word 0xffffc998 */
/* @0x124278 eoreq r7, r1, r8, asr r3 */
/* @0x12427c .word 0xffffc99c */
/* @0x124280 eoreq r7, r1, r0, asr r3 */
/* @0x124284 .word 0xffffc9a0 */
/* @0x124288 eoreq r7, r1, r8, asr #6 */
/* @0x12428c .word 0xffffc9a4 */
/* @0x124290 eoreq r7, r1, r4, asr #6 */
/* @0x124294 .word 0xffffc9a8 */
/* @0x124298 eoreq r7, r1, r0, asr #6 */
/* @0x12429c .word 0xffffc9ac */
/* @0x1242a0 eoreq r7, r1, r12, lsr r3 */
/* @0x1242a4 .word 0xffffc9b0 */
/* @0x1242a8 eoreq r7, r1, r4, lsr r3 */
/* @0x1242ac .word 0xffffc9b4 */
/* @0x1242b0 eoreq r7, r1, r0, lsr r3 */
/* @0x1242b4 .word 0xffffc9b8 */
/* @0x1242b8 eoreq r7, r1, r12, lsr #6 */
/* @0x1242bc .word 0xffffc9bc */
/* @0x1242c0 eoreq r7, r1, r0, lsr #6 */
/* @0x1242c4 .word 0xffffc9c0 */
/* @0x1242c8 eoreq r7, r1, r8, lsl r3 */
/* @0x1242cc .word 0xffffc9c4 */
/* @0x1242d0 eoreq r7, r1, r12, lsl #6 */
/* @0x1242d4 .word 0xffffc9c8 */
/* @0x1242d8 eoreq r7, r1, r4, lsl #6 */
/* @0x1242dc .word 0xffffc9cc */
/* @0x1242e0 .word 0x002172fc */
/* @0x1242e4 .word 0xffffc9d0 */
/* @0x1242e8 .word 0x002172f4 */
/* @0x1242ec .word 0xffffc9d4 */
/* @0x1242f0 .word 0x002172f0 */
/* @0x1242f4 .word 0xffffc9d8 */
/* @0x1242f8 eoreq r7, r1, r0, lsl #6 */
/* @0x1242fc .word 0xffffc9dc */
/* @0x124300 eoreq r7, r1, r8, lsl #6 */
/* @0x124304 .word 0xffffc9e0 */
/* @0x124308 eoreq r7, r1, r8, lsl r3 */
/* @0x12430c .word 0xffffc9e4 */
/* @0x124310 eoreq r7, r1, r0, lsr #6 */
/* @0x124314 .word 0xffffc9e8 */
/* @0x124318 eoreq r7, r1, r0, lsr #6 */
/* @0x12431c .word 0xffffc9ec */
/* @0x124320 eoreq r7, r1, r0, lsr #6 */
/* @0x124324 .word 0xffffc9f0 */
/* @0x124328 eoreq r7, r1, r0, lsr #6 */
/* @0x12432c .word 0xffffc9f4 */
/* @0x124330 eoreq r7, r1, r0, lsr #6 */
/* @0x124334 .word 0xffffc9f8 */
/* @0x124338 eoreq r7, r1, r0, lsr #6 */
/* @0x12433c .word 0xffffc9fc */
/* @0x124340 eoreq r7, r1, r8, lsl r3 */
/* @0x124344 .word 0xffffca00 */
/* @0x124348 eoreq r7, r1, r0, lsl r3 */
/* @0x12434c .word 0xffffca04 */
/* @0x124350 eoreq r7, r1, r12, lsl #6 */
/* @0x124354 .word 0xffffca08 */
/* @0x124358 eoreq r7, r1, r8, lsl #6 */
/* @0x12435c .word 0xffffca0c */
/* @0x124360 eoreq r7, r1, r4, lsl #6 */
/* @0x124364 .word 0xffffca10 */
/* @0x124368 eoreq r7, r1, r0, lsl #6 */
/* @0x12436c .word 0xffffca14 */
/* @0x124370 .word 0x002172fc */
/* @0x124374 .word 0xffffca18 */
/* @0x124378 .word 0x002172f8 */
/* @0x12437c .word 0xffffca1c */
/* @0x124380 .word 0x002172f4 */
/* @0x124384 .word 0xffffca20 */
/* @0x124388 .word 0x002172f0 */
/* @0x12438c .word 0xffffca24 */
/* @0x124390 eoreq r7, r1, r8, ror #5 */
/* @0x124394 .word 0xffffca28 */
/* @0x124398 eoreq r7, r1, r0, ror #5 */
/* @0x12439c .word 0xffffca2c */
/* @0x1243a0 .word 0x002172d8 */
/* @0x1243a4 .word 0xffffca30 */
/* @0x1243a8 .word 0x002172d0 */
/* @0x1243ac .word 0xffffca34 */
/* @0x1243b0 eoreq r7, r1, r8, asr #5 */
/* @0x1243b4 .word 0xffffca38 */
/* @0x1243b8 eoreq r7, r1, r0, asr #5 */
/* @0x1243bc .word 0x002172bc */
/* @0x1243c0 .word 0xffffca3c */
/* @0x1243c4 .word 0x002172b0 */
/* @0x1243c8 eoreq r7, r1, r8, lsr #5 */
/* @0x1243cc .word 0xffffca40 */
/* @0x1243d0 eoreq r7, r1, r0, lsr #5 */
/* @0x1243d4 .word 0xffffca44 */
/* @0x1243d8 mlaeq r1, r12, r2, r7 */
/* @0x1243dc .word 0xffffca48 */
/* @0x1243e0 mlaeq r1, r8, r2, r7 */
/* @0x1243e4 .word 0xffffca4c */
/* @0x1243e8 mlaeq r1, r4, r2, r7 */
/* @0x1243ec .word 0xffffca50 */
/* @0x1243f0 mlaeq r1, r0, r2, r7 */
/* @0x1243f4 .word 0xffffca54 */
/* @0x1243f8 eoreq r7, r1, r8, lsl #5 */
/* @0x1243fc .word 0xffffca58 */
/* @0x124400 eoreq r7, r1, r12, ror r2 */
/* @0x124404 .word 0xffffca5c */
/* @0x124408 eoreq r7, r1, r8, ror r2 */
/* @0x12440c .word 0xffffca60 */
/* @0x124410 eoreq r7, r1, r12, ror #4 */
/* @0x124414 .word 0xffffca64 */
/* @0x124418 eoreq r7, r1, r0, ror #4 */
/* @0x12441c .word 0xffffca68 */
/* @0x124420 eoreq r7, r1, r4, asr r2 */
/* @0x124424 .word 0xffffca6c */
/* @0x124428 eoreq r7, r1, r8, asr #4 */
/* @0x12442c .word 0xffffca70 */
/* @0x124430 eoreq r7, r1, r0, asr #4 */
/* @0x124434 .word 0xffffca74 */
/* @0x124438 eoreq r7, r1, r8, lsr r2 */
/* @0x12443c .word 0xffffca78 */
/* @0x124440 eoreq r7, r1, r8, lsr r2 */
/* @0x124444 .word 0xffffca7c */
/* @0x124448 eoreq r7, r1, r0, lsr r2 */
/* @0x12444c .word 0xffffca80 */
/* @0x124450 eoreq r7, r1, r8, lsr #4 */
/* @0x124454 .word 0xffffca84 */
/* @0x124458 eoreq r7, r1, r0, lsr #4 */
/* @0x12445c .word 0xffffca88 */
/* @0x124460 eoreq r7, r1, r12, lsl r2 */
/* @0x124464 .word 0xffffca8c */
/* @0x124468 eoreq r7, r1, r8, lsl r2 */
/* @0x12446c .word 0xffffca90 */
/* @0x124470 eoreq r7, r1, r4, lsl r2 */
/* @0x124474 .word 0xffffca94 */
/* @0x124478 eoreq r7, r1, r4, lsl r2 */
/* @0x12447c .word 0xffffca98 */
/* @0x124480 eoreq r7, r1, r4, lsl r2 */
/* @0x124484 .word 0xffffca9c */
/* @0x124488 eoreq r7, r1, r0, lsl r2 */
/* @0x12448c .word 0xffffcaa0 */
/* @0x124490 eoreq r7, r1, r0, lsl #4 */
/* @0x124494 .word 0xffffcaa4 */
/* @0x124498 .word 0x002171f8 */
/* @0x12449c .word 0xffffcaa8 */
/* @0x1244a0 eoreq r7, r1, r12, ror #3 */
/* @0x1244a4 .word 0xffffcaac */
/* @0x1244a8 eoreq r7, r1, r4, ror #3 */
/* @0x1244ac .word 0x002171dc */
/* @0x1244b0 .word 0xffffcab0 */
/* @0x1244b4 eoreq r7, r1, r12, asr #3 */
/* @0x1244b8 .word 0xffffcab4 */
/* @0x1244bc eoreq r7, r1, r0, asr #3 */
/* @0x1244c0 .word 0x002171b4 */
/* @0x1244c4 .word 0xffffcab8 */
/* @0x1244c8 eoreq r7, r1, r8, lsr #3 */
/* @0x1244cc .word 0xffffcabc */
/* @0x1244d0 mlaeq r1, r12, r1, r7 */
/* @0x1244d4 mlaeq r1, r0, r1, r7 */
/* @0x1244d8 eoreq r7, r1, r4, lsl #3 */
/* @0x1244dc eoreq r7, r1, r12, ror r1 */
/* @0x1244e0 .word 0xffffcac0 */
/* @0x1244e4 eoreq r7, r1, r12, ror #2 */
/* @0x1244e8 eoreq r7, r1, r4, ror #2 */
/* @0x1244ec .word 0xffffcac4 */
/* @0x1244f0 eoreq r7, r1, r4, asr r1 */
/* @0x1244f4 eoreq r7, r1, r12, asr #2 */
/* @0x1244f8 .word 0xffffcac8 */
/* @0x1244fc eoreq r7, r1, r12, lsr r1 */
/* @0x124500 eoreq r7, r1, r4, lsr r1 */
/* @0x124504 .word 0xffffcacc */
/* @0x124508 eoreq r7, r1, r8, lsr #2 */
/* @0x12450c eoreq r7, r1, r0, lsr #2 */
/* @0x124510 .word 0xffffcad0 */
/* @0x124514 eoreq r7, r1, r0, lsl r1 */
/* @0x124518 eoreq r7, r1, r8, lsl #2 */
/* @0x12451c .word 0xffffcad4 */
/* @0x124520 .word 0x002170f8 */
/* @0x124524 .word 0x002170f8 */
/* @0x124528 .word 0xffffcad8 */
/* @0x12452c .word 0x002170f0 */
/* @0x124530 eoreq r7, r1, r8, ror #1 */
/* @0x124534 .word 0xffffcadc */
/* @0x124538 .word 0x002170dc */
/* @0x12453c .word 0x002170d0 */
/* @0x124540 .word 0xffffcae0 */
/* @0x124544 eoreq r7, r1, r0, asr #1 */
/* @0x124548 .word 0xffffcae4 */
/* @0x12454c strhteq r7, [r1], -r8 */
/* @0x124550 .word 0xffffcae8 */
/* @0x124554 strhteq r7, [r1], -r4 */
/* @0x124558 strhteq r7, [r1], -r8 */
/* @0x12455c .word 0xffffcaec */
/* @0x124560 strhteq r7, [r1], -r8 */
/* @0x124564 .word 0xffffcaf0 */
/* @0x124568 strhteq r7, [r1], -r0 */
/* @0x12456c .word 0xffffcaf4 */
/* @0x124570 strhteq r7, [r1], -r4 */
/* @0x124574 .word 0xffffcaf8 */
/* @0x124578 eoreq r7, r1, r12, lsr #1 */
/* @0x12457c .word 0xffffcafc */
/* @0x124580 strhteq r7, [r1], -r0 */
/* @0x124584 .word 0xffffcb00 */
/* @0x124588 eoreq r7, r1, r0, lsr #1 */
/* @0x12458c .word 0xffffcb04 */
/* @0x124590 mlaeq r1, r8, r0, r7 */
/* @0x124594 .word 0xffffcb08 */
/* @0x124598 eoreq r7, r1, r8, lsl #1 */
/* @0x12459c .word 0xffffcb0c */
/* @0x1245a0 eoreq r7, r1, r8, ror r0 */
/* @0x1245a4 .word 0xffffcb10 */
/* @0x1245a8 eoreq r7, r1, r12, rrx */
/* @0x1245ac .word 0xffffcb14 */
/* @0x1245b0 eoreq r7, r1, r0, rrx */
/* @0x1245b4 .word 0xffffcb18 */
/* @0x1245b8 eoreq r7, r1, r4, asr r0 */
/* @0x1245bc .word 0xffffcb1c */
/* @0x1245c0 eoreq r7, r1, r12, asr #32 */
/* @0x1245c4 .word 0xffffcb20 */
/* @0x1245c8 eoreq r7, r1, r0, asr #32 */
/* @0x1245cc .word 0xffffcb24 */
/* @0x1245d0 eoreq r7, r1, r0, lsr r0 */
/* @0x1245d4 .word 0xffffcb28 */
/* @0x1245d8 eoreq r7, r1, r4, lsr #32 */
/* @0x1245dc .word 0xffffcb2c */
/* @0x1245e0 eoreq r7, r1, r4, lsl r0 */
/* @0x1245e4 .word 0xffffcb30 */
/* @0x1245e8 eoreq r7, r1, r4 */
/* @0x1245ec .word 0xffffcb34 */
/* @0x1245f0 .word 0x00216ff8 */
/* @0x1245f4 .word 0xffffcb38 */
/* @0x1245f8 eoreq r6, r1, r8, ror #31 */
/* @0x1245fc eoreq r6, r1, r4, ror #31 */
/* @0x124600 .word 0xffffcb3c */
/* @0x124604 .word 0x00216fd8 */
/* @0x124608 .word 0x00216fd0 */
/* @0x12460c .word 0xffffcb40 */
/* @0x124610 eoreq r6, r1, r4, asr #31 */
/* @0x124614 eoreq r6, r1, r4, asr #31 */
/* @0x124618 .word 0xffffcb44 */
/* @0x12461c .word 0x00216fbc */
/* @0x124620 .word 0x00216fbc */
/* @0x124624 .word 0xffffcb48 */
/* @0x124628 .word 0x00216fb4 */
/* @0x12462c .word 0x00216fb4 */
/* @0x124630 .word 0xffffcb4c */
/* @0x124634 eoreq r6, r1, r12, lsr #31 */
/* @0x124638 .word 0x00216fb0 */
/* @0x12463c .word 0xffffcb50 */
/* @0x124640 eoreq r6, r1, r12, lsr #31 */
/* @0x124644 eoreq r6, r1, r8, lsr #31 */
/* @0x124648 .word 0xffffcb54 */
/* @0x12464c eoreq r6, r1, r0, lsr #31 */
/* @0x124650 mlaeq r1, r12, pc, r6 */
/* @0x124654 .word 0xffffcb58 */
/* @0x124658 mlaeq r1, r0, pc, r6 */
/* @0x12465c eoreq r6, r1, r12, lsl #31 */
/* @0x124660 .word 0xffffcb5c */
/* @0x124664 eoreq r6, r1, r0, lsl #31 */
/* @0x124668 .word 0xffffcb60 */
/* @0x12466c eoreq r6, r1, r0, lsl #31 */
/* @0x124670 .word 0xffffcb64 */
/* @0x124674 eoreq r6, r1, r12, ror pc */
/* @0x124678 .word 0xffffcb68 */
/* @0x12467c eoreq r6, r1, r0, lsl #31 */
/* @0x124680 .word 0xffffcb6c */
/* @0x124684 eoreq r6, r1, r8, ror pc */
/* @0x124688 .word 0xffffcb70 */
/* @0x12468c eoreq r6, r1, r8, ror #30 */
/* @0x124690 eoreq r6, r1, r4, ror #30 */
/* @0x124694 .word 0xffffcb74 */
/* @0x124698 eoreq r6, r1, r8, asr pc */
/* @0x12469c .word 0xffffcb78 */
/* @0x1246a0 eoreq r6, r1, r8, lsr #13 */
/* @0x1246a4 eoreq r6, r1, r12, lsr #13 */
/* @0x1246a8 .word 0xffffcb7c */
/* @0x1246ac eoreq r6, r1, r8, lsr #13 */
/* @0x1246b0 .word 0xffffcb80 */
/* @0x1246b4 mlaeq r1, r12, r6, r6 */
/* @0x1246b8 .word 0xffffcb84 */
/* @0x1246bc mlaeq r1, r4, r6, r6 */
/* @0x1246c0 .word 0xffffcb88 */
/* @0x1246c4 eoreq r6, r1, r8, lsl #13 */
/* @0x1246c8 .word 0xffffcb8c */
/* @0x1246cc eoreq r6, r1, r0, lsl #13 */
/* @0x1246d0 .word 0xffffcb90 */
/* @0x1246d4 eoreq r6, r1, r12, ror r6 */
/* @0x1246d8 .word 0xffffcb94 */
/* @0x1246dc eoreq r6, r1, r4, ror r6 */
/* @0x1246e0 .word 0xffffcb98 */
/* @0x1246e4 eoreq r6, r1, r8, ror #12 */
/* @0x1246e8 .word 0xffffcb9c */
/* @0x1246ec eoreq r6, r1, r8, ror #12 */
/* @0x1246f0 .word 0xffffcba0 */
/* @0x1246f4 eoreq r6, r1, r12, ror #12 */
/* @0x1246f8 .word 0xffffcba4 */
/* @0x1246fc eoreq r6, r1, r8, ror #12 */
/* @0x124700 .word 0xffffcba8 */
/* @0x124704 eoreq r6, r1, r0, ror #12 */
/* @0x124708 .word 0xffffcbac */
/* @0x12470c eoreq r6, r1, r12, asr r6 */
/* @0x124710 .word 0xffffcbb0 */
/* @0x124714 eoreq r6, r1, r4, asr r6 */
/* @0x124718 .word 0xffffcbb4 */
/* @0x12471c eoreq r6, r1, r12, asr #12 */
/* @0x124720 .word 0xffffcbb8 */
/* @0x124724 eoreq r6, r1, r0, asr #12 */
/* @0x124728 .word 0xffffcbbc */
/* @0x12472c eoreq r6, r1, r12, lsr r6 */
/* @0x124730 .word 0xffffcbc0 */
/* @0x124734 eoreq r6, r1, r8, lsr r6 */
/* @0x124738 .word 0xffffcbc4 */
/* @0x12473c eoreq r6, r1, r12, lsr #12 */
/* @0x124740 .word 0xffffcbc8 */
/* @0x124744 eoreq r6, r1, r0, lsr #12 */
/* @0x124748 .word 0xffffcbcc */
/* @0x12474c eoreq r6, r1, r4, lsl r6 */
/* @0x124750 .word 0xffffcbd0 */
/* @0x124754 eoreq r6, r1, r8, lsl #12 */
/* @0x124758 .word 0xffffcbd4 */
/* @0x12475c .word 0x002165fc */
/* @0x124760 .word 0xffffcbd8 */
/* @0x124764 .word 0x002165f0 */
/* @0x124768 .word 0xffffcbdc */
/* @0x12476c eoreq r6, r1, r8, ror #11 */
/* @0x124770 .word 0xffffcbe0 */
/* @0x124774 eoreq r6, r1, r0, ror #11 */
/* @0x124778 .word 0xffffcbe4 */
/* @0x12477c .word 0x002165d0 */
/* @0x124780 .word 0xffffcbe8 */
/* @0x124784 eoreq r6, r1, r4, asr #11 */
/* @0x124788 .word 0xffffcbec */
/* @0x12478c eoreq r6, r1, r0, asr #11 */
/* @0x124790 .word 0xffffcbf0 */
/* @0x124794 eoreq r6, r1, r0, asr #11 */
/* @0x124798 .word 0x002165b8 */
/* @0x12479c .word 0xffffcbf4 */
/* @0x1247a0 eoreq r6, r1, r12, lsr #11 */
/* @0x1247a4 .word 0x002165b0 */
/* @0x1247a8 .word 0xffffcbf8 */
/* @0x1247ac .word 0x002165b0 */
/* @0x1247b0 eoreq r6, r1, r12, lsr #11 */
/* @0x1247b4 .word 0xffffcbfc */
/* @0x1247b8 eoreq r6, r1, r4, lsr #11 */
/* @0x1247bc eoreq r6, r1, r12, lsr #11 */
/* @0x1247c0 .word 0xffffcc00 */
/* @0x1247c4 .word 0x002165b0 */
/* @0x1247c8 .word 0xffffcc04 */
/* @0x1247cc eoreq r6, r1, r4, lsr #11 */
/* @0x1247d0 .word 0xffffcc08 */
/* @0x1247d4 mlaeq r1, r4, r5, r6 */
/* @0x1247d8 .word 0xffffcc0c */
/* @0x1247dc eoreq r6, r1, r4, lsl #11 */
/* @0x1247e0 .word 0xffffcc10 */
/* @0x1247e4 eoreq r6, r1, r4, ror r5 */
/* @0x1247e8 .word 0xffffcc14 */
/* @0x1247ec eoreq r6, r1, r12, ror #10 */
/* @0x1247f0 .word 0xffffcc18 */
/* @0x1247f4 eoreq r6, r1, r0, ror #10 */
/* @0x1247f8 .word 0xffffcc1c */
/* @0x1247fc eoreq r6, r1, r4, asr r5 */
/* @0x124800 .word 0xffffcc20 */
/* @0x124804 eoreq r6, r1, r0, asr r5 */
/* @0x124808 .word 0xffffcc24 */
/* @0x12480c eoreq r6, r1, r0, asr r5 */
/* @0x124810 .word 0xffffcc28 */
/* @0x124814 eoreq r6, r1, r8, asr #10 */
/* @0x124818 .word 0xffffcc2c */
/* @0x12481c eoreq r6, r1, r4, asr #10 */
/* @0x124820 .word 0xffffcc30 */
/* @0x124824 eoreq r6, r1, r12, lsr r5 */
/* @0x124828 .word 0xffffcc34 */
/* @0x12482c eoreq r6, r1, r4, lsr r5 */
/* @0x124830 .word 0xffffcc38 */
/* @0x124834 eoreq r6, r1, r0, lsr r5 */
/* @0x124838 .word 0xffffcc3c */
/* @0x12483c eoreq r6, r1, r4, lsr #10 */
/* @0x124840 .word 0xffffcc40 */
/* @0x124844 eoreq r6, r1, r12, lsl r5 */
/* @0x124848 .word 0xffffcc44 */
/* @0x12484c eoreq r6, r1, r12, lsl r5 */
/* @0x124850 .word 0xffffcc48 */
/* @0x124854 eoreq r6, r1, r0, lsr #10 */
/* @0x124858 .word 0xffffcc4c */
/* @0x12485c eoreq r6, r1, r12, lsl r5 */
/* @0x124860 .word 0xffffcc50 */
/* @0x124864 eoreq r6, r1, r12, lsl r5 */
/* @0x124868 .word 0xffffcc54 */
/* @0x12486c eoreq r6, r1, r8, lsl r5 */
/* @0x124870 .word 0xffffcc58 */
/* @0x124874 eoreq r6, r1, r4, lsl r5 */
/* @0x124878 .word 0xffffcc5c */
/* @0x12487c eoreq r6, r1, r4, lsl r5 */
/* @0x124880 .word 0xffffcc60 */
/* @0x124884 eoreq r6, r1, r0, lsl r5 */
/* @0x124888 .word 0xffffcc64 */
/* @0x12488c eoreq r6, r1, r0, lsl #10 */
/* @0x124890 .word 0xffffcc68 */
/* @0x124894 .word 0x002164f0 */
/* @0x124898 .word 0xffffcc6c */
/* @0x12489c eoreq r6, r1, r4, ror #9 */
/* @0x1248a0 .word 0xffffcc70 */
/* @0x1248a4 .word 0x002164d8 */
/* @0x1248a8 .word 0xffffcc74 */
/* @0x1248ac eoreq r6, r1, r12, asr #9 */
/* @0x1248b0 .word 0xffffcc78 */
/* @0x1248b4 eoreq r6, r1, r0, asr #9 */
/* @0x1248b8 .word 0xffffcc7c */
/* @0x1248bc .word 0x002164b4 */
/* @0x1248c0 .word 0xffffcc80 */
/* @0x1248c4 eoreq r6, r1, r12, lsr #9 */
/* @0x1248c8 .word 0xffffcc84 */
/* @0x1248cc eoreq r6, r1, r0, lsr #9 */
/* @0x1248d0 .word 0xffffcc88 */
/* @0x1248d4 mlaeq r1, r4, r4, r6 */
/* @0x1248d8 .word 0xffffcc8c */
/* @0x1248dc eoreq r6, r1, r8, lsl #9 */
/* @0x1248e0 .word 0xffffcc90 */
/* @0x1248e4 eoreq r6, r1, r12, ror r4 */
/* @0x1248e8 .word 0xffffcc94 */
/* @0x1248ec eoreq r6, r1, r4, ror r4 */
/* @0x1248f0 .word 0xffffcc98 */
/* @0x1248f4 eoreq r6, r1, r12, ror #8 */
/* @0x1248f8 .word 0xffffcc9c */
/* @0x1248fc eoreq r6, r1, r4, ror #8 */
/* @0x124900 .word 0xffffcca0 */
/* @0x124904 eoreq r6, r1, r8, asr r4 */
/* @0x124908 .word 0xffffcca4 */
/* @0x12490c eoreq r6, r1, r0, asr r4 */
/* @0x124910 .word 0xffffcca8 */
/* @0x124914 eoreq r6, r1, r4, asr #8 */
/* @0x124918 .word 0xffffccac */
/* @0x12491c eoreq r6, r1, r8, lsr r4 */
/* @0x124920 .word 0xffffccb0 */
/* @0x124924 eoreq r6, r1, r12, lsr #8 */
/* @0x124928 .word 0xffffccb4 */
/* @0x12492c eoreq r6, r1, r0, lsr #8 */
/* @0x124930 .word 0xffffccb8 */
/* @0x124934 eoreq r6, r1, r4, lsl r4 */
/* @0x124938 .word 0xffffccbc */
/* @0x12493c eoreq r6, r1, r4, lsl #8 */
/* @0x124940 .word 0xffffccc0 */
/* @0x124944 .word 0x002163f8 */
/* @0x124948 .word 0xffffccc4 */
/* @0x12494c .word 0x002163f4 */
/* @0x124950 .word 0xffffccc8 */
/* @0x124954 eoreq r6, r1, r4, ror #7 */
/* @0x124958 .word 0xffffcccc */
/* @0x12495c .word 0x002163d4 */
/* @0x124960 .word 0xffffccd0 */
/* @0x124964 eoreq r6, r1, r4, asr #7 */
/* @0x124968 .word 0xffffccd4 */
/* @0x12496c .word 0x002163b8 */
/* @0x124970 .word 0xffffccd8 */
/* @0x124974 eoreq r6, r1, r12, lsr #7 */
/* @0x124978 .word 0xffffccdc */
/* @0x12497c eoreq r6, r1, r4, lsr #7 */
/* @0x124980 .word 0xffffcce0 */
/* @0x124984 mlaeq r1, r12, r3, r6 */
/* @0x124988 .word 0xffffcce4 */
/* @0x12498c mlaeq r1, r0, r3, r6 */
/* @0x124990 .word 0xffffcce8 */
/* @0x124994 eoreq r6, r1, r12, lsl #7 */
/* @0x124998 .word 0xffffccec */
/* @0x12499c eoreq r6, r1, r4, lsl #7 */
/* @0x1249a0 .word 0xffffccf0 */
/* @0x1249a4 eoreq r6, r1, r8, ror r3 */
/* @0x1249a8 .word 0xffffccf4 */
/* @0x1249ac eoreq r6, r1, r0, ror r3 */
/* @0x1249b0 .word 0xffffccf8 */
/* @0x1249b4 eoreq r6, r1, r12, ror #6 */
/* @0x1249b8 .word 0xffffccfc */
/* @0x1249bc eoreq r6, r1, r0, ror #6 */
/* @0x1249c0 .word 0xffffcd00 */
/* @0x1249c4 eoreq r6, r1, r4, asr r3 */
/* @0x1249c8 .word 0xffffcd04 */
/* @0x1249cc eoreq r6, r1, r8, asr #6 */
/* @0x1249d0 .word 0xffffcd08 */
/* @0x1249d4 eoreq r6, r1, r0, asr #6 */
/* @0x1249d8 .word 0xffffcd0c */
/* @0x1249dc eoreq r6, r1, r8, lsr r3 */
/* @0x1249e0 .word 0xffffcd10 */
/* @0x1249e4 eoreq r6, r1, r0, lsr r3 */
/* @0x1249e8 .word 0xffffcd14 */
/* @0x1249ec eoreq r6, r1, r8, lsr #6 */
/* @0x1249f0 .word 0xffffcd18 */
/* @0x1249f4 eoreq r6, r1, r4, lsr #6 */
/* @0x1249f8 .word 0xffffcd1c */
/* @0x1249fc eoreq r6, r1, r0, lsr #6 */
/* @0x124a00 .word 0xffffcd20 */
/* @0x124a04 eoreq r6, r1, r12, lsl r3 */
/* @0x124a08 .word 0xffffcd24 */
/* @0x124a0c eoreq r6, r1, r12, lsl r3 */
/* @0x124a10 .word 0xffffcd28 */
/* @0x124a14 eoreq r6, r1, r0, lsl r3 */
/* @0x124a18 .word 0xffffcd2c */
/* @0x124a1c eoreq r6, r1, r8, lsl #6 */
/* @0x124a20 .word 0xffffcd30 */
/* @0x124a24 eoreq r6, r1, r4, lsl #6 */
/* @0x124a28 .word 0xffffcd34 */
/* @0x124a2c eoreq r6, r1, r4, lsl #6 */
/* @0x124a30 .word 0xffffcd38 */
/* @0x124a34 .word 0x002162fc */
/* @0x124a38 .word 0xffffcd3c */
/* @0x124a3c .word 0x002162f8 */
/* @0x124a40 .word 0xffffcd40 */
/* @0x124a44 .word 0x002162f4 */
/* @0x124a48 .word 0xffffcd44 */
/* @0x124a4c eoreq r6, r1, r12, ror #5 */
/* @0x124a50 .word 0xffffcd48 */
/* @0x124a54 eoreq r6, r1, r8, ror #5 */
/* @0x124a58 .word 0xffffcd4c */
/* @0x124a5c .word 0x002162dc */
/* @0x124a60 .word 0xffffcd50 */
/* @0x124a64 .word 0x002162d4 */
/* @0x124a68 .word 0xffffcd54 */
/* @0x124a6c eoreq r6, r1, r12, asr #5 */
/* @0x124a70 .word 0xffffcd58 */
/* @0x124a74 eoreq r6, r1, r8, asr #5 */
/* @0x124a78 .word 0xffffcd5c */
/* @0x124a7c .word 0x002162bc */
/* @0x124a80 .word 0xffffcd60 */
/* @0x124a84 .word 0x002162b4 */
/* @0x124a88 .word 0xffffcd64 */
/* @0x124a8c .word 0x002162b0 */
/* @0x124a90 .word 0xffffcd68 */
/* @0x124a94 eoreq r6, r1, r8, lsr #5 */
/* @0x124a98 .word 0xffffcd6c */
/* @0x124a9c eoreq r6, r1, r4, lsr #5 */
/* @0x124aa0 eoreq r6, r1, r8, lsr #5 */
/* @0x124aa4 .word 0xffffcd70 */
/* @0x124aa8 eoreq r6, r1, r8, lsr #5 */
/* @0x124aac .word 0xffffcd74 */
/* @0x124ab0 eoreq r6, r1, r12, lsr #5 */
/* @0x124ab4 .word 0xffffcd78 */
/* @0x124ab8 .word 0x002162b0 */
/* @0x124abc .word 0xffffcd7c */
/* @0x124ac0 .word 0x002162b0 */
/* @0x124ac4 .word 0xffffcd80 */
/* @0x124ac8 eoreq r6, r1, r8, lsr #5 */
/* @0x124acc .word 0xffffcd84 */
/* @0x124ad0 eoreq r6, r1, r0, lsr #5 */
/* @0x124ad4 .word 0xffffcd88 */
/* @0x124ad8 mlaeq r1, r12, r2, r6 */
/* @0x124adc .word 0xffffcd8c */
/* @0x124ae0 mlaeq r1, r8, r2, r6 */
/* @0x124ae4 .word 0xffffcd90 */
/* @0x124ae8 mlaeq r1, r8, r2, r6 */
/* @0x124aec .word 0xffffcd94 */
/* @0x124af0 mlaeq r1, r8, r2, r6 */
/* @0x124af4 .word 0xffffcd98 */
/* @0x124af8 mlaeq r1, r4, r2, r6 */
/* @0x124afc .word 0xffffcd9c */
/* @0x124b00 mlaeq r1, r0, r2, r6 */
/* @0x124b04 .word 0xffffcda0 */
/* @0x124b08 eoreq r6, r1, r12, lsl #5 */
/* @0x124b0c .word 0xffffcda4 */
/* @0x124b10 eoreq r6, r1, r8, lsl #5 */
/* @0x124b14 ldr r0, [pc, #-0x47c] */
/* @0x124b18 mov r2, #6 */
/* @0x124b1c mov r3, #1 */
/* @0x124b20 ldr r5, [r4, r1] */
/* @0x124b24 add r0, pc, r0 */
/* @0x124b28 mov r1, r5 */
/* @0x124b2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124b30 ldr r0, [pc, #-0x494] */
/* @0x124b34 mov r1, r5 */
/* @0x124b38 mov r2, #6 */
/* @0x124b3c add r0, pc, r0 */
/* @0x124b40 mov r3, #1 */
/* @0x124b44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124b48 ldr r1, [pc, #-0x4a8] */
/* @0x124b4c ldr r0, [pc, #-0x4a8] */
/* @0x124b50 mov r2, #2 */
/* @0x124b54 mov r3, #1 */
/* @0x124b58 ldr r1, [r4, r1] */
/* @0x124b5c add r0, pc, r0 */
/* @0x124b60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124b64 ldr r1, [pc, #-0x4bc] */
/* @0x124b68 ldr r0, [pc, #-0x4bc] */
/* @0x124b6c mov r2, #2 */
/* @0x124b70 mov r3, #1 */
/* @0x124b74 ldr r1, [r4, r1] */
/* @0x124b78 add r0, pc, r0 */
/* @0x124b7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124b80 ldr r1, [pc, #-0x4d0] */
/* @0x124b84 ldr r0, [pc, #-0x4d0] */
/* @0x124b88 mov r2, #2 */
/* @0x124b8c mov r3, #1 */
/* @0x124b90 ldr r1, [r4, r1] */
/* @0x124b94 add r0, pc, r0 */
/* @0x124b98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124b9c ldr r1, [pc, #-0x4e4] */
/* @0x124ba0 ldr r0, [pc, #-0x4e4] */
/* @0x124ba4 mov r2, #2 */
/* @0x124ba8 mov r3, #1 */
/* @0x124bac ldr r1, [r4, r1] */
/* @0x124bb0 add r0, pc, r0 */
/* @0x124bb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124bb8 ldr r1, [pc, #-0x4f8] */
/* @0x124bbc ldr r0, [pc, #-0x4f8] */
/* @0x124bc0 mov r2, #1 */
/* @0x124bc4 mov r3, r2 */
/* @0x124bc8 ldr r1, [r4, r1] */
/* @0x124bcc add r0, pc, r0 */
/* @0x124bd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124bd4 ldr r1, [pc, #-0x50c] */
/* @0x124bd8 ldr r0, [pc, #-0x50c] */
/* @0x124bdc mov r2, #1 */
/* @0x124be0 mov r3, r2 */
/* @0x124be4 ldr r1, [r4, r1] */
/* @0x124be8 add r0, pc, r0 */
/* @0x124bec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124bf0 ldr r1, [pc, #-0x520] */
/* @0x124bf4 ldr r0, [pc, #-0x520] */
/* @0x124bf8 mov r2, #1 */
/* @0x124bfc mov r3, r2 */
/* @0x124c00 ldr r1, [r4, r1] */
/* @0x124c04 add r0, pc, r0 */
/* @0x124c08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124c0c ldr r1, [pc, #-0x534] */
/* @0x124c10 ldr r0, [pc, #-0x534] */
/* @0x124c14 mov r2, #1 */
/* @0x124c18 mov r3, r2 */
/* @0x124c1c ldr r1, [r4, r1] */
/* @0x124c20 add r0, pc, r0 */
/* @0x124c24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124c28 ldr r1, [pc, #-0x548] */
/* @0x124c2c ldr r0, [pc, #-0x548] */
/* @0x124c30 mov r2, #2 */
/* @0x124c34 mov r3, #1 */
/* @0x124c38 ldr r1, [r4, r1] */
/* @0x124c3c add r0, pc, r0 */
/* @0x124c40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124c44 ldr r1, [pc, #-0x55c] */
/* @0x124c48 ldr r0, [pc, #-0x55c] */
/* @0x124c4c mov r2, #1 */
/* @0x124c50 mov r3, r2 */
/* @0x124c54 ldr r1, [r4, r1] */
/* @0x124c58 add r0, pc, r0 */
/* @0x124c5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124c60 ldr r1, [pc, #-0x570] */
/* @0x124c64 ldr r0, [pc, #-0x570] */
/* @0x124c68 mov r2, #1 */
/* @0x124c6c mov r3, r2 */
/* @0x124c70 ldr r1, [r4, r1] */
/* @0x124c74 add r0, pc, r0 */
/* @0x124c78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124c7c ldr r1, [pc, #-0x584] */
/* @0x124c80 ldr r0, [pc, #-0x584] */
/* @0x124c84 mov r2, #2 */
/* @0x124c88 mov r3, #1 */
/* @0x124c8c ldr r1, [r4, r1] */
/* @0x124c90 add r0, pc, r0 */
/* @0x124c94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124c98 ldr r1, [pc, #-0x598] */
/* @0x124c9c ldr r0, [pc, #-0x598] */
/* @0x124ca0 mov r2, #1 */
/* @0x124ca4 mov r3, r2 */
/* @0x124ca8 ldr r1, [r4, r1] */
/* @0x124cac add r0, pc, r0 */
/* @0x124cb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124cb4 ldr r1, [pc, #-0x5ac] */
/* @0x124cb8 ldr r0, [pc, #-0x5ac] */
/* @0x124cbc mov r2, #1 */
/* @0x124cc0 mov r3, r2 */
/* @0x124cc4 ldr r1, [r4, r1] */
/* @0x124cc8 add r0, pc, r0 */
/* @0x124ccc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124cd0 ldr r1, [pc, #-0x5c0] */
/* @0x124cd4 ldr r0, [pc, #-0x5c0] */
/* @0x124cd8 mov r2, #1 */
/* @0x124cdc mov r3, r2 */
/* @0x124ce0 ldr r1, [r4, r1] */
/* @0x124ce4 add r0, pc, r0 */
/* @0x124ce8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124cec ldr r1, [pc, #-0x5d4] */
/* @0x124cf0 ldr r0, [pc, #-0x5d4] */
/* @0x124cf4 mov r2, #2 */
/* @0x124cf8 mov r3, #1 */
/* @0x124cfc ldr r1, [r4, r1] */
/* @0x124d00 add r0, pc, r0 */
/* @0x124d04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124d08 ldr r1, [pc, #-0x5e8] */
/* @0x124d0c ldr r0, [pc, #-0x5e8] */
/* @0x124d10 mov r2, #1 */
/* @0x124d14 mov r3, r2 */
/* @0x124d18 ldr r1, [r4, r1] */
/* @0x124d1c add r0, pc, r0 */
/* @0x124d20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124d24 ldr r1, [pc, #-0x5fc] */
/* @0x124d28 ldr r0, [pc, #-0x5fc] */
/* @0x124d2c mov r2, #1 */
/* @0x124d30 mov r3, r2 */
/* @0x124d34 ldr r1, [r4, r1] */
/* @0x124d38 add r0, pc, r0 */
/* @0x124d3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124d40 ldr r1, [pc, #-0x610] */
/* @0x124d44 ldr r0, [pc, #-0x610] */
/* @0x124d48 mov r2, #1 */
/* @0x124d4c mov r3, #0 */
/* @0x124d50 ldr r1, [r4, r1] */
/* @0x124d54 add r0, pc, r0 */
/* @0x124d58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124d5c ldr r1, [pc, #-0x624] */
/* @0x124d60 ldr r0, [pc, #-0x624] */
/* @0x124d64 mov r2, #1 */
/* @0x124d68 mov r3, #0 */
/* @0x124d6c ldr r1, [r4, r1] */
/* @0x124d70 add r0, pc, r0 */
/* @0x124d74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124d78 ldr r1, [pc, #-0x638] */
/* @0x124d7c ldr r0, [pc, #-0x638] */
/* @0x124d80 mov r2, #1 */
/* @0x124d84 mov r3, #0 */
/* @0x124d88 ldr r1, [r4, r1] */
/* @0x124d8c add r0, pc, r0 */
/* @0x124d90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124d94 ldr r1, [pc, #-0x64c] */
/* @0x124d98 ldr r0, [pc, #-0x64c] */
/* @0x124d9c mov r2, #1 */
/* @0x124da0 mov r3, #0 */
/* @0x124da4 ldr r1, [r4, r1] */
/* @0x124da8 add r0, pc, r0 */
/* @0x124dac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124db0 ldr r1, [pc, #-0x660] */
/* @0x124db4 ldr r0, [pc, #-0x660] */
/* @0x124db8 mov r2, #1 */
/* @0x124dbc mov r3, #0 */
/* @0x124dc0 ldr r1, [r4, r1] */
/* @0x124dc4 add r0, pc, r0 */
/* @0x124dc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124dcc ldr r1, [pc, #-0x674] */
/* @0x124dd0 ldr r0, [pc, #-0x674] */
/* @0x124dd4 mov r2, #3 */
/* @0x124dd8 mov r3, #0 */
/* @0x124ddc ldr r1, [r4, r1] */
/* @0x124de0 add r0, pc, r0 */
/* @0x124de4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124de8 ldr r1, [pc, #-0x688] */
/* @0x124dec ldr r0, [pc, #-0x688] */
/* @0x124df0 mov r2, #3 */
/* @0x124df4 mov r3, #0 */
/* @0x124df8 ldr r1, [r4, r1] */
/* @0x124dfc add r0, pc, r0 */
/* @0x124e00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124e04 ldr r1, [pc, #-0x69c] */
/* @0x124e08 ldr r0, [pc, #-0x69c] */
/* @0x124e0c mov r2, #3 */
/* @0x124e10 mov r3, #0 */
/* @0x124e14 ldr r1, [r4, r1] */
/* @0x124e18 add r0, pc, r0 */
/* @0x124e1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124e20 ldr r1, [pc, #-0x6b0] */
/* @0x124e24 ldr r0, [pc, #-0x6b0] */
/* @0x124e28 mov r2, #5 */
/* @0x124e2c mov r3, #0 */
/* @0x124e30 ldr r1, [r4, r1] */
/* @0x124e34 add r0, pc, r0 */
/* @0x124e38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124e3c ldr r1, [pc, #-0x6c4] */
/* @0x124e40 ldr r0, [pc, #-0x6c4] */
/* @0x124e44 mov r2, #6 */
/* @0x124e48 mov r3, #1 */
/* @0x124e4c ldr r1, [r4, r1] */
/* @0x124e50 add r0, pc, r0 */
/* @0x124e54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124e58 ldr r1, [pc, #-0x6d8] */
/* @0x124e5c ldr r0, [pc, #-0x6d8] */
/* @0x124e60 mov r2, #8 */
/* @0x124e64 mov r3, #1 */
/* @0x124e68 ldr r1, [r4, r1] */
/* @0x124e6c add r0, pc, r0 */
/* @0x124e70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124e74 ldr r1, [pc, #-0x6ec] */
/* @0x124e78 ldr r0, [pc, #-0x6ec] */
/* @0x124e7c mov r2, #8 */
/* @0x124e80 mov r3, #1 */
/* @0x124e84 ldr r5, [r4, r1] */
/* @0x124e88 add r0, pc, r0 */
/* @0x124e8c mov r1, r5 */
/* @0x124e90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124e94 ldr r0, [pc, #-0x704] */
/* @0x124e98 mov r1, r5 */
/* @0x124e9c mov r2, #8 */
/* @0x124ea0 add r0, pc, r0 */
/* @0x124ea4 mov r3, #1 */
/* @0x124ea8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124eac ldr r1, [pc, #-0x718] */
/* @0x124eb0 ldr r0, [pc, #-0x718] */
/* @0x124eb4 mov r2, #11 */
/* @0x124eb8 mov r3, #1 */
/* @0x124ebc ldr r5, [r4, r1] */
/* @0x124ec0 add r0, pc, r0 */
/* @0x124ec4 mov r1, r5 */
/* @0x124ec8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124ecc ldr r0, [pc, #-0x730] */
/* @0x124ed0 mov r1, r5 */
/* @0x124ed4 mov r2, #11 */
/* @0x124ed8 add r0, pc, r0 */
/* @0x124edc mov r3, #1 */
/* @0x124ee0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124ee4 ldr r1, [pc, #-0x744] */
/* @0x124ee8 ldr r0, [pc, #-0x744] */
/* @0x124eec mov r2, #10 */
/* @0x124ef0 mov r3, #1 */
/* @0x124ef4 ldr r5, [r4, r1] */
/* @0x124ef8 add r0, pc, r0 */
/* @0x124efc mov r1, r5 */
/* @0x124f00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124f04 ldr r0, [pc, #-0x75c] */
/* @0x124f08 mov r1, r5 */
/* @0x124f0c mov r2, #10 */
/* @0x124f10 add r0, pc, r0 */
/* @0x124f14 mov r3, #1 */
/* @0x124f18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124f1c ldr r1, [pc, #-0x770] */
/* @0x124f20 ldr r0, [pc, #-0x770] */
/* @0x124f24 mov r2, #13 */
/* @0x124f28 mov r3, #1 */
/* @0x124f2c ldr r5, [r4, r1] */
/* @0x124f30 add r0, pc, r0 */
/* @0x124f34 mov r1, r5 */
/* @0x124f38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124f3c ldr r0, [pc, #-0x788] */
/* @0x124f40 mov r1, r5 */
/* @0x124f44 mov r2, #13 */
/* @0x124f48 add r0, pc, r0 */
/* @0x124f4c mov r3, #1 */
/* @0x124f50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124f54 ldr r1, [pc, #-0x79c] */
/* @0x124f58 ldr r0, [pc, #-0x79c] */
/* @0x124f5c mov r2, #9 */
/* @0x124f60 mov r3, #1 */
/* @0x124f64 ldr r1, [r4, r1] */
/* @0x124f68 add r0, pc, r0 */
/* @0x124f6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124f70 ldr r1, [pc, #-0x7b0] */
/* @0x124f74 ldr r0, [pc, #-0x7b0] */
/* @0x124f78 mov r2, #0 */
/* @0x124f7c mov r3, r2 */
/* @0x124f80 ldr r1, [r4, r1] */
/* @0x124f84 add r0, pc, r0 */
/* @0x124f88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124f8c ldr r1, [pc, #-0x7c4] */
/* @0x124f90 ldr r0, [pc, #-0x7c4] */
/* @0x124f94 mov r2, #4 */
/* @0x124f98 mov r3, #0 */
/* @0x124f9c ldr r1, [r4, r1] */
/* @0x124fa0 add r0, pc, r0 */
/* @0x124fa4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124fa8 ldr r1, [pc, #-0x7d8] */
/* @0x124fac ldr r0, [pc, #-0x7d8] */
/* @0x124fb0 mov r2, #11 */
/* @0x124fb4 mov r3, #1 */
/* @0x124fb8 ldr r1, [r4, r1] */
/* @0x124fbc add r0, pc, r0 */
/* @0x124fc0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124fc4 ldr r1, [pc, #-0x7ec] */
/* @0x124fc8 ldr r0, [pc, #-0x7ec] */
/* @0x124fcc mov r2, #10 */
/* @0x124fd0 mov r3, #1 */
/* @0x124fd4 ldr r1, [r4, r1] */
/* @0x124fd8 add r0, pc, r0 */
/* @0x124fdc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124fe0 ldr r1, [pc, #-0x800] */
/* @0x124fe4 ldr r0, [pc, #-0x800] */
/* @0x124fe8 mov r2, #9 */
/* @0x124fec mov r3, #1 */
/* @0x124ff0 ldr r1, [r4, r1] */
/* @0x124ff4 add r0, pc, r0 */
/* @0x124ff8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x124ffc ldr r1, [pc, #-0x814] */
/* @0x125000 ldr r0, [pc, #-0x814] */
/* @0x125004 mov r2, #11 */
/* @0x125008 mov r3, #0 */
/* @0x12500c ldr r1, [r4, r1] */
/* @0x125010 add r0, pc, r0 */
/* @0x125014 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125018 ldr r1, [pc, #-0x828] */
/* @0x12501c ldr r0, [pc, #-0x828] */
/* @0x125020 mov r2, #6 */
/* @0x125024 mov r3, #0 */
/* @0x125028 ldr r1, [r4, r1] */
/* @0x12502c add r0, pc, r0 */
/* @0x125030 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125034 ldr r1, [pc, #-0x83c] */
/* @0x125038 ldr r0, [pc, #-0x83c] */
/* @0x12503c mov r2, #8 */
/* @0x125040 mov r3, #1 */
/* @0x125044 ldr r1, [r4, r1] */
/* @0x125048 add r0, pc, r0 */
/* @0x12504c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125050 ldr r1, [pc, #-0x850] */
/* @0x125054 ldr r0, [pc, #-0x850] */
/* @0x125058 mov r2, #8 */
/* @0x12505c mov r3, #0 */
/* @0x125060 ldr r1, [r4, r1] */
/* @0x125064 add r0, pc, r0 */
/* @0x125068 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12506c ldr r1, [pc, #-0x864] */
/* @0x125070 ldr r0, [pc, #-0x864] */
/* @0x125074 mov r2, #12 */
/* @0x125078 mov r3, #1 */
/* @0x12507c ldr r1, [r4, r1] */
/* @0x125080 add r0, pc, r0 */
/* @0x125084 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125088 ldr r1, [pc, #-0x878] */
/* @0x12508c ldr r0, [pc, #-0x878] */
/* @0x125090 mov r2, #16 */
/* @0x125094 mov r3, #1 */
/* @0x125098 ldr r1, [r4, r1] */
/* @0x12509c add r0, pc, r0 */
/* @0x1250a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1250a4 ldr r1, [pc, #-0x88c] */
/* @0x1250a8 ldr r0, [pc, #-0x88c] */
/* @0x1250ac mov r2, #4 */
/* @0x1250b0 mov r3, #0 */
/* @0x1250b4 ldr r1, [r4, r1] */
/* @0x1250b8 add r0, pc, r0 */
/* @0x1250bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1250c0 ldr r1, [pc, #-0x8a0] */
/* @0x1250c4 ldr r0, [pc, #-0x8a0] */
/* @0x1250c8 mov r2, #8 */
/* @0x1250cc mov r3, #1 */
/* @0x1250d0 ldr r1, [r4, r1] */
/* @0x1250d4 add r0, pc, r0 */
/* @0x1250d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1250dc ldr r1, [pc, #-0x8b4] */
/* @0x1250e0 ldr r0, [pc, #-0x8b4] */
/* @0x1250e4 mov r2, #3 */
/* @0x1250e8 mov r3, #0 */
/* @0x1250ec ldr r1, [r4, r1] */
/* @0x1250f0 add r0, pc, r0 */
/* @0x1250f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1250f8 ldr r1, [pc, #-0x8c8] */
/* @0x1250fc ldr r0, [pc, #-0x8c8] */
/* @0x125100 mov r2, #8 */
/* @0x125104 mov r3, #1 */
/* @0x125108 ldr r1, [r4, r1] */
/* @0x12510c add r0, pc, r0 */
/* @0x125110 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125114 ldr r1, [pc, #-0x8dc] */
/* @0x125118 ldr r0, [pc, #-0x8dc] */
/* @0x12511c mov r2, #5 */
/* @0x125120 mov r3, #0 */
/* @0x125124 ldr r1, [r4, r1] */
/* @0x125128 add r0, pc, r0 */
/* @0x12512c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125130 ldr r1, [pc, #-0x8f0] */
/* @0x125134 ldr r0, [pc, #-0x8f0] */
/* @0x125138 mov r2, #7 */
/* @0x12513c mov r3, #1 */
/* @0x125140 ldr r1, [r4, r1] */
/* @0x125144 add r0, pc, r0 */
/* @0x125148 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12514c ldr r1, [pc, #-0x904] */
/* @0x125150 ldr r0, [pc, #-0x904] */
/* @0x125154 mov r2, #7 */
/* @0x125158 mov r3, #0 */
/* @0x12515c ldr r1, [r4, r1] */
/* @0x125160 add r0, pc, r0 */
/* @0x125164 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125168 ldr r1, [pc, #-0x918] */
/* @0x12516c ldr r0, [pc, #-0x918] */
/* @0x125170 mov r2, #11 */
/* @0x125174 mov r3, #1 */
/* @0x125178 ldr r1, [r4, r1] */
/* @0x12517c add r0, pc, r0 */
/* @0x125180 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125184 ldr r1, [pc, #-0x92c] */
/* @0x125188 ldr r0, [pc, #-0x92c] */
/* @0x12518c mov r2, #15 */
/* @0x125190 mov r3, #1 */
/* @0x125194 ldr r1, [r4, r1] */
/* @0x125198 add r0, pc, r0 */
/* @0x12519c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1251a0 ldr r1, [pc, #-0x940] */
/* @0x1251a4 ldr r0, [pc, #-0x940] */
/* @0x1251a8 mov r2, #3 */
/* @0x1251ac mov r3, #0 */
/* @0x1251b0 ldr r1, [r4, r1] */
/* @0x1251b4 add r0, pc, r0 */
/* @0x1251b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1251bc ldr r1, [pc, #-0x954] */
/* @0x1251c0 ldr r0, [pc, #-0x954] */
/* @0x1251c4 mov r2, #7 */
/* @0x1251c8 mov r3, #1 */
/* @0x1251cc ldr r1, [r4, r1] */
/* @0x1251d0 add r0, pc, r0 */
/* @0x1251d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1251d8 ldr r1, [pc, #-0x968] */
/* @0x1251dc ldr r0, [pc, #-0x968] */
/* @0x1251e0 mov r2, #1 */
/* @0x1251e4 mov r3, r2 */
/* @0x1251e8 ldr r1, [r4, r1] */
/* @0x1251ec add r0, pc, r0 */
/* @0x1251f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1251f4 ldr r1, [pc, #-0x97c] */
/* @0x1251f8 ldr r0, [pc, #-0x97c] */
/* @0x1251fc mov r2, #1 */
/* @0x125200 mov r3, #0 */
/* @0x125204 ldr r1, [r4, r1] */
/* @0x125208 add r0, pc, r0 */
/* @0x12520c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125210 ldr r1, [pc, #-0x990] */
/* @0x125214 ldr r0, [pc, #-0x990] */
/* @0x125218 mov r2, #1 */
/* @0x12521c mov r3, #0 */
/* @0x125220 ldr r1, [r4, r1] */
/* @0x125224 add r0, pc, r0 */
/* @0x125228 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12522c ldr r1, [pc, #-0x9a4] */
/* @0x125230 ldr r0, [pc, #-0x9a4] */
/* @0x125234 mov r2, #1 */
/* @0x125238 mov r3, #0 */
/* @0x12523c ldr r1, [r4, r1] */
/* @0x125240 add r0, pc, r0 */
/* @0x125244 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125248 ldr r1, [pc, #-0x9b8] */
/* @0x12524c ldr r0, [pc, #-0x9b8] */
/* @0x125250 mov r2, #1 */
/* @0x125254 mov r3, #0 */
/* @0x125258 ldr r1, [r4, r1] */
/* @0x12525c add r0, pc, r0 */
/* @0x125260 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125264 ldr r1, [pc, #-0x9cc] */
/* @0x125268 ldr r0, [pc, #-0x9cc] */
/* @0x12526c mov r2, #1 */
/* @0x125270 mov r3, #0 */
/* @0x125274 ldr r1, [r4, r1] */
/* @0x125278 add r0, pc, r0 */
/* @0x12527c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125280 ldr r1, [pc, #-0x9e0] */
/* @0x125284 ldr r0, [pc, #-0x9e0] */
/* @0x125288 mov r2, #1 */
/* @0x12528c mov r3, #0 */
/* @0x125290 ldr r1, [r4, r1] */
/* @0x125294 add r0, pc, r0 */
/* @0x125298 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12529c ldr r1, [pc, #-0x9f4] */
/* @0x1252a0 ldr r0, [pc, #-0x9f4] */
/* @0x1252a4 mov r2, #1 */
/* @0x1252a8 mov r3, #0 */
/* @0x1252ac ldr r1, [r4, r1] */
/* @0x1252b0 add r0, pc, r0 */
/* @0x1252b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1252b8 ldr r1, [pc, #-0xa08] */
/* @0x1252bc ldr r0, [pc, #-0xa08] */
/* @0x1252c0 mov r2, #1 */
/* @0x1252c4 mov r3, #0 */
/* @0x1252c8 ldr r1, [r4, r1] */
/* @0x1252cc add r0, pc, r0 */
/* @0x1252d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1252d4 ldr r1, [pc, #-0xa1c] */
/* @0x1252d8 ldr r0, [pc, #-0xa1c] */
/* @0x1252dc mov r2, #1 */
/* @0x1252e0 mov r3, #0 */
/* @0x1252e4 ldr r1, [r4, r1] */
/* @0x1252e8 add r0, pc, r0 */
/* @0x1252ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1252f0 ldr r1, [pc, #-0xa30] */
/* @0x1252f4 ldr r0, [pc, #-0xa30] */
/* @0x1252f8 mov r2, #1 */
/* @0x1252fc mov r3, #0 */
/* @0x125300 ldr r1, [r4, r1] */
/* @0x125304 add r0, pc, r0 */
/* @0x125308 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12530c ldr r1, [pc, #-0xa44] */
/* @0x125310 ldr r0, [pc, #-0xa44] */
/* @0x125314 mov r2, #1 */
/* @0x125318 mov r3, #0 */
/* @0x12531c ldr r1, [r4, r1] */
/* @0x125320 add r0, pc, r0 */
/* @0x125324 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125328 ldr r1, [pc, #-0xa58] */
/* @0x12532c ldr r0, [pc, #-0xa58] */
/* @0x125330 mov r2, #1 */
/* @0x125334 mov r3, #0 */
/* @0x125338 ldr r1, [r4, r1] */
/* @0x12533c add r0, pc, r0 */
/* @0x125340 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125344 ldr r1, [pc, #-0xa6c] */
/* @0x125348 ldr r0, [pc, #-0xa6c] */
/* @0x12534c mov r2, #1 */
/* @0x125350 mov r3, #0 */
/* @0x125354 ldr r1, [r4, r1] */
/* @0x125358 add r0, pc, r0 */
/* @0x12535c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125360 ldr r1, [pc, #-0xa80] */
/* @0x125364 ldr r0, [pc, #-0xa80] */
/* @0x125368 mov r2, #2 */
/* @0x12536c mov r3, #0 */
/* @0x125370 ldr r1, [r4, r1] */
/* @0x125374 add r0, pc, r0 */
/* @0x125378 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12537c ldr r1, [pc, #-0xa94] */
/* @0x125380 ldr r0, [pc, #-0xa94] */
/* @0x125384 mov r2, #2 */
/* @0x125388 mov r3, #0 */
/* @0x12538c ldr r1, [r4, r1] */
/* @0x125390 add r0, pc, r0 */
/* @0x125394 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125398 ldr r1, [pc, #-0xaa8] */
/* @0x12539c ldr r0, [pc, #-0xaa8] */
/* @0x1253a0 mov r2, #5 */
/* @0x1253a4 mov r3, #0 */
/* @0x1253a8 ldr r1, [r4, r1] */
/* @0x1253ac add r0, pc, r0 */
/* @0x1253b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1253b4 ldr r1, [pc, #-0xabc] */
/* @0x1253b8 ldr r0, [pc, #-0xabc] */
/* @0x1253bc mov r2, #3 */
/* @0x1253c0 mov r3, #0 */
/* @0x1253c4 ldr r1, [r4, r1] */
/* @0x1253c8 add r0, pc, r0 */
/* @0x1253cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1253d0 ldr r1, [pc, #-0xad0] */
/* @0x1253d4 ldr r0, [pc, #-0xad0] */
/* @0x1253d8 mov r2, #2 */
/* @0x1253dc mov r3, #0 */
/* @0x1253e0 ldr r1, [r4, r1] */
/* @0x1253e4 add r0, pc, r0 */
/* @0x1253e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1253ec ldr r1, [pc, #-0xae4] */
/* @0x1253f0 ldr r0, [pc, #-0xae4] */
/* @0x1253f4 mov r2, #3 */
/* @0x1253f8 mov r3, #0 */
/* @0x1253fc ldr r1, [r4, r1] */
/* @0x125400 add r0, pc, r0 */
/* @0x125404 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125408 ldr r1, [pc, #-0xaf8] */
/* @0x12540c ldr r0, [pc, #-0xaf8] */
/* @0x125410 mov r2, #2 */
/* @0x125414 mov r3, #1 */
/* @0x125418 ldr r1, [r4, r1] */
/* @0x12541c add r0, pc, r0 */
/* @0x125420 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125424 ldr r1, [pc, #-0xb0c] */
/* @0x125428 ldr r0, [pc, #-0xb0c] */
/* @0x12542c mov r2, #2 */
/* @0x125430 mov r3, #0 */
/* @0x125434 ldr r1, [r4, r1] */
/* @0x125438 add r0, pc, r0 */
/* @0x12543c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125440 ldr r1, [pc, #-0xb20] */
/* @0x125444 ldr r0, [pc, #-0xb20] */
/* @0x125448 mov r2, #0 */
/* @0x12544c mov r3, r2 */
/* @0x125450 ldr r1, [r4, r1] */
/* @0x125454 add r0, pc, r0 */
/* @0x125458 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12545c ldr r1, [pc, #-0xb34] */
/* @0x125460 ldr r0, [pc, #-0xb34] */
/* @0x125464 mov r2, #1 */
/* @0x125468 mov r3, #0 */
/* @0x12546c ldr r1, [r4, r1] */
/* @0x125470 add r0, pc, r0 */
/* @0x125474 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125478 ldr r1, [pc, #-0xb48] */
/* @0x12547c ldr r0, [pc, #-0xb48] */
/* @0x125480 mov r2, #0 */
/* @0x125484 mov r3, r2 */
/* @0x125488 ldr r1, [r4, r1] */
/* @0x12548c add r0, pc, r0 */
/* @0x125490 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125494 ldr r1, [pc, #-0xb5c] */
/* @0x125498 ldr r0, [pc, #-0xb5c] */
/* @0x12549c mov r2, #1 */
/* @0x1254a0 mov r3, #0 */
/* @0x1254a4 ldr r1, [r4, r1] */
/* @0x1254a8 add r0, pc, r0 */
/* @0x1254ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1254b0 ldr r1, [pc, #-0xb70] */
/* @0x1254b4 ldr r0, [pc, #-0xb70] */
/* @0x1254b8 mov r2, #8 */
/* @0x1254bc mov r3, #0 */
/* @0x1254c0 ldr r1, [r4, r1] */
/* @0x1254c4 add r0, pc, r0 */
/* @0x1254c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1254cc ldr r1, [pc, #-0xb84] */
/* @0x1254d0 ldr r0, [pc, #-0xb84] */
/* @0x1254d4 mov r2, #1 */
/* @0x1254d8 mov r3, #0 */
/* @0x1254dc ldr r1, [r4, r1] */
/* @0x1254e0 add r0, pc, r0 */
/* @0x1254e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1254e8 ldr r1, [pc, #-0xb98] */
/* @0x1254ec ldr r0, [pc, #-0xb98] */
/* @0x1254f0 mov r2, #1 */
/* @0x1254f4 mov r3, #0 */
/* @0x1254f8 ldr r1, [r4, r1] */
/* @0x1254fc add r0, pc, r0 */
/* @0x125500 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125504 ldr r1, [pc, #-0xbac] */
/* @0x125508 ldr r0, [pc, #-0xbac] */
/* @0x12550c mov r2, #1 */
/* @0x125510 mov r3, #0 */
/* @0x125514 ldr r1, [r4, r1] */
/* @0x125518 add r0, pc, r0 */
/* @0x12551c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125520 ldr r1, [pc, #-0xbc0] */
/* @0x125524 ldr r0, [pc, #-0xbc0] */
/* @0x125528 mov r2, #1 */
/* @0x12552c mov r3, #0 */
/* @0x125530 ldr r1, [r4, r1] */
/* @0x125534 add r0, pc, r0 */
/* @0x125538 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12553c ldr r1, [pc, #-0xbd4] */
/* @0x125540 ldr r0, [pc, #-0xbd4] */
/* @0x125544 mov r2, #1 */
/* @0x125548 mov r3, #0 */
/* @0x12554c ldr r1, [r4, r1] */
/* @0x125550 add r0, pc, r0 */
/* @0x125554 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125558 ldr r1, [pc, #-0xbe8] */
/* @0x12555c ldr r0, [pc, #-0xbe8] */
/* @0x125560 mov r2, #3 */
/* @0x125564 mov r3, #0 */
/* @0x125568 ldr r1, [r4, r1] */
/* @0x12556c add r0, pc, r0 */
/* @0x125570 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125574 ldr r1, [pc, #-0xbfc] */
/* @0x125578 ldr r0, [pc, #-0xbfc] */
/* @0x12557c mov r2, #3 */
/* @0x125580 mov r3, #0 */
/* @0x125584 ldr r1, [r4, r1] */
/* @0x125588 add r0, pc, r0 */
/* @0x12558c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125590 ldr r1, [pc, #-0xc10] */
/* @0x125594 ldr r0, [pc, #-0xc10] */
/* @0x125598 mov r2, #3 */
/* @0x12559c mov r3, #0 */
/* @0x1255a0 ldr r1, [r4, r1] */
/* @0x1255a4 add r0, pc, r0 */
/* @0x1255a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1255ac ldr r1, [pc, #-0xc24] */
/* @0x1255b0 ldr r0, [pc, #-0xc24] */
/* @0x1255b4 mov r2, #2 */
/* @0x1255b8 mov r3, #0 */
/* @0x1255bc ldr r1, [r4, r1] */
/* @0x1255c0 add r0, pc, r0 */
/* @0x1255c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1255c8 ldr r1, [pc, #-0xc38] */
/* @0x1255cc ldr r0, [pc, #-0xc38] */
/* @0x1255d0 mov r2, #2 */
/* @0x1255d4 mov r3, #1 */
/* @0x1255d8 ldr r1, [r4, r1] */
/* @0x1255dc add r0, pc, r0 */
/* @0x1255e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1255e4 ldr r1, [pc, #-0xc4c] */
/* @0x1255e8 ldr r0, [pc, #-0xc4c] */
/* @0x1255ec mov r2, #3 */
/* @0x1255f0 mov r3, #1 */
/* @0x1255f4 ldr r1, [r4, r1] */
/* @0x1255f8 add r0, pc, r0 */
/* @0x1255fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125600 ldr r1, [pc, #-0xc60] */
/* @0x125604 ldr r0, [pc, #-0xc60] */
/* @0x125608 mov r2, #3 */
/* @0x12560c mov r3, #1 */
/* @0x125610 ldr r1, [r4, r1] */
/* @0x125614 add r0, pc, r0 */
/* @0x125618 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12561c ldr r1, [pc, #-0xc74] */
/* @0x125620 ldr r0, [pc, #-0xc74] */
/* @0x125624 mov r2, #3 */
/* @0x125628 mov r3, #1 */
/* @0x12562c ldr r1, [r4, r1] */
/* @0x125630 add r0, pc, r0 */
/* @0x125634 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125638 ldr r1, [pc, #-0xc88] */
/* @0x12563c ldr r0, [pc, #-0xc88] */
/* @0x125640 mov r2, #1 */
/* @0x125644 mov r3, r2 */
/* @0x125648 ldr r1, [r4, r1] */
/* @0x12564c add r0, pc, r0 */
/* @0x125650 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125654 ldr r1, [pc, #-0xc9c] */
/* @0x125658 ldr r0, [pc, #-0xc9c] */
/* @0x12565c mov r2, #1 */
/* @0x125660 mov r3, r2 */
/* @0x125664 ldr r1, [r4, r1] */
/* @0x125668 add r0, pc, r0 */
/* @0x12566c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125670 ldr r1, [pc, #-0xcb0] */
/* @0x125674 ldr r0, [pc, #-0xcb0] */
/* @0x125678 mov r2, #1 */
/* @0x12567c mov r3, r2 */
/* @0x125680 ldr r1, [r4, r1] */
/* @0x125684 add r0, pc, r0 */
/* @0x125688 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12568c ldr r1, [pc, #-0xcc4] */
/* @0x125690 ldr r0, [pc, #-0xcc4] */
/* @0x125694 mov r2, #1 */
/* @0x125698 mov r3, r2 */
/* @0x12569c ldr r1, [r4, r1] */
/* @0x1256a0 add r0, pc, r0 */
/* @0x1256a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1256a8 ldr r1, [pc, #-0xcd8] */
/* @0x1256ac ldr r0, [pc, #-0xcd8] */
/* @0x1256b0 mov r2, #1 */
/* @0x1256b4 mov r3, r2 */
/* @0x1256b8 ldr r1, [r4, r1] */
/* @0x1256bc add r0, pc, r0 */
/* @0x1256c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1256c4 ldr r1, [pc, #-0xcec] */
/* @0x1256c8 ldr r0, [pc, #-0xcec] */
/* @0x1256cc mov r2, #1 */
/* @0x1256d0 mov r3, r2 */
/* @0x1256d4 ldr r1, [r4, r1] */
/* @0x1256d8 add r0, pc, r0 */
/* @0x1256dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1256e0 ldr r1, [pc, #-0xd00] */
/* @0x1256e4 ldr r0, [pc, #-0xd00] */
/* @0x1256e8 mov r2, #2 */
/* @0x1256ec mov r3, #1 */
/* @0x1256f0 ldr r1, [r4, r1] */
/* @0x1256f4 add r0, pc, r0 */
/* @0x1256f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1256fc ldr r1, [pc, #-0xd14] */
/* @0x125700 ldr r0, [pc, #-0xd14] */
/* @0x125704 mov r2, #0 */
/* @0x125708 mov r3, #1 */
/* @0x12570c ldr r1, [r4, r1] */
/* @0x125710 add r0, pc, r0 */
/* @0x125714 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125718 ldr r1, [pc, #-0xd28] */
/* @0x12571c ldr r0, [pc, #-0xd28] */
/* @0x125720 mov r2, #1 */
/* @0x125724 mov r3, r2 */
/* @0x125728 ldr r1, [r4, r1] */
/* @0x12572c add r0, pc, r0 */
/* @0x125730 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125734 ldr r1, [pc, #-0xd3c] */
/* @0x125738 ldr r0, [pc, #-0xd3c] */
/* @0x12573c mov r2, #0 */
/* @0x125740 mov r3, #1 */
/* @0x125744 ldr r1, [r4, r1] */
/* @0x125748 add r0, pc, r0 */
/* @0x12574c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125750 ldr r1, [pc, #-0xd50] */
/* @0x125754 ldr r0, [pc, #-0xd50] */
/* @0x125758 mov r2, #3 */
/* @0x12575c mov r3, #1 */
/* @0x125760 ldr r1, [r4, r1] */
/* @0x125764 add r0, pc, r0 */
/* @0x125768 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12576c ldr r1, [pc, #-0xd64] */
/* @0x125770 ldr r0, [pc, #-0xd64] */
/* @0x125774 mov r2, #8 */
/* @0x125778 mov r3, #1 */
/* @0x12577c ldr r1, [r4, r1] */
/* @0x125780 add r0, pc, r0 */
/* @0x125784 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125788 ldr r1, [pc, #-0xd78] */
/* @0x12578c ldr r0, [pc, #-0xd78] */
/* @0x125790 mov r2, #5 */
/* @0x125794 mov r3, #1 */
/* @0x125798 ldr r1, [r4, r1] */
/* @0x12579c add r0, pc, r0 */
/* @0x1257a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1257a4 ldr r1, [pc, #-0xd8c] */
/* @0x1257a8 ldr r0, [pc, #-0xd8c] */
/* @0x1257ac mov r2, #7 */
/* @0x1257b0 mov r3, #1 */
/* @0x1257b4 ldr r1, [r4, r1] */
/* @0x1257b8 add r0, pc, r0 */
/* @0x1257bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1257c0 ldr r1, [pc, #-0xda0] */
/* @0x1257c4 ldr r0, [pc, #-0xda0] */
/* @0x1257c8 mov r2, #7 */
/* @0x1257cc mov r3, #1 */
/* @0x1257d0 ldr r1, [r4, r1] */
/* @0x1257d4 add r0, pc, r0 */
/* @0x1257d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1257dc ldr r1, [pc, #-0xdb4] */
/* @0x1257e0 ldr r0, [pc, #-0xdb4] */
/* @0x1257e4 mov r2, #11 */
/* @0x1257e8 mov r3, #1 */
/* @0x1257ec ldr r1, [r4, r1] */
/* @0x1257f0 add r0, pc, r0 */
/* @0x1257f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1257f8 ldr r1, [pc, #-0xdc8] */
/* @0x1257fc ldr r0, [pc, #-0xdc8] */
/* @0x125800 mov r2, #15 */
/* @0x125804 mov r3, #1 */
/* @0x125808 ldr r1, [r4, r1] */
/* @0x12580c add r0, pc, r0 */
/* @0x125810 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125814 ldr r1, [pc, #-0xddc] */
/* @0x125818 ldr r0, [pc, #-0xddc] */
/* @0x12581c mov r2, #3 */
/* @0x125820 mov r3, #1 */
/* @0x125824 ldr r1, [r4, r1] */
/* @0x125828 add r0, pc, r0 */
/* @0x12582c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125830 ldr r1, [pc, #-0xdf0] */
/* @0x125834 ldr r0, [pc, #-0xdf0] */
/* @0x125838 mov r2, #7 */
/* @0x12583c mov r3, #1 */
/* @0x125840 ldr r1, [r4, r1] */
/* @0x125844 add r0, pc, r0 */
/* @0x125848 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12584c ldr r1, [pc, #-0xe04] */
/* @0x125850 ldr r0, [pc, #-0xe04] */
/* @0x125854 mov r2, #2 */
/* @0x125858 mov r3, #1 */
/* @0x12585c ldr r1, [r4, r1] */
/* @0x125860 add r0, pc, r0 */
/* @0x125864 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125868 ldr r1, [pc, #-0xe18] */
/* @0x12586c ldr r0, [pc, #-0xe18] */
/* @0x125870 mov r2, #6 */
/* @0x125874 mov r3, #1 */
/* @0x125878 ldr r1, [r4, r1] */
/* @0x12587c add r0, pc, r0 */
/* @0x125880 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125884 ldr r1, [pc, #-0xe2c] */
/* @0x125888 ldr r0, [pc, #-0xe2c] */
/* @0x12588c mov r2, #3 */
/* @0x125890 mov r3, #1 */
/* @0x125894 ldr r1, [r4, r1] */
/* @0x125898 add r0, pc, r0 */
/* @0x12589c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1258a0 ldr r1, [pc, #-0xe40] */
/* @0x1258a4 ldr r0, [pc, #-0xe40] */
/* @0x1258a8 mov r2, #3 */
/* @0x1258ac mov r3, #1 */
/* @0x1258b0 ldr r1, [r4, r1] */
/* @0x1258b4 add r0, pc, r0 */
/* @0x1258b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1258bc ldr r1, [pc, #-0xe54] */
/* @0x1258c0 ldr r0, [pc, #-0xe54] */
/* @0x1258c4 mov r2, #4 */
/* @0x1258c8 mov r3, #1 */
/* @0x1258cc ldr r1, [r4, r1] */
/* @0x1258d0 add r0, pc, r0 */
/* @0x1258d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1258d8 ldr r1, [pc, #-0xe68] */
/* @0x1258dc ldr r0, [pc, #-0xe68] */
/* @0x1258e0 mov r2, #8 */
/* @0x1258e4 mov r3, #1 */
/* @0x1258e8 ldr r1, [r4, r1] */
/* @0x1258ec add r0, pc, r0 */
/* @0x1258f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1258f4 ldr r1, [pc, #-0xe7c] */
/* @0x1258f8 ldr r0, [pc, #-0xe7c] */
/* @0x1258fc mov r2, #1 */
/* @0x125900 mov r3, r2 */
/* @0x125904 ldr r1, [r4, r1] */
/* @0x125908 add r0, pc, r0 */
/* @0x12590c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125910 ldr r1, [pc, #-0xe90] */
/* @0x125914 ldr r0, [pc, #-0xe90] */
/* @0x125918 mov r2, #0 */
/* @0x12591c mov r3, #1 */
/* @0x125920 ldr r5, [r4, r1] */
/* @0x125924 add r0, pc, r0 */
/* @0x125928 mov r1, r5 */
/* @0x12592c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125930 ldr r1, [pc, #-0xea8] */
/* @0x125934 ldr r0, [pc, #-0xea8] */
/* @0x125938 mov r2, #3 */
/* @0x12593c mov r3, #1 */
/* @0x125940 ldr r1, [r4, r1] */
/* @0x125944 add r0, pc, r0 */
/* @0x125948 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12594c ldr r1, [pc, #-0xebc] */
/* @0x125950 ldr r0, [pc, #-0xebc] */
/* @0x125954 mov r2, #2 */
/* @0x125958 mov r3, #1 */
/* @0x12595c ldr r1, [r4, r1] */
/* @0x125960 add r0, pc, r0 */
/* @0x125964 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125968 ldr r0, [pc, #-0xed0] */
/* @0x12596c mov r2, #1 */
/* @0x125970 mov r1, r5 */
/* @0x125974 mov r3, r2 */
/* @0x125978 add r0, pc, r0 */
/* @0x12597c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125980 ldr r1, [pc, #-0xee4] */
/* @0x125984 ldr r0, [pc, #-0xee4] */
/* @0x125988 mov r2, #1 */
/* @0x12598c mov r3, r2 */
/* @0x125990 ldr r1, [r4, r1] */
/* @0x125994 add r0, pc, r0 */
/* @0x125998 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12599c ldr r1, [pc, #-0xef8] */
/* @0x1259a0 ldr r0, [pc, #-0xef8] */
/* @0x1259a4 mov r2, #1 */
/* @0x1259a8 mov r3, r2 */
/* @0x1259ac ldr r1, [r4, r1] */
/* @0x1259b0 add r0, pc, r0 */
/* @0x1259b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1259b8 ldr r1, [pc, #-0xf0c] */
/* @0x1259bc ldr r0, [pc, #-0xf0c] */
/* @0x1259c0 mov r2, #1 */
/* @0x1259c4 mov r3, r2 */
/* @0x1259c8 ldr r1, [r4, r1] */
/* @0x1259cc add r0, pc, r0 */
/* @0x1259d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1259d4 ldr r1, [pc, #-0xf20] */
/* @0x1259d8 ldr r0, [pc, #-0xf20] */
/* @0x1259dc mov r2, #2 */
/* @0x1259e0 mov r3, #1 */
/* @0x1259e4 ldr r1, [r4, r1] */
/* @0x1259e8 add r0, pc, r0 */
/* @0x1259ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1259f0 ldr r1, [pc, #-0xf34] */
/* @0x1259f4 ldr r0, [pc, #-0xf34] */
/* @0x1259f8 mov r2, #2 */
/* @0x1259fc mov r3, #1 */
/* @0x125a00 ldr r1, [r4, r1] */
/* @0x125a04 add r0, pc, r0 */
/* @0x125a08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125a0c ldr r1, [pc, #-0xf48] */
/* @0x125a10 ldr r0, [pc, #-0xf48] */
/* @0x125a14 mov r2, #2 */
/* @0x125a18 mov r3, #1 */
/* @0x125a1c ldr r1, [r4, r1] */
/* @0x125a20 add r0, pc, r0 */
/* @0x125a24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125a28 ldr r1, [pc, #-0xf5c] */
/* @0x125a2c ldr r0, [pc, #-0xf5c] */
/* @0x125a30 mov r2, #2 */
/* @0x125a34 mov r3, #1 */
/* @0x125a38 ldr r1, [r4, r1] */
/* @0x125a3c add r0, pc, r0 */
/* @0x125a40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125a44 ldr r1, [pc, #-0xf70] */
/* @0x125a48 ldr r0, [pc, #-0xf70] */
/* @0x125a4c mov r2, #1 */
/* @0x125a50 mov r3, r2 */
/* @0x125a54 ldr r1, [r4, r1] */
/* @0x125a58 add r0, pc, r0 */
/* @0x125a5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125a60 ldr r1, [pc, #-0xf84] */
/* @0x125a64 ldr r0, [pc, #-0xf84] */
/* @0x125a68 mov r2, #1 */
/* @0x125a6c mov r3, r2 */
/* @0x125a70 ldr r1, [r4, r1] */
/* @0x125a74 add r0, pc, r0 */
/* @0x125a78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125a7c ldr r1, [pc, #-0xf98] */
/* @0x125a80 ldr r0, [pc, #-0xf98] */
/* @0x125a84 mov r2, #2 */
/* @0x125a88 mov r3, #1 */
/* @0x125a8c ldr r1, [r4, r1] */
/* @0x125a90 add r0, pc, r0 */
/* @0x125a94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125a98 ldr r1, [pc, #-0xfac] */
/* @0x125a9c ldr r0, [pc, #-0xfac] */
/* @0x125aa0 mov r2, #2 */
/* @0x125aa4 mov r3, #1 */
/* @0x125aa8 ldr r1, [r4, r1] */
/* @0x125aac add r0, pc, r0 */
/* @0x125ab0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125ab4 ldr r1, [pc, #-0xfc0] */
/* @0x125ab8 ldr r0, [pc, #-0xfc0] */
/* @0x125abc mov r2, #2 */
/* @0x125ac0 mov r3, #1 */
/* @0x125ac4 ldr r1, [r4, r1] */
/* @0x125ac8 add r0, pc, r0 */
/* @0x125acc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125ad0 ldr r1, [pc, #-0xfd4] */
/* @0x125ad4 ldr r0, [pc, #-0xfd4] */
/* @0x125ad8 mov r2, #2 */
/* @0x125adc mov r3, #1 */
/* @0x125ae0 ldr r1, [r4, r1] */
/* @0x125ae4 add r0, pc, r0 */
/* @0x125ae8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125aec ldr r1, [pc, #-0xfe8] */
/* @0x125af0 ldr r0, [pc, #-0xfe8] */
/* @0x125af4 mov r2, #11 */
/* @0x125af8 mov r3, #1 */
/* @0x125afc ldr r1, [r4, r1] */
/* @0x125b00 add r0, pc, r0 */
/* @0x125b04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125b08 ldr r1, [pc, #0x184] */
/* @0x125b0c ldr r0, [pc, #0x184] */
/* @0x125b10 mov r2, #11 */
/* @0x125b14 mov r3, #1 */
/* @0x125b18 ldr r1, [r4, r1] */
/* @0x125b1c add r0, pc, r0 */
/* @0x125b20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125b24 ldr r1, [pc, #0x170] */
/* @0x125b28 ldr r0, [pc, #0x170] */
/* @0x125b2c mov r2, #4 */
/* @0x125b30 mov r3, #1 */
/* @0x125b34 ldr r1, [r4, r1] */
/* @0x125b38 add r0, pc, r0 */
/* @0x125b3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125b40 ldr r1, [pc, #0x15c] */
/* @0x125b44 ldr r0, [pc, #0x15c] */
/* @0x125b48 mov r2, #9 */
/* @0x125b4c mov r3, #1 */
/* @0x125b50 ldr r1, [r4, r1] */
/* @0x125b54 add r0, pc, r0 */
/* @0x125b58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125b5c ldr r1, [pc, #0x148] */
/* @0x125b60 ldr r0, [pc, #0x148] */
/* @0x125b64 mov r2, #2 */
/* @0x125b68 mov r3, #1 */
/* @0x125b6c ldr r1, [r4, r1] */
/* @0x125b70 add r0, pc, r0 */
/* @0x125b74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125b78 ldr r1, [pc, #0x134] */
/* @0x125b7c ldr r0, [pc, #0x134] */
/* @0x125b80 mov r2, #2 */
/* @0x125b84 mov r3, #1 */
/* @0x125b88 ldr r1, [r4, r1] */
/* @0x125b8c add r0, pc, r0 */
/* @0x125b90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125b94 ldr r1, [pc, #0x120] */
/* @0x125b98 ldr r0, [pc, #0x120] */
/* @0x125b9c mov r2, #2 */
/* @0x125ba0 mov r3, #1 */
/* @0x125ba4 ldr r1, [r4, r1] */
/* @0x125ba8 add r0, pc, r0 */
/* @0x125bac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125bb0 ldr r1, [pc, #0x10c] */
/* @0x125bb4 ldr r0, [pc, #0x10c] */
/* @0x125bb8 mov r2, #1 */
/* @0x125bbc mov r3, r2 */
/* @0x125bc0 ldr r1, [r4, r1] */
/* @0x125bc4 add r0, pc, r0 */
/* @0x125bc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125bcc ldr r1, [pc, #0xf8] */
/* @0x125bd0 ldr r0, [pc, #0xf8] */
/* @0x125bd4 mov r2, #2 */
/* @0x125bd8 mov r3, #1 */
/* @0x125bdc ldr r1, [r4, r1] */
/* @0x125be0 add r0, pc, r0 */
/* @0x125be4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125be8 ldr r1, [pc, #0xe4] */
/* @0x125bec ldr r0, [pc, #0xe4] */
/* @0x125bf0 mov r2, #0 */
/* @0x125bf4 mov r3, #1 */
/* @0x125bf8 ldr r1, [r4, r1] */
/* @0x125bfc add r0, pc, r0 */
/* @0x125c00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125c04 ldr r1, [pc, #0xd0] */
/* @0x125c08 ldr r0, [pc, #0xd0] */
/* @0x125c0c mov r2, #0 */
/* @0x125c10 mov r3, #1 */
/* @0x125c14 ldr r1, [r4, r1] */
/* @0x125c18 add r0, pc, r0 */
/* @0x125c1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125c20 ldr r1, [pc, #0xbc] */
/* @0x125c24 ldr r0, [pc, #0xbc] */
/* @0x125c28 mov r2, #1 */
/* @0x125c2c mov r3, r2 */
/* @0x125c30 ldr r1, [r4, r1] */
/* @0x125c34 add r0, pc, r0 */
/* @0x125c38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125c3c ldr r1, [pc, #0xa8] */
/* @0x125c40 ldr r0, [pc, #0xa8] */
/* @0x125c44 mov r2, #1 */
/* @0x125c48 mov r3, r2 */
/* @0x125c4c ldr r1, [r4, r1] */
/* @0x125c50 add r0, pc, r0 */
/* @0x125c54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125c58 ldr r1, [pc, #0x94] */
/* @0x125c5c ldr r0, [pc, #0x94] */
/* @0x125c60 mov r2, #1 */
/* @0x125c64 mov r3, r2 */
/* @0x125c68 ldr r1, [r4, r1] */
/* @0x125c6c add r0, pc, r0 */
/* @0x125c70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125c74 ldr r1, [pc, #0x80] */
/* @0x125c78 ldr r0, [pc, #0x80] */
/* @0x125c7c mov r2, #0 */
/* @0x125c80 mov r3, #1 */
/* @0x125c84 ldr r1, [r4, r1] */
/* @0x125c88 add r0, pc, r0 */
/* @0x125c8c pop {r4, r5, r6, lr} */
/* @0x125c90 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x125c94 .word 0xffffcda8 */
/* @0x125c98 eoreq r6, r1, r12, ror r2 */
/* @0x125c9c .word 0xffffcdac */
/* @0x125ca0 eoreq r6, r1, r4, ror r2 */
/* @0x125ca4 .word 0xffffcdb0 */
/* @0x125ca8 eoreq r6, r1, r0, ror r2 */
/* @0x125cac .word 0xffffcdb4 */
/* @0x125cb0 eoreq r6, r1, r12, ror #4 */
/* @0x125cb4 .word 0xffffcdb8 */
/* @0x125cb8 eoreq r6, r1, r8, ror #4 */
/* @0x125cbc .word 0xffffcdbc */
/* @0x125cc0 eoreq r6, r1, r0, ror #4 */
/* @0x125cc4 .word 0xffffcdc0 */
/* @0x125cc8 eoreq r6, r1, r8, asr r2 */
/* @0x125ccc .word 0xffffcdc4 */
/* @0x125cd0 eoreq r6, r1, r12, asr r2 */
/* @0x125cd4 .word 0xffffcdc8 */
/* @0x125cd8 eoreq r6, r1, r0, ror #4 */
/* @0x125cdc .word 0xffffcdcc */
/* @0x125ce0 eoreq r6, r1, r8, asr r2 */
/* @0x125ce4 .word 0xffffcdd0 */
/* @0x125ce8 eoreq r6, r1, r4, asr r2 */
/* @0x125cec .word 0xffffcdd4 */
/* @0x125cf0 eoreq r6, r1, r12, asr #4 */
/* @0x125cf4 .word 0xffffcdd8 */
/* @0x125cf8 eoreq r6, r1, r4, asr #4 */
/* @0x125cfc .word 0xffffcddc */
/* @0x125d00 eoreq r6, r1, r0, asr #4 */

/* ── FUNC 0x125d04 · F_LoadInfo(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x125d04 ldr r3, [pc, #0x34] */
/* @0x125d08 push {r4, lr} */
/* @0x125d0c ldr r3, [pc, r3] */
/* @0x125d10 mov r4, r0 */
/* @0x125d14 ldr r1, [pc, #0x28] */
/* @0x125d18 ldr r0, [r3] */
/* @0x125d1c add r1, pc, r1 */
/* @0x125d20 ldr r3, [r0] */
/* @0x125d24 ldr r3, [r3, #0xc] */
/* @0x125d28 blx r3 */
/* @0x125d2c mov r3, #0 */
/* @0x125d30 str r3, [r4, #0xc] */
/* @0x125d34 str r3, [r4] */
/* @0x125d38 str r3, [r4, #0x4] */
/* @0x125d3c pop {r4, pc} */
/* @0x125d40 eoreq r7, r12, r8, lsl #20 */
/* @0x125d44 eoreq r6, r1, r4, asr #3 */

/* ── FUNC 0x125d48 · F_MessageBackground(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x125d48 push {r3, lr} */
/* @0x125d4c ldr r3, [pc, #0x1c] */
/* @0x125d50 ldr r1, [pc, #0x1c] */
/* @0x125d54 ldr r3, [pc, r3] */
/* @0x125d58 add r1, pc, r1 */
/* @0x125d5c ldr r0, [r3] */
/* @0x125d60 ldr r3, [r0] */
/* @0x125d64 ldr r3, [r3, #0xc] */
/* @0x125d68 blx r3 */
/* @0x125d6c pop {r3, pc} */
/* @0x125d70 eoreq r7, r12, r0, asr #19 */
/* @0x125d74 eoreq r6, r1, r8, lsr #3 */

/* ── FUNC 0x125d78 · F_MessageButton(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x125d78 push {r3, lr} */
/* @0x125d7c ldr r3, [pc, #0x1c] */
/* @0x125d80 ldr r1, [pc, #0x1c] */
/* @0x125d84 ldr r3, [pc, r3] */
/* @0x125d88 add r1, pc, r1 */
/* @0x125d8c ldr r0, [r3] */
/* @0x125d90 ldr r3, [r0] */
/* @0x125d94 ldr r3, [r3, #0xc] */
/* @0x125d98 blx r3 */
/* @0x125d9c pop {r3, pc} */
/* @0x125da0 mlaeq r12, r0, r9, r7 */
/* @0x125da4 eoreq r6, r1, r4, lsr #3 */

/* ── FUNC 0x125da8 · F_MessageTextFont(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x125da8 push {r3, lr} */
/* @0x125dac ldr r3, [pc, #0x1c] */
/* @0x125db0 ldr r1, [pc, #0x1c] */
/* @0x125db4 ldr r3, [pc, r3] */
/* @0x125db8 add r1, pc, r1 */
/* @0x125dbc ldr r0, [r3] */
/* @0x125dc0 ldr r3, [r0] */
/* @0x125dc4 ldr r3, [r3, #0xc] */
/* @0x125dc8 blx r3 */
/* @0x125dcc pop {r3, pc} */
/* @0x125dd0 eoreq r7, r12, r0, ror #18 */
/* @0x125dd4 mlaeq r1, r8, r1, r6 */
