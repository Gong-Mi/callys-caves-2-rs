/* libyoyo.so 覆盖卡组 0067
 * 函数 0x135214..0x135c64，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x135214 · F_AudioSoundPitch(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x135214 push {r3, r4, r5, lr} */
/* @0x135218 ldr r3, [pc, #0x38] */
/* @0x13521c ldr r4, [sp, #0x10] */
/* @0x135220 ldr r3, [pc, r3] */
/* @0x135224 ldrb r1, [r3] */
/* @0x135228 cmp r1, #0 */
/* @0x13522c popne {r3, r4, r5, pc} */
/* @0x135230 mov r0, r4 */
/* @0x135234 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135238 mov r1, #1 */
/* @0x13523c mov r5, r0 */
/* @0x135240 mov r0, r4 */
/* @0x135244 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x135248 mov r1, r0 */
/* @0x13524c mov r0, r5 */
/* @0x135250 pop {r3, r4, r5, lr} */
/* @0x135254 b 0x217460 <_Z16Audio_SoundPitchif> */
/* @0x135258 eoreq r9, r11, r12, lsr #28 */

/* ── FUNC 0x13525c · F_AudioSoundLength(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x13525c ldr r3, [pc, #0x40] */
/* @0x135260 push {r4, lr} */
/* @0x135264 ldr r3, [pc, r3] */
/* @0x135268 mov r4, r0 */
/* @0x13526c ldrb r1, [r3] */
/* @0x135270 cmp r1, #0 */
/* @0x135274 popne {r4, pc} */
/* @0x135278 str r1, [r0, #0xc] */
/* @0x13527c ldr r0, [sp, #0x8] */
/* @0x135280 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135284 bl 0x218640 <_Z17Audio_SoundLengthi> */
/* @0x135288 vmov s15, r0 */
/* @0x13528c vcvt.f64.f32 d7, s15 */
/* @0x135290 vmov r0, r1, d7 */
/* @0x135294 vmov r2, s14 */
/* @0x135298 mov r3, r1 */
/* @0x13529c stm r4, {r2, r3} */
/* @0x1352a0 pop {r4, pc} */
/* @0x1352a4 eoreq r9, r11, r8, ror #27 */

/* ── FUNC 0x1352a8 · F_AudioGetEmitterGain(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1352a8 ldr r3, [pc, #0x40] */
/* @0x1352ac push {r4, lr} */
/* @0x1352b0 ldr r3, [pc, r3] */
/* @0x1352b4 mov r4, r0 */
/* @0x1352b8 ldrb r1, [r3] */
/* @0x1352bc cmp r1, #0 */
/* @0x1352c0 popne {r4, pc} */
/* @0x1352c4 str r1, [r0, #0xc] */
/* @0x1352c8 ldr r0, [sp, #0x8] */
/* @0x1352cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1352d0 bl 0x2180ac <_Z20Audio_GetEmitterGaini> */
/* @0x1352d4 vmov s15, r0 */
/* @0x1352d8 vcvt.f64.f32 d7, s15 */
/* @0x1352dc vmov r0, r1, d7 */
/* @0x1352e0 vmov r2, s14 */
/* @0x1352e4 mov r3, r1 */
/* @0x1352e8 stm r4, {r2, r3} */
/* @0x1352ec pop {r4, pc} */
/* @0x1352f0 mlaeq r11, r12, sp, r9 */

/* ── FUNC 0x1352f4 · F_AudioGetEmitterPitch(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1352f4 ldr r3, [pc, #0x40] */
/* @0x1352f8 push {r4, lr} */
/* @0x1352fc ldr r3, [pc, r3] */
/* @0x135300 mov r4, r0 */
/* @0x135304 ldrb r1, [r3] */
/* @0x135308 cmp r1, #0 */
/* @0x13530c popne {r4, pc} */
/* @0x135310 str r1, [r0, #0xc] */
/* @0x135314 ldr r0, [sp, #0x8] */
/* @0x135318 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13531c bl 0x2182e0 <_Z21Audio_GetEmitterPitchi> */
/* @0x135320 vmov s15, r0 */
/* @0x135324 vcvt.f64.f32 d7, s15 */
/* @0x135328 vmov r0, r1, d7 */
/* @0x13532c vmov r2, s14 */
/* @0x135330 mov r3, r1 */
/* @0x135334 stm r4, {r2, r3} */
/* @0x135338 pop {r4, pc} */
/* @0x13533c eoreq r9, r11, r0, asr sp */

/* ── FUNC 0x135340 · F_AudioGetEmitterPositionX(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x135340 ldr r3, [pc, #0x50] */
/* @0x135344 push {r4, lr} */
/* @0x135348 ldr r3, [pc, r3] */
/* @0x13534c sub sp, sp, #16 */
/* @0x135350 mov r4, r0 */
/* @0x135354 ldrb r1, [r3] */
/* @0x135358 cmp r1, #0 */
/* @0x13535c beq 0x135368 <_Z26F_AudioGetEmitterPositionXR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x135360 add sp, sp, #16 */
/* @0x135364 pop {r4, pc} */
/* @0x135368 str r1, [r0, #0xc] */
/* @0x13536c ldr r0, [sp, #0x18] */
/* @0x135370 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135374 mov r1, r0 */
/* @0x135378 add r0, sp, #4 */
/* @0x13537c bl 0x216e6c <_Z24Audio_GetEmitterPositioni> */
/* @0x135380 vldr s15, [sp, #4] */
/* @0x135384 vcvt.f64.f32 d6, s15 */
/* @0x135388 vmov r2, r3, d6 */
/* @0x13538c stm r4, {r2, r3} */
/* @0x135390 add sp, sp, #16 */
/* @0x135394 pop {r4, pc} */
/* @0x135398 eoreq r9, r11, r4, lsl #26 */

/* ── FUNC 0x13539c · F_AudioGetEmitterPositionY(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x13539c ldr r3, [pc, #0x50] */
/* @0x1353a0 push {r4, lr} */
/* @0x1353a4 ldr r3, [pc, r3] */
/* @0x1353a8 sub sp, sp, #16 */
/* @0x1353ac mov r4, r0 */
/* @0x1353b0 ldrb r1, [r3] */
/* @0x1353b4 cmp r1, #0 */
/* @0x1353b8 beq 0x1353c4 <_Z26F_AudioGetEmitterPositionYR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x1353bc add sp, sp, #16 */
/* @0x1353c0 pop {r4, pc} */
/* @0x1353c4 str r1, [r0, #0xc] */
/* @0x1353c8 ldr r0, [sp, #0x18] */
/* @0x1353cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1353d0 mov r1, r0 */
/* @0x1353d4 add r0, sp, #4 */
/* @0x1353d8 bl 0x216e6c <_Z24Audio_GetEmitterPositioni> */
/* @0x1353dc vldr s15, [sp, #8] */
/* @0x1353e0 vcvt.f64.f32 d6, s15 */
/* @0x1353e4 vmov r2, r3, d6 */
/* @0x1353e8 stm r4, {r2, r3} */
/* @0x1353ec add sp, sp, #16 */
/* @0x1353f0 pop {r4, pc} */
/* @0x1353f4 eoreq r9, r11, r8, lsr #25 */

/* ── FUNC 0x1353f8 · F_AudioGetEmitterPositionZ(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x1353f8 ldr r3, [pc, #0x50] */
/* @0x1353fc push {r4, lr} */
/* @0x135400 ldr r3, [pc, r3] */
/* @0x135404 sub sp, sp, #16 */
/* @0x135408 mov r4, r0 */
/* @0x13540c ldrb r1, [r3] */
/* @0x135410 cmp r1, #0 */
/* @0x135414 beq 0x135420 <_Z26F_AudioGetEmitterPositionZR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x135418 add sp, sp, #16 */
/* @0x13541c pop {r4, pc} */
/* @0x135420 str r1, [r0, #0xc] */
/* @0x135424 ldr r0, [sp, #0x18] */
/* @0x135428 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13542c mov r1, r0 */
/* @0x135430 add r0, sp, #4 */
/* @0x135434 bl 0x216e6c <_Z24Audio_GetEmitterPositioni> */
/* @0x135438 vldr s15, [sp, #12] */
/* @0x13543c vcvt.f64.f32 d6, s15 */
/* @0x135440 vmov r2, r3, d6 */
/* @0x135444 stm r4, {r2, r3} */
/* @0x135448 add sp, sp, #16 */
/* @0x13544c pop {r4, pc} */
/* @0x135450 eoreq r9, r11, r12, asr #24 */

/* ── FUNC 0x135454 · F_AudioGetEmitterVelocityX(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x135454 ldr r3, [pc, #0x50] */
/* @0x135458 push {r4, lr} */
/* @0x13545c ldr r3, [pc, r3] */
/* @0x135460 sub sp, sp, #16 */
/* @0x135464 mov r4, r0 */
/* @0x135468 ldrb r1, [r3] */
/* @0x13546c cmp r1, #0 */
/* @0x135470 beq 0x13547c <_Z26F_AudioGetEmitterVelocityXR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x135474 add sp, sp, #16 */
/* @0x135478 pop {r4, pc} */
/* @0x13547c str r1, [r0, #0xc] */
/* @0x135480 ldr r0, [sp, #0x18] */
/* @0x135484 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135488 mov r1, r0 */
/* @0x13548c add r0, sp, #4 */
/* @0x135490 bl 0x216f4c <_Z24Audio_GetEmitterVelocityi> */
/* @0x135494 vldr s15, [sp, #4] */
/* @0x135498 vcvt.f64.f32 d6, s15 */
/* @0x13549c vmov r2, r3, d6 */
/* @0x1354a0 stm r4, {r2, r3} */
/* @0x1354a4 add sp, sp, #16 */
/* @0x1354a8 pop {r4, pc} */
/* @0x1354ac .word 0x002b9bf0 */

/* ── FUNC 0x1354b0 · F_AudioGetEmitterVelocityY(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x1354b0 ldr r3, [pc, #0x50] */
/* @0x1354b4 push {r4, lr} */
/* @0x1354b8 ldr r3, [pc, r3] */
/* @0x1354bc sub sp, sp, #16 */
/* @0x1354c0 mov r4, r0 */
/* @0x1354c4 ldrb r1, [r3] */
/* @0x1354c8 cmp r1, #0 */
/* @0x1354cc beq 0x1354d8 <_Z26F_AudioGetEmitterVelocityYR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x1354d0 add sp, sp, #16 */
/* @0x1354d4 pop {r4, pc} */
/* @0x1354d8 str r1, [r0, #0xc] */
/* @0x1354dc ldr r0, [sp, #0x18] */
/* @0x1354e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1354e4 mov r1, r0 */
/* @0x1354e8 add r0, sp, #4 */
/* @0x1354ec bl 0x216f4c <_Z24Audio_GetEmitterVelocityi> */
/* @0x1354f0 vldr s15, [sp, #8] */
/* @0x1354f4 vcvt.f64.f32 d6, s15 */
/* @0x1354f8 vmov r2, r3, d6 */
/* @0x1354fc stm r4, {r2, r3} */
/* @0x135500 add sp, sp, #16 */
/* @0x135504 pop {r4, pc} */
/* @0x135508 mlaeq r11, r4, r11, r9 */

/* ── FUNC 0x13550c · F_AudioGetEmitterVelocityZ(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x13550c ldr r3, [pc, #0x50] */
/* @0x135510 push {r4, lr} */
/* @0x135514 ldr r3, [pc, r3] */
/* @0x135518 sub sp, sp, #16 */
/* @0x13551c mov r4, r0 */
/* @0x135520 ldrb r1, [r3] */
/* @0x135524 cmp r1, #0 */
/* @0x135528 beq 0x135534 <_Z26F_AudioGetEmitterVelocityZR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x13552c add sp, sp, #16 */
/* @0x135530 pop {r4, pc} */
/* @0x135534 str r1, [r0, #0xc] */
/* @0x135538 ldr r0, [sp, #0x18] */
/* @0x13553c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135540 mov r1, r0 */
/* @0x135544 add r0, sp, #4 */
/* @0x135548 bl 0x216f4c <_Z24Audio_GetEmitterVelocityi> */
/* @0x13554c vldr s15, [sp, #12] */
/* @0x135550 vcvt.f64.f32 d6, s15 */
/* @0x135554 vmov r2, r3, d6 */
/* @0x135558 stm r4, {r2, r3} */
/* @0x13555c add sp, sp, #16 */
/* @0x135560 pop {r4, pc} */
/* @0x135564 eoreq r9, r11, r8, lsr r11 */

/* ── FUNC 0x135568 · F_AudioGetListenerData(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x135568 ldr r3, [pc, #0x40] */
/* @0x13556c push {r4, lr} */
/* @0x135570 ldr r3, [pc, r3] */
/* @0x135574 mov r4, r0 */
/* @0x135578 ldrb r1, [r3] */
/* @0x13557c cmp r1, #0 */
/* @0x135580 popne {r4, pc} */
/* @0x135584 str r1, [r0, #0xc] */
/* @0x135588 ldr r0, [sp, #0x8] */
/* @0x13558c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135590 bl 0x2167dc <_Z21Audio_GetListenerDatai> */
/* @0x135594 vmov s15, r0 */
/* @0x135598 vcvt.f64.s32 d7, s15 */
/* @0x13559c vmov r0, r1, d7 */
/* @0x1355a0 vmov r2, s14 */
/* @0x1355a4 mov r3, r1 */
/* @0x1355a8 stm r4, {r2, r3} */
/* @0x1355ac pop {r4, pc} */
/* @0x1355b0 .word 0x002b9adc */

/* ── FUNC 0x1355b4 · F_AudioGetMasterGainN(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1355b4 ldr r3, [pc, #0x40] */
/* @0x1355b8 push {r4, lr} */
/* @0x1355bc ldr r3, [pc, r3] */
/* @0x1355c0 mov r4, r0 */
/* @0x1355c4 ldrb r1, [r3] */
/* @0x1355c8 cmp r1, #0 */
/* @0x1355cc popne {r4, pc} */
/* @0x1355d0 str r1, [r0, #0xc] */
/* @0x1355d4 ldr r0, [sp, #0x8] */
/* @0x1355d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1355dc bl 0x218190 <_Z19Audio_GetMasterGaini> */
/* @0x1355e0 vmov s15, r0 */
/* @0x1355e4 vcvt.f64.f32 d7, s15 */
/* @0x1355e8 vmov r0, r1, d7 */
/* @0x1355ec vmov r2, s14 */
/* @0x1355f0 mov r3, r1 */
/* @0x1355f4 stm r4, {r2, r3} */
/* @0x1355f8 pop {r4, pc} */
/* @0x1355fc mlaeq r11, r0, r10, r9 */

/* ── FUNC 0x135600 · F_AudioGetSoundGain(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x135600 ldr r3, [pc, #0x40] */
/* @0x135604 push {r4, lr} */
/* @0x135608 ldr r3, [pc, r3] */
/* @0x13560c mov r4, r0 */
/* @0x135610 ldrb r1, [r3] */
/* @0x135614 cmp r1, #0 */
/* @0x135618 popne {r4, pc} */
/* @0x13561c str r1, [r0, #0xc] */
/* @0x135620 ldr r0, [sp, #0x8] */
/* @0x135624 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135628 bl 0x21788c <_Z18Audio_GetSoundGaini> */
/* @0x13562c vmov s15, r0 */
/* @0x135630 vcvt.f64.f32 d7, s15 */
/* @0x135634 vmov r0, r1, d7 */
/* @0x135638 vmov r2, s14 */
/* @0x13563c mov r3, r1 */
/* @0x135640 stm r4, {r2, r3} */
/* @0x135644 pop {r4, pc} */
/* @0x135648 eoreq r9, r11, r4, asr #20 */

/* ── FUNC 0x13564c · F_AudioGetSoundPitch(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x13564c ldr r3, [pc, #0x40] */
/* @0x135650 push {r4, lr} */
/* @0x135654 ldr r3, [pc, r3] */
/* @0x135658 mov r4, r0 */
/* @0x13565c ldrb r1, [r3] */
/* @0x135660 cmp r1, #0 */
/* @0x135664 popne {r4, pc} */
/* @0x135668 str r1, [r0, #0xc] */
/* @0x13566c ldr r0, [sp, #0x8] */
/* @0x135670 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135674 bl 0x2173fc <_Z19Audio_GetSoundPitchi> */
/* @0x135678 vmov s15, r0 */
/* @0x13567c vcvt.f64.f32 d7, s15 */
/* @0x135680 vmov r0, r1, d7 */
/* @0x135684 vmov r2, s14 */
/* @0x135688 mov r3, r1 */
/* @0x13568c stm r4, {r2, r3} */
/* @0x135690 pop {r4, pc} */
/* @0x135694 .word 0x002b99f8 */

/* ── FUNC 0x135698 · F_AudioGetName(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x135698 ldr r3, [pc, #0x30] */
/* @0x13569c push {r4, lr} */
/* @0x1356a0 ldr r3, [pc, r3] */
/* @0x1356a4 mov r4, r0 */
/* @0x1356a8 ldr r0, [sp, #0x8] */
/* @0x1356ac ldrb r1, [r3] */
/* @0x1356b0 cmp r1, #0 */
/* @0x1356b4 popne {r4, pc} */
/* @0x1356b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1356bc bl 0x218348 <_Z13Audio_GetNamei> */
/* @0x1356c0 mov r1, r0 */
/* @0x1356c4 mov r0, r4 */
/* @0x1356c8 pop {r4, lr} */
/* @0x1356cc b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1356d0 eoreq r9, r11, r12, lsr #19 */

/* ── FUNC 0x1356d4 · F_AudioSetTrackPos(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x1356d4 push {r3, r4, r5, lr} */
/* @0x1356d8 ldr r3, [pc, #0x38] */
/* @0x1356dc ldr r4, [sp, #0x10] */
/* @0x1356e0 ldr r3, [pc, r3] */
/* @0x1356e4 ldrb r1, [r3] */
/* @0x1356e8 cmp r1, #0 */
/* @0x1356ec popne {r3, r4, r5, pc} */
/* @0x1356f0 mov r0, r4 */
/* @0x1356f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1356f8 mov r1, #1 */
/* @0x1356fc mov r5, r0 */
/* @0x135700 mov r0, r4 */
/* @0x135704 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x135708 mov r1, r0 */
/* @0x13570c mov r0, r5 */
/* @0x135710 pop {r3, r4, r5, lr} */
/* @0x135714 b 0x2187ac <_Z17Audio_SetTrackPosif> */
/* @0x135718 eoreq r9, r11, r12, ror #18 */

/* ── FUNC 0x13571c · F_AudioGetTrackPos(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x13571c ldr r3, [pc, #0x40] */
/* @0x135720 push {r4, lr} */
/* @0x135724 ldr r3, [pc, r3] */
/* @0x135728 mov r4, r0 */
/* @0x13572c ldrb r1, [r3] */
/* @0x135730 cmp r1, #0 */
/* @0x135734 popne {r4, pc} */
/* @0x135738 str r1, [r0, #0xc] */
/* @0x13573c ldr r0, [sp, #0x8] */
/* @0x135740 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135744 bl 0x218908 <_Z17Audio_GetTrackPosi> */
/* @0x135748 vmov s15, r0 */
/* @0x13574c vcvt.f64.f32 d7, s15 */
/* @0x135750 vmov r0, r1, d7 */
/* @0x135754 vmov r2, s14 */
/* @0x135758 mov r3, r1 */
/* @0x13575c stm r4, {r2, r3} */
/* @0x135760 pop {r4, pc} */
/* @0x135764 eoreq r9, r11, r8, lsr #18 */

/* ── FUNC 0x135768 · F_Audio_LoadGroup(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x135768 push {r3, r4, r5, lr} */
/* @0x13576c mov r5, r0 */
/* @0x135770 ldr r3, [pc, #0x4c] */
/* @0x135774 ldr r3, [pc, r3] */
/* @0x135778 ldrb r4, [r3] */
/* @0x13577c cmp r4, #0 */
/* @0x135780 popne {r3, r4, r5, pc} */
/* @0x135784 str r4, [r0, #0xc] */
/* @0x135788 mov r1, r4 */
/* @0x13578c ldr r0, [sp, #0x10] */
/* @0x135790 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135794 ldr r3, [pc, #0x2c] */
/* @0x135798 mov r1, r0 */
/* @0x13579c ldr r0, [pc, r3] */
/* @0x1357a0 bl 0x21e018 <_ZN14CAudioGroupMan9LoadGroupEi> */
/* @0x1357a4 cmp r0, #0 */
/* @0x1357a8 moveq r4, r0 */
/* @0x1357ac movne r3, #0 */
/* @0x1357b0 moveq r3, r4 */
/* @0x1357b4 movtne r3, #0x3ff0 */
/* @0x1357b8 str r4, [r5] */
/* @0x1357bc str r3, [r5, #0x4] */
/* @0x1357c0 pop {r3, r4, r5, pc} */
/* @0x1357c4 .word 0x002b98d8 */
/* @0x1357c8 .word 0x002b98b4 */

/* ── FUNC 0x1357cc · F_Audio_UnloadGroup(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x1357cc push {r3, r4, r5, lr} */
/* @0x1357d0 mov r5, r0 */
/* @0x1357d4 ldr r3, [pc, #0x4c] */
/* @0x1357d8 ldr r3, [pc, r3] */
/* @0x1357dc ldrb r4, [r3] */
/* @0x1357e0 cmp r4, #0 */
/* @0x1357e4 popne {r3, r4, r5, pc} */
/* @0x1357e8 str r4, [r0, #0xc] */
/* @0x1357ec mov r1, r4 */
/* @0x1357f0 ldr r0, [sp, #0x10] */
/* @0x1357f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1357f8 ldr r3, [pc, #0x2c] */
/* @0x1357fc mov r1, r0 */
/* @0x135800 ldr r0, [pc, r3] */
/* @0x135804 bl 0x21e19c <_ZN14CAudioGroupMan11UnloadGroupEi> */
/* @0x135808 cmp r0, #0 */
/* @0x13580c moveq r4, r0 */
/* @0x135810 movne r3, #0 */
/* @0x135814 moveq r3, r4 */
/* @0x135818 movtne r3, #0x3ff0 */
/* @0x13581c str r4, [r5] */
/* @0x135820 str r3, [r5, #0x4] */
/* @0x135824 pop {r3, r4, r5, pc} */
/* @0x135828 eoreq r9, r11, r4, ror r8 */
/* @0x13582c eoreq r9, r11, r0, asr r8 */

/* ── FUNC 0x135830 · F_Audio_GroupIsLoaded(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x135830 push {r3, r4, r5, lr} */
/* @0x135834 mov r5, r0 */
/* @0x135838 ldr r3, [pc, #0x4c] */
/* @0x13583c ldr r3, [pc, r3] */
/* @0x135840 ldrb r4, [r3] */
/* @0x135844 cmp r4, #0 */
/* @0x135848 popne {r3, r4, r5, pc} */
/* @0x13584c str r4, [r0, #0xc] */
/* @0x135850 mov r1, r4 */
/* @0x135854 ldr r0, [sp, #0x10] */
/* @0x135858 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13585c ldr r3, [pc, #0x2c] */
/* @0x135860 mov r1, r0 */
/* @0x135864 ldr r0, [pc, r3] */
/* @0x135868 bl 0x21e1e0 <_ZN14CAudioGroupMan13IsGroupLoadedEi> */
/* @0x13586c cmp r0, #0 */
/* @0x135870 moveq r4, r0 */
/* @0x135874 movne r3, #0 */
/* @0x135878 moveq r3, r4 */
/* @0x13587c movtne r3, #0x3ff0 */
/* @0x135880 str r4, [r5] */
/* @0x135884 str r3, [r5, #0x4] */
/* @0x135888 pop {r3, r4, r5, pc} */
/* @0x13588c eoreq r9, r11, r0, lsl r8 */
/* @0x135890 eoreq r9, r11, r12, ror #15 */

/* ── FUNC 0x135894 · F_Audio_GroupLoadProgress(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x135894 ldr r3, [pc, #0x38] */
/* @0x135898 push {r4, lr} */
/* @0x13589c ldr r3, [pc, r3] */
/* @0x1358a0 mov r4, r0 */
/* @0x1358a4 ldrb r1, [r3] */
/* @0x1358a8 cmp r1, #0 */
/* @0x1358ac popne {r4, pc} */
/* @0x1358b0 str r1, [r0, #0xc] */
/* @0x1358b4 ldr r0, [sp, #0x8] */
/* @0x1358b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1358bc ldr r3, [pc, #0x14] */
/* @0x1358c0 mov r1, r0 */
/* @0x1358c4 ldr r0, [pc, r3] */
/* @0x1358c8 bl 0x21e218 <_ZN14CAudioGroupMan15GetLoadProgressEi> */
/* @0x1358cc stm r4, {r0, r1} */
/* @0x1358d0 pop {r4, pc} */
/* @0x1358d4 .word 0x002b97b0 */
/* @0x1358d8 eoreq r9, r11, r12, lsl #15 */

/* ── FUNC 0x1358dc · F_Audio_GroupName(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1358dc ldr r3, [pc, #0x3c] */
/* @0x1358e0 push {r4, lr} */
/* @0x1358e4 ldr r3, [pc, r3] */
/* @0x1358e8 mov r4, r0 */
/* @0x1358ec ldr r0, [sp, #0x8] */
/* @0x1358f0 ldrb r1, [r3] */
/* @0x1358f4 cmp r1, #0 */
/* @0x1358f8 popne {r4, pc} */
/* @0x1358fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135900 ldr r3, [pc, #0x1c] */
/* @0x135904 mov r1, r0 */
/* @0x135908 ldr r0, [pc, r3] */
/* @0x13590c bl 0x21df34 <_ZN14CAudioGroupMan12GetGroupNameEi> */
/* @0x135910 mov r1, r0 */
/* @0x135914 mov r0, r4 */
/* @0x135918 pop {r4, lr} */
/* @0x13591c b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x135920 eoreq r9, r11, r8, ror #14 */
/* @0x135924 eoreq r9, r11, r8, asr #14 */

/* ── FUNC 0x135928 · F_Audio_GroupStopAll(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x135928 push {r3, lr} */
/* @0x13592c ldr r3, [pc, #0x1c] */
/* @0x135930 ldr r0, [sp, #0x8] */
/* @0x135934 ldr r3, [pc, r3] */
/* @0x135938 ldrb r1, [r3] */
/* @0x13593c cmp r1, #0 */
/* @0x135940 popne {r3, pc} */
/* @0x135944 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135948 pop {r3, lr} */
/* @0x13594c b 0x21ad0c <_Z18Audio_StopAllGroupi> */
/* @0x135950 eoreq r9, r11, r8, lsl r7 */

/* ── FUNC 0x135954 · F_Audio_GroupSetGain(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x135954 ldr r3, [pc, #0x50] */
/* @0x135958 push {r4, r5, r6, lr} */
/* @0x13595c ldr r3, [pc, r3] */
/* @0x135960 ldr r4, [sp, #0x10] */
/* @0x135964 ldrb r1, [r3] */
/* @0x135968 cmp r1, #0 */
/* @0x13596c popne {r4, r5, r6, pc} */
/* @0x135970 mov r0, r4 */
/* @0x135974 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135978 mov r1, #1 */
/* @0x13597c mov r6, r0 */
/* @0x135980 mov r0, r4 */
/* @0x135984 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x135988 mov r1, #2 */
/* @0x13598c mov r5, r0 */
/* @0x135990 mov r0, r4 */
/* @0x135994 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135998 mov r1, r5 */
/* @0x13599c mov r2, r0 */
/* @0x1359a0 mov r0, r6 */
/* @0x1359a4 pop {r4, r5, r6, lr} */
/* @0x1359a8 b 0x218b84 <_Z18Audio_SetGainGroupifi> */
/* @0x1359ac .word 0x002b96f0 */

/* ── FUNC 0x1359b0 · F_Audio_CreateBufferSound(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0x1359b0 ldr r3, [pc, #0xb8] */
/* @0x1359b4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1359b8 ldr r3, [pc, r3] */
/* @0x1359bc sub sp, sp, #12 */
/* @0x1359c0 mov r6, r0 */
/* @0x1359c4 ldrb r5, [r3] */
/* @0x1359c8 ldr r4, [sp, #0x30] */
/* @0x1359cc cmp r5, #0 */
/* @0x1359d0 bne 0x135a68 <_Z25F_Audio_CreateBufferSoundR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x1359d4 mov r1, r5 */
/* @0x1359d8 mov r0, r4 */
/* @0x1359dc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1359e0 mov r1, #1 */
/* @0x1359e4 mov r7, r0 */
/* @0x1359e8 mov r0, r4 */
/* @0x1359ec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1359f0 mov r1, #2 */
/* @0x1359f4 mov r10, r0 */
/* @0x1359f8 mov r0, r4 */
/* @0x1359fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135a00 mov r1, #3 */
/* @0x135a04 mov r9, r0 */
/* @0x135a08 mov r0, r4 */
/* @0x135a0c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135a10 mov r1, #4 */
/* @0x135a14 mov r8, r0 */
/* @0x135a18 mov r0, r4 */
/* @0x135a1c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135a20 mov r1, #5 */
/* @0x135a24 mov r11, r0 */
/* @0x135a28 mov r0, r4 */
/* @0x135a2c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135a30 str r11, [sp] */
/* @0x135a34 mov r1, r10 */
/* @0x135a38 mov r2, r9 */
/* @0x135a3c mov r3, r8 */
/* @0x135a40 str r5, [r6, #0xc] */
/* @0x135a44 str r0, [sp, #0x4] */
/* @0x135a48 mov r0, r7 */
/* @0x135a4c bl 0x2198a0 <_Z23Audio_CreateBufferSoundiiiiii> */
/* @0x135a50 vmov s15, r0 */
/* @0x135a54 vcvt.f64.s32 d7, s15 */
/* @0x135a58 vmov r0, r1, d7 */
/* @0x135a5c vmov r2, s14 */
/* @0x135a60 mov r3, r1 */
/* @0x135a64 stm r6, {r2, r3} */
/* @0x135a68 add sp, sp, #12 */
/* @0x135a6c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x135a70 mlaeq r11, r4, r6, r9 */

/* ── FUNC 0x135a74 · F_Audio_FreeBufferSound(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x135a74 ldr r3, [pc, #0x40] */
/* @0x135a78 push {r4, lr} */
/* @0x135a7c ldr r3, [pc, r3] */
/* @0x135a80 mov r4, r0 */
/* @0x135a84 ldrb r1, [r3] */
/* @0x135a88 cmp r1, #0 */
/* @0x135a8c popne {r4, pc} */
/* @0x135a90 str r1, [r0, #0xc] */
/* @0x135a94 ldr r0, [sp, #0x8] */
/* @0x135a98 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135a9c bl 0x219d70 <_Z21Audio_FreeBufferSoundi> */
/* @0x135aa0 vmov s15, r0 */
/* @0x135aa4 vcvt.f64.s32 d7, s15 */
/* @0x135aa8 vmov r0, r1, d7 */
/* @0x135aac vmov r2, s14 */
/* @0x135ab0 mov r3, r1 */
/* @0x135ab4 stm r4, {r2, r3} */
/* @0x135ab8 pop {r4, pc} */
/* @0x135abc .word 0x002b95d0 */

/* ── FUNC 0x135ac0 · F_Audio_StartRecording(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x135ac0 ldr r3, [pc, #0x40] */
/* @0x135ac4 push {r4, lr} */
/* @0x135ac8 ldr r3, [pc, r3] */
/* @0x135acc mov r4, r0 */
/* @0x135ad0 ldrb r1, [r3] */
/* @0x135ad4 cmp r1, #0 */
/* @0x135ad8 popne {r4, pc} */
/* @0x135adc str r1, [r0, #0xc] */
/* @0x135ae0 ldr r0, [sp, #0x8] */
/* @0x135ae4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135ae8 bl 0x21c700 <_Z20Audio_StartRecordingi> */
/* @0x135aec vmov s15, r0 */
/* @0x135af0 vcvt.f64.s32 d7, s15 */
/* @0x135af4 vmov r0, r1, d7 */
/* @0x135af8 vmov r2, s14 */
/* @0x135afc mov r3, r1 */
/* @0x135b00 stm r4, {r2, r3} */
/* @0x135b04 pop {r4, pc} */
/* @0x135b08 eoreq r9, r11, r4, lsl #11 */

/* ── FUNC 0x135b0c · F_Audio_GetRecorderCount(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x135b0c ldr r3, [pc, #0x38] */
/* @0x135b10 push {r4, lr} */
/* @0x135b14 ldr r3, [pc, r3] */
/* @0x135b18 mov r4, r0 */
/* @0x135b1c ldrb r3, [r3] */
/* @0x135b20 cmp r3, #0 */
/* @0x135b24 popne {r4, pc} */
/* @0x135b28 str r3, [r0, #0xc] */
/* @0x135b2c bl 0x21c5b8 <_Z22Audio_GetRecorderCountv> */
/* @0x135b30 vmov s15, r0 */
/* @0x135b34 vcvt.f64.s32 d7, s15 */
/* @0x135b38 vmov r0, r1, d7 */
/* @0x135b3c vmov r2, s14 */
/* @0x135b40 mov r3, r1 */
/* @0x135b44 stm r4, {r2, r3} */
/* @0x135b48 pop {r4, pc} */
/* @0x135b4c eoreq r9, r11, r8, lsr r5 */

/* ── FUNC 0x135b50 · F_Audio_GetRecorderInfo(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x135b50 ldr r3, [pc, #0x40] */
/* @0x135b54 push {r4, lr} */
/* @0x135b58 ldr r3, [pc, r3] */
/* @0x135b5c mov r4, r0 */
/* @0x135b60 ldrb r1, [r3] */
/* @0x135b64 cmp r1, #0 */
/* @0x135b68 popne {r4, pc} */
/* @0x135b6c str r1, [r0, #0xc] */
/* @0x135b70 ldr r0, [sp, #0x8] */
/* @0x135b74 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135b78 bl 0x21c5bc <_Z21Audio_GetRecorderInfoi> */
/* @0x135b7c vmov s15, r0 */
/* @0x135b80 vcvt.f64.s32 d7, s15 */
/* @0x135b84 vmov r0, r1, d7 */
/* @0x135b88 vmov r2, s14 */
/* @0x135b8c mov r3, r1 */
/* @0x135b90 stm r4, {r2, r3} */
/* @0x135b94 pop {r4, pc} */
/* @0x135b98 .word 0x002b94f4 */

/* ── FUNC 0x135b9c · F_Audio_CreatePlayQueue(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x135b9c push {r3, r4, r5, r6, r7, lr} */
/* @0x135ba0 mov r5, r0 */
/* @0x135ba4 ldr r3, [pc, #0x68] */
/* @0x135ba8 ldr r4, [sp, #0x18] */
/* @0x135bac ldr r3, [pc, r3] */
/* @0x135bb0 ldrb r1, [r3] */
/* @0x135bb4 cmp r1, #0 */
/* @0x135bb8 popne {r3, r4, r5, r6, r7, pc} */
/* @0x135bbc str r1, [r0, #0xc] */
/* @0x135bc0 mov r0, r4 */
/* @0x135bc4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135bc8 mov r1, #1 */
/* @0x135bcc mov r7, r0 */
/* @0x135bd0 mov r0, r4 */
/* @0x135bd4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135bd8 mov r1, #2 */
/* @0x135bdc mov r6, r0 */
/* @0x135be0 mov r0, r4 */
/* @0x135be4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135be8 mov r1, r6 */
/* @0x135bec mov r2, r0 */
/* @0x135bf0 mov r0, r7 */
/* @0x135bf4 bl 0x21cb8c <_Z21Audio_CreatePlayQueueiii> */
/* @0x135bf8 vmov s15, r0 */
/* @0x135bfc vcvt.f64.s32 d7, s15 */
/* @0x135c00 vmov r0, r1, d7 */
/* @0x135c04 vmov r2, s14 */
/* @0x135c08 mov r3, r1 */
/* @0x135c0c stm r5, {r2, r3} */
/* @0x135c10 pop {r3, r4, r5, r6, r7, pc} */
/* @0x135c14 eoreq r9, r11, r0, lsr #9 */

/* ── FUNC 0x135c18 · F_Audio_FreePlayQueue(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x135c18 ldr r3, [pc, #0x40] */
/* @0x135c1c push {r4, lr} */
/* @0x135c20 ldr r3, [pc, r3] */
/* @0x135c24 mov r4, r0 */
/* @0x135c28 ldrb r1, [r3] */
/* @0x135c2c cmp r1, #0 */
/* @0x135c30 popne {r4, pc} */
/* @0x135c34 str r1, [r0, #0xc] */
/* @0x135c38 ldr r0, [sp, #0x8] */
/* @0x135c3c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135c40 bl 0x21ce90 <_Z19Audio_FreePlayQueuei> */
/* @0x135c44 vmov s15, r0 */
/* @0x135c48 vcvt.f64.s32 d7, s15 */
/* @0x135c4c vmov r0, r1, d7 */
/* @0x135c50 vmov r2, s14 */
/* @0x135c54 mov r3, r1 */
/* @0x135c58 stm r4, {r2, r3} */
/* @0x135c5c pop {r4, pc} */
/* @0x135c60 eoreq r9, r11, r12, lsr #8 */

/* ── FUNC 0x135c64 · F_Audio_QueueSound(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x135c64 ldr r3, [pc, #0x84] */
/* @0x135c68 push {r4, r5, r6, r7, r8, lr} */
/* @0x135c6c ldr r3, [pc, r3] */
/* @0x135c70 mov r5, r0 */
/* @0x135c74 ldr r4, [sp, #0x18] */
/* @0x135c78 ldrb r1, [r3] */
/* @0x135c7c cmp r1, #0 */
/* @0x135c80 popne {r4, r5, r6, r7, r8, pc} */
/* @0x135c84 str r1, [r0, #0xc] */
/* @0x135c88 mov r0, r4 */
/* @0x135c8c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135c90 mov r1, #1 */
/* @0x135c94 mov r8, r0 */
/* @0x135c98 mov r0, r4 */
/* @0x135c9c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135ca0 mov r1, #2 */
/* @0x135ca4 mov r7, r0 */
/* @0x135ca8 mov r0, r4 */
/* @0x135cac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135cb0 mov r1, #3 */
/* @0x135cb4 mov r6, r0 */
/* @0x135cb8 mov r0, r4 */
/* @0x135cbc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135cc0 mov r1, r7 */
/* @0x135cc4 mov r2, r6 */
/* @0x135cc8 mov r3, r0 */
/* @0x135ccc mov r0, r8 */
/* @0x135cd0 bl 0x21d0e0 <_Z22Audio_QueueBufferSoundiiii> */
/* @0x135cd4 vmov s15, r0 */
/* @0x135cd8 vcvt.f64.s32 d7, s15 */
/* @0x135cdc vmov r0, r1, d7 */
/* @0x135ce0 vmov r2, s14 */
/* @0x135ce4 mov r3, r1 */
/* @0x135ce8 stm r5, {r2, r3} */
/* @0x135cec pop {r4, r5, r6, r7, r8, pc} */
/* @0x135cf0 eoreq r9, r11, r0, ror #7 */
