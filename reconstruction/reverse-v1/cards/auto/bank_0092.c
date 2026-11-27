/* libyoyo.so 覆盖卡组 0092
 * 函数 0x158eac..0x159d20，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x158eac · F_YoYo_WinPhone_SetTile_Iconic_IconImage(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x158eac cmp r3, #1 */
/* @0x158eb0 push {r3, lr} */
/* @0x158eb4 mov r3, #0 */
/* @0x158eb8 str r3, [r0, #0xc] */
/* @0x158ebc str r3, [r0] */
/* @0x158ec0 str r3, [r0, #0x4] */
/* @0x158ec4 beq 0x158eec <_Z40F_YoYo_WinPhone_SetTile_Iconic_IconImageR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x158ec8 ldr r3, [pc, #0x50] */
/* @0x158ecc ldr r1, [pc, #0x50] */
/* @0x158ed0 ldr r3, [pc, r3] */
/* @0x158ed4 add r1, pc, r1 */
/* @0x158ed8 ldr r0, [r3] */
/* @0x158edc ldr r3, [r0] */
/* @0x158ee0 ldr r3, [r3, #0xc] */
/* @0x158ee4 blx r3 */
/* @0x158ee8 pop {r3, pc} */
/* @0x158eec ldr r2, [sp, #0x8] */
/* @0x158ef0 ldr r3, [r2, #0xc] */
/* @0x158ef4 cmp r3, #1 */
/* @0x158ef8 bne 0x158ec8 <_Z40F_YoYo_WinPhone_SetTile_Iconic_IconImageR6RValueP9CInstanceS2_iPS_+0x1c> */
/* @0x158efc ldr r3, [pc, #0x24] */
/* @0x158f00 ldr r1, [pc, #0x24] */
/* @0x158f04 ldr r3, [pc, r3] */
/* @0x158f08 add r1, pc, r1 */
/* @0x158f0c ldr r0, [r3] */
/* @0x158f10 ldr r3, [r0] */
/* @0x158f14 ldr r3, [r3, #0xc] */
/* @0x158f18 blx r3 */
/* @0x158f1c pop {r3, pc} */
/* @0x158f20 eoreq r4, r9, r4, asr #16 */
/* @0x158f24 ldrsheq sp, [lr], -r4 */
/* @0x158f28 eoreq r4, r9, r0, lsl r8 */
/* @0x158f2c andseq sp, lr, r4, lsl #12 */

/* ── FUNC 0x158f30 · F_YoYo_WinPhone_SetTile_Iconic_SmallIconImage(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x158f30 cmp r3, #1 */
/* @0x158f34 push {r3, lr} */
/* @0x158f38 mov r3, #0 */
/* @0x158f3c str r3, [r0, #0xc] */
/* @0x158f40 str r3, [r0] */
/* @0x158f44 str r3, [r0, #0x4] */
/* @0x158f48 beq 0x158f70 <_Z45F_YoYo_WinPhone_SetTile_Iconic_SmallIconImageR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x158f4c ldr r3, [pc, #0x50] */
/* @0x158f50 ldr r1, [pc, #0x50] */
/* @0x158f54 ldr r3, [pc, r3] */
/* @0x158f58 add r1, pc, r1 */
/* @0x158f5c ldr r0, [r3] */
/* @0x158f60 ldr r3, [r0] */
/* @0x158f64 ldr r3, [r3, #0xc] */
/* @0x158f68 blx r3 */
/* @0x158f6c pop {r3, pc} */
/* @0x158f70 ldr r2, [sp, #0x8] */
/* @0x158f74 ldr r3, [r2, #0xc] */
/* @0x158f78 cmp r3, #1 */
/* @0x158f7c bne 0x158f4c <_Z45F_YoYo_WinPhone_SetTile_Iconic_SmallIconImageR6RValueP9CInstanceS2_iPS_+0x1c> */
/* @0x158f80 ldr r3, [pc, #0x24] */
/* @0x158f84 ldr r1, [pc, #0x24] */
/* @0x158f88 ldr r3, [pc, r3] */
/* @0x158f8c add r1, pc, r1 */
/* @0x158f90 ldr r0, [r3] */
/* @0x158f94 ldr r3, [r0] */
/* @0x158f98 ldr r3, [r3, #0xc] */
/* @0x158f9c blx r3 */
/* @0x158fa0 pop {r3, pc} */
/* @0x158fa4 eoreq r4, r9, r0, asr #15 */
/* @0x158fa8 ldrheq sp, [lr], -r0 */
/* @0x158fac eoreq r4, r9, r12, lsl #15 */
/* @0x158fb0 andseq sp, lr, r0, lsl #11 */

/* ── FUNC 0x158fb4 · F_YoYo_WinPhone_SetTile_Cycle_SmallBackgroundImage(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x158fb4 cmp r3, #1 */
/* @0x158fb8 push {r3, lr} */
/* @0x158fbc mov r3, #0 */
/* @0x158fc0 str r3, [r0, #0xc] */
/* @0x158fc4 str r3, [r0] */
/* @0x158fc8 str r3, [r0, #0x4] */
/* @0x158fcc beq 0x158ff4 <_Z50F_YoYo_WinPhone_SetTile_Cycle_SmallBackgroundImageR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x158fd0 ldr r3, [pc, #0x50] */
/* @0x158fd4 ldr r1, [pc, #0x50] */
/* @0x158fd8 ldr r3, [pc, r3] */
/* @0x158fdc add r1, pc, r1 */
/* @0x158fe0 ldr r0, [r3] */
/* @0x158fe4 ldr r3, [r0] */
/* @0x158fe8 ldr r3, [r3, #0xc] */
/* @0x158fec blx r3 */
/* @0x158ff0 pop {r3, pc} */
/* @0x158ff4 ldr r2, [sp, #0x8] */
/* @0x158ff8 ldr r3, [r2, #0xc] */
/* @0x158ffc cmp r3, #1 */
/* @0x159000 bne 0x158fd0 <_Z50F_YoYo_WinPhone_SetTile_Cycle_SmallBackgroundImageR6RValueP9CInstanceS2_iPS_+0x1c> */
/* @0x159004 ldr r3, [pc, #0x24] */
/* @0x159008 ldr r1, [pc, #0x24] */
/* @0x15900c ldr r3, [pc, r3] */
/* @0x159010 add r1, pc, r1 */
/* @0x159014 ldr r0, [r3] */
/* @0x159018 ldr r3, [r0] */
/* @0x15901c ldr r3, [r3, #0xc] */
/* @0x159020 blx r3 */
/* @0x159024 pop {r3, pc} */
/* @0x159028 eoreq r4, r9, r12, lsr r7 */
/* @0x15902c andseq sp, lr, r0, ror r10 */
/* @0x159030 eoreq r4, r9, r8, lsl #14 */
/* @0x159034 ldrsheq sp, [lr], -r12 */

/* ── FUNC 0x159038 · F_YoYo_CloudStringSave(RValue&, CInstance*, CInstance*, int, RValue*) · size=188 · insn=47 */
/* @0x159038 cmp r3, #2 */
/* @0x15903c mov r1, #0 */
/* @0x159040 push {r3, r4, r5, r6, r7, lr} */
/* @0x159044 mov r4, r0 */
/* @0x159048 ldr r5, [sp, #0x18] */
/* @0x15904c str r1, [r0, #0xc] */
/* @0x159050 str r1, [r0] */
/* @0x159054 str r1, [r0, #0x4] */
/* @0x159058 bne 0x1590d4 <_Z22F_YoYo_CloudStringSaveR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x15905c ldr r3, [r5, #0xc] */
/* @0x159060 cmp r3, #1 */
/* @0x159064 beq 0x159074 <_Z22F_YoYo_CloudStringSaveR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x159068 ldr r3, [r5, #0x1c] */
/* @0x15906c cmp r3, #1 */
/* @0x159070 bne 0x1590c4 <_Z22F_YoYo_CloudStringSaveR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x159074 ldr r3, [pc, #0x68] */
/* @0x159078 mov r1, #0 */
/* @0x15907c mov r0, r5 */
/* @0x159080 ldr r3, [pc, r3] */
/* @0x159084 ldr r7, [r3] */
/* @0x159088 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x15908c mov r1, #1 */
/* @0x159090 mov r6, r0 */
/* @0x159094 mov r0, r5 */
/* @0x159098 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x15909c ldr r3, [pc, #0x44] */
/* @0x1590a0 ldr r2, [pc, r3] */
/* @0x1590a4 mov r1, r0 */
/* @0x1590a8 mov r0, r6 */
/* @0x1590ac bl 0x1612b0 <_Z17Cloud_String_SavePKcS0_PFiP16HTTP_REQ_CONTEXTPvPiE> */
/* @0x1590b0 vmov s15, r7 */
/* @0x1590b4 vcvt.f64.s32 d7, s15 */
/* @0x1590b8 vmov r2, r3, d7 */
/* @0x1590bc stm r4, {r2, r3} */
/* @0x1590c0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1590c4 ldr r0, [pc, #0x20] */
/* @0x1590c8 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1590cc add r0, pc, r0 */
/* @0x1590d0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1590d4 ldr r0, [pc, #0x14] */
/* @0x1590d8 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1590dc add r0, pc, r0 */
/* @0x1590e0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1590e4 .word 0x002961f8 */
/* @0x1590e8 .word 0x00296ab8 */
/* @0x1590ec andseq r9, lr, r0, ror #17 */
/* @0x1590f0 andseq sp, lr, r12, ror #9 */

/* ── FUNC 0x1590f4 · F_YoYo_PostAchievement(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x1590f4 push {r4, r5, r6, lr} */
/* @0x1590f8 cmp r3, #2 */
/* @0x1590fc sub sp, sp, #8 */
/* @0x159100 mov r1, #0 */
/* @0x159104 str r1, [r0, #0xc] */
/* @0x159108 ldr r4, [sp, #0x18] */
/* @0x15910c str r1, [r0] */
/* @0x159110 str r1, [r0, #0x4] */
/* @0x159114 bne 0x159184 <_Z22F_YoYo_PostAchievementR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x159118 ldr r1, [r4, #0xc] */
/* @0x15911c cmp r1, #1 */
/* @0x159120 bne 0x15916c <_Z22F_YoYo_PostAchievementR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x159124 ldr r5, [r4, #0x1c] */
/* @0x159128 cmp r5, #0 */
/* @0x15912c bne 0x15916c <_Z22F_YoYo_PostAchievementR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x159130 ldr r2, [pc, #0x60] */
/* @0x159134 ldr r2, [pc, r2] */
/* @0x159138 ldrb r2, [r2] */
/* @0x15913c cmp r2, #0 */
/* @0x159140 beq 0x15917c <_Z22F_YoYo_PostAchievementR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x159144 mov r0, r4 */
/* @0x159148 add r6, sp, #8 */
/* @0x15914c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x159150 mov r1, r5 */
/* @0x159154 str r0, [r6, #-0x4]! */
/* @0x159158 mov r0, r4 */
/* @0x15915c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x159160 mov r1, r6 */
/* @0x159164 bl 0x16163c <_Z21YoYo_CacheAchievementPKcPj> */
/* @0x159168 b 0x15917c <_Z22F_YoYo_PostAchievementR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x15916c ldr r0, [pc, #0x28] */
/* @0x159170 mov r1, #0 */
/* @0x159174 add r0, pc, r0 */
/* @0x159178 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x15917c add sp, sp, #8 */
/* @0x159180 pop {r4, r5, r6, pc} */
/* @0x159184 ldr r0, [pc, #0x14] */
/* @0x159188 add r0, pc, r0 */
/* @0x15918c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x159190 add sp, sp, #8 */
/* @0x159194 pop {r4, r5, r6, pc} */
/* @0x159198 .word 0x002969fc */
/* @0x15919c andseq r9, lr, r8, lsr r8 */
/* @0x1591a0 andseq sp, lr, r0, asr #8 */

/* ── FUNC 0x1591a4 · F_YoYo_IncrementAchievement(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x1591a4 push {r4, r5, r6, lr} */
/* @0x1591a8 cmp r3, #2 */
/* @0x1591ac sub sp, sp, #8 */
/* @0x1591b0 mov r1, #0 */
/* @0x1591b4 str r1, [r0, #0xc] */
/* @0x1591b8 ldr r4, [sp, #0x18] */
/* @0x1591bc str r1, [r0] */
/* @0x1591c0 str r1, [r0, #0x4] */
/* @0x1591c4 bne 0x159234 <_Z27F_YoYo_IncrementAchievementR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x1591c8 ldr r1, [r4, #0xc] */
/* @0x1591cc cmp r1, #1 */
/* @0x1591d0 bne 0x15921c <_Z27F_YoYo_IncrementAchievementR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1591d4 ldr r5, [r4, #0x1c] */
/* @0x1591d8 cmp r5, #0 */
/* @0x1591dc bne 0x15921c <_Z27F_YoYo_IncrementAchievementR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1591e0 ldr r2, [pc, #0x60] */
/* @0x1591e4 ldr r2, [pc, r2] */
/* @0x1591e8 ldrb r2, [r2] */
/* @0x1591ec cmp r2, #0 */
/* @0x1591f0 beq 0x15922c <_Z27F_YoYo_IncrementAchievementR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1591f4 mov r0, r4 */
/* @0x1591f8 add r6, sp, #8 */
/* @0x1591fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x159200 mov r1, r5 */
/* @0x159204 str r0, [r6, #-0x4]! */
/* @0x159208 mov r0, r4 */
/* @0x15920c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x159210 mov r1, r6 */
/* @0x159214 bl 0x1615f0 <_Z25YoYo_IncrementAchievementPKcPj> */
/* @0x159218 b 0x15922c <_Z27F_YoYo_IncrementAchievementR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x15921c ldr r0, [pc, #0x28] */
/* @0x159220 mov r1, #0 */
/* @0x159224 add r0, pc, r0 */
/* @0x159228 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x15922c add sp, sp, #8 */
/* @0x159230 pop {r4, r5, r6, pc} */
/* @0x159234 ldr r0, [pc, #0x14] */
/* @0x159238 add r0, pc, r0 */
/* @0x15923c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x159240 add sp, sp, #8 */
/* @0x159244 pop {r4, r5, r6, pc} */
/* @0x159248 eoreq r6, r9, r12, asr #18 */
/* @0x15924c andseq r9, lr, r8, lsl #15 */
/* @0x159250 mulseq lr, r0, r3 */

/* ── FUNC 0x159254 · F_YoYo_PostScore(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x159254 push {r4, r5, r6, lr} */
/* @0x159258 cmp r3, #2 */
/* @0x15925c sub sp, sp, #8 */
/* @0x159260 mov r1, #0 */
/* @0x159264 str r1, [r0, #0xc] */
/* @0x159268 ldr r4, [sp, #0x18] */
/* @0x15926c str r1, [r0] */
/* @0x159270 str r1, [r0, #0x4] */
/* @0x159274 bne 0x1592e4 <_Z16F_YoYo_PostScoreR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x159278 ldr r1, [r4, #0xc] */
/* @0x15927c cmp r1, #1 */
/* @0x159280 bne 0x1592cc <_Z16F_YoYo_PostScoreR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x159284 ldr r5, [r4, #0x1c] */
/* @0x159288 cmp r5, #0 */
/* @0x15928c bne 0x1592cc <_Z16F_YoYo_PostScoreR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x159290 ldr r2, [pc, #0x60] */
/* @0x159294 ldr r2, [pc, r2] */
/* @0x159298 ldrb r2, [r2] */
/* @0x15929c cmp r2, #0 */
/* @0x1592a0 beq 0x1592dc <_Z16F_YoYo_PostScoreR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1592a4 mov r0, r4 */
/* @0x1592a8 add r6, sp, #8 */
/* @0x1592ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1592b0 mov r1, r5 */
/* @0x1592b4 str r0, [r6, #-0x4]! */
/* @0x1592b8 mov r0, r4 */
/* @0x1592bc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1592c0 mov r1, r6 */
/* @0x1592c4 bl 0x161688 <_Z21YoYo_ScoreAchievementPKcPj> */
/* @0x1592c8 b 0x1592dc <_Z16F_YoYo_PostScoreR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1592cc ldr r0, [pc, #0x28] */
/* @0x1592d0 mov r1, #0 */
/* @0x1592d4 add r0, pc, r0 */
/* @0x1592d8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1592dc add sp, sp, #8 */
/* @0x1592e0 pop {r4, r5, r6, pc} */
/* @0x1592e4 ldr r0, [pc, #0x14] */
/* @0x1592e8 add r0, pc, r0 */
/* @0x1592ec bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1592f0 add sp, sp, #8 */
/* @0x1592f4 pop {r4, r5, r6, pc} */
/* @0x1592f8 mlaeq r9, r12, r8, r6 */
/* @0x1592fc ldrsbeq r9, [lr], -r8 */
/* @0x159300 andseq sp, lr, r0, ror #5 */

/* ── FUNC 0x159304 · F_YoYo_MoveAdsEx(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x159304 push {r4, r5, r6, lr} */
/* @0x159308 mov r1, #2 */
/* @0x15930c ldr r4, [sp, #0x10] */
/* @0x159310 mov r0, r4 */
/* @0x159314 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x159318 cmp r0, #4 */
/* @0x15931c mov r5, r0 */
/* @0x159320 bls 0x159338 <_Z16F_YoYo_MoveAdsExR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x159324 ldr r0, [pc, #0x3c] */
/* @0x159328 mov r1, #0 */
/* @0x15932c pop {r4, r5, r6, lr} */
/* @0x159330 add r0, pc, r0 */
/* @0x159334 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x159338 mov r0, r4 */
/* @0x15933c mov r1, #0 */
/* @0x159340 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x159344 mov r1, #1 */
/* @0x159348 mov r6, r0 */
/* @0x15934c mov r0, r4 */
/* @0x159350 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x159354 mov r2, r5 */
/* @0x159358 mov r1, r0 */
/* @0x15935c mov r0, r6 */
/* @0x159360 pop {r4, r5, r6, lr} */
/* @0x159364 b 0x15e340 <_Z6MoveAdiii> */
/* @0x159368 andseq sp, lr, r8, ror #14 */

/* ── FUNC 0x15936c · F_YoYo_DisableAds(RValue&, CInstance*, CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x15936c push {r3, lr} */
/* @0x159370 mov r1, #0 */
/* @0x159374 ldr r0, [sp, #0x8] */
/* @0x159378 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x15937c cmp r0, #4 */
/* @0x159380 bls 0x159398 <_Z17F_YoYo_DisableAdsR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x159384 ldr r0, [pc, #0x14] */
/* @0x159388 mov r1, #0 */
/* @0x15938c pop {r3, lr} */
/* @0x159390 add r0, pc, r0 */
/* @0x159394 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x159398 pop {r3, lr} */
/* @0x15939c b 0x15e3e8 <_Z16DisableAdServingi> */
/* @0x1593a0 andseq sp, lr, r8, lsl #14 */

/* ── FUNC 0x1593a4 · F_YoYo_GetAdsWidth(RValue&, CInstance*, CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x1593a4 push {r3, r4, r5, lr} */
/* @0x1593a8 mov r4, #0 */
/* @0x1593ac ldr r3, [sp, #0x10] */
/* @0x1593b0 mov r5, r0 */
/* @0x1593b4 str r4, [r0, #0xc] */
/* @0x1593b8 mov r1, r4 */
/* @0x1593bc mov r0, r3 */
/* @0x1593c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1593c4 cmp r0, #4 */
/* @0x1593c8 bls 0x1593e0 <_Z18F_YoYo_GetAdsWidthR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1593cc ldr r0, [pc, #0x2c] */
/* @0x1593d0 mov r1, r4 */
/* @0x1593d4 pop {r3, r4, r5, lr} */
/* @0x1593d8 add r0, pc, r0 */
/* @0x1593dc b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1593e0 bl 0x15e4c8 <_Z14AdDisplayWidthi> */
/* @0x1593e4 vmov s15, r0 */
/* @0x1593e8 vcvt.f64.s32 d7, s15 */
/* @0x1593ec vmov r0, r1, d7 */
/* @0x1593f0 vmov r2, s14 */
/* @0x1593f4 mov r3, r1 */
/* @0x1593f8 stm r5, {r2, r3} */
/* @0x1593fc pop {r3, r4, r5, pc} */
/* @0x159400 andseq sp, lr, r0, asr #13 */

/* ── FUNC 0x159404 · F_YoYo_GetAdsHeight(RValue&, CInstance*, CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x159404 push {r3, r4, r5, lr} */
/* @0x159408 mov r4, #0 */
/* @0x15940c ldr r3, [sp, #0x10] */
/* @0x159410 mov r5, r0 */
/* @0x159414 str r4, [r0, #0xc] */
/* @0x159418 mov r1, r4 */
/* @0x15941c mov r0, r3 */
/* @0x159420 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x159424 cmp r0, #4 */
/* @0x159428 bls 0x159440 <_Z19F_YoYo_GetAdsHeightR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x15942c ldr r0, [pc, #0x2c] */
/* @0x159430 mov r1, r4 */
/* @0x159434 pop {r3, r4, r5, lr} */
/* @0x159438 add r0, pc, r0 */
/* @0x15943c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x159440 bl 0x15e500 <_Z15AdDisplayHeighti> */
/* @0x159444 vmov s15, r0 */
/* @0x159448 vcvt.f64.s32 d7, s15 */
/* @0x15944c vmov r0, r1, d7 */
/* @0x159450 vmov r2, s14 */
/* @0x159454 mov r3, r1 */
/* @0x159458 stm r5, {r2, r3} */
/* @0x15945c pop {r3, r4, r5, pc} */
/* @0x159460 andseq sp, lr, r0, ror #12 */

/* ── FUNC 0x159464 · F_YoYo_OF_AddLeaderboard(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x159464 push {r4, r5, r6, lr} */
/* @0x159468 cmp r3, #3 */
/* @0x15946c ldr r4, [sp, #0x10] */
/* @0x159470 mov r1, #0 */
/* @0x159474 mov r0, r4 */
/* @0x159478 beq 0x1594a4 <_Z24F_YoYo_OF_AddLeaderboardR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x15947c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x159480 mov r1, #1 */
/* @0x159484 mov r5, r0 */
/* @0x159488 mov r0, r4 */
/* @0x15948c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x159490 mov r2, #1 */
/* @0x159494 mov r1, r0 */
/* @0x159498 mov r0, r5 */
/* @0x15949c pop {r4, r5, r6, lr} */
/* @0x1594a0 b 0x1616dc <_Z22YoYo_OF_AddLeaderboardPKcS0_16eLeaderboardType> */
/* @0x1594a4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1594a8 mov r1, #1 */
/* @0x1594ac mov r6, r0 */
/* @0x1594b0 mov r0, r4 */
/* @0x1594b4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1594b8 mov r1, #2 */
/* @0x1594bc mov r5, r0 */
/* @0x1594c0 mov r0, r4 */
/* @0x1594c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1594c8 mov r1, r5 */
/* @0x1594cc mov r2, r0 */
/* @0x1594d0 mov r0, r6 */
/* @0x1594d4 pop {r4, r5, r6, lr} */
/* @0x1594d8 b 0x1616dc <_Z22YoYo_OF_AddLeaderboardPKcS0_16eLeaderboardType> */

/* ── FUNC 0x1594dc · F_YoYo_LockOrientation(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0x1594dc push {r4, lr} */
/* @0x1594e0 mov r3, #0 */
/* @0x1594e4 ldr r12, [sp, #0x8] */
/* @0x1594e8 mov r1, r3 */
/* @0x1594ec str r3, [r0, #0xc] */
/* @0x1594f0 str r3, [r0] */
/* @0x1594f4 str r3, [r0, #0x4] */
/* @0x1594f8 mov r0, r12 */
/* @0x1594fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x159500 ldr r3, [pc, #0x98] */
/* @0x159504 add r3, pc, r3 */
/* @0x159508 cmp r0, #0 */
/* @0x15950c ble 0x159548 <_Z22F_YoYo_LockOrientationR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x159510 bl 0x15e288 <GetOrientation> */
/* @0x159514 subs r2, r0, #1 */
/* @0x159518 rsbs r1, r2, #0 */
/* @0x15951c adcs r1, r1, r2 */
/* @0x159520 subs r12, r0, #2 */
/* @0x159524 rsbs r2, r12, #0 */
/* @0x159528 adcs r2, r2, r12 */
/* @0x15952c subs lr, r0, #3 */
/* @0x159530 rsbs r3, lr, #0 */
/* @0x159534 adcs r3, r3, lr */
/* @0x159538 rsbs r0, r0, #1 */
/* @0x15953c pop {r4, lr} */
/* @0x159540 movlo r0, #0 */
/* @0x159544 b 0x15f1bc <_Z19RestrictOrientationbbbb> */
/* @0x159548 ldr r0, [pc, #0x54] */
/* @0x15954c ldr r1, [pc, #0x54] */
/* @0x159550 ldr r2, [pc, #0x54] */
/* @0x159554 ldr r0, [r3, r0] */
/* @0x159558 ldr r1, [r3, r1] */
/* @0x15955c ldr r12, [pc, #0x4c] */
/* @0x159560 ldr r0, [r0] */
/* @0x159564 ldr r2, [r3, r2] */
/* @0x159568 adds r0, r0, #0 */
/* @0x15956c ldr r1, [r1] */
/* @0x159570 ldr r3, [r3, r12] */
/* @0x159574 ldr r2, [r2] */
/* @0x159578 movne r0, #1 */
/* @0x15957c adds r1, r1, #0 */
/* @0x159580 ldr r3, [r3] */
/* @0x159584 movne r1, #1 */
/* @0x159588 adds r2, r2, #0 */
/* @0x15958c pop {r4, lr} */
/* @0x159590 movne r2, #1 */
/* @0x159594 adds r3, r3, #0 */
/* @0x159598 movne r3, #1 */
/* @0x15959c b 0x15f1bc <_Z19RestrictOrientationbbbb> */
/* @0x1595a0 eoreq r8, r9, r12, asr #14 */
/* @0x1595a4 .word 0xffffdf64 */
/* @0x1595a8 .word 0xffffdf68 */
/* @0x1595ac .word 0xffffdf6c */
/* @0x1595b0 .word 0xffffdf70 */

/* ── FUNC 0x1595b4 · WriteInt32(unsigned int, unsigned char*, int*) · size=80 · insn=20 */
/* @0x1595b4 ldr r3, [r2] */
/* @0x1595b8 lsr r12, r0, #24 */
/* @0x1595bc push {r4, r5} */
/* @0x1595c0 ubfx r5, r0, #0x8, #0x8 */
/* @0x1595c4 strb r0, [r1, r3] */
/* @0x1595c8 ubfx r4, r0, #0x10, #0x8 */
/* @0x1595cc ldr r3, [r2] */
/* @0x1595d0 add r3, r1, r3 */
/* @0x1595d4 strb r5, [r3, #0x1] */
/* @0x1595d8 ldr r3, [r2] */
/* @0x1595dc add r3, r1, r3 */
/* @0x1595e0 strb r4, [r3, #0x2] */
/* @0x1595e4 ldr r3, [r2] */
/* @0x1595e8 add r1, r1, r3 */
/* @0x1595ec strb r12, [r1, #0x3] */
/* @0x1595f0 ldr r3, [r2] */
/* @0x1595f4 pop {r4, r5} */
/* @0x1595f8 add r3, r3, #4 */
/* @0x1595fc str r3, [r2] */
/* @0x159600 bx lr */

/* ── FUNC 0x159604 · WriteString(char const*, unsigned char*, int*) · size=60 · insn=15 */
/* @0x159604 push {r4, r5, r6, lr} */
/* @0x159608 mov r4, r2 */
/* @0x15960c mov r6, r1 */
/* @0x159610 mov r5, r0 */
/* @0x159614 bl 0xb6538 <strlen@plt> */
/* @0x159618 ldr r3, [r4] */
/* @0x15961c mov r1, r5 */
/* @0x159620 add r5, r0, #1 */
/* @0x159624 add r0, r6, r3 */
/* @0x159628 mov r2, r5 */
/* @0x15962c bl 0xb65bc <memcpy@plt> */
/* @0x159630 ldr r3, [r4] */
/* @0x159634 add r5, r3, r5 */
/* @0x159638 str r5, [r4] */
/* @0x15963c pop {r4, r5, r6, pc} */

/* ── FUNC 0x159640 · FlushAchievementCache() · size=332 · insn=83 */
/* @0x159640 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x159644 sub sp, sp, #268 */
/* @0x159648 ldr r7, [pc, #0x124] */
/* @0x15964c ldr r8, [pc, #0x124] */
/* @0x159650 ldr r7, [pc, r7] */
/* @0x159654 ldr r8, [pc, r8] */
/* @0x159658 ldr r4, [r7] */
/* @0x15965c ldr r3, [r8] */
/* @0x159660 cmp r4, #0 */
/* @0x159664 str r3, [sp, #0x104] */
/* @0x159668 beq 0x159768 <_Z21FlushAchievementCachev+0x128> */
/* @0x15966c mov r5, #0 */
/* @0x159670 ldr r0, [r4, #0xc] */
/* @0x159674 bl 0xb6538 <strlen@plt> */
/* @0x159678 ldr r4, [r4] */
/* @0x15967c cmp r4, #0 */
/* @0x159680 add r0, r0, r5 */
/* @0x159684 add r5, r0, #9 */
/* @0x159688 bne 0x159670 <_Z21FlushAchievementCachev+0x30> */
/* @0x15968c bl 0x161210 <_Z20Achievement_PlayerIDv> */
/* @0x159690 cmp r0, #0 */
/* @0x159694 beq 0x159740 <_Z21FlushAchievementCachev+0x100> */
/* @0x159698 bl 0x161210 <_Z20Achievement_PlayerIDv> */
/* @0x15969c add r9, sp, #4 */
/* @0x1596a0 ldr r1, [pc, #0xd4] */
/* @0x1596a4 ldr r3, [pc, #0xd4] */
/* @0x1596a8 add r1, pc, r1 */
/* @0x1596ac add r3, pc, r3 */
/* @0x1596b0 mov r2, r0 */
/* @0x1596b4 mov r0, r9 */
/* @0x1596b8 bl 0xb6550 <sprintf@plt> */
/* @0x1596bc cmp r5, #0 */
/* @0x1596c0 ble 0x159740 <_Z21FlushAchievementCachev+0x100> */
/* @0x1596c4 ldr r1, [pc, #0xb8] */
/* @0x1596c8 mov r3, #1 */
/* @0x1596cc mov r0, r5 */
/* @0x1596d0 movw r2, #0x11d */
/* @0x1596d4 add r1, pc, r1 */
/* @0x1596d8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1596dc ldr r4, [r7] */
/* @0x1596e0 mov r3, #0 */
/* @0x1596e4 str r3, [sp] */
/* @0x1596e8 cmp r4, r3 */
/* @0x1596ec mov r6, r0 */
/* @0x1596f0 beq 0x159730 <_Z21FlushAchievementCachev+0xf0> */
/* @0x1596f4 ldr r0, [r4, #0x8] */
/* @0x1596f8 mov r1, r6 */
/* @0x1596fc mov r2, sp */
/* @0x159700 bl 0x1595b4 <_Z10WriteInt32jPhPi> */
/* @0x159704 ldr r0, [r4, #0xc] */
/* @0x159708 mov r1, r6 */
/* @0x15970c mov r2, sp */
/* @0x159710 bl 0x159604 <_Z11WriteStringPKcPhPi> */
/* @0x159714 ldr r0, [r4, #0x10] */
/* @0x159718 mov r1, r6 */
/* @0x15971c mov r2, sp */
/* @0x159720 bl 0x1595b4 <_Z10WriteInt32jPhPi> */
/* @0x159724 ldr r4, [r4] */
/* @0x159728 cmp r4, #0 */
/* @0x15972c bne 0x1596f4 <_Z21FlushAchievementCachev+0xb4> */
/* @0x159730 mov r0, r9 */
/* @0x159734 mov r1, r6 */
/* @0x159738 mov r2, r5 */
/* @0x15973c bl 0x18fa3c <_ZN8LoadSave9WriteFileEPKcS1_i> */
/* @0x159740 ldr r0, [sp, #0x104] */
/* @0x159744 mov r2, #0 */
/* @0x159748 ldr r3, [pc, #0x38] */
/* @0x15974c ldr r1, [r8] */
/* @0x159750 ldr r3, [pc, r3] */
/* @0x159754 cmp r0, r1 */
/* @0x159758 strb r2, [r3] */
/* @0x15975c bne 0x159770 <_Z21FlushAchievementCachev+0x130> */
/* @0x159760 add sp, sp, #268 */
/* @0x159764 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x159768 mov r5, r4 */
/* @0x15976c b 0x15968c <_Z21FlushAchievementCachev+0x4c> */
/* @0x159770 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x159774 eoreq r6, r9, r4, ror r5 */
/* @0x159778 .word 0x002942fc */
/* @0x15977c andseq r11, sp, r12, lsr #10 */
/* @0x159780 andseq sp, lr, r12, lsl #8 */
/* @0x159784 mulseq lr, r0, lr */
/* @0x159788 eoreq r6, r9, r8, ror r4 */

/* ── FUNC 0x15978c · UnLinkCacheAchievement(SAchivementCache*) · size=152 · insn=38 */
/* @0x15978c ldr r2, [r0, #0x4] */
/* @0x159790 ldr r3, [pc, #0x78] */
/* @0x159794 cmp r2, #0 */
/* @0x159798 add r3, pc, r3 */
/* @0x15979c beq 0x1597e0 <_Z22UnLinkCacheAchievementP16SAchivementCache+0x54> */
/* @0x1597a0 ldr r1, [r0] */
/* @0x1597a4 str r1, [r2] */
/* @0x1597a8 ldr r1, [r0] */
/* @0x1597ac cmp r1, #0 */
/* @0x1597b0 strne r2, [r1, #0x4] */
/* @0x1597b4 beq 0x159800 <_Z22UnLinkCacheAchievementP16SAchivementCache+0x74> */
/* @0x1597b8 ldr r2, [pc, #0x54] */
/* @0x1597bc mov r1, #1 */
/* @0x1597c0 ldr r0, [pc, #0x50] */
/* @0x1597c4 ldr r2, [r3, r2] */
/* @0x1597c8 ldr r12, [r2] */
/* @0x1597cc sub r12, r12, #1 */
/* @0x1597d0 str r12, [r2] */
/* @0x1597d4 ldr r3, [r3, r0] */
/* @0x1597d8 strb r1, [r3] */
/* @0x1597dc bx lr */
/* @0x1597e0 ldr r1, [pc, #0x34] */
/* @0x1597e4 ldr r0, [r0] */
/* @0x1597e8 ldr r12, [r3, r1] */
/* @0x1597ec mov r1, r0 */
/* @0x1597f0 cmp r1, #0 */
/* @0x1597f4 strne r2, [r1, #0x4] */
/* @0x1597f8 str r0, [r12] */
/* @0x1597fc bne 0x1597b8 <_Z22UnLinkCacheAchievementP16SAchivementCache+0x2c> */
/* @0x159800 ldr r1, [pc, #0x18] */
/* @0x159804 ldr r1, [r3, r1] */
/* @0x159808 str r2, [r1] */
/* @0x15980c b 0x1597b8 <_Z22UnLinkCacheAchievementP16SAchivementCache+0x2c> */
/* @0x159810 .word 0x002984b8 */
/* @0x159814 .word 0xffffdf7c */
/* @0x159818 .word 0xffffdf78 */
/* @0x15981c .word 0xffffdf74 */
/* @0x159820 .word 0xffffdf80 */

/* ── FUNC 0x159824 · LinkCacheAchievementToEnd(SAchivementCache*) · size=132 · insn=33 */
/* @0x159824 ldr r3, [pc, #0x68] */
/* @0x159828 mov r2, #0 */
/* @0x15982c ldr r1, [pc, #0x64] */
/* @0x159830 add r3, pc, r3 */
/* @0x159834 str r2, [r0] */
/* @0x159838 str r2, [r0, #0x4] */
/* @0x15983c ldr r1, [r3, r1] */
/* @0x159840 ldr r2, [r1] */
/* @0x159844 cmp r2, #0 */
/* @0x159848 strne r0, [r2] */
/* @0x15984c strne r2, [r0, #0x4] */
/* @0x159850 strne r0, [r1] */
/* @0x159854 beq 0x159880 <_Z25LinkCacheAchievementToEndP16SAchivementCache+0x5c> */
/* @0x159858 ldr r2, [pc, #0x3c] */
/* @0x15985c mov r1, #1 */
/* @0x159860 ldr r0, [pc, #0x38] */
/* @0x159864 ldr r2, [r3, r2] */
/* @0x159868 ldr r12, [r2] */
/* @0x15986c add r12, r12, r1 */
/* @0x159870 str r12, [r2] */
/* @0x159874 ldr r3, [r3, r0] */
/* @0x159878 strb r1, [r3] */
/* @0x15987c bx lr */
/* @0x159880 ldr r2, [pc, #0x1c] */
/* @0x159884 ldr r2, [r3, r2] */
/* @0x159888 str r0, [r1] */
/* @0x15988c str r0, [r2] */
/* @0x159890 b 0x159858 <_Z25LinkCacheAchievementToEndP16SAchivementCache+0x34> */
/* @0x159894 eoreq r8, r9, r0, lsr #8 */
/* @0x159898 .word 0xffffdf80 */
/* @0x15989c .word 0xffffdf7c */
/* @0x1598a0 .word 0xffffdf78 */
/* @0x1598a4 .word 0xffffdf74 */

/* ── FUNC 0x1598a8 · DeleteCachedAchievement(SAchivementCache*) · size=28 · insn=7 */
/* @0x1598a8 push {r4, lr} */
/* @0x1598ac mov r4, r0 */
/* @0x1598b0 bl 0x15978c <_Z22UnLinkCacheAchievementP16SAchivementCache> */
/* @0x1598b4 mov r0, r4 */
/* @0x1598b8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1598bc pop {r4, lr} */
/* @0x1598c0 b 0x159640 <_Z21FlushAchievementCachev> */

/* ── FUNC 0x1598c4 · UpdateAchievementCache() · size=412 · insn=103 */
/* @0x1598c4 push {r4, r5, r6, lr} */
/* @0x1598c8 ldr r4, [pc, #0x170] */
/* @0x1598cc ldr r3, [pc, #0x170] */
/* @0x1598d0 add r4, pc, r4 */
/* @0x1598d4 ldr r3, [r4, r3] */
/* @0x1598d8 ldrb r3, [r3] */
/* @0x1598dc cmp r3, #0 */
/* @0x1598e0 popeq {r4, r5, r6, pc} */
/* @0x1598e4 ldr r3, [pc, #0x15c] */
/* @0x1598e8 ldr r3, [r4, r3] */
/* @0x1598ec ldr r3, [r3] */
/* @0x1598f0 cmp r3, #0 */
/* @0x1598f4 popeq {r4, r5, r6, pc} */
/* @0x1598f8 ldr r3, [pc, #0x14c] */
/* @0x1598fc ldr r5, [r4, r3] */
/* @0x159900 ldr r0, [r5] */
/* @0x159904 bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0x159908 ldr r3, [pc, #0x140] */
/* @0x15990c ldr r6, [r4, r3] */
/* @0x159910 ldr r3, [r6] */
/* @0x159914 cmp r3, #4 */
/* @0x159918 addls pc, pc, r3, lsl #2 */
/* @0x15991c b 0x159980 <_Z22UpdateAchievementCachev+0xbc> */
/* @0x159920 b 0x159934 <_Z22UpdateAchievementCachev+0x70> */
/* @0x159924 b 0x159980 <_Z22UpdateAchievementCachev+0xbc> */
/* @0x159928 b 0x1599cc <_Z22UpdateAchievementCachev+0x108> */
/* @0x15992c b 0x15998c <_Z22UpdateAchievementCachev+0xc8> */
/* @0x159930 b 0x1599e8 <_Z22UpdateAchievementCachev+0x124> */
/* @0x159934 ldr r3, [pc, #0x118] */
/* @0x159938 ldr r3, [r4, r3] */
/* @0x15993c ldr r3, [r3] */
/* @0x159940 cmp r3, #0 */
/* @0x159944 beq 0x159980 <_Z22UpdateAchievementCachev+0xbc> */
/* @0x159948 ldr r2, [pc, #0x108] */
/* @0x15994c mov r1, #1 */
/* @0x159950 ldr r0, [r3, #0x8] */
/* @0x159954 ldr r2, [r4, r2] */
/* @0x159958 cmp r0, r1 */
/* @0x15995c str r1, [r6] */
/* @0x159960 str r3, [r2] */
/* @0x159964 beq 0x159a30 <_Z22UpdateAchievementCachev+0x16c> */
/* @0x159968 blt 0x159a0c <_Z22UpdateAchievementCachev+0x148> */
/* @0x15996c cmp r0, #3 */
/* @0x159970 bgt 0x159a0c <_Z22UpdateAchievementCachev+0x148> */
/* @0x159974 ldr r1, [r3, #0xc] */
/* @0x159978 ldr r2, [r3, #0x10] */
/* @0x15997c bl 0x1614b4 <_Z27Achievement_PostAchievement10eCacheTypePKcf> */
/* @0x159980 ldr r0, [r5] */
/* @0x159984 pop {r4, r5, r6, lr} */
/* @0x159988 b 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0x15998c ldr r2, [pc, #0xc8] */
/* @0x159990 mov r1, #600 */
/* @0x159994 ldr r3, [pc, #0xbc] */
/* @0x159998 mov r0, #4 */
/* @0x15999c ldr r2, [r4, r2] */
/* @0x1599a0 str r0, [r6] */
/* @0x1599a4 str r1, [r2] */
/* @0x1599a8 ldr r4, [r4, r3] */
/* @0x1599ac ldr r0, [r4] */
/* @0x1599b0 bl 0x15978c <_Z22UnLinkCacheAchievementP16SAchivementCache> */
/* @0x1599b4 ldr r0, [r4] */
/* @0x1599b8 bl 0x159824 <_Z25LinkCacheAchievementToEndP16SAchivementCache> */
/* @0x1599bc bl 0x159640 <_Z21FlushAchievementCachev> */
/* @0x1599c0 mov r3, #0 */
/* @0x1599c4 str r3, [r4] */
/* @0x1599c8 b 0x159980 <_Z22UpdateAchievementCachev+0xbc> */
/* @0x1599cc ldr r3, [pc, #0x84] */
/* @0x1599d0 ldr r3, [r4, r3] */
/* @0x1599d4 ldr r0, [r3] */
/* @0x1599d8 bl 0x1598a8 <_Z23DeleteCachedAchievementP16SAchivementCache> */
/* @0x1599dc mov r3, #0 */
/* @0x1599e0 str r3, [r6] */
/* @0x1599e4 b 0x159980 <_Z22UpdateAchievementCachev+0xbc> */
/* @0x1599e8 ldr r3, [pc, #0x6c] */
/* @0x1599ec ldr r3, [r4, r3] */
/* @0x1599f0 ldr r2, [r3] */
/* @0x1599f4 cmp r2, #0 */
/* @0x1599f8 subgt r2, r2, #1 */
/* @0x1599fc strgt r2, [r3] */
/* @0x159a00 movle r3, #0 */
/* @0x159a04 strle r3, [r6] */
/* @0x159a08 b 0x159980 <_Z22UpdateAchievementCachev+0xbc> */
/* @0x159a0c mov r0, r3 */
/* @0x159a10 bl 0x1598a8 <_Z23DeleteCachedAchievementP16SAchivementCache> */
/* @0x159a14 ldr r3, [pc, #0x40] */
/* @0x159a18 mov r2, #600 */
/* @0x159a1c mov r1, #4 */
/* @0x159a20 ldr r3, [r4, r3] */
/* @0x159a24 str r1, [r6] */
/* @0x159a28 str r2, [r3] */
/* @0x159a2c b 0x159980 <_Z22UpdateAchievementCachev+0xbc> */
/* @0x159a30 ldr r1, [r3, #0xc] */
/* @0x159a34 ldr r2, [r3, #0x10] */
/* @0x159a38 bl 0x1613fc <_Z23Achievement_PostHiScore10eCacheTypePKci> */
/* @0x159a3c b 0x159980 <_Z22UpdateAchievementCachev+0xbc> */
/* @0x159a40 eoreq r8, r9, r0, lsl #7 */
/* @0x159a44 .word 0xffffdee0 */
/* @0x159a48 .word 0xffffdf7c */
/* @0x159a4c .word 0xffffdf84 */
/* @0x159a50 .word 0xffffdf88 */
/* @0x159a54 .word 0xffffdf74 */
/* @0x159a58 .word 0xffffdf8c */
/* @0x159a5c .word 0xffffdf90 */

/* ── FUNC 0x159a60 · Set_AchievementSystem(bool) · size=20 · insn=5 */
/* @0x159a60 ldr r3, [pc, #0x8] */
/* @0x159a64 ldr r3, [pc, r3] */
/* @0x159a68 strb r0, [r3] */
/* @0x159a6c bx lr */
/* @0x159a70 eoreq r6, r9, r12, asr #1 */

/* ── FUNC 0x159a74 · Get_AchievementSystem() · size=20 · insn=5 */
/* @0x159a74 ldr r3, [pc, #0x8] */
/* @0x159a78 ldr r3, [pc, r3] */
/* @0x159a7c ldrb r0, [r3] */
/* @0x159a80 bx lr */
/* @0x159a84 strhteq r6, [r9], -r8 */

/* ── FUNC 0x159a88 · Threaded_UpdateComsState(eComsState) · size=20 · insn=5 */
/* @0x159a88 ldr r3, [pc, #0x8] */
/* @0x159a8c ldr r3, [pc, r3] */
/* @0x159a90 str r0, [r3] */
/* @0x159a94 bx lr */
/* @0x159a98 eoreq r6, r9, r12, asr #2 */

/* ── FUNC 0x159a9c · AddAchievementCacheBlock(eCacheType, char const*, unsigned int*) · size=144 · insn=36 */
/* @0x159a9c ldr r3, [pc, #0x80] */
/* @0x159aa0 push {r4, r5, r6, r7, r8, lr} */
/* @0x159aa4 ldr r3, [pc, r3] */
/* @0x159aa8 mov r6, r0 */
/* @0x159aac mov r5, r1 */
/* @0x159ab0 ldr r3, [r3] */
/* @0x159ab4 mov r7, r2 */
/* @0x159ab8 cmp r3, #2048 */
/* @0x159abc popgt {r4, r5, r6, r7, r8, pc} */
/* @0x159ac0 mov r0, r1 */
/* @0x159ac4 bl 0xb6538 <strlen@plt> */
/* @0x159ac8 ldr r1, [pc, #0x58] */
/* @0x159acc movw r2, #0x1ea */
/* @0x159ad0 mov r3, #1 */
/* @0x159ad4 add r1, pc, r1 */
/* @0x159ad8 mov r8, r0 */
/* @0x159adc add r0, r0, #21 */
/* @0x159ae0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x159ae4 add r2, r8, #1 */
/* @0x159ae8 mov r1, r5 */
/* @0x159aec mov r4, r0 */
/* @0x159af0 mov r3, r0 */
/* @0x159af4 mov r0, #0 */
/* @0x159af8 str r0, [r3], #20 */
/* @0x159afc str r3, [r4, #0xc] */
/* @0x159b00 mov r0, r3 */
/* @0x159b04 bl 0xb65bc <memcpy@plt> */
/* @0x159b08 ldr r3, [r7] */
/* @0x159b0c mov r0, r4 */
/* @0x159b10 str r6, [r4, #0x8] */
/* @0x159b14 str r3, [r4, #0x10] */
/* @0x159b18 bl 0x159824 <_Z25LinkCacheAchievementToEndP16SAchivementCache> */
/* @0x159b1c pop {r4, r5, r6, r7, r8, lr} */
/* @0x159b20 b 0x159640 <_Z21FlushAchievementCachev> */
/* @0x159b24 eoreq r6, r9, r8, lsr #2 */
/* @0x159b28 mulseq lr, r0, r10 */

/* ── FUNC 0x159b2c · Cache_ReadInt32(unsigned char*, int*) · size=56 · insn=14 */
/* @0x159b2c ldr r3, [r1] */
/* @0x159b30 str r4, [sp, #-0x4]! */
/* @0x159b34 add r4, r3, #4 */
/* @0x159b38 ldrb r2, [r0, r3]! */
/* @0x159b3c ldrb r3, [r0, #0x2] */
/* @0x159b40 ldrb r12, [r0, #0x1] */
/* @0x159b44 ldrb r0, [r0, #0x3] */
/* @0x159b48 lsl r3, r3, #16 */
/* @0x159b4c str r4, [r1] */
/* @0x159b50 orr r3, r3, r12, lsl #8 */
/* @0x159b54 ldr r4, [sp], #4 */
/* @0x159b58 orr r3, r3, r2 */
/* @0x159b5c orr r0, r3, r0, lsl #24 */
/* @0x159b60 bx lr */

/* ── FUNC 0x159b64 · Cache_ReadString(unsigned char*, int*) · size=44 · insn=11 */
/* @0x159b64 push {r4, r5, r6, lr} */
/* @0x159b68 mov r4, r1 */
/* @0x159b6c ldr r5, [r1] */
/* @0x159b70 add r6, r0, r5 */
/* @0x159b74 mov r0, r6 */
/* @0x159b78 bl 0xb6538 <strlen@plt> */
/* @0x159b7c add r3, r0, #1 */
/* @0x159b80 mov r0, r6 */
/* @0x159b84 add r5, r5, r3 */
/* @0x159b88 str r5, [r4] */
/* @0x159b8c pop {r4, r5, r6, pc} */

/* ── FUNC 0x159b90 · anon_159b90 · size=244 · insn=62 */
/* @0x159b90 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x159b94 sub sp, sp, #276 */
/* @0x159b98 ldr r9, [pc, #0xd8] */
/* @0x159b9c add r4, sp, #12 */
/* @0x159ba0 mov r6, #0 */
/* @0x159ba4 ldr r9, [pc, r9] */
/* @0x159ba8 ldr r3, [r9] */
/* @0x159bac str r3, [sp, #0x10c] */
/* @0x159bb0 bl 0x161210 <_Z20Achievement_PlayerIDv> */
/* @0x159bb4 ldr r1, [pc, #0xc0] */
/* @0x159bb8 ldr r3, [pc, #0xc0] */
/* @0x159bbc add r1, pc, r1 */
/* @0x159bc0 add r3, pc, r3 */
/* @0x159bc4 mov r2, r0 */
/* @0x159bc8 mov r0, r4 */
/* @0x159bcc bl 0xb6550 <sprintf@plt> */
/* @0x159bd0 add r1, sp, #272 */
/* @0x159bd4 mov r0, r4 */
/* @0x159bd8 str r6, [r1, #-0x10c]! */
/* @0x159bdc bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi> */
/* @0x159be0 subs r5, r0, #0 */
/* @0x159be4 beq 0x159c5c <_Z16Cache_ReadStringPhPi+0xf8> */
/* @0x159be8 ldr r4, [pc, #0x94] */
/* @0x159bec ldr r3, [sp, #0x4] */
/* @0x159bf0 ldr r4, [pc, r4] */
/* @0x159bf4 cmp r3, r6 */
/* @0x159bf8 str r6, [r4] */
/* @0x159bfc addgt r8, sp, #8 */
/* @0x159c00 ble 0x159c54 <_Z16Cache_ReadStringPhPi+0xf0> */
/* @0x159c04 mov r1, r4 */
/* @0x159c08 mov r0, r5 */
/* @0x159c0c bl 0x159b2c <_Z15Cache_ReadInt32PhPi> */
/* @0x159c10 mov r1, r4 */
/* @0x159c14 mov r6, r0 */
/* @0x159c18 mov r0, r5 */
/* @0x159c1c bl 0x159b64 <_Z16Cache_ReadStringPhPi> */
/* @0x159c20 mov r1, r4 */
/* @0x159c24 mov r7, r0 */
/* @0x159c28 mov r0, r5 */
/* @0x159c2c bl 0x159b2c <_Z15Cache_ReadInt32PhPi> */
/* @0x159c30 mov r1, r7 */
/* @0x159c34 mov r2, r8 */
/* @0x159c38 str r0, [sp, #0x8] */
/* @0x159c3c mov r0, r6 */
/* @0x159c40 bl 0x159a9c <_Z24AddAchievementCacheBlock10eCacheTypePKcPj> */
/* @0x159c44 ldr r1, [r4] */
/* @0x159c48 ldr r3, [sp, #0x4] */
/* @0x159c4c cmp r1, r3 */
/* @0x159c50 blt 0x159c04 <_Z16Cache_ReadStringPhPi+0xa0> */
/* @0x159c54 mov r0, r5 */
/* @0x159c58 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x159c5c ldr r2, [sp, #0x10c] */
/* @0x159c60 ldr r3, [r9] */
/* @0x159c64 cmp r2, r3 */
/* @0x159c68 bne 0x159c74 <_Z16Cache_ReadStringPhPi+0x110> */
/* @0x159c6c add sp, sp, #276 */
/* @0x159c70 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x159c74 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x159c78 eoreq r3, r9, r12, lsr #27 */
/* @0x159c7c andseq r11, sp, r8, lsl r0 */
/* @0x159c80 ldrsheq r12, [lr], -r8 */
/* @0x159c84 .word 0x00295ff4 */

/* ── FUNC 0x159c88 · UpdateCache(eCacheType, char const*, unsigned int) · size=56 · insn=14 */
/* @0x159c88 push {r3, lr} */
/* @0x159c8c ldr r3, [pc, #0x28] */
/* @0x159c90 ldr r3, [pc, r3] */
/* @0x159c94 ldr r3, [r3] */
/* @0x159c98 cmp r3, #0 */
/* @0x159c9c beq 0x159ca8 <_Z11UpdateCache10eCacheTypePKcj+0x20> */
/* @0x159ca0 mov r0, #0 */
/* @0x159ca4 pop {r3, pc} */
/* @0x159ca8 bl 0x161210 <_Z20Achievement_PlayerIDv> */
/* @0x159cac cmp r0, #0 */
/* @0x159cb0 beq 0x159ca0 <_Z11UpdateCache10eCacheTypePKcj+0x18> */
/* @0x159cb4 bl 0x159b90 <_Z16Cache_ReadStringPhPi+0x2c> */
/* @0x159cb8 b 0x159ca0 <_Z11UpdateCache10eCacheTypePKcj+0x18> */
/* @0x159cbc eoreq r5, r9, r4, lsr pc */

/* ── FUNC 0x159cc0 · CacheAchievement(eCacheType, char const*, unsigned int*) · size=52 · insn=13 */
/* @0x159cc0 push {r4, r5, r6, lr} */
/* @0x159cc4 mov r4, r2 */
/* @0x159cc8 ldr r2, [r2] */
/* @0x159ccc mov r6, r0 */
/* @0x159cd0 mov r5, r1 */
/* @0x159cd4 bl 0x159c88 <_Z11UpdateCache10eCacheTypePKcj> */
/* @0x159cd8 cmp r0, #0 */
/* @0x159cdc popne {r4, r5, r6, pc} */
/* @0x159ce0 mov r0, r6 */
/* @0x159ce4 mov r1, r5 */
/* @0x159ce8 mov r2, r4 */
/* @0x159cec pop {r4, r5, r6, lr} */
/* @0x159cf0 b 0x159a9c <_Z24AddAchievementCacheBlock10eCacheTypePKcPj> */

/* ── FUNC 0x159cf4 · YoYo_GetPlatform_DoWork() · size=16 · insn=4 */
/* @0x159cf4 mov r0, #0 */
/* @0x159cf8 mov r1, #0 */
/* @0x159cfc movt r1, #0x4010 */
/* @0x159d00 bx lr */

/* ── FUNC 0x159d04 · F_YoYo_GetPlatform(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x159d04 push {r4, lr} */
/* @0x159d08 mov r3, #0 */
/* @0x159d0c str r3, [r0, #0xc] */
/* @0x159d10 mov r4, r0 */
/* @0x159d14 bl 0x159cf4 <_Z23YoYo_GetPlatform_DoWorkv> */
/* @0x159d18 stm r4, {r0, r1} */
/* @0x159d1c pop {r4, pc} */

/* ── FUNC 0x159d20 · GET_YoYo_GetPlatform(CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x159d20 push {r4, lr} */
/* @0x159d24 mov r3, #0 */
/* @0x159d28 str r3, [r2, #0xc] */
/* @0x159d2c mov r4, r2 */
/* @0x159d30 bl 0x159cf4 <_Z23YoYo_GetPlatform_DoWorkv> */
/* @0x159d34 str r0, [r4] */
/* @0x159d38 mov r0, #1 */
/* @0x159d3c str r1, [r4, #0x4] */
/* @0x159d40 pop {r4, pc} */
