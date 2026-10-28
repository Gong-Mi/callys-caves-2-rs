/* libyoyo.so 覆盖卡组 0044
 * 函数 0x117eec..0x119b24，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x117eec · date_is_valid(int, int, int) · size=172 · insn=43 */
/* @0x117eec push {r4, r5, r6, r7, lr} */
/* @0x117ef0 cmp r2, #0 */
/* @0x117ef4 ldr r4, [pc, #0x98] */
/* @0x117ef8 mov r7, r0 */
/* @0x117efc mov r6, r1 */
/* @0x117f00 mov r5, r2 */
/* @0x117f04 add r4, pc, r4 */
/* @0x117f08 sub sp, sp, #60 */
/* @0x117f0c add r12, sp, #4 */
/* @0x117f10 ldm r4!, {r0, r1, r2, r3} */
/* @0x117f14 stm r12!, {r0, r1, r2, r3} */
/* @0x117f18 ldm r4!, {r0, r1, r2, r3} */
/* @0x117f1c stm r12!, {r0, r1, r2, r3} */
/* @0x117f20 ldm r4!, {r0, r1, r2, r3} */
/* @0x117f24 ldr r4, [r4] */
/* @0x117f28 stm r12!, {r0, r1, r2, r3} */
/* @0x117f2c str r4, [r12] */
/* @0x117f30 blt 0x117f88 <_Z13date_is_validiii+0x9c> */
/* @0x117f34 mov r0, r5 */
/* @0x117f38 bl 0x117a5c <_Z12is_leap_yeari> */
/* @0x117f3c cmp r0, #0 */
/* @0x117f40 movne r3, #29 */
/* @0x117f44 strne r3, [sp, #0xc] */
/* @0x117f48 sub r3, r6, #1 */
/* @0x117f4c cmp r3, #11 */
/* @0x117f50 bhi 0x117f88 <_Z13date_is_validiii+0x9c> */
/* @0x117f54 cmp r7, #0 */
/* @0x117f58 ble 0x117f88 <_Z13date_is_validiii+0x9c> */
/* @0x117f5c add r3, sp, #56 */
/* @0x117f60 add r6, r3, r6, lsl #2 */
/* @0x117f64 ldr r3, [r6, #-0x34] */
/* @0x117f68 cmp r7, r3 */
/* @0x117f6c bgt 0x117f88 <_Z13date_is_validiii+0x9c> */
/* @0x117f70 movw r0, #0x7b1 */
/* @0x117f74 cmp r5, r0 */
/* @0x117f78 movle r0, #0 */
/* @0x117f7c movgt r0, #1 */
/* @0x117f80 add sp, sp, #60 */
/* @0x117f84 pop {r4, r5, r6, r7, pc} */
/* @0x117f88 mov r0, #0 */
/* @0x117f8c add sp, sp, #60 */
/* @0x117f90 pop {r4, r5, r6, r7, pc} */
/* @0x117f94 eoreq r4, r4, r12, lsr r10 */

/* ── FUNC 0x117f98 · F_DateValidDateTime(RValue&, CInstance*, CInstance*, int, RValue*) · size=188 · insn=47 */
/* @0x117f98 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x117f9c mov r5, #0 */
/* @0x117fa0 ldr r4, [sp, #0x28] */
/* @0x117fa4 mov r1, r5 */
/* @0x117fa8 str r5, [r0, #0xc] */
/* @0x117fac mov r6, r0 */
/* @0x117fb0 str r5, [r0] */
/* @0x117fb4 str r5, [r0, #0x4] */
/* @0x117fb8 mov r0, r4 */
/* @0x117fbc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x117fc0 mov r1, #1 */
/* @0x117fc4 mov r7, r0 */
/* @0x117fc8 mov r0, r4 */
/* @0x117fcc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x117fd0 mov r1, #2 */
/* @0x117fd4 mov r8, r0 */
/* @0x117fd8 mov r0, r4 */
/* @0x117fdc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x117fe0 mov r1, #3 */
/* @0x117fe4 mov r9, r0 */
/* @0x117fe8 mov r0, r4 */
/* @0x117fec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x117ff0 mov r1, #4 */
/* @0x117ff4 mov r10, r0 */
/* @0x117ff8 mov r0, r4 */
/* @0x117ffc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x118000 mov r1, #5 */
/* @0x118004 mov r11, r0 */
/* @0x118008 mov r0, r4 */
/* @0x11800c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x118010 mov r1, r8 */
/* @0x118014 mov r2, r7 */
/* @0x118018 mov r4, r0 */
/* @0x11801c mov r0, r9 */
/* @0x118020 bl 0x117eec <_Z13date_is_validiii> */
/* @0x118024 cmp r0, r5 */
/* @0x118028 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11802c cmp r10, #23 */
/* @0x118030 pophi {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x118034 cmp r11, #59 */
/* @0x118038 pophi {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11803c cmp r4, #59 */
/* @0x118040 strls r5, [r6] */
/* @0x118044 movls r3, r5 */
/* @0x118048 movtls r3, #0x3ff0 */
/* @0x11804c strls r3, [r6, #0x4] */
/* @0x118050 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x118054 · F_DateValidDate(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x118054 push {r4, r5, r6, r7, r8, lr} */
/* @0x118058 mov r4, #0 */
/* @0x11805c ldr r6, [sp, #0x18] */
/* @0x118060 mov r5, r0 */
/* @0x118064 str r4, [r0, #0xc] */
/* @0x118068 mov r1, r4 */
/* @0x11806c str r4, [r0] */
/* @0x118070 str r4, [r0, #0x4] */
/* @0x118074 mov r0, r6 */
/* @0x118078 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11807c mov r1, #1 */
/* @0x118080 mov r7, r0 */
/* @0x118084 mov r0, r6 */
/* @0x118088 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11808c mov r1, #2 */
/* @0x118090 mov r8, r0 */
/* @0x118094 mov r0, r6 */
/* @0x118098 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11809c mov r1, r8 */
/* @0x1180a0 mov r2, r7 */
/* @0x1180a4 bl 0x117eec <_Z13date_is_validiii> */
/* @0x1180a8 cmp r0, r4 */
/* @0x1180ac strne r4, [r5] */
/* @0x1180b0 movne r3, r4 */
/* @0x1180b4 movtne r3, #0x3ff0 */
/* @0x1180b8 strne r3, [r5, #0x4] */
/* @0x1180bc pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x1180c0 · GetSecondOfYear(int, int, int, int, int, int) · size=208 · insn=52 */
/* @0x1180c0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1180c4 mov r8, r0 */
/* @0x1180c8 ldr r4, [pc, #0xbc] */
/* @0x1180cc mov r10, r1 */
/* @0x1180d0 mov r7, r2 */
/* @0x1180d4 mov r6, r3 */
/* @0x1180d8 add r4, pc, r4 */
/* @0x1180dc sub sp, sp, #56 */
/* @0x1180e0 add r9, sp, #4 */
/* @0x1180e4 cmp r8, #0 */
/* @0x1180e8 ldm r4!, {r0, r1, r2, r3} */
/* @0x1180ec mov r12, r9 */
/* @0x1180f0 ldr r5, [sp, #0x58] */
/* @0x1180f4 stm r12!, {r0, r1, r2, r3} */
/* @0x1180f8 ldm r4!, {r0, r1, r2, r3} */
/* @0x1180fc stm r12!, {r0, r1, r2, r3} */
/* @0x118100 ldm r4!, {r0, r1, r2, r3} */
/* @0x118104 ldr r4, [r4] */
/* @0x118108 stm r12!, {r0, r1, r2, r3} */
/* @0x11810c movlt r0, #0 */
/* @0x118110 str r4, [r12] */
/* @0x118114 blt 0x11817c <_Z15GetSecondOfYeariiiiii+0xbc> */
/* @0x118118 mov r0, r8 */
/* @0x11811c bl 0x117a5c <_Z12is_leap_yeari> */
/* @0x118120 cmp r0, #0 */
/* @0x118124 movne r3, #29 */
/* @0x118128 strne r3, [sp, #0xc] */
/* @0x11812c cmp r10, #1 */
/* @0x118130 ble 0x118184 <_Z15GetSecondOfYeariiiiii+0xc4> */
/* @0x118134 add r1, sp, r10, lsl #2 */
/* @0x118138 mov r0, r9 */
/* @0x11813c mov r12, #0 */
/* @0x118140 ldr r4, [r0, #0x4]! */
/* @0x118144 cmp r0, r1 */
/* @0x118148 add r12, r12, r4 */
/* @0x11814c bne 0x118140 <_Z15GetSecondOfYeariiiiii+0x80> */
/* @0x118150 add r12, r12, r7 */
/* @0x118154 movw r3, #0x5180 */
/* @0x118158 sub r0, r12, #1 */
/* @0x11815c movt r3, #0x1 */
/* @0x118160 mov r2, #3600 */
/* @0x118164 rsb r5, r5, r5, lsl #4 */
/* @0x118168 mul r6, r2, r6 */
/* @0x11816c mla r3, r3, r0, r6 */
/* @0x118170 add r0, r3, r5, lsl #2 */
/* @0x118174 ldr r3, [sp, #0x5c] */
/* @0x118178 add r0, r0, r3 */
/* @0x11817c add sp, sp, #56 */
/* @0x118180 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x118184 mov r12, #0 */
/* @0x118188 b 0x118150 <_Z15GetSecondOfYeariiiiii+0x90> */
/* @0x11818c eoreq r4, r4, r8, ror #16 */

/* ── FUNC 0x118190 · F_DateGetWeek(RValue&, CInstance*, CInstance*, int, RValue*) · size=308 · insn=77 */
/* @0x118190 push {r4, lr} */
/* @0x118194 sub sp, sp, #16 */
/* @0x118198 mov r1, #0 */
/* @0x11819c mov r4, r0 */
/* @0x1181a0 mov r3, r1 */
/* @0x1181a4 str r1, [r0, #0xc] */
/* @0x1181a8 movt r3, #0xbff0 */
/* @0x1181ac stm r0, {r1, r3} */
/* @0x1181b0 ldr r0, [sp, #0x18] */
/* @0x1181b4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1181b8 vldr d7, [pc, #232] */
/* @0x1181bc vldr d5, [pc, #236] */
/* @0x1181c0 vmov d6, r0, r1 */
/* @0x1181c4 vsub.f64 d7, d6, d7 */
/* @0x1181c8 vabs.f64 d4, d7 */
/* @0x1181cc vcmpe.f64 d4, d5 */
/* @0x1181d0 vmrs APSR_nzcv, fpscr */
/* @0x1181d4 vldrls d7, [pc, #220] */
/* @0x1181d8 vldrhi d6, [pc, #216] */
/* @0x1181dc vmul.f64 d5, d7, d6 */
/* @0x1181e0 vmov r0, r1, d5 */
/* @0x1181e4 bl 0x3194a0 <__fixdfdi> */
/* @0x1181e8 mov r3, r1 */
/* @0x1181ec ldr r1, [pc, #0xcc] */
/* @0x1181f0 mov r2, r0 */
/* @0x1181f4 strd r2, r3, [sp, #8] */
/* @0x1181f8 add r1, pc, r1 */
/* @0x1181fc add r0, sp, #8 */
/* @0x118200 ldrb r3, [r1] */
/* @0x118204 cmp r3, #0 */
/* @0x118208 bne 0x11829c <_Z13F_DateGetWeekR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x11820c bl 0xb6820 <gmtime64@plt> */
/* @0x118210 mov r12, r0 */
/* @0x118214 cmp r12, #0 */
/* @0x118218 beq 0x118294 <_Z13F_DateGetWeekR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x11821c ldr lr, [r12, #0x4] */
/* @0x118220 ldr r0, [r12, #0x14] */
/* @0x118224 ldr r1, [r12, #0x10] */
/* @0x118228 ldr r2, [r12, #0xc] */
/* @0x11822c add r0, r0, #1888 */
/* @0x118230 ldr r3, [r12, #0x8] */
/* @0x118234 add r1, r1, #1 */
/* @0x118238 str lr, [sp] */
/* @0x11823c add r2, r2, #1 */
/* @0x118240 ldr r12, [r12] */
/* @0x118244 add r0, r0, #12 */
/* @0x118248 str r12, [sp, #0x4] */
/* @0x11824c bl 0x1180c0 <_Z15GetSecondOfYeariiiiii> */
/* @0x118250 movw r3, #0x4507 */
/* @0x118254 movt r3, #0xc22e */
/* @0x118258 vmov.f64 d7, #7.000000e+00 */
/* @0x11825c smull r1, r3, r3, r0 */
/* @0x118260 asr r2, r0, #31 */
/* @0x118264 add r0, r3, r0 */
/* @0x118268 rsb r0, r2, r0, asr #16 */
/* @0x11826c vmov s10, r0 */
/* @0x118270 vcvt.f64.s32 d6, s10 */
/* @0x118274 vdiv.f64 d5, d6, d7 */
/* @0x118278 vmov r0, r1, d5 */
/* @0x11827c bl 0xb6598 <floor@plt> */
/* @0x118280 vmov d6, r0, r1 */
/* @0x118284 vcvt.s32.f64 s15, d6 */
/* @0x118288 vcvt.f64.s32 d5, s15 */
/* @0x11828c vmov r2, r3, d5 */
/* @0x118290 stm r4, {r2, r3} */
/* @0x118294 add sp, sp, #16 */
/* @0x118298 pop {r4, pc} */
/* @0x11829c bl 0xb682c <localtime64@plt> */
/* @0x1182a0 mov r12, r0 */
/* @0x1182a4 b 0x118214 <_Z13F_DateGetWeekR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x1182a8 andeq r0, r0, r0 */
/* @0x1182ac sbcsmi pc, r8, r0, asr #16 */
/* @0x1182b0 bl 0x828f6c <b2_toiTime+0xcfac8> */
/* @0x1182b4 svclo #0x1a36e2 */
/* @0x1182b8 andeq r0, r0, r0 */
/* @0x1182bc rscsmi r1, r5, r0, lsl #16 */
/* @0x1182c0 eoreq r9, sp, r0, asr #30 */

/* ── FUNC 0x1182c4 · anon_1182c4 · size=4 · insn=1 */
/* @0x1182c4 nop */

/* ── FUNC 0x1182c8 · F_DateGetDayOfYear(RValue&, CInstance*, CInstance*, int, RValue*) · size=284 · insn=71 */
/* @0x1182c8 push {r4, lr} */
/* @0x1182cc sub sp, sp, #16 */
/* @0x1182d0 mov r3, #0 */
/* @0x1182d4 mov r4, r0 */
/* @0x1182d8 str r3, [r0, #0xc] */
/* @0x1182dc mov r1, r3 */
/* @0x1182e0 str r3, [r0] */
/* @0x1182e4 str r3, [r0, #0x4] */
/* @0x1182e8 ldr r0, [sp, #0x18] */
/* @0x1182ec bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1182f0 vldr d7, [pc, #208] */
/* @0x1182f4 vldr d5, [pc, #212] */
/* @0x1182f8 vmov d6, r0, r1 */
/* @0x1182fc vsub.f64 d7, d6, d7 */
/* @0x118300 vabs.f64 d4, d7 */
/* @0x118304 vcmpe.f64 d4, d5 */
/* @0x118308 vmrs APSR_nzcv, fpscr */
/* @0x11830c vldrls d7, [pc, #196] */
/* @0x118310 vldrhi d6, [pc, #192] */
/* @0x118314 vmul.f64 d5, d7, d6 */
/* @0x118318 vmov r0, r1, d5 */
/* @0x11831c bl 0x3194a0 <__fixdfdi> */
/* @0x118320 mov r3, r1 */
/* @0x118324 ldr r1, [pc, #0xb4] */
/* @0x118328 mov r2, r0 */
/* @0x11832c strd r2, r3, [sp, #8] */
/* @0x118330 add r1, pc, r1 */
/* @0x118334 add r0, sp, #8 */
/* @0x118338 ldrb r3, [r1] */
/* @0x11833c cmp r3, #0 */
/* @0x118340 bne 0x1183b8 <_Z18F_DateGetDayOfYearR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x118344 bl 0xb6820 <gmtime64@plt> */
/* @0x118348 mov r12, r0 */
/* @0x11834c cmp r12, #0 */
/* @0x118350 beq 0x1183b0 <_Z18F_DateGetDayOfYearR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x118354 ldr lr, [r12, #0x4] */
/* @0x118358 ldr r0, [r12, #0x14] */
/* @0x11835c ldr r1, [r12, #0x10] */
/* @0x118360 ldr r2, [r12, #0xc] */
/* @0x118364 add r0, r0, #1888 */
/* @0x118368 ldr r3, [r12, #0x8] */
/* @0x11836c add r1, r1, #1 */
/* @0x118370 str lr, [sp] */
/* @0x118374 add r2, r2, #1 */
/* @0x118378 ldr r12, [r12] */
/* @0x11837c add r0, r0, #12 */
/* @0x118380 str r12, [sp, #0x4] */
/* @0x118384 bl 0x1180c0 <_Z15GetSecondOfYeariiiiii> */
/* @0x118388 movw r3, #0x4507 */
/* @0x11838c movt r3, #0xc22e */
/* @0x118390 smull r2, r3, r3, r0 */
/* @0x118394 asr r1, r0, #31 */
/* @0x118398 add r0, r3, r0 */
/* @0x11839c rsb r0, r1, r0, asr #16 */
/* @0x1183a0 vmov s11, r0 */
/* @0x1183a4 vcvt.f64.s32 d5, s11 */
/* @0x1183a8 vmov r2, r3, d5 */
/* @0x1183ac stm r4, {r2, r3} */
/* @0x1183b0 add sp, sp, #16 */
/* @0x1183b4 pop {r4, pc} */
/* @0x1183b8 bl 0xb682c <localtime64@plt> */
/* @0x1183bc mov r12, r0 */
/* @0x1183c0 b 0x11834c <_Z18F_DateGetDayOfYearR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x1183c4 nop */
/* @0x1183c8 andeq r0, r0, r0 */
/* @0x1183cc sbcsmi pc, r8, r0, asr #16 */
/* @0x1183d0 bl 0x82908c <b2_toiTime+0xcfbe8> */
/* @0x1183d4 svclo #0x1a36e2 */
/* @0x1183d8 andeq r0, r0, r0 */
/* @0x1183dc rscsmi r1, r5, r0, lsl #16 */
/* @0x1183e0 eoreq r9, sp, r8, lsl #28 */

/* ── FUNC 0x1183e4 · anon_1183e4 · size=4 · insn=1 */
/* @0x1183e4 nop */

/* ── FUNC 0x1183e8 · F_DateGetHourOfYear(RValue&, CInstance*, CInstance*, int, RValue*) · size=276 · insn=69 */
/* @0x1183e8 push {r4, lr} */
/* @0x1183ec sub sp, sp, #16 */
/* @0x1183f0 mov r3, #0 */
/* @0x1183f4 mov r4, r0 */
/* @0x1183f8 str r3, [r0, #0xc] */
/* @0x1183fc mov r1, r3 */
/* @0x118400 str r3, [r0] */
/* @0x118404 str r3, [r0, #0x4] */
/* @0x118408 ldr r0, [sp, #0x18] */
/* @0x11840c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x118410 vldr d7, [pc, #200] */
/* @0x118414 vldr d5, [pc, #204] */
/* @0x118418 vmov d6, r0, r1 */
/* @0x11841c vsub.f64 d7, d6, d7 */
/* @0x118420 vabs.f64 d4, d7 */
/* @0x118424 vcmpe.f64 d4, d5 */
/* @0x118428 vmrs APSR_nzcv, fpscr */
/* @0x11842c vldrls d7, [pc, #188] */
/* @0x118430 vldrhi d6, [pc, #184] */
/* @0x118434 vmul.f64 d5, d7, d6 */
/* @0x118438 vmov r0, r1, d5 */
/* @0x11843c bl 0x3194a0 <__fixdfdi> */
/* @0x118440 mov r3, r1 */
/* @0x118444 ldr r1, [pc, #0xac] */
/* @0x118448 mov r2, r0 */
/* @0x11844c strd r2, r3, [sp, #8] */
/* @0x118450 add r1, pc, r1 */
/* @0x118454 add r0, sp, #8 */
/* @0x118458 ldrb r3, [r1] */
/* @0x11845c cmp r3, #0 */
/* @0x118460 bne 0x1184d4 <_Z19F_DateGetHourOfYearR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x118464 bl 0xb6820 <gmtime64@plt> */
/* @0x118468 mov r12, r0 */
/* @0x11846c cmp r12, #0 */
/* @0x118470 beq 0x1184cc <_Z19F_DateGetHourOfYearR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x118474 ldr lr, [r12, #0x4] */
/* @0x118478 ldr r2, [r12, #0xc] */
/* @0x11847c ldr r0, [r12, #0x14] */
/* @0x118480 ldr r1, [r12, #0x10] */
/* @0x118484 ldr r3, [r12, #0x8] */
/* @0x118488 add r0, r0, #1888 */
/* @0x11848c str lr, [sp] */
/* @0x118490 add r1, r1, #1 */
/* @0x118494 ldr r12, [r12] */
/* @0x118498 add r0, r0, #12 */
/* @0x11849c str r12, [sp, #0x4] */
/* @0x1184a0 bl 0x1180c0 <_Z15GetSecondOfYeariiiiii> */
/* @0x1184a4 movw r3, #0xb3c5 */
/* @0x1184a8 movt r3, #0x91a2 */
/* @0x1184ac smull r2, r3, r3, r0 */
/* @0x1184b0 asr r1, r0, #31 */
/* @0x1184b4 add r0, r3, r0 */
/* @0x1184b8 rsb r0, r1, r0, asr #11 */
/* @0x1184bc vmov s11, r0 */
/* @0x1184c0 vcvt.f64.s32 d5, s11 */
/* @0x1184c4 vmov r2, r3, d5 */
/* @0x1184c8 stm r4, {r2, r3} */
/* @0x1184cc add sp, sp, #16 */
/* @0x1184d0 pop {r4, pc} */
/* @0x1184d4 bl 0xb682c <localtime64@plt> */
/* @0x1184d8 mov r12, r0 */
/* @0x1184dc b 0x11846c <_Z19F_DateGetHourOfYearR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x1184e0 andeq r0, r0, r0 */
/* @0x1184e4 sbcsmi pc, r8, r0, asr #16 */
/* @0x1184e8 bl 0x8291a4 <b2_toiTime+0xcfd00> */
/* @0x1184ec svclo #0x1a36e2 */
/* @0x1184f0 andeq r0, r0, r0 */
/* @0x1184f4 rscsmi r1, r5, r0, lsl #16 */
/* @0x1184f8 eoreq r9, sp, r8, ror #25 */

/* ── FUNC 0x1184fc · anon_1184fc · size=4 · insn=1 */
/* @0x1184fc nop */

/* ── FUNC 0x118500 · F_DateGetMinuteOfYear(RValue&, CInstance*, CInstance*, int, RValue*) · size=276 · insn=69 */
/* @0x118500 push {r4, lr} */
/* @0x118504 sub sp, sp, #16 */
/* @0x118508 mov r3, #0 */
/* @0x11850c mov r4, r0 */
/* @0x118510 str r3, [r0, #0xc] */
/* @0x118514 mov r1, r3 */
/* @0x118518 str r3, [r0] */
/* @0x11851c str r3, [r0, #0x4] */
/* @0x118520 ldr r0, [sp, #0x18] */
/* @0x118524 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x118528 vldr d7, [pc, #200] */
/* @0x11852c vldr d5, [pc, #204] */
/* @0x118530 vmov d6, r0, r1 */
/* @0x118534 vsub.f64 d7, d6, d7 */
/* @0x118538 vabs.f64 d4, d7 */
/* @0x11853c vcmpe.f64 d4, d5 */
/* @0x118540 vmrs APSR_nzcv, fpscr */
/* @0x118544 vldrls d7, [pc, #188] */
/* @0x118548 vldrhi d6, [pc, #184] */
/* @0x11854c vmul.f64 d5, d7, d6 */
/* @0x118550 vmov r0, r1, d5 */
/* @0x118554 bl 0x3194a0 <__fixdfdi> */
/* @0x118558 mov r3, r1 */
/* @0x11855c ldr r1, [pc, #0xac] */
/* @0x118560 mov r2, r0 */
/* @0x118564 strd r2, r3, [sp, #8] */
/* @0x118568 add r1, pc, r1 */
/* @0x11856c add r0, sp, #8 */
/* @0x118570 ldrb r3, [r1] */
/* @0x118574 cmp r3, #0 */
/* @0x118578 bne 0x1185ec <_Z21F_DateGetMinuteOfYearR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x11857c bl 0xb6820 <gmtime64@plt> */
/* @0x118580 mov r12, r0 */
/* @0x118584 cmp r12, #0 */
/* @0x118588 beq 0x1185e4 <_Z21F_DateGetMinuteOfYearR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x11858c ldr lr, [r12, #0x4] */
/* @0x118590 ldr r2, [r12, #0xc] */
/* @0x118594 ldr r0, [r12, #0x14] */
/* @0x118598 ldr r1, [r12, #0x10] */
/* @0x11859c ldr r3, [r12, #0x8] */
/* @0x1185a0 add r0, r0, #1888 */
/* @0x1185a4 str lr, [sp] */
/* @0x1185a8 add r1, r1, #1 */
/* @0x1185ac ldr r12, [r12] */
/* @0x1185b0 add r0, r0, #12 */
/* @0x1185b4 str r12, [sp, #0x4] */
/* @0x1185b8 bl 0x1180c0 <_Z15GetSecondOfYeariiiiii> */
/* @0x1185bc movw r3, #0x8889 */
/* @0x1185c0 movt r3, #0x8888 */
/* @0x1185c4 smull r2, r3, r3, r0 */
/* @0x1185c8 asr r1, r0, #31 */
/* @0x1185cc add r0, r3, r0 */
/* @0x1185d0 rsb r0, r1, r0, asr #5 */
/* @0x1185d4 vmov s11, r0 */
/* @0x1185d8 vcvt.f64.s32 d5, s11 */
/* @0x1185dc vmov r2, r3, d5 */
/* @0x1185e0 stm r4, {r2, r3} */
/* @0x1185e4 add sp, sp, #16 */
/* @0x1185e8 pop {r4, pc} */
/* @0x1185ec bl 0xb682c <localtime64@plt> */
/* @0x1185f0 mov r12, r0 */
/* @0x1185f4 b 0x118584 <_Z21F_DateGetMinuteOfYearR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x1185f8 andeq r0, r0, r0 */
/* @0x1185fc sbcsmi pc, r8, r0, asr #16 */
/* @0x118600 bl 0x8292bc <b2_toiTime+0xcfe18> */
/* @0x118604 svclo #0x1a36e2 */
/* @0x118608 andeq r0, r0, r0 */
/* @0x11860c rscsmi r1, r5, r0, lsl #16 */
/* @0x118610 .word 0x002d9bd0 */

/* ── FUNC 0x118614 · anon_118614 · size=4 · insn=1 */
/* @0x118614 nop */

/* ── FUNC 0x118618 · F_DateGetSecondOfYear(RValue&, CInstance*, CInstance*, int, RValue*) · size=260 · insn=65 */
/* @0x118618 push {r4, lr} */
/* @0x11861c sub sp, sp, #16 */
/* @0x118620 mov r3, #0 */
/* @0x118624 mov r4, r0 */
/* @0x118628 str r3, [r0, #0xc] */
/* @0x11862c mov r1, r3 */
/* @0x118630 str r3, [r0] */
/* @0x118634 str r3, [r0, #0x4] */
/* @0x118638 ldr r0, [sp, #0x18] */
/* @0x11863c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x118640 vldr d7, [pc, #184] */
/* @0x118644 vldr d5, [pc, #188] */
/* @0x118648 vmov d6, r0, r1 */
/* @0x11864c vsub.f64 d7, d6, d7 */
/* @0x118650 vabs.f64 d4, d7 */
/* @0x118654 vcmpe.f64 d4, d5 */
/* @0x118658 vmrs APSR_nzcv, fpscr */
/* @0x11865c vldrls d7, [pc, #172] */
/* @0x118660 vldrhi d6, [pc, #168] */
/* @0x118664 vmul.f64 d5, d7, d6 */
/* @0x118668 vmov r0, r1, d5 */
/* @0x11866c bl 0x3194a0 <__fixdfdi> */
/* @0x118670 mov r3, r1 */
/* @0x118674 ldr r1, [pc, #0x9c] */
/* @0x118678 mov r2, r0 */
/* @0x11867c strd r2, r3, [sp, #8] */
/* @0x118680 add r1, pc, r1 */
/* @0x118684 add r0, sp, #8 */
/* @0x118688 ldrb r3, [r1] */
/* @0x11868c cmp r3, #0 */
/* @0x118690 bne 0x1186f4 <_Z21F_DateGetSecondOfYearR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x118694 bl 0xb6820 <gmtime64@plt> */
/* @0x118698 mov r12, r0 */
/* @0x11869c cmp r12, #0 */
/* @0x1186a0 beq 0x1186ec <_Z21F_DateGetSecondOfYearR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x1186a4 ldr lr, [r12, #0x4] */
/* @0x1186a8 ldr r0, [r12, #0x14] */
/* @0x1186ac ldr r1, [r12, #0x10] */
/* @0x1186b0 ldr r2, [r12, #0xc] */
/* @0x1186b4 add r0, r0, #1888 */
/* @0x1186b8 ldr r3, [r12, #0x8] */
/* @0x1186bc add r1, r1, #1 */
/* @0x1186c0 str lr, [sp] */
/* @0x1186c4 add r0, r0, #12 */
/* @0x1186c8 ldr r12, [r12] */
/* @0x1186cc str r12, [sp, #0x4] */
/* @0x1186d0 bl 0x1180c0 <_Z15GetSecondOfYeariiiiii> */
/* @0x1186d4 vmov s15, r0 */
/* @0x1186d8 vcvt.f64.s32 d7, s15 */
/* @0x1186dc vmov r0, r1, d7 */
/* @0x1186e0 vmov r2, s14 */
/* @0x1186e4 mov r3, r1 */
/* @0x1186e8 stm r4, {r2, r3} */
/* @0x1186ec add sp, sp, #16 */
/* @0x1186f0 pop {r4, pc} */
/* @0x1186f4 bl 0xb682c <localtime64@plt> */
/* @0x1186f8 mov r12, r0 */
/* @0x1186fc b 0x11869c <_Z21F_DateGetSecondOfYearR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x118700 andeq r0, r0, r0 */
/* @0x118704 sbcsmi pc, r8, r0, asr #16 */
/* @0x118708 bl 0x8293c4 <b2_toiTime+0xcff20> */
/* @0x11870c svclo #0x1a36e2 */
/* @0x118710 andeq r0, r0, r0 */
/* @0x118714 rscsmi r1, r5, r0, lsl #16 */
/* @0x118718 .word 0x002d9ab8 */

/* ── FUNC 0x11871c · anon_11871c · size=4 · insn=1 */
/* @0x11871c nop */

/* ── FUNC 0x118720 · InitMiscFunctions() · size=3500 · insn=875 */
/* @0x118720 push {r4, lr} */
/* @0x118724 mov r2, #0 */
/* @0x118728 ldr r4, [pc, #0xa94] */
/* @0x11872c mov r3, r2 */
/* @0x118730 ldr r1, [pc, #0xa90] */
/* @0x118734 add r4, pc, r4 */
/* @0x118738 ldr r0, [pc, #0xa8c] */
/* @0x11873c add r0, pc, r0 */
/* @0x118740 ldr r1, [r4, r1] */
/* @0x118744 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118748 ldr r1, [pc, #0xa80] */
/* @0x11874c ldr r0, [pc, #0xa80] */
/* @0x118750 mov r2, #2 */
/* @0x118754 mov r3, #0 */
/* @0x118758 add r0, pc, r0 */
/* @0x11875c ldr r1, [r4, r1] */
/* @0x118760 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118764 ldr r1, [pc, #0xa6c] */
/* @0x118768 ldr r0, [pc, #0xa6c] */
/* @0x11876c mov r2, #1 */
/* @0x118770 mov r3, #0 */
/* @0x118774 add r0, pc, r0 */
/* @0x118778 ldr r1, [r4, r1] */
/* @0x11877c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118780 ldr r1, [pc, #0xa58] */
/* @0x118784 ldr r0, [pc, #0xa58] */
/* @0x118788 mov r3, #0 */
/* @0x11878c mov r2, #3 */
/* @0x118790 add r0, pc, r0 */
/* @0x118794 ldr r1, [r4, r1] */
/* @0x118798 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x11879c ldr r3, [pc, #0xa44] */
/* @0x1187a0 ldr r3, [r4, r3] */
/* @0x1187a4 ldrb r3, [r3] */
/* @0x1187a8 cmp r3, #0 */
/* @0x1187ac bne 0x1189fc <_Z17InitMiscFunctionsv+0x2dc> */
/* @0x1187b0 ldr r1, [pc, #0xa34] */
/* @0x1187b4 mvn r2, #0 */
/* @0x1187b8 ldr r0, [pc, #0xa30] */
/* @0x1187bc mov r3, #1 */
/* @0x1187c0 add r0, pc, r0 */
/* @0x1187c4 ldr r1, [r4, r1] */
/* @0x1187c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1187cc ldr r1, [pc, #0xa20] */
/* @0x1187d0 ldr r0, [pc, #0xa20] */
/* @0x1187d4 mvn r2, #0 */
/* @0x1187d8 mov r3, #1 */
/* @0x1187dc add r0, pc, r0 */
/* @0x1187e0 ldr r1, [r4, r1] */
/* @0x1187e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1187e8 ldr r1, [pc, #0xa0c] */
/* @0x1187ec ldr r0, [pc, #0xa0c] */
/* @0x1187f0 mov r2, #1 */
/* @0x1187f4 mov r3, r2 */
/* @0x1187f8 add r0, pc, r0 */
/* @0x1187fc ldr r1, [r4, r1] */
/* @0x118800 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118804 ldr r1, [pc, #0x9f8] */
/* @0x118808 ldr r0, [pc, #0x9f8] */
/* @0x11880c mov r2, #3 */
/* @0x118810 mov r3, #1 */
/* @0x118814 add r0, pc, r0 */
/* @0x118818 ldr r1, [r4, r1] */
/* @0x11881c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118820 ldr r1, [pc, #0x9e4] */
/* @0x118824 ldr r0, [pc, #0x9e4] */
/* @0x118828 mov r2, #1 */
/* @0x11882c mov r3, r2 */
/* @0x118830 add r0, pc, r0 */
/* @0x118834 ldr r1, [r4, r1] */
/* @0x118838 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x11883c ldr r1, [pc, #0x9d0] */
/* @0x118840 ldr r0, [pc, #0x9d0] */
/* @0x118844 mov r2, #4 */
/* @0x118848 mov r3, #1 */
/* @0x11884c add r0, pc, r0 */
/* @0x118850 ldr r1, [r4, r1] */
/* @0x118854 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118858 ldr r1, [pc, #0x9bc] */
/* @0x11885c ldr r0, [pc, #0x9bc] */
/* @0x118860 mov r2, #2 */
/* @0x118864 mov r3, #1 */
/* @0x118868 add r0, pc, r0 */
/* @0x11886c ldr r1, [r4, r1] */
/* @0x118870 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118874 ldr r1, [pc, #0x9a8] */
/* @0x118878 ldr r0, [pc, #0x9a8] */
/* @0x11887c mov r2, #5 */
/* @0x118880 mov r3, #1 */
/* @0x118884 add r0, pc, r0 */
/* @0x118888 ldr r1, [r4, r1] */
/* @0x11888c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118890 ldr r1, [pc, #0x994] */
/* @0x118894 ldr r0, [pc, #0x994] */
/* @0x118898 mov r2, #3 */
/* @0x11889c mov r3, #1 */
/* @0x1188a0 add r0, pc, r0 */
/* @0x1188a4 ldr r1, [r4, r1] */
/* @0x1188a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1188ac ldr r1, [pc, #0x980] */
/* @0x1188b0 ldr r0, [pc, #0x980] */
/* @0x1188b4 mov r2, #6 */
/* @0x1188b8 mov r3, #1 */
/* @0x1188bc add r0, pc, r0 */
/* @0x1188c0 ldr r1, [r4, r1] */
/* @0x1188c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1188c8 ldr r1, [pc, #0x96c] */
/* @0x1188cc ldr r0, [pc, #0x96c] */
/* @0x1188d0 mov r2, #4 */
/* @0x1188d4 mov r3, #1 */
/* @0x1188d8 add r0, pc, r0 */
/* @0x1188dc ldr r1, [r4, r1] */
/* @0x1188e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1188e4 ldr r1, [pc, #0x958] */
/* @0x1188e8 ldr r0, [pc, #0x958] */
/* @0x1188ec mov r2, #7 */
/* @0x1188f0 mov r3, #1 */
/* @0x1188f4 add r0, pc, r0 */
/* @0x1188f8 ldr r1, [r4, r1] */
/* @0x1188fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118900 ldr r1, [pc, #0x944] */
/* @0x118904 ldr r0, [pc, #0x944] */
/* @0x118908 mov r2, #5 */
/* @0x11890c mov r3, #1 */
/* @0x118910 add r0, pc, r0 */
/* @0x118914 ldr r1, [r4, r1] */
/* @0x118918 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x11891c ldr r1, [pc, #0x930] */
/* @0x118920 ldr r0, [pc, #0x930] */
/* @0x118924 mov r2, #3 */
/* @0x118928 mov r3, #1 */
/* @0x11892c add r0, pc, r0 */
/* @0x118930 ldr r1, [r4, r1] */
/* @0x118934 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118938 ldr r1, [pc, #0x91c] */
/* @0x11893c ldr r0, [pc, #0x91c] */
/* @0x118940 mov r2, #6 */
/* @0x118944 mov r3, #1 */
/* @0x118948 add r0, pc, r0 */
/* @0x11894c ldr r1, [r4, r1] */
/* @0x118950 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118954 ldr r1, [pc, #0x908] */
/* @0x118958 ldr r0, [pc, #0x908] */
/* @0x11895c mov r2, #3 */
/* @0x118960 mov r3, #1 */
/* @0x118964 add r0, pc, r0 */
/* @0x118968 ldr r1, [r4, r1] */
/* @0x11896c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118970 ldr r1, [pc, #0x8f4] */
/* @0x118974 ldr r0, [pc, #0x8f4] */
/* @0x118978 mov r2, #7 */
/* @0x11897c mov r3, #1 */
/* @0x118980 add r0, pc, r0 */
/* @0x118984 ldr r1, [r4, r1] */
/* @0x118988 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x11898c ldr r1, [pc, #0x8e0] */
/* @0x118990 ldr r0, [pc, #0x8e0] */
/* @0x118994 mov r2, #3 */
/* @0x118998 mov r3, #1 */
/* @0x11899c add r0, pc, r0 */
/* @0x1189a0 ldr r1, [r4, r1] */
/* @0x1189a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1189a8 ldr r1, [pc, #0x8cc] */
/* @0x1189ac ldr r0, [pc, #0x8cc] */
/* @0x1189b0 mov r2, #8 */
/* @0x1189b4 mov r3, #1 */
/* @0x1189b8 add r0, pc, r0 */
/* @0x1189bc ldr r1, [r4, r1] */
/* @0x1189c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1189c4 ldr r1, [pc, #0x8b8] */
/* @0x1189c8 ldr r0, [pc, #0x8b8] */
/* @0x1189cc mov r2, #3 */
/* @0x1189d0 mov r3, #1 */
/* @0x1189d4 add r0, pc, r0 */
/* @0x1189d8 ldr r1, [r4, r1] */
/* @0x1189dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1189e0 ldr r1, [pc, #0x8a4] */
/* @0x1189e4 ldr r0, [pc, #0x8a4] */
/* @0x1189e8 mov r2, #9 */
/* @0x1189ec mov r3, #1 */
/* @0x1189f0 add r0, pc, r0 */
/* @0x1189f4 ldr r1, [r4, r1] */
/* @0x1189f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1189fc ldr r1, [pc, #0x890] */
/* @0x118a00 mov r2, #0 */
/* @0x118a04 ldr r0, [pc, #0x88c] */
/* @0x118a08 mov r3, r2 */
/* @0x118a0c ldr r1, [r4, r1] */
/* @0x118a10 add r0, pc, r0 */
/* @0x118a14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118a18 ldr r1, [pc, #0x87c] */
/* @0x118a1c ldr r0, [pc, #0x87c] */
/* @0x118a20 mov r2, #0 */
/* @0x118a24 mov r3, r2 */
/* @0x118a28 ldr r1, [r4, r1] */
/* @0x118a2c add r0, pc, r0 */
/* @0x118a30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118a34 ldr r1, [pc, #0x868] */
/* @0x118a38 ldr r0, [pc, #0x868] */
/* @0x118a3c mov r2, #1 */
/* @0x118a40 mov r3, #0 */
/* @0x118a44 ldr r1, [r4, r1] */
/* @0x118a48 add r0, pc, r0 */
/* @0x118a4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118a50 ldr r1, [pc, #0x854] */
/* @0x118a54 ldr r0, [pc, #0x854] */
/* @0x118a58 mov r2, #1 */
/* @0x118a5c mov r3, #0 */
/* @0x118a60 ldr r1, [r4, r1] */
/* @0x118a64 add r0, pc, r0 */
/* @0x118a68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118a6c ldr r1, [pc, #0x840] */
/* @0x118a70 ldr r0, [pc, #0x840] */
/* @0x118a74 mov r2, #1 */
/* @0x118a78 mov r3, #0 */
/* @0x118a7c ldr r1, [r4, r1] */
/* @0x118a80 add r0, pc, r0 */
/* @0x118a84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118a88 ldr r1, [pc, #0x82c] */
/* @0x118a8c ldr r0, [pc, #0x82c] */
/* @0x118a90 mov r2, #0 */
/* @0x118a94 mov r3, r2 */
/* @0x118a98 ldr r1, [r4, r1] */
/* @0x118a9c add r0, pc, r0 */
/* @0x118aa0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118aa4 ldr r1, [pc, #0x818] */
/* @0x118aa8 ldr r0, [pc, #0x818] */
/* @0x118aac mov r2, #1 */
/* @0x118ab0 mov r3, #0 */
/* @0x118ab4 ldr r1, [r4, r1] */
/* @0x118ab8 add r0, pc, r0 */
/* @0x118abc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118ac0 ldr r1, [pc, #0x804] */
/* @0x118ac4 ldr r0, [pc, #0x804] */
/* @0x118ac8 mov r2, #1 */
/* @0x118acc mov r3, #0 */
/* @0x118ad0 ldr r1, [r4, r1] */
/* @0x118ad4 add r0, pc, r0 */
/* @0x118ad8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118adc ldr r1, [pc, #0x7f0] */
/* @0x118ae0 ldr r0, [pc, #0x7f0] */
/* @0x118ae4 mov r2, #2 */
/* @0x118ae8 mov r3, #0 */
/* @0x118aec ldr r1, [r4, r1] */
/* @0x118af0 add r0, pc, r0 */
/* @0x118af4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118af8 ldr r1, [pc, #0x7dc] */
/* @0x118afc ldr r0, [pc, #0x7dc] */
/* @0x118b00 mov r2, #1 */
/* @0x118b04 mov r3, #0 */
/* @0x118b08 ldr r1, [r4, r1] */
/* @0x118b0c add r0, pc, r0 */
/* @0x118b10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118b14 ldr r1, [pc, #0x7c8] */
/* @0x118b18 ldr r0, [pc, #0x7c8] */
/* @0x118b1c mov r2, #1 */
/* @0x118b20 mov r3, #0 */
/* @0x118b24 ldr r1, [r4, r1] */
/* @0x118b28 add r0, pc, r0 */
/* @0x118b2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118b30 ldr r1, [pc, #0x7b4] */
/* @0x118b34 ldr r0, [pc, #0x7b4] */
/* @0x118b38 mov r2, #1 */
/* @0x118b3c mov r3, #0 */
/* @0x118b40 ldr r1, [r4, r1] */
/* @0x118b44 add r0, pc, r0 */
/* @0x118b48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118b4c ldr r1, [pc, #0x7a0] */
/* @0x118b50 ldr r0, [pc, #0x7a0] */
/* @0x118b54 mov r2, #2 */
/* @0x118b58 mov r3, #0 */
/* @0x118b5c ldr r1, [r4, r1] */
/* @0x118b60 add r0, pc, r0 */
/* @0x118b64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118b68 ldr r1, [pc, #0x78c] */
/* @0x118b6c ldr r0, [pc, #0x78c] */
/* @0x118b70 mov r2, #2 */
/* @0x118b74 mov r3, #0 */
/* @0x118b78 ldr r1, [r4, r1] */
/* @0x118b7c add r0, pc, r0 */
/* @0x118b80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118b84 ldr r1, [pc, #0x778] */
/* @0x118b88 ldr r0, [pc, #0x778] */
/* @0x118b8c mov r2, #2 */
/* @0x118b90 mov r3, #0 */
/* @0x118b94 ldr r1, [r4, r1] */
/* @0x118b98 add r0, pc, r0 */
/* @0x118b9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118ba0 ldr r1, [pc, #0x764] */
/* @0x118ba4 ldr r0, [pc, #0x764] */
/* @0x118ba8 mov r2, #3 */
/* @0x118bac mov r3, #0 */
/* @0x118bb0 ldr r1, [r4, r1] */
/* @0x118bb4 add r0, pc, r0 */
/* @0x118bb8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118bbc ldr r1, [pc, #0x750] */
/* @0x118bc0 ldr r0, [pc, #0x750] */
/* @0x118bc4 mov r2, #1 */
/* @0x118bc8 mov r3, #0 */
/* @0x118bcc ldr r1, [r4, r1] */
/* @0x118bd0 add r0, pc, r0 */
/* @0x118bd4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118bd8 ldr r1, [pc, #0x73c] */
/* @0x118bdc ldr r0, [pc, #0x73c] */
/* @0x118be0 mov r2, #0 */
/* @0x118be4 mov r3, r2 */
/* @0x118be8 ldr r1, [r4, r1] */
/* @0x118bec add r0, pc, r0 */
/* @0x118bf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118bf4 ldr r1, [pc, #0x728] */
/* @0x118bf8 ldr r0, [pc, #0x728] */
/* @0x118bfc mov r2, #1 */
/* @0x118c00 mov r3, #0 */
/* @0x118c04 ldr r1, [r4, r1] */
/* @0x118c08 add r0, pc, r0 */
/* @0x118c0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118c10 ldr r1, [pc, #0x714] */
/* @0x118c14 ldr r0, [pc, #0x714] */
/* @0x118c18 mov r2, #0 */
/* @0x118c1c mov r3, r2 */
/* @0x118c20 ldr r1, [r4, r1] */
/* @0x118c24 add r0, pc, r0 */
/* @0x118c28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118c2c ldr r1, [pc, #0x700] */
/* @0x118c30 ldr r0, [pc, #0x700] */
/* @0x118c34 mov r2, #0 */
/* @0x118c38 mov r3, r2 */
/* @0x118c3c ldr r1, [r4, r1] */
/* @0x118c40 add r0, pc, r0 */
/* @0x118c44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118c48 ldr r1, [pc, #0x6ec] */
/* @0x118c4c ldr r0, [pc, #0x6ec] */
/* @0x118c50 mov r2, #0 */
/* @0x118c54 mov r3, r2 */
/* @0x118c58 ldr r1, [r4, r1] */
/* @0x118c5c add r0, pc, r0 */
/* @0x118c60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118c64 ldr r1, [pc, #0x6d8] */
/* @0x118c68 ldr r0, [pc, #0x6d8] */
/* @0x118c6c mov r2, #0 */
/* @0x118c70 mov r3, r2 */
/* @0x118c74 ldr r1, [r4, r1] */
/* @0x118c78 add r0, pc, r0 */
/* @0x118c7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118c80 ldr r1, [pc, #0x6c4] */
/* @0x118c84 ldr r0, [pc, #0x6c4] */
/* @0x118c88 mov r2, #6 */
/* @0x118c8c mov r3, #0 */
/* @0x118c90 ldr r1, [r4, r1] */
/* @0x118c94 add r0, pc, r0 */
/* @0x118c98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118c9c ldr r1, [pc, #0x6b0] */
/* @0x118ca0 ldr r0, [pc, #0x6b0] */
/* @0x118ca4 mov r2, #3 */
/* @0x118ca8 mov r3, #0 */
/* @0x118cac ldr r1, [r4, r1] */
/* @0x118cb0 add r0, pc, r0 */
/* @0x118cb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118cb8 ldr r1, [pc, #0x69c] */
/* @0x118cbc ldr r0, [pc, #0x69c] */
/* @0x118cc0 mov r2, #3 */
/* @0x118cc4 mov r3, #0 */
/* @0x118cc8 ldr r1, [r4, r1] */
/* @0x118ccc add r0, pc, r0 */
/* @0x118cd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118cd4 ldr r1, [pc, #0x688] */
/* @0x118cd8 ldr r0, [pc, #0x688] */
/* @0x118cdc mov r2, #6 */
/* @0x118ce0 mov r3, #0 */
/* @0x118ce4 ldr r1, [r4, r1] */
/* @0x118ce8 add r0, pc, r0 */
/* @0x118cec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118cf0 ldr r1, [pc, #0x674] */
/* @0x118cf4 ldr r0, [pc, #0x674] */
/* @0x118cf8 mov r2, #3 */
/* @0x118cfc mov r3, #0 */
/* @0x118d00 ldr r1, [r4, r1] */
/* @0x118d04 add r0, pc, r0 */
/* @0x118d08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118d0c ldr r1, [pc, #0x660] */
/* @0x118d10 ldr r0, [pc, #0x660] */
/* @0x118d14 mov r2, #3 */
/* @0x118d18 mov r3, #0 */
/* @0x118d1c ldr r1, [r4, r1] */
/* @0x118d20 add r0, pc, r0 */
/* @0x118d24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118d28 ldr r1, [pc, #0x64c] */
/* @0x118d2c ldr r0, [pc, #0x64c] */
/* @0x118d30 mov r2, #2 */
/* @0x118d34 mov r3, #0 */
/* @0x118d38 ldr r1, [r4, r1] */
/* @0x118d3c add r0, pc, r0 */
/* @0x118d40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118d44 ldr r1, [pc, #0x638] */
/* @0x118d48 ldr r0, [pc, #0x638] */
/* @0x118d4c mov r2, #2 */
/* @0x118d50 mov r3, #0 */
/* @0x118d54 ldr r1, [r4, r1] */
/* @0x118d58 add r0, pc, r0 */
/* @0x118d5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118d60 ldr r1, [pc, #0x624] */
/* @0x118d64 ldr r0, [pc, #0x624] */
/* @0x118d68 mov r2, #2 */
/* @0x118d6c mov r3, #0 */
/* @0x118d70 ldr r1, [r4, r1] */
/* @0x118d74 add r0, pc, r0 */
/* @0x118d78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118d7c ldr r1, [pc, #0x610] */
/* @0x118d80 ldr r0, [pc, #0x610] */
/* @0x118d84 mov r2, #2 */
/* @0x118d88 mov r3, #0 */
/* @0x118d8c ldr r1, [r4, r1] */
/* @0x118d90 add r0, pc, r0 */
/* @0x118d94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118d98 ldr r1, [pc, #0x5fc] */
/* @0x118d9c ldr r0, [pc, #0x5fc] */
/* @0x118da0 mov r2, #2 */
/* @0x118da4 mov r3, #0 */
/* @0x118da8 ldr r1, [r4, r1] */
/* @0x118dac add r0, pc, r0 */
/* @0x118db0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118db4 ldr r1, [pc, #0x5e8] */
/* @0x118db8 ldr r0, [pc, #0x5e8] */
/* @0x118dbc mov r2, #2 */
/* @0x118dc0 mov r3, #0 */
/* @0x118dc4 ldr r1, [r4, r1] */
/* @0x118dc8 add r0, pc, r0 */
/* @0x118dcc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118dd0 ldr r1, [pc, #0x5d4] */
/* @0x118dd4 ldr r0, [pc, #0x5d4] */
/* @0x118dd8 mov r2, #2 */
/* @0x118ddc mov r3, #0 */
/* @0x118de0 ldr r1, [r4, r1] */
/* @0x118de4 add r0, pc, r0 */
/* @0x118de8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118dec ldr r1, [pc, #0x5c0] */
/* @0x118df0 ldr r0, [pc, #0x5c0] */
/* @0x118df4 mov r2, #1 */
/* @0x118df8 mov r3, #0 */
/* @0x118dfc ldr r1, [r4, r1] */
/* @0x118e00 add r0, pc, r0 */
/* @0x118e04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118e08 ldr r1, [pc, #0x5ac] */
/* @0x118e0c ldr r0, [pc, #0x5ac] */
/* @0x118e10 mov r2, #1 */
/* @0x118e14 mov r3, #0 */
/* @0x118e18 ldr r1, [r4, r1] */
/* @0x118e1c add r0, pc, r0 */
/* @0x118e20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118e24 ldr r1, [pc, #0x598] */
/* @0x118e28 ldr r0, [pc, #0x598] */
/* @0x118e2c mov r2, #1 */
/* @0x118e30 mov r3, #0 */
/* @0x118e34 ldr r1, [r4, r1] */
/* @0x118e38 add r0, pc, r0 */
/* @0x118e3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118e40 ldr r1, [pc, #0x584] */
/* @0x118e44 ldr r0, [pc, #0x584] */
/* @0x118e48 mov r2, #1 */
/* @0x118e4c mov r3, #0 */
/* @0x118e50 ldr r1, [r4, r1] */
/* @0x118e54 add r0, pc, r0 */
/* @0x118e58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118e5c ldr r1, [pc, #0x570] */
/* @0x118e60 ldr r0, [pc, #0x570] */
/* @0x118e64 mov r2, #1 */
/* @0x118e68 mov r3, #0 */
/* @0x118e6c ldr r1, [r4, r1] */
/* @0x118e70 add r0, pc, r0 */
/* @0x118e74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118e78 ldr r1, [pc, #0x55c] */
/* @0x118e7c ldr r0, [pc, #0x55c] */
/* @0x118e80 mov r2, #1 */
/* @0x118e84 mov r3, #0 */
/* @0x118e88 ldr r1, [r4, r1] */
/* @0x118e8c add r0, pc, r0 */
/* @0x118e90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118e94 ldr r1, [pc, #0x548] */
/* @0x118e98 ldr r0, [pc, #0x548] */
/* @0x118e9c mov r2, #1 */
/* @0x118ea0 mov r3, #0 */
/* @0x118ea4 ldr r1, [r4, r1] */
/* @0x118ea8 add r0, pc, r0 */
/* @0x118eac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118eb0 ldr r1, [pc, #0x534] */
/* @0x118eb4 ldr r0, [pc, #0x534] */
/* @0x118eb8 mov r2, #1 */
/* @0x118ebc mov r3, #0 */
/* @0x118ec0 ldr r1, [r4, r1] */
/* @0x118ec4 add r0, pc, r0 */
/* @0x118ec8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118ecc ldr r1, [pc, #0x520] */
/* @0x118ed0 ldr r0, [pc, #0x520] */
/* @0x118ed4 mov r2, #1 */
/* @0x118ed8 mov r3, #0 */
/* @0x118edc ldr r1, [r4, r1] */
/* @0x118ee0 add r0, pc, r0 */
/* @0x118ee4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118ee8 ldr r1, [pc, #0x50c] */
/* @0x118eec ldr r0, [pc, #0x50c] */
/* @0x118ef0 mov r2, #1 */
/* @0x118ef4 mov r3, #0 */
/* @0x118ef8 ldr r1, [r4, r1] */
/* @0x118efc add r0, pc, r0 */
/* @0x118f00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118f04 ldr r1, [pc, #0x4f8] */
/* @0x118f08 ldr r0, [pc, #0x4f8] */
/* @0x118f0c mov r2, #1 */
/* @0x118f10 mov r3, #0 */
/* @0x118f14 ldr r1, [r4, r1] */
/* @0x118f18 add r0, pc, r0 */
/* @0x118f1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118f20 ldr r1, [pc, #0x4e4] */
/* @0x118f24 ldr r0, [pc, #0x4e4] */
/* @0x118f28 mov r2, #1 */
/* @0x118f2c mov r3, #0 */
/* @0x118f30 ldr r1, [r4, r1] */
/* @0x118f34 add r0, pc, r0 */
/* @0x118f38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118f3c ldr r1, [pc, #0x4d0] */
/* @0x118f40 ldr r0, [pc, #0x4d0] */
/* @0x118f44 mov r2, #2 */
/* @0x118f48 mov r3, #0 */
/* @0x118f4c ldr r1, [r4, r1] */
/* @0x118f50 add r0, pc, r0 */
/* @0x118f54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118f58 ldr r1, [pc, #0x4bc] */
/* @0x118f5c ldr r0, [pc, #0x4bc] */
/* @0x118f60 mov r2, #2 */
/* @0x118f64 mov r3, #0 */
/* @0x118f68 ldr r1, [r4, r1] */
/* @0x118f6c add r0, pc, r0 */
/* @0x118f70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118f74 ldr r1, [pc, #0x4a8] */
/* @0x118f78 ldr r0, [pc, #0x4a8] */
/* @0x118f7c mov r2, #2 */
/* @0x118f80 mov r3, #0 */
/* @0x118f84 ldr r1, [r4, r1] */
/* @0x118f88 add r0, pc, r0 */
/* @0x118f8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118f90 ldr r1, [pc, #0x494] */
/* @0x118f94 ldr r0, [pc, #0x494] */
/* @0x118f98 mov r2, #2 */
/* @0x118f9c mov r3, #0 */
/* @0x118fa0 ldr r1, [r4, r1] */
/* @0x118fa4 add r0, pc, r0 */
/* @0x118fa8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118fac ldr r1, [pc, #0x480] */
/* @0x118fb0 ldr r0, [pc, #0x480] */
/* @0x118fb4 mov r2, #2 */
/* @0x118fb8 mov r3, #0 */
/* @0x118fbc ldr r1, [r4, r1] */
/* @0x118fc0 add r0, pc, r0 */
/* @0x118fc4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118fc8 ldr r1, [pc, #0x46c] */
/* @0x118fcc ldr r0, [pc, #0x46c] */
/* @0x118fd0 mov r2, #2 */
/* @0x118fd4 mov r3, #0 */
/* @0x118fd8 ldr r1, [r4, r1] */
/* @0x118fdc add r0, pc, r0 */
/* @0x118fe0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x118fe4 ldr r1, [pc, #0x458] */
/* @0x118fe8 ldr r0, [pc, #0x458] */
/* @0x118fec mov r2, #2 */
/* @0x118ff0 mov r3, #0 */
/* @0x118ff4 ldr r1, [r4, r1] */
/* @0x118ff8 add r0, pc, r0 */
/* @0x118ffc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x119000 ldr r1, [pc, #0x444] */
/* @0x119004 ldr r0, [pc, #0x444] */
/* @0x119008 mov r2, #2 */
/* @0x11900c mov r3, #0 */
/* @0x119010 ldr r1, [r4, r1] */
/* @0x119014 add r0, pc, r0 */
/* @0x119018 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x11901c ldr r1, [pc, #0x430] */
/* @0x119020 ldr r0, [pc, #0x430] */
/* @0x119024 mov r2, #2 */
/* @0x119028 mov r3, #0 */
/* @0x11902c ldr r1, [r4, r1] */
/* @0x119030 add r0, pc, r0 */
/* @0x119034 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x119038 ldr r1, [pc, #0x41c] */
/* @0x11903c ldr r0, [pc, #0x41c] */
/* @0x119040 mov r2, #2 */
/* @0x119044 mov r3, #0 */
/* @0x119048 ldr r1, [r4, r1] */
/* @0x11904c add r0, pc, r0 */
/* @0x119050 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x119054 ldr r1, [pc, #0x408] */
/* @0x119058 ldr r0, [pc, #0x408] */
/* @0x11905c mov r2, #1 */
/* @0x119060 mov r3, #0 */
/* @0x119064 ldr r1, [r4, r1] */
/* @0x119068 add r0, pc, r0 */
/* @0x11906c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x119070 ldr r1, [pc, #0x3f4] */
/* @0x119074 ldr r0, [pc, #0x3f4] */
/* @0x119078 mov r2, #1 */
/* @0x11907c mov r3, #0 */
/* @0x119080 ldr r1, [r4, r1] */
/* @0x119084 add r0, pc, r0 */
/* @0x119088 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x11908c ldr r1, [pc, #0x3e0] */
/* @0x119090 ldr r0, [pc, #0x3e0] */
/* @0x119094 mov r2, #1 */
/* @0x119098 mov r3, #0 */
/* @0x11909c ldr r1, [r4, r1] */
/* @0x1190a0 add r0, pc, r0 */
/* @0x1190a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1190a8 ldr r1, [pc, #0x3cc] */
/* @0x1190ac ldr r0, [pc, #0x3cc] */
/* @0x1190b0 mov r2, #1 */
/* @0x1190b4 mov r3, #0 */
/* @0x1190b8 ldr r1, [r4, r1] */
/* @0x1190bc add r0, pc, r0 */
/* @0x1190c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1190c4 ldr r1, [pc, #0x3b8] */
/* @0x1190c8 ldr r0, [pc, #0x3b8] */
/* @0x1190cc mov r2, #1 */
/* @0x1190d0 mov r3, #0 */
/* @0x1190d4 ldr r1, [r4, r1] */
/* @0x1190d8 add r0, pc, r0 */
/* @0x1190dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1190e0 ldr r1, [pc, #0x3a4] */
/* @0x1190e4 ldr r0, [pc, #0x3a4] */
/* @0x1190e8 mov r2, #1 */
/* @0x1190ec mov r3, #0 */
/* @0x1190f0 ldr r1, [r4, r1] */
/* @0x1190f4 add r0, pc, r0 */
/* @0x1190f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1190fc ldr r1, [pc, #0x390] */
/* @0x119100 ldr r0, [pc, #0x390] */
/* @0x119104 mov r2, #1 */
/* @0x119108 mov r3, #0 */
/* @0x11910c ldr r1, [r4, r1] */
/* @0x119110 add r0, pc, r0 */
/* @0x119114 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x119118 ldr r1, [pc, #0x37c] */
/* @0x11911c ldr r0, [pc, #0x37c] */
/* @0x119120 mov r2, #1 */
/* @0x119124 mov r3, #0 */
/* @0x119128 ldr r1, [r4, r1] */
/* @0x11912c add r0, pc, r0 */
/* @0x119130 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x119134 ldr r1, [pc, #0x368] */
/* @0x119138 ldr r0, [pc, #0x368] */
/* @0x11913c mov r2, #1 */
/* @0x119140 mov r3, #0 */
/* @0x119144 ldr r1, [r4, r1] */
/* @0x119148 add r0, pc, r0 */
/* @0x11914c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x119150 ldr r1, [pc, #0x354] */
/* @0x119154 ldr r0, [pc, #0x354] */
/* @0x119158 mov r2, #1 */
/* @0x11915c mov r3, #0 */
/* @0x119160 ldr r1, [r4, r1] */
/* @0x119164 add r0, pc, r0 */
/* @0x119168 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x11916c ldr r1, [pc, #0x340] */
/* @0x119170 ldr r0, [pc, #0x340] */
/* @0x119174 mov r2, #0 */
/* @0x119178 mov r3, r2 */
/* @0x11917c ldr r1, [r4, r1] */
/* @0x119180 add r0, pc, r0 */
/* @0x119184 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x119188 ldr r1, [pc, #0x32c] */
/* @0x11918c ldr r0, [pc, #0x32c] */
/* @0x119190 mov r2, #2 */
/* @0x119194 mov r3, #1 */
/* @0x119198 ldr r1, [r4, r1] */
/* @0x11919c add r0, pc, r0 */
/* @0x1191a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1191a4 ldr r1, [pc, #0x318] */
/* @0x1191a8 ldr r0, [pc, #0x318] */
/* @0x1191ac mov r2, #2 */
/* @0x1191b0 mov r3, #1 */
/* @0x1191b4 ldr r1, [r4, r1] */
/* @0x1191b8 add r0, pc, r0 */
/* @0x1191bc pop {r4, lr} */
/* @0x1191c0 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1191c4 eoreq r9, sp, r12, lsl r5 */
/* @0x1191c8 .word 0xffffc7e0 */
/* @0x1191cc .word 0x002210f8 */
/* @0x1191d0 .word 0xffffc7e4 */
/* @0x1191d4 eoreq r1, r2, r12, ror #1 */
/* @0x1191d8 .word 0xffffc7e8 */
/* @0x1191dc eoreq r1, r2, r0, ror #1 */
/* @0x1191e0 .word 0xffffc7ec */
/* @0x1191e4 .word 0x002210d0 */
/* @0x1191e8 .word 0xffffc180 */
/* @0x1191ec .word 0xffffc7f0 */
/* @0x1191f0 strhteq r1, [r2], -r8 */
/* @0x1191f4 .word 0xffffc7f4 */
/* @0x1191f8 eoreq r1, r2, r12, lsr #1 */
/* @0x1191fc .word 0xffffc7f8 */
/* @0x119200 eoreq r1, r2, r0, lsr #1 */
/* @0x119204 .word 0xffffc7fc */
/* @0x119208 mlaeq r2, r4, r0, r1 */
/* @0x11920c .word 0xffffc800 */
/* @0x119210 eoreq r1, r2, r12, lsl #1 */
/* @0x119214 .word 0xffffc804 */
/* @0x119218 eoreq r1, r2, r0, lsl #1 */
/* @0x11921c .word 0xffffc808 */
/* @0x119220 eoreq r1, r2, r8, ror r0 */
/* @0x119224 .word 0xffffc80c */
/* @0x119228 eoreq r1, r2, r12, rrx */
/* @0x11922c .word 0xffffc810 */
/* @0x119230 eoreq r1, r2, r4, rrx */
/* @0x119234 .word 0xffffc814 */
/* @0x119238 eoreq r1, r2, r8, asr r0 */
/* @0x11923c .word 0xffffc818 */
/* @0x119240 eoreq r1, r2, r0, asr r0 */
/* @0x119244 .word 0xffffc81c */
/* @0x119248 eoreq r1, r2, r4, asr #32 */
/* @0x11924c .word 0xffffc820 */
/* @0x119250 eoreq r1, r2, r12, lsr r0 */
/* @0x119254 .word 0xffffc824 */
/* @0x119258 eoreq r1, r2, r0, lsr r0 */
/* @0x11925c .word 0xffffc828 */
/* @0x119260 eoreq r1, r2, r8, lsr #32 */
/* @0x119264 .word 0xffffc82c */
/* @0x119268 eoreq r1, r2, r12, lsl r0 */
/* @0x11926c .word 0xffffc830 */
/* @0x119270 eoreq r1, r2, r4, lsl r0 */
/* @0x119274 .word 0xffffc834 */
/* @0x119278 eoreq r1, r2, r8 */
/* @0x11927c .word 0xffffc838 */
/* @0x119280 eoreq r1, r2, r0 */
/* @0x119284 .word 0xffffc83c */
/* @0x119288 .word 0x00220ff4 */
/* @0x11928c .word 0xffffc840 */
/* @0x119290 eoreq r0, r2, r12, ror #31 */
/* @0x119294 .word 0xffffc844 */
/* @0x119298 .word 0x00220fdc */
/* @0x11929c .word 0xffffc848 */
/* @0x1192a0 .word 0x00220fd0 */
/* @0x1192a4 .word 0xffffc84c */
/* @0x1192a8 eoreq r0, r2, r4, asr #31 */
/* @0x1192ac .word 0xffffc850 */
/* @0x1192b0 .word 0x00220fbc */
/* @0x1192b4 .word 0xffffc854 */
/* @0x1192b8 .word 0x00220fb4 */
/* @0x1192bc .word 0xffffc858 */
/* @0x1192c0 eoreq r0, r2, r4, lsr #31 */
/* @0x1192c4 .word 0xffffc85c */
/* @0x1192c8 mlaeq r2, r12, pc, r0 */
/* @0x1192cc .word 0xffffc860 */
/* @0x1192d0 mlaeq r2, r8, pc, r0 */
/* @0x1192d4 .word 0xffffc864 */
/* @0x1192d8 mlaeq r2, r4, pc, r0 */
/* @0x1192dc .word 0xffffc868 */
/* @0x1192e0 eoreq r0, r2, r4, lsl #31 */
/* @0x1192e4 .word 0xffffc86c */
/* @0x1192e8 eoreq r0, r2, r4, ror pc */
/* @0x1192ec .word 0xffffc870 */
/* @0x1192f0 eoreq r0, r2, r0, ror pc */
/* @0x1192f4 .word 0xffffc874 */
/* @0x1192f8 eoreq r0, r2, r8, ror #30 */
/* @0x1192fc .word 0xffffc878 */
/* @0x119300 eoreq r0, r2, r0, ror #30 */
/* @0x119304 .word 0xffffc87c */
/* @0x119308 eoreq r0, r2, r0, ror #30 */
/* @0x11930c .word 0xffffc880 */
/* @0x119310 eoreq r0, r2, r12, asr pc */
/* @0x119314 .word 0xffffc884 */
/* @0x119318 eoreq r0, r2, r8, asr pc */
/* @0x11931c .word 0xffffc888 */
/* @0x119320 eoreq r0, r2, r8, asr pc */
/* @0x119324 .word 0xffffc88c */
/* @0x119328 eoreq r0, r2, r0, asr pc */
/* @0x11932c .word 0xffffc890 */
/* @0x119330 eoreq r0, r2, r8, asr #30 */
/* @0x119334 .word 0xffffc894 */
/* @0x119338 eoreq r0, r2, r0, asr #30 */
/* @0x11933c .word 0xffffc898 */
/* @0x119340 eoreq r0, r2, r12, lsr pc */
/* @0x119344 .word 0xffffc89c */
/* @0x119348 eoreq r0, r2, r4, lsr pc */
/* @0x11934c .word 0xffffc8a0 */
/* @0x119350 eoreq r0, r2, r12, lsr #30 */
/* @0x119354 .word 0xffffc8a4 */
/* @0x119358 eoreq r0, r2, r8, lsr #30 */
/* @0x11935c .word 0xffffc8a8 */
/* @0x119360 eoreq r0, r2, r0, lsr #30 */
/* @0x119364 .word 0xffffc8ac */
/* @0x119368 eoreq r0, r2, r8, lsl pc */
/* @0x11936c .word 0xffffc8b0 */
/* @0x119370 eoreq r0, r2, r0, lsl pc */
/* @0x119374 .word 0xffffc8b4 */
/* @0x119378 eoreq r0, r2, r4, lsl #30 */
/* @0x11937c .word 0xffffc8b8 */
/* @0x119380 .word 0x00220ef8 */
/* @0x119384 .word 0xffffc8bc */
/* @0x119388 eoreq r0, r2, r12, ror #29 */
/* @0x11938c .word 0xffffc8c0 */
/* @0x119390 eoreq r0, r2, r0, ror #29 */
/* @0x119394 .word 0xffffc8c4 */
/* @0x119398 .word 0x00220ed4 */
/* @0x11939c .word 0xffffc8c8 */
/* @0x1193a0 eoreq r0, r2, r8, asr #29 */
/* @0x1193a4 .word 0xffffc8cc */
/* @0x1193a8 .word 0x00220ebc */
/* @0x1193ac .word 0xffffc8d0 */
/* @0x1193b0 .word 0x00220eb0 */
/* @0x1193b4 .word 0xffffc8d4 */
/* @0x1193b8 eoreq r0, r2, r4, lsr #29 */
/* @0x1193bc .word 0xffffc8d8 */
/* @0x1193c0 mlaeq r2, r8, lr, r0 */
/* @0x1193c4 .word 0xffffc8dc */
/* @0x1193c8 eoreq r0, r2, r12, lsl #29 */
/* @0x1193cc .word 0xffffc8e0 */
/* @0x1193d0 eoreq r0, r2, r0, lsl #29 */
/* @0x1193d4 .word 0xffffc8e4 */
/* @0x1193d8 eoreq r0, r2, r4, ror lr */
/* @0x1193dc .word 0xffffc8e8 */
/* @0x1193e0 eoreq r0, r2, r8, ror #28 */
/* @0x1193e4 .word 0xffffc8ec */
/* @0x1193e8 eoreq r0, r2, r12, asr lr */
/* @0x1193ec .word 0xffffc8f0 */
/* @0x1193f0 eoreq r0, r2, r0, asr lr */
/* @0x1193f4 .word 0xffffc8f4 */
/* @0x1193f8 eoreq r0, r2, r8, asr #28 */
/* @0x1193fc .word 0xffffc8f8 */
/* @0x119400 eoreq r0, r2, r4, asr #28 */
/* @0x119404 .word 0xffffc8fc */
/* @0x119408 eoreq r0, r2, r0, asr #28 */
/* @0x11940c .word 0xffffc900 */
/* @0x119410 eoreq r0, r2, r12, lsr lr */
/* @0x119414 .word 0xffffc904 */
/* @0x119418 eoreq r0, r2, r8, lsr lr */
/* @0x11941c .word 0xffffc908 */
/* @0x119420 eoreq r0, r2, r12, lsr #28 */
/* @0x119424 .word 0xffffc90c */
/* @0x119428 eoreq r0, r2, r0, lsr #28 */
/* @0x11942c .word 0xffffc910 */
/* @0x119430 eoreq r0, r2, r4, lsl lr */
/* @0x119434 .word 0xffffc914 */
/* @0x119438 eoreq r0, r2, r8, lsl #28 */
/* @0x11943c .word 0xffffc918 */
/* @0x119440 .word 0x00220dfc */
/* @0x119444 .word 0xffffc91c */
/* @0x119448 .word 0x00220df4 */
/* @0x11944c .word 0xffffc920 */
/* @0x119450 eoreq r0, r2, r12, ror #27 */
/* @0x119454 .word 0xffffc924 */
/* @0x119458 eoreq r0, r2, r8, ror #27 */
/* @0x11945c .word 0xffffc928 */
/* @0x119460 eoreq r0, r2, r0, ror #27 */
/* @0x119464 .word 0xffffc92c */
/* @0x119468 .word 0x00220dd8 */
/* @0x11946c .word 0xffffc930 */
/* @0x119470 eoreq r0, r2, r12, asr #27 */
/* @0x119474 .word 0xffffc934 */
/* @0x119478 eoreq r0, r2, r0, asr #27 */
/* @0x11947c .word 0xffffc938 */
/* @0x119480 .word 0x00220dbc */
/* @0x119484 .word 0xffffc93c */
/* @0x119488 .word 0x00220db4 */
/* @0x11948c .word 0xffffc940 */
/* @0x119490 eoreq r0, r2, r12, lsr #27 */
/* @0x119494 .word 0xffffc944 */
/* @0x119498 eoreq r0, r2, r4, lsr #27 */
/* @0x11949c .word 0xffffc948 */
/* @0x1194a0 mlaeq r2, r12, sp, r0 */
/* @0x1194a4 .word 0xffffc94c */
/* @0x1194a8 mlaeq r2, r0, sp, r0 */
/* @0x1194ac .word 0xffffc950 */
/* @0x1194b0 eoreq r0, r2, r4, lsl #27 */
/* @0x1194b4 .word 0xffffc954 */
/* @0x1194b8 eoreq r0, r2, r12, ror sp */
/* @0x1194bc .word 0xffffc958 */
/* @0x1194c0 eoreq r0, r2, r4, ror sp */
/* @0x1194c4 .word 0xffffc95c */
/* @0x1194c8 eoreq r0, r2, r8, ror #26 */

/* ── FUNC 0x1194cc · F_ExternalCall(RValue&, CInstance*, CInstance*, int, RValue*) · size=728 · insn=182 */
/* @0x1194cc push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1194d0 sub sp, sp, #292 */
/* @0x1194d4 mov r7, r0 */
/* @0x1194d8 mov r1, #0 */
/* @0x1194dc ldr r4, [sp, #0x140] */
/* @0x1194e0 mov r6, r3 */
/* @0x1194e4 mov r0, r4 */
/* @0x1194e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1194ec subs r8, r0, #0 */
/* @0x1194f0 blt 0x11963c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x1194f4 add r5, sp, #16 */
/* @0x1194f8 sub r9, r6, #1 */
/* @0x1194fc mov r1, #0 */
/* @0x119500 mov r2, #272 */
/* @0x119504 mov r0, r5 */
/* @0x119508 bl 0xb65b0 <memset@plt> */
/* @0x11950c cmp r9, #0 */
/* @0x119510 subgt r6, r6, #-268435455 */
/* @0x119514 movgt r12, r4 */
/* @0x119518 movgt r4, #0 */
/* @0x11951c lslgt r6, r6, #4 */
/* @0x119520 ble 0x119540 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x119524 add r12, r12, #16 */
/* @0x119528 add lr, r5, r4 */
/* @0x11952c add r4, r4, #16 */
/* @0x119530 ldm r12, {r0, r1, r2, r3} */
/* @0x119534 cmp r4, r6 */
/* @0x119538 stm lr, {r0, r1, r2, r3} */
/* @0x11953c bne 0x119524 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x119540 mov r2, r5 */
/* @0x119544 mov r3, sp */
/* @0x119548 mov r0, r8 */
/* @0x11954c mov r1, r9 */
/* @0x119550 mov r12, #0 */
/* @0x119554 str r12, [sp] */
/* @0x119558 str r12, [sp, #0x4] */
/* @0x11955c str r12, [sp, #0x8] */
/* @0x119560 str r12, [sp, #0xc] */
/* @0x119564 bl 0x212b10 <_Z8DLL_CalliiP6RValueS0_> */
/* @0x119568 ldr r2, [r7, #0xc] */
/* @0x11956c bic r3, r2, #-16777216 */
/* @0x119570 cmp r3, #1 */
/* @0x119574 beq 0x1195f8 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x119578 cmp r3, #2 */
/* @0x11957c bne 0x119594 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x119580 sub r3, r2, #1 */
/* @0x119584 bic r3, r3, #-16777216 */
/* @0x119588 bic r3, r3, #3 */
/* @0x11958c cmp r3, #0 */
/* @0x119590 beq 0x1196d0 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x204> */
/* @0x119594 ldr r2, [sp, #0xc] */
/* @0x119598 mov r0, #0 */
/* @0x11959c ldr r1, [sp, #0x8] */
/* @0x1195a0 bic r3, r2, #-16777216 */
/* @0x1195a4 str r0, [r7] */
/* @0x1195a8 str r2, [r7, #0xc] */
/* @0x1195ac str r1, [r7, #0x8] */
/* @0x1195b0 cmp r3, #14 */
/* @0x1195b4 addls pc, pc, r3, lsl #2 */
/* @0x1195b8 b 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x1195bc b 0x11965c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x190> */
/* @0x1195c0 b 0x119698 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x1cc> */
/* @0x1195c4 b 0x11966c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x1195c8 b 0x11962c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x1195cc b 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x1195d0 b 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x1195d4 b 0x1196b0 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x1195d8 b 0x11962c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x1195dc b 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x1195e0 b 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x1195e4 b 0x11965c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x190> */
/* @0x1195e8 b 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x1195ec b 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x1195f0 b 0x11965c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x190> */
/* @0x1195f4 b 0x11962c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x1195f8 ldr r4, [r7] */
/* @0x1195fc cmp r4, #0 */
/* @0x119600 beq 0x119620 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x119604 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x119608 ldr r5, [r4, #0x4] */
/* @0x11960c sub r5, r5, #1 */
/* @0x119610 str r5, [r4, #0x4] */
/* @0x119614 cmp r5, #0 */
/* @0x119618 beq 0x1196dc <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x210> */
/* @0x11961c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x119620 mov r3, #0 */
/* @0x119624 str r3, [r7] */
/* @0x119628 b 0x119594 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x11962c ldr r3, [sp] */
/* @0x119630 str r3, [r7] */
/* @0x119634 add sp, sp, #292 */
/* @0x119638 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x11963c mov r2, #0 */
/* @0x119640 mov r3, r2 */
/* @0x119644 movt r2, #0xbff0 */
/* @0x119648 str r3, [r7] */
/* @0x11964c str r2, [r7, #0x4] */
/* @0x119650 str r3, [r7, #0xc] */
/* @0x119654 add sp, sp, #292 */
/* @0x119658 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x11965c ldm sp, {r2, r3} */
/* @0x119660 stm r7, {r2, r3} */
/* @0x119664 add sp, sp, #292 */
/* @0x119668 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x11966c ldr r3, [sp] */
/* @0x119670 cmp r3, #0 */
/* @0x119674 str r3, [r7] */
/* @0x119678 beq 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x11967c ldr r1, [r3, #0x8] */
/* @0x119680 ldr r2, [r3] */
/* @0x119684 cmp r1, #0 */
/* @0x119688 streq r7, [r3, #0x8] */
/* @0x11968c add r2, r2, #1 */
/* @0x119690 str r2, [r3] */
/* @0x119694 b 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x119698 ldr r3, [sp] */
/* @0x11969c cmp r3, #0 */
/* @0x1196a0 ldrne r2, [r3, #0x4] */
/* @0x1196a4 addne r2, r2, #1 */
/* @0x1196a8 strne r2, [r3, #0x4] */
/* @0x1196ac b 0x119630 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x1196b0 ldr r3, [sp] */
/* @0x1196b4 cmp r3, #0 */
/* @0x1196b8 str r3, [r7] */
/* @0x1196bc beq 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x1196c0 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1196c4 ldr r1, [sp] */
/* @0x1196c8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x1196cc b 0x119634 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x1196d0 mov r0, r7 */
/* @0x1196d4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1196d8 b 0x119594 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x1196dc ldr r0, [r4] */
/* @0x1196e0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1196e4 str r5, [r4] */
/* @0x1196e8 str r5, [r4, #0x8] */
/* @0x1196ec bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1196f0 ldr r5, [r4, #0x4] */
/* @0x1196f4 sub r5, r5, #1 */
/* @0x1196f8 str r5, [r4, #0x4] */
/* @0x1196fc cmp r5, #0 */
/* @0x119700 beq 0x119714 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x248> */
/* @0x119704 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x119708 mov r0, r4 */
/* @0x11970c bl 0x27d1d0 <_ZdlPv> */
/* @0x119710 b 0x11961c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x119714 ldr r0, [r4] */
/* @0x119718 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x11971c str r5, [r4] */
/* @0x119720 str r5, [r4, #0x8] */
/* @0x119724 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x119728 ldr r5, [r4, #0x4] */
/* @0x11972c sub r5, r5, #1 */
/* @0x119730 str r5, [r4, #0x4] */
/* @0x119734 cmp r5, #0 */
/* @0x119738 beq 0x11974c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x280> */
/* @0x11973c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x119740 mov r0, r4 */
/* @0x119744 bl 0x27d1d0 <_ZdlPv> */
/* @0x119748 b 0x119704 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x238> */
/* @0x11974c ldr r0, [r4] */
/* @0x119750 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x119754 str r5, [r4] */
/* @0x119758 str r5, [r4, #0x8] */
/* @0x11975c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x119760 ldr r5, [r4, #0x4] */
/* @0x119764 sub r5, r5, #1 */
/* @0x119768 str r5, [r4, #0x4] */
/* @0x11976c cmp r5, #0 */
/* @0x119770 bne 0x119794 <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x2c8> */
/* @0x119774 ldr r0, [r4] */
/* @0x119778 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x11977c mov r0, r4 */
/* @0x119780 str r5, [r4] */
/* @0x119784 str r5, [r4, #0x8] */
/* @0x119788 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x11978c mov r0, r4 */
/* @0x119790 bl 0x27d1d0 <_ZdlPv> */
/* @0x119794 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x119798 mov r0, r4 */
/* @0x11979c bl 0x27d1d0 <_ZdlPv> */
/* @0x1197a0 b 0x11973c <_Z14F_ExternalCallR6RValueP9CInstanceS2_iPS_+0x270> */

/* ── FUNC 0x1197a4 · F_VariableGlobalExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=224 · insn=56 */
/* @0x1197a4 push {r4, r5, r6, lr} */
/* @0x1197a8 sub sp, sp, #16 */
/* @0x1197ac mov r5, r0 */
/* @0x1197b0 mov r1, #0 */
/* @0x1197b4 ldr r0, [sp, #0x20] */
/* @0x1197b8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1197bc ldr r3, [pc, #0xbc] */
/* @0x1197c0 mov r2, #0 */
/* @0x1197c4 mov r12, #13 */
/* @0x1197c8 ldr r3, [pc, r3] */
/* @0x1197cc str r12, [r5, #0xc] */
/* @0x1197d0 str r2, [r5, #0x4] */
/* @0x1197d4 ldr r4, [r3] */
/* @0x1197d8 str r2, [r5] */
/* @0x1197dc mov r6, r0 */
/* @0x1197e0 bl 0x1f3a5c <_Z21Variable_BuiltIn_FindPKc> */
/* @0x1197e4 subs r1, r0, #0 */
/* @0x1197e8 blt 0x119860 <_Z22F_VariableGlobalExistsR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x1197ec mov r0, r4 */
/* @0x1197f0 mov r2, #-2147483648 */
/* @0x1197f4 mov r3, sp */
/* @0x1197f8 mov r4, #0 */
/* @0x1197fc str r4, [sp] */
/* @0x119800 str r4, [sp, #0x4] */
/* @0x119804 str r4, [sp, #0x8] */
/* @0x119808 str r4, [sp, #0xc] */
/* @0x11980c bl 0x1f3b8c <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue> */
/* @0x119810 ldr r2, [sp, #0xc] */
/* @0x119814 mvn r3, #-16777216 */
/* @0x119818 and r1, r2, r3 */
/* @0x11981c cmp r1, r3 */
/* @0x119820 moveq r1, r4 */
/* @0x119824 movne r1, #0 */
/* @0x119828 movtne r1, #0x3ff0 */
/* @0x11982c sub r2, r2, #1 */
/* @0x119830 str r4, [r5] */
/* @0x119834 bic r2, r2, #-16777216 */
/* @0x119838 str r1, [r5, #0x4] */
/* @0x11983c bic r2, r2, #3 */
/* @0x119840 cmp r2, #0 */
/* @0x119844 beq 0x119850 <_Z22F_VariableGlobalExistsR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x119848 add sp, sp, #16 */
/* @0x11984c pop {r4, r5, r6, pc} */
/* @0x119850 mov r0, sp */
/* @0x119854 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x119858 add sp, sp, #16 */
/* @0x11985c pop {r4, r5, r6, pc} */
/* @0x119860 mov r1, r6 */
/* @0x119864 mov r0, r4 */
/* @0x119868 bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc> */
/* @0x11986c cmp r0, #0 */
/* @0x119870 blt 0x119848 <_Z22F_VariableGlobalExistsR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x119874 add r1, r0, #99328 */
/* @0x119878 add r1, r1, #672 */
/* @0x11987c b 0x1197ec <_Z22F_VariableGlobalExistsR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x119880 eoreq r4, sp, r12, ror #7 */

/* ── FUNC 0x119884 · F_VariableInstanceGetNames(RValue&, CInstance*, CInstance*, int, RValue*) · size=352 · insn=88 */
/* @0x119884 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x119888 sub sp, sp, #20 */
/* @0x11988c mov r7, r0 */
/* @0x119890 mov r1, #0 */
/* @0x119894 ldr r0, [sp, #0x30] */
/* @0x119898 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11989c cmp r0, #0 */
/* @0x1198a0 blt 0x1199b8 <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1198a4 ldr r3, [pc, #0x134] */
/* @0x1198a8 ldr r3, [pc, r3] */
/* @0x1198ac ldr r2, [r3, #0x4] */
/* @0x1198b0 ldr r3, [r3] */
/* @0x1198b4 and r2, r0, r2 */
/* @0x1198b8 ldr r3, [r3, r2, lsl #3] */
/* @0x1198bc cmp r3, #0 */
/* @0x1198c0 bne 0x1198d4 <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x1198c4 b 0x1199b8 <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1198c8 ldr r3, [r3, #0x4] */
/* @0x1198cc cmp r3, #0 */
/* @0x1198d0 beq 0x1199b8 <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1198d4 ldr r2, [r3, #0x8] */
/* @0x1198d8 cmp r0, r2 */
/* @0x1198dc bne 0x1198c8 <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1198e0 ldr r8, [r3, #0xc] */
/* @0x1198e4 mov r0, r7 */
/* @0x1198e8 mov r3, #2 */
/* @0x1198ec str r3, [r7, #0xc] */
/* @0x1198f0 bl 0xced9c <_Z14ARRAY_RefAllocPv> */
/* @0x1198f4 cmp r8, #0 */
/* @0x1198f8 str r0, [r7] */
/* @0x1198fc beq 0x1199cc <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x119900 ldr r3, [r8, #0x60] */
/* @0x119904 cmp r3, #0 */
/* @0x119908 beq 0x1199cc <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x11990c ldr r1, [r3] */
/* @0x119910 mov r4, #0 */
/* @0x119914 ldr r0, [r3, #0x10] */
/* @0x119918 mov r5, r4 */
/* @0x11991c mvn r9, #-16777216 */
/* @0x119920 add r3, r4, r4, lsl #1 */
/* @0x119924 add r3, r0, r3, lsl #2 */
/* @0x119928 add r4, r4, #1 */
/* @0x11992c mov r12, r3 */
/* @0x119930 cmp r4, r1 */
/* @0x119934 add r3, r3, #12 */
/* @0x119938 bgt 0x1199cc <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x11993c ldr r2, [r12, #0x8] */
/* @0x119940 cmp r2, #0 */
/* @0x119944 ble 0x119928 <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x119948 ldm r12, {r2, r3} */
/* @0x11994c ldr r3, [r3, #0xc] */
/* @0x119950 bic r3, r3, #-16777216 */
/* @0x119954 cmp r3, r9 */
/* @0x119958 beq 0x119920 <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x11995c add r2, r2, #99328 */
/* @0x119960 mvn r1, #0 */
/* @0x119964 add r2, r2, #672 */
/* @0x119968 mov r0, #0 */
/* @0x11996c bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0x119970 mov r1, r0 */
/* @0x119974 mov r0, sp */
/* @0x119978 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x11997c mov r0, r7 */
/* @0x119980 mov r1, sp */
/* @0x119984 mov r2, r5 */
/* @0x119988 bl 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i> */
/* @0x11998c ldr r3, [sp, #0xc] */
/* @0x119990 sub r3, r3, #1 */
/* @0x119994 bic r3, r3, #-16777216 */
/* @0x119998 bic r3, r3, #3 */
/* @0x11999c cmp r3, #0 */
/* @0x1199a0 beq 0x1199d4 <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x1199a4 ldr r3, [r8, #0x60] */
/* @0x1199a8 add r5, r5, #1 */
/* @0x1199ac ldr r1, [r3] */
/* @0x1199b0 ldr r0, [r3, #0x10] */
/* @0x1199b4 b 0x119920 <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x1199b8 mov r3, #2 */
/* @0x1199bc mov r0, r7 */
/* @0x1199c0 str r3, [r7, #0xc] */
/* @0x1199c4 bl 0xced9c <_Z14ARRAY_RefAllocPv> */
/* @0x1199c8 str r0, [r7] */
/* @0x1199cc add sp, sp, #20 */
/* @0x1199d0 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1199d4 mov r0, sp */
/* @0x1199d8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1199dc b 0x1199a4 <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x1199e0 mlaeq sp, r12, r3, r4 */

/* ── FUNC 0x1199e4 · F_DrawGetWindowsVertexBufferMethod(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x1199e4 mov r3, #0 */
/* @0x1199e8 str r3, [r0, #0xc] */
/* @0x1199ec str r3, [r0] */
/* @0x1199f0 str r3, [r0, #0x4] */
/* @0x1199f4 bx lr */

/* ── FUNC 0x1199f8 · F_DrawGetWindowsAlternateSync(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x1199f8 mov r3, #0 */
/* @0x1199fc str r3, [r0, #0xc] */
/* @0x119a00 str r3, [r0] */
/* @0x119a04 str r3, [r0, #0x4] */
/* @0x119a08 bx lr */

/* ── FUNC 0x119a0c · F_DrawSetWindowsVertexBufferMethod(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x119a0c mov r3, #0 */
/* @0x119a10 str r3, [r0, #0xc] */
/* @0x119a14 str r3, [r0] */
/* @0x119a18 str r3, [r0, #0x4] */
/* @0x119a1c bx lr */

/* ── FUNC 0x119a20 · F_DrawSetWindowsAlternateSync(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x119a20 mov r3, #0 */
/* @0x119a24 str r3, [r0, #0xc] */
/* @0x119a28 str r3, [r0] */
/* @0x119a2c str r3, [r0, #0x4] */
/* @0x119a30 bx lr */

/* ── FUNC 0x119a34 · F_DisplayGetTimingMethod(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x119a34 ldr r3, [pc, #0x28] */
/* @0x119a38 mov r2, #0 */
/* @0x119a3c str r2, [r0, #0xc] */
/* @0x119a40 ldr r3, [pc, r3] */
/* @0x119a44 ldrb r3, [r3] */
/* @0x119a48 cmp r3, r2 */
/* @0x119a4c strne r2, [r0] */
/* @0x119a50 streq r3, [r0] */
/* @0x119a54 movne r3, #0 */
/* @0x119a58 movtne r3, #0x3ff0 */
/* @0x119a5c str r3, [r0, #0x4] */
/* @0x119a60 bx lr */
/* @0x119a64 eoreq r4, sp, r0, ror r11 */

/* ── FUNC 0x119a68 · F_DisplayGetSleepMargin(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x119a68 ldr r3, [pc, #0x20] */
/* @0x119a6c mov r2, #0 */
/* @0x119a70 str r2, [r0, #0xc] */
/* @0x119a74 ldr r3, [pc, r3] */
/* @0x119a78 ldr r2, [r3] */
/* @0x119a7c vmov s15, r2 */
/* @0x119a80 vcvt.f64.u32 d7, s15 */
/* @0x119a84 vmov r2, r3, d7 */
/* @0x119a88 stm r0, {r2, r3} */
/* @0x119a8c bx lr */
/* @0x119a90 eoreq r4, sp, r0, asr #22 */

/* ── FUNC 0x119a94 · F_DrawGetSWFAAlevel(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x119a94 ldr r3, [pc, #0x1c] */
/* @0x119a98 mov r2, #0 */
/* @0x119a9c str r2, [r0, #0xc] */
/* @0x119aa0 ldr r3, [pc, r3] */
/* @0x119aa4 vldr s15, [r3] */
/* @0x119aa8 vcvt.f64.f32 d6, s15 */
/* @0x119aac vmov r2, r3, d6 */
/* @0x119ab0 stm r0, {r2, r3} */
/* @0x119ab4 bx lr */
/* @0x119ab8 eoreq r4, sp, r8, lsl r11 */

/* ── FUNC 0x119abc · F_WindowSetVisible(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x119abc bx lr */

/* ── FUNC 0x119ac0 · F_WindowGetVisible(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x119ac0 ldr r3, [pc, #0x28] */
/* @0x119ac4 mov r2, #0 */
/* @0x119ac8 str r2, [r0, #0xc] */
/* @0x119acc ldr r3, [pc, r3] */
/* @0x119ad0 ldrb r3, [r3] */
/* @0x119ad4 cmp r3, r2 */
/* @0x119ad8 movne r3, r2 */
/* @0x119adc moveq r2, r3 */
/* @0x119ae0 movtne r2, #0x3ff0 */
/* @0x119ae4 str r3, [r0] */
/* @0x119ae8 str r2, [r0, #0x4] */
/* @0x119aec bx lr */
/* @0x119af0 .word 0x002d4af0 */

/* ── FUNC 0x119af4 · F_WindowSetShowborder(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x119af4 bx lr */

/* ── FUNC 0x119af8 · F_WindowGetShowborder(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x119af8 mov r3, #0 */
/* @0x119afc str r3, [r0, #0xc] */
/* @0x119b00 str r3, [r0] */
/* @0x119b04 str r3, [r0, #0x4] */
/* @0x119b08 bx lr */

/* ── FUNC 0x119b0c · F_WindowSetShowicons(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x119b0c bx lr */

/* ── FUNC 0x119b10 · F_WindowGetShowicons(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x119b10 mov r3, #0 */
/* @0x119b14 str r3, [r0, #0xc] */
/* @0x119b18 str r3, [r0] */
/* @0x119b1c str r3, [r0, #0x4] */
/* @0x119b20 bx lr */

/* ── FUNC 0x119b24 · F_WindowSetStayontop(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x119b24 bx lr */
