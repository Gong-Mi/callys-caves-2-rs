/* libyoyo.so 覆盖卡组 0220
 * 函数 0x244f60..0x247648，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x244f60 · DateFromTime(double) · size=392 · insn=98 */
/* @0x244f60 push {r3, r4, r5, lr} */
/* @0x244f64 vpush {d8, d9} */
/* @0x244f68 mov r4, r0 */
/* @0x244f6c mov r5, r1 */
/* @0x244f70 bl 0x244c28 <_Z13DayWithinYeard> */
/* @0x244f74 vmov d8, r0, r1 */
/* @0x244f78 mov r0, r4 */
/* @0x244f7c mov r1, r5 */
/* @0x244f80 bl 0x244be8 <_Z10InLeapYeard> */
/* @0x244f84 vmov d9, r0, r1 */
/* @0x244f88 mov r0, r4 */
/* @0x244f8c mov r1, r5 */
/* @0x244f90 bl 0x244c68 <_Z13MonthFromTimed> */
/* @0x244f94 vmov d7, r0, r1 */
/* @0x244f98 vcvt.s32.f64 s15, d7 */
/* @0x244f9c vmov r0, s15 */
/* @0x244fa0 cmp r0, #10 */
/* @0x244fa4 addls pc, pc, r0, lsl #2 */
/* @0x244fa8 b 0x245088 <_Z12DateFromTimed+0x128> */
/* @0x244fac b 0x244ff0 <_Z12DateFromTimed+0x90> */
/* @0x244fb0 b 0x244ffc <_Z12DateFromTimed+0x9c> */
/* @0x244fb4 b 0x245008 <_Z12DateFromTimed+0xa8> */
/* @0x244fb8 b 0x245018 <_Z12DateFromTimed+0xb8> */
/* @0x244fbc b 0x245028 <_Z12DateFromTimed+0xc8> */
/* @0x244fc0 b 0x245038 <_Z12DateFromTimed+0xd8> */
/* @0x244fc4 b 0x245048 <_Z12DateFromTimed+0xe8> */
/* @0x244fc8 b 0x245058 <_Z12DateFromTimed+0xf8> */
/* @0x244fcc b 0x245068 <_Z12DateFromTimed+0x108> */
/* @0x244fd0 b 0x245078 <_Z12DateFromTimed+0x118> */
/* @0x244fd4 b 0x244fd8 <_Z12DateFromTimed+0x78> */
/* @0x244fd8 vldr d7, [pc, #184] */
/* @0x244fdc vsub.f64 d8, d8, d7 */
/* @0x244fe0 vsub.f64 d8, d8, d9 */
/* @0x244fe4 vmov r0, r1, d8 */
/* @0x244fe8 vpop {d8, d9} */
/* @0x244fec pop {r3, r4, r5, pc} */
/* @0x244ff0 vmov.f64 d7, #1.000000e+00 */
/* @0x244ff4 vadd.f64 d8, d8, d7 */
/* @0x244ff8 b 0x244fe4 <_Z12DateFromTimed+0x84> */
/* @0x244ffc vmov.f64 d7, #3.000000e+01 */
/* @0x245000 vsub.f64 d8, d8, d7 */
/* @0x245004 b 0x244fe4 <_Z12DateFromTimed+0x84> */
/* @0x245008 vldr d7, [pc, #144] */
/* @0x24500c vsub.f64 d8, d8, d7 */
/* @0x245010 vsub.f64 d8, d8, d9 */
/* @0x245014 b 0x244fe4 <_Z12DateFromTimed+0x84> */
/* @0x245018 vldr d7, [pc, #136] */
/* @0x24501c vsub.f64 d8, d8, d7 */
/* @0x245020 vsub.f64 d8, d8, d9 */
/* @0x245024 b 0x244fe4 <_Z12DateFromTimed+0x84> */
/* @0x245028 vldr d7, [pc, #128] */
/* @0x24502c vsub.f64 d8, d8, d7 */
/* @0x245030 vsub.f64 d8, d8, d9 */
/* @0x245034 b 0x244fe4 <_Z12DateFromTimed+0x84> */
/* @0x245038 vldr d7, [pc, #120] */
/* @0x24503c vsub.f64 d8, d8, d7 */
/* @0x245040 vsub.f64 d8, d8, d9 */
/* @0x245044 b 0x244fe4 <_Z12DateFromTimed+0x84> */
/* @0x245048 vldr d7, [pc, #112] */
/* @0x24504c vsub.f64 d8, d8, d7 */
/* @0x245050 vsub.f64 d8, d8, d9 */
/* @0x245054 b 0x244fe4 <_Z12DateFromTimed+0x84> */
/* @0x245058 vldr d7, [pc, #104] */
/* @0x24505c vsub.f64 d8, d8, d7 */
/* @0x245060 vsub.f64 d8, d8, d9 */
/* @0x245064 b 0x244fe4 <_Z12DateFromTimed+0x84> */
/* @0x245068 vldr d7, [pc, #96] */
/* @0x24506c vsub.f64 d8, d8, d7 */
/* @0x245070 vsub.f64 d8, d8, d9 */
/* @0x245074 b 0x244fe4 <_Z12DateFromTimed+0x84> */
/* @0x245078 vldr d7, [pc, #88] */
/* @0x24507c vsub.f64 d8, d8, d7 */
/* @0x245080 vsub.f64 d8, d8, d9 */
/* @0x245084 b 0x244fe4 <_Z12DateFromTimed+0x84> */
/* @0x245088 vldr d7, [pc, #80] */
/* @0x24508c vsub.f64 d8, d8, d7 */
/* @0x245090 vsub.f64 d8, d8, d9 */
/* @0x245094 b 0x244fe4 <_Z12DateFromTimed+0x84> */
/* @0x245098 andeq r0, r0, r0 */
/* @0x24509c rsbsmi pc, r2, r0 */
/* @0x2450a0 andeq r0, r0, r0 */
/* @0x2450a4 submi r0, sp, r0 */
/* @0x2450a8 andeq r0, r0, r0 */
/* @0x2450ac subsmi r4, r6, r0 */
/* @0x2450b0 andeq r0, r0, r0 */
/* @0x2450b4 subsmi r12, sp, r0 */
/* @0x2450b8 andeq r0, r0, r0 */
/* @0x2450bc rsbmi r12, r2, r0 */
/* @0x2450c0 andeq r0, r0, r0 */
/* @0x2450c4 rsbmi r8, r6, r0 */
/* @0x2450c8 andeq r0, r0, r0 */
/* @0x2450cc rsbmi r6, r10, r0 */
/* @0x2450d0 andeq r0, r0, r0 */
/* @0x2450d4 rsbmi r4, lr, r0 */
/* @0x2450d8 andeq r0, r0, r0 */
/* @0x2450dc rsbsmi r0, r1, r0 */
/* @0x2450e0 andeq r0, r0, r0 */
/* @0x2450e4 rsbsmi sp, r4, r0 */

/* ── FUNC 0x2450e8 · WeekDay(double) · size=44 · insn=11 */
/* @0x2450e8 push {r4, lr} */
/* @0x2450ec bl 0x2449d8 <_Z3Dayd> */
/* @0x2450f0 vmov.f64 d7, #4.000000e+00 */
/* @0x2450f4 mov r3, #0 */
/* @0x2450f8 mov r2, #0 */
/* @0x2450fc movt r3, #0x401c */
/* @0x245100 pop {r4, lr} */
/* @0x245104 vmov d6, r0, r1 */
/* @0x245108 vadd.f64 d6, d6, d7 */
/* @0x24510c vmov r0, r1, d6 */
/* @0x245110 b 0xb66ac <fmod@plt> */

/* ── FUNC 0x245114 · LocalTime(double) · size=4 · insn=1 */
/* @0x245114 bx lr */

/* ── FUNC 0x245118 · UTC(double) · size=4 · insn=1 */
/* @0x245118 bx lr */

/* ── FUNC 0x24511c · anon_24511c · size=0 · insn=1 */
/* @0x24511c andeq r0, r0, r0 */

/* ── FUNC 0x245120 · HourFromTime(double) · size=56 · insn=14 */
/* @0x245120 vmov d6, r0, r1 */
/* @0x245124 vldr d7, [pc, #36] */
/* @0x245128 push {r4, lr} */
/* @0x24512c vdiv.f64 d6, d6, d7 */
/* @0x245130 vmov r0, r1, d6 */
/* @0x245134 bl 0xb6598 <floor@plt> */
/* @0x245138 mov r3, #0 */
/* @0x24513c mov r2, #0 */
/* @0x245140 movt r3, #0x4038 */
/* @0x245144 pop {r4, lr} */
/* @0x245148 b 0xb66ac <fmod@plt> */
/* @0x24514c nop */
/* @0x245150 andeq r0, r0, r0 */
/* @0x245154 .word 0x414b7740 */

/* ── FUNC 0x245158 · MinFromTime(double) · size=56 · insn=14 */
/* @0x245158 vmov d6, r0, r1 */
/* @0x24515c vldr d7, [pc, #36] */
/* @0x245160 push {r4, lr} */
/* @0x245164 vdiv.f64 d6, d6, d7 */
/* @0x245168 vmov r0, r1, d6 */
/* @0x24516c bl 0xb6598 <floor@plt> */
/* @0x245170 mov r3, #0 */
/* @0x245174 mov r2, #0 */
/* @0x245178 movt r3, #0x404e */
/* @0x24517c pop {r4, lr} */
/* @0x245180 b 0xb66ac <fmod@plt> */
/* @0x245184 nop */
/* @0x245188 andeq r0, r0, r0 */
/* @0x24518c rscmi r4, sp, r0, lsl #24 */

/* ── FUNC 0x245190 · SecFromTime(double) · size=56 · insn=14 */
/* @0x245190 vmov d6, r0, r1 */
/* @0x245194 vldr d7, [pc, #36] */
/* @0x245198 push {r4, lr} */
/* @0x24519c vdiv.f64 d6, d6, d7 */
/* @0x2451a0 vmov r0, r1, d6 */
/* @0x2451a4 bl 0xb6598 <floor@plt> */
/* @0x2451a8 mov r3, #0 */
/* @0x2451ac mov r2, #0 */
/* @0x2451b0 movt r3, #0x404e */
/* @0x2451b4 pop {r4, lr} */
/* @0x2451b8 b 0xb66ac <fmod@plt> */
/* @0x2451bc nop */
/* @0x2451c0 andeq r0, r0, r0 */
/* @0x2451c4 addmi r4, pc, r0 */

/* ── FUNC 0x2451c8 · msFromTime(double) · size=16 · insn=4 */
/* @0x2451c8 mov r3, #16384 */
/* @0x2451cc mov r2, #0 */
/* @0x2451d0 movt r3, #0x408f */
/* @0x2451d4 b 0xb66ac <fmod@plt> */

/* ── FUNC 0x2451d8 · MakeTime(double, double, double, double) · size=228 · insn=57 */
/* @0x2451d8 push {r3, r4, r5, r6, r7, lr} */
/* @0x2451dc vpush {d8, d9, d10} */
/* @0x2451e0 mov r4, r2 */
/* @0x2451e4 mov r5, r3 */
/* @0x2451e8 mov r6, r0 */
/* @0x2451ec mov r7, r1 */
/* @0x2451f0 bl 0x24364c <_Z7myisinfd> */
/* @0x2451f4 cmp r0, #0 */
/* @0x2451f8 beq 0x245210 <_Z8MakeTimedddd+0x38> */
/* @0x2451fc ldr r3, [pc, #0xb4] */
/* @0x245200 ldr r3, [pc, r3] */
/* @0x245204 ldrd r0, r1, [r3] */
/* @0x245208 vpop {d8, d9, d10} */
/* @0x24520c pop {r3, r4, r5, r6, r7, pc} */
/* @0x245210 mov r0, r4 */
/* @0x245214 mov r1, r5 */
/* @0x245218 bl 0x24364c <_Z7myisinfd> */
/* @0x24521c cmp r0, #0 */
/* @0x245220 bne 0x2451fc <_Z8MakeTimedddd+0x24> */
/* @0x245224 ldrd r0, r1, [sp, #48] */
/* @0x245228 bl 0x24364c <_Z7myisinfd> */
/* @0x24522c cmp r0, #0 */
/* @0x245230 bne 0x2451fc <_Z8MakeTimedddd+0x24> */
/* @0x245234 ldrd r0, r1, [sp, #56] */
/* @0x245238 bl 0x24364c <_Z7myisinfd> */
/* @0x24523c cmp r0, #0 */
/* @0x245240 bne 0x2451fc <_Z8MakeTimedddd+0x24> */
/* @0x245244 mov r0, r6 */
/* @0x245248 mov r1, r7 */
/* @0x24524c bl 0xb6598 <floor@plt> */
/* @0x245250 vmov d9, r0, r1 */
/* @0x245254 mov r0, r4 */
/* @0x245258 mov r1, r5 */
/* @0x24525c bl 0xb6598 <floor@plt> */
/* @0x245260 vmov d10, r0, r1 */
/* @0x245264 ldrd r0, r1, [sp, #48] */
/* @0x245268 bl 0xb6598 <floor@plt> */
/* @0x24526c vmov d8, r0, r1 */
/* @0x245270 ldrd r0, r1, [sp, #56] */
/* @0x245274 bl 0xb6598 <floor@plt> */
/* @0x245278 vldr d7, [pc, #32] */
/* @0x24527c vmul.f64 d7, d10, d7 */
/* @0x245280 vldr d5, [pc, #32] */
/* @0x245284 vldr d6, [pc, #36] */
/* @0x245288 vmla.f64 d7, d9, d5 */
/* @0x24528c vmla.f64 d7, d8, d6 */
/* @0x245290 vmov d6, r0, r1 */
/* @0x245294 vadd.f64 d6, d6, d7 */
/* @0x245298 vmov r0, r1, d6 */
/* @0x24529c b 0x245208 <_Z8MakeTimedddd+0x30> */
/* @0x2452a0 andeq r0, r0, r0 */
/* @0x2452a4 rscmi r4, sp, r0, lsl #24 */
/* @0x2452a8 andeq r0, r0, r0 */
/* @0x2452ac .word 0x414b7740 */
/* @0x2452b0 andeq r0, r0, r0 */
/* @0x2452b4 addmi r4, pc, r0 */
/* @0x2452b8 andseq r12, r10, r8, lsr #10 */

/* ── FUNC 0x2452bc · anon_2452bc · size=0 · insn=1 */
/* @0x2452bc nop */

/* ── FUNC 0x2452c0 · CalcTimeFromYear(double) · size=176 · insn=42 */
/* @0x2452c0 push {r3, lr} */
/* @0x2452c4 vpush {d8, d9, d10, d11} */
/* @0x2452c8 bl 0xb6598 <floor@plt> */
/* @0x2452cc vldr d11, [pc, #132] */
/* @0x2452d0 vmov d8, r0, r1 */
/* @0x2452d4 vcmp.f64 d8, d11 */
/* @0x2452d8 vmrs APSR_nzcv, fpscr */
/* @0x2452dc beq 0x245344 <_Z16CalcTimeFromYeard+0x84> */
/* @0x2452e0 vmov.f64 d7, #-1.000000e+00 */
/* @0x2452e4 vmov r0, r1, d11 */
/* @0x2452e8 vmov.f64 d10, #1.000000e+00 */
/* @0x2452ec vcmpe.f64 d8, d11 */
/* @0x2452f0 vmrs APSR_nzcv, fpscr */
/* @0x2452f4 vmovpl.f64 d10, d7 */
/* @0x2452f8 bl 0x244aa8 <_Z11DayFromYeard> */
/* @0x2452fc vadd.f64 d8, d10, d8 */
/* @0x245300 vcmp.f64 d8, d11 */
/* @0x245304 vmrs APSR_nzcv, fpscr */
/* @0x245308 vmov d9, r0, r1 */
/* @0x24530c beq 0x245330 <_Z16CalcTimeFromYeard+0x70> */
/* @0x245310 vmov r0, r1, d8 */
/* @0x245314 bl 0x244aa8 <_Z11DayFromYeard> */
/* @0x245318 vadd.f64 d8, d8, d10 */
/* @0x24531c vcmp.f64 d8, d11 */
/* @0x245320 vmrs APSR_nzcv, fpscr */
/* @0x245324 vmov d7, r0, r1 */
/* @0x245328 vadd.f64 d9, d9, d7 */
/* @0x24532c bne 0x245310 <_Z16CalcTimeFromYeard+0x50> */
/* @0x245330 vldr d7, [pc, #40] */
/* @0x245334 vmul.f64 d9, d9, d7 */
/* @0x245338 vmov r0, r1, d9 */
/* @0x24533c vpop {d8, d9, d10, d11} */
/* @0x245340 pop {r3, pc} */
/* @0x245344 vldr d9, [pc, #28] */
/* @0x245348 vmov r0, r1, d9 */
/* @0x24534c vpop {d8, d9, d10, d11} */
/* @0x245350 pop {r3, pc} */
/* @0x245354 nop */
/* @0x245358 andeq r0, r0, r0 */
/* @0x24535c addsmi r12, lr, r0, lsl #16 */
/* @0x245360 andeq r0, r0, r0 */
/* @0x245364 orrsmi r9, r4, r0, ror r9 */

/* ── FUNC 0x245370 · MakeDay(double, double, double) · size=268 · insn=67 */
/* @0x245370 push {r3, r4, r5, r6, r7, lr} */
/* @0x245374 vpush {d8, d9, d10} */
/* @0x245378 mov r4, r2 */
/* @0x24537c mov r5, r3 */
/* @0x245380 mov r6, r0 */
/* @0x245384 mov r7, r1 */
/* @0x245388 bl 0x24364c <_Z7myisinfd> */
/* @0x24538c cmp r0, #0 */
/* @0x245390 beq 0x2453a8 <_Z7MakeDayddd+0x38> */
/* @0x245394 ldr r3, [pc, #0xd8] */
/* @0x245398 ldr r3, [pc, r3] */
/* @0x24539c ldrd r0, r1, [r3] */
/* @0x2453a0 vpop {d8, d9, d10} */
/* @0x2453a4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2453a8 mov r0, r4 */
/* @0x2453ac mov r1, r5 */
/* @0x2453b0 bl 0x24364c <_Z7myisinfd> */
/* @0x2453b4 cmp r0, #0 */
/* @0x2453b8 bne 0x245394 <_Z7MakeDayddd+0x24> */
/* @0x2453bc ldrd r0, r1, [sp, #48] */
/* @0x2453c0 bl 0x24364c <_Z7myisinfd> */
/* @0x2453c4 cmp r0, #0 */
/* @0x2453c8 bne 0x245394 <_Z7MakeDayddd+0x24> */
/* @0x2453cc mov r0, r6 */
/* @0x2453d0 mov r1, r7 */
/* @0x2453d4 bl 0xb6598 <floor@plt> */
/* @0x2453d8 vmov d10, r0, r1 */
/* @0x2453dc mov r0, r4 */
/* @0x2453e0 mov r1, r5 */
/* @0x2453e4 bl 0xb6598 <floor@plt> */
/* @0x2453e8 vmov d8, r0, r1 */
/* @0x2453ec ldrd r0, r1, [sp, #48] */
/* @0x2453f0 bl 0xb6598 <floor@plt> */
/* @0x2453f4 vmov.f64 d7, #1.200000e+01 */
/* @0x2453f8 vdiv.f64 d6, d8, d7 */
/* @0x2453fc vmov d9, r0, r1 */
/* @0x245400 vmov r0, r1, d6 */
/* @0x245404 bl 0xb6598 <floor@plt> */
/* @0x245408 vmov d7, r0, r1 */
/* @0x24540c vadd.f64 d7, d10, d7 */
/* @0x245410 vmov r0, r1, d7 */
/* @0x245414 bl 0x2452c0 <_Z16CalcTimeFromYeard> */
/* @0x245418 movw r12, #0xaaab */
/* @0x24541c vcvt.s32.f64 s15, d8 */
/* @0x245420 movt r12, #0x2aaa */
/* @0x245424 ldr r3, [pc, #0x4c] */
/* @0x245428 ldr r3, [pc, r3] */
/* @0x24542c vmov r2, s15 */
/* @0x245430 smull lr, r12, r12, r2 */
/* @0x245434 asr lr, r2, #31 */
/* @0x245438 vmov d6, r0, r1 */
/* @0x24543c rsb r12, lr, r12, asr #1 */
/* @0x245440 add r12, r12, r12, lsl #1 */
/* @0x245444 sub r2, r2, r12, lsl #2 */
/* @0x245448 add r3, r3, r2, lsl #3 */
/* @0x24544c vldr d7, [r3] */
/* @0x245450 vadd.f64 d6, d6, d7 */
/* @0x245454 vmov r0, r1, d6 */
/* @0x245458 bl 0x2449d8 <_Z3Dayd> */
/* @0x24545c vmov.f64 d7, #1.000000e+00 */
/* @0x245460 vmov d6, r0, r1 */
/* @0x245464 vadd.f64 d9, d9, d6 */
/* @0x245468 vsub.f64 d6, d9, d7 */
/* @0x24546c vmov r0, r1, d6 */
/* @0x245470 b 0x2453a0 <_Z7MakeDayddd+0x30> */
/* @0x245474 mulseq r10, r0, r3 */
/* @0x245478 andseq r12, r10, r4, lsl #6 */

/* ── FUNC 0x24547c · anon_24547c · size=0 · insn=1 */
/* @0x24547c andeq r0, r0, r0 */

/* ── FUNC 0x245480 · MakeDate(double, double) · size=108 · insn=27 */
/* @0x245480 push {r3, r4, r5, lr} */
/* @0x245484 vpush {d8} */
/* @0x245488 mov r4, r2 */
/* @0x24548c mov r5, r3 */
/* @0x245490 vmov d8, r0, r1 */
/* @0x245494 bl 0x24364c <_Z7myisinfd> */
/* @0x245498 cmp r0, #0 */
/* @0x24549c beq 0x2454b4 <_Z8MakeDatedd+0x34> */
/* @0x2454a0 vpop {d8} */
/* @0x2454a4 ldr r3, [pc, #0x3c] */
/* @0x2454a8 ldr r3, [pc, r3] */
/* @0x2454ac ldrd r0, r1, [r3] */
/* @0x2454b0 pop {r3, r4, r5, pc} */
/* @0x2454b4 mov r0, r4 */
/* @0x2454b8 mov r1, r5 */
/* @0x2454bc bl 0x24364c <_Z7myisinfd> */
/* @0x2454c0 cmp r0, #0 */
/* @0x2454c4 bne 0x2454a0 <_Z8MakeDatedd+0x20> */
/* @0x2454c8 vmov d6, r4, r5 */
/* @0x2454cc vldr d7, [pc, #12] */
/* @0x2454d0 vmla.f64 d6, d8, d7 */
/* @0x2454d4 vpop {d8} */
/* @0x2454d8 vmov r0, r1, d6 */
/* @0x2454dc pop {r3, r4, r5, pc} */
/* @0x2454e0 andeq r0, r0, r0 */
/* @0x2454e4 orrsmi r9, r4, r0, ror r9 */
/* @0x2454e8 andseq r12, r10, r0, lsl #5 */

/* ── FUNC 0x2454ec · anon_2454ec · size=0 · insn=1 */
/* @0x2454ec nop */

/* ── FUNC 0x2454f0 · JS_Date_parse(RValue&, CInstance*, CInstance*, int, RValue*) · size=2436 · insn=609 */
/* @0x2454f0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2454f4 vpush {d8, d9, d10, d11} */
/* @0x2454f8 sub sp, sp, #24 */
/* @0x2454fc mov r1, #0 */
/* @0x245500 mov r6, r0 */
/* @0x245504 ldr r0, [sp, #0x58] */
/* @0x245508 add r4, sp, #24 */
/* @0x24550c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x245510 ldr r5, [pc, #0x4cc] */
/* @0x245514 str r0, [r4, #-0x4]! */
/* @0x245518 mov r0, r4 */
/* @0x24551c bl 0x10fb38 <utf8_extract_char> */
/* @0x245520 mov r8, r0 */
/* @0x245524 mov r0, r4 */
/* @0x245528 bl 0x10fb38 <utf8_extract_char> */
/* @0x24552c mov r9, r0 */
/* @0x245530 mov r0, r4 */
/* @0x245534 bl 0x10fb38 <utf8_extract_char> */
/* @0x245538 mov r10, r0 */
/* @0x24553c mov r0, r4 */
/* @0x245540 bl 0x10fb38 <utf8_extract_char> */
/* @0x245544 ldr r5, [pc, r5] */
/* @0x245548 ldr r3, [r5] */
/* @0x24554c uxtab r2, r3, r8 */
/* @0x245550 ldrb r7, [r2, #0x1] */
/* @0x245554 and r7, r7, #4 */
/* @0x245558 ands r7, r7, #255 */
/* @0x24555c beq 0x245610 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x245560 uxtab r2, r3, r9 */
/* @0x245564 ldrb r7, [r2, #0x1] */
/* @0x245568 and r7, r7, #4 */
/* @0x24556c ands r7, r7, #255 */
/* @0x245570 beq 0x245610 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x245574 uxtab r2, r3, r10 */
/* @0x245578 ldrb r7, [r2, #0x1] */
/* @0x24557c and r7, r7, #4 */
/* @0x245580 ands r7, r7, #255 */
/* @0x245584 beq 0x245610 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x245588 uxtab r3, r3, r0 */
/* @0x24558c ldrb r7, [r3, #0x1] */
/* @0x245590 and r7, r7, #4 */
/* @0x245594 ands r7, r7, #255 */
/* @0x245598 beq 0x2456e0 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x1f0> */
/* @0x24559c sub r9, r9, #48 */
/* @0x2455a0 mov r2, #100 */
/* @0x2455a4 sub r8, r8, #48 */
/* @0x2455a8 mov r3, #1000 */
/* @0x2455ac mul r9, r2, r9 */
/* @0x2455b0 sub r10, r10, #48 */
/* @0x2455b4 mla r8, r3, r8, r9 */
/* @0x2455b8 add r10, r10, r10, lsl #2 */
/* @0x2455bc sub r3, r0, #48 */
/* @0x2455c0 mov r0, r4 */
/* @0x2455c4 add r10, r8, r10, lsl #1 */
/* @0x2455c8 add r3, r10, r3 */
/* @0x2455cc vmov s22, r3 */
/* @0x2455d0 bl 0x10fb38 <utf8_extract_char> */
/* @0x2455d4 cmp r0, #45 */
/* @0x2455d8 beq 0x245714 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x224> */
/* @0x2455dc vcvt.f64.s32 d5, s22 */
/* @0x2455e0 mov r7, #0 */
/* @0x2455e4 vmov r0, r1, d5 */
/* @0x2455e8 vmov s18, r7 */
/* @0x2455ec mov r2, #0 */
/* @0x2455f0 vmov s16, r7 */
/* @0x2455f4 mov r3, #0 */
/* @0x2455f8 vmov s17, r7 */
/* @0x2455fc vldr s19, [pc, #996] */
/* @0x245600 vmov s20, r7 */
/* @0x245604 vmov s21, r7 */
/* @0x245608 vmov.f64 d4, #1.000000e+00 */
/* @0x24560c b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x245610 vmov.f64 d4, #1.000000e+00 */
/* @0x245614 mov r1, #51200 */
/* @0x245618 vmov s18, r7 */
/* @0x24561c movt r1, #0x409e */
/* @0x245620 vmov s16, r7 */
/* @0x245624 mov r2, #0 */
/* @0x245628 vmov s17, r7 */
/* @0x24562c mov r3, #0 */
/* @0x245630 vmov s20, r7 */
/* @0x245634 mov r0, #0 */
/* @0x245638 vmov s21, r7 */
/* @0x24563c vldr s19, [pc, #932] */
/* @0x245640 vstr d4, [sp] */
/* @0x245644 bl 0x245370 <_Z7MakeDayddd> */
/* @0x245648 vcvt.f64.s32 d5, s17 */
/* @0x24564c vcvt.f64.s32 d6, s16 */
/* @0x245650 vstr d5, [sp] */
/* @0x245654 vstr d6, [sp, #8] */
/* @0x245658 vcvt.f64.s32 d5, s21 */
/* @0x24565c vcvt.f64.s32 d6, s20 */
/* @0x245660 vmov r2, r3, d6 */
/* @0x245664 mov r4, r0 */
/* @0x245668 mov r5, r1 */
/* @0x24566c vmov r0, r1, d5 */
/* @0x245670 bl 0x2451d8 <_Z8MakeTimedddd> */
/* @0x245674 mov r2, r0 */
/* @0x245678 mov r3, r1 */
/* @0x24567c mov r0, r4 */
/* @0x245680 mov r1, r5 */
/* @0x245684 bl 0x245480 <_Z8MakeDatedd> */
/* @0x245688 vmov s11, r7 */
/* @0x24568c vcvt.f64.s32 d7, s18 */
/* @0x245690 mov r4, #0 */
/* @0x245694 mov r5, #0 */
/* @0x245698 strd r4, r5, [sp] */
/* @0x24569c strd r4, r5, [sp, #8] */
/* @0x2456a0 vcvt.f64.s32 d5, s11 */
/* @0x2456a4 vmov r2, r3, d5 */
/* @0x2456a8 vmov d8, r0, r1 */
/* @0x2456ac vmov r0, r1, d7 */
/* @0x2456b0 bl 0x2451d8 <_Z8MakeTimedddd> */
/* @0x2456b4 mov r3, #0 */
/* @0x2456b8 vcvt.f64.s32 d7, s19 */
/* @0x2456bc str r3, [r6, #0xc] */
/* @0x2456c0 vmov.f64 d6, d8 */
/* @0x2456c4 vmov d5, r0, r1 */
/* @0x2456c8 vmla.f64 d6, d7, d5 */
/* @0x2456cc vmov r2, r3, d6 */
/* @0x2456d0 stm r6, {r2, r3} */
/* @0x2456d4 add sp, sp, #24 */
/* @0x2456d8 vpop {d8, d9, d10, d11} */
/* @0x2456dc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2456e0 mov r1, #51200 */
/* @0x2456e4 vmov.f64 d4, #1.000000e+00 */
/* @0x2456e8 vmov s18, r7 */
/* @0x2456ec vldr s19, [pc, #756] */
/* @0x2456f0 vmov s16, r7 */
/* @0x2456f4 mov r2, #0 */
/* @0x2456f8 vmov s17, r7 */
/* @0x2456fc mov r3, #0 */
/* @0x245700 vmov s20, r7 */
/* @0x245704 mov r0, #0 */
/* @0x245708 vmov s21, r7 */
/* @0x24570c movt r1, #0x409e */
/* @0x245710 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x245714 mov r0, r4 */
/* @0x245718 bl 0x10fb38 <utf8_extract_char> */
/* @0x24571c mov r8, r0 */
/* @0x245720 mov r0, r4 */
/* @0x245724 bl 0x10fb38 <utf8_extract_char> */
/* @0x245728 ldr r3, [r5] */
/* @0x24572c uxtab r2, r3, r8 */
/* @0x245730 ldrb r7, [r2, #0x1] */
/* @0x245734 and r7, r7, #4 */
/* @0x245738 ands r7, r7, #255 */
/* @0x24573c beq 0x2457bc <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x2cc> */
/* @0x245740 uxtab r3, r3, r0 */
/* @0x245744 ldrb r3, [r3, #0x1] */
/* @0x245748 and r3, r3, #4 */
/* @0x24574c ands r7, r3, #255 */
/* @0x245750 beq 0x2457b0 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x2c0> */
/* @0x245754 sub r8, r8, #48 */
/* @0x245758 sub r3, r0, #48 */
/* @0x24575c mov r0, r4 */
/* @0x245760 add r8, r8, r8, lsl #2 */
/* @0x245764 add r8, r3, r8, lsl #1 */
/* @0x245768 bl 0x10fb38 <utf8_extract_char> */
/* @0x24576c cmp r0, #45 */
/* @0x245770 beq 0x2457c8 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x2d8> */
/* @0x245774 sub r2, r8, #1 */
/* @0x245778 vcvt.f64.s32 d6, s22 */
/* @0x24577c mov r7, #0 */
/* @0x245780 vldr s19, [pc, #608] */
/* @0x245784 vmov s11, r2 */
/* @0x245788 vmov s18, r7 */
/* @0x24578c vmov s16, r7 */
/* @0x245790 vmov s17, r7 */
/* @0x245794 vmov s20, r7 */
/* @0x245798 vcvt.f64.s32 d5, s11 */
/* @0x24579c vmov s21, r7 */
/* @0x2457a0 vmov r0, r1, d6 */
/* @0x2457a4 vmov r2, r3, d5 */
/* @0x2457a8 vmov.f64 d4, #1.000000e+00 */
/* @0x2457ac b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x2457b0 vcvt.f64.s32 d7, s22 */
/* @0x2457b4 vmov r0, r1, d7 */
/* @0x2457b8 b 0x2455e8 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x2457bc vcvt.f64.s32 d6, s22 */
/* @0x2457c0 vmov r0, r1, d6 */
/* @0x2457c4 b 0x2455e8 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x2457c8 mov r0, r4 */
/* @0x2457cc bl 0x10fb38 <utf8_extract_char> */
/* @0x2457d0 mov r9, r0 */
/* @0x2457d4 mov r0, r4 */
/* @0x2457d8 bl 0x10fb38 <utf8_extract_char> */
/* @0x2457dc ldr r3, [r5] */
/* @0x2457e0 uxtab r2, r3, r9 */
/* @0x2457e4 ldrb r2, [r2, #0x1] */
/* @0x2457e8 and r2, r2, #4 */
/* @0x2457ec ands r7, r2, #255 */
/* @0x2457f0 beq 0x2458a0 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x3b0> */
/* @0x2457f4 uxtab r3, r3, r0 */
/* @0x2457f8 ldrb r3, [r3, #0x1] */
/* @0x2457fc tst r3, #4 */
/* @0x245800 beq 0x245864 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x245804 sub r2, r9, #48 */
/* @0x245808 sub r3, r0, #48 */
/* @0x24580c mov r9, #10 */
/* @0x245810 mov r0, r4 */
/* @0x245814 mla r3, r9, r2, r3 */
/* @0x245818 vmov s23, r3 */
/* @0x24581c bl 0x10fb38 <utf8_extract_char> */
/* @0x245820 cmp r0, #84 */
/* @0x245824 beq 0x2458d8 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x3e8> */
/* @0x245828 sub r2, r8, #1 */
/* @0x24582c vcvt.f64.s32 d6, s22 */
/* @0x245830 mov r7, #0 */
/* @0x245834 vldr s19, [pc, #428] */
/* @0x245838 vmov s11, r2 */
/* @0x24583c vmov s18, r7 */
/* @0x245840 vmov s16, r7 */
/* @0x245844 vmov s17, r7 */
/* @0x245848 vmov s20, r7 */
/* @0x24584c vcvt.f64.s32 d5, s11 */
/* @0x245850 vmov s21, r7 */
/* @0x245854 vmov r0, r1, d6 */
/* @0x245858 vmov r2, r3, d5 */
/* @0x24585c vcvt.f64.s32 d4, s23 */
/* @0x245860 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x245864 sub r2, r8, #1 */
/* @0x245868 vcvt.f64.s32 d7, s22 */
/* @0x24586c mov r7, #0 */
/* @0x245870 vldr s19, [pc, #368] */
/* @0x245874 vmov s13, r2 */
/* @0x245878 vmov s18, r7 */
/* @0x24587c vmov s16, r7 */
/* @0x245880 vmov s17, r7 */
/* @0x245884 vmov s20, r7 */
/* @0x245888 vcvt.f64.s32 d6, s13 */
/* @0x24588c vmov s21, r7 */
/* @0x245890 vmov r0, r1, d7 */
/* @0x245894 vmov r2, r3, d6 */
/* @0x245898 vmov.f64 d4, #1.000000e+00 */
/* @0x24589c b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x2458a0 sub r2, r8, #1 */
/* @0x2458a4 vcvt.f64.s32 d5, s22 */
/* @0x2458a8 vmov s18, r7 */
/* @0x2458ac vldr s19, [pc, #308] */
/* @0x2458b0 vmov s15, r2 */
/* @0x2458b4 vmov s16, r7 */
/* @0x2458b8 vmov s17, r7 */
/* @0x2458bc vmov s20, r7 */
/* @0x2458c0 vmov s21, r7 */
/* @0x2458c4 vcvt.f64.s32 d7, s15 */
/* @0x2458c8 vmov r0, r1, d5 */
/* @0x2458cc vmov r2, r3, d7 */
/* @0x2458d0 vmov.f64 d4, #1.000000e+00 */
/* @0x2458d4 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x2458d8 mov r0, r4 */
/* @0x2458dc bl 0x10fb38 <utf8_extract_char> */
/* @0x2458e0 mov r10, r0 */
/* @0x2458e4 mov r0, r4 */
/* @0x2458e8 bl 0x10fb38 <utf8_extract_char> */
/* @0x2458ec ldr r3, [r5] */
/* @0x2458f0 uxtab r2, r3, r10 */
/* @0x2458f4 ldrb r2, [r2, #0x1] */
/* @0x2458f8 and r2, r2, #4 */
/* @0x2458fc ands r7, r2, #255 */
/* @0x245900 beq 0x245954 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x464> */
/* @0x245904 uxtab r3, r3, r0 */
/* @0x245908 ldrb r3, [r3, #0x1] */
/* @0x24590c and r3, r3, #4 */
/* @0x245910 ands r3, r3, #255 */
/* @0x245914 bne 0x24598c <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x49c> */
/* @0x245918 sub r2, r8, #1 */
/* @0x24591c vcvt.f64.s32 d7, s22 */
/* @0x245920 mov r7, r3 */
/* @0x245924 vmov s18, r3 */
/* @0x245928 vmov s13, r2 */
/* @0x24592c vldr s19, [pc, #180] */
/* @0x245930 vmov s16, r3 */
/* @0x245934 vmov s17, r7 */
/* @0x245938 vmov s20, r7 */
/* @0x24593c vmov s21, r7 */
/* @0x245940 vcvt.f64.s32 d6, s13 */
/* @0x245944 vmov r0, r1, d7 */
/* @0x245948 vmov r2, r3, d6 */
/* @0x24594c vcvt.f64.s32 d4, s23 */
/* @0x245950 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x245954 sub r2, r8, #1 */
/* @0x245958 vcvt.f64.s32 d5, s22 */
/* @0x24595c vmov s18, r7 */
/* @0x245960 vldr s19, [pc, #128] */
/* @0x245964 vmov s15, r2 */
/* @0x245968 vmov s16, r7 */
/* @0x24596c vmov s17, r7 */
/* @0x245970 vmov s20, r7 */
/* @0x245974 vmov s21, r7 */
/* @0x245978 vcvt.f64.s32 d7, s15 */
/* @0x24597c vmov r0, r1, d5 */
/* @0x245980 vmov r2, r3, d7 */
/* @0x245984 vcvt.f64.s32 d4, s23 */
/* @0x245988 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x24598c sub r3, r0, #48 */
/* @0x245990 sub r10, r10, #48 */
/* @0x245994 mov r0, r4 */
/* @0x245998 mla r3, r9, r10, r3 */
/* @0x24599c vmov s21, r3 */
/* @0x2459a0 bl 0x10fb38 <utf8_extract_char> */
/* @0x2459a4 cmp r0, #58 */
/* @0x2459a8 beq 0x2459ec <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x4fc> */
/* @0x2459ac sub r2, r8, #1 */
/* @0x2459b0 vcvt.f64.s32 d6, s22 */
/* @0x2459b4 mov r7, #0 */
/* @0x2459b8 vldr s19, [pc, #40] */
/* @0x2459bc vmov s11, r2 */
/* @0x2459c0 vmov s18, r7 */
/* @0x2459c4 vmov s16, r7 */
/* @0x2459c8 vmov s17, r7 */
/* @0x2459cc vmov s20, r7 */
/* @0x2459d0 vcvt.f64.s32 d5, s11 */
/* @0x2459d4 vmov r0, r1, d6 */
/* @0x2459d8 vmov r2, r3, d5 */
/* @0x2459dc vcvt.f64.s32 d4, s23 */
/* @0x2459e0 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x2459e4 andseq r8, r10, r12, lsr r4 */
/* @0x2459e8 andeq r0, r0, r1 */
/* @0x2459ec mov r0, r4 */
/* @0x2459f0 bl 0x10fb38 <utf8_extract_char> */
/* @0x2459f4 mov r10, r0 */
/* @0x2459f8 mov r0, r4 */
/* @0x2459fc bl 0x10fb38 <utf8_extract_char> */
/* @0x245a00 ldr r3, [r5] */
/* @0x245a04 uxtab r2, r3, r10 */
/* @0x245a08 ldrb r2, [r2, #0x1] */
/* @0x245a0c and r2, r2, #4 */
/* @0x245a10 ands r7, r2, #255 */
/* @0x245a14 beq 0x245a64 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x574> */
/* @0x245a18 uxtab r3, r3, r0 */
/* @0x245a1c ldrb r3, [r3, #0x1] */
/* @0x245a20 and r3, r3, #4 */
/* @0x245a24 ands r3, r3, #255 */
/* @0x245a28 bne 0x245a98 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x5a8> */
/* @0x245a2c sub r2, r8, #1 */
/* @0x245a30 vcvt.f64.s32 d7, s22 */
/* @0x245a34 mov r7, r3 */
/* @0x245a38 vmov s18, r3 */
/* @0x245a3c vmov s13, r2 */
/* @0x245a40 vldr s19, [pc, #-96] */
/* @0x245a44 vmov s16, r3 */
/* @0x245a48 vmov s17, r7 */
/* @0x245a4c vmov s20, r7 */
/* @0x245a50 vcvt.f64.s32 d6, s13 */
/* @0x245a54 vmov r0, r1, d7 */
/* @0x245a58 vmov r2, r3, d6 */
/* @0x245a5c vcvt.f64.s32 d4, s23 */
/* @0x245a60 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x245a64 sub r2, r8, #1 */
/* @0x245a68 vcvt.f64.s32 d5, s22 */
/* @0x245a6c vmov s18, r7 */
/* @0x245a70 vldr s19, [pc, #-144] */
/* @0x245a74 vmov s15, r2 */
/* @0x245a78 vmov s16, r7 */
/* @0x245a7c vmov s17, r7 */
/* @0x245a80 vmov s20, r7 */
/* @0x245a84 vcvt.f64.s32 d7, s15 */
/* @0x245a88 vmov r0, r1, d5 */
/* @0x245a8c vmov r2, r3, d7 */
/* @0x245a90 vcvt.f64.s32 d4, s23 */
/* @0x245a94 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x245a98 sub r3, r0, #48 */
/* @0x245a9c sub r10, r10, #48 */
/* @0x245aa0 mov r0, r4 */
/* @0x245aa4 mla r3, r9, r10, r3 */
/* @0x245aa8 vmov s20, r3 */
/* @0x245aac bl 0x10fb38 <utf8_extract_char> */
/* @0x245ab0 cmp r0, #58 */
/* @0x245ab4 beq 0x245aec <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x5fc> */
/* @0x245ab8 sub r2, r8, #1 */
/* @0x245abc vcvt.f64.s32 d6, s22 */
/* @0x245ac0 mov r7, #0 */
/* @0x245ac4 vldr s19, [pc, #-228] */
/* @0x245ac8 vmov s11, r2 */
/* @0x245acc vmov s18, r7 */
/* @0x245ad0 vmov s16, r7 */
/* @0x245ad4 vmov s17, r7 */
/* @0x245ad8 vcvt.f64.s32 d5, s11 */
/* @0x245adc vmov r0, r1, d6 */
/* @0x245ae0 vmov r2, r3, d5 */
/* @0x245ae4 vcvt.f64.s32 d4, s23 */
/* @0x245ae8 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x245aec mov r0, r4 */
/* @0x245af0 bl 0x10fb38 <utf8_extract_char> */
/* @0x245af4 mov r10, r0 */
/* @0x245af8 mov r0, r4 */
/* @0x245afc bl 0x10fb38 <utf8_extract_char> */
/* @0x245b00 ldr r3, [r5] */
/* @0x245b04 uxtab r2, r3, r10 */
/* @0x245b08 ldrb r2, [r2, #0x1] */
/* @0x245b0c and r2, r2, #4 */
/* @0x245b10 ands r7, r2, #255 */
/* @0x245b14 beq 0x245b60 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x670> */
/* @0x245b18 uxtab r3, r3, r0 */
/* @0x245b1c ldrb r3, [r3, #0x1] */
/* @0x245b20 and r3, r3, #4 */
/* @0x245b24 ands r3, r3, #255 */
/* @0x245b28 bne 0x245b90 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x6a0> */
/* @0x245b2c sub r2, r8, #1 */
/* @0x245b30 vcvt.f64.s32 d7, s22 */
/* @0x245b34 mov r7, r3 */
/* @0x245b38 vmov s18, r3 */
/* @0x245b3c vmov s13, r2 */
/* @0x245b40 vldr s19, [pc, #-352] */
/* @0x245b44 vmov s16, r3 */
/* @0x245b48 vmov s17, r7 */
/* @0x245b4c vcvt.f64.s32 d6, s13 */
/* @0x245b50 vmov r0, r1, d7 */
/* @0x245b54 vmov r2, r3, d6 */
/* @0x245b58 vcvt.f64.s32 d4, s23 */
/* @0x245b5c b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x245b60 sub r2, r8, #1 */
/* @0x245b64 vcvt.f64.s32 d5, s22 */
/* @0x245b68 vmov s18, r7 */
/* @0x245b6c vldr s19, [pc, #-396] */
/* @0x245b70 vmov s15, r2 */
/* @0x245b74 vmov s16, r7 */
/* @0x245b78 vmov s17, r7 */
/* @0x245b7c vcvt.f64.s32 d7, s15 */
/* @0x245b80 vmov r0, r1, d5 */
/* @0x245b84 vmov r2, r3, d7 */
/* @0x245b88 vcvt.f64.s32 d4, s23 */
/* @0x245b8c b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x245b90 sub r3, r0, #48 */
/* @0x245b94 sub r10, r10, #48 */
/* @0x245b98 mov r0, r4 */
/* @0x245b9c mla r3, r9, r10, r3 */
/* @0x245ba0 vmov s17, r3 */
/* @0x245ba4 bl 0x10fb38 <utf8_extract_char> */
/* @0x245ba8 cmp r0, #58 */
/* @0x245bac beq 0x245be0 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x6f0> */
/* @0x245bb0 sub r2, r8, #1 */
/* @0x245bb4 vcvt.f64.s32 d6, s22 */
/* @0x245bb8 mov r7, #0 */
/* @0x245bbc vldr s19, [pc, #-476] */
/* @0x245bc0 vmov s11, r2 */
/* @0x245bc4 vmov s18, r7 */
/* @0x245bc8 vmov s16, r7 */
/* @0x245bcc vcvt.f64.s32 d5, s11 */
/* @0x245bd0 vmov r0, r1, d6 */
/* @0x245bd4 vmov r2, r3, d5 */
/* @0x245bd8 vcvt.f64.s32 d4, s23 */
/* @0x245bdc b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x245be0 mov r0, r4 */
/* @0x245be4 bl 0x10fb38 <utf8_extract_char> */
/* @0x245be8 mov r9, r0 */
/* @0x245bec mov r0, r4 */
/* @0x245bf0 bl 0x10fb38 <utf8_extract_char> */
/* @0x245bf4 mov r10, r0 */
/* @0x245bf8 mov r0, r4 */
/* @0x245bfc bl 0x10fb38 <utf8_extract_char> */
/* @0x245c00 ldr r3, [r5] */
/* @0x245c04 uxtab r2, r3, r9 */
/* @0x245c08 ldrb r2, [r2, #0x1] */
/* @0x245c0c and r2, r2, #4 */
/* @0x245c10 ands r7, r2, #255 */
/* @0x245c14 beq 0x245d04 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x814> */
/* @0x245c18 uxtab r2, r3, r10 */
/* @0x245c1c ldrb r2, [r2, #0x1] */
/* @0x245c20 and r2, r2, #4 */
/* @0x245c24 ands r7, r2, #255 */
/* @0x245c28 beq 0x245e30 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x940> */
/* @0x245c2c uxtab r3, r3, r0 */
/* @0x245c30 ldrb r3, [r3, #0x1] */
/* @0x245c34 and r3, r3, #4 */
/* @0x245c38 ands r3, r3, #255 */
/* @0x245c3c beq 0x245bb0 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x6c0> */
/* @0x245c40 sub r1, r10, #48 */
/* @0x245c44 sub r2, r9, #48 */
/* @0x245c48 mov r9, #10 */
/* @0x245c4c mov r12, #100 */
/* @0x245c50 mul r1, r9, r1 */
/* @0x245c54 sub r3, r0, #48 */
/* @0x245c58 mla r2, r12, r2, r1 */
/* @0x245c5c mov r0, r4 */
/* @0x245c60 add r3, r2, r3 */
/* @0x245c64 vmov s16, r3 */
/* @0x245c68 bl 0x10fb38 <utf8_extract_char> */
/* @0x245c6c subs r2, r0, #45 */
/* @0x245c70 rsbs r3, r2, #0 */
/* @0x245c74 adcs r3, r3, r2 */
/* @0x245c78 cmp r0, #45 */
/* @0x245c7c cmpne r0, #43 */
/* @0x245c80 movne r0, #0 */
/* @0x245c84 moveq r0, #1 */
/* @0x245c88 bne 0x245e04 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x914> */
/* @0x245c8c cmp r3, #0 */
/* @0x245c90 mov r0, r4 */
/* @0x245c94 moveq r3, #1 */
/* @0x245c98 mvnne r3, #0 */
/* @0x245c9c vmov s19, r3 */
/* @0x245ca0 bl 0x10fb38 <utf8_extract_char> */
/* @0x245ca4 mov r10, r0 */
/* @0x245ca8 mov r0, r4 */
/* @0x245cac bl 0x10fb38 <utf8_extract_char> */
/* @0x245cb0 ldr r3, [r5] */
/* @0x245cb4 uxtab r2, r3, r10 */
/* @0x245cb8 ldrb r2, [r2, #0x1] */
/* @0x245cbc and r2, r2, #4 */
/* @0x245cc0 ands r7, r2, #255 */
/* @0x245cc4 beq 0x245d74 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x884> */
/* @0x245cc8 uxtab r3, r3, r0 */
/* @0x245ccc ldrb r3, [r3, #0x1] */
/* @0x245cd0 and r3, r3, #4 */
/* @0x245cd4 ands r3, r3, #255 */
/* @0x245cd8 bne 0x245d30 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x840> */
/* @0x245cdc sub r2, r8, #1 */
/* @0x245ce0 vmov s18, r3 */
/* @0x245ce4 mov r7, r3 */
/* @0x245ce8 vmov s11, r2 */
/* @0x245cec vcvt.f64.s32 d7, s22 */
/* @0x245cf0 vcvt.f64.s32 d5, s11 */
/* @0x245cf4 vmov r0, r1, d7 */
/* @0x245cf8 vmov r2, r3, d5 */
/* @0x245cfc vcvt.f64.s32 d4, s23 */
/* @0x245d00 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x245d04 sub r2, r8, #1 */
/* @0x245d08 vcvt.f64.s32 d5, s22 */
/* @0x245d0c vmov s18, r7 */
/* @0x245d10 vldr s19, [pc, #-816] */
/* @0x245d14 vmov s15, r2 */
/* @0x245d18 vmov s16, r7 */
/* @0x245d1c vcvt.f64.s32 d7, s15 */
/* @0x245d20 vmov r0, r1, d5 */
/* @0x245d24 vmov r2, r3, d7 */
/* @0x245d28 vcvt.f64.s32 d4, s23 */
/* @0x245d2c b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x245d30 sub r3, r0, #48 */
/* @0x245d34 sub r10, r10, #48 */
/* @0x245d38 mov r0, r4 */
/* @0x245d3c mla r3, r9, r10, r3 */
/* @0x245d40 vmov s18, r3 */
/* @0x245d44 bl 0x10fb38 <utf8_extract_char> */
/* @0x245d48 cmp r0, #58 */
/* @0x245d4c beq 0x245d98 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x8a8> */
/* @0x245d50 sub r2, r8, #1 */
/* @0x245d54 vcvt.f64.s32 d6, s22 */
/* @0x245d58 mov r7, #0 */
/* @0x245d5c vmov s15, r2 */
/* @0x245d60 vcvt.f64.s32 d7, s15 */
/* @0x245d64 vmov r0, r1, d6 */
/* @0x245d68 vmov r2, r3, d7 */
/* @0x245d6c vcvt.f64.s32 d4, s23 */
/* @0x245d70 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x245d74 sub r2, r8, #1 */
/* @0x245d78 vmov s18, r7 */
/* @0x245d7c vmov s13, r2 */
/* @0x245d80 vcvt.f64.s32 d5, s22 */
/* @0x245d84 vcvt.f64.s32 d6, s13 */
/* @0x245d88 vmov r0, r1, d5 */
/* @0x245d8c vmov r2, r3, d6 */
/* @0x245d90 vcvt.f64.s32 d4, s23 */
/* @0x245d94 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x245d98 mov r0, r4 */
/* @0x245d9c bl 0x10fb38 <utf8_extract_char> */
/* @0x245da0 mov r10, r0 */
/* @0x245da4 mov r0, r4 */
/* @0x245da8 bl 0x10fb38 <utf8_extract_char> */
/* @0x245dac ldr r3, [r5] */
/* @0x245db0 uxtab r2, r3, r10 */
/* @0x245db4 ldrb r2, [r2, #0x1] */
/* @0x245db8 and r2, r2, #4 */
/* @0x245dbc ands r7, r2, #255 */
/* @0x245dc0 beq 0x245e68 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x978> */
/* @0x245dc4 uxtab r3, r3, r0 */
/* @0x245dc8 ldrb r3, [r3, #0x1] */
/* @0x245dcc and r3, r3, #4 */
/* @0x245dd0 ands r3, r3, #255 */
/* @0x245dd4 beq 0x245e5c <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x96c> */
/* @0x245dd8 sub r2, r8, #1 */
/* @0x245ddc vcvt.f64.s32 d6, s22 */
/* @0x245de0 sub r3, r0, #48 */
/* @0x245de4 sub r7, r10, #48 */
/* @0x245de8 vmov s15, r2 */
/* @0x245dec mla r7, r9, r7, r3 */
/* @0x245df0 vcvt.f64.s32 d7, s15 */
/* @0x245df4 vmov r0, r1, d6 */
/* @0x245df8 vmov r2, r3, d7 */
/* @0x245dfc vcvt.f64.s32 d4, s23 */
/* @0x245e00 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x245e04 sub r2, r8, #1 */
/* @0x245e08 vcvt.f64.s32 d7, s22 */
/* @0x245e0c mov r7, r0 */
/* @0x245e10 vmov s18, r0 */
/* @0x245e14 vmov s11, r2 */
/* @0x245e18 vldr s19, [pc, #80] */
/* @0x245e1c vcvt.f64.s32 d5, s11 */
/* @0x245e20 vmov r0, r1, d7 */
/* @0x245e24 vmov r2, r3, d5 */
/* @0x245e28 vcvt.f64.s32 d4, s23 */
/* @0x245e2c b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x245e30 sub r2, r8, #1 */
/* @0x245e34 vcvt.f64.s32 d7, s22 */
/* @0x245e38 vmov s18, r7 */
/* @0x245e3c vldr s19, [pc, #44] */
/* @0x245e40 vmov s13, r2 */
/* @0x245e44 vmov s16, r7 */
/* @0x245e48 vcvt.f64.s32 d6, s13 */
/* @0x245e4c vmov r0, r1, d7 */
/* @0x245e50 vmov r2, r3, d6 */
/* @0x245e54 vcvt.f64.s32 d4, s23 */
/* @0x245e58 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x245e5c sub r2, r8, #1 */
/* @0x245e60 mov r7, r3 */
/* @0x245e64 b 0x245ce8 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x7f8> */
/* @0x245e68 sub r2, r8, #1 */
/* @0x245e6c b 0x245d7c <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x88c> */
/* @0x245e70 andeq r0, r0, r1 */

/* ── FUNC 0x245e74 · anon_245e74 · size=0 · insn=1 */
/* @0x245e74 andeq r0, r0, r0 */

/* ── FUNC 0x245e78 · TimeClip(double) · size=92 · insn=23 */
/* @0x245e78 push {r3, lr} */
/* @0x245e7c vpush {d8} */
/* @0x245e80 vmov d8, r0, r1 */
/* @0x245e84 bl 0x24364c <_Z7myisinfd> */
/* @0x245e88 cmp r0, #0 */
/* @0x245e8c bne 0x245eb4 <_Z8TimeClipd+0x3c> */
/* @0x245e90 vabs.f64 d6, d8 */
/* @0x245e94 vldr d7, [pc, #44] */
/* @0x245e98 vcmpe.f64 d6, d7 */
/* @0x245e9c vmrs APSR_nzcv, fpscr */
/* @0x245ea0 bgt 0x245eb4 <_Z8TimeClipd+0x3c> */
/* @0x245ea4 vmov r0, r1, d8 */
/* @0x245ea8 vpop {d8} */
/* @0x245eac pop {r3, lr} */
/* @0x245eb0 b 0xb6598 <floor@plt> */
/* @0x245eb4 vpop {d8} */
/* @0x245eb8 ldr r3, [pc, #0x10] */
/* @0x245ebc ldr r3, [pc, r3] */
/* @0x245ec0 ldrd r0, r1, [r3] */
/* @0x245ec4 pop {r3, pc} */
/* @0x245ec8 sbcsgt r0, r12, #0 */
/* @0x245ecc teqmi lr, #8, #4 */
/* @0x245ed0 andseq r11, r10, r12, ror #16 */

/* ── FUNC 0x245ed4 · anon_245ed4 · size=0 · insn=1 */
/* @0x245ed4 nop */

/* ── FUNC 0x245ed8 · JS_Date_UTC(RValue&, CInstance*, CInstance*, int, RValue*) · size=424 · insn=103 */
/* @0x245ed8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x245edc vpush {d8} */
/* @0x245ee0 subs r8, r3, #0 */
/* @0x245ee4 sub sp, sp, #48 */
/* @0x245ee8 mov r10, r0 */
/* @0x245eec ldr r9, [sp, #0x58] */
/* @0x245ef0 ble 0x245fa8 <_Z11JS_Date_UTCR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x245ef4 mov r0, r9 */
/* @0x245ef8 mov r1, #0 */
/* @0x245efc bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x245f00 cmp r8, #1 */
/* @0x245f04 vmov d8, r0, r1 */
/* @0x245f08 beq 0x245fac <_Z11JS_Date_UTCR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x245f0c mov r0, r9 */
/* @0x245f10 mov r1, #1 */
/* @0x245f14 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x245f18 cmp r8, #2 */
/* @0x245f1c strd r0, r1, [sp, #40] */
/* @0x245f20 beq 0x245fb4 <_Z11JS_Date_UTCR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x245f24 mov r0, r9 */
/* @0x245f28 mov r1, #2 */
/* @0x245f2c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x245f30 cmp r8, #3 */
/* @0x245f34 strd r0, r1, [sp, #16] */
/* @0x245f38 beq 0x245fbc <_Z11JS_Date_UTCR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x245f3c mov r0, r9 */
/* @0x245f40 mov r1, #3 */
/* @0x245f44 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x245f48 cmp r8, #4 */
/* @0x245f4c strd r0, r1, [sp, #24] */
/* @0x245f50 beq 0x245fc4 <_Z11JS_Date_UTCR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x245f54 mov r0, r9 */
/* @0x245f58 mov r1, #4 */
/* @0x245f5c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x245f60 cmp r8, #5 */
/* @0x245f64 strd r0, r1, [sp, #32] */
/* @0x245f68 beq 0x245fcc <_Z11JS_Date_UTCR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x245f6c mov r0, r9 */
/* @0x245f70 mov r1, #5 */
/* @0x245f74 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x245f78 cmp r8, #6 */
/* @0x245f7c moveq r6, #0 */
/* @0x245f80 moveq r7, #0 */
/* @0x245f84 mov r4, r0 */
/* @0x245f88 mov r5, r1 */
/* @0x245f8c beq 0x245fdc <_Z11JS_Date_UTCR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x245f90 mov r0, r9 */
/* @0x245f94 mov r1, #6 */
/* @0x245f98 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x245f9c mov r6, r0 */
/* @0x245fa0 mov r7, r1 */
/* @0x245fa4 b 0x245fdc <_Z11JS_Date_UTCR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x245fa8 vldr d8, [pc, #184] */
/* @0x245fac vldr d7, [pc, #180] */
/* @0x245fb0 vstr d7, [sp, #40] */
/* @0x245fb4 vmov.f64 d7, #1.000000e+00 */
/* @0x245fb8 vstr d7, [sp, #16] */
/* @0x245fbc vldr d7, [pc, #164] */
/* @0x245fc0 vstr d7, [sp, #24] */
/* @0x245fc4 vldr d7, [pc, #156] */
/* @0x245fc8 vstr d7, [sp, #32] */
/* @0x245fcc mov r4, #0 */
/* @0x245fd0 mov r5, #0 */
/* @0x245fd4 mov r6, r4 */
/* @0x245fd8 mov r7, r5 */
/* @0x245fdc vcmp.f64 d8, d8 */
/* @0x245fe0 vmrs APSR_nzcv, fpscr */
/* @0x245fe4 bvs 0x246008 <_Z11JS_Date_UTCR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x245fe8 vcmpe.f64 d8, #0 */
/* @0x245fec vmrs APSR_nzcv, fpscr */
/* @0x245ff0 blt 0x246008 <_Z11JS_Date_UTCR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x245ff4 vldr d7, [pc, #116] */
/* @0x245ff8 vcmpe.f64 d8, d7 */
/* @0x245ffc vmrs APSR_nzcv, fpscr */
/* @0x246000 vldrls d7, [pc, #112] */
/* @0x246004 vaddls.f64 d8, d8, d7 */
/* @0x246008 vldr d7, [sp, #16] */
/* @0x24600c ldrd r2, r3, [sp, #40] */
/* @0x246010 vstr d7, [sp] */
/* @0x246014 vmov r0, r1, d8 */
/* @0x246018 bl 0x245370 <_Z7MakeDayddd> */
/* @0x24601c ldrd r2, r3, [sp, #32] */
/* @0x246020 strd r4, r5, [sp] */
/* @0x246024 strd r6, r7, [sp, #8] */
/* @0x246028 mov r8, r0 */
/* @0x24602c mov r9, r1 */
/* @0x246030 ldrd r0, r1, [sp, #24] */
/* @0x246034 bl 0x2451d8 <_Z8MakeTimedddd> */
/* @0x246038 mov r2, r0 */
/* @0x24603c mov r3, r1 */
/* @0x246040 mov r0, r8 */
/* @0x246044 mov r1, r9 */
/* @0x246048 bl 0x245480 <_Z8MakeDatedd> */
/* @0x24604c bl 0x245e78 <_Z8TimeClipd> */
/* @0x246050 mov r3, #0 */
/* @0x246054 str r3, [r10, #0xc] */
/* @0x246058 stm r10, {r0, r1} */
/* @0x24605c add sp, sp, #48 */
/* @0x246060 vpop {d8} */
/* @0x246064 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x246074 subsmi r12, r8, r0 */
/* @0x246078 andeq r0, r0, r0 */
/* @0x24607c addsmi r11, sp, r0 */

/* ── FUNC 0x246080 · JS_Date_create(RValue&, CInstance*, CInstance*, int, RValue*, double) · size=132 · insn=33 */
/* @0x246080 push {r4, r5, r6, r7, lr} */
/* @0x246084 sub sp, sp, #12 */
/* @0x246088 mov r6, r0 */
/* @0x24608c ldr r7, [pc, #0x64] */
/* @0x246090 ldr r12, [sp, #0x20] */
/* @0x246094 ldrd r4, r5, [sp, #40] */
/* @0x246098 add r7, pc, r7 */
/* @0x24609c str r12, [sp] */
/* @0x2460a0 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x2460a4 ldr r3, [pc, #0x50] */
/* @0x2460a8 ldr r6, [r6] */
/* @0x2460ac ldr r3, [pc, r3] */
/* @0x2460b0 ldr r1, [r3] */
/* @0x2460b4 mov r0, r6 */
/* @0x2460b8 str r1, [r6, #0x18] */
/* @0x2460bc bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x2460c0 ldr r1, [r6, #0x28] */
/* @0x2460c4 mov r2, r4 */
/* @0x2460c8 mov r12, #0 */
/* @0x2460cc orr r4, r1, #1 */
/* @0x2460d0 ldr r1, [pc, #0x28] */
/* @0x2460d4 str r7, [r6, #0x40] */
/* @0x2460d8 mov r0, r6 */
/* @0x2460dc str r4, [r6, #0x28] */
/* @0x2460e0 mov r3, r5 */
/* @0x2460e4 add r1, pc, r1 */
/* @0x2460e8 str r12, [sp, #0x20] */
/* @0x2460ec add sp, sp, #12 */
/* @0x2460f0 pop {r4, r5, r6, r7, lr} */
/* @0x2460f4 b 0x1999d0 <_ZN12YYObjectBase3AddEPKcdi> */
/* @0x2460f8 andseq pc, r0, r4, ror #18 */
/* @0x2460fc andseq r11, r10, r4, lsl #13 */
/* @0x246100 andseq pc, r0, r12, lsr #8 */

/* ── FUNC 0x246104 · anon_246104 · size=0 · insn=1 */
/* @0x246104 andeq r0, r0, r0 */

/* ── FUNC 0x246108 · JS_Date_constructor(RValue&, CInstance*, CInstance*, int, RValue*) · size=540 · insn=132 */
/* @0x246108 push {r4, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24610c vpush {d8} */
/* @0x246110 subs r4, r3, #0 */
/* @0x246114 sub sp, sp, #72 */
/* @0x246118 mov r9, r0 */
/* @0x24611c mov r10, r1 */
/* @0x246120 mov r11, r2 */
/* @0x246124 ldr r8, [sp, #0x70] */
/* @0x246128 beq 0x246268 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x24612c cmp r4, #1 */
/* @0x246130 beq 0x24624c <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x246134 mov r0, r8 */
/* @0x246138 mov r1, #0 */
/* @0x24613c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x246140 vmov d8, r0, r1 */
/* @0x246144 mov r0, r8 */
/* @0x246148 mov r1, #1 */
/* @0x24614c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x246150 cmp r4, #2 */
/* @0x246154 vmovle.f64 d7, #1.000000e+00 */
/* @0x246158 mov r6, r0 */
/* @0x24615c mov r7, r1 */
/* @0x246160 vstrle d7, [sp, #32] */
/* @0x246164 bgt 0x246270 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x246168 vldr d7, [pc, #408] */
/* @0x24616c vstr d7, [sp, #40] */
/* @0x246170 vldr d7, [pc, #400] */
/* @0x246174 vstr d7, [sp, #48] */
/* @0x246178 vldr d7, [pc, #392] */
/* @0x24617c vstr d7, [sp, #16] */
/* @0x246180 vstr d7, [sp, #24] */
/* @0x246184 vcmp.f64 d8, d8 */
/* @0x246188 vmrs APSR_nzcv, fpscr */
/* @0x24618c bvs 0x2461b0 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x246190 vcmpe.f64 d8, #0 */
/* @0x246194 vmrs APSR_nzcv, fpscr */
/* @0x246198 blt 0x2461b0 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x24619c vldr d7, [pc, #364] */
/* @0x2461a0 vcmpe.f64 d8, d7 */
/* @0x2461a4 vmrs APSR_nzcv, fpscr */
/* @0x2461a8 vldrls d7, [pc, #360] */
/* @0x2461ac vaddls.f64 d8, d8, d7 */
/* @0x2461b0 ldr r3, [pc, #0x168] */
/* @0x2461b4 ldr r3, [pc, r3] */
/* @0x2461b8 ldrb r3, [r3] */
/* @0x2461bc cmp r3, #0 */
/* @0x2461c0 movne r0, #0 */
/* @0x2461c4 movne r1, #0 */
/* @0x2461c8 bne 0x246224 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x2461cc vldr d7, [sp, #32] */
/* @0x2461d0 mov r2, r6 */
/* @0x2461d4 mov r3, r7 */
/* @0x2461d8 vstr d7, [sp] */
/* @0x2461dc vmov r0, r1, d8 */
/* @0x2461e0 bl 0x245370 <_Z7MakeDayddd> */
/* @0x2461e4 vldr d7, [sp, #16] */
/* @0x2461e8 ldrd r2, r3, [sp, #48] */
/* @0x2461ec vstr d7, [sp] */
/* @0x2461f0 vldr d7, [sp, #24] */
/* @0x2461f4 vstr d7, [sp, #8] */
/* @0x2461f8 mov r6, r0 */
/* @0x2461fc mov r7, r1 */
/* @0x246200 ldrd r0, r1, [sp, #40] */
/* @0x246204 bl 0x2451d8 <_Z8MakeTimedddd> */
/* @0x246208 mov r2, r0 */
/* @0x24620c mov r3, r1 */
/* @0x246210 mov r0, r6 */
/* @0x246214 mov r1, r7 */
/* @0x246218 bl 0x245480 <_Z8MakeDatedd> */
/* @0x24621c bl 0x245118 <_Z3UTCd> */
/* @0x246220 bl 0x245e78 <_Z8TimeClipd> */
/* @0x246224 strd r0, r1, [sp, #8] */
/* @0x246228 mov r2, r11 */
/* @0x24622c str r8, [sp] */
/* @0x246230 mov r0, r9 */
/* @0x246234 mov r1, r10 */
/* @0x246238 mov r3, r4 */
/* @0x24623c bl 0x246080 <_Z14JS_Date_createR6RValueP9CInstanceS2_iPS_d> */
/* @0x246240 add sp, sp, #72 */
/* @0x246244 vpop {d8} */
/* @0x246248 pop {r4, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24624c ldr r0, [r8, #0xc] */
/* @0x246250 cmp r0, #1 */
/* @0x246254 beq 0x2462e4 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x1dc> */
/* @0x246258 mov r0, r8 */
/* @0x24625c mov r1, #0 */
/* @0x246260 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x246264 b 0x246224 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x246268 bl 0x244988 <_Z10DateGetNowv> */
/* @0x24626c b 0x246224 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x246270 mov r0, r8 */
/* @0x246274 mov r1, #2 */
/* @0x246278 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x24627c cmp r4, #3 */
/* @0x246280 strd r0, r1, [sp, #32] */
/* @0x246284 beq 0x246168 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x246288 mov r0, r8 */
/* @0x24628c mov r1, #3 */
/* @0x246290 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x246294 cmp r4, #4 */
/* @0x246298 strd r0, r1, [sp, #40] */
/* @0x24629c beq 0x246170 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x2462a0 mov r0, r8 */
/* @0x2462a4 mov r1, #4 */
/* @0x2462a8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x2462ac cmp r4, #5 */
/* @0x2462b0 strd r0, r1, [sp, #48] */
/* @0x2462b4 beq 0x246178 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x2462b8 mov r0, r8 */
/* @0x2462bc mov r1, #5 */
/* @0x2462c0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x2462c4 cmp r4, #6 */
/* @0x2462c8 strd r0, r1, [sp, #16] */
/* @0x2462cc beq 0x2462f8 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x1f0> */
/* @0x2462d0 mov r0, r8 */
/* @0x2462d4 mov r1, #6 */
/* @0x2462d8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x2462dc strd r0, r1, [sp, #24] */
/* @0x2462e0 b 0x246184 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x2462e4 add r0, sp, #56 */
/* @0x2462e8 str r8, [sp] */
/* @0x2462ec bl 0x2454f0 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_> */
/* @0x2462f0 ldrd r0, r1, [sp, #56] */
/* @0x2462f4 b 0x246224 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x2462f8 vldr d7, [pc, #8] */
/* @0x2462fc vstr d7, [sp, #24] */
/* @0x246300 b 0x246184 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x246304 nop */
/* @0x246314 subsmi r12, r8, r0 */
/* @0x246318 andeq r0, r0, r0 */
/* @0x24631c addsmi r11, sp, r0 */
/* @0x246320 andseq r11, r10, r0, asr #6 */

/* ── FUNC 0x246324 · anon_246324 · size=0 · insn=1 */
/* @0x246324 nop */

/* ── FUNC 0x246328 · JS_DateObjectSetup() · size=2456 · insn=614 */
/* @0x246328 push {r4, r5, r6, r7, r8, lr} */
/* @0x24632c sub sp, sp, #24 */
/* @0x246330 ldr r7, [pc, #0x894] */
/* @0x246334 mov r6, #0 */
/* @0x246338 ldr r12, [pc, #0x890] */
/* @0x24633c mov r1, r6 */
/* @0x246340 add r7, pc, r7 */
/* @0x246344 mov r2, r6 */
/* @0x246348 mov r3, r6 */
/* @0x24634c add r0, sp, #8 */
/* @0x246350 ldr r12, [r7, r12] */
/* @0x246354 mvn r4, #0 */
/* @0x246358 mvn r5, #-2147483648 */
/* @0x24635c str r6, [sp] */
/* @0x246360 strd r4, r5, [r12] */
/* @0x246364 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x246368 ldr r3, [pc, #0x864] */
/* @0x24636c ldr r4, [sp, #0x8] */
/* @0x246370 ldr r2, [pc, #0x860] */
/* @0x246374 ldr r8, [r7, r3] */
/* @0x246378 ldr r3, [pc, #0x85c] */
/* @0x24637c add r2, pc, r2 */
/* @0x246380 str r2, [r4, #0x40] */
/* @0x246384 mov r0, r4 */
/* @0x246388 str r4, [r8] */
/* @0x24638c ldr r3, [r7, r3] */
/* @0x246390 ldr r1, [r3] */
/* @0x246394 str r1, [r4, #0x18] */
/* @0x246398 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x24639c ldr r3, [pc, #0x83c] */
/* @0x2463a0 ldr r0, [r4, #0x28] */
/* @0x2463a4 mov r1, r6 */
/* @0x2463a8 mov r2, r6 */
/* @0x2463ac orr r0, r0, #1 */
/* @0x2463b0 str r0, [r4, #0x28] */
/* @0x2463b4 ldr r5, [r7, r3] */
/* @0x2463b8 mov r0, r5 */
/* @0x2463bc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2463c0 ldr r1, [pc, #0x81c] */
/* @0x2463c4 mov r3, #6 */
/* @0x2463c8 add r1, pc, r1 */
/* @0x2463cc mov r2, r0 */
/* @0x2463d0 mov r0, r4 */
/* @0x2463d4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2463d8 mov r0, r5 */
/* @0x2463dc mov r1, r6 */
/* @0x2463e0 mov r2, r6 */
/* @0x2463e4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2463e8 ldr r1, [pc, #0x7f8] */
/* @0x2463ec mov r3, #6 */
/* @0x2463f0 add r1, pc, r1 */
/* @0x2463f4 mov r2, r0 */
/* @0x2463f8 mov r0, r4 */
/* @0x2463fc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246400 mov r0, r5 */
/* @0x246404 mov r1, r6 */
/* @0x246408 mov r2, r6 */
/* @0x24640c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246410 ldr r1, [pc, #0x7d4] */
/* @0x246414 mov r3, #6 */
/* @0x246418 add r1, pc, r1 */
/* @0x24641c mov r2, r0 */
/* @0x246420 mov r0, r4 */
/* @0x246424 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246428 mov r0, r5 */
/* @0x24642c mov r1, r6 */
/* @0x246430 mov r2, r6 */
/* @0x246434 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246438 ldr r1, [pc, #0x7b0] */
/* @0x24643c mov r3, #6 */
/* @0x246440 add r1, pc, r1 */
/* @0x246444 mov r2, r0 */
/* @0x246448 mov r0, r4 */
/* @0x24644c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246450 mov r0, r5 */
/* @0x246454 mov r1, r6 */
/* @0x246458 mov r2, r6 */
/* @0x24645c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246460 ldr r1, [pc, #0x78c] */
/* @0x246464 mov r3, #6 */
/* @0x246468 add r1, pc, r1 */
/* @0x24646c mov r2, r0 */
/* @0x246470 mov r0, r4 */
/* @0x246474 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246478 mov r0, r5 */
/* @0x24647c mov r1, r6 */
/* @0x246480 mov r2, r6 */
/* @0x246484 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246488 ldr r1, [pc, #0x768] */
/* @0x24648c mov r3, #6 */
/* @0x246490 add r1, pc, r1 */
/* @0x246494 mov r2, r0 */
/* @0x246498 mov r0, r4 */
/* @0x24649c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2464a0 mov r0, r5 */
/* @0x2464a4 mov r1, r6 */
/* @0x2464a8 mov r2, r6 */
/* @0x2464ac bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2464b0 ldr r1, [pc, #0x744] */
/* @0x2464b4 mov r3, #6 */
/* @0x2464b8 add r1, pc, r1 */
/* @0x2464bc mov r2, r0 */
/* @0x2464c0 mov r0, r4 */
/* @0x2464c4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2464c8 mov r0, r5 */
/* @0x2464cc mov r1, r6 */
/* @0x2464d0 mov r2, r6 */
/* @0x2464d4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2464d8 ldr r1, [pc, #0x720] */
/* @0x2464dc mov r3, #6 */
/* @0x2464e0 add r1, pc, r1 */
/* @0x2464e4 mov r2, r0 */
/* @0x2464e8 mov r0, r4 */
/* @0x2464ec bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2464f0 mov r0, r5 */
/* @0x2464f4 mov r1, r6 */
/* @0x2464f8 mov r2, r6 */
/* @0x2464fc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246500 ldr r1, [pc, #0x6fc] */
/* @0x246504 mov r3, #6 */
/* @0x246508 add r1, pc, r1 */
/* @0x24650c mov r2, r0 */
/* @0x246510 mov r0, r4 */
/* @0x246514 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246518 mov r0, r5 */
/* @0x24651c mov r1, r6 */
/* @0x246520 mov r2, r6 */
/* @0x246524 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246528 ldr r1, [pc, #0x6d8] */
/* @0x24652c mov r3, #6 */
/* @0x246530 add r1, pc, r1 */
/* @0x246534 mov r2, r0 */
/* @0x246538 mov r0, r4 */
/* @0x24653c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246540 mov r0, r5 */
/* @0x246544 mov r1, r6 */
/* @0x246548 mov r2, r6 */
/* @0x24654c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246550 ldr r1, [pc, #0x6b4] */
/* @0x246554 mov r3, #6 */
/* @0x246558 add r1, pc, r1 */
/* @0x24655c mov r2, r0 */
/* @0x246560 mov r0, r4 */
/* @0x246564 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246568 mov r0, r5 */
/* @0x24656c mov r1, r6 */
/* @0x246570 mov r2, r6 */
/* @0x246574 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246578 ldr r1, [pc, #0x690] */
/* @0x24657c mov r3, #6 */
/* @0x246580 add r1, pc, r1 */
/* @0x246584 mov r2, r0 */
/* @0x246588 mov r0, r4 */
/* @0x24658c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246590 mov r0, r5 */
/* @0x246594 mov r1, r6 */
/* @0x246598 mov r2, r6 */
/* @0x24659c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2465a0 ldr r1, [pc, #0x66c] */
/* @0x2465a4 mov r3, #6 */
/* @0x2465a8 add r1, pc, r1 */
/* @0x2465ac mov r2, r0 */
/* @0x2465b0 mov r0, r4 */
/* @0x2465b4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2465b8 mov r0, r5 */
/* @0x2465bc mov r1, r6 */
/* @0x2465c0 mov r2, r6 */
/* @0x2465c4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2465c8 ldr r1, [pc, #0x648] */
/* @0x2465cc mov r3, #6 */
/* @0x2465d0 add r1, pc, r1 */
/* @0x2465d4 mov r2, r0 */
/* @0x2465d8 mov r0, r4 */
/* @0x2465dc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2465e0 mov r0, r5 */
/* @0x2465e4 mov r1, r6 */
/* @0x2465e8 mov r2, r6 */
/* @0x2465ec bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2465f0 ldr r1, [pc, #0x624] */
/* @0x2465f4 mov r3, #6 */
/* @0x2465f8 add r1, pc, r1 */
/* @0x2465fc mov r2, r0 */
/* @0x246600 mov r0, r4 */
/* @0x246604 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246608 mov r0, r5 */
/* @0x24660c mov r1, r6 */
/* @0x246610 mov r2, r6 */
/* @0x246614 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246618 ldr r1, [pc, #0x600] */
/* @0x24661c mov r3, #6 */
/* @0x246620 add r1, pc, r1 */
/* @0x246624 mov r2, r0 */
/* @0x246628 mov r0, r4 */
/* @0x24662c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246630 mov r0, r5 */
/* @0x246634 mov r1, r6 */
/* @0x246638 mov r2, r6 */
/* @0x24663c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246640 ldr r1, [pc, #0x5dc] */
/* @0x246644 mov r3, #6 */
/* @0x246648 add r1, pc, r1 */
/* @0x24664c mov r2, r0 */
/* @0x246650 mov r0, r4 */
/* @0x246654 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246658 mov r0, r5 */
/* @0x24665c mov r1, r6 */
/* @0x246660 mov r2, r6 */
/* @0x246664 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246668 ldr r1, [pc, #0x5b8] */
/* @0x24666c mov r3, #6 */
/* @0x246670 add r1, pc, r1 */
/* @0x246674 mov r2, r0 */
/* @0x246678 mov r0, r4 */
/* @0x24667c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246680 mov r0, r5 */
/* @0x246684 mov r1, r6 */
/* @0x246688 mov r2, r6 */
/* @0x24668c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246690 ldr r1, [pc, #0x594] */
/* @0x246694 mov r3, #6 */
/* @0x246698 add r1, pc, r1 */
/* @0x24669c mov r2, r0 */
/* @0x2466a0 mov r0, r4 */
/* @0x2466a4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2466a8 mov r0, r5 */
/* @0x2466ac mov r1, r6 */
/* @0x2466b0 mov r2, r6 */
/* @0x2466b4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2466b8 ldr r1, [pc, #0x570] */
/* @0x2466bc mov r3, #6 */
/* @0x2466c0 add r1, pc, r1 */
/* @0x2466c4 mov r2, r0 */
/* @0x2466c8 mov r0, r4 */
/* @0x2466cc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2466d0 mov r0, r5 */
/* @0x2466d4 mov r1, r6 */
/* @0x2466d8 mov r2, r6 */
/* @0x2466dc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2466e0 ldr r1, [pc, #0x54c] */
/* @0x2466e4 mov r3, #6 */
/* @0x2466e8 add r1, pc, r1 */
/* @0x2466ec mov r2, r0 */
/* @0x2466f0 mov r0, r4 */
/* @0x2466f4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2466f8 mov r0, r5 */
/* @0x2466fc mov r1, r6 */
/* @0x246700 mov r2, r6 */
/* @0x246704 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246708 ldr r1, [pc, #0x528] */
/* @0x24670c mov r3, #6 */
/* @0x246710 add r1, pc, r1 */
/* @0x246714 mov r2, r0 */
/* @0x246718 mov r0, r4 */
/* @0x24671c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246720 mov r0, r5 */
/* @0x246724 mov r1, r6 */
/* @0x246728 mov r2, r6 */
/* @0x24672c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246730 ldr r1, [pc, #0x504] */
/* @0x246734 mov r3, #6 */
/* @0x246738 add r1, pc, r1 */
/* @0x24673c mov r2, r0 */
/* @0x246740 mov r0, r4 */
/* @0x246744 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246748 mov r0, r5 */
/* @0x24674c mov r1, r6 */
/* @0x246750 mov r2, r6 */
/* @0x246754 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246758 ldr r1, [pc, #0x4e0] */
/* @0x24675c mov r3, #6 */
/* @0x246760 add r1, pc, r1 */
/* @0x246764 mov r2, r0 */
/* @0x246768 mov r0, r4 */
/* @0x24676c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246770 mov r0, r5 */
/* @0x246774 mov r1, r6 */
/* @0x246778 mov r2, r6 */
/* @0x24677c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246780 ldr r1, [pc, #0x4bc] */
/* @0x246784 mov r3, #6 */
/* @0x246788 add r1, pc, r1 */
/* @0x24678c mov r2, r0 */
/* @0x246790 mov r0, r4 */
/* @0x246794 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246798 mov r0, r5 */
/* @0x24679c mov r1, r6 */
/* @0x2467a0 mov r2, r6 */
/* @0x2467a4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2467a8 ldr r1, [pc, #0x498] */
/* @0x2467ac mov r3, #6 */
/* @0x2467b0 add r1, pc, r1 */
/* @0x2467b4 mov r2, r0 */
/* @0x2467b8 mov r0, r4 */
/* @0x2467bc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2467c0 mov r0, r5 */
/* @0x2467c4 mov r1, r6 */
/* @0x2467c8 mov r2, r6 */
/* @0x2467cc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2467d0 ldr r1, [pc, #0x474] */
/* @0x2467d4 mov r3, #6 */
/* @0x2467d8 add r1, pc, r1 */
/* @0x2467dc mov r2, r0 */
/* @0x2467e0 mov r0, r4 */
/* @0x2467e4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2467e8 mov r0, r5 */
/* @0x2467ec mov r1, r6 */
/* @0x2467f0 mov r2, r6 */
/* @0x2467f4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2467f8 ldr r1, [pc, #0x450] */
/* @0x2467fc mov r3, #6 */
/* @0x246800 add r1, pc, r1 */
/* @0x246804 mov r2, r0 */
/* @0x246808 mov r0, r4 */
/* @0x24680c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246810 mov r0, r5 */
/* @0x246814 mov r1, r6 */
/* @0x246818 mov r2, r6 */
/* @0x24681c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246820 ldr r1, [pc, #0x42c] */
/* @0x246824 mov r3, #6 */
/* @0x246828 add r1, pc, r1 */
/* @0x24682c mov r2, r0 */
/* @0x246830 mov r0, r4 */
/* @0x246834 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246838 mov r0, r5 */
/* @0x24683c mov r1, r6 */
/* @0x246840 mov r2, r6 */
/* @0x246844 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246848 ldr r1, [pc, #0x408] */
/* @0x24684c mov r3, #6 */
/* @0x246850 add r1, pc, r1 */
/* @0x246854 mov r2, r0 */
/* @0x246858 mov r0, r4 */
/* @0x24685c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246860 mov r0, r5 */
/* @0x246864 mov r1, r6 */
/* @0x246868 mov r2, r6 */
/* @0x24686c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246870 ldr r1, [pc, #0x3e4] */
/* @0x246874 mov r3, #6 */
/* @0x246878 add r1, pc, r1 */
/* @0x24687c mov r2, r0 */
/* @0x246880 mov r0, r4 */
/* @0x246884 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246888 mov r0, r5 */
/* @0x24688c mov r1, r6 */
/* @0x246890 mov r2, r6 */
/* @0x246894 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246898 ldr r1, [pc, #0x3c0] */
/* @0x24689c mov r3, #6 */
/* @0x2468a0 add r1, pc, r1 */
/* @0x2468a4 mov r2, r0 */
/* @0x2468a8 mov r0, r4 */
/* @0x2468ac bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2468b0 mov r0, r5 */
/* @0x2468b4 mov r1, r6 */
/* @0x2468b8 mov r2, r6 */
/* @0x2468bc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2468c0 ldr r1, [pc, #0x39c] */
/* @0x2468c4 mov r3, #6 */
/* @0x2468c8 add r1, pc, r1 */
/* @0x2468cc mov r2, r0 */
/* @0x2468d0 mov r0, r4 */
/* @0x2468d4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2468d8 mov r0, r5 */
/* @0x2468dc mov r1, r6 */
/* @0x2468e0 mov r2, r6 */
/* @0x2468e4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2468e8 ldr r1, [pc, #0x378] */
/* @0x2468ec mov r3, #6 */
/* @0x2468f0 add r1, pc, r1 */
/* @0x2468f4 mov r2, r0 */
/* @0x2468f8 mov r0, r4 */
/* @0x2468fc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246900 mov r0, r5 */
/* @0x246904 mov r1, r6 */
/* @0x246908 mov r2, r6 */
/* @0x24690c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246910 ldr r1, [pc, #0x354] */
/* @0x246914 mov r3, #6 */
/* @0x246918 add r1, pc, r1 */
/* @0x24691c mov r2, r0 */
/* @0x246920 mov r0, r4 */
/* @0x246924 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246928 mov r0, r5 */
/* @0x24692c mov r1, r6 */
/* @0x246930 mov r2, r6 */
/* @0x246934 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246938 ldr r1, [pc, #0x330] */
/* @0x24693c mov r3, #6 */
/* @0x246940 add r1, pc, r1 */
/* @0x246944 mov r2, r0 */
/* @0x246948 mov r0, r4 */
/* @0x24694c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246950 mov r0, r5 */
/* @0x246954 mov r1, r6 */
/* @0x246958 mov r2, r6 */
/* @0x24695c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246960 ldr r1, [pc, #0x30c] */
/* @0x246964 mov r3, #6 */
/* @0x246968 add r1, pc, r1 */
/* @0x24696c mov r2, r0 */
/* @0x246970 mov r0, r4 */
/* @0x246974 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246978 mov r0, r5 */
/* @0x24697c mov r1, r6 */
/* @0x246980 mov r2, r6 */
/* @0x246984 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246988 ldr r1, [pc, #0x2e8] */
/* @0x24698c mov r3, #6 */
/* @0x246990 add r1, pc, r1 */
/* @0x246994 mov r2, r0 */
/* @0x246998 mov r0, r4 */
/* @0x24699c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2469a0 mov r0, r5 */
/* @0x2469a4 mov r1, r6 */
/* @0x2469a8 mov r2, r6 */
/* @0x2469ac bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2469b0 ldr r1, [pc, #0x2c4] */
/* @0x2469b4 mov r3, #6 */
/* @0x2469b8 add r1, pc, r1 */
/* @0x2469bc mov r2, r0 */
/* @0x2469c0 mov r0, r4 */
/* @0x2469c4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2469c8 mov r0, r5 */
/* @0x2469cc mov r1, r6 */
/* @0x2469d0 mov r2, r6 */
/* @0x2469d4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x2469d8 ldr r1, [pc, #0x2a0] */
/* @0x2469dc mov r3, #6 */
/* @0x2469e0 add r1, pc, r1 */
/* @0x2469e4 mov r2, r0 */
/* @0x2469e8 mov r0, r4 */
/* @0x2469ec bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2469f0 mov r0, r5 */
/* @0x2469f4 mov r1, r6 */
/* @0x2469f8 mov r2, r6 */
/* @0x2469fc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246a00 ldr r1, [pc, #0x27c] */
/* @0x246a04 mov r3, #6 */
/* @0x246a08 add r1, pc, r1 */
/* @0x246a0c mov r2, r0 */
/* @0x246a10 mov r0, r4 */
/* @0x246a14 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246a18 ldr r3, [pc, #0x268] */
/* @0x246a1c mov r1, r6 */
/* @0x246a20 mov r2, r6 */
/* @0x246a24 ldr r0, [r7, r3] */
/* @0x246a28 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246a2c ldr r1, [pc, #0x258] */
/* @0x246a30 mov r3, #6 */
/* @0x246a34 add r1, pc, r1 */
/* @0x246a38 mov r2, r0 */
/* @0x246a3c mov r0, r4 */
/* @0x246a40 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246a44 mov r0, r5 */
/* @0x246a48 mov r1, r6 */
/* @0x246a4c mov r2, r6 */
/* @0x246a50 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246a54 ldr r1, [pc, #0x234] */
/* @0x246a58 mov r3, #6 */
/* @0x246a5c add r1, pc, r1 */
/* @0x246a60 mov r2, r0 */
/* @0x246a64 mov r0, r4 */
/* @0x246a68 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246a6c ldr r3, [pc, #0x220] */
/* @0x246a70 mov r2, r6 */
/* @0x246a74 mov r1, #7 */
/* @0x246a78 ldr r0, [r7, r3] */
/* @0x246a7c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246a80 ldr r3, [pc, #0x210] */
/* @0x246a84 mov r1, r6 */
/* @0x246a88 mov r2, r6 */
/* @0x246a8c mov r5, r0 */
/* @0x246a90 ldr r0, [pc, #0x204] */
/* @0x246a94 ldr r0, [r7, r0] */
/* @0x246a98 str r0, [r5, #0x94] */
/* @0x246a9c ldr r0, [r7, r3] */
/* @0x246aa0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246aa4 ldr r1, [pc, #0x1f4] */
/* @0x246aa8 mov r3, r6 */
/* @0x246aac add r1, pc, r1 */
/* @0x246ab0 mov r2, r0 */
/* @0x246ab4 mov r0, r5 */
/* @0x246ab8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246abc ldr r3, [pc, #0x1e0] */
/* @0x246ac0 mov r2, r6 */
/* @0x246ac4 mov r1, #7 */
/* @0x246ac8 ldr r0, [r7, r3] */
/* @0x246acc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246ad0 ldr r1, [pc, #0x1d0] */
/* @0x246ad4 mov r3, r6 */
/* @0x246ad8 add r1, pc, r1 */
/* @0x246adc mov r2, r0 */
/* @0x246ae0 mov r0, r5 */
/* @0x246ae4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246ae8 ldr r3, [pc, #0x1bc] */
/* @0x246aec mov r1, r6 */
/* @0x246af0 mov r2, r6 */
/* @0x246af4 ldr r0, [r7, r3] */
/* @0x246af8 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246afc ldr r1, [pc, #0x1ac] */
/* @0x246b00 mov r3, r6 */
/* @0x246b04 add r1, pc, r1 */
/* @0x246b08 mov r2, r0 */
/* @0x246b0c mov r0, r5 */
/* @0x246b10 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246b14 ldr r1, [pc, #0x198] */
/* @0x246b18 mov r3, r6 */
/* @0x246b1c mov r0, r4 */
/* @0x246b20 mov r2, r5 */
/* @0x246b24 add r1, pc, r1 */
/* @0x246b28 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246b2c ldr r3, [r5, #0x4] */
/* @0x246b30 cmp r3, r6 */
/* @0x246b34 beq 0x246b8c <_Z18JS_DateObjectSetupv+0x864> */
/* @0x246b38 ldr r1, [r8] */
/* @0x246b3c mov r0, r5 */
/* @0x246b40 str r1, [r3] */
/* @0x246b44 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x246b48 ldr r1, [r5, #0x4] */
/* @0x246b4c cmp r1, #0 */
/* @0x246b50 movne r3, #6 */
/* @0x246b54 strne r3, [r1, #0xc] */
/* @0x246b58 beq 0x246ba0 <_Z18JS_DateObjectSetupv+0x878> */
/* @0x246b5c ldr r0, [pc, #0x154] */
/* @0x246b60 mov r3, #6 */
/* @0x246b64 str r3, [r1, #0x8] */
/* @0x246b68 mov r2, r5 */
/* @0x246b6c ldr r1, [pc, #0x148] */
/* @0x246b70 mov r3, #0 */
/* @0x246b74 ldr r0, [r7, r0] */
/* @0x246b78 add r1, pc, r1 */
/* @0x246b7c ldr r0, [r0] */
/* @0x246b80 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246b84 add sp, sp, #24 */
/* @0x246b88 pop {r4, r5, r6, r7, r8, pc} */
/* @0x246b8c mov r1, r3 */
/* @0x246b90 mov r0, r5 */
/* @0x246b94 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x246b98 mov r3, r0 */
/* @0x246b9c b 0x246b38 <_Z18JS_DateObjectSetupv+0x810> */
/* @0x246ba0 mov r0, r5 */
/* @0x246ba4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x246ba8 ldr r1, [r5, #0x4] */
/* @0x246bac mov r3, #6 */
/* @0x246bb0 cmp r1, #0 */
/* @0x246bb4 str r3, [r0, #0xc] */
/* @0x246bb8 bne 0x246b5c <_Z18JS_DateObjectSetupv+0x834> */
/* @0x246bbc mov r0, r5 */
/* @0x246bc0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x246bc4 mov r1, r0 */
/* @0x246bc8 b 0x246b5c <_Z18JS_DateObjectSetupv+0x834> */
/* @0x246bcc andseq r11, r10, r0, lsl r9 */
/* @0x246bd0 .word 0xfffffad8 */
/* @0x246bd4 .word 0xfffffae0 */
/* @0x246bd8 andseq pc, r0, r0, lsl #13 */
/* @0x246bdc .word 0xffffc050 */
/* @0x246be0 .word 0xfffff8ec */
/* @0x246be4 andeq r12, lr, r8, asr #2 */
/* @0x246be8 andseq pc, r0, r4, lsl r6 */
/* @0x246bec ldrsheq pc, [r0], -r12 */
/* @0x246bf0 andseq pc, r0, r8, lsl #4 */
/* @0x246bf4 ldrheq pc, [r0], -r12 */
/* @0x246bf8 andseq pc, r0, r8, lsr #11 */
/* @0x246bfc andseq pc, r0, r0, lsr #3 */
/* @0x246c00 andseq pc, r0, r12, ror #10 */
/* @0x246c04 andseq pc, r0, r12, asr #10 */
/* @0x246c08 andseq pc, r0, r0, lsr r5 */
/* @0x246c0c andseq pc, r0, r8, lsl r5 */
/* @0x246c10 ldrsheq pc, [r0], -r12 */
/* @0x246c14 andseq pc, r0, r0, ror #9 */
/* @0x246c18 andseq pc, r0, r0, asr #9 */
/* @0x246c1c andseq pc, r0, r4, lsr #9 */
/* @0x246c20 andseq pc, r0, r4, lsl #9 */
/* @0x246c24 andseq pc, r0, r8, ror #8 */
/* @0x246c28 andseq pc, r0, r12, asr #8 */
/* @0x246c2c andseq pc, r0, r0, lsr r4 */
/* @0x246c30 andseq pc, r0, r4, lsl r4 */
/* @0x246c34 ldrsheq pc, [r0], -r12 */
/* @0x246c38 andseq pc, r0, r0, ror #7 */
/* @0x246c3c andseq pc, r0, r8, asr #7 */
/* @0x246c40 ldrheq pc, [r0], -r0 */
/* @0x246c44 mulseq r0, r12, r3 */
/* @0x246c48 andseq pc, r0, r8, lsl #7 */
/* @0x246c4c andseq pc, r0, r8, ror #6 */
/* @0x246c50 andseq pc, r0, r0, asr r3 */
/* @0x246c54 andseq pc, r0, r12, lsr r3 */
/* @0x246c58 andseq pc, r0, r0, lsr #6 */
/* @0x246c5c andseq pc, r0, r8, lsl #6 */
/* @0x246c60 andseq pc, r0, r12, ror #5 */
/* @0x246c64 ldrsbeq pc, [r0], -r4 */
/* @0x246c68 ldrheq pc, [r0], -r8 */
/* @0x246c6c mulseq r0, r12, r2 */
/* @0x246c70 andseq pc, r0, r12, ror r2 */
/* @0x246c74 andseq pc, r0, r0, ror #4 */
/* @0x246c78 andseq pc, r0, r4, asr #4 */
/* @0x246c7c andseq pc, r0, r8, lsr #4 */
/* @0x246c80 andseq pc, r0, r12, lsl #4 */
/* @0x246c84 ldrsheq pc, [r0], -r4 */
/* @0x246c88 .word 0xfffffae4 */
/* @0x246c8c ldrsbeq pc, [r0], -r4 */
/* @0x246c90 ldrheq pc, [r0], -r8 */
/* @0x246c94 .word 0xfffffae8 */
/* @0x246c98 .word 0xfffffaec */
/* @0x246c9c .word 0xfffffaf0 */
/* @0x246ca0 andseq pc, r0, r0, ror r1 */
/* @0x246ca4 .word 0xfffffaf4 */
/* @0x246ca8 andseq pc, r0, r8, asr #2 */
/* @0x246cac .word 0xfffffaf8 */
/* @0x246cb0 andseq pc, r0, r0, lsr #2 */
/* @0x246cb4 andseq lr, r0, r0, lsl #20 */
/* @0x246cb8 .word 0xffffbf64 */
/* @0x246cbc andseq lr, r0, r4, lsl #29 */

/* ── FUNC 0x246cc0 · JS_RegExpObjectSetup() · size=544 · insn=136 */
/* @0x246cc0 push {r4, r5, r6, r7, r8, lr} */
/* @0x246cc4 sub sp, sp, #24 */
/* @0x246cc8 mov r5, #0 */
/* @0x246ccc add r0, sp, #8 */
/* @0x246cd0 mov r1, r5 */
/* @0x246cd4 mov r2, r5 */
/* @0x246cd8 mov r3, r5 */
/* @0x246cdc str r5, [sp] */
/* @0x246ce0 ldr r6, [pc, #0x1bc] */
/* @0x246ce4 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x246ce8 ldr r3, [pc, #0x1b8] */
/* @0x246cec add r6, pc, r6 */
/* @0x246cf0 ldr r4, [sp, #0x8] */
/* @0x246cf4 ldr r2, [pc, #0x1b0] */
/* @0x246cf8 ldr r8, [r6, r3] */
/* @0x246cfc ldr r3, [pc, #0x1ac] */
/* @0x246d00 add r2, pc, r2 */
/* @0x246d04 str r2, [r4, #0x40] */
/* @0x246d08 mov r0, r4 */
/* @0x246d0c str r4, [r8] */
/* @0x246d10 ldr r3, [r6, r3] */
/* @0x246d14 ldr r1, [r3] */
/* @0x246d18 str r1, [r4, #0x18] */
/* @0x246d1c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x246d20 ldr r3, [pc, #0x18c] */
/* @0x246d24 ldr r0, [r4, #0x28] */
/* @0x246d28 mov r1, r5 */
/* @0x246d2c mov r2, r5 */
/* @0x246d30 orr r0, r0, #1 */
/* @0x246d34 str r0, [r4, #0x28] */
/* @0x246d38 ldr r0, [r6, r3] */
/* @0x246d3c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246d40 ldr r1, [pc, #0x170] */
/* @0x246d44 mov r3, #6 */
/* @0x246d48 add r1, pc, r1 */
/* @0x246d4c mov r2, r0 */
/* @0x246d50 mov r0, r4 */
/* @0x246d54 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246d58 ldr r3, [pc, #0x15c] */
/* @0x246d5c mov r2, r5 */
/* @0x246d60 mov r1, #1 */
/* @0x246d64 ldr r0, [r6, r3] */
/* @0x246d68 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246d6c ldr r1, [pc, #0x14c] */
/* @0x246d70 mov r3, #6 */
/* @0x246d74 add r1, pc, r1 */
/* @0x246d78 mov r2, r0 */
/* @0x246d7c mov r0, r4 */
/* @0x246d80 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246d84 ldr r3, [pc, #0x138] */
/* @0x246d88 mov r2, r5 */
/* @0x246d8c mov r1, #1 */
/* @0x246d90 ldr r0, [r6, r3] */
/* @0x246d94 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246d98 ldr r1, [pc, #0x128] */
/* @0x246d9c mov r3, #6 */
/* @0x246da0 add r1, pc, r1 */
/* @0x246da4 mov r2, r0 */
/* @0x246da8 mov r0, r4 */
/* @0x246dac bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246db0 ldr r3, [pc, #0x114] */
/* @0x246db4 mov r2, r5 */
/* @0x246db8 mov r1, #2 */
/* @0x246dbc ldr r0, [r6, r3] */
/* @0x246dc0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246dc4 ldr r12, [pc, #0x104] */
/* @0x246dc8 ldr r1, [pc, #0x104] */
/* @0x246dcc mov r3, r5 */
/* @0x246dd0 ldr r12, [r6, r12] */
/* @0x246dd4 add r1, pc, r1 */
/* @0x246dd8 mov r7, r0 */
/* @0x246ddc mov r0, r4 */
/* @0x246de0 mov r2, r7 */
/* @0x246de4 str r12, [r7, #0x94] */
/* @0x246de8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246dec ldr r1, [r7, #0x4] */
/* @0x246df0 cmp r1, r5 */
/* @0x246df4 beq 0x246e3c <_Z20JS_RegExpObjectSetupv+0x17c> */
/* @0x246df8 ldr r3, [r8] */
/* @0x246dfc mov r0, r1 */
/* @0x246e00 str r3, [r1] */
/* @0x246e04 mov r3, #6 */
/* @0x246e08 str r3, [r0, #0xc] */
/* @0x246e0c ldr r12, [pc, #0xc4] */
/* @0x246e10 mov r3, #6 */
/* @0x246e14 str r3, [r0, #0x8] */
/* @0x246e18 mov r2, r7 */
/* @0x246e1c ldr r1, [pc, #0xb8] */
/* @0x246e20 mov r3, #0 */
/* @0x246e24 ldr r0, [r6, r12] */
/* @0x246e28 add r1, pc, r1 */
/* @0x246e2c ldr r0, [r0] */
/* @0x246e30 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246e34 add sp, sp, #24 */
/* @0x246e38 pop {r4, r5, r6, r7, r8, pc} */
/* @0x246e3c ldr r3, [r7] */
/* @0x246e40 mov r0, r7 */
/* @0x246e44 ldr r3, [r3, #0x8] */
/* @0x246e48 blx r3 */
/* @0x246e4c ldr r1, [r7, #0x4] */
/* @0x246e50 ldr r3, [r8] */
/* @0x246e54 cmp r1, r5 */
/* @0x246e58 str r3, [r0] */
/* @0x246e5c bne 0x246e9c <_Z20JS_RegExpObjectSetupv+0x1dc> */
/* @0x246e60 ldr r3, [r7] */
/* @0x246e64 mov r0, r7 */
/* @0x246e68 ldr r3, [r3, #0x8] */
/* @0x246e6c blx r3 */
/* @0x246e70 ldr r1, [r7, #0x4] */
/* @0x246e74 mov r3, #6 */
/* @0x246e78 cmp r1, r5 */
/* @0x246e7c str r3, [r0, #0xc] */
/* @0x246e80 movne r0, r1 */
/* @0x246e84 bne 0x246e0c <_Z20JS_RegExpObjectSetupv+0x14c> */
/* @0x246e88 ldr r3, [r7] */
/* @0x246e8c mov r0, r7 */
/* @0x246e90 ldr r3, [r3, #0x8] */
/* @0x246e94 blx r3 */
/* @0x246e98 b 0x246e0c <_Z20JS_RegExpObjectSetupv+0x14c> */
/* @0x246e9c mov r0, r1 */
/* @0x246ea0 b 0x246e04 <_Z20JS_RegExpObjectSetupv+0x144> */
/* @0x246ea4 andseq r10, r10, r4, ror #30 */
/* @0x246ea8 .word 0xfffffafc */
/* @0x246eac andseq lr, r0, r12, lsr #30 */
/* @0x246eb0 .word 0xffffc050 */
/* @0x246eb4 .word 0xfffffb00 */
/* @0x246eb8 andeq r11, lr, r8, asr #15 */
/* @0x246ebc .word 0xfffffb04 */
/* @0x246ec0 andseq lr, r0, r0, asr #29 */
/* @0x246ec4 .word 0xfffffb08 */
/* @0x246ec8 mulseq r0, r12, lr */
/* @0x246ecc .word 0xfffffb0c */
/* @0x246ed0 .word 0xfffffb10 */
/* @0x246ed4 andseq lr, r0, r0, asr r7 */
/* @0x246ed8 .word 0xffffbf64 */
/* @0x246edc andseq lr, r0, r4, lsl #28 */

/* ── FUNC 0x246ee0 · JS_JSONObjectSetup() · size=200 · insn=50 */
/* @0x246ee0 push {r4, r5, r6, lr} */
/* @0x246ee4 sub sp, sp, #24 */
/* @0x246ee8 mov r4, #0 */
/* @0x246eec add r0, sp, #8 */
/* @0x246ef0 mov r3, r4 */
/* @0x246ef4 mov r1, r4 */
/* @0x246ef8 mov r2, r4 */
/* @0x246efc str r4, [sp] */
/* @0x246f00 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x246f04 ldr r5, [sp, #0x8] */
/* @0x246f08 ldr r6, [pc, #0x80] */
/* @0x246f0c mov r1, r4 */
/* @0x246f10 ldr r0, [pc, #0x7c] */
/* @0x246f14 mov r2, r4 */
/* @0x246f18 add r6, pc, r6 */
/* @0x246f1c str r6, [r5, #0x40] */
/* @0x246f20 ldr r0, [pc, r0] */
/* @0x246f24 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246f28 ldr r1, [pc, #0x68] */
/* @0x246f2c mov r3, #6 */
/* @0x246f30 add r1, pc, r1 */
/* @0x246f34 mov r2, r0 */
/* @0x246f38 mov r0, r5 */
/* @0x246f3c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246f40 ldr r0, [pc, #0x54] */
/* @0x246f44 mov r1, r4 */
/* @0x246f48 mov r2, r4 */
/* @0x246f4c ldr r0, [pc, r0] */
/* @0x246f50 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib> */
/* @0x246f54 ldr r1, [pc, #0x44] */
/* @0x246f58 mov r3, #6 */
/* @0x246f5c add r1, pc, r1 */
/* @0x246f60 mov r2, r0 */
/* @0x246f64 mov r0, r5 */
/* @0x246f68 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246f6c ldr r0, [pc, #0x30] */
/* @0x246f70 mov r1, r6 */
/* @0x246f74 mov r2, r5 */
/* @0x246f78 ldr r0, [pc, r0] */
/* @0x246f7c mov r3, r4 */
/* @0x246f80 ldr r0, [r0] */
/* @0x246f84 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x246f88 add sp, sp, #24 */
/* @0x246f8c pop {r4, r5, r6, pc} */
/* @0x246f90 andseq lr, r0, r12, lsr #26 */
/* @0x246f94 andseq r10, r10, r4, asr #16 */
/* @0x246f98 ldrsheq lr, [r0], -r4 */
/* @0x246f9c andseq r10, r10, r12, lsl r8 */
/* @0x246fa0 ldrsheq lr, [r0], -r0 */
/* @0x246fa4 andseq r6, r10, r12, lsr r12 */

/* ── FUNC 0x246fa8 · INITIALIZE_JavaScript() · size=56 · insn=14 */
/* @0x246fa8 push {r3, lr} */
/* @0x246fac bl 0x24163c <_Z16JS_FunctionSetupv> */
/* @0x246fb0 bl 0x240ffc <_Z20JS_GlobalObjectSetupv> */
/* @0x246fb4 bl 0x241df4 <_Z14JS_ObjectSetupv> */
/* @0x246fb8 bl 0x243074 <_Z19JS_ArrayObjectSetupv> */
/* @0x246fbc bl 0x24269c <_Z14JS_StringSetupv> */
/* @0x246fc0 bl 0x243680 <_Z18JS_MathObjectSetupv> */
/* @0x246fc4 bl 0x243bf0 <_Z21JS_BooleanObjectSetupv> */
/* @0x246fc8 bl 0x244368 <_Z19JS_ErrorObjectSetupv> */
/* @0x246fcc bl 0x2445a8 <_Z20JS_NumberObjectSetupv> */
/* @0x246fd0 bl 0x246328 <_Z18JS_DateObjectSetupv> */
/* @0x246fd4 bl 0x246cc0 <_Z20JS_RegExpObjectSetupv> */
/* @0x246fd8 pop {r3, lr} */
/* @0x246fdc b 0x246ee0 <_Z18JS_JSONObjectSetupv> */

/* ── FUNC 0x246fe0 · InitJavaScriptFunctions() · size=936 · insn=234 */
/* @0x246fe0 push {r4, r5, r6, lr} */
/* @0x246fe4 mov r2, #1 */
/* @0x246fe8 ldr r4, [pc, #0x2d0] */
/* @0x246fec mov r3, r2 */
/* @0x246ff0 ldr r1, [pc, #0x2cc] */
/* @0x246ff4 add r4, pc, r4 */
/* @0x246ff8 ldr r0, [pc, #0x2c8] */
/* @0x246ffc ldr r1, [r4, r1] */
/* @0x247000 add r0, pc, r0 */
/* @0x247004 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x247008 ldr r1, [pc, #0x2bc] */
/* @0x24700c ldr r0, [pc, #0x2bc] */
/* @0x247010 mov r2, #1 */
/* @0x247014 mov r3, r2 */
/* @0x247018 ldr r5, [r4, r1] */
/* @0x24701c add r0, pc, r0 */
/* @0x247020 mov r1, r5 */
/* @0x247024 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x247028 ldr r0, [pc, #0x2a4] */
/* @0x24702c mov r2, #1 */
/* @0x247030 mov r1, r5 */
/* @0x247034 mov r3, r2 */
/* @0x247038 add r0, pc, r0 */
/* @0x24703c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x247040 ldr r0, [pc, #0x290] */
/* @0x247044 mov r2, #1 */
/* @0x247048 mov r1, r5 */
/* @0x24704c mov r3, r2 */
/* @0x247050 add r0, pc, r0 */
/* @0x247054 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x247058 ldr r0, [pc, #0x27c] */
/* @0x24705c mov r2, #1 */
/* @0x247060 mov r1, r5 */
/* @0x247064 mov r3, r2 */
/* @0x247068 add r0, pc, r0 */
/* @0x24706c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x247070 ldr r1, [pc, #0x268] */
/* @0x247074 ldr r0, [pc, #0x268] */
/* @0x247078 mov r2, #1 */
/* @0x24707c mov r3, r2 */
/* @0x247080 ldr r1, [r4, r1] */
/* @0x247084 add r0, pc, r0 */
/* @0x247088 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x24708c ldr r1, [pc, #0x254] */
/* @0x247090 ldr r0, [pc, #0x254] */
/* @0x247094 mov r2, #1 */
/* @0x247098 mov r3, r2 */
/* @0x24709c ldr r1, [r4, r1] */
/* @0x2470a0 add r0, pc, r0 */
/* @0x2470a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x2470a8 ldr r1, [pc, #0x240] */
/* @0x2470ac ldr r0, [pc, #0x240] */
/* @0x2470b0 mov r2, #1 */
/* @0x2470b4 mov r3, r2 */
/* @0x2470b8 ldr r1, [r4, r1] */
/* @0x2470bc add r0, pc, r0 */
/* @0x2470c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x2470c4 ldr r1, [pc, #0x22c] */
/* @0x2470c8 ldr r0, [pc, #0x22c] */
/* @0x2470cc mov r2, #2 */
/* @0x2470d0 mov r3, #1 */
/* @0x2470d4 ldr r1, [r4, r1] */
/* @0x2470d8 add r0, pc, r0 */
/* @0x2470dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x2470e0 ldr r1, [pc, #0x218] */
/* @0x2470e4 ldr r0, [pc, #0x218] */
/* @0x2470e8 mov r2, #0 */
/* @0x2470ec mov r3, #1 */
/* @0x2470f0 ldr r1, [r4, r1] */
/* @0x2470f4 add r0, pc, r0 */
/* @0x2470f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x2470fc ldr r1, [pc, #0x204] */
/* @0x247100 ldr r0, [pc, #0x204] */
/* @0x247104 mov r2, #1 */
/* @0x247108 mov r3, r2 */
/* @0x24710c ldr r1, [r4, r1] */
/* @0x247110 add r0, pc, r0 */
/* @0x247114 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x247118 ldr r1, [pc, #0x1f0] */
/* @0x24711c ldr r0, [pc, #0x1f0] */
/* @0x247120 mov r2, #0 */
/* @0x247124 mov r3, #1 */
/* @0x247128 ldr r1, [r4, r1] */
/* @0x24712c add r0, pc, r0 */
/* @0x247130 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x247134 ldr r1, [pc, #0x1dc] */
/* @0x247138 ldr r0, [pc, #0x1dc] */
/* @0x24713c mov r2, #0 */
/* @0x247140 mov r3, #1 */
/* @0x247144 ldr r1, [r4, r1] */
/* @0x247148 add r0, pc, r0 */
/* @0x24714c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x247150 ldr r1, [pc, #0x1c8] */
/* @0x247154 ldr r0, [pc, #0x1c8] */
/* @0x247158 mov r2, #0 */
/* @0x24715c mov r3, #1 */
/* @0x247160 ldr r1, [r4, r1] */
/* @0x247164 add r0, pc, r0 */
/* @0x247168 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x24716c ldr r1, [pc, #0x1b4] */
/* @0x247170 ldr r0, [pc, #0x1b4] */
/* @0x247174 mov r2, #2 */
/* @0x247178 mov r3, #1 */
/* @0x24717c ldr r1, [r4, r1] */
/* @0x247180 add r0, pc, r0 */
/* @0x247184 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x247188 ldr r1, [pc, #0x1a0] */
/* @0x24718c ldr r0, [pc, #0x1a0] */
/* @0x247190 mov r2, #0 */
/* @0x247194 mov r3, #1 */
/* @0x247198 ldr r1, [r4, r1] */
/* @0x24719c add r0, pc, r0 */
/* @0x2471a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x2471a4 ldr r1, [pc, #0x18c] */
/* @0x2471a8 ldr r0, [pc, #0x18c] */
/* @0x2471ac mov r2, #0 */
/* @0x2471b0 mov r3, #1 */
/* @0x2471b4 ldr r1, [r4, r1] */
/* @0x2471b8 add r0, pc, r0 */
/* @0x2471bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x2471c0 ldr r1, [pc, #0x178] */
/* @0x2471c4 ldr r0, [pc, #0x178] */
/* @0x2471c8 mov r2, #0 */
/* @0x2471cc mov r3, #1 */
/* @0x2471d0 ldr r1, [r4, r1] */
/* @0x2471d4 add r0, pc, r0 */
/* @0x2471d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x2471dc ldr r1, [pc, #0x164] */
/* @0x2471e0 ldr r0, [pc, #0x164] */
/* @0x2471e4 mov r2, #0 */
/* @0x2471e8 mov r3, #1 */
/* @0x2471ec ldr r1, [r4, r1] */
/* @0x2471f0 add r0, pc, r0 */
/* @0x2471f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x2471f8 ldr r1, [pc, #0x150] */
/* @0x2471fc ldr r0, [pc, #0x150] */
/* @0x247200 mov r2, #0 */
/* @0x247204 mov r3, #1 */
/* @0x247208 ldr r1, [r4, r1] */
/* @0x24720c add r0, pc, r0 */
/* @0x247210 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x247214 ldr r1, [pc, #0x13c] */
/* @0x247218 ldr r0, [pc, #0x13c] */
/* @0x24721c mov r2, #0 */
/* @0x247220 mov r3, #1 */
/* @0x247224 ldr r1, [r4, r1] */
/* @0x247228 add r0, pc, r0 */
/* @0x24722c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x247230 ldr r1, [pc, #0x128] */
/* @0x247234 ldr r0, [pc, #0x128] */
/* @0x247238 mov r2, #0 */
/* @0x24723c mov r3, #1 */
/* @0x247240 ldr r1, [r4, r1] */
/* @0x247244 add r0, pc, r0 */
/* @0x247248 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x24724c ldr r1, [pc, #0x114] */
/* @0x247250 ldr r0, [pc, #0x114] */
/* @0x247254 mov r2, #0 */
/* @0x247258 mov r3, #1 */
/* @0x24725c ldr r1, [r4, r1] */
/* @0x247260 add r0, pc, r0 */
/* @0x247264 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x247268 ldr r1, [pc, #0x100] */
/* @0x24726c ldr r0, [pc, #0x100] */
/* @0x247270 mov r2, #0 */
/* @0x247274 mov r3, #1 */
/* @0x247278 ldr r1, [r4, r1] */
/* @0x24727c add r0, pc, r0 */
/* @0x247280 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x247284 ldr r1, [pc, #0xec] */
/* @0x247288 ldr r0, [pc, #0xec] */
/* @0x24728c mov r2, #0 */
/* @0x247290 mov r3, #1 */
/* @0x247294 ldr r1, [r4, r1] */
/* @0x247298 add r0, pc, r0 */
/* @0x24729c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x2472a0 ldr r1, [pc, #0xd8] */
/* @0x2472a4 ldr r0, [pc, #0xd8] */
/* @0x2472a8 mov r2, #0 */
/* @0x2472ac mov r3, #1 */
/* @0x2472b0 ldr r1, [r4, r1] */
/* @0x2472b4 add r0, pc, r0 */
/* @0x2472b8 pop {r4, r5, r6, lr} */
/* @0x2472bc b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x2472c0 andseq r10, r10, r12, asr r12 */
/* @0x2472c4 .word 0xfffffb1c */
/* @0x2472c8 andseq lr, r0, r8, asr r12 */
/* @0x2472cc .word 0xfffffb20 */
/* @0x2472d0 andseq lr, r0, r4, asr #24 */
/* @0x2472d4 andseq lr, r0, r0, lsr r12 */
/* @0x2472d8 andeq r11, lr, r12, lsr r5 */
/* @0x2472dc andseq lr, r0, r8, lsl #24 */
/* @0x2472e0 .word 0xfffffb24 */
/* @0x2472e4 ldrsheq lr, [r0], -r8 */
/* @0x2472e8 .word 0xfffffb28 */
/* @0x2472ec andseq lr, r0, r8, ror #23 */
/* @0x2472f0 .word 0xfffffb2c */
/* @0x2472f4 ldrsbeq lr, [r0], -r4 */
/* @0x2472f8 .word 0xfffffb30 */
/* @0x2472fc andseq lr, r0, r4, asr #23 */
/* @0x247300 .word 0xfffffb34 */
/* @0x247304 ldrheq lr, [r0], -r8 */
/* @0x247308 .word 0xfffffb38 */
/* @0x24730c andseq lr, r0, r12, lsr #23 */
/* @0x247310 .word 0xfffffb3c */
/* @0x247314 mulseq r0, r12, r11 */
/* @0x247318 .word 0xfffffb40 */
/* @0x24731c mulseq r0, r4, r11 */
/* @0x247320 .word 0xfffffb44 */
/* @0x247324 andseq lr, r0, r12, lsl #23 */
/* @0x247328 .word 0xfffffb48 */
/* @0x24732c andseq lr, r0, r0, lsl #23 */
/* @0x247330 .word 0xfffffb4c */
/* @0x247334 andseq lr, r0, r4, ror r11 */
/* @0x247338 .word 0xfffffb50 */
/* @0x24733c andseq lr, r0, r4, ror #22 */
/* @0x247340 .word 0xfffffb54 */
/* @0x247344 andseq lr, r0, r4, asr r11 */
/* @0x247348 .word 0xfffffb58 */
/* @0x24734c andseq lr, r0, r4, asr #22 */
/* @0x247350 .word 0xfffffb5c */
/* @0x247354 andseq lr, r0, r8, lsr r11 */
/* @0x247358 .word 0xfffffb60 */
/* @0x24735c andseq lr, r0, r12, lsr #22 */
/* @0x247360 .word 0xfffffb64 */
/* @0x247364 andseq lr, r0, r0, lsr #22 */
/* @0x247368 .word 0xfffffb68 */
/* @0x24736c andseq lr, r0, r4, lsl r11 */
/* @0x247370 .word 0xfffffb6c */
/* @0x247374 andseq lr, r0, r8, lsl #22 */
/* @0x247378 .word 0xfffffb70 */
/* @0x24737c andseq lr, r0, r0, lsl #22 */
/* @0x247380 .word 0xfffffb74 */
/* @0x247384 andseq lr, r0, r0, lsl #22 */

/* ── FUNC 0x247388 · F_JS_ToObject(RValue&, RValue*) · size=704 · insn=176 */
/* @0x247388 push {r4, r5, r6, r7, lr} */
/* @0x24738c mov r4, r1 */
/* @0x247390 ldr r1, [r1, #0xc] */
/* @0x247394 sub sp, sp, #12 */
/* @0x247398 mov r5, r0 */
/* @0x24739c bic r3, r1, #-16777216 */
/* @0x2473a0 cmp r3, #13 */
/* @0x2473a4 addls pc, pc, r3, lsl #2 */
/* @0x2473a8 b 0x2474f4 <_Z13F_JS_ToObjectR6RValuePS_+0x16c> */
/* @0x2473ac b 0x2474b4 <_Z13F_JS_ToObjectR6RValuePS_+0x12c> */
/* @0x2473b0 b 0x2474d4 <_Z13F_JS_ToObjectR6RValuePS_+0x14c> */
/* @0x2473b4 b 0x2474f4 <_Z13F_JS_ToObjectR6RValuePS_+0x16c> */
/* @0x2473b8 b 0x2474f4 <_Z13F_JS_ToObjectR6RValuePS_+0x16c> */
/* @0x2473bc b 0x2474f4 <_Z13F_JS_ToObjectR6RValuePS_+0x16c> */
/* @0x2473c0 b 0x2473e4 <_Z13F_JS_ToObjectR6RValuePS_+0x5c> */
/* @0x2473c4 b 0x2473f0 <_Z13F_JS_ToObjectR6RValuePS_+0x68> */
/* @0x2473c8 b 0x247494 <_Z13F_JS_ToObjectR6RValuePS_+0x10c> */
/* @0x2473cc b 0x2474f4 <_Z13F_JS_ToObjectR6RValuePS_+0x16c> */
/* @0x2473d0 b 0x2474f4 <_Z13F_JS_ToObjectR6RValuePS_+0x16c> */
/* @0x2473d4 b 0x247494 <_Z13F_JS_ToObjectR6RValuePS_+0x10c> */
/* @0x2473d8 b 0x2474f4 <_Z13F_JS_ToObjectR6RValuePS_+0x16c> */
/* @0x2473dc b 0x2473e4 <_Z13F_JS_ToObjectR6RValuePS_+0x5c> */
/* @0x2473e0 b 0x247494 <_Z13F_JS_ToObjectR6RValuePS_+0x10c> */
/* @0x2473e4 mov r0, #1 */
/* @0x2473e8 add sp, sp, #12 */
/* @0x2473ec pop {r4, r5, r6, r7, pc} */
/* @0x2473f0 ldr r2, [r0, #0xc] */
/* @0x2473f4 bic r3, r2, #-16777216 */
/* @0x2473f8 cmp r3, #1 */
/* @0x2473fc beq 0x24751c <_Z13F_JS_ToObjectR6RValuePS_+0x194> */
/* @0x247400 cmp r3, #2 */
/* @0x247404 bne 0x247430 <_Z13F_JS_ToObjectR6RValuePS_+0xa8> */
/* @0x247408 sub r3, r2, #1 */
/* @0x24740c bic r3, r3, #-16777216 */
/* @0x247410 bic r3, r3, #3 */
/* @0x247414 cmp r3, #0 */
/* @0x247418 beq 0x2475e4 <_Z13F_JS_ToObjectR6RValuePS_+0x25c> */
/* @0x24741c mov r2, #5 */
/* @0x247420 str r2, [r5, #0xc] */
/* @0x247424 ldr r1, [r4, #0xc] */
/* @0x247428 mov r3, #0 */
/* @0x24742c str r3, [r5, #0x8] */
/* @0x247430 str r1, [r5, #0xc] */
/* @0x247434 mov r1, #0 */
/* @0x247438 ldr r3, [r4, #0xc] */
/* @0x24743c ldr r2, [r4, #0x8] */
/* @0x247440 bic r3, r3, #-16777216 */
/* @0x247444 str r1, [r5] */
/* @0x247448 str r2, [r5, #0x8] */
/* @0x24744c cmp r3, #14 */
/* @0x247450 addls pc, pc, r3, lsl #2 */
/* @0x247454 b 0x2475bc <_Z13F_JS_ToObjectR6RValuePS_+0x234> */
/* @0x247458 b 0x247554 <_Z13F_JS_ToObjectR6RValuePS_+0x1cc> */
/* @0x24745c b 0x2475c4 <_Z13F_JS_ToObjectR6RValuePS_+0x23c> */
/* @0x247460 b 0x247590 <_Z13F_JS_ToObjectR6RValuePS_+0x208> */
/* @0x247464 b 0x24750c <_Z13F_JS_ToObjectR6RValuePS_+0x184> */
/* @0x247468 b 0x2475bc <_Z13F_JS_ToObjectR6RValuePS_+0x234> */
/* @0x24746c b 0x2475bc <_Z13F_JS_ToObjectR6RValuePS_+0x234> */
/* @0x247470 b 0x247568 <_Z13F_JS_ToObjectR6RValuePS_+0x1e0> */
/* @0x247474 b 0x24750c <_Z13F_JS_ToObjectR6RValuePS_+0x184> */
/* @0x247478 b 0x2475bc <_Z13F_JS_ToObjectR6RValuePS_+0x234> */
/* @0x24747c b 0x2475bc <_Z13F_JS_ToObjectR6RValuePS_+0x234> */
/* @0x247480 b 0x247554 <_Z13F_JS_ToObjectR6RValuePS_+0x1cc> */
/* @0x247484 b 0x2475bc <_Z13F_JS_ToObjectR6RValuePS_+0x234> */
/* @0x247488 b 0x2475bc <_Z13F_JS_ToObjectR6RValuePS_+0x234> */
/* @0x24748c b 0x247554 <_Z13F_JS_ToObjectR6RValuePS_+0x1cc> */
/* @0x247490 b 0x24750c <_Z13F_JS_ToObjectR6RValuePS_+0x184> */
/* @0x247494 mov r1, #0 */
/* @0x247498 str r4, [sp] */
/* @0x24749c mov r2, r1 */
/* @0x2474a0 mov r3, #1 */
/* @0x2474a4 bl 0x2405dc <_Z20F_JSBooleanConstructR6RValueP9CInstanceS2_iPS_> */
/* @0x2474a8 mov r0, #0 */
/* @0x2474ac add sp, sp, #12 */
/* @0x2474b0 pop {r4, r5, r6, r7, pc} */
/* @0x2474b4 mov r1, #0 */
/* @0x2474b8 str r4, [sp] */
/* @0x2474bc mov r2, r1 */
/* @0x2474c0 mov r3, #1 */
/* @0x2474c4 bl 0x24dc90 <_Z21JS_Number_ConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x2474c8 mov r0, #0 */
/* @0x2474cc add sp, sp, #12 */
/* @0x2474d0 pop {r4, r5, r6, r7, pc} */
/* @0x2474d4 mov r1, #0 */
/* @0x2474d8 str r4, [sp] */
/* @0x2474dc mov r2, r1 */
/* @0x2474e0 mov r3, #1 */
/* @0x2474e4 bl 0x2583e4 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_> */
/* @0x2474e8 mov r0, #0 */
/* @0x2474ec add sp, sp, #12 */
/* @0x2474f0 pop {r4, r5, r6, r7, pc} */
/* @0x2474f4 ldr r0, [pc, #0x148] */
/* @0x2474f8 add r0, pc, r0 */
/* @0x2474fc bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x247500 mov r0, #1 */
/* @0x247504 add sp, sp, #12 */
/* @0x247508 pop {r4, r5, r6, r7, pc} */
/* @0x24750c ldr r3, [r4] */
/* @0x247510 mov r0, #0 */
/* @0x247514 str r3, [r5] */
/* @0x247518 b 0x2473e8 <_Z13F_JS_ToObjectR6RValuePS_+0x60> */
/* @0x24751c ldr r6, [r0] */
/* @0x247520 cmp r6, #0 */
/* @0x247524 beq 0x247548 <_Z13F_JS_ToObjectR6RValuePS_+0x1c0> */
/* @0x247528 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24752c ldr r7, [r6, #0x4] */
/* @0x247530 sub r7, r7, #1 */
/* @0x247534 str r7, [r6, #0x4] */
/* @0x247538 cmp r7, #0 */
/* @0x24753c beq 0x2475ec <_Z13F_JS_ToObjectR6RValuePS_+0x264> */
/* @0x247540 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x247544 ldr r1, [r4, #0xc] */
/* @0x247548 mov r3, #0 */
/* @0x24754c str r3, [r5] */
/* @0x247550 b 0x247430 <_Z13F_JS_ToObjectR6RValuePS_+0xa8> */
/* @0x247554 ldr r2, [r4] */
/* @0x247558 mov r0, #0 */
/* @0x24755c ldr r3, [r4, #0x4] */
/* @0x247560 stm r5, {r2, r3} */
/* @0x247564 b 0x2473e8 <_Z13F_JS_ToObjectR6RValuePS_+0x60> */
/* @0x247568 ldr r3, [r4] */
/* @0x24756c str r3, [r5] */
/* @0x247570 ldr r3, [r4] */
/* @0x247574 cmp r3, #0 */
/* @0x247578 beq 0x2475bc <_Z13F_JS_ToObjectR6RValuePS_+0x234> */
/* @0x24757c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x247580 ldr r1, [r4] */
/* @0x247584 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x247588 mov r0, #0 */
/* @0x24758c b 0x2473e8 <_Z13F_JS_ToObjectR6RValuePS_+0x60> */
/* @0x247590 ldr r3, [r4] */
/* @0x247594 cmp r3, #0 */
/* @0x247598 str r3, [r5] */
/* @0x24759c beq 0x2475bc <_Z13F_JS_ToObjectR6RValuePS_+0x234> */
/* @0x2475a0 ldr r0, [r3, #0x8] */
/* @0x2475a4 ldr r2, [r3] */
/* @0x2475a8 cmp r0, #0 */
/* @0x2475ac streq r5, [r3, #0x8] */
/* @0x2475b0 add r2, r2, #1 */
/* @0x2475b4 str r2, [r3] */
/* @0x2475b8 beq 0x2473e8 <_Z13F_JS_ToObjectR6RValuePS_+0x60> */
/* @0x2475bc mov r0, #0 */
/* @0x2475c0 b 0x2473e8 <_Z13F_JS_ToObjectR6RValuePS_+0x60> */
/* @0x2475c4 ldr r3, [r4] */
/* @0x2475c8 mov r0, #0 */
/* @0x2475cc cmp r3, #0 */
/* @0x2475d0 ldrne r2, [r3, #0x4] */
/* @0x2475d4 addne r2, r2, #1 */
/* @0x2475d8 strne r2, [r3, #0x4] */
/* @0x2475dc str r3, [r5] */
/* @0x2475e0 b 0x2473e8 <_Z13F_JS_ToObjectR6RValuePS_+0x60> */
/* @0x2475e4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2475e8 b 0x24741c <_Z13F_JS_ToObjectR6RValuePS_+0x94> */
/* @0x2475ec ldr r0, [r6] */
/* @0x2475f0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2475f4 str r7, [r6] */
/* @0x2475f8 str r7, [r6, #0x8] */
/* @0x2475fc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x247600 ldr r7, [r6, #0x4] */
/* @0x247604 sub r7, r7, #1 */
/* @0x247608 str r7, [r6, #0x4] */
/* @0x24760c cmp r7, #0 */
/* @0x247610 bne 0x247634 <_Z13F_JS_ToObjectR6RValuePS_+0x2ac> */
/* @0x247614 ldr r0, [r6] */
/* @0x247618 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24761c mov r0, r6 */
/* @0x247620 str r7, [r6] */
/* @0x247624 str r7, [r6, #0x8] */
/* @0x247628 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x24762c mov r0, r6 */
/* @0x247630 bl 0x27d1d0 <_ZdlPv> */
/* @0x247634 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x247638 mov r0, r6 */
/* @0x24763c bl 0x27d1d0 <_ZdlPv> */
/* @0x247640 b 0x247540 <_Z13F_JS_ToObjectR6RValuePS_+0x1b8> */
/* @0x247644 ldrsbeq lr, [r0], -r4 */

/* ── FUNC 0x247648 · F_JSToObject(RValue&, CInstance*, CInstance*, int, RValue*) · size=700 · insn=175 */
/* @0x247648 push {r4, r5, r6, r7, lr} */
/* @0x24764c sub sp, sp, #12 */
/* @0x247650 mov r5, r0 */
/* @0x247654 ldr r4, [sp, #0x20] */
/* @0x247658 ldr r1, [r4, #0xc] */
/* @0x24765c cmp r1, #13 */
/* @0x247660 addls pc, pc, r1, lsl #2 */
/* @0x247664 b 0x2477a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x247668 b 0x24776c <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x24766c b 0x247788 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x247670 b 0x2477a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x247674 b 0x2477a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x247678 b 0x2477a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x24767c b 0x2476a0 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x247680 b 0x2476ac <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x247684 b 0x24776c <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x247688 b 0x2477a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x24768c b 0x2477a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x247690 b 0x2477a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x247694 b 0x2477a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x247698 b 0x2476a0 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x24769c b 0x247750 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x2476a0 mov r0, #1 */
/* @0x2476a4 add sp, sp, #12 */
/* @0x2476a8 pop {r4, r5, r6, r7, pc} */
/* @0x2476ac ldr r2, [r0, #0xc] */
/* @0x2476b0 bic r3, r2, #-16777216 */
/* @0x2476b4 cmp r3, #1 */
/* @0x2476b8 beq 0x2477d4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0x2476bc cmp r3, #2 */
/* @0x2476c0 bne 0x2477cc <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x2476c4 sub r3, r2, #1 */
/* @0x2476c8 bic r3, r3, #-16777216 */
/* @0x2476cc bic r3, r3, #3 */
/* @0x2476d0 cmp r3, #0 */
/* @0x2476d4 beq 0x2478a0 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x258> */
/* @0x2476d8 mov r3, #0 */
/* @0x2476dc mov r2, #5 */
/* @0x2476e0 str r3, [r5, #0x8] */
/* @0x2476e4 str r2, [r5, #0xc] */
/* @0x2476e8 ldr r3, [r4, #0xc] */
/* @0x2476ec ldr r2, [r4, #0x8] */
/* @0x2476f0 mov r1, #0 */
/* @0x2476f4 str r3, [r5, #0xc] */
/* @0x2476f8 ldr r3, [r4, #0xc] */
/* @0x2476fc str r1, [r5] */
/* @0x247700 bic r3, r3, #-16777216 */
/* @0x247704 str r2, [r5, #0x8] */
/* @0x247708 cmp r3, #14 */
/* @0x24770c addls pc, pc, r3, lsl #2 */
/* @0x247710 b 0x247878 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x230> */
/* @0x247714 b 0x247810 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x247718 b 0x247880 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x238> */
/* @0x24771c b 0x24784c <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x204> */
/* @0x247720 b 0x2477bc <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x247724 b 0x247878 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x230> */
/* @0x247728 b 0x247878 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x230> */
/* @0x24772c b 0x247824 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x1dc> */
/* @0x247730 b 0x2477bc <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x247734 b 0x247878 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x230> */
/* @0x247738 b 0x247878 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x230> */
/* @0x24773c b 0x247810 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x247740 b 0x247878 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x230> */
/* @0x247744 b 0x247878 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x230> */
/* @0x247748 b 0x247810 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x24774c b 0x2477bc <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x247750 mov r1, #0 */
/* @0x247754 str r4, [sp] */
/* @0x247758 mov r2, r1 */
/* @0x24775c bl 0x2405dc <_Z20F_JSBooleanConstructR6RValueP9CInstanceS2_iPS_> */
/* @0x247760 mov r0, #0 */
/* @0x247764 add sp, sp, #12 */
/* @0x247768 pop {r4, r5, r6, r7, pc} */
/* @0x24776c mov r1, #0 */
/* @0x247770 str r4, [sp] */
/* @0x247774 mov r2, r1 */
/* @0x247778 bl 0x24dc90 <_Z21JS_Number_ConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x24777c mov r0, #0 */
/* @0x247780 add sp, sp, #12 */
/* @0x247784 pop {r4, r5, r6, r7, pc} */
/* @0x247788 mov r1, #0 */
/* @0x24778c str r4, [sp] */
/* @0x247790 mov r2, r1 */
/* @0x247794 bl 0x2583e4 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_> */
/* @0x247798 mov r0, #0 */
/* @0x24779c add sp, sp, #12 */
/* @0x2477a0 pop {r4, r5, r6, r7, pc} */
/* @0x2477a4 ldr r0, [pc, #0x154] */
/* @0x2477a8 add r0, pc, r0 */
/* @0x2477ac bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x2477b0 mov r0, #0 */
/* @0x2477b4 add sp, sp, #12 */
/* @0x2477b8 pop {r4, r5, r6, r7, pc} */
/* @0x2477bc ldr r3, [r4] */
/* @0x2477c0 mov r0, #0 */
/* @0x2477c4 str r3, [r5] */
/* @0x2477c8 b 0x2476a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x2477cc mov r3, #6 */
/* @0x2477d0 b 0x2476ec <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x2477d4 ldr r6, [r0] */
/* @0x2477d8 cmp r6, #0 */
/* @0x2477dc moveq r3, #6 */
/* @0x2477e0 beq 0x247804 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x1bc> */
/* @0x2477e4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2477e8 ldr r7, [r6, #0x4] */
/* @0x2477ec sub r7, r7, #1 */
/* @0x2477f0 str r7, [r6, #0x4] */
/* @0x2477f4 cmp r7, #0 */
/* @0x2477f8 beq 0x2478a8 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x260> */
/* @0x2477fc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x247800 ldr r3, [r4, #0xc] */
/* @0x247804 mov r2, #0 */
/* @0x247808 str r2, [r5] */
/* @0x24780c b 0x2476ec <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x247810 ldr r2, [r4] */
/* @0x247814 mov r0, #0 */
/* @0x247818 ldr r3, [r4, #0x4] */
/* @0x24781c stm r5, {r2, r3} */
/* @0x247820 b 0x2476a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x247824 ldr r3, [r4] */
/* @0x247828 str r3, [r5] */
/* @0x24782c ldr r3, [r4] */
/* @0x247830 cmp r3, #0 */
/* @0x247834 beq 0x247878 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x230> */
/* @0x247838 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x24783c ldr r1, [r4] */
/* @0x247840 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x247844 mov r0, #0 */
/* @0x247848 b 0x2476a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x24784c ldr r3, [r4] */
/* @0x247850 cmp r3, #0 */
/* @0x247854 str r3, [r5] */
/* @0x247858 beq 0x247878 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x230> */
/* @0x24785c ldr r0, [r3, #0x8] */
/* @0x247860 ldr r2, [r3] */
/* @0x247864 cmp r0, #0 */
/* @0x247868 streq r5, [r3, #0x8] */
/* @0x24786c add r2, r2, #1 */
/* @0x247870 str r2, [r3] */
/* @0x247874 beq 0x2476a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x247878 mov r0, #0 */
/* @0x24787c b 0x2476a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x247880 ldr r3, [r4] */
/* @0x247884 mov r0, #0 */
/* @0x247888 cmp r3, #0 */
/* @0x24788c ldrne r2, [r3, #0x4] */
/* @0x247890 addne r2, r2, #1 */
/* @0x247894 strne r2, [r3, #0x4] */
/* @0x247898 str r3, [r5] */
/* @0x24789c b 0x2476a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x2478a0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2478a4 b 0x2476d8 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x2478a8 ldr r0, [r6] */
/* @0x2478ac bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2478b0 str r7, [r6] */
/* @0x2478b4 str r7, [r6, #0x8] */
/* @0x2478b8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2478bc ldr r7, [r6, #0x4] */
/* @0x2478c0 sub r7, r7, #1 */
/* @0x2478c4 str r7, [r6, #0x4] */
/* @0x2478c8 cmp r7, #0 */
/* @0x2478cc bne 0x2478f0 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x2a8> */
/* @0x2478d0 ldr r0, [r6] */
/* @0x2478d4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2478d8 mov r0, r6 */
/* @0x2478dc str r7, [r6] */
/* @0x2478e0 str r7, [r6, #0x8] */
/* @0x2478e4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x2478e8 mov r0, r6 */
/* @0x2478ec bl 0x27d1d0 <_ZdlPv> */
/* @0x2478f0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2478f4 mov r0, r6 */
/* @0x2478f8 bl 0x27d1d0 <_ZdlPv> */
/* @0x2478fc b 0x2477fc <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x247900 andseq lr, r0, r12, asr #12 */
