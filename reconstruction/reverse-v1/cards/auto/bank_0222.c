/* libyoyo.so 覆盖卡组 0222
 * 函数 0x24bf1c..0x24f2b0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x24bf1c · json_parse_jsarray(json_object*, RValue&) · size=156 · insn=39 */
/* @0x24bf1c push {r4, r5, r6, r7, r8, lr} */
/* @0x24bf20 sub sp, sp, #8 */
/* @0x24bf24 mov r4, r1 */
/* @0x24bf28 mov r7, r0 */
/* @0x24bf2c bl 0x27ede8 <json_object_array_length> */
/* @0x24bf30 mov r3, #0 */
/* @0x24bf34 mov r1, r3 */
/* @0x24bf38 str r3, [sp] */
/* @0x24bf3c mov r2, r3 */
/* @0x24bf40 mov r6, r0 */
/* @0x24bf44 mov r0, r4 */
/* @0x24bf48 mov r3, r6 */
/* @0x24bf4c bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_> */
/* @0x24bf50 ldr r0, [r4] */
/* @0x24bf54 ldr r3, [r0, #0x4] */
/* @0x24bf58 cmp r3, #0 */
/* @0x24bf5c beq 0x24bfac <_Z18json_parse_jsarrayP11json_objectR6RValue+0x90> */
/* @0x24bf60 add r0, r3, #16 */
/* @0x24bf64 ldr r3, [r0] */
/* @0x24bf68 cmp r6, #0 */
/* @0x24bf6c ldr r4, [r3, #0x4] */
/* @0x24bf70 ble 0x24bfa4 <_Z18json_parse_jsarrayP11json_objectR6RValue+0x88> */
/* @0x24bf74 mov r5, #0 */
/* @0x24bf78 mov r8, #6 */
/* @0x24bf7c mov r1, r5 */
/* @0x24bf80 mov r0, r7 */
/* @0x24bf84 bl 0x27ee00 <json_object_array_get_idx> */
/* @0x24bf88 add r5, r5, #1 */
/* @0x24bf8c mov r1, r4 */
/* @0x24bf90 add r4, r4, #16 */
/* @0x24bf94 bl 0x24beac <_Z10json_parseP11json_objectR6RValue> */
/* @0x24bf98 cmp r5, r6 */
/* @0x24bf9c str r8, [r4, #-0x8] */
/* @0x24bfa0 bne 0x24bf7c <_Z18json_parse_jsarrayP11json_objectR6RValue+0x60> */
/* @0x24bfa4 add sp, sp, #8 */
/* @0x24bfa8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x24bfac mov r1, #1 */
/* @0x24bfb0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24bfb4 b 0x24bf64 <_Z18json_parse_jsarrayP11json_objectR6RValue+0x48> */

/* ── FUNC 0x24bfb8 · JS_Argument_Get(YYObjectBase*, RValue*, char const*) · size=800 · insn=200 */
/* @0x24bfb8 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24bfbc mov r8, r0 */
/* @0x24bfc0 mov r0, #0 */
/* @0x24bfc4 mov r10, r2 */
/* @0x24bfc8 mov r9, r1 */
/* @0x24bfcc bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x24bfd0 ldr r3, [pc, #0x2fc] */
/* @0x24bfd4 mov r12, r10 */
/* @0x24bfd8 ldr r3, [pc, r3] */
/* @0x24bfdc ldr r4, [r3] */
/* @0x24bfe0 ldrb r3, [r12], #1 */
/* @0x24bfe4 cmp r3, #0 */
/* @0x24bfe8 add lr, r4, r3 */
/* @0x24bfec bne 0x24c0f4 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x13c> */
/* @0x24bff0 mov r0, r10 */
/* @0x24bff4 bl 0xb66c4 <atol@plt> */
/* @0x24bff8 ldr r3, [r8, #0x4] */
/* @0x24bffc cmp r3, #0 */
/* @0x24c000 mov r11, r0 */
/* @0x24c004 mov r4, r0 */
/* @0x24c008 asr r5, r0, #31 */
/* @0x24c00c beq 0x24c1d0 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x218> */
/* @0x24c010 add r0, r3, #16 */
/* @0x24c014 ldr r3, [r0] */
/* @0x24c018 mov r7, #0 */
/* @0x24c01c ldr r6, [r3, #0x24] */
/* @0x24c020 cmp r4, r6 */
/* @0x24c024 sbcs r3, r5, r7 */
/* @0x24c028 bge 0x24c100 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x148> */
/* @0x24c02c ldr r3, [r8, #0x4] */
/* @0x24c030 cmp r3, #0 */
/* @0x24c034 beq 0x24c234 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x27c> */
/* @0x24c038 add r0, r3, #16 */
/* @0x24c03c ldr r0, [r0] */
/* @0x24c040 ldr r4, [r0, #0x4] */
/* @0x24c044 cmp r4, #0 */
/* @0x24c048 beq 0x24c224 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x26c> */
/* @0x24c04c add r4, r4, r11, lsl #4 */
/* @0x24c050 ldr r2, [r9, #0xc] */
/* @0x24c054 bic r3, r2, #-16777216 */
/* @0x24c058 cmp r3, #1 */
/* @0x24c05c beq 0x24c134 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x17c> */
/* @0x24c060 cmp r3, #2 */
/* @0x24c064 bne 0x24c08c <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0xd4> */
/* @0x24c068 sub r3, r2, #1 */
/* @0x24c06c bic r3, r3, #-16777216 */
/* @0x24c070 bic r3, r3, #3 */
/* @0x24c074 cmp r3, #0 */
/* @0x24c078 beq 0x24c218 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x260> */
/* @0x24c07c mov r2, #0 */
/* @0x24c080 mov r3, #5 */
/* @0x24c084 str r2, [r9, #0x8] */
/* @0x24c088 str r3, [r9, #0xc] */
/* @0x24c08c ldr r3, [r4, #0xc] */
/* @0x24c090 mov r1, #0 */
/* @0x24c094 ldr r2, [r4, #0x8] */
/* @0x24c098 str r1, [r9] */
/* @0x24c09c str r3, [r9, #0xc] */
/* @0x24c0a0 ldr r3, [r4, #0xc] */
/* @0x24c0a4 str r2, [r9, #0x8] */
/* @0x24c0a8 bic r3, r3, #-16777216 */
/* @0x24c0ac cmp r3, #14 */
/* @0x24c0b0 addls pc, pc, r3, lsl #2 */
/* @0x24c0b4 b 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158> */
/* @0x24c0b8 b 0x24c128 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x170> */
/* @0x24c0bc b 0x24c18c <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x1d4> */
/* @0x24c0c0 b 0x24c1a4 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x1ec> */
/* @0x24c0c4 b 0x24c118 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x160> */
/* @0x24c0c8 b 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158> */
/* @0x24c0cc b 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158> */
/* @0x24c0d0 b 0x24c168 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x1b0> */
/* @0x24c0d4 b 0x24c118 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x160> */
/* @0x24c0d8 b 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158> */
/* @0x24c0dc b 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158> */
/* @0x24c0e0 b 0x24c128 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x170> */
/* @0x24c0e4 b 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158> */
/* @0x24c0e8 b 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158> */
/* @0x24c0ec b 0x24c128 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x170> */
/* @0x24c0f0 b 0x24c118 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x160> */
/* @0x24c0f4 ldrb r3, [lr, #0x1] */
/* @0x24c0f8 tst r3, #4 */
/* @0x24c0fc bne 0x24bfe0 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x28> */
/* @0x24c100 mov r0, r8 */
/* @0x24c104 mov r1, r9 */
/* @0x24c108 mov r2, r10 */
/* @0x24c10c bl 0x23d0f0 <_Z24JS_DefaultGetOwnPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x24c110 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24c114 b 0xd3a34 <_Z15PopContextStackv> */
/* @0x24c118 ldr r3, [r4] */
/* @0x24c11c str r3, [r9] */
/* @0x24c120 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24c124 b 0xd3a34 <_Z15PopContextStackv> */
/* @0x24c128 ldm r4, {r2, r3} */
/* @0x24c12c stm r9, {r2, r3} */
/* @0x24c130 b 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158> */
/* @0x24c134 ldr r5, [r9] */
/* @0x24c138 cmp r5, #0 */
/* @0x24c13c beq 0x24c15c <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x1a4> */
/* @0x24c140 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24c144 ldr r6, [r5, #0x4] */
/* @0x24c148 sub r6, r6, #1 */
/* @0x24c14c str r6, [r5, #0x4] */
/* @0x24c150 cmp r6, #0 */
/* @0x24c154 beq 0x24c1e0 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x228> */
/* @0x24c158 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24c15c mov r3, #0 */
/* @0x24c160 str r3, [r9] */
/* @0x24c164 b 0x24c08c <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0xd4> */
/* @0x24c168 ldr r3, [r4] */
/* @0x24c16c str r3, [r9] */
/* @0x24c170 ldr r3, [r4] */
/* @0x24c174 cmp r3, #0 */
/* @0x24c178 beq 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158> */
/* @0x24c17c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x24c180 ldr r1, [r4] */
/* @0x24c184 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x24c188 b 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158> */
/* @0x24c18c ldr r3, [r4] */
/* @0x24c190 cmp r3, #0 */
/* @0x24c194 ldrne r2, [r3, #0x4] */
/* @0x24c198 addne r2, r2, #1 */
/* @0x24c19c strne r2, [r3, #0x4] */
/* @0x24c1a0 b 0x24c11c <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x164> */
/* @0x24c1a4 ldr r3, [r4] */
/* @0x24c1a8 cmp r3, #0 */
/* @0x24c1ac str r3, [r9] */
/* @0x24c1b0 beq 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158> */
/* @0x24c1b4 ldr r1, [r3, #0x8] */
/* @0x24c1b8 ldr r2, [r3] */
/* @0x24c1bc cmp r1, #0 */
/* @0x24c1c0 streq r9, [r3, #0x8] */
/* @0x24c1c4 add r2, r2, #1 */
/* @0x24c1c8 str r2, [r3] */
/* @0x24c1cc b 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158> */
/* @0x24c1d0 mov r0, r8 */
/* @0x24c1d4 mov r1, #1 */
/* @0x24c1d8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24c1dc b 0x24c014 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x5c> */
/* @0x24c1e0 ldr r0, [r5] */
/* @0x24c1e4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24c1e8 str r6, [r5] */
/* @0x24c1ec str r6, [r5, #0x8] */
/* @0x24c1f0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24c1f4 ldr r6, [r5, #0x4] */
/* @0x24c1f8 sub r6, r6, #1 */
/* @0x24c1fc str r6, [r5, #0x4] */
/* @0x24c200 cmp r6, #0 */
/* @0x24c204 beq 0x24c244 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x28c> */
/* @0x24c208 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24c20c mov r0, r5 */
/* @0x24c210 bl 0x27d1d0 <_ZdlPv> */
/* @0x24c214 b 0x24c158 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x1a0> */
/* @0x24c218 mov r0, r9 */
/* @0x24c21c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24c220 b 0x24c07c <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0xc4> */
/* @0x24c224 mov r1, r11 */
/* @0x24c228 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24c22c mov r4, r0 */
/* @0x24c230 b 0x24c050 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x98> */
/* @0x24c234 mov r0, r8 */
/* @0x24c238 mov r1, #1 */
/* @0x24c23c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24c240 b 0x24c03c <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x84> */
/* @0x24c244 ldr r0, [r5] */
/* @0x24c248 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24c24c str r6, [r5] */
/* @0x24c250 str r6, [r5, #0x8] */
/* @0x24c254 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24c258 ldr r6, [r5, #0x4] */
/* @0x24c25c sub r6, r6, #1 */
/* @0x24c260 str r6, [r5, #0x4] */
/* @0x24c264 cmp r6, #0 */
/* @0x24c268 beq 0x24c27c <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x2c4> */
/* @0x24c26c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24c270 mov r0, r5 */
/* @0x24c274 bl 0x27d1d0 <_ZdlPv> */
/* @0x24c278 b 0x24c208 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x250> */
/* @0x24c27c ldr r0, [r5] */
/* @0x24c280 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24c284 str r6, [r5] */
/* @0x24c288 str r6, [r5, #0x8] */
/* @0x24c28c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24c290 ldr r6, [r5, #0x4] */
/* @0x24c294 sub r6, r6, #1 */
/* @0x24c298 str r6, [r5, #0x4] */
/* @0x24c29c cmp r6, #0 */
/* @0x24c2a0 bne 0x24c2c4 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x30c> */
/* @0x24c2a4 ldr r0, [r5] */
/* @0x24c2a8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24c2ac mov r0, r5 */
/* @0x24c2b0 str r6, [r5] */
/* @0x24c2b4 str r6, [r5, #0x8] */
/* @0x24c2b8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x24c2bc mov r0, r5 */
/* @0x24c2c0 bl 0x27d1d0 <_ZdlPv> */
/* @0x24c2c4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24c2c8 mov r0, r5 */
/* @0x24c2cc bl 0x27d1d0 <_ZdlPv> */
/* @0x24c2d0 b 0x24c26c <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x2b4> */
/* @0x24c2d4 andseq r1, r10, r8, lsr #19 */

/* ── FUNC 0x24c2d8 · F_JSDelete(RValue&, CInstance*, CInstance*, int, RValue*) · size=532 · insn=133 */
/* @0x24c2d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24c2dc sub sp, sp, #12 */
/* @0x24c2e0 mov r10, r0 */
/* @0x24c2e4 ldr r5, [sp, #0x30] */
/* @0x24c2e8 ldr r2, [r5, #0xc] */
/* @0x24c2ec sub r3, r2, #1 */
/* @0x24c2f0 bic r3, r3, #-16777216 */
/* @0x24c2f4 bics r4, r3, #3 */
/* @0x24c2f8 beq 0x24c320 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x24c2fc mov r3, #0 */
/* @0x24c300 mov r2, #5 */
/* @0x24c304 str r3, [r5, #0x8] */
/* @0x24c308 str r3, [r5] */
/* @0x24c30c str r2, [r5, #0xc] */
/* @0x24c310 str r3, [r10] */
/* @0x24c314 str r2, [r10, #0xc] */
/* @0x24c318 add sp, sp, #12 */
/* @0x24c31c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24c320 bic r2, r2, #-16777216 */
/* @0x24c324 cmp r2, #2 */
/* @0x24c328 beq 0x24c398 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x24c32c cmp r2, #3 */
/* @0x24c330 beq 0x24c370 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x24c334 cmp r2, #1 */
/* @0x24c338 bne 0x24c2fc <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x24c33c ldr r4, [r5] */
/* @0x24c340 cmp r4, #0 */
/* @0x24c344 beq 0x24c364 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x24c348 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24c34c ldr r6, [r4, #0x4] */
/* @0x24c350 sub r6, r6, #1 */
/* @0x24c354 str r6, [r4, #0x4] */
/* @0x24c358 cmp r6, #0 */
/* @0x24c35c beq 0x24c3d0 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x24c360 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24c364 mov r3, #0 */
/* @0x24c368 str r3, [r5] */
/* @0x24c36c b 0x24c2fc <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x24c370 ldr r3, [r5, #0x8] */
/* @0x24c374 tst r3, #8 */
/* @0x24c378 beq 0x24c2fc <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x24c37c ldr r0, [r5] */
/* @0x24c380 cmp r0, #0 */
/* @0x24c384 beq 0x24c2fc <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x24c388 ldr r3, [r0] */
/* @0x24c38c ldr r3, [r3, #0x4] */
/* @0x24c390 blx r3 */
/* @0x24c394 b 0x24c2fc <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x24c398 ldr r8, [r5] */
/* @0x24c39c cmp r8, #0 */
/* @0x24c3a0 beq 0x24c2fc <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x24c3a4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24c3a8 ldr r3, [r8] */
/* @0x24c3ac ldr r2, [r8, #0x8] */
/* @0x24c3b0 sub r3, r3, #1 */
/* @0x24c3b4 str r3, [r8] */
/* @0x24c3b8 cmp r5, r2 */
/* @0x24c3bc streq r4, [r8, #0x8] */
/* @0x24c3c0 cmp r3, #0 */
/* @0x24c3c4 ble 0x24c408 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x24c3c8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24c3cc b 0x24c2fc <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x24c3d0 ldr r0, [r4] */
/* @0x24c3d4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24c3d8 str r6, [r4] */
/* @0x24c3dc str r6, [r4, #0x8] */
/* @0x24c3e0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24c3e4 ldr r6, [r4, #0x4] */
/* @0x24c3e8 sub r6, r6, #1 */
/* @0x24c3ec str r6, [r4, #0x4] */
/* @0x24c3f0 cmp r6, #0 */
/* @0x24c3f4 beq 0x24c4c8 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x1f0> */
/* @0x24c3f8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24c3fc mov r0, r4 */
/* @0x24c400 bl 0x27d1d0 <_ZdlPv> */
/* @0x24c404 b 0x24c360 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x24c408 ldr r3, [r8, #0x10] */
/* @0x24c40c cmp r3, #0 */
/* @0x24c410 movgt r7, #0 */
/* @0x24c414 movgt r9, #5 */
/* @0x24c418 movgt r6, r7 */
/* @0x24c41c ble 0x24c4a0 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x24c420 ldr r3, [r8, #0x4] */
/* @0x24c424 add r2, r3, r7, lsl #3 */
/* @0x24c428 str r2, [sp, #0x4] */
/* @0x24c42c ldr r11, [r3, r7, lsl #3] */
/* @0x24c430 ldr r4, [r2, #0x4] */
/* @0x24c434 add r11, r4, r11, lsl #4 */
/* @0x24c438 cmp r4, r11 */
/* @0x24c43c blo 0x24c458 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x180> */
/* @0x24c440 b 0x24c4c0 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0x24c444 str r6, [r4, #0x8] */
/* @0x24c448 str r9, [r4, #0xc] */
/* @0x24c44c str r6, [r4], #16 */
/* @0x24c450 cmp r11, r4 */
/* @0x24c454 bls 0x24c47c <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x24c458 ldr r3, [r4, #0xc] */
/* @0x24c45c sub r3, r3, #1 */
/* @0x24c460 bic r3, r3, #-16777216 */
/* @0x24c464 bic r3, r3, #3 */
/* @0x24c468 cmp r3, #0 */
/* @0x24c46c bne 0x24c444 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x24c470 mov r0, r4 */
/* @0x24c474 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24c478 b 0x24c444 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x24c47c ldr r3, [sp, #0x4] */
/* @0x24c480 ldr r0, [r3, #0x4] */
/* @0x24c484 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x24c488 ldr r3, [r8, #0x10] */
/* @0x24c48c add r7, r7, #1 */
/* @0x24c490 ldr r2, [sp, #0x4] */
/* @0x24c494 cmp r7, r3 */
/* @0x24c498 str r6, [r2, #0x4] */
/* @0x24c49c blt 0x24c420 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x24c4a0 ldr r0, [r8, #0x4] */
/* @0x24c4a4 mov r4, #0 */
/* @0x24c4a8 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x24c4ac str r4, [r8, #0x4] */
/* @0x24c4b0 mov r0, r8 */
/* @0x24c4b4 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x24c4b8 str r4, [r5] */
/* @0x24c4bc b 0x24c3c8 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x24c4c0 mov r0, r4 */
/* @0x24c4c4 b 0x24c484 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0x24c4c8 ldr r0, [r4] */
/* @0x24c4cc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24c4d0 mov r0, r4 */
/* @0x24c4d4 str r6, [r4] */
/* @0x24c4d8 str r6, [r4, #0x8] */
/* @0x24c4dc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x24c4e0 mov r0, r4 */
/* @0x24c4e4 bl 0x27d1d0 <_ZdlPv> */
/* @0x24c4e8 b 0x24c3f8 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x120> */

/* ── FUNC 0x24c4ec · F_JSNewArray(RValue&, CInstance*, CInstance*, int, RValue*) · size=856 · insn=214 */
/* @0x24c4ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24c4f0 sub sp, sp, #20 */
/* @0x24c4f4 mov r6, r0 */
/* @0x24c4f8 mov r4, r3 */
/* @0x24c4fc ldr r5, [sp, #0x38] */
/* @0x24c500 cmp r3, #8 */
/* @0x24c504 movlt r3, #8 */
/* @0x24c508 str r5, [sp] */
/* @0x24c50c bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_> */
/* @0x24c510 ldr r0, [r6] */
/* @0x24c514 ldr r3, [r0, #0x4] */
/* @0x24c518 cmp r3, #0 */
/* @0x24c51c beq 0x24c78c <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x2a0> */
/* @0x24c520 add r0, r3, #16 */
/* @0x24c524 ldr r7, [r0] */
/* @0x24c528 mov r0, r7 */
/* @0x24c52c bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x24c530 subs r6, r4, #1 */
/* @0x24c534 str r4, [r7, #0x24] */
/* @0x24c538 addpl r5, r5, #16 */
/* @0x24c53c ldr r4, [r7, #0x4] */
/* @0x24c540 movpl r9, #0 */
/* @0x24c544 movpl r10, #7 */
/* @0x24c548 addpl r4, r4, #16 */
/* @0x24c54c bmi 0x24c614 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x24c550 ldr r2, [r4, #-0x4] */
/* @0x24c554 sub r8, r5, #16 */
/* @0x24c558 sub r7, r4, #16 */
/* @0x24c55c bic r3, r2, #-16777216 */
/* @0x24c560 cmp r3, #1 */
/* @0x24c564 beq 0x24c694 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x24c568 cmp r3, #2 */
/* @0x24c56c bne 0x24c590 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x24c570 sub r2, r2, #1 */
/* @0x24c574 bic r2, r2, #-16777216 */
/* @0x24c578 bic r2, r2, #3 */
/* @0x24c57c cmp r2, #0 */
/* @0x24c580 beq 0x24c700 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x24c584 mov r3, #5 */
/* @0x24c588 str r9, [r4, #-0x8] */
/* @0x24c58c str r3, [r4, #-0x4] */
/* @0x24c590 str r9, [r4, #-0x10] */
/* @0x24c594 ldr r3, [r5, #-0x4] */
/* @0x24c598 str r3, [r4, #-0x4] */
/* @0x24c59c ldr r3, [r5, #-0x8] */
/* @0x24c5a0 str r3, [r4, #-0x8] */
/* @0x24c5a4 ldr r3, [r5, #-0x4] */
/* @0x24c5a8 bic r3, r3, #-16777216 */
/* @0x24c5ac cmp r3, #14 */
/* @0x24c5b0 addls pc, pc, r3, lsl #2 */
/* @0x24c5b4 b 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x24c5b8 b 0x24c620 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x24c5bc b 0x24c67c <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x190> */
/* @0x24c5c0 b 0x24c650 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x24c5c4 b 0x24c5f4 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x24c5c8 b 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x24c5cc b 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x24c5d0 b 0x24c62c <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x24c5d4 b 0x24c5f4 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x24c5d8 b 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x24c5dc b 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x24c5e0 b 0x24c620 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x24c5e4 b 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x24c5e8 b 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x24c5ec b 0x24c620 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x24c5f0 b 0x24c5f4 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x24c5f4 ldr r3, [r5, #-0x10] */
/* @0x24c5f8 str r3, [r4, #-0x10] */
/* @0x24c5fc sub r6, r6, #1 */
/* @0x24c600 str r10, [r4, #-0x8] */
/* @0x24c604 cmn r6, #1 */
/* @0x24c608 add r5, r5, #16 */
/* @0x24c60c add r4, r4, #16 */
/* @0x24c610 bne 0x24c550 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x24c614 add sp, sp, #20 */
/* @0x24c618 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24c61c b 0xd3a34 <_Z15PopContextStackv> */
/* @0x24c620 ldm r8, {r2, r3} */
/* @0x24c624 stm r7, {r2, r3} */
/* @0x24c628 b 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x24c62c ldr r3, [r5, #-0x10] */
/* @0x24c630 str r3, [r4, #-0x10] */
/* @0x24c634 ldr r3, [r5, #-0x10] */
/* @0x24c638 cmp r3, #0 */
/* @0x24c63c beq 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x24c640 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x24c644 ldr r1, [r5, #-0x10] */
/* @0x24c648 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x24c64c b 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x24c650 ldr r3, [r5, #-0x10] */
/* @0x24c654 cmp r3, #0 */
/* @0x24c658 str r3, [r4, #-0x10] */
/* @0x24c65c beq 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x24c660 ldr r1, [r3, #0x8] */
/* @0x24c664 ldr r2, [r3] */
/* @0x24c668 cmp r1, #0 */
/* @0x24c66c streq r7, [r3, #0x8] */
/* @0x24c670 add r2, r2, #1 */
/* @0x24c674 str r2, [r3] */
/* @0x24c678 b 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x24c67c ldr r3, [r5, #-0x10] */
/* @0x24c680 cmp r3, #0 */
/* @0x24c684 ldrne r2, [r3, #0x4] */
/* @0x24c688 addne r2, r2, #1 */
/* @0x24c68c strne r2, [r3, #0x4] */
/* @0x24c690 b 0x24c5f8 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x24c694 ldr r11, [r4, #-0x10] */
/* @0x24c698 cmp r11, #0 */
/* @0x24c69c beq 0x24c590 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x24c6a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24c6a4 ldr r2, [r11, #0x4] */
/* @0x24c6a8 sub r2, r2, #1 */
/* @0x24c6ac str r2, [r11, #0x4] */
/* @0x24c6b0 cmp r2, #0 */
/* @0x24c6b4 beq 0x24c6c0 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x1d4> */
/* @0x24c6b8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24c6bc b 0x24c590 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x24c6c0 ldr r0, [r11] */
/* @0x24c6c4 str r2, [sp, #0xc] */
/* @0x24c6c8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24c6cc ldr r2, [sp, #0xc] */
/* @0x24c6d0 str r2, [r11] */
/* @0x24c6d4 str r2, [r11, #0x8] */
/* @0x24c6d8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24c6dc ldr r2, [r11, #0x4] */
/* @0x24c6e0 sub r2, r2, #1 */
/* @0x24c6e4 str r2, [r11, #0x4] */
/* @0x24c6e8 cmp r2, #0 */
/* @0x24c6ec beq 0x24c70c <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x220> */
/* @0x24c6f0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24c6f4 mov r0, r11 */
/* @0x24c6f8 bl 0x27d1d0 <_ZdlPv> */
/* @0x24c6fc b 0x24c6b8 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x1cc> */
/* @0x24c700 mov r0, r7 */
/* @0x24c704 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24c708 b 0x24c584 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x24c70c ldr r0, [r11] */
/* @0x24c710 str r2, [sp, #0xc] */
/* @0x24c714 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24c718 ldr r2, [sp, #0xc] */
/* @0x24c71c str r2, [r11] */
/* @0x24c720 str r2, [r11, #0x8] */
/* @0x24c724 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24c728 ldr r2, [r11, #0x4] */
/* @0x24c72c sub r2, r2, #1 */
/* @0x24c730 str r2, [r11, #0x4] */
/* @0x24c734 cmp r2, #0 */
/* @0x24c738 beq 0x24c74c <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x260> */
/* @0x24c73c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24c740 mov r0, r11 */
/* @0x24c744 bl 0x27d1d0 <_ZdlPv> */
/* @0x24c748 b 0x24c6f0 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x204> */
/* @0x24c74c ldr r0, [r11] */
/* @0x24c750 str r2, [sp, #0xc] */
/* @0x24c754 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24c758 ldr r2, [sp, #0xc] */
/* @0x24c75c str r2, [r11] */
/* @0x24c760 str r2, [r11, #0x8] */
/* @0x24c764 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24c768 ldr r2, [r11, #0x4] */
/* @0x24c76c sub r2, r2, #1 */
/* @0x24c770 str r2, [r11, #0x4] */
/* @0x24c774 cmp r2, #0 */
/* @0x24c778 beq 0x24c798 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x2ac> */
/* @0x24c77c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24c780 mov r0, r11 */
/* @0x24c784 bl 0x27d1d0 <_ZdlPv> */
/* @0x24c788 b 0x24c73c <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x250> */
/* @0x24c78c mov r1, #1 */
/* @0x24c790 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24c794 b 0x24c524 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x24c798 ldr r0, [r11] */
/* @0x24c79c str r2, [sp, #0xc] */
/* @0x24c7a0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24c7a4 ldr r2, [sp, #0xc] */
/* @0x24c7a8 str r2, [r11] */
/* @0x24c7ac str r2, [r11, #0x8] */
/* @0x24c7b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24c7b4 ldr r2, [r11, #0x4] */
/* @0x24c7b8 sub r2, r2, #1 */
/* @0x24c7bc str r2, [r11, #0x4] */
/* @0x24c7c0 cmp r2, #0 */
/* @0x24c7c4 beq 0x24c7d8 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x2ec> */
/* @0x24c7c8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24c7cc mov r0, r11 */
/* @0x24c7d0 bl 0x27d1d0 <_ZdlPv> */
/* @0x24c7d4 b 0x24c77c <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x290> */
/* @0x24c7d8 ldr r0, [r11] */
/* @0x24c7dc str r2, [sp, #0xc] */
/* @0x24c7e0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24c7e4 ldr r2, [sp, #0xc] */
/* @0x24c7e8 str r2, [r11] */
/* @0x24c7ec str r2, [r11, #0x8] */
/* @0x24c7f0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24c7f4 ldr r2, [r11, #0x4] */
/* @0x24c7f8 sub r2, r2, #1 */
/* @0x24c7fc str r2, [r11, #0x4] */
/* @0x24c800 cmp r2, #0 */
/* @0x24c804 beq 0x24c818 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x32c> */
/* @0x24c808 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24c80c mov r0, r11 */
/* @0x24c810 bl 0x27d1d0 <_ZdlPv> */
/* @0x24c814 b 0x24c7c8 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x2dc> */
/* @0x24c818 ldr r0, [r11] */
/* @0x24c81c str r2, [sp, #0xc] */
/* @0x24c820 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24c824 ldr r2, [sp, #0xc] */
/* @0x24c828 mov r0, r11 */
/* @0x24c82c str r2, [r11] */
/* @0x24c830 str r2, [r11, #0x8] */
/* @0x24c834 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x24c838 mov r0, r11 */
/* @0x24c83c bl 0x27d1d0 <_ZdlPv> */
/* @0x24c840 b 0x24c808 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x31c> */

/* ── FUNC 0x24c844 · F_JS_Object_DefaultValue(YYObjectBase*, RValue&, int) · size=1312 · insn=328 */
/* @0x24c844 cmp r2, #10 */
/* @0x24c848 push {r4, r5, r6, r7, r8, lr} */
/* @0x24c84c mov r4, r0 */
/* @0x24c850 sub sp, sp, #56 */
/* @0x24c854 mov r5, r1 */
/* @0x24c858 bne 0x24c8c8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x84> */
/* @0x24c85c add r7, sp, #8 */
/* @0x24c860 ldr r2, [pc, #0x4e4] */
/* @0x24c864 mov r0, r4 */
/* @0x24c868 mov r8, #5 */
/* @0x24c86c add r2, pc, r2 */
/* @0x24c870 mov r1, r7 */
/* @0x24c874 str r8, [sp, #0x14] */
/* @0x24c878 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x24c87c mov r0, r7 */
/* @0x24c880 bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0x24c884 cmp r0, #0 */
/* @0x24c888 bne 0x24ca6c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x228> */
/* @0x24c88c ldr r2, [pc, #0x4bc] */
/* @0x24c890 add r7, sp, #24 */
/* @0x24c894 mov r0, r4 */
/* @0x24c898 add r2, pc, r2 */
/* @0x24c89c mov r1, r7 */
/* @0x24c8a0 mov r8, #5 */
/* @0x24c8a4 str r8, [sp, #0x24] */
/* @0x24c8a8 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x24c8ac mov r0, r7 */
/* @0x24c8b0 bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0x24c8b4 cmp r0, #0 */
/* @0x24c8b8 bne 0x24cb0c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2c8> */
/* @0x24c8bc mov r0, #1 */
/* @0x24c8c0 add sp, sp, #56 */
/* @0x24c8c4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x24c8c8 cmp r2, #7 */
/* @0x24c8cc cmpne r2, #1 */
/* @0x24c8d0 bls 0x24c9f0 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x1ac> */
/* @0x24c8d4 ldr r1, [pc, #0x478] */
/* @0x24c8d8 ldr r0, [r0, #0x40] */
/* @0x24c8dc add r1, pc, r1 */
/* @0x24c8e0 bl 0xb6574 <strcmp@plt> */
/* @0x24c8e4 cmp r0, #0 */
/* @0x24c8e8 bne 0x24c85c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x18> */
/* @0x24c8ec add r7, sp, #8 */
/* @0x24c8f0 ldr r2, [pc, #0x460] */
/* @0x24c8f4 mov r0, r4 */
/* @0x24c8f8 mov r8, #5 */
/* @0x24c8fc add r2, pc, r2 */
/* @0x24c900 mov r1, r7 */
/* @0x24c904 str r8, [sp, #0x14] */
/* @0x24c908 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x24c90c mov r0, r7 */
/* @0x24c910 bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0x24c914 cmp r0, #0 */
/* @0x24c918 beq 0x24ca48 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x204> */
/* @0x24c91c add r6, sp, #40 */
/* @0x24c920 mov r3, #0 */
/* @0x24c924 mov r2, r7 */
/* @0x24c928 str r3, [sp] */
/* @0x24c92c mov r1, r6 */
/* @0x24c930 mov r0, r4 */
/* @0x24c934 str r8, [sp, #0x34] */
/* @0x24c938 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0x24c93c cmp r0, #2 */
/* @0x24c940 beq 0x24c8c0 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x7c> */
/* @0x24c944 mov r0, r6 */
/* @0x24c948 bl 0x241dc0 <_Z16F_JS_IsPrimitiveR6RValue> */
/* @0x24c94c cmp r0, #0 */
/* @0x24c950 beq 0x24ca28 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x1e4> */
/* @0x24c954 ldr r2, [r5, #0xc] */
/* @0x24c958 bic r3, r2, #-16777216 */
/* @0x24c95c cmp r3, #1 */
/* @0x24c960 beq 0x24cc18 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x3d4> */
/* @0x24c964 cmp r3, #2 */
/* @0x24c968 bne 0x24c988 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x144> */
/* @0x24c96c sub r3, r2, #1 */
/* @0x24c970 bic r3, r3, #-16777216 */
/* @0x24c974 bic r3, r3, #3 */
/* @0x24c978 cmp r3, #0 */
/* @0x24c97c bne 0x24c988 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x144> */
/* @0x24c980 mov r0, r5 */
/* @0x24c984 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24c988 ldr r3, [sp, #0x34] */
/* @0x24c98c mov r0, #0 */
/* @0x24c990 ldr r1, [sp, #0x30] */
/* @0x24c994 bic r2, r3, #-16777216 */
/* @0x24c998 str r0, [r5] */
/* @0x24c99c str r3, [r5, #0xc] */
/* @0x24c9a0 mov r0, r3 */
/* @0x24c9a4 str r1, [r5, #0x8] */
/* @0x24c9a8 cmp r2, #14 */
/* @0x24c9ac addls pc, pc, r2, lsl #2 */
/* @0x24c9b0 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4> */
/* @0x24c9b4 b 0x24cbb8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x374> */
/* @0x24c9b8 b 0x24cbf4 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x3b0> */
/* @0x24c9bc b 0x24cbc8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x384> */
/* @0x24c9c0 b 0x24cb88 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x344> */
/* @0x24c9c4 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4> */
/* @0x24c9c8 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4> */
/* @0x24c9cc b 0x24cac8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x284> */
/* @0x24c9d0 b 0x24cb88 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x344> */
/* @0x24c9d4 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4> */
/* @0x24c9d8 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4> */
/* @0x24c9dc b 0x24cbb8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x374> */
/* @0x24c9e0 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4> */
/* @0x24c9e4 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4> */
/* @0x24c9e8 b 0x24cbb8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x374> */
/* @0x24c9ec b 0x24cb88 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x344> */
/* @0x24c9f0 cmp r2, #10 */
/* @0x24c9f4 addls pc, pc, r2, lsl #2 */
/* @0x24c9f8 b 0x24ca5c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x218> */
/* @0x24c9fc b 0x24c85c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x18> */
/* @0x24ca00 b 0x24c8ec <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0xa8> */
/* @0x24ca04 b 0x24ca5c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x218> */
/* @0x24ca08 b 0x24ca5c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x218> */
/* @0x24ca0c b 0x24ca5c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x218> */
/* @0x24ca10 b 0x24ca5c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x218> */
/* @0x24ca14 b 0x24ca5c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x218> */
/* @0x24ca18 b 0x24c85c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x18> */
/* @0x24ca1c b 0x24ca5c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x218> */
/* @0x24ca20 b 0x24ca5c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x218> */
/* @0x24ca24 b 0x24c85c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x18> */
/* @0x24ca28 ldr r3, [sp, #0x34] */
/* @0x24ca2c sub r3, r3, #1 */
/* @0x24ca30 bic r3, r3, #-16777216 */
/* @0x24ca34 bic r3, r3, #3 */
/* @0x24ca38 cmp r3, #0 */
/* @0x24ca3c bne 0x24ca48 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x204> */
/* @0x24ca40 mov r0, r6 */
/* @0x24ca44 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24ca48 ldr r2, [pc, #0x30c] */
/* @0x24ca4c add r7, sp, #24 */
/* @0x24ca50 mov r0, r4 */
/* @0x24ca54 add r2, pc, r2 */
/* @0x24ca58 b 0x24c89c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x58> */
/* @0x24ca5c ldr r0, [pc, #0x2fc] */
/* @0x24ca60 add r0, pc, r0 */
/* @0x24ca64 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x24ca68 b 0x24c8bc <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x78> */
/* @0x24ca6c add r6, sp, #40 */
/* @0x24ca70 mov r3, #0 */
/* @0x24ca74 mov r2, r7 */
/* @0x24ca78 str r3, [sp] */
/* @0x24ca7c mov r1, r6 */
/* @0x24ca80 mov r0, r4 */
/* @0x24ca84 str r8, [sp, #0x34] */
/* @0x24ca88 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0x24ca8c cmp r0, #2 */
/* @0x24ca90 beq 0x24c8c0 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x7c> */
/* @0x24ca94 mov r0, r6 */
/* @0x24ca98 bl 0x241dc0 <_Z16F_JS_IsPrimitiveR6RValue> */
/* @0x24ca9c cmp r0, #0 */
/* @0x24caa0 bne 0x24c954 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x110> */
/* @0x24caa4 ldr r3, [sp, #0x34] */
/* @0x24caa8 sub r3, r3, #1 */
/* @0x24caac bic r3, r3, #-16777216 */
/* @0x24cab0 bic r3, r3, #3 */
/* @0x24cab4 cmp r3, #0 */
/* @0x24cab8 bne 0x24c88c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x48> */
/* @0x24cabc mov r0, r6 */
/* @0x24cac0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24cac4 b 0x24c88c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x48> */
/* @0x24cac8 ldr r3, [sp, #0x28] */
/* @0x24cacc cmp r3, #0 */
/* @0x24cad0 str r3, [r5] */
/* @0x24cad4 beq 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4> */
/* @0x24cad8 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x24cadc ldr r1, [sp, #0x28] */
/* @0x24cae0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x24cae4 ldr r0, [sp, #0x34] */
/* @0x24cae8 sub r0, r0, #1 */
/* @0x24caec bic r0, r0, #-16777216 */
/* @0x24caf0 bics r4, r0, #3 */
/* @0x24caf4 movne r0, #0 */
/* @0x24caf8 bne 0x24c8c0 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x7c> */
/* @0x24cafc mov r0, r6 */
/* @0x24cb00 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24cb04 mov r0, r4 */
/* @0x24cb08 b 0x24c8c0 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x7c> */
/* @0x24cb0c add r6, sp, #40 */
/* @0x24cb10 mov r3, #0 */
/* @0x24cb14 mov r0, r4 */
/* @0x24cb18 mov r2, r7 */
/* @0x24cb1c mov r1, r6 */
/* @0x24cb20 str r3, [sp] */
/* @0x24cb24 str r8, [sp, #0x34] */
/* @0x24cb28 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0x24cb2c cmp r0, #2 */
/* @0x24cb30 beq 0x24c8c0 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x7c> */
/* @0x24cb34 mov r0, r6 */
/* @0x24cb38 bl 0x241dc0 <_Z16F_JS_IsPrimitiveR6RValue> */
/* @0x24cb3c cmp r0, #0 */
/* @0x24cb40 beq 0x24cb94 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x350> */
/* @0x24cb44 ldr r2, [r5, #0xc] */
/* @0x24cb48 bic r3, r2, #-16777216 */
/* @0x24cb4c cmp r3, #1 */
/* @0x24cb50 bne 0x24c964 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x120> */
/* @0x24cb54 ldr r4, [r5] */
/* @0x24cb58 cmp r4, #0 */
/* @0x24cb5c beq 0x24cb7c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x338> */
/* @0x24cb60 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24cb64 ldr r7, [r4, #0x4] */
/* @0x24cb68 sub r7, r7, #1 */
/* @0x24cb6c str r7, [r4, #0x4] */
/* @0x24cb70 cmp r7, #0 */
/* @0x24cb74 beq 0x24cc94 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x450> */
/* @0x24cb78 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24cb7c mov r3, #0 */
/* @0x24cb80 str r3, [r5] */
/* @0x24cb84 b 0x24c988 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x144> */
/* @0x24cb88 ldr r3, [sp, #0x28] */
/* @0x24cb8c str r3, [r5] */
/* @0x24cb90 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4> */
/* @0x24cb94 ldr r3, [sp, #0x34] */
/* @0x24cb98 sub r3, r3, #1 */
/* @0x24cb9c bic r3, r3, #-16777216 */
/* @0x24cba0 bic r3, r3, #3 */
/* @0x24cba4 cmp r3, #0 */
/* @0x24cba8 bne 0x24c8bc <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x78> */
/* @0x24cbac mov r0, r6 */
/* @0x24cbb0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24cbb4 b 0x24c8bc <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x78> */
/* @0x24cbb8 ldr r2, [sp, #0x28] */
/* @0x24cbbc ldr r3, [sp, #0x2c] */
/* @0x24cbc0 stm r5, {r2, r3} */
/* @0x24cbc4 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4> */
/* @0x24cbc8 ldr r3, [sp, #0x28] */
/* @0x24cbcc cmp r3, #0 */
/* @0x24cbd0 str r3, [r5] */
/* @0x24cbd4 beq 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4> */
/* @0x24cbd8 ldr r1, [r3, #0x8] */
/* @0x24cbdc ldr r2, [r3] */
/* @0x24cbe0 cmp r1, #0 */
/* @0x24cbe4 streq r5, [r3, #0x8] */
/* @0x24cbe8 add r2, r2, #1 */
/* @0x24cbec str r2, [r3] */
/* @0x24cbf0 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4> */
/* @0x24cbf4 ldr r2, [sp, #0x28] */
/* @0x24cbf8 cmp r2, #0 */
/* @0x24cbfc ldrne r3, [r2, #0x4] */
/* @0x24cc00 addne r3, r3, #1 */
/* @0x24cc04 strne r3, [r2, #0x4] */
/* @0x24cc08 ldrne r3, [sp, #0x34] */
/* @0x24cc0c str r2, [r5] */
/* @0x24cc10 mov r0, r3 */
/* @0x24cc14 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4> */
/* @0x24cc18 ldr r4, [r5] */
/* @0x24cc1c cmp r4, #0 */
/* @0x24cc20 beq 0x24cb7c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x338> */
/* @0x24cc24 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24cc28 ldr r7, [r4, #0x4] */
/* @0x24cc2c sub r7, r7, #1 */
/* @0x24cc30 str r7, [r4, #0x4] */
/* @0x24cc34 cmp r7, #0 */
/* @0x24cc38 bne 0x24cb78 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x334> */
/* @0x24cc3c ldr r0, [r4] */
/* @0x24cc40 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24cc44 str r7, [r4] */
/* @0x24cc48 str r7, [r4, #0x8] */
/* @0x24cc4c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24cc50 ldr r7, [r4, #0x4] */
/* @0x24cc54 sub r7, r7, #1 */
/* @0x24cc58 str r7, [r4, #0x4] */
/* @0x24cc5c cmp r7, #0 */
/* @0x24cc60 bne 0x24cc84 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x440> */
/* @0x24cc64 ldr r0, [r4] */
/* @0x24cc68 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24cc6c mov r0, r4 */
/* @0x24cc70 str r7, [r4] */
/* @0x24cc74 str r7, [r4, #0x8] */
/* @0x24cc78 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x24cc7c mov r0, r4 */
/* @0x24cc80 bl 0x27d1d0 <_ZdlPv> */
/* @0x24cc84 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24cc88 mov r0, r4 */
/* @0x24cc8c bl 0x27d1d0 <_ZdlPv> */
/* @0x24cc90 b 0x24cb78 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x334> */
/* @0x24cc94 ldr r0, [r4] */
/* @0x24cc98 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24cc9c str r7, [r4] */
/* @0x24cca0 str r7, [r4, #0x8] */
/* @0x24cca4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24cca8 ldr r7, [r4, #0x4] */
/* @0x24ccac sub r7, r7, #1 */
/* @0x24ccb0 str r7, [r4, #0x4] */
/* @0x24ccb4 cmp r7, #0 */
/* @0x24ccb8 bne 0x24cc84 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x440> */
/* @0x24ccbc ldr r0, [r4] */
/* @0x24ccc0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24ccc4 str r7, [r4] */
/* @0x24ccc8 str r7, [r4, #0x8] */
/* @0x24cccc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24ccd0 ldr r7, [r4, #0x4] */
/* @0x24ccd4 sub r7, r7, #1 */
/* @0x24ccd8 str r7, [r4, #0x4] */
/* @0x24ccdc cmp r7, #0 */
/* @0x24cce0 beq 0x24ccf4 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x4b0> */
/* @0x24cce4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24cce8 mov r0, r4 */
/* @0x24ccec bl 0x27d1d0 <_ZdlPv> */
/* @0x24ccf0 b 0x24cc84 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x440> */
/* @0x24ccf4 ldr r0, [r4] */
/* @0x24ccf8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24ccfc str r7, [r4] */
/* @0x24cd00 str r7, [r4, #0x8] */
/* @0x24cd04 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24cd08 ldr r7, [r4, #0x4] */
/* @0x24cd0c sub r7, r7, #1 */
/* @0x24cd10 str r7, [r4, #0x4] */
/* @0x24cd14 cmp r7, #0 */
/* @0x24cd18 bne 0x24cd3c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x4f8> */
/* @0x24cd1c ldr r0, [r4] */
/* @0x24cd20 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24cd24 mov r0, r4 */
/* @0x24cd28 str r7, [r4] */
/* @0x24cd2c str r7, [r4, #0x8] */
/* @0x24cd30 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x24cd34 mov r0, r4 */
/* @0x24cd38 bl 0x27d1d0 <_ZdlPv> */
/* @0x24cd3c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24cd40 mov r0, r4 */
/* @0x24cd44 bl 0x27d1d0 <_ZdlPv> */
/* @0x24cd48 b 0x24cce4 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x4a0> */
/* @0x24cd4c andseq r8, r0, r12, ror #27 */
/* @0x24cd50 andeq r5, lr, r8, ror r12 */
/* @0x24cd54 andseq r9, r0, r0, lsr #2 */
/* @0x24cd58 andeq r5, lr, r4, lsl r12 */
/* @0x24cd5c andseq r8, r0, r4, lsl #24 */
/* @0x24cd60 andseq r9, r0, r4, lsl #8 */

/* ── FUNC 0x24cd64 · F_JS_ToPrimitive(RValue&, RValue&, int) · size=584 · insn=146 */
/* @0x24cd64 push {r3, r4, r5, r6, r7, lr} */
/* @0x24cd68 mov r4, r1 */
/* @0x24cd6c ldr r1, [r1, #0xc] */
/* @0x24cd70 mov r5, r0 */
/* @0x24cd74 bic r3, r1, #-16777216 */
/* @0x24cd78 cmp r3, #13 */
/* @0x24cd7c bhi 0x24cda0 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x3c> */
/* @0x24cd80 mov r6, #1 */
/* @0x24cd84 movw r12, #0x34a3 */
/* @0x24cd88 lsl r6, r6, r3 */
/* @0x24cd8c and r12, r6, r12 */
/* @0x24cd90 cmp r12, #0 */
/* @0x24cd94 bne 0x24cdb8 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x54> */
/* @0x24cd98 tst r6, #64 */
/* @0x24cd9c bne 0x24ceb8 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x154> */
/* @0x24cda0 ldr r0, [pc, #0x200] */
/* @0x24cda4 mov r1, r3 */
/* @0x24cda8 add r0, pc, r0 */
/* @0x24cdac bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x24cdb0 mov r0, #1 */
/* @0x24cdb4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x24cdb8 ldr r2, [r0, #0xc] */
/* @0x24cdbc bic r3, r2, #-16777216 */
/* @0x24cdc0 cmp r3, #1 */
/* @0x24cdc4 beq 0x24ce6c <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x108> */
/* @0x24cdc8 cmp r3, #2 */
/* @0x24cdcc bne 0x24cdf8 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x94> */
/* @0x24cdd0 sub r2, r2, #1 */
/* @0x24cdd4 bic r2, r2, #-16777216 */
/* @0x24cdd8 bic r2, r2, #3 */
/* @0x24cddc cmp r2, #0 */
/* @0x24cde0 beq 0x24cf98 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x234> */
/* @0x24cde4 mov r2, #5 */
/* @0x24cde8 str r2, [r5, #0xc] */
/* @0x24cdec ldr r1, [r4, #0xc] */
/* @0x24cdf0 mov r3, #0 */
/* @0x24cdf4 str r3, [r5, #0x8] */
/* @0x24cdf8 str r1, [r5, #0xc] */
/* @0x24cdfc mov r1, #0 */
/* @0x24ce00 ldr r3, [r4, #0xc] */
/* @0x24ce04 ldr r2, [r4, #0x8] */
/* @0x24ce08 bic r3, r3, #-16777216 */
/* @0x24ce0c str r1, [r5] */
/* @0x24ce10 str r2, [r5, #0x8] */
/* @0x24ce14 cmp r3, #14 */
/* @0x24ce18 addls pc, pc, r3, lsl #2 */
/* @0x24ce1c b 0x24cf18 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1b4> */
/* @0x24ce20 b 0x24cea4 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x140> */
/* @0x24ce24 b 0x24cf20 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1bc> */
/* @0x24ce28 b 0x24cef0 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x18c> */
/* @0x24ce2c b 0x24ce5c <_Z16F_JS_ToPrimitiveR6RValueS0_i+0xf8> */
/* @0x24ce30 b 0x24cf18 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1b4> */
/* @0x24ce34 b 0x24cf18 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1b4> */
/* @0x24ce38 b 0x24cec8 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x164> */
/* @0x24ce3c b 0x24ce5c <_Z16F_JS_ToPrimitiveR6RValueS0_i+0xf8> */
/* @0x24ce40 b 0x24cf18 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1b4> */
/* @0x24ce44 b 0x24cf18 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1b4> */
/* @0x24ce48 b 0x24cea4 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x140> */
/* @0x24ce4c b 0x24cf18 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1b4> */
/* @0x24ce50 b 0x24cf18 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1b4> */
/* @0x24ce54 b 0x24cea4 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x140> */
/* @0x24ce58 b 0x24ce5c <_Z16F_JS_ToPrimitiveR6RValueS0_i+0xf8> */
/* @0x24ce5c ldr r3, [r4] */
/* @0x24ce60 mov r0, #0 */
/* @0x24ce64 str r3, [r5] */
/* @0x24ce68 pop {r3, r4, r5, r6, r7, pc} */
/* @0x24ce6c ldr r6, [r0] */
/* @0x24ce70 cmp r6, #0 */
/* @0x24ce74 beq 0x24ce98 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x134> */
/* @0x24ce78 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24ce7c ldr r7, [r6, #0x4] */
/* @0x24ce80 sub r7, r7, #1 */
/* @0x24ce84 str r7, [r6, #0x4] */
/* @0x24ce88 cmp r7, #0 */
/* @0x24ce8c beq 0x24cf40 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1dc> */
/* @0x24ce90 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24ce94 ldr r1, [r4, #0xc] */
/* @0x24ce98 mov r3, #0 */
/* @0x24ce9c str r3, [r5] */
/* @0x24cea0 b 0x24cdf8 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x94> */
/* @0x24cea4 ldr r2, [r4] */
/* @0x24cea8 mov r0, #0 */
/* @0x24ceac ldr r3, [r4, #0x4] */
/* @0x24ceb0 stm r5, {r2, r3} */
/* @0x24ceb4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x24ceb8 ldr r0, [r4] */
/* @0x24cebc mov r1, r5 */
/* @0x24cec0 pop {r3, r4, r5, r6, r7, lr} */
/* @0x24cec4 b 0x24c844 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei> */
/* @0x24cec8 ldr r3, [r4] */
/* @0x24cecc str r3, [r5] */
/* @0x24ced0 ldr r3, [r4] */
/* @0x24ced4 cmp r3, #0 */
/* @0x24ced8 beq 0x24cf18 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1b4> */
/* @0x24cedc bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x24cee0 ldr r1, [r4] */
/* @0x24cee4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x24cee8 mov r0, #0 */
/* @0x24ceec pop {r3, r4, r5, r6, r7, pc} */
/* @0x24cef0 ldr r3, [r4] */
/* @0x24cef4 cmp r3, #0 */
/* @0x24cef8 str r3, [r5] */
/* @0x24cefc beq 0x24cf18 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1b4> */
/* @0x24cf00 ldr r0, [r3, #0x8] */
/* @0x24cf04 ldr r2, [r3] */
/* @0x24cf08 cmp r0, #0 */
/* @0x24cf0c add r2, r2, #1 */
/* @0x24cf10 str r2, [r3] */
/* @0x24cf14 beq 0x24cfa0 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x23c> */
/* @0x24cf18 mov r0, #0 */
/* @0x24cf1c pop {r3, r4, r5, r6, r7, pc} */
/* @0x24cf20 ldr r3, [r4] */
/* @0x24cf24 mov r0, #0 */
/* @0x24cf28 cmp r3, #0 */
/* @0x24cf2c ldrne r2, [r3, #0x4] */
/* @0x24cf30 addne r2, r2, #1 */
/* @0x24cf34 strne r2, [r3, #0x4] */
/* @0x24cf38 str r3, [r5] */
/* @0x24cf3c pop {r3, r4, r5, r6, r7, pc} */
/* @0x24cf40 ldr r0, [r6] */
/* @0x24cf44 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24cf48 str r7, [r6] */
/* @0x24cf4c str r7, [r6, #0x8] */
/* @0x24cf50 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24cf54 ldr r7, [r6, #0x4] */
/* @0x24cf58 sub r7, r7, #1 */
/* @0x24cf5c str r7, [r6, #0x4] */
/* @0x24cf60 cmp r7, #0 */
/* @0x24cf64 bne 0x24cf88 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x224> */
/* @0x24cf68 ldr r0, [r6] */
/* @0x24cf6c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24cf70 mov r0, r6 */
/* @0x24cf74 str r7, [r6] */
/* @0x24cf78 str r7, [r6, #0x8] */
/* @0x24cf7c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x24cf80 mov r0, r6 */
/* @0x24cf84 bl 0x27d1d0 <_ZdlPv> */
/* @0x24cf88 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24cf8c mov r0, r6 */
/* @0x24cf90 bl 0x27d1d0 <_ZdlPv> */
/* @0x24cf94 b 0x24ce90 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x12c> */
/* @0x24cf98 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24cf9c b 0x24cde4 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x80> */
/* @0x24cfa0 str r5, [r3, #0x8] */
/* @0x24cfa4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x24cfa8 andseq r9, r0, r8, ror #1 */

/* ── FUNC 0x24cfac · F_JS_ToNumber(RValue&, RValue&) · size=1352 · insn=338 */
/* @0x24cfac ldr r3, [r1, #0xc] */
/* @0x24cfb0 push {r4, r5, r6, r7, r8, lr} */
/* @0x24cfb4 bic r3, r3, #-16777216 */
/* @0x24cfb8 sub sp, sp, #24 */
/* @0x24cfbc mov r6, r0 */
/* @0x24cfc0 cmp r3, #13 */
/* @0x24cfc4 addls pc, pc, r3, lsl #2 */
/* @0x24cfc8 b 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> */
/* @0x24cfcc b 0x24d200 <_Z13F_JS_ToNumberR6RValueS0_+0x254> */
/* @0x24cfd0 b 0x24d004 <_Z13F_JS_ToNumberR6RValueS0_+0x58> */
/* @0x24cfd4 b 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> */
/* @0x24cfd8 b 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> */
/* @0x24cfdc b 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> */
/* @0x24cfe0 b 0x24d224 <_Z13F_JS_ToNumberR6RValueS0_+0x278> */
/* @0x24cfe4 b 0x24d258 <_Z13F_JS_ToNumberR6RValueS0_+0x2ac> */
/* @0x24cfe8 b 0x24d2d0 <_Z13F_JS_ToNumberR6RValueS0_+0x324> */
/* @0x24cfec b 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> */
/* @0x24cff0 b 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> */
/* @0x24cff4 b 0x24d2fc <_Z13F_JS_ToNumberR6RValueS0_+0x350> */
/* @0x24cff8 b 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> */
/* @0x24cffc b 0x24d1e0 <_Z13F_JS_ToNumberR6RValueS0_+0x234> */
/* @0x24d000 b 0x24d200 <_Z13F_JS_ToNumberR6RValueS0_+0x254> */
/* @0x24d004 ldr r2, [r1] */
/* @0x24d008 mov r3, #0 */
/* @0x24d00c ldr r4, [r2] */
/* @0x24d010 str r3, [r0, #0xc] */
/* @0x24d014 cmp r4, r3 */
/* @0x24d018 str r4, [sp] */
/* @0x24d01c beq 0x24d350 <_Z13F_JS_ToNumberR6RValueS0_+0x3a4> */
/* @0x24d020 ldrb r3, [r4] */
/* @0x24d024 cmp r3, #0 */
/* @0x24d028 beq 0x24d350 <_Z13F_JS_ToNumberR6RValueS0_+0x3a4> */
/* @0x24d02c movw r8, #0x2028 */
/* @0x24d030 mov r7, #1 */
/* @0x24d034 mov r0, sp */
/* @0x24d038 bl 0x10fb38 <utf8_extract_char> */
/* @0x24d03c movw r3, #0xff7f */
/* @0x24d040 sub r1, r0, #9 */
/* @0x24d044 and r3, r0, r3 */
/* @0x24d048 uxth r1, r1 */
/* @0x24d04c cmp r3, #32 */
/* @0x24d050 cmpne r1, #2 */
/* @0x24d054 bls 0x24d340 <_Z13F_JS_ToNumberR6RValueS0_+0x394> */
/* @0x24d058 cmp r0, #13 */
/* @0x24d05c beq 0x24d340 <_Z13F_JS_ToNumberR6RValueS0_+0x394> */
/* @0x24d060 cmp r0, r8 */
/* @0x24d064 cmpne r0, #12 */
/* @0x24d068 beq 0x24d340 <_Z13F_JS_ToNumberR6RValueS0_+0x394> */
/* @0x24d06c cmp r0, #160 */
/* @0x24d070 ble 0x24d0ac <_Z13F_JS_ToNumberR6RValueS0_+0x100> */
/* @0x24d074 bl 0x23f854 <_Z21utf8proc_get_propertyi> */
/* @0x24d078 mov r3, #1 */
/* @0x24d07c movt r3, #0x7f */
/* @0x24d080 cmp r0, #0 */
/* @0x24d084 beq 0x24d0ac <_Z13F_JS_ToNumberR6RValueS0_+0x100> */
/* @0x24d088 ldrh r2, [r0] */
/* @0x24d08c sub r2, r2, #7 */
/* @0x24d090 uxth r2, r2 */
/* @0x24d094 cmp r2, #22 */
/* @0x24d098 lsl r1, r7, r2 */
/* @0x24d09c and r3, r1, r3 */
/* @0x24d0a0 bhi 0x24d0ac <_Z13F_JS_ToNumberR6RValueS0_+0x100> */
/* @0x24d0a4 cmp r3, #0 */
/* @0x24d0a8 bne 0x24d340 <_Z13F_JS_ToNumberR6RValueS0_+0x394> */
/* @0x24d0ac str r4, [sp] */
/* @0x24d0b0 ldrb r3, [r4] */
/* @0x24d0b4 cmp r3, #0 */
/* @0x24d0b8 beq 0x24d350 <_Z13F_JS_ToNumberR6RValueS0_+0x3a4> */
/* @0x24d0bc add r0, sp, #4 */
/* @0x24d0c0 str r4, [sp, #0x4] */
/* @0x24d0c4 str r4, [sp, #0x8] */
/* @0x24d0c8 bl 0x10fb38 <utf8_extract_char> */
/* @0x24d0cc ldr r5, [sp] */
/* @0x24d0d0 ldrb r3, [r5, #0x1] */
/* @0x24d0d4 cmp r0, #48 */
/* @0x24d0d8 mov r4, r0 */
/* @0x24d0dc beq 0x24d3b8 <_Z13F_JS_ToNumberR6RValueS0_+0x40c> */
/* @0x24d0e0 cmp r3, #88 */
/* @0x24d0e4 beq 0x24d3c4 <_Z13F_JS_ToNumberR6RValueS0_+0x418> */
/* @0x24d0e8 cmp r0, #73 */
/* @0x24d0ec beq 0x24d450 <_Z13F_JS_ToNumberR6RValueS0_+0x4a4> */
/* @0x24d0f0 cmp r0, #45 */
/* @0x24d0f4 beq 0x24d488 <_Z13F_JS_ToNumberR6RValueS0_+0x4dc> */
/* @0x24d0f8 cmp r0, #43 */
/* @0x24d0fc beq 0x24d4c0 <_Z13F_JS_ToNumberR6RValueS0_+0x514> */
/* @0x24d100 sub r3, r0, #45 */
/* @0x24d104 uxth r3, r3 */
/* @0x24d108 cmp r3, #1 */
/* @0x24d10c bls 0x24d3a0 <_Z13F_JS_ToNumberR6RValueS0_+0x3f4> */
/* @0x24d110 sub r3, r4, #48 */
/* @0x24d114 uxth r3, r3 */
/* @0x24d118 cmp r3, #9 */
/* @0x24d11c bls 0x24d3a0 <_Z13F_JS_ToNumberR6RValueS0_+0x3f4> */
/* @0x24d120 ldr r4, [sp, #0x8] */
/* @0x24d124 add r5, sp, #8 */
/* @0x24d128 movw r8, #0x2028 */
/* @0x24d12c mov r7, #1 */
/* @0x24d130 ldrb r3, [r4] */
/* @0x24d134 mov r0, r5 */
/* @0x24d138 cmp r3, #0 */
/* @0x24d13c beq 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> */
/* @0x24d140 bl 0x10fb38 <utf8_extract_char> */
/* @0x24d144 movw r3, #0xff7f */
/* @0x24d148 sub r1, r0, #9 */
/* @0x24d14c and r3, r0, r3 */
/* @0x24d150 uxth r1, r1 */
/* @0x24d154 cmp r3, #32 */
/* @0x24d158 cmpne r1, #2 */
/* @0x24d15c bls 0x24d36c <_Z13F_JS_ToNumberR6RValueS0_+0x3c0> */
/* @0x24d160 cmp r0, #13 */
/* @0x24d164 beq 0x24d36c <_Z13F_JS_ToNumberR6RValueS0_+0x3c0> */
/* @0x24d168 cmp r0, r8 */
/* @0x24d16c cmpne r0, #12 */
/* @0x24d170 beq 0x24d36c <_Z13F_JS_ToNumberR6RValueS0_+0x3c0> */
/* @0x24d174 cmp r0, #160 */
/* @0x24d178 ble 0x24d1b4 <_Z13F_JS_ToNumberR6RValueS0_+0x208> */
/* @0x24d17c bl 0x23f854 <_Z21utf8proc_get_propertyi> */
/* @0x24d180 mov r3, #1 */
/* @0x24d184 movt r3, #0x7f */
/* @0x24d188 cmp r0, #0 */
/* @0x24d18c beq 0x24d1b4 <_Z13F_JS_ToNumberR6RValueS0_+0x208> */
/* @0x24d190 ldrh r2, [r0] */
/* @0x24d194 sub r2, r2, #7 */
/* @0x24d198 uxth r2, r2 */
/* @0x24d19c cmp r2, #22 */
/* @0x24d1a0 lsl r1, r7, r2 */
/* @0x24d1a4 and r3, r1, r3 */
/* @0x24d1a8 bhi 0x24d1b4 <_Z13F_JS_ToNumberR6RValueS0_+0x208> */
/* @0x24d1ac cmp r3, #0 */
/* @0x24d1b0 bne 0x24d36c <_Z13F_JS_ToNumberR6RValueS0_+0x3c0> */
/* @0x24d1b4 str r4, [sp, #0x8] */
/* @0x24d1b8 ldrb r3, [r4] */
/* @0x24d1bc cmp r3, #0 */
/* @0x24d1c0 beq 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> */
/* @0x24d1c4 mvn r2, #0 */
/* @0x24d1c8 mvn r3, #-2147483648 */
/* @0x24d1cc stm r6, {r2, r3} */
/* @0x24d1d0 mov r12, #0 */
/* @0x24d1d4 mov r0, r12 */
/* @0x24d1d8 add sp, sp, #24 */
/* @0x24d1dc pop {r4, r5, r6, r7, r8, pc} */
/* @0x24d1e0 mov r3, #0 */
/* @0x24d1e4 str r3, [r0] */
/* @0x24d1e8 mov r12, r3 */
/* @0x24d1ec str r3, [r0, #0x4] */
/* @0x24d1f0 str r3, [r0, #0xc] */
/* @0x24d1f4 mov r0, r12 */
/* @0x24d1f8 add sp, sp, #24 */
/* @0x24d1fc pop {r4, r5, r6, r7, r8, pc} */
/* @0x24d200 ldr r0, [r1] */
/* @0x24d204 mov r3, #0 */
/* @0x24d208 ldr r2, [r1, #0x4] */
/* @0x24d20c mov r12, r3 */
/* @0x24d210 str r3, [r6, #0xc] */
/* @0x24d214 stm r6, {r0, r2} */
/* @0x24d218 mov r0, r12 */
/* @0x24d21c add sp, sp, #24 */
/* @0x24d220 pop {r4, r5, r6, r7, r8, pc} */
/* @0x24d224 ldr r4, [pc, #0x2b8] */
/* @0x24d228 mov r12, #0 */
/* @0x24d22c add r4, pc, r4 */
/* @0x24d230 add r4, r4, #2352 */
/* @0x24d234 add r4, r4, #12 */
/* @0x24d238 ldm r4!, {r0, r1, r2, r3} */
/* @0x24d23c str r0, [r6] */
/* @0x24d240 mov r0, r12 */
/* @0x24d244 str r1, [r6, #0x4] */
/* @0x24d248 str r2, [r6, #0x8] */
/* @0x24d24c str r3, [r6, #0xc] */
/* @0x24d250 add sp, sp, #24 */
/* @0x24d254 pop {r4, r5, r6, r7, r8, pc} */
/* @0x24d258 add r7, sp, #8 */
/* @0x24d25c mov r3, #0 */
/* @0x24d260 mov r2, r3 */
/* @0x24d264 str r3, [sp, #0x10] */
/* @0x24d268 mov r0, r7 */
/* @0x24d26c mov r4, #0 */
/* @0x24d270 mvn r3, #-16777216 */
/* @0x24d274 mov r5, #0 */
/* @0x24d278 str r3, [sp, #0x14] */
/* @0x24d27c strd r4, r5, [sp, #8] */
/* @0x24d280 bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i> */
/* @0x24d284 cmp r0, #2 */
/* @0x24d288 mov r4, r0 */
/* @0x24d28c beq 0x24d374 <_Z13F_JS_ToNumberR6RValueS0_+0x3c8> */
/* @0x24d290 cmp r0, #1 */
/* @0x24d294 beq 0x24d320 <_Z13F_JS_ToNumberR6RValueS0_+0x374> */
/* @0x24d298 mov r0, r6 */
/* @0x24d29c mov r1, r7 */
/* @0x24d2a0 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x24d2a4 cmp r0, #1 */
/* @0x24d2a8 beq 0x24d320 <_Z13F_JS_ToNumberR6RValueS0_+0x374> */
/* @0x24d2ac ldr r3, [sp, #0x14] */
/* @0x24d2b0 sub r3, r3, #1 */
/* @0x24d2b4 bic r3, r3, #-16777216 */
/* @0x24d2b8 bic r3, r3, #3 */
/* @0x24d2bc cmp r3, #0 */
/* @0x24d2c0 bne 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> */
/* @0x24d2c4 mov r0, r7 */
/* @0x24d2c8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24d2cc b 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> */
/* @0x24d2d0 ldr r2, [r1] */
/* @0x24d2d4 mov r3, #0 */
/* @0x24d2d8 mov r12, r3 */
/* @0x24d2dc str r3, [r0, #0xc] */
/* @0x24d2e0 vmov s15, r2 */
/* @0x24d2e4 vcvt.f64.s32 d7, s15 */
/* @0x24d2e8 vmov r2, r3, d7 */
/* @0x24d2ec stm r0, {r2, r3} */
/* @0x24d2f0 mov r0, r12 */
/* @0x24d2f4 add sp, sp, #24 */
/* @0x24d2f8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x24d2fc ldm r1, {r0, r1} */
/* @0x24d300 bl 0x319164 <__floatdidf> */
/* @0x24d304 mov r3, #0 */
/* @0x24d308 mov r12, r3 */
/* @0x24d30c str r3, [r6, #0xc] */
/* @0x24d310 stm r6, {r0, r1} */
/* @0x24d314 mov r0, r12 */
/* @0x24d318 add sp, sp, #24 */
/* @0x24d31c pop {r4, r5, r6, r7, r8, pc} */
/* @0x24d320 ldr r3, [sp, #0x14] */
/* @0x24d324 sub r3, r3, #1 */
/* @0x24d328 bic r3, r3, #-16777216 */
/* @0x24d32c bic r3, r3, #3 */
/* @0x24d330 cmp r3, #0 */
/* @0x24d334 beq 0x24d360 <_Z13F_JS_ToNumberR6RValueS0_+0x3b4> */
/* @0x24d338 mov r12, #1 */
/* @0x24d33c b 0x24d1d4 <_Z13F_JS_ToNumberR6RValueS0_+0x228> */
/* @0x24d340 ldr r4, [sp] */
/* @0x24d344 ldrb r3, [r4] */
/* @0x24d348 cmp r3, #0 */
/* @0x24d34c bne 0x24d034 <_Z13F_JS_ToNumberR6RValueS0_+0x88> */
/* @0x24d350 mov r3, #0 */
/* @0x24d354 str r3, [r6] */
/* @0x24d358 str r3, [r6, #0x4] */
/* @0x24d35c b 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> */
/* @0x24d360 mov r0, r7 */
/* @0x24d364 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24d368 b 0x24d338 <_Z13F_JS_ToNumberR6RValueS0_+0x38c> */
/* @0x24d36c ldr r4, [sp, #0x8] */
/* @0x24d370 b 0x24d130 <_Z13F_JS_ToNumberR6RValueS0_+0x184> */
/* @0x24d374 ldr r3, [sp, #0x14] */
/* @0x24d378 sub r3, r3, #1 */
/* @0x24d37c bic r3, r3, #-16777216 */
/* @0x24d380 bic r3, r3, #3 */
/* @0x24d384 cmp r3, #0 */
/* @0x24d388 movne r12, r0 */
/* @0x24d38c bne 0x24d1d4 <_Z13F_JS_ToNumberR6RValueS0_+0x228> */
/* @0x24d390 mov r0, r7 */
/* @0x24d394 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24d398 mov r12, r4 */
/* @0x24d39c b 0x24d1d4 <_Z13F_JS_ToNumberR6RValueS0_+0x228> */
/* @0x24d3a0 mov r0, r5 */
/* @0x24d3a4 add r1, sp, #8 */
/* @0x24d3a8 bl 0xb6658 <strtod@plt> */
/* @0x24d3ac ldr r4, [sp, #0x8] */
/* @0x24d3b0 stm r6, {r0, r1} */
/* @0x24d3b4 b 0x24d124 <_Z13F_JS_ToNumberR6RValueS0_+0x178> */
/* @0x24d3b8 and r3, r3, #223 */
/* @0x24d3bc cmp r3, #88 */
/* @0x24d3c0 bne 0x24d110 <_Z13F_JS_ToNumberR6RValueS0_+0x164> */
/* @0x24d3c4 ldrb r0, [r5, #0x2] */
/* @0x24d3c8 mov r1, #16 */
/* @0x24d3cc bl 0x23fe9c <_Z16isValidRadixCharci> */
/* @0x24d3d0 add r4, r5, #2 */
/* @0x24d3d4 cmp r0, #0 */
/* @0x24d3d8 beq 0x24d1c4 <_Z13F_JS_ToNumberR6RValueS0_+0x218> */
/* @0x24d3dc ldrb r3, [r5, #0x2] */
/* @0x24d3e0 cmp r3, #0 */
/* @0x24d3e4 bne 0x24d3fc <_Z13F_JS_ToNumberR6RValueS0_+0x450> */
/* @0x24d3e8 mov r2, #0 */
/* @0x24d3ec mov r3, #0 */
/* @0x24d3f0 str r4, [sp, #0x8] */
/* @0x24d3f4 stm r6, {r2, r3} */
/* @0x24d3f8 b 0x24d124 <_Z13F_JS_ToNumberR6RValueS0_+0x178> */
/* @0x24d3fc mov r5, r4 */
/* @0x24d400 mov r7, #0 */
/* @0x24d404 mov r1, #16 */
/* @0x24d408 mov r0, r3 */
/* @0x24d40c bl 0x23fe9c <_Z16isValidRadixCharci> */
/* @0x24d410 mov r4, r5 */
/* @0x24d414 mov r1, #16 */
/* @0x24d418 add r5, r5, #1 */
/* @0x24d41c cmp r0, #0 */
/* @0x24d420 beq 0x24d440 <_Z13F_JS_ToNumberR6RValueS0_+0x494> */
/* @0x24d424 ldrb r0, [r4] */
/* @0x24d428 mov r4, r5 */
/* @0x24d42c bl 0x23fe14 <_Z12getRadixCharci> */
/* @0x24d430 ldrb r3, [r5] */
/* @0x24d434 cmp r3, #0 */
/* @0x24d438 add r7, r0, r7, lsl #4 */
/* @0x24d43c bne 0x24d404 <_Z13F_JS_ToNumberR6RValueS0_+0x458> */
/* @0x24d440 vmov s15, r7 */
/* @0x24d444 vcvt.f64.s32 d7, s15 */
/* @0x24d448 vmov r2, r3, d7 */
/* @0x24d44c b 0x24d3f0 <_Z13F_JS_ToNumberR6RValueS0_+0x444> */
/* @0x24d450 ldr r1, [pc, #0x90] */
/* @0x24d454 mov r0, r5 */
/* @0x24d458 mov r2, #8 */
/* @0x24d45c add r1, pc, r1 */
/* @0x24d460 bl 0xb65e0 <strncmp@plt> */
/* @0x24d464 cmp r0, #0 */
/* @0x24d468 addeq r4, r5, #8 */
/* @0x24d46c bne 0x24d110 <_Z13F_JS_ToNumberR6RValueS0_+0x164> */
/* @0x24d470 str r4, [sp, #0x8] */
/* @0x24d474 mov r3, #0 */
/* @0x24d478 str r0, [r6] */
/* @0x24d47c movt r3, #0x7ff0 */
/* @0x24d480 str r3, [r6, #0x4] */
/* @0x24d484 b 0x24d124 <_Z13F_JS_ToNumberR6RValueS0_+0x178> */
/* @0x24d488 ldr r1, [pc, #0x5c] */
/* @0x24d48c mov r0, r5 */
/* @0x24d490 mov r2, #9 */
/* @0x24d494 add r1, pc, r1 */
/* @0x24d498 bl 0xb65e0 <strncmp@plt> */
/* @0x24d49c cmp r0, #0 */
/* @0x24d4a0 bne 0x24d3a0 <_Z13F_JS_ToNumberR6RValueS0_+0x3f4> */
/* @0x24d4a4 add r4, r5, #9 */
/* @0x24d4a8 mov r3, #0 */
/* @0x24d4ac str r4, [sp, #0x8] */
/* @0x24d4b0 movt r3, #0xfff0 */
/* @0x24d4b4 str r0, [r6] */
/* @0x24d4b8 str r3, [r6, #0x4] */
/* @0x24d4bc b 0x24d124 <_Z13F_JS_ToNumberR6RValueS0_+0x178> */
/* @0x24d4c0 ldr r1, [pc, #0x28] */
/* @0x24d4c4 mov r0, r5 */
/* @0x24d4c8 mov r2, #9 */
/* @0x24d4cc add r1, pc, r1 */
/* @0x24d4d0 bl 0xb65e0 <strncmp@plt> */
/* @0x24d4d4 cmp r0, #0 */
/* @0x24d4d8 bne 0x24d3a0 <_Z13F_JS_ToNumberR6RValueS0_+0x3f4> */
/* @0x24d4dc add r4, r5, #9 */
/* @0x24d4e0 b 0x24d470 <_Z13F_JS_ToNumberR6RValueS0_+0x4c4> */
/* @0x24d4e4 subseq r8, r0, r4, ror r8 */
/* @0x24d4e8 mulseq r0, r0, pc */
/* @0x24d4ec andseq r8, r0, r8, lsr #20 */
/* @0x24d4f0 ldrsheq r8, [r0], -r12 */

/* ── FUNC 0x24d4f4 · F_JS_ToUint32(RValue&, RValue&) · size=212 · insn=53 */
/* @0x24d4f4 push {r4, r5, r6, lr} */
/* @0x24d4f8 sub sp, sp, #16 */
/* @0x24d4fc mov r6, r0 */
/* @0x24d500 mov r2, #0 */
/* @0x24d504 mov r0, sp */
/* @0x24d508 mov r3, #0 */
/* @0x24d50c mov r12, #0 */
/* @0x24d510 strd r2, r3, [sp] */
/* @0x24d514 str r12, [sp, #0x8] */
/* @0x24d518 mvn r3, #-16777216 */
/* @0x24d51c str r3, [sp, #0xc] */
/* @0x24d520 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x24d524 subs r4, r0, #0 */
/* @0x24d528 beq 0x24d550 <_Z13F_JS_ToUint32R6RValueS0_+0x5c> */
/* @0x24d52c ldr r3, [sp, #0xc] */
/* @0x24d530 sub r3, r3, #1 */
/* @0x24d534 bic r3, r3, #-16777216 */
/* @0x24d538 bic r3, r3, #3 */
/* @0x24d53c cmp r3, #0 */
/* @0x24d540 beq 0x24d59c <_Z13F_JS_ToUint32R6RValueS0_+0xa8> */
/* @0x24d544 mov r0, r4 */
/* @0x24d548 add sp, sp, #16 */
/* @0x24d54c pop {r4, r5, r6, pc} */
/* @0x24d550 vldr d7, [sp] */
/* @0x24d554 vcmp.f64 d7, d7 */
/* @0x24d558 str r4, [r6, #0xc] */
/* @0x24d55c str r4, [r6] */
/* @0x24d560 str r4, [r6, #0x4] */
/* @0x24d564 vmrs APSR_nzcv, fpscr */
/* @0x24d568 bvs 0x24d58c <_Z13F_JS_ToUint32R6RValueS0_+0x98> */
/* @0x24d56c mov r0, sp */
/* @0x24d570 bl 0x240970 <_Z7yyisinfR6RValue> */
/* @0x24d574 subs r4, r0, #0 */
/* @0x24d578 bne 0x24d58c <_Z13F_JS_ToUint32R6RValueS0_+0x98> */
/* @0x24d57c vldr d7, [sp] */
/* @0x24d580 vcmp.f64 d7, #0 */
/* @0x24d584 vmrs APSR_nzcv, fpscr */
/* @0x24d588 bne 0x24d5b0 <_Z13F_JS_ToUint32R6RValueS0_+0xbc> */
/* @0x24d58c mov r4, #0 */
/* @0x24d590 mov r0, r4 */
/* @0x24d594 add sp, sp, #16 */
/* @0x24d598 pop {r4, r5, r6, pc} */
/* @0x24d59c mov r0, sp */
/* @0x24d5a0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24d5a4 mov r0, r4 */
/* @0x24d5a8 add sp, sp, #16 */
/* @0x24d5ac pop {r4, r5, r6, pc} */
/* @0x24d5b0 vmov r0, r1, d7 */
/* @0x24d5b4 bl 0x3194a0 <__fixdfdi> */
/* @0x24d5b8 mov r1, #0 */
/* @0x24d5bc bl 0x319164 <__floatdidf> */
/* @0x24d5c0 stm r6, {r0, r1} */
/* @0x24d5c4 b 0x24d544 <_Z13F_JS_ToUint32R6RValueS0_+0x50> */

/* ── FUNC 0x24d5c8 · F_JS_ToInt32(RValue&, RValue&) · size=360 · insn=90 */
/* @0x24d5c8 push {r4, r5, r6, lr} */
/* @0x24d5cc vpush {d8} */
/* @0x24d5d0 sub sp, sp, #16 */
/* @0x24d5d4 mov r4, r0 */
/* @0x24d5d8 mov r2, #0 */
/* @0x24d5dc mov r0, sp */
/* @0x24d5e0 mov r3, #0 */
/* @0x24d5e4 mov r12, #0 */
/* @0x24d5e8 strd r2, r3, [sp] */
/* @0x24d5ec str r12, [sp, #0x8] */
/* @0x24d5f0 mvn r3, #-16777216 */
/* @0x24d5f4 str r3, [sp, #0xc] */
/* @0x24d5f8 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x24d5fc subs r5, r0, #0 */
/* @0x24d600 beq 0x24d62c <_Z12F_JS_ToInt32R6RValueS0_+0x64> */
/* @0x24d604 ldr r3, [sp, #0xc] */
/* @0x24d608 sub r3, r3, #1 */
/* @0x24d60c bic r3, r3, #-16777216 */
/* @0x24d610 bic r3, r3, #3 */
/* @0x24d614 cmp r3, #0 */
/* @0x24d618 movne r0, r5 */
/* @0x24d61c beq 0x24d678 <_Z12F_JS_ToInt32R6RValueS0_+0xb0> */
/* @0x24d620 add sp, sp, #16 */
/* @0x24d624 vpop {d8} */
/* @0x24d628 pop {r4, r5, r6, pc} */
/* @0x24d62c vldr d7, [sp] */
/* @0x24d630 vcmp.f64 d7, d7 */
/* @0x24d634 str r5, [r4, #0xc] */
/* @0x24d638 str r5, [r4] */
/* @0x24d63c str r5, [r4, #0x4] */
/* @0x24d640 vmrs APSR_nzcv, fpscr */
/* @0x24d644 bvs 0x24d668 <_Z12F_JS_ToInt32R6RValueS0_+0xa0> */
/* @0x24d648 mov r0, sp */
/* @0x24d64c bl 0x240970 <_Z7yyisinfR6RValue> */
/* @0x24d650 subs r5, r0, #0 */
/* @0x24d654 bne 0x24d668 <_Z12F_JS_ToInt32R6RValueS0_+0xa0> */
/* @0x24d658 vldr d7, [sp] */
/* @0x24d65c vcmp.f64 d7, #0 */
/* @0x24d660 vmrs APSR_nzcv, fpscr */
/* @0x24d664 bne 0x24d690 <_Z12F_JS_ToInt32R6RValueS0_+0xc8> */
/* @0x24d668 mov r0, #0 */
/* @0x24d66c add sp, sp, #16 */
/* @0x24d670 vpop {d8} */
/* @0x24d674 pop {r4, r5, r6, pc} */
/* @0x24d678 mov r0, sp */
/* @0x24d67c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24d680 mov r0, r5 */
/* @0x24d684 add sp, sp, #16 */
/* @0x24d688 vpop {d8} */
/* @0x24d68c pop {r4, r5, r6, pc} */
/* @0x24d690 vmov.f64 d6, #1.000000e+00 */
/* @0x24d694 vmov.f64 d8, #-1.000000e+00 */
/* @0x24d698 vabs.f64 d5, d7 */
/* @0x24d69c vcmpe.f64 d7, #0 */
/* @0x24d6a0 vmov r0, r1, d5 */
/* @0x24d6a4 vmrs APSR_nzcv, fpscr */
/* @0x24d6a8 vmovpl.f64 d8, d6 */
/* @0x24d6ac bl 0xb6598 <floor@plt> */
/* @0x24d6b0 vmov d6, r0, r1 */
/* @0x24d6b4 vmul.f64 d6, d8, d6 */
/* @0x24d6b8 vmov r0, r1, d6 */
/* @0x24d6bc bl 0x3194a0 <__fixdfdi> */
/* @0x24d6c0 mov r1, #0 */
/* @0x24d6c4 bl 0x319164 <__floatdidf> */
/* @0x24d6c8 vldr d7, [pc, #80] */
/* @0x24d6cc mov r2, r0 */
/* @0x24d6d0 mov r3, r1 */
/* @0x24d6d4 vmov d5, r2, r3 */
/* @0x24d6d8 vcmpe.f64 d5, d7 */
/* @0x24d6dc vmrs APSR_nzcv, fpscr */
/* @0x24d6e0 bgt 0x24d6f8 <_Z12F_JS_ToInt32R6RValueS0_+0x130> */
/* @0x24d6e4 mov r0, r5 */
/* @0x24d6e8 stm r4, {r2, r3} */
/* @0x24d6ec add sp, sp, #16 */
/* @0x24d6f0 vpop {d8} */
/* @0x24d6f4 pop {r4, r5, r6, pc} */
/* @0x24d6f8 vmov d5, r2, r3 */
/* @0x24d6fc vldr d7, [pc, #36] */
/* @0x24d700 mov r0, r5 */
/* @0x24d704 vsub.f64 d5, d5, d7 */
/* @0x24d708 vmov r2, r3, d5 */
/* @0x24d70c stm r4, {r2, r3} */
/* @0x24d710 add sp, sp, #16 */
/* @0x24d714 vpop {d8} */
/* @0x24d718 pop {r4, r5, r6, pc} */
/* @0x24d71c nop */
/* @0x24d720 andeq r0, r0, r0 */
/* @0x24d724 mvnmi r0, r0 */
/* @0x24d728 andeq r0, r0, r0 */
/* @0x24d72c mvnsmi r0, r0 */

/* ── FUNC 0x24d730 · F_JS_ToInteger(RValue&) · size=184 · insn=44 */
/* @0x24d730 push {r4, lr} */
/* @0x24d734 vpush {d8} */
/* @0x24d738 sub sp, sp, #16 */
/* @0x24d73c mov r1, r0 */
/* @0x24d740 mov r2, #0 */
/* @0x24d744 mov r0, sp */
/* @0x24d748 mov r3, #0 */
/* @0x24d74c strd r2, r3, [sp] */
/* @0x24d750 mov r2, #0 */
/* @0x24d754 mvn r3, #-16777216 */
/* @0x24d758 str r2, [sp, #0x8] */
/* @0x24d75c str r3, [sp, #0xc] */
/* @0x24d760 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x24d764 vldr d7, [sp] */
/* @0x24d768 vcmp.f64 d7, d7 */
/* @0x24d76c vmrs APSR_nzcv, fpscr */
/* @0x24d770 bvs 0x24d7cc <_Z14F_JS_ToIntegerR6RValue+0x9c> */
/* @0x24d774 mov r0, sp */
/* @0x24d778 bl 0x240970 <_Z7yyisinfR6RValue> */
/* @0x24d77c vldr d7, [sp] */
/* @0x24d780 cmp r0, #0 */
/* @0x24d784 bne 0x24d7bc <_Z14F_JS_ToIntegerR6RValue+0x8c> */
/* @0x24d788 vcmp.f64 d7, #0 */
/* @0x24d78c vmrs APSR_nzcv, fpscr */
/* @0x24d790 beq 0x24d7bc <_Z14F_JS_ToIntegerR6RValue+0x8c> */
/* @0x24d794 vmov.f64 d6, #1.000000e+00 */
/* @0x24d798 vmov.f64 d8, #-1.000000e+00 */
/* @0x24d79c vabs.f64 d5, d7 */
/* @0x24d7a0 vcmpe.f64 d7, #0 */
/* @0x24d7a4 vmov r0, r1, d5 */
/* @0x24d7a8 vmrs APSR_nzcv, fpscr */
/* @0x24d7ac vmovpl.f64 d8, d6 */
/* @0x24d7b0 bl 0xb6598 <floor@plt> */
/* @0x24d7b4 vmov d6, r0, r1 */
/* @0x24d7b8 vmul.f64 d7, d8, d6 */
/* @0x24d7bc vmov r0, r1, d7 */
/* @0x24d7c0 add sp, sp, #16 */
/* @0x24d7c4 vpop {d8} */
/* @0x24d7c8 pop {r4, pc} */
/* @0x24d7cc vldr d7, [pc, #12] */
/* @0x24d7d0 vmov r0, r1, d7 */
/* @0x24d7d4 add sp, sp, #16 */
/* @0x24d7d8 vpop {d8} */
/* @0x24d7dc pop {r4, pc} */

/* ── FUNC 0x24d7e8 · F_JS_IsNaN(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x24d7e8 push {r4, r5, r6, r7, lr} */
/* @0x24d7ec sub sp, sp, #20 */
/* @0x24d7f0 mov r6, r0 */
/* @0x24d7f4 mov r2, #0 */
/* @0x24d7f8 ldr r1, [sp, #0x28] */
/* @0x24d7fc mov r0, sp */
/* @0x24d800 mov r7, #0 */
/* @0x24d804 mov r3, #0 */
/* @0x24d808 str r7, [sp, #0x8] */
/* @0x24d80c strd r2, r3, [sp] */
/* @0x24d810 mvn r3, #-16777216 */
/* @0x24d814 str r3, [sp, #0xc] */
/* @0x24d818 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x24d81c ldrd r2, r3, [sp] */
/* @0x24d820 mov r1, #13 */
/* @0x24d824 str r7, [r6] */
/* @0x24d828 str r7, [r6, #0x4] */
/* @0x24d82c vmov d6, r2, r3 */
/* @0x24d830 str r1, [r6, #0xc] */
/* @0x24d834 vcmp.f64 d6, d6 */
/* @0x24d838 vmrs APSR_nzcv, fpscr */
/* @0x24d83c bvs 0x24d848 <_Z10F_JS_IsNaNR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x24d840 add sp, sp, #20 */
/* @0x24d844 pop {r4, r5, r6, r7, pc} */
/* @0x24d848 movw r5, #0xffff */
/* @0x24d84c movt r5, #0xf */
/* @0x24d850 and r3, r3, r5 */
/* @0x24d854 mvn r4, #0 */
/* @0x24d858 and r2, r2, r4 */
/* @0x24d85c orrs r1, r2, r3 */
/* @0x24d860 movne r3, r7 */
/* @0x24d864 movtne r3, #0x3ff0 */
/* @0x24d868 strne r3, [r6, #0x4] */
/* @0x24d86c add sp, sp, #20 */
/* @0x24d870 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x24d874 · F_JS_IsFinite(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x24d874 push {r4, r5, r6, r7, lr} */
/* @0x24d878 sub sp, sp, #20 */
/* @0x24d87c mov r6, r0 */
/* @0x24d880 mov r7, #0 */
/* @0x24d884 ldr r1, [sp, #0x28] */
/* @0x24d888 mov r0, sp */
/* @0x24d88c mov r2, #0 */
/* @0x24d890 mov r3, #0 */
/* @0x24d894 str r7, [sp, #0x8] */
/* @0x24d898 strd r2, r3, [sp] */
/* @0x24d89c mvn r3, #-16777216 */
/* @0x24d8a0 str r3, [sp, #0xc] */
/* @0x24d8a4 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x24d8a8 ldrd r4, r5, [sp] */
/* @0x24d8ac mov r3, #0 */
/* @0x24d8b0 movt r3, #0x7ff0 */
/* @0x24d8b4 mov r2, #0 */
/* @0x24d8b8 and r5, r5, r3 */
/* @0x24d8bc and r4, r4, r2 */
/* @0x24d8c0 cmp r5, r3 */
/* @0x24d8c4 cmpeq r4, r2 */
/* @0x24d8c8 mov r1, #13 */
/* @0x24d8cc mov r3, r7 */
/* @0x24d8d0 str r7, [r6] */
/* @0x24d8d4 movt r3, #0x3ff0 */
/* @0x24d8d8 str r1, [r6, #0xc] */
/* @0x24d8dc str r3, [r6, #0x4] */
/* @0x24d8e0 streq r7, [r6, #0x4] */
/* @0x24d8e4 add sp, sp, #20 */
/* @0x24d8e8 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x24d8ec · JS_ToUint16(RValue&, RValue&) · size=156 · insn=39 */
/* @0x24d8ec push {r4, r5, lr} */
/* @0x24d8f0 sub sp, sp, #20 */
/* @0x24d8f4 mov r3, #0 */
/* @0x24d8f8 mov r4, r0 */
/* @0x24d8fc str r3, [r0, #0xc] */
/* @0x24d900 mov r0, sp */
/* @0x24d904 str r3, [sp, #0x8] */
/* @0x24d908 mov r2, #0 */
/* @0x24d90c mov r3, #0 */
/* @0x24d910 mvn r12, #-16777216 */
/* @0x24d914 strd r2, r3, [sp] */
/* @0x24d918 str r12, [sp, #0xc] */
/* @0x24d91c bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x24d920 vldr d7, [sp] */
/* @0x24d924 vcmp.f64 d7, #0 */
/* @0x24d928 vmrs APSR_nzcv, fpscr */
/* @0x24d92c bne 0x24d944 <_Z11JS_ToUint16R6RValueS0_+0x58> */
/* @0x24d930 mov r3, #0 */
/* @0x24d934 str r3, [r4] */
/* @0x24d938 str r3, [r4, #0x4] */
/* @0x24d93c add sp, sp, #20 */
/* @0x24d940 pop {r4, r5, pc} */
/* @0x24d944 mov r0, sp */
/* @0x24d948 bl 0x240970 <_Z7yyisinfR6RValue> */
/* @0x24d94c cmp r0, #0 */
/* @0x24d950 bne 0x24d930 <_Z11JS_ToUint16R6RValueS0_+0x44> */
/* @0x24d954 vldr d7, [sp] */
/* @0x24d958 vcmp.f64 d7, d7 */
/* @0x24d95c vmrs APSR_nzcv, fpscr */
/* @0x24d960 bvs 0x24d930 <_Z11JS_ToUint16R6RValueS0_+0x44> */
/* @0x24d964 vmov r0, r1, d7 */
/* @0x24d968 bl 0x3194a0 <__fixdfdi> */
/* @0x24d96c uxth r0, r0 */
/* @0x24d970 vmov s15, r0 */
/* @0x24d974 vcvt.f64.s32 d7, s15 */
/* @0x24d978 vmov r2, r3, d7 */
/* @0x24d97c stm r4, {r2, r3} */
/* @0x24d980 add sp, sp, #20 */
/* @0x24d984 pop {r4, r5, pc} */

/* ── FUNC 0x24d988 · JS_String_fromCharCode(RValue&, CInstance*, CInstance*, int, RValue*) · size=772 · insn=193 */
/* @0x24d988 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24d98c vpush {d8, d9, d10} */
/* @0x24d990 mov r4, r3 */
/* @0x24d994 add r11, sp, #56 */
/* @0x24d998 ldr r3, [pc, #0x2e8] */
/* @0x24d99c sub sp, sp, #60 */
/* @0x24d9a0 add r2, r4, r4, lsl #1 */
/* @0x24d9a4 str r0, [r11, #-0x6c] */
/* @0x24d9a8 ldr r3, [pc, r3] */
/* @0x24d9ac str r3, [r11, #-0x68] */
/* @0x24d9b0 mov r3, #1 */
/* @0x24d9b4 str r3, [r0, #0xc] */
/* @0x24d9b8 ldr r0, [r11, #-0x68] */
/* @0x24d9bc lsl r2, r2, r3 */
/* @0x24d9c0 add r1, r2, #15 */
/* @0x24d9c4 add r2, r2, #1 */
/* @0x24d9c8 bic r1, r1, #7 */
/* @0x24d9cc ldr r3, [r0] */
/* @0x24d9d0 sub sp, sp, r1 */
/* @0x24d9d4 mov r1, #0 */
/* @0x24d9d8 str sp, [r11, #-0x60] */
/* @0x24d9dc mov r0, sp */
/* @0x24d9e0 str r3, [r11, #-0x40] */
/* @0x24d9e4 ldr r3, [r11, #0x4] */
/* @0x24d9e8 str r3, [r11, #-0x64] */
/* @0x24d9ec bl 0xb65b0 <memset@plt> */
/* @0x24d9f0 cmp r4, #0 */
/* @0x24d9f4 ble 0x24daf8 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x24d9f8 mov r2, #0 */
/* @0x24d9fc movw r3, #0xfffe */
/* @0x24da00 str r2, [r11, #-0x5c] */
/* @0x24da04 mov r9, r2 */
/* @0x24da08 mov r10, r2 */
/* @0x24da0c movt r3, #0x1f */
/* @0x24da10 sub r2, r11, #80 */
/* @0x24da14 str r3, [r11, #-0x70] */
/* @0x24da18 str r2, [r11, #-0x58] */
/* @0x24da1c vldr d8, [pc, #588] */
/* @0x24da20 vldr d9, [pc, #592] */
/* @0x24da24 vldr d10, [pc, #596] */
/* @0x24da28 ldr r3, [r11, #-0x64] */
/* @0x24da2c mov r7, #1 */
/* @0x24da30 mov r5, #0 */
/* @0x24da34 mvn r6, #-16777216 */
/* @0x24da38 add r8, r3, r9, lsl #4 */
/* @0x24da3c mov r3, r4 */
/* @0x24da40 mov r4, r8 */
/* @0x24da44 mov r8, r3 */
/* @0x24da48 b 0x24da50 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x24da4c mov r7, r1 */
/* @0x24da50 sub r0, r11, #80 */
/* @0x24da54 mov r1, r4 */
/* @0x24da58 str r10, [r11, #-0x50] */
/* @0x24da5c str r10, [r11, #-0x4c] */
/* @0x24da60 str r10, [r11, #-0x48] */
/* @0x24da64 str r6, [r11, #-0x44] */
/* @0x24da68 bl 0x24d8ec <_Z11JS_ToUint16R6RValueS0_> */
/* @0x24da6c vldr s14, [r11, #-80] */
/* @0x24da70 vldr s15, [r11, #-76] */
/* @0x24da74 vcmpe.f64 d7, d8 */
/* @0x24da78 vmrs APSR_nzcv, fpscr */
/* @0x24da7c bls 0x24db68 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x24da80 vcmpe.f64 d7, d9 */
/* @0x24da84 vmrs APSR_nzcv, fpscr */
/* @0x24da88 ble 0x24da98 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x24da8c vcmpe.f64 d7, d10 */
/* @0x24da90 vmrs APSR_nzcv, fpscr */
/* @0x24da94 bls 0x24db68 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x24da98 vcvt.s32.f64 s13, d7 */
/* @0x24da9c vmov r2, s13 */
/* @0x24daa0 ands r1, r2, #1024 */
/* @0x24daa4 bne 0x24db78 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x1f0> */
/* @0x24daa8 add r9, r9, #1 */
/* @0x24daac cmp r9, r8 */
/* @0x24dab0 beq 0x24dc5c <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x2d4> */
/* @0x24dab4 sub r5, r2, #55296 */
/* @0x24dab8 cmp r8, r9 */
/* @0x24dabc add r4, r4, #16 */
/* @0x24dac0 lsl r5, r5, #10 */
/* @0x24dac4 add r5, r5, #65536 */
/* @0x24dac8 bgt 0x24da4c <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x24dacc mov r4, r8 */
/* @0x24dad0 cmp r5, #126 */
/* @0x24dad4 bgt 0x24db24 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x24dad8 ldr r2, [r11, #-0x5c] */
/* @0x24dadc ldr r3, [r11, #-0x60] */
/* @0x24dae0 strb r5, [r3, r2] */
/* @0x24dae4 add r2, r2, #1 */
/* @0x24dae8 str r2, [r11, #-0x5c] */
/* @0x24daec add r9, r9, #1 */
/* @0x24daf0 cmp r4, r9 */
/* @0x24daf4 bgt 0x24da28 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x24daf8 ldr r0, [r11, #-0x6c] */
/* @0x24dafc ldr r1, [r11, #-0x60] */
/* @0x24db00 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x24db04 ldr r0, [r11, #-0x68] */
/* @0x24db08 ldr r2, [r11, #-0x40] */
/* @0x24db0c ldr r3, [r0] */
/* @0x24db10 cmp r2, r3 */
/* @0x24db14 bne 0x24dc68 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x2e0> */
/* @0x24db18 sub sp, r11, #56 */
/* @0x24db1c vpop {d8, d9, d10} */
/* @0x24db20 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24db24 movw r2, #0x7fe */
/* @0x24db28 cmp r5, r2 */
/* @0x24db2c bgt 0x24db90 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x208> */
/* @0x24db30 ldr r3, [r11, #-0x5c] */
/* @0x24db34 ubfx r2, r5, #0x6, #0x5 */
/* @0x24db38 ldr r0, [r11, #-0x60] */
/* @0x24db3c and r5, r5, #63 */
/* @0x24db40 add r1, r3, #1 */
/* @0x24db44 mvn r2, r2, lsl #26 */
/* @0x24db48 mvn r5, r5, lsl #25 */
/* @0x24db4c mvn r2, r2, lsr #26 */
/* @0x24db50 mvn r5, r5, lsr #25 */
/* @0x24db54 strb r2, [r0, r3] */
/* @0x24db58 add r3, r3, #2 */
/* @0x24db5c strb r5, [r0, r1] */
/* @0x24db60 str r3, [r11, #-0x5c] */
/* @0x24db64 b 0x24daec <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x24db68 vcvt.s32.f64 s13, d7 */
/* @0x24db6c mov r4, r8 */
/* @0x24db70 vmov r5, s13 */
/* @0x24db74 b 0x24dad0 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x24db78 cmp r7, #0 */
/* @0x24db7c mov r4, r8 */
/* @0x24db80 subeq r2, r2, #56320 */
/* @0x24db84 orreq r5, r5, r2 */
/* @0x24db88 movne r5, r2 */
/* @0x24db8c b 0x24dad0 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x24db90 movw r2, #0xfffe */
/* @0x24db94 cmp r5, r2 */
/* @0x24db98 bgt 0x24dbec <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x24db9c ldr r3, [r11, #-0x5c] */
/* @0x24dba0 ubfx r12, r5, #0xc, #0x4 */
/* @0x24dba4 ldr r1, [r11, #-0x60] */
/* @0x24dba8 ubfx r0, r5, #0x6, #0x6 */
/* @0x24dbac mvn r12, r12, lsl #27 */
/* @0x24dbb0 add lr, r3, #2 */
/* @0x24dbb4 and r2, r5, #63 */
/* @0x24dbb8 mvn r12, r12, lsr #27 */
/* @0x24dbbc strb r12, [r1, r3]! */
/* @0x24dbc0 mvn r0, r0, lsl #25 */
/* @0x24dbc4 ldr r3, [r11, #-0x60] */
/* @0x24dbc8 mvn r2, r2, lsl #25 */
/* @0x24dbcc mvn r2, r2, lsr #25 */
/* @0x24dbd0 mvn r0, r0, lsr #25 */
/* @0x24dbd4 strb r0, [r1, #0x1] */
/* @0x24dbd8 strb r2, [r3, lr] */
/* @0x24dbdc ldr r2, [r11, #-0x5c] */
/* @0x24dbe0 add r2, r2, #3 */
/* @0x24dbe4 str r2, [r11, #-0x5c] */
/* @0x24dbe8 b 0x24daec <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x24dbec ldr r3, [r11, #-0x70] */
/* @0x24dbf0 cmp r5, r3 */
/* @0x24dbf4 bgt 0x24daec <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x24dbf8 and lr, r5, #3670016 */
/* @0x24dbfc ldr r2, [r11, #-0x60] */
/* @0x24dc00 ldr r3, [r11, #-0x5c] */
/* @0x24dc04 ubfx r12, r5, #0xc, #0x6 */
/* @0x24dc08 asr lr, lr, #18 */
/* @0x24dc0c ubfx r0, r5, #0x6, #0x6 */
/* @0x24dc10 and r1, r5, #63 */
/* @0x24dc14 mvn r12, r12, lsl #25 */
/* @0x24dc18 mvn lr, lr, lsl #28 */
/* @0x24dc1c mvn r0, r0, lsl #25 */
/* @0x24dc20 mvn lr, lr, lsr #28 */
/* @0x24dc24 strb lr, [r2, r3]! */
/* @0x24dc28 add lr, r3, #3 */
/* @0x24dc2c ldr r3, [r11, #-0x60] */
/* @0x24dc30 mvn r12, r12, lsr #25 */
/* @0x24dc34 mvn r0, r0, lsr #25 */
/* @0x24dc38 strb r12, [r2, #0x1] */
/* @0x24dc3c mvn r1, r1, lsl #25 */
/* @0x24dc40 strb r0, [r2, #0x2] */
/* @0x24dc44 mvn r1, r1, lsr #25 */
/* @0x24dc48 ldr r2, [r11, #-0x5c] */
/* @0x24dc4c strb r1, [r3, lr] */
/* @0x24dc50 add r2, r2, #4 */
/* @0x24dc54 str r2, [r11, #-0x5c] */
/* @0x24dc58 b 0x24daec <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x24dc5c mov r4, r8 */
/* @0x24dc60 vmov r5, s13 */
/* @0x24dc64 b 0x24dad0 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x24dc68 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x24dc6c nop */
/* @0x24dc70 andeq r0, r0, r0 */
/* @0x24dc74 rscmi pc, r10, r0, ror #31 */
/* @0x24dc78 andeq r0, r0, r0 */
/* @0x24dc7c rscmi r0, r12, r0 */
/* @0x24dc80 andeq r0, r0, r0 */
/* @0x24dc84 rscmi pc, pc, r0, ror #31 */
/* @0x24dc88 andseq pc, r9, r8, lsr #31 */

/* ── FUNC 0x24dc8c · anon_24dc8c · size=4 · insn=1 */
/* @0x24dc8c nop */

/* ── FUNC 0x24dc90 · JS_Number_Constructor(RValue&, CInstance*, CInstance*, int, RValue*) · size=172 · insn=43 */
/* @0x24dc90 push {r4, r5, r6, lr} */
/* @0x24dc94 sub sp, sp, #24 */
/* @0x24dc98 mov r6, r3 */
/* @0x24dc9c mov r4, r0 */
/* @0x24dca0 ldr r5, [sp, #0x28] */
/* @0x24dca4 str r5, [sp] */
/* @0x24dca8 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x24dcac ldr r2, [pc, #0x7c] */
/* @0x24dcb0 ldr r4, [r4] */
/* @0x24dcb4 ldr r2, [pc, r2] */
/* @0x24dcb8 ldr r3, [pc, #0x74] */
/* @0x24dcbc ldr r1, [r2] */
/* @0x24dcc0 add r3, pc, r3 */
/* @0x24dcc4 mov r0, r4 */
/* @0x24dcc8 str r3, [r4, #0x40] */
/* @0x24dccc str r1, [r4, #0x18] */
/* @0x24dcd0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x24dcd4 ldr r1, [r4, #0x28] */
/* @0x24dcd8 cmp r6, #0 */
/* @0x24dcdc mov r0, #0 */
/* @0x24dce0 mov r2, #0 */
/* @0x24dce4 mov r3, #0 */
/* @0x24dce8 orr r1, r1, #1 */
/* @0x24dcec str r0, [sp, #0x10] */
/* @0x24dcf0 str r0, [sp, #0x14] */
/* @0x24dcf4 add r6, sp, #8 */
/* @0x24dcf8 str r1, [r4, #0x28] */
/* @0x24dcfc strd r2, r3, [sp, #8] */
/* @0x24dd00 ble 0x24dd10 <_Z21JS_Number_ConstructorR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x24dd04 mov r1, r5 */
/* @0x24dd08 mov r0, r6 */
/* @0x24dd0c bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x24dd10 ldr r1, [pc, #0x20] */
/* @0x24dd14 mov r0, r4 */
/* @0x24dd18 mov r2, r6 */
/* @0x24dd1c mov r3, #0 */
/* @0x24dd20 add r1, pc, r1 */
/* @0x24dd24 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x24dd28 add sp, sp, #24 */
/* @0x24dd2c pop {r4, r5, r6, pc} */
/* @0x24dd30 andseq r3, r10, r0, asr r10 */
/* @0x24dd34 ldrsbeq r7, [r0], -r0 */
/* @0x24dd38 ldrsheq r7, [r0], -r0 */

/* ── FUNC 0x24dd3c · F_JS_ToString(RValue&, RValue*) · size=888 · insn=222 */
/* @0x24dd3c push {r4, r5, r6, r7, lr} */
/* @0x24dd40 mvn r3, #-16777216 */
/* @0x24dd44 ldr r7, [pc, #0x340] */
/* @0x24dd48 mov r6, r0 */
/* @0x24dd4c str r3, [r0, #0xc] */
/* @0x24dd50 sub sp, sp, #292 */
/* @0x24dd54 ldr r7, [pc, r7] */
/* @0x24dd58 ldr r0, [r1, #0xc] */
/* @0x24dd5c mov r3, #0 */
/* @0x24dd60 str r3, [r6, #0x4] */
/* @0x24dd64 ldr r12, [r7] */
/* @0x24dd68 bic r2, r0, #-16777216 */
/* @0x24dd6c str r3, [r6] */
/* @0x24dd70 str r3, [r6, #0x8] */
/* @0x24dd74 str r12, [sp, #0x11c] */
/* @0x24dd78 cmp r2, #13 */
/* @0x24dd7c addls pc, pc, r2, lsl #2 */
/* @0x24dd80 b 0x24df20 <_Z13F_JS_ToStringR6RValuePS_+0x1e4> */
/* @0x24dd84 b 0x24de6c <_Z13F_JS_ToStringR6RValuePS_+0x130> */
/* @0x24dd88 b 0x24debc <_Z13F_JS_ToStringR6RValuePS_+0x180> */
/* @0x24dd8c b 0x24df20 <_Z13F_JS_ToStringR6RValuePS_+0x1e4> */
/* @0x24dd90 b 0x24df20 <_Z13F_JS_ToStringR6RValuePS_+0x1e4> */
/* @0x24dd94 b 0x24df20 <_Z13F_JS_ToStringR6RValuePS_+0x1e4> */
/* @0x24dd98 b 0x24ddbc <_Z13F_JS_ToStringR6RValuePS_+0x80> */
/* @0x24dd9c b 0x24dde8 <_Z13F_JS_ToStringR6RValuePS_+0xac> */
/* @0x24dda0 b 0x24de6c <_Z13F_JS_ToStringR6RValuePS_+0x130> */
/* @0x24dda4 b 0x24df20 <_Z13F_JS_ToStringR6RValuePS_+0x1e4> */
/* @0x24dda8 b 0x24df20 <_Z13F_JS_ToStringR6RValuePS_+0x1e4> */
/* @0x24ddac b 0x24de6c <_Z13F_JS_ToStringR6RValuePS_+0x130> */
/* @0x24ddb0 b 0x24df20 <_Z13F_JS_ToStringR6RValuePS_+0x1e4> */
/* @0x24ddb4 b 0x24de40 <_Z13F_JS_ToStringR6RValuePS_+0x104> */
/* @0x24ddb8 b 0x24de4c <_Z13F_JS_ToStringR6RValuePS_+0x110> */
/* @0x24ddbc ldr r1, [pc, #0x2cc] */
/* @0x24ddc0 add r1, pc, r1 */
/* @0x24ddc4 mov r0, r6 */
/* @0x24ddc8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x24ddcc mov r0, #0 */
/* @0x24ddd0 ldr r2, [sp, #0x11c] */
/* @0x24ddd4 ldr r3, [r7] */
/* @0x24ddd8 cmp r2, r3 */
/* @0x24dddc bne 0x24e088 <_Z13F_JS_ToStringR6RValuePS_+0x34c> */
/* @0x24dde0 add sp, sp, #292 */
/* @0x24dde4 pop {r4, r5, r6, r7, pc} */
/* @0x24dde8 add r5, sp, #12 */
/* @0x24ddec mov r2, #1 */
/* @0x24ddf0 mov r4, #0 */
/* @0x24ddf4 mvn r3, #-16777216 */
/* @0x24ddf8 mov r0, r5 */
/* @0x24ddfc str r4, [sp, #0xc] */
/* @0x24de00 str r4, [sp, #0x10] */
/* @0x24de04 str r4, [sp, #0x14] */
/* @0x24de08 str r3, [sp, #0x18] */
/* @0x24de0c bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i> */
/* @0x24de10 cmp r0, #2 */
/* @0x24de14 beq 0x24ddd0 <_Z13F_JS_ToStringR6RValuePS_+0x94> */
/* @0x24de18 cmp r0, #1 */
/* @0x24de1c bne 0x24df68 <_Z13F_JS_ToStringR6RValuePS_+0x22c> */
/* @0x24de20 ldr r3, [sp, #0x18] */
/* @0x24de24 sub r3, r3, #1 */
/* @0x24de28 bic r3, r3, #-16777216 */
/* @0x24de2c bic r3, r3, #3 */
/* @0x24de30 cmp r3, r4 */
/* @0x24de34 beq 0x24e04c <_Z13F_JS_ToStringR6RValuePS_+0x310> */
/* @0x24de38 mov r0, #1 */
/* @0x24de3c b 0x24ddd0 <_Z13F_JS_ToStringR6RValuePS_+0x94> */
/* @0x24de40 ldr r1, [pc, #0x24c] */
/* @0x24de44 add r1, pc, r1 */
/* @0x24de48 b 0x24ddc4 <_Z13F_JS_ToStringR6RValuePS_+0x88> */
/* @0x24de4c ldm r1, {r2, r3} */
/* @0x24de50 vmov d6, r2, r3 */
/* @0x24de54 vcmp.f64 d6, #0 */
/* @0x24de58 vmrs APSR_nzcv, fpscr */
/* @0x24de5c bne 0x24df5c <_Z13F_JS_ToStringR6RValuePS_+0x220> */
/* @0x24de60 ldr r1, [pc, #0x230] */
/* @0x24de64 add r1, pc, r1 */
/* @0x24de68 b 0x24ddc4 <_Z13F_JS_ToStringR6RValuePS_+0x88> */
/* @0x24de6c ldm r1, {r2, r3} */
/* @0x24de70 vmov d7, r2, r3 */
/* @0x24de74 vmov d6, r2, r3 */
/* @0x24de78 vcmp.f64 d7, d6 */
/* @0x24de7c vmrs APSR_nzcv, fpscr */
/* @0x24de80 bvs 0x24e07c <_Z13F_JS_ToStringR6RValuePS_+0x340> */
/* @0x24de84 mov r0, r1 */
/* @0x24de88 str r1, [sp, #0x4] */
/* @0x24de8c bl 0x240970 <_Z7yyisinfR6RValue> */
/* @0x24de90 ldr r1, [sp, #0x4] */
/* @0x24de94 subs r2, r0, #0 */
/* @0x24de98 beq 0x24dfa0 <_Z13F_JS_ToStringR6RValuePS_+0x264> */
/* @0x24de9c ldm r1, {r2, r3} */
/* @0x24dea0 vmov d7, r2, r3 */
/* @0x24dea4 vcmpe.f64 d7, #0 */
/* @0x24dea8 vmrs APSR_nzcv, fpscr */
/* @0x24deac ble 0x24e070 <_Z13F_JS_ToStringR6RValuePS_+0x334> */
/* @0x24deb0 ldr r1, [pc, #0x1e4] */
/* @0x24deb4 add r1, pc, r1 */
/* @0x24deb8 b 0x24ddc4 <_Z13F_JS_ToStringR6RValuePS_+0x88> */
/* @0x24debc str r0, [r6, #0xc] */
/* @0x24dec0 mov r0, #0 */
/* @0x24dec4 ldr r3, [r1, #0xc] */
/* @0x24dec8 ldr r2, [r1, #0x8] */
/* @0x24decc bic r3, r3, #-16777216 */
/* @0x24ded0 str r0, [r6] */
/* @0x24ded4 str r2, [r6, #0x8] */
/* @0x24ded8 cmp r3, #14 */
/* @0x24dedc addls pc, pc, r3, lsl #2 */
/* @0x24dee0 b 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218> */
/* @0x24dee4 b 0x24dfd0 <_Z13F_JS_ToStringR6RValuePS_+0x294> */
/* @0x24dee8 b 0x24e014 <_Z13F_JS_ToStringR6RValuePS_+0x2d8> */
/* @0x24deec b 0x24dfe4 <_Z13F_JS_ToStringR6RValuePS_+0x2a8> */
/* @0x24def0 b 0x24dfc0 <_Z13F_JS_ToStringR6RValuePS_+0x284> */
/* @0x24def4 b 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218> */
/* @0x24def8 b 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218> */
/* @0x24defc b 0x24df2c <_Z13F_JS_ToStringR6RValuePS_+0x1f0> */
/* @0x24df00 b 0x24dfc0 <_Z13F_JS_ToStringR6RValuePS_+0x284> */
/* @0x24df04 b 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218> */
/* @0x24df08 b 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218> */
/* @0x24df0c b 0x24dfd0 <_Z13F_JS_ToStringR6RValuePS_+0x294> */
/* @0x24df10 b 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218> */
/* @0x24df14 b 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218> */
/* @0x24df18 b 0x24dfd0 <_Z13F_JS_ToStringR6RValuePS_+0x294> */
/* @0x24df1c b 0x24dfc0 <_Z13F_JS_ToStringR6RValuePS_+0x284> */
/* @0x24df20 ldr r1, [pc, #0x178] */
/* @0x24df24 add r1, pc, r1 */
/* @0x24df28 b 0x24ddc4 <_Z13F_JS_ToStringR6RValuePS_+0x88> */
/* @0x24df2c ldr r3, [r1] */
/* @0x24df30 str r3, [r6] */
/* @0x24df34 ldr r3, [r1] */
/* @0x24df38 cmp r3, #0 */
/* @0x24df3c beq 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218> */
/* @0x24df40 str r1, [sp, #0x4] */
/* @0x24df44 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x24df48 ldr r1, [sp, #0x4] */
/* @0x24df4c ldr r1, [r1] */
/* @0x24df50 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x24df54 mov r0, #0 */
/* @0x24df58 b 0x24ddd0 <_Z13F_JS_ToStringR6RValuePS_+0x94> */
/* @0x24df5c ldr r1, [pc, #0x140] */
/* @0x24df60 add r1, pc, r1 */
/* @0x24df64 b 0x24ddc4 <_Z13F_JS_ToStringR6RValuePS_+0x88> */
/* @0x24df68 mov r0, r6 */
/* @0x24df6c mov r1, r5 */
/* @0x24df70 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x24df74 cmp r0, #1 */
/* @0x24df78 beq 0x24e034 <_Z13F_JS_ToStringR6RValuePS_+0x2f8> */
/* @0x24df7c ldr r0, [sp, #0x18] */
/* @0x24df80 sub r0, r0, #1 */
/* @0x24df84 bic r0, r0, #-16777216 */
/* @0x24df88 bics r6, r0, #3 */
/* @0x24df8c bne 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218> */
/* @0x24df90 mov r0, r5 */
/* @0x24df94 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24df98 mov r0, r6 */
/* @0x24df9c b 0x24ddd0 <_Z13F_JS_ToStringR6RValuePS_+0x94> */
/* @0x24dfa0 ldm r1, {r4, r5} */
/* @0x24dfa4 vmov d6, r4, r5 */
/* @0x24dfa8 vcmp.f64 d6, #0 */
/* @0x24dfac vmrs APSR_nzcv, fpscr */
/* @0x24dfb0 bne 0x24e058 <_Z13F_JS_ToStringR6RValuePS_+0x31c> */
/* @0x24dfb4 ldr r1, [pc, #0xec] */
/* @0x24dfb8 add r1, pc, r1 */
/* @0x24dfbc b 0x24ddc4 <_Z13F_JS_ToStringR6RValuePS_+0x88> */
/* @0x24dfc0 ldr r3, [r1] */
/* @0x24dfc4 mov r0, #0 */
/* @0x24dfc8 str r3, [r6] */
/* @0x24dfcc b 0x24ddd0 <_Z13F_JS_ToStringR6RValuePS_+0x94> */
/* @0x24dfd0 ldr r2, [r1] */
/* @0x24dfd4 mov r0, #0 */
/* @0x24dfd8 ldr r3, [r1, #0x4] */
/* @0x24dfdc stm r6, {r2, r3} */
/* @0x24dfe0 b 0x24ddd0 <_Z13F_JS_ToStringR6RValuePS_+0x94> */
/* @0x24dfe4 ldr r3, [r1] */
/* @0x24dfe8 cmp r3, #0 */
/* @0x24dfec str r3, [r6] */
/* @0x24dff0 beq 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218> */
/* @0x24dff4 ldr r0, [r3, #0x8] */
/* @0x24dff8 ldr r2, [r3] */
/* @0x24dffc cmp r0, #0 */
/* @0x24e000 streq r6, [r3, #0x8] */
/* @0x24e004 add r2, r2, #1 */
/* @0x24e008 str r2, [r3] */
/* @0x24e00c bne 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218> */
/* @0x24e010 b 0x24ddd0 <_Z13F_JS_ToStringR6RValuePS_+0x94> */
/* @0x24e014 ldr r3, [r1] */
/* @0x24e018 mov r0, #0 */
/* @0x24e01c cmp r3, #0 */
/* @0x24e020 ldrne r2, [r3, #0x4] */
/* @0x24e024 addne r2, r2, #1 */
/* @0x24e028 strne r2, [r3, #0x4] */
/* @0x24e02c str r3, [r6] */
/* @0x24e030 b 0x24ddd0 <_Z13F_JS_ToStringR6RValuePS_+0x94> */
/* @0x24e034 ldr r3, [sp, #0x18] */
/* @0x24e038 sub r3, r3, #1 */
/* @0x24e03c bic r3, r3, #-16777216 */
/* @0x24e040 bic r3, r3, #3 */
/* @0x24e044 cmp r3, #0 */
/* @0x24e048 bne 0x24de38 <_Z13F_JS_ToStringR6RValuePS_+0xfc> */
/* @0x24e04c mov r0, r5 */
/* @0x24e050 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24e054 b 0x24de38 <_Z13F_JS_ToStringR6RValuePS_+0xfc> */
/* @0x24e058 add r4, sp, #28 */
/* @0x24e05c mov r3, #256 */
/* @0x24e060 mov r0, r4 */
/* @0x24e064 bl 0x23f6c4 <_Z6g_dfmtPcPdij> */
/* @0x24e068 mov r1, r4 */
/* @0x24e06c b 0x24ddc4 <_Z13F_JS_ToStringR6RValuePS_+0x88> */
/* @0x24e070 ldr r1, [pc, #0x34] */
/* @0x24e074 add r1, pc, r1 */
/* @0x24e078 b 0x24ddc4 <_Z13F_JS_ToStringR6RValuePS_+0x88> */
/* @0x24e07c ldr r1, [pc, #0x2c] */
/* @0x24e080 add r1, pc, r1 */
/* @0x24e084 b 0x24ddc4 <_Z13F_JS_ToStringR6RValuePS_+0x88> */
/* @0x24e088 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x24e08c ldrsheq pc, [r9], -r12 */
/* @0x24e090 andeq r4, lr, r0, lsr #9 */
/* @0x24e094 andeq r4, lr, r0, ror #8 */
/* @0x24e098 andeq r6, lr, r4, asr #23 */
/* @0x24e09c andseq r7, r0, r8, lsr r5 */
/* @0x24e0a0 mulseq r0, r0, r4 */
/* @0x24e0a4 andeq r6, lr, r0, asr #21 */
/* @0x24e0a8 andeq r4, lr, r4, lsr r5 */
/* @0x24e0ac andseq r7, r0, r8, asr #28 */
/* @0x24e0b0 andeq r4, lr, r4, ror r4 */

/* ── FUNC 0x24e0b4 · UnwindExceptionStack() · size=576 · insn=144 */
/* @0x24e0b4 push {r4, r5, r6, r7, r8, lr} */
/* @0x24e0b8 sub sp, sp, #16 */
/* @0x24e0bc ldr r5, [pc, #0x20c] */
/* @0x24e0c0 ldr r3, [pc, #0x20c] */
/* @0x24e0c4 add r5, pc, r5 */
/* @0x24e0c8 ldr r3, [r5, r3] */
/* @0x24e0cc ldr r4, [r3] */
/* @0x24e0d0 cmp r4, #0 */
/* @0x24e0d4 beq 0x24e2b8 <_Z20UnwindExceptionStackv+0x204> */
/* @0x24e0d8 ldr r2, [pc, #0x1f8] */
/* @0x24e0dc mov r8, #1 */
/* @0x24e0e0 ldr r3, [pc, #0x1f4] */
/* @0x24e0e4 ldr r6, [r5, r2] */
/* @0x24e0e8 ldr r7, [r5, r3] */
/* @0x24e0ec ldr r3, [r4, #0x4c] */
/* @0x24e0f0 ldr r0, [r4, #0x28] */
/* @0x24e0f4 cmp r3, #0 */
/* @0x24e0f8 ble 0x24e2b0 <_Z20UnwindExceptionStackv+0x1fc> */
/* @0x24e0fc cmp r0, #0 */
/* @0x24e100 beq 0x24e19c <_Z20UnwindExceptionStackv+0xe8> */
/* @0x24e104 ldr r3, [r0, #0x28] */
/* @0x24e108 cmp r3, #0 */
/* @0x24e10c beq 0x24e128 <_Z20UnwindExceptionStackv+0x74> */
/* @0x24e110 b 0x24e25c <_Z20UnwindExceptionStackv+0x1a8> */
/* @0x24e114 cmp r3, #0 */
/* @0x24e118 beq 0x24e19c <_Z20UnwindExceptionStackv+0xe8> */
/* @0x24e11c ldr r3, [r3, #0x28] */
/* @0x24e120 cmp r3, #0 */
/* @0x24e124 bne 0x24e25c <_Z20UnwindExceptionStackv+0x1a8> */
/* @0x24e128 mov r1, r4 */
/* @0x24e12c bl 0xe42d8 <_Z13PerformReturnPhP6VMExec> */
/* @0x24e130 ldr r2, [r4, #0x4c] */
/* @0x24e134 ldr r3, [r4, #0x28] */
/* @0x24e138 cmp r2, #0 */
/* @0x24e13c bgt 0x24e114 <_Z20UnwindExceptionStackv+0x60> */
/* @0x24e140 cmp r3, #0 */
/* @0x24e144 str r0, [r7] */
/* @0x24e148 strb r8, [r6] */
/* @0x24e14c beq 0x24e1a4 <_Z20UnwindExceptionStackv+0xf0> */
/* @0x24e150 ldr r3, [r3, #0x28] */
/* @0x24e154 cmp r3, #0 */
/* @0x24e158 beq 0x24e1a4 <_Z20UnwindExceptionStackv+0xf0> */
/* @0x24e15c ldr r2, [r3, #0x4] */
/* @0x24e160 cmn r2, #1 */
/* @0x24e164 beq 0x24e270 <_Z20UnwindExceptionStackv+0x1bc> */
/* @0x24e168 cmp r2, #0 */
/* @0x24e16c add r0, r2, #3 */
/* @0x24e170 ldr r1, [r4, #0x5c] */
/* @0x24e174 movge r0, r2 */
/* @0x24e178 str r2, [r4, #0x44] */
/* @0x24e17c asr r2, r0, #2 */
/* @0x24e180 ldr r3, [pc, #0x158] */
/* @0x24e184 ldr r2, [r1, r2, lsl #2] */
/* @0x24e188 str r2, [r4, #0x48] */
/* @0x24e18c ldr r3, [r5, r3] */
/* @0x24e190 str r4, [r3] */
/* @0x24e194 add sp, sp, #16 */
/* @0x24e198 pop {r4, r5, r6, r7, r8, pc} */
/* @0x24e19c str r0, [r7] */
/* @0x24e1a0 strb r8, [r6] */
/* @0x24e1a4 ldr r4, [r4, #0x4] */
/* @0x24e1a8 cmp r4, #0 */
/* @0x24e1ac bne 0x24e0ec <_Z20UnwindExceptionStackv+0x38> */
/* @0x24e1b0 ldr r12, [pc, #0x12c] */
/* @0x24e1b4 mov r1, #0 */
/* @0x24e1b8 mov r3, #0 */
/* @0x24e1bc strb r1, [r6] */
/* @0x24e1c0 str r1, [sp, #0x8] */
/* @0x24e1c4 mov r2, #0 */
/* @0x24e1c8 mvn r1, #-16777216 */
/* @0x24e1cc strd r2, r3, [sp] */
/* @0x24e1d0 str r1, [sp, #0xc] */
/* @0x24e1d4 mov r0, sp */
/* @0x24e1d8 ldr r4, [r5, r12] */
/* @0x24e1dc mov r1, r4 */
/* @0x24e1e0 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x24e1e4 ldr r3, [sp] */
/* @0x24e1e8 cmp r3, #0 */
/* @0x24e1ec beq 0x24e194 <_Z20UnwindExceptionStackv+0xe0> */
/* @0x24e1f0 ldr r5, [pc, #0xf0] */
/* @0x24e1f4 add r5, pc, r5 */
/* @0x24e1f8 mov r0, r5 */
/* @0x24e1fc bl 0xd1f74 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc> */
/* @0x24e200 ldr r3, [sp] */
/* @0x24e204 mov r1, r5 */
/* @0x24e208 ldr r5, [r3] */
/* @0x24e20c mov r6, r0 */
/* @0x24e210 ldr r0, [r4] */
/* @0x24e214 bl 0x192218 <_ZN12YYObjectBase8HasValueEPKc> */
/* @0x24e218 ldr r2, [pc, #0xcc] */
/* @0x24e21c add r2, pc, r2 */
/* @0x24e220 cmp r0, #0 */
/* @0x24e224 beq 0x24e244 <_Z20UnwindExceptionStackv+0x190> */
/* @0x24e228 ldr r0, [r4] */
/* @0x24e22c ldr r3, [r0, #0x4] */
/* @0x24e230 cmp r3, #0 */
/* @0x24e234 beq 0x24e2c4 <_Z20UnwindExceptionStackv+0x210> */
/* @0x24e238 add r0, r3, r6, lsl #4 */
/* @0x24e23c ldr r3, [r0] */
/* @0x24e240 ldr r2, [r3] */
/* @0x24e244 ldr r0, [pc, #0xa4] */
/* @0x24e248 mov r1, r5 */
/* @0x24e24c add r0, pc, r0 */
/* @0x24e250 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x24e254 add sp, sp, #16 */
/* @0x24e258 pop {r4, r5, r6, r7, r8, pc} */
/* @0x24e25c ldr r2, [r3, #0x4] */
/* @0x24e260 str r0, [r7] */
/* @0x24e264 cmn r2, #1 */
/* @0x24e268 strb r8, [r6] */
/* @0x24e26c bne 0x24e168 <_Z20UnwindExceptionStackv+0xb4> */
/* @0x24e270 ldr r3, [r3, #0x8] */
/* @0x24e274 cmn r3, #1 */
/* @0x24e278 beq 0x24e1a4 <_Z20UnwindExceptionStackv+0xf0> */
/* @0x24e27c cmp r3, #0 */
/* @0x24e280 add r1, r3, #3 */
/* @0x24e284 ldr r2, [r4, #0x5c] */
/* @0x24e288 movge r1, r3 */
/* @0x24e28c str r3, [r4, #0x44] */
/* @0x24e290 asr r1, r1, #2 */
/* @0x24e294 ldr r3, [pc, #0x44] */
/* @0x24e298 ldr r2, [r2, r1, lsl #2] */
/* @0x24e29c str r2, [r4, #0x48] */
/* @0x24e2a0 ldr r3, [r5, r3] */
/* @0x24e2a4 str r4, [r3] */
/* @0x24e2a8 add sp, sp, #16 */
/* @0x24e2ac pop {r4, r5, r6, r7, r8, pc} */
/* @0x24e2b0 mov r3, r0 */
/* @0x24e2b4 b 0x24e140 <_Z20UnwindExceptionStackv+0x8c> */
/* @0x24e2b8 ldr r3, [pc, #0x18] */
/* @0x24e2bc ldr r6, [r5, r3] */
/* @0x24e2c0 b 0x24e1b0 <_Z20UnwindExceptionStackv+0xfc> */
/* @0x24e2c4 mov r1, r6 */
/* @0x24e2c8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24e2cc b 0x24e23c <_Z20UnwindExceptionStackv+0x188> */
/* @0x24e2d0 andseq r3, r10, r12, lsl #23 */
/* @0x24e2d4 .word 0xffffbf58 */
/* @0x24e2d8 .word 0xffffc0cc */
/* @0x24e2dc .word 0xffffc0e0 */
/* @0x24e2e0 .word 0xffffc0dc */
/* @0x24e2e4 .word 0xffffc0d8 */
/* @0x24e2e8 andseq r7, r0, r8, lsr r7 */
/* @0x24e2ec ldrheq r7, [r0], -r8 */
/* @0x24e2f0 mulseq r0, r8, r12 */

/* ── FUNC 0x24e2f4 · F_JSFinishFinally(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x24e2f4 ldr r3, [pc, #0x38] */
/* @0x24e2f8 push {r4, lr} */
/* @0x24e2fc ldr r3, [pc, r3] */
/* @0x24e300 mov r4, r0 */
/* @0x24e304 ldrb r3, [r3] */
/* @0x24e308 cmp r3, #0 */
/* @0x24e30c popeq {r4, pc} */
/* @0x24e310 bl 0x24e0b4 <_Z20UnwindExceptionStackv> */
/* @0x24e314 ldr r12, [pc, #0x1c] */
/* @0x24e318 ldr r12, [pc, r12] */
/* @0x24e31c ldm r12!, {r0, r1, r2, r3} */
/* @0x24e320 str r0, [r4] */
/* @0x24e324 str r1, [r4, #0x4] */
/* @0x24e328 str r2, [r4, #0x8] */
/* @0x24e32c str r3, [r4, #0xc] */
/* @0x24e330 pop {r4, pc} */
/* @0x24e334 ldrsheq r3, [r10], -r8 */
/* @0x24e338 andseq pc, r9, r0, lsl r10 */

/* ── FUNC 0x24e33c · F_JSThrow(RValue&, CInstance*, CInstance*, int, RValue*) · size=592 · insn=148 */
/* @0x24e33c push {r3, r4, r5, r6, r7, lr} */
/* @0x24e340 ldr r4, [pc, #0x23c] */
/* @0x24e344 ldr r5, [sp, #0x18] */
/* @0x24e348 ldr r4, [pc, r4] */
/* @0x24e34c ldr r2, [r4, #0xc] */
/* @0x24e350 bic r3, r2, #-16777216 */
/* @0x24e354 cmp r3, #1 */
/* @0x24e358 beq 0x24e41c <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x24e35c cmp r3, #2 */
/* @0x24e360 bne 0x24e388 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x24e364 sub r2, r2, #1 */
/* @0x24e368 bic r2, r2, #-16777216 */
/* @0x24e36c bic r2, r2, #3 */
/* @0x24e370 cmp r2, #0 */
/* @0x24e374 beq 0x24e4e8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0x24e378 mov r2, #0 */
/* @0x24e37c mov r3, #5 */
/* @0x24e380 str r2, [r4, #0x8] */
/* @0x24e384 str r3, [r4, #0xc] */
/* @0x24e388 ldr r3, [r5, #0xc] */
/* @0x24e38c mov r1, #0 */
/* @0x24e390 ldr r2, [r5, #0x8] */
/* @0x24e394 str r1, [r4] */
/* @0x24e398 str r3, [r4, #0xc] */
/* @0x24e39c ldr r3, [r5, #0xc] */
/* @0x24e3a0 str r2, [r4, #0x8] */
/* @0x24e3a4 bic r3, r3, #-16777216 */
/* @0x24e3a8 cmp r3, #14 */
/* @0x24e3ac addls pc, pc, r3, lsl #2 */
/* @0x24e3b0 b 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x24e3b4 b 0x24e410 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x24e3b8 b 0x24e46c <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x24e3bc b 0x24e484 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x24e3c0 b 0x24e3f0 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x24e3c4 b 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x24e3c8 b 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x24e3cc b 0x24e448 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x24e3d0 b 0x24e3f0 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x24e3d4 b 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x24e3d8 b 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x24e3dc b 0x24e410 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x24e3e0 b 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x24e3e4 b 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x24e3e8 b 0x24e410 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x24e3ec b 0x24e3f0 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x24e3f0 ldr r3, [r5] */
/* @0x24e3f4 str r3, [r4] */
/* @0x24e3f8 ldr r3, [pc, #0x188] */
/* @0x24e3fc mov r2, #1 */
/* @0x24e400 ldr r3, [pc, r3] */
/* @0x24e404 strb r2, [r3] */
/* @0x24e408 pop {r3, r4, r5, r6, r7, lr} */
/* @0x24e40c b 0x24e0b4 <_Z20UnwindExceptionStackv> */
/* @0x24e410 ldm r5, {r2, r3} */
/* @0x24e414 stm r4, {r2, r3} */
/* @0x24e418 b 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x24e41c ldr r6, [r4] */
/* @0x24e420 cmp r6, #0 */
/* @0x24e424 beq 0x24e388 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x24e428 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24e42c ldr r7, [r6, #0x4] */
/* @0x24e430 sub r7, r7, #1 */
/* @0x24e434 str r7, [r6, #0x4] */
/* @0x24e438 cmp r7, #0 */
/* @0x24e43c beq 0x24e4b0 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x24e440 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24e444 b 0x24e388 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x24e448 ldr r3, [r5] */
/* @0x24e44c str r3, [r4] */
/* @0x24e450 ldr r3, [r5] */
/* @0x24e454 cmp r3, #0 */
/* @0x24e458 beq 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x24e45c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x24e460 ldr r1, [r5] */
/* @0x24e464 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x24e468 b 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x24e46c ldr r3, [r5] */
/* @0x24e470 cmp r3, #0 */
/* @0x24e474 ldrne r2, [r3, #0x4] */
/* @0x24e478 addne r2, r2, #1 */
/* @0x24e47c strne r2, [r3, #0x4] */
/* @0x24e480 b 0x24e3f4 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x24e484 ldr r3, [r5] */
/* @0x24e488 cmp r3, #0 */
/* @0x24e48c str r3, [r4] */
/* @0x24e490 beq 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x24e494 ldr r1, [r3, #0x8] */
/* @0x24e498 ldr r2, [r3] */
/* @0x24e49c cmp r1, #0 */
/* @0x24e4a0 streq r4, [r3, #0x8] */
/* @0x24e4a4 add r2, r2, #1 */
/* @0x24e4a8 str r2, [r3] */
/* @0x24e4ac b 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x24e4b0 ldr r0, [r6] */
/* @0x24e4b4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24e4b8 str r7, [r6] */
/* @0x24e4bc str r7, [r6, #0x8] */
/* @0x24e4c0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24e4c4 ldr r7, [r6, #0x4] */
/* @0x24e4c8 sub r7, r7, #1 */
/* @0x24e4cc str r7, [r6, #0x4] */
/* @0x24e4d0 cmp r7, #0 */
/* @0x24e4d4 beq 0x24e4f4 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0x24e4d8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24e4dc mov r0, r6 */
/* @0x24e4e0 bl 0x27d1d0 <_ZdlPv> */
/* @0x24e4e4 b 0x24e440 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x24e4e8 mov r0, r4 */
/* @0x24e4ec bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24e4f0 b 0x24e378 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x24e4f4 ldr r0, [r6] */
/* @0x24e4f8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24e4fc str r7, [r6] */
/* @0x24e500 str r7, [r6, #0x8] */
/* @0x24e504 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24e508 ldr r7, [r6, #0x4] */
/* @0x24e50c sub r7, r7, #1 */
/* @0x24e510 str r7, [r6, #0x4] */
/* @0x24e514 cmp r7, #0 */
/* @0x24e518 beq 0x24e52c <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x1f0> */
/* @0x24e51c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24e520 mov r0, r6 */
/* @0x24e524 bl 0x27d1d0 <_ZdlPv> */
/* @0x24e528 b 0x24e4d8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x24e52c ldr r0, [r6] */
/* @0x24e530 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24e534 str r7, [r6] */
/* @0x24e538 str r7, [r6, #0x8] */
/* @0x24e53c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24e540 ldr r7, [r6, #0x4] */
/* @0x24e544 sub r7, r7, #1 */
/* @0x24e548 str r7, [r6, #0x4] */
/* @0x24e54c cmp r7, #0 */
/* @0x24e550 bne 0x24e574 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x238> */
/* @0x24e554 ldr r0, [r6] */
/* @0x24e558 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24e55c mov r0, r6 */
/* @0x24e560 str r7, [r6] */
/* @0x24e564 str r7, [r6, #0x8] */
/* @0x24e568 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x24e56c mov r0, r6 */
/* @0x24e570 bl 0x27d1d0 <_ZdlPv> */
/* @0x24e574 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24e578 mov r0, r6 */
/* @0x24e57c bl 0x27d1d0 <_ZdlPv> */
/* @0x24e580 b 0x24e51c <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x24e584 andseq pc, r9, r0, ror #19 */
/* @0x24e588 ldrsheq r3, [r10], -r4 */

/* ── FUNC 0x24e58c · JSThrowTypeError(char const*) · size=284 · insn=71 */
/* @0x24e58c push {r4, r5, r6, r7, lr} */
/* @0x24e590 sub sp, sp, #60 */
/* @0x24e594 add r6, sp, #8 */
/* @0x24e598 add r5, sp, #24 */
/* @0x24e59c mov r4, #0 */
/* @0x24e5a0 mov r1, r0 */
/* @0x24e5a4 add r7, sp, #40 */
/* @0x24e5a8 mov r0, r6 */
/* @0x24e5ac str r4, [sp, #0x8] */
/* @0x24e5b0 str r4, [sp, #0xc] */
/* @0x24e5b4 str r4, [sp, #0x10] */
/* @0x24e5b8 str r4, [sp, #0x14] */
/* @0x24e5bc str r4, [sp, #0x18] */
/* @0x24e5c0 str r4, [sp, #0x1c] */
/* @0x24e5c4 str r4, [sp, #0x20] */
/* @0x24e5c8 str r4, [sp, #0x24] */
/* @0x24e5cc bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x24e5d0 mov r1, r4 */
/* @0x24e5d4 mov r2, r4 */
/* @0x24e5d8 mov r0, r5 */
/* @0x24e5dc mov r3, #1 */
/* @0x24e5e0 str r6, [sp] */
/* @0x24e5e4 bl 0x244134 <_Z17F_JSTypeErrorCallR6RValueP9CInstanceS2_iPS_> */
/* @0x24e5e8 mov r3, #1 */
/* @0x24e5ec mov r1, r4 */
/* @0x24e5f0 str r5, [sp] */
/* @0x24e5f4 mov r2, r4 */
/* @0x24e5f8 mov r0, r7 */
/* @0x24e5fc str r4, [sp, #0x28] */
/* @0x24e600 str r4, [sp, #0x2c] */
/* @0x24e604 str r4, [sp, #0x30] */
/* @0x24e608 str r4, [sp, #0x34] */
/* @0x24e60c bl 0x24e33c <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_> */
/* @0x24e610 ldr r3, [sp, #0x14] */
/* @0x24e614 sub r3, r3, #1 */
/* @0x24e618 bic r3, r3, #-16777216 */
/* @0x24e61c bic r3, r3, #3 */
/* @0x24e620 cmp r3, r4 */
/* @0x24e624 beq 0x24e69c <_Z16JSThrowTypeErrorPKc+0x110> */
/* @0x24e628 ldr r1, [sp, #0x24] */
/* @0x24e62c mov r3, #0 */
/* @0x24e630 str r3, [sp, #0x10] */
/* @0x24e634 mov r2, #5 */
/* @0x24e638 sub r1, r1, #1 */
/* @0x24e63c str r3, [sp, #0x8] */
/* @0x24e640 bic r3, r1, #-16777216 */
/* @0x24e644 str r2, [sp, #0x14] */
/* @0x24e648 bic r3, r3, #3 */
/* @0x24e64c cmp r3, #0 */
/* @0x24e650 beq 0x24e690 <_Z16JSThrowTypeErrorPKc+0x104> */
/* @0x24e654 ldr r1, [sp, #0x34] */
/* @0x24e658 mov r3, #0 */
/* @0x24e65c str r3, [sp, #0x20] */
/* @0x24e660 mov r2, #5 */
/* @0x24e664 sub r1, r1, #1 */
/* @0x24e668 str r3, [sp, #0x18] */
/* @0x24e66c bic r3, r1, #-16777216 */
/* @0x24e670 str r2, [sp, #0x24] */
/* @0x24e674 bic r3, r3, #3 */
/* @0x24e678 cmp r3, #0 */
/* @0x24e67c bne 0x24e688 <_Z16JSThrowTypeErrorPKc+0xfc> */
/* @0x24e680 mov r0, r7 */
/* @0x24e684 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24e688 add sp, sp, #60 */
/* @0x24e68c pop {r4, r5, r6, r7, pc} */
/* @0x24e690 mov r0, r5 */
/* @0x24e694 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24e698 b 0x24e654 <_Z16JSThrowTypeErrorPKc+0xc8> */
/* @0x24e69c mov r0, r6 */
/* @0x24e6a0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24e6a4 b 0x24e628 <_Z16JSThrowTypeErrorPKc+0x9c> */

/* ── FUNC 0x24e6a8 · F_JSForInIterator(RValue&, CInstance*, CInstance*, int, RValue*) · size=200 · insn=50 */
/* @0x24e6a8 push {r4, r5, r6, lr} */
/* @0x24e6ac sub sp, sp, #16 */
/* @0x24e6b0 mov r2, #0 */
/* @0x24e6b4 mov r3, #0 */
/* @0x24e6b8 ldr r1, [sp, #0x20] */
/* @0x24e6bc mov r4, r0 */
/* @0x24e6c0 strd r2, r3, [sp] */
/* @0x24e6c4 mvn r2, #-16777216 */
/* @0x24e6c8 mov r0, #0 */
/* @0x24e6cc str r2, [sp, #0xc] */
/* @0x24e6d0 ldr r3, [r1, #0xc] */
/* @0x24e6d4 str r0, [sp, #0x8] */
/* @0x24e6d8 and r3, r3, r2 */
/* @0x24e6dc cmp r3, #5 */
/* @0x24e6e0 beq 0x24e73c <_Z17F_JSForInIteratorR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x24e6e4 cmp r3, #12 */
/* @0x24e6e8 beq 0x24e73c <_Z17F_JSForInIteratorR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x24e6ec cmp r3, r2 */
/* @0x24e6f0 beq 0x24e73c <_Z17F_JSForInIteratorR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x24e6f4 mov r0, sp */
/* @0x24e6f8 bl 0x247388 <_Z13F_JS_ToObjectR6RValuePS_> */
/* @0x24e6fc cmp r0, #1 */
/* @0x24e700 beq 0x24e758 <_Z17F_JSForInIteratorR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x24e704 mov r0, #28 */
/* @0x24e708 ldr r6, [sp] */
/* @0x24e70c bl 0x27c524 <_Znwj> */
/* @0x24e710 mov r2, #1 */
/* @0x24e714 mov r1, r6 */
/* @0x24e718 mov r5, r0 */
/* @0x24e71c bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei> */
/* @0x24e720 mov r2, #1 */
/* @0x24e724 mov r3, #14 */
/* @0x24e728 strb r2, [r5, #0x10] */
/* @0x24e72c str r5, [r4] */
/* @0x24e730 str r3, [r4, #0xc] */
/* @0x24e734 add sp, sp, #16 */
/* @0x24e738 pop {r4, r5, r6, pc} */
/* @0x24e73c mov r3, #0 */
/* @0x24e740 mov r2, #5 */
/* @0x24e744 str r3, [r4] */
/* @0x24e748 str r2, [r4, #0xc] */
/* @0x24e74c str r3, [r4, #0x4] */
/* @0x24e750 add sp, sp, #16 */
/* @0x24e754 pop {r4, r5, r6, pc} */
/* @0x24e758 ldr r0, [pc, #0xc] */
/* @0x24e75c add r0, pc, r0 */
/* @0x24e760 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x24e764 add sp, sp, #16 */
/* @0x24e768 pop {r4, r5, r6, pc} */
/* @0x24e76c ldrheq r7, [r0], -r8 */

/* ── FUNC 0x24e770 · JS_Function_prototype_toString(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x24e770 push {r4, r5, r6, lr} */
/* @0x24e774 mov r5, r1 */
/* @0x24e778 ldr r4, [pc, #0xb8] */
/* @0x24e77c sub sp, sp, #1024 */
/* @0x24e780 ldr r1, [pc, #0xb4] */
/* @0x24e784 sub sp, sp, #8 */
/* @0x24e788 ldr r4, [pc, r4] */
/* @0x24e78c mov r6, r0 */
/* @0x24e790 add r1, pc, r1 */
/* @0x24e794 ldr r0, [r5, #0x40] */
/* @0x24e798 ldr r3, [r4] */
/* @0x24e79c str r3, [sp, #0x404] */
/* @0x24e7a0 bl 0xb6574 <strcmp@plt> */
/* @0x24e7a4 cmp r0, #0 */
/* @0x24e7a8 bne 0x24e804 <_Z30JS_Function_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x24e7ac ldr r3, [r5, #0x64] */
/* @0x24e7b0 cmp r3, #0 */
/* @0x24e7b4 beq 0x24e814 <_Z30JS_Function_prototype_toStringR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x24e7b8 add r5, sp, #4 */
/* @0x24e7bc ldr r2, [pc, #0x7c] */
/* @0x24e7c0 ldr r3, [r3, #0x14] */
/* @0x24e7c4 mov r1, #1024 */
/* @0x24e7c8 add r2, pc, r2 */
/* @0x24e7cc mov r0, r5 */
/* @0x24e7d0 bl 0xb65c8 <snprintf@plt> */
/* @0x24e7d4 mov r0, r5 */
/* @0x24e7d8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x24e7dc mov r1, r0 */
/* @0x24e7e0 mov r0, r6 */
/* @0x24e7e4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x24e7e8 ldr r2, [sp, #0x404] */
/* @0x24e7ec ldr r3, [r4] */
/* @0x24e7f0 cmp r2, r3 */
/* @0x24e7f4 bne 0x24e834 <_Z30JS_Function_prototype_toStringR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x24e7f8 add sp, sp, #1024 */
/* @0x24e7fc add sp, sp, #8 */
/* @0x24e800 pop {r4, r5, r6, pc} */
/* @0x24e804 ldr r0, [pc, #0x38] */
/* @0x24e808 add r0, pc, r0 */
/* @0x24e80c bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x24e810 b 0x24e7e8 <_Z30JS_Function_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x24e814 ldr r3, [r5, #0x68] */
/* @0x24e818 add r5, sp, #4 */
/* @0x24e81c ldr r2, [pc, #0x24] */
/* @0x24e820 mov r1, #1024 */
/* @0x24e824 mov r0, r5 */
/* @0x24e828 add r2, pc, r2 */
/* @0x24e82c bl 0xb65c8 <snprintf@plt> */
/* @0x24e830 b 0x24e7d4 <_Z30JS_Function_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x24e834 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x24e838 andseq pc, r9, r8, asr #3 */
/* @0x24e83c andseq r6, r0, r4, asr #27 */
/* @0x24e840 andseq r7, r0, r12, lsl #15 */
/* @0x24e844 andseq r7, r0, r0, asr #14 */
/* @0x24e848 andseq r7, r0, r0, asr #14 */

/* ── FUNC 0x24e84c · JS_Function_prototype_apply(RValue&, CInstance*, CInstance*, int, RValue*) · size=548 · insn=137 */
/* @0x24e84c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24e850 sub sp, sp, #60 */
/* @0x24e854 ldr r4, [pc, #0x1f8] */
/* @0x24e858 mov r8, r1 */
/* @0x24e85c str r0, [sp, #0xc] */
/* @0x24e860 mov r0, r1 */
/* @0x24e864 ldr r4, [pc, r4] */
/* @0x24e868 ldr r5, [sp, #0x60] */
/* @0x24e86c ldr r3, [r4] */
/* @0x24e870 str r3, [sp, #0x34] */
/* @0x24e874 bl 0x240758 <_Z20JS_IsCallable_ObjectP12YYObjectBase> */
/* @0x24e878 cmp r0, #0 */
/* @0x24e87c beq 0x24e920 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x24e880 ldr r3, [r5, #0xc] */
/* @0x24e884 ldr r6, [pc, #0x1cc] */
/* @0x24e888 bic r3, r3, #-16777216 */
/* @0x24e88c ldr r6, [pc, r6] */
/* @0x24e890 cmp r3, #6 */
/* @0x24e894 ldr r9, [r6] */
/* @0x24e898 beq 0x24e8f0 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x24e89c mov r0, r5 */
/* @0x24e8a0 bl 0x241dc0 <_Z16F_JS_IsPrimitiveR6RValue> */
/* @0x24e8a4 cmp r0, #0 */
/* @0x24e8a8 bne 0x24ea34 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0x24e8ac ldr r3, [r5, #0x1c] */
/* @0x24e8b0 bic r3, r3, #-16777216 */
/* @0x24e8b4 cmp r3, #12 */
/* @0x24e8b8 beq 0x24e904 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x24e8bc cmp r3, #5 */
/* @0x24e8c0 beq 0x24e904 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x24e8c4 cmp r3, #6 */
/* @0x24e8c8 beq 0x24e930 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x24e8cc ldr r0, [pc, #0x188] */
/* @0x24e8d0 add r0, pc, r0 */
/* @0x24e8d4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x24e8d8 ldr r2, [sp, #0x34] */
/* @0x24e8dc ldr r3, [r4] */
/* @0x24e8e0 cmp r2, r3 */
/* @0x24e8e4 bne 0x24ea50 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0x204> */
/* @0x24e8e8 add sp, sp, #60 */
/* @0x24e8ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24e8f0 ldr r3, [r5, #0x1c] */
/* @0x24e8f4 ldr r9, [r5] */
/* @0x24e8f8 bic r3, r3, #-16777216 */
/* @0x24e8fc cmp r3, #12 */
/* @0x24e900 bne 0x24e8bc <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x24e904 mov r3, #0 */
/* @0x24e908 mov r0, r9 */
/* @0x24e90c ldr r1, [sp, #0xc] */
/* @0x24e910 mov r2, r8 */
/* @0x24e914 str r3, [sp] */
/* @0x24e918 bl 0x249590 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_> */
/* @0x24e91c b 0x24e8d8 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x24e920 ldr r0, [pc, #0x138] */
/* @0x24e924 add r0, pc, r0 */
/* @0x24e928 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x24e92c b 0x24e8d8 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x24e930 ldr r2, [pc, #0x12c] */
/* @0x24e934 add r1, sp, #24 */
/* @0x24e938 ldr r0, [r5, #0x10] */
/* @0x24e93c mvn r3, #-16777216 */
/* @0x24e940 add r2, pc, r2 */
/* @0x24e944 str r3, [sp, #0x24] */
/* @0x24e948 mov r10, #0 */
/* @0x24e94c mov r11, #0 */
/* @0x24e950 mov r6, #0 */
/* @0x24e954 strd r10, r11, [sp, #24] */
/* @0x24e958 str r6, [sp, #0x20] */
/* @0x24e95c bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x24e960 vmov.f64 d6, #1.600000e+01 */
/* @0x24e964 vldr d7, [sp, #24] */
/* @0x24e968 ldr r1, [pc, #0xf8] */
/* @0x24e96c mov r2, #70 */
/* @0x24e970 mov r3, #1 */
/* @0x24e974 add r1, pc, r1 */
/* @0x24e978 vmul.f64 d7, d7, d6 */
/* @0x24e97c vcvt.s32.f64 s13, d7 */
/* @0x24e980 vmov r0, s13 */
/* @0x24e984 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x24e988 vldr d7, [sp, #24] */
/* @0x24e98c vcmpe.f64 d7, #0 */
/* @0x24e990 vmrs APSR_nzcv, fpscr */
/* @0x24e994 str r0, [sp, #0x10] */
/* @0x24e998 ble 0x24ea08 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0x1bc> */
/* @0x24e99c ldr r3, [pc, #0xc8] */
/* @0x24e9a0 mov r10, r6 */
/* @0x24e9a4 add r7, sp, #40 */
/* @0x24e9a8 mov r11, r6 */
/* @0x24e9ac add r3, pc, r3 */
/* @0x24e9b0 str r4, [sp, #0x14] */
/* @0x24e9b4 mov r6, r0 */
/* @0x24e9b8 mov r4, r10 */
/* @0x24e9bc mov r10, r3 */
/* @0x24e9c0 mov r2, r4 */
/* @0x24e9c4 mov r1, r10 */
/* @0x24e9c8 mov r0, r7 */
/* @0x24e9cc add r4, r4, #1 */
/* @0x24e9d0 strb r11, [sp, #0x28] */
/* @0x24e9d4 bl 0xb6550 <sprintf@plt> */
/* @0x24e9d8 mov r1, r6 */
/* @0x24e9dc ldr r0, [r5, #0x10] */
/* @0x24e9e0 mov r2, r7 */
/* @0x24e9e4 add r6, r6, #16 */
/* @0x24e9e8 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x24e9ec vmov s15, r4 */
/* @0x24e9f0 vcvt.f64.s32 d6, s15 */
/* @0x24e9f4 vldr d7, [sp, #24] */
/* @0x24e9f8 vcmpe.f64 d6, d7 */
/* @0x24e9fc vmrs APSR_nzcv, fpscr */
/* @0x24ea00 bmi 0x24e9c0 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x24ea04 ldr r4, [sp, #0x14] */
/* @0x24ea08 vcvt.s32.f64 s13, d7 */
/* @0x24ea0c ldr r3, [sp, #0x10] */
/* @0x24ea10 mov r0, r9 */
/* @0x24ea14 ldr r1, [sp, #0xc] */
/* @0x24ea18 mov r2, r8 */
/* @0x24ea1c str r3, [sp] */
/* @0x24ea20 vmov r3, s13 */
/* @0x24ea24 bl 0x249590 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_> */
/* @0x24ea28 ldr r0, [sp, #0x10] */
/* @0x24ea2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x24ea30 b 0x24e8d8 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x24ea34 add r0, sp, #24 */
/* @0x24ea38 mov r1, r5 */
/* @0x24ea3c bl 0x247388 <_Z13F_JS_ToObjectR6RValuePS_> */
/* @0x24ea40 cmp r0, #0 */
/* @0x24ea44 ldrne r9, [r6] */
/* @0x24ea48 ldreq r9, [sp, #0x18] */
/* @0x24ea4c b 0x24e8ac <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x24ea50 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x24ea54 andseq pc, r9, r12, ror #1 */
/* @0x24ea58 andseq pc, r9, r12, lsl r4 */
/* @0x24ea5c andseq r7, r0, r4, ror #13 */
/* @0x24ea60 andseq r7, r0, r8, asr r6 */
/* @0x24ea64 andeq r1, lr, r12, lsr #30 */
/* @0x24ea68 strheq r2, [lr], -r12 */
/* @0x24ea6c andeq r3, lr, r0, ror #22 */

/* ── FUNC 0x24ea70 · JS_Function_prototype_call(RValue&, CInstance*, CInstance*, int, RValue*) · size=184 · insn=46 */
/* @0x24ea70 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x24ea74 sub sp, sp, #28 */
/* @0x24ea78 mov r9, r0 */
/* @0x24ea7c mov r0, r1 */
/* @0x24ea80 mov r6, r1 */
/* @0x24ea84 mov r8, r3 */
/* @0x24ea88 ldr r4, [sp, #0x38] */
/* @0x24ea8c bl 0x240758 <_Z20JS_IsCallable_ObjectP12YYObjectBase> */
/* @0x24ea90 cmp r0, #0 */
/* @0x24ea94 beq 0x24eaf0 <_Z26JS_Function_prototype_callR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x24ea98 ldr r3, [r4, #0xc] */
/* @0x24ea9c ldr r5, [pc, #0x7c] */
/* @0x24eaa0 bic r3, r3, #-16777216 */
/* @0x24eaa4 ldr r5, [pc, r5] */
/* @0x24eaa8 cmp r3, #6 */
/* @0x24eaac ldr r7, [r5] */
/* @0x24eab0 beq 0x24eae8 <_Z26JS_Function_prototype_callR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x24eab4 mov r0, r4 */
/* @0x24eab8 bl 0x241dc0 <_Z16F_JS_IsPrimitiveR6RValue> */
/* @0x24eabc cmp r0, #0 */
/* @0x24eac0 bne 0x24eb04 <_Z26JS_Function_prototype_callR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x24eac4 add r4, r4, #16 */
/* @0x24eac8 mov r0, r7 */
/* @0x24eacc str r4, [sp] */
/* @0x24ead0 mov r1, r9 */
/* @0x24ead4 mov r2, r6 */
/* @0x24ead8 sub r3, r8, #1 */
/* @0x24eadc bl 0x249590 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_> */
/* @0x24eae0 add sp, sp, #28 */
/* @0x24eae4 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x24eae8 ldr r7, [r4] */
/* @0x24eaec b 0x24eac4 <_Z26JS_Function_prototype_callR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x24eaf0 ldr r0, [pc, #0x2c] */
/* @0x24eaf4 add r0, pc, r0 */
/* @0x24eaf8 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x24eafc add sp, sp, #28 */
/* @0x24eb00 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x24eb04 add r0, sp, #8 */
/* @0x24eb08 mov r1, r4 */
/* @0x24eb0c bl 0x247388 <_Z13F_JS_ToObjectR6RValuePS_> */
/* @0x24eb10 cmp r0, #0 */
/* @0x24eb14 ldrne r7, [r5] */
/* @0x24eb18 ldreq r7, [sp, #0x8] */
/* @0x24eb1c b 0x24eac4 <_Z26JS_Function_prototype_callR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x24eb20 andseq pc, r9, r4, lsl #4 */
/* @0x24eb24 andseq r7, r0, r0, lsl #10 */

/* ── FUNC 0x24eb28 · F_JSThrowTypeError(RValue&, CInstance*, CInstance*, int, RValue*) · size=16 · insn=4 */
/* @0x24eb28 ldr r0, [pc, #0x4] */
/* @0x24eb2c add r0, pc, r0 */
/* @0x24eb30 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x24eb34 andseq r7, r0, r12, lsl r4 */

/* ── FUNC 0x24eb38 · F_JSObjectConstructor_Internal(RValue&, CInstance*, CInstance*, int, RValue*) · size=568 · insn=142 */
/* @0x24eb38 cmp r3, #0 */
/* @0x24eb3c push {r4, r5, r6, r7, r8, lr} */
/* @0x24eb40 mov r5, r0 */
/* @0x24eb44 ldr r4, [sp, #0x18] */
/* @0x24eb48 ble 0x24ec20 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x24eb4c ldr r6, [r4, #0xc] */
/* @0x24eb50 bic r12, r6, #-16777216 */
/* @0x24eb54 cmp r12, #13 */
/* @0x24eb58 bhi 0x24ec20 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x24eb5c mov r8, #1 */
/* @0x24eb60 movw r7, #0x2483 */
/* @0x24eb64 lsl r12, r8, r12 */
/* @0x24eb68 and r7, r12, r7 */
/* @0x24eb6c cmp r7, #0 */
/* @0x24eb70 bne 0x24ec40 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x24eb74 tst r12, #64 */
/* @0x24eb78 beq 0x24ec20 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x24eb7c ldr r2, [r0, #0xc] */
/* @0x24eb80 bic r3, r2, #-16777216 */
/* @0x24eb84 cmp r3, r8 */
/* @0x24eb88 beq 0x24ec60 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x24eb8c cmp r3, #2 */
/* @0x24eb90 bne 0x24ebbc <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x24eb94 sub r3, r2, #1 */
/* @0x24eb98 bic r3, r3, #-16777216 */
/* @0x24eb9c bic r3, r3, #3 */
/* @0x24eba0 cmp r3, #0 */
/* @0x24eba4 beq 0x24ed0c <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x1d4> */
/* @0x24eba8 mov r2, #5 */
/* @0x24ebac str r2, [r5, #0xc] */
/* @0x24ebb0 ldr r6, [r4, #0xc] */
/* @0x24ebb4 mov r3, #0 */
/* @0x24ebb8 str r3, [r5, #0x8] */
/* @0x24ebbc ldr r2, [r4, #0x8] */
/* @0x24ebc0 mov r1, #0 */
/* @0x24ebc4 str r6, [r5, #0xc] */
/* @0x24ebc8 ldr r3, [r4, #0xc] */
/* @0x24ebcc str r1, [r5] */
/* @0x24ebd0 bic r3, r3, #-16777216 */
/* @0x24ebd4 str r2, [r5, #0x8] */
/* @0x24ebd8 cmp r3, #14 */
/* @0x24ebdc addls pc, pc, r3, lsl #2 */
/* @0x24ebe0 b 0x24ec3c <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x24ebe4 b 0x24ec98 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x24ebe8 b 0x24ecc8 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x190> */
/* @0x24ebec b 0x24ece0 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x24ebf0 b 0x24ec30 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x24ebf4 b 0x24ec3c <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x24ebf8 b 0x24ec3c <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x24ebfc b 0x24eca4 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x24ec00 b 0x24ec30 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x24ec04 b 0x24ec3c <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x24ec08 b 0x24ec3c <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x24ec0c b 0x24ec98 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x24ec10 b 0x24ec3c <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x24ec14 b 0x24ec3c <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x24ec18 b 0x24ec98 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x24ec1c b 0x24ec30 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x24ec20 str r4, [sp, #0x18] */
/* @0x24ec24 mov r0, r5 */
/* @0x24ec28 pop {r4, r5, r6, r7, r8, lr} */
/* @0x24ec2c b 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x24ec30 ldr r3, [r4] */
/* @0x24ec34 str r3, [r5] */
/* @0x24ec38 pop {r4, r5, r6, r7, r8, pc} */
/* @0x24ec3c pop {r4, r5, r6, r7, r8, pc} */
/* @0x24ec40 mov r1, r4 */
/* @0x24ec44 bl 0x247388 <_Z13F_JS_ToObjectR6RValuePS_> */
/* @0x24ec48 cmp r0, #1 */
/* @0x24ec4c popne {r4, r5, r6, r7, r8, pc} */
/* @0x24ec50 ldr r0, [pc, #0x114] */
/* @0x24ec54 pop {r4, r5, r6, r7, r8, lr} */
/* @0x24ec58 add r0, pc, r0 */
/* @0x24ec5c b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x24ec60 ldr r7, [r0] */
/* @0x24ec64 cmp r7, #0 */
/* @0x24ec68 beq 0x24ec8c <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x24ec6c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24ec70 ldr r6, [r7, #0x4] */
/* @0x24ec74 sub r6, r6, #1 */
/* @0x24ec78 str r6, [r7, #0x4] */
/* @0x24ec7c cmp r6, #0 */
/* @0x24ec80 beq 0x24ed14 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x1dc> */
/* @0x24ec84 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24ec88 ldr r6, [r4, #0xc] */
/* @0x24ec8c mov r3, #0 */
/* @0x24ec90 str r3, [r5] */
/* @0x24ec94 b 0x24ebbc <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x24ec98 ldm r4, {r2, r3} */
/* @0x24ec9c stm r5, {r2, r3} */
/* @0x24eca0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x24eca4 ldr r3, [r4] */
/* @0x24eca8 str r3, [r5] */
/* @0x24ecac ldr r3, [r4] */
/* @0x24ecb0 cmp r3, #0 */
/* @0x24ecb4 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x24ecb8 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x24ecbc ldr r1, [r4] */
/* @0x24ecc0 pop {r4, r5, r6, r7, r8, lr} */
/* @0x24ecc4 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x24ecc8 ldr r3, [r4] */
/* @0x24eccc cmp r3, #0 */
/* @0x24ecd0 ldrne r2, [r3, #0x4] */
/* @0x24ecd4 addne r2, r2, #1 */
/* @0x24ecd8 strne r2, [r3, #0x4] */
/* @0x24ecdc b 0x24ec34 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x24ece0 ldr r3, [r4] */
/* @0x24ece4 cmp r3, #0 */
/* @0x24ece8 str r3, [r5] */
/* @0x24ecec popeq {r4, r5, r6, r7, r8, pc} */
/* @0x24ecf0 ldr r1, [r3, #0x8] */
/* @0x24ecf4 ldr r2, [r3] */
/* @0x24ecf8 cmp r1, #0 */
/* @0x24ecfc streq r5, [r3, #0x8] */
/* @0x24ed00 add r2, r2, #1 */
/* @0x24ed04 str r2, [r3] */
/* @0x24ed08 pop {r4, r5, r6, r7, r8, pc} */
/* @0x24ed0c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24ed10 b 0x24eba8 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x24ed14 ldr r0, [r7] */
/* @0x24ed18 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24ed1c str r6, [r7] */
/* @0x24ed20 str r6, [r7, #0x8] */
/* @0x24ed24 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24ed28 ldr r6, [r7, #0x4] */
/* @0x24ed2c sub r6, r6, #1 */
/* @0x24ed30 str r6, [r7, #0x4] */
/* @0x24ed34 cmp r6, #0 */
/* @0x24ed38 bne 0x24ed5c <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x224> */
/* @0x24ed3c ldr r0, [r7] */
/* @0x24ed40 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24ed44 mov r0, r7 */
/* @0x24ed48 str r6, [r7] */
/* @0x24ed4c str r6, [r7, #0x8] */
/* @0x24ed50 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x24ed54 mov r0, r7 */
/* @0x24ed58 bl 0x27d1d0 <_ZdlPv> */
/* @0x24ed5c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24ed60 mov r0, r7 */
/* @0x24ed64 bl 0x27d1d0 <_ZdlPv> */
/* @0x24ed68 b 0x24ec84 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x24ed6c ldrsbeq r7, [r0], -r4 */

/* ── FUNC 0x24ed70 · F_JSObjectCall(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x24ed70 push {r4, r5, r6, r7, r8, lr} */
/* @0x24ed74 subs r5, r3, #0 */
/* @0x24ed78 sub sp, sp, #8 */
/* @0x24ed7c mov r8, r0 */
/* @0x24ed80 mov r7, r1 */
/* @0x24ed84 mov r6, r2 */
/* @0x24ed88 ldr r12, [sp, #0x20] */
/* @0x24ed8c beq 0x24edbc <_Z14F_JSObjectCallR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x24ed90 ldr r4, [r12, #0xc] */
/* @0x24ed94 cmp r4, #5 */
/* @0x24ed98 beq 0x24edbc <_Z14F_JSObjectCallR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x24ed9c cmp r4, #12 */
/* @0x24eda0 beq 0x24edbc <_Z14F_JSObjectCallR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x24eda4 str r12, [sp] */
/* @0x24eda8 bl 0x247648 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_> */
/* @0x24edac cmp r0, #1 */
/* @0x24edb0 beq 0x24eddc <_Z14F_JSObjectCallR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x24edb4 add sp, sp, #8 */
/* @0x24edb8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x24edbc str r12, [sp, #0x20] */
/* @0x24edc0 mov r0, r8 */
/* @0x24edc4 mov r1, r7 */
/* @0x24edc8 mov r2, r6 */
/* @0x24edcc mov r3, r5 */
/* @0x24edd0 add sp, sp, #8 */
/* @0x24edd4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x24edd8 b 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x24eddc ldr r0, [pc, #0xc] */
/* @0x24ede0 add r0, pc, r0 */
/* @0x24ede4 add sp, sp, #8 */
/* @0x24ede8 pop {r4, r5, r6, r7, r8, lr} */
/* @0x24edec b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x24edf0 andseq r7, r0, r8, ror #2 */

/* ── FUNC 0x24edf4 · JS_DeleteProperty(YYObjectBase*, RValue*, char const*, bool) · size=688 · insn=172 */
/* @0x24edf4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x24edf8 mov r7, r0 */
/* @0x24edfc ldrb r0, [r2] */
/* @0x24ee00 sub sp, sp, #20 */
/* @0x24ee04 mov r9, r2 */
/* @0x24ee08 mov r8, r3 */
/* @0x24ee0c cmp r0, #0 */
/* @0x24ee10 mov r4, #0 */
/* @0x24ee14 mov r5, #0 */
/* @0x24ee18 mov r2, #0 */
/* @0x24ee1c mvn r3, #-16777216 */
/* @0x24ee20 mov r6, r1 */
/* @0x24ee24 strd r4, r5, [sp] */
/* @0x24ee28 str r2, [sp, #0x8] */
/* @0x24ee2c str r3, [sp, #0xc] */
/* @0x24ee30 beq 0x24ef1c <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x128> */
/* @0x24ee34 ldr r3, [pc, #0x258] */
/* @0x24ee38 ldr r3, [pc, r3] */
/* @0x24ee3c ldr r2, [r3] */
/* @0x24ee40 add r0, r2, r0 */
/* @0x24ee44 ldrb r3, [r0, #0x1] */
/* @0x24ee48 tst r3, #4 */
/* @0x24ee4c movne r3, r9 */
/* @0x24ee50 beq 0x24ef1c <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x128> */
/* @0x24ee54 ldrb r12, [r3, #0x1]! */
/* @0x24ee58 cmp r12, #0 */
/* @0x24ee5c add lr, r2, r12 */
/* @0x24ee60 bne 0x24ef10 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x11c> */
/* @0x24ee64 ldr r4, [r7, #0x40] */
/* @0x24ee68 mov r3, #13 */
/* @0x24ee6c ldr r1, [pc, #0x224] */
/* @0x24ee70 str r3, [r6, #0xc] */
/* @0x24ee74 add r1, pc, r1 */
/* @0x24ee78 mov r0, r4 */
/* @0x24ee7c bl 0xb6574 <strcmp@plt> */
/* @0x24ee80 cmp r0, #0 */
/* @0x24ee84 beq 0x24eea0 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0xac> */
/* @0x24ee88 ldr r1, [pc, #0x20c] */
/* @0x24ee8c mov r0, r4 */
/* @0x24ee90 add r1, pc, r1 */
/* @0x24ee94 bl 0xb6574 <strcmp@plt> */
/* @0x24ee98 cmp r0, #0 */
/* @0x24ee9c bne 0x24ef24 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x130> */
/* @0x24eea0 ldr r3, [r7, #0x4] */
/* @0x24eea4 cmp r3, #0 */
/* @0x24eea8 beq 0x24f030 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x23c> */
/* @0x24eeac add r3, r3, #16 */
/* @0x24eeb0 mov r0, r9 */
/* @0x24eeb4 ldr r4, [r3] */
/* @0x24eeb8 bl 0xb66b8 <atoi@plt> */
/* @0x24eebc subs r1, r0, #0 */
/* @0x24eec0 blt 0x24f004 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x210> */
/* @0x24eec4 ldr r3, [r4, #0x24] */
/* @0x24eec8 cmp r1, r3 */
/* @0x24eecc bhs 0x24f004 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x210> */
/* @0x24eed0 ldr r3, [r4, #0x4] */
/* @0x24eed4 cmp r3, #0 */
/* @0x24eed8 beq 0x24f064 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x270> */
/* @0x24eedc add r0, r3, r1, lsl #4 */
/* @0x24eee0 mov r3, #0 */
/* @0x24eee4 mov r2, #5 */
/* @0x24eee8 str r3, [r0] */
/* @0x24eeec str r2, [r0, #0xc] */
/* @0x24eef0 mov r2, r3 */
/* @0x24eef4 str r3, [r0, #0x4] */
/* @0x24eef8 movt r2, #0x3ff0 */
/* @0x24eefc str r3, [r0, #0x8] */
/* @0x24ef00 str r3, [r6] */
/* @0x24ef04 str r2, [r6, #0x4] */
/* @0x24ef08 add sp, sp, #20 */
/* @0x24ef0c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x24ef10 ldrb r12, [lr, #0x1] */
/* @0x24ef14 tst r12, #4 */
/* @0x24ef18 bne 0x24ee54 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x60> */
/* @0x24ef1c mov r3, #13 */
/* @0x24ef20 str r3, [r6, #0xc] */
/* @0x24ef24 mov r1, r9 */
/* @0x24ef28 mov r0, r7 */
/* @0x24ef2c bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc> */
/* @0x24ef30 cmn r0, #1 */
/* @0x24ef34 mov r4, r0 */
/* @0x24ef38 beq 0x24ef64 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x170> */
/* @0x24ef3c ldr r3, [r7, #0x4] */
/* @0x24ef40 cmp r3, #0 */
/* @0x24ef44 beq 0x24f050 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x25c> */
/* @0x24ef48 add r3, r3, r0, lsl #4 */
/* @0x24ef4c ldr r0, [r3] */
/* @0x24ef50 mov r12, sp */
/* @0x24ef54 ldr r1, [r3, #0x4] */
/* @0x24ef58 ldr r2, [r3, #0x8] */
/* @0x24ef5c ldr r3, [r3, #0xc] */
/* @0x24ef60 stm r12!, {r0, r1, r2, r3} */
/* @0x24ef64 ldr r2, [sp, #0xc] */
/* @0x24ef68 mvn r3, #-16777216 */
/* @0x24ef6c and r2, r2, r3 */
/* @0x24ef70 cmp r2, r3 */
/* @0x24ef74 beq 0x24f018 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x224> */
/* @0x24ef78 ldr r3, [sp, #0x8] */
/* @0x24ef7c tst r3, #2 */
/* @0x24ef80 beq 0x24eff0 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x1fc> */
/* @0x24ef84 ldr r5, [r7, #0x4] */
/* @0x24ef88 cmp r5, #0 */
/* @0x24ef8c beq 0x24f080 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x28c> */
/* @0x24ef90 add r5, r5, r4, lsl #4 */
/* @0x24ef94 ldr r3, [r5, #0xc] */
/* @0x24ef98 sub r3, r3, #1 */
/* @0x24ef9c bic r3, r3, #-16777216 */
/* @0x24efa0 bic r3, r3, #3 */
/* @0x24efa4 cmp r3, #0 */
/* @0x24efa8 beq 0x24f044 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x250> */
/* @0x24efac mov r3, #0 */
/* @0x24efb0 str r3, [r5] */
/* @0x24efb4 ldr r2, [r7, #0x4] */
/* @0x24efb8 mov r1, #5 */
/* @0x24efbc str r3, [r5, #0x8] */
/* @0x24efc0 cmp r2, r3 */
/* @0x24efc4 str r1, [r5, #0xc] */
/* @0x24efc8 beq 0x24f070 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x27c> */
/* @0x24efcc add r0, r2, r4, lsl #4 */
/* @0x24efd0 mvn r2, #-16777216 */
/* @0x24efd4 mov r3, #0 */
/* @0x24efd8 str r2, [r0, #0xc] */
/* @0x24efdc movt r3, #0x3ff0 */
/* @0x24efe0 mov r2, #0 */
/* @0x24efe4 stm r6, {r2, r3} */
/* @0x24efe8 add sp, sp, #20 */
/* @0x24efec pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x24eff0 cmp r8, #0 */
/* @0x24eff4 beq 0x24f004 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x210> */
/* @0x24eff8 ldr r0, [pc, #0xa0] */
/* @0x24effc add r0, pc, r0 */
/* @0x24f000 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x24f004 mov r3, #0 */
/* @0x24f008 str r3, [r6] */
/* @0x24f00c str r3, [r6, #0x4] */
/* @0x24f010 add sp, sp, #20 */
/* @0x24f014 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x24f018 mov r3, #0 */
/* @0x24f01c mov r2, r3 */
/* @0x24f020 movt r3, #0x3ff0 */
/* @0x24f024 stm r6, {r2, r3} */
/* @0x24f028 add sp, sp, #20 */
/* @0x24f02c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x24f030 mov r0, r7 */
/* @0x24f034 mov r1, #1 */
/* @0x24f038 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24f03c mov r3, r0 */
/* @0x24f040 b 0x24eeb0 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0xbc> */
/* @0x24f044 mov r0, r5 */
/* @0x24f048 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24f04c b 0x24efac <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x1b8> */
/* @0x24f050 mov r0, r7 */
/* @0x24f054 mov r1, r4 */
/* @0x24f058 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24f05c mov r3, r0 */
/* @0x24f060 b 0x24ef4c <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x158> */
/* @0x24f064 mov r0, r4 */
/* @0x24f068 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24f06c b 0x24eee0 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0xec> */
/* @0x24f070 mov r0, r7 */
/* @0x24f074 mov r1, r4 */
/* @0x24f078 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24f07c b 0x24efd0 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x1dc> */
/* @0x24f080 mov r0, r7 */
/* @0x24f084 mov r1, r4 */
/* @0x24f088 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24f08c mov r5, r0 */
/* @0x24f090 b 0x24ef94 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x1a0> */
/* @0x24f094 andseq lr, r9, r8, asr #22 */
/* @0x24f098 andeq r5, lr, r4, lsr #21 */
/* @0x24f09c ldrheq r6, [r0], -r4 */
/* @0x24f0a0 andseq r7, r0, r12, asr r0 */

/* ── FUNC 0x24f0a4 · JS_Object_Delete(YYObjectBase*, char const*, bool) · size=116 · insn=29 */
/* @0x24f0a4 push {r4, r5, lr} */
/* @0x24f0a8 sub sp, sp, #20 */
/* @0x24f0ac mov r12, r1 */
/* @0x24f0b0 mov r4, r2 */
/* @0x24f0b4 mov r1, sp */
/* @0x24f0b8 mov r2, r12 */
/* @0x24f0bc mov r12, #5 */
/* @0x24f0c0 str r12, [sp, #0xc] */
/* @0x24f0c4 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x24f0c8 ldr r1, [sp, #0xc] */
/* @0x24f0cc bic r1, r1, #-16777216 */
/* @0x24f0d0 cmp r1, #5 */
/* @0x24f0d4 beq 0x24f108 <_Z16JS_Object_DeleteP12YYObjectBasePKcb+0x64> */
/* @0x24f0d8 ldr r3, [sp, #0x8] */
/* @0x24f0dc ands r5, r3, #2 */
/* @0x24f0e0 bne 0x24f108 <_Z16JS_Object_DeleteP12YYObjectBasePKcb+0x64> */
/* @0x24f0e4 cmp r4, #0 */
/* @0x24f0e8 moveq r0, r4 */
/* @0x24f0ec beq 0x24f10c <_Z16JS_Object_DeleteP12YYObjectBasePKcb+0x68> */
/* @0x24f0f0 ldr r0, [pc, #0x1c] */
/* @0x24f0f4 add r0, pc, r0 */
/* @0x24f0f8 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x24f0fc mov r0, r5 */
/* @0x24f100 add sp, sp, #20 */
/* @0x24f104 pop {r4, r5, pc} */
/* @0x24f108 mov r0, #1 */
/* @0x24f10c add sp, sp, #20 */
/* @0x24f110 pop {r4, r5, pc} */
/* @0x24f114 andseq r6, r0, r4, asr lr */

/* ── FUNC 0x24f118 · JS_Object_Put(YYObjectBase*, RValue*, char const*, bool) · size=408 · insn=102 */
/* @0x24f118 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x24f11c mov r7, r1 */
/* @0x24f120 sub sp, sp, #32 */
/* @0x24f124 mov r1, r2 */
/* @0x24f128 mov r6, r2 */
/* @0x24f12c mov r9, r3 */
/* @0x24f130 mov r8, r0 */
/* @0x24f134 bl 0x241cac <_Z9JS_CanPutP12YYObjectBasePKc> */
/* @0x24f138 cmp r0, #0 */
/* @0x24f13c bne 0x24f150 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0x38> */
/* @0x24f140 cmp r9, #0 */
/* @0x24f144 bne 0x24f1f8 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0xe0> */
/* @0x24f148 add sp, sp, #32 */
/* @0x24f14c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x24f150 mov r0, r8 */
/* @0x24f154 mov r2, r6 */
/* @0x24f158 mov r1, sp */
/* @0x24f15c mov r12, #0 */
/* @0x24f160 mvn r3, #-16777216 */
/* @0x24f164 str r12, [sp, #0x8] */
/* @0x24f168 str r3, [sp, #0xc] */
/* @0x24f16c mov r4, #0 */
/* @0x24f170 mov r5, #0 */
/* @0x24f174 strd r4, r5, [sp] */
/* @0x24f178 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x24f17c mov r0, sp */
/* @0x24f180 bl 0x2407e8 <_Z19JS_IsDataDescriptorP6RValue> */
/* @0x24f184 cmp r0, #0 */
/* @0x24f188 beq 0x24f20c <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0xf4> */
/* @0x24f18c ldr r0, [r7] */
/* @0x24f190 add r4, sp, #16 */
/* @0x24f194 ldr r1, [r7, #0x4] */
/* @0x24f198 ldr r2, [r7, #0x8] */
/* @0x24f19c mov r12, r4 */
/* @0x24f1a0 ldr r3, [r7, #0xc] */
/* @0x24f1a4 ldr r5, [r8, #0x40] */
/* @0x24f1a8 ldr lr, [sp, #0x8] */
/* @0x24f1ac stm r12!, {r0, r1, r2, r3} */
/* @0x24f1b0 mov r0, r5 */
/* @0x24f1b4 ldr r1, [pc, #0xe8] */
/* @0x24f1b8 str lr, [sp, #0x18] */
/* @0x24f1bc add r1, pc, r1 */
/* @0x24f1c0 bl 0xb6574 <strcmp@plt> */
/* @0x24f1c4 cmp r0, #0 */
/* @0x24f1c8 beq 0x24f290 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0x178> */
/* @0x24f1cc ldr r1, [pc, #0xd4] */
/* @0x24f1d0 mov r0, r5 */
/* @0x24f1d4 add r1, pc, r1 */
/* @0x24f1d8 bl 0xb6574 <strcmp@plt> */
/* @0x24f1dc cmp r0, #0 */
/* @0x24f1e0 mov r0, r8 */
/* @0x24f1e4 bne 0x24f27c <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0x164> */
/* @0x24f1e8 mov r1, r4 */
/* @0x24f1ec mov r2, r6 */
/* @0x24f1f0 bl 0x2499cc <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc> */
/* @0x24f1f4 b 0x24f148 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0x30> */
/* @0x24f1f8 ldr r0, [pc, #0xac] */
/* @0x24f1fc add r0, pc, r0 */
/* @0x24f200 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x24f204 add sp, sp, #32 */
/* @0x24f208 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x24f20c mov r0, r8 */
/* @0x24f210 mov r1, sp */
/* @0x24f214 mov r2, r6 */
/* @0x24f218 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x24f21c mov r0, sp */
/* @0x24f220 bl 0x240828 <_Z23JS_IsAccessorDescriptorP6RValue> */
/* @0x24f224 cmp r0, #0 */
/* @0x24f228 beq 0x24f240 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0x128> */
/* @0x24f22c mov r0, r8 */
/* @0x24f230 mov r1, r7 */
/* @0x24f234 mov r2, sp */
/* @0x24f238 bl 0x24931c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_> */
/* @0x24f23c b 0x24f148 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0x30> */
/* @0x24f240 ldr r0, [r7] */
/* @0x24f244 add lr, sp, #16 */
/* @0x24f248 ldr r1, [r7, #0x4] */
/* @0x24f24c mov r4, #7 */
/* @0x24f250 ldr r2, [r7, #0x8] */
/* @0x24f254 mov r12, lr */
/* @0x24f258 ldr r3, [r7, #0xc] */
/* @0x24f25c stm r12!, {r0, r1, r2, r3} */
/* @0x24f260 mov r2, lr */
/* @0x24f264 mov r0, r8 */
/* @0x24f268 mov r1, r6 */
/* @0x24f26c mov r3, r9 */
/* @0x24f270 str r4, [sp, #0x18] */
/* @0x24f274 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb> */
/* @0x24f278 b 0x24f148 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0x30> */
/* @0x24f27c mov r1, r6 */
/* @0x24f280 mov r2, r4 */
/* @0x24f284 mov r3, r9 */
/* @0x24f288 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb> */
/* @0x24f28c b 0x24f148 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0x30> */
/* @0x24f290 mov r0, r8 */
/* @0x24f294 mov r1, r4 */
/* @0x24f298 mov r2, r6 */
/* @0x24f29c bl 0x24861c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc> */
/* @0x24f2a0 b 0x24f148 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0x30> */
/* @0x24f2a4 andeq r5, lr, r12, asr r7 */
/* @0x24f2a8 andseq r6, r0, r0, ror r12 */
/* @0x24f2ac andseq r6, r0, r12, asr #26 */

/* ── FUNC 0x24f2b0 · DoRegExpExec(YYObjectBase*, char const*, int, int*, int, int*, int) · size=520 · insn=130 */
/* @0x24f2b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24f2b4 sub sp, sp, #68 */
/* @0x24f2b8 mov r10, r1 */
/* @0x24f2bc mov r7, r2 */
/* @0x24f2c0 ldr r1, [pc, #0x1c8] */
/* @0x24f2c4 mov r8, r3 */
/* @0x24f2c8 ldr r2, [pc, #0x1c4] */
/* @0x24f2cc mov r5, r0 */
/* @0x24f2d0 ldr r6, [sp, #0x70] */
/* @0x24f2d4 add r1, pc, r1 */
/* @0x24f2d8 add r2, pc, r2 */
/* @0x24f2dc ldr r12, [sp, #0x68] */
/* @0x24f2e0 str r1, [sp, #0x18] */
/* @0x24f2e4 str r2, [sp, #0x1c] */
/* @0x24f2e8 lsr r9, r6, #31 */
/* @0x24f2ec ldr r1, [pc, #0x1a4] */
/* @0x24f2f0 mov r11, r12 */
/* @0x24f2f4 ldr r2, [pc, #0x1a0] */
/* @0x24f2f8 add r1, pc, r1 */
/* @0x24f2fc ldr r3, [pc, #0x19c] */
/* @0x24f300 add r2, pc, r2 */
/* @0x24f304 str r1, [sp, #0x24] */
/* @0x24f308 str r2, [sp, #0x28] */
/* @0x24f30c add r3, pc, r3 */
/* @0x24f310 ldr r1, [pc, #0x18c] */
/* @0x24f314 ldr r2, [pc, #0x18c] */
/* @0x24f318 str r3, [sp, #0x20] */
/* @0x24f31c add r1, pc, r1 */
/* @0x24f320 mov r3, #0 */
/* @0x24f324 add r2, pc, r2 */
/* @0x24f328 str r1, [sp, #0x2c] */
/* @0x24f32c str r2, [sp, #0x14] */
/* @0x24f330 str r3, [sp, #0x30] */
/* @0x24f334 str r3, [sp, #0x34] */
/* @0x24f338 str r3, [sp, #0x38] */
/* @0x24f33c str r3, [sp, #0x3c] */
/* @0x24f340 cmp r6, r7 */
/* @0x24f344 movle r4, r9 */
/* @0x24f348 orrgt r4, r9, #1 */
/* @0x24f34c mov r2, r10 */
/* @0x24f350 cmp r4, #0 */
/* @0x24f354 mov r3, r7 */
/* @0x24f358 bne 0x24f44c <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x19c> */
/* @0x24f35c ldr r0, [r5, #0x1c] */
/* @0x24f360 ldr r1, [r5, #0x20] */
/* @0x24f364 str r6, [sp] */
/* @0x24f368 stmib sp, {r4, r8, r11} */
/* @0x24f36c bl 0x279390 <pcre_exec> */
/* @0x24f370 cmp r0, #0 */
/* @0x24f374 blt 0x24f3c4 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x114> */
/* @0x24f378 add r8, r8, r0, lsl #3 */
/* @0x24f37c mov r11, r0 */
/* @0x24f380 mov r0, r5 */
/* @0x24f384 add r1, sp, #64 */
/* @0x24f388 ldr r5, [r8, #-0x4] */
/* @0x24f38c mov r3, #1 */
/* @0x24f390 ldr r2, [pc, #0x114] */
/* @0x24f394 str r4, [sp, #0x3c] */
/* @0x24f398 vmov s13, r5 */
/* @0x24f39c add r2, pc, r2 */
/* @0x24f3a0 vcvt.f64.s32 d7, s13 */
/* @0x24f3a4 vmov r6, r7, d7 */
/* @0x24f3a8 strd r6, r7, [r1, #-16]! */
/* @0x24f3ac bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x24f3b0 ldr r7, [sp, #0x6c] */
/* @0x24f3b4 mov r0, r5 */
/* @0x24f3b8 str r11, [r7] */
/* @0x24f3bc add sp, sp, #68 */
/* @0x24f3c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24f3c4 add r0, r0, #6 */
/* @0x24f3c8 cmp r0, #5 */
/* @0x24f3cc addls pc, pc, r0, lsl #2 */
/* @0x24f3d0 b 0x24f484 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x1d4> */
/* @0x24f3d4 b 0x24f440 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x190> */
/* @0x24f3d8 b 0x24f434 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x184> */
/* @0x24f3dc b 0x24f428 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x178> */
/* @0x24f3e0 b 0x24f41c <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x16c> */
/* @0x24f3e4 b 0x24f3f8 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x148> */
/* @0x24f3e8 b 0x24f3ec <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x13c> */
/* @0x24f3ec add r6, r6, #1 */
/* @0x24f3f0 lsr r9, r6, #31 */
/* @0x24f3f4 b 0x24f340 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x90> */
/* @0x24f3f8 ldr r3, [pc, #0xb0] */
/* @0x24f3fc ldr r1, [sp, #0x2c] */
/* @0x24f400 ldr r2, [sp, #0x14] */
/* @0x24f404 ldr r3, [r2, r3] */
/* @0x24f408 ldr r0, [r3] */
/* @0x24f40c ldr r3, [r0] */
/* @0x24f410 ldr r3, [r3, #0xc] */
/* @0x24f414 blx r3 */
/* @0x24f418 b 0x24f340 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x90> */
/* @0x24f41c ldr r3, [pc, #0x8c] */
/* @0x24f420 ldr r1, [sp, #0x28] */
/* @0x24f424 b 0x24f400 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x150> */
/* @0x24f428 ldr r3, [pc, #0x80] */
/* @0x24f42c ldr r1, [sp, #0x24] */
/* @0x24f430 b 0x24f400 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x150> */
/* @0x24f434 ldr r3, [pc, #0x74] */
/* @0x24f438 ldr r1, [sp, #0x20] */
/* @0x24f43c b 0x24f400 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x150> */
/* @0x24f440 ldr r3, [pc, #0x68] */
/* @0x24f444 ldr r1, [sp, #0x1c] */
/* @0x24f448 b 0x24f400 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x150> */
/* @0x24f44c add r1, sp, #64 */
/* @0x24f450 ldr r2, [pc, #0x5c] */
/* @0x24f454 mov r12, #0 */
/* @0x24f458 mov r0, r5 */
/* @0x24f45c mov r4, #0 */
/* @0x24f460 mov r5, #0 */
/* @0x24f464 mov r3, r12 */
/* @0x24f468 strd r4, r5, [r1, #-16]! */
/* @0x24f46c add r2, pc, r2 */
/* @0x24f470 str r12, [sp, #0x3c] */
/* @0x24f474 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x24f478 mvn r0, #0 */
/* @0x24f47c add sp, sp, #68 */
/* @0x24f480 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24f484 ldr r3, [pc, #0x24] */
/* @0x24f488 ldr r1, [sp, #0x18] */
/* @0x24f48c b 0x24f400 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x150> */
/* @0x24f490 andseq r6, r0, r4, ror #28 */
/* @0x24f494 andseq r6, r0, r4, asr #28 */
/* @0x24f498 andseq r6, r0, r8, ror #27 */
/* @0x24f49c andseq r6, r0, r4, asr #27 */
/* @0x24f4a0 ldrsheq r6, [r0], -r0 */
/* @0x24f4a4 mulseq r0, r0, sp */
/* @0x24f4a8 andseq r2, r10, r12, lsr #18 */
/* @0x24f4ac andseq r6, r0, r4, lsl #26 */
/* @0x24f4b0 .word 0xffffbac4 */
/* @0x24f4b4 andseq r6, r0, r4, lsr r12 */
