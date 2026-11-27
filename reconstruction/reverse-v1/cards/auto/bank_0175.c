/* libyoyo.so 覆盖卡组 0175
 * 函数 0x1fa048..0x1fa658，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1fa048 · GV_MouseY(CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x1fa048 mov r3, #0 */
/* @0x1fa04c push {r4, r5, r6, lr} */
/* @0x1fa050 mov r0, r3 */
/* @0x1fa054 str r3, [r2, #0xc] */
/* @0x1fa058 mov r6, r2 */
/* @0x1fa05c bl 0x17adb0 <_Z27GR_Window_Views_Mouse_Get_Yi> */
/* @0x1fa060 vmov s15, r0 */
/* @0x1fa064 mov r0, #1 */
/* @0x1fa068 vcvt.f64.s32 d7, s15 */
/* @0x1fa06c vmov r4, r5, d7 */
/* @0x1fa070 vmov r2, s14 */
/* @0x1fa074 mov r3, r5 */
/* @0x1fa078 stm r6, {r2, r3} */
/* @0x1fa07c pop {r4, r5, r6, pc} */

/* ── FUNC 0x1fa080 · GV_MouseButton(CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x1fa080 mov r3, #0 */
/* @0x1fa084 push {r4, r5, r6, lr} */
/* @0x1fa088 mov r0, r3 */
/* @0x1fa08c str r3, [r2, #0xc] */
/* @0x1fa090 mov r6, r2 */
/* @0x1fa094 bl 0x18c048 <_Z21IO_Button_Current_Geti> */
/* @0x1fa098 vmov s15, r0 */
/* @0x1fa09c mov r0, #1 */
/* @0x1fa0a0 vcvt.f64.s32 d7, s15 */
/* @0x1fa0a4 vmov r4, r5, d7 */
/* @0x1fa0a8 vmov r2, s14 */
/* @0x1fa0ac mov r3, r5 */
/* @0x1fa0b0 stm r6, {r2, r3} */
/* @0x1fa0b4 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1fa0b8 · GV_MouseLastButton(CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x1fa0b8 mov r3, #0 */
/* @0x1fa0bc push {r4, r5, r6, lr} */
/* @0x1fa0c0 mov r0, r3 */
/* @0x1fa0c4 str r3, [r2, #0xc] */
/* @0x1fa0c8 mov r6, r2 */
/* @0x1fa0cc bl 0x18c024 <_Z18IO_Button_Last_Geti> */
/* @0x1fa0d0 vmov s15, r0 */
/* @0x1fa0d4 mov r0, #1 */
/* @0x1fa0d8 vcvt.f64.s32 d7, s15 */
/* @0x1fa0dc vmov r4, r5, d7 */
/* @0x1fa0e0 vmov r2, s14 */
/* @0x1fa0e4 mov r3, r5 */
/* @0x1fa0e8 stm r6, {r2, r3} */
/* @0x1fa0ec pop {r4, r5, r6, pc} */

/* ── FUNC 0x1fa0f0 · GV_KeyboardKey(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1fa0f0 push {r4, r5, r6, lr} */
/* @0x1fa0f4 mov r3, #0 */
/* @0x1fa0f8 str r3, [r2, #0xc] */
/* @0x1fa0fc mov r6, r2 */
/* @0x1fa100 bl 0x18bea8 <_Z18IO_Key_Current_Getv> */
/* @0x1fa104 vmov s15, r0 */
/* @0x1fa108 mov r0, #1 */
/* @0x1fa10c vcvt.f64.s32 d7, s15 */
/* @0x1fa110 vmov r4, r5, d7 */
/* @0x1fa114 vmov r2, s14 */
/* @0x1fa118 mov r3, r5 */
/* @0x1fa11c stm r6, {r2, r3} */
/* @0x1fa120 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1fa124 · GV_KeyboardLastKey(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1fa124 push {r4, r5, r6, lr} */
/* @0x1fa128 mov r3, #0 */
/* @0x1fa12c str r3, [r2, #0xc] */
/* @0x1fa130 mov r6, r2 */
/* @0x1fa134 bl 0x18be94 <_Z15IO_Key_Last_Getv> */
/* @0x1fa138 vmov s15, r0 */
/* @0x1fa13c mov r0, #1 */
/* @0x1fa140 vcvt.f64.s32 d7, s15 */
/* @0x1fa144 vmov r4, r5, d7 */
/* @0x1fa148 vmov r2, s14 */
/* @0x1fa14c mov r3, r5 */
/* @0x1fa150 stm r6, {r2, r3} */
/* @0x1fa154 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1fa158 · GV_KeyboardLastChar(CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1fa158 push {r4, r5, r6, lr} */
/* @0x1fa15c sub sp, sp, #16 */
/* @0x1fa160 add r4, sp, #16 */
/* @0x1fa164 mov r6, r2 */
/* @0x1fa168 add r5, sp, #8 */
/* @0x1fa16c str r5, [r4, #-0xc]! */
/* @0x1fa170 bl 0x18bd0c <_Z16IO_Char_Last_Getv> */
/* @0x1fa174 mov r1, r0 */
/* @0x1fa178 mov r0, r4 */
/* @0x1fa17c bl 0x10fe28 <utf8_add_char> */
/* @0x1fa180 mov r0, r4 */
/* @0x1fa184 mov r1, #0 */
/* @0x1fa188 bl 0x10fe28 <utf8_add_char> */
/* @0x1fa18c mov r0, r6 */
/* @0x1fa190 mov r1, r5 */
/* @0x1fa194 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1fa198 mov r0, #1 */
/* @0x1fa19c add sp, sp, #16 */
/* @0x1fa1a0 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1fa1a4 · GV_KeyboardString(CInstance*, int, RValue*) · size=32 · insn=8 */
/* @0x1fa1a4 push {r4, lr} */
/* @0x1fa1a8 mov r4, r2 */
/* @0x1fa1ac bl 0x18bd34 <_Z13IO_String_Getv> */
/* @0x1fa1b0 mov r1, r0 */
/* @0x1fa1b4 mov r0, r4 */
/* @0x1fa1b8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1fa1bc mov r0, #1 */
/* @0x1fa1c0 pop {r4, pc} */

/* ── FUNC 0x1fa1c4 · GV_CaptionScore(CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x1fa1c4 push {r3, lr} */
/* @0x1fa1c8 mov r0, r2 */
/* @0x1fa1cc ldr r3, [pc, #0x10] */
/* @0x1fa1d0 ldr r3, [pc, r3] */
/* @0x1fa1d4 ldr r1, [r3] */
/* @0x1fa1d8 bl 0xe7dac <_Z14YYCreateStringP6RValueP9_RefThingIPKcE> */
/* @0x1fa1dc mov r0, #1 */
/* @0x1fa1e0 pop {r3, pc} */
/* @0x1fa1e4 andseq r5, pc, r0, lsr #8 */

/* ── FUNC 0x1fa1e8 · GV_CaptionLives(CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x1fa1e8 push {r3, lr} */
/* @0x1fa1ec mov r0, r2 */
/* @0x1fa1f0 ldr r3, [pc, #0x10] */
/* @0x1fa1f4 ldr r3, [pc, r3] */
/* @0x1fa1f8 ldr r1, [r3] */
/* @0x1fa1fc bl 0xe7dac <_Z14YYCreateStringP6RValueP9_RefThingIPKcE> */
/* @0x1fa200 mov r0, #1 */
/* @0x1fa204 pop {r3, pc} */
/* @0x1fa208 andseq r5, pc, r4, lsl #8 */

/* ── FUNC 0x1fa20c · GV_CaptionHealth(CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x1fa20c push {r3, lr} */
/* @0x1fa210 mov r0, r2 */
/* @0x1fa214 ldr r3, [pc, #0x10] */
/* @0x1fa218 ldr r3, [pc, r3] */
/* @0x1fa21c ldr r1, [r3] */
/* @0x1fa220 bl 0xe7dac <_Z14YYCreateStringP6RValueP9_RefThingIPKcE> */
/* @0x1fa224 mov r0, #1 */
/* @0x1fa228 pop {r3, pc} */
/* @0x1fa22c andseq r5, pc, r8, ror #7 */

/* ── FUNC 0x1fa230 · GV_ErrorLast(CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x1fa230 push {r3, lr} */
/* @0x1fa234 mov r0, r2 */
/* @0x1fa238 ldr r3, [pc, #0x10] */
/* @0x1fa23c ldr r3, [pc, r3] */
/* @0x1fa240 ldr r1, [r3] */
/* @0x1fa244 bl 0xe7dac <_Z14YYCreateStringP6RValueP9_RefThingIPKcE> */
/* @0x1fa248 mov r0, #1 */
/* @0x1fa24c pop {r3, pc} */
/* @0x1fa250 andseq r3, pc, r0, ror #22 */

/* ── FUNC 0x1fa254 · SV_FontTexturePageSize(CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x1fa254 push {r3, lr} */
/* @0x1fa258 mov r0, r2 */
/* @0x1fa25c mov r1, #0 */
/* @0x1fa260 bl 0xcea30 <_Z10YYGetInt64PK6RValuei> */
/* @0x1fa264 ldr r3, [pc, #0xc] */
/* @0x1fa268 ldr r3, [pc, r3] */
/* @0x1fa26c str r0, [r3] */
/* @0x1fa270 mov r0, #1 */
/* @0x1fa274 pop {r3, pc} */
/* @0x1fa278 andseq r3, pc, r12, ror #23 */

/* ── FUNC 0x1fa27c · GV_CurrentTime(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1fa27c push {r4, lr} */
/* @0x1fa280 mov r4, r2 */
/* @0x1fa284 bl 0x215148 <Timing_Time> */
/* @0x1fa288 mov r12, #0 */
/* @0x1fa28c mov r2, #1000 */
/* @0x1fa290 mov r3, #0 */
/* @0x1fa294 str r12, [r4, #0xc] */
/* @0x1fa298 bl 0x319414 <__aeabi_ldivmod> */
/* @0x1fa29c bl 0x319164 <__floatdidf> */
/* @0x1fa2a0 str r0, [r4] */
/* @0x1fa2a4 mov r0, #1 */
/* @0x1fa2a8 str r1, [r4, #0x4] */
/* @0x1fa2ac pop {r4, pc} */

/* ── FUNC 0x1fa2b0 · GV_CurrentYear(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1fa2b0 push {r4, r5, r6, lr} */
/* @0x1fa2b4 mov r3, #0 */
/* @0x1fa2b8 str r3, [r2, #0xc] */
/* @0x1fa2bc mov r6, r2 */
/* @0x1fa2c0 bl 0x117a10 <_Z15CurrentTimeToTMv> */
/* @0x1fa2c4 ldr r4, [r0, #0x14] */
/* @0x1fa2c8 mov r0, #1 */
/* @0x1fa2cc add r4, r4, #1888 */
/* @0x1fa2d0 add r4, r4, #12 */
/* @0x1fa2d4 vmov s15, r4 */
/* @0x1fa2d8 vcvt.f64.s32 d7, s15 */
/* @0x1fa2dc vmov r4, r5, d7 */
/* @0x1fa2e0 vmov r2, s14 */
/* @0x1fa2e4 mov r3, r5 */
/* @0x1fa2e8 stm r6, {r2, r3} */
/* @0x1fa2ec pop {r4, r5, r6, pc} */

/* ── FUNC 0x1fa2f0 · GV_CurrentMonth(CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1fa2f0 push {r4, r5, r6, lr} */
/* @0x1fa2f4 mov r3, #0 */
/* @0x1fa2f8 str r3, [r2, #0xc] */
/* @0x1fa2fc mov r6, r2 */
/* @0x1fa300 bl 0x117a10 <_Z15CurrentTimeToTMv> */
/* @0x1fa304 ldr r4, [r0, #0x10] */
/* @0x1fa308 mov r0, #1 */
/* @0x1fa30c add r4, r4, r0 */
/* @0x1fa310 vmov s15, r4 */
/* @0x1fa314 vcvt.f64.s32 d7, s15 */
/* @0x1fa318 vmov r4, r5, d7 */
/* @0x1fa31c vmov r2, s14 */
/* @0x1fa320 mov r3, r5 */
/* @0x1fa324 stm r6, {r2, r3} */
/* @0x1fa328 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1fa32c · GV_CurrentDay(CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x1fa32c push {r4, r5, r6, lr} */
/* @0x1fa330 mov r3, #0 */
/* @0x1fa334 str r3, [r2, #0xc] */
/* @0x1fa338 mov r6, r2 */
/* @0x1fa33c bl 0x117a10 <_Z15CurrentTimeToTMv> */
/* @0x1fa340 ldr r4, [r0, #0xc] */
/* @0x1fa344 mov r0, #1 */
/* @0x1fa348 vmov s15, r4 */
/* @0x1fa34c vcvt.f64.s32 d7, s15 */
/* @0x1fa350 vmov r4, r5, d7 */
/* @0x1fa354 vmov r2, s14 */
/* @0x1fa358 mov r3, r5 */
/* @0x1fa35c stm r6, {r2, r3} */
/* @0x1fa360 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1fa364 · GV_CurrentWeekday(CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x1fa364 push {r4, r5, r6, lr} */
/* @0x1fa368 mov r3, #0 */
/* @0x1fa36c str r3, [r2, #0xc] */
/* @0x1fa370 mov r6, r2 */
/* @0x1fa374 bl 0x117a10 <_Z15CurrentTimeToTMv> */
/* @0x1fa378 ldr r4, [r0, #0x18] */
/* @0x1fa37c mov r0, #1 */
/* @0x1fa380 vmov s15, r4 */
/* @0x1fa384 vcvt.f64.s32 d7, s15 */
/* @0x1fa388 vmov r4, r5, d7 */
/* @0x1fa38c vmov r2, s14 */
/* @0x1fa390 mov r3, r5 */
/* @0x1fa394 stm r6, {r2, r3} */
/* @0x1fa398 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1fa39c · GV_CurrentHour(CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x1fa39c push {r4, r5, r6, lr} */
/* @0x1fa3a0 mov r3, #0 */
/* @0x1fa3a4 str r3, [r2, #0xc] */
/* @0x1fa3a8 mov r6, r2 */
/* @0x1fa3ac bl 0x117a10 <_Z15CurrentTimeToTMv> */
/* @0x1fa3b0 ldr r4, [r0, #0x8] */
/* @0x1fa3b4 mov r0, #1 */
/* @0x1fa3b8 vmov s15, r4 */
/* @0x1fa3bc vcvt.f64.s32 d7, s15 */
/* @0x1fa3c0 vmov r4, r5, d7 */
/* @0x1fa3c4 vmov r2, s14 */
/* @0x1fa3c8 mov r3, r5 */
/* @0x1fa3cc stm r6, {r2, r3} */
/* @0x1fa3d0 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1fa3d4 · GV_CurrentMinute(CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x1fa3d4 push {r4, r5, r6, lr} */
/* @0x1fa3d8 mov r3, #0 */
/* @0x1fa3dc str r3, [r2, #0xc] */
/* @0x1fa3e0 mov r6, r2 */
/* @0x1fa3e4 bl 0x117a10 <_Z15CurrentTimeToTMv> */
/* @0x1fa3e8 ldr r4, [r0, #0x4] */
/* @0x1fa3ec mov r0, #1 */
/* @0x1fa3f0 vmov s15, r4 */
/* @0x1fa3f4 vcvt.f64.s32 d7, s15 */
/* @0x1fa3f8 vmov r4, r5, d7 */
/* @0x1fa3fc vmov r2, s14 */
/* @0x1fa400 mov r3, r5 */
/* @0x1fa404 stm r6, {r2, r3} */
/* @0x1fa408 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1fa40c · GV_CurrentSecond(CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x1fa40c push {r4, r5, r6, lr} */
/* @0x1fa410 mov r3, #0 */
/* @0x1fa414 str r3, [r2, #0xc] */
/* @0x1fa418 mov r6, r2 */
/* @0x1fa41c bl 0x117a10 <_Z15CurrentTimeToTMv> */
/* @0x1fa420 ldr r4, [r0] */
/* @0x1fa424 mov r0, #1 */
/* @0x1fa428 vmov s15, r4 */
/* @0x1fa42c vcvt.f64.s32 d7, s15 */
/* @0x1fa430 vmov r4, r5, d7 */
/* @0x1fa434 vmov r2, s14 */
/* @0x1fa438 mov r3, r5 */
/* @0x1fa43c stm r6, {r2, r3} */
/* @0x1fa440 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1fa444 · SV_Argument(CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x1fa444 push {r3, lr} */
/* @0x1fa448 cmp r1, #15 */
/* @0x1fa44c ldr r3, [pc, #0x24] */
/* @0x1fa450 lslls r0, r1, #4 */
/* @0x1fa454 movhi r0, #0 */
/* @0x1fa458 mov r1, r2 */
/* @0x1fa45c ldr r3, [pc, r3] */
/* @0x1fa460 mov r2, #-2147483648 */
/* @0x1fa464 ldr r3, [r3] */
/* @0x1fa468 add r0, r3, r0 */
/* @0x1fa46c bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1fa470 mov r0, #1 */
/* @0x1fa474 pop {r3, pc} */
/* @0x1fa478 ldrheq r3, [pc], -r4 */

/* ── FUNC 0x1fa47c · SV_Argument0(CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x1fa47c push {r3, lr} */
/* @0x1fa480 mov r0, r1 */
/* @0x1fa484 ldr r3, [pc, #0x18] */
/* @0x1fa488 mov r1, r2 */
/* @0x1fa48c mov r2, r0 */
/* @0x1fa490 ldr r3, [pc, r3] */
/* @0x1fa494 ldr r0, [r3] */
/* @0x1fa498 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1fa49c mov r0, #1 */
/* @0x1fa4a0 pop {r3, pc} */
/* @0x1fa4a4 andseq r3, pc, r0, lsl #17 */

/* ── FUNC 0x1fa4a8 · SV_Argument1(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1fa4a8 push {r3, lr} */
/* @0x1fa4ac mov r0, r1 */
/* @0x1fa4b0 ldr r3, [pc, #0x1c] */
/* @0x1fa4b4 mov r1, r2 */
/* @0x1fa4b8 mov r2, r0 */
/* @0x1fa4bc ldr r3, [pc, r3] */
/* @0x1fa4c0 ldr r0, [r3] */
/* @0x1fa4c4 add r0, r0, #16 */
/* @0x1fa4c8 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1fa4cc mov r0, #1 */
/* @0x1fa4d0 pop {r3, pc} */
/* @0x1fa4d4 andseq r3, pc, r4, asr r8 */

/* ── FUNC 0x1fa4d8 · SV_Argument2(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1fa4d8 push {r3, lr} */
/* @0x1fa4dc mov r0, r1 */
/* @0x1fa4e0 ldr r3, [pc, #0x1c] */
/* @0x1fa4e4 mov r1, r2 */
/* @0x1fa4e8 mov r2, r0 */
/* @0x1fa4ec ldr r3, [pc, r3] */
/* @0x1fa4f0 ldr r0, [r3] */
/* @0x1fa4f4 add r0, r0, #32 */
/* @0x1fa4f8 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1fa4fc mov r0, #1 */
/* @0x1fa500 pop {r3, pc} */
/* @0x1fa504 andseq r3, pc, r4, lsr #16 */

/* ── FUNC 0x1fa508 · SV_Argument3(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1fa508 push {r3, lr} */
/* @0x1fa50c mov r0, r1 */
/* @0x1fa510 ldr r3, [pc, #0x1c] */
/* @0x1fa514 mov r1, r2 */
/* @0x1fa518 mov r2, r0 */
/* @0x1fa51c ldr r3, [pc, r3] */
/* @0x1fa520 ldr r0, [r3] */
/* @0x1fa524 add r0, r0, #48 */
/* @0x1fa528 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1fa52c mov r0, #1 */
/* @0x1fa530 pop {r3, pc} */
/* @0x1fa534 ldrsheq r3, [pc], -r4 */

/* ── FUNC 0x1fa538 · SV_Argument4(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1fa538 push {r3, lr} */
/* @0x1fa53c mov r0, r1 */
/* @0x1fa540 ldr r3, [pc, #0x1c] */
/* @0x1fa544 mov r1, r2 */
/* @0x1fa548 mov r2, r0 */
/* @0x1fa54c ldr r3, [pc, r3] */
/* @0x1fa550 ldr r0, [r3] */
/* @0x1fa554 add r0, r0, #64 */
/* @0x1fa558 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1fa55c mov r0, #1 */
/* @0x1fa560 pop {r3, pc} */
/* @0x1fa564 andseq r3, pc, r4, asr #15 */

/* ── FUNC 0x1fa568 · SV_Argument5(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1fa568 push {r3, lr} */
/* @0x1fa56c mov r0, r1 */
/* @0x1fa570 ldr r3, [pc, #0x1c] */
/* @0x1fa574 mov r1, r2 */
/* @0x1fa578 mov r2, r0 */
/* @0x1fa57c ldr r3, [pc, r3] */
/* @0x1fa580 ldr r0, [r3] */
/* @0x1fa584 add r0, r0, #80 */
/* @0x1fa588 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1fa58c mov r0, #1 */
/* @0x1fa590 pop {r3, pc} */
/* @0x1fa594 mulseq pc, r4, r7 */

/* ── FUNC 0x1fa598 · SV_Argument6(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1fa598 push {r3, lr} */
/* @0x1fa59c mov r0, r1 */
/* @0x1fa5a0 ldr r3, [pc, #0x1c] */
/* @0x1fa5a4 mov r1, r2 */
/* @0x1fa5a8 mov r2, r0 */
/* @0x1fa5ac ldr r3, [pc, r3] */
/* @0x1fa5b0 ldr r0, [r3] */
/* @0x1fa5b4 add r0, r0, #96 */
/* @0x1fa5b8 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1fa5bc mov r0, #1 */
/* @0x1fa5c0 pop {r3, pc} */
/* @0x1fa5c4 andseq r3, pc, r4, ror #14 */

/* ── FUNC 0x1fa5c8 · SV_Argument7(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1fa5c8 push {r3, lr} */
/* @0x1fa5cc mov r0, r1 */
/* @0x1fa5d0 ldr r3, [pc, #0x1c] */
/* @0x1fa5d4 mov r1, r2 */
/* @0x1fa5d8 mov r2, r0 */
/* @0x1fa5dc ldr r3, [pc, r3] */
/* @0x1fa5e0 ldr r0, [r3] */
/* @0x1fa5e4 add r0, r0, #112 */
/* @0x1fa5e8 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1fa5ec mov r0, #1 */
/* @0x1fa5f0 pop {r3, pc} */
/* @0x1fa5f4 andseq r3, pc, r4, lsr r7 */

/* ── FUNC 0x1fa5f8 · SV_Argument8(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1fa5f8 push {r3, lr} */
/* @0x1fa5fc mov r0, r1 */
/* @0x1fa600 ldr r3, [pc, #0x1c] */
/* @0x1fa604 mov r1, r2 */
/* @0x1fa608 mov r2, r0 */
/* @0x1fa60c ldr r3, [pc, r3] */
/* @0x1fa610 ldr r0, [r3] */
/* @0x1fa614 add r0, r0, #128 */
/* @0x1fa618 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1fa61c mov r0, #1 */
/* @0x1fa620 pop {r3, pc} */
/* @0x1fa624 andseq r3, pc, r4, lsl #14 */

/* ── FUNC 0x1fa628 · SV_Argument9(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1fa628 push {r3, lr} */
/* @0x1fa62c mov r0, r1 */
/* @0x1fa630 ldr r3, [pc, #0x1c] */
/* @0x1fa634 mov r1, r2 */
/* @0x1fa638 mov r2, r0 */
/* @0x1fa63c ldr r3, [pc, r3] */
/* @0x1fa640 ldr r0, [r3] */
/* @0x1fa644 add r0, r0, #144 */
/* @0x1fa648 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1fa64c mov r0, #1 */
/* @0x1fa650 pop {r3, pc} */
/* @0x1fa654 ldrsbeq r3, [pc], -r4 */

/* ── FUNC 0x1fa658 · SV_Argument10(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1fa658 push {r3, lr} */
/* @0x1fa65c mov r0, r1 */
/* @0x1fa660 ldr r3, [pc, #0x1c] */
/* @0x1fa664 mov r1, r2 */
/* @0x1fa668 mov r2, r0 */
/* @0x1fa66c ldr r3, [pc, r3] */
/* @0x1fa670 ldr r0, [r3] */
/* @0x1fa674 add r0, r0, #160 */
/* @0x1fa678 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1fa67c mov r0, #1 */
/* @0x1fa680 pop {r3, pc} */
/* @0x1fa684 andseq r3, pc, r4, lsr #13 */
