/* libyoyo.so 覆盖卡组 0177
 * 函数 0x1fb2c0..0x1fbcfc，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1fb2c0 · SV_Lives(CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x1fb2c0 push {r3, r4, r5, lr} */
/* @0x1fb2c4 ldr r3, [r2, #0xc] */
/* @0x1fb2c8 ldr r4, [pc, #0x68] */
/* @0x1fb2cc bic r3, r3, #-16777216 */
/* @0x1fb2d0 ldr r4, [pc, r4] */
/* @0x1fb2d4 cmp r3, #0 */
/* @0x1fb2d8 ldr r5, [r4] */
/* @0x1fb2dc bne 0x1fb310 <_Z8SV_LivesP9CInstanceiP6RValue+0x50> */
/* @0x1fb2e0 ldr r12, [r2] */
/* @0x1fb2e4 ldr r3, [r2, #0x4] */
/* @0x1fb2e8 mov r0, r12 */
/* @0x1fb2ec mov r1, r3 */
/* @0x1fb2f0 bl 0xb66e8 <lrint@plt> */
/* @0x1fb2f4 cmp r5, #0 */
/* @0x1fb2f8 str r0, [r4] */
/* @0x1fb2fc ble 0x1fb308 <_Z8SV_LivesP9CInstanceiP6RValue+0x48> */
/* @0x1fb300 cmp r0, #0 */
/* @0x1fb304 ble 0x1fb324 <_Z8SV_LivesP9CInstanceiP6RValue+0x64> */
/* @0x1fb308 mov r0, #1 */
/* @0x1fb30c pop {r3, r4, r5, pc} */
/* @0x1fb310 mov r0, r2 */
/* @0x1fb314 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb318 mov r12, r0 */
/* @0x1fb31c mov r3, r1 */
/* @0x1fb320 b 0x1fb2e8 <_Z8SV_LivesP9CInstanceiP6RValue+0x28> */
/* @0x1fb324 mov r0, #7 */
/* @0x1fb328 mov r1, #6 */
/* @0x1fb32c bl 0xf33b0 <_Z17Perform_Event_Allii> */
/* @0x1fb330 mov r0, #1 */
/* @0x1fb334 pop {r3, r4, r5, pc} */
/* @0x1fb338 andseq r4, pc, r0, lsl #2 */

/* ── FUNC 0x1fb33c · SV_Health(CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x1fb33c ldr r3, [r2, #0xc] */
/* @0x1fb340 push {r4, lr} */
/* @0x1fb344 vpush {d8} */
/* @0x1fb348 bic r3, r3, #-16777216 */
/* @0x1fb34c ldr r4, [pc, #0x60] */
/* @0x1fb350 cmp r3, #0 */
/* @0x1fb354 ldr r4, [pc, r4] */
/* @0x1fb358 vldr d8, [r4] */
/* @0x1fb35c bne 0x1fb390 <_Z9SV_HealthP9CInstanceiP6RValue+0x54> */
/* @0x1fb360 ldm r2, {r0, r1} */
/* @0x1fb364 vcmpe.f64 d8, #0 */
/* @0x1fb368 strd r0, r1, [r4] */
/* @0x1fb36c vmrs APSR_nzcv, fpscr */
/* @0x1fb370 ble 0x1fb384 <_Z9SV_HealthP9CInstanceiP6RValue+0x48> */
/* @0x1fb374 vmov d7, r0, r1 */
/* @0x1fb378 vcmpe.f64 d7, #0 */
/* @0x1fb37c vmrs APSR_nzcv, fpscr */
/* @0x1fb380 bls 0x1fb39c <_Z9SV_HealthP9CInstanceiP6RValue+0x60> */
/* @0x1fb384 vpop {d8} */
/* @0x1fb388 mov r0, #1 */
/* @0x1fb38c pop {r4, pc} */
/* @0x1fb390 mov r0, r2 */
/* @0x1fb394 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb398 b 0x1fb364 <_Z9SV_HealthP9CInstanceiP6RValue+0x28> */
/* @0x1fb39c mov r0, #7 */
/* @0x1fb3a0 mov r1, #9 */
/* @0x1fb3a4 bl 0xf33b0 <_Z17Perform_Event_Allii> */
/* @0x1fb3a8 vpop {d8} */
/* @0x1fb3ac mov r0, #1 */
/* @0x1fb3b0 pop {r4, pc} */
/* @0x1fb3b4 andseq r4, pc, r4, lsl #1 */

/* ── FUNC 0x1fb3b8 · SV_MouseLastButton(CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1fb3b8 push {r3, lr} */
/* @0x1fb3bc ldr r3, [r2, #0xc] */
/* @0x1fb3c0 bic r3, r3, #-16777216 */
/* @0x1fb3c4 cmp r3, #0 */
/* @0x1fb3c8 bne 0x1fb3f0 <_Z18SV_MouseLastButtonP9CInstanceiP6RValue+0x38> */
/* @0x1fb3cc ldr r12, [r2] */
/* @0x1fb3d0 ldr r3, [r2, #0x4] */
/* @0x1fb3d4 mov r1, r3 */
/* @0x1fb3d8 mov r0, r12 */
/* @0x1fb3dc bl 0xb66e8 <lrint@plt> */
/* @0x1fb3e0 mov r1, #0 */
/* @0x1fb3e4 bl 0x18c06c <_Z18IO_Button_Last_Setii> */
/* @0x1fb3e8 mov r0, #1 */
/* @0x1fb3ec pop {r3, pc} */
/* @0x1fb3f0 mov r0, r2 */
/* @0x1fb3f4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb3f8 mov r12, r0 */
/* @0x1fb3fc mov r3, r1 */
/* @0x1fb400 b 0x1fb3d4 <_Z18SV_MouseLastButtonP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fb404 · SV_MouseButton(CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1fb404 push {r3, lr} */
/* @0x1fb408 ldr r3, [r2, #0xc] */
/* @0x1fb40c bic r3, r3, #-16777216 */
/* @0x1fb410 cmp r3, #0 */
/* @0x1fb414 bne 0x1fb43c <_Z14SV_MouseButtonP9CInstanceiP6RValue+0x38> */
/* @0x1fb418 ldr r12, [r2] */
/* @0x1fb41c ldr r3, [r2, #0x4] */
/* @0x1fb420 mov r1, r3 */
/* @0x1fb424 mov r0, r12 */
/* @0x1fb428 bl 0xb66e8 <lrint@plt> */
/* @0x1fb42c mov r1, #0 */
/* @0x1fb430 bl 0x18c090 <_Z21IO_Button_Current_Setii> */
/* @0x1fb434 mov r0, #1 */
/* @0x1fb438 pop {r3, pc} */
/* @0x1fb43c mov r0, r2 */
/* @0x1fb440 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb444 mov r12, r0 */
/* @0x1fb448 mov r3, r1 */
/* @0x1fb44c b 0x1fb420 <_Z14SV_MouseButtonP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fb450 · SV_KeyboardLastKey(CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x1fb450 push {r3, lr} */
/* @0x1fb454 ldr r3, [r2, #0xc] */
/* @0x1fb458 bic r3, r3, #-16777216 */
/* @0x1fb45c cmp r3, #0 */
/* @0x1fb460 bne 0x1fb484 <_Z18SV_KeyboardLastKeyP9CInstanceiP6RValue+0x34> */
/* @0x1fb464 ldr r12, [r2] */
/* @0x1fb468 ldr r3, [r2, #0x4] */
/* @0x1fb46c mov r0, r12 */
/* @0x1fb470 mov r1, r3 */
/* @0x1fb474 bl 0xb66e8 <lrint@plt> */
/* @0x1fb478 bl 0x18bebc <_Z15IO_Key_Last_Seti> */
/* @0x1fb47c mov r0, #1 */
/* @0x1fb480 pop {r3, pc} */
/* @0x1fb484 mov r0, r2 */
/* @0x1fb488 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb48c mov r12, r0 */
/* @0x1fb490 mov r3, r1 */
/* @0x1fb494 b 0x1fb46c <_Z18SV_KeyboardLastKeyP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fb498 · SV_KeyboardKey(CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x1fb498 push {r3, lr} */
/* @0x1fb49c ldr r3, [r2, #0xc] */
/* @0x1fb4a0 bic r3, r3, #-16777216 */
/* @0x1fb4a4 cmp r3, #0 */
/* @0x1fb4a8 bne 0x1fb4cc <_Z14SV_KeyboardKeyP9CInstanceiP6RValue+0x34> */
/* @0x1fb4ac ldr r12, [r2] */
/* @0x1fb4b0 ldr r3, [r2, #0x4] */
/* @0x1fb4b4 mov r0, r12 */
/* @0x1fb4b8 mov r1, r3 */
/* @0x1fb4bc bl 0xb66e8 <lrint@plt> */
/* @0x1fb4c0 bl 0x18bed0 <_Z18IO_Key_Current_Seti> */
/* @0x1fb4c4 mov r0, #1 */
/* @0x1fb4c8 pop {r3, pc} */
/* @0x1fb4cc mov r0, r2 */
/* @0x1fb4d0 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb4d4 mov r12, r0 */
/* @0x1fb4d8 mov r3, r1 */
/* @0x1fb4dc b 0x1fb4b4 <_Z14SV_KeyboardKeyP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fb4e0 · SV_ShowScore(CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x1fb4e0 push {r3, lr} */
/* @0x1fb4e4 ldr r3, [r2, #0xc] */
/* @0x1fb4e8 bic r3, r3, #-16777216 */
/* @0x1fb4ec cmp r3, #0 */
/* @0x1fb4f0 bne 0x1fb548 <_Z12SV_ShowScoreP9CInstanceiP6RValue+0x68> */
/* @0x1fb4f4 ldr r12, [r2] */
/* @0x1fb4f8 ldr r3, [r2, #0x4] */
/* @0x1fb4fc mov r1, r3 */
/* @0x1fb500 mov r0, r12 */
/* @0x1fb504 bl 0xb66e8 <lrint@plt> */
/* @0x1fb508 vmov.f64 d7, #5.000000e-01 */
/* @0x1fb50c ldr r3, [pc, #0x48] */
/* @0x1fb510 mov r1, #1 */
/* @0x1fb514 ldr r2, [pc, #0x44] */
/* @0x1fb518 ldr r3, [pc, r3] */
/* @0x1fb51c ldr r2, [pc, r2] */
/* @0x1fb520 strb r1, [r2] */
/* @0x1fb524 vmov s11, r0 */
/* @0x1fb528 mov r0, r1 */
/* @0x1fb52c vcvt.f64.s32 d6, s11 */
/* @0x1fb530 vcmpe.f64 d6, d7 */
/* @0x1fb534 vmrs APSR_nzcv, fpscr */
/* @0x1fb538 movle r2, #0 */
/* @0x1fb53c movgt r2, #1 */
/* @0x1fb540 strb r2, [r3] */
/* @0x1fb544 pop {r3, pc} */
/* @0x1fb548 mov r0, r2 */
/* @0x1fb54c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb550 mov r12, r0 */
/* @0x1fb554 mov r3, r1 */
/* @0x1fb558 b 0x1fb4fc <_Z12SV_ShowScoreP9CInstanceiP6RValue+0x1c> */
/* @0x1fb55c ldrsbeq r4, [pc], -r4 */
/* @0x1fb560 andseq r4, pc, r12, asr #1 */

/* ── FUNC 0x1fb564 · SV_ShowLives(CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x1fb564 push {r3, lr} */
/* @0x1fb568 ldr r3, [r2, #0xc] */
/* @0x1fb56c bic r3, r3, #-16777216 */
/* @0x1fb570 cmp r3, #0 */
/* @0x1fb574 bne 0x1fb5bc <_Z12SV_ShowLivesP9CInstanceiP6RValue+0x58> */
/* @0x1fb578 ldr r12, [r2] */
/* @0x1fb57c ldr r3, [r2, #0x4] */
/* @0x1fb580 mov r1, r3 */
/* @0x1fb584 mov r0, r12 */
/* @0x1fb588 bl 0xb66e8 <lrint@plt> */
/* @0x1fb58c vmov.f64 d7, #5.000000e-01 */
/* @0x1fb590 ldr r3, [pc, #0x38] */
/* @0x1fb594 ldr r3, [pc, r3] */
/* @0x1fb598 vmov s11, r0 */
/* @0x1fb59c mov r0, #1 */
/* @0x1fb5a0 vcvt.f64.s32 d6, s11 */
/* @0x1fb5a4 vcmpe.f64 d6, d7 */
/* @0x1fb5a8 vmrs APSR_nzcv, fpscr */
/* @0x1fb5ac movle r2, #0 */
/* @0x1fb5b0 movgt r2, #1 */
/* @0x1fb5b4 strb r2, [r3] */
/* @0x1fb5b8 pop {r3, pc} */
/* @0x1fb5bc mov r0, r2 */
/* @0x1fb5c0 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb5c4 mov r12, r0 */
/* @0x1fb5c8 mov r3, r1 */
/* @0x1fb5cc b 0x1fb580 <_Z12SV_ShowLivesP9CInstanceiP6RValue+0x1c> */
/* @0x1fb5d0 andseq r4, pc, r0, rrx */

/* ── FUNC 0x1fb5d4 · SV_ShowHealth(CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x1fb5d4 push {r3, lr} */
/* @0x1fb5d8 ldr r3, [r2, #0xc] */
/* @0x1fb5dc bic r3, r3, #-16777216 */
/* @0x1fb5e0 cmp r3, #0 */
/* @0x1fb5e4 bne 0x1fb62c <_Z13SV_ShowHealthP9CInstanceiP6RValue+0x58> */
/* @0x1fb5e8 ldr r12, [r2] */
/* @0x1fb5ec ldr r3, [r2, #0x4] */
/* @0x1fb5f0 mov r1, r3 */
/* @0x1fb5f4 mov r0, r12 */
/* @0x1fb5f8 bl 0xb66e8 <lrint@plt> */
/* @0x1fb5fc vmov.f64 d7, #5.000000e-01 */
/* @0x1fb600 ldr r3, [pc, #0x38] */
/* @0x1fb604 ldr r3, [pc, r3] */
/* @0x1fb608 vmov s11, r0 */
/* @0x1fb60c mov r0, #1 */
/* @0x1fb610 vcvt.f64.s32 d6, s11 */
/* @0x1fb614 vcmpe.f64 d6, d7 */
/* @0x1fb618 vmrs APSR_nzcv, fpscr */
/* @0x1fb61c movle r2, #0 */
/* @0x1fb620 movgt r2, #1 */
/* @0x1fb624 strb r2, [r3] */
/* @0x1fb628 pop {r3, pc} */
/* @0x1fb62c mov r0, r2 */
/* @0x1fb630 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb634 mov r12, r0 */
/* @0x1fb638 mov r3, r1 */
/* @0x1fb63c b 0x1fb5f0 <_Z13SV_ShowHealthP9CInstanceiP6RValue+0x1c> */
/* @0x1fb640 ldrsheq r3, [pc], -r8 */

/* ── FUNC 0x1fb644 · SV_CursorSprite(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1fb644 push {r3, lr} */
/* @0x1fb648 ldr r3, [r2, #0xc] */
/* @0x1fb64c bic r3, r3, #-16777216 */
/* @0x1fb650 cmp r3, #0 */
/* @0x1fb654 bne 0x1fb680 <_Z15SV_CursorSpriteP9CInstanceiP6RValue+0x3c> */
/* @0x1fb658 ldr r12, [r2] */
/* @0x1fb65c ldr r3, [r2, #0x4] */
/* @0x1fb660 mov r1, r3 */
/* @0x1fb664 mov r0, r12 */
/* @0x1fb668 bl 0xb66e8 <lrint@plt> */
/* @0x1fb66c ldr r3, [pc, #0x20] */
/* @0x1fb670 ldr r3, [pc, r3] */
/* @0x1fb674 str r0, [r3] */
/* @0x1fb678 mov r0, #1 */
/* @0x1fb67c pop {r3, pc} */
/* @0x1fb680 mov r0, r2 */
/* @0x1fb684 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb688 mov r12, r0 */
/* @0x1fb68c mov r3, r1 */
/* @0x1fb690 b 0x1fb660 <_Z15SV_CursorSpriteP9CInstanceiP6RValue+0x1c> */
/* @0x1fb694 andseq r3, pc, r8, ror sp */

/* ── FUNC 0x1fb698 · SV_HSpeed(CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1fb698 ldr r3, [r2, #0xc] */
/* @0x1fb69c push {r4, r5, r6, lr} */
/* @0x1fb6a0 bic r3, r3, #-16777216 */
/* @0x1fb6a4 cmp r3, #0 */
/* @0x1fb6a8 mov r6, r0 */
/* @0x1fb6ac bne 0x1fb6d0 <_Z9SV_HSpeedP9CInstanceiP6RValue+0x38> */
/* @0x1fb6b0 ldm r2, {r4, r5} */
/* @0x1fb6b4 vmov d7, r4, r5 */
/* @0x1fb6b8 mov r0, r6 */
/* @0x1fb6bc vcvt.f32.f64 s15, d7 */
/* @0x1fb6c0 vmov r1, s15 */
/* @0x1fb6c4 bl 0x1930f4 <_ZN9CInstance9SetHspeedEf> */
/* @0x1fb6c8 mov r0, #1 */
/* @0x1fb6cc pop {r4, r5, r6, pc} */
/* @0x1fb6d0 mov r0, r2 */
/* @0x1fb6d4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb6d8 mov r4, r0 */
/* @0x1fb6dc mov r5, r1 */
/* @0x1fb6e0 b 0x1fb6b4 <_Z9SV_HSpeedP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fb6e4 · SV_VSpeed(CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1fb6e4 ldr r3, [r2, #0xc] */
/* @0x1fb6e8 push {r4, r5, r6, lr} */
/* @0x1fb6ec bic r3, r3, #-16777216 */
/* @0x1fb6f0 cmp r3, #0 */
/* @0x1fb6f4 mov r6, r0 */
/* @0x1fb6f8 bne 0x1fb71c <_Z9SV_VSpeedP9CInstanceiP6RValue+0x38> */
/* @0x1fb6fc ldm r2, {r4, r5} */
/* @0x1fb700 vmov d7, r4, r5 */
/* @0x1fb704 mov r0, r6 */
/* @0x1fb708 vcvt.f32.f64 s15, d7 */
/* @0x1fb70c vmov r1, s15 */
/* @0x1fb710 bl 0x193114 <_ZN9CInstance9SetVspeedEf> */
/* @0x1fb714 mov r0, #1 */
/* @0x1fb718 pop {r4, r5, r6, pc} */
/* @0x1fb71c mov r0, r2 */
/* @0x1fb720 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb724 mov r4, r0 */
/* @0x1fb728 mov r5, r1 */
/* @0x1fb72c b 0x1fb700 <_Z9SV_VSpeedP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fb730 · SV_Direction(CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1fb730 ldr r3, [r2, #0xc] */
/* @0x1fb734 push {r4, r5, r6, lr} */
/* @0x1fb738 bic r3, r3, #-16777216 */
/* @0x1fb73c cmp r3, #0 */
/* @0x1fb740 mov r6, r0 */
/* @0x1fb744 bne 0x1fb768 <_Z12SV_DirectionP9CInstanceiP6RValue+0x38> */
/* @0x1fb748 ldm r2, {r4, r5} */
/* @0x1fb74c vmov d7, r4, r5 */
/* @0x1fb750 mov r0, r6 */
/* @0x1fb754 vcvt.f32.f64 s15, d7 */
/* @0x1fb758 vmov r1, s15 */
/* @0x1fb75c bl 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x1fb760 mov r0, #1 */
/* @0x1fb764 pop {r4, r5, r6, pc} */
/* @0x1fb768 mov r0, r2 */
/* @0x1fb76c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb770 mov r4, r0 */
/* @0x1fb774 mov r5, r1 */
/* @0x1fb778 b 0x1fb74c <_Z12SV_DirectionP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fb77c · SV_Speed(CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1fb77c ldr r3, [r2, #0xc] */
/* @0x1fb780 push {r4, r5, r6, lr} */
/* @0x1fb784 bic r3, r3, #-16777216 */
/* @0x1fb788 cmp r3, #0 */
/* @0x1fb78c mov r6, r0 */
/* @0x1fb790 bne 0x1fb7b4 <_Z8SV_SpeedP9CInstanceiP6RValue+0x38> */
/* @0x1fb794 ldm r2, {r4, r5} */
/* @0x1fb798 vmov d7, r4, r5 */
/* @0x1fb79c mov r0, r6 */
/* @0x1fb7a0 vcvt.f32.f64 s15, d7 */
/* @0x1fb7a4 vmov r1, s15 */
/* @0x1fb7a8 bl 0x1930d4 <_ZN9CInstance8SetSpeedEf> */
/* @0x1fb7ac mov r0, #1 */
/* @0x1fb7b0 pop {r4, r5, r6, pc} */
/* @0x1fb7b4 mov r0, r2 */
/* @0x1fb7b8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb7bc mov r4, r0 */
/* @0x1fb7c0 mov r5, r1 */
/* @0x1fb7c4 b 0x1fb798 <_Z8SV_SpeedP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fb7c8 · SV_Alarm(CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x1fb7c8 push {r3, r4, r5, lr} */
/* @0x1fb7cc cmp r1, #11 */
/* @0x1fb7d0 ldr r3, [r2, #0xc] */
/* @0x1fb7d4 mov r5, r0 */
/* @0x1fb7d8 movls r4, r1 */
/* @0x1fb7dc movhi r4, #0 */
/* @0x1fb7e0 bic r3, r3, #-16777216 */
/* @0x1fb7e4 cmp r3, #0 */
/* @0x1fb7e8 bne 0x1fb81c <_Z8SV_AlarmP9CInstanceiP6RValue+0x54> */
/* @0x1fb7ec ldm r2, {r0, r1} */
/* @0x1fb7f0 vmov d6, r0, r1 */
/* @0x1fb7f4 vcvt.f32.f64 s15, d6 */
/* @0x1fb7f8 vcvt.f64.f32 d6, s15 */
/* @0x1fb7fc vmov r0, r1, d6 */
/* @0x1fb800 bl 0xb66e8 <lrint@plt> */
/* @0x1fb804 mov r1, r4 */
/* @0x1fb808 mov r2, r0 */
/* @0x1fb80c mov r0, r5 */
/* @0x1fb810 bl 0x193148 <_ZN9CInstance8SetTimerEii> */
/* @0x1fb814 mov r0, #1 */
/* @0x1fb818 pop {r3, r4, r5, pc} */
/* @0x1fb81c mov r0, r2 */
/* @0x1fb820 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb824 b 0x1fb7f0 <_Z8SV_AlarmP9CInstanceiP6RValue+0x28> */

/* ── FUNC 0x1fb828 · SV_ImageXScale(CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1fb828 ldr r3, [r2, #0xc] */
/* @0x1fb82c push {r4, r5, r6, lr} */
/* @0x1fb830 bic r3, r3, #-16777216 */
/* @0x1fb834 cmp r3, #0 */
/* @0x1fb838 mov r6, r0 */
/* @0x1fb83c bne 0x1fb860 <_Z14SV_ImageXScaleP9CInstanceiP6RValue+0x38> */
/* @0x1fb840 ldm r2, {r4, r5} */
/* @0x1fb844 vmov d7, r4, r5 */
/* @0x1fb848 mov r0, r6 */
/* @0x1fb84c vcvt.f32.f64 s15, d7 */
/* @0x1fb850 vmov r1, s15 */
/* @0x1fb854 bl 0x192fec <_ZN9CInstance14SetImageScaleXEf> */
/* @0x1fb858 mov r0, #1 */
/* @0x1fb85c pop {r4, r5, r6, pc} */
/* @0x1fb860 mov r0, r2 */
/* @0x1fb864 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb868 mov r4, r0 */
/* @0x1fb86c mov r5, r1 */
/* @0x1fb870 b 0x1fb844 <_Z14SV_ImageXScaleP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fb874 · SV_ImageYScale(CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1fb874 ldr r3, [r2, #0xc] */
/* @0x1fb878 push {r4, r5, r6, lr} */
/* @0x1fb87c bic r3, r3, #-16777216 */
/* @0x1fb880 cmp r3, #0 */
/* @0x1fb884 mov r6, r0 */
/* @0x1fb888 bne 0x1fb8ac <_Z14SV_ImageYScaleP9CInstanceiP6RValue+0x38> */
/* @0x1fb88c ldm r2, {r4, r5} */
/* @0x1fb890 vmov d7, r4, r5 */
/* @0x1fb894 mov r0, r6 */
/* @0x1fb898 vcvt.f32.f64 s15, d7 */
/* @0x1fb89c vmov r1, s15 */
/* @0x1fb8a0 bl 0x193014 <_ZN9CInstance14SetImageScaleYEf> */
/* @0x1fb8a4 mov r0, #1 */
/* @0x1fb8a8 pop {r4, r5, r6, pc} */
/* @0x1fb8ac mov r0, r2 */
/* @0x1fb8b0 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb8b4 mov r4, r0 */
/* @0x1fb8b8 mov r5, r1 */
/* @0x1fb8bc b 0x1fb890 <_Z14SV_ImageYScaleP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fb8c0 · SV_ImageAngle(CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x1fb8c0 ldr r3, [pc, #0x6c] */
/* @0x1fb8c4 push {r4, r5, r6, lr} */
/* @0x1fb8c8 ldr r3, [pc, r3] */
/* @0x1fb8cc mov r6, r0 */
/* @0x1fb8d0 ldrb r1, [r3] */
/* @0x1fb8d4 cmp r1, #0 */
/* @0x1fb8d8 beq 0x1fb920 <_Z13SV_ImageAngleP9CInstanceiP6RValue+0x60> */
/* @0x1fb8dc ldr r3, [r2, #0xc] */
/* @0x1fb8e0 bic r3, r3, #-16777216 */
/* @0x1fb8e4 cmp r3, #0 */
/* @0x1fb8e8 bne 0x1fb90c <_Z13SV_ImageAngleP9CInstanceiP6RValue+0x4c> */
/* @0x1fb8ec ldm r2, {r4, r5} */
/* @0x1fb8f0 vmov d7, r4, r5 */
/* @0x1fb8f4 mov r0, r6 */
/* @0x1fb8f8 vcvt.f32.f64 s15, d7 */
/* @0x1fb8fc vmov r1, s15 */
/* @0x1fb900 bl 0x19303c <_ZN9CInstance13SetImageAngleEf> */
/* @0x1fb904 mov r0, #1 */
/* @0x1fb908 pop {r4, r5, r6, pc} */
/* @0x1fb90c mov r0, r2 */
/* @0x1fb910 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb914 mov r4, r0 */
/* @0x1fb918 mov r5, r1 */
/* @0x1fb91c b 0x1fb8f0 <_Z13SV_ImageAngleP9CInstanceiP6RValue+0x30> */
/* @0x1fb920 ldr r0, [pc, #0x10] */
/* @0x1fb924 add r0, pc, r0 */
/* @0x1fb928 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1fb92c mov r0, #1 */
/* @0x1fb930 pop {r4, r5, r6, pc} */
/* @0x1fb934 ldrsheq r5, [pc], -r4 */
/* @0x1fb938 andseq r7, r5, r4, asr r0 */

/* ── FUNC 0x1fb93c · SV_MaskIndex(CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1fb93c ldr r3, [r2, #0xc] */
/* @0x1fb940 push {r4, lr} */
/* @0x1fb944 bic r3, r3, #-16777216 */
/* @0x1fb948 cmp r3, #0 */
/* @0x1fb94c mov r4, r0 */
/* @0x1fb950 bne 0x1fb980 <_Z12SV_MaskIndexP9CInstanceiP6RValue+0x44> */
/* @0x1fb954 ldm r2, {r0, r1} */
/* @0x1fb958 vmov d6, r0, r1 */
/* @0x1fb95c vcvt.f32.f64 s15, d6 */
/* @0x1fb960 vcvt.f64.f32 d6, s15 */
/* @0x1fb964 vmov r0, r1, d6 */
/* @0x1fb968 bl 0xb66e8 <lrint@plt> */
/* @0x1fb96c mov r1, r0 */
/* @0x1fb970 mov r0, r4 */
/* @0x1fb974 bl 0x192ba8 <_ZN9CInstance13Set_MaskIndexEi> */
/* @0x1fb978 mov r0, #1 */
/* @0x1fb97c pop {r4, pc} */
/* @0x1fb980 mov r0, r2 */
/* @0x1fb984 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb988 b 0x1fb958 <_Z12SV_MaskIndexP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fb98c · SV_PathPosition(CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1fb98c ldr r3, [r2, #0xc] */
/* @0x1fb990 push {r4, r5, r6, lr} */
/* @0x1fb994 bic r3, r3, #-16777216 */
/* @0x1fb998 cmp r3, #0 */
/* @0x1fb99c mov r6, r0 */
/* @0x1fb9a0 bne 0x1fb9c4 <_Z15SV_PathPositionP9CInstanceiP6RValue+0x38> */
/* @0x1fb9a4 ldm r2, {r4, r5} */
/* @0x1fb9a8 vmov d7, r4, r5 */
/* @0x1fb9ac mov r0, r6 */
/* @0x1fb9b0 vcvt.f32.f64 s15, d7 */
/* @0x1fb9b4 vmov r1, s15 */
/* @0x1fb9b8 bl 0x1935c4 <_ZN9CInstance15SetPathPositionEf> */
/* @0x1fb9bc mov r0, #1 */
/* @0x1fb9c0 pop {r4, r5, r6, pc} */
/* @0x1fb9c4 mov r0, r2 */
/* @0x1fb9c8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb9cc mov r4, r0 */
/* @0x1fb9d0 mov r5, r1 */
/* @0x1fb9d4 b 0x1fb9a8 <_Z15SV_PathPositionP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fb9d8 · SV_PathPositionPrevious(CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1fb9d8 ldr r3, [r2, #0xc] */
/* @0x1fb9dc push {r4, r5, r6, lr} */
/* @0x1fb9e0 bic r3, r3, #-16777216 */
/* @0x1fb9e4 cmp r3, #0 */
/* @0x1fb9e8 mov r6, r0 */
/* @0x1fb9ec bne 0x1fba10 <_Z23SV_PathPositionPreviousP9CInstanceiP6RValue+0x38> */
/* @0x1fb9f0 ldm r2, {r4, r5} */
/* @0x1fb9f4 vmov d7, r4, r5 */
/* @0x1fb9f8 mov r0, r6 */
/* @0x1fb9fc vcvt.f32.f64 s15, d7 */
/* @0x1fba00 vmov r1, s15 */
/* @0x1fba04 bl 0x1935fc <_ZN9CInstance23SetPathPositionPreviousEf> */
/* @0x1fba08 mov r0, #1 */
/* @0x1fba0c pop {r4, r5, r6, pc} */
/* @0x1fba10 mov r0, r2 */
/* @0x1fba14 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fba18 mov r4, r0 */
/* @0x1fba1c mov r5, r1 */
/* @0x1fba20 b 0x1fb9f4 <_Z23SV_PathPositionPreviousP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fba24 · SV_PathSpeed(CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1fba24 ldr r3, [r2, #0xc] */
/* @0x1fba28 push {r4, r5, r6, lr} */
/* @0x1fba2c bic r3, r3, #-16777216 */
/* @0x1fba30 cmp r3, #0 */
/* @0x1fba34 mov r6, r0 */
/* @0x1fba38 bne 0x1fba5c <_Z12SV_PathSpeedP9CInstanceiP6RValue+0x38> */
/* @0x1fba3c ldm r2, {r4, r5} */
/* @0x1fba40 vmov d7, r4, r5 */
/* @0x1fba44 mov r0, r6 */
/* @0x1fba48 vcvt.f32.f64 s15, d7 */
/* @0x1fba4c vmov r1, s15 */
/* @0x1fba50 bl 0x193634 <_ZN9CInstance12SetPathSpeedEf> */
/* @0x1fba54 mov r0, #1 */
/* @0x1fba58 pop {r4, r5, r6, pc} */
/* @0x1fba5c mov r0, r2 */
/* @0x1fba60 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fba64 mov r4, r0 */
/* @0x1fba68 mov r5, r1 */
/* @0x1fba6c b 0x1fba40 <_Z12SV_PathSpeedP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fba70 · SV_ImageIndex(CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1fba70 ldr r3, [r2, #0xc] */
/* @0x1fba74 push {r4, lr} */
/* @0x1fba78 bic r3, r3, #-16777216 */
/* @0x1fba7c cmp r3, #0 */
/* @0x1fba80 mov r4, r0 */
/* @0x1fba84 bne 0x1fbaa0 <_Z13SV_ImageIndexP9CInstanceiP6RValue+0x30> */
/* @0x1fba88 ldm r2, {r0, r1} */
/* @0x1fba8c vmov d6, r0, r1 */
/* @0x1fba90 mov r0, #1 */
/* @0x1fba94 vcvt.f32.f64 s15, d6 */
/* @0x1fba98 vstr s15, [r4, #144] */
/* @0x1fba9c pop {r4, pc} */
/* @0x1fbaa0 mov r0, r2 */
/* @0x1fbaa4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbaa8 b 0x1fba8c <_Z13SV_ImageIndexP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fbaac · SV_ImageSingle(CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x1fbaac push {r3, r4, r5, lr} */
/* @0x1fbab0 mov r4, r2 */
/* @0x1fbab4 ldr r3, [r2, #0xc] */
/* @0x1fbab8 mov r5, r0 */
/* @0x1fbabc bic r3, r3, #-16777216 */
/* @0x1fbac0 cmp r3, #0 */
/* @0x1fbac4 bne 0x1fbb14 <_Z14SV_ImageSingleP9CInstanceiP6RValue+0x68> */
/* @0x1fbac8 ldm r2, {r0, r1} */
/* @0x1fbacc vmov d6, r0, r1 */
/* @0x1fbad0 vcmpe.f64 d6, #0 */
/* @0x1fbad4 vmrs APSR_nzcv, fpscr */
/* @0x1fbad8 movmi r3, #1065353216 */
/* @0x1fbadc strmi r3, [r5, #0x94] */
/* @0x1fbae0 bmi 0x1fbb0c <_Z14SV_ImageSingleP9CInstanceiP6RValue+0x60> */
/* @0x1fbae4 ldr r3, [r4, #0xc] */
/* @0x1fbae8 bic r3, r3, #-16777216 */
/* @0x1fbaec cmp r3, #0 */
/* @0x1fbaf0 bne 0x1fbb20 <_Z14SV_ImageSingleP9CInstanceiP6RValue+0x74> */
/* @0x1fbaf4 ldm r4, {r0, r1} */
/* @0x1fbaf8 vmov d6, r0, r1 */
/* @0x1fbafc mov r3, #0 */
/* @0x1fbb00 str r3, [r5, #0x94] */
/* @0x1fbb04 vcvt.f32.f64 s15, d6 */
/* @0x1fbb08 vstr s15, [r5, #144] */
/* @0x1fbb0c mov r0, #1 */
/* @0x1fbb10 pop {r3, r4, r5, pc} */
/* @0x1fbb14 mov r0, r2 */
/* @0x1fbb18 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbb1c b 0x1fbacc <_Z14SV_ImageSingleP9CInstanceiP6RValue+0x20> */
/* @0x1fbb20 mov r0, r4 */
/* @0x1fbb24 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbb28 b 0x1fbaf8 <_Z14SV_ImageSingleP9CInstanceiP6RValue+0x4c> */

/* ── FUNC 0x1fbb2c · SV_ImageSpeed(CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1fbb2c ldr r3, [r2, #0xc] */
/* @0x1fbb30 push {r4, lr} */
/* @0x1fbb34 bic r3, r3, #-16777216 */
/* @0x1fbb38 cmp r3, #0 */
/* @0x1fbb3c mov r4, r0 */
/* @0x1fbb40 bne 0x1fbb5c <_Z13SV_ImageSpeedP9CInstanceiP6RValue+0x30> */
/* @0x1fbb44 ldm r2, {r0, r1} */
/* @0x1fbb48 vmov d6, r0, r1 */
/* @0x1fbb4c mov r0, #1 */
/* @0x1fbb50 vcvt.f32.f64 s15, d6 */
/* @0x1fbb54 vstr s15, [r4, #148] */
/* @0x1fbb58 pop {r4, pc} */
/* @0x1fbb5c mov r0, r2 */
/* @0x1fbb60 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbb64 b 0x1fbb48 <_Z13SV_ImageSpeedP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fbb68 · SV_ImageAlpha(CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1fbb68 ldr r3, [r2, #0xc] */
/* @0x1fbb6c push {r4, lr} */
/* @0x1fbb70 bic r3, r3, #-16777216 */
/* @0x1fbb74 cmp r3, #0 */
/* @0x1fbb78 mov r4, r0 */
/* @0x1fbb7c bne 0x1fbb98 <_Z13SV_ImageAlphaP9CInstanceiP6RValue+0x30> */
/* @0x1fbb80 ldm r2, {r0, r1} */
/* @0x1fbb84 vmov d6, r0, r1 */
/* @0x1fbb88 mov r0, #1 */
/* @0x1fbb8c vcvt.f32.f64 s15, d6 */
/* @0x1fbb90 vstr s15, [r4, #164] */
/* @0x1fbb94 pop {r4, pc} */
/* @0x1fbb98 mov r0, r2 */
/* @0x1fbb9c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbba0 b 0x1fbb84 <_Z13SV_ImageAlphaP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fbba4 · SV_Y(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1fbba4 push {r3, r4, r5, r6, r7, lr} */
/* @0x1fbba8 mov r6, r0 */
/* @0x1fbbac ldr r3, [r2, #0xc] */
/* @0x1fbbb0 ldr r7, [r0, #0xb4] */
/* @0x1fbbb4 bic r3, r3, #-16777216 */
/* @0x1fbbb8 cmp r3, #0 */
/* @0x1fbbbc bne 0x1fbbe4 <_Z4SV_YP9CInstanceiP6RValue+0x40> */
/* @0x1fbbc0 ldm r2, {r4, r5} */
/* @0x1fbbc4 vmov d7, r4, r5 */
/* @0x1fbbc8 mov r0, r6 */
/* @0x1fbbcc mov r1, r7 */
/* @0x1fbbd0 vcvt.f32.f64 s15, d7 */
/* @0x1fbbd4 vmov r2, s15 */
/* @0x1fbbd8 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1fbbdc mov r0, #1 */
/* @0x1fbbe0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1fbbe4 mov r0, r2 */
/* @0x1fbbe8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbbec mov r4, r0 */
/* @0x1fbbf0 mov r5, r1 */
/* @0x1fbbf4 b 0x1fbbc4 <_Z4SV_YP9CInstanceiP6RValue+0x20> */

/* ── FUNC 0x1fbbf8 · SV_X(CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1fbbf8 ldr r3, [r2, #0xc] */
/* @0x1fbbfc push {r4, r5, r6, lr} */
/* @0x1fbc00 bic r3, r3, #-16777216 */
/* @0x1fbc04 cmp r3, #0 */
/* @0x1fbc08 mov r6, r0 */
/* @0x1fbc0c bne 0x1fbc34 <_Z4SV_XP9CInstanceiP6RValue+0x3c> */
/* @0x1fbc10 ldm r2, {r4, r5} */
/* @0x1fbc14 vmov d7, r4, r5 */
/* @0x1fbc18 mov r0, r6 */
/* @0x1fbc1c ldr r2, [r6, #0xb8] */
/* @0x1fbc20 vcvt.f32.f64 s15, d7 */
/* @0x1fbc24 vmov r1, s15 */
/* @0x1fbc28 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1fbc2c mov r0, #1 */
/* @0x1fbc30 pop {r4, r5, r6, pc} */
/* @0x1fbc34 mov r0, r2 */
/* @0x1fbc38 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbc3c mov r4, r0 */
/* @0x1fbc40 mov r5, r1 */
/* @0x1fbc44 b 0x1fbc14 <_Z4SV_XP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fbc48 · SV_XPrevious(CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1fbc48 ldr r3, [r2, #0xc] */
/* @0x1fbc4c push {r4, lr} */
/* @0x1fbc50 bic r3, r3, #-16777216 */
/* @0x1fbc54 cmp r3, #0 */
/* @0x1fbc58 mov r4, r0 */
/* @0x1fbc5c bne 0x1fbc78 <_Z12SV_XPreviousP9CInstanceiP6RValue+0x30> */
/* @0x1fbc60 ldm r2, {r0, r1} */
/* @0x1fbc64 vmov d6, r0, r1 */
/* @0x1fbc68 mov r0, #1 */
/* @0x1fbc6c vcvt.f32.f64 s15, d6 */
/* @0x1fbc70 vstr s15, [r4, #196] */
/* @0x1fbc74 pop {r4, pc} */
/* @0x1fbc78 mov r0, r2 */
/* @0x1fbc7c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbc80 b 0x1fbc64 <_Z12SV_XPreviousP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fbc84 · SV_YPrevious(CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1fbc84 ldr r3, [r2, #0xc] */
/* @0x1fbc88 push {r4, lr} */
/* @0x1fbc8c bic r3, r3, #-16777216 */
/* @0x1fbc90 cmp r3, #0 */
/* @0x1fbc94 mov r4, r0 */
/* @0x1fbc98 bne 0x1fbcb4 <_Z12SV_YPreviousP9CInstanceiP6RValue+0x30> */
/* @0x1fbc9c ldm r2, {r0, r1} */
/* @0x1fbca0 vmov d6, r0, r1 */
/* @0x1fbca4 mov r0, #1 */
/* @0x1fbca8 vcvt.f32.f64 s15, d6 */
/* @0x1fbcac vstr s15, [r4, #200] */
/* @0x1fbcb0 pop {r4, pc} */
/* @0x1fbcb4 mov r0, r2 */
/* @0x1fbcb8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbcbc b 0x1fbca0 <_Z12SV_YPreviousP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fbcc0 · SV_XStart(CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1fbcc0 ldr r3, [r2, #0xc] */
/* @0x1fbcc4 push {r4, lr} */
/* @0x1fbcc8 bic r3, r3, #-16777216 */
/* @0x1fbccc cmp r3, #0 */
/* @0x1fbcd0 mov r4, r0 */
/* @0x1fbcd4 bne 0x1fbcf0 <_Z9SV_XStartP9CInstanceiP6RValue+0x30> */
/* @0x1fbcd8 ldm r2, {r0, r1} */
/* @0x1fbcdc vmov d6, r0, r1 */
/* @0x1fbce0 mov r0, #1 */
/* @0x1fbce4 vcvt.f32.f64 s15, d6 */
/* @0x1fbce8 vstr s15, [r4, #188] */
/* @0x1fbcec pop {r4, pc} */
/* @0x1fbcf0 mov r0, r2 */
/* @0x1fbcf4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbcf8 b 0x1fbcdc <_Z9SV_XStartP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fbcfc · SV_YStart(CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1fbcfc ldr r3, [r2, #0xc] */
/* @0x1fbd00 push {r4, lr} */
/* @0x1fbd04 bic r3, r3, #-16777216 */
/* @0x1fbd08 cmp r3, #0 */
/* @0x1fbd0c mov r4, r0 */
/* @0x1fbd10 bne 0x1fbd2c <_Z9SV_YStartP9CInstanceiP6RValue+0x30> */
/* @0x1fbd14 ldm r2, {r0, r1} */
/* @0x1fbd18 vmov d6, r0, r1 */
/* @0x1fbd1c mov r0, #1 */
/* @0x1fbd20 vcvt.f32.f64 s15, d6 */
/* @0x1fbd24 vstr s15, [r4, #192] */
/* @0x1fbd28 pop {r4, pc} */
/* @0x1fbd2c mov r0, r2 */
/* @0x1fbd30 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbd34 b 0x1fbd18 <_Z9SV_YStartP9CInstanceiP6RValue+0x1c> */
