/* libyoyo.so 覆盖卡组 0294
 * 函数 0x319110..0x3195f4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x319110 · __aeabi_f2d · size=64 · insn=16 */
/* @0x319110 lsls r2, r0, #1 */
/* @0x319114 asr r1, r2, #3 */
/* @0x319118 rrx r1, r1 */
/* @0x31911c lsl r0, r2, #28 */
/* @0x319120 andsne r3, r2, #-16777216 */
/* @0x319124 teqne r3, #-16777216 */
/* @0x319128 eorne r1, r1, #939524096 */
/* @0x31912c bxne lr */
/* @0x319130 teq r2, #0 */
/* @0x319134 teqne r3, #-16777216 */
/* @0x319138 bxeq lr */
/* @0x31913c push {r4, r5, lr} */
/* @0x319140 mov r4, #896 */
/* @0x319144 and r5, r1, #-2147483648 */
/* @0x319148 bic r1, r1, #-2147483648 */
/* @0x31914c b 0x318f60 <__aeabi_dadd+0x148> */

/* ── FUNC 0x319110 · __extendsfdf2 · alias of the symbol above · insn=0 */

/* ── FUNC 0x319150 · __aeabi_ul2d · size=116 · insn=5 */
/* @0x319150 orrs r2, r0, r1 */
/* @0x319154 bxeq lr */
/* @0x319158 push {r4, r5, lr} */
/* @0x31915c mov r5, #0 */
/* @0x319160 b 0x319180 <__floatdidf+0x1c> */

/* ── FUNC 0x319150 · __floatundidf · alias of the symbol above · insn=0 */

/* ── FUNC 0x319164 · __aeabi_l2d · size=96 · insn=24 */
/* @0x319164 orrs r2, r0, r1 */
/* @0x319168 bxeq lr */
/* @0x31916c push {r4, r5, lr} */
/* @0x319170 ands r5, r1, #-2147483648 */
/* @0x319174 bpl 0x319180 <__floatdidf+0x1c> */
/* @0x319178 rsbs r0, r0, #0 */
/* @0x31917c rsc r1, r1, #0 */
/* @0x319180 mov r4, #1024 */
/* @0x319184 add r4, r4, #50 */
/* @0x319188 lsrs r12, r1, #22 */
/* @0x31918c beq 0x318f04 <__aeabi_dadd+0xec> */
/* @0x319190 mov r2, #3 */
/* @0x319194 lsrs r12, r12, #3 */
/* @0x319198 addne r2, r2, #3 */
/* @0x31919c lsrs r12, r12, #3 */
/* @0x3191a0 addne r2, r2, #3 */
/* @0x3191a4 add r2, r2, r12, lsr #3 */
/* @0x3191a8 rsb r3, r2, #32 */
/* @0x3191ac lsl r12, r0, r3 */
/* @0x3191b0 lsr r0, r0, r2 */
/* @0x3191b4 orr r0, r0, r1, lsl r3 */
/* @0x3191b8 lsr r1, r1, r2 */
/* @0x3191bc add r4, r4, r2 */
/* @0x3191c0 b 0x318f04 <__aeabi_dadd+0xec> */

/* ── FUNC 0x319164 · __floatdidf · alias of the symbol above · insn=0 */

/* ── FUNC 0x3191c4 · __aeabi_frsub · size=412 · insn=2 */
/* @0x3191c4 eor r0, r0, #-2147483648 */
/* @0x3191c8 b 0x3191d0 <__aeabi_fadd> */

/* ── FUNC 0x3191cc · __aeabi_fsub · size=404 · insn=1 */
/* @0x3191cc eor r1, r1, #-2147483648 */

/* ── FUNC 0x3191cc · __subsf3 · alias of the symbol above · insn=0 */

/* ── FUNC 0x3191d0 · __addsf3 · size=400 · insn=100 */
/* @0x3191d0 lsls r2, r0, #1 */
/* @0x3191d4 lslsne r3, r1, #1 */
/* @0x3191d8 teqne r2, r3 */
/* @0x3191dc mvnsne r12, r2, asr #24 */
/* @0x3191e0 mvnsne r12, r3, asr #24 */
/* @0x3191e4 beq 0x3192dc <__aeabi_fadd+0x10c> */
/* @0x3191e8 lsr r2, r2, #24 */
/* @0x3191ec rsbs r3, r2, r3, lsr #24 */
/* @0x3191f0 addgt r2, r2, r3 */
/* @0x3191f4 eorgt r1, r0, r1 */
/* @0x3191f8 eorgt r0, r1, r0 */
/* @0x3191fc eorgt r1, r0, r1 */
/* @0x319200 rsblt r3, r3, #0 */
/* @0x319204 cmp r3, #25 */
/* @0x319208 bxhi lr */
/* @0x31920c tst r0, #-2147483648 */
/* @0x319210 orr r0, r0, #8388608 */
/* @0x319214 bic r0, r0, #-16777216 */
/* @0x319218 rsbne r0, r0, #0 */
/* @0x31921c tst r1, #-2147483648 */
/* @0x319220 orr r1, r1, #8388608 */
/* @0x319224 bic r1, r1, #-16777216 */
/* @0x319228 rsbne r1, r1, #0 */
/* @0x31922c teq r2, r3 */
/* @0x319230 beq 0x3192c4 <__aeabi_fadd+0xf4> */
/* @0x319234 sub r2, r2, #1 */
/* @0x319238 adds r0, r0, r1, asr r3 */
/* @0x31923c rsb r3, r3, #32 */
/* @0x319240 lsl r1, r1, r3 */
/* @0x319244 and r3, r0, #-2147483648 */
/* @0x319248 bpl 0x319254 <__aeabi_fadd+0x84> */
/* @0x31924c rsbs r1, r1, #0 */
/* @0x319250 rsc r0, r0, #0 */
/* @0x319254 cmp r0, #8388608 */
/* @0x319258 blo 0x31928c <__aeabi_fadd+0xbc> */
/* @0x31925c cmp r0, #16777216 */
/* @0x319260 blo 0x319278 <__aeabi_fadd+0xa8> */
/* @0x319264 lsrs r0, r0, #1 */
/* @0x319268 rrx r1, r1 */
/* @0x31926c add r2, r2, #1 */
/* @0x319270 cmp r2, #254 */
/* @0x319274 bhs 0x319330 <__aeabi_fadd+0x160> */
/* @0x319278 cmp r1, #-2147483648 */
/* @0x31927c adc r0, r0, r2, lsl #23 */
/* @0x319280 biceq r0, r0, #1 */
/* @0x319284 orr r0, r0, r3 */
/* @0x319288 bx lr */
/* @0x31928c lsls r1, r1, #1 */
/* @0x319290 adc r0, r0, r0 */
/* @0x319294 tst r0, #8388608 */
/* @0x319298 sub r2, r2, #1 */
/* @0x31929c bne 0x319278 <__aeabi_fadd+0xa8> */
/* @0x3192a0 clz r12, r0 */
/* @0x3192a4 sub r12, r12, #8 */
/* @0x3192a8 subs r2, r2, r12 */
/* @0x3192ac lsl r0, r0, r12 */
/* @0x3192b0 addge r0, r0, r2, lsl #23 */
/* @0x3192b4 rsblt r2, r2, #0 */
/* @0x3192b8 orrge r0, r0, r3 */
/* @0x3192bc orrlt r0, r3, r0, lsr r2 */
/* @0x3192c0 bx lr */
/* @0x3192c4 teq r2, #0 */
/* @0x3192c8 eor r1, r1, #8388608 */
/* @0x3192cc eoreq r0, r0, #8388608 */
/* @0x3192d0 addeq r2, r2, #1 */
/* @0x3192d4 subne r3, r3, #1 */
/* @0x3192d8 b 0x319234 <__aeabi_fadd+0x64> */
/* @0x3192dc lsl r3, r1, #1 */
/* @0x3192e0 mvns r12, r2, asr #24 */
/* @0x3192e4 mvnsne r12, r3, asr #24 */
/* @0x3192e8 beq 0x31933c <__aeabi_fadd+0x16c> */
/* @0x3192ec teq r2, r3 */
/* @0x3192f0 beq 0x319300 <__aeabi_fadd+0x130> */
/* @0x3192f4 teq r2, #0 */
/* @0x3192f8 moveq r0, r1 */
/* @0x3192fc bx lr */
/* @0x319300 teq r0, r1 */
/* @0x319304 movne r0, #0 */
/* @0x319308 bxne lr */
/* @0x31930c tst r2, #-16777216 */
/* @0x319310 bne 0x319320 <__aeabi_fadd+0x150> */
/* @0x319314 lsls r0, r0, #1 */
/* @0x319318 orrhs r0, r0, #-2147483648 */
/* @0x31931c bx lr */
/* @0x319320 adds r2, r2, #33554432 */
/* @0x319324 addlo r0, r0, #8388608 */
/* @0x319328 bxlo lr */
/* @0x31932c and r3, r0, #-2147483648 */
/* @0x319330 orr r0, r3, #2130706432 */
/* @0x319334 orr r0, r0, #8388608 */
/* @0x319338 bx lr */
/* @0x31933c mvns r2, r2, asr #24 */
/* @0x319340 movne r0, r1 */
/* @0x319344 mvnseq r3, r3, asr #24 */
/* @0x319348 movne r1, r0 */
/* @0x31934c lsls r2, r0, #9 */
/* @0x319350 lslseq r3, r1, #9 */
/* @0x319354 teqeq r0, r1 */
/* @0x319358 orrne r0, r0, #4194304 */
/* @0x31935c bx lr */

/* ── FUNC 0x3191d0 · __aeabi_fadd · alias of the symbol above · insn=0 */

/* ── FUNC 0x319360 · __aeabi_ui2f · size=40 · insn=2 */
/* @0x319360 mov r3, #0 */
/* @0x319364 b 0x319370 <__floatsisf+0x8> */

/* ── FUNC 0x319360 · __floatunsisf · alias of the symbol above · insn=0 */

/* ── FUNC 0x319368 · __aeabi_i2f · size=32 · insn=8 */
/* @0x319368 ands r3, r0, #-2147483648 */
/* @0x31936c rsbmi r0, r0, #0 */
/* @0x319370 movs r12, r0 */
/* @0x319374 bxeq lr */
/* @0x319378 orr r3, r3, #1258291200 */
/* @0x31937c mov r1, r0 */
/* @0x319380 mov r0, #0 */
/* @0x319384 b 0x3193c8 <__floatdisf+0x30> */

/* ── FUNC 0x319368 · __floatsisf · alias of the symbol above · insn=0 */

/* ── FUNC 0x319388 · __aeabi_ul2f · size=140 · insn=4 */
/* @0x319388 orrs r2, r0, r1 */
/* @0x31938c bxeq lr */
/* @0x319390 mov r3, #0 */
/* @0x319394 b 0x3193b0 <__floatdisf+0x18> */

/* ── FUNC 0x319388 · __floatundisf · alias of the symbol above · insn=0 */

/* ── FUNC 0x319398 · __aeabi_l2f · size=124 · insn=31 */
/* @0x319398 orrs r2, r0, r1 */
/* @0x31939c bxeq lr */
/* @0x3193a0 ands r3, r1, #-2147483648 */
/* @0x3193a4 bpl 0x3193b0 <__floatdisf+0x18> */
/* @0x3193a8 rsbs r0, r0, #0 */
/* @0x3193ac rsc r1, r1, #0 */
/* @0x3193b0 movs r12, r1 */
/* @0x3193b4 moveq r12, r0 */
/* @0x3193b8 moveq r1, r0 */
/* @0x3193bc moveq r0, #0 */
/* @0x3193c0 orr r3, r3, #1526726656 */
/* @0x3193c4 subeq r3, r3, #268435456 */
/* @0x3193c8 sub r3, r3, #8388608 */
/* @0x3193cc clz r2, r12 */
/* @0x3193d0 subs r2, r2, #8 */
/* @0x3193d4 sub r3, r3, r2, lsl #23 */
/* @0x3193d8 blt 0x3193f8 <__floatdisf+0x60> */
/* @0x3193dc add r3, r3, r1, lsl r2 */
/* @0x3193e0 lsl r12, r0, r2 */
/* @0x3193e4 rsb r2, r2, #32 */
/* @0x3193e8 cmp r12, #-2147483648 */
/* @0x3193ec adc r0, r3, r0, lsr r2 */
/* @0x3193f0 biceq r0, r0, #1 */
/* @0x3193f4 bx lr */
/* @0x3193f8 add r2, r2, #32 */
/* @0x3193fc lsl r12, r1, r2 */
/* @0x319400 rsb r2, r2, #32 */
/* @0x319404 orrs r0, r0, r12, lsl #1 */
/* @0x319408 adc r0, r3, r1, lsr r2 */
/* @0x31940c biceq r0, r0, r12, lsr #31 */
/* @0x319410 bx lr */

/* ── FUNC 0x319398 · __floatdisf · alias of the symbol above · insn=0 */

/* ── FUNC 0x319414 · anon_319414 · size=64 · insn=17 */
/* @0x319414 cmp r3, #0 */
/* @0x319418 cmpeq r2, #0 */
/* @0x31941c bne 0x31943c <__aeabi_ldivmod+0x28> */
/* @0x319420 cmp r1, #0 */
/* @0x319424 cmpeq r0, #0 */
/* @0x319428 movlt r1, #-2147483648 */
/* @0x31942c movlt r0, #0 */
/* @0x319430 mvngt r1, #-2147483648 */
/* @0x319434 mvngt r0, #0 */
/* @0x319438 b 0x319458 <__aeabi_ldiv0> */
/* @0x31943c sub sp, sp, #8 */
/* @0x319440 push {sp, lr} */
/* @0x319444 bl 0x3195b8 <__gnu_ldivmod_helper> */
/* @0x319448 ldr lr, [sp, #0x4] */
/* @0x31944c add sp, sp, #8 */
/* @0x319450 pop {r2, r3} */
/* @0x319454 bx lr */

/* ── FUNC 0x319458 · __aeabi_idiv0 · size=16 · insn=4 */
/* @0x319458 push {r1, lr} */
/* @0x31945c mov r0, #8 */
/* @0x319460 bl 0xb6fb8 <raise@plt> */
/* @0x319464 pop {r1, pc} */

/* ── FUNC 0x319458 · __aeabi_ldiv0 · alias of the symbol above · insn=0 */

/* ── FUNC 0x319468 · __aeabi_f2lz · size=56 · insn=14 */
/* @0x319468 push {r4, lr} */
/* @0x31946c mov r1, #0 */
/* @0x319470 mov r4, r0 */
/* @0x319474 bl 0x31b1d0 <__aeabi_fcmplt> */
/* @0x319478 cmp r0, #0 */
/* @0x31947c beq 0x319494 <__fixsfdi+0x2c> */
/* @0x319480 add r0, r4, #-2147483648 */
/* @0x319484 bl 0x3194e4 <__fixunssfdi> */
/* @0x319488 rsbs r0, r0, #0 */
/* @0x31948c rsc r1, r1, #0 */
/* @0x319490 pop {r4, pc} */
/* @0x319494 mov r0, r4 */
/* @0x319498 pop {r4, lr} */
/* @0x31949c b 0x3194e4 <__fixunssfdi> */

/* ── FUNC 0x319468 · __fixsfdi · alias of the symbol above · insn=0 */

/* ── FUNC 0x3194a0 · __aeabi_d2lz · size=68 · insn=17 */
/* @0x3194a0 push {r3, r4, r5, lr} */
/* @0x3194a4 mov r2, #0 */
/* @0x3194a8 mov r3, #0 */
/* @0x3194ac mov r5, r0 */
/* @0x3194b0 mov r4, r1 */
/* @0x3194b4 bl 0x31b080 <__aeabi_dcmplt> */
/* @0x3194b8 cmp r0, #0 */
/* @0x3194bc mov r0, r5 */
/* @0x3194c0 beq 0x3194d8 <__fixdfdi+0x38> */
/* @0x3194c4 add r1, r4, #-2147483648 */
/* @0x3194c8 bl 0x319550 <__fixunsdfdi> */
/* @0x3194cc rsbs r0, r0, #0 */
/* @0x3194d0 rsc r1, r1, #0 */
/* @0x3194d4 pop {r3, r4, r5, pc} */
/* @0x3194d8 mov r1, r4 */
/* @0x3194dc pop {r3, r4, r5, lr} */
/* @0x3194e0 b 0x319550 <__fixunsdfdi> */

/* ── FUNC 0x3194a0 · __fixdfdi · alias of the symbol above · insn=0 */

/* ── FUNC 0x3194e4 · __aeabi_f2ulz · size=108 · insn=27 */
/* @0x3194e4 push {r4, r5, r6, lr} */
/* @0x3194e8 bl 0x319110 <__extendsfdf2> */
/* @0x3194ec mov r2, #0 */
/* @0x3194f0 ldr r3, [pc, #0x50] */
/* @0x3194f4 mov r4, r0 */
/* @0x3194f8 mov r5, r1 */
/* @0x3194fc bl 0x31ab34 <__muldf3> */
/* @0x319500 bl 0x31b0d0 <__fixunsdfsi> */
/* @0x319504 mov r6, r0 */
/* @0x319508 bl 0x3190c4 <__floatunsidf> */
/* @0x31950c mov r2, #0 */
/* @0x319510 ldr r3, [pc, #0x34] */
/* @0x319514 bl 0x31ab34 <__muldf3> */
/* @0x319518 mov r2, r0 */
/* @0x31951c mov r3, r1 */
/* @0x319520 mov r0, r4 */
/* @0x319524 mov r1, r5 */
/* @0x319528 bl 0x318e14 <__subdf3> */
/* @0x31952c mov r5, r6 */
/* @0x319530 bl 0x31b0d0 <__fixunsdfsi> */
/* @0x319534 mov r2, #0 */
/* @0x319538 mov r1, r6 */
/* @0x31953c orr r4, r2, r0 */
/* @0x319540 mov r0, r4 */
/* @0x319544 pop {r4, r5, r6, pc} */
/* @0x319548 ldcllo p0, c0, [r0, #0]! */
/* @0x31954c mvnsmi r0, r0 */

/* ── FUNC 0x3194e4 · __fixunssfdi · alias of the symbol above · insn=0 */

/* ── FUNC 0x319550 · __aeabi_d2ulz · size=104 · insn=26 */
/* @0x319550 push {r4, r5, r6, lr} */
/* @0x319554 mov r2, #0 */
/* @0x319558 ldr r3, [pc, #0x50] */
/* @0x31955c mov r4, r0 */
/* @0x319560 mov r5, r1 */
/* @0x319564 bl 0x31ab34 <__muldf3> */
/* @0x319568 bl 0x31b0d0 <__fixunsdfsi> */
/* @0x31956c mov r6, r0 */
/* @0x319570 bl 0x3190c4 <__floatunsidf> */
/* @0x319574 mov r2, #0 */
/* @0x319578 ldr r3, [pc, #0x34] */
/* @0x31957c bl 0x31ab34 <__muldf3> */
/* @0x319580 mov r2, r0 */
/* @0x319584 mov r3, r1 */
/* @0x319588 mov r0, r4 */
/* @0x31958c mov r1, r5 */
/* @0x319590 bl 0x318e14 <__subdf3> */
/* @0x319594 mov r5, r6 */
/* @0x319598 bl 0x31b0d0 <__fixunsdfsi> */
/* @0x31959c mov r2, #0 */
/* @0x3195a0 mov r1, r6 */
/* @0x3195a4 orr r4, r2, r0 */
/* @0x3195a8 mov r0, r4 */
/* @0x3195ac pop {r4, r5, r6, pc} */
/* @0x3195b0 ldcllo p0, c0, [r0, #0]! */
/* @0x3195b4 mvnsmi r0, r0 */

/* ── FUNC 0x319550 · __fixunsdfdi · alias of the symbol above · insn=0 */

/* ── FUNC 0x3195b8 · __gnu_ldivmod_helper · size=60 · insn=15 */
/* @0x3195b8 push {r3, r4, r5, r6, r7, lr} */
/* @0x3195bc mov r6, r2 */
/* @0x3195c0 mov r4, r0 */
/* @0x3195c4 mov r5, r1 */
/* @0x3195c8 mov r7, r3 */
/* @0x3195cc bl 0x31b220 <__divdi3> */
/* @0x3195d0 ldr r12, [sp, #0x18] */
/* @0x3195d4 mul r3, r6, r1 */
/* @0x3195d8 mla r7, r0, r7, r3 */
/* @0x3195dc umull r2, r3, r6, r0 */
/* @0x3195e0 add r3, r7, r3 */
/* @0x3195e4 subs r2, r4, r2 */
/* @0x3195e8 sbc r3, r5, r3 */
/* @0x3195ec strd r2, r3, [r12] */
/* @0x3195f0 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x3195f4 · __gnu_uldivmod_helper · size=60 · insn=15 */
/* @0x3195f4 push {r3, r4, r5, r6, r7, lr} */
/* @0x3195f8 mov r6, r2 */
/* @0x3195fc mov r4, r0 */
/* @0x319600 mov r5, r1 */
/* @0x319604 mov r7, r3 */
/* @0x319608 bl 0x31b698 <__udivdi3> */
/* @0x31960c ldr r12, [sp, #0x18] */
/* @0x319610 mul r7, r0, r7 */
/* @0x319614 umull r2, r3, r0, r6 */
/* @0x319618 mla r7, r6, r1, r7 */
/* @0x31961c add r3, r7, r3 */
/* @0x319620 subs r2, r4, r2 */
/* @0x319624 sbc r3, r5, r3 */
/* @0x319628 strd r2, r3, [r12] */
/* @0x31962c pop {r3, r4, r5, r6, r7, pc} */
