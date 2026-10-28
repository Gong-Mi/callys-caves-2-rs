/* libyoyo.so 覆盖卡组 0042
 * 函数 0x115504..0x1168c8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x115504 · F_DateHourSpan(RValue&, CInstance*, CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x115504 push {r3, r4, r5, lr} */
/* @0x115508 vpush {d8} */
/* @0x11550c mov r3, #0 */
/* @0x115510 ldr r5, [sp, #0x18] */
/* @0x115514 mov r1, r3 */
/* @0x115518 str r3, [r0, #0xc] */
/* @0x11551c mov r4, r0 */
/* @0x115520 str r3, [r0] */
/* @0x115524 str r3, [r0, #0x4] */
/* @0x115528 mov r0, r5 */
/* @0x11552c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x115530 vmov d8, r0, r1 */
/* @0x115534 mov r0, r5 */
/* @0x115538 mov r1, #1 */
/* @0x11553c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x115540 vmov.f64 d7, #2.400000e+01 */
/* @0x115544 vmov d6, r0, r1 */
/* @0x115548 vsub.f64 d8, d8, d6 */
/* @0x11554c vmul.f64 d8, d8, d7 */
/* @0x115550 vabs.f64 d7, d8 */
/* @0x115554 vmov r2, r3, d7 */
/* @0x115558 stm r4, {r2, r3} */
/* @0x11555c vpop {d8} */
/* @0x115560 pop {r3, r4, r5, pc} */

/* ── FUNC 0x115564 · anon_115564 · size=4 · insn=1 */
/* @0x115564 andeq r0, r0, r0 */

/* ── FUNC 0x115568 · F_DateMinuteSpan(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x115568 push {r3, r4, r5, lr} */
/* @0x11556c vpush {d8} */
/* @0x115570 mov r3, #0 */
/* @0x115574 ldr r5, [sp, #0x18] */
/* @0x115578 mov r1, r3 */
/* @0x11557c str r3, [r0, #0xc] */
/* @0x115580 mov r4, r0 */
/* @0x115584 str r3, [r0] */
/* @0x115588 str r3, [r0, #0x4] */
/* @0x11558c mov r0, r5 */
/* @0x115590 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x115594 vmov d8, r0, r1 */
/* @0x115598 mov r0, r5 */
/* @0x11559c mov r1, #1 */
/* @0x1155a0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1155a4 vldr d7, [pc, #28] */
/* @0x1155a8 vmov d6, r0, r1 */
/* @0x1155ac vsub.f64 d8, d8, d6 */
/* @0x1155b0 vmul.f64 d8, d8, d7 */
/* @0x1155b4 vabs.f64 d7, d8 */
/* @0x1155b8 vmov r2, r3, d7 */
/* @0x1155bc stm r4, {r2, r3} */
/* @0x1155c0 vpop {d8} */
/* @0x1155c4 pop {r3, r4, r5, pc} */
/* @0x1155c8 andeq r0, r0, r0 */
/* @0x1155cc addsmi r8, r6, r0 */

/* ── FUNC 0x1155d0 · F_DateSecondSpan(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x1155d0 push {r3, r4, r5, lr} */
/* @0x1155d4 vpush {d8} */
/* @0x1155d8 mov r3, #0 */
/* @0x1155dc ldr r5, [sp, #0x18] */
/* @0x1155e0 mov r1, r3 */
/* @0x1155e4 str r3, [r0, #0xc] */
/* @0x1155e8 mov r4, r0 */
/* @0x1155ec str r3, [r0] */
/* @0x1155f0 str r3, [r0, #0x4] */
/* @0x1155f4 mov r0, r5 */
/* @0x1155f8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1155fc vmov d8, r0, r1 */
/* @0x115600 mov r0, r5 */
/* @0x115604 mov r1, #1 */
/* @0x115608 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x11560c vldr d7, [pc, #28] */
/* @0x115610 vmov d6, r0, r1 */
/* @0x115614 vsub.f64 d8, d8, d6 */
/* @0x115618 vmul.f64 d8, d8, d7 */
/* @0x11561c vabs.f64 d7, d8 */
/* @0x115620 vmov r2, r3, d7 */
/* @0x115624 stm r4, {r2, r3} */
/* @0x115628 vpop {d8} */
/* @0x11562c pop {r3, r4, r5, pc} */
/* @0x115630 andeq r0, r0, r0 */
/* @0x115634 rscsmi r1, r5, r0, lsl #16 */

/* ── FUNC 0x115638 · F_DateCompareDateTime(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x115638 push {r3, r4, r5, lr} */
/* @0x11563c vpush {d8} */
/* @0x115640 mov r4, r0 */
/* @0x115644 ldr r5, [sp, #0x18] */
/* @0x115648 mov r1, #0 */
/* @0x11564c mov r0, r5 */
/* @0x115650 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x115654 vmov d8, r0, r1 */
/* @0x115658 mov r0, r5 */
/* @0x11565c mov r1, #1 */
/* @0x115660 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x115664 mov r3, #0 */
/* @0x115668 str r3, [r4, #0xc] */
/* @0x11566c vmov d7, r0, r1 */
/* @0x115670 vcmp.f64 d8, d7 */
/* @0x115674 vmrs APSR_nzcv, fpscr */
/* @0x115678 moveq r2, r3 */
/* @0x11567c beq 0x11569c <_Z21F_DateCompareDateTimeR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x115680 vcmpe.f64 d8, d7 */
/* @0x115684 mov r1, r3 */
/* @0x115688 mov r2, r3 */
/* @0x11568c movt r1, #0x3ff0 */
/* @0x115690 movt r2, #0xbff0 */
/* @0x115694 vmrs APSR_nzcv, fpscr */
/* @0x115698 movgt r2, r1 */
/* @0x11569c str r3, [r4] */
/* @0x1156a0 str r2, [r4, #0x4] */
/* @0x1156a4 vpop {d8} */
/* @0x1156a8 pop {r3, r4, r5, pc} */

/* ── FUNC 0x1156ac · anon_1156ac · size=4 · insn=1 */
/* @0x1156ac andeq r0, r0, r0 */

/* ── FUNC 0x1156b0 · F_DateIncYear(RValue&, CInstance*, CInstance*, int, RValue*) · size=248 · insn=62 */
/* @0x1156b0 push {r4, r5, r6, lr} */
/* @0x1156b4 sub sp, sp, #8 */
/* @0x1156b8 mov r1, #0 */
/* @0x1156bc mov r4, r0 */
/* @0x1156c0 ldr r6, [sp, #0x18] */
/* @0x1156c4 str r1, [r0, #0xc] */
/* @0x1156c8 mov r0, r6 */
/* @0x1156cc bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1156d0 vldr d7, [pc, #184] */
/* @0x1156d4 vldr d5, [pc, #188] */
/* @0x1156d8 vmov d6, r0, r1 */
/* @0x1156dc vsub.f64 d7, d6, d7 */
/* @0x1156e0 vabs.f64 d4, d7 */
/* @0x1156e4 vcmpe.f64 d4, d5 */
/* @0x1156e8 vmrs APSR_nzcv, fpscr */
/* @0x1156ec vldrls d7, [pc, #172] */
/* @0x1156f0 vldrhi d6, [pc, #168] */
/* @0x1156f4 vmulls.f64 d4, d6, d7 */
/* @0x1156f8 vmulhi.f64 d5, d7, d6 */
/* @0x1156fc vmovls r0, r1, d4 */
/* @0x115700 vmovhi r0, r1, d5 */
/* @0x115704 bl 0x3194a0 <__fixdfdi> */
/* @0x115708 mov r2, r0 */
/* @0x11570c add r0, sp, #8 */
/* @0x115710 mov r3, r1 */
/* @0x115714 strd r2, r3, [r0, #-8]! */
/* @0x115718 mov r0, sp */
/* @0x11571c bl 0xb6820 <gmtime64@plt> */
/* @0x115720 subs r5, r0, #0 */
/* @0x115724 beq 0x115778 <_Z13F_DateIncYearR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x115728 mov r0, r6 */
/* @0x11572c mov r1, #1 */
/* @0x115730 ldr r6, [r5, #0x14] */
/* @0x115734 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x115738 add r6, r6, r0 */
/* @0x11573c mov r0, r5 */
/* @0x115740 str r6, [r5, #0x14] */
/* @0x115744 bl 0xb6814 <timegm64@plt> */
/* @0x115748 bl 0x319164 <__floatdidf> */
/* @0x11574c vmov.f64 d6, #5.000000e-01 */
/* @0x115750 vldr d5, [pc, #72] */
/* @0x115754 vldr d7, [pc, #52] */
/* @0x115758 vmov d4, r0, r1 */
/* @0x11575c vadd.f64 d6, d4, d6 */
/* @0x115760 vdiv.f64 d6, d6, d5 */
/* @0x115764 vadd.f64 d5, d6, d7 */
/* @0x115768 vmov r2, r3, d5 */
/* @0x11576c stm r4, {r2, r3} */
/* @0x115770 add sp, sp, #8 */
/* @0x115774 pop {r4, r5, r6, pc} */
/* @0x115778 str r5, [r4] */
/* @0x11577c mov r3, #0 */
/* @0x115780 movt r3, #0xbff0 */
/* @0x115784 str r3, [r4, #0x4] */
/* @0x115788 add sp, sp, #8 */
/* @0x11578c pop {r4, r5, r6, pc} */
/* @0x115790 andeq r0, r0, r0 */
/* @0x115794 sbcsmi pc, r8, r0, asr #16 */
/* @0x115798 bl 0x826454 <b2_toiTime+0xccfb0> */
/* @0x11579c svclo #0x1a36e2 */
/* @0x1157a0 andeq r0, r0, r0 */
/* @0x1157a4 rscsmi r1, r5, r0, lsl #16 */

/* ── FUNC 0x1157a8 · F_DateIncMonth(RValue&, CInstance*, CInstance*, int, RValue*) · size=240 · insn=60 */
/* @0x1157a8 push {r4, r5, r6, lr} */
/* @0x1157ac sub sp, sp, #8 */
/* @0x1157b0 mov r1, #0 */
/* @0x1157b4 mov r4, r0 */
/* @0x1157b8 ldr r6, [sp, #0x18] */
/* @0x1157bc mov r3, r1 */
/* @0x1157c0 str r1, [r0, #0xc] */
/* @0x1157c4 movt r3, #0xbff0 */
/* @0x1157c8 stm r0, {r1, r3} */
/* @0x1157cc mov r0, r6 */
/* @0x1157d0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1157d4 vldr d7, [pc, #164] */
/* @0x1157d8 vldr d5, [pc, #168] */
/* @0x1157dc vmov d6, r0, r1 */
/* @0x1157e0 vsub.f64 d7, d6, d7 */
/* @0x1157e4 vabs.f64 d4, d7 */
/* @0x1157e8 vcmpe.f64 d4, d5 */
/* @0x1157ec vmrs APSR_nzcv, fpscr */
/* @0x1157f0 vldrls d7, [pc, #152] */
/* @0x1157f4 vldrhi d6, [pc, #148] */
/* @0x1157f8 vmulls.f64 d4, d6, d7 */
/* @0x1157fc vmulhi.f64 d5, d7, d6 */
/* @0x115800 vmovls r0, r1, d4 */
/* @0x115804 vmovhi r0, r1, d5 */
/* @0x115808 bl 0x3194a0 <__fixdfdi> */
/* @0x11580c mov r2, r0 */
/* @0x115810 add r0, sp, #8 */
/* @0x115814 mov r3, r1 */
/* @0x115818 strd r2, r3, [r0, #-8]! */
/* @0x11581c mov r0, sp */
/* @0x115820 bl 0xb6820 <gmtime64@plt> */
/* @0x115824 subs r5, r0, #0 */
/* @0x115828 beq 0x115874 <_Z14F_DateIncMonthR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x11582c mov r0, r6 */
/* @0x115830 mov r1, #1 */
/* @0x115834 ldr r6, [r5, #0x10] */
/* @0x115838 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11583c add r6, r6, r0 */
/* @0x115840 mov r0, r5 */
/* @0x115844 str r6, [r5, #0x10] */
/* @0x115848 bl 0xb6814 <timegm64@plt> */
/* @0x11584c bl 0x319164 <__floatdidf> */
/* @0x115850 vmov.f64 d6, #5.000000e-01 */
/* @0x115854 vldr d5, [pc, #52] */
/* @0x115858 vldr d7, [pc, #32] */
/* @0x11585c vmov d4, r0, r1 */
/* @0x115860 vadd.f64 d6, d4, d6 */
/* @0x115864 vdiv.f64 d6, d6, d5 */
/* @0x115868 vadd.f64 d5, d6, d7 */
/* @0x11586c vmov r2, r3, d5 */
/* @0x115870 stm r4, {r2, r3} */
/* @0x115874 add sp, sp, #8 */
/* @0x115878 pop {r4, r5, r6, pc} */
/* @0x11587c nop */
/* @0x115880 andeq r0, r0, r0 */
/* @0x115884 sbcsmi pc, r8, r0, asr #16 */
/* @0x115888 bl 0x826544 <b2_toiTime+0xcd0a0> */
/* @0x11588c svclo #0x1a36e2 */
/* @0x115890 andeq r0, r0, r0 */
/* @0x115894 rscsmi r1, r5, r0, lsl #16 */

/* ── FUNC 0x115898 · F_DateIncWeek(RValue&, CInstance*, CInstance*, int, RValue*) · size=240 · insn=60 */
/* @0x115898 push {r4, r5, r6, lr} */
/* @0x11589c sub sp, sp, #8 */
/* @0x1158a0 mov r1, #0 */
/* @0x1158a4 mov r4, r0 */
/* @0x1158a8 ldr r6, [sp, #0x18] */
/* @0x1158ac mov r3, r1 */
/* @0x1158b0 str r1, [r0, #0xc] */
/* @0x1158b4 movt r3, #0xbff0 */
/* @0x1158b8 stm r0, {r1, r3} */
/* @0x1158bc mov r0, r6 */
/* @0x1158c0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1158c4 vldr d7, [pc, #164] */
/* @0x1158c8 vldr d5, [pc, #168] */
/* @0x1158cc vmov d6, r0, r1 */
/* @0x1158d0 vsub.f64 d7, d6, d7 */
/* @0x1158d4 vabs.f64 d4, d7 */
/* @0x1158d8 vcmpe.f64 d4, d5 */
/* @0x1158dc vmrs APSR_nzcv, fpscr */
/* @0x1158e0 vldrls d7, [pc, #152] */
/* @0x1158e4 vldrhi d6, [pc, #148] */
/* @0x1158e8 vmulls.f64 d4, d6, d7 */
/* @0x1158ec vmulhi.f64 d5, d7, d6 */
/* @0x1158f0 vmovls r0, r1, d4 */
/* @0x1158f4 vmovhi r0, r1, d5 */
/* @0x1158f8 bl 0x3194a0 <__fixdfdi> */
/* @0x1158fc mov r2, r0 */
/* @0x115900 add r0, sp, #8 */
/* @0x115904 mov r3, r1 */
/* @0x115908 strd r2, r3, [r0, #-8]! */
/* @0x11590c mov r0, sp */
/* @0x115910 bl 0xb6820 <gmtime64@plt> */
/* @0x115914 subs r5, r0, #0 */
/* @0x115918 beq 0x115968 <_Z13F_DateIncWeekR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x11591c mov r0, r6 */
/* @0x115920 mov r1, #1 */
/* @0x115924 ldr r6, [r5, #0xc] */
/* @0x115928 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11592c rsb r3, r0, r0, lsl #3 */
/* @0x115930 mov r0, r5 */
/* @0x115934 add r6, r6, r3 */
/* @0x115938 str r6, [r5, #0xc] */
/* @0x11593c bl 0xb6814 <timegm64@plt> */
/* @0x115940 bl 0x319164 <__floatdidf> */
/* @0x115944 vmov.f64 d6, #5.000000e-01 */
/* @0x115948 vldr d5, [pc, #48] */
/* @0x11594c vldr d7, [pc, #28] */
/* @0x115950 vmov d4, r0, r1 */
/* @0x115954 vadd.f64 d6, d4, d6 */
/* @0x115958 vdiv.f64 d6, d6, d5 */
/* @0x11595c vadd.f64 d5, d6, d7 */
/* @0x115960 vmov r2, r3, d5 */
/* @0x115964 stm r4, {r2, r3} */
/* @0x115968 add sp, sp, #8 */
/* @0x11596c pop {r4, r5, r6, pc} */
/* @0x115970 andeq r0, r0, r0 */
/* @0x115974 sbcsmi pc, r8, r0, asr #16 */
/* @0x115978 bl 0x826634 <b2_toiTime+0xcd190> */
/* @0x11597c svclo #0x1a36e2 */
/* @0x115980 andeq r0, r0, r0 */
/* @0x115984 rscsmi r1, r5, r0, lsl #16 */

/* ── FUNC 0x115988 · F_DateIncDay(RValue&, CInstance*, CInstance*, int, RValue*) · size=240 · insn=60 */
/* @0x115988 push {r4, r5, r6, lr} */
/* @0x11598c sub sp, sp, #8 */
/* @0x115990 mov r1, #0 */
/* @0x115994 mov r4, r0 */
/* @0x115998 ldr r6, [sp, #0x18] */
/* @0x11599c mov r3, r1 */
/* @0x1159a0 str r1, [r0, #0xc] */
/* @0x1159a4 movt r3, #0xbff0 */
/* @0x1159a8 stm r0, {r1, r3} */
/* @0x1159ac mov r0, r6 */
/* @0x1159b0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1159b4 vldr d7, [pc, #164] */
/* @0x1159b8 vldr d5, [pc, #168] */
/* @0x1159bc vmov d6, r0, r1 */
/* @0x1159c0 vsub.f64 d7, d6, d7 */
/* @0x1159c4 vabs.f64 d4, d7 */
/* @0x1159c8 vcmpe.f64 d4, d5 */
/* @0x1159cc vmrs APSR_nzcv, fpscr */
/* @0x1159d0 vldrls d7, [pc, #152] */
/* @0x1159d4 vldrhi d6, [pc, #148] */
/* @0x1159d8 vmulls.f64 d4, d6, d7 */
/* @0x1159dc vmulhi.f64 d5, d7, d6 */
/* @0x1159e0 vmovls r0, r1, d4 */
/* @0x1159e4 vmovhi r0, r1, d5 */
/* @0x1159e8 bl 0x3194a0 <__fixdfdi> */
/* @0x1159ec mov r2, r0 */
/* @0x1159f0 add r0, sp, #8 */
/* @0x1159f4 mov r3, r1 */
/* @0x1159f8 strd r2, r3, [r0, #-8]! */
/* @0x1159fc mov r0, sp */
/* @0x115a00 bl 0xb6820 <gmtime64@plt> */
/* @0x115a04 subs r5, r0, #0 */
/* @0x115a08 beq 0x115a54 <_Z12F_DateIncDayR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x115a0c mov r0, r6 */
/* @0x115a10 mov r1, #1 */
/* @0x115a14 ldr r6, [r5, #0xc] */
/* @0x115a18 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x115a1c add r6, r6, r0 */
/* @0x115a20 mov r0, r5 */
/* @0x115a24 str r6, [r5, #0xc] */
/* @0x115a28 bl 0xb6814 <timegm64@plt> */
/* @0x115a2c bl 0x319164 <__floatdidf> */
/* @0x115a30 vmov.f64 d6, #5.000000e-01 */
/* @0x115a34 vldr d5, [pc, #52] */
/* @0x115a38 vldr d7, [pc, #32] */
/* @0x115a3c vmov d4, r0, r1 */
/* @0x115a40 vadd.f64 d6, d4, d6 */
/* @0x115a44 vdiv.f64 d6, d6, d5 */
/* @0x115a48 vadd.f64 d5, d6, d7 */
/* @0x115a4c vmov r2, r3, d5 */
/* @0x115a50 stm r4, {r2, r3} */
/* @0x115a54 add sp, sp, #8 */
/* @0x115a58 pop {r4, r5, r6, pc} */
/* @0x115a5c nop */
/* @0x115a60 andeq r0, r0, r0 */
/* @0x115a64 sbcsmi pc, r8, r0, asr #16 */
/* @0x115a68 bl 0x826724 <b2_toiTime+0xcd280> */
/* @0x115a6c svclo #0x1a36e2 */
/* @0x115a70 andeq r0, r0, r0 */
/* @0x115a74 rscsmi r1, r5, r0, lsl #16 */

/* ── FUNC 0x115a78 · F_DateIncHour(RValue&, CInstance*, CInstance*, int, RValue*) · size=240 · insn=60 */
/* @0x115a78 push {r4, r5, r6, lr} */
/* @0x115a7c sub sp, sp, #8 */
/* @0x115a80 mov r1, #0 */
/* @0x115a84 mov r4, r0 */
/* @0x115a88 ldr r6, [sp, #0x18] */
/* @0x115a8c mov r3, r1 */
/* @0x115a90 str r1, [r0, #0xc] */
/* @0x115a94 movt r3, #0xbff0 */
/* @0x115a98 stm r0, {r1, r3} */
/* @0x115a9c mov r0, r6 */
/* @0x115aa0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x115aa4 vldr d7, [pc, #164] */
/* @0x115aa8 vldr d5, [pc, #168] */
/* @0x115aac vmov d6, r0, r1 */
/* @0x115ab0 vsub.f64 d7, d6, d7 */
/* @0x115ab4 vabs.f64 d4, d7 */
/* @0x115ab8 vcmpe.f64 d4, d5 */
/* @0x115abc vmrs APSR_nzcv, fpscr */
/* @0x115ac0 vldrls d7, [pc, #152] */
/* @0x115ac4 vldrhi d6, [pc, #148] */
/* @0x115ac8 vmulls.f64 d4, d6, d7 */
/* @0x115acc vmulhi.f64 d5, d7, d6 */
/* @0x115ad0 vmovls r0, r1, d4 */
/* @0x115ad4 vmovhi r0, r1, d5 */
/* @0x115ad8 bl 0x3194a0 <__fixdfdi> */
/* @0x115adc mov r2, r0 */
/* @0x115ae0 add r0, sp, #8 */
/* @0x115ae4 mov r3, r1 */
/* @0x115ae8 strd r2, r3, [r0, #-8]! */
/* @0x115aec mov r0, sp */
/* @0x115af0 bl 0xb6820 <gmtime64@plt> */
/* @0x115af4 subs r5, r0, #0 */
/* @0x115af8 beq 0x115b44 <_Z13F_DateIncHourR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x115afc mov r0, r6 */
/* @0x115b00 mov r1, #1 */
/* @0x115b04 ldr r6, [r5, #0x8] */
/* @0x115b08 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x115b0c add r6, r6, r0 */
/* @0x115b10 mov r0, r5 */
/* @0x115b14 str r6, [r5, #0x8] */
/* @0x115b18 bl 0xb6814 <timegm64@plt> */
/* @0x115b1c bl 0x319164 <__floatdidf> */
/* @0x115b20 vmov.f64 d6, #5.000000e-01 */
/* @0x115b24 vldr d5, [pc, #52] */
/* @0x115b28 vldr d7, [pc, #32] */
/* @0x115b2c vmov d4, r0, r1 */
/* @0x115b30 vadd.f64 d6, d4, d6 */
/* @0x115b34 vdiv.f64 d6, d6, d5 */
/* @0x115b38 vadd.f64 d5, d6, d7 */
/* @0x115b3c vmov r2, r3, d5 */
/* @0x115b40 stm r4, {r2, r3} */
/* @0x115b44 add sp, sp, #8 */
/* @0x115b48 pop {r4, r5, r6, pc} */
/* @0x115b4c nop */
/* @0x115b50 andeq r0, r0, r0 */
/* @0x115b54 sbcsmi pc, r8, r0, asr #16 */
/* @0x115b58 bl 0x826814 <b2_toiTime+0xcd370> */
/* @0x115b5c svclo #0x1a36e2 */
/* @0x115b60 andeq r0, r0, r0 */
/* @0x115b64 rscsmi r1, r5, r0, lsl #16 */

/* ── FUNC 0x115b68 · F_DateIncMinute(RValue&, CInstance*, CInstance*, int, RValue*) · size=240 · insn=60 */
/* @0x115b68 push {r4, r5, r6, lr} */
/* @0x115b6c sub sp, sp, #8 */
/* @0x115b70 mov r1, #0 */
/* @0x115b74 mov r4, r0 */
/* @0x115b78 ldr r6, [sp, #0x18] */
/* @0x115b7c mov r3, r1 */
/* @0x115b80 str r1, [r0, #0xc] */
/* @0x115b84 movt r3, #0xbff0 */
/* @0x115b88 stm r0, {r1, r3} */
/* @0x115b8c mov r0, r6 */
/* @0x115b90 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x115b94 vldr d7, [pc, #164] */
/* @0x115b98 vldr d5, [pc, #168] */
/* @0x115b9c vmov d6, r0, r1 */
/* @0x115ba0 vsub.f64 d7, d6, d7 */
/* @0x115ba4 vabs.f64 d4, d7 */
/* @0x115ba8 vcmpe.f64 d4, d5 */
/* @0x115bac vmrs APSR_nzcv, fpscr */
/* @0x115bb0 vldrls d7, [pc, #152] */
/* @0x115bb4 vldrhi d6, [pc, #148] */
/* @0x115bb8 vmulls.f64 d4, d6, d7 */
/* @0x115bbc vmulhi.f64 d5, d7, d6 */
/* @0x115bc0 vmovls r0, r1, d4 */
/* @0x115bc4 vmovhi r0, r1, d5 */
/* @0x115bc8 bl 0x3194a0 <__fixdfdi> */
/* @0x115bcc mov r2, r0 */
/* @0x115bd0 add r0, sp, #8 */
/* @0x115bd4 mov r3, r1 */
/* @0x115bd8 strd r2, r3, [r0, #-8]! */
/* @0x115bdc mov r0, sp */
/* @0x115be0 bl 0xb6820 <gmtime64@plt> */
/* @0x115be4 subs r5, r0, #0 */
/* @0x115be8 beq 0x115c34 <_Z15F_DateIncMinuteR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x115bec mov r0, r6 */
/* @0x115bf0 mov r1, #1 */
/* @0x115bf4 ldr r6, [r5, #0x4] */
/* @0x115bf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x115bfc add r6, r6, r0 */
/* @0x115c00 mov r0, r5 */
/* @0x115c04 str r6, [r5, #0x4] */
/* @0x115c08 bl 0xb6814 <timegm64@plt> */
/* @0x115c0c bl 0x319164 <__floatdidf> */
/* @0x115c10 vmov.f64 d6, #5.000000e-01 */
/* @0x115c14 vldr d5, [pc, #52] */
/* @0x115c18 vldr d7, [pc, #32] */
/* @0x115c1c vmov d4, r0, r1 */
/* @0x115c20 vadd.f64 d6, d4, d6 */
/* @0x115c24 vdiv.f64 d6, d6, d5 */
/* @0x115c28 vadd.f64 d5, d6, d7 */
/* @0x115c2c vmov r2, r3, d5 */
/* @0x115c30 stm r4, {r2, r3} */
/* @0x115c34 add sp, sp, #8 */
/* @0x115c38 pop {r4, r5, r6, pc} */
/* @0x115c3c nop */
/* @0x115c40 andeq r0, r0, r0 */
/* @0x115c44 sbcsmi pc, r8, r0, asr #16 */
/* @0x115c48 bl 0x826904 <b2_toiTime+0xcd460> */
/* @0x115c4c svclo #0x1a36e2 */
/* @0x115c50 andeq r0, r0, r0 */
/* @0x115c54 rscsmi r1, r5, r0, lsl #16 */

/* ── FUNC 0x115c58 · F_DateIncSecond(RValue&, CInstance*, CInstance*, int, RValue*) · size=240 · insn=60 */
/* @0x115c58 push {r4, r5, r6, lr} */
/* @0x115c5c sub sp, sp, #8 */
/* @0x115c60 mov r1, #0 */
/* @0x115c64 mov r4, r0 */
/* @0x115c68 ldr r6, [sp, #0x18] */
/* @0x115c6c mov r3, r1 */
/* @0x115c70 str r1, [r0, #0xc] */
/* @0x115c74 movt r3, #0xbff0 */
/* @0x115c78 stm r0, {r1, r3} */
/* @0x115c7c mov r0, r6 */
/* @0x115c80 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x115c84 vldr d7, [pc, #164] */
/* @0x115c88 vldr d5, [pc, #168] */
/* @0x115c8c vmov d6, r0, r1 */
/* @0x115c90 vsub.f64 d7, d6, d7 */
/* @0x115c94 vabs.f64 d4, d7 */
/* @0x115c98 vcmpe.f64 d4, d5 */
/* @0x115c9c vmrs APSR_nzcv, fpscr */
/* @0x115ca0 vldrls d7, [pc, #152] */
/* @0x115ca4 vldrhi d6, [pc, #148] */
/* @0x115ca8 vmulls.f64 d4, d6, d7 */
/* @0x115cac vmulhi.f64 d5, d7, d6 */
/* @0x115cb0 vmovls r0, r1, d4 */
/* @0x115cb4 vmovhi r0, r1, d5 */
/* @0x115cb8 bl 0x3194a0 <__fixdfdi> */
/* @0x115cbc mov r2, r0 */
/* @0x115cc0 add r0, sp, #8 */
/* @0x115cc4 mov r3, r1 */
/* @0x115cc8 strd r2, r3, [r0, #-8]! */
/* @0x115ccc mov r0, sp */
/* @0x115cd0 bl 0xb6820 <gmtime64@plt> */
/* @0x115cd4 subs r5, r0, #0 */
/* @0x115cd8 beq 0x115d24 <_Z15F_DateIncSecondR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x115cdc mov r0, r6 */
/* @0x115ce0 mov r1, #1 */
/* @0x115ce4 ldr r6, [r5] */
/* @0x115ce8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x115cec add r6, r6, r0 */
/* @0x115cf0 mov r0, r5 */
/* @0x115cf4 str r6, [r5] */
/* @0x115cf8 bl 0xb6814 <timegm64@plt> */
/* @0x115cfc bl 0x319164 <__floatdidf> */
/* @0x115d00 vmov.f64 d6, #5.000000e-01 */
/* @0x115d04 vldr d5, [pc, #52] */
/* @0x115d08 vldr d7, [pc, #32] */
/* @0x115d0c vmov d4, r0, r1 */
/* @0x115d10 vadd.f64 d6, d4, d6 */
/* @0x115d14 vdiv.f64 d6, d6, d5 */
/* @0x115d18 vadd.f64 d5, d6, d7 */
/* @0x115d1c vmov r2, r3, d5 */
/* @0x115d20 stm r4, {r2, r3} */
/* @0x115d24 add sp, sp, #8 */
/* @0x115d28 pop {r4, r5, r6, pc} */
/* @0x115d2c nop */
/* @0x115d30 andeq r0, r0, r0 */
/* @0x115d34 sbcsmi pc, r8, r0, asr #16 */
/* @0x115d38 bl 0x8269f4 <b2_toiTime+0xcd550> */
/* @0x115d3c svclo #0x1a36e2 */
/* @0x115d40 andeq r0, r0, r0 */
/* @0x115d44 rscsmi r1, r5, r0, lsl #16 */

/* ── FUNC 0x115d48 · F_DateCompareTime(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x115d48 push {r4, r5, r6, r7, lr} */
/* @0x115d4c vpush {d8} */
/* @0x115d50 sub sp, sp, #12 */
/* @0x115d54 mov r5, #0 */
/* @0x115d58 mov r4, r0 */
/* @0x115d5c ldr r6, [sp, #0x28] */
/* @0x115d60 mov r1, r5 */
/* @0x115d64 str r5, [r0, #0xc] */
/* @0x115d68 mov r0, r6 */
/* @0x115d6c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x115d70 mov r2, sp */
/* @0x115d74 bl 0xb6718 <modf@plt> */
/* @0x115d78 vmov d8, r0, r1 */
/* @0x115d7c mov r0, r6 */
/* @0x115d80 mov r1, #1 */
/* @0x115d84 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x115d88 mov r2, sp */
/* @0x115d8c bl 0xb6718 <modf@plt> */
/* @0x115d90 vmov d7, r0, r1 */
/* @0x115d94 vcmp.f64 d8, d7 */
/* @0x115d98 vmrs APSR_nzcv, fpscr */
/* @0x115d9c moveq r3, r5 */
/* @0x115da0 beq 0x115dc0 <_Z17F_DateCompareTimeR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x115da4 vcmpe.f64 d8, d7 */
/* @0x115da8 mov r2, r5 */
/* @0x115dac mov r3, r5 */
/* @0x115db0 movt r2, #0x3ff0 */
/* @0x115db4 movt r3, #0xbff0 */
/* @0x115db8 vmrs APSR_nzcv, fpscr */
/* @0x115dbc movgt r3, r2 */
/* @0x115dc0 str r5, [r4] */
/* @0x115dc4 str r3, [r4, #0x4] */
/* @0x115dc8 add sp, sp, #12 */
/* @0x115dcc vpop {d8} */
/* @0x115dd0 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x115dd4 · F_DateTimeOf(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x115dd4 push {r4, lr} */
/* @0x115dd8 sub sp, sp, #8 */
/* @0x115ddc mov r3, #0 */
/* @0x115de0 mov r4, r0 */
/* @0x115de4 str r3, [r0, #0xc] */
/* @0x115de8 mov r1, r3 */
/* @0x115dec ldr r0, [sp, #0x10] */
/* @0x115df0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x115df4 mov r2, sp */
/* @0x115df8 bl 0xb6718 <modf@plt> */
/* @0x115dfc stm r4, {r0, r1} */
/* @0x115e00 add sp, sp, #8 */
/* @0x115e04 pop {r4, pc} */

/* ── FUNC 0x115e08 · F_AlarmSet(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x115e08 push {r4, r5, r6, lr} */
/* @0x115e0c mov r6, r1 */
/* @0x115e10 ldr r4, [sp, #0x10] */
/* @0x115e14 mov r1, #0 */
/* @0x115e18 mov r0, r4 */
/* @0x115e1c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x115e20 mov r1, #1 */
/* @0x115e24 mov r5, r0 */
/* @0x115e28 mov r0, r4 */
/* @0x115e2c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x115e30 mov r1, r5 */
/* @0x115e34 mov r2, r0 */
/* @0x115e38 mov r0, r6 */
/* @0x115e3c pop {r4, r5, r6, lr} */
/* @0x115e40 b 0x193148 <_ZN9CInstance8SetTimerEii> */

/* ── FUNC 0x115e44 · F_AlarmGet(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x115e44 push {r3, r4, r5, lr} */
/* @0x115e48 mov r3, #0 */
/* @0x115e4c mov r4, r0 */
/* @0x115e50 str r3, [r0, #0xc] */
/* @0x115e54 mov r5, r1 */
/* @0x115e58 ldr r0, [sp, #0x10] */
/* @0x115e5c mov r1, r3 */
/* @0x115e60 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x115e64 mov r1, r0 */
/* @0x115e68 mov r0, r5 */
/* @0x115e6c bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0x115e70 vmov s15, r0 */
/* @0x115e74 vcvt.f64.s32 d7, s15 */
/* @0x115e78 vmov r0, r1, d7 */
/* @0x115e7c vmov r2, s14 */
/* @0x115e80 mov r3, r1 */
/* @0x115e84 stm r4, {r2, r3} */
/* @0x115e88 pop {r3, r4, r5, pc} */

/* ── FUNC 0x115e8c · F_ExternalDefine0(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0x115e8c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x115e90 sub sp, sp, #84 */
/* @0x115e94 add r5, sp, #12 */
/* @0x115e98 mov r2, #68 */
/* @0x115e9c ldr r4, [sp, #0x70] */
/* @0x115ea0 mov r7, r0 */
/* @0x115ea4 mov r1, #0 */
/* @0x115ea8 mov r0, r5 */
/* @0x115eac bl 0xb65b0 <memset@plt> */
/* @0x115eb0 mov r1, #0 */
/* @0x115eb4 mov r0, r4 */
/* @0x115eb8 mov r6, r1 */
/* @0x115ebc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x115ec0 mov r1, #1 */
/* @0x115ec4 mov r8, r0 */
/* @0x115ec8 mov r0, r4 */
/* @0x115ecc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x115ed0 mov r1, #2 */
/* @0x115ed4 mov r9, r0 */
/* @0x115ed8 mov r0, r4 */
/* @0x115edc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x115ee0 str r5, [sp] */
/* @0x115ee4 mov r1, r9 */
/* @0x115ee8 str r6, [r7, #0xc] */
/* @0x115eec mov r2, r6 */
/* @0x115ef0 mov r3, r6 */
/* @0x115ef4 subs r0, r0, #1 */
/* @0x115ef8 rsbs r12, r0, #0 */
/* @0x115efc adcs r12, r12, r0 */
/* @0x115f00 mov r0, r8 */
/* @0x115f04 str r12, [sp, #0x4] */
/* @0x115f08 bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii> */
/* @0x115f0c vmov.f64 d7, #-1.000000e+00 */
/* @0x115f10 vmov s13, r0 */
/* @0x115f14 vcvt.f64.s32 d6, s13 */
/* @0x115f18 vmov r0, r1, d6 */
/* @0x115f1c vmov r2, s12 */
/* @0x115f20 vcmp.f64 d6, d7 */
/* @0x115f24 vmrs APSR_nzcv, fpscr */
/* @0x115f28 mov r3, r1 */
/* @0x115f2c stm r7, {r2, r3} */
/* @0x115f30 bne 0x115f44 <_Z17F_ExternalDefine0R6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x115f34 ldr r0, [pc, #0x10] */
/* @0x115f38 mov r1, r6 */
/* @0x115f3c add r0, pc, r0 */
/* @0x115f40 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x115f44 add sp, sp, #84 */
/* @0x115f48 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x115f4c eoreq r3, r2, r4, ror #14 */

/* ── FUNC 0x115f50 · F_ExternalDefine1(RValue&, CInstance*, CInstance*, int, RValue*) · size=228 · insn=57 */
/* @0x115f50 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x115f54 sub sp, sp, #84 */
/* @0x115f58 add r5, sp, #12 */
/* @0x115f5c mov r2, #68 */
/* @0x115f60 ldr r4, [sp, #0x70] */
/* @0x115f64 mov r6, r0 */
/* @0x115f68 mov r1, #0 */
/* @0x115f6c mov r0, r5 */
/* @0x115f70 bl 0xb65b0 <memset@plt> */
/* @0x115f74 mov r1, #0 */
/* @0x115f78 mov r0, r4 */
/* @0x115f7c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x115f80 mov r1, #1 */
/* @0x115f84 mov r9, r0 */
/* @0x115f88 mov r0, r4 */
/* @0x115f8c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x115f90 mov r1, #2 */
/* @0x115f94 mov r8, r0 */
/* @0x115f98 mov r0, r4 */
/* @0x115f9c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x115fa0 mov r1, #3 */
/* @0x115fa4 mov r7, r0 */
/* @0x115fa8 mov r0, r4 */
/* @0x115fac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x115fb0 cmp r7, #1 */
/* @0x115fb4 streq r7, [sp, #0xc] */
/* @0x115fb8 mov r7, #0 */
/* @0x115fbc movne r3, #0 */
/* @0x115fc0 str r5, [sp] */
/* @0x115fc4 mov r1, r8 */
/* @0x115fc8 strne r3, [sp, #0xc] */
/* @0x115fcc subs r2, r0, #1 */
/* @0x115fd0 rsbs r3, r2, #0 */
/* @0x115fd4 mov r0, r9 */
/* @0x115fd8 adcs r3, r3, r2 */
/* @0x115fdc mov r2, r7 */
/* @0x115fe0 str r3, [sp, #0x4] */
/* @0x115fe4 mov r3, #1 */
/* @0x115fe8 str r7, [r6, #0xc] */
/* @0x115fec bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii> */
/* @0x115ff0 vmov.f64 d7, #-1.000000e+00 */
/* @0x115ff4 vmov s13, r0 */
/* @0x115ff8 vcvt.f64.s32 d6, s13 */
/* @0x115ffc vmov r0, r1, d6 */
/* @0x116000 vmov r2, s12 */
/* @0x116004 vcmp.f64 d6, d7 */
/* @0x116008 vmrs APSR_nzcv, fpscr */
/* @0x11600c mov r3, r1 */
/* @0x116010 stm r6, {r2, r3} */
/* @0x116014 bne 0x116028 <_Z17F_ExternalDefine1R6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x116018 ldr r0, [pc, #0x10] */
/* @0x11601c mov r1, r7 */
/* @0x116020 add r0, pc, r0 */
/* @0x116024 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x116028 add sp, sp, #84 */
/* @0x11602c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x116030 eoreq r3, r2, r0, lsl #13 */

/* ── FUNC 0x116034 · F_ExternalDefine2(RValue&, CInstance*, CInstance*, int, RValue*) · size=260 · insn=65 */
/* @0x116034 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x116038 sub sp, sp, #80 */
/* @0x11603c add r5, sp, #12 */
/* @0x116040 mov r2, #68 */
/* @0x116044 ldr r4, [sp, #0x70] */
/* @0x116048 mov r6, r0 */
/* @0x11604c mov r1, #0 */
/* @0x116050 mov r0, r5 */
/* @0x116054 bl 0xb65b0 <memset@plt> */
/* @0x116058 mov r1, #0 */
/* @0x11605c mov r0, r4 */
/* @0x116060 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x116064 mov r1, #1 */
/* @0x116068 mov r10, r0 */
/* @0x11606c mov r0, r4 */
/* @0x116070 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x116074 mov r1, #2 */
/* @0x116078 mov r9, r0 */
/* @0x11607c mov r0, r4 */
/* @0x116080 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x116084 mov r1, #3 */
/* @0x116088 mov r8, r0 */
/* @0x11608c mov r0, r4 */
/* @0x116090 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x116094 mov r1, #4 */
/* @0x116098 mov r7, r0 */
/* @0x11609c mov r0, r4 */
/* @0x1160a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1160a4 cmp r8, #1 */
/* @0x1160a8 streq r8, [sp, #0xc] */
/* @0x1160ac mov r1, r9 */
/* @0x1160b0 movne r3, #0 */
/* @0x1160b4 str r5, [sp] */
/* @0x1160b8 strne r3, [sp, #0xc] */
/* @0x1160bc cmp r7, #1 */
/* @0x1160c0 streq r7, [sp, #0x10] */
/* @0x1160c4 mov r7, #0 */
/* @0x1160c8 movne r3, #0 */
/* @0x1160cc strne r3, [sp, #0x10] */
/* @0x1160d0 subs r2, r0, #1 */
/* @0x1160d4 mov r0, r10 */
/* @0x1160d8 rsbs r3, r2, #0 */
/* @0x1160dc adcs r3, r3, r2 */
/* @0x1160e0 mov r2, r7 */
/* @0x1160e4 str r3, [sp, #0x4] */
/* @0x1160e8 mov r3, #2 */
/* @0x1160ec str r7, [r6, #0xc] */
/* @0x1160f0 bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii> */
/* @0x1160f4 vmov.f64 d7, #-1.000000e+00 */
/* @0x1160f8 vmov s13, r0 */
/* @0x1160fc vcvt.f64.s32 d6, s13 */
/* @0x116100 vmov r0, r1, d6 */
/* @0x116104 vmov r2, s12 */
/* @0x116108 vcmp.f64 d6, d7 */
/* @0x11610c vmrs APSR_nzcv, fpscr */
/* @0x116110 mov r3, r1 */
/* @0x116114 stm r6, {r2, r3} */
/* @0x116118 bne 0x11612c <_Z17F_ExternalDefine2R6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x11611c ldr r0, [pc, #0x10] */
/* @0x116120 mov r1, r7 */
/* @0x116124 add r0, pc, r0 */
/* @0x116128 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11612c add sp, sp, #80 */
/* @0x116130 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x116134 eoreq r3, r2, r12, ror r5 */

/* ── FUNC 0x116138 · F_ExternalDefine3(RValue&, CInstance*, CInstance*, int, RValue*) · size=292 · insn=73 */
/* @0x116138 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11613c sub sp, sp, #84 */
/* @0x116140 add r5, sp, #12 */
/* @0x116144 mov r2, #68 */
/* @0x116148 ldr r4, [sp, #0x78] */
/* @0x11614c mov r6, r0 */
/* @0x116150 mov r1, #0 */
/* @0x116154 mov r0, r5 */
/* @0x116158 bl 0xb65b0 <memset@plt> */
/* @0x11615c mov r1, #0 */
/* @0x116160 mov r0, r4 */
/* @0x116164 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x116168 mov r1, #1 */
/* @0x11616c mov r11, r0 */
/* @0x116170 mov r0, r4 */
/* @0x116174 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x116178 mov r1, #2 */
/* @0x11617c mov r10, r0 */
/* @0x116180 mov r0, r4 */
/* @0x116184 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x116188 mov r1, #3 */
/* @0x11618c mov r9, r0 */
/* @0x116190 mov r0, r4 */
/* @0x116194 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x116198 mov r1, #4 */
/* @0x11619c mov r8, r0 */
/* @0x1161a0 mov r0, r4 */
/* @0x1161a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1161a8 mov r1, #5 */
/* @0x1161ac mov r7, r0 */
/* @0x1161b0 mov r0, r4 */
/* @0x1161b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1161b8 cmp r9, #1 */
/* @0x1161bc streq r9, [sp, #0xc] */
/* @0x1161c0 mov r1, r10 */
/* @0x1161c4 movne r3, #0 */
/* @0x1161c8 str r5, [sp] */
/* @0x1161cc strne r3, [sp, #0xc] */
/* @0x1161d0 cmp r8, #1 */
/* @0x1161d4 streq r8, [sp, #0x10] */
/* @0x1161d8 movne r3, #0 */
/* @0x1161dc strne r3, [sp, #0x10] */
/* @0x1161e0 cmp r7, #1 */
/* @0x1161e4 streq r7, [sp, #0x14] */
/* @0x1161e8 mov r7, #0 */
/* @0x1161ec movne r3, #0 */
/* @0x1161f0 strne r3, [sp, #0x14] */
/* @0x1161f4 subs r2, r0, #1 */
/* @0x1161f8 mov r0, r11 */
/* @0x1161fc rsbs r3, r2, #0 */
/* @0x116200 adcs r3, r3, r2 */
/* @0x116204 mov r2, r7 */
/* @0x116208 str r3, [sp, #0x4] */
/* @0x11620c mov r3, #3 */
/* @0x116210 str r7, [r6, #0xc] */
/* @0x116214 bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii> */
/* @0x116218 vmov.f64 d7, #-1.000000e+00 */
/* @0x11621c vmov s13, r0 */
/* @0x116220 vcvt.f64.s32 d6, s13 */
/* @0x116224 vmov r0, r1, d6 */
/* @0x116228 vmov r2, s12 */
/* @0x11622c vcmp.f64 d6, d7 */
/* @0x116230 vmrs APSR_nzcv, fpscr */
/* @0x116234 mov r3, r1 */
/* @0x116238 stm r6, {r2, r3} */
/* @0x11623c bne 0x116250 <_Z17F_ExternalDefine3R6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x116240 ldr r0, [pc, #0x10] */
/* @0x116244 mov r1, r7 */
/* @0x116248 add r0, pc, r0 */
/* @0x11624c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x116250 add sp, sp, #84 */
/* @0x116254 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x116258 eoreq r3, r2, r8, asr r4 */

/* ── FUNC 0x11625c · F_ExternalDefine4(RValue&, CInstance*, CInstance*, int, RValue*) · size=332 · insn=83 */
/* @0x11625c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x116260 sub sp, sp, #92 */
/* @0x116264 add r5, sp, #20 */
/* @0x116268 mov r2, #68 */
/* @0x11626c ldr r4, [sp, #0x80] */
/* @0x116270 mov r6, r0 */
/* @0x116274 mov r1, #0 */
/* @0x116278 mov r0, r5 */
/* @0x11627c bl 0xb65b0 <memset@plt> */
/* @0x116280 mov r1, #0 */
/* @0x116284 mov r0, r4 */
/* @0x116288 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11628c mov r1, #1 */
/* @0x116290 mov r3, r0 */
/* @0x116294 mov r0, r4 */
/* @0x116298 str r3, [sp, #0xc] */
/* @0x11629c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1162a0 mov r1, #2 */
/* @0x1162a4 mov r11, r0 */
/* @0x1162a8 mov r0, r4 */
/* @0x1162ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1162b0 mov r1, #3 */
/* @0x1162b4 mov r10, r0 */
/* @0x1162b8 mov r0, r4 */
/* @0x1162bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1162c0 mov r1, #4 */
/* @0x1162c4 mov r9, r0 */
/* @0x1162c8 mov r0, r4 */
/* @0x1162cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1162d0 mov r1, #5 */
/* @0x1162d4 mov r8, r0 */
/* @0x1162d8 mov r0, r4 */
/* @0x1162dc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1162e0 mov r1, #6 */
/* @0x1162e4 mov r7, r0 */
/* @0x1162e8 mov r0, r4 */
/* @0x1162ec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1162f0 cmp r10, #1 */
/* @0x1162f4 streq r10, [sp, #0x14] */
/* @0x1162f8 movne r2, #0 */
/* @0x1162fc ldr r3, [sp, #0xc] */
/* @0x116300 str r5, [sp] */
/* @0x116304 strne r2, [sp, #0x14] */
/* @0x116308 cmp r9, #1 */
/* @0x11630c streq r9, [sp, #0x18] */
/* @0x116310 movne r2, #0 */
/* @0x116314 strne r2, [sp, #0x18] */
/* @0x116318 cmp r8, #1 */
/* @0x11631c streq r8, [sp, #0x1c] */
/* @0x116320 movne r2, #0 */
/* @0x116324 strne r2, [sp, #0x1c] */
/* @0x116328 cmp r7, #1 */
/* @0x11632c streq r7, [sp, #0x20] */
/* @0x116330 mov r7, #0 */
/* @0x116334 movne r2, #0 */
/* @0x116338 strne r2, [sp, #0x20] */
/* @0x11633c subs r1, r0, #1 */
/* @0x116340 mov r0, r3 */
/* @0x116344 rsbs r2, r1, #0 */
/* @0x116348 mov r3, #4 */
/* @0x11634c adcs r2, r2, r1 */
/* @0x116350 mov r1, r11 */
/* @0x116354 str r2, [sp, #0x4] */
/* @0x116358 mov r2, r7 */
/* @0x11635c str r7, [r6, #0xc] */
/* @0x116360 bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii> */
/* @0x116364 vmov.f64 d7, #-1.000000e+00 */
/* @0x116368 vmov s13, r0 */
/* @0x11636c vcvt.f64.s32 d6, s13 */
/* @0x116370 vmov r0, r1, d6 */
/* @0x116374 vmov r2, s12 */
/* @0x116378 vcmp.f64 d6, d7 */
/* @0x11637c vmrs APSR_nzcv, fpscr */
/* @0x116380 mov r3, r1 */
/* @0x116384 stm r6, {r2, r3} */
/* @0x116388 bne 0x11639c <_Z17F_ExternalDefine4R6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x11638c ldr r0, [pc, #0x10] */
/* @0x116390 mov r1, r7 */
/* @0x116394 add r0, pc, r0 */
/* @0x116398 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11639c add sp, sp, #92 */
/* @0x1163a0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1163a4 eoreq r3, r2, r12, lsl #6 */

/* ── FUNC 0x1163a8 · F_ExternalDefine5(RValue&, CInstance*, CInstance*, int, RValue*) · size=204 · insn=51 */
/* @0x1163a8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1163ac sub sp, sp, #80 */
/* @0x1163b0 mov r1, #0 */
/* @0x1163b4 mov r7, r0 */
/* @0x1163b8 ldr r4, [sp, #0x68] */
/* @0x1163bc mov r0, r4 */
/* @0x1163c0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1163c4 mov r1, #1 */
/* @0x1163c8 mov r8, r0 */
/* @0x1163cc mov r0, r4 */
/* @0x1163d0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1163d4 mov r1, #2 */
/* @0x1163d8 mov r5, r0 */
/* @0x1163dc mov r0, r4 */
/* @0x1163e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1163e4 add r3, sp, #8 */
/* @0x1163e8 add r12, sp, #76 */
/* @0x1163ec mov r2, #0 */
/* @0x1163f0 subs r0, r0, #1 */
/* @0x1163f4 rsbs r1, r0, #0 */
/* @0x1163f8 adcs r1, r1, r0 */
/* @0x1163fc str r2, [r3, #0x4]! */
/* @0x116400 cmp r3, r12 */
/* @0x116404 mov r6, #0 */
/* @0x116408 bne 0x1163fc <_Z17F_ExternalDefine5R6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x11640c str r6, [r7, #0xc] */
/* @0x116410 mov r2, r6 */
/* @0x116414 str r1, [sp, #0x4] */
/* @0x116418 add r3, sp, #12 */
/* @0x11641c mov r1, r5 */
/* @0x116420 str r3, [sp] */
/* @0x116424 mov r0, r8 */
/* @0x116428 mov r3, #5 */
/* @0x11642c bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii> */
/* @0x116430 vmov.f64 d7, #-1.000000e+00 */
/* @0x116434 vmov s13, r0 */
/* @0x116438 vcvt.f64.s32 d6, s13 */
/* @0x11643c vmov r0, r1, d6 */
/* @0x116440 vmov r2, s12 */
/* @0x116444 vcmp.f64 d6, d7 */
/* @0x116448 vmrs APSR_nzcv, fpscr */
/* @0x11644c mov r3, r1 */
/* @0x116450 stm r7, {r2, r3} */
/* @0x116454 bne 0x116468 <_Z17F_ExternalDefine5R6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x116458 ldr r0, [pc, #0x10] */
/* @0x11645c mov r1, r6 */
/* @0x116460 add r0, pc, r0 */
/* @0x116464 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x116468 add sp, sp, #80 */
/* @0x11646c pop {r4, r5, r6, r7, r8, pc} */
/* @0x116470 eoreq r3, r2, r0, asr #4 */

/* ── FUNC 0x116474 · F_ExternalDefine6(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x116474 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x116478 sub sp, sp, #84 */
/* @0x11647c add r5, sp, #12 */
/* @0x116480 mov r2, #68 */
/* @0x116484 ldr r4, [sp, #0x70] */
/* @0x116488 mov r1, #0 */
/* @0x11648c mov r7, r0 */
/* @0x116490 mov r0, r5 */
/* @0x116494 bl 0xb65b0 <memset@plt> */
/* @0x116498 mov r1, #0 */
/* @0x11649c mov r0, r4 */
/* @0x1164a0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1164a4 mov r1, #1 */
/* @0x1164a8 mov r9, r0 */
/* @0x1164ac mov r0, r4 */
/* @0x1164b0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1164b4 mov r1, #2 */
/* @0x1164b8 mov r8, r0 */
/* @0x1164bc mov r0, r4 */
/* @0x1164c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1164c4 add r3, sp, #8 */
/* @0x1164c8 add r12, sp, #76 */
/* @0x1164cc mov r2, #0 */
/* @0x1164d0 subs r1, r0, #1 */
/* @0x1164d4 rsbs lr, r1, #0 */
/* @0x1164d8 adcs lr, lr, r1 */
/* @0x1164dc str r2, [r3, #0x4]! */
/* @0x1164e0 cmp r3, r12 */
/* @0x1164e4 mov r6, #0 */
/* @0x1164e8 bne 0x1164dc <_Z17F_ExternalDefine6R6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x1164ec str r6, [r7, #0xc] */
/* @0x1164f0 mov r1, r8 */
/* @0x1164f4 mov r2, r6 */
/* @0x1164f8 mov r3, #6 */
/* @0x1164fc mov r0, r9 */
/* @0x116500 str r5, [sp] */
/* @0x116504 str lr, [sp, #0x4] */
/* @0x116508 bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii> */
/* @0x11650c vmov.f64 d7, #-1.000000e+00 */
/* @0x116510 vmov s13, r0 */
/* @0x116514 vcvt.f64.s32 d6, s13 */
/* @0x116518 vmov r0, r1, d6 */
/* @0x11651c vmov r2, s12 */
/* @0x116520 vcmp.f64 d6, d7 */
/* @0x116524 vmrs APSR_nzcv, fpscr */
/* @0x116528 mov r3, r1 */
/* @0x11652c stm r7, {r2, r3} */
/* @0x116530 bne 0x116544 <_Z17F_ExternalDefine6R6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x116534 ldr r0, [pc, #0x10] */
/* @0x116538 mov r1, r6 */
/* @0x11653c add r0, pc, r0 */
/* @0x116540 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x116544 add sp, sp, #84 */
/* @0x116548 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x11654c eoreq r3, r2, r4, ror #2 */

/* ── FUNC 0x116550 · F_ExternalDefine7(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x116550 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x116554 sub sp, sp, #84 */
/* @0x116558 add r5, sp, #12 */
/* @0x11655c mov r2, #68 */
/* @0x116560 ldr r4, [sp, #0x70] */
/* @0x116564 mov r1, #0 */
/* @0x116568 mov r7, r0 */
/* @0x11656c mov r0, r5 */
/* @0x116570 bl 0xb65b0 <memset@plt> */
/* @0x116574 mov r1, #0 */
/* @0x116578 mov r0, r4 */
/* @0x11657c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x116580 mov r1, #1 */
/* @0x116584 mov r9, r0 */
/* @0x116588 mov r0, r4 */
/* @0x11658c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x116590 mov r1, #2 */
/* @0x116594 mov r8, r0 */
/* @0x116598 mov r0, r4 */
/* @0x11659c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1165a0 add r3, sp, #8 */
/* @0x1165a4 add r12, sp, #76 */
/* @0x1165a8 mov r2, #0 */
/* @0x1165ac subs r1, r0, #1 */
/* @0x1165b0 rsbs lr, r1, #0 */
/* @0x1165b4 adcs lr, lr, r1 */
/* @0x1165b8 str r2, [r3, #0x4]! */
/* @0x1165bc cmp r3, r12 */
/* @0x1165c0 mov r6, #0 */
/* @0x1165c4 bne 0x1165b8 <_Z17F_ExternalDefine7R6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x1165c8 str r6, [r7, #0xc] */
/* @0x1165cc mov r1, r8 */
/* @0x1165d0 mov r2, r6 */
/* @0x1165d4 mov r3, #7 */
/* @0x1165d8 mov r0, r9 */
/* @0x1165dc str r5, [sp] */
/* @0x1165e0 str lr, [sp, #0x4] */
/* @0x1165e4 bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii> */
/* @0x1165e8 vmov.f64 d7, #-1.000000e+00 */
/* @0x1165ec vmov s13, r0 */
/* @0x1165f0 vcvt.f64.s32 d6, s13 */
/* @0x1165f4 vmov r0, r1, d6 */
/* @0x1165f8 vmov r2, s12 */
/* @0x1165fc vcmp.f64 d6, d7 */
/* @0x116600 vmrs APSR_nzcv, fpscr */
/* @0x116604 mov r3, r1 */
/* @0x116608 stm r7, {r2, r3} */
/* @0x11660c bne 0x116620 <_Z17F_ExternalDefine7R6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x116610 ldr r0, [pc, #0x10] */
/* @0x116614 mov r1, r6 */
/* @0x116618 add r0, pc, r0 */
/* @0x11661c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x116620 add sp, sp, #84 */
/* @0x116624 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x116628 eoreq r3, r2, r8, lsl #1 */

/* ── FUNC 0x11662c · F_ExternalDefine8(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x11662c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x116630 sub sp, sp, #84 */
/* @0x116634 add r5, sp, #12 */
/* @0x116638 mov r2, #68 */
/* @0x11663c ldr r4, [sp, #0x70] */
/* @0x116640 mov r1, #0 */
/* @0x116644 mov r7, r0 */
/* @0x116648 mov r0, r5 */
/* @0x11664c bl 0xb65b0 <memset@plt> */
/* @0x116650 mov r1, #0 */
/* @0x116654 mov r0, r4 */
/* @0x116658 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11665c mov r1, #1 */
/* @0x116660 mov r9, r0 */
/* @0x116664 mov r0, r4 */
/* @0x116668 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11666c mov r1, #2 */
/* @0x116670 mov r8, r0 */
/* @0x116674 mov r0, r4 */
/* @0x116678 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11667c add r3, sp, #8 */
/* @0x116680 add r12, sp, #76 */
/* @0x116684 mov r2, #0 */
/* @0x116688 subs r1, r0, #1 */
/* @0x11668c rsbs lr, r1, #0 */
/* @0x116690 adcs lr, lr, r1 */
/* @0x116694 str r2, [r3, #0x4]! */
/* @0x116698 cmp r3, r12 */
/* @0x11669c mov r6, #0 */
/* @0x1166a0 bne 0x116694 <_Z17F_ExternalDefine8R6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x1166a4 str r6, [r7, #0xc] */
/* @0x1166a8 mov r1, r8 */
/* @0x1166ac mov r2, r6 */
/* @0x1166b0 mov r3, #8 */
/* @0x1166b4 mov r0, r9 */
/* @0x1166b8 str r5, [sp] */
/* @0x1166bc str lr, [sp, #0x4] */
/* @0x1166c0 bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii> */
/* @0x1166c4 vmov.f64 d7, #-1.000000e+00 */
/* @0x1166c8 vmov s13, r0 */
/* @0x1166cc vcvt.f64.s32 d6, s13 */
/* @0x1166d0 vmov r0, r1, d6 */
/* @0x1166d4 vmov r2, s12 */
/* @0x1166d8 vcmp.f64 d6, d7 */
/* @0x1166dc vmrs APSR_nzcv, fpscr */
/* @0x1166e0 mov r3, r1 */
/* @0x1166e4 stm r7, {r2, r3} */
/* @0x1166e8 bne 0x1166fc <_Z17F_ExternalDefine8R6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x1166ec ldr r0, [pc, #0x10] */
/* @0x1166f0 mov r1, r6 */
/* @0x1166f4 add r0, pc, r0 */
/* @0x1166f8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1166fc add sp, sp, #84 */
/* @0x116700 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x116704 eoreq r2, r2, r12, lsr #31 */

/* ── FUNC 0x116708 · F_ShowDebugOverlay(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x116708 push {r3, lr} */
/* @0x11670c mov r1, #0 */
/* @0x116710 ldr r0, [sp, #0x8] */
/* @0x116714 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x116718 cmp r0, #0 */
/* @0x11671c bne 0x116738 <_Z18F_ShowDebugOverlayR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x116720 ldr r3, [pc, #0x28] */
/* @0x116724 ldr r3, [pc, r3] */
/* @0x116728 ldr r2, [r3] */
/* @0x11672c bic r2, r2, #2 */
/* @0x116730 str r2, [r3] */
/* @0x116734 pop {r3, pc} */
/* @0x116738 ldr r3, [pc, #0x14] */
/* @0x11673c ldr r3, [pc, r3] */
/* @0x116740 ldr r2, [r3] */
/* @0x116744 orr r2, r2, #2 */
/* @0x116748 str r2, [r3] */
/* @0x11674c pop {r3, pc} */
/* @0x116750 eoreq r7, sp, r8, lsl #26 */
/* @0x116754 .word 0x002d7cf0 */

/* ── FUNC 0x116758 · F_GameSetSpeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=228 · insn=57 */
/* @0x116758 push {r4, r5, r6, lr} */
/* @0x11675c vpush {d8} */
/* @0x116760 mov r1, #0 */
/* @0x116764 ldr r4, [sp, #0x18] */
/* @0x116768 ldr r5, [pc, #0xc0] */
/* @0x11676c mov r0, r4 */
/* @0x116770 add r5, pc, r5 */
/* @0x116774 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x116778 vmov d8, r0, r1 */
/* @0x11677c mov r0, r4 */
/* @0x116780 mov r1, #1 */
/* @0x116784 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x116788 vcmpe.f64 d8, #0 */
/* @0x11678c vmrs APSR_nzcv, fpscr */
/* @0x116790 bmi 0x11680c <_Z14F_GameSetSpeedR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x116794 vcmp.f64 d8, #0 */
/* @0x116798 vmrs APSR_nzcv, fpscr */
/* @0x11679c beq 0x1167d8 <_Z14F_GameSetSpeedR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x1167a0 cmp r0, #0 */
/* @0x1167a4 beq 0x1167f4 <_Z14F_GameSetSpeedR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x1167a8 cmp r0, #1 */
/* @0x1167ac beq 0x1167b8 <_Z14F_GameSetSpeedR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x1167b0 vpop {d8} */
/* @0x1167b4 pop {r4, r5, r6, pc} */
/* @0x1167b8 vldr d7, [pc, #104] */
/* @0x1167bc vdiv.f64 d6, d7, d8 */
/* @0x1167c0 vpop {d8} */
/* @0x1167c4 ldr r1, [pc, #0x68] */
/* @0x1167c8 ldr r0, [r5, r1] */
/* @0x1167cc pop {r4, r5, r6, lr} */
/* @0x1167d0 vmov r2, r3, d6 */
/* @0x1167d4 b 0x214800 <_ZN13CTimingSource12SetFrameRateEd> */
/* @0x1167d8 vpop {d8} */
/* @0x1167dc mov r2, #0 */
/* @0x1167e0 ldr r1, [pc, #0x4c] */
/* @0x1167e4 mov r3, #0 */
/* @0x1167e8 ldr r0, [r5, r1] */
/* @0x1167ec pop {r4, r5, r6, lr} */
/* @0x1167f0 b 0x214800 <_ZN13CTimingSource12SetFrameRateEd> */
/* @0x1167f4 vmov r2, r3, d8 */
/* @0x1167f8 vpop {d8} */
/* @0x1167fc ldr r1, [pc, #0x30] */
/* @0x116800 ldr r0, [r5, r1] */
/* @0x116804 pop {r4, r5, r6, lr} */
/* @0x116808 b 0x214800 <_ZN13CTimingSource12SetFrameRateEd> */
/* @0x11680c vpop {d8} */
/* @0x116810 mov r1, #0 */
/* @0x116814 ldr r0, [pc, #0x1c] */
/* @0x116818 add r0, pc, r0 */
/* @0x11681c pop {r4, r5, r6, lr} */
/* @0x116820 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x116824 nop */
/* @0x116828 andeq r0, r0, r0 */
/* @0x11682c smlawbmi lr, r0, r4, r8 */
/* @0x116830 eoreq r11, sp, r0, ror #9 */
/* @0x116834 .word 0xffffbcdc */
/* @0x116838 mlaeq r2, r0, pc, r2 */

/* ── FUNC 0x11683c · anon_11683c · size=4 · insn=1 */
/* @0x11683c nop */

/* ── FUNC 0x116840 · F_GameGetSpeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x116840 push {r3, r4, r5, lr} */
/* @0x116844 mov r1, #0 */
/* @0x116848 ldr r4, [pc, #0x70] */
/* @0x11684c mov r5, r0 */
/* @0x116850 ldr r4, [pc, r4] */
/* @0x116854 vldr d7, [r4, #24] */
/* @0x116858 vcmpe.f64 d7, #0 */
/* @0x11685c str r1, [r0, #0xc] */
/* @0x116860 vmrs APSR_nzcv, fpscr */
/* @0x116864 strle r1, [r0] */
/* @0x116868 strle r1, [r0, #0x4] */
/* @0x11686c pople {r3, r4, r5, pc} */
/* @0x116870 ldr r0, [sp, #0x10] */
/* @0x116874 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x116878 cmp r0, #0 */
/* @0x11687c mov r0, r4 */
/* @0x116880 beq 0x1168a8 <_Z14F_GameGetSpeedR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x116884 bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0x116888 vldr d7, [pc, #40] */
/* @0x11688c vmov d6, r0, r1 */
/* @0x116890 vdiv.f64 d6, d7, d6 */
/* @0x116894 vmov r0, r1, d6 */
/* @0x116898 vmov r2, s12 */
/* @0x11689c mov r3, r1 */
/* @0x1168a0 stm r5, {r2, r3} */
/* @0x1168a4 pop {r3, r4, r5, pc} */
/* @0x1168a8 bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0x1168ac stm r5, {r0, r1} */
/* @0x1168b0 pop {r3, r4, r5, pc} */
/* @0x1168b4 nop */
/* @0x1168b8 andeq r0, r0, r0 */
/* @0x1168bc smlawbmi lr, r0, r4, r8 */
/* @0x1168c0 .word 0x002d70dc */

/* ── FUNC 0x1168c4 · anon_1168c4 · size=4 · insn=1 */
/* @0x1168c4 nop */

/* ── FUNC 0x1168c8 · F_EventInherited(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x1168c8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1168cc mov r7, r1 */
/* @0x1168d0 ldr r4, [pc, #0xb8] */
/* @0x1168d4 mov r6, r2 */
/* @0x1168d8 ldr r3, [pc, #0xb4] */
/* @0x1168dc add r4, pc, r4 */
/* @0x1168e0 ldr r5, [r4, r3] */
/* @0x1168e4 ldr r0, [r5] */
/* @0x1168e8 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x1168ec cmp r0, #0 */
/* @0x1168f0 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1168f4 ldr r3, [pc, #0x9c] */
/* @0x1168f8 ldr lr, [r5] */
/* @0x1168fc ldr r3, [r4, r3] */
/* @0x116900 ldr r3, [r3] */
/* @0x116904 ldr r2, [r3, #0x4] */
/* @0x116908 ldr r3, [r3] */
/* @0x11690c and r2, lr, r2 */
/* @0x116910 ldr r3, [r3, r2, lsl #3] */
/* @0x116914 cmp r3, #0 */
/* @0x116918 beq 0x116944 <_Z16F_EventInheritedR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x11691c ldr r2, [r3, #0x8] */
/* @0x116920 cmp lr, r2 */
/* @0x116924 bne 0x116938 <_Z16F_EventInheritedR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x116928 b 0x116988 <_Z16F_EventInheritedR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x11692c ldr r12, [r3, #0x8] */
/* @0x116930 cmp lr, r12 */
/* @0x116934 beq 0x116988 <_Z16F_EventInheritedR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x116938 ldr r3, [r3, #0x4] */
/* @0x11693c cmp r3, #0 */
/* @0x116940 bne 0x11692c <_Z16F_EventInheritedR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x116944 ldr r5, [r3, #0xc] */
/* @0x116948 mov r0, r5 */
/* @0x11694c bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x116950 cmp r0, #0 */
/* @0x116954 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x116958 ldr r12, [pc, #0x3c] */
/* @0x11695c mov r0, r7 */
/* @0x116960 ldr r3, [pc, #0x38] */
/* @0x116964 mov r1, r6 */
/* @0x116968 mov r2, r5 */
/* @0x11696c ldr r12, [r4, r12] */
/* @0x116970 ldr r3, [r4, r3] */
/* @0x116974 ldr r12, [r12] */
/* @0x116978 ldr r3, [r3] */
/* @0x11697c str r12, [sp, #0x18] */
/* @0x116980 pop {r4, r5, r6, r7, r8, lr} */
/* @0x116984 b 0xf32e4 <_Z20Perform_Event_ObjectP9CInstanceS0_iii> */
/* @0x116988 ldr r3, [r3, #0xc] */
/* @0x11698c b 0x116944 <_Z16F_EventInheritedR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x116990 eoreq r11, sp, r4, ror r3 */
/* @0x116994 .word 0xffffc168 */
/* @0x116998 .word 0xffffbfec */
/* @0x11699c .word 0xffffc164 */
/* @0x1169a0 .word 0xffffc160 */
