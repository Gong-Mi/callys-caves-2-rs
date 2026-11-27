/* libyoyo.so 覆盖卡组 0218
 * 函数 0x240858..0x242ebc，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x240858 · JS_IsGenericDescriptor(RValue*) · size=68 · insn=17 */
/* @0x240858 ldr r3, [r0, #0xc] */
/* @0x24085c push {r4, lr} */
/* @0x240860 bic r3, r3, #-16777216 */
/* @0x240864 cmp r3, #5 */
/* @0x240868 mov r4, r0 */
/* @0x24086c beq 0x24087c <_Z22JS_IsGenericDescriptorP6RValue+0x24> */
/* @0x240870 bl 0x2407e8 <_Z19JS_IsDataDescriptorP6RValue> */
/* @0x240874 cmp r0, #0 */
/* @0x240878 beq 0x240884 <_Z22JS_IsGenericDescriptorP6RValue+0x2c> */
/* @0x24087c mov r0, #0 */
/* @0x240880 pop {r4, pc} */
/* @0x240884 mov r0, r4 */
/* @0x240888 bl 0x240828 <_Z23JS_IsAccessorDescriptorP6RValue> */
/* @0x24088c cmp r0, #0 */
/* @0x240890 bne 0x24087c <_Z22JS_IsGenericDescriptorP6RValue+0x24> */
/* @0x240894 mov r0, #1 */
/* @0x240898 pop {r4, pc} */

/* ── FUNC 0x24089c · JS_SameValue(RValue*, RValue*) · size=212 · insn=53 */
/* @0x24089c push {r3, r4, r5, lr} */
/* @0x2408a0 ldr r2, [r1, #0xc] */
/* @0x2408a4 ldr r3, [r0, #0xc] */
/* @0x2408a8 eor r2, r3, r2 */
/* @0x2408ac bic r2, r2, #-16777216 */
/* @0x2408b0 cmp r2, #0 */
/* @0x2408b4 bne 0x2408fc <_Z12JS_SameValueP6RValueS0_+0x60> */
/* @0x2408b8 bic r3, r3, #-16777216 */
/* @0x2408bc cmp r3, #12 */
/* @0x2408c0 addls pc, pc, r3, lsl #2 */
/* @0x2408c4 b 0x2408fc <_Z12JS_SameValueP6RValueS0_+0x60> */
/* @0x2408c8 b 0x24091c <_Z12JS_SameValueP6RValueS0_+0x80> */
/* @0x2408cc b 0x240948 <_Z12JS_SameValueP6RValueS0_+0xac> */
/* @0x2408d0 b 0x2408fc <_Z12JS_SameValueP6RValueS0_+0x60> */
/* @0x2408d4 b 0x2408fc <_Z12JS_SameValueP6RValueS0_+0x60> */
/* @0x2408d8 b 0x2408fc <_Z12JS_SameValueP6RValueS0_+0x60> */
/* @0x2408dc b 0x240968 <_Z12JS_SameValueP6RValueS0_+0xcc> */
/* @0x2408e0 b 0x240904 <_Z12JS_SameValueP6RValueS0_+0x68> */
/* @0x2408e4 b 0x24091c <_Z12JS_SameValueP6RValueS0_+0x80> */
/* @0x2408e8 b 0x2408fc <_Z12JS_SameValueP6RValueS0_+0x60> */
/* @0x2408ec b 0x2408fc <_Z12JS_SameValueP6RValueS0_+0x60> */
/* @0x2408f0 b 0x24091c <_Z12JS_SameValueP6RValueS0_+0x80> */
/* @0x2408f4 b 0x2408fc <_Z12JS_SameValueP6RValueS0_+0x60> */
/* @0x2408f8 b 0x240968 <_Z12JS_SameValueP6RValueS0_+0xcc> */
/* @0x2408fc mov r0, #0 */
/* @0x240900 pop {r3, r4, r5, pc} */
/* @0x240904 ldr r0, [r0] */
/* @0x240908 ldr r3, [r1] */
/* @0x24090c subs r3, r0, r3 */
/* @0x240910 rsbs r0, r3, #0 */
/* @0x240914 adcs r0, r0, r3 */
/* @0x240918 pop {r3, r4, r5, pc} */
/* @0x24091c ldr r4, [r0] */
/* @0x240920 ldr r5, [r0, #0x4] */
/* @0x240924 ldr r2, [r1] */
/* @0x240928 ldr r3, [r1, #0x4] */
/* @0x24092c vmov d6, r4, r5 */
/* @0x240930 vmov d7, r2, r3 */
/* @0x240934 vcmp.f64 d6, d7 */
/* @0x240938 vmrs APSR_nzcv, fpscr */
/* @0x24093c movne r0, #0 */
/* @0x240940 moveq r0, #1 */
/* @0x240944 pop {r3, r4, r5, pc} */
/* @0x240948 ldr r2, [r0] */
/* @0x24094c ldr r3, [r1] */
/* @0x240950 ldr r0, [r2] */
/* @0x240954 ldr r1, [r3] */
/* @0x240958 bl 0xb6574 <strcmp@plt> */
/* @0x24095c rsbs r0, r0, #1 */
/* @0x240960 movlo r0, #0 */
/* @0x240964 pop {r3, r4, r5, pc} */
/* @0x240968 mov r0, #1 */
/* @0x24096c pop {r3, r4, r5, pc} */

/* ── FUNC 0x240970 · yyisinf(RValue&) · size=56 · insn=14 */
/* @0x240970 ldr r2, [r0] */
/* @0x240974 ldr r3, [r0, #0x4] */
/* @0x240978 push {r4, r5} */
/* @0x24097c mov r5, #0 */
/* @0x240980 movt r5, #0x7ff0 */
/* @0x240984 mov r4, #0 */
/* @0x240988 and r3, r3, r5 */
/* @0x24098c and r2, r2, r4 */
/* @0x240990 cmp r3, r5 */
/* @0x240994 cmpeq r2, r4 */
/* @0x240998 pop {r4, r5} */
/* @0x24099c movne r0, #0 */
/* @0x2409a0 moveq r0, #1 */
/* @0x2409a4 bx lr */

/* ── FUNC 0x2409a8 · IsNotCompatibleKind(int, int) · size=96 · insn=24 */
/* @0x2409a8 cmp r0, r1 */
/* @0x2409ac beq 0x240a00 <_Z19IsNotCompatibleKindii+0x58> */
/* @0x2409b0 cmp r0, #13 */
/* @0x2409b4 bhi 0x2409f0 <_Z19IsNotCompatibleKindii+0x48> */
/* @0x2409b8 mov r2, #1 */
/* @0x2409bc movw r3, #0x2481 */
/* @0x2409c0 lsl r0, r2, r0 */
/* @0x2409c4 and r3, r0, r3 */
/* @0x2409c8 cmp r3, #0 */
/* @0x2409cc beq 0x2409f8 <_Z19IsNotCompatibleKindii+0x50> */
/* @0x2409d0 cmp r1, #13 */
/* @0x2409d4 bhi 0x2409f8 <_Z19IsNotCompatibleKindii+0x50> */
/* @0x2409d8 lsl r1, r2, r1 */
/* @0x2409dc movw r0, #0x2481 */
/* @0x2409e0 and r0, r1, r0 */
/* @0x2409e4 rsbs r0, r0, #1 */
/* @0x2409e8 movlo r0, #0 */
/* @0x2409ec bx lr */
/* @0x2409f0 mov r0, #1 */
/* @0x2409f4 bx lr */
/* @0x2409f8 mov r0, r2 */
/* @0x2409fc bx lr */
/* @0x240a00 mov r0, #0 */
/* @0x240a04 bx lr */

/* ── FUNC 0x240a08 · JS_Global_abstractStrictEqualityComparison(RValue&, RValue&) · size=284 · insn=71 */
/* @0x240a08 push {r4, r5, r6, lr} */
/* @0x240a0c mov r6, r1 */
/* @0x240a10 ldr r4, [r0, #0xc] */
/* @0x240a14 mov r5, r0 */
/* @0x240a18 ldr r1, [r1, #0xc] */
/* @0x240a1c bic r4, r4, #-16777216 */
/* @0x240a20 bic r1, r1, #-16777216 */
/* @0x240a24 mov r0, r4 */
/* @0x240a28 bl 0x2409a8 <_Z19IsNotCompatibleKindii> */
/* @0x240a2c cmp r0, #0 */
/* @0x240a30 bne 0x240acc <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xc4> */
/* @0x240a34 cmp r4, #5 */
/* @0x240a38 beq 0x240ad4 <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xcc> */
/* @0x240a3c cmp r4, #12 */
/* @0x240a40 beq 0x240ad4 <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xcc> */
/* @0x240a44 cmp r4, #0 */
/* @0x240a48 beq 0x240a7c <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0x74> */
/* @0x240a4c cmp r4, #13 */
/* @0x240a50 beq 0x240afc <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xf4> */
/* @0x240a54 cmp r4, #1 */
/* @0x240a58 beq 0x240adc <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xd4> */
/* @0x240a5c cmp r4, #6 */
/* @0x240a60 bne 0x240acc <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xc4> */
/* @0x240a64 ldr r0, [r5] */
/* @0x240a68 ldr r3, [r6] */
/* @0x240a6c subs r3, r0, r3 */
/* @0x240a70 rsbs r0, r3, #0 */
/* @0x240a74 adcs r0, r0, r3 */
/* @0x240a78 pop {r4, r5, r6, pc} */
/* @0x240a7c mov r0, r6 */
/* @0x240a80 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x240a84 vldr s14, [r5] */
/* @0x240a88 vldr s15, [r5, #4] */
/* @0x240a8c vcmp.f64 d7, d7 */
/* @0x240a90 vmrs APSR_nzcv, fpscr */
/* @0x240a94 vmov d6, r0, r1 */
/* @0x240a98 bvs 0x240acc <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xc4> */
/* @0x240a9c vcmp.f64 d6, d6 */
/* @0x240aa0 vmrs APSR_nzcv, fpscr */
/* @0x240aa4 bvs 0x240acc <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xc4> */
/* @0x240aa8 vcmp.f64 d6, d7 */
/* @0x240aac vmrs APSR_nzcv, fpscr */
/* @0x240ab0 beq 0x240ad4 <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xcc> */
/* @0x240ab4 vcmp.f64 d7, #0 */
/* @0x240ab8 vmrs APSR_nzcv, fpscr */
/* @0x240abc bne 0x240acc <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xc4> */
/* @0x240ac0 vcmp.f64 d6, #0 */
/* @0x240ac4 vmrs APSR_nzcv, fpscr */
/* @0x240ac8 beq 0x240ad4 <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xcc> */
/* @0x240acc mov r0, #0 */
/* @0x240ad0 pop {r4, r5, r6, pc} */
/* @0x240ad4 mov r0, #1 */
/* @0x240ad8 pop {r4, r5, r6, pc} */
/* @0x240adc ldr r2, [r5] */
/* @0x240ae0 ldr r3, [r6] */
/* @0x240ae4 ldr r0, [r2] */
/* @0x240ae8 ldr r1, [r3] */
/* @0x240aec bl 0xb6574 <strcmp@plt> */
/* @0x240af0 rsbs r0, r0, #1 */
/* @0x240af4 movlo r0, #0 */
/* @0x240af8 pop {r4, r5, r6, pc} */
/* @0x240afc mov r0, r6 */
/* @0x240b00 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x240b04 ldm r5, {r2, r3} */
/* @0x240b08 vmov d7, r2, r3 */
/* @0x240b0c vmov d6, r0, r1 */
/* @0x240b10 vcmp.f64 d6, d7 */
/* @0x240b14 vmrs APSR_nzcv, fpscr */
/* @0x240b18 movne r0, #0 */
/* @0x240b1c moveq r0, #1 */
/* @0x240b20 pop {r4, r5, r6, pc} */

/* ── FUNC 0x240b24 · JS_Array_prototype_indexOf(RValue&, CInstance*, CInstance*, int, RValue*) · size=256 · insn=64 */
/* @0x240b24 mov r12, #0 */
/* @0x240b28 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x240b2c mov r2, r12 */
/* @0x240b30 movt r12, #0xbff0 */
/* @0x240b34 stm r0, {r2, r12} */
/* @0x240b38 ldr r12, [r1, #0x4] */
/* @0x240b3c sub sp, sp, #20 */
/* @0x240b40 mov r7, r0 */
/* @0x240b44 mov r4, r3 */
/* @0x240b48 cmp r12, r2 */
/* @0x240b4c str r2, [r0, #0xc] */
/* @0x240b50 beq 0x240c14 <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x240b54 add r0, r12, #16 */
/* @0x240b58 ldr r6, [r0] */
/* @0x240b5c ldr r8, [r6, #0x24] */
/* @0x240b60 cmp r8, #0 */
/* @0x240b64 beq 0x240c04 <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x240b68 cmp r4, #0 */
/* @0x240b6c mov r3, #5 */
/* @0x240b70 str r3, [sp, #0xc] */
/* @0x240b74 ble 0x240c0c <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x240b78 ldr r12, [sp, #0x30] */
/* @0x240b7c cmp r4, #1 */
/* @0x240b80 ldm r12, {r0, r1, r2, r3} */
/* @0x240b84 add r12, sp, #16 */
/* @0x240b88 stmdb r12, {r0, r1, r2, r3} */
/* @0x240b8c beq 0x240c0c <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x240b90 ldr r0, [sp, #0x30] */
/* @0x240b94 mov r1, #1 */
/* @0x240b98 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x240b9c mov r4, r0 */
/* @0x240ba0 cmp r8, r4 */
/* @0x240ba4 bls 0x240c04 <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x240ba8 lsl r5, r4, #4 */
/* @0x240bac b 0x240bd0 <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x240bb0 mov r0, sp */
/* @0x240bb4 add r5, r5, #16 */
/* @0x240bb8 bl 0x240a08 <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_> */
/* @0x240bbc cmp r0, #0 */
/* @0x240bc0 bne 0x240bf4 <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x240bc4 add r4, r4, #1 */
/* @0x240bc8 cmp r8, r4 */
/* @0x240bcc bls 0x240c04 <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x240bd0 ldr r1, [r6, #0x4] */
/* @0x240bd4 cmp r1, #0 */
/* @0x240bd8 add r1, r1, r5 */
/* @0x240bdc bne 0x240bb0 <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x240be0 mov r1, r4 */
/* @0x240be4 mov r0, r6 */
/* @0x240be8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x240bec mov r1, r0 */
/* @0x240bf0 b 0x240bb0 <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x240bf4 vmov s15, r4 */
/* @0x240bf8 vcvt.f64.u32 d7, s15 */
/* @0x240bfc vmov r2, r3, d7 */
/* @0x240c00 stm r7, {r2, r3} */
/* @0x240c04 add sp, sp, #20 */
/* @0x240c08 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x240c0c mov r4, #0 */
/* @0x240c10 b 0x240ba0 <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x240c14 mov r0, r1 */
/* @0x240c18 mov r1, #1 */
/* @0x240c1c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x240c20 b 0x240b58 <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x34> */

/* ── FUNC 0x240c24 · JS_Array_prototype_lastIndexOf(RValue&, CInstance*, CInstance*, int, RValue*) · size=252 · insn=63 */
/* @0x240c24 mov r12, #0 */
/* @0x240c28 push {r4, r5, r6, r7, r8, lr} */
/* @0x240c2c mov r2, r12 */
/* @0x240c30 movt r12, #0xbff0 */
/* @0x240c34 stm r0, {r2, r12} */
/* @0x240c38 ldr r12, [r1, #0x4] */
/* @0x240c3c sub sp, sp, #16 */
/* @0x240c40 mov r7, r0 */
/* @0x240c44 mov r5, r3 */
/* @0x240c48 cmp r12, r2 */
/* @0x240c4c str r2, [r0, #0xc] */
/* @0x240c50 beq 0x240d10 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x240c54 add r0, r12, #16 */
/* @0x240c58 ldr r6, [r0] */
/* @0x240c5c ldr r4, [r6, #0x24] */
/* @0x240c60 cmp r4, #0 */
/* @0x240c64 beq 0x240d00 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x240c68 cmp r5, #0 */
/* @0x240c6c mov r3, #5 */
/* @0x240c70 str r3, [sp, #0xc] */
/* @0x240c74 ble 0x240d08 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x240c78 ldr r12, [sp, #0x28] */
/* @0x240c7c cmp r5, #1 */
/* @0x240c80 ldm r12, {r0, r1, r2, r3} */
/* @0x240c84 add r12, sp, #16 */
/* @0x240c88 stmdb r12, {r0, r1, r2, r3} */
/* @0x240c8c beq 0x240d08 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x240c90 ldr r0, [sp, #0x28] */
/* @0x240c94 mov r1, #1 */
/* @0x240c98 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x240c9c mov r4, r0 */
/* @0x240ca0 cmp r4, #0 */
/* @0x240ca4 blt 0x240d00 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x240ca8 lsl r5, r4, #4 */
/* @0x240cac b 0x240ccc <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x240cb0 mov r0, sp */
/* @0x240cb4 sub r5, r5, #16 */
/* @0x240cb8 bl 0x240a08 <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_> */
/* @0x240cbc cmp r0, #0 */
/* @0x240cc0 bne 0x240cf0 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x240cc4 subs r4, r4, #1 */
/* @0x240cc8 blo 0x240d00 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x240ccc ldr r1, [r6, #0x4] */
/* @0x240cd0 cmp r1, #0 */
/* @0x240cd4 add r1, r1, r5 */
/* @0x240cd8 bne 0x240cb0 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x240cdc mov r1, r4 */
/* @0x240ce0 mov r0, r6 */
/* @0x240ce4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x240ce8 mov r1, r0 */
/* @0x240cec b 0x240cb0 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x240cf0 vmov s15, r4 */
/* @0x240cf4 vcvt.f64.s32 d7, s15 */
/* @0x240cf8 vmov r2, r3, d7 */
/* @0x240cfc stm r7, {r2, r3} */
/* @0x240d00 add sp, sp, #16 */
/* @0x240d04 pop {r4, r5, r6, r7, r8, pc} */
/* @0x240d08 sub r4, r4, #1 */
/* @0x240d0c b 0x240ca0 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x240d10 mov r0, r1 */
/* @0x240d14 mov r1, #1 */
/* @0x240d18 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x240d1c b 0x240c58 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x34> */

/* ── FUNC 0x240d20 · JS_StandardScriptRefConstructor(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x240d20 push {r3, r4, r5, lr} */
/* @0x240d24 mov r4, r0 */
/* @0x240d28 bl 0xdc3b0 <_Z14YYSetScriptRefP6RValue> */
/* @0x240d2c ldr r5, [pc, #0x5c] */
/* @0x240d30 ldr r3, [pc, #0x5c] */
/* @0x240d34 add r5, pc, r5 */
/* @0x240d38 ldr r4, [r4] */
/* @0x240d3c ldr r3, [r5, r3] */
/* @0x240d40 mov r0, r4 */
/* @0x240d44 ldr r1, [r3] */
/* @0x240d48 str r1, [r4, #0x18] */
/* @0x240d4c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x240d50 ldr r3, [pc, #0x40] */
/* @0x240d54 ldr r1, [r4, #0x28] */
/* @0x240d58 ldr r2, [pc, #0x3c] */
/* @0x240d5c orr r1, r1, #1 */
/* @0x240d60 str r1, [r4, #0x28] */
/* @0x240d64 add r2, pc, r2 */
/* @0x240d68 str r2, [r4, #0x40] */
/* @0x240d6c ldr r2, [pc, #0x2c] */
/* @0x240d70 ldr r1, [r5, r3] */
/* @0x240d74 ldr r3, [pc, #0x28] */
/* @0x240d78 str r1, [r4, #0x4c] */
/* @0x240d7c ldr r2, [r5, r2] */
/* @0x240d80 str r2, [r4, #0x50] */
/* @0x240d84 ldr r3, [r5, r3] */
/* @0x240d88 str r3, [r4, #0x54] */
/* @0x240d8c pop {r3, r4, r5, pc} */
/* @0x240d90 andseq r0, r11, r12, lsl pc */
/* @0x240d94 .word 0xffffc054 */
/* @0x240d98 .word 0xfffff8ac */
/* @0x240d9c ldrsheq r4, [r1], -r0 */
/* @0x240da0 .word 0xfffff8b0 */
/* @0x240da4 .word 0xfffff8b4 */

/* ── FUNC 0x240da8 · F_JSScriptRef(RValue&, CInstance*, CInstance*, int, RValue*) · size=468 · insn=117 */
/* @0x240da8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x240dac sub sp, sp, #8 */
/* @0x240db0 mov r7, r0 */
/* @0x240db4 mov r8, r1 */
/* @0x240db8 ldr r4, [sp, #0x28] */
/* @0x240dbc mov r1, #0 */
/* @0x240dc0 mov r10, r2 */
/* @0x240dc4 mov r9, r3 */
/* @0x240dc8 ldr r5, [pc, #0x188] */
/* @0x240dcc mov r0, r4 */
/* @0x240dd0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x240dd4 add r5, pc, r5 */
/* @0x240dd8 sub r0, r0, #99328 */
/* @0x240ddc sub r0, r0, #672 */
/* @0x240de0 bl 0x1e069c <_Z11Script_Datai> */
/* @0x240de4 subs r6, r0, #0 */
/* @0x240de8 beq 0x240f14 <_Z13F_JSScriptRefR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x240dec str r4, [sp] */
/* @0x240df0 mov r1, r8 */
/* @0x240df4 mov r2, r10 */
/* @0x240df8 mov r3, r9 */
/* @0x240dfc mov r0, r7 */
/* @0x240e00 bl 0x240d20 <_Z31JS_StandardScriptRefConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x240e04 ldr r4, [r7] */
/* @0x240e08 ldr r2, [pc, #0x14c] */
/* @0x240e0c mov r1, #0 */
/* @0x240e10 ldr r3, [pc, #0x148] */
/* @0x240e14 str r1, [r4, #0x68] */
/* @0x240e18 mov r0, r4 */
/* @0x240e1c ldr r2, [r5, r2] */
/* @0x240e20 str r2, [r4, #0x90] */
/* @0x240e24 ldr r3, [r5, r3] */
/* @0x240e28 ldr r3, [r3] */
/* @0x240e2c cmp r3, r1 */
/* @0x240e30 ldrne r2, [r3, #0xc] */
/* @0x240e34 moveq r1, r3 */
/* @0x240e38 ldrne r1, [r3, #0x10] */
/* @0x240e3c addne r2, r2, #1 */
/* @0x240e40 strne r2, [r3, #0xc] */
/* @0x240e44 mov r3, #6 */
/* @0x240e48 str r1, [r4, #0x6c] */
/* @0x240e4c str r3, [r4, #0x78] */
/* @0x240e50 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x240e54 ldr r2, [r6, #0x8] */
/* @0x240e58 ldr r1, [pc, #0x104] */
/* @0x240e5c mov r0, r4 */
/* @0x240e60 cmp r2, #0 */
/* @0x240e64 str r6, [r4, #0x64] */
/* @0x240e68 str r2, [r4, #0x8c] */
/* @0x240e6c add r1, pc, r1 */
/* @0x240e70 ldrne r2, [r2, #0x74] */
/* @0x240e74 mov r3, #0 */
/* @0x240e78 bl 0x199960 <_ZN12YYObjectBase3AddEPKcii> */
/* @0x240e7c ldr r0, [pc, #0xe4] */
/* @0x240e80 ldr r3, [pc, #0xe4] */
/* @0x240e84 mvn r1, #-16777216 */
/* @0x240e88 mov r2, #0 */
/* @0x240e8c ldr r0, [r5, r0] */
/* @0x240e90 str r0, [r4, #0x94] */
/* @0x240e94 ldr r3, [r5, r3] */
/* @0x240e98 ldr r0, [r3] */
/* @0x240e9c bl 0x19198c <_ZN12YYObjectBase5AllocEjib> */
/* @0x240ea0 ldr r1, [pc, #0xc8] */
/* @0x240ea4 ldr r2, [r7] */
/* @0x240ea8 mov r3, #6 */
/* @0x240eac add r1, pc, r1 */
/* @0x240eb0 mov r6, r0 */
/* @0x240eb4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x240eb8 ldr r3, [pc, #0xb4] */
/* @0x240ebc mov r0, r6 */
/* @0x240ec0 ldr r2, [pc, #0xb0] */
/* @0x240ec4 ldr r3, [r5, r3] */
/* @0x240ec8 add r2, pc, r2 */
/* @0x240ecc str r2, [r6, #0x40] */
/* @0x240ed0 ldr r1, [r3] */
/* @0x240ed4 str r1, [r6, #0x18] */
/* @0x240ed8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x240edc ldr r1, [r4, #0x4] */
/* @0x240ee0 cmp r1, #0 */
/* @0x240ee4 beq 0x240f1c <_Z13F_JSScriptRefR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x240ee8 str r6, [r1] */
/* @0x240eec mov r0, r4 */
/* @0x240ef0 mov r1, r6 */
/* @0x240ef4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x240ef8 ldr r1, [r4, #0x4] */
/* @0x240efc cmp r1, #0 */
/* @0x240f00 movne r3, #6 */
/* @0x240f04 strne r3, [r1, #0xc] */
/* @0x240f08 beq 0x240f2c <_Z13F_JSScriptRefR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x240f0c mov r3, #6 */
/* @0x240f10 str r3, [r1, #0x8] */
/* @0x240f14 add sp, sp, #8 */
/* @0x240f18 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x240f1c mov r0, r4 */
/* @0x240f20 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x240f24 mov r1, r0 */
/* @0x240f28 b 0x240ee8 <_Z13F_JSScriptRefR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x240f2c mov r0, r4 */
/* @0x240f30 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x240f34 ldr r1, [r4, #0x4] */
/* @0x240f38 mov r3, #6 */
/* @0x240f3c cmp r1, #0 */
/* @0x240f40 str r3, [r0, #0xc] */
/* @0x240f44 bne 0x240f0c <_Z13F_JSScriptRefR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x240f48 mov r0, r4 */
/* @0x240f4c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x240f50 mov r1, r0 */
/* @0x240f54 b 0x240f0c <_Z13F_JSScriptRefR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x240f58 andseq r0, r11, r12, ror lr */
/* @0x240f5c .word 0xfffff8cc */
/* @0x240f60 .word 0xffffbf58 */
/* @0x240f64 andeq pc, lr, r0, lsl #20 */
/* @0x240f68 .word 0xfffff8d8 */
/* @0x240f6c .word 0xffffc0c4 */
/* @0x240f70 andseq r4, r1, r8, ror r6 */
/* @0x240f74 .word 0xffffc050 */
/* @0x240f78 mulseq r1, r8, r6 */

/* ── FUNC 0x240f7c · JS_SetupFunction(void (*)(RValue&, CInstance*, CInstance*, int, RValue*), int, bool) · size=128 · insn=32 */
/* @0x240f7c push {r4, r5, r6, r7, lr} */
/* @0x240f80 sub sp, sp, #28 */
/* @0x240f84 mov r3, #0 */
/* @0x240f88 mov r6, r0 */
/* @0x240f8c mov r7, r2 */
/* @0x240f90 str r3, [sp] */
/* @0x240f94 mov r2, r3 */
/* @0x240f98 mov r5, r1 */
/* @0x240f9c add r0, sp, #8 */
/* @0x240fa0 mov r1, r3 */
/* @0x240fa4 bl 0x240d20 <_Z31JS_StandardScriptRefConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x240fa8 ldr r4, [sp, #0x8] */
/* @0x240fac ldr r3, [pc, #0x3c] */
/* @0x240fb0 cmp r7, #0 */
/* @0x240fb4 ldr r3, [pc, r3] */
/* @0x240fb8 str r6, [r4, #0x68] */
/* @0x240fbc str r3, [r4, #0x90] */
/* @0x240fc0 ldrne r3, [pc, #0x2c] */
/* @0x240fc4 ldrne r3, [pc, r3] */
/* @0x240fc8 strne r3, [r4, #0x94] */
/* @0x240fcc ldr r1, [pc, #0x24] */
/* @0x240fd0 mov r0, r4 */
/* @0x240fd4 mov r2, r5 */
/* @0x240fd8 mov r3, #0 */
/* @0x240fdc add r1, pc, r1 */
/* @0x240fe0 bl 0x199960 <_ZN12YYObjectBase3AddEPKcii> */
/* @0x240fe4 mov r0, r4 */
/* @0x240fe8 add sp, sp, #28 */
/* @0x240fec pop {r4, r5, r6, r7, pc} */
/* @0x240ff0 andseq r0, r11, r8, ror #10 */
/* @0x240ff4 andseq r0, r11, r12, asr r5 */
/* @0x240ff8 muleq lr, r0, r8 */

/* ── FUNC 0x240ffc · JS_GlobalObjectSetup() · size=1288 · insn=322 */
/* @0x240ffc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x241000 mov r3, #5 */
/* @0x241004 ldr r4, [pc, #0x468] */
/* @0x241008 mov r6, #0 */
/* @0x24100c ldr r7, [pc, #0x464] */
/* @0x241010 sub sp, sp, #28 */
/* @0x241014 ldr r1, [pc, #0x460] */
/* @0x241018 add r4, pc, r4 */
/* @0x24101c add r7, pc, r7 */
/* @0x241020 add r2, r4, #2336 */
/* @0x241024 str r3, [r4, #0x938] */
/* @0x241028 add r2, r2, #12 */
/* @0x24102c str r6, [r4, #0x934] */
/* @0x241030 mov r3, r6 */
/* @0x241034 str r6, [r4, #0x92c] */
/* @0x241038 str r6, [r4, #0x930] */
/* @0x24103c ldr r8, [r7, r1] */
/* @0x241040 ldr r1, [pc, #0x438] */
/* @0x241044 ldr r9, [pc, #0x438] */
/* @0x241048 add r1, pc, r1 */
/* @0x24104c ldr r0, [r8] */
/* @0x241050 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x241054 ldr r1, [pc, #0x42c] */
/* @0x241058 add r2, r4, #2352 */
/* @0x24105c ldr r0, [r8] */
/* @0x241060 add r2, r2, #12 */
/* @0x241064 mov r3, r6 */
/* @0x241068 add r1, pc, r1 */
/* @0x24106c mvn lr, #0 */
/* @0x241070 mvn r12, #-2147483648 */
/* @0x241074 str lr, [r4, #0x93c] */
/* @0x241078 str r12, [r4, #0x940] */
/* @0x24107c str r6, [r4, #0x948] */
/* @0x241080 str r6, [r4, #0x944] */
/* @0x241084 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x241088 ldr r1, [pc, #0x3fc] */
/* @0x24108c add r2, r4, #2368 */
/* @0x241090 ldr r0, [r8] */
/* @0x241094 add r2, r2, #12 */
/* @0x241098 mov r3, r6 */
/* @0x24109c add r1, pc, r1 */
/* @0x2410a0 str r6, [r4, #0x958] */
/* @0x2410a4 mov r12, r6 */
/* @0x2410a8 str r6, [r4, #0x954] */
/* @0x2410ac movt r12, #0x7ff0 */
/* @0x2410b0 str r6, [r4, #0x94c] */
/* @0x2410b4 str r12, [r4, #0x950] */
/* @0x2410b8 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x2410bc ldr r3, [pc, #0x3cc] */
/* @0x2410c0 mov r1, r6 */
/* @0x2410c4 mov r2, r6 */
/* @0x2410c8 ldr r4, [r8] */
/* @0x2410cc ldr r10, [pc, #0x3c0] */
/* @0x2410d0 ldr r0, [r7, r3] */
/* @0x2410d4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2410d8 ldr r1, [pc, #0x3b8] */
/* @0x2410dc mov r3, #6 */
/* @0x2410e0 add r1, pc, r1 */
/* @0x2410e4 mov r2, r0 */
/* @0x2410e8 mov r0, r4 */
/* @0x2410ec bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2410f0 ldr r3, [pc, #0x3a4] */
/* @0x2410f4 mov r1, r6 */
/* @0x2410f8 mov r2, r6 */
/* @0x2410fc ldr r4, [r8] */
/* @0x241100 ldr r0, [r7, r3] */
/* @0x241104 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x241108 ldr r1, [pc, #0x390] */
/* @0x24110c mov r3, #6 */
/* @0x241110 add r1, pc, r1 */
/* @0x241114 mov r2, r0 */
/* @0x241118 mov r0, r4 */
/* @0x24111c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x241120 ldr r3, [pc, #0x37c] */
/* @0x241124 mov r1, r6 */
/* @0x241128 mov r2, r6 */
/* @0x24112c ldr r4, [r8] */
/* @0x241130 ldr r0, [r7, r3] */
/* @0x241134 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x241138 ldr r1, [pc, #0x368] */
/* @0x24113c mov r3, #6 */
/* @0x241140 add r1, pc, r1 */
/* @0x241144 mov r2, r0 */
/* @0x241148 mov r0, r4 */
/* @0x24114c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x241150 ldr r3, [pc, #0x354] */
/* @0x241154 mov r1, r6 */
/* @0x241158 mov r2, r6 */
/* @0x24115c ldr r4, [r8] */
/* @0x241160 ldr r0, [r7, r3] */
/* @0x241164 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x241168 ldr r1, [pc, #0x340] */
/* @0x24116c mov r3, #6 */
/* @0x241170 add r1, pc, r1 */
/* @0x241174 mov r2, r0 */
/* @0x241178 mov r0, r4 */
/* @0x24117c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x241180 ldr r3, [pc, #0x32c] */
/* @0x241184 mov r1, r6 */
/* @0x241188 mov r2, r6 */
/* @0x24118c ldr r5, [r8] */
/* @0x241190 ldr r4, [r7, r3] */
/* @0x241194 mov r0, r4 */
/* @0x241198 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x24119c ldr r1, [pc, #0x314] */
/* @0x2411a0 mov r3, #6 */
/* @0x2411a4 add r1, pc, r1 */
/* @0x2411a8 mov r2, r0 */
/* @0x2411ac mov r0, r5 */
/* @0x2411b0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2411b4 mov r0, r4 */
/* @0x2411b8 mov r1, r6 */
/* @0x2411bc mov r2, r6 */
/* @0x2411c0 ldr r5, [r8] */
/* @0x2411c4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2411c8 ldr r1, [pc, #0x2ec] */
/* @0x2411cc mov r3, #6 */
/* @0x2411d0 add r1, pc, r1 */
/* @0x2411d4 mov r2, r0 */
/* @0x2411d8 mov r0, r5 */
/* @0x2411dc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2411e0 mov r0, r4 */
/* @0x2411e4 mov r1, r6 */
/* @0x2411e8 mov r2, r6 */
/* @0x2411ec ldr r5, [r8] */
/* @0x2411f0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2411f4 ldr r1, [pc, #0x2c4] */
/* @0x2411f8 mov r3, #6 */
/* @0x2411fc add r1, pc, r1 */
/* @0x241200 mov r2, r0 */
/* @0x241204 mov r0, r5 */
/* @0x241208 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x24120c mov r0, r4 */
/* @0x241210 mov r1, r6 */
/* @0x241214 mov r2, r6 */
/* @0x241218 ldr r4, [r8] */
/* @0x24121c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x241220 ldr r1, [pc, #0x29c] */
/* @0x241224 mov r3, #6 */
/* @0x241228 ldr r5, [pc, #0x298] */
/* @0x24122c add r1, pc, r1 */
/* @0x241230 add r5, pc, r5 */
/* @0x241234 mov r2, r0 */
/* @0x241238 mov r0, r4 */
/* @0x24123c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x241240 ldr r3, [pc, #0x284] */
/* @0x241244 ldr r12, [r8] */
/* @0x241248 mov r1, r6 */
/* @0x24124c mov r2, r6 */
/* @0x241250 add r0, sp, #8 */
/* @0x241254 ldr r4, [r7, r3] */
/* @0x241258 mov r3, r6 */
/* @0x24125c ldr r11, [r12, #0x28] */
/* @0x241260 mvn lr, #-16777216 */
/* @0x241264 str r5, [r12, #0x40] */
/* @0x241268 mov r5, #0 */
/* @0x24126c ldr r4, [r4] */
/* @0x241270 orr r11, r11, #1 */
/* @0x241274 str r11, [r12, #0x28] */
/* @0x241278 str r4, [r12, #0x18] */
/* @0x24127c mov r4, #0 */
/* @0x241280 ldr r11, [r7, r9] */
/* @0x241284 ldr r9, [pc, #0x244] */
/* @0x241288 str r11, [r12, #0x4c] */
/* @0x24128c ldr r10, [r7, r10] */
/* @0x241290 str r10, [r12, #0x50] */
/* @0x241294 ldr r9, [r7, r9] */
/* @0x241298 str r6, [sp, #0x10] */
/* @0x24129c strd r4, r5, [sp, #8] */
/* @0x2412a0 str r9, [r12, #0x54] */
/* @0x2412a4 str r6, [sp] */
/* @0x2412a8 str lr, [sp, #0x14] */
/* @0x2412ac bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x2412b0 ldr r1, [pc, #0x21c] */
/* @0x2412b4 ldr r3, [pc, #0x21c] */
/* @0x2412b8 ldr r2, [sp, #0x8] */
/* @0x2412bc ldr r9, [r7, r1] */
/* @0x2412c0 str r2, [r9] */
/* @0x2412c4 ldr r10, [r7, r3] */
/* @0x2412c8 ldr r3, [r10] */
/* @0x2412cc cmp r3, r6 */
/* @0x2412d0 ble 0x241320 <_Z20JS_GlobalObjectSetupv+0x324> */
/* @0x2412d4 ldr r3, [pc, #0x200] */
/* @0x2412d8 mov r5, r6 */
/* @0x2412dc ldr r11, [r7, r3] */
/* @0x2412e0 ldr r4, [r11] */
/* @0x2412e4 mov r2, #0 */
/* @0x2412e8 add r5, r5, #1 */
/* @0x2412ec add r4, r4, r6 */
/* @0x2412f0 add r6, r6, #80 */
/* @0x2412f4 ldr r1, [r4, #0x44] */
/* @0x2412f8 ldr r0, [r4, #0x40] */
/* @0x2412fc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x241300 mov r3, #1 */
/* @0x241304 mov r1, r4 */
/* @0x241308 mov r2, r0 */
/* @0x24130c ldr r0, [r9] */
/* @0x241310 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x241314 ldr r3, [r10] */
/* @0x241318 cmp r3, r5 */
/* @0x24131c bgt 0x2412e0 <_Z20JS_GlobalObjectSetupv+0x2e4> */
/* @0x241320 ldr r3, [pc, #0x1b8] */
/* @0x241324 ldr r6, [r7, r3] */
/* @0x241328 ldr r3, [r6] */
/* @0x24132c cmp r3, #0 */
/* @0x241330 ble 0x2413a8 <_Z20JS_GlobalObjectSetupv+0x3ac> */
/* @0x241334 ldr r3, [pc, #0x1a8] */
/* @0x241338 mov r4, #0 */
/* @0x24133c ldr r11, [pc, #0x1a4] */
/* @0x241340 ldr r10, [r7, r3] */
/* @0x241344 add r11, pc, r11 */
/* @0x241348 b 0x24135c <_Z20JS_GlobalObjectSetupv+0x360> */
/* @0x24134c ldr r3, [r6] */
/* @0x241350 add r4, r4, #1 */
/* @0x241354 cmp r3, r4 */
/* @0x241358 ble 0x2413a8 <_Z20JS_GlobalObjectSetupv+0x3ac> */
/* @0x24135c ldr r3, [r10] */
/* @0x241360 mov r1, r11 */
/* @0x241364 ldr r5, [r3, r4, lsl #2] */
/* @0x241368 mov r0, r5 */
/* @0x24136c bl 0xb6574 <strcmp@plt> */
/* @0x241370 cmp r0, #0 */
/* @0x241374 beq 0x24134c <_Z20JS_GlobalObjectSetupv+0x350> */
/* @0x241378 ldr r2, [pc, #0x16c] */
/* @0x24137c mov r3, #1 */
/* @0x241380 mov r1, r5 */
/* @0x241384 ldr r0, [r9] */
/* @0x241388 ldr r2, [r7, r2] */
/* @0x24138c ldr r2, [r2] */
/* @0x241390 add r2, r2, r4, lsl #4 */
/* @0x241394 add r4, r4, #1 */
/* @0x241398 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x24139c ldr r3, [r6] */
/* @0x2413a0 cmp r3, r4 */
/* @0x2413a4 bgt 0x24135c <_Z20JS_GlobalObjectSetupv+0x360> */
/* @0x2413a8 ldr r3, [pc, #0x140] */
/* @0x2413ac ldr r6, [r7, r3] */
/* @0x2413b0 ldr r3, [r6] */
/* @0x2413b4 cmp r3, #0 */
/* @0x2413b8 ble 0x241420 <_Z20JS_GlobalObjectSetupv+0x424> */
/* @0x2413bc ldr r3, [pc, #0x130] */
/* @0x2413c0 mov r5, #0 */
/* @0x2413c4 ldr r4, [r7, r3] */
/* @0x2413c8 add r4, r4, #8 */
/* @0x2413cc b 0x2413e0 <_Z20JS_GlobalObjectSetupv+0x3e4> */
/* @0x2413d0 ldr r3, [r6] */
/* @0x2413d4 add r4, r4, #16 */
/* @0x2413d8 cmp r3, r5 */
/* @0x2413dc ble 0x241420 <_Z20JS_GlobalObjectSetupv+0x424> */
/* @0x2413e0 ldr r0, [r4, #-0x8] */
/* @0x2413e4 add r5, r5, #1 */
/* @0x2413e8 bl 0x23f8f0 <_Z18isGlobalBuiltinVarPKc> */
/* @0x2413ec cmp r0, #0 */
/* @0x2413f0 beq 0x2413d0 <_Z20JS_GlobalObjectSetupv+0x3d4> */
/* @0x2413f4 ldmda r4, {r0, r1} */
/* @0x2413f8 add r4, r4, #16 */
/* @0x2413fc bl 0x23ffac <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_> */
/* @0x241400 ldr r1, [r4, #-0x18] */
/* @0x241404 mov r3, #1 */
/* @0x241408 mov r2, r0 */
/* @0x24140c ldr r0, [r9] */
/* @0x241410 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x241414 ldr r3, [r6] */
/* @0x241418 cmp r3, r5 */
/* @0x24141c bgt 0x2413e0 <_Z20JS_GlobalObjectSetupv+0x3e4> */
/* @0x241420 ldr r1, [pc, #0xd0] */
/* @0x241424 mov r3, #1 */
/* @0x241428 ldr r0, [r8] */
/* @0x24142c ldr r2, [r9] */
/* @0x241430 add r1, pc, r1 */
/* @0x241434 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x241438 ldr r0, [r8] */
/* @0x24143c ldr r1, [pc, #0xb8] */
/* @0x241440 mov r3, #1 */
/* @0x241444 mov r2, r0 */
/* @0x241448 add r1, pc, r1 */
/* @0x24144c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x241450 ldr r1, [pc, #0xa8] */
/* @0x241454 ldr r3, [r9] */
/* @0x241458 mov r2, #0 */
/* @0x24145c ldr r1, [r7, r1] */
/* @0x241460 ldr r1, [r1] */
/* @0x241464 str r3, [r1, #0xc] */
/* @0x241468 str r2, [r3, #0xc] */
/* @0x24146c add sp, sp, #28 */
/* @0x241470 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x241474 subseq r4, r1, r8, lsl #21 */
/* @0x241478 andseq r0, r11, r4, lsr r12 */
/* @0x24147c .word 0xffffbf64 */
/* @0x241480 andeq r1, pc, r8, lsl r2 */
/* @0x241484 .word 0xfffff8ac */
/* @0x241488 andeq r1, pc, r12, lsl #9 */
/* @0x24148c andseq r4, r1, r0, asr r3 */
/* @0x241490 .word 0xfffff8dc */
/* @0x241494 .word 0xfffff8b0 */
/* @0x241498 mulseq r1, r4, r4 */
/* @0x24149c .word 0xfffff8e0 */
/* @0x2414a0 andseq r4, r1, r12, ror #8 */
/* @0x2414a4 .word 0xfffff8e4 */
/* @0x2414a8 andseq r4, r1, r8, asr #8 */
/* @0x2414ac .word 0xfffff8e8 */
/* @0x2414b0 andseq r4, r1, r4, lsr #8 */
/* @0x2414b4 .word 0xfffff8ec */
/* @0x2414b8 ldrsheq r4, [r1], -r12 */
/* @0x2414bc ldrsbeq r4, [r1], -r12 */
/* @0x2414c0 andseq r4, r1, r4, asr #7 */
/* @0x2414c4 andseq r4, r1, r0, lsr #7 */
/* @0x2414c8 andseq r4, r1, r4, lsr #3 */
/* @0x2414cc .word 0xffffc050 */
/* @0x2414d0 .word 0xfffff8b4 */
/* @0x2414d4 .word 0xfffff8f0 */
/* @0x2414d8 .word 0xffffbec4 */
/* @0x2414dc .word 0xffffbec8 */
/* @0x2414e0 .word 0xffffc174 */
/* @0x2414e4 .word 0xffffc178 */
/* @0x2414e8 muleq pc, r4, r11 */
/* @0x2414ec .word 0xffffc17c */
/* @0x2414f0 .word 0xffffbfe4 */
/* @0x2414f4 .word 0xffffbfe8 */
/* @0x2414f8 ldrheq r4, [r1], -r0 */
/* @0x2414fc muleq pc, r0, r10 */
/* @0x241500 .word 0xffffc058 */

/* ── FUNC 0x241504 · JS_SetupProperty(void (*)(RValue&, CInstance*, CInstance*, int, RValue*), void (*)(RValue&, CInstance*, CInstance*, int, RValue*)) · size=312 · insn=78 */
/* @0x241504 push {r3, r4, r5, r6, r7, lr} */
/* @0x241508 mov r2, #0 */
/* @0x24150c mov r7, r0 */
/* @0x241510 mov r6, r1 */
/* @0x241514 mov r0, #2 */
/* @0x241518 mvn r1, #-16777216 */
/* @0x24151c bl 0x19198c <_ZN12YYObjectBase5AllocEjib> */
/* @0x241520 mov r3, #2 */
/* @0x241524 ldr r5, [r0, #0x4] */
/* @0x241528 mov r4, r0 */
/* @0x24152c str r3, [r0, #0x48] */
/* @0x241530 cmp r5, #0 */
/* @0x241534 beq 0x2415dc <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0xd8> */
/* @0x241538 mov r1, #0 */
/* @0x24153c mov r0, r7 */
/* @0x241540 mov r2, r1 */
/* @0x241544 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x241548 str r0, [r5] */
/* @0x24154c ldr r1, [r4, #0x4] */
/* @0x241550 cmp r1, #0 */
/* @0x241554 beq 0x2415ec <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0xe8> */
/* @0x241558 ldr r1, [r1] */
/* @0x24155c mov r0, r4 */
/* @0x241560 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x241564 ldr r1, [r4, #0x4] */
/* @0x241568 cmp r1, #0 */
/* @0x24156c movne r2, #11 */
/* @0x241570 strne r2, [r1, #0xc] */
/* @0x241574 beq 0x2415fc <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0xf8> */
/* @0x241578 add r5, r1, #16 */
/* @0x24157c mov r1, #0 */
/* @0x241580 mov r0, r6 */
/* @0x241584 mov r2, r1 */
/* @0x241588 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x24158c str r0, [r5] */
/* @0x241590 ldr r0, [r4, #0x4] */
/* @0x241594 cmp r0, #0 */
/* @0x241598 beq 0x24162c <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0x128> */
/* @0x24159c add r0, r0, #16 */
/* @0x2415a0 ldr r1, [r0] */
/* @0x2415a4 mov r0, r4 */
/* @0x2415a8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x2415ac ldr r0, [r4, #0x4] */
/* @0x2415b0 cmp r0, #0 */
/* @0x2415b4 beq 0x2415cc <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0xc8> */
/* @0x2415b8 add r0, r0, #16 */
/* @0x2415bc mov r3, #11 */
/* @0x2415c0 str r3, [r0, #0xc] */
/* @0x2415c4 mov r0, r4 */
/* @0x2415c8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2415cc mov r0, r4 */
/* @0x2415d0 mov r1, #1 */
/* @0x2415d4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2415d8 b 0x2415bc <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0xb8> */
/* @0x2415dc mov r1, r5 */
/* @0x2415e0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2415e4 mov r5, r0 */
/* @0x2415e8 b 0x241538 <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0x34> */
/* @0x2415ec mov r0, r4 */
/* @0x2415f0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2415f4 mov r1, r0 */
/* @0x2415f8 b 0x241558 <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0x54> */
/* @0x2415fc mov r0, r4 */
/* @0x241600 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x241604 ldr r1, [r4, #0x4] */
/* @0x241608 mov r2, #11 */
/* @0x24160c cmp r1, #0 */
/* @0x241610 str r2, [r0, #0xc] */
/* @0x241614 bne 0x241578 <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0x74> */
/* @0x241618 mov r0, r4 */
/* @0x24161c mov r1, #1 */
/* @0x241620 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x241624 mov r5, r0 */
/* @0x241628 b 0x24157c <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0x78> */
/* @0x24162c mov r0, r4 */
/* @0x241630 mov r1, #1 */
/* @0x241634 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x241638 b 0x2415a0 <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0x9c> */

/* ── FUNC 0x24163c · JS_FunctionSetup() · size=596 · insn=149 */
/* @0x24163c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x241640 sub sp, sp, #28 */
/* @0x241644 mov r4, #0 */
/* @0x241648 add r0, sp, #8 */
/* @0x24164c mov r1, r4 */
/* @0x241650 mov r2, r4 */
/* @0x241654 mov r3, r4 */
/* @0x241658 str r4, [sp] */
/* @0x24165c ldr r6, [pc, #0x1e8] */
/* @0x241660 str r4, [sp, #0x8] */
/* @0x241664 str r4, [sp, #0xc] */
/* @0x241668 add r6, pc, r6 */
/* @0x24166c str r4, [sp, #0x10] */
/* @0x241670 str r4, [sp, #0x14] */
/* @0x241674 bl 0x240d20 <_Z31JS_StandardScriptRefConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x241678 ldr r3, [pc, #0x1d0] */
/* @0x24167c mov r1, r4 */
/* @0x241680 ldr r5, [sp, #0x8] */
/* @0x241684 mov r2, r4 */
/* @0x241688 ldr r12, [pc, #0x1c4] */
/* @0x24168c ldr r8, [r6, r3] */
/* @0x241690 ldr r3, [pc, #0x1c0] */
/* @0x241694 add r12, pc, r12 */
/* @0x241698 ldr r0, [r5, #0x28] */
/* @0x24169c str r12, [r5, #0x40] */
/* @0x2416a0 str r5, [r8] */
/* @0x2416a4 orr r0, r0, #1 */
/* @0x2416a8 str r0, [r5, #0x28] */
/* @0x2416ac ldr r0, [r6, r3] */
/* @0x2416b0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2416b4 ldr r1, [pc, #0x1a0] */
/* @0x2416b8 mov r3, #6 */
/* @0x2416bc add r1, pc, r1 */
/* @0x2416c0 mov r2, r0 */
/* @0x2416c4 mov r0, r5 */
/* @0x2416c8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2416cc ldr r3, [pc, #0x18c] */
/* @0x2416d0 mov r2, r4 */
/* @0x2416d4 mov r1, #1 */
/* @0x2416d8 ldr r0, [r6, r3] */
/* @0x2416dc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2416e0 ldr r1, [pc, #0x17c] */
/* @0x2416e4 mov r3, #6 */
/* @0x2416e8 add r1, pc, r1 */
/* @0x2416ec mov r2, r0 */
/* @0x2416f0 mov r0, r5 */
/* @0x2416f4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2416f8 ldr r3, [pc, #0x168] */
/* @0x2416fc mov r2, r4 */
/* @0x241700 mov r1, #1 */
/* @0x241704 ldr r0, [r6, r3] */
/* @0x241708 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x24170c ldr r1, [pc, #0x158] */
/* @0x241710 mov r3, #6 */
/* @0x241714 add r1, pc, r1 */
/* @0x241718 mov r2, r0 */
/* @0x24171c mov r0, r5 */
/* @0x241720 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x241724 ldr r3, [pc, #0x144] */
/* @0x241728 mov r2, r4 */
/* @0x24172c mov r1, #1 */
/* @0x241730 ldr r0, [r6, r3] */
/* @0x241734 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x241738 ldr r1, [pc, #0x134] */
/* @0x24173c mov r3, #6 */
/* @0x241740 add r1, pc, r1 */
/* @0x241744 mov r2, r0 */
/* @0x241748 mov r0, r5 */
/* @0x24174c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x241750 ldr r12, [pc, #0x120] */
/* @0x241754 ldr r1, [pc, #0x120] */
/* @0x241758 mov r0, r5 */
/* @0x24175c mov r2, r4 */
/* @0x241760 mov r3, r4 */
/* @0x241764 ldr r12, [r6, r12] */
/* @0x241768 add r1, pc, r1 */
/* @0x24176c str r12, [r5, #0x68] */
/* @0x241770 bl 0x199960 <_ZN12YYObjectBase3AddEPKcii> */
/* @0x241774 ldr r3, [pc, #0x104] */
/* @0x241778 mov r1, r4 */
/* @0x24177c mov r2, r4 */
/* @0x241780 ldr r9, [r6, r3] */
/* @0x241784 mov r0, r9 */
/* @0x241788 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x24178c ldr r1, [pc, #0xf0] */
/* @0x241790 mov r3, r4 */
/* @0x241794 add r1, pc, r1 */
/* @0x241798 mov r7, r0 */
/* @0x24179c str r9, [r0, #0x94] */
/* @0x2417a0 mov r2, r7 */
/* @0x2417a4 mov r0, r5 */
/* @0x2417a8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2417ac ldr r3, [r7, #0x4] */
/* @0x2417b0 cmp r3, r4 */
/* @0x2417b4 beq 0x24180c <_Z16JS_FunctionSetupv+0x1d0> */
/* @0x2417b8 ldr r1, [r8] */
/* @0x2417bc mov r0, r7 */
/* @0x2417c0 str r1, [r3] */
/* @0x2417c4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x2417c8 ldr r1, [r7, #0x4] */
/* @0x2417cc cmp r1, #0 */
/* @0x2417d0 movne r3, #6 */
/* @0x2417d4 strne r3, [r1, #0xc] */
/* @0x2417d8 beq 0x241820 <_Z16JS_FunctionSetupv+0x1e4> */
/* @0x2417dc ldr r0, [pc, #0xa4] */
/* @0x2417e0 mov r3, #6 */
/* @0x2417e4 str r3, [r1, #0x8] */
/* @0x2417e8 mov r2, r7 */
/* @0x2417ec ldr r1, [pc, #0x98] */
/* @0x2417f0 mov r3, #0 */
/* @0x2417f4 ldr r0, [r6, r0] */
/* @0x2417f8 add r1, pc, r1 */
/* @0x2417fc ldr r0, [r0] */
/* @0x241800 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x241804 add sp, sp, #28 */
/* @0x241808 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x24180c mov r1, r3 */
/* @0x241810 mov r0, r7 */
/* @0x241814 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x241818 mov r3, r0 */
/* @0x24181c b 0x2417b8 <_Z16JS_FunctionSetupv+0x17c> */
/* @0x241820 mov r0, r7 */
/* @0x241824 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x241828 ldr r1, [r7, #0x4] */
/* @0x24182c mov r3, #6 */
/* @0x241830 cmp r1, #0 */
/* @0x241834 str r3, [r0, #0xc] */
/* @0x241838 bne 0x2417dc <_Z16JS_FunctionSetupv+0x1a0> */
/* @0x24183c mov r0, r7 */
/* @0x241840 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x241844 mov r1, r0 */
/* @0x241848 b 0x2417dc <_Z16JS_FunctionSetupv+0x1a0> */
/* @0x24184c andseq r0, r11, r8, ror #11 */
/* @0x241850 .word 0xffffc054 */
/* @0x241854 andseq r3, r1, r0, asr pc */
/* @0x241858 .word 0xfffff8f4 */
/* @0x24185c andeq r0, pc, r4, asr lr */
/* @0x241860 .word 0xfffff8f8 */
/* @0x241864 andseq r3, r1, r12, lsl #30 */
/* @0x241868 .word 0xfffff8fc */
/* @0x24186c andseq r3, r1, r8, ror #29 */
/* @0x241870 .word 0xfffff900 */
/* @0x241874 andseq r3, r1, r4, asr #29 */
/* @0x241878 .word 0xfffff904 */
/* @0x24187c andeq pc, lr, r4, lsl #2 */
/* @0x241880 .word 0xfffff908 */
/* @0x241884 mulseq r1, r0, sp */
/* @0x241888 .word 0xffffbf64 */
/* @0x24188c andseq r3, r1, r12, asr sp */

/* ── FUNC 0x241890 · JS_GetOwnProperty(YYObjectBase*, RValue*, char const*) · size=76 · insn=19 */
/* @0x241890 ldr r12, [r0, #0x4c] */
/* @0x241894 push {r3, lr} */
/* @0x241898 cmp r12, #0 */
/* @0x24189c bne 0x2418c8 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x38> */
/* @0x2418a0 ldr r3, [r0, #0x18] */
/* @0x2418a4 cmp r3, #0 */
/* @0x2418a8 bne 0x2418bc <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x2c> */
/* @0x2418ac b 0x2418d0 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x40> */
/* @0x2418b0 ldr r3, [r3, #0x18] */
/* @0x2418b4 cmp r3, #0 */
/* @0x2418b8 beq 0x2418d0 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x40> */
/* @0x2418bc ldr r12, [r3, #0x4c] */
/* @0x2418c0 cmp r12, #0 */
/* @0x2418c4 beq 0x2418b0 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x20> */
/* @0x2418c8 blx r12 */
/* @0x2418cc pop {r3, pc} */
/* @0x2418d0 mvn r3, #-16777216 */
/* @0x2418d4 str r3, [r1, #0xc] */
/* @0x2418d8 pop {r3, pc} */

/* ── FUNC 0x2418dc · JS_GetProperty(YYObjectBase*, RValue*, char const*) · size=72 · insn=18 */
/* @0x2418dc push {r3, r4, r5, r6, r7, lr} */
/* @0x2418e0 mov r4, r0 */
/* @0x2418e4 mov r5, r1 */
/* @0x2418e8 mov r7, r2 */
/* @0x2418ec mvn r6, #-16777216 */
/* @0x2418f0 mov r0, r4 */
/* @0x2418f4 mov r1, r5 */
/* @0x2418f8 mov r2, r7 */
/* @0x2418fc bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x241900 ldr r3, [r5, #0xc] */
/* @0x241904 bic r3, r3, #-16777216 */
/* @0x241908 cmp r3, r6 */
/* @0x24190c popne {r3, r4, r5, r6, r7, pc} */
/* @0x241910 ldr r4, [r4, #0x18] */
/* @0x241914 cmp r4, #0 */
/* @0x241918 bne 0x2418f0 <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc+0x14> */
/* @0x24191c str r6, [r5, #0xc] */
/* @0x241920 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x241924 · JS_HasProperty(YYObjectBase*, char const*) · size=56 · insn=14 */
/* @0x241924 str lr, [sp, #-0x4]! */
/* @0x241928 sub sp, sp, #20 */
/* @0x24192c mov r2, r1 */
/* @0x241930 mov r3, #5 */
/* @0x241934 mov r1, sp */
/* @0x241938 str r3, [sp, #0xc] */
/* @0x24193c bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x241940 ldr r0, [sp, #0xc] */
/* @0x241944 mvn r3, #-16777216 */
/* @0x241948 and r0, r0, r3 */
/* @0x24194c subs r0, r0, r3 */
/* @0x241950 movne r0, #1 */
/* @0x241954 add sp, sp, #20 */
/* @0x241958 ldr pc, [sp], #4 */

/* ── FUNC 0x24195c · F_JS_ToPropertyDescriptor(RValue*, RValue*) · size=848 · insn=212 */
/* @0x24195c ldr r3, [r1, #0xc] */
/* @0x241960 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x241964 bic r3, r3, #-16777216 */
/* @0x241968 cmp r3, #6 */
/* @0x24196c sub sp, sp, #20 */
/* @0x241970 mov r6, r0 */
/* @0x241974 beq 0x241984 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x28> */
/* @0x241978 mov r0, #1 */
/* @0x24197c add sp, sp, #20 */
/* @0x241980 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x241984 ldr r9, [pc, #0x308] */
/* @0x241988 mov r8, #0 */
/* @0x24198c ldr r7, [r1] */
/* @0x241990 mov r3, #5 */
/* @0x241994 add r9, pc, r9 */
/* @0x241998 str r8, [r0, #0x8] */
/* @0x24199c str r8, [r6, #0x4] */
/* @0x2419a0 mov r5, #0 */
/* @0x2419a4 mov r0, r7 */
/* @0x2419a8 mov r1, r9 */
/* @0x2419ac str r8, [r6] */
/* @0x2419b0 mov r4, #0 */
/* @0x2419b4 str r3, [r6, #0xc] */
/* @0x2419b8 strd r4, r5, [sp] */
/* @0x2419bc str r8, [sp, #0x8] */
/* @0x2419c0 str r3, [sp, #0xc] */
/* @0x2419c4 bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc> */
/* @0x2419c8 cmp r0, #0 */
/* @0x2419cc moveq r5, r0 */
/* @0x2419d0 bne 0x241c0c <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x2b0> */
/* @0x2419d4 ldr r4, [pc, #0x2bc] */
/* @0x2419d8 mov r0, r7 */
/* @0x2419dc add r4, pc, r4 */
/* @0x2419e0 mov r1, r4 */
/* @0x2419e4 bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc> */
/* @0x2419e8 cmp r0, #0 */
/* @0x2419ec bne 0x241be0 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x284> */
/* @0x2419f0 ldr r4, [pc, #0x2a4] */
/* @0x2419f4 mov r0, r7 */
/* @0x2419f8 add r4, pc, r4 */
/* @0x2419fc mov r1, r4 */
/* @0x241a00 bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc> */
/* @0x241a04 cmp r0, #0 */
/* @0x241a08 bne 0x241bb4 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x258> */
/* @0x241a0c ldr r4, [pc, #0x28c] */
/* @0x241a10 mov r0, r7 */
/* @0x241a14 add r4, pc, r4 */
/* @0x241a18 mov r1, r4 */
/* @0x241a1c bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc> */
/* @0x241a20 cmp r0, #0 */
/* @0x241a24 bne 0x241b80 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x224> */
/* @0x241a28 ldr r4, [pc, #0x274] */
/* @0x241a2c mov r0, r7 */
/* @0x241a30 add r4, pc, r4 */
/* @0x241a34 mov r1, r4 */
/* @0x241a38 bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc> */
/* @0x241a3c cmp r0, #0 */
/* @0x241a40 beq 0x241ad8 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x17c> */
/* @0x241a44 mov r2, r4 */
/* @0x241a48 mov r0, r7 */
/* @0x241a4c mov r1, sp */
/* @0x241a50 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x241a54 mov r0, sp */
/* @0x241a58 bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0x241a5c cmp r0, #0 */
/* @0x241a60 bne 0x241a74 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x118> */
/* @0x241a64 ldr r3, [sp, #0xc] */
/* @0x241a68 bic r3, r3, #-16777216 */
/* @0x241a6c cmp r3, #5 */
/* @0x241a70 bne 0x241978 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x1c> */
/* @0x241a74 cmp r5, #0 */
/* @0x241a78 bne 0x241978 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x1c> */
/* @0x241a7c mov r2, r5 */
/* @0x241a80 mov r0, #2 */
/* @0x241a84 mvn r1, #-16777216 */
/* @0x241a88 bl 0x19198c <_ZN12YYObjectBase5AllocEjib> */
/* @0x241a8c mov r3, #2 */
/* @0x241a90 mov r2, #6 */
/* @0x241a94 str r3, [r0, #0x48] */
/* @0x241a98 mov r4, r0 */
/* @0x241a9c str r0, [r6] */
/* @0x241aa0 ldr r3, [r0, #0x4] */
/* @0x241aa4 str r2, [r6, #0xc] */
/* @0x241aa8 cmp r3, #0 */
/* @0x241aac beq 0x241c28 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x2cc> */
/* @0x241ab0 ldr r2, [sp] */
/* @0x241ab4 mov r0, r4 */
/* @0x241ab8 str r2, [r3] */
/* @0x241abc ldr r1, [sp] */
/* @0x241ac0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x241ac4 ldr r1, [r4, #0x4] */
/* @0x241ac8 cmp r1, #0 */
/* @0x241acc beq 0x241c38 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x2dc> */
/* @0x241ad0 mov r3, #11 */
/* @0x241ad4 str r3, [r1, #0xc] */
/* @0x241ad8 ldr r4, [pc, #0x1c8] */
/* @0x241adc mov r0, r7 */
/* @0x241ae0 add r4, pc, r4 */
/* @0x241ae4 mov r1, r4 */
/* @0x241ae8 bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc> */
/* @0x241aec cmp r0, #0 */
/* @0x241af0 beq 0x24197c <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x20> */
/* @0x241af4 mov r0, r7 */
/* @0x241af8 mov r2, r4 */
/* @0x241afc mov r1, sp */
/* @0x241b00 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x241b04 mov r0, sp */
/* @0x241b08 bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0x241b0c cmp r0, #0 */
/* @0x241b10 bne 0x241b24 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x1c8> */
/* @0x241b14 ldr r3, [sp, #0xc] */
/* @0x241b18 bic r3, r3, #-16777216 */
/* @0x241b1c cmp r3, #5 */
/* @0x241b20 bne 0x241978 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x1c> */
/* @0x241b24 cmp r5, #0 */
/* @0x241b28 bne 0x241978 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x1c> */
/* @0x241b2c ldr r3, [r6] */
/* @0x241b30 cmp r3, #0 */
/* @0x241b34 beq 0x241c68 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x30c> */
/* @0x241b38 ldr r2, [r3, #0x4] */
/* @0x241b3c cmp r2, #0 */
/* @0x241b40 beq 0x241c58 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x2fc> */
/* @0x241b44 add r0, r2, #16 */
/* @0x241b48 ldr r3, [sp] */
/* @0x241b4c str r3, [r0] */
/* @0x241b50 ldr r1, [sp] */
/* @0x241b54 ldr r0, [r6] */
/* @0x241b58 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x241b5c ldr r0, [r6] */
/* @0x241b60 ldr r3, [r0, #0x4] */
/* @0x241b64 cmp r3, #0 */
/* @0x241b68 beq 0x241c48 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x2ec> */
/* @0x241b6c add r3, r3, #16 */
/* @0x241b70 mov r2, #11 */
/* @0x241b74 mov r0, #0 */
/* @0x241b78 str r2, [r3, #0xc] */
/* @0x241b7c b 0x24197c <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x20> */
/* @0x241b80 mov r2, r4 */
/* @0x241b84 mov r0, r7 */
/* @0x241b88 mov r1, sp */
/* @0x241b8c bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x241b90 mov r0, sp */
/* @0x241b94 bl 0x2404bc <_Z12JS_ToBooleanR6RValue> */
/* @0x241b98 cmp r0, #0 */
/* @0x241b9c ldrne r3, [r6, #0x8] */
/* @0x241ba0 movne r5, #1 */
/* @0x241ba4 moveq r5, #1 */
/* @0x241ba8 orrne r3, r3, #4 */
/* @0x241bac strne r3, [r6, #0x8] */
/* @0x241bb0 b 0x241a28 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0xcc> */
/* @0x241bb4 mov r2, r4 */
/* @0x241bb8 mov r0, r7 */
/* @0x241bbc mov r1, sp */
/* @0x241bc0 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x241bc4 mov r0, sp */
/* @0x241bc8 bl 0x2404bc <_Z12JS_ToBooleanR6RValue> */
/* @0x241bcc cmp r0, #0 */
/* @0x241bd0 ldrne r3, [r6, #0x8] */
/* @0x241bd4 orrne r3, r3, #2 */
/* @0x241bd8 strne r3, [r6, #0x8] */
/* @0x241bdc b 0x241a0c <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0xb0> */
/* @0x241be0 mov r2, r4 */
/* @0x241be4 mov r0, r7 */
/* @0x241be8 mov r1, sp */
/* @0x241bec bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x241bf0 mov r0, sp */
/* @0x241bf4 bl 0x2404bc <_Z12JS_ToBooleanR6RValue> */
/* @0x241bf8 cmp r0, #0 */
/* @0x241bfc ldrne r3, [r6, #0x8] */
/* @0x241c00 orrne r3, r3, #1 */
/* @0x241c04 strne r3, [r6, #0x8] */
/* @0x241c08 b 0x2419f0 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x94> */
/* @0x241c0c mov r2, r9 */
/* @0x241c10 mov r0, r7 */
/* @0x241c14 mov r1, r6 */
/* @0x241c18 mov r5, #1 */
/* @0x241c1c bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x241c20 str r8, [r6, #0x8] */
/* @0x241c24 b 0x2419d4 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x78> */
/* @0x241c28 mov r1, r5 */
/* @0x241c2c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x241c30 mov r3, r0 */
/* @0x241c34 b 0x241ab0 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x154> */
/* @0x241c38 mov r0, r4 */
/* @0x241c3c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x241c40 mov r1, r0 */
/* @0x241c44 b 0x241ad0 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x174> */
/* @0x241c48 mov r1, #1 */
/* @0x241c4c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x241c50 mov r3, r0 */
/* @0x241c54 b 0x241b70 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x214> */
/* @0x241c58 mov r0, r3 */
/* @0x241c5c mov r1, #1 */
/* @0x241c60 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x241c64 b 0x241b48 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x1ec> */
/* @0x241c68 mov r2, r5 */
/* @0x241c6c mvn r1, #-16777216 */
/* @0x241c70 mov r0, #2 */
/* @0x241c74 bl 0x19198c <_ZN12YYObjectBase5AllocEjib> */
/* @0x241c78 mov r1, #2 */
/* @0x241c7c mov r2, #6 */
/* @0x241c80 str r1, [r0, #0x48] */
/* @0x241c84 mov r3, r0 */
/* @0x241c88 str r0, [r6] */
/* @0x241c8c str r2, [r6, #0xc] */
/* @0x241c90 b 0x241b38 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x1dc> */
/* @0x241c94 andeq r5, pc, r12, asr #11 */
/* @0x241c98 andseq r3, r1, r0, lsr r12 */
/* @0x241c9c andseq r3, r1, r0, lsr #24 */
/* @0x241ca0 andseq r3, r1, r4, lsl r12 */
/* @0x241ca4 andseq r3, r1, r4, lsl #24 */
/* @0x241ca8 andseq r3, r1, r8, asr r11 */

/* ── FUNC 0x241cac · JS_CanPut(YYObjectBase*, char const*) · size=276 · insn=69 */
/* @0x241cac push {r4, r5, r6, lr} */
/* @0x241cb0 sub sp, sp, #32 */
/* @0x241cb4 mov r2, r1 */
/* @0x241cb8 mov r4, r1 */
/* @0x241cbc mov r1, sp */
/* @0x241cc0 mov r3, #5 */
/* @0x241cc4 mov r5, r0 */
/* @0x241cc8 str r3, [sp, #0xc] */
/* @0x241ccc bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x241cd0 ldr r3, [sp, #0xc] */
/* @0x241cd4 bic r3, r3, #-16777216 */
/* @0x241cd8 cmp r3, #5 */
/* @0x241cdc beq 0x241d30 <_Z9JS_CanPutP12YYObjectBasePKc+0x84> */
/* @0x241ce0 mvn r2, #-16777216 */
/* @0x241ce4 cmp r3, r2 */
/* @0x241ce8 beq 0x241d30 <_Z9JS_CanPutP12YYObjectBasePKc+0x84> */
/* @0x241cec mov r0, sp */
/* @0x241cf0 bl 0x240828 <_Z23JS_IsAccessorDescriptorP6RValue> */
/* @0x241cf4 cmp r0, #0 */
/* @0x241cf8 beq 0x241da4 <_Z9JS_CanPutP12YYObjectBasePKc+0xf8> */
/* @0x241cfc ldr r0, [sp] */
/* @0x241d00 ldr r3, [r0, #0x4] */
/* @0x241d04 cmp r3, #0 */
/* @0x241d08 beq 0x241db4 <_Z9JS_CanPutP12YYObjectBasePKc+0x108> */
/* @0x241d0c add r0, r3, #16 */
/* @0x241d10 ldr r0, [r0, #0xc] */
/* @0x241d14 mvn r3, #-16777216 */
/* @0x241d18 cmp r0, r3 */
/* @0x241d1c cmpne r0, #5 */
/* @0x241d20 moveq r0, #0 */
/* @0x241d24 movne r0, #1 */
/* @0x241d28 add sp, sp, #32 */
/* @0x241d2c pop {r4, r5, r6, pc} */
/* @0x241d30 ldr r3, [r5, #0x18] */
/* @0x241d34 cmp r3, #0 */
/* @0x241d38 beq 0x241d94 <_Z9JS_CanPutP12YYObjectBasePKc+0xe8> */
/* @0x241d3c add r6, sp, #16 */
/* @0x241d40 mov r2, r4 */
/* @0x241d44 mov r0, r5 */
/* @0x241d48 mov r3, #5 */
/* @0x241d4c mov r1, r6 */
/* @0x241d50 str r3, [sp, #0x1c] */
/* @0x241d54 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x241d58 ldr r3, [sp, #0x1c] */
/* @0x241d5c bic r3, r3, #-16777216 */
/* @0x241d60 cmp r3, #5 */
/* @0x241d64 beq 0x241d94 <_Z9JS_CanPutP12YYObjectBasePKc+0xe8> */
/* @0x241d68 mvn r2, #-16777216 */
/* @0x241d6c cmp r3, r2 */
/* @0x241d70 beq 0x241d94 <_Z9JS_CanPutP12YYObjectBasePKc+0xe8> */
/* @0x241d74 mov r0, r6 */
/* @0x241d78 bl 0x240828 <_Z23JS_IsAccessorDescriptorP6RValue> */
/* @0x241d7c cmp r0, #0 */
/* @0x241d80 bne 0x241d94 <_Z9JS_CanPutP12YYObjectBasePKc+0xe8> */
/* @0x241d84 ldr r0, [sp, #0x18] */
/* @0x241d88 ubfx r0, r0, #0x2, #0x1 */
/* @0x241d8c add sp, sp, #32 */
/* @0x241d90 pop {r4, r5, r6, pc} */
/* @0x241d94 mov r0, r5 */
/* @0x241d98 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv> */
/* @0x241d9c add sp, sp, #32 */
/* @0x241da0 pop {r4, r5, r6, pc} */
/* @0x241da4 ldr r0, [sp, #0x8] */
/* @0x241da8 ubfx r0, r0, #0x2, #0x1 */
/* @0x241dac add sp, sp, #32 */
/* @0x241db0 pop {r4, r5, r6, pc} */
/* @0x241db4 mov r1, #1 */
/* @0x241db8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x241dbc b 0x241d10 <_Z9JS_CanPutP12YYObjectBasePKc+0x64> */

/* ── FUNC 0x241dc0 · F_JS_IsPrimitive(RValue&) · size=52 · insn=13 */
/* @0x241dc0 ldr r3, [r0, #0xc] */
/* @0x241dc4 bic r3, r3, #-16777216 */
/* @0x241dc8 cmp r3, #13 */
/* @0x241dcc bhi 0x241dec <_Z16F_JS_IsPrimitiveR6RValue+0x2c> */
/* @0x241dd0 mov r2, #1 */
/* @0x241dd4 movw r0, #0x34a3 */
/* @0x241dd8 lsl r3, r2, r3 */
/* @0x241ddc and r0, r3, r0 */
/* @0x241de0 adds r0, r0, #0 */
/* @0x241de4 movne r0, #1 */
/* @0x241de8 bx lr */
/* @0x241dec mov r0, #0 */
/* @0x241df0 bx lr */

/* ── FUNC 0x241df4 · JS_ObjectSetup() · size=1456 · insn=364 */
/* @0x241df4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x241df8 sub sp, sp, #20 */
/* @0x241dfc ldr r4, [pc, #0x4cc] */
/* @0x241e00 mov r6, #6 */
/* @0x241e04 mov r0, sp */
/* @0x241e08 bl 0xdc37c <_Z13YYSetInstanceP6RValue> */
/* @0x241e0c ldr r3, [pc, #0x4c0] */
/* @0x241e10 add r4, pc, r4 */
/* @0x241e14 mov r1, #0 */
/* @0x241e18 mov r2, r1 */
/* @0x241e1c mov r5, r1 */
/* @0x241e20 ldr r0, [r4, r3] */
/* @0x241e24 ldr r8, [sp] */
/* @0x241e28 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x241e2c ldr r12, [pc, #0x4a4] */
/* @0x241e30 mov r3, r6 */
/* @0x241e34 ldr lr, [pc, #0x4a0] */
/* @0x241e38 ldr r1, [r8, #0x28] */
/* @0x241e3c add r12, pc, r12 */
/* @0x241e40 add lr, pc, lr */
/* @0x241e44 str r5, [r8, #0x18] */
/* @0x241e48 orr r1, r1, #1 */
/* @0x241e4c str r1, [r8, #0x28] */
/* @0x241e50 ldr r1, [pc, #0x488] */
/* @0x241e54 str lr, [r8, #0x40] */
/* @0x241e58 add r1, pc, r1 */
/* @0x241e5c str r6, [r12, #0x968] */
/* @0x241e60 mov r7, r0 */
/* @0x241e64 mov r0, r8 */
/* @0x241e68 mov r2, r7 */
/* @0x241e6c str r7, [r12, #0x95c] */
/* @0x241e70 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x241e74 ldr r3, [pc, #0x468] */
/* @0x241e78 mov r1, r5 */
/* @0x241e7c mov r2, r5 */
/* @0x241e80 ldr r0, [r4, r3] */
/* @0x241e84 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x241e88 ldr r1, [pc, #0x458] */
/* @0x241e8c mov r3, r6 */
/* @0x241e90 add r1, pc, r1 */
/* @0x241e94 mov r2, r0 */
/* @0x241e98 mov r0, r8 */
/* @0x241e9c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x241ea0 ldr r3, [pc, #0x444] */
/* @0x241ea4 mov r1, r5 */
/* @0x241ea8 mov r2, r5 */
/* @0x241eac ldr r0, [r4, r3] */
/* @0x241eb0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x241eb4 ldr r1, [pc, #0x434] */
/* @0x241eb8 mov r3, r6 */
/* @0x241ebc add r1, pc, r1 */
/* @0x241ec0 mov r2, r0 */
/* @0x241ec4 mov r0, r8 */
/* @0x241ec8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x241ecc ldr r3, [pc, #0x420] */
/* @0x241ed0 mov r1, r5 */
/* @0x241ed4 mov r2, r5 */
/* @0x241ed8 ldr r0, [r4, r3] */
/* @0x241edc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x241ee0 ldr r1, [pc, #0x410] */
/* @0x241ee4 mov r3, r6 */
/* @0x241ee8 add r1, pc, r1 */
/* @0x241eec mov r2, r0 */
/* @0x241ef0 mov r0, r8 */
/* @0x241ef4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x241ef8 ldr r3, [pc, #0x3fc] */
/* @0x241efc mov r1, r5 */
/* @0x241f00 mov r2, r5 */
/* @0x241f04 ldr r0, [r4, r3] */
/* @0x241f08 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x241f0c ldr r1, [pc, #0x3ec] */
/* @0x241f10 mov r3, r6 */
/* @0x241f14 add r1, pc, r1 */
/* @0x241f18 mov r2, r0 */
/* @0x241f1c mov r0, r8 */
/* @0x241f20 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x241f24 ldr r3, [pc, #0x3d8] */
/* @0x241f28 mov r1, r5 */
/* @0x241f2c mov r2, r5 */
/* @0x241f30 ldr r0, [r4, r3] */
/* @0x241f34 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x241f38 ldr r1, [pc, #0x3c8] */
/* @0x241f3c mov r3, r6 */
/* @0x241f40 add r1, pc, r1 */
/* @0x241f44 mov r2, r0 */
/* @0x241f48 mov r0, r8 */
/* @0x241f4c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x241f50 ldr r3, [pc, #0x3b4] */
/* @0x241f54 mov r1, r5 */
/* @0x241f58 mov r2, r5 */
/* @0x241f5c ldr r0, [r4, r3] */
/* @0x241f60 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x241f64 ldr r1, [pc, #0x3a4] */
/* @0x241f68 mov r3, r6 */
/* @0x241f6c add r1, pc, r1 */
/* @0x241f70 mov r2, r0 */
/* @0x241f74 mov r0, r8 */
/* @0x241f78 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x241f7c ldr r3, [pc, #0x390] */
/* @0x241f80 ldr r12, [pc, #0x390] */
/* @0x241f84 mov r1, r8 */
/* @0x241f88 ldr r0, [pc, #0x38c] */
/* @0x241f8c ldr lr, [r4, r3] */
/* @0x241f90 ldr r2, [pc, #0x388] */
/* @0x241f94 ldr r3, [pc, #0x388] */
/* @0x241f98 str lr, [r8, #0x4c] */
/* @0x241f9c ldr r12, [r4, r12] */
/* @0x241fa0 str r12, [r8, #0x50] */
/* @0x241fa4 ldr r0, [r4, r0] */
/* @0x241fa8 str r0, [r8, #0x54] */
/* @0x241fac ldr r9, [r4, r2] */
/* @0x241fb0 str r8, [r9] */
/* @0x241fb4 ldr r3, [r4, r3] */
/* @0x241fb8 ldr r0, [r3] */
/* @0x241fbc str r8, [r0, #0x18] */
/* @0x241fc0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x241fc4 ldr r1, [pc, #0x35c] */
/* @0x241fc8 mov r0, r7 */
/* @0x241fcc mov r3, r5 */
/* @0x241fd0 add r1, pc, r1 */
/* @0x241fd4 mov r2, #1 */
/* @0x241fd8 bl 0x199960 <_ZN12YYObjectBase3AddEPKcii> */
/* @0x241fdc ldr r3, [pc, #0x348] */
/* @0x241fe0 mov r2, r5 */
/* @0x241fe4 mov r1, #1 */
/* @0x241fe8 ldr r0, [r4, r3] */
/* @0x241fec bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x241ff0 ldr r1, [pc, #0x338] */
/* @0x241ff4 mov r3, r6 */
/* @0x241ff8 add r1, pc, r1 */
/* @0x241ffc mov r2, r0 */
/* @0x242000 mov r0, r7 */
/* @0x242004 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242008 ldr r3, [pc, #0x324] */
/* @0x24200c mov r2, r5 */
/* @0x242010 mov r1, #2 */
/* @0x242014 ldr r0, [r4, r3] */
/* @0x242018 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x24201c ldr r1, [pc, #0x314] */
/* @0x242020 mov r3, r6 */
/* @0x242024 add r1, pc, r1 */
/* @0x242028 mov r2, r0 */
/* @0x24202c mov r0, r7 */
/* @0x242030 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242034 ldr r3, [pc, #0x300] */
/* @0x242038 mov r2, r5 */
/* @0x24203c mov r1, #1 */
/* @0x242040 ldr r0, [r4, r3] */
/* @0x242044 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x242048 ldr r1, [pc, #0x2f0] */
/* @0x24204c mov r3, r6 */
/* @0x242050 add r1, pc, r1 */
/* @0x242054 mov r2, r0 */
/* @0x242058 mov r0, r7 */
/* @0x24205c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242060 ldr r3, [pc, #0x2dc] */
/* @0x242064 mov r2, r5 */
/* @0x242068 mov r1, #2 */
/* @0x24206c ldr r0, [r4, r3] */
/* @0x242070 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x242074 ldr r1, [pc, #0x2cc] */
/* @0x242078 mov r3, r6 */
/* @0x24207c add r1, pc, r1 */
/* @0x242080 mov r2, r0 */
/* @0x242084 mov r0, r7 */
/* @0x242088 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x24208c ldr r3, [pc, #0x2b8] */
/* @0x242090 mov r2, r5 */
/* @0x242094 mov r1, #3 */
/* @0x242098 ldr r0, [r4, r3] */
/* @0x24209c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2420a0 ldr r1, [pc, #0x2a8] */
/* @0x2420a4 mov r3, r6 */
/* @0x2420a8 add r1, pc, r1 */
/* @0x2420ac mov r2, r0 */
/* @0x2420b0 mov r0, r7 */
/* @0x2420b4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2420b8 ldr r3, [pc, #0x294] */
/* @0x2420bc mov r2, r5 */
/* @0x2420c0 mov r1, #2 */
/* @0x2420c4 ldr r0, [r4, r3] */
/* @0x2420c8 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2420cc ldr r1, [pc, #0x284] */
/* @0x2420d0 mov r3, r6 */
/* @0x2420d4 add r1, pc, r1 */
/* @0x2420d8 mov r2, r0 */
/* @0x2420dc mov r0, r7 */
/* @0x2420e0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2420e4 ldr r3, [pc, #0x270] */
/* @0x2420e8 mov r2, r5 */
/* @0x2420ec mov r1, #1 */
/* @0x2420f0 ldr r0, [r4, r3] */
/* @0x2420f4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2420f8 ldr r1, [pc, #0x260] */
/* @0x2420fc mov r3, r6 */
/* @0x242100 add r1, pc, r1 */
/* @0x242104 mov r2, r0 */
/* @0x242108 mov r0, r7 */
/* @0x24210c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242110 ldr r3, [pc, #0x24c] */
/* @0x242114 mov r2, r5 */
/* @0x242118 mov r1, #1 */
/* @0x24211c ldr r0, [r4, r3] */
/* @0x242120 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x242124 ldr r1, [pc, #0x23c] */
/* @0x242128 mov r3, r6 */
/* @0x24212c add r1, pc, r1 */
/* @0x242130 mov r2, r0 */
/* @0x242134 mov r0, r7 */
/* @0x242138 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x24213c ldr r3, [pc, #0x228] */
/* @0x242140 mov r2, r5 */
/* @0x242144 mov r1, #1 */
/* @0x242148 ldr r0, [r4, r3] */
/* @0x24214c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x242150 ldr r1, [pc, #0x218] */
/* @0x242154 mov r3, r6 */
/* @0x242158 add r1, pc, r1 */
/* @0x24215c mov r2, r0 */
/* @0x242160 mov r0, r7 */
/* @0x242164 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242168 ldr r3, [pc, #0x204] */
/* @0x24216c mov r2, r5 */
/* @0x242170 mov r1, #1 */
/* @0x242174 ldr r0, [r4, r3] */
/* @0x242178 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x24217c ldr r1, [pc, #0x1f4] */
/* @0x242180 mov r3, r6 */
/* @0x242184 add r1, pc, r1 */
/* @0x242188 mov r2, r0 */
/* @0x24218c mov r0, r7 */
/* @0x242190 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242194 ldr r3, [pc, #0x1e0] */
/* @0x242198 mov r2, r5 */
/* @0x24219c mov r1, #1 */
/* @0x2421a0 ldr r0, [r4, r3] */
/* @0x2421a4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2421a8 ldr r1, [pc, #0x1d0] */
/* @0x2421ac mov r3, r6 */
/* @0x2421b0 add r1, pc, r1 */
/* @0x2421b4 mov r2, r0 */
/* @0x2421b8 mov r0, r7 */
/* @0x2421bc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2421c0 ldr r3, [pc, #0x1bc] */
/* @0x2421c4 mov r2, r5 */
/* @0x2421c8 mov r1, #1 */
/* @0x2421cc ldr r0, [r4, r3] */
/* @0x2421d0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2421d4 ldr r1, [pc, #0x1ac] */
/* @0x2421d8 mov r3, r6 */
/* @0x2421dc add r1, pc, r1 */
/* @0x2421e0 mov r2, r0 */
/* @0x2421e4 mov r0, r7 */
/* @0x2421e8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2421ec ldr r3, [pc, #0x198] */
/* @0x2421f0 mov r2, r5 */
/* @0x2421f4 mov r1, #1 */
/* @0x2421f8 ldr r0, [r4, r3] */
/* @0x2421fc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x242200 ldr r1, [pc, #0x188] */
/* @0x242204 mov r3, r6 */
/* @0x242208 add r1, pc, r1 */
/* @0x24220c mov r2, r0 */
/* @0x242210 mov r0, r7 */
/* @0x242214 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242218 ldr r2, [pc, #0x174] */
/* @0x24221c ldr r3, [r7, #0x4] */
/* @0x242220 ldr r2, [r4, r2] */
/* @0x242224 cmp r3, r5 */
/* @0x242228 str r2, [r7, #0x94] */
/* @0x24222c beq 0x242290 <_Z14JS_ObjectSetupv+0x49c> */
/* @0x242230 ldr r1, [r9] */
/* @0x242234 mov r0, r7 */
/* @0x242238 str r1, [r3] */
/* @0x24223c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x242240 ldr r1, [r7, #0x4] */
/* @0x242244 cmp r1, #0 */
/* @0x242248 movne r3, #6 */
/* @0x24224c strne r3, [r1, #0xc] */
/* @0x242250 beq 0x2422a4 <_Z14JS_ObjectSetupv+0x4b0> */
/* @0x242254 ldr r0, [pc, #0x13c] */
/* @0x242258 mov r12, #6 */
/* @0x24225c ldr r2, [pc, #0x138] */
/* @0x242260 mov r3, #0 */
/* @0x242264 str r12, [r1, #0x8] */
/* @0x242268 ldr r0, [r4, r0] */
/* @0x24226c add r2, pc, r2 */
/* @0x242270 ldr r1, [pc, #0x128] */
/* @0x242274 add r2, r2, #2384 */
/* @0x242278 add r2, r2, #12 */
/* @0x24227c add r1, pc, r1 */
/* @0x242280 ldr r0, [r0] */
/* @0x242284 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x242288 add sp, sp, #20 */
/* @0x24228c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x242290 mov r1, r3 */
/* @0x242294 mov r0, r7 */
/* @0x242298 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24229c mov r3, r0 */
/* @0x2422a0 b 0x242230 <_Z14JS_ObjectSetupv+0x43c> */
/* @0x2422a4 mov r0, r7 */
/* @0x2422a8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2422ac ldr r1, [r7, #0x4] */
/* @0x2422b0 mov r3, #6 */
/* @0x2422b4 cmp r1, #0 */
/* @0x2422b8 str r3, [r0, #0xc] */
/* @0x2422bc bne 0x242254 <_Z14JS_ObjectSetupv+0x460> */
/* @0x2422c0 mov r0, r7 */
/* @0x2422c4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2422c8 mov r1, r0 */
/* @0x2422cc b 0x242254 <_Z14JS_ObjectSetupv+0x460> */
/* @0x2422d0 andseq pc, r10, r0, asr #28 */
/* @0x2422d4 .word 0xfffff90c */
/* @0x2422d8 subseq r3, r1, r4, ror #24 */
/* @0x2422dc ldrsheq r3, [r1], -r12 */
/* @0x2422e0 andseq r3, r1, r12, asr #13 */
/* @0x2422e4 .word 0xfffff910 */
/* @0x2422e8 andeq r0, pc, r0, lsl #13 */
/* @0x2422ec .word 0xfffff914 */
/* @0x2422f0 andseq r3, r1, r12, lsl #15 */
/* @0x2422f4 .word 0xfffff918 */
/* @0x2422f8 andseq r3, r1, r0, ror r7 */
/* @0x2422fc .word 0xfffff91c */
/* @0x242300 andseq r3, r1, r12, asr #14 */
/* @0x242304 .word 0xfffff920 */
/* @0x242308 andseq r3, r1, r0, lsr r7 */
/* @0x24230c .word 0xfffff924 */
/* @0x242310 andseq r3, r1, r4, lsl r7 */
/* @0x242314 .word 0xfffff8ac */
/* @0x242318 .word 0xfffff8b0 */
/* @0x24231c .word 0xfffff8b4 */
/* @0x242320 .word 0xffffc050 */
/* @0x242324 .word 0xffffc054 */
/* @0x242328 muleq lr, r12, r8 */
/* @0x24232c .word 0xfffff928 */
/* @0x242330 andseq r3, r1, r0, lsr #13 */
/* @0x242334 .word 0xfffff92c */
/* @0x242338 andseq r3, r1, r4, lsl #13 */
/* @0x24233c .word 0xfffff930 */
/* @0x242340 andseq r3, r1, r4, ror r6 */
/* @0x242344 .word 0xfffff934 */
/* @0x242348 andseq r3, r1, r12, asr r6 */
/* @0x24234c .word 0xfffff938 */
/* @0x242350 andseq r3, r1, r8, lsr r6 */
/* @0x242354 .word 0xfffff93c */
/* @0x242358 andseq r3, r1, r12, lsl r6 */
/* @0x24235c .word 0xfffff940 */
/* @0x242360 andseq r3, r1, r4, lsl #12 */
/* @0x242364 .word 0xfffff944 */
/* @0x242368 andseq r3, r1, r0, ror #11 */
/* @0x24236c .word 0xfffff948 */
/* @0x242370 ldrheq r3, [r1], -r12 */
/* @0x242374 .word 0xfffff94c */
/* @0x242378 andseq r3, r1, r4, lsr #11 */
/* @0x24237c .word 0xfffff950 */
/* @0x242380 andseq r3, r1, r4, lsl #11 */
/* @0x242384 .word 0xfffff954 */
/* @0x242388 andseq r3, r1, r4, ror #10 */
/* @0x24238c .word 0xfffff958 */
/* @0x242390 andseq r3, r1, r8, asr #10 */
/* @0x242394 .word 0xfffff95c */
/* @0x242398 .word 0xffffbf64 */
/* @0x24239c subseq r3, r1, r4, lsr r8 */
/* @0x2423a0 andseq r3, r1, r8, asr r1 */

/* ── FUNC 0x2423a4 · JS_CheckObjectCoercible(RValue&) · size=52 · insn=13 */
/* @0x2423a4 ldr r3, [r0, #0xc] */
/* @0x2423a8 bic r3, r3, #-16777216 */
/* @0x2423ac cmp r3, #10 */
/* @0x2423b0 bhi 0x2423d0 <_Z23JS_CheckObjectCoercibleR6RValue+0x2c> */
/* @0x2423b4 mov r2, #1 */
/* @0x2423b8 movw r0, #0x4c3 */
/* @0x2423bc lsl r3, r2, r3 */
/* @0x2423c0 and r0, r3, r0 */
/* @0x2423c4 rsbs r0, r0, #1 */
/* @0x2423c8 movlo r0, #0 */
/* @0x2423cc bx lr */
/* @0x2423d0 mov r0, #1 */
/* @0x2423d4 bx lr */

/* ── FUNC 0x2423d8 · CCodepointIterator_UTF8::CCodepointIterator_UTF8(char const*) · size=36 · insn=9 */
/* @0x2423d8 push {r4, lr} */
/* @0x2423dc mov r4, r0 */
/* @0x2423e0 str r1, [r4] */
/* @0x2423e4 mov r0, r1 */
/* @0x2423e8 str r1, [r4, #0x4] */
/* @0x2423ec bl 0xb6538 <strlen@plt> */
/* @0x2423f0 str r0, [r4, #0x8] */
/* @0x2423f4 mov r0, r4 */
/* @0x2423f8 pop {r4, pc} */

/* ── FUNC 0x2423d8 · CCodepointIterator_UTF8::CCodepointIterator_UTF8(char const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2423fc · CCodepointIterator_UTF8::Reset() · size=12 · insn=3 */
/* @0x2423fc ldr r3, [r0] */
/* @0x242400 str r3, [r0, #0x4] */
/* @0x242404 bx lr */

/* ── FUNC 0x242408 · CCodepointIterator_UTF8::GetNext() · size=188 · insn=47 */
/* @0x242408 ldr r3, [r0, #0x4] */
/* @0x24240c mov r2, r0 */
/* @0x242410 str r4, [sp, #-0x4]! */
/* @0x242414 ldrb r0, [r3] */
/* @0x242418 tst r0, #128 */
/* @0x24241c addeq r3, r3, #1 */
/* @0x242420 streq r3, [r2, #0x4] */
/* @0x242424 beq 0x242460 <_ZN23CCodepointIterator_UTF87GetNextEv+0x58> */
/* @0x242428 tst r0, #16 */
/* @0x24242c bne 0x242468 <_ZN23CCodepointIterator_UTF87GetNextEv+0x60> */
/* @0x242430 tst r0, #32 */
/* @0x242434 beq 0x2424a4 <_ZN23CCodepointIterator_UTF87GetNextEv+0x9c> */
/* @0x242438 ldrb r12, [r3, #0x1] */
/* @0x24243c lsl r0, r0, #12 */
/* @0x242440 ldrb r1, [r3, #0x2] */
/* @0x242444 add r3, r3, #3 */
/* @0x242448 and r12, r12, #63 */
/* @0x24244c uxth r0, r0 */
/* @0x242450 and r1, r1, #63 */
/* @0x242454 str r3, [r2, #0x4] */
/* @0x242458 add r0, r0, r12, lsl #6 */
/* @0x24245c add r0, r0, r1 */
/* @0x242460 ldr r4, [sp], #4 */
/* @0x242464 bx lr */
/* @0x242468 ldrb r12, [r3, #0x1] */
/* @0x24246c and r0, r0, #7 */
/* @0x242470 ldrb r1, [r3, #0x2] */
/* @0x242474 add r4, r3, #4 */
/* @0x242478 and r12, r12, #63 */
/* @0x24247c ldrb r3, [r3, #0x3] */
/* @0x242480 and r1, r1, #63 */
/* @0x242484 str r4, [r2, #0x4] */
/* @0x242488 lsl r2, r12, #12 */
/* @0x24248c and r3, r3, #63 */
/* @0x242490 add r0, r2, r0, lsl #18 */
/* @0x242494 ldr r4, [sp], #4 */
/* @0x242498 add r0, r0, r1, lsl #6 */
/* @0x24249c add r0, r0, r3 */
/* @0x2424a0 bx lr */
/* @0x2424a4 ldrb r1, [r3, #0x1] */
/* @0x2424a8 and r0, r0, #31 */
/* @0x2424ac add r3, r3, #2 */
/* @0x2424b0 str r3, [r2, #0x4] */
/* @0x2424b4 and r3, r1, #63 */
/* @0x2424b8 ldr r4, [sp], #4 */
/* @0x2424bc add r0, r3, r0, lsl #6 */
/* @0x2424c0 bx lr */

/* ── FUNC 0x2424c4 · CodepointToUTF16(int, unsigned short&, unsigned short&) · size=48 · insn=12 */
/* @0x2424c4 cmp r0, #65536 */
/* @0x2424c8 strhlt r0, [r1] */
/* @0x2424cc subge r3, r0, #65536 */
/* @0x2424d0 ubfxge r12, r3, #0xa, #0xa */
/* @0x2424d4 ubfxge r3, r3, #0x0, #0xa */
/* @0x2424d8 movlt r0, #1 */
/* @0x2424dc subge r12, r12, #10240 */
/* @0x2424e0 subge r3, r3, #9216 */
/* @0x2424e4 strhge r12, [r1] */
/* @0x2424e8 movge r0, #2 */
/* @0x2424ec strhge r3, [r2] */
/* @0x2424f0 bx lr */

/* ── FUNC 0x2424f4 · UTF8_get_U16_at_pos(RValue&, int) · size=184 · insn=46 */
/* @0x2424f4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2424f8 sub sp, sp, #20 */
/* @0x2424fc ldr r3, [r0] */
/* @0x242500 add r6, sp, #4 */
/* @0x242504 mov r5, r1 */
/* @0x242508 add r7, sp, #2 */
/* @0x24250c mov r0, r6 */
/* @0x242510 mov r4, #0 */
/* @0x242514 ldr r1, [r3] */
/* @0x242518 bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc> */
/* @0x24251c b 0x242524 <_Z19UTF8_get_U16_at_posR6RValuei+0x30> */
/* @0x242520 add r4, r4, r0 */
/* @0x242524 mov r0, r6 */
/* @0x242528 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x24252c mov r1, sp */
/* @0x242530 mov r2, r7 */
/* @0x242534 subs r9, r0, #0 */
/* @0x242538 beq 0x242588 <_Z19UTF8_get_U16_at_posR6RValuei+0x94> */
/* @0x24253c bl 0x2424c4 <_Z16CodepointToUTF16iRtS_> */
/* @0x242540 subs r1, r4, r5 */
/* @0x242544 rsbs r12, r1, #0 */
/* @0x242548 adcs r12, r12, r1 */
/* @0x24254c cmp r0, #1 */
/* @0x242550 cmpeq r4, r5 */
/* @0x242554 beq 0x242594 <_Z19UTF8_get_U16_at_posR6RValuei+0xa0> */
/* @0x242558 subs r2, r0, #2 */
/* @0x24255c rsbs r3, r2, #0 */
/* @0x242560 adcs r3, r3, r2 */
/* @0x242564 tst r3, r12 */
/* @0x242568 bne 0x2425a0 <_Z19UTF8_get_U16_at_posR6RValuei+0xac> */
/* @0x24256c cmp r3, #0 */
/* @0x242570 beq 0x242520 <_Z19UTF8_get_U16_at_posR6RValuei+0x2c> */
/* @0x242574 add r3, r4, #1 */
/* @0x242578 cmp r3, r5 */
/* @0x24257c bne 0x242520 <_Z19UTF8_get_U16_at_posR6RValuei+0x2c> */
/* @0x242580 ldrh r0, [sp, #2] */
/* @0x242584 b 0x24258c <_Z19UTF8_get_U16_at_posR6RValuei+0x98> */
/* @0x242588 mov r0, r9 */
/* @0x24258c add sp, sp, #20 */
/* @0x242590 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x242594 uxth r0, r9 */
/* @0x242598 add sp, sp, #20 */
/* @0x24259c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2425a0 ldrh r0, [sp] */
/* @0x2425a4 add sp, sp, #20 */
/* @0x2425a8 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x2425ac · JS_isWhitespace(int) · size=88 · insn=22 */
/* @0x2425ac cmp r0, #13 */
/* @0x2425b0 ble 0x2425e8 <_Z15JS_isWhitespacei+0x3c> */
/* @0x2425b4 cmp r0, #160 */
/* @0x2425b8 beq 0x2425e0 <_Z15JS_isWhitespacei+0x34> */
/* @0x2425bc bgt 0x2425d0 <_Z15JS_isWhitespacei+0x24> */
/* @0x2425c0 cmp r0, #32 */
/* @0x2425c4 beq 0x2425e0 <_Z15JS_isWhitespacei+0x34> */
/* @0x2425c8 mov r0, #0 */
/* @0x2425cc bx lr */
/* @0x2425d0 sub r0, r0, #8192 */
/* @0x2425d4 sub r0, r0, #40 */
/* @0x2425d8 cmp r0, #1 */
/* @0x2425dc bhi 0x2425c8 <_Z15JS_isWhitespacei+0x1c> */
/* @0x2425e0 mov r0, #1 */
/* @0x2425e4 bx lr */
/* @0x2425e8 cmp r0, #12 */
/* @0x2425ec bge 0x2425e0 <_Z15JS_isWhitespacei+0x34> */
/* @0x2425f0 sub r0, r0, #9 */
/* @0x2425f4 cmp r0, #1 */
/* @0x2425f8 bls 0x2425e0 <_Z15JS_isWhitespacei+0x34> */
/* @0x2425fc mov r0, #0 */
/* @0x242600 bx lr */

/* ── FUNC 0x242604 · JS_SplitMatch(char const*, int, char const*) · size=152 · insn=38 */
/* @0x242604 push {r4, r5, r6, r7, r8, lr} */
/* @0x242608 mov r4, r0 */
/* @0x24260c mov r0, r2 */
/* @0x242610 mov r6, r1 */
/* @0x242614 mov r7, r2 */
/* @0x242618 bl 0xb6538 <strlen@plt> */
/* @0x24261c mov r5, r0 */
/* @0x242620 mov r0, r4 */
/* @0x242624 bl 0xb6538 <strlen@plt> */
/* @0x242628 add r8, r5, r6 */
/* @0x24262c cmp r0, r8 */
/* @0x242630 blo 0x242694 <_Z13JS_SplitMatchPKciS0_+0x90> */
/* @0x242634 cmp r5, #0 */
/* @0x242638 beq 0x242678 <_Z13JS_SplitMatchPKciS0_+0x74> */
/* @0x24263c ldrb r1, [r4, r6] */
/* @0x242640 add r3, r4, r6 */
/* @0x242644 ldrb r2, [r7] */
/* @0x242648 cmp r1, r2 */
/* @0x24264c bne 0x242694 <_Z13JS_SplitMatchPKciS0_+0x90> */
/* @0x242650 sub r0, r7, #1 */
/* @0x242654 mov r2, r7 */
/* @0x242658 add r0, r0, r5 */
/* @0x24265c b 0x242670 <_Z13JS_SplitMatchPKciS0_+0x6c> */
/* @0x242660 ldrb r12, [r3, #0x1]! */
/* @0x242664 ldrb r1, [r2, #0x1]! */
/* @0x242668 cmp r12, r1 */
/* @0x24266c bne 0x242694 <_Z13JS_SplitMatchPKciS0_+0x90> */
/* @0x242670 cmp r2, r0 */
/* @0x242674 bne 0x242660 <_Z13JS_SplitMatchPKciS0_+0x5c> */
/* @0x242678 mov r0, #8 */
/* @0x24267c bl 0x27c524 <_Znwj> */
/* @0x242680 mov r2, #0 */
/* @0x242684 mov r3, r0 */
/* @0x242688 str r8, [r0] */
/* @0x24268c str r2, [r3, #0x4] */
/* @0x242690 pop {r4, r5, r6, r7, r8, pc} */
/* @0x242694 mov r0, #0 */
/* @0x242698 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x24269c · JS_StringSetup() · size=1512 · insn=378 */
/* @0x24269c push {r4, r5, r6, r7, r8, lr} */
/* @0x2426a0 sub sp, sp, #40 */
/* @0x2426a4 mov r6, #0 */
/* @0x2426a8 add r0, sp, #8 */
/* @0x2426ac mov r1, r6 */
/* @0x2426b0 mov r2, r6 */
/* @0x2426b4 mov r3, r6 */
/* @0x2426b8 mov r4, #0 */
/* @0x2426bc mov r5, #0 */
/* @0x2426c0 str r6, [sp] */
/* @0x2426c4 strd r4, r5, [sp, #8] */
/* @0x2426c8 mvn r12, #-16777216 */
/* @0x2426cc ldr r5, [pc, #0x4e8] */
/* @0x2426d0 str r12, [sp, #0x14] */
/* @0x2426d4 str r6, [sp, #0x10] */
/* @0x2426d8 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x2426dc ldr r3, [pc, #0x4dc] */
/* @0x2426e0 add r5, pc, r5 */
/* @0x2426e4 ldr r4, [sp, #0x8] */
/* @0x2426e8 ldr r2, [pc, #0x4d4] */
/* @0x2426ec ldr r8, [r5, r3] */
/* @0x2426f0 ldr r3, [pc, #0x4d0] */
/* @0x2426f4 add r2, pc, r2 */
/* @0x2426f8 str r2, [r4, #0x40] */
/* @0x2426fc mov r0, r4 */
/* @0x242700 str r4, [r8] */
/* @0x242704 ldr r3, [r5, r3] */
/* @0x242708 ldr r1, [r3] */
/* @0x24270c str r1, [r4, #0x18] */
/* @0x242710 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x242714 ldr r3, [pc, #0x4b0] */
/* @0x242718 ldr r0, [r4, #0x28] */
/* @0x24271c mov r1, r6 */
/* @0x242720 mov r2, r6 */
/* @0x242724 orr r0, r0, #1 */
/* @0x242728 str r0, [r4, #0x28] */
/* @0x24272c ldr r7, [r5, r3] */
/* @0x242730 mov r0, r7 */
/* @0x242734 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x242738 ldr r1, [pc, #0x490] */
/* @0x24273c mov r3, #6 */
/* @0x242740 add r1, pc, r1 */
/* @0x242744 mov r2, r0 */
/* @0x242748 mov r0, r4 */
/* @0x24274c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242750 mov r0, r7 */
/* @0x242754 mov r1, r6 */
/* @0x242758 mov r2, r6 */
/* @0x24275c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x242760 ldr r1, [pc, #0x46c] */
/* @0x242764 mov r3, #6 */
/* @0x242768 add r1, pc, r1 */
/* @0x24276c mov r2, r0 */
/* @0x242770 mov r0, r4 */
/* @0x242774 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242778 ldr r3, [pc, #0x458] */
/* @0x24277c mov r2, r6 */
/* @0x242780 mov r1, #1 */
/* @0x242784 ldr r0, [r5, r3] */
/* @0x242788 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x24278c ldr r1, [pc, #0x448] */
/* @0x242790 mov r3, #6 */
/* @0x242794 add r1, pc, r1 */
/* @0x242798 mov r2, r0 */
/* @0x24279c mov r0, r4 */
/* @0x2427a0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2427a4 ldr r3, [pc, #0x434] */
/* @0x2427a8 mov r2, r6 */
/* @0x2427ac mov r1, #1 */
/* @0x2427b0 ldr r0, [r5, r3] */
/* @0x2427b4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2427b8 ldr r1, [pc, #0x424] */
/* @0x2427bc mov r3, #6 */
/* @0x2427c0 add r1, pc, r1 */
/* @0x2427c4 mov r2, r0 */
/* @0x2427c8 mov r0, r4 */
/* @0x2427cc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2427d0 ldr r3, [pc, #0x410] */
/* @0x2427d4 mov r2, r6 */
/* @0x2427d8 mov r1, #1 */
/* @0x2427dc ldr r0, [r5, r3] */
/* @0x2427e0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2427e4 ldr r1, [pc, #0x400] */
/* @0x2427e8 mov r3, #6 */
/* @0x2427ec add r1, pc, r1 */
/* @0x2427f0 mov r2, r0 */
/* @0x2427f4 mov r0, r4 */
/* @0x2427f8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2427fc ldr r3, [pc, #0x3ec] */
/* @0x242800 mov r2, r6 */
/* @0x242804 mov r1, #1 */
/* @0x242808 ldr r0, [r5, r3] */
/* @0x24280c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x242810 ldr r1, [pc, #0x3dc] */
/* @0x242814 mov r3, #6 */
/* @0x242818 add r1, pc, r1 */
/* @0x24281c mov r2, r0 */
/* @0x242820 mov r0, r4 */
/* @0x242824 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242828 ldr r3, [pc, #0x3c8] */
/* @0x24282c mov r2, r6 */
/* @0x242830 mov r1, #1 */
/* @0x242834 ldr r0, [r5, r3] */
/* @0x242838 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x24283c ldr r1, [pc, #0x3b8] */
/* @0x242840 mov r3, #6 */
/* @0x242844 add r1, pc, r1 */
/* @0x242848 mov r2, r0 */
/* @0x24284c mov r0, r4 */
/* @0x242850 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242854 ldr r3, [pc, #0x3a4] */
/* @0x242858 mov r2, r6 */
/* @0x24285c mov r1, #1 */
/* @0x242860 ldr r0, [r5, r3] */
/* @0x242864 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x242868 ldr r1, [pc, #0x394] */
/* @0x24286c mov r3, #6 */
/* @0x242870 add r1, pc, r1 */
/* @0x242874 mov r2, r0 */
/* @0x242878 mov r0, r4 */
/* @0x24287c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242880 ldr r3, [pc, #0x380] */
/* @0x242884 mov r2, r6 */
/* @0x242888 mov r1, #1 */
/* @0x24288c ldr r0, [r5, r3] */
/* @0x242890 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x242894 ldr r1, [pc, #0x370] */
/* @0x242898 mov r3, #6 */
/* @0x24289c add r1, pc, r1 */
/* @0x2428a0 mov r2, r0 */
/* @0x2428a4 mov r0, r4 */
/* @0x2428a8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2428ac ldr r3, [pc, #0x35c] */
/* @0x2428b0 mov r2, r6 */
/* @0x2428b4 mov r1, #2 */
/* @0x2428b8 ldr r0, [r5, r3] */
/* @0x2428bc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2428c0 ldr r1, [pc, #0x34c] */
/* @0x2428c4 mov r3, #6 */
/* @0x2428c8 add r1, pc, r1 */
/* @0x2428cc mov r2, r0 */
/* @0x2428d0 mov r0, r4 */
/* @0x2428d4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2428d8 ldr r3, [pc, #0x338] */
/* @0x2428dc mov r2, r6 */
/* @0x2428e0 mov r1, #1 */
/* @0x2428e4 ldr r0, [r5, r3] */
/* @0x2428e8 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2428ec ldr r1, [pc, #0x328] */
/* @0x2428f0 mov r3, #6 */
/* @0x2428f4 add r1, pc, r1 */
/* @0x2428f8 mov r2, r0 */
/* @0x2428fc mov r0, r4 */
/* @0x242900 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242904 ldr r3, [pc, #0x314] */
/* @0x242908 mov r2, r6 */
/* @0x24290c mov r1, #2 */
/* @0x242910 ldr r0, [r5, r3] */
/* @0x242914 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x242918 ldr r1, [pc, #0x304] */
/* @0x24291c mov r3, #6 */
/* @0x242920 add r1, pc, r1 */
/* @0x242924 mov r2, r0 */
/* @0x242928 mov r0, r4 */
/* @0x24292c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242930 ldr r3, [pc, #0x2f0] */
/* @0x242934 mov r2, r6 */
/* @0x242938 mov r1, #2 */
/* @0x24293c ldr r0, [r5, r3] */
/* @0x242940 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x242944 ldr r1, [pc, #0x2e0] */
/* @0x242948 mov r3, #6 */
/* @0x24294c add r1, pc, r1 */
/* @0x242950 mov r2, r0 */
/* @0x242954 mov r0, r4 */
/* @0x242958 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x24295c ldr r3, [pc, #0x2cc] */
/* @0x242960 mov r2, r6 */
/* @0x242964 mov r1, #2 */
/* @0x242968 ldr r0, [r5, r3] */
/* @0x24296c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x242970 ldr r1, [pc, #0x2bc] */
/* @0x242974 mov r3, #6 */
/* @0x242978 add r1, pc, r1 */
/* @0x24297c mov r2, r0 */
/* @0x242980 mov r0, r4 */
/* @0x242984 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242988 ldr r3, [pc, #0x2a8] */
/* @0x24298c mov r1, r6 */
/* @0x242990 mov r2, r6 */
/* @0x242994 ldr r0, [r5, r3] */
/* @0x242998 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x24299c ldr r1, [pc, #0x298] */
/* @0x2429a0 mov r3, #6 */
/* @0x2429a4 add r1, pc, r1 */
/* @0x2429a8 mov r2, r0 */
/* @0x2429ac mov r0, r4 */
/* @0x2429b0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2429b4 ldr r3, [pc, #0x284] */
/* @0x2429b8 mov r1, r6 */
/* @0x2429bc mov r2, r6 */
/* @0x2429c0 ldr r7, [r5, r3] */
/* @0x2429c4 mov r0, r7 */
/* @0x2429c8 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2429cc ldr r1, [pc, #0x270] */
/* @0x2429d0 mov r3, #6 */
/* @0x2429d4 add r1, pc, r1 */
/* @0x2429d8 mov r2, r0 */
/* @0x2429dc mov r0, r4 */
/* @0x2429e0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2429e4 ldr r3, [pc, #0x25c] */
/* @0x2429e8 mov r1, r6 */
/* @0x2429ec mov r2, r6 */
/* @0x2429f0 ldr r0, [r5, r3] */
/* @0x2429f4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2429f8 ldr r1, [pc, #0x24c] */
/* @0x2429fc mov r3, #6 */
/* @0x242a00 add r1, pc, r1 */
/* @0x242a04 mov r2, r0 */
/* @0x242a08 mov r0, r4 */
/* @0x242a0c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242a10 mov r0, r7 */
/* @0x242a14 mov r1, r6 */
/* @0x242a18 mov r2, r6 */
/* @0x242a1c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x242a20 ldr r1, [pc, #0x228] */
/* @0x242a24 mov r3, #6 */
/* @0x242a28 add r7, sp, #24 */
/* @0x242a2c add r1, pc, r1 */
/* @0x242a30 mov r2, r0 */
/* @0x242a34 mov r0, r4 */
/* @0x242a38 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242a3c ldr r3, [pc, #0x210] */
/* @0x242a40 mov r1, r6 */
/* @0x242a44 mov r2, r6 */
/* @0x242a48 ldr r0, [r5, r3] */
/* @0x242a4c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x242a50 ldr r1, [pc, #0x200] */
/* @0x242a54 mov r3, #6 */
/* @0x242a58 add r1, pc, r1 */
/* @0x242a5c mov r2, r0 */
/* @0x242a60 mov r0, r4 */
/* @0x242a64 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242a68 ldr r1, [pc, #0x1ec] */
/* @0x242a6c mov r2, r6 */
/* @0x242a70 mov r3, r6 */
/* @0x242a74 mov r0, r4 */
/* @0x242a78 add r1, pc, r1 */
/* @0x242a7c bl 0x199960 <_ZN12YYObjectBase3AddEPKcii> */
/* @0x242a80 ldr r1, [pc, #0x1d8] */
/* @0x242a84 mov r0, r7 */
/* @0x242a88 str r6, [sp, #0x18] */
/* @0x242a8c add r1, pc, r1 */
/* @0x242a90 str r6, [sp, #0x1c] */
/* @0x242a94 str r6, [sp, #0x20] */
/* @0x242a98 str r6, [sp, #0x24] */
/* @0x242a9c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x242aa0 ldr r1, [pc, #0x1bc] */
/* @0x242aa4 mov r2, r7 */
/* @0x242aa8 mov r0, r4 */
/* @0x242aac mov r3, r6 */
/* @0x242ab0 add r1, pc, r1 */
/* @0x242ab4 bl 0x199b20 <_ZN12YYObjectBase3AddEPKcPvi> */
/* @0x242ab8 ldr r3, [pc, #0x1a8] */
/* @0x242abc mov r2, r6 */
/* @0x242ac0 mov r1, #1 */
/* @0x242ac4 ldr r0, [r5, r3] */
/* @0x242ac8 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x242acc ldr r3, [pc, #0x198] */
/* @0x242ad0 mov r2, r6 */
/* @0x242ad4 mov r1, #1 */
/* @0x242ad8 mov r7, r0 */
/* @0x242adc ldr r0, [r5, r3] */
/* @0x242ae0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x242ae4 ldr r1, [pc, #0x184] */
/* @0x242ae8 mov r3, r6 */
/* @0x242aec add r1, pc, r1 */
/* @0x242af0 mov r2, r0 */
/* @0x242af4 mov r0, r7 */
/* @0x242af8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242afc ldr r12, [pc, #0x170] */
/* @0x242b00 ldr r1, [pc, #0x170] */
/* @0x242b04 mov r3, r6 */
/* @0x242b08 mov r0, r4 */
/* @0x242b0c mov r2, r7 */
/* @0x242b10 ldr r12, [r5, r12] */
/* @0x242b14 add r1, pc, r1 */
/* @0x242b18 str r12, [r7, #0x94] */
/* @0x242b1c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242b20 ldr r3, [r7, #0x4] */
/* @0x242b24 cmp r3, r6 */
/* @0x242b28 beq 0x242b7c <_Z14JS_StringSetupv+0x4e0> */
/* @0x242b2c ldr r1, [r8] */
/* @0x242b30 mov r0, r7 */
/* @0x242b34 str r1, [r3] */
/* @0x242b38 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x242b3c ldr r1, [r7, #0x4] */
/* @0x242b40 cmp r1, #0 */
/* @0x242b44 movne r3, #6 */
/* @0x242b48 strne r3, [r1, #0xc] */
/* @0x242b4c beq 0x242b90 <_Z14JS_StringSetupv+0x4f4> */
/* @0x242b50 ldr r0, [pc, #0x124] */
/* @0x242b54 mov r3, #0 */
/* @0x242b58 str r3, [r1, #0x8] */
/* @0x242b5c mov r2, r7 */
/* @0x242b60 ldr r1, [pc, #0x118] */
/* @0x242b64 ldr r0, [r5, r0] */
/* @0x242b68 add r1, pc, r1 */
/* @0x242b6c ldr r0, [r0] */
/* @0x242b70 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242b74 add sp, sp, #40 */
/* @0x242b78 pop {r4, r5, r6, r7, r8, pc} */
/* @0x242b7c mov r1, r3 */
/* @0x242b80 mov r0, r7 */
/* @0x242b84 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x242b88 mov r3, r0 */
/* @0x242b8c b 0x242b2c <_Z14JS_StringSetupv+0x490> */
/* @0x242b90 mov r0, r7 */
/* @0x242b94 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x242b98 ldr r1, [r7, #0x4] */
/* @0x242b9c mov r3, #6 */
/* @0x242ba0 cmp r1, #0 */
/* @0x242ba4 str r3, [r0, #0xc] */
/* @0x242ba8 bne 0x242b50 <_Z14JS_StringSetupv+0x4b4> */
/* @0x242bac mov r0, r7 */
/* @0x242bb0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x242bb4 mov r1, r0 */
/* @0x242bb8 b 0x242b50 <_Z14JS_StringSetupv+0x4b4> */
/* @0x242bbc andseq pc, r10, r0, ror r5 */
/* @0x242bc0 .word 0xfffff960 */
/* @0x242bc4 andseq r3, r1, r4, rrx */
/* @0x242bc8 .word 0xffffc050 */
/* @0x242bcc .word 0xfffff964 */
/* @0x242bd0 .word 0x000efdd0 */
/* @0x242bd4 ldrsheq r2, [r1], -r0 */
/* @0x242bd8 .word 0xfffff968 */
/* @0x242bdc ldrsbeq r2, [r1], -r0 */
/* @0x242be0 .word 0xfffff96c */
/* @0x242be4 andseq r2, r1, r12, lsr #31 */
/* @0x242be8 .word 0xfffff970 */
/* @0x242bec andseq r2, r1, r12, lsl #31 */
/* @0x242bf0 .word 0xfffff974 */
/* @0x242bf4 andseq r2, r1, r8, ror #30 */
/* @0x242bf8 .word 0xfffff978 */
/* @0x242bfc andseq r2, r1, r4, asr #30 */
/* @0x242c00 .word 0xfffff97c */
/* @0x242c04 andseq r2, r1, r4, lsr #30 */
/* @0x242c08 .word 0xfffff980 */
/* @0x242c0c andseq r2, r1, r8, lsl #30 */
/* @0x242c10 .word 0xfffff984 */
/* @0x242c14 andseq r2, r1, r4, ror #29 */
/* @0x242c18 .word 0xfffff988 */
/* @0x242c1c andseq r2, r1, r0, asr #29 */
/* @0x242c20 .word 0xfffff98c */
/* @0x242c24 mulseq r1, r12, lr */
/* @0x242c28 .word 0xfffff990 */
/* @0x242c2c andseq r2, r1, r8, ror lr */
/* @0x242c30 .word 0xfffff994 */
/* @0x242c34 andseq r2, r1, r4, asr lr */
/* @0x242c38 .word 0xfffff998 */
/* @0x242c3c andseq r2, r1, r4, lsr lr */
/* @0x242c40 .word 0xfffff8ec */
/* @0x242c44 andseq r2, r1, r0, lsl lr */
/* @0x242c48 .word 0xfffff99c */
/* @0x242c4c ldrsheq r2, [r1], -r8 */
/* @0x242c50 ldrsbeq r2, [r1], -r8 */
/* @0x242c54 .word 0xfffff9a0 */
/* @0x242c58 andseq r2, r1, r0, asr #27 */
/* @0x242c5c strdeq sp, lr, [lr], -r4 */
/* @0x242c60 andeq r12, lr, r10, lsr #1 */
/* @0x242c64 andseq r2, r1, r0, ror #20 */
/* @0x242c68 .word 0xfffff9a4 */
/* @0x242c6c .word 0xfffff9a8 */
/* @0x242c70 andseq r2, r1, r4, lsr sp */
/* @0x242c74 .word 0xfffff9ac */
/* @0x242c78 andseq r2, r1, r0, lsl r10 */
/* @0x242c7c .word 0xffffbf64 */
/* @0x242c80 andseq r2, r1, r8, asr #25 */

/* ── FUNC 0x242c84 · F_JSNewArray_NoArguments(RValue&, CInstance*, CInstance*, int, RValue*) · size=568 · insn=142 */
/* @0x242c84 push {r4, r5, r6, r7, r8, lr} */
/* @0x242c88 sub sp, sp, #8 */
/* @0x242c8c ldr r5, [pc, #0x1fc] */
/* @0x242c90 mov r7, r0 */
/* @0x242c94 ldr r12, [sp, #0x20] */
/* @0x242c98 mov r8, r3 */
/* @0x242c9c add r5, pc, r5 */
/* @0x242ca0 str r12, [sp] */
/* @0x242ca4 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x242ca8 ldr r3, [pc, #0x1e4] */
/* @0x242cac ldr r4, [r7] */
/* @0x242cb0 ldr r3, [r5, r3] */
/* @0x242cb4 mov r0, r4 */
/* @0x242cb8 ldr r1, [r3] */
/* @0x242cbc str r1, [r4, #0x18] */
/* @0x242cc0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x242cc4 ldr r3, [pc, #0x1cc] */
/* @0x242cc8 ldr r2, [r4, #0x28] */
/* @0x242ccc ldr r1, [pc, #0x1c8] */
/* @0x242cd0 orr r2, r2, #1 */
/* @0x242cd4 str r2, [r4, #0x28] */
/* @0x242cd8 add r1, pc, r1 */
/* @0x242cdc str r1, [r4, #0x40] */
/* @0x242ce0 ldr r1, [pc, #0x1b8] */
/* @0x242ce4 ldr r0, [r5, r3] */
/* @0x242ce8 ldr r2, [pc, #0x1b4] */
/* @0x242cec ldr r3, [pc, #0x1b4] */
/* @0x242cf0 str r0, [r4, #0x4c] */
/* @0x242cf4 ldr r1, [r5, r1] */
/* @0x242cf8 str r1, [r4, #0x54] */
/* @0x242cfc ldr r1, [r5, r3] */
/* @0x242d00 ldr r0, [r5, r2] */
/* @0x242d04 bl 0x241504 <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_> */
/* @0x242d08 ldr r1, [pc, #0x19c] */
/* @0x242d0c mov r3, #6 */
/* @0x242d10 add r1, pc, r1 */
/* @0x242d14 mov r2, r0 */
/* @0x242d18 mov r0, r4 */
/* @0x242d1c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242d20 ldr r3, [pc, #0x188] */
/* @0x242d24 mvn r1, #-16777216 */
/* @0x242d28 mov r2, #0 */
/* @0x242d2c ldr r3, [r5, r3] */
/* @0x242d30 ldr r0, [r3] */
/* @0x242d34 bl 0x19198c <_ZN12YYObjectBase5AllocEjib> */
/* @0x242d38 ldr r1, [pc, #0x174] */
/* @0x242d3c ldr r2, [r7] */
/* @0x242d40 mov r3, #6 */
/* @0x242d44 add r1, pc, r1 */
/* @0x242d48 mov r6, r0 */
/* @0x242d4c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x242d50 ldr r3, [pc, #0x160] */
/* @0x242d54 mov r0, r6 */
/* @0x242d58 ldr r3, [r5, r3] */
/* @0x242d5c ldr r1, [r3] */
/* @0x242d60 str r1, [r6, #0x18] */
/* @0x242d64 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x242d68 ldr r1, [r4, #0x4] */
/* @0x242d6c cmp r1, #0 */
/* @0x242d70 beq 0x242e00 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x242d74 str r6, [r1] */
/* @0x242d78 mov r0, r4 */
/* @0x242d7c mov r1, r6 */
/* @0x242d80 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x242d84 ldr r2, [r4, #0x4] */
/* @0x242d88 cmp r2, #0 */
/* @0x242d8c movne r3, #6 */
/* @0x242d90 strne r3, [r2, #0xc] */
/* @0x242d94 beq 0x242e10 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0x242d98 mov r6, #0 */
/* @0x242d9c mov r0, r8 */
/* @0x242da0 str r6, [r2, #0x8] */
/* @0x242da4 mvn r1, #-16777216 */
/* @0x242da8 mov r2, #1 */
/* @0x242dac bl 0x19198c <_ZN12YYObjectBase5AllocEjib> */
/* @0x242db0 mov r5, r0 */
/* @0x242db4 ldr r0, [r4, #0x4] */
/* @0x242db8 str r6, [r5, #0x24] */
/* @0x242dbc cmp r0, r6 */
/* @0x242dc0 beq 0x242e44 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_+0x1c0> */
/* @0x242dc4 add r0, r0, #16 */
/* @0x242dc8 str r5, [r0] */
/* @0x242dcc mov r1, r5 */
/* @0x242dd0 mov r0, r4 */
/* @0x242dd4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x242dd8 ldr r3, [r4, #0x4] */
/* @0x242ddc cmp r3, #0 */
/* @0x242de0 beq 0x242e54 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x242de4 mov r2, #6 */
/* @0x242de8 str r2, [r3, #0x1c] */
/* @0x242dec add r0, r3, #16 */
/* @0x242df0 mov r2, #0 */
/* @0x242df4 str r2, [r0, #0x8] */
/* @0x242df8 add sp, sp, #8 */
/* @0x242dfc pop {r4, r5, r6, r7, r8, pc} */
/* @0x242e00 mov r0, r4 */
/* @0x242e04 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x242e08 mov r1, r0 */
/* @0x242e0c b 0x242d74 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x242e10 mov r1, r2 */
/* @0x242e14 mov r0, r4 */
/* @0x242e18 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x242e1c ldr r2, [r4, #0x4] */
/* @0x242e20 mov r3, #6 */
/* @0x242e24 cmp r2, #0 */
/* @0x242e28 str r3, [r0, #0xc] */
/* @0x242e2c bne 0x242d98 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x242e30 mov r1, r2 */
/* @0x242e34 mov r0, r4 */
/* @0x242e38 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x242e3c mov r2, r0 */
/* @0x242e40 b 0x242d98 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x242e44 mov r0, r4 */
/* @0x242e48 mov r1, #1 */
/* @0x242e4c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x242e50 b 0x242dc8 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x242e54 mov r0, r4 */
/* @0x242e58 mov r1, #1 */
/* @0x242e5c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x242e60 ldr r3, [r4, #0x4] */
/* @0x242e64 mov r2, #6 */
/* @0x242e68 cmp r3, #0 */
/* @0x242e6c str r2, [r0, #0xc] */
/* @0x242e70 bne 0x242dec <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x242e74 mov r0, r4 */
/* @0x242e78 mov r1, #1 */
/* @0x242e7c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x242e80 mov r2, #0 */
/* @0x242e84 str r2, [r0, #0x8] */
/* @0x242e88 add sp, sp, #8 */
/* @0x242e8c pop {r4, r5, r6, r7, r8, pc} */
/* @0x242e90 ldrheq lr, [r10], -r4 */
/* @0x242e94 .word 0xfffff9b0 */
/* @0x242e98 .word 0xfffff9b4 */
/* @0x242e9c andeq r1, pc, r0, asr #24 */
/* @0x242ea0 .word 0xfffff9b8 */
/* @0x242ea4 .word 0xfffff9bc */
/* @0x242ea8 .word 0xfffff9c0 */
/* @0x242eac andeq sp, lr, r12, asr r11 */
/* @0x242eb0 .word 0xffffc0c4 */
/* @0x242eb4 andseq r2, r1, r0, ror #15 */
/* @0x242eb8 .word 0xffffc050 */

/* ── FUNC 0x242ebc · translate(EJSRetVal) · size=32 · insn=8 */
/* @0x242ebc cmp r0, #1 */
/* @0x242ec0 beq 0x242ed4 <_Z9translate9EJSRetVal+0x18> */
/* @0x242ec4 cmp r0, #2 */
/* @0x242ec8 mvneq r0, #3 */
/* @0x242ecc movne r0, #0 */
/* @0x242ed0 bx lr */
/* @0x242ed4 mvn r0, #4 */
/* @0x242ed8 bx lr */
