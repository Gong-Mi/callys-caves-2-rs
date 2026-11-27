/* libyoyo.so 覆盖卡组 0074
 * 函数 0x13ebc8..0x140138，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x13ebc8 · F_ActionShowVideo(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x13ebc8 push {r3, r4, r5, lr} */
/* @0x13ebcc mov r1, #1 */
/* @0x13ebd0 ldr r4, [sp, #0x10] */
/* @0x13ebd4 mov r0, r4 */
/* @0x13ebd8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x13ebdc ldr r2, [pc, #0x5c] */
/* @0x13ebe0 ldr r3, [pc, #0x5c] */
/* @0x13ebe4 mov r1, #0 */
/* @0x13ebe8 ldr r2, [pc, r2] */
/* @0x13ebec ldr r3, [pc, r3] */
/* @0x13ebf0 mov r12, r0 */
/* @0x13ebf4 mov r0, r4 */
/* @0x13ebf8 eor lr, r12, #1 */
/* @0x13ebfc strb r12, [r2] */
/* @0x13ec00 strb lr, [r3] */
/* @0x13ec04 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13ec08 mov r1, #2 */
/* @0x13ec0c mov r5, r0 */
/* @0x13ec10 mov r0, r4 */
/* @0x13ec14 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x13ec18 mov r1, r0 */
/* @0x13ec1c mov r0, r5 */
/* @0x13ec20 bl 0x1dc774 <_Z17Splash_Show_MoviePKcb> */
/* @0x13ec24 subs r1, r0, #0 */
/* @0x13ec28 bne 0x13ec38 <_Z17F_ActionShowVideoR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x13ec2c ldr r0, [pc, #0x14] */
/* @0x13ec30 add r0, pc, r0 */
/* @0x13ec34 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x13ec38 pop {r3, r4, r5, lr} */
/* @0x13ec3c b 0x18c2c8 <_Z8IO_Clearv> */
/* @0x13ec40 eoreq pc, r10, r12, asr #28 */
/* @0x13ec44 eoreq pc, r10, r8, asr lr */
/* @0x13ec48 andseq sp, pc, r12, asr #9 */

/* ── FUNC 0x13ec4c · F_ActionEndGame(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x13ec4c b 0x1c9f50 <_Z15Command_EndGamev> */

/* ── FUNC 0x13ec50 · F_ActionRestartGame(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x13ec50 b 0x1c9f54 <_Z19Command_RestartGamev> */

/* ── FUNC 0x13ec54 · F_ActionSaveGame(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x13ec54 push {r3, lr} */
/* @0x13ec58 mov r1, #0 */
/* @0x13ec5c ldr r0, [sp, #0x8] */
/* @0x13ec60 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13ec64 pop {r3, lr} */
/* @0x13ec68 b 0x1d1468 <_Z16Command_SaveGamePKc> */

/* ── FUNC 0x13ec6c · F_ActionLoadGame(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x13ec6c push {r3, lr} */
/* @0x13ec70 mov r1, #0 */
/* @0x13ec74 ldr r0, [sp, #0x8] */
/* @0x13ec78 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13ec7c pop {r3, lr} */
/* @0x13ec80 b 0x1d14fc <_Z16Command_LoadGamePKc> */

/* ── FUNC 0x13ec84 · F_ActionIfEmpty(RValue&, CInstance*, CInstance*, int, RValue*) · size=172 · insn=43 */
/* @0x13ec84 push {r4, r5, r6, lr} */
/* @0x13ec88 vpush {d8} */
/* @0x13ec8c mov r3, #0 */
/* @0x13ec90 ldr r4, [sp, #0x18] */
/* @0x13ec94 mov r6, r1 */
/* @0x13ec98 str r3, [r0, #0xc] */
/* @0x13ec9c mov r1, r3 */
/* @0x13eca0 mov r5, r0 */
/* @0x13eca4 mov r0, r4 */
/* @0x13eca8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13ecac mov r1, #1 */
/* @0x13ecb0 vmov s17, r0 */
/* @0x13ecb4 mov r0, r4 */
/* @0x13ecb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13ecbc mov r1, #2 */
/* @0x13ecc0 vmov s16, r0 */
/* @0x13ecc4 mov r0, r4 */
/* @0x13ecc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13eccc ldr r3, [pc, #0x58] */
/* @0x13ecd0 ldr r3, [pc, r3] */
/* @0x13ecd4 ldrb r3, [r3] */
/* @0x13ecd8 cmp r3, #0 */
/* @0x13ecdc vldrne s14, [r6, #180] */
/* @0x13ece0 vldrne s15, [r6, #184] */
/* @0x13ece4 vaddne.f32 s17, s17, s14 */
/* @0x13ece8 vaddne.f32 s16, s16, s15 */
/* @0x13ecec cmp r0, #0 */
/* @0x13ecf0 vmov r1, s17 */
/* @0x13ecf4 mov r0, r6 */
/* @0x13ecf8 vmov r2, s16 */
/* @0x13ecfc beq 0x13ed24 <_Z15F_ActionIfEmptyR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x13ed00 bl 0x1caa1c <_Z15Command_IsEmptyP9CInstanceff> */
/* @0x13ed04 vmov s15, r0 */
/* @0x13ed08 vcvt.f64.u32 d7, s15 */
/* @0x13ed0c vmov r0, r1, d7 */
/* @0x13ed10 vmov r2, s14 */
/* @0x13ed14 mov r3, r1 */
/* @0x13ed18 stm r5, {r2, r3} */
/* @0x13ed1c vpop {d8} */
/* @0x13ed20 pop {r4, r5, r6, pc} */
/* @0x13ed24 bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff> */
/* @0x13ed28 b 0x13ed04 <_Z15F_ActionIfEmptyR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x13ed2c eoreq lr, r10, r12, ror #28 */

/* ── FUNC 0x13ed30 · F_ActionIfCollision(RValue&, CInstance*, CInstance*, int, RValue*) · size=204 · insn=51 */
/* @0x13ed30 push {r4, r5, r6, lr} */
/* @0x13ed34 vpush {d8} */
/* @0x13ed38 mov r3, #0 */
/* @0x13ed3c ldr r4, [sp, #0x18] */
/* @0x13ed40 mov r6, r1 */
/* @0x13ed44 str r3, [r0, #0xc] */
/* @0x13ed48 mov r1, r3 */
/* @0x13ed4c mov r5, r0 */
/* @0x13ed50 mov r0, r4 */
/* @0x13ed54 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13ed58 mov r1, #1 */
/* @0x13ed5c vmov s17, r0 */
/* @0x13ed60 mov r0, r4 */
/* @0x13ed64 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13ed68 mov r1, #2 */
/* @0x13ed6c vmov s16, r0 */
/* @0x13ed70 mov r0, r4 */
/* @0x13ed74 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13ed78 ldr r3, [pc, #0x78] */
/* @0x13ed7c ldr r3, [pc, r3] */
/* @0x13ed80 ldrb r3, [r3] */
/* @0x13ed84 cmp r3, #0 */
/* @0x13ed88 vldrne s14, [r6, #180] */
/* @0x13ed8c vldrne s15, [r6, #184] */
/* @0x13ed90 vaddne.f32 s17, s17, s14 */
/* @0x13ed94 mov r4, r0 */
/* @0x13ed98 mov r0, r6 */
/* @0x13ed9c vaddne.f32 s16, s16, s15 */
/* @0x13eda0 cmp r4, #0 */
/* @0x13eda4 vmov r1, s17 */
/* @0x13eda8 vmov r2, s16 */
/* @0x13edac bne 0x13edd4 <_Z19F_ActionIfCollisionR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x13edb0 bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff> */
/* @0x13edb4 str r4, [r5] */
/* @0x13edb8 cmp r0, #0 */
/* @0x13edbc moveq r3, #0 */
/* @0x13edc0 movne r3, r4 */
/* @0x13edc4 movteq r3, #0x3ff0 */
/* @0x13edc8 str r3, [r5, #0x4] */
/* @0x13edcc vpop {d8} */
/* @0x13edd0 pop {r4, r5, r6, pc} */
/* @0x13edd4 bl 0x1caa1c <_Z15Command_IsEmptyP9CInstanceff> */
/* @0x13edd8 cmp r0, #0 */
/* @0x13eddc movne r0, #0 */
/* @0x13ede0 moveq r3, #0 */
/* @0x13ede4 movne r3, r0 */
/* @0x13ede8 movteq r3, #0x3ff0 */
/* @0x13edec stm r5, {r0, r3} */
/* @0x13edf0 vpop {d8} */
/* @0x13edf4 pop {r4, r5, r6, pc} */
/* @0x13edf8 eoreq lr, r10, r0, asr #27 */

/* ── FUNC 0x13edfc · F_ActionIfNumber(RValue&, CInstance*, CInstance*, int, RValue*) · size=204 · insn=51 */
/* @0x13edfc push {r3, r4, r5, r6, r7, lr} */
/* @0x13ee00 vpush {d8} */
/* @0x13ee04 mov r1, #0 */
/* @0x13ee08 ldr r4, [sp, #0x20] */
/* @0x13ee0c mov r5, r0 */
/* @0x13ee10 mov r6, r1 */
/* @0x13ee14 mov r0, r4 */
/* @0x13ee18 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13ee1c mov r1, #1 */
/* @0x13ee20 mov r7, r0 */
/* @0x13ee24 mov r0, r4 */
/* @0x13ee28 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13ee2c vmov d8, r0, r1 */
/* @0x13ee30 mov r0, r4 */
/* @0x13ee34 mov r1, #2 */
/* @0x13ee38 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13ee3c str r6, [r5, #0xc] */
/* @0x13ee40 mov r4, r0 */
/* @0x13ee44 mov r0, r7 */
/* @0x13ee48 bl 0x1c8ed0 <_Z22Command_InstanceNumberi> */
/* @0x13ee4c cmp r4, #1 */
/* @0x13ee50 vmov s13, r0 */
/* @0x13ee54 vcvt.f64.s32 d7, s13 */
/* @0x13ee58 beq 0x13eea8 <_Z16F_ActionIfNumberR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x13ee5c cmp r4, #2 */
/* @0x13ee60 beq 0x13ee88 <_Z16F_ActionIfNumberR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x13ee64 vcmp.f64 d7, d8 */
/* @0x13ee68 vmrs APSR_nzcv, fpscr */
/* @0x13ee6c bne 0x13ee94 <_Z16F_ActionIfNumberR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x13ee70 mov r3, #0 */
/* @0x13ee74 movt r3, #0x3ff0 */
/* @0x13ee78 str r6, [r5] */
/* @0x13ee7c str r3, [r5, #0x4] */
/* @0x13ee80 vpop {d8} */
/* @0x13ee84 pop {r3, r4, r5, r6, r7, pc} */
/* @0x13ee88 vcmpe.f64 d8, d7 */
/* @0x13ee8c vmrs APSR_nzcv, fpscr */
/* @0x13ee90 bmi 0x13ee70 <_Z16F_ActionIfNumberR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x13ee94 mov r3, r6 */
/* @0x13ee98 str r6, [r5] */
/* @0x13ee9c str r3, [r5, #0x4] */
/* @0x13eea0 vpop {d8} */
/* @0x13eea4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x13eea8 vcmpe.f64 d8, d7 */
/* @0x13eeac mov r3, r6 */
/* @0x13eeb0 vmrs APSR_nzcv, fpscr */
/* @0x13eeb4 bgt 0x13ee74 <_Z16F_ActionIfNumberR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x13eeb8 str r6, [r5] */
/* @0x13eebc str r3, [r5, #0x4] */
/* @0x13eec0 vpop {d8} */
/* @0x13eec4 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x13eec8 · F_ActionIfObject(RValue&, CInstance*, CInstance*, int, RValue*) · size=188 · insn=47 */
/* @0x13eec8 push {r3, r4, r5, r6, r7, lr} */
/* @0x13eecc vpush {d8} */
/* @0x13eed0 mov r5, r0 */
/* @0x13eed4 ldr r4, [sp, #0x20] */
/* @0x13eed8 mov r6, r1 */
/* @0x13eedc mov r1, #0 */
/* @0x13eee0 mov r0, r4 */
/* @0x13eee4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13eee8 mov r1, #1 */
/* @0x13eeec mov r7, r0 */
/* @0x13eef0 mov r0, r4 */
/* @0x13eef4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13eef8 mov r1, #2 */
/* @0x13eefc vmov s16, r0 */
/* @0x13ef00 mov r0, r4 */
/* @0x13ef04 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13ef08 ldr r3, [pc, #0x70] */
/* @0x13ef0c ldr r3, [pc, r3] */
/* @0x13ef10 ldrb r3, [r3] */
/* @0x13ef14 cmp r3, #0 */
/* @0x13ef18 vmov s15, r0 */
/* @0x13ef1c beq 0x13ef68 <_Z16F_ActionIfObjectR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x13ef20 vldr s13, [r6, #180] */
/* @0x13ef24 vldr s14, [r6, #184] */
/* @0x13ef28 vadd.f32 s13, s16, s13 */
/* @0x13ef2c mov r1, r7 */
/* @0x13ef30 mov r0, r6 */
/* @0x13ef34 vadd.f32 s14, s15, s14 */
/* @0x13ef38 vmov r2, s13 */
/* @0x13ef3c vmov r3, s14 */
/* @0x13ef40 bl 0x1ca9f8 <_Z17Command_IsMeetingP9CInstanceiff> */
/* @0x13ef44 cmp r0, #0 */
/* @0x13ef48 mov r3, #0 */
/* @0x13ef4c str r3, [r5, #0xc] */
/* @0x13ef50 movne r0, r3 */
/* @0x13ef54 moveq r3, r0 */
/* @0x13ef58 movtne r3, #0x3ff0 */
/* @0x13ef5c stm r5, {r0, r3} */
/* @0x13ef60 vpop {d8} */
/* @0x13ef64 pop {r3, r4, r5, r6, r7, pc} */
/* @0x13ef68 mov r0, r6 */
/* @0x13ef6c mov r1, r7 */
/* @0x13ef70 vmov r2, s16 */
/* @0x13ef74 vmov r3, s15 */
/* @0x13ef78 bl 0x1ca9f8 <_Z17Command_IsMeetingP9CInstanceiff> */
/* @0x13ef7c b 0x13ef44 <_Z16F_ActionIfObjectR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x13ef80 eoreq lr, r10, r0, lsr r12 */

/* ── FUNC 0x13ef84 · F_ActionIfQuestion(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x13ef84 ldr r1, [pc, #0x98] */
/* @0x13ef88 mov r12, #16 */
/* @0x13ef8c push {r4, r5, lr} */
/* @0x13ef90 sub sp, sp, #20 */
/* @0x13ef94 mov r4, r0 */
/* @0x13ef98 add r1, pc, r1 */
/* @0x13ef9c mov r0, r12 */
/* @0x13efa0 movw r2, #0x4d6 */
/* @0x13efa4 mov r3, #1 */
/* @0x13efa8 str r12, [sp, #0x4] */
/* @0x13efac ldr r5, [sp, #0x20] */
/* @0x13efb0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x13efb4 add r1, sp, #8 */
/* @0x13efb8 mov r3, r5 */
/* @0x13efbc mov r5, #0 */
/* @0x13efc0 mov r2, r0 */
/* @0x13efc4 add r0, sp, #16 */
/* @0x13efc8 str r2, [sp, #0x8] */
/* @0x13efcc str r2, [r0, #-0x4]! */
/* @0x13efd0 strb r5, [r2] */
/* @0x13efd4 add r2, sp, #4 */
/* @0x13efd8 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x13efdc ldr r0, [sp, #0x8] */
/* @0x13efe0 bl 0x212da8 <_Z19String_Replace_HashPc> */
/* @0x13efe4 ldr r0, [pc, #0x3c] */
/* @0x13efe8 ldr r1, [sp, #0x8] */
/* @0x13efec str r5, [r4, #0xc] */
/* @0x13eff0 add r0, pc, r0 */
/* @0x13eff4 bl 0xf29a4 <_ZN10InputQuery8QuestionEPKcS1_> */
/* @0x13eff8 vmov s15, r0 */
/* @0x13effc vcvt.f64.s32 d7, s15 */
/* @0x13f000 vmov r0, r1, d7 */
/* @0x13f004 vmov r2, s14 */
/* @0x13f008 mov r3, r1 */
/* @0x13f00c stm r4, {r2, r3} */
/* @0x13f010 bl 0x18c2c8 <_Z8IO_Clearv> */
/* @0x13f014 ldr r0, [sp, #0x8] */
/* @0x13f018 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x13f01c add sp, sp, #20 */
/* @0x13f020 pop {r4, r5, pc} */
/* @0x13f024 eoreq r1, r0, r4, asr r9 */
/* @0x13f028 andseq pc, lr, r6, asr #22 */

/* ── FUNC 0x13f02c · F_ActionDrawVariable(RValue&, CInstance*, CInstance*, int, RValue*) · size=172 · insn=43 */
/* @0x13f02c push {r4, r5, r6, lr} */
/* @0x13f030 vpush {d8} */
/* @0x13f034 sub sp, sp, #8 */
/* @0x13f038 mov r6, r1 */
/* @0x13f03c ldr r4, [sp, #0x20] */
/* @0x13f040 mov r0, r4 */
/* @0x13f044 bl 0x111130 <_Z12YYGML_stringRK6RValue> */
/* @0x13f048 mov r1, #1 */
/* @0x13f04c mov r5, r0 */
/* @0x13f050 mov r0, r4 */
/* @0x13f054 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13f058 mov r1, #2 */
/* @0x13f05c vmov s16, r0 */
/* @0x13f060 mov r0, r4 */
/* @0x13f064 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13f068 ldr r3, [pc, #0x64] */
/* @0x13f06c ldr r3, [pc, r3] */
/* @0x13f070 ldrb r3, [r3] */
/* @0x13f074 cmp r3, #0 */
/* @0x13f078 mvn r3, #0 */
/* @0x13f07c vmov s15, r0 */
/* @0x13f080 bne 0x13f0ac <_Z20F_ActionDrawVariableR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x13f084 vmov r0, s16 */
/* @0x13f088 mov r2, r5 */
/* @0x13f08c str r3, [sp] */
/* @0x13f090 vmov r1, s15 */
/* @0x13f094 bl 0x172df8 <_Z12GR_Text_DrawffPKcii> */
/* @0x13f098 mov r0, r5 */
/* @0x13f09c add sp, sp, #8 */
/* @0x13f0a0 vpop {d8} */
/* @0x13f0a4 pop {r4, r5, r6, lr} */
/* @0x13f0a8 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x13f0ac vldr s14, [r6, #180] */
/* @0x13f0b0 vadd.f32 s14, s16, s14 */
/* @0x13f0b4 str r3, [sp] */
/* @0x13f0b8 mov r2, r5 */
/* @0x13f0bc vmov r0, s14 */
/* @0x13f0c0 vldr s14, [r6, #184] */
/* @0x13f0c4 vadd.f32 s14, s15, s14 */
/* @0x13f0c8 vmov r1, s14 */
/* @0x13f0cc bl 0x172df8 <_Z12GR_Text_DrawffPKcii> */
/* @0x13f0d0 b 0x13f098 <_Z20F_ActionDrawVariableR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x13f0d4 .word 0x002aead0 */

/* ── FUNC 0x13f0d8 · F_ActionDrawText(RValue&, CInstance*, CInstance*, int, RValue*) · size=228 · insn=57 */
/* @0x13f0d8 push {r4, r5, lr} */
/* @0x13f0dc vpush {d8} */
/* @0x13f0e0 mov r5, r1 */
/* @0x13f0e4 ldr r1, [pc, #0xc8] */
/* @0x13f0e8 sub sp, sp, #28 */
/* @0x13f0ec mov r12, #16 */
/* @0x13f0f0 movw r2, #0x7fb */
/* @0x13f0f4 mov r0, r12 */
/* @0x13f0f8 add r1, pc, r1 */
/* @0x13f0fc mov r3, #1 */
/* @0x13f100 str r12, [sp, #0xc] */
/* @0x13f104 ldr r4, [sp, #0x30] */
/* @0x13f108 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x13f10c add r1, sp, #16 */
/* @0x13f110 mov r2, #0 */
/* @0x13f114 mov r3, r0 */
/* @0x13f118 add r0, sp, #24 */
/* @0x13f11c str r3, [sp, #0x10] */
/* @0x13f120 str r3, [r0, #-0x4]! */
/* @0x13f124 strb r2, [r3] */
/* @0x13f128 mov r3, r4 */
/* @0x13f12c add r2, sp, #12 */
/* @0x13f130 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x13f134 ldr r0, [sp, #0x10] */
/* @0x13f138 bl 0x212da8 <_Z19String_Replace_HashPc> */
/* @0x13f13c mov r0, r4 */
/* @0x13f140 mov r1, #1 */
/* @0x13f144 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13f148 mov r1, #2 */
/* @0x13f14c vmov s16, r0 */
/* @0x13f150 mov r0, r4 */
/* @0x13f154 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13f158 ldr r3, [pc, #0x58] */
/* @0x13f15c mvn r1, #0 */
/* @0x13f160 ldr r2, [sp, #0x10] */
/* @0x13f164 ldr r3, [pc, r3] */
/* @0x13f168 ldrb r3, [r3] */
/* @0x13f16c str r1, [sp] */
/* @0x13f170 cmp r3, #0 */
/* @0x13f174 vldrne s13, [r5, #180] */
/* @0x13f178 vldrne s14, [r5, #184] */
/* @0x13f17c mov r3, r1 */
/* @0x13f180 vmov s15, r0 */
/* @0x13f184 vaddne.f32 s13, s16, s13 */
/* @0x13f188 vmoveq r0, s16 */
/* @0x13f18c vmoveq r1, s15 */
/* @0x13f190 vaddne.f32 s14, s15, s14 */
/* @0x13f194 vmovne r0, s13 */
/* @0x13f198 vmovne r1, s14 */
/* @0x13f19c bl 0x172df8 <_Z12GR_Text_DrawffPKcii> */
/* @0x13f1a0 ldr r0, [sp, #0x10] */
/* @0x13f1a4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x13f1a8 add sp, sp, #28 */
/* @0x13f1ac vpop {d8} */
/* @0x13f1b0 pop {r4, r5, pc} */
/* @0x13f1b4 .word 0x002017f4 */
/* @0x13f1b8 .word 0x002ae9d8 */

/* ── FUNC 0x13f1bc · F_ActionDrawScore(RValue&, CInstance*, CInstance*, int, RValue*) · size=432 · insn=108 */
/* @0x13f1bc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13f1c0 vpush {d8} */
/* @0x13f1c4 mov r7, #64 */
/* @0x13f1c8 ldr r4, [pc, #0x188] */
/* @0x13f1cc sub sp, sp, #92 */
/* @0x13f1d0 ldr r9, [pc, #0x184] */
/* @0x13f1d4 mov r0, r7 */
/* @0x13f1d8 ldr r4, [pc, r4] */
/* @0x13f1dc movw r2, #0x5a9 */
/* @0x13f1e0 add r9, pc, r9 */
/* @0x13f1e4 mov r3, #1 */
/* @0x13f1e8 ldr r12, [r4] */
/* @0x13f1ec mov r8, r1 */
/* @0x13f1f0 mov r1, r9 */
/* @0x13f1f4 ldr r5, [sp, #0x88] */
/* @0x13f1f8 str r7, [sp, #0x8] */
/* @0x13f1fc add r6, sp, #20 */
/* @0x13f200 str r12, [sp, #0x54] */
/* @0x13f204 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x13f208 add r3, r5, #32 */
/* @0x13f20c mov r1, #0 */
/* @0x13f210 mov r2, r0 */
/* @0x13f214 str r0, [sp, #0xc] */
/* @0x13f218 add r0, sp, #88 */
/* @0x13f21c str r2, [r0, #-0x48]! */
/* @0x13f220 strb r1, [r2] */
/* @0x13f224 add r1, sp, #12 */
/* @0x13f228 add r2, sp, #8 */
/* @0x13f22c bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x13f230 ldr r0, [sp, #0xc] */
/* @0x13f234 bl 0x212da8 <_Z19String_Replace_HashPc> */
/* @0x13f238 ldr r3, [pc, #0x120] */
/* @0x13f23c ldr r2, [pc, #0x120] */
/* @0x13f240 mov r1, r7 */
/* @0x13f244 ldr r3, [pc, r3] */
/* @0x13f248 mov r0, r6 */
/* @0x13f24c add r2, pc, r2 */
/* @0x13f250 ldr r3, [r3] */
/* @0x13f254 bl 0xb65c8 <snprintf@plt> */
/* @0x13f258 mov r0, r6 */
/* @0x13f25c bl 0xb6538 <strlen@plt> */
/* @0x13f260 ldr r10, [sp, #0xc] */
/* @0x13f264 mov r11, r0 */
/* @0x13f268 mov r0, r10 */
/* @0x13f26c bl 0xb6538 <strlen@plt> */
/* @0x13f270 ldr r3, [sp, #0x8] */
/* @0x13f274 mov r7, r0 */
/* @0x13f278 add r0, r11, r0 */
/* @0x13f27c add r0, r0, #1 */
/* @0x13f280 cmp r0, r3 */
/* @0x13f284 movle r0, r10 */
/* @0x13f288 bgt 0x13f320 <_Z17F_ActionDrawScoreR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x13f28c mov r1, r6 */
/* @0x13f290 add r0, r0, r7 */
/* @0x13f294 bl 0xb65a4 <strcpy@plt> */
/* @0x13f298 mov r1, #0 */
/* @0x13f29c mov r0, r5 */
/* @0x13f2a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13f2a4 mov r1, #1 */
/* @0x13f2a8 vmov s16, r0 */
/* @0x13f2ac mov r0, r5 */
/* @0x13f2b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13f2b4 ldr r3, [pc, #0xac] */
/* @0x13f2b8 mvn r1, #0 */
/* @0x13f2bc ldr r2, [sp, #0xc] */
/* @0x13f2c0 ldr r3, [pc, r3] */
/* @0x13f2c4 ldrb r3, [r3] */
/* @0x13f2c8 str r1, [sp] */
/* @0x13f2cc cmp r3, #0 */
/* @0x13f2d0 vldrne s13, [r8, #180] */
/* @0x13f2d4 vldrne s14, [r8, #184] */
/* @0x13f2d8 mov r3, r1 */
/* @0x13f2dc vmov s15, r0 */
/* @0x13f2e0 vaddne.f32 s13, s16, s13 */
/* @0x13f2e4 vmoveq r0, s16 */
/* @0x13f2e8 vmoveq r1, s15 */
/* @0x13f2ec vaddne.f32 s14, s15, s14 */
/* @0x13f2f0 vmovne r0, s13 */
/* @0x13f2f4 vmovne r1, s14 */
/* @0x13f2f8 bl 0x172df8 <_Z12GR_Text_DrawffPKcii> */
/* @0x13f2fc ldr r0, [sp, #0xc] */
/* @0x13f300 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x13f304 ldr r2, [sp, #0x54] */
/* @0x13f308 ldr r3, [r4] */
/* @0x13f30c cmp r2, r3 */
/* @0x13f310 bne 0x13f354 <_Z17F_ActionDrawScoreR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x13f314 add sp, sp, #92 */
/* @0x13f318 vpop {d8} */
/* @0x13f31c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x13f320 mov r3, #1 */
/* @0x13f324 mov r1, r9 */
/* @0x13f328 movw r2, #0x5b6 */
/* @0x13f32c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x13f330 ldr r1, [sp, #0xc] */
/* @0x13f334 add r2, r7, #1 */
/* @0x13f338 mov r10, r0 */
/* @0x13f33c bl 0xb65bc <memcpy@plt> */
/* @0x13f340 ldr r0, [sp, #0xc] */
/* @0x13f344 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x13f348 str r10, [sp, #0xc] */
/* @0x13f34c mov r0, r10 */
/* @0x13f350 b 0x13f28c <_Z17F_ActionDrawScoreR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x13f354 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x13f358 eoreq lr, r10, r8, ror r7 */
/* @0x13f35c eoreq r1, r0, r12, lsl #14 */
/* @0x13f360 eoreq pc, r10, r0, asr #16 */
/* @0x13f364 andseq r3, pc, r0, asr #5 */
/* @0x13f368 eoreq lr, r10, r12, ror r8 */

/* ── FUNC 0x13f36c · F_ActionDrawLife(RValue&, CInstance*, CInstance*, int, RValue*) · size=432 · insn=108 */
/* @0x13f36c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13f370 vpush {d8} */
/* @0x13f374 mov r12, #16 */
/* @0x13f378 ldr r4, [pc, #0x188] */
/* @0x13f37c sub sp, sp, #92 */
/* @0x13f380 ldr r9, [pc, #0x184] */
/* @0x13f384 mov r0, r12 */
/* @0x13f388 ldr r4, [pc, r4] */
/* @0x13f38c movw r2, #0x608 */
/* @0x13f390 add r9, pc, r9 */
/* @0x13f394 mov r3, #1 */
/* @0x13f398 ldr lr, [r4] */
/* @0x13f39c mov r7, r1 */
/* @0x13f3a0 mov r1, r9 */
/* @0x13f3a4 str r12, [sp, #0x8] */
/* @0x13f3a8 ldr r5, [sp, #0x88] */
/* @0x13f3ac add r6, sp, #20 */
/* @0x13f3b0 str lr, [sp, #0x54] */
/* @0x13f3b4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x13f3b8 add r3, r5, #32 */
/* @0x13f3bc mov r1, #0 */
/* @0x13f3c0 mov r2, r0 */
/* @0x13f3c4 str r0, [sp, #0xc] */
/* @0x13f3c8 add r0, sp, #88 */
/* @0x13f3cc str r2, [r0, #-0x48]! */
/* @0x13f3d0 strb r1, [r2] */
/* @0x13f3d4 add r1, sp, #12 */
/* @0x13f3d8 add r2, sp, #8 */
/* @0x13f3dc bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x13f3e0 ldr r0, [sp, #0xc] */
/* @0x13f3e4 bl 0x212da8 <_Z19String_Replace_HashPc> */
/* @0x13f3e8 ldr r3, [pc, #0x120] */
/* @0x13f3ec ldr r2, [pc, #0x120] */
/* @0x13f3f0 mov r1, #64 */
/* @0x13f3f4 ldr r3, [pc, r3] */
/* @0x13f3f8 mov r0, r6 */
/* @0x13f3fc add r2, pc, r2 */
/* @0x13f400 ldr r3, [r3] */
/* @0x13f404 bl 0xb65c8 <snprintf@plt> */
/* @0x13f408 mov r0, r6 */
/* @0x13f40c bl 0xb6538 <strlen@plt> */
/* @0x13f410 ldr r10, [sp, #0xc] */
/* @0x13f414 mov r11, r0 */
/* @0x13f418 mov r0, r10 */
/* @0x13f41c bl 0xb6538 <strlen@plt> */
/* @0x13f420 ldr r3, [sp, #0x8] */
/* @0x13f424 mov r8, r0 */
/* @0x13f428 add r0, r11, r0 */
/* @0x13f42c add r0, r0, #1 */
/* @0x13f430 cmp r0, r3 */
/* @0x13f434 movle r0, r10 */
/* @0x13f438 bgt 0x13f4d0 <_Z16F_ActionDrawLifeR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x13f43c mov r1, r6 */
/* @0x13f440 add r0, r0, r8 */
/* @0x13f444 bl 0xb65a4 <strcpy@plt> */
/* @0x13f448 mov r1, #0 */
/* @0x13f44c mov r0, r5 */
/* @0x13f450 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13f454 mov r1, #1 */
/* @0x13f458 vmov s16, r0 */
/* @0x13f45c mov r0, r5 */
/* @0x13f460 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13f464 ldr r3, [pc, #0xac] */
/* @0x13f468 mvn r1, #0 */
/* @0x13f46c ldr r2, [sp, #0xc] */
/* @0x13f470 ldr r3, [pc, r3] */
/* @0x13f474 ldrb r3, [r3] */
/* @0x13f478 str r1, [sp] */
/* @0x13f47c cmp r3, #0 */
/* @0x13f480 vldrne s13, [r7, #180] */
/* @0x13f484 vldrne s14, [r7, #184] */
/* @0x13f488 mov r3, r1 */
/* @0x13f48c vmov s15, r0 */
/* @0x13f490 vaddne.f32 s13, s16, s13 */
/* @0x13f494 vmoveq r0, s16 */
/* @0x13f498 vmoveq r1, s15 */
/* @0x13f49c vaddne.f32 s14, s15, s14 */
/* @0x13f4a0 vmovne r0, s13 */
/* @0x13f4a4 vmovne r1, s14 */
/* @0x13f4a8 bl 0x172df8 <_Z12GR_Text_DrawffPKcii> */
/* @0x13f4ac ldr r0, [sp, #0xc] */
/* @0x13f4b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x13f4b4 ldr r2, [sp, #0x54] */
/* @0x13f4b8 ldr r3, [r4] */
/* @0x13f4bc cmp r2, r3 */
/* @0x13f4c0 bne 0x13f504 <_Z16F_ActionDrawLifeR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x13f4c4 add sp, sp, #92 */
/* @0x13f4c8 vpop {d8} */
/* @0x13f4cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x13f4d0 mov r3, #1 */
/* @0x13f4d4 mov r1, r9 */
/* @0x13f4d8 movw r2, #0x615 */
/* @0x13f4dc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x13f4e0 ldr r1, [sp, #0xc] */
/* @0x13f4e4 add r2, r8, #1 */
/* @0x13f4e8 mov r10, r0 */
/* @0x13f4ec bl 0xb65bc <memcpy@plt> */
/* @0x13f4f0 ldr r0, [sp, #0xc] */
/* @0x13f4f4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x13f4f8 str r10, [sp, #0xc] */
/* @0x13f4fc mov r0, r10 */
/* @0x13f500 b 0x13f43c <_Z16F_ActionDrawLifeR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x13f504 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x13f508 eoreq lr, r10, r8, asr #11 */
/* @0x13f50c eoreq r1, r0, r12, asr r5 */
/* @0x13f510 .word 0x002affdc */
/* @0x13f514 andseq r3, pc, r0, lsl r1 */
/* @0x13f518 eoreq lr, r10, r12, asr #13 */

/* ── FUNC 0x13f51c · F_ActionHighscoreShow(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x13f51c push {r4, r5, lr} */
/* @0x13f520 sub sp, sp, #76 */
/* @0x13f524 ldr lr, [pc, #0x74] */
/* @0x13f528 add r5, sp, #8 */
/* @0x13f52c mov r3, #4 */
/* @0x13f530 mov r12, #0 */
/* @0x13f534 ldr lr, [pc, lr] */
/* @0x13f538 str r12, [sp, #0x14] */
/* @0x13f53c ldr r4, [lr] */
/* @0x13f540 ldr lr, [r4, #0x10] */
/* @0x13f544 ldr r4, [r4, #0x14] */
/* @0x13f548 str r5, [sp] */
/* @0x13f54c asr lr, lr, #1 */
/* @0x13f550 str r12, [sp, #0x24] */
/* @0x13f554 sub r5, lr, #100 */
/* @0x13f558 asr r4, r4, #1 */
/* @0x13f55c add lr, lr, #100 */
/* @0x13f560 sub r4, r4, #100 */
/* @0x13f564 vmov s10, r5 */
/* @0x13f568 str r12, [sp, #0x34] */
/* @0x13f56c vmov s15, r4 */
/* @0x13f570 str r12, [sp, #0x44] */
/* @0x13f574 vcvt.f64.s32 d5, s10 */
/* @0x13f578 vstr d5, [sp, #8] */
/* @0x13f57c vmov s11, lr */
/* @0x13f580 vcvt.f64.s32 d6, s15 */
/* @0x13f584 vcvt.f64.s32 d7, s11 */
/* @0x13f588 vstr d6, [sp, #24] */
/* @0x13f58c vstr d7, [sp, #40] */
/* @0x13f590 vstr d7, [sp, #56] */
/* @0x13f594 bl 0x1269fc <_Z15F_DrawHighscoreR6RValueP9CInstanceS2_iPS_> */
/* @0x13f598 add sp, sp, #76 */
/* @0x13f59c pop {r4, r5, pc} */
/* @0x13f5a0 .word 0x002ae3f4 */

/* ── FUNC 0x13f5a4 · F_ActionHighscoreClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x13f5a4 b 0x1dc2d8 <_Z15HighScore_Clearv> */

/* ── FUNC 0x13f5a8 · F_ActionDrawLifeImages(RValue&, CInstance*, CInstance*, int, RValue*) · size=328 · insn=82 */
/* @0x13f5a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13f5ac vpush {d8, d9} */
/* @0x13f5b0 sub sp, sp, #28 */
/* @0x13f5b4 mov r9, r1 */
/* @0x13f5b8 mov r1, #0 */
/* @0x13f5bc ldr r4, [sp, #0x50] */
/* @0x13f5c0 mov r0, r4 */
/* @0x13f5c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13f5c8 mov r1, #1 */
/* @0x13f5cc vmov s17, r0 */
/* @0x13f5d0 mov r0, r4 */
/* @0x13f5d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13f5d8 mov r1, #2 */
/* @0x13f5dc vmov s16, r0 */
/* @0x13f5e0 mov r0, r4 */
/* @0x13f5e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13f5e8 mov r4, r0 */
/* @0x13f5ec bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x13f5f0 cmp r0, #0 */
/* @0x13f5f4 bne 0x13f604 <_Z22F_ActionDrawLifeImagesR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x13f5f8 add sp, sp, #28 */
/* @0x13f5fc vpop {d8, d9} */
/* @0x13f600 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x13f604 mov r0, r4 */
/* @0x13f608 ldr r11, [pc, #0xd8] */
/* @0x13f60c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x13f610 ldr r11, [pc, r11] */
/* @0x13f614 ldr r3, [r11] */
/* @0x13f618 cmp r3, #0 */
/* @0x13f61c mov r7, r0 */
/* @0x13f620 ldr r10, [r0, #0x1c] */
/* @0x13f624 ble 0x13f5f8 <_Z22F_ActionDrawLifeImagesR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x13f628 ldr r8, [pc, #0xbc] */
/* @0x13f62c mov r4, #0 */
/* @0x13f630 mov r6, #1065353216 */
/* @0x13f634 mov r5, r4 */
/* @0x13f638 ldr r8, [pc, r8] */
/* @0x13f63c vldr s18, [pc, #160] */
/* @0x13f640 b 0x13f698 <_Z22F_ActionDrawLifeImagesR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x13f644 vldr s14, [r9, #180] */
/* @0x13f648 mvn r3, #-16777216 */
/* @0x13f64c str r6, [sp] */
/* @0x13f650 vstr s18, [sp, #8] */
/* @0x13f654 str r3, [sp, #0xc] */
/* @0x13f658 vadd.f32 s14, s17, s14 */
/* @0x13f65c str r6, [sp, #0x4] */
/* @0x13f660 vmov s13, r4 */
/* @0x13f664 str r6, [sp, #0x10] */
/* @0x13f668 vldr s15, [r9, #184] */
/* @0x13f66c vadd.f32 s15, s16, s15 */
/* @0x13f670 vmov r3, s15 */
/* @0x13f674 vcvt.f32.s32 s15, s13 */
/* @0x13f678 vadd.f32 s15, s14, s15 */
/* @0x13f67c vmov r2, s15 */
/* @0x13f680 bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */
/* @0x13f684 ldr r3, [r11] */
/* @0x13f688 add r5, r5, #1 */
/* @0x13f68c add r4, r4, r10 */
/* @0x13f690 cmp r3, r5 */
/* @0x13f694 ble 0x13f5f8 <_Z22F_ActionDrawLifeImagesR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x13f698 ldrb r2, [r8] */
/* @0x13f69c mov r1, #0 */
/* @0x13f6a0 mov r0, r7 */
/* @0x13f6a4 vmov r3, s16 */
/* @0x13f6a8 cmp r2, r1 */
/* @0x13f6ac bne 0x13f644 <_Z22F_ActionDrawLifeImagesR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x13f6b0 vmov s13, r4 */
/* @0x13f6b4 mvn r1, #-16777216 */
/* @0x13f6b8 str r6, [sp] */
/* @0x13f6bc vstr s18, [sp, #8] */
/* @0x13f6c0 vcvt.f32.s32 s15, s13 */
/* @0x13f6c4 str r1, [sp, #0xc] */
/* @0x13f6c8 str r6, [sp, #0x4] */
/* @0x13f6cc mov r1, r2 */
/* @0x13f6d0 str r6, [sp, #0x10] */
/* @0x13f6d4 vadd.f32 s15, s15, s17 */
/* @0x13f6d8 vmov r2, s15 */
/* @0x13f6dc bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */
/* @0x13f6e0 b 0x13f684 <_Z22F_ActionDrawLifeImagesR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x13f6e4 andeq r0, r0, r0 */
/* @0x13f6e8 eoreq pc, r10, r0, asr #27 */
/* @0x13f6ec eoreq lr, r10, r4, lsl #10 */

/* ── FUNC 0x13f6f0 · F_ActionDrawHealth(RValue&, CInstance*, CInstance*, int, RValue*) · size=452 · insn=113 */
/* @0x13f6f0 push {r4, r5, r6, r7, r8, lr} */
/* @0x13f6f4 vpush {d8, d9} */
/* @0x13f6f8 sub sp, sp, #32 */
/* @0x13f6fc mov r7, r1 */
/* @0x13f700 mov r1, #0 */
/* @0x13f704 ldr r4, [sp, #0x48] */
/* @0x13f708 ldr r5, [pc, #0x190] */
/* @0x13f70c mov r0, r4 */
/* @0x13f710 add r5, pc, r5 */
/* @0x13f714 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13f718 mov r1, #1 */
/* @0x13f71c vmov s19, r0 */
/* @0x13f720 mov r0, r4 */
/* @0x13f724 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13f728 mov r1, #2 */
/* @0x13f72c vmov s18, r0 */
/* @0x13f730 mov r0, r4 */
/* @0x13f734 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13f738 mov r1, #3 */
/* @0x13f73c vmov s17, r0 */
/* @0x13f740 mov r0, r4 */
/* @0x13f744 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13f748 mov r1, #4 */
/* @0x13f74c vmov s16, r0 */
/* @0x13f750 mov r0, r4 */
/* @0x13f754 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13f758 mov r1, #5 */
/* @0x13f75c mov r8, r0 */
/* @0x13f760 mov r0, r4 */
/* @0x13f764 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13f768 mov r1, #4 */
/* @0x13f76c mov r6, r0 */
/* @0x13f770 mov r0, r4 */
/* @0x13f774 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x13f778 sub r3, r8, #2 */
/* @0x13f77c cmp r3, #14 */
/* @0x13f780 movhi r8, #0 */
/* @0x13f784 mov r4, r0 */
/* @0x13f788 ldrls r2, [pc, #0x114] */
/* @0x13f78c addls r2, pc, r2 */
/* @0x13f790 ldrls r8, [r2, r3, lsl #2] */
/* @0x13f794 cmp r6, #17 */
/* @0x13f798 bhi 0x13f824 <_Z18F_ActionDrawHealthR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x13f79c ldr r3, [pc, #0x104] */
/* @0x13f7a0 add r3, pc, r3 */
/* @0x13f7a4 add r3, r3, r6, lsl #2 */
/* @0x13f7a8 ldr r12, [r3, #0x3c] */
/* @0x13f7ac ldr r2, [r3, #0x84] */
/* @0x13f7b0 ldr r3, [r3, #0xcc] */
/* @0x13f7b4 ldr r1, [pc, #0xf0] */
/* @0x13f7b8 cmp r6, #2 */
/* @0x13f7bc movge r3, r12 */
/* @0x13f7c0 movge r2, r12 */
/* @0x13f7c4 ldr r1, [r5, r1] */
/* @0x13f7c8 ldrb lr, [r1] */
/* @0x13f7cc cmp lr, #0 */
/* @0x13f7d0 bne 0x13f834 <_Z18F_ActionDrawHealthR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x13f7d4 ldr r7, [pc, #0xd4] */
/* @0x13f7d8 mov r6, #1 */
/* @0x13f7dc vmov r0, s19 */
/* @0x13f7e0 vmov r1, s18 */
/* @0x13f7e4 ldr r5, [r5, r7] */
/* @0x13f7e8 vldr d7, [r5] */
/* @0x13f7ec vcvt.f32.f64 s14, d7 */
/* @0x13f7f0 str r2, [sp, #0xc] */
/* @0x13f7f4 str r3, [sp, #0x10] */
/* @0x13f7f8 stmib sp, {r8, r12} */
/* @0x13f7fc str lr, [sp, #0x14] */
/* @0x13f800 str r4, [sp, #0x18] */
/* @0x13f804 str r6, [sp, #0x1c] */
/* @0x13f808 vmov r2, s17 */
/* @0x13f80c vstr s14, [sp] */
/* @0x13f810 vmov r3, s16 */
/* @0x13f814 bl 0x16c0d8 <_Z17GR_Draw_Healthbarfffffjjjjibb> */
/* @0x13f818 add sp, sp, #32 */
/* @0x13f81c vpop {d8, d9} */
/* @0x13f820 pop {r4, r5, r6, r7, r8, pc} */
/* @0x13f824 mov r3, #0 */
/* @0x13f828 mov r2, r3 */
/* @0x13f82c mov r12, r3 */
/* @0x13f830 b 0x13f7b4 <_Z18F_ActionDrawHealthR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x13f834 vldr s12, [r7, #180] */
/* @0x13f838 vldr s13, [r7, #184] */
/* @0x13f83c vadd.f32 s19, s19, s12 */
/* @0x13f840 ldr r6, [pc, #0x68] */
/* @0x13f844 mov lr, #0 */
/* @0x13f848 mov r1, #1 */
/* @0x13f84c ldr r5, [r5, r6] */
/* @0x13f850 vldr d7, [r5] */
/* @0x13f854 str r2, [sp, #0xc] */
/* @0x13f858 str r3, [sp, #0x10] */
/* @0x13f85c str r1, [sp, #0x1c] */
/* @0x13f860 stmib sp, {r8, r12} */
/* @0x13f864 str r4, [sp, #0x18] */
/* @0x13f868 str lr, [sp, #0x14] */
/* @0x13f86c vadd.f32 s12, s17, s12 */
/* @0x13f870 vmov r0, s19 */
/* @0x13f874 vadd.f32 s18, s18, s13 */
/* @0x13f878 vmov r2, s12 */
/* @0x13f87c vadd.f32 s13, s16, s13 */
/* @0x13f880 vmov r1, s18 */
/* @0x13f884 vcvt.f32.f64 s14, d7 */
/* @0x13f888 vmov r3, s13 */
/* @0x13f88c vstr s14, [sp] */
/* @0x13f890 bl 0x16c0d8 <_Z17GR_Draw_Healthbarfffffjjjjibb> */
/* @0x13f894 add sp, sp, #32 */
/* @0x13f898 vpop {d8, d9} */
/* @0x13f89c pop {r4, r5, r6, r7, r8, pc} */
/* @0x13f8a0 eoreq r2, r11, r0, asr #10 */
/* @0x13f8a4 eoreq sp, r1, r8, lsl r2 */
/* @0x13f8a8 eoreq sp, r1, r4, lsl #4 */
/* @0x13f8ac .word 0xffffbeec */
/* @0x13f8b0 .word 0xffffd788 */

/* ── FUNC 0x13f8b4 · F_ActionPartSystCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x13f8b4 push {r3, r4, r5, lr} */
/* @0x13f8b8 ldr r4, [pc, #0x90] */
/* @0x13f8bc ldr r5, [sp, #0x10] */
/* @0x13f8c0 ldr r4, [pc, r4] */
/* @0x13f8c4 ldr r3, [r4] */
/* @0x13f8c8 cmp r3, #0 */
/* @0x13f8cc movge r0, r3 */
/* @0x13f8d0 blt 0x13f938 <_Z22F_ActionPartSystCreateR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x13f8d4 bl 0x1a4180 <_Z20ParticleSystem_Cleari> */
/* @0x13f8d8 mov r1, #0 */
/* @0x13f8dc mov r0, r5 */
/* @0x13f8e0 ldr r4, [r4] */
/* @0x13f8e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13f8e8 mov r1, r0 */
/* @0x13f8ec mov r0, r4 */
/* @0x13f8f0 bl 0x1a47d4 <_Z20ParticleSystem_Depthif> */
/* @0x13f8f4 ldr r2, [pc, #0x58] */
/* @0x13f8f8 mvn r1, #0 */
/* @0x13f8fc ldr r2, [pc, r2] */
/* @0x13f900 sub r3, r2, #4 */
/* @0x13f904 add r2, r2, #60 */
/* @0x13f908 str r1, [r3, #0x4]! */
/* @0x13f90c cmp r3, r2 */
/* @0x13f910 bne 0x13f908 <_Z22F_ActionPartSystCreateR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x13f914 ldr r2, [pc, #0x3c] */
/* @0x13f918 mvn r1, #0 */
/* @0x13f91c ldr r2, [pc, r2] */
/* @0x13f920 sub r3, r2, #4 */
/* @0x13f924 add r2, r2, #60 */
/* @0x13f928 str r1, [r3, #0x4]! */
/* @0x13f92c cmp r3, r2 */
/* @0x13f930 bne 0x13f928 <_Z22F_ActionPartSystCreateR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x13f934 pop {r3, r4, r5, pc} */
/* @0x13f938 mvn r0, #0 */
/* @0x13f93c mov r1, #1 */
/* @0x13f940 bl 0x1a42dc <_Z21ParticleSystem_Createib> */
/* @0x13f944 mov r3, r0 */
/* @0x13f948 str r3, [r4] */
/* @0x13f94c b 0x13f8d4 <_Z22F_ActionPartSystCreateR6RValueP9CInstanceS2_iPS_+0x20> */
/* @0x13f950 eoreq pc, r10, r12, lsl r11 */
/* @0x13f954 eoreq pc, r10, r4, ror #21 */
/* @0x13f958 eoreq pc, r10, r8, asr #21 */

/* ── FUNC 0x13f95c · F_ActionPartSystDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x13f95c push {r4, lr} */
/* @0x13f960 ldr r4, [pc, #0x1c] */
/* @0x13f964 ldr r4, [pc, r4] */
/* @0x13f968 ldr r0, [r4] */
/* @0x13f96c cmp r0, #0 */
/* @0x13f970 blt 0x13f978 <_Z23F_ActionPartSystDestroyR6RValueP9CInstanceS2_iPS_+0x1c> */
/* @0x13f974 bl 0x1a454c <_Z22ParticleSystem_Destroyi> */
/* @0x13f978 mvn r3, #0 */
/* @0x13f97c str r3, [r4] */
/* @0x13f980 pop {r4, pc} */
/* @0x13f984 eoreq pc, r10, r8, ror r10 */

/* ── FUNC 0x13f988 · F_ActionPartSystClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x13f988 ldr r3, [pc, #0x10] */
/* @0x13f98c ldr r3, [pc, r3] */
/* @0x13f990 ldr r0, [r3] */
/* @0x13f994 cmp r0, #0 */
/* @0x13f998 bxlt lr */
/* @0x13f99c b 0x1a40d4 <_Z30ParticleSystem_Particles_Cleari> */
/* @0x13f9a0 eoreq pc, r10, r0, asr r10 */

/* ── FUNC 0x13f9a4 · F_ActionPartTypeCreateOld(RValue&, CInstance*, CInstance*, int, RValue*) · size=252 · insn=63 */
/* @0x13f9a4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13f9a8 sub sp, sp, #12 */
/* @0x13f9ac mov r1, #0 */
/* @0x13f9b0 ldr r5, [pc, #0xe0] */
/* @0x13f9b4 ldr r4, [sp, #0x30] */
/* @0x13f9b8 mov r0, r4 */
/* @0x13f9bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13f9c0 mov r1, #1 */
/* @0x13f9c4 mov r6, r0 */
/* @0x13f9c8 mov r0, r4 */
/* @0x13f9cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13f9d0 mov r1, #2 */
/* @0x13f9d4 mov r10, r0 */
/* @0x13f9d8 mov r0, r4 */
/* @0x13f9dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13f9e0 mov r1, #3 */
/* @0x13f9e4 mov r9, r0 */
/* @0x13f9e8 mov r0, r4 */
/* @0x13f9ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13f9f0 mov r1, #4 */
/* @0x13f9f4 mov r8, r0 */
/* @0x13f9f8 mov r0, r4 */
/* @0x13f9fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13fa00 mov r1, #5 */
/* @0x13fa04 mov r7, r0 */
/* @0x13fa08 mov r0, r4 */
/* @0x13fa0c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13fa10 ldr r5, [pc, r5] */
/* @0x13fa14 ldr r3, [r5] */
/* @0x13fa18 cmp r3, #0 */
/* @0x13fa1c mov r11, r0 */
/* @0x13fa20 blt 0x13fa84 <_Z25F_ActionPartTypeCreateOldR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x13fa24 ldr r5, [pc, #0x70] */
/* @0x13fa28 ldr r5, [pc, r5] */
/* @0x13fa2c ldr r4, [r5, r6, lsl #2] */
/* @0x13fa30 cmp r4, #0 */
/* @0x13fa34 blt 0x13fa74 <_Z25F_ActionPartTypeCreateOldR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x13fa38 mov r1, r10 */
/* @0x13fa3c mov r0, r4 */
/* @0x13fa40 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x13fa44 mov r1, r9 */
/* @0x13fa48 mov r2, r8 */
/* @0x13fa4c mov r3, #0 */
/* @0x13fa50 mov r0, r4 */
/* @0x13fa54 str r3, [sp] */
/* @0x13fa58 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x13fa5c mov r0, r4 */
/* @0x13fa60 mov r1, r7 */
/* @0x13fa64 mov r2, r11 */
/* @0x13fa68 add sp, sp, #12 */
/* @0x13fa6c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13fa70 b 0x1a35d8 <_Z19ParticleType_Color2ijj> */
/* @0x13fa74 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x13fa78 mov r4, r0 */
/* @0x13fa7c str r0, [r5, r6, lsl #2] */
/* @0x13fa80 b 0x13fa38 <_Z25F_ActionPartTypeCreateOldR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x13fa84 mvn r0, #0 */
/* @0x13fa88 mov r1, #1 */
/* @0x13fa8c bl 0x1a42dc <_Z21ParticleSystem_Createib> */
/* @0x13fa90 str r0, [r5] */
/* @0x13fa94 b 0x13fa24 <_Z25F_ActionPartTypeCreateOldR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x13fa98 eoreq pc, r10, r12, asr #19 */
/* @0x13fa9c .word 0x002af9b8 */

/* ── FUNC 0x13faa0 · F_ActionPartTypeCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=264 · insn=66 */
/* @0x13faa0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13faa4 sub sp, sp, #12 */
/* @0x13faa8 mov r1, #0 */
/* @0x13faac ldr r5, [pc, #0xec] */
/* @0x13fab0 ldr r4, [sp, #0x30] */
/* @0x13fab4 mov r0, r4 */
/* @0x13fab8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13fabc mov r1, #1 */
/* @0x13fac0 mov r6, r0 */
/* @0x13fac4 mov r0, r4 */
/* @0x13fac8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13facc mov r1, #2 */
/* @0x13fad0 mov r10, r0 */
/* @0x13fad4 mov r0, r4 */
/* @0x13fad8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13fadc mov r1, #3 */
/* @0x13fae0 mov r9, r0 */
/* @0x13fae4 mov r0, r4 */
/* @0x13fae8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13faec mov r1, #4 */
/* @0x13faf0 mov r8, r0 */
/* @0x13faf4 mov r0, r4 */
/* @0x13faf8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13fafc mov r1, #5 */
/* @0x13fb00 mov r7, r0 */
/* @0x13fb04 mov r0, r4 */
/* @0x13fb08 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13fb0c ldr r5, [pc, r5] */
/* @0x13fb10 ldr r3, [r5] */
/* @0x13fb14 cmp r3, #0 */
/* @0x13fb18 mov r11, r0 */
/* @0x13fb1c blt 0x13fb8c <_Z22F_ActionPartTypeCreateR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x13fb20 ldr r5, [pc, #0x7c] */
/* @0x13fb24 ldr r5, [pc, r5] */
/* @0x13fb28 ldr r4, [r5, r6, lsl #2] */
/* @0x13fb2c cmp r4, #0 */
/* @0x13fb30 blt 0x13fb7c <_Z22F_ActionPartTypeCreateR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x13fb34 mov r1, r10 */
/* @0x13fb38 mov r0, r4 */
/* @0x13fb3c bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x13fb40 mov r3, #0 */
/* @0x13fb44 mov r1, r9 */
/* @0x13fb48 str r3, [sp] */
/* @0x13fb4c mov r0, r4 */
/* @0x13fb50 mov r2, #1 */
/* @0x13fb54 bl 0x1a31e0 <_Z19ParticleType_Spriteiibbb> */
/* @0x13fb58 mov r12, #0 */
/* @0x13fb5c mov r0, r4 */
/* @0x13fb60 mov r1, r8 */
/* @0x13fb64 mov r2, r7 */
/* @0x13fb68 mov r3, r11 */
/* @0x13fb6c str r12, [sp, #0x30] */
/* @0x13fb70 add sp, sp, #12 */
/* @0x13fb74 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13fb78 b 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x13fb7c bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x13fb80 mov r4, r0 */
/* @0x13fb84 str r0, [r5, r6, lsl #2] */
/* @0x13fb88 b 0x13fb34 <_Z22F_ActionPartTypeCreateR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x13fb8c mvn r0, #0 */
/* @0x13fb90 mov r1, #1 */
/* @0x13fb94 bl 0x1a42dc <_Z21ParticleSystem_Createib> */
/* @0x13fb98 str r0, [r5] */
/* @0x13fb9c b 0x13fb20 <_Z22F_ActionPartTypeCreateR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x13fba0 .word 0x002af8d0 */
/* @0x13fba4 .word 0x002af8bc */

/* ── FUNC 0x13fba8 · F_ActionPartTypeColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=240 · insn=60 */
/* @0x13fba8 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13fbac mov r1, #0 */
/* @0x13fbb0 ldr r4, [sp, #0x28] */
/* @0x13fbb4 ldr r5, [pc, #0xd4] */
/* @0x13fbb8 mov r0, r4 */
/* @0x13fbbc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13fbc0 mov r1, #1 */
/* @0x13fbc4 mov r6, r0 */
/* @0x13fbc8 mov r0, r4 */
/* @0x13fbcc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13fbd0 mov r1, #2 */
/* @0x13fbd4 mov r10, r0 */
/* @0x13fbd8 mov r0, r4 */
/* @0x13fbdc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13fbe0 mov r1, #3 */
/* @0x13fbe4 mov r9, r0 */
/* @0x13fbe8 mov r0, r4 */
/* @0x13fbec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13fbf0 mov r1, #4 */
/* @0x13fbf4 mov r8, r0 */
/* @0x13fbf8 mov r0, r4 */
/* @0x13fbfc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13fc00 mov r1, #5 */
/* @0x13fc04 mov r7, r0 */
/* @0x13fc08 mov r0, r4 */
/* @0x13fc0c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13fc10 ldr r5, [pc, r5] */
/* @0x13fc14 ldr r3, [r5] */
/* @0x13fc18 cmp r3, #0 */
/* @0x13fc1c mov r11, r0 */
/* @0x13fc20 blt 0x13fc7c <_Z21F_ActionPartTypeColorR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x13fc24 ldr r5, [pc, #0x68] */
/* @0x13fc28 ldr r5, [pc, r5] */
/* @0x13fc2c ldr r4, [r5, r6, lsl #2] */
/* @0x13fc30 cmp r4, #0 */
/* @0x13fc34 blt 0x13fc6c <_Z21F_ActionPartTypeColorR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x13fc38 cmp r10, #0 */
/* @0x13fc3c mov r1, r9 */
/* @0x13fc40 mov r2, r8 */
/* @0x13fc44 mov r0, r4 */
/* @0x13fc48 beq 0x13fc64 <_Z21F_ActionPartTypeColorR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x13fc4c bl 0x1a35d8 <_Z19ParticleType_Color2ijj> */
/* @0x13fc50 mov r0, r4 */
/* @0x13fc54 mov r1, r7 */
/* @0x13fc58 mov r2, r11 */
/* @0x13fc5c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13fc60 b 0x1a36a4 <_Z19ParticleType_Alpha2iff> */
/* @0x13fc64 bl 0x1a34f4 <_Z22ParticleType_Color_Mixijj> */
/* @0x13fc68 b 0x13fc50 <_Z21F_ActionPartTypeColorR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x13fc6c bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x13fc70 mov r4, r0 */
/* @0x13fc74 str r0, [r5, r6, lsl #2] */
/* @0x13fc78 b 0x13fc38 <_Z21F_ActionPartTypeColorR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x13fc7c mvn r0, #0 */
/* @0x13fc80 mov r1, #1 */
/* @0x13fc84 bl 0x1a42dc <_Z21ParticleSystem_Createib> */
/* @0x13fc88 str r0, [r5] */
/* @0x13fc8c b 0x13fc24 <_Z21F_ActionPartTypeColorR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x13fc90 eoreq pc, r10, r12, asr #15 */
/* @0x13fc94 .word 0x002af7b8 */

/* ── FUNC 0x13fc98 · F_ActionPartTypeLife(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0x13fc98 push {r3, r4, r5, r6, r7, lr} */
/* @0x13fc9c mov r1, #0 */
/* @0x13fca0 ldr r5, [sp, #0x18] */
/* @0x13fca4 ldr r4, [pc, #0x88] */
/* @0x13fca8 mov r0, r5 */
/* @0x13fcac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13fcb0 mov r1, #1 */
/* @0x13fcb4 mov r6, r0 */
/* @0x13fcb8 mov r0, r5 */
/* @0x13fcbc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13fcc0 mov r1, #2 */
/* @0x13fcc4 mov r7, r0 */
/* @0x13fcc8 mov r0, r5 */
/* @0x13fccc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13fcd0 ldr r4, [pc, r4] */
/* @0x13fcd4 ldr r3, [r4] */
/* @0x13fcd8 cmp r3, #0 */
/* @0x13fcdc mov r5, r0 */
/* @0x13fce0 blt 0x13fd20 <_Z20F_ActionPartTypeLifeR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x13fce4 ldr r4, [pc, #0x4c] */
/* @0x13fce8 ldr r4, [pc, r4] */
/* @0x13fcec ldr r0, [r4, r6, lsl #2] */
/* @0x13fcf0 cmp r0, #0 */
/* @0x13fcf4 blt 0x13fd08 <_Z20F_ActionPartTypeLifeR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x13fcf8 mov r1, r7 */
/* @0x13fcfc mov r2, r5 */
/* @0x13fd00 pop {r3, r4, r5, r6, r7, lr} */
/* @0x13fd04 b 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x13fd08 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x13fd0c mov r1, r7 */
/* @0x13fd10 mov r2, r5 */
/* @0x13fd14 str r0, [r4, r6, lsl #2] */
/* @0x13fd18 pop {r3, r4, r5, r6, r7, lr} */
/* @0x13fd1c b 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x13fd20 mvn r0, #0 */
/* @0x13fd24 mov r1, #1 */
/* @0x13fd28 bl 0x1a42dc <_Z21ParticleSystem_Createib> */
/* @0x13fd2c str r0, [r4] */
/* @0x13fd30 b 0x13fce4 <_Z20F_ActionPartTypeLifeR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x13fd34 eoreq pc, r10, r12, lsl #14 */
/* @0x13fd38 .word 0x002af6f8 */

/* ── FUNC 0x13fd3c · F_ActionPartTypeSpeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=252 · insn=63 */
/* @0x13fd3c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13fd40 sub sp, sp, #12 */
/* @0x13fd44 mov r1, #0 */
/* @0x13fd48 ldr r5, [pc, #0xe0] */
/* @0x13fd4c ldr r4, [sp, #0x30] */
/* @0x13fd50 mov r0, r4 */
/* @0x13fd54 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13fd58 mov r1, #1 */
/* @0x13fd5c mov r6, r0 */
/* @0x13fd60 mov r0, r4 */
/* @0x13fd64 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13fd68 mov r1, #2 */
/* @0x13fd6c mov r10, r0 */
/* @0x13fd70 mov r0, r4 */
/* @0x13fd74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13fd78 mov r1, #5 */
/* @0x13fd7c mov r9, r0 */
/* @0x13fd80 mov r0, r4 */
/* @0x13fd84 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13fd88 mov r1, #3 */
/* @0x13fd8c mov r8, r0 */
/* @0x13fd90 mov r0, r4 */
/* @0x13fd94 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13fd98 mov r1, #4 */
/* @0x13fd9c mov r7, r0 */
/* @0x13fda0 mov r0, r4 */
/* @0x13fda4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13fda8 ldr r5, [pc, r5] */
/* @0x13fdac ldr r3, [r5] */
/* @0x13fdb0 cmp r3, #0 */
/* @0x13fdb4 mov r11, r0 */
/* @0x13fdb8 blt 0x13fe1c <_Z21F_ActionPartTypeSpeedR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x13fdbc ldr r5, [pc, #0x70] */
/* @0x13fdc0 ldr r5, [pc, r5] */
/* @0x13fdc4 ldr r4, [r5, r6, lsl #2] */
/* @0x13fdc8 cmp r4, #0 */
/* @0x13fdcc blt 0x13fe0c <_Z21F_ActionPartTypeSpeedR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x13fdd0 mov r5, #0 */
/* @0x13fdd4 mov r1, r10 */
/* @0x13fdd8 mov r2, r9 */
/* @0x13fddc eor r3, r8, #-2147483648 */
/* @0x13fde0 mov r0, r4 */
/* @0x13fde4 str r5, [sp] */
/* @0x13fde8 bl 0x1a3368 <_Z18ParticleType_Speediffff> */
/* @0x13fdec str r5, [sp, #0x30] */
/* @0x13fdf0 mov r3, r5 */
/* @0x13fdf4 mov r0, r4 */
/* @0x13fdf8 mov r1, r7 */
/* @0x13fdfc mov r2, r11 */
/* @0x13fe00 add sp, sp, #12 */
/* @0x13fe04 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13fe08 b 0x1a33b4 <_Z22ParticleType_Directioniffff> */
/* @0x13fe0c bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x13fe10 mov r4, r0 */
/* @0x13fe14 str r0, [r5, r6, lsl #2] */
/* @0x13fe18 b 0x13fdd0 <_Z21F_ActionPartTypeSpeedR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x13fe1c mvn r0, #0 */
/* @0x13fe20 mov r1, #1 */
/* @0x13fe24 bl 0x1a42dc <_Z21ParticleSystem_Createib> */
/* @0x13fe28 str r0, [r5] */
/* @0x13fe2c b 0x13fdbc <_Z21F_ActionPartTypeSpeedR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x13fe30 eoreq pc, r10, r4, lsr r6 */
/* @0x13fe34 eoreq pc, r10, r0, lsr #12 */

/* ── FUNC 0x13fe38 · F_ActionPartTypeGravity(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0x13fe38 push {r3, r4, r5, r6, r7, lr} */
/* @0x13fe3c mov r1, #0 */
/* @0x13fe40 ldr r5, [sp, #0x18] */
/* @0x13fe44 ldr r4, [pc, #0x88] */
/* @0x13fe48 mov r0, r5 */
/* @0x13fe4c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13fe50 mov r1, #1 */
/* @0x13fe54 mov r6, r0 */
/* @0x13fe58 mov r0, r5 */
/* @0x13fe5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13fe60 mov r1, #2 */
/* @0x13fe64 mov r7, r0 */
/* @0x13fe68 mov r0, r5 */
/* @0x13fe6c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13fe70 ldr r4, [pc, r4] */
/* @0x13fe74 ldr r3, [r4] */
/* @0x13fe78 cmp r3, #0 */
/* @0x13fe7c mov r5, r0 */
/* @0x13fe80 blt 0x13fec0 <_Z23F_ActionPartTypeGravityR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x13fe84 ldr r4, [pc, #0x4c] */
/* @0x13fe88 ldr r4, [pc, r4] */
/* @0x13fe8c ldr r0, [r4, r6, lsl #2] */
/* @0x13fe90 cmp r0, #0 */
/* @0x13fe94 blt 0x13fea8 <_Z23F_ActionPartTypeGravityR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x13fe98 mov r1, r7 */
/* @0x13fe9c mov r2, r5 */
/* @0x13fea0 pop {r3, r4, r5, r6, r7, lr} */
/* @0x13fea4 b 0x1a3454 <_Z20ParticleType_Gravityiff> */
/* @0x13fea8 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x13feac mov r1, r7 */
/* @0x13feb0 mov r2, r5 */
/* @0x13feb4 str r0, [r4, r6, lsl #2] */
/* @0x13feb8 pop {r3, r4, r5, r6, r7, lr} */
/* @0x13febc b 0x1a3454 <_Z20ParticleType_Gravityiff> */
/* @0x13fec0 mvn r0, #0 */
/* @0x13fec4 mov r1, #1 */
/* @0x13fec8 bl 0x1a42dc <_Z21ParticleSystem_Createib> */
/* @0x13fecc str r0, [r4] */
/* @0x13fed0 b 0x13fe84 <_Z23F_ActionPartTypeGravityR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x13fed4 eoreq pc, r10, r12, ror #10 */
/* @0x13fed8 eoreq pc, r10, r8, asr r5 */

/* ── FUNC 0x13fedc · F_ActionPartTypeSecondary(RValue&, CInstance*, CInstance*, int, RValue*) · size=208 · insn=52 */
/* @0x13fedc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x13fee0 mov r1, #0 */
/* @0x13fee4 ldr r4, [sp, #0x20] */
/* @0x13fee8 ldr r5, [pc, #0xb4] */
/* @0x13feec mov r0, r4 */
/* @0x13fef0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13fef4 mov r1, #2 */
/* @0x13fef8 mov r6, r0 */
/* @0x13fefc mov r0, r4 */
/* @0x13ff00 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13ff04 mov r1, #1 */
/* @0x13ff08 mov r9, r0 */
/* @0x13ff0c mov r0, r4 */
/* @0x13ff10 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13ff14 mov r1, #4 */
/* @0x13ff18 mov r8, r0 */
/* @0x13ff1c mov r0, r4 */
/* @0x13ff20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13ff24 mov r1, #3 */
/* @0x13ff28 mov r7, r0 */
/* @0x13ff2c mov r0, r4 */
/* @0x13ff30 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13ff34 ldr r5, [pc, r5] */
/* @0x13ff38 ldr r3, [r5] */
/* @0x13ff3c cmp r3, #0 */
/* @0x13ff40 mov r10, r0 */
/* @0x13ff44 blt 0x13ff90 <_Z25F_ActionPartTypeSecondaryR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x13ff48 ldr r4, [pc, #0x58] */
/* @0x13ff4c ldr r4, [pc, r4] */
/* @0x13ff50 ldr r5, [r4, r6, lsl #2] */
/* @0x13ff54 cmp r5, #0 */
/* @0x13ff58 blt 0x13ff80 <_Z25F_ActionPartTypeSecondaryR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x13ff5c mov r1, r9 */
/* @0x13ff60 ldr r2, [r4, r8, lsl #2] */
/* @0x13ff64 mov r0, r5 */
/* @0x13ff68 bl 0x1a32f0 <_Z17ParticleType_Stepiii> */
/* @0x13ff6c mov r0, r5 */
/* @0x13ff70 mov r1, r7 */
/* @0x13ff74 ldr r2, [r4, r10, lsl #2] */
/* @0x13ff78 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x13ff7c b 0x1a332c <_Z18ParticleType_Deathiii> */
/* @0x13ff80 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x13ff84 mov r5, r0 */
/* @0x13ff88 str r0, [r4, r6, lsl #2] */
/* @0x13ff8c b 0x13ff5c <_Z25F_ActionPartTypeSecondaryR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x13ff90 mvn r0, #0 */
/* @0x13ff94 mov r1, #1 */
/* @0x13ff98 bl 0x1a42dc <_Z21ParticleSystem_Createib> */
/* @0x13ff9c str r0, [r5] */
/* @0x13ffa0 b 0x13ff48 <_Z25F_ActionPartTypeSecondaryR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x13ffa4 eoreq pc, r10, r8, lsr #9 */
/* @0x13ffa8 mlaeq r10, r4, r4, pc */

/* ── FUNC 0x13ffac · F_ActionPartEmitCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=244 · insn=61 */
/* @0x13ffac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13ffb0 sub sp, sp, #20 */
/* @0x13ffb4 mov r1, #0 */
/* @0x13ffb8 ldr r5, [pc, #0xd8] */
/* @0x13ffbc ldr r4, [sp, #0x38] */
/* @0x13ffc0 mov r0, r4 */
/* @0x13ffc4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13ffc8 mov r1, #1 */
/* @0x13ffcc mov r6, r0 */
/* @0x13ffd0 mov r0, r4 */
/* @0x13ffd4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13ffd8 mov r1, #2 */
/* @0x13ffdc mov r9, r0 */
/* @0x13ffe0 mov r0, r4 */
/* @0x13ffe4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13ffe8 mov r1, #3 */
/* @0x13ffec mov r8, r0 */
/* @0x13fff0 mov r0, r4 */
/* @0x13fff4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13fff8 mov r1, #4 */
/* @0x13fffc mov r7, r0 */
/* @0x140000 mov r0, r4 */
/* @0x140004 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x140008 mov r1, #5 */
/* @0x14000c mov r10, r0 */
/* @0x140010 mov r0, r4 */
/* @0x140014 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x140018 ldr r5, [pc, r5] */
/* @0x14001c ldr r3, [r5] */
/* @0x140020 cmp r3, #0 */
/* @0x140024 mov r11, r0 */
/* @0x140028 movge r0, r3 */
/* @0x14002c blt 0x140080 <_Z22F_ActionPartEmitCreateR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x140030 ldr r4, [pc, #0x64] */
/* @0x140034 ldr r4, [pc, r4] */
/* @0x140038 ldr r1, [r4, r6, lsl #2] */
/* @0x14003c cmp r1, #0 */
/* @0x140040 blt 0x14006c <_Z22F_ActionPartEmitCreateR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x140044 mov r12, #0 */
/* @0x140048 str r10, [sp] */
/* @0x14004c str r11, [sp, #0x4] */
/* @0x140050 mov r2, r8 */
/* @0x140054 str r9, [sp, #0x8] */
/* @0x140058 mov r3, r7 */
/* @0x14005c str r12, [sp, #0xc] */
/* @0x140060 bl 0x1a394c <_Z29ParticleSystem_Emitter_Regioniiffffii> */
/* @0x140064 add sp, sp, #20 */
/* @0x140068 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x14006c bl 0x1a39b4 <_Z29ParticleSystem_Emitter_Createi> */
/* @0x140070 mov r1, r0 */
/* @0x140074 ldr r0, [r5] */
/* @0x140078 str r1, [r4, r6, lsl #2] */
/* @0x14007c b 0x140044 <_Z22F_ActionPartEmitCreateR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x140080 mvn r0, #0 */
/* @0x140084 mov r1, #1 */
/* @0x140088 bl 0x1a42dc <_Z21ParticleSystem_Createib> */
/* @0x14008c mov r3, r0 */
/* @0x140090 str r3, [r5] */
/* @0x140094 b 0x140030 <_Z22F_ActionPartEmitCreateR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x140098 eoreq pc, r10, r4, asr #7 */
/* @0x14009c .word 0x002af3b0 */

/* ── FUNC 0x1400a0 · F_ActionPartEmitDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x1400a0 push {r3, r4, r5, lr} */
/* @0x1400a4 mov r1, #0 */
/* @0x1400a8 ldr r0, [sp, #0x10] */
/* @0x1400ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1400b0 ldr r4, [pc, #0x44] */
/* @0x1400b4 ldr r4, [pc, r4] */
/* @0x1400b8 ldr r3, [r4] */
/* @0x1400bc cmp r3, #0 */
/* @0x1400c0 mov r5, r0 */
/* @0x1400c4 blt 0x1400e8 <_Z23F_ActionPartEmitDestroyR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1400c8 ldr r3, [pc, #0x30] */
/* @0x1400cc ldr r3, [pc, r3] */
/* @0x1400d0 ldr r1, [r3, r5, lsl #2] */
/* @0x1400d4 cmp r1, #0 */
/* @0x1400d8 poplt {r3, r4, r5, pc} */
/* @0x1400dc ldr r0, [r4] */
/* @0x1400e0 pop {r3, r4, r5, lr} */
/* @0x1400e4 b 0x1a38ac <_Z30ParticleSystem_Emitter_Destroyii> */
/* @0x1400e8 mvn r0, #0 */
/* @0x1400ec mov r1, #1 */
/* @0x1400f0 bl 0x1a42dc <_Z21ParticleSystem_Createib> */
/* @0x1400f4 str r0, [r4] */
/* @0x1400f8 b 0x1400c8 <_Z23F_ActionPartEmitDestroyR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x1400fc eoreq pc, r10, r8, lsr #6 */
/* @0x140100 eoreq pc, r10, r8, lsl r3 */

/* ── FUNC 0x140104 · F_ActionCDPlay(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x140104 push {r3, r4, r5, lr} */
/* @0x140108 mov r1, #0 */
/* @0x14010c ldr r4, [sp, #0x10] */
/* @0x140110 mov r0, r4 */
/* @0x140114 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x140118 mov r1, #1 */
/* @0x14011c mov r5, r0 */
/* @0x140120 mov r0, r4 */
/* @0x140124 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x140128 mov r1, r0 */
/* @0x14012c mov r0, r5 */
/* @0x140130 pop {r3, r4, r5, lr} */
/* @0x140134 b 0x2148a4 <_Z7CD_Playii> */

/* ── FUNC 0x140138 · F_ActionCDStop(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x140138 b 0x2148a8 <_Z7CD_Stopv> */
