/* libyoyo.so 覆盖卡组 0225
 * 函数 0x255170..0x2583e4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x255170 · F_JS_Object_defineProperty(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0x255170 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x255174 cmp r3, #0 */
/* @0x255178 sub sp, sp, #36 */
/* @0x25517c mov r7, r0 */
/* @0x255180 ldr r6, [sp, #0x48] */
/* @0x255184 beq 0x255198 <_Z26F_JS_Object_definePropertyR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x255188 ldr r3, [r6, #0xc] */
/* @0x25518c bic r3, r3, #-16777216 */
/* @0x255190 cmp r3, #6 */
/* @0x255194 beq 0x2551ac <_Z26F_JS_Object_definePropertyR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x255198 ldr r0, [pc, #0xa0] */
/* @0x25519c add r0, pc, r0 */
/* @0x2551a0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2551a4 add sp, sp, #36 */
/* @0x2551a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2551ac add r1, r6, #16 */
/* @0x2551b0 mov r0, sp */
/* @0x2551b4 mov r4, #0 */
/* @0x2551b8 mov r5, #0 */
/* @0x2551bc mov r9, #0 */
/* @0x2551c0 strd r4, r5, [sp] */
/* @0x2551c4 str r9, [sp, #0x8] */
/* @0x2551c8 mvn r8, #-16777216 */
/* @0x2551cc str r8, [sp, #0xc] */
/* @0x2551d0 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x2551d4 cmp r0, #1 */
/* @0x2551d8 beq 0x255198 <_Z26F_JS_Object_definePropertyR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x2551dc add r11, sp, #16 */
/* @0x2551e0 add r1, r6, #32 */
/* @0x2551e4 strd r4, r5, [sp, #16] */
/* @0x2551e8 mov r0, r11 */
/* @0x2551ec str r9, [sp, #0x18] */
/* @0x2551f0 str r8, [sp, #0x1c] */
/* @0x2551f4 bl 0x24195c <_Z25F_JS_ToPropertyDescriptorP6RValueS0_> */
/* @0x2551f8 cmp r0, #1 */
/* @0x2551fc beq 0x255198 <_Z26F_JS_Object_definePropertyR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x255200 mov r1, sp */
/* @0x255204 mov r2, r11 */
/* @0x255208 ldr r0, [r6] */
/* @0x25520c mov r3, #1 */
/* @0x255210 bl 0x248610 <_Z22JS_DefineOwnPropertyRVP12YYObjectBaseP6RValueS2_b> */
/* @0x255214 cmp r0, #2 */
/* @0x255218 beq 0x255198 <_Z26F_JS_Object_definePropertyR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x25521c ldr r0, [r6] */
/* @0x255220 ldr r1, [r6, #0x4] */
/* @0x255224 ldr r2, [r6, #0x8] */
/* @0x255228 ldr r3, [r6, #0xc] */
/* @0x25522c str r0, [r7] */
/* @0x255230 str r1, [r7, #0x4] */
/* @0x255234 str r2, [r7, #0x8] */
/* @0x255238 str r3, [r7, #0xc] */
/* @0x25523c b 0x2551a4 <_Z26F_JS_Object_definePropertyR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x255240 andseq r0, r0, r12, lsr #27 */

/* ── FUNC 0x255244 · F_JS_Object_getOwnPropertyDescriptor(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x255244 cmp r3, #0 */
/* @0x255248 push {r4, r5, lr} */
/* @0x25524c mov r4, r0 */
/* @0x255250 sub sp, sp, #36 */
/* @0x255254 beq 0x25526c <_Z36F_JS_Object_getOwnPropertyDescriptorR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x255258 ldr r2, [sp, #0x30] */
/* @0x25525c ldr r3, [r2, #0xc] */
/* @0x255260 bic r3, r3, #-16777216 */
/* @0x255264 cmp r3, #6 */
/* @0x255268 beq 0x255280 <_Z36F_JS_Object_getOwnPropertyDescriptorR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x25526c ldr r0, [pc, #0x70] */
/* @0x255270 add r0, pc, r0 */
/* @0x255274 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x255278 add sp, sp, #36 */
/* @0x25527c pop {r4, r5, pc} */
/* @0x255280 ldr r3, [sp, #0x30] */
/* @0x255284 mov r0, sp */
/* @0x255288 add r1, r3, #16 */
/* @0x25528c bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x255290 cmp r0, #2 */
/* @0x255294 beq 0x255278 <_Z36F_JS_Object_getOwnPropertyDescriptorR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x255298 cmp r0, #1 */
/* @0x25529c beq 0x2552d4 <_Z36F_JS_Object_getOwnPropertyDescriptorR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x2552a0 ldr r2, [sp, #0x30] */
/* @0x2552a4 add r5, sp, #16 */
/* @0x2552a8 ldr r3, [sp] */
/* @0x2552ac mov r1, r5 */
/* @0x2552b0 ldr r0, [r2] */
/* @0x2552b4 mov r2, #5 */
/* @0x2552b8 str r2, [sp, #0x1c] */
/* @0x2552bc ldr r2, [r3] */
/* @0x2552c0 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x2552c4 mov r0, r4 */
/* @0x2552c8 mov r1, r5 */
/* @0x2552cc bl 0x2483e0 <_Z27F_JS_FromPropertyDescriptorP6RValueS0_> */
/* @0x2552d0 b 0x255278 <_Z36F_JS_Object_getOwnPropertyDescriptorR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x2552d4 ldr r0, [pc, #0xc] */
/* @0x2552d8 add r0, pc, r0 */
/* @0x2552dc bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2552e0 b 0x255278 <_Z36F_JS_Object_getOwnPropertyDescriptorR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x2552e4 ldrsbeq r0, [r0], -r8 */
/* @0x2552e8 andseq r1, r0, r0, asr #13 */

/* ── FUNC 0x2552ec · F_JS_Object_prototype_hasOwnProperty(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x2552ec push {r4, r5, lr} */
/* @0x2552f0 sub sp, sp, #36 */
/* @0x2552f4 mov r5, r1 */
/* @0x2552f8 mov r4, r0 */
/* @0x2552fc ldr r1, [sp, #0x30] */
/* @0x255300 mov r0, sp */
/* @0x255304 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x255308 ldr r3, [sp] */
/* @0x25530c mov r2, #5 */
/* @0x255310 mov r0, r5 */
/* @0x255314 str r2, [sp, #0x1c] */
/* @0x255318 add r1, sp, #16 */
/* @0x25531c ldr r2, [r3] */
/* @0x255320 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x255324 ldr r2, [sp, #0x1c] */
/* @0x255328 mvn r3, #-16777216 */
/* @0x25532c cmp r2, r3 */
/* @0x255330 beq 0x255358 <_Z36F_JS_Object_prototype_hasOwnPropertyR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x255334 mov r2, #13 */
/* @0x255338 mov r3, #0 */
/* @0x25533c str r2, [r4, #0xc] */
/* @0x255340 movt r3, #0x3ff0 */
/* @0x255344 str r3, [r4, #0x4] */
/* @0x255348 mov r3, #0 */
/* @0x25534c str r3, [r4] */
/* @0x255350 add sp, sp, #36 */
/* @0x255354 pop {r4, r5, pc} */
/* @0x255358 mov r3, #0 */
/* @0x25535c mov r2, #13 */
/* @0x255360 str r3, [r4] */
/* @0x255364 str r2, [r4, #0xc] */
/* @0x255368 str r3, [r4, #0x4] */
/* @0x25536c add sp, sp, #36 */
/* @0x255370 pop {r4, r5, pc} */

/* ── FUNC 0x255374 · F_JS_Object_prototype_propertyIsEnumerable(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x255374 push {r4, r5, lr} */
/* @0x255378 sub sp, sp, #36 */
/* @0x25537c mov r5, r1 */
/* @0x255380 mov r4, r0 */
/* @0x255384 ldr r1, [sp, #0x30] */
/* @0x255388 mov r0, sp */
/* @0x25538c bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x255390 ldr r3, [sp] */
/* @0x255394 mov r2, #5 */
/* @0x255398 mov r0, r5 */
/* @0x25539c str r2, [sp, #0x1c] */
/* @0x2553a0 add r1, sp, #16 */
/* @0x2553a4 ldr r2, [r3] */
/* @0x2553a8 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x2553ac ldr r3, [sp, #0x1c] */
/* @0x2553b0 mvn r2, #-16777216 */
/* @0x2553b4 cmp r3, r2 */
/* @0x2553b8 cmpne r3, #5 */
/* @0x2553bc movne r3, #0 */
/* @0x2553c0 moveq r3, #1 */
/* @0x2553c4 beq 0x2553f4 <_Z42F_JS_Object_prototype_propertyIsEnumerableR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x2553c8 ldr r2, [sp, #0x18] */
/* @0x2553cc str r3, [r4, #0xc] */
/* @0x2553d0 ands r2, r2, #1 */
/* @0x2553d4 moveq r3, r2 */
/* @0x2553d8 movne r1, #0 */
/* @0x2553dc moveq r1, r3 */
/* @0x2553e0 movtne r1, #0x3ff0 */
/* @0x2553e4 str r3, [r4] */
/* @0x2553e8 str r1, [r4, #0x4] */
/* @0x2553ec add sp, sp, #36 */
/* @0x2553f0 pop {r4, r5, pc} */
/* @0x2553f4 mov r3, #0 */
/* @0x2553f8 str r3, [r4, #0xc] */
/* @0x2553fc str r3, [r4] */
/* @0x255400 str r3, [r4, #0x4] */
/* @0x255404 add sp, sp, #36 */
/* @0x255408 pop {r4, r5, pc} */

/* ── FUNC 0x25540c · JS_String_prototype_charAt(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0x25540c push {r4, r5, r6, lr} */
/* @0x255410 sub sp, sp, #56 */
/* @0x255414 add r4, sp, #56 */
/* @0x255418 mov r6, r0 */
/* @0x25541c mov r3, #6 */
/* @0x255420 str r3, [sp, #0x14] */
/* @0x255424 str r1, [r4, #-0x30]! */
/* @0x255428 mov r0, r4 */
/* @0x25542c bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue> */
/* @0x255430 cmp r0, #1 */
/* @0x255434 beq 0x2554a8 <_Z26JS_String_prototype_charAtR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x255438 add r5, sp, #24 */
/* @0x25543c mov r1, r4 */
/* @0x255440 mov r0, r5 */
/* @0x255444 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x255448 cmp r0, #1 */
/* @0x25544c beq 0x2554a8 <_Z26JS_String_prototype_charAtR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x255450 ldr r0, [sp, #0x48] */
/* @0x255454 mov r4, #0 */
/* @0x255458 bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue> */
/* @0x25545c str r4, [sp, #0x34] */
/* @0x255460 vmov d7, r0, r1 */
/* @0x255464 mov r0, r5 */
/* @0x255468 vcvt.s32.f64 s15, d7 */
/* @0x25546c vmov r1, s15 */
/* @0x255470 bl 0x2424f4 <_Z19UTF8_get_U16_at_posR6RValuei> */
/* @0x255474 mov r1, r4 */
/* @0x255478 mov r2, r4 */
/* @0x25547c add r12, sp, #56 */
/* @0x255480 mov r3, #1 */
/* @0x255484 vmov s13, r0 */
/* @0x255488 mov r0, r6 */
/* @0x25548c vcvt.f64.u32 d7, s13 */
/* @0x255490 vmov r4, r5, d7 */
/* @0x255494 strd r4, r5, [r12, #-16]! */
/* @0x255498 str r12, [sp] */
/* @0x25549c bl 0x24d988 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_> */
/* @0x2554a0 add sp, sp, #56 */
/* @0x2554a4 pop {r4, r5, r6, pc} */
/* @0x2554a8 ldr r0, [pc, #0xc] */
/* @0x2554ac add r0, pc, r0 */
/* @0x2554b0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2554b4 add sp, sp, #56 */
/* @0x2554b8 pop {r4, r5, r6, pc} */
/* @0x2554bc mulseq r0, r12, r10 */

/* ── FUNC 0x2554c0 · JS_String_prototype_charCodeAt(RValue&, CInstance*, CInstance*, int, RValue*) · size=184 · insn=46 */
/* @0x2554c0 push {r4, r5, r6, lr} */
/* @0x2554c4 sub sp, sp, #32 */
/* @0x2554c8 add r4, sp, #32 */
/* @0x2554cc mov r5, r0 */
/* @0x2554d0 mov r0, sp */
/* @0x2554d4 mov r3, #6 */
/* @0x2554d8 str r1, [r4, #-0x20]! */
/* @0x2554dc str r3, [sp, #0xc] */
/* @0x2554e0 bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue> */
/* @0x2554e4 cmp r0, #1 */
/* @0x2554e8 beq 0x255560 <_Z30JS_String_prototype_charCodeAtR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x2554ec add r6, sp, #16 */
/* @0x2554f0 mov r1, sp */
/* @0x2554f4 mov r2, #0 */
/* @0x2554f8 mov r3, #0 */
/* @0x2554fc mov r0, r6 */
/* @0x255500 strd r2, r3, [sp, #16] */
/* @0x255504 mov r4, #0 */
/* @0x255508 mvn r3, #-16777216 */
/* @0x25550c str r4, [sp, #0x18] */
/* @0x255510 str r3, [sp, #0x1c] */
/* @0x255514 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x255518 cmp r0, #1 */
/* @0x25551c beq 0x255560 <_Z30JS_String_prototype_charCodeAtR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x255520 ldr r0, [sp, #0x30] */
/* @0x255524 bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue> */
/* @0x255528 str r4, [r5, #0xc] */
/* @0x25552c vmov d7, r0, r1 */
/* @0x255530 mov r0, r6 */
/* @0x255534 vcvt.s32.f64 s15, d7 */
/* @0x255538 vmov r1, s15 */
/* @0x25553c bl 0x2424f4 <_Z19UTF8_get_U16_at_posR6RValuei> */
/* @0x255540 vmov s15, r0 */
/* @0x255544 vcvt.f64.u32 d7, s15 */
/* @0x255548 vmov r0, r1, d7 */
/* @0x25554c vmov r2, s14 */
/* @0x255550 mov r3, r1 */
/* @0x255554 stm r5, {r2, r3} */
/* @0x255558 add sp, sp, #32 */
/* @0x25555c pop {r4, r5, r6, pc} */
/* @0x255560 ldr r0, [pc, #0xc] */
/* @0x255564 add r0, pc, r0 */
/* @0x255568 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25556c add sp, sp, #32 */
/* @0x255570 pop {r4, r5, r6, pc} */
/* @0x255574 andseq r0, r0, r4, ror #19 */

/* ── FUNC 0x255578 · JS_String_prototype_localeCompare(RValue&, CInstance*, CInstance*, int, RValue*) · size=192 · insn=48 */
/* @0x255578 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x25557c sub sp, sp, #52 */
/* @0x255580 add r4, sp, #48 */
/* @0x255584 mov r6, r0 */
/* @0x255588 mov r0, sp */
/* @0x25558c mov r3, #6 */
/* @0x255590 str r1, [r4, #-0x30]! */
/* @0x255594 str r3, [sp, #0xc] */
/* @0x255598 bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue> */
/* @0x25559c cmp r0, #1 */
/* @0x2555a0 beq 0x255620 <_Z33JS_String_prototype_localeCompareR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x2555a4 mov r1, sp */
/* @0x2555a8 add r0, sp, #16 */
/* @0x2555ac mov r7, #0 */
/* @0x2555b0 mov r4, #0 */
/* @0x2555b4 mov r5, #0 */
/* @0x2555b8 mvn r8, #-16777216 */
/* @0x2555bc strd r4, r5, [sp, #16] */
/* @0x2555c0 str r7, [sp, #0x18] */
/* @0x2555c4 str r8, [sp, #0x1c] */
/* @0x2555c8 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x2555cc ldr r3, [sp, #0x10] */
/* @0x2555d0 add r0, sp, #32 */
/* @0x2555d4 ldr r1, [sp, #0x50] */
/* @0x2555d8 ldr r9, [r3] */
/* @0x2555dc strd r4, r5, [sp, #32] */
/* @0x2555e0 str r7, [sp, #0x28] */
/* @0x2555e4 str r8, [sp, #0x2c] */
/* @0x2555e8 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x2555ec ldr r3, [sp, #0x20] */
/* @0x2555f0 mov r0, r9 */
/* @0x2555f4 ldr r1, [r3] */
/* @0x2555f8 str r7, [r6, #0xc] */
/* @0x2555fc bl 0xb6574 <strcmp@plt> */
/* @0x255600 vmov s15, r0 */
/* @0x255604 vcvt.f64.s32 d7, s15 */
/* @0x255608 vmov r0, r1, d7 */
/* @0x25560c vmov r2, s14 */
/* @0x255610 mov r3, r1 */
/* @0x255614 stm r6, {r2, r3} */
/* @0x255618 add sp, sp, #52 */
/* @0x25561c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x255620 ldr r0, [pc, #0xc] */
/* @0x255624 add r0, pc, r0 */
/* @0x255628 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25562c add sp, sp, #52 */
/* @0x255630 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x255634 andseq r0, r0, r4, lsr #18 */

/* ── FUNC 0x255638 · JS_String_prototype_slice(RValue&, CInstance*, CInstance*, int, RValue*) · size=504 · insn=126 */
/* @0x255638 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x25563c sub sp, sp, #68 */
/* @0x255640 add r4, sp, #64 */
/* @0x255644 mov r8, r0 */
/* @0x255648 mov r3, #6 */
/* @0x25564c ldr r7, [sp, #0x68] */
/* @0x255650 str r1, [r4, #-0x20]! */
/* @0x255654 mov r0, r4 */
/* @0x255658 str r3, [sp, #0x2c] */
/* @0x25565c bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue> */
/* @0x255660 cmp r0, #1 */
/* @0x255664 beq 0x255810 <_Z25JS_String_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x1d8> */
/* @0x255668 mov r1, r4 */
/* @0x25566c add r0, sp, #48 */
/* @0x255670 mov r2, #0 */
/* @0x255674 mov r3, #0 */
/* @0x255678 mov r6, #0 */
/* @0x25567c strd r2, r3, [sp, #48] */
/* @0x255680 str r6, [sp, #0x38] */
/* @0x255684 mvn r3, #-16777216 */
/* @0x255688 str r3, [sp, #0x3c] */
/* @0x25568c bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x255690 ldr r3, [sp, #0x30] */
/* @0x255694 add r5, sp, #20 */
/* @0x255698 ldr r9, [pc, #0x184] */
/* @0x25569c add r11, sp, #4 */
/* @0x2556a0 mov r0, r5 */
/* @0x2556a4 add r10, sp, #6 */
/* @0x2556a8 ldr r1, [r3] */
/* @0x2556ac ldr r9, [pc, r9] */
/* @0x2556b0 add r3, r9, #8 */
/* @0x2556b4 str r3, [sp, #0x8] */
/* @0x2556b8 bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc> */
/* @0x2556bc b 0x2556c8 <_Z25JS_String_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x2556c0 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_> */
/* @0x2556c4 add r6, r6, r0 */
/* @0x2556c8 mov r0, r5 */
/* @0x2556cc bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x2556d0 mov r1, r11 */
/* @0x2556d4 mov r2, r10 */
/* @0x2556d8 subs r4, r0, #0 */
/* @0x2556dc bne 0x2556c0 <_Z25JS_String_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x2556e0 lsl r10, r6, #1 */
/* @0x2556e4 ldr r1, [pc, #0x13c] */
/* @0x2556e8 mov r2, #70 */
/* @0x2556ec mov r3, #1 */
/* @0x2556f0 add r1, pc, r1 */
/* @0x2556f4 mov r0, r10 */
/* @0x2556f8 str r6, [sp, #0x10] */
/* @0x2556fc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x255700 mov r2, r10 */
/* @0x255704 mov r1, r4 */
/* @0x255708 add r10, sp, #4 */
/* @0x25570c add r6, sp, #6 */
/* @0x255710 str r0, [sp, #0xc] */
/* @0x255714 bl 0xb65b0 <memset@plt> */
/* @0x255718 mov r0, r5 */
/* @0x25571c bl 0x2423fc <_ZN23CCodepointIterator_UTF85ResetEv> */
/* @0x255720 mov r0, r5 */
/* @0x255724 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x255728 mov r1, r10 */
/* @0x25572c mov r2, r6 */
/* @0x255730 cmp r0, #0 */
/* @0x255734 beq 0x255768 <_Z25JS_String_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x255738 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_> */
/* @0x25573c ldr r1, [sp, #0xc] */
/* @0x255740 lsl r2, r4, #1 */
/* @0x255744 mov r3, r0 */
/* @0x255748 cmp r0, #2 */
/* @0x25574c ldrh r0, [sp, #4] */
/* @0x255750 add r4, r4, r3 */
/* @0x255754 strh r0, [r1, r2] */
/* @0x255758 ldrheq r3, [sp, #6] */
/* @0x25575c addeq r2, r1, r2 */
/* @0x255760 strheq r3, [r2, #2] */
/* @0x255764 b 0x255720 <_Z25JS_String_prototype_sliceR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x255768 mov r0, r7 */
/* @0x25576c ldr r4, [sp, #0x10] */
/* @0x255770 bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue> */
/* @0x255774 ldr r3, [r7, #0x1c] */
/* @0x255778 cmp r3, #5 */
/* @0x25577c vmov d7, r0, r1 */
/* @0x255780 moveq r0, r4 */
/* @0x255784 vcvt.s32.f64 s15, d7 */
/* @0x255788 vmov r5, s15 */
/* @0x25578c beq 0x2557a4 <_Z25JS_String_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x255790 add r0, r7, #16 */
/* @0x255794 bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue> */
/* @0x255798 vmov d7, r0, r1 */
/* @0x25579c vcvt.s32.f64 s15, d7 */
/* @0x2557a0 vmov r0, s15 */
/* @0x2557a4 cmp r5, #0 */
/* @0x2557a8 addlt r2, r4, r5 */
/* @0x2557ac biclt r2, r2, r2, asr #31 */
/* @0x2557b0 blt 0x2557c0 <_Z25JS_String_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x188> */
/* @0x2557b4 cmp r5, r4 */
/* @0x2557b8 movlt r2, r5 */
/* @0x2557bc movge r2, r4 */
/* @0x2557c0 cmp r0, #0 */
/* @0x2557c4 addlt r3, r4, r0 */
/* @0x2557c8 biclt r3, r3, r3, asr #31 */
/* @0x2557cc blt 0x2557dc <_Z25JS_String_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x2557d0 cmp r0, r4 */
/* @0x2557d4 movlt r3, r0 */
/* @0x2557d8 movge r3, r4 */
/* @0x2557dc rsb r3, r2, r3 */
/* @0x2557e0 add r0, sp, #12 */
/* @0x2557e4 mov r1, r8 */
/* @0x2557e8 bic r3, r3, r3, asr #31 */
/* @0x2557ec bl 0x23cea8 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x2557f0 ldr r0, [sp, #0xc] */
/* @0x2557f4 add r9, r9, #8 */
/* @0x2557f8 str r9, [sp, #0x8] */
/* @0x2557fc cmp r0, #0 */
/* @0x255800 beq 0x255808 <_Z25JS_String_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x255804 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x255808 add sp, sp, #68 */
/* @0x25580c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x255810 ldr r0, [pc, #0x14] */
/* @0x255814 add r0, pc, r0 */
/* @0x255818 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25581c add sp, sp, #68 */
/* @0x255820 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x255824 andseq r11, r9, r12, asr #28 */
/* @0x255828 andeq r11, sp, r0, asr #18 */
/* @0x25582c andseq r0, r0, r4, lsr r7 */

/* ── FUNC 0x255830 · JS_String_prototype_substring(RValue&, CInstance*, CInstance*, int, RValue*) · size=500 · insn=125 */
/* @0x255830 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x255834 sub sp, sp, #68 */
/* @0x255838 add r4, sp, #64 */
/* @0x25583c mov r8, r0 */
/* @0x255840 mov r3, #6 */
/* @0x255844 ldr r7, [sp, #0x68] */
/* @0x255848 str r1, [r4, #-0x20]! */
/* @0x25584c mov r0, r4 */
/* @0x255850 str r3, [sp, #0x2c] */
/* @0x255854 bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue> */
/* @0x255858 cmp r0, #1 */
/* @0x25585c beq 0x255a04 <_Z29JS_String_prototype_substringR6RValueP9CInstanceS2_iPS_+0x1d4> */
/* @0x255860 mov r1, r4 */
/* @0x255864 add r0, sp, #48 */
/* @0x255868 mov r2, #0 */
/* @0x25586c mov r3, #0 */
/* @0x255870 mov r6, #0 */
/* @0x255874 strd r2, r3, [sp, #48] */
/* @0x255878 str r6, [sp, #0x38] */
/* @0x25587c mvn r3, #-16777216 */
/* @0x255880 str r3, [sp, #0x3c] */
/* @0x255884 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x255888 ldr r3, [sp, #0x30] */
/* @0x25588c add r5, sp, #20 */
/* @0x255890 ldr r9, [pc, #0x180] */
/* @0x255894 add r11, sp, #4 */
/* @0x255898 mov r0, r5 */
/* @0x25589c add r10, sp, #6 */
/* @0x2558a0 ldr r1, [r3] */
/* @0x2558a4 ldr r9, [pc, r9] */
/* @0x2558a8 add r3, r9, #8 */
/* @0x2558ac str r3, [sp, #0x8] */
/* @0x2558b0 bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc> */
/* @0x2558b4 b 0x2558c0 <_Z29JS_String_prototype_substringR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x2558b8 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_> */
/* @0x2558bc add r6, r6, r0 */
/* @0x2558c0 mov r0, r5 */
/* @0x2558c4 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x2558c8 mov r1, r11 */
/* @0x2558cc mov r2, r10 */
/* @0x2558d0 subs r4, r0, #0 */
/* @0x2558d4 bne 0x2558b8 <_Z29JS_String_prototype_substringR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x2558d8 lsl r10, r6, #1 */
/* @0x2558dc ldr r1, [pc, #0x138] */
/* @0x2558e0 mov r2, #70 */
/* @0x2558e4 mov r3, #1 */
/* @0x2558e8 add r1, pc, r1 */
/* @0x2558ec mov r0, r10 */
/* @0x2558f0 str r6, [sp, #0x10] */
/* @0x2558f4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2558f8 mov r2, r10 */
/* @0x2558fc mov r1, r4 */
/* @0x255900 add r10, sp, #4 */
/* @0x255904 add r6, sp, #6 */
/* @0x255908 str r0, [sp, #0xc] */
/* @0x25590c bl 0xb65b0 <memset@plt> */
/* @0x255910 mov r0, r5 */
/* @0x255914 bl 0x2423fc <_ZN23CCodepointIterator_UTF85ResetEv> */
/* @0x255918 mov r0, r5 */
/* @0x25591c bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x255920 mov r1, r10 */
/* @0x255924 mov r2, r6 */
/* @0x255928 cmp r0, #0 */
/* @0x25592c beq 0x255960 <_Z29JS_String_prototype_substringR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x255930 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_> */
/* @0x255934 ldr r1, [sp, #0xc] */
/* @0x255938 lsl r2, r4, #1 */
/* @0x25593c mov r3, r0 */
/* @0x255940 cmp r0, #2 */
/* @0x255944 ldrh r0, [sp, #4] */
/* @0x255948 add r4, r4, r3 */
/* @0x25594c strh r0, [r1, r2] */
/* @0x255950 ldrheq r3, [sp, #6] */
/* @0x255954 addeq r2, r1, r2 */
/* @0x255958 strheq r3, [r2, #2] */
/* @0x25595c b 0x255918 <_Z29JS_String_prototype_substringR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x255960 mov r0, r7 */
/* @0x255964 ldr r4, [sp, #0x10] */
/* @0x255968 bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue> */
/* @0x25596c ldr r3, [r7, #0x1c] */
/* @0x255970 cmp r3, #5 */
/* @0x255974 vmov d7, r0, r1 */
/* @0x255978 moveq r0, r4 */
/* @0x25597c vcvt.s32.f64 s15, d7 */
/* @0x255980 vmov r5, s15 */
/* @0x255984 beq 0x25599c <_Z29JS_String_prototype_substringR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x255988 add r0, r7, #16 */
/* @0x25598c bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue> */
/* @0x255990 vmov d7, r0, r1 */
/* @0x255994 vcvt.s32.f64 s15, d7 */
/* @0x255998 vmov r0, s15 */
/* @0x25599c bic r2, r5, r5, asr #31 */
/* @0x2559a0 bic r3, r0, r0, asr #31 */
/* @0x2559a4 cmp r2, r4 */
/* @0x2559a8 movge r2, r4 */
/* @0x2559ac cmp r3, r4 */
/* @0x2559b0 movge r3, r4 */
/* @0x2559b4 cmp r2, r3 */
/* @0x2559b8 bge 0x2559ec <_Z29JS_String_prototype_substringR6RValueP9CInstanceS2_iPS_+0x1bc> */
/* @0x2559bc add r0, sp, #12 */
/* @0x2559c0 mov r1, r8 */
/* @0x2559c4 rsb r3, r2, r3 */
/* @0x2559c8 add r9, r9, #8 */
/* @0x2559cc bl 0x23cea8 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x2559d0 ldr r0, [sp, #0xc] */
/* @0x2559d4 str r9, [sp, #0x8] */
/* @0x2559d8 cmp r0, #0 */
/* @0x2559dc beq 0x2559e4 <_Z29JS_String_prototype_substringR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x2559e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2559e4 add sp, sp, #68 */
/* @0x2559e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2559ec cmp r3, r2 */
/* @0x2559f0 movge r1, r3 */
/* @0x2559f4 movlt r1, r2 */
/* @0x2559f8 mov r2, r3 */
/* @0x2559fc mov r3, r1 */
/* @0x255a00 b 0x2559bc <_Z29JS_String_prototype_substringR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0x255a04 ldr r0, [pc, #0x14] */
/* @0x255a08 add r0, pc, r0 */
/* @0x255a0c bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x255a10 add sp, sp, #68 */
/* @0x255a14 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x255a18 andseq r11, r9, r4, asr r12 */
/* @0x255a1c andeq r11, sp, r8, asr #14 */
/* @0x255a20 andseq r0, r0, r0, asr #10 */

/* ── FUNC 0x255a24 · JS_String_prototype_toLowerCase(RValue&, CInstance*, CInstance*, int, RValue*) · size=520 · insn=130 */
/* @0x255a24 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x255a28 add r11, sp, #32 */
/* @0x255a2c ldr r7, [pc, #0x1f0] */
/* @0x255a30 sub sp, sp, #60 */
/* @0x255a34 sub r4, r11, #36 */
/* @0x255a38 ldr r7, [pc, r7] */
/* @0x255a3c mov r3, #6 */
/* @0x255a40 str r3, [r11, #-0x3c] */
/* @0x255a44 ldr r3, [r7] */
/* @0x255a48 str r0, [r11, #-0x58] */
/* @0x255a4c str r1, [r4, #-0x24]! */
/* @0x255a50 mov r0, r4 */
/* @0x255a54 str r3, [r11, #-0x28] */
/* @0x255a58 bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue> */
/* @0x255a5c cmp r0, #1 */
/* @0x255a60 beq 0x255c10 <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0x1ec> */
/* @0x255a64 mov r1, r4 */
/* @0x255a68 sub r0, r11, #56 */
/* @0x255a6c mov r5, #0 */
/* @0x255a70 mvn r3, #-16777216 */
/* @0x255a74 str r5, [r11, #-0x38] */
/* @0x255a78 sub r6, r11, #84 */
/* @0x255a7c str r5, [r11, #-0x34] */
/* @0x255a80 movw r10, #0xfffe */
/* @0x255a84 str r5, [r11, #-0x30] */
/* @0x255a88 mov r4, r5 */
/* @0x255a8c str r3, [r11, #-0x2c] */
/* @0x255a90 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x255a94 ldr r3, [r11, #-0x38] */
/* @0x255a98 mov r0, r6 */
/* @0x255a9c movt r10, #0x1f */
/* @0x255aa0 movw r8, #0x7fe */
/* @0x255aa4 movw r9, #0xfffe */
/* @0x255aa8 ldr r3, [r3] */
/* @0x255aac mov r1, r3 */
/* @0x255ab0 str r3, [r11, #-0x5c] */
/* @0x255ab4 bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc> */
/* @0x255ab8 ldr r3, [r11, #-0x5c] */
/* @0x255abc mov r0, r3 */
/* @0x255ac0 bl 0xb6538 <strlen@plt> */
/* @0x255ac4 mov r1, r5 */
/* @0x255ac8 lsl r2, r0, #2 */
/* @0x255acc add r3, r2, #14 */
/* @0x255ad0 bic r3, r3, #7 */
/* @0x255ad4 sub sp, sp, r3 */
/* @0x255ad8 mov r0, sp */
/* @0x255adc mov r5, sp */
/* @0x255ae0 bl 0xb65b0 <memset@plt> */
/* @0x255ae4 mov r0, r6 */
/* @0x255ae8 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x255aec cmp r0, #0 */
/* @0x255af0 beq 0x255b48 <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x255af4 bl 0x23f8b8 <_Z12utf8_toloweri> */
/* @0x255af8 cmp r0, #126 */
/* @0x255afc strble r0, [r5, r4] */
/* @0x255b00 addle r4, r4, #1 */
/* @0x255b04 ble 0x255ae4 <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x255b08 cmp r0, r8 */
/* @0x255b0c bgt 0x255b6c <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x255b10 ubfx r3, r0, #0x6, #0x5 */
/* @0x255b14 and r0, r0, #63 */
/* @0x255b18 add r2, r4, #1 */
/* @0x255b1c mvn r3, r3, lsl #26 */
/* @0x255b20 mvn r0, r0, lsl #25 */
/* @0x255b24 mvn r3, r3, lsr #26 */
/* @0x255b28 mvn r0, r0, lsr #25 */
/* @0x255b2c strb r3, [r5, r4] */
/* @0x255b30 add r4, r4, #2 */
/* @0x255b34 strb r0, [r5, r2] */
/* @0x255b38 mov r0, r6 */
/* @0x255b3c bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x255b40 cmp r0, #0 */
/* @0x255b44 bne 0x255af4 <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x255b48 ldr r0, [r11, #-0x58] */
/* @0x255b4c mov r1, r5 */
/* @0x255b50 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x255b54 ldr r2, [r11, #-0x28] */
/* @0x255b58 ldr r3, [r7] */
/* @0x255b5c cmp r2, r3 */
/* @0x255b60 bne 0x255c20 <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x255b64 sub sp, r11, #32 */
/* @0x255b68 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x255b6c cmp r0, r9 */
/* @0x255b70 bgt 0x255bb4 <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0x190> */
/* @0x255b74 ubfx r1, r0, #0xc, #0x4 */
/* @0x255b78 ubfx r2, r0, #0x6, #0x6 */
/* @0x255b7c and r0, r0, #63 */
/* @0x255b80 add r12, r4, #2 */
/* @0x255b84 mov r3, r5 */
/* @0x255b88 mvn r1, r1, lsl #27 */
/* @0x255b8c mvn r2, r2, lsl #25 */
/* @0x255b90 mvn r0, r0, lsl #25 */
/* @0x255b94 mvn r1, r1, lsr #27 */
/* @0x255b98 mvn r2, r2, lsr #25 */
/* @0x255b9c strb r1, [r3, r4]! */
/* @0x255ba0 mvn r0, r0, lsr #25 */
/* @0x255ba4 strb r2, [r3, #0x1] */
/* @0x255ba8 add r4, r4, #3 */
/* @0x255bac strb r0, [r5, r12] */
/* @0x255bb0 b 0x255ae4 <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x255bb4 cmp r0, r10 */
/* @0x255bb8 bgt 0x255ae4 <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x255bbc and lr, r0, #3670016 */
/* @0x255bc0 ubfx r12, r0, #0xc, #0x6 */
/* @0x255bc4 ubfx r1, r0, #0x6, #0x6 */
/* @0x255bc8 and r0, r0, #63 */
/* @0x255bcc asr lr, lr, #18 */
/* @0x255bd0 add r2, r4, #3 */
/* @0x255bd4 mov r3, r5 */
/* @0x255bd8 mvn r12, r12, lsl #25 */
/* @0x255bdc mvn lr, lr, lsl #28 */
/* @0x255be0 mvn r1, r1, lsl #25 */
/* @0x255be4 mvn r0, r0, lsl #25 */
/* @0x255be8 mvn lr, lr, lsr #28 */
/* @0x255bec mvn r12, r12, lsr #25 */
/* @0x255bf0 strb lr, [r3, r4]! */
/* @0x255bf4 mvn r1, r1, lsr #25 */
/* @0x255bf8 strb r12, [r3, #0x1] */
/* @0x255bfc strb r1, [r3, #0x2] */
/* @0x255c00 mvn r0, r0, lsr #25 */
/* @0x255c04 add r4, r4, #4 */
/* @0x255c08 strb r0, [r5, r2] */
/* @0x255c0c b 0x255ae4 <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x255c10 ldr r0, [pc, #0x10] */
/* @0x255c14 add r0, pc, r0 */
/* @0x255c18 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x255c1c b 0x255b54 <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x255c20 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x255c24 andseq r7, r9, r8, lsl pc */
/* @0x255c28 andseq r0, r0, r4, lsr r3 */

/* ── FUNC 0x255c2c · JS_String_prototype_toUpperCase(RValue&, CInstance*, CInstance*, int, RValue*) · size=520 · insn=130 */
/* @0x255c2c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x255c30 add r11, sp, #32 */
/* @0x255c34 ldr r7, [pc, #0x1f0] */
/* @0x255c38 sub sp, sp, #60 */
/* @0x255c3c sub r4, r11, #36 */
/* @0x255c40 ldr r7, [pc, r7] */
/* @0x255c44 mov r3, #6 */
/* @0x255c48 str r3, [r11, #-0x3c] */
/* @0x255c4c ldr r3, [r7] */
/* @0x255c50 str r0, [r11, #-0x58] */
/* @0x255c54 str r1, [r4, #-0x24]! */
/* @0x255c58 mov r0, r4 */
/* @0x255c5c str r3, [r11, #-0x28] */
/* @0x255c60 bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue> */
/* @0x255c64 cmp r0, #1 */
/* @0x255c68 beq 0x255e18 <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0x1ec> */
/* @0x255c6c mov r1, r4 */
/* @0x255c70 sub r0, r11, #56 */
/* @0x255c74 mov r5, #0 */
/* @0x255c78 mvn r3, #-16777216 */
/* @0x255c7c str r5, [r11, #-0x38] */
/* @0x255c80 sub r6, r11, #84 */
/* @0x255c84 str r5, [r11, #-0x34] */
/* @0x255c88 movw r10, #0xfffe */
/* @0x255c8c str r5, [r11, #-0x30] */
/* @0x255c90 mov r4, r5 */
/* @0x255c94 str r3, [r11, #-0x2c] */
/* @0x255c98 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x255c9c ldr r3, [r11, #-0x38] */
/* @0x255ca0 mov r0, r6 */
/* @0x255ca4 movt r10, #0x1f */
/* @0x255ca8 movw r8, #0x7fe */
/* @0x255cac movw r9, #0xfffe */
/* @0x255cb0 ldr r3, [r3] */
/* @0x255cb4 mov r1, r3 */
/* @0x255cb8 str r3, [r11, #-0x5c] */
/* @0x255cbc bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc> */
/* @0x255cc0 ldr r3, [r11, #-0x5c] */
/* @0x255cc4 mov r0, r3 */
/* @0x255cc8 bl 0xb6538 <strlen@plt> */
/* @0x255ccc mov r1, r5 */
/* @0x255cd0 lsl r2, r0, #2 */
/* @0x255cd4 add r3, r2, #14 */
/* @0x255cd8 bic r3, r3, #7 */
/* @0x255cdc sub sp, sp, r3 */
/* @0x255ce0 mov r0, sp */
/* @0x255ce4 mov r5, sp */
/* @0x255ce8 bl 0xb65b0 <memset@plt> */
/* @0x255cec mov r0, r6 */
/* @0x255cf0 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x255cf4 cmp r0, #0 */
/* @0x255cf8 beq 0x255d50 <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x255cfc bl 0x23f8d4 <_Z12utf8_toupperi> */
/* @0x255d00 cmp r0, #126 */
/* @0x255d04 strble r0, [r5, r4] */
/* @0x255d08 addle r4, r4, #1 */
/* @0x255d0c ble 0x255cec <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x255d10 cmp r0, r8 */
/* @0x255d14 bgt 0x255d74 <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x255d18 ubfx r3, r0, #0x6, #0x5 */
/* @0x255d1c and r0, r0, #63 */
/* @0x255d20 add r2, r4, #1 */
/* @0x255d24 mvn r3, r3, lsl #26 */
/* @0x255d28 mvn r0, r0, lsl #25 */
/* @0x255d2c mvn r3, r3, lsr #26 */
/* @0x255d30 mvn r0, r0, lsr #25 */
/* @0x255d34 strb r3, [r5, r4] */
/* @0x255d38 add r4, r4, #2 */
/* @0x255d3c strb r0, [r5, r2] */
/* @0x255d40 mov r0, r6 */
/* @0x255d44 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x255d48 cmp r0, #0 */
/* @0x255d4c bne 0x255cfc <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x255d50 ldr r0, [r11, #-0x58] */
/* @0x255d54 mov r1, r5 */
/* @0x255d58 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x255d5c ldr r2, [r11, #-0x28] */
/* @0x255d60 ldr r3, [r7] */
/* @0x255d64 cmp r2, r3 */
/* @0x255d68 bne 0x255e28 <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x255d6c sub sp, r11, #32 */
/* @0x255d70 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x255d74 cmp r0, r9 */
/* @0x255d78 bgt 0x255dbc <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0x190> */
/* @0x255d7c ubfx r1, r0, #0xc, #0x4 */
/* @0x255d80 ubfx r2, r0, #0x6, #0x6 */
/* @0x255d84 and r0, r0, #63 */
/* @0x255d88 add r12, r4, #2 */
/* @0x255d8c mov r3, r5 */
/* @0x255d90 mvn r1, r1, lsl #27 */
/* @0x255d94 mvn r2, r2, lsl #25 */
/* @0x255d98 mvn r0, r0, lsl #25 */
/* @0x255d9c mvn r1, r1, lsr #27 */
/* @0x255da0 mvn r2, r2, lsr #25 */
/* @0x255da4 strb r1, [r3, r4]! */
/* @0x255da8 mvn r0, r0, lsr #25 */
/* @0x255dac strb r2, [r3, #0x1] */
/* @0x255db0 add r4, r4, #3 */
/* @0x255db4 strb r0, [r5, r12] */
/* @0x255db8 b 0x255cec <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x255dbc cmp r0, r10 */
/* @0x255dc0 bgt 0x255cec <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x255dc4 and lr, r0, #3670016 */
/* @0x255dc8 ubfx r12, r0, #0xc, #0x6 */
/* @0x255dcc ubfx r1, r0, #0x6, #0x6 */
/* @0x255dd0 and r0, r0, #63 */
/* @0x255dd4 asr lr, lr, #18 */
/* @0x255dd8 add r2, r4, #3 */
/* @0x255ddc mov r3, r5 */
/* @0x255de0 mvn r12, r12, lsl #25 */
/* @0x255de4 mvn lr, lr, lsl #28 */
/* @0x255de8 mvn r1, r1, lsl #25 */
/* @0x255dec mvn r0, r0, lsl #25 */
/* @0x255df0 mvn lr, lr, lsr #28 */
/* @0x255df4 mvn r12, r12, lsr #25 */
/* @0x255df8 strb lr, [r3, r4]! */
/* @0x255dfc mvn r1, r1, lsr #25 */
/* @0x255e00 strb r12, [r3, #0x1] */
/* @0x255e04 strb r1, [r3, #0x2] */
/* @0x255e08 mvn r0, r0, lsr #25 */
/* @0x255e0c add r4, r4, #4 */
/* @0x255e10 strb r0, [r5, r2] */
/* @0x255e14 b 0x255cec <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x255e18 ldr r0, [pc, #0x10] */
/* @0x255e1c add r0, pc, r0 */
/* @0x255e20 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x255e24 b 0x255d5c <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x255e28 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x255e2c andseq r7, r9, r0, lsl sp */
/* @0x255e30 andseq r0, r0, r12, lsr #2 */

/* ── FUNC 0x255e34 · JS_String_prototype_trim(RValue&, CInstance*, CInstance*, int, RValue*) · size=572 · insn=143 */
/* @0x255e34 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x255e38 add r11, sp, #32 */
/* @0x255e3c ldr r7, [pc, #0x224] */
/* @0x255e40 sub sp, sp, #68 */
/* @0x255e44 sub r4, r11, #36 */
/* @0x255e48 ldr r7, [pc, r7] */
/* @0x255e4c mov r3, #6 */
/* @0x255e50 str r3, [r11, #-0x3c] */
/* @0x255e54 ldr r3, [r7] */
/* @0x255e58 str r0, [r11, #-0x60] */
/* @0x255e5c str r1, [r4, #-0x24]! */
/* @0x255e60 mov r0, r4 */
/* @0x255e64 str r3, [r11, #-0x28] */
/* @0x255e68 bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue> */
/* @0x255e6c cmp r0, #1 */
/* @0x255e70 beq 0x255fcc <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x255e74 mov r1, r4 */
/* @0x255e78 sub r0, r11, #56 */
/* @0x255e7c mov r4, #0 */
/* @0x255e80 mvn r3, #-16777216 */
/* @0x255e84 str r4, [r11, #-0x38] */
/* @0x255e88 sub r5, r11, #84 */
/* @0x255e8c str r3, [r11, #-0x2c] */
/* @0x255e90 movw r10, #0xfffe */
/* @0x255e94 str r4, [r11, #-0x34] */
/* @0x255e98 movt r10, #0x1f */
/* @0x255e9c str r4, [r11, #-0x30] */
/* @0x255ea0 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x255ea4 ldr r3, [r11, #-0x38] */
/* @0x255ea8 mov r0, r5 */
/* @0x255eac mvn r2, #0 */
/* @0x255eb0 str r2, [r11, #-0x58] */
/* @0x255eb4 mov r8, r4 */
/* @0x255eb8 mov r6, #1 */
/* @0x255ebc ldr r9, [r3] */
/* @0x255ec0 mov r1, r9 */
/* @0x255ec4 bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc> */
/* @0x255ec8 mov r0, r9 */
/* @0x255ecc bl 0xb6538 <strlen@plt> */
/* @0x255ed0 mov r1, r4 */
/* @0x255ed4 lsl r2, r0, #2 */
/* @0x255ed8 add r3, r2, #14 */
/* @0x255edc bic r3, r3, #7 */
/* @0x255ee0 sub sp, sp, r3 */
/* @0x255ee4 mov r3, sp */
/* @0x255ee8 lsr r3, r3, #3 */
/* @0x255eec str r3, [r11, #-0x5c] */
/* @0x255ef0 lsl r9, r3, #3 */
/* @0x255ef4 mov r0, r9 */
/* @0x255ef8 bl 0xb65b0 <memset@plt> */
/* @0x255efc b 0x255f0c <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x255f00 bl 0x2425ac <_Z15JS_isWhitespacei> */
/* @0x255f04 tst r0, r6 */
/* @0x255f08 beq 0x255f50 <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x255f0c mov r0, r5 */
/* @0x255f10 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x255f14 subs r4, r0, #0 */
/* @0x255f18 bne 0x255f00 <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x255f1c ldr r3, [r11, #-0x58] */
/* @0x255f20 mov r1, r9 */
/* @0x255f24 ldr r0, [r11, #-0x60] */
/* @0x255f28 cmp r8, r3 */
/* @0x255f2c ldrgt r2, [r11, #-0x5c] */
/* @0x255f30 strbgt r4, [r3, r2, lsl #3] */
/* @0x255f34 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x255f38 ldr r2, [r11, #-0x28] */
/* @0x255f3c ldr r3, [r7] */
/* @0x255f40 cmp r2, r3 */
/* @0x255f44 bne 0x256064 <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0x230> */
/* @0x255f48 sub sp, r11, #32 */
/* @0x255f4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x255f50 cmp r4, #126 */
/* @0x255f54 strble r4, [r9, r8] */
/* @0x255f58 addle r8, r8, #1 */
/* @0x255f5c ble 0x255fb4 <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0x180> */
/* @0x255f60 movw r2, #0x7fe */
/* @0x255f64 cmp r4, r2 */
/* @0x255f68 ble 0x255fdc <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x255f6c movw r3, #0xfffe */
/* @0x255f70 cmp r4, r3 */
/* @0x255f74 bgt 0x256008 <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0x1d4> */
/* @0x255f78 ubfx r12, r4, #0xc, #0x4 */
/* @0x255f7c mov r2, r9 */
/* @0x255f80 ubfx r1, r4, #0x6, #0x6 */
/* @0x255f84 and r3, r4, #63 */
/* @0x255f88 mvn r12, r12, lsl #27 */
/* @0x255f8c add lr, r8, #2 */
/* @0x255f90 mvn r12, r12, lsr #27 */
/* @0x255f94 strb r12, [r2, r8]! */
/* @0x255f98 add r8, r8, #3 */
/* @0x255f9c mvn r1, r1, lsl #25 */
/* @0x255fa0 mvn r3, r3, lsl #25 */
/* @0x255fa4 mvn r1, r1, lsr #25 */
/* @0x255fa8 mvn r3, r3, lsr #25 */
/* @0x255fac strb r1, [r2, #0x1] */
/* @0x255fb0 strb r3, [r9, lr] */
/* @0x255fb4 ldr r3, [r11, #-0x58] */
/* @0x255fb8 cmp r0, #0 */
/* @0x255fbc mov r6, #0 */
/* @0x255fc0 moveq r3, r8 */
/* @0x255fc4 str r3, [r11, #-0x58] */
/* @0x255fc8 b 0x255f0c <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x255fcc ldr r0, [pc, #0x98] */
/* @0x255fd0 add r0, pc, r0 */
/* @0x255fd4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x255fd8 b 0x255f38 <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x255fdc ubfx r2, r4, #0x6, #0x5 */
/* @0x255fe0 and r3, r4, #63 */
/* @0x255fe4 add r1, r8, #1 */
/* @0x255fe8 mvn r2, r2, lsl #26 */
/* @0x255fec mvn r3, r3, lsl #25 */
/* @0x255ff0 mvn r2, r2, lsr #26 */
/* @0x255ff4 mvn r3, r3, lsr #25 */
/* @0x255ff8 strb r2, [r9, r8] */
/* @0x255ffc add r8, r8, #2 */
/* @0x256000 strb r3, [r9, r1] */
/* @0x256004 b 0x255fb4 <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0x180> */
/* @0x256008 cmp r4, r10 */
/* @0x25600c bgt 0x255fb4 <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0x180> */
/* @0x256010 and lr, r4, #3670016 */
/* @0x256014 mov r3, r9 */
/* @0x256018 ubfx r12, r4, #0xc, #0x6 */
/* @0x25601c ubfx r1, r4, #0x6, #0x6 */
/* @0x256020 asr lr, lr, #18 */
/* @0x256024 and r2, r4, #63 */
/* @0x256028 mvn r12, r12, lsl #25 */
/* @0x25602c mvn r1, r1, lsl #25 */
/* @0x256030 mvn lr, lr, lsl #28 */
/* @0x256034 mvn r2, r2, lsl #25 */
/* @0x256038 mvn lr, lr, lsr #28 */
/* @0x25603c strb lr, [r3, r8]! */
/* @0x256040 add lr, r8, #3 */
/* @0x256044 mvn r12, r12, lsr #25 */
/* @0x256048 mvn r1, r1, lsr #25 */
/* @0x25604c strb r12, [r3, #0x1] */
/* @0x256050 strb r1, [r3, #0x2] */
/* @0x256054 mvn r2, r2, lsr #25 */
/* @0x256058 add r8, r8, #4 */
/* @0x25605c strb r2, [r9, lr] */
/* @0x256060 b 0x255fb4 <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0x180> */
/* @0x256064 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x256068 andseq r7, r9, r8, lsl #22 */
/* @0x25606c andeq pc, pc, r8, ror pc */

/* ── FUNC 0x256070 · F_JSStringCall(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x256070 cmp r3, #0 */
/* @0x256074 mov r12, r0 */
/* @0x256078 push {r3, lr} */
/* @0x25607c ldr r1, [sp, #0x8] */
/* @0x256080 beq 0x2560b0 <_Z14F_JSStringCallR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x256084 ldr r2, [r1, #0xc] */
/* @0x256088 mvn r3, #-16777216 */
/* @0x25608c cmp r2, r3 */
/* @0x256090 beq 0x2560b0 <_Z14F_JSStringCallR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x256094 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x256098 cmp r0, #1 */
/* @0x25609c popne {r3, pc} */
/* @0x2560a0 ldr r0, [pc, #0x1c] */
/* @0x2560a4 pop {r3, lr} */
/* @0x2560a8 add r0, pc, r0 */
/* @0x2560ac b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2560b0 ldr r1, [pc, #0x10] */
/* @0x2560b4 mov r0, r12 */
/* @0x2560b8 pop {r3, lr} */
/* @0x2560bc add r1, pc, r1 */
/* @0x2560c0 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x2560c4 andeq pc, pc, r0, lsr #29 */
/* @0x2560c8 andeq r8, sp, r10, ror r10 */

/* ── FUNC 0x2560cc · JS_String_prototype_search(RValue&, CInstance*, CInstance*, int, RValue*) · size=712 · insn=178 */
/* @0x2560cc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2560d0 sub sp, sp, #212 */
/* @0x2560d4 add r8, sp, #208 */
/* @0x2560d8 mov r7, r0 */
/* @0x2560dc mov r4, r1 */
/* @0x2560e0 mov r10, r2 */
/* @0x2560e4 str r1, [r8, #-0xa8]! */
/* @0x2560e8 mov r0, r8 */
/* @0x2560ec mov r6, r3 */
/* @0x2560f0 ldr r5, [sp, #0xf8] */
/* @0x2560f4 mov r3, #6 */
/* @0x2560f8 str r3, [sp, #0x34] */
/* @0x2560fc bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue> */
/* @0x256100 ldr r9, [pc, #0x264] */
/* @0x256104 add r9, pc, r9 */
/* @0x256108 cmp r0, #1 */
/* @0x25610c beq 0x256308 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x23c> */
/* @0x256110 mov r1, r8 */
/* @0x256114 add r0, sp, #56 */
/* @0x256118 mov r2, #0 */
/* @0x25611c mov r3, #0 */
/* @0x256120 mov r11, #0 */
/* @0x256124 strd r2, r3, [sp, #56] */
/* @0x256128 str r11, [sp, #0x40] */
/* @0x25612c mvn r3, #-16777216 */
/* @0x256130 str r3, [sp, #0x44] */
/* @0x256134 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x256138 cmp r0, #1 */
/* @0x25613c beq 0x256308 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x23c> */
/* @0x256140 ldr r2, [sp, #0x38] */
/* @0x256144 cmp r6, r11 */
/* @0x256148 mov r3, #5 */
/* @0x25614c ldr r8, [r2] */
/* @0x256150 str r11, [sp, #0x48] */
/* @0x256154 str r11, [sp, #0x4c] */
/* @0x256158 str r11, [sp, #0x50] */
/* @0x25615c str r3, [sp, #0x54] */
/* @0x256160 ble 0x256328 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x25c> */
/* @0x256164 ldr r3, [r5, #0xc] */
/* @0x256168 bic r3, r3, #-16777216 */
/* @0x25616c cmp r3, #6 */
/* @0x256170 beq 0x256330 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x256174 str r5, [sp] */
/* @0x256178 mov r1, r4 */
/* @0x25617c mov r3, #1 */
/* @0x256180 mov r2, r10 */
/* @0x256184 add r0, sp, #88 */
/* @0x256188 mvn r12, #-16777216 */
/* @0x25618c mov r4, #0 */
/* @0x256190 mov r5, #0 */
/* @0x256194 mov r6, #0 */
/* @0x256198 strd r4, r5, [sp, #88] */
/* @0x25619c str r6, [sp, #0x60] */
/* @0x2561a0 str r12, [sp, #0x64] */
/* @0x2561a4 bl 0x259ea8 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_> */
/* @0x2561a8 ldr r3, [sp, #0x64] */
/* @0x2561ac bic r3, r3, #-16777216 */
/* @0x2561b0 cmp r3, #6 */
/* @0x2561b4 beq 0x256364 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x298> */
/* @0x2561b8 cmp r6, #0 */
/* @0x2561bc mov r2, #0 */
/* @0x2561c0 mov r3, r2 */
/* @0x2561c4 movt r2, #0xbff0 */
/* @0x2561c8 str r3, [r7, #0xc] */
/* @0x2561cc str r2, [r7, #0x4] */
/* @0x2561d0 str r3, [r7] */
/* @0x2561d4 beq 0x256280 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x2561d8 ldr r3, [pc, #0x190] */
/* @0x2561dc mov r0, r8 */
/* @0x2561e0 ldr r10, [pc, #0x18c] */
/* @0x2561e4 mov r4, #0 */
/* @0x2561e8 add r3, pc, r3 */
/* @0x2561ec str r3, [sp, #0x14] */
/* @0x2561f0 bl 0xb6538 <strlen@plt> */
/* @0x2561f4 ldr r3, [pc, #0x17c] */
/* @0x2561f8 add r10, pc, r10 */
/* @0x2561fc add r3, pc, r3 */
/* @0x256200 str r3, [sp, #0x18] */
/* @0x256204 ldr r3, [pc, #0x170] */
/* @0x256208 add r3, pc, r3 */
/* @0x25620c str r3, [sp, #0x1c] */
/* @0x256210 ldr r3, [pc, #0x168] */
/* @0x256214 add r3, pc, r3 */
/* @0x256218 str r3, [sp, #0x20] */
/* @0x25621c ldr r3, [pc, #0x160] */
/* @0x256220 add r3, pc, r3 */
/* @0x256224 str r3, [sp, #0x24] */
/* @0x256228 mov r5, r0 */
/* @0x25622c cmp r5, r4 */
/* @0x256230 mov r2, r8 */
/* @0x256234 mov r3, r5 */
/* @0x256238 mov r1, #0 */
/* @0x25623c add r11, sp, #88 */
/* @0x256240 mov r12, #30 */
/* @0x256244 blt 0x256280 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x256248 ldr lr, [r6, #0x20] */
/* @0x25624c ldr r0, [r6, #0x1c] */
/* @0x256250 str r1, [sp, #0x4] */
/* @0x256254 str r4, [sp] */
/* @0x256258 mov r1, lr */
/* @0x25625c str r11, [sp, #0x8] */
/* @0x256260 str r12, [sp, #0xc] */
/* @0x256264 bl 0x279390 <pcre_exec> */
/* @0x256268 cmp r0, #0 */
/* @0x25626c blt 0x256288 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x1bc> */
/* @0x256270 vldr s15, [sp, #88] */
/* @0x256274 vcvt.f64.s32 d7, s15 */
/* @0x256278 vmov r2, r3, d7 */
/* @0x25627c stm r7, {r2, r3} */
/* @0x256280 add sp, sp, #212 */
/* @0x256284 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x256288 add r0, r0, #6 */
/* @0x25628c cmp r0, #5 */
/* @0x256290 addls pc, pc, r0, lsl #2 */
/* @0x256294 b 0x25631c <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x250> */
/* @0x256298 b 0x2562fc <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x230> */
/* @0x25629c b 0x2562f0 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x224> */
/* @0x2562a0 b 0x2562e4 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x218> */
/* @0x2562a4 b 0x2562d8 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x2562a8 b 0x2562b8 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x1ec> */
/* @0x2562ac b 0x2562b0 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x2562b0 add r4, r4, #1 */
/* @0x2562b4 b 0x25622c <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x2562b8 ldr r3, [pc, #0xc8] */
/* @0x2562bc ldr r1, [sp, #0x24] */
/* @0x2562c0 ldr r3, [r9, r3] */
/* @0x2562c4 ldr r0, [r3] */
/* @0x2562c8 ldr r3, [r0] */
/* @0x2562cc ldr r3, [r3, #0xc] */
/* @0x2562d0 blx r3 */
/* @0x2562d4 b 0x25622c <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x2562d8 ldr r3, [pc, #0xa8] */
/* @0x2562dc ldr r1, [sp, #0x20] */
/* @0x2562e0 b 0x2562c0 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0x2562e4 ldr r3, [pc, #0x9c] */
/* @0x2562e8 ldr r1, [sp, #0x1c] */
/* @0x2562ec b 0x2562c0 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0x2562f0 ldr r3, [pc, #0x90] */
/* @0x2562f4 ldr r1, [sp, #0x18] */
/* @0x2562f8 b 0x2562c0 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0x2562fc ldr r3, [pc, #0x84] */
/* @0x256300 ldr r1, [sp, #0x14] */
/* @0x256304 b 0x2562c0 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0x256308 ldr r0, [pc, #0x7c] */
/* @0x25630c add r0, pc, r0 */
/* @0x256310 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x256314 add sp, sp, #212 */
/* @0x256318 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25631c ldr r3, [pc, #0x64] */
/* @0x256320 mov r1, r10 */
/* @0x256324 b 0x2562c0 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0x256328 add r5, sp, #72 */
/* @0x25632c b 0x256174 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x256330 ldr r6, [r5] */
/* @0x256334 ldr r1, [pc, #0x54] */
/* @0x256338 ldr r0, [r6, #0x40] */
/* @0x25633c add r1, pc, r1 */
/* @0x256340 bl 0xb6574 <strcmp@plt> */
/* @0x256344 cmp r0, #0 */
/* @0x256348 bne 0x256174 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x25634c mov r3, #0 */
/* @0x256350 str r0, [r7, #0xc] */
/* @0x256354 movt r3, #0xbff0 */
/* @0x256358 str r0, [r7] */
/* @0x25635c str r3, [r7, #0x4] */
/* @0x256360 b 0x2561d8 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x256364 ldr r6, [sp, #0x58] */
/* @0x256368 b 0x2561b8 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x25636c andseq r11, r9, r12, asr #22 */
/* @0x256370 andeq pc, pc, r4, lsr pc */
/* @0x256374 andseq r0, r0, r12, asr #15 */
/* @0x256378 andeq pc, pc, r0, lsl #30 */
/* @0x25637c .word 0x000ffed8 */
/* @0x256380 strheq pc, [pc], -r0 */
/* @0x256384 andeq pc, pc, r12, lsl #29 */
/* @0x256388 .word 0xffffbac4 */
/* @0x25638c andeq pc, pc, r12, lsr r12 */
/* @0x256390 .word 0x000ff8f0 */

/* ── FUNC 0x256394 · anon_256394 · size=4 · insn=1 */
/* @0x256394 andeq r0, r0, r0 */

/* ── FUNC 0x256398 · JS_String_prototype_match(RValue&, CInstance*, CInstance*, int, RValue*) · size=852 · insn=211 */
/* @0x256398 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x25639c vpush {d8} */
/* @0x2563a0 sub sp, sp, #164 */
/* @0x2563a4 add r6, sp, #160 */
/* @0x2563a8 mov r5, r1 */
/* @0x2563ac str r0, [sp, #0x14] */
/* @0x2563b0 mov r9, r2 */
/* @0x2563b4 str r1, [r6, #-0x80]! */
/* @0x2563b8 mov r0, r6 */
/* @0x2563bc mov r4, r3 */
/* @0x2563c0 ldr r7, [sp, #0xd0] */
/* @0x2563c4 mov r3, #6 */
/* @0x2563c8 str r3, [sp, #0x2c] */
/* @0x2563cc bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue> */
/* @0x2563d0 cmp r0, #1 */
/* @0x2563d4 beq 0x25648c <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x2563d8 mov r1, r6 */
/* @0x2563dc add r0, sp, #48 */
/* @0x2563e0 add r2, sp, #48 */
/* @0x2563e4 mov r3, #0 */
/* @0x2563e8 str r2, [sp, #0x10] */
/* @0x2563ec mov r6, #0 */
/* @0x2563f0 mov r2, #0 */
/* @0x2563f4 str r6, [sp, #0x38] */
/* @0x2563f8 strd r2, r3, [sp, #48] */
/* @0x2563fc mvn r3, #-16777216 */
/* @0x256400 str r3, [sp, #0x3c] */
/* @0x256404 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x256408 cmp r0, #1 */
/* @0x25640c beq 0x25648c <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x256410 cmp r4, r6 */
/* @0x256414 mov r3, #5 */
/* @0x256418 str r6, [sp, #0x40] */
/* @0x25641c str r6, [sp, #0x44] */
/* @0x256420 str r6, [sp, #0x48] */
/* @0x256424 str r3, [sp, #0x4c] */
/* @0x256428 ble 0x2564a4 <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x25642c ldr r3, [r7, #0xc] */
/* @0x256430 bic r3, r3, #-16777216 */
/* @0x256434 cmp r3, #6 */
/* @0x256438 beq 0x2564ac <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x25643c mov r3, #1 */
/* @0x256440 str r7, [sp] */
/* @0x256444 add r0, sp, #144 */
/* @0x256448 mov r1, r5 */
/* @0x25644c mov r2, r9 */
/* @0x256450 mov r12, #0 */
/* @0x256454 mov r10, #0 */
/* @0x256458 str r12, [sp, #0x98] */
/* @0x25645c mov r11, #0 */
/* @0x256460 mvn r12, #-16777216 */
/* @0x256464 strd r10, r11, [sp, #144] */
/* @0x256468 str r12, [sp, #0x9c] */
/* @0x25646c bl 0x259ea8 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_> */
/* @0x256470 ldr r3, [sp, #0x9c] */
/* @0x256474 bic r3, r3, #-16777216 */
/* @0x256478 cmp r3, #6 */
/* @0x25647c beq 0x2566bc <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0x324> */
/* @0x256480 add sp, sp, #164 */
/* @0x256484 vpop {d8} */
/* @0x256488 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25648c ldr r0, [pc, #0x244] */
/* @0x256490 add r0, pc, r0 */
/* @0x256494 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x256498 add sp, sp, #164 */
/* @0x25649c vpop {d8} */
/* @0x2564a0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2564a4 add r7, sp, #64 */
/* @0x2564a8 b 0x25643c <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x2564ac ldr r4, [r7] */
/* @0x2564b0 ldr r1, [pc, #0x224] */
/* @0x2564b4 ldr r0, [r4, #0x40] */
/* @0x2564b8 add r1, pc, r1 */
/* @0x2564bc bl 0xb6574 <strcmp@plt> */
/* @0x2564c0 cmp r0, r6 */
/* @0x2564c4 bne 0x25643c <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x2564c8 add r8, sp, #80 */
/* @0x2564cc ldr r2, [pc, #0x20c] */
/* @0x2564d0 mov r6, #0 */
/* @0x2564d4 mov r0, r4 */
/* @0x2564d8 add r2, pc, r2 */
/* @0x2564dc mov r1, r8 */
/* @0x2564e0 str r6, [sp, #0x50] */
/* @0x2564e4 str r6, [sp, #0x54] */
/* @0x2564e8 str r6, [sp, #0x58] */
/* @0x2564ec str r6, [sp, #0x5c] */
/* @0x2564f0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x2564f4 mov r0, r8 */
/* @0x2564f8 mov r1, r6 */
/* @0x2564fc bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x256500 cmp r0, r6 */
/* @0x256504 bne 0x256530 <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x256508 add r3, sp, #48 */
/* @0x25650c mov r1, r4 */
/* @0x256510 str r3, [sp] */
/* @0x256514 mov r2, r4 */
/* @0x256518 ldr r0, [sp, #0x14] */
/* @0x25651c mov r3, #1 */
/* @0x256520 bl 0x257248 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_> */
/* @0x256524 add sp, sp, #164 */
/* @0x256528 vpop {d8} */
/* @0x25652c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x256530 vldr d8, [pc, #408] */
/* @0x256534 vmov r2, r3, d8 */
/* @0x256538 add r8, sp, #160 */
/* @0x25653c mov r0, r4 */
/* @0x256540 str r6, [sp, #0x6c] */
/* @0x256544 mov r10, r6 */
/* @0x256548 add r11, sp, #112 */
/* @0x25654c strd r2, r3, [r8, #-64]! */
/* @0x256550 mov r3, r6 */
/* @0x256554 ldr r2, [pc, #0x188] */
/* @0x256558 mov r1, r8 */
/* @0x25655c add r2, pc, r2 */
/* @0x256560 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x256564 mov r1, r5 */
/* @0x256568 mov r2, r9 */
/* @0x25656c mov r3, r6 */
/* @0x256570 str r7, [sp] */
/* @0x256574 mov r5, r6 */
/* @0x256578 ldr r0, [sp, #0x14] */
/* @0x25657c mov r9, r6 */
/* @0x256580 bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_> */
/* @0x256584 mvn r3, #-16777216 */
/* @0x256588 str r3, [sp, #0x7c] */
/* @0x25658c mov r1, #0 */
/* @0x256590 ldr r3, [pc, #0x150] */
/* @0x256594 str r6, [sp, #0x78] */
/* @0x256598 add r3, pc, r3 */
/* @0x25659c str r1, [sp, #0x70] */
/* @0x2565a0 str r1, [sp, #0x18] */
/* @0x2565a4 str r1, [sp, #0x74] */
/* @0x2565a8 str r1, [sp, #0x1c] */
/* @0x2565ac str r3, [sp, #0xc] */
/* @0x2565b0 b 0x25662c <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0x294> */
/* @0x2565b4 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x2565b8 mov r0, r8 */
/* @0x2565bc bl 0xd11b0 <_Z12INT32_RValuePK6RValue> */
/* @0x2565c0 cmp r0, r10 */
/* @0x2565c4 mov r12, r0 */
/* @0x2565c8 beq 0x256688 <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0x2f0> */
/* @0x2565cc ldr r3, [sp, #0x18] */
/* @0x2565d0 mov r1, r7 */
/* @0x2565d4 mov r2, r6 */
/* @0x2565d8 mov r0, r11 */
/* @0x2565dc str r9, [sp, #0x8c] */
/* @0x2565e0 vstr d8, [sp, #128] */
/* @0x2565e4 str r3, [sp, #0x90] */
/* @0x2565e8 mov r10, r12 */
/* @0x2565ec ldr r3, [sp, #0x1c] */
/* @0x2565f0 str r9, [sp, #0x98] */
/* @0x2565f4 str r3, [sp, #0x94] */
/* @0x2565f8 mvn r3, #-16777216 */
/* @0x2565fc str r3, [sp, #0x9c] */
/* @0x256600 bl 0x249cdc <_Z10JSArrayGetP6RValueS0_S0_> */
/* @0x256604 vmov s13, r5 */
/* @0x256608 mov r1, r7 */
/* @0x25660c mov r2, r6 */
/* @0x256610 ldr r0, [sp, #0x14] */
/* @0x256614 vcvt.f64.s32 d7, s13 */
/* @0x256618 mov r3, #7 */
/* @0x25661c add r5, r5, #1 */
/* @0x256620 str r3, [sp, #0x98] */
/* @0x256624 vstr d7, [sp, #128] */
/* @0x256628 bl 0x247c68 <_Z10JSArrayPutP6RValueS0_S0_> */
/* @0x25662c add r2, sp, #48 */
/* @0x256630 mov r0, r11 */
/* @0x256634 str r2, [sp] */
/* @0x256638 mov r1, r4 */
/* @0x25663c mov r2, r4 */
/* @0x256640 mov r3, #1 */
/* @0x256644 bl 0x257248 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_> */
/* @0x256648 ldr r3, [sp, #0x7c] */
/* @0x25664c add r7, sp, #128 */
/* @0x256650 add r6, sp, #144 */
/* @0x256654 bic r3, r3, #-16777216 */
/* @0x256658 mov r1, r8 */
/* @0x25665c cmp r3, #12 */
/* @0x256660 ldr r2, [sp, #0xc] */
/* @0x256664 mov r0, r4 */
/* @0x256668 bne 0x2565b4 <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x25666c cmp r5, #0 */
/* @0x256670 bne 0x256480 <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x256674 ldr r2, [sp, #0x14] */
/* @0x256678 str r3, [r2, #0xc] */
/* @0x25667c add sp, sp, #164 */
/* @0x256680 vpop {d8} */
/* @0x256684 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x256688 add r12, r10, #1 */
/* @0x25668c mov r0, r4 */
/* @0x256690 mov r1, r8 */
/* @0x256694 ldr r2, [sp, #0xc] */
/* @0x256698 vmov s13, r12 */
/* @0x25669c mov r3, #0 */
/* @0x2566a0 str r12, [sp, #0x8] */
/* @0x2566a4 vcvt.f64.s32 d7, s13 */
/* @0x2566a8 str r9, [sp, #0x6c] */
/* @0x2566ac vstr d7, [sp, #96] */
/* @0x2566b0 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x2566b4 ldr r12, [sp, #0x8] */
/* @0x2566b8 b 0x2565cc <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0x234> */
/* @0x2566bc ldr r4, [sp, #0x90] */
/* @0x2566c0 cmp r4, #0 */
/* @0x2566c4 bne 0x2564c8 <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x2566c8 b 0x256480 <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x2566cc nop */
/* @0x2566d8 strheq pc, [pc], -r8 */
/* @0x2566dc andeq pc, pc, r4, ror r7 */
/* @0x2566e0 andeq lr, sp, r0, lsl #20 */
/* @0x2566e4 andeq pc, pc, r4, asr #22 */
/* @0x2566e8 andeq pc, pc, r8, lsl #22 */

/* ── FUNC 0x2566ec · anon_2566ec · size=4 · insn=1 */
/* @0x2566ec nop */

/* ── FUNC 0x2566f0 · SortCompare(RValue*, RValue*, RValue*) · size=148 · insn=37 */
/* @0x2566f0 ldr r3, [r1, #0xc] */
/* @0x2566f4 push {r4, lr} */
/* @0x2566f8 bic r3, r3, #-16777216 */
/* @0x2566fc cmp r3, #5 */
/* @0x256700 sub sp, sp, #32 */
/* @0x256704 mov r4, r2 */
/* @0x256708 moveq r0, #1 */
/* @0x25670c beq 0x256768 <_Z11SortCompareP6RValueS0_S0_+0x78> */
/* @0x256710 ldr r3, [r2, #0xc] */
/* @0x256714 bic r3, r3, #-16777216 */
/* @0x256718 cmp r3, #5 */
/* @0x25671c beq 0x25677c <_Z11SortCompareP6RValueS0_S0_+0x8c> */
/* @0x256720 mov r0, sp */
/* @0x256724 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x256728 cmp r0, #0 */
/* @0x25672c bne 0x256770 <_Z11SortCompareP6RValueS0_S0_+0x80> */
/* @0x256730 mov r1, r4 */
/* @0x256734 add r0, sp, #16 */
/* @0x256738 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x25673c cmp r0, #0 */
/* @0x256740 bne 0x256770 <_Z11SortCompareP6RValueS0_S0_+0x80> */
/* @0x256744 ldr r2, [sp] */
/* @0x256748 ldr r3, [sp, #0x10] */
/* @0x25674c ldr r0, [r2] */
/* @0x256750 ldr r1, [r3] */
/* @0x256754 bl 0xb6574 <strcmp@plt> */
/* @0x256758 cmp r0, #0 */
/* @0x25675c blt 0x25677c <_Z11SortCompareP6RValueS0_S0_+0x8c> */
/* @0x256760 moveq r0, #0 */
/* @0x256764 movne r0, #1 */
/* @0x256768 add sp, sp, #32 */
/* @0x25676c pop {r4, pc} */
/* @0x256770 bl 0x242ebc <_Z9translate9EJSRetVal> */
/* @0x256774 add sp, sp, #32 */
/* @0x256778 pop {r4, pc} */
/* @0x25677c mvn r0, #0 */
/* @0x256780 b 0x256768 <_Z11SortCompareP6RValueS0_S0_+0x78> */

/* ── FUNC 0x256784 · JS_Error_prototype_toString(RValue&, CInstance*, CInstance*, int, RValue*) · size=916 · insn=229 */
/* @0x256784 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x256788 mov r5, r1 */
/* @0x25678c ldr r1, [pc, #0x370] */
/* @0x256790 sub sp, sp, #84 */
/* @0x256794 mov r8, r0 */
/* @0x256798 ldr r0, [r5, #0x40] */
/* @0x25679c add r1, pc, r1 */
/* @0x2567a0 bl 0xb6574 <strcmp@plt> */
/* @0x2567a4 subs r4, r0, #0 */
/* @0x2567a8 bne 0x256960 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x1dc> */
/* @0x2567ac add r7, sp, #16 */
/* @0x2567b0 ldr r2, [pc, #0x350] */
/* @0x2567b4 mov r0, r5 */
/* @0x2567b8 mov r6, #5 */
/* @0x2567bc add r2, pc, r2 */
/* @0x2567c0 mov r1, r7 */
/* @0x2567c4 str r6, [sp, #0x1c] */
/* @0x2567c8 str r6, [sp, #0x2c] */
/* @0x2567cc bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x2567d0 mov r1, r7 */
/* @0x2567d4 add r7, sp, #32 */
/* @0x2567d8 mov r0, r7 */
/* @0x2567dc bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x2567e0 mov r0, r7 */
/* @0x2567e4 mov r1, r4 */
/* @0x2567e8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x2567ec ldr r2, [pc, #0x318] */
/* @0x2567f0 str r6, [sp, #0x3c] */
/* @0x2567f4 add r2, pc, r2 */
/* @0x2567f8 str r6, [sp, #0x4c] */
/* @0x2567fc mov r7, r0 */
/* @0x256800 mov r0, r5 */
/* @0x256804 add r5, sp, #48 */
/* @0x256808 mov r1, r5 */
/* @0x25680c bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x256810 mov r1, r5 */
/* @0x256814 add r5, sp, #64 */
/* @0x256818 mov r0, r5 */
/* @0x25681c bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x256820 mov r0, r5 */
/* @0x256824 mov r1, r4 */
/* @0x256828 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x25682c cmp r7, #0 */
/* @0x256830 str r4, [sp, #0x4] */
/* @0x256834 str r4, [sp, #0x8] */
/* @0x256838 str r4, [sp, #0xc] */
/* @0x25683c mov r5, r0 */
/* @0x256840 beq 0x256850 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x256844 ldrb r3, [r7] */
/* @0x256848 cmp r3, #0 */
/* @0x25684c bne 0x2568e4 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x256850 cmp r5, #0 */
/* @0x256854 beq 0x256958 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x1d4> */
/* @0x256858 mov r0, r5 */
/* @0x25685c bl 0xb6538 <strlen@plt> */
/* @0x256860 adds r3, r0, #1 */
/* @0x256864 mov r4, r0 */
/* @0x256868 movmi r0, #0 */
/* @0x25686c bmi 0x2568a0 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x256870 add r3, r3, r3, lsl #1 */
/* @0x256874 asr r6, r3, #1 */
/* @0x256878 mov r0, r6 */
/* @0x25687c bl 0xcef4c <_Z7YYAlloci> */
/* @0x256880 mov r1, #0 */
/* @0x256884 ldr r2, [sp, #0x8] */
/* @0x256888 str r0, [sp, #0x4] */
/* @0x25688c bl 0xb65bc <memcpy@plt> */
/* @0x256890 ldr r0, [sp, #0x4] */
/* @0x256894 ldr r3, [sp, #0xc] */
/* @0x256898 str r6, [sp, #0x8] */
/* @0x25689c add r0, r0, r3 */
/* @0x2568a0 mov r1, r5 */
/* @0x2568a4 bl 0xb65a4 <strcpy@plt> */
/* @0x2568a8 ldr r3, [sp, #0xc] */
/* @0x2568ac add r4, r4, r3 */
/* @0x2568b0 cmp r4, #0 */
/* @0x2568b4 beq 0x256958 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x1d4> */
/* @0x2568b8 ldr r1, [sp, #0x4] */
/* @0x2568bc mov r0, r8 */
/* @0x2568c0 mov r3, #0 */
/* @0x2568c4 str r3, [sp, #0xc] */
/* @0x2568c8 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x2568cc ldr r0, [sp, #0x4] */
/* @0x2568d0 cmp r0, #0 */
/* @0x2568d4 beq 0x2568dc <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x2568d8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2568dc add sp, sp, #84 */
/* @0x2568e0 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2568e4 cmp r5, #0 */
/* @0x2568e8 mov r0, r7 */
/* @0x2568ec beq 0x2568fc <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x2568f0 ldrb r3, [r5] */
/* @0x2568f4 cmp r3, #0 */
/* @0x2568f8 bne 0x256974 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x1f0> */
/* @0x2568fc bl 0xb6538 <strlen@plt> */
/* @0x256900 adds r3, r0, #1 */
/* @0x256904 mov r4, r0 */
/* @0x256908 movmi r0, #0 */
/* @0x25690c bmi 0x256940 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x1bc> */
/* @0x256910 add r3, r3, r3, lsl #1 */
/* @0x256914 asr r5, r3, #1 */
/* @0x256918 mov r0, r5 */
/* @0x25691c bl 0xcef4c <_Z7YYAlloci> */
/* @0x256920 mov r1, #0 */
/* @0x256924 ldr r2, [sp, #0x8] */
/* @0x256928 str r0, [sp, #0x4] */
/* @0x25692c bl 0xb65bc <memcpy@plt> */
/* @0x256930 ldr r0, [sp, #0x4] */
/* @0x256934 ldr r3, [sp, #0xc] */
/* @0x256938 str r5, [sp, #0x8] */
/* @0x25693c add r0, r0, r3 */
/* @0x256940 mov r1, r7 */
/* @0x256944 bl 0xb65a4 <strcpy@plt> */
/* @0x256948 ldr r3, [sp, #0xc] */
/* @0x25694c add r4, r4, r3 */
/* @0x256950 cmp r4, #0 */
/* @0x256954 bne 0x2568b8 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x256958 add r1, sp, #12 */
/* @0x25695c b 0x2568bc <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x256960 ldr r0, [pc, #0x1a8] */
/* @0x256964 add r0, pc, r0 */
/* @0x256968 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25696c add sp, sp, #84 */
/* @0x256970 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x256974 bl 0xb6538 <strlen@plt> */
/* @0x256978 adds r3, r0, #1 */
/* @0x25697c mov r6, r0 */
/* @0x256980 movmi r0, r4 */
/* @0x256984 bmi 0x2569b8 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x234> */
/* @0x256988 add r3, r3, r3, lsl #1 */
/* @0x25698c asr r9, r3, #1 */
/* @0x256990 mov r0, r9 */
/* @0x256994 bl 0xcef4c <_Z7YYAlloci> */
/* @0x256998 mov r1, r4 */
/* @0x25699c ldr r2, [sp, #0x8] */
/* @0x2569a0 str r0, [sp, #0x4] */
/* @0x2569a4 bl 0xb65bc <memcpy@plt> */
/* @0x2569a8 ldr r0, [sp, #0x4] */
/* @0x2569ac ldr r3, [sp, #0xc] */
/* @0x2569b0 str r9, [sp, #0x8] */
/* @0x2569b4 add r0, r0, r3 */
/* @0x2569b8 mov r1, r7 */
/* @0x2569bc bl 0xb65a4 <strcpy@plt> */
/* @0x2569c0 ldr r3, [sp, #0xc] */
/* @0x2569c4 ldr r2, [sp, #0x8] */
/* @0x2569c8 add r3, r6, r3 */
/* @0x2569cc str r3, [sp, #0xc] */
/* @0x2569d0 mvn r1, r3 */
/* @0x2569d4 add r1, r2, r1 */
/* @0x2569d8 cmp r1, #2 */
/* @0x2569dc bgt 0x256a3c <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x2b8> */
/* @0x2569e0 cmp r2, #0 */
/* @0x2569e4 add r3, r3, #3 */
/* @0x2569e8 addne r2, r2, r2, lsl #1 */
/* @0x2569ec ldr r6, [sp, #0x4] */
/* @0x2569f0 moveq r4, #4 */
/* @0x2569f4 addne r2, r2, r2, lsr #31 */
/* @0x2569f8 asrne r4, r2, #1 */
/* @0x2569fc cmp r3, r4 */
/* @0x256a00 addgt r3, r3, r3, lsl #1 */
/* @0x256a04 addgt r3, r3, r3, lsr #31 */
/* @0x256a08 asrgt r4, r3, #1 */
/* @0x256a0c mov r0, r4 */
/* @0x256a10 bl 0xcef4c <_Z7YYAlloci> */
/* @0x256a14 ldr r2, [sp, #0x8] */
/* @0x256a18 mov r1, r6 */
/* @0x256a1c str r0, [sp, #0x4] */
/* @0x256a20 bl 0xb65bc <memcpy@plt> */
/* @0x256a24 cmp r6, #0 */
/* @0x256a28 str r4, [sp, #0x8] */
/* @0x256a2c beq 0x256a38 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x2b4> */
/* @0x256a30 mov r0, r6 */
/* @0x256a34 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x256a38 ldr r3, [sp, #0xc] */
/* @0x256a3c ldr r1, [pc, #0xd0] */
/* @0x256a40 mov r0, r5 */
/* @0x256a44 ldr r2, [sp, #0x4] */
/* @0x256a48 add r1, pc, r1 */
/* @0x256a4c add r12, r2, r3 */
/* @0x256a50 ldrh lr, [r1] */
/* @0x256a54 ldrb r1, [r1, #0x2] */
/* @0x256a58 strh lr, [r2, r3] */
/* @0x256a5c strb r1, [r12, #0x2] */
/* @0x256a60 ldr r6, [sp, #0xc] */
/* @0x256a64 add r6, r6, #2 */
/* @0x256a68 str r6, [sp, #0xc] */
/* @0x256a6c bl 0xb6538 <strlen@plt> */
/* @0x256a70 ldr r3, [sp, #0x8] */
/* @0x256a74 mvn r1, r6 */
/* @0x256a78 add r1, r3, r1 */
/* @0x256a7c add r2, r0, #1 */
/* @0x256a80 mov r4, r0 */
/* @0x256a84 cmp r2, r1 */
/* @0x256a88 ble 0x256ae8 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x364> */
/* @0x256a8c cmp r3, #0 */
/* @0x256a90 moveq r3, r2 */
/* @0x256a94 add r2, r6, r2 */
/* @0x256a98 add r3, r3, r3, lsl #1 */
/* @0x256a9c ldr r6, [sp, #0x4] */
/* @0x256aa0 add r3, r3, r3, lsr #31 */
/* @0x256aa4 asr r7, r3, #1 */
/* @0x256aa8 cmp r7, r2 */
/* @0x256aac addlt r2, r2, r2, lsl #1 */
/* @0x256ab0 addlt r2, r2, r2, lsr #31 */
/* @0x256ab4 asrlt r7, r2, #1 */
/* @0x256ab8 mov r0, r7 */
/* @0x256abc bl 0xcef4c <_Z7YYAlloci> */
/* @0x256ac0 ldr r2, [sp, #0x8] */
/* @0x256ac4 mov r1, r6 */
/* @0x256ac8 str r0, [sp, #0x4] */
/* @0x256acc bl 0xb65bc <memcpy@plt> */
/* @0x256ad0 cmp r6, #0 */
/* @0x256ad4 str r7, [sp, #0x8] */
/* @0x256ad8 beq 0x256ae4 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x360> */
/* @0x256adc mov r0, r6 */
/* @0x256ae0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x256ae4 ldr r6, [sp, #0xc] */
/* @0x256ae8 ldr r0, [sp, #0x4] */
/* @0x256aec mov r1, r5 */
/* @0x256af0 add r0, r0, r6 */
/* @0x256af4 bl 0xb65a4 <strcpy@plt> */
/* @0x256af8 ldr r3, [sp, #0xc] */
/* @0x256afc add r4, r4, r3 */
/* @0x256b00 b 0x2568b0 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x256b04 andeq pc, pc, r8, lsl #3 */
/* @0x256b08 andeq r10, sp, r12, asr #32 */
/* @0x256b0c muleq pc, r0, pc */
/* @0x256b10 andeq pc, pc, r4, ror #11 */
/* @0x256b14 andeq r9, lr, r12, ror #17 */

/* ── FUNC 0x256b18 · JS_Number_Prototype_toString(RValue&, CInstance*, CInstance*, int, RValue*) · size=860 · insn=215 */
/* @0x256b18 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x256b1c vpush {d8, d9, d10} */
/* @0x256b20 mov r6, r1 */
/* @0x256b24 ldr r7, [pc, #0x31c] */
/* @0x256b28 sub sp, sp, #2592 */
/* @0x256b2c ldr r1, [pc, #0x318] */
/* @0x256b30 sub sp, sp, #12 */
/* @0x256b34 ldr r7, [pc, r7] */
/* @0x256b38 mov r8, r0 */
/* @0x256b3c add r1, pc, r1 */
/* @0x256b40 ldr r0, [r6, #0x40] */
/* @0x256b44 ldr r2, [r7] */
/* @0x256b48 mov r4, r3 */
/* @0x256b4c ldr r5, [sp, #0xa68] */
/* @0x256b50 str r2, [sp, #0xa24] */
/* @0x256b54 bl 0xb6574 <strcmp@plt> */
/* @0x256b58 subs r3, r0, #0 */
/* @0x256b5c bne 0x256ba4 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x256b60 cmp r4, #1 */
/* @0x256b64 beq 0x256bb4 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x256b68 ldr r1, [pc, #0x2e0] */
/* @0x256b6c mov r0, r6 */
/* @0x256b70 add r1, pc, r1 */
/* @0x256b74 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0x256b78 mov r1, r0 */
/* @0x256b7c mov r0, r8 */
/* @0x256b80 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x256b84 ldr r2, [sp, #0xa24] */
/* @0x256b88 ldr r3, [r7] */
/* @0x256b8c cmp r2, r3 */
/* @0x256b90 bne 0x256e44 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x32c> */
/* @0x256b94 add sp, sp, #2592 */
/* @0x256b98 add sp, sp, #12 */
/* @0x256b9c vpop {d8, d9, d10} */
/* @0x256ba0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x256ba4 ldr r0, [pc, #0x2a8] */
/* @0x256ba8 add r0, pc, r0 */
/* @0x256bac bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x256bb0 b 0x256b84 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x256bb4 ldr r2, [r5, #0xc] */
/* @0x256bb8 bic r2, r2, #-16777216 */
/* @0x256bbc cmp r2, #5 */
/* @0x256bc0 beq 0x256b68 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x256bc4 mov r0, r5 */
/* @0x256bc8 str r3, [sp, #0x4] */
/* @0x256bcc bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue> */
/* @0x256bd0 ldr r3, [sp, #0x4] */
/* @0x256bd4 vmov d7, r0, r1 */
/* @0x256bd8 vcvt.s32.f64 s15, d7 */
/* @0x256bdc vmov r1, s15 */
/* @0x256be0 vstr s15, [sp, #8] */
/* @0x256be4 cmp r1, #10 */
/* @0x256be8 beq 0x256b68 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x256bec ldr r1, [sp, #0x8] */
/* @0x256bf0 sub r2, r1, #2 */
/* @0x256bf4 cmp r2, #34 */
/* @0x256bf8 bls 0x256c0c <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x256bfc ldr r0, [pc, #0x254] */
/* @0x256c00 add r0, pc, r0 */
/* @0x256c04 bl 0x253ea4 <_Z17JSThrowRangeErrorPKc> */
/* @0x256c08 b 0x256b84 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x256c0c ldr r11, [pc, #0x248] */
/* @0x256c10 add r9, sp, #36 */
/* @0x256c14 mov r1, r3 */
/* @0x256c18 mov r2, #1280 */
/* @0x256c1c add r11, pc, r11 */
/* @0x256c20 mov r0, r9 */
/* @0x256c24 bl 0xb65b0 <memset@plt> */
/* @0x256c28 mov r0, r6 */
/* @0x256c2c mov r1, r11 */
/* @0x256c30 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0x256c34 ldm r0, {r4, r5} */
/* @0x256c38 vmov d6, r4, r5 */
/* @0x256c3c vmov d7, r4, r5 */
/* @0x256c40 vcmp.f64 d6, d7 */
/* @0x256c44 vmrs APSR_nzcv, fpscr */
/* @0x256c48 bvs 0x256e30 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x318> */
/* @0x256c4c mov r1, r11 */
/* @0x256c50 mov r0, r6 */
/* @0x256c54 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0x256c58 bl 0x240970 <_Z7yyisinfR6RValue> */
/* @0x256c5c cmp r0, #0 */
/* @0x256c60 beq 0x256c80 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x256c64 mov r1, r11 */
/* @0x256c68 mov r0, r6 */
/* @0x256c6c bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0x256c70 mov r1, r0 */
/* @0x256c74 mov r0, r8 */
/* @0x256c78 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x256c7c b 0x256b84 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x256c80 add r11, sp, #24 */
/* @0x256c84 mov r0, r4 */
/* @0x256c88 sub r4, r11, #8 */
/* @0x256c8c mov r1, r5 */
/* @0x256c90 mov r2, r4 */
/* @0x256c94 bl 0xb6718 <modf@plt> */
/* @0x256c98 vldr d8, [r11, #-8] */
/* @0x256c9c vcmpe.f64 d8, #0 */
/* @0x256ca0 vmrs APSR_nzcv, fpscr */
/* @0x256ca4 vnegmi.f64 d8, d8 */
/* @0x256ca8 movmi r3, #45 */
/* @0x256cac vcmp.f64 d8, #0 */
/* @0x256cb0 vstrmi d8, [r11, #-8] */
/* @0x256cb4 vmov d10, r0, r1 */
/* @0x256cb8 strhmi r3, [r9] */
/* @0x256cbc mov r0, r9 */
/* @0x256cc0 vmrs APSR_nzcv, fpscr */
/* @0x256cc4 beq 0x256d84 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x256cc8 vldr s15, [sp, #8] */
/* @0x256ccc vcvt.f64.s32 d9, s15 */
/* @0x256cd0 bl 0xb6538 <strlen@plt> */
/* @0x256cd4 ldr r6, [pc, #0x184] */
/* @0x256cd8 add r1, sp, #1312 */
/* @0x256cdc mov r10, #0 */
/* @0x256ce0 add r1, r1, #8 */
/* @0x256ce4 add r6, pc, r6 */
/* @0x256ce8 sub r4, r1, #5 */
/* @0x256cec str r1, [sp, #0xc] */
/* @0x256cf0 add r5, r9, r0 */
/* @0x256cf4 vmov r2, r3, d9 */
/* @0x256cf8 add r10, r10, #1 */
/* @0x256cfc vmov r0, r1, d8 */
/* @0x256d00 bl 0xb66ac <fmod@plt> */
/* @0x256d04 vdiv.f64 d7, d8, d9 */
/* @0x256d08 vmov d6, r0, r1 */
/* @0x256d0c vcvt.s32.f64 s13, d6 */
/* @0x256d10 vmov r0, s13 */
/* @0x256d14 add r3, r6, r0 */
/* @0x256d18 vmov r0, r1, d7 */
/* @0x256d1c ldrb r3, [r3, #0x85c] */
/* @0x256d20 strb r3, [r4, #0x1]! */
/* @0x256d24 bl 0xb6598 <floor@plt> */
/* @0x256d28 vmov d8, r0, r1 */
/* @0x256d2c vcmpe.f64 d8, #0 */
/* @0x256d30 vmrs APSR_nzcv, fpscr */
/* @0x256d34 bgt 0x256cf4 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x1dc> */
/* @0x256d38 add r1, sp, #1312 */
/* @0x256d3c mov r3, #0 */
/* @0x256d40 add r1, r1, #8 */
/* @0x256d44 sub r2, r1, #4 */
/* @0x256d48 add r2, r2, r10 */
/* @0x256d4c ldrb r1, [r2, #-0x1]! */
/* @0x256d50 strb r1, [r5, r3] */
/* @0x256d54 add r3, r3, #1 */
/* @0x256d58 cmp r3, r10 */
/* @0x256d5c blt 0x256d4c <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x234> */
/* @0x256d60 mov r3, #0 */
/* @0x256d64 strb r3, [r5, r10] */
/* @0x256d68 vcmp.f64 d10, #0 */
/* @0x256d6c vmrs APSR_nzcv, fpscr */
/* @0x256d70 bne 0x256d9c <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x284> */
/* @0x256d74 mov r0, r8 */
/* @0x256d78 mov r1, r9 */
/* @0x256d7c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x256d80 b 0x256b84 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x256d84 bl 0xb6538 <strlen@plt> */
/* @0x256d88 ldr r3, [pc, #0xd4] */
/* @0x256d8c add r3, pc, r3 */
/* @0x256d90 ldrh r3, [r3] */
/* @0x256d94 strh r3, [r9, r0] */
/* @0x256d98 b 0x256d68 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x250> */
/* @0x256d9c mov r0, r9 */
/* @0x256da0 bl 0xb6538 <strlen@plt> */
/* @0x256da4 ldr r3, [pc, #0xbc] */
/* @0x256da8 vcmpe.f64 d10, #0 */
/* @0x256dac add r3, pc, r3 */
/* @0x256db0 ldrh r3, [r3] */
/* @0x256db4 vmrs APSR_nzcv, fpscr */
/* @0x256db8 add r6, r0, #1 */
/* @0x256dbc strh r3, [r9, r0] */
/* @0x256dc0 add r6, r9, r6 */
/* @0x256dc4 ble 0x256e28 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x310> */
/* @0x256dc8 vldr s12, [sp, #8] */
/* @0x256dcc vcvt.f64.s32 d8, s12 */
/* @0x256dd0 ldr r10, [pc, #0x94] */
/* @0x256dd4 sub r5, r6, #1 */
/* @0x256dd8 mov r4, #0 */
/* @0x256ddc add r10, pc, r10 */
/* @0x256de0 mov r2, r11 */
/* @0x256de4 add r4, r4, #1 */
/* @0x256de8 vmul.f64 d7, d10, d8 */
/* @0x256dec vmov r0, r1, d7 */
/* @0x256df0 bl 0xb6718 <modf@plt> */
/* @0x256df4 vldr d7, [r11] */
/* @0x256df8 vcvt.s32.f64 s12, d7 */
/* @0x256dfc vmov r3, s12 */
/* @0x256e00 add r3, r10, r3 */
/* @0x256e04 ldrb r3, [r3, #0x85c] */
/* @0x256e08 vmov d10, r0, r1 */
/* @0x256e0c strb r3, [r5, #0x1]! */
/* @0x256e10 vcmpe.f64 d10, #0 */
/* @0x256e14 vmrs APSR_nzcv, fpscr */
/* @0x256e18 bgt 0x256de0 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x2c8> */
/* @0x256e1c mov r3, #0 */
/* @0x256e20 strb r3, [r6, r4] */
/* @0x256e24 b 0x256d74 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x25c> */
/* @0x256e28 mov r4, #0 */
/* @0x256e2c b 0x256e1c <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x304> */
/* @0x256e30 ldr r1, [pc, #0x38] */
/* @0x256e34 mov r0, r8 */
/* @0x256e38 add r1, pc, r1 */
/* @0x256e3c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x256e40 b 0x256b84 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x256e44 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x256e48 andseq r6, r9, r12, lsl lr */
/* @0x256e4c andeq lr, pc, r4, asr lr */
/* @0x256e50 andeq lr, pc, r0, lsr #19 */
/* @0x256e54 andeq pc, pc, r12, lsr #28 */
/* @0x256e58 andeq pc, pc, r4, lsr #28 */
/* @0x256e5c strdeq lr, pc, [pc], -r4 */
/* @0x256e60 andseq r6, r2, r12, lsr #4 */
/* @0x256e64 andeq r11, sp, r0, ror #14 */
/* @0x256e68 muleq lr, r0, r5 */
/* @0x256e6c andseq r6, r2, r4, lsr r1 */
/* @0x256e70 strheq r11, [sp], -r12 */

/* ── FUNC 0x256e74 · JS_Number_Prototype_toLocaleString(RValue&, CInstance*, CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x256e74 push {r3, r4, r5, lr} */
/* @0x256e78 mov r4, r1 */
/* @0x256e7c ldr r1, [pc, #0x44] */
/* @0x256e80 mov r5, r0 */
/* @0x256e84 ldr r0, [r4, #0x40] */
/* @0x256e88 add r1, pc, r1 */
/* @0x256e8c bl 0xb6574 <strcmp@plt> */
/* @0x256e90 cmp r0, #0 */
/* @0x256e94 bne 0x256eb8 <_Z34JS_Number_Prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x256e98 ldr r1, [pc, #0x2c] */
/* @0x256e9c mov r0, r4 */
/* @0x256ea0 add r1, pc, r1 */
/* @0x256ea4 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0x256ea8 mov r1, r0 */
/* @0x256eac mov r0, r5 */
/* @0x256eb0 pop {r3, r4, r5, lr} */
/* @0x256eb4 b 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x256eb8 ldr r0, [pc, #0x10] */
/* @0x256ebc pop {r3, r4, r5, lr} */
/* @0x256ec0 add r0, pc, r0 */
/* @0x256ec4 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x256ec8 andeq lr, pc, r8, lsl #22 */
/* @0x256ecc andeq lr, pc, r0, ror r6 */
/* @0x256ed0 andeq pc, pc, r8, lsl #1 */

/* ── FUNC 0x256ed4 · anon_256ed4 · size=4 · insn=1 */
/* @0x256ed4 andeq r0, r0, r0 */

/* ── FUNC 0x256ed8 · JS_Number_Prototype_toFixed(RValue&, CInstance*, CInstance*, int, RValue*) · size=364 · insn=89 */
/* @0x256ed8 push {r4, r5, r6, r7, r8, r11, lr} */
/* @0x256edc vpush {d8} */
/* @0x256ee0 add r11, sp, #32 */
/* @0x256ee4 ldr r6, [pc, #0x144] */
/* @0x256ee8 sub sp, sp, #36 */
/* @0x256eec cmp r3, #0 */
/* @0x256ef0 ldr r6, [pc, r6] */
/* @0x256ef4 mov r7, r0 */
/* @0x256ef8 mov r4, r1 */
/* @0x256efc ldr r0, [r11, #0x4] */
/* @0x256f00 ldr r3, [r6] */
/* @0x256f04 str r3, [r11, #-0x28] */
/* @0x256f08 ble 0x256f64 <_Z27JS_Number_Prototype_toFixedR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x256f0c bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue> */
/* @0x256f10 vmov d8, r0, r1 */
/* @0x256f14 vcmpe.f64 d8, #0 */
/* @0x256f18 vmrs APSR_nzcv, fpscr */
/* @0x256f1c bmi 0x256f30 <_Z27JS_Number_Prototype_toFixedR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x256f20 vmov.f64 d7, #2.000000e+01 */
/* @0x256f24 vcmpe.f64 d8, d7 */
/* @0x256f28 vmrs APSR_nzcv, fpscr */
/* @0x256f2c ble 0x256f68 <_Z27JS_Number_Prototype_toFixedR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x256f30 vcmp.f64 d8, d8 */
/* @0x256f34 vmrs APSR_nzcv, fpscr */
/* @0x256f38 bvs 0x256f68 <_Z27JS_Number_Prototype_toFixedR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x256f3c ldr r0, [pc, #0xf0] */
/* @0x256f40 add r0, pc, r0 */
/* @0x256f44 bl 0x253ea4 <_Z17JSThrowRangeErrorPKc> */
/* @0x256f48 ldr r2, [r11, #-0x28] */
/* @0x256f4c ldr r3, [r6] */
/* @0x256f50 cmp r2, r3 */
/* @0x256f54 bne 0x25701c <_Z27JS_Number_Prototype_toFixedR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x256f58 sub sp, r11, #32 */
/* @0x256f5c vpop {d8} */
/* @0x256f60 pop {r4, r5, r6, r7, r8, r11, pc} */
/* @0x256f64 vldr d8, [pc, #180] */
/* @0x256f68 ldr r1, [pc, #0xc8] */
/* @0x256f6c mov r0, r4 */
/* @0x256f70 mov r8, #0 */
/* @0x256f74 str r8, [r11, #-0x2c] */
/* @0x256f78 add r1, pc, r1 */
/* @0x256f7c bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0x256f80 ldm r0, {r4, r5} */
/* @0x256f84 vmov d6, r4, r5 */
/* @0x256f88 str r4, [r11, #-0x38] */
/* @0x256f8c str r5, [r11, #-0x34] */
/* @0x256f90 vmov d7, r4, r5 */
/* @0x256f94 vcmp.f64 d6, d7 */
/* @0x256f98 vmrs APSR_nzcv, fpscr */
/* @0x256f9c bvs 0x257008 <_Z27JS_Number_Prototype_toFixedR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x256fa0 sub sp, sp, #264 */
/* @0x256fa4 mov r1, r8 */
/* @0x256fa8 add r8, sp, #8 */
/* @0x256fac mov r2, #256 */
/* @0x256fb0 mov r0, r8 */
/* @0x256fb4 bl 0xb65b0 <memset@plt> */
/* @0x256fb8 vmov d6, r4, r5 */
/* @0x256fbc vldr d7, [pc, #100] */
/* @0x256fc0 vcmpe.f64 d6, d7 */
/* @0x256fc4 vmrs APSR_nzcv, fpscr */
/* @0x256fc8 blt 0x256fdc <_Z27JS_Number_Prototype_toFixedR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x256fcc mov r0, r7 */
/* @0x256fd0 sub r1, r11, #56 */
/* @0x256fd4 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x256fd8 b 0x256f48 <_Z27JS_Number_Prototype_toFixedR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x256fdc vcvt.s32.f64 s13, d8 */
/* @0x256fe0 ldr r1, [pc, #0x54] */
/* @0x256fe4 strd r4, r5, [sp] */
/* @0x256fe8 mov r0, r8 */
/* @0x256fec add r1, pc, r1 */
/* @0x256ff0 vmov r2, s13 */
/* @0x256ff4 bl 0xb6550 <sprintf@plt> */
/* @0x256ff8 mov r0, r7 */
/* @0x256ffc mov r1, r8 */
/* @0x257000 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x257004 b 0x256f48 <_Z27JS_Number_Prototype_toFixedR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x257008 ldr r1, [pc, #0x30] */
/* @0x25700c mov r0, r7 */
/* @0x257010 add r1, pc, r1 */
/* @0x257014 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x257018 b 0x256f48 <_Z27JS_Number_Prototype_toFixedR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x25701c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x257028 usatle lr, #0x2, r0, asr #30 */
/* @0x25702c strbmi r1, [r11], #-2788 */
/* @0x257030 andseq r6, r9, r0, ror #20 */
/* @0x257034 andeq pc, pc, r8, lsr #22 */
/* @0x257038 muleq pc, r8, r5 */
/* @0x25703c andeq pc, pc, r0, asr #21 */
/* @0x257040 andeq r11, sp, r4, ror #9 */

/* ── FUNC 0x257044 · anon_257044 · size=4 · insn=1 */
/* @0x257044 nop */

/* ── FUNC 0x257048 · JS_Number_Prototype_toPrecision(RValue&, CInstance*, CInstance*, int, RValue*) · size=512 · insn=128 */
/* @0x257048 push {r4, r5, r6, r7, r8, r11, lr} */
/* @0x25704c vpush {d8, d9} */
/* @0x257050 add r11, sp, #40 */
/* @0x257054 ldr r6, [pc, #0x1d0] */
/* @0x257058 sub sp, sp, #36 */
/* @0x25705c cmp r3, #0 */
/* @0x257060 ldr r6, [pc, r6] */
/* @0x257064 mov r8, r0 */
/* @0x257068 mov r4, r1 */
/* @0x25706c ldr r0, [r11, #0x4] */
/* @0x257070 ldr r3, [r6] */
/* @0x257074 str r3, [r11, #-0x30] */
/* @0x257078 ble 0x2571a0 <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x25707c ldr r3, [r0, #0xc] */
/* @0x257080 bic r3, r3, #-16777216 */
/* @0x257084 cmp r3, #5 */
/* @0x257088 beq 0x2571a0 <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x25708c bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue> */
/* @0x257090 vmov.f64 d7, #1.000000e+00 */
/* @0x257094 vmov d8, r0, r1 */
/* @0x257098 vcmpe.f64 d8, d7 */
/* @0x25709c vmrs APSR_nzcv, fpscr */
/* @0x2570a0 bmi 0x257178 <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x2570a4 vmov.f64 d7, #2.000000e+01 */
/* @0x2570a8 vcmpe.f64 d8, d7 */
/* @0x2570ac vmrs APSR_nzcv, fpscr */
/* @0x2570b0 bgt 0x257178 <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x2570b4 ldr r1, [pc, #0x174] */
/* @0x2570b8 mov r0, r4 */
/* @0x2570bc mov r7, #0 */
/* @0x2570c0 str r7, [r11, #-0x34] */
/* @0x2570c4 add r1, pc, r1 */
/* @0x2570c8 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0x2570cc ldm r0, {r4, r5} */
/* @0x2570d0 vmov d6, r4, r5 */
/* @0x2570d4 str r4, [r11, #-0x40] */
/* @0x2570d8 str r5, [r11, #-0x3c] */
/* @0x2570dc vmov d7, r4, r5 */
/* @0x2570e0 vcmp.f64 d6, d7 */
/* @0x2570e4 vmrs APSR_nzcv, fpscr */
/* @0x2570e8 bvs 0x2571e8 <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x2570ec sub sp, sp, #264 */
/* @0x2570f0 mov r1, r7 */
/* @0x2570f4 add r7, sp, #8 */
/* @0x2570f8 mov r2, #256 */
/* @0x2570fc mov r0, r7 */
/* @0x257100 bl 0xb65b0 <memset@plt> */
/* @0x257104 vcvt.s32.f64 s12, d8 */
/* @0x257108 ldr r1, [pc, #0x124] */
/* @0x25710c mov r0, r7 */
/* @0x257110 strd r4, r5, [sp] */
/* @0x257114 add r1, pc, r1 */
/* @0x257118 vmov r2, s12 */
/* @0x25711c bl 0xb6550 <sprintf@plt> */
/* @0x257120 mov r0, r7 */
/* @0x257124 bl 0xb6538 <strlen@plt> */
/* @0x257128 vmov s13, r0 */
/* @0x25712c vcvt.f64.u32 d9, s13 */
/* @0x257130 vcmpe.f64 d8, d9 */
/* @0x257134 vmrs APSR_nzcv, fpscr */
/* @0x257138 ble 0x257150 <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x25713c mov r0, r7 */
/* @0x257140 mov r1, #46 */
/* @0x257144 bl 0xb6634 <strchr@plt> */
/* @0x257148 cmp r0, #0 */
/* @0x25714c beq 0x2571fc <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x257150 mov r0, r8 */
/* @0x257154 mov r1, r7 */
/* @0x257158 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x25715c ldr r2, [r11, #-0x30] */
/* @0x257160 ldr r3, [r6] */
/* @0x257164 cmp r2, r3 */
/* @0x257168 bne 0x257228 <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x25716c sub sp, r11, #40 */
/* @0x257170 vpop {d8, d9} */
/* @0x257174 pop {r4, r5, r6, r7, r8, r11, pc} */
/* @0x257178 vcmp.f64 d8, d8 */
/* @0x25717c vmrs APSR_nzcv, fpscr */
/* @0x257180 movvs r3, #0 */
/* @0x257184 movvc r3, #1 */
/* @0x257188 cmp r3, #0 */
/* @0x25718c beq 0x2570b4 <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x257190 ldr r0, [pc, #0xa0] */
/* @0x257194 add r0, pc, r0 */
/* @0x257198 bl 0x253ea4 <_Z17JSThrowRangeErrorPKc> */
/* @0x25719c b 0x25715c <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x2571a0 ldr r1, [pc, #0x94] */
/* @0x2571a4 mov r0, r4 */
/* @0x2571a8 mov r3, #0 */
/* @0x2571ac str r3, [r11, #-0x34] */
/* @0x2571b0 add r1, pc, r1 */
/* @0x2571b4 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0x2571b8 ldm r0, {r2, r3} */
/* @0x2571bc vmov d6, r2, r3 */
/* @0x2571c0 str r2, [r11, #-0x40] */
/* @0x2571c4 str r3, [r11, #-0x3c] */
/* @0x2571c8 vmov d7, r2, r3 */
/* @0x2571cc vcmp.f64 d6, d7 */
/* @0x2571d0 vmrs APSR_nzcv, fpscr */
/* @0x2571d4 bvs 0x2571e8 <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x2571d8 mov r0, r8 */
/* @0x2571dc sub r1, r11, #64 */
/* @0x2571e0 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x2571e4 b 0x25715c <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x2571e8 ldr r1, [pc, #0x50] */
/* @0x2571ec mov r0, r8 */
/* @0x2571f0 add r1, pc, r1 */
/* @0x2571f4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x2571f8 b 0x25715c <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x2571fc vsub.f64 d8, d8, d9 */
/* @0x257200 ldr r2, [r11, #-0x40] */
/* @0x257204 ldr r3, [r11, #-0x3c] */
/* @0x257208 mov r0, r7 */
/* @0x25720c ldr r1, [pc, #0x30] */
/* @0x257210 strd r2, r3, [sp] */
/* @0x257214 add r1, pc, r1 */
/* @0x257218 vcvt.s32.f64 s14, d8 */
/* @0x25721c vmov r2, s14 */
/* @0x257220 bl 0xb6550 <sprintf@plt> */
/* @0x257224 b 0x257150 <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x257228 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x25722c ldrsheq r6, [r9], -r0 */
/* @0x257230 andeq lr, pc, r12, asr #8 */
/* @0x257234 andeq pc, pc, r8, ror #19 */
/* @0x257238 andeq pc, pc, r0, lsr #18 */
/* @0x25723c andeq lr, pc, r0, ror #6 */
/* @0x257240 andeq r11, sp, r4, lsl #6 */
/* @0x257244 muleq pc, r8, r8 */

/* ── FUNC 0x257248 · JS_RegExp_prototype_exec(RValue&, CInstance*, CInstance*, int, RValue*) · size=1140 · insn=285 */
/* @0x257248 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x25724c mov r8, r1 */
/* @0x257250 ldr r1, [pc, #0x41c] */
/* @0x257254 sub sp, sp, #548 */
/* @0x257258 mov r9, r0 */
/* @0x25725c ldr r0, [r8, #0x40] */
/* @0x257260 add r1, pc, r1 */
/* @0x257264 str r2, [sp, #0x18] */
/* @0x257268 bl 0xb6574 <strcmp@plt> */
/* @0x25726c ldr r6, [pc, #0x404] */
/* @0x257270 add r6, pc, r6 */
/* @0x257274 str r6, [sp, #0x10] */
/* @0x257278 subs r5, r0, #0 */
/* @0x25727c beq 0x257294 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x257280 ldr r0, [pc, #0x3f4] */
/* @0x257284 add r0, pc, r0 */
/* @0x257288 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25728c add sp, sp, #548 */
/* @0x257290 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x257294 add r4, sp, #64 */
/* @0x257298 movw r12, #0xfe20 */
/* @0x25729c add r10, sp, #544 */
/* @0x2572a0 movt r12, #0xffff */
/* @0x2572a4 ldr r1, [sp, #0x248] */
/* @0x2572a8 mov r0, r4 */
/* @0x2572ac mov r2, #0 */
/* @0x2572b0 mov r3, #0 */
/* @0x2572b4 mvn lr, #-16777216 */
/* @0x2572b8 str r5, [sp, #0x48] */
/* @0x2572bc strd r2, r3, [r10, r12] */
/* @0x2572c0 str lr, [sp, #0x4c] */
/* @0x2572c4 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x2572c8 cmp r0, #2 */
/* @0x2572cc beq 0x25728c <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x2572d0 cmp r0, #1 */
/* @0x2572d4 beq 0x257660 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x418> */
/* @0x2572d8 mov r1, r5 */
/* @0x2572dc mov r0, r4 */
/* @0x2572e0 add r11, sp, #80 */
/* @0x2572e4 str r11, [sp, #0x1c] */
/* @0x2572e8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x2572ec add r6, sp, #96 */
/* @0x2572f0 ldr r11, [pc, #0x388] */
/* @0x2572f4 add r11, pc, r11 */
/* @0x2572f8 str r0, [sp, #0x14] */
/* @0x2572fc bl 0xb6538 <strlen@plt> */
/* @0x257300 ldr r2, [pc, #0x37c] */
/* @0x257304 add r1, sp, #80 */
/* @0x257308 str r5, [sp, #0x50] */
/* @0x25730c add r2, pc, r2 */
/* @0x257310 str r5, [sp, #0x54] */
/* @0x257314 str r5, [sp, #0x58] */
/* @0x257318 str r5, [sp, #0x5c] */
/* @0x25731c str r5, [sp, #0x60] */
/* @0x257320 str r5, [sp, #0x64] */
/* @0x257324 str r5, [sp, #0x68] */
/* @0x257328 str r5, [sp, #0x6c] */
/* @0x25732c mov r4, r0 */
/* @0x257330 mov r0, r8 */
/* @0x257334 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x257338 ldr r2, [pc, #0x348] */
/* @0x25733c mov r1, r6 */
/* @0x257340 mov r0, r8 */
/* @0x257344 add r2, pc, r2 */
/* @0x257348 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x25734c mov r1, r5 */
/* @0x257350 add r0, sp, #80 */
/* @0x257354 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x257358 mov r1, r5 */
/* @0x25735c mov r10, r0 */
/* @0x257360 mov r0, r6 */
/* @0x257364 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x257368 ldr r6, [pc, #0x31c] */
/* @0x25736c str r11, [sp, #0x24] */
/* @0x257370 ldr r11, [pc, #0x318] */
/* @0x257374 add r6, pc, r6 */
/* @0x257378 str r6, [sp, #0x20] */
/* @0x25737c add r11, pc, r11 */
/* @0x257380 ldr r6, [pc, #0x30c] */
/* @0x257384 str r11, [sp, #0x2c] */
/* @0x257388 ldr r11, [pc, #0x308] */
/* @0x25738c add r6, pc, r6 */
/* @0x257390 str r6, [sp, #0x28] */
/* @0x257394 add r11, pc, r11 */
/* @0x257398 ldr r6, [pc, #0x2fc] */
/* @0x25739c str r11, [sp, #0x34] */
/* @0x2573a0 add r6, pc, r6 */
/* @0x2573a4 str r6, [sp, #0x30] */
/* @0x2573a8 cmp r0, #0 */
/* @0x2573ac moveq r10, #0 */
/* @0x2573b0 lsr r11, r10, #31 */
/* @0x2573b4 cmp r10, r4 */
/* @0x2573b8 movle r7, r11 */
/* @0x2573bc orrgt r7, r11, #1 */
/* @0x2573c0 ldr r2, [sp, #0x14] */
/* @0x2573c4 cmp r7, #0 */
/* @0x2573c8 mov r3, r4 */
/* @0x2573cc add r5, sp, #144 */
/* @0x2573d0 mov r12, #100 */
/* @0x2573d4 bne 0x257618 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x3d0> */
/* @0x2573d8 ldr r0, [r8, #0x1c] */
/* @0x2573dc ldr r1, [r8, #0x20] */
/* @0x2573e0 str r10, [sp] */
/* @0x2573e4 str r7, [sp, #0x4] */
/* @0x2573e8 str r5, [sp, #0x8] */
/* @0x2573ec str r12, [sp, #0xc] */
/* @0x2573f0 bl 0x279390 <pcre_exec> */
/* @0x2573f4 cmp r0, #0 */
/* @0x2573f8 blt 0x257590 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x348> */
/* @0x2573fc ldr r1, [r8, #0x20] */
/* @0x257400 add r10, sp, #544 */
/* @0x257404 mov r6, r0 */
/* @0x257408 mov r2, #2 */
/* @0x25740c ldr r0, [r8, #0x1c] */
/* @0x257410 add r3, sp, #56 */
/* @0x257414 bl 0x25ee20 <pcre_fullinfo> */
/* @0x257418 add r3, r10, r6, lsl #3 */
/* @0x25741c vldr s14, [r3, #-404] */
/* @0x257420 vcvt.f64.s32 d7, s14 */
/* @0x257424 ldr r2, [pc, #0x274] */
/* @0x257428 mov r0, r8 */
/* @0x25742c add r1, sp, #80 */
/* @0x257430 mov r3, #1 */
/* @0x257434 add r2, pc, r2 */
/* @0x257438 mov r4, r10 */
/* @0x25743c str r7, [sp, #0x5c] */
/* @0x257440 ldr r10, [sp, #0x90] */
/* @0x257444 vstr d7, [sp, #80] */
/* @0x257448 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x25744c ldr r11, [sp, #0x248] */
/* @0x257450 mov r1, r8 */
/* @0x257454 ldr r2, [sp, #0x18] */
/* @0x257458 mov r0, r9 */
/* @0x25745c mov r3, r7 */
/* @0x257460 str r11, [sp] */
/* @0x257464 bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_> */
/* @0x257468 ldr r8, [r9] */
/* @0x25746c ldr r1, [pc, #0x230] */
/* @0x257470 mov r2, r10 */
/* @0x257474 mov r3, #7 */
/* @0x257478 add r1, pc, r1 */
/* @0x25747c mov r0, r8 */
/* @0x257480 bl 0x199960 <_ZN12YYObjectBase3AddEPKcii> */
/* @0x257484 ldr r1, [pc, #0x21c] */
/* @0x257488 mov r0, r8 */
/* @0x25748c ldr r2, [sp, #0x14] */
/* @0x257490 add r1, pc, r1 */
/* @0x257494 mov r3, #7 */
/* @0x257498 bl 0x199aa8 <_ZN12YYObjectBase3AddEPKcS1_i> */
/* @0x25749c ldr r3, [sp, #0x38] */
/* @0x2574a0 ldr r2, [pc, #0x204] */
/* @0x2574a4 mov r0, r8 */
/* @0x2574a8 add r3, r3, #1 */
/* @0x2574ac str r7, [sp, #0x78] */
/* @0x2574b0 add r2, pc, r2 */
/* @0x2574b4 str r7, [sp, #0x7c] */
/* @0x2574b8 vmov s14, r3 */
/* @0x2574bc mov r3, r7 */
/* @0x2574c0 vcvt.f64.s32 d7, s14 */
/* @0x2574c4 vmov r10, r11, d7 */
/* @0x2574c8 str r10, [r4, #-0x1b0]! */
/* @0x2574cc str r11, [r4, #0x4] */
/* @0x2574d0 mov r1, r4 */
/* @0x2574d4 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x2574d8 ldr r3, [sp, #0x38] */
/* @0x2574dc mov r11, #5 */
/* @0x2574e0 str r7, [sp, #0x80] */
/* @0x2574e4 cmp r3, #0 */
/* @0x2574e8 str r7, [sp, #0x84] */
/* @0x2574ec str r7, [sp, #0x88] */
/* @0x2574f0 str r11, [sp, #0x8c] */
/* @0x2574f4 blt 0x25728c <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x2574f8 mov r8, r7 */
/* @0x2574fc mov r10, r7 */
/* @0x257500 add r2, sp, #60 */
/* @0x257504 add r7, sp, #128 */
/* @0x257508 str r2, [sp, #0x10] */
/* @0x25750c b 0x257544 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x2fc> */
/* @0x257510 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x257514 mov r2, #7 */
/* @0x257518 mov r1, r4 */
/* @0x25751c str r2, [sp, #0x88] */
/* @0x257520 mov r0, r9 */
/* @0x257524 mov r2, r7 */
/* @0x257528 add r8, r8, #1 */
/* @0x25752c bl 0x247c68 <_Z10JSArrayPutP6RValueS0_S0_> */
/* @0x257530 ldr r0, [sp, #0x3c] */
/* @0x257534 bl 0x25f6ac <pcre_free_substring> */
/* @0x257538 ldr r3, [sp, #0x38] */
/* @0x25753c cmp r3, r8 */
/* @0x257540 blt 0x25728c <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x257544 add r2, sp, #60 */
/* @0x257548 mov r1, r5 */
/* @0x25754c str r2, [sp] */
/* @0x257550 mov r3, r8 */
/* @0x257554 ldr r0, [sp, #0x14] */
/* @0x257558 mov r2, r6 */
/* @0x25755c str r10, [sp, #0x3c] */
/* @0x257560 bl 0x25f5e8 <pcre_get_substring> */
/* @0x257564 vmov s13, r8 */
/* @0x257568 ldr r3, [sp, #0x3c] */
/* @0x25756c mov r0, r7 */
/* @0x257570 vcvt.f64.s32 d7, s13 */
/* @0x257574 cmp r3, #0 */
/* @0x257578 mov r1, r3 */
/* @0x25757c vstr d7, [sp, #112] */
/* @0x257580 bne 0x257510 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x2c8> */
/* @0x257584 str r11, [sp, #0x8c] */
/* @0x257588 str r3, [sp, #0x80] */
/* @0x25758c b 0x257514 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x2cc> */
/* @0x257590 add r6, r0, #6 */
/* @0x257594 cmp r6, #5 */
/* @0x257598 addls pc, pc, r6, lsl #2 */
/* @0x25759c b 0x257654 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x40c> */
/* @0x2575a0 b 0x25760c <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x3c4> */
/* @0x2575a4 b 0x257600 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x3b8> */
/* @0x2575a8 b 0x2575f4 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x3ac> */
/* @0x2575ac b 0x2575e8 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x3a0> */
/* @0x2575b0 b 0x2575c4 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x37c> */
/* @0x2575b4 b 0x2575b8 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x370> */
/* @0x2575b8 add r10, r10, #1 */
/* @0x2575bc lsr r11, r10, #31 */
/* @0x2575c0 b 0x2573b4 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x2575c4 ldr r3, [pc, #0xe4] */
/* @0x2575c8 ldr r1, [sp, #0x34] */
/* @0x2575cc ldr r6, [sp, #0x10] */
/* @0x2575d0 ldr r3, [r6, r3] */
/* @0x2575d4 ldr r0, [r3] */
/* @0x2575d8 ldr r3, [r0] */
/* @0x2575dc ldr r3, [r3, #0xc] */
/* @0x2575e0 blx r3 */
/* @0x2575e4 b 0x2573b4 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x2575e8 ldr r3, [pc, #0xc0] */
/* @0x2575ec ldr r1, [sp, #0x30] */
/* @0x2575f0 b 0x2575cc <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x384> */
/* @0x2575f4 ldr r3, [pc, #0xb4] */
/* @0x2575f8 ldr r1, [sp, #0x2c] */
/* @0x2575fc b 0x2575cc <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x384> */
/* @0x257600 ldr r3, [pc, #0xa8] */
/* @0x257604 ldr r1, [sp, #0x28] */
/* @0x257608 b 0x2575cc <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x384> */
/* @0x25760c ldr r3, [pc, #0x9c] */
/* @0x257610 ldr r1, [sp, #0x24] */
/* @0x257614 b 0x2575cc <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x384> */
/* @0x257618 ldr r2, [pc, #0x94] */
/* @0x25761c mov r12, #0 */
/* @0x257620 mov r3, r12 */
/* @0x257624 mov r0, r8 */
/* @0x257628 add r1, sp, #80 */
/* @0x25762c add r2, pc, r2 */
/* @0x257630 mov r4, #0 */
/* @0x257634 mov r5, #0 */
/* @0x257638 str r12, [sp, #0x5c] */
/* @0x25763c strd r4, r5, [sp, #80] */
/* @0x257640 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x257644 mov r3, #12 */
/* @0x257648 str r3, [r9, #0xc] */
/* @0x25764c add sp, sp, #548 */
/* @0x257650 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x257654 ldr r3, [pc, #0x54] */
/* @0x257658 ldr r1, [sp, #0x20] */
/* @0x25765c b 0x2575cc <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x384> */
/* @0x257660 ldr r0, [pc, #0x50] */
/* @0x257664 add r0, pc, r0 */
/* @0x257668 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25766c add sp, sp, #548 */
/* @0x257670 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x257674 andeq lr, pc, r12, asr #19 */
/* @0x257678 andseq r10, r9, r0, ror #19 */
/* @0x25767c andeq lr, pc, r4, asr #25 */
/* @0x257680 andeq lr, pc, r8, lsr #28 */
/* @0x257684 muleq pc, r4, sp */
/* @0x257688 muleq sp, r4, r11 */
/* @0x25768c andeq lr, pc, r4, asr #27 */
/* @0x257690 andeq lr, pc, r4, ror #26 */
/* @0x257694 andeq lr, pc, r0, ror sp */
/* @0x257698 andeq lr, pc, r8, lsl sp */
/* @0x25769c andeq lr, pc, r4, lsr #26 */
/* @0x2576a0 andeq lr, pc, r12, ror #24 */
/* @0x2576a4 muleq lr, r0, sp */
/* @0x2576a8 strheq pc, [pc], -r4 */
/* @0x2576ac strheq r9, [sp], -r12 */
/* @0x2576b0 .word 0xffffbac4 */
/* @0x2576b4 andeq lr, pc, r4, ror r10 */
/* @0x2576b8 andeq pc, pc, r0, lsr #9 */

/* ── FUNC 0x2576bc · JS_RegExp_prototype_test(RValue&, CInstance*, CInstance*, int, RValue*) · size=684 · insn=171 */
/* @0x2576bc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2576c0 mov r5, r1 */
/* @0x2576c4 ldr r1, [pc, #0x268] */
/* @0x2576c8 sub sp, sp, #212 */
/* @0x2576cc mov r6, r0 */
/* @0x2576d0 ldr r0, [r5, #0x40] */
/* @0x2576d4 add r1, pc, r1 */
/* @0x2576d8 ldr r11, [pc, #0x258] */
/* @0x2576dc bl 0xb6574 <strcmp@plt> */
/* @0x2576e0 add r11, pc, r11 */
/* @0x2576e4 subs r4, r0, #0 */
/* @0x2576e8 beq 0x257700 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x2576ec ldr r0, [pc, #0x248] */
/* @0x2576f0 add r0, pc, r0 */
/* @0x2576f4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2576f8 add sp, sp, #212 */
/* @0x2576fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x257700 add r7, sp, #40 */
/* @0x257704 ldr r1, [sp, #0xf8] */
/* @0x257708 mov r2, #0 */
/* @0x25770c mov r3, #0 */
/* @0x257710 mov r0, r7 */
/* @0x257714 strd r2, r3, [sp, #40] */
/* @0x257718 str r4, [sp, #0x30] */
/* @0x25771c mvn r3, #-16777216 */
/* @0x257720 str r3, [sp, #0x34] */
/* @0x257724 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x257728 cmp r0, #2 */
/* @0x25772c beq 0x2576f8 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x257730 cmp r0, #1 */
/* @0x257734 beq 0x257924 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x268> */
/* @0x257738 mov r1, r4 */
/* @0x25773c mov r0, r7 */
/* @0x257740 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x257744 add r7, sp, #56 */
/* @0x257748 add r9, sp, #72 */
/* @0x25774c mov r10, r0 */
/* @0x257750 bl 0xb6538 <strlen@plt> */
/* @0x257754 ldr r2, [pc, #0x1e4] */
/* @0x257758 mov r1, r7 */
/* @0x25775c str r4, [sp, #0x38] */
/* @0x257760 add r2, pc, r2 */
/* @0x257764 str r4, [sp, #0x3c] */
/* @0x257768 str r4, [sp, #0x40] */
/* @0x25776c str r4, [sp, #0x44] */
/* @0x257770 str r4, [sp, #0x48] */
/* @0x257774 str r4, [sp, #0x4c] */
/* @0x257778 str r4, [sp, #0x50] */
/* @0x25777c str r4, [sp, #0x54] */
/* @0x257780 mov r8, r0 */
/* @0x257784 mov r0, r5 */
/* @0x257788 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x25778c ldr r2, [pc, #0x1b0] */
/* @0x257790 mov r1, r9 */
/* @0x257794 mov r0, r5 */
/* @0x257798 add r2, pc, r2 */
/* @0x25779c bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x2577a0 mov r0, r7 */
/* @0x2577a4 mov r1, r4 */
/* @0x2577a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x2577ac mov r1, r4 */
/* @0x2577b0 mov r7, r0 */
/* @0x2577b4 mov r0, r9 */
/* @0x2577b8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x2577bc ldr r3, [pc, #0x184] */
/* @0x2577c0 add r3, pc, r3 */
/* @0x2577c4 str r3, [sp, #0x10] */
/* @0x2577c8 ldr r3, [pc, #0x17c] */
/* @0x2577cc add r3, pc, r3 */
/* @0x2577d0 str r3, [sp, #0x14] */
/* @0x2577d4 ldr r3, [pc, #0x174] */
/* @0x2577d8 add r3, pc, r3 */
/* @0x2577dc str r3, [sp, #0x18] */
/* @0x2577e0 ldr r3, [pc, #0x16c] */
/* @0x2577e4 add r3, pc, r3 */
/* @0x2577e8 str r3, [sp, #0x1c] */
/* @0x2577ec ldr r3, [pc, #0x164] */
/* @0x2577f0 add r3, pc, r3 */
/* @0x2577f4 str r3, [sp, #0x20] */
/* @0x2577f8 ldr r3, [pc, #0x15c] */
/* @0x2577fc add r3, pc, r3 */
/* @0x257800 str r3, [sp, #0x24] */
/* @0x257804 cmp r0, #0 */
/* @0x257808 moveq r7, #0 */
/* @0x25780c lsr r9, r7, #31 */
/* @0x257810 cmp r7, r8 */
/* @0x257814 movle r4, r9 */
/* @0x257818 orrgt r4, r9, #1 */
/* @0x25781c mov r2, r10 */
/* @0x257820 cmp r4, #0 */
/* @0x257824 mov r3, r8 */
/* @0x257828 add r1, sp, #88 */
/* @0x25782c mov r12, #30 */
/* @0x257830 bne 0x257900 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x244> */
/* @0x257834 ldr lr, [r5, #0x20] */
/* @0x257838 ldr r0, [r5, #0x1c] */
/* @0x25783c str r1, [sp, #0x8] */
/* @0x257840 str r7, [sp] */
/* @0x257844 mov r1, lr */
/* @0x257848 str r4, [sp, #0x4] */
/* @0x25784c str r12, [sp, #0xc] */
/* @0x257850 bl 0x279390 <pcre_exec> */
/* @0x257854 cmp r0, #0 */
/* @0x257858 blt 0x25787c <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x1c0> */
/* @0x25785c mov r2, #13 */
/* @0x257860 str r4, [r6] */
/* @0x257864 mov r3, #0 */
/* @0x257868 str r2, [r6, #0xc] */
/* @0x25786c movt r3, #0x3ff0 */
/* @0x257870 str r3, [r6, #0x4] */
/* @0x257874 add sp, sp, #212 */
/* @0x257878 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25787c add r0, r0, #6 */
/* @0x257880 cmp r0, #5 */
/* @0x257884 addls pc, pc, r0, lsl #2 */
/* @0x257888 b 0x257918 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x25c> */
/* @0x25788c b 0x2578f4 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x238> */
/* @0x257890 b 0x2578e8 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x22c> */
/* @0x257894 b 0x2578dc <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x220> */
/* @0x257898 b 0x2578d0 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x25789c b 0x2578b0 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0x2578a0 b 0x2578a4 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0x2578a4 add r7, r7, #1 */
/* @0x2578a8 lsr r9, r7, #31 */
/* @0x2578ac b 0x257810 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x2578b0 ldr r3, [pc, #0xa8] */
/* @0x2578b4 ldr r1, [sp, #0x24] */
/* @0x2578b8 ldr r3, [r11, r3] */
/* @0x2578bc ldr r0, [r3] */
/* @0x2578c0 ldr r3, [r0] */
/* @0x2578c4 ldr r3, [r3, #0xc] */
/* @0x2578c8 blx r3 */
/* @0x2578cc b 0x257810 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x2578d0 ldr r3, [pc, #0x88] */
/* @0x2578d4 ldr r1, [sp, #0x20] */
/* @0x2578d8 b 0x2578b8 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x2578dc ldr r3, [pc, #0x7c] */
/* @0x2578e0 ldr r1, [sp, #0x1c] */
/* @0x2578e4 b 0x2578b8 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x2578e8 ldr r3, [pc, #0x70] */
/* @0x2578ec ldr r1, [sp, #0x18] */
/* @0x2578f0 b 0x2578b8 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x2578f4 ldr r3, [pc, #0x64] */
/* @0x2578f8 ldr r1, [sp, #0x14] */
/* @0x2578fc b 0x2578b8 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x257900 mov r3, #0 */
/* @0x257904 mov r2, #13 */
/* @0x257908 str r3, [r6] */
/* @0x25790c str r2, [r6, #0xc] */
/* @0x257910 str r3, [r6, #0x4] */
/* @0x257914 b 0x2576f8 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x257918 ldr r3, [pc, #0x40] */
/* @0x25791c ldr r1, [sp, #0x10] */
/* @0x257920 b 0x2578b8 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x257924 ldr r0, [pc, #0x38] */
/* @0x257928 add r0, pc, r0 */
/* @0x25792c bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x257930 b 0x2576f8 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x257934 andeq lr, pc, r8, asr r5 */
/* @0x257938 andseq r10, r9, r0, ror r5 */
/* @0x25793c andeq lr, pc, r8, asr r8 */
/* @0x257940 andeq lr, pc, r0, asr #18 */
/* @0x257944 andeq sp, sp, r0, asr #14 */
/* @0x257948 andeq lr, pc, r8, ror r9 */
/* @0x25794c andeq lr, pc, r0, asr r9 */
/* @0x257950 andeq lr, pc, r4, lsr #18 */
/* @0x257954 strdeq lr, pc, [pc], -r12 */
/* @0x257958 ldrdeq lr, pc, [pc], -r4 */
/* @0x25795c strheq lr, [pc], -r0 */
/* @0x257960 .word 0xffffbac4 */
/* @0x257964 .word 0x000ff1dc */

/* ── FUNC 0x257968 · JS_String_prototype_concat(RValue&, CInstance*, CInstance*, int, RValue*) · size=380 · insn=95 */
/* @0x257968 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x25796c sub sp, sp, #32 */
/* @0x257970 add r4, sp, #32 */
/* @0x257974 mov r8, r0 */
/* @0x257978 mov r0, sp */
/* @0x25797c mov r6, r3 */
/* @0x257980 str r1, [r4, #-0x20]! */
/* @0x257984 mov r3, #6 */
/* @0x257988 ldr r5, [sp, #0x40] */
/* @0x25798c str r3, [sp, #0xc] */
/* @0x257990 bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue> */
/* @0x257994 cmp r0, #1 */
/* @0x257998 beq 0x257a98 <_Z26JS_String_prototype_concatR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x25799c add r7, sp, #16 */
/* @0x2579a0 mov r1, sp */
/* @0x2579a4 mov r2, #0 */
/* @0x2579a8 mov r3, #0 */
/* @0x2579ac mov r0, r7 */
/* @0x2579b0 strd r2, r3, [sp, #16] */
/* @0x2579b4 mov r4, #0 */
/* @0x2579b8 mvn r3, #-16777216 */
/* @0x2579bc str r4, [sp, #0x18] */
/* @0x2579c0 str r3, [sp, #0x1c] */
/* @0x2579c4 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x2579c8 ldr r3, [sp, #0x10] */
/* @0x2579cc ldr r0, [r3] */
/* @0x2579d0 bl 0xb6538 <strlen@plt> */
/* @0x2579d4 cmp r6, r4 */
/* @0x2579d8 mov r9, r0 */
/* @0x2579dc ble 0x257aac <_Z26JS_String_prototype_concatR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x2579e0 lsl r10, r6, #4 */
/* @0x2579e4 ldr r3, [r5, r4] */
/* @0x2579e8 add r4, r4, #16 */
/* @0x2579ec ldr r0, [r3] */
/* @0x2579f0 bl 0xb6538 <strlen@plt> */
/* @0x2579f4 cmp r4, r10 */
/* @0x2579f8 add r9, r9, r0 */
/* @0x2579fc bne 0x2579e4 <_Z26JS_String_prototype_concatR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x257a00 ldr r1, [pc, #0xd0] */
/* @0x257a04 mov r0, r9 */
/* @0x257a08 mov r3, #1 */
/* @0x257a0c mov r2, #70 */
/* @0x257a10 add r1, pc, r1 */
/* @0x257a14 mov r4, #0 */
/* @0x257a18 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x257a1c strb r4, [r0] */
/* @0x257a20 mov r9, r0 */
/* @0x257a24 ldr r3, [sp, #0x10] */
/* @0x257a28 ldr r1, [r3] */
/* @0x257a2c bl 0xb65a4 <strcpy@plt> */
/* @0x257a30 ldr r3, [r5, r4, lsl #4] */
/* @0x257a34 mov r0, r9 */
/* @0x257a38 add r4, r4, #1 */
/* @0x257a3c ldr r1, [r3] */
/* @0x257a40 bl 0xb6628 <strcat@plt> */
/* @0x257a44 cmp r4, r6 */
/* @0x257a48 bne 0x257a30 <_Z26JS_String_prototype_concatR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x257a4c ldr r3, [sp, #0x1c] */
/* @0x257a50 sub r3, r3, #1 */
/* @0x257a54 bic r3, r3, #-16777216 */
/* @0x257a58 bic r3, r3, #3 */
/* @0x257a5c cmp r3, #0 */
/* @0x257a60 beq 0x257a8c <_Z26JS_String_prototype_concatR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x257a64 mov r0, r8 */
/* @0x257a68 mov r1, r9 */
/* @0x257a6c mov r3, #0 */
/* @0x257a70 mov r2, #5 */
/* @0x257a74 str r3, [sp, #0x18] */
/* @0x257a78 str r3, [sp, #0x10] */
/* @0x257a7c str r2, [sp, #0x1c] */
/* @0x257a80 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x257a84 add sp, sp, #32 */
/* @0x257a88 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x257a8c mov r0, r7 */
/* @0x257a90 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x257a94 b 0x257a64 <_Z26JS_String_prototype_concatR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x257a98 ldr r0, [pc, #0x3c] */
/* @0x257a9c add r0, pc, r0 */
/* @0x257aa0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x257aa4 add sp, sp, #32 */
/* @0x257aa8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x257aac ldr r1, [pc, #0x2c] */
/* @0x257ab0 mov r2, #70 */
/* @0x257ab4 mov r3, #1 */
/* @0x257ab8 add r1, pc, r1 */
/* @0x257abc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x257ac0 strb r4, [r0] */
/* @0x257ac4 mov r9, r0 */
/* @0x257ac8 ldr r3, [sp, #0x10] */
/* @0x257acc ldr r1, [r3] */
/* @0x257ad0 bl 0xb65a4 <strcpy@plt> */
/* @0x257ad4 b 0x257a4c <_Z26JS_String_prototype_concatR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x257ad8 andeq r9, sp, r0, lsr #12 */
/* @0x257adc andeq lr, pc, r12, lsr #9 */
/* @0x257ae0 andeq r9, sp, r8, ror r5 */

/* ── FUNC 0x257ae4 · JS_String_prototype_indexOf(RValue&, CInstance*, CInstance*, int, RValue*) · size=920 · insn=230 */
/* @0x257ae4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x257ae8 sub sp, sp, #92 */
/* @0x257aec add r4, sp, #88 */
/* @0x257af0 str r0, [sp, #0x4] */
/* @0x257af4 str r1, [r4, #-0x30]! */
/* @0x257af8 mov r0, r4 */
/* @0x257afc str r3, [sp, #0x10] */
/* @0x257b00 mov r3, #6 */
/* @0x257b04 str r3, [sp, #0x34] */
/* @0x257b08 bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue> */
/* @0x257b0c cmp r0, #1 */
/* @0x257b10 beq 0x257e5c <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x378> */
/* @0x257b14 add r1, sp, #56 */
/* @0x257b18 add r0, sp, #56 */
/* @0x257b1c str r1, [sp, #0xc] */
/* @0x257b20 mov r1, r4 */
/* @0x257b24 mov r2, #0 */
/* @0x257b28 mov r3, #0 */
/* @0x257b2c mov r6, #0 */
/* @0x257b30 strd r2, r3, [sp, #56] */
/* @0x257b34 str r6, [sp, #0x40] */
/* @0x257b38 mvn r3, #-16777216 */
/* @0x257b3c str r3, [sp, #0x44] */
/* @0x257b40 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x257b44 ldr r3, [sp, #0x38] */
/* @0x257b48 add r7, sp, #72 */
/* @0x257b4c add r4, sp, #28 */
/* @0x257b50 add r8, sp, #26 */
/* @0x257b54 mov r0, r7 */
/* @0x257b58 ldr r1, [r3] */
/* @0x257b5c bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc> */
/* @0x257b60 b 0x257b6c <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x257b64 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_> */
/* @0x257b68 add r6, r6, r0 */
/* @0x257b6c mov r0, r7 */
/* @0x257b70 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x257b74 mov r1, r8 */
/* @0x257b78 mov r2, r4 */
/* @0x257b7c subs r5, r0, #0 */
/* @0x257b80 bne 0x257b64 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x257b84 lsl r8, r6, #1 */
/* @0x257b88 ldr r1, [pc, #0x2e0] */
/* @0x257b8c mov r2, #70 */
/* @0x257b90 mov r3, #1 */
/* @0x257b94 add r1, pc, r1 */
/* @0x257b98 mov r0, r8 */
/* @0x257b9c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x257ba0 mov r1, r5 */
/* @0x257ba4 mov r2, r8 */
/* @0x257ba8 add r9, sp, #26 */
/* @0x257bac mov r10, r0 */
/* @0x257bb0 bl 0xb65b0 <memset@plt> */
/* @0x257bb4 mov r0, r7 */
/* @0x257bb8 bl 0x2423fc <_ZN23CCodepointIterator_UTF85ResetEv> */
/* @0x257bbc mov r0, r7 */
/* @0x257bc0 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x257bc4 mov r1, r9 */
/* @0x257bc8 mov r2, r4 */
/* @0x257bcc subs r8, r0, #0 */
/* @0x257bd0 beq 0x257bfc <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x257bd4 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_> */
/* @0x257bd8 ldrh r2, [sp, #26] */
/* @0x257bdc lsl r3, r5, #1 */
/* @0x257be0 strh r2, [r10, r3] */
/* @0x257be4 cmp r0, #2 */
/* @0x257be8 add r5, r5, r0 */
/* @0x257bec ldrheq r2, [sp, #28] */
/* @0x257bf0 addeq r3, r10, r3 */
/* @0x257bf4 strheq r2, [r3, #2] */
/* @0x257bf8 b 0x257bbc <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x257bfc ldr r1, [sp, #0x80] */
/* @0x257c00 mov r0, r7 */
/* @0x257c04 mov r2, #0 */
/* @0x257c08 str r8, [sp, #0x50] */
/* @0x257c0c mov r3, #0 */
/* @0x257c10 strd r2, r3, [sp, #72] */
/* @0x257c14 mvn r3, #-16777216 */
/* @0x257c18 str r3, [sp, #0x54] */
/* @0x257c1c bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x257c20 ldr r3, [sp, #0x48] */
/* @0x257c24 mov r0, r4 */
/* @0x257c28 add r11, sp, #24 */
/* @0x257c2c add r9, sp, #26 */
/* @0x257c30 ldr r1, [r3] */
/* @0x257c34 bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc> */
/* @0x257c38 b 0x257c44 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x257c3c bl 0x2424c4 <_Z16CodepointToUTF16iRtS_> */
/* @0x257c40 add r8, r8, r0 */
/* @0x257c44 mov r0, r4 */
/* @0x257c48 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x257c4c mov r1, r11 */
/* @0x257c50 mov r2, r9 */
/* @0x257c54 subs r5, r0, #0 */
/* @0x257c58 bne 0x257c3c <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x257c5c ldr r1, [pc, #0x210] */
/* @0x257c60 lsl r2, r8, #1 */
/* @0x257c64 str r2, [sp, #0x8] */
/* @0x257c68 mov r3, #1 */
/* @0x257c6c add r1, pc, r1 */
/* @0x257c70 mov r2, #70 */
/* @0x257c74 ldr r0, [sp, #0x8] */
/* @0x257c78 add r12, sp, #24 */
/* @0x257c7c str r12, [sp] */
/* @0x257c80 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x257c84 mov r1, r5 */
/* @0x257c88 ldr r2, [sp, #0x8] */
/* @0x257c8c add r11, sp, #26 */
/* @0x257c90 mov r9, r0 */
/* @0x257c94 bl 0xb65b0 <memset@plt> */
/* @0x257c98 mov r0, r4 */
/* @0x257c9c bl 0x2423fc <_ZN23CCodepointIterator_UTF85ResetEv> */
/* @0x257ca0 ldr r12, [sp] */
/* @0x257ca4 str r6, [sp, #0x14] */
/* @0x257ca8 mov r6, r12 */
/* @0x257cac mov r0, r4 */
/* @0x257cb0 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x257cb4 mov r1, r6 */
/* @0x257cb8 mov r2, r11 */
/* @0x257cbc subs r3, r0, #0 */
/* @0x257cc0 beq 0x257cec <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x208> */
/* @0x257cc4 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_> */
/* @0x257cc8 ldrh r2, [sp, #24] */
/* @0x257ccc lsl r3, r5, #1 */
/* @0x257cd0 strh r2, [r9, r3] */
/* @0x257cd4 cmp r0, #2 */
/* @0x257cd8 add r5, r5, r0 */
/* @0x257cdc ldrheq r2, [sp, #26] */
/* @0x257ce0 addeq r3, r9, r3 */
/* @0x257ce4 strheq r2, [r3, #2] */
/* @0x257ce8 b 0x257cac <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x257cec ldr r1, [sp, #0x10] */
/* @0x257cf0 ldr r6, [sp, #0x14] */
/* @0x257cf4 cmp r1, #1 */
/* @0x257cf8 movle r0, r3 */
/* @0x257cfc ble 0x257d1c <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x238> */
/* @0x257d00 ldr r2, [sp, #0x80] */
/* @0x257d04 add r0, r2, #16 */
/* @0x257d08 bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue> */
/* @0x257d0c vmov d7, r0, r1 */
/* @0x257d10 vcvt.s32.f64 s15, d7 */
/* @0x257d14 vmov r0, s15 */
/* @0x257d18 bic r0, r0, r0, asr #31 */
/* @0x257d1c cmp r0, r6 */
/* @0x257d20 movlt r4, r0 */
/* @0x257d24 movge r4, r6 */
/* @0x257d28 cmp r8, #0 */
/* @0x257d2c bne 0x257de8 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x304> */
/* @0x257d30 cmp r4, r6 */
/* @0x257d34 movlt r2, r4 */
/* @0x257d38 movge r2, r6 */
/* @0x257d3c vmov s15, r2 */
/* @0x257d40 vcvt.f64.s32 d7, s15 */
/* @0x257d44 vmov r2, r3, d7 */
/* @0x257d48 mov r0, r2 */
/* @0x257d4c mov r2, r3 */
/* @0x257d50 ldr r3, [sp, #0x4] */
/* @0x257d54 ldr r1, [sp, #0x44] */
/* @0x257d58 str r0, [r3] */
/* @0x257d5c sub r3, r1, #1 */
/* @0x257d60 ldr r1, [sp, #0x4] */
/* @0x257d64 bic r3, r3, #-16777216 */
/* @0x257d68 bic r3, r3, #3 */
/* @0x257d6c str r2, [r1, #0x4] */
/* @0x257d70 mov r2, #0 */
/* @0x257d74 cmp r3, r2 */
/* @0x257d78 str r2, [r1, #0xc] */
/* @0x257d7c beq 0x257e40 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x35c> */
/* @0x257d80 ldr r1, [sp, #0x54] */
/* @0x257d84 mov r3, #0 */
/* @0x257d88 str r3, [sp, #0x40] */
/* @0x257d8c mov r2, #5 */
/* @0x257d90 sub r1, r1, #1 */
/* @0x257d94 str r3, [sp, #0x38] */
/* @0x257d98 bic r3, r1, #-16777216 */
/* @0x257d9c str r2, [sp, #0x44] */
/* @0x257da0 bic r3, r3, #3 */
/* @0x257da4 cmp r3, #0 */
/* @0x257da8 beq 0x257e34 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x350> */
/* @0x257dac cmp r9, #0 */
/* @0x257db0 mov r3, #0 */
/* @0x257db4 mov r2, #5 */
/* @0x257db8 str r3, [sp, #0x50] */
/* @0x257dbc str r3, [sp, #0x48] */
/* @0x257dc0 str r2, [sp, #0x54] */
/* @0x257dc4 beq 0x257dd0 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x2ec> */
/* @0x257dc8 mov r0, r9 */
/* @0x257dcc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x257dd0 cmp r10, #0 */
/* @0x257dd4 beq 0x257de0 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x2fc> */
/* @0x257dd8 mov r0, r10 */
/* @0x257ddc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x257de0 add sp, sp, #92 */
/* @0x257de4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x257de8 cmp r4, r6 */
/* @0x257dec addlt r5, r10, r4, lsl #1 */
/* @0x257df0 ldrlt r8, [sp, #0x8] */
/* @0x257df4 blt 0x257e08 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x324> */
/* @0x257df8 b 0x257e4c <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x368> */
/* @0x257dfc add r4, r4, #1 */
/* @0x257e00 cmp r4, r6 */
/* @0x257e04 beq 0x257e4c <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x368> */
/* @0x257e08 mov r0, r5 */
/* @0x257e0c mov r1, r9 */
/* @0x257e10 mov r2, r8 */
/* @0x257e14 add r5, r5, #2 */
/* @0x257e18 bl 0xb6c40 <memcmp@plt> */
/* @0x257e1c cmp r0, #0 */
/* @0x257e20 bne 0x257dfc <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x318> */
/* @0x257e24 vmov s15, r4 */
/* @0x257e28 vcvt.f64.s32 d7, s15 */
/* @0x257e2c vmov r2, r3, d7 */
/* @0x257e30 b 0x257d48 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x257e34 mov r0, r7 */
/* @0x257e38 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x257e3c b 0x257dac <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x2c8> */
/* @0x257e40 add r0, sp, #56 */
/* @0x257e44 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x257e48 b 0x257d80 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x29c> */
/* @0x257e4c mov r3, #0 */
/* @0x257e50 mov r2, #0 */
/* @0x257e54 movt r3, #0xbff0 */
/* @0x257e58 b 0x257d48 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x257e5c ldr r0, [pc, #0x14] */
/* @0x257e60 add r0, pc, r0 */
/* @0x257e64 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x257e68 add sp, sp, #92 */
/* @0x257e6c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x257e70 muleq sp, r12, r4 */
/* @0x257e74 andeq r9, sp, r4, asr #7 */
/* @0x257e78 andeq lr, pc, r8, ror #1 */

/* ── FUNC 0x257e7c · JS_String_prototype_lastIndexOf(RValue&, CInstance*, CInstance*, int, RValue*) · size=880 · insn=220 */
/* @0x257e7c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x257e80 sub sp, sp, #92 */
/* @0x257e84 add r4, sp, #88 */
/* @0x257e88 str r0, [sp, #0x4] */
/* @0x257e8c str r1, [r4, #-0x30]! */
/* @0x257e90 mov r0, r4 */
/* @0x257e94 str r3, [sp, #0x8] */
/* @0x257e98 mov r3, #6 */
/* @0x257e9c str r3, [sp, #0x34] */
/* @0x257ea0 bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue> */
/* @0x257ea4 cmp r0, #1 */
/* @0x257ea8 beq 0x2581b4 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x338> */
/* @0x257eac add r12, sp, #56 */
/* @0x257eb0 ldr lr, [sp, #0x4] */
/* @0x257eb4 str r12, [sp, #0xc] */
/* @0x257eb8 mov r3, #0 */
/* @0x257ebc mov r0, r12 */
/* @0x257ec0 ldr r12, [sp, #0x4] */
/* @0x257ec4 mov r10, r3 */
/* @0x257ec8 mov r1, r4 */
/* @0x257ecc movt r3, #0xbff0 */
/* @0x257ed0 mov r2, #0 */
/* @0x257ed4 str r3, [r12, #0x4] */
/* @0x257ed8 mov r3, #0 */
/* @0x257edc str r10, [r12, #0xc] */
/* @0x257ee0 mvn r12, #-16777216 */
/* @0x257ee4 str r10, [lr] */
/* @0x257ee8 add r9, sp, #72 */
/* @0x257eec strd r2, r3, [sp, #56] */
/* @0x257ef0 add r4, sp, #28 */
/* @0x257ef4 str r10, [sp, #0x40] */
/* @0x257ef8 add r5, sp, #26 */
/* @0x257efc str r12, [sp, #0x44] */
/* @0x257f00 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x257f04 ldr r3, [sp, #0x38] */
/* @0x257f08 mov r0, r9 */
/* @0x257f0c ldr r1, [r3] */
/* @0x257f10 bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc> */
/* @0x257f14 b 0x257f20 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x257f18 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_> */
/* @0x257f1c add r10, r10, r0 */
/* @0x257f20 mov r0, r9 */
/* @0x257f24 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x257f28 mov r1, r5 */
/* @0x257f2c mov r2, r4 */
/* @0x257f30 subs r6, r0, #0 */
/* @0x257f34 bne 0x257f18 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x257f38 lsl r5, r10, #1 */
/* @0x257f3c ldr r1, [pc, #0x29c] */
/* @0x257f40 mov r3, #1 */
/* @0x257f44 mov r2, #70 */
/* @0x257f48 add r1, pc, r1 */
/* @0x257f4c mov r0, r5 */
/* @0x257f50 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x257f54 add r8, sp, #26 */
/* @0x257f58 mov r1, r6 */
/* @0x257f5c mov r2, r5 */
/* @0x257f60 mov r7, r0 */
/* @0x257f64 bl 0xb65b0 <memset@plt> */
/* @0x257f68 mov r0, r9 */
/* @0x257f6c bl 0x2423fc <_ZN23CCodepointIterator_UTF85ResetEv> */
/* @0x257f70 str r10, [sp, #0x10] */
/* @0x257f74 mov r0, r9 */
/* @0x257f78 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x257f7c mov r1, r8 */
/* @0x257f80 mov r2, r4 */
/* @0x257f84 subs r5, r0, #0 */
/* @0x257f88 beq 0x257fb4 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x257f8c bl 0x2424c4 <_Z16CodepointToUTF16iRtS_> */
/* @0x257f90 ldrh r2, [sp, #26] */
/* @0x257f94 lsl r3, r6, #1 */
/* @0x257f98 strh r2, [r7, r3] */
/* @0x257f9c cmp r0, #2 */
/* @0x257fa0 add r6, r6, r0 */
/* @0x257fa4 ldrheq r2, [sp, #28] */
/* @0x257fa8 addeq r3, r7, r3 */
/* @0x257fac strheq r2, [r3, #2] */
/* @0x257fb0 b 0x257f74 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x257fb4 ldr r1, [sp, #0x80] */
/* @0x257fb8 mov r0, r9 */
/* @0x257fbc mov r2, #0 */
/* @0x257fc0 str r5, [sp, #0x50] */
/* @0x257fc4 mov r3, #0 */
/* @0x257fc8 strd r2, r3, [sp, #72] */
/* @0x257fcc mvn r3, #-16777216 */
/* @0x257fd0 str r3, [sp, #0x54] */
/* @0x257fd4 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x257fd8 ldr r3, [sp, #0x48] */
/* @0x257fdc mov r0, r4 */
/* @0x257fe0 add r11, sp, #24 */
/* @0x257fe4 add r8, sp, #26 */
/* @0x257fe8 ldr r1, [r3] */
/* @0x257fec bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc> */
/* @0x257ff0 b 0x257ffc <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x180> */
/* @0x257ff4 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_> */
/* @0x257ff8 add r5, r5, r0 */
/* @0x257ffc mov r0, r4 */
/* @0x258000 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x258004 mov r1, r11 */
/* @0x258008 mov r2, r8 */
/* @0x25800c subs r6, r0, #0 */
/* @0x258010 bne 0x257ff4 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x258014 lsl r11, r5, #1 */
/* @0x258018 ldr r1, [pc, #0x1c4] */
/* @0x25801c mov r3, #1 */
/* @0x258020 mov r2, #70 */
/* @0x258024 add r1, pc, r1 */
/* @0x258028 mov r0, r11 */
/* @0x25802c add r12, sp, #24 */
/* @0x258030 str r12, [sp] */
/* @0x258034 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x258038 mov r2, r11 */
/* @0x25803c mov r1, r6 */
/* @0x258040 add r11, sp, #26 */
/* @0x258044 mov r8, r0 */
/* @0x258048 bl 0xb65b0 <memset@plt> */
/* @0x25804c mov r0, r4 */
/* @0x258050 bl 0x2423fc <_ZN23CCodepointIterator_UTF85ResetEv> */
/* @0x258054 ldr r12, [sp] */
/* @0x258058 str r10, [sp, #0x14] */
/* @0x25805c mov r10, r12 */
/* @0x258060 mov r0, r4 */
/* @0x258064 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x258068 mov r1, r10 */
/* @0x25806c mov r2, r11 */
/* @0x258070 cmp r0, #0 */
/* @0x258074 beq 0x2580a0 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x224> */
/* @0x258078 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_> */
/* @0x25807c ldrh r2, [sp, #24] */
/* @0x258080 lsl r3, r6, #1 */
/* @0x258084 strh r2, [r8, r3] */
/* @0x258088 cmp r0, #2 */
/* @0x25808c add r6, r6, r0 */
/* @0x258090 ldrheq r2, [sp, #26] */
/* @0x258094 addeq r3, r8, r3 */
/* @0x258098 strheq r2, [r3, #2] */
/* @0x25809c b 0x258060 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x2580a0 ldr r12, [sp, #0x8] */
/* @0x2580a4 ldr r10, [sp, #0x14] */
/* @0x2580a8 cmp r12, #1 */
/* @0x2580ac ble 0x2580c8 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x24c> */
/* @0x2580b0 ldr r12, [sp, #0x80] */
/* @0x2580b4 add r0, r12, #16 */
/* @0x2580b8 bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue> */
/* @0x2580bc vmov d7, r0, r1 */
/* @0x2580c0 vcvt.s32.f64 s15, d7 */
/* @0x2580c4 vmov r10, s15 */
/* @0x2580c8 ldr r12, [sp, #0x10] */
/* @0x2580cc rsb r3, r5, r12 */
/* @0x2580d0 cmp r10, r3 */
/* @0x2580d4 movge r10, r3 */
/* @0x2580d8 add r10, r7, r10, lsl #1 */
/* @0x2580dc cmp r10, r7 */
/* @0x2580e0 bhs 0x2580f4 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x278> */
/* @0x2580e4 b 0x2581a8 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x32c> */
/* @0x2580e8 sub r10, r10, #2 */
/* @0x2580ec cmp r10, r7 */
/* @0x2580f0 blo 0x2581a8 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x32c> */
/* @0x2580f4 mov r0, r10 */
/* @0x2580f8 mov r1, r8 */
/* @0x2580fc mov r2, r5 */
/* @0x258100 bl 0xb6c40 <memcmp@plt> */
/* @0x258104 cmp r0, #0 */
/* @0x258108 bne 0x2580e8 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x25810c rsb r10, r7, r10 */
/* @0x258110 ldr r1, [sp, #0x44] */
/* @0x258114 ldr r12, [sp, #0x4] */
/* @0x258118 asr r10, r10, #1 */
/* @0x25811c sub r1, r1, #1 */
/* @0x258120 bic r1, r1, #-16777216 */
/* @0x258124 vmov s15, r10 */
/* @0x258128 bic r1, r1, #3 */
/* @0x25812c cmp r1, #0 */
/* @0x258130 vcvt.f64.s32 d7, s15 */
/* @0x258134 vmov r2, r3, d7 */
/* @0x258138 stm r12, {r2, r3} */
/* @0x25813c beq 0x2581c8 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x34c> */
/* @0x258140 ldr r1, [sp, #0x54] */
/* @0x258144 mov r3, #0 */
/* @0x258148 str r3, [sp, #0x40] */
/* @0x25814c mov r2, #5 */
/* @0x258150 sub r1, r1, #1 */
/* @0x258154 str r3, [sp, #0x38] */
/* @0x258158 bic r3, r1, #-16777216 */
/* @0x25815c str r2, [sp, #0x44] */
/* @0x258160 bic r3, r3, #3 */
/* @0x258164 cmp r3, #0 */
/* @0x258168 beq 0x2581d4 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x358> */
/* @0x25816c cmp r8, #0 */
/* @0x258170 mov r3, #0 */
/* @0x258174 mov r2, #5 */
/* @0x258178 str r3, [sp, #0x50] */
/* @0x25817c str r3, [sp, #0x48] */
/* @0x258180 str r2, [sp, #0x54] */
/* @0x258184 beq 0x258190 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x314> */
/* @0x258188 mov r0, r8 */
/* @0x25818c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x258190 cmp r7, #0 */
/* @0x258194 beq 0x2581a0 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x324> */
/* @0x258198 mov r0, r7 */
/* @0x25819c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2581a0 add sp, sp, #92 */
/* @0x2581a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2581a8 cmp r8, #0 */
/* @0x2581ac bne 0x258188 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x30c> */
/* @0x2581b0 b 0x258190 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x314> */
/* @0x2581b4 ldr r0, [pc, #0x2c] */
/* @0x2581b8 add r0, pc, r0 */
/* @0x2581bc bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2581c0 add sp, sp, #92 */
/* @0x2581c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2581c8 add r0, sp, #56 */
/* @0x2581cc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2581d0 b 0x258140 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x2c4> */
/* @0x2581d4 mov r0, r9 */
/* @0x2581d8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2581dc b 0x25816c <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x2f0> */
/* @0x2581e0 andeq r9, sp, r8, ror #1 */
/* @0x2581e4 andeq r9, sp, r12 */
/* @0x2581e8 muleq pc, r0, sp */

/* ── FUNC 0x2581ec · JS_String_GetOwnProperty(YYObjectBase*, RValue*, char const*) · size=504 · insn=126 */
/* @0x2581ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2581f0 vpush {d8} */
/* @0x2581f4 mov r8, r0 */
/* @0x2581f8 sub sp, sp, #60 */
/* @0x2581fc mov r0, r2 */
/* @0x258200 mov r7, r2 */
/* @0x258204 mov r6, r1 */
/* @0x258208 bl 0xd1f74 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc> */
/* @0x25820c cmn r0, #1 */
/* @0x258210 beq 0x258264 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x78> */
/* @0x258214 ldr r2, [r8, #0x4] */
/* @0x258218 cmp r2, #0 */
/* @0x25821c beq 0x2583cc <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x1e0> */
/* @0x258220 add r3, r2, r0, lsl #4 */
/* @0x258224 ldr r4, [r3, #0xc] */
/* @0x258228 mvn r0, #-16777216 */
/* @0x25822c ldr r12, [r3] */
/* @0x258230 ldr r1, [r3, #0x4] */
/* @0x258234 ldr r2, [r3, #0x8] */
/* @0x258238 str r4, [r6, #0xc] */
/* @0x25823c ldr r3, [r6, #0xc] */
/* @0x258240 str r12, [r6] */
/* @0x258244 cmp r3, r0 */
/* @0x258248 cmpne r3, #5 */
/* @0x25824c str r1, [r6, #0x4] */
/* @0x258250 str r2, [r6, #0x8] */
/* @0x258254 beq 0x258264 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x78> */
/* @0x258258 add sp, sp, #60 */
/* @0x25825c vpop {d8} */
/* @0x258260 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x258264 add r4, sp, #8 */
/* @0x258268 mov r1, r7 */
/* @0x25826c mov r3, #5 */
/* @0x258270 str r3, [sp, #0x14] */
/* @0x258274 mov r0, r4 */
/* @0x258278 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x25827c mov r0, r4 */
/* @0x258280 bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue> */
/* @0x258284 ldr r3, [sp, #0x14] */
/* @0x258288 sub r3, r3, #1 */
/* @0x25828c bic r3, r3, #-16777216 */
/* @0x258290 bic r3, r3, #3 */
/* @0x258294 cmp r3, #0 */
/* @0x258298 vmov d7, r0, r1 */
/* @0x25829c vcvt.s32.f64 s16, d7 */
/* @0x2582a0 beq 0x2583b4 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x1c8> */
/* @0x2582a4 vmov r2, s16 */
/* @0x2582a8 add r11, sp, #40 */
/* @0x2582ac add r10, sp, #24 */
/* @0x2582b0 mov r3, #0 */
/* @0x2582b4 mov r0, r11 */
/* @0x2582b8 mov r12, #5 */
/* @0x2582bc mov r1, r10 */
/* @0x2582c0 str r3, [sp, #0x10] */
/* @0x2582c4 str r3, [sp, #0x8] */
/* @0x2582c8 mov r4, #0 */
/* @0x2582cc str r3, [sp, #0x24] */
/* @0x2582d0 mov r5, #0 */
/* @0x2582d4 str r3, [sp, #0x30] */
/* @0x2582d8 mvn r9, #-16777216 */
/* @0x2582dc str r12, [sp, #0x14] */
/* @0x2582e0 strd r4, r5, [sp, #40] */
/* @0x2582e4 str r9, [sp, #0x34] */
/* @0x2582e8 cmp r2, #0 */
/* @0x2582ec rsblt r2, r2, #0 */
/* @0x2582f0 vmov s14, r2 */
/* @0x2582f4 vcvt.f64.s32 d7, s14 */
/* @0x2582f8 vstr d7, [sp, #24] */
/* @0x2582fc bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x258300 ldr r3, [sp, #0x28] */
/* @0x258304 mov r1, r7 */
/* @0x258308 ldr r0, [r3] */
/* @0x25830c bl 0xb6574 <strcmp@plt> */
/* @0x258310 ldr r3, [sp, #0x34] */
/* @0x258314 cmp r0, #0 */
/* @0x258318 bne 0x258390 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x1a4> */
/* @0x25831c sub r3, r3, #1 */
/* @0x258320 bic r3, r3, #-16777216 */
/* @0x258324 bic r3, r3, #3 */
/* @0x258328 cmp r3, #0 */
/* @0x25832c beq 0x2583c0 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x1d4> */
/* @0x258330 ldr r1, [pc, #0xa8] */
/* @0x258334 mov r0, r8 */
/* @0x258338 mov r4, #0 */
/* @0x25833c mov r5, #5 */
/* @0x258340 add r1, pc, r1 */
/* @0x258344 str r4, [sp, #0x30] */
/* @0x258348 str r4, [sp, #0x28] */
/* @0x25834c str r5, [sp, #0x34] */
/* @0x258350 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0x258354 vmov r2, s16 */
/* @0x258358 ldr r3, [r0] */
/* @0x25835c ldr r3, [r3, #0x8] */
/* @0x258360 cmp r2, r3 */
/* @0x258364 strge r5, [r6, #0xc] */
/* @0x258368 bge 0x258258 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x6c> */
/* @0x25836c mov r3, #1 */
/* @0x258370 str r10, [sp] */
/* @0x258374 mov r1, r8 */
/* @0x258378 mov r2, r4 */
/* @0x25837c mov r0, r6 */
/* @0x258380 bl 0x25540c <_Z26JS_String_prototype_charAtR6RValueP9CInstanceS2_iPS_> */
/* @0x258384 mov r3, #1 */
/* @0x258388 str r3, [r6, #0x8] */
/* @0x25838c b 0x258258 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x6c> */
/* @0x258390 sub r3, r3, #1 */
/* @0x258394 str r9, [r6, #0xc] */
/* @0x258398 and r3, r3, r9 */
/* @0x25839c bic r3, r3, #3 */
/* @0x2583a0 cmp r3, #0 */
/* @0x2583a4 bne 0x258258 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x6c> */
/* @0x2583a8 mov r0, r11 */
/* @0x2583ac bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2583b0 b 0x258258 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x6c> */
/* @0x2583b4 mov r0, r4 */
/* @0x2583b8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2583bc b 0x2582a4 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0xb8> */
/* @0x2583c0 mov r0, r11 */
/* @0x2583c4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2583c8 b 0x258330 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x144> */
/* @0x2583cc mov r1, r0 */
/* @0x2583d0 mov r0, r8 */
/* @0x2583d4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2583d8 mov r3, r0 */
/* @0x2583dc b 0x258224 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x38> */
/* @0x2583e0 andeq lr, pc, r12, lsl #16 */

/* ── FUNC 0x2583e4 · JS_String(RValue&, CInstance*, CInstance*, int, RValue*) · size=1112 · insn=278 */
/* @0x2583e4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2583e8 sub sp, sp, #124 */
/* @0x2583ec ldr r11, [pc, #0x404] */
/* @0x2583f0 mov r5, r0 */
/* @0x2583f4 ldr lr, [pc, #0x400] */
/* @0x2583f8 mov r9, r3 */
/* @0x2583fc add r11, pc, r11 */
/* @0x258400 ldr r4, [sp, #0xa0] */
/* @0x258404 ldr lr, [r11, lr] */
/* @0x258408 str r4, [sp] */
/* @0x25840c str lr, [sp, #0xc] */
/* @0x258410 ldr lr, [lr] */
/* @0x258414 str lr, [sp, #0x74] */
/* @0x258418 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x25841c ldr r6, [r5] */
/* @0x258420 ldr r2, [pc, #0x3d8] */
/* @0x258424 ldr r3, [pc, #0x3d8] */
/* @0x258428 add r2, pc, r2 */
/* @0x25842c str r2, [r6, #0x40] */
/* @0x258430 mov r0, r6 */
/* @0x258434 ldr r3, [r11, r3] */
/* @0x258438 ldr r1, [r3] */
/* @0x25843c str r1, [r6, #0x18] */
/* @0x258440 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x258444 ldr r2, [r6, #0x28] */
/* @0x258448 ldr r3, [pc, #0x3b8] */
/* @0x25844c cmp r9, #0 */
/* @0x258450 orr r2, r2, #1 */
/* @0x258454 str r2, [r6, #0x28] */
/* @0x258458 ldr r3, [r11, r3] */
/* @0x25845c str r3, [r6, #0x4c] */
/* @0x258460 bne 0x2585f4 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x210> */
/* @0x258464 add r7, sp, #36 */
/* @0x258468 ldr r1, [pc, #0x39c] */
/* @0x25846c mvn r3, #-16777216 */
/* @0x258470 str r9, [sp, #0x24] */
/* @0x258474 mov r0, r7 */
/* @0x258478 add r1, pc, r1 */
/* @0x25847c str r3, [sp, #0x30] */
/* @0x258480 add r5, sp, #20 */
/* @0x258484 str r9, [sp, #0x28] */
/* @0x258488 add r4, sp, #16 */
/* @0x25848c str r9, [sp, #0x2c] */
/* @0x258490 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x258494 ldr r1, [pc, #0x374] */
/* @0x258498 mov r0, r6 */
/* @0x25849c mov r2, r7 */
/* @0x2584a0 mov r3, r9 */
/* @0x2584a4 add r1, pc, r1 */
/* @0x2584a8 add r10, sp, #18 */
/* @0x2584ac bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x2584b0 ldr r3, [sp, #0x24] */
/* @0x2584b4 mov r0, #12 */
/* @0x2584b8 ldr r1, [r3] */
/* @0x2584bc str r1, [sp, #0x8] */
/* @0x2584c0 bl 0x27c524 <_Znwj> */
/* @0x2584c4 ldr r3, [pc, #0x348] */
/* @0x2584c8 ldr r1, [sp, #0x8] */
/* @0x2584cc ldr r3, [r11, r3] */
/* @0x2584d0 add r3, r3, #8 */
/* @0x2584d4 mov r8, r0 */
/* @0x2584d8 mov r0, r5 */
/* @0x2584dc str r3, [r8] */
/* @0x2584e0 bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc> */
/* @0x2584e4 b 0x2584f8 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x2584e8 mov r1, r4 */
/* @0x2584ec mov r2, r10 */
/* @0x2584f0 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_> */
/* @0x2584f4 add r9, r9, r0 */
/* @0x2584f8 mov r0, r5 */
/* @0x2584fc bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x258500 subs r11, r0, #0 */
/* @0x258504 bne 0x2584e8 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x258508 lsl r4, r9, #1 */
/* @0x25850c ldr r1, [pc, #0x304] */
/* @0x258510 str r9, [r8, #0x8] */
/* @0x258514 mov r3, #1 */
/* @0x258518 add r1, pc, r1 */
/* @0x25851c mov r2, #70 */
/* @0x258520 mov r0, r4 */
/* @0x258524 add r10, sp, #16 */
/* @0x258528 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x25852c mov r2, r4 */
/* @0x258530 mov r1, r11 */
/* @0x258534 add r9, sp, #18 */
/* @0x258538 mov r4, r11 */
/* @0x25853c str r0, [r8, #0x4] */
/* @0x258540 bl 0xb65b0 <memset@plt> */
/* @0x258544 mov r0, r5 */
/* @0x258548 bl 0x2423fc <_ZN23CCodepointIterator_UTF85ResetEv> */
/* @0x25854c b 0x258580 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x258550 mov r1, r10 */
/* @0x258554 mov r2, r9 */
/* @0x258558 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_> */
/* @0x25855c ldr r2, [r8, #0x4] */
/* @0x258560 ldrh r1, [sp, #16] */
/* @0x258564 lsl r3, r4, #1 */
/* @0x258568 strh r1, [r2, r3] */
/* @0x25856c cmp r0, #2 */
/* @0x258570 add r4, r4, r0 */
/* @0x258574 addeq r3, r2, r3 */
/* @0x258578 ldrheq r1, [sp, #18] */
/* @0x25857c strheq r1, [r3, #2] */
/* @0x258580 mov r0, r5 */
/* @0x258584 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x258588 subs r11, r0, #0 */
/* @0x25858c bne 0x258550 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x258590 ldr r1, [pc, #0x284] */
/* @0x258594 mov r2, r8 */
/* @0x258598 mov r0, r6 */
/* @0x25859c mov r3, #8 */
/* @0x2585a0 add r1, pc, r1 */
/* @0x2585a4 bl 0x199b20 <_ZN12YYObjectBase3AddEPKcPvi> */
/* @0x2585a8 ldr r1, [pc, #0x270] */
/* @0x2585ac mov r3, r11 */
/* @0x2585b0 mov r0, r6 */
/* @0x2585b4 mov r2, r11 */
/* @0x2585b8 add r1, pc, r1 */
/* @0x2585bc bl 0x199960 <_ZN12YYObjectBase3AddEPKcii> */
/* @0x2585c0 ldr r3, [sp, #0x30] */
/* @0x2585c4 sub r3, r3, #1 */
/* @0x2585c8 bic r3, r3, #-16777216 */
/* @0x2585cc bic r3, r3, #3 */
/* @0x2585d0 cmp r3, #0 */
/* @0x2585d4 beq 0x2587d8 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x3f4> */
/* @0x2585d8 ldr r12, [sp, #0xc] */
/* @0x2585dc ldr r2, [sp, #0x74] */
/* @0x2585e0 ldr r3, [r12] */
/* @0x2585e4 cmp r2, r3 */
/* @0x2585e8 bne 0x2587f4 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x410> */
/* @0x2585ec add sp, sp, #124 */
/* @0x2585f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2585f4 add r5, sp, #20 */
/* @0x2585f8 mov r1, r4 */
/* @0x2585fc mov r9, #0 */
/* @0x258600 mvn r3, #-16777216 */
/* @0x258604 mov r0, r5 */
/* @0x258608 str r9, [sp, #0x14] */
/* @0x25860c str r9, [sp, #0x18] */
/* @0x258610 str r9, [sp, #0x1c] */
/* @0x258614 str r3, [sp, #0x20] */
/* @0x258618 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x25861c cmp r0, #2 */
/* @0x258620 beq 0x2585d8 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0x258624 cmp r0, #1 */
/* @0x258628 beq 0x2587e4 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x400> */
/* @0x25862c ldr r2, [sp, #0x14] */
/* @0x258630 mov r0, r6 */
/* @0x258634 ldr r1, [pc, #0x1e8] */
/* @0x258638 mov r3, r9 */
/* @0x25863c add r7, sp, #36 */
/* @0x258640 add r8, sp, #16 */
/* @0x258644 ldr r2, [r2] */
/* @0x258648 add r1, pc, r1 */
/* @0x25864c bl 0x199aa8 <_ZN12YYObjectBase3AddEPKcS1_i> */
/* @0x258650 ldr r3, [sp, #0x14] */
/* @0x258654 mov r0, #12 */
/* @0x258658 add r10, sp, #18 */
/* @0x25865c ldr r1, [r3] */
/* @0x258660 str r1, [sp, #0x8] */
/* @0x258664 bl 0x27c524 <_Znwj> */
/* @0x258668 ldr r3, [pc, #0x1a4] */
/* @0x25866c ldr r1, [sp, #0x8] */
/* @0x258670 ldr r3, [r11, r3] */
/* @0x258674 add r3, r3, #8 */
/* @0x258678 mov r4, r0 */
/* @0x25867c mov r0, r7 */
/* @0x258680 str r3, [r4] */
/* @0x258684 bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc> */
/* @0x258688 b 0x25869c <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x2b8> */
/* @0x25868c mov r1, r8 */
/* @0x258690 mov r2, r10 */
/* @0x258694 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_> */
/* @0x258698 add r9, r9, r0 */
/* @0x25869c mov r0, r7 */
/* @0x2586a0 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x2586a4 subs r11, r0, #0 */
/* @0x2586a8 bne 0x25868c <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x2a8> */
/* @0x2586ac lsl r8, r9, #1 */
/* @0x2586b0 ldr r1, [pc, #0x170] */
/* @0x2586b4 str r9, [r4, #0x8] */
/* @0x2586b8 mov r3, #1 */
/* @0x2586bc add r1, pc, r1 */
/* @0x2586c0 mov r2, #70 */
/* @0x2586c4 mov r0, r8 */
/* @0x2586c8 add r10, sp, #16 */
/* @0x2586cc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2586d0 mov r2, r8 */
/* @0x2586d4 mov r1, r11 */
/* @0x2586d8 add r9, sp, #18 */
/* @0x2586dc mov r8, r11 */
/* @0x2586e0 str r0, [r4, #0x4] */
/* @0x2586e4 bl 0xb65b0 <memset@plt> */
/* @0x2586e8 mov r0, r7 */
/* @0x2586ec bl 0x2423fc <_ZN23CCodepointIterator_UTF85ResetEv> */
/* @0x2586f0 b 0x258724 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x340> */
/* @0x2586f4 mov r1, r10 */
/* @0x2586f8 mov r2, r9 */
/* @0x2586fc bl 0x2424c4 <_Z16CodepointToUTF16iRtS_> */
/* @0x258700 ldr r2, [r4, #0x4] */
/* @0x258704 ldrh r1, [sp, #16] */
/* @0x258708 lsl r3, r8, #1 */
/* @0x25870c strh r1, [r2, r3] */
/* @0x258710 cmp r0, #2 */
/* @0x258714 add r8, r8, r0 */
/* @0x258718 addeq r3, r2, r3 */
/* @0x25871c ldrheq r1, [sp, #18] */
/* @0x258720 strheq r1, [r3, #2] */
/* @0x258724 mov r0, r7 */
/* @0x258728 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x25872c subs r11, r0, #0 */
/* @0x258730 bne 0x2586f4 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x310> */
/* @0x258734 ldr r1, [pc, #0xf0] */
/* @0x258738 mov r2, r4 */
/* @0x25873c mov r0, r6 */
/* @0x258740 mov r3, #8 */
/* @0x258744 add r1, pc, r1 */
/* @0x258748 bl 0x199b20 <_ZN12YYObjectBase3AddEPKcPvi> */
/* @0x25874c ldr r2, [r4, #0x8] */
/* @0x258750 cmp r2, #0 */
/* @0x258754 ble 0x2587a0 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x3bc> */
/* @0x258758 ldr r10, [pc, #0xd0] */
/* @0x25875c add r8, sp, #52 */
/* @0x258760 mov r9, #5 */
/* @0x258764 add r10, pc, r10 */
/* @0x258768 mov r2, r11 */
/* @0x25876c mov r1, r10 */
/* @0x258770 mov r0, r8 */
/* @0x258774 add r11, r11, #1 */
/* @0x258778 bl 0xb6550 <sprintf@plt> */
/* @0x25877c mov r2, r7 */
/* @0x258780 mov r0, r6 */
/* @0x258784 mov r1, r8 */
/* @0x258788 mov r3, #7 */
/* @0x25878c str r9, [sp, #0x30] */
/* @0x258790 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x258794 ldr r2, [r4, #0x8] */
/* @0x258798 cmp r2, r11 */
/* @0x25879c bgt 0x258768 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x384> */
/* @0x2587a0 ldr r1, [pc, #0x8c] */
/* @0x2587a4 mov r3, #0 */
/* @0x2587a8 mov r0, r6 */
/* @0x2587ac add r1, pc, r1 */
/* @0x2587b0 bl 0x199960 <_ZN12YYObjectBase3AddEPKcii> */
/* @0x2587b4 ldr r3, [sp, #0x20] */
/* @0x2587b8 sub r3, r3, #1 */
/* @0x2587bc bic r3, r3, #-16777216 */
/* @0x2587c0 bic r3, r3, #3 */
/* @0x2587c4 cmp r3, #0 */
/* @0x2587c8 bne 0x2585d8 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0x2587cc mov r0, r5 */
/* @0x2587d0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2587d4 b 0x2585d8 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0x2587d8 mov r0, r7 */
/* @0x2587dc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2587e0 b 0x2585d8 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0x2587e4 ldr r0, [pc, #0x4c] */
/* @0x2587e8 add r0, pc, r0 */
/* @0x2587ec bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2587f0 b 0x2585d8 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0x2587f4 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2587f8 andseq r9, r9, r4, asr r8 */
/* @0x2587fc .word 0xffffbd00 */
/* @0x258800 andeq sp, pc, r8, lsl #8 */
/* @0x258804 .word 0xfffff960 */
/* @0x258808 .word 0xfffffb88 */
/* @0x25880c strheq r6, [sp], -lr */
/* @0x258810 andeq sp, pc, r12, rrx */
/* @0x258814 .word 0xfffff8a8 */
/* @0x258818 andeq r8, sp, r8, lsl r11 */
/* @0x25881c andeq lr, pc, r12, lsr #11 */
/* @0x258820 strheq r8, [sp], -r4 */
/* @0x258824 andeq r12, pc, r8, asr #29 */
/* @0x258828 andeq r8, sp, r4, ror r9 */
/* @0x25882c andeq lr, pc, r8, lsl #8 */
/* @0x258830 andeq r9, sp, r8, lsr #27 */
/* @0x258834 andeq r8, sp, r0, asr #1 */
/* @0x258838 andeq lr, pc, r0, lsl #7 */
