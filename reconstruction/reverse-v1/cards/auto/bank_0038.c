/* libyoyo.so 覆盖卡组 0038
 * 函数 0x10ec64..0x10fcc0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x10ec64 · F_Bool(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x10ec64 push {r4, lr} */
/* @0x10ec68 mov r4, r0 */
/* @0x10ec6c mov r3, #13 */
/* @0x10ec70 ldr r0, [sp, #0x8] */
/* @0x10ec74 str r3, [r4, #0xc] */
/* @0x10ec78 bl 0xd1294 <_Z11BOOL_RValuePK6RValue> */
/* @0x10ec7c vmov s15, r0 */
/* @0x10ec80 vcvt.f64.u32 d7, s15 */
/* @0x10ec84 vmov r0, r1, d7 */
/* @0x10ec88 vmov r2, s14 */
/* @0x10ec8c mov r3, r1 */
/* @0x10ec90 stm r4, {r2, r3} */
/* @0x10ec94 pop {r4, pc} */

/* ── FUNC 0x10ec98 · F_String(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x10ec98 ldr r1, [pc, #0x98] */
/* @0x10ec9c mov r12, #256 */
/* @0x10eca0 push {r4, r5, lr} */
/* @0x10eca4 sub sp, sp, #28 */
/* @0x10eca8 mov r4, r0 */
/* @0x10ecac mov r3, #1 */
/* @0x10ecb0 add r1, pc, r1 */
/* @0x10ecb4 str r3, [r0, #0xc] */
/* @0x10ecb8 movw r2, #0x621 */
/* @0x10ecbc mov r0, r12 */
/* @0x10ecc0 str r12, [sp, #0xc] */
/* @0x10ecc4 ldr r5, [sp, #0x28] */
/* @0x10ecc8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x10eccc add r1, sp, #16 */
/* @0x10ecd0 mov r3, r5 */
/* @0x10ecd4 mov r5, #0 */
/* @0x10ecd8 mov r2, r0 */
/* @0x10ecdc add r0, sp, #24 */
/* @0x10ece0 str r2, [sp, #0x10] */
/* @0x10ece4 str r2, [r0, #-0x4]! */
/* @0x10ece8 strb r5, [r2] */
/* @0x10ecec add r2, sp, #12 */
/* @0x10ecf0 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x10ecf4 ldr r0, [sp, #0x10] */
/* @0x10ecf8 ldr r1, [sp, #0x14] */
/* @0x10ecfc mov r3, #74 */
/* @0x10ed00 ldr r2, [pc, #0x34] */
/* @0x10ed04 rsb r1, r0, r1 */
/* @0x10ed08 str r5, [sp] */
/* @0x10ed0c add r2, pc, r2 */
/* @0x10ed10 add r1, r1, #1 */
/* @0x10ed14 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10ed18 mov r5, r0 */
/* @0x10ed1c mov r0, r4 */
/* @0x10ed20 mov r1, r5 */
/* @0x10ed24 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x10ed28 mov r0, r5 */
/* @0x10ed2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x10ed30 add sp, sp, #28 */
/* @0x10ed34 pop {r4, r5, pc} */
/* @0x10ed38 mlaeq r2, r4, r1, r10 */
/* @0x10ed3c eoreq r2, r2, r4, lsr #6 */

/* ── FUNC 0x10ed40 · F_Chr(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x10ed40 push {r4, lr} */
/* @0x10ed44 sub sp, sp, #8 */
/* @0x10ed48 mov r4, r0 */
/* @0x10ed4c mov r3, #1 */
/* @0x10ed50 ldr r0, [sp, #0x10] */
/* @0x10ed54 mov r1, #0 */
/* @0x10ed58 str r3, [r4, #0xc] */
/* @0x10ed5c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10ed60 cmp r0, #127 */
/* @0x10ed64 ble 0x10edd4 <_Z5F_ChrR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x10ed68 cmp r0, #2048 */
/* @0x10ed6c blt 0x10edb0 <_Z5F_ChrR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x10ed70 ubfx r1, r0, #0xc, #0x4 */
/* @0x10ed74 ubfx r2, r0, #0x6, #0x6 */
/* @0x10ed78 and r3, r0, #63 */
/* @0x10ed7c sub r2, r2, #128 */
/* @0x10ed80 sub r1, r1, #32 */
/* @0x10ed84 strb r2, [sp, #0x5] */
/* @0x10ed88 sub r3, r3, #128 */
/* @0x10ed8c mov r2, #0 */
/* @0x10ed90 strb r1, [sp, #0x4] */
/* @0x10ed94 strb r3, [sp, #0x6] */
/* @0x10ed98 strb r2, [sp, #0x7] */
/* @0x10ed9c mov r0, r4 */
/* @0x10eda0 add r1, sp, #4 */
/* @0x10eda4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x10eda8 add sp, sp, #8 */
/* @0x10edac pop {r4, pc} */
/* @0x10edb0 asr r2, r0, #6 */
/* @0x10edb4 and r3, r0, #63 */
/* @0x10edb8 sub r2, r2, #64 */
/* @0x10edbc sub r3, r3, #128 */
/* @0x10edc0 strb r2, [sp, #0x4] */
/* @0x10edc4 mov r2, #0 */
/* @0x10edc8 strb r3, [sp, #0x5] */
/* @0x10edcc strb r2, [sp, #0x6] */
/* @0x10edd0 b 0x10ed9c <_Z5F_ChrR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x10edd4 and r3, r0, #127 */
/* @0x10edd8 mov r2, #0 */
/* @0x10eddc strb r3, [sp, #0x4] */
/* @0x10ede0 strb r2, [sp, #0x5] */
/* @0x10ede4 b 0x10ed9c <_Z5F_ChrR6RValueP9CInstanceS2_iPS_+0x5c> */

/* ── FUNC 0x10ede8 · F_AnsiChar(RValue&, CInstance*, CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x10ede8 push {r4, lr} */
/* @0x10edec sub sp, sp, #8 */
/* @0x10edf0 mov r4, r0 */
/* @0x10edf4 mov r1, #0 */
/* @0x10edf8 ldr r0, [sp, #0x10] */
/* @0x10edfc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10ee00 add r1, sp, #4 */
/* @0x10ee04 mov r3, #0 */
/* @0x10ee08 strb r3, [sp, #0x5] */
/* @0x10ee0c strb r0, [sp, #0x4] */
/* @0x10ee10 mov r0, r4 */
/* @0x10ee14 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x10ee18 add sp, sp, #8 */
/* @0x10ee1c pop {r4, pc} */

/* ── FUNC 0x10ee20 · F_Int64(RValue&, CInstance*, CInstance*, int, RValue*) · size=32 · insn=8 */
/* @0x10ee20 push {r4, lr} */
/* @0x10ee24 mov r4, r0 */
/* @0x10ee28 mov r3, #10 */
/* @0x10ee2c ldr r0, [sp, #0x8] */
/* @0x10ee30 str r3, [r4, #0xc] */
/* @0x10ee34 bl 0xd10a4 <_Z12INT64_RValuePK6RValue> */
/* @0x10ee38 stm r4, {r0, r1} */
/* @0x10ee3c pop {r4, pc} */

/* ── FUNC 0x10ee40 · F_Ptr(RValue&, CInstance*, CInstance*, int, RValue*) · size=32 · insn=8 */
/* @0x10ee40 push {r4, lr} */
/* @0x10ee44 mov r4, r0 */
/* @0x10ee48 mov r3, #3 */
/* @0x10ee4c ldr r0, [sp, #0x8] */
/* @0x10ee50 str r3, [r4, #0xc] */
/* @0x10ee54 bl 0xd0fc0 <_Z10PTR_RValuePK6RValue> */
/* @0x10ee58 str r0, [r4] */
/* @0x10ee5c pop {r4, pc} */

/* ── FUNC 0x10ee60 · F_StringByteLength(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x10ee60 push {r4, lr} */
/* @0x10ee64 mov r1, #0 */
/* @0x10ee68 mov r4, r0 */
/* @0x10ee6c ldr r0, [sp, #0x8] */
/* @0x10ee70 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x10ee74 cmp r0, #0 */
/* @0x10ee78 beq 0x10eea8 <_Z18F_StringByteLengthR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x10ee7c bl 0xb6538 <strlen@plt> */
/* @0x10ee80 vmov s15, r0 */
/* @0x10ee84 vcvt.f64.u32 d7, s15 */
/* @0x10ee88 vmov r2, r3, d7 */
/* @0x10ee8c mov r1, r2 */
/* @0x10ee90 mov r2, r3 */
/* @0x10ee94 str r1, [r4] */
/* @0x10ee98 mov r3, #0 */
/* @0x10ee9c str r2, [r4, #0x4] */
/* @0x10eea0 str r3, [r4, #0xc] */
/* @0x10eea4 pop {r4, pc} */
/* @0x10eea8 mov r2, #0 */
/* @0x10eeac mov r3, #0 */
/* @0x10eeb0 b 0x10ee8c <_Z18F_StringByteLengthR6RValueP9CInstanceS2_iPS_+0x2c> */

/* ── FUNC 0x10eeb4 · F_StringSetByteAt(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x10eeb4 push {r4, r5, r6, r7, r8, lr} */
/* @0x10eeb8 mov r1, #0 */
/* @0x10eebc ldr r4, [sp, #0x18] */
/* @0x10eec0 mov r7, r0 */
/* @0x10eec4 mov r0, r4 */
/* @0x10eec8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x10eecc mov r1, #1 */
/* @0x10eed0 mov r6, r0 */
/* @0x10eed4 mov r0, r4 */
/* @0x10eed8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10eedc mov r1, #2 */
/* @0x10eee0 sub r5, r0, #1 */
/* @0x10eee4 mov r0, r4 */
/* @0x10eee8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10eeec mov r8, r0 */
/* @0x10eef0 mov r0, r6 */
/* @0x10eef4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x10eef8 mov r4, r0 */
/* @0x10eefc mov r0, r6 */
/* @0x10ef00 bl 0xb6538 <strlen@plt> */
/* @0x10ef04 cmp r5, r0 */
/* @0x10ef08 movge r1, #0 */
/* @0x10ef0c movlt r1, #1 */
/* @0x10ef10 cmp r5, #0 */
/* @0x10ef14 movlt r1, #0 */
/* @0x10ef18 cmp r1, #0 */
/* @0x10ef1c strbne r8, [r4, r5] */
/* @0x10ef20 bne 0x10ef30 <_Z17F_StringSetByteAtR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x10ef24 ldr r0, [pc, #0x1c] */
/* @0x10ef28 add r0, pc, r0 */
/* @0x10ef2c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x10ef30 mov r0, r7 */
/* @0x10ef34 mov r1, r4 */
/* @0x10ef38 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x10ef3c mov r0, r4 */
/* @0x10ef40 pop {r4, r5, r6, r7, r8, lr} */
/* @0x10ef44 b 0xcef90 <_Z6YYFreePKv> */
/* @0x10ef48 eoreq r9, r2, r8, asr pc */

/* ── FUNC 0x10ef4c · F_StringRepeat(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x10ef4c push {r4, r5, r6, r7, r8, lr} */
/* @0x10ef50 mov r1, #0 */
/* @0x10ef54 ldr r4, [sp, #0x18] */
/* @0x10ef58 mov r8, r0 */
/* @0x10ef5c mov r0, r4 */
/* @0x10ef60 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x10ef64 mov r1, #1 */
/* @0x10ef68 mov r7, r0 */
/* @0x10ef6c mov r0, r4 */
/* @0x10ef70 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10ef74 subs r6, r0, #0 */
/* @0x10ef78 ble 0x10efd8 <_Z14F_StringRepeatR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x10ef7c mov r0, r7 */
/* @0x10ef80 mov r4, #1 */
/* @0x10ef84 bl 0xb6538 <strlen@plt> */
/* @0x10ef88 ldr r1, [pc, #0x5c] */
/* @0x10ef8c movw r2, #0x826 */
/* @0x10ef90 mov r3, r4 */
/* @0x10ef94 add r1, pc, r1 */
/* @0x10ef98 mul r0, r6, r0 */
/* @0x10ef9c add r0, r0, r4 */
/* @0x10efa0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x10efa4 mov r5, r0 */
/* @0x10efa8 add r4, r4, #1 */
/* @0x10efac mov r0, r5 */
/* @0x10efb0 mov r1, r7 */
/* @0x10efb4 bl 0xb6628 <strcat@plt> */
/* @0x10efb8 cmp r6, r4 */
/* @0x10efbc bge 0x10efa8 <_Z14F_StringRepeatR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x10efc0 mov r0, r8 */
/* @0x10efc4 mov r1, r5 */
/* @0x10efc8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x10efcc mov r0, r5 */
/* @0x10efd0 pop {r4, r5, r6, r7, r8, lr} */
/* @0x10efd4 b 0xcef90 <_Z6YYFreePKv> */
/* @0x10efd8 ldr r0, [pc, #0x10] */
/* @0x10efdc add r0, pc, r0 */
/* @0x10efe0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x10efe4 mov r5, r0 */
/* @0x10efe8 b 0x10efc0 <_Z14F_StringRepeatR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x10efec .word 0x00229eb0 */
/* @0x10eff0 eoreq sp, r4, r0, ror #18 */

/* ── FUNC 0x10eff4 · F_PointDistance(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x10eff4 push {r4, r5, r6, lr} */
/* @0x10eff8 vpush {d8} */
/* @0x10effc mov r6, #0 */
/* @0x10f000 ldr r4, [sp, #0x18] */
/* @0x10f004 mov r1, #2 */
/* @0x10f008 str r6, [r0, #0xc] */
/* @0x10f00c mov r5, r0 */
/* @0x10f010 mov r0, r4 */
/* @0x10f014 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f018 mov r1, r6 */
/* @0x10f01c vmov s16, r0 */
/* @0x10f020 mov r0, r4 */
/* @0x10f024 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f028 mov r1, #3 */
/* @0x10f02c vmov s12, r0 */
/* @0x10f030 mov r0, r4 */
/* @0x10f034 vsub.f32 s16, s16, s12 */
/* @0x10f038 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f03c mov r1, #1 */
/* @0x10f040 vmov s17, r0 */
/* @0x10f044 mov r0, r4 */
/* @0x10f048 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f04c vmov s13, r0 */
/* @0x10f050 vsub.f32 s14, s17, s13 */
/* @0x10f054 vmul.f32 s14, s14, s14 */
/* @0x10f058 vmla.f32 s14, s16, s16 */
/* @0x10f05c vsqrt.f32 s15, s14 */
/* @0x10f060 vcmp.f32 s15, s15 */
/* @0x10f064 vmrs APSR_nzcv, fpscr */
/* @0x10f068 bne 0x10f080 <_Z15F_PointDistanceR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x10f06c vcvt.f64.f32 d6, s15 */
/* @0x10f070 vmov r2, r3, d6 */
/* @0x10f074 stm r5, {r2, r3} */
/* @0x10f078 vpop {d8} */
/* @0x10f07c pop {r4, r5, r6, pc} */
/* @0x10f080 vmov r0, s14 */
/* @0x10f084 bl 0xb6700 <sqrtf@plt> */
/* @0x10f088 vmov s15, r0 */
/* @0x10f08c b 0x10f06c <_Z15F_PointDistanceR6RValueP9CInstanceS2_iPS_+0x78> */

/* ── FUNC 0x10f090 · F_PointDistance_3D(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0x10f090 push {r4, r5, r6, lr} */
/* @0x10f094 vpush {d8, d9} */
/* @0x10f098 mov r6, #0 */
/* @0x10f09c ldr r4, [sp, #0x20] */
/* @0x10f0a0 mov r1, #3 */
/* @0x10f0a4 str r6, [r0, #0xc] */
/* @0x10f0a8 mov r5, r0 */
/* @0x10f0ac mov r0, r4 */
/* @0x10f0b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f0b4 mov r1, r6 */
/* @0x10f0b8 vmov s16, r0 */
/* @0x10f0bc mov r0, r4 */
/* @0x10f0c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f0c4 mov r1, #4 */
/* @0x10f0c8 vmov s12, r0 */
/* @0x10f0cc mov r0, r4 */
/* @0x10f0d0 vsub.f32 s16, s16, s12 */
/* @0x10f0d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f0d8 mov r1, #1 */
/* @0x10f0dc vmov s17, r0 */
/* @0x10f0e0 mov r0, r4 */
/* @0x10f0e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f0e8 mov r1, #5 */
/* @0x10f0ec vmov s13, r0 */
/* @0x10f0f0 mov r0, r4 */
/* @0x10f0f4 vsub.f32 s17, s17, s13 */
/* @0x10f0f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f0fc mov r1, #2 */
/* @0x10f100 vmov s18, r0 */
/* @0x10f104 mov r0, r4 */
/* @0x10f108 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f10c vmul.f32 s15, s17, s17 */
/* @0x10f110 vmla.f32 s15, s16, s16 */
/* @0x10f114 vmov s12, r0 */
/* @0x10f118 vsub.f32 s14, s18, s12 */
/* @0x10f11c vmla.f32 s15, s14, s14 */
/* @0x10f120 vsqrt.f32 s14, s15 */
/* @0x10f124 vcmp.f32 s14, s14 */
/* @0x10f128 vmrs APSR_nzcv, fpscr */
/* @0x10f12c bne 0x10f144 <_Z18F_PointDistance_3DR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x10f130 vcvt.f64.f32 d6, s14 */
/* @0x10f134 vmov r2, r3, d6 */
/* @0x10f138 stm r5, {r2, r3} */
/* @0x10f13c vpop {d8, d9} */
/* @0x10f140 pop {r4, r5, r6, pc} */
/* @0x10f144 vmov r0, s15 */
/* @0x10f148 bl 0xb6700 <sqrtf@plt> */
/* @0x10f14c vmov s14, r0 */
/* @0x10f150 b 0x10f130 <_Z18F_PointDistance_3DR6RValueP9CInstanceS2_iPS_+0xa0> */

/* ── FUNC 0x10f154 · F_DotProduct_Normalised(RValue&, CInstance*, CInstance*, int, RValue*) · size=200 · insn=50 */
/* @0x10f154 push {r3, r4, r5, lr} */
/* @0x10f158 vpush {d8, d9, d10} */
/* @0x10f15c mov r1, #0 */
/* @0x10f160 ldr r4, [sp, #0x28] */
/* @0x10f164 mov r5, r0 */
/* @0x10f168 str r1, [r0, #0xc] */
/* @0x10f16c mov r0, r4 */
/* @0x10f170 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f174 mov r1, #1 */
/* @0x10f178 vmov s18, r0 */
/* @0x10f17c mov r0, r4 */
/* @0x10f180 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f184 mov r1, #2 */
/* @0x10f188 vmov s20, r0 */
/* @0x10f18c mov r0, r4 */
/* @0x10f190 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f194 mov r1, #3 */
/* @0x10f198 vmov s17, r0 */
/* @0x10f19c mov r0, r4 */
/* @0x10f1a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f1a4 vmul.f32 s14, s20, s20 */
/* @0x10f1a8 vmla.f32 s14, s18, s18 */
/* @0x10f1ac vmov s19, r0 */
/* @0x10f1b0 vsqrt.f32 s16, s14 */
/* @0x10f1b4 vcmp.f32 s16, s16 */
/* @0x10f1b8 vmrs APSR_nzcv, fpscr */
/* @0x10f1bc bne 0x10f1fc <_Z23F_DotProduct_NormalisedR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x10f1c0 vmul.f32 s14, s19, s19 */
/* @0x10f1c4 vmla.f32 s14, s17, s17 */
/* @0x10f1c8 vsqrt.f32 s15, s14 */
/* @0x10f1cc vcmp.f32 s15, s15 */
/* @0x10f1d0 vmrs APSR_nzcv, fpscr */
/* @0x10f1d4 bne 0x10f20c <_Z23F_DotProduct_NormalisedR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x10f1d8 vmul.f32 s19, s20, s19 */
/* @0x10f1dc vmla.f32 s19, s18, s17 */
/* @0x10f1e0 vmul.f32 s16, s16, s15 */
/* @0x10f1e4 vdiv.f32 s19, s19, s16 */
/* @0x10f1e8 vcvt.f64.f32 d7, s19 */
/* @0x10f1ec vmov r2, r3, d7 */
/* @0x10f1f0 stm r5, {r2, r3} */
/* @0x10f1f4 vpop {d8, d9, d10} */
/* @0x10f1f8 pop {r3, r4, r5, pc} */
/* @0x10f1fc vmov r0, s14 */
/* @0x10f200 bl 0xb6700 <sqrtf@plt> */
/* @0x10f204 vmov s16, r0 */
/* @0x10f208 b 0x10f1c0 <_Z23F_DotProduct_NormalisedR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x10f20c vmov r0, s14 */
/* @0x10f210 bl 0xb6700 <sqrtf@plt> */
/* @0x10f214 vmov s15, r0 */
/* @0x10f218 b 0x10f1d8 <_Z23F_DotProduct_NormalisedR6RValueP9CInstanceS2_iPS_+0x84> */

/* ── FUNC 0x10f21c · F_DotProduct_3D_Normalised(RValue&, CInstance*, CInstance*, int, RValue*) · size=244 · insn=61 */
/* @0x10f21c push {r3, r4, r5, lr} */
/* @0x10f220 vpush {d8, d9, d10, d11} */
/* @0x10f224 mov r1, #0 */
/* @0x10f228 ldr r4, [sp, #0x30] */
/* @0x10f22c mov r5, r0 */
/* @0x10f230 str r1, [r0, #0xc] */
/* @0x10f234 mov r0, r4 */
/* @0x10f238 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f23c mov r1, #1 */
/* @0x10f240 vmov s20, r0 */
/* @0x10f244 mov r0, r4 */
/* @0x10f248 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f24c mov r1, #2 */
/* @0x10f250 vmov s22, r0 */
/* @0x10f254 mov r0, r4 */
/* @0x10f258 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f25c mov r1, #3 */
/* @0x10f260 vmov s18, r0 */
/* @0x10f264 mov r0, r4 */
/* @0x10f268 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f26c mov r1, #4 */
/* @0x10f270 vmov s19, r0 */
/* @0x10f274 mov r0, r4 */
/* @0x10f278 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f27c mov r1, #5 */
/* @0x10f280 vmov s21, r0 */
/* @0x10f284 mov r0, r4 */
/* @0x10f288 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f28c vmul.f32 s15, s22, s22 */
/* @0x10f290 vmla.f32 s15, s20, s20 */
/* @0x10f294 vmov s17, r0 */
/* @0x10f298 vmla.f32 s15, s18, s18 */
/* @0x10f29c vsqrt.f32 s16, s15 */
/* @0x10f2a0 vcmp.f32 s16, s16 */
/* @0x10f2a4 vmrs APSR_nzcv, fpscr */
/* @0x10f2a8 bne 0x10f2f0 <_Z26F_DotProduct_3D_NormalisedR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x10f2ac vmul.f32 s15, s21, s21 */
/* @0x10f2b0 vmla.f32 s15, s19, s19 */
/* @0x10f2b4 vmla.f32 s15, s17, s17 */
/* @0x10f2b8 vsqrt.f32 s14, s15 */
/* @0x10f2bc vcmp.f32 s14, s14 */
/* @0x10f2c0 vmrs APSR_nzcv, fpscr */
/* @0x10f2c4 bne 0x10f300 <_Z26F_DotProduct_3D_NormalisedR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x10f2c8 vmul.f32 s15, s22, s21 */
/* @0x10f2cc vmla.f32 s15, s20, s19 */
/* @0x10f2d0 vmla.f32 s15, s18, s17 */
/* @0x10f2d4 vmul.f32 s16, s16, s14 */
/* @0x10f2d8 vdiv.f32 s15, s15, s16 */
/* @0x10f2dc vcvt.f64.f32 d6, s15 */
/* @0x10f2e0 vmov r2, r3, d6 */
/* @0x10f2e4 stm r5, {r2, r3} */
/* @0x10f2e8 vpop {d8, d9, d10, d11} */
/* @0x10f2ec pop {r3, r4, r5, pc} */
/* @0x10f2f0 vmov r0, s15 */
/* @0x10f2f4 bl 0xb6700 <sqrtf@plt> */
/* @0x10f2f8 vmov s16, r0 */
/* @0x10f2fc b 0x10f2ac <_Z26F_DotProduct_3D_NormalisedR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x10f300 vmov r0, s15 */
/* @0x10f304 bl 0xb6700 <sqrtf@plt> */
/* @0x10f308 vmov s14, r0 */
/* @0x10f30c b 0x10f2c8 <_Z26F_DotProduct_3D_NormalisedR6RValueP9CInstanceS2_iPS_+0xac> */

/* ── FUNC 0x10f310 · F_MathAngleDifference(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x10f310 push {r4, r5, r6, lr} */
/* @0x10f314 vpush {d8} */
/* @0x10f318 mov r4, r0 */
/* @0x10f31c ldr r6, [sp, #0x18] */
/* @0x10f320 mov r1, #0 */
/* @0x10f324 mov r5, #0 */
/* @0x10f328 movt r5, #0x43b4 */
/* @0x10f32c mov r0, r6 */
/* @0x10f330 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f334 mov r1, #1 */
/* @0x10f338 vmov s16, r0 */
/* @0x10f33c mov r0, r6 */
/* @0x10f340 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10f344 mov r3, #0 */
/* @0x10f348 mov r1, r5 */
/* @0x10f34c str r3, [r4, #0xc] */
/* @0x10f350 vmov s12, r0 */
/* @0x10f354 vsub.f32 s12, s16, s12 */
/* @0x10f358 vmov r0, s12 */
/* @0x10f35c bl 0xb6790 <fmodf@plt> */
/* @0x10f360 vldr s15, [pc, #48] */
/* @0x10f364 mov r1, r5 */
/* @0x10f368 vmov s13, r0 */
/* @0x10f36c vadd.f32 s13, s13, s15 */
/* @0x10f370 vmov r0, s13 */
/* @0x10f374 bl 0xb6790 <fmodf@plt> */
/* @0x10f378 vldr s15, [pc, #28] */
/* @0x10f37c vmov s14, r0 */
/* @0x10f380 vsub.f32 s15, s14, s15 */
/* @0x10f384 vcvt.f64.f32 d6, s15 */
/* @0x10f388 vmov r2, r3, d6 */
/* @0x10f38c stm r4, {r2, r3} */
/* @0x10f390 vpop {d8} */
/* @0x10f394 pop {r4, r5, r6, pc} */
/* @0x10f398 strmi r0, [r7], #-0 */
/* @0x10f39c teqmi r4, #0 */

/* ── FUNC 0x10f3a0 · F_Typeof(RValue&, CInstance*, CInstance*, int, RValue*) · size=32 · insn=8 */
/* @0x10f3a0 push {r4, lr} */
/* @0x10f3a4 mov r4, r0 */
/* @0x10f3a8 ldr r0, [sp, #0x8] */
/* @0x10f3ac bl 0xce54c <_Z8KindNamePK6RValue> */
/* @0x10f3b0 mov r1, r0 */
/* @0x10f3b4 mov r0, r4 */
/* @0x10f3b8 pop {r4, lr} */
/* @0x10f3bc b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x10f3c0 · F_ArrayHeight2D(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x10f3c0 cmp r3, #1 */
/* @0x10f3c4 mov r3, #0 */
/* @0x10f3c8 str r3, [r0, #0xc] */
/* @0x10f3cc str r3, [r0] */
/* @0x10f3d0 str r3, [r0, #0x4] */
/* @0x10f3d4 bxne lr */
/* @0x10f3d8 ldr r2, [sp] */
/* @0x10f3dc ldr r3, [r2, #0xc] */
/* @0x10f3e0 cmp r3, #2 */
/* @0x10f3e4 bxne lr */
/* @0x10f3e8 ldr r3, [r2] */
/* @0x10f3ec cmp r3, #0 */
/* @0x10f3f0 ldrne r2, [r3, #0x10] */
/* @0x10f3f4 vmovne s15, r2 */
/* @0x10f3f8 vcvtne.f64.s32 d7, s15 */
/* @0x10f3fc vmovne r2, r3, d7 */
/* @0x10f400 stmne r0, {r2, r3} */
/* @0x10f404 bx lr */

/* ── FUNC 0x10f408 · F_ArrayGet2D(RValue&, CInstance*, CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x10f408 cmp r3, #3 */
/* @0x10f40c push {r3, r4, r5, r6, r7, lr} */
/* @0x10f410 mov r5, r0 */
/* @0x10f414 ldr r4, [sp, #0x18] */
/* @0x10f418 popne {r3, r4, r5, r6, r7, pc} */
/* @0x10f41c ldr r6, [r4, #0xc] */
/* @0x10f420 cmp r6, #2 */
/* @0x10f424 popne {r3, r4, r5, r6, r7, pc} */
/* @0x10f428 ldr r3, [r4] */
/* @0x10f42c cmp r3, #0 */
/* @0x10f430 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x10f434 mov r0, r4 */
/* @0x10f438 mov r1, #1 */
/* @0x10f43c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10f440 mov r1, r6 */
/* @0x10f444 mov r7, r0 */
/* @0x10f448 mov r0, r4 */
/* @0x10f44c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10f450 mov r2, #32000 */
/* @0x10f454 mov r1, r4 */
/* @0x10f458 mla r2, r2, r7, r0 */
/* @0x10f45c mov r0, r5 */
/* @0x10f460 pop {r3, r4, r5, r6, r7, lr} */
/* @0x10f464 b 0xd13bc <_Z10GET_RValueP6RValueS0_i> */

/* ── FUNC 0x10f468 · F_ArrayGet(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0x10f468 push {r4, r5, r6, lr} */
/* @0x10f46c mov r4, r0 */
/* @0x10f470 ldr r5, [sp, #0x10] */
/* @0x10f474 ldr r6, [pc, #0xa4] */
/* @0x10f478 ldr r3, [r5, #0xc] */
/* @0x10f47c add r6, pc, r6 */
/* @0x10f480 cmp r3, #2 */
/* @0x10f484 beq 0x10f4a0 <_Z10F_ArrayGetR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x10f488 mov r3, #0 */
/* @0x10f48c mov r2, #5 */
/* @0x10f490 str r3, [r4] */
/* @0x10f494 str r2, [r4, #0xc] */
/* @0x10f498 str r3, [r4, #0x4] */
/* @0x10f49c pop {r4, r5, r6, pc} */
/* @0x10f4a0 ldr r3, [r5] */
/* @0x10f4a4 cmp r3, #0 */
/* @0x10f4a8 beq 0x10f488 <_Z10F_ArrayGetR6RValueP9CInstanceS2_iPS_+0x20> */
/* @0x10f4ac mov r1, #1 */
/* @0x10f4b0 mov r0, r5 */
/* @0x10f4b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10f4b8 mov r1, r5 */
/* @0x10f4bc mov r2, r0 */
/* @0x10f4c0 mov r0, r4 */
/* @0x10f4c4 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x10f4c8 ldr r3, [pc, #0x54] */
/* @0x10f4cc ldr r3, [r6, r3] */
/* @0x10f4d0 ldrb r3, [r3] */
/* @0x10f4d4 cmp r3, #0 */
/* @0x10f4d8 popeq {r4, r5, r6, pc} */
/* @0x10f4dc ldr r0, [pc, #0x44] */
/* @0x10f4e0 ldr r1, [pc, #0x44] */
/* @0x10f4e4 ldr r2, [pc, #0x44] */
/* @0x10f4e8 ldr r0, [r6, r0] */
/* @0x10f4ec ldr r3, [pc, #0x40] */
/* @0x10f4f0 ldr r1, [r6, r1] */
/* @0x10f4f4 ldr r2, [r6, r2] */
/* @0x10f4f8 ldr r3, [r6, r3] */
/* @0x10f4fc ldr r12, [r0] */
/* @0x10f500 ldr r0, [pc, #0x30] */
/* @0x10f504 ldr r1, [r1] */
/* @0x10f508 ldr r2, [r2] */
/* @0x10f50c add r0, pc, r0 */
/* @0x10f510 ldr r3, [r3] */
/* @0x10f514 str r12, [sp, #0x10] */
/* @0x10f518 pop {r4, r5, r6, lr} */
/* @0x10f51c b 0xd547c <_Z7YYErrorPKcz> */
/* @0x10f520 .word 0x002e27d4 */
/* @0x10f524 .word 0xffffbf24 */
/* @0x10f528 .word 0xffffbf34 */
/* @0x10f52c .word 0xffffbf28 */
/* @0x10f530 .word 0xffffbf2c */
/* @0x10f534 .word 0xffffbf30 */
/* @0x10f538 eoreq r9, r2, r4, lsr #19 */

/* ── FUNC 0x10f53c · F_ArraySet(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x10f53c push {r4, lr} */
/* @0x10f540 cmp r3, #3 */
/* @0x10f544 ldr r4, [sp, #0x8] */
/* @0x10f548 ldr r3, [r4, #0xc] */
/* @0x10f54c beq 0x10f568 <_Z10F_ArraySetR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x10f550 cmp r3, #2 */
/* @0x10f554 beq 0x10f57c <_Z10F_ArraySetR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x10f558 ldr r0, [pc, #0x4c] */
/* @0x10f55c pop {r4, lr} */
/* @0x10f560 add r0, pc, r0 */
/* @0x10f564 b 0xd547c <_Z7YYErrorPKcz> */
/* @0x10f568 cmp r3, #2 */
/* @0x10f56c bne 0x10f558 <_Z10F_ArraySetR6RValueP9CInstanceS2_iPS_+0x1c> */
/* @0x10f570 ldr r3, [r4] */
/* @0x10f574 cmp r3, #0 */
/* @0x10f578 bne 0x10f58c <_Z10F_ArraySetR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x10f57c ldr r0, [pc, #0x2c] */
/* @0x10f580 pop {r4, lr} */
/* @0x10f584 add r0, pc, r0 */
/* @0x10f588 b 0xd547c <_Z7YYErrorPKcz> */
/* @0x10f58c mov r0, r4 */
/* @0x10f590 mov r1, #1 */
/* @0x10f594 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10f598 add r1, r4, #32 */
/* @0x10f59c mov r2, r0 */
/* @0x10f5a0 mov r0, r4 */
/* @0x10f5a4 pop {r4, lr} */
/* @0x10f5a8 b 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i> */
/* @0x10f5ac eoreq r9, r2, r0, lsl #19 */
/* @0x10f5b0 eoreq r9, r2, r4, lsl #19 */

/* ── FUNC 0x10f5b4 · F_ArraySet2D(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x10f5b4 cmp r3, #4 */
/* @0x10f5b8 push {r4, r5, r6, lr} */
/* @0x10f5bc ldr r4, [sp, #0x10] */
/* @0x10f5c0 beq 0x10f5e0 <_Z12F_ArraySet2DR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x10f5c4 ldr r3, [r4, #0xc] */
/* @0x10f5c8 cmp r3, #2 */
/* @0x10f5cc beq 0x10f5f8 <_Z12F_ArraySet2DR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x10f5d0 ldr r0, [pc, #0x64] */
/* @0x10f5d4 pop {r4, r5, r6, lr} */
/* @0x10f5d8 add r0, pc, r0 */
/* @0x10f5dc b 0xd547c <_Z7YYErrorPKcz> */
/* @0x10f5e0 ldr r5, [r4, #0xc] */
/* @0x10f5e4 cmp r5, #2 */
/* @0x10f5e8 bne 0x10f5d0 <_Z12F_ArraySet2DR6RValueP9CInstanceS2_iPS_+0x1c> */
/* @0x10f5ec ldr r3, [r4] */
/* @0x10f5f0 cmp r3, #0 */
/* @0x10f5f4 bne 0x10f608 <_Z12F_ArraySet2DR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x10f5f8 ldr r0, [pc, #0x40] */
/* @0x10f5fc pop {r4, r5, r6, lr} */
/* @0x10f600 add r0, pc, r0 */
/* @0x10f604 b 0xd547c <_Z7YYErrorPKcz> */
/* @0x10f608 mov r0, r4 */
/* @0x10f60c mov r1, #1 */
/* @0x10f610 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10f614 mov r1, r5 */
/* @0x10f618 mov r6, r0 */
/* @0x10f61c mov r0, r4 */
/* @0x10f620 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10f624 mov r2, #32000 */
/* @0x10f628 add r1, r4, #48 */
/* @0x10f62c mla r2, r2, r6, r0 */
/* @0x10f630 mov r0, r4 */
/* @0x10f634 pop {r4, r5, r6, lr} */
/* @0x10f638 b 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i> */
/* @0x10f63c eoreq r9, r2, r0, asr r9 */
/* @0x10f640 eoreq r9, r2, r4, asr r9 */

/* ── FUNC 0x10f644 · F_ArraySet2DPost(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x10f644 cmp r3, #4 */
/* @0x10f648 push {r3, r4, r5, r6, r7, lr} */
/* @0x10f64c mov r5, r0 */
/* @0x10f650 ldr r4, [sp, #0x18] */
/* @0x10f654 beq 0x10f674 <_Z16F_ArraySet2DPostR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x10f658 ldr r3, [r4, #0xc] */
/* @0x10f65c cmp r3, #2 */
/* @0x10f660 beq 0x10f68c <_Z16F_ArraySet2DPostR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x10f664 ldr r0, [pc, #0x78] */
/* @0x10f668 pop {r3, r4, r5, r6, r7, lr} */
/* @0x10f66c add r0, pc, r0 */
/* @0x10f670 b 0xd547c <_Z7YYErrorPKcz> */
/* @0x10f674 ldr r6, [r4, #0xc] */
/* @0x10f678 cmp r6, #2 */
/* @0x10f67c bne 0x10f664 <_Z16F_ArraySet2DPostR6RValueP9CInstanceS2_iPS_+0x20> */
/* @0x10f680 ldr r3, [r4] */
/* @0x10f684 cmp r3, #0 */
/* @0x10f688 bne 0x10f69c <_Z16F_ArraySet2DPostR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x10f68c ldr r0, [pc, #0x54] */
/* @0x10f690 pop {r3, r4, r5, r6, r7, lr} */
/* @0x10f694 add r0, pc, r0 */
/* @0x10f698 b 0xd547c <_Z7YYErrorPKcz> */
/* @0x10f69c mov r0, r4 */
/* @0x10f6a0 mov r1, #1 */
/* @0x10f6a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10f6a8 mov r1, r6 */
/* @0x10f6ac mov r6, #32000 */
/* @0x10f6b0 mov r7, r0 */
/* @0x10f6b4 mov r0, r4 */
/* @0x10f6b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10f6bc mov r1, r4 */
/* @0x10f6c0 mla r6, r6, r7, r0 */
/* @0x10f6c4 mov r0, r5 */
/* @0x10f6c8 mov r2, r6 */
/* @0x10f6cc bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x10f6d0 mov r0, r4 */
/* @0x10f6d4 mov r2, r6 */
/* @0x10f6d8 add r1, r4, #48 */
/* @0x10f6dc pop {r3, r4, r5, r6, r7, lr} */
/* @0x10f6e0 b 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i> */
/* @0x10f6e4 .word 0x002298bc */
/* @0x10f6e8 eoreq r9, r2, r0, asr #17 */

/* ── FUNC 0x10f6ec · anon_10f6ec · size=0 · insn=1 */
/* @0x10f6ec andeq r0, r0, r0 */

/* ── FUNC 0x10f6f0 · F_Mean(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=30 */
/* @0x10f6f0 push {r3, r4, r5, r6, r7, lr} */
/* @0x10f6f4 vpush {d8} */
/* @0x10f6f8 subs r5, r3, #0 */
/* @0x10f6fc mov r4, #0 */
/* @0x10f700 mov r7, r0 */
/* @0x10f704 ldr r6, [sp, #0x20] */
/* @0x10f708 str r4, [r0, #0xc] */
/* @0x10f70c str r4, [r0] */
/* @0x10f710 str r4, [r0, #0x4] */
/* @0x10f714 beq 0x10f75c <_Z6F_MeanR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x10f718 vldr d8, [pc, #72] */
/* @0x10f71c ble 0x10f740 <_Z6F_MeanR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x10f720 mov r1, r4 */
/* @0x10f724 mov r0, r6 */
/* @0x10f728 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10f72c add r4, r4, #1 */
/* @0x10f730 cmp r4, r5 */
/* @0x10f734 vmov d6, r0, r1 */
/* @0x10f738 vadd.f64 d8, d8, d6 */
/* @0x10f73c bne 0x10f720 <_Z6F_MeanR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x10f740 vmov s13, r5 */
/* @0x10f744 mov r3, #0 */
/* @0x10f748 str r3, [r7, #0xc] */
/* @0x10f74c vcvt.f64.s32 d7, s13 */
/* @0x10f750 vdiv.f64 d6, d8, d7 */
/* @0x10f754 vmov r2, r3, d6 */
/* @0x10f758 stm r7, {r2, r3} */
/* @0x10f75c vpop {d8} */
/* @0x10f760 pop {r3, r4, r5, r6, r7, pc} */
/* @0x10f764 nop */

/* ── FUNC 0x10f770 · F_Sqrt(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x10f770 push {r3, r4, r5, lr} */
/* @0x10f774 mov r4, #0 */
/* @0x10f778 ldr r3, [sp, #0x10] */
/* @0x10f77c mov r5, r0 */
/* @0x10f780 str r4, [r0, #0xc] */
/* @0x10f784 mov r1, r4 */
/* @0x10f788 mov r0, r3 */
/* @0x10f78c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10f790 vmov d7, r0, r1 */
/* @0x10f794 vcmpe.f64 d7, #0 */
/* @0x10f798 vmrs APSR_nzcv, fpscr */
/* @0x10f79c blt 0x10f7c0 <_Z6F_SqrtR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x10f7a0 vsqrt.f64 d7, d7 */
/* @0x10f7a4 vcmp.f64 d7, d7 */
/* @0x10f7a8 vmrs APSR_nzcv, fpscr */
/* @0x10f7ac bne 0x10f7d4 <_Z6F_SqrtR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x10f7b0 vmov r2, s14 */
/* @0x10f7b4 vmov r3, s15 */
/* @0x10f7b8 stm r5, {r2, r3} */
/* @0x10f7bc pop {r3, r4, r5, pc} */
/* @0x10f7c0 ldr r0, [pc, #0x18] */
/* @0x10f7c4 mov r1, r4 */
/* @0x10f7c8 pop {r3, r4, r5, lr} */
/* @0x10f7cc add r0, pc, r0 */
/* @0x10f7d0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x10f7d4 bl 0xb66f4 <sqrt@plt> */
/* @0x10f7d8 vmov d7, r0, r1 */
/* @0x10f7dc b 0x10f7b0 <_Z6F_SqrtR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x10f7e0 eoreq r9, r2, r12, lsr #15 */

/* ── FUNC 0x10f7e4 · F_StringFormat(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0x10f7e4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x10f7e8 sub sp, sp, #396 */
/* @0x10f7ec ldr r6, [pc, #0xbc] */
/* @0x10f7f0 mov r8, r0 */
/* @0x10f7f4 ldr r7, [sp, #0x1a8] */
/* @0x10f7f8 mov r1, #0 */
/* @0x10f7fc ldr r6, [pc, r6] */
/* @0x10f800 ldr r2, [r7, #0xc] */
/* @0x10f804 mov r0, r7 */
/* @0x10f808 ldr r3, [r6] */
/* @0x10f80c cmp r2, #1 */
/* @0x10f810 str r3, [sp, #0x184] */
/* @0x10f814 beq 0x10f898 <_Z14F_StringFormatR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x10f818 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10f81c mov r4, r0 */
/* @0x10f820 mov r5, r1 */
/* @0x10f824 mov r0, r7 */
/* @0x10f828 mov r1, #1 */
/* @0x10f82c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10f830 mov r1, #2 */
/* @0x10f834 mov r9, r0 */
/* @0x10f838 mov r0, r7 */
/* @0x10f83c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10f840 add r7, sp, #4 */
/* @0x10f844 ldr r1, [pc, #0x68] */
/* @0x10f848 add r1, pc, r1 */
/* @0x10f84c mov r3, r0 */
/* @0x10f850 add r2, r9, r0 */
/* @0x10f854 mov r0, r7 */
/* @0x10f858 bl 0xb6550 <sprintf@plt> */
/* @0x10f85c mov r2, r4 */
/* @0x10f860 add r4, sp, #132 */
/* @0x10f864 mov r1, r7 */
/* @0x10f868 mov r3, r5 */
/* @0x10f86c mov r0, r4 */
/* @0x10f870 bl 0xb6550 <sprintf@plt> */
/* @0x10f874 mov r0, r8 */
/* @0x10f878 mov r1, r4 */
/* @0x10f87c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x10f880 ldr r2, [sp, #0x184] */
/* @0x10f884 ldr r3, [r6] */
/* @0x10f888 cmp r2, r3 */
/* @0x10f88c bne 0x10f8ac <_Z14F_StringFormatR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x10f890 add sp, sp, #396 */
/* @0x10f894 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x10f898 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x10f89c mov r1, r0 */
/* @0x10f8a0 mov r0, r8 */
/* @0x10f8a4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x10f8a8 b 0x10f880 <_Z14F_StringFormatR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x10f8ac bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x10f8b0 eoreq lr, sp, r4, asr r1 */
/* @0x10f8b4 eoreq r9, r2, r8, asr r7 */

/* ── FUNC 0x10f8b8 · F_ArrayEquals(RValue&, CInstance*, CInstance*, int, RValue*) · size=336 · insn=84 */
/* @0x10f8b8 cmp r3, #2 */
/* @0x10f8bc push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x10f8c0 mov r10, r0 */
/* @0x10f8c4 ldr r3, [sp, #0x28] */
/* @0x10f8c8 beq 0x10f8dc <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x10f8cc ldr r0, [pc, #0x124] */
/* @0x10f8d0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x10f8d4 add r0, pc, r0 */
/* @0x10f8d8 b 0xd547c <_Z7YYErrorPKcz> */
/* @0x10f8dc ldr r2, [r3, #0xc] */
/* @0x10f8e0 bic r1, r2, #-16777216 */
/* @0x10f8e4 cmp r1, #2 */
/* @0x10f8e8 beq 0x10f914 <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x10f8ec cmp r2, #2 */
/* @0x10f8f0 beq 0x10f904 <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x10f8f4 ldr r0, [pc, #0x100] */
/* @0x10f8f8 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x10f8fc add r0, pc, r0 */
/* @0x10f900 b 0xd547c <_Z7YYErrorPKcz> */
/* @0x10f904 ldr r0, [pc, #0xf4] */
/* @0x10f908 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x10f90c add r0, pc, r0 */
/* @0x10f910 b 0xd547c <_Z7YYErrorPKcz> */
/* @0x10f914 ldr r1, [r3, #0x1c] */
/* @0x10f918 bic r1, r1, #-16777216 */
/* @0x10f91c cmp r1, #2 */
/* @0x10f920 bne 0x10f8ec <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x10f924 ldr r8, [r3] */
/* @0x10f928 ldr r9, [r3, #0x10] */
/* @0x10f92c ldr r2, [r8, #0x10] */
/* @0x10f930 ldr r3, [r9, #0x10] */
/* @0x10f934 cmp r3, r2 */
/* @0x10f938 bne 0x10f96c <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x10f93c cmp r3, #0 */
/* @0x10f940 movgt r7, #0 */
/* @0x10f944 ble 0x10f9e0 <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x10f948 ldr r1, [r8, #0x4] */
/* @0x10f94c lsl r2, r7, #3 */
/* @0x10f950 ldr r3, [r9, #0x4] */
/* @0x10f954 add r6, r1, r2 */
/* @0x10f958 add r0, r3, r2 */
/* @0x10f95c ldr r1, [r1, r7, lsl #3] */
/* @0x10f960 ldr r2, [r3, r7, lsl #3] */
/* @0x10f964 cmp r2, r1 */
/* @0x10f968 beq 0x10f988 <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x10f96c mov r3, #0 */
/* @0x10f970 mov r1, #13 */
/* @0x10f974 mov r2, r3 */
/* @0x10f978 str r1, [r10, #0xc] */
/* @0x10f97c str r3, [r10] */
/* @0x10f980 str r2, [r10, #0x4] */
/* @0x10f984 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x10f988 ldr r5, [r0, #0x4] */
/* @0x10f98c mov r4, #0 */
/* @0x10f990 ldr r11, [r6, #0x4] */
/* @0x10f994 b 0x10f9b4 <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x10f998 ldr r3, [pc, r3] */
/* @0x10f99c add r11, r11, #16 */
/* @0x10f9a0 ldrd r2, r3, [r3] */
/* @0x10f9a4 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x10f9a8 cmp r0, #0 */
/* @0x10f9ac bne 0x10f96c <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x10f9b0 ldr r2, [r6] */
/* @0x10f9b4 cmp r2, r4 */
/* @0x10f9b8 mov r0, r5 */
/* @0x10f9bc ldr r3, [pc, #0x40] */
/* @0x10f9c0 mov r1, r11 */
/* @0x10f9c4 add r5, r5, #16 */
/* @0x10f9c8 add r4, r4, #1 */
/* @0x10f9cc bgt 0x10f998 <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x10f9d0 ldr r3, [r8, #0x10] */
/* @0x10f9d4 add r7, r7, #1 */
/* @0x10f9d8 cmp r7, r3 */
/* @0x10f9dc blt 0x10f948 <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x10f9e0 mov r3, #13 */
/* @0x10f9e4 mov r2, #0 */
/* @0x10f9e8 str r3, [r10, #0xc] */
/* @0x10f9ec movt r2, #0x3ff0 */
/* @0x10f9f0 mov r3, #0 */
/* @0x10f9f4 b 0x10f97c <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x10f9f8 .word 0x002296d8 */
/* @0x10f9fc .word 0x002296d4 */
/* @0x10fa00 .word 0x002296f0 */
/* @0x10fa04 eoreq lr, sp, r0, lsl #7 */

/* ── FUNC 0x10fa08 · F_ArrayCopy(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x10fa08 cmp r3, #5 */
/* @0x10fa0c push {r4, r5, r6, r7, r8, lr} */
/* @0x10fa10 ldr r5, [sp, #0x18] */
/* @0x10fa14 beq 0x10fa28 <_Z11F_ArrayCopyR6RValueP9CInstanceS2_iPS_+0x20> */
/* @0x10fa18 ldr r0, [pc, #0xb8] */
/* @0x10fa1c pop {r4, r5, r6, r7, r8, lr} */
/* @0x10fa20 add r0, pc, r0 */
/* @0x10fa24 b 0xd547c <_Z7YYErrorPKcz> */
/* @0x10fa28 ldr r3, [r5, #0xc] */
/* @0x10fa2c bic r2, r3, #-16777216 */
/* @0x10fa30 cmp r2, #2 */
/* @0x10fa34 beq 0x10fa60 <_Z11F_ArrayCopyR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x10fa38 cmp r3, #2 */
/* @0x10fa3c beq 0x10fa50 <_Z11F_ArrayCopyR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x10fa40 ldr r0, [pc, #0x94] */
/* @0x10fa44 pop {r4, r5, r6, r7, r8, lr} */
/* @0x10fa48 add r0, pc, r0 */
/* @0x10fa4c b 0xd547c <_Z7YYErrorPKcz> */
/* @0x10fa50 ldr r0, [pc, #0x88] */
/* @0x10fa54 pop {r4, r5, r6, r7, r8, lr} */
/* @0x10fa58 add r0, pc, r0 */
/* @0x10fa5c b 0xd547c <_Z7YYErrorPKcz> */
/* @0x10fa60 ldr r2, [r5, #0x2c] */
/* @0x10fa64 bic r2, r2, #-16777216 */
/* @0x10fa68 cmp r2, #2 */
/* @0x10fa6c bne 0x10fa38 <_Z11F_ArrayCopyR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x10fa70 mov r1, #1 */
/* @0x10fa74 mov r0, r5 */
/* @0x10fa78 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10fa7c mov r1, #3 */
/* @0x10fa80 add r7, r5, #32 */
/* @0x10fa84 mov r8, r0 */
/* @0x10fa88 mov r0, r5 */
/* @0x10fa8c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10fa90 mov r1, #4 */
/* @0x10fa94 mov r6, r0 */
/* @0x10fa98 mov r0, r5 */
/* @0x10fa9c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10faa0 subs r4, r0, #1 */
/* @0x10faa4 popmi {r4, r5, r6, r7, r8, pc} */
/* @0x10faa8 add r1, r4, r6 */
/* @0x10faac mov r0, r7 */
/* @0x10fab0 bl 0xcede4 <_Z17ARRAY_RVAL_RValuePK6RValuei> */
/* @0x10fab4 add r2, r4, r8 */
/* @0x10fab8 sub r4, r4, #1 */
/* @0x10fabc subs r1, r0, #0 */
/* @0x10fac0 mov r0, r5 */
/* @0x10fac4 beq 0x10facc <_Z11F_ArrayCopyR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x10fac8 bl 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i> */
/* @0x10facc cmn r4, #1 */
/* @0x10fad0 bne 0x10faa8 <_Z11F_ArrayCopyR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x10fad4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x10fad8 eoreq r9, r2, r8, lsl #12 */
/* @0x10fadc eoreq r9, r2, r0, lsl #12 */
/* @0x10fae0 eoreq r9, r2, r12, lsl r6 */

/* ── FUNC 0x10fae4 · utf8_get_char · size=84 · insn=21 */
/* @0x10fae4 ldrb r3, [r0] */
/* @0x10fae8 tst r3, #128 */
/* @0x10faec beq 0x10fb30 <utf8_get_char+0x4c> */
/* @0x10faf0 tst r3, #32 */
/* @0x10faf4 bne 0x10fb0c <utf8_get_char+0x28> */
/* @0x10faf8 ldrb r0, [r0, #0x1] */
/* @0x10fafc and r3, r3, #31 */
/* @0x10fb00 and r0, r0, #63 */
/* @0x10fb04 add r0, r0, r3, lsl #6 */
/* @0x10fb08 bx lr */
/* @0x10fb0c ldrb r2, [r0, #0x1] */
/* @0x10fb10 ldrb r0, [r0, #0x2] */
/* @0x10fb14 and r2, r2, #63 */
/* @0x10fb18 and r0, r0, #63 */
/* @0x10fb1c lsl r2, r2, #6 */
/* @0x10fb20 add r3, r2, r3, lsl #12 */
/* @0x10fb24 add r0, r0, r3 */
/* @0x10fb28 uxth r0, r0 */
/* @0x10fb2c bx lr */
/* @0x10fb30 mov r0, r3 */
/* @0x10fb34 bx lr */

/* ── FUNC 0x10fb38 · utf8_extract_char · size=132 · insn=33 */
/* @0x10fb38 ldr r3, [r0] */
/* @0x10fb3c mov r1, r0 */
/* @0x10fb40 str r4, [sp, #-0x4]! */
/* @0x10fb44 ldrb r2, [r3] */
/* @0x10fb48 tst r2, #128 */
/* @0x10fb4c beq 0x10fb88 <utf8_extract_char+0x50> */
/* @0x10fb50 tst r2, #32 */
/* @0x10fb54 beq 0x10fb9c <utf8_extract_char+0x64> */
/* @0x10fb58 ldrb r4, [r3, #0x1] */
/* @0x10fb5c add r12, r3, #3 */
/* @0x10fb60 ldrb r0, [r3, #0x2] */
/* @0x10fb64 and r3, r4, #63 */
/* @0x10fb68 str r12, [r1] */
/* @0x10fb6c and r0, r0, #63 */
/* @0x10fb70 ldr r4, [sp], #4 */
/* @0x10fb74 lsl r3, r3, #6 */
/* @0x10fb78 add r2, r3, r2, lsl #12 */
/* @0x10fb7c add r0, r0, r2 */
/* @0x10fb80 uxth r0, r0 */
/* @0x10fb84 bx lr */
/* @0x10fb88 mov r0, r2 */
/* @0x10fb8c add r3, r3, #1 */
/* @0x10fb90 str r3, [r1] */
/* @0x10fb94 ldr r4, [sp], #4 */
/* @0x10fb98 bx lr */
/* @0x10fb9c ldrb r0, [r3, #0x1] */
/* @0x10fba0 and r2, r2, #31 */
/* @0x10fba4 add r3, r3, #2 */
/* @0x10fba8 ldr r4, [sp], #4 */
/* @0x10fbac and r0, r0, #63 */
/* @0x10fbb0 str r3, [r1] */
/* @0x10fbb4 add r0, r0, r2, lsl #6 */
/* @0x10fbb8 bx lr */

/* ── FUNC 0x10fbbc · utf8_strrchr · size=144 · insn=36 */
/* @0x10fbbc push {r4, r5, r6, r7, r8, lr} */
/* @0x10fbc0 sub sp, sp, #8 */
/* @0x10fbc4 mov r5, r0 */
/* @0x10fbc8 mov r6, r1 */
/* @0x10fbcc mov r8, r2 */
/* @0x10fbd0 bl 0xb6538 <strlen@plt> */
/* @0x10fbd4 adds r4, r5, r0 */
/* @0x10fbd8 addlo r7, sp, #4 */
/* @0x10fbdc blo 0x10fbec <utf8_strrchr+0x30> */
/* @0x10fbe0 b 0x10fc3c <utf8_strrchr+0x80> */
/* @0x10fbe4 cmp r4, r5 */
/* @0x10fbe8 blo 0x10fc3c <utf8_strrchr+0x80> */
/* @0x10fbec mov r0, r7 */
/* @0x10fbf0 str r4, [sp, #0x4] */
/* @0x10fbf4 bl 0x10fb38 <utf8_extract_char> */
/* @0x10fbf8 cmp r6, r0 */
/* @0x10fbfc beq 0x10fc40 <utf8_strrchr+0x84> */
/* @0x10fc00 cmp r8, r0 */
/* @0x10fc04 beq 0x10fc40 <utf8_strrchr+0x84> */
/* @0x10fc08 ldrsb r3, [r4] */
/* @0x10fc0c cmp r3, #0 */
/* @0x10fc10 subge r4, r4, #1 */
/* @0x10fc14 bge 0x10fbe4 <utf8_strrchr+0x28> */
/* @0x10fc18 sub r3, r4, #1 */
/* @0x10fc1c mov r4, r3 */
/* @0x10fc20 sub r3, r3, #1 */
/* @0x10fc24 ldrb r12, [r4] */
/* @0x10fc28 and r12, r12, #192 */
/* @0x10fc2c cmp r12, #128 */
/* @0x10fc30 beq 0x10fc1c <utf8_strrchr+0x60> */
/* @0x10fc34 cmp r4, r5 */
/* @0x10fc38 bhs 0x10fbec <utf8_strrchr+0x30> */
/* @0x10fc3c mov r4, #0 */
/* @0x10fc40 mov r0, r4 */
/* @0x10fc44 add sp, sp, #8 */
/* @0x10fc48 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x10fc4c · F_Ord(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x10fc4c push {r4, lr} */
/* @0x10fc50 sub sp, sp, #8 */
/* @0x10fc54 mov r4, r0 */
/* @0x10fc58 mov r1, #0 */
/* @0x10fc5c ldr r0, [sp, #0x10] */
/* @0x10fc60 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x10fc64 mov r3, #0 */
/* @0x10fc68 str r3, [r4, #0xc] */
/* @0x10fc6c cmp r0, #0 */
/* @0x10fc70 str r0, [sp, #0x4] */
/* @0x10fc74 beq 0x10fc84 <_Z5F_OrdR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x10fc78 ldrb r3, [r0] */
/* @0x10fc7c cmp r3, #0 */
/* @0x10fc80 bne 0x10fc98 <_Z5F_OrdR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x10fc84 mov r3, #0 */
/* @0x10fc88 str r3, [r4] */
/* @0x10fc8c str r3, [r4, #0x4] */
/* @0x10fc90 add sp, sp, #8 */
/* @0x10fc94 pop {r4, pc} */
/* @0x10fc98 add r0, sp, #4 */
/* @0x10fc9c bl 0x10fb38 <utf8_extract_char> */
/* @0x10fca0 vmov s15, r0 */
/* @0x10fca4 vcvt.f64.u32 d7, s15 */
/* @0x10fca8 vmov r0, r1, d7 */
/* @0x10fcac vmov r2, s14 */
/* @0x10fcb0 mov r3, r1 */
/* @0x10fcb4 stm r4, {r2, r3} */
/* @0x10fcb8 add sp, sp, #8 */
/* @0x10fcbc pop {r4, pc} */

/* ── FUNC 0x10fcc0 · F_StringCopy(RValue&, CInstance*, CInstance*, int, RValue*) · size=360 · insn=90 */
/* @0x10fcc0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x10fcc4 sub sp, sp, #12 */
/* @0x10fcc8 mov r1, #0 */
/* @0x10fccc mov r8, r0 */
/* @0x10fcd0 ldr r4, [sp, #0x30] */
/* @0x10fcd4 mov r0, r4 */
/* @0x10fcd8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x10fcdc mov r1, #1 */
/* @0x10fce0 mov r5, r0 */
/* @0x10fce4 mov r0, r4 */
/* @0x10fce8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10fcec mov r1, #2 */
/* @0x10fcf0 mov r7, r0 */
/* @0x10fcf4 mov r0, r4 */
/* @0x10fcf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10fcfc cmp r7, #0 */
/* @0x10fd00 subgt r7, r7, #1 */
/* @0x10fd04 movle r7, #0 */
/* @0x10fd08 cmp r5, #0 */
/* @0x10fd0c bic r6, r0, r0, asr #31 */
/* @0x10fd10 beq 0x10fdec <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x10fd14 cmp r7, #0 */
/* @0x10fd18 str r5, [sp, #0x4] */
/* @0x10fd1c beq 0x10fde4 <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x10fd20 add r5, sp, #4 */
/* @0x10fd24 mov r4, #0 */
/* @0x10fd28 add r4, r4, #1 */
/* @0x10fd2c mov r0, r5 */
/* @0x10fd30 bl 0x10fb38 <utf8_extract_char> */
/* @0x10fd34 cmp r4, r7 */
/* @0x10fd38 bne 0x10fd28 <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x10fd3c ldr r7, [sp, #0x4] */
/* @0x10fd40 cmp r6, #0 */
/* @0x10fd44 beq 0x10fe1c <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x10fd48 add r5, sp, #4 */
/* @0x10fd4c mov r4, #0 */
/* @0x10fd50 b 0x10fd5c <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x10fd54 cmp r4, r6 */
/* @0x10fd58 beq 0x10fdd0 <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x10fd5c mov r0, r5 */
/* @0x10fd60 add r4, r4, #1 */
/* @0x10fd64 bl 0x10fb38 <utf8_extract_char> */
/* @0x10fd68 cmp r0, #0 */
/* @0x10fd6c bne 0x10fd54 <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x10fd70 ldr r5, [sp, #0x4] */
/* @0x10fd74 sub r5, r5, #1 */
/* @0x10fd78 str r5, [sp, #0x4] */
/* @0x10fd7c rsb r5, r7, r5 */
/* @0x10fd80 add r11, r5, #1 */
/* @0x10fd84 mov r6, r5 */
/* @0x10fd88 mov r9, #1 */
/* @0x10fd8c mov r0, #12 */
/* @0x10fd90 str r9, [r8, #0xc] */
/* @0x10fd94 mov r10, #0 */
/* @0x10fd98 bl 0x27c524 <_Znwj> */
/* @0x10fd9c mov r4, r0 */
/* @0x10fda0 mov r0, r11 */
/* @0x10fda4 bl 0xcef4c <_Z7YYAlloci> */
/* @0x10fda8 str r9, [r4, #0x4] */
/* @0x10fdac str r5, [r4, #0x8] */
/* @0x10fdb0 mov r1, r7 */
/* @0x10fdb4 mov r2, r6 */
/* @0x10fdb8 str r0, [r4] */
/* @0x10fdbc str r4, [r8] */
/* @0x10fdc0 bl 0xb65bc <memcpy@plt> */
/* @0x10fdc4 strb r10, [r0, r6] */
/* @0x10fdc8 add sp, sp, #12 */
/* @0x10fdcc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x10fdd0 ldr r5, [sp, #0x4] */
/* @0x10fdd4 rsb r5, r7, r5 */
/* @0x10fdd8 add r11, r5, #1 */
/* @0x10fddc mov r6, r5 */
/* @0x10fde0 b 0x10fd88 <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x10fde4 mov r7, r5 */
/* @0x10fde8 b 0x10fd40 <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x10fdec mov r6, #1 */
/* @0x10fdf0 mov r0, #12 */
/* @0x10fdf4 str r6, [r8, #0xc] */
/* @0x10fdf8 bl 0x27c524 <_Znwj> */
/* @0x10fdfc mov r4, r0 */
/* @0x10fe00 mov r0, r6 */
/* @0x10fe04 bl 0xcef4c <_Z7YYAlloci> */
/* @0x10fe08 str r5, [r4, #0x8] */
/* @0x10fe0c stm r4, {r0, r6} */
/* @0x10fe10 str r4, [r8] */
/* @0x10fe14 strb r5, [r0] */
/* @0x10fe18 b 0x10fdc8 <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x10fe1c mov r11, #1 */
/* @0x10fe20 mov r5, r6 */
/* @0x10fe24 b 0x10fd88 <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0xc8> */
